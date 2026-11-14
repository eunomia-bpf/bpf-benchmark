// Catch signed-register-width errors and stores wider than the selected size.
#ifdef TEST_DRIVER
extern int errno32(const int *);
extern long errno64(const long *);
extern unsigned long store0(char *, unsigned long, unsigned char);
extern unsigned long store7(char *, unsigned long, unsigned char);
extern unsigned long store19(char *, unsigned long, unsigned char);
int main(void) {
    long values[] = {(-0x7fffffffffffffffL - 1), -0x80000000L, -4096, -4095,
                     -4094, -1, 0, 1, 0xff, 0xffff, 0x7fffffffL, 0xffffffffL,
                     0x100000000L, 0x7fffffffffffffffL};
    unsigned offsets[] = {0, 7, 19};
    unsigned long (*stores[])(char *, unsigned long, unsigned char) = {store0, store7, store19};
    for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        long n = values[i];int low = (int)n;
        if (errno64(&n) != ((n >= -4095 && n <= 0) ? n : -1)) return 1;
        // Original BPF LDXW zero-extends before the two signed 64-bit jumps.
        if (errno32(&low) != (low == 0 ? 0 : -1)) return 2;
        for (unsigned size = 0; size < 256; ++size) for (unsigned s = 0; s < 3; ++s) {
            unsigned char buffer[64], expected[64];
            __builtin_memset(buffer, 0xa5, sizeof(buffer));
            __builtin_memcpy(expected, buffer, sizeof(buffer));
            if (size == 1 || size == 2 || size == 4 || size == 8)
                __builtin_memcpy(expected + 1 + offsets[s], &n, size);
            if (stores[s]((char *)buffer + 1, (unsigned long)n, (unsigned char)size) != (unsigned long)n) return 3;
            if (__builtin_memcmp(buffer, expected, sizeof(buffer))) return 4;
        }
    }
    return 0;
}
#else
int errno32(const int *p) {
    int n = *p;
    asm volatile("if %0 s< -4095 goto +1\nif %0 s<= 0 goto +1\n%0 = -1\n" : "+r"(n));
    return n;
}
long errno64(const long *p) {
    long n = *p;
    asm volatile("if %0 s< -4095 goto +1\nif %0 s<= 0 goto +1\n%0 = -1\n" : "+r"(n));
    return n;
}
#define STORE(name, offset) \
unsigned long name(char *ctx, unsigned long val, unsigned char size) { \
    char *original_ctx = ctx;unsigned long original_val = val;unsigned char original_size = size; \
    asm volatile("if %[size] != 8 goto +2\n" \
                 "*(u64 *)(%[ctx] + %[off]) = %[val]\n" \
                 "goto +8\n" \
                 "if %[size] != 4 goto +2\n" \
                 "*(u32 *)(%[ctx] + %[off]) = %[val]\n" \
                 "goto +5\n" \
                 "if %[size] != 2 goto +2\n" \
                 "*(u16 *)(%[ctx] + %[off]) = %[val]\n" \
                 "goto +2\n" \
                 "if %[size] != 1 goto +1\n" \
                 "*(u8 *)(%[ctx] + %[off]) = %[val]\n" \
                 : [ctx] "+r"(ctx), [val] "+r"(val), [size] "+r"(size) \
                 : [off] "i"(offset)); \
    return ctx == original_ctx && val == original_val && size == original_size ? val : ~val; \
}
STORE(store0, 0)
STORE(store7, 7)
STORE(store19, 19)
#endif
