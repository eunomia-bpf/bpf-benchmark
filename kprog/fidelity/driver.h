#ifndef KPROG_CPU_DIFFERENTIAL_H
#define KPROG_CPU_DIFFERENTIAL_H
#include <stdint.h>
#include <stddef.h>
struct state { uint64_t r[32], flags, vec[2]; unsigned char stack[64]; };
_Static_assert(offsetof(struct state, flags) == 256, "assembly flags offset");
_Static_assert(offsetof(struct state, vec) == 264, "assembly vector offset");
_Static_assert(offsetof(struct state, stack) == 280, "assembly stack offset");
struct form {
    const char *assembly, *opcode;
    void (*native)(struct state *), (*sim)(struct state *);
    unsigned flag_mask, width, count, mode;
};
extern const struct form forms[];
extern const unsigned form_count;
#endif
