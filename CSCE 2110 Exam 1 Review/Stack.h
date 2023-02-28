#pragma once

/*
* Written by Grayson Kippes on 2/27/2023
* 
* This class represents the LIFO abstract data type Stack.
*/

template <class T>
class Stack
{
public:
	// Inserts x at the top of this stack.
	virtual void push(T x) = 0;

	// Removes and returns the item at the top of this stack.
	virtual T pop(void) = 0;

	// Returns the item at the top of this stack.
	virtual T peek(void) = 0;

	// Returns true if this stack
	virtual bool isEmpty(void) = 0;

	// Returns the number of items in this stack.
	virtual size_t length(void) = 0;
};