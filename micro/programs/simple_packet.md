# simple_packet

## Original C
```c
#include "common.h"

static __always_inline int bench_simple_packet(const u8 *data, u32 len, u64 *out)
{
    (void)data;
    (void)len;
    *out = 12345678ULL;
    return 0;
}

DEFINE_PACKET_BACKED_XDP_BENCH(simple_packet_xdp, bench_simple_packet)
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

0000000000001100 <simple_packet_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	77 22                	ja     1130 <simple_packet_xdp+0x30>
    110e:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1112:	48 39 d6             	cmp    rsi,rdx
    1115:	77 19                	ja     1130 <simple_packet_xdp+0x30>
    1117:	66 c7 01 4e 61       	mov    WORD PTR [rcx],0x614e
    111c:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
    1120:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
    1127:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
    112b:	b8 02 00 00 00       	mov    eax,0x2
    1130:	c3                   	ret

Disassembly of section .fini:

0000000000001134 <_fini>:
    1134:	f3 0f 1e fa          	endbr64
    1138:	48 83 ec 08          	sub    rsp,0x8
    113c:	48 83 c4 08          	add    rsp,0x8
    1140:	c3                   	ret
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
   e:	48 8b 77 00          	mov    rsi,QWORD PTR [rdi+0x0]
  12:	48 8b 7f 08          	mov    rdi,QWORD PTR [rdi+0x8]
  16:	48 39 fe             	cmp    rsi,rdi
  19:	77 42                	ja     0x5d
  1b:	48 89 f2             	mov    rdx,rsi
  1e:	48 83 c2 08          	add    rdx,0x8
  22:	48 39 fa             	cmp    rdx,rdi
  25:	77 36                	ja     0x5d
  27:	bf bc 00 00 00       	mov    edi,0xbc
  2c:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
  30:	bf 61 00 00 00       	mov    edi,0x61
  35:	40 88 7e 01          	mov    BYTE PTR [rsi+0x1],dil
  39:	bf 4e 00 00 00       	mov    edi,0x4e
  3e:	40 88 7e 00          	mov    BYTE PTR [rsi+0x0],dil
  42:	31 ff                	xor    edi,edi
  44:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
  48:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
  4c:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
  50:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
  54:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
  58:	b8 02 00 00 00       	mov    eax,0x2
  5d:	c9                   	leave
  5e:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
