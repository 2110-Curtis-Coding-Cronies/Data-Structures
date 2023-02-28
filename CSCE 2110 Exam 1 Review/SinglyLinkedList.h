#pragma once
#include "delete.h"

/*
* Written by Grayson Kippes on 2/21/2023
*
* This class represents a singly-linked list.
*/

// Node for a singly-linked list.
template<class T>
struct SingleNode
{
	T value;
	SingleNode<T>* next;

	template<class T>
	inline SingleNode(T val) : value(val), next(nullptr) {};
	template<class T>
	inline SingleNode(T val, SingleNode<T>* next) : value(val), next(next) {};
};

template<class T>
class SinglyLinkedList
{
public:
	inline SinglyLinkedList(void) : m_head(nullptr), m_tail(nullptr) {};
	inline ~SinglyLinkedList(void)
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
	SingleNode<T>* getHead(void) const
	{
		return m_head;
	};

	// Returns the pointer to the tail node.
	SingleNode<T>* getTail(void) const
	{
		return m_tail;
	};

	// Returns the first node which matches the given value.
	SingleNode<T>* search(T val) const
	{
		for (SingleNode<T>* next = m_head; next != nullptr; next = next->next) {
			if (next->value == val)
				return next;
		}
		return nullptr;
	};

	// Inserts a new node with the given value after the tail node.
	inline void append(T val)
	{
		if (m_head == nullptr) {
			m_head = new SingleNode<T>(val);
			m_tail = m_head;
		}
		else {
			m_tail->next = new SingleNode<T>(val);
			m_tail = m_tail->next;
		}
	};

	// Inserts a new node with the given value before the head node.
	void prepend(T val)
	{
		if (m_head == nullptr) {
			m_head = new SingleNode<T>(val);
			m_tail = m_head;
		}
		else {
			m_head = new SingleNode<T>(val, m_head);
		}
	};

	// Inserts the value after the specified node.
	void insertAfter(SingleNode<T>* node, T val)
	{
		// Scenario 1: the list is empty.
		if (m_head == nullptr) {
			// Set both the head and tail pointer to a new node constructed from the given value.
			m_head = new SingleNode<T>(val);
			m_tail = m_head;
		}
		// Scenario 2: the list is not empty, and the specified node is the tail node.
		else if (node == m_tail) {
			// Append a new node with the given value to the end of the list.
			m_tail->next = new SingleNode<T>(val);
			m_tail = m_tail->next;
		}
		// Scenario 3: the list is not empty, and the specified node is not the tail node.
		else {
			SingleNode<T>* newNode = new SingleNode<T>(val, node->next);
			node->next = newNode;
		}
	};

	// Removes the node after the specified node.
	void removeAfter(SingleNode<T>* node)
	{
		// No node can be removed if the list is empty, so if the pointer to the head is null, don't do anything.
		if (m_head == nullptr) return;
		// Special case: the specified node is null.
		if (node == nullptr) {
			// Remove the head node.
			SingleNode<T>* nextNode = m_head->next;
			delete m_head;
			m_head = nextNode;
		}
		else if (node->next != nullptr)
		{
			// Remove the node after the specified node.
			SingleNode<T>* nextNode = node->next;
			node->next = nextNode->next;
			delete nextNode;
		}
	};

	void printEach(void)
	{
		size_t counter = 0;
		SingleNode<T>* node = m_head;
		while (node != nullptr) {
			std::cout << counter++ << ": " << node->value << std::endl;
			node = node->next;
		}
	}

private:
	SingleNode<T>* m_head;
	SingleNode<T>* m_tail;
};
