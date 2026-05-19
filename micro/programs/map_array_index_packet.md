# map_array_index_packet

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
  16:	31 c0                	xor    eax,eax
  18:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  1c:	48 8b 5f 00          	mov    rbx,QWORD PTR [rdi+0x0]
  20:	48 89 df             	mov    rdi,rbx
  23:	48 83 c7 20          	add    rdi,0x20
  27:	48 39 f7             	cmp    rdi,rsi
  2a:	0f 87 c8 00 00 00    	ja     0xf8
  30:	45 31 ed             	xor    r13d,r13d
  33:	44 89 6d fc          	mov    DWORD PTR [rbp-0x4],r13d
  37:	48 bf be ba fe ca ef 	movabs rdi,0xdeadbeefcafebabe
  3e:	be ad de 
  41:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  45:	48 89 ee             	mov    rsi,rbp
  48:	48 83 c6 fc          	add    rsi,0xfffffffffffffffc
  4c:	48 89 ea             	mov    rdx,rbp
  4f:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  53:	48 bf 00 b6 8e 02 a9 	movabs rdi,0xffff8ba9028eb600
  5a:	8b ff ff 
  5d:	31 c9                	xor    ecx,ecx
  5f:	e8 d0 fa 4a dc       	call   0xffffffffdc4afb34
  64:	48 0f b6 7b 10       	movzx  rdi,BYTE PTR [rbx+0x10]
  69:	48 83 e7 0f          	and    rdi,0xf
  6d:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
  70:	48 89 ee             	mov    rsi,rbp
  73:	48 83 c6 ec          	add    rsi,0xffffffffffffffec
  77:	48 bf 00 b6 8e 02 a9 	movabs rdi,0xffff8ba9028eb600
  7e:	8b ff ff 
  81:	48 81 c7 30 01 00 00 	add    rdi,0x130
  88:	8b 46 00             	mov    eax,DWORD PTR [rsi+0x0]
  8b:	48 83 f8 10          	cmp    rax,0x10
  8f:	73 09                	jae    0x9a
  91:	48 c1 e0 03          	shl    rax,0x3
  95:	48 01 f8             	add    rax,rdi
  98:	eb 02                	jmp    0x9c
  9a:	31 c0                	xor    eax,eax
  9c:	48 85 c0             	test   rax,rax
  9f:	74 04                	je     0xa5
  a1:	4c 8b 68 00          	mov    r13,QWORD PTR [rax+0x0]
  a5:	4c 89 ef             	mov    rdi,r13
  a8:	48 c1 ef 38          	shr    rdi,0x38
  ac:	40 88 7b 07          	mov    BYTE PTR [rbx+0x7],dil
  b0:	4c 89 ef             	mov    rdi,r13
  b3:	48 c1 ef 30          	shr    rdi,0x30
  b7:	40 88 7b 06          	mov    BYTE PTR [rbx+0x6],dil
  bb:	4c 89 ef             	mov    rdi,r13
  be:	48 c1 ef 28          	shr    rdi,0x28
  c2:	40 88 7b 05          	mov    BYTE PTR [rbx+0x5],dil
  c6:	4c 89 ef             	mov    rdi,r13
  c9:	48 c1 ef 20          	shr    rdi,0x20
  cd:	40 88 7b 04          	mov    BYTE PTR [rbx+0x4],dil
  d1:	4c 89 ef             	mov    rdi,r13
  d4:	48 c1 ef 18          	shr    rdi,0x18
  d8:	40 88 7b 03          	mov    BYTE PTR [rbx+0x3],dil
  dc:	4c 89 ef             	mov    rdi,r13
  df:	48 c1 ef 10          	shr    rdi,0x10
  e3:	40 88 7b 02          	mov    BYTE PTR [rbx+0x2],dil
  e7:	44 88 6b 00          	mov    BYTE PTR [rbx+0x0],r13b
  eb:	49 c1 ed 08          	shr    r13,0x8
  ef:	44 88 6b 01          	mov    BYTE PTR [rbx+0x1],r13b
  f3:	b8 02 00 00 00       	mov    eax,0x2
  f8:	41 5d                	pop    r13
  fa:	5b                   	pop    rbx
  fb:	c9                   	leave
  fc:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
