#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 0),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, HC_X86_RDX, BPF_REG_1, 4),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RDX, HC_X86_SHADOW_RDX_OFF),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: ja     1130 <simple_packet_xdp+0x30> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (16) - 1, 0),
    /* 0x110e: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1112: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1115: ja     1130 <simple_packet_xdp+0x30> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (11) - 1, 0),
    /* 0x1117: mov    WORD PTR [rcx],0x614e [exact-kinsn: mov immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(HC_X86_RCX, 0, 24910), MICRO_HANDCRAFT_BPF_X86_MOVW),
    /* 0x111c: mov    BYTE PTR [rcx+0x2],0xbc [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(HC_X86_RCX, 2, 188), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1120: mov    DWORD PTR [rcx+0x3],0x0 [exact-kinsn: mov immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(HC_X86_RCX, 3, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1127: mov    BYTE PTR [rcx+0x7],0x0 [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(HC_X86_RCX, 7, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x112b: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1130: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
