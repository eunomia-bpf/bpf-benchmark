# combined_helper_map

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
  2c:	0f 87 d5 00 00 00    	ja     0x107
  32:	48 c7 c0 34 10 2b 9f 	mov    rax,0xffffffff9f2b1034
  39:	65 48 03 04 25 28 10 	add    rax,QWORD PTR gs:0xffffffff9f2b1028
  40:	2b 9f 
  42:	8b 40 00             	mov    eax,DWORD PTR [rax+0x0]
  45:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
  48:	e8 ab ca 49 dc       	call   0xffffffffdc49caf8
  4d:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  51:	48 89 eb             	mov    rbx,rbp
  54:	48 83 c3 fc          	add    rbx,0xfffffffffffffffc
  58:	48 89 ea             	mov    rdx,rbp
  5b:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  5f:	45 31 f6             	xor    r14d,r14d
  62:	48 bf 00 94 1f 06 a8 	movabs rdi,0xffff8ba8061f9400
  69:	8b ff ff 
  6c:	48 89 de             	mov    rsi,rbx
  6f:	31 c9                	xor    ecx,ecx
  71:	e8 a2 fa 4a dc       	call   0xffffffffdc4afb18
  76:	48 bf 00 94 1f 06 a8 	movabs rdi,0xffff8ba8061f9400
  7d:	8b ff ff 
  80:	48 89 de             	mov    rsi,rbx
  83:	48 81 c7 30 01 00 00 	add    rdi,0x130
  8a:	8b 46 00             	mov    eax,DWORD PTR [rsi+0x0]
  8d:	48 83 f8 40          	cmp    rax,0x40
  91:	73 16                	jae    0xa9
  93:	48 c1 e0 03          	shl    rax,0x3
  97:	48 01 f8             	add    rax,rdi
  9a:	48 8b 40 00          	mov    rax,QWORD PTR [rax+0x0]
  9e:	65 48 03 04 25 28 10 	add    rax,QWORD PTR gs:0xffffffff9f2b1028
  a5:	2b 9f 
  a7:	eb 02                	jmp    0xab
  a9:	31 c0                	xor    eax,eax
  ab:	48 85 c0             	test   rax,rax
  ae:	74 04                	je     0xb4
  b0:	4c 8b 70 00          	mov    r14,QWORD PTR [rax+0x0]
  b4:	4c 89 f7             	mov    rdi,r14
  b7:	48 c1 ef 38          	shr    rdi,0x38
  bb:	41 88 7d 07          	mov    BYTE PTR [r13+0x7],dil
  bf:	4c 89 f7             	mov    rdi,r14
  c2:	48 c1 ef 30          	shr    rdi,0x30
  c6:	41 88 7d 06          	mov    BYTE PTR [r13+0x6],dil
  ca:	4c 89 f7             	mov    rdi,r14
  cd:	48 c1 ef 28          	shr    rdi,0x28
  d1:	41 88 7d 05          	mov    BYTE PTR [r13+0x5],dil
  d5:	4c 89 f7             	mov    rdi,r14
  d8:	48 c1 ef 20          	shr    rdi,0x20
  dc:	41 88 7d 04          	mov    BYTE PTR [r13+0x4],dil
  e0:	4c 89 f7             	mov    rdi,r14
  e3:	48 c1 ef 18          	shr    rdi,0x18
  e7:	41 88 7d 03          	mov    BYTE PTR [r13+0x3],dil
  eb:	4c 89 f7             	mov    rdi,r14
  ee:	48 c1 ef 10          	shr    rdi,0x10
  f2:	41 88 7d 02          	mov    BYTE PTR [r13+0x2],dil
  f6:	45 88 75 00          	mov    BYTE PTR [r13+0x0],r14b
  fa:	49 c1 ee 08          	shr    r14,0x8
  fe:	45 88 75 01          	mov    BYTE PTR [r13+0x1],r14b
 102:	b8 02 00 00 00       	mov    eax,0x2
 107:	41 5e                	pop    r14
 109:	41 5d                	pop    r13
 10b:	5b                   	pop    rbx
 10c:	c9                   	leave
 10d:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
