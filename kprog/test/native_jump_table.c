/* Direct-x86 switch fixture: volatile case work prevents value-table folding. */
unsigned long jump_table(const volatile unsigned long *values, unsigned int index)
{
    switch (index) {
    case 0:
#if defined(TEST_TABLE_LIVE_FLAGS)
        {
            unsigned long value = values[0];
            __asm__ volatile("adc $0,%0" : "+r"(value) : : "cc");
            return value;
        }
#elif defined(TEST_TABLE_PARTIAL_RESULT)
        {
            unsigned long value;
            __asm__ volatile("movw $0x55,%%ax" : "=a"(value));
            return value;
        }
#else
        return values[0] + 17;
#endif
    case 1: return values[1] * 3;
    case 2: return values[2] ^ 0x1234;
    case 3: return values[3] - 29;
    case 4: return values[4] | 0x8000;
    case 5: return values[5] & 0x7fff;
    case 6: return values[6] + 71;
    case 7: return values[7] * 5;
    default: return 0;
    }
}
