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
#define HC_LEA_ARCH_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | (1ULL << 48))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    r8,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_R8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    r8,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <cilium_socket_lb_service_select_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (4) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x110f: lea    rdx,[r8+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-9) - 1, 0),
    /* 0x1118: lea    rdx,[r8+0x610] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_R8, 0, 0, 1, 0, 1552), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-16) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [r8+0x8],0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1129: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-20) - 1, 64),
    /* 0x112b: cmp    DWORD PTR [r8+0xc],0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1130: jne    110e <cilium_socket_lb_service_select_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-24) - 1, 24),
    /* 0x1132: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113a: lea    r9,[r8+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R8, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113e: movabs rdi,0x243f6a8885a308d3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x243f6a8885a308d3ULL),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDI, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1148: xor    r10d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114b: jmp    116e <cilium_socket_lb_service_select_xdp+0x6e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (16) - 1, 0),
    /* 0x114d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r11,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1154: movzx  eax,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1157: or     rax,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x115a: xor    rdi,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x115d: inc    r10 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1160: add    r9,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1164: cmp    r10,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1168: je     125c <cilium_socket_lb_service_select_xdp+0x15c> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (145) - 1, 64),
    /* 0x116e: mov    eax,DWORD PTR [r9-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_R9, -19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1172: movzx  ebx,WORD PTR [r9-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBX, HC_X86_R9, -13), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1177: movzx  r11d,BYTE PTR [r9-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_R9, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x117c: cmp    r11,0x11 [exact-kinsn: cmp64 reg,imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 17), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1180: setne  cl [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_STACK_PAYLOAD(HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SETNE),
    /* 0x1183: cmp    r11,0x6 [exact-kinsn: cmp64 reg,imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 6), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1187: setne  dl [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_STACK_PAYLOAD(HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_SETNE),
    /* 0x118a: movzx  r15d,BYTE PTR [r9-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R15, HC_X86_R9, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118f: test   r15b,0x2 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R15, 2), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1193: mov    ebp,0x0 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: cmove  ebp,eax [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_ARCH_STACK_PAYLOAD(HC_X86_RBP, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_CMOVEL),
    /* 0x119b: test   dl,cl [exact-kinsn: test8 reg,reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x119d: jne    1150 <cilium_socket_lb_service_select_xdp+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-42) - 1, 0),
    /* 0x119f: movzx  r12d,WORD PTR [r9-0x9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R12, HC_X86_R9, -9), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a4: test   r12w,r12w [control-flow-operand: test folded into BPF branch] */
    /* 0x11a8: je     1150 <cilium_socket_lb_service_select_xdp+0x50> [exact-bpf: je as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, 65535),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-48) - 1, 0),
    /* 0x11aa: mov    r14d,DWORD PTR [r9-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_R9, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ae: movzx  ecx,WORD PTR [r9-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_R9, -15), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b3: mov    edx,ecx [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b5: shl    edx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b8: xor    edx,DWORD PTR [r9-0x17] [exact-kinsn: xor32 memory-source kinsn] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDX, HC_X86_R9, -23), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bc: xor    edx,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11be: xor    edx,DWORD PTR [r9-0x7] [exact-kinsn: xor32 memory-source kinsn] */
    HC_KINSN(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDX, HC_X86_R9, -7), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11c2: movsx  esi,bx [exact-kinsn: movswl reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVSWL),
    /* 0x11c5: cmp    esi,0x752f [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11cb: jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0> [exact-bpf: jg as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_6, 0, (19) - 1, 29999),
    /* 0x11cd: mov    esi,r15d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d0: and    esi,0x2 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RSI, 2), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11d3: jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (12) - 1, 0),
    /* 0x11d5: mov    eax,eax [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d7: shl    rax,0x10 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11db: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11de: or     rcx,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e1: add    rdi,rcx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11e4: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-77) - 1, 0),
    /* 0x11e9: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: xor    edx,ebp [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11f2: lea    esi,[r14+r15*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_R14, HC_X86_R15, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f6: add    esi,edx [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11f8: mov    ecx,r11d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fb: and    ecx,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11fe: inc    ecx [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1200: rol    esi,cl [exact-kinsn: roll cl kinsn] */
    HC_KINSN(HC_ROTATE_ARCH_CL_PAYLOAD(HC_X86_RSI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1202: xor    esi,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1204: mov    eax,esi [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1206: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1208: div    r12d [exact-kinsn: divl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_DIVL),
    /* 0x120b: inc    edx [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x120d: shl    r15d,0x1d [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R15, 29), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1211: sar    r15d,0x1f [exact-kinsn: sar32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R15, 31), MICRO_HANDCRAFT_BPF_X86_SARL),
    /* 0x1215: inc    r14d [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1218: and    r14d,r15d [exact-kinsn: and32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x121b: xor    r14d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x121e: mov    eax,ebp [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1220: shl    rax,0x10 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1224: movzx  edx,bx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1227: shl    rdx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x122b: xor    rdx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x122e: shl    r14,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R14, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1232: or     rsi,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1235: mov    eax,r10d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1238: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x123b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x123e: mov    rbx,rsi [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1241: shl    rbx,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1244: not    al [exact-kinsn: not8 reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1246: mov    ecx,eax [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1248: shr    rsi,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x124b: add    rdi,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x124e: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1251: or     rsi,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1254: xor    rdi,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1257: jmp    115d <cilium_socket_lb_service_select_xdp+0x5d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-150) - 1, 0),
    /* 0x125c: mov    QWORD PTR [r8],rdi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDI, HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x125f: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1264: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1265: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1267: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1269: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126b: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x126c: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
