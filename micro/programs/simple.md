# simple

## Original C
```c
#include "common.h"

static __always_inline int bench_simple(const u8 *data, u32 len, u64 *out)
{
    (void)data;
    (void)len;
    *out = 12345678ULL;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(simple_xdp, bench_simple, simple_input_value, 64U)
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

0000000000001100 <simple_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	77 2b                	ja     1139 <simple_xdp+0x39>
    110e:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1112:	48 39 d6             	cmp    rsi,rdx
    1115:	77 22                	ja     1139 <simple_xdp+0x39>
    1117:	48 8d 71 48          	lea    rsi,[rcx+0x48]
    111b:	48 39 d6             	cmp    rsi,rdx
    111e:	77 19                	ja     1139 <simple_xdp+0x39>
    1120:	66 c7 01 4e 61       	mov    WORD PTR [rcx],0x614e
    1125:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
    1129:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
    1130:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
    1134:	b8 02 00 00 00       	mov    eax,0x2
    1139:	c3                   	ret

Disassembly of section .fini:

000000000000113c <_fini>:
    113c:	f3 0f 1e fa          	endbr64
    1140:	48 83 ec 08          	sub    rsp,0x8
    1144:	48 83 c4 08          	add    rsp,0x8
    1148:	c3                   	ret
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
  19:	77 4e                	ja     0x69
  1b:	48 89 fa             	mov    rdx,rdi
  1e:	48 83 c2 08          	add    rdx,0x8
  22:	48 39 f2             	cmp    rdx,rsi
  25:	77 42                	ja     0x69
  27:	48 89 fa             	mov    rdx,rdi
  2a:	48 83 c2 48          	add    rdx,0x48
  2e:	48 39 f2             	cmp    rdx,rsi
  31:	77 36                	ja     0x69
  33:	be bc 00 00 00       	mov    esi,0xbc
  38:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
  3c:	be 61 00 00 00       	mov    esi,0x61
  41:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
  45:	be 4e 00 00 00       	mov    esi,0x4e
  4a:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
  4e:	31 f6                	xor    esi,esi
  50:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
  54:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
  58:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
  5c:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
  60:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
  64:	b8 02 00 00 00       	mov    eax,0x2
  69:	c9                   	leave
  6a:	c3                   	ret
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
   d:	77 2b                	ja     0x3a
   f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  13:	48 39 d6             	cmp    rsi,rdx
  16:	77 22                	ja     0x3a
  18:	48 8d 71 48          	lea    rsi,[rcx+0x48]
  1c:	48 39 d6             	cmp    rsi,rdx
  1f:	77 19                	ja     0x3a
  21:	c6 41 02 bc          	mov    BYTE PTR [rcx+0x2],0xbc
  25:	66 c7 01 4e 61       	mov    WORD PTR [rcx],0x614e
  2a:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
  31:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
  35:	b8 02 00 00 00       	mov    eax,0x2
  3a:	c3                   	ret
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
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: ja     113e <simple_xdp+0x3e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (31) - 1, 0),
    /* 0x110e: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1112: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1115: ja     113e <simple_xdp+0x3e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (24) - 1, 0),
    /* 0x1117: lea    rsi,[rcx+0x48] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 72), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111b: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x111e: ja     113e <simple_xdp+0x3e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (17) - 1, 0),
    /* 0x1120: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1121: mov    rbp,rsp [exact-kinsn: movq frame-register kinsn] */
    HC_KINSN(HC_X86_FRAME_PAYLOAD(HC_X86_RBP, HC_X86_RSP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1124: mov    WORD PTR [rcx],0x614e [exact-kinsn: mov immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_IMM_PAYLOAD(HC_X86_RCX, 0, 24910), MICRO_HANDCRAFT_BPF_X86_MOVW),
    /* 0x1129: mov    BYTE PTR [rcx+0x2],0xbc [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_IMM_PAYLOAD(HC_X86_RCX, 2, 188), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x112d: mov    DWORD PTR [rcx+0x3],0x0 [exact-kinsn: mov immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_IMM_PAYLOAD(HC_X86_RCX, 3, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1134: mov    BYTE PTR [rcx+0x7],0x0 [exact-kinsn: movb immediate memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_IMM_PAYLOAD(HC_X86_RCX, 7, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1138: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x113d: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x113e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
