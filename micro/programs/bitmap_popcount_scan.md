# bitmap_popcount_scan

## Original C
```c
#include "common.h"

#define BITCOUNT_MAX_COUNT 256U
#define BITCOUNT_INPUT_SIZE (8U + BITCOUNT_MAX_COUNT * 8U)

static __always_inline u64 micro_popcount64(u64 value)
{
    u64 count = 0;
    for (u32 bit = 0; bit < 64 && value != 0; bit++) {
        value &= value - 1;
        count++;
    }
    return count;
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
```

## Native ASM
```asm

/artifacts/user/micro-programs/x86_64/bitmap_popcount_scan.native.so:     file format elf64-x86-64


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
    1131:	eb 29                	jmp    115c <bitmap_popcount_scan_xdp+0x5c>
    1133:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    113a:	84 00 00 00 00 00 
    1140:	48 01 cf             	add    rdi,rcx
    1143:	89 c1                	mov    ecx,eax
    1145:	80 e1 07             	and    cl,0x7
    1148:	48 d3 ee             	shr    rsi,cl
    114b:	48 89 f1             	mov    rcx,rsi
    114e:	48 31 f9             	xor    rcx,rdi
    1151:	48 ff c0             	inc    rax
    1154:	48 3d 00 01 00 00    	cmp    rax,0x100
    115a:	74 2b                	je     1187 <bitmap_popcount_scan_xdp+0x87>
    115c:	48 8b 74 c2 10       	mov    rsi,QWORD PTR [rdx+rax*8+0x10]
    1161:	49 89 f0             	mov    r8,rsi
    1164:	31 ff                	xor    edi,edi
    1166:	49 31 c8             	xor    r8,rcx
    1169:	74 d5                	je     1140 <bitmap_popcount_scan_xdp+0x40>
    116b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1170:	49 89 f9             	mov    r9,rdi
    1173:	48 ff c7             	inc    rdi
    1176:	41 83 f9 3e          	cmp    r9d,0x3e
    117a:	77 c4                	ja     1140 <bitmap_popcount_scan_xdp+0x40>
    117c:	4d 8d 48 ff          	lea    r9,[r8-0x1]
    1180:	4d 21 c8             	and    r8,r9
    1183:	75 eb                	jne    1170 <bitmap_popcount_scan_xdp+0x70>
    1185:	eb b9                	jmp    1140 <bitmap_popcount_scan_xdp+0x40>
    1187:	48 89 0a             	mov    QWORD PTR [rdx],rcx
    118a:	b8 02 00 00 00       	mov    eax,0x2
    118f:	c3                   	ret

Disassembly of section .fini:
```

