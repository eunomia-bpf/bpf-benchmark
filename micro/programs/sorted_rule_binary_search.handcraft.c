#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 15
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rcx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rcx+0x8],0x20]
 * - 0x112a: cmp    DWORD PTR [rcx+0xc],0x10 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rcx+0xc],0x10]
 * - 0x114d: xor    r9d,r9d [warning-reg-remap: zero idiom; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1150: mov    r10d,r9d [warning-reg-remap: 32-bit register move; native r10 has no exact BPF JIT register; remapped to BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1153: mov    r11,rdi [warning-reg-remap: movq register-to-register kinsn; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1156: cmp    QWORD PTR [rcx+r8*8+0x10],rsi [warning-unmapped: CMP operand form has no current kinsn selector: cmp    QWORD PTR [rcx+r8*8+0x10],rsi]
 * - 0x115b: sete   r9b [warning-unmapped: sete is flag-bound; automatic conversion needs an adjacent cmp/test proof]
 * - 0x115f: cmove  rdi,r8 [warning-unmapped: cmove needs an adjacent test/cmp proof payload]
 * - 0x1163: or     r9b,r10b [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15; native r10 has no exact BPF JIT register; remapped to BPF_REG_6]
 * - 0x1166: test   r10b,0x1 [warning-reg-remap: testb imm kinsn; native r10 has no exact BPF JIT register; remapped to BPF_REG_6]
 * - 0x116a: cmovne rdi,r11 [warning-unmapped: cmovne needs an adjacent test/cmp proof payload]
 * - 0x1181: test   r9b,0x1 [warning-reg-remap: testb imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1185: cmovne rdx,rdi [warning-unmapped: cmovne needs an adjacent test/cmp proof payload]
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
    /* 0x110c: jbe    110f <sorted_rule_binary_search_xdp+0xf> [bpf-branch: lowered cmp    rcx,rdx + jbe    110f <sorted_rule_binary_search_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_4, BPF_REG_3, 2),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <sorted_rule_binary_search_xdp+0xe> [bpf-branch: lowered cmp    rsi,rdx + ja     110e <sorted_rule_binary_search_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, -6),
    /* 0x1118: lea    rsi,[rcx+0x190] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <sorted_rule_binary_search_xdp+0xe> [bpf-branch: lowered cmp    rsi,rdx + ja     110e <sorted_rule_binary_search_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, -11),
    /* 0x1124: cmp    DWORD PTR [rcx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rcx+0x8],0x20] */
    /* 0x1128: jne    110e <sorted_rule_binary_search_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rcx+0x8],0x20 + jne    110e <sorted_rule_binary_search_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_8, BPF_REG_4, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_8, 0, -13, 32),
    /* 0x112a: cmp    DWORD PTR [rcx+0xc],0x10 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rcx+0xc],0x10] */
    /* 0x112e: jne    110e <sorted_rule_binary_search_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rcx+0xc],0x10 + jne    110e <sorted_rule_binary_search_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_8, BPF_REG_4, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_8, 0, -15, 16),
    /* 0x1130: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1132: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x1134: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: mov    rsi,QWORD PTR [rcx+rax*8+0x110] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_0, 3, 272), MICRO_HANDCRAFT_BPF_X86_MOVQ_SIB),
    /* 0x1148: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x114b: xor    edi,edi [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 0),
    /* 0x114d: xor    r9d,r9d [warning-reg-remap: zero idiom; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 0),
    /* 0x1150: mov    r10d,r9d [warning-reg-remap: 32-bit register move; native r10 has no exact BPF JIT register; remapped to BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1153: mov    r11,rdi [warning-reg-remap: movq register-to-register kinsn; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_7, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1156: cmp    QWORD PTR [rcx+r8*8+0x10],rsi [warning-unmapped: CMP operand form has no current kinsn selector: cmp    QWORD PTR [rcx+r8*8+0x10],rsi] */
    /* 0x115b: sete   r9b [warning-unmapped: sete is flag-bound; automatic conversion needs an adjacent cmp/test proof] */
    /* 0x115f: cmove  rdi,r8 [warning-unmapped: cmove needs an adjacent test/cmp proof payload] */
    /* 0x1163: or     r9b,r10b [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15; native r10 has no exact BPF JIT register; remapped to BPF_REG_6] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_6, 0, 0),
    /* 0x1166: test   r10b,0x1 [warning-reg-remap: testb imm kinsn; native r10 has no exact BPF JIT register; remapped to BPF_REG_6] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x116a: cmovne rdi,r11 [warning-unmapped: cmovne needs an adjacent test/cmp proof payload] */
    /* 0x116e: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1171: cmp    r8,0x20 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 32), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1175: jne    1150 <sorted_rule_binary_search_xdp+0x50> [bpf-branch: lowered cmp    r8,0x20 + jne    1150 <sorted_rule_binary_search_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, -11, 32),
    /* 0x1177: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x117a: add    rsi,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 32),
    /* 0x117e: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x1181: test   r9b,0x1 [warning-reg-remap: testb imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x1185: cmovne rdx,rdi [warning-unmapped: cmovne needs an adjacent test/cmp proof payload] */
    /* 0x1189: inc    rax [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x118c: cmp    rax,0x10 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1190: jne    1140 <sorted_rule_binary_search_xdp+0x40> [bpf-branch: lowered cmp    rax,0x10 + jne    1140 <sorted_rule_binary_search_xdp+0x40> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, -25, 16),
    /* 0x1192: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x1195: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x119a: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
