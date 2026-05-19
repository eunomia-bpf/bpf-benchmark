# map_array_lookup

## Original C
```c
not captured
```

## Native ASM
```asm
not captured
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 10 00 00 00 	sub    rsp,0x10
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	31 c0                	xor    eax,eax
  1a:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  1e:	4c 8b 6f 00          	mov    r13,QWORD PTR [rdi+0x0]
  22:	4c 89 ef             	mov    rdi,r13
  25:	48 83 c7 08          	add    rdi,0x8
  29:	48 39 f7             	cmp    rdi,rsi
  2c:	0f 87 bb 00 00 00    	ja     0xed
  32:	45 31 f6             	xor    r14d,r14d
  35:	44 89 75 fc          	mov    DWORD PTR [rbp-0x4],r14d
  39:	48 bf 01 00 fe ca ef 	movabs rdi,0xdeadbeefcafe0001
  40:	be ad de 
  43:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  47:	48 89 eb             	mov    rbx,rbp
  4a:	48 83 c3 fc          	add    rbx,0xfffffffffffffffc
  4e:	48 89 ea             	mov    rdx,rbp
  51:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  55:	48 bf 00 ce fa 01 a8 	movabs rdi,0xffff8ba801face00
  5c:	8b ff ff 
  5f:	48 89 de             	mov    rsi,rbx
  62:	31 c9                	xor    ecx,ecx
  64:	e8 47 fc 4a dc       	call   0xffffffffdc4afcb0
  69:	48 bf 00 ce fa 01 a8 	movabs rdi,0xffff8ba801face00
  70:	8b ff ff 
  73:	48 89 de             	mov    rsi,rbx
  76:	48 81 c7 30 01 00 00 	add    rdi,0x130
  7d:	8b 46 00             	mov    eax,DWORD PTR [rsi+0x0]
  80:	48 83 f8 04          	cmp    rax,0x4
  84:	73 09                	jae    0x8f
  86:	48 c1 e0 03          	shl    rax,0x3
  8a:	48 01 f8             	add    rax,rdi
  8d:	eb 02                	jmp    0x91
  8f:	31 c0                	xor    eax,eax
  91:	48 85 c0             	test   rax,rax
  94:	74 04                	je     0x9a
  96:	4c 8b 70 00          	mov    r14,QWORD PTR [rax+0x0]
  9a:	4c 89 f7             	mov    rdi,r14
  9d:	48 c1 ef 38          	shr    rdi,0x38
  a1:	41 88 7d 07          	mov    BYTE PTR [r13+0x7],dil
  a5:	4c 89 f7             	mov    rdi,r14
  a8:	48 c1 ef 30          	shr    rdi,0x30
  ac:	41 88 7d 06          	mov    BYTE PTR [r13+0x6],dil
  b0:	4c 89 f7             	mov    rdi,r14
  b3:	48 c1 ef 28          	shr    rdi,0x28
  b7:	41 88 7d 05          	mov    BYTE PTR [r13+0x5],dil
  bb:	4c 89 f7             	mov    rdi,r14
  be:	48 c1 ef 20          	shr    rdi,0x20
  c2:	41 88 7d 04          	mov    BYTE PTR [r13+0x4],dil
  c6:	4c 89 f7             	mov    rdi,r14
  c9:	48 c1 ef 18          	shr    rdi,0x18
  cd:	41 88 7d 03          	mov    BYTE PTR [r13+0x3],dil
  d1:	4c 89 f7             	mov    rdi,r14
  d4:	48 c1 ef 10          	shr    rdi,0x10
  d8:	41 88 7d 02          	mov    BYTE PTR [r13+0x2],dil
  dc:	45 88 75 00          	mov    BYTE PTR [r13+0x0],r14b
  e0:	49 c1 ee 08          	shr    r14,0x8
  e4:	45 88 75 01          	mov    BYTE PTR [r13+0x1],r14b
  e8:	b8 02 00 00 00       	mov    eax,0x2
  ed:	41 5e                	pop    r14
  ef:	41 5d                	pop    r13
  f1:	5b                   	pop    rbx
  f2:	c9                   	leave
  f3:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
