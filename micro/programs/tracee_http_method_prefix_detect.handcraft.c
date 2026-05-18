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
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rsi,[rdx+0x90] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 144), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 8),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 16),
    /* 0x1130: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: lea    rax,[rdx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1137: movabs rbx,0xa0761d6478bd642f [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xa0761d6478bd642fULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RBX_OFF),
    /* 0x1141: mov    ecx,0x1 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1146: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x1150: mov    rsi,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1153: movzx  edi,BYTE PTR [rax-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RAX, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1157: movzx  r8d,BYTE PTR [rax-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R8, HC_X86_RAX, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x115c: cmp    edi,0x47 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x115f: jg     11b0 <tracee_http_method_prefix_detect_xdp+0xb0> [exact-bpf: jg as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDI_OFF),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (23) - 1, 71),
    /* 0x1161: cmp    edi,0x44 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1164: je     120f <tracee_http_method_prefix_detect_xdp+0x10f> [exact-bpf: je as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDI_OFF),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (54) - 1, 68),
    /* 0x116a: cmp    edi,0x47 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x116d: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDI_OFF),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (153) - 1, 71),
    /* 0x1173: cmp    r8b,0x45 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1177: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_R8_OFF),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (150) - 1, 69),
    /* 0x117d: mov    r8b,0x45 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1180: cmp    BYTE PTR [rax-0x4],0x54 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1184: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (144) - 1, 84),
    /* 0x118a: mov    r10b,0x45 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x118d: cmp    BYTE PTR [rax-0x3],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1191: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (138) - 1, 32),
    /* 0x1197: mov    r9d,0x1 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119d: jmp    12ab <tracee_http_method_prefix_detect_xdp+0x1ab> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (109) - 1, 0),
    /* 0x11a2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11b0: movzx  r9d,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11b4: cmp    edi,0x48 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b7: je     1261 <tracee_http_method_prefix_detect_xdp+0x161> [exact-bpf: je as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDI_OFF),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (64) - 1, 72),
    /* 0x11bd: cmp    edi,0x50 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11c0: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDI_OFF),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (129) - 1, 80),
    /* 0x11c6: cmp    r9d,0x55 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ca: je     1293 <tracee_http_method_prefix_detect_xdp+0x193> [exact-bpf: je as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_R9_OFF),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (87) - 1, 85),
    /* 0x11d0: cmp    r9d,0x4f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11d4: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_R9_OFF),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (125) - 1, 79),
    /* 0x11da: mov    r8b,0x4f [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11dd: cmp    BYTE PTR [rax-0x4],0x53 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11e1: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (119) - 1, 83),
    /* 0x11e7: cmp    BYTE PTR [rax-0x3],0x54 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11eb: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (115) - 1, 84),
    /* 0x11f1: mov    r10b,0x4f [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11f4: cmp    BYTE PTR [rax-0x2],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11f8: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (109) - 1, 32),
    /* 0x11fe: mov    r9d,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1204: mov    r8b,0x53 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 83), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1207: mov    r11b,0x54 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x120a: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (110) - 1, 0),
    /* 0x120f: cmp    r8b,0x45 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1213: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_R8_OFF),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (99) - 1, 69),
    /* 0x1219: mov    r8b,0x45 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x121c: cmp    BYTE PTR [rax-0x4],0x4c [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1220: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (93) - 1, 76),
    /* 0x1226: cmp    BYTE PTR [rax-0x3],0x45 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x122a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (89) - 1, 69),
    /* 0x1230: cmp    BYTE PTR [rax-0x2],0x54 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1234: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (85) - 1, 84),
    /* 0x123a: cmp    BYTE PTR [rax-0x1],0x45 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x123e: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -1),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (81) - 1, 69),
    /* 0x1244: mov    r11b,0x45 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1247: cmp    BYTE PTR [rax],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x124a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 0),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (75) - 1, 32),
    /* 0x1250: mov    r9d,0x4 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1256: mov    r8b,0x4c [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 76), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1259: mov    r10b,0x45 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x125c: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (76) - 1, 0),
    /* 0x1261: cmp    r9d,0x54 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1265: je     12b3 <tracee_http_method_prefix_detect_xdp+0x1b3> [exact-bpf: je as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_R9_OFF),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (45) - 1, 84),
    /* 0x1267: cmp    r9d,0x45 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x126b: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_R9_OFF),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (64) - 1, 69),
    /* 0x126d: mov    r8b,0x45 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1270: cmp    BYTE PTR [rax-0x4],0x41 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1274: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (58) - 1, 65),
    /* 0x1276: cmp    BYTE PTR [rax-0x3],0x44 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x127a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (54) - 1, 68),
    /* 0x127c: mov    r10b,0x45 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x127f: cmp    BYTE PTR [rax-0x2],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1283: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (48) - 1, 32),
    /* 0x1285: mov    r9d,0x5 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x128b: mov    r8b,0x41 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 65), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x128e: mov    r11b,0x44 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 68), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1291: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (49) - 1, 0),
    /* 0x1293: mov    r8b,0x55 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1296: cmp    BYTE PTR [rax-0x4],0x54 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x129a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (35) - 1, 84),
    /* 0x129c: mov    r10b,0x55 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x129f: cmp    BYTE PTR [rax-0x3],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12a3: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (29) - 1, 32),
    /* 0x12a5: mov    r9d,0x3 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ab: mov    r8b,0x54 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12ae: mov    r11b,0x20 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12b1: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (30) - 1, 0),
    /* 0x12b3: mov    r8b,0x54 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R8, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12b6: cmp    BYTE PTR [rax-0x4],0x54 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12ba: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (16) - 1, 84),
    /* 0x12bc: cmp    BYTE PTR [rax-0x3],0x50 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12c0: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (12) - 1, 80),
    /* 0x12c2: cmp    BYTE PTR [rax-0x2],0x2f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12c6: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RAX_OFF),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (8) - 1, 47),
    /* 0x12c8: mov    r9d,0x6 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ce: mov    r11b,0x50 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 80), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12d1: mov    r10b,0x54 [exact-kinsn: mov8 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12d4: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (9) - 1, 0),
    /* 0x12d6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x12e0: mov    r10d,r8d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12e3: movzx  r8d,BYTE PTR [rax-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R8, HC_X86_RAX, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e8: movzx  r11d,BYTE PTR [rax-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RAX, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ed: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12f0: movzx  r11d,r11b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f4: lea    ebx,[r9+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RBX, HC_X86_R9, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12f8: lea    r14,[rcx+0xa] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R14, HC_X86_RCX, 0, 0, 1, 0, 10), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12fc: imul   rbx,r14 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1300: add    rsi,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1303: shl    r11,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1307: movzx  r8d,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x130b: shl    r8d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R8, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130f: movzx  r10d,r10b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1313: shl    r10d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1317: shl    edi,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDI, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x131a: or     edi,r10d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x131d: or     edi,r8d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1320: or     rdi,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1323: mov    ebx,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1326: or     rbx,rdi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1329: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x132c: xor    rbx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132f: add    rax,0x10 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1333: inc    rcx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1336: cmp    rcx,0x9 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x133a: jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-213) - 1, 9),
    /* 0x1340: mov    BYTE PTR [rdx],sil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1343: mov    BYTE PTR [rdx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(HC_X86_RBX, HC_X86_RDX, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1346: mov    eax,ebx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1348: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x134b: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x134e: mov    eax,ebx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1350: shr    eax,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1353: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1356: mov    rax,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1359: shr    rax,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x135d: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1360: mov    rax,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1363: shr    rax,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1367: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x136a: mov    rax,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x136d: shr    rax,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1371: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1374: shr    rbx,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBX, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1378: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RBX, HC_X86_RDX, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x137b: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1380: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1381: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1383: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
