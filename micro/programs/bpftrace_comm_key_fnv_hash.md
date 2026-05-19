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

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 c1 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fc1]        # 3fd0 <__gmon_start__@Base>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 ca 2f 00 00    	push   QWORD PTR [rip+0x2fca]        # 3ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 2f 00 00    	jmp    QWORD PTR [rip+0x2fcc]        # 3ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

Disassembly of section .plt.got:

0000000000001030 <__cxa_finalize@plt>:
    1030:	ff 25 aa 2f 00 00    	jmp    QWORD PTR [rip+0x2faa]        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    1036:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000001040 <deregister_tm_clones>:
    1040:	48 8d 3d c1 2f 00 00 	lea    rdi,[rip+0x2fc1]        # 4008 <completed.0>
    1047:	48 8d 05 ba 2f 00 00 	lea    rax,[rip+0x2fba]        # 4008 <completed.0>
    104e:	48 39 f8             	cmp    rax,rdi
    1051:	74 15                	je     1068 <deregister_tm_clones+0x28>
    1053:	48 8b 05 6e 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f6e]        # 3fc8 <_ITM_deregisterTMCloneTable@Base>
    105a:	48 85 c0             	test   rax,rax
    105d:	74 09                	je     1068 <deregister_tm_clones+0x28>
    105f:	ff e0                	jmp    rax
    1061:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1068:	c3                   	ret
    1069:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001070 <register_tm_clones>:
    1070:	48 8d 3d 91 2f 00 00 	lea    rdi,[rip+0x2f91]        # 4008 <completed.0>
    1077:	48 8d 35 8a 2f 00 00 	lea    rsi,[rip+0x2f8a]        # 4008 <completed.0>
    107e:	48 29 fe             	sub    rsi,rdi
    1081:	48 89 f0             	mov    rax,rsi
    1084:	48 c1 ee 3f          	shr    rsi,0x3f
    1088:	48 c1 f8 03          	sar    rax,0x3
    108c:	48 01 c6             	add    rsi,rax
    108f:	48 d1 fe             	sar    rsi,1
    1092:	74 14                	je     10a8 <register_tm_clones+0x38>
    1094:	48 8b 05 3d 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f3d]        # 3fd8 <_ITM_registerTMCloneTable@Base>
    109b:	48 85 c0             	test   rax,rax
    109e:	74 08                	je     10a8 <register_tm_clones+0x38>
    10a0:	ff e0                	jmp    rax
    10a2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    10a8:	c3                   	ret
    10a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010b0 <__do_global_dtors_aux>:
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	80 3d 4d 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f4d],0x0        # 4008 <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 25 2f 00 00 01 	mov    BYTE PTR [rip+0x2f25],0x1        # 4008 <completed.0>
    10e3:	5d                   	pop    rbp
    10e4:	c3                   	ret
    10e5:	0f 1f 00             	nop    DWORD PTR [rax]
    10e8:	c3                   	ret
    10e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010f0 <frame_dummy>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	e9 77 ff ff ff       	jmp    1070 <register_tm_clones>
    10f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

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
    113c:	48 83 ec 48          	sub    rsp,0x48
    1140:	4c 89 44 24 08       	mov    QWORD PTR [rsp+0x8],r8
    1145:	49 8d 78 2f          	lea    rdi,[r8+0x2f]
    1149:	48 be eb 11 31 13 bb 	movabs rsi,0x94d049bb133111eb
    1150:	49 d0 94 
    1153:	45 31 c0             	xor    r8d,r8d
    1156:	49 ba b3 01 00 00 00 	movabs r10,0x100000001b3
    115d:	01 00 00 
    1160:	eb 5d                	jmp    11bf <bpftrace_comm_key_fnv_hash_xdp+0xbf>
    1162:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1169:	1f 84 00 00 00 00 00 
    1170:	41 c1 e4 08          	shl    r12d,0x8
    1174:	41 c1 e7 10          	shl    r15d,0x10
    1178:	45 09 e7             	or     r15d,r12d
    117b:	c1 e3 18             	shl    ebx,0x18
    117e:	44 89 c0             	mov    eax,r8d
    1181:	24 07                	and    al,0x7
    1183:	8d 48 01             	lea    ecx,[rax+0x1]
    1186:	4c 89 da             	mov    rdx,r11
    1189:	48 d3 e2             	shl    rdx,cl
    118c:	f6 d0                	not    al
    118e:	89 c1                	mov    ecx,eax
    1190:	49 d3 eb             	shr    r11,cl
    1193:	44 09 fb             	or     ebx,r15d
    1196:	44 09 cb             	or     ebx,r9d
    1199:	49 09 d3             	or     r11,rdx
    119c:	48 89 f0             	mov    rax,rsi
    119f:	4c 31 d8             	xor    rax,r11
    11a2:	49 c1 e6 38          	shl    r14,0x38
    11a6:	89 de                	mov    esi,ebx
    11a8:	4c 09 f6             	or     rsi,r14
    11ab:	48 01 c6             	add    rsi,rax
    11ae:	49 ff c0             	inc    r8
    11b1:	48 83 c7 20          	add    rdi,0x20
    11b5:	49 83 f8 20          	cmp    r8,0x20
    11b9:	0f 84 2a 02 00 00    	je     13e9 <bpftrace_comm_key_fnv_hash_xdp+0x2e9>
    11bf:	4c 89 44 24 40       	mov    QWORD PTR [rsp+0x40],r8
    11c4:	44 0f b6 6f e1       	movzx  r13d,BYTE PTR [rdi-0x1f]
    11c9:	44 0f b6 4f e2       	movzx  r9d,BYTE PTR [rdi-0x1e]
    11ce:	0f b6 47 e3          	movzx  eax,BYTE PTR [rdi-0x1d]
    11d2:	0f b6 57 e4          	movzx  edx,BYTE PTR [rdi-0x1c]
    11d6:	0f b6 6f e5          	movzx  ebp,BYTE PTR [rdi-0x1b]
    11da:	0f b6 4f e6          	movzx  ecx,BYTE PTR [rdi-0x1a]
    11de:	48 89 4c 24 38       	mov    QWORD PTR [rsp+0x38],rcx
    11e3:	0f b6 4f e7          	movzx  ecx,BYTE PTR [rdi-0x19]
    11e7:	48 89 4c 24 30       	mov    QWORD PTR [rsp+0x30],rcx
    11ec:	44 0f b6 47 e8       	movzx  r8d,BYTE PTR [rdi-0x18]
    11f1:	44 0f b6 77 e9       	movzx  r14d,BYTE PTR [rdi-0x17]
    11f6:	44 0f b6 67 ea       	movzx  r12d,BYTE PTR [rdi-0x16]
    11fb:	44 0f b6 7f eb       	movzx  r15d,BYTE PTR [rdi-0x15]
    1200:	0f b6 5f ec          	movzx  ebx,BYTE PTR [rdi-0x14]
    1204:	4d 89 eb             	mov    r11,r13
    1207:	48 b9 25 23 22 84 e4 	movabs rcx,0xcbf29ce484222325
    120e:	9c f2 cb 
    1211:	49 31 cb             	xor    r11,rcx
    1214:	4d 0f af da          	imul   r11,r10
    1218:	4c 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],r9
    121d:	4d 31 cb             	xor    r11,r9
    1220:	4d 89 c1             	mov    r9,r8
    1223:	4c 8b 44 24 30       	mov    r8,QWORD PTR [rsp+0x30]
    1228:	4d 0f af da          	imul   r11,r10
    122c:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    1231:	49 31 c3             	xor    r11,rax
    1234:	4d 0f af da          	imul   r11,r10
    1238:	48 89 54 24 18       	mov    QWORD PTR [rsp+0x18],rdx
    123d:	49 31 d3             	xor    r11,rdx
    1240:	4d 0f af da          	imul   r11,r10
    1244:	48 89 6c 24 28       	mov    QWORD PTR [rsp+0x28],rbp
    1249:	49 31 eb             	xor    r11,rbp
    124c:	48 8b 6c 24 38       	mov    rbp,QWORD PTR [rsp+0x38]
    1251:	4d 0f af da          	imul   r11,r10
    1255:	49 31 eb             	xor    r11,rbp
    1258:	4d 0f af da          	imul   r11,r10
    125c:	4d 31 c3             	xor    r11,r8
    125f:	4d 0f af da          	imul   r11,r10
    1263:	4d 31 cb             	xor    r11,r9
    1266:	4d 0f af da          	imul   r11,r10
    126a:	4c 89 34 24          	mov    QWORD PTR [rsp],r14
    126e:	4d 31 f3             	xor    r11,r14
    1271:	4d 0f af da          	imul   r11,r10
    1275:	4d 31 e3             	xor    r11,r12
    1278:	4d 0f af da          	imul   r11,r10
    127c:	4d 31 fb             	xor    r11,r15
    127f:	4d 0f af da          	imul   r11,r10
    1283:	49 89 de             	mov    r14,rbx
    1286:	4d 31 de             	xor    r14,r11
    1289:	4d 0f af f2          	imul   r14,r10
    128d:	44 0f b6 5f f1       	movzx  r11d,BYTE PTR [rdi-0xf]
    1292:	4d 31 f3             	xor    r11,r14
    1295:	4d 0f af da          	imul   r11,r10
    1299:	44 0f b6 77 f2       	movzx  r14d,BYTE PTR [rdi-0xe]
    129e:	4d 31 de             	xor    r14,r11
    12a1:	4d 0f af f2          	imul   r14,r10
    12a5:	44 0f b6 5f f3       	movzx  r11d,BYTE PTR [rdi-0xd]
    12aa:	4d 31 f3             	xor    r11,r14
    12ad:	4d 0f af da          	imul   r11,r10
    12b1:	44 0f b6 77 f4       	movzx  r14d,BYTE PTR [rdi-0xc]
    12b6:	4d 31 de             	xor    r14,r11
    12b9:	4d 0f af f2          	imul   r14,r10
    12bd:	44 0f b6 5f f5       	movzx  r11d,BYTE PTR [rdi-0xb]
    12c2:	4d 31 f3             	xor    r11,r14
    12c5:	4d 0f af da          	imul   r11,r10
    12c9:	44 0f b6 77 f6       	movzx  r14d,BYTE PTR [rdi-0xa]
    12ce:	4d 31 de             	xor    r14,r11
    12d1:	4d 0f af f2          	imul   r14,r10
    12d5:	44 0f b6 5f f7       	movzx  r11d,BYTE PTR [rdi-0x9]
    12da:	4d 31 f3             	xor    r11,r14
    12dd:	4d 0f af da          	imul   r11,r10
    12e1:	44 0f b6 77 f8       	movzx  r14d,BYTE PTR [rdi-0x8]
    12e6:	4d 31 de             	xor    r14,r11
    12e9:	4d 0f af f2          	imul   r14,r10
    12ed:	44 0f b6 5f f9       	movzx  r11d,BYTE PTR [rdi-0x7]
    12f2:	4d 31 f3             	xor    r11,r14
    12f5:	4d 0f af da          	imul   r11,r10
    12f9:	44 0f b6 77 fa       	movzx  r14d,BYTE PTR [rdi-0x6]
    12fe:	4d 31 de             	xor    r14,r11
    1301:	4d 0f af f2          	imul   r14,r10
    1305:	44 0f b6 5f fb       	movzx  r11d,BYTE PTR [rdi-0x5]
    130a:	4d 31 f3             	xor    r11,r14
    130d:	4d 0f af da          	imul   r11,r10
    1311:	44 0f b6 77 fc       	movzx  r14d,BYTE PTR [rdi-0x4]
    1316:	4d 31 de             	xor    r14,r11
    1319:	4d 0f af f2          	imul   r14,r10
    131d:	44 0f b6 5f fd       	movzx  r11d,BYTE PTR [rdi-0x3]
    1322:	4d 31 f3             	xor    r11,r14
    1325:	4d 0f af da          	imul   r11,r10
    1329:	44 0f b6 77 fe       	movzx  r14d,BYTE PTR [rdi-0x2]
    132e:	4d 31 de             	xor    r14,r11
    1331:	4d 0f af f2          	imul   r14,r10
    1335:	0f b6 4f ff          	movzx  ecx,BYTE PTR [rdi-0x1]
    1339:	4c 31 f1             	xor    rcx,r14
    133c:	49 0f af ca          	imul   rcx,r10
    1340:	44 0f b6 1f          	movzx  r11d,BYTE PTR [rdi]
    1344:	49 31 cb             	xor    r11,rcx
    1347:	44 0f b6 77 ed       	movzx  r14d,BYTE PTR [rdi-0x13]
    134c:	4d 0f af da          	imul   r11,r10
    1350:	41 f6 c6 01          	test   r14b,0x1
    1354:	75 0a                	jne    1360 <bpftrace_comm_key_fnv_hash_xdp+0x260>
    1356:	4c 8b 0c 24          	mov    r9,QWORD PTR [rsp]
    135a:	eb 64                	jmp    13c0 <bpftrace_comm_key_fnv_hash_xdp+0x2c0>
    135c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1360:	41 c1 e1 18          	shl    r9d,0x18
    1364:	41 c1 e0 10          	shl    r8d,0x10
    1368:	c1 e5 08             	shl    ebp,0x8
    136b:	48 8b 44 24 20       	mov    rax,QWORD PTR [rsp+0x20]
    1370:	48 c1 e0 30          	shl    rax,0x30
    1374:	48 8b 4c 24 18       	mov    rcx,QWORD PTR [rsp+0x18]
    1379:	48 c1 e1 38          	shl    rcx,0x38
    137d:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
    1382:	48 c1 e2 28          	shl    rdx,0x28
    1386:	49 c1 e5 20          	shl    r13,0x20
    138a:	49 09 d5             	or     r13,rdx
    138d:	49 09 c5             	or     r13,rax
    1390:	49 09 cd             	or     r13,rcx
    1393:	49 09 ed             	or     r13,rbp
    1396:	4d 09 c5             	or     r13,r8
    1399:	4d 09 cd             	or     r13,r9
    139c:	4c 0b 6c 24 28       	or     r13,QWORD PTR [rsp+0x28]
    13a1:	4c 8b 0c 24          	mov    r9,QWORD PTR [rsp]
    13a5:	44 89 c8             	mov    eax,r9d
    13a8:	24 07                	and    al,0x7
    13aa:	8d 48 01             	lea    ecx,[rax+0x1]
    13ad:	4c 89 ea             	mov    rdx,r13
    13b0:	48 d3 e2             	shl    rdx,cl
    13b3:	f6 d0                	not    al
    13b5:	89 c1                	mov    ecx,eax
    13b7:	49 d3 ed             	shr    r13,cl
    13ba:	49 09 d5             	or     r13,rdx
    13bd:	4d 31 eb             	xor    r11,r13
    13c0:	41 f6 c6 02          	test   r14b,0x2
    13c4:	4c 8b 44 24 40       	mov    r8,QWORD PTR [rsp+0x40]
    13c9:	0f 84 a1 fd ff ff    	je     1170 <bpftrace_comm_key_fnv_hash_xdp+0x70>
    13cf:	48 b8 87 ca eb 85 b1 	movabs rax,0x9e3779b185ebca87
    13d6:	79 37 9e 
    13d9:	4c 01 d8             	add    rax,r11
    13dc:	80 7f f1 70          	cmp    BYTE PTR [rdi-0xf],0x70
    13e0:	4c 0f 44 d8          	cmove  r11,rax
    13e4:	e9 87 fd ff ff       	jmp    1170 <bpftrace_comm_key_fnv_hash_xdp+0x70>
    13e9:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    13ee:	48 89 30             	mov    QWORD PTR [rax],rsi
    13f1:	b8 02 00 00 00       	mov    eax,0x2
    13f6:	48 83 c4 48          	add    rsp,0x48
    13fa:	5b                   	pop    rbx
    13fb:	41 5c                	pop    r12
    13fd:	41 5d                	pop    r13
    13ff:	41 5e                	pop    r14
    1401:	41 5f                	pop    r15
    1403:	5d                   	pop    rbp
    1404:	c3                   	ret

