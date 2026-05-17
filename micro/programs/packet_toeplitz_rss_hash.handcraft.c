#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 3
 *
 * - 0x1154: lea    r9,[rip+0xea5] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xea5]]
 * - 0x115b: lea    r10,[rip+0xed2] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xed2]]
 * - 0x1162: lea    r11,[rip+0xeff] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeff]]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(15, 1, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-20, -10, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1118: lea    rdx,[rsi+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111c: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x111f: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-53, -19, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1121: movzx  ecx,WORD PTR [rsi+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1125: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1129: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x112c: cmp    ecx,0x800 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1132: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-96, -38, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1134: movzx  ecx,BYTE PTR [rsi+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1138: and    cl,0xf [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 15), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x113b: cmp    cl,0x5 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 5), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x113e: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-131, -50, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 31, 6), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1144: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-162, -56, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1146: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1147: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1149: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x114a: lea    rdi,[rsi+0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114e: lea    r8,[rsi+0x22] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 34), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1152: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1154: lea    r9,[rip+0xea5] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xea5]] */
    /* 0x115b: lea    r10,[rip+0xed2] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xed2]] */
    /* 0x1162: lea    r11,[rip+0xeff] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeff]] */
    /* 0x1169: xor    ebx,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x116b: jmp    1179 <packet_toeplitz_rss_hash_xdp+0x79> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(41, 12, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x116d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1170: xor    eax,ebp [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_0, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1172: inc    ebx [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1174: cmp    ebx,0x68 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 104), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1177: je     11d6 <packet_toeplitz_rss_hash_xdp+0xd6> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(300, 93, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x1179: mov    edx,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117b: shr    edx,0x3 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x117e: cmp    ebx,0x1f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 31), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1181: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(115, 29, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x1183: cmp    ebx,0x3f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 63), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1186: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(84, 24, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x1188: cmp    ebx,0x4f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 79), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x118b: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(53, 19, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x118d: mov    rcx,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1190: cmp    ebx,0x5f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 95), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1193: ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(23, 16, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1195: data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a2: add    rcx,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a5: movzx  ebp,BYTE PTR [rcx] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a8: mov    ecx,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11aa: and    ecx,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11ad: shl    ebp,cl [exact-kinsn: shl32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11af: test   bpl,bpl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11b2: jns    1172 <packet_toeplitz_rss_hash_xdp+0x72> [exact-kinsn: jns branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-221, -66, 0), MICRO_HANDCRAFT_BPF_X86_JNS),
    /* 0x11b4: mov    edx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b6: mov    ebp,DWORD PTR [r10+rdx*4] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RBP, HC_X86_R10, BPF_REG_3, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ba: or     ebp,DWORD PTR [r9+rdx*4] [exact-kinsn: or32 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RBP, HC_X86_R9, BPF_REG_3, 2, 0), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11be: test   ecx,ecx [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x11c0: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> [exact-kinsn: je branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-278, -82, 0), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x11c2: shl    ebp,cl [exact-kinsn: shl32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11c4: mov    r14d,DWORD PTR [r11+rdx*4] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_8, HC_X86_R11, BPF_REG_3, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c8: mov    dl,0x8 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11ca: sub    dl,cl [exact-kinsn: sub8 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SUBB),
    /* 0x11cc: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ce: shr    r14d,cl [exact-kinsn: shr32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x11d1: or     ebp,r14d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11d4: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-325, -102, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x11d6: mov    edx,DWORD PTR [rsi+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d9: movzx  ecx,BYTE PTR [rsi+0x2a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 42), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11dd: movzx  r8d,BYTE PTR [rsi+0x2b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_2, 43), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e2: movzx  r9d,BYTE PTR [rsi+0x2c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_2, 44), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e7: movzx  r10d,BYTE PTR [rsi+0x2d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_2, 45), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ec: mov    r11,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11ef: shl    r11,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11f3: xor    edx,DWORD PTR [rsi+0x22] [exact-kinsn: xor32 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 34), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11f6: bswap  edx [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11f8: mov    edi,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fa: xor    edi,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11fc: or     rdi,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11ff: shl    rcx,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1203: shl    r8,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1207: or     r8,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x120a: shl    r9,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x120e: or     r9,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1211: shl    r10,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1215: or     rdx,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1218: or     rdx,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x121b: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x121e: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1221: mov    r8,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1224: shl    r8,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1227: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1229: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122b: shr    rdx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x122e: or     rdx,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1231: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1234: mov    QWORD PTR [rsi],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1237: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x123c: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x123d: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x123f: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1240: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
