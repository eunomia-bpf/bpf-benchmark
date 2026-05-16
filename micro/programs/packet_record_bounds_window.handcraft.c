#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 15
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20]
 * - 0x1128: jne    110e <packet_record_bounds_window_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <packet_record_bounds_window_xdp+0xe> to BPF branch]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x18]
 * - 0x112e: jne    110e <packet_record_bounds_window_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <packet_record_bounds_window_xdp+0xe> to BPF branch]
 * - 0x1130: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: movabs r9,0xd6e8feb86659fd93 [warning-unmapped: movabs into HC_X86_R9 needs an immediate-load kinsn]
 * - 0x1177: shl    r9,cl [warning-unmapped: shl    r9,cl needs a shadow-aware ALU kinsn]
 * - 0x1189: shl    r10,cl [warning-unmapped: shl    r10,cl needs a shadow-aware ALU kinsn]
 * - 0x1190: shr    r9,cl [warning-unmapped: shr    r9,cl needs a shadow-aware ALU kinsn]
 * - 0x11d7: je     1150 <packet_record_bounds_window_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11f4: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x11f5: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    /* 0x110c: jbe    110f <packet_record_bounds_window_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <packet_record_bounds_window_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <packet_record_bounds_window_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_record_bounds_window_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x310] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 784), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <packet_record_bounds_window_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_record_bounds_window_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20] */
    /* 0x1128: jne    110e <packet_record_bounds_window_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <packet_record_bounds_window_xdp+0xe> to BPF branch] */
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x18] */
    /* 0x112e: jne    110e <packet_record_bounds_window_xdp+0xe> [warning-unmapped: cannot lower cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <packet_record_bounds_window_xdp+0xe> to BPF branch] */
    /* 0x1130: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: lea    rsi,[rdx+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1137: movabs r9,0xd6e8feb86659fd93 [warning-unmapped: movabs into HC_X86_R9 needs an immediate-load kinsn] */
    /* 0x1141: mov    edi,0x300 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 768),
    /* 0x1146: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1149: jmp    11a4 <packet_record_bounds_window_xdp+0xa4> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 44, 0),
    /* 0x114b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r14,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1154: mov    ecx,ecx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1156: or     rcx,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1159: add    r11,rcx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x115c: movzx  r9d,WORD PTR [rsi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R9, BPF_REG_2, -1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1161: lea    ecx,[rax*4+0x0] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, 0, BPF_REG_0, 2, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1168: and    cl,0x1c [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 28), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x116b: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x116e: xor    rbx,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1171: mov    ecx,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1174: and    cl,0x18 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1177: shl    r9,cl [warning-unmapped: shl    r9,cl needs a shadow-aware ALU kinsn] */
    /* 0x117a: add    r9,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117d: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1180: xor    eax,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1183: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1186: mov    r10,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1189: shl    r10,cl [warning-unmapped: shl    r10,cl needs a shadow-aware ALU kinsn] */
    /* 0x118c: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x118e: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL_RR),
    /* 0x1190: shr    r9,cl [warning-unmapped: shr    r9,cl needs a shadow-aware ALU kinsn] */
    /* 0x1193: or     r9,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1196: add    r8,0x8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119a: add    rsi,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119e: add    rdi,0xffffffffffffffe8 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 18446744073709551592), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a2: je     11ec <packet_record_bounds_window_xdp+0xec> [bpf-branch: lowered flags from add    rdi,0xffffffffffffffe8 + je     11ec <packet_record_bounds_window_xdp+0xec> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_1, 0, 36, 0),
    /* 0x11a4: movzx  r10d,BYTE PTR [rsi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R10, BPF_REG_2, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11a9: and    r10d,0x3 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 3), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11ad: lea    rax,[r10+0x18] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, HC_X86_R10, 0, 0, 1, 0, 24), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11b1: cmp    rdi,rax [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x11b4: jb     1196 <packet_record_bounds_window_xdp+0x96> [bpf-branch: lowered cmp    rdi,rax + jb     1196 <packet_record_bounds_window_xdp+0x96> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLT, BPF_REG_1, BPF_REG_0, -16),
    /* 0x11b6: movzx  eax,BYTE PTR [rsi-0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_2, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ba: mov    ebx,DWORD PTR [rsi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_2, -19), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11bd: mov    r14d,DWORD PTR [rsi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_2, -15), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11c1: mov    ecx,DWORD PTR [rsi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -11), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11c4: movzx  r11d,WORD PTR [rsi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R11, BPF_REG_2, -3), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11c9: add    rbx,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11cc: add    r11,r14 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11cf: add    r11,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d2: mov    ebx,DWORD PTR [rsi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_2, -7), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11d5: test   al,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x11d7: je     1150 <packet_record_bounds_window_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11dd: shl    rcx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11e1: or     rcx,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e4: xor    r11,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11e7: jmp    115c <packet_record_bounds_window_xdp+0x5c> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -72, 0),
    /* 0x11ec: mov    QWORD PTR [rdx],r9 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(HC_X86_R9, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x11ef: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x11f4: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11f5: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x11f7: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
