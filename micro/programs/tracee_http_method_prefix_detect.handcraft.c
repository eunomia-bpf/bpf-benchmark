#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 2
 *
 * - 0x1148: lea    rsi,[rip+0xeb1] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeb1]]
 * - 0x1176: jmp    r11 [warning-unmapped: needs a machine-level x86 indirect-branch kinsn for target r11]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(15, 9, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-5, -18, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1118: lea    rsi,[rdx+0x90] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 144), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-11, -30, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_3, 8, 8), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-15, -36, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_3, 12, 16), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-19, -42, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1130: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1134: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: lea    rax,[rdx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_3, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1139: movabs rbx,0xa0761d6478bd642f [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 11562461410679940143ULL),
    /* 0x1143: mov    ecx,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1148: lea    rsi,[rip+0xeb1] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeb1]] */
    /* 0x114f: nop [padding: padding is not part of BPF semantics] */
    /* 0x1150: mov    rdi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1153: movzx  r8d,BYTE PTR [rax-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_0, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1158: movzx  r9d,BYTE PTR [rax-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_0, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x115d: lea    r11d,[r8-0x44] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R11, BPF_REG_5, 0, 0, 1, 0, -68), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1161: cmp    r11d,0xc [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 12), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1165: ja     12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(977, 320, 1, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x116b: movzx  r10d,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x116f: movsxd r11,DWORD PTR [rsi+r11*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R11, BPF_REG_2, HC_X86_R11, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD),
    /* 0x1173: add    r11,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1176: jmp    r11 [warning-unmapped: needs a machine-level x86 indirect-branch kinsn for target r11] */
    /* 0x1179: cmp    r9b,0x45 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x117d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(918, 297, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1183: mov    r9b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1186: cmp    BYTE PTR [rax-0x4],0x4c [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 76), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x118a: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(879, 284, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1190: cmp    BYTE PTR [rax-0x3],0x45 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1194: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(848, 274, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x119a: cmp    BYTE PTR [rax-0x2],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x119e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(817, 264, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11a4: cmp    BYTE PTR [rax-0x1],0x45 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -1, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11a8: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(786, 254, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11ae: mov    bl,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11b0: cmp    BYTE PTR [rax],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, 0, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11b3: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(754, 243, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11b9: mov    r10d,0x4 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11bf: mov    r9b,0x4c [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 76), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11c2: mov    r11b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11c5: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(744, 241, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x11ca: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11d0: cmp    r10d,0x54 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 84), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11d4: je     1275 <tracee_http_method_prefix_detect_xdp+0x175> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(483, 151, 1, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x11da: cmp    r10d,0x45 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11de: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(666, 206, 1, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11e4: mov    r9b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11e7: cmp    BYTE PTR [rax-0x4],0x41 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 65), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11eb: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(626, 193, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11f1: cmp    BYTE PTR [rax-0x3],0x44 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 68), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11f5: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(595, 183, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11fb: mov    r11b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11fe: cmp    BYTE PTR [rax-0x2],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1202: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(556, 170, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1208: mov    r10d,0x5 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x120e: mov    r9b,0x41 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 65), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1211: mov    bl,0x44 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 68), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1213: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(553, 169, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1218: cmp    r9b,0x45 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x121c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(506, 144, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1222: mov    r9b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1225: cmp    BYTE PTR [rax-0x4],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1229: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(467, 131, 1), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x122f: mov    r11b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1232: cmp    BYTE PTR [rax-0x3],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1236: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(428, 122, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x123c: mov    r10d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1242: jmp    12af <tracee_http_method_prefix_detect_xdp+0x1af> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(397, 107, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1244: cmp    r10d,0x55 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 85), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1248: je     1297 <tracee_http_method_prefix_detect_xdp+0x197> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(292, 77, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x124a: cmp    r10d,0x4f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 79), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x124e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(356, 102, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1250: mov    r9b,0x4f [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1253: cmp    BYTE PTR [rax-0x4],0x53 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 83), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1257: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(316, 93, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1259: cmp    BYTE PTR [rax-0x3],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x125d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(285, 87, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x125f: mov    r11b,0x4f [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1262: cmp    BYTE PTR [rax-0x2],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1266: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(246, 78, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1268: mov    r10d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x126e: mov    r9b,0x53 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 83), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1271: mov    bl,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1273: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(243, 80, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1275: mov    r9b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1278: cmp    BYTE PTR [rax-0x4],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x127c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(189, 56, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x127e: cmp    BYTE PTR [rax-0x3],0x50 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 80), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1282: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(158, 50, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1284: cmp    BYTE PTR [rax-0x2],0x2f [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 47), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1288: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(127, 44, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x128a: mov    r10d,0x6 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1290: mov    bl,0x50 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 80), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1292: mov    r11b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1295: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(124, 46, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1297: mov    r9b,0x55 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x129a: cmp    BYTE PTR [rax-0x4],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x129e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(70, 22, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x12a0: mov    r11b,0x55 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12a3: cmp    BYTE PTR [rax-0x3],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x12a7: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(31, 13, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x12a9: mov    r10d,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12af: mov    r9b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12b2: mov    bl,0x20 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12b4: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(28, 15, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12b6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x12c0: mov    r11d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c3: movzx  r9d,BYTE PTR [rax-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_0, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12c8: movzx  ebx,BYTE PTR [rax-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12cc: xor    r10d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12cf: movzx  ebx,bl [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d2: lea    r14d,[r10+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, HC_X86_R10, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12d6: lea    r15,[rcx+0xa] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_4, 0, 0, 1, 0, 10), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12da: imul   r14,r15 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12de: add    rdi,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12e1: shl    rbx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x12e5: movzx  r9d,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e9: shl    r9d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12ed: movzx  r11d,r11b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f1: shl    r11d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12f5: shl    r8d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12f9: or     r8d,r11d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12fc: or     r8d,r9d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12ff: or     r8,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1302: mov    ebx,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1305: or     rbx,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1308: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x130b: xor    rbx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x130e: add    rax,0x10 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1312: inc    rcx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1315: cmp    rcx,0x9 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 9), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1319: jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-230, -442, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x131f: mov    BYTE PTR [rdx],dil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1322: mov    BYTE PTR [rdx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_6, BPF_REG_3, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1325: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1327: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x132a: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x132d: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x132f: shr    eax,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1332: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1335: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1338: shr    rax,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x133c: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x133f: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1342: shr    rax,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1346: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1349: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x134c: shr    rax,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1350: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1353: shr    rbx,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1357: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x135a: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x135f: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1360: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1362: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1364: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
