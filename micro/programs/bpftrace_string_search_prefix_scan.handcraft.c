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
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_4, BPF_REG_3, (266) - 1, 0),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1119: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, (261) - 1, 0),
    /* 0x111f: lea    rsi,[rcx+0x78] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 120), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1126: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, (256) - 1, 0),
    /* 0x112c: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112d: mov    edi,DWORD PTR [rcx+0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1130: movzx  edx,BYTE PTR [rcx+0x70] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 112), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1134: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1136: mov    r8d,0x0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x113c: test   dl,dl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x113e: je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 255),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (86) - 1),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1140: cmp    BYTE PTR [rcx+0x71],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 113, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1144: je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 113),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 0),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (58) - 1),
    /* 0x1146: cmp    BYTE PTR [rcx+0x72],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 114, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x114a: je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 114),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 0),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (51) - 1),
    /* 0x114c: cmp    BYTE PTR [rcx+0x73],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 115, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1150: je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 115),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 0),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (44) - 1),
    /* 0x1152: cmp    BYTE PTR [rcx+0x74],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 116, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1156: je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 116),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 0),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (37) - 1),
    /* 0x1158: cmp    BYTE PTR [rcx+0x75],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 117, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x115c: je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 117),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 0),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (30) - 1),
    /* 0x115e: cmp    BYTE PTR [rcx+0x76],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 118, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1162: je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 118),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 0),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (23) - 1),
    /* 0x1164: cmp    BYTE PTR [rcx+0x77],0x1 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 119, 1), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1168: mov    r8d,0x8 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x116e: sbb    r8d,0x0 [exact-kinsn: sbbl imm0 kinsn using module shadow CF] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 0), MICRO_HANDCRAFT_BPF_X86_SBBL),
    /* 0x1172: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (18) - 1),
    /* 0x1174: mov    r8d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (15) - 1),
    /* 0x117c: mov    r8d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1182: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (12) - 1),
    /* 0x1184: mov    r8d,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x118a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (9) - 1),
    /* 0x118c: mov    r8d,0x4 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1192: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (6) - 1),
    /* 0x1194: mov    r8d,0x5 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (3) - 1),
    /* 0x119c: mov    r8d,0x6 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a2: cmp    edi,0x60 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 96), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11a5: ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_1, 0, (148) - 1, 96),
    /* 0x11ab: mov    esi,DWORD PTR [rcx+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ae: cmp    esi,r8d [exact-kinsn: cmpl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11b1: jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_2, BPF_REG_5, (143) - 1, 0),
    /* 0x11b7: test   dl,dl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11b9: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 255),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (135) - 1),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11bf: movabs rax,0x4f82338baed89116 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x4f82338baed89116ULL),
    /* 0x11c9: mov    r9d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11cc: lea    r10d,[rsi+0x3] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R10, BPF_REG_2, 0, 0, 1, 0, 3), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11d0: movabs rdi,0xd1b54a32d192ed03 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0xd1b54a32d192ed03ULL),
    /* 0x11da: add    rdi,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11dd: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e0: jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (17) - 1),
    /* 0x11e2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: test   r11b,r11b [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -424),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 255),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (96) - 1),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11f9: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11fc: add    rdi,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ff: cmp    r8,0x59 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 89), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1203: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, (101) - 1, 89),
    /* 0x1209: lea    r11,[rsi+r8*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R11, BPF_REG_2, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x120d: cmp    r11,r9 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1210: ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_7, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -424),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -440),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, 3, 0),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 3),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, -368),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-21) - 1),
    /* 0x1212: test   rsi,rsi [exact-kinsn: testq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_TESTQ),
    /* 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_2, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (69) - 1),
    /* 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R11, BPF_REG_4, BPF_REG_5, 0, 16), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1221: xor    r11b,dl [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1224: cmp    esi,0x2 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1227: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: jb ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, (-41) - 1, 2),
    /* 0x1229: movzx  ebx,BYTE PTR [rcx+0x71] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 113), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x122d: xor    bl,BYTE PTR [rcx+r8*1+0x11] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 17), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1232: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1235: cmp    esi,0x3 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 3), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1238: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: jb ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, (-50) - 1, 3),
    /* 0x123a: movzx  ebx,BYTE PTR [rcx+0x72] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 114), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x123e: xor    bl,BYTE PTR [rcx+r8*1+0x12] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 18), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1243: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1246: cmp    esi,0x4 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 4), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1249: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: jb ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, (-59) - 1, 4),
    /* 0x124b: movzx  ebx,BYTE PTR [rcx+0x73] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 115), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x124f: xor    bl,BYTE PTR [rcx+r8*1+0x13] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 19), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1254: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1257: cmp    esi,0x5 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 5), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x125a: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: jb ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, (-68) - 1, 5),
    /* 0x125c: movzx  ebx,BYTE PTR [rcx+0x74] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 116), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1260: xor    bl,BYTE PTR [rcx+r8*1+0x14] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 20), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1265: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1268: cmp    esi,0x6 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 6), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x126b: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: jb ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, (-77) - 1, 6),
    /* 0x126d: movzx  ebx,BYTE PTR [rcx+0x75] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 117), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1271: xor    bl,BYTE PTR [rcx+r8*1+0x15] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 21), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1276: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1279: cmp    esi,0x7 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 7), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x127c: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: jb ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, (-86) - 1, 7),
    /* 0x1282: movzx  ebx,BYTE PTR [rcx+0x76] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 118), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1286: xor    bl,BYTE PTR [rcx+r8*1+0x16] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 22), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x128b: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x128e: cmp    esi,0x8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1291: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: jb ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, (-95) - 1, 8),
    /* 0x1297: movzx  ebx,BYTE PTR [rcx+0x77] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 119), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x129b: xor    bl,BYTE PTR [rcx+r8*1+0x17] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 23), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x12a0: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x12a3: jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-102) - 1),
    /* 0x12a8: cmp    r8,0x60 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 96), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x12ac: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, (11) - 1, 96),
    /* 0x12ae: shl    rsi,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x12b2: add    rsi,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12b5: rol    rsi,0x3 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 3), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12b9: xor    rdi,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12bc: mov    rax,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12bf: mov    QWORD PTR [rcx],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12c2: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c7: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x12c8: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
