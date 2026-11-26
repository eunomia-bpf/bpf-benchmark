#include <stdint.h>
#include <stdio.h>

typedef unsigned long u64;
extern u64 atomic_entry(u64 *);
extern u64 tail_entry(void *, void *, const volatile u64 *);
static uintptr_t observed_x26;
static const u64 clock_value = 0x123456789abcdef0UL;

u64 bpf_ktime_get_ns(void) { return clock_value; }

/* Observe the register that the real native-link tail template dereferences.
 * This is a userspace ABI observer, not execution of a kernel tail call. */
long bpf_tail_call(void *ctx, void *map, unsigned index)
{
    (void)ctx; (void)map; (void)index;
    __asm__ volatile("mov %0, x26" : "=r"(observed_x26));
    return 0;
}

int main(void)
{
    u64 value = 0;
    for (unsigned i = 0; i < 64; ++i)
        if (atomic_entry(&value) != i) return 2;
    if (value != 64) return 2;
    volatile u64 inputs[12];
    u64 expected = 0, counter = 0;
    for (unsigned i = 0; i < 12; ++i) {
        inputs[i] = 17 * i + 3;
        expected += inputs[i] ^ (clock_value + i);
    }
    uintptr_t previous;
    __asm__ volatile("mov %0, x26" : "=r"(previous));
    __asm__ volatile("mov x26, %0" : : "r"(&counter) : "x26");
    u64 actual = tail_entry(0, 0, inputs);
    __asm__ volatile("mov x26, %0" : : "r"(previous) : "x26");
    printf("atomic_cases=64 values_ok=%u counter_pointer_ok=%u\n",
           actual == expected, observed_x26 == (uintptr_t)&counter);
    return actual == expected && observed_x26 == (uintptr_t)&counter ? 0 : 1;
}
