#pragma once

/*
* Written by Grayson Kippes on 2/27/2023
* 
* This class represents the abstract data type List.
* Template T is the data type which this list holds.
* Template P is a pointer type which is used for nodes or offsets, depending on the implementation.
*/

template <class T, class P>
class List
{
public:
	// Inserts x at the end of this list.
	virtual void append(T x) = 0;

	// Inserts x at the front of this list.
	virtual void prepend(T x) = 0;

	// Inserts x after the position indicated by the pointer.
	virtual void insertAfter(P ptr, T x) = 0;

	// Removes the element at the position indicated by the pointer.
	virtual void remove(P ptr) = 0;
};