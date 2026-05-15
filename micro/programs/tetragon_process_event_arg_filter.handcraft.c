#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 71
 *
 * - 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113a: mov    QWORD PTR [rsp-0x30],rsi [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1164: mov    eax,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r12d]
 * - 0x1194: lea    rsi,[rip+0xe65] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xe65]]
 * - 0x11a2: jmp    rdx [warning-unmapped: cannot parse branch target rdx]
 * - 0x11f4: movzx  r9d,BYTE PTR [rdi-0x5] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f9: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11fd: or     r9,rsi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1207: or     rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x120a: movzx  r11d,BYTE PTR [rdi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x120f: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1213: movzx  r10d,BYTE PTR [rdi-0x2] [warning-unmapped: destination register r10d is not in the BPF JIT register file]
 * - 0x1218: shl    r10,0x28 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x121c: or     r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x121f: or     r10,rsi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1255: movabs r11,0x6e6f68747970 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x6e6f68747970]
 * - 0x1262: je     1280 <tetragon_process_event_arg_filter_xdp+0x180> [warning-unmapped: cannot lower cmp    r10,r11 + je     1280 <tetragon_process_event_arg_filter_xdp+0x180> to BPF branch]
 * - 0x126d: sete   sil [warning-unmapped: sete is flag-bound; automatic conversion needs an adjacent cmp/test proof]
 * - 0x1280: mov    r12d,DWORD PTR [rdi-0x1f] [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,DWORD PTR [rdi-0x1f]]
 * - 0x1286: jne    1160 <tetragon_process_event_arg_filter_xdp+0x60> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x128c: mov    QWORD PTR [rsp-0x38],rbx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1299: mov    QWORD PTR [rsp-0x20],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x129e: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12a7: mov    DWORD PTR [rsp-0x3c],ecx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x12ab: movzx  ebp,BYTE PTR [rdi-0xc] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x12b3: mov    QWORD PTR [rsp-0x18],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x12c0: mov    QWORD PTR [rsp-0x10],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x12c9: mov    QWORD PTR [rsp-0x8],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x12d2: mov    QWORD PTR [rsp-0x28],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x12db: movzx  r11d,WORD PTR [rdi-0x11] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12e9: mov    ecx,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x130c: mov    rbx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x132a: mov    rdx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r11]
 * - 0x1334: mov    r12d,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,r12d]
 * - 0x1337: or     r12,rdx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x133a: movzx  r11d,r11w [warning-unmapped: movzx source size not recognized: r11w]
 * - 0x133e: test   r11b,0x2 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x1342: je     1373 <tetragon_process_event_arg_filter_xdp+0x273> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1346: je     1373 <tetragon_process_event_arg_filter_xdp+0x273> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1348: mov    rcx,QWORD PTR [rsp-0x28] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1358: or     r15,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x1370: xor    r12,r15 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x1373: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1377: add    r9,QWORD PTR [rsp-0x20] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file]
 * - 0x137c: mov    eax,DWORD PTR [rsp-0x3c] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1383: shl    ebp,0x18 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1386: or     ebp,eax [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1388: mov    rax,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1398: mov    rcx,QWORD PTR [rsp-0x10] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13a1: mov    rax,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13ad: or     rbp,r9 [warning-unmapped: ALU destination rbp is not in the BPF JIT register file]
 * - 0x13b0: or     rbp,rbx [warning-unmapped: ALU destination rbp is not in the BPF JIT register file]
 * - 0x13b3: or     rbp,rax [warning-unmapped: ALU destination rbp is not in the BPF JIT register file]
 * - 0x13b6: xor    r13,rbp [warning-unmapped: ALU source rbp is not supported]
 * - 0x13b9: test   r11b,0x4 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x13c6: add    rdx,r12 [warning-unmapped: ALU source r12 is not supported]
 * - 0x13e1: mov    rbx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13ee: mov    rax,QWORD PTR [rsp-0x30] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13fb: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13fc: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13fe: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1400: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1402: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1404: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <tetragon_process_event_arg_filter_xdp+0xf> [bpf-branch: lowered cmp    rsi,rcx + jbe    110f <tetragon_process_event_arg_filter_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_2, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <tetragon_process_event_arg_filter_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <tetragon_process_event_arg_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -4),
    /* 0x1118: lea    rdx,[rsi+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <tetragon_process_event_arg_filter_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <tetragon_process_event_arg_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [rsi+0x8],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1128: jne    110e <tetragon_process_event_arg_filter_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi+0x8],0x20 + jne    110e <tetragon_process_event_arg_filter_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -9, 32),
    /* 0x112a: cmp    DWORD PTR [rsi+0xc],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x112e: jne    110e <tetragon_process_event_arg_filter_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi+0xc],0x20 + jne    110e <tetragon_process_event_arg_filter_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -11, 32),
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113a: mov    QWORD PTR [rsp-0x30],rsi [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x113f: lea    rdi,[rsi+0x2f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1143: movabs rbx,0xe7037ed1a0b428db [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xe7037ed1a0b428dbULL),
    /* 0x114d: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x1150: jmp    117e <tetragon_process_event_arg_filter_xdp+0x7e> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 6, 0),
    /* 0x1152: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: shl    rcx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 32),
    /* 0x1164: mov    eax,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r12d] */
    /* 0x1167: or     rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x116a: xor    rbx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x116d: inc    r8 [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x1170: add    rdi,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 32),
    /* 0x1174: cmp    r8,0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1178: je     13ee <tetragon_process_event_arg_filter_xdp+0x2ee> [bpf-branch: lowered cmp    r8,0x20 + je     13ee <tetragon_process_event_arg_filter_xdp+0x2ee> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 141, 32),
    /* 0x117e: movzx  eax,BYTE PTR [rdi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1182: movzx  ecx,BYTE PTR [rdi-0x12] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -18), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1186: shl    ecx,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 8),
    /* 0x1189: or     rcx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x118c: lea    edx,[rcx-0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_4, 0, 0, 1, 0, -1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x118f: cmp    edx,0xc [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1192: ja     11b2 <tetragon_process_event_arg_filter_xdp+0xb2> [bpf-branch: lowered cmp    edx,0xc + ja     11b2 <tetragon_process_event_arg_filter_xdp+0xb2> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_3, 0, 7, 12),
    /* 0x1194: lea    rsi,[rip+0xe65] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xe65]] */
    /* 0x119b: movsxd rdx,DWORD PTR [rsi+rdx*4] [exact-kinsn: movsxd SIB kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_SIB_TMP_PAYLOAD(BPF_REG_3, BPF_REG_2, BPF_REG_3, 2, 0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVSXD_SIB),
    /* 0x119f: add    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x11a2: jmp    rdx [warning-unmapped: cannot parse branch target rdx] */
    /* 0x11a4: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x11a6: movabs r14,0x11000000000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x11000000000000ULL),
    /* 0x11b0: jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 18, 0),
    /* 0x11b2: mov    dl,0x1 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_3, 1),
    /* 0x11b4: xor    r14d,r14d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_8, 0, 0, 0),
    /* 0x11b7: jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 15, 0),
    /* 0x11b9: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x11bb: movabs r14,0x37000000000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x37000000000000ULL),
    /* 0x11c5: jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 11, 0),
    /* 0x11c7: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x11c9: movabs r14,0x23000000000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x23000000000000ULL),
    /* 0x11d3: jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 7, 0),
    /* 0x11d5: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x11d7: movabs r14,0x41000000000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x41000000000000ULL),
    /* 0x11e1: jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 3, 0),
    /* 0x11e3: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x11e5: movabs r14,0x59000000000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x59000000000000ULL),
    /* 0x11ef: nop [padding: padding is not part of BPF semantics] */
    /* 0x11f0: movzx  esi,WORD PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11f4: movzx  r9d,BYTE PTR [rdi-0x5] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11f9: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x11fd: or     r9,rsi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_2, 0, 0),
    /* 0x1200: movzx  esi,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1204: shl    esi,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 24),
    /* 0x1207: or     rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x120a: movzx  r11d,BYTE PTR [rdi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x120f: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1213: movzx  r10d,BYTE PTR [rdi-0x2] [warning-unmapped: destination register r10d is not in the BPF JIT register file] */
    /* 0x1218: shl    r10,0x28 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x121c: or     r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x121f: or     r10,rsi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1222: cmp    rsi,0x68736162 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1229: je     1240 <tetragon_process_event_arg_filter_xdp+0x140> [bpf-branch: lowered cmp    rsi,0x68736162 + je     1240 <tetragon_process_event_arg_filter_xdp+0x140> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_2, 0, 3, 1752392034),
    /* 0x122b: cmp    esi,0x6c727563 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1231: jne    1250 <tetragon_process_event_arg_filter_xdp+0x150> [bpf-branch: lowered cmp    esi,0x6c727563 + jne    1250 <tetragon_process_event_arg_filter_xdp+0x150> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_2, 0, 4, 1819440483),
    /* 0x1233: mov    esi,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x1238: jmp    1280 <tetragon_process_event_arg_filter_xdp+0x180> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x123a: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1240: mov    esi,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x1245: jmp    1280 <tetragon_process_event_arg_filter_xdp+0x180> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 3, 0),
    /* 0x1247: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: mov    esi,0x3 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 3),
    /* 0x1255: movabs r11,0x6e6f68747970 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x6e6f68747970] */
    /* 0x125f: cmp    r10,r11 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1262: je     1280 <tetragon_process_event_arg_filter_xdp+0x180> [warning-unmapped: cannot lower cmp    r10,r11 + je     1280 <tetragon_process_event_arg_filter_xdp+0x180> to BPF branch] */
    /* 0x1264: xor    esi,esi [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 0),
    /* 0x1266: cmp    r9d,0x6873 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x126d: sete   sil [warning-unmapped: sete is flag-bound; automatic conversion needs an adjacent cmp/test proof] */
    /* 0x1271: shl    esi,0x2 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x1274: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1280: mov    r12d,DWORD PTR [rdi-0x1f] [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,DWORD PTR [rdi-0x1f]] */
    /* 0x1284: test   dl,dl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x1286: jne    1160 <tetragon_process_event_arg_filter_xdp+0x60> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x128c: mov    QWORD PTR [rsp-0x38],rbx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1291: movzx  edx,BYTE PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1295: movzx  ecx,BYTE PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1299: mov    QWORD PTR [rsp-0x20],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x129e: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12a3: movzx  ecx,BYTE PTR [rdi-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12a7: mov    DWORD PTR [rsp-0x3c],ecx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x12ab: movzx  ebp,BYTE PTR [rdi-0xc] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x12af: movzx  ecx,BYTE PTR [rdi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12b3: mov    QWORD PTR [rsp-0x18],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x12b8: movzx  ebx,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12bc: movzx  ecx,BYTE PTR [rdi-0x9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12c0: mov    QWORD PTR [rsp-0x10],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x12c5: movzx  ecx,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12c9: mov    QWORD PTR [rsp-0x8],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x12ce: movzx  ecx,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12d2: mov    QWORD PTR [rsp-0x28],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x12d7: movzx  r15d,BYTE PTR [rdi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12db: movzx  r11d,WORD PTR [rdi-0x11] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12e0: mov    r13d,DWORD PTR [rdi-0x1b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -27), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x12e4: cmp    dl,0x42 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x12e7: je     1320 <tetragon_process_event_arg_filter_xdp+0x220> [bpf-branch: lowered cmp    dl,0x42 + je     1320 <tetragon_process_event_arg_filter_xdp+0x220> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_3, 0, 16, 66),
    /* 0x12e9: mov    ecx,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_9, 0, 0),
    /* 0x12ec: and    ecx,0x24 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 36), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x12ef: jne    1320 <tetragon_process_event_arg_filter_xdp+0x220> [bpf-branch: lowered flags from and    ecx,0x24 + jne    1320 <tetragon_process_event_arg_filter_xdp+0x220> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, 12, 0),
    /* 0x12f1: movzx  eax,BYTE PTR [rdi-0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12f5: shl    eax,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 8),
    /* 0x12f8: movzx  ecx,WORD PTR [rdi-0x15] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -21), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x12fc: shl    ecx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 16),
    /* 0x12ff: or     rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x1302: or     rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x1305: shl    r13,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_7, 0, 0, 16),
    /* 0x1309: xor    r13,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_7, BPF_REG_0, 0, 0),
    /* 0x130c: mov    rbx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1311: add    rbx,r13 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_7, 0, 0),
    /* 0x1314: jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -97, 0),
    /* 0x1319: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1320: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1323: shl    rcx,0x28 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 40),
    /* 0x1327: or     rcx,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_8, 0, 0),
    /* 0x132a: mov    rdx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r11] */
    /* 0x132d: shl    rdx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x1331: or     rdx,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x1334: mov    r12d,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,r12d] */
    /* 0x1337: or     r12,rdx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x133a: movzx  r11d,r11w [warning-unmapped: movzx source size not recognized: r11w] */
    /* 0x133e: test   r11b,0x2 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x1342: je     1373 <tetragon_process_event_arg_filter_xdp+0x273> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1344: test   esi,esi [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_TESTL_RR),
    /* 0x1346: je     1373 <tetragon_process_event_arg_filter_xdp+0x273> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1348: mov    rcx,QWORD PTR [rsp-0x28] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x134d: shl    rcx,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 48),
    /* 0x1351: shl    r15,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 56),
    /* 0x1355: or     r15,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x1358: or     r15,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x135b: and    al,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 7),
    /* 0x135d: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1360: mov    rdx,r15 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1363: shl    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x1366: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1368: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x136a: shr    r15,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x136d: or     r15,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x1370: xor    r12,r15 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x1373: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 8),
    /* 0x1377: add    r9,QWORD PTR [rsp-0x20] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file] */
    /* 0x137c: mov    eax,DWORD PTR [rsp-0x3c] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1380: shl    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x1383: shl    ebp,0x18 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1386: or     ebp,eax [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1388: mov    rax,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x138d: shl    rax,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 32),
    /* 0x1391: shl    rbx,0x28 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 40),
    /* 0x1395: or     rbx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x1398: mov    rcx,QWORD PTR [rsp-0x10] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x139d: shl    rcx,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 48),
    /* 0x13a1: mov    rax,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x13a6: shl    rax,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 56),
    /* 0x13aa: or     rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x13ad: or     rbp,r9 [warning-unmapped: ALU destination rbp is not in the BPF JIT register file] */
    /* 0x13b0: or     rbp,rbx [warning-unmapped: ALU destination rbp is not in the BPF JIT register file] */
    /* 0x13b3: or     rbp,rax [warning-unmapped: ALU destination rbp is not in the BPF JIT register file] */
    /* 0x13b6: xor    r13,rbp [warning-unmapped: ALU source rbp is not supported] */
    /* 0x13b9: test   r11b,0x4 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x13bd: mov    edx,0x0 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x13c2: cmovne rdx,r13 [exact-kinsn: cmov kinsn; cond register must match prior test] */
    HC_KINSN(HC_CMOV_PAYLOAD(BPF_REG_3, BPF_REG_7, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ_RR),
    /* 0x13c6: add    rdx,r12 [warning-unmapped: ALU source r12 is not supported] */
    /* 0x13c9: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x13cc: and    al,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 7),
    /* 0x13ce: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13d1: mov    rsi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x13d4: shl    rsi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x13d7: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x13d9: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x13db: shr    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x13de: or     rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x13e1: mov    rbx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x13e6: xor    rbx,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_3, 0, 0),
    /* 0x13e9: jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -144, 0),
    /* 0x13ee: mov    rax,QWORD PTR [rsp-0x30] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x13f3: mov    QWORD PTR [rax],rbx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x13f6: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x13fb: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13fc: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13fe: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1400: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1402: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1404: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1405: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
