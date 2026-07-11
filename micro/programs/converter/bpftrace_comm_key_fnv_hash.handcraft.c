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
    /* 0x1100: mov    r8,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, HC_X86_R8, BPF_REG_1, 0),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_R8, HC_X86_SHADOW_R8_OFF),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 4),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    r8,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rdx,[r8+0x410] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1129: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 32),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1130: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 32),
    /* 0x1132: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r13 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R13, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   r12 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113b: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113c: sub    rsp,0x48 [exact-kop: sub64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 72), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x1140: mov    QWORD PTR [rsp+0x8],r8 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_R8, HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1145: lea    rdi,[r8+0x2f] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDI, HC_X86_R8, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1149: movabs rsi,0x94d049bb133111eb [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x94d049bb133111ebULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RSI_OFF),
    /* 0x1153: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1156: movabs r10,0x100000001b3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x100000001b3ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R10_OFF),
    /* 0x1160: jmp    11bf <bpftrace_comm_key_fnv_hash_xdp+0xbf> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (49) - 1, 0),
    /* 0x1162: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1170: shl    r12d,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1174: shl    r15d,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R15, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1178: or     r15d,r12d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R15, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x117b: shl    ebx,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBX, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x117e: mov    eax,r8d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1181: and    al,0x7 [exact-kop: andb imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1183: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1186: mov    rdx,r11 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1189: shl    rdx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x118c: not    al [exact-kop: not8 reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x118e: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1190: shr    r11,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1193: or     ebx,r15d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1196: or     ebx,r9d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1199: or     r11,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x119c: mov    rax,rsi [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x119f: xor    rax,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11a2: shl    r14,0x38 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R14, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11a6: mov    esi,ebx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a8: or     rsi,r14 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11ab: add    rsi,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ae: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11b1: add    rdi,0x20 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b5: cmp    r8,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b9: je     13e9 <bpftrace_comm_key_fnv_hash_xdp+0x2e9> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (279) - 1, 32),
    /* 0x11bf: mov    QWORD PTR [rsp+0x40],r8 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_R8, HC_X86_RSP, 64), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11c4: movzx  r13d,BYTE PTR [rdi-0x1f] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R13, HC_X86_RDI, -31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c9: movzx  r9d,BYTE PTR [rdi-0x1e] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R9, HC_X86_RDI, -30), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ce: movzx  eax,BYTE PTR [rdi-0x1d] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RDI, -29), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d2: movzx  edx,BYTE PTR [rdi-0x1c] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RDI, -28), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d6: movzx  ebp,BYTE PTR [rdi-0x1b] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RDI, -27), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11da: movzx  ecx,BYTE PTR [rdi-0x1a] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDI, -26), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11de: mov    QWORD PTR [rsp+0x38],rcx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RCX, HC_X86_RSP, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11e3: movzx  ecx,BYTE PTR [rdi-0x19] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDI, -25), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e7: mov    QWORD PTR [rsp+0x30],rcx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RCX, HC_X86_RSP, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11ec: movzx  r8d,BYTE PTR [rdi-0x18] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R8, HC_X86_RDI, -24), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f1: movzx  r14d,BYTE PTR [rdi-0x17] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f6: movzx  r12d,BYTE PTR [rdi-0x16] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R12, HC_X86_RDI, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11fb: movzx  r15d,BYTE PTR [rdi-0x15] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R15, HC_X86_RDI, -21), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1200: movzx  ebx,BYTE PTR [rdi-0x14] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RBX, HC_X86_RDI, -20), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1204: mov    r11,r13 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1207: movabs rcx,0xcbf29ce484222325 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xcbf29ce484222325ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x1211: xor    r11,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1214: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1218: mov    QWORD PTR [rsp+0x10],r9 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_R9, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x121d: xor    r11,r9 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1220: mov    r9,r8 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1223: mov    r8,QWORD PTR [rsp+0x30] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R8, HC_X86_RSP, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1228: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x122c: mov    QWORD PTR [rsp+0x20],rax [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RSP, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1231: xor    r11,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1234: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1238: mov    QWORD PTR [rsp+0x18],rdx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x123d: xor    r11,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1240: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1244: mov    QWORD PTR [rsp+0x28],rbp [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RBP, HC_X86_RSP, 40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1249: xor    r11,rbp [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x124c: mov    rbp,QWORD PTR [rsp+0x38] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RSP, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1251: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1255: xor    r11,rbp [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1258: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x125c: xor    r11,r8 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x125f: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1263: xor    r11,r9 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1266: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x126a: mov    QWORD PTR [rsp],r14 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_R14, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x126e: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1271: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1275: xor    r11,r12 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1278: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x127c: xor    r11,r15 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x127f: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1283: mov    r14,rbx [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1286: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1289: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x128d: movzx  r11d,BYTE PTR [rdi-0xf] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1292: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1295: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1299: movzx  r14d,BYTE PTR [rdi-0xe] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x129e: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12a1: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12a5: movzx  r11d,BYTE PTR [rdi-0xd] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12aa: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ad: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12b1: movzx  r14d,BYTE PTR [rdi-0xc] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12b6: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12b9: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12bd: movzx  r11d,BYTE PTR [rdi-0xb] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12c2: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12c5: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12c9: movzx  r14d,BYTE PTR [rdi-0xa] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ce: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12d1: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12d5: movzx  r11d,BYTE PTR [rdi-0x9] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12da: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12dd: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12e1: movzx  r14d,BYTE PTR [rdi-0x8] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e6: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12e9: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ed: movzx  r11d,BYTE PTR [rdi-0x7] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f2: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12f5: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12f9: movzx  r14d,BYTE PTR [rdi-0x6] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12fe: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1301: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1305: movzx  r11d,BYTE PTR [rdi-0x5] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x130a: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x130d: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1311: movzx  r14d,BYTE PTR [rdi-0x4] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1316: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1319: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x131d: movzx  r11d,BYTE PTR [rdi-0x3] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1322: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1325: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1329: movzx  r14d,BYTE PTR [rdi-0x2] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x132e: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1331: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1335: movzx  ecx,BYTE PTR [rdi-0x1] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDI, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1339: xor    rcx,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x133c: imul   rcx,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1340: movzx  r11d,BYTE PTR [rdi] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1344: xor    r11,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1347: movzx  r14d,BYTE PTR [rdi-0x13] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x134c: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1350: test   r14b,0x1 [control-flow-operand: test folded into BPF branch] */
    /* 0x1354: jne    1360 <bpftrace_comm_key_fnv_hash_xdp+0x260> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, (4) - 1, 1),
    /* 0x1356: mov    r9,QWORD PTR [rsp] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x135a: jmp    13c0 <bpftrace_comm_key_fnv_hash_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (57) - 1, 0),
    /* 0x135c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1360: shl    r9d,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1364: shl    r8d,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1368: shl    ebp,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x136b: mov    rax,QWORD PTR [rsp+0x20] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RSP, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1370: shl    rax,0x30 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1374: mov    rcx,QWORD PTR [rsp+0x18] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1379: shl    rcx,0x38 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x137d: mov    rdx,QWORD PTR [rsp+0x10] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1382: shl    rdx,0x28 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1386: shl    r13,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R13, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x138a: or     r13,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x138d: or     r13,rax [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1390: or     r13,rcx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1393: or     r13,rbp [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1396: or     r13,r8 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1399: or     r13,r9 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x139c: or     r13,QWORD PTR [rsp+0x28] [exact-kop: or64 memory-source kop] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R13, HC_X86_RSP, 40), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13a1: mov    r9,QWORD PTR [rsp] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13a5: mov    eax,r9d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13a8: and    al,0x7 [exact-kop: andb imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x13aa: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13ad: mov    rdx,r13 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13b0: shl    rdx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13b3: not    al [exact-kop: not8 reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13b5: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13b7: shr    r13,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13ba: or     r13,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13bd: xor    r11,r13 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c0: test   r14b,0x2 [exact-kop: testb imm kop; branch operands snapshotted] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R14, 2), MICRO_HANDCRAFT_BPF_X86_TESTB),
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_BRANCH_LHS_OFF),
    /* 0x13c4: mov    r8,QWORD PTR [rsp+0x40] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R8, HC_X86_RSP, 64), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13c9: je     1170 <bpftrace_comm_key_fnv_hash_xdp+0x70> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (-315) - 1, 0),
    /* 0x13cf: movabs rax,0x9e3779b185ebca87 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b185ebca87ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RAX_OFF),
    /* 0x13d9: add    rax,r11 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13dc: cmp    BYTE PTR [rdi-0xf],0x70 [exact-kop: cmp memory,imm kop] */
    HC_KOP(HC_X86_CMP_MEM_IMM_PAYLOAD(HC_X86_RDI, -15, 112), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x13e0: cmove  r11,rax [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_PAYLOAD(HC_X86_R11, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_CMOVEQ),
    /* 0x13e4: jmp    1170 <bpftrace_comm_key_fnv_hash_xdp+0x70> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-325) - 1, 0),
    /* 0x13e9: mov    rax,QWORD PTR [rsp+0x8] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ee: mov    QWORD PTR [rax],rsi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RSI, HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13f1: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13f6: add    rsp,0x48 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 72), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13fa: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13fb: pop    r12 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13fd: pop    r13 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R13, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13ff: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1401: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1403: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1404: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
