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
   c:	48 81 ec 48 00 00 00 	sub    rsp,0x48
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 8a 0d 00 00    	ja     0xdb7
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 7a 0d 00 00    	ja     0xdb7
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 83 c7 48          	add    rdi,0x48
  44:	48 39 f7             	cmp    rdi,rsi
  47:	0f 87 6a 0d 00 00    	ja     0xdb7
  4d:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  52:	48 c1 e7 08          	shl    rdi,0x8
  56:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5b:	48 09 f7             	or     rdi,rsi
  5e:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  63:	48 c1 e6 10          	shl    rsi,0x10
  67:	48 09 fe             	or     rsi,rdi
  6a:	48 0f b6 7a 0b       	movzx  rdi,BYTE PTR [rdx+0xb]
  6f:	48 c1 e7 18          	shl    rdi,0x18
  73:	48 09 f7             	or     rdi,rsi
  76:	48 0f b6 4a 31       	movzx  rcx,BYTE PTR [rdx+0x31]
  7b:	48 c1 e1 08          	shl    rcx,0x8
  7f:	48 0f b6 72 30       	movzx  rsi,BYTE PTR [rdx+0x30]
  84:	48 09 f1             	or     rcx,rsi
  87:	4c 0f b6 42 39       	movzx  r8,BYTE PTR [rdx+0x39]
  8c:	49 c1 e0 08          	shl    r8,0x8
  90:	48 0f b6 72 38       	movzx  rsi,BYTE PTR [rdx+0x38]
  95:	49 09 f0             	or     r8,rsi
  98:	48 0f b6 42 41       	movzx  rax,BYTE PTR [rdx+0x41]
  9d:	48 c1 e0 08          	shl    rax,0x8
  a1:	48 0f b6 72 40       	movzx  rsi,BYTE PTR [rdx+0x40]
  a6:	48 09 f0             	or     rax,rsi
  a9:	48 0f b6 72 29       	movzx  rsi,BYTE PTR [rdx+0x29]
  ae:	48 c1 e6 08          	shl    rsi,0x8
  b2:	49 89 d7             	mov    r15,rdx
  b5:	49 0f b6 57 28       	movzx  rdx,BYTE PTR [r15+0x28]
  ba:	48 09 d6             	or     rsi,rdx
  bd:	49 0f b6 5f 0c       	movzx  rbx,BYTE PTR [r15+0xc]
  c2:	48 c1 e3 20          	shl    rbx,0x20
  c6:	48 09 fb             	or     rbx,rdi
  c9:	49 0f b6 7f 11       	movzx  rdi,BYTE PTR [r15+0x11]
  ce:	48 c1 e7 08          	shl    rdi,0x8
  d2:	49 0f b6 57 10       	movzx  rdx,BYTE PTR [r15+0x10]
  d7:	48 09 d7             	or     rdi,rdx
  da:	49 0f b6 57 42       	movzx  rdx,BYTE PTR [r15+0x42]
  df:	48 c1 e2 10          	shl    rdx,0x10
  e3:	48 09 c2             	or     rdx,rax
  e6:	49 0f b6 47 3a       	movzx  rax,BYTE PTR [r15+0x3a]
  eb:	48 c1 e0 10          	shl    rax,0x10
  ef:	4c 09 c0             	or     rax,r8
  f2:	4d 0f b6 47 32       	movzx  r8,BYTE PTR [r15+0x32]
  f7:	49 c1 e0 10          	shl    r8,0x10
  fb:	49 09 c8             	or     r8,rcx
  fe:	4d 0f b6 6f 21       	movzx  r13,BYTE PTR [r15+0x21]
 103:	49 c1 e5 08          	shl    r13,0x8
 107:	49 0f b6 4f 20       	movzx  rcx,BYTE PTR [r15+0x20]
 10c:	49 09 cd             	or     r13,rcx
 10f:	4d 0f b6 77 0d       	movzx  r14,BYTE PTR [r15+0xd]
 114:	49 c1 e6 28          	shl    r14,0x28
 118:	49 09 de             	or     r14,rbx
 11b:	49 0f b6 4f 0e       	movzx  rcx,BYTE PTR [r15+0xe]
 120:	48 c1 e1 30          	shl    rcx,0x30
 124:	4c 09 f1             	or     rcx,r14
 127:	49 0f b6 5f 2a       	movzx  rbx,BYTE PTR [r15+0x2a]
 12c:	48 c1 e3 10          	shl    rbx,0x10
 130:	48 09 f3             	or     rbx,rsi
 133:	4d 0f b6 77 22       	movzx  r14,BYTE PTR [r15+0x22]
 138:	49 c1 e6 10          	shl    r14,0x10
 13c:	4d 09 ee             	or     r14,r13
 13f:	49 0f b6 77 33       	movzx  rsi,BYTE PTR [r15+0x33]
 144:	48 c1 e6 18          	shl    rsi,0x18
 148:	4c 09 c6             	or     rsi,r8
 14b:	4d 0f b6 47 3b       	movzx  r8,BYTE PTR [r15+0x3b]
 150:	49 c1 e0 18          	shl    r8,0x18
 154:	49 09 c0             	or     r8,rax
 157:	4d 0f b6 6f 43       	movzx  r13,BYTE PTR [r15+0x43]
 15c:	4c 89 f8             	mov    rax,r15
 15f:	49 c1 e5 18          	shl    r13,0x18
 163:	49 09 d5             	or     r13,rdx
 166:	4c 0f b6 78 12       	movzx  r15,BYTE PTR [rax+0x12]
 16b:	49 c1 e7 10          	shl    r15,0x10
 16f:	49 09 ff             	or     r15,rdi
 172:	48 0f b6 78 19       	movzx  rdi,BYTE PTR [rax+0x19]
 177:	48 c1 e7 08          	shl    rdi,0x8
 17b:	48 0f b6 50 18       	movzx  rdx,BYTE PTR [rax+0x18]
 180:	48 09 d7             	or     rdi,rdx
 183:	48 0f b6 50 23       	movzx  rdx,BYTE PTR [rax+0x23]
 188:	48 c1 e2 18          	shl    rdx,0x18
 18c:	4c 09 f2             	or     rdx,r14
 18f:	49 89 c6             	mov    r14,rax
 192:	49 0f b6 46 2b       	movzx  rax,BYTE PTR [r14+0x2b]
 197:	48 c1 e0 18          	shl    rax,0x18
 19b:	48 09 d8             	or     rax,rbx
 19e:	49 0f b6 5e 0f       	movzx  rbx,BYTE PTR [r14+0xf]
 1a3:	48 c1 e3 38          	shl    rbx,0x38
 1a7:	48 09 cb             	or     rbx,rcx
 1aa:	48 89 5d f0          	mov    QWORD PTR [rbp-0x10],rbx
 1ae:	49 0f b6 4e 1a       	movzx  rcx,BYTE PTR [r14+0x1a]
 1b3:	48 c1 e1 10          	shl    rcx,0x10
 1b7:	48 09 f9             	or     rcx,rdi
 1ba:	49 0f b6 7e 13       	movzx  rdi,BYTE PTR [r14+0x13]
 1bf:	48 c1 e7 18          	shl    rdi,0x18
 1c3:	4c 09 ff             	or     rdi,r15
 1c6:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 1ca:	49 0f b6 7e 44       	movzx  rdi,BYTE PTR [r14+0x44]
 1cf:	48 c1 e7 20          	shl    rdi,0x20
 1d3:	4c 09 ef             	or     rdi,r13
 1d6:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 1da:	49 0f b6 5e 3c       	movzx  rbx,BYTE PTR [r14+0x3c]
 1df:	48 c1 e3 20          	shl    rbx,0x20
 1e3:	4c 09 c3             	or     rbx,r8
 1e6:	4d 0f b6 7e 34       	movzx  r15,BYTE PTR [r14+0x34]
 1eb:	49 c1 e7 20          	shl    r15,0x20
 1ef:	49 09 f7             	or     r15,rsi
 1f2:	49 0f b6 76 1b       	movzx  rsi,BYTE PTR [r14+0x1b]
 1f7:	48 c1 e6 18          	shl    rsi,0x18
 1fb:	48 09 ce             	or     rsi,rcx
 1fe:	48 bf 73 65 74 79 62 	movabs rdi,0x7465646279746573
 205:	64 65 74 
 208:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 20c:	49 31 fd             	xor    r13,rdi
 20f:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 213:	4c 89 ef             	mov    rdi,r13
 216:	48 c1 ef 30          	shr    rdi,0x30
 21a:	49 c1 e5 10          	shl    r13,0x10
 21e:	49 09 fd             	or     r13,rdi
 221:	4d 0f b6 46 2c       	movzx  r8,BYTE PTR [r14+0x2c]
 226:	49 c1 e0 20          	shl    r8,0x20
 22a:	49 09 c0             	or     r8,rax
 22d:	49 0f b6 4e 24       	movzx  rcx,BYTE PTR [r14+0x24]
 232:	48 c1 e1 20          	shl    rcx,0x20
 236:	48 09 d1             	or     rcx,rdx
 239:	49 0f b6 7e 1c       	movzx  rdi,BYTE PTR [r14+0x1c]
 23e:	48 c1 e7 20          	shl    rdi,0x20
 242:	48 09 f7             	or     rdi,rsi
 245:	49 0f b6 76 35       	movzx  rsi,BYTE PTR [r14+0x35]
 24a:	48 c1 e6 28          	shl    rsi,0x28
 24e:	4c 09 fe             	or     rsi,r15
 251:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
 255:	49 0f b6 46 3d       	movzx  rax,BYTE PTR [r14+0x3d]
 25a:	48 c1 e0 28          	shl    rax,0x28
 25e:	48 09 d8             	or     rax,rbx
 261:	49 0f b6 56 45       	movzx  rdx,BYTE PTR [r14+0x45]
 266:	48 c1 e2 28          	shl    rdx,0x28
 26a:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 26e:	48 09 f2             	or     rdx,rsi
 271:	49 0f b6 5e 14       	movzx  rbx,BYTE PTR [r14+0x14]
 276:	48 c1 e3 20          	shl    rbx,0x20
 27a:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 27e:	48 09 f3             	or     rbx,rsi
 281:	49 0f b6 76 1d       	movzx  rsi,BYTE PTR [r14+0x1d]
 286:	48 c1 e6 28          	shl    rsi,0x28
 28a:	48 09 fe             	or     rsi,rdi
 28d:	48 89 75 c8          	mov    QWORD PTR [rbp-0x38],rsi
 291:	4d 0f b6 7e 25       	movzx  r15,BYTE PTR [r14+0x25]
 296:	49 c1 e7 28          	shl    r15,0x28
 29a:	49 09 cf             	or     r15,rcx
 29d:	49 0f b6 76 2d       	movzx  rsi,BYTE PTR [r14+0x2d]
 2a2:	48 c1 e6 28          	shl    rsi,0x28
 2a6:	4c 09 c6             	or     rsi,r8
 2a9:	48 b9 61 72 65 6e 65 	movabs rcx,0x6c7967656e657261
 2b0:	67 79 6c 
 2b3:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 2b7:	49 89 f8             	mov    r8,rdi
 2ba:	49 01 c8             	add    r8,rcx
 2bd:	4d 31 c5             	xor    r13,r8
 2c0:	49 0f b6 4e 15       	movzx  rcx,BYTE PTR [r14+0x15]
 2c5:	48 c1 e1 28          	shl    rcx,0x28
 2c9:	48 09 d9             	or     rcx,rbx
 2cc:	49 b8 d0 ea 9f c1 6f 	movabs r8,0xa60c596fc19fead0
 2d3:	59 0c a6 
 2d6:	4c 01 c7             	add    rdi,r8
 2d9:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
 2dd:	4c 89 f3             	mov    rbx,r14
 2e0:	48 0f b6 7b 46       	movzx  rdi,BYTE PTR [rbx+0x46]
 2e5:	48 c1 e7 30          	shl    rdi,0x30
 2e9:	48 09 d7             	or     rdi,rdx
 2ec:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 2f0:	48 0f b6 7b 3e       	movzx  rdi,BYTE PTR [rbx+0x3e]
 2f5:	48 c1 e7 30          	shl    rdi,0x30
 2f9:	48 09 c7             	or     rdi,rax
 2fc:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 300:	48 0f b6 7b 36       	movzx  rdi,BYTE PTR [rbx+0x36]
 305:	48 c1 e7 30          	shl    rdi,0x30
 309:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 30d:	48 09 d7             	or     rdi,rdx
 310:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 314:	4c 0f b6 73 2e       	movzx  r14,BYTE PTR [rbx+0x2e]
 319:	49 c1 e6 30          	shl    r14,0x30
 31d:	49 09 f6             	or     r14,rsi
 320:	4c 0f b6 43 26       	movzx  r8,BYTE PTR [rbx+0x26]
 325:	49 c1 e0 30          	shl    r8,0x30
 329:	4d 09 f8             	or     r8,r15
 32c:	48 0f b6 53 1e       	movzx  rdx,BYTE PTR [rbx+0x1e]
 331:	48 c1 e2 30          	shl    rdx,0x30
 335:	48 8b 7d c8          	mov    rdi,QWORD PTR [rbp-0x38]
 339:	48 09 fa             	or     rdx,rdi
 33c:	48 0f b6 7b 16       	movzx  rdi,BYTE PTR [rbx+0x16]
 341:	48 c1 e7 30          	shl    rdi,0x30
 345:	48 09 cf             	or     rdi,rcx
 348:	48 b9 c6 df de d7 e2 	movabs rcx,0xded7d4e2d7dedfc6
 34f:	d4 d7 de 
 352:	4c 89 ee             	mov    rsi,r13
 355:	48 01 ce             	add    rsi,rcx
 358:	4c 89 e9             	mov    rcx,r13
 35b:	48 c1 e9 2b          	shr    rcx,0x2b
 35f:	49 c1 e5 15          	shl    r13,0x15
 363:	49 09 cd             	or     r13,rcx
 366:	48 b8 25 73 de f0 74 	movabs rax,0xe414a674f0de7325
 36d:	a6 14 e4 
 370:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 374:	48 31 c1             	xor    rcx,rax
 377:	48 89 c8             	mov    rax,rcx
 37a:	48 c1 e8 33          	shr    rax,0x33
 37e:	49 89 cf             	mov    r15,rcx
 381:	49 c1 e7 0d          	shl    r15,0xd
 385:	49 09 c7             	or     r15,rax
 388:	48 89 5d e8          	mov    QWORD PTR [rbp-0x18],rbx
 38c:	48 0f b6 43 17       	movzx  rax,BYTE PTR [rbx+0x17]
 391:	48 c1 e0 38          	shl    rax,0x38
 395:	48 09 f8             	or     rax,rdi
 398:	48 0f b6 7b 1f       	movzx  rdi,BYTE PTR [rbx+0x1f]
 39d:	48 c1 e7 38          	shl    rdi,0x38
 3a1:	48 09 d7             	or     rdi,rdx
 3a4:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 3a8:	48 0f b6 7b 27       	movzx  rdi,BYTE PTR [rbx+0x27]
 3ad:	48 c1 e7 38          	shl    rdi,0x38
 3b1:	4c 09 c7             	or     rdi,r8
 3b4:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 3b8:	48 0f b6 7b 2f       	movzx  rdi,BYTE PTR [rbx+0x2f]
 3bd:	48 c1 e7 38          	shl    rdi,0x38
 3c1:	4c 09 f7             	or     rdi,r14
 3c4:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 3c8:	48 0f b6 7b 37       	movzx  rdi,BYTE PTR [rbx+0x37]
 3cd:	48 c1 e7 38          	shl    rdi,0x38
 3d1:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 3d5:	48 09 d7             	or     rdi,rdx
 3d8:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 3dc:	48 0f b6 7b 3f       	movzx  rdi,BYTE PTR [rbx+0x3f]
 3e1:	48 c1 e7 38          	shl    rdi,0x38
 3e5:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
 3e9:	48 09 d7             	or     rdi,rdx
 3ec:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 3f0:	48 0f b6 7b 47       	movzx  rdi,BYTE PTR [rbx+0x47]
 3f5:	48 c1 e7 38          	shl    rdi,0x38
 3f9:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 3fd:	48 09 d7             	or     rdi,rdx
 400:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 404:	49 31 f5             	xor    r13,rsi
 407:	48 01 ce             	add    rsi,rcx
 40a:	4c 89 ef             	mov    rdi,r13
 40d:	48 c1 ef 30          	shr    rdi,0x30
 411:	4d 89 ee             	mov    r14,r13
 414:	49 c1 e6 10          	shl    r14,0x10
 418:	49 09 fe             	or     r14,rdi
 41b:	48 89 f7             	mov    rdi,rsi
 41e:	4c 31 ff             	xor    rdi,r15
 421:	48 89 f9             	mov    rcx,rdi
 424:	48 c1 e9 2f          	shr    rcx,0x2f
 428:	48 89 fa             	mov    rdx,rdi
 42b:	48 c1 e2 11          	shl    rdx,0x11
 42f:	48 09 ca             	or     rdx,rcx
 432:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 436:	4c 89 c1             	mov    rcx,r8
 439:	48 c1 e9 20          	shr    rcx,0x20
 43d:	49 c1 e0 20          	shl    r8,0x20
 441:	49 09 c8             	or     r8,rcx
 444:	4d 01 c5             	add    r13,r8
 447:	4d 31 ee             	xor    r14,r13
 44a:	49 01 fd             	add    r13,rdi
 44d:	4c 31 ea             	xor    rdx,r13
 450:	48 89 d7             	mov    rdi,rdx
 453:	48 c1 ef 33          	shr    rdi,0x33
 457:	48 89 d1             	mov    rcx,rdx
 45a:	48 c1 e1 0d          	shl    rcx,0xd
 45e:	48 09 f9             	or     rcx,rdi
 461:	48 89 f7             	mov    rdi,rsi
 464:	48 c1 ef 20          	shr    rdi,0x20
 468:	48 c1 e6 20          	shl    rsi,0x20
 46c:	48 09 fe             	or     rsi,rdi
 46f:	4d 89 f0             	mov    r8,r14
 472:	49 01 f0             	add    r8,rsi
 475:	4c 89 c6             	mov    rsi,r8
 478:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 47c:	48 31 fe             	xor    rsi,rdi
 47f:	48 01 d6             	add    rsi,rdx
 482:	48 89 f7             	mov    rdi,rsi
 485:	48 31 cf             	xor    rdi,rcx
 488:	48 89 fa             	mov    rdx,rdi
 48b:	48 c1 ea 2f          	shr    rdx,0x2f
 48f:	48 89 f9             	mov    rcx,rdi
 492:	48 c1 e1 11          	shl    rcx,0x11
 496:	48 09 d1             	or     rcx,rdx
 499:	4c 89 ea             	mov    rdx,r13
 49c:	48 c1 ea 20          	shr    rdx,0x20
 4a0:	49 c1 e5 20          	shl    r13,0x20
 4a4:	49 09 d5             	or     r13,rdx
 4a7:	4c 89 f2             	mov    rdx,r14
 4aa:	48 c1 ea 2b          	shr    rdx,0x2b
 4ae:	49 c1 e6 15          	shl    r14,0x15
 4b2:	49 09 d6             	or     r14,rdx
 4b5:	4d 31 c6             	xor    r14,r8
 4b8:	49 31 c6             	xor    r14,rax
 4bb:	4c 89 f2             	mov    rdx,r14
 4be:	4c 01 ea             	add    rdx,r13
 4c1:	4d 89 f0             	mov    r8,r14
 4c4:	49 c1 e8 30          	shr    r8,0x30
 4c8:	49 c1 e6 10          	shl    r14,0x10
 4cc:	4d 09 c6             	or     r14,r8
 4cf:	49 31 d6             	xor    r14,rdx
 4d2:	48 01 fa             	add    rdx,rdi
 4d5:	49 89 d0             	mov    r8,rdx
 4d8:	49 31 c8             	xor    r8,rcx
 4db:	4c 89 c7             	mov    rdi,r8
 4de:	48 c1 ef 33          	shr    rdi,0x33
 4e2:	4c 89 c1             	mov    rcx,r8
 4e5:	48 c1 e1 0d          	shl    rcx,0xd
 4e9:	48 09 f9             	or     rcx,rdi
 4ec:	4c 89 f3             	mov    rbx,r14
 4ef:	48 c1 eb 2b          	shr    rbx,0x2b
 4f3:	4c 89 f7             	mov    rdi,r14
 4f6:	48 c1 e7 15          	shl    rdi,0x15
 4fa:	48 09 df             	or     rdi,rbx
 4fd:	48 89 f3             	mov    rbx,rsi
 500:	48 c1 eb 20          	shr    rbx,0x20
 504:	48 c1 e6 20          	shl    rsi,0x20
 508:	48 09 de             	or     rsi,rbx
 50b:	49 01 f6             	add    r14,rsi
 50e:	4c 31 f7             	xor    rdi,r14
 511:	4d 01 c6             	add    r14,r8
 514:	4c 31 f1             	xor    rcx,r14
 517:	48 89 ce             	mov    rsi,rcx
 51a:	48 c1 ee 2f          	shr    rsi,0x2f
 51e:	49 89 c8             	mov    r8,rcx
 521:	49 c1 e0 11          	shl    r8,0x11
 525:	49 09 f0             	or     r8,rsi
 528:	48 89 fb             	mov    rbx,rdi
 52b:	48 c1 eb 30          	shr    rbx,0x30
 52f:	48 89 fe             	mov    rsi,rdi
 532:	48 c1 e6 10          	shl    rsi,0x10
 536:	48 09 de             	or     rsi,rbx
 539:	48 89 d3             	mov    rbx,rdx
 53c:	48 c1 eb 20          	shr    rbx,0x20
 540:	48 c1 e2 20          	shl    rdx,0x20
 544:	48 09 da             	or     rdx,rbx
 547:	48 01 d7             	add    rdi,rdx
 54a:	48 31 fe             	xor    rsi,rdi
 54d:	48 01 cf             	add    rdi,rcx
 550:	49 31 f8             	xor    r8,rdi
 553:	4c 89 c2             	mov    rdx,r8
 556:	48 c1 ea 33          	shr    rdx,0x33
 55a:	4c 89 c3             	mov    rbx,r8
 55d:	48 c1 e3 0d          	shl    rbx,0xd
 561:	48 09 d3             	or     rbx,rdx
 564:	4c 89 f2             	mov    rdx,r14
 567:	48 c1 ea 20          	shr    rdx,0x20
 56b:	49 c1 e6 20          	shl    r14,0x20
 56f:	49 09 d6             	or     r14,rdx
 572:	48 89 f1             	mov    rcx,rsi
 575:	4c 01 f1             	add    rcx,r14
 578:	48 89 ca             	mov    rdx,rcx
 57b:	48 31 c2             	xor    rdx,rax
 57e:	4c 01 c2             	add    rdx,r8
 581:	49 89 d0             	mov    r8,rdx
 584:	49 31 d8             	xor    r8,rbx
 587:	4c 89 c3             	mov    rbx,r8
 58a:	48 c1 eb 2f          	shr    rbx,0x2f
 58e:	4c 89 c0             	mov    rax,r8
 591:	48 c1 e0 11          	shl    rax,0x11
 595:	48 09 d8             	or     rax,rbx
 598:	48 89 fb             	mov    rbx,rdi
 59b:	48 c1 eb 20          	shr    rbx,0x20
 59f:	48 c1 e7 20          	shl    rdi,0x20
 5a3:	48 09 df             	or     rdi,rbx
 5a6:	48 89 f3             	mov    rbx,rsi
 5a9:	48 c1 eb 2b          	shr    rbx,0x2b
 5ad:	48 c1 e6 15          	shl    rsi,0x15
 5b1:	48 09 de             	or     rsi,rbx
 5b4:	48 31 ce             	xor    rsi,rcx
 5b7:	4c 8b 6d b8          	mov    r13,QWORD PTR [rbp-0x48]
 5bb:	4c 31 ee             	xor    rsi,r13
 5be:	48 89 f1             	mov    rcx,rsi
 5c1:	48 01 f9             	add    rcx,rdi
 5c4:	48 89 f7             	mov    rdi,rsi
 5c7:	48 c1 ef 30          	shr    rdi,0x30
 5cb:	48 c1 e6 10          	shl    rsi,0x10
 5cf:	48 09 fe             	or     rsi,rdi
 5d2:	48 31 ce             	xor    rsi,rcx
 5d5:	4c 01 c1             	add    rcx,r8
 5d8:	48 89 cb             	mov    rbx,rcx
 5db:	48 31 c3             	xor    rbx,rax
 5de:	48 89 df             	mov    rdi,rbx
 5e1:	48 c1 ef 33          	shr    rdi,0x33
 5e5:	49 89 d8             	mov    r8,rbx
 5e8:	49 c1 e0 0d          	shl    r8,0xd
 5ec:	49 09 f8             	or     r8,rdi
 5ef:	48 89 f0             	mov    rax,rsi
 5f2:	48 c1 e8 2b          	shr    rax,0x2b
 5f6:	48 89 f7             	mov    rdi,rsi
 5f9:	48 c1 e7 15          	shl    rdi,0x15
 5fd:	48 09 c7             	or     rdi,rax
 600:	48 89 d0             	mov    rax,rdx
 603:	48 c1 e8 20          	shr    rax,0x20
 607:	48 c1 e2 20          	shl    rdx,0x20
 60b:	48 09 c2             	or     rdx,rax
 60e:	48 01 d6             	add    rsi,rdx
 611:	48 31 f7             	xor    rdi,rsi
 614:	48 01 de             	add    rsi,rbx
 617:	49 31 f0             	xor    r8,rsi
 61a:	4c 89 c2             	mov    rdx,r8
 61d:	48 c1 ea 2f          	shr    rdx,0x2f
 621:	4c 89 c0             	mov    rax,r8
 624:	48 c1 e0 11          	shl    rax,0x11
 628:	48 09 d0             	or     rax,rdx
 62b:	48 89 fb             	mov    rbx,rdi
 62e:	48 c1 eb 30          	shr    rbx,0x30
 632:	48 89 fa             	mov    rdx,rdi
 635:	48 c1 e2 10          	shl    rdx,0x10
 639:	48 09 da             	or     rdx,rbx
 63c:	48 89 cb             	mov    rbx,rcx
 63f:	48 c1 eb 20          	shr    rbx,0x20
 643:	48 c1 e1 20          	shl    rcx,0x20
 647:	48 09 d9             	or     rcx,rbx
 64a:	48 01 cf             	add    rdi,rcx
 64d:	48 31 fa             	xor    rdx,rdi
 650:	4c 01 c7             	add    rdi,r8
 653:	48 31 f8             	xor    rax,rdi
 656:	48 89 c1             	mov    rcx,rax
 659:	48 c1 e9 33          	shr    rcx,0x33
 65d:	48 89 c3             	mov    rbx,rax
 660:	48 c1 e3 0d          	shl    rbx,0xd
 664:	48 09 cb             	or     rbx,rcx
 667:	48 89 f1             	mov    rcx,rsi
 66a:	48 c1 e9 20          	shr    rcx,0x20
 66e:	48 c1 e6 20          	shl    rsi,0x20
 672:	48 09 ce             	or     rsi,rcx
 675:	48 89 d1             	mov    rcx,rdx
 678:	48 01 f1             	add    rcx,rsi
 67b:	48 89 ce             	mov    rsi,rcx
 67e:	4c 31 ee             	xor    rsi,r13
 681:	48 01 c6             	add    rsi,rax
 684:	49 89 f0             	mov    r8,rsi
 687:	49 31 d8             	xor    r8,rbx
 68a:	4c 89 c3             	mov    rbx,r8
 68d:	48 c1 eb 2f          	shr    rbx,0x2f
 691:	4c 89 c0             	mov    rax,r8
 694:	48 c1 e0 11          	shl    rax,0x11
 698:	48 09 d8             	or     rax,rbx
 69b:	48 89 fb             	mov    rbx,rdi
 69e:	48 c1 eb 20          	shr    rbx,0x20
 6a2:	48 c1 e7 20          	shl    rdi,0x20
 6a6:	48 09 df             	or     rdi,rbx
 6a9:	48 89 d3             	mov    rbx,rdx
 6ac:	48 c1 eb 2b          	shr    rbx,0x2b
 6b0:	48 c1 e2 15          	shl    rdx,0x15
 6b4:	48 09 da             	or     rdx,rbx
 6b7:	48 31 ca             	xor    rdx,rcx
 6ba:	4c 8b 6d c0          	mov    r13,QWORD PTR [rbp-0x40]
 6be:	4c 31 ea             	xor    rdx,r13
 6c1:	48 89 d1             	mov    rcx,rdx
 6c4:	48 01 f9             	add    rcx,rdi
 6c7:	48 89 d7             	mov    rdi,rdx
 6ca:	48 c1 ef 30          	shr    rdi,0x30
 6ce:	48 c1 e2 10          	shl    rdx,0x10
 6d2:	48 09 fa             	or     rdx,rdi
 6d5:	48 31 ca             	xor    rdx,rcx
 6d8:	4c 01 c1             	add    rcx,r8
 6db:	48 89 cb             	mov    rbx,rcx
 6de:	48 31 c3             	xor    rbx,rax
 6e1:	48 89 df             	mov    rdi,rbx
 6e4:	48 c1 ef 33          	shr    rdi,0x33
 6e8:	49 89 d8             	mov    r8,rbx
 6eb:	49 c1 e0 0d          	shl    r8,0xd
 6ef:	49 09 f8             	or     r8,rdi
 6f2:	48 89 d0             	mov    rax,rdx
 6f5:	48 c1 e8 2b          	shr    rax,0x2b
 6f9:	48 89 d7             	mov    rdi,rdx
 6fc:	48 c1 e7 15          	shl    rdi,0x15
 700:	48 09 c7             	or     rdi,rax
 703:	48 89 f0             	mov    rax,rsi
 706:	48 c1 e8 20          	shr    rax,0x20
 70a:	48 c1 e6 20          	shl    rsi,0x20
 70e:	48 09 c6             	or     rsi,rax
 711:	48 01 f2             	add    rdx,rsi
 714:	48 31 d7             	xor    rdi,rdx
 717:	48 01 da             	add    rdx,rbx
 71a:	49 31 d0             	xor    r8,rdx
 71d:	4c 89 c6             	mov    rsi,r8
 720:	48 c1 ee 2f          	shr    rsi,0x2f
 724:	4c 89 c0             	mov    rax,r8
 727:	48 c1 e0 11          	shl    rax,0x11
 72b:	48 09 f0             	or     rax,rsi
 72e:	48 89 fb             	mov    rbx,rdi
 731:	48 c1 eb 30          	shr    rbx,0x30
 735:	48 89 fe             	mov    rsi,rdi
 738:	48 c1 e6 10          	shl    rsi,0x10
 73c:	48 09 de             	or     rsi,rbx
 73f:	48 89 cb             	mov    rbx,rcx
 742:	48 c1 eb 20          	shr    rbx,0x20
 746:	48 c1 e1 20          	shl    rcx,0x20
 74a:	48 09 d9             	or     rcx,rbx
 74d:	48 01 cf             	add    rdi,rcx
 750:	48 31 fe             	xor    rsi,rdi
 753:	4c 01 c7             	add    rdi,r8
 756:	48 31 f8             	xor    rax,rdi
 759:	48 89 c1             	mov    rcx,rax
 75c:	48 c1 e9 33          	shr    rcx,0x33
 760:	48 89 c3             	mov    rbx,rax
 763:	48 c1 e3 0d          	shl    rbx,0xd
 767:	48 09 cb             	or     rbx,rcx
 76a:	48 89 d1             	mov    rcx,rdx
 76d:	48 c1 e9 20          	shr    rcx,0x20
 771:	48 c1 e2 20          	shl    rdx,0x20
 775:	48 09 ca             	or     rdx,rcx
 778:	48 89 f1             	mov    rcx,rsi
 77b:	48 01 d1             	add    rcx,rdx
 77e:	48 89 ca             	mov    rdx,rcx
 781:	4c 31 ea             	xor    rdx,r13
 784:	48 01 c2             	add    rdx,rax
 787:	49 89 d0             	mov    r8,rdx
 78a:	49 31 d8             	xor    r8,rbx
 78d:	4c 89 c3             	mov    rbx,r8
 790:	48 c1 eb 2f          	shr    rbx,0x2f
 794:	4c 89 c0             	mov    rax,r8
 797:	48 c1 e0 11          	shl    rax,0x11
 79b:	48 09 d8             	or     rax,rbx
 79e:	48 89 fb             	mov    rbx,rdi
 7a1:	48 c1 eb 20          	shr    rbx,0x20
 7a5:	48 c1 e7 20          	shl    rdi,0x20
 7a9:	48 09 df             	or     rdi,rbx
 7ac:	48 89 f3             	mov    rbx,rsi
 7af:	48 c1 eb 2b          	shr    rbx,0x2b
 7b3:	48 c1 e6 15          	shl    rsi,0x15
 7b7:	48 09 de             	or     rsi,rbx
 7ba:	48 31 ce             	xor    rsi,rcx
 7bd:	4c 8b 6d c8          	mov    r13,QWORD PTR [rbp-0x38]
 7c1:	4c 31 ee             	xor    rsi,r13
 7c4:	48 89 f1             	mov    rcx,rsi
 7c7:	48 01 f9             	add    rcx,rdi
 7ca:	48 89 f7             	mov    rdi,rsi
 7cd:	48 c1 ef 30          	shr    rdi,0x30
 7d1:	48 c1 e6 10          	shl    rsi,0x10
 7d5:	48 09 fe             	or     rsi,rdi
 7d8:	48 31 ce             	xor    rsi,rcx
 7db:	4c 01 c1             	add    rcx,r8
 7de:	48 89 cb             	mov    rbx,rcx
 7e1:	48 31 c3             	xor    rbx,rax
 7e4:	48 89 df             	mov    rdi,rbx
 7e7:	48 c1 ef 33          	shr    rdi,0x33
 7eb:	49 89 d8             	mov    r8,rbx
 7ee:	49 c1 e0 0d          	shl    r8,0xd
 7f2:	49 09 f8             	or     r8,rdi
 7f5:	48 89 f0             	mov    rax,rsi
 7f8:	48 c1 e8 2b          	shr    rax,0x2b
 7fc:	48 89 f7             	mov    rdi,rsi
 7ff:	48 c1 e7 15          	shl    rdi,0x15
 803:	48 09 c7             	or     rdi,rax
 806:	48 89 d0             	mov    rax,rdx
 809:	48 c1 e8 20          	shr    rax,0x20
 80d:	48 c1 e2 20          	shl    rdx,0x20
 811:	48 09 c2             	or     rdx,rax
 814:	48 01 d6             	add    rsi,rdx
 817:	48 31 f7             	xor    rdi,rsi
 81a:	48 01 de             	add    rsi,rbx
 81d:	49 31 f0             	xor    r8,rsi
 820:	4c 89 c2             	mov    rdx,r8
 823:	48 c1 ea 2f          	shr    rdx,0x2f
 827:	4c 89 c0             	mov    rax,r8
 82a:	48 c1 e0 11          	shl    rax,0x11
 82e:	48 09 d0             	or     rax,rdx
 831:	48 89 fb             	mov    rbx,rdi
 834:	48 c1 eb 30          	shr    rbx,0x30
 838:	48 89 fa             	mov    rdx,rdi
 83b:	48 c1 e2 10          	shl    rdx,0x10
 83f:	48 09 da             	or     rdx,rbx
 842:	48 89 cb             	mov    rbx,rcx
 845:	48 c1 eb 20          	shr    rbx,0x20
 849:	48 c1 e1 20          	shl    rcx,0x20
 84d:	48 09 d9             	or     rcx,rbx
 850:	48 01 cf             	add    rdi,rcx
 853:	48 31 fa             	xor    rdx,rdi
 856:	4c 01 c7             	add    rdi,r8
 859:	48 31 f8             	xor    rax,rdi
 85c:	48 89 c1             	mov    rcx,rax
 85f:	48 c1 e9 33          	shr    rcx,0x33
 863:	48 89 c3             	mov    rbx,rax
 866:	48 c1 e3 0d          	shl    rbx,0xd
 86a:	48 09 cb             	or     rbx,rcx
 86d:	48 89 f1             	mov    rcx,rsi
 870:	48 c1 e9 20          	shr    rcx,0x20
 874:	48 c1 e6 20          	shl    rsi,0x20
 878:	48 09 ce             	or     rsi,rcx
 87b:	48 89 d1             	mov    rcx,rdx
 87e:	48 01 f1             	add    rcx,rsi
 881:	48 89 ce             	mov    rsi,rcx
 884:	4c 31 ee             	xor    rsi,r13
 887:	48 01 c6             	add    rsi,rax
 88a:	49 89 f0             	mov    r8,rsi
 88d:	49 31 d8             	xor    r8,rbx
 890:	4c 89 c3             	mov    rbx,r8
 893:	48 c1 eb 2f          	shr    rbx,0x2f
 897:	4c 89 c0             	mov    rax,r8
 89a:	48 c1 e0 11          	shl    rax,0x11
 89e:	48 09 d8             	or     rax,rbx
 8a1:	48 89 fb             	mov    rbx,rdi
 8a4:	48 c1 eb 20          	shr    rbx,0x20
 8a8:	48 c1 e7 20          	shl    rdi,0x20
 8ac:	48 09 df             	or     rdi,rbx
 8af:	48 89 d3             	mov    rbx,rdx
 8b2:	48 c1 eb 2b          	shr    rbx,0x2b
 8b6:	48 c1 e2 15          	shl    rdx,0x15
 8ba:	48 09 da             	or     rdx,rbx
 8bd:	48 31 ca             	xor    rdx,rcx
 8c0:	4c 8b 75 d0          	mov    r14,QWORD PTR [rbp-0x30]
 8c4:	4c 31 f2             	xor    rdx,r14
 8c7:	48 89 d1             	mov    rcx,rdx
 8ca:	48 01 f9             	add    rcx,rdi
 8cd:	48 89 d7             	mov    rdi,rdx
 8d0:	48 c1 ef 30          	shr    rdi,0x30
 8d4:	48 c1 e2 10          	shl    rdx,0x10
 8d8:	48 09 fa             	or     rdx,rdi
 8db:	48 31 ca             	xor    rdx,rcx
 8de:	4c 01 c1             	add    rcx,r8
 8e1:	49 89 c8             	mov    r8,rcx
 8e4:	49 31 c0             	xor    r8,rax
 8e7:	4c 89 c7             	mov    rdi,r8
 8ea:	48 c1 ef 33          	shr    rdi,0x33
 8ee:	4c 89 c0             	mov    rax,r8
 8f1:	48 c1 e0 0d          	shl    rax,0xd
 8f5:	48 09 f8             	or     rax,rdi
 8f8:	48 89 d3             	mov    rbx,rdx
 8fb:	48 c1 eb 2b          	shr    rbx,0x2b
 8ff:	48 89 d7             	mov    rdi,rdx
 902:	48 c1 e7 15          	shl    rdi,0x15
 906:	48 09 df             	or     rdi,rbx
 909:	48 89 f3             	mov    rbx,rsi
 90c:	48 c1 eb 20          	shr    rbx,0x20
 910:	48 c1 e6 20          	shl    rsi,0x20
 914:	48 09 de             	or     rsi,rbx
 917:	48 01 f2             	add    rdx,rsi
 91a:	48 31 d7             	xor    rdi,rdx
 91d:	4c 01 c2             	add    rdx,r8
 920:	48 31 d0             	xor    rax,rdx
 923:	48 89 c6             	mov    rsi,rax
 926:	48 c1 ee 2f          	shr    rsi,0x2f
 92a:	48 89 c3             	mov    rbx,rax
 92d:	48 c1 e3 11          	shl    rbx,0x11
 931:	48 09 f3             	or     rbx,rsi
 934:	48 89 fe             	mov    rsi,rdi
 937:	48 c1 ee 30          	shr    rsi,0x30
 93b:	49 89 f8             	mov    r8,rdi
 93e:	49 c1 e0 10          	shl    r8,0x10
 942:	49 09 f0             	or     r8,rsi
 945:	48 89 ce             	mov    rsi,rcx
 948:	48 c1 ee 20          	shr    rsi,0x20
 94c:	48 c1 e1 20          	shl    rcx,0x20
 950:	48 09 f1             	or     rcx,rsi
 953:	48 01 cf             	add    rdi,rcx
 956:	49 31 f8             	xor    r8,rdi
 959:	48 01 c7             	add    rdi,rax
 95c:	48 31 fb             	xor    rbx,rdi
 95f:	48 89 de             	mov    rsi,rbx
 962:	48 c1 ee 33          	shr    rsi,0x33
 966:	48 89 d8             	mov    rax,rbx
 969:	48 c1 e0 0d          	shl    rax,0xd
 96d:	48 09 f0             	or     rax,rsi
 970:	48 89 d6             	mov    rsi,rdx
 973:	48 c1 ee 20          	shr    rsi,0x20
 977:	48 c1 e2 20          	shl    rdx,0x20
 97b:	48 09 f2             	or     rdx,rsi
 97e:	4d 89 c5             	mov    r13,r8
 981:	49 01 d5             	add    r13,rdx
 984:	4c 89 ee             	mov    rsi,r13
 987:	4c 31 f6             	xor    rsi,r14
 98a:	48 01 de             	add    rsi,rbx
 98d:	48 89 f1             	mov    rcx,rsi
 990:	48 31 c1             	xor    rcx,rax
 993:	48 89 ca             	mov    rdx,rcx
 996:	48 c1 ea 2f          	shr    rdx,0x2f
 99a:	48 89 c8             	mov    rax,rcx
 99d:	48 c1 e0 11          	shl    rax,0x11
 9a1:	48 09 d0             	or     rax,rdx
 9a4:	48 89 fa             	mov    rdx,rdi
 9a7:	48 c1 ea 20          	shr    rdx,0x20
 9ab:	48 c1 e7 20          	shl    rdi,0x20
 9af:	48 09 d7             	or     rdi,rdx
 9b2:	4c 89 c2             	mov    rdx,r8
 9b5:	48 c1 ea 2b          	shr    rdx,0x2b
 9b9:	49 c1 e0 15          	shl    r8,0x15
 9bd:	49 09 d0             	or     r8,rdx
 9c0:	4d 31 e8             	xor    r8,r13
 9c3:	4c 8b 6d d8          	mov    r13,QWORD PTR [rbp-0x28]
 9c7:	4d 31 e8             	xor    r8,r13
 9ca:	4c 89 c2             	mov    rdx,r8
 9cd:	48 01 fa             	add    rdx,rdi
 9d0:	4c 89 c7             	mov    rdi,r8
 9d3:	48 c1 ef 30          	shr    rdi,0x30
 9d7:	49 c1 e0 10          	shl    r8,0x10
 9db:	49 09 f8             	or     r8,rdi
 9de:	49 31 d0             	xor    r8,rdx
 9e1:	48 01 ca             	add    rdx,rcx
 9e4:	48 89 d3             	mov    rbx,rdx
 9e7:	48 31 c3             	xor    rbx,rax
 9ea:	48 89 df             	mov    rdi,rbx
 9ed:	48 c1 ef 33          	shr    rdi,0x33
 9f1:	48 89 d9             	mov    rcx,rbx
 9f4:	48 c1 e1 0d          	shl    rcx,0xd
 9f8:	48 09 f9             	or     rcx,rdi
 9fb:	4c 89 c0             	mov    rax,r8
 9fe:	48 c1 e8 2b          	shr    rax,0x2b
 a02:	4c 89 c7             	mov    rdi,r8
 a05:	48 c1 e7 15          	shl    rdi,0x15
 a09:	48 09 c7             	or     rdi,rax
 a0c:	48 89 f0             	mov    rax,rsi
 a0f:	48 c1 e8 20          	shr    rax,0x20
 a13:	48 c1 e6 20          	shl    rsi,0x20
 a17:	48 09 c6             	or     rsi,rax
 a1a:	49 01 f0             	add    r8,rsi
 a1d:	4c 31 c7             	xor    rdi,r8
 a20:	49 01 d8             	add    r8,rbx
 a23:	4c 31 c1             	xor    rcx,r8
 a26:	48 89 ce             	mov    rsi,rcx
 a29:	48 c1 ee 2f          	shr    rsi,0x2f
 a2d:	48 89 c8             	mov    rax,rcx
 a30:	48 c1 e0 11          	shl    rax,0x11
 a34:	48 09 f0             	or     rax,rsi
 a37:	48 89 fb             	mov    rbx,rdi
 a3a:	48 c1 eb 30          	shr    rbx,0x30
 a3e:	48 89 fe             	mov    rsi,rdi
 a41:	48 c1 e6 10          	shl    rsi,0x10
 a45:	48 09 de             	or     rsi,rbx
 a48:	48 89 d3             	mov    rbx,rdx
 a4b:	48 c1 eb 20          	shr    rbx,0x20
 a4f:	48 c1 e2 20          	shl    rdx,0x20
 a53:	48 09 da             	or     rdx,rbx
 a56:	48 01 d7             	add    rdi,rdx
 a59:	48 31 fe             	xor    rsi,rdi
 a5c:	48 01 cf             	add    rdi,rcx
 a5f:	48 31 f8             	xor    rax,rdi
 a62:	48 89 c2             	mov    rdx,rax
 a65:	48 c1 ea 33          	shr    rdx,0x33
 a69:	48 89 c3             	mov    rbx,rax
 a6c:	48 c1 e3 0d          	shl    rbx,0xd
 a70:	48 09 d3             	or     rbx,rdx
 a73:	4c 89 c2             	mov    rdx,r8
 a76:	48 c1 ea 20          	shr    rdx,0x20
 a7a:	49 c1 e0 20          	shl    r8,0x20
 a7e:	49 09 d0             	or     r8,rdx
 a81:	48 89 f1             	mov    rcx,rsi
 a84:	4c 01 c1             	add    rcx,r8
 a87:	48 89 ca             	mov    rdx,rcx
 a8a:	4c 31 ea             	xor    rdx,r13
 a8d:	48 01 c2             	add    rdx,rax
 a90:	49 89 d0             	mov    r8,rdx
 a93:	49 31 d8             	xor    r8,rbx
 a96:	4c 89 c3             	mov    rbx,r8
 a99:	48 c1 eb 2f          	shr    rbx,0x2f
 a9d:	4c 89 c0             	mov    rax,r8
 aa0:	48 c1 e0 11          	shl    rax,0x11
 aa4:	48 09 d8             	or     rax,rbx
 aa7:	48 89 fb             	mov    rbx,rdi
 aaa:	48 c1 eb 20          	shr    rbx,0x20
 aae:	48 c1 e7 20          	shl    rdi,0x20
 ab2:	48 09 df             	or     rdi,rbx
 ab5:	48 89 f3             	mov    rbx,rsi
 ab8:	48 c1 eb 2b          	shr    rbx,0x2b
 abc:	48 c1 e6 15          	shl    rsi,0x15
 ac0:	48 09 de             	or     rsi,rbx
 ac3:	48 31 ce             	xor    rsi,rcx
 ac6:	4c 8b 6d e0          	mov    r13,QWORD PTR [rbp-0x20]
 aca:	4c 31 ee             	xor    rsi,r13
 acd:	48 89 f1             	mov    rcx,rsi
 ad0:	48 01 f9             	add    rcx,rdi
 ad3:	48 89 f7             	mov    rdi,rsi
 ad6:	48 c1 ef 30          	shr    rdi,0x30
 ada:	48 c1 e6 10          	shl    rsi,0x10
 ade:	48 09 fe             	or     rsi,rdi
 ae1:	48 31 ce             	xor    rsi,rcx
 ae4:	4c 01 c1             	add    rcx,r8
 ae7:	48 89 cf             	mov    rdi,rcx
 aea:	48 31 c7             	xor    rdi,rax
 aed:	49 89 f8             	mov    r8,rdi
 af0:	49 c1 e8 33          	shr    r8,0x33
 af4:	48 89 fb             	mov    rbx,rdi
 af7:	48 c1 e3 0d          	shl    rbx,0xd
 afb:	4c 09 c3             	or     rbx,r8
 afe:	48 89 f0             	mov    rax,rsi
 b01:	48 c1 e8 2b          	shr    rax,0x2b
 b05:	49 89 f0             	mov    r8,rsi
 b08:	49 c1 e0 15          	shl    r8,0x15
 b0c:	49 09 c0             	or     r8,rax
 b0f:	48 89 d0             	mov    rax,rdx
 b12:	48 c1 e8 20          	shr    rax,0x20
 b16:	48 c1 e2 20          	shl    rdx,0x20
 b1a:	48 09 c2             	or     rdx,rax
 b1d:	48 01 d6             	add    rsi,rdx
 b20:	49 31 f0             	xor    r8,rsi
 b23:	48 01 fe             	add    rsi,rdi
 b26:	48 31 f3             	xor    rbx,rsi
 b29:	48 89 da             	mov    rdx,rbx
 b2c:	48 c1 ea 2f          	shr    rdx,0x2f
 b30:	48 89 df             	mov    rdi,rbx
 b33:	48 c1 e7 11          	shl    rdi,0x11
 b37:	48 09 d7             	or     rdi,rdx
 b3a:	4c 89 c2             	mov    rdx,r8
 b3d:	48 c1 ea 30          	shr    rdx,0x30
 b41:	4c 89 c0             	mov    rax,r8
 b44:	48 c1 e0 10          	shl    rax,0x10
 b48:	48 09 d0             	or     rax,rdx
 b4b:	48 89 ca             	mov    rdx,rcx
 b4e:	48 c1 ea 20          	shr    rdx,0x20
 b52:	48 c1 e1 20          	shl    rcx,0x20
 b56:	48 09 d1             	or     rcx,rdx
 b59:	49 01 c8             	add    r8,rcx
 b5c:	4c 31 c0             	xor    rax,r8
 b5f:	49 01 d8             	add    r8,rbx
 b62:	4c 31 c7             	xor    rdi,r8
 b65:	48 89 fa             	mov    rdx,rdi
 b68:	48 c1 ea 33          	shr    rdx,0x33
 b6c:	48 89 f9             	mov    rcx,rdi
 b6f:	48 c1 e1 0d          	shl    rcx,0xd
 b73:	48 09 d1             	or     rcx,rdx
 b76:	48 89 f2             	mov    rdx,rsi
 b79:	48 c1 ea 20          	shr    rdx,0x20
 b7d:	48 c1 e6 20          	shl    rsi,0x20
 b81:	48 09 d6             	or     rsi,rdx
 b84:	48 89 c3             	mov    rbx,rax
 b87:	48 c1 eb 2b          	shr    rbx,0x2b
 b8b:	48 89 c2             	mov    rdx,rax
 b8e:	48 c1 e2 15          	shl    rdx,0x15
 b92:	48 09 da             	or     rdx,rbx
 b95:	48 01 f0             	add    rax,rsi
 b98:	48 31 c2             	xor    rdx,rax
 b9b:	4c 31 e8             	xor    rax,r13
 b9e:	48 01 f8             	add    rax,rdi
 ba1:	48 89 c7             	mov    rdi,rax
 ba4:	48 31 cf             	xor    rdi,rcx
 ba7:	48 89 f9             	mov    rcx,rdi
 baa:	48 c1 e9 2f          	shr    rcx,0x2f
 bae:	48 89 fe             	mov    rsi,rdi
 bb1:	48 c1 e6 11          	shl    rsi,0x11
 bb5:	48 09 ce             	or     rsi,rcx
 bb8:	4c 89 c1             	mov    rcx,r8
 bbb:	48 c1 e9 20          	shr    rcx,0x20
 bbf:	49 c1 e0 20          	shl    r8,0x20
 bc3:	49 09 c8             	or     r8,rcx
 bc6:	49 81 f0 ff 00 00 00 	xor    r8,0xff
 bcd:	49 01 d0             	add    r8,rdx
 bd0:	4c 01 c7             	add    rdi,r8
 bd3:	48 31 fe             	xor    rsi,rdi
 bd6:	48 89 f3             	mov    rbx,rsi
 bd9:	48 c1 eb 33          	shr    rbx,0x33
 bdd:	48 89 f1             	mov    rcx,rsi
 be0:	48 c1 e1 0d          	shl    rcx,0xd
 be4:	48 09 d9             	or     rcx,rbx
 be7:	48 89 d3             	mov    rbx,rdx
 bea:	48 c1 eb 30          	shr    rbx,0x30
 bee:	48 c1 e2 10          	shl    rdx,0x10
 bf2:	48 09 da             	or     rdx,rbx
 bf5:	4c 31 c2             	xor    rdx,r8
 bf8:	49 89 c0             	mov    r8,rax
 bfb:	49 c1 e8 20          	shr    r8,0x20
 bff:	48 c1 e0 20          	shl    rax,0x20
 c03:	4c 09 c0             	or     rax,r8
 c06:	48 01 d0             	add    rax,rdx
 c09:	48 01 c6             	add    rsi,rax
 c0c:	48 31 f1             	xor    rcx,rsi
 c0f:	48 89 cb             	mov    rbx,rcx
 c12:	48 c1 eb 2f          	shr    rbx,0x2f
 c16:	49 89 c8             	mov    r8,rcx
 c19:	49 c1 e0 11          	shl    r8,0x11
 c1d:	49 09 d8             	or     r8,rbx
 c20:	48 89 fb             	mov    rbx,rdi
 c23:	48 c1 eb 20          	shr    rbx,0x20
 c27:	48 c1 e7 20          	shl    rdi,0x20
 c2b:	48 09 df             	or     rdi,rbx
 c2e:	48 89 d3             	mov    rbx,rdx
 c31:	48 c1 eb 2b          	shr    rbx,0x2b
 c35:	48 c1 e2 15          	shl    rdx,0x15
 c39:	48 09 da             	or     rdx,rbx
 c3c:	48 31 c2             	xor    rdx,rax
 c3f:	48 01 d7             	add    rdi,rdx
 c42:	48 01 f9             	add    rcx,rdi
 c45:	49 31 c8             	xor    r8,rcx
 c48:	4c 89 c3             	mov    rbx,r8
 c4b:	48 c1 eb 33          	shr    rbx,0x33
 c4f:	4c 89 c0             	mov    rax,r8
 c52:	48 c1 e0 0d          	shl    rax,0xd
 c56:	48 09 d8             	or     rax,rbx
 c59:	48 89 d3             	mov    rbx,rdx
 c5c:	48 c1 eb 30          	shr    rbx,0x30
 c60:	48 c1 e2 10          	shl    rdx,0x10
 c64:	48 09 da             	or     rdx,rbx
 c67:	48 31 fa             	xor    rdx,rdi
 c6a:	48 89 f7             	mov    rdi,rsi
 c6d:	48 c1 ef 20          	shr    rdi,0x20
 c71:	48 c1 e6 20          	shl    rsi,0x20
 c75:	48 09 fe             	or     rsi,rdi
 c78:	48 01 d6             	add    rsi,rdx
 c7b:	49 01 f0             	add    r8,rsi
 c7e:	4c 31 c0             	xor    rax,r8
 c81:	48 89 c7             	mov    rdi,rax
 c84:	48 c1 ef 2f          	shr    rdi,0x2f
 c88:	48 89 c3             	mov    rbx,rax
 c8b:	48 c1 e3 11          	shl    rbx,0x11
 c8f:	48 09 fb             	or     rbx,rdi
 c92:	48 89 cf             	mov    rdi,rcx
 c95:	48 c1 ef 20          	shr    rdi,0x20
 c99:	48 c1 e1 20          	shl    rcx,0x20
 c9d:	48 09 f9             	or     rcx,rdi
 ca0:	48 89 d7             	mov    rdi,rdx
 ca3:	48 c1 ef 2b          	shr    rdi,0x2b
 ca7:	48 c1 e2 15          	shl    rdx,0x15
 cab:	48 09 fa             	or     rdx,rdi
 cae:	48 31 f2             	xor    rdx,rsi
 cb1:	48 01 d1             	add    rcx,rdx
 cb4:	48 01 c8             	add    rax,rcx
 cb7:	48 31 c3             	xor    rbx,rax
 cba:	48 89 de             	mov    rsi,rbx
 cbd:	48 c1 ee 33          	shr    rsi,0x33
 cc1:	48 89 df             	mov    rdi,rbx
 cc4:	48 c1 e7 0d          	shl    rdi,0xd
 cc8:	48 09 f7             	or     rdi,rsi
 ccb:	48 89 d6             	mov    rsi,rdx
 cce:	48 c1 ee 30          	shr    rsi,0x30
 cd2:	48 c1 e2 10          	shl    rdx,0x10
 cd6:	48 09 f2             	or     rdx,rsi
 cd9:	48 31 ca             	xor    rdx,rcx
 cdc:	4c 89 c6             	mov    rsi,r8
 cdf:	48 c1 ee 20          	shr    rsi,0x20
 ce3:	49 c1 e0 20          	shl    r8,0x20
 ce7:	49 09 f0             	or     r8,rsi
 cea:	49 01 d0             	add    r8,rdx
 ced:	4c 01 c3             	add    rbx,r8
 cf0:	48 31 df             	xor    rdi,rbx
 cf3:	48 89 c6             	mov    rsi,rax
 cf6:	48 c1 ee 20          	shr    rsi,0x20
 cfa:	48 c1 e0 20          	shl    rax,0x20
 cfe:	48 09 f0             	or     rax,rsi
 d01:	48 89 d6             	mov    rsi,rdx
 d04:	48 c1 ee 2b          	shr    rsi,0x2b
 d08:	48 c1 e2 15          	shl    rdx,0x15
 d0c:	48 09 f2             	or     rdx,rsi
 d0f:	4c 31 c2             	xor    rdx,r8
 d12:	48 01 d0             	add    rax,rdx
 d15:	48 89 d6             	mov    rsi,rdx
 d18:	48 c1 ee 30          	shr    rsi,0x30
 d1c:	48 c1 e2 10          	shl    rdx,0x10
 d20:	48 09 f2             	or     rdx,rsi
 d23:	48 31 c2             	xor    rdx,rax
 d26:	48 89 fe             	mov    rsi,rdi
 d29:	48 01 c6             	add    rsi,rax
 d2c:	48 89 f1             	mov    rcx,rsi
 d2f:	48 c1 e9 20          	shr    rcx,0x20
 d33:	49 89 f0             	mov    r8,rsi
 d36:	49 c1 e0 20          	shl    r8,0x20
 d3a:	49 09 c8             	or     r8,rcx
 d3d:	48 89 d1             	mov    rcx,rdx
 d40:	48 c1 e9 2b          	shr    rcx,0x2b
 d44:	48 c1 e2 15          	shl    rdx,0x15
 d48:	48 09 ca             	or     rdx,rcx
 d4b:	48 89 f9             	mov    rcx,rdi
 d4e:	48 c1 e9 2f          	shr    rcx,0x2f
 d52:	48 c1 e7 11          	shl    rdi,0x11
 d56:	48 09 cf             	or     rdi,rcx
 d59:	48 31 fa             	xor    rdx,rdi
 d5c:	4c 31 c2             	xor    rdx,r8
 d5f:	48 31 f2             	xor    rdx,rsi
 d62:	48 89 d7             	mov    rdi,rdx
 d65:	48 c1 ef 38          	shr    rdi,0x38
 d69:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 d6d:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 d71:	48 89 d7             	mov    rdi,rdx
 d74:	48 c1 ef 30          	shr    rdi,0x30
 d78:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 d7c:	48 89 d7             	mov    rdi,rdx
 d7f:	48 c1 ef 28          	shr    rdi,0x28
 d83:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 d87:	48 89 d7             	mov    rdi,rdx
 d8a:	48 c1 ef 20          	shr    rdi,0x20
 d8e:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 d92:	48 89 d7             	mov    rdi,rdx
 d95:	48 c1 ef 18          	shr    rdi,0x18
 d99:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 d9d:	48 89 d7             	mov    rdi,rdx
 da0:	48 c1 ef 10          	shr    rdi,0x10
 da4:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 da8:	88 56 00             	mov    BYTE PTR [rsi+0x0],dl
 dab:	48 c1 ea 08          	shr    rdx,0x8
 daf:	88 56 01             	mov    BYTE PTR [rsi+0x1],dl
 db2:	b8 02 00 00 00       	mov    eax,0x2
 db7:	41 5f                	pop    r15
 db9:	41 5e                	pop    r14
 dbb:	41 5d                	pop    r13
 dbd:	5b                   	pop    rbx
 dbe:	c9                   	leave
 dbf:	c3                   	ret
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
   d:	0f 87 50 05 00 00    	ja     0x563
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 43 05 00 00    	ja     0x563
  20:	48 8d 71 48          	lea    rsi,[rcx+0x48]
  24:	48 39 d6             	cmp    rsi,rdx
  27:	0f 87 36 05 00 00    	ja     0x563
  2d:	55                   	push   rbp
  2e:	41 57                	push   r15
  30:	41 56                	push   r14
  32:	41 55                	push   r13
  34:	41 54                	push   r12
  36:	53                   	push   rbx
  37:	4c 8b 59 08          	mov    r11,QWORD PTR [rcx+0x8]
  3b:	4c 8b 51 10          	mov    r10,QWORD PTR [rcx+0x10]
  3f:	48 b8 73 65 74 79 62 	movabs rax,0x7465646279746573
  46:	64 65 74 
  49:	4c 31 d8             	xor    rax,r11
  4c:	c4 e3 fb f0 d0 30    	rorx   rdx,rax,0x30
  52:	48 be 61 72 65 6e 65 	movabs rsi,0x6c7967656e657261
  59:	67 79 6c 
  5c:	48 01 c6             	add    rsi,rax
  5f:	48 31 d6             	xor    rsi,rdx
  62:	48 bb d0 ea 9f c1 6f 	movabs rbx,0xa60c596fc19fead0
  69:	59 0c a6 
  6c:	48 01 c3             	add    rbx,rax
  6f:	49 be c6 df de d7 e2 	movabs r14,0xded7d4e2d7dedfc6
  76:	d4 d7 de 
  79:	49 01 f6             	add    r14,rsi
  7c:	c4 63 fb f0 fe 2b    	rorx   r15,rsi,0x2b
  82:	49 bc 25 73 de f0 74 	movabs r12,0xe414a674f0de7325
  89:	a6 14 e4 
  8c:	49 31 dc             	xor    r12,rbx
  8f:	c4 43 fb f0 ec 33    	rorx   r13,r12,0x33
  95:	4c 8b 49 18          	mov    r9,QWORD PTR [rcx+0x18]
  99:	4c 8b 41 20          	mov    r8,QWORD PTR [rcx+0x20]
  9d:	48 8b 79 28          	mov    rdi,QWORD PTR [rcx+0x28]
  a1:	48 8b 71 30          	mov    rsi,QWORD PTR [rcx+0x30]
  a5:	48 8b 51 38          	mov    rdx,QWORD PTR [rcx+0x38]
  a9:	48 8b 41 40          	mov    rax,QWORD PTR [rcx+0x40]
  ad:	4d 31 f7             	xor    r15,r14
  b0:	4d 01 f4             	add    r12,r14
  b3:	c4 43 fb f0 f7 30    	rorx   r14,r15,0x30
  b9:	4d 31 e5             	xor    r13,r12
  bc:	c4 c3 fb f0 ed 2f    	rorx   rbp,r13,0x2f
  c2:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
  c8:	4c 01 fb             	add    rbx,r15
  cb:	49 31 de             	xor    r14,rbx
  ce:	4c 01 eb             	add    rbx,r13
  d1:	48 31 dd             	xor    rbp,rbx
  d4:	c4 63 fb f0 fd 33    	rorx   r15,rbp,0x33
  da:	c4 43 fb f0 e4 20    	rorx   r12,r12,0x20
  e0:	4d 01 f4             	add    r12,r14
  e3:	4d 31 e3             	xor    r11,r12
  e6:	49 01 eb             	add    r11,rbp
  e9:	4d 31 df             	xor    r15,r11
  ec:	c4 43 fb f0 ef 2f    	rorx   r13,r15,0x2f
  f2:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
  f8:	c4 43 fb f0 f6 2b    	rorx   r14,r14,0x2b
  fe:	4d 31 e6             	xor    r14,r12
 101:	4d 31 d6             	xor    r14,r10
 104:	4c 01 f3             	add    rbx,r14
 107:	c4 43 fb f0 f6 30    	rorx   r14,r14,0x30
 10d:	49 31 de             	xor    r14,rbx
 110:	4c 01 fb             	add    rbx,r15
 113:	49 31 dd             	xor    r13,rbx
 116:	c4 43 fb f0 fd 33    	rorx   r15,r13,0x33
 11c:	c4 43 fb f0 e6 2b    	rorx   r12,r14,0x2b
 122:	c4 43 fb f0 db 20    	rorx   r11,r11,0x20
 128:	4d 01 f3             	add    r11,r14
 12b:	4d 31 dc             	xor    r12,r11
 12e:	4d 01 eb             	add    r11,r13
 131:	4d 31 df             	xor    r15,r11
 134:	c4 43 fb f0 f7 2f    	rorx   r14,r15,0x2f
 13a:	c4 43 fb f0 ec 30    	rorx   r13,r12,0x30
 140:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 146:	4c 01 e3             	add    rbx,r12
 149:	49 31 dd             	xor    r13,rbx
 14c:	4c 01 fb             	add    rbx,r15
 14f:	49 31 de             	xor    r14,rbx
 152:	c4 43 fb f0 fe 33    	rorx   r15,r14,0x33
 158:	c4 43 fb f0 db 20    	rorx   r11,r11,0x20
 15e:	4d 01 eb             	add    r11,r13
 161:	4d 31 da             	xor    r10,r11
 164:	4d 01 f2             	add    r10,r14
 167:	4d 31 d7             	xor    r15,r10
 16a:	c4 43 fb f0 f7 2f    	rorx   r14,r15,0x2f
 170:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 176:	c4 43 fb f0 e5 2b    	rorx   r12,r13,0x2b
 17c:	4d 31 cc             	xor    r12,r9
 17f:	4d 31 dc             	xor    r12,r11
 182:	4c 01 e3             	add    rbx,r12
 185:	c4 43 fb f0 dc 30    	rorx   r11,r12,0x30
 18b:	49 31 db             	xor    r11,rbx
 18e:	4c 01 fb             	add    rbx,r15
 191:	49 31 de             	xor    r14,rbx
 194:	c4 43 fb f0 fe 33    	rorx   r15,r14,0x33
 19a:	c4 43 fb f0 e3 2b    	rorx   r12,r11,0x2b
 1a0:	c4 43 fb f0 d2 20    	rorx   r10,r10,0x20
 1a6:	4d 01 da             	add    r10,r11
 1a9:	4d 31 d4             	xor    r12,r10
 1ac:	4d 01 f2             	add    r10,r14
 1af:	4d 31 d7             	xor    r15,r10
 1b2:	c4 43 fb f0 df 2f    	rorx   r11,r15,0x2f
 1b8:	c4 43 fb f0 f4 30    	rorx   r14,r12,0x30
 1be:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 1c4:	4c 01 e3             	add    rbx,r12
 1c7:	49 31 de             	xor    r14,rbx
 1ca:	4c 01 fb             	add    rbx,r15
 1cd:	49 31 db             	xor    r11,rbx
 1d0:	c4 43 fb f0 fb 33    	rorx   r15,r11,0x33
 1d6:	c4 43 fb f0 d2 20    	rorx   r10,r10,0x20
 1dc:	4d 01 f2             	add    r10,r14
 1df:	4d 31 d1             	xor    r9,r10
 1e2:	4d 01 d9             	add    r9,r11
 1e5:	4d 31 cf             	xor    r15,r9
 1e8:	c4 43 fb f0 df 2f    	rorx   r11,r15,0x2f
 1ee:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 1f4:	c4 43 fb f0 f6 2b    	rorx   r14,r14,0x2b
 1fa:	4d 31 c6             	xor    r14,r8
 1fd:	4d 31 d6             	xor    r14,r10
 200:	4c 01 f3             	add    rbx,r14
 203:	c4 43 fb f0 d6 30    	rorx   r10,r14,0x30
 209:	49 31 da             	xor    r10,rbx
 20c:	4c 01 fb             	add    rbx,r15
 20f:	49 31 db             	xor    r11,rbx
 212:	c4 43 fb f0 f3 33    	rorx   r14,r11,0x33
 218:	c4 43 fb f0 fa 2b    	rorx   r15,r10,0x2b
 21e:	c4 43 fb f0 c9 20    	rorx   r9,r9,0x20
 224:	4d 01 d1             	add    r9,r10
 227:	4d 31 cf             	xor    r15,r9
 22a:	4d 01 d9             	add    r9,r11
 22d:	4d 31 ce             	xor    r14,r9
 230:	c4 43 fb f0 d6 2f    	rorx   r10,r14,0x2f
 236:	c4 43 fb f0 df 30    	rorx   r11,r15,0x30
 23c:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 242:	4c 01 fb             	add    rbx,r15
 245:	49 31 db             	xor    r11,rbx
 248:	4c 01 f3             	add    rbx,r14
 24b:	49 31 da             	xor    r10,rbx
 24e:	c4 43 fb f0 f2 33    	rorx   r14,r10,0x33
 254:	c4 43 fb f0 c9 20    	rorx   r9,r9,0x20
 25a:	4d 01 d9             	add    r9,r11
 25d:	4d 31 c8             	xor    r8,r9
 260:	4d 01 d0             	add    r8,r10
 263:	4d 31 c6             	xor    r14,r8
 266:	c4 43 fb f0 d6 2f    	rorx   r10,r14,0x2f
 26c:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 272:	c4 43 fb f0 db 2b    	rorx   r11,r11,0x2b
 278:	49 31 fb             	xor    r11,rdi
 27b:	4d 31 cb             	xor    r11,r9
 27e:	4c 01 db             	add    rbx,r11
 281:	c4 43 fb f0 cb 30    	rorx   r9,r11,0x30
 287:	49 31 d9             	xor    r9,rbx
 28a:	4c 01 f3             	add    rbx,r14
 28d:	49 31 da             	xor    r10,rbx
 290:	c4 43 fb f0 da 33    	rorx   r11,r10,0x33
 296:	c4 43 fb f0 f1 2b    	rorx   r14,r9,0x2b
 29c:	c4 43 fb f0 c0 20    	rorx   r8,r8,0x20
 2a2:	4d 01 c8             	add    r8,r9
 2a5:	4d 31 c6             	xor    r14,r8
 2a8:	4d 01 d0             	add    r8,r10
 2ab:	4d 31 c3             	xor    r11,r8
 2ae:	c4 43 fb f0 cb 2f    	rorx   r9,r11,0x2f
 2b4:	c4 43 fb f0 d6 30    	rorx   r10,r14,0x30
 2ba:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 2c0:	4c 01 f3             	add    rbx,r14
 2c3:	49 31 da             	xor    r10,rbx
 2c6:	4c 01 db             	add    rbx,r11
 2c9:	49 31 d9             	xor    r9,rbx
 2cc:	c4 43 fb f0 d9 33    	rorx   r11,r9,0x33
 2d2:	c4 43 fb f0 c0 20    	rorx   r8,r8,0x20
 2d8:	4d 01 d0             	add    r8,r10
 2db:	4c 31 c7             	xor    rdi,r8
 2de:	4c 01 cf             	add    rdi,r9
 2e1:	49 31 fb             	xor    r11,rdi
 2e4:	c4 43 fb f0 cb 2f    	rorx   r9,r11,0x2f
 2ea:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 2f0:	c4 43 fb f0 d2 2b    	rorx   r10,r10,0x2b
 2f6:	49 31 f2             	xor    r10,rsi
 2f9:	4d 31 c2             	xor    r10,r8
 2fc:	4c 01 d3             	add    rbx,r10
 2ff:	c4 43 fb f0 c2 30    	rorx   r8,r10,0x30
 305:	49 31 d8             	xor    r8,rbx
 308:	4c 01 db             	add    rbx,r11
 30b:	49 31 d9             	xor    r9,rbx
 30e:	c4 43 fb f0 d1 33    	rorx   r10,r9,0x33
 314:	c4 43 fb f0 d8 2b    	rorx   r11,r8,0x2b
 31a:	c4 e3 fb f0 ff 20    	rorx   rdi,rdi,0x20
 320:	4c 01 c7             	add    rdi,r8
 323:	49 31 fb             	xor    r11,rdi
 326:	4c 01 cf             	add    rdi,r9
 329:	49 31 fa             	xor    r10,rdi
 32c:	c4 43 fb f0 c2 2f    	rorx   r8,r10,0x2f
 332:	c4 43 fb f0 cb 30    	rorx   r9,r11,0x30
 338:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
 33e:	4c 01 db             	add    rbx,r11
 341:	49 31 d9             	xor    r9,rbx
 344:	4c 01 d3             	add    rbx,r10
 347:	49 31 d8             	xor    r8,rbx
 34a:	c4 43 fb f0 d0 33    	rorx   r10,r8,0x33
 350:	c4 e3 fb f0 ff 20    	rorx   rdi,rdi,0x20
 356:	4c 01 cf             	add    rdi,r9
 359:	48 31 fe             	xor    rsi,rdi
 35c:	4c 01 c6             	add    rsi,r8
 35f:	49 31 f2             	xor    r10,rsi
 362:	c4 43 fb f0 c2 2f    	rorx   r8,r10,0x2f
 368:	c4 63 fb f0 db 20    	rorx   r11,rbx,0x20
 36e:	c4 43 fb f0 c9 2b    	rorx   r9,r9,0x2b
 374:	49 31 d1             	xor    r9,rdx
 377:	49 31 f9             	xor    r9,rdi
 37a:	4d 01 cb             	add    r11,r9
 37d:	c4 c3 fb f0 f9 30    	rorx   rdi,r9,0x30
 383:	4c 31 df             	xor    rdi,r11
 386:	4d 01 d3             	add    r11,r10
 389:	4d 31 d8             	xor    r8,r11
 38c:	c4 43 fb f0 c8 33    	rorx   r9,r8,0x33
 392:	c4 63 fb f0 d7 2b    	rorx   r10,rdi,0x2b
 398:	c4 e3 fb f0 f6 20    	rorx   rsi,rsi,0x20
 39e:	48 01 fe             	add    rsi,rdi
 3a1:	49 31 f2             	xor    r10,rsi
 3a4:	4c 01 c6             	add    rsi,r8
 3a7:	49 31 f1             	xor    r9,rsi
 3aa:	c4 c3 fb f0 f9 2f    	rorx   rdi,r9,0x2f
 3b0:	c4 43 fb f0 c2 30    	rorx   r8,r10,0x30
 3b6:	c4 43 fb f0 db 20    	rorx   r11,r11,0x20
 3bc:	4d 01 d3             	add    r11,r10
 3bf:	4d 31 d8             	xor    r8,r11
 3c2:	4d 01 cb             	add    r11,r9
 3c5:	4c 31 df             	xor    rdi,r11
 3c8:	c4 63 fb f0 cf 33    	rorx   r9,rdi,0x33
 3ce:	c4 e3 fb f0 f6 20    	rorx   rsi,rsi,0x20
 3d4:	4c 01 c6             	add    rsi,r8
 3d7:	48 31 f2             	xor    rdx,rsi
 3da:	48 01 fa             	add    rdx,rdi
 3dd:	49 31 d1             	xor    r9,rdx
 3e0:	c4 c3 fb f0 f9 2f    	rorx   rdi,r9,0x2f
 3e6:	c4 43 fb f0 d3 20    	rorx   r10,r11,0x20
 3ec:	c4 43 fb f0 c0 2b    	rorx   r8,r8,0x2b
 3f2:	49 31 c0             	xor    r8,rax
 3f5:	49 31 f0             	xor    r8,rsi
 3f8:	4d 01 c2             	add    r10,r8
 3fb:	c4 c3 fb f0 f0 30    	rorx   rsi,r8,0x30
 401:	4c 31 d6             	xor    rsi,r10
 404:	4d 01 ca             	add    r10,r9
 407:	4c 31 d7             	xor    rdi,r10
 40a:	c4 63 fb f0 c7 33    	rorx   r8,rdi,0x33
 410:	c4 63 fb f0 ce 2b    	rorx   r9,rsi,0x2b
 416:	c4 e3 fb f0 d2 20    	rorx   rdx,rdx,0x20
 41c:	48 01 f2             	add    rdx,rsi
 41f:	49 31 d1             	xor    r9,rdx
 422:	48 01 fa             	add    rdx,rdi
 425:	49 31 d0             	xor    r8,rdx
 428:	c4 c3 fb f0 f8 2f    	rorx   rdi,r8,0x2f
 42e:	c4 43 fb f0 d9 30    	rorx   r11,r9,0x30
 434:	c4 43 fb f0 d2 20    	rorx   r10,r10,0x20
 43a:	4d 01 ca             	add    r10,r9
 43d:	4d 31 d3             	xor    r11,r10
 440:	4d 01 c2             	add    r10,r8
 443:	4c 31 d7             	xor    rdi,r10
 446:	c4 e3 fb f0 f7 33    	rorx   rsi,rdi,0x33
 44c:	c4 63 fb f0 c2 20    	rorx   r8,rdx,0x20
 452:	c4 43 fb f0 cb 2b    	rorx   r9,r11,0x2b
 458:	4d 01 d8             	add    r8,r11
 45b:	4d 31 c1             	xor    r9,r8
 45e:	49 31 c0             	xor    r8,rax
 461:	49 01 f8             	add    r8,rdi
 464:	4c 31 c6             	xor    rsi,r8
 467:	c4 e3 fb f0 d6 2f    	rorx   rdx,rsi,0x2f
 46d:	c4 c3 fb f0 c2 20    	rorx   rax,r10,0x20
 473:	48 35 ff 00 00 00    	xor    rax,0xff
 479:	4c 01 c8             	add    rax,r9
 47c:	48 01 c6             	add    rsi,rax
 47f:	48 31 f2             	xor    rdx,rsi
 482:	c4 e3 fb f0 fa 33    	rorx   rdi,rdx,0x33
 488:	c4 43 fb f0 c9 30    	rorx   r9,r9,0x30
 48e:	49 31 c1             	xor    r9,rax
 491:	c4 43 fb f0 c0 20    	rorx   r8,r8,0x20
 497:	4d 01 c8             	add    r8,r9
 49a:	4c 01 c2             	add    rdx,r8
 49d:	48 31 d7             	xor    rdi,rdx
 4a0:	c4 e3 fb f0 c7 2f    	rorx   rax,rdi,0x2f
 4a6:	c4 63 fb f0 d6 20    	rorx   r10,rsi,0x20
 4ac:	c4 43 fb f0 c9 2b    	rorx   r9,r9,0x2b
 4b2:	4d 31 c1             	xor    r9,r8
 4b5:	4d 01 ca             	add    r10,r9
 4b8:	4c 01 d7             	add    rdi,r10
 4bb:	48 31 f8             	xor    rax,rdi
 4be:	c4 e3 fb f0 f0 33    	rorx   rsi,rax,0x33
 4c4:	c4 43 fb f0 c1 30    	rorx   r8,r9,0x30
 4ca:	4d 31 d0             	xor    r8,r10
 4cd:	c4 63 fb f0 ca 20    	rorx   r9,rdx,0x20
 4d3:	4d 01 c1             	add    r9,r8
 4d6:	4c 01 c8             	add    rax,r9
 4d9:	48 31 c6             	xor    rsi,rax
 4dc:	c4 e3 fb f0 d6 2f    	rorx   rdx,rsi,0x2f
 4e2:	c4 e3 fb f0 ff 20    	rorx   rdi,rdi,0x20
 4e8:	c4 43 fb f0 c0 2b    	rorx   r8,r8,0x2b
 4ee:	4d 31 c8             	xor    r8,r9
 4f1:	4c 01 c7             	add    rdi,r8
 4f4:	48 01 fe             	add    rsi,rdi
 4f7:	48 31 f2             	xor    rdx,rsi
 4fa:	c4 63 fb f0 ca 33    	rorx   r9,rdx,0x33
 500:	c4 43 fb f0 c0 30    	rorx   r8,r8,0x30
 506:	49 31 f8             	xor    r8,rdi
 509:	c4 e3 fb f0 c0 20    	rorx   rax,rax,0x20
 50f:	4c 01 c0             	add    rax,r8
 512:	48 01 c2             	add    rdx,rax
 515:	4c 31 ca             	xor    rdx,r9
 518:	c4 e3 fb f0 f6 20    	rorx   rsi,rsi,0x20
 51e:	c4 c3 fb f0 f8 2b    	rorx   rdi,r8,0x2b
 524:	48 31 c7             	xor    rdi,rax
 527:	48 01 fe             	add    rsi,rdi
 52a:	c4 e3 fb f0 c7 30    	rorx   rax,rdi,0x30
 530:	48 31 f0             	xor    rax,rsi
 533:	48 01 d6             	add    rsi,rdx
 536:	c4 e3 fb f0 fe 20    	rorx   rdi,rsi,0x20
 53c:	c4 e3 fb f0 c0 2b    	rorx   rax,rax,0x2b
 542:	c4 e3 fb f0 d2 2f    	rorx   rdx,rdx,0x2f
 548:	48 31 c2             	xor    rdx,rax
 54b:	48 31 f7             	xor    rdi,rsi
 54e:	48 31 d7             	xor    rdi,rdx
 551:	48 89 39             	mov    QWORD PTR [rcx],rdi
 554:	b8 02 00 00 00       	mov    eax,0x2
 559:	5b                   	pop    rbx
 55a:	41 5c                	pop    r12
 55c:	41 5d                	pop    r13
 55e:	41 5e                	pop    r14
 560:	41 5f                	pop    r15
 562:	5d                   	pop    rbp
 563:	c3                   	ret
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
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: ja     1569 <siphash_rotate64_mixer_xdp+0x469> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (639) - 1, 0),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1119: ja     1569 <siphash_rotate64_mixer_xdp+0x469> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (632) - 1, 0),
    /* 0x111f: lea    rsi,[rcx+0x48] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 72), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1126: ja     1569 <siphash_rotate64_mixer_xdp+0x469> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (625) - 1, 0),
    /* 0x112c: mov    r9,QWORD PTR [rcx+0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RCX, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1130: movabs rdi,0x7465646279746573 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x7465646279746573ULL),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDI, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x113a: xor    rdi,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x113d: movabs rdx,0x6c7967656e657261 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6c7967656e657261ULL),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1147: add    rdx,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x114a: movabs rax,0xa60c596fc19fead0 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xa60c596fc19fead0ULL),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RAX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1154: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1157: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x115b: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x115e: movabs r8,0xded7d4e2d7dedfc6 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xded7d4e2d7dedfc6ULL),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_R8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1168: add    r8,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x116b: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x116f: movabs rdx,0xe414a674f0de7325 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xe414a674f0de7325ULL),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1179: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x117c: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1180: xor    rdi,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1183: add    r8,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1186: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x118a: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x118d: rol    r8,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1191: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1194: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1198: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x119b: add    r8,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119e: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11a2: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a5: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11a9: mov    rsi,QWORD PTR [rcx+0x10] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11ad: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11b0: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11b4: xor    r9,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11b7: add    r9,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ba: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11be: xor    r8,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11c1: xor    rdx,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11c4: rol    r9,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11c8: xor    r8,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11cb: add    rax,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ce: rol    r8,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11d2: xor    r8,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11d5: add    r9,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d8: rol    r8,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11dc: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11df: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11e3: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11e6: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11ea: xor    r8,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11ed: add    r9,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11f0: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11f4: xor    rdx,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11f7: rol    r9,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11fb: add    rax,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11fe: rol    r8,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1202: xor    r8,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1205: add    r9,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1208: rol    r8,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x120c: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x120f: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1213: mov    rdi,QWORD PTR [rcx+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1217: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x121a: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x121e: xor    rsi,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1221: add    rsi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1224: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1228: xor    r9,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x122b: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x122e: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1232: xor    r9,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1235: add    rax,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1238: rol    r9,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x123c: xor    r9,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x123f: add    rsi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1242: rol    r9,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1246: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1249: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x124d: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1250: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1254: xor    r9,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1257: add    rsi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x125a: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x125e: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1261: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1265: add    rax,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1268: rol    r9,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x126c: xor    r9,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x126f: add    rsi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1272: rol    r9,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1276: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1279: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x127d: mov    r8,QWORD PTR [rcx+0x20] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R8, HC_X86_RCX, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1281: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1284: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1288: xor    rdi,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x128b: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x128e: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1292: xor    rsi,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1295: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1298: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x129c: xor    rsi,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x129f: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12a2: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12a6: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12a9: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12ac: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12b0: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12b3: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12b7: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ba: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12be: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12c1: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12c4: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12c8: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12cb: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12cf: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12d2: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12d6: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12d9: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12dc: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12e0: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12e3: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12e7: mov    r9,QWORD PTR [rcx+0x28] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RCX, 40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12eb: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ee: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12f2: xor    r8,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12f5: add    r8,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12f8: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12fc: xor    rdi,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ff: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1302: rol    r8,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1306: xor    rdi,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1309: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x130c: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1310: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1313: add    r8,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1316: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x131a: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x131d: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1321: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1324: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1328: xor    rdi,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132b: add    r8,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x132e: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1332: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1335: rol    r8,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1339: add    rax,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x133c: rol    rdi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1340: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1343: add    r8,rdi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1346: rol    rdi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x134a: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x134d: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1351: mov    rsi,QWORD PTR [rcx+0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1355: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1358: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x135c: xor    r9,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x135f: add    r9,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1362: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1366: xor    r8,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1369: xor    rdx,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x136c: rol    r9,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1370: xor    r8,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1373: add    rax,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1376: rol    r8,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x137a: xor    r8,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x137d: add    r9,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1380: rol    r8,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1384: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1387: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x138b: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x138e: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1392: xor    r8,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1395: add    r9,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1398: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x139c: xor    rdx,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x139f: rol    r9,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13a3: add    rax,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13a6: rol    r8,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13aa: xor    r8,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13ad: add    r9,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13b0: rol    r8,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R8, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13b4: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13b7: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13bb: mov    rdi,QWORD PTR [rcx+0x38] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13bf: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c2: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13c6: xor    rsi,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c9: add    rsi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13cc: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13d0: xor    r9,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13d3: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13d6: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13da: xor    r9,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13dd: add    rax,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e0: rol    r9,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13e4: xor    r9,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13e7: add    rsi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13ea: rol    r9,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13ee: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13f1: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13f5: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13f8: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13fc: xor    r9,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13ff: add    rsi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1402: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1406: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1409: rol    rsi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x140d: add    rax,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1410: rol    r9,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1414: xor    r9,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1417: add    rsi,r9 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x141a: rol    r9,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R9, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x141e: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1421: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1425: mov    r8,QWORD PTR [rcx+0x40] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R8, HC_X86_RCX, 64), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1429: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x142c: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1430: xor    rdi,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1433: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1436: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x143a: xor    rsi,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x143d: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1440: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1444: xor    rsi,r9 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1447: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x144a: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x144e: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1451: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1454: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1458: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x145b: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x145f: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1462: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1466: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1469: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x146c: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1470: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1473: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1477: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x147a: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x147e: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1481: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1484: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1488: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x148b: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x148f: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1492: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1495: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1499: xor    rdi,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x149c: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x149f: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14a3: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14a6: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14aa: xor    rax,0xff [exact-kinsn: xor64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 255), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14b0: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14b3: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14b7: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14ba: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14bd: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14c1: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14c4: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14c8: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14cb: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14cf: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14d2: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14d5: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14d9: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14dc: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14e0: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14e3: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14e7: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14ea: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14ed: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14f1: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x14f4: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14f8: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x14fb: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x14ff: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1502: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1505: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1509: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x150c: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1510: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1513: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1517: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x151a: add    rdi,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x151d: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1521: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1524: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1528: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x152b: rol    rax,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x152f: xor    rsi,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1532: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1535: rol    rdx,0xd [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 13), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1539: add    rax,rsi [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x153c: rol    rsi,0x10 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1540: xor    rsi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1543: rol    rsi,0x15 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RSI, 21), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1547: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x154a: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x154d: rol    rdx,0x11 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 17), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1551: mov    rdi,rax [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1554: rol    rdi,0x20 [exact-kinsn: rolq imm kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RDI, 32), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1558: xor    rdi,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x155b: xor    rdi,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x155e: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1561: mov    QWORD PTR [rcx],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1564: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1569: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
