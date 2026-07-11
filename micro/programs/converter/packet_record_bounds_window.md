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
  27:	0f 87 96 02 00 00    	ja     0x2c3
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 86 02 00 00    	ja     0x2c3
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 03 00 00 	add    rdi,0x310
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 73 02 00 00    	ja     0x2c3
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
  85:	0f 85 38 02 00 00    	jne    0x2c3
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
  c0:	0f 85 fd 01 00 00    	jne    0x2c3
  c6:	48 bb 93 fd 59 66 b8 	movabs rbx,0xd6e8feb86659fd93
  cd:	fe e8 d6 
  d0:	31 f6                	xor    esi,esi
  d2:	ba 00 03 00 00       	mov    edx,0x300
  d7:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
  db:	48 83 c1 14          	add    rcx,0x14
  df:	e9 8b 00 00 00       	jmp    0x16f
  e4:	49 c1 e7 20          	shl    r15,0x20
  e8:	48 c1 e3 20          	shl    rbx,0x20
  ec:	48 c1 eb 20          	shr    rbx,0x20
  f0:	49 09 df             	or     r15,rbx
  f3:	4d 01 fd             	add    r13,r15
  f6:	49 c1 e6 20          	shl    r14,0x20
  fa:	49 c1 ee 20          	shr    r14,0x20
  fe:	4c 89 eb             	mov    rbx,r13
 101:	48 0f b6 79 13       	movzx  rdi,BYTE PTR [rcx+0x13]
 106:	48 c1 e7 08          	shl    rdi,0x8
 10a:	4c 0f b6 69 12       	movzx  r13,BYTE PTR [rcx+0x12]
 10f:	4c 09 ef             	or     rdi,r13
 112:	49 89 f5             	mov    r13,rsi
 115:	49 83 e5 18          	and    r13,0x18
 119:	c4 e2 91 f7 ff       	shlx   rdi,rdi,r13
 11e:	49 89 c5             	mov    r13,rax
 121:	49 c1 e5 02          	shl    r13,0x2
 125:	49 83 e5 1c          	and    r13,0x1c
 129:	c4 42 91 f7 f6       	shlx   r14,r14,r13
 12e:	4c 31 f3             	xor    rbx,r14
 131:	48 01 fb             	add    rbx,rdi
 134:	48 83 e0 07          	and    rax,0x7
 138:	4c 31 c0             	xor    rax,r8
 13b:	48 89 c7             	mov    rdi,rax
 13e:	48 83 f7 3f          	xor    rdi,0x3f
 142:	49 89 d8             	mov    r8,rbx
 145:	c4 42 c3 f7 c0       	shrx   r8,r8,rdi
 14a:	48 83 c0 01          	add    rax,0x1
 14e:	c4 e2 f9 f7 db       	shlx   rbx,rbx,rax
 153:	4c 09 c3             	or     rbx,r8
 156:	48 83 c1 18          	add    rcx,0x18
 15a:	48 83 c2 e8          	add    rdx,0xffffffffffffffe8
 15e:	48 83 c6 08          	add    rsi,0x8
 162:	48 81 fe 00 01 00 00 	cmp    rsi,0x100
 169:	0f 84 ff 00 00 00    	je     0x26e
 16f:	4c 0f b6 41 fc       	movzx  r8,BYTE PTR [rcx-0x4]
 174:	49 83 e0 03          	and    r8,0x3
 178:	4c 89 c7             	mov    rdi,r8
 17b:	48 83 cf 18          	or     rdi,0x18
 17f:	48 39 d7             	cmp    rdi,rdx
 182:	77 d2                	ja     0x156
 184:	48 0f b6 41 fd       	movzx  rax,BYTE PTR [rcx-0x3]
 189:	4c 0f b6 79 05       	movzx  r15,BYTE PTR [rcx+0x5]
 18e:	49 c1 e7 08          	shl    r15,0x8
 192:	48 0f b6 79 04       	movzx  rdi,BYTE PTR [rcx+0x4]
 197:	49 09 ff             	or     r15,rdi
 19a:	4c 0f b6 69 01       	movzx  r13,BYTE PTR [rcx+0x1]
 19f:	49 c1 e5 08          	shl    r13,0x8
 1a3:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 1a8:	49 09 fd             	or     r13,rdi
 1ab:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 1b0:	48 c1 e7 10          	shl    rdi,0x10
 1b4:	49 09 fd             	or     r13,rdi
 1b7:	48 0f b6 79 03       	movzx  rdi,BYTE PTR [rcx+0x3]
 1bc:	48 c1 e7 18          	shl    rdi,0x18
 1c0:	49 09 fd             	or     r13,rdi
 1c3:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 1c8:	48 c1 e7 10          	shl    rdi,0x10
 1cc:	49 09 ff             	or     r15,rdi
 1cf:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 1d4:	48 c1 e7 08          	shl    rdi,0x8
 1d8:	4c 0f b6 71 10       	movzx  r14,BYTE PTR [rcx+0x10]
 1dd:	4c 09 f7             	or     rdi,r14
 1e0:	4c 0f b6 71 07       	movzx  r14,BYTE PTR [rcx+0x7]
 1e5:	49 c1 e6 18          	shl    r14,0x18
 1e9:	4d 09 f7             	or     r15,r14
 1ec:	49 01 dd             	add    r13,rbx
 1ef:	4c 0f b6 71 0d       	movzx  r14,BYTE PTR [rcx+0xd]
 1f4:	49 c1 e6 08          	shl    r14,0x8
 1f8:	48 0f b6 59 0c       	movzx  rbx,BYTE PTR [rcx+0xc]
 1fd:	49 09 de             	or     r14,rbx
 200:	48 0f b6 59 0e       	movzx  rbx,BYTE PTR [rcx+0xe]
 205:	48 c1 e3 10          	shl    rbx,0x10
 209:	49 09 de             	or     r14,rbx
 20c:	4d 01 fd             	add    r13,r15
 20f:	49 01 fd             	add    r13,rdi
 212:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
 217:	48 c1 e7 18          	shl    rdi,0x18
 21b:	49 09 fe             	or     r14,rdi
 21e:	48 0f b6 59 09       	movzx  rbx,BYTE PTR [rcx+0x9]
 223:	48 c1 e3 08          	shl    rbx,0x8
 227:	48 0f b6 79 08       	movzx  rdi,BYTE PTR [rcx+0x8]
 22c:	48 09 fb             	or     rbx,rdi
 22f:	48 0f b6 79 0a       	movzx  rdi,BYTE PTR [rcx+0xa]
 234:	48 c1 e7 10          	shl    rdi,0x10
 238:	48 09 fb             	or     rbx,rdi
 23b:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 240:	48 c1 e7 18          	shl    rdi,0x18
 244:	48 09 fb             	or     rbx,rdi
 247:	48 89 c7             	mov    rdi,rax
 24a:	48 83 e7 01          	and    rdi,0x1
 24e:	48 85 ff             	test   rdi,rdi
 251:	0f 84 8d fe ff ff    	je     0xe4
 257:	48 c1 e3 20          	shl    rbx,0x20
 25b:	49 c1 e6 20          	shl    r14,0x20
 25f:	49 c1 ee 20          	shr    r14,0x20
 263:	4c 09 f3             	or     rbx,r14
 266:	49 31 dd             	xor    r13,rbx
 269:	e9 90 fe ff ff       	jmp    0xfe
 26e:	48 89 df             	mov    rdi,rbx
 271:	48 c1 ef 38          	shr    rdi,0x38
 275:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 279:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 27d:	48 89 df             	mov    rdi,rbx
 280:	48 c1 ef 30          	shr    rdi,0x30
 284:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 288:	48 89 df             	mov    rdi,rbx
 28b:	48 c1 ef 28          	shr    rdi,0x28
 28f:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 293:	48 89 df             	mov    rdi,rbx
 296:	48 c1 ef 20          	shr    rdi,0x20
 29a:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 29e:	48 89 df             	mov    rdi,rbx
 2a1:	48 c1 ef 18          	shr    rdi,0x18
 2a5:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 2a9:	48 89 df             	mov    rdi,rbx
 2ac:	48 c1 ef 10          	shr    rdi,0x10
 2b0:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 2b4:	88 5e 00             	mov    BYTE PTR [rsi+0x0],bl
 2b7:	48 c1 eb 08          	shr    rbx,0x8
 2bb:	88 5e 01             	mov    BYTE PTR [rsi+0x1],bl
 2be:	b8 02 00 00 00       	mov    eax,0x2
 2c3:	41 5f                	pop    r15
 2c5:	41 5e                	pop    r14
 2c7:	41 5d                	pop    r13
 2c9:	5b                   	pop    rbx
 2ca:	c9                   	leave
 2cb:	c3                   	ret
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
   d:	0f 87 04 01 00 00    	ja     0x117
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 f7 00 00 00    	ja     0x117
  20:	48 8d b1 10 03 00 00 	lea    rsi,[rcx+0x310]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 e7 00 00 00    	ja     0x117
  30:	83 79 08 20          	cmp    DWORD PTR [rcx+0x8],0x20
  34:	0f 85 d1 00 00 00    	jne    0x10b
  3a:	83 79 0c 18          	cmp    DWORD PTR [rcx+0xc],0x18
  3e:	0f 85 c7 00 00 00    	jne    0x10b
  44:	53                   	push   rbx
  45:	48 8d 41 14          	lea    rax,[rcx+0x14]
  49:	49 b9 93 fd 59 66 b8 	movabs r9,0xd6e8feb86659fd93
  50:	fe e8 d6 
  53:	ba 00 03 00 00       	mov    edx,0x300
  58:	31 f6                	xor    esi,esi
  5a:	eb 65                	jmp    0xc1
  5c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  60:	48 c1 e3 20          	shl    rbx,0x20
  64:	49 09 da             	or     r10,rbx
  67:	4d 01 da             	add    r10,r11
  6a:	44 0f b7 58 12       	movzx  r11d,WORD PTR [rax+0x12]
  6f:	89 f3                	mov    ebx,esi
  71:	80 e3 18             	and    bl,0x18
  74:	c4 42 e1 f7 db       	shlx   r11,r11,rbx
  79:	42 8d 1c 85 00 00 00 	lea    ebx,[r8*4+0x0]
  80:	00 
  81:	80 e3 1c             	and    bl,0x1c
  84:	c4 42 e1 f7 c9       	shlx   r9,r9,rbx
  89:	4d 31 d1             	xor    r9,r10
  8c:	4d 01 d9             	add    r9,r11
  8f:	41 83 e0 07          	and    r8d,0x7
  93:	44 31 c7             	xor    edi,r8d
  96:	41 89 f8             	mov    r8d,edi
  99:	41 f6 d0             	not    r8b
  9c:	c4 42 bb f7 c1       	shrx   r8,r9,r8
  a1:	40 fe c7             	inc    dil
  a4:	c4 42 c1 f7 c9       	shlx   r9,r9,rdi
  a9:	4d 09 c1             	or     r9,r8
  ac:	48 83 c0 18          	add    rax,0x18
  b0:	48 83 c2 e8          	add    rdx,0xffffffffffffffe8
  b4:	48 83 c6 08          	add    rsi,0x8
  b8:	48 81 fe 00 01 00 00 	cmp    rsi,0x100
  bf:	74 4d                	je     0x10e
  c1:	0f b6 78 fc          	movzx  edi,BYTE PTR [rax-0x4]
  c5:	83 e7 03             	and    edi,0x3
  c8:	4c 8d 47 18          	lea    r8,[rdi+0x18]
  cc:	49 39 d0             	cmp    r8,rdx
  cf:	77 db                	ja     0xac
  d1:	44 0f b6 40 fd       	movzx  r8d,BYTE PTR [rax-0x3]
  d6:	44 8b 10             	mov    r10d,DWORD PTR [rax]
  d9:	8b 58 04             	mov    ebx,DWORD PTR [rax+0x4]
  dc:	44 0f b7 58 10       	movzx  r11d,WORD PTR [rax+0x10]
  e1:	4d 01 ca             	add    r10,r9
  e4:	49 01 db             	add    r11,rbx
  e7:	4d 01 d3             	add    r11,r10
  ea:	44 8b 48 0c          	mov    r9d,DWORD PTR [rax+0xc]
  ee:	44 8b 50 08          	mov    r10d,DWORD PTR [rax+0x8]
  f2:	41 f6 c0 01          	test   r8b,0x1
  f6:	0f 84 64 ff ff ff    	je     0x60
  fc:	49 c1 e2 20          	shl    r10,0x20
 100:	4d 09 ca             	or     r10,r9
 103:	4d 31 da             	xor    r10,r11
 106:	e9 5f ff ff ff       	jmp    0x6a
 10b:	31 c0                	xor    eax,eax
 10d:	c3                   	ret
 10e:	4c 89 09             	mov    QWORD PTR [rcx],r9
 111:	b8 02 00 00 00       	mov    eax,0x2
 116:	5b                   	pop    rbx
 117:	c3                   	ret
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
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <packet_record_bounds_window_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (4) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <packet_record_bounds_window_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-9) - 1, 0),
    /* 0x1118: lea    rsi,[rdx+0x310] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 784), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <packet_record_bounds_window_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-16) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: jne    110e <packet_record_bounds_window_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-20) - 1, 32),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112e: jne    110e <packet_record_bounds_window_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-24) - 1, 24),
    /* 0x1130: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: lea    rsi,[rdx+0x27] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1137: movabs r9,0xd6e8feb86659fd93 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xd6e8feb86659fd93ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_R9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1141: mov    edi,0x300 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 768), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1146: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1149: jmp    11a4 <packet_record_bounds_window_xdp+0xa4> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (54) - 1, 0),
    /* 0x114b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: shl    r14,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R14, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1154: mov    ecx,ecx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1156: or     rcx,r14 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1159: add    r11,rcx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x115c: movzx  r9d,WORD PTR [rsi-0x1] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RSI, -1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1161: lea    ecx,[rax*4+0x0] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, 0, HC_X86_RAX, 2, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1168: and    cl,0x1c [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(HC_X86_RCX, 28), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x116b: shl    rbx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x116e: xor    rbx,r11 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1171: mov    ecx,r8d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1174: and    cl,0x18 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(HC_X86_RCX, 24), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1177: shl    r9,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x117a: add    r9,rbx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117d: and    eax,0x7 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1180: xor    eax,r10d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1183: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1186: mov    r10,r9 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1189: shl    r10,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x118c: not    al [exact-kop: not8 reg kop] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x118e: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1190: shr    r9,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1193: or     r9,r10 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1196: add    r8,0x8 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 8), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119a: add    rsi,0x18 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RSI, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119e: add    rdi,0xffffffffffffffe8 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, -24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a2: je     11ec <packet_record_bounds_window_xdp+0xec> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (41) - 1, 0),
    /* 0x11a4: movzx  r10d,BYTE PTR [rsi-0x17] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R10, HC_X86_RSI, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a9: and    r10d,0x3 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 3), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11ad: lea    rax,[r10+0x18] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_R10, 0, 0, 1, 0, 24), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11b1: cmp    rdi,rax [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b4: jb     1196 <packet_record_bounds_window_xdp+0x96> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_X, BPF_REG_6, BPF_REG_7, (-19) - 1, 0),
    /* 0x11b6: movzx  eax,BYTE PTR [rsi-0x16] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RSI, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11ba: mov    ebx,DWORD PTR [rsi-0x13] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBX, HC_X86_RSI, -19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11bd: mov    r14d,DWORD PTR [rsi-0xf] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RSI, -15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c1: mov    ecx,DWORD PTR [rsi-0xb] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RSI, -11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c4: movzx  r11d,WORD PTR [rsi-0x3] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RSI, -3), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11c9: add    rbx,r9 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11cc: add    r11,r14 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11cf: add    r11,rbx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d2: mov    ebx,DWORD PTR [rsi-0x7] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBX, HC_X86_RSI, -7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d5: test   al,0x1 [control-flow-operand: test folded into BPF branch] */
    /* 0x11d7: je     1150 <packet_record_bounds_window_xdp+0x50> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 1, 1),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-85) - 1, 0),
    /* 0x11dd: shl    rcx,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11e1: or     rcx,rbx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e4: xor    r11,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11e7: jmp    115c <packet_record_bounds_window_xdp+0x5c> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-84) - 1, 0),
    /* 0x11ec: mov    QWORD PTR [rdx],r9 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_R9, HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11ef: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f4: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11f5: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11f7: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
