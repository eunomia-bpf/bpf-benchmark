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
    /* 0x110c: jbe    110f <flow_record_field_scan_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <flow_record_field_scan_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-5) - 1, 0),
    /* 0x1118: lea    rdi,[rdx+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RDI, HC_X86_RDX, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <flow_record_field_scan_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDI_OFF),
    HC_LDX(BPF_DW, BPF_REG_7, BPF_REG_10, HC_X86_SHADOW_RCX_OFF),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-10) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1127: jne    110e <flow_record_field_scan_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RSI_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-13) - 1, 32),
    /* 0x1129: cmp    DWORD PTR [rdx+0xc],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112d: jne    110e <flow_record_field_scan_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDX_OFF),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-16) - 1, 32),
    /* 0x112f: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1130: movabs r8,0x9e3779b97f4a7c15 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b97f4a7c15ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, HC_X86_SHADOW_R8_OFF),
    /* 0x113a: xor    esi,esi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RSI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x113c: xor    edi,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x113e: jmp    117e <flow_record_field_scan_xdp+0x7e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (43) - 1, 0),
    /* 0x1140: mov    ecx,edi [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1142: and    cl,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1145: shr    r10,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1148: xor    r9,r10 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x114b: add    r9,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x114e: mov    ecx,esi [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1150: and    cl,0x18 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RCX, 24), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1153: mov    r8,rax [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R8, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1156: shl    r8,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1159: xor    r8,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x115c: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x115e: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1161: mov    rbx,r8 [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RBX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1164: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1167: not    al [exact-kinsn: not8 reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1169: mov    ecx,eax [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x116b: shr    r8,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x116e: or     r8,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R8, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1171: inc    rdi [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RDI, 0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1174: add    rsi,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSI, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1178: cmp    rdi,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x117c: je     11c6 <flow_record_field_scan_xdp+0xc6> [exact-bpf: je as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RDI_OFF),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (39) - 1, 32),
    /* 0x117e: mov    r10,QWORD PTR [rdx+rsi*4+0x20] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R10, HC_X86_RDX, HC_X86_RSI, 2, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1183: mov    rcx,QWORD PTR [rdx+rsi*4+0x18] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RCX, HC_X86_RDX, HC_X86_RSI, 2, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1188: add    rcx,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_RCX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x118b: mov    eax,DWORD PTR [rdx+rsi*4+0x28] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RAX, HC_X86_RDX, HC_X86_RSI, 2, 40), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x118f: shl    rax,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1193: mov    r9d,DWORD PTR [rdx+rsi*4+0x2c] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R9, HC_X86_RDX, HC_X86_RSI, 2, 44), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: or     r9,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x119b: mov    eax,DWORD PTR [rdx+rsi*4+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RAX, HC_X86_RDX, HC_X86_RSI, 2, 16), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119f: mov    r11,rax [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a2: shl    r11,0x10 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11a6: movzx  ebx,WORD PTR [rdx+rsi*4+0x14] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RBX, HC_X86_RDX, HC_X86_RSI, 2, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11ab: or     r11,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11ae: xor    r11,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11b1: add    r11,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b4: test   bl,0x1 [control-flow-operand: test folded into BPF branch] */
    /* 0x11b7: je     1140 <flow_record_field_scan_xdp+0x40> [exact-bpf: je as ordinary BPF branch] */
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, HC_X86_SHADOW_RBX_OFF),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, 1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-72) - 1, 0),
    /* 0x11b9: movzx  ecx,WORD PTR [rdx+rsi*4+0x16] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_RCX, HC_X86_RDX, HC_X86_RSI, 2, 22), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11be: add    r9,rcx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c1: xor    r9,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11c4: jmp    114e <flow_record_field_scan_xdp+0x4e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-69) - 1, 0),
    /* 0x11c6: mov    BYTE PTR [rdx],r8b [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R8, HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11c9: mov    BYTE PTR [rdx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(HC_X86_RBX, HC_X86_RDX, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11cc: mov    eax,ebx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ce: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x11d1: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11d4: mov    eax,ebx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d6: shr    eax,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x11d9: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11dc: mov    rax,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11df: shr    rax,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11e3: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11e6: mov    rax,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11e9: shr    rax,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11ed: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11f0: mov    rax,rbx [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11f3: shr    rax,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RAX, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11f7: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11fa: shr    rbx,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RBX, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11fe: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RBX, HC_X86_RDX, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1201: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1206: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_X86_RBX, MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1207: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
