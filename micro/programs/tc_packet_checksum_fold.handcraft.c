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
    /* 0x1100: mov    rax,QWORD PTR [rdi] [context-abi: native skb shim field at off 0 maps to __sk_buff u32 ctx field at off 76] */
    HC_LDX(BPF_W, HC_X86_RAX, BPF_REG_1, 76),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RAX, HC_X86_SHADOW_RAX_OFF),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native skb shim field at off 8 maps to __sk_buff u32 ctx field at off 80] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 80),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1107: cmp    rax,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110a: jbe    1121 <tc_packet_checksum_fold_prog+0x21> [exact-bpf: jbe as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (10) - 1, 0),
    /* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff [context-abi: native skb shim cb store at off 16 maps to __sk_buff cb field at off 48] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(HC_X86_RDI, 48, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1113: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1118: mov    edx,0xffffffff [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDX, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111d: mov    DWORD PTR [rdi+0x14],edx [context-abi: native skb shim cb store at off 20 maps to __sk_buff cb field at off 52] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1120: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x1121: lea    rdx,[rax+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1125: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: ja     110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-13) - 1, 0),
    /* 0x112a: lea    rdx,[rax+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1131: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1134: ja     110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-18) - 1, 0),
    /* 0x1136: cmp    DWORD PTR [rax+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x113a: jne    110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-21) - 1, 32),
    /* 0x113c: cmp    DWORD PTR [rax+0xc],0x200 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1143: jne    110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-24) - 1, 512),
    /* 0x1145: xor    esi,esi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1147: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1149: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: xor    ecx,ecx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1152: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1155: data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: movzx  r9d,WORD PTR [rax+rcx*2+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R9, HC_X86_RAX, HC_X86_RCX, 1, 16), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1166: add    r9d,r8d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1169: movzx  r8d,r9w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x116d: shr    r9d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1171: add    r9d,r8d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1174: movzx  r8d,WORD PTR [rax+rcx*2+0x12] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R8, HC_X86_RAX, HC_X86_RCX, 1, 18), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x117a: add    r8d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x117d: movzx  r9d,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1181: shr    r8d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1185: add    r8d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1188: add    rcx,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x118c: cmp    rcx,0x200 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1193: jne    1160 <tc_packet_checksum_fold_prog+0x60> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-23) - 1, 512),
    /* 0x1195: mov    ecx,r8d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: shr    ecx,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x119b: add    ecx,r8d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x119e: not    ecx [exact-kinsn: not32 reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_NOTL),
    /* 0x11a0: movzx  r8d,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a4: mov    ecx,esi [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a6: shl    ecx,0x4 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11a9: shl    r8,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11ac: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11af: inc    esi [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RSI, 0), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x11b1: cmp    esi,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b4: jne    1150 <tc_packet_checksum_fold_prog+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-49) - 1, 32),
    /* 0x11b6: mov    DWORD PTR [rdi+0x10],edx [context-abi: native skb shim cb store at off 16 maps to __sk_buff cb field at off 48] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 48), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b9: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11bd: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bf: mov    DWORD PTR [rdi+0x14],edx [context-abi: native skb shim cb store at off 20 maps to __sk_buff cb field at off 52] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c2: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
