# packet_toeplitz_rss_hash

## Original C
```c
#include "common.h"

#define PACKET_TOEPLITZ_RSS_INPUT_SIZE 54U
#define PACKET_TOEPLITZ_TUPLE_BITS 104U

static __always_inline u8 packet_toeplitz_key_byte(u32 index)
{
    switch (index) {
    case 0U: return 0x6DU;
    case 1U: return 0x5AU;
    case 2U: return 0x56U;
    case 3U: return 0xDAU;
    case 4U: return 0x25U;
    case 5U: return 0x5BU;
    case 6U: return 0x0EU;
    case 7U: return 0xC2U;
    case 8U: return 0x41U;
    case 9U: return 0x67U;
    case 10U: return 0x25U;
    case 11U: return 0x3DU;
    case 12U: return 0x43U;
    case 13U: return 0xA3U;
    case 14U: return 0x8FU;
    case 15U: return 0xB0U;
    case 16U: return 0xD0U;
    default: return 0U;
    }
}

static __always_inline u32 packet_toeplitz_word(u32 bit)
{
    u32 byte = bit >> 3U;
    u32 shift = bit & 7U;
    u32 word = ((u32)packet_toeplitz_key_byte(byte) << 24U) |
               ((u32)packet_toeplitz_key_byte(byte + 1U) << 16U) |
               ((u32)packet_toeplitz_key_byte(byte + 2U) << 8U) |
               (u32)packet_toeplitz_key_byte(byte + 3U);

    if (shift != 0U) {
        word = (word << shift) |
               ((u32)packet_toeplitz_key_byte(byte + 4U) >> (8U - shift));
    }
    return word;
}

static __always_inline u8
packet_toeplitz_tuple_byte(const u8 *data, u32 ip, u32 tcp, u32 index)
{
    if (index < 4U) {
        return data[ip + 12U + index];
    }
    if (index < 8U) {
        return data[ip + 16U + (index - 4U)];
    }
    if (index < 10U) {
        return data[tcp + (index - 8U)];
    }
    if (index < 12U) {
        return data[tcp + 2U + (index - 10U)];
    }
    return data[ip + 9U];
}

static __always_inline int
bench_packet_toeplitz_rss_hash(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, PACKET_TOEPLITZ_RSS_INPUT_SIZE)) {
        return -1;
    }
    if (micro_read_u16_be(data, 12U) != 0x0800U) {
        return -1;
    }

    u32 ip = 14U;
    u8 ihl = (data[ip] & 0x0FU) * 4U;
    if (ihl != 20U || data[ip + 9U] != 6U) {
        return -1;
    }
    u32 tcp = ip + ihl;
    if (!micro_has_bytes(len, tcp, 20U)) {
        return -1;
    }

    u32 hash = 0U;
    for (u32 bit = 0; bit < PACKET_TOEPLITZ_TUPLE_BITS; bit++) {
        u8 tuple = packet_toeplitz_tuple_byte(data, ip, tcp, bit >> 3U);
        if ((tuple & (0x80U >> (bit & 7U))) != 0U) {
            hash ^= packet_toeplitz_word(bit);
        }
    }

    u32 src = micro_read_u32_be(data, ip + 12U);
    u32 dst = micro_read_u32_be(data, ip + 16U);
    u16 sport = micro_read_u16_be(data, tcp);
    u16 dport = micro_read_u16_be(data, tcp + 2U);
    u64 acc = ((u64)hash << 32U) | (hash ^ src ^ dst);
    acc ^= micro_rotl64(((u64)sport << 48U) | ((u64)dport << 32U) |
                            ((u64)src ^ dst),
                        (hash & 7U) + 1U);

    *out = acc;
    return 0;
}

DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(
    packet_toeplitz_rss_hash_xdp,
    bench_packet_toeplitz_rss_hash,
    PACKET_TOEPLITZ_RSS_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <packet_toeplitz_rss_hash_xdp>:
    1100:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ce             	cmp    rsi,rcx
    110c:	76 01                	jbe    110f <packet_toeplitz_rss_hash_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 56 08          	lea    rdx,[rsi+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <packet_toeplitz_rss_hash_xdp+0xe>
    1118:	48 8d 56 3e          	lea    rdx,[rsi+0x3e]
    111c:	48 39 ca             	cmp    rdx,rcx
    111f:	77 ed                	ja     110e <packet_toeplitz_rss_hash_xdp+0xe>
    1121:	0f b7 4e 14          	movzx  ecx,WORD PTR [rsi+0x14]
    1125:	66 c1 c1 08          	rol    cx,0x8
    1129:	0f b7 c9             	movzx  ecx,cx
    112c:	81 f9 00 08 00 00    	cmp    ecx,0x800
    1132:	75 da                	jne    110e <packet_toeplitz_rss_hash_xdp+0xe>
    1134:	0f b6 4e 16          	movzx  ecx,BYTE PTR [rsi+0x16]
    1138:	80 e1 0f             	and    cl,0xf
    113b:	80 f9 05             	cmp    cl,0x5
    113e:	75 ce                	jne    110e <packet_toeplitz_rss_hash_xdp+0xe>
    1140:	80 7e 1f 06          	cmp    BYTE PTR [rsi+0x1f],0x6
    1144:	75 c8                	jne    110e <packet_toeplitz_rss_hash_xdp+0xe>
    1146:	55                   	push   rbp
    1147:	41 56                	push   r14
    1149:	53                   	push   rbx
    114a:	48 8d 7e 1f          	lea    rdi,[rsi+0x1f]
    114e:	4c 8d 46 22          	lea    r8,[rsi+0x22]
    1152:	31 c0                	xor    eax,eax
    1154:	4c 8d 0d a5 0e 00 00 	lea    r9,[rip+0xea5]        # 2000 <_fini+0xdbc>
    115b:	4c 8d 15 d2 0e 00 00 	lea    r10,[rip+0xed2]        # 2034 <_fini+0xdf0>
    1162:	4c 8d 1d ff 0e 00 00 	lea    r11,[rip+0xeff]        # 2068 <_fini+0xe24>
    1169:	31 db                	xor    ebx,ebx
    116b:	eb 0c                	jmp    1179 <packet_toeplitz_rss_hash_xdp+0x79>
    116d:	0f 1f 00             	nop    DWORD PTR [rax]
    1170:	31 e8                	xor    eax,ebp
    1172:	ff c3                	inc    ebx
    1174:	83 fb 68             	cmp    ebx,0x68
    1177:	74 5d                	je     11d6 <packet_toeplitz_rss_hash_xdp+0xd6>
    1179:	89 da                	mov    edx,ebx
    117b:	c1 ea 03             	shr    edx,0x3
    117e:	83 fb 1f             	cmp    ebx,0x1f
    1181:	76 1d                	jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0>
    1183:	83 fb 3f             	cmp    ebx,0x3f
    1186:	76 18                	jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0>
    1188:	83 fb 4f             	cmp    ebx,0x4f
    118b:	76 13                	jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0>
    118d:	48 89 f9             	mov    rcx,rdi
    1190:	83 fb 5f             	cmp    ebx,0x5f
    1193:	77 10                	ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5>
    1195:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    119c:	00 00 00 00 
    11a0:	89 d1                	mov    ecx,edx
    11a2:	4c 01 c1             	add    rcx,r8
    11a5:	0f b6 29             	movzx  ebp,BYTE PTR [rcx]
    11a8:	89 d9                	mov    ecx,ebx
    11aa:	83 e1 07             	and    ecx,0x7
    11ad:	d3 e5                	shl    ebp,cl
    11af:	40 84 ed             	test   bpl,bpl
    11b2:	79 be                	jns    1172 <packet_toeplitz_rss_hash_xdp+0x72>
    11b4:	89 d2                	mov    edx,edx
    11b6:	41 8b 2c 92          	mov    ebp,DWORD PTR [r10+rdx*4]
    11ba:	41 0b 2c 91          	or     ebp,DWORD PTR [r9+rdx*4]
    11be:	85 c9                	test   ecx,ecx
    11c0:	74 ae                	je     1170 <packet_toeplitz_rss_hash_xdp+0x70>
    11c2:	d3 e5                	shl    ebp,cl
    11c4:	45 8b 34 93          	mov    r14d,DWORD PTR [r11+rdx*4]
    11c8:	b2 08                	mov    dl,0x8
    11ca:	28 ca                	sub    dl,cl
    11cc:	89 d1                	mov    ecx,edx
    11ce:	41 d3 ee             	shr    r14d,cl
    11d1:	44 09 f5             	or     ebp,r14d
    11d4:	eb 9a                	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    11d6:	8b 56 26             	mov    edx,DWORD PTR [rsi+0x26]
    11d9:	0f b6 4e 2a          	movzx  ecx,BYTE PTR [rsi+0x2a]
    11dd:	44 0f b6 46 2b       	movzx  r8d,BYTE PTR [rsi+0x2b]
    11e2:	44 0f b6 4e 2c       	movzx  r9d,BYTE PTR [rsi+0x2c]
    11e7:	44 0f b6 56 2d       	movzx  r10d,BYTE PTR [rsi+0x2d]
    11ec:	49 89 c3             	mov    r11,rax
    11ef:	49 c1 e3 20          	shl    r11,0x20
    11f3:	33 56 22             	xor    edx,DWORD PTR [rsi+0x22]
    11f6:	0f ca                	bswap  edx
    11f8:	89 d7                	mov    edi,edx
    11fa:	31 c7                	xor    edi,eax
    11fc:	4c 09 df             	or     rdi,r11
    11ff:	48 c1 e1 38          	shl    rcx,0x38
    1203:	49 c1 e0 30          	shl    r8,0x30
    1207:	49 09 c8             	or     r8,rcx
    120a:	49 c1 e1 28          	shl    r9,0x28
    120e:	4d 09 c1             	or     r9,r8
    1211:	49 c1 e2 20          	shl    r10,0x20
    1215:	4c 09 ca             	or     rdx,r9
    1218:	4c 09 d2             	or     rdx,r10
    121b:	83 e0 07             	and    eax,0x7
    121e:	8d 48 01             	lea    ecx,[rax+0x1]
    1221:	49 89 d0             	mov    r8,rdx
    1224:	49 d3 e0             	shl    r8,cl
    1227:	f6 d0                	not    al
    1229:	89 c1                	mov    ecx,eax
    122b:	48 d3 ea             	shr    rdx,cl
    122e:	4c 09 c2             	or     rdx,r8
    1231:	48 31 fa             	xor    rdx,rdi
    1234:	48 89 16             	mov    QWORD PTR [rsi],rdx
    1237:	b8 02 00 00 00       	mov    eax,0x2
    123c:	5b                   	pop    rbx
    123d:	41 5e                	pop    r14
    123f:	5d                   	pop    rbp
    1240:	c3                   	ret

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
  11:	31 c0                	xor    eax,eax
  13:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  17:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  1b:	48 39 f7             	cmp    rdi,rsi
  1e:	0f 87 13 04 00 00    	ja     0x437
  24:	48 89 fa             	mov    rdx,rdi
  27:	48 83 c2 08          	add    rdx,0x8
  2b:	48 39 f2             	cmp    rdx,rsi
  2e:	0f 87 03 04 00 00    	ja     0x437
  34:	48 89 fa             	mov    rdx,rdi
  37:	48 83 c2 3e          	add    rdx,0x3e
  3b:	48 39 f2             	cmp    rdx,rsi
  3e:	0f 87 f3 03 00 00    	ja     0x437
  44:	48 0f b6 77 15       	movzx  rsi,BYTE PTR [rdi+0x15]
  49:	48 0f b6 57 14       	movzx  rdx,BYTE PTR [rdi+0x14]
  4e:	48 c1 e2 08          	shl    rdx,0x8
  52:	48 09 f2             	or     rdx,rsi
  55:	48 81 e2 ff ff 00 00 	and    rdx,0xffff
  5c:	48 81 fa 00 08 00 00 	cmp    rdx,0x800
  63:	0f 85 ce 03 00 00    	jne    0x437
  69:	48 0f b6 77 16       	movzx  rsi,BYTE PTR [rdi+0x16]
  6e:	48 83 e6 0f          	and    rsi,0xf
  72:	48 83 fe 05          	cmp    rsi,0x5
  76:	0f 85 bb 03 00 00    	jne    0x437
  7c:	48 0f b6 77 1f       	movzx  rsi,BYTE PTR [rdi+0x1f]
  81:	48 83 fe 06          	cmp    rsi,0x6
  85:	0f 85 ac 03 00 00    	jne    0x437
  8b:	48 89 fa             	mov    rdx,rdi
  8e:	48 83 c2 1f          	add    rdx,0x1f
  92:	31 f6                	xor    esi,esi
  94:	48 89 f9             	mov    rcx,rdi
  97:	48 83 c1 22          	add    rcx,0x22
  9b:	45 31 c0             	xor    r8d,r8d
  9e:	eb 35                	jmp    0xd5
  a0:	41 bd c2 00 00 00    	mov    r13d,0xc2
  a6:	bb 08 00 00 00       	mov    ebx,0x8
  ab:	48 29 c3             	sub    rbx,rax
  ae:	c4 42 e3 f7 ed       	shrx   r13,r13,rbx
  b3:	4d 09 f5             	or     r13,r14
  b6:	49 31 f5             	xor    r13,rsi
  b9:	4c 89 ee             	mov    rsi,r13
  bc:	49 83 c0 01          	add    r8,0x1
  c0:	4c 89 c0             	mov    rax,r8
  c3:	48 c1 e0 20          	shl    rax,0x20
  c7:	48 c1 e8 20          	shr    rax,0x20
  cb:	48 83 f8 68          	cmp    rax,0x68
  cf:	0f 84 4a 02 00 00    	je     0x31f
  d5:	4c 89 c0             	mov    rax,r8
  d8:	48 c1 e0 20          	shl    rax,0x20
  dc:	48 c1 e8 20          	shr    rax,0x20
  e0:	48 89 c3             	mov    rbx,rax
  e3:	48 c1 eb 03          	shr    rbx,0x3
  e7:	48 83 f8 1f          	cmp    rax,0x1f
  eb:	77 02                	ja     0xef
  ed:	eb 24                	jmp    0x113
  ef:	48 83 f8 3f          	cmp    rax,0x3f
  f3:	77 02                	ja     0xf7
  f5:	eb 1c                	jmp    0x113
  f7:	4c 89 c0             	mov    rax,r8
  fa:	48 c1 e0 20          	shl    rax,0x20
  fe:	48 c1 e8 20          	shr    rax,0x20
 102:	48 83 f8 4f          	cmp    rax,0x4f
 106:	77 02                	ja     0x10a
 108:	eb 09                	jmp    0x113
 10a:	49 89 d5             	mov    r13,rdx
 10d:	48 83 f8 5f          	cmp    rax,0x5f
 111:	77 06                	ja     0x119
 113:	49 89 cd             	mov    r13,rcx
 116:	49 01 dd             	add    r13,rbx
 119:	4c 89 c0             	mov    rax,r8
 11c:	48 83 e0 07          	and    rax,0x7
 120:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 125:	c4 42 f9 f7 ed       	shlx   r13,r13,rax
 12a:	49 81 e5 80 00 00 00 	and    r13,0x80
 131:	4d 85 ed             	test   r13,r13
 134:	74 86                	je     0xbc
 136:	48 83 fb 05          	cmp    rbx,0x5
 13a:	7f 36                	jg     0x172
 13c:	48 83 fb 02          	cmp    rbx,0x2
 140:	7f 70                	jg     0x1b2
 142:	41 bd da 00 00 00    	mov    r13d,0xda
 148:	41 be 00 56 5a 6d    	mov    r14d,0x6d5a5600
 14e:	48 85 db             	test   rbx,rbx
 151:	0f 84 e9 00 00 00    	je     0x240
 157:	48 83 fb 01          	cmp    rbx,0x1
 15b:	0f 84 c5 00 00 00    	je     0x226
 161:	41 bd 5b 00 00 00    	mov    r13d,0x5b
 167:	41 be 00 25 da 56    	mov    r14d,0x56da2500
 16d:	e9 ce 00 00 00       	jmp    0x240
 172:	48 83 fb 08          	cmp    rbx,0x8
 176:	7f 1d                	jg     0x195
 178:	48 83 fb 06          	cmp    rbx,0x6
 17c:	74 62                	je     0x1e0
 17e:	48 83 fb 07          	cmp    rbx,0x7
 182:	74 78                	je     0x1fc
 184:	41 bd 3d 00 00 00    	mov    r13d,0x3d
 18a:	41 be 00 25 67 41    	mov    r14d,0x41672500
 190:	e9 ab 00 00 00       	jmp    0x240
 195:	48 83 fb 0a          	cmp    rbx,0xa
 199:	7f 31                	jg     0x1cc
 19b:	48 83 fb 09          	cmp    rbx,0x9
 19f:	74 69                	je     0x20a
 1a1:	41 bd a3 00 00 00    	mov    r13d,0xa3
 1a7:	41 be 00 43 3d 25    	mov    r14d,0x253d4300
 1ad:	e9 8e 00 00 00       	jmp    0x240
 1b2:	48 83 fb 03          	cmp    rbx,0x3
 1b6:	74 36                	je     0x1ee
 1b8:	48 83 fb 04          	cmp    rbx,0x4
 1bc:	74 76                	je     0x234
 1be:	41 bd 41 00 00 00    	mov    r13d,0x41
 1c4:	41 be 00 c2 0e 5b    	mov    r14d,0x5b0ec200
 1ca:	eb 74                	jmp    0x240
 1cc:	48 83 fb 0b          	cmp    rbx,0xb
 1d0:	74 46                	je     0x218
 1d2:	41 bd b0 00 00 00    	mov    r13d,0xb0
 1d8:	41 be 00 8f a3 43    	mov    r14d,0x43a38f00
 1de:	eb 60                	jmp    0x240
 1e0:	41 bd 67 00 00 00    	mov    r13d,0x67
 1e6:	41 be 00 41 c2 0e    	mov    r14d,0xec24100
 1ec:	eb 52                	jmp    0x240
 1ee:	41 bd 0e 00 00 00    	mov    r13d,0xe
 1f4:	41 be 00 5b 25 da    	mov    r14d,0xda255b00
 1fa:	eb 44                	jmp    0x240
 1fc:	41 bd 25 00 00 00    	mov    r13d,0x25
 202:	41 be 00 67 41 c2    	mov    r14d,0xc2416700
 208:	eb 36                	jmp    0x240
 20a:	41 bd 43 00 00 00    	mov    r13d,0x43
 210:	41 be 00 3d 25 67    	mov    r14d,0x67253d00
 216:	eb 28                	jmp    0x240
 218:	41 bd 8f 00 00 00    	mov    r13d,0x8f
 21e:	41 be 00 a3 43 3d    	mov    r14d,0x3d43a300
 224:	eb 1a                	jmp    0x240
 226:	41 bd 25 00 00 00    	mov    r13d,0x25
 22c:	41 be 00 da 56 5a    	mov    r14d,0x5a56da00
 232:	eb 0c                	jmp    0x240
 234:	41 bd c2 00 00 00    	mov    r13d,0xc2
 23a:	41 be 00 0e 5b 25    	mov    r14d,0x255b0e00
 240:	4d 09 f5             	or     r13,r14
 243:	48 85 c0             	test   rax,rax
 246:	0f 84 6a fe ff ff    	je     0xb6
 24c:	4d 89 ee             	mov    r14,r13
 24f:	c4 42 f9 f7 f6       	shlx   r14,r14,rax
 254:	41 bd 25 00 00 00    	mov    r13d,0x25
 25a:	48 83 fb 05          	cmp    rbx,0x5
 25e:	7f 24                	jg     0x284
 260:	48 83 fb 02          	cmp    rbx,0x2
 264:	7f 56                	jg     0x2bc
 266:	48 85 db             	test   rbx,rbx
 269:	0f 84 37 fe ff ff    	je     0xa6
 26f:	48 83 fb 01          	cmp    rbx,0x1
 273:	0f 84 90 00 00 00    	je     0x309
 279:	41 bd 0e 00 00 00    	mov    r13d,0xe
 27f:	e9 22 fe ff ff       	jmp    0xa6
 284:	48 83 fb 08          	cmp    rbx,0x8
 288:	7f 1b                	jg     0x2a5
 28a:	48 83 fb 06          	cmp    rbx,0x6
 28e:	0f 84 12 fe ff ff    	je     0xa6
 294:	48 83 fb 07          	cmp    rbx,0x7
 298:	74 4e                	je     0x2e8
 29a:	41 bd 43 00 00 00    	mov    r13d,0x43
 2a0:	e9 01 fe ff ff       	jmp    0xa6
 2a5:	48 83 fb 0a          	cmp    rbx,0xa
 2a9:	7f 2c                	jg     0x2d7
 2ab:	48 83 fb 09          	cmp    rbx,0x9
 2af:	74 42                	je     0x2f3
 2b1:	41 bd 8f 00 00 00    	mov    r13d,0x8f
 2b7:	e9 ea fd ff ff       	jmp    0xa6
 2bc:	48 83 fb 03          	cmp    rbx,0x3
 2c0:	0f 84 da fd ff ff    	je     0xa0
 2c6:	48 83 fb 04          	cmp    rbx,0x4
 2ca:	74 48                	je     0x314
 2cc:	41 bd 67 00 00 00    	mov    r13d,0x67
 2d2:	e9 cf fd ff ff       	jmp    0xa6
 2d7:	48 83 fb 0b          	cmp    rbx,0xb
 2db:	74 21                	je     0x2fe
 2dd:	41 bd d0 00 00 00    	mov    r13d,0xd0
 2e3:	e9 be fd ff ff       	jmp    0xa6
 2e8:	41 bd 3d 00 00 00    	mov    r13d,0x3d
 2ee:	e9 b3 fd ff ff       	jmp    0xa6
 2f3:	41 bd a3 00 00 00    	mov    r13d,0xa3
 2f9:	e9 a8 fd ff ff       	jmp    0xa6
 2fe:	41 bd b0 00 00 00    	mov    r13d,0xb0
 304:	e9 9d fd ff ff       	jmp    0xa6
 309:	41 bd 5b 00 00 00    	mov    r13d,0x5b
 30f:	e9 92 fd ff ff       	jmp    0xa6
 314:	41 bd 41 00 00 00    	mov    r13d,0x41
 31a:	e9 87 fd ff ff       	jmp    0xa6
 31f:	48 0f b6 4f 22       	movzx  rcx,BYTE PTR [rdi+0x22]
 324:	48 c1 e1 18          	shl    rcx,0x18
 328:	48 0f b6 57 23       	movzx  rdx,BYTE PTR [rdi+0x23]
 32d:	48 c1 e2 10          	shl    rdx,0x10
 331:	48 09 ca             	or     rdx,rcx
 334:	48 0f b6 4f 24       	movzx  rcx,BYTE PTR [rdi+0x24]
 339:	48 c1 e1 08          	shl    rcx,0x8
 33d:	48 09 ca             	or     rdx,rcx
 340:	48 0f b6 4f 25       	movzx  rcx,BYTE PTR [rdi+0x25]
 345:	48 09 ca             	or     rdx,rcx
 348:	4c 0f b6 47 26       	movzx  r8,BYTE PTR [rdi+0x26]
 34d:	49 c1 e0 18          	shl    r8,0x18
 351:	48 0f b6 4f 27       	movzx  rcx,BYTE PTR [rdi+0x27]
 356:	48 c1 e1 10          	shl    rcx,0x10
 35a:	4c 09 c1             	or     rcx,r8
 35d:	4c 0f b6 47 28       	movzx  r8,BYTE PTR [rdi+0x28]
 362:	49 c1 e0 08          	shl    r8,0x8
 366:	4c 09 c1             	or     rcx,r8
 369:	4c 0f b6 47 29       	movzx  r8,BYTE PTR [rdi+0x29]
 36e:	4c 09 c1             	or     rcx,r8
 371:	48 31 d1             	xor    rcx,rdx
 374:	4c 0f b6 47 2a       	movzx  r8,BYTE PTR [rdi+0x2a]
 379:	49 c1 e0 38          	shl    r8,0x38
 37d:	48 0f b6 57 2b       	movzx  rdx,BYTE PTR [rdi+0x2b]
 382:	48 c1 e2 30          	shl    rdx,0x30
 386:	4c 09 c2             	or     rdx,r8
 389:	4c 0f b6 47 2c       	movzx  r8,BYTE PTR [rdi+0x2c]
 38e:	49 c1 e0 28          	shl    r8,0x28
 392:	4c 09 c2             	or     rdx,r8
 395:	49 89 c8             	mov    r8,rcx
 398:	49 c1 e0 20          	shl    r8,0x20
 39c:	49 c1 e8 20          	shr    r8,0x20
 3a0:	4c 09 c2             	or     rdx,r8
 3a3:	4c 0f b6 47 2d       	movzx  r8,BYTE PTR [rdi+0x2d]
 3a8:	49 c1 e0 20          	shl    r8,0x20
 3ac:	4c 09 c2             	or     rdx,r8
 3af:	49 89 f0             	mov    r8,rsi
 3b2:	49 83 e0 07          	and    r8,0x7
 3b6:	4c 89 c0             	mov    rax,r8
 3b9:	48 83 c0 01          	add    rax,0x1
 3bd:	49 83 f0 3f          	xor    r8,0x3f
 3c1:	48 89 d3             	mov    rbx,rdx
 3c4:	c4 e2 bb f7 db       	shrx   rbx,rbx,r8
 3c9:	c4 e2 f9 f7 d2       	shlx   rdx,rdx,rax
 3ce:	48 09 da             	or     rdx,rbx
 3d1:	48 31 f1             	xor    rcx,rsi
 3d4:	48 c1 e6 20          	shl    rsi,0x20
 3d8:	48 c1 e1 20          	shl    rcx,0x20
 3dc:	48 c1 e9 20          	shr    rcx,0x20
 3e0:	48 09 ce             	or     rsi,rcx
 3e3:	48 31 f2             	xor    rdx,rsi
 3e6:	48 89 d6             	mov    rsi,rdx
 3e9:	48 c1 ee 38          	shr    rsi,0x38
 3ed:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 3f1:	48 89 d6             	mov    rsi,rdx
 3f4:	48 c1 ee 30          	shr    rsi,0x30
 3f8:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 3fc:	48 89 d6             	mov    rsi,rdx
 3ff:	48 c1 ee 28          	shr    rsi,0x28
 403:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 407:	48 89 d6             	mov    rsi,rdx
 40a:	48 c1 ee 20          	shr    rsi,0x20
 40e:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 412:	48 89 d6             	mov    rsi,rdx
 415:	48 c1 ee 18          	shr    rsi,0x18
 419:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 41d:	48 89 d6             	mov    rsi,rdx
 420:	48 c1 ee 10          	shr    rsi,0x10
 424:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 428:	88 57 00             	mov    BYTE PTR [rdi+0x0],dl
 42b:	48 c1 ea 08          	shr    rdx,0x8
 42f:	88 57 01             	mov    BYTE PTR [rdi+0x1],dl
 432:	b8 02 00 00 00       	mov    eax,0x2
 437:	41 5e                	pop    r14
 439:	41 5d                	pop    r13
 43b:	5b                   	pop    rbx
 43c:	c9                   	leave
 43d:	c3                   	ret
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
   d:	0f 87 3a 03 00 00    	ja     0x34d
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 2d 03 00 00    	ja     0x34d
  20:	48 8d 71 3e          	lea    rsi,[rcx+0x3e]
  24:	48 39 d6             	cmp    rsi,rdx
  27:	0f 87 20 03 00 00    	ja     0x34d
  2d:	66 0f 38 f0 41 14    	movbe  ax,WORD PTR [rcx+0x14]
  33:	0f b7 c0             	movzx  eax,ax
  36:	3d 00 08 00 00       	cmp    eax,0x800
  3b:	75 40                	jne    0x7d
  3d:	0f b6 41 16          	movzx  eax,BYTE PTR [rcx+0x16]
  41:	24 0f                	and    al,0xf
  43:	3c 05                	cmp    al,0x5
  45:	75 36                	jne    0x7d
  47:	80 79 1f 06          	cmp    BYTE PTR [rcx+0x1f],0x6
  4b:	75 30                	jne    0x7d
  4d:	55                   	push   rbp
  4e:	41 57                	push   r15
  50:	41 56                	push   r14
  52:	41 55                	push   r13
  54:	41 54                	push   r12
  56:	53                   	push   rbx
  57:	48 8d 71 1f          	lea    rsi,[rcx+0x1f]
  5b:	48 8d 79 22          	lea    rdi,[rcx+0x22]
  5f:	31 c0                	xor    eax,eax
  61:	41 be 3d 00 00 00    	mov    r14d,0x3d
  67:	41 bf 25 00 00 00    	mov    r15d,0x25
  6d:	41 bc 41 00 00 00    	mov    r12d,0x41
  73:	41 bd c2 00 00 00    	mov    r13d,0xc2
  79:	31 d2                	xor    edx,edx
  7b:	eb 3a                	jmp    0xb7
  7d:	31 c0                	xor    eax,eax
  7f:	c3                   	ret
  80:	49 83 f8 04          	cmp    r8,0x4
  84:	bb 67 00 00 00       	mov    ebx,0x67
  89:	49 0f 44 dc          	cmove  rbx,r12
  8d:	49 83 f8 03          	cmp    r8,0x3
  91:	49 0f 44 dd          	cmove  rbx,r13
  95:	c4 42 d1 f7 c2       	shlx   r8,r10,rbp
  9a:	41 b1 08             	mov    r9b,0x8
  9d:	41 28 e9             	sub    r9b,bpl
  a0:	c4 62 b3 f7 d3       	shrx   r10,rbx,r9
  a5:	4d 09 c2             	or     r10,r8
  a8:	4c 31 d0             	xor    rax,r10
  ab:	48 ff c2             	inc    rdx
  ae:	83 fa 68             	cmp    edx,0x68
  b1:	0f 84 22 02 00 00    	je     0x2d9
  b7:	41 89 d1             	mov    r9d,edx
  ba:	41 89 d0             	mov    r8d,edx
  bd:	41 c1 e8 03          	shr    r8d,0x3
  c1:	4e 8d 14 07          	lea    r10,[rdi+r8*1]
  c5:	49 83 f9 60          	cmp    r9,0x60
  c9:	4c 0f 43 d6          	cmovae r10,rsi
  cd:	89 d5                	mov    ebp,edx
  cf:	83 e5 07             	and    ebp,0x7
  d2:	45 0f b6 12          	movzx  r10d,BYTE PTR [r10]
  d6:	c4 42 d1 f7 d2       	shlx   r10,r10,rbp
  db:	45 84 d2             	test   r10b,r10b
  de:	79 cb                	jns    0xab
  e0:	41 83 f9 2f          	cmp    r9d,0x2f
  e4:	76 4a                	jbe    0x130
  e6:	41 83 f9 47          	cmp    r9d,0x47
  ea:	76 7c                	jbe    0x168
  ec:	41 83 f9 57          	cmp    r9d,0x57
  f0:	0f 86 ba 00 00 00    	jbe    0x1b0
  f6:	49 83 f8 0b          	cmp    r8,0xb
  fa:	41 ba b0 00 00 00    	mov    r10d,0xb0
 100:	bb 8f 00 00 00       	mov    ebx,0x8f
 105:	4c 0f 44 d3          	cmove  r10,rbx
 109:	41 83 f8 0b          	cmp    r8d,0xb
 10d:	bb 00 8f a3 43       	mov    ebx,0x43a38f00
 112:	41 bb 00 a3 43 3d    	mov    r11d,0x3d43a300
 118:	49 0f 44 db          	cmove  rbx,r11
 11c:	e9 1f 01 00 00       	jmp    0x240
 121:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 128:	0f 1f 84 00 00 00 00 
 12f:	00 
 130:	41 83 f9 17          	cmp    r9d,0x17
 134:	76 64                	jbe    0x19a
 136:	45 89 c2             	mov    r10d,r8d
 139:	41 80 e2 07          	and    r10b,0x7
 13d:	41 80 fa 03          	cmp    r10b,0x3
 141:	0f 84 b5 00 00 00    	je     0x1fc
 147:	45 89 c2             	mov    r10d,r8d
 14a:	41 83 e2 07          	and    r10d,0x7
 14e:	41 83 fa 04          	cmp    r10d,0x4
 152:	0f 85 c6 00 00 00    	jne    0x21e
 158:	bb 00 0e 5b 25       	mov    ebx,0x255b0e00
 15d:	41 ba c2 00 00 00    	mov    r10d,0xc2
 163:	e9 d8 00 00 00       	jmp    0x240
 168:	45 89 c2             	mov    r10d,r8d
 16b:	41 80 e2 0f          	and    r10b,0xf
 16f:	41 80 fa 06          	cmp    r10b,0x6
 173:	0f 84 98 00 00 00    	je     0x211
 179:	45 89 c2             	mov    r10d,r8d
 17c:	41 83 e2 0f          	and    r10d,0xf
 180:	41 83 fa 07          	cmp    r10d,0x7
 184:	0f 85 a1 00 00 00    	jne    0x22b
 18a:	41 ba 25 00 00 00    	mov    r10d,0x25
 190:	bb 00 67 41 c2       	mov    ebx,0xc2416700
 195:	e9 a6 00 00 00       	jmp    0x240
 19a:	41 83 f9 08          	cmp    r9d,0x8
 19e:	73 39                	jae    0x1d9
 1a0:	bb 00 56 5a 6d       	mov    ebx,0x6d5a5600
 1a5:	41 ba da 00 00 00    	mov    r10d,0xda
 1ab:	e9 90 00 00 00       	jmp    0x240
 1b0:	49 83 f8 09          	cmp    r8,0x9
 1b4:	41 ba a3 00 00 00    	mov    r10d,0xa3
 1ba:	41 bb 43 00 00 00    	mov    r11d,0x43
 1c0:	4d 0f 44 d3          	cmove  r10,r11
 1c4:	41 83 f8 09          	cmp    r8d,0x9
 1c8:	bb 00 43 3d 25       	mov    ebx,0x253d4300
 1cd:	41 bb 00 3d 25 67    	mov    r11d,0x67253d00
 1d3:	49 0f 44 db          	cmove  rbx,r11
 1d7:	eb 67                	jmp    0x240
 1d9:	49 83 f8 01          	cmp    r8,0x1
 1dd:	41 ba 5b 00 00 00    	mov    r10d,0x5b
 1e3:	4d 0f 44 d7          	cmove  r10,r15
 1e7:	41 83 f8 01          	cmp    r8d,0x1
 1eb:	bb 00 25 da 56       	mov    ebx,0x56da2500
 1f0:	41 bb 00 da 56 5a    	mov    r11d,0x5a56da00
 1f6:	49 0f 44 db          	cmove  rbx,r11
 1fa:	eb 44                	jmp    0x240
 1fc:	41 ba 00 67 41 c2    	mov    r10d,0xc2416700
 202:	49 8d 9a 00 f4 e3 17 	lea    rbx,[r10+0x17e3f400]
 209:	41 ba 0e 00 00 00    	mov    r10d,0xe
 20f:	eb 2f                	jmp    0x240
 211:	bb 00 41 c2 0e       	mov    ebx,0xec24100
 216:	41 ba 67 00 00 00    	mov    r10d,0x67
 21c:	eb 22                	jmp    0x240
 21e:	bb 00 c2 0e 5b       	mov    ebx,0x5b0ec200
 223:	41 ba 41 00 00 00    	mov    r10d,0x41
 229:	eb 15                	jmp    0x240
 22b:	bb 00 25 67 41       	mov    ebx,0x41672500
 230:	41 ba 3d 00 00 00    	mov    r10d,0x3d
 236:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
 23d:	00 00 00 
 240:	49 09 da             	or     r10,rbx
 243:	48 85 ed             	test   rbp,rbp
 246:	0f 84 5c fe ff ff    	je     0xa8
 24c:	41 83 f9 2f          	cmp    r9d,0x2f
 250:	76 24                	jbe    0x276
 252:	41 83 f9 47          	cmp    r9d,0x47
 256:	76 4f                	jbe    0x2a7
 258:	41 83 f9 57          	cmp    r9d,0x57
 25c:	76 63                	jbe    0x2c1
 25e:	31 db                	xor    ebx,ebx
 260:	41 83 f8 0b          	cmp    r8d,0xb
 264:	0f 95 c3             	setne  bl
 267:	c1 e3 05             	shl    ebx,0x5
 26a:	48 81 c3 b0 00 00 00 	add    rbx,0xb0
 271:	e9 1f fe ff ff       	jmp    0x95
 276:	41 83 f9 17          	cmp    r9d,0x17
 27a:	0f 87 00 fe ff ff    	ja     0x80
 280:	bb 25 00 00 00       	mov    ebx,0x25
 285:	41 83 f9 08          	cmp    r9d,0x8
 289:	0f 82 06 fe ff ff    	jb     0x95
 28f:	41 83 f8 01          	cmp    r8d,0x1
 293:	bb 0e 00 00 00       	mov    ebx,0xe
 298:	41 b8 5b 00 00 00    	mov    r8d,0x5b
 29e:	49 0f 44 d8          	cmove  rbx,r8
 2a2:	e9 ee fd ff ff       	jmp    0x95
 2a7:	49 83 f8 07          	cmp    r8,0x7
 2ab:	bb 43 00 00 00       	mov    ebx,0x43
 2b0:	49 0f 44 de          	cmove  rbx,r14
 2b4:	49 83 f8 06          	cmp    r8,0x6
 2b8:	49 0f 44 df          	cmove  rbx,r15
 2bc:	e9 d4 fd ff ff       	jmp    0x95
 2c1:	41 83 f8 09          	cmp    r8d,0x9
 2c5:	bb 8f 00 00 00       	mov    ebx,0x8f
 2ca:	41 b8 a3 00 00 00    	mov    r8d,0xa3
 2d0:	49 0f 44 d8          	cmove  rbx,r8
 2d4:	e9 bc fd ff ff       	jmp    0x95
 2d9:	8b 51 26             	mov    edx,DWORD PTR [rcx+0x26]
 2dc:	33 51 22             	xor    edx,DWORD PTR [rcx+0x22]
 2df:	0f ca                	bswap  edx
 2e1:	0f b6 71 2a          	movzx  esi,BYTE PTR [rcx+0x2a]
 2e5:	48 c1 e6 38          	shl    rsi,0x38
 2e9:	0f b6 79 2b          	movzx  edi,BYTE PTR [rcx+0x2b]
 2ed:	48 c1 e7 30          	shl    rdi,0x30
 2f1:	48 09 f7             	or     rdi,rsi
 2f4:	0f b6 71 2c          	movzx  esi,BYTE PTR [rcx+0x2c]
 2f8:	48 c1 e6 28          	shl    rsi,0x28
 2fc:	48 09 fe             	or     rsi,rdi
 2ff:	0f b6 79 2d          	movzx  edi,BYTE PTR [rcx+0x2d]
 303:	48 c1 e7 20          	shl    rdi,0x20
 307:	48 09 f7             	or     rdi,rsi
 30a:	48 09 d7             	or     rdi,rdx
 30d:	89 c6                	mov    esi,eax
 30f:	40 80 e6 07          	and    sil,0x7
 313:	41 89 f0             	mov    r8d,esi
 316:	41 f6 d0             	not    r8b
 319:	c4 62 bb f7 c7       	shrx   r8,rdi,r8
 31e:	40 fe c6             	inc    sil
 321:	c4 e2 c9 f7 f7       	shlx   rsi,rdi,rsi
 326:	4c 09 c6             	or     rsi,r8
 329:	48 89 c7             	mov    rdi,rax
 32c:	48 c1 e7 20          	shl    rdi,0x20
 330:	89 c0                	mov    eax,eax
 332:	48 31 d0             	xor    rax,rdx
 335:	48 09 f8             	or     rax,rdi
 338:	48 31 f0             	xor    rax,rsi
 33b:	48 89 01             	mov    QWORD PTR [rcx],rax
 33e:	b8 02 00 00 00       	mov    eax,0x2
 343:	5b                   	pop    rbx
 344:	41 5c                	pop    r12
 346:	41 5d                	pop    r13
 348:	41 5e                	pop    r14
 34a:	41 5f                	pop    r15
 34c:	5d                   	pop    rbp
 34d:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 34
 *
 * - 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x113b: cmp    cl,0x5 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    cl,0x5]
 * - 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rsi+0x1f],0x6]
 * - 0x1146: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1147: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1149: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1154: lea    r9,[rip+0xea5] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xea5]]
 * - 0x115b: lea    r10,[rip+0xed2] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xed2]]
 * - 0x1162: lea    r11,[rip+0xeff] [warning-unmapped: LEA operands are not representable]
 * - 0x1170: xor    eax,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x11a5: movzx  ebp,BYTE PTR [rcx] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11ad: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11af: test   bpl,bpl [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11b2: jns    1172 <packet_toeplitz_rss_hash_xdp+0x72> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11b6: mov    ebp,DWORD PTR [r10+rdx*4] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [r10+rdx*4]]
 * - 0x11ba: or     ebp,DWORD PTR [r9+rdx*4] [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11c0: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11c2: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11c4: mov    r14d,DWORD PTR [r11+rdx*4] [warning-unmapped: memory base r11 is not in the BPF JIT register file]
 * - 0x11d1: or     ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x11e2: movzx  r9d,BYTE PTR [rsi+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11e7: movzx  r10d,BYTE PTR [rsi+0x2d] [warning-reg-remap: direct memory load via x86 kinsn selector; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11ec: mov    r11,rax [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rax]
 * - 0x11ef: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11fc: or     rdi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x120a: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x120e: or     r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1211: shl    r10,0x20 [warning-reg-remap: ALU imm operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1215: or     rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1218: or     rdx,r10 [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x123c: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x123d: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x123f: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> [bpf-branch: lowered cmp    rsi,rcx + jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_2, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -6),
    /* 0x1118: lea    rdx,[rsi+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111c: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x111f: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -11),
    /* 0x1121: movzx  ecx,WORD PTR [rsi+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1125: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x1129: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x112c: cmp    ecx,0x800 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1132: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    ecx,0x800 + jne    110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -20, 2048),
    /* 0x1134: movzx  ecx,BYTE PTR [rsi+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1138: and    cl,0xf [exact-kinsn: andb imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_4, 15, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x113b: cmp    cl,0x5 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    cl,0x5] */
    /* 0x113e: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    cl,0x5 + jne    110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -25, 5),
    /* 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rsi+0x1f],0x6] */
    /* 0x1144: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [bpf-branch: lowered cmp    BYTE PTR [rsi+0x1f],0x6 + jne    110e <packet_toeplitz_rss_hash_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_2, 31),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -27, 6),
    /* 0x1146: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1147: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1149: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x114a: lea    rdi,[rsi+0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114e: lea    r8,[rsi+0x22] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 34), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1152: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1154: lea    r9,[rip+0xea5] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xea5]] */
    /* 0x115b: lea    r10,[rip+0xed2] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xed2]] */
    /* 0x1162: lea    r11,[rip+0xeff] [warning-unmapped: LEA operands are not representable] */
    /* 0x1169: xor    ebx,ebx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_6, 0, 0, 0),
    /* 0x116b: jmp    1179 <packet_toeplitz_rss_hash_xdp+0x79> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 4, 0),
    /* 0x116d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1170: xor    eax,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x1172: inc    ebx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_6, 0, 0, 1),
    /* 0x1174: cmp    ebx,0x68 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 104), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1177: je     11d6 <packet_toeplitz_rss_hash_xdp+0xd6> [bpf-branch: lowered cmp    ebx,0x68 + je     11d6 <packet_toeplitz_rss_hash_xdp+0xd6> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 29, 104),
    /* 0x1179: mov    edx,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_6, 0, 0),
    /* 0x117b: shr    edx,0x3 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_3, 0, 0, 3),
    /* 0x117e: cmp    ebx,0x1f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 31), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1181: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [bpf-branch: lowered cmp    ebx,0x1f + jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_K, BPF_REG_6, 0, 11, 31),
    /* 0x1183: cmp    ebx,0x3f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 63), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1186: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [bpf-branch: lowered cmp    ebx,0x3f + jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_K, BPF_REG_6, 0, 8, 63),
    /* 0x1188: cmp    ebx,0x4f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 79), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x118b: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [bpf-branch: lowered cmp    ebx,0x4f + jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_K, BPF_REG_6, 0, 5, 79),
    /* 0x118d: mov    rcx,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1190: cmp    ebx,0x5f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 95), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1193: ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> [bpf-branch: lowered cmp    ebx,0x5f + ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_6, 0, 2, 95),
    /* 0x1195: data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    ecx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_3, 0, 0),
    /* 0x11a2: add    rcx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_4, BPF_REG_5, 0, 0),
    /* 0x11a5: movzx  ebp,BYTE PTR [rcx] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11a8: mov    ecx,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_6, 0, 0),
    /* 0x11aa: and    ecx,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11ad: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11af: test   bpl,bpl [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11b2: jns    1172 <packet_toeplitz_rss_hash_xdp+0x72> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11b4: mov    edx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_3, 0, 0),
    /* 0x11b6: mov    ebp,DWORD PTR [r10+rdx*4] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [r10+rdx*4]] */
    /* 0x11ba: or     ebp,DWORD PTR [r9+rdx*4] [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11be: test   ecx,ecx [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_TESTL_RR),
    /* 0x11c0: je     1170 <packet_toeplitz_rss_hash_xdp+0x70> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11c2: shl    ebp,cl [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11c4: mov    r14d,DWORD PTR [r11+rdx*4] [warning-unmapped: memory base r11 is not in the BPF JIT register file] */
    /* 0x11c8: mov    dl,0x8 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_3, 8),
    /* 0x11ca: sub    dl,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x11cc: mov    ecx,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_3, 0, 0),
    /* 0x11ce: shr    r14d,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x11d1: or     ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x11d4: jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -33, 0),
    /* 0x11d6: mov    edx,DWORD PTR [rsi+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 38), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11d9: movzx  ecx,BYTE PTR [rsi+0x2a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 42), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11dd: movzx  r8d,BYTE PTR [rsi+0x2b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_2, 43), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e2: movzx  r9d,BYTE PTR [rsi+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, 44), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e7: movzx  r10d,BYTE PTR [rsi+0x2d] [warning-reg-remap: direct memory load via x86 kinsn selector; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_2, 45), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ec: mov    r11,rax [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rax] */
    /* 0x11ef: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11f3: xor    edx,DWORD PTR [rsi+0x22] [exact-kinsn: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 34, BPF_REG_6, 0), MICRO_HANDCRAFT_BPF_X86_XORL_MEM),
    /* 0x11f6: bswap  edx [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11f8: mov    edi,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x11fa: xor    edi,eax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x11fc: or     rdi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x11ff: shl    rcx,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 56),
    /* 0x1203: shl    r8,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 48),
    /* 0x1207: or     r8,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_4, 0, 0),
    /* 0x120a: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 40),
    /* 0x120e: or     r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1211: shl    r10,0x20 [warning-reg-remap: ALU imm operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_7, 0, 0, 32),
    /* 0x1215: or     rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x1218: or     rdx,r10 [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_7, 0, 0),
    /* 0x121b: and    eax,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x121e: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1221: mov    r8,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1224: shl    r8,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_5, BPF_REG_4, 0, 0),
    /* 0x1227: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1229: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x122b: shr    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x122e: or     rdx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x1231: xor    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1234: mov    QWORD PTR [rsi],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x1237: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x123c: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x123d: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x123f: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1240: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
