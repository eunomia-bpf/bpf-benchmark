#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 32
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x18]
 * - 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to BPF branch]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x18]
 * - 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to BPF branch]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1148: movabs r11,0x589965cc75374cc3 [warning-unmapped: movabs into HC_X86_R11 needs an immediate-load kinsn]
 * - 0x118f: cmp    r14w,0x3 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r14w,0x3]
 * - 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: cannot lower cmp    r12d,0x2001 + jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> to BPF branch]
 * - 0x11b0: movzx  ebp,WORD PTR [rsi-0x7] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11bc: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11c3: mov    r10d,0x8 [warning-unmapped: movl immediate into HC_X86_R10 needs an immediate-load kinsn]
 * - 0x11c9: cmove  r13d,r10d [warning-unmapped: cmove needs an adjacent test/cmp proof payload]
 * - 0x11d4: lea    r10,[rip+0xe25] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xe25]]
 * - 0x11db: or     rbx,QWORD PTR [r10+r14*8] [warning-unmapped: ALU memory source form has no current selector: or     rbx,QWORD PTR [r10+r14*8]]
 * - 0x11eb: test   bpl,0x2 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11ef: je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1203: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x120d: cmovne r14,rbx [warning-unmapped: cmovne needs an adjacent test/cmp proof payload]
 * - 0x122f: movzx  eax,bp [warning-unmapped: movzx source size not recognized: bp]
 * - 0x1249: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124c: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124e: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1250: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1252: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 2),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x250] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 592), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x18] */
    /* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to BPF branch] */
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x18] */
    /* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to BPF branch] */
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
    /* 0x1148: movabs r11,0x589965cc75374cc3 [warning-unmapped: movabs into HC_X86_R11 needs an immediate-load kinsn] */
    /* 0x1152: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1155: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 14, 0),
    /* 0x1157: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: shl    r14,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1164: or     r14,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1167: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x116a: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x116d: add    rsi,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1171: cmp    r8,0x18 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 24), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1175: je     1241 <otel_stack_frame_unwind_scan_xdp+0x141> [bpf-branch: lowered cmp    r8,0x18 + je     1241 <otel_stack_frame_unwind_scan_xdp+0x141> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 79, 24),
    /* 0x117b: mov    rax,QWORD PTR [rsi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_2, -23), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x117f: movzx  ecx,BYTE PTR [rsi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1183: movzx  r14d,BYTE PTR [rsi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_2, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1188: shl    r14d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x118c: or     r14,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x118f: cmp    r14w,0x3 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r14w,0x3] */
    /* 0x1194: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: lowered cmp    r14w,0x3 + ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_8, 0, -23, 3),
    /* 0x1196: mov    r15d,DWORD PTR [rsi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -15), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x119a: cmp    r15d,0x1000 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 4096), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a1: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: lowered cmp    r15d,0x1000 + ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_9, 0, -28, 4096),
    /* 0x11a3: mov    r12d,DWORD PTR [rsi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R12, BPF_REG_2, -11), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11a7: cmp    r12d,0x2001 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R12, 8193), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: cannot lower cmp    r12d,0x2001 + jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> to BPF branch] */
    /* 0x11b0: movzx  ebp,WORD PTR [rsi-0x7] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11b4: mov    r9d,DWORD PTR [rsi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R9, BPF_REG_2, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11b8: movzx  r14d,r14w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11bc: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11c0: mov    r13d,r12d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_7, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x11c3: mov    r10d,0x8 [warning-unmapped: movl immediate into HC_X86_R10 needs an immediate-load kinsn] */
    /* 0x11c9: cmove  r13d,r10d [warning-unmapped: cmove needs an adjacent test/cmp proof payload] */
    /* 0x11cd: mov    rbx,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11d0: shl    rbx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11d4: lea    r10,[rip+0xe25] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xe25]] */
    /* 0x11db: or     rbx,QWORD PTR [r10+r14*8] [warning-unmapped: ALU memory source form has no current selector: or     rbx,QWORD PTR [r10+r14*8]] */
    /* 0x11df: add    r13d,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11e2: add    rdi,r13 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11e5: xor    rax,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11e8: xor    rax,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11eb: test   bpl,0x2 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11ef: je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11f1: inc    ecx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x11f3: rol    rax,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLQ_CL),
    /* 0x11f6: mov    ecx,r12d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x11f9: shl    rcx,0x18 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11fd: mov    ebx,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1200: xor    rbx,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1203: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x1207: mov    r14d,0x0 [exact-kinsn: movl zero via xorl reg,reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x120d: cmovne r14,rbx [warning-unmapped: cmovne needs an adjacent test/cmp proof payload] */
    /* 0x1211: add    r14,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1214: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1217: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1219: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x121c: mov    rbx,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x121f: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1222: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1224: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1226: shr    r14,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x1229: or     r14,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x122c: add    r14,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x122f: movzx  eax,bp [warning-unmapped: movzx source size not recognized: bp] */
    /* 0x1232: shl    rax,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1236: or     r9,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1239: mov    r11,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x123c: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -86, 0),
    /* 0x1241: mov    QWORD PTR [rdx],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R11, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
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
