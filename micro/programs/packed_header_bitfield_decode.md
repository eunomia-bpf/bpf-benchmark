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
    113a:	48 83 ec 18          	sub    rsp,0x18
    113e:	48 89 74 24 08       	mov    QWORD PTR [rsp+0x8],rsi
    1143:	48 8d 7e 1f          	lea    rdi,[rsi+0x1f]
    1147:	48 bb 09 c9 bc f3 67 	movabs rbx,0x6a09e667f3bcc909
    114e:	e6 09 6a 
    1151:	31 c0                	xor    eax,eax
    1153:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    1157:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    115e:	00 00 
    1160:	48 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],rbx
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
    128b:	4c 8b 04 24          	mov    r8,QWORD PTR [rsp]
    128f:	4c 01 c6             	add    rsi,r8
    1292:	48 01 c6             	add    rsi,rax
    1295:	48 8d 04 6d 00 00 00 	lea    rax,[rbp*2+0x0]
    129c:	00 
    129d:	48 01 e8             	add    rax,rbp
    12a0:	4e 8d 24 ed 00 00 00 	lea    r12,[r13*8+0x0]
    12a7:	00 
    12a8:	4d 29 ec             	sub    r12,r13
    12ab:	4f 8d 2c 92          	lea    r13,[r10+r10*4]
    12af:	49 31 c4             	xor    r12,rax
    12b2:	4d 31 ec             	xor    r12,r13
    12b5:	4b 8d 04 b6          	lea    rax,[r14+r14*4]
    12b9:	49 8d 04 46          	lea    rax,[r14+rax*2]
    12bd:	4f 8d 2c 7f          	lea    r13,[r15+r15*2]
    12c1:	4f 8d 3c af          	lea    r15,[r15+r13*4]
    12c5:	4c 8d 2c d2          	lea    r13,[rdx+rdx*8]
    12c9:	4d 31 fd             	xor    r13,r15
    12cc:	45 89 cf             	mov    r15d,r9d
    12cf:	41 c1 e7 04          	shl    r15d,0x4
    12d3:	4d 01 cf             	add    r15,r9
    12d6:	49 31 c7             	xor    r15,rax
    12d9:	4d 31 ef             	xor    r15,r13
    12dc:	48 8d 04 c9          	lea    rax,[rcx+rcx*8]
    12e0:	48 8d 04 41          	lea    rax,[rcx+rax*2]
    12e4:	4c 31 f8             	xor    rax,r15
    12e7:	80 e3 07             	and    bl,0x7
    12ea:	8d 4b 01             	lea    ecx,[rbx+0x1]
    12ed:	49 89 f7             	mov    r15,rsi
    12f0:	49 d3 e7             	shl    r15,cl
    12f3:	f6 d3                	not    bl
    12f5:	89 d9                	mov    ecx,ebx
    12f7:	48 d3 ee             	shr    rsi,cl
    12fa:	4c 01 e0             	add    rax,r12
    12fd:	4c 09 fe             	or     rsi,r15
    1300:	4c 31 de             	xor    rsi,r11
    1303:	48 03 74 24 10       	add    rsi,QWORD PTR [rsp+0x10]
    1308:	48 31 c6             	xor    rsi,rax
    130b:	4a 8d 1c 0a          	lea    rbx,[rdx+r9*1]
    130f:	4c 01 d3             	add    rbx,r10
    1312:	48 01 f3             	add    rbx,rsi
    1315:	44 31 f2             	xor    edx,r14d
    1318:	80 e2 0f             	and    dl,0xf
    131b:	8d 4a 01             	lea    ecx,[rdx+0x1]
    131e:	48 89 d8             	mov    rax,rbx
    1321:	48 d3 e0             	shl    rax,cl
    1324:	f6 d2                	not    dl
    1326:	89 d1                	mov    ecx,edx
    1328:	48 d3 eb             	shr    rbx,cl
    132b:	48 09 c3             	or     rbx,rax
    132e:	49 ff c0             	inc    r8
    1331:	48 83 c7 10          	add    rdi,0x10
    1335:	4c 89 c1             	mov    rcx,r8
    1338:	4c 89 04 24          	mov    QWORD PTR [rsp],r8
    133c:	49 83 f8 20          	cmp    r8,0x20
    1340:	0f 85 1a fe ff ff    	jne    1160 <packed_header_bitfield_decode_xdp+0x60>
    1346:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
    134b:	88 1a                	mov    BYTE PTR [rdx],bl
    134d:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
    1350:	89 c1                	mov    ecx,eax
    1352:	c1 e9 10             	shr    ecx,0x10
    1355:	88 4a 02             	mov    BYTE PTR [rdx+0x2],cl
    1358:	89 c1                	mov    ecx,eax
    135a:	c1 e9 18             	shr    ecx,0x18
    135d:	88 4a 03             	mov    BYTE PTR [rdx+0x3],cl
    1360:	48 89 c1             	mov    rcx,rax
    1363:	48 c1 e9 20          	shr    rcx,0x20
    1367:	88 4a 04             	mov    BYTE PTR [rdx+0x4],cl
    136a:	48 89 c1             	mov    rcx,rax
    136d:	48 c1 e9 28          	shr    rcx,0x28
    1371:	88 4a 05             	mov    BYTE PTR [rdx+0x5],cl
    1374:	48 89 c1             	mov    rcx,rax
    1377:	48 c1 e9 30          	shr    rcx,0x30
    137b:	88 4a 06             	mov    BYTE PTR [rdx+0x6],cl
    137e:	48 c1 e8 38          	shr    rax,0x38
    1382:	88 42 07             	mov    BYTE PTR [rdx+0x7],al
    1385:	b8 02 00 00 00       	mov    eax,0x2
    138a:	48 83 c4 18          	add    rsp,0x18
    138e:	5b                   	pop    rbx
    138f:	41 5c                	pop    r12
    1391:	41 5d                	pop    r13
    1393:	41 5e                	pop    r14
    1395:	41 5f                	pop    r15
    1397:	5d                   	pop    rbp
    1398:	c3                   	ret

