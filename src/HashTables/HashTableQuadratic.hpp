#pragma once

#include <vector>
#include "HashTableBucket.hpp"

class HashTableQuadratic
{
public:
    // Since resizing is not implemented, an empty hash table must not be allowed to be constructed.
    HashTableQuadratic(void) = delete;

    // Constructs a hash table with a specified size.
    HashTableQuadratic(std::size_t size);

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
    // Probe this table for an address based on the value provided.
    // If parameter searching is true, stop only on empty-since-start; otherwise, stop on any empty bucket.
    std::size_t probe(int x, bool searching = false) const;

    double m_c1 = 0.0;
    double m_c2 = 1.0;

    // Hashes the passed item and returns the bucket index.
    // Uses the modulo hash function.
    std::size_t hashModulo(int x) const;

    // The internal table object.
    // nullptr = empty object.
    std::vector<HashTableBucket> m_table;
};