#pragma once
#include "List.h"
#include <iostream>

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
class DoublyLinkedList : public List <T, DoubleNode<T>*>
{
public:
	inline DoublyLinkedList(void) : m_head(nullptr), m_tail(nullptr) {};
	inline ~DoublyLinkedList(void) 
	{
		// Loop through the entire list; deletion is only done when there is no head.
		while (m_head != nullptr) {
			// Set a temporary node pointer to the next node in the list, starting with the first node after the head.
			DoubleNode<T>* next = m_head->next;
			// Delete the previous node, which will be the head.
			delete m_head;
			// The new head is now the next node.
			m_head = next;
		}
		// By this point, every node has been deleted, so the tail pointer should just be set to null.
		m_tail = nullptr;
	};

	// Returns the pointer to the head node.
	inline DoubleNode<T>* getHead(void) const
	{
		return m_head;
	};

	// Returns the pointer to the tail node.
	inline DoubleNode<T>* getTail(void) const
	{
		return m_tail;
	};

	// Inserts a new node with the given value after the tail node.
	inline void append(T val) override
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
		List<T, DoubleNode<T>*>::m_length++;
	};

	// Inserts a new node with the given value before the head node.
	inline void prepend(T val) override
	{
		if (m_head == nullptr) {
			m_head = new DoubleNode<T>(val);
			m_tail = m_head;
		}
		else {
			// Insert the new node at the front of the list.
			m_head = new DoubleNode<T>(val, (DoubleNode<T>*)nullptr, m_head);
		}
		List<T, DoubleNode<T>*>::m_length++;
	};

	// Inserts a new node with value x into this list after the node ptr.
	inline void insertAfter(DoubleNode<T>* ptr, T x) override
	{
		// Special case 1: this list is empty.
		if (m_head == nullptr) {
			// Set both the head and tail pointer to a new node constructed from the given value.
			m_head = new DoubleNode<T>(x);
			m_tail = m_head;
		}
		// Special case 2: this list is not empty, and the specified node is the tail node.
		else if (ptr == m_tail) {
			// Append a new node with the given value to the end of this list.
			m_tail->next = new DoubleNode<T>(x);
			m_tail = m_tail->next;
		}
		// Normal case: this list is not empty, and the specified node is not the tail node.
		else {
			// Create the new node initialized with the given value, with the specified node as the previous node and the specified node's original next node as this node's next node.
			DoubleNode<T>* newNode = new DoubleNode<T>(x, ptr, ptr->next);
			// Insert the new node after the specified node.
			ptr->next = newNode;
		}
		List<T, DoubleNode<T>*>::m_length++;
	};

	// Attempts to remove the node ptr from this list.
	inline void remove(DoubleNode<T>* ptr) override
	{
		// There can be no removal if this list is empty, or if the specified node is null.
		if (m_head == nullptr || ptr == nullptr) return;

		// Special case 1: the specified node is the head node.
		if (ptr == m_head) {
			// Delete the head node and set the new head node to the next node.
			m_head = m_head->next;
			m_head->prev = nullptr;
		}
		// Special case 2: the specified node is the tail node.
		else if (ptr == m_tail) {
			// Delete the tail node and set it to the previous node.
			m_tail = m_tail->prev;
			m_tail->next = nullptr;
		}
		// Normal case: the specified node is in the middle of this list.
		else {
			// Elide the specified node out of the list.
			ptr->prev->next = ptr->next;
		}
		delete ptr;
		List<T, DoubleNode<T>*>::m_length--;
	};

	// Returns the first node which matches the given value, searching forwards.
	inline DoubleNode<T>* search(T val) const override
	{
		for (DoubleNode<T>* node = m_head; node != nullptr; node = node->next) {
			if (node->value == val)
				return node;
		}
		return nullptr;
	};

	// Returns the last node which matches the given value, searching backwards.
	inline DoubleNode<T>* searchReverse(T val) const override
	{
		for (DoubleNode<T>* node = m_tail; node != nullptr; node = node->prev) {
			if (node->value == val)
				return node;
		}
		return nullptr;
	};

	// Returns true if this list is empty, false otherwise.
	inline bool isEmpty(void) const override
	{
		return m_head == nullptr || m_tail == nullptr;
	};

	inline void printEach(void)
	{
		size_t counter = 0;
		DoubleNode<T>* node = m_head;
		while (node != nullptr) {
			std::cout << counter++ << ": " << node->value << '\n';
			node = node->next;
		}
		std::cout << std::endl;
	};

private:
	DoubleNode<T>* m_head;
	DoubleNode<T>* m_tail;
};