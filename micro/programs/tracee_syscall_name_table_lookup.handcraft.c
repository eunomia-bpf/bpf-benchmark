#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 6
 *
 * - 0x114a: lea    r10,[rip+0xeaf] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeaf]]
 * - 0x1158: lea    r15,[rip+0x111d] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111d]]
 * - 0x1169: movabs rbp,0x74613274617473 [warning-unmapped: movabs into HC_X86_RBP needs a machine-level immediate-load kinsn]
 * - 0x1173: movabs r9,0x647466656e676973 [warning-unmapped: movabs into HC_X86_R9 needs a machine-level immediate-load kinsn]
 * - 0x11b3: jmp    rcx [warning-unmapped: needs a machine-level x86 indirect-branch kinsn for target rcx]
 * - 0x11d9: jmp    rcx [warning-unmapped: needs a machine-level x86 indirect-branch kinsn for target rcx]
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
    /* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(15, 1, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-20, -10, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1118: lea    rdi,[rdx+0x10c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 268), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-53, -22, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1124: cmp    DWORD PTR [rsi],0x40 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 0, 64), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-83, -27, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1129: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112a: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112c: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112e: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1130: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: movabs r14,0x6a09e667f3bcc909 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 7640891576956012809ULL),
    /* 0x113d: movabs rsi,0x65736f6c63 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 435728378979ULL),
    /* 0x1147: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114a: lea    r10,[rip+0xeaf] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeaf]] */
    /* 0x1151: lea    r11,[rsi+0xfa0614] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R11, BPF_REG_2, 0, 0, 1, 0, 16385556), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1158: lea    r15,[rip+0x111d] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111d]] */
    /* 0x115f: movabs r13,0x74616b6e696c6e75 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_7, 0, 8386102103099862645ULL),
    /* 0x1169: movabs rbp,0x74613274617473 [warning-unmapped: movabs into HC_X86_RBP needs a machine-level immediate-load kinsn] */
    /* 0x1173: movabs r9,0x647466656e676973 [warning-unmapped: movabs into HC_X86_R9 needs a machine-level immediate-load kinsn] */
    /* 0x117d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1180: movzx  edi,BYTE PTR [rdx+r8*4+0xc] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_3, BPF_REG_5, 2, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1186: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_5, 2, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118c: shl    ecx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x118f: or     ecx,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1191: movzx  eax,WORD PTR [rdx+r8*4+0xe] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_5, 2, 14), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1197: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x119a: or     eax,ecx [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x119c: cmp    eax,0xd8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 216), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11a1: jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0> [exact-kinsn: jg branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(71, 29, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JG),
    /* 0x11a3: cmp    eax,0x9e [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 158), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11a8: ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(207, 110, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x11aa: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ac: movsxd rcx,DWORD PTR [r10+rcx*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_4, HC_X86_R10, BPF_REG_4, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD),
    /* 0x11b0: add    rcx,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b3: jmp    rcx [warning-unmapped: needs a machine-level x86 indirect-branch kinsn for target rcx] */
    /* 0x11b5: mov    ecx,0x72656164 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1919246692), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ba: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(294, 321, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x11bf: nop [padding: padding is not part of BPF semantics] */
    /* 0x11c0: cmp    eax,0x140 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 320), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11c5: jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea> [exact-kinsn: jg branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(52, 35, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JG),
    /* 0x11c7: lea    ecx,[rax-0x101] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, -257), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11cd: cmp    ecx,0x22 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11d0: ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(83, 48, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x11d2: movsxd rcx,DWORD PTR [r15+rcx*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_4, BPF_REG_9, BPF_REG_4, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD),
    /* 0x11d6: add    rcx,r15 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d9: jmp    rcx [warning-unmapped: needs a machine-level x86 indirect-branch kinsn for target rcx] */
    /* 0x11db: movabs rcx,0x74616e65706f [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 127961812791407ULL),
    /* 0x11e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(225, 278, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x11ea: cmp    eax,0x141 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 321), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11ef: je     1246 <tracee_syscall_name_table_lookup_xdp+0x146> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(142, 85, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x11f1: cmp    eax,0x14c [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 332), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11f6: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(113, 88, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x11f8: mov    ecx,0x78746173 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2020893043), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fd: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(161, 254, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1202: cmp    eax,0xd9 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 217), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1207: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(80, 71, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1209: movabs rcx,0x646461746567 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 110382294525287ULL),
    /* 0x1213: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(127, 232, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1218: cmp    eax,0xca [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 202), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x121d: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(46, 49, 0, 1, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x121f: movabs rcx,0x786574756655 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 132377140880981ULL),
    /* 0x1229: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(93, 210, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x122e: mov    rcx,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1231: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(84, 202, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1236: mov    rcx,rbp [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1239: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(75, 194, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x123e: mov    rcx,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1241: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(66, 186, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1246: mov    ecx,0x706662 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 7366242), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124b: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(64, 176, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1250: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1252: movabs rcx,0x9e3779b185ebca87 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 11400714785074694791ULL),
    /* 0x125c: imul   rax,rcx [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1260: xor    r14,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1263: jmp    132f <tracee_syscall_name_table_lookup_xdp+0x22f> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(125, 199, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1268: movabs rcx,0x657663657865 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 111559148140645ULL),
    /* 0x1272: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(48, 137, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1277: movabs rcx,0x6469707467 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 431265707111ULL),
    /* 0x1281: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(45, 125, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1283: mov    ecx,0x70616d6d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1885433197), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1288: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(43, 118, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x128a: movabs rcx,0x6b6e696c6e75 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 118121959288437ULL),
    /* 0x1294: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(40, 106, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x1296: movabs rcx,0x656e6f6c6355 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 111524990182229ULL),
    /* 0x12a0: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(37, 94, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12a2: movabs rcx,0x347469617755 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 57674588845909ULL),
    /* 0x12ac: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(34, 82, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12ae: mov    ecx,0x6e65706f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1852141679), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b3: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(32, 75, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12b5: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12b8: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(23, 70, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12ba: mov    ecx,0x6b726f66 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802661734), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12bf: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(21, 63, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12c1: mov    ecx,0x74697865 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1953069157), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c6: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(19, 56, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12c8: mov    rcx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12cb: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(10, 51, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12cd: movabs rcx,0x6b6e696c55 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 461413903445ULL),
    /* 0x12d7: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(7, 39, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12d9: mov    ecx,0x6b72626b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802658411), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12de: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(5, 32, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12e0: mov    ecx,0x69646863 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1768188003), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(3, 25, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x12e7: movabs rcx,0x6c74635f68637261 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 7814980514819043937ULL),
    /* 0x12f1: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1300: mov    ebx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1302: xor    rbx,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1305: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1308: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x130b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x130e: mov    r12,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1311: shl    r12,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1314: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1316: not    cl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1318: shr    rbx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x131b: shl    eax,0x3 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 3), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x131e: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1320: shl    rdi,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1323: or     rbx,r12 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1326: add    rbx,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1329: xor    rdi,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132c: mov    r14,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x132f: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1332: cmp    r8,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1336: jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> [exact-kinsn: jne branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-507, -444, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x133c: mov    QWORD PTR [rdx],r14 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_8, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x133f: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1344: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1345: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1347: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1349: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x134b: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x134d: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x134e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
