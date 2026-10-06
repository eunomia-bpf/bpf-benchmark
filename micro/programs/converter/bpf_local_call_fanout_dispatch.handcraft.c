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
    /* 0x1100: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1101: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1103: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1105: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R13, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1107: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1109: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110a: push   rax [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RAX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110b: mov    r14,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, HC_X86_R14, BPF_REG_1, 0),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_R14, HC_X86_SHADOW_R14_OFF),
    /* 0x110e: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 4),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1112: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1114: cmp    r14,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1117: jbe    1128 <bpf_local_call_fanout_dispatch_xdp+0x28> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (16) - 1, 0),
    /* 0x1119: add    rsp,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x111d: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x111e: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1120: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R13, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1122: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1124: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1126: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1127: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x1128: lea    rdx,[r14+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_R14, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112c: mov    QWORD PTR [rsp],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1130: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1133: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-21) - 1, 0),
    /* 0x1135: lea    rdx,[r14+0x190] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_R14, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x113f: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-26) - 1, 0),
    /* 0x1141: cmp    DWORD PTR [r14+0x8],0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1146: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-29) - 1, 16),
    /* 0x1148: cmp    DWORD PTR [r14+0xc],0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x114d: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-32) - 1, 24),
    /* 0x114f: movabs rdi,0x243f6a8885a308d3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x243f6a8885a308d3ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RDI_OFF),
    /* 0x1159: xor    r15d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R15, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115c: mov    r12d,0x17 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R12, 23), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1162: xor    r13d,r13d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R13, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1165: jmp    11a1 <bpf_local_call_fanout_dispatch_xdp+0xa1> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (26) - 1, 0),
    /* 0x1167: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1170: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RSI, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1174: mov    ecx,ebp [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1176: call   1260 <local_call_pressure> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(103),
    /* 0x117b: mov    ecx,r13d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117e: and    cl,0x38 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 56), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1181: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1184: mov    edi,ebp [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDI, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1186: add    rdi,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1189: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x118c: add    r13,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R13, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1190: add    r15d,0x10 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R15, 16), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1194: add    r12,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1198: cmp    r13,0x80 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x119f: je     1200 <bpf_local_call_fanout_dispatch_xdp+0x100> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R13),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (35) - 1, 128),
    /* 0x11a1: movzx  ebx,BYTE PTR [r14+r12*1-0x7] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RBX, HC_X86_R14, HC_X86_R12, 0, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a7: and    ebx,0x3 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBX, 3), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11aa: mov    ebp,DWORD PTR [r14+r12*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RBP, HC_X86_R14, HC_X86_R12, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11af: xor    ebp,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBP, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11b2: lea    rdx,[r12-0xf] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_R12, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11b7: cmp    rbx,0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11bb: je     11e0 <bpf_local_call_fanout_dispatch_xdp+0xe0> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RBX),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (11) - 1, 2),
    /* 0x11bd: cmp    ebx,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11c0: je     1170 <bpf_local_call_fanout_dispatch_xdp+0x70> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RBX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (-38) - 1, 1),
    /* 0x11c2: test   ebx,ebx [control-flow-operand: test folded into BPF branch] */
    /* 0x11c4: jne    11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RBX),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, (13) - 1, -1),
    /* 0x11c6: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RSI, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11ca: mov    ecx,ebp [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11cc: call   1210 <local_call_linear> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(19),
    /* 0x11d1: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-41) - 1, 0),
    /* 0x11d3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11e0: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RSI, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11e4: mov    ecx,ebp [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e6: call   12b0 <local_call_crossload> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(97),
    /* 0x11eb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-47) - 1, 0),
    /* 0x11ed: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: mov    rsi,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RSI, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11f4: mov    ecx,ebp [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f6: call   1340 <local_call_bytes> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(172),
    /* 0x11fb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-53) - 1, 0),
    /* 0x1200: mov    QWORD PTR [r14],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RDI, HC_X86_R14, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1203: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1208: jmp    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-106) - 1, 0),
    /* 0x120d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1210: mov    r8d,ecx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1213: mov    ecx,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1215: mov    rax,QWORD PTR [rcx+rsi*1+0x8] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RAX, HC_X86_RCX, HC_X86_RSI, 0, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x121a: lea    r9,[rax+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_RAX, HC_X86_RAX, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x121e: mov    edx,r8d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1221: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1224: add    r9,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1227: add    r9,QWORD PTR [rcx+rsi*1+0x10] [exact-kinsn: add64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R9, HC_X86_RCX, HC_X86_RSI, 0, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x122c: shl    rdx,0xb [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 11), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1230: add    rdx,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1233: and    r8d,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R8, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1237: lea    ecx,[r8+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_R8, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123b: mov    rsi,rdx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x123e: shl    rsi,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1241: not    r8b [exact-kinsn: not8 reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1244: mov    ecx,r8d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1247: shr    rdx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x124a: or     rdx,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x124d: xor    rdx,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1250: shr    rax,0x3 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 3), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1254: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1257: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x1258: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1260: mov    eax,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1262: mov    r8,QWORD PTR [rax+rsi*1+0x8] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R8, HC_X86_RAX, HC_X86_RSI, 0, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1267: mov    rdx,QWORD PTR [rax+rsi*1+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDX, HC_X86_RAX, HC_X86_RSI, 0, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x126c: xor    rdi,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x126f: mov    eax,ecx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1271: shl    rax,0x11 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 17), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1275: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1278: lea    rcx,[rdi*8+0x0] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RCX, 0, HC_X86_RDI, 3, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1280: shr    rdx,0x2 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1284: xor    r8,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1287: rol    r8,0x5 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R8, HC_X86_R8, 5), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x128b: xor    rdx,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x128e: lea    rcx,[rdx+rdi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RDX, HC_X86_RDI, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1292: rol    rcx,0xb [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RCX, HC_X86_RCX, 11), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1296: add    rcx,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1299: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x129c: shr    rax,0x7 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x12a0: xor    rax,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12a3: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12a6: xor    rax,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12a9: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x12aa: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x12b0: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x12b2: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x12b3: mov    r8d,ecx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b6: mov    eax,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b8: movzx  edx,BYTE PTR [rsi+rax*1] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDX, HC_X86_RSI, HC_X86_RAX, 0, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12bc: lea    rcx,[rax+0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 4), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12c0: movzx  r9d,BYTE PTR [rsi+rax*1+0x4] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R9, HC_X86_RSI, HC_X86_RAX, 0, 4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12c6: movsxd r11,ecx [exact-kinsn: movsxd reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVSXD),
    /* 0x12c9: movzx  r10d,BYTE PTR [rsi+r11*1+0x1] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R10, HC_X86_RSI, HC_X86_R11, 0, 1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12cf: add    rdi,QWORD PTR [rsi+rax*1+0x8] [exact-kinsn: add64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RSI, HC_X86_RAX, 0, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12d4: mov    rax,QWORD PTR [rsi+rax*1+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RAX, HC_X86_RSI, HC_X86_RAX, 0, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12d9: xor    rax,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12dc: and    dl,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x12df: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12e2: mov    rbx,rax [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12e5: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x12e8: movzx  r14d,BYTE PTR [rsi+r11*1+0x2] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R14, HC_X86_RSI, HC_X86_R11, 0, 2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ee: movzx  esi,BYTE PTR [rsi+r11*1+0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RSI, HC_X86_R11, 0, 3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f4: mov    ecx,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f6: not    cl [exact-kinsn: not8 reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x12f8: shr    rax,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x12fb: or     rax,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x12fe: shl    rsi,0x21 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSI, 33), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1302: shl    r14,0x19 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R14, 25), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1306: shl    r10d,0x11 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 17), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130a: shl    r9d,0x9 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 9), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130e: or     r9d,r10d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1311: or     r9,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1314: or     r9,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1317: xor    r9,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x131a: xor    r9,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x131d: mov    esi,r8d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RSI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1320: mov    ecx,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1322: shl    rsi,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1325: add    rsi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1328: shr    rax,0x5 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 5), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x132c: xor    rax,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132f: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1332: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1333: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1335: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x1336: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x1340: mov    eax,ecx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1342: mov    ecx,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1344: movzx  edx,BYTE PTR [rsi+rcx*1] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDX, HC_X86_RSI, HC_X86_RCX, 0, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1348: movabs r8,0x94d049bb133111eb [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x94d049bb133111ebULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R8_OFF),
    /* 0x1352: xor    r8,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1355: xor    r8,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1358: add    r8,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x135b: rol    r8,1 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R8, HC_X86_R8, 1), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x135e: movzx  edx,BYTE PTR [rsi+rcx*1+0x1] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDX, HC_X86_RSI, HC_X86_RCX, 0, 1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1363: shl    edx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1366: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1369: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x136c: inc    rdx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x136f: rol    rdx,0x2 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 2), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1373: movzx  edi,BYTE PTR [rsi+rcx*1+0x2] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RSI, HC_X86_RCX, 0, 2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1378: shl    edi,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x137b: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x137e: lea    rdx,[rax+rdi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, HC_X86_RDI, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1382: add    rdx,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1386: rol    rdx,0x3 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 3), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x138a: movzx  edi,BYTE PTR [rsi+rcx*1+0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RSI, HC_X86_RCX, 0, 3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x138f: shl    edi,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1392: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1395: lea    rdx,[rax+rdi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, HC_X86_RDI, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1399: add    rdx,0x3 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x139d: rol    rdx,0x4 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 4), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13a1: movzx  edi,BYTE PTR [rsi+rcx*1+0x4] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RSI, HC_X86_RCX, 0, 4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13a6: shl    rdi,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13aa: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13ad: lea    rdx,[rax+rdi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, HC_X86_RDI, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x13b1: add    rdx,0x4 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13b5: rol    rdx,0x5 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 5), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13b9: movzx  edi,BYTE PTR [rsi+rcx*1+0x5] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RSI, HC_X86_RCX, 0, 5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13be: shl    rdi,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c2: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c5: lea    rdx,[rax+rdi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, HC_X86_RDI, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x13c9: add    rdx,0x5 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13cd: rol    rdx,0x6 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 6), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13d1: movzx  edi,BYTE PTR [rsi+rcx*1+0x6] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RSI, HC_X86_RCX, 0, 6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13d6: shl    rdi,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13da: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13dd: lea    rdx,[rax+rdi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RAX, HC_X86_RDI, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x13e1: add    rdx,0x6 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e5: rol    rdx,0x7 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 7), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13e9: movzx  edi,BYTE PTR [rsi+rcx*1+0x7] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RDI, HC_X86_RSI, HC_X86_RCX, 0, 7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13ee: shl    rdi,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13f2: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13f5: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13f8: add    rax,0x7 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13fc: rol    rax,0x8 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 8), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1400: add    rax,QWORD PTR [rsi+rcx*1+0x8] [exact-kinsn: add64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RAX, HC_X86_RSI, HC_X86_RCX, 0, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1405: xor    rax,QWORD PTR [rsi+rcx*1+0x10] [exact-kinsn: xor64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RAX, HC_X86_RSI, HC_X86_RCX, 0, 16), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x140a: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
