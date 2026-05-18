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
    /* 0x110c: jbe    110f <sorted_rule_binary_search_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rsi,[rcx+0x190] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rcx+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: jne    110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 32),
    /* 0x112a: cmp    DWORD PTR [rcx+0xc],0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112e: jne    110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 16),
    /* 0x1130: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1132: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1134: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: mov    rsi,QWORD PTR [rcx+rax*8+0x110] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RCX, HC_X86_RAX, 3, 272), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1148: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114b: xor    edi,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114d: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1150: mov    r10d,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1153: mov    r11,rdi [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1156: cmp    QWORD PTR [rcx+r8*8+0x10],rsi [exact-kinsn: cmpq SIB memory-source kinsn] */
    HC_KINSN(HC_X86_CMP_SIB_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8, 3, 16, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x115b: sete   r9b [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SETE),
    /* 0x115f: cmove  rdi,r8 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_CMOVEQ),
    /* 0x1163: or     r9b,r10b [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1166: test   r10b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x116a: cmovne rdi,r11 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_PAYLOAD(HC_X86_RDI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x116e: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1171: cmp    r8,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1175: jne    1150 <sorted_rule_binary_search_xdp+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_R8_OFF),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-19) - 1, 32),
    /* 0x1177: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117a: add    rsi,0x20 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSI, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117e: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1181: test   r9b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1185: cmovne rdx,rdi [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1189: inc    rax [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x118c: cmp    rax,0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1190: jne    1140 <sorted_rule_binary_search_xdp+0x40> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-41) - 1, 16),
    /* 0x1192: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1195: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119a: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
