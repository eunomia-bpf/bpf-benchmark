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

00000000000012b0 <_fini>:
    12b0:	f3 0f 1e fa          	endbr64
    12b4:	48 83 ec 08          	sub    rsp,0x8
    12b8:	48 83 c4 08          	add    rsp,0x8
    12bc:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 20 00 00 00 	sub    rsp,0x20
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 37 03 00 00    	ja     0x364
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 27 03 00 00    	ja     0x364
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 03 00 00 	add    rdi,0x310
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 14 03 00 00    	ja     0x364
  50:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
  55:	c1 e7 08             	shl    edi,0x8
  58:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  5d:	09 f7                	or     edi,esi
  5f:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  64:	c1 e6 10             	shl    esi,0x10
  67:	09 f7                	or     edi,esi
  69:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  6e:	c1 e6 18             	shl    esi,0x18
  71:	09 f7                	or     edi,esi
  73:	83 ff 20             	cmp    edi,0x20
  76:	0f 85 e8 02 00 00    	jne    0x364
  7c:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
  81:	c1 e7 08             	shl    edi,0x8
  84:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
  89:	09 f7                	or     edi,esi
  8b:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
  90:	c1 e6 10             	shl    esi,0x10
  93:	09 f7                	or     edi,esi
  95:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
  9a:	c1 e6 18             	shl    esi,0x18
  9d:	09 f7                	or     edi,esi
  9f:	83 ff 18             	cmp    edi,0x18
  a2:	0f 85 bc 02 00 00    	jne    0x364
  a8:	49 be 2f 64 bd 78 64 	movabs r14,0xa0761d6478bd642f
  af:	1d 76 a0 
  b2:	31 d2                	xor    edx,edx
  b4:	48 89 4d e0          	mov    QWORD PTR [rbp-0x20],rcx
  b8:	48 83 c1 13          	add    rcx,0x13
  bc:	eb 4c                	jmp    0x10a
  be:	48 0f b6 41 fe       	movzx  rax,BYTE PTR [rcx-0x2]
  c3:	c1 e0 08             	shl    eax,0x8
  c6:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
  cb:	09 f8                	or     eax,edi
  cd:	48 0f b6 79 ff       	movzx  rdi,BYTE PTR [rcx-0x1]
  d2:	c1 e7 10             	shl    edi,0x10
  d5:	09 f8                	or     eax,edi
  d7:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
  dc:	c1 e7 18             	shl    edi,0x18
  df:	09 f8                	or     eax,edi
  e1:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
  e6:	83 ff 02             	cmp    edi,0x2
  e9:	74 5d                	je     0x148
  eb:	48 c1 e7 30          	shl    rdi,0x30
  ef:	48 09 c7             	or     rdi,rax
  f2:	4c 31 f7             	xor    rdi,r14
  f5:	49 89 fe             	mov    r14,rdi
  f8:	48 83 c1 18          	add    rcx,0x18
  fc:	48 83 c2 01          	add    rdx,0x1
 100:	48 83 fa 20          	cmp    rdx,0x20
 104:	0f 84 03 02 00 00    	je     0x30d
 10a:	48 0f b6 79 10       	movzx  rdi,BYTE PTR [rcx+0x10]
 10f:	c1 e7 08             	shl    edi,0x8
 112:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
 117:	09 f7                	or     edi,esi
 119:	41 bf 01 00 00 00    	mov    r15d,0x1
 11f:	41 89 fd             	mov    r13d,edi
 122:	41 c1 e5 10          	shl    r13d,0x10
 126:	41 c1 fd 10          	sar    r13d,0x10
 12a:	81 e7 ff ff 00 00    	and    edi,0xffff
 130:	83 ff 50             	cmp    edi,0x50
 133:	74 89                	je     0xbe
 135:	81 ff bb 01 00 00    	cmp    edi,0x1bb
 13b:	75 5b                	jne    0x198
 13d:	41 bf 02 00 00 00    	mov    r15d,0x2
 143:	e9 76 ff ff ff       	jmp    0xbe
 148:	48 0f b6 59 02       	movzx  rbx,BYTE PTR [rcx+0x2]
 14d:	c1 e3 08             	shl    ebx,0x8
 150:	48 0f b6 79 01       	movzx  rdi,BYTE PTR [rcx+0x1]
 155:	09 fb                	or     ebx,edi
 157:	48 0f b6 79 03       	movzx  rdi,BYTE PTR [rcx+0x3]
 15c:	c1 e7 10             	shl    edi,0x10
 15f:	09 fb                	or     ebx,edi
 161:	48 0f b6 79 04       	movzx  rdi,BYTE PTR [rcx+0x4]
 166:	c1 e7 18             	shl    edi,0x18
 169:	09 fb                	or     ebx,edi
 16b:	4c 0f b6 41 12       	movzx  r8,BYTE PTR [rcx+0x12]
 170:	44 89 c7             	mov    edi,r8d
 173:	83 e7 01             	and    edi,0x1
 176:	85 ff                	test   edi,edi
 178:	74 05                	je     0x17f
 17a:	45 85 ff             	test   r15d,r15d
 17d:	75 54                	jne    0x1d3
 17f:	49 81 e5 ff ff 00 00 	and    r13,0xffff
 186:	48 c1 e3 20          	shl    rbx,0x20
 18a:	4c 09 eb             	or     rbx,r13
 18d:	4c 01 f3             	add    rbx,r14
 190:	49 89 de             	mov    r14,rbx
 193:	e9 60 ff ff ff       	jmp    0xf8
 198:	41 bf 03 00 00 00    	mov    r15d,0x3
 19e:	41 81 fd fb 20 00 00 	cmp    r13d,0x20fb
 1a5:	0f 84 13 ff ff ff    	je     0xbe
 1ab:	41 81 fd 90 1f 00 00 	cmp    r13d,0x1f90
 1b2:	0f 84 06 ff ff ff    	je     0xbe
 1b8:	41 bf 04 00 00 00    	mov    r15d,0x4
 1be:	41 81 fd 2f 75 00 00 	cmp    r13d,0x752f
 1c5:	0f 8f f3 fe ff ff    	jg     0xbe
 1cb:	45 31 ff             	xor    r15d,r15d
 1ce:	e9 eb fe ff ff       	jmp    0xbe
 1d3:	4c 89 75 f8          	mov    QWORD PTR [rbp-0x8],r14
 1d7:	4c 0f b6 71 0a       	movzx  r14,BYTE PTR [rcx+0xa]
 1dc:	41 c1 e6 08          	shl    r14d,0x8
 1e0:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 1e5:	41 09 fe             	or     r14d,edi
 1e8:	48 0f b6 71 06       	movzx  rsi,BYTE PTR [rcx+0x6]
 1ed:	c1 e6 08             	shl    esi,0x8
 1f0:	48 0f b6 79 05       	movzx  rdi,BYTE PTR [rcx+0x5]
 1f5:	09 fe                	or     esi,edi
 1f7:	48 0f b6 79 07       	movzx  rdi,BYTE PTR [rcx+0x7]
 1fc:	c1 e7 10             	shl    edi,0x10
 1ff:	09 fe                	or     esi,edi
 201:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 206:	c1 e7 10             	shl    edi,0x10
 209:	41 09 fe             	or     r14d,edi
 20c:	48 0f b6 79 14       	movzx  rdi,BYTE PTR [rcx+0x14]
 211:	c1 e7 08             	shl    edi,0x8
 214:	44 89 45 e8          	mov    DWORD PTR [rbp-0x18],r8d
 218:	4c 0f b6 41 13       	movzx  r8,BYTE PTR [rcx+0x13]
 21d:	44 09 c7             	or     edi,r8d
 220:	4c 0f b6 41 0c       	movzx  r8,BYTE PTR [rcx+0xc]
 225:	41 c1 e0 18          	shl    r8d,0x18
 229:	45 09 c6             	or     r14d,r8d
 22c:	4c 0f b6 41 08       	movzx  r8,BYTE PTR [rcx+0x8]
 231:	41 c1 e0 18          	shl    r8d,0x18
 235:	44 09 c6             	or     esi,r8d
 238:	4c 0f b6 41 0e       	movzx  r8,BYTE PTR [rcx+0xe]
 23d:	4c 89 7d f0          	mov    QWORD PTR [rbp-0x10],r15
 241:	4c 0f b6 79 0d       	movzx  r15,BYTE PTR [rcx+0xd]
 246:	41 c1 e7 10          	shl    r15d,0x10
 24a:	41 c1 e0 18          	shl    r8d,0x18
 24e:	45 09 f8             	or     r8d,r15d
 251:	45 89 f7             	mov    r15d,r14d
 254:	41 c1 ef 19          	shr    r15d,0x19
 258:	41 c1 e6 07          	shl    r14d,0x7
 25c:	45 09 fe             	or     r14d,r15d
 25f:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 263:	41 31 f6             	xor    r14d,esi
 266:	45 31 c6             	xor    r14d,r8d
 269:	41 81 e5 ff ff 00 00 	and    r13d,0xffff
 270:	45 31 ee             	xor    r14d,r13d
 273:	89 de                	mov    esi,ebx
 275:	01 c6                	add    esi,eax
 277:	44 8b 6d e8          	mov    r13d,DWORD PTR [rbp-0x18]
 27b:	45 89 e8             	mov    r8d,r13d
 27e:	41 c1 e0 1e          	shl    r8d,0x1e
 282:	41 c1 f8 1f          	sar    r8d,0x1f
 286:	41 21 f0             	and    r8d,esi
 289:	45 31 c6             	xor    r14d,r8d
 28c:	89 fe                	mov    esi,edi
 28e:	81 e6 ff ff 00 00    	and    esi,0xffff
 294:	41 31 f6             	xor    r14d,esi
 297:	44 89 ee             	mov    esi,r13d
 29a:	83 e6 04             	and    esi,0x4
 29d:	85 f6                	test   esi,esi
 29f:	74 24                	je     0x2c5
 2a1:	be fd ff ff ff       	mov    esi,0xfffffffd
 2a6:	44 29 fe             	sub    esi,r15d
 2a9:	83 e6 1f             	and    esi,0x1f
 2ac:	45 89 f0             	mov    r8d,r14d
 2af:	c4 42 4b f7 c0       	shrx   r8d,r8d,esi
 2b4:	44 89 fe             	mov    esi,r15d
 2b7:	83 c6 03             	add    esi,0x3
 2ba:	83 e6 1f             	and    esi,0x1f
 2bd:	c4 42 49 f7 f6       	shlx   r14d,r14d,esi
 2c2:	45 09 c6             	or     r14d,r8d
 2c5:	49 c1 e7 38          	shl    r15,0x38
 2c9:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 2d0:	48 c1 e7 10          	shl    rdi,0x10
 2d4:	49 09 ff             	or     r15,rdi
 2d7:	49 c1 e6 20          	shl    r14,0x20
 2db:	49 09 c6             	or     r14,rax
 2de:	49 31 df             	xor    r15,rbx
 2e1:	89 d7                	mov    edi,edx
 2e3:	83 e7 07             	and    edi,0x7
 2e6:	89 fe                	mov    esi,edi
 2e8:	83 f6 3f             	xor    esi,0x3f
 2eb:	4d 89 f0             	mov    r8,r14
 2ee:	c4 42 cb f7 c0       	shrx   r8,r8,rsi
 2f3:	83 c7 01             	add    edi,0x1
 2f6:	c4 42 c1 f7 f6       	shlx   r14,r14,rdi
 2fb:	4d 09 c6             	or     r14,r8
 2fe:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 302:	49 31 fe             	xor    r14,rdi
 305:	4d 01 fe             	add    r14,r15
 308:	e9 eb fd ff ff       	jmp    0xf8
 30d:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 311:	44 88 76 00          	mov    BYTE PTR [rsi+0x0],r14b
 315:	4c 89 f7             	mov    rdi,r14
 318:	48 c1 ef 38          	shr    rdi,0x38
 31c:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 320:	4c 89 f7             	mov    rdi,r14
 323:	48 c1 ef 30          	shr    rdi,0x30
 327:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 32b:	4c 89 f7             	mov    rdi,r14
 32e:	48 c1 ef 28          	shr    rdi,0x28
 332:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 336:	4c 89 f7             	mov    rdi,r14
 339:	48 c1 ef 20          	shr    rdi,0x20
 33d:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 341:	4c 89 f7             	mov    rdi,r14
 344:	48 c1 ef 18          	shr    rdi,0x18
 348:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 34c:	4c 89 f7             	mov    rdi,r14
 34f:	48 c1 ef 10          	shr    rdi,0x10
 353:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 357:	49 c1 ee 08          	shr    r14,0x8
 35b:	44 88 76 01          	mov    BYTE PTR [rsi+0x1],r14b
 35f:	b8 02 00 00 00       	mov    eax,0x2
 364:	41 5f                	pop    r15
 366:	41 5e                	pop    r14
 368:	41 5d                	pop    r13
 36a:	5b                   	pop    rbx
 36b:	c9                   	leave
 36c:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
