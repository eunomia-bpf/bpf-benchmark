/* Equal register lanes must be observed once, including a stack/map tag merge. */
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_STACK_BYTES 64U
#include "kprog/x86/x86_sim_local_bpf.h"
#undef NATIVE_LAB_ENTRY_INPUT
#define NATIVE_LAB_ENTRY_INPUT(KIND) 4096UL

#if defined(__bpf__) || defined(__BPF__)
struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, __u64);
} values SEC(".maps");

SEC("socket") int self_compare(struct __sk_buff *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    __u32 key = 0;
    *(__u64 *)X86_SIM_L_STACK_PTR(-8) = 7;
    if (ctx->mark) {
        __x86_rax.ptr = bpf_map_lookup_elem(&values, &key);
        __x86_rax_tag = X86_SIM_TAG_SCALAR;
    } else {
        __x86_rax.ptr = X86_SIM_L_STACK_PTR(-8);
        __x86_rax_tag = X86_SIM_TAG_STACK;
    }
    X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
    if (X86_SIM_L_EVAL_CC(X86_CC_E)) return 0;
    if (!ctx->mark) return 0;
    return *(const __u64 *)__x86_rax.ptr;
}
char LICENSE[] SEC("license") = "GPL";
#else
#include <stdio.h>

static unsigned observed(__u64 left, __u64 right, unsigned width,
                         unsigned source, unsigned aux, unsigned op)
{
    X86_SIM_ENTRY_RAW(&left);
    X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, left, X86_WIDTH_64);
    X86_SIM_L_WRITE_REG_WIDTH(X86_RCX, right, X86_WIDTH_64);
    X86_SIM_L_EXEC_CMP_REG_OP_AUX(op, X86_RAX, source, width, aux);
    return __x86_cf | (__x86_zf << 1) | (__x86_sf << 2) |
           (__x86_of << 3) | (__x86_pf << 4);
}

static unsigned reference(__u64 left, __u64 right, unsigned bits,
                          unsigned dst_shift, unsigned src_shift, unsigned test)
{
    __u64 mask = bits == 64 ? ~0ULL : (1ULL << bits) - 1;
    __u64 a = (left >> (bits == 8 ? dst_shift : 0)) & mask;
    __u64 b = (right >> (bits == 8 ? src_shift : 0)) & mask;
    __u64 value = test ? a & b : (a - b) & mask;
    unsigned parity = 1;
    for (unsigned i = 0; i < 8; ++i) parity ^= (value >> i) & 1;
    unsigned carry = test ? 0 : a < b;
    unsigned overflow = test ? 0 : ((a ^ b) & (a ^ value)) >> (bits - 1);
    return carry | ((value == 0) << 1) | (((value >> (bits - 1)) & 1) << 2) |
           (overflow << 3) | (parity << 4);
}

int main(void)
{
    const unsigned widths[] = {X86_WIDTH_8, X86_WIDTH_16, X86_WIDTH_32, X86_WIDTH_64};
    const unsigned bits[] = {8, 16, 32, 64};
    const __u64 edges[] = {0, 1, 0x80, 0x100, 0xff00, 0x8000, 0x80000000ULL,
                          0x8000000000000000ULL, ~0ULL};
    __u64 state = 0x973ed452b1ULL;
    unsigned cases = 0;
    for (unsigned i = 0; i < 521; ++i) {
        state = state * 6364136223846793005ULL + 1;
        __u64 left = i < 9 ? edges[i] : state;
        __u64 right = i < 9 ? edges[8-i] : state ^ (state >> 17);
        for (unsigned w = 0; w < 4; ++w)
        for (unsigned same = 0; same < 2; ++same)
        for (unsigned lanes = 0; lanes < 4; ++lanes)
        for (unsigned test = 0; test < 2; ++test) {
            unsigned ds = (lanes & 1) * 8, ss = (lanes >> 1) * 8;
            unsigned source = same ? X86_RAX : X86_RCX;
            unsigned actual = observed(left, right, widths[w], source,
                KPROG_X86_REG_LANE_AUX(0,ds,ss), test ? X86_OP_TEST_REG : X86_OP_CMP_REG);
            unsigned expected = reference(left, same ? left : right, bits[w], ds, ss, test);
            if (actual != expected) {
                printf("compare mismatch case=%u width=%u same=%u lanes=%u test=%u actual=%u expected=%u\n",
                       i,bits[w],same,lanes,test,actual,expected);
                return 1;
            }
            ++cases;
        }
    }
    printf("CMP/TEST defined flags PASS: %u vectors, equal/different registers and byte lanes\n", cases);
    return 0;
}
#endif
