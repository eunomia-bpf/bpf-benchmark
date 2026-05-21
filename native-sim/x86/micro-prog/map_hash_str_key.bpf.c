#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 test: HASH map with a 16-byte string key.
 *
 * Real-world shape: per-process / per-cgroup / per-command lookup
 * keyed by a fixed-length name buffer (tetragon / bpftrace pattern).
 * Larger key means the inline `add rax, KEY_OFFSET` after
 * `__htab_map_lookup_elem` carries a larger immediate than the u32-key
 * case -- still well within imm8 range here.
 *
 * Maps: 1 (HASH).   Helpers: 0.   Inline-eligible: yes.
 */
#include "../../test/include/native_helpers.h"

/* 16-byte key declared as 2 u64s so clang materializes the literal as
 * two `mov qword [rsp+N], imm64` stack stores instead of `memcpy` from
 * a `.rodata` symbol (the latter would emit an R_X86_64_PC32 reloc that
 * native-link doesn't yet handle for embedded rodata). The map key
 * type is the same 16 contiguous bytes either way. */
struct key16 { __u64 lo; __u64 hi; };

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 8);
    __type(key, struct key16);
    __type(value, __u64);
} str_hash SEC(".maps");

SEC("xdp")
int map_hash_str_key_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_4:
	/* 0x4: mov    r15,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7:
	/* 0x7: lea    rcx,[r15+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b:
	/* 0xb: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_d:
	/* 0xd: cmp    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_11:
	/* 0x11: ja     6c <map_hash_str_key+0x6c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11, 0x6c, x86_l_6c);
x86_l_13:
	/* 0x13: movups xmm0,XMMWORD PTR [rip+0x0] */
	X86_SIM_L_LOAD_CONST16_XMM0(7164775529535926370ULL, 3472325312118467944ULL);
x86_l_1a:
	/* 0x1a: movaps XMMWORD PTR [rsp+0x10],xmm0 */
	X86_SIM_L_STORE_XMM0_STACK((__s64)(long)X86_SIM_L_READ_REG_PTR(X86_RSP) + 16);
x86_l_1f:
	/* 0x1f: movabs rax,0xfeedfacedeadbeef */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 18369614221520256751ULL);
x86_l_29:
	/* 0x29: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e:
	/* 0x2e: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, &str_hash);
x86_l_35:
	/* 0x35: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_38:
	/* 0x38: lea    r14,[rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d:
	/* 0x3d: lea    rdx,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42:
	/* 0x42: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_45:
	/* 0x45: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_48:
	/* 0x48: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_4a:
	/* 0x4a: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_update_elem();
x86_l_50:
	/* 0x50: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_53:
	/* 0x53: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_56:
	/* 0x56: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_lookup_elem();
x86_l_5c:
	/* 0x5c: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_5f:
	/* 0x5f: je     64 <map_hash_str_key+0x64> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f, 0x64, x86_l_64);
x86_l_61:
	/* 0x61: mov    r13,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [r15],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67:
	/* 0x67: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_6c:
	/* 0x6c: add    rsp,0x28 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_70:
	/* 0x70: jmp    75 <map_hash_str_key+0x75> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_75:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
