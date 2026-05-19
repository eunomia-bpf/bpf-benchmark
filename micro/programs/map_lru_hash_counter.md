# map_lru_hash_counter

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
  2c:	0f 87 d0 00 00 00    	ja     0x102
  32:	bf 2a 00 00 00       	mov    edi,0x2a
  37:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
  3a:	48 89 eb             	mov    rbx,rbp
  3d:	48 83 c3 fc          	add    rbx,0xfffffffffffffffc
  41:	48 bf 00 2c 22 08 a8 	movabs rdi,0xffff8ba808222c00
  48:	8b ff ff 
  4b:	48 89 de             	mov    rsi,rbx
  4e:	e8 c1 c5 4a dc       	call   0xffffffffdc4ac614
  53:	45 31 f6             	xor    r14d,r14d
  56:	4c 89 75 f0          	mov    QWORD PTR [rbp-0x10],r14
  5a:	48 89 ea             	mov    rdx,rbp
  5d:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  61:	48 bf 00 2c 22 08 a8 	movabs rdi,0xffff8ba808222c00
  68:	8b ff ff 
  6b:	48 89 de             	mov    rsi,rbx
  6e:	31 c9                	xor    ecx,ecx
  70:	e8 9f c8 4a dc       	call   0xffffffffdc4ac914
  75:	48 bf 00 2c 22 08 a8 	movabs rdi,0xffff8ba808222c00
  7c:	8b ff ff 
  7f:	48 89 de             	mov    rsi,rbx
  82:	e8 3d a5 4a dc       	call   0xffffffffdc4aa5c4
  87:	48 85 c0             	test   rax,rax
  8a:	74 12                	je     0x9e
  8c:	48 0f b6 78 23       	movzx  rdi,BYTE PTR [rax+0x23]
  91:	48 85 ff             	test   rdi,rdi
  94:	75 04                	jne    0x9a
  96:	c6 40 23 01          	mov    BYTE PTR [rax+0x23],0x1
  9a:	48 83 c0 38          	add    rax,0x38
  9e:	48 85 c0             	test   rax,rax
  a1:	74 0c                	je     0xaf
  a3:	4c 8b 70 00          	mov    r14,QWORD PTR [rax+0x0]
  a7:	49 83 c6 01          	add    r14,0x1
  ab:	4c 89 70 00          	mov    QWORD PTR [rax+0x0],r14
  af:	4c 89 f7             	mov    rdi,r14
  b2:	48 c1 ef 38          	shr    rdi,0x38
  b6:	41 88 7d 07          	mov    BYTE PTR [r13+0x7],dil
  ba:	4c 89 f7             	mov    rdi,r14
  bd:	48 c1 ef 30          	shr    rdi,0x30
  c1:	41 88 7d 06          	mov    BYTE PTR [r13+0x6],dil
  c5:	4c 89 f7             	mov    rdi,r14
  c8:	48 c1 ef 28          	shr    rdi,0x28
  cc:	41 88 7d 05          	mov    BYTE PTR [r13+0x5],dil
  d0:	4c 89 f7             	mov    rdi,r14
  d3:	48 c1 ef 20          	shr    rdi,0x20
  d7:	41 88 7d 04          	mov    BYTE PTR [r13+0x4],dil
  db:	4c 89 f7             	mov    rdi,r14
  de:	48 c1 ef 18          	shr    rdi,0x18
  e2:	41 88 7d 03          	mov    BYTE PTR [r13+0x3],dil
  e6:	4c 89 f7             	mov    rdi,r14
  e9:	48 c1 ef 10          	shr    rdi,0x10
  ed:	41 88 7d 02          	mov    BYTE PTR [r13+0x2],dil
  f1:	45 88 75 00          	mov    BYTE PTR [r13+0x0],r14b
  f5:	49 c1 ee 08          	shr    r14,0x8
  f9:	45 88 75 01          	mov    BYTE PTR [r13+0x1],r14b
  fd:	b8 02 00 00 00       	mov    eax,0x2
 102:	41 5e                	pop    r14
 104:	41 5d                	pop    r13
 106:	5b                   	pop    rbx
 107:	c9                   	leave
 108:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
