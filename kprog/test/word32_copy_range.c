/* Catch loss of a bounded scalar alias at an x86 register's 32-bit write. */
#include "kprog/x86/x86_sim_local_bpf.h"
#undef NATIVE_LAB_ENTRY_INPUT
#define NATIVE_LAB_ENTRY_INPUT(KIND) 0UL

struct copy_value { __u16 offset; __u8 bytes[64]; };
#if defined(__bpf__) || defined(__BPF__)
struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct copy_value);
} copy_values SEC(".maps");
#endif

SEC("kprobe/word32_copy")
int word32_copy(void *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
#if defined(__bpf__) || defined(__BPF__)
    __u32 key=0;
    struct copy_value *value=bpf_map_lookup_elem(&copy_values, &key);
    if (!value) return 0;
#else
    struct copy_value *value=ctx;
#endif
    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, value->offset, X86_WIDTH_32);
    X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_32);
    X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 63);
    if (X86_SIM_L_EVAL_CC(X86_CC_A)) return 0;
    value->bytes[X86_SIM_L_READ_REG(X86_RBX)]=1;
    return 0;
}

#if !defined(__bpf__) && !defined(__BPF__)
#include <stdio.h>
int main(void)
{
    for (unsigned offset=0; offset<65536; ++offset) {
        struct copy_value value={.offset=offset};
        word32_copy(&value);
        for (unsigned i=0; i<64; ++i)
            if (value.bytes[i]!=(offset<64 && i==offset)) return 1;
    }
    puts("word32 copied alias semantics PASS: all 65536 source offsets");
    return 0;
}
#else
char LICENSE[] SEC("license")="GPL";
#endif
