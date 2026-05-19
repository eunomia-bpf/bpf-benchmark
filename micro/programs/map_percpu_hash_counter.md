# map_percpu_hash_counter

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
  2c:	0f 87 bd 00 00 00    	ja     0xef
  32:	bf 07 00 00 00       	mov    edi,0x7
  37:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
  3a:	45 31 f6             	xor    r14d,r14d
  3d:	4c 89 75 f0          	mov    QWORD PTR [rbp-0x10],r14
  41:	48 89 eb             	mov    rbx,rbp
  44:	48 83 c3 fc          	add    rbx,0xfffffffffffffffc
  48:	48 89 ea             	mov    rdx,rbp
  4b:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  4f:	48 bf 00 70 92 00 a8 	movabs rdi,0xffff8ba800927000
  56:	8b ff ff 
  59:	48 89 de             	mov    rsi,rbx
  5c:	31 c9                	xor    ecx,ecx
  5e:	e8 81 ce 4a dc       	call   0xffffffffdc4acee4
  63:	48 bf 00 70 92 00 a8 	movabs rdi,0xffff8ba800927000
  6a:	8b ff ff 
  6d:	48 89 de             	mov    rsi,rbx
  70:	e8 9f a5 4a dc       	call   0xffffffffdc4aa614
  75:	48 85 c0             	test   rax,rax
  78:	74 11                	je     0x8b
  7a:	48 83 c0 38          	add    rax,0x38
  7e:	48 8b 40 00          	mov    rax,QWORD PTR [rax+0x0]
  82:	65 48 03 04 25 28 10 	add    rax,QWORD PTR gs:0xffffffff9f2b1028
  89:	2b 9f 
  8b:	48 85 c0             	test   rax,rax
  8e:	74 0c                	je     0x9c
  90:	4c 8b 70 00          	mov    r14,QWORD PTR [rax+0x0]
  94:	49 83 c6 01          	add    r14,0x1
  98:	4c 89 70 00          	mov    QWORD PTR [rax+0x0],r14
  9c:	4c 89 f7             	mov    rdi,r14
  9f:	48 c1 ef 38          	shr    rdi,0x38
  a3:	41 88 7d 07          	mov    BYTE PTR [r13+0x7],dil
  a7:	4c 89 f7             	mov    rdi,r14
  aa:	48 c1 ef 30          	shr    rdi,0x30
  ae:	41 88 7d 06          	mov    BYTE PTR [r13+0x6],dil
  b2:	4c 89 f7             	mov    rdi,r14
  b5:	48 c1 ef 28          	shr    rdi,0x28
  b9:	41 88 7d 05          	mov    BYTE PTR [r13+0x5],dil
  bd:	4c 89 f7             	mov    rdi,r14
  c0:	48 c1 ef 20          	shr    rdi,0x20
  c4:	41 88 7d 04          	mov    BYTE PTR [r13+0x4],dil
  c8:	4c 89 f7             	mov    rdi,r14
  cb:	48 c1 ef 18          	shr    rdi,0x18
  cf:	41 88 7d 03          	mov    BYTE PTR [r13+0x3],dil
  d3:	4c 89 f7             	mov    rdi,r14
  d6:	48 c1 ef 10          	shr    rdi,0x10
  da:	41 88 7d 02          	mov    BYTE PTR [r13+0x2],dil
  de:	45 88 75 00          	mov    BYTE PTR [r13+0x0],r14b
  e2:	49 c1 ee 08          	shr    r14,0x8
  e6:	45 88 75 01          	mov    BYTE PTR [r13+0x1],r14b
  ea:	b8 02 00 00 00       	mov    eax,0x2
  ef:	41 5e                	pop    r14
  f1:	41 5d                	pop    r13
  f3:	5b                   	pop    rbx
  f4:	c9                   	leave
  f5:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
