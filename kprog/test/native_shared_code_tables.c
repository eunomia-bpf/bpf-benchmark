/* Two roots share anonymous .rodata; neither root calls the other. */
#define ROOT(NAME, BIAS) \
unsigned int NAME(const volatile unsigned long *context) \
{ \
    switch (context[0] & 15) { \
    case 0: return context[1] + BIAS; \
    case 1: return context[2] * 3; \
    case 2: return context[3] ^ (BIAS + 0x1234); \
    case 3: return context[4] - BIAS; \
    case 4: return context[5] | 0x8000; \
    case 5: return context[6] & 0x7fff; \
    case 6: return context[7] + BIAS * 7; \
    case 7: return context[8] * 5; \
    default: return 0; \
    } \
}
ROOT(first_table, 17)
ROOT(second_table, 29)
