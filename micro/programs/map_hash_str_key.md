# map_hash_str_key

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
   c:	48 81 ec 18 00 00 00 	sub    rsp,0x18
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	31 c0                	xor    eax,eax
  1a:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  1e:	4c 8b 6f 00          	mov    r13,QWORD PTR [rdi+0x0]
  22:	4c 89 ef             	mov    rdi,r13
  25:	48 83 c7 08          	add    rdi,0x8
  29:	48 39 f7             	cmp    rdi,rsi
  2c:	0f 87 c6 00 00 00    	ja     0xf8
  32:	48 bf 68 2d 6b 65 79 	movabs rdi,0x30302d79656b2d68
  39:	2d 30 30 
  3c:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  40:	48 bf 62 70 66 2d 62 	movabs rdi,0x636e65622d667062
  47:	65 6e 63 
  4a:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  4e:	48 bf ef be ad de ce 	movabs rdi,0xfeedfacedeadbeef
  55:	fa ed fe 
  58:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  5c:	48 89 eb             	mov    rbx,rbp
  5f:	48 83 c3 f0          	add    rbx,0xfffffffffffffff0
  63:	48 89 ea             	mov    rdx,rbp
  66:	48 83 c2 e8          	add    rdx,0xffffffffffffffe8
  6a:	45 31 f6             	xor    r14d,r14d
  6d:	48 bf 00 a0 1f 06 a8 	movabs rdi,0xffff8ba8061fa000
  74:	8b ff ff 
  77:	48 89 de             	mov    rsi,rbx
  7a:	31 c9                	xor    ecx,ecx
  7c:	e8 f3 cd 4a dc       	call   0xffffffffdc4ace74
  81:	48 bf 00 a0 1f 06 a8 	movabs rdi,0xffff8ba8061fa000
  88:	8b ff ff 
  8b:	48 89 de             	mov    rsi,rbx
  8e:	e8 e1 a4 4a dc       	call   0xffffffffdc4aa574
  93:	48 85 c0             	test   rax,rax
  96:	74 04                	je     0x9c
  98:	48 83 c0 40          	add    rax,0x40
  9c:	48 85 c0             	test   rax,rax
  9f:	74 04                	je     0xa5
  a1:	4c 8b 70 00          	mov    r14,QWORD PTR [rax+0x0]
  a5:	4c 89 f7             	mov    rdi,r14
  a8:	48 c1 ef 38          	shr    rdi,0x38
  ac:	41 88 7d 07          	mov    BYTE PTR [r13+0x7],dil
  b0:	4c 89 f7             	mov    rdi,r14
  b3:	48 c1 ef 30          	shr    rdi,0x30
  b7:	41 88 7d 06          	mov    BYTE PTR [r13+0x6],dil
  bb:	4c 89 f7             	mov    rdi,r14
  be:	48 c1 ef 28          	shr    rdi,0x28
  c2:	41 88 7d 05          	mov    BYTE PTR [r13+0x5],dil
  c6:	4c 89 f7             	mov    rdi,r14
  c9:	48 c1 ef 20          	shr    rdi,0x20
  cd:	41 88 7d 04          	mov    BYTE PTR [r13+0x4],dil
  d1:	4c 89 f7             	mov    rdi,r14
  d4:	48 c1 ef 18          	shr    rdi,0x18
  d8:	41 88 7d 03          	mov    BYTE PTR [r13+0x3],dil
  dc:	4c 89 f7             	mov    rdi,r14
  df:	48 c1 ef 10          	shr    rdi,0x10
  e3:	41 88 7d 02          	mov    BYTE PTR [r13+0x2],dil
  e7:	45 88 75 00          	mov    BYTE PTR [r13+0x0],r14b
  eb:	49 c1 ee 08          	shr    r14,0x8
  ef:	45 88 75 01          	mov    BYTE PTR [r13+0x1],r14b
  f3:	b8 02 00 00 00       	mov    eax,0x2
  f8:	41 5e                	pop    r14
  fa:	41 5d                	pop    r13
  fc:	5b                   	pop    rbx
  fd:	c9                   	leave
  fe:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
