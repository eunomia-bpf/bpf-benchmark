# packet_5tuple_classify

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
  25:	48 83 c7 20          	add    rdi,0x20
  29:	48 39 f7             	cmp    rdi,rsi
  2c:	0f 87 b6 00 00 00    	ja     0xe8
  32:	45 31 f6             	xor    r14d,r14d
  35:	44 89 75 fc          	mov    DWORD PTR [rbp-0x4],r14d
  39:	41 8b 7d 10          	mov    edi,DWORD PTR [r13+0x10]
  3d:	89 7d f0             	mov    DWORD PTR [rbp-0x10],edi
  40:	41 8b 7d 14          	mov    edi,DWORD PTR [r13+0x14]
  44:	89 7d f4             	mov    DWORD PTR [rbp-0xc],edi
  47:	49 0f b7 7d 18       	movzx  rdi,WORD PTR [r13+0x18]
  4c:	66 89 7d f8          	mov    WORD PTR [rbp-0x8],di
  50:	49 0f b7 7d 1a       	movzx  rdi,WORD PTR [r13+0x1a]
  55:	66 89 7d fa          	mov    WORD PTR [rbp-0x6],di
  59:	49 0f b6 7d 1c       	movzx  rdi,BYTE PTR [r13+0x1c]
  5e:	40 88 7d fc          	mov    BYTE PTR [rbp-0x4],dil
  62:	bf be ba fe ca       	mov    edi,0xcafebabe
  67:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
  6a:	48 89 eb             	mov    rbx,rbp
  6d:	48 83 c3 f0          	add    rbx,0xfffffffffffffff0
  71:	48 89 ea             	mov    rdx,rbp
  74:	48 83 c2 ec          	add    rdx,0xffffffffffffffec
  78:	48 bf 00 6c 22 08 a8 	movabs rdi,0xffff8ba808226c00
  7f:	8b ff ff 
  82:	48 89 de             	mov    rsi,rbx
  85:	31 c9                	xor    ecx,ecx
  87:	e8 40 ce 4a dc       	call   0xffffffffdc4acecc
  8c:	48 bf 00 6c 22 08 a8 	movabs rdi,0xffff8ba808226c00
  93:	8b ff ff 
  96:	48 89 de             	mov    rsi,rbx
  99:	e8 2e a5 4a dc       	call   0xffffffffdc4aa5cc
  9e:	48 85 c0             	test   rax,rax
  a1:	74 04                	je     0xa7
  a3:	48 83 c0 40          	add    rax,0x40
  a7:	31 ff                	xor    edi,edi
  a9:	48 85 c0             	test   rax,rax
  ac:	74 03                	je     0xb1
  ae:	8b 78 00             	mov    edi,DWORD PTR [rax+0x0]
  b1:	45 88 75 07          	mov    BYTE PTR [r13+0x7],r14b
  b5:	45 88 75 06          	mov    BYTE PTR [r13+0x6],r14b
  b9:	45 88 75 05          	mov    BYTE PTR [r13+0x5],r14b
  bd:	45 88 75 04          	mov    BYTE PTR [r13+0x4],r14b
  c1:	48 89 fe             	mov    rsi,rdi
  c4:	48 c1 ee 18          	shr    rsi,0x18
  c8:	41 88 75 03          	mov    BYTE PTR [r13+0x3],sil
  cc:	48 89 fe             	mov    rsi,rdi
  cf:	48 c1 ee 10          	shr    rsi,0x10
  d3:	41 88 75 02          	mov    BYTE PTR [r13+0x2],sil
  d7:	41 88 7d 00          	mov    BYTE PTR [r13+0x0],dil
  db:	48 c1 ef 08          	shr    rdi,0x8
  df:	41 88 7d 01          	mov    BYTE PTR [r13+0x1],dil
  e3:	b8 02 00 00 00       	mov    eax,0x2
  e8:	41 5e                	pop    r14
  ea:	41 5d                	pop    r13
  ec:	5b                   	pop    rbx
  ed:	c9                   	leave
  ee:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
