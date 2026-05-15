#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 24
 *
 * - 0x1100: mov    rax,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x113c: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113e: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1140: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1142: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x115c: xor    r9d,r9d [warning-reg-remap: zero idiom; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x115f: movabs r10,0x9e3779b97f4a7c15 [warning-unmapped: unsupported mnemonic or operand form: movabs r10,0x9e3779b97f4a7c15]
 * - 0x1169: movabs r11,0x100000001b3 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x100000001b3]
 * - 0x1180: inc    r9 [warning-reg-remap: inc lowered to add immediate; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1183: mov    rbx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1186: imul   rbx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rbx,r10]
 * - 0x11a0: mov    r12,r14 [warning-unmapped: unsupported mnemonic or operand form: mov    r12,r14]
 * - 0x11a3: xor    r12,rbx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x11a6: add    r12,QWORD PTR [rax+r15*8+0x10] [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x11ab: xor    r12,rdx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x11ae: rol    r12,cl [warning-unmapped: ROL width/register not supported by current selectors: r12]
 * - 0x11b4: imul   r12,r11 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r12,r11]
 * - 0x11b8: mov    rdx,r12 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r12]
 * - 0x11bf: xor    rdx,r12 [warning-unmapped: ALU source r12 is not supported]
 * - 0x11e5: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x11e6: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x11e8: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x11ea: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rax,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_0, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: cmp    rax,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110a: jbe    111e <cgroup_skb_hash_chain_prog+0x1e> [bpf-branch: lowered cmp    rax,rcx + jbe    111e <cgroup_skb_hash_chain_prog+0x1e> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_0, BPF_REG_4, 6),
    /* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff [bpf-jit: immediate memory store] */
    HC_ST(BPF_W, BPF_REG_1, 16, 4294967295),
    /* 0x1113: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1115: mov    edx,0xffffffff [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 4294967295),
    /* 0x111a: mov    DWORD PTR [rdi+0x14],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 20), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM_REG),
    /* 0x111d: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x111e: lea    rdx,[rax+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1122: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1125: ja     110c <cgroup_skb_hash_chain_prog+0xc> [bpf-branch: lowered cmp    rdx,rcx + ja     110c <cgroup_skb_hash_chain_prog+0xc> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -9),
    /* 0x1127: lea    rdx,[rax+0x50] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 80), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112b: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x112e: ja     110c <cgroup_skb_hash_chain_prog+0xc> [bpf-branch: lowered cmp    rdx,rcx + ja     110c <cgroup_skb_hash_chain_prog+0xc> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -12),
    /* 0x1130: cmp    DWORD PTR [rax+0x8],0x10 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1134: jne    110c <cgroup_skb_hash_chain_prog+0xc> [bpf-branch: lowered cmp    DWORD PTR [rax+0x8],0x10 + jne    110c <cgroup_skb_hash_chain_prog+0xc> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_0, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -14, 16),
    /* 0x1136: cmp    DWORD PTR [rax+0xc],0x8 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x113a: jne    110c <cgroup_skb_hash_chain_prog+0xc> [bpf-branch: lowered cmp    DWORD PTR [rax+0xc],0x8 + jne    110c <cgroup_skb_hash_chain_prog+0xc> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_0, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -16, 8),
    /* 0x113c: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113e: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1140: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1142: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1143: movabs rdx,0xcbf29ce484222325 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0xcbf29ce484222325ULL),
    /* 0x114d: mov    esi,0x7 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 7),
    /* 0x1152: movabs r8,0xd1342543de82ef95 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 0xd1342543de82ef95ULL),
    /* 0x115c: xor    r9d,r9d [warning-reg-remap: zero idiom; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 0),
    /* 0x115f: movabs r10,0x9e3779b97f4a7c15 [warning-unmapped: unsupported mnemonic or operand form: movabs r10,0x9e3779b97f4a7c15] */
    /* 0x1169: movabs r11,0x100000001b3 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x100000001b3] */
    /* 0x1173: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1180: inc    r9 [warning-reg-remap: inc lowered to add immediate; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x1183: mov    rbx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1186: imul   rbx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rbx,r10] */
    /* 0x118a: mov    r14,r8 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x118d: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1190: xor    r15d,r15d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 0),
    /* 0x1193: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    r12,r14 [warning-unmapped: unsupported mnemonic or operand form: mov    r12,r14] */
    /* 0x11a3: xor    r12,rbx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x11a6: add    r12,QWORD PTR [rax+r15*8+0x10] [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x11ab: xor    r12,rdx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x11ae: rol    r12,cl [warning-unmapped: ROL width/register not supported by current selectors: r12] */
    /* 0x11b1: inc    r15 [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x11b4: imul   r12,r11 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r12,r11] */
    /* 0x11b8: mov    rdx,r12 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r12] */
    /* 0x11bb: shr    rdx,0x1d [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 29), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x11bf: xor    rdx,r12 [warning-unmapped: ALU source r12 is not supported] */
    /* 0x11c2: add    rcx,0xb [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 11),
    /* 0x11c6: add    r14,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_5, 0, 0),
    /* 0x11c9: cmp    r15,0x8 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11cd: jne    11a0 <cgroup_skb_hash_chain_prog+0xa0> [bpf-branch: lowered cmp    r15,0x8 + jne    11a0 <cgroup_skb_hash_chain_prog+0xa0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, -6, 8),
    /* 0x11cf: add    rsi,0x5 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 5),
    /* 0x11d3: cmp    r9,0x10 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11d7: jne    1180 <cgroup_skb_hash_chain_prog+0x80> [bpf-branch: lowered cmp    r9,0x10 + jne    1180 <cgroup_skb_hash_chain_prog+0x80> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, -16, 16),
    /* 0x11d9: mov    DWORD PTR [rdi+0x10],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM_REG),
    /* 0x11dc: shr    rdx,0x20 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x11e0: mov    eax,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 1),
    /* 0x11e5: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11e6: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11e8: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11ea: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11ec: mov    DWORD PTR [rdi+0x14],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 20), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM_REG),
    /* 0x11ef: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
