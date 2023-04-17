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
    std::size_t initialHash = hashMidsquare(x);
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

std::size_t HashTableLinear::hashMidsquare(int x) const
{
    // The square of the value to be hashed.
    int sq = x * x;
    
    // Find the number of digits in the square of the value to be hashed.
    std::size_t numDigits = 1;
    int y = sq;
    while (y >= 10) {
        y /= 10;
        numDigits++;
    }

    // Find the number of digits in the table size.
    // This will be the number of digits to extract from the square of the value to be hashed.
    std::size_t numDigitsTableSize = 1;
    std::size_t tableSize = m_table.size();
    while (tableSize >= 10) {
        tableSize /= 10;
        numDigitsTableSize++;
    }

    // Calculate the first digit to extract (from left to right).
    std::size_t startDigit = (numDigits / 2) - (numDigitsTableSize / 2);
    int extractedDigits = sq;
    for (std::size_t i = 0; i < startDigit; i++) {
        extractedDigits /= 10;
    }

    // Find the digits before the extracted digits to subtract, aka the larger digits.
    int lopOff = extractedDigits;
    int power = 1;
    for (std::size_t i = 0; i < numDigitsTableSize; i++) {
        lopOff /= 10;
        power *= 10;
    }
    lopOff *= power;

    // Lop off the extra digits before the extracted digits, and modulo the extracted digits with the table size.
    return (extractedDigits - lopOff) % m_table.size();
}