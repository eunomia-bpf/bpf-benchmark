#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#define X86_SIM_USE_STATE_STRUCT
#define X86_SIM_STACK_BYTES 64U
#include "../../x86/x86_sim_local_bpf.h"
#include "../../x86/x86_sim_inline.h"
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_REG,X86_OP_MOV_STORE_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD,X86_OP_MOV_LOAD)

unsigned long native_lab_entry_input(unsigned kind)
{ assert(kind == NATIVE_LAB_INPUT_UNSPECIFIED); return 0x1020304050607080UL; }

int main(void)
{
    unsigned cases=0;
    for (unsigned tag=0; tag<=X86_SIM_TAG_CODE; ++tag)
    for (unsigned word=1; word<=5; word+=4)
    for (unsigned alias=0; alias<2; ++alias) {
        struct x86_sim_state state={0};
        X86_SIM_L_BIND_COMMON_STATE(&state);
        X86_SIM_BIND_INLINE();
        state.abi_kind=X86_SIM_ABI_KIND_RAW;
        state.rsp.ptr=(void *)(intptr_t)-64;
        state.native_stack_base=0x12340000;
        unsigned index=word*8;
        __s64 offset=(__s64)index-64;
        unsigned aux=X86_MEM_AUX_FULL(X86_REG_NONE,0,X86_WIDTH_64);
        state.rdi.ptr=&state.stack_mem.b[index];
        state.rdi_tag=X86_SIM_TAG_STACK;
        state.rbx.ptr=&state.stack_mem.b[8];
        state.rbx_tag=tag;
        for (unsigned replant=0; replant<2; ++replant) {
            state.rsp.ptr=(void *)(intptr_t)-64;
            X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG,alias?X86_RDI:X86_RSP,
                X86_RBX,X86_WIDTH_64,aux,alias?0:(__u64)offset);
            struct x86_sim_stack_value cached=X86_SIM_L_STACK_VALUES_READ(index,X86_WIDTH_64);
            assert(cached.tag==tag);
            if (tag==X86_SIM_TAG_STACK) assert(cached.pointer==state.rbx.ptr);
            X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,alias?X86_RDI:X86_RSP,
                X86_WIDTH_64,aux,alias?0:(__u64)offset);
            if (state.rax_tag!=tag || state.rax.ptr!=state.rbx.ptr)
                fprintf(stderr,"reload tag=%u word=%u alias=%u replant=%u observed_tag=%u same_pointer=%d\n",
                    tag,word,alias,replant,state.rax_tag,state.rax.ptr==state.rbx.ptr);
            assert(state.rax_tag==tag && state.rax.ptr==state.rbx.ptr);
            /* Partial writes erase a complete pointer fact. */
            X86_SIM_L_STACK_WRITE(offset,X86_WIDTH_8,0x5a);
            cached=X86_SIM_L_STACK_VALUES_READ(index,X86_WIDTH_64);
            assert(cached.tag==X86_SIM_TAG_SCALAR);
            /* Releasing and replanting the slot must not resurrect it. */
            state.rsp.ptr=(void *)(intptr_t)-8;
            X86_SIM_L_STACK_RELEASE(offset);
            cached=X86_SIM_L_STACK_VALUES_READ(index,X86_WIDTH_64);
            assert(cached.tag==X86_SIM_TAG_SCALAR);
            X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,alias?X86_RDI:X86_RSP,
                X86_WIDTH_64,aux,alias?0:(__u64)offset);
            assert(state.rax_tag==X86_SIM_TAG_SCALAR &&
                   (uintptr_t)state.rax.ptr==0x1020304050607080UL);
            ++cases;
        }
    }
    printf("{\"tag_alias_partial_release_cases\":%u}\n",cases);
    return 0;
}
