#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 79
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x8]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x10]
 * - 0x1130: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1132: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1134: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1148: lea    rsi,[rip+0xeb1] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeb1]]
 * - 0x1158: movzx  r9d,BYTE PTR [rax-0x5] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x115d: lea    r11d,[r8-0x44] [warning-reg-remap: LEA via x86 kinsn selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x116b: movzx  r10d,r9b [warning-unmapped: movzx source size not recognized: r9b]
 * - 0x116f: movsxd r11,DWORD PTR [rsi+r11*4] [warning-reg-remap: movsxd SIB kinsn; verifier instantiate uses temp BPF_REG_6; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1173: add    r11,rsi [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1176: jmp    r11 [warning-unmapped: cannot parse branch target r11]
 * - 0x1179: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r9b,0x45]
 * - 0x1183: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1186: cmp    BYTE PTR [rax-0x4],0x4c [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x4c]
 * - 0x1190: cmp    BYTE PTR [rax-0x3],0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x45]
 * - 0x119a: cmp    BYTE PTR [rax-0x2],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x54]
 * - 0x11a4: cmp    BYTE PTR [rax-0x1],0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x1],0x45]
 * - 0x11b0: cmp    BYTE PTR [rax],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax],0x20]
 * - 0x11b9: mov    r10d,0x4 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x4]
 * - 0x11bf: mov    r9b,0x4c [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c2: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11d0: cmp    r10d,0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x54]
 * - 0x11d4: je     1275 <tracee_http_method_prefix_detect_xdp+0x175> [warning-unmapped: cannot lower cmp    r10d,0x54 + je     1275 <tracee_http_method_prefix_detect_xdp+0x175> to BPF branch]
 * - 0x11da: cmp    r10d,0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x45]
 * - 0x11de: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch]
 * - 0x11e4: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11e7: cmp    BYTE PTR [rax-0x4],0x41 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x41]
 * - 0x11f1: cmp    BYTE PTR [rax-0x3],0x44 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x44]
 * - 0x11fb: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11fe: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x20]
 * - 0x1208: mov    r10d,0x5 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x5]
 * - 0x120e: mov    r9b,0x41 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1218: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r9b,0x45]
 * - 0x1222: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1225: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x54]
 * - 0x122f: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1232: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x20]
 * - 0x123c: mov    r10d,0x1 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x1]
 * - 0x1244: cmp    r10d,0x55 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x55]
 * - 0x1248: je     1297 <tracee_http_method_prefix_detect_xdp+0x197> [warning-unmapped: cannot lower cmp    r10d,0x55 + je     1297 <tracee_http_method_prefix_detect_xdp+0x197> to BPF branch]
 * - 0x124a: cmp    r10d,0x4f [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x4f]
 * - 0x124e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x4f + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch]
 * - 0x1250: mov    r9b,0x4f [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1253: cmp    BYTE PTR [rax-0x4],0x53 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x53]
 * - 0x1259: cmp    BYTE PTR [rax-0x3],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x54]
 * - 0x125f: mov    r11b,0x4f [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1262: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x20]
 * - 0x1268: mov    r10d,0x2 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x2]
 * - 0x126e: mov    r9b,0x53 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1275: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1278: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x54]
 * - 0x127e: cmp    BYTE PTR [rax-0x3],0x50 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x50]
 * - 0x1284: cmp    BYTE PTR [rax-0x2],0x2f [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x2f]
 * - 0x128a: mov    r10d,0x6 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x6]
 * - 0x1292: mov    r11b,0x54 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1297: mov    r9b,0x55 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x129a: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x54]
 * - 0x12a0: mov    r11b,0x55 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12a3: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x20]
 * - 0x12a9: mov    r10d,0x3 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x3]
 * - 0x12af: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c0: mov    r11d,r9d [warning-reg-remap: 32-bit register move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c3: movzx  r9d,BYTE PTR [rax-0x4] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12cc: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x12d2: lea    r14d,[r10+0x1] [warning-unmapped: LEA base/index not in BPF register file: [r10+0x1]]
 * - 0x12e5: movzx  r9d,r9b [warning-reg-remap: movzx r32,r8 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12e9: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12ed: movzx  r11d,r11b [warning-reg-remap: movzx r32,r8 kinsn; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12f1: shl    r11d,0x10 [warning-reg-remap: ALU imm operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12f9: or     r8d,r11d [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12fc: or     r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1302: mov    ebx,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    ebx,r10d]
 * - 0x1322: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh]
 * - 0x135f: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1360: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1362: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 2),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x90] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 144), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x8] */
    /* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0x8],0x8 + jne    110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 8),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x10] */
    /* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x10 + jne    110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -15, 16),
    /* 0x1130: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1134: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: lea    rax,[rdx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_3, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1139: movabs rbx,0xa0761d6478bd642f [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xa0761d6478bd642fULL),
    /* 0x1143: mov    ecx,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x1148: lea    rsi,[rip+0xeb1] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeb1]] */
    /* 0x114f: nop [padding: padding is not part of BPF semantics] */
    /* 0x1150: mov    rdi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1153: movzx  r8d,BYTE PTR [rax-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_0, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1158: movzx  r9d,BYTE PTR [rax-0x5] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_0, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x115d: lea    r11d,[r8-0x44] [warning-reg-remap: LEA via x86 kinsn selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_5, 0, 0, 1, 0, -68), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1161: cmp    r11d,0xc [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_7, 12), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1165: ja     12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    r11d,0xc + ja     12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_7, 0, 68, 12),
    /* 0x116b: movzx  r10d,r9b [warning-unmapped: movzx source size not recognized: r9b] */
    /* 0x116f: movsxd r11,DWORD PTR [rsi+r11*4] [warning-reg-remap: movsxd SIB kinsn; verifier instantiate uses temp BPF_REG_6; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KINSN(HC_SIB_TMP_PAYLOAD(BPF_REG_7, BPF_REG_2, BPF_REG_7, 2, 0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVSXD_SIB),
    /* 0x1173: add    r11,rsi [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_7, BPF_REG_2, 0, 0),
    /* 0x1176: jmp    r11 [warning-unmapped: cannot parse branch target r11] */
    /* 0x1179: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r9b,0x45] */
    /* 0x117d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    r9b,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 64, 69),
    /* 0x1183: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 69),
    /* 0x1186: cmp    BYTE PTR [rax-0x4],0x4c [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x4c] */
    /* 0x118a: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x4c + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 61, 76),
    /* 0x1190: cmp    BYTE PTR [rax-0x3],0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x45] */
    /* 0x1194: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 59, 69),
    /* 0x119a: cmp    BYTE PTR [rax-0x2],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x54] */
    /* 0x119e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 57, 84),
    /* 0x11a4: cmp    BYTE PTR [rax-0x1],0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x1],0x45] */
    /* 0x11a8: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x1],0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -1),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 55, 69),
    /* 0x11ae: mov    bl,0x45 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 69),
    /* 0x11b0: cmp    BYTE PTR [rax],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax],0x20] */
    /* 0x11b3: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 52, 32),
    /* 0x11b9: mov    r10d,0x4 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x4] */
    /* 0x11bf: mov    r9b,0x4c [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 76),
    /* 0x11c2: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 69),
    /* 0x11c5: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 55, 0),
    /* 0x11ca: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11d0: cmp    r10d,0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x54] */
    /* 0x11d4: je     1275 <tracee_http_method_prefix_detect_xdp+0x175> [warning-unmapped: cannot lower cmp    r10d,0x54 + je     1275 <tracee_http_method_prefix_detect_xdp+0x175> to BPF branch] */
    /* 0x11da: cmp    r10d,0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x45] */
    /* 0x11de: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch] */
    /* 0x11e4: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 69),
    /* 0x11e7: cmp    BYTE PTR [rax-0x4],0x41 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x41] */
    /* 0x11eb: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x41 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 46, 65),
    /* 0x11f1: cmp    BYTE PTR [rax-0x3],0x44 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x44] */
    /* 0x11f5: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x44 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 44, 68),
    /* 0x11fb: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 69),
    /* 0x11fe: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x20] */
    /* 0x1202: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 41, 32),
    /* 0x1208: mov    r10d,0x5 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x5] */
    /* 0x120e: mov    r9b,0x41 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 65),
    /* 0x1211: mov    bl,0x44 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 68),
    /* 0x1213: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 44, 0),
    /* 0x1218: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r9b,0x45] */
    /* 0x121c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    r9b,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 37, 69),
    /* 0x1222: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 69),
    /* 0x1225: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x54] */
    /* 0x1229: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 34, 84),
    /* 0x122f: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 69),
    /* 0x1232: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x20] */
    /* 0x1236: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 31, 32),
    /* 0x123c: mov    r10d,0x1 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x1] */
    /* 0x1242: jmp    12af <tracee_http_method_prefix_detect_xdp+0x1af> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 27, 0),
    /* 0x1244: cmp    r10d,0x55 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x55] */
    /* 0x1248: je     1297 <tracee_http_method_prefix_detect_xdp+0x197> [warning-unmapped: cannot lower cmp    r10d,0x55 + je     1297 <tracee_http_method_prefix_detect_xdp+0x197> to BPF branch] */
    /* 0x124a: cmp    r10d,0x4f [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10d,0x4f] */
    /* 0x124e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x4f + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch] */
    /* 0x1250: mov    r9b,0x4f [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 79),
    /* 0x1253: cmp    BYTE PTR [rax-0x4],0x53 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x53] */
    /* 0x1257: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x53 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 27, 83),
    /* 0x1259: cmp    BYTE PTR [rax-0x3],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x54] */
    /* 0x125d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 25, 84),
    /* 0x125f: mov    r11b,0x4f [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 79),
    /* 0x1262: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x20] */
    /* 0x1266: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 22, 32),
    /* 0x1268: mov    r10d,0x2 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x2] */
    /* 0x126e: mov    r9b,0x53 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 83),
    /* 0x1271: mov    bl,0x54 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 84),
    /* 0x1273: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 25, 0),
    /* 0x1275: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 84),
    /* 0x1278: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x54] */
    /* 0x127c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 16, 84),
    /* 0x127e: cmp    BYTE PTR [rax-0x3],0x50 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x50] */
    /* 0x1282: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x50 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 14, 80),
    /* 0x1284: cmp    BYTE PTR [rax-0x2],0x2f [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x2],0x2f] */
    /* 0x1288: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x2f + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 12, 47),
    /* 0x128a: mov    r10d,0x6 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x6] */
    /* 0x1290: mov    bl,0x50 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 80),
    /* 0x1292: mov    r11b,0x54 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 84),
    /* 0x1295: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 15, 0),
    /* 0x1297: mov    r9b,0x55 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 85),
    /* 0x129a: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x4],0x54] */
    /* 0x129e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 6, 84),
    /* 0x12a0: mov    r11b,0x55 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 85),
    /* 0x12a3: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rax-0x3],0x20] */
    /* 0x12a7: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 3, 32),
    /* 0x12a9: mov    r10d,0x3 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x3] */
    /* 0x12af: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 84),
    /* 0x12b2: mov    bl,0x20 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 32),
    /* 0x12b4: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 6, 0),
    /* 0x12b6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x12c0: mov    r11d,r9d [warning-reg-remap: 32-bit register move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x12c3: movzx  r9d,BYTE PTR [rax-0x4] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_0, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12c8: movzx  ebx,BYTE PTR [rax-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12cc: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x12cf: movzx  ebx,bl [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR),
    /* 0x12d2: lea    r14d,[r10+0x1] [warning-unmapped: LEA base/index not in BPF register file: [r10+0x1]] */
    /* 0x12d6: lea    r15,[rcx+0xa] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_4, 0, 0, 1, 0, 10), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12da: imul   r14,r15 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_IMULQ_RR),
    /* 0x12de: add    rdi,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_8, 0, 0),
    /* 0x12e1: shl    rbx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 32),
    /* 0x12e5: movzx  r9d,r9b [warning-reg-remap: movzx r32,r8 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR),
    /* 0x12e9: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x12ed: movzx  r11d,r11b [warning-reg-remap: movzx r32,r8 kinsn; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_7, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR),
    /* 0x12f1: shl    r11d,0x10 [warning-reg-remap: ALU imm operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_7, 0, 0, 16),
    /* 0x12f5: shl    r8d,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 8),
    /* 0x12f9: or     r8d,r11d [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_7, 0, 0),
    /* 0x12fc: or     r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_9, 0, 0),
    /* 0x12ff: or     r8,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_6, 0, 0),
    /* 0x1302: mov    ebx,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    ebx,r10d] */
    /* 0x1305: or     rbx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_5, 0, 0),
    /* 0x1308: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x130b: xor    rbx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x130e: add    rax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x1312: inc    rcx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1315: cmp    rcx,0x9 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 9), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1319: jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> [bpf-branch: lowered cmp    rcx,0x9 + jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -110, 9),
    /* 0x131f: mov    BYTE PTR [rdx],dil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1322: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh] */
    /* 0x1325: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x1327: shr    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x132a: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x132d: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x132f: shr    eax,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 24),
    /* 0x1332: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1335: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1338: shr    rax,0x20 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x133c: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x133f: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1342: shr    rax,0x28 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1346: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1349: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x134c: shr    rax,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1350: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1353: shr    rbx,0x38 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1357: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x135a: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x135f: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1360: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1362: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1364: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
