#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rax,QWORD PTR [rdi] [context-abi: native skb shim field at off 0 maps to __sk_buff u32 ctx field at off 76] */
    HC_LDX(BPF_W, HC_X86_RAX, BPF_REG_1, 76),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RAX, HC_X86_SHADOW_RAX_OFF),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native skb shim field at off 8 maps to __sk_buff u32 ctx field at off 80] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 80),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1107: cmp    rax,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110a: jbe    111e <cgroup_skb_hash_chain_prog+0x1e> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (10) - 1, 0),
    /* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff [context-abi: native skb shim cb store at off 16 maps to __sk_buff cb field at off 48] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(HC_X86_RDI, 48, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1113: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1115: mov    edx,0xffffffff [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDX, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111a: mov    DWORD PTR [rdi+0x14],edx [context-abi: native skb shim cb store at off 20 maps to __sk_buff cb field at off 52] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111d: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x111e: lea    rdx,[rax+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1122: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1125: ja     110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-13) - 1, 0),
    /* 0x1127: lea    rdx,[rax+0x50] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, 0, 0, 1, 0, 80), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112b: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112e: ja     110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-18) - 1, 0),
    /* 0x1130: cmp    DWORD PTR [rax+0x8],0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1134: jne    110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-21) - 1, 16),
    /* 0x1136: cmp    DWORD PTR [rax+0xc],0x8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x113a: jne    110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-24) - 1, 8),
    /* 0x113c: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113e: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1140: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1142: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1143: movabs rdx,0xcbf29ce484222325 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xcbf29ce484222325ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RDX_OFF),
    /* 0x114d: mov    esi,0x7 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RSI, 7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1152: movabs r8,0xd1342543de82ef95 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xd1342543de82ef95ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R8_OFF),
    /* 0x115c: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115f: movabs r10,0x9e3779b97f4a7c15 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b97f4a7c15ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R10_OFF),
    /* 0x1169: movabs r11,0x100000001b3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x100000001b3ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R11_OFF),
    /* 0x1173: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1180: inc    r9 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1183: mov    rbx,r9 [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1186: imul   rbx,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x118a: mov    r14,r8 [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x118d: mov    rcx,rsi [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1190: xor    r15d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R15, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1193: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    r12,r14 [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a3: xor    r12,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11a6: add    r12,QWORD PTR [rax+r15*8+0x10] [exact-kinsn: add64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R12, HC_X86_RAX, HC_X86_R15, 3, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ab: xor    r12,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11ae: rol    r12,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(HC_X86_R12, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11b1: inc    r15 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R15, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11b4: imul   r12,r11 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x11b8: mov    rdx,r12 [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11bb: shr    rdx,0x1d [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 29), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11bf: xor    rdx,r12 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11c2: add    rcx,0xb [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c6: add    r14,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c9: cmp    r15,0x8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11cd: jne    11a0 <cgroup_skb_hash_chain_prog+0xa0> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R15),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-25) - 1, 8),
    /* 0x11cf: add    rsi,0x5 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSI, 5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d3: cmp    r9,0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11d7: jne    1180 <cgroup_skb_hash_chain_prog+0x80> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-42) - 1, 16),
    /* 0x11d9: mov    DWORD PTR [rdi+0x10],edx [context-abi: native skb shim cb store at off 16 maps to __sk_buff cb field at off 48] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 48), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11dc: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11e0: mov    eax,0x1 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e5: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11e6: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11e8: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11ea: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11ec: mov    DWORD PTR [rdi+0x14],edx [context-abi: native skb shim cb store at off 20 maps to __sk_buff cb field at off 52] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ef: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
