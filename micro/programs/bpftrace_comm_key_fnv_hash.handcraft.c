#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 119
 *
 * - 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113b: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113c: mov    QWORD PTR [rsp-0x40],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1152: movabs r10,0x100000001b3 [warning-unmapped: unsupported mnemonic or operand form: movabs r10,0x100000001b3]
 * - 0x1160: shl    r12d,0x8 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file]
 * - 0x1168: or     r15d,r12d [warning-unmapped: ALU source r12d is not supported]
 * - 0x1176: mov    rdx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r11]
 * - 0x1180: shr    r11,cl [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1186: or     ebx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1189: or     r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x118f: xor    rax,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x11af: mov    QWORD PTR [rsp-0x8],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x11b9: movzx  r9d,BYTE PTR [rdi-0x1e] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c6: movzx  ebp,BYTE PTR [rdi-0x1b] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11ce: mov    QWORD PTR [rsp-0x10],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x11d7: mov    QWORD PTR [rsp-0x18],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x11e6: movzx  r12d,BYTE PTR [rdi-0x16] [warning-unmapped: destination register r12d is not in the BPF JIT register file]
 * - 0x11f4: mov    r11,r13 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r13]
 * - 0x1201: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1204: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1208: mov    QWORD PTR [rsp-0x38],r9 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x120d: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1210: mov    r9,r8 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1213: mov    r8,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1218: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x121c: mov    QWORD PTR [rsp-0x28],rax [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1221: xor    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1224: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1228: mov    QWORD PTR [rsp-0x30],rdx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x122d: xor    r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1230: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1234: mov    QWORD PTR [rsp-0x20],rbp [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rsp-0x20],rbp]
 * - 0x1239: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x123c: mov    rbp,QWORD PTR [rsp-0x10] [warning-unmapped: unsupported mnemonic or operand form: mov    rbp,QWORD PTR [rsp-0x10]]
 * - 0x1241: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1245: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1248: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x124c: xor    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x124f: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1253: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1256: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x125a: mov    QWORD PTR [rsp-0x48],r14 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x125f: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1262: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1266: xor    r11,r12 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1269: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x126d: xor    r11,r15 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1270: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1277: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x127a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x127e: movzx  r11d,BYTE PTR [rdi-0xf] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1283: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1286: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x128f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1292: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x1296: movzx  r11d,BYTE PTR [rdi-0xd] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x129b: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x129e: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12a7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12aa: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12ae: movzx  r11d,BYTE PTR [rdi-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12b3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12b6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12bf: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12c2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12c6: movzx  r11d,BYTE PTR [rdi-0x9] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12cb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12ce: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12d7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12da: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12de: movzx  r11d,BYTE PTR [rdi-0x7] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12e3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12e6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12ef: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12f2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12f6: movzx  r11d,BYTE PTR [rdi-0x5] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12fb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12fe: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1307: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x130a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x130e: movzx  r11d,BYTE PTR [rdi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1313: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1316: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x131f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1322: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x132d: imul   rcx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rcx,r10]
 * - 0x1331: movzx  r11d,BYTE PTR [rdi] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1335: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x133d: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1345: jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1347: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1350: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1358: shl    ebp,0x8 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x135b: mov    rax,QWORD PTR [rsp-0x28] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1364: mov    rcx,QWORD PTR [rsp-0x30] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x136d: mov    rdx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1383: or     r13,rbp [warning-unmapped: ALU source rbp is not supported]
 * - 0x1389: or     r13,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x138c: or     r13,QWORD PTR [rsp-0x20] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file]
 * - 0x1391: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1396: mov    eax,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13ae: xor    r11,r13 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x13b5: mov    r8,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13ba: je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x13ca: add    rax,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x13d1: cmove  r11,rax [warning-unmapped: cmove operands are not supported]
 * - 0x13da: mov    rax,QWORD PTR [rsp-0x40] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13e7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13e8: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13ea: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13ec: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13ee: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13f0: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_5, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    r8,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> [bpf-branch: lowered cmp    r8,rcx + jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_5, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -4),
    /* 0x1118: lea    rdx,[r8+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1129: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0x8],0x20 + jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -9, 32),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1130: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0xc],0x20 + jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -11, 32),
    /* 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113b: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113c: mov    QWORD PTR [rsp-0x40],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1141: lea    rdi,[r8+0x2f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_5, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1145: movabs rsi,0x94d049bb133111eb [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x94d049bb133111ebULL),
    /* 0x114f: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x1152: movabs r10,0x100000001b3 [warning-unmapped: unsupported mnemonic or operand form: movabs r10,0x100000001b3] */
    /* 0x115c: jmp    11af <bpftrace_comm_key_fnv_hash_xdp+0xaf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 21, 0),
    /* 0x115e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1160: shl    r12d,0x8 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file] */
    /* 0x1164: shl    r15d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x1168: or     r15d,r12d [warning-unmapped: ALU source r12d is not supported] */
    /* 0x116b: shl    ebx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 24),
    /* 0x116e: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1171: and    al,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 7),
    /* 0x1173: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1176: mov    rdx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r11] */
    /* 0x1179: shl    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x117c: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x117e: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1180: shr    r11,cl [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1183: or     ebx,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1186: or     ebx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1189: or     r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x118c: mov    rax,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x118f: xor    rax,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1192: shl    r14,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 56),
    /* 0x1196: mov    esi,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_2, BPF_REG_6, 0, 0),
    /* 0x1198: or     rsi,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_8, 0, 0),
    /* 0x119b: add    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x119e: inc    r8 [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x11a1: add    rdi,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 32),
    /* 0x11a5: cmp    r8,0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11a9: je     13da <bpftrace_comm_key_fnv_hash_xdp+0x2da> [bpf-branch: lowered cmp    r8,0x20 + je     13da <bpftrace_comm_key_fnv_hash_xdp+0x2da> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 76, 32),
    /* 0x11af: mov    QWORD PTR [rsp-0x8],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x11b4: movzx  r13d,BYTE PTR [rdi-0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -31), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11b9: movzx  r9d,BYTE PTR [rdi-0x1e] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -30), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11be: movzx  eax,BYTE PTR [rdi-0x1d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -29), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11c2: movzx  edx,BYTE PTR [rdi-0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, -28), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11c6: movzx  ebp,BYTE PTR [rdi-0x1b] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11ca: movzx  ecx,BYTE PTR [rdi-0x1a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -26), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ce: mov    QWORD PTR [rsp-0x10],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x11d3: movzx  ecx,BYTE PTR [rdi-0x19] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -25), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11d7: mov    QWORD PTR [rsp-0x18],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x11dc: movzx  r8d,BYTE PTR [rdi-0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_1, -24), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e1: movzx  r14d,BYTE PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e6: movzx  r12d,BYTE PTR [rdi-0x16] [warning-unmapped: destination register r12d is not in the BPF JIT register file] */
    /* 0x11eb: movzx  r15d,BYTE PTR [rdi-0x15] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -21), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11f0: movzx  ebx,BYTE PTR [rdi-0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -20), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11f4: mov    r11,r13 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r13] */
    /* 0x11f7: movabs rcx,0xcbf29ce484222325 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0xcbf29ce484222325ULL),
    /* 0x1201: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1204: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1208: mov    QWORD PTR [rsp-0x38],r9 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x120d: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1210: mov    r9,r8 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1213: mov    r8,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1218: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x121c: mov    QWORD PTR [rsp-0x28],rax [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1221: xor    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1224: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1228: mov    QWORD PTR [rsp-0x30],rdx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x122d: xor    r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1230: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1234: mov    QWORD PTR [rsp-0x20],rbp [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rsp-0x20],rbp] */
    /* 0x1239: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x123c: mov    rbp,QWORD PTR [rsp-0x10] [warning-unmapped: unsupported mnemonic or operand form: mov    rbp,QWORD PTR [rsp-0x10]] */
    /* 0x1241: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1245: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1248: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x124c: xor    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x124f: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1253: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1256: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x125a: mov    QWORD PTR [rsp-0x48],r14 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x125f: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1262: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1266: xor    r11,r12 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1269: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x126d: xor    r11,r15 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1270: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1274: mov    r14,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1277: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x127a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x127e: movzx  r11d,BYTE PTR [rdi-0xf] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1283: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1286: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x128a: movzx  r14d,BYTE PTR [rdi-0xe] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x128f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1292: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x1296: movzx  r11d,BYTE PTR [rdi-0xd] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x129b: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x129e: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12a2: movzx  r14d,BYTE PTR [rdi-0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12a7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12aa: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12ae: movzx  r11d,BYTE PTR [rdi-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12b3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12b6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12ba: movzx  r14d,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12bf: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12c2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12c6: movzx  r11d,BYTE PTR [rdi-0x9] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12cb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12ce: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12d2: movzx  r14d,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12d7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12da: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12de: movzx  r11d,BYTE PTR [rdi-0x7] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12e3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12e6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12ea: movzx  r14d,BYTE PTR [rdi-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12ef: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12f2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12f6: movzx  r11d,BYTE PTR [rdi-0x5] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12fb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12fe: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1302: movzx  r14d,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1307: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x130a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x130e: movzx  r11d,BYTE PTR [rdi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1313: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1316: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x131a: movzx  r14d,BYTE PTR [rdi-0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x131f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1322: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x1326: movzx  ecx,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x132a: xor    rcx,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_8, 0, 0),
    /* 0x132d: imul   rcx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rcx,r10] */
    /* 0x1331: movzx  r11d,BYTE PTR [rdi] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1335: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1338: movzx  r14d,BYTE PTR [rdi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x133d: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1341: test   r14b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x1345: jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1347: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x134c: jmp    13b1 <bpftrace_comm_key_fnv_hash_xdp+0x2b1> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 23, 0),
    /* 0x134e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1350: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x1354: shl    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x1358: shl    ebp,0x8 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x135b: mov    rax,QWORD PTR [rsp-0x28] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1360: shl    rax,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 48),
    /* 0x1364: mov    rcx,QWORD PTR [rsp-0x30] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1369: shl    rcx,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 56),
    /* 0x136d: mov    rdx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1372: shl    rdx,0x28 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 40),
    /* 0x1376: shl    r13,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_7, 0, 0, 32),
    /* 0x137a: or     r13,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_3, 0, 0),
    /* 0x137d: or     r13,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_0, 0, 0),
    /* 0x1380: or     r13,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_4, 0, 0),
    /* 0x1383: or     r13,rbp [warning-unmapped: ALU source rbp is not supported] */
    /* 0x1386: or     r13,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_5, 0, 0),
    /* 0x1389: or     r13,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x138c: or     r13,QWORD PTR [rsp-0x20] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file] */
    /* 0x1391: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1396: mov    eax,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x1399: and    al,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 7),
    /* 0x139b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x139e: mov    rdx,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x13a1: shl    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x13a4: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x13a6: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x13a8: shr    r13,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_7, BPF_REG_4, 0, 0),
    /* 0x13ab: or     r13,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_3, 0, 0),
    /* 0x13ae: xor    r11,r13 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x13b1: test   r14b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x13b5: mov    r8,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x13ba: je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x13c0: movabs rax,0x9e3779b185ebca87 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x9e3779b185ebca87ULL),
    /* 0x13ca: add    rax,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x13cd: cmp    BYTE PTR [rdi-0xf],0x70 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x13d1: cmove  r11,rax [warning-unmapped: cmove operands are not supported] */
    /* 0x13d5: jmp    1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -97, 0),
    /* 0x13da: mov    rax,QWORD PTR [rsp-0x40] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x13df: mov    QWORD PTR [rax],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x13e2: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x13e7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13e8: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13ea: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13ec: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13ee: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13f0: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13f1: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
