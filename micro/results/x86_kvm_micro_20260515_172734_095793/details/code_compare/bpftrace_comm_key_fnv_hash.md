# bpftrace_comm_key_fnv_hash

## Original C
```c
#include "common.h"

#define BPFTRACE_COMM_KEY_RECORDS 32U
#define BPFTRACE_COMM_KEY_RECORD_SIZE 32U
#define BPFTRACE_COMM_KEY_INPUT_SIZE \
    (8U + BPFTRACE_COMM_KEY_RECORDS * BPFTRACE_COMM_KEY_RECORD_SIZE)
#define BPFTRACE_FNV_OFFSET 14695981039346656037ULL
#define BPFTRACE_FNV_PRIME 1099511628211ULL

static __always_inline u64 bpftrace_fnv1a_byte(u64 hash, u8 value)
{
    return (hash ^ value) * BPFTRACE_FNV_PRIME;
}

static __always_inline u64 bpftrace_fnv1a_u32(u64 hash, u32 value)
{
    hash = bpftrace_fnv1a_byte(hash, value & 0xFFU);
    hash = bpftrace_fnv1a_byte(hash, (value >> 8U) & 0xFFU);
    hash = bpftrace_fnv1a_byte(hash, (value >> 16U) & 0xFFU);
    return bpftrace_fnv1a_byte(hash, (value >> 24U) & 0xFFU);
}

static __always_inline int
bench_bpftrace_comm_key_fnv_hash(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BPFTRACE_COMM_KEY_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != BPFTRACE_COMM_KEY_RECORDS ||
        record_size != BPFTRACE_COMM_KEY_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0x94D049BB133111EBULL;
    for (u32 index = 0; index < BPFTRACE_COMM_KEY_RECORDS; index++) {
        u32 base = 8U + index * BPFTRACE_COMM_KEY_RECORD_SIZE;
        u32 pid = micro_read_u32_le(data, base);
        u32 tgid = micro_read_u32_le(data, base + 4U);
        u32 probe_id = micro_read_u32_le(data, base + 8U);
        u32 flags = micro_read_u32_le(data, base + 12U);
        u64 hash = BPFTRACE_FNV_OFFSET;

        hash = bpftrace_fnv1a_u32(hash, pid);
        hash = bpftrace_fnv1a_u32(hash, tgid);
        hash = bpftrace_fnv1a_u32(hash, probe_id);
        for (u32 byte = 0; byte < 16U; byte++) {
            hash = bpftrace_fnv1a_byte(hash, data[base + 16U + byte]);
        }

        if ((flags & 1U) != 0U) {
            hash ^= micro_rotl64(((u64)pid << 32U) | tgid,
                                 (probe_id & 7U) + 1U);
        }
        if ((flags & 2U) != 0U && data[base + 16U] == 'p') {
            hash += 0x9E3779B185EBCA87ULL;
        }

        acc ^= micro_rotl64(hash, (index & 7U) + 1U);
        acc += ((u64)(flags & 0xFFU) << 56U) ^ probe_id;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bpftrace_comm_key_fnv_hash_xdp,
    bench_bpftrace_comm_key_fnv_hash,
    bpftrace_comm_key_fnv_hash_input_value,
    BPFTRACE_COMM_KEY_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <bpftrace_comm_key_fnv_hash_xdp>:
    1100:	4c 8b 07             	mov    r8,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	49 39 c8             	cmp    r8,rcx
    110c:	76 01                	jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf>
    110e:	c3                   	ret
    110f:	49 8d 50 08          	lea    rdx,[r8+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe>
    1118:	49 8d 90 10 04 00 00 	lea    rdx,[r8+0x410]
    111f:	48 39 ca             	cmp    rdx,rcx
    1122:	77 ea                	ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe>
    1124:	41 83 78 08 20       	cmp    DWORD PTR [r8+0x8],0x20
    1129:	75 e3                	jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe>
    112b:	41 83 78 0c 20       	cmp    DWORD PTR [r8+0xc],0x20
    1130:	75 dc                	jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe>
    1132:	55                   	push   rbp
    1133:	41 57                	push   r15
    1135:	41 56                	push   r14
    1137:	41 55                	push   r13
    1139:	41 54                	push   r12
    113b:	53                   	push   rbx
    113c:	4c 89 44 24 c0       	mov    QWORD PTR [rsp-0x40],r8
    1141:	49 8d 78 2f          	lea    rdi,[r8+0x2f]
    1145:	48 be eb 11 31 13 bb 	movabs rsi,0x94d049bb133111eb
    114c:	49 d0 94 
    114f:	45 31 c0             	xor    r8d,r8d
    1152:	49 ba b3 01 00 00 00 	movabs r10,0x100000001b3
    1159:	01 00 00 
    115c:	eb 51                	jmp    11af <bpftrace_comm_key_fnv_hash_xdp+0xaf>
    115e:	66 90                	xchg   ax,ax
    1160:	41 c1 e4 08          	shl    r12d,0x8
    1164:	41 c1 e7 10          	shl    r15d,0x10
    1168:	45 09 e7             	or     r15d,r12d
    116b:	c1 e3 18             	shl    ebx,0x18
    116e:	44 89 c0             	mov    eax,r8d
    1171:	24 07                	and    al,0x7
    1173:	8d 48 01             	lea    ecx,[rax+0x1]
    1176:	4c 89 da             	mov    rdx,r11
    1179:	48 d3 e2             	shl    rdx,cl
    117c:	f6 d0                	not    al
    117e:	89 c1                	mov    ecx,eax
    1180:	49 d3 eb             	shr    r11,cl
    1183:	44 09 fb             	or     ebx,r15d
    1186:	44 09 cb             	or     ebx,r9d
    1189:	49 09 d3             	or     r11,rdx
    118c:	48 89 f0             	mov    rax,rsi
    118f:	4c 31 d8             	xor    rax,r11
    1192:	49 c1 e6 38          	shl    r14,0x38
    1196:	89 de                	mov    esi,ebx
    1198:	4c 09 f6             	or     rsi,r14
    119b:	48 01 c6             	add    rsi,rax
    119e:	49 ff c0             	inc    r8
    11a1:	48 83 c7 20          	add    rdi,0x20
    11a5:	49 83 f8 20          	cmp    r8,0x20
    11a9:	0f 84 2b 02 00 00    	je     13da <bpftrace_comm_key_fnv_hash_xdp+0x2da>
    11af:	4c 89 44 24 f8       	mov    QWORD PTR [rsp-0x8],r8
    11b4:	44 0f b6 6f e1       	movzx  r13d,BYTE PTR [rdi-0x1f]
    11b9:	44 0f b6 4f e2       	movzx  r9d,BYTE PTR [rdi-0x1e]
    11be:	0f b6 47 e3          	movzx  eax,BYTE PTR [rdi-0x1d]
    11c2:	0f b6 57 e4          	movzx  edx,BYTE PTR [rdi-0x1c]
    11c6:	0f b6 6f e5          	movzx  ebp,BYTE PTR [rdi-0x1b]
    11ca:	0f b6 4f e6          	movzx  ecx,BYTE PTR [rdi-0x1a]
    11ce:	48 89 4c 24 f0       	mov    QWORD PTR [rsp-0x10],rcx
    11d3:	0f b6 4f e7          	movzx  ecx,BYTE PTR [rdi-0x19]
    11d7:	48 89 4c 24 e8       	mov    QWORD PTR [rsp-0x18],rcx
    11dc:	44 0f b6 47 e8       	movzx  r8d,BYTE PTR [rdi-0x18]
    11e1:	44 0f b6 77 e9       	movzx  r14d,BYTE PTR [rdi-0x17]
    11e6:	44 0f b6 67 ea       	movzx  r12d,BYTE PTR [rdi-0x16]
    11eb:	44 0f b6 7f eb       	movzx  r15d,BYTE PTR [rdi-0x15]
    11f0:	0f b6 5f ec          	movzx  ebx,BYTE PTR [rdi-0x14]
    11f4:	4d 89 eb             	mov    r11,r13
    11f7:	48 b9 25 23 22 84 e4 	movabs rcx,0xcbf29ce484222325
    11fe:	9c f2 cb 
    1201:	49 31 cb             	xor    r11,rcx
    1204:	4d 0f af da          	imul   r11,r10
    1208:	4c 89 4c 24 c8       	mov    QWORD PTR [rsp-0x38],r9
    120d:	4d 31 cb             	xor    r11,r9
    1210:	4d 89 c1             	mov    r9,r8
    1213:	4c 8b 44 24 e8       	mov    r8,QWORD PTR [rsp-0x18]
    1218:	4d 0f af da          	imul   r11,r10
    121c:	48 89 44 24 d8       	mov    QWORD PTR [rsp-0x28],rax
    1221:	49 31 c3             	xor    r11,rax
    1224:	4d 0f af da          	imul   r11,r10
    1228:	48 89 54 24 d0       	mov    QWORD PTR [rsp-0x30],rdx
    122d:	49 31 d3             	xor    r11,rdx
    1230:	4d 0f af da          	imul   r11,r10
    1234:	48 89 6c 24 e0       	mov    QWORD PTR [rsp-0x20],rbp
    1239:	49 31 eb             	xor    r11,rbp
    123c:	48 8b 6c 24 f0       	mov    rbp,QWORD PTR [rsp-0x10]
    1241:	4d 0f af da          	imul   r11,r10
    1245:	49 31 eb             	xor    r11,rbp
    1248:	4d 0f af da          	imul   r11,r10
    124c:	4d 31 c3             	xor    r11,r8
    124f:	4d 0f af da          	imul   r11,r10
    1253:	4d 31 cb             	xor    r11,r9
    1256:	4d 0f af da          	imul   r11,r10
    125a:	4c 89 74 24 b8       	mov    QWORD PTR [rsp-0x48],r14
    125f:	4d 31 f3             	xor    r11,r14
    1262:	4d 0f af da          	imul   r11,r10
    1266:	4d 31 e3             	xor    r11,r12
    1269:	4d 0f af da          	imul   r11,r10
    126d:	4d 31 fb             	xor    r11,r15
    1270:	4d 0f af da          	imul   r11,r10
    1274:	49 89 de             	mov    r14,rbx
    1277:	4d 31 de             	xor    r14,r11
    127a:	4d 0f af f2          	imul   r14,r10
    127e:	44 0f b6 5f f1       	movzx  r11d,BYTE PTR [rdi-0xf]
    1283:	4d 31 f3             	xor    r11,r14
    1286:	4d 0f af da          	imul   r11,r10
    128a:	44 0f b6 77 f2       	movzx  r14d,BYTE PTR [rdi-0xe]
    128f:	4d 31 de             	xor    r14,r11
    1292:	4d 0f af f2          	imul   r14,r10
    1296:	44 0f b6 5f f3       	movzx  r11d,BYTE PTR [rdi-0xd]
    129b:	4d 31 f3             	xor    r11,r14
    129e:	4d 0f af da          	imul   r11,r10
    12a2:	44 0f b6 77 f4       	movzx  r14d,BYTE PTR [rdi-0xc]
    12a7:	4d 31 de             	xor    r14,r11
    12aa:	4d 0f af f2          	imul   r14,r10
    12ae:	44 0f b6 5f f5       	movzx  r11d,BYTE PTR [rdi-0xb]
    12b3:	4d 31 f3             	xor    r11,r14
    12b6:	4d 0f af da          	imul   r11,r10
    12ba:	44 0f b6 77 f6       	movzx  r14d,BYTE PTR [rdi-0xa]
    12bf:	4d 31 de             	xor    r14,r11
    12c2:	4d 0f af f2          	imul   r14,r10
    12c6:	44 0f b6 5f f7       	movzx  r11d,BYTE PTR [rdi-0x9]
    12cb:	4d 31 f3             	xor    r11,r14
    12ce:	4d 0f af da          	imul   r11,r10
    12d2:	44 0f b6 77 f8       	movzx  r14d,BYTE PTR [rdi-0x8]
    12d7:	4d 31 de             	xor    r14,r11
    12da:	4d 0f af f2          	imul   r14,r10
    12de:	44 0f b6 5f f9       	movzx  r11d,BYTE PTR [rdi-0x7]
    12e3:	4d 31 f3             	xor    r11,r14
    12e6:	4d 0f af da          	imul   r11,r10
    12ea:	44 0f b6 77 fa       	movzx  r14d,BYTE PTR [rdi-0x6]
    12ef:	4d 31 de             	xor    r14,r11
    12f2:	4d 0f af f2          	imul   r14,r10
    12f6:	44 0f b6 5f fb       	movzx  r11d,BYTE PTR [rdi-0x5]
    12fb:	4d 31 f3             	xor    r11,r14
    12fe:	4d 0f af da          	imul   r11,r10
    1302:	44 0f b6 77 fc       	movzx  r14d,BYTE PTR [rdi-0x4]
    1307:	4d 31 de             	xor    r14,r11
    130a:	4d 0f af f2          	imul   r14,r10
    130e:	44 0f b6 5f fd       	movzx  r11d,BYTE PTR [rdi-0x3]
    1313:	4d 31 f3             	xor    r11,r14
    1316:	4d 0f af da          	imul   r11,r10
    131a:	44 0f b6 77 fe       	movzx  r14d,BYTE PTR [rdi-0x2]
    131f:	4d 31 de             	xor    r14,r11
    1322:	4d 0f af f2          	imul   r14,r10
    1326:	0f b6 4f ff          	movzx  ecx,BYTE PTR [rdi-0x1]
    132a:	4c 31 f1             	xor    rcx,r14
    132d:	49 0f af ca          	imul   rcx,r10
    1331:	44 0f b6 1f          	movzx  r11d,BYTE PTR [rdi]
    1335:	49 31 cb             	xor    r11,rcx
    1338:	44 0f b6 77 ed       	movzx  r14d,BYTE PTR [rdi-0x13]
    133d:	4d 0f af da          	imul   r11,r10
    1341:	41 f6 c6 01          	test   r14b,0x1
    1345:	75 09                	jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250>
    1347:	4c 8b 4c 24 b8       	mov    r9,QWORD PTR [rsp-0x48]
    134c:	eb 63                	jmp    13b1 <bpftrace_comm_key_fnv_hash_xdp+0x2b1>
    134e:	66 90                	xchg   ax,ax
    1350:	41 c1 e1 18          	shl    r9d,0x18
    1354:	41 c1 e0 10          	shl    r8d,0x10
    1358:	c1 e5 08             	shl    ebp,0x8
    135b:	48 8b 44 24 d8       	mov    rax,QWORD PTR [rsp-0x28]
    1360:	48 c1 e0 30          	shl    rax,0x30
    1364:	48 8b 4c 24 d0       	mov    rcx,QWORD PTR [rsp-0x30]
    1369:	48 c1 e1 38          	shl    rcx,0x38
    136d:	48 8b 54 24 c8       	mov    rdx,QWORD PTR [rsp-0x38]
    1372:	48 c1 e2 28          	shl    rdx,0x28
    1376:	49 c1 e5 20          	shl    r13,0x20
    137a:	49 09 d5             	or     r13,rdx
    137d:	49 09 c5             	or     r13,rax
    1380:	49 09 cd             	or     r13,rcx
    1383:	49 09 ed             	or     r13,rbp
    1386:	4d 09 c5             	or     r13,r8
    1389:	4d 09 cd             	or     r13,r9
    138c:	4c 0b 6c 24 e0       	or     r13,QWORD PTR [rsp-0x20]
    1391:	4c 8b 4c 24 b8       	mov    r9,QWORD PTR [rsp-0x48]
    1396:	44 89 c8             	mov    eax,r9d
    1399:	24 07                	and    al,0x7
    139b:	8d 48 01             	lea    ecx,[rax+0x1]
    139e:	4c 89 ea             	mov    rdx,r13
    13a1:	48 d3 e2             	shl    rdx,cl
    13a4:	f6 d0                	not    al
    13a6:	89 c1                	mov    ecx,eax
    13a8:	49 d3 ed             	shr    r13,cl
    13ab:	49 09 d5             	or     r13,rdx
    13ae:	4d 31 eb             	xor    r11,r13
    13b1:	41 f6 c6 02          	test   r14b,0x2
    13b5:	4c 8b 44 24 f8       	mov    r8,QWORD PTR [rsp-0x8]
    13ba:	0f 84 a0 fd ff ff    	je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60>
    13c0:	48 b8 87 ca eb 85 b1 	movabs rax,0x9e3779b185ebca87
    13c7:	79 37 9e 
    13ca:	4c 01 d8             	add    rax,r11
    13cd:	80 7f f1 70          	cmp    BYTE PTR [rdi-0xf],0x70
    13d1:	4c 0f 44 d8          	cmove  r11,rax
    13d5:	e9 86 fd ff ff       	jmp    1160 <bpftrace_comm_key_fnv_hash_xdp+0x60>
    13da:	48 8b 44 24 c0       	mov    rax,QWORD PTR [rsp-0x40]
    13df:	48 89 30             	mov    QWORD PTR [rax],rsi
    13e2:	b8 02 00 00 00       	mov    eax,0x2
    13e7:	5b                   	pop    rbx
    13e8:	41 5c                	pop    r12
    13ea:	41 5d                	pop    r13
    13ec:	41 5e                	pop    r14
    13ee:	41 5f                	pop    r15
    13f0:	5d                   	pop    rbp
    13f1:	c3                   	ret

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
   c:	48 81 ec 58 00 00 00 	sub    rsp,0x58
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 ac 03 00 00    	ja     0x3d9
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 9c 03 00 00    	ja     0x3d9
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 89 03 00 00    	ja     0x3d9
  50:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 83 ff 20          	cmp    rdi,0x20
  85:	0f 85 4e 03 00 00    	jne    0x3d9
  8b:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
  90:	48 c1 e7 08          	shl    rdi,0x8
  94:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
  99:	48 09 f7             	or     rdi,rsi
  9c:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
  a1:	48 c1 e6 10          	shl    rsi,0x10
  a5:	48 09 f7             	or     rdi,rsi
  a8:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
  ad:	48 c1 e6 18          	shl    rsi,0x18
  b1:	48 09 f7             	or     rdi,rsi
  b4:	48 c1 e7 20          	shl    rdi,0x20
  b8:	48 c1 ef 20          	shr    rdi,0x20
  bc:	48 83 ff 20          	cmp    rdi,0x20
  c0:	0f 85 13 03 00 00    	jne    0x3d9
  c6:	48 be eb 11 31 13 bb 	movabs rsi,0x94d049bb133111eb
  cd:	49 d0 94 
  d0:	31 d2                	xor    edx,edx
  d2:	48 89 4d a8          	mov    QWORD PTR [rbp-0x58],rcx
  d6:	48 83 c1 17          	add    rcx,0x17
  da:	48 b8 b3 01 00 00 00 	movabs rax,0x100000001b3
  e1:	01 00 00 
  e4:	eb 66                	jmp    0x14c
  e6:	48 8b 7d e0          	mov    rdi,QWORD PTR [rbp-0x20]
  ea:	48 c1 e7 10          	shl    rdi,0x10
  ee:	49 c1 e6 08          	shl    r14,0x8
  f2:	49 09 fe             	or     r14,rdi
  f5:	48 8b 7d e8          	mov    rdi,QWORD PTR [rbp-0x18]
  f9:	48 c1 e7 18          	shl    rdi,0x18
  fd:	49 09 fe             	or     r14,rdi
 100:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 104:	49 09 fe             	or     r14,rdi
 107:	48 89 d7             	mov    rdi,rdx
 10a:	48 83 e7 07          	and    rdi,0x7
 10e:	49 89 f8             	mov    r8,rdi
 111:	49 83 f0 3f          	xor    r8,0x3f
 115:	48 89 f3             	mov    rbx,rsi
 118:	c4 e2 bb f7 db       	shrx   rbx,rbx,r8
 11d:	48 83 c7 01          	add    rdi,0x1
 121:	c4 e2 c1 f7 f6       	shlx   rsi,rsi,rdi
 126:	48 09 de             	or     rsi,rbx
 129:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 12d:	48 31 fe             	xor    rsi,rdi
 130:	49 c1 e7 38          	shl    r15,0x38
 134:	4d 09 f7             	or     r15,r14
 137:	4c 01 fe             	add    rsi,r15
 13a:	48 83 c1 20          	add    rcx,0x20
 13e:	48 83 c2 01          	add    rdx,0x1
 142:	48 83 fa 20          	cmp    rdx,0x20
 146:	0f 84 36 02 00 00    	je     0x382
 14c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
 150:	4c 0f b6 69 03       	movzx  r13,BYTE PTR [rcx+0x3]
 155:	4c 0f b6 71 02       	movzx  r14,BYTE PTR [rcx+0x2]
 15a:	4c 0f b6 79 04       	movzx  r15,BYTE PTR [rcx+0x4]
 15f:	4c 0f b6 41 f9       	movzx  r8,BYTE PTR [rcx-0x7]
 164:	4c 89 c6             	mov    rsi,r8
 167:	48 bf 25 23 22 84 e4 	movabs rdi,0xcbf29ce484222325
 16e:	9c f2 cb 
 171:	48 31 fe             	xor    rsi,rdi
 174:	48 0f af f0          	imul   rsi,rax
 178:	48 0f b6 79 fa       	movzx  rdi,BYTE PTR [rcx-0x6]
 17d:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 181:	48 31 fe             	xor    rsi,rdi
 184:	48 0f af f0          	imul   rsi,rax
 188:	48 0f b6 79 fb       	movzx  rdi,BYTE PTR [rcx-0x5]
 18d:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 191:	48 31 fe             	xor    rsi,rdi
 194:	48 0f af f0          	imul   rsi,rax
 198:	48 0f b6 79 fc       	movzx  rdi,BYTE PTR [rcx-0x4]
 19d:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 1a1:	48 31 fe             	xor    rsi,rdi
 1a4:	48 0f af f0          	imul   rsi,rax
 1a8:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
 1ad:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 1b1:	48 31 fe             	xor    rsi,rdi
 1b4:	48 0f af f0          	imul   rsi,rax
 1b8:	48 0f b6 79 fe       	movzx  rdi,BYTE PTR [rcx-0x2]
 1bd:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 1c1:	48 31 fe             	xor    rsi,rdi
 1c4:	48 0f af f0          	imul   rsi,rax
 1c8:	48 0f b6 59 ff       	movzx  rbx,BYTE PTR [rcx-0x1]
 1cd:	48 31 de             	xor    rsi,rbx
 1d0:	48 0f af f0          	imul   rsi,rax
 1d4:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 1d9:	48 89 7d b0          	mov    QWORD PTR [rbp-0x50],rdi
 1dd:	48 31 fe             	xor    rsi,rdi
 1e0:	48 0f af f0          	imul   rsi,rax
 1e4:	48 0f b6 79 01       	movzx  rdi,BYTE PTR [rcx+0x1]
 1e9:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
 1ed:	48 31 fe             	xor    rsi,rdi
 1f0:	48 0f af f0          	imul   rsi,rax
 1f4:	4c 31 f6             	xor    rsi,r14
 1f7:	48 0f af f0          	imul   rsi,rax
 1fb:	4c 89 6d e0          	mov    QWORD PTR [rbp-0x20],r13
 1ff:	4c 31 ee             	xor    rsi,r13
 202:	48 0f af f0          	imul   rsi,rax
 206:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 20a:	4c 31 fe             	xor    rsi,r15
 20d:	48 0f af f0          	imul   rsi,rax
 211:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 216:	48 31 fe             	xor    rsi,rdi
 219:	48 0f af f0          	imul   rsi,rax
 21d:	48 0f b6 79 0a       	movzx  rdi,BYTE PTR [rcx+0xa]
 222:	48 31 fe             	xor    rsi,rdi
 225:	48 0f af f0          	imul   rsi,rax
 229:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 22e:	48 31 fe             	xor    rsi,rdi
 231:	48 0f af f0          	imul   rsi,rax
 235:	48 0f b6 79 0c       	movzx  rdi,BYTE PTR [rcx+0xc]
 23a:	48 31 fe             	xor    rsi,rdi
 23d:	48 0f af f0          	imul   rsi,rax
 241:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
 246:	48 31 fe             	xor    rsi,rdi
 249:	48 0f af f0          	imul   rsi,rax
 24d:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 252:	48 31 fe             	xor    rsi,rdi
 255:	48 0f af f0          	imul   rsi,rax
 259:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
 25e:	48 31 fe             	xor    rsi,rdi
 261:	48 0f af f0          	imul   rsi,rax
 265:	48 0f b6 79 10       	movzx  rdi,BYTE PTR [rcx+0x10]
 26a:	48 31 fe             	xor    rsi,rdi
 26d:	48 0f af f0          	imul   rsi,rax
 271:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 276:	48 31 fe             	xor    rsi,rdi
 279:	48 0f af f0          	imul   rsi,rax
 27d:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 282:	48 31 fe             	xor    rsi,rdi
 285:	48 0f af f0          	imul   rsi,rax
 289:	48 0f b6 79 13       	movzx  rdi,BYTE PTR [rcx+0x13]
 28e:	48 31 fe             	xor    rsi,rdi
 291:	48 0f af f0          	imul   rsi,rax
 295:	48 0f b6 79 14       	movzx  rdi,BYTE PTR [rcx+0x14]
 29a:	48 31 fe             	xor    rsi,rdi
 29d:	48 0f af f0          	imul   rsi,rax
 2a1:	48 0f b6 79 15       	movzx  rdi,BYTE PTR [rcx+0x15]
 2a6:	48 31 fe             	xor    rsi,rdi
 2a9:	48 0f af f0          	imul   rsi,rax
 2ad:	48 0f b6 79 16       	movzx  rdi,BYTE PTR [rcx+0x16]
 2b2:	48 31 fe             	xor    rsi,rdi
 2b5:	48 0f af f0          	imul   rsi,rax
 2b9:	48 0f b6 79 17       	movzx  rdi,BYTE PTR [rcx+0x17]
 2be:	48 31 fe             	xor    rsi,rdi
 2c1:	48 0f af f0          	imul   rsi,rax
 2c5:	48 0f b6 79 18       	movzx  rdi,BYTE PTR [rcx+0x18]
 2ca:	48 31 fe             	xor    rsi,rdi
 2cd:	48 0f af f0          	imul   rsi,rax
 2d1:	4c 0f b6 79 05       	movzx  r15,BYTE PTR [rcx+0x5]
 2d6:	4c 89 ff             	mov    rdi,r15
 2d9:	48 83 e7 01          	and    rdi,0x1
 2dd:	48 85 ff             	test   rdi,rdi
 2e0:	74 6f                	je     0x351
 2e2:	49 c1 e0 20          	shl    r8,0x20
 2e6:	48 8b 7d c0          	mov    rdi,QWORD PTR [rbp-0x40]
 2ea:	48 c1 e7 30          	shl    rdi,0x30
 2ee:	49 09 f8             	or     r8,rdi
 2f1:	48 8b 7d d8          	mov    rdi,QWORD PTR [rbp-0x28]
 2f5:	48 c1 e7 28          	shl    rdi,0x28
 2f9:	4c 8b 6d c8          	mov    r13,QWORD PTR [rbp-0x38]
 2fd:	49 c1 e5 38          	shl    r13,0x38
 301:	4c 09 ef             	or     rdi,r13
 304:	49 09 f8             	or     r8,rdi
 307:	48 8b 7d b8          	mov    rdi,QWORD PTR [rbp-0x48]
 30b:	48 c1 e7 08          	shl    rdi,0x8
 30f:	49 09 f8             	or     r8,rdi
 312:	48 8b 7d b0          	mov    rdi,QWORD PTR [rbp-0x50]
 316:	48 c1 e7 18          	shl    rdi,0x18
 31a:	48 c1 e3 10          	shl    rbx,0x10
 31e:	48 09 fb             	or     rbx,rdi
 321:	49 09 d8             	or     r8,rbx
 324:	48 8b 7d d0          	mov    rdi,QWORD PTR [rbp-0x30]
 328:	49 09 f8             	or     r8,rdi
 32b:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 32f:	48 83 e7 07          	and    rdi,0x7
 333:	48 89 fb             	mov    rbx,rdi
 336:	48 83 c3 01          	add    rbx,0x1
 33a:	48 83 f7 3f          	xor    rdi,0x3f
 33e:	4d 89 c5             	mov    r13,r8
 341:	c4 42 c3 f7 ed       	shrx   r13,r13,rdi
 346:	c4 42 e1 f7 c0       	shlx   r8,r8,rbx
 34b:	4d 09 e8             	or     r8,r13
 34e:	4c 31 c6             	xor    rsi,r8
 351:	4c 89 ff             	mov    rdi,r15
 354:	48 83 e7 02          	and    rdi,0x2
 358:	48 85 ff             	test   rdi,rdi
 35b:	0f 84 85 fd ff ff    	je     0xe6
 361:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 366:	48 83 ff 70          	cmp    rdi,0x70
 36a:	0f 85 76 fd ff ff    	jne    0xe6
 370:	48 bf 87 ca eb 85 b1 	movabs rdi,0x9e3779b185ebca87
 377:	79 37 9e 
 37a:	48 01 fe             	add    rsi,rdi
 37d:	e9 64 fd ff ff       	jmp    0xe6
 382:	48 89 f7             	mov    rdi,rsi
 385:	48 c1 ef 38          	shr    rdi,0x38
 389:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
 38d:	40 88 7a 07          	mov    BYTE PTR [rdx+0x7],dil
 391:	48 89 f7             	mov    rdi,rsi
 394:	48 c1 ef 30          	shr    rdi,0x30
 398:	40 88 7a 06          	mov    BYTE PTR [rdx+0x6],dil
 39c:	48 89 f7             	mov    rdi,rsi
 39f:	48 c1 ef 28          	shr    rdi,0x28
 3a3:	40 88 7a 05          	mov    BYTE PTR [rdx+0x5],dil
 3a7:	48 89 f7             	mov    rdi,rsi
 3aa:	48 c1 ef 20          	shr    rdi,0x20
 3ae:	40 88 7a 04          	mov    BYTE PTR [rdx+0x4],dil
 3b2:	48 89 f7             	mov    rdi,rsi
 3b5:	48 c1 ef 18          	shr    rdi,0x18
 3b9:	40 88 7a 03          	mov    BYTE PTR [rdx+0x3],dil
 3bd:	48 89 f7             	mov    rdi,rsi
 3c0:	48 c1 ef 10          	shr    rdi,0x10
 3c4:	40 88 7a 02          	mov    BYTE PTR [rdx+0x2],dil
 3c8:	40 88 72 00          	mov    BYTE PTR [rdx+0x0],sil
 3cc:	48 c1 ee 08          	shr    rsi,0x8
 3d0:	40 88 72 01          	mov    BYTE PTR [rdx+0x1],sil
 3d4:	b8 02 00 00 00       	mov    eax,0x2
 3d9:	41 5f                	pop    r15
 3db:	41 5e                	pop    r14
 3dd:	41 5d                	pop    r13
 3df:	5b                   	pop    rbx
 3e0:	c9                   	leave
 3e1:	c3                   	ret
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
   d:	0f 87 ed 02 00 00    	ja     0x300
  13:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  17:	48 39 ca             	cmp    rdx,rcx
  1a:	0f 87 e0 02 00 00    	ja     0x300
  20:	48 8d 96 10 04 00 00 	lea    rdx,[rsi+0x410]
  27:	48 39 ca             	cmp    rdx,rcx
  2a:	0f 87 d0 02 00 00    	ja     0x300
  30:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
  34:	0f 85 ac 02 00 00    	jne    0x2e6
  3a:	83 7e 0c 20          	cmp    DWORD PTR [rsi+0xc],0x20
  3e:	0f 85 a2 02 00 00    	jne    0x2e6
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 b8 b3 01 00 00 00 	movabs rax,0x100000001b3
  55:	01 00 00 
  58:	48 89 74 24 c8       	mov    QWORD PTR [rsp-0x38],rsi
  5d:	48 8d 56 17          	lea    rdx,[rsi+0x17]
  61:	49 bf eb 11 31 13 bb 	movabs r15,0x94d049bb133111eb
  68:	49 d0 94 
  6b:	31 f6                	xor    esi,esi
  6d:	e9 f1 00 00 00       	jmp    0x163
  72:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  79:	1f 84 00 00 00 00 00 
  80:	48 89 4c 24 d0       	mov    QWORD PTR [rsp-0x30],rcx
  85:	48 8b 4c 24 e8       	mov    rcx,QWORD PTR [rsp-0x18]
  8a:	48 c1 e1 20          	shl    rcx,0x20
  8e:	49 89 de             	mov    r14,rbx
  91:	48 8b 5c 24 e0       	mov    rbx,QWORD PTR [rsp-0x20]
  96:	48 c1 e3 30          	shl    rbx,0x30
  9a:	48 c1 e5 28          	shl    rbp,0x28
  9e:	48 09 cd             	or     rbp,rcx
  a1:	48 09 dd             	or     rbp,rbx
  a4:	4c 89 f3             	mov    rbx,r14
  a7:	48 c1 e7 38          	shl    rdi,0x38
  ab:	48 09 ef             	or     rdi,rbp
  ae:	41 c1 e0 08          	shl    r8d,0x8
  b2:	49 09 f8             	or     r8,rdi
  b5:	48 8b 4c 24 d8       	mov    rcx,QWORD PTR [rsp-0x28]
  ba:	c1 e1 18             	shl    ecx,0x18
  bd:	41 c1 e4 10          	shl    r12d,0x10
  c1:	4d 09 c4             	or     r12,r8
  c4:	49 09 cc             	or     r12,rcx
  c7:	4c 0b 64 24 f0       	or     r12,QWORD PTR [rsp-0x10]
  cc:	4c 8b 74 24 d0       	mov    r14,QWORD PTR [rsp-0x30]
  d1:	44 89 f1             	mov    ecx,r14d
  d4:	80 e1 07             	and    cl,0x7
  d7:	89 cf                	mov    edi,ecx
  d9:	40 f6 d7             	not    dil
  dc:	c4 c2 c3 f7 fc       	shrx   rdi,r12,rdi
  e1:	fe c1                	inc    cl
  e3:	c4 c2 f1 f7 cc       	shlx   rcx,r12,rcx
  e8:	48 09 f9             	or     rcx,rdi
  eb:	49 31 cd             	xor    r13,rcx
  ee:	48 b9 87 ca eb 85 b1 	movabs rcx,0x9e3779b185ebca87
  f5:	79 37 9e 
  f8:	4c 01 e9             	add    rcx,r13
  fb:	80 fb 70             	cmp    bl,0x70
  fe:	49 0f 45 cd          	cmovne rcx,r13
 102:	41 f6 c1 02          	test   r9b,0x2
 106:	49 0f 44 cd          	cmove  rcx,r13
 10a:	48 8b 7c 24 f8       	mov    rdi,QWORD PTR [rsp-0x8]
 10f:	c1 e7 10             	shl    edi,0x10
 112:	41 c1 e3 08          	shl    r11d,0x8
 116:	41 09 fb             	or     r11d,edi
 119:	41 c1 e2 18          	shl    r10d,0x18
 11d:	45 09 da             	or     r10d,r11d
 120:	89 f7                	mov    edi,esi
 122:	40 80 e7 07          	and    dil,0x7
 126:	41 89 f8             	mov    r8d,edi
 129:	41 f6 d0             	not    r8b
 12c:	c4 62 bb f7 c1       	shrx   r8,rcx,r8
 131:	40 fe c7             	inc    dil
 134:	c4 e2 c1 f7 c9       	shlx   rcx,rcx,rdi
 139:	4c 09 c1             	or     rcx,r8
 13c:	4c 89 ff             	mov    rdi,r15
 13f:	48 31 cf             	xor    rdi,rcx
 142:	49 c1 e1 38          	shl    r9,0x38
 146:	4d 09 d1             	or     r9,r10
 149:	4d 09 f1             	or     r9,r14
 14c:	4d 89 cf             	mov    r15,r9
 14f:	49 01 ff             	add    r15,rdi
 152:	48 83 c2 20          	add    rdx,0x20
 156:	48 ff c6             	inc    rsi
 159:	48 83 fe 20          	cmp    rsi,0x20
 15d:	0f 84 86 01 00 00    	je     0x2e9
 163:	44 0f b6 72 03       	movzx  r14d,BYTE PTR [rdx+0x3]
 168:	44 0f b6 5a 02       	movzx  r11d,BYTE PTR [rdx+0x2]
 16d:	44 0f b6 52 04       	movzx  r10d,BYTE PTR [rdx+0x4]
 172:	44 0f b6 4a f9       	movzx  r9d,BYTE PTR [rdx-0x7]
 177:	4c 89 4c 24 e8       	mov    QWORD PTR [rsp-0x18],r9
 17c:	48 b9 25 23 22 84 e4 	movabs rcx,0xcbf29ce484222325
 183:	9c f2 cb 
 186:	49 31 c9             	xor    r9,rcx
 189:	4c 0f af c8          	imul   r9,rax
 18d:	0f b6 6a fa          	movzx  ebp,BYTE PTR [rdx-0x6]
 191:	49 31 e9             	xor    r9,rbp
 194:	4c 0f af c8          	imul   r9,rax
 198:	0f b6 4a fb          	movzx  ecx,BYTE PTR [rdx-0x5]
 19c:	48 89 4c 24 e0       	mov    QWORD PTR [rsp-0x20],rcx
 1a1:	49 31 c9             	xor    r9,rcx
 1a4:	4c 0f af c8          	imul   r9,rax
 1a8:	0f b6 7a fc          	movzx  edi,BYTE PTR [rdx-0x4]
 1ac:	49 31 f9             	xor    r9,rdi
 1af:	4c 0f af c8          	imul   r9,rax
 1b3:	44 0f b6 42 fd       	movzx  r8d,BYTE PTR [rdx-0x3]
 1b8:	4c 89 44 24 f0       	mov    QWORD PTR [rsp-0x10],r8
 1bd:	4d 31 c1             	xor    r9,r8
 1c0:	4c 0f af c8          	imul   r9,rax
 1c4:	44 0f b6 42 fe       	movzx  r8d,BYTE PTR [rdx-0x2]
 1c9:	4d 31 c1             	xor    r9,r8
 1cc:	4c 0f af c8          	imul   r9,rax
 1d0:	44 0f b6 62 ff       	movzx  r12d,BYTE PTR [rdx-0x1]
 1d5:	4d 31 e1             	xor    r9,r12
 1d8:	4c 0f af c8          	imul   r9,rax
 1dc:	0f b6 0a             	movzx  ecx,BYTE PTR [rdx]
 1df:	48 89 4c 24 d8       	mov    QWORD PTR [rsp-0x28],rcx
 1e4:	49 31 c9             	xor    r9,rcx
 1e7:	4c 0f af c8          	imul   r9,rax
 1eb:	0f b6 4a 01          	movzx  ecx,BYTE PTR [rdx+0x1]
 1ef:	49 31 c9             	xor    r9,rcx
 1f2:	4c 0f af c8          	imul   r9,rax
 1f6:	4d 31 d9             	xor    r9,r11
 1f9:	4c 0f af c8          	imul   r9,rax
 1fd:	4c 89 74 24 f8       	mov    QWORD PTR [rsp-0x8],r14
 202:	4d 31 f1             	xor    r9,r14
 205:	4c 0f af c8          	imul   r9,rax
 209:	4d 31 d1             	xor    r9,r10
 20c:	4c 0f af c8          	imul   r9,rax
 210:	0f b6 5a 09          	movzx  ebx,BYTE PTR [rdx+0x9]
 214:	49 31 d9             	xor    r9,rbx
 217:	4c 0f af c8          	imul   r9,rax
 21b:	44 0f b6 6a 0a       	movzx  r13d,BYTE PTR [rdx+0xa]
 220:	4d 31 cd             	xor    r13,r9
 223:	4c 0f af e8          	imul   r13,rax
 227:	44 0f b6 4a 0b       	movzx  r9d,BYTE PTR [rdx+0xb]
 22c:	4d 31 e9             	xor    r9,r13
 22f:	4c 0f af c8          	imul   r9,rax
 233:	44 0f b6 6a 0c       	movzx  r13d,BYTE PTR [rdx+0xc]
 238:	4d 31 cd             	xor    r13,r9
 23b:	4c 0f af e8          	imul   r13,rax
 23f:	44 0f b6 4a 0d       	movzx  r9d,BYTE PTR [rdx+0xd]
 244:	4d 31 e9             	xor    r9,r13
 247:	4c 0f af c8          	imul   r9,rax
 24b:	44 0f b6 6a 0e       	movzx  r13d,BYTE PTR [rdx+0xe]
 250:	4d 31 cd             	xor    r13,r9
 253:	4c 0f af e8          	imul   r13,rax
 257:	44 0f b6 4a 0f       	movzx  r9d,BYTE PTR [rdx+0xf]
 25c:	4d 31 e9             	xor    r9,r13
 25f:	4c 0f af c8          	imul   r9,rax
 263:	44 0f b6 6a 10       	movzx  r13d,BYTE PTR [rdx+0x10]
 268:	4d 31 cd             	xor    r13,r9
 26b:	4c 0f af e8          	imul   r13,rax
 26f:	44 0f b6 4a 11       	movzx  r9d,BYTE PTR [rdx+0x11]
 274:	4d 31 e9             	xor    r9,r13
 277:	4c 0f af c8          	imul   r9,rax
 27b:	44 0f b6 6a 12       	movzx  r13d,BYTE PTR [rdx+0x12]
 280:	4d 31 cd             	xor    r13,r9
 283:	4c 0f af e8          	imul   r13,rax
 287:	44 0f b6 4a 13       	movzx  r9d,BYTE PTR [rdx+0x13]
 28c:	4d 31 e9             	xor    r9,r13
 28f:	4c 0f af c8          	imul   r9,rax
 293:	44 0f b6 6a 14       	movzx  r13d,BYTE PTR [rdx+0x14]
 298:	4d 31 cd             	xor    r13,r9
 29b:	4c 0f af e8          	imul   r13,rax
 29f:	44 0f b6 4a 15       	movzx  r9d,BYTE PTR [rdx+0x15]
 2a4:	4d 31 e9             	xor    r9,r13
 2a7:	4c 0f af c8          	imul   r9,rax
 2ab:	44 0f b6 6a 16       	movzx  r13d,BYTE PTR [rdx+0x16]
 2b0:	4d 31 cd             	xor    r13,r9
 2b3:	4c 0f af e8          	imul   r13,rax
 2b7:	44 0f b6 4a 17       	movzx  r9d,BYTE PTR [rdx+0x17]
 2bc:	4d 31 e9             	xor    r9,r13
 2bf:	4c 0f af c8          	imul   r9,rax
 2c3:	44 0f b6 6a 18       	movzx  r13d,BYTE PTR [rdx+0x18]
 2c8:	4d 31 cd             	xor    r13,r9
 2cb:	4c 0f af e8          	imul   r13,rax
 2cf:	44 0f b6 4a 05       	movzx  r9d,BYTE PTR [rdx+0x5]
 2d4:	41 f6 c1 01          	test   r9b,0x1
 2d8:	0f 85 a2 fd ff ff    	jne    0x80
 2de:	49 89 ce             	mov    r14,rcx
 2e1:	e9 08 fe ff ff       	jmp    0xee
 2e6:	31 c0                	xor    eax,eax
 2e8:	c3                   	ret
 2e9:	48 8b 44 24 c8       	mov    rax,QWORD PTR [rsp-0x38]
 2ee:	4c 89 38             	mov    QWORD PTR [rax],r15
 2f1:	b8 02 00 00 00       	mov    eax,0x2
 2f6:	5b                   	pop    rbx
 2f7:	41 5c                	pop    r12
 2f9:	41 5d                	pop    r13
 2fb:	41 5e                	pop    r14
 2fd:	41 5f                	pop    r15
 2ff:	5d                   	pop    rbp
 300:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 122
 *
 * - 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [r8+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0x8],0x20]
 * - 0x112b: cmp    DWORD PTR [r8+0xc],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0xc],0x20]
 * - 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113b: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113c: mov    QWORD PTR [rsp-0x40],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1152: movabs r10,0x100000001b3 [warning-unmapped: unsupported mnemonic or operand form: movabs r10,0x100000001b3]
 * - 0x1160: shl    r12d,0x8 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file]
 * - 0x1168: or     r15d,r12d [warning-unmapped: ALU source r12d is not supported]
 * - 0x1176: mov    rdx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r11]
 * - 0x1180: shr    r11,cl [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1186: or     ebx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1189: or     r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x118f: xor    rax,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x11af: mov    QWORD PTR [rsp-0x8],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x11b9: movzx  r9d,BYTE PTR [rdi-0x1e] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c6: movzx  ebp,BYTE PTR [rdi-0x1b] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11ce: mov    QWORD PTR [rsp-0x10],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x11d7: mov    QWORD PTR [rsp-0x18],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x11e6: movzx  r12d,BYTE PTR [rdi-0x16] [warning-unmapped: destination register r12d is not in the BPF JIT register file]
 * - 0x11f4: mov    r11,r13 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r13]
 * - 0x1201: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1204: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1208: mov    QWORD PTR [rsp-0x38],r9 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x120d: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1210: mov    r9,r8 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1213: mov    r8,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1218: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x121c: mov    QWORD PTR [rsp-0x28],rax [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1221: xor    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1224: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1228: mov    QWORD PTR [rsp-0x30],rdx [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x122d: xor    r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1230: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1234: mov    QWORD PTR [rsp-0x20],rbp [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rsp-0x20],rbp]
 * - 0x1239: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x123c: mov    rbp,QWORD PTR [rsp-0x10] [warning-unmapped: unsupported mnemonic or operand form: mov    rbp,QWORD PTR [rsp-0x10]]
 * - 0x1241: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1245: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1248: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x124c: xor    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x124f: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1253: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1256: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x125a: mov    QWORD PTR [rsp-0x48],r14 [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x125f: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1262: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1266: xor    r11,r12 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1269: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x126d: xor    r11,r15 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1270: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1277: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x127a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x127e: movzx  r11d,BYTE PTR [rdi-0xf] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1283: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1286: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x128f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1292: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x1296: movzx  r11d,BYTE PTR [rdi-0xd] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x129b: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x129e: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12a7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12aa: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12ae: movzx  r11d,BYTE PTR [rdi-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12b3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12b6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12bf: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12c2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12c6: movzx  r11d,BYTE PTR [rdi-0x9] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12cb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12ce: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12d7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12da: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12de: movzx  r11d,BYTE PTR [rdi-0x7] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12e3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12e6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x12ef: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x12f2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x12f6: movzx  r11d,BYTE PTR [rdi-0x5] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x12fb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x12fe: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1307: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x130a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x130e: movzx  r11d,BYTE PTR [rdi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1313: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1316: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x131f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1322: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10]
 * - 0x132d: imul   rcx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rcx,r10]
 * - 0x1331: movzx  r11d,BYTE PTR [rdi] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x1335: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x133d: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10]
 * - 0x1345: jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1347: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1350: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1358: shl    ebp,0x8 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x135b: mov    rax,QWORD PTR [rsp-0x28] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1364: mov    rcx,QWORD PTR [rsp-0x30] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x136d: mov    rdx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1383: or     r13,rbp [warning-unmapped: ALU source rbp is not supported]
 * - 0x1389: or     r13,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x138c: or     r13,QWORD PTR [rsp-0x20] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file]
 * - 0x1391: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1396: mov    eax,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13ae: xor    r11,r13 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x13b5: mov    r8,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13ba: je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x13ca: add    rax,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x13cd: cmp    BYTE PTR [rdi-0xf],0x70 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rdi-0xf],0x70]
 * - 0x13d1: cmove  r11,rax [warning-unmapped: cmove operands are not supported]
 * - 0x13da: mov    rax,QWORD PTR [rsp-0x40] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x13e7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13e8: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13ea: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13ec: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13ee: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x13f0: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_5, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    r8,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> [bpf-branch: lowered cmp    r8,rcx + jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_5, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -6),
    /* 0x1118: lea    rdx,[r8+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0x8],0x20] */
    /* 0x1129: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0x8],0x20 + jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 32),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0xc],0x20] */
    /* 0x1130: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0xc],0x20 + jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -15, 32),
    /* 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113b: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113c: mov    QWORD PTR [rsp-0x40],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1141: lea    rdi,[r8+0x2f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_5, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1145: movabs rsi,0x94d049bb133111eb [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x94d049bb133111ebULL),
    /* 0x114f: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x1152: movabs r10,0x100000001b3 [warning-unmapped: unsupported mnemonic or operand form: movabs r10,0x100000001b3] */
    /* 0x115c: jmp    11af <bpftrace_comm_key_fnv_hash_xdp+0xaf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 25, 0),
    /* 0x115e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1160: shl    r12d,0x8 [warning-unmapped: ALU destination r12d is not in the BPF JIT register file] */
    /* 0x1164: shl    r15d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x1168: or     r15d,r12d [warning-unmapped: ALU source r12d is not supported] */
    /* 0x116b: shl    ebx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 24),
    /* 0x116e: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1171: and    al,0x7 [exact-kinsn: andb imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_0, 7, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1173: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1176: mov    rdx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r11] */
    /* 0x1179: shl    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x117c: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x117e: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1180: shr    r11,cl [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1183: or     ebx,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1186: or     ebx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1189: or     r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x118c: mov    rax,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x118f: xor    rax,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1192: shl    r14,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 56),
    /* 0x1196: mov    esi,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_2, BPF_REG_6, 0, 0),
    /* 0x1198: or     rsi,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_8, 0, 0),
    /* 0x119b: add    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x119e: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11a1: add    rdi,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 32),
    /* 0x11a5: cmp    r8,0x20 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 32), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x11a9: je     13da <bpftrace_comm_key_fnv_hash_xdp+0x2da> [bpf-branch: lowered cmp    r8,0x20 + je     13da <bpftrace_comm_key_fnv_hash_xdp+0x2da> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 77, 32),
    /* 0x11af: mov    QWORD PTR [rsp-0x8],r8 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x11b4: movzx  r13d,BYTE PTR [rdi-0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -31), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11b9: movzx  r9d,BYTE PTR [rdi-0x1e] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -30), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11be: movzx  eax,BYTE PTR [rdi-0x1d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -29), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11c2: movzx  edx,BYTE PTR [rdi-0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, -28), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11c6: movzx  ebp,BYTE PTR [rdi-0x1b] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11ca: movzx  ecx,BYTE PTR [rdi-0x1a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -26), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ce: mov    QWORD PTR [rsp-0x10],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x11d3: movzx  ecx,BYTE PTR [rdi-0x19] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -25), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11d7: mov    QWORD PTR [rsp-0x18],rcx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x11dc: movzx  r8d,BYTE PTR [rdi-0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_1, -24), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e1: movzx  r14d,BYTE PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11e6: movzx  r12d,BYTE PTR [rdi-0x16] [warning-unmapped: destination register r12d is not in the BPF JIT register file] */
    /* 0x11eb: movzx  r15d,BYTE PTR [rdi-0x15] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -21), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11f0: movzx  ebx,BYTE PTR [rdi-0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -20), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11f4: mov    r11,r13 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r13] */
    /* 0x11f7: movabs rcx,0xcbf29ce484222325 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0xcbf29ce484222325ULL),
    /* 0x1201: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1204: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1208: mov    QWORD PTR [rsp-0x38],r9 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x120d: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1210: mov    r9,r8 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1213: mov    r8,QWORD PTR [rsp-0x18] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1218: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x121c: mov    QWORD PTR [rsp-0x28],rax [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1221: xor    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1224: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1228: mov    QWORD PTR [rsp-0x30],rdx [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x122d: xor    r11,rdx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1230: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1234: mov    QWORD PTR [rsp-0x20],rbp [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rsp-0x20],rbp] */
    /* 0x1239: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x123c: mov    rbp,QWORD PTR [rsp-0x10] [warning-unmapped: unsupported mnemonic or operand form: mov    rbp,QWORD PTR [rsp-0x10]] */
    /* 0x1241: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1245: xor    r11,rbp [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1248: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x124c: xor    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x124f: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1253: xor    r11,r9 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1256: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x125a: mov    QWORD PTR [rsp-0x48],r14 [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x125f: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1262: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1266: xor    r11,r12 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1269: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x126d: xor    r11,r15 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1270: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1274: mov    r14,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1277: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x127a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x127e: movzx  r11d,BYTE PTR [rdi-0xf] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1283: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1286: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x128a: movzx  r14d,BYTE PTR [rdi-0xe] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x128f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1292: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x1296: movzx  r11d,BYTE PTR [rdi-0xd] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x129b: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x129e: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12a2: movzx  r14d,BYTE PTR [rdi-0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12a7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12aa: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12ae: movzx  r11d,BYTE PTR [rdi-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12b3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12b6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12ba: movzx  r14d,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12bf: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12c2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12c6: movzx  r11d,BYTE PTR [rdi-0x9] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12cb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12ce: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12d2: movzx  r14d,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12d7: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12da: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12de: movzx  r11d,BYTE PTR [rdi-0x7] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12e3: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12e6: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x12ea: movzx  r14d,BYTE PTR [rdi-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x12ef: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x12f2: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x12f6: movzx  r11d,BYTE PTR [rdi-0x5] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x12fb: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x12fe: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1302: movzx  r14d,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1307: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x130a: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x130e: movzx  r11d,BYTE PTR [rdi-0x3] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1313: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1316: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x131a: movzx  r14d,BYTE PTR [rdi-0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x131f: xor    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1322: imul   r14,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r14,r10] */
    /* 0x1326: movzx  ecx,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x132a: xor    rcx,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_8, 0, 0),
    /* 0x132d: imul   rcx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rcx,r10] */
    /* 0x1331: movzx  r11d,BYTE PTR [rdi] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x1335: xor    r11,rcx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1338: movzx  r14d,BYTE PTR [rdi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x133d: imul   r11,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   r11,r10] */
    /* 0x1341: test   r14b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x1345: jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1347: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x134c: jmp    13b1 <bpftrace_comm_key_fnv_hash_xdp+0x2b1> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 24, 0),
    /* 0x134e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1350: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x1354: shl    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x1358: shl    ebp,0x8 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x135b: mov    rax,QWORD PTR [rsp-0x28] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1360: shl    rax,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 48),
    /* 0x1364: mov    rcx,QWORD PTR [rsp-0x30] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1369: shl    rcx,0x38 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 56),
    /* 0x136d: mov    rdx,QWORD PTR [rsp-0x38] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1372: shl    rdx,0x28 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 40),
    /* 0x1376: shl    r13,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_7, 0, 0, 32),
    /* 0x137a: or     r13,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_3, 0, 0),
    /* 0x137d: or     r13,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_0, 0, 0),
    /* 0x1380: or     r13,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_4, 0, 0),
    /* 0x1383: or     r13,rbp [warning-unmapped: ALU source rbp is not supported] */
    /* 0x1386: or     r13,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_5, 0, 0),
    /* 0x1389: or     r13,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x138c: or     r13,QWORD PTR [rsp-0x20] [warning-unmapped: ALU memory base rsp is not in the BPF JIT register file] */
    /* 0x1391: mov    r9,QWORD PTR [rsp-0x48] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1396: mov    eax,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x1399: and    al,0x7 [exact-kinsn: andb imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_0, 7, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x139b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x139e: mov    rdx,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x13a1: shl    rdx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x13a4: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x13a6: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x13a8: shr    r13,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_7, BPF_REG_4, 0, 0),
    /* 0x13ab: or     r13,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_7, BPF_REG_3, 0, 0),
    /* 0x13ae: xor    r11,r13 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x13b1: test   r14b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x13b5: mov    r8,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x13ba: je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x13c0: movabs rax,0x9e3779b185ebca87 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x9e3779b185ebca87ULL),
    /* 0x13ca: add    rax,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x13cd: cmp    BYTE PTR [rdi-0xf],0x70 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    BYTE PTR [rdi-0xf],0x70] */
    /* 0x13d1: cmove  r11,rax [warning-unmapped: cmove operands are not supported] */
    /* 0x13d5: jmp    1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -102, 0),
    /* 0x13da: mov    rax,QWORD PTR [rsp-0x40] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x13df: mov    QWORD PTR [rax],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x13e2: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x13e7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13e8: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13ea: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13ec: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13ee: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13f0: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x13f1: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
