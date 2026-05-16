# simple_packet

## Original C
```c
#include "common.h"

static __always_inline int bench_simple_packet(const u8 *data, u32 len, u64 *out)
{
    (void)data;
    (void)len;
    *out = 12345678ULL;
    return 0;
}

DEFINE_PACKET_BACKED_XDP_BENCH(simple_packet_xdp, bench_simple_packet)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <simple_packet_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	77 22                	ja     1130 <simple_packet_xdp+0x30>
    110e:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1112:	48 39 d6             	cmp    rsi,rdx
    1115:	77 19                	ja     1130 <simple_packet_xdp+0x30>
    1117:	66 c7 01 4e 61       	mov    WORD PTR [rcx],0x614e
    111c:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
    1120:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
    1127:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
    112b:	b8 02 00 00 00       	mov    eax,0x2
    1130:	c3                   	ret

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
   e:	48 8b 77 00          	mov    rsi,QWORD PTR [rdi+0x0]
  12:	48 8b 7f 08          	mov    rdi,QWORD PTR [rdi+0x8]
  16:	48 39 fe             	cmp    rsi,rdi
  19:	77 42                	ja     0x5d
  1b:	48 89 f2             	mov    rdx,rsi
  1e:	48 83 c2 08          	add    rdx,0x8
  22:	48 39 fa             	cmp    rdx,rdi
  25:	77 36                	ja     0x5d
  27:	bf bc 00 00 00       	mov    edi,0xbc
  2c:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
  30:	bf 61 00 00 00       	mov    edi,0x61
  35:	40 88 7e 01          	mov    BYTE PTR [rsi+0x1],dil
  39:	bf 4e 00 00 00       	mov    edi,0x4e
  3e:	40 88 7e 00          	mov    BYTE PTR [rsi+0x0],dil
  42:	31 ff                	xor    edi,edi
  44:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
  48:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
  4c:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
  50:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
  54:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
  58:	b8 02 00 00 00       	mov    eax,0x2
  5d:	c9                   	leave
  5e:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 07                	mov    eax,DWORD PTR [rdi]
   6:	8b 4f 04             	mov    ecx,DWORD PTR [rdi+0x4]
   9:	39 c8                	cmp    eax,ecx
   b:	77 09                	ja     0x16
   d:	48 8d 50 08          	lea    rdx,[rax+0x8]
  11:	48 39 ca             	cmp    rdx,rcx
  14:	76 03                	jbe    0x19
  16:	31 c0                	xor    eax,eax
  18:	c3                   	ret
  19:	c6 40 02 bc          	mov    BYTE PTR [rax+0x2],0xbc
  1d:	66 c7 00 4e 61       	mov    WORD PTR [rax],0x614e
  22:	c7 40 03 00 00 00 00 	mov    DWORD PTR [rax+0x3],0x0
  29:	c6 40 07 00          	mov    BYTE PTR [rax+0x7],0x0
  2d:	b8 02 00 00 00       	mov    eax,0x2
  32:	c3                   	ret
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
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: ja     1130 <simple_packet_xdp+0x30> [bpf-branch: lowered cmp    rcx,rdx + ja     1130 <simple_packet_xdp+0x30> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_3, 12),
    /* 0x110e: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1112: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1115: ja     1130 <simple_packet_xdp+0x30> [bpf-branch: lowered cmp    rsi,rdx + ja     1130 <simple_packet_xdp+0x30> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 7),
    /* 0x1117: mov    WORD PTR [rcx],0x614e [bpf-jit: immediate memory store] */
    HC_ST(BPF_H, BPF_REG_4, 0, 24910),
    /* 0x111c: mov    BYTE PTR [rcx+0x2],0xbc [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_STORE_IMM_PAYLOAD(BPF_REG_4, 2, 188), MICRO_HANDCRAFT_BPF_X86_MOVB_IMM_MEM),
    /* 0x1120: mov    DWORD PTR [rcx+0x3],0x0 [bpf-jit: immediate memory store] */
    HC_ST(BPF_W, BPF_REG_4, 3, 0),
    /* 0x1127: mov    BYTE PTR [rcx+0x7],0x0 [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_STORE_IMM_PAYLOAD(BPF_REG_4, 7, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_IMM_MEM),
    /* 0x112b: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1130: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
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
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	31 db                	xor    ebx,ebx
  1a:	45 31 ed             	xor    r13d,r13d
  1d:	45 31 f6             	xor    r14d,r14d
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
  28:	31 c0                	xor    eax,eax
  2a:	48 39 d1             	cmp    rcx,rdx
  2d:	48 39 d1             	cmp    rcx,rdx
  30:	77 26                	ja     0x58
  32:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  36:	48 39 d6             	cmp    rsi,rdx
  39:	48 39 d6             	cmp    rsi,rdx
  3c:	77 1a                	ja     0x58
  3e:	66 c7 41 00 4e 61    	mov    WORD PTR [rcx+0x0],0x614e
  44:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
  48:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
  4f:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
  53:	b8 02 00 00 00       	mov    eax,0x2
  58:	41 5e                	pop    r14
  5a:	41 5d                	pop    r13
  5c:	5b                   	pop    rbx
  5d:	c9                   	leave
  5e:	c3                   	ret
```
