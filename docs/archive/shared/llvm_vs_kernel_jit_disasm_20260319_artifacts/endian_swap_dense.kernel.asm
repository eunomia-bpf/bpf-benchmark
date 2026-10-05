
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/endian_swap_dense.kernel.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
       0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
       5:	0f 1f 00             	nop    DWORD PTR [rax]
       8:	55                   	push   rbp
       9:	48 89 e5             	mov    rbp,rsp
       c:	31 c0                	xor    eax,eax
       e:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
      12:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
      16:	48 39 f7             	cmp    rdi,rsi
      19:	0f 87 1c 12 00 00    	ja     0x123b
      1f:	48 89 fa             	mov    rdx,rdi
      22:	48 83 c2 08          	add    rdx,0x8
      26:	48 39 f2             	cmp    rdx,rsi
      29:	0f 87 0c 12 00 00    	ja     0x123b
      2f:	48 89 fa             	mov    rdx,rdi
      32:	48 81 c2 08 04 00 00 	add    rdx,0x408
      39:	48 39 f2             	cmp    rdx,rsi
      3c:	0f 87 f9 11 00 00    	ja     0x123b
      42:	8b 57 08             	mov    edx,DWORD PTR [rdi+0x8]
      45:	0f ca                	bswap  edx
      47:	48 b9 2b fc 94 fe 72 	movabs rcx,0x3c6ef372fe94fc2b
      4e:	f3 6e 3c 
      51:	48 89 d6             	mov    rsi,rdx
      54:	48 01 ce             	add    rsi,rcx
      57:	8b 57 0c             	mov    edx,DWORD PTR [rdi+0xc]
      5a:	0f ca                	bswap  edx
      5c:	48 01 d6             	add    rsi,rdx
      5f:	48 81 c6 00 00 01 00 	add    rsi,0x10000
      66:	8b 57 10             	mov    edx,DWORD PTR [rdi+0x10]
      69:	0f ca                	bswap  edx
      6b:	48 01 d6             	add    rsi,rdx
      6e:	48 81 c6 00 00 02 00 	add    rsi,0x20000
      75:	8b 57 14             	mov    edx,DWORD PTR [rdi+0x14]
      78:	0f ca                	bswap  edx
      7a:	48 01 d6             	add    rsi,rdx
      7d:	48 81 c6 00 00 03 00 	add    rsi,0x30000
      84:	8b 57 18             	mov    edx,DWORD PTR [rdi+0x18]
      87:	0f ca                	bswap  edx
      89:	48 01 d6             	add    rsi,rdx
      8c:	48 81 c6 00 00 04 00 	add    rsi,0x40000
      93:	8b 57 1c             	mov    edx,DWORD PTR [rdi+0x1c]
      96:	0f ca                	bswap  edx
      98:	48 01 d6             	add    rsi,rdx
      9b:	48 81 c6 00 00 05 00 	add    rsi,0x50000
      a2:	8b 57 20             	mov    edx,DWORD PTR [rdi+0x20]
      a5:	0f ca                	bswap  edx
      a7:	48 01 d6             	add    rsi,rdx
      aa:	48 81 c6 00 00 06 00 	add    rsi,0x60000
      b1:	8b 57 24             	mov    edx,DWORD PTR [rdi+0x24]
      b4:	0f ca                	bswap  edx
      b6:	48 01 d6             	add    rsi,rdx
      b9:	48 81 c6 00 00 07 00 	add    rsi,0x70000
      c0:	8b 57 28             	mov    edx,DWORD PTR [rdi+0x28]
      c3:	0f ca                	bswap  edx
      c5:	48 01 d6             	add    rsi,rdx
      c8:	48 81 c6 00 00 08 00 	add    rsi,0x80000
      cf:	8b 57 2c             	mov    edx,DWORD PTR [rdi+0x2c]
      d2:	0f ca                	bswap  edx
      d4:	48 01 d6             	add    rsi,rdx
      d7:	48 81 c6 00 00 09 00 	add    rsi,0x90000
      de:	8b 57 30             	mov    edx,DWORD PTR [rdi+0x30]
      e1:	0f ca                	bswap  edx
      e3:	48 01 d6             	add    rsi,rdx
      e6:	48 81 c6 00 00 0a 00 	add    rsi,0xa0000
      ed:	8b 57 34             	mov    edx,DWORD PTR [rdi+0x34]
      f0:	0f ca                	bswap  edx
      f2:	48 01 d6             	add    rsi,rdx
      f5:	48 81 c6 00 00 0b 00 	add    rsi,0xb0000
      fc:	8b 57 38             	mov    edx,DWORD PTR [rdi+0x38]
      ff:	0f ca                	bswap  edx
     101:	48 01 d6             	add    rsi,rdx
     104:	48 81 c6 00 00 0c 00 	add    rsi,0xc0000
     10b:	8b 57 3c             	mov    edx,DWORD PTR [rdi+0x3c]
     10e:	0f ca                	bswap  edx
     110:	48 01 d6             	add    rsi,rdx
     113:	48 81 c6 00 00 0d 00 	add    rsi,0xd0000
     11a:	8b 57 40             	mov    edx,DWORD PTR [rdi+0x40]
     11d:	0f ca                	bswap  edx
     11f:	48 01 d6             	add    rsi,rdx
     122:	48 81 c6 00 00 0e 00 	add    rsi,0xe0000
     129:	8b 57 44             	mov    edx,DWORD PTR [rdi+0x44]
     12c:	0f ca                	bswap  edx
     12e:	48 01 d6             	add    rsi,rdx
     131:	48 81 c6 00 00 0f 00 	add    rsi,0xf0000
     138:	8b 57 48             	mov    edx,DWORD PTR [rdi+0x48]
     13b:	0f ca                	bswap  edx
     13d:	48 01 d6             	add    rsi,rdx
     140:	48 81 c6 00 00 10 00 	add    rsi,0x100000
     147:	8b 57 4c             	mov    edx,DWORD PTR [rdi+0x4c]
     14a:	0f ca                	bswap  edx
     14c:	48 01 d6             	add    rsi,rdx
     14f:	48 81 c6 00 00 11 00 	add    rsi,0x110000
     156:	8b 57 50             	mov    edx,DWORD PTR [rdi+0x50]
     159:	0f ca                	bswap  edx
     15b:	48 01 d6             	add    rsi,rdx
     15e:	48 81 c6 00 00 12 00 	add    rsi,0x120000
     165:	8b 57 54             	mov    edx,DWORD PTR [rdi+0x54]
     168:	0f ca                	bswap  edx
     16a:	48 01 d6             	add    rsi,rdx
     16d:	48 81 c6 00 00 13 00 	add    rsi,0x130000
     174:	8b 57 58             	mov    edx,DWORD PTR [rdi+0x58]
     177:	0f ca                	bswap  edx
     179:	48 01 d6             	add    rsi,rdx
     17c:	48 81 c6 00 00 14 00 	add    rsi,0x140000
     183:	8b 57 5c             	mov    edx,DWORD PTR [rdi+0x5c]
     186:	0f ca                	bswap  edx
     188:	48 01 d6             	add    rsi,rdx
     18b:	48 81 c6 00 00 15 00 	add    rsi,0x150000
     192:	8b 57 60             	mov    edx,DWORD PTR [rdi+0x60]
     195:	0f ca                	bswap  edx
     197:	48 01 d6             	add    rsi,rdx
     19a:	48 81 c6 00 00 16 00 	add    rsi,0x160000
     1a1:	8b 57 64             	mov    edx,DWORD PTR [rdi+0x64]
     1a4:	0f ca                	bswap  edx
     1a6:	48 01 d6             	add    rsi,rdx
     1a9:	48 81 c6 00 00 17 00 	add    rsi,0x170000
     1b0:	8b 57 68             	mov    edx,DWORD PTR [rdi+0x68]
     1b3:	0f ca                	bswap  edx
     1b5:	48 01 d6             	add    rsi,rdx
     1b8:	48 81 c6 00 00 18 00 	add    rsi,0x180000
     1bf:	8b 57 6c             	mov    edx,DWORD PTR [rdi+0x6c]
     1c2:	0f ca                	bswap  edx
     1c4:	48 01 d6             	add    rsi,rdx
     1c7:	48 81 c6 00 00 19 00 	add    rsi,0x190000
     1ce:	8b 57 70             	mov    edx,DWORD PTR [rdi+0x70]
     1d1:	0f ca                	bswap  edx
     1d3:	48 01 d6             	add    rsi,rdx
     1d6:	48 81 c6 00 00 1a 00 	add    rsi,0x1a0000
     1dd:	8b 57 74             	mov    edx,DWORD PTR [rdi+0x74]
     1e0:	0f ca                	bswap  edx
     1e2:	48 01 d6             	add    rsi,rdx
     1e5:	48 81 c6 00 00 1b 00 	add    rsi,0x1b0000
     1ec:	8b 57 78             	mov    edx,DWORD PTR [rdi+0x78]
     1ef:	0f ca                	bswap  edx
     1f1:	48 01 d6             	add    rsi,rdx
     1f4:	48 81 c6 00 00 1c 00 	add    rsi,0x1c0000
     1fb:	8b 57 7c             	mov    edx,DWORD PTR [rdi+0x7c]
     1fe:	0f ca                	bswap  edx
     200:	48 01 d6             	add    rsi,rdx
     203:	48 81 c6 00 00 1d 00 	add    rsi,0x1d0000
     20a:	8b 97 80 00 00 00    	mov    edx,DWORD PTR [rdi+0x80]
     210:	0f ca                	bswap  edx
     212:	48 01 d6             	add    rsi,rdx
     215:	48 81 c6 00 00 1e 00 	add    rsi,0x1e0000
     21c:	8b 97 84 00 00 00    	mov    edx,DWORD PTR [rdi+0x84]
     222:	0f ca                	bswap  edx
     224:	48 01 d6             	add    rsi,rdx
     227:	48 81 c6 00 00 1f 00 	add    rsi,0x1f0000
     22e:	8b 97 88 00 00 00    	mov    edx,DWORD PTR [rdi+0x88]
     234:	0f ca                	bswap  edx
     236:	48 01 d6             	add    rsi,rdx
     239:	48 81 c6 00 00 20 00 	add    rsi,0x200000
     240:	8b 97 8c 00 00 00    	mov    edx,DWORD PTR [rdi+0x8c]
     246:	0f ca                	bswap  edx
     248:	48 01 d6             	add    rsi,rdx
     24b:	48 81 c6 00 00 21 00 	add    rsi,0x210000
     252:	8b 97 90 00 00 00    	mov    edx,DWORD PTR [rdi+0x90]
     258:	0f ca                	bswap  edx
     25a:	48 01 d6             	add    rsi,rdx
     25d:	48 81 c6 00 00 22 00 	add    rsi,0x220000
     264:	8b 97 94 00 00 00    	mov    edx,DWORD PTR [rdi+0x94]
     26a:	0f ca                	bswap  edx
     26c:	48 01 d6             	add    rsi,rdx
     26f:	48 81 c6 00 00 23 00 	add    rsi,0x230000
     276:	8b 97 98 00 00 00    	mov    edx,DWORD PTR [rdi+0x98]
     27c:	0f ca                	bswap  edx
     27e:	48 01 d6             	add    rsi,rdx
     281:	48 81 c6 00 00 24 00 	add    rsi,0x240000
     288:	8b 97 9c 00 00 00    	mov    edx,DWORD PTR [rdi+0x9c]
     28e:	0f ca                	bswap  edx
     290:	48 01 d6             	add    rsi,rdx
     293:	48 81 c6 00 00 25 00 	add    rsi,0x250000
     29a:	8b 97 a0 00 00 00    	mov    edx,DWORD PTR [rdi+0xa0]
     2a0:	0f ca                	bswap  edx
     2a2:	48 01 d6             	add    rsi,rdx
     2a5:	48 81 c6 00 00 26 00 	add    rsi,0x260000
     2ac:	8b 97 a4 00 00 00    	mov    edx,DWORD PTR [rdi+0xa4]
     2b2:	0f ca                	bswap  edx
     2b4:	48 01 d6             	add    rsi,rdx
     2b7:	48 81 c6 00 00 27 00 	add    rsi,0x270000
     2be:	8b 97 a8 00 00 00    	mov    edx,DWORD PTR [rdi+0xa8]
     2c4:	0f ca                	bswap  edx
     2c6:	48 01 d6             	add    rsi,rdx
     2c9:	48 81 c6 00 00 28 00 	add    rsi,0x280000
     2d0:	8b 97 ac 00 00 00    	mov    edx,DWORD PTR [rdi+0xac]
     2d6:	0f ca                	bswap  edx
     2d8:	48 01 d6             	add    rsi,rdx
     2db:	48 81 c6 00 00 29 00 	add    rsi,0x290000
     2e2:	8b 97 b0 00 00 00    	mov    edx,DWORD PTR [rdi+0xb0]
     2e8:	0f ca                	bswap  edx
     2ea:	48 01 d6             	add    rsi,rdx
     2ed:	48 81 c6 00 00 2a 00 	add    rsi,0x2a0000
     2f4:	8b 97 b4 00 00 00    	mov    edx,DWORD PTR [rdi+0xb4]
     2fa:	0f ca                	bswap  edx
     2fc:	48 01 d6             	add    rsi,rdx
     2ff:	48 81 c6 00 00 2b 00 	add    rsi,0x2b0000
     306:	8b 97 b8 00 00 00    	mov    edx,DWORD PTR [rdi+0xb8]
     30c:	0f ca                	bswap  edx
     30e:	48 01 d6             	add    rsi,rdx
     311:	48 81 c6 00 00 2c 00 	add    rsi,0x2c0000
     318:	8b 97 bc 00 00 00    	mov    edx,DWORD PTR [rdi+0xbc]
     31e:	0f ca                	bswap  edx
     320:	48 01 d6             	add    rsi,rdx
     323:	48 81 c6 00 00 2d 00 	add    rsi,0x2d0000
     32a:	8b 97 c0 00 00 00    	mov    edx,DWORD PTR [rdi+0xc0]
     330:	0f ca                	bswap  edx
     332:	48 01 d6             	add    rsi,rdx
     335:	48 81 c6 00 00 2e 00 	add    rsi,0x2e0000
     33c:	8b 97 c4 00 00 00    	mov    edx,DWORD PTR [rdi+0xc4]
     342:	0f ca                	bswap  edx
     344:	48 01 d6             	add    rsi,rdx
     347:	48 81 c6 00 00 2f 00 	add    rsi,0x2f0000
     34e:	8b 97 c8 00 00 00    	mov    edx,DWORD PTR [rdi+0xc8]
     354:	0f ca                	bswap  edx
     356:	48 01 d6             	add    rsi,rdx
     359:	48 81 c6 00 00 30 00 	add    rsi,0x300000
     360:	8b 97 cc 00 00 00    	mov    edx,DWORD PTR [rdi+0xcc]
     366:	0f ca                	bswap  edx
     368:	48 01 d6             	add    rsi,rdx
     36b:	48 81 c6 00 00 31 00 	add    rsi,0x310000
     372:	8b 97 d0 00 00 00    	mov    edx,DWORD PTR [rdi+0xd0]
     378:	0f ca                	bswap  edx
     37a:	48 01 d6             	add    rsi,rdx
     37d:	48 81 c6 00 00 32 00 	add    rsi,0x320000
     384:	8b 97 d4 00 00 00    	mov    edx,DWORD PTR [rdi+0xd4]
     38a:	0f ca                	bswap  edx
     38c:	48 01 d6             	add    rsi,rdx
     38f:	48 81 c6 00 00 33 00 	add    rsi,0x330000
     396:	8b 97 d8 00 00 00    	mov    edx,DWORD PTR [rdi+0xd8]
     39c:	0f ca                	bswap  edx
     39e:	48 01 d6             	add    rsi,rdx
     3a1:	48 81 c6 00 00 34 00 	add    rsi,0x340000
     3a8:	8b 97 dc 00 00 00    	mov    edx,DWORD PTR [rdi+0xdc]
     3ae:	0f ca                	bswap  edx
     3b0:	48 01 d6             	add    rsi,rdx
     3b3:	48 81 c6 00 00 35 00 	add    rsi,0x350000
     3ba:	8b 97 e0 00 00 00    	mov    edx,DWORD PTR [rdi+0xe0]
     3c0:	0f ca                	bswap  edx
     3c2:	48 01 d6             	add    rsi,rdx
     3c5:	48 81 c6 00 00 36 00 	add    rsi,0x360000
     3cc:	8b 97 e4 00 00 00    	mov    edx,DWORD PTR [rdi+0xe4]
     3d2:	0f ca                	bswap  edx
     3d4:	48 01 d6             	add    rsi,rdx
     3d7:	48 81 c6 00 00 37 00 	add    rsi,0x370000
     3de:	8b 97 e8 00 00 00    	mov    edx,DWORD PTR [rdi+0xe8]
     3e4:	0f ca                	bswap  edx
     3e6:	48 01 d6             	add    rsi,rdx
     3e9:	48 81 c6 00 00 38 00 	add    rsi,0x380000
     3f0:	8b 97 ec 00 00 00    	mov    edx,DWORD PTR [rdi+0xec]
     3f6:	0f ca                	bswap  edx
     3f8:	48 01 d6             	add    rsi,rdx
     3fb:	48 81 c6 00 00 39 00 	add    rsi,0x390000
     402:	8b 97 f0 00 00 00    	mov    edx,DWORD PTR [rdi+0xf0]
     408:	0f ca                	bswap  edx
     40a:	48 01 d6             	add    rsi,rdx
     40d:	48 81 c6 00 00 3a 00 	add    rsi,0x3a0000
     414:	8b 97 f4 00 00 00    	mov    edx,DWORD PTR [rdi+0xf4]
     41a:	0f ca                	bswap  edx
     41c:	48 01 d6             	add    rsi,rdx
     41f:	48 81 c6 00 00 3b 00 	add    rsi,0x3b0000
     426:	8b 97 f8 00 00 00    	mov    edx,DWORD PTR [rdi+0xf8]
     42c:	0f ca                	bswap  edx
     42e:	48 01 d6             	add    rsi,rdx
     431:	48 81 c6 00 00 3c 00 	add    rsi,0x3c0000
     438:	8b 97 fc 00 00 00    	mov    edx,DWORD PTR [rdi+0xfc]
     43e:	0f ca                	bswap  edx
     440:	48 01 d6             	add    rsi,rdx
     443:	48 81 c6 00 00 3d 00 	add    rsi,0x3d0000
     44a:	8b 97 00 01 00 00    	mov    edx,DWORD PTR [rdi+0x100]
     450:	0f ca                	bswap  edx
     452:	48 01 d6             	add    rsi,rdx
     455:	48 81 c6 00 00 3e 00 	add    rsi,0x3e0000
     45c:	8b 97 04 01 00 00    	mov    edx,DWORD PTR [rdi+0x104]
     462:	0f ca                	bswap  edx
     464:	48 01 d6             	add    rsi,rdx
     467:	48 81 c6 00 00 3f 00 	add    rsi,0x3f0000
     46e:	8b 97 08 01 00 00    	mov    edx,DWORD PTR [rdi+0x108]
     474:	0f ca                	bswap  edx
     476:	48 01 d6             	add    rsi,rdx
     479:	48 81 c6 00 00 40 00 	add    rsi,0x400000
     480:	8b 97 0c 01 00 00    	mov    edx,DWORD PTR [rdi+0x10c]
     486:	0f ca                	bswap  edx
     488:	48 01 d6             	add    rsi,rdx
     48b:	48 81 c6 00 00 41 00 	add    rsi,0x410000
     492:	8b 97 10 01 00 00    	mov    edx,DWORD PTR [rdi+0x110]
     498:	0f ca                	bswap  edx
     49a:	48 01 d6             	add    rsi,rdx
     49d:	48 81 c6 00 00 42 00 	add    rsi,0x420000
     4a4:	8b 97 14 01 00 00    	mov    edx,DWORD PTR [rdi+0x114]
     4aa:	0f ca                	bswap  edx
     4ac:	48 01 d6             	add    rsi,rdx
     4af:	48 81 c6 00 00 43 00 	add    rsi,0x430000
     4b6:	8b 97 18 01 00 00    	mov    edx,DWORD PTR [rdi+0x118]
     4bc:	0f ca                	bswap  edx
     4be:	48 01 d6             	add    rsi,rdx
     4c1:	48 81 c6 00 00 44 00 	add    rsi,0x440000
     4c8:	8b 97 1c 01 00 00    	mov    edx,DWORD PTR [rdi+0x11c]
     4ce:	0f ca                	bswap  edx
     4d0:	48 01 d6             	add    rsi,rdx
     4d3:	48 81 c6 00 00 45 00 	add    rsi,0x450000
     4da:	8b 97 20 01 00 00    	mov    edx,DWORD PTR [rdi+0x120]
     4e0:	0f ca                	bswap  edx
     4e2:	48 01 d6             	add    rsi,rdx
     4e5:	48 81 c6 00 00 46 00 	add    rsi,0x460000
     4ec:	8b 97 24 01 00 00    	mov    edx,DWORD PTR [rdi+0x124]
     4f2:	0f ca                	bswap  edx
     4f4:	48 01 d6             	add    rsi,rdx
     4f7:	48 81 c6 00 00 47 00 	add    rsi,0x470000
     4fe:	8b 97 28 01 00 00    	mov    edx,DWORD PTR [rdi+0x128]
     504:	0f ca                	bswap  edx
     506:	48 01 d6             	add    rsi,rdx
     509:	48 81 c6 00 00 48 00 	add    rsi,0x480000
     510:	8b 97 2c 01 00 00    	mov    edx,DWORD PTR [rdi+0x12c]
     516:	0f ca                	bswap  edx
     518:	48 01 d6             	add    rsi,rdx
     51b:	48 81 c6 00 00 49 00 	add    rsi,0x490000
     522:	8b 97 30 01 00 00    	mov    edx,DWORD PTR [rdi+0x130]
     528:	0f ca                	bswap  edx
     52a:	48 01 d6             	add    rsi,rdx
     52d:	48 81 c6 00 00 4a 00 	add    rsi,0x4a0000
     534:	8b 97 34 01 00 00    	mov    edx,DWORD PTR [rdi+0x134]
     53a:	0f ca                	bswap  edx
     53c:	48 01 d6             	add    rsi,rdx
     53f:	48 81 c6 00 00 4b 00 	add    rsi,0x4b0000
     546:	8b 97 38 01 00 00    	mov    edx,DWORD PTR [rdi+0x138]
     54c:	0f ca                	bswap  edx
     54e:	48 01 d6             	add    rsi,rdx
     551:	48 81 c6 00 00 4c 00 	add    rsi,0x4c0000
     558:	8b 97 3c 01 00 00    	mov    edx,DWORD PTR [rdi+0x13c]
     55e:	0f ca                	bswap  edx
     560:	48 01 d6             	add    rsi,rdx
     563:	48 81 c6 00 00 4d 00 	add    rsi,0x4d0000
     56a:	8b 97 40 01 00 00    	mov    edx,DWORD PTR [rdi+0x140]
     570:	0f ca                	bswap  edx
     572:	48 01 d6             	add    rsi,rdx
     575:	48 81 c6 00 00 4e 00 	add    rsi,0x4e0000
     57c:	8b 97 44 01 00 00    	mov    edx,DWORD PTR [rdi+0x144]
     582:	0f ca                	bswap  edx
     584:	48 01 d6             	add    rsi,rdx
     587:	48 81 c6 00 00 4f 00 	add    rsi,0x4f0000
     58e:	8b 97 48 01 00 00    	mov    edx,DWORD PTR [rdi+0x148]
     594:	0f ca                	bswap  edx
     596:	48 01 d6             	add    rsi,rdx
     599:	48 81 c6 00 00 50 00 	add    rsi,0x500000
     5a0:	8b 97 4c 01 00 00    	mov    edx,DWORD PTR [rdi+0x14c]
     5a6:	0f ca                	bswap  edx
     5a8:	48 01 d6             	add    rsi,rdx
     5ab:	48 81 c6 00 00 51 00 	add    rsi,0x510000
     5b2:	8b 97 50 01 00 00    	mov    edx,DWORD PTR [rdi+0x150]
     5b8:	0f ca                	bswap  edx
     5ba:	48 01 d6             	add    rsi,rdx
     5bd:	48 81 c6 00 00 52 00 	add    rsi,0x520000
     5c4:	8b 97 54 01 00 00    	mov    edx,DWORD PTR [rdi+0x154]
     5ca:	0f ca                	bswap  edx
     5cc:	48 01 d6             	add    rsi,rdx
     5cf:	48 81 c6 00 00 53 00 	add    rsi,0x530000
     5d6:	8b 97 58 01 00 00    	mov    edx,DWORD PTR [rdi+0x158]
     5dc:	0f ca                	bswap  edx
     5de:	48 01 d6             	add    rsi,rdx
     5e1:	48 81 c6 00 00 54 00 	add    rsi,0x540000
     5e8:	8b 97 5c 01 00 00    	mov    edx,DWORD PTR [rdi+0x15c]
     5ee:	0f ca                	bswap  edx
     5f0:	48 01 d6             	add    rsi,rdx
     5f3:	48 81 c6 00 00 55 00 	add    rsi,0x550000
     5fa:	8b 97 60 01 00 00    	mov    edx,DWORD PTR [rdi+0x160]
     600:	0f ca                	bswap  edx
     602:	48 01 d6             	add    rsi,rdx
     605:	48 81 c6 00 00 56 00 	add    rsi,0x560000
     60c:	8b 97 64 01 00 00    	mov    edx,DWORD PTR [rdi+0x164]
     612:	0f ca                	bswap  edx
     614:	48 01 d6             	add    rsi,rdx
     617:	48 81 c6 00 00 57 00 	add    rsi,0x570000
     61e:	8b 97 68 01 00 00    	mov    edx,DWORD PTR [rdi+0x168]
     624:	0f ca                	bswap  edx
     626:	48 01 d6             	add    rsi,rdx
     629:	48 81 c6 00 00 58 00 	add    rsi,0x580000
     630:	8b 97 6c 01 00 00    	mov    edx,DWORD PTR [rdi+0x16c]
     636:	0f ca                	bswap  edx
     638:	48 01 d6             	add    rsi,rdx
     63b:	48 81 c6 00 00 59 00 	add    rsi,0x590000
     642:	8b 97 70 01 00 00    	mov    edx,DWORD PTR [rdi+0x170]
     648:	0f ca                	bswap  edx
     64a:	48 01 d6             	add    rsi,rdx
     64d:	48 81 c6 00 00 5a 00 	add    rsi,0x5a0000
     654:	8b 97 74 01 00 00    	mov    edx,DWORD PTR [rdi+0x174]
     65a:	0f ca                	bswap  edx
     65c:	48 01 d6             	add    rsi,rdx
     65f:	48 81 c6 00 00 5b 00 	add    rsi,0x5b0000
     666:	8b 97 78 01 00 00    	mov    edx,DWORD PTR [rdi+0x178]
     66c:	0f ca                	bswap  edx
     66e:	48 01 d6             	add    rsi,rdx
     671:	48 81 c6 00 00 5c 00 	add    rsi,0x5c0000
     678:	8b 97 7c 01 00 00    	mov    edx,DWORD PTR [rdi+0x17c]
     67e:	0f ca                	bswap  edx
     680:	48 01 d6             	add    rsi,rdx
     683:	48 81 c6 00 00 5d 00 	add    rsi,0x5d0000
     68a:	8b 97 80 01 00 00    	mov    edx,DWORD PTR [rdi+0x180]
     690:	0f ca                	bswap  edx
     692:	48 01 d6             	add    rsi,rdx
     695:	48 81 c6 00 00 5e 00 	add    rsi,0x5e0000
     69c:	8b 97 84 01 00 00    	mov    edx,DWORD PTR [rdi+0x184]
     6a2:	0f ca                	bswap  edx
     6a4:	48 01 d6             	add    rsi,rdx
     6a7:	48 81 c6 00 00 5f 00 	add    rsi,0x5f0000
     6ae:	8b 97 88 01 00 00    	mov    edx,DWORD PTR [rdi+0x188]
     6b4:	0f ca                	bswap  edx
     6b6:	48 01 d6             	add    rsi,rdx
     6b9:	48 81 c6 00 00 60 00 	add    rsi,0x600000
     6c0:	8b 97 8c 01 00 00    	mov    edx,DWORD PTR [rdi+0x18c]
     6c6:	0f ca                	bswap  edx
     6c8:	48 01 d6             	add    rsi,rdx
     6cb:	48 81 c6 00 00 61 00 	add    rsi,0x610000
     6d2:	8b 97 90 01 00 00    	mov    edx,DWORD PTR [rdi+0x190]
     6d8:	0f ca                	bswap  edx
     6da:	48 01 d6             	add    rsi,rdx
     6dd:	48 81 c6 00 00 62 00 	add    rsi,0x620000
     6e4:	8b 97 94 01 00 00    	mov    edx,DWORD PTR [rdi+0x194]
     6ea:	0f ca                	bswap  edx
     6ec:	48 01 d6             	add    rsi,rdx
     6ef:	48 81 c6 00 00 63 00 	add    rsi,0x630000
     6f6:	8b 97 98 01 00 00    	mov    edx,DWORD PTR [rdi+0x198]
     6fc:	0f ca                	bswap  edx
     6fe:	48 01 d6             	add    rsi,rdx
     701:	48 81 c6 00 00 64 00 	add    rsi,0x640000
     708:	8b 97 9c 01 00 00    	mov    edx,DWORD PTR [rdi+0x19c]
     70e:	0f ca                	bswap  edx
     710:	48 01 d6             	add    rsi,rdx
     713:	48 81 c6 00 00 65 00 	add    rsi,0x650000
     71a:	8b 97 a0 01 00 00    	mov    edx,DWORD PTR [rdi+0x1a0]
     720:	0f ca                	bswap  edx
     722:	48 01 d6             	add    rsi,rdx
     725:	48 81 c6 00 00 66 00 	add    rsi,0x660000
     72c:	8b 97 a4 01 00 00    	mov    edx,DWORD PTR [rdi+0x1a4]
     732:	0f ca                	bswap  edx
     734:	48 01 d6             	add    rsi,rdx
     737:	48 81 c6 00 00 67 00 	add    rsi,0x670000
     73e:	8b 97 a8 01 00 00    	mov    edx,DWORD PTR [rdi+0x1a8]
     744:	0f ca                	bswap  edx
     746:	48 01 d6             	add    rsi,rdx
     749:	48 81 c6 00 00 68 00 	add    rsi,0x680000
     750:	8b 97 ac 01 00 00    	mov    edx,DWORD PTR [rdi+0x1ac]
     756:	0f ca                	bswap  edx
     758:	48 01 d6             	add    rsi,rdx
     75b:	48 81 c6 00 00 69 00 	add    rsi,0x690000
     762:	8b 97 b0 01 00 00    	mov    edx,DWORD PTR [rdi+0x1b0]
     768:	0f ca                	bswap  edx
     76a:	48 01 d6             	add    rsi,rdx
     76d:	48 81 c6 00 00 6a 00 	add    rsi,0x6a0000
     774:	8b 97 b4 01 00 00    	mov    edx,DWORD PTR [rdi+0x1b4]
     77a:	0f ca                	bswap  edx
     77c:	48 01 d6             	add    rsi,rdx
     77f:	48 81 c6 00 00 6b 00 	add    rsi,0x6b0000
     786:	8b 97 b8 01 00 00    	mov    edx,DWORD PTR [rdi+0x1b8]
     78c:	0f ca                	bswap  edx
     78e:	48 01 d6             	add    rsi,rdx
     791:	48 81 c6 00 00 6c 00 	add    rsi,0x6c0000
     798:	8b 97 bc 01 00 00    	mov    edx,DWORD PTR [rdi+0x1bc]
     79e:	0f ca                	bswap  edx
     7a0:	48 01 d6             	add    rsi,rdx
     7a3:	48 81 c6 00 00 6d 00 	add    rsi,0x6d0000
     7aa:	8b 97 c0 01 00 00    	mov    edx,DWORD PTR [rdi+0x1c0]
     7b0:	0f ca                	bswap  edx
     7b2:	48 01 d6             	add    rsi,rdx
     7b5:	48 81 c6 00 00 6e 00 	add    rsi,0x6e0000
     7bc:	8b 97 c4 01 00 00    	mov    edx,DWORD PTR [rdi+0x1c4]
     7c2:	0f ca                	bswap  edx
     7c4:	48 01 d6             	add    rsi,rdx
     7c7:	48 81 c6 00 00 6f 00 	add    rsi,0x6f0000
     7ce:	8b 97 c8 01 00 00    	mov    edx,DWORD PTR [rdi+0x1c8]
     7d4:	0f ca                	bswap  edx
     7d6:	48 01 d6             	add    rsi,rdx
     7d9:	48 81 c6 00 00 70 00 	add    rsi,0x700000
     7e0:	8b 97 cc 01 00 00    	mov    edx,DWORD PTR [rdi+0x1cc]
     7e6:	0f ca                	bswap  edx
     7e8:	48 01 d6             	add    rsi,rdx
     7eb:	48 81 c6 00 00 71 00 	add    rsi,0x710000
     7f2:	8b 97 d0 01 00 00    	mov    edx,DWORD PTR [rdi+0x1d0]
     7f8:	0f ca                	bswap  edx
     7fa:	48 01 d6             	add    rsi,rdx
     7fd:	48 81 c6 00 00 72 00 	add    rsi,0x720000
     804:	8b 97 d4 01 00 00    	mov    edx,DWORD PTR [rdi+0x1d4]
     80a:	0f ca                	bswap  edx
     80c:	48 01 d6             	add    rsi,rdx
     80f:	48 81 c6 00 00 73 00 	add    rsi,0x730000
     816:	8b 97 d8 01 00 00    	mov    edx,DWORD PTR [rdi+0x1d8]
     81c:	0f ca                	bswap  edx
     81e:	48 01 d6             	add    rsi,rdx
     821:	48 81 c6 00 00 74 00 	add    rsi,0x740000
     828:	8b 97 dc 01 00 00    	mov    edx,DWORD PTR [rdi+0x1dc]
     82e:	0f ca                	bswap  edx
     830:	48 01 d6             	add    rsi,rdx
     833:	48 81 c6 00 00 75 00 	add    rsi,0x750000
     83a:	8b 97 e0 01 00 00    	mov    edx,DWORD PTR [rdi+0x1e0]
     840:	0f ca                	bswap  edx
     842:	48 01 d6             	add    rsi,rdx
     845:	48 81 c6 00 00 76 00 	add    rsi,0x760000
     84c:	8b 97 e4 01 00 00    	mov    edx,DWORD PTR [rdi+0x1e4]
     852:	0f ca                	bswap  edx
     854:	48 01 d6             	add    rsi,rdx
     857:	48 81 c6 00 00 77 00 	add    rsi,0x770000
     85e:	8b 97 e8 01 00 00    	mov    edx,DWORD PTR [rdi+0x1e8]
     864:	0f ca                	bswap  edx
     866:	48 01 d6             	add    rsi,rdx
     869:	48 81 c6 00 00 78 00 	add    rsi,0x780000
     870:	8b 97 ec 01 00 00    	mov    edx,DWORD PTR [rdi+0x1ec]
     876:	0f ca                	bswap  edx
     878:	48 01 d6             	add    rsi,rdx
     87b:	48 81 c6 00 00 79 00 	add    rsi,0x790000
     882:	8b 97 f0 01 00 00    	mov    edx,DWORD PTR [rdi+0x1f0]
     888:	0f ca                	bswap  edx
     88a:	48 01 d6             	add    rsi,rdx
     88d:	48 81 c6 00 00 7a 00 	add    rsi,0x7a0000
     894:	8b 97 f4 01 00 00    	mov    edx,DWORD PTR [rdi+0x1f4]
     89a:	0f ca                	bswap  edx
     89c:	48 01 d6             	add    rsi,rdx
     89f:	48 81 c6 00 00 7b 00 	add    rsi,0x7b0000
     8a6:	8b 97 f8 01 00 00    	mov    edx,DWORD PTR [rdi+0x1f8]
     8ac:	0f ca                	bswap  edx
     8ae:	48 01 d6             	add    rsi,rdx
     8b1:	48 81 c6 00 00 7c 00 	add    rsi,0x7c0000
     8b8:	8b 97 fc 01 00 00    	mov    edx,DWORD PTR [rdi+0x1fc]
     8be:	0f ca                	bswap  edx
     8c0:	48 01 d6             	add    rsi,rdx
     8c3:	48 81 c6 00 00 7d 00 	add    rsi,0x7d0000
     8ca:	8b 97 00 02 00 00    	mov    edx,DWORD PTR [rdi+0x200]
     8d0:	0f ca                	bswap  edx
     8d2:	48 01 d6             	add    rsi,rdx
     8d5:	48 81 c6 00 00 7e 00 	add    rsi,0x7e0000
     8dc:	8b 97 04 02 00 00    	mov    edx,DWORD PTR [rdi+0x204]
     8e2:	0f ca                	bswap  edx
     8e4:	48 01 d6             	add    rsi,rdx
     8e7:	48 81 c6 00 00 7f 00 	add    rsi,0x7f0000
     8ee:	8b 97 08 02 00 00    	mov    edx,DWORD PTR [rdi+0x208]
     8f4:	0f ca                	bswap  edx
     8f6:	48 01 d6             	add    rsi,rdx
     8f9:	48 81 c6 00 00 80 00 	add    rsi,0x800000
     900:	8b 97 0c 02 00 00    	mov    edx,DWORD PTR [rdi+0x20c]
     906:	0f ca                	bswap  edx
     908:	48 01 d6             	add    rsi,rdx
     90b:	48 81 c6 00 00 81 00 	add    rsi,0x810000
     912:	8b 97 10 02 00 00    	mov    edx,DWORD PTR [rdi+0x210]
     918:	0f ca                	bswap  edx
     91a:	48 01 d6             	add    rsi,rdx
     91d:	48 81 c6 00 00 82 00 	add    rsi,0x820000
     924:	8b 97 14 02 00 00    	mov    edx,DWORD PTR [rdi+0x214]
     92a:	0f ca                	bswap  edx
     92c:	48 01 d6             	add    rsi,rdx
     92f:	48 81 c6 00 00 83 00 	add    rsi,0x830000
     936:	8b 97 18 02 00 00    	mov    edx,DWORD PTR [rdi+0x218]
     93c:	0f ca                	bswap  edx
     93e:	48 01 d6             	add    rsi,rdx
     941:	48 81 c6 00 00 84 00 	add    rsi,0x840000
     948:	8b 97 1c 02 00 00    	mov    edx,DWORD PTR [rdi+0x21c]
     94e:	0f ca                	bswap  edx
     950:	48 01 d6             	add    rsi,rdx
     953:	48 81 c6 00 00 85 00 	add    rsi,0x850000
     95a:	8b 97 20 02 00 00    	mov    edx,DWORD PTR [rdi+0x220]
     960:	0f ca                	bswap  edx
     962:	48 01 d6             	add    rsi,rdx
     965:	48 81 c6 00 00 86 00 	add    rsi,0x860000
     96c:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [rdi+0x224]
     972:	0f ca                	bswap  edx
     974:	48 01 d6             	add    rsi,rdx
     977:	48 81 c6 00 00 87 00 	add    rsi,0x870000
     97e:	8b 97 28 02 00 00    	mov    edx,DWORD PTR [rdi+0x228]
     984:	0f ca                	bswap  edx
     986:	48 01 d6             	add    rsi,rdx
     989:	48 81 c6 00 00 88 00 	add    rsi,0x880000
     990:	8b 97 2c 02 00 00    	mov    edx,DWORD PTR [rdi+0x22c]
     996:	0f ca                	bswap  edx
     998:	48 01 d6             	add    rsi,rdx
     99b:	48 81 c6 00 00 89 00 	add    rsi,0x890000
     9a2:	8b 97 30 02 00 00    	mov    edx,DWORD PTR [rdi+0x230]
     9a8:	0f ca                	bswap  edx
     9aa:	48 01 d6             	add    rsi,rdx
     9ad:	48 81 c6 00 00 8a 00 	add    rsi,0x8a0000
     9b4:	8b 97 34 02 00 00    	mov    edx,DWORD PTR [rdi+0x234]
     9ba:	0f ca                	bswap  edx
     9bc:	48 01 d6             	add    rsi,rdx
     9bf:	48 81 c6 00 00 8b 00 	add    rsi,0x8b0000
     9c6:	8b 97 38 02 00 00    	mov    edx,DWORD PTR [rdi+0x238]
     9cc:	0f ca                	bswap  edx
     9ce:	48 01 d6             	add    rsi,rdx
     9d1:	48 81 c6 00 00 8c 00 	add    rsi,0x8c0000
     9d8:	8b 97 3c 02 00 00    	mov    edx,DWORD PTR [rdi+0x23c]
     9de:	0f ca                	bswap  edx
     9e0:	48 01 d6             	add    rsi,rdx
     9e3:	48 81 c6 00 00 8d 00 	add    rsi,0x8d0000
     9ea:	8b 97 40 02 00 00    	mov    edx,DWORD PTR [rdi+0x240]
     9f0:	0f ca                	bswap  edx
     9f2:	48 01 d6             	add    rsi,rdx
     9f5:	48 81 c6 00 00 8e 00 	add    rsi,0x8e0000
     9fc:	8b 97 44 02 00 00    	mov    edx,DWORD PTR [rdi+0x244]
     a02:	0f ca                	bswap  edx
     a04:	48 01 d6             	add    rsi,rdx
     a07:	48 81 c6 00 00 8f 00 	add    rsi,0x8f0000
     a0e:	8b 97 48 02 00 00    	mov    edx,DWORD PTR [rdi+0x248]
     a14:	0f ca                	bswap  edx
     a16:	48 01 d6             	add    rsi,rdx
     a19:	48 81 c6 00 00 90 00 	add    rsi,0x900000
     a20:	8b 97 4c 02 00 00    	mov    edx,DWORD PTR [rdi+0x24c]
     a26:	0f ca                	bswap  edx
     a28:	48 01 d6             	add    rsi,rdx
     a2b:	48 81 c6 00 00 91 00 	add    rsi,0x910000
     a32:	8b 97 50 02 00 00    	mov    edx,DWORD PTR [rdi+0x250]
     a38:	0f ca                	bswap  edx
     a3a:	48 01 d6             	add    rsi,rdx
     a3d:	48 81 c6 00 00 92 00 	add    rsi,0x920000
     a44:	8b 97 54 02 00 00    	mov    edx,DWORD PTR [rdi+0x254]
     a4a:	0f ca                	bswap  edx
     a4c:	48 01 d6             	add    rsi,rdx
     a4f:	48 81 c6 00 00 93 00 	add    rsi,0x930000
     a56:	8b 97 58 02 00 00    	mov    edx,DWORD PTR [rdi+0x258]
     a5c:	0f ca                	bswap  edx
     a5e:	48 01 d6             	add    rsi,rdx
     a61:	48 81 c6 00 00 94 00 	add    rsi,0x940000
     a68:	8b 97 5c 02 00 00    	mov    edx,DWORD PTR [rdi+0x25c]
     a6e:	0f ca                	bswap  edx
     a70:	48 01 d6             	add    rsi,rdx
     a73:	48 81 c6 00 00 95 00 	add    rsi,0x950000
     a7a:	8b 97 60 02 00 00    	mov    edx,DWORD PTR [rdi+0x260]
     a80:	0f ca                	bswap  edx
     a82:	48 01 d6             	add    rsi,rdx
     a85:	48 81 c6 00 00 96 00 	add    rsi,0x960000
     a8c:	8b 97 64 02 00 00    	mov    edx,DWORD PTR [rdi+0x264]
     a92:	0f ca                	bswap  edx
     a94:	48 01 d6             	add    rsi,rdx
     a97:	48 81 c6 00 00 97 00 	add    rsi,0x970000
     a9e:	8b 97 68 02 00 00    	mov    edx,DWORD PTR [rdi+0x268]
     aa4:	0f ca                	bswap  edx
     aa6:	48 01 d6             	add    rsi,rdx
     aa9:	48 81 c6 00 00 98 00 	add    rsi,0x980000
     ab0:	8b 97 6c 02 00 00    	mov    edx,DWORD PTR [rdi+0x26c]
     ab6:	0f ca                	bswap  edx
     ab8:	48 01 d6             	add    rsi,rdx
     abb:	48 81 c6 00 00 99 00 	add    rsi,0x990000
     ac2:	8b 97 70 02 00 00    	mov    edx,DWORD PTR [rdi+0x270]
     ac8:	0f ca                	bswap  edx
     aca:	48 01 d6             	add    rsi,rdx
     acd:	48 81 c6 00 00 9a 00 	add    rsi,0x9a0000
     ad4:	8b 97 74 02 00 00    	mov    edx,DWORD PTR [rdi+0x274]
     ada:	0f ca                	bswap  edx
     adc:	48 01 d6             	add    rsi,rdx
     adf:	48 81 c6 00 00 9b 00 	add    rsi,0x9b0000
     ae6:	8b 97 78 02 00 00    	mov    edx,DWORD PTR [rdi+0x278]
     aec:	0f ca                	bswap  edx
     aee:	48 01 d6             	add    rsi,rdx
     af1:	48 81 c6 00 00 9c 00 	add    rsi,0x9c0000
     af8:	8b 97 7c 02 00 00    	mov    edx,DWORD PTR [rdi+0x27c]
     afe:	0f ca                	bswap  edx
     b00:	48 01 d6             	add    rsi,rdx
     b03:	48 81 c6 00 00 9d 00 	add    rsi,0x9d0000
     b0a:	8b 97 80 02 00 00    	mov    edx,DWORD PTR [rdi+0x280]
     b10:	0f ca                	bswap  edx
     b12:	48 01 d6             	add    rsi,rdx
     b15:	48 81 c6 00 00 9e 00 	add    rsi,0x9e0000
     b1c:	8b 97 84 02 00 00    	mov    edx,DWORD PTR [rdi+0x284]
     b22:	0f ca                	bswap  edx
     b24:	48 01 d6             	add    rsi,rdx
     b27:	48 81 c6 00 00 9f 00 	add    rsi,0x9f0000
     b2e:	8b 97 88 02 00 00    	mov    edx,DWORD PTR [rdi+0x288]
     b34:	0f ca                	bswap  edx
     b36:	48 01 d6             	add    rsi,rdx
     b39:	48 81 c6 00 00 a0 00 	add    rsi,0xa00000
     b40:	8b 97 8c 02 00 00    	mov    edx,DWORD PTR [rdi+0x28c]
     b46:	0f ca                	bswap  edx
     b48:	48 01 d6             	add    rsi,rdx
     b4b:	48 81 c6 00 00 a1 00 	add    rsi,0xa10000
     b52:	8b 97 90 02 00 00    	mov    edx,DWORD PTR [rdi+0x290]
     b58:	0f ca                	bswap  edx
     b5a:	48 01 d6             	add    rsi,rdx
     b5d:	48 81 c6 00 00 a2 00 	add    rsi,0xa20000
     b64:	8b 97 94 02 00 00    	mov    edx,DWORD PTR [rdi+0x294]
     b6a:	0f ca                	bswap  edx
     b6c:	48 01 d6             	add    rsi,rdx
     b6f:	48 81 c6 00 00 a3 00 	add    rsi,0xa30000
     b76:	8b 97 98 02 00 00    	mov    edx,DWORD PTR [rdi+0x298]
     b7c:	0f ca                	bswap  edx
     b7e:	48 01 d6             	add    rsi,rdx
     b81:	48 81 c6 00 00 a4 00 	add    rsi,0xa40000
     b88:	8b 97 9c 02 00 00    	mov    edx,DWORD PTR [rdi+0x29c]
     b8e:	0f ca                	bswap  edx
     b90:	48 01 d6             	add    rsi,rdx
     b93:	48 81 c6 00 00 a5 00 	add    rsi,0xa50000
     b9a:	8b 97 a0 02 00 00    	mov    edx,DWORD PTR [rdi+0x2a0]
     ba0:	0f ca                	bswap  edx
     ba2:	48 01 d6             	add    rsi,rdx
     ba5:	48 81 c6 00 00 a6 00 	add    rsi,0xa60000
     bac:	8b 97 a4 02 00 00    	mov    edx,DWORD PTR [rdi+0x2a4]
     bb2:	0f ca                	bswap  edx
     bb4:	48 01 d6             	add    rsi,rdx
     bb7:	48 81 c6 00 00 a7 00 	add    rsi,0xa70000
     bbe:	8b 97 a8 02 00 00    	mov    edx,DWORD PTR [rdi+0x2a8]
     bc4:	0f ca                	bswap  edx
     bc6:	48 01 d6             	add    rsi,rdx
     bc9:	48 81 c6 00 00 a8 00 	add    rsi,0xa80000
     bd0:	8b 97 ac 02 00 00    	mov    edx,DWORD PTR [rdi+0x2ac]
     bd6:	0f ca                	bswap  edx
     bd8:	48 01 d6             	add    rsi,rdx
     bdb:	48 81 c6 00 00 a9 00 	add    rsi,0xa90000
     be2:	8b 97 b0 02 00 00    	mov    edx,DWORD PTR [rdi+0x2b0]
     be8:	0f ca                	bswap  edx
     bea:	48 01 d6             	add    rsi,rdx
     bed:	48 81 c6 00 00 aa 00 	add    rsi,0xaa0000
     bf4:	8b 97 b4 02 00 00    	mov    edx,DWORD PTR [rdi+0x2b4]
     bfa:	0f ca                	bswap  edx
     bfc:	48 01 d6             	add    rsi,rdx
     bff:	48 81 c6 00 00 ab 00 	add    rsi,0xab0000
     c06:	8b 97 b8 02 00 00    	mov    edx,DWORD PTR [rdi+0x2b8]
     c0c:	0f ca                	bswap  edx
     c0e:	48 01 d6             	add    rsi,rdx
     c11:	48 81 c6 00 00 ac 00 	add    rsi,0xac0000
     c18:	8b 97 bc 02 00 00    	mov    edx,DWORD PTR [rdi+0x2bc]
     c1e:	0f ca                	bswap  edx
     c20:	48 01 d6             	add    rsi,rdx
     c23:	48 81 c6 00 00 ad 00 	add    rsi,0xad0000
     c2a:	8b 97 c0 02 00 00    	mov    edx,DWORD PTR [rdi+0x2c0]
     c30:	0f ca                	bswap  edx
     c32:	48 01 d6             	add    rsi,rdx
     c35:	48 81 c6 00 00 ae 00 	add    rsi,0xae0000
     c3c:	8b 97 c4 02 00 00    	mov    edx,DWORD PTR [rdi+0x2c4]
     c42:	0f ca                	bswap  edx
     c44:	48 01 d6             	add    rsi,rdx
     c47:	48 81 c6 00 00 af 00 	add    rsi,0xaf0000
     c4e:	8b 97 c8 02 00 00    	mov    edx,DWORD PTR [rdi+0x2c8]
     c54:	0f ca                	bswap  edx
     c56:	48 01 d6             	add    rsi,rdx
     c59:	48 81 c6 00 00 b0 00 	add    rsi,0xb00000
     c60:	8b 97 cc 02 00 00    	mov    edx,DWORD PTR [rdi+0x2cc]
     c66:	0f ca                	bswap  edx
     c68:	48 01 d6             	add    rsi,rdx
     c6b:	48 81 c6 00 00 b1 00 	add    rsi,0xb10000
     c72:	8b 97 d0 02 00 00    	mov    edx,DWORD PTR [rdi+0x2d0]
     c78:	0f ca                	bswap  edx
     c7a:	48 01 d6             	add    rsi,rdx
     c7d:	48 81 c6 00 00 b2 00 	add    rsi,0xb20000
     c84:	8b 97 d4 02 00 00    	mov    edx,DWORD PTR [rdi+0x2d4]
     c8a:	0f ca                	bswap  edx
     c8c:	48 01 d6             	add    rsi,rdx
     c8f:	48 81 c6 00 00 b3 00 	add    rsi,0xb30000
     c96:	8b 97 d8 02 00 00    	mov    edx,DWORD PTR [rdi+0x2d8]
     c9c:	0f ca                	bswap  edx
     c9e:	48 01 d6             	add    rsi,rdx
     ca1:	48 81 c6 00 00 b4 00 	add    rsi,0xb40000
     ca8:	8b 97 dc 02 00 00    	mov    edx,DWORD PTR [rdi+0x2dc]
     cae:	0f ca                	bswap  edx
     cb0:	48 01 d6             	add    rsi,rdx
     cb3:	48 81 c6 00 00 b5 00 	add    rsi,0xb50000
     cba:	8b 97 e0 02 00 00    	mov    edx,DWORD PTR [rdi+0x2e0]
     cc0:	0f ca                	bswap  edx
     cc2:	48 01 d6             	add    rsi,rdx
     cc5:	48 81 c6 00 00 b6 00 	add    rsi,0xb60000
     ccc:	8b 97 e4 02 00 00    	mov    edx,DWORD PTR [rdi+0x2e4]
     cd2:	0f ca                	bswap  edx
     cd4:	48 01 d6             	add    rsi,rdx
     cd7:	48 81 c6 00 00 b7 00 	add    rsi,0xb70000
     cde:	8b 97 e8 02 00 00    	mov    edx,DWORD PTR [rdi+0x2e8]
     ce4:	0f ca                	bswap  edx
     ce6:	48 01 d6             	add    rsi,rdx
     ce9:	48 81 c6 00 00 b8 00 	add    rsi,0xb80000
     cf0:	8b 97 ec 02 00 00    	mov    edx,DWORD PTR [rdi+0x2ec]
     cf6:	0f ca                	bswap  edx
     cf8:	48 01 d6             	add    rsi,rdx
     cfb:	48 81 c6 00 00 b9 00 	add    rsi,0xb90000
     d02:	8b 97 f0 02 00 00    	mov    edx,DWORD PTR [rdi+0x2f0]
     d08:	0f ca                	bswap  edx
     d0a:	48 01 d6             	add    rsi,rdx
     d0d:	48 81 c6 00 00 ba 00 	add    rsi,0xba0000
     d14:	8b 97 f4 02 00 00    	mov    edx,DWORD PTR [rdi+0x2f4]
     d1a:	0f ca                	bswap  edx
     d1c:	48 01 d6             	add    rsi,rdx
     d1f:	48 81 c6 00 00 bb 00 	add    rsi,0xbb0000
     d26:	8b 97 f8 02 00 00    	mov    edx,DWORD PTR [rdi+0x2f8]
     d2c:	0f ca                	bswap  edx
     d2e:	48 01 d6             	add    rsi,rdx
     d31:	48 81 c6 00 00 bc 00 	add    rsi,0xbc0000
     d38:	8b 97 fc 02 00 00    	mov    edx,DWORD PTR [rdi+0x2fc]
     d3e:	0f ca                	bswap  edx
     d40:	48 01 d6             	add    rsi,rdx
     d43:	48 81 c6 00 00 bd 00 	add    rsi,0xbd0000
     d4a:	8b 97 00 03 00 00    	mov    edx,DWORD PTR [rdi+0x300]
     d50:	0f ca                	bswap  edx
     d52:	48 01 d6             	add    rsi,rdx
     d55:	48 81 c6 00 00 be 00 	add    rsi,0xbe0000
     d5c:	8b 97 04 03 00 00    	mov    edx,DWORD PTR [rdi+0x304]
     d62:	0f ca                	bswap  edx
     d64:	48 01 d6             	add    rsi,rdx
     d67:	48 81 c6 00 00 bf 00 	add    rsi,0xbf0000
     d6e:	8b 97 08 03 00 00    	mov    edx,DWORD PTR [rdi+0x308]
     d74:	0f ca                	bswap  edx
     d76:	48 01 d6             	add    rsi,rdx
     d79:	48 81 c6 00 00 c0 00 	add    rsi,0xc00000
     d80:	8b 97 0c 03 00 00    	mov    edx,DWORD PTR [rdi+0x30c]
     d86:	0f ca                	bswap  edx
     d88:	48 01 d6             	add    rsi,rdx
     d8b:	48 81 c6 00 00 c1 00 	add    rsi,0xc10000
     d92:	8b 97 10 03 00 00    	mov    edx,DWORD PTR [rdi+0x310]
     d98:	0f ca                	bswap  edx
     d9a:	48 01 d6             	add    rsi,rdx
     d9d:	48 81 c6 00 00 c2 00 	add    rsi,0xc20000
     da4:	8b 97 14 03 00 00    	mov    edx,DWORD PTR [rdi+0x314]
     daa:	0f ca                	bswap  edx
     dac:	48 01 d6             	add    rsi,rdx
     daf:	48 81 c6 00 00 c3 00 	add    rsi,0xc30000
     db6:	8b 97 18 03 00 00    	mov    edx,DWORD PTR [rdi+0x318]
     dbc:	0f ca                	bswap  edx
     dbe:	48 01 d6             	add    rsi,rdx
     dc1:	48 81 c6 00 00 c4 00 	add    rsi,0xc40000
     dc8:	8b 97 1c 03 00 00    	mov    edx,DWORD PTR [rdi+0x31c]
     dce:	0f ca                	bswap  edx
     dd0:	48 01 d6             	add    rsi,rdx
     dd3:	48 81 c6 00 00 c5 00 	add    rsi,0xc50000
     dda:	8b 97 20 03 00 00    	mov    edx,DWORD PTR [rdi+0x320]
     de0:	0f ca                	bswap  edx
     de2:	48 01 d6             	add    rsi,rdx
     de5:	48 81 c6 00 00 c6 00 	add    rsi,0xc60000
     dec:	8b 97 24 03 00 00    	mov    edx,DWORD PTR [rdi+0x324]
     df2:	0f ca                	bswap  edx
     df4:	48 01 d6             	add    rsi,rdx
     df7:	48 81 c6 00 00 c7 00 	add    rsi,0xc70000
     dfe:	8b 97 28 03 00 00    	mov    edx,DWORD PTR [rdi+0x328]
     e04:	0f ca                	bswap  edx
     e06:	48 01 d6             	add    rsi,rdx
     e09:	48 81 c6 00 00 c8 00 	add    rsi,0xc80000
     e10:	8b 97 2c 03 00 00    	mov    edx,DWORD PTR [rdi+0x32c]
     e16:	0f ca                	bswap  edx
     e18:	48 01 d6             	add    rsi,rdx
     e1b:	48 81 c6 00 00 c9 00 	add    rsi,0xc90000
     e22:	8b 97 30 03 00 00    	mov    edx,DWORD PTR [rdi+0x330]
     e28:	0f ca                	bswap  edx
     e2a:	48 01 d6             	add    rsi,rdx
     e2d:	48 81 c6 00 00 ca 00 	add    rsi,0xca0000
     e34:	8b 97 34 03 00 00    	mov    edx,DWORD PTR [rdi+0x334]
     e3a:	0f ca                	bswap  edx
     e3c:	48 01 d6             	add    rsi,rdx
     e3f:	48 81 c6 00 00 cb 00 	add    rsi,0xcb0000
     e46:	8b 97 38 03 00 00    	mov    edx,DWORD PTR [rdi+0x338]
     e4c:	0f ca                	bswap  edx
     e4e:	48 01 d6             	add    rsi,rdx
     e51:	48 81 c6 00 00 cc 00 	add    rsi,0xcc0000
     e58:	8b 97 3c 03 00 00    	mov    edx,DWORD PTR [rdi+0x33c]
     e5e:	0f ca                	bswap  edx
     e60:	48 01 d6             	add    rsi,rdx
     e63:	48 81 c6 00 00 cd 00 	add    rsi,0xcd0000
     e6a:	8b 97 40 03 00 00    	mov    edx,DWORD PTR [rdi+0x340]
     e70:	0f ca                	bswap  edx
     e72:	48 01 d6             	add    rsi,rdx
     e75:	48 81 c6 00 00 ce 00 	add    rsi,0xce0000
     e7c:	8b 97 44 03 00 00    	mov    edx,DWORD PTR [rdi+0x344]
     e82:	0f ca                	bswap  edx
     e84:	48 01 d6             	add    rsi,rdx
     e87:	48 81 c6 00 00 cf 00 	add    rsi,0xcf0000
     e8e:	8b 97 48 03 00 00    	mov    edx,DWORD PTR [rdi+0x348]
     e94:	0f ca                	bswap  edx
     e96:	48 01 d6             	add    rsi,rdx
     e99:	48 81 c6 00 00 d0 00 	add    rsi,0xd00000
     ea0:	8b 97 4c 03 00 00    	mov    edx,DWORD PTR [rdi+0x34c]
     ea6:	0f ca                	bswap  edx
     ea8:	48 01 d6             	add    rsi,rdx
     eab:	48 81 c6 00 00 d1 00 	add    rsi,0xd10000
     eb2:	8b 97 50 03 00 00    	mov    edx,DWORD PTR [rdi+0x350]
     eb8:	0f ca                	bswap  edx
     eba:	48 01 d6             	add    rsi,rdx
     ebd:	48 81 c6 00 00 d2 00 	add    rsi,0xd20000
     ec4:	8b 97 54 03 00 00    	mov    edx,DWORD PTR [rdi+0x354]
     eca:	0f ca                	bswap  edx
     ecc:	48 01 d6             	add    rsi,rdx
     ecf:	48 81 c6 00 00 d3 00 	add    rsi,0xd30000
     ed6:	8b 97 58 03 00 00    	mov    edx,DWORD PTR [rdi+0x358]
     edc:	0f ca                	bswap  edx
     ede:	48 01 d6             	add    rsi,rdx
     ee1:	48 81 c6 00 00 d4 00 	add    rsi,0xd40000
     ee8:	8b 97 5c 03 00 00    	mov    edx,DWORD PTR [rdi+0x35c]
     eee:	0f ca                	bswap  edx
     ef0:	48 01 d6             	add    rsi,rdx
     ef3:	48 81 c6 00 00 d5 00 	add    rsi,0xd50000
     efa:	8b 97 60 03 00 00    	mov    edx,DWORD PTR [rdi+0x360]
     f00:	0f ca                	bswap  edx
     f02:	48 01 d6             	add    rsi,rdx
     f05:	48 81 c6 00 00 d6 00 	add    rsi,0xd60000
     f0c:	8b 97 64 03 00 00    	mov    edx,DWORD PTR [rdi+0x364]
     f12:	0f ca                	bswap  edx
     f14:	48 01 d6             	add    rsi,rdx
     f17:	48 81 c6 00 00 d7 00 	add    rsi,0xd70000
     f1e:	8b 97 68 03 00 00    	mov    edx,DWORD PTR [rdi+0x368]
     f24:	0f ca                	bswap  edx
     f26:	48 01 d6             	add    rsi,rdx
     f29:	48 81 c6 00 00 d8 00 	add    rsi,0xd80000
     f30:	8b 97 6c 03 00 00    	mov    edx,DWORD PTR [rdi+0x36c]
     f36:	0f ca                	bswap  edx
     f38:	48 01 d6             	add    rsi,rdx
     f3b:	48 81 c6 00 00 d9 00 	add    rsi,0xd90000
     f42:	8b 97 70 03 00 00    	mov    edx,DWORD PTR [rdi+0x370]
     f48:	0f ca                	bswap  edx
     f4a:	48 01 d6             	add    rsi,rdx
     f4d:	48 81 c6 00 00 da 00 	add    rsi,0xda0000
     f54:	8b 97 74 03 00 00    	mov    edx,DWORD PTR [rdi+0x374]
     f5a:	0f ca                	bswap  edx
     f5c:	48 01 d6             	add    rsi,rdx
     f5f:	48 81 c6 00 00 db 00 	add    rsi,0xdb0000
     f66:	8b 97 78 03 00 00    	mov    edx,DWORD PTR [rdi+0x378]
     f6c:	0f ca                	bswap  edx
     f6e:	48 01 d6             	add    rsi,rdx
     f71:	48 81 c6 00 00 dc 00 	add    rsi,0xdc0000
     f78:	8b 97 7c 03 00 00    	mov    edx,DWORD PTR [rdi+0x37c]
     f7e:	0f ca                	bswap  edx
     f80:	48 01 d6             	add    rsi,rdx
     f83:	48 81 c6 00 00 dd 00 	add    rsi,0xdd0000
     f8a:	8b 97 80 03 00 00    	mov    edx,DWORD PTR [rdi+0x380]
     f90:	0f ca                	bswap  edx
     f92:	48 01 d6             	add    rsi,rdx
     f95:	48 81 c6 00 00 de 00 	add    rsi,0xde0000
     f9c:	8b 97 84 03 00 00    	mov    edx,DWORD PTR [rdi+0x384]
     fa2:	0f ca                	bswap  edx
     fa4:	48 01 d6             	add    rsi,rdx
     fa7:	48 81 c6 00 00 df 00 	add    rsi,0xdf0000
     fae:	8b 97 88 03 00 00    	mov    edx,DWORD PTR [rdi+0x388]
     fb4:	0f ca                	bswap  edx
     fb6:	48 01 d6             	add    rsi,rdx
     fb9:	48 81 c6 00 00 e0 00 	add    rsi,0xe00000
     fc0:	8b 97 8c 03 00 00    	mov    edx,DWORD PTR [rdi+0x38c]
     fc6:	0f ca                	bswap  edx
     fc8:	48 01 d6             	add    rsi,rdx
     fcb:	48 81 c6 00 00 e1 00 	add    rsi,0xe10000
     fd2:	8b 97 90 03 00 00    	mov    edx,DWORD PTR [rdi+0x390]
     fd8:	0f ca                	bswap  edx
     fda:	48 01 d6             	add    rsi,rdx
     fdd:	48 81 c6 00 00 e2 00 	add    rsi,0xe20000
     fe4:	8b 97 94 03 00 00    	mov    edx,DWORD PTR [rdi+0x394]
     fea:	0f ca                	bswap  edx
     fec:	48 01 d6             	add    rsi,rdx
     fef:	48 81 c6 00 00 e3 00 	add    rsi,0xe30000
     ff6:	8b 97 98 03 00 00    	mov    edx,DWORD PTR [rdi+0x398]
     ffc:	0f ca                	bswap  edx
     ffe:	48 01 d6             	add    rsi,rdx
    1001:	48 81 c6 00 00 e4 00 	add    rsi,0xe40000
    1008:	8b 97 9c 03 00 00    	mov    edx,DWORD PTR [rdi+0x39c]
    100e:	0f ca                	bswap  edx
    1010:	48 01 d6             	add    rsi,rdx
    1013:	48 81 c6 00 00 e5 00 	add    rsi,0xe50000
    101a:	8b 97 a0 03 00 00    	mov    edx,DWORD PTR [rdi+0x3a0]
    1020:	0f ca                	bswap  edx
    1022:	48 01 d6             	add    rsi,rdx
    1025:	48 81 c6 00 00 e6 00 	add    rsi,0xe60000
    102c:	8b 97 a4 03 00 00    	mov    edx,DWORD PTR [rdi+0x3a4]
    1032:	0f ca                	bswap  edx
    1034:	48 01 d6             	add    rsi,rdx
    1037:	48 81 c6 00 00 e7 00 	add    rsi,0xe70000
    103e:	8b 97 a8 03 00 00    	mov    edx,DWORD PTR [rdi+0x3a8]
    1044:	0f ca                	bswap  edx
    1046:	48 01 d6             	add    rsi,rdx
    1049:	48 81 c6 00 00 e8 00 	add    rsi,0xe80000
    1050:	8b 97 ac 03 00 00    	mov    edx,DWORD PTR [rdi+0x3ac]
    1056:	0f ca                	bswap  edx
    1058:	48 01 d6             	add    rsi,rdx
    105b:	48 81 c6 00 00 e9 00 	add    rsi,0xe90000
    1062:	8b 97 b0 03 00 00    	mov    edx,DWORD PTR [rdi+0x3b0]
    1068:	0f ca                	bswap  edx
    106a:	48 01 d6             	add    rsi,rdx
    106d:	48 81 c6 00 00 ea 00 	add    rsi,0xea0000
    1074:	8b 97 b4 03 00 00    	mov    edx,DWORD PTR [rdi+0x3b4]
    107a:	0f ca                	bswap  edx
    107c:	48 01 d6             	add    rsi,rdx
    107f:	48 81 c6 00 00 eb 00 	add    rsi,0xeb0000
    1086:	8b 97 b8 03 00 00    	mov    edx,DWORD PTR [rdi+0x3b8]
    108c:	0f ca                	bswap  edx
    108e:	48 01 d6             	add    rsi,rdx
    1091:	48 81 c6 00 00 ec 00 	add    rsi,0xec0000
    1098:	8b 97 bc 03 00 00    	mov    edx,DWORD PTR [rdi+0x3bc]
    109e:	0f ca                	bswap  edx
    10a0:	48 01 d6             	add    rsi,rdx
    10a3:	48 81 c6 00 00 ed 00 	add    rsi,0xed0000
    10aa:	8b 97 c0 03 00 00    	mov    edx,DWORD PTR [rdi+0x3c0]
    10b0:	0f ca                	bswap  edx
    10b2:	48 01 d6             	add    rsi,rdx
    10b5:	48 81 c6 00 00 ee 00 	add    rsi,0xee0000
    10bc:	8b 97 c4 03 00 00    	mov    edx,DWORD PTR [rdi+0x3c4]
    10c2:	0f ca                	bswap  edx
    10c4:	48 01 d6             	add    rsi,rdx
    10c7:	48 81 c6 00 00 ef 00 	add    rsi,0xef0000
    10ce:	8b 97 c8 03 00 00    	mov    edx,DWORD PTR [rdi+0x3c8]
    10d4:	0f ca                	bswap  edx
    10d6:	48 01 d6             	add    rsi,rdx
    10d9:	48 81 c6 00 00 f0 00 	add    rsi,0xf00000
    10e0:	8b 97 cc 03 00 00    	mov    edx,DWORD PTR [rdi+0x3cc]
    10e6:	0f ca                	bswap  edx
    10e8:	48 01 d6             	add    rsi,rdx
    10eb:	48 81 c6 00 00 f1 00 	add    rsi,0xf10000
    10f2:	8b 97 d0 03 00 00    	mov    edx,DWORD PTR [rdi+0x3d0]
    10f8:	0f ca                	bswap  edx
    10fa:	48 01 d6             	add    rsi,rdx
    10fd:	48 81 c6 00 00 f2 00 	add    rsi,0xf20000
    1104:	8b 97 d4 03 00 00    	mov    edx,DWORD PTR [rdi+0x3d4]
    110a:	0f ca                	bswap  edx
    110c:	48 01 d6             	add    rsi,rdx
    110f:	48 81 c6 00 00 f3 00 	add    rsi,0xf30000
    1116:	8b 97 d8 03 00 00    	mov    edx,DWORD PTR [rdi+0x3d8]
    111c:	0f ca                	bswap  edx
    111e:	48 01 d6             	add    rsi,rdx
    1121:	48 81 c6 00 00 f4 00 	add    rsi,0xf40000
    1128:	8b 97 dc 03 00 00    	mov    edx,DWORD PTR [rdi+0x3dc]
    112e:	0f ca                	bswap  edx
    1130:	48 01 d6             	add    rsi,rdx
    1133:	48 81 c6 00 00 f5 00 	add    rsi,0xf50000
    113a:	8b 97 e0 03 00 00    	mov    edx,DWORD PTR [rdi+0x3e0]
    1140:	0f ca                	bswap  edx
    1142:	48 01 d6             	add    rsi,rdx
    1145:	48 81 c6 00 00 f6 00 	add    rsi,0xf60000
    114c:	8b 97 e4 03 00 00    	mov    edx,DWORD PTR [rdi+0x3e4]
    1152:	0f ca                	bswap  edx
    1154:	48 01 d6             	add    rsi,rdx
    1157:	48 81 c6 00 00 f7 00 	add    rsi,0xf70000
    115e:	8b 97 e8 03 00 00    	mov    edx,DWORD PTR [rdi+0x3e8]
    1164:	0f ca                	bswap  edx
    1166:	48 01 d6             	add    rsi,rdx
    1169:	48 81 c6 00 00 f8 00 	add    rsi,0xf80000
    1170:	8b 97 ec 03 00 00    	mov    edx,DWORD PTR [rdi+0x3ec]
    1176:	0f ca                	bswap  edx
    1178:	48 01 d6             	add    rsi,rdx
    117b:	48 81 c6 00 00 f9 00 	add    rsi,0xf90000
    1182:	8b 97 f0 03 00 00    	mov    edx,DWORD PTR [rdi+0x3f0]
    1188:	0f ca                	bswap  edx
    118a:	48 01 d6             	add    rsi,rdx
    118d:	48 81 c6 00 00 fa 00 	add    rsi,0xfa0000
    1194:	8b 97 f4 03 00 00    	mov    edx,DWORD PTR [rdi+0x3f4]
    119a:	0f ca                	bswap  edx
    119c:	48 01 d6             	add    rsi,rdx
    119f:	48 81 c6 00 00 fb 00 	add    rsi,0xfb0000
    11a6:	8b 97 f8 03 00 00    	mov    edx,DWORD PTR [rdi+0x3f8]
    11ac:	0f ca                	bswap  edx
    11ae:	48 01 d6             	add    rsi,rdx
    11b1:	48 81 c6 00 00 fc 00 	add    rsi,0xfc0000
    11b8:	8b 97 fc 03 00 00    	mov    edx,DWORD PTR [rdi+0x3fc]
    11be:	0f ca                	bswap  edx
    11c0:	48 01 d6             	add    rsi,rdx
    11c3:	48 81 c6 00 00 fd 00 	add    rsi,0xfd0000
    11ca:	8b 97 00 04 00 00    	mov    edx,DWORD PTR [rdi+0x400]
    11d0:	0f ca                	bswap  edx
    11d2:	48 01 d6             	add    rsi,rdx
    11d5:	48 81 c6 00 00 fe 00 	add    rsi,0xfe0000
    11dc:	8b 97 04 04 00 00    	mov    edx,DWORD PTR [rdi+0x404]
    11e2:	0f ca                	bswap  edx
    11e4:	48 01 d6             	add    rsi,rdx
    11e7:	48 81 c6 00 00 ff 00 	add    rsi,0xff0000
    11ee:	48 89 f2             	mov    rdx,rsi
    11f1:	48 c1 ea 38          	shr    rdx,0x38
    11f5:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
    11f8:	48 89 f2             	mov    rdx,rsi
    11fb:	48 c1 ea 30          	shr    rdx,0x30
    11ff:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
    1202:	48 89 f2             	mov    rdx,rsi
    1205:	48 c1 ea 28          	shr    rdx,0x28
    1209:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
    120c:	48 89 f2             	mov    rdx,rsi
    120f:	48 c1 ea 20          	shr    rdx,0x20
    1213:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
    1216:	48 89 f2             	mov    rdx,rsi
    1219:	48 c1 ea 18          	shr    rdx,0x18
    121d:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
    1220:	48 89 f2             	mov    rdx,rsi
    1223:	48 c1 ea 10          	shr    rdx,0x10
    1227:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
    122a:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
    122e:	48 c1 ee 08          	shr    rsi,0x8
    1232:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
    1236:	b8 02 00 00 00       	mov    eax,0x2
    123b:	c9                   	leave
    123c:	c3                   	ret
    123d:	cc                   	int3
