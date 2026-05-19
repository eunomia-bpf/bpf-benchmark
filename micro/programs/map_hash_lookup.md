# map_hash_lookup

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
  2c:	0f 87 b2 00 00 00    	ja     0xe4
  32:	bf 07 00 00 00       	mov    edi,0x7
  37:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
  3a:	48 bf 88 77 66 55 44 	movabs rdi,0x1122334455667788
  41:	33 22 11 
  44:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  48:	48 89 eb             	mov    rbx,rbp
  4b:	48 83 c3 fc          	add    rbx,0xfffffffffffffffc
  4f:	48 89 ea             	mov    rdx,rbp
  52:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  56:	45 31 f6             	xor    r14d,r14d
  59:	48 bf 00 98 1f 06 a8 	movabs rdi,0xffff8ba8061f9800
  60:	8b ff ff 
  63:	48 89 de             	mov    rsi,rbx
  66:	31 c9                	xor    ecx,ecx
  68:	e8 4b ce 4a dc       	call   0xffffffffdc4aceb8
  6d:	48 bf 00 98 1f 06 a8 	movabs rdi,0xffff8ba8061f9800
  74:	8b ff ff 
  77:	48 89 de             	mov    rsi,rbx
  7a:	e8 39 a5 4a dc       	call   0xffffffffdc4aa5b8
  7f:	48 85 c0             	test   rax,rax
  82:	74 04                	je     0x88
  84:	48 83 c0 38          	add    rax,0x38
  88:	48 85 c0             	test   rax,rax
  8b:	74 04                	je     0x91
  8d:	4c 8b 70 00          	mov    r14,QWORD PTR [rax+0x0]
  91:	4c 89 f7             	mov    rdi,r14
  94:	48 c1 ef 38          	shr    rdi,0x38
  98:	41 88 7d 07          	mov    BYTE PTR [r13+0x7],dil
  9c:	4c 89 f7             	mov    rdi,r14
  9f:	48 c1 ef 30          	shr    rdi,0x30
  a3:	41 88 7d 06          	mov    BYTE PTR [r13+0x6],dil
  a7:	4c 89 f7             	mov    rdi,r14
  aa:	48 c1 ef 28          	shr    rdi,0x28
  ae:	41 88 7d 05          	mov    BYTE PTR [r13+0x5],dil
  b2:	4c 89 f7             	mov    rdi,r14
  b5:	48 c1 ef 20          	shr    rdi,0x20
  b9:	41 88 7d 04          	mov    BYTE PTR [r13+0x4],dil
  bd:	4c 89 f7             	mov    rdi,r14
  c0:	48 c1 ef 18          	shr    rdi,0x18
  c4:	41 88 7d 03          	mov    BYTE PTR [r13+0x3],dil
  c8:	4c 89 f7             	mov    rdi,r14
  cb:	48 c1 ef 10          	shr    rdi,0x10
  cf:	41 88 7d 02          	mov    BYTE PTR [r13+0x2],dil
  d3:	45 88 75 00          	mov    BYTE PTR [r13+0x0],r14b
  d7:	49 c1 ee 08          	shr    r14,0x8
  db:	45 88 75 01          	mov    BYTE PTR [r13+0x1],r14b
  df:	b8 02 00 00 00       	mov    eax,0x2
  e4:	41 5e                	pop    r14
  e6:	41 5d                	pop    r13
  e8:	5b                   	pop    rbx
  e9:	c9                   	leave
  ea:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
