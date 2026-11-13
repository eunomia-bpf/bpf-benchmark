/* Helpers may invalidate output bytes, not unrelated caller stack facts. */
#include <stdio.h>
#include <string.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 320U
#include "kprog/x86/x86_sim_local_bpf.h"
unsigned long native_lab_entry_input(unsigned int kind) { return 0; }
#define bpf_ktime_get_ns() 42ULL
#define bpf_get_current_task_btf() ((void *)0x1234)
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
