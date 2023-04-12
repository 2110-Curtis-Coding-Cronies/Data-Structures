#include <iostream>
#include "HashTables/HashTableLinear.h"
#include <stdlib.h>

int main(void)
{
	const size_t n = 10;
	int *table = (int *)calloc(n, sizeof(int));
	
	insert(table, n, 20);

	for (size_t i = 0; i < n; i++)
		std::cout << *(table + i) << ' ';
	std::cout << std::endl;

	return 0;
}