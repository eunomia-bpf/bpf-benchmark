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
    /* 0x110c: jbe    110f <cilium_socket_lb_service_select_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rdx,[r8+0x610] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 1552), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_MOV64_REG(BPF_REG_7, HC_X86_RCX),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1129: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 64),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1130: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_R8),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 24),
    /* 0x1132: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r12 [exact-kop: pushq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113a: lea    r9,[r8+0x27] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_R8, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113e: movabs rdi,0x243f6a8885a308d3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x243f6a8885a308d3ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_RDI_OFF),
    /* 0x1148: xor    r10d,r10d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114b: jmp    116e <cilium_socket_lb_service_select_xdp+0x6e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (16) - 1, 0),
    /* 0x114d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r11,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1154: movzx  eax,bx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1157: or     rax,r11 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x115a: xor    rdi,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x115d: inc    r10 [exact-kop: incq reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R10, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1160: add    r9,0x18 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1164: cmp    r10,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (142) - 1, 64),
    /* 0x116e: mov    eax,DWORD PTR [r9-0x13] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RAX, HC_X86_R9, -19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1172: movzx  ebx,WORD PTR [r9-0xd] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RBX, HC_X86_R9, -13), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1177: movzx  r11d,BYTE PTR [r9-0xb] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_R9, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x117c: cmp    r11,0x11 [exact-kop: cmp64 reg,imm kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R11, 17), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1180: setne  cl [exact-kop: setcc kop using module shadow flags] */
    HC_KOP(HC_SETCC_PAYLOAD(HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SETNE),
    /* 0x1183: cmp    r11,0x6 [exact-kop: cmp64 reg,imm kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R11, 6), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1187: setne  dl [exact-kop: setcc kop using module shadow flags] */
    HC_KOP(HC_SETCC_PAYLOAD(HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_SETNE),
    /* 0x118a: movzx  r15d,BYTE PTR [r9-0xa] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R15, HC_X86_R9, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118f: test   r15b,0x2 [exact-kop: testb imm kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R15, 2), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1193: mov    ebp,0x0 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RBP, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: cmove  ebp,eax [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_PAYLOAD(HC_X86_RBP, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_CMOVEL),
    /* 0x119b: test   dl,cl [exact-kop: test8 reg,reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RDX),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-41) - 1, 0),
    /* 0x119f: movzx  r12d,WORD PTR [r9-0x9] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R12, HC_X86_R9, -9), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a4: test   r12w,r12w [control-flow-operand: test folded into BPF branch] */
    /* 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, 65535),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-47) - 1, 0),
    /* 0x11aa: mov    r14d,DWORD PTR [r9-0x3] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_R14, HC_X86_R9, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ae: movzx  ecx,WORD PTR [r9-0xf] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RCX, HC_X86_R9, -15), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b3: mov    edx,ecx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b5: shl    edx,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b8: xor    edx,DWORD PTR [r9-0x17] [exact-kop: xor32 memory-source kop] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RDX, HC_X86_R9, -23), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bc: xor    edx,ebx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11be: xor    edx,DWORD PTR [r9-0x7] [exact-kop: xor32 memory-source kop] */
    HC_KOP(HC_X86_MEM_PAYLOAD(HC_X86_RDX, HC_X86_R9, -7), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11c2: movsx  esi,bx [exact-kop: movswl reg kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVSWL),
    /* 0x11c5: cmp    esi,0x752f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11cb: jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> [exact-bpf: jg as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (18) - 1, 29999),
    /* 0x11cd: mov    esi,r15d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RSI, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d0: and    esi,0x2 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSI, 2), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11d3: jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> [exact-bpf: jne as ordinary BPF branch] */
    HC_MOV64_REG(BPF_REG_6, HC_X86_RSI),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (12) - 1, 0),
    /* 0x11d5: mov    eax,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d7: shl    rax,0x10 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11db: movzx  ecx,cx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11de: or     rcx,rax [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e1: add    rdi,rcx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11e4: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-74) - 1, 0),
    /* 0x11e9: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: xor    edx,ebp [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11f2: lea    esi,[r14+r15*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_R14, HC_X86_R15, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f6: add    esi,edx [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11f8: mov    ecx,r11d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fb: and    ecx,0x7 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11fe: inc    ecx [exact-kop: incl reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1200: rol    esi,cl [exact-kop: roll cl kop] */
    HC_KOP(HC_ROTATE_CL_PAYLOAD(HC_X86_RSI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1202: xor    esi,edx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1204: mov    eax,esi [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1206: xor    edx,edx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1208: div    r12d [exact-kop: divl reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R12, 0), MICRO_HANDCRAFT_BPF_X86_DIVL),
    /* 0x120b: inc    edx [exact-kop: incl reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x120d: shl    r15d,0x1d [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R15, 29), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1211: sar    r15d,0x1f [exact-kop: sar32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R15, 31), MICRO_HANDCRAFT_BPF_X86_SARL),
    /* 0x1215: inc    r14d [exact-kop: incl reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R14, 0), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1218: and    r14d,r15d [exact-kop: and32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x121b: xor    r14d,edx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R14, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x121e: mov    eax,ebp [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1220: shl    rax,0x10 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1224: movzx  edx,bx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RDX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1227: shl    rdx,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RDX, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x122b: xor    rdx,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x122e: shl    r14,0x30 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R14, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1232: or     rsi,r14 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1235: mov    eax,r10d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1238: and    eax,0x7 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x123b: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123e: mov    rbx,rsi [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1241: shl    rbx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1244: not    al [exact-kop: not8 reg kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1246: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1248: shr    rsi,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x124b: add    rdi,r11 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x124e: add    rdi,rdx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1251: or     rsi,rbx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1254: xor    rdi,rsi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1257: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-147) - 1, 0),
    /* 0x125c: mov    QWORD PTR [r8],rdi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(HC_X86_RDI, HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x125f: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1264: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1265: pop    r12 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R12, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1267: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R14, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1269: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_X86_R15, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126b: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_X86_RBP, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126c: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