Disassembly of section .fini:

0000000000001408 <_fini>:
    1408:	f3 0f 1e fa          	endbr64
    140c:	48 83 ec 08          	sub    rsp,0x8
    1410:	48 83 c4 08          	add    rsp,0x8
    1414:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 68 00 00 00 	sub    rsp,0x68
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 97 03 00 00    	ja     0x3c4
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 87 03 00 00    	ja     0x3c4
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 74 03 00 00    	ja     0x3c4
  50:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
  55:	c1 e7 08             	shl    edi,0x8
  58:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  5d:	09 f7                	or     edi,esi
  5f:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  64:	c1 e6 10             	shl    esi,0x10
  67:	09 f7                	or     edi,esi
  69:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  6e:	c1 e6 18             	shl    esi,0x18
  71:	09 f7                	or     edi,esi
  73:	83 ff 20             	cmp    edi,0x20
  76:	0f 85 48 03 00 00    	jne    0x3c4
  7c:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
  81:	c1 e7 08             	shl    edi,0x8
  84:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
  89:	09 f7                	or     edi,esi
  8b:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
  90:	c1 e6 10             	shl    esi,0x10
  93:	09 f7                	or     edi,esi
  95:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
  9a:	c1 e6 18             	shl    esi,0x18
  9d:	09 f7                	or     edi,esi
  9f:	83 ff 20             	cmp    edi,0x20
  a2:	0f 85 1c 03 00 00    	jne    0x3c4
  a8:	48 be eb 11 31 13 bb 	movabs rsi,0x94d049bb133111eb
  af:	49 d0 94 
  b2:	31 d2                	xor    edx,edx
  b4:	48 89 4d 98          	mov    QWORD PTR [rbp-0x68],rcx
  b8:	48 83 c1 17          	add    rcx,0x17
  bc:	eb 42                	jmp    0x100
  be:	89 d7                	mov    edi,edx
  c0:	83 e7 07             	and    edi,0x7
  c3:	41 89 f8             	mov    r8d,edi
  c6:	41 83 f0 3f          	xor    r8d,0x3f
  ca:	48 89 f3             	mov    rbx,rsi
  cd:	c4 e2 bb f7 db       	shrx   rbx,rbx,r8
  d2:	83 c7 01             	add    edi,0x1
  d5:	c4 e2 c1 f7 f6       	shlx   rsi,rsi,rdi
  da:	48 09 de             	or     rsi,rbx
  dd:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
  e1:	48 31 fe             	xor    rsi,rdi
  e4:	49 c1 e7 38          	shl    r15,0x38
  e8:	4d 09 ef             	or     r15,r13
  eb:	4c 01 fe             	add    rsi,r15
  ee:	48 83 c1 20          	add    rcx,0x20
  f2:	48 83 c2 01          	add    rdx,0x1
  f6:	48 83 fa 20          	cmp    rdx,0x20
  fa:	0f 84 6d 02 00 00    	je     0x36d
 100:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
 104:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
 108:	48 0f b6 59 03       	movzx  rbx,BYTE PTR [rcx+0x3]
 10d:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 112:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 116:	4c 0f b6 79 04       	movzx  r15,BYTE PTR [rcx+0x4]
 11b:	48 0f b6 71 f9       	movzx  rsi,BYTE PTR [rcx-0x7]
 120:	48 89 75 a0          	mov    QWORD PTR [rbp-0x60],rsi
 124:	48 bf 25 23 22 84 e4 	movabs rdi,0xcbf29ce484222325
 12b:	9c f2 cb 
 12e:	48 31 fe             	xor    rsi,rdi
 131:	49 b8 b3 01 00 00 00 	movabs r8,0x100000001b3
 138:	01 00 00 
 13b:	49 0f af f0          	imul   rsi,r8
 13f:	48 0f b6 79 fa       	movzx  rdi,BYTE PTR [rcx-0x6]
 144:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 148:	48 31 fe             	xor    rsi,rdi
 14b:	49 0f af f0          	imul   rsi,r8
 14f:	48 0f b6 79 fb       	movzx  rdi,BYTE PTR [rcx-0x5]
 154:	48 89 7d b0          	mov    QWORD PTR [rbp-0x50],rdi
 158:	48 31 fe             	xor    rsi,rdi
 15b:	49 0f af f0          	imul   rsi,r8
 15f:	4c 0f b6 71 00       	movzx  r14,BYTE PTR [rcx+0x0]
 164:	4c 0f b6 69 ff       	movzx  r13,BYTE PTR [rcx-0x1]
 169:	48 0f b6 51 fe       	movzx  rdx,BYTE PTR [rcx-0x2]
 16e:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
 173:	48 0f b6 41 fc       	movzx  rax,BYTE PTR [rcx-0x4]
 178:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
 17c:	48 31 c6             	xor    rsi,rax
 17f:	49 0f af f0          	imul   rsi,r8
 183:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 187:	48 31 fe             	xor    rsi,rdi
 18a:	4c 89 ef             	mov    rdi,r13
 18d:	4c 8b 6d d0          	mov    r13,QWORD PTR [rbp-0x30]
 191:	49 0f af f0          	imul   rsi,r8
 195:	48 31 d6             	xor    rsi,rdx
 198:	49 0f af f0          	imul   rsi,r8
 19c:	48 31 fe             	xor    rsi,rdi
 19f:	49 0f af f0          	imul   rsi,r8
 1a3:	4c 89 75 c0          	mov    QWORD PTR [rbp-0x40],r14
 1a7:	4c 31 f6             	xor    rsi,r14
 1aa:	49 0f af f0          	imul   rsi,r8
 1ae:	4c 0f b6 71 01       	movzx  r14,BYTE PTR [rcx+0x1]
 1b3:	4c 89 75 f8          	mov    QWORD PTR [rbp-0x8],r14
 1b7:	4c 31 f6             	xor    rsi,r14
 1ba:	49 0f af f0          	imul   rsi,r8
 1be:	4c 31 ee             	xor    rsi,r13
 1c1:	49 0f af f0          	imul   rsi,r8
 1c5:	48 89 5d e8          	mov    QWORD PTR [rbp-0x18],rbx
 1c9:	48 31 de             	xor    rsi,rbx
 1cc:	4c 89 7d e0          	mov    QWORD PTR [rbp-0x20],r15
 1d0:	49 81 e7 ff 00 00 00 	and    r15,0xff
 1d7:	49 0f af f0          	imul   rsi,r8
 1db:	4c 31 fe             	xor    rsi,r15
 1de:	4c 0f b6 79 09       	movzx  r15,BYTE PTR [rcx+0x9]
 1e3:	49 0f af f0          	imul   rsi,r8
 1e7:	4c 31 fe             	xor    rsi,r15
 1ea:	4c 0f b6 79 0a       	movzx  r15,BYTE PTR [rcx+0xa]
 1ef:	49 0f af f0          	imul   rsi,r8
 1f3:	4c 31 fe             	xor    rsi,r15
 1f6:	4c 0f b6 79 0b       	movzx  r15,BYTE PTR [rcx+0xb]
 1fb:	49 0f af f0          	imul   rsi,r8
 1ff:	4c 31 fe             	xor    rsi,r15
 202:	4c 0f b6 79 0c       	movzx  r15,BYTE PTR [rcx+0xc]
 207:	49 0f af f0          	imul   rsi,r8
 20b:	4c 31 fe             	xor    rsi,r15
 20e:	4c 0f b6 79 0d       	movzx  r15,BYTE PTR [rcx+0xd]
 213:	49 0f af f0          	imul   rsi,r8
 217:	4c 31 fe             	xor    rsi,r15
 21a:	4c 0f b6 79 0e       	movzx  r15,BYTE PTR [rcx+0xe]
 21f:	49 0f af f0          	imul   rsi,r8
 223:	4c 31 fe             	xor    rsi,r15
 226:	4c 0f b6 79 0f       	movzx  r15,BYTE PTR [rcx+0xf]
 22b:	49 0f af f0          	imul   rsi,r8
 22f:	4c 31 fe             	xor    rsi,r15
 232:	4c 0f b6 79 10       	movzx  r15,BYTE PTR [rcx+0x10]
 237:	49 0f af f0          	imul   rsi,r8
 23b:	4c 31 fe             	xor    rsi,r15
 23e:	4c 0f b6 79 11       	movzx  r15,BYTE PTR [rcx+0x11]
 243:	49 0f af f0          	imul   rsi,r8
 247:	4c 31 fe             	xor    rsi,r15
 24a:	4c 0f b6 79 12       	movzx  r15,BYTE PTR [rcx+0x12]
 24f:	49 0f af f0          	imul   rsi,r8
 253:	4c 31 fe             	xor    rsi,r15
 256:	4c 0f b6 79 13       	movzx  r15,BYTE PTR [rcx+0x13]
 25b:	49 0f af f0          	imul   rsi,r8
 25f:	4c 31 fe             	xor    rsi,r15
 262:	4c 0f b6 79 14       	movzx  r15,BYTE PTR [rcx+0x14]
 267:	49 0f af f0          	imul   rsi,r8
 26b:	4c 31 fe             	xor    rsi,r15
 26e:	4c 0f b6 79 15       	movzx  r15,BYTE PTR [rcx+0x15]
 273:	49 0f af f0          	imul   rsi,r8
 277:	4c 31 fe             	xor    rsi,r15
 27a:	4c 0f b6 79 16       	movzx  r15,BYTE PTR [rcx+0x16]
 27f:	49 0f af f0          	imul   rsi,r8
 283:	4c 31 fe             	xor    rsi,r15
 286:	4c 0f b6 79 17       	movzx  r15,BYTE PTR [rcx+0x17]
 28b:	49 0f af f0          	imul   rsi,r8
 28f:	4c 31 fe             	xor    rsi,r15
 292:	4c 0f b6 79 18       	movzx  r15,BYTE PTR [rcx+0x18]
 297:	49 0f af f0          	imul   rsi,r8
 29b:	4c 31 fe             	xor    rsi,r15
 29e:	49 0f af f0          	imul   rsi,r8
 2a2:	4c 0f b6 79 05       	movzx  r15,BYTE PTR [rcx+0x5]
 2a7:	44 89 fb             	mov    ebx,r15d
 2aa:	83 e3 01             	and    ebx,0x1
 2ad:	85 db                	test   ebx,ebx
 2af:	74 6b                	je     0x31c
 2b1:	4c 8b 45 a0          	mov    r8,QWORD PTR [rbp-0x60]
 2b5:	49 c1 e0 20          	shl    r8,0x20
 2b9:	48 8b 5d b0          	mov    rbx,QWORD PTR [rbp-0x50]
 2bd:	48 c1 e3 30          	shl    rbx,0x30
 2c1:	49 09 d8             	or     r8,rbx
 2c4:	48 8b 5d c8          	mov    rbx,QWORD PTR [rbp-0x38]
 2c8:	48 c1 e3 28          	shl    rbx,0x28
 2cc:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 2d0:	48 c1 e0 38          	shl    rax,0x38
 2d4:	48 09 c3             	or     rbx,rax
 2d7:	49 09 d8             	or     r8,rbx
 2da:	48 c1 e2 08          	shl    rdx,0x8
 2de:	49 09 d0             	or     r8,rdx
 2e1:	48 8b 5d c0          	mov    rbx,QWORD PTR [rbp-0x40]
 2e5:	48 c1 e3 18          	shl    rbx,0x18
 2e9:	48 c1 e7 10          	shl    rdi,0x10
 2ed:	48 09 df             	or     rdi,rbx
 2f0:	49 09 f8             	or     r8,rdi
 2f3:	48 8b 7d b8          	mov    rdi,QWORD PTR [rbp-0x48]
 2f7:	49 09 f8             	or     r8,rdi
 2fa:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 2fe:	83 e7 07             	and    edi,0x7
 301:	89 fb                	mov    ebx,edi
 303:	83 c3 01             	add    ebx,0x1
 306:	83 f7 3f             	xor    edi,0x3f
 309:	4d 89 c6             	mov    r14,r8
 30c:	c4 42 c3 f7 f6       	shrx   r14,r14,rdi
 311:	c4 42 e1 f7 c0       	shlx   r8,r8,rbx
 316:	4d 09 f0             	or     r8,r14
 319:	4c 31 c6             	xor    rsi,r8
 31c:	48 8b 7d e8          	mov    rdi,QWORD PTR [rbp-0x18]
 320:	c1 e7 10             	shl    edi,0x10
 323:	41 c1 e5 08          	shl    r13d,0x8
 327:	41 09 fd             	or     r13d,edi
 32a:	48 8b 7d e0          	mov    rdi,QWORD PTR [rbp-0x20]
 32e:	c1 e7 18             	shl    edi,0x18
 331:	41 09 fd             	or     r13d,edi
 334:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 338:	41 09 fd             	or     r13d,edi
 33b:	44 89 ff             	mov    edi,r15d
 33e:	83 e7 02             	and    edi,0x2
 341:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
 345:	85 ff                	test   edi,edi
 347:	0f 84 71 fd ff ff    	je     0xbe
 34d:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 352:	83 ff 70             	cmp    edi,0x70
 355:	0f 85 63 fd ff ff    	jne    0xbe
 35b:	48 bf 87 ca eb 85 b1 	movabs rdi,0x9e3779b185ebca87
 362:	79 37 9e 
 365:	48 01 fe             	add    rsi,rdi
 368:	e9 51 fd ff ff       	jmp    0xbe
 36d:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
 371:	40 88 72 00          	mov    BYTE PTR [rdx+0x0],sil
 375:	48 89 f7             	mov    rdi,rsi
 378:	48 c1 ef 38          	shr    rdi,0x38
 37c:	40 88 7a 07          	mov    BYTE PTR [rdx+0x7],dil
 380:	48 89 f7             	mov    rdi,rsi
 383:	48 c1 ef 30          	shr    rdi,0x30
 387:	40 88 7a 06          	mov    BYTE PTR [rdx+0x6],dil
 38b:	48 89 f7             	mov    rdi,rsi
 38e:	48 c1 ef 28          	shr    rdi,0x28
 392:	40 88 7a 05          	mov    BYTE PTR [rdx+0x5],dil
 396:	48 89 f7             	mov    rdi,rsi
 399:	48 c1 ef 20          	shr    rdi,0x20
 39d:	40 88 7a 04          	mov    BYTE PTR [rdx+0x4],dil
 3a1:	48 89 f7             	mov    rdi,rsi
 3a4:	48 c1 ef 18          	shr    rdi,0x18
 3a8:	40 88 7a 03          	mov    BYTE PTR [rdx+0x3],dil
 3ac:	48 89 f7             	mov    rdi,rsi
 3af:	48 c1 ef 10          	shr    rdi,0x10
 3b3:	40 88 7a 02          	mov    BYTE PTR [rdx+0x2],dil
 3b7:	48 c1 ee 08          	shr    rsi,0x8
 3bb:	40 88 72 01          	mov    BYTE PTR [rdx+0x1],sil
 3bf:	b8 02 00 00 00       	mov    eax,0x2
 3c4:	41 5f                	pop    r15
 3c6:	41 5e                	pop    r14
 3c8:	41 5d                	pop    r13
 3ca:	5b                   	pop    rbx
 3cb:	c9                   	leave
 3cc:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
