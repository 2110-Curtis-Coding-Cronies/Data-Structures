#pragma once

/*
* Written by Grayson Kippes on 2/26/2023
*
* This class represents a doubly-linked list.
*/

// Node for a doubly-linked list.
template<class T>
struct DoubleNode
{
	T value;
	DoubleNode<T>* prev;
	DoubleNode<T>* next;

	// Constructs a node with a value and no previous or next pointers.
	template<class T>
	inline DoubleNode(T val) : value(val), prev(nullptr), next(nullptr) {};

	// Constructs a node with a value and a previous node pointer. The pointer to the next node is null.
	template<class T>
	inline DoubleNode(T val, DoubleNode<T>* prev) : value(val), prev(prev), next(nullptr) {};

	// Constructs a node with a value, and previous and next pointers.
	template<class T>
	inline DoubleNode(T val, DoubleNode<T>* prev, DoubleNode<T>* next) : value(val), prev(prev), next(next) {};
};

template<class T>
class DoublyLinkedList
{
public:
	inline DoublyLinkedList(void) : m_head(nullptr), m_tail(nullptr) {};
	inline ~DoublyLinkedList(void) 
	{
		// Loop through the entire list; deletion is only done when there is no head.
		while (m_head != nullptr) {
			// Set a temporary node pointer to the next node in the list, starting with the first node after the head.
			SingleNode<T>* next = m_head->next;
			// Delete the previous node, which will be the head.
			delete m_head;
			// The new head is now the next node.
			m_head = next;
		}
		// By this point, every node has been deleted, so the tail pointer should just be set to null.
		m_tail = nullptr;
	};

	// Returns the pointer to the head node.
	DoubleNode<T>* getHead(void) const
	{
		return m_head;
	};

	// Returns the pointer to the tail node.
	DoubleNode<T>* getTail(void) const
	{
		return m_tail;
	};

	// Returns the first node which matches the given value, searching forwards.
	DoubleNode<T>* search(T val) const
	{
		for (DoubleNode<T>* node = m_head; node != nullptr; node = node->next) {
			if (node->value == val)
				return node;
		}
		return nullptr;
	};

	// Returns the last node which matches the given value, searching backwards.
	DoubleNode<T>* searchReverse(T val) const
	{
		for (DoubleNode<T>* node = m_tail; node != nullptr; node = node->prev) {
			if (node->value == val)
				return node;
		}
		return nullptr;
	};

	// Inserts a new node with the given value after the tail node.
	inline void append(T val)
	{
		// Special case: this list is empty.
		if (m_head == nullptr) {
			m_head = new DoubleNode<T>(val);
			m_tail = m_head;
		}
		else {
			// Insert the new node at the end of the list.
			m_tail->next = new DoubleNode<T>(val, m_tail);
			m_tail = m_tail->next;
		}
	};

	// Inserts a new node with the given value before the head node.
	void prepend(T val)
	{
		if (m_head == nullptr) {
			m_head = new DoubleNode<T>(val);
			m_tail = m_head;
		}
		else {
			// Insert the new node at the front of the list.
			m_head = new DoubleNode<T>(val, nullptr, m_head);
		}
	};

private:
	DoubleNode<T>* m_head;
	DoubleNode<T>* m_tail;
};