#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 4
 *
 * - 0x1176: call   1260 <local_call_pressure> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x1260 is outside parsed asm]
 * - 0x11cc: call   1210 <local_call_linear> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x1210 is outside parsed asm]
 * - 0x11e6: call   12b0 <local_call_crossload> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x12b0 is outside parsed asm]
 * - 0x11f6: call   1340 <local_call_bytes> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x1340 is outside parsed asm]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1101: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1103: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1105: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1107: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1109: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110a: push   rax [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110b: mov    r14,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_8, BPF_REG_1, 0),
    /* 0x110e: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1112: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1114: cmp    r14,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1117: jbe    1128 <bpf_local_call_fanout_dispatch_xdp+0x28> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(43, 15, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x1119: add    rsp,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x111d: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x111e: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1120: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1122: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1124: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1126: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1127: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x1128: lea    rdx,[r14+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_8, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112c: mov    QWORD PTR [rsp],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1130: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1133: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-56, -28, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1135: lea    rdx,[r14+0x190] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_8, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x113f: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-89, -40, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1141: cmp    DWORD PTR [r14+0x8],0x10 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_8, 8, 16), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1146: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-119, -47, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1148: cmp    DWORD PTR [r14+0xc],0x18 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_8, 12, 24), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x114d: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-148, -54, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x114f: movabs rdi,0x243f6a8885a308d3 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 2611923443488327891ULL),
    /* 0x1159: xor    r15d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115c: mov    r12d,0x17 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R12, 23), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1162: xor    r13d,r13d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1165: jmp    11a1 <bpf_local_call_fanout_dispatch_xdp+0xa1> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(79, 58, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1167: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1170: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1174: mov    ecx,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1176: call   1260 <local_call_pressure> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x1260 is outside parsed asm] */
    /* 0x117b: mov    ecx,r13d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117e: and    cl,0x38 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1181: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1184: mov    edi,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_1, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
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
    /* 0x119f: je     1200 <bpf_local_call_fanout_dispatch_xdp+0x100> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(191, 95, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x11a1: movzx  ebx,BYTE PTR [r14+r12*1-0x7] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_8, HC_X86_R12, 0, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a7: and    ebx,0x3 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 3), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11aa: mov    ebp,DWORD PTR [r14+r12*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RBP, BPF_REG_8, HC_X86_R12, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11af: xor    ebp,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11b2: lea    rdx,[r12-0xf] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, HC_X86_R12, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11b7: cmp    rbx,0x2 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11bb: je     11e0 <bpf_local_call_fanout_dispatch_xdp+0xe0> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(88, 35, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x11bd: cmp    ebx,0x1 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 1), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11c0: je     1170 <bpf_local_call_fanout_dispatch_xdp+0x70> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-162, -82, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x11c2: test   ebx,ebx [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x11c4: jne    11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(49, 42, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11c6: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11ca: mov    ecx,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11cc: call   1210 <local_call_linear> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x1210 is outside parsed asm] */
    /* 0x11d1: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-201, -88, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x11d3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11e0: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11e4: mov    ecx,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e6: call   12b0 <local_call_crossload> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x12b0 is outside parsed asm] */
    /* 0x11eb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-219, -114, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x11ed: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11f4: mov    ecx,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f6: call   1340 <local_call_bytes> [warning-unmapped: native direct call maps to BPF pseudo call; branch target 0x1340 is outside parsed asm] */
    /* 0x11fb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-237, -133, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1200: mov    QWORD PTR [r14],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, BPF_REG_8, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1203: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1208: jmp    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-438, -244, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
};

HC_EXPORT_PROGRAM(program)
