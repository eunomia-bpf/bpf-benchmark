/* Changing a host ABI preserved register reaches the existing fault arm. */
#include <stdio.h>
#ifdef TEST_ARM64
#define ARM64_SIM_ENABLE_STACK 1
#include "kprog/arm64/arm64_sim_local_bpf.h"
#undef ARM64_SIM_L_REJECT_PC
#define ARM64_SIM_L_REJECT_PC() return 99
#define ENTRY() ARM64_SIM_ENTRY_RAW((void *)0)
#define RET() ARM64_SIM_RET()
#define CHANGE(I) do { if ((I)<11) { __a64_cells[19+(I)]->x=7; } else __a64_sp=-16; } while(0)
#define N 12
#else
#define X86_SIM_ENABLE_STACK 1
#include "kprog/x86/x86_sim_local_bpf.h"
#undef X86_SIM_L_ARCHITECTURAL_FAULT
#define X86_SIM_L_ARCHITECTURAL_FAULT() return 99
#define ENTRY() X86_SIM_ENTRY_RAW((void *)0)
#define RET() X86_SIM_X86_RET()
#define CHANGE(I) do { switch(I) { case 0: __x86_rbx.ptr=(void*)7;break; case 1:__x86_rbp.ptr=(void*)7;break;case 2:__x86_r12.ptr=(void*)7;break;case 3:__x86_r13.ptr=(void*)7;break;case 4:__x86_r14.ptr=(void*)7;break;case 5:__x86_r15.ptr=(void*)7;break;default:__x86_rsp.ptr=(void*)-8; }} while(0)
#define N 7
#endif
unsigned long native_lab_entry_input(unsigned int kind) { return 0; }
static unsigned run(int i) { ENTRY(); if(i>=0) CHANGE(i); RET(); }
int main(void) { if(run(-1)!=0) return 1; for(int i=0;i<N;++i) if(run(i)!=99) {printf("exit register %d mismatch\n",i);return 1;} printf("exit contract PASS: %d changed registers/SP plus preserved frame\n",N); }
