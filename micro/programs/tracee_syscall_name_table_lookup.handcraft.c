#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 24
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rsi],0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rsi],0x40]
 * - 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rsi],0x40 + jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> to BPF branch]
 * - 0x1129: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112a: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112c: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112e: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1130: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x114a: lea    r10,[rip+0xeaf] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeaf]]
 * - 0x1158: lea    r15,[rip+0x111d] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111d]]
 * - 0x1169: movabs rbp,0x74613274617473 [warning-unmapped: unsupported mnemonic or operand form: movabs rbp,0x74613274617473]
 * - 0x1173: movabs r9,0x647466656e676973 [warning-unmapped: movabs into HC_X86_R9 needs an immediate-load kinsn]
 * - 0x11b3: jmp    rcx [warning-unmapped: cannot parse branch target rcx]
 * - 0x11d9: jmp    rcx [warning-unmapped: cannot parse branch target rcx]
 * - 0x1236: mov    rcx,rbp [warning-unmapped: unsupported mnemonic or operand form: mov    rcx,rbp]
 * - 0x1311: shl    r12,cl [warning-unmapped: shl    r12,cl needs a shadow-aware ALU kinsn]
 * - 0x1344: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1345: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1347: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1349: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x134b: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x134d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    /* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 2),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rdi,[rdx+0x10c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 268), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [bpf-branch: lowered cmp    rdi,rcx + ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rsi],0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rsi],0x40] */
    /* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rsi],0x40 + jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> to BPF branch] */
    /* 0x1129: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112a: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112c: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112e: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1130: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: movabs r14,0x6a09e667f3bcc909 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x6a09e667f3bcc909ULL),
    /* 0x113d: movabs rsi,0x65736f6c63 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x65736f6c63ULL),
    /* 0x1147: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114a: lea    r10,[rip+0xeaf] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeaf]] */
    /* 0x1151: lea    r11,[rsi+0xfa0614] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R11, BPF_REG_2, 0, 0, 1, 0, 16385556), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1158: lea    r15,[rip+0x111d] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111d]] */
    /* 0x115f: movabs r13,0x74616b6e696c6e75 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_7, 0, 0x74616b6e696c6e75ULL),
    /* 0x1169: movabs rbp,0x74613274617473 [warning-unmapped: unsupported mnemonic or operand form: movabs rbp,0x74613274617473] */
    /* 0x1173: movabs r9,0x647466656e676973 [warning-unmapped: movabs into HC_X86_R9 needs an immediate-load kinsn] */
    /* 0x117d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1180: movzx  edi,BYTE PTR [rdx+r8*4+0xc] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_1, BPF_REG_3, BPF_REG_5, 2, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x1186: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_5, 2, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x118c: shl    ecx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x118f: or     ecx,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1191: movzx  eax,WORD PTR [rdx+r8*4+0xe] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_5, 2, 14), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x1197: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x119a: or     eax,ecx [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x119c: cmp    eax,0xd8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 216), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a1: jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0> [bpf-branch: lowered cmp    eax,0xd8 + jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_0, 0, 12, 216),
    /* 0x11a3: cmp    eax,0x9e [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 158), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a8: ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118> [bpf-branch: lowered cmp    eax,0x9e + ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_0, 0, 38, 158),
    /* 0x11aa: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x11ac: movsxd rcx,DWORD PTR [r10+rcx*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, HC_X86_R10, BPF_REG_4, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD_SIB),
    /* 0x11b0: add    rcx,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b3: jmp    rcx [warning-unmapped: cannot parse branch target rcx] */
    /* 0x11b5: mov    ecx,0x72656164 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1919246692),
    /* 0x11ba: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 92, 0),
    /* 0x11bf: nop [padding: padding is not part of BPF semantics] */
    /* 0x11c0: cmp    eax,0x140 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 320), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11c5: jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea> [bpf-branch: lowered cmp    eax,0x140 + jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_0, 0, 13, 320),
    /* 0x11c7: lea    ecx,[rax-0x101] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, -257), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11cd: cmp    ecx,0x22 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11d0: ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102> [bpf-branch: lowered cmp    ecx,0x22 + ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_4, 0, 16, 34),
    /* 0x11d2: movsxd rcx,DWORD PTR [r15+rcx*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_9, BPF_REG_4, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD_SIB),
    /* 0x11d6: add    rcx,r15 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d9: jmp    rcx [warning-unmapped: cannot parse branch target rcx] */
    /* 0x11db: movabs rcx,0x74616e65706f [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x74616e65706fULL),
    /* 0x11e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 77, 0),
    /* 0x11ea: cmp    eax,0x141 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 321), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11ef: je     1246 <tracee_syscall_name_table_lookup_xdp+0x146> [bpf-branch: lowered cmp    eax,0x141 + je     1246 <tracee_syscall_name_table_lookup_xdp+0x146> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_0, 0, 24, 321),
    /* 0x11f1: cmp    eax,0x14c [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 332), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11f6: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [bpf-branch: lowered cmp    eax,0x14c + jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 24, 332),
    /* 0x11f8: mov    ecx,0x78746173 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 2020893043),
    /* 0x11fd: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 69, 0),
    /* 0x1202: cmp    eax,0xd9 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 217), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1207: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [bpf-branch: lowered cmp    eax,0xd9 + jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 19, 217),
    /* 0x1209: movabs rcx,0x646461746567 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x646461746567ULL),
    /* 0x1213: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 63, 0),
    /* 0x1218: cmp    eax,0xca [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 202), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x121d: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [bpf-branch: lowered cmp    eax,0xca + jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 13, 202),
    /* 0x121f: movabs rcx,0x786574756655 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x786574756655ULL),
    /* 0x1229: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 57, 0),
    /* 0x122e: mov    rcx,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1231: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 54, 0),
    /* 0x1236: mov    rcx,rbp [warning-unmapped: unsupported mnemonic or operand form: mov    rcx,rbp] */
    /* 0x1239: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 53, 0),
    /* 0x123e: mov    rcx,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1241: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 50, 0),
    /* 0x1246: mov    ecx,0x706662 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 7366242),
    /* 0x124b: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 48, 0),
    /* 0x1250: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1252: movabs rcx,0x9e3779b185ebca87 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x9e3779b185ebca87ULL),
    /* 0x125c: imul   rax,rcx [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_IMULQ_RR),
    /* 0x1260: xor    r14,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1263: jmp    132f <tracee_syscall_name_table_lookup_xdp+0x22f> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 69, 0),
    /* 0x1268: movabs rcx,0x657663657865 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x657663657865ULL),
    /* 0x1272: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 36, 0),
    /* 0x1277: movabs rcx,0x6469707467 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6469707467ULL),
    /* 0x1281: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 33, 0),
    /* 0x1283: mov    ecx,0x70616d6d [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1885433197),
    /* 0x1288: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 31, 0),
    /* 0x128a: movabs rcx,0x6b6e696c6e75 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c6e75ULL),
    /* 0x1294: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 28, 0),
    /* 0x1296: movabs rcx,0x656e6f6c6355 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x656e6f6c6355ULL),
    /* 0x12a0: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 25, 0),
    /* 0x12a2: movabs rcx,0x347469617755 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x347469617755ULL),
    /* 0x12ac: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 22, 0),
    /* 0x12ae: mov    ecx,0x6e65706f [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1852141679),
    /* 0x12b3: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 20, 0),
    /* 0x12b5: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x12b8: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 17, 0),
    /* 0x12ba: mov    ecx,0x6b726f66 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1802661734),
    /* 0x12bf: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 15, 0),
    /* 0x12c1: mov    ecx,0x74697865 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1953069157),
    /* 0x12c6: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 13, 0),
    /* 0x12c8: mov    rcx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x12cb: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 10, 0),
    /* 0x12cd: movabs rcx,0x6b6e696c55 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c55ULL),
    /* 0x12d7: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 7, 0),
    /* 0x12d9: mov    ecx,0x6b72626b [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1802658411),
    /* 0x12de: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x12e0: mov    ecx,0x69646863 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1768188003),
    /* 0x12e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 3, 0),
    /* 0x12e7: movabs rcx,0x6c74635f68637261 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6c74635f68637261ULL),
    /* 0x12f1: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1300: mov    ebx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1302: xor    rbx,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1305: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1308: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x130b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x130e: mov    r12,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R12, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1311: shl    r12,cl [warning-unmapped: shl    r12,cl needs a shadow-aware ALU kinsn] */
    /* 0x1314: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1316: not    cl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1318: shr    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x131b: shl    eax,0x3 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 3), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x131e: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1320: shl    rdi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x1323: or     rbx,r12 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1326: add    rbx,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1329: xor    rdi,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132c: mov    r14,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x132f: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1332: cmp    r8,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1336: jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> [bpf-branch: lowered cmp    r8,0x40 + jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, -153, 64),
    /* 0x133c: mov    QWORD PTR [rdx],r14 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x133f: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1344: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1345: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1347: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1349: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134b: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
