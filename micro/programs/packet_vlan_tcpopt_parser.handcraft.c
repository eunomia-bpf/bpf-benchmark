#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 1
 *
 * - 0x131c: movabs r9,0x144000000 [warning-unmapped: movabs into HC_X86_R9 needs a machine-level immediate-load kinsn]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    r10,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, HC_X86_R10, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(829, 306, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1112: lea    rcx,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rcx,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1119: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(796, 293, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x111f: lea    r9,[rdx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_3, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    r9,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1126: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(756, 280, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x112c: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112d: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112f: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: movzx  eax,WORD PTR [rdx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1136: rol    ax,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x113a: movzx  ecx,ax [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x113d: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x113f: cmp    ecx,0x800 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1145: je     11df <packet_vlan_tcpopt_parser_xdp+0xdf> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(355, 148, 1, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x114b: cmp    ecx,0x88a8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 34984), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1151: je     115f <packet_vlan_tcpopt_parser_xdp+0x5f> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(45, 12, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x1153: cmp    ecx,0x8100 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 33024), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1159: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(628, 223, 1, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x115f: lea    r9,[rdx+0x1a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_3, 0, 0, 1, 0, 26), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1163: cmp    r9,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1166: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(588, 210, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x116c: movzx  esi,WORD PTR [rdx+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_3, 22), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1170: movzx  ecx,WORD PTR [rdx+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1174: rol    si,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1178: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x117c: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x117f: cmp    ecx,0x800 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1185: je     1245 <packet_vlan_tcpopt_parser_xdp+0x145> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(555, 186, 1, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x118b: cmp    ecx,0x88a8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 34984), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1191: je     119f <packet_vlan_tcpopt_parser_xdp+0x9f> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(45, 12, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x1193: cmp    ecx,0x8100 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 33024), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1199: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(481, 159, 1, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x119f: lea    rcx,[rdx+0x1e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 30), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11a3: cmp    rcx,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11a6: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(448, 146, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x11ac: movzx  ecx,WORD PTR [rdx+0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 28), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b0: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11b4: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b7: cmp    ecx,0x800 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11bd: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(405, 127, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11bf: lea    rcx,[rdx+0x32] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 50), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11c3: cmp    rcx,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11c6: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(372, 118, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x11c8: lea    r9,[rdx+0x1e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_3, 0, 0, 1, 0, 30), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11cc: movzx  ecx,WORD PTR [rdx+0x1a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 26), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d0: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11d4: movzx  r8d,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d8: mov    ecx,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11dd: jmp    11ef <packet_vlan_tcpopt_parser_xdp+0xef> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(44, 16, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x11df: xor    esi,esi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e1: xor    ecx,ecx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e3: lea    rdi,[r9+0x14] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, HC_X86_R9, 0, 0, 1, 0, 20), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11e7: cmp    rdi,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11ea: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(307, 82, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x11ec: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11ef: movzx  edi,BYTE PTR [r9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, HC_X86_R9, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f3: mov    r11d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f6: and    r11b,0xf0 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R11, 240), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x11fa: cmp    r11b,0x40 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 64), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11fe: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(247, 62, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1200: and    edi,0xf [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1203: cmp    dil,0x5 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 5), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1207: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jb branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(214, 53, 0), MICRO_HANDCRAFT_BPF_X86_JB),
    /* 0x1209: lea    rbx,[r9+rdi*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_6, HC_X86_R9, BPF_REG_1, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x120d: cmp    rbx,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1210: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(176, 44, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1212: cmp    BYTE PTR [r9+0x9],0x6 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(HC_X86_R9, 9, 6), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1217: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(144, 37, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1219: lea    r14,[rbx+0x14] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_6, 0, 0, 1, 0, 20), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x121d: cmp    r14,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1220: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(112, 28, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1222: movzx  r11d,BYTE PTR [rbx+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_6, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1227: cmp    r11,0x50 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 80), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x122b: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jb branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(70, 17, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JB),
    /* 0x122d: shr    r11d,0x2 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 2), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1231: and    r11d,0xfffffffc [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, -4), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1235: lea    r15,[rbx+r11*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_6, HC_X86_R11, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1239: cmp    r15,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x123c: jbe    124c <packet_vlan_tcpopt_parser_xdp+0x14c> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(28, 14, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x123e: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x123f: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1241: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1243: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1244: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x1245: mov    ecx,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124a: jmp    11e3 <packet_vlan_tcpopt_parser_xdp+0xe3> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-346, -105, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x124c: lea    r15,[rbx+0x20] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_6, 0, 0, 1, 0, 32), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1250: cmp    r15,r10 [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1253: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-33, -23, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1255: cmp    r11b,0x20 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1259: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jb branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-66, -29, 0), MICRO_HANDCRAFT_BPF_X86_JB),
    /* 0x125b: cmp    BYTE PTR [r14],0x2 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_8, 0, 2), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x125f: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-96, -35, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1261: cmp    BYTE PTR [rbx+0x15],0x4 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_6, 21, 4), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1265: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jb branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-127, -41, 0), MICRO_HANDCRAFT_BPF_X86_JB),
    /* 0x1267: cmp    BYTE PTR [rbx+0x18],0x1 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_6, 24, 1), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x126b: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-157, -47, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x126d: cmp    BYTE PTR [rbx+0x19],0x3 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_6, 25, 3), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1271: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-188, -53, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1273: cmp    BYTE PTR [rbx+0x1a],0x3 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_6, 26, 3), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1277: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jb branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-219, -59, 0), MICRO_HANDCRAFT_BPF_X86_JB),
    /* 0x1279: cmp    BYTE PTR [rbx+0x1c],0x4 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_6, 28, 4), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x127d: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-249, -65, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x127f: cmp    BYTE PTR [rbx+0x1d],0x2 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_6, 29, 2), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1283: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jb branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-280, -71, 0), MICRO_HANDCRAFT_BPF_X86_JB),
    /* 0x1285: cmp    BYTE PTR [rbx+0x1e],0x1 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_6, 30, 1), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1289: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-310, -77, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x128b: shl    rdi,0x2 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x128f: movzx  eax,WORD PTR [r9+0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1294: rol    ax,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1298: movzx  eax,ax [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x129b: mov    r10d,DWORD PTR [r9+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, HC_X86_R9, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x129f: bswap  r10d [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x12a2: mov    r9d,DWORD PTR [r9+0x10] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12a6: bswap  r9d [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x12a9: movzx  ebp,WORD PTR [rbx] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_6, 0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12ac: movzx  r14d,WORD PTR [rbx+0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12b1: rol    bp,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x12b5: movzx  r15d,bp [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_9, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12b9: add    r15,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12bc: rol    r14w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x12c1: movzx  eax,r14w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12c5: add    rax,r15 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12c8: xor    rax,r10 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12cb: add    rax,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12ce: movzx  r9d,BYTE PTR [rbx+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_6, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d3: mov    r10d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12d6: shl    r10d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12da: movzx  r14d,BYTE PTR [rbx+0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_6, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12df: or     r10d,r14d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12e2: add    r10,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12e6: shl    r9d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12ea: xor    r9,r10 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ed: shl    r14d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12f1: add    r9,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12f4: add    r9,0x30100 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 196864), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12fb: movzx  r10d,BYTE PTR [rbx+0x1b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_6, 27), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1300: mov    r14,r10 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1303: shl    r14,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1307: shl    r10d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130b: xor    r10,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x130e: xor    r10,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1311: movzx  ebx,BYTE PTR [rbx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_6, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1315: shl    rbx,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1319: or     rbx,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x131c: movabs r9,0x144000000 [warning-unmapped: movabs into HC_X86_R9 needs a machine-level immediate-load kinsn] */
    /* 0x1326: add    r9,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1329: shl    esi,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x132c: or     rsi,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x132f: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1332: mov    rax,rcx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1335: shl    rax,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1339: shl    edi,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x133c: or     rdi,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x133f: or     rdi,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1342: movabs rax,0x600000000 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 25769803776ULL),
    /* 0x134c: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x134f: add    ecx,0x5 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 5), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1352: rol    r9,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(HC_X86_R9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1355: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1358: xor    r9,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x135b: mov    QWORD PTR [rdx],r9 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R9, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x135e: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1363: jmp    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-624, -298, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
};

HC_EXPORT_PROGRAM(program)
