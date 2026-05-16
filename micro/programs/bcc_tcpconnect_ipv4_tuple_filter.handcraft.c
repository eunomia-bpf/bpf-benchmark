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
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20]
 * - 0x1128: jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> to BPF branch]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x18]
 * - 0x112e: jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> to BPF branch]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1184: mov    r9d,0x2 [warning-unmapped: movl immediate into HC_X86_R9 needs an immediate-load kinsn]
 * - 0x119e: mov    r9d,0x3 [warning-unmapped: movl immediate into HC_X86_R9 needs an immediate-load kinsn]
 * - 0x11b2: setge  r9b [warning-unmapped: setge needs SF/OF shadow-flag support]
 * - 0x11bc: mov    r9d,0x1 [warning-unmapped: movl immediate into HC_X86_R9 needs an immediate-load kinsn]
 * - 0x11e4: movzx  ebp,BYTE PTR [rsi-0x2] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11e8: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11ec: je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11f5: je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1226: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp]
 * - 0x1244: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x12a7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x12a8: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x12aa: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x12ac: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    /* 0x110c: jbe    110f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x310] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 784), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20] */
    /* 0x1128: jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> to BPF branch] */
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x18] */
    /* 0x112e: jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe> to BPF branch] */
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1136: lea    rsi,[rdx+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113a: movabs r8,0xa0761d6478bd642f [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 0xa0761d6478bd642fULL),
    /* 0x1144: xor    edi,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1146: jmp    116d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x6d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 15, 0),
    /* 0x1148: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    rcx,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1154: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1156: or     rax,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1159: xor    r8,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x115c: inc    rdi [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x115f: add    rsi,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1163: cmp    rdi,0x20 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 32), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1167: je     129f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x19f> [bpf-branch: lowered cmp    rdi,0x20 + je     129f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x19f> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_1, 0, 127, 32),
    /* 0x116d: movzx  eax,WORD PTR [rsi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_2, -5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1171: cmp    eax,0x1f8f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 8079), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1176: jg     1190 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x90> [bpf-branch: lowered cmp    eax,0x1f8f + jg     1190 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x90> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_0, 0, 7, 8079),
    /* 0x1178: cmp    eax,0x50 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 80), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x117b: je     11bc <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xbc> [bpf-branch: lowered cmp    eax,0x50 + je     11bc <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xbc> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_0, 0, 20, 80),
    /* 0x117d: cmp    eax,0x1bb [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 443), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1182: jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6> [bpf-branch: lowered cmp    eax,0x1bb + jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 8, 443),
    /* 0x1184: mov    r9d,0x2 [warning-unmapped: movl immediate into HC_X86_R9 needs an immediate-load kinsn] */
    /* 0x118a: jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 16, 0),
    /* 0x118c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1190: cmp    eax,0x1f90 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 8080), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1195: je     119e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x9e> [bpf-branch: lowered cmp    eax,0x1f90 + je     119e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x9e> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_0, 0, 3, 8080),
    /* 0x1197: cmp    eax,0x20fb [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 8443), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x119c: jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6> [bpf-branch: lowered cmp    eax,0x20fb + jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 1, 8443),
    /* 0x119e: mov    r9d,0x3 [warning-unmapped: movl immediate into HC_X86_R9 needs an immediate-load kinsn] */
    /* 0x11a4: jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 9, 0),
    /* 0x11a6: movsx  ecx,ax [exact-kinsn: movswl reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVSWL),
    /* 0x11a9: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11ac: cmp    ecx,0x7530 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 30000), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11b2: setge  r9b [warning-unmapped: setge needs SF/OF shadow-flag support] */
    /* 0x11b6: shl    r9d,0x2 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11ba: jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 0, 0),
    /* 0x11bc: mov    r9d,0x1 [warning-unmapped: movl immediate into HC_X86_R9 needs an immediate-load kinsn] */
    /* 0x11c2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11d0: mov    ebx,DWORD PTR [rsi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_2, -23), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d3: movzx  ecx,BYTE PTR [rsi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d7: cmp    ecx,0x2 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11da: jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50> [bpf-branch: lowered cmp    ecx,0x2 + jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -50, 2),
    /* 0x11e0: mov    r10d,DWORD PTR [rsi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R10, BPF_REG_2, -19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e4: movzx  ebp,BYTE PTR [rsi-0x2] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11e8: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11ec: je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11f2: test   r9d,r9d [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x11f5: je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11fb: mov    ecx,DWORD PTR [rsi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fe: movzx  r14d,BYTE PTR [rsi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_2, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1203: movzx  r15d,BYTE PTR [rsi-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1208: rol    ecx,0x7 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_4, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x120b: xor    ecx,DWORD PTR [rsi-0xf] [exact-kinsn: xorl memory-source kinsn] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -15), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x120e: movzx  r11d,WORD PTR [rsi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R11, BPF_REG_2, -1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1213: shl    r15d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1217: shl    r14d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x121b: or     r14d,r15d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x121e: movzx  eax,ax [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1221: xor    eax,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1224: xor    eax,ecx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1226: mov    ecx,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,ebp] */
    /* 0x1228: shl    ecx,0x1e [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 30), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x122b: sar    ecx,0x1f [exact-kinsn: sar32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_SARL),
    /* 0x122e: lea    r14d,[r10+rbx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, HC_X86_R10, BPF_REG_6, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1232: and    r14d,ecx [exact-kinsn: and32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1235: xor    r14d,r11d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1238: xor    r14d,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x123b: lea    ecx,[r9+0x3] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, HC_X86_R9, 0, 0, 1, 0, 3), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123f: mov    eax,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1242: rol    eax,cl [exact-kinsn: roll cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1244: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x1248: cmove  eax,r14d [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_CMOVEL),
    /* 0x124c: shl    rax,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1250: mov    ebx,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1252: or     rbx,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1255: mov    eax,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1257: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1259: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x125c: mov    r14,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x125f: shl    r14,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x1262: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1264: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1266: shr    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1269: or     rbx,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x126c: xor    rbx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x126f: shl    r9,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1273: shl    r11d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1277: or     r11,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x127a: mov    r8d,r10d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127d: xor    r8,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1280: add    r8,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1283: jmp    115c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -127, 0),
    /* 0x1288: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1290: shl    r10,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1294: or     r10,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1297: add    r8,r10 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x129a: jmp    115c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -134, 0),
    /* 0x129f: mov    QWORD PTR [rdx],r8 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_5, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12a2: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x12a7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12a8: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12aa: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12ac: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12ad: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
