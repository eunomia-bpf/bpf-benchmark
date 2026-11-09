/* Opaque outputs preserve live frames and select the fault arm below SP. */
#include <stdio.h>
#ifdef TEST_ARM64
#define ARM64_SIM_ENABLE_STACK 1
#include "kprog/arm64/arm64_sim_local_bpf.h"
#undef ARM64_SIM_L_UNSUPPORTED_OPCODE
#define ARM64_SIM_L_UNSUPPORTED_OPCODE() return 99
#define ENTRY() ARM64_SIM_ENTRY_RAW((void *)0)
#define PREPARE(OFF) do { __a64_sp=-16; __a64_x0.ptr=(void *)(long)(OFF); __a64_x0_tag=ARM64_SIM_TAG_STACK; __a64_x1.x=7; __a64_x2.x=1; } while(0)
#define PTR() ARM64_SIM_L_HELPER_WRITE_ARG_PTR(ARM64_X0)
#define FILL() ARM64_SIM_LIBC_MEMSET()
#define COPY() do { __a64_x1.ptr=(void *)-8; __a64_x1_tag=ARM64_SIM_TAG_STACK; ARM64_SIM_LIBC_MEMCPY(); } while(0)
#define HELPER() ARM64_SIM_BPF_CALL_bpf_get_current_comm()
#else
#define X86_SIM_ENABLE_STACK 1
#include "kprog/x86/x86_sim_local_bpf.h"
#undef X86_SIM_L_ARCHITECTURAL_FAULT
#define X86_SIM_L_ARCHITECTURAL_FAULT() return 99
#define ENTRY() X86_SIM_ENTRY_RAW((void *)0)
#define PREPARE(OFF) do { __x86_rsp.ptr=(void *)-16; __x86_rdi.ptr=X86_SIM_L_STACK_PTR(OFF); __x86_rdi_tag=X86_SIM_TAG_STACK; __x86_rsi.ptr=(void *)7; __x86_rdx.ptr=(void *)1; } while(0)
#define PTR() X86_SIM_L_HELPER_WRITE_ARG_PTR(X86_RDI)
#define FILL() X86_SIM_L_EXEC_CALL_MEMSET_REG(0)
#define COPY() do { __x86_rsi.ptr=X86_SIM_L_STACK_PTR(-8); __x86_rsi_tag=X86_SIM_TAG_STACK; X86_SIM_L_EXEC_CALL_MEMCPY_REG(0); } while(0)
#define HELPER() X86_SIM_BPF_CALL_bpf_get_current_comm()
#endif
unsigned long native_lab_entry_input(unsigned int kind) { (void)kind; return 0; }
static unsigned run(int kind,long off) {
    ENTRY(); PREPARE(off);
    switch(kind) { case 0:(void)PTR();break; case 1:FILL();break;
      case 2:COPY();break; case 3:HELPER();break; }
    return 0;
}
int main(void) {
    for(int kind=0;kind<4;++kind) if(run(kind,-24)!=99) return 1;
    if(run(0,-16)!=0 || run(0,-8)!=0 || run(1,-16)!=0 || run(2,-16)!=0) return 2;
    puts("stack output lifetime PASS: helper, memcpy, memset fault and live-frame controls");
}
