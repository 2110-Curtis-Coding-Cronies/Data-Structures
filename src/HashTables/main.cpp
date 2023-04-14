#include <iostream>
#include "HashTableChaining.hpp"

// Entrypoint for hash-table classes.
// Written by Grayson Kippes on 4/13/2023.

int main(void)
{
    // Unit testing for chaining hash table.
    HashTableChaining table1(10);

    table1.output();

    table1.insert(20);
    table1.insert(40);
    table1.insert(47);
    table1.insert(817);
    table1.insert(97);
    table1.insert(81);

    table1.output();

    std::cout << "table1 has 97 = " << table1.search(97) << std::endl;
    std::cout << "table1 has 55 = " << table1.search(55) << std::endl;

    std::cout << "table1.remove(817) = " << table1.remove(817) << std::endl;
    std::cout << "table1.remove(89) = " << table1.remove(89) << '\n' << std::endl;

    table1.output();

    return 0;
}