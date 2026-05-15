# tetragon_process_event_arg_filter

## Original C
```c
#include "common.h"

#define TETRAGON_ARG_FILTER_RECORDS 32U
#define TETRAGON_ARG_FILTER_RECORD_SIZE 32U
#define TETRAGON_ARG_FILTER_INPUT_SIZE \
    (8U + TETRAGON_ARG_FILTER_RECORDS * TETRAGON_ARG_FILTER_RECORD_SIZE)

static __always_inline u32 tetragon_event_weight(u16 event_id)
{
    switch (event_id) {
    case 1U: return 0x11U;
    case 2U: return 0x23U;
    case 5U: return 0x37U;
    case 9U: return 0x41U;
    case 13U: return 0x59U;
    default: return 0U;
    }
}

static __always_inline u32 tetragon_arg_prefix_class(u64 arg_sig)
{
    if ((arg_sig & 0xFFFFFFFFULL) == 0x68736162ULL) {
        return 1U;
    }
    if ((arg_sig & 0xFFFFFFFFULL) == 0x6C727563ULL) {
        return 2U;
    }
    if ((arg_sig & 0xFFFFFFFFFFFFULL) == 0x6E6F68747970ULL) {
        return 3U;
    }
    if ((arg_sig & 0xFFFFFFULL) == 0x006873ULL) {
        return 4U;
    }
    return 0U;
}

static __always_inline int
bench_tetragon_process_event_arg_filter(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TETRAGON_ARG_FILTER_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != TETRAGON_ARG_FILTER_RECORDS ||
        record_size != TETRAGON_ARG_FILTER_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0xE7037ED1A0B428DBULL;
    for (u32 index = 0; index < TETRAGON_ARG_FILTER_RECORDS; index++) {
        u32 base = 8U + index * TETRAGON_ARG_FILTER_RECORD_SIZE;
        u32 pid = micro_read_u32_le(data, base);
        u32 tid = micro_read_u32_le(data, base + 4U);
        u32 namespace_id = micro_read_u32_le(data, base + 8U);
        u16 event_id = micro_read_u16_le(data, base + 12U);
        u16 action = micro_read_u16_le(data, base + 14U);
        u64 caps = micro_read_u64_le(data, base + 16U);
        u64 arg_sig = micro_read_u64_le(data, base + 24U);
        u32 weight = tetragon_event_weight(event_id);
        u32 arg_class = tetragon_arg_prefix_class(arg_sig);
        u32 namespace_match = (namespace_id & 0xFFU) == 0x42U;
        u32 cap_match = (caps & 0x0000000000002400ULL) != 0U;

        if (weight == 0U) {
            acc ^= ((u64)event_id << 32U) | pid;
            continue;
        }
        if (namespace_match == 0U && cap_match == 0U) {
            acc += ((u64)tid << 16U) ^ namespace_id;
            continue;
        }

        u64 decision = ((u64)weight << 48U) | ((u64)arg_class << 40U) |
                       ((u64)action << 24U) | pid;
        if ((action & 2U) != 0U && arg_class != 0U) {
            decision ^= micro_rotl64(arg_sig, (event_id & 7U) + 1U);
        }
        if ((action & 4U) != 0U) {
            decision += caps ^ tid;
        }

        acc ^= micro_rotl64(decision, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tetragon_process_event_arg_filter_xdp,
    bench_tetragon_process_event_arg_filter,
    tetragon_process_event_arg_filter_input_value,
    TETRAGON_ARG_FILTER_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <tetragon_process_event_arg_filter_xdp>:
    1100:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ce             	cmp    rsi,rcx
    110c:	76 01                	jbe    110f <tetragon_process_event_arg_filter_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 56 08          	lea    rdx,[rsi+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <tetragon_process_event_arg_filter_xdp+0xe>
    1118:	48 8d 96 10 04 00 00 	lea    rdx,[rsi+0x410]
    111f:	48 39 ca             	cmp    rdx,rcx
    1122:	77 ea                	ja     110e <tetragon_process_event_arg_filter_xdp+0xe>
    1124:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
    1128:	75 e4                	jne    110e <tetragon_process_event_arg_filter_xdp+0xe>
    112a:	83 7e 0c 20          	cmp    DWORD PTR [rsi+0xc],0x20
    112e:	75 de                	jne    110e <tetragon_process_event_arg_filter_xdp+0xe>
    1130:	55                   	push   rbp
    1131:	41 57                	push   r15
    1133:	41 56                	push   r14
    1135:	41 55                	push   r13
    1137:	41 54                	push   r12
    1139:	53                   	push   rbx
    113a:	48 89 74 24 d0       	mov    QWORD PTR [rsp-0x30],rsi
    113f:	48 8d 7e 2f          	lea    rdi,[rsi+0x2f]
    1143:	48 bb db 28 b4 a0 d1 	movabs rbx,0xe7037ed1a0b428db
    114a:	7e 03 e7 
    114d:	45 31 c0             	xor    r8d,r8d
    1150:	eb 2c                	jmp    117e <tetragon_process_event_arg_filter_xdp+0x7e>
    1152:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1159:	1f 84 00 00 00 00 00 
    1160:	48 c1 e1 20          	shl    rcx,0x20
    1164:	44 89 e0             	mov    eax,r12d
    1167:	48 09 c8             	or     rax,rcx
    116a:	48 31 c3             	xor    rbx,rax
    116d:	49 ff c0             	inc    r8
    1170:	48 83 c7 20          	add    rdi,0x20
    1174:	49 83 f8 20          	cmp    r8,0x20
    1178:	0f 84 70 02 00 00    	je     13ee <tetragon_process_event_arg_filter_xdp+0x2ee>
    117e:	0f b6 47 ed          	movzx  eax,BYTE PTR [rdi-0x13]
    1182:	0f b6 4f ee          	movzx  ecx,BYTE PTR [rdi-0x12]
    1186:	c1 e1 08             	shl    ecx,0x8
    1189:	48 09 c1             	or     rcx,rax
    118c:	8d 51 ff             	lea    edx,[rcx-0x1]
    118f:	83 fa 0c             	cmp    edx,0xc
    1192:	77 1e                	ja     11b2 <tetragon_process_event_arg_filter_xdp+0xb2>
    1194:	48 8d 35 65 0e 00 00 	lea    rsi,[rip+0xe65]        # 2000 <_fini+0xbf8>
    119b:	48 63 14 96          	movsxd rdx,DWORD PTR [rsi+rdx*4]
    119f:	48 01 f2             	add    rdx,rsi
    11a2:	ff e2                	jmp    rdx
    11a4:	31 d2                	xor    edx,edx
    11a6:	49 be 00 00 00 00 00 	movabs r14,0x11000000000000
    11ad:	00 11 00 
    11b0:	eb 3e                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11b2:	b2 01                	mov    dl,0x1
    11b4:	45 31 f6             	xor    r14d,r14d
    11b7:	eb 37                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11b9:	31 d2                	xor    edx,edx
    11bb:	49 be 00 00 00 00 00 	movabs r14,0x37000000000000
    11c2:	00 37 00 
    11c5:	eb 29                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11c7:	31 d2                	xor    edx,edx
    11c9:	49 be 00 00 00 00 00 	movabs r14,0x23000000000000
    11d0:	00 23 00 
    11d3:	eb 1b                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11d5:	31 d2                	xor    edx,edx
    11d7:	49 be 00 00 00 00 00 	movabs r14,0x41000000000000
    11de:	00 41 00 
    11e1:	eb 0d                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11e3:	31 d2                	xor    edx,edx
    11e5:	49 be 00 00 00 00 00 	movabs r14,0x59000000000000
    11ec:	00 59 00 
    11ef:	90                   	nop
    11f0:	0f b7 77 f9          	movzx  esi,WORD PTR [rdi-0x7]
    11f4:	44 0f b6 4f fb       	movzx  r9d,BYTE PTR [rdi-0x5]
    11f9:	41 c1 e1 10          	shl    r9d,0x10
    11fd:	49 09 f1             	or     r9,rsi
    1200:	0f b6 77 fc          	movzx  esi,BYTE PTR [rdi-0x4]
    1204:	c1 e6 18             	shl    esi,0x18
    1207:	4c 09 ce             	or     rsi,r9
    120a:	44 0f b6 5f fd       	movzx  r11d,BYTE PTR [rdi-0x3]
    120f:	49 c1 e3 20          	shl    r11,0x20
    1213:	44 0f b6 57 fe       	movzx  r10d,BYTE PTR [rdi-0x2]
    1218:	49 c1 e2 28          	shl    r10,0x28
    121c:	4d 09 da             	or     r10,r11
    121f:	49 09 f2             	or     r10,rsi
    1222:	48 81 fe 62 61 73 68 	cmp    rsi,0x68736162
    1229:	74 15                	je     1240 <tetragon_process_event_arg_filter_xdp+0x140>
    122b:	81 fe 63 75 72 6c    	cmp    esi,0x6c727563
    1231:	75 1d                	jne    1250 <tetragon_process_event_arg_filter_xdp+0x150>
    1233:	be 02 00 00 00       	mov    esi,0x2
    1238:	eb 46                	jmp    1280 <tetragon_process_event_arg_filter_xdp+0x180>
    123a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1240:	be 01 00 00 00       	mov    esi,0x1
    1245:	eb 39                	jmp    1280 <tetragon_process_event_arg_filter_xdp+0x180>
    1247:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    124e:	00 00 
    1250:	be 03 00 00 00       	mov    esi,0x3
    1255:	49 bb 70 79 74 68 6f 	movabs r11,0x6e6f68747970
    125c:	6e 00 00 
    125f:	4d 39 da             	cmp    r10,r11
    1262:	74 1c                	je     1280 <tetragon_process_event_arg_filter_xdp+0x180>
    1264:	31 f6                	xor    esi,esi
    1266:	41 81 f9 73 68 00 00 	cmp    r9d,0x6873
    126d:	40 0f 94 c6          	sete   sil
    1271:	c1 e6 02             	shl    esi,0x2
    1274:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    127b:	00 00 00 00 00 
    1280:	44 8b 67 e1          	mov    r12d,DWORD PTR [rdi-0x1f]
    1284:	84 d2                	test   dl,dl
    1286:	0f 85 d4 fe ff ff    	jne    1160 <tetragon_process_event_arg_filter_xdp+0x60>
    128c:	48 89 5c 24 c8       	mov    QWORD PTR [rsp-0x38],rbx
    1291:	0f b6 57 e9          	movzx  edx,BYTE PTR [rdi-0x17]
    1295:	0f b6 4f f1          	movzx  ecx,BYTE PTR [rdi-0xf]
    1299:	48 89 4c 24 e0       	mov    QWORD PTR [rsp-0x20],rcx
    129e:	44 0f b6 4f f2       	movzx  r9d,BYTE PTR [rdi-0xe]
    12a3:	0f b6 4f f3          	movzx  ecx,BYTE PTR [rdi-0xd]
    12a7:	89 4c 24 c4          	mov    DWORD PTR [rsp-0x3c],ecx
    12ab:	0f b6 6f f4          	movzx  ebp,BYTE PTR [rdi-0xc]
    12af:	0f b6 4f f5          	movzx  ecx,BYTE PTR [rdi-0xb]
    12b3:	48 89 4c 24 e8       	mov    QWORD PTR [rsp-0x18],rcx
    12b8:	0f b6 5f f6          	movzx  ebx,BYTE PTR [rdi-0xa]
    12bc:	0f b6 4f f7          	movzx  ecx,BYTE PTR [rdi-0x9]
    12c0:	48 89 4c 24 f0       	mov    QWORD PTR [rsp-0x10],rcx
    12c5:	0f b6 4f f8          	movzx  ecx,BYTE PTR [rdi-0x8]
    12c9:	48 89 4c 24 f8       	mov    QWORD PTR [rsp-0x8],rcx
    12ce:	0f b6 4f ff          	movzx  ecx,BYTE PTR [rdi-0x1]
    12d2:	48 89 4c 24 d8       	mov    QWORD PTR [rsp-0x28],rcx
    12d7:	44 0f b6 3f          	movzx  r15d,BYTE PTR [rdi]
    12db:	44 0f b7 5f ef       	movzx  r11d,WORD PTR [rdi-0x11]
    12e0:	44 8b 6f e5          	mov    r13d,DWORD PTR [rdi-0x1b]
    12e4:	80 fa 42             	cmp    dl,0x42
    12e7:	74 37                	je     1320 <tetragon_process_event_arg_filter_xdp+0x220>
    12e9:	44 89 c9             	mov    ecx,r9d
    12ec:	83 e1 24             	and    ecx,0x24
    12ef:	75 2f                	jne    1320 <tetragon_process_event_arg_filter_xdp+0x220>
    12f1:	0f b6 47 ea          	movzx  eax,BYTE PTR [rdi-0x16]
    12f5:	c1 e0 08             	shl    eax,0x8
    12f8:	0f b7 4f eb          	movzx  ecx,WORD PTR [rdi-0x15]
    12fc:	c1 e1 10             	shl    ecx,0x10
    12ff:	48 09 d0             	or     rax,rdx
    1302:	48 09 c8             	or     rax,rcx
    1305:	49 c1 e5 10          	shl    r13,0x10
    1309:	49 31 c5             	xor    r13,rax
    130c:	48 8b 5c 24 c8       	mov    rbx,QWORD PTR [rsp-0x38]
    1311:	4c 01 eb             	add    rbx,r13
    1314:	e9 54 fe ff ff       	jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d>
    1319:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1320:	48 89 f1             	mov    rcx,rsi
    1323:	48 c1 e1 28          	shl    rcx,0x28
    1327:	4c 09 f1             	or     rcx,r14
    132a:	4c 89 da             	mov    rdx,r11
    132d:	48 c1 e2 18          	shl    rdx,0x18
    1331:	48 09 ca             	or     rdx,rcx
    1334:	45 89 e4             	mov    r12d,r12d
    1337:	49 09 d4             	or     r12,rdx
    133a:	45 0f b7 db          	movzx  r11d,r11w
    133e:	41 f6 c3 02          	test   r11b,0x2
    1342:	74 2f                	je     1373 <tetragon_process_event_arg_filter_xdp+0x273>
    1344:	85 f6                	test   esi,esi
    1346:	74 2b                	je     1373 <tetragon_process_event_arg_filter_xdp+0x273>
    1348:	48 8b 4c 24 d8       	mov    rcx,QWORD PTR [rsp-0x28]
    134d:	48 c1 e1 30          	shl    rcx,0x30
    1351:	49 c1 e7 38          	shl    r15,0x38
    1355:	49 09 cf             	or     r15,rcx
    1358:	4d 09 d7             	or     r15,r10
    135b:	24 07                	and    al,0x7
    135d:	8d 48 01             	lea    ecx,[rax+0x1]
    1360:	4c 89 fa             	mov    rdx,r15
    1363:	48 d3 e2             	shl    rdx,cl
    1366:	f6 d0                	not    al
    1368:	89 c1                	mov    ecx,eax
    136a:	49 d3 ef             	shr    r15,cl
    136d:	49 09 d7             	or     r15,rdx
    1370:	4d 31 fc             	xor    r12,r15
    1373:	41 c1 e1 08          	shl    r9d,0x8
    1377:	4c 03 4c 24 e0       	add    r9,QWORD PTR [rsp-0x20]
    137c:	8b 44 24 c4          	mov    eax,DWORD PTR [rsp-0x3c]
    1380:	c1 e0 10             	shl    eax,0x10
    1383:	c1 e5 18             	shl    ebp,0x18
    1386:	09 c5                	or     ebp,eax
    1388:	48 8b 44 24 e8       	mov    rax,QWORD PTR [rsp-0x18]
    138d:	48 c1 e0 20          	shl    rax,0x20
    1391:	48 c1 e3 28          	shl    rbx,0x28
    1395:	48 09 c3             	or     rbx,rax
    1398:	48 8b 4c 24 f0       	mov    rcx,QWORD PTR [rsp-0x10]
    139d:	48 c1 e1 30          	shl    rcx,0x30
    13a1:	48 8b 44 24 f8       	mov    rax,QWORD PTR [rsp-0x8]
    13a6:	48 c1 e0 38          	shl    rax,0x38
    13aa:	48 09 c8             	or     rax,rcx
    13ad:	4c 09 cd             	or     rbp,r9
    13b0:	48 09 dd             	or     rbp,rbx
    13b3:	48 09 c5             	or     rbp,rax
    13b6:	49 31 ed             	xor    r13,rbp
    13b9:	41 f6 c3 04          	test   r11b,0x4
    13bd:	ba 00 00 00 00       	mov    edx,0x0
    13c2:	49 0f 45 d5          	cmovne rdx,r13
    13c6:	4c 01 e2             	add    rdx,r12
    13c9:	44 89 c0             	mov    eax,r8d
    13cc:	24 07                	and    al,0x7
    13ce:	8d 48 01             	lea    ecx,[rax+0x1]
    13d1:	48 89 d6             	mov    rsi,rdx
    13d4:	48 d3 e6             	shl    rsi,cl
    13d7:	f6 d0                	not    al
    13d9:	89 c1                	mov    ecx,eax
    13db:	48 d3 ea             	shr    rdx,cl
    13de:	48 09 f2             	or     rdx,rsi
    13e1:	48 8b 5c 24 c8       	mov    rbx,QWORD PTR [rsp-0x38]
    13e6:	48 31 d3             	xor    rbx,rdx
    13e9:	e9 7f fd ff ff       	jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d>
    13ee:	48 8b 44 24 d0       	mov    rax,QWORD PTR [rsp-0x30]
    13f3:	48 89 18             	mov    QWORD PTR [rax],rbx
    13f6:	b8 02 00 00 00       	mov    eax,0x2
    13fb:	5b                   	pop    rbx
    13fc:	41 5c                	pop    r12
    13fe:	41 5d                	pop    r13
    1400:	41 5e                	pop    r14
    1402:	41 5f                	pop    r15
    1404:	5d                   	pop    rbp
    1405:	c3                   	ret

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
   c:	48 81 ec 78 00 00 00 	sub    rsp,0x78
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 b6 04 00 00    	ja     0x4e3
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 a6 04 00 00    	ja     0x4e3
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 93 04 00 00    	ja     0x4e3
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
  81:	48 83 ff 20          	cmp    rdi,0x20
  85:	0f 85 58 04 00 00    	jne    0x4e3
  8b:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  90:	48 c1 e7 08          	shl    rdi,0x8
  94:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  99:	48 09 f7             	or     rdi,rsi
  9c:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  a1:	48 c1 e6 10          	shl    rsi,0x10
  a5:	48 09 f7             	or     rdi,rsi
  a8:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  ad:	48 c1 e6 18          	shl    rsi,0x18
  b1:	48 09 f7             	or     rdi,rsi
  b4:	48 c1 e7 20          	shl    rdi,0x20
  b8:	48 c1 ef 20          	shr    rdi,0x20
  bc:	48 83 ff 20          	cmp    rdi,0x20
  c0:	0f 85 1d 04 00 00    	jne    0x4e3
  c6:	49 bf db 28 b4 a0 d1 	movabs r15,0xe7037ed1a0b428db
  cd:	7e 03 e7 
  d0:	48 89 55 88          	mov    QWORD PTR [rbp-0x78],rdx
  d4:	48 89 d1             	mov    rcx,rdx
  d7:	31 d2                	xor    edx,edx
  d9:	48 83 c1 17          	add    rcx,0x17
  dd:	eb 60                	jmp    0x13f
  df:	4c 0f b6 41 fa       	movzx  r8,BYTE PTR [rcx-0x6]
  e4:	49 c1 e0 08          	shl    r8,0x8
  e8:	48 0f b6 59 f9       	movzx  rbx,BYTE PTR [rcx-0x7]
  ed:	49 09 d8             	or     r8,rbx
  f0:	48 0f b6 59 fb       	movzx  rbx,BYTE PTR [rcx-0x5]
  f5:	48 c1 e3 10          	shl    rbx,0x10
  f9:	49 09 d8             	or     r8,rbx
  fc:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 101:	48 c1 e3 18          	shl    rbx,0x18
 105:	49 09 d8             	or     r8,rbx
 108:	48 85 ff             	test   rdi,rdi
 10b:	0f 84 a4 00 00 00    	je     0x1b5
 111:	49 c1 e0 20          	shl    r8,0x20
 115:	49 c1 e8 20          	shr    r8,0x20
 119:	49 81 e5 ff ff 00 00 	and    r13,0xffff
 120:	49 c1 e5 20          	shl    r13,0x20
 124:	4d 09 c5             	or     r13,r8
 127:	4d 31 fd             	xor    r13,r15
 12a:	4d 89 ef             	mov    r15,r13
 12d:	48 83 c1 20          	add    rcx,0x20
 131:	48 83 c2 01          	add    rdx,0x1
 135:	48 83 fa 20          	cmp    rdx,0x20
 139:	0f 84 4d 03 00 00    	je     0x48c
 13f:	4c 0f b6 69 06       	movzx  r13,BYTE PTR [rcx+0x6]
 144:	49 c1 e5 08          	shl    r13,0x8
 148:	48 0f b6 79 05       	movzx  rdi,BYTE PTR [rcx+0x5]
 14d:	49 09 fd             	or     r13,rdi
 150:	4c 89 ee             	mov    rsi,r13
 153:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 15a:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
 15e:	48 83 fe 04          	cmp    rsi,0x4
 162:	7f 26                	jg     0x18a
 164:	b8 11 00 00 00       	mov    eax,0x11
 169:	31 ff                	xor    edi,edi
 16b:	48 83 fe 01          	cmp    rsi,0x1
 16f:	0f 84 80 02 00 00    	je     0x3f5
 175:	48 83 fe 02          	cmp    rsi,0x2
 179:	74 05                	je     0x180
 17b:	e9 6e 02 00 00       	jmp    0x3ee
 180:	b8 23 00 00 00       	mov    eax,0x23
 185:	e9 6b 02 00 00       	jmp    0x3f5
 18a:	48 83 fe 05          	cmp    rsi,0x5
 18e:	0f 84 48 02 00 00    	je     0x3dc
 194:	48 83 fe 09          	cmp    rsi,0x9
 198:	0f 84 47 02 00 00    	je     0x3e5
 19e:	48 83 fe 0d          	cmp    rsi,0xd
 1a2:	74 05                	je     0x1a9
 1a4:	e9 45 02 00 00       	jmp    0x3ee
 1a9:	b8 59 00 00 00       	mov    eax,0x59
 1ae:	31 ff                	xor    edi,edi
 1b0:	e9 40 02 00 00       	jmp    0x3f5
 1b5:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
 1b9:	48 89 55 e0          	mov    QWORD PTR [rbp-0x20],rdx
 1bd:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 1c1:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 1c6:	48 89 7d a8          	mov    QWORD PTR [rbp-0x58],rdi
 1ca:	48 0f b6 79 0a       	movzx  rdi,BYTE PTR [rcx+0xa]
 1cf:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
 1d3:	48 0f b6 79 0c       	movzx  rdi,BYTE PTR [rcx+0xc]
 1d8:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 1dc:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 1e1:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 1e5:	4c 0f b6 69 fe       	movzx  r13,BYTE PTR [rcx-0x2]
 1ea:	49 c1 e5 08          	shl    r13,0x8
 1ee:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
 1f3:	49 09 fd             	or     r13,rdi
 1f6:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 1fb:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 1ff:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
 204:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 208:	4c 0f b6 79 01       	movzx  r15,BYTE PTR [rcx+0x1]
 20d:	48 0f b6 79 ff       	movzx  rdi,BYTE PTR [rcx-0x1]
 212:	48 c1 e7 10          	shl    rdi,0x10
 216:	49 09 fd             	or     r13,rdi
 219:	48 0f b6 79 10       	movzx  rdi,BYTE PTR [rcx+0x10]
 21e:	48 89 7d b0          	mov    QWORD PTR [rbp-0x50],rdi
 222:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
 227:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 22b:	48 0f b6 59 08       	movzx  rbx,BYTE PTR [rcx+0x8]
 230:	48 0f b6 51 00       	movzx  rdx,BYTE PTR [rcx+0x0]
 235:	48 c1 e2 18          	shl    rdx,0x18
 239:	48 0f b6 79 18       	movzx  rdi,BYTE PTR [rcx+0x18]
 23e:	48 89 7d 90          	mov    QWORD PTR [rbp-0x70],rdi
 242:	48 0f b6 79 17       	movzx  rdi,BYTE PTR [rcx+0x17]
 247:	48 0f b6 41 07       	movzx  rax,BYTE PTR [rcx+0x7]
 24c:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
 250:	49 09 d5             	or     r13,rdx
 253:	49 83 ff 42          	cmp    r15,0x42
 257:	74 53                	je     0x2ac
 259:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 25d:	48 83 e2 24          	and    rdx,0x24
 261:	48 85 d2             	test   rdx,rdx
 264:	75 46                	jne    0x2ac
 266:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 26b:	48 c1 e7 08          	shl    rdi,0x8
 26f:	4c 09 ff             	or     rdi,r15
 272:	48 0f b6 71 03       	movzx  rsi,BYTE PTR [rcx+0x3]
 277:	48 c1 e6 10          	shl    rsi,0x10
 27b:	48 09 f7             	or     rdi,rsi
 27e:	48 0f b6 71 04       	movzx  rsi,BYTE PTR [rcx+0x4]
 283:	48 c1 e6 18          	shl    rsi,0x18
 287:	48 09 f7             	or     rdi,rsi
 28a:	49 c1 e5 20          	shl    r13,0x20
 28e:	49 c1 ed 20          	shr    r13,0x20
 292:	49 c1 e5 10          	shl    r13,0x10
 296:	4c 31 ef             	xor    rdi,r13
 299:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 29d:	48 01 f7             	add    rdi,rsi
 2a0:	49 89 ff             	mov    r15,rdi
 2a3:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 2a7:	e9 81 fe ff ff       	jmp    0x12d
 2ac:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 2b0:	48 c1 e3 08          	shl    rbx,0x8
 2b4:	48 8b 55 a0          	mov    rdx,QWORD PTR [rbp-0x60]
 2b8:	48 09 d3             	or     rbx,rdx
 2bb:	48 89 f2             	mov    rdx,rsi
 2be:	48 c1 e2 28          	shl    rdx,0x28
 2c2:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
 2c6:	48 c1 e0 30          	shl    rax,0x30
 2ca:	48 09 d0             	or     rax,rdx
 2cd:	49 89 df             	mov    r15,rbx
 2d0:	49 81 e7 ff ff 00 00 	and    r15,0xffff
 2d7:	4c 89 fa             	mov    rdx,r15
 2da:	48 c1 e2 18          	shl    rdx,0x18
 2de:	48 09 d0             	or     rax,rdx
 2e1:	49 c1 e0 20          	shl    r8,0x20
 2e5:	49 c1 e8 20          	shr    r8,0x20
 2e9:	4c 09 c0             	or     rax,r8
 2ec:	48 83 e3 02          	and    rbx,0x2
 2f0:	48 85 db             	test   rbx,rbx
 2f3:	74 45                	je     0x33a
 2f5:	48 c1 e6 20          	shl    rsi,0x20
 2f9:	48 c1 ee 20          	shr    rsi,0x20
 2fd:	48 85 f6             	test   rsi,rsi
 300:	74 38                	je     0x33a
 302:	48 8b 75 90          	mov    rsi,QWORD PTR [rbp-0x70]
 306:	48 c1 e6 38          	shl    rsi,0x38
 30a:	48 c1 e7 30          	shl    rdi,0x30
 30e:	48 09 f7             	or     rdi,rsi
 311:	4c 09 f7             	or     rdi,r14
 314:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
 318:	49 83 e0 07          	and    r8,0x7
 31c:	4c 89 c6             	mov    rsi,r8
 31f:	48 83 f6 3f          	xor    rsi,0x3f
 323:	48 89 fa             	mov    rdx,rdi
 326:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 32b:	49 83 c0 01          	add    r8,0x1
 32f:	c4 e2 b9 f7 ff       	shlx   rdi,rdi,r8
 334:	48 09 d7             	or     rdi,rdx
 337:	48 31 f8             	xor    rax,rdi
 33a:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 33e:	48 c1 e6 08          	shl    rsi,0x8
 342:	48 8b 7d a8          	mov    rdi,QWORD PTR [rbp-0x58]
 346:	48 09 fe             	or     rsi,rdi
 349:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 34d:	48 c1 e2 18          	shl    rdx,0x18
 351:	48 8b 7d d0          	mov    rdi,QWORD PTR [rbp-0x30]
 355:	48 c1 e7 10          	shl    rdi,0x10
 359:	48 09 d7             	or     rdi,rdx
 35c:	48 09 f7             	or     rdi,rsi
 35f:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 363:	48 c1 e2 28          	shl    rdx,0x28
 367:	48 8b 75 c8          	mov    rsi,QWORD PTR [rbp-0x38]
 36b:	48 c1 e6 20          	shl    rsi,0x20
 36f:	48 09 d6             	or     rsi,rdx
 372:	48 09 fe             	or     rsi,rdi
 375:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
 379:	48 c1 e2 38          	shl    rdx,0x38
 37d:	48 8b 7d d8          	mov    rdi,QWORD PTR [rbp-0x28]
 381:	48 c1 e7 30          	shl    rdi,0x30
 385:	48 09 d7             	or     rdi,rdx
 388:	48 09 f7             	or     rdi,rsi
 38b:	49 c1 e5 20          	shl    r13,0x20
 38f:	49 c1 ed 20          	shr    r13,0x20
 393:	4c 31 ef             	xor    rdi,r13
 396:	49 c1 e7 3d          	shl    r15,0x3d
 39a:	49 c1 ff 3f          	sar    r15,0x3f
 39e:	49 21 ff             	and    r15,rdi
 3a1:	4c 01 f8             	add    rax,r15
 3a4:	4c 8b 45 e0          	mov    r8,QWORD PTR [rbp-0x20]
 3a8:	4c 89 c7             	mov    rdi,r8
 3ab:	48 83 e7 07          	and    rdi,0x7
 3af:	48 89 fe             	mov    rsi,rdi
 3b2:	48 83 f6 3f          	xor    rsi,0x3f
 3b6:	48 89 c2             	mov    rdx,rax
 3b9:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 3be:	48 83 c7 01          	add    rdi,0x1
 3c2:	c4 e2 c1 f7 c0       	shlx   rax,rax,rdi
 3c7:	48 09 d0             	or     rax,rdx
 3ca:	4c 89 c2             	mov    rdx,r8
 3cd:	48 8b 7d e8          	mov    rdi,QWORD PTR [rbp-0x18]
 3d1:	48 31 f8             	xor    rax,rdi
 3d4:	49 89 c7             	mov    r15,rax
 3d7:	e9 51 fd ff ff       	jmp    0x12d
 3dc:	b8 37 00 00 00       	mov    eax,0x37
 3e1:	31 ff                	xor    edi,edi
 3e3:	eb 10                	jmp    0x3f5
 3e5:	b8 41 00 00 00       	mov    eax,0x41
 3ea:	31 ff                	xor    edi,edi
 3ec:	eb 07                	jmp    0x3f5
 3ee:	31 c0                	xor    eax,eax
 3f0:	bf 01 00 00 00       	mov    edi,0x1
 3f5:	48 0f b6 71 12       	movzx  rsi,BYTE PTR [rcx+0x12]
 3fa:	48 c1 e6 08          	shl    rsi,0x8
 3fe:	4c 0f b6 41 11       	movzx  r8,BYTE PTR [rcx+0x11]
 403:	4c 09 c6             	or     rsi,r8
 406:	4c 0f b6 41 16       	movzx  r8,BYTE PTR [rcx+0x16]
 40b:	49 c1 e0 28          	shl    r8,0x28
 40f:	4c 0f b6 71 15       	movzx  r14,BYTE PTR [rcx+0x15]
 414:	49 c1 e6 20          	shl    r14,0x20
 418:	4d 09 c6             	or     r14,r8
 41b:	4c 0f b6 41 13       	movzx  r8,BYTE PTR [rcx+0x13]
 420:	49 c1 e0 10          	shl    r8,0x10
 424:	49 09 f0             	or     r8,rsi
 427:	48 0f b6 59 14       	movzx  rbx,BYTE PTR [rcx+0x14]
 42c:	48 c1 e3 18          	shl    rbx,0x18
 430:	4c 09 c3             	or     rbx,r8
 433:	49 09 de             	or     r14,rbx
 436:	be 01 00 00 00       	mov    esi,0x1
 43b:	48 81 fb 62 61 73 68 	cmp    rbx,0x68736162
 442:	0f 84 97 fc ff ff    	je     0xdf
 448:	48 81 fb 63 75 72 6c 	cmp    rbx,0x6c727563
 44f:	75 0a                	jne    0x45b
 451:	be 02 00 00 00       	mov    esi,0x2
 456:	e9 84 fc ff ff       	jmp    0xdf
 45b:	be 03 00 00 00       	mov    esi,0x3
 460:	48 bb 70 79 74 68 6f 	movabs rbx,0x6e6f68747970
 467:	6e 00 00 
 46a:	49 39 de             	cmp    r14,rbx
 46d:	0f 84 6c fc ff ff    	je     0xdf
 473:	be 01 00 00 00       	mov    esi,0x1
 478:	49 81 f8 73 68 00 00 	cmp    r8,0x6873
 47f:	74 02                	je     0x483
 481:	31 f6                	xor    esi,esi
 483:	48 c1 e6 02          	shl    rsi,0x2
 487:	e9 53 fc ff ff       	jmp    0xdf
 48c:	4c 89 ff             	mov    rdi,r15
 48f:	48 c1 ef 38          	shr    rdi,0x38
 493:	48 8b 75 88          	mov    rsi,QWORD PTR [rbp-0x78]
 497:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 49b:	4c 89 ff             	mov    rdi,r15
 49e:	48 c1 ef 30          	shr    rdi,0x30
 4a2:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 4a6:	4c 89 ff             	mov    rdi,r15
 4a9:	48 c1 ef 28          	shr    rdi,0x28
 4ad:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 4b1:	4c 89 ff             	mov    rdi,r15
 4b4:	48 c1 ef 20          	shr    rdi,0x20
 4b8:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 4bc:	4c 89 ff             	mov    rdi,r15
 4bf:	48 c1 ef 18          	shr    rdi,0x18
 4c3:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 4c7:	4c 89 ff             	mov    rdi,r15
 4ca:	48 c1 ef 10          	shr    rdi,0x10
 4ce:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 4d2:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 4d6:	49 c1 ef 08          	shr    r15,0x8
 4da:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 4de:	b8 02 00 00 00       	mov    eax,0x2
 4e3:	41 5f                	pop    r15
 4e5:	41 5e                	pop    r14
 4e7:	41 5d                	pop    r13
 4e9:	5b                   	pop    rbx
 4ea:	c9                   	leave
 4eb:	c3                   	ret
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
   d:	0f 87 5a 03 00 00    	ja     0x36d
  13:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  17:	48 39 ca             	cmp    rdx,rcx
  1a:	0f 87 4d 03 00 00    	ja     0x36d
  20:	48 8d 96 10 04 00 00 	lea    rdx,[rsi+0x410]
  27:	48 39 ca             	cmp    rdx,rcx
  2a:	0f 87 3d 03 00 00    	ja     0x36d
  30:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
  34:	0f 85 19 03 00 00    	jne    0x353
  3a:	83 7e 0c 20          	cmp    DWORD PTR [rsi+0xc],0x20
  3e:	0f 85 0f 03 00 00    	jne    0x353
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 89 74 24 c0       	mov    QWORD PTR [rsp-0x40],rsi
  53:	48 8d 56 17          	lea    rdx,[rsi+0x17]
  57:	49 bc db 28 b4 a0 d1 	movabs r12,0xe7037ed1a0b428db
  5e:	7e 03 e7 
  61:	31 f6                	xor    esi,esi
  63:	eb 26                	jmp    0x8b
  65:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  6c:	00 00 00 00 
  70:	49 c1 e7 20          	shl    r15,0x20
  74:	4d 09 f9             	or     r9,r15
  77:	4d 31 cc             	xor    r12,r9
  7a:	48 83 c2 20          	add    rdx,0x20
  7e:	48 ff c6             	inc    rsi
  81:	48 83 fe 20          	cmp    rsi,0x20
  85:	0f 84 cb 02 00 00    	je     0x356
  8b:	44 0f b6 7a 06       	movzx  r15d,BYTE PTR [rdx+0x6]
  90:	41 c1 e7 08          	shl    r15d,0x8
  94:	44 0f b6 72 05       	movzx  r14d,BYTE PTR [rdx+0x5]
  99:	4d 09 f7             	or     r15,r14
  9c:	49 83 ff 04          	cmp    r15,0x4
  a0:	76 2e                	jbe    0xd0
  a2:	41 b0 01             	mov    r8b,0x1
  a5:	49 83 ff 05          	cmp    r15,0x5
  a9:	74 75                	je     0x120
  ab:	41 83 ff 09          	cmp    r15d,0x9
  af:	74 63                	je     0x114
  b1:	49 bb 00 00 00 00 00 	movabs r11,0x59000000000000
  b8:	00 59 00 
  bb:	41 83 ff 0d          	cmp    r15d,0xd
  bf:	74 6f                	je     0x130
  c1:	eb 3d                	jmp    0x100
  c3:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  ca:	84 00 00 00 00 00 
  d0:	44 89 f0             	mov    eax,r14d
  d3:	24 07                	and    al,0x7
  d5:	41 b0 01             	mov    r8b,0x1
  d8:	3c 01                	cmp    al,0x1
  da:	74 2c                	je     0x108
  dc:	44 89 f0             	mov    eax,r14d
  df:	83 e0 07             	and    eax,0x7
  e2:	83 f8 02             	cmp    eax,0x2
  e5:	75 19                	jne    0x100
  e7:	49 bb 00 00 00 00 00 	movabs r11,0x23000000000000
  ee:	00 23 00 
  f1:	eb 3d                	jmp    0x130
  f3:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  fa:	84 00 00 00 00 00 
 100:	45 31 c0             	xor    r8d,r8d
 103:	45 31 db             	xor    r11d,r11d
 106:	eb 28                	jmp    0x130
 108:	49 bb 00 00 00 00 00 	movabs r11,0x11000000000000
 10f:	00 11 00 
 112:	eb 1c                	jmp    0x130
 114:	49 bb 00 00 00 00 00 	movabs r11,0x41000000000000
 11b:	00 41 00 
 11e:	eb 10                	jmp    0x130
 120:	49 bb 00 00 00 00 00 	movabs r11,0x37000000000000
 127:	00 37 00 
 12a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
 130:	0f b7 4a 11          	movzx  ecx,WORD PTR [rdx+0x11]
 134:	0f b6 42 16          	movzx  eax,BYTE PTR [rdx+0x16]
 138:	48 c1 e0 28          	shl    rax,0x28
 13c:	44 0f b6 6a 15       	movzx  r13d,BYTE PTR [rdx+0x15]
 141:	49 c1 e5 20          	shl    r13,0x20
 145:	49 09 c5             	or     r13,rax
 148:	0f b6 42 13          	movzx  eax,BYTE PTR [rdx+0x13]
 14c:	c1 e0 10             	shl    eax,0x10
 14f:	48 09 c8             	or     rax,rcx
 152:	0f b6 4a 14          	movzx  ecx,BYTE PTR [rdx+0x14]
 156:	c1 e1 18             	shl    ecx,0x18
 159:	48 09 c1             	or     rcx,rax
 15c:	49 09 cd             	or     r13,rcx
 15f:	48 81 f9 62 61 73 68 	cmp    rcx,0x68736162
 166:	74 18                	je     0x180
 168:	81 f9 63 75 72 6c    	cmp    ecx,0x6c727563
 16e:	75 20                	jne    0x190
 170:	b9 02 00 00 00       	mov    ecx,0x2
 175:	eb 49                	jmp    0x1c0
 177:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
 17e:	00 00 
 180:	b9 01 00 00 00       	mov    ecx,0x1
 185:	eb 39                	jmp    0x1c0
 187:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
 18e:	00 00 
 190:	b9 03 00 00 00       	mov    ecx,0x3
 195:	48 bf 70 79 74 68 6f 	movabs rdi,0x6e6f68747970
 19c:	6e 00 00 
 19f:	49 39 fd             	cmp    r13,rdi
 1a2:	74 1c                	je     0x1c0
 1a4:	31 c9                	xor    ecx,ecx
 1a6:	3d 73 68 00 00       	cmp    eax,0x6873
 1ab:	0f 94 c1             	sete   cl
 1ae:	c1 e1 02             	shl    ecx,0x2
 1b1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 1b8:	0f 1f 84 00 00 00 00 
 1bf:	00 
 1c0:	44 8b 4a f9          	mov    r9d,DWORD PTR [rdx-0x7]
 1c4:	45 84 c0             	test   r8b,r8b
 1c7:	0f 84 a3 fe ff ff    	je     0x70
 1cd:	0f b6 42 09          	movzx  eax,BYTE PTR [rdx+0x9]
 1d1:	48 89 44 24 d0       	mov    QWORD PTR [rsp-0x30],rax
 1d6:	0f b6 42 0a          	movzx  eax,BYTE PTR [rdx+0xa]
 1da:	44 0f b6 52 0c       	movzx  r10d,BYTE PTR [rdx+0xc]
 1df:	0f b6 7a 0b          	movzx  edi,BYTE PTR [rdx+0xb]
 1e3:	48 89 7c 24 d8       	mov    QWORD PTR [rsp-0x28],rdi
 1e8:	0f b6 7a 0e          	movzx  edi,BYTE PTR [rdx+0xe]
 1ec:	48 89 7c 24 e0       	mov    QWORD PTR [rsp-0x20],rdi
 1f1:	0f b6 7a 0d          	movzx  edi,BYTE PTR [rdx+0xd]
 1f5:	48 89 7c 24 f0       	mov    QWORD PTR [rsp-0x10],rdi
 1fa:	0f b6 7a 01          	movzx  edi,BYTE PTR [rdx+0x1]
 1fe:	44 0f b6 42 10       	movzx  r8d,BYTE PTR [rdx+0x10]
 203:	4c 89 44 24 e8       	mov    QWORD PTR [rsp-0x18],r8
 208:	44 0f b6 42 0f       	movzx  r8d,BYTE PTR [rdx+0xf]
 20d:	4c 89 44 24 f8       	mov    QWORD PTR [rsp-0x8],r8
 212:	44 0f b6 42 18       	movzx  r8d,BYTE PTR [rdx+0x18]
 217:	4c 89 44 24 c8       	mov    QWORD PTR [rsp-0x38],r8
 21c:	0f b6 6a 17          	movzx  ebp,BYTE PTR [rdx+0x17]
 220:	0f b6 5a 07          	movzx  ebx,BYTE PTR [rdx+0x7]
 224:	44 8b 7a fd          	mov    r15d,DWORD PTR [rdx-0x3]
 228:	48 83 ff 42          	cmp    rdi,0x42
 22c:	74 42                	je     0x270
 22e:	41 89 c0             	mov    r8d,eax
 231:	41 83 e0 24          	and    r8d,0x24
 235:	75 39                	jne    0x270
 237:	0f b6 42 02          	movzx  eax,BYTE PTR [rdx+0x2]
 23b:	c1 e0 08             	shl    eax,0x8
 23e:	48 09 f8             	or     rax,rdi
 241:	0f b6 4a 03          	movzx  ecx,BYTE PTR [rdx+0x3]
 245:	c1 e1 10             	shl    ecx,0x10
 248:	48 09 c1             	or     rcx,rax
 24b:	0f b6 42 04          	movzx  eax,BYTE PTR [rdx+0x4]
 24f:	c1 e0 18             	shl    eax,0x18
 252:	48 09 c8             	or     rax,rcx
 255:	49 c1 e7 10          	shl    r15,0x10
 259:	49 31 c7             	xor    r15,rax
 25c:	4d 01 fc             	add    r12,r15
 25f:	e9 16 fe ff ff       	jmp    0x7a
 264:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 26b:	00 00 00 00 00 
 270:	4c 89 64 24 b8       	mov    QWORD PTR [rsp-0x48],r12
 275:	44 0f b6 42 08       	movzx  r8d,BYTE PTR [rdx+0x8]
 27a:	48 89 cf             	mov    rdi,rcx
 27d:	48 c1 e7 28          	shl    rdi,0x28
 281:	4c 09 df             	or     rdi,r11
 284:	49 c1 e0 20          	shl    r8,0x20
 288:	41 89 dc             	mov    r12d,ebx
 28b:	41 c1 e4 18          	shl    r12d,0x18
 28f:	4d 09 c4             	or     r12,r8
 292:	4c 09 cf             	or     rdi,r9
 295:	4c 09 e7             	or     rdi,r12
 298:	48 85 c9             	test   rcx,rcx
 29b:	74 36                	je     0x2d3
 29d:	89 d9                	mov    ecx,ebx
 29f:	83 e1 02             	and    ecx,0x2
 2a2:	74 2f                	je     0x2d3
 2a4:	48 8b 4c 24 c8       	mov    rcx,QWORD PTR [rsp-0x38]
 2a9:	48 c1 e1 38          	shl    rcx,0x38
 2ad:	48 c1 e5 30          	shl    rbp,0x30
 2b1:	48 09 cd             	or     rbp,rcx
 2b4:	4c 09 ed             	or     rbp,r13
 2b7:	41 80 e6 07          	and    r14b,0x7
 2bb:	44 89 f1             	mov    ecx,r14d
 2be:	f6 d1                	not    cl
 2c0:	c4 e2 f3 f7 cd       	shrx   rcx,rbp,rcx
 2c5:	41 fe c6             	inc    r14b
 2c8:	c4 62 89 f7 c5       	shlx   r8,rbp,r14
 2cd:	49 09 c8             	or     r8,rcx
 2d0:	4c 31 c7             	xor    rdi,r8
 2d3:	4c 8b 64 24 b8       	mov    r12,QWORD PTR [rsp-0x48]
 2d8:	c1 e0 08             	shl    eax,0x8
 2db:	48 03 44 24 d0       	add    rax,QWORD PTR [rsp-0x30]
 2e0:	41 c1 e2 18          	shl    r10d,0x18
 2e4:	49 09 c2             	or     r10,rax
 2e7:	4c 8b 44 24 d8       	mov    r8,QWORD PTR [rsp-0x28]
 2ec:	41 c1 e0 10          	shl    r8d,0x10
 2f0:	4d 09 d0             	or     r8,r10
 2f3:	48 8b 4c 24 e0       	mov    rcx,QWORD PTR [rsp-0x20]
 2f8:	48 c1 e1 28          	shl    rcx,0x28
 2fc:	4c 09 c1             	or     rcx,r8
 2ff:	48 8b 44 24 f0       	mov    rax,QWORD PTR [rsp-0x10]
 304:	48 c1 e0 20          	shl    rax,0x20
 308:	48 09 c8             	or     rax,rcx
 30b:	48 8b 4c 24 e8       	mov    rcx,QWORD PTR [rsp-0x18]
 310:	48 c1 e1 38          	shl    rcx,0x38
 314:	48 09 c1             	or     rcx,rax
 317:	48 8b 44 24 f8       	mov    rax,QWORD PTR [rsp-0x8]
 31c:	48 c1 e0 30          	shl    rax,0x30
 320:	48 09 c8             	or     rax,rcx
 323:	49 31 c7             	xor    r15,rax
 326:	48 c1 e3 3d          	shl    rbx,0x3d
 32a:	48 c1 fb 3f          	sar    rbx,0x3f
 32e:	4c 21 fb             	and    rbx,r15
 331:	48 01 fb             	add    rbx,rdi
 334:	89 f0                	mov    eax,esi
 336:	24 07                	and    al,0x7
 338:	89 c1                	mov    ecx,eax
 33a:	f6 d1                	not    cl
 33c:	c4 e2 f3 f7 cb       	shrx   rcx,rbx,rcx
 341:	fe c0                	inc    al
 343:	c4 e2 f9 f7 c3       	shlx   rax,rbx,rax
 348:	48 09 c8             	or     rax,rcx
 34b:	49 31 c4             	xor    r12,rax
 34e:	e9 27 fd ff ff       	jmp    0x7a
 353:	31 c0                	xor    eax,eax
 355:	c3                   	ret
 356:	48 8b 44 24 c0       	mov    rax,QWORD PTR [rsp-0x40]
 35b:	4c 89 20             	mov    QWORD PTR [rax],r12
 35e:	b8 02 00 00 00       	mov    eax,0x2
 363:	5b                   	pop    rbx
 364:	41 5c                	pop    r12
 366:	41 5d                	pop    r13
 368:	41 5e                	pop    r14
 36a:	41 5f                	pop    r15
 36c:	5d                   	pop    rbp
 36d:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
