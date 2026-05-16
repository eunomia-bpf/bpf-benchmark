#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 20
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1129: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112a: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112d: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112f: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x114d: lea    r10,[rip+0xeac] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeac]]
 * - 0x115b: lea    r12,[rip+0x111a] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111a]]
 * - 0x11b3: jmp    rcx [warning-unmapped: cannot parse branch target rcx]
 * - 0x11d9: jmp    rcx [warning-unmapped: cannot parse branch target rcx]
 * - 0x1345: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1346: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1348: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x134a: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x134c: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x134e: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> [bpf-branch: verifier-visible branch from preceding cmp    rdx,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, 1, 0),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, -6, 0),
    /* 0x1118: lea    rdi,[rdx+0x10c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 268), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [bpf-branch: verifier-visible branch from preceding cmp    rdi,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_4, -11, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x40 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 0, 64), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1129: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112a: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112d: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112f: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1136: movabs r14,0x6a09e667f3bcc909 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x6a09e667f3bcc909ULL),
    /* 0x1140: movabs rsi,0x65736f6c63 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x65736f6c63ULL),
    /* 0x114a: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114d: lea    r10,[rip+0xeac] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeac]] */
    /* 0x1154: lea    r11,[rsi+0xfa0614] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R11, BPF_REG_2, 0, 0, 1, 0, 16385556), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x115b: lea    r12,[rip+0x111a] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111a]] */
    /* 0x1162: movabs rbx,0x74613274617473 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74613274617473ULL),
    /* 0x116c: movabs r15,0x647466656e676973 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_9, 0, 0x647466656e676973ULL),
    /* 0x1176: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
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
    /* 0x11a1: jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0> [bpf-branch: verifier-visible branch from preceding cmp    eax,0xd8; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, 12, 216),
    /* 0x11a3: cmp    eax,0x9e [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 158), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11a8: ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118> [bpf-branch: verifier-visible branch from preceding cmp    eax,0x9e; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_0, 0, 39, 158),
    /* 0x11aa: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ac: movsxd rcx,DWORD PTR [r10+rcx*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_4, HC_X86_R10, BPF_REG_4, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD),
    /* 0x11b0: add    rcx,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11b3: jmp    rcx [warning-unmapped: cannot parse branch target rcx] */
    /* 0x11b5: mov    ecx,0x72656164 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1919246692), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ba: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 101, 0),
    /* 0x11bf: nop [padding: padding is not part of BPF semantics] */
    /* 0x11c0: cmp    eax,0x140 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 320), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11c5: jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea> [bpf-branch: verifier-visible branch from preceding cmp    eax,0x140; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, 12, 320),
    /* 0x11c7: lea    ecx,[rax-0x101] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, -257), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11cd: cmp    ecx,0x22 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11d0: ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102> [bpf-branch: verifier-visible branch from preceding cmp    ecx,0x22; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_4, 0, 16, 34),
    /* 0x11d2: movsxd rcx,DWORD PTR [r12+rcx*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_4, HC_X86_R12, BPF_REG_4, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD),
    /* 0x11d6: add    rcx,r12 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d9: jmp    rcx [warning-unmapped: cannot parse branch target rcx] */
    /* 0x11db: movabs rcx,0x74616e65706f [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x74616e65706fULL),
    /* 0x11e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 86, 0),
    /* 0x11ea: cmp    eax,0x141 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 321), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11ef: je     124d <tracee_syscall_name_table_lookup_xdp+0x14d> [bpf-branch: verifier-visible branch from preceding cmp    eax,0x141; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, 27, 321),
    /* 0x11f1: cmp    eax,0x14c [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 332), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11f6: jne    1257 <tracee_syscall_name_table_lookup_xdp+0x157> [bpf-branch: verifier-visible branch from preceding cmp    eax,0x14c; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, 27, 332),
    /* 0x11f8: mov    ecx,0x78746173 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2020893043), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fd: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 77, 0),
    /* 0x1202: cmp    eax,0xd9 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 217), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1207: jne    1257 <tracee_syscall_name_table_lookup_xdp+0x157> [bpf-branch: verifier-visible branch from preceding cmp    eax,0xd9; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, 21, 217),
    /* 0x1209: movabs rcx,0x646461746567 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x646461746567ULL),
    /* 0x1213: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 71, 0),
    /* 0x1218: cmp    eax,0xca [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 202), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x121d: jne    1257 <tracee_syscall_name_table_lookup_xdp+0x157> [bpf-branch: verifier-visible branch from preceding cmp    eax,0xca; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, 15, 202),
    /* 0x121f: movabs rcx,0x786574756655 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x786574756655ULL),
    /* 0x1229: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 65, 0),
    /* 0x122e: movabs rcx,0x74616b6e696c6e75 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x74616b6e696c6e75ULL),
    /* 0x1238: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 62, 0),
    /* 0x123d: mov    rcx,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1240: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 59, 0),
    /* 0x1245: mov    rcx,r15 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1248: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 56, 0),
    /* 0x124d: mov    ecx,0x706662 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 7366242), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1252: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 53, 0),
    /* 0x1257: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1259: movabs rcx,0x9e3779b185ebca87 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x9e3779b185ebca87ULL),
    /* 0x1263: imul   rax,rcx [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1267: xor    r14,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x126a: jmp    1330 <tracee_syscall_name_table_lookup_xdp+0x230> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 78, 0),
    /* 0x126f: movabs rcx,0x657663657865 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x657663657865ULL),
    /* 0x1279: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 41, 0),
    /* 0x127e: movabs rcx,0x6469707467 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6469707467ULL),
    /* 0x1288: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 38, 0),
    /* 0x128a: mov    ecx,0x70616d6d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1885433197), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x128f: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 35, 0),
    /* 0x1291: movabs rcx,0x6b6e696c6e75 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c6e75ULL),
    /* 0x129b: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 32, 0),
    /* 0x129d: movabs rcx,0x656e6f6c6355 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x656e6f6c6355ULL),
    /* 0x12a7: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 29, 0),
    /* 0x12a9: movabs rcx,0x347469617755 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x347469617755ULL),
    /* 0x12b3: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 26, 0),
    /* 0x12b5: mov    ecx,0x6e65706f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1852141679), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ba: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 23, 0),
    /* 0x12bc: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12bf: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 20, 0),
    /* 0x12c1: mov    ecx,0x6b726f66 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802661734), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c6: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 17, 0),
    /* 0x12c8: mov    ecx,0x74697865 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1953069157), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12cd: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 14, 0),
    /* 0x12cf: mov    rcx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12d2: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 11, 0),
    /* 0x12d4: movabs rcx,0x6b6e696c55 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c55ULL),
    /* 0x12de: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 8, 0),
    /* 0x12e0: mov    ecx,0x6b72626b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802658411), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x12e7: mov    ecx,0x69646863 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1768188003), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ec: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 2, 0),
    /* 0x12ee: movabs rcx,0x6c74635f68637261 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6c74635f68637261ULL),
    /* 0x12f8: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1300: mov    r13d,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_7, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1303: xor    r13,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1306: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1309: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x130c: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x130f: mov    r9,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1312: shl    r9,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1315: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1317: not    cl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1319: shr    r13,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x131c: shl    eax,0x3 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 3), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x131f: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1321: shl    rdi,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1324: or     r13,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1327: add    r13,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x132a: xor    rdi,r13 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132d: mov    r14,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1330: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1333: cmp    r8,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1337: jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> [bpf-branch: verifier-visible branch from preceding cmp    r8,0x40; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, -169, 64),
    /* 0x133d: mov    QWORD PTR [rdx],r14 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_8, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1340: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1345: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1346: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1348: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134a: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134c: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134e: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134f: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
