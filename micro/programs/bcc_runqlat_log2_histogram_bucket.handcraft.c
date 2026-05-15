#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 35
 *
 * - 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112e: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1130: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1144: mov    edx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edx,r11d]
 * - 0x1154: mov    rax,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rax,r10]
 * - 0x115e: je     123b <bcc_runqlat_log2_histogram_bucket_xdp+0x13b> [warning-unmapped: cannot lower cmp    r10,0x80 + je     123b <bcc_runqlat_log2_histogram_bucket_xdp+0x13b> to BPF branch]
 * - 0x1190: mov    r9d,r8d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1193: lea    r8d,[r9+0x1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x119d: mov    r9,rdx [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11a0: shr    r9,1 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11a7: mov    rdx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11aa: ja     1190 <bcc_runqlat_log2_histogram_bucket_xdp+0x90> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11c0: movzx  r10d,BYTE PTR [rsi+rax*8+0x15] [warning-unmapped: destination register r10d is not in the BPF JIT register file]
 * - 0x11c6: shl    r10,0x28 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x11ca: or     r10,rcx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x11cd: or     r10,rdx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x11d9: movzx  r9d,BYTE PTR [rsi+rax*8+0x17] [warning-reg-remap: indexed memory load via x86 SIB kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11df: shl    r9,0x38 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11e3: or     r9,rcx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11e6: or     r9,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x11ed: mov    r11d,0x19 [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,0x19]
 * - 0x11f3: cmovb  r11d,r8d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x11f7: lea    r14d,[r11+0x1] [warning-unmapped: LEA base/index not in BPF register file: [r11+0x1]]
 * - 0x11fb: mov    edx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edx,r11d]
 * - 0x1204: mov    r15,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x120a: lea    r10,[rax+0x1] [warning-unmapped: LEA operands are not representable]
 * - 0x120e: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x1214: mov    rbx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x122f: shr    r9,0x20 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1233: add    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1243: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1244: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1246: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <bcc_runqlat_log2_histogram_bucket_xdp+0xf> [bpf-branch: lowered cmp    rsi,rcx + jbe    110f <bcc_runqlat_log2_histogram_bucket_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_2, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -4),
    /* 0x1118: lea    rdi,[rsi+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> [bpf-branch: lowered cmp    rdi,rcx + ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [rdx],0x80 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x112a: jne    110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx],0x80 + jne    110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_3, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -9, 128),
    /* 0x112c: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112e: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1130: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: mov    edi,DWORD PTR [rsi+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 12), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x1134: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1136: jmp    1164 <bcc_runqlat_log2_histogram_bucket_xdp+0x64> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 7, 0),
    /* 0x1138: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: shl    rax,0x3 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 3),
    /* 0x1144: mov    edx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edx,r11d] */
    /* 0x1147: and    al,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 56),
    /* 0x1149: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x114b: shl    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x114e: xor    rbx,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_3, 0, 0),
    /* 0x1151: mov    rdi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1154: mov    rax,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rax,r10] */
    /* 0x1157: cmp    r10,0x80 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x115e: je     123b <bcc_runqlat_log2_histogram_bucket_xdp+0x13b> [warning-unmapped: cannot lower cmp    r10,0x80 + je     123b <bcc_runqlat_log2_histogram_bucket_xdp+0x13b> to BPF branch] */
    /* 0x1164: movzx  edx,WORD PTR [rsi+rax*8+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_3, BPF_REG_2, BPF_REG_0, 3, 16), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x1169: movzx  ecx,BYTE PTR [rsi+rax*8+0x12] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_2, BPF_REG_0, 3, 18), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x116e: shl    ecx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 16),
    /* 0x1171: or     rcx,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_3, 0, 0),
    /* 0x1174: mov    edx,ecx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x1176: shr    edx,0x3 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_3, 0, 0, 3),
    /* 0x1179: mov    r8d,0x0 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x117f: and    edx,0xfffff [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 1048575), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x1185: je     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac> [bpf-branch: lowered flags from and    edx,0xfffff + je     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_3, 0, 12, 0),
    /* 0x1187: inc    rdx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_3, 0, 0, 1),
    /* 0x118a: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x118d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1190: mov    r9d,r8d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1193: lea    r8d,[r9+0x1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_9, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1197: cmp    r9d,0x3d [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x119b: ja     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac> [bpf-branch: lowered cmp    r9d,0x3d + ja     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_9, 0, 6, 61),
    /* 0x119d: mov    r9,rdx [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11a0: shr    r9,1 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 1), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x11a3: cmp    rdx,0x3 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11a7: mov    rdx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11aa: ja     1190 <bcc_runqlat_log2_histogram_bucket_xdp+0x90> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11ac: movzx  edx,BYTE PTR [rsi+rax*8+0x13] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_3, BPF_REG_2, BPF_REG_0, 3, 19), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x11b1: shl    edx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x11b4: or     rdx,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x11b7: movzx  ecx,BYTE PTR [rsi+rax*8+0x14] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_2, BPF_REG_0, 3, 20), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x11bc: shl    rcx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 32),
    /* 0x11c0: movzx  r10d,BYTE PTR [rsi+rax*8+0x15] [warning-unmapped: destination register r10d is not in the BPF JIT register file] */
    /* 0x11c6: shl    r10,0x28 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x11ca: or     r10,rcx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x11cd: or     r10,rdx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x11d0: movzx  ecx,BYTE PTR [rsi+rax*8+0x16] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_2, BPF_REG_0, 3, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x11d5: shl    rcx,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 48),
    /* 0x11d9: movzx  r9d,BYTE PTR [rsi+rax*8+0x17] [warning-reg-remap: indexed memory load via x86 SIB kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_9, BPF_REG_2, BPF_REG_0, 3, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x11df: shl    r9,0x38 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 56),
    /* 0x11e3: or     r9,rcx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x11e6: or     r9,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x11e9: cmp    r8d,0x19 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11ed: mov    r11d,0x19 [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,0x19] */
    /* 0x11f3: cmovb  r11d,r8d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x11f7: lea    r14d,[r11+0x1] [warning-unmapped: LEA base/index not in BPF register file: [r11+0x1]] */
    /* 0x11fb: mov    edx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edx,r11d] */
    /* 0x11fe: and    dl,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_3, 0, 0, 7),
    /* 0x1201: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1204: mov    r15,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1207: shl    r15,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x120a: lea    r10,[rax+0x1] [warning-unmapped: LEA operands are not representable] */
    /* 0x120e: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x1212: not    dl [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_3, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1214: mov    rbx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1217: mov    ecx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_3, 0, 0),
    /* 0x1219: shr    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x121c: add    rdi,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_8, 0, 0),
    /* 0x121f: or     rbx,r15 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1222: xor    rbx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x1225: cmp    r8d,0x19 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1229: jb     1140 <bcc_runqlat_log2_histogram_bucket_xdp+0x40> [bpf-branch: lowered cmp    r8d,0x19 + jb     1140 <bcc_runqlat_log2_histogram_bucket_xdp+0x40> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_5, 0, -61, 25),
    /* 0x122f: shr    r9,0x20 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1233: add    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1236: jmp    1151 <bcc_runqlat_log2_histogram_bucket_xdp+0x51> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -60, 0),
    /* 0x123b: mov    QWORD PTR [rsi],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x123e: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1243: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1244: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1246: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1248: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
