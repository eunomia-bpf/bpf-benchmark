#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 2
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: ja     130f <flow_5tuple_rss_hash_xdp+0x20f> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(300, 509, 1), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1119: ja     130f <flow_5tuple_rss_hash_xdp+0x20f> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(294, 496, 1), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x111f: lea    rsi,[rcx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1126: ja     130f <flow_5tuple_rss_hash_xdp+0x20f> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(288, 483, 1), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x112c: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112d: mov    rbp,rsp [exact-kinsn: movq frame-register kinsn] */
    HC_KINSN(HC_X86_FRAME_PAYLOAD(HC_X86_RBP, HC_X86_RSP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1130: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1134: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1136: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: movzx  edi,WORD PTR [rcx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x113b: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x113f: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1142: cmp    edi,0x800 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1148: jne    1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(256, 441, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x114e: lea    rdi,[rcx+0x2a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1152: cmp    rdi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1155: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(250, 428, 1), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x115b: movzx  edi,BYTE PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x115e: mov    r8d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1161: and    r8b,0xf0 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 240), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1165: cmp    r8b,0x40 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 64), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1169: jne    1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(240, 408, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x116f: and    edi,0xf [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1172: cmp    dil,0x5 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 5), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1176: jb     1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-kinsn: jb branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(234, 395, 1), MICRO_HANDCRAFT_BPF_X86_JB),
    /* 0x117c: lea    rsi,[rsi+rdi*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_2, BPF_REG_1, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1180: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1183: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(228, 382, 1), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1189: movzx  r11d,BYTE PTR [rcx+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118e: movzx  edi,BYTE PTR [rcx+0x19] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 25), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1192: movzx  ebx,BYTE PTR [rcx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1196: cmp    ebx,0x11 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 17), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1199: je     11a4 <flow_5tuple_rss_hash_xdp+0xa4> [exact-kinsn: je branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(6, 9, 0), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x119b: cmp    ebx,0x6 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 6), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x119e: jne    1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(214, 355, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11a4: lea    r8,[rsi+0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 4), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11a8: cmp    r8,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11ab: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(208, 342, 1), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x11b1: mov    eax,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b4: shl    eax,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b7: or     eax,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11b9: mov    r8d,DWORD PTR [rcx+0x22] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11bd: mov    r10d,DWORD PTR [rcx+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c1: bswap  r10d [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11c4: bswap  r8d [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11c7: movzx  edx,WORD PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11ca: movzx  edi,WORD PTR [rsi+0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11ce: rol    dx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11d2: movzx  esi,dx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d5: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11d9: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11dc: lea    r9d,[rax+r8*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_0, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11e0: lea    r14d,[r10-0x61c88647] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, HC_X86_R10, 0, 0, 1, 0, -1640531527), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11e7: mov    edx,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e9: shl    edx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11ec: or     edx,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11ee: lea    r12d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R12, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f2: lea    r15d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f6: add    r15d,0x12345678 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 305419896), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11fd: sub    r9d,r15d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1200: add    r9d,0xdeadbeef [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, -559038737), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1207: rol    r15d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x120b: xor    r15d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x120e: lea    r9d,[r10+r12*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_R10, HC_X86_R12, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1212: add    r9d,0xb06bd031 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, -1335111631), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1219: mov    r12d,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x121c: rol    r12d,0x6 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R12, HC_X86_R12, 6), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1220: sub    r14d,r15d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1223: xor    r12d,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1226: add    r15d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1229: sub    r9d,r12d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x122c: mov    r14d,r12d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122f: rol    r14d,0x8 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 8), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1233: xor    r14d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1236: add    r12d,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1239: mov    r9d,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x123c: rol    r9d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1240: sub    r15d,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1243: xor    r9d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1246: add    r14d,r12d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1249: sub    r12d,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x124c: mov    r15d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124f: rol    r15d,0x13 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 19), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1253: xor    r15d,r12d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1256: add    r9d,r14d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1259: xor    r8d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x125c: rol    r8d,0x7 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 7), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1260: sub    r14d,r15d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1263: add    r8d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1266: add    r9d,edx [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1269: add    r9d,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x126c: rol    r15d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1270: xor    r15d,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1273: mov    edx,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1275: shl    edx,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1278: or     edx,eax [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x127a: add    edx,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x127d: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1280: mov    r10d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1283: rol    r10d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1287: sub    edx,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x128a: mov    r10d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x128d: rol    r10d,0xb [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 11), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1291: xor    r8d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1294: sub    r8d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1297: xor    r9d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x129a: mov    r10d,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x129d: rol    r10d,0x19 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 25), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12a1: sub    r9d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12a4: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12a7: mov    r10d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12aa: rol    r10d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12ae: sub    edx,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12b1: xor    r8d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12b4: mov    r10d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b7: rol    r10d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12bb: sub    r8d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12be: xor    r9d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12c1: rol    r8d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12c5: sub    r9d,r8d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12c8: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12cb: rol    r9d,0x18 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R9, HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12cf: sub    edx,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12d2: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d5: shl    esi,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d8: or     ebx,esi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12da: xor    ebx,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12dc: xor    esi,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12de: mov    BYTE PTR [rcx],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12e0: mov    BYTE PTR [rcx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_6, BPF_REG_4, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12e3: shr    esi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12e6: mov    BYTE PTR [rcx+0x2],sil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12ea: mov    BYTE PTR [rcx+0x3],r11b [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, BPF_REG_4, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12ee: mov    BYTE PTR [rcx+0x4],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12f1: mov    BYTE PTR [rcx+0x5],dh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_3, BPF_REG_4, 5, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12f4: mov    eax,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f6: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12f9: mov    BYTE PTR [rcx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_4, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12fc: shr    edx,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12ff: mov    BYTE PTR [rcx+0x7],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1302: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1307: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1308: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x130a: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x130c: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x130e: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x130f: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
