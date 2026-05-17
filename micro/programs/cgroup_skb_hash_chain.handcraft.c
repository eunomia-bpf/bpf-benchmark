#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 2
 *
 * - 0x115f: movabs r10,0x9e3779b97f4a7c15 [warning-unmapped: movabs into HC_X86_R10 needs a machine-level immediate-load kinsn]
 * - 0x1169: movabs r11,0x100000001b3 [warning-unmapped: movabs into HC_X86_R11 needs a machine-level immediate-load kinsn]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rax,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_0, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: cmp    rax,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110a: jbe    111e <cgroup_skb_hash_chain_prog+0x1e> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(26, 18, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff [exact-kinsn: mov immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(BPF_REG_1, 16, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1113: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1115: mov    edx,0xffffffff [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111a: mov    DWORD PTR [rdi+0x14],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_1, 20), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111d: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x111e: lea    rdx,[rax+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1122: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1125: ja     110c <cgroup_skb_hash_chain_prog+0xc> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-31, -27, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1127: lea    rdx,[rax+0x50] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 80), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112b: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x112e: ja     110c <cgroup_skb_hash_chain_prog+0xc> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-64, -36, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1130: cmp    DWORD PTR [rax+0x8],0x10 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, 8, 16), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1134: jne    110c <cgroup_skb_hash_chain_prog+0xc> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-94, -42, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1136: cmp    DWORD PTR [rax+0xc],0x8 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, 12, 8), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x113a: jne    110c <cgroup_skb_hash_chain_prog+0xc> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-123, -48, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x113c: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113e: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1140: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1142: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1143: movabs rdx,0xcbf29ce484222325 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 14695981039346656037ULL),
    /* 0x114d: mov    esi,0x7 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1152: movabs r8,0xd1342543de82ef95 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 15074714826142052245ULL),
    /* 0x115c: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115f: movabs r10,0x9e3779b97f4a7c15 [warning-unmapped: movabs into HC_X86_R10 needs a machine-level immediate-load kinsn] */
    /* 0x1169: movabs r11,0x100000001b3 [warning-unmapped: movabs into HC_X86_R11 needs a machine-level immediate-load kinsn] */
    /* 0x1173: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1180: inc    r9 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1183: mov    rbx,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1186: imul   rbx,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x118a: mov    r14,r8 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x118d: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1190: xor    r15d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1193: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    r12,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a3: xor    r12,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11a6: add    r12,QWORD PTR [rax+r15*8+0x10] [exact-kinsn: add64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R12, BPF_REG_0, BPF_REG_9, 3, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ab: xor    r12,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11ae: rol    r12,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(HC_X86_R12, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11b1: inc    r15 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11b4: imul   r12,r11 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R12, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x11b8: mov    rdx,r12 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11bb: shr    rdx,0x1d [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 29), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11bf: xor    rdx,r12 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11c2: add    rcx,0xb [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c6: add    r14,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c9: cmp    r15,0x8 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_9, 8), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11cd: jne    11a0 <cgroup_skb_hash_chain_prog+0xa0> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-85, -47, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11cf: add    rsi,0x5 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d3: cmp    r9,0x10 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11d7: jne    1180 <cgroup_skb_hash_chain_prog+0x80> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-159, -89, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11d9: mov    DWORD PTR [rdi+0x10],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11dc: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11e0: mov    eax,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e5: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11e6: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11e8: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11ea: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11ec: mov    DWORD PTR [rdi+0x14],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_1, 20), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ef: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
