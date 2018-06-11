//
//  Seat.cpp
//  CSC300_hw3_22.7
//
//  Created by James Parks on 7/18/16.
//  Copyright © 2016 James Parks. All rights reserved.
//

#include "Seat.h"

Seat::Seat() : passenger(""), seatClass("")
{
	this->is_available = true;
}

Seat::Seat(string sPos) : seatClass("")
{
	set_position(sPos);
	this->is_available = true;
}

Seat::Seat(string sClass, string sPos) : seatClass(sClass)
{
	set_position(sPos);
	this->is_available = true;
}

Seat::~Seat()
{}

void Seat::set_passenger(string pName)
{
	this->passenger = pName;
	this->is_available = false;
}

void Seat::set_seatClass(string scType)
{
	this->seatClass = scType;
}

string Seat::get_passenger() const
{
	return this->passenger;
}

string Seat::get_seatClass() const
{
	return this->seatClass;
}

string Seat::get_position() const
{
	string retVal = "";
	if(this->is_window)
		retVal = "window";
	if(this->is_center)
		retVal = "center";
	if(this->is_aisle)
		retVal = "aisle";
	return retVal;
}

bool Seat::get_available() const
{
	return this->is_available;
}

int Seat::get_row() const
{
	return row;
}

int Seat::get_col() const
{
	return col;
}

void Seat::set_available(bool value)
{
	this->is_available = value;
}

void Seat::set_position(string pos)
{
	if(pos == static_cast<string>("window"))
	{
		this->is_window = true;
		this->is_center = false;
		this->is_aisle = false;
	}
	else if(pos == static_cast<string>("center"))
	{
		this->is_window = false;
		this->is_center = true;
		this->is_aisle = false;
	}
	else if(pos == static_cast<string>("aisle"))
	{
		this->is_window = false;
		this->is_center = false;
		this->is_aisle = true;
	}
}

void Seat::set_row(int r)
{
	row = r;
}

void Seat::set_col(int c)
{
	col = c;
}






