# bcc_runqlat_log2_histogram_bucket

## Original C
```c
#include "common.h"

#define BCC_RUNQLAT_COUNT 128U
#define BCC_RUNQLAT_MAX_SLOTS 26U
#define BCC_RUNQLAT_INPUT_SIZE (8U + BCC_RUNQLAT_COUNT * 8U)

static __always_inline u32 bcc_runqlat_bucket(u64 raw_delta)
{
    u64 delta_us = ((raw_delta >> 3U) & 0xFFFFFULL) + 1U;
    u32 slot = 0;

    for (u32 bit = 0; bit < 63U; bit++) {
        if (delta_us <= 1U) {
            break;
        }
        delta_us >>= 1U;
        slot++;
    }

    if (slot >= BCC_RUNQLAT_MAX_SLOTS) {
        slot = BCC_RUNQLAT_MAX_SLOTS - 1U;
    }
    return slot;
}

static __always_inline int
bench_bcc_runqlat_log2_histogram_bucket(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BCC_RUNQLAT_INPUT_SIZE)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    u32 seed = micro_read_u32_le(data, 4U);
    if (count != BCC_RUNQLAT_COUNT) {
        return -1;
    }

    u64 acc = seed;
    for (u32 index = 0; index < BCC_RUNQLAT_COUNT; index++) {
        u64 raw_delta = micro_read_u64_le(data, 8U + index * 8U);
        u32 slot = bcc_runqlat_bucket(raw_delta);

        acc += (u64)(slot + 1U) * (u64)(index + 1U);
        acc ^= micro_rotl64(raw_delta, (slot & 7U) + 1U);
        if (slot == BCC_RUNQLAT_MAX_SLOTS - 1U) {
            acc += raw_delta >> 32U;
        } else {
            acc ^= (u64)slot << ((index & 7U) * 8U);
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bcc_runqlat_log2_histogram_bucket_xdp,
    bench_bcc_runqlat_log2_histogram_bucket,
    bcc_runqlat_log2_histogram_bucket_input_value,
    BCC_RUNQLAT_INPUT_SIZE)
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

0000000000001100 <bcc_runqlat_log2_histogram_bucket_xdp>:
    1100:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ce             	cmp    rsi,rcx
    110c:	76 01                	jbe    110f <bcc_runqlat_log2_histogram_bucket_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 56 08          	lea    rdx,[rsi+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe>
    1118:	48 8d be 10 04 00 00 	lea    rdi,[rsi+0x410]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe>
    1124:	81 3a 80 00 00 00    	cmp    DWORD PTR [rdx],0x80
    112a:	75 e2                	jne    110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe>
    112c:	41 57                	push   r15
    112e:	41 56                	push   r14
    1130:	53                   	push   rbx
    1131:	8b 7e 0c             	mov    edi,DWORD PTR [rsi+0xc]
    1134:	31 c0                	xor    eax,eax
    1136:	eb 2c                	jmp    1164 <bcc_runqlat_log2_histogram_bucket_xdp+0x64>
    1138:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    113f:	00 
    1140:	48 c1 e0 03          	shl    rax,0x3
    1144:	44 89 da             	mov    edx,r11d
    1147:	24 38                	and    al,0x38
    1149:	89 c1                	mov    ecx,eax
    114b:	48 d3 e2             	shl    rdx,cl
    114e:	48 31 d3             	xor    rbx,rdx
    1151:	48 89 df             	mov    rdi,rbx
    1154:	4c 89 d0             	mov    rax,r10
    1157:	49 81 fa 80 00 00 00 	cmp    r10,0x80
    115e:	0f 84 d7 00 00 00    	je     123b <bcc_runqlat_log2_histogram_bucket_xdp+0x13b>
    1164:	0f b7 54 c6 10       	movzx  edx,WORD PTR [rsi+rax*8+0x10]
    1169:	0f b6 4c c6 12       	movzx  ecx,BYTE PTR [rsi+rax*8+0x12]
    116e:	c1 e1 10             	shl    ecx,0x10
    1171:	48 09 d1             	or     rcx,rdx
    1174:	89 ca                	mov    edx,ecx
    1176:	c1 ea 03             	shr    edx,0x3
    1179:	41 b8 00 00 00 00    	mov    r8d,0x0
    117f:	81 e2 ff ff 0f 00    	and    edx,0xfffff
    1185:	74 25                	je     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac>
    1187:	48 ff c2             	inc    rdx
    118a:	45 31 c0             	xor    r8d,r8d
    118d:	0f 1f 00             	nop    DWORD PTR [rax]
    1190:	45 89 c1             	mov    r9d,r8d
    1193:	45 8d 41 01          	lea    r8d,[r9+0x1]
    1197:	41 83 f9 3d          	cmp    r9d,0x3d
    119b:	77 0f                	ja     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac>
    119d:	49 89 d1             	mov    r9,rdx
    11a0:	49 d1 e9             	shr    r9,1
    11a3:	48 83 fa 03          	cmp    rdx,0x3
    11a7:	4c 89 ca             	mov    rdx,r9
    11aa:	77 e4                	ja     1190 <bcc_runqlat_log2_histogram_bucket_xdp+0x90>
    11ac:	0f b6 54 c6 13       	movzx  edx,BYTE PTR [rsi+rax*8+0x13]
    11b1:	c1 e2 18             	shl    edx,0x18
    11b4:	48 09 ca             	or     rdx,rcx
    11b7:	0f b6 4c c6 14       	movzx  ecx,BYTE PTR [rsi+rax*8+0x14]
    11bc:	48 c1 e1 20          	shl    rcx,0x20
    11c0:	44 0f b6 54 c6 15    	movzx  r10d,BYTE PTR [rsi+rax*8+0x15]
    11c6:	49 c1 e2 28          	shl    r10,0x28
    11ca:	49 09 ca             	or     r10,rcx
    11cd:	49 09 d2             	or     r10,rdx
    11d0:	0f b6 4c c6 16       	movzx  ecx,BYTE PTR [rsi+rax*8+0x16]
    11d5:	48 c1 e1 30          	shl    rcx,0x30
    11d9:	44 0f b6 4c c6 17    	movzx  r9d,BYTE PTR [rsi+rax*8+0x17]
    11df:	49 c1 e1 38          	shl    r9,0x38
    11e3:	49 09 c9             	or     r9,rcx
    11e6:	4d 09 d1             	or     r9,r10
    11e9:	41 83 f8 19          	cmp    r8d,0x19
    11ed:	41 bb 19 00 00 00    	mov    r11d,0x19
    11f3:	45 0f 42 d8          	cmovb  r11d,r8d
    11f7:	45 8d 73 01          	lea    r14d,[r11+0x1]
    11fb:	44 89 da             	mov    edx,r11d
    11fe:	80 e2 07             	and    dl,0x7
    1201:	8d 4a 01             	lea    ecx,[rdx+0x1]
    1204:	4d 89 cf             	mov    r15,r9
    1207:	49 d3 e7             	shl    r15,cl
    120a:	4c 8d 50 01          	lea    r10,[rax+0x1]
    120e:	4d 0f af f2          	imul   r14,r10
    1212:	f6 d2                	not    dl
    1214:	4c 89 cb             	mov    rbx,r9
    1217:	89 d1                	mov    ecx,edx
    1219:	48 d3 eb             	shr    rbx,cl
    121c:	4c 01 f7             	add    rdi,r14
    121f:	4c 09 fb             	or     rbx,r15
    1222:	48 31 fb             	xor    rbx,rdi
    1225:	41 83 f8 19          	cmp    r8d,0x19
    1229:	0f 82 11 ff ff ff    	jb     1140 <bcc_runqlat_log2_histogram_bucket_xdp+0x40>
    122f:	49 c1 e9 20          	shr    r9,0x20
    1233:	4c 01 cb             	add    rbx,r9
    1236:	e9 16 ff ff ff       	jmp    1151 <bcc_runqlat_log2_histogram_bucket_xdp+0x51>
    123b:	48 89 3e             	mov    QWORD PTR [rsi],rdi
    123e:	b8 02 00 00 00       	mov    eax,0x2
    1243:	5b                   	pop    rbx
    1244:	41 5e                	pop    r14
    1246:	41 5f                	pop    r15
    1248:	c3                   	ret

Disassembly of section .fini:

000000000000124c <_fini>:
    124c:	f3 0f 1e fa          	endbr64
    1250:	48 83 ec 08          	sub    rsp,0x8
    1254:	48 83 c4 08          	add    rsp,0x8
    1258:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 40 00 00 00 	sub    rsp,0x40
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 62 02 00 00    	ja     0x28f
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 52 02 00 00    	ja     0x28f
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 3f 02 00 00    	ja     0x28f
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
  73:	81 ff 80 00 00 00    	cmp    edi,0x80
  79:	0f 85 10 02 00 00    	jne    0x28f
  7f:	48 0f b6 79 0c       	movzx  rdi,BYTE PTR [rcx+0xc]
  84:	4c 0f b6 69 0d       	movzx  r13,BYTE PTR [rcx+0xd]
  89:	49 c1 e5 08          	shl    r13,0x8
  8d:	49 09 fd             	or     r13,rdi
  90:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
  95:	48 c1 e7 10          	shl    rdi,0x10
  99:	49 09 fd             	or     r13,rdi
  9c:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
  a1:	48 c1 e7 18          	shl    rdi,0x18
  a5:	49 09 fd             	or     r13,rdi
  a8:	31 d2                	xor    edx,edx
  aa:	48 89 cf             	mov    rdi,rcx
  ad:	48 83 c7 17          	add    rdi,0x17
  b1:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  b5:	48 89 cf             	mov    rdi,rcx
  b8:	48 83 c7 16          	add    rdi,0x16
  bc:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  c0:	48 89 cf             	mov    rdi,rcx
  c3:	48 83 c7 15          	add    rdi,0x15
  c7:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  cb:	48 89 cf             	mov    rdi,rcx
  ce:	48 83 c7 14          	add    rdi,0x14
  d2:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
  d6:	48 89 cf             	mov    rdi,rcx
  d9:	48 83 c7 13          	add    rdi,0x13
  dd:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
  e1:	48 89 cf             	mov    rdi,rcx
  e4:	48 83 c7 12          	add    rdi,0x12
  e8:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
  ec:	48 89 cf             	mov    rdi,rcx
  ef:	48 83 c7 11          	add    rdi,0x11
  f3:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
  f7:	48 89 4d c0          	mov    QWORD PTR [rbp-0x40],rcx
  fb:	48 89 cf             	mov    rdi,rcx
  fe:	48 83 c7 10          	add    rdi,0x10
 102:	e9 9d 00 00 00       	jmp    0x1a4
 107:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 10b:	48 01 f0             	add    rax,rsi
 10e:	4c 0f b6 70 00       	movzx  r14,BYTE PTR [rax+0x0]
 113:	49 c1 e6 28          	shl    r14,0x28
 117:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 11b:	48 01 f0             	add    rax,rsi
 11e:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 123:	48 c1 e0 20          	shl    rax,0x20
 127:	4c 09 f0             	or     rax,r14
 12a:	4c 8b 75 d8          	mov    r14,QWORD PTR [rbp-0x28]
 12e:	49 01 f6             	add    r14,rsi
 131:	4d 0f b6 76 00       	movzx  r14,BYTE PTR [r14+0x0]
 136:	49 c1 e6 18          	shl    r14,0x18
 13a:	49 09 ce             	or     r14,rcx
 13d:	4c 09 f0             	or     rax,r14
 140:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 144:	48 01 f1             	add    rcx,rsi
 147:	4c 0f b6 71 00       	movzx  r14,BYTE PTR [rcx+0x0]
 14c:	49 c1 e6 38          	shl    r14,0x38
 150:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
 154:	48 01 f1             	add    rcx,rsi
 157:	48 0f b6 49 00       	movzx  rcx,BYTE PTR [rcx+0x0]
 15c:	48 c1 e1 30          	shl    rcx,0x30
 160:	4c 09 f1             	or     rcx,r14
 163:	48 09 c1             	or     rcx,rax
 166:	41 89 de             	mov    r14d,ebx
 169:	41 83 e6 07          	and    r14d,0x7
 16d:	44 89 f0             	mov    eax,r14d
 170:	83 f0 3f             	xor    eax,0x3f
 173:	49 89 cf             	mov    r15,rcx
 176:	c4 42 fb f7 ff       	shrx   r15,r15,rax
 17b:	41 83 c6 01          	add    r14d,0x1
 17f:	48 89 c8             	mov    rax,rcx
 182:	c4 e2 89 f7 c0       	shlx   rax,rax,r14
 187:	4c 09 f8             	or     rax,r15
 18a:	41 89 de             	mov    r14d,ebx
 18d:	41 83 c6 01          	add    r14d,0x1
 191:	48 83 c2 01          	add    rdx,0x1
 195:	49 89 d7             	mov    r15,rdx
 198:	4d 0f af fe          	imul   r15,r14
 19c:	4d 01 fd             	add    r13,r15
 19f:	4c 31 e8             	xor    rax,r13
 1a2:	eb 76                	jmp    0x21a
 1a4:	48 89 d6             	mov    rsi,rdx
 1a7:	48 c1 e6 03          	shl    rsi,0x3
 1ab:	48 89 f9             	mov    rcx,rdi
 1ae:	48 01 f1             	add    rcx,rsi
 1b1:	48 0f b6 49 00       	movzx  rcx,BYTE PTR [rcx+0x0]
 1b6:	4c 8b 45 c8          	mov    r8,QWORD PTR [rbp-0x38]
 1ba:	49 01 f0             	add    r8,rsi
 1bd:	4d 0f b6 40 00       	movzx  r8,BYTE PTR [r8+0x0]
 1c2:	49 c1 e0 08          	shl    r8,0x8
 1c6:	49 09 c8             	or     r8,rcx
 1c9:	48 8b 4d d0          	mov    rcx,QWORD PTR [rbp-0x30]
 1cd:	48 01 f1             	add    rcx,rsi
 1d0:	48 0f b6 49 00       	movzx  rcx,BYTE PTR [rcx+0x0]
 1d5:	48 c1 e1 10          	shl    rcx,0x10
 1d9:	4c 09 c1             	or     rcx,r8
 1dc:	45 31 c0             	xor    r8d,r8d
 1df:	48 89 c8             	mov    rax,rcx
 1e2:	48 c1 e8 03          	shr    rax,0x3
 1e6:	48 25 ff ff 0f 00    	and    rax,0xfffff
 1ec:	48 85 c0             	test   rax,rax
 1ef:	74 21                	je     0x212
 1f1:	31 db                	xor    ebx,ebx
 1f3:	48 83 c0 01          	add    rax,0x1
 1f7:	49 89 c6             	mov    r14,rax
 1fa:	41 83 c0 01          	add    r8d,0x1
 1fe:	83 fb 3d             	cmp    ebx,0x3d
 201:	77 0f                	ja     0x212
 203:	4c 89 f0             	mov    rax,r14
 206:	48 d1 e8             	shr    rax,1
 209:	44 89 c3             	mov    ebx,r8d
 20c:	49 83 fe 03          	cmp    r14,0x3
 210:	77 e5                	ja     0x1f7
 212:	44 89 c3             	mov    ebx,r8d
 215:	e9 ed fe ff ff       	jmp    0x107
 21a:	48 83 e6 38          	and    rsi,0x38
 21e:	c4 e2 c9 f7 db       	shlx   rbx,rbx,rsi
 223:	48 31 c3             	xor    rbx,rax
 226:	48 89 d8             	mov    rax,rbx
 229:	49 89 dd             	mov    r13,rbx
 22c:	48 81 fa 80 00 00 00 	cmp    rdx,0x80
 233:	74 05                	je     0x23a
 235:	e9 6a ff ff ff       	jmp    0x1a4
 23a:	48 8b 75 c0          	mov    rsi,QWORD PTR [rbp-0x40]
 23e:	88 46 00             	mov    BYTE PTR [rsi+0x0],al
 241:	48 89 c7             	mov    rdi,rax
 244:	48 c1 ef 38          	shr    rdi,0x38
 248:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 24c:	48 89 c7             	mov    rdi,rax
 24f:	48 c1 ef 30          	shr    rdi,0x30
 253:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 257:	48 89 c7             	mov    rdi,rax
 25a:	48 c1 ef 28          	shr    rdi,0x28
 25e:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 262:	48 89 c7             	mov    rdi,rax
 265:	48 c1 ef 20          	shr    rdi,0x20
 269:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 26d:	48 89 c7             	mov    rdi,rax
 270:	48 c1 ef 18          	shr    rdi,0x18
 274:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 278:	48 89 c7             	mov    rdi,rax
 27b:	48 c1 ef 10          	shr    rdi,0x10
 27f:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 283:	48 c1 e8 08          	shr    rax,0x8
 287:	88 46 01             	mov    BYTE PTR [rsi+0x1],al
 28a:	b8 02 00 00 00       	mov    eax,0x2
 28f:	41 5f                	pop    r15
 291:	41 5e                	pop    r14
 293:	41 5d                	pop    r13
 295:	5b                   	pop    rbx
 296:	c9                   	leave
 297:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
