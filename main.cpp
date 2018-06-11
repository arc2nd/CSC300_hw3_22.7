//
//  main.cpp
//  CSC300_hw3_22.7
//
//  Created by James Parks on 7/18/16.
//  Copyright © 2016 James Parks. All rights reserved.
//

/*
 Ch. 22 Exercise P22.7
 
 Airplane Seating. Write a program that assigns seats on an airplane. assume the airplane has 20 seast in first class (5 rows of 4 seats each, separated by an aisle) and 180 seats in economy class(30 rows of 6 seats each, separated by an aisle). Your program should take three commands: add pasengers, show seating, and quit. When passengers are added, ask for the class (first or economy), the number of passengers travelling together (1 or 2 in first class; 1 to 3 in economy), and the seating preference (aisle or window in first class; aisle, center, or window in economy). Then try to find a match and assign the seats. If no match exists, print a message. Your user interface can be text-based or graphical. Follow the design process that was described in the chapter.
 
 */

#include <iostream>
#include "Airplane.h"

using std::cout;
using std::cin;
using std::endl;

//TODO: make check_seating variably bi-directional
//    right now it finds the first available seat and then checks the availability
//    of the seats before or after it in the amount of the passengers in the party.
//    I would like it to be able to, for a party of 3, check one seat forward and
//    one seat back.

void check_seating(Airplane &p, string sClass, string sPos, int numInParty)
{
	int totRows = 0;
	int totCols = 0;
	if(sClass == "first")
	{
		totRows = p.get_fcRows();
		totCols = p.get_fcCols();
	}
	else
	{
		totRows = p.get_ecRows();
		totCols = p.get_ecCols();
	}
	Seat* thisSeat = NULL;
	int i = 0;
	int curRow = 0;
	int curCol = 0;
	bool booked = false;
	bool finished = false;
	bool bookable = false;
	
	//cout << "Looking for first class" << endl;
	while(!booked && !finished)
	{
		//we've run through every possible seat and found no possibilities
		if(i >=(totCols * totRows))
		{
			finished = true;
			cout << endl << "Sorry, no seating match." << endl;
		}
		else
		{
			curRow = i / totCols;
			curCol = i % totCols;
			
			thisSeat = p.get_seat(sClass, curRow, curCol);
			//cout << thisSeat->get_row() << ", " << thisSeat->get_col() << endl;
			
			if(numInParty > 0)
			{
				bookable = false;
				Seat* testSeat = NULL;
				//check to see if we've got an initial available seat in the right position
				//    and that we haven't performed the booking process yet.
				if(thisSeat->get_available() && thisSeat->get_position() == sPos && !booked)
				{
					//if there's only one passenger, then we've already found their seat
					if(numInParty == 1)
						bookable = true;
					else
					{
						//found an initial seat to book, need to test following seats
						for(int k=0; k<numInParty; ++k)
						{
							//make sure we don't go past the end of the row
							//    and at this point we don't care about the seat position
							//    just that it's next to our initial traveller
							if(curCol + numInParty <= totCols)
							{
								testSeat = p.get_seat(sClass, curRow, curCol + k);
								if(testSeat->get_available() && !booked)
									bookable = true;
								else
									bookable = false;
							}
						}//end check seats after init seat
						
						//check the seats before the initial seat to book
						if(!bookable)
						{
							for(int k=0; k<numInParty; ++k)
							{
								if(curCol - numInParty > 0)
								{
									testSeat = p.get_seat(sClass, curRow, curCol - k);
									if(testSeat->get_available() && !booked)
										bookable = true;
									else
										bookable = false;
								}
							}//end check seats before for
						}//end if still !bookable
						
						if(!bookable)
						{
							cout << "Check seats on either side" << endl;
						}
					}
					
					//if we survived all of those tests and the bookable flag is set to true
					//    then let's go ahead and book them all
					if(bookable)
					{
						//I suppose I could turn the booking process into an Airplane method
						//    but is that REALLY very different than telling the seat it's been booked?
						//p.book(string sClass, int r, int c);
						for(int j=0; j<numInParty; ++j)
						{
							if(curCol + numInParty <= totCols)
							{
								testSeat = p.get_seat(sClass, curRow, curCol + j);
								cout << endl << "booking seat at row " << curRow << ", col " << curCol + j << endl;
								testSeat->set_available(false);
								booked = true;
							}
							
							else if(curCol - numInParty > 0)
							{
								testSeat = p.get_seat(sClass, curRow, curCol - j);
								cout << endl << "booking seat at row " << curRow << ", col " << curCol - j << endl;
								testSeat->set_available(false);
								booked = true;
							}
						}//end bookable for
					}//end bookable if
				}//end first available seat
				testSeat = NULL;
			}//end if numInParty > 0
			++i;
		}
	}//end while/for
	thisSeat = NULL;
}
 

