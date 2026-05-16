#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 38
 *
 * - 0x1100: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1101: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1103: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1105: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1107: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1109: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x110a: push   rax [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x110b: mov    r14,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x110e: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1119: add    rsp,0x8 [warning-unmapped: ALU destination rsp is not in the BPF JIT register file]
 * - 0x111d: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x111e: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1120: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1122: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1124: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1126: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112c: mov    QWORD PTR [rsp],rdx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1141: cmp    DWORD PTR [r14+0x8],0x10 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r14+0x8],0x10]
 * - 0x1146: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [warning-unmapped: cannot lower cmp    DWORD PTR [r14+0x8],0x10 + jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> to BPF branch]
 * - 0x1148: cmp    DWORD PTR [r14+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r14+0xc],0x18]
 * - 0x114d: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [warning-unmapped: cannot lower cmp    DWORD PTR [r14+0xc],0x18 + jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> to BPF branch]
 * - 0x115c: mov    r12d,0x17 [warning-unmapped: movl immediate into HC_X86_R12 needs an immediate-load kinsn]
 * - 0x1170: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1174: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp]
 * - 0x1176: call   1260 <local_call_pressure> [warning-unmapped: unsupported mnemonic or operand form: call   1260 <local_call_pressure>]
 * - 0x1184: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp]
 * - 0x11aa: mov    ebp,DWORD PTR [r14+r12*1-0x3] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [r14+r12*1-0x3]]
 * - 0x11af: xor    ebp,r15d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11c4: jne    11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11c6: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x11ca: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp]
 * - 0x11cc: call   1210 <local_call_linear> [warning-unmapped: unsupported mnemonic or operand form: call   1210 <local_call_linear>]
 * - 0x11e0: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x11e4: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp]
 * - 0x11e6: call   12b0 <local_call_crossload> [warning-unmapped: unsupported mnemonic or operand form: call   12b0 <local_call_crossload>]
 * - 0x11f0: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x11f4: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp]
 * - 0x11f6: call   1340 <local_call_bytes> [warning-unmapped: unsupported mnemonic or operand form: call   1340 <local_call_bytes>]
 */

static const struct bpf_insn program[] = {
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1101: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1103: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1105: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1107: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1109: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x110a: push   rax [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x110b: mov    r14,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_8, BPF_REG_1, 0),
    /* 0x110e: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1112: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1114: cmp    r14,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1117: jbe    1128 <bpf_local_call_fanout_dispatch_xdp+0x28> [bpf-branch: lowered cmp    r14,rcx + jbe    1128 <bpf_local_call_fanout_dispatch_xdp+0x28> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_8, BPF_REG_4, 1),
    /* 0x1119: add    rsp,0x8 [warning-unmapped: ALU destination rsp is not in the BPF JIT register file] */
    /* 0x111d: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x111e: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1120: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1122: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1124: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1126: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1127: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x1128: lea    rdx,[r14+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_8, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112c: mov    QWORD PTR [rsp],rdx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1130: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1133: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [bpf-branch: lowered cmp    rdx,rcx + ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -6),
    /* 0x1135: lea    rdx,[r14+0x190] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_8, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x113f: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [bpf-branch: lowered cmp    rdx,rcx + ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -11),
    /* 0x1141: cmp    DWORD PTR [r14+0x8],0x10 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r14+0x8],0x10] */
    /* 0x1146: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [warning-unmapped: cannot lower cmp    DWORD PTR [r14+0x8],0x10 + jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> to BPF branch] */
    /* 0x1148: cmp    DWORD PTR [r14+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r14+0xc],0x18] */
    /* 0x114d: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [warning-unmapped: cannot lower cmp    DWORD PTR [r14+0xc],0x18 + jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> to BPF branch] */
    /* 0x114f: movabs rdi,0x243f6a8885a308d3 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x243f6a8885a308d3ULL),
    /* 0x1159: xor    r15d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115c: mov    r12d,0x17 [warning-unmapped: movl immediate into HC_X86_R12 needs an immediate-load kinsn] */
    /* 0x1162: xor    r13d,r13d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1165: jmp    11a1 <bpf_local_call_fanout_dispatch_xdp+0xa1> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 18, 0),
    /* 0x1167: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1170: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1174: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp] */
    /* 0x1176: call   1260 <local_call_pressure> [warning-unmapped: unsupported mnemonic or operand form: call   1260 <local_call_pressure>] */
    /* 0x117b: mov    ecx,r13d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117e: and    cl,0x38 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1181: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1184: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp] */
    /* 0x1186: add    rdi,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1189: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x118c: add    r13,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1190: add    r15d,0x10 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 16), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1194: add    r12,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1198: cmp    r13,0x80 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_7, 128), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x119f: je     1200 <bpf_local_call_fanout_dispatch_xdp+0x100> [bpf-branch: lowered cmp    r13,0x80 + je     1200 <bpf_local_call_fanout_dispatch_xdp+0x100> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, 17, 128),
    /* 0x11a1: movzx  ebx,BYTE PTR [r14+r12*1-0x7] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_8, HC_X86_R12, 0, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a7: and    ebx,0x3 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 3), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11aa: mov    ebp,DWORD PTR [r14+r12*1-0x3] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [r14+r12*1-0x3]] */
    /* 0x11af: xor    ebp,r15d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11b2: lea    rdx,[r12-0xf] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, HC_X86_R12, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11b7: cmp    rbx,0x2 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11bb: je     11e0 <bpf_local_call_fanout_dispatch_xdp+0xe0> [bpf-branch: lowered cmp    rbx,0x2 + je     11e0 <bpf_local_call_fanout_dispatch_xdp+0xe0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 6, 2),
    /* 0x11bd: cmp    ebx,0x1 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 1), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11c0: je     1170 <bpf_local_call_fanout_dispatch_xdp+0x70> [bpf-branch: lowered cmp    ebx,0x1 + je     1170 <bpf_local_call_fanout_dispatch_xdp+0x70> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, -30, 1),
    /* 0x11c2: test   ebx,ebx [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x11c4: jne    11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11c6: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x11ca: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp] */
    /* 0x11cc: call   1210 <local_call_linear> [warning-unmapped: unsupported mnemonic or operand form: call   1210 <local_call_linear>] */
    /* 0x11d1: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -33, 0),
    /* 0x11d3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11e0: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x11e4: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp] */
    /* 0x11e6: call   12b0 <local_call_crossload> [warning-unmapped: unsupported mnemonic or operand form: call   12b0 <local_call_crossload>] */
    /* 0x11eb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -34, 0),
    /* 0x11ed: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: mov    rsi,QWORD PTR [rsp] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x11f4: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp] */
    /* 0x11f6: call   1340 <local_call_bytes> [warning-unmapped: unsupported mnemonic or operand form: call   1340 <local_call_bytes>] */
    /* 0x11fb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -35, 0),
    /* 0x1200: mov    QWORD PTR [r14],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, BPF_REG_8, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1203: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1208: jmp    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -57, 0),
};

HC_EXPORT_PROGRAM(program)
