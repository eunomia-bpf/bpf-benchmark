# siphash_rotate64_mixer

## Original C
```c
#include "common.h"

/*
 * siphash_rotate64_mixer: SipHash-like hash using 64-bit rotations.
 *
 * Uses micro_rotl64() exclusively in the hot path so clang emits
 * the clean 4-insn rotate pattern (mov+lsh+rsh+or) without masking.
 * This exercises the ROTATE rewrite's 4-insn variant.
 *
 * Input: 8 u64 words (64 bytes) from the packet payload.
 * Output: 64-bit hash result.
 */

/*
 * SipHash-like round: 4 adds, 4 rotates, 2 xors per round.
 * Uses 64-bit rotations with varying amounts to create multiple
 * distinct rotate sites.
 */
#define SIPROUND(v0, v1, v2, v3)                \
    do {                                        \
        (v0) += (v1);                           \
        (v1) = micro_rotl64((v1), 13U);         \
        (v1) ^= (v0);                           \
        (v0) = micro_rotl64((v0), 32U);         \
        (v2) += (v3);                           \
        (v3) = micro_rotl64((v3), 16U);         \
        (v3) ^= (v2);                           \
        (v0) += (v3);                           \
        (v3) = micro_rotl64((v3), 21U);         \
        (v3) ^= (v0);                           \
        (v2) += (v1);                           \
        (v1) = micro_rotl64((v1), 17U);         \
        (v1) ^= (v2);                           \
        (v2) = micro_rotl64((v2), 32U);         \
    } while (0)

static __always_inline int
bench_siphash_rotate64_mixer(const u8 *data, u32 len, u64 *out)
{
    (void)len;

    u64 v0 = 0x736F6D6570736575ULL;
    u64 v1 = 0x646F72616E646F6DULL;
    u64 v2 = 0x6C7967656E657261ULL;
    u64 v3 = 0x7465646279746573ULL;

    /* Read 8 input words */
    u64 m0 = micro_read_u64_le(data, 0);
    u64 m1 = micro_read_u64_le(data, 8);
    u64 m2 = micro_read_u64_le(data, 16);
    u64 m3 = micro_read_u64_le(data, 24);
    u64 m4 = micro_read_u64_le(data, 32);
    u64 m5 = micro_read_u64_le(data, 40);
    u64 m6 = micro_read_u64_le(data, 48);
    u64 m7 = micro_read_u64_le(data, 56);

    /* Process each word: xor into v3, do 2 rounds, xor into v0 */
    v3 ^= m0;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m0;

    v3 ^= m1;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m1;

    v3 ^= m2;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m2;

    v3 ^= m3;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m3;

    v3 ^= m4;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m4;

    v3 ^= m5;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m5;

    v3 ^= m6;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m6;

    v3 ^= m7;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m7;

    /* Finalization: 4 rounds */
    v2 ^= 0xFF;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);

    *out = v0 ^ v1 ^ v2 ^ v3;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(siphash_rotate64_mixer_xdp, bench_siphash_rotate64_mixer,
                              siphash_rotate64_mixer_input, 64)
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

0000000000001100 <siphash_rotate64_mixer_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	0f 87 57 04 00 00    	ja     1569 <siphash_rotate64_mixer_xdp+0x469>
    1112:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1116:	48 39 d6             	cmp    rsi,rdx
    1119:	0f 87 4a 04 00 00    	ja     1569 <siphash_rotate64_mixer_xdp+0x469>
    111f:	48 8d 71 48          	lea    rsi,[rcx+0x48]
    1123:	48 39 d6             	cmp    rsi,rdx
    1126:	0f 87 3d 04 00 00    	ja     1569 <siphash_rotate64_mixer_xdp+0x469>
    112c:	4c 8b 49 08          	mov    r9,QWORD PTR [rcx+0x8]
    1130:	48 bf 73 65 74 79 62 	movabs rdi,0x7465646279746573
    1137:	64 65 74 
    113a:	4c 31 cf             	xor    rdi,r9
    113d:	48 ba 61 72 65 6e 65 	movabs rdx,0x6c7967656e657261
    1144:	67 79 6c 
    1147:	48 01 fa             	add    rdx,rdi
    114a:	48 b8 d0 ea 9f c1 6f 	movabs rax,0xa60c596fc19fead0
    1151:	59 0c a6 
    1154:	48 01 f8             	add    rax,rdi
    1157:	48 c1 c7 10          	rol    rdi,0x10
    115b:	48 31 d7             	xor    rdi,rdx
    115e:	49 b8 c6 df de d7 e2 	movabs r8,0xded7d4e2d7dedfc6
    1165:	d4 d7 de 
    1168:	49 01 f8             	add    r8,rdi
    116b:	48 c1 c7 15          	rol    rdi,0x15
    116f:	48 ba 25 73 de f0 74 	movabs rdx,0xe414a674f0de7325
    1176:	a6 14 e4 
    1179:	48 31 c2             	xor    rdx,rax
    117c:	48 c1 c0 20          	rol    rax,0x20
    1180:	4c 31 c7             	xor    rdi,r8
    1183:	49 01 d0             	add    r8,rdx
    1186:	48 c1 c2 0d          	rol    rdx,0xd
    118a:	4c 31 c2             	xor    rdx,r8
    118d:	49 c1 c0 20          	rol    r8,0x20
    1191:	48 01 f8             	add    rax,rdi
    1194:	48 c1 c7 10          	rol    rdi,0x10
    1198:	48 31 c7             	xor    rdi,rax
    119b:	49 01 f8             	add    r8,rdi
    119e:	48 c1 c7 15          	rol    rdi,0x15
    11a2:	48 01 d0             	add    rax,rdx
    11a5:	48 c1 c2 11          	rol    rdx,0x11
    11a9:	48 8b 71 10          	mov    rsi,QWORD PTR [rcx+0x10]
    11ad:	48 31 c2             	xor    rdx,rax
    11b0:	48 c1 c0 20          	rol    rax,0x20
    11b4:	4d 31 c1             	xor    r9,r8
    11b7:	49 01 d1             	add    r9,rdx
    11ba:	48 c1 c2 0d          	rol    rdx,0xd
    11be:	49 31 f0             	xor    r8,rsi
    11c1:	4c 31 ca             	xor    rdx,r9
    11c4:	49 c1 c1 20          	rol    r9,0x20
    11c8:	49 31 f8             	xor    r8,rdi
    11cb:	4c 01 c0             	add    rax,r8
    11ce:	49 c1 c0 10          	rol    r8,0x10
    11d2:	49 31 c0             	xor    r8,rax
    11d5:	4d 01 c1             	add    r9,r8
    11d8:	49 c1 c0 15          	rol    r8,0x15
    11dc:	48 01 d0             	add    rax,rdx
    11df:	48 c1 c2 11          	rol    rdx,0x11
    11e3:	48 31 c2             	xor    rdx,rax
    11e6:	48 c1 c0 20          	rol    rax,0x20
    11ea:	4d 31 c8             	xor    r8,r9
    11ed:	49 01 d1             	add    r9,rdx
    11f0:	48 c1 c2 0d          	rol    rdx,0xd
    11f4:	4c 31 ca             	xor    rdx,r9
    11f7:	49 c1 c1 20          	rol    r9,0x20
    11fb:	4c 01 c0             	add    rax,r8
    11fe:	49 c1 c0 10          	rol    r8,0x10
    1202:	49 31 c0             	xor    r8,rax
    1205:	4d 01 c1             	add    r9,r8
    1208:	49 c1 c0 15          	rol    r8,0x15
    120c:	48 01 d0             	add    rax,rdx
    120f:	48 c1 c2 11          	rol    rdx,0x11
    1213:	48 8b 79 18          	mov    rdi,QWORD PTR [rcx+0x18]
    1217:	48 31 c2             	xor    rdx,rax
    121a:	48 c1 c0 20          	rol    rax,0x20
    121e:	4c 31 ce             	xor    rsi,r9
    1221:	48 01 d6             	add    rsi,rdx
    1224:	48 c1 c2 0d          	rol    rdx,0xd
    1228:	49 31 f9             	xor    r9,rdi
    122b:	48 31 f2             	xor    rdx,rsi
    122e:	48 c1 c6 20          	rol    rsi,0x20
    1232:	4d 31 c1             	xor    r9,r8
    1235:	4c 01 c8             	add    rax,r9
    1238:	49 c1 c1 10          	rol    r9,0x10
    123c:	49 31 c1             	xor    r9,rax
    123f:	4c 01 ce             	add    rsi,r9
    1242:	49 c1 c1 15          	rol    r9,0x15
    1246:	48 01 d0             	add    rax,rdx
    1249:	48 c1 c2 11          	rol    rdx,0x11
    124d:	48 31 c2             	xor    rdx,rax
    1250:	48 c1 c0 20          	rol    rax,0x20
    1254:	49 31 f1             	xor    r9,rsi
    1257:	48 01 d6             	add    rsi,rdx
    125a:	48 c1 c2 0d          	rol    rdx,0xd
    125e:	48 31 f2             	xor    rdx,rsi
    1261:	48 c1 c6 20          	rol    rsi,0x20
    1265:	4c 01 c8             	add    rax,r9
    1268:	49 c1 c1 10          	rol    r9,0x10
    126c:	49 31 c1             	xor    r9,rax
    126f:	4c 01 ce             	add    rsi,r9
    1272:	49 c1 c1 15          	rol    r9,0x15
    1276:	48 01 d0             	add    rax,rdx
    1279:	48 c1 c2 11          	rol    rdx,0x11
    127d:	4c 8b 41 20          	mov    r8,QWORD PTR [rcx+0x20]
    1281:	48 31 c2             	xor    rdx,rax
    1284:	48 c1 c0 20          	rol    rax,0x20
    1288:	48 31 f7             	xor    rdi,rsi
    128b:	48 01 d7             	add    rdi,rdx
    128e:	48 c1 c2 0d          	rol    rdx,0xd
    1292:	4c 31 c6             	xor    rsi,r8
    1295:	48 31 fa             	xor    rdx,rdi
    1298:	48 c1 c7 20          	rol    rdi,0x20
    129c:	4c 31 ce             	xor    rsi,r9
    129f:	48 01 f0             	add    rax,rsi
    12a2:	48 c1 c6 10          	rol    rsi,0x10
    12a6:	48 31 c6             	xor    rsi,rax
    12a9:	48 01 f7             	add    rdi,rsi
    12ac:	48 c1 c6 15          	rol    rsi,0x15
    12b0:	48 01 d0             	add    rax,rdx
    12b3:	48 c1 c2 11          	rol    rdx,0x11
    12b7:	48 31 c2             	xor    rdx,rax
    12ba:	48 c1 c0 20          	rol    rax,0x20
    12be:	48 31 fe             	xor    rsi,rdi
    12c1:	48 01 d7             	add    rdi,rdx
    12c4:	48 c1 c2 0d          	rol    rdx,0xd
    12c8:	48 31 fa             	xor    rdx,rdi
    12cb:	48 c1 c7 20          	rol    rdi,0x20
    12cf:	48 01 f0             	add    rax,rsi
    12d2:	48 c1 c6 10          	rol    rsi,0x10
    12d6:	48 31 c6             	xor    rsi,rax
    12d9:	48 01 f7             	add    rdi,rsi
    12dc:	48 c1 c6 15          	rol    rsi,0x15
    12e0:	48 01 d0             	add    rax,rdx
    12e3:	48 c1 c2 11          	rol    rdx,0x11
    12e7:	4c 8b 49 28          	mov    r9,QWORD PTR [rcx+0x28]
    12eb:	48 31 c2             	xor    rdx,rax
    12ee:	48 c1 c0 20          	rol    rax,0x20
    12f2:	49 31 f8             	xor    r8,rdi
    12f5:	49 01 d0             	add    r8,rdx
    12f8:	48 c1 c2 0d          	rol    rdx,0xd
    12fc:	4c 31 cf             	xor    rdi,r9
    12ff:	4c 31 c2             	xor    rdx,r8
    1302:	49 c1 c0 20          	rol    r8,0x20
    1306:	48 31 f7             	xor    rdi,rsi
    1309:	48 01 f8             	add    rax,rdi
    130c:	48 c1 c7 10          	rol    rdi,0x10
    1310:	48 31 c7             	xor    rdi,rax
    1313:	49 01 f8             	add    r8,rdi
    1316:	48 c1 c7 15          	rol    rdi,0x15
    131a:	48 01 d0             	add    rax,rdx
    131d:	48 c1 c2 11          	rol    rdx,0x11
    1321:	48 31 c2             	xor    rdx,rax
    1324:	48 c1 c0 20          	rol    rax,0x20
    1328:	4c 31 c7             	xor    rdi,r8
    132b:	49 01 d0             	add    r8,rdx
    132e:	48 c1 c2 0d          	rol    rdx,0xd
    1332:	4c 31 c2             	xor    rdx,r8
    1335:	49 c1 c0 20          	rol    r8,0x20
    1339:	48 01 f8             	add    rax,rdi
    133c:	48 c1 c7 10          	rol    rdi,0x10
    1340:	48 31 c7             	xor    rdi,rax
    1343:	49 01 f8             	add    r8,rdi
    1346:	48 c1 c7 15          	rol    rdi,0x15
    134a:	48 01 d0             	add    rax,rdx
    134d:	48 c1 c2 11          	rol    rdx,0x11
    1351:	48 8b 71 30          	mov    rsi,QWORD PTR [rcx+0x30]
    1355:	48 31 c2             	xor    rdx,rax
    1358:	48 c1 c0 20          	rol    rax,0x20
    135c:	4d 31 c1             	xor    r9,r8
    135f:	49 01 d1             	add    r9,rdx
    1362:	48 c1 c2 0d          	rol    rdx,0xd
    1366:	49 31 f0             	xor    r8,rsi
    1369:	4c 31 ca             	xor    rdx,r9
    136c:	49 c1 c1 20          	rol    r9,0x20
    1370:	49 31 f8             	xor    r8,rdi
    1373:	4c 01 c0             	add    rax,r8
    1376:	49 c1 c0 10          	rol    r8,0x10
    137a:	49 31 c0             	xor    r8,rax
    137d:	4d 01 c1             	add    r9,r8
    1380:	49 c1 c0 15          	rol    r8,0x15
    1384:	48 01 d0             	add    rax,rdx
    1387:	48 c1 c2 11          	rol    rdx,0x11
    138b:	48 31 c2             	xor    rdx,rax
    138e:	48 c1 c0 20          	rol    rax,0x20
    1392:	4d 31 c8             	xor    r8,r9
    1395:	49 01 d1             	add    r9,rdx
    1398:	48 c1 c2 0d          	rol    rdx,0xd
    139c:	4c 31 ca             	xor    rdx,r9
    139f:	49 c1 c1 20          	rol    r9,0x20
    13a3:	4c 01 c0             	add    rax,r8
    13a6:	49 c1 c0 10          	rol    r8,0x10
    13aa:	49 31 c0             	xor    r8,rax
    13ad:	4d 01 c1             	add    r9,r8
    13b0:	49 c1 c0 15          	rol    r8,0x15
    13b4:	48 01 d0             	add    rax,rdx
    13b7:	48 c1 c2 11          	rol    rdx,0x11
    13bb:	48 8b 79 38          	mov    rdi,QWORD PTR [rcx+0x38]
    13bf:	48 31 c2             	xor    rdx,rax
    13c2:	48 c1 c0 20          	rol    rax,0x20
    13c6:	4c 31 ce             	xor    rsi,r9
    13c9:	48 01 d6             	add    rsi,rdx
    13cc:	48 c1 c2 0d          	rol    rdx,0xd
    13d0:	49 31 f9             	xor    r9,rdi
    13d3:	48 31 f2             	xor    rdx,rsi
    13d6:	48 c1 c6 20          	rol    rsi,0x20
    13da:	4d 31 c1             	xor    r9,r8
    13dd:	4c 01 c8             	add    rax,r9
    13e0:	49 c1 c1 10          	rol    r9,0x10
    13e4:	49 31 c1             	xor    r9,rax
    13e7:	4c 01 ce             	add    rsi,r9
    13ea:	49 c1 c1 15          	rol    r9,0x15
    13ee:	48 01 d0             	add    rax,rdx
    13f1:	48 c1 c2 11          	rol    rdx,0x11
    13f5:	48 31 c2             	xor    rdx,rax
    13f8:	48 c1 c0 20          	rol    rax,0x20
    13fc:	49 31 f1             	xor    r9,rsi
    13ff:	48 01 d6             	add    rsi,rdx
    1402:	48 c1 c2 0d          	rol    rdx,0xd
    1406:	48 31 f2             	xor    rdx,rsi
    1409:	48 c1 c6 20          	rol    rsi,0x20
    140d:	4c 01 c8             	add    rax,r9
    1410:	49 c1 c1 10          	rol    r9,0x10
    1414:	49 31 c1             	xor    r9,rax
    1417:	4c 01 ce             	add    rsi,r9
    141a:	49 c1 c1 15          	rol    r9,0x15
    141e:	48 01 d0             	add    rax,rdx
    1421:	48 c1 c2 11          	rol    rdx,0x11
    1425:	4c 8b 41 40          	mov    r8,QWORD PTR [rcx+0x40]
    1429:	48 31 c2             	xor    rdx,rax
    142c:	48 c1 c0 20          	rol    rax,0x20
    1430:	48 31 f7             	xor    rdi,rsi
    1433:	48 01 d7             	add    rdi,rdx
    1436:	48 c1 c2 0d          	rol    rdx,0xd
    143a:	4c 31 c6             	xor    rsi,r8
    143d:	48 31 fa             	xor    rdx,rdi
    1440:	48 c1 c7 20          	rol    rdi,0x20
    1444:	4c 31 ce             	xor    rsi,r9
    1447:	48 01 f0             	add    rax,rsi
    144a:	48 c1 c6 10          	rol    rsi,0x10
    144e:	48 31 c6             	xor    rsi,rax
    1451:	48 01 f7             	add    rdi,rsi
    1454:	48 c1 c6 15          	rol    rsi,0x15
    1458:	48 01 d0             	add    rax,rdx
    145b:	48 c1 c2 11          	rol    rdx,0x11
    145f:	48 31 c2             	xor    rdx,rax
    1462:	48 c1 c0 20          	rol    rax,0x20
    1466:	48 31 fe             	xor    rsi,rdi
    1469:	48 01 d7             	add    rdi,rdx
    146c:	48 c1 c2 0d          	rol    rdx,0xd
    1470:	48 31 fa             	xor    rdx,rdi
    1473:	48 c1 c7 20          	rol    rdi,0x20
    1477:	48 01 f0             	add    rax,rsi
    147a:	48 c1 c6 10          	rol    rsi,0x10
    147e:	48 31 c6             	xor    rsi,rax
    1481:	48 01 f7             	add    rdi,rsi
    1484:	48 c1 c6 15          	rol    rsi,0x15
    1488:	48 01 d0             	add    rax,rdx
    148b:	48 c1 c2 11          	rol    rdx,0x11
    148f:	48 31 fe             	xor    rsi,rdi
    1492:	48 31 c2             	xor    rdx,rax
    1495:	48 c1 c0 20          	rol    rax,0x20
    1499:	4c 31 c7             	xor    rdi,r8
    149c:	48 01 d7             	add    rdi,rdx
    149f:	48 c1 c2 0d          	rol    rdx,0xd
    14a3:	48 31 fa             	xor    rdx,rdi
    14a6:	48 c1 c7 20          	rol    rdi,0x20
    14aa:	48 35 ff 00 00 00    	xor    rax,0xff
    14b0:	48 01 f0             	add    rax,rsi
    14b3:	48 c1 c6 10          	rol    rsi,0x10
    14b7:	48 31 c6             	xor    rsi,rax
    14ba:	48 01 f7             	add    rdi,rsi
    14bd:	48 c1 c6 15          	rol    rsi,0x15
    14c1:	48 01 d0             	add    rax,rdx
    14c4:	48 c1 c2 11          	rol    rdx,0x11
    14c8:	48 31 c2             	xor    rdx,rax
    14cb:	48 c1 c0 20          	rol    rax,0x20
    14cf:	48 31 fe             	xor    rsi,rdi
    14d2:	48 01 d7             	add    rdi,rdx
    14d5:	48 c1 c2 0d          	rol    rdx,0xd
    14d9:	48 31 fa             	xor    rdx,rdi
    14dc:	48 c1 c7 20          	rol    rdi,0x20
    14e0:	48 01 f0             	add    rax,rsi
    14e3:	48 c1 c6 10          	rol    rsi,0x10
    14e7:	48 31 c6             	xor    rsi,rax
    14ea:	48 01 f7             	add    rdi,rsi
    14ed:	48 c1 c6 15          	rol    rsi,0x15
    14f1:	48 01 d0             	add    rax,rdx
    14f4:	48 c1 c2 11          	rol    rdx,0x11
    14f8:	48 31 c2             	xor    rdx,rax
    14fb:	48 c1 c0 20          	rol    rax,0x20
    14ff:	48 31 fe             	xor    rsi,rdi
    1502:	48 01 d7             	add    rdi,rdx
    1505:	48 c1 c2 0d          	rol    rdx,0xd
    1509:	48 31 fa             	xor    rdx,rdi
    150c:	48 c1 c7 20          	rol    rdi,0x20
    1510:	48 01 f0             	add    rax,rsi
    1513:	48 c1 c6 10          	rol    rsi,0x10
    1517:	48 31 c6             	xor    rsi,rax
    151a:	48 01 f7             	add    rdi,rsi
    151d:	48 c1 c6 15          	rol    rsi,0x15
    1521:	48 01 d0             	add    rax,rdx
    1524:	48 c1 c2 11          	rol    rdx,0x11
    1528:	48 31 c2             	xor    rdx,rax
    152b:	48 c1 c0 20          	rol    rax,0x20
    152f:	48 31 fe             	xor    rsi,rdi
    1532:	48 01 d7             	add    rdi,rdx
    1535:	48 c1 c2 0d          	rol    rdx,0xd
    1539:	48 01 f0             	add    rax,rsi
    153c:	48 c1 c6 10          	rol    rsi,0x10
    1540:	48 31 c6             	xor    rsi,rax
    1543:	48 c1 c6 15          	rol    rsi,0x15
    1547:	48 31 fa             	xor    rdx,rdi
    154a:	48 01 d0             	add    rax,rdx
    154d:	48 c1 c2 11          	rol    rdx,0x11
    1551:	48 89 c7             	mov    rdi,rax
    1554:	48 c1 c7 20          	rol    rdi,0x20
    1558:	48 31 d7             	xor    rdi,rdx
    155b:	48 31 f7             	xor    rdi,rsi
    155e:	48 31 c7             	xor    rdi,rax
    1561:	48 89 39             	mov    QWORD PTR [rcx],rdi
    1564:	b8 02 00 00 00       	mov    eax,0x2
    1569:	c3                   	ret

Disassembly of section .fini:

000000000000156c <_fini>:
    156c:	f3 0f 1e fa          	endbr64
    1570:	48 83 ec 08          	sub    rsp,0x8
    1574:	48 83 c4 08          	add    rsp,0x8
    1578:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 00 02 00 00 	sub    rsp,0x200
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 db                	xor    ebx,ebx
  1c:	45 31 ed             	xor    r13d,r13d
  1f:	45 31 f6             	xor    r14d,r14d
  22:	31 c0                	xor    eax,eax
  24:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  28:	4c 8b 7f 00          	mov    r15,QWORD PTR [rdi+0x0]
  2c:	49 39 f7             	cmp    r15,rsi
  2f:	0f 87 21 09 00 00    	ja     0x956
  35:	4c 89 ff             	mov    rdi,r15
  38:	48 83 c7 08          	add    rdi,0x8
  3c:	48 39 f7             	cmp    rdi,rsi
  3f:	0f 87 11 09 00 00    	ja     0x956
  45:	4c 89 ff             	mov    rdi,r15
  48:	48 83 c7 48          	add    rdi,0x48
  4c:	48 39 f7             	cmp    rdi,rsi
  4f:	0f 87 01 09 00 00    	ja     0x956
  55:	49 0f b6 7f 08       	movzx  rdi,BYTE PTR [r15+0x8]
  5a:	49 0f b6 77 09       	movzx  rsi,BYTE PTR [r15+0x9]
  5f:	48 c1 e6 08          	shl    rsi,0x8
  63:	48 09 fe             	or     rsi,rdi
  66:	49 0f b6 7f 0a       	movzx  rdi,BYTE PTR [r15+0xa]
  6b:	48 c1 e7 10          	shl    rdi,0x10
  6f:	48 09 f7             	or     rdi,rsi
  72:	49 0f b6 57 0b       	movzx  rdx,BYTE PTR [r15+0xb]
  77:	48 c1 e2 18          	shl    rdx,0x18
  7b:	48 09 fa             	or     rdx,rdi
  7e:	49 0f b6 7f 38       	movzx  rdi,BYTE PTR [r15+0x38]
  83:	49 0f b6 4f 39       	movzx  rcx,BYTE PTR [r15+0x39]
  88:	48 c1 e1 08          	shl    rcx,0x8
  8c:	48 09 f9             	or     rcx,rdi
  8f:	49 0f b6 77 40       	movzx  rsi,BYTE PTR [r15+0x40]
  94:	49 0f b6 7f 41       	movzx  rdi,BYTE PTR [r15+0x41]
  99:	48 c1 e7 08          	shl    rdi,0x8
  9d:	48 09 f7             	or     rdi,rsi
  a0:	49 0f b6 77 0c       	movzx  rsi,BYTE PTR [r15+0xc]
  a5:	48 c1 e6 20          	shl    rsi,0x20
  a9:	48 09 d6             	or     rsi,rdx
  ac:	49 0f b6 57 28       	movzx  rdx,BYTE PTR [r15+0x28]
  b1:	4d 0f b6 47 29       	movzx  r8,BYTE PTR [r15+0x29]
  b6:	49 c1 e0 08          	shl    r8,0x8
  ba:	49 09 d0             	or     r8,rdx
  bd:	4c 89 45 f8          	mov    QWORD PTR [rbp-0x8],r8
  c1:	49 0f b6 57 30       	movzx  rdx,BYTE PTR [r15+0x30]
  c6:	49 0f b6 47 31       	movzx  rax,BYTE PTR [r15+0x31]
  cb:	48 c1 e0 08          	shl    rax,0x8
  cf:	48 09 d0             	or     rax,rdx
  d2:	4d 0f b6 47 18       	movzx  r8,BYTE PTR [r15+0x18]
  d7:	49 0f b6 57 19       	movzx  rdx,BYTE PTR [r15+0x19]
  dc:	48 c1 e2 08          	shl    rdx,0x8
  e0:	4c 09 c2             	or     rdx,r8
  e3:	4d 0f b6 47 10       	movzx  r8,BYTE PTR [r15+0x10]
  e8:	49 0f b6 5f 11       	movzx  rbx,BYTE PTR [r15+0x11]
  ed:	48 c1 e3 08          	shl    rbx,0x8
  f1:	4c 09 c3             	or     rbx,r8
  f4:	48 89 5d f0          	mov    QWORD PTR [rbp-0x10],rbx
  f8:	4d 0f b6 47 42       	movzx  r8,BYTE PTR [r15+0x42]
  fd:	49 c1 e0 10          	shl    r8,0x10
 101:	49 09 f8             	or     r8,rdi
 104:	4d 0f b6 6f 3a       	movzx  r13,BYTE PTR [r15+0x3a]
 109:	49 c1 e5 10          	shl    r13,0x10
 10d:	49 09 cd             	or     r13,rcx
 110:	49 0f b6 5f 0d       	movzx  rbx,BYTE PTR [r15+0xd]
 115:	48 c1 e3 28          	shl    rbx,0x28
 119:	48 09 f3             	or     rbx,rsi
 11c:	49 0f b6 7f 20       	movzx  rdi,BYTE PTR [r15+0x20]
 121:	49 0f b6 77 21       	movzx  rsi,BYTE PTR [r15+0x21]
 126:	48 c1 e6 08          	shl    rsi,0x8
 12a:	48 09 fe             	or     rsi,rdi
 12d:	49 0f b6 4f 1a       	movzx  rcx,BYTE PTR [r15+0x1a]
 132:	48 c1 e1 10          	shl    rcx,0x10
 136:	48 09 d1             	or     rcx,rdx
 139:	4d 0f b6 77 32       	movzx  r14,BYTE PTR [r15+0x32]
 13e:	49 c1 e6 10          	shl    r14,0x10
 142:	49 09 c6             	or     r14,rax
 145:	49 0f b6 7f 2a       	movzx  rdi,BYTE PTR [r15+0x2a]
 14a:	48 c1 e7 10          	shl    rdi,0x10
 14e:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 152:	48 09 d7             	or     rdi,rdx
 155:	49 0f b6 47 0e       	movzx  rax,BYTE PTR [r15+0xe]
 15a:	48 c1 e0 30          	shl    rax,0x30
 15e:	48 09 d8             	or     rax,rbx
 161:	49 0f b6 57 3b       	movzx  rdx,BYTE PTR [r15+0x3b]
 166:	48 c1 e2 18          	shl    rdx,0x18
 16a:	4c 09 ea             	or     rdx,r13
 16d:	49 0f b6 5f 43       	movzx  rbx,BYTE PTR [r15+0x43]
 172:	48 c1 e3 18          	shl    rbx,0x18
 176:	4c 09 c3             	or     rbx,r8
 179:	4d 0f b6 47 12       	movzx  r8,BYTE PTR [r15+0x12]
 17e:	49 c1 e0 10          	shl    r8,0x10
 182:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 186:	4d 09 e8             	or     r8,r13
 189:	4d 0f b6 6f 22       	movzx  r13,BYTE PTR [r15+0x22]
 18e:	49 c1 e5 10          	shl    r13,0x10
 192:	49 09 f5             	or     r13,rsi
 195:	49 0f b6 77 2b       	movzx  rsi,BYTE PTR [r15+0x2b]
 19a:	48 c1 e6 18          	shl    rsi,0x18
 19e:	48 09 fe             	or     rsi,rdi
 1a1:	48 89 75 f8          	mov    QWORD PTR [rbp-0x8],rsi
 1a5:	49 0f b6 77 33       	movzx  rsi,BYTE PTR [r15+0x33]
 1aa:	48 c1 e6 18          	shl    rsi,0x18
 1ae:	4c 09 f6             	or     rsi,r14
 1b1:	49 0f b6 7f 1b       	movzx  rdi,BYTE PTR [r15+0x1b]
 1b6:	48 c1 e7 18          	shl    rdi,0x18
 1ba:	48 09 cf             	or     rdi,rcx
 1bd:	49 0f b6 4f 0f       	movzx  rcx,BYTE PTR [r15+0xf]
 1c2:	48 c1 e1 38          	shl    rcx,0x38
 1c6:	48 09 c1             	or     rcx,rax
 1c9:	48 89 4d f0          	mov    QWORD PTR [rbp-0x10],rcx
 1cd:	49 0f b6 47 23       	movzx  rax,BYTE PTR [r15+0x23]
 1d2:	48 c1 e0 18          	shl    rax,0x18
 1d6:	4c 09 e8             	or     rax,r13
 1d9:	49 0f b6 4f 13       	movzx  rcx,BYTE PTR [r15+0x13]
 1de:	48 c1 e1 18          	shl    rcx,0x18
 1e2:	4c 09 c1             	or     rcx,r8
 1e5:	48 89 4d d8          	mov    QWORD PTR [rbp-0x28],rcx
 1e9:	4d 0f b6 77 44       	movzx  r14,BYTE PTR [r15+0x44]
 1ee:	49 c1 e6 20          	shl    r14,0x20
 1f2:	49 09 de             	or     r14,rbx
 1f5:	49 0f b6 4f 3c       	movzx  rcx,BYTE PTR [r15+0x3c]
 1fa:	48 c1 e1 20          	shl    rcx,0x20
 1fe:	48 09 d1             	or     rcx,rdx
 201:	4d 0f b6 47 1c       	movzx  r8,BYTE PTR [r15+0x1c]
 206:	49 c1 e0 20          	shl    r8,0x20
 20a:	49 09 f8             	or     r8,rdi
 20d:	49 0f b6 57 34       	movzx  rdx,BYTE PTR [r15+0x34]
 212:	48 c1 e2 20          	shl    rdx,0x20
 216:	48 09 f2             	or     rdx,rsi
 219:	49 0f b6 77 2c       	movzx  rsi,BYTE PTR [r15+0x2c]
 21e:	48 c1 e6 20          	shl    rsi,0x20
 222:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 226:	48 09 fe             	or     rsi,rdi
 229:	48 bf 73 65 74 79 62 	movabs rdi,0x7465646279746573
 230:	64 65 74 
 233:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 237:	49 31 fd             	xor    r13,rdi
 23a:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 23e:	49 c1 c5 10          	rol    r13,0x10
 242:	49 0f b6 5f 24       	movzx  rbx,BYTE PTR [r15+0x24]
 247:	48 c1 e3 20          	shl    rbx,0x20
 24b:	48 09 c3             	or     rbx,rax
 24e:	49 0f b6 7f 3d       	movzx  rdi,BYTE PTR [r15+0x3d]
 253:	48 c1 e7 28          	shl    rdi,0x28
 257:	48 09 cf             	or     rdi,rcx
 25a:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 25e:	49 0f b6 47 45       	movzx  rax,BYTE PTR [r15+0x45]
 263:	48 c1 e0 28          	shl    rax,0x28
 267:	4c 09 f0             	or     rax,r14
 26a:	49 0f b6 7f 14       	movzx  rdi,BYTE PTR [r15+0x14]
 26f:	48 c1 e7 20          	shl    rdi,0x20
 273:	48 8b 4d d8          	mov    rcx,QWORD PTR [rbp-0x28]
 277:	48 09 cf             	or     rdi,rcx
 27a:	49 0f b6 4f 2d       	movzx  rcx,BYTE PTR [r15+0x2d]
 27f:	48 c1 e1 28          	shl    rcx,0x28
 283:	48 09 f1             	or     rcx,rsi
 286:	48 89 4d d8          	mov    QWORD PTR [rbp-0x28],rcx
 28a:	49 0f b6 77 35       	movzx  rsi,BYTE PTR [r15+0x35]
 28f:	48 c1 e6 28          	shl    rsi,0x28
 293:	48 09 d6             	or     rsi,rdx
 296:	4d 0f b6 77 1d       	movzx  r14,BYTE PTR [r15+0x1d]
 29b:	49 c1 e6 28          	shl    r14,0x28
 29f:	4d 09 c6             	or     r14,r8
 2a2:	49 0f b6 4f 25       	movzx  rcx,BYTE PTR [r15+0x25]
 2a7:	48 c1 e1 28          	shl    rcx,0x28
 2ab:	48 09 d9             	or     rcx,rbx
 2ae:	49 b8 61 72 65 6e 65 	movabs r8,0x6c7967656e657261
 2b5:	67 79 6c 
 2b8:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 2bc:	48 89 d3             	mov    rbx,rdx
 2bf:	4c 01 c3             	add    rbx,r8
 2c2:	49 31 dd             	xor    r13,rbx
 2c5:	4d 0f b6 47 15       	movzx  r8,BYTE PTR [r15+0x15]
 2ca:	49 c1 e0 28          	shl    r8,0x28
 2ce:	49 09 f8             	or     r8,rdi
 2d1:	48 bf d0 ea 9f c1 6f 	movabs rdi,0xa60c596fc19fead0
 2d8:	59 0c a6 
 2db:	48 01 fa             	add    rdx,rdi
 2de:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 2e2:	49 0f b6 7f 46       	movzx  rdi,BYTE PTR [r15+0x46]
 2e7:	48 c1 e7 30          	shl    rdi,0x30
 2eb:	48 09 c7             	or     rdi,rax
 2ee:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 2f2:	49 0f b6 7f 3e       	movzx  rdi,BYTE PTR [r15+0x3e]
 2f7:	48 c1 e7 30          	shl    rdi,0x30
 2fb:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 2ff:	48 09 d7             	or     rdi,rdx
 302:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 306:	49 0f b6 5f 36       	movzx  rbx,BYTE PTR [r15+0x36]
 30b:	48 c1 e3 30          	shl    rbx,0x30
 30f:	48 09 f3             	or     rbx,rsi
 312:	49 0f b6 47 2e       	movzx  rax,BYTE PTR [r15+0x2e]
 317:	48 c1 e0 30          	shl    rax,0x30
 31b:	48 8b 7d d8          	mov    rdi,QWORD PTR [rbp-0x28]
 31f:	48 09 f8             	or     rax,rdi
 322:	49 0f b6 57 26       	movzx  rdx,BYTE PTR [r15+0x26]
 327:	48 c1 e2 30          	shl    rdx,0x30
 32b:	48 09 ca             	or     rdx,rcx
 32e:	49 0f b6 77 1e       	movzx  rsi,BYTE PTR [r15+0x1e]
 333:	48 c1 e6 30          	shl    rsi,0x30
 337:	4c 09 f6             	or     rsi,r14
 33a:	49 0f b6 7f 16       	movzx  rdi,BYTE PTR [r15+0x16]
 33f:	48 c1 e7 30          	shl    rdi,0x30
 343:	4c 09 c7             	or     rdi,r8
 346:	48 b9 c6 df de d7 e2 	movabs rcx,0xded7d4e2d7dedfc6
 34d:	d4 d7 de 
 350:	4d 89 ee             	mov    r14,r13
 353:	49 01 ce             	add    r14,rcx
 356:	49 c1 c5 15          	rol    r13,0x15
 35a:	49 b8 25 73 de f0 74 	movabs r8,0xe414a674f0de7325
 361:	a6 14 e4 
 364:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 368:	4c 31 c1             	xor    rcx,r8
 36b:	49 89 c8             	mov    r8,rcx
 36e:	49 c1 c0 0d          	rol    r8,0xd
 372:	4c 89 45 a8          	mov    QWORD PTR [rbp-0x58],r8
 376:	4d 0f b6 47 17       	movzx  r8,BYTE PTR [r15+0x17]
 37b:	49 c1 e0 38          	shl    r8,0x38
 37f:	49 09 f8             	or     r8,rdi
 382:	4c 89 45 b0          	mov    QWORD PTR [rbp-0x50],r8
 386:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 38a:	49 0f b6 7f 1f       	movzx  rdi,BYTE PTR [r15+0x1f]
 38f:	48 c1 e7 38          	shl    rdi,0x38
 393:	48 09 f7             	or     rdi,rsi
 396:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 39a:	49 0f b6 7f 27       	movzx  rdi,BYTE PTR [r15+0x27]
 39f:	48 c1 e7 38          	shl    rdi,0x38
 3a3:	48 09 d7             	or     rdi,rdx
 3a6:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 3aa:	49 0f b6 7f 2f       	movzx  rdi,BYTE PTR [r15+0x2f]
 3af:	48 c1 e7 38          	shl    rdi,0x38
 3b3:	48 09 c7             	or     rdi,rax
 3b6:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 3ba:	49 0f b6 7f 37       	movzx  rdi,BYTE PTR [r15+0x37]
 3bf:	48 c1 e7 38          	shl    rdi,0x38
 3c3:	48 09 df             	or     rdi,rbx
 3c6:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 3ca:	49 0f b6 7f 3f       	movzx  rdi,BYTE PTR [r15+0x3f]
 3cf:	48 c1 e7 38          	shl    rdi,0x38
 3d3:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 3d7:	48 09 f7             	or     rdi,rsi
 3da:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 3de:	4d 0f b6 7f 47       	movzx  r15,BYTE PTR [r15+0x47]
 3e3:	49 c1 e7 38          	shl    r15,0x38
 3e7:	48 8b 75 b8          	mov    rsi,QWORD PTR [rbp-0x48]
 3eb:	49 09 f7             	or     r15,rsi
 3ee:	4d 31 f5             	xor    r13,r14
 3f1:	49 01 ce             	add    r14,rcx
 3f4:	4c 89 ee             	mov    rsi,r13
 3f7:	48 c1 c6 10          	rol    rsi,0x10
 3fb:	4c 89 f7             	mov    rdi,r14
 3fe:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
 402:	48 31 d7             	xor    rdi,rdx
 405:	48 89 f9             	mov    rcx,rdi
 408:	48 c1 c1 11          	rol    rcx,0x11
 40c:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 410:	48 c1 c2 20          	rol    rdx,0x20
 414:	49 01 d5             	add    r13,rdx
 417:	4c 89 ea             	mov    rdx,r13
 41a:	48 01 fa             	add    rdx,rdi
 41d:	48 31 d1             	xor    rcx,rdx
 420:	49 89 c8             	mov    r8,rcx
 423:	49 c1 c0 0d          	rol    r8,0xd
 427:	4c 31 ee             	xor    rsi,r13
 42a:	49 c1 c6 20          	rol    r14,0x20
 42e:	48 89 f3             	mov    rbx,rsi
 431:	4c 01 f3             	add    rbx,r14
 434:	48 89 df             	mov    rdi,rbx
 437:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 43b:	48 31 c7             	xor    rdi,rax
 43e:	48 01 cf             	add    rdi,rcx
 441:	49 89 fd             	mov    r13,rdi
 444:	4d 31 c5             	xor    r13,r8
 447:	4d 89 e8             	mov    r8,r13
 44a:	49 c1 c0 11          	rol    r8,0x11
 44e:	48 c1 c2 20          	rol    rdx,0x20
 452:	48 c1 c6 15          	rol    rsi,0x15
 456:	48 31 de             	xor    rsi,rbx
 459:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
 45d:	48 31 c6             	xor    rsi,rax
 460:	48 89 f1             	mov    rcx,rsi
 463:	48 01 d1             	add    rcx,rdx
 466:	48 c1 c6 10          	rol    rsi,0x10
 46a:	48 31 ce             	xor    rsi,rcx
 46d:	4c 01 e9             	add    rcx,r13
 470:	48 89 ca             	mov    rdx,rcx
 473:	4c 31 c2             	xor    rdx,r8
 476:	49 89 d5             	mov    r13,rdx
 479:	49 c1 c5 0d          	rol    r13,0xd
 47d:	48 89 f3             	mov    rbx,rsi
 480:	48 c1 c3 15          	rol    rbx,0x15
 484:	48 c1 c7 20          	rol    rdi,0x20
 488:	48 01 fe             	add    rsi,rdi
 48b:	48 31 f3             	xor    rbx,rsi
 48e:	48 01 d6             	add    rsi,rdx
 491:	49 31 f5             	xor    r13,rsi
 494:	4d 89 ee             	mov    r14,r13
 497:	49 c1 c6 11          	rol    r14,0x11
 49b:	48 89 da             	mov    rdx,rbx
 49e:	48 c1 c2 10          	rol    rdx,0x10
 4a2:	48 c1 c1 20          	rol    rcx,0x20
 4a6:	48 01 cb             	add    rbx,rcx
 4a9:	49 89 d8             	mov    r8,rbx
 4ac:	4d 01 e8             	add    r8,r13
 4af:	4d 31 c6             	xor    r14,r8
 4b2:	4c 89 f1             	mov    rcx,r14
 4b5:	48 c1 c1 0d          	rol    rcx,0xd
 4b9:	48 31 da             	xor    rdx,rbx
 4bc:	48 c1 c6 20          	rol    rsi,0x20
 4c0:	48 89 d3             	mov    rbx,rdx
 4c3:	48 01 f3             	add    rbx,rsi
 4c6:	48 89 df             	mov    rdi,rbx
 4c9:	48 31 c7             	xor    rdi,rax
 4cc:	4c 01 f7             	add    rdi,r14
 4cf:	48 89 fe             	mov    rsi,rdi
 4d2:	48 31 ce             	xor    rsi,rcx
 4d5:	48 89 f0             	mov    rax,rsi
 4d8:	48 c1 c0 11          	rol    rax,0x11
 4dc:	49 c1 c0 20          	rol    r8,0x20
 4e0:	48 c1 c2 15          	rol    rdx,0x15
 4e4:	48 31 da             	xor    rdx,rbx
 4e7:	4c 8b 75 c0          	mov    r14,QWORD PTR [rbp-0x40]
 4eb:	4c 31 f2             	xor    rdx,r14
 4ee:	48 89 d1             	mov    rcx,rdx
 4f1:	4c 01 c1             	add    rcx,r8
 4f4:	48 c1 c2 10          	rol    rdx,0x10
 4f8:	48 31 ca             	xor    rdx,rcx
 4fb:	48 01 f1             	add    rcx,rsi
 4fe:	48 89 ce             	mov    rsi,rcx
 501:	48 31 c6             	xor    rsi,rax
 504:	48 89 f3             	mov    rbx,rsi
 507:	48 c1 c3 0d          	rol    rbx,0xd
 50b:	48 89 d0             	mov    rax,rdx
 50e:	48 c1 c0 15          	rol    rax,0x15
 512:	48 c1 c7 20          	rol    rdi,0x20
 516:	48 01 fa             	add    rdx,rdi
 519:	48 31 d0             	xor    rax,rdx
 51c:	48 01 f2             	add    rdx,rsi
 51f:	48 31 d3             	xor    rbx,rdx
 522:	49 89 dd             	mov    r13,rbx
 525:	49 c1 c5 11          	rol    r13,0x11
 529:	48 89 c6             	mov    rsi,rax
 52c:	48 c1 c6 10          	rol    rsi,0x10
 530:	48 c1 c1 20          	rol    rcx,0x20
 534:	48 01 c8             	add    rax,rcx
 537:	49 89 c0             	mov    r8,rax
 53a:	49 01 d8             	add    r8,rbx
 53d:	4d 31 c5             	xor    r13,r8
 540:	4c 89 e9             	mov    rcx,r13
 543:	48 c1 c1 0d          	rol    rcx,0xd
 547:	48 31 c6             	xor    rsi,rax
 54a:	48 c1 c2 20          	rol    rdx,0x20
 54e:	48 89 f0             	mov    rax,rsi
 551:	48 01 d0             	add    rax,rdx
 554:	48 89 c7             	mov    rdi,rax
 557:	4c 31 f7             	xor    rdi,r14
 55a:	4c 01 ef             	add    rdi,r13
 55d:	48 89 fa             	mov    rdx,rdi
 560:	48 31 ca             	xor    rdx,rcx
 563:	48 89 d3             	mov    rbx,rdx
 566:	48 c1 c3 11          	rol    rbx,0x11
 56a:	49 c1 c0 20          	rol    r8,0x20
 56e:	48 c1 c6 15          	rol    rsi,0x15
 572:	48 31 c6             	xor    rsi,rax
 575:	4c 8b 75 c8          	mov    r14,QWORD PTR [rbp-0x38]
 579:	4c 31 f6             	xor    rsi,r14
 57c:	48 89 f1             	mov    rcx,rsi
 57f:	4c 01 c1             	add    rcx,r8
 582:	48 c1 c6 10          	rol    rsi,0x10
 586:	48 31 ce             	xor    rsi,rcx
 589:	48 01 d1             	add    rcx,rdx
 58c:	48 89 ca             	mov    rdx,rcx
 58f:	48 31 da             	xor    rdx,rbx
 592:	48 89 d3             	mov    rbx,rdx
 595:	48 c1 c3 0d          	rol    rbx,0xd
 599:	48 89 f0             	mov    rax,rsi
 59c:	48 c1 c0 15          	rol    rax,0x15
 5a0:	48 c1 c7 20          	rol    rdi,0x20
 5a4:	48 01 fe             	add    rsi,rdi
 5a7:	48 31 f0             	xor    rax,rsi
 5aa:	48 01 d6             	add    rsi,rdx
 5ad:	48 31 f3             	xor    rbx,rsi
 5b0:	49 89 dd             	mov    r13,rbx
 5b3:	49 c1 c5 11          	rol    r13,0x11
 5b7:	48 89 c2             	mov    rdx,rax
 5ba:	48 c1 c2 10          	rol    rdx,0x10
 5be:	48 c1 c1 20          	rol    rcx,0x20
 5c2:	48 01 c8             	add    rax,rcx
 5c5:	49 89 c0             	mov    r8,rax
 5c8:	49 01 d8             	add    r8,rbx
 5cb:	4d 31 c5             	xor    r13,r8
 5ce:	4c 89 e9             	mov    rcx,r13
 5d1:	48 c1 c1 0d          	rol    rcx,0xd
 5d5:	48 31 c2             	xor    rdx,rax
 5d8:	48 c1 c6 20          	rol    rsi,0x20
 5dc:	48 89 d0             	mov    rax,rdx
 5df:	48 01 f0             	add    rax,rsi
 5e2:	48 89 c7             	mov    rdi,rax
 5e5:	4c 31 f7             	xor    rdi,r14
 5e8:	4c 01 ef             	add    rdi,r13
 5eb:	48 89 fe             	mov    rsi,rdi
 5ee:	48 31 ce             	xor    rsi,rcx
 5f1:	48 89 f3             	mov    rbx,rsi
 5f4:	48 c1 c3 11          	rol    rbx,0x11
 5f8:	49 c1 c0 20          	rol    r8,0x20
 5fc:	48 c1 c2 15          	rol    rdx,0x15
 600:	48 31 c2             	xor    rdx,rax
 603:	4c 8b 75 d0          	mov    r14,QWORD PTR [rbp-0x30]
 607:	4c 31 f2             	xor    rdx,r14
 60a:	48 89 d1             	mov    rcx,rdx
 60d:	4c 01 c1             	add    rcx,r8
 610:	48 c1 c2 10          	rol    rdx,0x10
 614:	48 31 ca             	xor    rdx,rcx
 617:	48 01 f1             	add    rcx,rsi
 61a:	48 89 ce             	mov    rsi,rcx
 61d:	48 31 de             	xor    rsi,rbx
 620:	48 89 f3             	mov    rbx,rsi
 623:	48 c1 c3 0d          	rol    rbx,0xd
 627:	48 89 d0             	mov    rax,rdx
 62a:	48 c1 c0 15          	rol    rax,0x15
 62e:	48 c1 c7 20          	rol    rdi,0x20
 632:	48 01 fa             	add    rdx,rdi
 635:	48 31 d0             	xor    rax,rdx
 638:	48 01 f2             	add    rdx,rsi
 63b:	48 31 d3             	xor    rbx,rdx
 63e:	49 89 dd             	mov    r13,rbx
 641:	49 c1 c5 11          	rol    r13,0x11
 645:	48 89 c6             	mov    rsi,rax
 648:	48 c1 c6 10          	rol    rsi,0x10
 64c:	48 c1 c1 20          	rol    rcx,0x20
 650:	48 01 c8             	add    rax,rcx
 653:	49 89 c0             	mov    r8,rax
 656:	49 01 d8             	add    r8,rbx
 659:	4d 31 c5             	xor    r13,r8
 65c:	4c 89 e9             	mov    rcx,r13
 65f:	48 c1 c1 0d          	rol    rcx,0xd
 663:	48 31 c6             	xor    rsi,rax
 666:	48 c1 c2 20          	rol    rdx,0x20
 66a:	48 89 f0             	mov    rax,rsi
 66d:	48 01 d0             	add    rax,rdx
 670:	48 89 c7             	mov    rdi,rax
 673:	4c 31 f7             	xor    rdi,r14
 676:	4c 01 ef             	add    rdi,r13
 679:	48 89 fa             	mov    rdx,rdi
 67c:	48 31 ca             	xor    rdx,rcx
 67f:	48 89 d3             	mov    rbx,rdx
 682:	48 c1 c3 11          	rol    rbx,0x11
 686:	49 c1 c0 20          	rol    r8,0x20
 68a:	48 c1 c6 15          	rol    rsi,0x15
 68e:	48 31 c6             	xor    rsi,rax
 691:	4c 8b 75 d8          	mov    r14,QWORD PTR [rbp-0x28]
 695:	4c 31 f6             	xor    rsi,r14
 698:	48 89 f1             	mov    rcx,rsi
 69b:	4c 01 c1             	add    rcx,r8
 69e:	48 c1 c6 10          	rol    rsi,0x10
 6a2:	48 31 ce             	xor    rsi,rcx
 6a5:	48 01 d1             	add    rcx,rdx
 6a8:	48 89 ca             	mov    rdx,rcx
 6ab:	48 31 da             	xor    rdx,rbx
 6ae:	48 89 d3             	mov    rbx,rdx
 6b1:	48 c1 c3 0d          	rol    rbx,0xd
 6b5:	48 89 f0             	mov    rax,rsi
 6b8:	48 c1 c0 15          	rol    rax,0x15
 6bc:	48 c1 c7 20          	rol    rdi,0x20
 6c0:	48 01 fe             	add    rsi,rdi
 6c3:	48 31 f0             	xor    rax,rsi
 6c6:	48 01 d6             	add    rsi,rdx
 6c9:	48 31 f3             	xor    rbx,rsi
 6cc:	49 89 dd             	mov    r13,rbx
 6cf:	49 c1 c5 11          	rol    r13,0x11
 6d3:	48 89 c2             	mov    rdx,rax
 6d6:	48 c1 c2 10          	rol    rdx,0x10
 6da:	48 c1 c1 20          	rol    rcx,0x20
 6de:	48 01 c8             	add    rax,rcx
 6e1:	49 89 c0             	mov    r8,rax
 6e4:	49 01 d8             	add    r8,rbx
 6e7:	4d 31 c5             	xor    r13,r8
 6ea:	4c 89 e9             	mov    rcx,r13
 6ed:	48 c1 c1 0d          	rol    rcx,0xd
 6f1:	48 31 c2             	xor    rdx,rax
 6f4:	48 c1 c6 20          	rol    rsi,0x20
 6f8:	48 89 d0             	mov    rax,rdx
 6fb:	48 01 f0             	add    rax,rsi
 6fe:	48 89 c7             	mov    rdi,rax
 701:	4c 31 f7             	xor    rdi,r14
 704:	4c 01 ef             	add    rdi,r13
 707:	48 89 fe             	mov    rsi,rdi
 70a:	48 31 ce             	xor    rsi,rcx
 70d:	48 89 f3             	mov    rbx,rsi
 710:	48 c1 c3 11          	rol    rbx,0x11
 714:	49 c1 c0 20          	rol    r8,0x20
 718:	48 c1 c2 15          	rol    rdx,0x15
 71c:	48 31 c2             	xor    rdx,rax
 71f:	4c 8b 6d e0          	mov    r13,QWORD PTR [rbp-0x20]
 723:	4c 31 ea             	xor    rdx,r13
 726:	48 89 d1             	mov    rcx,rdx
 729:	4c 01 c1             	add    rcx,r8
 72c:	48 c1 c2 10          	rol    rdx,0x10
 730:	48 31 ca             	xor    rdx,rcx
 733:	48 01 f1             	add    rcx,rsi
 736:	48 89 ce             	mov    rsi,rcx
 739:	48 31 de             	xor    rsi,rbx
 73c:	48 89 f0             	mov    rax,rsi
 73f:	48 c1 c0 0d          	rol    rax,0xd
 743:	49 89 d0             	mov    r8,rdx
 746:	49 c1 c0 15          	rol    r8,0x15
 74a:	48 c1 c7 20          	rol    rdi,0x20
 74e:	48 01 fa             	add    rdx,rdi
 751:	49 31 d0             	xor    r8,rdx
 754:	48 01 f2             	add    rdx,rsi
 757:	48 31 d0             	xor    rax,rdx
 75a:	48 89 c3             	mov    rbx,rax
 75d:	48 c1 c3 11          	rol    rbx,0x11
 761:	4c 89 c6             	mov    rsi,r8
 764:	48 c1 c6 10          	rol    rsi,0x10
 768:	48 c1 c1 20          	rol    rcx,0x20
 76c:	49 01 c8             	add    r8,rcx
 76f:	4c 89 c1             	mov    rcx,r8
 772:	48 01 c1             	add    rcx,rax
 775:	48 31 cb             	xor    rbx,rcx
 778:	48 89 d8             	mov    rax,rbx
 77b:	48 c1 c0 0d          	rol    rax,0xd
 77f:	4c 31 c6             	xor    rsi,r8
 782:	48 c1 c2 20          	rol    rdx,0x20
 786:	49 89 f0             	mov    r8,rsi
 789:	49 01 d0             	add    r8,rdx
 78c:	4c 89 c7             	mov    rdi,r8
 78f:	4c 31 ef             	xor    rdi,r13
 792:	48 01 df             	add    rdi,rbx
 795:	48 89 fb             	mov    rbx,rdi
 798:	48 31 c3             	xor    rbx,rax
 79b:	48 89 d8             	mov    rax,rbx
 79e:	48 c1 c0 11          	rol    rax,0x11
 7a2:	48 c1 c1 20          	rol    rcx,0x20
 7a6:	48 c1 c6 15          	rol    rsi,0x15
 7aa:	4c 31 c6             	xor    rsi,r8
 7ad:	4c 31 fe             	xor    rsi,r15
 7b0:	48 89 f2             	mov    rdx,rsi
 7b3:	48 01 ca             	add    rdx,rcx
 7b6:	48 c1 c6 10          	rol    rsi,0x10
 7ba:	48 31 d6             	xor    rsi,rdx
 7bd:	48 01 da             	add    rdx,rbx
 7c0:	48 89 d1             	mov    rcx,rdx
 7c3:	48 31 c1             	xor    rcx,rax
 7c6:	49 89 cd             	mov    r13,rcx
 7c9:	49 c1 c5 0d          	rol    r13,0xd
 7cd:	48 89 f0             	mov    rax,rsi
 7d0:	48 c1 c0 15          	rol    rax,0x15
 7d4:	48 c1 c7 20          	rol    rdi,0x20
 7d8:	48 01 fe             	add    rsi,rdi
 7db:	48 31 f0             	xor    rax,rsi
 7de:	48 01 ce             	add    rsi,rcx
 7e1:	49 31 f5             	xor    r13,rsi
 7e4:	4c 89 eb             	mov    rbx,r13
 7e7:	48 c1 c3 11          	rol    rbx,0x11
 7eb:	48 89 c1             	mov    rcx,rax
 7ee:	48 c1 c1 10          	rol    rcx,0x10
 7f2:	48 c1 c2 20          	rol    rdx,0x20
 7f6:	48 01 d0             	add    rax,rdx
 7f9:	49 89 c0             	mov    r8,rax
 7fc:	4d 01 e8             	add    r8,r13
 7ff:	4c 31 c3             	xor    rbx,r8
 802:	49 89 dd             	mov    r13,rbx
 805:	49 c1 c5 0d          	rol    r13,0xd
 809:	48 31 c1             	xor    rcx,rax
 80c:	48 c1 c6 20          	rol    rsi,0x20
 810:	48 89 ca             	mov    rdx,rcx
 813:	48 c1 c2 15          	rol    rdx,0x15
 817:	48 01 f1             	add    rcx,rsi
 81a:	48 89 cf             	mov    rdi,rcx
 81d:	4c 31 ff             	xor    rdi,r15
 820:	48 01 df             	add    rdi,rbx
 823:	48 89 fb             	mov    rbx,rdi
 826:	4c 31 eb             	xor    rbx,r13
 829:	48 89 de             	mov    rsi,rbx
 82c:	48 c1 c6 11          	rol    rsi,0x11
 830:	48 31 ca             	xor    rdx,rcx
 833:	49 c1 c0 20          	rol    r8,0x20
 837:	49 81 f0 ff 00 00 00 	xor    r8,0xff
 83e:	49 01 d0             	add    r8,rdx
 841:	4c 01 c3             	add    rbx,r8
 844:	48 31 de             	xor    rsi,rbx
 847:	48 89 f1             	mov    rcx,rsi
 84a:	48 c1 c1 0d          	rol    rcx,0xd
 84e:	48 c1 c2 10          	rol    rdx,0x10
 852:	4c 31 c2             	xor    rdx,r8
 855:	48 c1 c7 20          	rol    rdi,0x20
 859:	48 01 d7             	add    rdi,rdx
 85c:	48 01 fe             	add    rsi,rdi
 85f:	48 31 f1             	xor    rcx,rsi
 862:	49 89 c8             	mov    r8,rcx
 865:	49 c1 c0 11          	rol    r8,0x11
 869:	48 c1 c3 20          	rol    rbx,0x20
 86d:	48 c1 c2 15          	rol    rdx,0x15
 871:	48 31 fa             	xor    rdx,rdi
 874:	48 01 d3             	add    rbx,rdx
 877:	48 01 d9             	add    rcx,rbx
 87a:	49 31 c8             	xor    r8,rcx
 87d:	4c 89 c0             	mov    rax,r8
 880:	48 c1 c0 0d          	rol    rax,0xd
 884:	48 c1 c2 10          	rol    rdx,0x10
 888:	48 31 da             	xor    rdx,rbx
 88b:	48 c1 c6 20          	rol    rsi,0x20
 88f:	48 01 d6             	add    rsi,rdx
 892:	49 01 f0             	add    r8,rsi
 895:	4c 31 c0             	xor    rax,r8
 898:	48 89 c3             	mov    rbx,rax
 89b:	48 c1 c3 11          	rol    rbx,0x11
 89f:	48 c1 c1 20          	rol    rcx,0x20
 8a3:	48 c1 c2 15          	rol    rdx,0x15
 8a7:	48 31 f2             	xor    rdx,rsi
 8aa:	48 01 d1             	add    rcx,rdx
 8ad:	48 01 c8             	add    rax,rcx
 8b0:	48 31 c3             	xor    rbx,rax
 8b3:	48 89 df             	mov    rdi,rbx
 8b6:	48 c1 c7 0d          	rol    rdi,0xd
 8ba:	48 c1 c2 10          	rol    rdx,0x10
 8be:	48 31 ca             	xor    rdx,rcx
 8c1:	49 c1 c0 20          	rol    r8,0x20
 8c5:	49 01 d0             	add    r8,rdx
 8c8:	4c 01 c3             	add    rbx,r8
 8cb:	48 31 df             	xor    rdi,rbx
 8ce:	48 c1 c0 20          	rol    rax,0x20
 8d2:	48 c1 c2 15          	rol    rdx,0x15
 8d6:	4c 31 c2             	xor    rdx,r8
 8d9:	48 01 d0             	add    rax,rdx
 8dc:	48 c1 c2 10          	rol    rdx,0x10
 8e0:	48 31 c2             	xor    rdx,rax
 8e3:	48 89 fe             	mov    rsi,rdi
 8e6:	48 01 c6             	add    rsi,rax
 8e9:	48 89 f1             	mov    rcx,rsi
 8ec:	48 c1 c1 20          	rol    rcx,0x20
 8f0:	48 c1 c2 15          	rol    rdx,0x15
 8f4:	48 c1 c7 11          	rol    rdi,0x11
 8f8:	48 31 fa             	xor    rdx,rdi
 8fb:	48 31 ca             	xor    rdx,rcx
 8fe:	48 31 f2             	xor    rdx,rsi
 901:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 905:	88 56 00             	mov    BYTE PTR [rsi+0x0],dl
 908:	48 89 d7             	mov    rdi,rdx
 90b:	48 c1 ef 38          	shr    rdi,0x38
 90f:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 913:	48 89 d7             	mov    rdi,rdx
 916:	48 c1 ef 30          	shr    rdi,0x30
 91a:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 91e:	48 89 d7             	mov    rdi,rdx
 921:	48 c1 ef 28          	shr    rdi,0x28
 925:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 929:	48 89 d7             	mov    rdi,rdx
 92c:	48 c1 ef 20          	shr    rdi,0x20
 930:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 934:	48 89 d7             	mov    rdi,rdx
 937:	48 c1 ef 18          	shr    rdi,0x18
 93b:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 93f:	48 89 d7             	mov    rdi,rdx
 942:	48 c1 ef 10          	shr    rdi,0x10
 946:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 94a:	48 c1 ea 08          	shr    rdx,0x8
 94e:	88 56 01             	mov    BYTE PTR [rsi+0x1],dl
 951:	b8 02 00 00 00       	mov    eax,0x2
 956:	41 5f                	pop    r15
 958:	41 5e                	pop    r14
 95a:	41 5d                	pop    r13
 95c:	5b                   	pop    rbx
 95d:	c9                   	leave
 95e:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
