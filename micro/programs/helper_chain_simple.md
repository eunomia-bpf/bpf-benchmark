# helper_chain_simple

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
  2c:	0f 87 c2 00 00 00    	ja     0xf4
  32:	45 31 f6             	xor    r14d,r14d
  35:	44 89 75 fc          	mov    DWORD PTR [rbp-0x4],r14d
  39:	e8 b2 ca 49 dc       	call   0xffffffffdc49caf0
  3e:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  42:	48 89 eb             	mov    rbx,rbp
  45:	48 83 c3 fc          	add    rbx,0xfffffffffffffffc
  49:	48 89 ea             	mov    rdx,rbp
  4c:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  50:	48 bf 00 18 92 00 a8 	movabs rdi,0xffff8ba800921800
  57:	8b ff ff 
  5a:	48 89 de             	mov    rsi,rbx
  5d:	31 c9                	xor    ecx,ecx
  5f:	e8 4c ce 4a dc       	call   0xffffffffdc4aceb0
  64:	48 bf 00 18 92 00 a8 	movabs rdi,0xffff8ba800921800
  6b:	8b ff ff 
  6e:	48 89 de             	mov    rsi,rbx
  71:	e8 3a a5 4a dc       	call   0xffffffffdc4aa5b0
  76:	48 85 c0             	test   rax,rax
  79:	74 04                	je     0x7f
  7b:	48 83 c0 38          	add    rax,0x38
  7f:	48 85 c0             	test   rax,rax
  82:	74 04                	je     0x88
  84:	4c 8b 70 00          	mov    r14,QWORD PTR [rax+0x0]
  88:	48 89 ee             	mov    rsi,rbp
  8b:	48 83 c6 fc          	add    rsi,0xfffffffffffffffc
  8f:	48 bf 00 18 92 00 a8 	movabs rdi,0xffff8ba800921800
  96:	8b ff ff 
  99:	e8 d2 c3 4a dc       	call   0xffffffffdc4ac470
  9e:	4c 89 f7             	mov    rdi,r14
  a1:	48 c1 ef 38          	shr    rdi,0x38
  a5:	41 88 7d 07          	mov    BYTE PTR [r13+0x7],dil
  a9:	4c 89 f7             	mov    rdi,r14
  ac:	48 c1 ef 30          	shr    rdi,0x30
  b0:	41 88 7d 06          	mov    BYTE PTR [r13+0x6],dil
  b4:	4c 89 f7             	mov    rdi,r14
  b7:	48 c1 ef 28          	shr    rdi,0x28
  bb:	41 88 7d 05          	mov    BYTE PTR [r13+0x5],dil
  bf:	4c 89 f7             	mov    rdi,r14
  c2:	48 c1 ef 20          	shr    rdi,0x20
  c6:	41 88 7d 04          	mov    BYTE PTR [r13+0x4],dil
  ca:	4c 89 f7             	mov    rdi,r14
  cd:	48 c1 ef 18          	shr    rdi,0x18
  d1:	41 88 7d 03          	mov    BYTE PTR [r13+0x3],dil
  d5:	4c 89 f7             	mov    rdi,r14
  d8:	48 c1 ef 10          	shr    rdi,0x10
  dc:	41 88 7d 02          	mov    BYTE PTR [r13+0x2],dil
  e0:	4c 89 f7             	mov    rdi,r14
  e3:	48 c1 ef 08          	shr    rdi,0x8
  e7:	41 88 7d 01          	mov    BYTE PTR [r13+0x1],dil
  eb:	45 88 75 00          	mov    BYTE PTR [r13+0x0],r14b
  ef:	b8 02 00 00 00       	mov    eax,0x2
  f4:	41 5e                	pop    r14
  f6:	41 5d                	pop    r13
  f8:	5b                   	pop    rbx
  f9:	c9                   	leave
  fa:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
