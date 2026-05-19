# packet_record_bounds_window

## Original C
```c
#include "common.h"

#define PACKET_REDUNDANT_BOUNDS_RECORDS 32U
#define PACKET_REDUNDANT_BOUNDS_RECORD_SIZE 24U
#define PACKET_REDUNDANT_BOUNDS_INPUT_SIZE \
    (8U + PACKET_REDUNDANT_BOUNDS_RECORDS * PACKET_REDUNDANT_BOUNDS_RECORD_SIZE)

static __always_inline int
bench_packet_record_bounds_window(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != PACKET_REDUNDANT_BOUNDS_RECORDS ||
        record_size != PACKET_REDUNDANT_BOUNDS_RECORD_SIZE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, PACKET_REDUNDANT_BOUNDS_RECORDS * PACKET_REDUNDANT_BOUNDS_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0xD6E8FEB86659FD93ULL;
    for (u32 index = 0; index < PACKET_REDUNDANT_BOUNDS_RECORDS; index++) {
        u32 base = 8U + index * PACKET_REDUNDANT_BOUNDS_RECORD_SIZE;
        u32 slack;
        u32 selector;
        u32 lane0;
        u32 lane1;
        u32 lane2;
        u32 lane3;
        u16 tail0;
        u16 tail1;

        if (!micro_has_bytes(len, base, 4U)) {
            continue;
        }

        slack = data[base + 0U] & 3U;
        selector = data[base + 1U];

        /* This dominating window makes the narrower checks below redundant. */
        if (!micro_has_bytes(len, base, PACKET_REDUNDANT_BOUNDS_RECORD_SIZE + slack)) {
            continue;
        }
        if (!micro_has_bytes(len, base + 4U, 4U)) {
            continue;
        }
        lane0 = micro_read_u32_le(data, base + 4U);
        if (!micro_has_bytes(len, base + 8U, 4U)) {
            continue;
        }
        lane1 = micro_read_u32_le(data, base + 8U);
        if (!micro_has_bytes(len, base + 12U, 4U)) {
            continue;
        }
        lane2 = micro_read_u32_le(data, base + 12U);
        if (!micro_has_bytes(len, base + 16U, 4U)) {
            continue;
        }
        lane3 = micro_read_u32_le(data, base + 16U);
        if (!micro_has_bytes(len, base + 20U, 2U)) {
            continue;
        }
        tail0 = micro_read_u16_le(data, base + 20U);
        if (!micro_has_bytes(len, base + 22U, 2U)) {
            continue;
        }
        tail1 = micro_read_u16_le(data, base + 22U);

        acc += (u64)lane0 + lane1 + tail0;
        if ((selector & 1U) != 0U) {
            if (!micro_has_bytes(len, base + 12U, 8U)) {
                continue;
            }
            acc ^= ((u64)lane2 << 32U) | lane3;
        } else {
            if (!micro_has_bytes(len, base + 8U, 8U)) {
                continue;
            }
            acc += ((u64)lane1 << 32U) | lane2;
        }
        acc ^= (u64)lane3 << ((selector & 7U) * 4U);
        acc += (u64)tail1 << ((index & 3U) * 8U);
        acc = micro_rotl64(acc, ((selector ^ slack) & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(
    packet_record_bounds_window_xdp,
    bench_packet_record_bounds_window,
    PACKET_REDUNDANT_BOUNDS_INPUT_SIZE)
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

0000000000001100 <packet_record_bounds_window_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <packet_record_bounds_window_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <packet_record_bounds_window_xdp+0xe>
    1118:	48 8d b2 10 03 00 00 	lea    rsi,[rdx+0x310]
    111f:	48 39 ce             	cmp    rsi,rcx
    1122:	77 ea                	ja     110e <packet_record_bounds_window_xdp+0xe>
    1124:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    1128:	75 e4                	jne    110e <packet_record_bounds_window_xdp+0xe>
    112a:	83 7a 0c 18          	cmp    DWORD PTR [rdx+0xc],0x18
    112e:	75 de                	jne    110e <packet_record_bounds_window_xdp+0xe>
    1130:	41 56                	push   r14
    1132:	53                   	push   rbx
    1133:	48 8d 72 27          	lea    rsi,[rdx+0x27]
    1137:	49 b9 93 fd 59 66 b8 	movabs r9,0xd6e8feb86659fd93
    113e:	fe e8 d6 
    1141:	bf 00 03 00 00       	mov    edi,0x300
    1146:	45 31 c0             	xor    r8d,r8d
    1149:	eb 59                	jmp    11a4 <packet_record_bounds_window_xdp+0xa4>
    114b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1150:	49 c1 e6 20          	shl    r14,0x20
    1154:	89 c9                	mov    ecx,ecx
    1156:	4c 09 f1             	or     rcx,r14
    1159:	49 01 cb             	add    r11,rcx
    115c:	44 0f b7 4e ff       	movzx  r9d,WORD PTR [rsi-0x1]
    1161:	8d 0c 85 00 00 00 00 	lea    ecx,[rax*4+0x0]
    1168:	80 e1 1c             	and    cl,0x1c
    116b:	48 d3 e3             	shl    rbx,cl
    116e:	4c 31 db             	xor    rbx,r11
    1171:	44 89 c1             	mov    ecx,r8d
    1174:	80 e1 18             	and    cl,0x18
    1177:	49 d3 e1             	shl    r9,cl
    117a:	49 01 d9             	add    r9,rbx
    117d:	83 e0 07             	and    eax,0x7
    1180:	44 31 d0             	xor    eax,r10d
    1183:	8d 48 01             	lea    ecx,[rax+0x1]
    1186:	4d 89 ca             	mov    r10,r9
    1189:	49 d3 e2             	shl    r10,cl
    118c:	f6 d0                	not    al
    118e:	89 c1                	mov    ecx,eax
    1190:	49 d3 e9             	shr    r9,cl
    1193:	4d 09 d1             	or     r9,r10
    1196:	49 83 c0 08          	add    r8,0x8
    119a:	48 83 c6 18          	add    rsi,0x18
    119e:	48 83 c7 e8          	add    rdi,0xffffffffffffffe8
    11a2:	74 48                	je     11ec <packet_record_bounds_window_xdp+0xec>
    11a4:	44 0f b6 56 e9       	movzx  r10d,BYTE PTR [rsi-0x17]
    11a9:	41 83 e2 03          	and    r10d,0x3
    11ad:	49 8d 42 18          	lea    rax,[r10+0x18]
    11b1:	48 39 c7             	cmp    rdi,rax
    11b4:	72 e0                	jb     1196 <packet_record_bounds_window_xdp+0x96>
    11b6:	0f b6 46 ea          	movzx  eax,BYTE PTR [rsi-0x16]
    11ba:	8b 5e ed             	mov    ebx,DWORD PTR [rsi-0x13]
    11bd:	44 8b 76 f1          	mov    r14d,DWORD PTR [rsi-0xf]
    11c1:	8b 4e f5             	mov    ecx,DWORD PTR [rsi-0xb]
    11c4:	44 0f b7 5e fd       	movzx  r11d,WORD PTR [rsi-0x3]
    11c9:	4c 01 cb             	add    rbx,r9
    11cc:	4d 01 f3             	add    r11,r14
    11cf:	49 01 db             	add    r11,rbx
    11d2:	8b 5e f9             	mov    ebx,DWORD PTR [rsi-0x7]
    11d5:	a8 01                	test   al,0x1
    11d7:	0f 84 73 ff ff ff    	je     1150 <packet_record_bounds_window_xdp+0x50>
    11dd:	48 c1 e1 20          	shl    rcx,0x20
    11e1:	48 09 d9             	or     rcx,rbx
    11e4:	49 31 cb             	xor    r11,rcx
    11e7:	e9 70 ff ff ff       	jmp    115c <packet_record_bounds_window_xdp+0x5c>
    11ec:	4c 89 0a             	mov    QWORD PTR [rdx],r9
    11ef:	b8 02 00 00 00       	mov    eax,0x2
    11f4:	5b                   	pop    rbx
    11f5:	41 5e                	pop    r14
    11f7:	c3                   	ret

Disassembly of section .fini:

00000000000011f8 <_fini>:
    11f8:	f3 0f 1e fa          	endbr64
    11fc:	48 83 ec 08          	sub    rsp,0x8
    1200:	48 83 c4 08          	add    rsp,0x8
    1204:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 08 00 00 00 	sub    rsp,0x8
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 4e 02 00 00    	ja     0x27b
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 3e 02 00 00    	ja     0x27b
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 03 00 00 	add    rdi,0x310
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 2b 02 00 00    	ja     0x27b
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
  76:	0f 85 ff 01 00 00    	jne    0x27b
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
  a2:	0f 85 d3 01 00 00    	jne    0x27b
  a8:	49 b8 93 fd 59 66 b8 	movabs r8,0xd6e8feb86659fd93
  af:	fe e8 d6 
  b2:	31 f6                	xor    esi,esi
  b4:	ba 00 03 00 00       	mov    edx,0x300
  b9:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
  bd:	48 83 c1 14          	add    rcx,0x14
  c1:	eb 73                	jmp    0x136
  c3:	49 c1 e6 20          	shl    r14,0x20
  c7:	4d 09 c6             	or     r14,r8
  ca:	4d 01 f5             	add    r13,r14
  cd:	4d 89 e8             	mov    r8,r13
  d0:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
  d5:	4c 0f b6 69 13       	movzx  r13,BYTE PTR [rcx+0x13]
  da:	49 c1 e5 08          	shl    r13,0x8
  de:	49 09 fd             	or     r13,rdi
  e1:	48 89 f7             	mov    rdi,rsi
  e4:	48 83 e7 18          	and    rdi,0x18
  e8:	c4 42 c1 f7 ed       	shlx   r13,r13,rdi
  ed:	89 df                	mov    edi,ebx
  ef:	c1 e7 02             	shl    edi,0x2
  f2:	83 e7 1c             	and    edi,0x1c
  f5:	c4 42 c1 f7 ff       	shlx   r15,r15,rdi
  fa:	4d 31 f8             	xor    r8,r15
  fd:	4d 01 e8             	add    r8,r13
 100:	83 e3 07             	and    ebx,0x7
 103:	31 c3                	xor    ebx,eax
 105:	89 df                	mov    edi,ebx
 107:	83 f7 3f             	xor    edi,0x3f
 10a:	4c 89 c0             	mov    rax,r8
 10d:	c4 e2 c3 f7 c0       	shrx   rax,rax,rdi
 112:	83 c3 01             	add    ebx,0x1
 115:	c4 42 e1 f7 c0       	shlx   r8,r8,rbx
 11a:	49 09 c0             	or     r8,rax
 11d:	48 83 c1 18          	add    rcx,0x18
 121:	48 83 c2 e8          	add    rdx,0xffffffffffffffe8
 125:	48 83 c6 08          	add    rsi,0x8
 129:	48 81 fe 00 01 00 00 	cmp    rsi,0x100
 130:	0f 84 ee 00 00 00    	je     0x224
 136:	48 0f b6 41 fc       	movzx  rax,BYTE PTR [rcx-0x4]
 13b:	83 e0 03             	and    eax,0x3
 13e:	89 c7                	mov    edi,eax
 140:	83 cf 18             	or     edi,0x18
 143:	48 39 fa             	cmp    rdx,rdi
 146:	72 d5                	jb     0x11d
 148:	48 0f b6 59 fd       	movzx  rbx,BYTE PTR [rcx-0x3]
 14d:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 152:	4c 0f b6 69 01       	movzx  r13,BYTE PTR [rcx+0x1]
 157:	49 c1 e5 08          	shl    r13,0x8
 15b:	49 09 fd             	or     r13,rdi
 15e:	48 0f b6 79 04       	movzx  rdi,BYTE PTR [rcx+0x4]
 163:	4c 0f b6 71 05       	movzx  r14,BYTE PTR [rcx+0x5]
 168:	49 c1 e6 08          	shl    r14,0x8
 16c:	49 09 fe             	or     r14,rdi
 16f:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 174:	48 c1 e7 10          	shl    rdi,0x10
 178:	49 09 fd             	or     r13,rdi
 17b:	48 0f b6 79 03       	movzx  rdi,BYTE PTR [rcx+0x3]
 180:	48 c1 e7 18          	shl    rdi,0x18
 184:	49 09 fd             	or     r13,rdi
 187:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 18c:	48 c1 e7 10          	shl    rdi,0x10
 190:	49 09 fe             	or     r14,rdi
 193:	4c 0f b6 79 10       	movzx  r15,BYTE PTR [rcx+0x10]
 198:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 19d:	48 c1 e7 08          	shl    rdi,0x8
 1a1:	4c 09 ff             	or     rdi,r15
 1a4:	4c 0f b6 79 07       	movzx  r15,BYTE PTR [rcx+0x7]
 1a9:	49 c1 e7 18          	shl    r15,0x18
 1ad:	4d 09 fe             	or     r14,r15
 1b0:	4d 01 c5             	add    r13,r8
 1b3:	4c 0f b6 79 0d       	movzx  r15,BYTE PTR [rcx+0xd]
 1b8:	41 c1 e7 08          	shl    r15d,0x8
 1bc:	4c 0f b6 41 0c       	movzx  r8,BYTE PTR [rcx+0xc]
 1c1:	45 09 c7             	or     r15d,r8d
 1c4:	4c 0f b6 41 0e       	movzx  r8,BYTE PTR [rcx+0xe]
 1c9:	41 c1 e0 10          	shl    r8d,0x10
 1cd:	45 09 c7             	or     r15d,r8d
 1d0:	4d 01 f5             	add    r13,r14
 1d3:	49 01 fd             	add    r13,rdi
 1d6:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
 1db:	c1 e7 18             	shl    edi,0x18
 1de:	41 09 ff             	or     r15d,edi
 1e1:	4c 0f b6 41 09       	movzx  r8,BYTE PTR [rcx+0x9]
 1e6:	41 c1 e0 08          	shl    r8d,0x8
 1ea:	48 0f b6 79 08       	movzx  rdi,BYTE PTR [rcx+0x8]
 1ef:	41 09 f8             	or     r8d,edi
 1f2:	48 0f b6 79 0a       	movzx  rdi,BYTE PTR [rcx+0xa]
 1f7:	c1 e7 10             	shl    edi,0x10
 1fa:	41 09 f8             	or     r8d,edi
 1fd:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 202:	c1 e7 18             	shl    edi,0x18
 205:	41 09 f8             	or     r8d,edi
 208:	89 df                	mov    edi,ebx
 20a:	83 e7 01             	and    edi,0x1
 20d:	85 ff                	test   edi,edi
 20f:	0f 84 ae fe ff ff    	je     0xc3
 215:	49 c1 e0 20          	shl    r8,0x20
 219:	4d 09 f8             	or     r8,r15
 21c:	4d 31 c5             	xor    r13,r8
 21f:	e9 a9 fe ff ff       	jmp    0xcd
 224:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 228:	44 88 46 00          	mov    BYTE PTR [rsi+0x0],r8b
 22c:	4c 89 c7             	mov    rdi,r8
 22f:	48 c1 ef 38          	shr    rdi,0x38
 233:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 237:	4c 89 c7             	mov    rdi,r8
 23a:	48 c1 ef 30          	shr    rdi,0x30
 23e:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 242:	4c 89 c7             	mov    rdi,r8
 245:	48 c1 ef 28          	shr    rdi,0x28
 249:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 24d:	4c 89 c7             	mov    rdi,r8
 250:	48 c1 ef 20          	shr    rdi,0x20
 254:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 258:	4c 89 c7             	mov    rdi,r8
 25b:	48 c1 ef 18          	shr    rdi,0x18
 25f:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 263:	4c 89 c7             	mov    rdi,r8
 266:	48 c1 ef 10          	shr    rdi,0x10
 26a:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 26e:	49 c1 e8 08          	shr    r8,0x8
 272:	44 88 46 01          	mov    BYTE PTR [rsi+0x1],r8b
 276:	b8 02 00 00 00       	mov    eax,0x2
 27b:	41 5f                	pop    r15
 27d:	41 5e                	pop    r14
 27f:	41 5d                	pop    r13
 281:	5b                   	pop    rbx
 282:	c9                   	leave
 283:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
