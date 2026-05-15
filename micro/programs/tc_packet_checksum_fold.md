# tc_packet_checksum_fold

## Original C
```c
#include "common.h"

#define TC_CHECKSUM_MAX_ROUNDS 32U
#define TC_CHECKSUM_MAX_WORDS 512U
#define TC_CHECKSUM_INPUT_SIZE (8U + TC_CHECKSUM_MAX_WORDS * 2U)

static __always_inline int bench_checksum(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);
    u64 acc = 0;

    if (rounds != TC_CHECKSUM_MAX_ROUNDS || word_count != TC_CHECKSUM_MAX_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, TC_CHECKSUM_MAX_WORDS * 2U)) {
        return -1;
    }

    for (u32 round = 0; round < TC_CHECKSUM_MAX_ROUNDS; round++) {
        u32 sum = 0;
        for (u32 i = 0; i < TC_CHECKSUM_MAX_WORDS; i++) {
            sum += micro_read_u16_le(data, 8 + i * 2U);
            sum = (sum & 0xFFFFU) + (sum >> 16);
        }
        sum = (sum & 0xFFFFU) + (sum >> 16);
        /*
         * The same checksum value is folded into four 16-bit lanes. With 32
         * rounds each lane toggles eight times, so the final accumulator is
         * intentionally zero even though the staged input is non-zero.
         */
        acc ^= (u64)(~sum & 0xFFFFU) << ((round & 3U) * 16U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_TC_BENCH(
    tc_packet_checksum_fold_prog,
    bench_checksum,
    tc_packet_checksum_fold_input_value,
    TC_CHECKSUM_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <tc_packet_checksum_fold_prog>:
    1100:	48 8b 07             	mov    rax,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	48 39 c8             	cmp    rax,rcx
    110a:	76 15                	jbe    1121 <tc_packet_checksum_fold_prog+0x21>
    110c:	c7 47 10 ff ff ff ff 	mov    DWORD PTR [rdi+0x10],0xffffffff
    1113:	b8 02 00 00 00       	mov    eax,0x2
    1118:	ba ff ff ff ff       	mov    edx,0xffffffff
    111d:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    1120:	c3                   	ret
    1121:	48 8d 50 08          	lea    rdx,[rax+0x8]
    1125:	48 39 ca             	cmp    rdx,rcx
    1128:	77 e2                	ja     110c <tc_packet_checksum_fold_prog+0xc>
    112a:	48 8d 90 10 04 00 00 	lea    rdx,[rax+0x410]
    1131:	48 39 ca             	cmp    rdx,rcx
    1134:	77 d6                	ja     110c <tc_packet_checksum_fold_prog+0xc>
    1136:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
    113a:	75 d0                	jne    110c <tc_packet_checksum_fold_prog+0xc>
    113c:	81 78 0c 00 02 00 00 	cmp    DWORD PTR [rax+0xc],0x200
    1143:	75 c7                	jne    110c <tc_packet_checksum_fold_prog+0xc>
    1145:	31 f6                	xor    esi,esi
    1147:	31 d2                	xor    edx,edx
    1149:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1150:	31 c9                	xor    ecx,ecx
    1152:	45 31 c0             	xor    r8d,r8d
    1155:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    115c:	00 00 00 00 
    1160:	44 0f b7 4c 48 10    	movzx  r9d,WORD PTR [rax+rcx*2+0x10]
    1166:	45 01 c1             	add    r9d,r8d
    1169:	45 0f b7 c1          	movzx  r8d,r9w
    116d:	41 c1 e9 10          	shr    r9d,0x10
    1171:	45 01 c1             	add    r9d,r8d
    1174:	44 0f b7 44 48 12    	movzx  r8d,WORD PTR [rax+rcx*2+0x12]
    117a:	45 01 c8             	add    r8d,r9d
    117d:	45 0f b7 c8          	movzx  r9d,r8w
    1181:	41 c1 e8 10          	shr    r8d,0x10
    1185:	45 01 c8             	add    r8d,r9d
    1188:	48 83 c1 02          	add    rcx,0x2
    118c:	48 81 f9 00 02 00 00 	cmp    rcx,0x200
    1193:	75 cb                	jne    1160 <tc_packet_checksum_fold_prog+0x60>
    1195:	44 89 c1             	mov    ecx,r8d
    1198:	c1 e9 10             	shr    ecx,0x10
    119b:	44 01 c1             	add    ecx,r8d
    119e:	f7 d1                	not    ecx
    11a0:	44 0f b7 c1          	movzx  r8d,cx
    11a4:	89 f1                	mov    ecx,esi
    11a6:	c1 e1 04             	shl    ecx,0x4
    11a9:	49 d3 e0             	shl    r8,cl
    11ac:	4c 31 c2             	xor    rdx,r8
    11af:	ff c6                	inc    esi
    11b1:	83 fe 20             	cmp    esi,0x20
    11b4:	75 9a                	jne    1150 <tc_packet_checksum_fold_prog+0x50>
    11b6:	89 57 10             	mov    DWORD PTR [rdi+0x10],edx
    11b9:	48 c1 ea 20          	shr    rdx,0x20
    11bd:	31 c0                	xor    eax,eax
    11bf:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    11c2:	c3                   	ret

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
  11:	48 8b 57 50          	mov    rdx,QWORD PTR [rdi+0x50]
  15:	48 8b b7 d0 00 00 00 	mov    rsi,QWORD PTR [rdi+0xd0]
  1c:	48 39 d6             	cmp    rsi,rdx
  1f:	77 1b                	ja     0x3c
  21:	48 89 f1             	mov    rcx,rsi
  24:	48 83 c1 08          	add    rcx,0x8
  28:	48 39 d1             	cmp    rcx,rdx
  2b:	77 0f                	ja     0x3c
  2d:	48 89 f1             	mov    rcx,rsi
  30:	48 81 c1 10 04 00 00 	add    rcx,0x410
  37:	48 39 ca             	cmp    rdx,rcx
  3a:	73 17                	jae    0x53
  3c:	bb ff ff ff ff       	mov    ebx,0xffffffff
  41:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
  44:	b8 02 00 00 00       	mov    eax,0x2
  49:	89 5f 34             	mov    DWORD PTR [rdi+0x34],ebx
  4c:	41 5e                	pop    r14
  4e:	41 5d                	pop    r13
  50:	5b                   	pop    rbx
  51:	c9                   	leave
  52:	c3                   	ret
  53:	48 0f b6 56 09       	movzx  rdx,BYTE PTR [rsi+0x9]
  58:	48 c1 e2 08          	shl    rdx,0x8
  5c:	48 0f b6 4e 08       	movzx  rcx,BYTE PTR [rsi+0x8]
  61:	48 09 ca             	or     rdx,rcx
  64:	48 0f b6 4e 0a       	movzx  rcx,BYTE PTR [rsi+0xa]
  69:	48 c1 e1 10          	shl    rcx,0x10
  6d:	48 09 ca             	or     rdx,rcx
  70:	48 0f b6 4e 0b       	movzx  rcx,BYTE PTR [rsi+0xb]
  75:	48 c1 e1 18          	shl    rcx,0x18
  79:	48 09 ca             	or     rdx,rcx
  7c:	48 c1 e2 20          	shl    rdx,0x20
  80:	48 c1 ea 20          	shr    rdx,0x20
  84:	48 83 fa 20          	cmp    rdx,0x20
  88:	75 b2                	jne    0x3c
  8a:	48 0f b6 56 0d       	movzx  rdx,BYTE PTR [rsi+0xd]
  8f:	48 c1 e2 08          	shl    rdx,0x8
  93:	48 0f b6 4e 0c       	movzx  rcx,BYTE PTR [rsi+0xc]
  98:	48 09 ca             	or     rdx,rcx
  9b:	48 0f b6 4e 0e       	movzx  rcx,BYTE PTR [rsi+0xe]
  a0:	48 c1 e1 10          	shl    rcx,0x10
  a4:	48 09 ca             	or     rdx,rcx
  a7:	48 0f b6 4e 0f       	movzx  rcx,BYTE PTR [rsi+0xf]
  ac:	48 c1 e1 18          	shl    rcx,0x18
  b0:	48 09 ca             	or     rdx,rcx
  b3:	48 c1 e2 20          	shl    rdx,0x20
  b7:	48 c1 ea 20          	shr    rdx,0x20
  bb:	48 81 fa 00 02 00 00 	cmp    rdx,0x200
  c2:	0f 85 74 ff ff ff    	jne    0x3c
  c8:	31 d2                	xor    edx,edx
  ca:	b9 00 00 ff ff       	mov    ecx,0xffff0000
  cf:	45 31 c0             	xor    r8d,r8d
  d2:	31 c0                	xor    eax,eax
  d4:	31 db                	xor    ebx,ebx
  d6:	49 89 f5             	mov    r13,rsi
  d9:	49 01 c5             	add    r13,rax
  dc:	4d 0f b6 75 10       	movzx  r14,BYTE PTR [r13+0x10]
  e1:	4d 0f b6 6d 11       	movzx  r13,BYTE PTR [r13+0x11]
  e6:	49 c1 e5 08          	shl    r13,0x8
  ea:	4d 09 f5             	or     r13,r14
  ed:	49 01 dd             	add    r13,rbx
  f0:	4c 89 eb             	mov    rbx,r13
  f3:	48 21 cb             	and    rbx,rcx
  f6:	49 81 e5 ff ff 00 00 	and    r13,0xffff
  fd:	48 c1 eb 10          	shr    rbx,0x10
 101:	49 01 dd             	add    r13,rbx
 104:	48 83 c0 02          	add    rax,0x2
 108:	4c 89 eb             	mov    rbx,r13
 10b:	48 81 f8 00 04 00 00 	cmp    rax,0x400
 112:	74 02                	je     0x116
 114:	eb c0                	jmp    0xd6
 116:	4c 89 eb             	mov    rbx,r13
 119:	48 c1 eb 10          	shr    rbx,0x10
 11d:	4c 01 eb             	add    rbx,r13
 120:	48 83 f3 ff          	xor    rbx,0xffffffffffffffff
 124:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 12b:	48 89 d0             	mov    rax,rdx
 12e:	48 c1 e0 04          	shl    rax,0x4
 132:	48 83 e0 30          	and    rax,0x30
 136:	c4 e2 f9 f7 db       	shlx   rbx,rbx,rax
 13b:	4c 31 c3             	xor    rbx,r8
 13e:	48 83 c2 01          	add    rdx,0x1
 142:	48 89 d0             	mov    rax,rdx
 145:	48 c1 e0 20          	shl    rax,0x20
 149:	48 c1 e8 20          	shr    rax,0x20
 14d:	49 89 d8             	mov    r8,rbx
 150:	48 83 f8 20          	cmp    rax,0x20
 154:	74 05                	je     0x15b
 156:	e9 77 ff ff ff       	jmp    0xd2
 15b:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
 15e:	31 c0                	xor    eax,eax
 160:	48 c1 eb 20          	shr    rbx,0x20
 164:	e9 e0 fe ff ff       	jmp    0x49
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 47 4c             	mov    eax,DWORD PTR [rdi+0x4c]
   7:	8b 4f 50             	mov    ecx,DWORD PTR [rdi+0x50]
   a:	39 c8                	cmp    eax,ecx
   c:	0f 87 a4 00 00 00    	ja     0xb6
  12:	48 8d 50 08          	lea    rdx,[rax+0x8]
  16:	48 39 ca             	cmp    rdx,rcx
  19:	0f 87 97 00 00 00    	ja     0xb6
  1f:	48 8d 90 10 04 00 00 	lea    rdx,[rax+0x410]
  26:	48 39 ca             	cmp    rdx,rcx
  29:	0f 87 87 00 00 00    	ja     0xb6
  2f:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
  33:	0f 85 7d 00 00 00    	jne    0xb6
  39:	81 78 0c 00 02 00 00 	cmp    DWORD PTR [rax+0xc],0x200
  40:	75 74                	jne    0xb6
  42:	31 c9                	xor    ecx,ecx
  44:	31 d2                	xor    edx,edx
  46:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  4d:	00 00 00 
  50:	45 31 c0             	xor    r8d,r8d
  53:	31 f6                	xor    esi,esi
  55:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  5c:	00 00 00 00 
  60:	44 0f b7 4c 30 10    	movzx  r9d,WORD PTR [rax+rsi*1+0x10]
  66:	4d 01 c1             	add    r9,r8
  69:	45 0f b7 d1          	movzx  r10d,r9w
  6d:	41 c1 e9 10          	shr    r9d,0x10
  71:	4d 89 c8             	mov    r8,r9
  74:	4d 01 d0             	add    r8,r10
  77:	48 83 c6 02          	add    rsi,0x2
  7b:	48 81 fe 00 04 00 00 	cmp    rsi,0x400
  82:	75 dc                	jne    0x60
  84:	44 89 c6             	mov    esi,r8d
  87:	c1 ee 10             	shr    esi,0x10
  8a:	44 01 c6             	add    esi,r8d
  8d:	f7 d6                	not    esi
  8f:	0f b7 f6             	movzx  esi,si
  92:	41 89 d0             	mov    r8d,edx
  95:	41 c1 e0 04          	shl    r8d,0x4
  99:	c4 e2 b9 f7 f6       	shlx   rsi,rsi,r8
  9e:	48 31 f1             	xor    rcx,rsi
  a1:	48 ff c2             	inc    rdx
  a4:	83 fa 20             	cmp    edx,0x20
  a7:	75 a7                	jne    0x50
  a9:	89 4f 30             	mov    DWORD PTR [rdi+0x30],ecx
  ac:	48 c1 e9 20          	shr    rcx,0x20
  b0:	31 c0                	xor    eax,eax
  b2:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
  b5:	c3                   	ret
  b6:	c7 47 30 ff ff ff ff 	mov    DWORD PTR [rdi+0x30],0xffffffff
  bd:	b8 02 00 00 00       	mov    eax,0x2
  c2:	b9 ff ff ff ff       	mov    ecx,0xffffffff
  c7:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
  ca:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
