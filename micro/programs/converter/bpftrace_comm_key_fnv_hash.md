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
    1040:	48 8d 3d c9 2f 00 00 	lea    rdi,[rip+0x2fc9]        # 4010 <__TMC_END__>
    1047:	48 8d 05 c2 2f 00 00 	lea    rax,[rip+0x2fc2]        # 4010 <__TMC_END__>
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
    1070:	48 8d 3d 99 2f 00 00 	lea    rdi,[rip+0x2f99]        # 4010 <__TMC_END__>
    1077:	48 8d 35 92 2f 00 00 	lea    rsi,[rip+0x2f92]        # 4010 <__TMC_END__>
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
    10b4:	80 3d 51 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f51],0x0        # 400c <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 29 2f 00 00 01 	mov    BYTE PTR [rip+0x2f29],0x1        # 400c <completed.0>
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
#define HC_LEA_ARCH_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | (1ULL << 48))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    r8,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_R8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    r8,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <bpftrace_comm_key_fnv_hash_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (4) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-9) - 1, 0),
    /* 0x1118: lea    rdx,[r8+0x410] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-16) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1129: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-20) - 1, 32),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1130: jne    110e <bpftrace_comm_key_fnv_hash_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-24) - 1, 32),
    /* 0x1132: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r13 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   r12 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113b: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113c: mov    QWORD PTR [rsp-0x40],r8 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_R8, HC_X86_RSP, -64), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1141: lea    rdi,[r8+0x2f] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_R8, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1145: movabs rsi,0x94d049bb133111eb [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x94d049bb133111ebULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RSI, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x114f: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1152: movabs r10,0x100000001b3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x100000001b3ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x115c: jmp    11af <bpftrace_comm_key_fnv_hash_xdp+0xaf> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (50) - 1, 0),
    /* 0x115e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1160: shl    r12d,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R12, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1164: shl    r15d,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R15, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1168: or     r15d,r12d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R15, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x116b: shl    ebx,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBX, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x116e: mov    eax,r8d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1171: and    al,0x7 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1173: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1176: mov    rdx,r11 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1179: shl    rdx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x117c: not    al [exact-kop: not8 reg kop] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x117e: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1180: shr    r11,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1183: or     ebx,r15d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1186: or     ebx,r9d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1189: or     r11,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x118c: mov    rax,rsi [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x118f: xor    rax,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1192: shl    r14,0x38 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R14, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1196: mov    esi,ebx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: or     rsi,r14 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x119b: add    rsi,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119e: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11a1: add    rdi,0x20 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a5: cmp    r8,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11a9: je     13da <bpftrace_comm_key_fnv_hash_xdp+0x2da> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (281) - 1, 32),
    /* 0x11af: mov    QWORD PTR [rsp-0x8],r8 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_R8, HC_X86_RSP, -8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11b4: movzx  r13d,BYTE PTR [rdi-0x1f] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R13, HC_X86_RDI, -31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11b9: movzx  r9d,BYTE PTR [rdi-0x1e] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RDI, -30), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11be: movzx  eax,BYTE PTR [rdi-0x1d] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RDI, -29), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c2: movzx  edx,BYTE PTR [rdi-0x1c] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RDI, -28), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c6: movzx  ebp,BYTE PTR [rdi-0x1b] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RDI, -27), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ca: movzx  ecx,BYTE PTR [rdi-0x1a] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDI, -26), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ce: mov    QWORD PTR [rsp-0x10],rcx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RCX, HC_X86_RSP, -16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11d3: movzx  ecx,BYTE PTR [rdi-0x19] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDI, -25), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d7: mov    QWORD PTR [rsp-0x18],rcx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RCX, HC_X86_RSP, -24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11dc: movzx  r8d,BYTE PTR [rdi-0x18] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R8, HC_X86_RDI, -24), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e1: movzx  r14d,BYTE PTR [rdi-0x17] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e6: movzx  r12d,BYTE PTR [rdi-0x16] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R12, HC_X86_RDI, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11eb: movzx  r15d,BYTE PTR [rdi-0x15] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R15, HC_X86_RDI, -21), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f0: movzx  ebx,BYTE PTR [rdi-0x14] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBX, HC_X86_RDI, -20), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f4: mov    r11,r13 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11f7: movabs rcx,0xcbf29ce484222325 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xcbf29ce484222325ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1201: xor    r11,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1204: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1208: mov    QWORD PTR [rsp-0x38],r9 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_R9, HC_X86_RSP, -56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x120d: xor    r11,r9 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1210: mov    r9,r8 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1213: mov    r8,QWORD PTR [rsp-0x18] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R8, HC_X86_RSP, -24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1218: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x121c: mov    QWORD PTR [rsp-0x28],rax [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RAX, HC_X86_RSP, -40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1221: xor    r11,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1224: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1228: mov    QWORD PTR [rsp-0x30],rdx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RSP, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x122d: xor    r11,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1230: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1234: mov    QWORD PTR [rsp-0x20],rbp [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RBP, HC_X86_RSP, -32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1239: xor    r11,rbp [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x123c: mov    rbp,QWORD PTR [rsp-0x10] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RSP, -16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1241: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1245: xor    r11,rbp [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1248: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x124c: xor    r11,r8 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x124f: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1253: xor    r11,r9 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1256: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x125a: mov    QWORD PTR [rsp-0x48],r14 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_R14, HC_X86_RSP, -72), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x125f: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1262: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1266: xor    r11,r12 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1269: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x126d: xor    r11,r15 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1270: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1274: mov    r14,rbx [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1277: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x127a: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x127e: movzx  r11d,BYTE PTR [rdi-0xf] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1283: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1286: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x128a: movzx  r14d,BYTE PTR [rdi-0xe] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x128f: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1292: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1296: movzx  r11d,BYTE PTR [rdi-0xd] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x129b: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x129e: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12a2: movzx  r14d,BYTE PTR [rdi-0xc] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12a7: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12aa: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ae: movzx  r11d,BYTE PTR [rdi-0xb] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12b3: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12b6: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ba: movzx  r14d,BYTE PTR [rdi-0xa] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12bf: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12c2: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12c6: movzx  r11d,BYTE PTR [rdi-0x9] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12cb: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ce: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12d2: movzx  r14d,BYTE PTR [rdi-0x8] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d7: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12da: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12de: movzx  r11d,BYTE PTR [rdi-0x7] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e3: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12e6: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12ea: movzx  r14d,BYTE PTR [rdi-0x6] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ef: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12f2: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x12f6: movzx  r11d,BYTE PTR [rdi-0x5] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12fb: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12fe: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1302: movzx  r14d,BYTE PTR [rdi-0x4] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1307: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x130a: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x130e: movzx  r11d,BYTE PTR [rdi-0x3] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1313: xor    r11,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1316: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x131a: movzx  r14d,BYTE PTR [rdi-0x2] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x131f: xor    r14,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1322: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1326: movzx  ecx,BYTE PTR [rdi-0x1] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDI, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x132a: xor    rcx,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132d: imul   rcx,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_RCX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1331: movzx  r11d,BYTE PTR [rdi] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RDI, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1335: xor    r11,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1338: movzx  r14d,BYTE PTR [rdi-0x13] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RDI, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x133d: imul   r11,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R11, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1341: test   r14b,0x1 [control-flow-operand: test folded into BPF branch] */
    /* 0x1345: jne    1350 <bpftrace_comm_key_fnv_hash_xdp+0x250> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, (4) - 1, 1),
    /* 0x1347: mov    r9,QWORD PTR [rsp-0x48] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSP, -72), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x134c: jmp    13b1 <bpftrace_comm_key_fnv_hash_xdp+0x2b1> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (57) - 1, 0),
    /* 0x134e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1350: shl    r9d,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1354: shl    r8d,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1358: shl    ebp,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x135b: mov    rax,QWORD PTR [rsp-0x28] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RSP, -40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1360: shl    rax,0x30 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1364: mov    rcx,QWORD PTR [rsp-0x30] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RSP, -48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1369: shl    rcx,0x38 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x136d: mov    rdx,QWORD PTR [rsp-0x38] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RSP, -56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1372: shl    rdx,0x28 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1376: shl    r13,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R13, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x137a: or     r13,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x137d: or     r13,rax [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1380: or     r13,rcx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1383: or     r13,rbp [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1386: or     r13,r8 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1389: or     r13,r9 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x138c: or     r13,QWORD PTR [rsp-0x20] [exact-kop: or64 memory-source kop] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R13, HC_X86_RSP, -32), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1391: mov    r9,QWORD PTR [rsp-0x48] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSP, -72), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1396: mov    eax,r9d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1399: and    al,0x7 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x139b: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x139e: mov    rdx,r13 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13a1: shl    rdx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13a4: not    al [exact-kop: not8 reg kop] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13a6: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13a8: shr    r13,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13ab: or     r13,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R13, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13ae: xor    r11,r13 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13b1: test   r14b,0x2 [exact-kop: testb imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R14, 2), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x13b5: mov    r8,QWORD PTR [rsp-0x8] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R8, HC_X86_RSP, -8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ba: je     1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (-317) - 1, 0),
    /* 0x13c0: movabs rax,0x9e3779b185ebca87 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b185ebca87ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RAX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ca: add    rax,r11 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13cd: cmp    BYTE PTR [rdi-0xf],0x70 [exact-kop: cmp memory,imm kop] */
    HC_KOP(HC_X86_CMP_ARCH_MEM_IMM_PAYLOAD(HC_X86_RDI, -15, 112), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x13d1: cmove  r11,rax [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_ARCH_STACK_PAYLOAD(HC_X86_R11, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_CMOVEQ),
    /* 0x13d5: jmp    1160 <bpftrace_comm_key_fnv_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-328) - 1, 0),
    /* 0x13da: mov    rax,QWORD PTR [rsp-0x40] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RSP, -64), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13df: mov    QWORD PTR [rax],rsi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RSI, HC_X86_RAX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13e2: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e7: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13e8: pop    r12 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13ea: pop    r13 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R13), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13ec: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13ee: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13f0: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x13f1: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
