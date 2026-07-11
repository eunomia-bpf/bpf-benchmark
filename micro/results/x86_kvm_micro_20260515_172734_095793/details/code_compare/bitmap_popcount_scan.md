# bitmap_popcount_scan

## Original C
```c
#include "common.h"

#ifdef MICRO_NATIVE
#pragma clang attribute push (__attribute__((target("popcnt"))), apply_to = function)
#endif

#define BITCOUNT_MAX_COUNT 256U
#define BITCOUNT_INPUT_SIZE (8U + BITCOUNT_MAX_COUNT * 8U)

static __always_inline u64 micro_popcount64(u64 value)
{
    return (u64)__builtin_popcountll(value);
}

static __always_inline int bench_bitmap_popcount_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);

    if (count != BITCOUNT_MAX_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, BITCOUNT_MAX_COUNT * 8U)) {
        return -1;
    }

    u64 acc = seed;
    for (u32 i = 0; i < BITCOUNT_MAX_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8);
        acc += micro_popcount64(value ^ acc);
        acc ^= value >> (i & 7);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(bitmap_popcount_scan_xdp, bench_bitmap_popcount_scan, bitmap_popcount_scan_input_value, BITCOUNT_INPUT_SIZE)

#ifdef MICRO_NATIVE
#pragma clang attribute pop
#endif
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <bitmap_popcount_scan_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <bitmap_popcount_scan_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <bitmap_popcount_scan_xdp+0xe>
    1118:	48 8d ba 10 08 00 00 	lea    rdi,[rdx+0x810]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <bitmap_popcount_scan_xdp+0xe>
    1124:	81 3e 00 01 00 00    	cmp    DWORD PTR [rsi],0x100
    112a:	75 e2                	jne    110e <bitmap_popcount_scan_xdp+0xe>
    112c:	8b 4a 0c             	mov    ecx,DWORD PTR [rdx+0xc]
    112f:	31 c0                	xor    eax,eax
    1131:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1138:	0f 1f 84 00 00 00 00 
    113f:	00 
    1140:	48 8b 74 c2 10       	mov    rsi,QWORD PTR [rdx+rax*8+0x10]
    1145:	48 89 f7             	mov    rdi,rsi
    1148:	48 31 cf             	xor    rdi,rcx
    114b:	f3 48 0f b8 ff       	popcnt rdi,rdi
    1150:	48 01 cf             	add    rdi,rcx
    1153:	89 c1                	mov    ecx,eax
    1155:	80 e1 07             	and    cl,0x7
    1158:	48 d3 ee             	shr    rsi,cl
    115b:	48 89 f1             	mov    rcx,rsi
    115e:	48 31 f9             	xor    rcx,rdi
    1161:	48 ff c0             	inc    rax
    1164:	48 3d 00 01 00 00    	cmp    rax,0x100
    116a:	75 d4                	jne    1140 <bitmap_popcount_scan_xdp+0x40>
    116c:	48 89 0a             	mov    QWORD PTR [rdx],rcx
    116f:	b8 02 00 00 00       	mov    eax,0x2
    1174:	c3                   	ret

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
   c:	53                   	push   rbx
   d:	41 55                	push   r13
   f:	41 56                	push   r14
  11:	41 57                	push   r15
  13:	31 c0                	xor    eax,eax
  15:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  19:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  1d:	48 39 f7             	cmp    rdi,rsi
  20:	0f 87 c9 01 00 00    	ja     0x1ef
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 b9 01 00 00    	ja     0x1ef
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 10 08 00 00 	add    rdx,0x810
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 a6 01 00 00    	ja     0x1ef
  49:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4e:	48 c1 e6 08          	shl    rsi,0x8
  52:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  57:	48 09 d6             	or     rsi,rdx
  5a:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  5f:	48 c1 e2 10          	shl    rdx,0x10
  63:	48 09 d6             	or     rsi,rdx
  66:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  6b:	48 c1 e2 18          	shl    rdx,0x18
  6f:	48 09 d6             	or     rsi,rdx
  72:	48 c1 e6 20          	shl    rsi,0x20
  76:	48 c1 ee 20          	shr    rsi,0x20
  7a:	48 81 fe 00 01 00 00 	cmp    rsi,0x100
  81:	0f 85 68 01 00 00    	jne    0x1ef
  87:	48 0f b6 77 0d       	movzx  rsi,BYTE PTR [rdi+0xd]
  8c:	48 c1 e6 08          	shl    rsi,0x8
  90:	48 0f b6 57 0c       	movzx  rdx,BYTE PTR [rdi+0xc]
  95:	48 09 d6             	or     rsi,rdx
  98:	48 0f b6 57 0e       	movzx  rdx,BYTE PTR [rdi+0xe]
  9d:	48 c1 e2 10          	shl    rdx,0x10
  a1:	48 09 d6             	or     rsi,rdx
  a4:	48 0f b6 57 0f       	movzx  rdx,BYTE PTR [rdi+0xf]
  a9:	48 c1 e2 18          	shl    rdx,0x18
  ad:	48 09 d6             	or     rsi,rdx
  b0:	31 d2                	xor    edx,edx
  b2:	48 89 f9             	mov    rcx,rdi
  b5:	48 83 c1 17          	add    rcx,0x17
  b9:	48 b8 33 33 33 33 33 	movabs rax,0x3333333333333333
  c0:	33 33 33 
  c3:	49 bd 01 01 01 01 01 	movabs r13,0x101010101010101
  ca:	01 01 01 
  cd:	48 bb 55 55 55 55 55 	movabs rbx,0x5555555555555555
  d4:	55 55 55 
  d7:	4c 0f b6 71 fd       	movzx  r14,BYTE PTR [rcx-0x3]
  dc:	49 c1 e6 20          	shl    r14,0x20
  e0:	4c 0f b6 79 fb       	movzx  r15,BYTE PTR [rcx-0x5]
  e5:	49 c1 e7 10          	shl    r15,0x10
  e9:	4d 09 f7             	or     r15,r14
  ec:	4c 0f b6 41 fc       	movzx  r8,BYTE PTR [rcx-0x4]
  f1:	49 c1 e0 18          	shl    r8,0x18
  f5:	4c 0f b6 71 fa       	movzx  r14,BYTE PTR [rcx-0x6]
  fa:	49 c1 e6 08          	shl    r14,0x8
  fe:	4d 09 c6             	or     r14,r8
 101:	4d 09 fe             	or     r14,r15
 104:	4c 0f b6 41 fe       	movzx  r8,BYTE PTR [rcx-0x2]
 109:	49 c1 e0 28          	shl    r8,0x28
 10d:	4d 09 c6             	or     r14,r8
 110:	4c 0f b6 41 00       	movzx  r8,BYTE PTR [rcx+0x0]
 115:	49 c1 e0 38          	shl    r8,0x38
 119:	4c 0f b6 79 ff       	movzx  r15,BYTE PTR [rcx-0x1]
 11e:	49 c1 e7 30          	shl    r15,0x30
 122:	4d 09 c7             	or     r15,r8
 125:	4d 09 fe             	or     r14,r15
 128:	4c 0f b6 41 f9       	movzx  r8,BYTE PTR [rcx-0x7]
 12d:	4d 09 c6             	or     r14,r8
 130:	4d 89 f0             	mov    r8,r14
 133:	49 31 f0             	xor    r8,rsi
 136:	4d 89 c7             	mov    r15,r8
 139:	49 d1 ef             	shr    r15,1
 13c:	49 21 df             	and    r15,rbx
 13f:	4d 29 f8             	sub    r8,r15
 142:	4d 89 c7             	mov    r15,r8
 145:	49 21 c7             	and    r15,rax
 148:	49 c1 e8 02          	shr    r8,0x2
 14c:	49 21 c0             	and    r8,rax
 14f:	4d 01 c7             	add    r15,r8
 152:	49 89 d0             	mov    r8,rdx
 155:	49 83 e0 07          	and    r8,0x7
 159:	c4 42 bb f7 f6       	shrx   r14,r14,r8
 15e:	4d 89 f8             	mov    r8,r15
 161:	49 c1 e8 04          	shr    r8,0x4
 165:	4d 01 c7             	add    r15,r8
 168:	49 b8 0f 0f 0f 0f 0f 	movabs r8,0xf0f0f0f0f0f0f0f
 16f:	0f 0f 0f 
 172:	4d 21 c7             	and    r15,r8
 175:	4d 0f af fd          	imul   r15,r13
 179:	49 c1 ef 38          	shr    r15,0x38
 17d:	49 01 f7             	add    r15,rsi
 180:	4d 31 f7             	xor    r15,r14
 183:	48 83 c1 08          	add    rcx,0x8
 187:	48 83 c2 01          	add    rdx,0x1
 18b:	4c 89 fe             	mov    rsi,r15
 18e:	48 81 fa 00 01 00 00 	cmp    rdx,0x100
 195:	74 05                	je     0x19c
 197:	e9 3b ff ff ff       	jmp    0xd7
 19c:	4c 89 fe             	mov    rsi,r15
 19f:	48 c1 ee 38          	shr    rsi,0x38
 1a3:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 1a7:	4c 89 fe             	mov    rsi,r15
 1aa:	48 c1 ee 30          	shr    rsi,0x30
 1ae:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 1b2:	4c 89 fe             	mov    rsi,r15
 1b5:	48 c1 ee 28          	shr    rsi,0x28
 1b9:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 1bd:	4c 89 fe             	mov    rsi,r15
 1c0:	48 c1 ee 20          	shr    rsi,0x20
 1c4:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 1c8:	4c 89 fe             	mov    rsi,r15
 1cb:	48 c1 ee 18          	shr    rsi,0x18
 1cf:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 1d3:	4c 89 fe             	mov    rsi,r15
 1d6:	48 c1 ee 10          	shr    rsi,0x10
 1da:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 1de:	44 88 7f 00          	mov    BYTE PTR [rdi+0x0],r15b
 1e2:	49 c1 ef 08          	shr    r15,0x8
 1e6:	44 88 7f 01          	mov    BYTE PTR [rdi+0x1],r15b
 1ea:	b8 02 00 00 00       	mov    eax,0x2
 1ef:	41 5f                	pop    r15
 1f1:	41 5e                	pop    r14
 1f3:	41 5d                	pop    r13
 1f5:	5b                   	pop    rbx
 1f6:	c9                   	leave
 1f7:	c3                   	ret
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
   d:	77 67                	ja     0x76
   f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  13:	48 39 d6             	cmp    rsi,rdx
  16:	77 5e                	ja     0x76
  18:	48 8d b1 10 08 00 00 	lea    rsi,[rcx+0x810]
  1f:	48 39 d6             	cmp    rsi,rdx
  22:	77 52                	ja     0x76
  24:	81 79 08 00 01 00 00 	cmp    DWORD PTR [rcx+0x8],0x100
  2b:	75 4a                	jne    0x77
  2d:	8b 41 0c             	mov    eax,DWORD PTR [rcx+0xc]
  30:	48 8d 51 17          	lea    rdx,[rcx+0x17]
  34:	31 f6                	xor    esi,esi
  36:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  3d:	00 00 00 
  40:	48 8b 7a f9          	mov    rdi,QWORD PTR [rdx-0x7]
  44:	41 89 f0             	mov    r8d,esi
  47:	41 80 e0 07          	and    r8b,0x7
  4b:	c4 62 bb f7 c7       	shrx   r8,rdi,r8
  50:	48 31 c7             	xor    rdi,rax
  53:	f3 48 0f b8 ff       	popcnt rdi,rdi
  58:	48 01 f8             	add    rax,rdi
  5b:	4c 31 c0             	xor    rax,r8
  5e:	48 83 c2 08          	add    rdx,0x8
  62:	48 ff c6             	inc    rsi
  65:	48 81 fe 00 01 00 00 	cmp    rsi,0x100
  6c:	75 d2                	jne    0x40
  6e:	48 89 01             	mov    QWORD PTR [rcx],rax
  71:	b8 02 00 00 00       	mov    eax,0x2
  76:	c3                   	ret
  77:	31 c0                	xor    eax,eax
  79:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 3
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rsi],0x100 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rsi],0x100]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <bitmap_popcount_scan_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <bitmap_popcount_scan_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <bitmap_popcount_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <bitmap_popcount_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rdi,[rdx+0x810] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 2064), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <bitmap_popcount_scan_xdp+0xe> [bpf-branch: lowered cmp    rdi,rcx + ja     110e <bitmap_popcount_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rsi],0x100 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rsi],0x100] */
    /* 0x112a: jne    110e <bitmap_popcount_scan_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi],0x100 + jne    110e <bitmap_popcount_scan_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 256),
    /* 0x112c: mov    ecx,DWORD PTR [rdx+0xc] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 12), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x112f: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1131: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: mov    rsi,QWORD PTR [rdx+rax*8+0x10] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_SIB_PAYLOAD(BPF_REG_2, BPF_REG_3, BPF_REG_0, 3, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ_SIB),
    /* 0x1145: mov    rdi,rsi [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1148: xor    rdi,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x114b: popcnt rdi,rdi [exact-kop: popcntq kop; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KOP(HC_POPCNT_PAYLOAD(BPF_REG_1, BPF_REG_1, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPCNTQ),
    /* 0x1150: add    rdi,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x1153: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1155: and    cl,0x7 [exact-kop: andb imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_4, 7, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1158: shr    rsi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x115b: mov    rcx,rsi [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x115e: xor    rcx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_1, 0, 0),
    /* 0x1161: inc    rax [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1164: cmp    rax,0x100 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 256), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x116a: jne    1140 <bitmap_popcount_scan_xdp+0x40> [bpf-branch: lowered cmp    rax,0x100 + jne    1140 <bitmap_popcount_scan_xdp+0x40> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, -20, 256),
    /* 0x116c: mov    QWORD PTR [rdx],rcx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x116f: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1174: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
