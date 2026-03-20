
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/load_byte_recompose.llvmbpf.bin:     file format binary


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
  2d:	75 40                	jne    0x6f
  2f:	81 78 08 80 00 00 00 	cmp    DWORD PTR [rax+0x8],0x80
  36:	75 37                	jne    0x6f
  38:	48 8d 48 17          	lea    rcx,[rax+0x17]
  3c:	31 d2                	xor    edx,edx
  3e:	31 f6                	xor    esi,esi
  40:	48 8b 79 f9          	mov    rdi,QWORD PTR [rcx-0x7]
  44:	41 89 d0             	mov    r8d,edx
  47:	41 80 e0 0f          	and    r8b,0xf
  4b:	c4 62 bb f7 c7       	shrx   r8,rdi,r8
  50:	48 01 fe             	add    rsi,rdi
  53:	4c 31 c6             	xor    rsi,r8
  56:	48 83 c1 08          	add    rcx,0x8
  5a:	48 ff c2             	inc    rdx
  5d:	48 81 fa 80 00 00 00 	cmp    rdx,0x80
  64:	75 da                	jne    0x40
  66:	48 89 30             	mov    QWORD PTR [rax],rsi
  69:	b8 02 00 00 00       	mov    eax,0x2
  6e:	c3                   	ret
  6f:	31 c0                	xor    eax,eax
  71:	c3                   	ret
