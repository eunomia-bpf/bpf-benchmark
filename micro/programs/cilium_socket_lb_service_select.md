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

0000000000001270 <_fini>:
    1270:	f3 0f 1e fa          	endbr64
    1274:	48 83 ec 08          	sub    rsp,0x8
    1278:	48 83 c4 08          	add    rsp,0x8
    127c:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 78 00 00 00 	sub    rsp,0x78
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 6d 03 00 00    	ja     0x39a
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 5d 03 00 00    	ja     0x39a
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 06 00 00 	add    rdi,0x610
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 4a 03 00 00    	ja     0x39a
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	c1 e7 08             	shl    edi,0x8
  58:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5d:	09 f7                	or     edi,esi
  5f:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  64:	c1 e6 10             	shl    esi,0x10
  67:	09 f7                	or     edi,esi
  69:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  6e:	c1 e6 18             	shl    esi,0x18
  71:	09 f7                	or     edi,esi
  73:	83 ff 40             	cmp    edi,0x40
  76:	0f 85 1e 03 00 00    	jne    0x39a
  7c:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  81:	c1 e7 08             	shl    edi,0x8
  84:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  89:	09 f7                	or     edi,esi
  8b:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  90:	c1 e6 10             	shl    esi,0x10
  93:	09 f7                	or     edi,esi
  95:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  9a:	c1 e6 18             	shl    esi,0x18
  9d:	09 f7                	or     edi,esi
  9f:	83 ff 18             	cmp    edi,0x18
  a2:	0f 85 f2 02 00 00    	jne    0x39a
  a8:	49 bf d3 08 a3 85 88 	movabs r15,0x243f6a8885a308d3
  af:	6a 3f 24 
  b2:	31 db                	xor    ebx,ebx
  b4:	48 89 55 88          	mov    QWORD PTR [rbp-0x78],rdx
  b8:	48 89 d1             	mov    rcx,rdx
  bb:	48 83 c1 13          	add    rcx,0x13
  bf:	eb 12                	jmp    0xd3
  c1:	48 83 c1 18          	add    rcx,0x18
  c5:	48 83 c3 01          	add    rbx,0x1
  c9:	48 83 fb 40          	cmp    rbx,0x40
  cd:	0f 84 70 02 00 00    	je     0x343
  d3:	48 89 5d f8          	mov    QWORD PTR [rbp-0x8],rbx
  d7:	4c 0f b6 41 09       	movzx  r8,BYTE PTR [rcx+0x9]
  dc:	bf 01 00 00 00       	mov    edi,0x1
  e1:	bb 01 00 00 00       	mov    ebx,0x1
  e6:	49 83 f8 11          	cmp    r8,0x11
  ea:	75 02                	jne    0xee
  ec:	31 db                	xor    ebx,ebx
  ee:	49 83 f8 06          	cmp    r8,0x6
  f2:	75 02                	jne    0xf6
  f4:	31 ff                	xor    edi,edi
  f6:	48 0f b6 41 02       	movzx  rax,BYTE PTR [rcx+0x2]
  fb:	c1 e0 08             	shl    eax,0x8
  fe:	48 0f b6 71 01       	movzx  rsi,BYTE PTR [rcx+0x1]
 103:	09 f0                	or     eax,esi
 105:	48 0f b6 71 03       	movzx  rsi,BYTE PTR [rcx+0x3]
 10a:	c1 e6 10             	shl    esi,0x10
 10d:	09 f0                	or     eax,esi
 10f:	48 0f b6 71 04       	movzx  rsi,BYTE PTR [rcx+0x4]
 114:	c1 e6 18             	shl    esi,0x18
 117:	09 f0                	or     eax,esi
 119:	48 0f b6 51 0a       	movzx  rdx,BYTE PTR [rcx+0xa]
 11e:	89 55 e8             	mov    DWORD PTR [rbp-0x18],edx
 121:	83 e2 02             	and    edx,0x2
 124:	89 c6                	mov    esi,eax
 126:	85 d2                	test   edx,edx
 128:	74 02                	je     0x12c
 12a:	31 f6                	xor    esi,esi
 12c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
 130:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
 135:	c1 e6 08             	shl    esi,0x8
 138:	4c 0f b6 69 07       	movzx  r13,BYTE PTR [rcx+0x7]
 13d:	44 09 ee             	or     esi,r13d
 140:	21 df                	and    edi,ebx
 142:	89 f3                	mov    ebx,esi
 144:	c1 e3 10             	shl    ebx,0x10
 147:	c1 fb 10             	sar    ebx,0x10
 14a:	83 e7 01             	and    edi,0x1
 14d:	85 ff                	test   edi,edi
 14f:	75 1d                	jne    0x16e
 151:	4c 0f b6 71 0c       	movzx  r14,BYTE PTR [rcx+0xc]
 156:	41 c1 e6 08          	shl    r14d,0x8
 15a:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 15f:	41 09 fe             	or     r14d,edi
 162:	41 81 e6 ff ff 00 00 	and    r14d,0xffff
 169:	45 85 f6             	test   r14d,r14d
 16c:	75 19                	jne    0x187
 16e:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 175:	49 c1 e0 20          	shl    r8,0x20
 179:	49 09 d8             	or     r8,rbx
 17c:	4d 31 f8             	xor    r8,r15
 17f:	4d 89 c7             	mov    r15,r8
 182:	e9 96 00 00 00       	jmp    0x21d
 187:	4c 89 45 d8          	mov    QWORD PTR [rbp-0x28],r8
 18b:	4c 89 7d e0          	mov    QWORD PTR [rbp-0x20],r15
 18f:	4c 0f b6 79 fe       	movzx  r15,BYTE PTR [rcx-0x2]
 194:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
 199:	89 7d 90             	mov    DWORD PTR [rbp-0x70],edi
 19c:	4c 0f b6 41 ff       	movzx  r8,BYTE PTR [rcx-0x1]
 1a1:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 1a6:	89 7d 98             	mov    DWORD PTR [rbp-0x68],edi
 1a9:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
 1ae:	89 7d a0             	mov    DWORD PTR [rbp-0x60],edi
 1b1:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 1b6:	89 7d d0             	mov    DWORD PTR [rbp-0x30],edi
 1b9:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 1be:	89 7d a8             	mov    DWORD PTR [rbp-0x58],edi
 1c1:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 1c6:	89 7d b0             	mov    DWORD PTR [rbp-0x50],edi
 1c9:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 1ce:	c1 e7 08             	shl    edi,0x8
 1d1:	4c 0f b6 69 05       	movzx  r13,BYTE PTR [rcx+0x5]
 1d6:	44 09 ef             	or     edi,r13d
 1d9:	4c 0f b6 69 13       	movzx  r13,BYTE PTR [rcx+0x13]
 1de:	44 89 6d b8          	mov    DWORD PTR [rbp-0x48],r13d
 1e2:	4c 0f b6 69 0f       	movzx  r13,BYTE PTR [rcx+0xf]
 1e7:	44 89 6d c0          	mov    DWORD PTR [rbp-0x40],r13d
 1eb:	4c 0f b6 69 10       	movzx  r13,BYTE PTR [rcx+0x10]
 1f0:	44 89 6d c8          	mov    DWORD PTR [rbp-0x38],r13d
 1f4:	4c 0f b6 69 14       	movzx  r13,BYTE PTR [rcx+0x14]
 1f9:	81 fb 2f 75 00 00    	cmp    ebx,0x752f
 1ff:	7f 25                	jg     0x226
 201:	85 d2                	test   edx,edx
 203:	75 21                	jne    0x226
 205:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 20c:	48 c1 e0 10          	shl    rax,0x10
 210:	48 09 f8             	or     rax,rdi
 213:	48 8b 7d e0          	mov    rdi,QWORD PTR [rbp-0x20]
 217:	48 01 f8             	add    rax,rdi
 21a:	49 89 c7             	mov    r15,rax
 21d:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 221:	e9 9b fe ff ff       	jmp    0xc1
 226:	41 c1 e7 08          	shl    r15d,0x8
 22a:	8b 55 90             	mov    edx,DWORD PTR [rbp-0x70]
 22d:	41 09 d7             	or     r15d,edx
 230:	41 c1 e0 10          	shl    r8d,0x10
 234:	45 09 c7             	or     r15d,r8d
 237:	8b 55 98             	mov    edx,DWORD PTR [rbp-0x68]
 23a:	c1 e2 08             	shl    edx,0x8
 23d:	44 8b 45 a0          	mov    r8d,DWORD PTR [rbp-0x60]
 241:	44 09 c2             	or     edx,r8d
 244:	44 8b 45 d0          	mov    r8d,DWORD PTR [rbp-0x30]
 248:	41 c1 e0 08          	shl    r8d,0x8
 24c:	8b 45 a8             	mov    eax,DWORD PTR [rbp-0x58]
 24f:	41 09 c0             	or     r8d,eax
 252:	8b 45 b0             	mov    eax,DWORD PTR [rbp-0x50]
 255:	c1 e0 18             	shl    eax,0x18
 258:	41 09 c7             	or     r15d,eax
 25b:	c1 e7 10             	shl    edi,0x10
 25e:	44 31 ff             	xor    edi,r15d
 261:	8b 45 b8             	mov    eax,DWORD PTR [rbp-0x48]
 264:	c1 e0 10             	shl    eax,0x10
 267:	41 09 c0             	or     r8d,eax
 26a:	8b 45 c0             	mov    eax,DWORD PTR [rbp-0x40]
 26d:	c1 e0 10             	shl    eax,0x10
 270:	09 c2                	or     edx,eax
 272:	81 e6 ff ff 00 00    	and    esi,0xffff
 278:	31 f7                	xor    edi,esi
 27a:	8b 75 c8             	mov    esi,DWORD PTR [rbp-0x38]
 27d:	c1 e6 18             	shl    esi,0x18
 280:	09 f2                	or     edx,esi
 282:	41 c1 e5 18          	shl    r13d,0x18
 286:	45 09 e8             	or     r8d,r13d
 289:	31 d7                	xor    edi,edx
 28b:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 28f:	31 f7                	xor    edi,esi
 291:	44 89 c2             	mov    edx,r8d
 294:	8b 75 e8             	mov    esi,DWORD PTR [rbp-0x18]
 297:	01 f2                	add    edx,esi
 299:	01 fa                	add    edx,edi
 29b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 29f:	83 e0 07             	and    eax,0x7
 2a2:	41 89 c5             	mov    r13d,eax
 2a5:	41 83 c5 01          	add    r13d,0x1
 2a9:	41 89 d7             	mov    r15d,edx
 2ac:	c4 42 11 f7 ff       	shlx   r15d,r15d,r13d
 2b1:	83 f0 ff             	xor    eax,0xffffffff
 2b4:	83 e0 1f             	and    eax,0x1f
 2b7:	c4 e2 7b f7 d2       	shrx   edx,edx,eax
 2bc:	41 09 d7             	or     r15d,edx
 2bf:	41 31 ff             	xor    r15d,edi
 2c2:	41 83 c0 01          	add    r8d,0x1
 2c6:	c1 e6 1d             	shl    esi,0x1d
 2c9:	c1 fe 1f             	sar    esi,0x1f
 2cc:	44 21 c6             	and    esi,r8d
 2cf:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 2d3:	48 8b 7d d8          	mov    rdi,QWORD PTR [rbp-0x28]
 2d7:	48 01 f8             	add    rax,rdi
 2da:	44 89 ff             	mov    edi,r15d
 2dd:	45 85 f6             	test   r14d,r14d
 2e0:	74 0f                	je     0x2f1
 2e2:	50                   	push   rax
 2e3:	52                   	push   rdx
 2e4:	89 f8                	mov    eax,edi
 2e6:	31 d2                	xor    edx,edx
 2e8:	41 f7 f6             	div    r14d
 2eb:	89 d7                	mov    edi,edx
 2ed:	5a                   	pop    rdx
 2ee:	58                   	pop    rax
 2ef:	eb 02                	jmp    0x2f3
 2f1:	89 ff                	mov    edi,edi
 2f3:	83 c7 01             	add    edi,0x1
 2f6:	31 f7                	xor    edi,esi
 2f8:	81 e3 ff ff 00 00    	and    ebx,0xffff
 2fe:	48 c1 e3 20          	shl    rbx,0x20
 302:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 306:	48 c1 e6 10          	shl    rsi,0x10
 30a:	48 31 de             	xor    rsi,rbx
 30d:	48 01 f0             	add    rax,rsi
 310:	48 c1 e7 30          	shl    rdi,0x30
 314:	4c 09 ff             	or     rdi,r15
 317:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 31b:	89 de                	mov    esi,ebx
 31d:	83 e6 07             	and    esi,0x7
 320:	89 f2                	mov    edx,esi
 322:	83 c2 01             	add    edx,0x1
 325:	83 f6 3f             	xor    esi,0x3f
 328:	49 89 f8             	mov    r8,rdi
 32b:	c4 42 cb f7 c0       	shrx   r8,r8,rsi
 330:	c4 e2 e9 f7 ff       	shlx   rdi,rdi,rdx
 335:	4c 09 c7             	or     rdi,r8
 338:	48 31 c7             	xor    rdi,rax
 33b:	49 89 ff             	mov    r15,rdi
 33e:	e9 7e fd ff ff       	jmp    0xc1
 343:	48 8b 75 88          	mov    rsi,QWORD PTR [rbp-0x78]
 347:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 34b:	4c 89 ff             	mov    rdi,r15
 34e:	48 c1 ef 38          	shr    rdi,0x38
 352:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 356:	4c 89 ff             	mov    rdi,r15
 359:	48 c1 ef 30          	shr    rdi,0x30
 35d:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 361:	4c 89 ff             	mov    rdi,r15
 364:	48 c1 ef 28          	shr    rdi,0x28
 368:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 36c:	4c 89 ff             	mov    rdi,r15
 36f:	48 c1 ef 20          	shr    rdi,0x20
 373:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 377:	4c 89 ff             	mov    rdi,r15
 37a:	48 c1 ef 18          	shr    rdi,0x18
 37e:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 382:	4c 89 ff             	mov    rdi,r15
 385:	48 c1 ef 10          	shr    rdi,0x10
 389:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 38d:	49 c1 ef 08          	shr    r15,0x8
 391:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 395:	b8 02 00 00 00       	mov    eax,0x2
 39a:	41 5f                	pop    r15
 39c:	41 5e                	pop    r14
 39e:	41 5d                	pop    r13
 3a0:	5b                   	pop    rbx
 3a1:	c9                   	leave
 3a2:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
