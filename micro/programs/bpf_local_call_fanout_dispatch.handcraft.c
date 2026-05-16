#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 25
 *
 * - 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1112: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1113: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1116: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1118: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x111a: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x111c: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x111e: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x111f: sub    rsp,0x18 [warning-unmapped: ALU destination rsp is not in the BPF JIT register file]
 * - 0x1148: jne    1219 <bpf_local_call_fanout_dispatch_xdp+0x119> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1152: jne    1219 <bpf_local_call_fanout_dispatch_xdp+0x119> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1187: call   1280 <local_call_pressure> [warning-unmapped: unsupported mnemonic or operand form: call   1280 <local_call_pressure>]
 * - 0x11b4: je     1211 <bpf_local_call_fanout_dispatch_xdp+0x111> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11db: jne    1200 <bpf_local_call_fanout_dispatch_xdp+0x100> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11e4: call   1230 <local_call_linear> [warning-unmapped: unsupported mnemonic or operand form: call   1230 <local_call_linear>]
 * - 0x11f7: call   12d0 <local_call_crossload> [warning-unmapped: unsupported mnemonic or operand form: call   12d0 <local_call_crossload>]
 * - 0x1207: call   1360 <local_call_bytes> [warning-unmapped: unsupported mnemonic or operand form: call   1360 <local_call_bytes>]
 * - 0x1219: add    rsp,0x18 [warning-unmapped: ALU destination rsp is not in the BPF JIT register file]
 * - 0x121d: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x121e: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1220: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1222: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1224: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1226: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: ja     1227 <bpf_local_call_fanout_dispatch_xdp+0x127> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, 90, 0),
    /* 0x1112: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1113: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1116: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1118: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x111a: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x111c: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x111e: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x111f: sub    rsp,0x18 [warning-unmapped: ALU destination rsp is not in the BPF JIT register file] */
    /* 0x1123: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1127: mov    QWORD PTR [rbp-0x30],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, HC_X86_RBP_STACK_BASE, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x112b: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x112e: ja     1219 <bpf_local_call_fanout_dispatch_xdp+0x119> [bpf-branch: verifier-visible branch from preceding cmp    rdx,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, 83, 0),
    /* 0x1134: lea    rdx,[rsi+0x190] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113b: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x113e: ja     1219 <bpf_local_call_fanout_dispatch_xdp+0x119> [bpf-branch: verifier-visible branch from preceding cmp    rdx,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, 78, 0),
    /* 0x1144: cmp    DWORD PTR [rsi+0x8],0x10 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 8, 16), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1148: jne    1219 <bpf_local_call_fanout_dispatch_xdp+0x119> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x114e: cmp    DWORD PTR [rsi+0xc],0x18 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 12, 24), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1152: jne    1219 <bpf_local_call_fanout_dispatch_xdp+0x119> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1158: movabs rdi,0x243f6a8885a308d3 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x243f6a8885a308d3ULL),
    /* 0x1162: xor    r12d,r12d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1165: mov    r13d,0x17 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_7, 23), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x116b: xor    ebx,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x116d: mov    QWORD PTR [rbp-0x38],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, HC_X86_RBP_STACK_BASE, -56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1171: jmp    11b6 <bpf_local_call_fanout_dispatch_xdp+0xb6> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 26, 0),
    /* 0x1173: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1180: mov    rsi,QWORD PTR [rbp-0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RBP_STACK_BASE, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1184: mov    ecx,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1187: call   1280 <local_call_pressure> [warning-unmapped: unsupported mnemonic or operand form: call   1280 <local_call_pressure>] */
    /* 0x118c: mov    ecx,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x118e: and    cl,0x38 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1191: shl    r15,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1194: mov    edi,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1197: add    rdi,r15 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119a: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x119d: add    rbx,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a1: add    r12d,0x10 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 16), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11a5: add    r13,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a9: cmp    rbx,0x80 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 128), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11b0: mov    rsi,QWORD PTR [rbp-0x38] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RBP_STACK_BASE, -56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11b4: je     1211 <bpf_local_call_fanout_dispatch_xdp+0x111> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11b6: movzx  r15d,BYTE PTR [rsi+r13*1-0x7] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_9, BPF_REG_2, BPF_REG_7, 0, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11bc: and    r15d,0x3 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 3), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11c0: mov    r14d,DWORD PTR [rsi+r13*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_8, BPF_REG_2, BPF_REG_7, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c5: xor    r14d,r12d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11c8: lea    rdx,[r13-0xf] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_7, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11cc: cmp    r15,0x2 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11d0: je     11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> [bpf-branch: verifier-visible branch from preceding cmp    r15,0x2; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_9, 0, 10, 2),
    /* 0x11d2: cmp    r15d,0x1 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_9, 1), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11d6: je     1180 <bpf_local_call_fanout_dispatch_xdp+0x80> [bpf-branch: verifier-visible branch from preceding cmp    r15d,0x1; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_9, 0, -42, 1),
    /* 0x11d8: test   r15d,r15d [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x11db: jne    1200 <bpf_local_call_fanout_dispatch_xdp+0x100> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11dd: mov    rsi,QWORD PTR [rbp-0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RBP_STACK_BASE, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11e1: mov    ecx,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e4: call   1230 <local_call_linear> [warning-unmapped: unsupported mnemonic or operand form: call   1230 <local_call_linear>] */
    /* 0x11e9: jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -45, 0),
    /* 0x11eb: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: mov    rsi,QWORD PTR [rbp-0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RBP_STACK_BASE, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11f4: mov    ecx,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f7: call   12d0 <local_call_crossload> [warning-unmapped: unsupported mnemonic or operand form: call   12d0 <local_call_crossload>] */
    /* 0x11fc: jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -50, 0),
    /* 0x11fe: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1200: mov    rsi,QWORD PTR [rbp-0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RBP_STACK_BASE, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1204: mov    ecx,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1207: call   1360 <local_call_bytes> [warning-unmapped: unsupported mnemonic or operand form: call   1360 <local_call_bytes>] */
    /* 0x120c: jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -55, 0),
    /* 0x1211: mov    QWORD PTR [rsi],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1214: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1219: add    rsp,0x18 [warning-unmapped: ALU destination rsp is not in the BPF JIT register file] */
    /* 0x121d: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x121e: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1220: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1222: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1224: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1226: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1227: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
