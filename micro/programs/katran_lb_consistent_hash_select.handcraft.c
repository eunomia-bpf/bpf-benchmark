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
    /* 0x1100: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1101: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1103: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1105: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1107: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1109: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110a: push   rax [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110b: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x110e: mov    rbx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    /* 0x1112: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1114: cmp    rcx,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1117: ja     1610 <katran_lb_consistent_hash_select_xdp+0x510> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_4, BPF_REG_6, (666) - 1, 0),
    /* 0x111d: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1121: cmp    rsi,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1124: ja     1610 <katran_lb_consistent_hash_select_xdp+0x510> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_6, (663) - 1, 0),
    /* 0x112a: lea    rdx,[rcx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_4, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112e: cmp    rdx,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1131: ja     1610 <katran_lb_consistent_hash_select_xdp+0x510> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_6, (660) - 1, 0),
    /* 0x1137: movabs rax,0x9e3779b97f4a7c15 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x9e3779b97f4a7c15ULL),
    /* 0x1141: mov    r10,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1144: sub    r10,rsi [exact-kinsn: sub64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x1147: movzx  esi,WORD PTR [rcx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x114b: cmp    esi,0xdd86 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1151: je     11e6 <katran_lb_consistent_hash_select_xdp+0xe6> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (67) - 1, 56710),
    /* 0x1157: cmp    esi,0x8 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x115a: jne    1215 <katran_lb_consistent_hash_select_xdp+0x115> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (90) - 1, 8),
    /* 0x1160: lea    rsi,[rcx+0x2a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1164: mov    r9d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x116a: cmp    rsi,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x116d: ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_6, (623) - 1, 0),
    /* 0x1173: movzx  edx,BYTE PTR [rdx] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1176: and    dl,0xf [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 15), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1179: cmp    dl,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x117c: jne    15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 5),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (612) - 1),
    /* 0x1182: movzx  edx,BYTE PTR [rcx+0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 28), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1186: movzx  esi,BYTE PTR [rcx+0x1d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 29), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118a: and    edx,0x3f [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 63), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x118d: or     dx,si [exact-kinsn: or16 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORW),
    /* 0x1190: jne    15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: jne ordinary BPF branch from preceding or] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xffff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 65535),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (596) - 1),
    /* 0x1196: movzx  r14d,BYTE PTR [rcx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x119b: mov    esi,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a0: cmp    r14d,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11a4: je     1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_8, 0, (71) - 1, 1),
    /* 0x11aa: movzx  edi,BYTE PTR [rcx+0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ae: movzx  ebp,WORD PTR [rcx+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b2: movzx  r11d,WORD PTR [rcx+0x22] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b7: movzx  r8d,BYTE PTR [rcx+0x24] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 36), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11bc: movzx  edx,BYTE PTR [rcx+0x25] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 37), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c0: mov    r15d,DWORD PTR [rcx+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c4: cmp    r14d,0x11 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11c8: je     15e0 <katran_lb_consistent_hash_select_xdp+0x4e0> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_8, 0, (565) - 1, 17),
    /* 0x11ce: cmp    r14d,0x6 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11d2: jne    1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_8, 0, (57) - 1, 6),
    /* 0x11d4: lea    r12,[rcx+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R12, BPF_REG_4, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11d8: cmp    r12,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x11db: ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -416),
    HC_MOV64_REG(BPF_REG_7, BPF_REG_6),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (564) - 1),
    /* 0x11e1: jmp    161f <katran_lb_consistent_hash_select_xdp+0x51f> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (600) - 1),
    /* 0x11e6: lea    rdx,[rcx+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_4, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11ea: mov    r9d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f0: cmp    rdx,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x11f3: ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_6, (558) - 1, 0),
    /* 0x11f9: movzx  r12d,BYTE PTR [rcx+0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R12, BPF_REG_4, 28), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11fe: cmp    r12d,0x2c [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1202: je     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -416),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 44),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (549) - 1),
    /* 0x1208: cmp    r12d,0x3a [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x120c: jne    123e <katran_lb_consistent_hash_select_xdp+0x13e> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -416),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 58),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (25) - 1),
    /* 0x120e: mov    esi,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1213: jmp    1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (19) - 1),
    /* 0x1215: add    r10,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1218: mov    rdx,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x121b: shl    rdx,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x121f: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1222: mov    rsi,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1225: shr    rsi,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1229: add    rsi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x122c: add    rsi,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1230: xor    rsi,r10 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1233: mov    r9d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1239: jmp    15ee <katran_lb_consistent_hash_select_xdp+0x4ee> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (520) - 1),
    /* 0x123e: movzx  edx,BYTE PTR [rcx+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1242: movzx  r15d,BYTE PTR [rcx+0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1247: movzx  r14d,WORD PTR [rcx+0x1a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_4, 26), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x124c: mov    edi,DWORD PTR [rcx+0x1e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 30), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124f: mov    r11d,DWORD PTR [rcx+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1253: mov    ebp,DWORD PTR [rcx+0x2a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_4, 42), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1256: mov    r13d,DWORD PTR [rcx+0x2e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_7, BPF_REG_4, 46), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x125a: mov    r8d,0xdeadc0ff [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 3735929087), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1260: add    r8d,DWORD PTR [rcx+0x22] [exact-kinsn: add32 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1264: mov    esi,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1269: cmp    r12d,0x11 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x126d: je     1288 <katran_lb_consistent_hash_select_xdp+0x188> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -416),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 17),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (14) - 1),
    /* 0x126f: cmp    r12d,0x6 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1273: jne    1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -416),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 6),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-36) - 1),
    /* 0x1275: mov    QWORD PTR [rsp],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1279: lea    rdi,[rcx+0x52] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 82), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x127d: cmp    rdi,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1280: ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_6, (479) - 1, 0),
    /* 0x1286: jmp    1299 <katran_lb_consistent_hash_select_xdp+0x199> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (6) - 1),
    /* 0x1288: mov    QWORD PTR [rsp],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x128c: lea    rdi,[rcx+0x46] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 70), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1290: cmp    rdi,rbx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1293: ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_6, (473) - 1, 0),
    /* 0x1299: cmp    r12d,0x6 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x129d: jne    1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -416),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 6),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-54) - 1),
    /* 0x129f: cmp    r13d,0x101640a [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12a6: jne    1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_7, 0, (-55) - 1, 16868362),
    /* 0x12a8: movzx  edi,WORD PTR [rcx+0x40] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 64), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12ac: mov    r9d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b2: cmp    edi,0x901f [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12b8: jne    15ee <katran_lb_consistent_hash_select_xdp+0x4ee> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_1, 0, (462) - 1, 36895),
    /* 0x12be: mov    esi,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c3: mov    r9d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c9: cmp    r10,0x5ea [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x12d0: jg     15ee <katran_lb_consistent_hash_select_xdp+0x4ee> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -432),
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_6, 0, 2, 1514),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (451) - 1),
    /* 0x12d6: shr    r15b,0x4 [exact-kinsn: shr8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 4), MICRO_HANDCRAFT_BPF_X86_SHRB),
    /* 0x12da: mov    r12d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12dd: shl    r12b,0x4 [exact-kinsn: shl8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 4), MICRO_HANDCRAFT_BPF_X86_SHLB),
    /* 0x12e1: or     r12b,r15b [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R12, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x12e4: rol    r14w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x12e9: movzx  esi,r14w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12ed: mov    edi,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_1, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ef: and    edi,0xff000000 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, -16777216), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x12f5: lea    r9d,[r11-0x21523f01] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_R11, 0, 0, 1, 0, -559038209), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12fc: mov    r10d,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ff: and    r10d,0xff0000 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 16711680), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1306: add    r10d,edi [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1309: mov    edi,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_1, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x130b: and    edi,0xff00 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 65280), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1311: add    edi,r10d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1314: movzx  ebx,bpl [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_6, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1318: add    ebx,edi [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x131a: mov    rdx,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x131e: mov    edi,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1320: sub    edi,r11d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1323: mov    r14d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1326: rol    r14d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x132a: xor    r14d,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x132d: add    r9d,r8d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1330: sub    r8d,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1333: mov    r10d,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1336: rol    r10d,0x6 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 6), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x133a: xor    r10d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x133d: add    r14d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1340: lea    edi,[r10+r14*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, HC_X86_R10, BPF_REG_8, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1344: sub    r9d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1347: rol    r10d,0x8 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 8), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x134b: movzx  r8d,WORD PTR [rcx+0x3e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 62), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1350: xor    r10d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1353: sub    r14d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1356: mov    r11d,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1359: rol    r11d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R11, HC_X86_R11, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x135d: xor    r11d,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1360: add    r10d,edi [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1363: sub    edi,r11d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1366: mov    r14d,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1369: rol    r14d,0x13 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 19), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x136d: xor    r14d,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1370: add    r11d,r10d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1373: lea    r9d,[r14+r11*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_8, HC_X86_R11, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1377: sub    r10d,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x137a: rol    r14d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x137e: add    r11d,ebx [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1381: xor    r10d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1384: xor    r10d,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1387: mov    edi,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x138a: rol    edi,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x138d: sub    r10d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1390: mov    edi,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1393: rol    edi,0xb [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 11), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1396: xor    r11d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1399: sub    r11d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x139c: xor    r9d,r11d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x139f: mov    edi,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13a2: rol    edi,0x19 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 25), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x13a5: sub    r9d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x13a8: xor    r10d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13ab: mov    edi,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13ae: rol    edi,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x13b1: sub    r10d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x13b4: xor    r11d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13b7: mov    edi,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13ba: rol    edi,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x13bd: sub    r11d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x13c0: xor    r9d,r11d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13c3: rol    r11d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R11, HC_X86_R11, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x13c7: sub    r9d,r11d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x13ca: mov    edi,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13cd: rol    edi,0x18 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 24), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x13d0: xor    r9d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13d3: sub    r9d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x13d6: add    r9d,0xe0adc0f7 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, -525483785), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x13dd: mov    r11d,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e0: add    r11d,0x70ccc0f7 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 1892466935), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x13e7: mov    r10d,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13ea: xor    r10d,0xe0adc0f7 [exact-kinsn: xor32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, -525483785), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13f1: mov    edi,0x70cc0000 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 1892417536), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13f6: shrd   edi,r11d,0x12 [exact-kinsn: shrd imm kinsn] */
    HC_KINSN(HC_SHD_PAYLOAD(BPF_REG_1, HC_X86_R11, 18), MICRO_HANDCRAFT_BPF_X86_SHRDL),
    /* 0x13fb: sub    r10d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x13fe: xor    r9d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1401: mov    edi,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1404: rol    edi,0xb [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 11), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1407: sub    r9d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x140a: xor    r11d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x140d: mov    edi,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1410: rol    edi,0x19 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 25), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1413: sub    r11d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1416: mov    edi,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1419: rol    edi,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x141c: xor    r10d,r11d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x141f: sub    r10d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1422: xor    r9d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1425: mov    edi,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1428: rol    edi,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x142b: sub    r9d,edi [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x142e: xor    r11d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1431: rol    r9d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R9, HC_X86_R9, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1435: sub    r11d,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1438: xor    r10d,r11d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x143b: rol    r11d,0x18 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R11, HC_X86_R11, 24), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x143f: sub    r10d,r11d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1442: mov    edi,0xffff0001 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 4294901761), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1447: imul   rdi,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x144b: shr    rdi,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x144f: mov    r9d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1452: shl    r9d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1456: or     r9d,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1459: sub    r10d,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x145c: mov    rdi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x145f: add    rdi,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1462: mov    r9,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1465: shl    r9,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1469: add    r9,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x146c: mov    r11,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x146f: shr    r11,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1473: add    r9,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1476: add    r9,0x101640a [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16868362), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x147d: xor    r9,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1480: mov    r11,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1483: shl    r11,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1487: add    r11,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x148a: add    r11,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x148d: mov    rdi,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1490: shr    rdi,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1494: mov    ebx,0x901f0000 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 2417950720), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1499: add    rbx,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x149c: add    rbx,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x149f: xor    rbx,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14a2: mov    rdi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14a5: shl    rdi,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x14a9: mov    r9,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14ac: shr    r9,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x14b0: add    rdi,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14b3: add    rdi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14b6: add    rdi,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14b9: xor    rdi,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14bc: mov    r9,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14bf: shl    r9,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x14c3: add    r9,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14c6: mov    r10,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14c9: shr    r10,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x14cd: add    r9,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14d0: inc    r9 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x14d3: xor    r9,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14d6: mov    rdi,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14d9: shl    rdi,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x14dd: add    rdi,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14e0: mov    r10,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14e3: shr    r10,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x14e7: add    r10,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14ea: xor    r10,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14ed: mov    r11,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14f0: shl    r11,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x14f4: add    r11,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14f7: add    r11,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14fa: mov    r9,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x14fd: shr    r9,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1501: add    r9,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1504: rol    r8w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1509: shl    r8d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x150d: and    edx,0xffff0000 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, -65536), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1513: xor    edx,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1516: mov    edi,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1518: add    edi,0x14 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 20), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x151b: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x151f: movzx  r8d,r12b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1523: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1526: mov    r11d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1529: shr    r11d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x152d: add    rdi,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1530: add    rdi,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1533: add    rdi,0xdf3b [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 57147), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x153a: mov    r8d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x153d: shr    r8d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1541: movzx  r11d,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1545: add    r11,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1548: cmp    rdi,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x154f: cmovb  r11,rdi [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_CMOVBQ),
    /* 0x1553: mov    edi,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1556: shr    edi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1559: movzx  r8d,r11w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x155d: add    r8,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1560: cmp    r11,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1567: cmovb  r8,r11 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_5, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_CMOVBQ),
    /* 0x156b: mov    edi,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x156e: shr    edi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1571: movzx  r11d,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1575: add    r11,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1578: cmp    r8,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x157f: cmovb  r11,r8 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R11, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_CMOVBQ),
    /* 0x1583: mov    edi,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1586: shr    edi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1589: add    edi,r11d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x158c: xor    r9,r10 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x158f: or     edx,0x10ac [exact-kinsn: or32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 4268), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1595: shl    rdx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1599: or     rdx,0x200c80a [exact-kinsn: or64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 33605642), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x15a0: cmp    r11,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x15a7: cmovb  edi,r11d [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_CMOVBL),
    /* 0x15ab: shl    edi,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x15ae: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x15b1: movabs rsi,0x200ffff000b [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x200ffff000bULL),
    /* 0x15bb: xor    rsi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x15be: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x15c1: mov    rdx,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x15c4: shl    rdx,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x15c8: mov    rdi,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x15cb: shr    rdi,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x15cf: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x15d2: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x15d5: add    rdx,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x15d8: xor    rdx,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x15db: jmp    1875 <katran_lb_consistent_hash_select_xdp+0x775> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (375) - 1),
    /* 0x15e0: lea    r12,[rcx+0x32] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R12, BPF_REG_4, 0, 0, 1, 0, 50), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x15e4: cmp    r12,rbx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x15e7: jbe    161f <katran_lb_consistent_hash_select_xdp+0x51f> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -416),
    HC_MOV64_REG(BPF_REG_7, BPF_REG_6),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (38) - 1),
    /* 0x15e9: mov    esi,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15ee: mov    rdx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x15f1: shl    rdx,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x15f5: mov    rdi,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x15f8: shr    rdi,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x15fc: add    rdi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x15ff: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1602: add    rdx,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1605: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1608: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x160b: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1610: add    rsp,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1614: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1615: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1617: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1619: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x161b: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x161d: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x161e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x161f: cmp    r15d,0x101640a [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1626: jne    1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_9, 0, (-557) - 1, 16868362),
    /* 0x162c: movzx  r9d,WORD PTR [rcx+0x2c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_4, 44), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1631: cmp    r9d,0x901f [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1638: jne    1233 <katran_lb_consistent_hash_select_xdp+0x133> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -440),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 36895),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-566) - 1),
    /* 0x163e: mov    r9d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1644: cmp    r14b,0x6 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1648: jne    15ee <katran_lb_consistent_hash_select_xdp+0x4ee> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 6),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-53) - 1),
    /* 0x164a: mov    esi,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x164f: mov    r9d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1655: cmp    r10,0x5ea [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x165c: jg     15ee <katran_lb_consistent_hash_select_xdp+0x4ee> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -432),
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_6, 0, 2, 1514),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-64) - 1),
    /* 0x165e: rol    bp,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1662: movzx  esi,bp [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_2, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1665: shl    r8d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1669: shl    edx,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x166c: or     r11d,r8d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x166f: or     r11d,edx [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1672: movzx  r9d,WORD PTR [rcx+0x2a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_4, 42), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1677: mov    ebx,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x167a: add    ebx,0x70ccc0f7 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 1892466935), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1680: mov    r10d,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1683: xor    r10d,0xe0adc0f7 [exact-kinsn: xor32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, -525483785), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x168a: mov    ebp,0x70cc0000 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 1892417536), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x168f: shrd   ebp,ebx,0x12 [exact-kinsn: shrd imm kinsn] */
    HC_KINSN(HC_SHD_ARCH_PAYLOAD(HC_X86_RBP, BPF_REG_6, 18), MICRO_HANDCRAFT_BPF_X86_SHRDL),
    /* 0x1693: sub    r10d,ebp [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1696: lea    ebp,[r11-0x1f523f09] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RBP, HC_X86_R11, 0, 0, 1, 0, -525483785), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x169d: xor    ebp,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x16a0: mov    r14d,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16a3: rol    r14d,0xb [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 11), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x16a7: sub    ebp,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x16aa: mov    r14d,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_8, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16ad: rol    r14d,0x19 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 25), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x16b1: xor    ebx,ebp [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_6, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x16b3: sub    ebx,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x16b6: xor    r10d,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x16b9: mov    r14d,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16bc: rol    r14d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x16c0: sub    r10d,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x16c3: xor    ebp,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x16c6: mov    r14d,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16c9: rol    r14d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x16cd: sub    ebp,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x16d0: xor    ebx,ebp [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_6, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x16d2: rol    ebp,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RBP, HC_X86_RBP, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x16d5: sub    ebx,ebp [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_6, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x16d7: xor    r10d,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x16da: rol    ebx,0x18 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_6, BPF_REG_6, 24), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x16dd: sub    r10d,ebx [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x16e0: mov    ebx,0xffff0001 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 4294901761), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16e5: imul   rbx,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x16e9: shr    rbx,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x16ed: mov    ebp,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16ef: shl    ebp,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x16f2: or     ebp,ebx [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x16f4: sub    r10d,ebp [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x16f7: mov    r11d,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16fa: add    r11,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x16fd: mov    rbx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1700: shl    rbx,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1704: mov    r14,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1707: shr    r14,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x170b: add    r14,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x170e: add    rbx,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1711: add    rbx,0x101640a [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 16868362), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1718: xor    rbx,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x171b: mov    r11,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x171e: shl    r11,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1722: mov    r14,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1725: shr    r14,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1729: add    r14,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x172c: add    r11,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x172f: add    r11,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1732: mov    r14d,0x901f0000 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_8, 2417950720), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1738: add    r14,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x173b: xor    r14,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x173e: mov    r11,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1741: shl    r11,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1745: mov    rbx,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1748: shr    rbx,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x174c: add    r11,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x174f: add    r11,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1752: add    r11,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1755: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1758: mov    r10,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x175b: shl    r10,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x175f: add    r10,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1762: mov    rbx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1765: shr    rbx,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1769: add    r10,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x176c: inc    r10 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x176f: xor    r10,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1772: mov    rbx,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1775: shl    rbx,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1779: add    rbx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x177c: mov    r11,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x177f: shr    r11,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1783: add    r11,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1786: xor    r11,r10 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1789: mov    rbx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x178c: shl    rbx,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1790: add    rbx,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1793: add    rbx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1796: mov    r10,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1799: shr    r10,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x179d: rol    r9w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R9, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x17a2: add    r10,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x17a5: shl    r9d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x17a9: or     edx,r8d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x17ac: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x17af: mov    r8d,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x17b2: add    r8d,0x14 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 20), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x17b6: rol    r8w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x17bb: movzx  r8d,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x17bf: mov    r9d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x17c2: shr    r9d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x17c6: add    r8,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x17c9: lea    rdi,[r9+r8*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, HC_X86_R9, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x17cd: add    rdi,0xdf3b [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 57147), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x17d4: mov    r8d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x17d7: shr    r8d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x17db: movzx  r9d,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x17df: add    r9,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x17e2: cmp    rdi,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x17e9: cmovb  r9,rdi [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_CMOVBQ),
    /* 0x17ed: mov    edi,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x17f0: shr    edi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x17f3: movzx  r8d,r9w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x17f7: add    r8,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x17fa: cmp    r9,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1801: cmovb  r8,r9 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMOVBQ),
    /* 0x1805: mov    edi,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1808: shr    edi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x180b: movzx  r9d,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x180f: add    r9,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1812: cmp    r8,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1819: cmovb  r9,r8 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_CMOVBQ),
    /* 0x181d: mov    edi,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1820: shr    edi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1823: add    edi,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1826: xor    r10,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1829: or     edx,0x10ac [exact-kinsn: or32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 4268), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x182f: shl    rdx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1833: or     rdx,0x200c80a [exact-kinsn: or64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 33605642), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x183a: cmp    r9,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1841: cmovb  edi,r9d [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMOVBL),
    /* 0x1845: shl    edi,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1848: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x184b: movabs rsi,0x200ffff000b [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x200ffff000bULL),
    /* 0x1855: xor    rsi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1858: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x185b: mov    rdx,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x185e: shl    rdx,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1862: mov    rdi,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1865: shr    rdi,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1869: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x186c: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x186f: add    rdx,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1872: xor    rdx,r10 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1875: mov    rsi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1878: shl    rsi,0x6 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 6), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x187c: add    rsi,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x187f: mov    rdi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1882: shr    rdi,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1886: add    rsi,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1889: add    rsi,0x3 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x188d: xor    rsi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1890: mov    r9d,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1896: jmp    15ee <katran_lb_consistent_hash_select_xdp+0x4ee> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-377) - 1),
};

HC_EXPORT_PROGRAM(program)
