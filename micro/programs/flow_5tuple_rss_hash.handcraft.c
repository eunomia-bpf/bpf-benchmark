#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 67
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112d: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112f: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1184: movzx  r11d,BYTE PTR [rcx+0x18] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x11ac: mov    eax,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r11d]
 * - 0x11b8: mov    r10d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,DWORD PTR [rcx+0x26]]
 * - 0x11bc: bswap  r10d [warning-unmapped: BSWAP destination r10d is not in the BPF JIT register file]
 * - 0x11d7: lea    r9d,[rax+r8*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11db: lea    ebp,[r10-0x61c88647] [warning-unmapped: LEA operands are not representable]
 * - 0x11f8: sub    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11fb: add    r9d,0xdeadbeef [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1206: xor    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1209: lea    r9d,[r10+r15*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r15*1]]
 * - 0x120d: add    r9d,0xb06bd031 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x121b: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x121e: xor    r15d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x1221: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1224: sub    r9d,r15d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1227: mov    ebp,r15d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r15d]
 * - 0x122a: rol    ebp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: ebp]
 * - 0x122d: xor    ebp,r9d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1233: mov    r9d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r9d,ebp]
 * - 0x1236: rol    r9d,0x10 [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x123a: sub    r14d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x123d: xor    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1240: add    ebp,r15d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1243: sub    r15d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1246: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1250: add    r9d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x1253: xor    r8d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x125a: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x125d: add    r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1260: add    r9d,edx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1263: add    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x126a: xor    r14d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x1277: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x127a: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d]
 * - 0x127d: rol    r10d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x1281: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1284: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx]
 * - 0x1287: rol    r10d,0xb [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x128e: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1291: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1294: mov    r10d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r8d]
 * - 0x1297: rol    r10d,0x19 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x129b: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x129e: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12a1: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d]
 * - 0x12a4: rol    r10d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x12a8: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x12ae: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx]
 * - 0x12b1: rol    r10d,0x4 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x12b5: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x12b8: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12bf: sub    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c2: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c5: rol    r9d,0x18 [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c9: sub    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12da: mov    BYTE PTR [rcx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rcx+0x1],bh]
 * - 0x12e4: mov    BYTE PTR [rcx+0x3],r11b [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rcx+0x3],r11b]
 * - 0x1301: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1302: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1304: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1306: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rcx,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x110c: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: lowered cmp    rcx,rdx + ja     1307 <flow_5tuple_rss_hash_xdp+0x207> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_3, 130),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1119: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: lowered cmp    rsi,rdx + ja     1307 <flow_5tuple_rss_hash_xdp+0x207> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 127),
    /* 0x111f: lea    rsi,[rcx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1126: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: lowered cmp    rsi,rdx + ja     1307 <flow_5tuple_rss_hash_xdp+0x207> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 124),
    /* 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112d: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112f: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: movzx  edi,WORD PTR [rcx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1136: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x113a: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x113d: cmp    edi,0x800 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1143: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    edi,0x800 + jne    1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_1, 0, 117, 2048),
    /* 0x1149: lea    rdi,[rcx+0x2a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114d: cmp    rdi,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1150: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    rdi,rdx + ja     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_3, 114),
    /* 0x1156: movzx  edi,BYTE PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1159: mov    r8d,edi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x115c: and    r8b,0xf0 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_5, 0, 0, 240),
    /* 0x1160: cmp    r8b,0x40 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1164: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    r8b,0x40 + jne    1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, 109, 64),
    /* 0x116a: and    edi,0xf [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 15), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x116d: cmp    dil,0x5 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1171: jb     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    dil,0x5 + jb     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_1, 0, 106, 5),
    /* 0x1177: lea    rsi,[rsi+rdi*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_2, BPF_REG_1, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x117b: cmp    rsi,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x117e: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    rsi,rdx + ja     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 103),
    /* 0x1184: movzx  r11d,BYTE PTR [rcx+0x18] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1189: movzx  edi,BYTE PTR [rcx+0x19] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 25), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x118d: movzx  ebx,BYTE PTR [rcx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1191: cmp    ebx,0x11 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1194: je     119f <flow_5tuple_rss_hash_xdp+0x9f> [bpf-branch: lowered cmp    ebx,0x11 + je     119f <flow_5tuple_rss_hash_xdp+0x9f> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 1, 17),
    /* 0x1196: cmp    ebx,0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1199: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    ebx,0x6 + jne    1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 97, 6),
    /* 0x119f: lea    r8,[rsi+0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 4), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11a3: cmp    r8,rdx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11a6: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    r8,rdx + ja     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_5, BPF_REG_3, 94),
    /* 0x11ac: mov    eax,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r11d] */
    /* 0x11af: shl    eax,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 8),
    /* 0x11b2: or     eax,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x11b4: mov    r8d,DWORD PTR [rcx+0x22] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11b8: mov    r10d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,DWORD PTR [rcx+0x26]] */
    /* 0x11bc: bswap  r10d [warning-unmapped: BSWAP destination r10d is not in the BPF JIT register file] */
    /* 0x11bf: bswap  r8d [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11c2: movzx  edx,WORD PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11c5: movzx  edi,WORD PTR [rsi+0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11c9: rol    dx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x11cd: movzx  esi,dx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11d0: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x11d4: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11d7: lea    r9d,[rax+r8*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_0, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11db: lea    ebp,[r10-0x61c88647] [warning-unmapped: LEA operands are not representable] */
    /* 0x11e2: mov    edx,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x11e4: shl    edx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 16),
    /* 0x11e7: or     edx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x11e9: lea    r15d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ed: lea    r14d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f1: add    r14d,0x12345678 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_8, 0, 0, 305419896),
    /* 0x11f8: sub    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x11fb: add    r9d,0xdeadbeef [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 3735928559),
    /* 0x1202: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1206: xor    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1209: lea    r9d,[r10+r15*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r15*1]] */
    /* 0x120d: add    r9d,0xb06bd031 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 2959855665),
    /* 0x1214: mov    r15d,r14d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1217: rol    r15d,0x6 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x121b: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x121e: xor    r15d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x1221: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1224: sub    r9d,r15d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_9, 0, 0),
    /* 0x1227: mov    ebp,r15d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r15d] */
    /* 0x122a: rol    ebp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: ebp] */
    /* 0x122d: xor    ebp,r9d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1230: add    r15d,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1233: mov    r9d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r9d,ebp] */
    /* 0x1236: rol    r9d,0x10 [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 16, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x123a: sub    r14d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x123d: xor    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1240: add    ebp,r15d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1243: sub    r15d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_9, 0, 0),
    /* 0x1246: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1249: rol    r14d,0x13 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 19, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x124d: xor    r14d,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1250: add    r9d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x1253: xor    r8d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1256: rol    r8d,0x7 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 7, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x125a: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x125d: add    r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_9, 0, 0),
    /* 0x1260: add    r9d,edx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x1263: add    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1266: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x126a: xor    r14d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x126d: mov    edx,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_6, 0, 0),
    /* 0x126f: shl    edx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x1272: or     edx,eax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1274: add    edx,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_8, 0, 0),
    /* 0x1277: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x127a: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d] */
    /* 0x127d: rol    r10d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x1281: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1284: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx] */
    /* 0x1287: rol    r10d,0xb [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x128b: xor    r8d,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_3, 0, 0),
    /* 0x128e: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1291: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1294: mov    r10d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r8d] */
    /* 0x1297: rol    r10d,0x19 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x129b: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x129e: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x12a1: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d] */
    /* 0x12a4: rol    r10d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x12a8: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x12ab: xor    r8d,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_3, 0, 0),
    /* 0x12ae: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx] */
    /* 0x12b1: rol    r10d,0x4 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x12b5: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x12b8: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x12bb: rol    r8d,0xe [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 14, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x12bf: sub    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x12c2: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x12c5: rol    r9d,0x18 [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 24, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x12c9: sub    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x12cc: shl    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x12cf: shl    esi,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 8),
    /* 0x12d2: or     ebx,esi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_2, 0, 0),
    /* 0x12d4: xor    ebx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x12d6: xor    esi,eax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x12d8: mov    BYTE PTR [rcx],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12da: mov    BYTE PTR [rcx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rcx+0x1],bh] */
    /* 0x12dd: shr    esi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_2, 0, 0, 16),
    /* 0x12e0: mov    BYTE PTR [rcx+0x2],sil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12e4: mov    BYTE PTR [rcx+0x3],r11b [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rcx+0x3],r11b] */
    /* 0x12e8: mov    BYTE PTR [rcx+0x4],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12eb: mov    BYTE PTR [rcx+0x5],dh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12ee: mov    eax,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x12f0: shr    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x12f3: mov    BYTE PTR [rcx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12f6: shr    edx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x12f9: mov    BYTE PTR [rcx+0x7],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12fc: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1301: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1302: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1304: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1306: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1307: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
