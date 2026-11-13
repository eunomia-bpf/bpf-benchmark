/* Helpers may invalidate output bytes, not unrelated caller stack facts. */
#include <stdio.h>
#include <string.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 320U
#include "kprog/x86/x86_sim_local_bpf.h"
unsigned long native_lab_entry_input(unsigned int kind) { return 0; }
#define bpf_ktime_get_ns() 42ULL
#define bpf_get_current_task_btf() ((void *)0x1234)
#define bpf_map_update_elem(MAP, KEY, VALUE, FLAGS) (memcpy((MAP), (VALUE), 8), 0)
#define bpf_map_delete_elem(MAP, KEY) (memset((MAP), 0, 8), 0)
#define bpf_probe_read(DST, SIZE, SRC) (memcpy((DST), (SRC), (SIZE)), 0)
#define bpf_skb_load_bytes(CTX, OFF, DST, SIZE) (memset((DST), 0x5a, (SIZE)), 0)
#define REQUIRE(C) do { if (!(C)) { printf("helper effect failure line %d\n", __LINE__); return 1; } } while (0)
#define SAVE(OFF, VALUE) X86_SIM_L_STACK_VALUES_SAVE(X86_SIM_L_STACK_INDEX(OFF), 8, (void *)(VALUE), X86_SIM_TAG_STACK)
#define SAVED(OFF) X86_SIM_L_STACK_VALUES_READ(X86_SIM_L_STACK_INDEX(OFF), 8)
int main(void) {
    X86_SIM_ENTRY_RAW((void *)0);
    __x86_rsp.ptr=(void *)-32;
    SAVE(-24, 7); SAVE(-16, 9);
    X86_SIM_BPF_CALL_bpf_ktime_get_ns();
    REQUIRE((__u64)(long)__x86_rax.ptr==42 && SAVED(-24).pointer==(void *)7);
    X86_SIM_BPF_CALL_bpf_get_current_task_btf();
    REQUIRE(__x86_rax.ptr==(void *)0x1234 && __x86_rax_tag==X86_SIM_TAG_MAP_VALUE);
    REQUIRE(SAVED(-24).pointer==(void *)7);

    /* Map mutation reads caller key/value buffers and writes map storage. */
    unsigned long map_value=0, input_value=17, key=0;
    __x86_rdi.ptr=&map_value; __x86_rdi_tag=X86_SIM_TAG_MAP_VALUE;
    __x86_rsi.ptr=&key; __x86_rdx.ptr=&input_value; __x86_rcx.ptr=0;
    X86_SIM_BPF_CALL_bpf_map_update_elem();
    REQUIRE(map_value==17 && SAVED(-24).pointer==(void *)7);
    __x86_rdi.ptr=&map_value; __x86_rsi.ptr=&key;
    X86_SIM_BPF_CALL_bpf_map_delete_elem();
    REQUIRE(map_value==0 && SAVED(-24).pointer==(void *)7);

    /* Ordinary native calls spill and reload an address in the caller frame. */
    __x86_rsp.ptr=(void *)-40;
    X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7);
    void *caller_byte=__x86_rcx.ptr;
    __x86_rsp.ptr=(void *)-232;
    X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80);
    REQUIRE(SAVED(-152).pointer==caller_byte);
    X86_SIM_BPF_CALL_bpf_ktime_get_ns();
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80);
    REQUIRE(__x86_rax_tag==X86_SIM_TAG_STACK && __x86_rax.ptr==caller_byte);
    unsigned char output_buffer[16]={}, input_buffer[16]={3};
    __x86_rbp.ptr=output_buffer; __x86_rbp_tag=X86_SIM_TAG_MAP_VALUE;
    X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88);
    X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88);
    REQUIRE(__x86_rcx_tag==X86_SIM_TAG_MAP_VALUE && __x86_rcx.ptr==output_buffer);
    X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 1);
    REQUIRE(__x86_rcx_tag==X86_SIM_TAG_MAP_VALUE && __x86_rcx.ptr==output_buffer+1);
    X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0);
    __x86_rsi.ptr=(void *)1; __x86_rdx.ptr=input_buffer;
    X86_SIM_BPF_CALL_bpf_probe_read();
    REQUIRE(SAVED(-152).pointer==caller_byte);

    /* Every memory-region tag follows full-width offset arithmetic. */
    for (unsigned tag=X86_SIM_TAG_ABI; tag<=X86_SIM_TAG_MAP_VALUE; ++tag) {
        if (tag==X86_SIM_TAG_MAP_PTR) continue;
        __x86_rbx.ptr=output_buffer+4; __x86_rbx_tag=tag;
        __u64 prior_bits=X86_SIM_L_READ_REG(X86_RBX);
        X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_64, X86_ALU_SUB, 1);
        REQUIRE(__x86_rbx_tag==tag && __x86_rbx.ptr==output_buffer+3);
        REQUIRE(X86_SIM_L_READ_REG(X86_RBX)==prior_bits-1);
        __x86_rdx.ptr=(void *)2; __x86_rdx_tag=X86_SIM_TAG_SCALAR;
        X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
        REQUIRE(__x86_rbx_tag==tag && __x86_rbx.ptr==output_buffer+5);
        X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
        REQUIRE(__x86_rbx_tag==tag && __x86_rbx.ptr==output_buffer+3);
        __x86_rdx.ptr=(void *)1; __x86_rdx_tag=X86_SIM_TAG_SCALAR;
        X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBX, X86_WIDTH_64, X86_ALU_ADD);
        REQUIRE(__x86_rdx_tag==tag && __x86_rdx.ptr==output_buffer+4);
        __x86_rcx.ptr=(void *)1; __x86_rcx_tag=X86_SIM_TAG_SCALAR;
        X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RBX, 0), 1);
        REQUIRE(__x86_rdi_tag==tag && __x86_rdi.ptr==output_buffer+5);
        X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_SUB);
        REQUIRE(__x86_rdi_tag==X86_SIM_TAG_SCALAR && (__u64)(long)__x86_rdi.ptr==1);
        X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_ADD, 1);
        REQUIRE(__x86_rbx_tag==X86_SIM_TAG_SCALAR);
    }
    __x86_rsp.ptr=(void *)-32;

    unsigned char foreign[16]={}, source[16]={1,2,3,4};
    __x86_rdi.ptr=foreign; __x86_rdi_tag=X86_SIM_TAG_MAP_VALUE;
    __x86_rsi.ptr=(void *)4; __x86_rdx.ptr=source;
    X86_SIM_BPF_CALL_bpf_probe_read();
    REQUIRE(foreign[3]==4 && SAVED(-24).pointer==(void *)7);

    __x86_rdi.ptr=X86_SIM_L_STACK_PTR(-24); __x86_rdi_tag=X86_SIM_TAG_STACK;
    __x86_rsi.ptr=(void *)4; __x86_rdx.ptr=source;
    X86_SIM_BPF_CALL_bpf_probe_read();
    REQUIRE(SAVED(-24).tag==X86_SIM_TAG_SCALAR && SAVED(-16).pointer==(void *)9);
    REQUIRE(X86_SIM_L_STACK_READ(-24, 4)==0x04030201);

    /* A different output-argument position uses the same effect primitive. */
    __x86_rdx.ptr=X86_SIM_L_STACK_PTR(-16); __x86_rdx_tag=X86_SIM_TAG_STACK;
    __x86_rcx.ptr=0;
    X86_SIM_BPF_CALL_bpf_skb_load_bytes();
    REQUIRE(SAVED(-16).pointer==(void *)9);
    __x86_rdx.ptr=X86_SIM_L_STACK_PTR(-16); __x86_rdx_tag=X86_SIM_TAG_STACK;
    __x86_rcx.ptr=(void *)1;
    X86_SIM_BPF_CALL_bpf_skb_load_bytes();
    REQUIRE(SAVED(-16).tag==X86_SIM_TAG_SCALAR);

    /* Range lengths are not narrowed to the instruction width's u8. */
    __x86_rsp.ptr=(void *)-320;
    unsigned char large_source[300]={};
    SAVE(-32, 11); SAVE(-16, 13);
    __x86_rdi.ptr=X86_SIM_L_STACK_PTR(-320); __x86_rdi_tag=X86_SIM_TAG_STACK;
    __x86_rsi.ptr=(void *)300; __x86_rdx.ptr=large_source;
    X86_SIM_BPF_CALL_bpf_probe_read();
    REQUIRE(SAVED(-32).tag==X86_SIM_TAG_SCALAR && SAVED(-16).pointer==(void *)13);

    /* An unclassified destination still invalidates potentially aliased facts. */
    __x86_rdi.ptr=foreign; __x86_rdi_tag=X86_SIM_TAG_SCALAR;
    __x86_rsi.ptr=(void *)1; __x86_rdx.ptr=source;
    X86_SIM_BPF_CALL_bpf_probe_read();
    REQUIRE(SAVED(-16).tag==X86_SIM_TAG_SCALAR);
    puts("helper effects PASS: getter, foreign/stack output, overlap, zero/large length, unknown alias");
    return 0;
}
