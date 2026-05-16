#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 22
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1134: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1136: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1138: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113a: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113c: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x114f: movabs r11,0x589965cc75374cc3 [warning-unmapped: movabs into HC_X86_R11 needs an immediate-load kinsn]
 * - 0x118f: cmp    r15w,0x3 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r15w,0x3]
 * - 0x1194: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11d7: lea    rdi,[rip+0xe22] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xe22]]
 * - 0x11f5: je     11fc <otel_stack_frame_unwind_scan_xdp+0xfc> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1254: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1255: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1257: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1259: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x125b: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x125d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> [bpf-branch: verifier-visible branch from preceding cmp    rdx,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, 1, 0),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, -6, 0),
    /* 0x1118: lea    rsi,[rdx+0x250] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 592), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, -11, 0),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x18 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_3, 8, 24), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_3, 12, 24), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1134: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1136: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1138: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113a: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113c: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113d: mov    QWORD PTR [rbp-0x30],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, HC_X86_RBP_STACK_BASE, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1141: lea    rsi,[rdx+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1145: movabs rdi,0x100000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x100000000ULL),
    /* 0x114f: movabs r11,0x589965cc75374cc3 [warning-unmapped: movabs into HC_X86_R11 needs an immediate-load kinsn] */
    /* 0x1159: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115c: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 13, 0),
    /* 0x115e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1160: shl    r15,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1164: or     r15,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1167: xor    r11,r15 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x116a: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x116d: add    rsi,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1171: cmp    r8,0x18 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 24), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1175: je     1248 <otel_stack_frame_unwind_scan_xdp+0x148> [bpf-branch: verifier-visible branch from preceding cmp    r8,0x18; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 102, 24),
    /* 0x117b: mov    rax,QWORD PTR [rsi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_2, -23), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x117f: movzx  ecx,BYTE PTR [rsi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1183: movzx  r15d,BYTE PTR [rsi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1188: shl    r15d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x118c: or     r15,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x118f: cmp    r15w,0x3 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r15w,0x3] */
    /* 0x1194: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1196: mov    r12d,DWORD PTR [rsi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R12, BPF_REG_2, -15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119a: cmp    r12d,0x1000 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R12, 4096), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11a1: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: verifier-visible branch from preceding cmp    r12d,0x1000; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, HC_X86_R12, 0, -28, 4096),
    /* 0x11a3: mov    r13d,DWORD PTR [rsi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_7, BPF_REG_2, -11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a7: cmp    r13d,0x2001 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_7, 8193), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: verifier-visible branch from preceding cmp    r13d,0x2001; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JGE | BPF_K, BPF_REG_7, 0, -33, 8193),
    /* 0x11b0: movzx  r14d,WORD PTR [rsi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_2, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b5: mov    r10d,DWORD PTR [rsi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_2, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b9: movzx  r15d,r15w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11bd: test   r14b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_8, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11c1: mov    r9d,r13d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c4: mov    edx,0x8 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c9: cmove  r9d,edx [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R9, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMOVEL),
    /* 0x11cd: mov    rbx,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11d0: shl    rbx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11d4: mov    rdx,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11d7: lea    rdi,[rip+0xe22] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xe22]] */
    /* 0x11de: or     rbx,QWORD PTR [rdi+r15*8] [exact-kinsn: or64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_1, BPF_REG_9, 3, 0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e2: mov    rdi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11e5: add    r9d,r12d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11e8: add    rdi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11eb: xor    rax,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11ee: xor    rax,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11f1: test   r14b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11f5: je     11fc <otel_stack_frame_unwind_scan_xdp+0xfc> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11f7: inc    ecx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x11f9: rol    rax,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11fc: mov    ecx,r13d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ff: shl    rcx,0x18 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1203: mov    r9d,r12d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1206: xor    r9,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1209: test   r14b,0x4 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_8, 4), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x120d: mov    r15d,0x0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_9, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1213: cmovne r15,r9 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1217: add    r15,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x121a: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x121d: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x121f: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1222: mov    r9,r15 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1225: shl    r9,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1228: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x122a: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122c: shr    r15,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x122f: or     r15,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1232: add    r15,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1235: movzx  eax,r14w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1239: shl    rax,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x123d: or     r10,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1240: mov    r11,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1243: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -111, 0),
    /* 0x1248: mov    rax,QWORD PTR [rbp-0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RBP_STACK_BASE, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x124c: mov    QWORD PTR [rax],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x124f: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1254: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1255: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1257: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1259: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x125b: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x125d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x125e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
