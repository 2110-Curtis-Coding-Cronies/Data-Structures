#pragma once

/*
* Written by Grayson Kippes on 2/27/2023
*
* This class represents the FIFO abstract data type Queue.
*/

template <class T>
class Queue
{
public:
	// Inserts x at the end of this queue.
	virtual void enqueue(T x) = 0;

	// Removes and returns the item at the front of this queue.
	virtual T dequeue(void) = 0;

	// Returns the item at the front of this queue.
	virtual T peek(void) = 0;

	// Returns true if this queue is empty, false otherwise.
	virtual bool isEmpty(void) = 0;

	// Returns the number of items in this queue.
	virtual size_t length(void) = 0;
};