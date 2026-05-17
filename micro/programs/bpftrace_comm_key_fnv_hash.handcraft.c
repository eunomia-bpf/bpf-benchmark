#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 1
 *
 * - 0x1152: movabs r10,0x100000001b3 [warning-unmapped: movabs into HC_X86_R10 needs a machine-level immediate-load kinsn]
 */

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    r8,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_5, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    r8,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> [exact-kinsn: jbe branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(15, 1, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JBE),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1116: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-20, -10, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1118: lea    rdx,[r8+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1122: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-kinsn: ja branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(-53, -22, 0, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JA),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_5, 8, 32), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1129: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-83, -29, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x20 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_5, 12, 32), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1130: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-112, -36, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1132: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113b: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113c: mov    QWORD PTR [rsp-0x40],r8 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_5, HC_X86_RSP, -64), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1141: lea    rdi,[r8+0x2f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_5, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1145: movabs rsi,0x94d049bb133111eb [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 10723151780598845931ULL),
    /* 0x114f: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1152: movabs r10,0x100000001b3 [warning-unmapped: movabs into HC_X86_R10 needs a machine-level immediate-load kinsn] */
    /* 0x115c: jmp    11af <bpftrace_comm_key_fnv_hash_xdp+0xaf> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(133, 81, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x115e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1160: shl    r12d,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1164: shl    r15d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1168: or     r15d,r12d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x116b: shl    ebx,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x116e: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1171: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1173: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1176: mov    rdx,r11 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1179: shl    rdx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x117c: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x117e: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1180: shr    r11,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1183: or     ebx,r15d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1186: or     ebx,r9d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1189: or     r11,rdx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x118c: mov    rax,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x118f: xor    rax,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1192: shl    r14,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1196: mov    esi,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: or     rsi,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x119b: add    rsi,rax [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119e: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11a1: add    rdi,0x20 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a5: cmp    r8,0x20 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 32), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11a9: je     13da <bpftrace_comm_key_fnv_hash_xdp+0x2da> [exact-kinsn: je branch kinsn; verifier proof from preceding cmp] */
    HC_KINSN(HC_X86_BRANCH_PROOF_PAYLOAD(912, 555, 1, 0, HC_X86_BRANCH_PROOF_CMP_RR), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x11af: mov    QWORD PTR [rsp-0x8],r8 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_5, HC_X86_RSP, -8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11b4: movzx  r13d,BYTE PTR [rdi-0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11b9: movzx  r9d,BYTE PTR [rdi-0x1e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_1, -30), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11be: movzx  eax,BYTE PTR [rdi-0x1d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -29), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c2: movzx  edx,BYTE PTR [rdi-0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, -28), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c6: movzx  ebp,BYTE PTR [rdi-0x1b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_1, -27), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ca: movzx  ecx,BYTE PTR [rdi-0x1a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -26), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ce: mov    QWORD PTR [rsp-0x10],rcx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_4, HC_X86_RSP, -16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11d3: movzx  ecx,BYTE PTR [rdi-0x19] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -25), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d7: mov    QWORD PTR [rsp-0x18],rcx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_4, HC_X86_RSP, -24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11dc: movzx  r8d,BYTE PTR [rdi-0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_1, -24), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e1: movzx  r14d,BYTE PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e6: movzx  r12d,BYTE PTR [rdi-0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R12, BPF_REG_1, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11eb: movzx  r15d,BYTE PTR [rdi-0x15] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -21), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f0: movzx  ebx,BYTE PTR [rdi-0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -20), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f4: mov    r11,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11f7: movabs rcx,0xcbf29ce484222325 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 14695981039346656037ULL),
    /* 0x1201: xor    r11,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1204: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1208: mov    QWORD PTR [rsp-0x38],r9 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R9, HC_X86_RSP, -56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x120d: xor    r11,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1210: mov    r9,r8 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1213: mov    r8,QWORD PTR [rsp-0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, HC_X86_RSP, -24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1218: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x121c: mov    QWORD PTR [rsp-0x28],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, -40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1221: xor    r11,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1224: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1228: mov    QWORD PTR [rsp-0x30],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, HC_X86_RSP, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x122d: xor    r11,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1230: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1234: mov    QWORD PTR [rsp-0x20],rbp [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_RBP, HC_X86_RSP, -32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1239: xor    r11,rbp [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x123c: mov    rbp,QWORD PTR [rsp-0x10] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RSP, -16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1241: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1245: xor    r11,rbp [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1248: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x124c: xor    r11,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x124f: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1253: xor    r11,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1256: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x125a: mov    QWORD PTR [rsp-0x48],r14 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_8, HC_X86_RSP, -72), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x125f: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1262: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1266: xor    r11,r12 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1269: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x126d: xor    r11,r15 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1270: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1274: mov    r14,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1277: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x127a: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x127e: movzx  r11d,BYTE PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1283: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1286: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x128a: movzx  r14d,BYTE PTR [rdi-0xe] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x128f: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1292: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1296: movzx  r11d,BYTE PTR [rdi-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x129b: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x129e: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12a2: movzx  r14d,BYTE PTR [rdi-0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12a7: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12aa: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ae: movzx  r11d,BYTE PTR [rdi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12b3: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12b6: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ba: movzx  r14d,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12bf: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12c2: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12c6: movzx  r11d,BYTE PTR [rdi-0x9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12cb: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ce: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12d2: movzx  r14d,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d7: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12da: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12de: movzx  r11d,BYTE PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e3: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12e6: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ea: movzx  r14d,BYTE PTR [rdi-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ef: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12f2: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12f6: movzx  r11d,BYTE PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12fb: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12fe: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1302: movzx  r14d,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1307: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x130a: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x130e: movzx  r11d,BYTE PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1313: xor    r11,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1316: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x131a: movzx  r14d,BYTE PTR [rdi-0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x131f: xor    r14,r11 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1322: imul   r14,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1326: movzx  ecx,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x132a: xor    rcx,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132d: imul   rcx,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1331: movzx  r11d,BYTE PTR [rdi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1335: xor    r11,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1338: movzx  r14d,BYTE PTR [rdi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x133d: imul   r11,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1341: test   r14b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_8, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1345: jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250> [exact-kinsn: jne branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(22, 9, 0), MICRO_HANDCRAFT_BPF_X86_JNE),
    /* 0x1347: mov    r9,QWORD PTR [rsp-0x48] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSP, -72), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x134c: jmp    13b1 <bpftrace_comm_key_fnv_hash_xdp+0x2b1> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(121, 99, 0), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x134e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1350: shl    r9d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1354: shl    r8d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1358: shl    ebp,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x135b: mov    rax,QWORD PTR [rsp-0x28] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, -40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1360: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1364: mov    rcx,QWORD PTR [rsp-0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, HC_X86_RSP, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1369: shl    rcx,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x136d: mov    rdx,QWORD PTR [rsp-0x38] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, HC_X86_RSP, -56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1372: shl    rdx,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1376: shl    r13,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x137a: or     r13,rdx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x137d: or     r13,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1380: or     r13,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1383: or     r13,rbp [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_7, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1386: or     r13,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1389: or     r13,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x138c: or     r13,QWORD PTR [rsp-0x20] [exact-kinsn: or64 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_7, HC_X86_RSP, -32), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1391: mov    r9,QWORD PTR [rsp-0x48] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSP, -72), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1396: mov    eax,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1399: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x139b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x139e: mov    rdx,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13a1: shl    rdx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13a4: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13a6: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13a8: shr    r13,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13ab: or     r13,rdx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13ae: xor    r11,r13 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13b1: test   r14b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x13b5: mov    r8,QWORD PTR [rsp-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, HC_X86_RSP, -8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ba: je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [exact-kinsn: je branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-981, -608, 1), MICRO_HANDCRAFT_BPF_X86_JE),
    /* 0x13c0: movabs rax,0x9e3779b185ebca87 [exact-bpf: movabs via BPF_LD_IMM64; x86 JIT emits movabs] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 11400714785074694791ULL),
    /* 0x13ca: add    rax,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13cd: cmp    BYTE PTR [rdi-0xf],0x70 [exact-kinsn: cmp memory,imm kinsn] */
    HC_KINSN(HC_X86_CMP_MEM_IMM_PAYLOAD(BPF_REG_1, -15, 112), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x13d1: cmove  r11,rax [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_CMOVEQ),
    /* 0x13d5: jmp    1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [exact-kinsn: jmp branch kinsn] */
    HC_KINSN(HC_X86_BRANCH_PAYLOAD(-1029, -634, 1), MICRO_HANDCRAFT_BPF_X86_JMP),
    /* 0x13da: mov    rax,QWORD PTR [rsp-0x40] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, -64), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13df: mov    QWORD PTR [rax],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13e2: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e7: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13e8: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13ea: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13ec: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13ee: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13f0: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13f1: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
