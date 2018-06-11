//
//  Airplane.cpp
//  CSC300_hw3_22.7
//
//  Created by James Parks on 7/18/16.
//  Copyright © 2016 James Parks. All rights reserved.
//

#include "Airplane.h"
#include "Seat.h"
using std::cout;
using std::endl;
using std::vector;

Airplane::Airplane() : fcSeats(20), fcPerAisle(4), ecSeats(180), ecPerAisle(6)
{}

Airplane::Airplane(int _fcSeats, int _fcPerAisle, int _ecSeats, int _ecPerAisle)
: fcSeats(_fcSeats), fcPerAisle(_fcPerAisle), ecSeats(_ecSeats), ecPerAisle(_ecPerAisle)
{
	int i = 0;
	string sPos;
	Seat* newSeat = NULL;
	
	try
	{
		for(i = 0; i < fcSeats; ++i)
		{
			if(i % fcPerAisle == 0 || i % fcPerAisle == fcPerAisle - 1)
				sPos = "window";
			else
				sPos = "aisle";
			
			newSeat = new Seat("first", sPos);
			(*newSeat).set_row(i / fcPerAisle);
			(*newSeat).set_col(i % fcPerAisle);
			firstClass.push_back(*newSeat);
		}
		
		for(i = 0; i < ecSeats; ++i)
		{
			if(i % ecPerAisle == 0 || i % ecPerAisle == ecPerAisle - 1)
				sPos = "window";
			else if(i % (ecPerAisle / 2) == 1)
				sPos = "center";
			else
				sPos = "aisle";
			
			newSeat = new Seat("economy", sPos);
			(*newSeat).set_row(i / ecPerAisle);
			(*newSeat).set_col(i % ecPerAisle);
			economyClass.push_back(*newSeat);
		}
		delete newSeat;
		newSeat = NULL;
	}
	catch (...)
	{
		delete newSeat;
		newSeat = NULL;
		cout << "Something went wrong creating a Seat" << endl;
		throw;
	}
}

Airplane::~Airplane()
{}

void Airplane::add_passenger(string pName, string sClass, string sPos)
{

}

void Airplane::show_seating() const
{
	cout << "Showing Seating..." << endl << "  First Class" << endl;
	//vector<Seat>::iterator iter;
	int i = 0;
	for(auto iter = firstClass.begin(); iter != firstClass.end(); iter++)
	//for(vector<Seat>::iterator iter = firstClass.begin(); iter != firstClass.end(); ++iter)
	{
		if(i % this->fcPerAisle == 0)
			cout << "\n  ";
		if(i % this->fcPerAisle == (this->fcPerAisle / 2))
			cout << "| | ";
		bool open = (*iter).get_available();
		char printVal = '0';
		if(open)
			printVal = '0';
		else
			printVal = '1';
		cout << printVal << " ";
		++i;
    }
	
	cout << endl << "  -----------" << endl << " Economy Class" << endl;;
	
	i = 0;
	for(auto iter = economyClass.begin(); iter != economyClass.end(); iter++)
	{
		if((i % this->ecPerAisle) == 0)
			cout << "\n";
		if((i % this->ecPerAisle) == (this->ecPerAisle / 2))
			cout << "| | ";
		bool open = (*iter).get_available();
		char printVal = '0';
		if(open)
			printVal = '0';
		else
			printVal = '1';
		cout << printVal << " ";
		++i;
	}
}

int Airplane::get_fcRows() const
{
	return fcSeats / fcPerAisle;
}

int Airplane::get_ecRows() const
{
	return ecSeats / ecPerAisle;
}

int Airplane::get_fcCols() const
{
	return fcPerAisle;
}

int Airplane::get_ecCols() const
{
	return ecPerAisle;
}

Seat* Airplane::get_seat(string sClass, int r, int c)
{
	Seat* retSeat = NULL;
	int rcIndex = 0;
	if(sClass == "first")
	{
		rcIndex = (r * fcPerAisle) + c;
		retSeat = &firstClass[rcIndex];
	}
	else if(sClass == "economy")
	{
		rcIndex = (r * ecPerAisle) + c;
		retSeat = &economyClass[rcIndex];
	}
	
	return retSeat;
}