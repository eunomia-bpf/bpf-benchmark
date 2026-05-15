# bcc_tcpconnect_ipv4_tuple_filter

## Original C
```c
#include "common.h"

#define BCC_TCPCONNECT_RECORDS 32U
#define BCC_TCPCONNECT_RECORD_SIZE 24U
#define BCC_TCPCONNECT_INPUT_SIZE \
    (8U + BCC_TCPCONNECT_RECORDS * BCC_TCPCONNECT_RECORD_SIZE)

static __always_inline u32 bcc_tcpconnect_port_class(u16 dport)
{
    if (dport == 80U) {
        return 1U;
    }
    if (dport == 443U) {
        return 2U;
    }
    if (dport == 8080U || dport == 8443U) {
        return 3U;
    }
    if (dport >= 30000U && dport <= 32767U) {
        return 4U;
    }
    return 0U;
}

static __always_inline int
bench_bcc_tcpconnect_ipv4_tuple_filter(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BCC_TCPCONNECT_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != BCC_TCPCONNECT_RECORDS ||
        record_size != BCC_TCPCONNECT_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0xA0761D6478BD642FULL;
    for (u32 index = 0; index < BCC_TCPCONNECT_RECORDS; index++) {
        u32 base = 8U + index * BCC_TCPCONNECT_RECORD_SIZE;
        u32 pid = micro_read_u32_le(data, base);
        u32 uid = micro_read_u32_le(data, base + 4U);
        u32 src = micro_read_u32_le(data, base + 8U);
        u32 dst = micro_read_u32_le(data, base + 12U);
        u16 sport = micro_read_u16_le(data, base + 16U);
        u16 dport = micro_read_u16_le(data, base + 18U);
        u8 family = data[base + 20U];
        u8 flags = data[base + 21U];
        u16 netns = micro_read_u16_le(data, base + 22U);
        u32 port_class = bcc_tcpconnect_port_class(dport);

        if (family != 2U) {
            acc ^= ((u64)family << 48U) | pid;
            continue;
        }
        if ((flags & 1U) == 0U || port_class == 0U) {
            acc += ((u64)uid << 32U) ^ dport;
            continue;
        }

        u32 tuple_hash = src ^ micro_rotl32(dst, 7U) ^
                         ((u32)sport << 16U) ^ dport ^ netns;
        if ((flags & 2U) != 0U) {
            tuple_hash ^= pid + uid;
        }
        if ((flags & 4U) != 0U) {
            tuple_hash = micro_rotl32(tuple_hash, port_class + 3U);
        }

        acc ^= micro_rotl64(((u64)tuple_hash << 32U) | pid,
                            (index & 7U) + 1U);
        acc += ((u64)port_class << 56U) ^ ((u64)netns << 16U) ^ uid;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bcc_tcpconnect_ipv4_tuple_filter_xdp,
    bench_bcc_tcpconnect_ipv4_tuple_filter,
    bcc_tcpconnect_ipv4_tuple_filter_input_value,
    BCC_TCPCONNECT_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <bcc_tcpconnect_ipv4_tuple_filter_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe>
    1118:	48 8d b2 10 03 00 00 	lea    rsi,[rdx+0x310]
    111f:	48 39 ce             	cmp    rsi,rcx
    1122:	77 ea                	ja     110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe>
    1124:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    1128:	75 e4                	jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe>
    112a:	83 7a 0c 18          	cmp    DWORD PTR [rdx+0xc],0x18
    112e:	75 de                	jne    110e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xe>
    1130:	55                   	push   rbp
    1131:	41 57                	push   r15
    1133:	41 56                	push   r14
    1135:	53                   	push   rbx
    1136:	48 8d 72 27          	lea    rsi,[rdx+0x27]
    113a:	49 b8 2f 64 bd 78 64 	movabs r8,0xa0761d6478bd642f
    1141:	1d 76 a0 
    1144:	31 ff                	xor    edi,edi
    1146:	eb 25                	jmp    116d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x6d>
    1148:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    114f:	00 
    1150:	48 c1 e1 30          	shl    rcx,0x30
    1154:	89 d8                	mov    eax,ebx
    1156:	48 09 c8             	or     rax,rcx
    1159:	49 31 c0             	xor    r8,rax
    115c:	48 ff c7             	inc    rdi
    115f:	48 83 c6 18          	add    rsi,0x18
    1163:	48 83 ff 20          	cmp    rdi,0x20
    1167:	0f 84 32 01 00 00    	je     129f <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x19f>
    116d:	0f b7 46 fb          	movzx  eax,WORD PTR [rsi-0x5]
    1171:	3d 8f 1f 00 00       	cmp    eax,0x1f8f
    1176:	7f 18                	jg     1190 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x90>
    1178:	83 f8 50             	cmp    eax,0x50
    117b:	74 3f                	je     11bc <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xbc>
    117d:	3d bb 01 00 00       	cmp    eax,0x1bb
    1182:	75 22                	jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6>
    1184:	41 b9 02 00 00 00    	mov    r9d,0x2
    118a:	eb 44                	jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0>
    118c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1190:	3d 90 1f 00 00       	cmp    eax,0x1f90
    1195:	74 07                	je     119e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x9e>
    1197:	3d fb 20 00 00       	cmp    eax,0x20fb
    119c:	75 08                	jne    11a6 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa6>
    119e:	41 b9 03 00 00 00    	mov    r9d,0x3
    11a4:	eb 2a                	jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0>
    11a6:	0f bf c8             	movsx  ecx,ax
    11a9:	45 31 c9             	xor    r9d,r9d
    11ac:	81 f9 30 75 00 00    	cmp    ecx,0x7530
    11b2:	41 0f 9d c1          	setge  r9b
    11b6:	41 c1 e1 02          	shl    r9d,0x2
    11ba:	eb 14                	jmp    11d0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xd0>
    11bc:	41 b9 01 00 00 00    	mov    r9d,0x1
    11c2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11c9:	1f 84 00 00 00 00 00 
    11d0:	8b 5e e9             	mov    ebx,DWORD PTR [rsi-0x17]
    11d3:	0f b6 4e fd          	movzx  ecx,BYTE PTR [rsi-0x3]
    11d7:	83 f9 02             	cmp    ecx,0x2
    11da:	0f 85 70 ff ff ff    	jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50>
    11e0:	44 8b 56 ed          	mov    r10d,DWORD PTR [rsi-0x13]
    11e4:	0f b6 6e fe          	movzx  ebp,BYTE PTR [rsi-0x2]
    11e8:	40 f6 c5 01          	test   bpl,0x1
    11ec:	0f 84 9e 00 00 00    	je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190>
    11f2:	45 85 c9             	test   r9d,r9d
    11f5:	0f 84 95 00 00 00    	je     1290 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x190>
    11fb:	8b 4e f5             	mov    ecx,DWORD PTR [rsi-0xb]
    11fe:	44 0f b6 76 f9       	movzx  r14d,BYTE PTR [rsi-0x7]
    1203:	44 0f b6 7e fa       	movzx  r15d,BYTE PTR [rsi-0x6]
    1208:	c1 c1 07             	rol    ecx,0x7
    120b:	33 4e f1             	xor    ecx,DWORD PTR [rsi-0xf]
    120e:	44 0f b7 5e ff       	movzx  r11d,WORD PTR [rsi-0x1]
    1213:	41 c1 e7 18          	shl    r15d,0x18
    1217:	41 c1 e6 10          	shl    r14d,0x10
    121b:	45 09 fe             	or     r14d,r15d
    121e:	0f b7 c0             	movzx  eax,ax
    1221:	44 31 f0             	xor    eax,r14d
    1224:	31 c8                	xor    eax,ecx
    1226:	89 e9                	mov    ecx,ebp
    1228:	c1 e1 1e             	shl    ecx,0x1e
    122b:	c1 f9 1f             	sar    ecx,0x1f
    122e:	45 8d 34 1a          	lea    r14d,[r10+rbx*1]
    1232:	41 21 ce             	and    r14d,ecx
    1235:	45 31 de             	xor    r14d,r11d
    1238:	41 31 c6             	xor    r14d,eax
    123b:	41 8d 49 03          	lea    ecx,[r9+0x3]
    123f:	44 89 f0             	mov    eax,r14d
    1242:	d3 c0                	rol    eax,cl
    1244:	40 f6 c5 04          	test   bpl,0x4
    1248:	41 0f 44 c6          	cmove  eax,r14d
    124c:	48 c1 e0 20          	shl    rax,0x20
    1250:	89 db                	mov    ebx,ebx
    1252:	48 09 c3             	or     rbx,rax
    1255:	89 f8                	mov    eax,edi
    1257:	24 07                	and    al,0x7
    1259:	8d 48 01             	lea    ecx,[rax+0x1]
    125c:	49 89 de             	mov    r14,rbx
    125f:	49 d3 e6             	shl    r14,cl
    1262:	f6 d0                	not    al
    1264:	89 c1                	mov    ecx,eax
    1266:	48 d3 eb             	shr    rbx,cl
    1269:	4c 09 f3             	or     rbx,r14
    126c:	4c 31 c3             	xor    rbx,r8
    126f:	49 c1 e1 38          	shl    r9,0x38
    1273:	41 c1 e3 10          	shl    r11d,0x10
    1277:	4d 09 cb             	or     r11,r9
    127a:	45 89 d0             	mov    r8d,r10d
    127d:	4d 31 d8             	xor    r8,r11
    1280:	49 01 d8             	add    r8,rbx
    1283:	e9 d4 fe ff ff       	jmp    115c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c>
    1288:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    128f:	00 
    1290:	49 c1 e2 20          	shl    r10,0x20
    1294:	49 09 c2             	or     r10,rax
    1297:	4d 01 d0             	add    r8,r10
    129a:	e9 bd fe ff ff       	jmp    115c <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5c>
    129f:	4c 89 02             	mov    QWORD PTR [rdx],r8
    12a2:	b8 02 00 00 00       	mov    eax,0x2
    12a7:	5b                   	pop    rbx
    12a8:	41 5e                	pop    r14
    12aa:	41 5f                	pop    r15
    12ac:	5d                   	pop    rbp
    12ad:	c3                   	ret

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
   c:	48 81 ec 28 00 00 00 	sub    rsp,0x28
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 b5 03 00 00    	ja     0x3e2
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 a5 03 00 00    	ja     0x3e2
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 03 00 00 	add    rdi,0x310
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 92 03 00 00    	ja     0x3e2
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
  85:	0f 85 57 03 00 00    	jne    0x3e2
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
  bc:	48 83 ff 18          	cmp    rdi,0x18
  c0:	0f 85 1c 03 00 00    	jne    0x3e2
  c6:	49 bf 2f 64 bd 78 64 	movabs r15,0xa0761d6478bd642f
  cd:	1d 76 a0 
  d0:	31 d2                	xor    edx,edx
  d2:	48 89 4d d8          	mov    QWORD PTR [rbp-0x28],rcx
  d6:	48 83 c1 13          	add    rcx,0x13
  da:	eb 5b                	jmp    0x137
  dc:	4c 0f b6 69 fe       	movzx  r13,BYTE PTR [rcx-0x2]
  e1:	49 c1 e5 08          	shl    r13,0x8
  e5:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
  ea:	49 09 fd             	or     r13,rdi
  ed:	48 0f b6 79 ff       	movzx  rdi,BYTE PTR [rcx-0x1]
  f2:	48 c1 e7 10          	shl    rdi,0x10
  f6:	49 09 fd             	or     r13,rdi
  f9:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
  fe:	48 c1 e7 18          	shl    rdi,0x18
 102:	49 09 fd             	or     r13,rdi
 105:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 10a:	48 83 ff 02          	cmp    rdi,0x2
 10e:	74 6e                	je     0x17e
 110:	48 c1 e7 30          	shl    rdi,0x30
 114:	49 c1 e5 20          	shl    r13,0x20
 118:	49 c1 ed 20          	shr    r13,0x20
 11c:	4c 09 ef             	or     rdi,r13
 11f:	4c 31 ff             	xor    rdi,r15
 122:	49 89 ff             	mov    r15,rdi
 125:	48 83 c1 18          	add    rcx,0x18
 129:	48 83 c2 01          	add    rdx,0x1
 12d:	48 83 fa 20          	cmp    rdx,0x20
 131:	0f 84 54 02 00 00    	je     0x38b
 137:	48 0f b6 79 10       	movzx  rdi,BYTE PTR [rcx+0x10]
 13c:	48 c1 e7 08          	shl    rdi,0x8
 140:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
 145:	48 09 f7             	or     rdi,rsi
 148:	41 b8 01 00 00 00    	mov    r8d,0x1
 14e:	49 89 fe             	mov    r14,rdi
 151:	49 c1 e6 30          	shl    r14,0x30
 155:	49 c1 fe 30          	sar    r14,0x30
 159:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 160:	48 83 ff 50          	cmp    rdi,0x50
 164:	0f 84 72 ff ff ff    	je     0xdc
 16a:	48 81 ff bb 01 00 00 	cmp    rdi,0x1bb
 171:	75 6e                	jne    0x1e1
 173:	41 b8 02 00 00 00    	mov    r8d,0x2
 179:	e9 5e ff ff ff       	jmp    0xdc
 17e:	48 0f b6 59 02       	movzx  rbx,BYTE PTR [rcx+0x2]
 183:	48 c1 e3 08          	shl    rbx,0x8
 187:	48 0f b6 79 01       	movzx  rdi,BYTE PTR [rcx+0x1]
 18c:	48 09 fb             	or     rbx,rdi
 18f:	48 0f b6 79 03       	movzx  rdi,BYTE PTR [rcx+0x3]
 194:	48 c1 e7 10          	shl    rdi,0x10
 198:	48 09 fb             	or     rbx,rdi
 19b:	48 0f b6 79 04       	movzx  rdi,BYTE PTR [rcx+0x4]
 1a0:	48 c1 e7 18          	shl    rdi,0x18
 1a4:	48 09 fb             	or     rbx,rdi
 1a7:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 1ac:	48 89 fe             	mov    rsi,rdi
 1af:	48 83 e6 01          	and    rsi,0x1
 1b3:	48 85 f6             	test   rsi,rsi
 1b6:	74 10                	je     0x1c8
 1b8:	4c 89 c6             	mov    rsi,r8
 1bb:	48 c1 e6 20          	shl    rsi,0x20
 1bf:	48 c1 ee 20          	shr    rsi,0x20
 1c3:	48 85 f6             	test   rsi,rsi
 1c6:	75 54                	jne    0x21c
 1c8:	49 81 e6 ff ff 00 00 	and    r14,0xffff
 1cf:	48 c1 e3 20          	shl    rbx,0x20
 1d3:	4c 09 f3             	or     rbx,r14
 1d6:	4c 01 fb             	add    rbx,r15
 1d9:	49 89 df             	mov    r15,rbx
 1dc:	e9 44 ff ff ff       	jmp    0x125
 1e1:	41 b8 03 00 00 00    	mov    r8d,0x3
 1e7:	49 81 fe fb 20 00 00 	cmp    r14,0x20fb
 1ee:	0f 84 e8 fe ff ff    	je     0xdc
 1f4:	49 81 fe 90 1f 00 00 	cmp    r14,0x1f90
 1fb:	0f 84 db fe ff ff    	je     0xdc
 201:	41 b8 01 00 00 00    	mov    r8d,0x1
 207:	49 81 fe 2f 75 00 00 	cmp    r14,0x752f
 20e:	7f 03                	jg     0x213
 210:	45 31 c0             	xor    r8d,r8d
 213:	49 c1 e0 02          	shl    r8,0x2
 217:	e9 c0 fe ff ff       	jmp    0xdc
 21c:	4c 89 7d f8          	mov    QWORD PTR [rbp-0x8],r15
 220:	4c 0f b6 79 0a       	movzx  r15,BYTE PTR [rcx+0xa]
 225:	49 c1 e7 08          	shl    r15,0x8
 229:	48 0f b6 71 09       	movzx  rsi,BYTE PTR [rcx+0x9]
 22e:	49 09 f7             	or     r15,rsi
 231:	48 0f b6 71 06       	movzx  rsi,BYTE PTR [rcx+0x6]
 236:	48 c1 e6 08          	shl    rsi,0x8
 23a:	4c 89 45 f0          	mov    QWORD PTR [rbp-0x10],r8
 23e:	4c 0f b6 41 05       	movzx  r8,BYTE PTR [rcx+0x5]
 243:	4c 09 c6             	or     rsi,r8
 246:	4c 0f b6 41 07       	movzx  r8,BYTE PTR [rcx+0x7]
 24b:	49 c1 e0 10          	shl    r8,0x10
 24f:	4c 09 c6             	or     rsi,r8
 252:	4c 0f b6 41 0b       	movzx  r8,BYTE PTR [rcx+0xb]
 257:	49 c1 e0 10          	shl    r8,0x10
 25b:	4d 09 c7             	or     r15,r8
 25e:	4c 0f b6 41 14       	movzx  r8,BYTE PTR [rcx+0x14]
 263:	49 c1 e0 08          	shl    r8,0x8
 267:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
 26b:	48 0f b6 79 13       	movzx  rdi,BYTE PTR [rcx+0x13]
 270:	49 09 f8             	or     r8,rdi
 273:	4c 89 45 e0          	mov    QWORD PTR [rbp-0x20],r8
 277:	48 0f b6 79 0c       	movzx  rdi,BYTE PTR [rcx+0xc]
 27c:	48 c1 e7 18          	shl    rdi,0x18
 280:	49 09 ff             	or     r15,rdi
 283:	48 0f b6 79 08       	movzx  rdi,BYTE PTR [rcx+0x8]
 288:	48 c1 e7 18          	shl    rdi,0x18
 28c:	48 09 fe             	or     rsi,rdi
 28f:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 294:	48 0f b6 41 0d       	movzx  rax,BYTE PTR [rcx+0xd]
 299:	48 c1 e0 10          	shl    rax,0x10
 29d:	48 c1 e7 18          	shl    rdi,0x18
 2a1:	48 09 c7             	or     rdi,rax
 2a4:	4c 89 f8             	mov    rax,r15
 2a7:	41 b8 00 00 00 fe    	mov    r8d,0xfe000000
 2ad:	4c 21 c0             	and    rax,r8
 2b0:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
 2b4:	48 c1 e8 19          	shr    rax,0x19
 2b8:	49 c1 e7 07          	shl    r15,0x7
 2bc:	49 09 c7             	or     r15,rax
 2bf:	49 31 f7             	xor    r15,rsi
 2c2:	49 31 ff             	xor    r15,rdi
 2c5:	49 81 e6 ff ff 00 00 	and    r14,0xffff
 2cc:	4d 31 f7             	xor    r15,r14
 2cf:	4c 8b 75 e0          	mov    r14,QWORD PTR [rbp-0x20]
 2d3:	48 89 df             	mov    rdi,rbx
 2d6:	4c 01 ef             	add    rdi,r13
 2d9:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 2dd:	48 89 c6             	mov    rsi,rax
 2e0:	48 c1 e6 3e          	shl    rsi,0x3e
 2e4:	48 c1 fe 3f          	sar    rsi,0x3f
 2e8:	48 21 fe             	and    rsi,rdi
 2eb:	49 31 f7             	xor    r15,rsi
 2ee:	49 81 e6 ff ff 00 00 	and    r14,0xffff
 2f5:	4d 31 f7             	xor    r15,r14
 2f8:	48 89 c7             	mov    rdi,rax
 2fb:	48 83 e7 04          	and    rdi,0x4
 2ff:	48 85 ff             	test   rdi,rdi
 302:	74 31                	je     0x335
 304:	48 c7 c7 fd ff ff ff 	mov    rdi,0xfffffffffffffffd
 30b:	4c 29 c7             	sub    rdi,r8
 30e:	48 83 e7 1f          	and    rdi,0x1f
 312:	4c 89 fe             	mov    rsi,r15
 315:	48 c1 e6 20          	shl    rsi,0x20
 319:	48 c1 ee 20          	shr    rsi,0x20
 31d:	c4 e2 c3 f7 f6       	shrx   rsi,rsi,rdi
 322:	4c 89 c7             	mov    rdi,r8
 325:	48 83 c7 03          	add    rdi,0x3
 329:	48 83 e7 1f          	and    rdi,0x1f
 32d:	c4 42 c1 f7 ff       	shlx   r15,r15,rdi
 332:	49 09 f7             	or     r15,rsi
 335:	49 c1 e7 20          	shl    r15,0x20
 339:	49 c1 e5 20          	shl    r13,0x20
 33d:	49 c1 ed 20          	shr    r13,0x20
 341:	4d 09 ef             	or     r15,r13
 344:	48 89 d7             	mov    rdi,rdx
 347:	48 83 e7 07          	and    rdi,0x7
 34b:	48 89 fe             	mov    rsi,rdi
 34e:	48 83 f6 3f          	xor    rsi,0x3f
 352:	4c 89 f8             	mov    rax,r15
 355:	c4 e2 cb f7 c0       	shrx   rax,rax,rsi
 35a:	48 83 c7 01          	add    rdi,0x1
 35e:	c4 42 c1 f7 ff       	shlx   r15,r15,rdi
 363:	49 09 c7             	or     r15,rax
 366:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 36a:	49 31 ff             	xor    r15,rdi
 36d:	49 c1 e0 38          	shl    r8,0x38
 371:	49 c1 e6 10          	shl    r14,0x10
 375:	4d 09 f0             	or     r8,r14
 378:	48 c1 e3 20          	shl    rbx,0x20
 37c:	48 c1 eb 20          	shr    rbx,0x20
 380:	49 31 d8             	xor    r8,rbx
 383:	4d 01 c7             	add    r15,r8
 386:	e9 9a fd ff ff       	jmp    0x125
 38b:	4c 89 ff             	mov    rdi,r15
 38e:	48 c1 ef 38          	shr    rdi,0x38
 392:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 396:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 39a:	4c 89 ff             	mov    rdi,r15
 39d:	48 c1 ef 30          	shr    rdi,0x30
 3a1:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3a5:	4c 89 ff             	mov    rdi,r15
 3a8:	48 c1 ef 28          	shr    rdi,0x28
 3ac:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 3b0:	4c 89 ff             	mov    rdi,r15
 3b3:	48 c1 ef 20          	shr    rdi,0x20
 3b7:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 3bb:	4c 89 ff             	mov    rdi,r15
 3be:	48 c1 ef 18          	shr    rdi,0x18
 3c2:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 3c6:	4c 89 ff             	mov    rdi,r15
 3c9:	48 c1 ef 10          	shr    rdi,0x10
 3cd:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 3d1:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 3d5:	49 c1 ef 08          	shr    r15,0x8
 3d9:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 3dd:	b8 02 00 00 00       	mov    eax,0x2
 3e2:	41 5f                	pop    r15
 3e4:	41 5e                	pop    r14
 3e6:	41 5d                	pop    r13
 3e8:	5b                   	pop    rbx
 3e9:	c9                   	leave
 3ea:	c3                   	ret
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
   d:	0f 87 16 02 00 00    	ja     0x229
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 09 02 00 00    	ja     0x229
  20:	48 8d b1 10 03 00 00 	lea    rsi,[rcx+0x310]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 f9 01 00 00    	ja     0x229
  30:	83 79 08 20          	cmp    DWORD PTR [rcx+0x8],0x20
  34:	0f 85 d5 01 00 00    	jne    0x20f
  3a:	83 79 0c 18          	cmp    DWORD PTR [rcx+0xc],0x18
  3e:	0f 85 cb 01 00 00    	jne    0x20f
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 89 4c 24 f0       	mov    QWORD PTR [rsp-0x10],rcx
  53:	48 8d 41 13          	lea    rax,[rcx+0x13]
  57:	49 bc 2f 64 bd 78 64 	movabs r12,0xa0761d6478bd642f
  5e:	1d 76 a0 
  61:	31 d2                	xor    edx,edx
  63:	eb 26                	jmp    0x8b
  65:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  6c:	00 00 00 00 
  70:	49 c1 e1 30          	shl    r9,0x30
  74:	4d 09 d9             	or     r9,r11
  77:	4d 31 cc             	xor    r12,r9
  7a:	48 83 c0 18          	add    rax,0x18
  7e:	48 ff c2             	inc    rdx
  81:	48 83 fa 20          	cmp    rdx,0x20
  85:	0f 84 87 01 00 00    	je     0x212
  8b:	44 0f b7 50 0f       	movzx  r10d,WORD PTR [rax+0xf]
  90:	41 81 fa 8f 1f 00 00 	cmp    r10d,0x1f8f
  97:	7f 17                	jg     0xb0
  99:	41 83 fa 50          	cmp    r10d,0x50
  9d:	74 4c                	je     0xeb
  9f:	41 81 fa bb 01 00 00 	cmp    r10d,0x1bb
  a6:	75 22                	jne    0xca
  a8:	41 b8 02 00 00 00    	mov    r8d,0x2
  ae:	eb 50                	jmp    0x100
  b0:	41 81 fa 90 1f 00 00 	cmp    r10d,0x1f90
  b7:	74 09                	je     0xc2
  b9:	41 81 fa fb 20 00 00 	cmp    r10d,0x20fb
  c0:	75 08                	jne    0xca
  c2:	41 b8 03 00 00 00    	mov    r8d,0x3
  c8:	eb 36                	jmp    0x100
  ca:	4d 89 d1             	mov    r9,r10
  cd:	49 c1 e1 30          	shl    r9,0x30
  d1:	45 31 c0             	xor    r8d,r8d
  d4:	48 b9 00 00 00 00 00 	movabs rcx,0x752f000000000000
  db:	00 2f 75 
  de:	49 39 c9             	cmp    r9,rcx
  e1:	41 0f 9f c0          	setg   r8b
  e5:	41 c1 e0 02          	shl    r8d,0x2
  e9:	eb 15                	jmp    0x100
  eb:	41 b8 01 00 00 00    	mov    r8d,0x1
  f1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  f8:	0f 1f 84 00 00 00 00 
  ff:	00 
 100:	44 8b 58 fd          	mov    r11d,DWORD PTR [rax-0x3]
 104:	44 0f b6 48 11       	movzx  r9d,BYTE PTR [rax+0x11]
 109:	49 83 f9 02          	cmp    r9,0x2
 10d:	0f 85 5d ff ff ff    	jne    0x70
 113:	44 8b 48 01          	mov    r9d,DWORD PTR [rax+0x1]
 117:	44 0f b6 78 12       	movzx  r15d,BYTE PTR [rax+0x12]
 11c:	41 f6 c7 01          	test   r15b,0x1
 120:	0f 84 da 00 00 00    	je     0x200
 126:	4d 85 c0             	test   r8,r8
 129:	0f 84 d1 00 00 00    	je     0x200
 12f:	0f b6 68 0a          	movzx  ebp,BYTE PTR [rax+0xa]
 133:	44 0f b6 70 09       	movzx  r14d,BYTE PTR [rax+0x9]
 138:	44 0f b6 68 0b       	movzx  r13d,BYTE PTR [rax+0xb]
 13d:	0f b7 58 13          	movzx  ebx,WORD PTR [rax+0x13]
 141:	0f b6 70 0c          	movzx  esi,BYTE PTR [rax+0xc]
 145:	8b 48 05             	mov    ecx,DWORD PTR [rax+0x5]
 148:	48 89 4c 24 f8       	mov    QWORD PTR [rsp-0x8],rcx
 14d:	0f b6 48 0d          	movzx  ecx,BYTE PTR [rax+0xd]
 151:	c1 e1 10             	shl    ecx,0x10
 154:	0f b6 78 0e          	movzx  edi,BYTE PTR [rax+0xe]
 158:	c1 e7 18             	shl    edi,0x18
 15b:	09 cf                	or     edi,ecx
 15d:	89 f1                	mov    ecx,esi
 15f:	d1 e9                	shr    ecx,1
 161:	48 c1 e6 1f          	shl    rsi,0x1f
 165:	41 c1 e5 17          	shl    r13d,0x17
 169:	c1 e5 0f             	shl    ebp,0xf
 16c:	41 c1 e6 07          	shl    r14d,0x7
 170:	41 09 ee             	or     r14d,ebp
 173:	45 09 ee             	or     r14d,r13d
 176:	49 09 f6             	or     r14,rsi
 179:	49 09 ce             	or     r14,rcx
 17c:	49 31 fe             	xor    r14,rdi
 17f:	4b 8d 0c 19          	lea    rcx,[r9+r11*1]
 183:	4c 89 fe             	mov    rsi,r15
 186:	48 c1 e6 3e          	shl    rsi,0x3e
 18a:	48 c1 fe 3f          	sar    rsi,0x3f
 18e:	48 21 ce             	and    rsi,rcx
 191:	48 33 74 24 f8       	xor    rsi,QWORD PTR [rsp-0x8]
 196:	4c 31 d6             	xor    rsi,r10
 199:	49 31 de             	xor    r14,rbx
 19c:	49 31 f6             	xor    r14,rsi
 19f:	41 f6 c7 04          	test   r15b,0x4
 1a3:	74 1a                	je     0x1bf
 1a5:	44 89 f1             	mov    ecx,r14d
 1a8:	40 b6 1d             	mov    sil,0x1d
 1ab:	44 28 c6             	sub    sil,r8b
 1ae:	c4 e2 cb f7 c9       	shrx   rcx,rcx,rsi
 1b3:	41 8d 70 03          	lea    esi,[r8+0x3]
 1b7:	c4 42 c9 f7 f6       	shlx   r14,r14,rsi
 1bc:	49 09 ce             	or     r14,rcx
 1bf:	49 c1 e6 20          	shl    r14,0x20
 1c3:	4d 09 de             	or     r14,r11
 1c6:	89 d1                	mov    ecx,edx
 1c8:	80 e1 07             	and    cl,0x7
 1cb:	89 ce                	mov    esi,ecx
 1cd:	40 f6 d6             	not    sil
 1d0:	c4 c2 cb f7 f6       	shrx   rsi,r14,rsi
 1d5:	fe c1                	inc    cl
 1d7:	c4 c2 f1 f7 ce       	shlx   rcx,r14,rcx
 1dc:	48 09 f1             	or     rcx,rsi
 1df:	4c 31 e1             	xor    rcx,r12
 1e2:	49 c1 e0 38          	shl    r8,0x38
 1e6:	c1 e3 10             	shl    ebx,0x10
 1e9:	4c 09 c3             	or     rbx,r8
 1ec:	4c 31 cb             	xor    rbx,r9
 1ef:	48 01 cb             	add    rbx,rcx
 1f2:	49 89 dc             	mov    r12,rbx
 1f5:	e9 80 fe ff ff       	jmp    0x7a
 1fa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
 200:	49 c1 e1 20          	shl    r9,0x20
 204:	4d 09 d1             	or     r9,r10
 207:	4d 01 cc             	add    r12,r9
 20a:	e9 6b fe ff ff       	jmp    0x7a
 20f:	31 c0                	xor    eax,eax
 211:	c3                   	ret
 212:	48 8b 44 24 f0       	mov    rax,QWORD PTR [rsp-0x10]
 217:	4c 89 20             	mov    QWORD PTR [rax],r12
 21a:	b8 02 00 00 00       	mov    eax,0x2
 21f:	5b                   	pop    rbx
 220:	41 5c                	pop    r12
 222:	41 5d                	pop    r13
 224:	41 5e                	pop    r14
 226:	41 5f                	pop    r15
 228:	5d                   	pop    rbp
 229:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
