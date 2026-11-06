/* Catch raw-context offsets 0/8 being misclassified as XDP packet pointers. */
#include <stdint.h>
#include <stdio.h>
#include "../../../kprog/x86/x86_sim_local_bpf.h"
static int check(unsigned offset) {
    uint64_t context[32];
    for (unsigned i=0;i<32;i++) context[i]=0x1234000000000000ULL+i;
    X86_SIM_ENTRY_RAW(context);
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD,X86_RAX,X86_RDI,X86_WIDTH_64,0,offset);
    if (((uint64_t)(uintptr_t)__x86_rax.ptr)!=context[offset/8] || __x86_rax_tag!=X86_SIM_TAG_SCALAR) {
        fprintf(stderr,"raw offset=%u value=%llx tag=%u\n",offset,
                (unsigned long long)((uint64_t)(uintptr_t)__x86_rax.ptr),__x86_rax_tag);
        return 1;
    }
    return 0;
}
int main(void) {
    int result=check(0)|check(8)|check(80)|check(208);
    if (!result) puts("raw context: exact 64-bit loads at all four packet ABI offsets remain scalar");
    return result;
}
