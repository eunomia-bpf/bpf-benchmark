# tracee_http_method_prefix_detect

## Original C
```c
#include "common.h"

#define TRACEE_HTTP_METHOD_RECORDS 8U
#define TRACEE_HTTP_METHOD_RECORD_SIZE 16U
#define TRACEE_HTTP_METHOD_INPUT_SIZE \
    (8U + TRACEE_HTTP_METHOD_RECORDS * TRACEE_HTTP_METHOD_RECORD_SIZE)

static __always_inline int tracee_match3(const u8 *data, u32 base, u8 a, u8 b, u8 c)
{
    return data[base] == a && data[base + 1U] == b && data[base + 2U] == c;
}

static __always_inline int tracee_match4(const u8 *data, u32 base, u8 a, u8 b, u8 c, u8 d)
{
    return tracee_match3(data, base, a, b, c) && data[base + 3U] == d;
}

static __always_inline int tracee_match5(const u8 *data, u32 base, u8 a, u8 b, u8 c, u8 d, u8 e)
{
    return tracee_match4(data, base, a, b, c, d) && data[base + 4U] == e;
}

static __always_inline int tracee_match7(const u8 *data, u32 base, u8 a, u8 b, u8 c, u8 d, u8 e, u8 f, u8 g)
{
    return tracee_match5(data, base, a, b, c, d, e) &&
           data[base + 5U] == f && data[base + 6U] == g;
}

static __always_inline u32 tracee_http_method_code(const u8 *data, u32 base)
{
    if (tracee_match4(data, base, 'G', 'E', 'T', ' ')) {
        return 1U;
    }
    if (tracee_match5(data, base, 'P', 'O', 'S', 'T', ' ')) {
        return 2U;
    }
    if (tracee_match4(data, base, 'P', 'U', 'T', ' ')) {
        return 3U;
    }
    if (tracee_match7(data, base, 'D', 'E', 'L', 'E', 'T', 'E', ' ')) {
        return 4U;
    }
    if (tracee_match5(data, base, 'H', 'E', 'A', 'D', ' ')) {
        return 5U;
    }
    if (tracee_match5(data, base, 'H', 'T', 'T', 'P', '/')) {
        return 6U;
    }
    return 0U;
}

static __always_inline int
bench_tracee_http_method_prefix_detect(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TRACEE_HTTP_METHOD_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != TRACEE_HTTP_METHOD_RECORDS ||
        record_size != TRACEE_HTTP_METHOD_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0xA0761D6478BD642FULL;
    for (u32 index = 0; index < TRACEE_HTTP_METHOD_RECORDS; index++) {
        u32 base = 8U + index * TRACEE_HTTP_METHOD_RECORD_SIZE;
        u32 code = tracee_http_method_code(data, base);
        u32 first = micro_read_u32_le(data, base);

        acc += (u64)(code + 1U) * (u64)(index + 11U);
        acc ^= micro_rotl64(((u64)first << 8U) | code, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tracee_http_method_prefix_detect_xdp,
    bench_tracee_http_method_prefix_detect,
    tracee_http_method_prefix_detect_input_value,
    TRACEE_HTTP_METHOD_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <tracee_http_method_prefix_detect_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <tracee_http_method_prefix_detect_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <tracee_http_method_prefix_detect_xdp+0xe>
    1118:	48 8d b2 90 00 00 00 	lea    rsi,[rdx+0x90]
    111f:	48 39 ce             	cmp    rsi,rcx
    1122:	77 ea                	ja     110e <tracee_http_method_prefix_detect_xdp+0xe>
    1124:	83 7a 08 08          	cmp    DWORD PTR [rdx+0x8],0x8
    1128:	75 e4                	jne    110e <tracee_http_method_prefix_detect_xdp+0xe>
    112a:	83 7a 0c 10          	cmp    DWORD PTR [rdx+0xc],0x10
    112e:	75 de                	jne    110e <tracee_http_method_prefix_detect_xdp+0xe>
    1130:	41 57                	push   r15
    1132:	41 56                	push   r14
    1134:	53                   	push   rbx
    1135:	48 8d 42 16          	lea    rax,[rdx+0x16]
    1139:	48 bb 2f 64 bd 78 64 	movabs rbx,0xa0761d6478bd642f
    1140:	1d 76 a0 
    1143:	b9 01 00 00 00       	mov    ecx,0x1
    1148:	48 8d 35 b1 0e 00 00 	lea    rsi,[rip+0xeb1]        # 2000 <_fini+0xc98>
    114f:	90                   	nop
    1150:	48 89 df             	mov    rdi,rbx
    1153:	44 0f b6 40 fa       	movzx  r8d,BYTE PTR [rax-0x6]
    1158:	44 0f b6 48 fb       	movzx  r9d,BYTE PTR [rax-0x5]
    115d:	45 8d 58 bc          	lea    r11d,[r8-0x44]
    1161:	41 83 fb 0c          	cmp    r11d,0xc
    1165:	0f 87 55 01 00 00    	ja     12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    116b:	45 0f b6 d1          	movzx  r10d,r9b
    116f:	4e 63 1c 9e          	movsxd r11,DWORD PTR [rsi+r11*4]
    1173:	49 01 f3             	add    r11,rsi
    1176:	41 ff e3             	jmp    r11
    1179:	41 80 f9 45          	cmp    r9b,0x45
    117d:	0f 85 3d 01 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1183:	41 b1 45             	mov    r9b,0x45
    1186:	80 78 fc 4c          	cmp    BYTE PTR [rax-0x4],0x4c
    118a:	0f 85 30 01 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1190:	80 78 fd 45          	cmp    BYTE PTR [rax-0x3],0x45
    1194:	0f 85 26 01 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    119a:	80 78 fe 54          	cmp    BYTE PTR [rax-0x2],0x54
    119e:	0f 85 1c 01 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    11a4:	80 78 ff 45          	cmp    BYTE PTR [rax-0x1],0x45
    11a8:	0f 85 12 01 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    11ae:	b3 45                	mov    bl,0x45
    11b0:	80 38 20             	cmp    BYTE PTR [rax],0x20
    11b3:	0f 85 07 01 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    11b9:	41 ba 04 00 00 00    	mov    r10d,0x4
    11bf:	41 b1 4c             	mov    r9b,0x4c
    11c2:	41 b3 45             	mov    r11b,0x45
    11c5:	e9 05 01 00 00       	jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf>
    11ca:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    11d0:	41 83 fa 54          	cmp    r10d,0x54
    11d4:	0f 84 9b 00 00 00    	je     1275 <tracee_http_method_prefix_detect_xdp+0x175>
    11da:	41 83 fa 45          	cmp    r10d,0x45
    11de:	0f 85 dc 00 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    11e4:	41 b1 45             	mov    r9b,0x45
    11e7:	80 78 fc 41          	cmp    BYTE PTR [rax-0x4],0x41
    11eb:	0f 85 cf 00 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    11f1:	80 78 fd 44          	cmp    BYTE PTR [rax-0x3],0x44
    11f5:	0f 85 c5 00 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    11fb:	41 b3 45             	mov    r11b,0x45
    11fe:	80 78 fe 20          	cmp    BYTE PTR [rax-0x2],0x20
    1202:	0f 85 b8 00 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1208:	41 ba 05 00 00 00    	mov    r10d,0x5
    120e:	41 b1 41             	mov    r9b,0x41
    1211:	b3 44                	mov    bl,0x44
    1213:	e9 b7 00 00 00       	jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf>
    1218:	41 80 f9 45          	cmp    r9b,0x45
    121c:	0f 85 9e 00 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1222:	41 b1 45             	mov    r9b,0x45
    1225:	80 78 fc 54          	cmp    BYTE PTR [rax-0x4],0x54
    1229:	0f 85 91 00 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    122f:	41 b3 45             	mov    r11b,0x45
    1232:	80 78 fd 20          	cmp    BYTE PTR [rax-0x3],0x20
    1236:	0f 85 84 00 00 00    	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    123c:	41 ba 01 00 00 00    	mov    r10d,0x1
    1242:	eb 6b                	jmp    12af <tracee_http_method_prefix_detect_xdp+0x1af>
    1244:	41 83 fa 55          	cmp    r10d,0x55
    1248:	74 4d                	je     1297 <tracee_http_method_prefix_detect_xdp+0x197>
    124a:	41 83 fa 4f          	cmp    r10d,0x4f
    124e:	75 70                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1250:	41 b1 4f             	mov    r9b,0x4f
    1253:	80 78 fc 53          	cmp    BYTE PTR [rax-0x4],0x53
    1257:	75 67                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1259:	80 78 fd 54          	cmp    BYTE PTR [rax-0x3],0x54
    125d:	75 61                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    125f:	41 b3 4f             	mov    r11b,0x4f
    1262:	80 78 fe 20          	cmp    BYTE PTR [rax-0x2],0x20
    1266:	75 58                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1268:	41 ba 02 00 00 00    	mov    r10d,0x2
    126e:	41 b1 53             	mov    r9b,0x53
    1271:	b3 54                	mov    bl,0x54
    1273:	eb 5a                	jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf>
    1275:	41 b1 54             	mov    r9b,0x54
    1278:	80 78 fc 54          	cmp    BYTE PTR [rax-0x4],0x54
    127c:	75 42                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    127e:	80 78 fd 50          	cmp    BYTE PTR [rax-0x3],0x50
    1282:	75 3c                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    1284:	80 78 fe 2f          	cmp    BYTE PTR [rax-0x2],0x2f
    1288:	75 36                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    128a:	41 ba 06 00 00 00    	mov    r10d,0x6
    1290:	b3 50                	mov    bl,0x50
    1292:	41 b3 54             	mov    r11b,0x54
    1295:	eb 38                	jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf>
    1297:	41 b1 55             	mov    r9b,0x55
    129a:	80 78 fc 54          	cmp    BYTE PTR [rax-0x4],0x54
    129e:	75 20                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    12a0:	41 b3 55             	mov    r11b,0x55
    12a3:	80 78 fd 20          	cmp    BYTE PTR [rax-0x3],0x20
    12a7:	75 17                	jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0>
    12a9:	41 ba 03 00 00 00    	mov    r10d,0x3
    12af:	41 b1 54             	mov    r9b,0x54
    12b2:	b3 20                	mov    bl,0x20
    12b4:	eb 19                	jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf>
    12b6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    12bd:	00 00 00 
    12c0:	45 89 cb             	mov    r11d,r9d
    12c3:	44 0f b6 48 fc       	movzx  r9d,BYTE PTR [rax-0x4]
    12c8:	0f b6 58 fd          	movzx  ebx,BYTE PTR [rax-0x3]
    12cc:	45 31 d2             	xor    r10d,r10d
    12cf:	0f b6 db             	movzx  ebx,bl
    12d2:	45 8d 72 01          	lea    r14d,[r10+0x1]
    12d6:	4c 8d 79 0a          	lea    r15,[rcx+0xa]
    12da:	4d 0f af f7          	imul   r14,r15
    12de:	4c 01 f7             	add    rdi,r14
    12e1:	48 c1 e3 20          	shl    rbx,0x20
    12e5:	45 0f b6 c9          	movzx  r9d,r9b
    12e9:	41 c1 e1 18          	shl    r9d,0x18
    12ed:	45 0f b6 db          	movzx  r11d,r11b
    12f1:	41 c1 e3 10          	shl    r11d,0x10
    12f5:	41 c1 e0 08          	shl    r8d,0x8
    12f9:	45 09 d8             	or     r8d,r11d
    12fc:	45 09 c8             	or     r8d,r9d
    12ff:	49 09 d8             	or     r8,rbx
    1302:	44 89 d3             	mov    ebx,r10d
    1305:	4c 09 c3             	or     rbx,r8
    1308:	48 d3 e3             	shl    rbx,cl
    130b:	48 31 fb             	xor    rbx,rdi
    130e:	48 83 c0 10          	add    rax,0x10
    1312:	48 ff c1             	inc    rcx
    1315:	48 83 f9 09          	cmp    rcx,0x9
    1319:	0f 85 31 fe ff ff    	jne    1150 <tracee_http_method_prefix_detect_xdp+0x50>
    131f:	40 88 3a             	mov    BYTE PTR [rdx],dil
    1322:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
    1325:	89 d8                	mov    eax,ebx
    1327:	c1 e8 10             	shr    eax,0x10
    132a:	88 42 02             	mov    BYTE PTR [rdx+0x2],al
    132d:	89 d8                	mov    eax,ebx
    132f:	c1 e8 18             	shr    eax,0x18
    1332:	88 42 03             	mov    BYTE PTR [rdx+0x3],al
    1335:	48 89 d8             	mov    rax,rbx
    1338:	48 c1 e8 20          	shr    rax,0x20
    133c:	88 42 04             	mov    BYTE PTR [rdx+0x4],al
    133f:	48 89 d8             	mov    rax,rbx
    1342:	48 c1 e8 28          	shr    rax,0x28
    1346:	88 42 05             	mov    BYTE PTR [rdx+0x5],al
    1349:	48 89 d8             	mov    rax,rbx
    134c:	48 c1 e8 30          	shr    rax,0x30
    1350:	88 42 06             	mov    BYTE PTR [rdx+0x6],al
    1353:	48 c1 eb 38          	shr    rbx,0x38
    1357:	88 5a 07             	mov    BYTE PTR [rdx+0x7],bl
    135a:	b8 02 00 00 00       	mov    eax,0x2
    135f:	5b                   	pop    rbx
    1360:	41 5e                	pop    r14
    1362:	41 5f                	pop    r15
    1364:	c3                   	ret

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
  20:	0f 87 5b 03 00 00    	ja     0x381
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 4b 03 00 00    	ja     0x381
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 90 00 00 00 	add    rdx,0x90
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 38 03 00 00    	ja     0x381
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
  7a:	48 83 fe 08          	cmp    rsi,0x8
  7e:	0f 85 fd 02 00 00    	jne    0x381
  84:	48 0f b6 77 0d       	movzx  rsi,BYTE PTR [rdi+0xd]
  89:	48 c1 e6 08          	shl    rsi,0x8
  8d:	48 0f b6 57 0c       	movzx  rdx,BYTE PTR [rdi+0xc]
  92:	48 09 d6             	or     rsi,rdx
  95:	48 0f b6 57 0e       	movzx  rdx,BYTE PTR [rdi+0xe]
  9a:	48 c1 e2 10          	shl    rdx,0x10
  9e:	48 09 d6             	or     rsi,rdx
  a1:	48 0f b6 57 0f       	movzx  rdx,BYTE PTR [rdi+0xf]
  a6:	48 c1 e2 18          	shl    rdx,0x18
  aa:	48 09 d6             	or     rsi,rdx
  ad:	48 c1 e6 20          	shl    rsi,0x20
  b1:	48 c1 ee 20          	shr    rsi,0x20
  b5:	48 83 fe 10          	cmp    rsi,0x10
  b9:	0f 85 c2 02 00 00    	jne    0x381
  bf:	48 ba 2f 64 bd 78 64 	movabs rdx,0xa0761d6478bd642f
  c6:	1d 76 a0 
  c9:	be 01 00 00 00       	mov    esi,0x1
  ce:	48 89 f9             	mov    rcx,rdi
  d1:	48 83 c1 16          	add    rcx,0x16
  d5:	49 89 d0             	mov    r8,rdx
  d8:	48 0f b6 51 fb       	movzx  rdx,BYTE PTR [rcx-0x5]
  dd:	48 0f b6 41 fa       	movzx  rax,BYTE PTR [rcx-0x6]
  e2:	48 83 f8 47          	cmp    rax,0x47
  e6:	7f 58                	jg     0x140
  e8:	48 83 f8 44          	cmp    rax,0x44
  ec:	0f 84 bf 00 00 00    	je     0x1b1
  f2:	48 83 f8 47          	cmp    rax,0x47
  f6:	74 05                	je     0xfd
  f8:	e9 da 01 00 00       	jmp    0x2d7
  fd:	48 83 fa 45          	cmp    rdx,0x45
 101:	0f 85 d0 01 00 00    	jne    0x2d7
 107:	ba 45 00 00 00       	mov    edx,0x45
 10c:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 111:	48 83 fb 54          	cmp    rbx,0x54
 115:	0f 85 bc 01 00 00    	jne    0x2d7
 11b:	bb 01 00 00 00       	mov    ebx,0x1
 120:	41 be 54 00 00 00    	mov    r14d,0x54
 126:	41 bd 20 00 00 00    	mov    r13d,0x20
 12c:	4c 0f b6 79 fd       	movzx  r15,BYTE PTR [rcx-0x3]
 131:	49 83 ff 20          	cmp    r15,0x20
 135:	0f 84 a8 01 00 00    	je     0x2e3
 13b:	e9 97 01 00 00       	jmp    0x2d7
 140:	48 83 f8 48          	cmp    rax,0x48
 144:	0f 84 d7 00 00 00    	je     0x221
 14a:	48 83 f8 50          	cmp    rax,0x50
 14e:	74 05                	je     0x155
 150:	e9 82 01 00 00       	jmp    0x2d7
 155:	48 83 fa 55          	cmp    rdx,0x55
 159:	0f 84 13 01 00 00    	je     0x272
 15f:	48 83 fa 4f          	cmp    rdx,0x4f
 163:	0f 85 6e 01 00 00    	jne    0x2d7
 169:	ba 4f 00 00 00       	mov    edx,0x4f
 16e:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 173:	48 83 fb 53          	cmp    rbx,0x53
 177:	0f 85 5a 01 00 00    	jne    0x2d7
 17d:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 182:	48 83 fb 54          	cmp    rbx,0x54
 186:	0f 85 4b 01 00 00    	jne    0x2d7
 18c:	bb 02 00 00 00       	mov    ebx,0x2
 191:	41 be 53 00 00 00    	mov    r14d,0x53
 197:	41 bd 54 00 00 00    	mov    r13d,0x54
 19d:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 1a2:	49 83 ff 20          	cmp    r15,0x20
 1a6:	0f 84 37 01 00 00    	je     0x2e3
 1ac:	e9 26 01 00 00       	jmp    0x2d7
 1b1:	48 83 fa 45          	cmp    rdx,0x45
 1b5:	0f 85 1c 01 00 00    	jne    0x2d7
 1bb:	ba 45 00 00 00       	mov    edx,0x45
 1c0:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 1c5:	48 83 fb 4c          	cmp    rbx,0x4c
 1c9:	0f 85 08 01 00 00    	jne    0x2d7
 1cf:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 1d4:	48 83 fb 45          	cmp    rbx,0x45
 1d8:	0f 85 f9 00 00 00    	jne    0x2d7
 1de:	48 0f b6 59 fe       	movzx  rbx,BYTE PTR [rcx-0x2]
 1e3:	48 83 fb 54          	cmp    rbx,0x54
 1e7:	0f 85 ea 00 00 00    	jne    0x2d7
 1ed:	48 0f b6 59 ff       	movzx  rbx,BYTE PTR [rcx-0x1]
 1f2:	48 83 fb 45          	cmp    rbx,0x45
 1f6:	0f 85 db 00 00 00    	jne    0x2d7
 1fc:	bb 04 00 00 00       	mov    ebx,0x4
 201:	41 be 4c 00 00 00    	mov    r14d,0x4c
 207:	4c 0f b6 79 00       	movzx  r15,BYTE PTR [rcx+0x0]
 20c:	41 bd 45 00 00 00    	mov    r13d,0x45
 212:	49 83 ff 20          	cmp    r15,0x20
 216:	0f 84 c7 00 00 00    	je     0x2e3
 21c:	e9 b6 00 00 00       	jmp    0x2d7
 221:	48 83 fa 54          	cmp    rdx,0x54
 225:	74 79                	je     0x2a0
 227:	48 83 fa 45          	cmp    rdx,0x45
 22b:	0f 85 a6 00 00 00    	jne    0x2d7
 231:	ba 45 00 00 00       	mov    edx,0x45
 236:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 23b:	48 83 fb 41          	cmp    rbx,0x41
 23f:	0f 85 92 00 00 00    	jne    0x2d7
 245:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 24a:	48 83 fb 44          	cmp    rbx,0x44
 24e:	0f 85 83 00 00 00    	jne    0x2d7
 254:	bb 05 00 00 00       	mov    ebx,0x5
 259:	41 be 41 00 00 00    	mov    r14d,0x41
 25f:	41 bd 44 00 00 00    	mov    r13d,0x44
 265:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 26a:	49 83 ff 20          	cmp    r15,0x20
 26e:	74 73                	je     0x2e3
 270:	eb 65                	jmp    0x2d7
 272:	ba 55 00 00 00       	mov    edx,0x55
 277:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 27c:	48 83 fb 54          	cmp    rbx,0x54
 280:	75 55                	jne    0x2d7
 282:	bb 03 00 00 00       	mov    ebx,0x3
 287:	41 be 54 00 00 00    	mov    r14d,0x54
 28d:	41 bd 20 00 00 00    	mov    r13d,0x20
 293:	4c 0f b6 79 fd       	movzx  r15,BYTE PTR [rcx-0x3]
 298:	49 83 ff 20          	cmp    r15,0x20
 29c:	74 45                	je     0x2e3
 29e:	eb 37                	jmp    0x2d7
 2a0:	ba 54 00 00 00       	mov    edx,0x54
 2a5:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 2aa:	48 83 fb 54          	cmp    rbx,0x54
 2ae:	75 27                	jne    0x2d7
 2b0:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 2b5:	48 83 fb 50          	cmp    rbx,0x50
 2b9:	75 1c                	jne    0x2d7
 2bb:	bb 06 00 00 00       	mov    ebx,0x6
 2c0:	41 bd 50 00 00 00    	mov    r13d,0x50
 2c6:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 2cb:	41 be 54 00 00 00    	mov    r14d,0x54
 2d1:	49 83 ff 2f          	cmp    r15,0x2f
 2d5:	74 0c                	je     0x2e3
 2d7:	31 db                	xor    ebx,ebx
 2d9:	4c 0f b6 69 fd       	movzx  r13,BYTE PTR [rcx-0x3]
 2de:	4c 0f b6 71 fc       	movzx  r14,BYTE PTR [rcx-0x4]
 2e3:	48 c1 e0 08          	shl    rax,0x8
 2e7:	48 c1 e2 10          	shl    rdx,0x10
 2eb:	48 09 c2             	or     rdx,rax
 2ee:	48 89 d8             	mov    rax,rbx
 2f1:	48 83 c0 01          	add    rax,0x1
 2f5:	49 89 f7             	mov    r15,rsi
 2f8:	49 83 c7 0a          	add    r15,0xa
 2fc:	4c 0f af f8          	imul   r15,rax
 300:	4d 01 f8             	add    r8,r15
 303:	49 c1 e6 18          	shl    r14,0x18
 307:	4c 09 f2             	or     rdx,r14
 30a:	49 c1 e5 20          	shl    r13,0x20
 30e:	4c 09 ea             	or     rdx,r13
 311:	48 09 da             	or     rdx,rbx
 314:	48 83 c1 10          	add    rcx,0x10
 318:	c4 e2 c9 f7 d2       	shlx   rdx,rdx,rsi
 31d:	4c 31 c2             	xor    rdx,r8
 320:	48 83 c6 01          	add    rsi,0x1
 324:	48 83 fe 09          	cmp    rsi,0x9
 328:	74 05                	je     0x32f
 32a:	e9 a6 fd ff ff       	jmp    0xd5
 32f:	44 88 47 00          	mov    BYTE PTR [rdi+0x0],r8b
 333:	48 89 d6             	mov    rsi,rdx
 336:	48 c1 ee 38          	shr    rsi,0x38
 33a:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 33e:	48 89 d6             	mov    rsi,rdx
 341:	48 c1 ee 30          	shr    rsi,0x30
 345:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 349:	48 89 d6             	mov    rsi,rdx
 34c:	48 c1 ee 28          	shr    rsi,0x28
 350:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 354:	48 89 d6             	mov    rsi,rdx
 357:	48 c1 ee 20          	shr    rsi,0x20
 35b:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 35f:	48 89 d6             	mov    rsi,rdx
 362:	48 c1 ee 18          	shr    rsi,0x18
 366:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 36a:	48 89 d6             	mov    rsi,rdx
 36d:	48 c1 ee 10          	shr    rsi,0x10
 371:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 375:	48 c1 ea 08          	shr    rdx,0x8
 379:	88 57 01             	mov    BYTE PTR [rdi+0x1],dl
 37c:	b8 02 00 00 00       	mov    eax,0x2
 381:	41 5f                	pop    r15
 383:	41 5e                	pop    r14
 385:	41 5d                	pop    r13
 387:	5b                   	pop    rbx
 388:	c9                   	leave
 389:	c3                   	ret
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
   d:	0f 87 b5 02 00 00    	ja     0x2c8
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 a8 02 00 00    	ja     0x2c8
  20:	48 8d b1 90 00 00 00 	lea    rsi,[rcx+0x90]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 98 02 00 00    	ja     0x2c8
  30:	83 79 08 08          	cmp    DWORD PTR [rcx+0x8],0x8
  34:	0f 85 8f 02 00 00    	jne    0x2c9
  3a:	83 79 0c 10          	cmp    DWORD PTR [rcx+0xc],0x10
  3e:	0f 85 85 02 00 00    	jne    0x2c9
  44:	53                   	push   rbx
  45:	48 8d 51 16          	lea    rdx,[rcx+0x16]
  49:	48 b8 2f 64 bd 78 64 	movabs rax,0xa0761d6478bd642f
  50:	1d 76 a0 
  53:	be 01 00 00 00       	mov    esi,0x1
  58:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  5f:	00 
  60:	44 0f b6 42 fb       	movzx  r8d,BYTE PTR [rdx-0x5]
  65:	0f b6 7a fa          	movzx  edi,BYTE PTR [rdx-0x6]
  69:	48 83 ff 47          	cmp    rdi,0x47
  6d:	76 71                	jbe    0xe0
  6f:	45 0f b6 c8          	movzx  r9d,r8b
  73:	48 83 ff 48          	cmp    rdi,0x48
  77:	0f 84 0a 01 00 00    	je     0x187
  7d:	83 ff 50             	cmp    edi,0x50
  80:	0f 85 aa 01 00 00    	jne    0x230
  86:	41 83 f9 55          	cmp    r9d,0x55
  8a:	0f 84 3e 01 00 00    	je     0x1ce
  90:	41 83 f9 4f          	cmp    r9d,0x4f
  94:	0f 85 96 01 00 00    	jne    0x230
  9a:	41 b0 4f             	mov    r8b,0x4f
  9d:	80 7a fc 53          	cmp    BYTE PTR [rdx-0x4],0x53
  a1:	0f 85 89 01 00 00    	jne    0x230
  a7:	80 7a fd 54          	cmp    BYTE PTR [rdx-0x3],0x54
  ab:	0f 85 7f 01 00 00    	jne    0x230
  b1:	80 7a fe 20          	cmp    BYTE PTR [rdx-0x2],0x20
  b5:	0f 85 75 01 00 00    	jne    0x230
  bb:	41 b9 53 00 00 00    	mov    r9d,0x53
  c1:	41 b8 54 00 00 00    	mov    r8d,0x54
  c7:	41 ba 02 00 00 00    	mov    r10d,0x2
  cd:	41 bb 4f 00 00 00    	mov    r11d,0x4f
  d3:	e9 69 01 00 00       	jmp    0x241
  d8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  df:	00 
  e0:	83 ff 44             	cmp    edi,0x44
  e3:	75 5b                	jne    0x140
  e5:	41 80 f8 45          	cmp    r8b,0x45
  e9:	0f 85 41 01 00 00    	jne    0x230
  ef:	41 b0 45             	mov    r8b,0x45
  f2:	80 7a fc 4c          	cmp    BYTE PTR [rdx-0x4],0x4c
  f6:	0f 85 34 01 00 00    	jne    0x230
  fc:	80 7a fd 45          	cmp    BYTE PTR [rdx-0x3],0x45
 100:	0f 85 2a 01 00 00    	jne    0x230
 106:	80 7a fe 54          	cmp    BYTE PTR [rdx-0x2],0x54
 10a:	0f 85 20 01 00 00    	jne    0x230
 110:	80 7a ff 45          	cmp    BYTE PTR [rdx-0x1],0x45
 114:	0f 85 16 01 00 00    	jne    0x230
 11a:	80 3a 20             	cmp    BYTE PTR [rdx],0x20
 11d:	0f 85 0d 01 00 00    	jne    0x230
 123:	41 b9 4c 00 00 00    	mov    r9d,0x4c
 129:	41 ba 04 00 00 00    	mov    r10d,0x4
 12f:	41 bb 45 00 00 00    	mov    r11d,0x45
 135:	41 b8 45 00 00 00    	mov    r8d,0x45
 13b:	e9 01 01 00 00       	jmp    0x241
 140:	83 ff 47             	cmp    edi,0x47
 143:	0f 85 e7 00 00 00    	jne    0x230
 149:	41 80 f8 45          	cmp    r8b,0x45
 14d:	0f 85 dd 00 00 00    	jne    0x230
 153:	41 b0 45             	mov    r8b,0x45
 156:	80 7a fc 54          	cmp    BYTE PTR [rdx-0x4],0x54
 15a:	0f 85 d0 00 00 00    	jne    0x230
 160:	80 7a fd 20          	cmp    BYTE PTR [rdx-0x3],0x20
 164:	0f 85 c6 00 00 00    	jne    0x230
 16a:	41 b9 54 00 00 00    	mov    r9d,0x54
 170:	41 b8 20 00 00 00    	mov    r8d,0x20
 176:	41 ba 01 00 00 00    	mov    r10d,0x1
 17c:	41 bb 45 00 00 00    	mov    r11d,0x45
 182:	e9 ba 00 00 00       	jmp    0x241
 187:	41 83 f9 54          	cmp    r9d,0x54
 18b:	74 6a                	je     0x1f7
 18d:	41 83 f9 45          	cmp    r9d,0x45
 191:	0f 85 99 00 00 00    	jne    0x230
 197:	41 b0 45             	mov    r8b,0x45
 19a:	80 7a fc 41          	cmp    BYTE PTR [rdx-0x4],0x41
 19e:	0f 85 8c 00 00 00    	jne    0x230
 1a4:	80 7a fd 44          	cmp    BYTE PTR [rdx-0x3],0x44
 1a8:	0f 85 82 00 00 00    	jne    0x230
 1ae:	80 7a fe 20          	cmp    BYTE PTR [rdx-0x2],0x20
 1b2:	75 7c                	jne    0x230
 1b4:	41 b9 41 00 00 00    	mov    r9d,0x41
 1ba:	41 b8 44 00 00 00    	mov    r8d,0x44
 1c0:	41 ba 05 00 00 00    	mov    r10d,0x5
 1c6:	41 bb 45 00 00 00    	mov    r11d,0x45
 1cc:	eb 73                	jmp    0x241
 1ce:	41 b0 55             	mov    r8b,0x55
 1d1:	80 7a fc 54          	cmp    BYTE PTR [rdx-0x4],0x54
 1d5:	75 59                	jne    0x230
 1d7:	80 7a fd 20          	cmp    BYTE PTR [rdx-0x3],0x20
 1db:	75 53                	jne    0x230
 1dd:	41 b9 54 00 00 00    	mov    r9d,0x54
 1e3:	41 b8 20 00 00 00    	mov    r8d,0x20
 1e9:	41 ba 03 00 00 00    	mov    r10d,0x3
 1ef:	41 bb 55 00 00 00    	mov    r11d,0x55
 1f5:	eb 4a                	jmp    0x241
 1f7:	41 b0 54             	mov    r8b,0x54
 1fa:	80 7a fc 54          	cmp    BYTE PTR [rdx-0x4],0x54
 1fe:	75 30                	jne    0x230
 200:	80 7a fd 50          	cmp    BYTE PTR [rdx-0x3],0x50
 204:	75 2a                	jne    0x230
 206:	80 7a fe 2f          	cmp    BYTE PTR [rdx-0x2],0x2f
 20a:	75 24                	jne    0x230
 20c:	41 b8 50 00 00 00    	mov    r8d,0x50
 212:	41 ba 06 00 00 00    	mov    r10d,0x6
 218:	41 bb 54 00 00 00    	mov    r11d,0x54
 21e:	41 b9 54 00 00 00    	mov    r9d,0x54
 224:	eb 1b                	jmp    0x241
 226:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
 22d:	00 00 00 
 230:	45 0f b6 d8          	movzx  r11d,r8b
 234:	44 0f b6 42 fd       	movzx  r8d,BYTE PTR [rdx-0x3]
 239:	44 0f b6 4a fc       	movzx  r9d,BYTE PTR [rdx-0x4]
 23e:	45 31 d2             	xor    r10d,r10d
 241:	c1 e7 08             	shl    edi,0x8
 244:	41 c1 e3 10          	shl    r11d,0x10
 248:	41 09 fb             	or     r11d,edi
 24b:	49 8d 7a 01          	lea    rdi,[r10+0x1]
 24f:	48 8d 5e 0a          	lea    rbx,[rsi+0xa]
 253:	48 0f af fb          	imul   rdi,rbx
 257:	48 01 c7             	add    rdi,rax
 25a:	41 c1 e1 18          	shl    r9d,0x18
 25e:	45 09 d9             	or     r9d,r11d
 261:	49 c1 e0 20          	shl    r8,0x20
 265:	4d 09 c8             	or     r8,r9
 268:	4d 09 d0             	or     r8,r10
 26b:	48 83 c2 10          	add    rdx,0x10
 26f:	c4 c2 c9 f7 c0       	shlx   rax,r8,rsi
 274:	48 31 f8             	xor    rax,rdi
 277:	48 ff c6             	inc    rsi
 27a:	48 83 fe 09          	cmp    rsi,0x9
 27e:	0f 85 dc fd ff ff    	jne    0x60
 284:	40 88 39             	mov    BYTE PTR [rcx],dil
 287:	48 89 c2             	mov    rdx,rax
 28a:	48 c1 ea 38          	shr    rdx,0x38
 28e:	88 51 07             	mov    BYTE PTR [rcx+0x7],dl
 291:	48 89 c2             	mov    rdx,rax
 294:	48 c1 ea 30          	shr    rdx,0x30
 298:	88 51 06             	mov    BYTE PTR [rcx+0x6],dl
 29b:	48 89 c2             	mov    rdx,rax
 29e:	48 c1 ea 28          	shr    rdx,0x28
 2a2:	88 51 05             	mov    BYTE PTR [rcx+0x5],dl
 2a5:	48 89 c2             	mov    rdx,rax
 2a8:	48 c1 ea 20          	shr    rdx,0x20
 2ac:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
 2af:	89 c2                	mov    edx,eax
 2b1:	c1 ea 18             	shr    edx,0x18
 2b4:	88 51 03             	mov    BYTE PTR [rcx+0x3],dl
 2b7:	89 c2                	mov    edx,eax
 2b9:	c1 ea 10             	shr    edx,0x10
 2bc:	88 51 02             	mov    BYTE PTR [rcx+0x2],dl
 2bf:	88 61 01             	mov    BYTE PTR [rcx+0x1],ah
 2c2:	b8 02 00 00 00       	mov    eax,0x2
 2c7:	5b                   	pop    rbx
 2c8:	c3                   	ret
 2c9:	31 c0                	xor    eax,eax
 2cb:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 79
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0x8],0x8]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0xc],0x10]
 * - 0x1130: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1132: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1134: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1148: lea    rsi,[rip+0xeb1] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeb1]]
 * - 0x1158: movzx  r9d,BYTE PTR [rax-0x5] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x115d: lea    r11d,[r8-0x44] [warning-reg-remap: LEA via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x116b: movzx  r10d,r9b [warning-unmapped: movzx source size not recognized: r9b]
 * - 0x116f: movsxd r11,DWORD PTR [rsi+r11*4] [warning-reg-remap: movsxd SIB kop; verifier instantiate uses temp BPF_REG_6; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1173: add    r11,rsi [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1176: jmp    r11 [warning-unmapped: cannot parse branch target r11]
 * - 0x1179: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    r9b,0x45]
 * - 0x1183: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1186: cmp    BYTE PTR [rax-0x4],0x4c [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x4c]
 * - 0x1190: cmp    BYTE PTR [rax-0x3],0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x45]
 * - 0x119a: cmp    BYTE PTR [rax-0x2],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x54]
 * - 0x11a4: cmp    BYTE PTR [rax-0x1],0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x1],0x45]
 * - 0x11b0: cmp    BYTE PTR [rax],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax],0x20]
 * - 0x11b9: mov    r10d,0x4 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x4]
 * - 0x11bf: mov    r9b,0x4c [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c2: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11d0: cmp    r10d,0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x54]
 * - 0x11d4: je     1275 <tracee_http_method_prefix_detect_xdp+0x175> [warning-unmapped: cannot lower cmp    r10d,0x54 + je     1275 <tracee_http_method_prefix_detect_xdp+0x175> to BPF branch]
 * - 0x11da: cmp    r10d,0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x45]
 * - 0x11de: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch]
 * - 0x11e4: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11e7: cmp    BYTE PTR [rax-0x4],0x41 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x41]
 * - 0x11f1: cmp    BYTE PTR [rax-0x3],0x44 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x44]
 * - 0x11fb: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11fe: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x20]
 * - 0x1208: mov    r10d,0x5 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x5]
 * - 0x120e: mov    r9b,0x41 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1218: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    r9b,0x45]
 * - 0x1222: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1225: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x54]
 * - 0x122f: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1232: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x20]
 * - 0x123c: mov    r10d,0x1 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x1]
 * - 0x1244: cmp    r10d,0x55 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x55]
 * - 0x1248: je     1297 <tracee_http_method_prefix_detect_xdp+0x197> [warning-unmapped: cannot lower cmp    r10d,0x55 + je     1297 <tracee_http_method_prefix_detect_xdp+0x197> to BPF branch]
 * - 0x124a: cmp    r10d,0x4f [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x4f]
 * - 0x124e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x4f + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch]
 * - 0x1250: mov    r9b,0x4f [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1253: cmp    BYTE PTR [rax-0x4],0x53 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x53]
 * - 0x1259: cmp    BYTE PTR [rax-0x3],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x54]
 * - 0x125f: mov    r11b,0x4f [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1262: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x20]
 * - 0x1268: mov    r10d,0x2 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x2]
 * - 0x126e: mov    r9b,0x53 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1275: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1278: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x54]
 * - 0x127e: cmp    BYTE PTR [rax-0x3],0x50 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x50]
 * - 0x1284: cmp    BYTE PTR [rax-0x2],0x2f [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x2f]
 * - 0x128a: mov    r10d,0x6 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x6]
 * - 0x1292: mov    r11b,0x54 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1297: mov    r9b,0x55 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x129a: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x54]
 * - 0x12a0: mov    r11b,0x55 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12a3: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x20]
 * - 0x12a9: mov    r10d,0x3 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x3]
 * - 0x12af: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c0: mov    r11d,r9d [warning-reg-remap: 32-bit register move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c3: movzx  r9d,BYTE PTR [rax-0x4] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12cc: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x12d2: lea    r14d,[r10+0x1] [warning-unmapped: LEA base/index not in BPF register file: [r10+0x1]]
 * - 0x12e5: movzx  r9d,r9b [warning-reg-remap: movzx r32,r8 kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12e9: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12ed: movzx  r11d,r11b [warning-reg-remap: movzx r32,r8 kop; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12f1: shl    r11d,0x10 [warning-reg-remap: ALU imm operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12f9: or     r8d,r11d [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x12fc: or     r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1302: mov    ebx,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    ebx,r10d]
 * - 0x1322: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh]
 * - 0x135f: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1360: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1362: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    /* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x90] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 144), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0x8],0x8] */
    /* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0x8],0x8 + jne    110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 8),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0xc],0x10] */
    /* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x10 + jne    110e <tracee_http_method_prefix_detect_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -15, 16),
    /* 0x1130: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1134: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: lea    rax,[rdx+0x16] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_3, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1139: movabs rbx,0xa0761d6478bd642f [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xa0761d6478bd642fULL),
    /* 0x1143: mov    ecx,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x1148: lea    rsi,[rip+0xeb1] [warning-unmapped: LEA base/index not in BPF register file: [rip+0xeb1]] */
    /* 0x114f: nop [padding: padding is not part of BPF semantics] */
    /* 0x1150: mov    rdi,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1153: movzx  r8d,BYTE PTR [rax-0x6] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_0, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1158: movzx  r9d,BYTE PTR [rax-0x5] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_0, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x115d: lea    r11d,[r8-0x44] [warning-reg-remap: LEA via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_5, 0, 0, 1, 0, -68), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1161: cmp    r11d,0xc [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_7, 12), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1165: ja     12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    r11d,0xc + ja     12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_7, 0, 68, 12),
    /* 0x116b: movzx  r10d,r9b [warning-unmapped: movzx source size not recognized: r9b] */
    /* 0x116f: movsxd r11,DWORD PTR [rsi+r11*4] [warning-reg-remap: movsxd SIB kop; verifier instantiate uses temp BPF_REG_6; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_SIB_TMP_PAYLOAD(BPF_REG_7, BPF_REG_2, BPF_REG_7, 2, 0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVSXD_SIB),
    /* 0x1173: add    r11,rsi [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_7, BPF_REG_2, 0, 0),
    /* 0x1176: jmp    r11 [warning-unmapped: cannot parse branch target r11] */
    /* 0x1179: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    r9b,0x45] */
    /* 0x117d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    r9b,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 64, 69),
    /* 0x1183: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 69),
    /* 0x1186: cmp    BYTE PTR [rax-0x4],0x4c [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x4c] */
    /* 0x118a: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x4c + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 61, 76),
    /* 0x1190: cmp    BYTE PTR [rax-0x3],0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x45] */
    /* 0x1194: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 59, 69),
    /* 0x119a: cmp    BYTE PTR [rax-0x2],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x54] */
    /* 0x119e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 57, 84),
    /* 0x11a4: cmp    BYTE PTR [rax-0x1],0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x1],0x45] */
    /* 0x11a8: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x1],0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -1),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 55, 69),
    /* 0x11ae: mov    bl,0x45 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 69),
    /* 0x11b0: cmp    BYTE PTR [rax],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax],0x20] */
    /* 0x11b3: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 52, 32),
    /* 0x11b9: mov    r10d,0x4 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x4] */
    /* 0x11bf: mov    r9b,0x4c [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 76),
    /* 0x11c2: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 69),
    /* 0x11c5: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 54, 0),
    /* 0x11ca: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11d0: cmp    r10d,0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x54] */
    /* 0x11d4: je     1275 <tracee_http_method_prefix_detect_xdp+0x175> [warning-unmapped: cannot lower cmp    r10d,0x54 + je     1275 <tracee_http_method_prefix_detect_xdp+0x175> to BPF branch] */
    /* 0x11da: cmp    r10d,0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x45] */
    /* 0x11de: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch] */
    /* 0x11e4: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 69),
    /* 0x11e7: cmp    BYTE PTR [rax-0x4],0x41 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x41] */
    /* 0x11eb: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x41 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 46, 65),
    /* 0x11f1: cmp    BYTE PTR [rax-0x3],0x44 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x44] */
    /* 0x11f5: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x44 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 44, 68),
    /* 0x11fb: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 69),
    /* 0x11fe: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x20] */
    /* 0x1202: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 41, 32),
    /* 0x1208: mov    r10d,0x5 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x5] */
    /* 0x120e: mov    r9b,0x41 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 65),
    /* 0x1211: mov    bl,0x44 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 68),
    /* 0x1213: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 43, 0),
    /* 0x1218: cmp    r9b,0x45 [warning-unmapped: CMP operand form has no current kop selector: cmp    r9b,0x45] */
    /* 0x121c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    r9b,0x45 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 37, 69),
    /* 0x1222: mov    r9b,0x45 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 69),
    /* 0x1225: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x54] */
    /* 0x1229: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 34, 84),
    /* 0x122f: mov    r11b,0x45 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 69),
    /* 0x1232: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x20] */
    /* 0x1236: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 31, 32),
    /* 0x123c: mov    r10d,0x1 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x1] */
    /* 0x1242: jmp    12af <tracee_http_method_prefix_detect_xdp+0x1af> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 27, 0),
    /* 0x1244: cmp    r10d,0x55 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x55] */
    /* 0x1248: je     1297 <tracee_http_method_prefix_detect_xdp+0x197> [warning-unmapped: cannot lower cmp    r10d,0x55 + je     1297 <tracee_http_method_prefix_detect_xdp+0x197> to BPF branch] */
    /* 0x124a: cmp    r10d,0x4f [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x4f] */
    /* 0x124e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [warning-unmapped: cannot lower cmp    r10d,0x4f + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to BPF branch] */
    /* 0x1250: mov    r9b,0x4f [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 79),
    /* 0x1253: cmp    BYTE PTR [rax-0x4],0x53 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x53] */
    /* 0x1257: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x53 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 27, 83),
    /* 0x1259: cmp    BYTE PTR [rax-0x3],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x54] */
    /* 0x125d: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 25, 84),
    /* 0x125f: mov    r11b,0x4f [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 79),
    /* 0x1262: cmp    BYTE PTR [rax-0x2],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x20] */
    /* 0x1266: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 22, 32),
    /* 0x1268: mov    r10d,0x2 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x2] */
    /* 0x126e: mov    r9b,0x53 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 83),
    /* 0x1271: mov    bl,0x54 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 84),
    /* 0x1273: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 24, 0),
    /* 0x1275: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 84),
    /* 0x1278: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x54] */
    /* 0x127c: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 16, 84),
    /* 0x127e: cmp    BYTE PTR [rax-0x3],0x50 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x50] */
    /* 0x1282: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x50 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 14, 80),
    /* 0x1284: cmp    BYTE PTR [rax-0x2],0x2f [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x2],0x2f] */
    /* 0x1288: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x2],0x2f + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 12, 47),
    /* 0x128a: mov    r10d,0x6 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x6] */
    /* 0x1290: mov    bl,0x50 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 80),
    /* 0x1292: mov    r11b,0x54 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 84),
    /* 0x1295: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 14, 0),
    /* 0x1297: mov    r9b,0x55 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 85),
    /* 0x129a: cmp    BYTE PTR [rax-0x4],0x54 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x4],0x54] */
    /* 0x129e: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x4],0x54 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 6, 84),
    /* 0x12a0: mov    r11b,0x55 [warning-reg-remap: 64-bit immediate move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_MOV64_IMM(BPF_REG_7, 85),
    /* 0x12a3: cmp    BYTE PTR [rax-0x3],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rax-0x3],0x20] */
    /* 0x12a7: jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> [bpf-branch: lowered cmp    BYTE PTR [rax-0x3],0x20 + jne    12c0 <tracee_http_method_prefix_detect_xdp+0x1c0> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 3, 32),
    /* 0x12a9: mov    r10d,0x3 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x3] */
    /* 0x12af: mov    r9b,0x54 [warning-reg-remap: 64-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_MOV64_IMM(BPF_REG_9, 84),
    /* 0x12b2: mov    bl,0x20 [bpf-jit: 64-bit immediate move] */
    HC_MOV64_IMM(BPF_REG_6, 32),
    /* 0x12b4: jmp    12cf <tracee_http_method_prefix_detect_xdp+0x1cf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x12b6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x12c0: mov    r11d,r9d [warning-reg-remap: 32-bit register move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x12c3: movzx  r9d,BYTE PTR [rax-0x4] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_0, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12c8: movzx  ebx,BYTE PTR [rax-0x3] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12cc: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x12cf: movzx  ebx,bl [exact-kop: movzx r32,r8 kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR),
    /* 0x12d2: lea    r14d,[r10+0x1] [warning-unmapped: LEA base/index not in BPF register file: [r10+0x1]] */
    /* 0x12d6: lea    r15,[rcx+0xa] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_4, 0, 0, 1, 0, 10), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12da: imul   r14,r15 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_IMULQ_RR),
    /* 0x12de: add    rdi,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_8, 0, 0),
    /* 0x12e1: shl    rbx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 32),
    /* 0x12e5: movzx  r9d,r9b [warning-reg-remap: movzx r32,r8 kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR),
    /* 0x12e9: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x12ed: movzx  r11d,r11b [warning-reg-remap: movzx r32,r8 kop; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_7, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVZBL_RR),
    /* 0x12f1: shl    r11d,0x10 [warning-reg-remap: ALU imm operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_7, 0, 0, 16),
    /* 0x12f5: shl    r8d,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 8),
    /* 0x12f9: or     r8d,r11d [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_7, 0, 0),
    /* 0x12fc: or     r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_9, 0, 0),
    /* 0x12ff: or     r8,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_5, BPF_REG_6, 0, 0),
    /* 0x1302: mov    ebx,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    ebx,r10d] */
    /* 0x1305: or     rbx,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_5, 0, 0),
    /* 0x1308: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x130b: xor    rbx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x130e: add    rax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x1312: inc    rcx [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1315: cmp    rcx,0x9 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_4, 9), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1319: jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> [bpf-branch: lowered cmp    rcx,0x9 + jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -111, 9),
    /* 0x131f: mov    BYTE PTR [rdx],dil [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1322: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh] */
    /* 0x1325: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x1327: shr    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x132a: mov    BYTE PTR [rdx+0x2],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x132d: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x132f: shr    eax,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 24),
    /* 0x1332: mov    BYTE PTR [rdx+0x3],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1335: mov    rax,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1338: shr    rax,0x20 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x133c: mov    BYTE PTR [rdx+0x4],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x133f: mov    rax,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1342: shr    rax,0x28 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1346: mov    BYTE PTR [rdx+0x5],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1349: mov    rax,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x134c: shr    rax,0x30 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1350: mov    BYTE PTR [rdx+0x6],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1353: shr    rbx,0x38 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1357: mov    BYTE PTR [rdx+0x7],bl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x135a: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x135f: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1360: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1362: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1364: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
