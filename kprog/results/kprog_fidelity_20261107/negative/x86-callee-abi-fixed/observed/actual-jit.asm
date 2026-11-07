
/workspaces/repository/kprog/results/kprog_fidelity_20261107/negative/x86-callee-abi-fixed/observed/load-only/6-8/jit.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00                                  	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00                                        	nop    DWORD PTR [rax]
   8:	55                                              	push   rbp
   9:	48 89 e5                                        	mov    rbp,rsp
   c:	53                                              	push   rbx
   d:	48 bb f0 de bc 9a 78 56 34 12                   	movabs rbx,0x123456789abcdef0
  17:	b8 02 00 00 00                                  	mov    eax,0x2
  1c:	5b                                              	pop    rbx
  1d:	c9                                              	leave
  1e:	e9 f1 21 c1 ce                                  	jmp    0xffffffffcec12214
