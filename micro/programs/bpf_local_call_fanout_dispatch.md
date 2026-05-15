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

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

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
  ec:	e8 5b 01 00 00       	call   0x24c
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
 191:	e8 36 02 00 00       	call   0x3cc
 196:	e9 56 ff ff ff       	jmp    0xf1
 19b:	48 89 c7             	mov    rdi,rax
 19e:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 1a2:	4c 89 e9             	mov    rcx,r13
 1a5:	e8 9a 03 00 00       	call   0x544
 1aa:	e9 42 ff ff ff       	jmp    0xf1
 1af:	48 89 c7             	mov    rdi,rax
 1b2:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 1b6:	4c 89 e9             	mov    rcx,r13
 1b9:	e8 7e 05 00 00       	call   0x73c
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

/*
 * Semantic handcraft for bpf_local_call_fanout_dispatch.
 * Starts from verified kernel xlated BPF, restores verifier-facing XDP ctx
 * loads at the entry, converts dumped local-call off/func-id fields back to
 * loadable pseudo-call immediates, and replaces same-PC-count mov+add address
 * calculations with x86 leaq kinsns.
 */

static const struct bpf_insn program[] = {
    HC_RAW(0xb7, BPF_REG_0, BPF_REG_0, 0, 0), /* pc 0 */
    HC_RAW(0x61, BPF_REG_3, BPF_REG_1, 0, 0), /* pc 1 verifier-facing XDP ctx load restored */
    HC_RAW(0x61, BPF_REG_2, BPF_REG_1, 4, 0), /* pc 2 verifier-facing XDP ctx load restored */
    HC_RAW(0x2d, BPF_REG_3, BPF_REG_2, 115, 0), /* pc 3 */
    /* pc 4: xlated mov+add pair lowered to leaq kinsn; pc count preserved */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_1, -16, 0), /* pc 6 */
    HC_RAW(0x2d, BPF_REG_1, BPF_REG_2, 111, 0), /* pc 7 */
    /* pc 8: xlated mov+add pair lowered to leaq kinsn; pc count preserved */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_1, BPF_REG_2, 108, 0), /* pc 10 */
    HC_RAW(0x71, BPF_REG_1, BPF_REG_3, 9, 0), /* pc 11 */
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 8), /* pc 12 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_3, 8, 0), /* pc 13 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 14 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_3, 10, 0), /* pc 15 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 16), /* pc 16 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 17 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_3, 11, 0), /* pc 18 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 24), /* pc 19 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 20 */
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 32), /* pc 21 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 32), /* pc 22 */
    HC_RAW(0x55, BPF_REG_1, BPF_REG_0, 95, 16), /* pc 23 */
    HC_RAW(0x71, BPF_REG_1, BPF_REG_3, 13, 0), /* pc 24 */
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 8), /* pc 25 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_3, 12, 0), /* pc 26 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 27 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_3, 14, 0), /* pc 28 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 16), /* pc 29 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 30 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_3, 15, 0), /* pc 31 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 24), /* pc 32 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 33 */
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 32), /* pc 34 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 32), /* pc 35 */
    HC_RAW(0x55, BPF_REG_1, BPF_REG_0, 82, 24), /* pc 36 */
    HC_RAW(0x18, BPF_REG_0, BPF_REG_0, 0, -2052912941), /* pc 37 */
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 608135816), /* pc 38 */
    HC_RAW(0xb7, BPF_REG_9, BPF_REG_0, 0, 0), /* pc 39 */
    HC_RAW(0xb7, BPF_REG_4, BPF_REG_0, 0, 0), /* pc 40 */
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 0), /* pc 41 */
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -24, 0), /* pc 42 */
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, 17, 0), /* pc 43 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 44 */
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -16, 0), /* pc 45 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_7, 0, 0), /* pc 46 */
    HC_RAW(0x85, BPF_REG_0, BPF_REG_1, 0, 72), /* pc 47 pseudo-call target restored from dumped off field */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_8, 0, 0), /* pc 48 */
    HC_RAW(0x57, BPF_REG_1, BPF_REG_0, 0, 56), /* pc 49 */
    HC_RAW(0x6f, BPF_REG_6, BPF_REG_1, 0, 0), /* pc 50 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 32), /* pc 51 */
    HC_RAW(0x77, BPF_REG_7, BPF_REG_0, 0, 32), /* pc 52 */
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_7, 0, 0), /* pc 53 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_6, 0, 0), /* pc 54 */
    HC_RAW(0x07, BPF_REG_9, BPF_REG_0, 0, 24), /* pc 55 */
    HC_RAW(0x79, BPF_REG_4, BPF_REG_10, -8, 0), /* pc 56 */
    HC_RAW(0x07, BPF_REG_4, BPF_REG_0, 0, 16), /* pc 57 */
    HC_RAW(0x07, BPF_REG_8, BPF_REG_0, 0, 8), /* pc 58 */
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -24, 0), /* pc 59 */
    HC_RAW(0x15, BPF_REG_8, BPF_REG_0, 36, 128), /* pc 60 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_3, 0, 0), /* pc 61 */
    HC_RAW(0x0f, BPF_REG_1, BPF_REG_9, 0, 0), /* pc 62 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_1, 21, 0), /* pc 63 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 8), /* pc 64 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 20, 0), /* pc 65 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_2, 0, 0), /* pc 66 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 22, 0), /* pc 67 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 16), /* pc 68 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_2, 0, 0), /* pc 69 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 23, 0), /* pc 70 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 24), /* pc 71 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_2, 0, 0), /* pc 72 */
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_4, 0, 0), /* pc 73 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_9, 0, 0), /* pc 74 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 8), /* pc 75 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_1, 16, 0), /* pc 76 */
    HC_RAW(0x57, BPF_REG_6, BPF_REG_0, 0, 3), /* pc 77 */
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_4, -8, 0), /* pc 78 */
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, 7, 2), /* pc 79 */
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, -37, 1), /* pc 80 */
    HC_RAW(0x55, BPF_REG_6, BPF_REG_0, 10, 0), /* pc 81 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 82 */
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -16, 0), /* pc 83 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_7, 0, 0), /* pc 84 */
    HC_RAW(0x85, BPF_REG_0, BPF_REG_1, 0, 118), /* pc 85 pseudo-call target restored from dumped off field */
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, -39, 0), /* pc 86 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 87 */
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -16, 0), /* pc 88 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_7, 0, 0), /* pc 89 */
    HC_RAW(0x85, BPF_REG_0, BPF_REG_1, 0, 191), /* pc 90 pseudo-call target restored from dumped off field */
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, -44, 0), /* pc 91 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 92 */
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -16, 0), /* pc 93 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_7, 0, 0), /* pc 94 */
    HC_RAW(0x85, BPF_REG_0, BPF_REG_1, 0, 291), /* pc 95 pseudo-call target restored from dumped off field */
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, -49, 0), /* pc 96 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 97 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 56), /* pc 98 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_1, 7, 0), /* pc 99 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 100 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 48), /* pc 101 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_1, 6, 0), /* pc 102 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 103 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 40), /* pc 104 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_1, 5, 0), /* pc 105 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 106 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 32), /* pc 107 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_1, 4, 0), /* pc 108 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 109 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 24), /* pc 110 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_1, 3, 0), /* pc 111 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 112 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 16), /* pc 113 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_1, 2, 0), /* pc 114 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_0, 0, 0), /* pc 115 */
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 8), /* pc 116 */
    HC_RAW(0x73, BPF_REG_3, BPF_REG_0, 1, 0), /* pc 117 */
    HC_RAW(0xb7, BPF_REG_0, BPF_REG_0, 0, 2), /* pc 118 */
    HC_RAW(0x95, BPF_REG_0, BPF_REG_0, 0, 0), /* pc 119 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 120 */
    HC_RAW(0x07, BPF_REG_0, BPF_REG_0, 0, 8), /* pc 121 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 16), /* pc 122 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 123 */
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 124 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0), /* pc 125 */
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_3, 0, 0), /* pc 126 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 32), /* pc 127 */
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 32), /* pc 128 */
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_0, 0, 0), /* pc 129 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_2, 1, 0), /* pc 130 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 8), /* pc 131 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 132 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 133 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 1, 0), /* pc 134 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8), /* pc 135 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_5, 0, 0), /* pc 136 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 137 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_5, 2, 0), /* pc 138 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 16), /* pc 139 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_6, 0, 0), /* pc 140 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 2, 0), /* pc 141 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 16), /* pc 142 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_0, 0, 0), /* pc 143 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_2, 3, 0), /* pc 144 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 24), /* pc 145 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 146 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_2, 4, 0), /* pc 147 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 32), /* pc 148 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_7, 0, 0), /* pc 149 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 3, 0), /* pc 150 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 24), /* pc 151 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 152 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_5, 4, 0), /* pc 153 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 32), /* pc 154 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 155 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_5, 5, 0), /* pc 156 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 40), /* pc 157 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_7, 0, 0), /* pc 158 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 5, 0), /* pc 159 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 40), /* pc 160 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_0, 0, 0), /* pc 161 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_2, 6, 0), /* pc 162 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 48), /* pc 163 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 164 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_2, 7, 0), /* pc 165 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 56), /* pc 166 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_7, 0, 0), /* pc 167 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 6, 0), /* pc 168 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 48), /* pc 169 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 170 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 7, 0), /* pc 171 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 56), /* pc 172 */
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_6, 0, 0), /* pc 173 */
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 32), /* pc 174 */
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 32), /* pc 175 */
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 17), /* pc 176 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 177 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_4, 0, 0), /* pc 178 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_3, 0, 0), /* pc 179 */
    HC_RAW(0xaf, BPF_REG_4, BPF_REG_0, 0, 0), /* pc 180 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_4, 0, 0), /* pc 181 */
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 59), /* pc 182 */
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 5), /* pc 183 */
    HC_RAW(0x4f, BPF_REG_4, BPF_REG_5, 0, 0), /* pc 184 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_1, 0, 0), /* pc 185 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2), /* pc 186 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 187 */
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 3), /* pc 188 */
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_1, 0, 0), /* pc 189 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 190 */
    HC_RAW(0x0f, BPF_REG_1, BPF_REG_0, 0, 0), /* pc 191 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_1, 0, 0), /* pc 192 */
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 53), /* pc 193 */
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 11), /* pc 194 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_5, 0, 0), /* pc 195 */
    HC_RAW(0x0f, BPF_REG_1, BPF_REG_4, 0, 0), /* pc 196 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_3, 0, 0), /* pc 197 */
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 7), /* pc 198 */
    HC_RAW(0xaf, BPF_REG_1, BPF_REG_4, 0, 0), /* pc 199 */
    HC_RAW(0x0f, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 200 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_1, 0, 0), /* pc 201 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 202 */
    HC_RAW(0x95, BPF_REG_0, BPF_REG_0, 0, 0), /* pc 203 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 204 */
    HC_RAW(0x07, BPF_REG_0, BPF_REG_0, 0, 16), /* pc 205 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 8), /* pc 206 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 207 */
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 208 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0), /* pc 209 */
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_3, 0, 0), /* pc 210 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 32), /* pc 211 */
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 32), /* pc 212 */
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_0, 0, 0), /* pc 213 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 1, 0), /* pc 214 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 8), /* pc 215 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_2, 0, 0), /* pc 216 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_0, 0, 0), /* pc 217 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 1, 0), /* pc 218 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 8), /* pc 219 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 0, 0), /* pc 220 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_6, 0, 0), /* pc 221 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 2, 0), /* pc 222 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 16), /* pc 223 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_0, 0, 0), /* pc 224 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 3, 0), /* pc 225 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 24), /* pc 226 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_6, 0, 0), /* pc 227 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 2, 0), /* pc 228 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 16), /* pc 229 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 230 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_2, 3, 0), /* pc 231 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 24), /* pc 232 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 233 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 4, 0), /* pc 234 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 235 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_7, 0, 0), /* pc 236 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 4, 0), /* pc 237 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 32), /* pc 238 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_0, 0, 0), /* pc 239 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_5, 5, 0), /* pc 240 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 40), /* pc 241 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 242 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 6, 0), /* pc 243 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 48), /* pc 244 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_7, 0, 0), /* pc 245 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 5, 0), /* pc 246 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 40), /* pc 247 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 248 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 6, 0), /* pc 249 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 48), /* pc 250 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_6, 0, 0), /* pc 251 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 7, 0), /* pc 252 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 56), /* pc 253 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 254 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 7, 0), /* pc 255 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 56), /* pc 256 */
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_0, 0, 0), /* pc 257 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_4, 0, 0), /* pc 258 */
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 32), /* pc 259 */
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 32), /* pc 260 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_5, 0, 0), /* pc 261 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_1, 0, 0), /* pc 262 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 263 */
    HC_RAW(0x27, BPF_REG_1, BPF_REG_0, 0, 3), /* pc 264 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_1, 0, 0), /* pc 265 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_6, 0, 0), /* pc 266 */
    HC_RAW(0x57, BPF_REG_4, BPF_REG_0, 0, 7), /* pc 267 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_4, 0, 0), /* pc 268 */
    HC_RAW(0x07, BPF_REG_1, BPF_REG_0, 0, 1), /* pc 269 */
    HC_RAW(0xa7, BPF_REG_4, BPF_REG_0, 0, 63), /* pc 270 */
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 11), /* pc 271 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 272 */
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_5, 0, 0), /* pc 273 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_0, 0, 0), /* pc 274 */
    HC_RAW(0x7f, BPF_REG_5, BPF_REG_4, 0, 0), /* pc 275 */
    HC_RAW(0x6f, BPF_REG_0, BPF_REG_1, 0, 0), /* pc 276 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_5, 0, 0), /* pc 277 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 278 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 3), /* pc 279 */
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_2, 0, 0), /* pc 280 */
    HC_RAW(0x95, BPF_REG_0, BPF_REG_0, 0, 0), /* pc 281 */
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_4, -8, 0), /* pc 282 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_3, 0, 0), /* pc 283 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_4, 0, 0), /* pc 284 */
    HC_RAW(0x07, BPF_REG_5, BPF_REG_0, 0, 8), /* pc 285 */
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 32), /* pc 286 */
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 32), /* pc 287 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_2, 0, 0), /* pc 288 */
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_5, 0, 0), /* pc 289 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_0, 1, 0), /* pc 290 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8), /* pc 291 */
    HC_RAW(0x71, BPF_REG_5, BPF_REG_0, 0, 0), /* pc 292 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_5, 0, 0), /* pc 293 */
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_4, 0, 0), /* pc 294 */
    HC_RAW(0x07, BPF_REG_7, BPF_REG_0, 0, 16), /* pc 295 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 32), /* pc 296 */
    HC_RAW(0x77, BPF_REG_7, BPF_REG_0, 0, 32), /* pc 297 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0), /* pc 298 */
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_7, 0, 0), /* pc 299 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_5, 1, 0), /* pc 300 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 8), /* pc 301 */
    HC_RAW(0x71, BPF_REG_8, BPF_REG_5, 0, 0), /* pc 302 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_8, 0, 0), /* pc 303 */
    HC_RAW(0x71, BPF_REG_9, BPF_REG_5, 2, 0), /* pc 304 */
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 16), /* pc 305 */
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_7, 0, 0), /* pc 306 */
    HC_RAW(0x71, BPF_REG_8, BPF_REG_5, 3, 0), /* pc 307 */
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 24), /* pc 308 */
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_9, 0, 0), /* pc 309 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_0, 2, 0), /* pc 310 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 16), /* pc 311 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 312 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_0, 3, 0), /* pc 313 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 24), /* pc 314 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_7, 0, 0), /* pc 315 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_0, 4, 0), /* pc 316 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 32), /* pc 317 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 318 */
    HC_RAW(0x71, BPF_REG_9, BPF_REG_5, 4, 0), /* pc 319 */
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 32), /* pc 320 */
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_8, 0, 0), /* pc 321 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 322 */
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 323 */
    HC_RAW(0x07, BPF_REG_4, BPF_REG_0, 0, 4), /* pc 324 */
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 32), /* pc 325 */
    HC_RAW(0xbf, BPF_REG_6, BPF_REG_4, 0, 0), /* pc 326 */
    HC_RAW(0xc7, BPF_REG_6, BPF_REG_0, 0, 32), /* pc 327 */
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 32), /* pc 328 */
    HC_RAW(0xbf, BPF_REG_8, BPF_REG_2, 0, 0), /* pc 329 */
    HC_RAW(0x0f, BPF_REG_8, BPF_REG_4, 0, 0), /* pc 330 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_2, 0, 0), /* pc 331 */
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_3, 0, 0), /* pc 332 */
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_6, 0, 0), /* pc 333 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_5, 5, 0), /* pc 334 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 40), /* pc 335 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_9, 0, 0), /* pc 336 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_0, 5, 0), /* pc 337 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 40), /* pc 338 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_7, 0, 0), /* pc 339 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_0, 6, 0), /* pc 340 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 48), /* pc 341 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 342 */
    HC_RAW(0x71, BPF_REG_9, BPF_REG_0, 7, 0), /* pc 343 */
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 56), /* pc 344 */
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_7, 0, 0), /* pc 345 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 6, 0), /* pc 346 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 48), /* pc 347 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 348 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_8, 0, 0), /* pc 349 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 9), /* pc 350 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_2, 1, 0), /* pc 351 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 17), /* pc 352 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_3, 0, 0), /* pc 353 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 2, 0), /* pc 354 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 25), /* pc 355 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_3, 0, 0), /* pc 356 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_2, 3, 0), /* pc 357 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 33), /* pc 358 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_2, 0, 0), /* pc 359 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 7, 0), /* pc 360 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 56), /* pc 361 */
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_0, 0, 0), /* pc 362 */
    HC_RAW(0x0f, BPF_REG_9, BPF_REG_1, 0, 0), /* pc 363 */
    HC_RAW(0x71, BPF_REG_1, BPF_REG_4, 0, 0), /* pc 364 */
    HC_RAW(0x57, BPF_REG_1, BPF_REG_0, 0, 7), /* pc 365 */
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -8, 0), /* pc 366 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 367 */
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 368 */
    HC_RAW(0x6f, BPF_REG_3, BPF_REG_1, 0, 0), /* pc 369 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_3, 0, 0), /* pc 370 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_1, 0, 0), /* pc 371 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 1), /* pc 372 */
    HC_RAW(0xa7, BPF_REG_1, BPF_REG_0, 0, 63), /* pc 373 */
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_9, 0, 0), /* pc 374 */
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_2, 0, 0), /* pc 375 */
    HC_RAW(0x7f, BPF_REG_4, BPF_REG_1, 0, 0), /* pc 376 */
    HC_RAW(0x6f, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 377 */
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_4, 0, 0), /* pc 378 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_9, 0, 0), /* pc 379 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_7, 0, 0), /* pc 380 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_2, 0, 0), /* pc 381 */
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_5, 0, 0), /* pc 382 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 5), /* pc 383 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_2, 0, 0), /* pc 384 */
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_9, 0, 0), /* pc 385 */
    HC_RAW(0x95, BPF_REG_0, BPF_REG_0, 0, 0), /* pc 386 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 387 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 32), /* pc 388 */
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 32), /* pc 389 */
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0), /* pc 390 */
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_0, 0, 0), /* pc 391 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 0, 0), /* pc 392 */
    HC_RAW(0xaf, BPF_REG_6, BPF_REG_1, 0, 0), /* pc 393 */
    HC_RAW(0x18, BPF_REG_1, BPF_REG_0, 0, 321982955), /* pc 394 */
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1798288965), /* pc 395 */
    HC_RAW(0xaf, BPF_REG_6, BPF_REG_1, 0, 0), /* pc 396 */
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 32), /* pc 397 */
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 32), /* pc 398 */
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_4, 0, 0), /* pc 399 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_6, 0, 0), /* pc 400 */
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 63), /* pc 401 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 1), /* pc 402 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_1, 0, 0), /* pc 403 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 1, 0), /* pc 404 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 8), /* pc 405 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_6, 0, 0), /* pc 406 */
    HC_RAW(0xbf, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 407 */
    HC_RAW(0x07, BPF_REG_6, BPF_REG_0, 0, 16), /* pc 408 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 32), /* pc 409 */
    HC_RAW(0x77, BPF_REG_6, BPF_REG_0, 0, 32), /* pc 410 */
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_2, 0, 0), /* pc 411 */
    HC_RAW(0x0f, BPF_REG_1, BPF_REG_6, 0, 0), /* pc 412 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_1, 1, 0), /* pc 413 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 8), /* pc 414 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_1, 0, 0), /* pc 415 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 416 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_1, 2, 0), /* pc 417 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 16), /* pc 418 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_7, 0, 0), /* pc 419 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 8), /* pc 420 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 421 */
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 422 */
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 423 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_4, 0, 0), /* pc 424 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_0, 0, 0), /* pc 425 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 1), /* pc 426 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 427 */
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 62), /* pc 428 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 2), /* pc 429 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_0, 0, 0), /* pc 430 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_1, 3, 0), /* pc 431 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 24), /* pc 432 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_6, 0, 0), /* pc 433 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 1, 0), /* pc 434 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8), /* pc 435 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_2, 0, 0), /* pc 436 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_7, 0, 0), /* pc 437 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_2, 2, 0), /* pc 438 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 16), /* pc 439 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_6, 0, 0), /* pc 440 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 3, 0), /* pc 441 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 24), /* pc 442 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_7, 0, 0), /* pc 443 */
    HC_RAW(0x71, BPF_REG_8, BPF_REG_1, 4, 0), /* pc 444 */
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 32), /* pc 445 */
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_0, 0, 0), /* pc 446 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 2, 0), /* pc 447 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 16), /* pc 448 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_3, 0, 0), /* pc 449 */
    HC_RAW(0x71, BPF_REG_7, BPF_REG_1, 5, 0), /* pc 450 */
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 40), /* pc 451 */
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_8, 0, 0), /* pc 452 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 4, 0), /* pc 453 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 32), /* pc 454 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_6, 0, 0), /* pc 455 */
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 5, 0), /* pc 456 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 40), /* pc 457 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0), /* pc 458 */
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 6, 0), /* pc 459 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 48), /* pc 460 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_6, 0, 0), /* pc 461 */
    HC_RAW(0x71, BPF_REG_8, BPF_REG_1, 6, 0), /* pc 462 */
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 48), /* pc 463 */
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_7, 0, 0), /* pc 464 */
    HC_RAW(0xbf, BPF_REG_6, BPF_REG_4, 0, 0), /* pc 465 */
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_0, 0, 0), /* pc 466 */
    HC_RAW(0x07, BPF_REG_6, BPF_REG_0, 0, 2), /* pc 467 */
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_6, 0, 0), /* pc 468 */
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 61), /* pc 469 */
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 3), /* pc 470 */
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_0, 0, 0), /* pc 471 */
    HC_RAW(0x71, BPF_REG_0, BPF_REG_1, 7, 0), /* pc 472 */
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 56), /* pc 473 */
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_8, 0, 0), /* pc 474 */
    HC_RAW(0x71, BPF_REG_1, BPF_REG_2, 7, 0), /* pc 475 */
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 56), /* pc 476 */
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_3, 0, 0), /* pc 477 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 3, 0), /* pc 478 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 24), /* pc 479 */
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_6, 0, 0), /* pc 480 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_4, 0, 0), /* pc 481 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 482 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 3), /* pc 483 */
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 484 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 60), /* pc 485 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 4), /* pc 486 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 487 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 4, 0), /* pc 488 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 32), /* pc 489 */
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 490 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_4, 0, 0), /* pc 491 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 492 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 4), /* pc 493 */
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 494 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 59), /* pc 495 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 5), /* pc 496 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 497 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 5, 0), /* pc 498 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 40), /* pc 499 */
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 500 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_4, 0, 0), /* pc 501 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 502 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 5), /* pc 503 */
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 504 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 58), /* pc 505 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 6), /* pc 506 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 507 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 6, 0), /* pc 508 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 48), /* pc 509 */
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 510 */
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_4, 0, 0), /* pc 511 */
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 512 */
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, 6), /* pc 513 */
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 514 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 57), /* pc 515 */
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 7), /* pc 516 */
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0), /* pc 517 */
    HC_RAW(0x71, BPF_REG_2, BPF_REG_5, 7, 0), /* pc 518 */
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 56), /* pc 519 */
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_3, 0, 0), /* pc 520 */
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_2, 0, 0), /* pc 521 */
    HC_RAW(0x07, BPF_REG_4, BPF_REG_0, 0, 7), /* pc 522 */
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_4, 0, 0), /* pc 523 */
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 56), /* pc 524 */
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 8), /* pc 525 */
    HC_RAW(0x4f, BPF_REG_4, BPF_REG_2, 0, 0), /* pc 526 */
    HC_RAW(0x0f, BPF_REG_1, BPF_REG_4, 0, 0), /* pc 527 */
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_1, 0, 0), /* pc 528 */
    HC_RAW(0x95, BPF_REG_0, BPF_REG_0, 0, 0), /* pc 529 */
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
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
  1c:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  20:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 e1 01 00 00    	ja     0x20e
  2d:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
  31:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  35:	48 39 f7             	cmp    rdi,rsi
  38:	0f 87 d0 01 00 00    	ja     0x20e
  3e:	48 8d ba 90 01 00 00 	lea    rdi,[rdx+0x190]
  45:	48 39 f7             	cmp    rdi,rsi
  48:	0f 87 c0 01 00 00    	ja     0x20e
  4e:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  53:	48 c1 e7 08          	shl    rdi,0x8
  57:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5c:	48 09 f7             	or     rdi,rsi
  5f:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  64:	48 c1 e6 10          	shl    rsi,0x10
  68:	48 09 f7             	or     rdi,rsi
  6b:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  70:	48 c1 e6 18          	shl    rsi,0x18
  74:	48 09 f7             	or     rdi,rsi
  77:	48 c1 e7 20          	shl    rdi,0x20
  7b:	48 c1 ef 20          	shr    rdi,0x20
  7f:	48 83 ff 10          	cmp    rdi,0x10
  83:	0f 85 85 01 00 00    	jne    0x20e
  89:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  8e:	48 c1 e7 08          	shl    rdi,0x8
  92:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  97:	48 09 f7             	or     rdi,rsi
  9a:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  9f:	48 c1 e6 10          	shl    rsi,0x10
  a3:	48 09 f7             	or     rdi,rsi
  a6:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  ab:	48 c1 e6 18          	shl    rsi,0x18
  af:	48 09 f7             	or     rdi,rsi
  b2:	48 c1 e7 20          	shl    rdi,0x20
  b6:	48 c1 ef 20          	shr    rdi,0x20
  ba:	48 83 ff 18          	cmp    rdi,0x18
  be:	0f 85 4a 01 00 00    	jne    0x20e
  c4:	48 b8 d3 08 a3 85 88 	movabs rax,0x243f6a8885a308d3
  cb:	6a 3f 24 
  ce:	45 31 ff             	xor    r15d,r15d
  d1:	31 c9                	xor    ecx,ecx
  d3:	45 31 f6             	xor    r14d,r14d
  d6:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
  da:	eb 4a                	jmp    0x126
  dc:	48 89 c7             	mov    rdi,rax
  df:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
  e3:	4c 89 e9             	mov    rcx,r13
  e6:	e8 45 01 00 00       	call   0x230
  eb:	4c 89 f7             	mov    rdi,r14
  ee:	48 83 e7 38          	and    rdi,0x38
  f2:	c4 e2 c1 f7 db       	shlx   rbx,rbx,rdi
  f7:	49 c1 e5 20          	shl    r13,0x20
  fb:	49 c1 ed 20          	shr    r13,0x20
  ff:	4c 01 eb             	add    rbx,r13
 102:	48 31 d8             	xor    rax,rbx
 105:	49 83 c7 18          	add    r15,0x18
 109:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 10d:	48 83 c1 10          	add    rcx,0x10
 111:	49 83 c6 08          	add    r14,0x8
 115:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 119:	49 81 fe 80 00 00 00 	cmp    r14,0x80
 120:	0f 84 97 00 00 00    	je     0x1bd
 126:	48 89 d7             	mov    rdi,rdx
 129:	4c 01 ff             	add    rdi,r15
 12c:	4c 0f b6 6f 15       	movzx  r13,BYTE PTR [rdi+0x15]
 131:	49 c1 e5 08          	shl    r13,0x8
 135:	48 0f b6 77 14       	movzx  rsi,BYTE PTR [rdi+0x14]
 13a:	49 09 f5             	or     r13,rsi
 13d:	48 0f b6 77 16       	movzx  rsi,BYTE PTR [rdi+0x16]
 142:	48 c1 e6 10          	shl    rsi,0x10
 146:	49 09 f5             	or     r13,rsi
 149:	48 0f b6 77 17       	movzx  rsi,BYTE PTR [rdi+0x17]
 14e:	48 c1 e6 18          	shl    rsi,0x18
 152:	49 09 f5             	or     r13,rsi
 155:	49 31 cd             	xor    r13,rcx
 158:	4c 89 fa             	mov    rdx,r15
 15b:	48 83 c2 08          	add    rdx,0x8
 15f:	48 0f b6 5f 10       	movzx  rbx,BYTE PTR [rdi+0x10]
 164:	48 83 e3 03          	and    rbx,0x3
 168:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
 16c:	48 83 fb 02          	cmp    rbx,0x2
 170:	74 23                	je     0x195
 172:	48 83 fb 01          	cmp    rbx,0x1
 176:	0f 84 60 ff ff ff    	je     0xdc
 17c:	48 85 db             	test   rbx,rbx
 17f:	75 28                	jne    0x1a9
 181:	48 89 c7             	mov    rdi,rax
 184:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 188:	4c 89 e9             	mov    rcx,r13
 18b:	e8 40 02 00 00       	call   0x3d0
 190:	e9 56 ff ff ff       	jmp    0xeb
 195:	48 89 c7             	mov    rdi,rax
 198:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 19c:	4c 89 e9             	mov    rcx,r13
 19f:	e8 90 03 00 00       	call   0x534
 1a4:	e9 42 ff ff ff       	jmp    0xeb
 1a9:	48 89 c7             	mov    rdi,rax
 1ac:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 1b0:	4c 89 e9             	mov    rcx,r13
 1b3:	e8 90 05 00 00       	call   0x748
 1b8:	e9 2e ff ff ff       	jmp    0xeb
 1bd:	48 89 c7             	mov    rdi,rax
 1c0:	48 c1 ef 38          	shr    rdi,0x38
 1c4:	40 88 7a 07          	mov    BYTE PTR [rdx+0x7],dil
 1c8:	48 89 c7             	mov    rdi,rax
 1cb:	48 c1 ef 30          	shr    rdi,0x30
 1cf:	40 88 7a 06          	mov    BYTE PTR [rdx+0x6],dil
 1d3:	48 89 c7             	mov    rdi,rax
 1d6:	48 c1 ef 28          	shr    rdi,0x28
 1da:	40 88 7a 05          	mov    BYTE PTR [rdx+0x5],dil
 1de:	48 89 c7             	mov    rdi,rax
 1e1:	48 c1 ef 20          	shr    rdi,0x20
 1e5:	40 88 7a 04          	mov    BYTE PTR [rdx+0x4],dil
 1e9:	48 89 c7             	mov    rdi,rax
 1ec:	48 c1 ef 18          	shr    rdi,0x18
 1f0:	40 88 7a 03          	mov    BYTE PTR [rdx+0x3],dil
 1f4:	48 89 c7             	mov    rdi,rax
 1f7:	48 c1 ef 10          	shr    rdi,0x10
 1fb:	40 88 7a 02          	mov    BYTE PTR [rdx+0x2],dil
 1ff:	88 42 00             	mov    BYTE PTR [rdx+0x0],al
 202:	48 c1 e8 08          	shr    rax,0x8
 206:	88 42 01             	mov    BYTE PTR [rdx+0x1],al
 209:	b8 02 00 00 00       	mov    eax,0x2
 20e:	41 5f                	pop    r15
 210:	41 5e                	pop    r14
 212:	41 5d                	pop    r13
 214:	5b                   	pop    rbx
 215:	c9                   	leave
 216:	c3                   	ret
 217:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 21c:	0f 1f 00             	nop    DWORD PTR [rax]
 21f:	55                   	push   rbp
 220:	48 89 e5             	mov    rbp,rsp
 223:	53                   	push   rbx
 224:	41 55                	push   r13
 226:	48 89 d0             	mov    rax,rdx
 229:	48 83 c0 08          	add    rax,0x8
 22d:	48 83 c2 10          	add    rdx,0x10
 231:	48 c1 e2 20          	shl    rdx,0x20
 235:	48 c1 ea 20          	shr    rdx,0x20
 239:	49 89 f0             	mov    r8,rsi
 23c:	49 01 d0             	add    r8,rdx
 23f:	48 c1 e0 20          	shl    rax,0x20
 243:	48 c1 e8 20          	shr    rax,0x20
 247:	48 01 c6             	add    rsi,rax
 24a:	48 0f b6 46 01       	movzx  rax,BYTE PTR [rsi+0x1]
 24f:	48 c1 e0 08          	shl    rax,0x8
 253:	48 0f b6 56 00       	movzx  rdx,BYTE PTR [rsi+0x0]
 258:	48 09 d0             	or     rax,rdx
 25b:	49 0f b6 58 01       	movzx  rbx,BYTE PTR [r8+0x1]
 260:	48 c1 e3 08          	shl    rbx,0x8
 264:	49 0f b6 50 00       	movzx  rdx,BYTE PTR [r8+0x0]
 269:	48 09 d3             	or     rbx,rdx
 26c:	49 0f b6 50 02       	movzx  rdx,BYTE PTR [r8+0x2]
 271:	48 c1 e2 10          	shl    rdx,0x10
 275:	48 09 da             	or     rdx,rbx
 278:	48 0f b6 5e 02       	movzx  rbx,BYTE PTR [rsi+0x2]
 27d:	48 c1 e3 10          	shl    rbx,0x10
 281:	48 09 c3             	or     rbx,rax
 284:	4c 0f b6 6e 03       	movzx  r13,BYTE PTR [rsi+0x3]
 289:	49 c1 e5 18          	shl    r13,0x18
 28d:	49 09 dd             	or     r13,rbx
 290:	48 0f b6 46 04       	movzx  rax,BYTE PTR [rsi+0x4]
 295:	48 c1 e0 20          	shl    rax,0x20
 299:	4c 09 e8             	or     rax,r13
 29c:	49 0f b6 58 03       	movzx  rbx,BYTE PTR [r8+0x3]
 2a1:	48 c1 e3 18          	shl    rbx,0x18
 2a5:	48 09 d3             	or     rbx,rdx
 2a8:	4d 0f b6 68 04       	movzx  r13,BYTE PTR [r8+0x4]
 2ad:	49 c1 e5 20          	shl    r13,0x20
 2b1:	49 09 dd             	or     r13,rbx
 2b4:	49 0f b6 50 05       	movzx  rdx,BYTE PTR [r8+0x5]
 2b9:	48 c1 e2 28          	shl    rdx,0x28
 2bd:	4c 09 ea             	or     rdx,r13
 2c0:	48 0f b6 5e 05       	movzx  rbx,BYTE PTR [rsi+0x5]
 2c5:	48 c1 e3 28          	shl    rbx,0x28
 2c9:	48 09 c3             	or     rbx,rax
 2cc:	4c 0f b6 6e 06       	movzx  r13,BYTE PTR [rsi+0x6]
 2d1:	49 c1 e5 30          	shl    r13,0x30
 2d5:	49 09 dd             	or     r13,rbx
 2d8:	48 0f b6 46 07       	movzx  rax,BYTE PTR [rsi+0x7]
 2dd:	48 c1 e0 38          	shl    rax,0x38
 2e1:	4c 09 e8             	or     rax,r13
 2e4:	49 0f b6 58 06       	movzx  rbx,BYTE PTR [r8+0x6]
 2e9:	48 c1 e3 30          	shl    rbx,0x30
 2ed:	48 09 d3             	or     rbx,rdx
 2f0:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 2f5:	48 c1 e6 38          	shl    rsi,0x38
 2f9:	48 09 de             	or     rsi,rbx
 2fc:	48 c1 e1 20          	shl    rcx,0x20
 300:	48 c1 e9 20          	shr    rcx,0x20
 304:	48 c1 e1 11          	shl    rcx,0x11
 308:	48 89 f2             	mov    rdx,rsi
 30b:	48 01 ca             	add    rdx,rcx
 30e:	48 89 d1             	mov    rcx,rdx
 311:	48 31 c1             	xor    rcx,rax
 314:	49 89 c8             	mov    r8,rcx
 317:	49 c1 e8 3b          	shr    r8,0x3b
 31b:	48 c1 e1 05          	shl    rcx,0x5
 31f:	4c 09 c1             	or     rcx,r8
 322:	48 31 f8             	xor    rax,rdi
 325:	48 c1 ee 02          	shr    rsi,0x2
 329:	48 89 c7             	mov    rdi,rax
 32c:	48 c1 e7 03          	shl    rdi,0x3
 330:	48 31 fe             	xor    rsi,rdi
 333:	48 89 f7             	mov    rdi,rsi
 336:	48 01 c7             	add    rdi,rax
 339:	49 89 f8             	mov    r8,rdi
 33c:	49 c1 e8 35          	shr    r8,0x35
 340:	48 c1 e7 0b          	shl    rdi,0xb
 344:	4c 09 c7             	or     rdi,r8
 347:	48 01 cf             	add    rdi,rcx
 34a:	48 89 d1             	mov    rcx,rdx
 34d:	48 c1 e9 07          	shr    rcx,0x7
 351:	48 31 cf             	xor    rdi,rcx
 354:	48 01 f7             	add    rdi,rsi
 357:	48 31 f8             	xor    rax,rdi
 35a:	48 31 d0             	xor    rax,rdx
 35d:	41 5d                	pop    r13
 35f:	5b                   	pop    rbx
 360:	c9                   	leave
 361:	c3                   	ret
 362:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 367:	0f 1f 00             	nop    DWORD PTR [rax]
 36a:	55                   	push   rbp
 36b:	48 89 e5             	mov    rbp,rsp
 36e:	53                   	push   rbx
 36f:	41 55                	push   r13
 371:	48 89 d0             	mov    rax,rdx
 374:	48 83 c0 10          	add    rax,0x10
 378:	48 83 c2 08          	add    rdx,0x8
 37c:	48 c1 e2 20          	shl    rdx,0x20
 380:	48 c1 ea 20          	shr    rdx,0x20
 384:	49 89 f0             	mov    r8,rsi
 387:	49 01 d0             	add    r8,rdx
 38a:	48 c1 e0 20          	shl    rax,0x20
 38e:	48 c1 e8 20          	shr    rax,0x20
 392:	48 01 c6             	add    rsi,rax
 395:	48 0f b6 56 01       	movzx  rdx,BYTE PTR [rsi+0x1]
 39a:	48 c1 e2 08          	shl    rdx,0x8
 39e:	48 0f b6 46 00       	movzx  rax,BYTE PTR [rsi+0x0]
 3a3:	48 09 c2             	or     rdx,rax
 3a6:	49 0f b6 40 01       	movzx  rax,BYTE PTR [r8+0x1]
 3ab:	48 c1 e0 08          	shl    rax,0x8
 3af:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 3b4:	48 09 d8             	or     rax,rbx
 3b7:	49 0f b6 58 02       	movzx  rbx,BYTE PTR [r8+0x2]
 3bc:	48 c1 e3 10          	shl    rbx,0x10
 3c0:	48 09 c3             	or     rbx,rax
 3c3:	49 0f b6 40 03       	movzx  rax,BYTE PTR [r8+0x3]
 3c8:	48 c1 e0 18          	shl    rax,0x18
 3cc:	48 09 d8             	or     rax,rbx
 3cf:	48 0f b6 5e 02       	movzx  rbx,BYTE PTR [rsi+0x2]
 3d4:	48 c1 e3 10          	shl    rbx,0x10
 3d8:	48 09 d3             	or     rbx,rdx
 3db:	4c 0f b6 6e 03       	movzx  r13,BYTE PTR [rsi+0x3]
 3e0:	49 c1 e5 18          	shl    r13,0x18
 3e4:	49 09 dd             	or     r13,rbx
 3e7:	48 0f b6 56 04       	movzx  rdx,BYTE PTR [rsi+0x4]
 3ec:	48 c1 e2 20          	shl    rdx,0x20
 3f0:	4c 09 ea             	or     rdx,r13
 3f3:	49 0f b6 58 04       	movzx  rbx,BYTE PTR [r8+0x4]
 3f8:	48 c1 e3 20          	shl    rbx,0x20
 3fc:	48 09 c3             	or     rbx,rax
 3ff:	4d 0f b6 68 05       	movzx  r13,BYTE PTR [r8+0x5]
 404:	49 c1 e5 28          	shl    r13,0x28
 408:	49 09 dd             	or     r13,rbx
 40b:	49 0f b6 40 06       	movzx  rax,BYTE PTR [r8+0x6]
 410:	48 c1 e0 30          	shl    rax,0x30
 414:	4c 09 e8             	or     rax,r13
 417:	48 0f b6 5e 05       	movzx  rbx,BYTE PTR [rsi+0x5]
 41c:	48 c1 e3 28          	shl    rbx,0x28
 420:	48 09 d3             	or     rbx,rdx
 423:	48 0f b6 56 06       	movzx  rdx,BYTE PTR [rsi+0x6]
 428:	48 c1 e2 30          	shl    rdx,0x30
 42c:	48 09 da             	or     rdx,rbx
 42f:	48 0f b6 5e 07       	movzx  rbx,BYTE PTR [rsi+0x7]
 434:	48 c1 e3 38          	shl    rbx,0x38
 438:	48 09 d3             	or     rbx,rdx
 43b:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 440:	48 c1 e6 38          	shl    rsi,0x38
 444:	48 09 c6             	or     rsi,rax
 447:	49 89 c8             	mov    r8,rcx
 44a:	49 c1 e0 20          	shl    r8,0x20
 44e:	49 c1 e8 20          	shr    r8,0x20
 452:	4c 89 c2             	mov    rdx,r8
 455:	48 01 fa             	add    rdx,rdi
 458:	48 89 f7             	mov    rdi,rsi
 45b:	48 6b ff 03          	imul   rdi,rdi,0x3
 45f:	48 01 fa             	add    rdx,rdi
 462:	48 01 da             	add    rdx,rbx
 465:	48 83 e1 07          	and    rcx,0x7
 469:	48 89 cf             	mov    rdi,rcx
 46c:	48 83 c7 01          	add    rdi,0x1
 470:	48 83 f1 3f          	xor    rcx,0x3f
 474:	49 c1 e0 0b          	shl    r8,0xb
 478:	48 89 d0             	mov    rax,rdx
 47b:	4c 01 c0             	add    rax,r8
 47e:	49 89 c0             	mov    r8,rax
 481:	49 d3 e8             	shr    r8,cl
 484:	c4 e2 c1 f7 c0       	shlx   rax,rax,rdi
 489:	4c 09 c0             	or     rax,r8
 48c:	48 31 d0             	xor    rax,rdx
 48f:	48 c1 ee 03          	shr    rsi,0x3
 493:	48 01 f0             	add    rax,rsi
 496:	41 5d                	pop    r13
 498:	5b                   	pop    rbx
 499:	c9                   	leave
 49a:	c3                   	ret
 49b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 4a0:	0f 1f 00             	nop    DWORD PTR [rax]
 4a3:	55                   	push   rbp
 4a4:	48 89 e5             	mov    rbp,rsp
 4a7:	48 81 ec 08 00 00 00 	sub    rsp,0x8
 4ae:	53                   	push   rbx
 4af:	41 55                	push   r13
 4b1:	41 56                	push   r14
 4b3:	41 57                	push   r15
 4b5:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
 4b9:	48 89 d1             	mov    rcx,rdx
 4bc:	49 89 c8             	mov    r8,rcx
 4bf:	49 83 c0 08          	add    r8,0x8
 4c3:	49 c1 e0 20          	shl    r8,0x20
 4c7:	49 c1 e8 20          	shr    r8,0x20
 4cb:	48 89 f0             	mov    rax,rsi
 4ce:	4c 01 c0             	add    rax,r8
 4d1:	48 0f b6 58 01       	movzx  rbx,BYTE PTR [rax+0x1]
 4d6:	48 c1 e3 08          	shl    rbx,0x8
 4da:	4c 0f b6 40 00       	movzx  r8,BYTE PTR [rax+0x0]
 4df:	4c 09 c3             	or     rbx,r8
 4e2:	49 89 cd             	mov    r13,rcx
 4e5:	49 83 c5 10          	add    r13,0x10
 4e9:	49 c1 e5 20          	shl    r13,0x20
 4ed:	49 c1 ed 20          	shr    r13,0x20
 4f1:	49 89 f0             	mov    r8,rsi
 4f4:	4d 01 e8             	add    r8,r13
 4f7:	4d 0f b6 68 01       	movzx  r13,BYTE PTR [r8+0x1]
 4fc:	49 c1 e5 08          	shl    r13,0x8
 500:	4d 0f b6 70 00       	movzx  r14,BYTE PTR [r8+0x0]
 505:	4d 09 f5             	or     r13,r14
 508:	4d 0f b6 78 02       	movzx  r15,BYTE PTR [r8+0x2]
 50d:	49 c1 e7 10          	shl    r15,0x10
 511:	4d 09 ef             	or     r15,r13
 514:	4d 0f b6 70 03       	movzx  r14,BYTE PTR [r8+0x3]
 519:	49 c1 e6 18          	shl    r14,0x18
 51d:	4d 09 fe             	or     r14,r15
 520:	4c 0f b6 68 02       	movzx  r13,BYTE PTR [rax+0x2]
 525:	49 c1 e5 10          	shl    r13,0x10
 529:	49 09 dd             	or     r13,rbx
 52c:	48 0f b6 58 03       	movzx  rbx,BYTE PTR [rax+0x3]
 531:	48 c1 e3 18          	shl    rbx,0x18
 535:	4c 09 eb             	or     rbx,r13
 538:	4c 0f b6 68 04       	movzx  r13,BYTE PTR [rax+0x4]
 53d:	49 c1 e5 20          	shl    r13,0x20
 541:	49 09 dd             	or     r13,rbx
 544:	4d 0f b6 78 04       	movzx  r15,BYTE PTR [r8+0x4]
 549:	49 c1 e7 20          	shl    r15,0x20
 54d:	4d 09 f7             	or     r15,r14
 550:	48 c1 e2 20          	shl    rdx,0x20
 554:	48 c1 ea 20          	shr    rdx,0x20
 558:	48 83 c1 04          	add    rcx,0x4
 55c:	48 c1 e1 20          	shl    rcx,0x20
 560:	48 89 cb             	mov    rbx,rcx
 563:	48 c1 fb 20          	sar    rbx,0x20
 567:	48 c1 e9 20          	shr    rcx,0x20
 56b:	49 89 f6             	mov    r14,rsi
 56e:	49 01 ce             	add    r14,rcx
 571:	48 89 f1             	mov    rcx,rsi
 574:	48 01 d1             	add    rcx,rdx
 577:	48 01 de             	add    rsi,rbx
 57a:	49 0f b6 50 05       	movzx  rdx,BYTE PTR [r8+0x5]
 57f:	48 c1 e2 28          	shl    rdx,0x28
 583:	4c 09 fa             	or     rdx,r15
 586:	48 0f b6 58 05       	movzx  rbx,BYTE PTR [rax+0x5]
 58b:	48 c1 e3 28          	shl    rbx,0x28
 58f:	4c 09 eb             	or     rbx,r13
 592:	4c 0f b6 68 06       	movzx  r13,BYTE PTR [rax+0x6]
 597:	49 c1 e5 30          	shl    r13,0x30
 59b:	49 09 dd             	or     r13,rbx
 59e:	4c 0f b6 78 07       	movzx  r15,BYTE PTR [rax+0x7]
 5a3:	49 c1 e7 38          	shl    r15,0x38
 5a7:	4d 09 ef             	or     r15,r13
 5aa:	49 0f b6 40 06       	movzx  rax,BYTE PTR [r8+0x6]
 5af:	48 c1 e0 30          	shl    rax,0x30
 5b3:	48 09 d0             	or     rax,rdx
 5b6:	49 0f b6 56 00       	movzx  rdx,BYTE PTR [r14+0x0]
 5bb:	48 c1 e2 09          	shl    rdx,0x9
 5bf:	4c 0f b6 6e 01       	movzx  r13,BYTE PTR [rsi+0x1]
 5c4:	49 c1 e5 11          	shl    r13,0x11
 5c8:	49 09 d5             	or     r13,rdx
 5cb:	48 0f b6 56 02       	movzx  rdx,BYTE PTR [rsi+0x2]
 5d0:	48 c1 e2 19          	shl    rdx,0x19
 5d4:	49 09 d5             	or     r13,rdx
 5d7:	48 0f b6 76 03       	movzx  rsi,BYTE PTR [rsi+0x3]
 5dc:	48 c1 e6 21          	shl    rsi,0x21
 5e0:	49 09 f5             	or     r13,rsi
 5e3:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 5e8:	48 c1 e6 38          	shl    rsi,0x38
 5ec:	48 09 c6             	or     rsi,rax
 5ef:	49 01 ff             	add    r15,rdi
 5f2:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 5f7:	48 83 e7 07          	and    rdi,0x7
 5fb:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 5ff:	48 c1 e2 20          	shl    rdx,0x20
 603:	48 c1 ea 20          	shr    rdx,0x20
 607:	c4 e2 c1 f7 d2       	shlx   rdx,rdx,rdi
 60c:	49 89 d0             	mov    r8,rdx
 60f:	48 89 fa             	mov    rdx,rdi
 612:	48 83 c2 01          	add    rdx,0x1
 616:	48 83 f7 3f          	xor    rdi,0x3f
 61a:	4c 31 fe             	xor    rsi,r15
 61d:	48 89 f1             	mov    rcx,rsi
 620:	c4 e2 c3 f7 c9       	shrx   rcx,rcx,rdi
 625:	c4 e2 e9 f7 f6       	shlx   rsi,rsi,rdx
 62a:	48 09 ce             	or     rsi,rcx
 62d:	4c 89 f8             	mov    rax,r15
 630:	4c 31 e8             	xor    rax,r13
 633:	48 31 f0             	xor    rax,rsi
 636:	4c 01 c0             	add    rax,r8
 639:	48 c1 ee 05          	shr    rsi,0x5
 63d:	48 31 f0             	xor    rax,rsi
 640:	4c 01 f8             	add    rax,r15
 643:	41 5f                	pop    r15
 645:	41 5e                	pop    r14
 647:	41 5d                	pop    r13
 649:	5b                   	pop    rbx
 64a:	c9                   	leave
 64b:	c3                   	ret
 64c:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
 651:	0f 1f 00             	nop    DWORD PTR [rax]
 654:	55                   	push   rbp
 655:	48 89 e5             	mov    rbp,rsp
 658:	53                   	push   rbx
 659:	41 55                	push   r13
 65b:	41 56                	push   r14
 65d:	48 89 d0             	mov    rax,rdx
 660:	48 c1 e0 20          	shl    rax,0x20
 664:	48 c1 e8 20          	shr    rax,0x20
 668:	49 89 f0             	mov    r8,rsi
 66b:	49 01 c0             	add    r8,rax
 66e:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 673:	48 31 fb             	xor    rbx,rdi
 676:	48 bf eb 11 31 13 bb 	movabs rdi,0x94d049bb133111eb
 67d:	49 d0 94 
 680:	48 31 fb             	xor    rbx,rdi
 683:	48 c1 e1 20          	shl    rcx,0x20
 687:	48 c1 e9 20          	shr    rcx,0x20
 68b:	48 01 cb             	add    rbx,rcx
 68e:	48 89 df             	mov    rdi,rbx
 691:	48 c1 ef 3f          	shr    rdi,0x3f
 695:	48 d1 e3             	shl    rbx,1
 698:	48 09 fb             	or     rbx,rdi
 69b:	49 0f b6 40 01       	movzx  rax,BYTE PTR [r8+0x1]
 6a0:	48 c1 e0 08          	shl    rax,0x8
 6a4:	48 31 d8             	xor    rax,rbx
 6a7:	48 89 d3             	mov    rbx,rdx
 6aa:	48 83 c3 10          	add    rbx,0x10
 6ae:	48 c1 e3 20          	shl    rbx,0x20
 6b2:	48 c1 eb 20          	shr    rbx,0x20
 6b6:	48 89 f7             	mov    rdi,rsi
 6b9:	48 01 df             	add    rdi,rbx
 6bc:	4c 0f b6 6f 01       	movzx  r13,BYTE PTR [rdi+0x1]
 6c1:	49 c1 e5 08          	shl    r13,0x8
 6c5:	48 0f b6 5f 00       	movzx  rbx,BYTE PTR [rdi+0x0]
 6ca:	49 09 dd             	or     r13,rbx
 6cd:	48 0f b6 5f 02       	movzx  rbx,BYTE PTR [rdi+0x2]
 6d2:	48 c1 e3 10          	shl    rbx,0x10
 6d6:	4c 09 eb             	or     rbx,r13
 6d9:	48 83 c2 08          	add    rdx,0x8
 6dd:	48 c1 e2 20          	shl    rdx,0x20
 6e1:	48 c1 ea 20          	shr    rdx,0x20
 6e5:	48 01 d6             	add    rsi,rdx
 6e8:	48 89 ca             	mov    rdx,rcx
 6eb:	48 01 c2             	add    rdx,rax
 6ee:	48 83 c2 01          	add    rdx,0x1
 6f2:	48 89 d0             	mov    rax,rdx
 6f5:	48 c1 e8 3e          	shr    rax,0x3e
 6f9:	48 c1 e2 02          	shl    rdx,0x2
 6fd:	48 09 c2             	or     rdx,rax
 700:	48 0f b6 47 03       	movzx  rax,BYTE PTR [rdi+0x3]
 705:	48 c1 e0 18          	shl    rax,0x18
 709:	48 09 d8             	or     rax,rbx
 70c:	48 0f b6 5e 01       	movzx  rbx,BYTE PTR [rsi+0x1]
 711:	48 c1 e3 08          	shl    rbx,0x8
 715:	4c 0f b6 6e 00       	movzx  r13,BYTE PTR [rsi+0x0]
 71a:	4c 09 eb             	or     rbx,r13
 71d:	4c 0f b6 6e 02       	movzx  r13,BYTE PTR [rsi+0x2]
 722:	49 c1 e5 10          	shl    r13,0x10
 726:	49 09 dd             	or     r13,rbx
 729:	48 0f b6 5e 03       	movzx  rbx,BYTE PTR [rsi+0x3]
 72e:	48 c1 e3 18          	shl    rbx,0x18
 732:	4c 09 eb             	or     rbx,r13
 735:	4c 0f b6 77 04       	movzx  r14,BYTE PTR [rdi+0x4]
 73a:	49 c1 e6 20          	shl    r14,0x20
 73e:	49 09 c6             	or     r14,rax
 741:	49 0f b6 40 02       	movzx  rax,BYTE PTR [r8+0x2]
 746:	48 c1 e0 10          	shl    rax,0x10
 74a:	48 31 d0             	xor    rax,rdx
 74d:	4c 0f b6 6f 05       	movzx  r13,BYTE PTR [rdi+0x5]
 752:	49 c1 e5 28          	shl    r13,0x28
 756:	4d 09 f5             	or     r13,r14
 759:	48 0f b6 56 04       	movzx  rdx,BYTE PTR [rsi+0x4]
 75e:	48 c1 e2 20          	shl    rdx,0x20
 762:	48 09 da             	or     rdx,rbx
 765:	48 0f b6 5e 05       	movzx  rbx,BYTE PTR [rsi+0x5]
 76a:	48 c1 e3 28          	shl    rbx,0x28
 76e:	48 09 d3             	or     rbx,rdx
 771:	48 0f b6 56 06       	movzx  rdx,BYTE PTR [rsi+0x6]
 776:	48 c1 e2 30          	shl    rdx,0x30
 77a:	48 09 da             	or     rdx,rbx
 77d:	4c 0f b6 77 06       	movzx  r14,BYTE PTR [rdi+0x6]
 782:	49 c1 e6 30          	shl    r14,0x30
 786:	4d 09 ee             	or     r14,r13
 789:	48 89 cb             	mov    rbx,rcx
 78c:	48 01 c3             	add    rbx,rax
 78f:	48 83 c3 02          	add    rbx,0x2
 793:	48 89 d8             	mov    rax,rbx
 796:	48 c1 e8 3d          	shr    rax,0x3d
 79a:	48 c1 e3 03          	shl    rbx,0x3
 79e:	48 09 c3             	or     rbx,rax
 7a1:	48 0f b6 47 07       	movzx  rax,BYTE PTR [rdi+0x7]
 7a6:	48 c1 e0 38          	shl    rax,0x38
 7aa:	4c 09 f0             	or     rax,r14
 7ad:	48 0f b6 7e 07       	movzx  rdi,BYTE PTR [rsi+0x7]
 7b2:	48 c1 e7 38          	shl    rdi,0x38
 7b6:	48 09 d7             	or     rdi,rdx
 7b9:	49 0f b6 70 03       	movzx  rsi,BYTE PTR [r8+0x3]
 7be:	48 c1 e6 18          	shl    rsi,0x18
 7c2:	48 31 de             	xor    rsi,rbx
 7c5:	48 89 ca             	mov    rdx,rcx
 7c8:	48 01 f2             	add    rdx,rsi
 7cb:	48 83 c2 03          	add    rdx,0x3
 7cf:	48 89 d6             	mov    rsi,rdx
 7d2:	48 c1 ee 3c          	shr    rsi,0x3c
 7d6:	48 c1 e2 04          	shl    rdx,0x4
 7da:	48 09 f2             	or     rdx,rsi
 7dd:	49 0f b6 70 04       	movzx  rsi,BYTE PTR [r8+0x4]
 7e2:	48 c1 e6 20          	shl    rsi,0x20
 7e6:	48 31 d6             	xor    rsi,rdx
 7e9:	48 89 ca             	mov    rdx,rcx
 7ec:	48 01 f2             	add    rdx,rsi
 7ef:	48 83 c2 04          	add    rdx,0x4
 7f3:	48 89 d6             	mov    rsi,rdx
 7f6:	48 c1 ee 3b          	shr    rsi,0x3b
 7fa:	48 c1 e2 05          	shl    rdx,0x5
 7fe:	48 09 f2             	or     rdx,rsi
 801:	49 0f b6 70 05       	movzx  rsi,BYTE PTR [r8+0x5]
 806:	48 c1 e6 28          	shl    rsi,0x28
 80a:	48 31 d6             	xor    rsi,rdx
 80d:	48 89 ca             	mov    rdx,rcx
 810:	48 01 f2             	add    rdx,rsi
 813:	48 83 c2 05          	add    rdx,0x5
 817:	48 89 d6             	mov    rsi,rdx
 81a:	48 c1 ee 3a          	shr    rsi,0x3a
 81e:	48 c1 e2 06          	shl    rdx,0x6
 822:	48 09 f2             	or     rdx,rsi
 825:	49 0f b6 70 06       	movzx  rsi,BYTE PTR [r8+0x6]
 82a:	48 c1 e6 30          	shl    rsi,0x30
 82e:	48 31 d6             	xor    rsi,rdx
 831:	48 89 ca             	mov    rdx,rcx
 834:	48 01 f2             	add    rdx,rsi
 837:	48 83 c2 06          	add    rdx,0x6
 83b:	48 89 d6             	mov    rsi,rdx
 83e:	48 c1 ee 39          	shr    rsi,0x39
 842:	48 c1 e2 07          	shl    rdx,0x7
 846:	48 09 f2             	or     rdx,rsi
 849:	49 0f b6 70 07       	movzx  rsi,BYTE PTR [r8+0x7]
 84e:	48 c1 e6 38          	shl    rsi,0x38
 852:	48 31 d6             	xor    rsi,rdx
 855:	48 01 f1             	add    rcx,rsi
 858:	48 83 c1 07          	add    rcx,0x7
 85c:	48 89 ce             	mov    rsi,rcx
 85f:	48 c1 ee 38          	shr    rsi,0x38
 863:	48 c1 e1 08          	shl    rcx,0x8
 867:	48 09 f1             	or     rcx,rsi
 86a:	48 01 cf             	add    rdi,rcx
 86d:	48 31 f8             	xor    rax,rdi
 870:	41 5e                	pop    r14
 872:	41 5d                	pop    r13
 874:	5b                   	pop    rbx
 875:	c9                   	leave
 876:	c3                   	ret
```
