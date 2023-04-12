#ifndef HASH_TABLE_LINEAR_H
#define HASH_TABLE_LINEAR_H

// Written by Grayson Kippes on  4/12/2023.
// Hash Table that uses Linear Probing to resolve collisions.
// Specialized for type int; 0 represents empty.

#include <stddef.h>

// Inserts val into table, which is of size n.
// Returns 1 if the value was inserted, 0 otherwise.
int insert(int *table, size_t n, int val);

#endif