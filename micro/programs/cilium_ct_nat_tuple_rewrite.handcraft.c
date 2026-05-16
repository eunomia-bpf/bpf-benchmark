#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 31
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20]
 * - 0x1128: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to BPF branch]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x20]
 * - 0x112e: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x20 + jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to BPF branch]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1150: mov    r15d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r15d,ebp]
 * - 0x1153: mov    ebp,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r12d]
 * - 0x1156: mov    r12d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,ebp]
 * - 0x1197: mov    r11d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,ebp]
 * - 0x11b0: shr    r11,cl [warning-unmapped: shr    r11,cl needs a shadow-aware ALU kinsn]
 * - 0x11e5: je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> [warning-unmapped: cannot lower cmp    r10d,0x6 + je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> to BPF branch]
 * - 0x11eb: jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> [warning-unmapped: cannot lower cmp    r10d,0x11 + jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> to BPF branch]
 * - 0x1202: mov    ebp,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r11d]
 * - 0x1205: and    ebp,0x1 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1208: cmovne ebp,r9d [warning-unmapped: cmovne operands are not supported]
 * - 0x1210: xor    bp,WORD PTR [rdi-0x17] [warning-unmapped: ALU destination bp is not in the BPF JIT register file]
 * - 0x122f: test   BYTE PTR [rdi-0x12],0x1 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x1233: jne    1150 <cilium_ct_nat_tuple_rewrite_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x123c: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp]
 * - 0x123f: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx]
 * - 0x1269: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126c: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126e: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1270: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <cilium_ct_nat_tuple_rewrite_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <cilium_ct_nat_tuple_rewrite_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20] */
    /* 0x1128: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to BPF branch] */
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x20] */
    /* 0x112e: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x20 + jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to BPF branch] */
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1138: lea    rdi,[rdx+0x2f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: movabs rsi,0x8ebc6af09c88c6e3 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x8ebc6af09c88c6e3ULL),
    /* 0x1146: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1149: jmp    11d0 <cilium_ct_nat_tuple_rewrite_xdp+0xd0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 66, 0),
    /* 0x114e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1150: mov    r15d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r15d,ebp] */
    /* 0x1153: mov    ebp,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r12d] */
    /* 0x1156: mov    r12d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,ebp] */
    /* 0x1159: rol    r12d,0xb [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R12, HC_X86_R12, 11), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x115d: shl    r14d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1161: xor    r14d,r12d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1164: movzx  r15d,r15w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1168: shl    r10d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x116c: or     ecx,r10d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x116f: xor    ecx,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1172: xor    ecx,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1175: xor    ecx,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1177: shl    r11d,0x1d [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 29), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x117b: sar    r11d,0x1f [exact-kinsn: sar32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 31), MICRO_HANDCRAFT_BPF_X86_SARL),
    /* 0x117f: shl    r9d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1183: xor    r9d,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1186: and    r9d,r11d [exact-kinsn: and32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1189: add    r9d,ecx [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x118c: shl    r9,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1190: mov    r10d,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R10, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1193: shl    rbx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1197: mov    r11d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,ebp] */
    /* 0x119a: or     r11,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x119d: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x11a0: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11a3: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11a6: mov    rbx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11a9: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x11ac: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x11ae: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x11b0: shr    r11,cl [warning-unmapped: shr    r11,cl needs a shadow-aware ALU kinsn] */
    /* 0x11b3: add    rsi,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b6: add    rsi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b9: or     r11,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11bc: xor    rsi,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11bf: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11c2: add    rdi,0x20 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c6: cmp    r8,0x20 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 32), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x11ca: je     1261 <cilium_ct_nat_tuple_rewrite_xdp+0x161> [bpf-branch: lowered cmp    r8,0x20 + je     1261 <cilium_ct_nat_tuple_rewrite_xdp+0x161> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 52, 32),
    /* 0x11d0: movzx  r10d,BYTE PTR [rdi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R10, BPF_REG_1, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11d5: movzx  r9d,WORD PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R9, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11da: movzx  ecx,WORD PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11de: mov    eax,DWORD PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11e1: cmp    r10d,0x6 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R10, 6), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11e5: je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> [warning-unmapped: cannot lower cmp    r10d,0x6 + je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> to BPF branch] */
    /* 0x11e7: cmp    r10d,0x11 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R10, 17), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11eb: jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> [warning-unmapped: cannot lower cmp    r10d,0x11 + jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> to BPF branch] */
    /* 0x11ed: lea    rbx,[rdi-0xb] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_6, BPF_REG_1, 0, 0, 1, 0, -11), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11f1: lea    r14,[rdi-0xf] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_1, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11f5: movzx  r11d,BYTE PTR [rdi-0x11] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -17), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11fa: lea    r15,[rdi-0x1b] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_1, 0, 0, 1, 0, -27), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11fe: lea    r12,[rdi-0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R12, BPF_REG_1, 0, 0, 1, 0, -31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1202: mov    ebp,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r11d] */
    /* 0x1205: and    ebp,0x1 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1208: cmovne ebp,r9d [warning-unmapped: cmovne operands are not supported] */
    /* 0x120c: cmovne r12,r14 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R12, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1210: xor    bp,WORD PTR [rdi-0x17] [warning-unmapped: ALU destination bp is not in the BPF JIT register file] */
    /* 0x1214: mov    r14d,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1217: and    r14d,0x2 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x121b: cmovne r14d,r9d [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMOVNEL),
    /* 0x121f: cmovne r15,rbx [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1223: xor    r14w,WORD PTR [rdi-0x15] [exact-kinsn: xorw memory-source kinsn] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -21), MICRO_HANDCRAFT_BPF_X86_XORW_MEM),
    /* 0x1228: mov    r12d,DWORD PTR [r12] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R12, HC_X86_R12, 0), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x122c: mov    ebx,DWORD PTR [r15] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_9, 0), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x122f: test   BYTE PTR [rdi-0x12],0x1 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x1233: jne    1150 <cilium_ct_nat_tuple_rewrite_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1239: mov    r15d,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x123c: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp] */
    /* 0x123f: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx] */
    /* 0x1241: mov    ebx,r12d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1244: jmp    1156 <cilium_ct_nat_tuple_rewrite_xdp+0x56> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -109, 0),
    /* 0x1249: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: shl    r10,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1254: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1256: or     rax,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1259: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x125c: jmp    11bf <cilium_ct_nat_tuple_rewrite_xdp+0xbf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -59, 0),
    /* 0x1261: mov    QWORD PTR [rdx],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x1264: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1269: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126c: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126e: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1270: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1271: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
