#pragma once

#include <vector>
#include "HashTableBucket.hpp"

// Hash table that implements chaining as its collision strategy.
// Written by Grayson Kippes on 4/13/2023.
class HashTableLinear
{
public:
    // Since resizing is not implemented, an empty hash table must not be allowed to be constructed.
    HashTableLinear(void) = delete;

    // Constructs a hash table with a specified size.
    HashTableLinear(SizeInt size);
private:
    // The internal table object.
    // nullptr = empty object.
    std::vector<HashTableBucket> m_table;
};