#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 70
 *
 * - 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113a: mov    QWORD PTR [rsp-0x10],rsi [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x114f: mov    QWORD PTR [rsp-0x18],rax [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1160: mov    QWORD PTR [rsp-0x8],rbx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1169: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x116e: mov    r13d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x117c: movzx  r12d,BYTE PTR [rdi-0xc] [warning-unmapped: destination register r12d is not in the BPF JIT register file]
 * - 0x1181: shl    r12d,0x18 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file]
 * - 0x1185: or     r12d,eax [warning-unmapped: ALU destination r12d is not in the BPF JIT register file]
 * - 0x1188: movzx  r10d,BYTE PTR [rdi-0xb] [warning-unmapped: destination register r10d is not in the BPF JIT register file]
 * - 0x118d: shl    r10,0x20 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1191: movzx  ebp,BYTE PTR [rdi-0xa] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x1195: shl    rbp,0x28 [warning-unmapped: ALU destination rbp is not in the BPF JIT register file]
 * - 0x1199: movzx  r11d,BYTE PTR [rdi-0x9] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x119e: shl    r11,0x30 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11df: or     r10,rbp [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x11e2: or     r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x11e5: or     r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11e8: lea    ebp,[r12+r13*1] [warning-unmapped: LEA operands are not representable]
 * - 0x120b: or     r10,rbp [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x120e: shr    ebp,0xb [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1211: and    ebp,0x7ff [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1217: shr    r12d,0x16 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file]
 * - 0x121b: movzx  esi,r12b [warning-unmapped: movzx source size not recognized: r12b]
 * - 0x121f: add    rax,rbp [warning-unmapped: ALU source rbp is not supported]
 * - 0x122c: shr    r10,0x1e [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1230: and    r10d,0x3fff [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1237: shr    r11,0x2c [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x123b: and    r11d,0x3ff [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1242: add    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1245: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1254: mov    r12d,r13d [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,r13d]
 * - 0x1257: and    r12d,0xf [warning-unmapped: ALU destination r12d is not in the BPF JIT register file]
 * - 0x1263: shr    r9d,1 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1266: and    r9d,0x1f [warning-reg-remap: andl imm32 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1271: add    r12,r15 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x1274: add    r12,rdx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x127d: add    rax,r12 [warning-unmapped: ALU source r12 is not supported]
 * - 0x1287: lea    rsi,[r9+r13*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x128b: mov    r8,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1296: lea    rax,[rbp*2+0x0] [warning-unmapped: LEA base/index not in BPF register file: [rbp*2+0x0]]
 * - 0x129e: add    rax,rbp [warning-unmapped: ALU source rbp is not supported]
 * - 0x12a1: lea    r12,[r13*8+0x0] [warning-unmapped: LEA operands are not representable]
 * - 0x12a9: sub    r12,r13 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x12ac: lea    r13,[r10+r10*4] [warning-unmapped: LEA base/index not in BPF register file: [r10+r10*4]]
 * - 0x12b0: xor    r12,rax [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x12b3: xor    r12,r13 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x12cd: mov    r15d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12d4: add    r15,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12fb: add    rax,r12 [warning-unmapped: ALU source r12 is not supported]
 * - 0x1301: xor    rsi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1304: add    rsi,QWORD PTR [rsp-0x8] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file]
 * - 0x130c: lea    rbx,[rdx+r9*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1310: add    rbx,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x1339: mov    QWORD PTR [rsp-0x18],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1348: mov    rdx,QWORD PTR [rsp-0x10] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x134f: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh]
 * - 0x138c: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x138d: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x138f: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1391: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1393: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1395: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <packed_header_bitfield_decode_xdp+0xf> [bpf-branch: lowered cmp    rsi,rcx + jbe    110f <packed_header_bitfield_decode_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_2, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <packed_header_bitfield_decode_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <packed_header_bitfield_decode_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -4),
    /* 0x1118: lea    rdx,[rsi+0x210] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 528), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <packed_header_bitfield_decode_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <packed_header_bitfield_decode_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [rsi+0x8],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1128: jne    110e <packed_header_bitfield_decode_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi+0x8],0x20 + jne    110e <packed_header_bitfield_decode_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -9, 32),
    /* 0x112a: cmp    DWORD PTR [rsi+0xc],0x2 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x112e: jne    110e <packed_header_bitfield_decode_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi+0xc],0x2 + jne    110e <packed_header_bitfield_decode_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -11, 2),
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113a: mov    QWORD PTR [rsp-0x10],rsi [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x113f: lea    rdi,[rsi+0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1143: movabs rbx,0x6a09e667f3bcc909 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6a09e667f3bcc909ULL),
    /* 0x114d: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x114f: mov    QWORD PTR [rsp-0x18],rax [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1154: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: mov    QWORD PTR [rsp-0x8],rbx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1165: movzx  ebx,BYTE PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1169: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x116e: mov    r13d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x1171: shl    r13d,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_7, 0, 0, 8),
    /* 0x1175: movzx  eax,BYTE PTR [rdi-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1179: shl    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x117c: movzx  r12d,BYTE PTR [rdi-0xc] [warning-unmapped: destination register r12d is not in the BPF JIT register file] */
    /* 0x1181: shl    r12d,0x18 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file] */
    /* 0x1185: or     r12d,eax [warning-unmapped: ALU destination r12d is not in the BPF JIT register file] */
    /* 0x1188: movzx  r10d,BYTE PTR [rdi-0xb] [warning-unmapped: destination register r10d is not in the BPF JIT register file] */
    /* 0x118d: shl    r10,0x20 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1191: movzx  ebp,BYTE PTR [rdi-0xa] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x1195: shl    rbp,0x28 [warning-unmapped: ALU destination rbp is not in the BPF JIT register file] */
    /* 0x1199: movzx  r11d,BYTE PTR [rdi-0x9] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x119e: shl    r11,0x30 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11a2: movzx  eax,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11a6: shl    eax,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 24),
    /* 0x11a9: movzx  r15d,BYTE PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ae: shl    r15,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 32),
    /* 0x11b2: movzx  esi,BYTE PTR [rdi-0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11b6: shl    rsi,0x28 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 40),
    /* 0x11ba: lea    rcx,[r15+rsi*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_9, BPF_REG_2, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11be: or     r15,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x11c1: movzx  eax,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11c5: shl    rax,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 48),
    /* 0x11c9: movzx  edx,BYTE PTR [rdi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11cc: shl    rdx,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 56),
    /* 0x11d0: or     rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x11d3: movzx  r14d,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11d8: shl    r14,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 56),
    /* 0x11dc: or     r13d,ebx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_6, 0, 0),
    /* 0x11df: or     r10,rbp [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x11e2: or     r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x11e5: or     r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11e8: lea    ebp,[r12+r13*1] [warning-unmapped: LEA operands are not representable] */
    /* 0x11ec: or     rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x11ef: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x11f1: and    eax,0x3f [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 63), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11f4: shr    r13d,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_7, 0, 0, 6),
    /* 0x11f8: and    r13d,0x1f [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_7, 31), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11fc: shr    r14,0x36 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 54), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1200: add    rax,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_8, 0, 0),
    /* 0x1203: add    rax,r13 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_7, 0, 0),
    /* 0x1206: movzx  r13d,BYTE PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x120b: or     r10,rbp [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x120e: shr    ebp,0xb [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1211: and    ebp,0x7ff [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1217: shr    r12d,0x16 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file] */
    /* 0x121b: movzx  esi,r12b [warning-unmapped: movzx source size not recognized: r12b] */
    /* 0x121f: add    rax,rbp [warning-unmapped: ALU source rbp is not supported] */
    /* 0x1222: add    rax,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x1225: movzx  esi,BYTE PTR [rdi-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1229: shl    esi,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 8),
    /* 0x122c: shr    r10,0x1e [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1230: and    r10d,0x3fff [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1237: shr    r11,0x2c [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x123b: and    r11d,0x3ff [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1242: add    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1245: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1248: movzx  eax,BYTE PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x124c: shl    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x124f: or     eax,esi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x1251: or     esi,r13d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_7, 0, 0),
    /* 0x1254: mov    r12d,r13d [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,r13d] */
    /* 0x1257: and    r12d,0xf [warning-unmapped: ALU destination r12d is not in the BPF JIT register file] */
    /* 0x125b: shr    r15,0x18 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 24), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x125f: shr    rdx,0x28 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1263: shr    r9d,1 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x1266: and    r9d,0x1f [warning-reg-remap: andl imm32 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 31), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x126a: shr    rcx,0x26 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x126e: and    ecx,0x7f [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 127), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x1271: add    r12,r15 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x1274: add    r12,rdx [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x1277: shr    eax,0xc [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 12),
    /* 0x127a: add    rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x127d: add    rax,r12 [warning-unmapped: ALU source r12 is not supported] */
    /* 0x1280: shr    esi,0x4 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_2, 0, 0, 4),
    /* 0x1283: movzx  r13d,sil [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_7, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR),
    /* 0x1287: lea    rsi,[r9+r13*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_9, BPF_REG_7, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x128b: mov    r8,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1290: add    rsi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_5, 0, 0),
    /* 0x1293: add    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x1296: lea    rax,[rbp*2+0x0] [warning-unmapped: LEA base/index not in BPF register file: [rbp*2+0x0]] */
    /* 0x129e: add    rax,rbp [warning-unmapped: ALU source rbp is not supported] */
    /* 0x12a1: lea    r12,[r13*8+0x0] [warning-unmapped: LEA operands are not representable] */
    /* 0x12a9: sub    r12,r13 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x12ac: lea    r13,[r10+r10*4] [warning-unmapped: LEA base/index not in BPF register file: [r10+r10*4]] */
    /* 0x12b0: xor    r12,rax [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x12b3: xor    r12,r13 [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x12b6: lea    rax,[r14+r14*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_8, BPF_REG_8, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12ba: lea    rax,[r14+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_8, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12be: lea    r13,[r15+r15*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_9, BPF_REG_9, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12c2: lea    r15,[r15+r13*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_9, BPF_REG_7, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12c6: lea    r13,[rdx+rdx*8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_3, BPF_REG_3, 3, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12ca: xor    r13,r15 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x12cd: mov    r15d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_9, 0, 0),
    /* 0x12d0: shl    r15d,0x4 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 4),
    /* 0x12d4: add    r15,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_9, 0, 0),
    /* 0x12d7: xor    r15,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x12da: xor    r15,r13 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_7, 0, 0),
    /* 0x12dd: lea    rax,[rcx+rcx*8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_4, BPF_REG_4, 3, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12e1: lea    rax,[rcx+rax*2] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_4, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12e5: xor    rax,r15 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x12e8: and    bl,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_6, 0, 0, 7),
    /* 0x12eb: lea    ecx,[rbx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_6, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12ee: mov    r15,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x12f1: shl    r15,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x12f4: not    bl [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x12f6: mov    ecx,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_6, 0, 0),
    /* 0x12f8: shr    rsi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x12fb: add    rax,r12 [warning-unmapped: ALU source r12 is not supported] */
    /* 0x12fe: or     rsi,r15 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x1301: xor    rsi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1304: add    rsi,QWORD PTR [rsp-0x8] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file] */
    /* 0x1309: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x130c: lea    rbx,[rdx+r9*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_6, BPF_REG_3, BPF_REG_9, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1310: add    rbx,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1313: add    rbx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_2, 0, 0),
    /* 0x1316: xor    edx,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_8, 0, 0),
    /* 0x1319: and    dl,0xf [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_3, 0, 0, 15),
    /* 0x131c: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x131f: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1322: shl    rax,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x1325: not    dl [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1327: mov    ecx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_3, 0, 0),
    /* 0x1329: shr    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x132c: or     rbx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x132f: inc    r8 [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x1332: add    rdi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1336: mov    rcx,r8 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1339: mov    QWORD PTR [rsp-0x18],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x133e: cmp    r8,0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1342: jne    1160 <packed_header_bitfield_decode_xdp+0x60> [bpf-branch: lowered cmp    r8,0x20 + jne    1160 <packed_header_bitfield_decode_xdp+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, -127, 32),
    /* 0x1348: mov    rdx,QWORD PTR [rsp-0x10] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x134d: mov    BYTE PTR [rdx],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x134f: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh] */
    /* 0x1352: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1354: shr    ecx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_4, 0, 0, 16),
    /* 0x1357: mov    BYTE PTR [rdx+0x2],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x135a: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x135c: shr    ecx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_4, 0, 0, 24),
    /* 0x135f: mov    BYTE PTR [rdx+0x3],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1362: mov    rcx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1365: shr    rcx,0x20 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1369: mov    BYTE PTR [rdx+0x4],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x136c: mov    rcx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x136f: shr    rcx,0x28 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1373: mov    BYTE PTR [rdx+0x5],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1376: mov    rcx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1379: shr    rcx,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x137d: mov    BYTE PTR [rdx+0x6],cl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1380: shr    rax,0x38 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1384: mov    BYTE PTR [rdx+0x7],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1387: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x138c: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x138d: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x138f: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1391: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1393: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1395: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1396: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
