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

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <tracee_http_method_prefix_detect_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, (-3) - 1, 0),
    /* 0x1118: lea    rsi,[rdx+0x90] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 144), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x8 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1128: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 8),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x10 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x112e: jne    110e <tracee_http_method_prefix_detect_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 16),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-20) - 1),
    /* 0x1130: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: lea    rax,[rdx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_3, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1137: movabs rbx,0xa0761d6478bd642f [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xa0761d6478bd642fULL),
    /* 0x1141: mov    ecx,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1146: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x1150: mov    rsi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1153: movzx  edi,BYTE PTR [rax-0x6] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_0, -6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1157: movzx  r8d,BYTE PTR [rax-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_0, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x115c: cmp    edi,0x47 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x115f: jg     11b0 <tracee_http_method_prefix_detect_xdp+0xb0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_1, 0, (33) - 1, 71),
    /* 0x1161: cmp    edi,0x44 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1164: je     120f <tracee_http_method_prefix_detect_xdp+0x10f> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_1, 0, (87) - 1, 68),
    /* 0x116a: cmp    edi,0x47 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x116d: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_1, 0, (255) - 1, 71),
    /* 0x1173: cmp    r8b,0x45 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1177: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_5),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 69),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (248) - 1),
    /* 0x117d: mov    r8b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1180: cmp    BYTE PTR [rax-0x4],0x54 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1184: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 84),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (238) - 1),
    /* 0x118a: mov    r10b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x118d: cmp    BYTE PTR [rax-0x3],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1191: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (228) - 1),
    /* 0x1197: mov    r9d,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119d: jmp    12ab <tracee_http_method_prefix_detect_xdp+0x1ab> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (187) - 1),
    /* 0x11a2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11b0: movzx  r9d,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11b4: cmp    edi,0x48 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11b7: je     1261 <tracee_http_method_prefix_detect_xdp+0x161> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_1, 0, (111) - 1, 72),
    /* 0x11bd: cmp    edi,0x50 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11c0: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_1, 0, (221) - 1, 80),
    /* 0x11c6: cmp    r9d,0x55 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11ca: je     1293 <tracee_http_method_prefix_detect_xdp+0x193> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 85),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (153) - 1),
    /* 0x11d0: cmp    r9d,0x4f [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11d4: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 79),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (205) - 1),
    /* 0x11da: mov    r8b,0x4f [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11dd: cmp    BYTE PTR [rax-0x4],0x53 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11e1: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 83),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (195) - 1),
    /* 0x11e7: cmp    BYTE PTR [rax-0x3],0x54 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11eb: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 84),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (187) - 1),
    /* 0x11f1: mov    r10b,0x4f [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 79), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11f4: cmp    BYTE PTR [rax-0x2],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11f8: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (177) - 1),
    /* 0x11fe: mov    r9d,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1204: mov    r8b,0x53 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 83), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1207: mov    r11b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x120a: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (178) - 1),
    /* 0x120f: cmp    r8b,0x45 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1213: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_5),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 69),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (163) - 1),
    /* 0x1219: mov    r8b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x121c: cmp    BYTE PTR [rax-0x4],0x4c [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1220: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 76),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (153) - 1),
    /* 0x1226: cmp    BYTE PTR [rax-0x3],0x45 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x122a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 69),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (145) - 1),
    /* 0x1230: cmp    BYTE PTR [rax-0x2],0x54 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1234: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 84),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (137) - 1),
    /* 0x123a: cmp    BYTE PTR [rax-0x1],0x45 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x123e: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -1),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 69),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (129) - 1),
    /* 0x1244: mov    r11b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1247: cmp    BYTE PTR [rax],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x124a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, 0),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (119) - 1),
    /* 0x1250: mov    r9d,0x4 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1256: mov    r8b,0x4c [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 76), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1259: mov    r10b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x125c: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (120) - 1),
    /* 0x1261: cmp    r9d,0x54 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1265: je     12b3 <tracee_http_method_prefix_detect_xdp+0x1b3> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 84),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (71) - 1),
    /* 0x1267: cmp    r9d,0x45 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x126b: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 69),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (96) - 1),
    /* 0x126d: mov    r8b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1270: cmp    BYTE PTR [rax-0x4],0x41 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1274: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 65),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (86) - 1),
    /* 0x1276: cmp    BYTE PTR [rax-0x3],0x44 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x127a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 68),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (78) - 1),
    /* 0x127c: mov    r10b,0x45 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 69), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x127f: cmp    BYTE PTR [rax-0x2],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1283: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (68) - 1),
    /* 0x1285: mov    r9d,0x5 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x128b: mov    r8b,0x41 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 65), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x128e: mov    r11b,0x44 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 68), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1291: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (69) - 1),
    /* 0x1293: mov    r8b,0x55 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1296: cmp    BYTE PTR [rax-0x4],0x54 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x129a: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 84),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (51) - 1),
    /* 0x129c: mov    r10b,0x55 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 85), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x129f: cmp    BYTE PTR [rax-0x3],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12a3: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (41) - 1),
    /* 0x12a5: mov    r9d,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ab: mov    r8b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12ae: mov    r11b,0x20 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12b1: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (42) - 1),
    /* 0x12b3: mov    r8b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12b6: cmp    BYTE PTR [rax-0x4],0x54 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12ba: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 84),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (24) - 1),
    /* 0x12bc: cmp    BYTE PTR [rax-0x3],0x50 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12c0: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 80),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (16) - 1),
    /* 0x12c2: cmp    BYTE PTR [rax-0x2],0x2f [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12c6: jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_0, -2),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 47),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (8) - 1),
    /* 0x12c8: mov    r9d,0x6 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ce: mov    r11b,0x50 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 80), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12d1: mov    r10b,0x54 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 84), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12d4: jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (9) - 1),
    /* 0x12d6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x12e0: mov    r10d,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12e3: movzx  r8d,BYTE PTR [rax-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_0, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e8: movzx  r11d,BYTE PTR [rax-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ed: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12f0: movzx  r11d,r11b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f4: lea    ebx,[r9+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_6, HC_X86_R9, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12f8: lea    r14,[rcx+0xa] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_4, 0, 0, 1, 0, 10), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12fc: imul   rbx,r14 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1300: add    rsi,rbx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1303: shl    r11,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1307: movzx  r8d,r8b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x130b: shl    r8d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130f: movzx  r10d,r10b [exact-kinsn: movzx r32,r8 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1313: shl    r10d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1317: shl    edi,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x131a: or     edi,r10d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x131d: or     edi,r8d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1320: or     rdi,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1323: mov    ebx,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1326: or     rbx,rdi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1329: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x132c: xor    rbx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132f: add    rax,0x10 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1333: inc    rcx [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1336: cmp    rcx,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x133a: jne    1150 <tracee_http_method_prefix_detect_xdp+0x50> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, (-311) - 1, 9),
    /* 0x1340: mov    BYTE PTR [rdx],sil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1343: mov    BYTE PTR [rdx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_6, BPF_REG_3, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1346: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1348: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x134b: mov    BYTE PTR [rdx+0x2],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x134e: mov    eax,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1350: shr    eax,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1353: mov    BYTE PTR [rdx+0x3],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1356: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1359: shr    rax,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x135d: mov    BYTE PTR [rdx+0x4],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1360: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1363: shr    rax,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1367: mov    BYTE PTR [rdx+0x5],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x136a: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x136d: shr    rax,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1371: mov    BYTE PTR [rdx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1374: shr    rbx,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1378: mov    BYTE PTR [rdx+0x7],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x137b: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1380: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1381: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1383: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
