
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/large_mixed_500.kernel.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 40 00 00 00 	sub    rsp,0x40
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 2c 08 00 00    	ja     0x859
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 1c 08 00 00    	ja     0x859
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 01 00 00 	add    rdi,0x110
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 09 08 00 00    	ja     0x859
  50:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 83 ff 20          	cmp    rdi,0x20
  85:	0f 85 ce 07 00 00    	jne    0x859
  8b:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
  90:	48 c1 e7 25          	shl    rdi,0x25
  94:	48 0f b6 51 0c       	movzx  rdx,BYTE PTR [rcx+0xc]
  99:	48 c1 e2 1d          	shl    rdx,0x1d
  9d:	48 09 fa             	or     rdx,rdi
  a0:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
  a5:	48 c1 e7 2d          	shl    rdi,0x2d
  a9:	48 09 fa             	or     rdx,rdi
  ac:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
  b1:	48 c1 e7 35          	shl    rdi,0x35
  b5:	48 09 fa             	or     rdx,rdi
  b8:	48 bf 2f 64 bd 78 64 	movabs rdi,0xa0761d6478bd642f
  bf:	1d 76 a0 
  c2:	48 31 fa             	xor    rdx,rdi
  c5:	bb 38 00 00 00       	mov    ebx,0x38
  ca:	45 31 c0             	xor    r8d,r8d
  cd:	49 89 cf             	mov    r15,rcx
  d0:	49 83 c7 17          	add    r15,0x17
  d4:	48 89 cf             	mov    rdi,rcx
  d7:	48 83 c7 16          	add    rdi,0x16
  db:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  df:	48 89 cf             	mov    rdi,rcx
  e2:	48 83 c7 15          	add    rdi,0x15
  e6:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  ea:	48 89 cf             	mov    rdi,rcx
  ed:	48 83 c7 11          	add    rdi,0x11
  f1:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  f5:	48 89 cf             	mov    rdi,rcx
  f8:	48 83 c7 10          	add    rdi,0x10
  fc:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 100:	45 31 f6             	xor    r14d,r14d
 103:	48 89 4d c0          	mov    QWORD PTR [rbp-0x40],rcx
 107:	4c 89 7d d0          	mov    QWORD PTR [rbp-0x30],r15
 10b:	eb 5c                	jmp    0x169
 10d:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 111:	48 89 c2             	mov    rdx,rax
 114:	48 01 ca             	add    rdx,rcx
 117:	48 31 f2             	xor    rdx,rsi
 11a:	48 89 d6             	mov    rsi,rdx
 11d:	4c 8b 45 c8          	mov    r8,QWORD PTR [rbp-0x38]
 121:	48 89 f2             	mov    rdx,rsi
 124:	48 c1 ea 04          	shr    rdx,0x4
 128:	48 31 f2             	xor    rdx,rsi
 12b:	48 89 d6             	mov    rsi,rdx
 12e:	48 c1 ee 38          	shr    rsi,0x38
 132:	48 c1 e2 08          	shl    rdx,0x8
 136:	48 09 f2             	or     rdx,rsi
 139:	48 01 f9             	add    rcx,rdi
 13c:	4c 89 c7             	mov    rdi,r8
 13f:	48 01 cf             	add    rdi,rcx
 142:	48 31 fa             	xor    rdx,rdi
 145:	49 83 c6 01          	add    r14,0x1
 149:	49 81 c0 00 08 00 00 	add    r8,0x800
 150:	48 83 c0 02          	add    rax,0x2
 154:	48 83 c3 08          	add    rbx,0x8
 158:	48 8b 4d c0          	mov    rcx,QWORD PTR [rbp-0x40]
 15c:	48 81 fb 38 01 00 00 	cmp    rbx,0x138
 163:	0f 84 9f 06 00 00    	je     0x808
 169:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
 16d:	4c 89 45 c8          	mov    QWORD PTR [rbp-0x38],r8
 171:	48 89 ce             	mov    rsi,rcx
 174:	48 01 de             	add    rsi,rbx
 177:	48 0f b6 7e dc       	movzx  rdi,BYTE PTR [rsi-0x24]
 17c:	48 c1 e7 20          	shl    rdi,0x20
 180:	48 0f b6 4e da       	movzx  rcx,BYTE PTR [rsi-0x26]
 185:	48 c1 e1 10          	shl    rcx,0x10
 189:	48 09 f9             	or     rcx,rdi
 18c:	4c 0f b6 46 db       	movzx  r8,BYTE PTR [rsi-0x25]
 191:	49 c1 e0 18          	shl    r8,0x18
 195:	48 0f b6 7e d9       	movzx  rdi,BYTE PTR [rsi-0x27]
 19a:	48 c1 e7 08          	shl    rdi,0x8
 19e:	4c 09 c7             	or     rdi,r8
 1a1:	48 09 cf             	or     rdi,rcx
 1a4:	48 0f b6 4e dd       	movzx  rcx,BYTE PTR [rsi-0x23]
 1a9:	48 c1 e1 28          	shl    rcx,0x28
 1ad:	48 09 cf             	or     rdi,rcx
 1b0:	48 0f b6 4e df       	movzx  rcx,BYTE PTR [rsi-0x21]
 1b5:	48 c1 e1 38          	shl    rcx,0x38
 1b9:	4c 0f b6 46 de       	movzx  r8,BYTE PTR [rsi-0x22]
 1be:	49 c1 e0 30          	shl    r8,0x30
 1c2:	49 09 c8             	or     r8,rcx
 1c5:	4c 09 c7             	or     rdi,r8
 1c8:	48 0f b6 76 d8       	movzx  rsi,BYTE PTR [rsi-0x28]
 1cd:	48 09 f7             	or     rdi,rsi
 1d0:	4c 89 f6             	mov    rsi,r14
 1d3:	48 83 e6 07          	and    rsi,0x7
 1d7:	4d 89 f0             	mov    r8,r14
 1da:	c4 42 c9 f7 c0       	shlx   r8,r8,rsi
 1df:	49 31 d0             	xor    r8,rdx
 1e2:	49 31 f8             	xor    r8,rdi
 1e5:	49 01 f8             	add    r8,rdi
 1e8:	48 89 f9             	mov    rcx,rdi
 1eb:	4c 31 c1             	xor    rcx,r8
 1ee:	4d 89 f0             	mov    r8,r14
 1f1:	49 01 c8             	add    r8,rcx
 1f4:	49 31 d0             	xor    r8,rdx
 1f7:	48 89 ce             	mov    rsi,rcx
 1fa:	48 83 e6 01          	and    rsi,0x1
 1fe:	48 85 f6             	test   rsi,rsi
 201:	74 06                	je     0x209
 203:	49 89 c8             	mov    r8,rcx
 206:	49 01 d0             	add    r8,rdx
 209:	48 89 de             	mov    rsi,rbx
 20c:	48 83 c6 d0          	add    rsi,0xffffffffffffffd0
 210:	48 81 e6 f8 00 00 00 	and    rsi,0xf8
 217:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 21b:	48 01 f2             	add    rdx,rsi
 21e:	48 0f b6 42 03       	movzx  rax,BYTE PTR [rdx+0x3]
 223:	48 c1 e0 20          	shl    rax,0x20
 227:	4c 0f b6 6a 01       	movzx  r13,BYTE PTR [rdx+0x1]
 22c:	49 c1 e5 10          	shl    r13,0x10
 230:	49 09 c5             	or     r13,rax
 233:	48 0f b6 42 02       	movzx  rax,BYTE PTR [rdx+0x2]
 238:	48 c1 e0 18          	shl    rax,0x18
 23c:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 241:	48 c1 e2 08          	shl    rdx,0x8
 245:	48 09 c2             	or     rdx,rax
 248:	4c 09 ea             	or     rdx,r13
 24b:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 24f:	48 01 f0             	add    rax,rsi
 252:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 257:	48 c1 e0 28          	shl    rax,0x28
 25b:	48 09 c2             	or     rdx,rax
 25e:	4c 89 f8             	mov    rax,r15
 261:	48 01 f0             	add    rax,rsi
 264:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 269:	48 c1 e0 38          	shl    rax,0x38
 26d:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 271:	49 01 f5             	add    r13,rsi
 274:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 279:	49 c1 e5 30          	shl    r13,0x30
 27d:	49 09 c5             	or     r13,rax
 280:	4c 09 ea             	or     rdx,r13
 283:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 287:	48 01 f0             	add    rax,rsi
 28a:	4d 89 c5             	mov    r13,r8
 28d:	49 d1 e5             	shl    r13,1
 290:	4c 89 c6             	mov    rsi,r8
 293:	48 83 e6 fe          	and    rsi,0xfffffffffffffffe
 297:	4c 31 ee             	xor    rsi,r13
 29a:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 29f:	48 09 c2             	or     rdx,rax
 2a2:	49 c1 e8 3f          	shr    r8,0x3f
 2a6:	4c 09 c6             	or     rsi,r8
 2a9:	49 89 f8             	mov    r8,rdi
 2ac:	48 b8 15 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c15
 2b3:	79 37 9e 
 2b6:	49 31 c0             	xor    r8,rax
 2b9:	4c 01 c1             	add    rcx,r8
 2bc:	48 31 ca             	xor    rdx,rcx
 2bf:	4d 89 f0             	mov    r8,r14
 2c2:	49 01 d0             	add    r8,rdx
 2c5:	49 31 f0             	xor    r8,rsi
 2c8:	48 89 d1             	mov    rcx,rdx
 2cb:	48 83 e1 02          	and    rcx,0x2
 2cf:	48 85 c9             	test   rcx,rcx
 2d2:	74 0d                	je     0x2e1
 2d4:	48 01 d6             	add    rsi,rdx
 2d7:	48 81 c6 00 00 08 00 	add    rsi,0x80000
 2de:	49 89 f0             	mov    r8,rsi
 2e1:	48 89 d8             	mov    rax,rbx
 2e4:	48 83 c0 d8          	add    rax,0xffffffffffffffd8
 2e8:	48 25 f8 00 00 00    	and    rax,0xf8
 2ee:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 2f2:	48 01 c6             	add    rsi,rax
 2f5:	48 0f b6 4e 03       	movzx  rcx,BYTE PTR [rsi+0x3]
 2fa:	48 c1 e1 20          	shl    rcx,0x20
 2fe:	4c 0f b6 6e 01       	movzx  r13,BYTE PTR [rsi+0x1]
 303:	49 c1 e5 10          	shl    r13,0x10
 307:	49 09 cd             	or     r13,rcx
 30a:	4c 0f b6 7e 02       	movzx  r15,BYTE PTR [rsi+0x2]
 30f:	49 c1 e7 18          	shl    r15,0x18
 313:	48 0f b6 4e 00       	movzx  rcx,BYTE PTR [rsi+0x0]
 318:	48 c1 e1 08          	shl    rcx,0x8
 31c:	4c 09 f9             	or     rcx,r15
 31f:	4c 09 e9             	or     rcx,r13
 322:	48 89 fe             	mov    rsi,rdi
 325:	49 bd 2a f8 94 fe 72 	movabs r13,0x3c6ef372fe94f82a
 32c:	f3 6e 3c 
 32f:	4c 31 ee             	xor    rsi,r13
 332:	48 01 f2             	add    rdx,rsi
 335:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 339:	48 01 c6             	add    rsi,rax
 33c:	48 0f b6 76 00       	movzx  rsi,BYTE PTR [rsi+0x0]
 341:	48 c1 e6 28          	shl    rsi,0x28
 345:	48 09 f1             	or     rcx,rsi
 348:	4c 8b 7d d0          	mov    r15,QWORD PTR [rbp-0x30]
 34c:	4c 89 fe             	mov    rsi,r15
 34f:	48 01 c6             	add    rsi,rax
 352:	48 0f b6 76 00       	movzx  rsi,BYTE PTR [rsi+0x0]
 357:	48 c1 e6 38          	shl    rsi,0x38
 35b:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 35f:	49 01 c5             	add    r13,rax
 362:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 367:	49 c1 e5 30          	shl    r13,0x30
 36b:	49 09 f5             	or     r13,rsi
 36e:	4c 09 e9             	or     rcx,r13
 371:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 375:	48 01 c6             	add    rsi,rax
 378:	48 0f b6 76 00       	movzx  rsi,BYTE PTR [rsi+0x0]
 37d:	48 09 f1             	or     rcx,rsi
 380:	48 31 d1             	xor    rcx,rdx
 383:	4c 89 c6             	mov    rsi,r8
 386:	48 d1 ee             	shr    rsi,1
 389:	4c 31 c6             	xor    rsi,r8
 38c:	48 89 f2             	mov    rdx,rsi
 38f:	48 c1 ea 3e          	shr    rdx,0x3e
 393:	48 c1 e6 02          	shl    rsi,0x2
 397:	48 09 d6             	or     rsi,rdx
 39a:	4c 89 f2             	mov    rdx,r14
 39d:	48 01 ca             	add    rdx,rcx
 3a0:	48 31 f2             	xor    rdx,rsi
 3a3:	49 89 c8             	mov    r8,rcx
 3a6:	49 83 e0 04          	and    r8,0x4
 3aa:	4d 85 c0             	test   r8,r8
 3ad:	74 0d                	je     0x3bc
 3af:	48 01 ce             	add    rsi,rcx
 3b2:	48 81 c6 00 00 10 00 	add    rsi,0x100000
 3b9:	48 89 f2             	mov    rdx,rsi
 3bc:	48 89 de             	mov    rsi,rbx
 3bf:	48 83 c6 e0          	add    rsi,0xffffffffffffffe0
 3c3:	48 81 e6 f8 00 00 00 	and    rsi,0xf8
 3ca:	4c 8b 45 e8          	mov    r8,QWORD PTR [rbp-0x18]
 3ce:	49 01 f0             	add    r8,rsi
 3d1:	49 0f b6 40 03       	movzx  rax,BYTE PTR [r8+0x3]
 3d6:	48 c1 e0 20          	shl    rax,0x20
 3da:	4d 0f b6 68 01       	movzx  r13,BYTE PTR [r8+0x1]
 3df:	49 c1 e5 10          	shl    r13,0x10
 3e3:	49 09 c5             	or     r13,rax
 3e6:	49 0f b6 40 02       	movzx  rax,BYTE PTR [r8+0x2]
 3eb:	48 c1 e0 18          	shl    rax,0x18
 3ef:	4d 0f b6 40 00       	movzx  r8,BYTE PTR [r8+0x0]
 3f4:	49 c1 e0 08          	shl    r8,0x8
 3f8:	49 09 c0             	or     r8,rax
 3fb:	4d 09 e8             	or     r8,r13
 3fe:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 402:	48 01 f0             	add    rax,rsi
 405:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 40a:	48 c1 e0 28          	shl    rax,0x28
 40e:	49 09 c0             	or     r8,rax
 411:	4c 89 f8             	mov    rax,r15
 414:	48 01 f0             	add    rax,rsi
 417:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 41c:	48 c1 e0 38          	shl    rax,0x38
 420:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 424:	49 01 f5             	add    r13,rsi
 427:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 42c:	49 c1 e5 30          	shl    r13,0x30
 430:	49 09 c5             	or     r13,rax
 433:	4d 09 e8             	or     r8,r13
 436:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 43a:	48 01 f0             	add    rax,rsi
 43d:	48 89 fe             	mov    rsi,rdi
 440:	49 bd 3f 74 df 7d 2c 	movabs r13,0xdaa66d2c7ddf743f
 447:	6d a6 da 
 44a:	4c 31 ee             	xor    rsi,r13
 44d:	48 01 f1             	add    rcx,rsi
 450:	48 0f b6 70 00       	movzx  rsi,BYTE PTR [rax+0x0]
 455:	49 09 f0             	or     r8,rsi
 458:	49 31 c8             	xor    r8,rcx
 45b:	48 89 d6             	mov    rsi,rdx
 45e:	48 c1 ee 02          	shr    rsi,0x2
 462:	48 31 d6             	xor    rsi,rdx
 465:	48 89 f2             	mov    rdx,rsi
 468:	48 c1 ea 3d          	shr    rdx,0x3d
 46c:	48 c1 e6 03          	shl    rsi,0x3
 470:	48 09 d6             	or     rsi,rdx
 473:	4c 89 f1             	mov    rcx,r14
 476:	4c 01 c1             	add    rcx,r8
 479:	48 31 f1             	xor    rcx,rsi
 47c:	4c 89 c2             	mov    rdx,r8
 47f:	48 83 e2 08          	and    rdx,0x8
 483:	48 85 d2             	test   rdx,rdx
 486:	74 0d                	je     0x495
 488:	4c 01 c6             	add    rsi,r8
 48b:	48 81 c6 00 00 18 00 	add    rsi,0x180000
 492:	48 89 f1             	mov    rcx,rsi
 495:	48 89 de             	mov    rsi,rbx
 498:	48 83 c6 e8          	add    rsi,0xffffffffffffffe8
 49c:	48 81 e6 f8 00 00 00 	and    rsi,0xf8
 4a3:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 4a7:	48 01 f2             	add    rdx,rsi
 4aa:	48 0f b6 42 03       	movzx  rax,BYTE PTR [rdx+0x3]
 4af:	48 c1 e0 20          	shl    rax,0x20
 4b3:	4c 0f b6 6a 01       	movzx  r13,BYTE PTR [rdx+0x1]
 4b8:	49 c1 e5 10          	shl    r13,0x10
 4bc:	49 09 c5             	or     r13,rax
 4bf:	48 0f b6 42 02       	movzx  rax,BYTE PTR [rdx+0x2]
 4c4:	48 c1 e0 18          	shl    rax,0x18
 4c8:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 4cd:	48 c1 e2 08          	shl    rdx,0x8
 4d1:	48 09 c2             	or     rdx,rax
 4d4:	4c 09 ea             	or     rdx,r13
 4d7:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 4db:	48 01 f0             	add    rax,rsi
 4de:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 4e3:	48 c1 e0 28          	shl    rax,0x28
 4e7:	48 09 c2             	or     rdx,rax
 4ea:	4c 89 f8             	mov    rax,r15
 4ed:	48 01 f0             	add    rax,rsi
 4f0:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 4f5:	48 c1 e0 38          	shl    rax,0x38
 4f9:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 4fd:	49 01 f5             	add    r13,rsi
 500:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 505:	49 c1 e5 30          	shl    r13,0x30
 509:	49 09 c5             	or     r13,rax
 50c:	4c 09 ea             	or     rdx,r13
 50f:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 513:	48 01 f0             	add    rax,rsi
 516:	48 0f b6 70 00       	movzx  rsi,BYTE PTR [rax+0x0]
 51b:	48 09 f2             	or     rdx,rsi
 51e:	48 89 fe             	mov    rsi,rdi
 521:	48 b8 54 f0 29 fd e5 	movabs rax,0x78dde6e5fd29f054
 528:	e6 dd 78 
 52b:	48 31 c6             	xor    rsi,rax
 52e:	49 01 f0             	add    r8,rsi
 531:	4c 31 c2             	xor    rdx,r8
 534:	48 89 c8             	mov    rax,rcx
 537:	48 c1 e8 02          	shr    rax,0x2
 53b:	48 31 c8             	xor    rax,rcx
 53e:	48 89 c6             	mov    rsi,rax
 541:	48 c1 ee 3c          	shr    rsi,0x3c
 545:	48 c1 e0 04          	shl    rax,0x4
 549:	48 09 f0             	or     rax,rsi
 54c:	48 89 d6             	mov    rsi,rdx
 54f:	48 83 e6 10          	and    rsi,0x10
 553:	48 85 f6             	test   rsi,rsi
 556:	74 0b                	je     0x563
 558:	48 01 d0             	add    rax,rdx
 55b:	48 05 00 00 20 00    	add    rax,0x200000
 561:	eb 0d                	jmp    0x570
 563:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 567:	48 01 d6             	add    rsi,rdx
 56a:	48 31 c6             	xor    rsi,rax
 56d:	48 89 f0             	mov    rax,rsi
 570:	48 89 de             	mov    rsi,rbx
 573:	48 83 c6 f0          	add    rsi,0xfffffffffffffff0
 577:	48 81 e6 f8 00 00 00 	and    rsi,0xf8
 57e:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
 582:	48 01 f1             	add    rcx,rsi
 585:	4c 0f b6 41 03       	movzx  r8,BYTE PTR [rcx+0x3]
 58a:	49 c1 e0 20          	shl    r8,0x20
 58e:	4c 0f b6 69 01       	movzx  r13,BYTE PTR [rcx+0x1]
 593:	49 c1 e5 10          	shl    r13,0x10
 597:	4d 09 c5             	or     r13,r8
 59a:	4c 0f b6 41 02       	movzx  r8,BYTE PTR [rcx+0x2]
 59f:	49 c1 e0 18          	shl    r8,0x18
 5a3:	48 0f b6 49 00       	movzx  rcx,BYTE PTR [rcx+0x0]
 5a8:	48 c1 e1 08          	shl    rcx,0x8
 5ac:	4c 09 c1             	or     rcx,r8
 5af:	4c 09 e9             	or     rcx,r13
 5b2:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
 5b6:	49 01 f0             	add    r8,rsi
 5b9:	4d 0f b6 40 00       	movzx  r8,BYTE PTR [r8+0x0]
 5be:	49 c1 e0 28          	shl    r8,0x28
 5c2:	4c 09 c1             	or     rcx,r8
 5c5:	4d 89 f8             	mov    r8,r15
 5c8:	49 01 f0             	add    r8,rsi
 5cb:	4d 0f b6 40 00       	movzx  r8,BYTE PTR [r8+0x0]
 5d0:	49 c1 e0 38          	shl    r8,0x38
 5d4:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 5d8:	49 01 f5             	add    r13,rsi
 5db:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 5e0:	49 c1 e5 30          	shl    r13,0x30
 5e4:	4d 09 c5             	or     r13,r8
 5e7:	49 89 c0             	mov    r8,rax
 5ea:	49 c1 e8 03          	shr    r8,0x3
 5ee:	49 31 c0             	xor    r8,rax
 5f1:	4c 09 e9             	or     rcx,r13
 5f4:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 5f8:	48 01 f0             	add    rax,rsi
 5fb:	48 0f b6 70 00       	movzx  rsi,BYTE PTR [rax+0x0]
 600:	48 09 f1             	or     rcx,rsi
 603:	4c 89 c6             	mov    rsi,r8
 606:	48 c1 ee 3b          	shr    rsi,0x3b
 60a:	49 c1 e0 05          	shl    r8,0x5
 60e:	49 09 f0             	or     r8,rsi
 611:	48 89 fe             	mov    rsi,rdi
 614:	48 b8 69 6c 74 7c 9f 	movabs rax,0x1715609f7c746c69
 61b:	60 15 17 
 61e:	48 31 c6             	xor    rsi,rax
 621:	48 01 f2             	add    rdx,rsi
 624:	48 31 d1             	xor    rcx,rdx
 627:	48 89 ce             	mov    rsi,rcx
 62a:	48 83 e6 20          	and    rsi,0x20
 62e:	48 85 f6             	test   rsi,rsi
 631:	74 0c                	je     0x63f
 633:	49 01 c8             	add    r8,rcx
 636:	49 81 c0 00 00 28 00 	add    r8,0x280000
 63d:	eb 0d                	jmp    0x64c
 63f:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 643:	48 01 ce             	add    rsi,rcx
 646:	4c 31 c6             	xor    rsi,r8
 649:	49 89 f0             	mov    r8,rsi
 64c:	48 89 de             	mov    rsi,rbx
 64f:	48 83 c6 f8          	add    rsi,0xfffffffffffffff8
 653:	48 81 e6 f8 00 00 00 	and    rsi,0xf8
 65a:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 65e:	48 01 f2             	add    rdx,rsi
 661:	48 0f b6 42 03       	movzx  rax,BYTE PTR [rdx+0x3]
 666:	48 c1 e0 20          	shl    rax,0x20
 66a:	4c 0f b6 6a 01       	movzx  r13,BYTE PTR [rdx+0x1]
 66f:	49 c1 e5 10          	shl    r13,0x10
 673:	49 09 c5             	or     r13,rax
 676:	48 0f b6 42 02       	movzx  rax,BYTE PTR [rdx+0x2]
 67b:	48 c1 e0 18          	shl    rax,0x18
 67f:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 684:	48 c1 e2 08          	shl    rdx,0x8
 688:	48 09 c2             	or     rdx,rax
 68b:	4c 09 ea             	or     rdx,r13
 68e:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 692:	48 01 f0             	add    rax,rsi
 695:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 69a:	48 c1 e0 28          	shl    rax,0x28
 69e:	48 09 c2             	or     rdx,rax
 6a1:	4c 89 f8             	mov    rax,r15
 6a4:	48 01 f0             	add    rax,rsi
 6a7:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 6ac:	48 c1 e0 38          	shl    rax,0x38
 6b0:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 6b4:	49 01 f5             	add    r13,rsi
 6b7:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 6bc:	49 c1 e5 30          	shl    r13,0x30
 6c0:	49 09 c5             	or     r13,rax
 6c3:	4c 89 c0             	mov    rax,r8
 6c6:	48 c1 e8 03          	shr    rax,0x3
 6ca:	4c 31 c0             	xor    rax,r8
 6cd:	4c 09 ea             	or     rdx,r13
 6d0:	4c 8b 45 e0          	mov    r8,QWORD PTR [rbp-0x20]
 6d4:	49 01 f0             	add    r8,rsi
 6d7:	49 0f b6 70 00       	movzx  rsi,BYTE PTR [r8+0x0]
 6dc:	48 09 f2             	or     rdx,rsi
 6df:	48 89 c6             	mov    rsi,rax
 6e2:	48 c1 ee 3a          	shr    rsi,0x3a
 6e6:	48 c1 e0 06          	shl    rax,0x6
 6ea:	48 09 f0             	or     rax,rsi
 6ed:	48 89 fe             	mov    rsi,rdi
 6f0:	49 b8 7e e8 be fb 58 	movabs r8,0xb54cda58fbbee87e
 6f7:	da 4c b5 
 6fa:	4c 31 c6             	xor    rsi,r8
 6fd:	48 01 f1             	add    rcx,rsi
 700:	48 31 ca             	xor    rdx,rcx
 703:	48 89 d6             	mov    rsi,rdx
 706:	48 83 e6 40          	and    rsi,0x40
 70a:	48 85 f6             	test   rsi,rsi
 70d:	74 0b                	je     0x71a
 70f:	48 01 d0             	add    rax,rdx
 712:	48 05 00 00 30 00    	add    rax,0x300000
 718:	eb 0d                	jmp    0x727
 71a:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 71e:	48 01 d6             	add    rsi,rdx
 721:	48 31 c6             	xor    rsi,rax
 724:	48 89 f0             	mov    rax,rsi
 727:	49 89 d8             	mov    r8,rbx
 72a:	49 81 e0 f8 00 00 00 	and    r8,0xf8
 731:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 735:	4c 01 c6             	add    rsi,r8
 738:	48 0f b6 4e 03       	movzx  rcx,BYTE PTR [rsi+0x3]
 73d:	48 c1 e1 20          	shl    rcx,0x20
 741:	4c 0f b6 6e 01       	movzx  r13,BYTE PTR [rsi+0x1]
 746:	49 c1 e5 10          	shl    r13,0x10
 74a:	49 09 cd             	or     r13,rcx
 74d:	4c 0f b6 7e 02       	movzx  r15,BYTE PTR [rsi+0x2]
 752:	49 c1 e7 18          	shl    r15,0x18
 756:	48 0f b6 4e 00       	movzx  rcx,BYTE PTR [rsi+0x0]
 75b:	48 c1 e1 08          	shl    rcx,0x8
 75f:	4c 09 f9             	or     rcx,r15
 762:	4c 09 e9             	or     rcx,r13
 765:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 769:	4c 01 c6             	add    rsi,r8
 76c:	48 0f b6 76 00       	movzx  rsi,BYTE PTR [rsi+0x0]
 771:	48 c1 e6 28          	shl    rsi,0x28
 775:	48 09 f1             	or     rcx,rsi
 778:	4c 8b 7d d0          	mov    r15,QWORD PTR [rbp-0x30]
 77c:	4c 89 fe             	mov    rsi,r15
 77f:	4c 01 c6             	add    rsi,r8
 782:	48 0f b6 76 00       	movzx  rsi,BYTE PTR [rsi+0x0]
 787:	48 c1 e6 38          	shl    rsi,0x38
 78b:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 78f:	4d 01 c5             	add    r13,r8
 792:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 797:	49 c1 e5 30          	shl    r13,0x30
 79b:	49 09 f5             	or     r13,rsi
 79e:	4c 09 e9             	or     rcx,r13
 7a1:	48 89 c6             	mov    rsi,rax
 7a4:	48 c1 ee 04          	shr    rsi,0x4
 7a8:	48 31 c6             	xor    rsi,rax
 7ab:	48 89 f8             	mov    rax,rdi
 7ae:	49 bd 93 64 09 7b 12 	movabs r13,0x538454127b096493
 7b5:	54 84 53 
 7b8:	4c 31 e8             	xor    rax,r13
 7bb:	48 01 c2             	add    rdx,rax
 7be:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 7c2:	4c 01 c0             	add    rax,r8
 7c5:	4c 0f b6 40 00       	movzx  r8,BYTE PTR [rax+0x0]
 7ca:	4c 09 c1             	or     rcx,r8
 7cd:	48 31 d1             	xor    rcx,rdx
 7d0:	48 89 f2             	mov    rdx,rsi
 7d3:	48 c1 ea 39          	shr    rdx,0x39
 7d7:	48 c1 e6 07          	shl    rsi,0x7
 7db:	48 09 d6             	or     rsi,rdx
 7de:	48 89 ca             	mov    rdx,rcx
 7e1:	48 81 e2 80 00 00 00 	and    rdx,0x80
 7e8:	48 85 d2             	test   rdx,rdx
 7eb:	0f 84 1c f9 ff ff    	je     0x10d
 7f1:	48 01 ce             	add    rsi,rcx
 7f4:	48 81 c6 00 00 38 00 	add    rsi,0x380000
 7fb:	4c 8b 45 c8          	mov    r8,QWORD PTR [rbp-0x38]
 7ff:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 803:	e9 19 f9 ff ff       	jmp    0x121
 808:	48 89 d7             	mov    rdi,rdx
 80b:	48 c1 ef 38          	shr    rdi,0x38
 80f:	40 88 79 07          	mov    BYTE PTR [rcx+0x7],dil
 813:	48 89 d7             	mov    rdi,rdx
 816:	48 c1 ef 30          	shr    rdi,0x30
 81a:	40 88 79 06          	mov    BYTE PTR [rcx+0x6],dil
 81e:	48 89 d7             	mov    rdi,rdx
 821:	48 c1 ef 28          	shr    rdi,0x28
 825:	40 88 79 05          	mov    BYTE PTR [rcx+0x5],dil
 829:	48 89 d7             	mov    rdi,rdx
 82c:	48 c1 ef 20          	shr    rdi,0x20
 830:	40 88 79 04          	mov    BYTE PTR [rcx+0x4],dil
 834:	48 89 d7             	mov    rdi,rdx
 837:	48 c1 ef 18          	shr    rdi,0x18
 83b:	40 88 79 03          	mov    BYTE PTR [rcx+0x3],dil
 83f:	48 89 d7             	mov    rdi,rdx
 842:	48 c1 ef 10          	shr    rdi,0x10
 846:	40 88 79 02          	mov    BYTE PTR [rcx+0x2],dil
 84a:	88 51 00             	mov    BYTE PTR [rcx+0x0],dl
 84d:	48 c1 ea 08          	shr    rdx,0x8
 851:	88 51 01             	mov    BYTE PTR [rcx+0x1],dl
 854:	b8 02 00 00 00       	mov    eax,0x2
 859:	41 5f                	pop    r15
 85b:	41 5e                	pop    r14
 85d:	41 5d                	pop    r13
 85f:	5b                   	pop    rbx
 860:	c9                   	leave
 861:	c3                   	ret
 862:	cc                   	int3
