# simple

## Original C
```c
#include "common.h"

static __always_inline int bench_simple(const u8 *data, u32 len, u64 *out)
{
    (void)data;
    (void)len;
    *out = 12345678ULL;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(simple_xdp, bench_simple, simple_input_value, 64U)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <simple_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	77 2b                	ja     1139 <simple_xdp+0x39>
    110e:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1112:	48 39 d6             	cmp    rsi,rdx
    1115:	77 22                	ja     1139 <simple_xdp+0x39>
    1117:	48 8d 71 48          	lea    rsi,[rcx+0x48]
    111b:	48 39 d6             	cmp    rsi,rdx
    111e:	77 19                	ja     1139 <simple_xdp+0x39>
    1120:	66 c7 01 4e 61       	mov    WORD PTR [rcx],0x614e
    1125:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
    1129:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
    1130:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
    1134:	b8 02 00 00 00       	mov    eax,0x2
    1139:	c3                   	ret

Disassembly of section .fini:
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	31 c0                	xor    eax,eax
   e:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  12:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  16:	48 39 f7             	cmp    rdi,rsi
  19:	77 4e                	ja     0x69
  1b:	48 89 fa             	mov    rdx,rdi
  1e:	48 83 c2 08          	add    rdx,0x8
  22:	48 39 f2             	cmp    rdx,rsi
  25:	77 42                	ja     0x69
  27:	48 89 fa             	mov    rdx,rdi
  2a:	48 83 c2 48          	add    rdx,0x48
  2e:	48 39 f2             	cmp    rdx,rsi
  31:	77 36                	ja     0x69
  33:	be bc 00 00 00       	mov    esi,0xbc
  38:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
  3c:	be 61 00 00 00       	mov    esi,0x61
  41:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
  45:	be 4e 00 00 00       	mov    esi,0x4e
  4a:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
  4e:	31 f6                	xor    esi,esi
  50:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
  54:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
  58:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
  5c:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
  60:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
  64:	b8 02 00 00 00       	mov    eax,0x2
  69:	c9                   	leave
  6a:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   6:	8b 57 04             	mov    edx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 d1                	cmp    ecx,edx
   d:	77 2b                	ja     0x3a
   f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  13:	48 39 d6             	cmp    rsi,rdx
  16:	77 22                	ja     0x3a
  18:	48 8d 71 48          	lea    rsi,[rcx+0x48]
  1c:	48 39 d6             	cmp    rsi,rdx
  1f:	77 19                	ja     0x3a
  21:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
  25:	66 c7 01 4e 61       	mov    WORD PTR [rcx],0x614e
  2a:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
  31:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
  35:	b8 02 00 00 00       	mov    eax,0x2
  3a:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 2
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: ja     1139 <simple_xdp+0x39> [bpf-branch: lowered cmp    rcx,rdx + ja     1139 <simple_xdp+0x39> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_3, 17),
    /* 0x110e: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1112: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1115: ja     1139 <simple_xdp+0x39> [bpf-branch: lowered cmp    rsi,rdx + ja     1139 <simple_xdp+0x39> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 12),
    /* 0x1117: lea    rsi,[rcx+0x48] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 72), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111b: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x111e: ja     1139 <simple_xdp+0x39> [bpf-branch: lowered cmp    rsi,rdx + ja     1139 <simple_xdp+0x39> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 7),
    /* 0x1120: mov    WORD PTR [rcx],0x614e [bpf-jit: immediate memory store] */
    HC_ST(BPF_H, BPF_REG_4, 0, 24910),
    /* 0x1125: mov    BYTE PTR [rcx+0x2],0xbc [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_STORE_IMM_PAYLOAD(BPF_REG_4, 2, 188), MICRO_HANDCRAFT_BPF_X86_MOVB_IMM_MEM),
    /* 0x1129: mov    DWORD PTR [rcx+0x3],0x0 [bpf-jit: immediate memory store] */
    HC_ST(BPF_W, BPF_REG_4, 3, 0),
    /* 0x1130: mov    BYTE PTR [rcx+0x7],0x0 [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_STORE_IMM_PAYLOAD(BPF_REG_4, 7, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_IMM_MEM),
    /* 0x1134: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1139: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 80 01 00 00 	sub    rsp,0x180
  13:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  17:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
  1b:	31 c0                	xor    eax,eax
  1d:	48 39 d1             	cmp    rcx,rdx
  20:	48 39 d1             	cmp    rcx,rdx
  23:	77 32                	ja     0x57
  25:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  29:	48 39 d6             	cmp    rsi,rdx
  2c:	48 39 d6             	cmp    rsi,rdx
  2f:	77 26                	ja     0x57
  31:	48 8d 71 48          	lea    rsi,[rcx+0x48]
  35:	48 39 d6             	cmp    rsi,rdx
  38:	48 39 d6             	cmp    rsi,rdx
  3b:	77 1a                	ja     0x57
  3d:	66 c7 41 00 4e 61    	mov    WORD PTR [rcx+0x0],0x614e
  43:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
  47:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
  4e:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
  52:	b8 02 00 00 00       	mov    eax,0x2
  57:	c9                   	leave
  58:	c3                   	ret
```
