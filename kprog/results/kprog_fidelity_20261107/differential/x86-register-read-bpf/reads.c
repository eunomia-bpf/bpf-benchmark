typedef unsigned long long __u64;
typedef unsigned int __u32;
#define X86_WIDTH_8 1U
#define X86_WIDTH_16 2U
#define X86_WIDTH_32 4U
#define X86_WIDTH_64 8U
#include "frame.h"
#include "x86_width.h"
#include <x86_reg_read.h>
#define READ(N,W,S) __u64 N(const struct Frame *p) { return KPROG_X86_READ_REG_AT(p->value,W,S); }
#define GUARD(N,W,S) __u64 N(const struct Frame *p) { \
 __u64 original=p->value, compared=KPROG_X86_READ_REG_AT(original,W,S); \
 if(compared>15) return 0; \
 return (__u32)(p->table[KPROG_X86_READ_REG_AT(original,W,S)]+(original>>8)); }
READ(read_0_0,0,0)
READ(read_0_8,0,8)
READ(read_1_0,1,0)
READ(read_1_8,1,8)
READ(read_2_0,2,0)
READ(read_2_8,2,8)
READ(read_4_0,4,0)
READ(read_4_8,4,8)
READ(read_8_0,8,0)
READ(read_8_8,8,8)
GUARD(guard_0_0,0,0)
GUARD(guard_0_8,0,8)
GUARD(guard_1_0,1,0)
GUARD(guard_1_8,1,8)
GUARD(guard_2_0,2,0)
GUARD(guard_2_8,2,8)
GUARD(guard_4_0,4,0)
GUARD(guard_4_8,4,8)
GUARD(guard_8_0,8,0)
GUARD(guard_8_8,8,8)
