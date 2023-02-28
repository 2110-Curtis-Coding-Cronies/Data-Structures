#pragma once

/*
* Written by Grayson Kippes on 2/27/2023
* 
* This class represents the abstract data type List.
*/

template <class T>
class List
{
public:
	// Inserts x at the end of the list.
	virtual void append(T x) = 0;

	// Inserts x at the front of the list.
	virtual void prepend(T x) = 0;

};