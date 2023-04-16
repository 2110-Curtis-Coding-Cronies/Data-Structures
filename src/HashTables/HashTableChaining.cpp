#include "HashTableChaining.hpp"
#include <iostream>

HashTableChaining::HashTableChaining(std::size_t size) : m_table(size) {}

bool HashTableChaining::insert(int x)
{
    m_table.at(hashModulo(x)).push_back(x);
    // Chaining never halts, so insertion always returns true.
    return true;
}

bool HashTableChaining::search(int x) const
{
    for (const int &item : m_table.at(hashModulo(x))) {
        if (item == x)
            return true;
    }
    return false;
}

bool HashTableChaining::remove(int x)
{
    std::list<int> &bucket = m_table.at(hashModulo(x));
    for (std::list<int>::iterator iter = bucket.begin(); iter != bucket.end(); iter++) {
        if (*iter == x) {
            bucket.erase(iter);
            return true;
        }
    }
    return false;
}

void HashTableChaining::output(void) const
{
    for (std::size_t i = 0; i < m_table.size(); i++) {
        // Print the index of this bucket.
        std::cout << i << ": ";

        const std::list<int> &bucket = m_table.at(i);
        if (bucket.empty()) {
            std::cout << "empty\n";
        }
        else {
            for (const int &item : m_table.at(i)) 
                std::cout << item << ' ';
            std::cout << '\n';
        }
    }
    std::cout << std::endl;
}

std::size_t HashTableChaining::hashModulo(int x) const
{
    return x % m_table.size();
}