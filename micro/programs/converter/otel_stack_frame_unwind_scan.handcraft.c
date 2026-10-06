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
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, HC_X86_RSI, BPF_REG_1, 0),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RSI, HC_X86_SHADOW_RSI_OFF),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, HC_X86_RCX, BPF_REG_1, 4),
    HC_STX(BPF_DW, BPF_REG_10, HC_X86_RCX, HC_X86_SHADOW_RCX_OFF),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rdx,[rsi+0x250] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 0, 0, 1, 0, 592), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi+0x8],0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 24),
    /* 0x112a: cmp    DWORD PTR [rsi+0xc],0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 24),
    /* 0x1130: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1138: lea    rdi,[rsi+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDI, HC_X86_RSI, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: movabs r8,0x100000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x100000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R8_OFF),
    /* 0x1146: movabs r11,0x589965cc75374cc3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x589965cc75374cc3ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R11_OFF),
    /* 0x1150: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1153: mov    r10d,0x8 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1159: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (14) - 1, 0),
    /* 0x115b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1164: or     rax,rdx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1167: xor    r11,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x116a: inc    r9 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x116d: add    rdi,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1171: cmp    r9,0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1175: je     1272 <otel_stack_frame_unwind_scan_xdp+0x172> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (120) - 1, 24),
    /* 0x117b: mov    rdx,QWORD PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RDI, -23), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x117f: mov    r14d,DWORD PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1183: mov    r15d,DWORD PTR [rdi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R15, HC_X86_RDI, -11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1187: movzx  ebp,WORD PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RDI, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x118b: movzx  eax,WORD PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RDI, -5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x118f: mov    ebx,DWORD PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBX, HC_X86_RDI, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1192: cmp    eax,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1195: jg     11b0 <otel_stack_frame_unwind_scan_xdp+0xb0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (11) - 1, 1),
    /* 0x1197: test   eax,eax [control-flow-operand: test folded into BPF branch] */
    /* 0x1199: je     11ca <otel_stack_frame_unwind_scan_xdp+0xca> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, -1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (17) - 1, 0),
    /* 0x119b: cmp    eax,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x119e: jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-31) - 1, 1),
    /* 0x11a0: mov    ecx,0x35 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 53), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a5: cmp    r14d,0x1000 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ac: jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, (20) - 1, 4096),
    /* 0x11ae: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-36) - 1, 0),
    /* 0x11b0: cmp    eax,0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b3: je     11da <otel_stack_frame_unwind_scan_xdp+0xda> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (13) - 1, 2),
    /* 0x11b5: cmp    eax,0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b8: jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RAX),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-40) - 1, 3),
    /* 0x11ba: mov    ecx,0x89 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 137), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11bf: cmp    r14d,0x1000 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11c6: jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, (11) - 1, 4096),
    /* 0x11c8: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-45) - 1, 0),
    /* 0x11ca: mov    ecx,0x21 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 33), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11cf: cmp    r14d,0x1000 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11d6: jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, (6) - 1, 4096),
    /* 0x11d8: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-50) - 1, 0),
    /* 0x11da: mov    ecx,0x55 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 85), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11df: cmp    r14d,0x1000 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11e6: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R14),
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_6, 0, (-54) - 1, 4096),
    /* 0x11ec: cmp    r15d,0x2001 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11f3: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: jae as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R15),
    HC_RAW(BPF_JMP32 | BPF_JGE | BPF_K, BPF_REG_6, 0, (-56) - 1, 8193),
    /* 0x11f9: test   bpl,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RBP, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11fd: mov    r12d,r15d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1200: cmove  r12d,r10d [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_PAYLOAD(HC_X86_R12, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMOVEL),
    /* 0x1204: add    r12d,r14d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1207: add    r8,r12 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x120a: mov    r12,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x120d: shl    r12,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1211: or     rcx,r12 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1214: xor    rdx,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1217: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x121a: test   bpl,0x2 [control-flow-operand: test folded into BPF branch] */
    /* 0x121e: je     1227 <otel_stack_frame_unwind_scan_xdp+0x127> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, 2),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (7) - 1, 0),
    /* 0x1220: inc    al [exact-kinsn: incb reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_INCB),
    /* 0x1222: mov    ecx,eax [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1224: rol    rdx,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1227: mov    eax,r15d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122a: shl    rax,0x18 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 24), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x122e: mov    ecx,r14d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1231: xor    rcx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1234: test   bpl,0x4 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RBP, 4), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1238: mov    eax,0x0 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x123d: cmovne rax,rcx [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1241: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1244: mov    edx,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1247: and    dl,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x124a: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x124d: mov    r14,rax [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R14, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1250: shl    r14,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1253: not    dl [exact-kinsn: not8 reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1255: mov    ecx,edx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1257: shr    rax,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x125a: or     rax,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x125d: add    rax,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1260: movzx  ecx,bp [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1263: shl    rcx,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1267: or     rbx,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x126a: mov    r11,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x126d: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-127) - 1, 0),
    /* 0x1272: mov    QWORD PTR [rsi],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, HC_X86_RSI, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1275: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127a: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x127b: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x127d: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x127f: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1281: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1282: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
