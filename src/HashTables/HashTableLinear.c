#include "HashTableLinear.h"

size_t hashModulo(size_t n, int val)
{
    return val % n;
}

int insert(int *table, size_t n, int val)
{
    // The result of the has function.
    size_t index = hashModulo(n, val);
    // Probe for an empty spot; if n spots have been traversed, there is no empty space avaiable.
    for (size_t i = index; i < index + n; i++) {
        size_t j = i % n;
        if (*(table + j) == 0) {
            *(table + j) = val;
            return 1;
        }
    }
    return 0;
}