#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 36
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1148: movabs r11,0x589965cc75374cc3 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x589965cc75374cc3]
 * - 0x1167: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11a3: mov    r12d,DWORD PTR [rsi-0xb] [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,DWORD PTR [rsi-0xb]]
 * - 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: cannot lower cmp    r12d,0x2001 + jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> to BPF branch]
 * - 0x11b0: movzx  ebp,WORD PTR [rsi-0x7] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11b4: mov    r9d,DWORD PTR [rsi-0x3] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11bc: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11c0: mov    r13d,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    r13d,r12d]
 * - 0x11c3: mov    r10d,0x8 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x8]
 * - 0x11c9: cmove  r13d,r10d [warning-unmapped: cmove operands are not supported]
 * - 0x11cd: mov    rbx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11d4: lea    r10,[rip+0xe25] [warning-unmapped: LEA operands are not representable]
 * - 0x11db: or     rbx,QWORD PTR [r10+r14*8] [warning-unmapped: ALU memory base r10 is not in the BPF JIT register file]
 * - 0x11eb: test   bpl,0x2 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11ef: je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11f6: mov    ecx,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r12d]
 * - 0x1203: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x122c: add    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x122f: movzx  eax,bp [warning-unmapped: movzx source size not recognized: bp]
 * - 0x1236: or     r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1239: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9]
 * - 0x1241: mov    QWORD PTR [rdx],r11 [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rdx],r11]
 * - 0x1249: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124c: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124e: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1250: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1252: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -4),
    /* 0x1118: lea    rsi,[rdx+0x250] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 592), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x18 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0x8],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -9, 24),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -11, 24),
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113a: lea    rsi,[rdx+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113e: movabs rdi,0x100000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x100000000ULL),
    /* 0x1148: movabs r11,0x589965cc75374cc3 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x589965cc75374cc3] */
    /* 0x1152: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x1155: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x1157: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: shl    r14,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 48),
    /* 0x1164: or     r14,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_0, 0, 0),
    /* 0x1167: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x116a: inc    r8 [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x116d: add    rsi,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 24),
    /* 0x1171: cmp    r8,0x18 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1175: je     1241 <otel_stack_frame_unwind_scan_xdp+0x141> [bpf-branch: lowered cmp    r8,0x18 + je     1241 <otel_stack_frame_unwind_scan_xdp+0x141> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 48, 24),
    /* 0x117b: mov    rax,QWORD PTR [rsi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_2, -23), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x117f: movzx  ecx,BYTE PTR [rsi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1183: movzx  r14d,BYTE PTR [rsi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_2, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1188: shl    r14d,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 8),
    /* 0x118c: or     r14,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x118f: cmp    r14w,0x3 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1194: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: lowered cmp    r14w,0x3 + ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_8, 0, -14, 3),
    /* 0x1196: mov    r15d,DWORD PTR [rsi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -15), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x119a: cmp    r15d,0x1000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11a1: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: lowered cmp    r15d,0x1000 + ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_9, 0, -17, 4096),
    /* 0x11a3: mov    r12d,DWORD PTR [rsi-0xb] [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,DWORD PTR [rsi-0xb]] */
    /* 0x11a7: cmp    r12d,0x2001 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: cannot lower cmp    r12d,0x2001 + jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> to BPF branch] */
    /* 0x11b0: movzx  ebp,WORD PTR [rsi-0x7] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11b4: mov    r9d,DWORD PTR [rsi-0x3] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11b8: movzx  r14d,r14w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11bc: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11c0: mov    r13d,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    r13d,r12d] */
    /* 0x11c3: mov    r10d,0x8 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x8] */
    /* 0x11c9: cmove  r13d,r10d [warning-unmapped: cmove operands are not supported] */
    /* 0x11cd: mov    rbx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11d0: shl    rbx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 32),
    /* 0x11d4: lea    r10,[rip+0xe25] [warning-unmapped: LEA operands are not representable] */
    /* 0x11db: or     rbx,QWORD PTR [r10+r14*8] [warning-unmapped: ALU memory base r10 is not in the BPF JIT register file] */
    /* 0x11df: add    r13d,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x11e2: add    rdi,r13 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_7, 0, 0),
    /* 0x11e5: xor    rax,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x11e8: xor    rax,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x11eb: test   bpl,0x2 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11ef: je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11f1: inc    ecx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x11f3: rol    rax,cl [exact-kinsn: rolq cl kinsn; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_0, BPF_REG_4, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLQ_CL),
    /* 0x11f6: mov    ecx,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r12d] */
    /* 0x11f9: shl    rcx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 24),
    /* 0x11fd: mov    ebx,r15d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1200: xor    rbx,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1203: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x1207: mov    r14d,0x0 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_8, 0, 0, 0),
    /* 0x120d: cmovne r14,rbx [exact-kinsn: cmov kinsn; cond register must match prior test] */
    HC_KINSN(HC_CMOV_PAYLOAD(BPF_REG_8, BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ_RR),
    /* 0x1211: add    r14,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_0, 0, 0),
    /* 0x1214: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1217: and    al,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 7),
    /* 0x1219: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x121c: mov    rbx,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x121f: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1222: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1224: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1226: shr    r14,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x1229: or     r14,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x122c: add    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x122f: movzx  eax,bp [warning-unmapped: movzx source size not recognized: bp] */
    /* 0x1232: shl    rax,0x28 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 40),
    /* 0x1236: or     r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x1239: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9] */
    /* 0x123c: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -51, 0),
    /* 0x1241: mov    QWORD PTR [rdx],r11 [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rdx],r11] */
    /* 0x1244: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1249: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x124a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x124c: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x124e: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1250: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1252: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1253: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
