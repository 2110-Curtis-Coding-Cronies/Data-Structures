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
	// Initializes this list with a length of 0.
	inline List(void) : m_length(0) {};
	// Initializes this list with a set length.
	inline List(size_t initLen) : m_length(initLen) {};

	// Inserts x at the end of this list.
	virtual void append(T x) = 0;

	// Inserts x at the front of this list.
	virtual void prepend(T x) = 0;

	// Inserts x after the position indicated by the pointer.
	virtual void insertAfter(P ptr, T x) = 0;

	// Removes the element at the position indicated by the pointer.
	virtual void remove(P ptr) = 0;

	// Returns a pointer to the first instance of the specified item in this list, or null if it is not present.
	virtual P search(T x) const = 0;

	// Returns a pointer to the last instance of the specified item in this list, searching backwards, or null if it is not present.
	virtual P searchReverse(T x) const = 0;

	// Returns true if this list is empty, false otherwise.
	virtual inline bool isEmpty(void) const { return m_length == 0; };

	// Returns the current number of elements in this list.
	inline size_t length(void) const { return m_length; };

protected:
	size_t m_length;
};