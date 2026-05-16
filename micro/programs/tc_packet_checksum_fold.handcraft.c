#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (((__u64)(DST) << 4) | ((__u64)(BASE) << 8) | ((__u64)(INDEX) << 12) | \
     ((__u64)(SCALE) << 16) | ((__u64)(HAS_INDEX) << 18) | \
     ((__u64)(HAS_BASE) << 19) | ((__u64)(__u32)(DISP) << 20))
#define HC_LEA_TMP_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP, TMP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | \
     (__u64)(TMP))

/*
 * native asm to handcraft warnings: 4
 *
 * - 0x1100: mov    rax,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1136: cmp    DWORD PTR [rax+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rax+0x8],0x20]
 * - 0x113c: cmp    DWORD PTR [rax+0xc],0x200 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rax+0xc],0x200]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rax,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_0, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: cmp    rax,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110a: jbe    1121 <tc_packet_checksum_fold_prog+0x21> [bpf-branch: lowered cmp    rax,rcx + jbe    1121 <tc_packet_checksum_fold_prog+0x21> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_0, BPF_REG_4, 7),
    /* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff [bpf-jit: immediate memory store] */
    HC_ST(BPF_W, BPF_REG_1, 16, 4294967295),
    /* 0x1113: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1118: mov    edx,0xffffffff [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 4294967295),
    /* 0x111d: mov    DWORD PTR [rdi+0x14],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 20), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM_REG),
    /* 0x1120: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x1121: lea    rdx,[rax+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_TMP_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 8, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1125: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1128: ja     110c <tc_packet_checksum_fold_prog+0xc> [bpf-branch: lowered cmp    rdx,rcx + ja     110c <tc_packet_checksum_fold_prog+0xc> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -11),
    /* 0x112a: lea    rdx,[rax+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_TMP_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 1040, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1131: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1134: ja     110c <tc_packet_checksum_fold_prog+0xc> [bpf-branch: lowered cmp    rdx,rcx + ja     110c <tc_packet_checksum_fold_prog+0xc> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -16),
    /* 0x1136: cmp    DWORD PTR [rax+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rax+0x8],0x20] */
    /* 0x113a: jne    110c <tc_packet_checksum_fold_prog+0xc> [bpf-branch: lowered cmp    DWORD PTR [rax+0x8],0x20 + jne    110c <tc_packet_checksum_fold_prog+0xc> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_0, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -18, 32),
    /* 0x113c: cmp    DWORD PTR [rax+0xc],0x200 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rax+0xc],0x200] */
    /* 0x1143: jne    110c <tc_packet_checksum_fold_prog+0xc> [bpf-branch: lowered cmp    DWORD PTR [rax+0xc],0x200 + jne    110c <tc_packet_checksum_fold_prog+0xc> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_0, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -20, 512),
    /* 0x1145: xor    esi,esi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_2, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1147: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1149: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: xor    ecx,ecx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_4, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1152: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1155: data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: movzx  r9d,WORD PTR [rax+rcx*2+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(HC_X86_R9, BPF_REG_0, BPF_REG_4, 1, 16), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x1166: add    r9d,r8d [exact-kinsn: add32 reg kinsn; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1169: movzx  r8d,r9w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x116d: shr    r9d,0x10 [exact-kinsn: shr32 imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1171: add    r9d,r8d [exact-kinsn: add32 reg kinsn; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1174: movzx  r8d,WORD PTR [rax+rcx*2+0x12] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_5, BPF_REG_0, BPF_REG_4, 1, 18), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x117a: add    r8d,r9d [exact-kinsn: add32 reg kinsn; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R9, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x117d: movzx  r9d,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1181: shr    r8d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 16, 0), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1185: add    r8d,r9d [exact-kinsn: add32 reg kinsn; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R9, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1188: add    rcx,0x2 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 2, 0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x118c: cmp    rcx,0x200 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 512), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1193: jne    1160 <tc_packet_checksum_fold_prog+0x60> [bpf-branch: lowered cmp    rcx,0x200 + jne    1160 <tc_packet_checksum_fold_prog+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -24, 512),
    /* 0x1195: mov    ecx,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1198: shr    ecx,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 16, 0), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x119b: add    ecx,r8d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_5, 0, 0), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x119e: not    ecx [exact-kinsn: notl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTL_R),
    /* 0x11a0: movzx  r8d,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11a4: mov    ecx,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x11a6: shl    ecx,0x4 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 4, 0), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11a9: shl    r8,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_5, BPF_REG_4, 0, 0),
    /* 0x11ac: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11af: inc    esi [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x11b1: cmp    esi,0x20 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 32), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11b4: jne    1150 <tc_packet_checksum_fold_prog+0x50> [bpf-branch: lowered cmp    esi,0x20 + jne    1150 <tc_packet_checksum_fold_prog+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_2, 0, -49, 32),
    /* 0x11b6: mov    DWORD PTR [rdi+0x10],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM_REG),
    /* 0x11b9: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32, 0), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11bd: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0, 0, 0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bf: mov    DWORD PTR [rdi+0x14],edx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 20), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM_REG),
    /* 0x11c2: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
