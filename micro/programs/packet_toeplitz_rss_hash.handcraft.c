#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 32
 *
 * - 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1146: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1147: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1149: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1154: lea    r9,[rip+0xea5] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xea5]]
 * - 0x115b: lea    r10,[rip+0xed2] [warning-unmapped: LEA operands are not representable]
 * - 0x1162: lea    r11,[rip+0xeff] [warning-unmapped: LEA operands are not representable]
 * - 0x1170: xor    eax,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x11a5: movzx  ebp,BYTE PTR [rcx] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11ad: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11af: test   bpl,bpl [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11b2: jns    1172 <packet_toeplitz_rss_hash_xdp+0x72> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11b6: mov    ebp,DWORD PTR [r10+rdx*4] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [r10+rdx*4]]
 * - 0x11ba: or     ebp,DWORD PTR [r9+rdx*4] [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11c0: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11c2: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11c4: mov    r14d,DWORD PTR [r11+rdx*4] [warning-unmapped: memory base r11 is not in the BPF JIT register file]
 * - 0x11d1: or     ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11e2: movzx  r9d,BYTE PTR [rsi+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11e7: movzx  r10d,BYTE PTR [rsi+0x2d] [warning-unmapped: destination register r10d is not in the BPF JIT register file]
 * - 0x11ec: mov    r11,rax [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rax]
 * - 0x11ef: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11fc: or     rdi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x120a: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x120e: or     r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1211: shl    r10,0x20 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1215: or     rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1218: or     rdx,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x123c: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x123d: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x123f: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> [bpf-branch: lowered cmp    rsi,rcx + jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_2, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -4),
    /* 0x1118: lea    rdx,[rsi+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111c: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x111f: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -7),
    /* 0x1121: movzx  ecx,WORD PTR [rsi+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1125: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x1129: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x112c: cmp    ecx,0x800 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1132: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    ecx,0x800 + jne    110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -14, 2048),
    /* 0x1134: movzx  ecx,BYTE PTR [rsi+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1138: and    cl,0xf [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_4, 0, 0, 15),
    /* 0x113b: cmp    cl,0x5 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x113e: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    cl,0x5 + jne    110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -18, 5),
    /* 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1144: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    BYTE PTR [rsi+0x1f],0x6 + jne    110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_7, BPF_REG_2, 31),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -20, 6),
    /* 0x1146: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1147: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1149: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x114a: lea    rdi,[rsi+0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114e: lea    r8,[rsi+0x22] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 34), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1152: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1154: lea    r9,[rip+0xea5] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xea5]] */
    /* 0x115b: lea    r10,[rip+0xed2] [warning-unmapped: LEA operands are not representable] */
    /* 0x1162: lea    r11,[rip+0xeff] [warning-unmapped: LEA operands are not representable] */
    /* 0x1169: xor    ebx,ebx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_6, 0, 0, 0),
    /* 0x116b: jmp    1179 <packet_toeplitz_rss_hash_xdp+0x79> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 2, 0),
    /* 0x116d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1170: xor    eax,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x1172: inc    ebx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_6, 0, 0, 1),
    /* 0x1174: cmp    ebx,0x68 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1177: je     11d6 <packet_toeplitz_rss_hash_xdp+0xd6> [bpf-branch: lowered cmp    ebx,0x68 + je     11d6 <packet_toeplitz_rss_hash_xdp+0xd6> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 21, 104),
    /* 0x1179: mov    edx,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_6, 0, 0),
    /* 0x117b: shr    edx,0x3 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_3, 0, 0, 3),
    /* 0x117e: cmp    ebx,0x1f [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1181: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [bpf-branch: lowered cmp    ebx,0x1f + jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_K, BPF_REG_6, 0, 5, 31),
    /* 0x1183: cmp    ebx,0x3f [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1186: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [bpf-branch: lowered cmp    ebx,0x3f + jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_K, BPF_REG_6, 0, 4, 63),
    /* 0x1188: cmp    ebx,0x4f [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x118b: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [bpf-branch: lowered cmp    ebx,0x4f + jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_K, BPF_REG_6, 0, 3, 79),
    /* 0x118d: mov    rcx,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1190: cmp    ebx,0x5f [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1193: ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> [bpf-branch: lowered cmp    ebx,0x5f + ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_6, 0, 2, 95),
    /* 0x1195: data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    ecx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_3, 0, 0),
    /* 0x11a2: add    rcx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_4, BPF_REG_5, 0, 0),
    /* 0x11a5: movzx  ebp,BYTE PTR [rcx] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11a8: mov    ecx,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_6, 0, 0),
    /* 0x11aa: and    ecx,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11ad: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11af: test   bpl,bpl [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11b2: jns    1172 <packet_toeplitz_rss_hash_xdp+0x72> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11b4: mov    edx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_3, 0, 0),
    /* 0x11b6: mov    ebp,DWORD PTR [r10+rdx*4] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [r10+rdx*4]] */
    /* 0x11ba: or     ebp,DWORD PTR [r9+rdx*4] [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11be: test   ecx,ecx [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_TESTL_RR),
    /* 0x11c0: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11c2: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11c4: mov    r14d,DWORD PTR [r11+rdx*4] [warning-unmapped: memory base r11 is not in the BPF JIT register file] */
    /* 0x11c8: mov    dl,0x8 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_3, 8),
    /* 0x11ca: sub    dl,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x11cc: mov    ecx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_3, 0, 0),
    /* 0x11ce: shr    r14d,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x11d1: or     ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11d4: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -23, 0),
    /* 0x11d6: mov    edx,DWORD PTR [rsi+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 38), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11d9: movzx  ecx,BYTE PTR [rsi+0x2a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 42), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11dd: movzx  r8d,BYTE PTR [rsi+0x2b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_2, 43), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e2: movzx  r9d,BYTE PTR [rsi+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, 44), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e7: movzx  r10d,BYTE PTR [rsi+0x2d] [warning-unmapped: destination register r10d is not in the BPF JIT register file] */
    /* 0x11ec: mov    r11,rax [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rax] */
    /* 0x11ef: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11f3: xor    edx,DWORD PTR [rsi+0x22] [exact-kinsn: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 34, BPF_REG_7, 0), MICRO_HANDCRAFT_BPF_X86_XORL_MEM),
    /* 0x11f6: bswap  edx [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11f8: mov    edi,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x11fa: xor    edi,eax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x11fc: or     rdi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x11ff: shl    rcx,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 56),
    /* 0x1203: shl    r8,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 48),
    /* 0x1207: or     r8,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_4, 0, 0),
    /* 0x120a: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 40),
    /* 0x120e: or     r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1211: shl    r10,0x20 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1215: or     rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x1218: or     rdx,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x121b: and    eax,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x121e: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1221: mov    r8,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1224: shl    r8,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_5, BPF_REG_4, 0, 0),
    /* 0x1227: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1229: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x122b: shr    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x122e: or     rdx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x1231: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1234: mov    QWORD PTR [rsi],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x1237: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x123c: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x123d: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x123f: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1240: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
