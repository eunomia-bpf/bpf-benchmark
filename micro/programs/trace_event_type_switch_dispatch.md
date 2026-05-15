# trace_event_type_switch_dispatch

## Original C
```c
#include "common.h"

#define SWITCH_DISPATCH_COUNT 128U
#define SWITCH_DISPATCH_INPUT_SIZE (4U + SWITCH_DISPATCH_COUNT * 4U)

static __always_inline u32 switch_value(u32 value)
{
    switch (value) {
    case 0: return 56;
    case 1: return 43;
    case 2: return 57;
    case 3: return 28;
    case 4: return 14;
    case 5: return 61;
    case 6: return 10;
    case 7: return 58;
    case 8: return 2;
    case 9: return 63;
    case 10: return 49;
    case 11: return 36;
    case 12: return 19;
    case 13: return 42;
    case 14: return 37;
    case 15: return 46;
    case 16: return 34;
    case 17: return 62;
    case 18: return 47;
    case 19: return 6;
    case 20: return 29;
    case 21: return 21;
    case 22: return 15;
    case 23: return 40;
    case 24: return 38;
    case 25: return 26;
    case 26: return 17;
    case 27: return 41;
    case 28: return 33;
    case 29: return 31;
    case 30: return 23;
    case 31: return 52;
    case 32: return 25;
    case 33: return 39;
    case 34: return 11;
    case 35: return 27;
    case 36: return 53;
    case 37: return 4;
    case 38: return 24;
    case 39: return 48;
    case 40: return 32;
    case 41: return 50;
    case 42: return 7;
    case 43: return 35;
    case 44: return 8;
    case 45: return 44;
    case 46: return 51;
    case 47: return 59;
    case 48: return 45;
    case 49: return 0;
    case 50: return 9;
    case 51: return 3;
    case 52: return 13;
    case 53: return 20;
    case 54: return 30;
    case 55: return 18;
    case 56: return 1;
    case 57: return 54;
    case 58: return 22;
    case 59: return 16;
    case 60: return 60;
    case 61: return 5;
    case 62: return 12;
    case 63: return 55;
    default: return 114514U;
    }
}

static __always_inline int bench_trace_event_type_switch_dispatch(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);

    if (count != SWITCH_DISPATCH_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 4, SWITCH_DISPATCH_COUNT * 4U)) {
        return -1;
    }

    u64 hash = 0;
    for (u32 i = 0; i < SWITCH_DISPATCH_COUNT; i++) {
        hash ^= switch_value(micro_read_u32_le(data, 4 + i * 4U));
    }

    *out = hash;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    trace_event_type_switch_dispatch_xdp,
    bench_trace_event_type_switch_dispatch,
    trace_event_type_switch_dispatch_input_value,
    SWITCH_DISPATCH_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <trace_event_type_switch_dispatch_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	76 01                	jbe    110f <trace_event_type_switch_dispatch_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1113:	48 39 d6             	cmp    rsi,rdx
    1116:	77 f6                	ja     110e <trace_event_type_switch_dispatch_xdp+0xe>
    1118:	48 8d b9 0c 02 00 00 	lea    rdi,[rcx+0x20c]
    111f:	48 39 d7             	cmp    rdi,rdx
    1122:	77 ea                	ja     110e <trace_event_type_switch_dispatch_xdp+0xe>
    1124:	81 3e 80 00 00 00    	cmp    DWORD PTR [rsi],0x80
    112a:	75 e2                	jne    110e <trace_event_type_switch_dispatch_xdp+0xe>
    112c:	be 0f 00 00 00       	mov    esi,0xf
    1131:	31 d2                	xor    edx,edx
    1133:	48 8d 3d c6 0e 00 00 	lea    rdi,[rip+0xec6]        # 2000 <_fini+0xe54>
    113a:	eb 14                	jmp    1150 <trace_event_type_switch_dispatch_xdp+0x50>
    113c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1140:	48 31 c2             	xor    rdx,rax
    1143:	48 83 c6 04          	add    rsi,0x4
    1147:	48 81 fe 0f 02 00 00 	cmp    rsi,0x20f
    114e:	74 1c                	je     116c <trace_event_type_switch_dispatch_xdp+0x6c>
    1150:	48 89 d0             	mov    rax,rdx
    1153:	44 8b 44 31 fd       	mov    r8d,DWORD PTR [rcx+rsi*1-0x3]
    1158:	ba 52 bf 01 00       	mov    edx,0x1bf52
    115d:	41 83 f8 3f          	cmp    r8d,0x3f
    1161:	77 dd                	ja     1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1163:	44 89 c2             	mov    edx,r8d
    1166:	48 8b 14 d7          	mov    rdx,QWORD PTR [rdi+rdx*8]
    116a:	eb d4                	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    116c:	88 11                	mov    BYTE PTR [rcx],dl
    116e:	88 71 01             	mov    BYTE PTR [rcx+0x1],dh
    1171:	c1 ea 10             	shr    edx,0x10
    1174:	88 51 02             	mov    BYTE PTR [rcx+0x2],dl
    1177:	89 c2                	mov    edx,eax
    1179:	c1 ea 18             	shr    edx,0x18
    117c:	88 51 03             	mov    BYTE PTR [rcx+0x3],dl
    117f:	48 89 c2             	mov    rdx,rax
    1182:	48 c1 ea 20          	shr    rdx,0x20
    1186:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
    1189:	48 89 c2             	mov    rdx,rax
    118c:	48 c1 ea 28          	shr    rdx,0x28
    1190:	88 51 05             	mov    BYTE PTR [rcx+0x5],dl
    1193:	48 89 c2             	mov    rdx,rax
    1196:	48 c1 ea 30          	shr    rdx,0x30
    119a:	88 51 06             	mov    BYTE PTR [rcx+0x6],dl
    119d:	48 c1 e8 38          	shr    rax,0x38
    11a1:	88 41 07             	mov    BYTE PTR [rcx+0x7],al
    11a4:	b8 02 00 00 00       	mov    eax,0x2
    11a9:	c3                   	ret

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
   c:	31 c0                	xor    eax,eax
   e:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  12:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  16:	48 39 f7             	cmp    rdi,rsi
  19:	0f 87 34 06 00 00    	ja     0x653
  1f:	48 89 fa             	mov    rdx,rdi
  22:	48 83 c2 08          	add    rdx,0x8
  26:	48 39 f2             	cmp    rdx,rsi
  29:	0f 87 24 06 00 00    	ja     0x653
  2f:	48 89 fa             	mov    rdx,rdi
  32:	48 81 c2 0c 02 00 00 	add    rdx,0x20c
  39:	48 39 f2             	cmp    rdx,rsi
  3c:	0f 87 11 06 00 00    	ja     0x653
  42:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  47:	48 c1 e6 08          	shl    rsi,0x8
  4b:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  50:	48 09 d6             	or     rsi,rdx
  53:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  58:	48 c1 e2 10          	shl    rdx,0x10
  5c:	48 09 d6             	or     rsi,rdx
  5f:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  64:	48 c1 e2 18          	shl    rdx,0x18
  68:	48 09 d6             	or     rsi,rdx
  6b:	48 c1 e6 20          	shl    rsi,0x20
  6f:	48 c1 ee 20          	shr    rsi,0x20
  73:	48 81 fe 80 00 00 00 	cmp    rsi,0x80
  7a:	0f 85 d3 05 00 00    	jne    0x653
  80:	31 d2                	xor    edx,edx
  82:	45 31 c0             	xor    r8d,r8d
  85:	eb 1a                	jmp    0xa1
  87:	41 b8 0c 00 00 00    	mov    r8d,0xc
  8d:	49 31 f0             	xor    r8,rsi
  90:	48 83 c2 04          	add    rdx,0x4
  94:	48 81 fa 00 02 00 00 	cmp    rdx,0x200
  9b:	0f 84 66 05 00 00    	je     0x607
  a1:	4c 89 c6             	mov    rsi,r8
  a4:	49 89 f8             	mov    r8,rdi
  a7:	49 01 d0             	add    r8,rdx
  aa:	49 0f b6 48 0d       	movzx  rcx,BYTE PTR [r8+0xd]
  af:	48 c1 e1 08          	shl    rcx,0x8
  b3:	49 0f b6 40 0c       	movzx  rax,BYTE PTR [r8+0xc]
  b8:	48 09 c1             	or     rcx,rax
  bb:	49 0f b6 40 0e       	movzx  rax,BYTE PTR [r8+0xe]
  c0:	48 c1 e0 10          	shl    rax,0x10
  c4:	48 09 c1             	or     rcx,rax
  c7:	4d 0f b6 40 0f       	movzx  r8,BYTE PTR [r8+0xf]
  cc:	49 c1 e0 18          	shl    r8,0x18
  d0:	4c 09 c1             	or     rcx,r8
  d3:	48 c1 e1 20          	shl    rcx,0x20
  d7:	48 c1 e9 20          	shr    rcx,0x20
  db:	48 83 f9 1f          	cmp    rcx,0x1f
  df:	7f 3e                	jg     0x11f
  e1:	48 83 f9 0f          	cmp    rcx,0xf
  e5:	7f 71                	jg     0x158
  e7:	48 83 f9 07          	cmp    rcx,0x7
  eb:	0f 8f ca 00 00 00    	jg     0x1bb
  f1:	48 83 f9 03          	cmp    rcx,0x3
  f5:	0f 8f 64 01 00 00    	jg     0x25f
  fb:	48 83 f9 01          	cmp    rcx,0x1
  ff:	0f 8f 52 02 00 00    	jg     0x357
 105:	41 b8 38 00 00 00    	mov    r8d,0x38
 10b:	48 85 c9             	test   rcx,rcx
 10e:	0f 84 79 ff ff ff    	je     0x8d
 114:	41 b8 2b 00 00 00    	mov    r8d,0x2b
 11a:	e9 6e ff ff ff       	jmp    0x8d
 11f:	48 83 f9 2f          	cmp    rcx,0x2f
 123:	7f 66                	jg     0x18b
 125:	48 83 f9 27          	cmp    rcx,0x27
 129:	0f 8f b5 00 00 00    	jg     0x1e4
 12f:	48 83 f9 23          	cmp    rcx,0x23
 133:	0f 8f 45 01 00 00    	jg     0x27e
 139:	48 83 f9 21          	cmp    rcx,0x21
 13d:	0f 8f 29 02 00 00    	jg     0x36c
 143:	48 83 f9 20          	cmp    rcx,0x20
 147:	0f 84 65 03 00 00    	je     0x4b2
 14d:	41 b8 27 00 00 00    	mov    r8d,0x27
 153:	e9 35 ff ff ff       	jmp    0x8d
 158:	48 83 f9 17          	cmp    rcx,0x17
 15c:	0f 8f ab 00 00 00    	jg     0x20d
 162:	48 83 f9 13          	cmp    rcx,0x13
 166:	0f 8f 31 01 00 00    	jg     0x29d
 16c:	48 83 f9 11          	cmp    rcx,0x11
 170:	0f 8f 0b 02 00 00    	jg     0x381
 176:	48 83 f9 10          	cmp    rcx,0x10
 17a:	0f 84 3d 03 00 00    	je     0x4bd
 180:	41 b8 3e 00 00 00    	mov    r8d,0x3e
 186:	e9 02 ff ff ff       	jmp    0x8d
 18b:	48 83 f9 37          	cmp    rcx,0x37
 18f:	0f 8f a1 00 00 00    	jg     0x236
 195:	48 83 f9 33          	cmp    rcx,0x33
 199:	0f 8f 1d 01 00 00    	jg     0x2bc
 19f:	48 83 f9 31          	cmp    rcx,0x31
 1a3:	0f 8f ed 01 00 00    	jg     0x396
 1a9:	48 83 f9 30          	cmp    rcx,0x30
 1ad:	0f 84 15 03 00 00    	je     0x4c8
 1b3:	45 31 c0             	xor    r8d,r8d
 1b6:	e9 d2 fe ff ff       	jmp    0x8d
 1bb:	48 83 f9 0b          	cmp    rcx,0xb
 1bf:	0f 8f 16 01 00 00    	jg     0x2db
 1c5:	48 83 f9 09          	cmp    rcx,0x9
 1c9:	0f 8f dc 01 00 00    	jg     0x3ab
 1cf:	48 83 f9 08          	cmp    rcx,0x8
 1d3:	0f 84 fa 02 00 00    	je     0x4d3
 1d9:	41 b8 3f 00 00 00    	mov    r8d,0x3f
 1df:	e9 a9 fe ff ff       	jmp    0x8d
 1e4:	48 83 f9 2b          	cmp    rcx,0x2b
 1e8:	0f 8f 0c 01 00 00    	jg     0x2fa
 1ee:	48 83 f9 29          	cmp    rcx,0x29
 1f2:	0f 8f c8 01 00 00    	jg     0x3c0
 1f8:	48 83 f9 28          	cmp    rcx,0x28
 1fc:	0f 84 dc 02 00 00    	je     0x4de
 202:	41 b8 32 00 00 00    	mov    r8d,0x32
 208:	e9 80 fe ff ff       	jmp    0x8d
 20d:	48 83 f9 1b          	cmp    rcx,0x1b
 211:	0f 8f 02 01 00 00    	jg     0x319
 217:	48 83 f9 19          	cmp    rcx,0x19
 21b:	0f 8f b4 01 00 00    	jg     0x3d5
 221:	48 83 f9 18          	cmp    rcx,0x18
 225:	0f 84 be 02 00 00    	je     0x4e9
 22b:	41 b8 1a 00 00 00    	mov    r8d,0x1a
 231:	e9 57 fe ff ff       	jmp    0x8d
 236:	48 83 f9 3b          	cmp    rcx,0x3b
 23a:	0f 8f f8 00 00 00    	jg     0x338
 240:	48 83 f9 39          	cmp    rcx,0x39
 244:	0f 8f a0 01 00 00    	jg     0x3ea
 24a:	48 83 f9 38          	cmp    rcx,0x38
 24e:	0f 84 a0 02 00 00    	je     0x4f4
 254:	41 b8 36 00 00 00    	mov    r8d,0x36
 25a:	e9 2e fe ff ff       	jmp    0x8d
 25f:	48 83 f9 05          	cmp    rcx,0x5
 263:	0f 8f 96 01 00 00    	jg     0x3ff
 269:	48 83 f9 04          	cmp    rcx,0x4
 26d:	0f 84 8c 02 00 00    	je     0x4ff
 273:	41 b8 3d 00 00 00    	mov    r8d,0x3d
 279:	e9 0f fe ff ff       	jmp    0x8d
 27e:	48 83 f9 25          	cmp    rcx,0x25
 282:	0f 8f 8c 01 00 00    	jg     0x414
 288:	48 83 f9 24          	cmp    rcx,0x24
 28c:	0f 84 78 02 00 00    	je     0x50a
 292:	41 b8 04 00 00 00    	mov    r8d,0x4
 298:	e9 f0 fd ff ff       	jmp    0x8d
 29d:	48 83 f9 15          	cmp    rcx,0x15
 2a1:	0f 8f 82 01 00 00    	jg     0x429
 2a7:	48 83 f9 14          	cmp    rcx,0x14
 2ab:	0f 84 64 02 00 00    	je     0x515
 2b1:	41 b8 15 00 00 00    	mov    r8d,0x15
 2b7:	e9 d1 fd ff ff       	jmp    0x8d
 2bc:	48 83 f9 35          	cmp    rcx,0x35
 2c0:	0f 8f 78 01 00 00    	jg     0x43e
 2c6:	48 83 f9 34          	cmp    rcx,0x34
 2ca:	0f 84 50 02 00 00    	je     0x520
 2d0:	41 b8 14 00 00 00    	mov    r8d,0x14
 2d6:	e9 b2 fd ff ff       	jmp    0x8d
 2db:	48 83 f9 0d          	cmp    rcx,0xd
 2df:	0f 8f 6e 01 00 00    	jg     0x453
 2e5:	48 83 f9 0c          	cmp    rcx,0xc
 2e9:	0f 84 3c 02 00 00    	je     0x52b
 2ef:	41 b8 2a 00 00 00    	mov    r8d,0x2a
 2f5:	e9 93 fd ff ff       	jmp    0x8d
 2fa:	48 83 f9 2d          	cmp    rcx,0x2d
 2fe:	0f 8f 64 01 00 00    	jg     0x468
 304:	48 83 f9 2c          	cmp    rcx,0x2c
 308:	0f 84 28 02 00 00    	je     0x536
 30e:	41 b8 2c 00 00 00    	mov    r8d,0x2c
 314:	e9 74 fd ff ff       	jmp    0x8d
 319:	48 83 f9 1d          	cmp    rcx,0x1d
 31d:	0f 8f 5a 01 00 00    	jg     0x47d
 323:	48 83 f9 1c          	cmp    rcx,0x1c
 327:	0f 84 14 02 00 00    	je     0x541
 32d:	41 b8 1f 00 00 00    	mov    r8d,0x1f
 333:	e9 55 fd ff ff       	jmp    0x8d
 338:	48 83 f9 3d          	cmp    rcx,0x3d
 33c:	0f 8f 50 01 00 00    	jg     0x492
 342:	48 83 f9 3c          	cmp    rcx,0x3c
 346:	0f 84 00 02 00 00    	je     0x54c
 34c:	41 b8 05 00 00 00    	mov    r8d,0x5
 352:	e9 36 fd ff ff       	jmp    0x8d
 357:	48 83 f9 02          	cmp    rcx,0x2
 35b:	0f 84 f6 01 00 00    	je     0x557
 361:	41 b8 1c 00 00 00    	mov    r8d,0x1c
 367:	e9 21 fd ff ff       	jmp    0x8d
 36c:	48 83 f9 22          	cmp    rcx,0x22
 370:	0f 84 ec 01 00 00    	je     0x562
 376:	41 b8 1b 00 00 00    	mov    r8d,0x1b
 37c:	e9 0c fd ff ff       	jmp    0x8d
 381:	48 83 f9 12          	cmp    rcx,0x12
 385:	0f 84 e2 01 00 00    	je     0x56d
 38b:	41 b8 06 00 00 00    	mov    r8d,0x6
 391:	e9 f7 fc ff ff       	jmp    0x8d
 396:	48 83 f9 32          	cmp    rcx,0x32
 39a:	0f 84 d8 01 00 00    	je     0x578
 3a0:	41 b8 03 00 00 00    	mov    r8d,0x3
 3a6:	e9 e2 fc ff ff       	jmp    0x8d
 3ab:	48 83 f9 0a          	cmp    rcx,0xa
 3af:	0f 84 ce 01 00 00    	je     0x583
 3b5:	41 b8 24 00 00 00    	mov    r8d,0x24
 3bb:	e9 cd fc ff ff       	jmp    0x8d
 3c0:	48 83 f9 2a          	cmp    rcx,0x2a
 3c4:	0f 84 c4 01 00 00    	je     0x58e
 3ca:	41 b8 23 00 00 00    	mov    r8d,0x23
 3d0:	e9 b8 fc ff ff       	jmp    0x8d
 3d5:	48 83 f9 1a          	cmp    rcx,0x1a
 3d9:	0f 84 ba 01 00 00    	je     0x599
 3df:	41 b8 29 00 00 00    	mov    r8d,0x29
 3e5:	e9 a3 fc ff ff       	jmp    0x8d
 3ea:	48 83 f9 3a          	cmp    rcx,0x3a
 3ee:	0f 84 b0 01 00 00    	je     0x5a4
 3f4:	41 b8 10 00 00 00    	mov    r8d,0x10
 3fa:	e9 8e fc ff ff       	jmp    0x8d
 3ff:	48 83 f9 06          	cmp    rcx,0x6
 403:	0f 84 a6 01 00 00    	je     0x5af
 409:	41 b8 3a 00 00 00    	mov    r8d,0x3a
 40f:	e9 79 fc ff ff       	jmp    0x8d
 414:	48 83 f9 26          	cmp    rcx,0x26
 418:	0f 84 9c 01 00 00    	je     0x5ba
 41e:	41 b8 30 00 00 00    	mov    r8d,0x30
 424:	e9 64 fc ff ff       	jmp    0x8d
 429:	48 83 f9 16          	cmp    rcx,0x16
 42d:	0f 84 92 01 00 00    	je     0x5c5
 433:	41 b8 28 00 00 00    	mov    r8d,0x28
 439:	e9 4f fc ff ff       	jmp    0x8d
 43e:	48 83 f9 36          	cmp    rcx,0x36
 442:	0f 84 88 01 00 00    	je     0x5d0
 448:	41 b8 12 00 00 00    	mov    r8d,0x12
 44e:	e9 3a fc ff ff       	jmp    0x8d
 453:	48 83 f9 0e          	cmp    rcx,0xe
 457:	0f 84 7e 01 00 00    	je     0x5db
 45d:	41 b8 2e 00 00 00    	mov    r8d,0x2e
 463:	e9 25 fc ff ff       	jmp    0x8d
 468:	48 83 f9 2e          	cmp    rcx,0x2e
 46c:	0f 84 74 01 00 00    	je     0x5e6
 472:	41 b8 3b 00 00 00    	mov    r8d,0x3b
 478:	e9 10 fc ff ff       	jmp    0x8d
 47d:	48 83 f9 1e          	cmp    rcx,0x1e
 481:	0f 84 6a 01 00 00    	je     0x5f1
 487:	41 b8 34 00 00 00    	mov    r8d,0x34
 48d:	e9 fb fb ff ff       	jmp    0x8d
 492:	48 83 f9 3e          	cmp    rcx,0x3e
 496:	0f 84 eb fb ff ff    	je     0x87
 49c:	48 83 f9 3f          	cmp    rcx,0x3f
 4a0:	74 05                	je     0x4a7
 4a2:	e9 55 01 00 00       	jmp    0x5fc
 4a7:	41 b8 37 00 00 00    	mov    r8d,0x37
 4ad:	e9 db fb ff ff       	jmp    0x8d
 4b2:	41 b8 19 00 00 00    	mov    r8d,0x19
 4b8:	e9 d0 fb ff ff       	jmp    0x8d
 4bd:	41 b8 22 00 00 00    	mov    r8d,0x22
 4c3:	e9 c5 fb ff ff       	jmp    0x8d
 4c8:	41 b8 2d 00 00 00    	mov    r8d,0x2d
 4ce:	e9 ba fb ff ff       	jmp    0x8d
 4d3:	41 b8 02 00 00 00    	mov    r8d,0x2
 4d9:	e9 af fb ff ff       	jmp    0x8d
 4de:	41 b8 20 00 00 00    	mov    r8d,0x20
 4e4:	e9 a4 fb ff ff       	jmp    0x8d
 4e9:	41 b8 26 00 00 00    	mov    r8d,0x26
 4ef:	e9 99 fb ff ff       	jmp    0x8d
 4f4:	41 b8 01 00 00 00    	mov    r8d,0x1
 4fa:	e9 8e fb ff ff       	jmp    0x8d
 4ff:	41 b8 0e 00 00 00    	mov    r8d,0xe
 505:	e9 83 fb ff ff       	jmp    0x8d
 50a:	41 b8 35 00 00 00    	mov    r8d,0x35
 510:	e9 78 fb ff ff       	jmp    0x8d
 515:	41 b8 1d 00 00 00    	mov    r8d,0x1d
 51b:	e9 6d fb ff ff       	jmp    0x8d
 520:	41 b8 0d 00 00 00    	mov    r8d,0xd
 526:	e9 62 fb ff ff       	jmp    0x8d
 52b:	41 b8 13 00 00 00    	mov    r8d,0x13
 531:	e9 57 fb ff ff       	jmp    0x8d
 536:	41 b8 08 00 00 00    	mov    r8d,0x8
 53c:	e9 4c fb ff ff       	jmp    0x8d
 541:	41 b8 21 00 00 00    	mov    r8d,0x21
 547:	e9 41 fb ff ff       	jmp    0x8d
 54c:	41 b8 3c 00 00 00    	mov    r8d,0x3c
 552:	e9 36 fb ff ff       	jmp    0x8d
 557:	41 b8 39 00 00 00    	mov    r8d,0x39
 55d:	e9 2b fb ff ff       	jmp    0x8d
 562:	41 b8 0b 00 00 00    	mov    r8d,0xb
 568:	e9 20 fb ff ff       	jmp    0x8d
 56d:	41 b8 2f 00 00 00    	mov    r8d,0x2f
 573:	e9 15 fb ff ff       	jmp    0x8d
 578:	41 b8 09 00 00 00    	mov    r8d,0x9
 57e:	e9 0a fb ff ff       	jmp    0x8d
 583:	41 b8 31 00 00 00    	mov    r8d,0x31
 589:	e9 ff fa ff ff       	jmp    0x8d
 58e:	41 b8 07 00 00 00    	mov    r8d,0x7
 594:	e9 f4 fa ff ff       	jmp    0x8d
 599:	41 b8 11 00 00 00    	mov    r8d,0x11
 59f:	e9 e9 fa ff ff       	jmp    0x8d
 5a4:	41 b8 16 00 00 00    	mov    r8d,0x16
 5aa:	e9 de fa ff ff       	jmp    0x8d
 5af:	41 b8 0a 00 00 00    	mov    r8d,0xa
 5b5:	e9 d3 fa ff ff       	jmp    0x8d
 5ba:	41 b8 18 00 00 00    	mov    r8d,0x18
 5c0:	e9 c8 fa ff ff       	jmp    0x8d
 5c5:	41 b8 0f 00 00 00    	mov    r8d,0xf
 5cb:	e9 bd fa ff ff       	jmp    0x8d
 5d0:	41 b8 1e 00 00 00    	mov    r8d,0x1e
 5d6:	e9 b2 fa ff ff       	jmp    0x8d
 5db:	41 b8 25 00 00 00    	mov    r8d,0x25
 5e1:	e9 a7 fa ff ff       	jmp    0x8d
 5e6:	41 b8 33 00 00 00    	mov    r8d,0x33
 5ec:	e9 9c fa ff ff       	jmp    0x8d
 5f1:	41 b8 17 00 00 00    	mov    r8d,0x17
 5f7:	e9 91 fa ff ff       	jmp    0x8d
 5fc:	41 b8 52 bf 01 00    	mov    r8d,0x1bf52
 602:	e9 86 fa ff ff       	jmp    0x8d
 607:	48 89 f2             	mov    rdx,rsi
 60a:	48 c1 ea 38          	shr    rdx,0x38
 60e:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 611:	48 89 f2             	mov    rdx,rsi
 614:	48 c1 ea 30          	shr    rdx,0x30
 618:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 61b:	48 89 f2             	mov    rdx,rsi
 61e:	48 c1 ea 28          	shr    rdx,0x28
 622:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 625:	48 89 f2             	mov    rdx,rsi
 628:	48 c1 ea 20          	shr    rdx,0x20
 62c:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 62f:	48 c1 ee 18          	shr    rsi,0x18
 633:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 637:	4c 89 c6             	mov    rsi,r8
 63a:	48 c1 ee 10          	shr    rsi,0x10
 63e:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 642:	44 88 47 00          	mov    BYTE PTR [rdi+0x0],r8b
 646:	49 c1 e8 08          	shr    r8,0x8
 64a:	44 88 47 01          	mov    BYTE PTR [rdi+0x1],r8b
 64e:	b8 02 00 00 00       	mov    eax,0x2
 653:	c9                   	leave
 654:	c3                   	ret
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
   d:	0f 87 d9 04 00 00    	ja     0x4ec
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 cc 04 00 00    	ja     0x4ec
  20:	48 8d b1 0c 02 00 00 	lea    rsi,[rcx+0x20c]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 bc 04 00 00    	ja     0x4ec
  30:	81 79 08 80 00 00 00 	cmp    DWORD PTR [rcx+0x8],0x80
  37:	75 48                	jne    0x81
  39:	55                   	push   rbp
  3a:	41 57                	push   r15
  3c:	41 56                	push   r14
  3e:	41 55                	push   r13
  40:	41 54                	push   r12
  42:	53                   	push   rbx
  43:	31 c0                	xor    eax,eax
  45:	41 bb 2f 00 00 00    	mov    r11d,0x2f
  4b:	bb 22 00 00 00       	mov    ebx,0x22
  50:	41 be 13 00 00 00    	mov    r14d,0x13
  56:	41 bf 31 00 00 00    	mov    r15d,0x31
  5c:	41 bd 02 00 00 00    	mov    r13d,0x2
  62:	bd 0a 00 00 00       	mov    ebp,0xa
  67:	41 bc 0e 00 00 00    	mov    r12d,0xe
  6d:	be 39 00 00 00       	mov    esi,0x39
  72:	bf 38 00 00 00       	mov    edi,0x38
  77:	31 d2                	xor    edx,edx
  79:	41 ba 37 00 00 00    	mov    r10d,0x37
  7f:	eb 32                	jmp    0xb3
  81:	31 c0                	xor    eax,eax
  83:	c3                   	ret
  84:	41 83 f8 02          	cmp    r8d,0x2
  88:	41 b9 1c 00 00 00    	mov    r9d,0x1c
  8e:	4c 0f 44 ce          	cmove  r9,rsi
  92:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  99:	1f 84 00 00 00 00 00 
  a0:	4c 31 ca             	xor    rdx,r9
  a3:	48 83 c0 04          	add    rax,0x4
  a7:	48 3d 00 02 00 00    	cmp    rax,0x200
  ad:	0f 84 12 04 00 00    	je     0x4c5
  b3:	44 8b 44 01 0c       	mov    r8d,DWORD PTR [rcx+rax*1+0xc]
  b8:	49 83 f8 1f          	cmp    r8,0x1f
  bc:	76 42                	jbe    0x100
  be:	41 83 f8 2f          	cmp    r8d,0x2f
  c2:	76 7c                	jbe    0x140
  c4:	41 83 f8 37          	cmp    r8d,0x37
  c8:	0f 86 e8 00 00 00    	jbe    0x1b6
  ce:	41 83 f8 3b          	cmp    r8d,0x3b
  d2:	0f 86 8c 01 00 00    	jbe    0x264
  d8:	41 83 f8 3d          	cmp    r8d,0x3d
  dc:	0f 86 86 02 00 00    	jbe    0x368
  e2:	49 83 f8 3f          	cmp    r8,0x3f
  e6:	41 b9 52 bf 01 00    	mov    r9d,0x1bf52
  ec:	4d 0f 44 ca          	cmove  r9,r10
  f0:	49 83 f8 3e          	cmp    r8,0x3e
  f4:	41 b8 0c 00 00 00    	mov    r8d,0xc
  fa:	4d 0f 44 c8          	cmove  r9,r8
  fe:	eb a0                	jmp    0xa0
 100:	41 83 f8 0f          	cmp    r8d,0xf
 104:	76 7a                	jbe    0x180
 106:	41 83 f8 17          	cmp    r8d,0x17
 10a:	0f 86 d3 00 00 00    	jbe    0x1e3
 110:	41 83 f8 1b          	cmp    r8d,0x1b
 114:	0f 86 6d 01 00 00    	jbe    0x287
 11a:	41 83 f8 1d          	cmp    r8d,0x1d
 11e:	0f 86 5d 02 00 00    	jbe    0x381
 124:	41 83 f8 1e          	cmp    r8d,0x1e
 128:	41 b9 34 00 00 00    	mov    r9d,0x34
 12e:	41 b8 17 00 00 00    	mov    r8d,0x17
 134:	4d 0f 44 c8          	cmove  r9,r8
 138:	e9 63 ff ff ff       	jmp    0xa0
 13d:	0f 1f 00             	nop    DWORD PTR [rax]
 140:	41 83 f8 27          	cmp    r8d,0x27
 144:	0f 86 c6 00 00 00    	jbe    0x210
 14a:	41 83 f8 2b          	cmp    r8d,0x2b
 14e:	0f 86 56 01 00 00    	jbe    0x2aa
 154:	41 83 f8 2d          	cmp    r8d,0x2d
 158:	0f 86 3b 02 00 00    	jbe    0x399
 15e:	45 31 c9             	xor    r9d,r9d
 161:	41 83 f8 2e          	cmp    r8d,0x2e
 165:	41 0f 95 c1          	setne  r9b
 169:	4e 8d 0c cd 33 00 00 	lea    r9,[r9*8+0x33]
 170:	00 
 171:	e9 2a ff ff ff       	jmp    0xa0
 176:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
 17d:	00 00 00 
 180:	41 83 f8 07          	cmp    r8d,0x7
 184:	0f 86 b3 00 00 00    	jbe    0x23d
 18a:	41 83 f8 0b          	cmp    r8d,0xb
 18e:	0f 86 39 01 00 00    	jbe    0x2cd
 194:	41 83 f8 0d          	cmp    r8d,0xd
 198:	0f 86 14 02 00 00    	jbe    0x3b2
 19e:	45 31 c9             	xor    r9d,r9d
 1a1:	41 83 f8 0e          	cmp    r8d,0xe
 1a5:	41 0f 95 c1          	setne  r9b
 1a9:	4f 8d 0c c9          	lea    r9,[r9+r9*8]
 1ad:	49 83 c1 25          	add    r9,0x25
 1b1:	e9 ea fe ff ff       	jmp    0xa0
 1b6:	41 83 f8 33          	cmp    r8d,0x33
 1ba:	0f 86 2a 01 00 00    	jbe    0x2ea
 1c0:	41 83 f8 35          	cmp    r8d,0x35
 1c4:	0f 86 fb 01 00 00    	jbe    0x3c5
 1ca:	41 83 f8 36          	cmp    r8d,0x36
 1ce:	41 b9 12 00 00 00    	mov    r9d,0x12
 1d4:	41 b8 1e 00 00 00    	mov    r8d,0x1e
 1da:	4d 0f 44 c8          	cmove  r9,r8
 1de:	e9 bd fe ff ff       	jmp    0xa0
 1e3:	41 83 f8 13          	cmp    r8d,0x13
 1e7:	0f 86 20 01 00 00    	jbe    0x30d
 1ed:	41 83 f8 15          	cmp    r8d,0x15
 1f1:	0f 86 e7 01 00 00    	jbe    0x3de
 1f7:	41 83 f8 16          	cmp    r8d,0x16
 1fb:	41 b9 28 00 00 00    	mov    r9d,0x28
 201:	41 b8 0f 00 00 00    	mov    r8d,0xf
 207:	4d 0f 44 c8          	cmove  r9,r8
 20b:	e9 90 fe ff ff       	jmp    0xa0
 210:	41 83 f8 23          	cmp    r8d,0x23
 214:	0f 86 10 01 00 00    	jbe    0x32a
 21a:	41 83 f8 25          	cmp    r8d,0x25
 21e:	0f 86 d2 01 00 00    	jbe    0x3f6
 224:	41 83 f8 26          	cmp    r8d,0x26
 228:	41 b9 30 00 00 00    	mov    r9d,0x30
 22e:	41 b8 18 00 00 00    	mov    r8d,0x18
 234:	4d 0f 44 c8          	cmove  r9,r8
 238:	e9 63 fe ff ff       	jmp    0xa0
 23d:	41 83 f8 03          	cmp    r8d,0x3
 241:	0f 86 05 01 00 00    	jbe    0x34c
 247:	41 83 f8 05          	cmp    r8d,0x5
 24b:	0f 86 be 01 00 00    	jbe    0x40f
 251:	41 83 f8 06          	cmp    r8d,0x6
 255:	41 b9 3a 00 00 00    	mov    r9d,0x3a
 25b:	4c 0f 44 cd          	cmove  r9,rbp
 25f:	e9 3c fe ff ff       	jmp    0xa0
 264:	41 83 f8 39          	cmp    r8d,0x39
 268:	0f 86 b4 01 00 00    	jbe    0x422
 26e:	41 83 f8 3a          	cmp    r8d,0x3a
 272:	41 b9 10 00 00 00    	mov    r9d,0x10
 278:	41 b8 16 00 00 00    	mov    r8d,0x16
 27e:	4d 0f 44 c8          	cmove  r9,r8
 282:	e9 19 fe ff ff       	jmp    0xa0
 287:	41 83 f8 19          	cmp    r8d,0x19
 28b:	0f 86 aa 01 00 00    	jbe    0x43b
 291:	41 83 f8 1a          	cmp    r8d,0x1a
 295:	41 b9 29 00 00 00    	mov    r9d,0x29
 29b:	41 b8 11 00 00 00    	mov    r8d,0x11
 2a1:	4d 0f 44 c8          	cmove  r9,r8
 2a5:	e9 f6 fd ff ff       	jmp    0xa0
 2aa:	41 83 f8 29          	cmp    r8d,0x29
 2ae:	0f 86 a0 01 00 00    	jbe    0x454
 2b4:	41 83 f8 2a          	cmp    r8d,0x2a
 2b8:	41 b9 23 00 00 00    	mov    r9d,0x23
 2be:	41 b8 07 00 00 00    	mov    r8d,0x7
 2c4:	4d 0f 44 c8          	cmove  r9,r8
 2c8:	e9 d3 fd ff ff       	jmp    0xa0
 2cd:	41 83 f8 09          	cmp    r8d,0x9
 2d1:	0f 86 96 01 00 00    	jbe    0x46d
 2d7:	41 83 f8 0a          	cmp    r8d,0xa
 2db:	41 b9 24 00 00 00    	mov    r9d,0x24
 2e1:	4d 0f 44 cf          	cmove  r9,r15
 2e5:	e9 b6 fd ff ff       	jmp    0xa0
 2ea:	41 83 f8 31          	cmp    r8d,0x31
 2ee:	0f 86 8c 01 00 00    	jbe    0x480
 2f4:	41 83 f8 32          	cmp    r8d,0x32
 2f8:	41 b9 03 00 00 00    	mov    r9d,0x3
 2fe:	41 b8 09 00 00 00    	mov    r8d,0x9
 304:	4d 0f 44 c8          	cmove  r9,r8
 308:	e9 93 fd ff ff       	jmp    0xa0
 30d:	41 83 f8 11          	cmp    r8d,0x11
 311:	0f 86 82 01 00 00    	jbe    0x499
 317:	41 83 f8 12          	cmp    r8d,0x12
 31b:	41 b9 06 00 00 00    	mov    r9d,0x6
 321:	4d 0f 44 cb          	cmove  r9,r11
 325:	e9 76 fd ff ff       	jmp    0xa0
 32a:	41 83 f8 21          	cmp    r8d,0x21
 32e:	0f 86 78 01 00 00    	jbe    0x4ac
 334:	45 31 c9             	xor    r9d,r9d
 337:	41 83 f8 22          	cmp    r8d,0x22
 33b:	41 0f 95 c1          	setne  r9b
 33f:	41 c1 e1 04          	shl    r9d,0x4
 343:	49 83 c9 0b          	or     r9,0xb
 347:	e9 54 fd ff ff       	jmp    0xa0
 34c:	41 83 f8 01          	cmp    r8d,0x1
 350:	0f 87 2e fd ff ff    	ja     0x84
 356:	4d 85 c0             	test   r8,r8
 359:	41 b9 2b 00 00 00    	mov    r9d,0x2b
 35f:	4c 0f 44 cf          	cmove  r9,rdi
 363:	e9 38 fd ff ff       	jmp    0xa0
 368:	41 83 f8 3c          	cmp    r8d,0x3c
 36c:	41 b9 05 00 00 00    	mov    r9d,0x5
 372:	41 b8 3c 00 00 00    	mov    r8d,0x3c
 378:	4d 0f 44 c8          	cmove  r9,r8
 37c:	e9 1f fd ff ff       	jmp    0xa0
 381:	45 31 c9             	xor    r9d,r9d
 384:	41 83 f8 1c          	cmp    r8d,0x1c
 388:	41 0f 94 c1          	sete   r9b
 38c:	4e 8d 0c 4d 1f 00 00 	lea    r9,[r9*2+0x1f]
 393:	00 
 394:	e9 07 fd ff ff       	jmp    0xa0
 399:	41 83 f8 2c          	cmp    r8d,0x2c
 39d:	41 b9 2c 00 00 00    	mov    r9d,0x2c
 3a3:	41 b8 08 00 00 00    	mov    r8d,0x8
 3a9:	4d 0f 44 c8          	cmove  r9,r8
 3ad:	e9 ee fc ff ff       	jmp    0xa0
 3b2:	41 83 f8 0c          	cmp    r8d,0xc
 3b6:	41 b9 2a 00 00 00    	mov    r9d,0x2a
 3bc:	4d 0f 44 ce          	cmove  r9,r14
 3c0:	e9 db fc ff ff       	jmp    0xa0
 3c5:	41 83 f8 34          	cmp    r8d,0x34
 3c9:	41 b9 14 00 00 00    	mov    r9d,0x14
 3cf:	41 b8 0d 00 00 00    	mov    r8d,0xd
 3d5:	4d 0f 44 c8          	cmove  r9,r8
 3d9:	e9 c2 fc ff ff       	jmp    0xa0
 3de:	45 31 c9             	xor    r9d,r9d
 3e1:	41 83 f8 14          	cmp    r8d,0x14
 3e5:	41 0f 94 c1          	sete   r9b
 3e9:	4e 8d 0c cd 15 00 00 	lea    r9,[r9*8+0x15]
 3f0:	00 
 3f1:	e9 aa fc ff ff       	jmp    0xa0
 3f6:	41 83 f8 24          	cmp    r8d,0x24
 3fa:	41 b9 04 00 00 00    	mov    r9d,0x4
 400:	41 b8 35 00 00 00    	mov    r8d,0x35
 406:	4d 0f 44 c8          	cmove  r9,r8
 40a:	e9 91 fc ff ff       	jmp    0xa0
 40f:	41 83 f8 04          	cmp    r8d,0x4
 413:	41 b9 3d 00 00 00    	mov    r9d,0x3d
 419:	4d 0f 44 cc          	cmove  r9,r12
 41d:	e9 7e fc ff ff       	jmp    0xa0
 422:	41 83 f8 38          	cmp    r8d,0x38
 426:	41 b9 36 00 00 00    	mov    r9d,0x36
 42c:	41 b8 01 00 00 00    	mov    r8d,0x1
 432:	4d 0f 44 c8          	cmove  r9,r8
 436:	e9 65 fc ff ff       	jmp    0xa0
 43b:	41 83 f8 18          	cmp    r8d,0x18
 43f:	41 b9 1a 00 00 00    	mov    r9d,0x1a
 445:	41 b8 26 00 00 00    	mov    r8d,0x26
 44b:	4d 0f 44 c8          	cmove  r9,r8
 44f:	e9 4c fc ff ff       	jmp    0xa0
 454:	41 83 f8 28          	cmp    r8d,0x28
 458:	41 b9 32 00 00 00    	mov    r9d,0x32
 45e:	41 b8 20 00 00 00    	mov    r8d,0x20
 464:	4d 0f 44 c8          	cmove  r9,r8
 468:	e9 33 fc ff ff       	jmp    0xa0
 46d:	41 83 f8 08          	cmp    r8d,0x8
 471:	41 b9 3f 00 00 00    	mov    r9d,0x3f
 477:	4d 0f 44 cd          	cmove  r9,r13
 47b:	e9 20 fc ff ff       	jmp    0xa0
 480:	41 83 f8 30          	cmp    r8d,0x30
 484:	41 b9 00 00 00 00    	mov    r9d,0x0
 48a:	41 b8 2d 00 00 00    	mov    r8d,0x2d
 490:	4d 0f 44 c8          	cmove  r9,r8
 494:	e9 07 fc ff ff       	jmp    0xa0
 499:	41 83 f8 10          	cmp    r8d,0x10
 49d:	41 b9 3e 00 00 00    	mov    r9d,0x3e
 4a3:	4c 0f 44 cb          	cmove  r9,rbx
 4a7:	e9 f4 fb ff ff       	jmp    0xa0
 4ac:	41 83 f8 20          	cmp    r8d,0x20
 4b0:	41 b9 27 00 00 00    	mov    r9d,0x27
 4b6:	41 b8 19 00 00 00    	mov    r8d,0x19
 4bc:	4d 0f 44 c8          	cmove  r9,r8
 4c0:	e9 db fb ff ff       	jmp    0xa0
 4c5:	89 d0                	mov    eax,edx
 4c7:	c1 e8 10             	shr    eax,0x10
 4ca:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
 4ce:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
 4d5:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
 4d8:	88 11                	mov    BYTE PTR [rcx],dl
 4da:	88 71 01             	mov    BYTE PTR [rcx+0x1],dh
 4dd:	b8 02 00 00 00       	mov    eax,0x2
 4e2:	5b                   	pop    rbx
 4e3:	41 5c                	pop    r12
 4e5:	41 5d                	pop    r13
 4e7:	41 5e                	pop    r14
 4e9:	41 5f                	pop    r15
 4eb:	5d                   	pop    rbp
 4ec:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
