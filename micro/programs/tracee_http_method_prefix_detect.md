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
    1130:	41 56                	push   r14
    1132:	53                   	push   rbx
    1133:	48 8d 42 16          	lea    rax,[rdx+0x16]
    1137:	48 bb 2f 64 bd 78 64 	movabs rbx,0xa0761d6478bd642f
    113e:	1d 76 a0 
    1141:	b9 01 00 00 00       	mov    ecx,0x1
    1146:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    114d:	00 00 00 
    1150:	48 89 de             	mov    rsi,rbx
    1153:	0f b6 78 fa          	movzx  edi,BYTE PTR [rax-0x6]
    1157:	44 0f b6 40 fb       	movzx  r8d,BYTE PTR [rax-0x5]
    115c:	83 ff 47             	cmp    edi,0x47
    115f:	7f 4f                	jg     11b0 <tracee_http_method_prefix_detect_xdp+0xb0>
    1161:	83 ff 44             	cmp    edi,0x44
    1164:	0f 84 a5 00 00 00    	je     120f <tracee_http_method_prefix_detect_xdp+0x10f>
    116a:	83 ff 47             	cmp    edi,0x47
    116d:	0f 85 6d 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1173:	41 80 f8 45          	cmp    r8b,0x45
    1177:	0f 85 63 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    117d:	41 b0 45             	mov    r8b,0x45
    1180:	80 78 fc 54          	cmp    BYTE PTR [rax-0x4],0x54
    1184:	0f 85 56 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    118a:	41 b2 45             	mov    r10b,0x45
    118d:	80 78 fd 20          	cmp    BYTE PTR [rax-0x3],0x20
    1191:	0f 85 49 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1197:	41 b9 01 00 00 00    	mov    r9d,0x1
    119d:	e9 09 01 00 00       	jmp    12ab <tracee_http_method_prefix_detect_xdp+0x1ab>
    11a2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11a9:	1f 84 00 00 00 00 00 
    11b0:	45 0f b6 c8          	movzx  r9d,r8b
    11b4:	83 ff 48             	cmp    edi,0x48
    11b7:	0f 84 a4 00 00 00    	je     1261 <tracee_http_method_prefix_detect_xdp+0x161>
    11bd:	83 ff 50             	cmp    edi,0x50
    11c0:	0f 85 1a 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11c6:	41 83 f9 55          	cmp    r9d,0x55
    11ca:	0f 84 c3 00 00 00    	je     1293 <tracee_http_method_prefix_detect_xdp+0x193>
    11d0:	41 83 f9 4f          	cmp    r9d,0x4f
    11d4:	0f 85 06 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11da:	41 b0 4f             	mov    r8b,0x4f
    11dd:	80 78 fc 53          	cmp    BYTE PTR [rax-0x4],0x53
    11e1:	0f 85 f9 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11e7:	80 78 fd 54          	cmp    BYTE PTR [rax-0x3],0x54
    11eb:	0f 85 ef 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11f1:	41 b2 4f             	mov    r10b,0x4f
    11f4:	80 78 fe 20          	cmp    BYTE PTR [rax-0x2],0x20
    11f8:	0f 85 e2 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11fe:	41 b9 02 00 00 00    	mov    r9d,0x2
    1204:	41 b0 53             	mov    r8b,0x53
    1207:	41 b3 54             	mov    r11b,0x54
    120a:	e9 e1 00 00 00       	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    120f:	41 80 f8 45          	cmp    r8b,0x45
    1213:	0f 85 c7 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1219:	41 b0 45             	mov    r8b,0x45
    121c:	80 78 fc 4c          	cmp    BYTE PTR [rax-0x4],0x4c
    1220:	0f 85 ba 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1226:	80 78 fd 45          	cmp    BYTE PTR [rax-0x3],0x45
    122a:	0f 85 b0 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1230:	80 78 fe 54          	cmp    BYTE PTR [rax-0x2],0x54
    1234:	0f 85 a6 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    123a:	80 78 ff 45          	cmp    BYTE PTR [rax-0x1],0x45
    123e:	0f 85 9c 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1244:	41 b3 45             	mov    r11b,0x45
    1247:	80 38 20             	cmp    BYTE PTR [rax],0x20
    124a:	0f 85 90 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1250:	41 b9 04 00 00 00    	mov    r9d,0x4
    1256:	41 b0 4c             	mov    r8b,0x4c
    1259:	41 b2 45             	mov    r10b,0x45
    125c:	e9 8f 00 00 00       	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    1261:	41 83 f9 54          	cmp    r9d,0x54
    1265:	74 4c                	je     12b3 <tracee_http_method_prefix_detect_xdp+0x1b3>
    1267:	41 83 f9 45          	cmp    r9d,0x45
    126b:	75 73                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    126d:	41 b0 45             	mov    r8b,0x45
    1270:	80 78 fc 41          	cmp    BYTE PTR [rax-0x4],0x41
    1274:	75 6a                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1276:	80 78 fd 44          	cmp    BYTE PTR [rax-0x3],0x44
    127a:	75 64                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    127c:	41 b2 45             	mov    r10b,0x45
    127f:	80 78 fe 20          	cmp    BYTE PTR [rax-0x2],0x20
    1283:	75 5b                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1285:	41 b9 05 00 00 00    	mov    r9d,0x5
    128b:	41 b0 41             	mov    r8b,0x41
    128e:	41 b3 44             	mov    r11b,0x44
    1291:	eb 5d                	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    1293:	41 b0 55             	mov    r8b,0x55
    1296:	80 78 fc 54          	cmp    BYTE PTR [rax-0x4],0x54
    129a:	75 44                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    129c:	41 b2 55             	mov    r10b,0x55
    129f:	80 78 fd 20          	cmp    BYTE PTR [rax-0x3],0x20
    12a3:	75 3b                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12a5:	41 b9 03 00 00 00    	mov    r9d,0x3
    12ab:	41 b0 54             	mov    r8b,0x54
    12ae:	41 b3 20             	mov    r11b,0x20
    12b1:	eb 3d                	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    12b3:	41 b0 54             	mov    r8b,0x54
    12b6:	80 78 fc 54          	cmp    BYTE PTR [rax-0x4],0x54
    12ba:	75 24                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12bc:	80 78 fd 50          	cmp    BYTE PTR [rax-0x3],0x50
    12c0:	75 1e                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12c2:	80 78 fe 2f          	cmp    BYTE PTR [rax-0x2],0x2f
    12c6:	75 18                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12c8:	41 b9 06 00 00 00    	mov    r9d,0x6
    12ce:	41 b3 50             	mov    r11b,0x50
    12d1:	41 b2 54             	mov    r10b,0x54
    12d4:	eb 1a                	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    12d6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    12dd:	00 00 00 
    12e0:	45 89 c2             	mov    r10d,r8d
    12e3:	44 0f b6 40 fc       	movzx  r8d,BYTE PTR [rax-0x4]
    12e8:	44 0f b6 58 fd       	movzx  r11d,BYTE PTR [rax-0x3]
    12ed:	45 31 c9             	xor    r9d,r9d
    12f0:	45 0f b6 db          	movzx  r11d,r11b
    12f4:	41 8d 59 01          	lea    ebx,[r9+0x1]
    12f8:	4c 8d 71 0a          	lea    r14,[rcx+0xa]
    12fc:	49 0f af de          	imul   rbx,r14
    1300:	48 01 de             	add    rsi,rbx
    1303:	49 c1 e3 20          	shl    r11,0x20
    1307:	45 0f b6 c0          	movzx  r8d,r8b
    130b:	41 c1 e0 18          	shl    r8d,0x18
    130f:	45 0f b6 d2          	movzx  r10d,r10b
    1313:	41 c1 e2 10          	shl    r10d,0x10
    1317:	c1 e7 08             	shl    edi,0x8
    131a:	44 09 d7             	or     edi,r10d
    131d:	44 09 c7             	or     edi,r8d
    1320:	4c 09 df             	or     rdi,r11
    1323:	44 89 cb             	mov    ebx,r9d
    1326:	48 09 fb             	or     rbx,rdi
    1329:	48 d3 e3             	shl    rbx,cl
    132c:	48 31 f3             	xor    rbx,rsi
    132f:	48 83 c0 10          	add    rax,0x10
    1333:	48 ff c1             	inc    rcx
    1336:	48 83 f9 09          	cmp    rcx,0x9
    133a:	0f 85 10 fe ff ff    	jne    1150 <tracee_http_method_prefix_detect_xdp+0x50>
    1340:	40 88 32             	mov    BYTE PTR [rdx],sil
    1343:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
    1346:	89 d8                	mov    eax,ebx
    1348:	c1 e8 10             	shr    eax,0x10
    134b:	88 42 02             	mov    BYTE PTR [rdx+0x2],al
    134e:	89 d8                	mov    eax,ebx
    1350:	c1 e8 18             	shr    eax,0x18
    1353:	88 42 03             	mov    BYTE PTR [rdx+0x3],al
    1356:	48 89 d8             	mov    rax,rbx
    1359:	48 c1 e8 20          	shr    rax,0x20
    135d:	88 42 04             	mov    BYTE PTR [rdx+0x4],al
    1360:	48 89 d8             	mov    rax,rbx
    1363:	48 c1 e8 28          	shr    rax,0x28
    1367:	88 42 05             	mov    BYTE PTR [rdx+0x5],al
    136a:	48 89 d8             	mov    rax,rbx
    136d:	48 c1 e8 30          	shr    rax,0x30
    1371:	88 42 06             	mov    BYTE PTR [rdx+0x6],al
    1374:	48 c1 eb 38          	shr    rbx,0x38
    1378:	88 5a 07             	mov    BYTE PTR [rdx+0x7],bl
    137b:	b8 02 00 00 00       	mov    eax,0x2
    1380:	5b                   	pop    rbx
    1381:	41 5e                	pop    r14
    1383:	c3                   	ret

