#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 6
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20]
 * - 0x1128: jne    110e <packet_checksum_fold_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <packet_checksum_fold_xdp+0xe> to BPF branch]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x200 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x200]
 * - 0x1131: jne    110e <packet_checksum_fold_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x200 + jne    110e <packet_checksum_fold_xdp+0xe> to BPF branch]
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
    /* 0x110c: jbe    110f <packet_checksum_fold_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <packet_checksum_fold_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <packet_checksum_fold_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_checksum_fold_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <packet_checksum_fold_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_checksum_fold_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20] */
    /* 0x1128: jne    110e <packet_checksum_fold_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <packet_checksum_fold_xdp+0xe> to BPF branch] */
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x200 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x200] */
    /* 0x1131: jne    110e <packet_checksum_fold_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x200 + jne    110e <packet_checksum_fold_xdp+0xe> to BPF branch] */
    /* 0x1133: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1135: xor    esi,esi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1137: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: mov    ecx,0x13 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 19),
    /* 0x1145: xor    edi,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1147: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: movzx  r8d,WORD PTR [rdx+rcx*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_5, BPF_REG_3, BPF_REG_4, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x1156: add    r8d,edi [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1159: movzx  edi,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x115d: shr    r8d,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1161: add    r8d,edi [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1164: movzx  edi,WORD PTR [rdx+rcx*1-0x1] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_1, BPF_REG_3, BPF_REG_4, 0, -1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x1169: add    edi,r8d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x116c: movzx  r8d,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1170: shr    edi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1173: add    edi,r8d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1176: add    rcx,0x4 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117a: cmp    rcx,0x413 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 1043), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1181: jne    1150 <packet_checksum_fold_xdp+0x50> [bpf-branch: lowered cmp    rcx,0x413 + jne    1150 <packet_checksum_fold_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -25, 1043),
    /* 0x1183: mov    ecx,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1185: shr    ecx,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1188: add    ecx,edi [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x118a: not    ecx [exact-kinsn: notl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTL_R),
    /* 0x118c: movzx  edi,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x118f: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1191: shl    ecx,0x4 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1194: shl    rdi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x1197: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x119a: inc    eax [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_0, 0, 0, 1),
    /* 0x119c: cmp    eax,0x20 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x119f: jne    1140 <packet_checksum_fold_xdp+0x40> [bpf-branch: lowered cmp    eax,0x20 + jne    1140 <packet_checksum_fold_xdp+0x40> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, -49, 32),
    /* 0x11a1: mov    QWORD PTR [rdx],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x11a4: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x11a9: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
