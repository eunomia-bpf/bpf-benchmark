#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 29
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1129: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x118d: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1192: test   r9b,0x1 [warning-reg-remap: testb imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1196: je     11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1198: movzx  r9d,BYTE PTR [rdi-0xd] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x119d: test   r9b,r9b [warning-reg-remap: testb reg,reg kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11a0: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef> [warning-unmapped: unsupported mnemonic or operand form: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef>]
 * - 0x11a2: movzx  r9d,BYTE PTR [rdi-0xc] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11a7: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d]
 * - 0x11aa: xor    r10d,r8d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x11b1: jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5> [warning-unmapped: cannot lower cmp    r10b,0x11 + jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5> to BPF branch]
 * - 0x11b3: movzx  r9d,BYTE PTR [rdi-0xb] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11b8: add    cl,r9b [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c4: mov    r9d,ecx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c7: and    r9b,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11d1: movzx  r9d,BYTE PTR [rdi-0x9] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ef: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f5: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f9: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1204: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1208: xor    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x121d: mov    r10d,ecx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ecx]
 * - 0x1220: and    r10b,0x3 [warning-unmapped: ALU destination r10b is not in the BPF JIT register file]
 * - 0x1228: je     113d <cilium_policy_guard_tree_filter_xdp+0x3d> [warning-unmapped: cannot lower cmp    r10b,0x1 + je     113d <cilium_policy_guard_tree_filter_xdp+0x3d> to BPF branch]
 * - 0x122e: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1237: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh]
 * - 0x1274: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <cilium_policy_guard_tree_filter_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <cilium_policy_guard_tree_filter_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -4),
    /* 0x1118: lea    rdi,[rdx+0x20c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 524), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> [bpf-branch: lowered cmp    rdi,rcx + ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [rsi],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1127: jne    110e <cilium_policy_guard_tree_filter_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi],0x20 + jne    110e <cilium_policy_guard_tree_filter_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_2, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -9, 32),
    /* 0x1129: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112a: lea    rdi,[rdx+0x1b] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 27), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112e: movabs rsi,0xe7037ed1a0b428db [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0xe7037ed1a0b428dbULL),
    /* 0x1138: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x113b: jmp    117f <cilium_policy_guard_tree_filter_xdp+0x7f> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 18, 0),
    /* 0x113d: shl    rcx,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 48),
    /* 0x1141: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: xor    rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x1153: add    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x1156: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1159: and    al,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 7),
    /* 0x115b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x115e: mov    rbx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1161: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1164: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1166: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1168: shr    rsi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x116b: or     rsi,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_6, 0, 0),
    /* 0x116e: inc    r8 [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x1171: add    rdi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1175: cmp    r8,0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1179: je     1234 <cilium_policy_guard_tree_filter_xdp+0x134> [bpf-branch: lowered cmp    r8,0x20 + je     1234 <cilium_policy_guard_tree_filter_xdp+0x134> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 48, 32),
    /* 0x117f: movzx  ecx,BYTE PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1183: mov    rax,QWORD PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x1187: cmp    rcx,0x21 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x118b: jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50> [bpf-branch: lowered cmp    rcx,0x21 + jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_4, 0, -22, 33),
    /* 0x118d: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1192: test   r9b,0x1 [warning-reg-remap: testb imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x1196: je     11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1198: movzx  r9d,BYTE PTR [rdi-0xd] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x119d: test   r9b,r9b [warning-reg-remap: testb reg,reg kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x11a0: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef> [warning-unmapped: unsupported mnemonic or operand form: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef>] */
    /* 0x11a2: movzx  r9d,BYTE PTR [rdi-0xc] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11a7: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d] */
    /* 0x11aa: xor    r10d,r8d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x11ad: cmp    r10b,0x11 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11b1: jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5> [warning-unmapped: cannot lower cmp    r10b,0x11 + jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5> to BPF branch] */
    /* 0x11b3: movzx  r9d,BYTE PTR [rdi-0xb] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11b8: add    cl,r9b [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_4, BPF_REG_9, 0, 0),
    /* 0x11bb: cmp    cl,0xbf [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11be: ja     1204 <cilium_policy_guard_tree_filter_xdp+0x104> [bpf-branch: lowered cmp    cl,0xbf + ja     1204 <cilium_policy_guard_tree_filter_xdp+0x104> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_4, 0, 19, 191),
    /* 0x11c0: movzx  ecx,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11c4: mov    r9d,ecx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x11c7: and    r9b,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x11cb: cmp    r9b,0x10 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11cf: jne    1210 <cilium_policy_guard_tree_filter_xdp+0x110> [bpf-branch: lowered cmp    r9b,0x10 + jne    1210 <cilium_policy_guard_tree_filter_xdp+0x110> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 17, 16),
    /* 0x11d1: movzx  r9d,BYTE PTR [rdi-0x9] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11d6: cmp    r9d,0xaa [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11dd: jne    1219 <cilium_policy_guard_tree_filter_xdp+0x119> [bpf-branch: lowered cmp    r9d,0xaa + jne    1219 <cilium_policy_guard_tree_filter_xdp+0x119> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 17, 170),
    /* 0x11df: xor    rcx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x11e2: shld   rcx,rax,0x7 [exact-kinsn: shld imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_SHD_PAYLOAD(BPF_REG_4, BPF_REG_0, 7, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_SHLDQ_IMM),
    /* 0x11e7: add    rsi,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x11ea: jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -47, 0),
    /* 0x11ef: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 8),
    /* 0x11f3: jmp    1208 <cilium_policy_guard_tree_filter_xdp+0x108> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x11f5: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x11f9: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x11fc: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x11ff: jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -53, 0),
    /* 0x1204: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x1208: xor    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x120b: jmp    1153 <cilium_policy_guard_tree_filter_xdp+0x53> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -57, 0),
    /* 0x1210: shl    rcx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 32),
    /* 0x1214: add    rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x1217: jmp    11fc <cilium_policy_guard_tree_filter_xdp+0xfc> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -8, 0),
    /* 0x1219: movzx  ecx,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x121d: mov    r10d,ecx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ecx] */
    /* 0x1220: and    r10b,0x3 [warning-unmapped: ALU destination r10b is not in the BPF JIT register file] */
    /* 0x1224: cmp    r10b,0x1 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1228: je     113d <cilium_policy_guard_tree_filter_xdp+0x3d> [warning-unmapped: cannot lower cmp    r10b,0x1 + je     113d <cilium_policy_guard_tree_filter_xdp+0x3d> to BPF branch] */
    /* 0x122e: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 40),
    /* 0x1232: jmp    11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -13, 0),
    /* 0x1234: mov    BYTE PTR [rdx],sil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1237: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh] */
    /* 0x123a: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x123c: shr    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x123f: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1242: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x1244: shr    eax,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 24),
    /* 0x1247: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x124a: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x124d: shr    rax,0x20 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1251: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1254: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1257: shr    rax,0x28 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x125b: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x125e: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1261: shr    rax,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1265: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1268: shr    rbx,0x38 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x126c: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x126f: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1274: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1275: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
