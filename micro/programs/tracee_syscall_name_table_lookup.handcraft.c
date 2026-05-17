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
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, (-5) - 1, 0),
    /* 0x1118: lea    rdi,[rdx+0x10c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 268), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_4, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x40 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 0, 64), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 64),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-19) - 1),
    /* 0x1129: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112a: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112c: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112e: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1130: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: movabs r13,0x6a09e667f3bcc909 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_7, 0, 0x6a09e667f3bcc909ULL),
    /* 0x113d: movabs rsi,0x65736f6c63 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x65736f6c63ULL),
    /* 0x1147: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114a: lea    r9,[rsi+0xfa0614] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_2, 0, 0, 1, 0, 16385556), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1151: movabs r15,0x646461746567 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_9, 0, 0x646461746567ULL),
    /* 0x115b: movabs r11,0x74616e65706f [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74616e65706fULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -424),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1165: movabs rbx,0x74616b6e696c6e75 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74616b6e696c6e75ULL),
    /* 0x116f: movabs r14,0x74613274617473 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x74613274617473ULL),
    /* 0x1179: movabs r12,0x647466656e676973 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x647466656e676973ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1183: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1190: movzx  edi,BYTE PTR [rdx+r8*4+0xc] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_3, BPF_REG_5, 2, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1196: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_5, 2, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x119c: shl    ecx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x119f: or     ecx,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11a1: movzx  eax,WORD PTR [rdx+r8*4+0xe] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_5, 2, 14), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a7: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11aa: or     eax,ecx [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11ac: cmp    eax,0x4f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 79), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11af: jg     11f0 <tracee_syscall_name_table_lookup_xdp+0xf0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (20) - 1, 79),
    /* 0x11b1: cmp    eax,0x26 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 38), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11b4: jg     1230 <tracee_syscall_name_table_lookup_xdp+0x130> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (35) - 1, 38),
    /* 0x11b6: cmp    eax,0x2 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11b9: jg     1294 <tracee_syscall_name_table_lookup_xdp+0x194> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (62) - 1, 2),
    /* 0x11bf: test   eax,eax [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x11c1: je     1378 <tracee_syscall_name_table_lookup_xdp+0x278> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_0, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (132) - 1),
    /* 0x11c7: cmp    eax,0x1 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 1), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11ca: je     1332 <tracee_syscall_name_table_lookup_xdp+0x232> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (105) - 1, 1),
    /* 0x11d0: cmp    eax,0x2 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11d3: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (186) - 1, 2),
    /* 0x11d9: mov    ecx,0x6e65706f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1852141679), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11de: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (143) - 1),
    /* 0x11e3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: cmp    eax,0x100 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 256), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11f5: jg     1260 <tracee_syscall_name_table_lookup_xdp+0x160> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (31) - 1, 256),
    /* 0x11f7: cmp    eax,0x9d [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 157), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11fc: jg     12bc <tracee_syscall_name_table_lookup_xdp+0x1bc> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (57) - 1, 157),
    /* 0x1202: cmp    eax,0x50 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 80), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1205: je     137f <tracee_syscall_name_table_lookup_xdp+0x27f> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (117) - 1, 80),
    /* 0x120b: cmp    eax,0x57 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 87), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x120e: je     133a <tracee_syscall_name_table_lookup_xdp+0x23a> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (90) - 1, 87),
    /* 0x1214: cmp    eax,0x59 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 89), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1217: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (168) - 1, 89),
    /* 0x121d: movabs rcx,0x6b6e696c55 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c55ULL),
    /* 0x1227: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (125) - 1),
    /* 0x122c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1230: cmp    eax,0x3a [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 58), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1233: jg     12e5 <tracee_syscall_name_table_lookup_xdp+0x1e5> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (54) - 1, 58),
    /* 0x1239: cmp    eax,0x27 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 39), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x123c: je     1386 <tracee_syscall_name_table_lookup_xdp+0x286> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (105) - 1, 39),
    /* 0x1242: cmp    eax,0x38 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 56), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1245: je     1346 <tracee_syscall_name_table_lookup_xdp+0x246> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (78) - 1, 56),
    /* 0x124b: cmp    eax,0x39 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 57), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x124e: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (153) - 1, 57),
    /* 0x1254: mov    ecx,0x6b726f66 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802661734), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1259: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (110) - 1),
    /* 0x125e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1260: cmp    eax,0x122 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 290), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1265: jg     130b <tracee_syscall_name_table_lookup_xdp+0x20b> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (51) - 1, 290),
    /* 0x126b: cmp    eax,0x101 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 257), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1270: je     1392 <tracee_syscall_name_table_lookup_xdp+0x292> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (93) - 1, 257),
    /* 0x1276: cmp    eax,0x107 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 263), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x127b: je     1352 <tracee_syscall_name_table_lookup_xdp+0x252> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (66) - 1, 263),
    /* 0x1281: cmp    eax,0x119 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 281), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1286: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (138) - 1, 281),
    /* 0x128c: mov    rcx,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x128f: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (95) - 1),
    /* 0x1294: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1297: cmp    eax,0x3 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 3), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x129a: je     13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (90) - 1, 3),
    /* 0x12a0: cmp    eax,0x9 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 9), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12a3: je     1357 <tracee_syscall_name_table_lookup_xdp+0x257> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (55) - 1, 9),
    /* 0x12a9: cmp    eax,0xc [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 12), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12ac: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (124) - 1, 12),
    /* 0x12b2: mov    ecx,0x6b72626b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802658411), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b7: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (81) - 1),
    /* 0x12bc: cmp    eax,0x9e [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 158), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12c1: je     1397 <tracee_syscall_name_table_lookup_xdp+0x297> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (70) - 1, 158),
    /* 0x12c7: cmp    eax,0xca [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 202), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12cc: je     135e <tracee_syscall_name_table_lookup_xdp+0x25e> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (46) - 1, 202),
    /* 0x12d2: cmp    eax,0xd9 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 217), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12d7: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (112) - 1, 217),
    /* 0x12dd: mov    rcx,r15 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12e0: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (69) - 1),
    /* 0x12e5: cmp    eax,0x3b [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 59), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12e8: je     13a3 <tracee_syscall_name_table_lookup_xdp+0x2a3> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (61) - 1, 59),
    /* 0x12ee: cmp    eax,0x3c [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 60), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12f1: je     136a <tracee_syscall_name_table_lookup_xdp+0x26a> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (37) - 1, 60),
    /* 0x12f3: cmp    eax,0x3d [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 61), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x12f6: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (100) - 1, 61),
    /* 0x12fc: movabs rcx,0x347469617755 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x347469617755ULL),
    /* 0x1306: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (57) - 1),
    /* 0x130b: cmp    eax,0x123 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 291), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1310: je     13af <tracee_syscall_name_table_lookup_xdp+0x2af> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (52) - 1, 291),
    /* 0x1316: cmp    eax,0x141 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 321), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x131b: je     1371 <tracee_syscall_name_table_lookup_xdp+0x271> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (28) - 1, 321),
    /* 0x131d: cmp    eax,0x14c [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 332), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1322: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (88) - 1, 332),
    /* 0x1328: mov    ecx,0x78746173 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2020893043), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x132d: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (45) - 1),
    /* 0x1332: mov    rcx,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1335: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (42) - 1),
    /* 0x133a: movabs rcx,0x6b6e696c6e75 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c6e75ULL),
    /* 0x1344: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (39) - 1),
    /* 0x1346: movabs rcx,0x656e6f6c6355 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x656e6f6c6355ULL),
    /* 0x1350: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (36) - 1),
    /* 0x1352: mov    rcx,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1355: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (33) - 1),
    /* 0x1357: mov    ecx,0x70616d6d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1885433197), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x135c: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (30) - 1),
    /* 0x135e: movabs rcx,0x786574756655 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x786574756655ULL),
    /* 0x1368: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (27) - 1),
    /* 0x136a: mov    ecx,0x74697865 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1953069157), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x136f: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (24) - 1),
    /* 0x1371: mov    ecx,0x706662 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 7366242), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1376: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (21) - 1),
    /* 0x1378: mov    ecx,0x72656164 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1919246692), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x137d: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (18) - 1),
    /* 0x137f: mov    ecx,0x69646863 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1768188003), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1384: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (15) - 1),
    /* 0x1386: movabs rcx,0x6469707467 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6469707467ULL),
    /* 0x1390: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (12) - 1),
    /* 0x1392: mov    rcx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1395: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (9) - 1),
    /* 0x1397: movabs rcx,0x6c74635f68637261 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6c74635f68637261ULL),
    /* 0x13a1: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (6) - 1),
    /* 0x13a3: movabs rcx,0x657663657865 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x657663657865ULL),
    /* 0x13ad: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (3) - 1),
    /* 0x13af: mov    rcx,r12 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13b2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x13c0: mov    ebp,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c2: xor    rbp,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c5: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c8: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x13cb: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13ce: mov    r10,rbp [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13d1: shl    r10,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13d4: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13d6: not    cl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13d8: shr    rbp,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13db: shl    eax,0x3 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 3), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x13de: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e0: shl    rdi,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13e3: or     rbp,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13e6: add    rbp,r13 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e9: xor    rdi,rbp [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_1, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13ec: mov    r13,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_7, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ef: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x13f2: cmp    r8,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x13f6: jne    1190 <tracee_syscall_name_table_lookup_xdp+0x90> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, (-216) - 1, 64),
    /* 0x13fc: jmp    1413 <tracee_syscall_name_table_lookup_xdp+0x313> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (10) - 1),
    /* 0x13fe: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1400: movabs rcx,0x9e3779b185ebca87 [exact-bpf: movabs via verifier-visible BPF shadow write] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x9e3779b185ebca87ULL),
    /* 0x140a: imul   rax,rcx [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x140e: xor    r13,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1411: jmp    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-14) - 1),
    /* 0x1413: mov    QWORD PTR [rdx],r13 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_7, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1416: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x141b: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141c: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141e: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1420: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1422: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1424: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1425: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
