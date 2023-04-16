#include "HashTableLinear.hpp"
#include <iostream>

HashTableLinear::HashTableLinear(std::size_t size) : m_table(size) {}

bool HashTableLinear::insert(int x)
{
    std::size_t location = probe(x, false);
    if (location < m_table.size()) {
        m_table.at(location).set(x);
        return true;
    }
    return false;
}

bool HashTableLinear::search(int x) const
{
    return probe(x, true) < m_table.size();
}

bool HashTableLinear::remove(int x)
{
    std::size_t location = probe(x, true);
    if (location < m_table.size()) {
        m_table[location].empty();
        return true;
    }
    return false;
}

std::size_t HashTableLinear::probe(int x, bool searching) const
{
    std::size_t initialHash = hashModulo(x);
    for (std::size_t i = 0; i < m_table.size(); i++) {
        std::size_t currentIndex = (i + initialHash) % m_table.size();
        const HashTableBucket &bucket = m_table.at(currentIndex);

        // If searching for a value, probe until it is found or until an empty-since-start bucket is found.
        // If not searching, just probe until an empty bucket is found.
        if (searching) {
            if (bucket.hasValue() && bucket.getValue() == x)
                return currentIndex;
            else if (bucket.getState() == BucketState::EMPTY_SINCE_START)
                break;
        }
        else if (bucket.isEmpty())
            return currentIndex;
    }
    return -1;
}

void HashTableLinear::output(void) const
{
    for (std::size_t i = 0; i < m_table.size(); i++) {
        std::cout << i << ": ";
        if (m_table.at(i).hasValue())
            std::cout << *m_table.at(i) << '\n';
        else
            std::cout << "empty\n";
    }
    std::cout << std::endl;
}

std::size_t HashTableLinear::hashModulo(int x) const
{
    return x % m_table.size();
}