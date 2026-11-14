// Detect tied-operand mistakes, signed branches, truncated masks, unaligned
// memory accesses and bounded-store neighbor corruption.
#ifdef TEST_DRIVER
extern unsigned long mask_reg(unsigned long);
extern unsigned mask_literal(unsigned);
extern unsigned long mask_ones(unsigned long);
extern unsigned long mask_reg_ones(unsigned long);
extern unsigned long mask_bound(unsigned long);
extern unsigned long mask_bound_full(unsigned long);
extern unsigned long bounded_store(char *, unsigned, unsigned);
extern unsigned long register_load(char *);
extern int size_branch(unsigned long);
extern int size_branch_alias(unsigned long);
static char buffer[4104], expected[4104];
int main(void) {
    unsigned long values[] = {0, 1, 4095, 4096, 8999, 9000, 32735, 32736,
                              32767, 65535, 0x100000000UL, 0x8000000000000000UL, ~0UL};
    for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        unsigned long n = values[i], bound = n & 0x7fff;
        if (bound >= 9000) bound = 9000;
        unsigned long full = n & 0x7fff;if (full >= 32736) full = 32736;
        if (mask_reg(n) != (n & 0xfff) || mask_literal(n) != (unsigned)n ||
            mask_ones(n) != n || mask_reg_ones(n) != n || mask_bound(n) != bound) return 1;
        if (mask_bound_full(n) != full) return 5;
        if (size_branch(n) != (n < 32736 ? 20 : 10) ||
            size_branch_alias(n) != (n < 32736 ? 20 : 10)) return 2;
        __builtin_memset(buffer, 0xa5, sizeof(buffer));
        __builtin_memcpy(expected, buffer, sizeof(buffer));
        unsigned data = (unsigned)n ^ 0x12345678;
        __builtin_memcpy(expected + ((unsigned)n & 0xfff), &data, sizeof(data));
        unsigned long result = bounded_store(buffer, (unsigned)n, data);
        if (result != (((unsigned long)((unsigned)n & 0xfff) << 32) | data) ||
            __builtin_memcmp(buffer, expected, sizeof(buffer))) return 3;
        __builtin_memcpy(buffer + 9, &n, sizeof(n));
        if (register_load(buffer + 1) != n) return 4;
    }
    return 0;
}
#else
unsigned long mask_reg(unsigned long n) {
    asm volatile("%0 &= %1 ;\n" : "+r"(n) : "i"(0xfff));return n;
}
unsigned mask_literal(unsigned n) {
    asm volatile("%0 &= 0xffffffff;\n" : "+r"(n));return n;
}
unsigned long mask_ones(unsigned long n) {
    asm volatile("%0 &= 0xffffffff;\n" : "+r"(n));return n;
}
unsigned long mask_reg_ones(unsigned long n) {
    asm volatile("%0 &= %1;\n" : "+r"(n) : "i"(0xffffffffUL));return n;
}
unsigned long mask_bound(unsigned long n) {
    asm volatile("%0 &= 0x7fff;\nif %0 < 9000 goto +1\n;%0 = 9000;\n" : "+r"(n));return n;
}
unsigned long mask_bound_full(unsigned long n) {
    asm volatile("%0 &= 0x7fff;\nif %0 < 32736 goto +1\n;%0 = 32736;\n" : "+r"(n));return n;
}
unsigned long bounded_store(char *buffer, unsigned offset, unsigned data) {
    asm volatile("%[offset] &= 0xfff;\nr1 = *(u64 *)%[buffer];\nr1 += %[offset];\n*(u32 *)(r1 + 0) = %[data];\n"
                 : [offset] "+r"(offset), [buffer] "+m"(buffer), [data] "+r"(data) : : "r1");
    return ((unsigned long)offset << 32) | data;
}
unsigned long register_load(char *buffer) {
    char *base = buffer;unsigned long value = 0;
    asm volatile("%[value] = *(u64 *)(%[base] + %[offset])\n"
                 : [base] "+r"(base), [value] "+r"(value) : [offset] "i"(8));
    return base == buffer ? value : 0;
}
int size_branch(unsigned long size) {
    asm goto("if %0 < 0 goto %l[negative]\n;if %0 < 32736 goto %l[good]\n;"
             : : "r"(size) : : good, negative);
    return 10;
good:
    return 20;
negative:
    return 30;
}
int size_branch_alias(unsigned long size) {
    asm goto("if %0 < 0 goto %l[negative]\n;if %0 < 32736 goto %l[good]\n;"
             : : "r"(size) : : good, negative);
    return 10;
good:
negative:
    return 20;
}
#endif
