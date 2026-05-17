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
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <payload_prefix_memcmp_scan_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_4, BPF_REG_3, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <payload_prefix_memcmp_scan_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, (-3) - 1, 0),
    /* 0x1118: lea    rdi,[rcx+0xcc] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 204), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rdx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <payload_prefix_memcmp_scan_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_3, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x3 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1127: jne    110e <payload_prefix_memcmp_scan_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 3),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x1129: mov    dl,0x1d [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x112b: mov    dil,0x4 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x112e: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1130: movzx  esi,BYTE PTR [rcx+rax*1+0xc] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_0, 0, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1135: lea    r9d,[rdx-0x1d] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_3, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1139: lea    r8d,[rdi-0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_1, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x113d: xor    r8b,r9b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1140: xor    r8b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1144: add    r8b,0x11 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1148: cmp    sil,r8b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x114b: jne    1186 <payload_prefix_memcmp_scan_xdp+0x86> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_2),
    HC_MOV64_REG(BPF_REG_7, BPF_REG_5),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (36) - 1),
    /* 0x114d: movzx  esi,BYTE PTR [rcx+rax*1+0xd] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_0, 0, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1152: mov    r8d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1155: xor    r8b,dil [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1158: xor    r8b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x115c: add    r8b,0x11 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1160: add    rax,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1164: cmp    sil,r8b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1167: jne    1189 <payload_prefix_memcmp_scan_xdp+0x89> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_2),
    HC_MOV64_REG(BPF_REG_7, BPF_REG_5),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (13) - 1),
    /* 0x1169: add    dl,0x3a [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x116c: add    dil,0x8 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1170: cmp    rax,0x40 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1174: jne    1130 <payload_prefix_memcmp_scan_xdp+0x30> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, (-54) - 1, 64),
    /* 0x1176: movzx  eax,BYTE PTR [rcx+0x4b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 75), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x117a: movabs rdx,0xf43e9fde8cf6b51c [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0xf43e9fde8cf6b51cULL),
    /* 0x1184: jmp    11a7 <payload_prefix_memcmp_scan_xdp+0xa7> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (17) - 1),
    /* 0x1186: inc    rax [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1189: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x118b: lea    rax,[rax+rax*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_0, BPF_REG_0, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x118f: movabs rdx,0x6a09e667f3bcc909 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0x6a09e667f3bcc909ULL),
    /* 0x1199: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119c: movzx  eax,sil [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a0: xor    rax,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11a3: movzx  edx,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a7: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11aa: rol    rdx,0x5 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11ae: mov    sil,0x1d [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11b1: mov    dil,0x4 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11b4: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11b6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x11c0: movzx  r8d,BYTE PTR [rcx+rax*1+0x4c] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_5, BPF_REG_4, BPF_REG_0, 0, 76), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c6: lea    r10d,[rsi-0x1d] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R10, BPF_REG_2, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ca: lea    r9d,[rdi-0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_1, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ce: xor    r9b,r10b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11d1: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11d5: add    r9b,0x11 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x11d9: cmp    r8b,r9b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11dc: jne    1222 <payload_prefix_memcmp_scan_xdp+0x122> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_5),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -440),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (40) - 1),
    /* 0x11de: movzx  r8d,BYTE PTR [rcx+rax*1+0x4d] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_5, BPF_REG_4, BPF_REG_0, 0, 77), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e4: mov    r9d,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e7: xor    r9b,dil [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11ea: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11ee: add    r9b,0x11 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x11f2: add    rax,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11f6: cmp    r8b,r9b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11f9: jne    1225 <payload_prefix_memcmp_scan_xdp+0x125> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_5),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -440),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (17) - 1),
    /* 0x11fb: add    sil,0x3a [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x11ff: add    dil,0x8 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1203: cmp    rax,0x40 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1207: jne    11c0 <payload_prefix_memcmp_scan_xdp+0xc0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, (-54) - 1, 64),
    /* 0x1209: movabs rax,0x9e3779b97f4a7c16 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x9e3779b97f4a7c16ULL),
    /* 0x1213: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1216: movzx  eax,BYTE PTR [rcx+0x8b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 139), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x121d: shl    eax,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1220: jmp    123d <payload_prefix_memcmp_scan_xdp+0x13d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (17) - 1),
    /* 0x1222: inc    rax [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1225: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1227: lea    rax,[rax+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_0, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x122b: lea    rax,[rdx+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x122f: movzx  edx,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1233: shl    edx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1236: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1239: movzx  eax,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x123d: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1240: rol    rax,0x6 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 6), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1244: mov    dil,0x1d [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1247: mov    r8b,0x4 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x124a: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x124c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: movzx  esi,BYTE PTR [rcx+rdx*1+0x8c] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_3, 0, 140), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1258: lea    r10d,[rdi-0x1d] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R10, BPF_REG_1, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x125c: lea    r9d,[r8-0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_5, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1260: xor    r9b,r10b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1263: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1267: add    r9b,0x11 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x126b: cmp    sil,r9b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x126e: jne    12bd <payload_prefix_memcmp_scan_xdp+0x1bd> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_2),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -440),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (44) - 1),
    /* 0x1270: movzx  esi,BYTE PTR [rcx+rdx*1+0x8d] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_3, 0, 141), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1278: mov    r9d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127b: xor    r9b,r8b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x127e: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1282: add    r9b,0x11 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1286: add    rdx,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x128a: cmp    sil,r9b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x128d: jne    12c0 <payload_prefix_memcmp_scan_xdp+0x1c0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_2),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -440),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (21) - 1),
    /* 0x128f: add    dil,0x3a [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1293: add    r8b,0x8 [exact-kinsn: add8 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1297: cmp    rdx,0x40 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x129b: jne    1250 <payload_prefix_memcmp_scan_xdp+0x150> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_3, 0, (-54) - 1, 64),
    /* 0x129d: movabs rdx,0x9e3779b97f4a7c16 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0x9e3779b97f4a7c16ULL),
    /* 0x12a7: or     rdx,0x1 [exact-kinsn: or64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 1), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x12ab: xor    rax,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ae: movzx  edx,BYTE PTR [rcx+0xcb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 203), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12b5: shl    edx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12b8: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12bb: jmp    12e1 <payload_prefix_memcmp_scan_xdp+0x1e1> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (21) - 1),
    /* 0x12bd: inc    rdx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x12c0: mov    edx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c2: lea    rdi,[rdx*8+0x0] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, 0, BPF_REG_3, 3, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12ca: sub    rdi,rdx [exact-kinsn: sub64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x12cd: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12d0: movzx  esi,sil [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d4: shl    esi,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d7: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12da: movzx  edx,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12de: add    rdx,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12e1: rol    rdx,0x7 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12e5: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12e8: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ed: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
