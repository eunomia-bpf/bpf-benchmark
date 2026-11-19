typedef unsigned long long u64;

u64 identity_constant(void) {
    u64 value = 5;
    asm volatile("" : "+r"(value));
    return value * 3;
}

u64 identity_live(u64 value) {
    value &= 255;
    asm volatile("" : "+r"(value));
    return value * 3 + 4;
}

const u64 *pointer_identity(const u64 *value) {
    asm volatile("" : "+r"(value));
    return value;
}

u64 clobber_identity(u64 value) {
    asm volatile("" : "+r"(value) : : "memory");
    return value;
}

void memory_barrier(void) {
    asm volatile("" : : : "memory");
}

u64 memory_load(const u64 *pointer) {
    u64 value;
    asm volatile("%0 = *(u64 *)(%1 + 0)" : "=r"(value) : "r"(pointer));
    return value;
}
