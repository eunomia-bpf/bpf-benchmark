#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 27
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1130: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: movabs r9,0xd6e8feb86659fd93 [warning-reg-remap: 64-bit immediate load; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1159: add    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x115c: movzx  r9d,WORD PTR [rsi-0x1] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x116e: xor    rbx,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1177: shl    r9,cl [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x117a: add    r9,rbx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1180: xor    eax,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1186: mov    r10,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r9]
 * - 0x1189: shl    r10,cl [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1190: shr    r9,cl [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1193: or     r9,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x11a4: movzx  r10d,BYTE PTR [rsi-0x17] [warning-unmapped: destination register r10d is not in the BPF JIT register file]
 * - 0x11a9: and    r10d,0x3 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x11ad: lea    rax,[r10+0x18] [warning-unmapped: LEA base/index not in BPF register file: [r10+0x18]]
 * - 0x11c4: movzx  r11d,WORD PTR [rsi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x11c9: add    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11cc: add    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11cf: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11d7: je     1150 <packet_record_bounds_window_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11e4: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11ec: mov    QWORD PTR [rdx],r9 [warning-reg-remap: direct memory store via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f4: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x11f5: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <packet_record_bounds_window_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <packet_record_bounds_window_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <packet_record_bounds_window_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_record_bounds_window_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -4),
    /* 0x1118: lea    rsi,[rdx+0x310] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 784), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <packet_record_bounds_window_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_record_bounds_window_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1128: jne    110e <packet_record_bounds_window_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <packet_record_bounds_window_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_3, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -9, 32),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x112e: jne    110e <packet_record_bounds_window_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <packet_record_bounds_window_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -11, 24),
    /* 0x1130: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: lea    rsi,[rdx+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1137: movabs r9,0xd6e8feb86659fd93 [warning-reg-remap: 64-bit immediate load; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_LD_IMM64_RAW(BPF_REG_9, 0, 0xd6e8feb86659fd93ULL),
    /* 0x1141: mov    edi,0x300 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 768),
    /* 0x1146: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x1149: jmp    11a4 <packet_record_bounds_window_xdp+0xa4> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 25, 0),
    /* 0x114b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r14,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 32),
    /* 0x1154: mov    ecx,ecx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_4, 0, 0),
    /* 0x1156: or     rcx,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_8, 0, 0),
    /* 0x1159: add    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x115c: movzx  r9d,WORD PTR [rsi-0x1] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1161: lea    ecx,[rax*4+0x0] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, 0, BPF_REG_0, 2, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1168: and    cl,0x1c [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_4, 0, 0, 28),
    /* 0x116b: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x116e: xor    rbx,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1171: mov    ecx,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_5, 0, 0),
    /* 0x1174: and    cl,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_4, 0, 0, 24),
    /* 0x1177: shl    r9,cl [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x117a: add    r9,rbx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_6, 0, 0),
    /* 0x117d: and    eax,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x1180: xor    eax,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1183: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1186: mov    r10,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r9] */
    /* 0x1189: shl    r10,cl [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x118c: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x118e: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1190: shr    r9,cl [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x1193: or     r9,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1196: add    r8,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 8),
    /* 0x119a: add    rsi,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 24),
    /* 0x119e: add    rdi,0xffffffffffffffe8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 18446744073709551592),
    /* 0x11a2: je     11ec <packet_record_bounds_window_xdp+0xec> [bpf-branch: lowered flags from add    rdi,0xffffffffffffffe8 + je     11ec <packet_record_bounds_window_xdp+0xec> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_1, 0, 17, 0),
    /* 0x11a4: movzx  r10d,BYTE PTR [rsi-0x17] [warning-unmapped: destination register r10d is not in the BPF JIT register file] */
    /* 0x11a9: and    r10d,0x3 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x11ad: lea    rax,[r10+0x18] [warning-unmapped: LEA base/index not in BPF register file: [r10+0x18]] */
    /* 0x11b1: cmp    rdi,rax [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11b4: jb     1196 <packet_record_bounds_window_xdp+0x96> [bpf-branch: lowered cmp    rdi,rax + jb     1196 <packet_record_bounds_window_xdp+0x96> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLT, BPF_REG_1, BPF_REG_0, -5),
    /* 0x11b6: movzx  eax,BYTE PTR [rsi-0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_2, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ba: mov    ebx,DWORD PTR [rsi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_2, -19), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11bd: mov    r14d,DWORD PTR [rsi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_2, -15), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11c1: mov    ecx,DWORD PTR [rsi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -11), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11c4: movzx  r11d,WORD PTR [rsi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x11c9: add    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x11cc: add    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11cf: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11d2: mov    ebx,DWORD PTR [rsi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_2, -7), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11d5: test   al,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x11d7: je     1150 <packet_record_bounds_window_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11dd: shl    rcx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 32),
    /* 0x11e1: or     rcx,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_6, 0, 0),
    /* 0x11e4: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11e7: jmp    115c <packet_record_bounds_window_xdp+0x5c> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -39, 0),
    /* 0x11ec: mov    QWORD PTR [rdx],r9 [warning-reg-remap: direct memory store via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x11ef: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x11f4: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11f5: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11f7: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
