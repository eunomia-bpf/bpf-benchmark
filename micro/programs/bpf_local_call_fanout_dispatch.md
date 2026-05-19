# bpf_local_call_fanout_dispatch

## Original C
```c
#include "common.h"

#define LOCAL_CALL_FANOUT_RECORDS 16U
#define LOCAL_CALL_FANOUT_RECORD_SIZE 24U
#define LOCAL_CALL_FANOUT_INPUT_SIZE (8U + LOCAL_CALL_FANOUT_RECORDS * LOCAL_CALL_FANOUT_RECORD_SIZE)

static __noinline u64 local_call_linear(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u64 left = micro_read_u64_le(data, offset + 8U);
    u64 right = micro_read_u64_le(data, offset + 16U);
    u64 mixed = acc + left * 3U + right + tag;
    mixed ^= micro_rotl64(mixed + ((u64)tag << 11U), (tag & 7U) + 1U);
    return mixed + (left >> 3U);
}

static __noinline u64 local_call_pressure(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u64 a = micro_read_u64_le(data, offset + 8U);
    u64 b = micro_read_u64_le(data, offset + 16U);
    u64 c = acc ^ a;
    u64 d = b + ((u64)tag << 17U);
    u64 e = (c << 3U) ^ (b >> 2U);
    u64 f = micro_rotl64(d ^ a, 5U);
    u64 g = micro_rotl64(e + c, 11U);
    u64 h = (f + g) ^ (d >> 7U);
    return (h + e) ^ c ^ d;
}

static __noinline u64 local_call_crossload(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u32 selector = micro_read_u32_le(data, offset);
    u32 record_tag = micro_read_u32_le(data, offset + 4U);
    u64 left = micro_read_u64_le(data, offset + 8U);
    u64 right = micro_read_u64_le(data, offset + 16U);
    u64 lane0 = acc + left;
    u64 lane1 = micro_rotl64(right ^ lane0, (selector & 7U) + 1U);
    u64 lane2 = lane0 ^ lane1 ^ ((u64)record_tag << 9U);
    u64 lane3 = lane2 + ((u64)tag << (selector & 7U));
    return (lane3 ^ (lane1 >> 5U)) + lane0;
}

static __noinline u64 local_call_bytes(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u64 mixed = acc ^ 0x94D049BB133111EBULL;
    for (u32 index = 0; index < 8U; index++) {
        mixed ^= (u64)data[offset + index] << ((index & 7U) * 8U);
        mixed = micro_rotl64(mixed + tag + index, index + 1U);
    }
    mixed += micro_read_u64_le(data, offset + 8U);
    mixed ^= micro_read_u64_le(data, offset + 16U);
    return mixed;
}

static __always_inline int bench_bpf_local_call_fanout_dispatch(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0);
    u32 record_size = micro_read_u32_le(data, 4);
    if (record_count != LOCAL_CALL_FANOUT_RECORDS || record_size != LOCAL_CALL_FANOUT_RECORD_SIZE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, LOCAL_CALL_FANOUT_RECORDS * LOCAL_CALL_FANOUT_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0x243F6A8885A308D3ULL;
    for (u32 index = 0; index < LOCAL_CALL_FANOUT_RECORDS; index++) {
        u32 offset = 8U + index * LOCAL_CALL_FANOUT_RECORD_SIZE;
        u32 selector = micro_read_u32_le(data, offset) & 3U;
        u32 tag = micro_read_u32_le(data, offset + 4U) ^ (index << 4U);

        switch (selector) {
        case 0U:
            acc = local_call_linear(acc, data, offset, tag);
            break;
        case 1U:
            acc = local_call_pressure(acc, data, offset, tag);
            break;
        case 2U:
            acc = local_call_crossload(acc, data, offset, tag);
            break;
        default:
            acc = local_call_bytes(acc, data, offset, tag);
            break;
        }

        acc ^= ((u64)selector << ((index & 7U) * 8U)) + tag;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bpf_local_call_fanout_dispatch_xdp,
    bench_bpf_local_call_fanout_dispatch,
    bpf_local_call_fanout_dispatch_input_value,
    LOCAL_CALL_FANOUT_INPUT_SIZE)
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

0000000000001100 <bpf_local_call_fanout_dispatch_xdp>:
    1100:	55                   	push   rbp
    1101:	41 57                	push   r15
    1103:	41 56                	push   r14
    1105:	41 55                	push   r13
    1107:	41 54                	push   r12
    1109:	53                   	push   rbx
    110a:	50                   	push   rax
    110b:	4c 8b 37             	mov    r14,QWORD PTR [rdi]
    110e:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1112:	31 c0                	xor    eax,eax
    1114:	49 39 ce             	cmp    r14,rcx
    1117:	76 0f                	jbe    1128 <bpf_local_call_fanout_dispatch_xdp+0x28>
    1119:	48 83 c4 08          	add    rsp,0x8
    111d:	5b                   	pop    rbx
    111e:	41 5c                	pop    r12
    1120:	41 5d                	pop    r13
    1122:	41 5e                	pop    r14
    1124:	41 5f                	pop    r15
    1126:	5d                   	pop    rbp
    1127:	c3                   	ret
    1128:	49 8d 56 08          	lea    rdx,[r14+0x8]
    112c:	48 89 14 24          	mov    QWORD PTR [rsp],rdx
    1130:	48 39 ca             	cmp    rdx,rcx
    1133:	77 e4                	ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19>
    1135:	49 8d 96 90 01 00 00 	lea    rdx,[r14+0x190]
    113c:	48 39 ca             	cmp    rdx,rcx
    113f:	77 d8                	ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19>
    1141:	41 83 7e 08 10       	cmp    DWORD PTR [r14+0x8],0x10
    1146:	75 d1                	jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19>
    1148:	41 83 7e 0c 18       	cmp    DWORD PTR [r14+0xc],0x18
    114d:	75 ca                	jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19>
    114f:	48 bf d3 08 a3 85 88 	movabs rdi,0x243f6a8885a308d3
    1156:	6a 3f 24 
    1159:	45 31 ff             	xor    r15d,r15d
    115c:	41 bc 17 00 00 00    	mov    r12d,0x17
    1162:	45 31 ed             	xor    r13d,r13d
    1165:	eb 3a                	jmp    11a1 <bpf_local_call_fanout_dispatch_xdp+0xa1>
    1167:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    116e:	00 00 
    1170:	48 8b 34 24          	mov    rsi,QWORD PTR [rsp]
    1174:	89 e9                	mov    ecx,ebp
    1176:	e8 e5 00 00 00       	call   1260 <local_call_pressure>
    117b:	44 89 e9             	mov    ecx,r13d
    117e:	80 e1 38             	and    cl,0x38
    1181:	48 d3 e3             	shl    rbx,cl
    1184:	89 ef                	mov    edi,ebp
    1186:	48 01 df             	add    rdi,rbx
    1189:	48 31 c7             	xor    rdi,rax
    118c:	49 83 c5 08          	add    r13,0x8
    1190:	41 83 c7 10          	add    r15d,0x10
    1194:	49 83 c4 18          	add    r12,0x18
    1198:	49 81 fd 80 00 00 00 	cmp    r13,0x80
    119f:	74 5f                	je     1200 <bpf_local_call_fanout_dispatch_xdp+0x100>
    11a1:	43 0f b6 5c 26 f9    	movzx  ebx,BYTE PTR [r14+r12*1-0x7]
    11a7:	83 e3 03             	and    ebx,0x3
    11aa:	43 8b 6c 26 fd       	mov    ebp,DWORD PTR [r14+r12*1-0x3]
    11af:	44 31 fd             	xor    ebp,r15d
    11b2:	49 8d 54 24 f1       	lea    rdx,[r12-0xf]
    11b7:	48 83 fb 02          	cmp    rbx,0x2
    11bb:	74 23                	je     11e0 <bpf_local_call_fanout_dispatch_xdp+0xe0>
    11bd:	83 fb 01             	cmp    ebx,0x1
    11c0:	74 ae                	je     1170 <bpf_local_call_fanout_dispatch_xdp+0x70>
    11c2:	85 db                	test   ebx,ebx
    11c4:	75 2a                	jne    11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0>
    11c6:	48 8b 34 24          	mov    rsi,QWORD PTR [rsp]
    11ca:	89 e9                	mov    ecx,ebp
    11cc:	e8 3f 00 00 00       	call   1210 <local_call_linear>
    11d1:	eb a8                	jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b>
    11d3:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11da:	84 00 00 00 00 00 
    11e0:	48 8b 34 24          	mov    rsi,QWORD PTR [rsp]
    11e4:	89 e9                	mov    ecx,ebp
    11e6:	e8 c5 00 00 00       	call   12b0 <local_call_crossload>
    11eb:	eb 8e                	jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b>
    11ed:	0f 1f 00             	nop    DWORD PTR [rax]
    11f0:	48 8b 34 24          	mov    rsi,QWORD PTR [rsp]
    11f4:	89 e9                	mov    ecx,ebp
    11f6:	e8 45 01 00 00       	call   1340 <local_call_bytes>
    11fb:	e9 7b ff ff ff       	jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b>
    1200:	49 89 3e             	mov    QWORD PTR [r14],rdi
    1203:	b8 02 00 00 00       	mov    eax,0x2
    1208:	e9 0c ff ff ff       	jmp    1119 <bpf_local_call_fanout_dispatch_xdp+0x19>
    120d:	0f 1f 00             	nop    DWORD PTR [rax]

0000000000001210 <local_call_linear>:
    1210:	41 89 c8             	mov    r8d,ecx
    1213:	89 d1                	mov    ecx,edx
    1215:	48 8b 44 31 08       	mov    rax,QWORD PTR [rcx+rsi*1+0x8]
    121a:	4c 8d 0c 40          	lea    r9,[rax+rax*2]
    121e:	44 89 c2             	mov    edx,r8d
    1221:	48 01 d7             	add    rdi,rdx
    1224:	49 01 f9             	add    r9,rdi
    1227:	4c 03 4c 31 10       	add    r9,QWORD PTR [rcx+rsi*1+0x10]
    122c:	48 c1 e2 0b          	shl    rdx,0xb
    1230:	4c 01 ca             	add    rdx,r9
    1233:	41 83 e0 07          	and    r8d,0x7
    1237:	41 8d 48 01          	lea    ecx,[r8+0x1]
    123b:	48 89 d6             	mov    rsi,rdx
    123e:	48 d3 e6             	shl    rsi,cl
    1241:	41 f6 d0             	not    r8b
    1244:	44 89 c1             	mov    ecx,r8d
    1247:	48 d3 ea             	shr    rdx,cl
    124a:	48 09 f2             	or     rdx,rsi
    124d:	4c 31 ca             	xor    rdx,r9
    1250:	48 c1 e8 03          	shr    rax,0x3
    1254:	48 01 d0             	add    rax,rdx
    1257:	c3                   	ret
    1258:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    125f:	00 

0000000000001260 <local_call_pressure>:
    1260:	89 d0                	mov    eax,edx
    1262:	4c 8b 44 30 08       	mov    r8,QWORD PTR [rax+rsi*1+0x8]
    1267:	48 8b 54 30 10       	mov    rdx,QWORD PTR [rax+rsi*1+0x10]
    126c:	4c 31 c7             	xor    rdi,r8
    126f:	89 c8                	mov    eax,ecx
    1271:	48 c1 e0 11          	shl    rax,0x11
    1275:	48 01 d0             	add    rax,rdx
    1278:	48 8d 0c fd 00 00 00 	lea    rcx,[rdi*8+0x0]
    127f:	00 
    1280:	48 c1 ea 02          	shr    rdx,0x2
    1284:	49 31 c0             	xor    r8,rax
    1287:	49 c1 c0 05          	rol    r8,0x5
    128b:	48 31 ca             	xor    rdx,rcx
    128e:	48 8d 0c 3a          	lea    rcx,[rdx+rdi*1]
    1292:	48 c1 c1 0b          	rol    rcx,0xb
    1296:	4c 01 c1             	add    rcx,r8
    1299:	48 31 c7             	xor    rdi,rax
    129c:	48 c1 e8 07          	shr    rax,0x7
    12a0:	48 31 c8             	xor    rax,rcx
    12a3:	48 01 d0             	add    rax,rdx
    12a6:	48 31 f8             	xor    rax,rdi
    12a9:	c3                   	ret
    12aa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000000012b0 <local_call_crossload>:
    12b0:	41 56                	push   r14
    12b2:	53                   	push   rbx
    12b3:	41 89 c8             	mov    r8d,ecx
    12b6:	89 d0                	mov    eax,edx
    12b8:	0f b6 14 06          	movzx  edx,BYTE PTR [rsi+rax*1]
    12bc:	48 8d 48 04          	lea    rcx,[rax+0x4]
    12c0:	44 0f b6 4c 06 04    	movzx  r9d,BYTE PTR [rsi+rax*1+0x4]
    12c6:	4c 63 d9             	movsxd r11,ecx
    12c9:	46 0f b6 54 1e 01    	movzx  r10d,BYTE PTR [rsi+r11*1+0x1]
    12cf:	48 03 7c 06 08       	add    rdi,QWORD PTR [rsi+rax*1+0x8]
    12d4:	48 8b 44 06 10       	mov    rax,QWORD PTR [rsi+rax*1+0x10]
    12d9:	48 31 f8             	xor    rax,rdi
    12dc:	80 e2 07             	and    dl,0x7
    12df:	8d 4a 01             	lea    ecx,[rdx+0x1]
    12e2:	48 89 c3             	mov    rbx,rax
    12e5:	48 d3 e3             	shl    rbx,cl
    12e8:	46 0f b6 74 1e 02    	movzx  r14d,BYTE PTR [rsi+r11*1+0x2]
    12ee:	42 0f b6 74 1e 03    	movzx  esi,BYTE PTR [rsi+r11*1+0x3]
    12f4:	89 d1                	mov    ecx,edx
    12f6:	f6 d1                	not    cl
    12f8:	48 d3 e8             	shr    rax,cl
    12fb:	48 09 d8             	or     rax,rbx
    12fe:	48 c1 e6 21          	shl    rsi,0x21
    1302:	49 c1 e6 19          	shl    r14,0x19
    1306:	41 c1 e2 11          	shl    r10d,0x11
    130a:	41 c1 e1 09          	shl    r9d,0x9
    130e:	45 09 d1             	or     r9d,r10d
    1311:	4d 09 f1             	or     r9,r14
    1314:	49 09 f1             	or     r9,rsi
    1317:	49 31 f9             	xor    r9,rdi
    131a:	49 31 c1             	xor    r9,rax
    131d:	44 89 c6             	mov    esi,r8d
    1320:	89 d1                	mov    ecx,edx
    1322:	48 d3 e6             	shl    rsi,cl
    1325:	4c 01 ce             	add    rsi,r9
    1328:	48 c1 e8 05          	shr    rax,0x5
    132c:	48 31 f0             	xor    rax,rsi
    132f:	48 01 f8             	add    rax,rdi
    1332:	5b                   	pop    rbx
    1333:	41 5e                	pop    r14
    1335:	c3                   	ret
    1336:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    133d:	00 00 00 

0000000000001340 <local_call_bytes>:
    1340:	89 c8                	mov    eax,ecx
    1342:	89 d1                	mov    ecx,edx
    1344:	0f b6 14 0e          	movzx  edx,BYTE PTR [rsi+rcx*1]
    1348:	49 b8 eb 11 31 13 bb 	movabs r8,0x94d049bb133111eb
    134f:	49 d0 94 
    1352:	49 31 f8             	xor    r8,rdi
    1355:	49 31 d0             	xor    r8,rdx
    1358:	49 01 c0             	add    r8,rax
    135b:	49 d1 c0             	rol    r8,1
    135e:	0f b6 54 0e 01       	movzx  edx,BYTE PTR [rsi+rcx*1+0x1]
    1363:	c1 e2 08             	shl    edx,0x8
    1366:	4c 31 c2             	xor    rdx,r8
    1369:	48 01 c2             	add    rdx,rax
    136c:	48 ff c2             	inc    rdx
    136f:	48 c1 c2 02          	rol    rdx,0x2
    1373:	0f b6 7c 0e 02       	movzx  edi,BYTE PTR [rsi+rcx*1+0x2]
    1378:	c1 e7 10             	shl    edi,0x10
    137b:	48 31 d7             	xor    rdi,rdx
    137e:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    1382:	48 83 c2 02          	add    rdx,0x2
    1386:	48 c1 c2 03          	rol    rdx,0x3
    138a:	0f b6 7c 0e 03       	movzx  edi,BYTE PTR [rsi+rcx*1+0x3]
    138f:	c1 e7 18             	shl    edi,0x18
    1392:	48 31 d7             	xor    rdi,rdx
    1395:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    1399:	48 83 c2 03          	add    rdx,0x3
    139d:	48 c1 c2 04          	rol    rdx,0x4
    13a1:	0f b6 7c 0e 04       	movzx  edi,BYTE PTR [rsi+rcx*1+0x4]
    13a6:	48 c1 e7 20          	shl    rdi,0x20
    13aa:	48 31 d7             	xor    rdi,rdx
    13ad:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    13b1:	48 83 c2 04          	add    rdx,0x4
    13b5:	48 c1 c2 05          	rol    rdx,0x5
    13b9:	0f b6 7c 0e 05       	movzx  edi,BYTE PTR [rsi+rcx*1+0x5]
    13be:	48 c1 e7 28          	shl    rdi,0x28
    13c2:	48 31 d7             	xor    rdi,rdx
    13c5:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    13c9:	48 83 c2 05          	add    rdx,0x5
    13cd:	48 c1 c2 06          	rol    rdx,0x6
    13d1:	0f b6 7c 0e 06       	movzx  edi,BYTE PTR [rsi+rcx*1+0x6]
    13d6:	48 c1 e7 30          	shl    rdi,0x30
    13da:	48 31 d7             	xor    rdi,rdx
    13dd:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    13e1:	48 83 c2 06          	add    rdx,0x6
    13e5:	48 c1 c2 07          	rol    rdx,0x7
    13e9:	0f b6 7c 0e 07       	movzx  edi,BYTE PTR [rsi+rcx*1+0x7]
    13ee:	48 c1 e7 38          	shl    rdi,0x38
    13f2:	48 31 d7             	xor    rdi,rdx
    13f5:	48 01 f8             	add    rax,rdi
    13f8:	48 83 c0 07          	add    rax,0x7
    13fc:	48 c1 c0 08          	rol    rax,0x8
    1400:	48 03 44 0e 08       	add    rax,QWORD PTR [rsi+rcx*1+0x8]
    1405:	48 33 44 0e 10       	xor    rax,QWORD PTR [rsi+rcx*1+0x10]
    140a:	c3                   	ret

Disassembly of section .fini:

000000000000140c <_fini>:
    140c:	f3 0f 1e fa          	endbr64
    1410:	48 83 ec 08          	sub    rsp,0x8
    1414:	48 83 c4 08          	add    rsp,0x8
    1418:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 18 00 00 00 	sub    rsp,0x18
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 b8 01 00 00    	ja     0x1e5
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  38:	48 39 f7             	cmp    rdi,rsi
  3b:	0f 87 a4 01 00 00    	ja     0x1e5
  41:	48 89 d7             	mov    rdi,rdx
  44:	48 81 c7 90 01 00 00 	add    rdi,0x190
  4b:	48 39 f7             	cmp    rdi,rsi
  4e:	0f 87 91 01 00 00    	ja     0x1e5
  54:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  59:	c1 e7 08             	shl    edi,0x8
  5c:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  61:	09 f7                	or     edi,esi
  63:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  68:	c1 e6 10             	shl    esi,0x10
  6b:	09 f7                	or     edi,esi
  6d:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  72:	c1 e6 18             	shl    esi,0x18
  75:	09 f7                	or     edi,esi
  77:	83 ff 10             	cmp    edi,0x10
  7a:	0f 85 65 01 00 00    	jne    0x1e5
  80:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  85:	c1 e7 08             	shl    edi,0x8
  88:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  8d:	09 f7                	or     edi,esi
  8f:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  94:	c1 e6 10             	shl    esi,0x10
  97:	09 f7                	or     edi,esi
  99:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  9e:	c1 e6 18             	shl    esi,0x18
  a1:	09 f7                	or     edi,esi
  a3:	83 ff 18             	cmp    edi,0x18
  a6:	0f 85 39 01 00 00    	jne    0x1e5
  ac:	48 b8 d3 08 a3 85 88 	movabs rax,0x243f6a8885a308d3
  b3:	6a 3f 24 
  b6:	45 31 ff             	xor    r15d,r15d
  b9:	31 c9                	xor    ecx,ecx
  bb:	45 31 f6             	xor    r14d,r14d
  be:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
  c2:	eb 40                	jmp    0x104
  c4:	48 89 c7             	mov    rdi,rax
  c7:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
  cb:	44 89 e9             	mov    ecx,r13d
  ce:	e8 61 01 00 00       	call   0x234
  d3:	4c 89 ff             	mov    rdi,r15
  d6:	48 83 e7 38          	and    rdi,0x38
  da:	c4 e2 c1 f7 db       	shlx   rbx,rbx,rdi
  df:	4c 01 eb             	add    rbx,r13
  e2:	48 31 d8             	xor    rax,rbx
  e5:	8b 4d f8             	mov    ecx,DWORD PTR [rbp-0x8]
  e8:	83 c1 10             	add    ecx,0x10
  eb:	49 83 c7 08          	add    r15,0x8
  ef:	49 83 c6 18          	add    r14,0x18
  f3:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  f7:	49 81 fe 80 01 00 00 	cmp    r14,0x180
  fe:	0f 84 90 00 00 00    	je     0x194
 104:	48 89 d7             	mov    rdi,rdx
 107:	4c 01 f7             	add    rdi,r14
 10a:	4c 0f b6 6f 15       	movzx  r13,BYTE PTR [rdi+0x15]
 10f:	41 c1 e5 08          	shl    r13d,0x8
 113:	48 0f b6 77 14       	movzx  rsi,BYTE PTR [rdi+0x14]
 118:	41 09 f5             	or     r13d,esi
 11b:	48 0f b6 77 16       	movzx  rsi,BYTE PTR [rdi+0x16]
 120:	c1 e6 10             	shl    esi,0x10
 123:	41 09 f5             	or     r13d,esi
 126:	48 0f b6 77 17       	movzx  rsi,BYTE PTR [rdi+0x17]
 12b:	c1 e6 18             	shl    esi,0x18
 12e:	41 09 f5             	or     r13d,esi
 131:	41 31 cd             	xor    r13d,ecx
 134:	4c 89 f2             	mov    rdx,r14
 137:	48 83 c2 08          	add    rdx,0x8
 13b:	48 0f b6 5f 10       	movzx  rbx,BYTE PTR [rdi+0x10]
 140:	83 e3 03             	and    ebx,0x3
 143:	89 4d f8             	mov    DWORD PTR [rbp-0x8],ecx
 146:	83 fb 02             	cmp    ebx,0x2
 149:	74 21                	je     0x16c
 14b:	83 fb 01             	cmp    ebx,0x1
 14e:	0f 84 70 ff ff ff    	je     0xc4
 154:	85 db                	test   ebx,ebx
 156:	75 28                	jne    0x180
 158:	48 89 c7             	mov    rdi,rax
 15b:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 15f:	44 89 e9             	mov    ecx,r13d
 162:	e8 55 02 00 00       	call   0x3bc
 167:	e9 67 ff ff ff       	jmp    0xd3
 16c:	48 89 c7             	mov    rdi,rax
 16f:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 173:	44 89 e9             	mov    ecx,r13d
 176:	e8 a5 03 00 00       	call   0x520
 17b:	e9 53 ff ff ff       	jmp    0xd3
 180:	48 89 c7             	mov    rdi,rax
 183:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 187:	44 89 e9             	mov    ecx,r13d
 18a:	e8 29 05 00 00       	call   0x6b8
 18f:	e9 3f ff ff ff       	jmp    0xd3
 194:	88 42 00             	mov    BYTE PTR [rdx+0x0],al
 197:	48 89 c7             	mov    rdi,rax
 19a:	48 c1 ef 38          	shr    rdi,0x38
 19e:	40 88 7a 07          	mov    BYTE PTR [rdx+0x7],dil
 1a2:	48 89 c7             	mov    rdi,rax
 1a5:	48 c1 ef 30          	shr    rdi,0x30
 1a9:	40 88 7a 06          	mov    BYTE PTR [rdx+0x6],dil
 1ad:	48 89 c7             	mov    rdi,rax
 1b0:	48 c1 ef 28          	shr    rdi,0x28
 1b4:	40 88 7a 05          	mov    BYTE PTR [rdx+0x5],dil
 1b8:	48 89 c7             	mov    rdi,rax
 1bb:	48 c1 ef 20          	shr    rdi,0x20
 1bf:	40 88 7a 04          	mov    BYTE PTR [rdx+0x4],dil
 1c3:	48 89 c7             	mov    rdi,rax
 1c6:	48 c1 ef 18          	shr    rdi,0x18
 1ca:	40 88 7a 03          	mov    BYTE PTR [rdx+0x3],dil
 1ce:	48 89 c7             	mov    rdi,rax
 1d1:	48 c1 ef 10          	shr    rdi,0x10
 1d5:	40 88 7a 02          	mov    BYTE PTR [rdx+0x2],dil
 1d9:	48 c1 e8 08          	shr    rax,0x8
 1dd:	88 42 01             	mov    BYTE PTR [rdx+0x1],al
 1e0:	b8 02 00 00 00       	mov    eax,0x2
 1e5:	41 5f                	pop    r15
 1e7:	41 5e                	pop    r14
 1e9:	41 5d                	pop    r13
 1eb:	5b                   	pop    rbx
 1ec:	c9                   	leave
 1ed:	c3                   	ret
 1ee:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 1f3:	0f 1f 00             	nop    DWORD PTR [rax]
 1f6:	55                   	push   rbp
 1f7:	48 89 e5             	mov    rbp,rsp
 1fa:	53                   	push   rbx
 1fb:	89 d0                	mov    eax,edx
 1fd:	83 c0 08             	add    eax,0x8
 200:	83 c2 10             	add    edx,0x10
 203:	49 89 f0             	mov    r8,rsi
 206:	49 01 d0             	add    r8,rdx
 209:	48 01 c6             	add    rsi,rax
 20c:	48 0f b6 56 00       	movzx  rdx,BYTE PTR [rsi+0x0]
 211:	48 0f b6 46 01       	movzx  rax,BYTE PTR [rsi+0x1]
 216:	48 c1 e0 08          	shl    rax,0x8
 21a:	48 09 d0             	or     rax,rdx
 21d:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 222:	49 0f b6 50 01       	movzx  rdx,BYTE PTR [r8+0x1]
 227:	48 c1 e2 08          	shl    rdx,0x8
 22b:	48 09 da             	or     rdx,rbx
 22e:	48 0f b6 5e 02       	movzx  rbx,BYTE PTR [rsi+0x2]
 233:	48 c1 e3 10          	shl    rbx,0x10
 237:	48 09 c3             	or     rbx,rax
 23a:	48 0f b6 46 03       	movzx  rax,BYTE PTR [rsi+0x3]
 23f:	48 c1 e0 18          	shl    rax,0x18
 243:	48 09 d8             	or     rax,rbx
 246:	49 0f b6 58 02       	movzx  rbx,BYTE PTR [r8+0x2]
 24b:	48 c1 e3 10          	shl    rbx,0x10
 24f:	48 09 d3             	or     rbx,rdx
 252:	49 0f b6 50 03       	movzx  rdx,BYTE PTR [r8+0x3]
 257:	48 c1 e2 18          	shl    rdx,0x18
 25b:	48 09 da             	or     rdx,rbx
 25e:	48 0f b6 5e 04       	movzx  rbx,BYTE PTR [rsi+0x4]
 263:	48 c1 e3 20          	shl    rbx,0x20
 267:	48 09 c3             	or     rbx,rax
 26a:	48 0f b6 46 05       	movzx  rax,BYTE PTR [rsi+0x5]
 26f:	48 c1 e0 28          	shl    rax,0x28
 273:	48 09 d8             	or     rax,rbx
 276:	49 0f b6 58 04       	movzx  rbx,BYTE PTR [r8+0x4]
 27b:	48 c1 e3 20          	shl    rbx,0x20
 27f:	48 09 d3             	or     rbx,rdx
 282:	49 0f b6 50 05       	movzx  rdx,BYTE PTR [r8+0x5]
 287:	48 c1 e2 28          	shl    rdx,0x28
 28b:	48 09 da             	or     rdx,rbx
 28e:	48 0f b6 5e 06       	movzx  rbx,BYTE PTR [rsi+0x6]
 293:	48 c1 e3 30          	shl    rbx,0x30
 297:	48 09 c3             	or     rbx,rax
 29a:	48 0f b6 46 07       	movzx  rax,BYTE PTR [rsi+0x7]
 29f:	48 c1 e0 38          	shl    rax,0x38
 2a3:	48 09 d8             	or     rax,rbx
 2a6:	49 0f b6 58 06       	movzx  rbx,BYTE PTR [r8+0x6]
 2ab:	48 c1 e3 30          	shl    rbx,0x30
 2af:	48 09 d3             	or     rbx,rdx
 2b2:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 2b7:	48 c1 e6 38          	shl    rsi,0x38
 2bb:	48 09 de             	or     rsi,rbx
 2be:	89 c9                	mov    ecx,ecx
 2c0:	48 c1 e1 11          	shl    rcx,0x11
 2c4:	48 89 f2             	mov    rdx,rsi
 2c7:	48 01 ca             	add    rdx,rcx
 2ca:	48 89 d1             	mov    rcx,rdx
 2cd:	48 31 c1             	xor    rcx,rax
 2d0:	49 89 c8             	mov    r8,rcx
 2d3:	49 c1 e8 3b          	shr    r8,0x3b
 2d7:	48 c1 e1 05          	shl    rcx,0x5
 2db:	4c 09 c1             	or     rcx,r8
 2de:	48 31 f8             	xor    rax,rdi
 2e1:	48 c1 ee 02          	shr    rsi,0x2
 2e5:	48 89 c7             	mov    rdi,rax
 2e8:	48 c1 e7 03          	shl    rdi,0x3
 2ec:	48 31 fe             	xor    rsi,rdi
 2ef:	48 89 f7             	mov    rdi,rsi
 2f2:	48 01 c7             	add    rdi,rax
 2f5:	49 89 f8             	mov    r8,rdi
 2f8:	49 c1 e8 35          	shr    r8,0x35
 2fc:	48 c1 e7 0b          	shl    rdi,0xb
 300:	4c 09 c7             	or     rdi,r8
 303:	48 01 cf             	add    rdi,rcx
 306:	48 89 d1             	mov    rcx,rdx
 309:	48 c1 e9 07          	shr    rcx,0x7
 30d:	48 31 cf             	xor    rdi,rcx
 310:	48 01 f7             	add    rdi,rsi
 313:	48 31 f8             	xor    rax,rdi
 316:	48 31 d0             	xor    rax,rdx
 319:	5b                   	pop    rbx
 31a:	c9                   	leave
 31b:	c3                   	ret
 31c:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 321:	0f 1f 00             	nop    DWORD PTR [rax]
 324:	55                   	push   rbp
 325:	48 89 e5             	mov    rbp,rsp
 328:	53                   	push   rbx
 329:	41 55                	push   r13
 32b:	89 d0                	mov    eax,edx
 32d:	83 c0 10             	add    eax,0x10
 330:	83 c2 08             	add    edx,0x8
 333:	49 89 f0             	mov    r8,rsi
 336:	49 01 d0             	add    r8,rdx
 339:	48 01 c6             	add    rsi,rax
 33c:	48 0f b6 46 00       	movzx  rax,BYTE PTR [rsi+0x0]
 341:	48 0f b6 56 01       	movzx  rdx,BYTE PTR [rsi+0x1]
 346:	48 c1 e2 08          	shl    rdx,0x8
 34a:	48 09 c2             	or     rdx,rax
 34d:	49 0f b6 40 00       	movzx  rax,BYTE PTR [r8+0x0]
 352:	49 0f b6 58 01       	movzx  rbx,BYTE PTR [r8+0x1]
 357:	48 c1 e3 08          	shl    rbx,0x8
 35b:	48 09 c3             	or     rbx,rax
 35e:	49 0f b6 40 02       	movzx  rax,BYTE PTR [r8+0x2]
 363:	48 c1 e0 10          	shl    rax,0x10
 367:	48 09 d8             	or     rax,rbx
 36a:	48 0f b6 5e 02       	movzx  rbx,BYTE PTR [rsi+0x2]
 36f:	48 c1 e3 10          	shl    rbx,0x10
 373:	48 09 d3             	or     rbx,rdx
 376:	48 0f b6 56 03       	movzx  rdx,BYTE PTR [rsi+0x3]
 37b:	48 c1 e2 18          	shl    rdx,0x18
 37f:	48 09 da             	or     rdx,rbx
 382:	49 0f b6 58 03       	movzx  rbx,BYTE PTR [r8+0x3]
 387:	48 c1 e3 18          	shl    rbx,0x18
 38b:	48 09 c3             	or     rbx,rax
 38e:	49 0f b6 40 04       	movzx  rax,BYTE PTR [r8+0x4]
 393:	48 c1 e0 20          	shl    rax,0x20
 397:	48 09 d8             	or     rax,rbx
 39a:	48 0f b6 5e 04       	movzx  rbx,BYTE PTR [rsi+0x4]
 39f:	48 c1 e3 20          	shl    rbx,0x20
 3a3:	48 09 d3             	or     rbx,rdx
 3a6:	48 0f b6 56 05       	movzx  rdx,BYTE PTR [rsi+0x5]
 3ab:	48 c1 e2 28          	shl    rdx,0x28
 3af:	48 09 da             	or     rdx,rbx
 3b2:	49 0f b6 58 05       	movzx  rbx,BYTE PTR [r8+0x5]
 3b7:	48 c1 e3 28          	shl    rbx,0x28
 3bb:	48 09 c3             	or     rbx,rax
 3be:	49 0f b6 40 06       	movzx  rax,BYTE PTR [r8+0x6]
 3c3:	48 c1 e0 30          	shl    rax,0x30
 3c7:	48 09 d8             	or     rax,rbx
 3ca:	48 0f b6 5e 06       	movzx  rbx,BYTE PTR [rsi+0x6]
 3cf:	48 c1 e3 30          	shl    rbx,0x30
 3d3:	48 09 d3             	or     rbx,rdx
 3d6:	4c 0f b6 6e 07       	movzx  r13,BYTE PTR [rsi+0x7]
 3db:	49 c1 e5 38          	shl    r13,0x38
 3df:	49 09 dd             	or     r13,rbx
 3e2:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 3e7:	48 c1 e6 38          	shl    rsi,0x38
 3eb:	48 09 c6             	or     rsi,rax
 3ee:	41 89 c8             	mov    r8d,ecx
 3f1:	4c 89 c2             	mov    rdx,r8
 3f4:	48 01 fa             	add    rdx,rdi
 3f7:	48 89 f7             	mov    rdi,rsi
 3fa:	48 6b ff 03          	imul   rdi,rdi,0x3
 3fe:	48 01 fa             	add    rdx,rdi
 401:	4c 01 ea             	add    rdx,r13
 404:	83 e1 07             	and    ecx,0x7
 407:	89 cf                	mov    edi,ecx
 409:	83 c7 01             	add    edi,0x1
 40c:	83 f1 3f             	xor    ecx,0x3f
 40f:	49 c1 e0 0b          	shl    r8,0xb
 413:	48 89 d0             	mov    rax,rdx
 416:	4c 01 c0             	add    rax,r8
 419:	49 89 c0             	mov    r8,rax
 41c:	49 d3 e8             	shr    r8,cl
 41f:	c4 e2 c1 f7 c0       	shlx   rax,rax,rdi
 424:	4c 09 c0             	or     rax,r8
 427:	48 31 d0             	xor    rax,rdx
 42a:	48 c1 ee 03          	shr    rsi,0x3
 42e:	48 01 f0             	add    rax,rsi
 431:	41 5d                	pop    r13
 433:	5b                   	pop    rbx
 434:	c9                   	leave
 435:	c3                   	ret
 436:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 43b:	0f 1f 00             	nop    DWORD PTR [rax]
 43e:	55                   	push   rbp
 43f:	48 89 e5             	mov    rbp,rsp
 442:	48 81 ec 08 00 00 00 	sub    rsp,0x8
 449:	53                   	push   rbx
 44a:	41 55                	push   r13
 44c:	41 56                	push   r14
 44e:	41 57                	push   r15
 450:	89 4d f8             	mov    DWORD PTR [rbp-0x8],ecx
 453:	48 89 f1             	mov    rcx,rsi
 456:	89 d6                	mov    esi,edx
 458:	83 c6 08             	add    esi,0x8
 45b:	49 89 c8             	mov    r8,rcx
 45e:	49 01 f0             	add    r8,rsi
 461:	49 0f b6 70 00       	movzx  rsi,BYTE PTR [r8+0x0]
 466:	49 0f b6 40 01       	movzx  rax,BYTE PTR [r8+0x1]
 46b:	48 c1 e0 08          	shl    rax,0x8
 46f:	48 09 f0             	or     rax,rsi
 472:	49 0f b6 70 02       	movzx  rsi,BYTE PTR [r8+0x2]
 477:	48 c1 e6 10          	shl    rsi,0x10
 47b:	48 09 c6             	or     rsi,rax
 47e:	49 0f b6 58 03       	movzx  rbx,BYTE PTR [r8+0x3]
 483:	48 c1 e3 18          	shl    rbx,0x18
 487:	48 09 f3             	or     rbx,rsi
 48a:	89 d6                	mov    esi,edx
 48c:	83 c6 10             	add    esi,0x10
 48f:	48 89 c8             	mov    rax,rcx
 492:	48 01 f0             	add    rax,rsi
 495:	48 0f b6 70 00       	movzx  rsi,BYTE PTR [rax+0x0]
 49a:	4c 0f b6 70 01       	movzx  r14,BYTE PTR [rax+0x1]
 49f:	49 c1 e6 08          	shl    r14,0x8
 4a3:	49 09 f6             	or     r14,rsi
 4a6:	4c 0f b6 68 02       	movzx  r13,BYTE PTR [rax+0x2]
 4ab:	49 c1 e5 10          	shl    r13,0x10
 4af:	4d 09 f5             	or     r13,r14
 4b2:	49 0f b6 70 04       	movzx  rsi,BYTE PTR [r8+0x4]
 4b7:	48 c1 e6 20          	shl    rsi,0x20
 4bb:	48 09 de             	or     rsi,rbx
 4be:	49 0f b6 58 05       	movzx  rbx,BYTE PTR [r8+0x5]
 4c3:	48 c1 e3 28          	shl    rbx,0x28
 4c7:	48 09 f3             	or     rbx,rsi
 4ca:	4c 0f b6 78 03       	movzx  r15,BYTE PTR [rax+0x3]
 4cf:	49 c1 e7 18          	shl    r15,0x18
 4d3:	4d 09 ef             	or     r15,r13
 4d6:	41 89 d6             	mov    r14d,edx
 4d9:	83 c2 04             	add    edx,0x4
 4dc:	48 89 ce             	mov    rsi,rcx
 4df:	48 01 d6             	add    rsi,rdx
 4e2:	48 c1 e2 20          	shl    rdx,0x20
 4e6:	48 c1 fa 20          	sar    rdx,0x20
 4ea:	49 89 cd             	mov    r13,rcx
 4ed:	4d 01 f5             	add    r13,r14
 4f0:	48 01 d1             	add    rcx,rdx
 4f3:	4c 0f b6 70 04       	movzx  r14,BYTE PTR [rax+0x4]
 4f8:	49 c1 e6 20          	shl    r14,0x20
 4fc:	4d 09 fe             	or     r14,r15
 4ff:	4d 0f b6 78 06       	movzx  r15,BYTE PTR [r8+0x6]
 504:	49 c1 e7 30          	shl    r15,0x30
 508:	49 09 df             	or     r15,rbx
 50b:	48 0f b6 76 00       	movzx  rsi,BYTE PTR [rsi+0x0]
 510:	48 c1 e6 09          	shl    rsi,0x9
 514:	48 0f b6 59 01       	movzx  rbx,BYTE PTR [rcx+0x1]
 519:	48 c1 e3 11          	shl    rbx,0x11
 51d:	48 09 f3             	or     rbx,rsi
 520:	49 0f b6 50 07       	movzx  rdx,BYTE PTR [r8+0x7]
 525:	48 c1 e2 38          	shl    rdx,0x38
 529:	4c 09 fa             	or     rdx,r15
 52c:	48 0f b6 70 05       	movzx  rsi,BYTE PTR [rax+0x5]
 531:	48 c1 e6 28          	shl    rsi,0x28
 535:	4c 09 f6             	or     rsi,r14
 538:	4c 0f b6 70 06       	movzx  r14,BYTE PTR [rax+0x6]
 53d:	49 c1 e6 30          	shl    r14,0x30
 541:	49 09 f6             	or     r14,rsi
 544:	4c 0f b6 40 07       	movzx  r8,BYTE PTR [rax+0x7]
 549:	49 c1 e0 38          	shl    r8,0x38
 54d:	4d 09 f0             	or     r8,r14
 550:	48 01 fa             	add    rdx,rdi
 553:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 558:	48 c1 e7 19          	shl    rdi,0x19
 55c:	48 09 fb             	or     rbx,rdi
 55f:	49 0f b6 75 00       	movzx  rsi,BYTE PTR [r13+0x0]
 564:	48 83 e6 07          	and    rsi,0x7
 568:	8b 7d f8             	mov    edi,DWORD PTR [rbp-0x8]
 56b:	89 ff                	mov    edi,edi
 56d:	c4 e2 c9 f7 ff       	shlx   rdi,rdi,rsi
 572:	89 f0                	mov    eax,esi
 574:	83 c0 01             	add    eax,0x1
 577:	83 f6 3f             	xor    esi,0x3f
 57a:	49 31 d0             	xor    r8,rdx
 57d:	4d 89 c5             	mov    r13,r8
 580:	c4 42 cb f7 ed       	shrx   r13,r13,rsi
 585:	c4 42 f9 f7 c0       	shlx   r8,r8,rax
 58a:	4d 09 e8             	or     r8,r13
 58d:	48 0f b6 71 03       	movzx  rsi,BYTE PTR [rcx+0x3]
 592:	48 c1 e6 21          	shl    rsi,0x21
 596:	48 09 f3             	or     rbx,rsi
 599:	48 89 d0             	mov    rax,rdx
 59c:	48 31 d8             	xor    rax,rbx
 59f:	4c 31 c0             	xor    rax,r8
 5a2:	48 01 f8             	add    rax,rdi
 5a5:	49 c1 e8 05          	shr    r8,0x5
 5a9:	4c 31 c0             	xor    rax,r8
 5ac:	48 01 d0             	add    rax,rdx
 5af:	41 5f                	pop    r15
 5b1:	41 5e                	pop    r14
 5b3:	41 5d                	pop    r13
 5b5:	5b                   	pop    rbx
 5b6:	c9                   	leave
 5b7:	c3                   	ret
 5b8:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 5bd:	0f 1f 00             	nop    DWORD PTR [rax]
 5c0:	55                   	push   rbp
 5c1:	48 89 e5             	mov    rbp,rsp
 5c4:	53                   	push   rbx
 5c5:	41 55                	push   r13
 5c7:	41 56                	push   r14
 5c9:	89 d0                	mov    eax,edx
 5cb:	49 89 f0             	mov    r8,rsi
 5ce:	49 01 c0             	add    r8,rax
 5d1:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 5d6:	48 31 fb             	xor    rbx,rdi
 5d9:	48 bf eb 11 31 13 bb 	movabs rdi,0x94d049bb133111eb
 5e0:	49 d0 94 
 5e3:	48 31 fb             	xor    rbx,rdi
 5e6:	89 cf                	mov    edi,ecx
 5e8:	48 01 fb             	add    rbx,rdi
 5eb:	48 89 d9             	mov    rcx,rbx
 5ee:	48 c1 e9 3f          	shr    rcx,0x3f
 5f2:	48 d1 e3             	shl    rbx,1
 5f5:	48 09 cb             	or     rbx,rcx
 5f8:	89 d0                	mov    eax,edx
 5fa:	83 c0 10             	add    eax,0x10
 5fd:	83 c2 08             	add    edx,0x8
 600:	48 89 f1             	mov    rcx,rsi
 603:	48 01 d1             	add    rcx,rdx
 606:	48 01 c6             	add    rsi,rax
 609:	49 0f b6 40 01       	movzx  rax,BYTE PTR [r8+0x1]
 60e:	48 c1 e0 08          	shl    rax,0x8
 612:	48 31 d8             	xor    rax,rbx
 615:	48 0f b6 5e 00       	movzx  rbx,BYTE PTR [rsi+0x0]
 61a:	48 0f b6 56 01       	movzx  rdx,BYTE PTR [rsi+0x1]
 61f:	48 c1 e2 08          	shl    rdx,0x8
 623:	48 09 da             	or     rdx,rbx
 626:	48 0f b6 59 00       	movzx  rbx,BYTE PTR [rcx+0x0]
 62b:	4c 0f b6 69 01       	movzx  r13,BYTE PTR [rcx+0x1]
 630:	49 c1 e5 08          	shl    r13,0x8
 634:	49 09 dd             	or     r13,rbx
 637:	48 0f b6 59 02       	movzx  rbx,BYTE PTR [rcx+0x2]
 63c:	48 c1 e3 10          	shl    rbx,0x10
 640:	4c 09 eb             	or     rbx,r13
 643:	4c 0f b6 6e 02       	movzx  r13,BYTE PTR [rsi+0x2]
 648:	49 c1 e5 10          	shl    r13,0x10
 64c:	49 09 d5             	or     r13,rdx
 64f:	48 89 fa             	mov    rdx,rdi
 652:	48 01 c2             	add    rdx,rax
 655:	48 83 c2 01          	add    rdx,0x1
 659:	48 89 d0             	mov    rax,rdx
 65c:	48 c1 e8 3e          	shr    rax,0x3e
 660:	48 c1 e2 02          	shl    rdx,0x2
 664:	48 09 c2             	or     rdx,rax
 667:	48 0f b6 46 03       	movzx  rax,BYTE PTR [rsi+0x3]
 66c:	48 c1 e0 18          	shl    rax,0x18
 670:	4c 09 e8             	or     rax,r13
 673:	4c 0f b6 69 03       	movzx  r13,BYTE PTR [rcx+0x3]
 678:	49 c1 e5 18          	shl    r13,0x18
 67c:	49 09 dd             	or     r13,rbx
 67f:	48 0f b6 59 04       	movzx  rbx,BYTE PTR [rcx+0x4]
 684:	48 c1 e3 20          	shl    rbx,0x20
 688:	4c 09 eb             	or     rbx,r13
 68b:	4c 0f b6 76 04       	movzx  r14,BYTE PTR [rsi+0x4]
 690:	49 c1 e6 20          	shl    r14,0x20
 694:	49 09 c6             	or     r14,rax
 697:	49 0f b6 40 02       	movzx  rax,BYTE PTR [r8+0x2]
 69c:	48 c1 e0 10          	shl    rax,0x10
 6a0:	48 31 d0             	xor    rax,rdx
 6a3:	4c 0f b6 6e 05       	movzx  r13,BYTE PTR [rsi+0x5]
 6a8:	49 c1 e5 28          	shl    r13,0x28
 6ac:	4d 09 f5             	or     r13,r14
 6af:	4c 0f b6 71 05       	movzx  r14,BYTE PTR [rcx+0x5]
 6b4:	49 c1 e6 28          	shl    r14,0x28
 6b8:	49 09 de             	or     r14,rbx
 6bb:	48 0f b6 51 06       	movzx  rdx,BYTE PTR [rcx+0x6]
 6c0:	48 c1 e2 30          	shl    rdx,0x30
 6c4:	4c 09 f2             	or     rdx,r14
 6c7:	4c 0f b6 76 06       	movzx  r14,BYTE PTR [rsi+0x6]
 6cc:	49 c1 e6 30          	shl    r14,0x30
 6d0:	4d 09 ee             	or     r14,r13
 6d3:	48 89 fb             	mov    rbx,rdi
 6d6:	48 01 c3             	add    rbx,rax
 6d9:	48 83 c3 02          	add    rbx,0x2
 6dd:	48 89 d8             	mov    rax,rbx
 6e0:	48 c1 e8 3d          	shr    rax,0x3d
 6e4:	48 c1 e3 03          	shl    rbx,0x3
 6e8:	48 09 c3             	or     rbx,rax
 6eb:	48 0f b6 46 07       	movzx  rax,BYTE PTR [rsi+0x7]
 6f0:	48 c1 e0 38          	shl    rax,0x38
 6f4:	4c 09 f0             	or     rax,r14
 6f7:	48 0f b6 71 07       	movzx  rsi,BYTE PTR [rcx+0x7]
 6fc:	48 c1 e6 38          	shl    rsi,0x38
 700:	48 09 d6             	or     rsi,rdx
 703:	49 0f b6 50 03       	movzx  rdx,BYTE PTR [r8+0x3]
 708:	48 c1 e2 18          	shl    rdx,0x18
 70c:	48 31 da             	xor    rdx,rbx
 70f:	48 89 f9             	mov    rcx,rdi
 712:	48 01 d1             	add    rcx,rdx
 715:	48 83 c1 03          	add    rcx,0x3
 719:	48 89 ca             	mov    rdx,rcx
 71c:	48 c1 ea 3c          	shr    rdx,0x3c
 720:	48 c1 e1 04          	shl    rcx,0x4
 724:	48 09 d1             	or     rcx,rdx
 727:	49 0f b6 50 04       	movzx  rdx,BYTE PTR [r8+0x4]
 72c:	48 c1 e2 20          	shl    rdx,0x20
 730:	48 31 ca             	xor    rdx,rcx
 733:	48 89 f9             	mov    rcx,rdi
 736:	48 01 d1             	add    rcx,rdx
 739:	48 83 c1 04          	add    rcx,0x4
 73d:	48 89 ca             	mov    rdx,rcx
 740:	48 c1 ea 3b          	shr    rdx,0x3b
 744:	48 c1 e1 05          	shl    rcx,0x5
 748:	48 09 d1             	or     rcx,rdx
 74b:	49 0f b6 50 05       	movzx  rdx,BYTE PTR [r8+0x5]
 750:	48 c1 e2 28          	shl    rdx,0x28
 754:	48 31 ca             	xor    rdx,rcx
 757:	48 89 f9             	mov    rcx,rdi
 75a:	48 01 d1             	add    rcx,rdx
 75d:	48 83 c1 05          	add    rcx,0x5
 761:	48 89 ca             	mov    rdx,rcx
 764:	48 c1 ea 3a          	shr    rdx,0x3a
 768:	48 c1 e1 06          	shl    rcx,0x6
 76c:	48 09 d1             	or     rcx,rdx
 76f:	49 0f b6 50 06       	movzx  rdx,BYTE PTR [r8+0x6]
 774:	48 c1 e2 30          	shl    rdx,0x30
 778:	48 31 ca             	xor    rdx,rcx
 77b:	48 89 f9             	mov    rcx,rdi
 77e:	48 01 d1             	add    rcx,rdx
 781:	48 83 c1 06          	add    rcx,0x6
 785:	48 89 ca             	mov    rdx,rcx
 788:	48 c1 ea 39          	shr    rdx,0x39
 78c:	48 c1 e1 07          	shl    rcx,0x7
 790:	48 09 d1             	or     rcx,rdx
 793:	49 0f b6 50 07       	movzx  rdx,BYTE PTR [r8+0x7]
 798:	48 c1 e2 38          	shl    rdx,0x38
 79c:	48 31 ca             	xor    rdx,rcx
 79f:	48 01 d7             	add    rdi,rdx
 7a2:	48 83 c7 07          	add    rdi,0x7
 7a6:	48 89 fa             	mov    rdx,rdi
 7a9:	48 c1 ea 38          	shr    rdx,0x38
 7ad:	48 c1 e7 08          	shl    rdi,0x8
 7b1:	48 09 d7             	or     rdi,rdx
 7b4:	48 01 fe             	add    rsi,rdi
 7b7:	48 31 f0             	xor    rax,rsi
 7ba:	41 5e                	pop    r14
 7bc:	41 5d                	pop    r13
 7be:	5b                   	pop    rbx
 7bf:	c9                   	leave
 7c0:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
