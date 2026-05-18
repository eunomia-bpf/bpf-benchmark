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
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 0),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, HC_X86_RDX, BPF_REG_1, 4),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RDX, HC_X86_SHADOW_RDX_OFF),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RCX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (280) - 1, 0),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1119: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (275) - 1, 0),
    /* 0x111f: lea    rsi,[rcx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1126: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (270) - 1, 0),
    /* 0x112c: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112d: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112f: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: movzx  edi,WORD PTR [rcx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1136: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDI, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x113a: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x113d: cmp    edi,0x800 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1143: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (246) - 1, 2048),
    /* 0x1149: lea    rdi,[rcx+0x2a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114d: cmp    rdi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1150: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (241) - 1, 0),
    /* 0x1156: movzx  edi,BYTE PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RSI, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1159: mov    r8d,edi [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x115c: and    r8b,0xf0 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R8, 240), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1160: cmp    r8b,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1164: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (232) - 1, 64),
    /* 0x116a: and    edi,0xf [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x116d: cmp    dil,0x5 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1171: jb     1301 <flow_5tuple_rss_hash_xdp+0x201> [exact-bpf: jb as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDI),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_6, 0, (227) - 1, 5),
    /* 0x1177: lea    rsi,[rsi+rdi*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RSI, HC_X86_RDI, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x117b: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x117e: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (222) - 1, 0),
    /* 0x1184: movzx  r11d,BYTE PTR [rcx+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RCX, 24), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1189: movzx  edi,BYTE PTR [rcx+0x19] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 25), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118d: movzx  ebx,BYTE PTR [rcx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBX, HC_X86_RCX, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1191: cmp    ebx,0x11 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1194: je     119f <flow_5tuple_rss_hash_xdp+0x9f> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RBX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (3) - 1, 17),
    /* 0x1196: cmp    ebx,0x6 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1199: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RBX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (212) - 1, 6),
    /* 0x119f: lea    r8,[rsi+0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R8, HC_X86_RSI, 0, 0, 1, 0, 4), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11a3: cmp    r8,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11a6: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (207) - 1, 0),
    /* 0x11ac: mov    eax,r11d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11af: shl    eax,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b2: or     eax,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11b4: mov    r8d,DWORD PTR [rcx+0x22] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R8, HC_X86_RCX, 34), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b8: mov    r10d,DWORD PTR [rcx+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, HC_X86_RCX, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11bc: bswap  r10d [exact-kinsn: bswap32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 0), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11bf: bswap  r8d [exact-kinsn: bswap32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11c2: movzx  edx,WORD PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11c5: movzx  edi,WORD PTR [rsi+0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RSI, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11c9: rol    dx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDX, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11cd: movzx  esi,dx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d0: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDI, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11d4: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d7: lea    r9d,[rax+r8*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_RAX, HC_X86_R8, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11db: lea    ebp,[r10-0x61c88647] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RBP, HC_X86_R10, 0, 0, 1, 0, -1640531527), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11e2: mov    edx,esi [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e4: shl    edx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11e7: or     edx,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11e9: lea    r15d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R15, HC_X86_RBX, HC_X86_RDX, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ed: lea    r14d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R14, HC_X86_RBX, HC_X86_RDX, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f1: add    r14d,0x12345678 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R14, 305419896), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11f8: sub    r9d,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x11fb: add    r9d,0xdeadbeef [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, -559038737), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1202: rol    r14d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R14, HC_X86_R14, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1206: xor    r14d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1209: lea    r9d,[r10+r15*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_R10, HC_X86_R15, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x120d: add    r9d,0xb06bd031 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, -1335111631), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1214: mov    r15d,r14d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R15, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1217: rol    r15d,0x6 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R15, HC_X86_R15, 6), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x121b: sub    ebp,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x121e: xor    r15d,ebp [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R15, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1221: add    r14d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1224: sub    r9d,r15d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1227: mov    ebp,r15d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBP, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122a: rol    ebp,0x8 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RBP, HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x122d: xor    ebp,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1230: add    r15d,r14d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R15, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1233: mov    r9d,ebp [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1236: rol    r9d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x123a: sub    r14d,ebp [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x123d: xor    r9d,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1240: add    ebp,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1243: sub    r15d,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R15, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1246: mov    r14d,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1249: rol    r14d,0x13 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R14, HC_X86_R14, 19), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x124d: xor    r14d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1250: add    r9d,ebp [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1253: xor    r8d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1256: rol    r8d,0x7 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R8, HC_X86_R8, 7), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x125a: sub    ebp,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x125d: add    r8d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1260: add    r9d,edx [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1263: add    r9d,r14d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1266: rol    r14d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R14, HC_X86_R14, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x126a: xor    r14d,ebp [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x126d: mov    edx,ebx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x126f: shl    edx,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1272: or     edx,eax [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1274: add    edx,r14d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1277: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x127a: mov    r10d,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127d: rol    r10d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1281: sub    edx,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1284: mov    r10d,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1287: rol    r10d,0xb [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 11), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x128b: xor    r8d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x128e: sub    r8d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1291: xor    r9d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1294: mov    r10d,r8d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1297: rol    r10d,0x19 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 25), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x129b: sub    r9d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x129e: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12a1: mov    r10d,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12a4: rol    r10d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12a8: sub    edx,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12ab: xor    r8d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12ae: mov    r10d,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b1: rol    r10d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12b5: sub    r8d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12b8: xor    r9d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12bb: rol    r8d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R8, HC_X86_R8, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12bf: sub    r9d,r8d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12c2: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12c5: rol    r9d,0x18 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R9, HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12c9: sub    edx,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12cc: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12cf: shl    esi,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSI, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d2: or     ebx,esi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12d4: xor    ebx,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12d6: xor    esi,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12d8: mov    BYTE PTR [rcx],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RBX, HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12da: mov    BYTE PTR [rcx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(HC_X86_RBX, HC_X86_RCX, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12dd: shr    esi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12e0: mov    BYTE PTR [rcx+0x2],sil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12e4: mov    BYTE PTR [rcx+0x3],r11b [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, HC_X86_RCX, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12e8: mov    BYTE PTR [rcx+0x4],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12eb: mov    BYTE PTR [rcx+0x5],dh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 5, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12ee: mov    eax,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f0: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12f3: mov    BYTE PTR [rcx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RCX, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12f6: shr    edx,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12f9: mov    BYTE PTR [rcx+0x7],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12fc: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1301: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1302: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1304: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1306: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1307: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
