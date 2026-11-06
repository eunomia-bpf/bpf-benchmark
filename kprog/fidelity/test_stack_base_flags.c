/* Detect flags computed from virtual RSP zero instead of native SP. */
#include <stdio.h>
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed int __s32;
typedef signed long long __s64;
#define __BPF_HELPERS__ 1
#undef __always_inline
#define __always_inline inline
#include "../x86/x86_sim_local_bpf.h"
int main(void) {
 unsigned char native_z;
 __asm__ volatile("subq $8, %%rsp\n\taddq $8, %%rsp\n\tsete %0" : "=q"(native_z) : : "cc");
 X86_SIM_L_DECLARE_STATE();
 X86_SIM_L_EXEC_ALU_IMM(X86_RSP,X86_WIDTH_64,X86_ALU_SUB,8);
 X86_SIM_L_EXEC_ALU_IMM(X86_RSP,X86_WIDTH_64,X86_ALU_ADD,8);
 printf("balanced RSP SUB/ADD: CPU ZF=%u, simulator ZF=%u\n", native_z, __x86_zf);
 return native_z != __x86_zf;
}
