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
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <tetragon_process_event_arg_filter_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_2, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-3) - 1, 0),
    /* 0x1118: lea    rdx,[rsi+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi+0x8],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1128: jne    110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x112a: cmp    DWORD PTR [rsi+0xc],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x112e: jne    110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-20) - 1),
    /* 0x1130: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113a: sub    rsp,0x40 [exact-kinsn: sub64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 64), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x113e: mov    QWORD PTR [rsp+0x10],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1143: lea    rdi,[rsi+0x2f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1147: movabs r11,0xe7037ed1a0b428db [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xe7037ed1a0b428dbULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -424),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1151: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1154: jmp    117e <tetragon_process_event_arg_filter_xdp+0x7e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (14) - 1),
    /* 0x1156: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x1160: shl    rcx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1164: mov    eax,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1167: or     rax,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x116a: xor    r11,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x116d: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1170: add    rdi,0x20 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1174: cmp    r8,0x20 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1178: je     1406 <tetragon_process_event_arg_filter_xdp+0x306> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, (325) - 1, 32),
    /* 0x117e: movzx  r14d,BYTE PTR [rdi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1183: movzx  ecx,BYTE PTR [rdi-0x12] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -18), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1187: shl    ecx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x118a: or     rcx,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x118d: cmp    ecx,0x4 [absorbed-control-flow: cmp folded into following ordinary BPF jle] */
    /* 0x1190: jle    11b0 <tetragon_process_event_arg_filter_xdp+0xb0> [exact-bpf: jle ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_4, 0, (12) - 1, 4),
    /* 0x1192: cmp    ecx,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1195: je     11c8 <tetragon_process_event_arg_filter_xdp+0xc8> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_4, 0, (21) - 1, 5),
    /* 0x1197: cmp    ecx,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x119a: je     11d6 <tetragon_process_event_arg_filter_xdp+0xd6> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_4, 0, (28) - 1, 9),
    /* 0x119c: cmp    ecx,0xd [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x119f: jne    11f2 <tetragon_process_event_arg_filter_xdp+0xf2> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_4, 0, (43) - 1, 13),
    /* 0x11a1: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11a3: movabs r12,0x59000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x59000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11ad: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (39) - 1),
    /* 0x11af: nop [padding: padding is not part of BPF semantics] */
    /* 0x11b0: cmp    ecx,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11b3: je     11e4 <tetragon_process_event_arg_filter_xdp+0xe4> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_4, 0, (26) - 1, 1),
    /* 0x11b5: cmp    ecx,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11b8: jne    11f2 <tetragon_process_event_arg_filter_xdp+0xf2> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_4, 0, (33) - 1, 2),
    /* 0x11ba: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bc: movabs r12,0x23000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x23000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11c6: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (29) - 1),
    /* 0x11c8: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11ca: movabs r12,0x37000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x37000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11d4: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (21) - 1),
    /* 0x11d6: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11d8: movabs r12,0x41000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x41000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11e2: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (13) - 1),
    /* 0x11e4: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e6: movabs r12,0x11000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x11000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11f0: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (5) - 1),
    /* 0x11f2: mov    dl,0x1 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11f4: xor    r12d,r12d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11f7: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1200: movzx  esi,WORD PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1204: movzx  r9d,BYTE PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1209: shl    r9d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x120d: or     r9,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1210: movzx  esi,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1214: shl    esi,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1217: or     rsi,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x121a: movzx  r10d,BYTE PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x121f: shl    r10,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1223: movzx  ebx,BYTE PTR [rdi-0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1227: shl    rbx,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x122b: or     rbx,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x122e: or     rbx,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1231: cmp    rsi,0x68736162 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1238: je     1250 <tetragon_process_event_arg_filter_xdp+0x150> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_2, 0, (5) - 1, 1752392034),
    /* 0x123a: cmp    esi,0x6c727563 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1240: jne    1260 <tetragon_process_event_arg_filter_xdp+0x160> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (7) - 1, 1819440483),
    /* 0x1242: mov    esi,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1247: jmp    1290 <tetragon_process_event_arg_filter_xdp+0x190> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (17) - 1),
    /* 0x1249: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: mov    esi,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1255: jmp    1290 <tetragon_process_event_arg_filter_xdp+0x190> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (14) - 1),
    /* 0x1257: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1260: mov    esi,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1265: movabs rax,0x6e6f68747970 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x6e6f68747970ULL),
    /* 0x126f: cmp    rbx,rax [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1272: je     1290 <tetragon_process_event_arg_filter_xdp+0x190> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_X, BPF_REG_6, BPF_REG_0, (9) - 1, 0),
    /* 0x1274: xor    esi,esi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1276: cmp    r9d,0x6873 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 26739), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x127d: sete   sil [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_STACK_PAYLOAD(BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_SETE),
    /* 0x1281: shl    esi,0x2 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1284: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1290: mov    r15d,DWORD PTR [rdi-0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -31), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1294: test   dl,dl [absorbed-control-flow: test folded into following ordinary BPF jne] */
    /* 0x1296: jne    1160 <tetragon_process_event_arg_filter_xdp+0x60> [exact-bpf: jne ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 255),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-127) - 1),
    /* 0x129c: mov    rcx,r12 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x129f: mov    QWORD PTR [rsp+0x20],r14 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_8, HC_X86_RSP, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12a4: mov    QWORD PTR [rsp],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12a8: movzx  r11d,BYTE PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ad: movzx  eax,BYTE PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12b1: mov    QWORD PTR [rsp+0x28],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12b6: movzx  ebp,BYTE PTR [rdi-0xe] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ba: movzx  eax,BYTE PTR [rdi-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12be: mov    DWORD PTR [rsp+0xc],eax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c2: movzx  r13d,BYTE PTR [rdi-0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12c7: movzx  eax,BYTE PTR [rdi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12cb: mov    QWORD PTR [rsp+0x30],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12d0: movzx  r9d,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d5: movzx  eax,BYTE PTR [rdi-0x9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d9: mov    QWORD PTR [rsp+0x38],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12de: movzx  r10d,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e3: movzx  eax,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e7: mov    QWORD PTR [rsp+0x18],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12ec: movzx  r14d,BYTE PTR [rdi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f0: movzx  edx,WORD PTR [rdi-0x11] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, -17), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12f4: mov    r12d,DWORD PTR [rdi-0x1b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R12, BPF_REG_1, -27), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f8: cmp    r11b,0x42 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12fc: je     1330 <tetragon_process_event_arg_filter_xdp+0x230> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 66),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (27) - 1),
    /* 0x12fe: mov    eax,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_0, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1300: and    eax,0x24 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 36), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1303: jne    1330 <tetragon_process_event_arg_filter_xdp+0x230> [exact-bpf: jne ordinary BPF branch from preceding and] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_0, 0, (22) - 1, -1),
    /* 0x1305: movzx  eax,BYTE PTR [rdi-0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1309: shl    eax,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130c: movzx  ecx,WORD PTR [rdi-0x15] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -21), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1310: shl    ecx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1313: or     rax,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1316: or     rax,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1319: shl    r12,0x10 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x131d: xor    r12,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1320: mov    r11,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1324: add    r11,r12 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1327: jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-195) - 1),
    /* 0x132c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1330: mov    rax,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1333: shl    rax,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1337: or     rax,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x133a: mov    r11,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x133d: shl    r11,0x18 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 24), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1341: or     r11,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1344: mov    r15d,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1347: or     r15,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x134a: movzx  ecx,dx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x134d: test   cl,0x2 [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x1350: je     1391 <tetragon_process_event_arg_filter_xdp+0x291> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (43) - 1),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1352: test   esi,esi [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x1354: mov    r11,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1358: je     1395 <tetragon_process_event_arg_filter_xdp+0x295> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_2, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (38) - 1),
    /* 0x135a: mov    rax,QWORD PTR [rsp+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x135f: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1363: shl    r14,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1367: or     r14,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x136a: or     r14,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x136d: mov    rdx,QWORD PTR [rsp+0x20] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, HC_X86_RSP, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1372: and    dl,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1375: mov    esi,ecx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1377: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x137a: mov    rax,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x137d: shl    rax,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1380: not    dl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1382: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1384: shr    r14,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1387: mov    ecx,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1389: or     r14,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x138c: xor    r15,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x138f: jmp    1395 <tetragon_process_event_arg_filter_xdp+0x295> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (3) - 1),
    /* 0x1391: mov    r11,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1395: shl    ebp,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1398: add    rbp,QWORD PTR [rsp+0x28] [exact-kinsn: add64 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RSP, 40), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x139d: mov    eax,DWORD PTR [rsp+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13a1: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x13a4: shl    r13d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x13a8: or     r13d,eax [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x13ab: mov    rax,QWORD PTR [rsp+0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13b0: shl    rax,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13b4: shl    r9,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13b8: or     r9,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13bb: mov    rax,QWORD PTR [rsp+0x38] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13c0: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c4: shl    r10,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c8: or     r10,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13cb: or     r13,rbp [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_7, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13ce: or     r13,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13d1: or     r13,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13d4: xor    r12,r13 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13d7: test   cl,0x4 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x13da: mov    edx,0x0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13df: cmovne rdx,r12 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_3, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x13e3: add    rdx,r15 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e6: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e9: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x13eb: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13ee: mov    rsi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13f1: shl    rsi,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13f4: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13f6: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13f8: shr    rdx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13fb: or     rdx,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13fe: xor    r11,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1401: jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-328) - 1),
    /* 0x1406: mov    rax,QWORD PTR [rsp+0x10] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x140b: mov    QWORD PTR [rax],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x140e: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1413: add    rsp,0x40 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 64), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1417: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1418: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141a: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141c: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141e: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1420: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1421: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
