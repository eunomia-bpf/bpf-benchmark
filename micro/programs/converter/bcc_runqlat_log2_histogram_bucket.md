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
   c:	48 81 ec 48 00 00 00 	sub    rsp,0x48
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 96 02 00 00    	ja     0x2c3
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 86 02 00 00    	ja     0x2c3
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 73 02 00 00    	ja     0x2c3
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
  81:	48 81 ff 80 00 00 00 	cmp    rdi,0x80
  88:	0f 85 35 02 00 00    	jne    0x2c3
  8e:	4c 0f b6 72 0d       	movzx  r14,BYTE PTR [rdx+0xd]
  93:	49 c1 e6 08          	shl    r14,0x8
  97:	48 0f b6 7a 0c       	movzx  rdi,BYTE PTR [rdx+0xc]
  9c:	49 09 fe             	or     r14,rdi
  9f:	48 0f b6 7a 0e       	movzx  rdi,BYTE PTR [rdx+0xe]
  a4:	48 c1 e7 10          	shl    rdi,0x10
  a8:	49 09 fe             	or     r14,rdi
  ab:	48 0f b6 7a 0f       	movzx  rdi,BYTE PTR [rdx+0xf]
  b0:	48 c1 e7 18          	shl    rdi,0x18
  b4:	49 09 fe             	or     r14,rdi
  b7:	31 c9                	xor    ecx,ecx
  b9:	48 89 d7             	mov    rdi,rdx
  bc:	48 83 c7 17          	add    rdi,0x17
  c0:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  c4:	48 89 d7             	mov    rdi,rdx
  c7:	48 83 c7 16          	add    rdi,0x16
  cb:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  cf:	48 89 d7             	mov    rdi,rdx
  d2:	48 83 c7 15          	add    rdi,0x15
  d6:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  da:	48 89 d7             	mov    rdi,rdx
  dd:	48 83 c7 14          	add    rdi,0x14
  e1:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
  e5:	48 89 d7             	mov    rdi,rdx
  e8:	48 83 c7 13          	add    rdi,0x13
  ec:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
  f0:	48 89 d7             	mov    rdi,rdx
  f3:	48 83 c7 12          	add    rdi,0x12
  f7:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
  fb:	48 89 d7             	mov    rdi,rdx
  fe:	48 83 c7 11          	add    rdi,0x11
 102:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 106:	48 89 55 b8          	mov    QWORD PTR [rbp-0x48],rdx
 10a:	48 83 c2 10          	add    rdx,0x10
 10e:	48 89 55 c0          	mov    QWORD PTR [rbp-0x40],rdx
 112:	e9 a1 00 00 00       	jmp    0x1b8
 117:	48 8b 5d e8          	mov    rbx,QWORD PTR [rbp-0x18]
 11b:	48 01 f3             	add    rbx,rsi
 11e:	4c 0f b6 7b 00       	movzx  r15,BYTE PTR [rbx+0x0]
 123:	49 c1 e7 28          	shl    r15,0x28
 127:	48 8b 5d e0          	mov    rbx,QWORD PTR [rbp-0x20]
 12b:	48 01 f3             	add    rbx,rsi
 12e:	48 0f b6 5b 00       	movzx  rbx,BYTE PTR [rbx+0x0]
 133:	48 c1 e3 20          	shl    rbx,0x20
 137:	4c 09 fb             	or     rbx,r15
 13a:	4c 8b 7d d8          	mov    r15,QWORD PTR [rbp-0x28]
 13e:	49 01 f7             	add    r15,rsi
 141:	4d 0f b6 7f 00       	movzx  r15,BYTE PTR [r15+0x0]
 146:	49 c1 e7 18          	shl    r15,0x18
 14a:	49 09 c7             	or     r15,rax
 14d:	4c 09 fb             	or     rbx,r15
 150:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 154:	48 01 f0             	add    rax,rsi
 157:	4c 0f b6 78 00       	movzx  r15,BYTE PTR [rax+0x0]
 15c:	49 c1 e7 38          	shl    r15,0x38
 160:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 164:	48 01 f0             	add    rax,rsi
 167:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 16c:	48 c1 e0 30          	shl    rax,0x30
 170:	4c 09 f8             	or     rax,r15
 173:	48 09 d8             	or     rax,rbx
 176:	4d 89 c7             	mov    r15,r8
 179:	49 83 e7 07          	and    r15,0x7
 17d:	4c 89 fb             	mov    rbx,r15
 180:	48 83 f3 3f          	xor    rbx,0x3f
 184:	48 89 c7             	mov    rdi,rax
 187:	c4 e2 e3 f7 ff       	shrx   rdi,rdi,rbx
 18c:	49 83 c7 01          	add    r15,0x1
 190:	48 89 c3             	mov    rbx,rax
 193:	c4 e2 81 f7 db       	shlx   rbx,rbx,r15
 198:	48 09 fb             	or     rbx,rdi
 19b:	48 83 c1 01          	add    rcx,0x1
 19f:	4c 89 c7             	mov    rdi,r8
 1a2:	48 83 c7 01          	add    rdi,0x1
 1a6:	49 89 cf             	mov    r15,rcx
 1a9:	4c 0f af ff          	imul   r15,rdi
 1ad:	4d 01 fe             	add    r14,r15
 1b0:	4c 31 f3             	xor    rbx,r14
 1b3:	e9 8e 00 00 00       	jmp    0x246
 1b8:	48 89 ce             	mov    rsi,rcx
 1bb:	48 c1 e6 03          	shl    rsi,0x3
 1bf:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 1c3:	48 01 f2             	add    rdx,rsi
 1c6:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 1cb:	4c 8b 45 c8          	mov    r8,QWORD PTR [rbp-0x38]
 1cf:	49 01 f0             	add    r8,rsi
 1d2:	4d 0f b6 40 00       	movzx  r8,BYTE PTR [r8+0x0]
 1d7:	49 c1 e0 08          	shl    r8,0x8
 1db:	49 09 d0             	or     r8,rdx
 1de:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 1e2:	48 01 f2             	add    rdx,rsi
 1e5:	48 0f b6 42 00       	movzx  rax,BYTE PTR [rdx+0x0]
 1ea:	48 c1 e0 10          	shl    rax,0x10
 1ee:	4c 09 c0             	or     rax,r8
 1f1:	49 89 c0             	mov    r8,rax
 1f4:	49 c1 e8 03          	shr    r8,0x3
 1f8:	49 81 e0 ff ff 0f 00 	and    r8,0xfffff
 1ff:	31 d2                	xor    edx,edx
 201:	4d 85 c0             	test   r8,r8
 204:	74 2a                	je     0x230
 206:	31 db                	xor    ebx,ebx
 208:	49 83 c0 01          	add    r8,0x1
 20c:	4d 89 c5             	mov    r13,r8
 20f:	48 83 c2 01          	add    rdx,0x1
 213:	48 c1 e3 20          	shl    rbx,0x20
 217:	48 c1 eb 20          	shr    rbx,0x20
 21b:	48 83 fb 3d          	cmp    rbx,0x3d
 21f:	77 0f                	ja     0x230
 221:	4d 89 e8             	mov    r8,r13
 224:	49 d1 e8             	shr    r8,1
 227:	48 89 d3             	mov    rbx,rdx
 22a:	49 83 fd 03          	cmp    r13,0x3
 22e:	77 dc                	ja     0x20c
 230:	48 c1 e2 20          	shl    rdx,0x20
 234:	48 c1 ea 20          	shr    rdx,0x20
 238:	41 bd 19 00 00 00    	mov    r13d,0x19
 23e:	49 89 d0             	mov    r8,rdx
 241:	e9 d1 fe ff ff       	jmp    0x117
 246:	48 83 e6 38          	and    rsi,0x38
 24a:	49 c1 e0 20          	shl    r8,0x20
 24e:	49 c1 e8 20          	shr    r8,0x20
 252:	c4 42 c9 f7 c0       	shlx   r8,r8,rsi
 257:	49 31 d8             	xor    r8,rbx
 25a:	4c 89 c3             	mov    rbx,r8
 25d:	4d 89 c6             	mov    r14,r8
 260:	48 81 f9 80 00 00 00 	cmp    rcx,0x80
 267:	74 05                	je     0x26e
 269:	e9 4a ff ff ff       	jmp    0x1b8
 26e:	48 89 df             	mov    rdi,rbx
 271:	48 c1 ef 38          	shr    rdi,0x38
 275:	48 8b 75 b8          	mov    rsi,QWORD PTR [rbp-0x48]
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
   d:	0f 87 9e 01 00 00    	ja     0x1b1
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 91 01 00 00    	ja     0x1b1
  20:	48 8d b1 10 04 00 00 	lea    rsi,[rcx+0x410]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 81 01 00 00    	ja     0x1b1
  30:	81 79 08 80 00 00 00 	cmp    DWORD PTR [rcx+0x8],0x80
  37:	0f 85 24 01 00 00    	jne    0x161
  3d:	8b 41 0c             	mov    eax,DWORD PTR [rcx+0xc]
  40:	31 d2                	xor    edx,edx
  42:	eb 23                	jmp    0x67
  44:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  4b:	00 00 00 00 00 
  50:	49 c1 e9 20          	shr    r9,0x20
  54:	4c 01 c8             	add    rax,r9
  57:	48 89 f2             	mov    rdx,rsi
  5a:	48 81 fe 80 00 00 00 	cmp    rsi,0x80
  61:	0f 84 fd 00 00 00    	je     0x164
  67:	0f b7 7c d1 10       	movzx  edi,WORD PTR [rcx+rdx*8+0x10]
  6c:	0f b6 74 d1 12       	movzx  esi,BYTE PTR [rcx+rdx*8+0x12]
  71:	c1 e6 10             	shl    esi,0x10
  74:	48 09 fe             	or     rsi,rdi
  77:	89 f7                	mov    edi,esi
  79:	c1 ef 03             	shr    edi,0x3
  7c:	81 e7 ff ff 0f 00    	and    edi,0xfffff
  82:	74 3c                	je     0xc0
  84:	48 ff c7             	inc    rdi
  87:	45 31 c0             	xor    r8d,r8d
  8a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
  90:	4d 89 c1             	mov    r9,r8
  93:	49 ff c0             	inc    r8
  96:	41 83 e1 fe          	and    r9d,0xfffffffe
  9a:	41 83 f9 3d          	cmp    r9d,0x3d
  9e:	77 23                	ja     0xc3
  a0:	49 89 f9             	mov    r9,rdi
  a3:	49 d1 e9             	shr    r9,1
  a6:	48 83 ff 03          	cmp    rdi,0x3
  aa:	4c 89 cf             	mov    rdi,r9
  ad:	77 e1                	ja     0x90
  af:	eb 12                	jmp    0xc3
  b1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  b8:	0f 1f 84 00 00 00 00 
  bf:	00 
  c0:	45 31 c0             	xor    r8d,r8d
  c3:	45 89 c0             	mov    r8d,r8d
  c6:	49 83 f8 19          	cmp    r8,0x19
  ca:	bf 19 00 00 00       	mov    edi,0x19
  cf:	49 0f 42 f8          	cmovb  rdi,r8
  d3:	44 0f b6 4c d1 15    	movzx  r9d,BYTE PTR [rcx+rdx*8+0x15]
  d9:	49 c1 e1 28          	shl    r9,0x28
  dd:	44 0f b6 54 d1 14    	movzx  r10d,BYTE PTR [rcx+rdx*8+0x14]
  e3:	49 c1 e2 20          	shl    r10,0x20
  e7:	4d 09 ca             	or     r10,r9
  ea:	44 0f b6 4c d1 13    	movzx  r9d,BYTE PTR [rcx+rdx*8+0x13]
  f0:	41 c1 e1 18          	shl    r9d,0x18
  f4:	4d 09 d1             	or     r9,r10
  f7:	44 0f b6 54 d1 17    	movzx  r10d,BYTE PTR [rcx+rdx*8+0x17]
  fd:	49 c1 e2 38          	shl    r10,0x38
 101:	4d 09 ca             	or     r10,r9
 104:	44 0f b6 4c d1 16    	movzx  r9d,BYTE PTR [rcx+rdx*8+0x16]
 10a:	49 c1 e1 30          	shl    r9,0x30
 10e:	4d 09 d1             	or     r9,r10
 111:	4c 09 ce             	or     rsi,r9
 114:	41 89 fa             	mov    r10d,edi
 117:	41 80 e2 07          	and    r10b,0x7
 11b:	45 89 d3             	mov    r11d,r10d
 11e:	41 f6 d3             	not    r11b
 121:	c4 62 a3 f7 de       	shrx   r11,rsi,r11
 126:	41 fe c2             	inc    r10b
 129:	c4 62 a9 f7 d6       	shlx   r10,rsi,r10
 12e:	4d 09 da             	or     r10,r11
 131:	48 8d 72 01          	lea    rsi,[rdx+0x1]
 135:	4c 8d 5f 01          	lea    r11,[rdi+0x1]
 139:	4c 0f af de          	imul   r11,rsi
 13d:	4c 01 d8             	add    rax,r11
 140:	4c 31 d0             	xor    rax,r10
 143:	49 83 f8 18          	cmp    r8,0x18
 147:	0f 87 03 ff ff ff    	ja     0x50
 14d:	48 c1 e2 03          	shl    rdx,0x3
 151:	80 e2 38             	and    dl,0x38
 154:	c4 e2 e9 f7 d7       	shlx   rdx,rdi,rdx
 159:	48 31 d0             	xor    rax,rdx
 15c:	e9 f6 fe ff ff       	jmp    0x57
 161:	31 c0                	xor    eax,eax
 163:	c3                   	ret
 164:	89 c2                	mov    edx,eax
 166:	c1 ea 08             	shr    edx,0x8
 169:	89 c6                	mov    esi,eax
 16b:	c1 ee 10             	shr    esi,0x10
 16e:	89 c7                	mov    edi,eax
 170:	c1 ef 18             	shr    edi,0x18
 173:	49 89 c0             	mov    r8,rax
 176:	49 c1 e8 20          	shr    r8,0x20
 17a:	49 89 c1             	mov    r9,rax
 17d:	49 c1 e9 28          	shr    r9,0x28
 181:	49 89 c2             	mov    r10,rax
 184:	49 c1 ea 30          	shr    r10,0x30
 188:	49 89 c3             	mov    r11,rax
 18b:	49 c1 eb 38          	shr    r11,0x38
 18f:	44 88 59 07          	mov    BYTE PTR [rcx+0x7],r11b
 193:	44 88 51 06          	mov    BYTE PTR [rcx+0x6],r10b
 197:	44 88 49 05          	mov    BYTE PTR [rcx+0x5],r9b
 19b:	44 88 41 04          	mov    BYTE PTR [rcx+0x4],r8b
 19f:	40 88 79 03          	mov    BYTE PTR [rcx+0x3],dil
 1a3:	40 88 71 02          	mov    BYTE PTR [rcx+0x2],sil
 1a7:	88 01                	mov    BYTE PTR [rcx],al
 1a9:	88 51 01             	mov    BYTE PTR [rcx+0x1],dl
 1ac:	b8 02 00 00 00       	mov    eax,0x2
 1b1:	c3                   	ret
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
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RSI, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <bcc_runqlat_log2_histogram_bucket_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (4) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RSI, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-9) - 1, 0),
    /* 0x1118: lea    rdi,[rsi+0x410] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RSI, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-16) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rdx],0x80 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112a: jne    110e <bcc_runqlat_log2_histogram_bucket_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-20) - 1, 128),
    /* 0x112c: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112e: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1130: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: mov    edi,DWORD PTR [rsi+0xc] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDI, HC_X86_RSI, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1134: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1136: jmp    1164 <bcc_runqlat_log2_histogram_bucket_xdp+0x64> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (20) - 1, 0),
    /* 0x1138: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: shl    rax,0x3 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 3), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1144: mov    edx,r11d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1147: and    al,0x38 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(HC_X86_RAX, 56), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1149: mov    ecx,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x114b: shl    rdx,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x114e: xor    rbx,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1151: mov    rdi,rbx [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1154: mov    rax,r10 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1157: cmp    r10,0x80 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x115e: je     123b <bcc_runqlat_log2_histogram_bucket_xdp+0x13b> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, (118) - 1, 128),
    /* 0x1164: movzx  edx,WORD PTR [rsi+rax*8+0x10] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RDX, HC_X86_RSI, HC_X86_RAX, 3, 16), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1169: movzx  ecx,BYTE PTR [rsi+rax*8+0x12] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RCX, HC_X86_RSI, HC_X86_RAX, 3, 18), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x116e: shl    ecx,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1171: or     rcx,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1174: mov    edx,ecx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1176: shr    edx,0x3 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 3), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1179: mov    r8d,0x0 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117f: and    edx,0xfffff [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 1048575), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1185: je     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (25) - 1, 0),
    /* 0x1187: inc    rdx [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x118a: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x118d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1190: mov    r9d,r8d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1193: lea    r8d,[r9+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R8, HC_X86_R9, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1197: cmp    r9d,0x3d [control-flow-operand: cmp folded into BPF branch] */
    /* 0x119b: ja     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_6, 0, (14) - 1, 61),
    /* 0x119d: mov    r9,rdx [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a0: shr    r9,1 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11a3: cmp    rdx,0x3 [exact-kop: cmp64 reg,imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11a7: mov    rdx,r9 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11aa: ja     1190 <bcc_runqlat_log2_histogram_bucket_xdp+0x90> [exact-bpf: ja as ordinary BPF branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -380),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 3, 0),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_10, -384),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 1, 0),
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-19) - 1, 0),
    /* 0x11ac: movzx  edx,BYTE PTR [rsi+rax*8+0x13] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RDX, HC_X86_RSI, HC_X86_RAX, 3, 19), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11b1: shl    edx,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b4: or     rdx,rcx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11b7: movzx  ecx,BYTE PTR [rsi+rax*8+0x14] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RCX, HC_X86_RSI, HC_X86_RAX, 3, 20), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11bc: shl    rcx,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11c0: movzx  r10d,BYTE PTR [rsi+rax*8+0x15] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_R10, HC_X86_RSI, HC_X86_RAX, 3, 21), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c6: shl    r10,0x28 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11ca: or     r10,rcx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11cd: or     r10,rdx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11d0: movzx  ecx,BYTE PTR [rsi+rax*8+0x16] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RCX, HC_X86_RSI, HC_X86_RAX, 3, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11d5: shl    rcx,0x30 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11d9: movzx  r9d,BYTE PTR [rsi+rax*8+0x17] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_R9, HC_X86_RSI, HC_X86_RAX, 3, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11df: shl    r9,0x38 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11e3: or     r9,rcx [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e6: or     r9,r10 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x11e9: cmp    r8d,0x19 [exact-kop: cmp32 reg,imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 25), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x11ed: mov    r11d,0x19 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 25), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f3: cmovb  r11d,r8d [exact-kop: cmov kop using module shadow flags] */
    HC_KOP(HC_CMOV_ARCH_STACK_PAYLOAD(HC_X86_R11, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_CMOVBL),
    /* 0x11f7: lea    r14d,[r11+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R14, HC_X86_R11, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11fb: mov    edx,r11d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fe: and    dl,0x7 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(HC_X86_RDX, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1201: lea    ecx,[rdx+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1204: mov    r15,r9 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R15, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1207: shl    r15,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R15, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x120a: lea    r10,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R10, HC_X86_RAX, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x120e: imul   r14,r10 [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x1212: not    dl [exact-kop: not8 reg kop] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1214: mov    rbx,r9 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1217: mov    ecx,edx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1219: shr    rbx,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x121c: add    rdi,r14 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x121f: or     rbx,r15 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1222: xor    rbx,rdi [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1225: cmp    r8d,0x19 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1229: jb     1140 <bcc_runqlat_log2_histogram_bucket_xdp+0x40> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JLT | BPF_K, BPF_REG_6, 0, (-130) - 1, 25),
    /* 0x122f: shr    r9,0x20 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1233: add    rbx,r9 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1236: jmp    1151 <bcc_runqlat_log2_histogram_bucket_xdp+0x51> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-123) - 1, 0),
    /* 0x123b: mov    QWORD PTR [rsi],rdi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDI, HC_X86_RSI, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x123e: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1243: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1244: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1246: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1248: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
