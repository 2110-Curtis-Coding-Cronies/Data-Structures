#pragma once

// Hash tables for CSCE 2110, specialized for type int.
// Each hash table must be able to insert, search, and delete an item, and output its contents.

#include <vector>
#include <list>

// Used as a stand-in for std::size_t, since <cstddef> cannot be included in the test.
typedef unsigned long long int SizeInt;

// Hash table that implements chaining as its collision strategy.
// Written by Grayson Kippes on 4/13/2023.
class HashTableChaining
{
public:
    // Since resizing is not implemented, an empty hash table must not be allowed to be constructed.
    HashTableChaining(void) = delete;

    // Constructs a hash table with a specified size.
    HashTableChaining(SizeInt size);

    // Inserts the specified item into this table.
    // Returns true if the specified item was successfully inserted, false otherwise.
    bool insert(int x);

    // Searches for the specified item in this table.
    // Returns true if the specified item was found in this table, false otherwise.
    bool search(int x) const;

    // Removes the specified item from this table.
    // Returns true if the specified item was found in and successfully removed from this table, false otherwise.
    bool remove(int x);

    // Outputs the contents of this table.
    void output(void) const;

private:
    // Hashes the passed item and returns the bucket index.
    // Uses the modulo hash function.
    SizeInt hashModulo(int x) const;

    std::vector<std::list<int>> m_table;
};