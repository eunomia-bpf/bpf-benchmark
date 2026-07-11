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
    /* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rdi,[rdx+0x10c] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDI, HC_X86_RDX, 0, 0, 1, 0, 268), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 64),
    /* 0x1129: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112a: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112c: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112e: push   r13 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R13, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1130: push   r12 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: movabs r13,0x6a09e667f3bcc909 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6a09e667f3bcc909ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R13_OFF),
    /* 0x113d: movabs rsi,0x65736f6c63 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x65736f6c63ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RSI_OFF),
    /* 0x1147: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114a: lea    r9,[rsi+0xfa0614] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_RSI, 0, 0, 1, 0, 16385556), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1151: movabs r15,0x646461746567 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x646461746567ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R15_OFF),
    /* 0x115b: movabs r11,0x74616e65706f [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74616e65706fULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R11_OFF),
    /* 0x1165: movabs rbx,0x74616b6e696c6e75 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74616b6e696c6e75ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RBX_OFF),
    /* 0x116f: movabs r14,0x74613274617473 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74613274617473ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R14_OFF),
    /* 0x1179: movabs r12,0x647466656e676973 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x647466656e676973ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R12_OFF),
    /* 0x1183: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1190: movzx  edi,BYTE PTR [rdx+r8*4+0xc] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RDX, HC_X86_R8, 2, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1196: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_RCX, HC_X86_RDX, HC_X86_R8, 2, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x119c: shl    ecx,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x119f: or     ecx,edi [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11a1: movzx  eax,WORD PTR [rdx+r8*4+0xe] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_RAX, HC_X86_RDX, HC_X86_R8, 2, 14), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a7: shl    eax,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11aa: or     eax,ecx [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11ac: cmp    eax,0x4f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11af: jg     11f0 <tracee_syscall_name_table_lookup_xdp+0xf0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (15) - 1, 79),
    /* 0x11b1: cmp    eax,0x26 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b4: jg     1230 <tracee_syscall_name_table_lookup_xdp+0x130> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (27) - 1, 38),
    /* 0x11b6: cmp    eax,0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b9: jg     1294 <tracee_syscall_name_table_lookup_xdp+0x194> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (47) - 1, 2),
    /* 0x11bf: test   eax,eax [control-flow-operand: test folded into BPF branch] */
    /* 0x11c1: je     1378 <tracee_syscall_name_table_lookup_xdp+0x278> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, -1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (110) - 1, 0),
    /* 0x11c7: cmp    eax,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ca: je     1332 <tracee_syscall_name_table_lookup_xdp+0x232> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (81) - 1, 1),
    /* 0x11d0: cmp    eax,0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11d3: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (168) - 1, 2),
    /* 0x11d9: mov    ecx,0x6e65706f [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1852141679), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11de: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (126) - 1, 0),
    /* 0x11e3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: cmp    eax,0x100 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11f5: jg     1260 <tracee_syscall_name_table_lookup_xdp+0x160> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (24) - 1, 256),
    /* 0x11f7: cmp    eax,0x9d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11fc: jg     12bc <tracee_syscall_name_table_lookup_xdp+0x1bc> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (44) - 1, 157),
    /* 0x1202: cmp    eax,0x50 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1205: je     137f <tracee_syscall_name_table_lookup_xdp+0x27f> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (100) - 1, 80),
    /* 0x120b: cmp    eax,0x57 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x120e: je     133a <tracee_syscall_name_table_lookup_xdp+0x23a> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (71) - 1, 87),
    /* 0x1214: cmp    eax,0x59 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1217: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (155) - 1, 89),
    /* 0x121d: movabs rcx,0x6b6e696c55 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6b6e696c55ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x1227: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (112) - 1, 0),
    /* 0x122c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1230: cmp    eax,0x3a [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1233: jg     12e5 <tracee_syscall_name_table_lookup_xdp+0x1e5> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (41) - 1, 58),
    /* 0x1239: cmp    eax,0x27 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x123c: je     1386 <tracee_syscall_name_table_lookup_xdp+0x286> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (91) - 1, 39),
    /* 0x1242: cmp    eax,0x38 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1245: je     1346 <tracee_syscall_name_table_lookup_xdp+0x246> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (63) - 1, 56),
    /* 0x124b: cmp    eax,0x39 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x124e: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (143) - 1, 57),
    /* 0x1254: mov    ecx,0x6b726f66 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1802661734), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1259: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (101) - 1, 0),
    /* 0x125e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1260: cmp    eax,0x122 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1265: jg     130b <tracee_syscall_name_table_lookup_xdp+0x20b> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (40) - 1, 290),
    /* 0x126b: cmp    eax,0x101 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1270: je     1392 <tracee_syscall_name_table_lookup_xdp+0x292> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (84) - 1, 257),
    /* 0x1276: cmp    eax,0x107 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x127b: je     1352 <tracee_syscall_name_table_lookup_xdp+0x252> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (56) - 1, 263),
    /* 0x1281: cmp    eax,0x119 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1286: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (132) - 1, 281),
    /* 0x128c: mov    rcx,r14 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x128f: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (90) - 1, 0),
    /* 0x1294: mov    rcx,rsi [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1297: cmp    eax,0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x129a: je     13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (86) - 1, 3),
    /* 0x12a0: cmp    eax,0x9 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12a3: je     1357 <tracee_syscall_name_table_lookup_xdp+0x257> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (48) - 1, 9),
    /* 0x12a9: cmp    eax,0xc [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12ac: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (121) - 1, 12),
    /* 0x12b2: mov    ecx,0x6b72626b [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1802658411), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b7: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (79) - 1, 0),
    /* 0x12bc: cmp    eax,0x9e [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12c1: je     1397 <tracee_syscall_name_table_lookup_xdp+0x297> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (67) - 1, 158),
    /* 0x12c7: cmp    eax,0xca [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12cc: je     135e <tracee_syscall_name_table_lookup_xdp+0x25e> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (42) - 1, 202),
    /* 0x12d2: cmp    eax,0xd9 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12d7: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (112) - 1, 217),
    /* 0x12dd: mov    rcx,r15 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12e0: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (70) - 1, 0),
    /* 0x12e5: cmp    eax,0x3b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12e8: je     13a3 <tracee_syscall_name_table_lookup_xdp+0x2a3> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (62) - 1, 59),
    /* 0x12ee: cmp    eax,0x3c [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12f1: je     136a <tracee_syscall_name_table_lookup_xdp+0x26a> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (37) - 1, 60),
    /* 0x12f3: cmp    eax,0x3d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12f6: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (103) - 1, 61),
    /* 0x12fc: movabs rcx,0x347469617755 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x347469617755ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x1306: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (60) - 1, 0),
    /* 0x130b: cmp    eax,0x123 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1310: je     13af <tracee_syscall_name_table_lookup_xdp+0x2af> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (56) - 1, 291),
    /* 0x1316: cmp    eax,0x141 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x131b: je     1371 <tracee_syscall_name_table_lookup_xdp+0x271> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (30) - 1, 321),
    /* 0x131d: cmp    eax,0x14c [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1322: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (93) - 1, 332),
    /* 0x1328: mov    ecx,0x78746173 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 2020893043), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x132d: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (51) - 1, 0),
    /* 0x1332: mov    rcx,r9 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1335: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (48) - 1, 0),
    /* 0x133a: movabs rcx,0x6b6e696c6e75 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6b6e696c6e75ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x1344: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (44) - 1, 0),
    /* 0x1346: movabs rcx,0x656e6f6c6355 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x656e6f6c6355ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x1350: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (40) - 1, 0),
    /* 0x1352: mov    rcx,rbx [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1355: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (37) - 1, 0),
    /* 0x1357: mov    ecx,0x70616d6d [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1885433197), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x135c: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (34) - 1, 0),
    /* 0x135e: movabs rcx,0x786574756655 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x786574756655ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x1368: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (30) - 1, 0),
    /* 0x136a: mov    ecx,0x74697865 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1953069157), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x136f: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (27) - 1, 0),
    /* 0x1371: mov    ecx,0x706662 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 7366242), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1376: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (24) - 1, 0),
    /* 0x1378: mov    ecx,0x72656164 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1919246692), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x137d: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (21) - 1, 0),
    /* 0x137f: mov    ecx,0x69646863 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1768188003), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1384: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (18) - 1, 0),
    /* 0x1386: movabs rcx,0x6469707467 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6469707467ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x1390: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (14) - 1, 0),
    /* 0x1392: mov    rcx,r11 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1395: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (11) - 1, 0),
    /* 0x1397: movabs rcx,0x6c74635f68637261 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6c74635f68637261ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x13a1: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (7) - 1, 0),
    /* 0x13a3: movabs rcx,0x657663657865 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x657663657865ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x13ad: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (3) - 1, 0),
    /* 0x13af: mov    rcx,r12 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13b2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x13c0: mov    ebp,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBP, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c2: xor    rbp,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c5: mov    eax,r8d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c8: and    eax,0x7 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x13cb: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13ce: mov    r10,rbp [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13d1: shl    r10,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13d4: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13d6: not    cl [exact-kop: not8 reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13d8: shr    rbp,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13db: shl    eax,0x3 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 3), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x13de: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e0: shl    rdi,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13e3: or     rbp,r10 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13e6: add    rbp,r13 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e9: xor    rdi,rbp [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13ec: mov    r13,rdi [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_R13, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ef: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x13f2: cmp    r8,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13f6: jne    1190 <tracee_syscall_name_table_lookup_xdp+0x90> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-192) - 1, 64),
    /* 0x13fc: jmp    1413 <tracee_syscall_name_table_lookup_xdp+0x313> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (11) - 1, 0),
    /* 0x13fe: mov    eax,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1400: movabs rcx,0x9e3779b185ebca87 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b185ebca87ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RCX_OFF),
    /* 0x140a: imul   rax,rcx [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x140e: xor    r13,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1411: jmp    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-14) - 1, 0),
    /* 0x1413: mov    QWORD PTR [rdx],r13 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_R13, HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1416: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x141b: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141c: pop    r12 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141e: pop    r13 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R13, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1420: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1422: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1424: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1425: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
