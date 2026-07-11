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
  27:	0f 87 e7 01 00 00    	ja     0x214
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  38:	48 39 f7             	cmp    rdi,rsi
  3b:	0f 87 d3 01 00 00    	ja     0x214
  41:	48 89 d7             	mov    rdi,rdx
  44:	48 81 c7 90 01 00 00 	add    rdi,0x190
  4b:	48 39 f7             	cmp    rdi,rsi
  4e:	0f 87 c0 01 00 00    	ja     0x214
  54:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  59:	48 c1 e7 08          	shl    rdi,0x8
  5d:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  62:	48 09 f7             	or     rdi,rsi
  65:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  6a:	48 c1 e6 10          	shl    rsi,0x10
  6e:	48 09 f7             	or     rdi,rsi
  71:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  76:	48 c1 e6 18          	shl    rsi,0x18
  7a:	48 09 f7             	or     rdi,rsi
  7d:	48 c1 e7 20          	shl    rdi,0x20
  81:	48 c1 ef 20          	shr    rdi,0x20
  85:	48 83 ff 10          	cmp    rdi,0x10
  89:	0f 85 85 01 00 00    	jne    0x214
  8f:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  94:	48 c1 e7 08          	shl    rdi,0x8
  98:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  9d:	48 09 f7             	or     rdi,rsi
  a0:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  a5:	48 c1 e6 10          	shl    rsi,0x10
  a9:	48 09 f7             	or     rdi,rsi
  ac:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  b1:	48 c1 e6 18          	shl    rsi,0x18
  b5:	48 09 f7             	or     rdi,rsi
  b8:	48 c1 e7 20          	shl    rdi,0x20
  bc:	48 c1 ef 20          	shr    rdi,0x20
  c0:	48 83 ff 18          	cmp    rdi,0x18
  c4:	0f 85 4a 01 00 00    	jne    0x214
  ca:	48 b8 d3 08 a3 85 88 	movabs rax,0x243f6a8885a308d3
  d1:	6a 3f 24 
  d4:	45 31 ff             	xor    r15d,r15d
  d7:	31 c9                	xor    ecx,ecx
  d9:	45 31 f6             	xor    r14d,r14d
  dc:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
  e0:	eb 4a                	jmp    0x12c
  e2:	48 89 c7             	mov    rdi,rax
  e5:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
  e9:	4c 89 e9             	mov    rcx,r13
  ec:	e8 63 01 00 00       	call   0x254
  f1:	4c 89 f7             	mov    rdi,r14
  f4:	48 83 e7 38          	and    rdi,0x38
  f8:	c4 e2 c1 f7 db       	shlx   rbx,rbx,rdi
  fd:	49 c1 e5 20          	shl    r13,0x20
 101:	49 c1 ed 20          	shr    r13,0x20
 105:	4c 01 eb             	add    rbx,r13
 108:	48 31 d8             	xor    rax,rbx
 10b:	49 83 c7 18          	add    r15,0x18
 10f:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 113:	48 83 c1 10          	add    rcx,0x10
 117:	49 83 c6 08          	add    r14,0x8
 11b:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 11f:	49 81 fe 80 00 00 00 	cmp    r14,0x80
 126:	0f 84 97 00 00 00    	je     0x1c3
 12c:	48 89 d7             	mov    rdi,rdx
 12f:	4c 01 ff             	add    rdi,r15
 132:	4c 0f b6 6f 15       	movzx  r13,BYTE PTR [rdi+0x15]
 137:	49 c1 e5 08          	shl    r13,0x8
 13b:	48 0f b6 77 14       	movzx  rsi,BYTE PTR [rdi+0x14]
 140:	49 09 f5             	or     r13,rsi
 143:	48 0f b6 77 16       	movzx  rsi,BYTE PTR [rdi+0x16]
 148:	48 c1 e6 10          	shl    rsi,0x10
 14c:	49 09 f5             	or     r13,rsi
 14f:	48 0f b6 77 17       	movzx  rsi,BYTE PTR [rdi+0x17]
 154:	48 c1 e6 18          	shl    rsi,0x18
 158:	49 09 f5             	or     r13,rsi
 15b:	49 31 cd             	xor    r13,rcx
 15e:	4c 89 fa             	mov    rdx,r15
 161:	48 83 c2 08          	add    rdx,0x8
 165:	48 0f b6 5f 10       	movzx  rbx,BYTE PTR [rdi+0x10]
 16a:	48 83 e3 03          	and    rbx,0x3
 16e:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
 172:	48 83 fb 02          	cmp    rbx,0x2
 176:	74 23                	je     0x19b
 178:	48 83 fb 01          	cmp    rbx,0x1
 17c:	0f 84 60 ff ff ff    	je     0xe2
 182:	48 85 db             	test   rbx,rbx
 185:	75 28                	jne    0x1af
 187:	48 89 c7             	mov    rdi,rax
 18a:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 18e:	4c 89 e9             	mov    rcx,r13
 191:	e8 2e 02 00 00       	call   0x3c4
 196:	e9 56 ff ff ff       	jmp    0xf1
 19b:	48 89 c7             	mov    rdi,rax
 19e:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 1a2:	4c 89 e9             	mov    rcx,r13
 1a5:	e8 96 03 00 00       	call   0x540
 1aa:	e9 42 ff ff ff       	jmp    0xf1
 1af:	48 89 c7             	mov    rdi,rax
 1b2:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 1b6:	4c 89 e9             	mov    rcx,r13
 1b9:	e8 86 05 00 00       	call   0x744
 1be:	e9 2e ff ff ff       	jmp    0xf1
 1c3:	48 89 c7             	mov    rdi,rax
 1c6:	48 c1 ef 38          	shr    rdi,0x38
 1ca:	40 88 7a 07          	mov    BYTE PTR [rdx+0x7],dil
 1ce:	48 89 c7             	mov    rdi,rax
 1d1:	48 c1 ef 30          	shr    rdi,0x30
 1d5:	40 88 7a 06          	mov    BYTE PTR [rdx+0x6],dil
 1d9:	48 89 c7             	mov    rdi,rax
 1dc:	48 c1 ef 28          	shr    rdi,0x28
 1e0:	40 88 7a 05          	mov    BYTE PTR [rdx+0x5],dil
 1e4:	48 89 c7             	mov    rdi,rax
 1e7:	48 c1 ef 20          	shr    rdi,0x20
 1eb:	40 88 7a 04          	mov    BYTE PTR [rdx+0x4],dil
 1ef:	48 89 c7             	mov    rdi,rax
 1f2:	48 c1 ef 18          	shr    rdi,0x18
 1f6:	40 88 7a 03          	mov    BYTE PTR [rdx+0x3],dil
 1fa:	48 89 c7             	mov    rdi,rax
 1fd:	48 c1 ef 10          	shr    rdi,0x10
 201:	40 88 7a 02          	mov    BYTE PTR [rdx+0x2],dil
 205:	88 42 00             	mov    BYTE PTR [rdx+0x0],al
 208:	48 c1 e8 08          	shr    rax,0x8
 20c:	88 42 01             	mov    BYTE PTR [rdx+0x1],al
 20f:	b8 02 00 00 00       	mov    eax,0x2
 214:	41 5f                	pop    r15
 216:	41 5e                	pop    r14
 218:	41 5d                	pop    r13
 21a:	5b                   	pop    rbx
 21b:	c9                   	leave
 21c:	c3                   	ret
 21d:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 222:	0f 1f 00             	nop    DWORD PTR [rax]
 225:	55                   	push   rbp
 226:	48 89 e5             	mov    rbp,rsp
 229:	53                   	push   rbx
 22a:	41 55                	push   r13
 22c:	48 89 d0             	mov    rax,rdx
 22f:	48 83 c0 08          	add    rax,0x8
 233:	48 83 c2 10          	add    rdx,0x10
 237:	48 c1 e2 20          	shl    rdx,0x20
 23b:	48 c1 ea 20          	shr    rdx,0x20
 23f:	49 89 f0             	mov    r8,rsi
 242:	49 01 d0             	add    r8,rdx
 245:	48 c1 e0 20          	shl    rax,0x20
 249:	48 c1 e8 20          	shr    rax,0x20
 24d:	48 01 c6             	add    rsi,rax
 250:	48 0f b6 46 01       	movzx  rax,BYTE PTR [rsi+0x1]
 255:	48 c1 e0 08          	shl    rax,0x8
 259:	48 0f b6 56 00       	movzx  rdx,BYTE PTR [rsi+0x0]
 25e:	48 09 d0             	or     rax,rdx
 261:	49 0f b6 58 01       	movzx  rbx,BYTE PTR [r8+0x1]
 266:	48 c1 e3 08          	shl    rbx,0x8
 26a:	49 0f b6 50 00       	movzx  rdx,BYTE PTR [r8+0x0]
 26f:	48 09 d3             	or     rbx,rdx
 272:	49 0f b6 50 02       	movzx  rdx,BYTE PTR [r8+0x2]
 277:	48 c1 e2 10          	shl    rdx,0x10
 27b:	48 09 da             	or     rdx,rbx
 27e:	48 0f b6 5e 02       	movzx  rbx,BYTE PTR [rsi+0x2]
 283:	48 c1 e3 10          	shl    rbx,0x10
 287:	48 09 c3             	or     rbx,rax
 28a:	4c 0f b6 6e 03       	movzx  r13,BYTE PTR [rsi+0x3]
 28f:	49 c1 e5 18          	shl    r13,0x18
 293:	49 09 dd             	or     r13,rbx
 296:	48 0f b6 46 04       	movzx  rax,BYTE PTR [rsi+0x4]
 29b:	48 c1 e0 20          	shl    rax,0x20
 29f:	4c 09 e8             	or     rax,r13
 2a2:	49 0f b6 58 03       	movzx  rbx,BYTE PTR [r8+0x3]
 2a7:	48 c1 e3 18          	shl    rbx,0x18
 2ab:	48 09 d3             	or     rbx,rdx
 2ae:	4d 0f b6 68 04       	movzx  r13,BYTE PTR [r8+0x4]
 2b3:	49 c1 e5 20          	shl    r13,0x20
 2b7:	49 09 dd             	or     r13,rbx
 2ba:	49 0f b6 50 05       	movzx  rdx,BYTE PTR [r8+0x5]
 2bf:	48 c1 e2 28          	shl    rdx,0x28
 2c3:	4c 09 ea             	or     rdx,r13
 2c6:	48 0f b6 5e 05       	movzx  rbx,BYTE PTR [rsi+0x5]
 2cb:	48 c1 e3 28          	shl    rbx,0x28
 2cf:	48 09 c3             	or     rbx,rax
 2d2:	4c 0f b6 6e 06       	movzx  r13,BYTE PTR [rsi+0x6]
 2d7:	49 c1 e5 30          	shl    r13,0x30
 2db:	49 09 dd             	or     r13,rbx
 2de:	48 0f b6 46 07       	movzx  rax,BYTE PTR [rsi+0x7]
 2e3:	48 c1 e0 38          	shl    rax,0x38
 2e7:	4c 09 e8             	or     rax,r13
 2ea:	49 0f b6 58 06       	movzx  rbx,BYTE PTR [r8+0x6]
 2ef:	48 c1 e3 30          	shl    rbx,0x30
 2f3:	48 09 d3             	or     rbx,rdx
 2f6:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 2fb:	48 c1 e6 38          	shl    rsi,0x38
 2ff:	48 09 de             	or     rsi,rbx
 302:	48 c1 e1 20          	shl    rcx,0x20
 306:	48 c1 e9 20          	shr    rcx,0x20
 30a:	48 c1 e1 11          	shl    rcx,0x11
 30e:	48 89 f2             	mov    rdx,rsi
 311:	48 01 ca             	add    rdx,rcx
 314:	48 89 d1             	mov    rcx,rdx
 317:	48 31 c1             	xor    rcx,rax
 31a:	49 89 c8             	mov    r8,rcx
 31d:	49 c1 e8 3b          	shr    r8,0x3b
 321:	48 c1 e1 05          	shl    rcx,0x5
 325:	4c 09 c1             	or     rcx,r8
 328:	48 31 f8             	xor    rax,rdi
 32b:	48 c1 ee 02          	shr    rsi,0x2
 32f:	48 89 c7             	mov    rdi,rax
 332:	48 c1 e7 03          	shl    rdi,0x3
 336:	48 31 fe             	xor    rsi,rdi
 339:	48 89 f7             	mov    rdi,rsi
 33c:	48 01 c7             	add    rdi,rax
 33f:	49 89 f8             	mov    r8,rdi
 342:	49 c1 e8 35          	shr    r8,0x35
 346:	48 c1 e7 0b          	shl    rdi,0xb
 34a:	4c 09 c7             	or     rdi,r8
 34d:	48 01 cf             	add    rdi,rcx
 350:	48 89 d1             	mov    rcx,rdx
 353:	48 c1 e9 07          	shr    rcx,0x7
 357:	48 31 cf             	xor    rdi,rcx
 35a:	48 01 f7             	add    rdi,rsi
 35d:	48 31 f8             	xor    rax,rdi
 360:	48 31 d0             	xor    rax,rdx
 363:	41 5d                	pop    r13
 365:	5b                   	pop    rbx
 366:	c9                   	leave
 367:	c3                   	ret
 368:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 36d:	0f 1f 00             	nop    DWORD PTR [rax]
 370:	55                   	push   rbp
 371:	48 89 e5             	mov    rbp,rsp
 374:	53                   	push   rbx
 375:	41 55                	push   r13
 377:	48 89 d0             	mov    rax,rdx
 37a:	48 83 c0 10          	add    rax,0x10
 37e:	48 83 c2 08          	add    rdx,0x8
 382:	48 c1 e2 20          	shl    rdx,0x20
 386:	48 c1 ea 20          	shr    rdx,0x20
 38a:	49 89 f0             	mov    r8,rsi
 38d:	49 01 d0             	add    r8,rdx
 390:	48 c1 e0 20          	shl    rax,0x20
 394:	48 c1 e8 20          	shr    rax,0x20
 398:	48 01 c6             	add    rsi,rax
 39b:	48 0f b6 56 01       	movzx  rdx,BYTE PTR [rsi+0x1]
 3a0:	48 c1 e2 08          	shl    rdx,0x8
 3a4:	48 0f b6 46 00       	movzx  rax,BYTE PTR [rsi+0x0]
 3a9:	48 09 c2             	or     rdx,rax
 3ac:	49 0f b6 40 01       	movzx  rax,BYTE PTR [r8+0x1]
 3b1:	48 c1 e0 08          	shl    rax,0x8
 3b5:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 3ba:	48 09 d8             	or     rax,rbx
 3bd:	49 0f b6 58 02       	movzx  rbx,BYTE PTR [r8+0x2]
 3c2:	48 c1 e3 10          	shl    rbx,0x10
 3c6:	48 09 c3             	or     rbx,rax
 3c9:	49 0f b6 40 03       	movzx  rax,BYTE PTR [r8+0x3]
 3ce:	48 c1 e0 18          	shl    rax,0x18
 3d2:	48 09 d8             	or     rax,rbx
 3d5:	48 0f b6 5e 02       	movzx  rbx,BYTE PTR [rsi+0x2]
 3da:	48 c1 e3 10          	shl    rbx,0x10
 3de:	48 09 d3             	or     rbx,rdx
 3e1:	4c 0f b6 6e 03       	movzx  r13,BYTE PTR [rsi+0x3]
 3e6:	49 c1 e5 18          	shl    r13,0x18
 3ea:	49 09 dd             	or     r13,rbx
 3ed:	48 0f b6 56 04       	movzx  rdx,BYTE PTR [rsi+0x4]
 3f2:	48 c1 e2 20          	shl    rdx,0x20
 3f6:	4c 09 ea             	or     rdx,r13
 3f9:	49 0f b6 58 04       	movzx  rbx,BYTE PTR [r8+0x4]
 3fe:	48 c1 e3 20          	shl    rbx,0x20
 402:	48 09 c3             	or     rbx,rax
 405:	4d 0f b6 68 05       	movzx  r13,BYTE PTR [r8+0x5]
 40a:	49 c1 e5 28          	shl    r13,0x28
 40e:	49 09 dd             	or     r13,rbx
 411:	49 0f b6 40 06       	movzx  rax,BYTE PTR [r8+0x6]
 416:	48 c1 e0 30          	shl    rax,0x30
 41a:	4c 09 e8             	or     rax,r13
 41d:	48 0f b6 5e 05       	movzx  rbx,BYTE PTR [rsi+0x5]
 422:	48 c1 e3 28          	shl    rbx,0x28
 426:	48 09 d3             	or     rbx,rdx
 429:	48 0f b6 56 06       	movzx  rdx,BYTE PTR [rsi+0x6]
 42e:	48 c1 e2 30          	shl    rdx,0x30
 432:	48 09 da             	or     rdx,rbx
 435:	48 0f b6 5e 07       	movzx  rbx,BYTE PTR [rsi+0x7]
 43a:	48 c1 e3 38          	shl    rbx,0x38
 43e:	48 09 d3             	or     rbx,rdx
 441:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 446:	48 c1 e6 38          	shl    rsi,0x38
 44a:	48 09 c6             	or     rsi,rax
 44d:	49 89 c8             	mov    r8,rcx
 450:	49 c1 e0 20          	shl    r8,0x20
 454:	49 c1 e8 20          	shr    r8,0x20
 458:	4c 89 c2             	mov    rdx,r8
 45b:	48 01 fa             	add    rdx,rdi
 45e:	48 89 f7             	mov    rdi,rsi
 461:	48 6b ff 03          	imul   rdi,rdi,0x3
 465:	48 01 fa             	add    rdx,rdi
 468:	48 01 da             	add    rdx,rbx
 46b:	48 83 e1 07          	and    rcx,0x7
 46f:	48 89 cf             	mov    rdi,rcx
 472:	48 83 c7 01          	add    rdi,0x1
 476:	48 83 f1 3f          	xor    rcx,0x3f
 47a:	49 c1 e0 0b          	shl    r8,0xb
 47e:	48 89 d0             	mov    rax,rdx
 481:	4c 01 c0             	add    rax,r8
 484:	49 89 c0             	mov    r8,rax
 487:	49 d3 e8             	shr    r8,cl
 48a:	c4 e2 c1 f7 c0       	shlx   rax,rax,rdi
 48f:	4c 09 c0             	or     rax,r8
 492:	48 31 d0             	xor    rax,rdx
 495:	48 c1 ee 03          	shr    rsi,0x3
 499:	48 01 f0             	add    rax,rsi
 49c:	41 5d                	pop    r13
 49e:	5b                   	pop    rbx
 49f:	c9                   	leave
 4a0:	c3                   	ret
 4a1:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 4a6:	0f 1f 00             	nop    DWORD PTR [rax]
 4a9:	55                   	push   rbp
 4aa:	48 89 e5             	mov    rbp,rsp
 4ad:	48 81 ec 08 00 00 00 	sub    rsp,0x8
 4b4:	53                   	push   rbx
 4b5:	41 55                	push   r13
 4b7:	41 56                	push   r14
 4b9:	41 57                	push   r15
 4bb:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
 4bf:	48 89 d1             	mov    rcx,rdx
 4c2:	49 89 c8             	mov    r8,rcx
 4c5:	49 83 c0 08          	add    r8,0x8
 4c9:	49 c1 e0 20          	shl    r8,0x20
 4cd:	49 c1 e8 20          	shr    r8,0x20
 4d1:	48 89 f0             	mov    rax,rsi
 4d4:	4c 01 c0             	add    rax,r8
 4d7:	48 0f b6 58 01       	movzx  rbx,BYTE PTR [rax+0x1]
 4dc:	48 c1 e3 08          	shl    rbx,0x8
 4e0:	4c 0f b6 40 00       	movzx  r8,BYTE PTR [rax+0x0]
 4e5:	4c 09 c3             	or     rbx,r8
 4e8:	49 89 cd             	mov    r13,rcx
 4eb:	49 83 c5 10          	add    r13,0x10
 4ef:	49 c1 e5 20          	shl    r13,0x20
 4f3:	49 c1 ed 20          	shr    r13,0x20
 4f7:	49 89 f0             	mov    r8,rsi
 4fa:	4d 01 e8             	add    r8,r13
 4fd:	4d 0f b6 68 01       	movzx  r13,BYTE PTR [r8+0x1]
 502:	49 c1 e5 08          	shl    r13,0x8
 506:	4d 0f b6 70 00       	movzx  r14,BYTE PTR [r8+0x0]
 50b:	4d 09 f5             	or     r13,r14
 50e:	4d 0f b6 78 02       	movzx  r15,BYTE PTR [r8+0x2]
 513:	49 c1 e7 10          	shl    r15,0x10
 517:	4d 09 ef             	or     r15,r13
 51a:	4d 0f b6 70 03       	movzx  r14,BYTE PTR [r8+0x3]
 51f:	49 c1 e6 18          	shl    r14,0x18
 523:	4d 09 fe             	or     r14,r15
 526:	4c 0f b6 68 02       	movzx  r13,BYTE PTR [rax+0x2]
 52b:	49 c1 e5 10          	shl    r13,0x10
 52f:	49 09 dd             	or     r13,rbx
 532:	48 0f b6 58 03       	movzx  rbx,BYTE PTR [rax+0x3]
 537:	48 c1 e3 18          	shl    rbx,0x18
 53b:	4c 09 eb             	or     rbx,r13
 53e:	4c 0f b6 68 04       	movzx  r13,BYTE PTR [rax+0x4]
 543:	49 c1 e5 20          	shl    r13,0x20
 547:	49 09 dd             	or     r13,rbx
 54a:	4d 0f b6 78 04       	movzx  r15,BYTE PTR [r8+0x4]
 54f:	49 c1 e7 20          	shl    r15,0x20
 553:	4d 09 f7             	or     r15,r14
 556:	48 c1 e2 20          	shl    rdx,0x20
 55a:	48 c1 ea 20          	shr    rdx,0x20
 55e:	48 83 c1 04          	add    rcx,0x4
 562:	48 c1 e1 20          	shl    rcx,0x20
 566:	48 89 cb             	mov    rbx,rcx
 569:	48 c1 fb 20          	sar    rbx,0x20
 56d:	48 c1 e9 20          	shr    rcx,0x20
 571:	49 89 f6             	mov    r14,rsi
 574:	49 01 ce             	add    r14,rcx
 577:	48 89 f1             	mov    rcx,rsi
 57a:	48 01 d1             	add    rcx,rdx
 57d:	48 01 de             	add    rsi,rbx
 580:	49 0f b6 50 05       	movzx  rdx,BYTE PTR [r8+0x5]
 585:	48 c1 e2 28          	shl    rdx,0x28
 589:	4c 09 fa             	or     rdx,r15
 58c:	48 0f b6 58 05       	movzx  rbx,BYTE PTR [rax+0x5]
 591:	48 c1 e3 28          	shl    rbx,0x28
 595:	4c 09 eb             	or     rbx,r13
 598:	4c 0f b6 68 06       	movzx  r13,BYTE PTR [rax+0x6]
 59d:	49 c1 e5 30          	shl    r13,0x30
 5a1:	49 09 dd             	or     r13,rbx
 5a4:	4c 0f b6 78 07       	movzx  r15,BYTE PTR [rax+0x7]
 5a9:	49 c1 e7 38          	shl    r15,0x38
 5ad:	4d 09 ef             	or     r15,r13
 5b0:	49 0f b6 40 06       	movzx  rax,BYTE PTR [r8+0x6]
 5b5:	48 c1 e0 30          	shl    rax,0x30
 5b9:	48 09 d0             	or     rax,rdx
 5bc:	49 0f b6 56 00       	movzx  rdx,BYTE PTR [r14+0x0]
 5c1:	48 c1 e2 09          	shl    rdx,0x9
 5c5:	4c 0f b6 6e 01       	movzx  r13,BYTE PTR [rsi+0x1]
 5ca:	49 c1 e5 11          	shl    r13,0x11
 5ce:	49 09 d5             	or     r13,rdx
 5d1:	48 0f b6 56 02       	movzx  rdx,BYTE PTR [rsi+0x2]
 5d6:	48 c1 e2 19          	shl    rdx,0x19
 5da:	49 09 d5             	or     r13,rdx
 5dd:	48 0f b6 76 03       	movzx  rsi,BYTE PTR [rsi+0x3]
 5e2:	48 c1 e6 21          	shl    rsi,0x21
 5e6:	49 09 f5             	or     r13,rsi
 5e9:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 5ee:	48 c1 e6 38          	shl    rsi,0x38
 5f2:	48 09 c6             	or     rsi,rax
 5f5:	49 01 ff             	add    r15,rdi
 5f8:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 5fd:	48 83 e7 07          	and    rdi,0x7
 601:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 605:	48 c1 e2 20          	shl    rdx,0x20
 609:	48 c1 ea 20          	shr    rdx,0x20
 60d:	c4 e2 c1 f7 d2       	shlx   rdx,rdx,rdi
 612:	49 89 d0             	mov    r8,rdx
 615:	48 89 fa             	mov    rdx,rdi
 618:	48 83 c2 01          	add    rdx,0x1
 61c:	48 83 f7 3f          	xor    rdi,0x3f
 620:	4c 31 fe             	xor    rsi,r15
 623:	48 89 f1             	mov    rcx,rsi
 626:	c4 e2 c3 f7 c9       	shrx   rcx,rcx,rdi
 62b:	c4 e2 e9 f7 f6       	shlx   rsi,rsi,rdx
 630:	48 09 ce             	or     rsi,rcx
 633:	4c 89 f8             	mov    rax,r15
 636:	4c 31 e8             	xor    rax,r13
 639:	48 31 f0             	xor    rax,rsi
 63c:	4c 01 c0             	add    rax,r8
 63f:	48 c1 ee 05          	shr    rsi,0x5
 643:	48 31 f0             	xor    rax,rsi
 646:	4c 01 f8             	add    rax,r15
 649:	41 5f                	pop    r15
 64b:	41 5e                	pop    r14
 64d:	41 5d                	pop    r13
 64f:	5b                   	pop    rbx
 650:	c9                   	leave
 651:	c3                   	ret
 652:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 657:	0f 1f 00             	nop    DWORD PTR [rax]
 65a:	55                   	push   rbp
 65b:	48 89 e5             	mov    rbp,rsp
 65e:	53                   	push   rbx
 65f:	41 55                	push   r13
 661:	41 56                	push   r14
 663:	48 89 d0             	mov    rax,rdx
 666:	48 c1 e0 20          	shl    rax,0x20
 66a:	48 c1 e8 20          	shr    rax,0x20
 66e:	49 89 f0             	mov    r8,rsi
 671:	49 01 c0             	add    r8,rax
 674:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 679:	48 31 fb             	xor    rbx,rdi
 67c:	48 bf eb 11 31 13 bb 	movabs rdi,0x94d049bb133111eb
 683:	49 d0 94 
 686:	48 31 fb             	xor    rbx,rdi
 689:	48 c1 e1 20          	shl    rcx,0x20
 68d:	48 c1 e9 20          	shr    rcx,0x20
 691:	48 01 cb             	add    rbx,rcx
 694:	48 89 df             	mov    rdi,rbx
 697:	48 c1 ef 3f          	shr    rdi,0x3f
 69b:	48 d1 e3             	shl    rbx,1
 69e:	48 09 fb             	or     rbx,rdi
 6a1:	49 0f b6 40 01       	movzx  rax,BYTE PTR [r8+0x1]
 6a6:	48 c1 e0 08          	shl    rax,0x8
 6aa:	48 31 d8             	xor    rax,rbx
 6ad:	48 89 d3             	mov    rbx,rdx
 6b0:	48 83 c3 10          	add    rbx,0x10
 6b4:	48 c1 e3 20          	shl    rbx,0x20
 6b8:	48 c1 eb 20          	shr    rbx,0x20
 6bc:	48 89 f7             	mov    rdi,rsi
 6bf:	48 01 df             	add    rdi,rbx
 6c2:	4c 0f b6 6f 01       	movzx  r13,BYTE PTR [rdi+0x1]
 6c7:	49 c1 e5 08          	shl    r13,0x8
 6cb:	48 0f b6 5f 00       	movzx  rbx,BYTE PTR [rdi+0x0]
 6d0:	49 09 dd             	or     r13,rbx
 6d3:	48 0f b6 5f 02       	movzx  rbx,BYTE PTR [rdi+0x2]
 6d8:	48 c1 e3 10          	shl    rbx,0x10
 6dc:	4c 09 eb             	or     rbx,r13
 6df:	48 83 c2 08          	add    rdx,0x8
 6e3:	48 c1 e2 20          	shl    rdx,0x20
 6e7:	48 c1 ea 20          	shr    rdx,0x20
 6eb:	48 01 d6             	add    rsi,rdx
 6ee:	48 89 ca             	mov    rdx,rcx
 6f1:	48 01 c2             	add    rdx,rax
 6f4:	48 83 c2 01          	add    rdx,0x1
 6f8:	48 89 d0             	mov    rax,rdx
 6fb:	48 c1 e8 3e          	shr    rax,0x3e
 6ff:	48 c1 e2 02          	shl    rdx,0x2
 703:	48 09 c2             	or     rdx,rax
 706:	48 0f b6 47 03       	movzx  rax,BYTE PTR [rdi+0x3]
 70b:	48 c1 e0 18          	shl    rax,0x18
 70f:	48 09 d8             	or     rax,rbx
 712:	48 0f b6 5e 01       	movzx  rbx,BYTE PTR [rsi+0x1]
 717:	48 c1 e3 08          	shl    rbx,0x8
 71b:	4c 0f b6 6e 00       	movzx  r13,BYTE PTR [rsi+0x0]
 720:	4c 09 eb             	or     rbx,r13
 723:	4c 0f b6 6e 02       	movzx  r13,BYTE PTR [rsi+0x2]
 728:	49 c1 e5 10          	shl    r13,0x10
 72c:	49 09 dd             	or     r13,rbx
 72f:	48 0f b6 5e 03       	movzx  rbx,BYTE PTR [rsi+0x3]
 734:	48 c1 e3 18          	shl    rbx,0x18
 738:	4c 09 eb             	or     rbx,r13
 73b:	4c 0f b6 77 04       	movzx  r14,BYTE PTR [rdi+0x4]
 740:	49 c1 e6 20          	shl    r14,0x20
 744:	49 09 c6             	or     r14,rax
 747:	49 0f b6 40 02       	movzx  rax,BYTE PTR [r8+0x2]
 74c:	48 c1 e0 10          	shl    rax,0x10
 750:	48 31 d0             	xor    rax,rdx
 753:	4c 0f b6 6f 05       	movzx  r13,BYTE PTR [rdi+0x5]
 758:	49 c1 e5 28          	shl    r13,0x28
 75c:	4d 09 f5             	or     r13,r14
 75f:	48 0f b6 56 04       	movzx  rdx,BYTE PTR [rsi+0x4]
 764:	48 c1 e2 20          	shl    rdx,0x20
 768:	48 09 da             	or     rdx,rbx
 76b:	48 0f b6 5e 05       	movzx  rbx,BYTE PTR [rsi+0x5]
 770:	48 c1 e3 28          	shl    rbx,0x28
 774:	48 09 d3             	or     rbx,rdx
 777:	48 0f b6 56 06       	movzx  rdx,BYTE PTR [rsi+0x6]
 77c:	48 c1 e2 30          	shl    rdx,0x30
 780:	48 09 da             	or     rdx,rbx
 783:	4c 0f b6 77 06       	movzx  r14,BYTE PTR [rdi+0x6]
 788:	49 c1 e6 30          	shl    r14,0x30
 78c:	4d 09 ee             	or     r14,r13
 78f:	48 89 cb             	mov    rbx,rcx
 792:	48 01 c3             	add    rbx,rax
 795:	48 83 c3 02          	add    rbx,0x2
 799:	48 89 d8             	mov    rax,rbx
 79c:	48 c1 e8 3d          	shr    rax,0x3d
 7a0:	48 c1 e3 03          	shl    rbx,0x3
 7a4:	48 09 c3             	or     rbx,rax
 7a7:	48 0f b6 47 07       	movzx  rax,BYTE PTR [rdi+0x7]
 7ac:	48 c1 e0 38          	shl    rax,0x38
 7b0:	4c 09 f0             	or     rax,r14
 7b3:	48 0f b6 7e 07       	movzx  rdi,BYTE PTR [rsi+0x7]
 7b8:	48 c1 e7 38          	shl    rdi,0x38
 7bc:	48 09 d7             	or     rdi,rdx
 7bf:	49 0f b6 70 03       	movzx  rsi,BYTE PTR [r8+0x3]
 7c4:	48 c1 e6 18          	shl    rsi,0x18
 7c8:	48 31 de             	xor    rsi,rbx
 7cb:	48 89 ca             	mov    rdx,rcx
 7ce:	48 01 f2             	add    rdx,rsi
 7d1:	48 83 c2 03          	add    rdx,0x3
 7d5:	48 89 d6             	mov    rsi,rdx
 7d8:	48 c1 ee 3c          	shr    rsi,0x3c
 7dc:	48 c1 e2 04          	shl    rdx,0x4
 7e0:	48 09 f2             	or     rdx,rsi
 7e3:	49 0f b6 70 04       	movzx  rsi,BYTE PTR [r8+0x4]
 7e8:	48 c1 e6 20          	shl    rsi,0x20
 7ec:	48 31 d6             	xor    rsi,rdx
 7ef:	48 89 ca             	mov    rdx,rcx
 7f2:	48 01 f2             	add    rdx,rsi
 7f5:	48 83 c2 04          	add    rdx,0x4
 7f9:	48 89 d6             	mov    rsi,rdx
 7fc:	48 c1 ee 3b          	shr    rsi,0x3b
 800:	48 c1 e2 05          	shl    rdx,0x5
 804:	48 09 f2             	or     rdx,rsi
 807:	49 0f b6 70 05       	movzx  rsi,BYTE PTR [r8+0x5]
 80c:	48 c1 e6 28          	shl    rsi,0x28
 810:	48 31 d6             	xor    rsi,rdx
 813:	48 89 ca             	mov    rdx,rcx
 816:	48 01 f2             	add    rdx,rsi
 819:	48 83 c2 05          	add    rdx,0x5
 81d:	48 89 d6             	mov    rsi,rdx
 820:	48 c1 ee 3a          	shr    rsi,0x3a
 824:	48 c1 e2 06          	shl    rdx,0x6
 828:	48 09 f2             	or     rdx,rsi
 82b:	49 0f b6 70 06       	movzx  rsi,BYTE PTR [r8+0x6]
 830:	48 c1 e6 30          	shl    rsi,0x30
 834:	48 31 d6             	xor    rsi,rdx
 837:	48 89 ca             	mov    rdx,rcx
 83a:	48 01 f2             	add    rdx,rsi
 83d:	48 83 c2 06          	add    rdx,0x6
 841:	48 89 d6             	mov    rsi,rdx
 844:	48 c1 ee 39          	shr    rsi,0x39
 848:	48 c1 e2 07          	shl    rdx,0x7
 84c:	48 09 f2             	or     rdx,rsi
 84f:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 854:	48 c1 e6 38          	shl    rsi,0x38
 858:	48 31 d6             	xor    rsi,rdx
 85b:	48 01 f1             	add    rcx,rsi
 85e:	48 83 c1 07          	add    rcx,0x7
 862:	48 89 ce             	mov    rsi,rcx
 865:	48 c1 ee 38          	shr    rsi,0x38
 869:	48 c1 e1 08          	shl    rcx,0x8
 86d:	48 09 f1             	or     rcx,rsi
 870:	48 01 cf             	add    rdi,rcx
 873:	48 31 f8             	xor    rax,rdi
 876:	41 5e                	pop    r14
 878:	41 5d                	pop    r13
 87a:	5b                   	pop    rbx
 87b:	c9                   	leave
 87c:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	44 8b 07             	mov    r8d,DWORD PTR [rdi]
   7:	8b 4f 04             	mov    ecx,DWORD PTR [rdi+0x4]
   a:	41 39 c8             	cmp    r8d,ecx
   d:	76 03                	jbe    0x12
   f:	31 c0                	xor    eax,eax
  11:	c3                   	ret
  12:	41 57                	push   r15
  14:	41 56                	push   r14
  16:	53                   	push   rbx
  17:	48 81 ec d0 3f 00 00 	sub    rsp,0x3fd0
  1e:	49 8d 50 08          	lea    rdx,[r8+0x8]
  22:	48 89 94 24 70 3f 00 	mov    QWORD PTR [rsp+0x3f70],rdx
  29:	00 
  2a:	31 c0                	xor    eax,eax
  2c:	48 39 ca             	cmp    rdx,rcx
  2f:	0f 87 23 03 00 00    	ja     0x358
  35:	49 8d 90 90 01 00 00 	lea    rdx,[r8+0x190]
  3c:	48 39 ca             	cmp    rdx,rcx
  3f:	0f 87 13 03 00 00    	ja     0x358
  45:	41 83 78 08 10       	cmp    DWORD PTR [r8+0x8],0x10
  4a:	0f 85 fc 02 00 00    	jne    0x34c
  50:	41 83 78 0c 18       	cmp    DWORD PTR [r8+0xc],0x18
  55:	0f 85 f1 02 00 00    	jne    0x34c
  5b:	4c 89 84 24 68 3f 00 	mov    QWORD PTR [rsp+0x3f68],r8
  62:	00 
  63:	48 be d3 08 a3 85 88 	movabs rsi,0x243f6a8885a308d3
  6a:	6a 3f 24 
  6d:	45 31 c9             	xor    r9d,r9d
  70:	48 b8 00 00 00 00 0c 	movabs rax,0xc00000000
  77:	00 00 00 
  7a:	48 b9 eb 11 31 13 bb 	movabs rcx,0x94d049bb133111eb
  81:	49 d0 94 
  84:	31 d2                	xor    edx,edx
  86:	31 ff                	xor    edi,edi
  88:	e9 95 00 00 00       	jmp    0x122
  8d:	0f 1f 00             	nop    DWORD PTR [rax]
  90:	4a 8b 5c 0f 10       	mov    rbx,QWORD PTR [rdi+r9*1+0x10]
  95:	4d 8b 4c 39 18       	mov    r9,QWORD PTR [r9+rdi*1+0x18]
  9a:	48 83 c7 18          	add    rdi,0x18
  9e:	45 89 d0             	mov    r8d,r10d
  a1:	4d 89 c3             	mov    r11,r8
  a4:	49 c1 e3 11          	shl    r11,0x11
  a8:	4d 01 cb             	add    r11,r9
  ab:	4d 89 da             	mov    r10,r11
  ae:	49 31 da             	xor    r10,rbx
  b1:	c4 43 fb f0 d2 3b    	rorx   r10,r10,0x3b
  b7:	48 31 de             	xor    rsi,rbx
  ba:	49 c1 e9 02          	shr    r9,0x2
  be:	48 8d 1c f5 00 00 00 	lea    rbx,[rsi*8+0x0]
  c5:	00 
  c6:	4c 31 cb             	xor    rbx,r9
  c9:	4c 8d 0c 33          	lea    r9,[rbx+rsi*1]
  cd:	c4 43 fb f0 c9 35    	rorx   r9,r9,0x35
  d3:	4d 01 d1             	add    r9,r10
  d6:	4c 31 de             	xor    rsi,r11
  d9:	49 c1 eb 07          	shr    r11,0x7
  dd:	4d 31 cb             	xor    r11,r9
  e0:	49 01 db             	add    r11,rbx
  e3:	49 31 f3             	xor    r11,rsi
  e6:	be 01 00 00 00       	mov    esi,0x1
  eb:	41 89 d1             	mov    r9d,edx
  ee:	41 80 e1 38          	and    r9b,0x38
  f2:	c4 e2 b1 f7 f6       	shlx   rsi,rsi,r9
  f7:	4c 01 c6             	add    rsi,r8
  fa:	4c 31 de             	xor    rsi,r11
  fd:	4c 8b 84 24 68 3f 00 	mov    r8,QWORD PTR [rsp+0x3f68]
 104:	00 
 105:	4c 8b 8c 24 78 3f 00 	mov    r9,QWORD PTR [rsp+0x3f78]
 10c:	00 
 10d:	49 83 c1 10          	add    r9,0x10
 111:	48 83 c2 08          	add    rdx,0x8
 115:	48 81 fa 80 00 00 00 	cmp    rdx,0x80
 11c:	0f 84 2e 02 00 00    	je     0x350
 122:	46 8b 54 07 14       	mov    r10d,DWORD PTR [rdi+r8*1+0x14]
 127:	4d 31 ca             	xor    r10,r9
 12a:	46 0f b6 44 07 10    	movzx  r8d,BYTE PTR [rdi+r8*1+0x10]
 130:	41 83 e0 03          	and    r8d,0x3
 134:	4c 89 8c 24 78 3f 00 	mov    QWORD PTR [rsp+0x3f78],r9
 13b:	00 
 13c:	4c 8b 8c 24 70 3f 00 	mov    r9,QWORD PTR [rsp+0x3f70]
 143:	00 
 144:	41 83 f8 02          	cmp    r8d,0x2
 148:	74 66                	je     0x1b0
 14a:	41 83 f8 01          	cmp    r8d,0x1
 14e:	0f 84 3c ff ff ff    	je     0x90
 154:	45 85 c0             	test   r8d,r8d
 157:	0f 85 03 01 00 00    	jne    0x260
 15d:	4e 8b 5c 0f 10       	mov    r11,QWORD PTR [rdi+r9*1+0x10]
 162:	45 89 d0             	mov    r8d,r10d
 165:	4c 01 c6             	add    rsi,r8
 168:	49 03 74 39 18       	add    rsi,QWORD PTR [r9+rdi*1+0x18]
 16d:	48 83 c7 18          	add    rdi,0x18
 171:	4f 8d 0c 5b          	lea    r9,[r11+r11*2]
 175:	4c 01 ce             	add    rsi,r9
 178:	4d 89 c1             	mov    r9,r8
 17b:	49 c1 e1 0b          	shl    r9,0xb
 17f:	49 01 f1             	add    r9,rsi
 182:	41 80 e2 07          	and    r10b,0x7
 186:	44 89 d3             	mov    ebx,r10d
 189:	f6 d3                	not    bl
 18b:	c4 c2 e3 f7 d9       	shrx   rbx,r9,rbx
 190:	41 fe c2             	inc    r10b
 193:	c4 42 a9 f7 c9       	shlx   r9,r9,r10
 198:	49 09 d9             	or     r9,rbx
 19b:	49 31 f1             	xor    r9,rsi
 19e:	49 c1 eb 03          	shr    r11,0x3
 1a2:	4d 01 cb             	add    r11,r9
 1a5:	31 f6                	xor    esi,esi
 1a7:	e9 3f ff ff ff       	jmp    0xeb
 1ac:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
 1b0:	4c 89 94 24 38 3f 00 	mov    QWORD PTR [rsp+0x3f38],r10
 1b7:	00 
 1b8:	48 8d 5f 18          	lea    rbx,[rdi+0x18]
 1bc:	49 03 74 39 10       	add    rsi,QWORD PTR [r9+rdi*1+0x10]
 1c1:	45 0f b6 5c 39 08    	movzx  r11d,BYTE PTR [r9+rdi*1+0x8]
 1c7:	4d 8b 74 39 18       	mov    r14,QWORD PTR [r9+rdi*1+0x18]
 1cc:	48 c1 e7 20          	shl    rdi,0x20
 1d0:	48 01 c7             	add    rdi,rax
 1d3:	49 89 f8             	mov    r8,rdi
 1d6:	49 c1 f8 20          	sar    r8,0x20
 1da:	48 c1 ef 20          	shr    rdi,0x20
 1de:	41 0f b6 3c 39       	movzx  edi,BYTE PTR [r9+rdi*1]
 1e3:	c1 e7 09             	shl    edi,0x9
 1e6:	47 0f b6 7c 01 01    	movzx  r15d,BYTE PTR [r9+r8*1+0x1]
 1ec:	41 c1 e7 11          	shl    r15d,0x11
 1f0:	41 09 ff             	or     r15d,edi
 1f3:	43 0f b6 7c 01 02    	movzx  edi,BYTE PTR [r9+r8*1+0x2]
 1f9:	48 c1 e7 19          	shl    rdi,0x19
 1fd:	4c 09 ff             	or     rdi,r15
 200:	47 0f b6 4c 01 03    	movzx  r9d,BYTE PTR [r9+r8*1+0x3]
 206:	49 c1 e1 21          	shl    r9,0x21
 20a:	49 09 f9             	or     r9,rdi
 20d:	45 89 d0             	mov    r8d,r10d
 210:	41 80 e3 07          	and    r11b,0x7
 214:	c4 c2 a1 f7 f8       	shlx   rdi,r8,r11
 219:	49 31 f6             	xor    r14,rsi
 21c:	45 89 da             	mov    r10d,r11d
 21f:	41 f6 d2             	not    r10b
 222:	c4 42 ab f7 d6       	shrx   r10,r14,r10
 227:	41 fe c3             	inc    r11b
 22a:	c4 42 a1 f7 de       	shlx   r11,r14,r11
 22f:	4d 09 d3             	or     r11,r10
 232:	49 31 f1             	xor    r9,rsi
 235:	4d 31 d9             	xor    r9,r11
 238:	49 01 f9             	add    r9,rdi
 23b:	49 c1 eb 05          	shr    r11,0x5
 23f:	4d 31 cb             	xor    r11,r9
 242:	49 01 f3             	add    r11,rsi
 245:	be 02 00 00 00       	mov    esi,0x2
 24a:	48 89 df             	mov    rdi,rbx
 24d:	e9 99 fe ff ff       	jmp    0xeb
 252:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 259:	1f 84 00 00 00 00 00 
 260:	45 0f b6 44 39 08    	movzx  r8d,BYTE PTR [r9+rdi*1+0x8]
 266:	48 31 ce             	xor    rsi,rcx
 269:	4c 31 c6             	xor    rsi,r8
 26c:	45 89 d0             	mov    r8d,r10d
 26f:	4c 01 c6             	add    rsi,r8
 272:	c4 e3 fb f0 f6 3f    	rorx   rsi,rsi,0x3f
 278:	45 0f b6 54 39 09    	movzx  r10d,BYTE PTR [r9+rdi*1+0x9]
 27e:	41 c1 e2 08          	shl    r10d,0x8
 282:	49 31 f2             	xor    r10,rsi
 285:	4b 8d 34 10          	lea    rsi,[r8+r10*1]
 289:	48 ff c6             	inc    rsi
 28c:	c4 e3 fb f0 f6 3e    	rorx   rsi,rsi,0x3e
 292:	45 0f b6 54 39 0a    	movzx  r10d,BYTE PTR [r9+rdi*1+0xa]
 298:	41 c1 e2 10          	shl    r10d,0x10
 29c:	49 31 f2             	xor    r10,rsi
 29f:	4b 8d 34 10          	lea    rsi,[r8+r10*1]
 2a3:	48 83 c6 02          	add    rsi,0x2
 2a7:	c4 e3 fb f0 f6 3d    	rorx   rsi,rsi,0x3d
 2ad:	45 0f b6 54 39 0b    	movzx  r10d,BYTE PTR [r9+rdi*1+0xb]
 2b3:	41 c1 e2 18          	shl    r10d,0x18
 2b7:	49 31 f2             	xor    r10,rsi
 2ba:	4b 8d 34 10          	lea    rsi,[r8+r10*1]
 2be:	48 83 c6 03          	add    rsi,0x3
 2c2:	c4 e3 fb f0 f6 3c    	rorx   rsi,rsi,0x3c
 2c8:	45 0f b6 54 39 0c    	movzx  r10d,BYTE PTR [r9+rdi*1+0xc]
 2ce:	49 c1 e2 20          	shl    r10,0x20
 2d2:	49 31 f2             	xor    r10,rsi
 2d5:	4b 8d 34 10          	lea    rsi,[r8+r10*1]
 2d9:	48 83 c6 04          	add    rsi,0x4
 2dd:	c4 e3 fb f0 f6 3b    	rorx   rsi,rsi,0x3b
 2e3:	45 0f b6 54 39 0d    	movzx  r10d,BYTE PTR [r9+rdi*1+0xd]
 2e9:	49 c1 e2 28          	shl    r10,0x28
 2ed:	49 31 f2             	xor    r10,rsi
 2f0:	4b 8d 34 10          	lea    rsi,[r8+r10*1]
 2f4:	48 83 c6 05          	add    rsi,0x5
 2f8:	c4 e3 fb f0 f6 3a    	rorx   rsi,rsi,0x3a
 2fe:	45 0f b6 54 39 0e    	movzx  r10d,BYTE PTR [r9+rdi*1+0xe]
 304:	49 c1 e2 30          	shl    r10,0x30
 308:	49 31 f2             	xor    r10,rsi
 30b:	4b 8d 34 10          	lea    rsi,[r8+r10*1]
 30f:	48 83 c6 06          	add    rsi,0x6
 313:	c4 e3 fb f0 f6 39    	rorx   rsi,rsi,0x39
 319:	45 0f b6 54 39 0f    	movzx  r10d,BYTE PTR [r9+rdi*1+0xf]
 31f:	49 c1 e2 38          	shl    r10,0x38
 323:	49 31 f2             	xor    r10,rsi
 326:	4b 8d 34 10          	lea    rsi,[r8+r10*1]
 32a:	48 83 c6 07          	add    rsi,0x7
 32e:	c4 63 fb f0 de 38    	rorx   r11,rsi,0x38
 334:	4d 03 5c 39 10       	add    r11,QWORD PTR [r9+rdi*1+0x10]
 339:	4d 33 5c 39 18       	xor    r11,QWORD PTR [r9+rdi*1+0x18]
 33e:	48 83 c7 18          	add    rdi,0x18
 342:	be 03 00 00 00       	mov    esi,0x3
 347:	e9 9f fd ff ff       	jmp    0xeb
 34c:	31 c0                	xor    eax,eax
 34e:	eb 08                	jmp    0x358
 350:	49 89 30             	mov    QWORD PTR [r8],rsi
 353:	b8 02 00 00 00       	mov    eax,0x2
 358:	48 81 c4 d0 3f 00 00 	add    rsp,0x3fd0
 35f:	5b                   	pop    rbx
 360:	41 5e                	pop    r14
 362:	41 5f                	pop    r15
 364:	c3                   	ret
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
    /* 0x1100: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1101: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1103: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1105: push   r13 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1107: push   r12 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1109: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110a: push   rax [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x110b: mov    r14,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_8, BPF_REG_1, 0),
    /* 0x110e: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1112: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1114: cmp    r14,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x1117: jbe    1128 <bpf_local_call_fanout_dispatch_xdp+0x28> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_8, BPF_REG_4, (16) - 1, 0),
    /* 0x1119: add    rsp,0x8 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x111d: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x111e: pop    r12 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1120: pop    r13 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1122: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1124: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1126: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1127: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x1128: lea    rdx,[r14+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_8, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112c: mov    QWORD PTR [rsp],rdx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(BPF_REG_3, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1130: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1133: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-19) - 1, 0),
    /* 0x1135: lea    rdx,[r14+0x190] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_8, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x113f: ja     1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-22) - 1, 0),
    /* 0x1141: cmp    DWORD PTR [r14+0x8],0x10 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1146: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_8, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 1, 16),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-26) - 1),
    /* 0x1148: cmp    DWORD PTR [r14+0xc],0x18 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x114d: jne    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_8, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 1, 24),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-30) - 1),
    /* 0x114f: movabs rdi,0x243f6a8885a308d3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x243f6a8885a308d3ULL),
    /* 0x1159: xor    r15d,r15d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115c: mov    r12d,0x17 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(HC_X86_R12, 23), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1162: xor    r13d,r13d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1165: jmp    11a1 <bpf_local_call_fanout_dispatch_xdp+0xa1> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (25) - 1),
    /* 0x1167: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1170: mov    rsi,QWORD PTR [rsp] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1174: mov    ecx,ebp [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1176: call   1260 <local_call_pressure> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(99),
    /* 0x117b: mov    ecx,r13d [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117e: and    cl,0x38 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1181: shl    rbx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1184: mov    edi,ebp [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_1, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1186: add    rdi,rbx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1189: xor    rdi,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x118c: add    r13,0x8 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1190: add    r15d,0x10 [exact-kop: add32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 16), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1194: add    r12,0x18 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1198: cmp    r13,0x80 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x119f: je     1200 <bpf_local_call_fanout_dispatch_xdp+0x100> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, (32) - 1, 128),
    /* 0x11a1: movzx  ebx,BYTE PTR [r14+r12*1-0x7] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_6, BPF_REG_8, HC_X86_R12, 0, -7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a7: and    ebx,0x3 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 3), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11aa: mov    ebp,DWORD PTR [r14+r12*1-0x3] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_RBP, BPF_REG_8, HC_X86_R12, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11af: xor    ebp,r15d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11b2: lea    rdx,[r12-0xf] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, HC_X86_R12, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11b7: cmp    rbx,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11bb: je     11e0 <bpf_local_call_fanout_dispatch_xdp+0xe0> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (9) - 1, 2),
    /* 0x11bd: cmp    ebx,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11c0: je     1170 <bpf_local_call_fanout_dispatch_xdp+0x70> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (-35) - 1, 1),
    /* 0x11c2: test   ebx,ebx [absorbed-control-flow: test folded into following ordinary BPF jne] */
    /* 0x11c4: jne    11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0> [exact-bpf: jne ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, (13) - 1, -1),
    /* 0x11c6: mov    rsi,QWORD PTR [rsp] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11ca: mov    ecx,ebp [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11cc: call   1210 <local_call_linear> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(19),
    /* 0x11d1: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-37) - 1),
    /* 0x11d3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11e0: mov    rsi,QWORD PTR [rsp] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11e4: mov    ecx,ebp [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e6: call   12b0 <local_call_crossload> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(97),
    /* 0x11eb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-43) - 1),
    /* 0x11ed: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: mov    rsi,QWORD PTR [rsp] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_MEM_PAYLOAD(BPF_REG_2, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11f4: mov    ecx,ebp [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f6: call   1340 <local_call_bytes> [abi-boundary: native direct call maps to BPF pseudo call] */
    HC_CALL(174),
    /* 0x11fb: jmp    117b <bpf_local_call_fanout_dispatch_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-49) - 1),
    /* 0x1200: mov    QWORD PTR [r14],rdi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(BPF_REG_1, BPF_REG_8, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1203: mov    eax,0x2 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1208: jmp    1119 <bpf_local_call_fanout_dispatch_xdp+0x19> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-99) - 1),
    /* 0x120d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1210: mov    r8d,ecx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1213: mov    ecx,edx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1215: mov    rax,QWORD PTR [rcx+rsi*1+0x8] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_0, BPF_REG_4, BPF_REG_2, 0, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x121a: lea    r9,[rax+rax*2] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_0, BPF_REG_0, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x121e: mov    edx,r8d [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1221: add    rdi,rdx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1224: add    r9,rdi [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1227: add    r9,QWORD PTR [rcx+rsi*1+0x10] [exact-kop: add64 SIB memory-source kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_R9, BPF_REG_4, BPF_REG_2, 0, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x122c: shl    rdx,0xb [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 11), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1230: add    rdx,r9 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1233: and    r8d,0x7 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1237: lea    ecx,[r8+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_5, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123b: mov    rsi,rdx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x123e: shl    rsi,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1241: not    r8b [exact-kop: notb reg kop] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1244: mov    ecx,r8d [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1247: shr    rdx,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x124a: or     rdx,rsi [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x124d: xor    rdx,r9 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1250: shr    rax,0x3 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 3), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1254: add    rax,rdx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1257: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x1258: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1260: mov    eax,edx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1262: mov    r8,QWORD PTR [rax+rsi*1+0x8] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_5, BPF_REG_0, BPF_REG_2, 0, 8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1267: mov    rdx,QWORD PTR [rax+rsi*1+0x10] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_3, BPF_REG_0, BPF_REG_2, 0, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x126c: xor    rdi,r8 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x126f: mov    eax,ecx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1271: shl    rax,0x11 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 17), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1275: add    rax,rdx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1278: lea    rcx,[rdi*8+0x0] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, 0, BPF_REG_1, 3, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1280: shr    rdx,0x2 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1284: xor    r8,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1287: rol    r8,0x5 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 5), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x128b: xor    rdx,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x128e: lea    rcx,[rdx+rdi*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_1, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1292: rol    rcx,0xb [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_4, BPF_REG_4, 11), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1296: add    rcx,r8 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1299: xor    rdi,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x129c: shr    rax,0x7 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x12a0: xor    rax,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12a3: add    rax,rdx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12a6: xor    rax,rdi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12a9: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x12aa: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x12b0: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x12b2: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x12b3: mov    r8d,ecx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b6: mov    eax,edx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b8: movzx  edx,BYTE PTR [rsi+rax*1] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_3, BPF_REG_2, BPF_REG_0, 0, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12bc: lea    rcx,[rax+0x4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 4), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12c0: movzx  r9d,BYTE PTR [rsi+rax*1+0x4] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_R9, BPF_REG_2, BPF_REG_0, 0, 4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12c6: movsxd r11,ecx [exact-bpf: movsxd reg32 via verifier-visible BPF sign extension] */
    HC_MOV64_REG(BPF_REG_6, BPF_REG_4),
    HC_ALU64_IMM(BPF_LSH, BPF_REG_6, 32),
    HC_ALU64_IMM(BPF_ARSH, BPF_REG_6, 32),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -424),
    /* 0x12c9: movzx  r10d,BYTE PTR [rsi+r11*1+0x1] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(HC_X86_R10, BPF_REG_2, HC_X86_R11, 0, 1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12cf: add    rdi,QWORD PTR [rsi+rax*1+0x8] [exact-kop: add64 SIB memory-source kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_2, BPF_REG_0, 0, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12d4: mov    rax,QWORD PTR [rsi+rax*1+0x10] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_0, BPF_REG_2, BPF_REG_0, 0, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12d9: xor    rax,rdi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12dc: and    dl,0x7 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x12df: lea    ecx,[rdx+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x12e2: mov    rbx,rax [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12e5: shl    rbx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x12e8: movzx  r14d,BYTE PTR [rsi+r11*1+0x2] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_8, BPF_REG_2, HC_X86_R11, 0, 2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ee: movzx  esi,BYTE PTR [rsi+r11*1+0x3] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_2, HC_X86_R11, 0, 3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f4: mov    ecx,edx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f6: not    cl [exact-kop: notb reg kop] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x12f8: shr    rax,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x12fb: or     rax,rbx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x12fe: shl    rsi,0x21 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 33), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1302: shl    r14,0x19 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 25), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1306: shl    r10d,0x11 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 17), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130a: shl    r9d,0x9 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 9), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130e: or     r9d,r10d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x1311: or     r9,r14 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1314: or     r9,rsi [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1317: xor    r9,rdi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x131a: xor    r9,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x131d: mov    esi,r8d [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1320: mov    ecx,edx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1322: shl    rsi,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1325: add    rsi,r9 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1328: shr    rax,0x5 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 5), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x132c: xor    rax,rsi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x132f: add    rax,rdi [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1332: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1333: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1335: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x1336: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x1340: mov    eax,ecx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1342: mov    ecx,edx [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1344: movzx  edx,BYTE PTR [rsi+rcx*1] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_3, BPF_REG_2, BPF_REG_4, 0, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1348: movabs r8,0x94d049bb133111eb [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 0x94d049bb133111ebULL),
    /* 0x1352: xor    r8,rdi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1355: xor    r8,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1358: add    r8,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x135b: rol    r8,1 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 1), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x135e: movzx  edx,BYTE PTR [rsi+rcx*1+0x1] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_3, BPF_REG_2, BPF_REG_4, 0, 1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1363: shl    edx,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1366: xor    rdx,r8 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1369: add    rdx,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x136c: inc    rdx [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x136f: rol    rdx,0x2 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1373: movzx  edi,BYTE PTR [rsi+rcx*1+0x2] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_2, BPF_REG_4, 0, 2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1378: shl    edi,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x137b: xor    rdi,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x137e: lea    rdx,[rax+rdi*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, BPF_REG_1, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1382: add    rdx,0x2 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1386: rol    rdx,0x3 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x138a: movzx  edi,BYTE PTR [rsi+rcx*1+0x3] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_2, BPF_REG_4, 0, 3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x138f: shl    edi,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1392: xor    rdi,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1395: lea    rdx,[rax+rdi*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, BPF_REG_1, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1399: add    rdx,0x3 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x139d: rol    rdx,0x4 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13a1: movzx  edi,BYTE PTR [rsi+rcx*1+0x4] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_2, BPF_REG_4, 0, 4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13a6: shl    rdi,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13aa: xor    rdi,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13ad: lea    rdx,[rax+rdi*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, BPF_REG_1, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x13b1: add    rdx,0x4 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13b5: rol    rdx,0x5 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13b9: movzx  edi,BYTE PTR [rsi+rcx*1+0x5] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_2, BPF_REG_4, 0, 5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13be: shl    rdi,0x28 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c2: xor    rdi,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c5: lea    rdx,[rax+rdi*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, BPF_REG_1, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x13c9: add    rdx,0x5 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13cd: rol    rdx,0x6 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13d1: movzx  edi,BYTE PTR [rsi+rcx*1+0x6] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_2, BPF_REG_4, 0, 6), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13d6: shl    rdi,0x30 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13da: xor    rdi,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13dd: lea    rdx,[rax+rdi*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, BPF_REG_1, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x13e1: add    rdx,0x6 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e5: rol    rdx,0x7 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_3, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x13e9: movzx  edi,BYTE PTR [rsi+rcx*1+0x7] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_2, BPF_REG_4, 0, 7), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x13ee: shl    rdi,0x38 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13f2: xor    rdi,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13f5: add    rax,rdi [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13f8: add    rax,0x7 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13fc: rol    rax,0x8 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1400: add    rax,QWORD PTR [rsi+rcx*1+0x8] [exact-kop: add64 SIB memory-source kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_0, BPF_REG_2, BPF_REG_4, 0, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1405: xor    rax,QWORD PTR [rsi+rcx*1+0x10] [exact-kop: xor64 SIB memory-source kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_0, BPF_REG_2, BPF_REG_4, 0, 16), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x140a: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
