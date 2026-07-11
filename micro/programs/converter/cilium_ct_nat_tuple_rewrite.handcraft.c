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
    /* 0x110c: jbe    110f <cilium_ct_nat_tuple_rewrite_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rsi,[rdx+0x410] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 32),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112e: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 32),
    /* 0x1130: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r12 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1138: lea    rdi,[rdx+0x2f] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDI, HC_X86_RDX, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: movabs rsi,0x8ebc6af09c88c6e3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x8ebc6af09c88c6e3ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RSI_OFF),
    /* 0x1146: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1149: jmp    11d0 <cilium_ct_nat_tuple_rewrite_xdp+0xd0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (77) - 1, 0),
    /* 0x114e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1150: mov    r15d,ebp [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R15, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1153: mov    ebp,r12d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBP, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1156: mov    r12d,ebp [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R12, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1159: rol    r12d,0xb [exact-kop: roll imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(HC_X86_R12, HC_X86_R12, 11), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x115d: shl    r14d,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R14, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1161: xor    r14d,r12d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1164: movzx  r15d,r15w [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R15, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1168: shl    r10d,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x116c: or     ecx,r10d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x116f: xor    ecx,r15d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1172: xor    ecx,r14d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1175: xor    ecx,ebx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1177: shl    r11d,0x1d [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 29), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x117b: sar    r11d,0x1f [exact-kop: sar32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 31), MICRO_HANDCRAFT_BPF_X86_SARL),
    /* 0x117f: shl    r9d,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1183: xor    r9d,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1186: and    r9d,r11d [exact-kop: and32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1189: add    r9d,ecx [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x118c: shl    r9,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1190: mov    r10d,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1193: shl    rbx,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBX, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1197: mov    r11d,ebp [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119a: or     r11,rbx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x119d: mov    eax,r8d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a0: and    eax,0x7 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11a3: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11a6: mov    rbx,r11 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a9: shl    rbx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11ac: not    al [exact-kop: not8 reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x11ae: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b0: shr    r11,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11b3: add    rsi,r10 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b6: add    rsi,r9 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b9: or     r11,rbx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11bc: xor    rsi,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11bf: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11c2: add    rdi,0x20 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c6: cmp    r8,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ca: je     1261 <cilium_ct_nat_tuple_rewrite_xdp+0x161> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (70) - 1, 32),
    /* 0x11d0: movzx  r10d,BYTE PTR [rdi-0x13] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R10, HC_X86_RDI, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d5: movzx  r9d,WORD PTR [rdi-0x7] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R9, HC_X86_RDI, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11da: movzx  ecx,WORD PTR [rdi-0x5] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDI, -5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11de: mov    eax,DWORD PTR [rdi-0x3] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RDI, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e1: cmp    r10d,0x6 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11e5: je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (4) - 1, 6),
    /* 0x11e7: cmp    r10d,0x11 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11eb: jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (47) - 1, 17),
    /* 0x11ed: lea    rbx,[rdi-0xb] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RBX, HC_X86_RDI, 0, 0, 1, 0, -11), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11f1: lea    r14,[rdi-0xf] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_R14, HC_X86_RDI, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11f5: movzx  r11d,BYTE PTR [rdi-0x11] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -17), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11fa: lea    r15,[rdi-0x1b] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_R15, HC_X86_RDI, 0, 0, 1, 0, -27), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11fe: lea    r12,[rdi-0x1f] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_R12, HC_X86_RDI, 0, 0, 1, 0, -31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1202: mov    ebp,r11d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBP, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1205: and    ebp,0x1 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBP, 1), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1208: cmovne ebp,r9d [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_PAYLOAD(HC_X86_RBP, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMOVNEL),
    /* 0x120c: cmovne r12,r14 [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_PAYLOAD(HC_X86_R12, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1210: xor    bp,WORD PTR [rdi-0x17] [exact-kop: xorw memory-source kop] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RDI, -23), MICRO_HANDCRAFT_BPF_X86_XORW),
    /* 0x1214: mov    r14d,r11d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1217: and    r14d,0x2 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R14, 2), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x121b: cmovne r14d,r9d [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_PAYLOAD(HC_X86_R14, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMOVNEL),
    /* 0x121f: cmovne r15,rbx [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_PAYLOAD(HC_X86_R15, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1223: xor    r14w,WORD PTR [rdi-0x15] [exact-kop: xorw memory-source kop] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -21), MICRO_HANDCRAFT_BPF_X86_XORW),
    /* 0x1228: mov    r12d,DWORD PTR [r12] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R12, HC_X86_R12, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122c: mov    ebx,DWORD PTR [r15] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RBX, HC_X86_R15, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122f: test   BYTE PTR [rdi-0x12],0x1 [control-flow-operand: test folded into BPF branch] */
    /* 0x1233: jne    1150 <cilium_ct_nat_tuple_rewrite_xdp+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDI),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -18),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, (-126) - 1, 1),
    /* 0x1239: mov    r15d,r14d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R15, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x123c: mov    r14d,ebp [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x123f: mov    ebp,ebx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBP, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1241: mov    ebx,r12d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1244: jmp    1156 <cilium_ct_nat_tuple_rewrite_xdp+0x56> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-131) - 1, 0),
    /* 0x1249: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: shl    r10,0x38 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1254: mov    eax,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1256: or     rax,r10 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1259: xor    rsi,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x125c: jmp    11bf <cilium_ct_nat_tuple_rewrite_xdp+0xbf> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-74) - 1, 0),
    /* 0x1261: mov    QWORD PTR [rdx],rsi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1264: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1269: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126a: pop    r12 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126c: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126e: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1270: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1271: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
