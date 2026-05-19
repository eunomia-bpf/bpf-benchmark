# map_percpu_array

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
  18:	41 57                	push   r15
  1a:	31 db                	xor    ebx,ebx
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	4c 8b 77 00          	mov    r14,QWORD PTR [rdi+0x0]
  24:	4c 89 f7             	mov    rdi,r14
  27:	48 83 c7 08          	add    rdi,0x8
  2b:	48 39 f7             	cmp    rdi,rsi
  2e:	0f 87 c7 00 00 00    	ja     0xfb
  34:	bb 02 00 00 00       	mov    ebx,0x2
  39:	89 5d fc             	mov    DWORD PTR [rbp-0x4],ebx
  3c:	48 bf be ba fe ca ce 	movabs rdi,0xfeedfacecafebabe
  43:	fa ed fe 
  46:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  4a:	49 89 ed             	mov    r13,rbp
  4d:	49 83 c5 fc          	add    r13,0xfffffffffffffffc
  51:	48 89 ea             	mov    rdx,rbp
  54:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  58:	45 31 ff             	xor    r15d,r15d
  5b:	48 bf 00 be eb 85 a8 	movabs rdi,0xffff8ba885ebbe00
  62:	8b ff ff 
  65:	4c 89 ee             	mov    rsi,r13
  68:	31 c9                	xor    ecx,ecx
  6a:	e8 e9 fa 4a dc       	call   0xffffffffdc4afb58
  6f:	48 bf 00 be eb 85 a8 	movabs rdi,0xffff8ba885ebbe00
  76:	8b ff ff 
  79:	4c 89 ee             	mov    rsi,r13
  7c:	48 81 c7 30 01 00 00 	add    rdi,0x130
  83:	8b 46 00             	mov    eax,DWORD PTR [rsi+0x0]
  86:	48 83 f8 04          	cmp    rax,0x4
  8a:	73 16                	jae    0xa2
  8c:	48 c1 e0 03          	shl    rax,0x3
  90:	48 01 f8             	add    rax,rdi
  93:	48 8b 40 00          	mov    rax,QWORD PTR [rax+0x0]
  97:	65 48 03 04 25 28 10 	add    rax,QWORD PTR gs:0xffffffff9f2b1028
  9e:	2b 9f 
  a0:	eb 02                	jmp    0xa4
  a2:	31 c0                	xor    eax,eax
  a4:	48 85 c0             	test   rax,rax
  a7:	74 04                	je     0xad
  a9:	4c 8b 78 00          	mov    r15,QWORD PTR [rax+0x0]
  ad:	4c 89 ff             	mov    rdi,r15
  b0:	48 c1 ef 38          	shr    rdi,0x38
  b4:	41 88 7e 07          	mov    BYTE PTR [r14+0x7],dil
  b8:	4c 89 ff             	mov    rdi,r15
  bb:	48 c1 ef 30          	shr    rdi,0x30
  bf:	41 88 7e 06          	mov    BYTE PTR [r14+0x6],dil
  c3:	4c 89 ff             	mov    rdi,r15
  c6:	48 c1 ef 28          	shr    rdi,0x28
  ca:	41 88 7e 05          	mov    BYTE PTR [r14+0x5],dil
  ce:	4c 89 ff             	mov    rdi,r15
  d1:	48 c1 ef 20          	shr    rdi,0x20
  d5:	41 88 7e 04          	mov    BYTE PTR [r14+0x4],dil
  d9:	4c 89 ff             	mov    rdi,r15
  dc:	48 c1 ef 18          	shr    rdi,0x18
  e0:	41 88 7e 03          	mov    BYTE PTR [r14+0x3],dil
  e4:	4c 89 ff             	mov    rdi,r15
  e7:	48 c1 ef 10          	shr    rdi,0x10
  eb:	41 88 7e 02          	mov    BYTE PTR [r14+0x2],dil
  ef:	45 88 7e 00          	mov    BYTE PTR [r14+0x0],r15b
  f3:	49 c1 ef 08          	shr    r15,0x8
  f7:	45 88 7e 01          	mov    BYTE PTR [r14+0x1],r15b
  fb:	48 89 d8             	mov    rax,rbx
  fe:	41 5f                	pop    r15
 100:	41 5e                	pop    r14
 102:	41 5d                	pop    r13
 104:	5b                   	pop    rbx
 105:	c9                   	leave
 106:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
