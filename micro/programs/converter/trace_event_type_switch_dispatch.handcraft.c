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
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <trace_event_type_switch_dispatch_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RCX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rdi,[rcx+0x20c] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 0, 0, 1, 0, 524), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDI),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x80 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112a: jne    110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 128),
    /* 0x112c: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112d: mov    edx,0xf [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RDX, 15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1132: xor    ebx,ebx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1134: jmp    1154 <trace_event_type_switch_dispatch_xdp+0x54> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (9) - 1, 0),
    /* 0x1136: mov    ebx,0xc [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x113b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: xor    rbx,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1143: add    rdx,0x4 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1147: cmp    rdx,0x20f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x114e: je     172a <trace_event_type_switch_dispatch_xdp+0x62a> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (387) - 1, 527),
    /* 0x1154: mov    rax,rbx [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1157: mov    esi,DWORD PTR [rcx+rdx*1-0x3] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RCX, HC_X86_RDX, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x115b: cmp    esi,0x1f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x115e: jg     11a0 <trace_event_type_switch_dispatch_xdp+0xa0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (19) - 1, 31),
    /* 0x1160: cmp    esi,0xf [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1163: jg     11e0 <trace_event_type_switch_dispatch_xdp+0xe0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (32) - 1, 15),
    /* 0x1165: cmp    esi,0x7 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1168: jg     1254 <trace_event_type_switch_dispatch_xdp+0x154> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (56) - 1, 7),
    /* 0x116e: cmp    esi,0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1171: jg     130c <trace_event_type_switch_dispatch_xdp+0x20c> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (98) - 1, 3),
    /* 0x1177: cmp    esi,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x117a: jg     1434 <trace_event_type_switch_dispatch_xdp+0x334> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (168) - 1, 1),
    /* 0x1180: mov    ebx,0x38 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 56), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1185: test   esi,esi [control-flow-operand: test folded into BPF branch] */
    /* 0x1187: je     1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, -1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-24) - 1, 0),
    /* 0x1189: cmp    esi,0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x118c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (363) - 1, 1),
    /* 0x1192: mov    ebx,0x2b [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 43), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1197: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-29) - 1, 0),
    /* 0x1199: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: cmp    esi,0x2f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11a3: jg     1220 <trace_event_type_switch_dispatch_xdp+0x120> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (27) - 1, 47),
    /* 0x11a5: cmp    esi,0x27 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11a8: jg     1282 <trace_event_type_switch_dispatch_xdp+0x182> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (49) - 1, 39),
    /* 0x11ae: cmp    esi,0x23 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b1: jg     1331 <trace_event_type_switch_dispatch_xdp+0x231> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (89) - 1, 35),
    /* 0x11b7: cmp    esi,0x21 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ba: jg     1450 <trace_event_type_switch_dispatch_xdp+0x350> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (157) - 1, 33),
    /* 0x11c0: cmp    esi,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11c3: je     15f4 <trace_event_type_switch_dispatch_xdp+0x4f4> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (260) - 1, 32),
    /* 0x11c9: cmp    esi,0x21 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11cc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (348) - 1, 33),
    /* 0x11d2: mov    ebx,0x27 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 39), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-44) - 1, 0),
    /* 0x11dc: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11e0: cmp    esi,0x17 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11e3: jg     12b0 <trace_event_type_switch_dispatch_xdp+0x1b0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (47) - 1, 23),
    /* 0x11e9: cmp    esi,0x13 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ec: jg     1356 <trace_event_type_switch_dispatch_xdp+0x256> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (85) - 1, 19),
    /* 0x11f2: cmp    esi,0x11 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11f5: jg     146c <trace_event_type_switch_dispatch_xdp+0x36c> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (151) - 1, 17),
    /* 0x11fb: cmp    esi,0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11fe: je     15fe <trace_event_type_switch_dispatch_xdp+0x4fe> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (250) - 1, 16),
    /* 0x1204: cmp    esi,0x11 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1207: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (335) - 1, 17),
    /* 0x120d: mov    ebx,0x3e [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 62), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1212: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-57) - 1, 0),
    /* 0x1217: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1220: cmp    esi,0x37 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1223: jg     12de <trace_event_type_switch_dispatch_xdp+0x1de> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (45) - 1, 55),
    /* 0x1229: cmp    esi,0x33 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x122c: jg     137b <trace_event_type_switch_dispatch_xdp+0x27b> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (81) - 1, 51),
    /* 0x1232: cmp    esi,0x31 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1235: jg     1488 <trace_event_type_switch_dispatch_xdp+0x388> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (145) - 1, 49),
    /* 0x123b: cmp    esi,0x30 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x123e: je     1608 <trace_event_type_switch_dispatch_xdp+0x508> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (240) - 1, 48),
    /* 0x1244: cmp    esi,0x31 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1247: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (322) - 1, 49),
    /* 0x124d: xor    ebx,ebx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x124f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-70) - 1, 0),
    /* 0x1254: cmp    esi,0xb [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1257: jg     13a0 <trace_event_type_switch_dispatch_xdp+0x2a0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (79) - 1, 11),
    /* 0x125d: cmp    esi,0x9 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1260: jg     14a4 <trace_event_type_switch_dispatch_xdp+0x3a4> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (141) - 1, 9),
    /* 0x1266: cmp    esi,0x8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1269: je     1612 <trace_event_type_switch_dispatch_xdp+0x512> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (232) - 1, 8),
    /* 0x126f: cmp    esi,0x9 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1272: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (311) - 1, 9),
    /* 0x1278: mov    ebx,0x3f [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 63), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-81) - 1, 0),
    /* 0x1282: cmp    esi,0x2b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1285: jg     13c5 <trace_event_type_switch_dispatch_xdp+0x2c5> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (77) - 1, 43),
    /* 0x128b: cmp    esi,0x29 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x128e: jg     14c0 <trace_event_type_switch_dispatch_xdp+0x3c0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (137) - 1, 41),
    /* 0x1294: cmp    esi,0x28 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1297: je     161c <trace_event_type_switch_dispatch_xdp+0x51c> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (224) - 1, 40),
    /* 0x129d: cmp    esi,0x29 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12a0: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (300) - 1, 41),
    /* 0x12a6: mov    ebx,0x32 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 50), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ab: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-92) - 1, 0),
    /* 0x12b0: cmp    esi,0x1b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12b3: jg     13ea <trace_event_type_switch_dispatch_xdp+0x2ea> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (75) - 1, 27),
    /* 0x12b9: cmp    esi,0x19 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12bc: jg     14dc <trace_event_type_switch_dispatch_xdp+0x3dc> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (133) - 1, 25),
    /* 0x12c2: cmp    esi,0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12c5: je     1626 <trace_event_type_switch_dispatch_xdp+0x526> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (216) - 1, 24),
    /* 0x12cb: cmp    esi,0x19 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12ce: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (289) - 1, 25),
    /* 0x12d4: mov    ebx,0x1a [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 26), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12d9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-103) - 1, 0),
    /* 0x12de: cmp    esi,0x3b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12e1: jg     140f <trace_event_type_switch_dispatch_xdp+0x30f> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (73) - 1, 59),
    /* 0x12e7: cmp    esi,0x39 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12ea: jg     14f8 <trace_event_type_switch_dispatch_xdp+0x3f8> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (129) - 1, 57),
    /* 0x12f0: cmp    esi,0x38 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12f3: je     1630 <trace_event_type_switch_dispatch_xdp+0x530> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (208) - 1, 56),
    /* 0x12f9: cmp    esi,0x39 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x12fc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (278) - 1, 57),
    /* 0x1302: mov    ebx,0x36 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 54), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1307: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-114) - 1, 0),
    /* 0x130c: cmp    esi,0x5 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x130f: jg     1514 <trace_event_type_switch_dispatch_xdp+0x414> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (127) - 1, 5),
    /* 0x1315: cmp    esi,0x4 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1318: je     163a <trace_event_type_switch_dispatch_xdp+0x53a> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (202) - 1, 4),
    /* 0x131e: cmp    esi,0x5 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1321: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (269) - 1, 5),
    /* 0x1327: mov    ebx,0x3d [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 61), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x132c: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-123) - 1, 0),
    /* 0x1331: cmp    esi,0x25 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1334: jg     1530 <trace_event_type_switch_dispatch_xdp+0x430> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (125) - 1, 37),
    /* 0x133a: cmp    esi,0x24 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x133d: je     1644 <trace_event_type_switch_dispatch_xdp+0x544> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (196) - 1, 36),
    /* 0x1343: cmp    esi,0x25 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1346: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (260) - 1, 37),
    /* 0x134c: mov    ebx,0x4 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1351: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-132) - 1, 0),
    /* 0x1356: cmp    esi,0x15 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1359: jg     154c <trace_event_type_switch_dispatch_xdp+0x44c> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (123) - 1, 21),
    /* 0x135f: cmp    esi,0x14 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1362: je     164e <trace_event_type_switch_dispatch_xdp+0x54e> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (190) - 1, 20),
    /* 0x1368: cmp    esi,0x15 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x136b: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (251) - 1, 21),
    /* 0x1371: mov    ebx,0x15 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 21), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1376: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-141) - 1, 0),
    /* 0x137b: cmp    esi,0x35 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x137e: jg     1568 <trace_event_type_switch_dispatch_xdp+0x468> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (121) - 1, 53),
    /* 0x1384: cmp    esi,0x34 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1387: je     1658 <trace_event_type_switch_dispatch_xdp+0x558> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (184) - 1, 52),
    /* 0x138d: cmp    esi,0x35 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1390: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (242) - 1, 53),
    /* 0x1396: mov    ebx,0x14 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 20), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x139b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-150) - 1, 0),
    /* 0x13a0: cmp    esi,0xd [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13a3: jg     1584 <trace_event_type_switch_dispatch_xdp+0x484> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (119) - 1, 13),
    /* 0x13a9: cmp    esi,0xc [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13ac: je     1662 <trace_event_type_switch_dispatch_xdp+0x562> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (178) - 1, 12),
    /* 0x13b2: cmp    esi,0xd [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13b5: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (233) - 1, 13),
    /* 0x13bb: mov    ebx,0x2a [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 42), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c0: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-159) - 1, 0),
    /* 0x13c5: cmp    esi,0x2d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13c8: jg     15a0 <trace_event_type_switch_dispatch_xdp+0x4a0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (117) - 1, 45),
    /* 0x13ce: cmp    esi,0x2c [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13d1: je     166c <trace_event_type_switch_dispatch_xdp+0x56c> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (172) - 1, 44),
    /* 0x13d7: cmp    esi,0x2d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13da: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (224) - 1, 45),
    /* 0x13e0: mov    ebx,0x2c [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 44), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e5: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-168) - 1, 0),
    /* 0x13ea: cmp    esi,0x1d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13ed: jg     15bc <trace_event_type_switch_dispatch_xdp+0x4bc> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (115) - 1, 29),
    /* 0x13f3: cmp    esi,0x1c [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13f6: je     1676 <trace_event_type_switch_dispatch_xdp+0x576> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (166) - 1, 28),
    /* 0x13fc: cmp    esi,0x1d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x13ff: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (215) - 1, 29),
    /* 0x1405: mov    ebx,0x1f [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 31), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x140a: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-177) - 1, 0),
    /* 0x140f: cmp    esi,0x3d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1412: jg     15d8 <trace_event_type_switch_dispatch_xdp+0x4d8> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (113) - 1, 61),
    /* 0x1418: cmp    esi,0x3c [control-flow-operand: cmp folded into BPF branch] */
    /* 0x141b: je     1680 <trace_event_type_switch_dispatch_xdp+0x580> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (160) - 1, 60),
    /* 0x1421: cmp    esi,0x3d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1424: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (206) - 1, 61),
    /* 0x142a: mov    ebx,0x5 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x142f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-186) - 1, 0),
    /* 0x1434: cmp    esi,0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1437: je     168a <trace_event_type_switch_dispatch_xdp+0x58a> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (156) - 1, 2),
    /* 0x143d: cmp    esi,0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1440: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (199) - 1, 3),
    /* 0x1446: mov    ebx,0x1c [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 28), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x144b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-193) - 1, 0),
    /* 0x1450: cmp    esi,0x22 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1453: je     1694 <trace_event_type_switch_dispatch_xdp+0x594> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (152) - 1, 34),
    /* 0x1459: cmp    esi,0x23 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x145c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (192) - 1, 35),
    /* 0x1462: mov    ebx,0x1b [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 27), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1467: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-200) - 1, 0),
    /* 0x146c: cmp    esi,0x12 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x146f: je     169e <trace_event_type_switch_dispatch_xdp+0x59e> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (148) - 1, 18),
    /* 0x1475: cmp    esi,0x13 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1478: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (185) - 1, 19),
    /* 0x147e: mov    ebx,0x6 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1483: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-207) - 1, 0),
    /* 0x1488: cmp    esi,0x32 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x148b: je     16a8 <trace_event_type_switch_dispatch_xdp+0x5a8> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (144) - 1, 50),
    /* 0x1491: cmp    esi,0x33 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1494: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (178) - 1, 51),
    /* 0x149a: mov    ebx,0x3 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x149f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-214) - 1, 0),
    /* 0x14a4: cmp    esi,0xa [control-flow-operand: cmp folded into BPF branch] */
    /* 0x14a7: je     16b2 <trace_event_type_switch_dispatch_xdp+0x5b2> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (140) - 1, 10),
    /* 0x14ad: cmp    esi,0xb [control-flow-operand: cmp folded into BPF branch] */
    /* 0x14b0: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (171) - 1, 11),
    /* 0x14b6: mov    ebx,0x24 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 36), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x14bb: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-221) - 1, 0),
    /* 0x14c0: cmp    esi,0x2a [control-flow-operand: cmp folded into BPF branch] */
    /* 0x14c3: je     16bc <trace_event_type_switch_dispatch_xdp+0x5bc> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (136) - 1, 42),
    /* 0x14c9: cmp    esi,0x2b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x14cc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (164) - 1, 43),
    /* 0x14d2: mov    ebx,0x23 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 35), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x14d7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-228) - 1, 0),
    /* 0x14dc: cmp    esi,0x1a [control-flow-operand: cmp folded into BPF branch] */
    /* 0x14df: je     16c6 <trace_event_type_switch_dispatch_xdp+0x5c6> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (132) - 1, 26),
    /* 0x14e5: cmp    esi,0x1b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x14e8: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (157) - 1, 27),
    /* 0x14ee: mov    ebx,0x29 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 41), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x14f3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-235) - 1, 0),
    /* 0x14f8: cmp    esi,0x3a [control-flow-operand: cmp folded into BPF branch] */
    /* 0x14fb: je     16d0 <trace_event_type_switch_dispatch_xdp+0x5d0> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (128) - 1, 58),
    /* 0x1501: cmp    esi,0x3b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1504: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (150) - 1, 59),
    /* 0x150a: mov    ebx,0x10 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 16), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x150f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-242) - 1, 0),
    /* 0x1514: cmp    esi,0x6 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1517: je     16da <trace_event_type_switch_dispatch_xdp+0x5da> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (124) - 1, 6),
    /* 0x151d: cmp    esi,0x7 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1520: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (143) - 1, 7),
    /* 0x1526: mov    ebx,0x3a [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 58), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x152b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-249) - 1, 0),
    /* 0x1530: cmp    esi,0x26 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1533: je     16e4 <trace_event_type_switch_dispatch_xdp+0x5e4> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (120) - 1, 38),
    /* 0x1539: cmp    esi,0x27 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x153c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (136) - 1, 39),
    /* 0x1542: mov    ebx,0x30 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 48), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1547: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-256) - 1, 0),
    /* 0x154c: cmp    esi,0x16 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x154f: je     16ee <trace_event_type_switch_dispatch_xdp+0x5ee> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (116) - 1, 22),
    /* 0x1555: cmp    esi,0x17 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1558: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (129) - 1, 23),
    /* 0x155e: mov    ebx,0x28 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 40), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1563: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-263) - 1, 0),
    /* 0x1568: cmp    esi,0x36 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x156b: je     16f8 <trace_event_type_switch_dispatch_xdp+0x5f8> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (112) - 1, 54),
    /* 0x1571: cmp    esi,0x37 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1574: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (122) - 1, 55),
    /* 0x157a: mov    ebx,0x12 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 18), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x157f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-270) - 1, 0),
    /* 0x1584: cmp    esi,0xe [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1587: je     1702 <trace_event_type_switch_dispatch_xdp+0x602> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (108) - 1, 14),
    /* 0x158d: cmp    esi,0xf [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1590: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (115) - 1, 15),
    /* 0x1596: mov    ebx,0x2e [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 46), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x159b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-277) - 1, 0),
    /* 0x15a0: cmp    esi,0x2e [control-flow-operand: cmp folded into BPF branch] */
    /* 0x15a3: je     170c <trace_event_type_switch_dispatch_xdp+0x60c> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (104) - 1, 46),
    /* 0x15a9: cmp    esi,0x2f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x15ac: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (108) - 1, 47),
    /* 0x15b2: mov    ebx,0x3b [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 59), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15b7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-284) - 1, 0),
    /* 0x15bc: cmp    esi,0x1e [control-flow-operand: cmp folded into BPF branch] */
    /* 0x15bf: je     1716 <trace_event_type_switch_dispatch_xdp+0x616> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (100) - 1, 30),
    /* 0x15c5: cmp    esi,0x1f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x15c8: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (101) - 1, 31),
    /* 0x15ce: mov    ebx,0x34 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15d3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-291) - 1, 0),
    /* 0x15d8: cmp    esi,0x3e [control-flow-operand: cmp folded into BPF branch] */
    /* 0x15db: je     1136 <trace_event_type_switch_dispatch_xdp+0x36> [exact-bpf: je as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (-295) - 1, 62),
    /* 0x15e1: cmp    esi,0x3f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x15e4: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (94) - 1, 63),
    /* 0x15ea: mov    ebx,0x37 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 55), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15ef: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-298) - 1, 0),
    /* 0x15f4: mov    ebx,0x19 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 25), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15f9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-301) - 1, 0),
    /* 0x15fe: mov    ebx,0x22 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 34), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1603: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-304) - 1, 0),
    /* 0x1608: mov    ebx,0x2d [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 45), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x160d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-307) - 1, 0),
    /* 0x1612: mov    ebx,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1617: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-310) - 1, 0),
    /* 0x161c: mov    ebx,0x20 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 32), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1621: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-313) - 1, 0),
    /* 0x1626: mov    ebx,0x26 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x162b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-316) - 1, 0),
    /* 0x1630: mov    ebx,0x1 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1635: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-319) - 1, 0),
    /* 0x163a: mov    ebx,0xe [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x163f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-322) - 1, 0),
    /* 0x1644: mov    ebx,0x35 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 53), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1649: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-325) - 1, 0),
    /* 0x164e: mov    ebx,0x1d [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 29), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1653: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-328) - 1, 0),
    /* 0x1658: mov    ebx,0xd [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 13), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x165d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-331) - 1, 0),
    /* 0x1662: mov    ebx,0x13 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1667: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-334) - 1, 0),
    /* 0x166c: mov    ebx,0x8 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1671: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-337) - 1, 0),
    /* 0x1676: mov    ebx,0x21 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 33), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x167b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-340) - 1, 0),
    /* 0x1680: mov    ebx,0x3c [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 60), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1685: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-343) - 1, 0),
    /* 0x168a: mov    ebx,0x39 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 57), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x168f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-346) - 1, 0),
    /* 0x1694: mov    ebx,0xb [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1699: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-349) - 1, 0),
    /* 0x169e: mov    ebx,0x2f [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 47), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16a3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-352) - 1, 0),
    /* 0x16a8: mov    ebx,0x9 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16ad: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-355) - 1, 0),
    /* 0x16b2: mov    ebx,0x31 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 49), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16b7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-358) - 1, 0),
    /* 0x16bc: mov    ebx,0x7 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16c1: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-361) - 1, 0),
    /* 0x16c6: mov    ebx,0x11 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 17), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16cb: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-364) - 1, 0),
    /* 0x16d0: mov    ebx,0x16 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 22), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16d5: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-367) - 1, 0),
    /* 0x16da: mov    ebx,0xa [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16df: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-370) - 1, 0),
    /* 0x16e4: mov    ebx,0x18 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 24), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16e9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-373) - 1, 0),
    /* 0x16ee: mov    ebx,0xf [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16f3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-376) - 1, 0),
    /* 0x16f8: mov    ebx,0x1e [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 30), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16fd: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-379) - 1, 0),
    /* 0x1702: mov    ebx,0x25 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1707: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-382) - 1, 0),
    /* 0x170c: mov    ebx,0x33 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 51), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1711: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-385) - 1, 0),
    /* 0x1716: mov    ebx,0x17 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 23), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x171b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-388) - 1, 0),
    /* 0x1720: mov    ebx,0x1bf52 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBX, 114514), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1725: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-391) - 1, 0),
    /* 0x172a: mov    BYTE PTR [rcx],bl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RBX, HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x172c: mov    BYTE PTR [rcx+0x1],bh [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_BYTE_PAYLOAD(HC_X86_RBX, HC_X86_RCX, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x172f: shr    ebx,0x10 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBX, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1732: mov    BYTE PTR [rcx+0x2],bl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RBX, HC_X86_RCX, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1735: mov    edx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1737: shr    edx,0x18 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x173a: mov    BYTE PTR [rcx+0x3],dl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x173d: mov    rdx,rax [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1740: shr    rdx,0x20 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1744: mov    BYTE PTR [rcx+0x4],dl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1747: mov    rdx,rax [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x174a: shr    rdx,0x28 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x174e: mov    BYTE PTR [rcx+0x5],dl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1751: mov    rdx,rax [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1754: shr    rdx,0x30 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1758: mov    BYTE PTR [rcx+0x6],dl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x175b: shr    rax,0x38 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x175f: mov    BYTE PTR [rcx+0x7],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RCX, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1762: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1767: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1768: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
