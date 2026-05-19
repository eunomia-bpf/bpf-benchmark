# stats_mixed_helpers

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
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	4c 8b 77 00          	mov    r14,QWORD PTR [rdi+0x0]
  24:	4c 89 f7             	mov    rdi,r14
  27:	48 83 c7 08          	add    rdi,0x8
  2b:	48 39 f7             	cmp    rdi,rsi
  2e:	0f 87 2f 01 00 00    	ja     0x163
  34:	e8 43 c8 49 dc       	call   0xffffffffdc49c87c
  39:	48 83 e0 3f          	and    rax,0x3f
  3d:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
  40:	48 c7 c0 34 10 2b 9f 	mov    rax,0xffffffff9f2b1034
  47:	65 48 03 04 25 28 10 	add    rax,QWORD PTR gs:0xffffffff9f2b1028
  4e:	2b 9f 
  50:	8b 40 00             	mov    eax,DWORD PTR [rax+0x0]
  53:	48 83 e0 3f          	and    rax,0x3f
  57:	89 45 f8             	mov    DWORD PTR [rbp-0x8],eax
  5a:	e8 ed c9 49 dc       	call   0xffffffffdc49ca4c
  5f:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  63:	48 89 eb             	mov    rbx,rbp
  66:	48 83 c3 fc          	add    rbx,0xfffffffffffffffc
  6a:	48 89 ea             	mov    rdx,rbp
  6d:	48 83 c2 f0          	add    rdx,0xfffffffffffffff0
  71:	45 31 ff             	xor    r15d,r15d
  74:	48 bf 00 1c 92 00 a8 	movabs rdi,0xffff8ba800921c00
  7b:	8b ff ff 
  7e:	48 89 de             	mov    rsi,rbx
  81:	31 c9                	xor    ecx,ecx
  83:	e8 84 cd 4a dc       	call   0xffffffffdc4ace0c
  88:	bf 01 00 00 00       	mov    edi,0x1
  8d:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  91:	49 89 ed             	mov    r13,rbp
  94:	49 83 c5 f8          	add    r13,0xfffffffffffffff8
  98:	48 89 ea             	mov    rdx,rbp
  9b:	48 83 c2 e8          	add    rdx,0xffffffffffffffe8
  9f:	48 bf 00 34 a7 8e a8 	movabs rdi,0xffff8ba88ea73400
  a6:	8b ff ff 
  a9:	4c 89 ee             	mov    rsi,r13
  ac:	31 c9                	xor    ecx,ecx
  ae:	e8 29 cd 4a dc       	call   0xffffffffdc4acddc
  b3:	48 bf 00 1c 92 00 a8 	movabs rdi,0xffff8ba800921c00
  ba:	8b ff ff 
  bd:	48 89 de             	mov    rsi,rbx
  c0:	e8 47 a4 4a dc       	call   0xffffffffdc4aa50c
  c5:	48 85 c0             	test   rax,rax
  c8:	74 04                	je     0xce
  ca:	48 83 c0 38          	add    rax,0x38
  ce:	48 89 c3             	mov    rbx,rax
  d1:	48 bf 00 34 a7 8e a8 	movabs rdi,0xffff8ba88ea73400
  d8:	8b ff ff 
  db:	4c 89 ee             	mov    rsi,r13
  de:	e8 29 a4 4a dc       	call   0xffffffffdc4aa50c
  e3:	48 85 c0             	test   rax,rax
  e6:	74 11                	je     0xf9
  e8:	48 83 c0 38          	add    rax,0x38
  ec:	48 8b 40 00          	mov    rax,QWORD PTR [rax+0x0]
  f0:	65 48 03 04 25 28 10 	add    rax,QWORD PTR gs:0xffffffff9f2b1028
  f7:	2b 9f 
  f9:	31 ff                	xor    edi,edi
  fb:	48 85 db             	test   rbx,rbx
  fe:	74 04                	je     0x104
 100:	48 8b 7b 00          	mov    rdi,QWORD PTR [rbx+0x0]
 104:	48 85 c0             	test   rax,rax
 107:	74 04                	je     0x10d
 109:	4c 8b 78 00          	mov    r15,QWORD PTR [rax+0x0]
 10d:	49 31 ff             	xor    r15,rdi
 110:	4c 89 ff             	mov    rdi,r15
 113:	48 c1 ef 38          	shr    rdi,0x38
 117:	41 88 7e 07          	mov    BYTE PTR [r14+0x7],dil
 11b:	4c 89 ff             	mov    rdi,r15
 11e:	48 c1 ef 30          	shr    rdi,0x30
 122:	41 88 7e 06          	mov    BYTE PTR [r14+0x6],dil
 126:	4c 89 ff             	mov    rdi,r15
 129:	48 c1 ef 28          	shr    rdi,0x28
 12d:	41 88 7e 05          	mov    BYTE PTR [r14+0x5],dil
 131:	4c 89 ff             	mov    rdi,r15
 134:	48 c1 ef 20          	shr    rdi,0x20
 138:	41 88 7e 04          	mov    BYTE PTR [r14+0x4],dil
 13c:	4c 89 ff             	mov    rdi,r15
 13f:	48 c1 ef 18          	shr    rdi,0x18
 143:	41 88 7e 03          	mov    BYTE PTR [r14+0x3],dil
 147:	4c 89 ff             	mov    rdi,r15
 14a:	48 c1 ef 10          	shr    rdi,0x10
 14e:	41 88 7e 02          	mov    BYTE PTR [r14+0x2],dil
 152:	45 88 7e 00          	mov    BYTE PTR [r14+0x0],r15b
 156:	49 c1 ef 08          	shr    r15,0x8
 15a:	45 88 7e 01          	mov    BYTE PTR [r14+0x1],r15b
 15e:	b8 02 00 00 00       	mov    eax,0x2
 163:	41 5f                	pop    r15
 165:	41 5e                	pop    r14
 167:	41 5d                	pop    r13
 169:	5b                   	pop    rbx
 16a:	c9                   	leave
 16b:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
