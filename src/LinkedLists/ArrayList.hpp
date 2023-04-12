#pragma once
#include "List.h"
#include <cstdlib>

/*
* Written by Grayson Kippes on 2/27/2023
* 
* 
*/

// Executes std::malloc(), where t is the pointer type, and n is the number of spaces.
#define MALLOC(t, n) ((t*)std::malloc(sizeof(t) * (n)))

// Executes std::realloc(), where p is the pointer whose memory is being reallocated, t is the pointer type, and n is the new number of spaces.
#define REALLOC(p, t, n) ((p) = (t*)std::realloc((p), sizeof(t) * (n)))

template <class T>
class ArrayList : public List<T, T*>
{
public:
	inline ArrayList(void) : m_array(MALLOC(T, 1)), m_size(1) {};
	inline ~ArrayList(void)
	{
		std::free(m_array);
	};

	inline T at(size_t i) const { return m_array[i]; };

	// Inserts x at the end of this list.
	inline void append(T x) override
	{
		// Check whether more space needs to be allocated.
		if (List<T, T*>::m_length == m_size) {
			m_array = (T*)std::realloc(m_array, ++m_size * sizeof(T));
		}
		// Insert the new item after the last real element.
		m_array[List<T, T*>::m_length] = x;
		List<T, T*>::m_length++;
	};

	inline void prepend(T x) override 
	{

	};

	inline void insertAfter(T* ptr, T x) override
	{

	};

	inline void remove(T* ptr) override
	{

	};

	inline T* search(T x) const override
	{
		return nullptr;
	};

	inline T* searchReverse(T x) const override
	{
		return nullptr;
	};

private:
	T* m_array;
	size_t m_size;	// The total number of allocated slots in the array--not necessary equal to how many are being used, which is the length of this list.
};