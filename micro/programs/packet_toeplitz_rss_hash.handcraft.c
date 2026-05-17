#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))
#define HC_LEA_ARCH_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | (1ULL << 48))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RSI, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (4) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-9) - 1, 0),
    /* 0x1118: lea    rdx,[rsi+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111c: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x111f: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-16) - 1, 0),
    /* 0x1121: movzx  ecx,WORD PTR [rsi+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RSI, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1125: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RCX, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1129: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x112c: cmp    ecx,0x800 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1132: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-25) - 1, 2048),
    /* 0x1134: movzx  ecx,BYTE PTR [rsi+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RSI, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1138: and    cl,0xf [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_RCX, 15), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x113b: cmp    cl,0x5 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x113e: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-33) - 1, 5),
    /* 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1144: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 31),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-38) - 1, 6),
    /* 0x1146: lea    rdi,[rsi+0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RSI, 0, 0, 1, 0, 31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114a: lea    r8,[rsi+0x22] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_R8, HC_X86_RSI, 0, 0, 1, 0, 34), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114e: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1150: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1153: jmp    117c <packet_toeplitz_rss_hash_xdp+0x7c> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (20) - 1, 0),
    /* 0x1155: mov    r11d,0xc2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 194), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x115b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: mov    dl,0x8 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 8), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1162: sub    dl,cl [exact-kinsn: sub8 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SUBB),
    /* 0x1164: mov    ecx,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1166: shr    r11d,cl [exact-kinsn: shr32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1169: or     r10d,r11d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x116c: xor    eax,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x116f: inc    r9d [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1172: cmp    r9d,0x68 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1176: je     1389 <packet_toeplitz_rss_hash_xdp+0x289> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (213) - 1, 104),
    /* 0x117c: mov    edx,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117f: shr    edx,0x3 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 3), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1182: cmp    r9d,0x1f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1186: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, (12) - 1, 31),
    /* 0x1188: cmp    r9d,0x3f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x118c: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, (9) - 1, 63),
    /* 0x118e: cmp    r9d,0x4f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1192: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, (6) - 1, 79),
    /* 0x1194: mov    rcx,rdi [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1197: cmp    r9d,0x5f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x119b: ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_6, 0, (5) - 1, 95),
    /* 0x119d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    ecx,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a2: add    rcx,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a5: movzx  r10d,BYTE PTR [rcx] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R10, HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a9: mov    ecx,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ac: and    ecx,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11af: shl    r10d,cl [exact-kinsn: shl32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b2: test   r10b,r10b [control-flow-operand: test folded into BPF branch] */
    /* 0x11b5: jns    116f <packet_toeplitz_rss_hash_xdp+0x6f> [exact-bpf: jns as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, 128),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-38) - 1, 0),
    /* 0x11b7: cmp    edx,0x5 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ba: jle    11e0 <packet_toeplitz_rss_hash_xdp+0xe0> [exact-bpf: jle as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_6, 0, (15) - 1, 5),
    /* 0x11bc: cmp    edx,0x8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11bf: jle    1203 <packet_toeplitz_rss_hash_xdp+0x103> [exact-bpf: jle as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_6, 0, (27) - 1, 8),
    /* 0x11c1: cmp    edx,0xa [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11c4: jg     123d <packet_toeplitz_rss_hash_xdp+0x13d> [exact-bpf: jg as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (46) - 1, 10),
    /* 0x11c6: cmp    edx,0x9 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11c9: jne    1288 <packet_toeplitz_rss_hash_xdp+0x188> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (71) - 1, 9),
    /* 0x11cf: mov    r11d,0x43 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 67), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d5: mov    r10d,0x67253d00 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1730493696), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11db: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (85) - 1, 0),
    /* 0x11e0: cmp    edx,0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11e3: jg     121e <packet_toeplitz_rss_hash_xdp+0x11e> [exact-bpf: jg as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (24) - 1, 2),
    /* 0x11e5: test   edx,edx [control-flow-operand: test folded into BPF branch] */
    /* 0x11e7: je     125e <packet_toeplitz_rss_hash_xdp+0x15e> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, -1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (44) - 1, 0),
    /* 0x11e9: cmp    edx,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ec: jne    12a4 <packet_toeplitz_rss_hash_xdp+0x1a4> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (66) - 1, 1),
    /* 0x11f2: mov    r11d,0x25 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f8: mov    r10d,0x5a56da00 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1515641344), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fe: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (70) - 1, 0),
    /* 0x1203: cmp    edx,0x6 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1206: je     1250 <packet_toeplitz_rss_hash_xdp+0x150> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (28) - 1, 6),
    /* 0x1208: cmp    edx,0x7 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x120b: jne    127a <packet_toeplitz_rss_hash_xdp+0x17a> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (40) - 1, 7),
    /* 0x120d: mov    r11d,0x25 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1213: mov    r10d,0xc2416700 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 3259066112), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1219: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (59) - 1, 0),
    /* 0x121e: cmp    edx,0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1221: je     126c <packet_toeplitz_rss_hash_xdp+0x16c> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (27) - 1, 3),
    /* 0x1223: cmp    edx,0x4 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1226: jne    12b2 <packet_toeplitz_rss_hash_xdp+0x1b2> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (49) - 1, 4),
    /* 0x122c: mov    r11d,0xc2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 194), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1232: mov    r10d,0x255b0e00 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 626724352), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1238: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (48) - 1, 0),
    /* 0x123d: cmp    edx,0xb [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1240: jne    1296 <packet_toeplitz_rss_hash_xdp+0x196> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (31) - 1, 11),
    /* 0x1242: mov    r11d,0x8f [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 143), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1248: mov    r10d,0x3d43a300 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1027842816), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124e: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (40) - 1, 0),
    /* 0x1250: mov    r11d,0x67 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 103), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1256: mov    r10d,0xec24100 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 247611648), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x125c: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (35) - 1, 0),
    /* 0x125e: mov    r11d,0xda [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 218), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1264: mov    r10d,0x6d5a5600 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1834636800), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x126a: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (30) - 1, 0),
    /* 0x126c: mov    r11d,0xe [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1272: mov    r10d,0xda255b00 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 3659881216), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1278: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (25) - 1, 0),
    /* 0x127a: mov    r11d,0x3d [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 61), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1280: mov    r10d,0x41672500 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1097278720), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1286: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (20) - 1, 0),
    /* 0x1288: mov    r11d,0xa3 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 163), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x128e: mov    r10d,0x253d4300 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 624771840), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1294: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (15) - 1, 0),
    /* 0x1296: mov    r11d,0xb0 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 176), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x129c: mov    r10d,0x43a38f00 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1134792448), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12a2: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (10) - 1, 0),
    /* 0x12a4: mov    r11d,0x5b [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 91), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12aa: mov    r10d,0x56da2500 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1457136896), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b0: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (5) - 1, 0),
    /* 0x12b2: mov    r11d,0x41 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 65), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b8: mov    r10d,0x5b0ec200 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1527693824), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12be: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x12c0: or     r10d,r11d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12c3: test   ecx,ecx [control-flow-operand: test folded into BPF branch] */
    /* 0x12c5: je     116c <packet_toeplitz_rss_hash_xdp+0x6c> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, -1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-147) - 1, 0),
    /* 0x12cb: shl    r10d,cl [exact-kinsn: shl32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12ce: mov    r11d,0x25 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12d4: cmp    edx,0x5 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12d7: jle    12f3 <packet_toeplitz_rss_hash_xdp+0x1f3> [exact-bpf: jle as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_6, 0, (13) - 1, 5),
    /* 0x12d9: cmp    edx,0x8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12dc: jle    1310 <packet_toeplitz_rss_hash_xdp+0x210> [exact-bpf: jle as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_6, 0, (23) - 1, 8),
    /* 0x12de: cmp    edx,0xa [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12e1: jg     1342 <packet_toeplitz_rss_hash_xdp+0x242> [exact-bpf: jg as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (38) - 1, 10),
    /* 0x12e3: cmp    edx,0x9 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12e6: jne    135d <packet_toeplitz_rss_hash_xdp+0x25d> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (44) - 1, 9),
    /* 0x12e8: mov    r11d,0xa3 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 163), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ee: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-176) - 1, 0),
    /* 0x12f3: cmp    edx,0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12f6: jg     1329 <packet_toeplitz_rss_hash_xdp+0x229> [exact-bpf: jg as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (20) - 1, 2),
    /* 0x12f8: test   edx,edx [control-flow-operand: test folded into BPF branch] */
    /* 0x12fa: je     1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, -1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-183) - 1, 0),
    /* 0x1300: cmp    edx,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1303: jne    1373 <packet_toeplitz_rss_hash_xdp+0x273> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (37) - 1, 1),
    /* 0x1305: mov    r11d,0x5b [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 91), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x130b: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-189) - 1, 0),
    /* 0x1310: cmp    edx,0x6 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1313: je     1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (-192) - 1, 6),
    /* 0x1319: cmp    edx,0x7 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x131c: jne    1352 <packet_toeplitz_rss_hash_xdp+0x252> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (19) - 1, 7),
    /* 0x131e: mov    r11d,0x3d [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 61), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1324: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-198) - 1, 0),
    /* 0x1329: cmp    edx,0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x132c: je     1155 <packet_toeplitz_rss_hash_xdp+0x55> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (-203) - 1, 3),
    /* 0x1332: cmp    edx,0x4 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1335: jne    137e <packet_toeplitz_rss_hash_xdp+0x27e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (22) - 1, 4),
    /* 0x1337: mov    r11d,0x41 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 65), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x133d: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-207) - 1, 0),
    /* 0x1342: cmp    edx,0xb [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1345: jne    1368 <packet_toeplitz_rss_hash_xdp+0x268> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (10) - 1, 11),
    /* 0x1347: mov    r11d,0xb0 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 176), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x134d: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-213) - 1, 0),
    /* 0x1352: mov    r11d,0x43 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 67), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1358: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-216) - 1, 0),
    /* 0x135d: mov    r11d,0x8f [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 143), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1363: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-219) - 1, 0),
    /* 0x1368: mov    r11d,0xd0 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 208), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x136e: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-222) - 1, 0),
    /* 0x1373: mov    r11d,0xe [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1379: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-225) - 1, 0),
    /* 0x137e: mov    r11d,0x67 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 103), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1384: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-228) - 1, 0),
    /* 0x1389: mov    edx,DWORD PTR [rsi+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x138c: movzx  ecx,BYTE PTR [rsi+0x2a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RSI, 42), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1390: movzx  r8d,BYTE PTR [rsi+0x2b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R8, HC_X86_RSI, 43), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1395: movzx  r9d,BYTE PTR [rsi+0x2c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSI, 44), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x139a: movzx  r10d,BYTE PTR [rsi+0x2d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R10, HC_X86_RSI, 45), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x139f: mov    r11,rax [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13a2: shl    r11,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13a6: xor    edx,DWORD PTR [rsi+0x22] [exact-kinsn: xor32 memory-source kinsn] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 34), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13a9: bswap  edx [exact-kinsn: bswap32 kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x13ab: mov    edi,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13ad: xor    edi,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13af: or     rdi,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13b2: shl    rcx,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13b6: shl    r8,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13ba: or     r8,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13bd: shl    r9,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c1: or     r9,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13c4: shl    r10,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c8: or     rdx,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13cb: or     rdx,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13ce: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x13d1: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13d4: mov    r8,rdx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13d7: shl    r8,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13da: not    al [exact-kinsn: not8 reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13dc: mov    ecx,eax [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13de: shr    rdx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13e1: or     rdx,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13e4: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13e7: mov    QWORD PTR [rsi],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ea: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13ef: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
