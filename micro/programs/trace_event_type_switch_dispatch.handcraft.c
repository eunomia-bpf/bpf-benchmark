#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 3
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1133: lea    rdi,[rip+0xec6] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xec6]]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: jbe    110f <trace_event_type_switch_dispatch_xdp+0xf> [exact-kinsn: jbe branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(3, 1, 0), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-5, -10, 0), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1118: lea    rdi,[rcx+0x20c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 524), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-11, -22, 0), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1124: cmp    DWORD PTR [rsi],0x80 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 0, 128), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x112a: jne    110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-15, -30, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x112c: mov    esi,0xf [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1131: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1133: lea    rdi,[rip+0xec6] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xec6]] */
    /* 0x113a: jmp    1150 <trace_event_type_switch_dispatch_xdp+0x50> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(10, 20, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x113c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1143: add    rsi,0x4 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1147: cmp    rsi,0x20f [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 527), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x114e: je     116c <trace_event_type_switch_dispatch_xdp+0x6c> [exact-kinsn: je branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(18, 28, 0), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x1150: mov    rax,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1153: mov    r8d,DWORD PTR [rcx+rsi*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_5, BPF_REG_4, BPF_REG_2, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1158: mov    edx,0x1bf52 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 114514), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x115d: cmp    r8d,0x3f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 63), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1161: ja     1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-kinsn: ja branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-16, -35, 0), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1163: mov    edx,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1166: mov    rdx,QWORD PTR [rdi+rdx*8] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_3, BPF_REG_1, BPF_REG_3, 3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x116a: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-22, -44, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x116c: mov    BYTE PTR [rcx],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x116e: mov    BYTE PTR [rcx+0x1],dh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_3, BPF_REG_4, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1171: shr    edx,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1174: mov    BYTE PTR [rcx+0x2],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1177: mov    edx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1179: shr    edx,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x117c: mov    BYTE PTR [rcx+0x3],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x117f: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1182: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1186: mov    BYTE PTR [rcx+0x4],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1189: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x118c: shr    rdx,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1190: mov    BYTE PTR [rcx+0x5],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1193: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1196: shr    rdx,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x119a: mov    BYTE PTR [rcx+0x6],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x119d: shr    rax,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11a1: mov    BYTE PTR [rcx+0x7],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11a4: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a9: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