## Original Kernel JIT ASM
```asm

/home/yunwei37/workspace/bpf-benchmark/micro/results/x86_kvm_micro_20260515_033620_169457/details/jit_dumps/bitmap_popcount_scan__kernel__sample00.jited.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 18 00 00 00 	sub    rsp,0x18
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 fb 01 00 00    	ja     0x228
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 eb 01 00 00    	ja     0x228
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 08 00 00 	add    rdi,0x810
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 d8 01 00 00    	ja     0x228
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 81 ff 00 01 00 00 	cmp    rdi,0x100
  88:	0f 85 9a 01 00 00    	jne    0x228
  8e:	4c 0f b6 72 0d       	movzx  r14,BYTE PTR [rdx+0xd]
  93:	49 c1 e6 08          	shl    r14,0x8
  97:	48 0f b6 7a 0c       	movzx  rdi,BYTE PTR [rdx+0xc]
  9c:	49 09 fe             	or     r14,rdi
  9f:	48 0f b6 7a 0e       	movzx  rdi,BYTE PTR [rdx+0xe]
  a4:	48 c1 e7 10          	shl    rdi,0x10
  a8:	49 09 fe             	or     r14,rdi
  ab:	48 0f b6 7a 0f       	movzx  rdi,BYTE PTR [rdx+0xf]
  b0:	48 c1 e7 18          	shl    rdi,0x18
  b4:	49 09 fe             	or     r14,rdi
  b7:	31 f6                	xor    esi,esi
  b9:	48 89 d7             	mov    rdi,rdx
  bc:	48 83 c7 17          	add    rdi,0x17
  c0:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  c4:	48 89 d7             	mov    rdi,rdx
  c7:	48 83 c7 16          	add    rdi,0x16
  cb:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  cf:	49 89 d0             	mov    r8,rdx
  d2:	49 83 c0 15          	add    r8,0x15
  d6:	48 89 d0             	mov    rax,rdx
  d9:	48 83 c0 11          	add    rax,0x11
  dd:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
  e1:	48 89 d3             	mov    rbx,rdx
  e4:	48 83 c3 10          	add    rbx,0x10
  e8:	eb 4a                	jmp    0x134
  ea:	49 83 c6 01          	add    r14,0x1
  ee:	49 c1 e5 20          	shl    r13,0x20
  f2:	49 c1 ed 20          	shr    r13,0x20
  f6:	49 83 fd 3e          	cmp    r13,0x3e
  fa:	77 15                	ja     0x111
  fc:	49 89 ff             	mov    r15,rdi
  ff:	49 83 c7 ff          	add    r15,0xffffffffffffffff
 103:	49 21 ff             	and    r15,rdi
 106:	4d 89 f5             	mov    r13,r14
 109:	4c 89 ff             	mov    rdi,r15
 10c:	4d 85 ff             	test   r15,r15
 10f:	75 d9                	jne    0xea
 111:	49 01 d6             	add    r14,rdx
 114:	48 89 f7             	mov    rdi,rsi
 117:	48 83 e7 07          	and    rdi,0x7
 11b:	c4 e2 c3 f7 c9       	shrx   rcx,rcx,rdi
 120:	49 31 ce             	xor    r14,rcx
 123:	48 83 c6 01          	add    rsi,0x1
 127:	48 81 fe 00 01 00 00 	cmp    rsi,0x100
 12e:	0f 84 9d 00 00 00    	je     0x1d1
 134:	4c 89 f2             	mov    rdx,r14
 137:	49 89 f5             	mov    r13,rsi
 13a:	49 c1 e5 03          	shl    r13,0x3
 13e:	48 89 c7             	mov    rdi,rax
 141:	4c 01 ef             	add    rdi,r13
 144:	4c 0f b6 77 03       	movzx  r14,BYTE PTR [rdi+0x3]
 149:	49 c1 e6 20          	shl    r14,0x20
 14d:	4c 0f b6 7f 01       	movzx  r15,BYTE PTR [rdi+0x1]
 152:	49 c1 e7 10          	shl    r15,0x10
 156:	4d 09 f7             	or     r15,r14
 159:	4c 0f b6 77 02       	movzx  r14,BYTE PTR [rdi+0x2]
 15e:	49 c1 e6 18          	shl    r14,0x18
 162:	48 0f b6 4f 00       	movzx  rcx,BYTE PTR [rdi+0x0]
 167:	48 c1 e1 08          	shl    rcx,0x8
 16b:	4c 09 f1             	or     rcx,r14
 16e:	4c 09 f9             	or     rcx,r15
 171:	4d 89 c6             	mov    r14,r8
 174:	4d 01 ee             	add    r14,r13
 177:	4d 0f b6 76 00       	movzx  r14,BYTE PTR [r14+0x0]
 17c:	49 c1 e6 28          	shl    r14,0x28
 180:	4c 09 f1             	or     rcx,r14
 183:	4c 8b 75 f8          	mov    r14,QWORD PTR [rbp-0x8]
 187:	4d 01 ee             	add    r14,r13
 18a:	4d 0f b6 76 00       	movzx  r14,BYTE PTR [r14+0x0]
 18f:	49 c1 e6 38          	shl    r14,0x38
 193:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 197:	4d 01 ef             	add    r15,r13
 19a:	4d 0f b6 7f 00       	movzx  r15,BYTE PTR [r15+0x0]
 19f:	49 c1 e7 30          	shl    r15,0x30
 1a3:	4d 09 f7             	or     r15,r14
 1a6:	4c 09 f9             	or     rcx,r15
 1a9:	49 89 de             	mov    r14,rbx
 1ac:	4d 01 ee             	add    r14,r13
 1af:	4d 0f b6 6e 00       	movzx  r13,BYTE PTR [r14+0x0]
 1b4:	4c 09 e9             	or     rcx,r13
 1b7:	48 89 cf             	mov    rdi,rcx
 1ba:	48 31 d7             	xor    rdi,rdx
 1bd:	45 31 f6             	xor    r14d,r14d
 1c0:	48 85 ff             	test   rdi,rdi
 1c3:	0f 84 48 ff ff ff    	je     0x111
 1c9:	45 31 ed             	xor    r13d,r13d
 1cc:	e9 19 ff ff ff       	jmp    0xea
 1d1:	4c 89 f7             	mov    rdi,r14
 1d4:	48 c1 ef 38          	shr    rdi,0x38
 1d8:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 1dc:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 1e0:	4c 89 f7             	mov    rdi,r14
 1e3:	48 c1 ef 30          	shr    rdi,0x30
 1e7:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 1eb:	4c 89 f7             	mov    rdi,r14
 1ee:	48 c1 ef 28          	shr    rdi,0x28
 1f2:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 1f6:	4c 89 f7             	mov    rdi,r14
 1f9:	48 c1 ef 20          	shr    rdi,0x20
 1fd:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 201:	4c 89 f7             	mov    rdi,r14
 204:	48 c1 ef 18          	shr    rdi,0x18
 208:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 20c:	4c 89 f7             	mov    rdi,r14
 20f:	48 c1 ef 10          	shr    rdi,0x10
 213:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 217:	44 88 76 00          	mov    BYTE PTR [rsi+0x0],r14b
 21b:	49 c1 ee 08          	shr    r14,0x8
 21f:	44 88 76 01          	mov    BYTE PTR [rsi+0x1],r14b
 223:	b8 02 00 00 00       	mov    eax,0x2
 228:	41 5f                	pop    r15
 22a:	41 5e                	pop    r14
 22c:	41 5d                	pop    r13
 22e:	5b                   	pop    rbx
 22f:	c9                   	leave
 230:	c3                   	ret
```

