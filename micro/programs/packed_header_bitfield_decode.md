# packed_header_bitfield_decode

## Original C
```c
#include "common.h"

#define BITFIELD_EXTRACT_RECORDS 32U
#define BITFIELD_EXTRACT_RECORD_WORDS 2U
#define BITFIELD_EXTRACT_HEADER_SIZE 8U
#define BITFIELD_EXTRACT_RECORD_SIZE 16U
#define BITFIELD_EXTRACT_INPUT_SIZE \
    (BITFIELD_EXTRACT_HEADER_SIZE + BITFIELD_EXTRACT_RECORDS * BITFIELD_EXTRACT_RECORD_SIZE)

static __always_inline int
bench_packed_header_bitfield_decode(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BITFIELD_EXTRACT_HEADER_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0);
    u32 record_words = micro_read_u32_le(data, 4);
    if (record_count != BITFIELD_EXTRACT_RECORDS ||
        record_words != BITFIELD_EXTRACT_RECORD_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, BITFIELD_EXTRACT_HEADER_SIZE,
                         record_count * BITFIELD_EXTRACT_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 index = 0; index < BITFIELD_EXTRACT_RECORDS; index++) {
        u32 base = BITFIELD_EXTRACT_HEADER_SIZE + index * BITFIELD_EXTRACT_RECORD_SIZE;
        u64 word0 = micro_read_u64_le(data, base);
        u64 word1 = micro_read_u64_le(data, base + 8U);
        u32 lane0 = (u32)word0;
        u32 lane1 = (u32)(word1 >> 32U);

        u64 field0 = (word0 >> 0U) & 0x3FULL;
        u64 field1 = (word0 >> 6U) & 0x1FULL;
        u64 field2 = (word0 >> 11U) & 0x7FFULL;
        u64 field3 = (word0 >> 22U) & 0xFFULL;
        u64 field4 = (word0 >> 30U) & 0x3FFFULL;
        u64 field5 = (word0 >> 44U) & 0x3FFULL;
        u64 field6 = (word0 >> 54U) & 0x3FFULL;

        u64 field7 = (word1 >> 0U) & 0xFULL;
        u64 field8 = (word1 >> 4U) & 0xFFULL;
        u64 field9 = (word1 >> 12U) & 0xFFFULL;
        u64 field10 = (word1 >> 24U) & 0xFFFFULL;
        u64 field11 = (word1 >> 40U) & 0xFFFFFFULL;
        u64 field12 = (lane0 >> 9U) & 0x1FULL;
        u64 field13 = (lane1 >> 6U) & 0x7FULL;

        u64 sum0 = field0 + field1 + field2 + field3 + field4 + field5 + field6;
        u64 sum1 = field7 + field8 + field9 + field10 + field11 + field12 +
                   field13 + (u64)index;
        u64 mix0 = (field2 * 3U) ^ (field4 * 5U) ^ (field8 * 7U);
        u64 mix1 = (field6 * 11U) ^ (field10 * 13U) ^ (field11 * 9U) ^
                   (field12 * 17U) ^ (field13 * 19U);

        acc += sum0 ^ micro_rotl64(sum1, (field0 & 7U) + 1U);
        acc ^= mix0 + mix1;
        acc = micro_rotl64(acc + field4 + field11 + field12,
                           ((field6 ^ field11) & 15U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    packed_header_bitfield_decode_xdp,
    bench_packed_header_bitfield_decode,
    packed_header_bitfield_decode_input_value,
    BITFIELD_EXTRACT_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <packed_header_bitfield_decode_xdp>:
    1100:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ce             	cmp    rsi,rcx
    110c:	76 01                	jbe    110f <packed_header_bitfield_decode_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 56 08          	lea    rdx,[rsi+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <packed_header_bitfield_decode_xdp+0xe>
    1118:	48 8d 96 10 02 00 00 	lea    rdx,[rsi+0x210]
    111f:	48 39 ca             	cmp    rdx,rcx
    1122:	77 ea                	ja     110e <packed_header_bitfield_decode_xdp+0xe>
    1124:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
    1128:	75 e4                	jne    110e <packed_header_bitfield_decode_xdp+0xe>
    112a:	83 7e 0c 02          	cmp    DWORD PTR [rsi+0xc],0x2
    112e:	75 de                	jne    110e <packed_header_bitfield_decode_xdp+0xe>
    1130:	55                   	push   rbp
    1131:	41 57                	push   r15
    1133:	41 56                	push   r14
    1135:	41 55                	push   r13
    1137:	41 54                	push   r12
    1139:	53                   	push   rbx
    113a:	48 89 74 24 f0       	mov    QWORD PTR [rsp-0x10],rsi
    113f:	48 8d 7e 1f          	lea    rdi,[rsi+0x1f]
    1143:	48 bb 09 c9 bc f3 67 	movabs rbx,0x6a09e667f3bcc909
    114a:	e6 09 6a 
    114d:	31 c0                	xor    eax,eax
    114f:	48 89 44 24 e8       	mov    QWORD PTR [rsp-0x18],rax
    1154:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    115b:	00 00 00 00 00 
    1160:	48 89 5c 24 f8       	mov    QWORD PTR [rsp-0x8],rbx
    1165:	0f b6 5f f1          	movzx  ebx,BYTE PTR [rdi-0xf]
    1169:	44 0f b6 4f f2       	movzx  r9d,BYTE PTR [rdi-0xe]
    116e:	45 89 cd             	mov    r13d,r9d
    1171:	41 c1 e5 08          	shl    r13d,0x8
    1175:	0f b6 47 f3          	movzx  eax,BYTE PTR [rdi-0xd]
    1179:	c1 e0 10             	shl    eax,0x10
    117c:	44 0f b6 67 f4       	movzx  r12d,BYTE PTR [rdi-0xc]
    1181:	41 c1 e4 18          	shl    r12d,0x18
    1185:	41 09 c4             	or     r12d,eax
    1188:	44 0f b6 57 f5       	movzx  r10d,BYTE PTR [rdi-0xb]
    118d:	49 c1 e2 20          	shl    r10,0x20
    1191:	0f b6 6f f6          	movzx  ebp,BYTE PTR [rdi-0xa]
    1195:	48 c1 e5 28          	shl    rbp,0x28
    1199:	44 0f b6 5f f7       	movzx  r11d,BYTE PTR [rdi-0x9]
    119e:	49 c1 e3 30          	shl    r11,0x30
    11a2:	0f b6 47 fc          	movzx  eax,BYTE PTR [rdi-0x4]
    11a6:	c1 e0 18             	shl    eax,0x18
    11a9:	44 0f b6 7f fd       	movzx  r15d,BYTE PTR [rdi-0x3]
    11ae:	49 c1 e7 20          	shl    r15,0x20
    11b2:	0f b6 77 fe          	movzx  esi,BYTE PTR [rdi-0x2]
    11b6:	48 c1 e6 28          	shl    rsi,0x28
    11ba:	49 8d 0c 37          	lea    rcx,[r15+rsi*1]
    11be:	49 09 c7             	or     r15,rax
    11c1:	0f b6 47 ff          	movzx  eax,BYTE PTR [rdi-0x1]
    11c5:	48 c1 e0 30          	shl    rax,0x30
    11c9:	0f b6 17             	movzx  edx,BYTE PTR [rdi]
    11cc:	48 c1 e2 38          	shl    rdx,0x38
    11d0:	48 09 c2             	or     rdx,rax
    11d3:	44 0f b6 77 f8       	movzx  r14d,BYTE PTR [rdi-0x8]
    11d8:	49 c1 e6 38          	shl    r14,0x38
    11dc:	41 09 dd             	or     r13d,ebx
    11df:	49 09 ea             	or     r10,rbp
    11e2:	4d 09 de             	or     r14,r11
    11e5:	49 09 eb             	or     r11,rbp
    11e8:	43 8d 2c 2c          	lea    ebp,[r12+r13*1]
    11ec:	48 09 f2             	or     rdx,rsi
    11ef:	89 d8                	mov    eax,ebx
    11f1:	83 e0 3f             	and    eax,0x3f
    11f4:	41 c1 ed 06          	shr    r13d,0x6
    11f8:	41 83 e5 1f          	and    r13d,0x1f
    11fc:	49 c1 ee 36          	shr    r14,0x36
    1200:	4c 01 f0             	add    rax,r14
    1203:	4c 01 e8             	add    rax,r13
    1206:	44 0f b6 6f f9       	movzx  r13d,BYTE PTR [rdi-0x7]
    120b:	49 09 ea             	or     r10,rbp
    120e:	c1 ed 0b             	shr    ebp,0xb
    1211:	81 e5 ff 07 00 00    	and    ebp,0x7ff
    1217:	41 c1 ec 16          	shr    r12d,0x16
    121b:	41 0f b6 f4          	movzx  esi,r12b
    121f:	48 01 e8             	add    rax,rbp
    1222:	48 01 f0             	add    rax,rsi
    1225:	0f b6 77 fa          	movzx  esi,BYTE PTR [rdi-0x6]
    1229:	c1 e6 08             	shl    esi,0x8
    122c:	49 c1 ea 1e          	shr    r10,0x1e
    1230:	41 81 e2 ff 3f 00 00 	and    r10d,0x3fff
    1237:	49 c1 eb 2c          	shr    r11,0x2c
    123b:	41 81 e3 ff 03 00 00 	and    r11d,0x3ff
    1242:	4d 01 d3             	add    r11,r10
    1245:	49 01 c3             	add    r11,rax
    1248:	0f b6 47 fb          	movzx  eax,BYTE PTR [rdi-0x5]
    124c:	c1 e0 10             	shl    eax,0x10
    124f:	09 f0                	or     eax,esi
    1251:	44 09 ee             	or     esi,r13d
    1254:	45 89 ec             	mov    r12d,r13d
    1257:	41 83 e4 0f          	and    r12d,0xf
    125b:	49 c1 ef 18          	shr    r15,0x18
    125f:	48 c1 ea 28          	shr    rdx,0x28
    1263:	41 d1 e9             	shr    r9d,1
    1266:	41 83 e1 1f          	and    r9d,0x1f
    126a:	48 c1 e9 26          	shr    rcx,0x26
    126e:	83 e1 7f             	and    ecx,0x7f
    1271:	4d 01 fc             	add    r12,r15
    1274:	49 01 d4             	add    r12,rdx
    1277:	c1 e8 0c             	shr    eax,0xc
    127a:	48 01 c8             	add    rax,rcx
    127d:	4c 01 e0             	add    rax,r12
    1280:	c1 ee 04             	shr    esi,0x4
    1283:	44 0f b6 ee          	movzx  r13d,sil
    1287:	4b 8d 34 29          	lea    rsi,[r9+r13*1]
    128b:	4c 8b 44 24 e8       	mov    r8,QWORD PTR [rsp-0x18]
    1290:	4c 01 c6             	add    rsi,r8
    1293:	48 01 c6             	add    rsi,rax
    1296:	48 8d 04 6d 00 00 00 	lea    rax,[rbp*2+0x0]
    129d:	00 
    129e:	48 01 e8             	add    rax,rbp
    12a1:	4e 8d 24 ed 00 00 00 	lea    r12,[r13*8+0x0]
    12a8:	00 
    12a9:	4d 29 ec             	sub    r12,r13
    12ac:	4f 8d 2c 92          	lea    r13,[r10+r10*4]
    12b0:	49 31 c4             	xor    r12,rax
    12b3:	4d 31 ec             	xor    r12,r13
    12b6:	4b 8d 04 b6          	lea    rax,[r14+r14*4]
    12ba:	49 8d 04 46          	lea    rax,[r14+rax*2]
    12be:	4f 8d 2c 7f          	lea    r13,[r15+r15*2]
    12c2:	4f 8d 3c af          	lea    r15,[r15+r13*4]
    12c6:	4c 8d 2c d2          	lea    r13,[rdx+rdx*8]
    12ca:	4d 31 fd             	xor    r13,r15
    12cd:	45 89 cf             	mov    r15d,r9d
    12d0:	41 c1 e7 04          	shl    r15d,0x4
    12d4:	4d 01 cf             	add    r15,r9
    12d7:	49 31 c7             	xor    r15,rax
    12da:	4d 31 ef             	xor    r15,r13
    12dd:	48 8d 04 c9          	lea    rax,[rcx+rcx*8]
    12e1:	48 8d 04 41          	lea    rax,[rcx+rax*2]
    12e5:	4c 31 f8             	xor    rax,r15
    12e8:	80 e3 07             	and    bl,0x7
    12eb:	8d 4b 01             	lea    ecx,[rbx+0x1]
    12ee:	49 89 f7             	mov    r15,rsi
    12f1:	49 d3 e7             	shl    r15,cl
    12f4:	f6 d3                	not    bl
    12f6:	89 d9                	mov    ecx,ebx
    12f8:	48 d3 ee             	shr    rsi,cl
    12fb:	4c 01 e0             	add    rax,r12
    12fe:	4c 09 fe             	or     rsi,r15
    1301:	4c 31 de             	xor    rsi,r11
    1304:	48 03 74 24 f8       	add    rsi,QWORD PTR [rsp-0x8]
    1309:	48 31 c6             	xor    rsi,rax
    130c:	4a 8d 1c 0a          	lea    rbx,[rdx+r9*1]
    1310:	4c 01 d3             	add    rbx,r10
    1313:	48 01 f3             	add    rbx,rsi
    1316:	44 31 f2             	xor    edx,r14d
    1319:	80 e2 0f             	and    dl,0xf
    131c:	8d 4a 01             	lea    ecx,[rdx+0x1]
    131f:	48 89 d8             	mov    rax,rbx
    1322:	48 d3 e0             	shl    rax,cl
    1325:	f6 d2                	not    dl
    1327:	89 d1                	mov    ecx,edx
    1329:	48 d3 eb             	shr    rbx,cl
    132c:	48 09 c3             	or     rbx,rax
    132f:	49 ff c0             	inc    r8
    1332:	48 83 c7 10          	add    rdi,0x10
    1336:	4c 89 c1             	mov    rcx,r8
    1339:	4c 89 44 24 e8       	mov    QWORD PTR [rsp-0x18],r8
    133e:	49 83 f8 20          	cmp    r8,0x20
    1342:	0f 85 18 fe ff ff    	jne    1160 <packed_header_bitfield_decode_xdp+0x60>
    1348:	48 8b 54 24 f0       	mov    rdx,QWORD PTR [rsp-0x10]
    134d:	88 1a                	mov    BYTE PTR [rdx],bl
    134f:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
    1352:	89 c1                	mov    ecx,eax
    1354:	c1 e9 10             	shr    ecx,0x10
    1357:	88 4a 02             	mov    BYTE PTR [rdx+0x2],cl
    135a:	89 c1                	mov    ecx,eax
    135c:	c1 e9 18             	shr    ecx,0x18
    135f:	88 4a 03             	mov    BYTE PTR [rdx+0x3],cl
    1362:	48 89 c1             	mov    rcx,rax
    1365:	48 c1 e9 20          	shr    rcx,0x20
    1369:	88 4a 04             	mov    BYTE PTR [rdx+0x4],cl
    136c:	48 89 c1             	mov    rcx,rax
    136f:	48 c1 e9 28          	shr    rcx,0x28
    1373:	88 4a 05             	mov    BYTE PTR [rdx+0x5],cl
    1376:	48 89 c1             	mov    rcx,rax
    1379:	48 c1 e9 30          	shr    rcx,0x30
    137d:	88 4a 06             	mov    BYTE PTR [rdx+0x6],cl
    1380:	48 c1 e8 38          	shr    rax,0x38
    1384:	88 42 07             	mov    BYTE PTR [rdx+0x7],al
    1387:	b8 02 00 00 00       	mov    eax,0x2
    138c:	5b                   	pop    rbx
    138d:	41 5c                	pop    r12
    138f:	41 5d                	pop    r13
    1391:	41 5e                	pop    r14
    1393:	41 5f                	pop    r15
    1395:	5d                   	pop    rbp
    1396:	c3                   	ret

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
   c:	48 81 ec 80 00 00 00 	sub    rsp,0x80
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 5f 00          	mov    rbx,QWORD PTR [rdi+0x0]
  24:	48 39 f3             	cmp    rbx,rsi
  27:	0f 87 be 03 00 00    	ja     0x3eb
  2d:	48 89 df             	mov    rdi,rbx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 ae 03 00 00    	ja     0x3eb
  3d:	48 89 df             	mov    rdi,rbx
  40:	48 81 c7 10 02 00 00 	add    rdi,0x210
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 9b 03 00 00    	ja     0x3eb
  50:	48 0f b6 7b 09       	movzx  rdi,BYTE PTR [rbx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 73 08       	movzx  rsi,BYTE PTR [rbx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 73 0a       	movzx  rsi,BYTE PTR [rbx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 73 0b       	movzx  rsi,BYTE PTR [rbx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 83 ff 20          	cmp    rdi,0x20
  85:	0f 85 60 03 00 00    	jne    0x3eb
  8b:	48 0f b6 7b 0d       	movzx  rdi,BYTE PTR [rbx+0xd]
  90:	48 c1 e7 08          	shl    rdi,0x8
  94:	48 0f b6 73 0c       	movzx  rsi,BYTE PTR [rbx+0xc]
  99:	48 09 f7             	or     rdi,rsi
  9c:	48 0f b6 73 0e       	movzx  rsi,BYTE PTR [rbx+0xe]
  a1:	48 c1 e6 10          	shl    rsi,0x10
  a5:	48 09 f7             	or     rdi,rsi
  a8:	48 0f b6 73 0f       	movzx  rsi,BYTE PTR [rbx+0xf]
  ad:	48 c1 e6 18          	shl    rsi,0x18
  b1:	48 09 f7             	or     rdi,rsi
  b4:	48 c1 e7 20          	shl    rdi,0x20
  b8:	48 c1 ef 20          	shr    rdi,0x20
  bc:	48 83 ff 02          	cmp    rdi,0x2
  c0:	0f 85 25 03 00 00    	jne    0x3eb
  c6:	48 b9 09 c9 bc f3 67 	movabs rcx,0x6a09e667f3bcc909
  cd:	e6 09 6a 
  d0:	45 31 f6             	xor    r14d,r14d
  d3:	48 89 5d 80          	mov    QWORD PTR [rbp-0x80],rbx
  d7:	48 83 c3 1f          	add    rbx,0x1f
  db:	48 89 4d b8          	mov    QWORD PTR [rbp-0x48],rcx
  df:	4c 89 75 d0          	mov    QWORD PTR [rbp-0x30],r14
  e3:	48 0f b6 7b f8       	movzx  rdi,BYTE PTR [rbx-0x8]
  e8:	48 c1 e7 38          	shl    rdi,0x38
  ec:	48 0f b6 73 f7       	movzx  rsi,BYTE PTR [rbx-0x9]
  f1:	48 c1 e6 30          	shl    rsi,0x30
  f5:	48 09 fe             	or     rsi,rdi
  f8:	49 89 f0             	mov    r8,rsi
  fb:	48 0f b6 7b f6       	movzx  rdi,BYTE PTR [rbx-0xa]
 100:	48 c1 e7 28          	shl    rdi,0x28
 104:	48 0f b6 43 f5       	movzx  rax,BYTE PTR [rbx-0xb]
 109:	48 c1 e0 20          	shl    rax,0x20
 10d:	48 09 f8             	or     rax,rdi
 110:	48 0f b6 7b f4       	movzx  rdi,BYTE PTR [rbx-0xc]
 115:	48 c1 e7 18          	shl    rdi,0x18
 119:	48 0f b6 53 f3       	movzx  rdx,BYTE PTR [rbx-0xd]
 11e:	48 c1 e2 10          	shl    rdx,0x10
 122:	48 09 fa             	or     rdx,rdi
 125:	48 89 55 b0          	mov    QWORD PTR [rbp-0x50],rdx
 129:	48 0f b6 7b f1       	movzx  rdi,BYTE PTR [rbx-0xf]
 12e:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 132:	48 0f b6 73 f2       	movzx  rsi,BYTE PTR [rbx-0xe]
 137:	49 89 f6             	mov    r14,rsi
 13a:	49 c1 e6 08          	shl    r14,0x8
 13e:	49 09 fe             	or     r14,rdi
 141:	4c 09 f2             	or     rdx,r14
 144:	48 09 d0             	or     rax,rdx
 147:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
 14b:	49 09 c0             	or     r8,rax
 14e:	4c 89 45 c0          	mov    QWORD PTR [rbp-0x40],r8
 152:	48 d1 ee             	shr    rsi,1
 155:	48 83 e6 1f          	and    rsi,0x1f
 159:	48 89 75 c8          	mov    QWORD PTR [rbp-0x38],rsi
 15d:	4c 89 c7             	mov    rdi,r8
 160:	48 c1 ef 36          	shr    rdi,0x36
 164:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 168:	48 6b ff 0b          	imul   rdi,rdi,0xb
 16c:	49 89 f0             	mov    r8,rsi
 16f:	4d 6b c0 11          	imul   r8,r8,0x11
 173:	49 31 f8             	xor    r8,rdi
 176:	4d 89 c7             	mov    r15,r8
 179:	48 0f b6 73 00       	movzx  rsi,BYTE PTR [rbx+0x0]
 17e:	48 c1 e6 38          	shl    rsi,0x38
 182:	48 0f b6 7b ff       	movzx  rdi,BYTE PTR [rbx-0x1]
 187:	48 c1 e7 30          	shl    rdi,0x30
 18b:	48 09 f7             	or     rdi,rsi
 18e:	48 0f b6 73 fc       	movzx  rsi,BYTE PTR [rbx-0x4]
 193:	48 c1 e6 18          	shl    rsi,0x18
 197:	49 89 f0             	mov    r8,rsi
 19a:	4c 89 45 98          	mov    QWORD PTR [rbp-0x68],r8
 19e:	48 0f b6 4b fb       	movzx  rcx,BYTE PTR [rbx-0x5]
 1a3:	48 c1 e1 10          	shl    rcx,0x10
 1a7:	48 89 4d a0          	mov    QWORD PTR [rbp-0x60],rcx
 1ab:	48 0f b6 73 fa       	movzx  rsi,BYTE PTR [rbx-0x6]
 1b0:	48 c1 e6 08          	shl    rsi,0x8
 1b4:	48 89 75 a8          	mov    QWORD PTR [rbp-0x58],rsi
 1b8:	48 0f b6 43 f9       	movzx  rax,BYTE PTR [rbx-0x7]
 1bd:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
 1c1:	49 89 f5             	mov    r13,rsi
 1c4:	49 09 c5             	or     r13,rax
 1c7:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 1cb:	48 89 ce             	mov    rsi,rcx
 1ce:	4c 09 c6             	or     rsi,r8
 1d1:	4c 09 ee             	or     rsi,r13
 1d4:	48 0f b6 4b fe       	movzx  rcx,BYTE PTR [rbx-0x2]
 1d9:	48 c1 e1 28          	shl    rcx,0x28
 1dd:	48 89 4d 88          	mov    QWORD PTR [rbp-0x78],rcx
 1e1:	48 0f b6 43 fd       	movzx  rax,BYTE PTR [rbx-0x3]
 1e6:	48 c1 e0 20          	shl    rax,0x20
 1ea:	49 89 c0             	mov    r8,rax
 1ed:	49 09 c8             	or     r8,rcx
 1f0:	4c 89 c1             	mov    rcx,r8
 1f3:	48 09 f1             	or     rcx,rsi
 1f6:	49 89 fd             	mov    r13,rdi
 1f9:	49 09 cd             	or     r13,rcx
 1fc:	49 c1 ed 28          	shr    r13,0x28
 200:	4c 89 ee             	mov    rsi,r13
 203:	48 6b f6 09          	imul   rsi,rsi,0x9
 207:	49 31 f7             	xor    r15,rsi
 20a:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 20e:	4c 8b 7d d8          	mov    r15,QWORD PTR [rbp-0x28]
 212:	49 83 e7 3f          	and    r15,0x3f
 216:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 21a:	4c 01 fe             	add    rsi,r15
 21d:	49 c1 ee 06          	shr    r14,0x6
 221:	49 83 e6 1f          	and    r14,0x1f
 225:	4c 01 f6             	add    rsi,r14
 228:	48 c1 e9 18          	shr    rcx,0x18
 22c:	48 81 e1 ff ff 00 00 	and    rcx,0xffff
 233:	48 6b c9 0d          	imul   rcx,rcx,0xd
 237:	4c 8b 7d e8          	mov    r15,QWORD PTR [rbp-0x18]
 23b:	49 31 cf             	xor    r15,rcx
 23e:	4c 8b 75 f8          	mov    r14,QWORD PTR [rbp-0x8]
 242:	49 c1 ee 1e          	shr    r14,0x1e
 246:	49 81 e6 ff 3f 00 00 	and    r14,0x3fff
 24d:	4c 89 f1             	mov    rcx,r14
 250:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
 254:	48 c1 ea 0b          	shr    rdx,0xb
 258:	48 81 e2 ff 07 00 00 	and    rdx,0x7ff
 25f:	48 01 d6             	add    rsi,rdx
 262:	48 6b d2 03          	imul   rdx,rdx,0x3
 266:	48 6b c9 05          	imul   rcx,rcx,0x5
 26a:	48 31 ca             	xor    rdx,rcx
 26d:	48 8b 4d 88          	mov    rcx,QWORD PTR [rbp-0x78]
 271:	48 09 cf             	or     rdi,rcx
 274:	48 8b 4d b0          	mov    rcx,QWORD PTR [rbp-0x50]
 278:	48 c1 e9 16          	shr    rcx,0x16
 27c:	48 81 e1 ff 00 00 00 	and    rcx,0xff
 283:	48 01 ce             	add    rsi,rcx
 286:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
 28a:	48 c1 e9 04          	shr    rcx,0x4
 28e:	48 81 e1 ff 00 00 00 	and    rcx,0xff
 295:	48 89 4d f0          	mov    QWORD PTR [rbp-0x10],rcx
 299:	48 6b c9 07          	imul   rcx,rcx,0x7
 29d:	48 31 ca             	xor    rdx,rcx
 2a0:	49 c1 e8 26          	shr    r8,0x26
 2a4:	49 83 e0 7f          	and    r8,0x7f
 2a8:	4c 89 c1             	mov    rcx,r8
 2ab:	48 6b c9 13          	imul   rcx,rcx,0x13
 2af:	49 31 cf             	xor    r15,rcx
 2b2:	48 c1 ef 28          	shr    rdi,0x28
 2b6:	48 8b 4d 90          	mov    rcx,QWORD PTR [rbp-0x70]
 2ba:	48 83 e1 0f          	and    rcx,0xf
 2be:	48 01 cf             	add    rdi,rcx
 2c1:	48 8b 4d 98          	mov    rcx,QWORD PTR [rbp-0x68]
 2c5:	48 09 c8             	or     rax,rcx
 2c8:	48 c1 e8 18          	shr    rax,0x18
 2cc:	48 01 c7             	add    rdi,rax
 2cf:	48 8b 4d a0          	mov    rcx,QWORD PTR [rbp-0x60]
 2d3:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 2d7:	48 09 c1             	or     rcx,rax
 2da:	48 c1 e9 0c          	shr    rcx,0xc
 2de:	48 01 cf             	add    rdi,rcx
 2e1:	4c 01 c7             	add    rdi,r8
 2e4:	4c 8b 75 d0          	mov    r14,QWORD PTR [rbp-0x30]
 2e8:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
 2ec:	48 01 cf             	add    rdi,rcx
 2ef:	49 01 d7             	add    r15,rdx
 2f2:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 2f6:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
 2fa:	4c 01 fe             	add    rsi,r15
 2fd:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 301:	48 c1 ea 2c          	shr    rdx,0x2c
 305:	48 81 e2 ff 03 00 00 	and    rdx,0x3ff
 30c:	48 01 d6             	add    rsi,rdx
 30f:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
 313:	48 83 e2 07          	and    rdx,0x7
 317:	48 89 d1             	mov    rcx,rdx
 31a:	48 83 c1 01          	add    rcx,0x1
 31e:	48 83 f2 3f          	xor    rdx,0x3f
 322:	48 89 d0             	mov    rax,rdx
 325:	4c 8b 45 c8          	mov    r8,QWORD PTR [rbp-0x38]
 329:	4c 01 c7             	add    rdi,r8
 32c:	4c 89 f2             	mov    rdx,r14
 32f:	48 01 fa             	add    rdx,rdi
 332:	48 89 d7             	mov    rdi,rdx
 335:	c4 e2 fb f7 ff       	shrx   rdi,rdi,rax
 33a:	48 d3 e2             	shl    rdx,cl
 33d:	48 09 fa             	or     rdx,rdi
 340:	4c 89 ef             	mov    rdi,r13
 343:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
 347:	48 31 cf             	xor    rdi,rcx
 34a:	4d 01 c5             	add    r13,r8
 34d:	48 31 f2             	xor    rdx,rsi
 350:	4d 01 fd             	add    r13,r15
 353:	48 8b 75 b8          	mov    rsi,QWORD PTR [rbp-0x48]
 357:	48 01 f2             	add    rdx,rsi
 35a:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 35e:	48 31 f2             	xor    rdx,rsi
 361:	49 01 d5             	add    r13,rdx
 364:	48 83 e7 0f          	and    rdi,0xf
 368:	48 89 fe             	mov    rsi,rdi
 36b:	48 83 c6 01          	add    rsi,0x1
 36f:	48 83 f7 3f          	xor    rdi,0x3f
 373:	4c 89 ea             	mov    rdx,r13
 376:	c4 e2 c3 f7 d2       	shrx   rdx,rdx,rdi
 37b:	c4 42 c9 f7 ed       	shlx   r13,r13,rsi
 380:	48 83 c3 10          	add    rbx,0x10
 384:	4c 89 e9             	mov    rcx,r13
 387:	48 09 d1             	or     rcx,rdx
 38a:	49 83 c6 01          	add    r14,0x1
 38e:	49 83 fe 20          	cmp    r14,0x20
 392:	74 05                	je     0x399
 394:	e9 42 fd ff ff       	jmp    0xdb
 399:	4c 89 ef             	mov    rdi,r13
 39c:	48 c1 ef 38          	shr    rdi,0x38
 3a0:	48 8b 75 80          	mov    rsi,QWORD PTR [rbp-0x80]
 3a4:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3a8:	4c 89 ef             	mov    rdi,r13
 3ab:	48 c1 ef 30          	shr    rdi,0x30
 3af:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3b3:	4c 89 ef             	mov    rdi,r13
 3b6:	48 c1 ef 28          	shr    rdi,0x28
 3ba:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 3be:	4c 89 ef             	mov    rdi,r13
 3c1:	48 c1 ef 20          	shr    rdi,0x20
 3c5:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 3c9:	4c 89 ef             	mov    rdi,r13
 3cc:	48 c1 ef 18          	shr    rdi,0x18
 3d0:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 3d4:	49 c1 ed 10          	shr    r13,0x10
 3d8:	44 88 6e 02          	mov    BYTE PTR [rsi+0x2],r13b
 3dc:	88 4e 00             	mov    BYTE PTR [rsi+0x0],cl
 3df:	48 c1 e9 08          	shr    rcx,0x8
 3e3:	88 4e 01             	mov    BYTE PTR [rsi+0x1],cl
 3e6:	b8 02 00 00 00       	mov    eax,0x2
 3eb:	41 5f                	pop    r15
 3ed:	41 5e                	pop    r14
 3ef:	41 5d                	pop    r13
 3f1:	5b                   	pop    rbx
 3f2:	c9                   	leave
 3f3:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 37                	mov    esi,DWORD PTR [rdi]
   6:	8b 4f 04             	mov    ecx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 ce                	cmp    esi,ecx
   d:	0f 87 cd 02 00 00    	ja     0x2e0
  13:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  17:	48 39 ca             	cmp    rdx,rcx
  1a:	0f 87 c0 02 00 00    	ja     0x2e0
  20:	48 8d 96 10 02 00 00 	lea    rdx,[rsi+0x210]
  27:	48 39 ca             	cmp    rdx,rcx
  2a:	0f 87 b0 02 00 00    	ja     0x2e0
  30:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
  34:	0f 85 a7 02 00 00    	jne    0x2e1
  3a:	83 7e 0c 02          	cmp    DWORD PTR [rsi+0xc],0x2
  3e:	0f 85 9d 02 00 00    	jne    0x2e1
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 89 74 24 c8       	mov    QWORD PTR [rsp-0x38],rsi
  53:	4c 8d 66 1f          	lea    r12,[rsi+0x1f]
  57:	48 bb 09 c9 bc f3 67 	movabs rbx,0x6a09e667f3bcc909
  5e:	e6 09 6a 
  61:	45 31 db             	xor    r11d,r11d
  64:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  6b:	00 00 00 00 00 
  70:	48 89 5c 24 e8       	mov    QWORD PTR [rsp-0x18],rbx
  75:	4c 89 5c 24 f8       	mov    QWORD PTR [rsp-0x8],r11
  7a:	41 0f b6 7c 24 f8    	movzx  edi,BYTE PTR [r12-0x8]
  80:	48 c1 e7 38          	shl    rdi,0x38
  84:	41 0f b6 44 24 f7    	movzx  eax,BYTE PTR [r12-0x9]
  8a:	48 c1 e0 30          	shl    rax,0x30
  8e:	48 09 c7             	or     rdi,rax
  91:	45 0f b6 44 24 f6    	movzx  r8d,BYTE PTR [r12-0xa]
  97:	49 c1 e0 28          	shl    r8,0x28
  9b:	45 0f b6 7c 24 f5    	movzx  r15d,BYTE PTR [r12-0xb]
  a1:	49 c1 e7 20          	shl    r15,0x20
  a5:	4d 09 c7             	or     r15,r8
  a8:	41 0f b6 4c 24 f4    	movzx  ecx,BYTE PTR [r12-0xc]
  ae:	c1 e1 18             	shl    ecx,0x18
  b1:	41 0f b6 6c 24 f3    	movzx  ebp,BYTE PTR [r12-0xd]
  b7:	c1 e5 10             	shl    ebp,0x10
  ba:	09 cd                	or     ebp,ecx
  bc:	41 0f b6 4c 24 f2    	movzx  ecx,BYTE PTR [r12-0xe]
  c2:	41 89 c9             	mov    r9d,ecx
  c5:	49 09 c0             	or     r8,rax
  c8:	d1 e9                	shr    ecx,1
  ca:	83 e1 1f             	and    ecx,0x1f
  cd:	48 89 4c 24 f0       	mov    QWORD PTR [rsp-0x10],rcx
  d2:	48 c1 ef 36          	shr    rdi,0x36
  d6:	48 8d 04 bf          	lea    rax,[rdi+rdi*4]
  da:	48 8d 04 47          	lea    rax,[rdi+rax*2]
  de:	89 ca                	mov    edx,ecx
  e0:	c1 e2 04             	shl    edx,0x4
  e3:	48 01 ca             	add    rdx,rcx
  e6:	48 31 c2             	xor    rdx,rax
  e9:	48 89 54 24 e0       	mov    QWORD PTR [rsp-0x20],rdx
  ee:	41 0f b6 04 24       	movzx  eax,BYTE PTR [r12]
  f3:	48 c1 e0 38          	shl    rax,0x38
  f7:	41 0f b6 4c 24 ff    	movzx  ecx,BYTE PTR [r12-0x1]
  fd:	48 c1 e1 30          	shl    rcx,0x30
 101:	48 09 c1             	or     rcx,rax
 104:	41 0f b6 44 24 fc    	movzx  eax,BYTE PTR [r12-0x4]
 10a:	c1 e0 18             	shl    eax,0x18
 10d:	48 89 c2             	mov    rdx,rax
 110:	48 89 44 24 d8       	mov    QWORD PTR [rsp-0x28],rax
 115:	45 0f b6 5c 24 fb    	movzx  r11d,BYTE PTR [r12-0x5]
 11b:	41 c1 e3 10          	shl    r11d,0x10
 11f:	41 0f b6 44 24 fa    	movzx  eax,BYTE PTR [r12-0x6]
 125:	c1 e0 08             	shl    eax,0x8
 128:	41 09 c3             	or     r11d,eax
 12b:	45 0f b6 54 24 fe    	movzx  r10d,BYTE PTR [r12-0x2]
 131:	49 c1 e2 28          	shl    r10,0x28
 135:	45 0f b6 6c 24 fd    	movzx  r13d,BYTE PTR [r12-0x3]
 13b:	49 c1 e5 20          	shl    r13,0x20
 13f:	4b 8d 1c 2a          	lea    rbx,[r10+r13*1]
 143:	49 09 ca             	or     r10,rcx
 146:	89 d1                	mov    ecx,edx
 148:	44 09 d9             	or     ecx,r11d
 14b:	4c 09 e9             	or     rcx,r13
 14e:	48 c1 e9 18          	shr    rcx,0x18
 152:	48 8d 14 49          	lea    rdx,[rcx+rcx*2]
 156:	48 8d 14 91          	lea    rdx,[rcx+rdx*4]
 15a:	49 c1 ea 28          	shr    r10,0x28
 15e:	4b 8d 0c d2          	lea    rcx,[r10+r10*8]
 162:	48 31 ca             	xor    rdx,rcx
 165:	48 89 54 24 d0       	mov    QWORD PTR [rsp-0x30],rdx
 16a:	41 c1 e1 08          	shl    r9d,0x8
 16e:	41 0f b6 74 24 f1    	movzx  esi,BYTE PTR [r12-0xf]
 174:	41 09 f1             	or     r9d,esi
 177:	41 89 f6             	mov    r14d,esi
 17a:	41 83 e6 3f          	and    r14d,0x3f
 17e:	41 8d 0c 29          	lea    ecx,[r9+rbp*1]
 182:	c1 ed 16             	shr    ebp,0x16
 185:	40 0f b6 d5          	movzx  edx,bpl
 189:	4c 01 f2             	add    rdx,r14
 18c:	41 c1 e9 06          	shr    r9d,0x6
 190:	41 83 e1 1f          	and    r9d,0x1f
 194:	4c 01 ca             	add    rdx,r9
 197:	4e 8d 0c 39          	lea    r9,[rcx+r15*1]
 19b:	c1 e9 0b             	shr    ecx,0xb
 19e:	81 e1 ff 07 00 00    	and    ecx,0x7ff
 1a4:	41 0f b6 6c 24 f9    	movzx  ebp,BYTE PTR [r12-0x7]
 1aa:	09 e8                	or     eax,ebp
 1ac:	c1 e8 04             	shr    eax,0x4
 1af:	44 0f b6 f0          	movzx  r14d,al
 1b3:	4e 8d 3c f5 00 00 00 	lea    r15,[r14*8+0x0]
 1ba:	00 
 1bb:	4d 29 f7             	sub    r15,r14
 1be:	48 8d 04 49          	lea    rax,[rcx+rcx*2]
 1c2:	49 31 c7             	xor    r15,rax
 1c5:	49 c1 e9 1e          	shr    r9,0x1e
 1c9:	41 81 e1 ff 3f 00 00 	and    r9d,0x3fff
 1d0:	4b 8d 04 89          	lea    rax,[r9+r9*4]
 1d4:	49 31 c7             	xor    r15,rax
 1d7:	48 c1 eb 26          	shr    rbx,0x26
 1db:	83 e3 7f             	and    ebx,0x7f
 1de:	48 8d 04 db          	lea    rax,[rbx+rbx*8]
 1e2:	48 8d 04 43          	lea    rax,[rbx+rax*2]
 1e6:	48 33 44 24 e0       	xor    rax,QWORD PTR [rsp-0x20]
 1eb:	48 33 44 24 d0       	xor    rax,QWORD PTR [rsp-0x30]
 1f0:	4c 01 f8             	add    rax,r15
 1f3:	48 01 ca             	add    rdx,rcx
 1f6:	49 c1 e8 2c          	shr    r8,0x2c
 1fa:	41 81 e0 ff 03 00 00 	and    r8d,0x3ff
 201:	48 01 fa             	add    rdx,rdi
 204:	4d 01 c8             	add    r8,r9
 207:	49 01 d0             	add    r8,rdx
 20a:	4c 03 6c 24 d8       	add    r13,QWORD PTR [rsp-0x28]
 20f:	49 c1 ed 18          	shr    r13,0x18
 213:	41 c1 eb 0c          	shr    r11d,0xc
 217:	4d 01 eb             	add    r11,r13
 21a:	83 e5 0f             	and    ebp,0xf
 21d:	4d 01 d3             	add    r11,r10
 220:	49 01 eb             	add    r11,rbp
 223:	4c 01 f3             	add    rbx,r14
 226:	4c 01 db             	add    rbx,r11
 229:	4c 8b 5c 24 f8       	mov    r11,QWORD PTR [rsp-0x8]
 22e:	4c 8b 74 24 f0       	mov    r14,QWORD PTR [rsp-0x10]
 233:	4c 01 db             	add    rbx,r11
 236:	4c 01 f3             	add    rbx,r14
 239:	40 80 e6 07          	and    sil,0x7
 23d:	89 f1                	mov    ecx,esi
 23f:	f6 d1                	not    cl
 241:	c4 e2 f3 f7 cb       	shrx   rcx,rbx,rcx
 246:	40 fe c6             	inc    sil
 249:	c4 e2 c9 f7 d3       	shlx   rdx,rbx,rsi
 24e:	48 09 ca             	or     rdx,rcx
 251:	4c 31 c2             	xor    rdx,r8
 254:	48 03 54 24 e8       	add    rdx,QWORD PTR [rsp-0x18]
 259:	48 31 c2             	xor    rdx,rax
 25c:	44 31 d7             	xor    edi,r10d
 25f:	4d 01 f2             	add    r10,r14
 262:	4d 01 ca             	add    r10,r9
 265:	49 01 d2             	add    r10,rdx
 268:	40 80 e7 0f          	and    dil,0xf
 26c:	89 f8                	mov    eax,edi
 26e:	f6 d0                	not    al
 270:	c4 c2 fb f7 da       	shrx   rbx,r10,rax
 275:	40 fe c7             	inc    dil
 278:	c4 c2 c1 f7 c2       	shlx   rax,r10,rdi
 27d:	49 83 c4 10          	add    r12,0x10
 281:	48 09 c3             	or     rbx,rax
 284:	49 ff c3             	inc    r11
 287:	49 83 fb 20          	cmp    r11,0x20
 28b:	0f 85 df fd ff ff    	jne    0x70
 291:	48 89 c1             	mov    rcx,rax
 294:	48 c1 e9 38          	shr    rcx,0x38
 298:	48 8b 54 24 c8       	mov    rdx,QWORD PTR [rsp-0x38]
 29d:	88 4a 07             	mov    BYTE PTR [rdx+0x7],cl
 2a0:	48 89 c1             	mov    rcx,rax
 2a3:	48 c1 e9 30          	shr    rcx,0x30
 2a7:	88 4a 06             	mov    BYTE PTR [rdx+0x6],cl
 2aa:	48 89 c1             	mov    rcx,rax
 2ad:	48 c1 e9 28          	shr    rcx,0x28
 2b1:	88 4a 05             	mov    BYTE PTR [rdx+0x5],cl
 2b4:	48 89 c1             	mov    rcx,rax
 2b7:	48 c1 e9 20          	shr    rcx,0x20
 2bb:	88 4a 04             	mov    BYTE PTR [rdx+0x4],cl
 2be:	89 c1                	mov    ecx,eax
 2c0:	c1 e9 18             	shr    ecx,0x18
 2c3:	88 4a 03             	mov    BYTE PTR [rdx+0x3],cl
 2c6:	c1 e8 10             	shr    eax,0x10
 2c9:	88 42 02             	mov    BYTE PTR [rdx+0x2],al
 2cc:	88 1a                	mov    BYTE PTR [rdx],bl
 2ce:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
 2d1:	b8 02 00 00 00       	mov    eax,0x2
 2d6:	5b                   	pop    rbx
 2d7:	41 5c                	pop    r12
 2d9:	41 5d                	pop    r13
 2db:	41 5e                	pop    r14
 2dd:	41 5f                	pop    r15
 2df:	5d                   	pop    rbp
 2e0:	c3                   	ret
 2e1:	31 c0                	xor    eax,eax
 2e3:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
