# otel_stack_frame_unwind_scan

## Original C
```c
#include "common.h"

#define OTEL_UNWIND_FRAME_COUNT 24U
#define OTEL_UNWIND_FRAME_SIZE 24U
#define OTEL_UNWIND_INPUT_SIZE \
    (8U + OTEL_UNWIND_FRAME_COUNT * OTEL_UNWIND_FRAME_SIZE)

static __always_inline u32 otel_frame_kind_weight(u16 kind)
{
    switch (kind) {
    case 0U: return 0x21U;
    case 1U: return 0x35U;
    case 2U: return 0x55U;
    case 3U: return 0x89U;
    default: return 0U;
    }
}

static __always_inline int
bench_otel_stack_frame_unwind_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, OTEL_UNWIND_INPUT_SIZE)) {
        return -1;
    }

    u32 frame_count = micro_read_u32_le(data, 0U);
    u32 frame_size = micro_read_u32_le(data, 4U);
    if (frame_count != OTEL_UNWIND_FRAME_COUNT ||
        frame_size != OTEL_UNWIND_FRAME_SIZE) {
        return -1;
    }

    u64 acc = 0x589965CC75374CC3ULL;
    u64 cursor = 0x100000000ULL;
    for (u32 index = 0; index < OTEL_UNWIND_FRAME_COUNT; index++) {
        u32 base = 8U + index * OTEL_UNWIND_FRAME_SIZE;
        u64 ip = micro_read_u64_le(data, base);
        u32 sp_delta = micro_read_u32_le(data, base + 8U);
        u32 fp_delta = micro_read_u32_le(data, base + 12U);
        u16 flags = micro_read_u16_le(data, base + 16U);
        u16 kind = micro_read_u16_le(data, base + 18U);
        u32 symbol_hash = micro_read_u32_le(data, base + 20U);
        u32 weight = otel_frame_kind_weight(kind);
        u32 frame_ok = sp_delta <= 4096U && fp_delta <= 8192U;

        if (weight == 0U || frame_ok == 0U) {
            acc ^= ((u64)kind << 48U) | ip;
            continue;
        }

        cursor += sp_delta + ((flags & 1U) ? fp_delta : 8U);
        u64 frame_sig = ip ^ cursor ^ ((u64)symbol_hash << 32U) ^ weight;
        if ((flags & 2U) != 0U) {
            frame_sig = micro_rotl64(frame_sig, (kind & 7U) + 1U);
        }
        if ((flags & 4U) != 0U) {
            frame_sig += ((u64)fp_delta << 24U) ^ sp_delta;
        }

        acc += micro_rotl64(frame_sig, (index & 7U) + 1U);
        acc ^= ((u64)flags << 40U) | symbol_hash;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    otel_stack_frame_unwind_scan_xdp,
    bench_otel_stack_frame_unwind_scan,
    otel_stack_frame_unwind_scan_input_value,
    OTEL_UNWIND_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <otel_stack_frame_unwind_scan_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <otel_stack_frame_unwind_scan_xdp+0xe>
    1118:	48 8d b2 50 02 00 00 	lea    rsi,[rdx+0x250]
    111f:	48 39 ce             	cmp    rsi,rcx
    1122:	77 ea                	ja     110e <otel_stack_frame_unwind_scan_xdp+0xe>
    1124:	83 7a 08 18          	cmp    DWORD PTR [rdx+0x8],0x18
    1128:	75 e4                	jne    110e <otel_stack_frame_unwind_scan_xdp+0xe>
    112a:	83 7a 0c 18          	cmp    DWORD PTR [rdx+0xc],0x18
    112e:	75 de                	jne    110e <otel_stack_frame_unwind_scan_xdp+0xe>
    1130:	55                   	push   rbp
    1131:	41 57                	push   r15
    1133:	41 56                	push   r14
    1135:	41 55                	push   r13
    1137:	41 54                	push   r12
    1139:	53                   	push   rbx
    113a:	48 8d 72 27          	lea    rsi,[rdx+0x27]
    113e:	48 bf 00 00 00 00 01 	movabs rdi,0x100000000
    1145:	00 00 00 
    1148:	49 bb c3 4c 37 75 cc 	movabs r11,0x589965cc75374cc3
    114f:	65 99 58 
    1152:	45 31 c0             	xor    r8d,r8d
    1155:	eb 24                	jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b>
    1157:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    115e:	00 00 
    1160:	49 c1 e6 30          	shl    r14,0x30
    1164:	49 09 c6             	or     r14,rax
    1167:	4d 31 f3             	xor    r11,r14
    116a:	49 ff c0             	inc    r8
    116d:	48 83 c6 18          	add    rsi,0x18
    1171:	49 83 f8 18          	cmp    r8,0x18
    1175:	0f 84 c6 00 00 00    	je     1241 <otel_stack_frame_unwind_scan_xdp+0x141>
    117b:	48 8b 46 e9          	mov    rax,QWORD PTR [rsi-0x17]
    117f:	0f b6 4e fb          	movzx  ecx,BYTE PTR [rsi-0x5]
    1183:	44 0f b6 76 fc       	movzx  r14d,BYTE PTR [rsi-0x4]
    1188:	41 c1 e6 08          	shl    r14d,0x8
    118c:	49 09 ce             	or     r14,rcx
    118f:	66 41 83 fe 03       	cmp    r14w,0x3
    1194:	77 ca                	ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    1196:	44 8b 7e f1          	mov    r15d,DWORD PTR [rsi-0xf]
    119a:	41 81 ff 00 10 00 00 	cmp    r15d,0x1000
    11a1:	77 bd                	ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11a3:	44 8b 66 f5          	mov    r12d,DWORD PTR [rsi-0xb]
    11a7:	41 81 fc 01 20 00 00 	cmp    r12d,0x2001
    11ae:	73 b0                	jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11b0:	0f b7 6e f9          	movzx  ebp,WORD PTR [rsi-0x7]
    11b4:	44 8b 4e fd          	mov    r9d,DWORD PTR [rsi-0x3]
    11b8:	45 0f b7 f6          	movzx  r14d,r14w
    11bc:	40 f6 c5 01          	test   bpl,0x1
    11c0:	45 89 e5             	mov    r13d,r12d
    11c3:	41 ba 08 00 00 00    	mov    r10d,0x8
    11c9:	45 0f 44 ea          	cmove  r13d,r10d
    11cd:	4c 89 cb             	mov    rbx,r9
    11d0:	48 c1 e3 20          	shl    rbx,0x20
    11d4:	4c 8d 15 25 0e 00 00 	lea    r10,[rip+0xe25]        # 2000 <_fini+0xdac>
    11db:	4b 0b 1c f2          	or     rbx,QWORD PTR [r10+r14*8]
    11df:	45 01 fd             	add    r13d,r15d
    11e2:	4c 01 ef             	add    rdi,r13
    11e5:	48 31 f8             	xor    rax,rdi
    11e8:	48 31 d8             	xor    rax,rbx
    11eb:	40 f6 c5 02          	test   bpl,0x2
    11ef:	74 05                	je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6>
    11f1:	ff c1                	inc    ecx
    11f3:	48 d3 c0             	rol    rax,cl
    11f6:	44 89 e1             	mov    ecx,r12d
    11f9:	48 c1 e1 18          	shl    rcx,0x18
    11fd:	44 89 fb             	mov    ebx,r15d
    1200:	48 31 cb             	xor    rbx,rcx
    1203:	40 f6 c5 04          	test   bpl,0x4
    1207:	41 be 00 00 00 00    	mov    r14d,0x0
    120d:	4c 0f 45 f3          	cmovne r14,rbx
    1211:	49 01 c6             	add    r14,rax
    1214:	44 89 c0             	mov    eax,r8d
    1217:	24 07                	and    al,0x7
    1219:	8d 48 01             	lea    ecx,[rax+0x1]
    121c:	4c 89 f3             	mov    rbx,r14
    121f:	48 d3 e3             	shl    rbx,cl
    1222:	f6 d0                	not    al
    1224:	89 c1                	mov    ecx,eax
    1226:	49 d3 ee             	shr    r14,cl
    1229:	49 09 de             	or     r14,rbx
    122c:	4d 01 de             	add    r14,r11
    122f:	0f b7 c5             	movzx  eax,bp
    1232:	48 c1 e0 28          	shl    rax,0x28
    1236:	49 09 c1             	or     r9,rax
    1239:	4d 89 cb             	mov    r11,r9
    123c:	e9 26 ff ff ff       	jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67>
    1241:	4c 89 1a             	mov    QWORD PTR [rdx],r11
    1244:	b8 02 00 00 00       	mov    eax,0x2
    1249:	5b                   	pop    rbx
    124a:	41 5c                	pop    r12
    124c:	41 5d                	pop    r13
    124e:	41 5e                	pop    r14
    1250:	41 5f                	pop    r15
    1252:	5d                   	pop    rbp
    1253:	c3                   	ret

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
   c:	48 81 ec 70 00 00 00 	sub    rsp,0x70
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 f3 03 00 00    	ja     0x420
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 e3 03 00 00    	ja     0x420
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 50 02 00 00 	add    rdi,0x250
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 d0 03 00 00    	ja     0x420
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
  81:	48 83 ff 18          	cmp    rdi,0x18
  85:	0f 85 95 03 00 00    	jne    0x420
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
  c0:	0f 85 5a 03 00 00    	jne    0x420
  c6:	48 bf 00 00 00 00 01 	movabs rdi,0x100000000
  cd:	00 00 00 
  d0:	48 89 7d 98          	mov    QWORD PTR [rbp-0x68],rdi
  d4:	48 bf c3 4c 37 75 cc 	movabs rdi,0x589965cc75374cc3
  db:	65 99 58 
  de:	45 31 c0             	xor    r8d,r8d
  e1:	48 89 55 90          	mov    QWORD PTR [rbp-0x70],rdx
  e5:	48 89 d1             	mov    rcx,rdx
  e8:	48 83 c1 13          	add    rcx,0x13
  ec:	e9 8a 00 00 00       	jmp    0x17b
  f1:	48 c1 e7 08          	shl    rdi,0x8
  f5:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
  f9:	48 09 f7             	or     rdi,rsi
  fc:	48 c1 e2 10          	shl    rdx,0x10
 100:	48 09 d7             	or     rdi,rdx
 103:	48 c1 e3 18          	shl    rbx,0x18
 107:	48 09 df             	or     rdi,rbx
 10a:	48 89 fa             	mov    rdx,rdi
 10d:	48 c1 e2 20          	shl    rdx,0x20
 111:	48 c1 ea 20          	shr    rdx,0x20
 115:	48 81 fa 00 10 00 00 	cmp    rdx,0x1000
 11c:	77 36                	ja     0x154
 11e:	49 c1 e5 08          	shl    r13,0x8
 122:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 126:	49 09 f5             	or     r13,rsi
 129:	49 c1 e0 10          	shl    r8,0x10
 12d:	4d 09 c5             	or     r13,r8
 130:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 134:	48 c1 e6 18          	shl    rsi,0x18
 138:	49 09 f5             	or     r13,rsi
 13b:	4c 89 ee             	mov    rsi,r13
 13e:	48 c1 e6 20          	shl    rsi,0x20
 142:	48 c1 ee 20          	shr    rsi,0x20
 146:	ba 01 20 00 00       	mov    edx,0x2001
 14b:	48 39 f2             	cmp    rdx,rsi
 14e:	0f 87 4d 01 00 00    	ja     0x2a1
 154:	49 c1 e6 30          	shl    r14,0x30
 158:	4d 09 fe             	or     r14,r15
 15b:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 15f:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 163:	49 31 fe             	xor    r14,rdi
 166:	48 83 c1 18          	add    rcx,0x18
 16a:	49 83 c0 01          	add    r8,0x1
 16e:	4c 89 f7             	mov    rdi,r14
 171:	49 83 f8 18          	cmp    r8,0x18
 175:	0f 84 4e 02 00 00    	je     0x3c9
 17b:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
 17f:	4c 89 45 f8          	mov    QWORD PTR [rbp-0x8],r8
 183:	48 0f b6 79 fe       	movzx  rdi,BYTE PTR [rcx-0x2]
 188:	48 c1 e7 08          	shl    rdi,0x8
 18c:	48 0f b6 71 fd       	movzx  rsi,BYTE PTR [rcx-0x3]
 191:	48 09 f7             	or     rdi,rsi
 194:	48 0f b6 71 ff       	movzx  rsi,BYTE PTR [rcx-0x1]
 199:	48 c1 e6 10          	shl    rsi,0x10
 19d:	48 09 fe             	or     rsi,rdi
 1a0:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 1a5:	48 c1 e7 18          	shl    rdi,0x18
 1a9:	48 09 f7             	or     rdi,rsi
 1ac:	48 0f b6 71 01       	movzx  rsi,BYTE PTR [rcx+0x1]
 1b1:	48 c1 e6 20          	shl    rsi,0x20
 1b5:	48 09 fe             	or     rsi,rdi
 1b8:	4c 0f b6 69 0a       	movzx  r13,BYTE PTR [rcx+0xa]
 1bd:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 1c2:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 1c6:	4c 0f b6 41 02       	movzx  r8,BYTE PTR [rcx+0x2]
 1cb:	49 c1 e0 28          	shl    r8,0x28
 1cf:	49 09 f0             	or     r8,rsi
 1d2:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 1d7:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 1db:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 1e0:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 1e4:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 1e9:	48 0f b6 71 05       	movzx  rsi,BYTE PTR [rcx+0x5]
 1ee:	48 89 75 e8          	mov    QWORD PTR [rbp-0x18],rsi
 1f2:	48 0f b6 51 07       	movzx  rdx,BYTE PTR [rcx+0x7]
 1f7:	48 0f b6 71 13       	movzx  rsi,BYTE PTR [rcx+0x13]
 1fc:	48 89 75 b0          	mov    QWORD PTR [rbp-0x50],rsi
 200:	48 0f b6 41 03       	movzx  rax,BYTE PTR [rcx+0x3]
 205:	48 c1 e0 30          	shl    rax,0x30
 209:	4c 09 c0             	or     rax,r8
 20c:	4c 0f b6 41 0b       	movzx  r8,BYTE PTR [rcx+0xb]
 211:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
 216:	48 89 75 c0          	mov    QWORD PTR [rbp-0x40],rsi
 21a:	48 0f b6 71 0d       	movzx  rsi,BYTE PTR [rcx+0xd]
 21f:	48 89 75 a0          	mov    QWORD PTR [rbp-0x60],rsi
 223:	48 0f b6 71 14       	movzx  rsi,BYTE PTR [rcx+0x14]
 228:	48 89 75 a8          	mov    QWORD PTR [rbp-0x58],rsi
 22c:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
 231:	48 89 75 d8          	mov    QWORD PTR [rbp-0x28],rsi
 235:	48 0f b6 59 08       	movzx  rbx,BYTE PTR [rcx+0x8]
 23a:	4c 0f b6 79 04       	movzx  r15,BYTE PTR [rcx+0x4]
 23f:	49 c1 e7 38          	shl    r15,0x38
 243:	49 09 c7             	or     r15,rax
 246:	48 0f b6 41 0f       	movzx  rax,BYTE PTR [rcx+0xf]
 24b:	4c 0f b6 71 10       	movzx  r14,BYTE PTR [rcx+0x10]
 250:	49 c1 e6 08          	shl    r14,0x8
 254:	49 09 c6             	or     r14,rax
 257:	4c 89 f0             	mov    rax,r14
 25a:	48 25 ff ff 00 00    	and    rax,0xffff
 260:	48 83 f8 01          	cmp    rax,0x1
 264:	7f 1c                	jg     0x282
 266:	be 21 00 00 00       	mov    esi,0x21
 26b:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
 26f:	48 85 c0             	test   rax,rax
 272:	0f 84 79 fe ff ff    	je     0xf1
 278:	be 35 00 00 00       	mov    esi,0x35
 27d:	e9 3e 01 00 00       	jmp    0x3c0
 282:	48 83 f8 02          	cmp    rax,0x2
 286:	0f 84 2f 01 00 00    	je     0x3bb
 28c:	48 83 f8 03          	cmp    rax,0x3
 290:	74 05                	je     0x297
 292:	e9 bd fe ff ff       	jmp    0x154
 297:	be 89 00 00 00       	mov    esi,0x89
 29c:	e9 1f 01 00 00       	jmp    0x3c0
 2a1:	48 8b 5d c0          	mov    rbx,QWORD PTR [rbp-0x40]
 2a5:	48 c1 e3 08          	shl    rbx,0x8
 2a9:	48 8b 75 a0          	mov    rsi,QWORD PTR [rbp-0x60]
 2ad:	48 09 f3             	or     rbx,rsi
 2b0:	48 89 da             	mov    rdx,rbx
 2b3:	48 83 e2 01          	and    rdx,0x1
 2b7:	be 08 00 00 00       	mov    esi,0x8
 2bc:	48 85 d2             	test   rdx,rdx
 2bf:	74 03                	je     0x2c4
 2c1:	4c 89 ee             	mov    rsi,r13
 2c4:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
 2c8:	48 c1 e0 08          	shl    rax,0x8
 2cc:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 2d0:	48 09 d0             	or     rax,rdx
 2d3:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
 2d7:	48 c1 e2 10          	shl    rdx,0x10
 2db:	48 09 d0             	or     rax,rdx
 2de:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
 2e2:	48 c1 e2 18          	shl    rdx,0x18
 2e6:	48 09 d0             	or     rax,rdx
 2e9:	48 01 fe             	add    rsi,rdi
 2ec:	48 c1 e6 20          	shl    rsi,0x20
 2f0:	48 c1 ee 20          	shr    rsi,0x20
 2f4:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
 2f8:	48 01 f2             	add    rdx,rsi
 2fb:	48 89 c6             	mov    rsi,rax
 2fe:	48 c1 e6 20          	shl    rsi,0x20
 302:	4c 8b 45 d0          	mov    r8,QWORD PTR [rbp-0x30]
 306:	49 09 f0             	or     r8,rsi
 309:	4d 31 c7             	xor    r15,r8
 30c:	48 89 55 98          	mov    QWORD PTR [rbp-0x68],rdx
 310:	49 31 d7             	xor    r15,rdx
 313:	48 89 de             	mov    rsi,rbx
 316:	48 83 e6 02          	and    rsi,0x2
 31a:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 31e:	48 85 f6             	test   rsi,rsi
 321:	74 26                	je     0x349
 323:	49 83 c6 01          	add    r14,0x1
 327:	49 81 e6 ff ff 00 00 	and    r14,0xffff
 32e:	be 40 00 00 00       	mov    esi,0x40
 333:	4c 29 f6             	sub    rsi,r14
 336:	4c 89 fa             	mov    rdx,r15
 339:	c4 e2 89 f7 d2       	shlx   rdx,rdx,r14
 33e:	c4 42 cb f7 ff       	shrx   r15,r15,rsi
 343:	4c 09 fa             	or     rdx,r15
 346:	49 89 d7             	mov    r15,rdx
 349:	48 89 de             	mov    rsi,rbx
 34c:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 353:	48 83 e6 04          	and    rsi,0x4
 357:	48 85 f6             	test   rsi,rsi
 35a:	74 1d                	je     0x379
 35c:	48 c1 e7 20          	shl    rdi,0x20
 360:	48 c1 ef 20          	shr    rdi,0x20
 364:	49 c1 e5 20          	shl    r13,0x20
 368:	49 c1 ed 20          	shr    r13,0x20
 36c:	49 c1 e5 18          	shl    r13,0x18
 370:	49 31 fd             	xor    r13,rdi
 373:	4d 01 fd             	add    r13,r15
 376:	4d 89 ef             	mov    r15,r13
 379:	4c 89 c7             	mov    rdi,r8
 37c:	48 83 e7 07          	and    rdi,0x7
 380:	48 89 fe             	mov    rsi,rdi
 383:	48 83 f6 3f          	xor    rsi,0x3f
 387:	4c 89 fa             	mov    rdx,r15
 38a:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 38f:	48 83 c7 01          	add    rdi,0x1
 393:	c4 42 c1 f7 ff       	shlx   r15,r15,rdi
 398:	49 09 d7             	or     r15,rdx
 39b:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 39f:	49 01 ff             	add    r15,rdi
 3a2:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 3a9:	48 c1 e3 28          	shl    rbx,0x28
 3ad:	48 09 d8             	or     rax,rbx
 3b0:	48 89 c7             	mov    rdi,rax
 3b3:	4d 89 fe             	mov    r14,r15
 3b6:	e9 a8 fd ff ff       	jmp    0x163
 3bb:	be 55 00 00 00       	mov    esi,0x55
 3c0:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
 3c4:	e9 28 fd ff ff       	jmp    0xf1
 3c9:	4c 89 f7             	mov    rdi,r14
 3cc:	48 c1 ef 38          	shr    rdi,0x38
 3d0:	48 8b 75 90          	mov    rsi,QWORD PTR [rbp-0x70]
 3d4:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3d8:	4c 89 f7             	mov    rdi,r14
 3db:	48 c1 ef 30          	shr    rdi,0x30
 3df:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3e3:	4c 89 f7             	mov    rdi,r14
 3e6:	48 c1 ef 28          	shr    rdi,0x28
 3ea:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 3ee:	4c 89 f7             	mov    rdi,r14
 3f1:	48 c1 ef 20          	shr    rdi,0x20
 3f5:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 3f9:	4c 89 f7             	mov    rdi,r14
 3fc:	48 c1 ef 18          	shr    rdi,0x18
 400:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 404:	4c 89 f7             	mov    rdi,r14
 407:	48 c1 ef 10          	shr    rdi,0x10
 40b:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 40f:	44 88 76 00          	mov    BYTE PTR [rsi+0x0],r14b
 413:	49 c1 ee 08          	shr    r14,0x8
 417:	44 88 76 01          	mov    BYTE PTR [rsi+0x1],r14b
 41b:	b8 02 00 00 00       	mov    eax,0x2
 420:	41 5f                	pop    r15
 422:	41 5e                	pop    r14
 424:	41 5d                	pop    r13
 426:	5b                   	pop    rbx
 427:	c9                   	leave
 428:	c3                   	ret
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
   d:	0f 87 9e 02 00 00    	ja     0x2b1
  13:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  17:	48 39 ca             	cmp    rdx,rcx
  1a:	0f 87 91 02 00 00    	ja     0x2b1
  20:	48 8d 96 50 02 00 00 	lea    rdx,[rsi+0x250]
  27:	48 39 ca             	cmp    rdx,rcx
  2a:	0f 87 81 02 00 00    	ja     0x2b1
  30:	83 7e 08 18          	cmp    DWORD PTR [rsi+0x8],0x18
  34:	0f 85 5d 02 00 00    	jne    0x297
  3a:	83 7e 0c 18          	cmp    DWORD PTR [rsi+0xc],0x18
  3e:	0f 85 53 02 00 00    	jne    0x297
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 89 74 24 c0       	mov    QWORD PTR [rsp-0x40],rsi
  53:	48 8d 46 13          	lea    rax,[rsi+0x13]
  57:	49 bb c3 4c 37 75 cc 	movabs r11,0x589965cc75374cc3
  5e:	65 99 58 
  61:	48 b9 00 00 00 00 01 	movabs rcx,0x100000000
  68:	00 00 00 
  6b:	48 89 4c 24 b8       	mov    QWORD PTR [rsp-0x48],rcx
  70:	31 ff                	xor    edi,edi
  72:	eb 2d                	jmp    0xa1
  74:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  7b:	00 00 00 00 00 
  80:	49 c1 e2 30          	shl    r10,0x30
  84:	49 09 f2             	or     r10,rsi
  87:	4c 89 d9             	mov    rcx,r11
  8a:	4d 89 d3             	mov    r11,r10
  8d:	49 31 cb             	xor    r11,rcx
  90:	48 83 c0 18          	add    rax,0x18
  94:	48 ff c7             	inc    rdi
  97:	48 83 ff 18          	cmp    rdi,0x18
  9b:	0f 84 f9 01 00 00    	je     0x29a
  a1:	0f b6 58 0a          	movzx  ebx,BYTE PTR [rax+0xa]
  a5:	44 0f b6 40 09       	movzx  r8d,BYTE PTR [rax+0x9]
  aa:	0f b6 48 12          	movzx  ecx,BYTE PTR [rax+0x12]
  ae:	48 89 4c 24 e0       	mov    QWORD PTR [rsp-0x20],rcx
  b3:	0f b6 48 11          	movzx  ecx,BYTE PTR [rax+0x11]
  b7:	48 89 4c 24 d8       	mov    QWORD PTR [rsp-0x28],rcx
  bc:	0f b6 68 06          	movzx  ebp,BYTE PTR [rax+0x6]
  c0:	0f b6 48 05          	movzx  ecx,BYTE PTR [rax+0x5]
  c4:	48 89 4c 24 f8       	mov    QWORD PTR [rsp-0x8],rcx
  c9:	44 0f b6 70 07       	movzx  r14d,BYTE PTR [rax+0x7]
  ce:	0f b6 48 13          	movzx  ecx,BYTE PTR [rax+0x13]
  d2:	48 89 4c 24 e8       	mov    QWORD PTR [rsp-0x18],rcx
  d7:	44 0f b6 48 0b       	movzx  r9d,BYTE PTR [rax+0xb]
  dc:	0f b6 48 0e          	movzx  ecx,BYTE PTR [rax+0xe]
  e0:	48 89 4c 24 f0       	mov    QWORD PTR [rsp-0x10],rcx
  e5:	0f b6 50 0d          	movzx  edx,BYTE PTR [rax+0xd]
  e9:	44 0f b6 60 14       	movzx  r12d,BYTE PTR [rax+0x14]
  ee:	44 0f b6 78 0c       	movzx  r15d,BYTE PTR [rax+0xc]
  f3:	0f b6 48 0f          	movzx  ecx,BYTE PTR [rax+0xf]
  f7:	44 0f b6 50 10       	movzx  r10d,BYTE PTR [rax+0x10]
  fc:	41 c1 e2 08          	shl    r10d,0x8
 100:	48 89 4c 24 d0       	mov    QWORD PTR [rsp-0x30],rcx
 105:	49 09 ca             	or     r10,rcx
 108:	44 0f b6 68 08       	movzx  r13d,BYTE PTR [rax+0x8]
 10d:	48 8b 70 fd          	mov    rsi,QWORD PTR [rax-0x3]
 111:	49 83 fa 01          	cmp    r10,0x1
 115:	76 29                	jbe    0x140
 117:	49 83 fa 02          	cmp    r10,0x2
 11b:	74 70                	je     0x18d
 11d:	b9 89 00 00 00       	mov    ecx,0x89
 122:	48 89 4c 24 b0       	mov    QWORD PTR [rsp-0x50],rcx
 127:	41 83 fa 03          	cmp    r10d,0x3
 12b:	74 73                	je     0x1a0
 12d:	e9 4e ff ff ff       	jmp    0x80
 132:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 139:	1f 84 00 00 00 00 00 
 140:	4d 85 d2             	test   r10,r10
 143:	4c 89 7c 24 c8       	mov    QWORD PTR [rsp-0x38],r15
 148:	49 89 ff             	mov    r15,rdi
 14b:	4c 89 cf             	mov    rdi,r9
 14e:	49 89 d9             	mov    r9,rbx
 151:	4c 89 c3             	mov    rbx,r8
 154:	41 b8 35 00 00 00    	mov    r8d,0x35
 15a:	48 89 f1             	mov    rcx,rsi
 15d:	4c 89 e6             	mov    rsi,r12
 160:	49 89 d4             	mov    r12,rdx
 163:	ba 21 00 00 00       	mov    edx,0x21
 168:	4c 0f 44 c2          	cmove  r8,rdx
 16c:	4c 89 44 24 b0       	mov    QWORD PTR [rsp-0x50],r8
 171:	49 89 d8             	mov    r8,rbx
 174:	4c 89 cb             	mov    rbx,r9
 177:	49 89 f9             	mov    r9,rdi
 17a:	4c 89 ff             	mov    rdi,r15
 17d:	4c 8b 7c 24 c8       	mov    r15,QWORD PTR [rsp-0x38]
 182:	4c 89 e2             	mov    rdx,r12
 185:	49 89 f4             	mov    r12,rsi
 188:	48 89 ce             	mov    rsi,rcx
 18b:	eb 13                	jmp    0x1a0
 18d:	b9 55 00 00 00       	mov    ecx,0x55
 192:	48 89 4c 24 b0       	mov    QWORD PTR [rsp-0x50],rcx
 197:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
 19e:	00 00 
 1a0:	c1 e5 08             	shl    ebp,0x8
 1a3:	48 03 6c 24 f8       	add    rbp,QWORD PTR [rsp-0x8]
 1a8:	41 c1 e6 10          	shl    r14d,0x10
 1ac:	49 09 ee             	or     r14,rbp
 1af:	41 c1 e5 18          	shl    r13d,0x18
 1b3:	4d 09 f5             	or     r13,r14
 1b6:	49 81 fd 00 10 00 00 	cmp    r13,0x1000
 1bd:	0f 87 bd fe ff ff    	ja     0x80
 1c3:	c1 e3 08             	shl    ebx,0x8
 1c6:	4c 09 c3             	or     rbx,r8
 1c9:	41 c1 e1 10          	shl    r9d,0x10
 1cd:	49 09 d9             	or     r9,rbx
 1d0:	41 c1 e7 18          	shl    r15d,0x18
 1d4:	4d 09 cf             	or     r15,r9
 1d7:	49 81 ff 01 20 00 00 	cmp    r15,0x2001
 1de:	0f 83 9c fe ff ff    	jae    0x80
 1e4:	f6 c2 01             	test   dl,0x1
 1e7:	4d 89 f8             	mov    r8,r15
 1ea:	41 b9 08 00 00 00    	mov    r9d,0x8
 1f0:	4d 0f 44 c1          	cmove  r8,r9
 1f4:	4c 8b 4c 24 e0       	mov    r9,QWORD PTR [rsp-0x20]
 1f9:	41 c1 e1 08          	shl    r9d,0x8
 1fd:	4c 03 4c 24 d8       	add    r9,QWORD PTR [rsp-0x28]
 202:	48 8b 4c 24 e8       	mov    rcx,QWORD PTR [rsp-0x18]
 207:	c1 e1 10             	shl    ecx,0x10
 20a:	4c 09 c9             	or     rcx,r9
 20d:	41 c1 e4 18          	shl    r12d,0x18
 211:	49 09 cc             	or     r12,rcx
 214:	4c 8b 4c 24 b8       	mov    r9,QWORD PTR [rsp-0x48]
 219:	4d 01 e9             	add    r9,r13
 21c:	4d 01 c1             	add    r9,r8
 21f:	4d 89 e0             	mov    r8,r12
 222:	49 c1 e0 20          	shl    r8,0x20
 226:	48 8b 4c 24 b0       	mov    rcx,QWORD PTR [rsp-0x50]
 22b:	4c 09 c1             	or     rcx,r8
 22e:	48 31 ce             	xor    rsi,rcx
 231:	4c 89 4c 24 b8       	mov    QWORD PTR [rsp-0x48],r9
 236:	4c 31 ce             	xor    rsi,r9
 239:	f6 c2 02             	test   dl,0x2
 23c:	74 0a                	je     0x248
 23e:	48 8b 4c 24 d0       	mov    rcx,QWORD PTR [rsp-0x30]
 243:	fe c1                	inc    cl
 245:	48 d3 c6             	rol    rsi,cl
 248:	48 89 d1             	mov    rcx,rdx
 24b:	48 c1 e1 3d          	shl    rcx,0x3d
 24f:	48 c1 f9 3f          	sar    rcx,0x3f
 253:	49 c1 e7 18          	shl    r15,0x18
 257:	4d 09 ef             	or     r15,r13
 25a:	49 21 cf             	and    r15,rcx
 25d:	49 01 f7             	add    r15,rsi
 260:	89 f9                	mov    ecx,edi
 262:	80 e1 07             	and    cl,0x7
 265:	89 ce                	mov    esi,ecx
 267:	40 f6 d6             	not    sil
 26a:	c4 c2 cb f7 f7       	shrx   rsi,r15,rsi
 26f:	fe c1                	inc    cl
 271:	c4 42 f1 f7 d7       	shlx   r10,r15,rcx
 276:	49 09 f2             	or     r10,rsi
 279:	4d 01 da             	add    r10,r11
 27c:	48 8b 4c 24 f0       	mov    rcx,QWORD PTR [rsp-0x10]
 281:	48 c1 e1 30          	shl    rcx,0x30
 285:	48 c1 e2 28          	shl    rdx,0x28
 289:	48 09 ca             	or     rdx,rcx
 28c:	4c 09 e2             	or     rdx,r12
 28f:	49 89 d3             	mov    r11,rdx
 292:	e9 f0 fd ff ff       	jmp    0x87
 297:	31 c0                	xor    eax,eax
 299:	c3                   	ret
 29a:	48 8b 44 24 c0       	mov    rax,QWORD PTR [rsp-0x40]
 29f:	4c 89 18             	mov    QWORD PTR [rax],r11
 2a2:	b8 02 00 00 00       	mov    eax,0x2
 2a7:	5b                   	pop    rbx
 2a8:	41 5c                	pop    r12
 2aa:	41 5d                	pop    r13
 2ac:	41 5e                	pop    r14
 2ae:	41 5f                	pop    r15
 2b0:	5d                   	pop    rbp
 2b1:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 41
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x18 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0x8],0x18]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0xc],0x18]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1148: movabs r11,0x589965cc75374cc3 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x589965cc75374cc3]
 * - 0x1167: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x118f: cmp    r14w,0x3 [warning-unmapped: CMP operand form has no current kop selector: cmp    r14w,0x3]
 * - 0x11a3: mov    r12d,DWORD PTR [rsi-0xb] [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,DWORD PTR [rsi-0xb]]
 * - 0x11a7: cmp    r12d,0x2001 [warning-unmapped: CMP operand form has no current kop selector: cmp    r12d,0x2001]
 * - 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: cannot lower cmp    r12d,0x2001 + jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> to BPF branch]
 * - 0x11b0: movzx  ebp,WORD PTR [rsi-0x7] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11b4: mov    r9d,DWORD PTR [rsi-0x3] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11bc: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11c0: mov    r13d,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    r13d,r12d]
 * - 0x11c3: mov    r10d,0x8 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x8]
 * - 0x11c9: cmove  r13d,r10d [warning-unmapped: cmove operands are not supported]
 * - 0x11cd: mov    rbx,r9 [warning-reg-remap: movq register-to-register kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11d4: lea    r10,[rip+0xe25] [warning-unmapped: LEA operands are not representable]
 * - 0x11db: or     rbx,QWORD PTR [r10+r14*8] [warning-unmapped: ALU memory base r10 is not in the BPF JIT register file]
 * - 0x11eb: test   bpl,0x2 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x11ef: je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11f6: mov    ecx,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r12d]
 * - 0x1203: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x120d: cmovne r14,rbx [warning-unmapped: cmovne needs an adjacent test/cmp proof payload]
 * - 0x122c: add    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x122f: movzx  eax,bp [warning-unmapped: movzx source size not recognized: bp]
 * - 0x1236: or     r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1239: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9]
 * - 0x1241: mov    QWORD PTR [rdx],r11 [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rdx],r11]
 * - 0x1249: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124c: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x124e: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1250: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1252: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x250] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 592), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x18 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0x8],0x18] */
    /* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0x8],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 24),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x18 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0xc],0x18] */
    /* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x18 + jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -15, 24),
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1139: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x113a: lea    rsi,[rdx+0x27] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113e: movabs rdi,0x100000000 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0x100000000ULL),
    /* 0x1148: movabs r11,0x589965cc75374cc3 [warning-unmapped: unsupported mnemonic or operand form: movabs r11,0x589965cc75374cc3] */
    /* 0x1152: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x1155: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 8, 0),
    /* 0x1157: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: shl    r14,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 48),
    /* 0x1164: or     r14,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_0, 0, 0),
    /* 0x1167: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x116a: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x116d: add    rsi,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 24),
    /* 0x1171: cmp    r8,0x18 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_5, 24), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1175: je     1241 <otel_stack_frame_unwind_scan_xdp+0x141> [bpf-branch: lowered cmp    r8,0x18 + je     1241 <otel_stack_frame_unwind_scan_xdp+0x141> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 49, 24),
    /* 0x117b: mov    rax,QWORD PTR [rsi-0x17] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_2, -23), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x117f: movzx  ecx,BYTE PTR [rsi-0x5] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1183: movzx  r14d,BYTE PTR [rsi-0x4] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_2, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1188: shl    r14d,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 8),
    /* 0x118c: or     r14,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x118f: cmp    r14w,0x3 [warning-unmapped: CMP operand form has no current kop selector: cmp    r14w,0x3] */
    /* 0x1194: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: lowered cmp    r14w,0x3 + ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_8, 0, -17, 3),
    /* 0x1196: mov    r15d,DWORD PTR [rsi-0xf] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -15), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x119a: cmp    r15d,0x1000 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_9, 4096), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a1: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [bpf-branch: lowered cmp    r15d,0x1000 + ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_9, 0, -22, 4096),
    /* 0x11a3: mov    r12d,DWORD PTR [rsi-0xb] [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,DWORD PTR [rsi-0xb]] */
    /* 0x11a7: cmp    r12d,0x2001 [warning-unmapped: CMP operand form has no current kop selector: cmp    r12d,0x2001] */
    /* 0x11ae: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [warning-unmapped: cannot lower cmp    r12d,0x2001 + jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> to BPF branch] */
    /* 0x11b0: movzx  ebp,WORD PTR [rsi-0x7] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11b4: mov    r9d,DWORD PTR [rsi-0x3] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_2, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11b8: movzx  r14d,r14w [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11bc: test   bpl,0x1 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11c0: mov    r13d,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    r13d,r12d] */
    /* 0x11c3: mov    r10d,0x8 [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,0x8] */
    /* 0x11c9: cmove  r13d,r10d [warning-unmapped: cmove operands are not supported] */
    /* 0x11cd: mov    rbx,r9 [warning-reg-remap: movq register-to-register kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x11d0: shl    rbx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 32),
    /* 0x11d4: lea    r10,[rip+0xe25] [warning-unmapped: LEA operands are not representable] */
    /* 0x11db: or     rbx,QWORD PTR [r10+r14*8] [warning-unmapped: ALU memory base r10 is not in the BPF JIT register file] */
    /* 0x11df: add    r13d,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x11e2: add    rdi,r13 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_7, 0, 0),
    /* 0x11e5: xor    rax,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x11e8: xor    rax,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x11eb: test   bpl,0x2 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x11ef: je     11f6 <otel_stack_frame_unwind_scan_xdp+0xf6> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11f1: inc    ecx [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 1),
    /* 0x11f3: rol    rax,cl [exact-kop: rolq cl kop; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KOP(HC_ROTATE_CL_PAYLOAD(BPF_REG_0, BPF_REG_4, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLQ_CL),
    /* 0x11f6: mov    ecx,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ecx,r12d] */
    /* 0x11f9: shl    rcx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 24),
    /* 0x11fd: mov    ebx,r15d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1200: xor    rbx,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1203: test   bpl,0x4 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x1207: mov    r14d,0x0 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_8, 0, 0, 0),
    /* 0x120d: cmovne r14,rbx [warning-unmapped: cmovne needs an adjacent test/cmp proof payload] */
    /* 0x1211: add    r14,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_0, 0, 0),
    /* 0x1214: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1217: and    al,0x7 [exact-kop: andb imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_0, 7, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1219: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x121c: mov    rbx,r14 [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x121f: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1222: not    al [exact-kop: notb reg kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1224: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1226: shr    r14,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_8, BPF_REG_4, 0, 0),
    /* 0x1229: or     r14,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x122c: add    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x122f: movzx  eax,bp [warning-unmapped: movzx source size not recognized: bp] */
    /* 0x1232: shl    rax,0x28 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 40),
    /* 0x1236: or     r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x1239: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9] */
    /* 0x123c: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -55, 0),
    /* 0x1241: mov    QWORD PTR [rdx],r11 [warning-unmapped: unsupported mnemonic or operand form: mov    QWORD PTR [rdx],r11] */
    /* 0x1244: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1249: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x124a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x124c: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x124e: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1250: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1252: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1253: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
