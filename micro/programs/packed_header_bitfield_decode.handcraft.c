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
    /* 0x110c: jbe    110f <packed_header_bitfield_decode_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_2, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <packed_header_bitfield_decode_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-3) - 1, 0),
    /* 0x1118: lea    rdx,[rsi+0x210] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 528), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <packed_header_bitfield_decode_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi+0x8],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1128: jne    110e <packed_header_bitfield_decode_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x112a: cmp    DWORD PTR [rsi+0xc],0x2 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x112e: jne    110e <packed_header_bitfield_decode_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 2),
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
    /* 0x113a: sub    rsp,0x18 [exact-kinsn: sub64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x113e: mov    QWORD PTR [rsp+0x8],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1143: lea    rdi,[rsi+0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1147: movabs rbx,0x6a09e667f3bcc909 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6a09e667f3bcc909ULL),
    /* 0x1151: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1153: mov    QWORD PTR [rsp],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1157: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: mov    QWORD PTR [rsp+0x10],rbx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1165: movzx  ebx,BYTE PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1169: movzx  r9d,BYTE PTR [rdi-0xe] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x116e: mov    r13d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1171: shl    r13d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1175: movzx  eax,BYTE PTR [rdi-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1179: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x117c: movzx  r12d,BYTE PTR [rdi-0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R12, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1181: shl    r12d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1185: or     r12d,eax [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1188: movzx  r10d,BYTE PTR [rdi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118d: shl    r10,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1191: movzx  ebp,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1195: shl    rbp,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1199: movzx  r11d,BYTE PTR [rdi-0x9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x119e: shl    r11,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11a2: movzx  eax,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a6: shl    eax,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11a9: movzx  r15d,BYTE PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ae: shl    r15,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11b2: movzx  esi,BYTE PTR [rdi-0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11b6: shl    rsi,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11ba: lea    rcx,[r15+rsi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_9, BPF_REG_2, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11be: or     r15,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11c1: movzx  eax,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c5: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11c9: movzx  edx,BYTE PTR [rdi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11cc: shl    rdx,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11d0: or     rdx,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11d3: movzx  r14d,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d8: shl    r14,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11dc: or     r13d,ebx [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11df: or     r10,rbp [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e2: or     r14,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e5: or     r11,rbp [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e8: lea    ebp,[r12+r13*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RBP, HC_X86_R12, BPF_REG_7, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ec: or     rdx,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11ef: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f1: and    eax,0x3f [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 63), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11f4: shr    r13d,0x6 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 6), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x11f8: and    r13d,0x1f [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 31), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11fc: shr    r14,0x36 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 54), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1200: add    rax,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1203: add    rax,r13 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1206: movzx  r13d,BYTE PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x120b: or     r10,rbp [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x120e: shr    ebp,0xb [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 11), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1211: and    ebp,0x7ff [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 2047), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1217: shr    r12d,0x16 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 22), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x121b: movzx  esi,r12b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x121f: add    rax,rbp [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_0, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1222: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1225: movzx  esi,BYTE PTR [rdi-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1229: shl    esi,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x122c: shr    r10,0x1e [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 30), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1230: and    r10d,0x3fff [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 16383), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1237: shr    r11,0x2c [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 44), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x123b: and    r11d,0x3ff [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 1023), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1242: add    r11,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1245: add    r11,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1248: movzx  eax,BYTE PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x124c: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x124f: or     eax,esi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1251: or     esi,r13d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1254: mov    r12d,r13d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1257: and    r12d,0xf [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x125b: shr    r15,0x18 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 24), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x125f: shr    rdx,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1263: shr    r9d,1 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1266: and    r9d,0x1f [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 31), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x126a: shr    rcx,0x26 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x126e: and    ecx,0x7f [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 127), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1271: add    r12,r15 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1274: add    r12,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1277: shr    eax,0xc [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 12), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x127a: add    rax,rcx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x127d: add    rax,r12 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1280: shr    esi,0x4 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 4), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1283: movzx  r13d,sil [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_7, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1287: lea    rsi,[r9+r13*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, HC_X86_R9, BPF_REG_7, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x128b: mov    r8,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x128f: add    rsi,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1292: add    rsi,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1295: lea    rax,[rbp*2+0x0] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, 0, HC_X86_RBP, 1, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x129d: add    rax,rbp [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_0, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12a0: lea    r12,[r13*8+0x0] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R12, 0, BPF_REG_7, 3, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12a8: sub    r12,r13 [exact-kinsn: sub64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x12ab: lea    r13,[r10+r10*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, HC_X86_R10, HC_X86_R10, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12af: xor    r12,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12b2: xor    r12,r13 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12b5: lea    rax,[r14+r14*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_8, BPF_REG_8, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12b9: lea    rax,[r14+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_8, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12bd: lea    r13,[r15+r15*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_9, BPF_REG_9, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12c1: lea    r15,[r15+r13*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_9, BPF_REG_7, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12c5: lea    r13,[rdx+rdx*8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_3, BPF_REG_3, 3, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12c9: xor    r13,r15 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12cc: mov    r15d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12cf: shl    r15d,0x4 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d3: add    r15,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12d6: xor    r15,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12d9: xor    r15,r13 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12dc: lea    rax,[rcx+rcx*8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_4, BPF_REG_4, 3, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12e0: lea    rax,[rcx+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_4, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12e4: xor    rax,r15 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12e7: and    bl,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x12ea: lea    ecx,[rbx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_6, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12ed: mov    r15,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12f0: shl    r15,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x12f3: not    bl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x12f5: mov    ecx,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f7: shr    rsi,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x12fa: add    rax,r12 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12fd: or     rsi,r15 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1300: xor    rsi,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1303: add    rsi,QWORD PTR [rsp+0x10] [exact-kinsn: add64 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1308: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x130b: lea    rbx,[rdx+r9*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_6, BPF_REG_3, HC_X86_R9, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x130f: add    rbx,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1312: add    rbx,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1315: xor    edx,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1318: and    dl,0xf [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 15), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x131b: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x131e: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1321: shl    rax,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1324: not    dl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1326: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1328: shr    rbx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x132b: or     rbx,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x132e: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1331: add    rdi,0x10 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1335: mov    rcx,r8 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1338: mov    QWORD PTR [rsp],r8 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_5, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x133c: cmp    r8,0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1340: jne    1160 <packed_header_bitfield_decode_xdp+0x60> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, (-264) - 1, 32),
    /* 0x1346: mov    rdx,QWORD PTR [rsp+0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x134b: mov    BYTE PTR [rdx],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x134d: mov    BYTE PTR [rdx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_6, BPF_REG_3, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1350: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1352: shr    ecx,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1355: mov    BYTE PTR [rdx+0x2],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_4, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1358: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x135a: shr    ecx,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x135d: mov    BYTE PTR [rdx+0x3],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_4, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1360: mov    rcx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1363: shr    rcx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1367: mov    BYTE PTR [rdx+0x4],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_4, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x136a: mov    rcx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x136d: shr    rcx,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1371: mov    BYTE PTR [rdx+0x5],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_4, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1374: mov    rcx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1377: shr    rcx,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x137b: mov    BYTE PTR [rdx+0x6],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_4, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x137e: shr    rax,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1382: mov    BYTE PTR [rdx+0x7],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1385: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x138a: add    rsp,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x138e: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x138f: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1391: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1393: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1395: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1397: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1398: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
