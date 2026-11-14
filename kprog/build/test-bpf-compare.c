// All LLVM integer comparison predicates must keep their signedness and width.
#ifdef TEST_DRIVER
extern int compare32(unsigned, unsigned, unsigned);
extern int compare64(unsigned, unsigned long, unsigned long);
#define CHECK_OPS(T, S) \
    switch (predicate) { \
    case 0: return (T)a == (T)b; case 1: return (T)a != (T)b; \
    case 2: return (T)a > (T)b; case 3: return (T)a >= (T)b; \
    case 4: return (T)a < (T)b; case 5: return (T)a <= (T)b; \
    case 6: return (S)a > (S)b; case 7: return (S)a >= (S)b; \
    case 8: return (S)a < (S)b; case 9: return (S)a <= (S)b; \
    default: return -1; }
static int expected32(unsigned predicate, unsigned a, unsigned b) { CHECK_OPS(unsigned, int) }
static int expected64(unsigned predicate, unsigned long a, unsigned long b) { CHECK_OPS(unsigned long, long) }
int main(void) {
    unsigned long values[] = {0, 1, 2, 0x7fffffffUL, 0x80000000UL, 0xffffffffUL,
                             0x100000000UL, 0x7fffffffffffffffUL, 0x8000000000000000UL, ~0UL};
    for (unsigned i = 0; i < 10; ++i) for (unsigned j = 0; j < 10; ++j) for (unsigned p = 0; p < 10; ++p) {
        if (compare32(p, values[i], values[j]) != expected32(p, values[i], values[j])) return 1;
        if (compare64(p, values[i], values[j]) != expected64(p, values[i], values[j])) return 2;
    }
    return 0;
}
#else
extern _Bool cmp32(unsigned, unsigned, unsigned) __asm__("llvm.bpf.compare.i32.i32");
extern _Bool cmp64(unsigned, unsigned long, unsigned long) __asm__("llvm.bpf.compare.i64.i64");
#define COMPARES(F) \
    switch (predicate) { \
    case 0: return F(32, a, b); case 1: return F(33, a, b); \
    case 2: return F(34, a, b); case 3: return F(35, a, b); \
    case 4: return F(36, a, b); case 5: return F(37, a, b); \
    case 6: return F(38, a, b); case 7: return F(39, a, b); \
    case 8: return F(40, a, b); case 9: return F(41, a, b); \
    default: return -1; }
int compare32(unsigned predicate, unsigned a, unsigned b) { COMPARES(cmp32) }
int compare64(unsigned predicate, unsigned long a, unsigned long b) { COMPARES(cmp64) }
#endif
