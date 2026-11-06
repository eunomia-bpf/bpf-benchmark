#ifndef KPROG_CPU_DIFFERENTIAL_H
#define KPROG_CPU_DIFFERENTIAL_H
#include <stdint.h>
#include <stddef.h>
#ifndef KPROG_FIDELITY_VECTOR_BANK
#define KPROG_FIDELITY_VECTOR_BANK 1
#endif
_Static_assert(KPROG_FIDELITY_VECTOR_BANK == 1 || KPROG_FIDELITY_VECTOR_BANK == 32,
               "supported trace vector-bank layouts");
struct state { uint64_t r[32], flags, vec[2 * KPROG_FIDELITY_VECTOR_BANK]; unsigned char stack[64]; };
_Static_assert(offsetof(struct state, flags) == 256, "assembly flags offset");
_Static_assert(offsetof(struct state, vec) == 264, "assembly vector offset");
_Static_assert(offsetof(struct state, stack) == 264 + 16 * KPROG_FIDELITY_VECTOR_BANK, "assembly stack offset");
_Static_assert(sizeof(struct state) == 328 + 16 * KPROG_FIDELITY_VECTOR_BANK, "trace state record size");
struct form {
    const char *assembly, *opcode;
    void (*native)(struct state *), (*sim)(struct state *);
    unsigned flag_mask, width, count, mode;
    const unsigned char *pc, *next_pc;
};
extern const struct form forms[];
extern const unsigned form_count;
#endif
