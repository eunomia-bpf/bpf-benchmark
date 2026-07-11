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
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, HC_X86_RDX, BPF_REG_1, 0),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RDX, HC_X86_SHADOW_RDX_OFF),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 4),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <packet_checksum_fold_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <packet_checksum_fold_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rsi,[rdx+0x410] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <packet_checksum_fold_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: jne    110e <packet_checksum_fold_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 32),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x200 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1131: jne    110e <packet_checksum_fold_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 512),
    /* 0x1133: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1135: xor    esi,esi [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1137: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: mov    ecx,0x13 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1145: xor    edi,edi [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1147: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: movzx  r8d,WORD PTR [rdx+rcx*1-0x3] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_R8, HC_X86_RDX, HC_X86_RCX, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1156: add    r8d,edi [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1159: movzx  edi,r8w [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x115d: shr    r8d,0x10 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1161: add    r8d,edi [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1164: movzx  edi,WORD PTR [rdx+rcx*1-0x1] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RDX, HC_X86_RCX, 0, -1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1169: add    edi,r8d [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x116c: movzx  r8d,di [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1170: shr    edi,0x10 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1173: add    edi,r8d [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1176: add    rcx,0x4 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117a: cmp    rcx,0x413 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1181: jne    1150 <packet_checksum_fold_xdp+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-23) - 1, 1043),
    /* 0x1183: mov    ecx,edi [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1185: shr    ecx,0x10 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1188: add    ecx,edi [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x118a: not    ecx [exact-kop: not32 reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_NOTL),
    /* 0x118c: movzx  edi,cx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x118f: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1191: shl    ecx,0x4 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1194: shl    rdi,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1197: xor    rsi,rdi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x119a: inc    eax [exact-kop: incl reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x119c: cmp    eax,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x119f: jne    1140 <packet_checksum_fold_xdp+0x40> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-49) - 1, 32),
    /* 0x11a1: mov    QWORD PTR [rdx],rsi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a4: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a9: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
