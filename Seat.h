//
//  Seat.h
//  CSC300_hw3_22.7
//
//  Created by James Parks on 7/18/16.
//  Copyright © 2016 James Parks. All rights reserved.
//

#ifndef Seat_h
#define Seat_h

#include <iostream>
#include <string>

using std::string;

class Seat
{
public:
	//Construct an empty Seat
	Seat();
	//Construct a seat with a position: window/center/aisle
	// @param sPos, the seat position
	Seat(string sPos);
	//Construct a seat with a position and a class
	// @param sPos, the seat positions
	// @param sClass, the seat class: first/economy
	Seat(string sClass, string sPos);
	//Destruct a seat
	~Seat();
	
	//get the name of the passenger assigned to this seat
	// @return a string of the passenger's name
	virtual string get_passenger() const;
	//get the class (first/economy) of this seat
	// @return a string describing the seat class
	virtual string get_seatClass() const;
	//get the position of this seat: window/center/aisle
	// #return a string describing the seat position
	virtual string get_position() const;
	//get the availability of the seat
	// @return true if the seat is available
	virtual bool get_available() const;
	//get the row of the seat
	// @return
	virtual int get_row() const;
	//get the column of the seat
	// @return
	virtual int get_col() const;
	
	//set the passenger name
	// @param pName, the passenger name
	virtual void set_passenger(string pName);
	//set the seat class: first/economy
	// @param scType, the seat class type
	virtual void set_seatClass(string scType);
	//set the availability of the seat
	// @param value, true if available false if not
	virtual void set_available(bool value);
	//set the row of the seat
	// @param r,
	virtual void set_row(int r);
	//set the column of the seat
	// @param c
	virtual void set_col(int c);
private:
	void set_position(string pos);
	string passenger;
	string seatClass;
	int row;
	int col;
	bool is_available;
	bool is_window;
	bool is_center;
	bool is_aisle;
};

#endif /* Seat_h */
