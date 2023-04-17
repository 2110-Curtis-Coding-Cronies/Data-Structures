#include <iostream>
#include "HashTableLinear.hpp"
#include "HashTableQuadratic.hpp"

// Entrypoint for hash-table classes.
// Written by Grayson Kippes on 4/13/2023.

int main(void)
{
    // Unit testing for HashTableLinear.
    HashTableLinear table2(17);

    table2.output();

    table2.insert(11);
    table2.insert(134);
    table2.insert(24);
    table2.insert(13875);
    table2.insert(644);

    table2.output();

    table2.remove(24);

    table2.output();

    std::cout << "table2 has 24: " << table2.search(24) << std::endl;
    std::cout << "table2 has 3874: " << table2.search(3874) << std::endl;

    return 0;
}