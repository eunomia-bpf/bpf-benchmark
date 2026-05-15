#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 56
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: mov    r9,QWORD PTR [rcx+0x8] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x113a: xor    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11b4: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11b7: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c1: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c4: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11d5: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ea: xor    r8,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ed: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f4: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f7: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1205: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x121e: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1228: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1232: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1235: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1238: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x123c: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x123f: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1242: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1254: xor    r9,rsi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1265: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1268: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x126c: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x126f: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1272: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x129c: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12e7: mov    r9,QWORD PTR [rcx+0x28] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12fc: xor    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x135c: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x135f: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1369: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x136c: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x137d: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1392: xor    r8,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1395: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x139c: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x139f: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13ad: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13c6: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13d0: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13da: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13dd: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13e0: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13e4: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13e7: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13ea: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13fc: xor    r9,rsi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x140d: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1410: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1414: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1417: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x141a: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1444: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: ja     1569 <siphash_rotate64_mixer_xdp+0x469> [bpf-branch: lowered cmp    rcx,rdx + ja     1569 <siphash_rotate64_mixer_xdp+0x469> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_3, 448),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1119: ja     1569 <siphash_rotate64_mixer_xdp+0x469> [bpf-branch: lowered cmp    rsi,rdx + ja     1569 <siphash_rotate64_mixer_xdp+0x469> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 443),
    /* 0x111f: lea    rsi,[rcx+0x48] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 72), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1126: ja     1569 <siphash_rotate64_mixer_xdp+0x469> [bpf-branch: lowered cmp    rsi,rdx + ja     1569 <siphash_rotate64_mixer_xdp+0x469> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 438),
    /* 0x112c: mov    r9,QWORD PTR [rcx+0x8] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x1130: movabs rdi,0x7465646279746573 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x7465646279746573ULL),
    /* 0x113a: xor    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x113d: movabs rdx,0x6c7967656e657261 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0x6c7967656e657261ULL),
    /* 0x1147: add    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x114a: movabs rax,0xa60c596fc19fead0 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0xa60c596fc19fead0ULL),
    /* 0x1154: add    rax,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x1157: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x115b: xor    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x115e: movabs r8,0xded7d4e2d7dedfc6 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 0xded7d4e2d7dedfc6ULL),
    /* 0x1168: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x116b: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x116f: movabs rdx,0xe414a674f0de7325 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0xe414a674f0de7325ULL),
    /* 0x1179: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x117c: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1180: xor    rdi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1183: add    r8,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_3, 0, 0),
    /* 0x1186: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x118a: xor    rdx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x118d: rol    r8,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1191: add    rax,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x1194: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1198: xor    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x119b: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x119e: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11a2: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x11a5: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11a9: mov    rsi,QWORD PTR [rcx+0x10] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x11ad: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x11b0: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11b4: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x11b7: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x11ba: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11be: xor    r8,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_2, 0, 0),
    /* 0x11c1: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x11c4: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11c8: xor    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x11cb: add    rax,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x11ce: rol    r8,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11d2: xor    r8,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_0, 0, 0),
    /* 0x11d5: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x11d8: rol    r8,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11dc: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x11df: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11e3: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x11e6: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11ea: xor    r8,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_9, 0, 0),
    /* 0x11ed: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x11f0: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11f4: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x11f7: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x11fb: add    rax,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x11fe: rol    r8,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1202: xor    r8,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_0, 0, 0),
    /* 0x1205: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1208: rol    r8,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x120c: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x120f: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1213: mov    rdi,QWORD PTR [rcx+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x1217: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x121a: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x121e: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x1221: add    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x1224: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1228: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x122b: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x122e: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1232: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1235: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x1238: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x123c: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x123f: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x1242: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1246: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x1249: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x124d: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1250: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1254: xor    r9,rsi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_2, 0, 0),
    /* 0x1257: add    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x125a: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x125e: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x1261: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1265: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x1268: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x126c: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x126f: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x1272: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1276: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x1279: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x127d: mov    r8,QWORD PTR [rcx+0x20] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x1281: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1284: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1288: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x128b: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x128e: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1292: xor    rsi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_5, 0, 0),
    /* 0x1295: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1298: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x129c: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x129f: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x12a2: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12a6: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x12a9: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x12ac: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12b0: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x12b3: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12b7: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x12ba: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12be: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x12c1: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x12c4: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12c8: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x12cb: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12cf: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x12d2: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12d6: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x12d9: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x12dc: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12e0: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x12e3: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12e7: mov    r9,QWORD PTR [rcx+0x28] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 40), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x12eb: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x12ee: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12f2: xor    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x12f5: add    r8,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_3, 0, 0),
    /* 0x12f8: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12fc: xor    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x12ff: xor    rdx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x1302: rol    r8,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1306: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x1309: add    rax,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x130c: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1310: xor    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x1313: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x1316: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x131a: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x131d: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1321: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1324: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1328: xor    rdi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x132b: add    r8,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_3, 0, 0),
    /* 0x132e: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1332: xor    rdx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x1335: rol    r8,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1339: add    rax,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x133c: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1340: xor    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x1343: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x1346: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x134a: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x134d: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1351: mov    rsi,QWORD PTR [rcx+0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x1355: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1358: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x135c: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x135f: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x1362: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1366: xor    r8,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_2, 0, 0),
    /* 0x1369: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x136c: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1370: xor    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x1373: add    rax,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1376: rol    r8,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x137a: xor    r8,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_0, 0, 0),
    /* 0x137d: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1380: rol    r8,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1384: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x1387: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x138b: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x138e: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1392: xor    r8,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_9, 0, 0),
    /* 0x1395: add    r9,rdx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x1398: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x139c: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x139f: rol    r9,0x20 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13a3: add    rax,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x13a6: rol    r8,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13aa: xor    r8,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_0, 0, 0),
    /* 0x13ad: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x13b0: rol    r8,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13b4: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x13b7: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13bb: mov    rdi,QWORD PTR [rcx+0x38] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x13bf: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x13c2: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13c6: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x13c9: add    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x13cc: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13d0: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x13d3: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x13d6: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13da: xor    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x13dd: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x13e0: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13e4: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x13e7: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x13ea: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13ee: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x13f1: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13f5: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x13f8: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x13fc: xor    r9,rsi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_2, 0, 0),
    /* 0x13ff: add    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x1402: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1406: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x1409: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x140d: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x1410: rol    r9,0x10 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1414: xor    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x1417: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x141a: rol    r9,0x15 [warning-reg-remap: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x141e: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x1421: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1425: mov    r8,QWORD PTR [rcx+0x40] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 64), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x1429: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x142c: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1430: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x1433: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x1436: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x143a: xor    rsi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_5, 0, 0),
    /* 0x143d: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1440: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1444: xor    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x1447: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x144a: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x144e: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x1451: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x1454: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1458: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x145b: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x145f: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1462: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1466: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1469: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x146c: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1470: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1473: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1477: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x147a: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x147e: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x1481: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x1484: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1488: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x148b: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x148f: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1492: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1495: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1499: xor    rdi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x149c: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x149f: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14a3: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x14a6: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14aa: xor    rax,0xff [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_K, BPF_REG_0, 0, 0, 255),
    /* 0x14b0: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x14b3: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14b7: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x14ba: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x14bd: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14c1: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x14c4: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14c8: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x14cb: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14cf: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x14d2: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x14d5: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14d9: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x14dc: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14e0: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x14e3: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14e7: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x14ea: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x14ed: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14f1: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x14f4: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14f8: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x14fb: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x14ff: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1502: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x1505: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1509: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x150c: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1510: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x1513: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1517: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x151a: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x151d: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1521: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x1524: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1528: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x152b: rol    rax,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x152f: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1532: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x1535: rol    rdx,0xd [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 13, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1539: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x153c: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1540: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x1543: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 21, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1547: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x154a: add    rax,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x154d: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 17, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1551: mov    rdi,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1554: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 32, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x1558: xor    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x155b: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x155e: xor    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x1561: mov    QWORD PTR [rcx],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x1564: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1569: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
