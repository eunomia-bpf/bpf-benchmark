# bitmap_popcount_scan

## Original C
```c
#include "common.h"

#ifdef MICRO_NATIVE
#pragma clang attribute push (__attribute__((target("popcnt"))), apply_to = function)
#endif

#define BITCOUNT_MAX_COUNT 256U
#define BITCOUNT_INPUT_SIZE (8U + BITCOUNT_MAX_COUNT * 8U)

static __always_inline u64 micro_popcount64(u64 value)
{
    return (u64)__builtin_popcountll(value);
}

static __always_inline int bench_bitmap_popcount_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);

    if (count != BITCOUNT_MAX_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, BITCOUNT_MAX_COUNT * 8U)) {
        return -1;
    }

    u64 acc = seed;
    for (u32 i = 0; i < BITCOUNT_MAX_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8);
        acc += micro_popcount64(value ^ acc);
        acc ^= value >> (i & 7);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(bitmap_popcount_scan_xdp, bench_bitmap_popcount_scan, bitmap_popcount_scan_input_value, BITCOUNT_INPUT_SIZE)

#ifdef MICRO_NATIVE
#pragma clang attribute pop
#endif
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

0000000000001100 <bitmap_popcount_scan_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <bitmap_popcount_scan_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <bitmap_popcount_scan_xdp+0xe>
    1118:	48 8d ba 10 08 00 00 	lea    rdi,[rdx+0x810]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <bitmap_popcount_scan_xdp+0xe>
    1124:	81 3e 00 01 00 00    	cmp    DWORD PTR [rsi],0x100
    112a:	75 e2                	jne    110e <bitmap_popcount_scan_xdp+0xe>
    112c:	8b 4a 0c             	mov    ecx,DWORD PTR [rdx+0xc]
    112f:	31 c0                	xor    eax,eax
    1131:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1138:	0f 1f 84 00 00 00 00 
    113f:	00 
    1140:	48 8b 74 c2 10       	mov    rsi,QWORD PTR [rdx+rax*8+0x10]
    1145:	48 89 f7             	mov    rdi,rsi
    1148:	48 31 cf             	xor    rdi,rcx
    114b:	f3 48 0f b8 ff       	popcnt rdi,rdi
    1150:	48 01 cf             	add    rdi,rcx
    1153:	89 c1                	mov    ecx,eax
    1155:	80 e1 07             	and    cl,0x7
    1158:	48 d3 ee             	shr    rsi,cl
    115b:	48 89 f1             	mov    rcx,rsi
    115e:	48 31 f9             	xor    rcx,rdi
    1161:	48 ff c0             	inc    rax
    1164:	48 3d 00 01 00 00    	cmp    rax,0x100
    116a:	75 d4                	jne    1140 <bitmap_popcount_scan_xdp+0x40>
    116c:	48 89 0a             	mov    QWORD PTR [rdx],rcx
    116f:	b8 02 00 00 00       	mov    eax,0x2
    1174:	c3                   	ret

Disassembly of section .fini:

0000000000001178 <_fini>:
    1178:	f3 0f 1e fa          	endbr64
    117c:	48 83 ec 08          	sub    rsp,0x8
    1180:	48 83 c4 08          	add    rsp,0x8
    1184:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	53                   	push   rbx
   d:	41 55                	push   r13
   f:	41 56                	push   r14
  11:	41 57                	push   r15
  13:	31 c0                	xor    eax,eax
  15:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  19:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  1d:	48 39 f7             	cmp    rdi,rsi
  20:	0f 87 ba 01 00 00    	ja     0x1e0
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 aa 01 00 00    	ja     0x1e0
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 10 08 00 00 	add    rdx,0x810
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 97 01 00 00    	ja     0x1e0
  49:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4e:	c1 e6 08             	shl    esi,0x8
  51:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  56:	09 d6                	or     esi,edx
  58:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  5d:	c1 e2 10             	shl    edx,0x10
  60:	09 d6                	or     esi,edx
  62:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  67:	c1 e2 18             	shl    edx,0x18
  6a:	09 d6                	or     esi,edx
  6c:	81 fe 00 01 00 00    	cmp    esi,0x100
  72:	0f 85 68 01 00 00    	jne    0x1e0
  78:	48 0f b6 57 0c       	movzx  rdx,BYTE PTR [rdi+0xc]
  7d:	48 0f b6 77 0d       	movzx  rsi,BYTE PTR [rdi+0xd]
  82:	48 c1 e6 08          	shl    rsi,0x8
  86:	48 09 d6             	or     rsi,rdx
  89:	48 0f b6 57 0e       	movzx  rdx,BYTE PTR [rdi+0xe]
  8e:	48 c1 e2 10          	shl    rdx,0x10
  92:	48 09 d6             	or     rsi,rdx
  95:	48 0f b6 57 0f       	movzx  rdx,BYTE PTR [rdi+0xf]
  9a:	48 c1 e2 18          	shl    rdx,0x18
  9e:	48 09 d6             	or     rsi,rdx
  a1:	31 d2                	xor    edx,edx
  a3:	48 89 f9             	mov    rcx,rdi
  a6:	48 83 c1 17          	add    rcx,0x17
  aa:	48 b8 33 33 33 33 33 	movabs rax,0x3333333333333333
  b1:	33 33 33 
  b4:	49 bd 01 01 01 01 01 	movabs r13,0x101010101010101
  bb:	01 01 01 
  be:	48 bb 55 55 55 55 55 	movabs rbx,0x5555555555555555
  c5:	55 55 55 
  c8:	4c 0f b6 71 fd       	movzx  r14,BYTE PTR [rcx-0x3]
  cd:	49 c1 e6 20          	shl    r14,0x20
  d1:	4c 0f b6 41 fb       	movzx  r8,BYTE PTR [rcx-0x5]
  d6:	49 c1 e0 10          	shl    r8,0x10
  da:	4d 09 f0             	or     r8,r14
  dd:	4c 0f b6 71 fc       	movzx  r14,BYTE PTR [rcx-0x4]
  e2:	49 c1 e6 18          	shl    r14,0x18
  e6:	4c 0f b6 79 fa       	movzx  r15,BYTE PTR [rcx-0x6]
  eb:	49 c1 e7 08          	shl    r15,0x8
  ef:	4d 09 f7             	or     r15,r14
  f2:	4d 09 c7             	or     r15,r8
  f5:	4c 0f b6 41 fe       	movzx  r8,BYTE PTR [rcx-0x2]
  fa:	49 c1 e0 28          	shl    r8,0x28
  fe:	4d 09 c7             	or     r15,r8
 101:	4c 0f b6 41 00       	movzx  r8,BYTE PTR [rcx+0x0]
 106:	49 c1 e0 38          	shl    r8,0x38
 10a:	4c 0f b6 71 ff       	movzx  r14,BYTE PTR [rcx-0x1]
 10f:	49 c1 e6 30          	shl    r14,0x30
 113:	4d 09 c6             	or     r14,r8
 116:	4d 09 f7             	or     r15,r14
 119:	4c 0f b6 41 f9       	movzx  r8,BYTE PTR [rcx-0x7]
 11e:	4d 09 c7             	or     r15,r8
 121:	4d 89 f8             	mov    r8,r15
 124:	49 31 f0             	xor    r8,rsi
 127:	4d 89 c6             	mov    r14,r8
 12a:	49 d1 ee             	shr    r14,1
 12d:	49 21 de             	and    r14,rbx
 130:	4d 29 f0             	sub    r8,r14
 133:	4d 89 c6             	mov    r14,r8
 136:	49 21 c6             	and    r14,rax
 139:	49 c1 e8 02          	shr    r8,0x2
 13d:	49 21 c0             	and    r8,rax
 140:	4d 01 c6             	add    r14,r8
 143:	49 89 d0             	mov    r8,rdx
 146:	49 83 e0 07          	and    r8,0x7
 14a:	c4 42 bb f7 ff       	shrx   r15,r15,r8
 14f:	4d 89 f0             	mov    r8,r14
 152:	49 c1 e8 04          	shr    r8,0x4
 156:	4d 01 c6             	add    r14,r8
 159:	49 b8 0f 0f 0f 0f 0f 	movabs r8,0xf0f0f0f0f0f0f0f
 160:	0f 0f 0f 
 163:	4d 21 c6             	and    r14,r8
 166:	4d 0f af f5          	imul   r14,r13
 16a:	49 c1 ee 38          	shr    r14,0x38
 16e:	49 01 f6             	add    r14,rsi
 171:	4d 31 fe             	xor    r14,r15
 174:	48 83 c1 08          	add    rcx,0x8
 178:	48 83 c2 01          	add    rdx,0x1
 17c:	4c 89 f6             	mov    rsi,r14
 17f:	48 81 fa 00 01 00 00 	cmp    rdx,0x100
 186:	74 05                	je     0x18d
 188:	e9 3b ff ff ff       	jmp    0xc8
 18d:	44 88 77 00          	mov    BYTE PTR [rdi+0x0],r14b
 191:	4c 89 f6             	mov    rsi,r14
 194:	48 c1 ee 38          	shr    rsi,0x38
 198:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 19c:	4c 89 f6             	mov    rsi,r14
 19f:	48 c1 ee 30          	shr    rsi,0x30
 1a3:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 1a7:	4c 89 f6             	mov    rsi,r14
 1aa:	48 c1 ee 28          	shr    rsi,0x28
 1ae:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 1b2:	4c 89 f6             	mov    rsi,r14
 1b5:	48 c1 ee 20          	shr    rsi,0x20
 1b9:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 1bd:	4c 89 f6             	mov    rsi,r14
 1c0:	48 c1 ee 18          	shr    rsi,0x18
 1c4:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 1c8:	4c 89 f6             	mov    rsi,r14
 1cb:	48 c1 ee 10          	shr    rsi,0x10
 1cf:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 1d3:	49 c1 ee 08          	shr    r14,0x8
 1d7:	44 88 77 01          	mov    BYTE PTR [rdi+0x1],r14b
 1db:	b8 02 00 00 00       	mov    eax,0x2
 1e0:	41 5f                	pop    r15
 1e2:	41 5e                	pop    r14
 1e4:	41 5d                	pop    r13
 1e6:	5b                   	pop    rbx
 1e7:	c9                   	leave
 1e8:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
