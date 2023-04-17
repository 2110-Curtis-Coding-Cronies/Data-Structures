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

std::size_t HashTableLinear::hashMidsquare(int x) const
{
    // Find the number of digits in the value to be hashed.
    std::size_t numDigits = 1;
    int y = x;
    while (y >= 10) {
        y /= 10;
        numDigits++;
    }

    // Find the number of digits in the table size.
    std::size_t numDigitsTableSize = 1;
    std::size_t tableSize = m_table.size();
    while (tableSize >= 10) {
        tableSize /= 10;
        numDigitsTableSize++;
    }

    // Calculate the first digit to extract (from left to right), and the number of digits to extract.
    std::size_t startDigit = (numDigits / 2) - (numDigitsTableSize / 2);
    std::size_t numDigitsToExtract = numDigitsTableSize - 1;
    int extractedDigits = x;
    for (std::size_t i = 0; i < startDigit; i++) {
        extractedDigits /= 10;
    }

    // Find the digits before the extracted digits to subract.
    int lopOff = extractedDigits;
    int power = 1;
    for (std::size_t i = 0; i < numDigitsToExtract; i++) {
        lopOff /= 10;
        power *= 10;
    }
    lopOff *= power;

    // Lop off the extra digits before the extracted digits.
    extractedDigits -= lopOff;
    return extractedDigits;
}