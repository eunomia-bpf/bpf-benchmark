#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 25
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113e: je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x116e: sbb    r8d,0x0 [warning-unmapped: sbb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x11b9: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11c9: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11cc: lea    r10d,[rsi+0x3] [warning-unmapped: LEA operands are not representable]
 * - 0x11da: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x11f0: test   r11b,r11b [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11fc: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x1209: lea    r11,[rsi+r8*1] [warning-unmapped: LEA operands are not representable]
 * - 0x1210: ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> [warning-unmapped: cannot lower cmp    r11,r9 + ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> to BPF branch]
 * - 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1221: xor    r11b,dl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x1232: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x1243: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x1254: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x1265: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x1276: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x128b: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x12a0: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file]
 * - 0x12c7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rcx,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [bpf-branch: lowered cmp    rcx,rdx + ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_3, 103),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1119: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [bpf-branch: lowered cmp    rsi,rdx + ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 100),
    /* 0x111f: lea    rsi,[rcx+0x78] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 120), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1126: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [bpf-branch: lowered cmp    rsi,rdx + ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 97),
    /* 0x112c: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112d: mov    edi,DWORD PTR [rcx+0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x1130: movzx  edx,BYTE PTR [rcx+0x70] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 112), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1134: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1136: mov    r8d,0x0 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x113c: test   dl,dl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x113e: je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1140: cmp    BYTE PTR [rcx+0x71],0x0 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1144: je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x71],0x0 + je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_7, BPF_REG_4, 113),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, 12, 0),
    /* 0x1146: cmp    BYTE PTR [rcx+0x72],0x0 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x114a: je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x72],0x0 + je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_7, BPF_REG_4, 114),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, 12, 0),
    /* 0x114c: cmp    BYTE PTR [rcx+0x73],0x0 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1150: je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x73],0x0 + je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_7, BPF_REG_4, 115),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, 12, 0),
    /* 0x1152: cmp    BYTE PTR [rcx+0x74],0x0 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1156: je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x74],0x0 + je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_7, BPF_REG_4, 116),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, 12, 0),
    /* 0x1158: cmp    BYTE PTR [rcx+0x75],0x0 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x115c: je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x75],0x0 + je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_7, BPF_REG_4, 117),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, 12, 0),
    /* 0x115e: cmp    BYTE PTR [rcx+0x76],0x0 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1162: je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x76],0x0 + je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_7, BPF_REG_4, 118),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, 12, 0),
    /* 0x1164: cmp    BYTE PTR [rcx+0x77],0x1 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1168: mov    r8d,0x8 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 8),
    /* 0x116e: sbb    r8d,0x0 [warning-unmapped: sbb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1172: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 11, 0),
    /* 0x1174: mov    r8d,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x117a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 9, 0),
    /* 0x117c: mov    r8d,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 2),
    /* 0x1182: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 7, 0),
    /* 0x1184: mov    r8d,0x3 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 3),
    /* 0x118a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x118c: mov    r8d,0x4 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 4),
    /* 0x1192: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 3, 0),
    /* 0x1194: mov    r8d,0x5 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 5),
    /* 0x119a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0),
    /* 0x119c: mov    r8d,0x6 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 6),
    /* 0x11a2: cmp    edi,0x60 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11a5: ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [bpf-branch: lowered cmp    edi,0x60 + ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_1, 0, 63, 96),
    /* 0x11ab: mov    esi,DWORD PTR [rcx+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 12), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11ae: cmp    esi,r8d [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11b1: jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [bpf-branch: lowered cmp    esi,r8d + jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JNE, BPF_REG_2, BPF_REG_5, 60),
    /* 0x11b7: test   dl,dl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x11b9: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11bf: movabs rax,0x4f82338baed89116 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x4f82338baed89116ULL),
    /* 0x11c9: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x11cc: lea    r10d,[rsi+0x3] [warning-unmapped: LEA operands are not representable] */
    /* 0x11d0: movabs rdi,0xd1b54a32d192ed03 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0xd1b54a32d192ed03ULL),
    /* 0x11da: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x11dd: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x11e0: jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 2, 0),
    /* 0x11e2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: test   r11b,r11b [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11f9: inc    r8 [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x11fc: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x11ff: cmp    r8,0x59 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1203: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [bpf-branch: lowered cmp    r8,0x59 + je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 46, 89),
    /* 0x1209: lea    r11,[rsi+r8*1] [warning-unmapped: LEA operands are not representable] */
    /* 0x120d: cmp    r11,r9 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1210: ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> [warning-unmapped: cannot lower cmp    r11,r9 + ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> to BPF branch] */
    /* 0x1212: test   rsi,rsi [exact-kinsn: testq reg,reg kinsn] */
    HC_KINSN(HC_TEST_PAYLOAD(BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_TESTQ_RR),
    /* 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1221: xor    r11b,dl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x1224: cmp    esi,0x2 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1227: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x2 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -5, 2),
    /* 0x1229: movzx  ebx,BYTE PTR [rcx+0x71] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 113), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x122d: xor    bl,BYTE PTR [rcx+r8*1+0x11] [exact-kinsn: xorb SIB memory-source kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KINSN(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 17, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1232: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x1235: cmp    esi,0x3 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1238: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x3 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -10, 3),
    /* 0x123a: movzx  ebx,BYTE PTR [rcx+0x72] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 114), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x123e: xor    bl,BYTE PTR [rcx+r8*1+0x12] [exact-kinsn: xorb SIB memory-source kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KINSN(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 18, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1243: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x1246: cmp    esi,0x4 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1249: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x4 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -15, 4),
    /* 0x124b: movzx  ebx,BYTE PTR [rcx+0x73] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 115), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x124f: xor    bl,BYTE PTR [rcx+r8*1+0x13] [exact-kinsn: xorb SIB memory-source kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KINSN(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 19, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1254: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x1257: cmp    esi,0x5 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x125a: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x5 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -20, 5),
    /* 0x125c: movzx  ebx,BYTE PTR [rcx+0x74] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 116), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1260: xor    bl,BYTE PTR [rcx+r8*1+0x14] [exact-kinsn: xorb SIB memory-source kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KINSN(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 20, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1265: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x1268: cmp    esi,0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x126b: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x6 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -25, 6),
    /* 0x126d: movzx  ebx,BYTE PTR [rcx+0x75] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 117), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1271: xor    bl,BYTE PTR [rcx+r8*1+0x15] [exact-kinsn: xorb SIB memory-source kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KINSN(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 21, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1276: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x1279: cmp    esi,0x7 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x127c: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x7 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -30, 7),
    /* 0x1282: movzx  ebx,BYTE PTR [rcx+0x76] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 118), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1286: xor    bl,BYTE PTR [rcx+r8*1+0x16] [exact-kinsn: xorb SIB memory-source kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KINSN(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 22, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x128b: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x128e: cmp    esi,0x8 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1291: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x8 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -35, 8),
    /* 0x1297: movzx  ebx,BYTE PTR [rcx+0x77] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 119), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x129b: xor    bl,BYTE PTR [rcx+r8*1+0x17] [exact-kinsn: xorb SIB memory-source kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KINSN(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 23, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x12a0: or     r11b,bl [warning-unmapped: ALU destination r11b is not in the BPF JIT register file] */
    /* 0x12a3: jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -40, 0),
    /* 0x12a8: cmp    r8,0x60 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x12ac: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [bpf-branch: lowered cmp    r8,0x60 + je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 7, 96),
    /* 0x12ae: shl    rsi,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 32),
    /* 0x12b2: add    rsi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_5, 0, 0),
    /* 0x12b5: rol    rsi,0x3 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 3, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12b9: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x12bc: mov    rax,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x12bf: mov    QWORD PTR [rcx],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x12c2: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x12c7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12c8: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