Disassembly of section .fini:

000000000000139c <_fini>:
    139c:	f3 0f 1e fa          	endbr64
    13a0:	48 83 ec 08          	sub    rsp,0x8
    13a4:	48 83 c4 08          	add    rsp,0x8
    13a8:	c3                   	ret
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
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 07 04 00 00    	ja     0x434
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 f7 03 00 00    	ja     0x434
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 02 00 00 	add    rdi,0x210
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 e4 03 00 00    	ja     0x434
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	c1 e7 08             	shl    edi,0x8
  58:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5d:	09 f7                	or     edi,esi
  5f:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  64:	c1 e6 10             	shl    esi,0x10
  67:	09 f7                	or     edi,esi
  69:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  6e:	c1 e6 18             	shl    esi,0x18
  71:	09 f7                	or     edi,esi
  73:	83 ff 20             	cmp    edi,0x20
  76:	0f 85 b8 03 00 00    	jne    0x434
  7c:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  81:	c1 e7 08             	shl    edi,0x8
  84:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  89:	09 f7                	or     edi,esi
  8b:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  90:	c1 e6 10             	shl    esi,0x10
  93:	09 f7                	or     edi,esi
  95:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  9a:	c1 e6 18             	shl    esi,0x18
  9d:	09 f7                	or     edi,esi
  9f:	83 ff 02             	cmp    edi,0x2
  a2:	0f 85 8c 03 00 00    	jne    0x434
  a8:	48 b9 09 c9 bc f3 67 	movabs rcx,0x6a09e667f3bcc909
  af:	e6 09 6a 
  b2:	31 c0                	xor    eax,eax
  b4:	48 89 55 80          	mov    QWORD PTR [rbp-0x80],rdx
  b8:	48 89 d7             	mov    rdi,rdx
  bb:	48 83 c7 1f          	add    rdi,0x1f
  bf:	48 89 4d a8          	mov    QWORD PTR [rbp-0x58],rcx
  c3:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  c7:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
  cb:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
  cf:	48 0f b6 7f f8       	movzx  rdi,BYTE PTR [rdi-0x8]
  d4:	48 c1 e7 38          	shl    rdi,0x38
  d8:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
  dc:	48 0f b6 76 f7       	movzx  rsi,BYTE PTR [rsi-0x9]
  e1:	48 c1 e6 30          	shl    rsi,0x30
  e5:	48 09 fe             	or     rsi,rdi
  e8:	48 89 f2             	mov    rdx,rsi
  eb:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
  ef:	48 0f b6 7f f6       	movzx  rdi,BYTE PTR [rdi-0xa]
  f4:	48 c1 e7 28          	shl    rdi,0x28
  f8:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
  fc:	48 0f b6 46 f5       	movzx  rax,BYTE PTR [rsi-0xb]
 101:	48 c1 e0 20          	shl    rax,0x20
 105:	48 09 f8             	or     rax,rdi
 108:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 10c:	48 0f b6 7f f4       	movzx  rdi,BYTE PTR [rdi-0xc]
 111:	48 c1 e7 18          	shl    rdi,0x18
 115:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 119:	48 0f b6 76 f3       	movzx  rsi,BYTE PTR [rsi-0xd]
 11e:	48 c1 e6 10          	shl    rsi,0x10
 122:	48 09 fe             	or     rsi,rdi
 125:	48 89 f1             	mov    rcx,rsi
 128:	48 89 4d 98          	mov    QWORD PTR [rbp-0x68],rcx
 12c:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 130:	48 0f b6 77 f2       	movzx  rsi,BYTE PTR [rdi-0xe]
 135:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 139:	4c 0f b6 47 f1       	movzx  r8,BYTE PTR [rdi-0xf]
 13e:	4c 89 45 d0          	mov    QWORD PTR [rbp-0x30],r8
 142:	48 89 f7             	mov    rdi,rsi
 145:	48 c1 e6 08          	shl    rsi,0x8
 149:	4c 09 c6             	or     rsi,r8
 14c:	48 09 f1             	or     rcx,rsi
 14f:	48 89 4d f0          	mov    QWORD PTR [rbp-0x10],rcx
 153:	48 09 c8             	or     rax,rcx
 156:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
 15a:	48 09 c2             	or     rdx,rax
 15d:	48 89 55 b0          	mov    QWORD PTR [rbp-0x50],rdx
 161:	48 d1 ef             	shr    rdi,1
 164:	48 83 e7 1f          	and    rdi,0x1f
 168:	48 89 7d a0          	mov    QWORD PTR [rbp-0x60],rdi
 16c:	48 c1 ea 36          	shr    rdx,0x36
 170:	48 89 55 c8          	mov    QWORD PTR [rbp-0x38],rdx
 174:	48 6b d2 0b          	imul   rdx,rdx,0xb
 178:	48 6b ff 11          	imul   rdi,rdi,0x11
 17c:	48 31 d7             	xor    rdi,rdx
 17f:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 183:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 187:	48 0f b6 57 00       	movzx  rdx,BYTE PTR [rdi+0x0]
 18c:	48 c1 e2 38          	shl    rdx,0x38
 190:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 194:	4c 0f b6 7f ff       	movzx  r15,BYTE PTR [rdi-0x1]
 199:	49 c1 e7 30          	shl    r15,0x30
 19d:	49 09 d7             	or     r15,rdx
 1a0:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 1a4:	48 0f b6 57 fb       	movzx  rdx,BYTE PTR [rdi-0x5]
 1a9:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 1ad:	48 0f b6 7f fc       	movzx  rdi,BYTE PTR [rdi-0x4]
 1b2:	48 c1 e7 18          	shl    rdi,0x18
 1b6:	49 89 f8             	mov    r8,rdi
 1b9:	4c 89 45 d8          	mov    QWORD PTR [rbp-0x28],r8
 1bd:	48 c1 e2 10          	shl    rdx,0x10
 1c1:	48 89 55 88          	mov    QWORD PTR [rbp-0x78],rdx
 1c5:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 1c9:	48 0f b6 47 fa       	movzx  rax,BYTE PTR [rdi-0x6]
 1ce:	48 c1 e0 08          	shl    rax,0x8
 1d2:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 1d6:	48 0f b6 7f f9       	movzx  rdi,BYTE PTR [rdi-0x7]
 1db:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 1df:	48 89 c1             	mov    rcx,rax
 1e2:	48 09 f9             	or     rcx,rdi
 1e5:	4c 09 c2             	or     rdx,r8
 1e8:	48 09 ca             	or     rdx,rcx
 1eb:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 1ef:	4c 0f b6 77 fe       	movzx  r14,BYTE PTR [rdi-0x2]
 1f4:	49 c1 e6 28          	shl    r14,0x28
 1f8:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 1fc:	4c 0f b6 47 fd       	movzx  r8,BYTE PTR [rdi-0x3]
 201:	49 c1 e0 20          	shl    r8,0x20
 205:	4c 89 c3             	mov    rbx,r8
 208:	4c 09 f3             	or     rbx,r14
 20b:	48 89 5d 90          	mov    QWORD PTR [rbp-0x70],rbx
 20f:	48 09 d3             	or     rbx,rdx
 212:	4d 89 fd             	mov    r13,r15
 215:	49 09 dd             	or     r13,rbx
 218:	49 c1 ed 28          	shr    r13,0x28
 21c:	4c 89 ea             	mov    rdx,r13
 21f:	48 6b d2 09          	imul   rdx,rdx,0x9
 223:	48 8b 7d e0          	mov    rdi,QWORD PTR [rbp-0x20]
 227:	48 31 d7             	xor    rdi,rdx
 22a:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 22e:	48 8b 7d d0          	mov    rdi,QWORD PTR [rbp-0x30]
 232:	48 83 e7 3f          	and    rdi,0x3f
 236:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
 23a:	48 01 fa             	add    rdx,rdi
 23d:	48 c1 ee 06          	shr    rsi,0x6
 241:	48 83 e6 1f          	and    rsi,0x1f
 245:	48 01 f2             	add    rdx,rsi
 248:	4d 09 f7             	or     r15,r14
 24b:	48 c1 eb 18          	shr    rbx,0x18
 24f:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 256:	48 6b db 0d          	imul   rbx,rbx,0xd
 25a:	4c 8b 75 e0          	mov    r14,QWORD PTR [rbp-0x20]
 25e:	49 31 de             	xor    r14,rbx
 261:	48 8b 5d e8          	mov    rbx,QWORD PTR [rbp-0x18]
 265:	48 c1 eb 1e          	shr    rbx,0x1e
 269:	48 81 e3 ff 3f 00 00 	and    rbx,0x3fff
 270:	48 89 df             	mov    rdi,rbx
 273:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
 277:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 27b:	48 c1 ee 0b          	shr    rsi,0xb
 27f:	48 81 e6 ff 07 00 00 	and    rsi,0x7ff
 286:	48 01 f2             	add    rdx,rsi
 289:	48 89 55 e0          	mov    QWORD PTR [rbp-0x20],rdx
 28d:	48 6b f6 03          	imul   rsi,rsi,0x3
 291:	48 6b ff 05          	imul   rdi,rdi,0x5
 295:	48 31 fe             	xor    rsi,rdi
 298:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
 29c:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
 2a0:	49 09 d0             	or     r8,rdx
 2a3:	4c 89 c6             	mov    rsi,r8
 2a6:	4c 09 fe             	or     rsi,r15
 2a9:	48 8b 5d 88          	mov    rbx,QWORD PTR [rbp-0x78]
 2ad:	48 09 de             	or     rsi,rbx
 2b0:	48 09 c6             	or     rsi,rax
 2b3:	48 8b 7d c0          	mov    rdi,QWORD PTR [rbp-0x40]
 2b7:	48 01 fe             	add    rsi,rdi
 2ba:	48 83 e7 0f          	and    rdi,0xf
 2be:	48 c1 ee 28          	shr    rsi,0x28
 2c2:	48 01 fe             	add    rsi,rdi
 2c5:	09 da                	or     edx,ebx
 2c7:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
 2cb:	48 8b 7d 98          	mov    rdi,QWORD PTR [rbp-0x68]
 2cf:	48 c1 ef 16          	shr    rdi,0x16
 2d3:	48 81 e7 ff 00 00 00 	and    rdi,0xff
 2da:	4c 8b 7d e0          	mov    r15,QWORD PTR [rbp-0x20]
 2de:	49 01 ff             	add    r15,rdi
 2e1:	48 c1 e9 04          	shr    rcx,0x4
 2e5:	48 81 e1 ff 00 00 00 	and    rcx,0xff
 2ec:	48 6b c9 07          	imul   rcx,rcx,0x7
 2f0:	48 8b 5d f0          	mov    rbx,QWORD PTR [rbp-0x10]
 2f4:	48 31 cb             	xor    rbx,rcx
 2f7:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
 2fb:	48 c1 ea 26          	shr    rdx,0x26
 2ff:	48 83 e2 7f          	and    rdx,0x7f
 303:	48 89 d7             	mov    rdi,rdx
 306:	48 6b ff 13          	imul   rdi,rdi,0x13
 30a:	49 31 fe             	xor    r14,rdi
 30d:	49 c1 e8 18          	shr    r8,0x18
 311:	4c 01 c6             	add    rsi,r8
 314:	89 c7                	mov    edi,eax
 316:	48 8b 4d c0          	mov    rcx,QWORD PTR [rbp-0x40]
 31a:	09 cf                	or     edi,ecx
 31c:	48 8b 4d d8          	mov    rcx,QWORD PTR [rbp-0x28]
 320:	09 c8                	or     eax,ecx
 322:	c1 e8 0c             	shr    eax,0xc
 325:	48 25 ff 0f 00 00    	and    rax,0xfff
 32b:	48 01 c6             	add    rsi,rax
 32e:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
 332:	48 01 d6             	add    rsi,rdx
 335:	c1 ef 04             	shr    edi,0x4
 338:	48 81 e7 ff 00 00 00 	and    rdi,0xff
 33f:	48 01 fe             	add    rsi,rdi
 342:	49 01 de             	add    r14,rbx
 345:	44 89 ef             	mov    edi,r13d
 348:	48 8b 4d c8          	mov    rcx,QWORD PTR [rbp-0x38]
 34c:	31 cf                	xor    edi,ecx
 34e:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
 352:	49 01 cf             	add    r15,rcx
 355:	4c 8b 45 a0          	mov    r8,QWORD PTR [rbp-0x60]
 359:	4d 01 c5             	add    r13,r8
 35c:	49 01 cd             	add    r13,rcx
 35f:	48 8b 4d b0          	mov    rcx,QWORD PTR [rbp-0x50]
 363:	48 c1 e9 2c          	shr    rcx,0x2c
 367:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
 36e:	49 01 cf             	add    r15,rcx
 371:	4c 01 c6             	add    rsi,r8
 374:	4c 8b 45 d0          	mov    r8,QWORD PTR [rbp-0x30]
 378:	41 83 e0 07          	and    r8d,0x7
 37c:	44 89 c1             	mov    ecx,r8d
 37f:	83 c1 01             	add    ecx,0x1
 382:	41 83 f0 3f          	xor    r8d,0x3f
 386:	4c 89 c3             	mov    rbx,r8
 389:	49 89 c0             	mov    r8,rax
 38c:	49 01 f0             	add    r8,rsi
 38f:	4c 89 c6             	mov    rsi,r8
 392:	c4 e2 e3 f7 f6       	shrx   rsi,rsi,rbx
 397:	49 d3 e0             	shl    r8,cl
 39a:	49 09 f0             	or     r8,rsi
 39d:	4d 31 f8             	xor    r8,r15
 3a0:	48 8b 75 a8          	mov    rsi,QWORD PTR [rbp-0x58]
 3a4:	49 01 f0             	add    r8,rsi
 3a7:	4d 31 f0             	xor    r8,r14
 3aa:	4d 01 c5             	add    r13,r8
 3ad:	83 e7 0f             	and    edi,0xf
 3b0:	89 fe                	mov    esi,edi
 3b2:	83 c6 01             	add    esi,0x1
 3b5:	83 f7 3f             	xor    edi,0x3f
 3b8:	4c 89 ea             	mov    rdx,r13
 3bb:	c4 e2 c3 f7 d2       	shrx   rdx,rdx,rdi
 3c0:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 3c4:	c4 42 c9 f7 ed       	shlx   r13,r13,rsi
 3c9:	48 83 c7 10          	add    rdi,0x10
 3cd:	4c 89 e9             	mov    rcx,r13
 3d0:	48 09 d1             	or     rcx,rdx
 3d3:	48 83 c0 01          	add    rax,0x1
 3d7:	48 83 f8 20          	cmp    rax,0x20
 3db:	74 05                	je     0x3e2
 3dd:	e9 dd fc ff ff       	jmp    0xbf
 3e2:	48 8b 75 80          	mov    rsi,QWORD PTR [rbp-0x80]
 3e6:	88 4e 00             	mov    BYTE PTR [rsi+0x0],cl
 3e9:	4c 89 ef             	mov    rdi,r13
 3ec:	48 c1 ef 38          	shr    rdi,0x38
 3f0:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3f4:	4c 89 ef             	mov    rdi,r13
 3f7:	48 c1 ef 30          	shr    rdi,0x30
 3fb:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3ff:	4c 89 ef             	mov    rdi,r13
 402:	48 c1 ef 28          	shr    rdi,0x28
 406:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 40a:	4c 89 ef             	mov    rdi,r13
 40d:	48 c1 ef 20          	shr    rdi,0x20
 411:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 415:	4c 89 ef             	mov    rdi,r13
 418:	48 c1 ef 18          	shr    rdi,0x18
 41c:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 420:	49 c1 ed 10          	shr    r13,0x10
 424:	44 88 6e 02          	mov    BYTE PTR [rsi+0x2],r13b
 428:	48 c1 e9 08          	shr    rcx,0x8
 42c:	88 4e 01             	mov    BYTE PTR [rsi+0x1],cl
 42f:	b8 02 00 00 00       	mov    eax,0x2
 434:	41 5f                	pop    r15
 436:	41 5e                	pop    r14
 438:	41 5d                	pop    r13
 43a:	5b                   	pop    rbx
 43b:	c9                   	leave
 43c:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
