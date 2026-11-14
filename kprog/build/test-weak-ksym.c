// Nullable external function guards must use the actual binding in a PIE.
#ifdef TEST_DRIVER
extern unsigned long weak_symbol_test(unsigned long);
#ifdef SYMBOL_PRESENT
unsigned long kprog_fixture_ksym(unsigned long n) { return (n * 3) ^ 0x123456789abcdef0UL; }
#endif
int main(void) {
    unsigned long values[] = {0, 1, 0xffffffffUL, 0x100000000UL, 0x8000000000000000UL, ~0UL};
    for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
#ifdef SYMBOL_PRESENT
        unsigned long expected = kprog_fixture_ksym(values[i]);
#else
        unsigned long expected = 0x5678;
#endif
        if (weak_symbol_test(values[i]) != expected) return 1;
    }
    return 0;
}
#else
extern unsigned long kprog_fixture_ksym(unsigned long) __attribute__((weak, section(".ksyms")));
unsigned long weak_symbol_test(unsigned long n) {
    if (kprog_fixture_ksym) return kprog_fixture_ksym(n);
    return 0x5678;
}
#endif
