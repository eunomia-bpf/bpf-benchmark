#include <stdio.h>
typedef unsigned long long u64;
u64 identity_constant(void), identity_live(u64), clobber_identity(u64);
const u64 *pointer_identity(const u64 *);
void memory_barrier(void);
u64 memory_load(const u64 *);

int main(void) {
    for (u64 value = 0; value < 1024; ++value) {
        if (identity_constant() != 15 ||
            identity_live(value) != (value & 255) * 3 + 4 ||
            clobber_identity(value) != value ||
            pointer_identity(&value) != &value || memory_load(&value) != value)
            return 1;
        memory_barrier();
    }
    puts("1024 integer/pointer/clobber/address-boundary execution cases passed");
    return 0;
}
