#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

/*
 * Stage 2 test: HASH map keyed by a 16-byte 5-tuple struct.
 *
 * Real-world shape: simplified connection classifier. We read the
 * 5-tuple fields out of the packet (offsets 16..28 -- well outside the
 * 0..7 result-write zone so input bytes survive across inner-repeat
 * iterations and the lookup key stays stable). Zero-filled test input
 * means the key is all zero in practice; we populate that key with a
 * known verdict before the lookup so both BPF JIT and native paths
 * read back the same value.
 *
 * Maps: 1 (HASH).   Helpers: 0.   Inline-eligible: yes.
 */
#include "../../test/include/native_helpers.h"

struct flow_key {
    __u32 src_ip;
    __u32 dst_ip;
    __u16 src_port;
    __u16 dst_port;
    __u8  proto;
    __u8  _pad[3];
};

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1024);
    __type(key, struct flow_key);
    __type(value, __u32);
} flow_table SEC(".maps");

SEC("xdp")
int packet_5tuple_classify_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1:
	/* 0x1: sub    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_5:
	/* 0x5: mov    rbp,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8:
	/* 0x8: lea    rcx,[rbp+0x20] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c:
	/* 0xc: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_e:
	/* 0xe: cmp    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_CMP_REG_MEM, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_12:
	/* 0x12: ja     a4 <packet_5tuple_classify+0xa4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x12, 0xa4, x86_l_a4);
x86_l_18:
	/* 0x18: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_20:
	/* 0x20: mov    eax,DWORD PTR [rbp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_23:
	/* 0x23: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27:
	/* 0x27: mov    eax,DWORD PTR [rbp+0x14] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2a:
	/* 0x2a: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e:
	/* 0x2e: movzx  eax,WORD PTR [rbp+0x18] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_32:
	/* 0x32: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_37:
	/* 0x37: movzx  eax,WORD PTR [rbp+0x1a] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_3b:
	/* 0x3b: mov    WORD PTR [rsp+0x12],ax */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_40:
	/* 0x40: movzx  eax,BYTE PTR [rbp+0x1c] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_44:
	/* 0x44: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_48:
	/* 0x48: mov    DWORD PTR [rsp+0x4],0xcafebabe */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20585560766ULL);
x86_l_50:
	/* 0x50: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, &flow_table);
x86_l_57:
	/* 0x57: xor    ebx,ebx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_59:
	/* 0x59: lea    r14,[rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e:
	/* 0x5e: lea    rdx,[rsp+0x4] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_63:
	/* 0x63: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_66:
	/* 0x66: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_69:
	/* 0x69: xor    ecx,ecx */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_6b:
	/* 0x6b: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_update_elem();
x86_l_71:
	/* 0x71: mov    rdi,r15 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RDI, X86_R15, X86_WIDTH_64, 0, 0);
x86_l_74:
	/* 0x74: mov    rsi,r14 */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_R14, X86_WIDTH_64, 0, 0);
x86_l_77:
	/* 0x77: call   QWORD PTR [rip+0x0] */
	X86_SIM_BPF_CALL_bpf_map_lookup_elem();
x86_l_7d:
	/* 0x7d: test   rax,rax */
	X86_SIM_RUN_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64, 0, 0);
x86_l_80:
	/* 0x80: je     84 <packet_5tuple_classify+0x84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80, 0x84, x86_l_84);
x86_l_82:
	/* 0x82: mov    ebx,DWORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84:
	/* 0x84: mov    BYTE PTR [rbp+0x0],bl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87:
	/* 0x87: mov    BYTE PTR [rbp+0x1],bh */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_REG_AUX_SRC_SHIFT(8)), 1ULL);
x86_l_8a:
	/* 0x8a: mov    eax,ebx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RAX, X86_RBX, X86_WIDTH_32, 0, 0);
x86_l_8c:
	/* 0x8c: shr    eax,0x10 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_8f:
	/* 0x8f: mov    BYTE PTR [rbp+0x2],al */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_92:
	/* 0x92: shr    ebx,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 24ULL);
x86_l_95:
	/* 0x95: mov    BYTE PTR [rbp+0x3],bl */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RBP, X86_RBX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_98:
	/* 0x98: mov    DWORD PTR [rbp+0x4],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_9f:
	/* 0x9f: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_a4:
	/* 0xa4: add    rsp,0x18 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_a8:
	/* 0xa8: pop    rbp */
	X86_SIM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_a9:
	/* 0xa9: jmp    ae <packet_5tuple_classify+0xae> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ae:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
