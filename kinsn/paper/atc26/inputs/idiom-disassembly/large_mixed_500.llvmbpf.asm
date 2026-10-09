
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/large_mixed_500.llvmbpf.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   6:	8b 57 04             	mov    edx,DWORD PTR [rdi+0x4]
   9:	89 d6                	mov    esi,edx
   b:	89 c8                	mov    eax,ecx
   d:	39 d1                	cmp    ecx,edx
   f:	0f 97 c1             	seta   cl
  12:	48 8d 50 08          	lea    rdx,[rax+0x8]
  16:	48 39 f2             	cmp    rdx,rsi
  19:	0f 97 c2             	seta   dl
  1c:	08 ca                	or     dl,cl
  1e:	48 8d 88 10 01 00 00 	lea    rcx,[rax+0x110]
  25:	48 39 f1             	cmp    rcx,rsi
  28:	0f 97 c1             	seta   cl
  2b:	08 d1                	or     cl,dl
  2d:	0f 85 44 03 00 00    	jne    0x377
  33:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
  37:	0f 85 3a 03 00 00    	jne    0x377
  3d:	55                   	push   rbp
  3e:	41 57                	push   r15
  40:	41 56                	push   r14
  42:	41 55                	push   r13
  44:	41 54                	push   r12
  46:	53                   	push   rbx
  47:	0f b6 48 0d          	movzx  ecx,BYTE PTR [rax+0xd]
  4b:	48 c1 e1 25          	shl    rcx,0x25
  4f:	0f b6 50 0c          	movzx  edx,BYTE PTR [rax+0xc]
  53:	48 c1 e2 1d          	shl    rdx,0x1d
  57:	48 09 ca             	or     rdx,rcx
  5a:	0f b6 48 0e          	movzx  ecx,BYTE PTR [rax+0xe]
  5e:	48 c1 e1 2d          	shl    rcx,0x2d
  62:	48 09 d1             	or     rcx,rdx
  65:	0f b6 50 0f          	movzx  edx,BYTE PTR [rax+0xf]
  69:	48 c1 e2 35          	shl    rdx,0x35
  6d:	48 09 ca             	or     rdx,rcx
  70:	49 bc 2f 64 bd 78 64 	movabs r12,0xa0761d6478bd642f
  77:	1d 76 a0 
  7a:	49 31 d4             	xor    r12,rdx
  7d:	b9 38 00 00 00       	mov    ecx,0x38
  82:	31 d2                	xor    edx,edx
  84:	49 ba 69 6c 74 7c 9f 	movabs r10,0x1715609f7c746c69
  8b:	60 15 17 
  8e:	49 bb 7e e8 be fb 58 	movabs r11,0xb54cda58fbbee87e
  95:	da 4c b5 
  98:	48 bb 93 64 09 7b 12 	movabs rbx,0x538454127b096493
  9f:	54 84 53 
  a2:	45 31 f6             	xor    r14d,r14d
  a5:	45 31 ff             	xor    r15d,r15d
  a8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
  af:	00 
  b0:	0f b6 74 08 dc       	movzx  esi,BYTE PTR [rax+rcx*1-0x24]
  b5:	48 c1 e6 20          	shl    rsi,0x20
  b9:	0f b6 7c 08 da       	movzx  edi,BYTE PTR [rax+rcx*1-0x26]
  be:	c1 e7 10             	shl    edi,0x10
  c1:	48 09 f7             	or     rdi,rsi
  c4:	0f b6 74 08 db       	movzx  esi,BYTE PTR [rax+rcx*1-0x25]
  c9:	c1 e6 18             	shl    esi,0x18
  cc:	48 09 fe             	or     rsi,rdi
  cf:	0f b6 7c 08 d9       	movzx  edi,BYTE PTR [rax+rcx*1-0x27]
  d4:	c1 e7 08             	shl    edi,0x8
  d7:	48 09 f7             	or     rdi,rsi
  da:	0f b6 74 08 dd       	movzx  esi,BYTE PTR [rax+rcx*1-0x23]
  df:	48 c1 e6 28          	shl    rsi,0x28
  e3:	48 09 fe             	or     rsi,rdi
  e6:	0f b6 7c 08 df       	movzx  edi,BYTE PTR [rax+rcx*1-0x21]
  eb:	48 c1 e7 38          	shl    rdi,0x38
  ef:	48 09 f7             	or     rdi,rsi
  f2:	0f b6 74 08 de       	movzx  esi,BYTE PTR [rax+rcx*1-0x22]
  f7:	48 c1 e6 30          	shl    rsi,0x30
  fb:	48 09 fe             	or     rsi,rdi
  fe:	0f b6 6c 08 d8       	movzx  ebp,BYTE PTR [rax+rcx*1-0x28]
 103:	49 89 f5             	mov    r13,rsi
 106:	49 09 ed             	or     r13,rbp
 109:	44 89 f7             	mov    edi,r14d
 10c:	40 80 e7 07          	and    dil,0x7
 110:	c4 c2 c1 f7 fe       	shlx   rdi,r14,rdi
 115:	4c 31 e7             	xor    rdi,r12
 118:	4c 31 ef             	xor    rdi,r13
 11b:	4c 01 ef             	add    rdi,r13
 11e:	4c 31 ef             	xor    rdi,r13
 121:	4d 8d 04 3e          	lea    r8,[r14+rdi*1]
 125:	4d 31 e0             	xor    r8,r12
 128:	49 01 fc             	add    r12,rdi
 12b:	40 f6 c7 01          	test   dil,0x1
 12f:	4d 0f 44 e0          	cmove  r12,r8
 133:	4f 8d 04 24          	lea    r8,[r12+r12*1]
 137:	4d 89 e1             	mov    r9,r12
 13a:	49 83 e1 fe          	and    r9,0xfffffffffffffffe
 13e:	4d 31 c1             	xor    r9,r8
 141:	49 c1 ec 3f          	shr    r12,0x3f
 145:	4d 09 cc             	or     r12,r9
 148:	4d 89 e8             	mov    r8,r13
 14b:	49 b9 15 7c 4a 7f b9 	movabs r9,0x9e3779b97f4a7c15
 152:	79 37 9e 
 155:	4d 31 c8             	xor    r8,r9
 158:	49 01 f8             	add    r8,rdi
 15b:	8d b9 d0 00 00 00    	lea    edi,[rcx+0xd0]
 161:	81 e7 f8 00 00 00    	and    edi,0xf8
 167:	4c 33 44 07 10       	xor    r8,QWORD PTR [rdi+rax*1+0x10]
 16c:	4b 8d 3c 06          	lea    rdi,[r14+r8*1]
 170:	4c 31 e7             	xor    rdi,r12
 173:	41 f6 c0 02          	test   r8b,0x2
 177:	4f 8d 8c 20 00 00 08 	lea    r9,[r8+r12*1+0x80000]
 17e:	00 
 17f:	4c 0f 44 cf          	cmove  r9,rdi
 183:	4c 89 ef             	mov    rdi,r13
 186:	49 bc 2a f8 94 fe 72 	movabs r12,0x3c6ef372fe94f82a
 18d:	f3 6e 3c 
 190:	4c 31 e7             	xor    rdi,r12
 193:	4c 01 c7             	add    rdi,r8
 196:	44 8d 81 d8 00 00 00 	lea    r8d,[rcx+0xd8]
 19d:	41 81 e0 f8 00 00 00 	and    r8d,0xf8
 1a4:	49 33 7c 00 10       	xor    rdi,QWORD PTR [r8+rax*1+0x10]
 1a9:	4d 89 c8             	mov    r8,r9
 1ac:	49 d1 e8             	shr    r8,1
 1af:	4d 31 c8             	xor    r8,r9
 1b2:	c4 43 fb f0 c0 3e    	rorx   r8,r8,0x3e
 1b8:	4d 8d 0c 3e          	lea    r9,[r14+rdi*1]
 1bc:	4d 31 c1             	xor    r9,r8
 1bf:	40 f6 c7 04          	test   dil,0x4
 1c3:	4d 8d 84 38 00 00 10 	lea    r8,[r8+rdi*1+0x100000]
 1ca:	00 
 1cb:	4d 0f 44 c1          	cmove  r8,r9
 1cf:	4d 89 e9             	mov    r9,r13
 1d2:	49 bc 3f 74 df 7d 2c 	movabs r12,0xdaa66d2c7ddf743f
 1d9:	6d a6 da 
 1dc:	4d 31 e1             	xor    r9,r12
 1df:	49 01 f9             	add    r9,rdi
 1e2:	8d b9 e0 00 00 00    	lea    edi,[rcx+0xe0]
 1e8:	81 e7 f8 00 00 00    	and    edi,0xf8
 1ee:	4c 33 4c 07 10       	xor    r9,QWORD PTR [rdi+rax*1+0x10]
 1f3:	4c 89 c7             	mov    rdi,r8
 1f6:	48 c1 ef 02          	shr    rdi,0x2
 1fa:	4c 31 c7             	xor    rdi,r8
 1fd:	c4 e3 fb f0 ff 3d    	rorx   rdi,rdi,0x3d
 203:	4f 8d 04 0e          	lea    r8,[r14+r9*1]
 207:	49 31 f8             	xor    r8,rdi
 20a:	41 f6 c1 08          	test   r9b,0x8
 20e:	4e 8d a4 0f 00 00 18 	lea    r12,[rdi+r9*1+0x180000]
 215:	00 
 216:	4d 0f 44 e0          	cmove  r12,r8
 21a:	4c 89 ef             	mov    rdi,r13
 21d:	49 b8 54 f0 29 fd e5 	movabs r8,0x78dde6e5fd29f054
 224:	e6 dd 78 
 227:	4c 31 c7             	xor    rdi,r8
 22a:	4c 01 cf             	add    rdi,r9
 22d:	44 8d 81 e8 00 00 00 	lea    r8d,[rcx+0xe8]
 234:	41 81 e0 f8 00 00 00 	and    r8d,0xf8
 23b:	49 33 7c 00 10       	xor    rdi,QWORD PTR [r8+rax*1+0x10]
 240:	4d 89 e0             	mov    r8,r12
 243:	49 c1 e8 02          	shr    r8,0x2
 247:	4d 31 e0             	xor    r8,r12
 24a:	c4 43 fb f0 c0 3c    	rorx   r8,r8,0x3c
 250:	4d 8d 0c 3f          	lea    r9,[r15+rdi*1]
 254:	4d 31 c1             	xor    r9,r8
 257:	40 f6 c7 10          	test   dil,0x10
 25b:	4d 8d 84 38 00 00 20 	lea    r8,[r8+rdi*1+0x200000]
 262:	00 
 263:	4d 0f 44 c1          	cmove  r8,r9
 267:	4d 89 c1             	mov    r9,r8
 26a:	49 c1 e9 03          	shr    r9,0x3
 26e:	4d 31 c1             	xor    r9,r8
 271:	4d 89 e8             	mov    r8,r13
 274:	4d 31 d0             	xor    r8,r10
 277:	49 01 f8             	add    r8,rdi
 27a:	8d b9 f0 00 00 00    	lea    edi,[rcx+0xf0]
 280:	81 e7 f8 00 00 00    	and    edi,0xf8
 286:	c4 43 fb f0 c9 3b    	rorx   r9,r9,0x3b
 28c:	4c 33 44 07 10       	xor    r8,QWORD PTR [rdi+rax*1+0x10]
 291:	4b 8d 3c 07          	lea    rdi,[r15+r8*1]
 295:	4c 31 cf             	xor    rdi,r9
 298:	41 f6 c0 20          	test   r8b,0x20
 29c:	4f 8d 8c 01 00 00 28 	lea    r9,[r9+r8*1+0x280000]
 2a3:	00 
 2a4:	4c 0f 44 cf          	cmove  r9,rdi
 2a8:	4c 89 cf             	mov    rdi,r9
 2ab:	48 c1 ef 03          	shr    rdi,0x3
 2af:	4c 31 cf             	xor    rdi,r9
 2b2:	4d 89 e9             	mov    r9,r13
 2b5:	4d 31 d9             	xor    r9,r11
 2b8:	4d 01 c1             	add    r9,r8
 2bb:	44 8d 81 f8 00 00 00 	lea    r8d,[rcx+0xf8]
 2c2:	41 81 e0 f8 00 00 00 	and    r8d,0xf8
 2c9:	4d 33 4c 00 10       	xor    r9,QWORD PTR [r8+rax*1+0x10]
 2ce:	c4 e3 fb f0 ff 3a    	rorx   rdi,rdi,0x3a
 2d4:	4f 8d 04 0f          	lea    r8,[r15+r9*1]
 2d8:	49 31 f8             	xor    r8,rdi
 2db:	41 f6 c1 40          	test   r9b,0x40
 2df:	4a 8d bc 0f 00 00 30 	lea    rdi,[rdi+r9*1+0x300000]
 2e6:	00 
 2e7:	49 0f 44 f8          	cmove  rdi,r8
 2eb:	49 31 dd             	xor    r13,rbx
 2ee:	4d 01 cd             	add    r13,r9
 2f1:	41 89 c8             	mov    r8d,ecx
 2f4:	41 81 e0 f8 00 00 00 	and    r8d,0xf8
 2fb:	4d 33 6c 00 10       	xor    r13,QWORD PTR [r8+rax*1+0x10]
 300:	49 89 f8             	mov    r8,rdi
 303:	49 c1 e8 04          	shr    r8,0x4
 307:	49 31 f8             	xor    r8,rdi
 30a:	c4 c3 fb f0 f8 39    	rorx   rdi,r8,0x39
 310:	4f 8d 04 2f          	lea    r8,[r15+r13*1]
 314:	49 31 f8             	xor    r8,rdi
 317:	45 84 ed             	test   r13b,r13b
 31a:	4a 8d bc 2f 00 00 38 	lea    rdi,[rdi+r13*1+0x380000]
 321:	00 
 322:	49 0f 49 f8          	cmovns rdi,r8
 326:	49 89 f8             	mov    r8,rdi
 329:	49 c1 e8 04          	shr    r8,0x4
 32d:	49 31 f8             	xor    r8,rdi
 330:	48 01 ee             	add    rsi,rbp
 333:	48 01 d6             	add    rsi,rdx
 336:	4c 01 ee             	add    rsi,r13
 339:	c4 c3 fb f0 f8 38    	rorx   rdi,r8,0x38
 33f:	49 89 f4             	mov    r12,rsi
 342:	49 31 fc             	xor    r12,rdi
 345:	49 ff c6             	inc    r14
 348:	48 81 c2 00 08 00 00 	add    rdx,0x800
 34f:	49 83 c7 02          	add    r15,0x2
 353:	48 83 c1 08          	add    rcx,0x8
 357:	48 81 f9 38 01 00 00 	cmp    rcx,0x138
 35e:	0f 85 4c fd ff ff    	jne    0xb0
 364:	4c 89 20             	mov    QWORD PTR [rax],r12
 367:	b8 02 00 00 00       	mov    eax,0x2
 36c:	5b                   	pop    rbx
 36d:	41 5c                	pop    r12
 36f:	41 5d                	pop    r13
 371:	41 5e                	pop    r14
 373:	41 5f                	pop    r15
 375:	5d                   	pop    rbp
 376:	c3                   	ret
 377:	31 c0                	xor    eax,eax
 379:	c3                   	ret
