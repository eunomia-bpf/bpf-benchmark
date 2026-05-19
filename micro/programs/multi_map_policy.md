# multi_map_policy

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
   c:	48 81 ec 28 00 00 00 	sub    rsp,0x28
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	4c 8b 7f 00          	mov    r15,QWORD PTR [rdi+0x0]
  24:	4c 89 ff             	mov    rdi,r15
  27:	48 83 c7 08          	add    rdi,0x8
  2b:	48 39 f7             	cmp    rdi,rsi
  2e:	0f 87 82 01 00 00    	ja     0x1b6
  34:	bf 03 00 00 00       	mov    edi,0x3
  39:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
  3c:	48 bf 11 00 ff ee dd 	movabs rdi,0xaabbccddeeff0011
  43:	cc bb aa 
  46:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  4a:	49 89 ed             	mov    r13,rbp
  4d:	49 83 c5 fc          	add    r13,0xfffffffffffffffc
  51:	49 89 ee             	mov    r14,rbp
  54:	49 83 c6 f0          	add    r14,0xfffffffffffffff0
  58:	31 db                	xor    ebx,ebx
  5a:	48 bf 00 c4 fa 01 a8 	movabs rdi,0xffff8ba801fac400
  61:	8b ff ff 
  64:	4c 89 ee             	mov    rsi,r13
  67:	4c 89 f2             	mov    rdx,r14
  6a:	31 c9                	xor    ecx,ecx
  6c:	e8 83 f9 4a dc       	call   0xffffffffdc4af9f4
  71:	48 bf 78 56 34 12 78 	movabs rdi,0x1234567812345678
  78:	56 34 12 
  7b:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  7f:	48 89 ea             	mov    rdx,rbp
  82:	48 83 c2 e8          	add    rdx,0xffffffffffffffe8
  86:	48 bf 00 08 92 00 a8 	movabs rdi,0xffff8ba800920800
  8d:	8b ff ff 
  90:	4c 89 f6             	mov    rsi,r14
  93:	31 c9                	xor    ecx,ecx
  95:	e8 fa cc 4a dc       	call   0xffffffffdc4acd94
  9a:	89 5d e4             	mov    DWORD PTR [rbp-0x1c],ebx
  9d:	48 89 5d d8          	mov    QWORD PTR [rbp-0x28],rbx
  a1:	48 89 ee             	mov    rsi,rbp
  a4:	48 83 c6 e4          	add    rsi,0xffffffffffffffe4
  a8:	48 89 ea             	mov    rdx,rbp
  ab:	48 83 c2 d8          	add    rdx,0xffffffffffffffd8
  af:	48 bf 00 a8 8e 02 a9 	movabs rdi,0xffff8ba9028ea800
  b6:	8b ff ff 
  b9:	31 c9                	xor    ecx,ecx
  bb:	e8 34 f9 4a dc       	call   0xffffffffdc4af9f4
  c0:	48 bf 00 c4 fa 01 a8 	movabs rdi,0xffff8ba801fac400
  c7:	8b ff ff 
  ca:	4c 89 ee             	mov    rsi,r13
  cd:	48 81 c7 30 01 00 00 	add    rdi,0x130
  d4:	8b 46 00             	mov    eax,DWORD PTR [rsi+0x0]
  d7:	48 83 f8 10          	cmp    rax,0x10
  db:	73 09                	jae    0xe6
  dd:	48 c1 e0 03          	shl    rax,0x3
  e1:	48 01 f8             	add    rax,rdi
  e4:	eb 02                	jmp    0xe8
  e6:	31 c0                	xor    eax,eax
  e8:	48 85 c0             	test   rax,rax
  eb:	74 1e                	je     0x10b
  ed:	48 bf 00 08 92 00 a8 	movabs rdi,0xffff8ba800920800
  f4:	8b ff ff 
  f7:	48 89 c6             	mov    rsi,rax
  fa:	e8 95 a3 4a dc       	call   0xffffffffdc4aa494
  ff:	48 85 c0             	test   rax,rax
 102:	74 04                	je     0x108
 104:	48 83 c0 38          	add    rax,0x38
 108:	48 89 c3             	mov    rbx,rax
 10b:	48 89 ee             	mov    rsi,rbp
 10e:	48 83 c6 e4          	add    rsi,0xffffffffffffffe4
 112:	48 bf 00 a8 8e 02 a9 	movabs rdi,0xffff8ba9028ea800
 119:	8b ff ff 
 11c:	48 81 c7 30 01 00 00 	add    rdi,0x130
 123:	8b 46 00             	mov    eax,DWORD PTR [rsi+0x0]
 126:	48 83 f8 08          	cmp    rax,0x8
 12a:	73 16                	jae    0x142
 12c:	48 c1 e0 03          	shl    rax,0x3
 130:	48 01 f8             	add    rax,rdi
 133:	48 8b 40 00          	mov    rax,QWORD PTR [rax+0x0]
 137:	65 48 03 04 25 28 10 	add    rax,QWORD PTR gs:0xffffffff9f2b1028
 13e:	2b 9f 
 140:	eb 02                	jmp    0x144
 142:	31 c0                	xor    eax,eax
 144:	48 85 c0             	test   rax,rax
 147:	74 0f                	je     0x158
 149:	48 85 db             	test   rbx,rbx
 14c:	74 0a                	je     0x158
 14e:	48 8b 7b 00          	mov    rdi,QWORD PTR [rbx+0x0]
 152:	48 89 78 00          	mov    QWORD PTR [rax+0x0],rdi
 156:	eb 0b                	jmp    0x163
 158:	31 ff                	xor    edi,edi
 15a:	48 85 c0             	test   rax,rax
 15d:	74 04                	je     0x163
 15f:	48 8b 78 00          	mov    rdi,QWORD PTR [rax+0x0]
 163:	48 89 fe             	mov    rsi,rdi
 166:	48 c1 ee 38          	shr    rsi,0x38
 16a:	41 88 77 07          	mov    BYTE PTR [r15+0x7],sil
 16e:	48 89 fe             	mov    rsi,rdi
 171:	48 c1 ee 30          	shr    rsi,0x30
 175:	41 88 77 06          	mov    BYTE PTR [r15+0x6],sil
 179:	48 89 fe             	mov    rsi,rdi
 17c:	48 c1 ee 28          	shr    rsi,0x28
 180:	41 88 77 05          	mov    BYTE PTR [r15+0x5],sil
 184:	48 89 fe             	mov    rsi,rdi
 187:	48 c1 ee 20          	shr    rsi,0x20
 18b:	41 88 77 04          	mov    BYTE PTR [r15+0x4],sil
 18f:	48 89 fe             	mov    rsi,rdi
 192:	48 c1 ee 18          	shr    rsi,0x18
 196:	41 88 77 03          	mov    BYTE PTR [r15+0x3],sil
 19a:	48 89 fe             	mov    rsi,rdi
 19d:	48 c1 ee 10          	shr    rsi,0x10
 1a1:	41 88 77 02          	mov    BYTE PTR [r15+0x2],sil
 1a5:	41 88 7f 00          	mov    BYTE PTR [r15+0x0],dil
 1a9:	48 c1 ef 08          	shr    rdi,0x8
 1ad:	41 88 7f 01          	mov    BYTE PTR [r15+0x1],dil
 1b1:	b8 02 00 00 00       	mov    eax,0x2
 1b6:	41 5f                	pop    r15
 1b8:	41 5e                	pop    r14
 1ba:	41 5d                	pop    r13
 1bc:	5b                   	pop    rbx
 1bd:	c9                   	leave
 1be:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
