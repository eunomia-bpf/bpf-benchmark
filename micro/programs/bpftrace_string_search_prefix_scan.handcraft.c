#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 17
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112d: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1130: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1142: je     11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1148: je     1178 <bpftrace_string_search_prefix_scan_xdp+0x78> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x114e: je     1180 <bpftrace_string_search_prefix_scan_xdp+0x80> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1154: je     1188 <bpftrace_string_search_prefix_scan_xdp+0x88> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x115a: je     1190 <bpftrace_string_search_prefix_scan_xdp+0x90> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1160: je     1198 <bpftrace_string_search_prefix_scan_xdp+0x98> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1166: je     11a0 <bpftrace_string_search_prefix_scan_xdp+0xa0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11bd: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x12c7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x12c8: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: ja     12c9 <bpftrace_string_search_prefix_scan_xdp+0x1c9> [bpf-branch: verifier-visible branch from preceding cmp    rcx,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_4, BPF_REG_3, 180, 0),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1119: ja     12c9 <bpftrace_string_search_prefix_scan_xdp+0x1c9> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, 175, 0),
    /* 0x111f: lea    rsi,[rcx+0x78] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 120), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1126: ja     12c9 <bpftrace_string_search_prefix_scan_xdp+0x1c9> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, 170, 0),
    /* 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112d: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1130: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: mov    edi,DWORD PTR [rcx+0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1134: movzx  edx,BYTE PTR [rcx+0x70] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 112), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1138: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x113a: mov    r8d,0x0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1140: test   dl,dl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1142: je     11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1144: cmp    BYTE PTR [rcx+0x71],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 113, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1148: je     1178 <bpftrace_string_search_prefix_scan_xdp+0x78> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x114a: cmp    BYTE PTR [rcx+0x72],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 114, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x114e: je     1180 <bpftrace_string_search_prefix_scan_xdp+0x80> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1150: cmp    BYTE PTR [rcx+0x73],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 115, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1154: je     1188 <bpftrace_string_search_prefix_scan_xdp+0x88> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1156: cmp    BYTE PTR [rcx+0x74],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 116, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x115a: je     1190 <bpftrace_string_search_prefix_scan_xdp+0x90> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x115c: cmp    BYTE PTR [rcx+0x75],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 117, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1160: je     1198 <bpftrace_string_search_prefix_scan_xdp+0x98> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1162: cmp    BYTE PTR [rcx+0x76],0x0 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 118, 0), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1166: je     11a0 <bpftrace_string_search_prefix_scan_xdp+0xa0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1168: cmp    BYTE PTR [rcx+0x77],0x1 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_4, 119, 1), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x116c: mov    r8d,0x8 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1172: sbb    r8d,0x0 [exact-kinsn: sbbl imm0 kinsn using module shadow CF] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 0), MICRO_HANDCRAFT_BPF_X86_SBBL),
    /* 0x1176: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 17, 0),
    /* 0x1178: mov    r8d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117e: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 14, 0),
    /* 0x1180: mov    r8d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1186: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 11, 0),
    /* 0x1188: mov    r8d,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x118e: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 8, 0),
    /* 0x1190: mov    r8d,0x4 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1196: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x1198: mov    r8d,0x5 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119e: jmp    11a6 <bpftrace_string_search_prefix_scan_xdp+0xa6> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 2, 0),
    /* 0x11a0: mov    r8d,0x6 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a6: cmp    edi,0x60 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 96), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11a9: ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [bpf-branch: verifier-visible branch from preceding cmp    edi,0x60; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_1, 0, 121, 96),
    /* 0x11af: mov    esi,DWORD PTR [rcx+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b2: cmp    esi,r8d [exact-kinsn: cmpl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11b5: jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [bpf-branch: verifier-visible branch from preceding cmp    esi,r8d; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_X, BPF_REG_2, BPF_REG_5, 116, 0),
    /* 0x11bb: test   dl,dl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11bd: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11c3: movabs rax,0x4f82338baed89116 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x4f82338baed89116ULL),
    /* 0x11cd: mov    r9d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d0: lea    r10d,[rsi+0x3] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R10, BPF_REG_2, 0, 0, 1, 0, 3), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11d4: movabs rdi,0xd1b54a32d192ed03 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0xd1b54a32d192ed03ULL),
    /* 0x11de: add    rdi,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11e1: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e4: jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 9, 0),
    /* 0x11e6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x11f0: test   r11b,r11b [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11f9: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11fc: add    rdi,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ff: cmp    r8,0x59 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 89), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1203: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [bpf-branch: verifier-visible branch from preceding cmp    r8,0x59; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 88, 89),
    /* 0x1209: lea    r11,[rsi+r8*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R11, BPF_REG_2, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x120d: cmp    r11,r9 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1210: ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> [bpf-branch: verifier-visible branch from preceding cmp    r11,r9; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, HC_X86_R11, HC_X86_R9, -12, 0),
    /* 0x1212: test   rsi,rsi [exact-kinsn: testq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_TESTQ),
    /* 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R11, BPF_REG_4, BPF_REG_5, 0, 16), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1221: xor    r11b,dl [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1224: cmp    esi,0x2 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1227: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    esi,0x2; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, -23, 2),
    /* 0x1229: movzx  ebx,BYTE PTR [rcx+0x71] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 113), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x122d: xor    bl,BYTE PTR [rcx+r8*1+0x11] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 17), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1232: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1235: cmp    esi,0x3 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 3), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1238: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    esi,0x3; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, -32, 3),
    /* 0x123a: movzx  ebx,BYTE PTR [rcx+0x72] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 114), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x123e: xor    bl,BYTE PTR [rcx+r8*1+0x12] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 18), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1243: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1246: cmp    esi,0x4 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 4), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1249: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    esi,0x4; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, -41, 4),
    /* 0x124b: movzx  ebx,BYTE PTR [rcx+0x73] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 115), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x124f: xor    bl,BYTE PTR [rcx+r8*1+0x13] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 19), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1254: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1257: cmp    esi,0x5 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 5), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x125a: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    esi,0x5; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, -50, 5),
    /* 0x125c: movzx  ebx,BYTE PTR [rcx+0x74] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 116), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1260: xor    bl,BYTE PTR [rcx+r8*1+0x14] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 20), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1265: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1268: cmp    esi,0x6 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 6), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x126b: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    esi,0x6; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, -59, 6),
    /* 0x126d: movzx  ebx,BYTE PTR [rcx+0x75] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 117), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1271: xor    bl,BYTE PTR [rcx+r8*1+0x15] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 21), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1276: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1279: cmp    esi,0x7 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 7), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x127c: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    esi,0x7; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, -68, 7),
    /* 0x1282: movzx  ebx,BYTE PTR [rcx+0x76] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 118), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1286: xor    bl,BYTE PTR [rcx+r8*1+0x16] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 22), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x128b: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x128e: cmp    esi,0x8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1291: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    esi,0x8; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_2, 0, -77, 8),
    /* 0x1297: movzx  ebx,BYTE PTR [rcx+0x77] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 119), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x129b: xor    bl,BYTE PTR [rcx+r8*1+0x17] [exact-kinsn: xorb SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 23), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x12a0: or     r11b,bl [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x12a3: jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -84, 0),
    /* 0x12a8: cmp    r8,0x60 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 96), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x12ac: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [bpf-branch: verifier-visible branch from preceding cmp    r8,0x60; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 10, 96),
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
    /* 0x12c7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12c8: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12c9: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
