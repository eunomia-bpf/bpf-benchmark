#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern uint64_t entry(const uint64_t *, uint64_t);

int main(void)
{
    unsigned cases = 0;
    for (unsigned pattern = 0; pattern < 16; ++pattern) {
        uint64_t values[64];
        for (unsigned i = 0; i < 64; ++i)
            values[i] = (uint64_t)i * (pattern + 1);
        for (unsigned key = 0; key < 1024; ++key) {
            unsigned expected = 0;
            while (expected < 63 && values[expected] < key)
                ++expected;
            uint64_t actual = entry(values, key);
            if (actual != expected) {
                fprintf(stderr, "pattern=%u key=%u expected=%u actual=%llu\n",
                        pattern, key, expected, (unsigned long long)actual);
                return EXIT_FAILURE;
            }
            ++cases;
        }
    }
    printf("%u cases passed\n", cases);
    return 0;
}
