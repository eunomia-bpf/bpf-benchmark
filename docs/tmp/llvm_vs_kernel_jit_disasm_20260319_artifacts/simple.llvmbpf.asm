
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/simple.llvmbpf.bin:     file format binary


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
  1e:	48 8d 48 48          	lea    rcx,[rax+0x48]
  22:	48 39 f1             	cmp    rcx,rsi
  25:	0f 97 c1             	seta   cl
  28:	08 d1                	or     cl,dl
  2a:	74 03                	je     0x2f
  2c:	31 c0                	xor    eax,eax
  2e:	c3                   	ret
  2f:	c6 40 02 bc          	mov    BYTE PTR [rax+0x2],0xbc
  33:	66 c7 00 4e 61       	mov    WORD PTR [rax],0x614e
  38:	c7 40 03 00 00 00 00 	mov    DWORD PTR [rax+0x3],0x0
  3f:	c6 40 07 00          	mov    BYTE PTR [rax+0x7],0x0
  43:	b8 02 00 00 00       	mov    eax,0x2
  48:	c3                   	ret
