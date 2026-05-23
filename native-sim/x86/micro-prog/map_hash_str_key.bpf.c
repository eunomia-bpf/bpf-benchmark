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
	/* 0x0: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
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
	/* 0x11: ja     7b <map_hash_str_key+0x7b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11, 0x7b, x86_l_7b);
x86_l_13:
	/* 0x13: movabs rax,0x30302d79656b2d68 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 3472325312118467944ULL);
x86_l_1d:
	/* 0x1d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22:
	/* 0x22: movabs rax,0x636e65622d667062 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 7164775529535926370ULL);
x86_l_2c:
	/* 0x2c: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31:
	/* 0x31: movabs rax,0xfeedfacedeadbeef */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0, 18369614221520256751ULL);
x86_l_3b:
	/* 0x3b: mov    QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f:
	/* 0x3f: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, &str_hash);
x86_l_46:
	/* 0x46: xor    r13d,r13d */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_49:
	/* 0x49: lea    r14,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e:
	/* 0x4e: mov    rdx,rsp */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDX, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_51:
	/* 0x51: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_54:
	/* 0x54: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_57:
	/* 0x57: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_59:
	/* 0x59: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_update_elem();
x86_l_5f:
	/* 0x5f: mov    rdi,rbx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_RBX, X86_WIDTH_64, 0, 0);
x86_l_62:
	/* 0x62: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_65:
	/* 0x65: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_lookup_elem();
x86_l_6b:
	/* 0x6b: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_6e:
	/* 0x6e: je     73 <map_hash_str_key+0x73> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0x73, x86_l_73);
x86_l_70:
	/* 0x70: mov    r13,QWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73:
	/* 0x73: mov    QWORD PTR [r15],r13 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76:
	/* 0x76: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_7b:
	/* 0x7b: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_7f:
	/* 0x7f: jmp    84 <map_hash_str_key+0x84> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_84:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
