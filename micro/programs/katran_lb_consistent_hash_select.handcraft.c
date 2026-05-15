#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 280
 *
 * - 0x1100: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1101: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1103: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1105: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1107: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1109: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x110a: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x110d: mov    rbx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1140: mov    r10,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rbx]
 * - 0x1143: sub    r10,rsi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1163: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ad: movzx  ebp,WORD PTR [rcx+0x18] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11b1: movzx  r11d,WORD PTR [rcx+0x22] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x11d3: lea    r12,[rcx+0x3e] [warning-unmapped: LEA operands are not representable]
 * - 0x11da: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch]
 * - 0x11e9: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f8: movzx  r12d,BYTE PTR [rcx+0x1c] [warning-unmapped: destination register r12d is not in the BPF JIT register file]
 * - 0x1201: je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12d,0x2c + je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch]
 * - 0x120b: jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> [warning-unmapped: cannot lower cmp    r12d,0x3a + jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> to BPF branch]
 * - 0x1214: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1217: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10]
 * - 0x1221: mov    rsi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rsi,r10]
 * - 0x122f: xor    rsi,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x1232: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x124e: mov    r11d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,DWORD PTR [rcx+0x26]]
 * - 0x1252: mov    ebp,DWORD PTR [rcx+0x2a] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [rcx+0x2a]]
 * - 0x126c: je     1288 <katran_lb_consistent_hash_select_xdp+0x188> [warning-unmapped: cannot lower cmp    r12d,0x11 + je     1288 <katran_lb_consistent_hash_select_xdp+0x188> to BPF branch]
 * - 0x1272: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch]
 * - 0x1274: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1288: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x129e: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch]
 * - 0x12ad: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c4: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12d1: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch]
 * - 0x12db: mov    r12d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,edx]
 * - 0x12de: shl    r12b,0x4 [warning-unmapped: ALU destination r12b is not in the BPF JIT register file]
 * - 0x12e2: or     r12b,r15b [warning-unmapped: ALU destination r12b is not in the BPF JIT register file]
 * - 0x12ee: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp]
 * - 0x12f6: lea    r9d,[r11-0x21523f01] [warning-unmapped: LEA base/index not in BPF register file: [r11-0x21523f01]]
 * - 0x12fd: mov    r10d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebp]
 * - 0x1300: and    r10d,0xff0000 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1307: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x130a: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp]
 * - 0x1312: add    edi,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1315: movzx  ebx,bpl [warning-unmapped: movzx source size not recognized: bpl]
 * - 0x131b: mov    rdx,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1322: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x1325: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x132f: add    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1335: mov    r10d,r14d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r14d]
 * - 0x1338: rol    r10d,0x6 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x133c: xor    r10d,r8d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x133f: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1342: lea    edi,[r10+r14*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r14*1]]
 * - 0x1346: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1349: rol    r10d,0x8 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x1352: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1355: sub    r14d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1358: mov    r11d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r10d]
 * - 0x135b: rol    r11d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r11d]
 * - 0x135f: xor    r11d,r14d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1362: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1365: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x1368: mov    r14d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r11d]
 * - 0x1372: add    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1375: lea    r9d,[r14+r11*1] [warning-unmapped: LEA base/index not in BPF register file: [r14+r11*1]]
 * - 0x1379: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1380: add    r11d,ebx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1383: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1386: xor    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1389: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x138f: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1392: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x1398: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x139b: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x139e: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x13a1: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x13a7: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13aa: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x13ad: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13b3: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x13b6: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x13b9: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x13bf: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x13c2: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x13c5: rol    r11d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r11d]
 * - 0x13c9: sub    r9d,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x13cc: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13d2: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x13d5: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13d8: add    r9d,0xe0adc0f7 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13df: mov    r11d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r8d]
 * - 0x13e2: add    r11d,0x70ccc0f7 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x13e9: mov    r10d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r11d]
 * - 0x13ec: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x13f8: shrd   edi,r11d,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   edi,r11d,0x12]
 * - 0x13fd: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1400: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1403: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x1409: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x140c: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x140f: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1415: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1418: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x141e: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1421: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1424: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1427: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x142d: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1430: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1433: rol    r9d,0xe [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1437: sub    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x143a: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x143d: rol    r11d,0x18 [warning-unmapped: ROL width/register not supported by current selectors: r11d]
 * - 0x1441: sub    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1449: imul   rdi,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rdi,r10]
 * - 0x1451: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1454: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1458: or     r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x145b: sub    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1464: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1467: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x146b: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x146e: mov    r11,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rdi]
 * - 0x1471: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1475: add    r9,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1478: add    r9,0x101640a [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x147f: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1482: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9]
 * - 0x1485: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1489: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x148c: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x148f: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x149e: add    rbx,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x14a1: xor    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14ab: mov    r9,rbx [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14ae: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14b5: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14b8: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x14be: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14c1: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14c5: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14c8: mov    r10,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rdi]
 * - 0x14cb: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14cf: add    r9,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x14d2: inc    r9 [warning-reg-remap: inc lowered to add immediate; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14d5: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14d8: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14e2: mov    r10,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r9]
 * - 0x14e5: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14e9: add    r10,rdi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14ec: xor    r10,r9 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14ef: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10]
 * - 0x14f2: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x14f6: add    r11,rsi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x14f9: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x14fc: mov    r9,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r9,r10]
 * - 0x14ff: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1503: add    r9,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1521: movzx  r8d,r12b [warning-unmapped: movzx source size not recognized: r12b]
 * - 0x1528: mov    r11d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,edx]
 * - 0x152b: shr    r11d,0x10 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1532: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1543: movzx  r11d,di [warning-unmapped: movzx source size not recognized: di]
 * - 0x1547: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1551: cmovb  r11,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1555: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x155b: movzx  r8d,r11w [warning-unmapped: movzx source size not recognized: r11w]
 * - 0x1569: cmovb  r8,r11 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1573: movzx  r11d,r8w [warning-unmapped: movzx source size not recognized: r8w]
 * - 0x1577: add    r11,rdi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1581: cmovb  r11,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1585: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x158b: add    edi,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x158e: xor    r9,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x15a9: cmovb  edi,r11d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x15c3: mov    rdx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x15ca: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x15da: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x15e2: lea    r12,[rcx+0x32] [warning-unmapped: LEA operands are not representable]
 * - 0x15e9: jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> [warning-unmapped: cannot lower cmp    r12,rbx + jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> to BPF branch]
 * - 0x15fe: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1612: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1613: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1615: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1617: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1619: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x161b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x162a: movzx  r9d,WORD PTR [rcx+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x163c: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x164d: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x165a: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch]
 * - 0x165c: rol    bp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: bp]
 * - 0x1660: movzx  esi,bp [warning-unmapped: movzx source size not recognized: bp]
 * - 0x166a: or     r11d,r8d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x166d: or     r11d,edx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1670: movzx  r9d,WORD PTR [rcx+0x2a] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1675: mov    ebx,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x167e: mov    r10d,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebx]
 * - 0x1681: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1688: mov    ebp,0x70cc0000 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x70cc0000]
 * - 0x168d: shrd   ebp,ebx,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   ebp,ebx,0x12]
 * - 0x1691: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1694: lea    ebp,[r11-0x1f523f09] [warning-unmapped: LEA operands are not representable]
 * - 0x169b: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x169e: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d]
 * - 0x16a5: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16a8: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp]
 * - 0x16af: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x16b4: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16be: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16c1: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16c4: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d]
 * - 0x16cb: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16ce: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x16d0: rol    ebp,0xe [warning-unmapped: ROL width/register not supported by current selectors: ebp]
 * - 0x16d3: sub    ebx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x16d5: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16db: sub    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16e3: imul   rbx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rbx,r10]
 * - 0x16eb: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx]
 * - 0x16ed: shl    ebp,0x10 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16f0: or     ebp,ebx [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16f2: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16f5: mov    r11d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r11d]
 * - 0x16f8: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x16fb: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11]
 * - 0x1702: mov    r14,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r14,r11]
 * - 0x1716: xor    rbx,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1719: mov    r11,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rbx]
 * - 0x171c: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1727: add    r14,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x172a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x172d: add    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1736: add    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x173c: mov    r11,r14 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r14]
 * - 0x173f: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x174a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x174d: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1750: add    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1753: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1756: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11]
 * - 0x1759: shl    r10,0x6 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x175d: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1760: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11]
 * - 0x1767: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x176a: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file]
 * - 0x176d: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1770: mov    rbx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r10]
 * - 0x177a: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10]
 * - 0x177d: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1781: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1784: xor    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1787: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11]
 * - 0x1794: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11]
 * - 0x1797: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x179b: rol    r9w,0x8 [warning-reg-remap: rolw imm8 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17a0: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x17a3: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17aa: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17bd: mov    r9d,edx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17c0: shr    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17c7: lea    rdi,[r9+r8*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17d9: movzx  r9d,di [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17dd: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17e7: cmovb  r9,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x17eb: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17f1: movzx  r8d,r9w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17ff: cmovb  r8,r9 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1809: movzx  r9d,r8w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x180d: add    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1817: cmovb  r9,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x181b: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1821: add    edi,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1824: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x183f: cmovb  edi,r9d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1859: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10]
 * - 0x1860: mov    rdi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdi,r10]
 * - 0x1870: xor    rdx,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x188e: mov    r9d,0x3 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1101: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1103: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1105: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1107: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1109: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x110a: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x110d: mov    rbx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    /* 0x1111: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1113: cmp    rcx,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1116: ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> [bpf-branch: lowered cmp    rcx,rbx + ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_6, 243),
    /* 0x111c: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1120: cmp    rsi,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1123: ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> [bpf-branch: lowered cmp    rsi,rbx + ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_6, 240),
    /* 0x1129: lea    rdx,[rcx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_4, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112d: cmp    rdx,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1130: ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> [bpf-branch: lowered cmp    rdx,rbx + ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_6, 237),
    /* 0x1136: movabs rax,0x9e3779b97f4a7c15 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x9e3779b97f4a7c15ULL),
    /* 0x1140: mov    r10,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rbx] */
    /* 0x1143: sub    r10,rsi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1146: movzx  esi,WORD PTR [rcx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x114a: cmp    esi,0xdd86 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1150: je     11e5 <katran_lb_consistent_hash_select_xdp+0xe5> [bpf-branch: lowered cmp    esi,0xdd86 + je     11e5 <katran_lb_consistent_hash_select_xdp+0xe5> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_2, 0, 32, 56710),
    /* 0x1156: cmp    esi,0x8 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1159: jne    1214 <katran_lb_consistent_hash_select_xdp+0x114> [bpf-branch: lowered cmp    esi,0x8 + jne    1214 <katran_lb_consistent_hash_select_xdp+0x114> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_2, 0, 37, 8),
    /* 0x115f: lea    rsi,[rcx+0x2a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1163: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x1169: cmp    rsi,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x116c: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rsi,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_6, 212),
    /* 0x1172: movzx  edx,BYTE PTR [rdx] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1175: and    dl,0xf [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_K, BPF_REG_3, 0, 0, 15),
    /* 0x1178: cmp    dl,0x5 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x117b: jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    dl,0x5 + jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_3, 0, 208, 5),
    /* 0x1181: movzx  edx,BYTE PTR [rcx+0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 28), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1185: movzx  esi,BYTE PTR [rcx+0x1d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 29), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1189: and    edx,0x3f [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 63), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x118c: or     dx,si [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x118f: jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered flags from or     dx,si + jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_3, 0, 200, 0),
    /* 0x1195: movzx  r14d,BYTE PTR [rcx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x119a: mov    esi,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x119f: cmp    r14d,0x1 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11a3: je     1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r14d,0x1 + je     1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_8, 0, 23, 1),
    /* 0x11a9: movzx  edi,BYTE PTR [rcx+0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ad: movzx  ebp,WORD PTR [rcx+0x18] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11b1: movzx  r11d,WORD PTR [rcx+0x22] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x11b6: movzx  r8d,BYTE PTR [rcx+0x24] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 36), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11bb: movzx  edx,BYTE PTR [rcx+0x25] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 37), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11bf: mov    r15d,DWORD PTR [rcx+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11c3: cmp    r14d,0x11 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11c7: je     15e2 <katran_lb_consistent_hash_select_xdp+0x4e2> [bpf-branch: lowered cmp    r14d,0x11 + je     15e2 <katran_lb_consistent_hash_select_xdp+0x4e2> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_8, 0, 187, 17),
    /* 0x11cd: cmp    r14d,0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11d1: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r14d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_8, 0, 13, 6),
    /* 0x11d3: lea    r12,[rcx+0x3e] [warning-unmapped: LEA operands are not representable] */
    /* 0x11d7: cmp    r12,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11da: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch] */
    /* 0x11e0: jmp    161d <katran_lb_consistent_hash_select_xdp+0x51d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 201, 0),
    /* 0x11e5: lea    rdx,[rcx+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_4, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11e9: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x11ef: cmp    rdx,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x11f2: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rdx,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_6, 181),
    /* 0x11f8: movzx  r12d,BYTE PTR [rcx+0x1c] [warning-unmapped: destination register r12d is not in the BPF JIT register file] */
    /* 0x11fd: cmp    r12d,0x2c [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1201: je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12d,0x2c + je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch] */
    /* 0x1207: cmp    r12d,0x3a [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x120b: jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> [warning-unmapped: cannot lower cmp    r12d,0x3a + jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> to BPF branch] */
    /* 0x120d: mov    esi,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x1212: jmp    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 6, 0),
    /* 0x1214: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1217: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10] */
    /* 0x121a: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x121e: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1221: mov    rsi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rsi,r10] */
    /* 0x1224: shr    rsi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1228: add    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x122b: add    rsi,0x2 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x122f: xor    rsi,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1232: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 2),
    /* 0x1238: jmp    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 172, 0),
    /* 0x123d: movzx  edx,BYTE PTR [rcx+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1241: movzx  r15d,BYTE PTR [rcx+0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1246: movzx  r14d,WORD PTR [rcx+0x1a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_4, 26), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x124b: mov    edi,DWORD PTR [rcx+0x1e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 30), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x124e: mov    r11d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,DWORD PTR [rcx+0x26]] */
    /* 0x1252: mov    ebp,DWORD PTR [rcx+0x2a] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [rcx+0x2a]] */
    /* 0x1255: mov    r13d,DWORD PTR [rcx+0x2e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_4, 46), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x1259: mov    r8d,0xdeadc0ff [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 3735929087),
    /* 0x125f: add    r8d,DWORD PTR [rcx+0x22] [exact-kinsn: addl memory-source kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 34, BPF_REG_6, 0), MICRO_HANDCRAFT_BPF_X86_ADDL_MEM),
    /* 0x1263: mov    esi,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x1268: cmp    r12d,0x11 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x126c: je     1288 <katran_lb_consistent_hash_select_xdp+0x188> [warning-unmapped: cannot lower cmp    r12d,0x11 + je     1288 <katran_lb_consistent_hash_select_xdp+0x188> to BPF branch] */
    /* 0x126e: cmp    r12d,0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1272: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch] */
    /* 0x1274: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1279: lea    rdi,[rcx+0x52] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 82), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x127d: cmp    rdi,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1280: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rdi,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_6, 154),
    /* 0x1286: jmp    129a <katran_lb_consistent_hash_select_xdp+0x19a> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 3, 0),
    /* 0x1288: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x128d: lea    rdi,[rcx+0x46] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 70), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1291: cmp    rdi,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1294: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rdi,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_6, 150),
    /* 0x129a: cmp    r12d,0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x129e: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch] */
    /* 0x12a0: cmp    r13d,0x101640a [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x12a7: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r13d,0x101640a + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -24, 16868362),
    /* 0x12a9: movzx  edi,WORD PTR [rcx+0x40] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 64), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x12ad: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 2),
    /* 0x12b3: cmp    edi,0x901f [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x12b9: jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered cmp    edi,0x901f + jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_1, 0, 146, 36895),
    /* 0x12bf: mov    esi,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x12c4: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x12ca: cmp    r10,0x5ea [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x12d1: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch] */
    /* 0x12d7: shr    r15b,0x4 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_9, 0, 0, 4),
    /* 0x12db: mov    r12d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,edx] */
    /* 0x12de: shl    r12b,0x4 [warning-unmapped: ALU destination r12b is not in the BPF JIT register file] */
    /* 0x12e2: or     r12b,r15b [warning-unmapped: ALU destination r12b is not in the BPF JIT register file] */
    /* 0x12e5: rol    r14w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x12ea: movzx  esi,r14w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x12ee: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp] */
    /* 0x12f0: and    edi,0xff000000 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 4278190080), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x12f6: lea    r9d,[r11-0x21523f01] [warning-unmapped: LEA base/index not in BPF register file: [r11-0x21523f01]] */
    /* 0x12fd: mov    r10d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebp] */
    /* 0x1300: and    r10d,0xff0000 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1307: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x130a: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp] */
    /* 0x130c: and    edi,0xff00 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 65280), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x1312: add    edi,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1315: movzx  ebx,bpl [warning-unmapped: movzx source size not recognized: bpl] */
    /* 0x1319: add    ebx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x131b: mov    rdx,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1320: mov    edi,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x1322: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x1325: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1328: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x132c: xor    r14d,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_1, 0, 0),
    /* 0x132f: add    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1332: sub    r8d,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_5, BPF_REG_8, 0, 0),
    /* 0x1335: mov    r10d,r14d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r14d] */
    /* 0x1338: rol    r10d,0x6 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x133c: xor    r10d,r8d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x133f: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1342: lea    edi,[r10+r14*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r14*1]] */
    /* 0x1346: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1349: rol    r10d,0x8 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x134d: movzx  r8d,WORD PTR [rcx+0x3e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 62), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1352: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1355: sub    r14d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1358: mov    r11d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r10d] */
    /* 0x135b: rol    r11d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r11d] */
    /* 0x135f: xor    r11d,r14d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1362: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1365: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x1368: mov    r14d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r11d] */
    /* 0x136b: rol    r14d,0x13 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 19, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x136f: xor    r14d,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_1, 0, 0),
    /* 0x1372: add    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1375: lea    r9d,[r14+r11*1] [warning-unmapped: LEA base/index not in BPF register file: [r14+r11*1]] */
    /* 0x1379: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x137c: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1380: add    r11d,ebx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1383: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1386: xor    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1389: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x138c: rol    edi,0xe [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 14, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x138f: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1392: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x1395: rol    edi,0xb [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1398: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x139b: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x139e: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x13a1: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x13a4: rol    edi,0x19 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 25, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13a7: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x13aa: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x13ad: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x13b0: rol    edi,0x10 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13b3: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x13b6: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x13b9: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x13bc: rol    edi,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13bf: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x13c2: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x13c5: rol    r11d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r11d] */
    /* 0x13c9: sub    r9d,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x13cc: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x13cf: rol    edi,0x18 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 24, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13d2: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x13d5: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x13d8: add    r9d,0xe0adc0f7 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 3769483511),
    /* 0x13df: mov    r11d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r8d] */
    /* 0x13e2: add    r11d,0x70ccc0f7 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x13e9: mov    r10d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r11d] */
    /* 0x13ec: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x13f3: mov    edi,0x70cc0000 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 1892417536),
    /* 0x13f8: shrd   edi,r11d,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   edi,r11d,0x12] */
    /* 0x13fd: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1400: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1403: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x1406: rol    edi,0xb [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1409: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x140c: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x140f: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x1412: rol    edi,0x19 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 25, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1415: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1418: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x141b: rol    edi,0x10 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x141e: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1421: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1424: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1427: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x142a: rol    edi,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x142d: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1430: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1433: rol    r9d,0xe [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 14, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1437: sub    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x143a: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x143d: rol    r11d,0x18 [warning-unmapped: ROL width/register not supported by current selectors: r11d] */
    /* 0x1441: sub    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1444: mov    edi,0xffff0001 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 4294901761),
    /* 0x1449: imul   rdi,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rdi,r10] */
    /* 0x144d: shr    rdi,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1451: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1454: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x1458: or     r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x145b: sub    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x145e: mov    rdi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1461: add    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x1464: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1467: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 6),
    /* 0x146b: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x146e: mov    r11,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rdi] */
    /* 0x1471: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1475: add    r9,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1478: add    r9,0x101640a [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 16868362),
    /* 0x147f: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1482: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9] */
    /* 0x1485: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1489: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x148c: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x148f: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1492: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1496: mov    ebx,0x901f0000 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_6, 0, 0, 2417950720),
    /* 0x149b: add    rbx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x149e: add    rbx,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x14a1: xor    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x14a4: mov    rdi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14a7: shl    rdi,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 6),
    /* 0x14ab: mov    r9,rbx [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14ae: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x14b2: add    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x14b5: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x14b8: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x14bb: xor    rdi,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_6, 0, 0),
    /* 0x14be: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14c1: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 6),
    /* 0x14c5: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x14c8: mov    r10,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rdi] */
    /* 0x14cb: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14cf: add    r9,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x14d2: inc    r9 [warning-reg-remap: inc lowered to add immediate; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x14d5: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x14d8: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14db: shl    rdi,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 6),
    /* 0x14df: add    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x14e2: mov    r10,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r9] */
    /* 0x14e5: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14e9: add    r10,rdi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14ec: xor    r10,r9 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14ef: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10] */
    /* 0x14f2: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x14f6: add    r11,rsi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x14f9: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x14fc: mov    r9,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r9,r10] */
    /* 0x14ff: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1503: add    r9,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1506: rol    r8w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x150b: shl    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x150f: and    edx,0xffff0000 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 4294901760), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x1515: xor    edx,r8d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x1518: mov    edi,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x151a: add    edi,0x14 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 20),
    /* 0x151d: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x1521: movzx  r8d,r12b [warning-unmapped: movzx source size not recognized: r12b] */
    /* 0x1525: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1528: mov    r11d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,edx] */
    /* 0x152b: shr    r11d,0x10 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x152f: add    rdi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1532: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1535: add    rdi,0xdf3b [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 57147),
    /* 0x153c: mov    r8d,edi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x153f: shr    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x1543: movzx  r11d,di [warning-unmapped: movzx source size not recognized: di] */
    /* 0x1547: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x154a: cmp    rdi,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1551: cmovb  r11,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1555: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x1558: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x155b: movzx  r8d,r11w [warning-unmapped: movzx source size not recognized: r11w] */
    /* 0x155f: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x1562: cmp    r11,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1569: cmovb  r8,r11 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x156d: mov    edi,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1570: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1573: movzx  r11d,r8w [warning-unmapped: movzx source size not recognized: r8w] */
    /* 0x1577: add    r11,rdi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x157a: cmp    r8,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1581: cmovb  r11,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1585: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x1588: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x158b: add    edi,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x158e: xor    r9,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1591: or     edx,0x10ac [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 4268),
    /* 0x1597: shl    rdx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 32),
    /* 0x159b: or     rdx,0x200c80a [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 33605642),
    /* 0x15a2: cmp    r11,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x15a9: cmovb  edi,r11d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x15ad: shl    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x15b0: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x15b3: movabs rsi,0x200ffff000b [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x200ffff000bULL),
    /* 0x15bd: xor    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x15c0: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x15c3: mov    rdx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15c6: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x15ca: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15cd: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x15d1: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x15d4: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x15d7: add    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x15da: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x15dd: jmp    1873 <katran_lb_consistent_hash_select_xdp+0x773> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 119, 0),
    /* 0x15e2: lea    r12,[rcx+0x32] [warning-unmapped: LEA operands are not representable] */
    /* 0x15e6: cmp    r12,rbx [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x15e9: jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> [warning-unmapped: cannot lower cmp    r12,rbx + jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> to BPF branch] */
    /* 0x15eb: mov    esi,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x15f0: mov    rdx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15f3: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x15f7: mov    rdi,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15fa: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x15fe: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x1601: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1604: add    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1607: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x160a: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x160d: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1612: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1613: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1615: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1617: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1619: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x161b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x161c: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x161d: cmp    r15d,0x101640a [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1624: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r15d,0x101640a + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, -190, 16868362),
    /* 0x162a: movzx  r9d,WORD PTR [rcx+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 44), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x162f: cmp    r9d,0x901f [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1636: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r9d,0x901f + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, -193, 36895),
    /* 0x163c: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 2),
    /* 0x1642: cmp    r14b,0x6 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1646: jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered cmp    r14b,0x6 + jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_8, 0, -21, 6),
    /* 0x1648: mov    esi,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x164d: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x1653: cmp    r10,0x5ea [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x165a: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch] */
    /* 0x165c: rol    bp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: bp] */
    /* 0x1660: movzx  esi,bp [warning-unmapped: movzx source size not recognized: bp] */
    /* 0x1663: shl    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x1667: shl    edx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x166a: or     r11d,r8d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x166d: or     r11d,edx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1670: movzx  r9d,WORD PTR [rcx+0x2a] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 42), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1675: mov    ebx,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1678: add    ebx,0x70ccc0f7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_6, 0, 0, 1892466935),
    /* 0x167e: mov    r10d,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebx] */
    /* 0x1681: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1688: mov    ebp,0x70cc0000 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x70cc0000] */
    /* 0x168d: shrd   ebp,ebx,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   ebp,ebx,0x12] */
    /* 0x1691: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1694: lea    ebp,[r11-0x1f523f09] [warning-unmapped: LEA operands are not representable] */
    /* 0x169b: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x169e: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d] */
    /* 0x16a1: rol    r14d,0xb [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16a5: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16a8: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp] */
    /* 0x16ab: rol    r14d,0x19 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 25, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16af: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x16b1: sub    ebx,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_6, BPF_REG_8, 0, 0),
    /* 0x16b4: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16b7: mov    r14d,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x16ba: rol    r14d,0x10 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16be: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16c1: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16c4: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d] */
    /* 0x16c7: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16cb: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16ce: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x16d0: rol    ebp,0xe [warning-unmapped: ROL width/register not supported by current selectors: ebp] */
    /* 0x16d3: sub    ebx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x16d5: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16d8: rol    ebx,0x18 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_6, BPF_REG_6, 24, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16db: sub    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16de: mov    ebx,0xffff0001 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_6, 0, 0, 4294901761),
    /* 0x16e3: imul   rbx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rbx,r10] */
    /* 0x16e7: shr    rbx,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x16eb: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx] */
    /* 0x16ed: shl    ebp,0x10 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16f0: or     ebp,ebx [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16f2: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16f5: mov    r11d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r11d] */
    /* 0x16f8: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x16fb: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11] */
    /* 0x16fe: shl    rbx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 6),
    /* 0x1702: mov    r14,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r14,r11] */
    /* 0x1705: shr    r14,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1709: add    r14,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_0, 0, 0),
    /* 0x170c: add    rbx,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_8, 0, 0),
    /* 0x170f: add    rbx,0x101640a [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_6, 0, 0, 16868362),
    /* 0x1716: xor    rbx,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1719: mov    r11,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rbx] */
    /* 0x171c: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1720: mov    r14,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1723: shr    r14,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1727: add    r14,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x172a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x172d: add    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1730: mov    r14d,0x901f0000 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_8, 0, 0, 2417950720),
    /* 0x1736: add    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1739: xor    r14,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x173c: mov    r11,r14 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r14] */
    /* 0x173f: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1743: mov    rbx,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1746: shr    rbx,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x174a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x174d: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1750: add    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1753: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1756: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11] */
    /* 0x1759: shl    r10,0x6 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x175d: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1760: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11] */
    /* 0x1763: shr    rbx,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1767: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x176a: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file] */
    /* 0x176d: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1770: mov    rbx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r10] */
    /* 0x1773: shl    rbx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 6),
    /* 0x1777: add    rbx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x177a: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10] */
    /* 0x177d: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1781: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1784: xor    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1787: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11] */
    /* 0x178a: shl    rbx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 6),
    /* 0x178e: add    rbx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_2, 0, 0),
    /* 0x1791: add    rbx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x1794: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11] */
    /* 0x1797: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x179b: rol    r9w,0x8 [warning-reg-remap: rolw imm8 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x17a0: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x17a3: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x17a7: or     edx,r8d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x17aa: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x17ad: mov    r8d,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_2, 0, 0),
    /* 0x17b0: add    r8d,0x14 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 20),
    /* 0x17b4: rol    r8w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x17b9: movzx  r8d,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x17bd: mov    r9d,edx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x17c0: shr    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x17c4: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x17c7: lea    rdi,[r9+r8*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_9, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x17cb: add    rdi,0xdf3b [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 57147),
    /* 0x17d2: mov    r8d,edi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x17d5: shr    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x17d9: movzx  r9d,di [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x17dd: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x17e0: cmp    rdi,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x17e7: cmovb  r9,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x17eb: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x17ee: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x17f1: movzx  r8d,r9w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x17f5: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x17f8: cmp    r9,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x17ff: cmovb  r8,r9 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1803: mov    edi,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1806: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1809: movzx  r9d,r8w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x180d: add    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1810: cmp    r8,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x1817: cmovb  r9,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x181b: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x181e: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1821: add    edi,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x1824: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1827: or     edx,0x10ac [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 4268),
    /* 0x182d: shl    rdx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 32),
    /* 0x1831: or     rdx,0x200c80a [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 33605642),
    /* 0x1838: cmp    r9,0x10000 [cmp-state: sets flags; materialized by following jcc when possible] */
    /* 0x183f: cmovb  edi,r9d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1843: shl    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1846: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x1849: movabs rsi,0x200ffff000b [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x200ffff000bULL),
    /* 0x1853: xor    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x1856: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1859: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10] */
    /* 0x185c: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x1860: mov    rdi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdi,r10] */
    /* 0x1863: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1867: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x186a: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x186d: add    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1870: xor    rdx,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1873: mov    rsi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1876: shl    rsi,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 6),
    /* 0x187a: add    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x187d: mov    rdi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1880: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1884: add    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1887: add    rsi,0x3 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 3),
    /* 0x188b: xor    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x188e: mov    r9d,0x3 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 3),
    /* 0x1894: jmp    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -131, 0),
};

HC_EXPORT_PROGRAM(program)
