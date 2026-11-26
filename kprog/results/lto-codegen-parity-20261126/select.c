#include <stdint.h>

uint64_t entry(const uint64_t *values, uint64_t key)
{
    uint64_t low = 0, high = 63;
#pragma unroll
    for (unsigned i = 0; i < 6; ++i) {
        uint64_t middle = (low + high) / 2;
        unsigned below = values[middle] < key;
        low = below ? middle + 1 : low;
        high = below ? high : middle;
    }
    return low;
}
