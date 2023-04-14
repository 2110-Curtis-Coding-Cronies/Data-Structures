#pragma once

// Used as a stand-in for std::size_t, since <cstddef> cannot be included in the test.
typedef unsigned long long int SizeInt;

enum class BucketState
{
    EMPTY_SINCE_START,
    EMPTY_SINCE_REMOVAL,
    FULL
};

class HashTableBucket
{
public:
    // Constructs an empty bucket.
    HashTableBucket(void);

    // Constructs a bucket holding the specified value.
    HashTableBucket(int value);

    inline BucketState getState(void) const { return m_state; };

    inline int operator*(void) const { return m_value; };

    inline int getValue(void) const { return m_value; };

    // Attempts to set the value of this bucket; the value is only set if this bucket is empty.
    // Returns true if the value of this bucket was successfully set, false otherwise.
    bool set(int value);

    // Empties this bucket, setting the state to EMPTY_SINCE_REMOVAL if this bucket had an item, or EMPTY_SINCE_REMOVAL if not.
    void empty(void);

private:
    BucketState m_state;
    int m_value;
};