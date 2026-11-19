#include <stdint.h>

#if WIDTH == 8
typedef uint8_t word;
#elif WIDTH == 16
typedef uint16_t word;
#elif WIDTH == 32
typedef uint32_t word;
#elif WIDTH == 64
typedef uint64_t word;
#endif

/* The returned old value is needed to compute flags from the successful RMW. */
#if defined(FETCH_ADD)
uint64_t atomic_operation(word *address, uint64_t value)
{
    return __atomic_fetch_add(address, (word)value, __ATOMIC_SEQ_CST);
}
#else
uint64_t atomic_operation(word *address, uint64_t expected, uint64_t desired)
{
    word observed = (word)expected;
    __atomic_compare_exchange_n(address, &observed, (word)desired, 0,
                                __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
    return observed;
}
#endif