## llvmbpf JIT ASM
```asm

/home/yunwei37/workspace/bpf-benchmark/micro/results/x86_kvm_micro_20260515_033620_169457/details/jit_dumps/bitmap_popcount_scan__llvmbpf__sample00.jited.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   6:	8b 57 04             	mov    edx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 d1                	cmp    ecx,edx
   d:	77 7e                	ja     0x8d
   f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  13:	48 39 d6             	cmp    rsi,rdx
  16:	77 75                	ja     0x8d
  18:	48 8d b1 10 08 00 00 	lea    rsi,[rcx+0x810]
  1f:	48 39 d6             	cmp    rsi,rdx
  22:	77 69                	ja     0x8d
  24:	81 79 08 00 01 00 00 	cmp    DWORD PTR [rcx+0x8],0x100
  2b:	75 55                	jne    0x82
  2d:	8b 51 0c             	mov    edx,DWORD PTR [rcx+0xc]
  30:	31 c0                	xor    eax,eax
  32:	eb 2c                	jmp    0x60
  34:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  3b:	00 00 00 00 00 
  40:	bf 40 00 00 00       	mov    edi,0x40
  45:	48 01 d7             	add    rdi,rdx
  48:	89 c2                	mov    edx,eax
  4a:	80 e2 07             	and    dl,0x7
  4d:	c4 e2 eb f7 d6       	shrx   rdx,rsi,rdx
  52:	48 31 fa             	xor    rdx,rdi
  55:	48 ff c0             	inc    rax
  58:	48 3d 00 01 00 00    	cmp    rax,0x100
  5e:	74 25                	je     0x85
  60:	48 8b 74 c1 10       	mov    rsi,QWORD PTR [rcx+rax*8+0x10]
  65:	49 89 f0             	mov    r8,rsi
  68:	31 ff                	xor    edi,edi
  6a:	49 31 d0             	xor    r8,rdx
  6d:	74 d6                	je     0x45
  6f:	90                   	nop
  70:	48 83 ff 3e          	cmp    rdi,0x3e
  74:	77 ca                	ja     0x40
  76:	48 ff c7             	inc    rdi
  79:	c4 c2 b8 f3 c8       	blsr   r8,r8
  7e:	75 f0                	jne    0x70
  80:	eb c3                	jmp    0x45
  82:	31 c0                	xor    eax,eax
  84:	c3                   	ret
  85:	48 89 11             	mov    QWORD PTR [rcx],rdx
  88:	b8 02 00 00 00       	mov    eax,0x2
  8d:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
