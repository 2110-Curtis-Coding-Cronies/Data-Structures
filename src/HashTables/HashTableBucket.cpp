#include "HashTableBucket.hpp"

HashTableBucket::HashTableBucket(void) : m_state(BucketState::EMPTY_SINCE_START), m_value(0) {}

HashTableBucket::HashTableBucket(int value) : m_state(BucketState::FULL), m_value(value) {}

bool HashTableBucket::set(int value)
{
    if (m_state == BucketState::FULL)
        return false;
    m_value = value;
    m_state = BucketState::FULL;
    return true;
}

void HashTableBucket::empty(void)
{
    if (m_state == BucketState::FULL)
        m_state = BucketState::EMPTY_SINCE_REMOVAL;
}