int main()
{
	//set up the airplane's possible seats
	Airplane* myPlane = new Airplane(20,4, 180, 6);
	//1Airplane* myPlane = new Airplane(8, 4, 18, 6); // this is my test airplane because it's a lot faster
	
	//key:
	//    first class window = seats 0 and 3
	//    first class aisle = seats 1 and 2
	//    economy class window = seats 0 and 5
	//    economy class center = seats 1 and 4
	//    economy class aisle = seats 2 and 3
	
	
	//******************
	//***PSUEDO-CODE****
	//******************
	//present menu loop
	//    show seating
	//	      myPlane->show_seating();
	//    add passenger
	//        QUERY: seat class type
	//        QUERY: # of passengers
	//        QUERY: seating preference
	//            check seating loop: this is a seperate function
	//                for thisSeat firstClass/economyClass
	//                    is_window()/is_center()/is_aisle()
	//					      are neighbors open?
	//                            if yes: assign
	//                            else: show no match
	//    quit
	
	bool sentinel = false;
	bool addSentinel = false;
	int choice = 0;
	string desiredClass = "";
	string desiredSeat = "";
	int numInParty = 0;
	
	while(!sentinel)
	{
		addSentinel = false;
		cout << endl << endl << " 1. Show Seating" << endl;
		cout << " 2. Add Passenger(s)" << endl;
		cout << " 3. Quit" << endl;
		
		cin >> choice;
		
		if(!cin.fail())
		{
			cout << endl;
			switch(choice)
			{
				case 1:
				{
					myPlane->show_seating();
					break;
				}//end case 1: show seating
				case 2:
				{
					addSentinel = false;
					while(!addSentinel)
					{
						cout << "Enter Travel Class (first/economy): ";
						cin >> desiredClass;
						if(!cin.fail())
						{
							cout << "Enter Number in Party: ";
							cin >> numInParty;
							if(!cin.fail())
							{
								if(desiredClass == "economy")
									cout << "Enter Desired Seat (window/center/aisle): ";
								else
									cout << "Enter Desired Seat (window/aisle): ";
								cin >> desiredSeat;
								if(!cin.fail())
								{
									if(desiredClass == "first" && numInParty > 2)
									{
										cout << endl << "Sorry, too many in your party." << endl;
									}
									else if(desiredClass == "economy" && numInParty > 3)
									{
										cout << endl << "Sorry, too many in your party." << endl;
									}
									else
									{
										check_seating((*myPlane), desiredClass, desiredSeat, numInParty);
										addSentinel = true;
									}
								}//end !cin.fail : desiredSeat
								else
								{
									cin.clear();
									cin.ignore(256, '\n');
								}
							}//end !cin.fail : numInParty
							else
							{
								cin.clear();
								cin.ignore(256, '\n');
							}

						}//end !cin.fail : desiredClass
						else
						{
							cin.clear();
							cin.ignore(256, '\n');
						}
						
					}//end while !addSentinel

					break;
				}//end case 2: add passengers
				case 3:
				{
					sentinel = true;
					cout << "Exiting." << endl;
					cout << endl;
					break;
				}//end case 3: quit
				default:
				{
					cout << "That's not a valid choice, try again" << endl;
					cout << endl;
					break;
				}//end default case
			}//end choice switch
		}//end if !cin.fail : choice
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
		}

	}// end while !sentinel
	
    return 0;
}
