
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/bounds_ladder.kernel.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 08 00 00 00 	sub    rsp,0x8
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	4c 8b 47 00          	mov    r8,QWORD PTR [rdi+0x0]
  24:	49 39 f0             	cmp    r8,rsi
  27:	0f 87 ce 02 00 00    	ja     0x2fb
  2d:	4c 89 c7             	mov    rdi,r8
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 be 02 00 00    	ja     0x2fb
  3d:	4c 89 c7             	mov    rdi,r8
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 ab 02 00 00    	ja     0x2fb
  50:	49 0f b6 70 09       	movzx  rsi,BYTE PTR [r8+0x9]
  55:	48 c1 e6 08          	shl    rsi,0x8
  59:	49 0f b6 78 08       	movzx  rdi,BYTE PTR [r8+0x8]
  5e:	48 09 fe             	or     rsi,rdi
  61:	49 0f b6 78 0a       	movzx  rdi,BYTE PTR [r8+0xa]
  66:	48 c1 e7 10          	shl    rdi,0x10
  6a:	48 09 fe             	or     rsi,rdi
  6d:	49 0f b6 78 0b       	movzx  rdi,BYTE PTR [r8+0xb]
  72:	48 c1 e7 18          	shl    rdi,0x18
  76:	48 09 fe             	or     rsi,rdi
  79:	48 c1 e6 20          	shl    rsi,0x20
  7d:	48 c1 ee 20          	shr    rsi,0x20
  81:	48 83 fe 20          	cmp    rsi,0x20
  85:	0f 85 70 02 00 00    	jne    0x2fb
  8b:	49 0f b6 70 0d       	movzx  rsi,BYTE PTR [r8+0xd]
  90:	48 c1 e6 08          	shl    rsi,0x8
  94:	49 0f b6 78 0c       	movzx  rdi,BYTE PTR [r8+0xc]
  99:	48 09 fe             	or     rsi,rdi
  9c:	49 0f b6 78 0e       	movzx  rdi,BYTE PTR [r8+0xe]
  a1:	48 c1 e7 10          	shl    rdi,0x10
  a5:	48 09 fe             	or     rsi,rdi
  a8:	49 0f b6 78 0f       	movzx  rdi,BYTE PTR [r8+0xf]
  ad:	48 c1 e7 18          	shl    rdi,0x18
  b1:	48 09 fe             	or     rsi,rdi
  b4:	48 c1 e6 20          	shl    rsi,0x20
  b8:	48 c1 ee 20          	shr    rsi,0x20
  bc:	48 83 fe 20          	cmp    rsi,0x20
  c0:	0f 85 35 02 00 00    	jne    0x2fb
  c6:	31 f6                	xor    esi,esi
  c8:	31 d2                	xor    edx,edx
  ca:	4c 89 45 f8          	mov    QWORD PTR [rbp-0x8],r8
  ce:	eb 15                	jmp    0xe5
  d0:	48 83 c6 20          	add    rsi,0x20
  d4:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
  d8:	48 81 fe 00 04 00 00 	cmp    rsi,0x400
  df:	0f 84 c3 01 00 00    	je     0x2a8
  e5:	49 01 f0             	add    r8,rsi
  e8:	49 0f b6 78 24       	movzx  rdi,BYTE PTR [r8+0x24]
  ed:	48 c1 e7 20          	shl    rdi,0x20
  f1:	49 0f b6 58 22       	movzx  rbx,BYTE PTR [r8+0x22]
  f6:	48 c1 e3 10          	shl    rbx,0x10
  fa:	48 09 fb             	or     rbx,rdi
  fd:	49 0f b6 78 23       	movzx  rdi,BYTE PTR [r8+0x23]
 102:	48 c1 e7 18          	shl    rdi,0x18
 106:	49 0f b6 48 21       	movzx  rcx,BYTE PTR [r8+0x21]
 10b:	48 c1 e1 08          	shl    rcx,0x8
 10f:	48 09 f9             	or     rcx,rdi
 112:	49 0f b6 78 18       	movzx  rdi,BYTE PTR [r8+0x18]
 117:	48 c1 e7 20          	shl    rdi,0x20
 11b:	4d 0f b6 68 16       	movzx  r13,BYTE PTR [r8+0x16]
 120:	49 c1 e5 10          	shl    r13,0x10
 124:	49 09 fd             	or     r13,rdi
 127:	49 0f b6 78 17       	movzx  rdi,BYTE PTR [r8+0x17]
 12c:	48 c1 e7 18          	shl    rdi,0x18
 130:	49 0f b6 40 15       	movzx  rax,BYTE PTR [r8+0x15]
 135:	48 c1 e0 08          	shl    rax,0x8
 139:	48 09 f8             	or     rax,rdi
 13c:	4c 09 e8             	or     rax,r13
 13f:	48 09 d9             	or     rcx,rbx
 142:	49 0f b6 78 2c       	movzx  rdi,BYTE PTR [r8+0x2c]
 147:	48 c1 e7 20          	shl    rdi,0x20
 14b:	4d 0f b6 68 2a       	movzx  r13,BYTE PTR [r8+0x2a]
 150:	49 c1 e5 10          	shl    r13,0x10
 154:	49 09 fd             	or     r13,rdi
 157:	49 0f b6 78 2b       	movzx  rdi,BYTE PTR [r8+0x2b]
 15c:	48 c1 e7 18          	shl    rdi,0x18
 160:	49 0f b6 58 29       	movzx  rbx,BYTE PTR [r8+0x29]
 165:	48 c1 e3 08          	shl    rbx,0x8
 169:	48 09 fb             	or     rbx,rdi
 16c:	4c 09 eb             	or     rbx,r13
 16f:	49 0f b6 78 2d       	movzx  rdi,BYTE PTR [r8+0x2d]
 174:	48 c1 e7 28          	shl    rdi,0x28
 178:	48 09 fb             	or     rbx,rdi
 17b:	49 0f b6 78 25       	movzx  rdi,BYTE PTR [r8+0x25]
 180:	48 c1 e7 28          	shl    rdi,0x28
 184:	48 09 f9             	or     rcx,rdi
 187:	49 0f b6 78 19       	movzx  rdi,BYTE PTR [r8+0x19]
 18c:	48 c1 e7 28          	shl    rdi,0x28
 190:	48 09 f8             	or     rax,rdi
 193:	49 0f b6 78 2f       	movzx  rdi,BYTE PTR [r8+0x2f]
 198:	48 c1 e7 38          	shl    rdi,0x38
 19c:	4d 0f b6 68 2e       	movzx  r13,BYTE PTR [r8+0x2e]
 1a1:	49 c1 e5 30          	shl    r13,0x30
 1a5:	49 09 fd             	or     r13,rdi
 1a8:	49 0f b6 78 27       	movzx  rdi,BYTE PTR [r8+0x27]
 1ad:	48 c1 e7 38          	shl    rdi,0x38
 1b1:	4d 0f b6 70 26       	movzx  r14,BYTE PTR [r8+0x26]
 1b6:	49 c1 e6 30          	shl    r14,0x30
 1ba:	49 09 fe             	or     r14,rdi
 1bd:	49 0f b6 78 1b       	movzx  rdi,BYTE PTR [r8+0x1b]
 1c2:	48 c1 e7 38          	shl    rdi,0x38
 1c6:	4d 0f b6 78 1a       	movzx  r15,BYTE PTR [r8+0x1a]
 1cb:	49 c1 e7 30          	shl    r15,0x30
 1cf:	49 09 ff             	or     r15,rdi
 1d2:	4c 09 f8             	or     rax,r15
 1d5:	4c 09 f1             	or     rcx,r14
 1d8:	4c 09 eb             	or     rbx,r13
 1db:	49 0f b6 78 1e       	movzx  rdi,BYTE PTR [r8+0x1e]
 1e0:	48 c1 e7 10          	shl    rdi,0x10
 1e4:	4d 0f b6 68 1d       	movzx  r13,BYTE PTR [r8+0x1d]
 1e9:	49 c1 e5 08          	shl    r13,0x8
 1ed:	49 09 fd             	or     r13,rdi
 1f0:	49 0f b6 78 20       	movzx  rdi,BYTE PTR [r8+0x20]
 1f5:	48 09 f9             	or     rcx,rdi
 1f8:	49 0f b6 78 14       	movzx  rdi,BYTE PTR [r8+0x14]
 1fd:	48 09 f8             	or     rax,rdi
 200:	4d 0f b6 70 12       	movzx  r14,BYTE PTR [r8+0x12]
 205:	49 c1 e6 10          	shl    r14,0x10
 209:	49 0f b6 78 11       	movzx  rdi,BYTE PTR [r8+0x11]
 20e:	48 c1 e7 08          	shl    rdi,0x8
 212:	4c 09 f7             	or     rdi,r14
 215:	4d 0f b6 70 28       	movzx  r14,BYTE PTR [r8+0x28]
 21a:	4c 09 f3             	or     rbx,r14
 21d:	4d 0f b6 70 1f       	movzx  r14,BYTE PTR [r8+0x1f]
 222:	49 c1 e6 18          	shl    r14,0x18
 226:	4d 09 f5             	or     r13,r14
 229:	4d 0f b6 70 13       	movzx  r14,BYTE PTR [r8+0x13]
 22e:	49 c1 e6 18          	shl    r14,0x18
 232:	4c 09 f7             	or     rdi,r14
 235:	49 89 c7             	mov    r15,rax
 238:	49 01 d7             	add    r15,rdx
 23b:	49 0f b6 50 10       	movzx  rdx,BYTE PTR [r8+0x10]
 240:	48 09 d7             	or     rdi,rdx
 243:	48 c1 e7 20          	shl    rdi,0x20
 247:	49 01 cf             	add    r15,rcx
 24a:	48 c1 ef 20          	shr    rdi,0x20
 24e:	4d 0f b6 40 1c       	movzx  r8,BYTE PTR [r8+0x1c]
 253:	4d 09 c5             	or     r13,r8
 256:	49 c1 e5 20          	shl    r13,0x20
 25a:	49 c1 ed 20          	shr    r13,0x20
 25e:	4d 89 ee             	mov    r14,r13
 261:	49 01 fe             	add    r14,rdi
 264:	49 01 de             	add    r14,rbx
 267:	4d 31 fe             	xor    r14,r15
 26a:	4d 89 f7             	mov    r15,r14
 26d:	4d 01 ef             	add    r15,r13
 270:	48 83 e2 01          	and    rdx,0x1
 274:	48 85 d2             	test   rdx,rdx
 277:	74 0a                	je     0x283
 279:	48 c1 e8 05          	shr    rax,0x5
 27d:	49 31 c6             	xor    r14,rax
 280:	4d 89 f7             	mov    r15,r14
 283:	48 c1 eb 07          	shr    rbx,0x7
 287:	4c 89 fa             	mov    rdx,r15
 28a:	48 01 da             	add    rdx,rbx
 28d:	49 83 e0 03          	and    r8,0x3
 291:	4d 85 c0             	test   r8,r8
 294:	0f 84 36 fe ff ff    	je     0xd0
 29a:	48 d1 e1             	shl    rcx,1
 29d:	49 31 cf             	xor    r15,rcx
 2a0:	4c 89 fa             	mov    rdx,r15
 2a3:	e9 28 fe ff ff       	jmp    0xd0
 2a8:	48 89 d7             	mov    rdi,rdx
 2ab:	48 c1 ef 38          	shr    rdi,0x38
 2af:	41 88 78 07          	mov    BYTE PTR [r8+0x7],dil
 2b3:	48 89 d7             	mov    rdi,rdx
 2b6:	48 c1 ef 30          	shr    rdi,0x30
 2ba:	41 88 78 06          	mov    BYTE PTR [r8+0x6],dil
 2be:	48 89 d7             	mov    rdi,rdx
 2c1:	48 c1 ef 28          	shr    rdi,0x28
 2c5:	41 88 78 05          	mov    BYTE PTR [r8+0x5],dil
 2c9:	48 89 d7             	mov    rdi,rdx
 2cc:	48 c1 ef 20          	shr    rdi,0x20
 2d0:	41 88 78 04          	mov    BYTE PTR [r8+0x4],dil
 2d4:	48 89 d7             	mov    rdi,rdx
 2d7:	48 c1 ef 18          	shr    rdi,0x18
 2db:	41 88 78 03          	mov    BYTE PTR [r8+0x3],dil
 2df:	48 89 d7             	mov    rdi,rdx
 2e2:	48 c1 ef 10          	shr    rdi,0x10
 2e6:	41 88 78 02          	mov    BYTE PTR [r8+0x2],dil
 2ea:	41 88 50 00          	mov    BYTE PTR [r8+0x0],dl
 2ee:	48 c1 ea 08          	shr    rdx,0x8
 2f2:	41 88 50 01          	mov    BYTE PTR [r8+0x1],dl
 2f6:	b8 02 00 00 00       	mov    eax,0x2
 2fb:	41 5f                	pop    r15
 2fd:	41 5e                	pop    r14
 2ff:	41 5d                	pop    r13
 301:	5b                   	pop    rbx
 302:	c9                   	leave
 303:	c3                   	ret
 304:	cc                   	int3
