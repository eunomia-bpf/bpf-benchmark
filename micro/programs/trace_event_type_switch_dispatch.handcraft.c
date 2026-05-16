#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (((__u64)(DST) << 4) | ((__u64)(BASE) << 8) | ((__u64)(INDEX) << 12) | \
     ((__u64)(SCALE) << 16) | ((__u64)(HAS_INDEX) << 18) | \
     ((__u64)(HAS_BASE) << 19) | ((__u64)(__u32)(DISP) << 20))
#define HC_LEA_TMP_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP, TMP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | \
     (__u64)(TMP))

/*
 * native asm to handcraft warnings: 4
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rsi],0x80 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rsi],0x80]
 * - 0x1133: lea    rdi,[rip+0xec6] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xec6]]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <trace_event_type_switch_dispatch_xdp+0xf> [bpf-branch: lowered cmp    rcx,rdx + jbe    110f <trace_event_type_switch_dispatch_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_4, BPF_REG_3, 2),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_TMP_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [bpf-branch: lowered cmp    rsi,rdx + ja     110e <trace_event_type_switch_dispatch_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, -6),
    /* 0x1118: lea    rdi,[rcx+0x20c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_TMP_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 524, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [bpf-branch: lowered cmp    rdi,rdx + ja     110e <trace_event_type_switch_dispatch_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_3, -11),
    /* 0x1124: cmp    DWORD PTR [rsi],0x80 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rsi],0x80] */
    /* 0x112a: jne    110e <trace_event_type_switch_dispatch_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi],0x80 + jne    110e <trace_event_type_switch_dispatch_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 128),
    /* 0x112c: mov    esi,0xf [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 15),
    /* 0x1131: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1133: lea    rdi,[rip+0xec6] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xec6]] */
    /* 0x113a: jmp    1150 <trace_event_type_switch_dispatch_xdp+0x50> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 8, 0),
    /* 0x113c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1143: add    rsi,0x4 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 4, 0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1147: cmp    rsi,0x20f [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 527), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x114e: je     116c <trace_event_type_switch_dispatch_xdp+0x6c> [bpf-branch: lowered cmp    rsi,0x20f + je     116c <trace_event_type_switch_dispatch_xdp+0x6c> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_2, 0, 14, 527),
    /* 0x1150: mov    rax,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1153: mov    r8d,DWORD PTR [rcx+rsi*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_5, BPF_REG_4, BPF_REG_2, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_SIB),
    /* 0x1158: mov    edx,0x1bf52 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 114514),
    /* 0x115d: cmp    r8d,0x3f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 63), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1161: ja     1140 <trace_event_type_switch_dispatch_xdp+0x40> [bpf-branch: lowered cmp    r8d,0x3f + ja     1140 <trace_event_type_switch_dispatch_xdp+0x40> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_5, 0, -14, 63),
    /* 0x1163: mov    edx,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1166: mov    rdx,QWORD PTR [rdi+rdx*8] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_3, BPF_REG_1, BPF_REG_3, 3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_SIB),
    /* 0x116a: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -19, 0),
    /* 0x116c: mov    BYTE PTR [rcx],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x116e: mov    BYTE PTR [rcx+0x1],dh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 1), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1171: shr    edx,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 16, 0), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1174: mov    BYTE PTR [rcx+0x2],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1177: mov    edx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1179: shr    edx,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24, 0), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x117c: mov    BYTE PTR [rcx+0x3],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x117f: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1182: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32, 0), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1186: mov    BYTE PTR [rcx+0x4],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1189: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x118c: shr    rdx,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 40, 0), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1190: mov    BYTE PTR [rcx+0x5],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1193: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1196: shr    rdx,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 48, 0), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x119a: mov    BYTE PTR [rcx+0x6],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x119d: shr    rax,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 56, 0), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11a1: mov    BYTE PTR [rcx+0x7],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x11a4: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x11a9: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
