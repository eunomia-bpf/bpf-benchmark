typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
#define X86_WIDTH_8 1
#define X86_WIDTH_16 2
#define X86_WIDTH_32 4
#define X86_WIDTH_64 8
#include "x86_mem_access.h"
#define LOAD(N,W) __u64 N(const void *p) { return KPROG_X86_MEM_LOAD(p,W); }
#define FIXED(N,D,W) __u64 N(const void *p) { return KPROG_X86_MEM_LOAD_FIXED(p,D,W); }
LOAD(load_0,0)
LOAD(load_1,1)
LOAD(load_2,2)
LOAD(load_4,4)
LOAD(load_8,8)
FIXED(fixed_0_0,-32768,0)
FIXED(fixed_0_1,-32768,1)
FIXED(fixed_0_2,-32768,2)
FIXED(fixed_0_4,-32768,4)
FIXED(fixed_0_8,-32768,8)
FIXED(fixed_1_0,-3,0)
FIXED(fixed_1_1,-3,1)
FIXED(fixed_1_2,-3,2)
FIXED(fixed_1_4,-3,4)
FIXED(fixed_1_8,-3,8)
FIXED(fixed_2_0,-1,0)
FIXED(fixed_2_1,-1,1)
FIXED(fixed_2_2,-1,2)
FIXED(fixed_2_4,-1,4)
FIXED(fixed_2_8,-1,8)
FIXED(fixed_3_0,0,0)
FIXED(fixed_3_1,0,1)
FIXED(fixed_3_2,0,2)
FIXED(fixed_3_4,0,4)
FIXED(fixed_3_8,0,8)
FIXED(fixed_4_0,88,0)
FIXED(fixed_4_1,88,1)
FIXED(fixed_4_2,88,2)
FIXED(fixed_4_4,88,4)
FIXED(fixed_4_8,88,8)
FIXED(fixed_5_0,32767,0)
FIXED(fixed_5_1,32767,1)
FIXED(fixed_5_2,32767,2)
FIXED(fixed_5_4,32767,4)
FIXED(fixed_5_8,32767,8)
