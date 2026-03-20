
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/bounds_ladder.llvmbpf.bin:     file format binary


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
  1e:	48 8d 88 10 04 00 00 	lea    rcx,[rax+0x410]
  25:	48 39 f1             	cmp    rcx,rsi
  28:	0f 97 c1             	seta   cl
  2b:	08 d1                	or     cl,dl
  2d:	0f 85 d6 00 00 00    	jne    0x109
  33:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
  37:	0f 85 cc 00 00 00    	jne    0x109
  3d:	83 78 0c 20          	cmp    DWORD PTR [rax+0xc],0x20
  41:	0f 85 c2 00 00 00    	jne    0x109
  47:	53                   	push   rbx
  48:	31 d2                	xor    edx,edx
  4a:	31 c9                	xor    ecx,ecx
  4c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  50:	0f b6 74 08 1e       	movzx  esi,BYTE PTR [rax+rcx*1+0x1e]
  55:	c1 e6 10             	shl    esi,0x10
  58:	44 0f b6 54 08 1d    	movzx  r10d,BYTE PTR [rax+rcx*1+0x1d]
  5e:	41 c1 e2 08          	shl    r10d,0x8
  62:	41 09 f2             	or     r10d,esi
  65:	48 8b 7c 08 14       	mov    rdi,QWORD PTR [rax+rcx*1+0x14]
  6a:	48 8b 74 08 20       	mov    rsi,QWORD PTR [rax+rcx*1+0x20]
  6f:	44 0f b6 44 08 12    	movzx  r8d,BYTE PTR [rax+rcx*1+0x12]
  75:	41 c1 e0 10          	shl    r8d,0x10
  79:	44 0f b6 5c 08 11    	movzx  r11d,BYTE PTR [rax+rcx*1+0x11]
  7f:	41 c1 e3 08          	shl    r11d,0x8
  83:	45 09 c3             	or     r11d,r8d
  86:	4c 8b 44 08 28       	mov    r8,QWORD PTR [rax+rcx*1+0x28]
  8b:	44 0f b6 4c 08 1f    	movzx  r9d,BYTE PTR [rax+rcx*1+0x1f]
  91:	41 c1 e1 18          	shl    r9d,0x18
  95:	45 09 d1             	or     r9d,r10d
  98:	44 0f b6 54 08 13    	movzx  r10d,BYTE PTR [rax+rcx*1+0x13]
  9e:	41 c1 e2 18          	shl    r10d,0x18
  a2:	45 09 da             	or     r10d,r11d
  a5:	44 0f b6 5c 08 10    	movzx  r11d,BYTE PTR [rax+rcx*1+0x10]
  ab:	4d 09 da             	or     r10,r11
  ae:	48 01 f2             	add    rdx,rsi
  b1:	48 01 fa             	add    rdx,rdi
  b4:	0f b6 5c 08 1c       	movzx  ebx,BYTE PTR [rax+rcx*1+0x1c]
  b9:	49 09 d9             	or     r9,rbx
  bc:	4d 01 c2             	add    r10,r8
  bf:	4d 01 ca             	add    r10,r9
  c2:	49 31 d2             	xor    r10,rdx
  c5:	4d 01 d1             	add    r9,r10
  c8:	48 c1 ef 05          	shr    rdi,0x5
  cc:	4c 31 d7             	xor    rdi,r10
  cf:	41 f6 c3 01          	test   r11b,0x1
  d3:	49 0f 44 f9          	cmove  rdi,r9
  d7:	49 c1 e8 07          	shr    r8,0x7
  db:	49 01 f8             	add    r8,rdi
  de:	48 01 f6             	add    rsi,rsi
  e1:	48 31 fe             	xor    rsi,rdi
  e4:	f6 c3 03             	test   bl,0x3
  e7:	48 89 f2             	mov    rdx,rsi
  ea:	49 0f 44 d0          	cmove  rdx,r8
  ee:	48 83 c1 20          	add    rcx,0x20
  f2:	48 81 f9 00 04 00 00 	cmp    rcx,0x400
  f9:	0f 85 51 ff ff ff    	jne    0x50
  ff:	48 89 10             	mov    QWORD PTR [rax],rdx
 102:	b8 02 00 00 00       	mov    eax,0x2
 107:	5b                   	pop    rbx
 108:	c3                   	ret
 109:	31 c0                	xor    eax,eax
 10b:	c3                   	ret
