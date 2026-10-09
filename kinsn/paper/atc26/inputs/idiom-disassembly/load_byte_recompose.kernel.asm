
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/load_byte_recompose.kernel.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	53                   	push   rbx
   d:	31 c0                	xor    eax,eax
   f:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  13:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  17:	48 39 f7             	cmp    rdi,rsi
  1a:	0f 87 41 01 00 00    	ja     0x161
  20:	48 89 fa             	mov    rdx,rdi
  23:	48 83 c2 08          	add    rdx,0x8
  27:	48 39 f2             	cmp    rdx,rsi
  2a:	0f 87 31 01 00 00    	ja     0x161
  30:	48 89 fa             	mov    rdx,rdi
  33:	48 81 c2 10 04 00 00 	add    rdx,0x410
  3a:	48 39 f2             	cmp    rdx,rsi
  3d:	0f 87 1e 01 00 00    	ja     0x161
  43:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  48:	48 c1 e6 08          	shl    rsi,0x8
  4c:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  51:	48 09 d6             	or     rsi,rdx
  54:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  59:	48 c1 e2 10          	shl    rdx,0x10
  5d:	48 09 d6             	or     rsi,rdx
  60:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  65:	48 c1 e2 18          	shl    rdx,0x18
  69:	48 09 d6             	or     rsi,rdx
  6c:	48 c1 e6 20          	shl    rsi,0x20
  70:	48 c1 ee 20          	shr    rsi,0x20
  74:	48 81 fe 80 00 00 00 	cmp    rsi,0x80
  7b:	0f 85 e0 00 00 00    	jne    0x161
  81:	31 d2                	xor    edx,edx
  83:	48 89 f9             	mov    rcx,rdi
  86:	48 83 c1 17          	add    rcx,0x17
  8a:	45 31 c0             	xor    r8d,r8d
  8d:	48 0f b6 71 fd       	movzx  rsi,BYTE PTR [rcx-0x3]
  92:	48 c1 e6 20          	shl    rsi,0x20
  96:	48 0f b6 41 fb       	movzx  rax,BYTE PTR [rcx-0x5]
  9b:	48 c1 e0 10          	shl    rax,0x10
  9f:	48 09 f0             	or     rax,rsi
  a2:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
  a7:	48 c1 e3 18          	shl    rbx,0x18
  ab:	48 0f b6 71 fa       	movzx  rsi,BYTE PTR [rcx-0x6]
  b0:	48 c1 e6 08          	shl    rsi,0x8
  b4:	48 09 de             	or     rsi,rbx
  b7:	48 09 c6             	or     rsi,rax
  ba:	48 0f b6 41 fe       	movzx  rax,BYTE PTR [rcx-0x2]
  bf:	48 c1 e0 28          	shl    rax,0x28
  c3:	48 09 c6             	or     rsi,rax
  c6:	48 0f b6 41 00       	movzx  rax,BYTE PTR [rcx+0x0]
  cb:	48 c1 e0 38          	shl    rax,0x38
  cf:	48 0f b6 59 ff       	movzx  rbx,BYTE PTR [rcx-0x1]
  d4:	48 c1 e3 30          	shl    rbx,0x30
  d8:	48 09 c3             	or     rbx,rax
  db:	48 09 de             	or     rsi,rbx
  de:	48 0f b6 41 f9       	movzx  rax,BYTE PTR [rcx-0x7]
  e3:	48 09 c6             	or     rsi,rax
  e6:	48 89 d0             	mov    rax,rdx
  e9:	48 83 e0 0f          	and    rax,0xf
  ed:	48 89 f3             	mov    rbx,rsi
  f0:	c4 e2 fb f7 db       	shrx   rbx,rbx,rax
  f5:	4c 01 c6             	add    rsi,r8
  f8:	48 31 de             	xor    rsi,rbx
  fb:	48 83 c1 08          	add    rcx,0x8
  ff:	48 83 c2 01          	add    rdx,0x1
 103:	49 89 f0             	mov    r8,rsi
 106:	48 81 fa 80 00 00 00 	cmp    rdx,0x80
 10d:	74 05                	je     0x114
 10f:	e9 79 ff ff ff       	jmp    0x8d
 114:	48 89 f2             	mov    rdx,rsi
 117:	48 c1 ea 38          	shr    rdx,0x38
 11b:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 11e:	48 89 f2             	mov    rdx,rsi
 121:	48 c1 ea 30          	shr    rdx,0x30
 125:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 128:	48 89 f2             	mov    rdx,rsi
 12b:	48 c1 ea 28          	shr    rdx,0x28
 12f:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 132:	48 89 f2             	mov    rdx,rsi
 135:	48 c1 ea 20          	shr    rdx,0x20
 139:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 13c:	48 89 f2             	mov    rdx,rsi
 13f:	48 c1 ea 18          	shr    rdx,0x18
 143:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 146:	48 89 f2             	mov    rdx,rsi
 149:	48 c1 ea 10          	shr    rdx,0x10
 14d:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 150:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
 154:	48 c1 ee 08          	shr    rsi,0x8
 158:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
 15c:	b8 02 00 00 00       	mov    eax,0x2
 161:	5b                   	pop    rbx
 162:	c9                   	leave
 163:	c3                   	ret
 164:	cc                   	int3
