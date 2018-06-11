//
//  Airplane.h
//  CSC300_hw3_22.7
//
//  Created by James Parks on 7/18/16.
//  Copyright © 2016 James Parks. All rights reserved.
//

#ifndef Airplane_h
#define Airplane_h

#include <iostream>
#include <vector>
#include "Seat.h"

using std::vector;

class Airplane
{
public:
	//Construct an empty airplane
	Airplane();
	//Construct an airplane with a seat plan
	// @param _fcSeats, the number of first class seats
	// @param _fcPerAisle, the number of first class seats in an aisle
	// @param _ecSeats, the number of economy class seats
	// @param _ecPerAisle, the number of economy class seats in an aisle
	Airplane(int _fcSeats, int _fcPerAisle, int _ecSeats, int _ecPerAisle);
	//Destruct an airplane
	~Airplane();
	
	//add a passenger to the airplane
	// @param pName
	// @param sClass
	// @param sPos
	virtual void add_passenger(string pName, string sClass, string sPos);
	//print out all the seats on the airplane, 0 for open, 1 for occupied
	virtual void show_seating() const;
	//get the number of first class rows == total first class seats / first class seats per aisle
	virtual int get_fcRows() const;
	//get the number of economy class rows == total seats / seats per aisle
	virtual int get_ecRows() const;
	//get the number of first class columns == first class seats per aisle
	virtual int get_fcCols() const;
	//get the number of economy class columns == economy class seats per aisle
	virtual int get_ecCols() const;
	//get a seat
	// @param sClass
	// @param r
	// @param c
	// @return a pointer to a seat object
	virtual Seat* get_seat(string sClass, int r, int c);
private:
	const int fcSeats;
	const int ecSeats;
	const int fcPerAisle;
	const int ecPerAisle;
	vector<Seat> firstClass;
	vector<Seat> economyClass;
};

#endif /* Airplane_h */
