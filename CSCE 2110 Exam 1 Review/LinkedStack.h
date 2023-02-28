#pragma once
#include "Stack.h"

// Linked-Stack Node
template <class T>
struct LSNode
{
	T value;
	LSNode<T>* below;

	inline LSNode(T value) : value(value), below(nullptr) {};
	inline LSNode(T value, LSNode<T>* below) : value(value), below(below) {};
};

template <class T>
class LinkedStack : public Stack<T>
{
public:
	inline LinkedStack(void) : m_top(nullptr), m_length(0) {};
	inline ~LinkedStack(void) 
	{
		while (m_top != nullptr) {
			LSNode<T>* temp = m_top;
			m_top = m_top->below;
			delete temp;
		}
	};

	inline void push(T x) override 
	{
		m_top = new LSNode<T>(x, m_top);
		m_length++;
	};

	inline T pop(void) override
	{
		T topValue = m_top->value;
		LSNode<T>* topNode = m_top;
		m_top = m_top->below;
		delete topNode;
		m_length--;
		return topValue;
	};

	inline T peek(void) override
	{
		return m_top->value;
	};

	inline bool isEmpty(void) override
	{
		return m_top == nullptr;
	};

	inline size_t length(void) override { return m_length; };

private:
	LSNode<T>* m_top;
	size_t m_length;
};