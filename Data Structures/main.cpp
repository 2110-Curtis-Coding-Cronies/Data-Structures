#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "LinkedStack.h"

int main(void)
{
	DoublyLinkedList<int> dList1;

	for (int i = 0; i < 10; i++) {
		dList1.append((i + 1) * 5);
	}
	
	size_t counter = 0;
	for (DoubleNode<int>* node = dList1.getHead(); node != nullptr; node = node->next) {
		std::cout << ++counter << ": " << node->value << '\n';
	}
	std::cout << std::endl;

	return 0;
}