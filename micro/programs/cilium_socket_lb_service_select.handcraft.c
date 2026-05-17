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
    HC_LDX(BPF_W, BPF_REG_5, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    r8,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <cilium_socket_lb_service_select_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_5, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, 1, 0),
    HC_EXIT(),
    /* 0x1118: lea    rdx,[r8+0x610] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 1552), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, 1, 0),
    HC_EXIT(),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x40 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1129: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 8),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 1, 64),
    HC_EXIT(),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x18 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1130: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 12),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 1, 24),
    HC_EXIT(),
    /* 0x1132: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113a: lea    r9,[r8+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_5, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113e: movabs rdi,0x243f6a8885a308d3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x243f6a8885a308d3ULL),
    /* 0x1148: xor    r10d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114b: jmp    116e <cilium_socket_lb_service_select_xdp+0x6e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (18) - 1, 0),
    /* 0x114d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r11,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1154: movzx  eax,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1157: or     rax,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x115a: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x115d: inc    r10 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1160: add    r9,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1164: cmp    r10,0x40 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 1, 64),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (143) - 1, 0),
    /* 0x116e: mov    eax,DWORD PTR [r9-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_R9, -19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1172: movzx  ebx,WORD PTR [r9-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, HC_X86_R9, -13), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1177: movzx  r11d,BYTE PTR [r9-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_R9, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x117c: cmp    r11,0x11 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 17), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1180: setne  cl [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_STACK_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SETNE),
    /* 0x1183: cmp    r11,0x6 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 6), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1187: setne  dl [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_STACK_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_SETNE),
    /* 0x118a: movzx  r15d,BYTE PTR [r9-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, HC_X86_R9, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118f: test   r15b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1193: mov    ebp,0x0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: cmove  ebp,eax [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_ARCH_STACK_PAYLOAD(HC_X86_RBP, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_CMOVEL),
    /* 0x119b: test   dl,cl [absorbed-control-flow: test folded into following ordinary BPF jne] */
    /* 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> [exact-bpf: jne ordinary BPF branch from preceding test] */
    HC_MOV64_REG(BPF_REG_6, BPF_REG_3),
    HC_MOV64_REG(BPF_REG_7, BPF_REG_4),
    HC_ALU64_REG(BPF_AND, BPF_REG_6, BPF_REG_7),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 1, 0),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-45) - 1, 0),
    /* 0x119f: movzx  r12d,WORD PTR [r9-0x9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R12, HC_X86_R9, -9), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a4: test   r12w,r12w [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xffff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, 65535),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-52) - 1, 0),
    /* 0x11aa: mov    r14d,DWORD PTR [r9-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, HC_X86_R9, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ae: movzx  ecx,WORD PTR [r9-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, HC_X86_R9, -15), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b3: mov    edx,ecx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b5: shl    edx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b8: xor    edx,DWORD PTR [r9-0x17] [exact-kinsn: xor32 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, HC_X86_R9, -23), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bc: xor    edx,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11be: xor    edx,DWORD PTR [r9-0x7] [exact-kinsn: xor32 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, HC_X86_R9, -7), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11c2: movsx  esi,bx [exact-kinsn: movswl reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVSWL),
    /* 0x11c5: cmp    esi,0x752f [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11cb: jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (17) - 1, 29999),
    /* 0x11cd: mov    esi,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d0: and    esi,0x2 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11d3: jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> [exact-bpf: jne ordinary BPF branch from preceding and] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_2, 0, (12) - 1, -1),
    /* 0x11d5: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d7: shl    rax,0x10 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11db: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11de: or     rcx,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e1: add    rdi,rcx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11e4: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-77) - 1, 0),
    /* 0x11e9: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: xor    edx,ebp [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_3, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11f2: lea    esi,[r14+r15*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_8, BPF_REG_9, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f6: add    esi,edx [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11f8: mov    ecx,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fb: and    ecx,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11fe: inc    ecx [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1200: rol    esi,cl [exact-kinsn: roll cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1202: xor    esi,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1204: mov    eax,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1206: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1208: div    r12d [exact-kinsn: divl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_DIVL),
    /* 0x120b: inc    edx [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x120d: shl    r15d,0x1d [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 29), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1211: sar    r15d,0x1f [exact-kinsn: sar32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 31), MICRO_HANDCRAFT_BPF_X86_SARL),
    /* 0x1215: inc    r14d [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1218: and    r14d,r15d [exact-kinsn: and32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x121b: xor    r14d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x121e: mov    eax,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_0, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1220: shl    rax,0x10 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1224: movzx  edx,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1227: shl    rdx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x122b: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x122e: shl    r14,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1232: or     rsi,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1235: mov    eax,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1238: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x123b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123e: mov    rbx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1241: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1244: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1246: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1248: shr    rsi,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x124b: add    rdi,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x124e: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1251: or     rsi,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1254: xor    rdi,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1257: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-150) - 1, 0),
    /* 0x125c: mov    QWORD PTR [r8],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, BPF_REG_5, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x125f: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1264: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1265: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1267: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1269: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126b: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126c: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
