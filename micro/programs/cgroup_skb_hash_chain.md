# cgroup_skb_hash_chain

## Original C
```c
#include "common.h"

#define HASH_CHAIN_ROUNDS 16U
#define HASH_CHAIN_WORDS 8U
#define HASH_CHAIN_INPUT_SIZE (8U + HASH_CHAIN_WORDS * 8U)

static __always_inline int bench_hash_chain(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);

    if (rounds != HASH_CHAIN_ROUNDS || word_count != HASH_CHAIN_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, HASH_CHAIN_WORDS * 8U)) {
        return -1;
    }

    u64 acc = 0xCBF29CE484222325ULL;
    for (u32 round = 0; round < HASH_CHAIN_ROUNDS; round++) {
        for (u32 i = 0; i < HASH_CHAIN_WORDS; i++) {
            u64 word = micro_read_u64_le(data, 8 + i * 8U);
            u64 salt = ((u64)(round + 1U) * 0x9E3779B97F4A7C15ULL) ^
                       ((u64)(i + 1U) * 0xD1342543DE82EF95ULL);

            acc ^= word + salt;
            acc = micro_rotl64(acc, (round * 5U + i * 11U + 7U) & 63U);
            acc *= 0x100000001B3ULL;
            acc ^= acc >> 29U;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_CGROUP_SKB_BENCH(
    cgroup_skb_hash_chain_prog,
    bench_hash_chain,
    cgroup_skb_hash_chain_input_value,
    HASH_CHAIN_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <cgroup_skb_hash_chain_prog>:
    1100:	48 8b 07             	mov    rax,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	48 39 c8             	cmp    rax,rcx
    110a:	76 12                	jbe    111e <cgroup_skb_hash_chain_prog+0x1e>
    110c:	c7 47 10 ff ff ff ff 	mov    DWORD PTR [rdi+0x10],0xffffffff
    1113:	31 c0                	xor    eax,eax
    1115:	ba ff ff ff ff       	mov    edx,0xffffffff
    111a:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    111d:	c3                   	ret
    111e:	48 8d 50 08          	lea    rdx,[rax+0x8]
    1122:	48 39 ca             	cmp    rdx,rcx
    1125:	77 e5                	ja     110c <cgroup_skb_hash_chain_prog+0xc>
    1127:	48 8d 50 50          	lea    rdx,[rax+0x50]
    112b:	48 39 ca             	cmp    rdx,rcx
    112e:	77 dc                	ja     110c <cgroup_skb_hash_chain_prog+0xc>
    1130:	83 78 08 10          	cmp    DWORD PTR [rax+0x8],0x10
    1134:	75 d6                	jne    110c <cgroup_skb_hash_chain_prog+0xc>
    1136:	83 78 0c 08          	cmp    DWORD PTR [rax+0xc],0x8
    113a:	75 d0                	jne    110c <cgroup_skb_hash_chain_prog+0xc>
    113c:	41 57                	push   r15
    113e:	41 56                	push   r14
    1140:	41 54                	push   r12
    1142:	53                   	push   rbx
    1143:	48 ba 25 23 22 84 e4 	movabs rdx,0xcbf29ce484222325
    114a:	9c f2 cb 
    114d:	be 07 00 00 00       	mov    esi,0x7
    1152:	49 b8 95 ef 82 de 43 	movabs r8,0xd1342543de82ef95
    1159:	25 34 d1 
    115c:	45 31 c9             	xor    r9d,r9d
    115f:	49 ba 15 7c 4a 7f b9 	movabs r10,0x9e3779b97f4a7c15
    1166:	79 37 9e 
    1169:	49 bb b3 01 00 00 00 	movabs r11,0x100000001b3
    1170:	01 00 00 
    1173:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    117a:	84 00 00 00 00 00 
    1180:	49 ff c1             	inc    r9
    1183:	4c 89 cb             	mov    rbx,r9
    1186:	49 0f af da          	imul   rbx,r10
    118a:	4d 89 c6             	mov    r14,r8
    118d:	48 89 f1             	mov    rcx,rsi
    1190:	45 31 ff             	xor    r15d,r15d
    1193:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    119a:	84 00 00 00 00 00 
    11a0:	4d 89 f4             	mov    r12,r14
    11a3:	49 31 dc             	xor    r12,rbx
    11a6:	4e 03 64 f8 10       	add    r12,QWORD PTR [rax+r15*8+0x10]
    11ab:	49 31 d4             	xor    r12,rdx
    11ae:	49 d3 c4             	rol    r12,cl
    11b1:	49 ff c7             	inc    r15
    11b4:	4d 0f af e3          	imul   r12,r11
    11b8:	4c 89 e2             	mov    rdx,r12
    11bb:	48 c1 ea 1d          	shr    rdx,0x1d
    11bf:	4c 31 e2             	xor    rdx,r12
    11c2:	48 83 c1 0b          	add    rcx,0xb
    11c6:	4d 01 c6             	add    r14,r8
    11c9:	49 83 ff 08          	cmp    r15,0x8
    11cd:	75 d1                	jne    11a0 <cgroup_skb_hash_chain_prog+0xa0>
    11cf:	48 83 c6 05          	add    rsi,0x5
    11d3:	49 83 f9 10          	cmp    r9,0x10
    11d7:	75 a7                	jne    1180 <cgroup_skb_hash_chain_prog+0x80>
    11d9:	89 57 10             	mov    DWORD PTR [rdi+0x10],edx
    11dc:	48 c1 ea 20          	shr    rdx,0x20
    11e0:	b8 01 00 00 00       	mov    eax,0x1
    11e5:	5b                   	pop    rbx
    11e6:	41 5c                	pop    r12
    11e8:	41 5e                	pop    r14
    11ea:	41 5f                	pop    r15
    11ec:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    11ef:	c3                   	ret

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
   c:	48 81 ec 18 00 00 00 	sub    rsp,0x18
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	48 8b 57 50          	mov    rdx,QWORD PTR [rdi+0x50]
  1e:	48 8b 8f d0 00 00 00 	mov    rcx,QWORD PTR [rdi+0xd0]
  25:	48 39 d1             	cmp    rcx,rdx
  28:	77 18                	ja     0x42
  2a:	48 89 ce             	mov    rsi,rcx
  2d:	48 83 c6 08          	add    rsi,0x8
  31:	48 39 d6             	cmp    rsi,rdx
  34:	77 0c                	ja     0x42
  36:	48 89 ce             	mov    rsi,rcx
  39:	48 83 c6 50          	add    rsi,0x50
  3d:	48 39 f2             	cmp    rdx,rsi
  40:	73 16                	jae    0x58
  42:	bb ff ff ff ff       	mov    ebx,0xffffffff
  47:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
  4a:	31 c0                	xor    eax,eax
  4c:	89 5f 34             	mov    DWORD PTR [rdi+0x34],ebx
  4f:	41 5f                	pop    r15
  51:	41 5e                	pop    r14
  53:	41 5d                	pop    r13
  55:	5b                   	pop    rbx
  56:	c9                   	leave
  57:	c3                   	ret
  58:	48 0f b6 51 09       	movzx  rdx,BYTE PTR [rcx+0x9]
  5d:	48 c1 e2 08          	shl    rdx,0x8
  61:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  66:	48 09 f2             	or     rdx,rsi
  69:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  6e:	48 c1 e6 10          	shl    rsi,0x10
  72:	48 09 f2             	or     rdx,rsi
  75:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  7a:	48 c1 e6 18          	shl    rsi,0x18
  7e:	48 09 f2             	or     rdx,rsi
  81:	48 c1 e2 20          	shl    rdx,0x20
  85:	48 c1 ea 20          	shr    rdx,0x20
  89:	48 83 fa 10          	cmp    rdx,0x10
  8d:	75 b3                	jne    0x42
  8f:	48 0f b6 51 0d       	movzx  rdx,BYTE PTR [rcx+0xd]
  94:	48 c1 e2 08          	shl    rdx,0x8
  98:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
  9d:	48 09 f2             	or     rdx,rsi
  a0:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
  a5:	48 c1 e6 10          	shl    rsi,0x10
  a9:	48 09 f2             	or     rdx,rsi
  ac:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
  b1:	48 c1 e6 18          	shl    rsi,0x18
  b5:	48 09 f2             	or     rdx,rsi
  b8:	48 c1 e2 20          	shl    rdx,0x20
  bc:	48 c1 ea 20          	shr    rdx,0x20
  c0:	48 83 fa 08          	cmp    rdx,0x8
  c4:	0f 85 78 ff ff ff    	jne    0x42
  ca:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  ce:	48 bb 25 23 22 84 e4 	movabs rbx,0xcbf29ce484222325
  d5:	9c f2 cb 
  d8:	45 31 ed             	xor    r13d,r13d
  db:	48 83 c1 17          	add    rcx,0x17
  df:	45 31 ff             	xor    r15d,r15d
  e2:	48 89 4d f0          	mov    QWORD PTR [rbp-0x10],rcx
  e6:	eb 16                	jmp    0xfe
  e8:	49 83 c5 05          	add    r13,0x5
  ec:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  f0:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
  f4:	49 83 ff 10          	cmp    r15,0x10
  f8:	0f 84 f1 00 00 00    	je     0x1ef
  fe:	41 be 07 00 00 00    	mov    r14d,0x7
 104:	49 83 c7 01          	add    r15,0x1
 108:	4c 89 7d f8          	mov    QWORD PTR [rbp-0x8],r15
 10c:	48 bf 15 7c 4a 7f b9 	movabs rdi,0x9e3779b97f4a7c15
 113:	79 37 9e 
 116:	4c 0f af ff          	imul   r15,rdi
 11a:	48 89 ce             	mov    rsi,rcx
 11d:	49 b8 95 ef 82 de 43 	movabs r8,0xd1342543de82ef95
 124:	25 34 d1 
 127:	eb 33                	jmp    0x15c
 129:	48 bf b3 01 00 00 00 	movabs rdi,0x100000001b3
 130:	01 00 00 
 133:	48 0f af d7          	imul   rdx,rdi
 137:	48 89 d3             	mov    rbx,rdx
 13a:	48 c1 eb 1d          	shr    rbx,0x1d
 13e:	48 31 d3             	xor    rbx,rdx
 141:	48 bf 95 ef 82 de 43 	movabs rdi,0xd1342543de82ef95
 148:	25 34 d1 
 14b:	49 01 f8             	add    r8,rdi
 14e:	48 83 c6 08          	add    rsi,0x8
 152:	49 83 c6 0b          	add    r14,0xb
 156:	49 83 fe 5f          	cmp    r14,0x5f
 15a:	74 8c                	je     0xe8
 15c:	48 0f b6 56 fd       	movzx  rdx,BYTE PTR [rsi-0x3]
 161:	48 c1 e2 20          	shl    rdx,0x20
 165:	48 0f b6 4e fb       	movzx  rcx,BYTE PTR [rsi-0x5]
 16a:	48 c1 e1 10          	shl    rcx,0x10
 16e:	48 09 d1             	or     rcx,rdx
 171:	48 0f b6 46 fc       	movzx  rax,BYTE PTR [rsi-0x4]
 176:	48 c1 e0 18          	shl    rax,0x18
 17a:	48 0f b6 56 fa       	movzx  rdx,BYTE PTR [rsi-0x6]
 17f:	48 c1 e2 08          	shl    rdx,0x8
 183:	48 09 c2             	or     rdx,rax
 186:	48 09 ca             	or     rdx,rcx
 189:	48 0f b6 4e fe       	movzx  rcx,BYTE PTR [rsi-0x2]
 18e:	48 c1 e1 28          	shl    rcx,0x28
 192:	48 09 ca             	or     rdx,rcx
 195:	48 0f b6 4e 00       	movzx  rcx,BYTE PTR [rsi+0x0]
 19a:	48 c1 e1 38          	shl    rcx,0x38
 19e:	48 0f b6 46 ff       	movzx  rax,BYTE PTR [rsi-0x1]
 1a3:	48 c1 e0 30          	shl    rax,0x30
 1a7:	48 09 c8             	or     rax,rcx
 1aa:	48 09 c2             	or     rdx,rax
 1ad:	48 0f b6 4e f9       	movzx  rcx,BYTE PTR [rsi-0x7]
 1b2:	48 09 ca             	or     rdx,rcx
 1b5:	4c 89 e9             	mov    rcx,r13
 1b8:	4c 01 f1             	add    rcx,r14
 1bb:	4c 89 c0             	mov    rax,r8
 1be:	4c 31 f8             	xor    rax,r15
 1c1:	48 01 c2             	add    rdx,rax
 1c4:	48 31 da             	xor    rdx,rbx
 1c7:	48 83 e1 3f          	and    rcx,0x3f
 1cb:	48 85 c9             	test   rcx,rcx
 1ce:	0f 84 55 ff ff ff    	je     0x129
 1d4:	bf 40 00 00 00       	mov    edi,0x40
 1d9:	48 29 cf             	sub    rdi,rcx
 1dc:	48 89 d0             	mov    rax,rdx
 1df:	c4 e2 c3 f7 c0       	shrx   rax,rax,rdi
 1e4:	48 d3 e2             	shl    rdx,cl
 1e7:	48 09 c2             	or     rdx,rax
 1ea:	e9 3a ff ff ff       	jmp    0x129
 1ef:	48 8b 7d e8          	mov    rdi,QWORD PTR [rbp-0x18]
 1f3:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
 1f6:	b8 01 00 00 00       	mov    eax,0x1
 1fb:	48 c1 eb 20          	shr    rbx,0x20
 1ff:	e9 48 fe ff ff       	jmp    0x4c
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 47 4c             	mov    eax,DWORD PTR [rdi+0x4c]
   7:	8b 4f 50             	mov    ecx,DWORD PTR [rdi+0x50]
   a:	39 c8                	cmp    eax,ecx
   c:	0f 87 ef 00 00 00    	ja     0x101
  12:	48 8d 50 08          	lea    rdx,[rax+0x8]
  16:	48 39 ca             	cmp    rdx,rcx
  19:	0f 87 e2 00 00 00    	ja     0x101
  1f:	48 8d 50 50          	lea    rdx,[rax+0x50]
  23:	48 39 ca             	cmp    rdx,rcx
  26:	0f 87 d5 00 00 00    	ja     0x101
  2c:	83 78 08 10          	cmp    DWORD PTR [rax+0x8],0x10
  30:	0f 85 cb 00 00 00    	jne    0x101
  36:	83 78 0c 08          	cmp    DWORD PTR [rax+0xc],0x8
  3a:	0f 85 c1 00 00 00    	jne    0x101
  40:	55                   	push   rbp
  41:	41 57                	push   r15
  43:	41 56                	push   r14
  45:	41 55                	push   r13
  47:	41 54                	push   r12
  49:	53                   	push   rbx
  4a:	48 be 95 ef 82 de 43 	movabs rsi,0xd1342543de82ef95
  51:	25 34 d1 
  54:	48 83 c0 17          	add    rax,0x17
  58:	48 ba 25 23 22 84 e4 	movabs rdx,0xcbf29ce484222325
  5f:	9c f2 cb 
  62:	45 31 c0             	xor    r8d,r8d
  65:	49 b9 15 7c 4a 7f b9 	movabs r9,0x9e3779b97f4a7c15
  6c:	79 37 9e 
  6f:	49 ba b3 01 00 00 00 	movabs r10,0x100000001b3
  76:	01 00 00 
  79:	45 31 db             	xor    r11d,r11d
  7c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  80:	49 ff c3             	inc    r11
  83:	4c 89 db             	mov    rbx,r11
  86:	49 0f af d9          	imul   rbx,r9
  8a:	41 be 07 00 00 00    	mov    r14d,0x7
  90:	49 89 c7             	mov    r15,rax
  93:	49 89 f4             	mov    r12,rsi
  96:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  9d:	00 00 00 
  a0:	4b 8d 0c 30          	lea    rcx,[r8+r14*1]
  a4:	4d 89 e5             	mov    r13,r12
  a7:	49 31 dd             	xor    r13,rbx
  aa:	4d 03 6f f9          	add    r13,QWORD PTR [r15-0x7]
  ae:	49 31 d5             	xor    r13,rdx
  b1:	4c 89 ed             	mov    rbp,r13
  b4:	48 d3 c5             	rol    rbp,cl
  b7:	f6 c1 3f             	test   cl,0x3f
  ba:	49 0f 44 ed          	cmove  rbp,r13
  be:	49 0f af ea          	imul   rbp,r10
  c2:	48 89 ea             	mov    rdx,rbp
  c5:	48 c1 ea 1d          	shr    rdx,0x1d
  c9:	48 31 ea             	xor    rdx,rbp
  cc:	49 01 f4             	add    r12,rsi
  cf:	49 83 c7 08          	add    r15,0x8
  d3:	49 83 c6 0b          	add    r14,0xb
  d7:	49 83 fe 5f          	cmp    r14,0x5f
  db:	75 c3                	jne    0xa0
  dd:	49 83 c0 05          	add    r8,0x5
  e1:	49 83 fb 10          	cmp    r11,0x10
  e5:	75 99                	jne    0x80
  e7:	89 57 30             	mov    DWORD PTR [rdi+0x30],edx
  ea:	48 c1 ea 20          	shr    rdx,0x20
  ee:	b8 01 00 00 00       	mov    eax,0x1
  f3:	5b                   	pop    rbx
  f4:	41 5c                	pop    r12
  f6:	41 5d                	pop    r13
  f8:	41 5e                	pop    r14
  fa:	41 5f                	pop    r15
  fc:	5d                   	pop    rbp
  fd:	89 57 34             	mov    DWORD PTR [rdi+0x34],edx
 100:	c3                   	ret
 101:	c7 47 30 ff ff ff ff 	mov    DWORD PTR [rdi+0x30],0xffffffff
 108:	ba ff ff ff ff       	mov    edx,0xffffffff
 10d:	31 c0                	xor    eax,eax
 10f:	89 57 34             	mov    DWORD PTR [rdi+0x34],edx
 112:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
