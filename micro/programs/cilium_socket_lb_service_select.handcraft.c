#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 41
 *
 * - 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113a: lea    r9,[r8+0x27] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1148: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1150: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1157: or     rax,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x115d: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file]
 * - 0x1160: add    r9,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> [warning-unmapped: cannot lower cmp    r10,0x40 + je     125c <cilium_socket_lb_service_select_xdp+0x15c> to BPF branch]
 * - 0x116e: mov    eax,DWORD PTR [r9-0x13] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1172: movzx  ebx,WORD PTR [r9-0xd] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1177: movzx  r11d,BYTE PTR [r9-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1180: setne  cl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof]
 * - 0x1187: setne  dl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof]
 * - 0x118a: movzx  r15d,BYTE PTR [r9-0xa] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1193: mov    ebp,0x0 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x0]
 * - 0x1198: cmove  ebp,eax [warning-unmapped: cmove operands are not supported]
 * - 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x119f: movzx  r12d,WORD PTR [r9-0x9] [warning-unmapped: destination register r12d is not in the BPF JIT register file]
 * - 0x11a4: test   r12w,r12w [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11aa: mov    r14d,DWORD PTR [r9-0x3] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ae: movzx  ecx,WORD PTR [r9-0xf] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11b8: xor    edx,DWORD PTR [r9-0x17] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11be: xor    edx,DWORD PTR [r9-0x7] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f0: xor    edx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x11f8: mov    ecx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r11d]
 * - 0x1208: div    r12d [warning-unmapped: unsupported mnemonic or operand form: div    r12d]
 * - 0x121e: mov    eax,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    eax,ebp]
 * - 0x1235: mov    eax,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r10d]
 * - 0x124b: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1264: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1265: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1267: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1269: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_5, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    r8,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: jbe    110f <cilium_socket_lb_service_select_xdp+0xf> [bpf-branch: lowered cmp    r8,rcx + jbe    110f <cilium_socket_lb_service_select_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_5, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -4),
    /* 0x1118: lea    rdx,[r8+0x610] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 1552), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1122: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -7),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x40 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1129: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0x8],0x40 + jne    110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_5, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -9, 64),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x18 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1130: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0xc],0x18 + jne    110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_7, BPF_REG_5, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -11, 24),
    /* 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113a: lea    r9,[r8+0x27] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_5, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113e: movabs rdi,0x243f6a8885a308d3 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x243f6a8885a308d3ULL),
    /* 0x1148: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x114b: jmp    116e <cilium_socket_lb_service_select_xdp+0x6e> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 4, 0),
    /* 0x114d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1154: movzx  eax,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1157: or     rax,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x115a: xor    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x115d: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file] */
    /* 0x1160: add    r9,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x1164: cmp    r10,0x40 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> [warning-unmapped: cannot lower cmp    r10,0x40 + je     125c <cilium_socket_lb_service_select_xdp+0x15c> to BPF branch] */
    /* 0x116e: mov    eax,DWORD PTR [r9-0x13] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_9, -19), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x1172: movzx  ebx,WORD PTR [r9-0xd] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_9, -13), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1177: movzx  r11d,BYTE PTR [r9-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x117c: cmp    r11,0x11 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1180: setne  cl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof] */
    /* 0x1183: cmp    r11,0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1187: setne  dl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof] */
    /* 0x118a: movzx  r15d,BYTE PTR [r9-0xa] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_9, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x118f: test   r15b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x1193: mov    ebp,0x0 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x0] */
    /* 0x1198: cmove  ebp,eax [warning-unmapped: cmove operands are not supported] */
    /* 0x119b: test   dl,cl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x119f: movzx  r12d,WORD PTR [r9-0x9] [warning-unmapped: destination register r12d is not in the BPF JIT register file] */
    /* 0x11a4: test   r12w,r12w [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11aa: mov    r14d,DWORD PTR [r9-0x3] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_9, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11ae: movzx  ecx,WORD PTR [r9-0xf] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_9, -15), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11b3: mov    edx,ecx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x11b5: shl    edx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 16),
    /* 0x11b8: xor    edx,DWORD PTR [r9-0x17] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_3, BPF_REG_9, -23, BPF_REG_7, 0), MICRO_HANDCRAFT_BPF_X86_XORL_MEM),
    /* 0x11bc: xor    edx,ebx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_6, 0, 0),
    /* 0x11be: xor    edx,DWORD PTR [r9-0x7] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_3, BPF_REG_9, -7, BPF_REG_7, 0), MICRO_HANDCRAFT_BPF_X86_XORL_MEM),
    /* 0x11c2: movsx  esi,bx [exact-kinsn: movswl reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVSWL_RR),
    /* 0x11c5: cmp    esi,0x752f [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11cb: jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x752f + jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_2, 0, 11, 29999),
    /* 0x11cd: mov    esi,r15d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x11d0: and    esi,0x2 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11d3: jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> [bpf-branch: lowered flags from and    esi,0x2 + jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_2, 0, 7, 0),
    /* 0x11d5: mov    eax,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_0, 0, 0),
    /* 0x11d7: shl    rax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x11db: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11de: or     rcx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x11e1: add    rdi,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x11e4: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -36, 0),
    /* 0x11e9: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: xor    edx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x11f2: lea    esi,[r14+r15*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_8, BPF_REG_9, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f6: add    esi,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x11f8: mov    ecx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r11d] */
    /* 0x11fb: and    ecx,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11fe: inc    ecx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x1200: rol    esi,cl [exact-kinsn: roll cl kinsn; verifier instantiate uses temps BPF_REG_7/BPF_REG_6] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_7, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_CL),
    /* 0x1202: xor    esi,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x1204: mov    eax,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x1206: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x1208: div    r12d [warning-unmapped: unsupported mnemonic or operand form: div    r12d] */
    /* 0x120b: inc    edx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_3, 0, 0, 1),
    /* 0x120d: shl    r15d,0x1d [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 29),
    /* 0x1211: sar    r15d,0x1f [bpf-jit: SAR immediate maps directly to BPF ARSH] */
    HC_RAW(BPF_ALU | BPF_ARSH | BPF_K, BPF_REG_9, 0, 0, 31),
    /* 0x1215: inc    r14d [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_8, 0, 0, 1),
    /* 0x1218: and    r14d,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x121b: xor    r14d,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_3, 0, 0),
    /* 0x121e: mov    eax,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    eax,ebp] */
    /* 0x1220: shl    rax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x1224: movzx  edx,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1227: shl    rdx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 32),
    /* 0x122b: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x122e: shl    r14,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 48),
    /* 0x1232: or     rsi,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_8, 0, 0),
    /* 0x1235: mov    eax,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r10d] */
    /* 0x1238: and    eax,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x123b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123e: mov    rbx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1241: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1244: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1246: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1248: shr    rsi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x124b: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x124e: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x1251: or     rsi,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_6, 0, 0),
    /* 0x1254: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x1257: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -75, 0),
    /* 0x125c: mov    QWORD PTR [r8],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_5, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x125f: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1264: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1265: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1267: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1269: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126c: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
