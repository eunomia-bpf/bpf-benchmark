# cilium_socket_lb_service_select

## Original C
```c
#include "common.h"

#define CILIUM_SOCKET_LB_RECORDS 64U
#define CILIUM_SOCKET_LB_RECORD_SIZE 24U
#define CILIUM_SOCKET_LB_INPUT_SIZE \
    (8U + CILIUM_SOCKET_LB_RECORDS * CILIUM_SOCKET_LB_RECORD_SIZE)
#define CILIUM_NODEPORT_MIN 30000U
#define CILIUM_NODEPORT_MAX 32767U

static __always_inline int
bench_cilium_socket_lb_service_select(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, CILIUM_SOCKET_LB_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != CILIUM_SOCKET_LB_RECORDS ||
        record_size != CILIUM_SOCKET_LB_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0x243F6A8885A308D3ULL;
    for (u32 index = 0; index < CILIUM_SOCKET_LB_RECORDS; index++) {
        u32 base = 8U + index * CILIUM_SOCKET_LB_RECORD_SIZE;
        u32 src_ip = micro_read_u32_le(data, base);
        u32 dst_ip = micro_read_u32_le(data, base + 4U);
        u16 sport = micro_read_u16_le(data, base + 8U);
        u16 dport = micro_read_u16_le(data, base + 10U);
        u8 proto = data[base + 12U];
        u8 flags = data[base + 13U];
        u16 svc_count = micro_read_u16_le(data, base + 14U);
        u32 cookie = micro_read_u32_le(data, base + 16U);
        u32 scope = micro_read_u32_le(data, base + 20U);
        u32 is_l4 = proto == 6U || proto == 17U;
        u32 is_nodeport = dport >= CILIUM_NODEPORT_MIN && dport <= CILIUM_NODEPORT_MAX;
        u32 wildcard = (flags & 2U) != 0U;
        u32 service_ip = wildcard ? 0U : dst_ip;
        u32 hash = cookie ^ src_ip ^ service_ip ^ ((u32)sport << 16U) ^ dport;

        if (is_l4 == 0U || svc_count == 0U) {
            acc ^= ((u64)proto << 32U) | dport;
            continue;
        }
        if (is_nodeport == 0U && wildcard == 0U) {
            acc += ((u64)dst_ip << 16U) ^ sport;
            continue;
        }

        hash ^= micro_rotl32(hash + scope + flags, (proto & 7U) + 1U);
        u32 backend = (hash % svc_count) + 1U;
        if ((flags & 4U) != 0U) {
            backend ^= scope + 1U;
        }

        acc += ((u64)service_ip << 16U) ^ ((u64)dport << 32U) ^ proto;
        acc ^= micro_rotl64(((u64)backend << 48U) | hash, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cilium_socket_lb_service_select_xdp,
    bench_cilium_socket_lb_service_select,
    cilium_socket_lb_service_select_input_value,
    CILIUM_SOCKET_LB_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <cilium_socket_lb_service_select_xdp>:
    1100:	4c 8b 07             	mov    r8,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	49 39 c8             	cmp    r8,rcx
    110c:	76 01                	jbe    110f <cilium_socket_lb_service_select_xdp+0xf>
    110e:	c3                   	ret
    110f:	49 8d 50 08          	lea    rdx,[r8+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <cilium_socket_lb_service_select_xdp+0xe>
    1118:	49 8d 90 10 06 00 00 	lea    rdx,[r8+0x610]
    111f:	48 39 ca             	cmp    rdx,rcx
    1122:	77 ea                	ja     110e <cilium_socket_lb_service_select_xdp+0xe>
    1124:	41 83 78 08 40       	cmp    DWORD PTR [r8+0x8],0x40
    1129:	75 e3                	jne    110e <cilium_socket_lb_service_select_xdp+0xe>
    112b:	41 83 78 0c 18       	cmp    DWORD PTR [r8+0xc],0x18
    1130:	75 dc                	jne    110e <cilium_socket_lb_service_select_xdp+0xe>
    1132:	55                   	push   rbp
    1133:	41 57                	push   r15
    1135:	41 56                	push   r14
    1137:	41 54                	push   r12
    1139:	53                   	push   rbx
    113a:	4d 8d 48 27          	lea    r9,[r8+0x27]
    113e:	48 bf d3 08 a3 85 88 	movabs rdi,0x243f6a8885a308d3
    1145:	6a 3f 24 
    1148:	45 31 d2             	xor    r10d,r10d
    114b:	eb 21                	jmp    116e <cilium_socket_lb_service_select_xdp+0x6e>
    114d:	0f 1f 00             	nop    DWORD PTR [rax]
    1150:	49 c1 e3 20          	shl    r11,0x20
    1154:	0f b7 c3             	movzx  eax,bx
    1157:	4c 09 d8             	or     rax,r11
    115a:	48 31 c7             	xor    rdi,rax
    115d:	49 ff c2             	inc    r10
    1160:	49 83 c1 18          	add    r9,0x18
    1164:	49 83 fa 40          	cmp    r10,0x40
    1168:	0f 84 ee 00 00 00    	je     125c <cilium_socket_lb_service_select_xdp+0x15c>
    116e:	41 8b 41 ed          	mov    eax,DWORD PTR [r9-0x13]
    1172:	41 0f b7 59 f3       	movzx  ebx,WORD PTR [r9-0xd]
    1177:	45 0f b6 59 f5       	movzx  r11d,BYTE PTR [r9-0xb]
    117c:	49 83 fb 11          	cmp    r11,0x11
    1180:	0f 95 c1             	setne  cl
    1183:	49 83 fb 06          	cmp    r11,0x6
    1187:	0f 95 c2             	setne  dl
    118a:	45 0f b6 79 f6       	movzx  r15d,BYTE PTR [r9-0xa]
    118f:	41 f6 c7 02          	test   r15b,0x2
    1193:	bd 00 00 00 00       	mov    ebp,0x0
    1198:	0f 44 e8             	cmove  ebp,eax
    119b:	84 ca                	test   dl,cl
    119d:	75 b1                	jne    1150 <cilium_socket_lb_service_select_xdp+0x50>
    119f:	45 0f b7 61 f7       	movzx  r12d,WORD PTR [r9-0x9]
    11a4:	66 45 85 e4          	test   r12w,r12w
    11a8:	74 a6                	je     1150 <cilium_socket_lb_service_select_xdp+0x50>
    11aa:	45 8b 71 fd          	mov    r14d,DWORD PTR [r9-0x3]
    11ae:	41 0f b7 49 f1       	movzx  ecx,WORD PTR [r9-0xf]
    11b3:	89 ca                	mov    edx,ecx
    11b5:	c1 e2 10             	shl    edx,0x10
    11b8:	41 33 51 e9          	xor    edx,DWORD PTR [r9-0x17]
    11bc:	31 da                	xor    edx,ebx
    11be:	41 33 51 f9          	xor    edx,DWORD PTR [r9-0x7]
    11c2:	0f bf f3             	movsx  esi,bx
    11c5:	81 fe 2f 75 00 00    	cmp    esi,0x752f
    11cb:	7f 23                	jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0>
    11cd:	44 89 fe             	mov    esi,r15d
    11d0:	83 e6 02             	and    esi,0x2
    11d3:	75 1b                	jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0>
    11d5:	89 c0                	mov    eax,eax
    11d7:	48 c1 e0 10          	shl    rax,0x10
    11db:	0f b7 c9             	movzx  ecx,cx
    11de:	48 09 c1             	or     rcx,rax
    11e1:	48 01 cf             	add    rdi,rcx
    11e4:	e9 74 ff ff ff       	jmp    115d <cilium_socket_lb_service_select_xdp+0x5d>
    11e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    11f0:	31 ea                	xor    edx,ebp
    11f2:	43 8d 34 3e          	lea    esi,[r14+r15*1]
    11f6:	01 d6                	add    esi,edx
    11f8:	44 89 d9             	mov    ecx,r11d
    11fb:	83 e1 07             	and    ecx,0x7
    11fe:	ff c1                	inc    ecx
    1200:	d3 c6                	rol    esi,cl
    1202:	31 d6                	xor    esi,edx
    1204:	89 f0                	mov    eax,esi
    1206:	31 d2                	xor    edx,edx
    1208:	41 f7 f4             	div    r12d
    120b:	ff c2                	inc    edx
    120d:	41 c1 e7 1d          	shl    r15d,0x1d
    1211:	41 c1 ff 1f          	sar    r15d,0x1f
    1215:	41 ff c6             	inc    r14d
    1218:	45 21 fe             	and    r14d,r15d
    121b:	41 31 d6             	xor    r14d,edx
    121e:	89 e8                	mov    eax,ebp
    1220:	48 c1 e0 10          	shl    rax,0x10
    1224:	0f b7 d3             	movzx  edx,bx
    1227:	48 c1 e2 20          	shl    rdx,0x20
    122b:	48 31 c2             	xor    rdx,rax
    122e:	49 c1 e6 30          	shl    r14,0x30
    1232:	4c 09 f6             	or     rsi,r14
    1235:	44 89 d0             	mov    eax,r10d
    1238:	83 e0 07             	and    eax,0x7
    123b:	8d 48 01             	lea    ecx,[rax+0x1]
    123e:	48 89 f3             	mov    rbx,rsi
    1241:	48 d3 e3             	shl    rbx,cl
    1244:	f6 d0                	not    al
    1246:	89 c1                	mov    ecx,eax
    1248:	48 d3 ee             	shr    rsi,cl
    124b:	4c 01 df             	add    rdi,r11
    124e:	48 01 d7             	add    rdi,rdx
    1251:	48 09 de             	or     rsi,rbx
    1254:	48 31 f7             	xor    rdi,rsi
    1257:	e9 01 ff ff ff       	jmp    115d <cilium_socket_lb_service_select_xdp+0x5d>
    125c:	49 89 38             	mov    QWORD PTR [r8],rdi
    125f:	b8 02 00 00 00       	mov    eax,0x2
    1264:	5b                   	pop    rbx
    1265:	41 5c                	pop    r12
    1267:	41 5e                	pop    r14
    1269:	41 5f                	pop    r15
    126b:	5d                   	pop    rbp
    126c:	c3                   	ret

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
   c:	48 81 ec 88 00 00 00 	sub    rsp,0x88
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 03 04 00 00    	ja     0x430
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 f3 03 00 00    	ja     0x430
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 06 00 00 	add    rdi,0x610
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 e0 03 00 00    	ja     0x430
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 83 ff 40          	cmp    rdi,0x40
  85:	0f 85 a5 03 00 00    	jne    0x430
  8b:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  90:	48 c1 e7 08          	shl    rdi,0x8
  94:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  99:	48 09 f7             	or     rdi,rsi
  9c:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  a1:	48 c1 e6 10          	shl    rsi,0x10
  a5:	48 09 f7             	or     rdi,rsi
  a8:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  ad:	48 c1 e6 18          	shl    rsi,0x18
  b1:	48 09 f7             	or     rdi,rsi
  b4:	48 c1 e7 20          	shl    rdi,0x20
  b8:	48 c1 ef 20          	shr    rdi,0x20
  bc:	48 83 ff 18          	cmp    rdi,0x18
  c0:	0f 85 6a 03 00 00    	jne    0x430
  c6:	49 bf d3 08 a3 85 88 	movabs r15,0x243f6a8885a308d3
  cd:	6a 3f 24 
  d0:	31 db                	xor    ebx,ebx
  d2:	48 89 95 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rdx
  d9:	48 89 d1             	mov    rcx,rdx
  dc:	48 83 c1 13          	add    rcx,0x13
  e0:	eb 12                	jmp    0xf4
  e2:	48 83 c1 18          	add    rcx,0x18
  e6:	48 83 c3 01          	add    rbx,0x1
  ea:	48 83 fb 40          	cmp    rbx,0x40
  ee:	0f 84 e2 02 00 00    	je     0x3d6
  f4:	4c 0f b6 41 09       	movzx  r8,BYTE PTR [rcx+0x9]
  f9:	bf 01 00 00 00       	mov    edi,0x1
  fe:	be 01 00 00 00       	mov    esi,0x1
 103:	49 83 f8 11          	cmp    r8,0x11
 107:	75 02                	jne    0x10b
 109:	31 f6                	xor    esi,esi
 10b:	48 89 5d f8          	mov    QWORD PTR [rbp-0x8],rbx
 10f:	49 83 f8 06          	cmp    r8,0x6
 113:	75 02                	jne    0x117
 115:	31 ff                	xor    edi,edi
 117:	48 0f b6 59 02       	movzx  rbx,BYTE PTR [rcx+0x2]
 11c:	48 c1 e3 08          	shl    rbx,0x8
 120:	48 0f b6 51 01       	movzx  rdx,BYTE PTR [rcx+0x1]
 125:	48 09 d3             	or     rbx,rdx
 128:	48 0f b6 51 03       	movzx  rdx,BYTE PTR [rcx+0x3]
 12d:	48 c1 e2 10          	shl    rdx,0x10
 131:	48 09 d3             	or     rbx,rdx
 134:	48 0f b6 51 04       	movzx  rdx,BYTE PTR [rcx+0x4]
 139:	48 c1 e2 18          	shl    rdx,0x18
 13d:	48 09 d3             	or     rbx,rdx
 140:	48 0f b6 41 0a       	movzx  rax,BYTE PTR [rcx+0xa]
 145:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
 149:	48 83 e0 02          	and    rax,0x2
 14d:	48 89 da             	mov    rdx,rbx
 150:	48 85 c0             	test   rax,rax
 153:	74 02                	je     0x157
 155:	31 d2                	xor    edx,edx
 157:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
 15b:	4c 0f b6 69 08       	movzx  r13,BYTE PTR [rcx+0x8]
 160:	49 c1 e5 08          	shl    r13,0x8
 164:	48 0f b6 51 07       	movzx  rdx,BYTE PTR [rcx+0x7]
 169:	49 09 d5             	or     r13,rdx
 16c:	48 21 f7             	and    rdi,rsi
 16f:	4c 89 ee             	mov    rsi,r13
 172:	48 c1 e6 30          	shl    rsi,0x30
 176:	48 c1 fe 30          	sar    rsi,0x30
 17a:	48 83 e7 01          	and    rdi,0x1
 17e:	48 85 ff             	test   rdi,rdi
 181:	75 1d                	jne    0x1a0
 183:	4c 0f b6 71 0c       	movzx  r14,BYTE PTR [rcx+0xc]
 188:	49 c1 e6 08          	shl    r14,0x8
 18c:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 191:	49 09 fe             	or     r14,rdi
 194:	49 81 e6 ff ff 00 00 	and    r14,0xffff
 19b:	4d 85 f6             	test   r14,r14
 19e:	75 19                	jne    0x1b9
 1a0:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 1a7:	49 c1 e0 20          	shl    r8,0x20
 1ab:	49 09 f0             	or     r8,rsi
 1ae:	4d 31 f8             	xor    r8,r15
 1b1:	4d 89 c7             	mov    r15,r8
 1b4:	e9 ab 00 00 00       	jmp    0x264
 1b9:	4c 89 7d d8          	mov    QWORD PTR [rbp-0x28],r15
 1bd:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 1c2:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
 1c7:	48 89 7d 88          	mov    QWORD PTR [rbp-0x78],rdi
 1cb:	48 0f b6 79 ff       	movzx  rdi,BYTE PTR [rcx-0x1]
 1d0:	48 89 7d 90          	mov    QWORD PTR [rbp-0x70],rdi
 1d4:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 1d9:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 1dd:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 1e2:	48 89 7d 98          	mov    QWORD PTR [rbp-0x68],rdi
 1e6:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 1eb:	48 89 7d a0          	mov    QWORD PTR [rbp-0x60],rdi
 1ef:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 1f4:	48 c1 e7 08          	shl    rdi,0x8
 1f8:	48 0f b6 51 05       	movzx  rdx,BYTE PTR [rcx+0x5]
 1fd:	48 09 d7             	or     rdi,rdx
 200:	48 0f b6 51 13       	movzx  rdx,BYTE PTR [rcx+0x13]
 205:	48 89 55 a8          	mov    QWORD PTR [rbp-0x58],rdx
 209:	48 0f b6 51 0e       	movzx  rdx,BYTE PTR [rcx+0xe]
 20e:	48 89 55 c8          	mov    QWORD PTR [rbp-0x38],rdx
 212:	48 0f b6 51 0d       	movzx  rdx,BYTE PTR [rcx+0xd]
 217:	48 89 55 b0          	mov    QWORD PTR [rbp-0x50],rdx
 21b:	48 0f b6 51 0f       	movzx  rdx,BYTE PTR [rcx+0xf]
 220:	48 89 55 b8          	mov    QWORD PTR [rbp-0x48],rdx
 224:	48 0f b6 51 14       	movzx  rdx,BYTE PTR [rcx+0x14]
 229:	48 89 55 c0          	mov    QWORD PTR [rbp-0x40],rdx
 22d:	48 0f b6 51 10       	movzx  rdx,BYTE PTR [rcx+0x10]
 232:	48 89 55 d0          	mov    QWORD PTR [rbp-0x30],rdx
 236:	48 81 fe 2f 75 00 00 	cmp    rsi,0x752f
 23d:	7f 2e                	jg     0x26d
 23f:	48 85 c0             	test   rax,rax
 242:	75 29                	jne    0x26d
 244:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 24b:	48 c1 e3 20          	shl    rbx,0x20
 24f:	48 c1 eb 20          	shr    rbx,0x20
 253:	48 c1 e3 10          	shl    rbx,0x10
 257:	48 09 fb             	or     rbx,rdi
 25a:	48 8b 7d d8          	mov    rdi,QWORD PTR [rbp-0x28]
 25e:	48 01 fb             	add    rbx,rdi
 261:	49 89 df             	mov    r15,rbx
 264:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 268:	e9 75 fe ff ff       	jmp    0xe2
 26d:	49 c1 e7 08          	shl    r15,0x8
 271:	48 8b 55 88          	mov    rdx,QWORD PTR [rbp-0x78]
 275:	49 09 d7             	or     r15,rdx
 278:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
 27c:	48 c1 e2 10          	shl    rdx,0x10
 280:	49 09 d7             	or     r15,rdx
 283:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 287:	48 c1 e0 08          	shl    rax,0x8
 28b:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
 28f:	48 09 d0             	or     rax,rdx
 292:	48 8b 55 a0          	mov    rdx,QWORD PTR [rbp-0x60]
 296:	48 c1 e2 18          	shl    rdx,0x18
 29a:	49 09 d7             	or     r15,rdx
 29d:	48 c1 e7 10          	shl    rdi,0x10
 2a1:	4c 31 ff             	xor    rdi,r15
 2a4:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
 2a8:	48 c1 e2 10          	shl    rdx,0x10
 2ac:	48 09 d0             	or     rax,rdx
 2af:	4c 8b 7d c8          	mov    r15,QWORD PTR [rbp-0x38]
 2b3:	49 c1 e7 08          	shl    r15,0x8
 2b7:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
 2bb:	49 09 d7             	or     r15,rdx
 2be:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 2c2:	48 c1 e2 10          	shl    rdx,0x10
 2c6:	49 09 d7             	or     r15,rdx
 2c9:	49 81 e5 ff ff 00 00 	and    r13,0xffff
 2d0:	4c 31 ef             	xor    rdi,r13
 2d3:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 2d7:	48 c1 e2 18          	shl    rdx,0x18
 2db:	48 09 d0             	or     rax,rdx
 2de:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
 2e2:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 2e6:	48 c1 e2 18          	shl    rdx,0x18
 2ea:	49 09 d7             	or     r15,rdx
 2ed:	4c 31 ff             	xor    rdi,r15
 2f0:	4c 89 c2             	mov    rdx,r8
 2f3:	48 89 55 80          	mov    QWORD PTR [rbp-0x80],rdx
 2f7:	4c 8b 45 e8          	mov    r8,QWORD PTR [rbp-0x18]
 2fb:	4c 31 c7             	xor    rdi,r8
 2fe:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 302:	4c 01 f8             	add    rax,r15
 305:	48 01 f8             	add    rax,rdi
 308:	48 89 d3             	mov    rbx,rdx
 30b:	48 83 e3 07          	and    rbx,0x7
 30f:	49 89 dd             	mov    r13,rbx
 312:	49 83 c5 01          	add    r13,0x1
 316:	48 89 c2             	mov    rdx,rax
 319:	c4 e2 91 f7 d2       	shlx   rdx,rdx,r13
 31e:	48 c1 e0 20          	shl    rax,0x20
 322:	48 c1 e8 20          	shr    rax,0x20
 326:	48 83 f3 ff          	xor    rbx,0xffffffffffffffff
 32a:	48 83 e3 1f          	and    rbx,0x1f
 32e:	c4 e2 e3 f7 c0       	shrx   rax,rax,rbx
 333:	48 09 c2             	or     rdx,rax
 336:	48 31 fa             	xor    rdx,rdi
 339:	48 8b 7d e0          	mov    rdi,QWORD PTR [rbp-0x20]
 33d:	48 83 c7 01          	add    rdi,0x1
 341:	49 c1 e7 3d          	shl    r15,0x3d
 345:	49 c1 ff 20          	sar    r15,0x20
 349:	49 c1 ef 1f          	shr    r15,0x1f
 34d:	49 21 ff             	and    r15,rdi
 350:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 354:	48 8b 7d 80          	mov    rdi,QWORD PTR [rbp-0x80]
 358:	48 01 f8             	add    rax,rdi
 35b:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 362:	48 c1 e6 20          	shl    rsi,0x20
 366:	49 c1 e0 20          	shl    r8,0x20
 36a:	49 c1 e8 20          	shr    r8,0x20
 36e:	49 c1 e0 10          	shl    r8,0x10
 372:	49 31 f0             	xor    r8,rsi
 375:	4c 01 c0             	add    rax,r8
 378:	48 c1 e2 20          	shl    rdx,0x20
 37c:	48 c1 ea 20          	shr    rdx,0x20
 380:	48 89 d7             	mov    rdi,rdx
 383:	4d 85 f6             	test   r14,r14
 386:	74 0f                	je     0x397
 388:	50                   	push   rax
 389:	52                   	push   rdx
 38a:	48 89 f8             	mov    rax,rdi
 38d:	31 d2                	xor    edx,edx
 38f:	49 f7 f6             	div    r14
 392:	48 89 d7             	mov    rdi,rdx
 395:	5a                   	pop    rdx
 396:	58                   	pop    rax
 397:	48 83 c7 01          	add    rdi,0x1
 39b:	4c 31 ff             	xor    rdi,r15
 39e:	48 c1 e7 30          	shl    rdi,0x30
 3a2:	48 09 d7             	or     rdi,rdx
 3a5:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 3a9:	48 89 de             	mov    rsi,rbx
 3ac:	48 83 e6 07          	and    rsi,0x7
 3b0:	48 89 f2             	mov    rdx,rsi
 3b3:	48 83 c2 01          	add    rdx,0x1
 3b7:	48 83 f6 3f          	xor    rsi,0x3f
 3bb:	49 89 f8             	mov    r8,rdi
 3be:	c4 42 cb f7 c0       	shrx   r8,r8,rsi
 3c3:	c4 e2 e9 f7 ff       	shlx   rdi,rdi,rdx
 3c8:	4c 09 c7             	or     rdi,r8
 3cb:	48 31 c7             	xor    rdi,rax
 3ce:	49 89 ff             	mov    r15,rdi
 3d1:	e9 0c fd ff ff       	jmp    0xe2
 3d6:	4c 89 ff             	mov    rdi,r15
 3d9:	48 c1 ef 38          	shr    rdi,0x38
 3dd:	48 8b b5 78 ff ff ff 	mov    rsi,QWORD PTR [rbp-0x88]
 3e4:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3e8:	4c 89 ff             	mov    rdi,r15
 3eb:	48 c1 ef 30          	shr    rdi,0x30
 3ef:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3f3:	4c 89 ff             	mov    rdi,r15
 3f6:	48 c1 ef 28          	shr    rdi,0x28
 3fa:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 3fe:	4c 89 ff             	mov    rdi,r15
 401:	48 c1 ef 20          	shr    rdi,0x20
 405:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 409:	4c 89 ff             	mov    rdi,r15
 40c:	48 c1 ef 18          	shr    rdi,0x18
 410:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 414:	4c 89 ff             	mov    rdi,r15
 417:	48 c1 ef 10          	shr    rdi,0x10
 41b:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 41f:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 423:	49 c1 ef 08          	shr    r15,0x8
 427:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 42b:	b8 02 00 00 00       	mov    eax,0x2
 430:	41 5f                	pop    r15
 432:	41 5e                	pop    r14
 434:	41 5d                	pop    r13
 436:	5b                   	pop    rbx
 437:	c9                   	leave
 438:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 37                	mov    esi,DWORD PTR [rdi]
   6:	8b 4f 04             	mov    ecx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 ce                	cmp    esi,ecx
   d:	0f 87 a6 01 00 00    	ja     0x1b9
  13:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  17:	48 39 ca             	cmp    rdx,rcx
  1a:	0f 87 99 01 00 00    	ja     0x1b9
  20:	48 8d 96 10 06 00 00 	lea    rdx,[rsi+0x610]
  27:	48 39 ca             	cmp    rdx,rcx
  2a:	0f 87 89 01 00 00    	ja     0x1b9
  30:	83 7e 08 40          	cmp    DWORD PTR [rsi+0x8],0x40
  34:	0f 85 65 01 00 00    	jne    0x19f
  3a:	83 7e 0c 18          	cmp    DWORD PTR [rsi+0xc],0x18
  3e:	0f 85 5b 01 00 00    	jne    0x19f
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 89 74 24 f8       	mov    QWORD PTR [rsp-0x8],rsi
  53:	48 8d 7e 13          	lea    rdi,[rsi+0x13]
  57:	48 b8 d3 08 a3 85 88 	movabs rax,0x243f6a8885a308d3
  5e:	6a 3f 24 
  61:	45 31 c0             	xor    r8d,r8d
  64:	48 be 00 00 00 00 00 	movabs rsi,0x752f000000000000
  6b:	00 2f 75 
  6e:	eb 1b                	jmp    0x8b
  70:	48 c1 e2 20          	shl    rdx,0x20
  74:	48 09 d3             	or     rbx,rdx
  77:	48 31 d8             	xor    rax,rbx
  7a:	48 83 c7 18          	add    rdi,0x18
  7e:	49 ff c0             	inc    r8
  81:	49 83 f8 40          	cmp    r8,0x40
  85:	0f 84 17 01 00 00    	je     0x1a2
  8b:	0f b6 57 09          	movzx  edx,BYTE PTR [rdi+0x9]
  8f:	8b 4f 01             	mov    ecx,DWORD PTR [rdi+0x1]
  92:	44 0f b6 5f 0a       	movzx  r11d,BYTE PTR [rdi+0xa]
  97:	41 f6 c3 02          	test   r11b,0x2
  9b:	41 ba 00 00 00 00    	mov    r10d,0x0
  a1:	4c 0f 44 d1          	cmove  r10,rcx
  a5:	0f b7 5f 07          	movzx  ebx,WORD PTR [rdi+0x7]
  a9:	83 fa 11             	cmp    edx,0x11
  ac:	74 05                	je     0xb3
  ae:	83 fa 06             	cmp    edx,0x6
  b1:	75 bd                	jne    0x70
  b3:	44 0f b7 77 0b       	movzx  r14d,WORD PTR [rdi+0xb]
  b8:	4d 85 f6             	test   r14,r14
  bb:	74 b3                	je     0x70
  bd:	49 89 dc             	mov    r12,rbx
  c0:	49 c1 e4 30          	shl    r12,0x30
  c4:	44 0f b7 7f 05       	movzx  r15d,WORD PTR [rdi+0x5]
  c9:	49 39 f4             	cmp    r12,rsi
  cc:	7f 22                	jg     0xf0
  ce:	44 89 dd             	mov    ebp,r11d
  d1:	83 e5 02             	and    ebp,0x2
  d4:	75 1a                	jne    0xf0
  d6:	48 c1 e1 10          	shl    rcx,0x10
  da:	49 09 cf             	or     r15,rcx
  dd:	4c 01 f8             	add    rax,r15
  e0:	eb 98                	jmp    0x7a
  e2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  e9:	1f 84 00 00 00 00 00 
  f0:	0f b6 6f 13          	movzx  ebp,BYTE PTR [rdi+0x13]
  f4:	44 0f b7 67 11       	movzx  r12d,WORD PTR [rdi+0x11]
  f9:	44 8b 6f fd          	mov    r13d,DWORD PTR [rdi-0x3]
  fd:	44 8b 4f 0d          	mov    r9d,DWORD PTR [rdi+0xd]
 101:	41 c1 e7 10          	shl    r15d,0x10
 105:	c1 e5 10             	shl    ebp,0x10
 108:	0f b6 4f 14          	movzx  ecx,BYTE PTR [rdi+0x14]
 10c:	c1 e1 18             	shl    ecx,0x18
 10f:	09 e9                	or     ecx,ebp
 111:	4c 09 e1             	or     rcx,r12
 114:	4d 31 e9             	xor    r9,r13
 117:	49 09 df             	or     r15,rbx
 11a:	4d 31 cf             	xor    r15,r9
 11d:	4d 31 d7             	xor    r15,r10
 120:	4c 01 d9             	add    rcx,r11
 123:	4c 01 f9             	add    rcx,r15
 126:	41 89 d1             	mov    r9d,edx
 129:	41 80 e1 07          	and    r9b,0x7
 12d:	45 8d 69 01          	lea    r13d,[r9+0x1]
 131:	c4 62 91 f7 e9       	shlx   r13,rcx,r13
 136:	89 c9                	mov    ecx,ecx
 138:	41 80 f1 1f          	xor    r9b,0x1f
 13c:	c4 e2 b3 f7 c9       	shrx   rcx,rcx,r9
 141:	4c 09 e9             	or     rcx,r13
 144:	4c 31 f9             	xor    rcx,r15
 147:	41 ff c4             	inc    r12d
 14a:	49 c1 e3 3d          	shl    r11,0x3d
 14e:	49 c1 fb 20          	sar    r11,0x20
 152:	49 c1 eb 1f          	shr    r11,0x1f
 156:	45 21 e3             	and    r11d,r12d
 159:	48 01 d0             	add    rax,rdx
 15c:	48 c1 e3 20          	shl    rbx,0x20
 160:	49 c1 e2 10          	shl    r10,0x10
 164:	49 31 da             	xor    r10,rbx
 167:	49 01 c2             	add    r10,rax
 16a:	89 c8                	mov    eax,ecx
 16c:	31 d2                	xor    edx,edx
 16e:	41 f7 f6             	div    r14d
 171:	89 c8                	mov    eax,ecx
 173:	ff c2                	inc    edx
 175:	44 31 da             	xor    edx,r11d
 178:	48 c1 e2 30          	shl    rdx,0x30
 17c:	48 09 c2             	or     rdx,rax
 17f:	44 89 c0             	mov    eax,r8d
 182:	24 07                	and    al,0x7
 184:	89 c1                	mov    ecx,eax
 186:	f6 d1                	not    cl
 188:	c4 e2 f3 f7 ca       	shrx   rcx,rdx,rcx
 18d:	fe c0                	inc    al
 18f:	c4 e2 f9 f7 c2       	shlx   rax,rdx,rax
 194:	48 09 c8             	or     rax,rcx
 197:	4c 31 d0             	xor    rax,r10
 19a:	e9 db fe ff ff       	jmp    0x7a
 19f:	31 c0                	xor    eax,eax
 1a1:	c3                   	ret
 1a2:	48 8b 4c 24 f8       	mov    rcx,QWORD PTR [rsp-0x8]
 1a7:	48 89 01             	mov    QWORD PTR [rcx],rax
 1aa:	b8 02 00 00 00       	mov    eax,0x2
 1af:	5b                   	pop    rbx
 1b0:	41 5c                	pop    r12
 1b2:	41 5d                	pop    r13
 1b4:	41 5e                	pop    r14
 1b6:	41 5f                	pop    r15
 1b8:	5d                   	pop    rbp
 1b9:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 46
 *
 * - 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [r8+0x8],0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0x8],0x40]
 * - 0x112b: cmp    DWORD PTR [r8+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0xc],0x18]
 * - 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113a: lea    r9,[r8+0x27] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1148: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1150: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1157: or     rax,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x115d: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file]
 * - 0x1160: add    r9,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1164: cmp    r10,0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10,0x40]
 * - 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> [warning-unmapped: cannot lower cmp    r10,0x40 + je     125c <cilium_socket_lb_service_select_xdp+0x15c> to BPF branch]
 * - 0x116e: mov    eax,DWORD PTR [r9-0x13] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1172: movzx  ebx,WORD PTR [r9-0xd] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1177: movzx  r11d,BYTE PTR [r9-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x117c: cmp    r11,0x11 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x11]
 * - 0x1180: setne  cl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof]
 * - 0x1183: cmp    r11,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x6]
 * - 0x1187: setne  dl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof]
 * - 0x118a: movzx  r15d,BYTE PTR [r9-0xa] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1193: mov    ebp,0x0 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x0]
 * - 0x1198: cmove  ebp,eax [warning-unmapped: cmove operands are not supported]
 * - 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x119f: movzx  r12d,WORD PTR [r9-0x9] [warning-reg-remap: direct memory load via x86 kinsn selector; native r12 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11a4: test   r12w,r12w [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11aa: mov    r14d,DWORD PTR [r9-0x3] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ae: movzx  ecx,WORD PTR [r9-0xf] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11b8: xor    edx,DWORD PTR [r9-0x17] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11be: xor    edx,DWORD PTR [r9-0x7] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f0: xor    edx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x11f8: mov    ecx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r11d]
 * - 0x1208: div    r12d [warning-unmapped: unsupported mnemonic or operand form: div    r12d]
 * - 0x121e: mov    eax,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    eax,ebp]
 * - 0x1235: mov    eax,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r10d]
 * - 0x124b: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1264: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1265: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1267: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1269: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    r8,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_5, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    r8,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <cilium_socket_lb_service_select_xdp+0xf> [bpf-branch: lowered cmp    r8,rcx + jbe    110f <cilium_socket_lb_service_select_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_5, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -6),
    /* 0x1118: lea    rdx,[r8+0x610] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_5, 0, 0, 1, 0, 1552), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    rdx,rcx + ja     110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0x8],0x40] */
    /* 0x1129: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0x8],0x40 + jne    110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 64),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x18 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [r8+0xc],0x18] */
    /* 0x1130: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [r8+0xc],0x18 + jne    110e <cilium_socket_lb_service_select_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_5, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -15, 24),
    /* 0x1132: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113a: lea    r9,[r8+0x27] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_5, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113e: movabs rdi,0x243f6a8885a308d3 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x243f6a8885a308d3ULL),
    /* 0x1148: xor    r10d,r10d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x114b: jmp    116e <cilium_socket_lb_service_select_xdp+0x6e> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 4, 0),
    /* 0x114d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r11,0x20 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1154: movzx  eax,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1157: or     rax,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x115a: xor    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x115d: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file] */
    /* 0x1160: add    r9,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x1164: cmp    r10,0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10,0x40] */
    /* 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> [warning-unmapped: cannot lower cmp    r10,0x40 + je     125c <cilium_socket_lb_service_select_xdp+0x15c> to BPF branch] */
    /* 0x116e: mov    eax,DWORD PTR [r9-0x13] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_9, -19), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x1172: movzx  ebx,WORD PTR [r9-0xd] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_9, -13), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1177: movzx  r11d,BYTE PTR [r9-0xb] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x117c: cmp    r11,0x11 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x11] */
    /* 0x1180: setne  cl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof] */
    /* 0x1183: cmp    r11,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x6] */
    /* 0x1187: setne  dl [warning-unmapped: setne is flag-bound; automatic conversion needs an adjacent cmp/test proof] */
    /* 0x118a: movzx  r15d,BYTE PTR [r9-0xa] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_9, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x118f: test   r15b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x1193: mov    ebp,0x0 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x0] */
    /* 0x1198: cmove  ebp,eax [warning-unmapped: cmove operands are not supported] */
    /* 0x119b: test   dl,cl [exact-kinsn: testb reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x119f: movzx  r12d,WORD PTR [r9-0x9] [warning-reg-remap: direct memory load via x86 kinsn selector; native r12 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_9, -9), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11a4: test   r12w,r12w [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11aa: mov    r14d,DWORD PTR [r9-0x3] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_9, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11ae: movzx  ecx,WORD PTR [r9-0xf] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_9, -15), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11b3: mov    edx,ecx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_4, 0, 0),
    /* 0x11b5: shl    edx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 16),
    /* 0x11b8: xor    edx,DWORD PTR [r9-0x17] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_3, BPF_REG_9, -23, BPF_REG_6, 0), MICRO_HANDCRAFT_BPF_X86_XORL_MEM),
    /* 0x11bc: xor    edx,ebx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_6, 0, 0),
    /* 0x11be: xor    edx,DWORD PTR [r9-0x7] [warning-reg-remap: xorl memory-source kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_3, BPF_REG_9, -7, BPF_REG_6, 0), MICRO_HANDCRAFT_BPF_X86_XORL_MEM),
    /* 0x11c2: movsx  esi,bx [exact-kinsn: movswl reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVSWL_RR),
    /* 0x11c5: cmp    esi,0x752f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 29999), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11cb: jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x752f + jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_2, 0, 11, 29999),
    /* 0x11cd: mov    esi,r15d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x11d0: and    esi,0x2 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11d3: jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> [bpf-branch: lowered flags from and    esi,0x2 + jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_2, 0, 7, 0),
    /* 0x11d5: mov    eax,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_0, 0, 0),
    /* 0x11d7: shl    rax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x11db: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11de: or     rcx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x11e1: add    rdi,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x11e4: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -40, 0),
    /* 0x11e9: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: xor    edx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x11f2: lea    esi,[r14+r15*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_8, BPF_REG_9, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f6: add    esi,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x11f8: mov    ecx,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r11d] */
    /* 0x11fb: and    ecx,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11fe: inc    ecx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x1200: rol    esi,cl [exact-kinsn: roll cl kinsn; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_CL),
    /* 0x1202: xor    esi,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x1204: mov    eax,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_2, 0, 0),
    /* 0x1206: xor    edx,edx [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_3, 0, 0, 0),
    /* 0x1208: div    r12d [warning-unmapped: unsupported mnemonic or operand form: div    r12d] */
    /* 0x120b: inc    edx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_3, 0, 0, 1),
    /* 0x120d: shl    r15d,0x1d [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 29),
    /* 0x1211: sar    r15d,0x1f [bpf-jit: SAR immediate maps directly to BPF ARSH] */
    HC_RAW(BPF_ALU | BPF_ARSH | BPF_K, BPF_REG_9, 0, 0, 31),
    /* 0x1215: inc    r14d [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_8, 0, 0, 1),
    /* 0x1218: and    r14d,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_AND | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x121b: xor    r14d,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_3, 0, 0),
    /* 0x121e: mov    eax,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    eax,ebp] */
    /* 0x1220: shl    rax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x1224: movzx  edx,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1227: shl    rdx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 32),
    /* 0x122b: xor    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x122e: shl    r14,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 48),
    /* 0x1232: or     rsi,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_8, 0, 0),
    /* 0x1235: mov    eax,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    eax,r10d] */
    /* 0x1238: and    eax,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x123b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123e: mov    rbx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1241: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1244: not    al [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1246: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1248: shr    rsi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x124b: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x124e: add    rdi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x1251: or     rsi,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_6, 0, 0),
    /* 0x1254: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x1257: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -79, 0),
    /* 0x125c: mov    QWORD PTR [r8],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_5, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x125f: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1264: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1265: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1267: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1269: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126c: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
