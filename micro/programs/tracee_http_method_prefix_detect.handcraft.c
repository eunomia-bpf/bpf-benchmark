#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 35
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1134: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1136: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1138: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x114c: lea    rsi,[rip+0xead] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xead]]
 * - 0x1186: jmp    r11 [warning-unmapped: cannot parse branch target r11]
 * - 0x118d: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x119a: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11a4: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11ae: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11b8: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11c3: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11fb: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1205: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1212: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x122c: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1239: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1246: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1267: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x126d: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1276: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x128c: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1292: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1298: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x12ae: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x12b7: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x136f: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1370: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1372: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1374: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    /* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> [bpf-branch: verifier-visible branch from preceding cmp    rdx,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, 1, 0),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, -6, 0),
    /* 0x1118: lea    rsi,[rdx+0x90] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 144), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rcx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, -11, 0),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_3, 8, 8), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_3, 12, 16), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1134: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1136: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1138: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: lea    rax,[rdx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_3, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113d: movabs rbx,0xa0761d6478bd642f [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xa0761d6478bd642fULL),
    /* 0x1147: mov    ecx,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x114c: lea    rsi,[rip+0xead] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xead]] */
    /* 0x1153: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: mov    rdi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1163: movzx  r8d,BYTE PTR [rax-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_0, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1168: movzx  r9d,BYTE PTR [rax-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_0, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x116d: lea    r11d,[r8-0x44] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R11, BPF_REG_5, 0, 0, 1, 0, -68), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1171: cmp    r11d,0xc [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 12), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1175: ja     12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [bpf-branch: verifier-visible branch from preceding cmp    r11d,0xc; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, HC_X86_R11, 0, 118, 12),
    /* 0x117b: movzx  r10d,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x117f: movsxd r11,DWORD PTR [rsi+r11*4] [exact-kinsn: movsxd SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R11, BPF_REG_2, HC_X86_R11, 2, 0), MICRO_HANDCRAFT_BPF_X86_MOVSXD),
    /* 0x1183: add    r11,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1186: jmp    r11 [warning-unmapped: cannot parse branch target r11] */
    /* 0x1189: cmp    r9b,0x45 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x118d: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1193: mov    r9b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1196: cmp    BYTE PTR [rax-0x4],0x4c [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 76), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x119a: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11a0: cmp    BYTE PTR [rax-0x3],0x45 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11a4: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11aa: cmp    BYTE PTR [rax-0x2],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11ae: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11b4: cmp    BYTE PTR [rax-0x1],0x45 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -1, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11b8: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11be: mov    bl,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11c0: cmp    BYTE PTR [rax],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, 0, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11c3: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11c9: mov    r10d,0x4 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11cf: mov    r9b,0x4c [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 76), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11d2: mov    r11b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11d5: jmp    12df <tracee_http_method_prefix_detect_xdp+0x1df> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 97, 0),
    /* 0x11da: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11e0: cmp    r10d,0x54 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 84), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11e4: je     1285 <tracee_http_method_prefix_detect_xdp+0x185> [bpf-branch: verifier-visible branch from preceding cmp    r10d,0x54; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, HC_X86_R10, 0, 56, 84),
    /* 0x11ea: cmp    r10d,0x45 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11ee: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [bpf-branch: verifier-visible branch from preceding cmp    r10d,0x45; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, HC_X86_R10, 0, 83, 69),
    /* 0x11f4: mov    r9b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11f7: cmp    BYTE PTR [rax-0x4],0x41 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 65), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11fb: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1201: cmp    BYTE PTR [rax-0x3],0x44 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 68), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1205: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x120b: mov    r11b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x120e: cmp    BYTE PTR [rax-0x2],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1212: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1218: mov    r10d,0x5 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x121e: mov    r9b,0x41 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 65), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1221: mov    bl,0x44 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 68), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1223: jmp    12df <tracee_http_method_prefix_detect_xdp+0x1df> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 74, 0),
    /* 0x1228: cmp    r9b,0x45 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x122c: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1232: mov    r9b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1235: cmp    BYTE PTR [rax-0x4],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1239: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x123f: mov    r11b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1242: cmp    BYTE PTR [rax-0x3],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1246: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x124c: mov    r10d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1252: jmp    12bf <tracee_http_method_prefix_detect_xdp+0x1bf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 48, 0),
    /* 0x1254: cmp    r10d,0x55 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 85), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1258: je     12a7 <tracee_http_method_prefix_detect_xdp+0x1a7> [bpf-branch: verifier-visible branch from preceding cmp    r10d,0x55; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, HC_X86_R10, 0, 35, 85),
    /* 0x125a: cmp    r10d,0x4f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 79), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x125e: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [bpf-branch: verifier-visible branch from preceding cmp    r10d,0x4f; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, HC_X86_R10, 0, 47, 79),
    /* 0x1260: mov    r9b,0x4f [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1263: cmp    BYTE PTR [rax-0x4],0x53 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 83), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1267: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1269: cmp    BYTE PTR [rax-0x3],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x126d: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x126f: mov    r11b,0x4f [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1272: cmp    BYTE PTR [rax-0x2],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1276: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1278: mov    r10d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127e: mov    r9b,0x53 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 83), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1281: mov    bl,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1283: jmp    12df <tracee_http_method_prefix_detect_xdp+0x1df> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 38, 0),
    /* 0x1285: mov    r9b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1288: cmp    BYTE PTR [rax-0x4],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x128c: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x128e: cmp    BYTE PTR [rax-0x3],0x50 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 80), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1292: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1294: cmp    BYTE PTR [rax-0x2],0x2f [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -2, 47), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1298: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x129a: mov    r10d,0x6 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12a0: mov    bl,0x50 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 80), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12a2: mov    r11b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12a5: jmp    12df <tracee_http_method_prefix_detect_xdp+0x1df> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 23, 0),
    /* 0x12a7: mov    r9b,0x55 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12aa: cmp    BYTE PTR [rax-0x4],0x54 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -4, 84), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x12ae: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x12b0: mov    r11b,0x55 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12b3: cmp    BYTE PTR [rax-0x3],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_0, -3, 32), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x12b7: jne    12d0 <tracee_http_method_prefix_detect_xdp+0x1d0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x12b9: mov    r10d,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12bf: mov    r9b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12c2: mov    bl,0x20 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12c4: jmp    12df <tracee_http_method_prefix_detect_xdp+0x1df> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 8, 0),
    /* 0x12c6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x12d0: mov    r11d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12d3: movzx  r9d,BYTE PTR [rax-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_0, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d8: movzx  ebx,BYTE PTR [rax-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12dc: xor    r10d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12df: movzx  ebx,bl [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e2: lea    r14d,[r10+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, HC_X86_R10, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12e6: lea    r15,[rcx+0xa] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_4, 0, 0, 1, 0, 10), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12ea: imul   r14,r15 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ee: add    rdi,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12f1: shl    rbx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x12f5: movzx  r9d,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f9: shl    r9d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12fd: movzx  r11d,r11b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1301: shl    r11d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1305: shl    r8d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1309: or     r8d,r11d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x130c: or     r8d,r9d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x130f: or     r8,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1312: mov    ebx,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1315: or     rbx,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1318: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x131b: xor    rbx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x131e: add    rax,0x10 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1322: inc    rcx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1325: cmp    rcx,0x9 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 9), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1329: jne    1160 <tracee_http_method_prefix_detect_xdp+0x60> [bpf-branch: verifier-visible branch from preceding cmp    rcx,0x9; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -180, 9),
    /* 0x132f: mov    BYTE PTR [rdx],dil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_1, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1332: mov    BYTE PTR [rdx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_6, BPF_REG_3, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1335: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1337: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x133a: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x133d: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x133f: shr    eax,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1342: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1345: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1348: shr    rax,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x134c: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x134f: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1352: shr    rax,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1356: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1359: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x135c: shr    rax,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1360: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1363: shr    rbx,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1367: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x136a: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x136f: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1370: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1372: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1374: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1375: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
