#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 21
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112f: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1145: shr    r10,cl [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1148: xor    r9,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x114b: add    r9,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1159: xor    r8,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x117e: mov    r10,QWORD PTR [rdx+rsi*4+0x20] [warning-unmapped: unsupported mnemonic or operand form: mov    r10,QWORD PTR [rdx+rsi*4+0x20]]
 * - 0x1188: add    rcx,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x1193: mov    r9d,DWORD PTR [rdx+rsi*4+0x2c] [warning-reg-remap: indexed memory load via x86 SIB kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1198: or     r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x119f: mov    r11,rax [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rax]
 * - 0x11a2: shl    r11,0x10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11ab: or     r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11ae: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11b1: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11b7: je     1140 <flow_record_field_scan_xdp+0x40> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11be: add    r9,rcx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c1: xor    r9,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x11c9: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh]
 * - 0x1206: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <flow_record_field_scan_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <flow_record_field_scan_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <flow_record_field_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <flow_record_field_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -4),
    /* 0x1118: lea    rdi,[rdx+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <flow_record_field_scan_xdp+0xe> [bpf-branch: lowered cmp    rdi,rcx + ja     110e <flow_record_field_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [rsi],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1127: jne    110e <flow_record_field_scan_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi],0x20 + jne    110e <flow_record_field_scan_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_2, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -9, 32),
    /* 0x1129: cmp    DWORD PTR [rdx+0xc],0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x112d: jne    110e <flow_record_field_scan_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x20 + jne    110e <flow_record_field_scan_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -11, 32),
    /* 0x112f: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1130: movabs r8,0x9e3779b97f4a7c15 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 0x9e3779b97f4a7c15ULL),
    /* 0x113a: xor    esi,esi [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 0),
    /* 0x113c: xor    edi,edi [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 0),
    /* 0x113e: jmp    117e <flow_record_field_scan_xdp+0x7e> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 22, 0),
    /* 0x1140: mov    ecx,edi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_1, 0, 0),
    /* 0x1142: and    cl,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_4, 0, 0, 7),
    /* 0x1145: shr    r10,cl [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1148: xor    r9,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x114b: add    r9,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x114e: mov    ecx,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_2, 0, 0),
    /* 0x1150: and    cl,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_4, 0, 0, 24),
    /* 0x1153: mov    r8,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1156: shl    r8,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_5, BPF_REG_4, 0, 0),
    /* 0x1159: xor    r8,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_9, 0, 0),
    /* 0x115c: and    al,0x7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_0, 0, 0, 7),
    /* 0x115e: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1161: mov    rbx,r8 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1164: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1167: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1169: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x116b: shr    r8,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_5, BPF_REG_4, 0, 0),
    /* 0x116e: or     r8,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_6, 0, 0),
    /* 0x1171: inc    rdi [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 1),
    /* 0x1174: add    rsi,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 8),
    /* 0x1178: cmp    rdi,0x20 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x117c: je     11c6 <flow_record_field_scan_xdp+0xc6> [bpf-branch: lowered cmp    rdi,0x20 + je     11c6 <flow_record_field_scan_xdp+0xc6> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_1, 0, 18, 32),
    /* 0x117e: mov    r10,QWORD PTR [rdx+rsi*4+0x20] [warning-unmapped: unsupported mnemonic or operand form: mov    r10,QWORD PTR [rdx+rsi*4+0x20]] */
    /* 0x1183: mov    rcx,QWORD PTR [rdx+rsi*4+0x18] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_2, 2, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ_SIB),
    /* 0x1188: add    rcx,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x118b: mov    eax,DWORD PTR [rdx+rsi*4+0x28] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_2, 2, 40), MICRO_HANDCRAFT_BPF_X86_MOVL_SIB),
    /* 0x118f: shl    rax,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 32),
    /* 0x1193: mov    r9d,DWORD PTR [rdx+rsi*4+0x2c] [warning-reg-remap: indexed memory load via x86 SIB kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_9, BPF_REG_3, BPF_REG_2, 2, 44), MICRO_HANDCRAFT_BPF_X86_MOVL_SIB),
    /* 0x1198: or     r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x119b: mov    eax,DWORD PTR [rdx+rsi*4+0x10] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_2, 2, 16), MICRO_HANDCRAFT_BPF_X86_MOVL_SIB),
    /* 0x119f: mov    r11,rax [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rax] */
    /* 0x11a2: shl    r11,0x10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11a6: movzx  ebx,WORD PTR [rdx+rsi*4+0x14] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_6, BPF_REG_3, BPF_REG_2, 2, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x11ab: or     r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11ae: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11b1: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11b4: test   bl,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x11b7: je     1140 <flow_record_field_scan_xdp+0x40> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11b9: movzx  ecx,WORD PTR [rdx+rsi*4+0x16] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_2, 2, 22), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x11be: add    r9,rcx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x11c1: xor    r9,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x11c4: jmp    114e <flow_record_field_scan_xdp+0x4e> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -38, 0),
    /* 0x11c6: mov    BYTE PTR [rdx],r8b [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x11c9: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh] */
    /* 0x11cc: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x11ce: shr    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x11d1: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x11d4: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x11d6: shr    eax,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 24),
    /* 0x11d9: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x11dc: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11df: shr    rax,0x20 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x11e3: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x11e6: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11e9: shr    rax,0x28 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x11ed: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x11f0: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11f3: shr    rax,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x11f7: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x11fa: shr    rbx,0x38 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x11fe: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1201: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1206: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1207: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
