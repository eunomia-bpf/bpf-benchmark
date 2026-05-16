#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 12
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112f: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1130: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1136: jne    130d <payload_prefix_memcmp_scan_xdp+0x20d> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x116b: jne    11a6 <payload_prefix_memcmp_scan_xdp+0xa6> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1187: jne    11a9 <payload_prefix_memcmp_scan_xdp+0xa9> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x11fc: jne    1242 <payload_prefix_memcmp_scan_xdp+0x142> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1219: jne    1245 <payload_prefix_memcmp_scan_xdp+0x145> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x128e: jne    12dd <payload_prefix_memcmp_scan_xdp+0x1dd> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x12ad: jne    12e0 <payload_prefix_memcmp_scan_xdp+0x1e0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x130d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: ja     130e <payload_prefix_memcmp_scan_xdp+0x20e> [bpf-branch: verifier-visible branch from preceding cmp    rcx,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_4, BPF_REG_3, 228, 0),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1119: ja     130e <payload_prefix_memcmp_scan_xdp+0x20e> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, 223, 0),
    /* 0x111f: lea    rdi,[rcx+0xcc] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 204), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1126: cmp    rdi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1129: ja     130e <payload_prefix_memcmp_scan_xdp+0x20e> [bpf-branch: verifier-visible branch from preceding cmp    rdi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_3, 218, 0),
    /* 0x112f: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1130: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: cmp    DWORD PTR [rsi],0x3 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_2, 0, 3), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1136: jne    130d <payload_prefix_memcmp_scan_xdp+0x20d> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x113c: mov    dl,0x1d [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x113e: mov    dil,0x4 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1141: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1143: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: movzx  esi,BYTE PTR [rcx+rax*1+0xc] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_0, 0, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1155: lea    r9d,[rdx-0x1d] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_3, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1159: lea    r8d,[rdi-0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_1, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x115d: xor    r8b,r9b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1160: xor    r8b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1164: add    r8b,0x11 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1168: cmp    sil,r8b [exact-kinsn: cmpb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x116b: jne    11a6 <payload_prefix_memcmp_scan_xdp+0xa6> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x116d: movzx  esi,BYTE PTR [rcx+rax*1+0xd] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_0, 0, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1172: mov    r8d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1175: xor    r8b,dil [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1178: xor    r8b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x117c: add    r8b,0x11 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1180: add    rax,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1184: cmp    sil,r8b [exact-kinsn: cmpb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1187: jne    11a9 <payload_prefix_memcmp_scan_xdp+0xa9> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1189: add    dl,0x3a [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x118c: add    dil,0x8 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1190: cmp    rax,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1194: jne    1150 <payload_prefix_memcmp_scan_xdp+0x50> [bpf-branch: verifier-visible branch from preceding cmp    rax,0x40; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, -35, 64),
    /* 0x1196: movzx  eax,BYTE PTR [rcx+0x4b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 75), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x119a: movabs rdx,0xf43e9fde8cf6b51c [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0xf43e9fde8cf6b51cULL),
    /* 0x11a4: jmp    11c7 <payload_prefix_memcmp_scan_xdp+0xc7> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 16, 0),
    /* 0x11a6: inc    rax [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11a9: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ab: lea    rax,[rax+rax*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_0, BPF_REG_0, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11af: movabs rdx,0x6a09e667f3bcc909 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0x6a09e667f3bcc909ULL),
    /* 0x11b9: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11bc: movzx  eax,sil [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c0: xor    rax,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11c3: movzx  edx,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c7: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ca: rol    rdx,0x5 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11ce: mov    sil,0x1d [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11d1: mov    dil,0x4 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11d4: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11d6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x11e0: movzx  r8d,BYTE PTR [rcx+rax*1+0x4c] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_5, BPF_REG_4, BPF_REG_0, 0, 76), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e6: lea    r10d,[rsi-0x1d] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R10, BPF_REG_2, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ea: lea    r9d,[rdi-0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_1, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ee: xor    r9b,r10b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11f1: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11f5: add    r9b,0x11 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x11f9: cmp    r8b,r9b [exact-kinsn: cmpb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x11fc: jne    1242 <payload_prefix_memcmp_scan_xdp+0x142> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x11fe: movzx  r8d,BYTE PTR [rcx+rax*1+0x4d] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_5, BPF_REG_4, BPF_REG_0, 0, 77), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1204: mov    r9d,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1207: xor    r9b,dil [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x120a: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x120e: add    r9b,0x11 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1212: add    rax,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1216: cmp    r8b,r9b [exact-kinsn: cmpb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1219: jne    1245 <payload_prefix_memcmp_scan_xdp+0x145> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x121b: add    sil,0x3a [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x121f: add    dil,0x8 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1223: cmp    rax,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1227: jne    11e0 <payload_prefix_memcmp_scan_xdp+0xe0> [bpf-branch: verifier-visible branch from preceding cmp    rax,0x40; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, -35, 64),
    /* 0x1229: movabs rax,0x9e3779b97f4a7c16 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x9e3779b97f4a7c16ULL),
    /* 0x1233: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1236: movzx  eax,BYTE PTR [rcx+0x8b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 139), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x123d: shl    eax,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1240: jmp    125d <payload_prefix_memcmp_scan_xdp+0x15d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 16, 0),
    /* 0x1242: inc    rax [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1245: mov    eax,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1247: lea    rax,[rax+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_0, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x124b: lea    rax,[rdx+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x124f: movzx  edx,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1253: shl    edx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1256: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1259: movzx  eax,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x125d: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1260: rol    rax,0x6 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 6), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1264: mov    dil,0x1d [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1267: mov    r8b,0x4 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x126a: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x126c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1270: movzx  esi,BYTE PTR [rcx+rdx*1+0x8c] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_3, 0, 140), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1278: lea    r10d,[rdi-0x1d] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R10, BPF_REG_1, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x127c: lea    r9d,[r8-0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_5, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1280: xor    r9b,r10b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1283: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1287: add    r9b,0x11 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x128b: cmp    sil,r9b [exact-kinsn: cmpb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x128e: jne    12dd <payload_prefix_memcmp_scan_xdp+0x1dd> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x1290: movzx  esi,BYTE PTR [rcx+rdx*1+0x8d] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_3, 0, 141), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1298: mov    r9d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x129b: xor    r9b,r8b [exact-kinsn: xorb reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x129e: xor    r9b,0xa5 [exact-kinsn: xorb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x12a2: add    r9b,0x11 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x12a6: add    rdx,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12aa: cmp    sil,r9b [exact-kinsn: cmpb reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x12ad: jne    12e0 <payload_prefix_memcmp_scan_xdp+0x1e0> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x12af: add    dil,0x3a [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x12b3: add    r8b,0x8 [exact-kinsn: addb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x12b7: cmp    rdx,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x12bb: jne    1270 <payload_prefix_memcmp_scan_xdp+0x170> [bpf-branch: verifier-visible branch from preceding cmp    rdx,0x40; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_3, 0, -35, 64),
    /* 0x12bd: movabs rdx,0x9e3779b97f4a7c16 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0x9e3779b97f4a7c16ULL),
    /* 0x12c7: or     rdx,0x1 [exact-kinsn: or64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 1), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x12cb: xor    rax,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ce: movzx  edx,BYTE PTR [rcx+0xcb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 203), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d5: shl    edx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d8: add    rdx,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12db: jmp    1301 <payload_prefix_memcmp_scan_xdp+0x201> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 20, 0),
    /* 0x12dd: inc    rdx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x12e0: mov    edx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12e2: lea    rdi,[rdx*8+0x0] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, 0, BPF_REG_3, 3, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12ea: sub    rdi,rdx [exact-kinsn: sub64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x12ed: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12f0: movzx  esi,sil [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f4: shl    esi,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12f7: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12fa: movzx  edx,r9b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12fe: add    rdx,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1301: rol    rdx,0x7 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1305: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1308: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x130d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x130e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