Disassembly of section .fini:

0000000000001384 <_fini>:
    1384:	f3 0f 1e fa          	endbr64
    1388:	48 83 ec 08          	sub    rsp,0x8
    138c:	48 83 c4 08          	add    rsp,0x8
    1390:	c3                   	ret
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
  20:	0f 87 3f 03 00 00    	ja     0x365
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 2f 03 00 00    	ja     0x365
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 90 00 00 00 	add    rdx,0x90
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 1c 03 00 00    	ja     0x365
  49:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4e:	c1 e6 08             	shl    esi,0x8
  51:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  56:	09 d6                	or     esi,edx
  58:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  5d:	c1 e2 10             	shl    edx,0x10
  60:	09 d6                	or     esi,edx
  62:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  67:	c1 e2 18             	shl    edx,0x18
  6a:	09 d6                	or     esi,edx
  6c:	83 fe 08             	cmp    esi,0x8
  6f:	0f 85 f0 02 00 00    	jne    0x365
  75:	48 0f b6 77 0d       	movzx  rsi,BYTE PTR [rdi+0xd]
  7a:	c1 e6 08             	shl    esi,0x8
  7d:	48 0f b6 57 0c       	movzx  rdx,BYTE PTR [rdi+0xc]
  82:	09 d6                	or     esi,edx
  84:	48 0f b6 57 0e       	movzx  rdx,BYTE PTR [rdi+0xe]
  89:	c1 e2 10             	shl    edx,0x10
  8c:	09 d6                	or     esi,edx
  8e:	48 0f b6 57 0f       	movzx  rdx,BYTE PTR [rdi+0xf]
  93:	c1 e2 18             	shl    edx,0x18
  96:	09 d6                	or     esi,edx
  98:	83 fe 10             	cmp    esi,0x10
  9b:	0f 85 c4 02 00 00    	jne    0x365
  a1:	48 be 2f 64 bd 78 64 	movabs rsi,0xa0761d6478bd642f
  a8:	1d 76 a0 
  ab:	ba 01 00 00 00       	mov    edx,0x1
  b0:	48 89 f9             	mov    rcx,rdi
  b3:	48 83 c1 16          	add    rcx,0x16
  b7:	49 89 f0             	mov    r8,rsi
  ba:	48 0f b6 71 fb       	movzx  rsi,BYTE PTR [rcx-0x5]
  bf:	48 0f b6 41 fa       	movzx  rax,BYTE PTR [rcx-0x6]
  c4:	83 f8 47             	cmp    eax,0x47
  c7:	7f 59                	jg     0x122
  c9:	83 f8 44             	cmp    eax,0x44
  cc:	0f 84 c0 00 00 00    	je     0x192
  d2:	83 f8 47             	cmp    eax,0x47
  d5:	74 05                	je     0xdc
  d7:	e9 e8 01 00 00       	jmp    0x2c4
  dc:	83 fe 45             	cmp    esi,0x45
  df:	0f 85 df 01 00 00    	jne    0x2c4
  e5:	be 45 00 00 00       	mov    esi,0x45
  ea:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
  ef:	83 fb 54             	cmp    ebx,0x54
  f2:	0f 85 cc 01 00 00    	jne    0x2c4
  f8:	bb 01 00 00 00       	mov    ebx,0x1
  fd:	be 45 00 00 00       	mov    esi,0x45
 102:	41 be 54 00 00 00    	mov    r14d,0x54
 108:	41 bd 20 00 00 00    	mov    r13d,0x20
 10e:	4c 0f b6 79 fd       	movzx  r15,BYTE PTR [rcx-0x3]
 113:	41 83 ff 20          	cmp    r15d,0x20
 117:	0f 84 b3 01 00 00    	je     0x2d0
 11d:	e9 a2 01 00 00       	jmp    0x2c4
 122:	83 f8 48             	cmp    eax,0x48
 125:	0f 84 d7 00 00 00    	je     0x202
 12b:	83 f8 50             	cmp    eax,0x50
 12e:	74 05                	je     0x135
 130:	e9 8f 01 00 00       	jmp    0x2c4
 135:	83 fe 55             	cmp    esi,0x55
 138:	0f 84 1a 01 00 00    	je     0x258
 13e:	83 fe 4f             	cmp    esi,0x4f
 141:	0f 85 7d 01 00 00    	jne    0x2c4
 147:	be 4f 00 00 00       	mov    esi,0x4f
 14c:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 151:	83 fb 53             	cmp    ebx,0x53
 154:	0f 85 6a 01 00 00    	jne    0x2c4
 15a:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 15f:	83 fb 54             	cmp    ebx,0x54
 162:	0f 85 5c 01 00 00    	jne    0x2c4
 168:	bb 02 00 00 00       	mov    ebx,0x2
 16d:	be 4f 00 00 00       	mov    esi,0x4f
 172:	41 be 53 00 00 00    	mov    r14d,0x53
 178:	41 bd 54 00 00 00    	mov    r13d,0x54
 17e:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 183:	41 83 ff 20          	cmp    r15d,0x20
 187:	0f 84 43 01 00 00    	je     0x2d0
 18d:	e9 32 01 00 00       	jmp    0x2c4
 192:	83 fe 45             	cmp    esi,0x45
 195:	0f 85 29 01 00 00    	jne    0x2c4
 19b:	be 45 00 00 00       	mov    esi,0x45
 1a0:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 1a5:	83 fb 4c             	cmp    ebx,0x4c
 1a8:	0f 85 16 01 00 00    	jne    0x2c4
 1ae:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 1b3:	83 fb 45             	cmp    ebx,0x45
 1b6:	0f 85 08 01 00 00    	jne    0x2c4
 1bc:	48 0f b6 59 fe       	movzx  rbx,BYTE PTR [rcx-0x2]
 1c1:	83 fb 54             	cmp    ebx,0x54
 1c4:	0f 85 fa 00 00 00    	jne    0x2c4
 1ca:	48 0f b6 59 ff       	movzx  rbx,BYTE PTR [rcx-0x1]
 1cf:	83 fb 45             	cmp    ebx,0x45
 1d2:	0f 85 ec 00 00 00    	jne    0x2c4
 1d8:	bb 04 00 00 00       	mov    ebx,0x4
 1dd:	41 be 4c 00 00 00    	mov    r14d,0x4c
 1e3:	be 45 00 00 00       	mov    esi,0x45
 1e8:	4c 0f b6 79 00       	movzx  r15,BYTE PTR [rcx+0x0]
 1ed:	41 bd 45 00 00 00    	mov    r13d,0x45
 1f3:	41 83 ff 20          	cmp    r15d,0x20
 1f7:	0f 84 d3 00 00 00    	je     0x2d0
 1fd:	e9 c2 00 00 00       	jmp    0x2c4
 202:	83 fe 54             	cmp    esi,0x54
 205:	0f 84 7f 00 00 00    	je     0x28a
 20b:	83 fe 45             	cmp    esi,0x45
 20e:	0f 85 b0 00 00 00    	jne    0x2c4
 214:	be 45 00 00 00       	mov    esi,0x45
 219:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 21e:	83 fb 41             	cmp    ebx,0x41
 221:	0f 85 9d 00 00 00    	jne    0x2c4
 227:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 22c:	83 fb 44             	cmp    ebx,0x44
 22f:	0f 85 8f 00 00 00    	jne    0x2c4
 235:	bb 05 00 00 00       	mov    ebx,0x5
 23a:	be 45 00 00 00       	mov    esi,0x45
 23f:	41 be 41 00 00 00    	mov    r14d,0x41
 245:	41 bd 44 00 00 00    	mov    r13d,0x44
 24b:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 250:	41 83 ff 20          	cmp    r15d,0x20
 254:	74 7a                	je     0x2d0
 256:	eb 6c                	jmp    0x2c4
 258:	be 55 00 00 00       	mov    esi,0x55
 25d:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 262:	83 fb 54             	cmp    ebx,0x54
 265:	75 5d                	jne    0x2c4
 267:	bb 03 00 00 00       	mov    ebx,0x3
 26c:	be 55 00 00 00       	mov    esi,0x55
 271:	41 be 54 00 00 00    	mov    r14d,0x54
 277:	41 bd 20 00 00 00    	mov    r13d,0x20
 27d:	4c 0f b6 79 fd       	movzx  r15,BYTE PTR [rcx-0x3]
 282:	41 83 ff 20          	cmp    r15d,0x20
 286:	74 48                	je     0x2d0
 288:	eb 3a                	jmp    0x2c4
 28a:	be 54 00 00 00       	mov    esi,0x54
 28f:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 294:	83 fb 54             	cmp    ebx,0x54
 297:	75 2b                	jne    0x2c4
 299:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 29e:	83 fb 50             	cmp    ebx,0x50
 2a1:	75 21                	jne    0x2c4
 2a3:	bb 06 00 00 00       	mov    ebx,0x6
 2a8:	be 54 00 00 00       	mov    esi,0x54
 2ad:	41 bd 50 00 00 00    	mov    r13d,0x50
 2b3:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 2b8:	41 be 54 00 00 00    	mov    r14d,0x54
 2be:	41 83 ff 2f          	cmp    r15d,0x2f
 2c2:	74 0c                	je     0x2d0
 2c4:	31 db                	xor    ebx,ebx
 2c6:	4c 0f b6 69 fd       	movzx  r13,BYTE PTR [rcx-0x3]
 2cb:	4c 0f b6 71 fc       	movzx  r14,BYTE PTR [rcx-0x4]
 2d0:	48 c1 e0 08          	shl    rax,0x8
 2d4:	48 c1 e6 10          	shl    rsi,0x10
 2d8:	48 09 c6             	or     rsi,rax
 2db:	49 c1 e6 18          	shl    r14,0x18
 2df:	4c 09 f6             	or     rsi,r14
 2e2:	49 c1 e5 20          	shl    r13,0x20
 2e6:	4c 09 ee             	or     rsi,r13
 2e9:	48 09 de             	or     rsi,rbx
 2ec:	83 c3 01             	add    ebx,0x1
 2ef:	48 89 d0             	mov    rax,rdx
 2f2:	48 83 c0 0a          	add    rax,0xa
 2f6:	48 0f af c3          	imul   rax,rbx
 2fa:	49 01 c0             	add    r8,rax
 2fd:	48 83 c1 10          	add    rcx,0x10
 301:	c4 e2 e9 f7 f6       	shlx   rsi,rsi,rdx
 306:	4c 31 c6             	xor    rsi,r8
 309:	48 83 c2 01          	add    rdx,0x1
 30d:	48 83 fa 09          	cmp    rdx,0x9
 311:	74 05                	je     0x318
 313:	e9 9f fd ff ff       	jmp    0xb7
 318:	44 88 47 00          	mov    BYTE PTR [rdi+0x0],r8b
 31c:	48 89 f2             	mov    rdx,rsi
 31f:	48 c1 ea 38          	shr    rdx,0x38
 323:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 326:	48 89 f2             	mov    rdx,rsi
 329:	48 c1 ea 30          	shr    rdx,0x30
 32d:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 330:	48 89 f2             	mov    rdx,rsi
 333:	48 c1 ea 28          	shr    rdx,0x28
 337:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 33a:	48 89 f2             	mov    rdx,rsi
 33d:	48 c1 ea 20          	shr    rdx,0x20
 341:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 344:	48 89 f2             	mov    rdx,rsi
 347:	48 c1 ea 18          	shr    rdx,0x18
 34b:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 34e:	48 89 f2             	mov    rdx,rsi
 351:	48 c1 ea 10          	shr    rdx,0x10
 355:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 358:	48 c1 ee 08          	shr    rsi,0x8
 35c:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
 360:	b8 02 00 00 00       	mov    eax,0x2
 365:	41 5f                	pop    r15
 367:	41 5e                	pop    r14
 369:	41 5d                	pop    r13
 36b:	5b                   	pop    rbx
 36c:	c9                   	leave
 36d:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
