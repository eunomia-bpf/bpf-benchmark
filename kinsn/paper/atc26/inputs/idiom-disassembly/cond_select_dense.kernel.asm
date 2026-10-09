
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/cond_select_dense.kernel.bin:     file format binary


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
      1a:	0f 87 dd 17 00 00    	ja     0x17fd
      20:	48 89 fa             	mov    rdx,rdi
      23:	48 83 c2 08          	add    rdx,0x8
      27:	48 39 f2             	cmp    rdx,rsi
      2a:	0f 87 cd 17 00 00    	ja     0x17fd
      30:	48 89 fa             	mov    rdx,rdi
      33:	48 81 c2 08 0d 00 00 	add    rdx,0xd08
      3a:	48 39 f2             	cmp    rdx,rsi
      3d:	0f 87 ba 17 00 00    	ja     0x17fd
      43:	48 8b b7 c8 09 00 00 	mov    rsi,QWORD PTR [rdi+0x9c8]
      4a:	48 8b 8f 88 06 00 00 	mov    rcx,QWORD PTR [rdi+0x688]
      51:	4c 8b 87 48 03 00 00 	mov    r8,QWORD PTR [rdi+0x348]
      58:	48 8b 47 08          	mov    rax,QWORD PTR [rdi+0x8]
      5c:	48 89 ca             	mov    rdx,rcx
      5f:	4c 39 c0             	cmp    rax,r8
      62:	77 03                	ja     0x67
      64:	48 89 f2             	mov    rdx,rsi
      67:	48 b9 15 7c 4a 7f b9 	movabs rcx,0x9e3779b97f4a7c15
      6e:	79 37 9e 
      71:	48 89 d6             	mov    rsi,rdx
      74:	48 31 ce             	xor    rsi,rcx
      77:	48 b9 d3 05 a3 85 88 	movabs rcx,0x243f6a8885a305d3
      7e:	6a 3f 24 
      81:	48 01 ce             	add    rsi,rcx
      84:	48 8b 97 d0 09 00 00 	mov    rdx,QWORD PTR [rdi+0x9d0]
      8b:	4c 8b 87 90 06 00 00 	mov    r8,QWORD PTR [rdi+0x690]
      92:	48 8b 87 50 03 00 00 	mov    rax,QWORD PTR [rdi+0x350]
      99:	48 8b 5f 10          	mov    rbx,QWORD PTR [rdi+0x10]
      9d:	4c 89 c1             	mov    rcx,r8
      a0:	48 39 c3             	cmp    rbx,rax
      a3:	77 03                	ja     0xa8
      a5:	48 89 d1             	mov    rcx,rdx
      a8:	49 b8 aa 6b cd 5d fd 	movabs r8,0x6f6b9efd5dcd6baa
      af:	9e 6b 6f 
      b2:	48 89 ca             	mov    rdx,rcx
      b5:	4c 31 c2             	xor    rdx,r8
      b8:	48 01 f2             	add    rdx,rsi
      bb:	48 8b b7 d8 09 00 00 	mov    rsi,QWORD PTR [rdi+0x9d8]
      c2:	4c 8b 87 98 06 00 00 	mov    r8,QWORD PTR [rdi+0x698]
      c9:	48 8b 87 58 03 00 00 	mov    rax,QWORD PTR [rdi+0x358]
      d0:	48 8b 5f 18          	mov    rbx,QWORD PTR [rdi+0x18]
      d4:	4c 89 c1             	mov    rcx,r8
      d7:	48 39 c3             	cmp    rbx,rax
      da:	77 03                	ja     0xdf
      dc:	48 89 f1             	mov    rcx,rsi
      df:	49 b8 3f 5b 50 3c 41 	movabs r8,0x409fc4413c505b3f
      e6:	c4 9f 40 
      e9:	48 89 ce             	mov    rsi,rcx
      ec:	4c 31 c6             	xor    rsi,r8
      ef:	48 01 d6             	add    rsi,rdx
      f2:	48 8b 97 e0 09 00 00 	mov    rdx,QWORD PTR [rdi+0x9e0]
      f9:	4c 8b 87 a0 06 00 00 	mov    r8,QWORD PTR [rdi+0x6a0]
     100:	48 8b 87 60 03 00 00 	mov    rax,QWORD PTR [rdi+0x360]
     107:	48 8b 5f 20          	mov    rbx,QWORD PTR [rdi+0x20]
     10b:	4c 89 c1             	mov    rcx,r8
     10e:	48 39 c3             	cmp    rbx,rax
     111:	77 03                	ja     0x116
     113:	48 89 d1             	mov    rcx,rdx
     116:	49 b8 d4 4a d3 1a 85 	movabs r8,0x11d3e9851ad34ad4
     11d:	e9 d3 11 
     120:	48 89 ca             	mov    rdx,rcx
     123:	4c 31 c2             	xor    rdx,r8
     126:	48 01 f2             	add    rdx,rsi
     129:	48 8b b7 e8 09 00 00 	mov    rsi,QWORD PTR [rdi+0x9e8]
     130:	4c 8b 87 a8 06 00 00 	mov    r8,QWORD PTR [rdi+0x6a8]
     137:	48 8b 87 68 03 00 00 	mov    rax,QWORD PTR [rdi+0x368]
     13e:	48 8b 5f 28          	mov    rbx,QWORD PTR [rdi+0x28]
     142:	4c 89 c1             	mov    rcx,r8
     145:	48 39 c3             	cmp    rbx,rax
     148:	77 03                	ja     0x14d
     14a:	48 89 f1             	mov    rcx,rsi
     14d:	49 b8 69 3a 56 f9 c8 	movabs r8,0xe3080ec8f9563a69
     154:	0e 08 e3 
     157:	48 89 ce             	mov    rsi,rcx
     15a:	4c 31 c6             	xor    rsi,r8
     15d:	48 01 d6             	add    rsi,rdx
     160:	48 8b 97 f0 09 00 00 	mov    rdx,QWORD PTR [rdi+0x9f0]
     167:	4c 8b 87 b0 06 00 00 	mov    r8,QWORD PTR [rdi+0x6b0]
     16e:	48 8b 87 70 03 00 00 	mov    rax,QWORD PTR [rdi+0x370]
     175:	48 8b 5f 30          	mov    rbx,QWORD PTR [rdi+0x30]
     179:	4c 89 c1             	mov    rcx,r8
     17c:	48 39 c3             	cmp    rbx,rax
     17f:	77 03                	ja     0x184
     181:	48 89 d1             	mov    rcx,rdx
     184:	49 b8 fe 29 d9 d7 0c 	movabs r8,0xb43c340cd7d929fe
     18b:	34 3c b4 
     18e:	48 89 ca             	mov    rdx,rcx
     191:	4c 31 c2             	xor    rdx,r8
     194:	48 01 f2             	add    rdx,rsi
     197:	48 8b b7 f8 09 00 00 	mov    rsi,QWORD PTR [rdi+0x9f8]
     19e:	4c 8b 87 b8 06 00 00 	mov    r8,QWORD PTR [rdi+0x6b8]
     1a5:	48 8b 87 78 03 00 00 	mov    rax,QWORD PTR [rdi+0x378]
     1ac:	48 8b 5f 38          	mov    rbx,QWORD PTR [rdi+0x38]
     1b0:	4c 89 c1             	mov    rcx,r8
     1b3:	48 39 c3             	cmp    rbx,rax
     1b6:	77 03                	ja     0x1bb
     1b8:	48 89 f1             	mov    rcx,rsi
     1bb:	49 b8 93 19 5c b6 50 	movabs r8,0x85705950b65c1993
     1c2:	59 70 85 
     1c5:	48 89 ce             	mov    rsi,rcx
     1c8:	4c 31 c6             	xor    rsi,r8
     1cb:	48 01 d6             	add    rsi,rdx
     1ce:	48 8b 97 00 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa00]
     1d5:	4c 8b 87 c0 06 00 00 	mov    r8,QWORD PTR [rdi+0x6c0]
     1dc:	48 8b 87 80 03 00 00 	mov    rax,QWORD PTR [rdi+0x380]
     1e3:	48 8b 5f 40          	mov    rbx,QWORD PTR [rdi+0x40]
     1e7:	4c 89 c1             	mov    rcx,r8
     1ea:	48 39 c3             	cmp    rbx,rax
     1ed:	77 03                	ja     0x1f2
     1ef:	48 89 d1             	mov    rcx,rdx
     1f2:	49 b8 28 09 df 94 94 	movabs r8,0x56a47e9494df0928
     1f9:	7e a4 56 
     1fc:	48 89 ca             	mov    rdx,rcx
     1ff:	4c 31 c2             	xor    rdx,r8
     202:	48 01 f2             	add    rdx,rsi
     205:	48 8b b7 08 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa08]
     20c:	4c 8b 87 c8 06 00 00 	mov    r8,QWORD PTR [rdi+0x6c8]
     213:	48 8b 87 88 03 00 00 	mov    rax,QWORD PTR [rdi+0x388]
     21a:	48 8b 5f 48          	mov    rbx,QWORD PTR [rdi+0x48]
     21e:	4c 89 c1             	mov    rcx,r8
     221:	48 39 c3             	cmp    rbx,rax
     224:	77 03                	ja     0x229
     226:	48 89 f1             	mov    rcx,rsi
     229:	49 b8 bd f8 61 73 d8 	movabs r8,0x27d8a3d87361f8bd
     230:	a3 d8 27 
     233:	48 89 ce             	mov    rsi,rcx
     236:	4c 31 c6             	xor    rsi,r8
     239:	48 01 d6             	add    rsi,rdx
     23c:	48 8b 97 10 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa10]
     243:	4c 8b 87 d0 06 00 00 	mov    r8,QWORD PTR [rdi+0x6d0]
     24a:	48 8b 87 90 03 00 00 	mov    rax,QWORD PTR [rdi+0x390]
     251:	48 8b 5f 50          	mov    rbx,QWORD PTR [rdi+0x50]
     255:	4c 89 c1             	mov    rcx,r8
     258:	48 39 c3             	cmp    rbx,rax
     25b:	77 03                	ja     0x260
     25d:	48 89 d1             	mov    rcx,rdx
     260:	49 b8 52 e8 e4 51 1c 	movabs r8,0xf90cc91c51e4e852
     267:	c9 0c f9 
     26a:	48 89 ca             	mov    rdx,rcx
     26d:	4c 31 c2             	xor    rdx,r8
     270:	48 01 f2             	add    rdx,rsi
     273:	48 8b b7 18 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa18]
     27a:	4c 8b 87 d8 06 00 00 	mov    r8,QWORD PTR [rdi+0x6d8]
     281:	48 8b 87 98 03 00 00 	mov    rax,QWORD PTR [rdi+0x398]
     288:	48 8b 5f 58          	mov    rbx,QWORD PTR [rdi+0x58]
     28c:	4c 89 c1             	mov    rcx,r8
     28f:	48 39 c3             	cmp    rbx,rax
     292:	77 03                	ja     0x297
     294:	48 89 f1             	mov    rcx,rsi
     297:	49 b8 e7 d7 67 30 60 	movabs r8,0xca40ee603067d7e7
     29e:	ee 40 ca 
     2a1:	48 89 ce             	mov    rsi,rcx
     2a4:	4c 31 c6             	xor    rsi,r8
     2a7:	48 01 d6             	add    rsi,rdx
     2aa:	48 8b 97 20 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa20]
     2b1:	4c 8b 87 e0 06 00 00 	mov    r8,QWORD PTR [rdi+0x6e0]
     2b8:	48 8b 87 a0 03 00 00 	mov    rax,QWORD PTR [rdi+0x3a0]
     2bf:	48 8b 5f 60          	mov    rbx,QWORD PTR [rdi+0x60]
     2c3:	4c 89 c1             	mov    rcx,r8
     2c6:	48 39 c3             	cmp    rbx,rax
     2c9:	77 03                	ja     0x2ce
     2cb:	48 89 d1             	mov    rcx,rdx
     2ce:	49 b8 7c c7 ea 0e a4 	movabs r8,0x9b7513a40eeac77c
     2d5:	13 75 9b 
     2d8:	48 89 ca             	mov    rdx,rcx
     2db:	4c 31 c2             	xor    rdx,r8
     2de:	48 01 f2             	add    rdx,rsi
     2e1:	48 8b b7 28 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa28]
     2e8:	4c 8b 87 e8 06 00 00 	mov    r8,QWORD PTR [rdi+0x6e8]
     2ef:	48 8b 87 a8 03 00 00 	mov    rax,QWORD PTR [rdi+0x3a8]
     2f6:	48 8b 5f 68          	mov    rbx,QWORD PTR [rdi+0x68]
     2fa:	4c 89 c1             	mov    rcx,r8
     2fd:	48 39 c3             	cmp    rbx,rax
     300:	77 03                	ja     0x305
     302:	48 89 f1             	mov    rcx,rsi
     305:	49 b8 11 b7 6d ed e7 	movabs r8,0x6ca938e7ed6db711
     30c:	38 a9 6c 
     30f:	48 89 ce             	mov    rsi,rcx
     312:	4c 31 c6             	xor    rsi,r8
     315:	48 01 d6             	add    rsi,rdx
     318:	48 8b 97 30 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa30]
     31f:	4c 8b 87 f0 06 00 00 	mov    r8,QWORD PTR [rdi+0x6f0]
     326:	48 8b 87 b0 03 00 00 	mov    rax,QWORD PTR [rdi+0x3b0]
     32d:	48 8b 5f 70          	mov    rbx,QWORD PTR [rdi+0x70]
     331:	4c 89 c1             	mov    rcx,r8
     334:	48 39 c3             	cmp    rbx,rax
     337:	77 03                	ja     0x33c
     339:	48 89 d1             	mov    rcx,rdx
     33c:	49 b8 a6 a6 f0 cb 2b 	movabs r8,0x3ddd5e2bcbf0a6a6
     343:	5e dd 3d 
     346:	48 89 ca             	mov    rdx,rcx
     349:	4c 31 c2             	xor    rdx,r8
     34c:	48 01 f2             	add    rdx,rsi
     34f:	48 8b b7 38 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa38]
     356:	4c 8b 87 f8 06 00 00 	mov    r8,QWORD PTR [rdi+0x6f8]
     35d:	48 8b 87 b8 03 00 00 	mov    rax,QWORD PTR [rdi+0x3b8]
     364:	48 8b 5f 78          	mov    rbx,QWORD PTR [rdi+0x78]
     368:	4c 89 c1             	mov    rcx,r8
     36b:	48 39 c3             	cmp    rbx,rax
     36e:	77 03                	ja     0x373
     370:	48 89 f1             	mov    rcx,rsi
     373:	49 b8 3b 96 73 aa 6f 	movabs r8,0xf11836faa73963b
     37a:	83 11 0f 
     37d:	48 89 ce             	mov    rsi,rcx
     380:	4c 31 c6             	xor    rsi,r8
     383:	48 01 d6             	add    rsi,rdx
     386:	48 8b 97 40 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa40]
     38d:	4c 8b 87 00 07 00 00 	mov    r8,QWORD PTR [rdi+0x700]
     394:	48 8b 87 c0 03 00 00 	mov    rax,QWORD PTR [rdi+0x3c0]
     39b:	48 8b 9f 80 00 00 00 	mov    rbx,QWORD PTR [rdi+0x80]
     3a2:	4c 89 c1             	mov    rcx,r8
     3a5:	48 39 c3             	cmp    rbx,rax
     3a8:	77 03                	ja     0x3ad
     3aa:	48 89 d1             	mov    rcx,rdx
     3ad:	49 b8 d0 85 f6 88 b3 	movabs r8,0xe045a8b388f685d0
     3b4:	a8 45 e0 
     3b7:	48 89 ca             	mov    rdx,rcx
     3ba:	4c 31 c2             	xor    rdx,r8
     3bd:	48 01 f2             	add    rdx,rsi
     3c0:	48 8b b7 48 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa48]
     3c7:	4c 8b 87 08 07 00 00 	mov    r8,QWORD PTR [rdi+0x708]
     3ce:	48 8b 87 c8 03 00 00 	mov    rax,QWORD PTR [rdi+0x3c8]
     3d5:	48 8b 9f 88 00 00 00 	mov    rbx,QWORD PTR [rdi+0x88]
     3dc:	4c 89 c1             	mov    rcx,r8
     3df:	48 39 c3             	cmp    rbx,rax
     3e2:	77 03                	ja     0x3e7
     3e4:	48 89 f1             	mov    rcx,rsi
     3e7:	49 b8 65 75 79 67 f7 	movabs r8,0xb179cdf767797565
     3ee:	cd 79 b1 
     3f1:	48 89 ce             	mov    rsi,rcx
     3f4:	4c 31 c6             	xor    rsi,r8
     3f7:	48 01 d6             	add    rsi,rdx
     3fa:	48 8b 97 50 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa50]
     401:	4c 8b 87 10 07 00 00 	mov    r8,QWORD PTR [rdi+0x710]
     408:	48 8b 87 d0 03 00 00 	mov    rax,QWORD PTR [rdi+0x3d0]
     40f:	48 8b 9f 90 00 00 00 	mov    rbx,QWORD PTR [rdi+0x90]
     416:	4c 89 c1             	mov    rcx,r8
     419:	48 39 c3             	cmp    rbx,rax
     41c:	77 03                	ja     0x421
     41e:	48 89 d1             	mov    rcx,rdx
     421:	49 b8 fa 64 fc 45 3b 	movabs r8,0x82adf33b45fc64fa
     428:	f3 ad 82 
     42b:	48 89 ca             	mov    rdx,rcx
     42e:	4c 31 c2             	xor    rdx,r8
     431:	48 01 f2             	add    rdx,rsi
     434:	48 8b b7 58 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa58]
     43b:	4c 8b 87 18 07 00 00 	mov    r8,QWORD PTR [rdi+0x718]
     442:	48 8b 87 d8 03 00 00 	mov    rax,QWORD PTR [rdi+0x3d8]
     449:	48 8b 9f 98 00 00 00 	mov    rbx,QWORD PTR [rdi+0x98]
     450:	4c 89 c1             	mov    rcx,r8
     453:	48 39 c3             	cmp    rbx,rax
     456:	77 03                	ja     0x45b
     458:	48 89 f1             	mov    rcx,rsi
     45b:	49 b8 8f 54 7f 24 7f 	movabs r8,0x53e2187f247f548f
     462:	18 e2 53 
     465:	48 89 ce             	mov    rsi,rcx
     468:	4c 31 c6             	xor    rsi,r8
     46b:	48 01 d6             	add    rsi,rdx
     46e:	48 8b 97 60 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa60]
     475:	4c 8b 87 20 07 00 00 	mov    r8,QWORD PTR [rdi+0x720]
     47c:	48 8b 87 e0 03 00 00 	mov    rax,QWORD PTR [rdi+0x3e0]
     483:	48 8b 9f a0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xa0]
     48a:	4c 89 c1             	mov    rcx,r8
     48d:	48 39 c3             	cmp    rbx,rax
     490:	77 03                	ja     0x495
     492:	48 89 d1             	mov    rcx,rdx
     495:	49 b8 24 44 02 03 c3 	movabs r8,0x25163dc303024424
     49c:	3d 16 25 
     49f:	48 89 ca             	mov    rdx,rcx
     4a2:	4c 31 c2             	xor    rdx,r8
     4a5:	48 01 f2             	add    rdx,rsi
     4a8:	48 8b b7 68 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa68]
     4af:	4c 8b 87 28 07 00 00 	mov    r8,QWORD PTR [rdi+0x728]
     4b6:	48 8b 87 e8 03 00 00 	mov    rax,QWORD PTR [rdi+0x3e8]
     4bd:	48 8b 9f a8 00 00 00 	mov    rbx,QWORD PTR [rdi+0xa8]
     4c4:	4c 89 c1             	mov    rcx,r8
     4c7:	48 39 c3             	cmp    rbx,rax
     4ca:	77 03                	ja     0x4cf
     4cc:	48 89 f1             	mov    rcx,rsi
     4cf:	49 b8 b9 33 85 e1 06 	movabs r8,0xf64a6306e18533b9
     4d6:	63 4a f6 
     4d9:	48 89 ce             	mov    rsi,rcx
     4dc:	4c 31 c6             	xor    rsi,r8
     4df:	48 01 d6             	add    rsi,rdx
     4e2:	48 8b 97 70 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa70]
     4e9:	4c 8b 87 30 07 00 00 	mov    r8,QWORD PTR [rdi+0x730]
     4f0:	48 8b 87 f0 03 00 00 	mov    rax,QWORD PTR [rdi+0x3f0]
     4f7:	48 8b 9f b0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xb0]
     4fe:	4c 89 c1             	mov    rcx,r8
     501:	48 39 c3             	cmp    rbx,rax
     504:	77 03                	ja     0x509
     506:	48 89 d1             	mov    rcx,rdx
     509:	49 b8 4e 23 08 c0 4a 	movabs r8,0xc77e884ac008234e
     510:	88 7e c7 
     513:	48 89 ca             	mov    rdx,rcx
     516:	4c 31 c2             	xor    rdx,r8
     519:	48 01 f2             	add    rdx,rsi
     51c:	48 8b b7 78 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa78]
     523:	4c 8b 87 38 07 00 00 	mov    r8,QWORD PTR [rdi+0x738]
     52a:	48 8b 87 f8 03 00 00 	mov    rax,QWORD PTR [rdi+0x3f8]
     531:	48 8b 9f b8 00 00 00 	mov    rbx,QWORD PTR [rdi+0xb8]
     538:	4c 89 c1             	mov    rcx,r8
     53b:	48 39 c3             	cmp    rbx,rax
     53e:	77 03                	ja     0x543
     540:	48 89 f1             	mov    rcx,rsi
     543:	49 b8 e3 12 8b 9e 8e 	movabs r8,0x98b2ad8e9e8b12e3
     54a:	ad b2 98 
     54d:	48 89 ce             	mov    rsi,rcx
     550:	4c 31 c6             	xor    rsi,r8
     553:	48 01 d6             	add    rsi,rdx
     556:	48 8b 97 80 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa80]
     55d:	4c 8b 87 40 07 00 00 	mov    r8,QWORD PTR [rdi+0x740]
     564:	48 8b 87 00 04 00 00 	mov    rax,QWORD PTR [rdi+0x400]
     56b:	48 8b 9f c0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xc0]
     572:	4c 89 c1             	mov    rcx,r8
     575:	48 39 c3             	cmp    rbx,rax
     578:	77 03                	ja     0x57d
     57a:	48 89 d1             	mov    rcx,rdx
     57d:	49 b8 78 02 0e 7d d2 	movabs r8,0x69e6d2d27d0e0278
     584:	d2 e6 69 
     587:	48 89 ca             	mov    rdx,rcx
     58a:	4c 31 c2             	xor    rdx,r8
     58d:	48 01 f2             	add    rdx,rsi
     590:	48 8b b7 88 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa88]
     597:	4c 8b 87 48 07 00 00 	mov    r8,QWORD PTR [rdi+0x748]
     59e:	48 8b 87 08 04 00 00 	mov    rax,QWORD PTR [rdi+0x408]
     5a5:	48 8b 9f c8 00 00 00 	mov    rbx,QWORD PTR [rdi+0xc8]
     5ac:	4c 89 c1             	mov    rcx,r8
     5af:	48 39 c3             	cmp    rbx,rax
     5b2:	77 03                	ja     0x5b7
     5b4:	48 89 f1             	mov    rcx,rsi
     5b7:	49 b8 0d f2 90 5b 16 	movabs r8,0x3b1af8165b90f20d
     5be:	f8 1a 3b 
     5c1:	48 89 ce             	mov    rsi,rcx
     5c4:	4c 31 c6             	xor    rsi,r8
     5c7:	48 01 d6             	add    rsi,rdx
     5ca:	48 8b 97 90 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xa90]
     5d1:	4c 8b 87 50 07 00 00 	mov    r8,QWORD PTR [rdi+0x750]
     5d8:	48 8b 87 10 04 00 00 	mov    rax,QWORD PTR [rdi+0x410]
     5df:	48 8b 9f d0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xd0]
     5e6:	4c 89 c1             	mov    rcx,r8
     5e9:	48 39 c3             	cmp    rbx,rax
     5ec:	77 03                	ja     0x5f1
     5ee:	48 89 d1             	mov    rcx,rdx
     5f1:	49 b8 a2 e1 13 3a 5a 	movabs r8,0xc4f1d5a3a13e1a2
     5f8:	1d 4f 0c 
     5fb:	48 89 ca             	mov    rdx,rcx
     5fe:	4c 31 c2             	xor    rdx,r8
     601:	48 01 f2             	add    rdx,rsi
     604:	48 8b b7 98 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xa98]
     60b:	4c 8b 87 58 07 00 00 	mov    r8,QWORD PTR [rdi+0x758]
     612:	48 8b 87 18 04 00 00 	mov    rax,QWORD PTR [rdi+0x418]
     619:	48 8b 9f d8 00 00 00 	mov    rbx,QWORD PTR [rdi+0xd8]
     620:	4c 89 c1             	mov    rcx,r8
     623:	48 39 c3             	cmp    rbx,rax
     626:	77 03                	ja     0x62b
     628:	48 89 f1             	mov    rcx,rsi
     62b:	49 b8 37 d1 96 18 9e 	movabs r8,0xdd83429e1896d137
     632:	42 83 dd 
     635:	48 89 ce             	mov    rsi,rcx
     638:	4c 31 c6             	xor    rsi,r8
     63b:	48 01 d6             	add    rsi,rdx
     63e:	48 8b 97 a0 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xaa0]
     645:	4c 8b 87 60 07 00 00 	mov    r8,QWORD PTR [rdi+0x760]
     64c:	48 8b 87 20 04 00 00 	mov    rax,QWORD PTR [rdi+0x420]
     653:	48 8b 9f e0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xe0]
     65a:	4c 89 c1             	mov    rcx,r8
     65d:	48 39 c3             	cmp    rbx,rax
     660:	77 03                	ja     0x665
     662:	48 89 d1             	mov    rcx,rdx
     665:	49 b8 cc c0 19 f7 e1 	movabs r8,0xaeb767e1f719c0cc
     66c:	67 b7 ae 
     66f:	48 89 ca             	mov    rdx,rcx
     672:	4c 31 c2             	xor    rdx,r8
     675:	48 01 f2             	add    rdx,rsi
     678:	48 8b b7 a8 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xaa8]
     67f:	4c 8b 87 68 07 00 00 	mov    r8,QWORD PTR [rdi+0x768]
     686:	48 8b 87 28 04 00 00 	mov    rax,QWORD PTR [rdi+0x428]
     68d:	48 8b 9f e8 00 00 00 	mov    rbx,QWORD PTR [rdi+0xe8]
     694:	4c 89 c1             	mov    rcx,r8
     697:	48 39 c3             	cmp    rbx,rax
     69a:	77 03                	ja     0x69f
     69c:	48 89 f1             	mov    rcx,rsi
     69f:	49 b8 61 b0 9c d5 25 	movabs r8,0x7feb8d25d59cb061
     6a6:	8d eb 7f 
     6a9:	48 89 ce             	mov    rsi,rcx
     6ac:	4c 31 c6             	xor    rsi,r8
     6af:	48 01 d6             	add    rsi,rdx
     6b2:	48 8b 97 b0 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xab0]
     6b9:	4c 8b 87 70 07 00 00 	mov    r8,QWORD PTR [rdi+0x770]
     6c0:	48 8b 87 30 04 00 00 	mov    rax,QWORD PTR [rdi+0x430]
     6c7:	48 8b 9f f0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xf0]
     6ce:	4c 89 c1             	mov    rcx,r8
     6d1:	48 39 c3             	cmp    rbx,rax
     6d4:	77 03                	ja     0x6d9
     6d6:	48 89 d1             	mov    rcx,rdx
     6d9:	49 b8 f6 9f 1f b4 69 	movabs r8,0x511fb269b41f9ff6
     6e0:	b2 1f 51 
     6e3:	48 89 ca             	mov    rdx,rcx
     6e6:	4c 31 c2             	xor    rdx,r8
     6e9:	48 01 f2             	add    rdx,rsi
     6ec:	48 8b b7 b8 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xab8]
     6f3:	4c 8b 87 78 07 00 00 	mov    r8,QWORD PTR [rdi+0x778]
     6fa:	48 8b 87 38 04 00 00 	mov    rax,QWORD PTR [rdi+0x438]
     701:	48 8b 9f f8 00 00 00 	mov    rbx,QWORD PTR [rdi+0xf8]
     708:	4c 89 c1             	mov    rcx,r8
     70b:	48 39 c3             	cmp    rbx,rax
     70e:	77 03                	ja     0x713
     710:	48 89 f1             	mov    rcx,rsi
     713:	49 b8 8b 8f a2 92 ad 	movabs r8,0x2253d7ad92a28f8b
     71a:	d7 53 22 
     71d:	48 89 ce             	mov    rsi,rcx
     720:	4c 31 c6             	xor    rsi,r8
     723:	48 01 d6             	add    rsi,rdx
     726:	48 8b 97 c0 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xac0]
     72d:	4c 8b 87 80 07 00 00 	mov    r8,QWORD PTR [rdi+0x780]
     734:	48 8b 87 40 04 00 00 	mov    rax,QWORD PTR [rdi+0x440]
     73b:	48 8b 9f 00 01 00 00 	mov    rbx,QWORD PTR [rdi+0x100]
     742:	4c 89 c1             	mov    rcx,r8
     745:	48 39 c3             	cmp    rbx,rax
     748:	77 03                	ja     0x74d
     74a:	48 89 d1             	mov    rcx,rdx
     74d:	49 b8 20 7f 25 71 f1 	movabs r8,0xf387fcf171257f20
     754:	fc 87 f3 
     757:	48 89 ca             	mov    rdx,rcx
     75a:	4c 31 c2             	xor    rdx,r8
     75d:	48 01 f2             	add    rdx,rsi
     760:	48 8b b7 c8 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xac8]
     767:	4c 8b 87 88 07 00 00 	mov    r8,QWORD PTR [rdi+0x788]
     76e:	48 8b 87 48 04 00 00 	mov    rax,QWORD PTR [rdi+0x448]
     775:	48 8b 9f 08 01 00 00 	mov    rbx,QWORD PTR [rdi+0x108]
     77c:	4c 89 c1             	mov    rcx,r8
     77f:	48 39 c3             	cmp    rbx,rax
     782:	77 03                	ja     0x787
     784:	48 89 f1             	mov    rcx,rsi
     787:	49 b8 b5 6e a8 4f 35 	movabs r8,0xc4bc22354fa86eb5
     78e:	22 bc c4 
     791:	48 89 ce             	mov    rsi,rcx
     794:	4c 31 c6             	xor    rsi,r8
     797:	48 01 d6             	add    rsi,rdx
     79a:	48 8b 97 d0 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xad0]
     7a1:	4c 8b 87 90 07 00 00 	mov    r8,QWORD PTR [rdi+0x790]
     7a8:	48 8b 87 50 04 00 00 	mov    rax,QWORD PTR [rdi+0x450]
     7af:	48 8b 9f 10 01 00 00 	mov    rbx,QWORD PTR [rdi+0x110]
     7b6:	4c 89 c1             	mov    rcx,r8
     7b9:	48 39 c3             	cmp    rbx,rax
     7bc:	77 03                	ja     0x7c1
     7be:	48 89 d1             	mov    rcx,rdx
     7c1:	49 b8 4a 5e 2b 2e 79 	movabs r8,0x95f047792e2b5e4a
     7c8:	47 f0 95 
     7cb:	48 89 ca             	mov    rdx,rcx
     7ce:	4c 31 c2             	xor    rdx,r8
     7d1:	48 01 f2             	add    rdx,rsi
     7d4:	48 8b b7 d8 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xad8]
     7db:	4c 8b 87 98 07 00 00 	mov    r8,QWORD PTR [rdi+0x798]
     7e2:	48 8b 87 58 04 00 00 	mov    rax,QWORD PTR [rdi+0x458]
     7e9:	48 8b 9f 18 01 00 00 	mov    rbx,QWORD PTR [rdi+0x118]
     7f0:	4c 89 c1             	mov    rcx,r8
     7f3:	48 39 c3             	cmp    rbx,rax
     7f6:	77 03                	ja     0x7fb
     7f8:	48 89 f1             	mov    rcx,rsi
     7fb:	49 b8 df 4d ae 0c bd 	movabs r8,0x67246cbd0cae4ddf
     802:	6c 24 67 
     805:	48 89 ce             	mov    rsi,rcx
     808:	4c 31 c6             	xor    rsi,r8
     80b:	48 01 d6             	add    rsi,rdx
     80e:	48 8b 97 e0 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xae0]
     815:	4c 8b 87 a0 07 00 00 	mov    r8,QWORD PTR [rdi+0x7a0]
     81c:	48 8b 87 60 04 00 00 	mov    rax,QWORD PTR [rdi+0x460]
     823:	48 8b 9f 20 01 00 00 	mov    rbx,QWORD PTR [rdi+0x120]
     82a:	4c 89 c1             	mov    rcx,r8
     82d:	48 39 c3             	cmp    rbx,rax
     830:	77 03                	ja     0x835
     832:	48 89 d1             	mov    rcx,rdx
     835:	49 b8 74 3d 31 eb 00 	movabs r8,0x38589200eb313d74
     83c:	92 58 38 
     83f:	48 89 ca             	mov    rdx,rcx
     842:	4c 31 c2             	xor    rdx,r8
     845:	48 01 f2             	add    rdx,rsi
     848:	48 8b b7 e8 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xae8]
     84f:	4c 8b 87 a8 07 00 00 	mov    r8,QWORD PTR [rdi+0x7a8]
     856:	48 8b 87 68 04 00 00 	mov    rax,QWORD PTR [rdi+0x468]
     85d:	48 8b 9f 28 01 00 00 	mov    rbx,QWORD PTR [rdi+0x128]
     864:	4c 89 c1             	mov    rcx,r8
     867:	48 39 c3             	cmp    rbx,rax
     86a:	77 03                	ja     0x86f
     86c:	48 89 f1             	mov    rcx,rsi
     86f:	49 b8 09 2d b4 c9 44 	movabs r8,0x98cb744c9b42d09
     876:	b7 8c 09 
     879:	48 89 ce             	mov    rsi,rcx
     87c:	4c 31 c6             	xor    rsi,r8
     87f:	48 01 d6             	add    rsi,rdx
     882:	48 8b 97 f0 0a 00 00 	mov    rdx,QWORD PTR [rdi+0xaf0]
     889:	4c 8b 87 b0 07 00 00 	mov    r8,QWORD PTR [rdi+0x7b0]
     890:	48 8b 87 70 04 00 00 	mov    rax,QWORD PTR [rdi+0x470]
     897:	48 8b 9f 30 01 00 00 	mov    rbx,QWORD PTR [rdi+0x130]
     89e:	4c 89 c1             	mov    rcx,r8
     8a1:	48 39 c3             	cmp    rbx,rax
     8a4:	77 03                	ja     0x8a9
     8a6:	48 89 d1             	mov    rcx,rdx
     8a9:	49 b8 9e 1c 37 a8 88 	movabs r8,0xdac0dc88a8371c9e
     8b0:	dc c0 da 
     8b3:	48 89 ca             	mov    rdx,rcx
     8b6:	4c 31 c2             	xor    rdx,r8
     8b9:	48 01 f2             	add    rdx,rsi
     8bc:	48 8b b7 f8 0a 00 00 	mov    rsi,QWORD PTR [rdi+0xaf8]
     8c3:	4c 8b 87 b8 07 00 00 	mov    r8,QWORD PTR [rdi+0x7b8]
     8ca:	48 8b 87 78 04 00 00 	mov    rax,QWORD PTR [rdi+0x478]
     8d1:	48 8b 9f 38 01 00 00 	mov    rbx,QWORD PTR [rdi+0x138]
     8d8:	4c 89 c1             	mov    rcx,r8
     8db:	48 39 c3             	cmp    rbx,rax
     8de:	77 03                	ja     0x8e3
     8e0:	48 89 f1             	mov    rcx,rsi
     8e3:	49 b8 33 0c ba 86 cc 	movabs r8,0xabf501cc86ba0c33
     8ea:	01 f5 ab 
     8ed:	48 89 ce             	mov    rsi,rcx
     8f0:	4c 31 c6             	xor    rsi,r8
     8f3:	48 01 d6             	add    rsi,rdx
     8f6:	48 8b 97 00 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb00]
     8fd:	4c 8b 87 c0 07 00 00 	mov    r8,QWORD PTR [rdi+0x7c0]
     904:	48 8b 87 80 04 00 00 	mov    rax,QWORD PTR [rdi+0x480]
     90b:	48 8b 9f 40 01 00 00 	mov    rbx,QWORD PTR [rdi+0x140]
     912:	4c 89 c1             	mov    rcx,r8
     915:	48 39 c3             	cmp    rbx,rax
     918:	77 03                	ja     0x91d
     91a:	48 89 d1             	mov    rcx,rdx
     91d:	49 b8 c8 fb 3c 65 10 	movabs r8,0x7d292710653cfbc8
     924:	27 29 7d 
     927:	48 89 ca             	mov    rdx,rcx
     92a:	4c 31 c2             	xor    rdx,r8
     92d:	48 01 f2             	add    rdx,rsi
     930:	48 8b b7 08 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb08]
     937:	4c 8b 87 c8 07 00 00 	mov    r8,QWORD PTR [rdi+0x7c8]
     93e:	48 8b 87 88 04 00 00 	mov    rax,QWORD PTR [rdi+0x488]
     945:	48 8b 9f 48 01 00 00 	mov    rbx,QWORD PTR [rdi+0x148]
     94c:	4c 89 c1             	mov    rcx,r8
     94f:	48 39 c3             	cmp    rbx,rax
     952:	77 03                	ja     0x957
     954:	48 89 f1             	mov    rcx,rsi
     957:	49 b8 5d eb bf 43 54 	movabs r8,0x4e5d4c5443bfeb5d
     95e:	4c 5d 4e 
     961:	48 89 ce             	mov    rsi,rcx
     964:	4c 31 c6             	xor    rsi,r8
     967:	48 01 d6             	add    rsi,rdx
     96a:	48 8b 97 10 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb10]
     971:	4c 8b 87 d0 07 00 00 	mov    r8,QWORD PTR [rdi+0x7d0]
     978:	48 8b 87 90 04 00 00 	mov    rax,QWORD PTR [rdi+0x490]
     97f:	48 8b 9f 50 01 00 00 	mov    rbx,QWORD PTR [rdi+0x150]
     986:	4c 89 c1             	mov    rcx,r8
     989:	48 39 c3             	cmp    rbx,rax
     98c:	77 03                	ja     0x991
     98e:	48 89 d1             	mov    rcx,rdx
     991:	49 b8 f2 da 42 22 98 	movabs r8,0x1f9171982242daf2
     998:	71 91 1f 
     99b:	48 89 ca             	mov    rdx,rcx
     99e:	4c 31 c2             	xor    rdx,r8
     9a1:	48 01 f2             	add    rdx,rsi
     9a4:	48 8b b7 18 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb18]
     9ab:	4c 8b 87 d8 07 00 00 	mov    r8,QWORD PTR [rdi+0x7d8]
     9b2:	48 8b 87 98 04 00 00 	mov    rax,QWORD PTR [rdi+0x498]
     9b9:	48 8b 9f 58 01 00 00 	mov    rbx,QWORD PTR [rdi+0x158]
     9c0:	4c 89 c1             	mov    rcx,r8
     9c3:	48 39 c3             	cmp    rbx,rax
     9c6:	77 03                	ja     0x9cb
     9c8:	48 89 f1             	mov    rcx,rsi
     9cb:	49 b8 87 ca c5 00 dc 	movabs r8,0xf0c596dc00c5ca87
     9d2:	96 c5 f0 
     9d5:	48 89 ce             	mov    rsi,rcx
     9d8:	4c 31 c6             	xor    rsi,r8
     9db:	48 01 d6             	add    rsi,rdx
     9de:	48 8b 97 20 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb20]
     9e5:	4c 8b 87 e0 07 00 00 	mov    r8,QWORD PTR [rdi+0x7e0]
     9ec:	48 8b 87 a0 04 00 00 	mov    rax,QWORD PTR [rdi+0x4a0]
     9f3:	48 8b 9f 60 01 00 00 	mov    rbx,QWORD PTR [rdi+0x160]
     9fa:	4c 89 c1             	mov    rcx,r8
     9fd:	48 39 c3             	cmp    rbx,rax
     a00:	77 03                	ja     0xa05
     a02:	48 89 d1             	mov    rcx,rdx
     a05:	49 b8 1c ba 48 df 1f 	movabs r8,0xc1f9bc1fdf48ba1c
     a0c:	bc f9 c1 
     a0f:	48 89 ca             	mov    rdx,rcx
     a12:	4c 31 c2             	xor    rdx,r8
     a15:	48 01 f2             	add    rdx,rsi
     a18:	48 8b b7 28 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb28]
     a1f:	4c 8b 87 e8 07 00 00 	mov    r8,QWORD PTR [rdi+0x7e8]
     a26:	48 8b 87 a8 04 00 00 	mov    rax,QWORD PTR [rdi+0x4a8]
     a2d:	48 8b 9f 68 01 00 00 	mov    rbx,QWORD PTR [rdi+0x168]
     a34:	4c 89 c1             	mov    rcx,r8
     a37:	48 39 c3             	cmp    rbx,rax
     a3a:	77 03                	ja     0xa3f
     a3c:	48 89 f1             	mov    rcx,rsi
     a3f:	49 b8 b1 a9 cb bd 63 	movabs r8,0x932de163bdcba9b1
     a46:	e1 2d 93 
     a49:	48 89 ce             	mov    rsi,rcx
     a4c:	4c 31 c6             	xor    rsi,r8
     a4f:	48 01 d6             	add    rsi,rdx
     a52:	48 8b 97 30 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb30]
     a59:	4c 8b 87 f0 07 00 00 	mov    r8,QWORD PTR [rdi+0x7f0]
     a60:	48 8b 87 b0 04 00 00 	mov    rax,QWORD PTR [rdi+0x4b0]
     a67:	48 8b 9f 70 01 00 00 	mov    rbx,QWORD PTR [rdi+0x170]
     a6e:	4c 89 c1             	mov    rcx,r8
     a71:	48 39 c3             	cmp    rbx,rax
     a74:	77 03                	ja     0xa79
     a76:	48 89 d1             	mov    rcx,rdx
     a79:	49 b8 46 99 4e 9c a7 	movabs r8,0x646206a79c4e9946
     a80:	06 62 64 
     a83:	48 89 ca             	mov    rdx,rcx
     a86:	4c 31 c2             	xor    rdx,r8
     a89:	48 01 f2             	add    rdx,rsi
     a8c:	48 8b b7 38 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb38]
     a93:	4c 8b 87 f8 07 00 00 	mov    r8,QWORD PTR [rdi+0x7f8]
     a9a:	48 8b 87 b8 04 00 00 	mov    rax,QWORD PTR [rdi+0x4b8]
     aa1:	48 8b 9f 78 01 00 00 	mov    rbx,QWORD PTR [rdi+0x178]
     aa8:	4c 89 c1             	mov    rcx,r8
     aab:	48 39 c3             	cmp    rbx,rax
     aae:	77 03                	ja     0xab3
     ab0:	48 89 f1             	mov    rcx,rsi
     ab3:	49 b8 db 88 d1 7a eb 	movabs r8,0x35962beb7ad188db
     aba:	2b 96 35 
     abd:	48 89 ce             	mov    rsi,rcx
     ac0:	4c 31 c6             	xor    rsi,r8
     ac3:	48 01 d6             	add    rsi,rdx
     ac6:	48 8b 97 40 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb40]
     acd:	4c 8b 87 00 08 00 00 	mov    r8,QWORD PTR [rdi+0x800]
     ad4:	48 8b 87 c0 04 00 00 	mov    rax,QWORD PTR [rdi+0x4c0]
     adb:	48 8b 9f 80 01 00 00 	mov    rbx,QWORD PTR [rdi+0x180]
     ae2:	4c 89 c1             	mov    rcx,r8
     ae5:	48 39 c3             	cmp    rbx,rax
     ae8:	77 03                	ja     0xaed
     aea:	48 89 d1             	mov    rcx,rdx
     aed:	49 b8 70 78 54 59 2f 	movabs r8,0x6ca512f59547870
     af4:	51 ca 06 
     af7:	48 89 ca             	mov    rdx,rcx
     afa:	4c 31 c2             	xor    rdx,r8
     afd:	48 01 f2             	add    rdx,rsi
     b00:	48 8b b7 48 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb48]
     b07:	4c 8b 87 08 08 00 00 	mov    r8,QWORD PTR [rdi+0x808]
     b0e:	48 8b 87 c8 04 00 00 	mov    rax,QWORD PTR [rdi+0x4c8]
     b15:	48 8b 9f 88 01 00 00 	mov    rbx,QWORD PTR [rdi+0x188]
     b1c:	4c 89 c1             	mov    rcx,r8
     b1f:	48 39 c3             	cmp    rbx,rax
     b22:	77 03                	ja     0xb27
     b24:	48 89 f1             	mov    rcx,rsi
     b27:	49 b8 05 68 d7 37 73 	movabs r8,0xd7fe767337d76805
     b2e:	76 fe d7 
     b31:	48 89 ce             	mov    rsi,rcx
     b34:	4c 31 c6             	xor    rsi,r8
     b37:	48 01 d6             	add    rsi,rdx
     b3a:	48 8b 97 50 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb50]
     b41:	4c 8b 87 10 08 00 00 	mov    r8,QWORD PTR [rdi+0x810]
     b48:	48 8b 87 d0 04 00 00 	mov    rax,QWORD PTR [rdi+0x4d0]
     b4f:	48 8b 9f 90 01 00 00 	mov    rbx,QWORD PTR [rdi+0x190]
     b56:	4c 89 c1             	mov    rcx,r8
     b59:	48 39 c3             	cmp    rbx,rax
     b5c:	77 03                	ja     0xb61
     b5e:	48 89 d1             	mov    rcx,rdx
     b61:	49 b8 9a 57 5a 16 b7 	movabs r8,0xa9329bb7165a579a
     b68:	9b 32 a9 
     b6b:	48 89 ca             	mov    rdx,rcx
     b6e:	4c 31 c2             	xor    rdx,r8
     b71:	48 01 f2             	add    rdx,rsi
     b74:	48 8b b7 58 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb58]
     b7b:	4c 8b 87 18 08 00 00 	mov    r8,QWORD PTR [rdi+0x818]
     b82:	48 8b 87 d8 04 00 00 	mov    rax,QWORD PTR [rdi+0x4d8]
     b89:	48 8b 9f 98 01 00 00 	mov    rbx,QWORD PTR [rdi+0x198]
     b90:	4c 89 c1             	mov    rcx,r8
     b93:	48 39 c3             	cmp    rbx,rax
     b96:	77 03                	ja     0xb9b
     b98:	48 89 f1             	mov    rcx,rsi
     b9b:	49 b8 2f 47 dd f4 fa 	movabs r8,0x7a66c0faf4dd472f
     ba2:	c0 66 7a 
     ba5:	48 89 ce             	mov    rsi,rcx
     ba8:	4c 31 c6             	xor    rsi,r8
     bab:	48 01 d6             	add    rsi,rdx
     bae:	48 8b 97 60 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb60]
     bb5:	4c 8b 87 20 08 00 00 	mov    r8,QWORD PTR [rdi+0x820]
     bbc:	48 8b 87 e0 04 00 00 	mov    rax,QWORD PTR [rdi+0x4e0]
     bc3:	48 8b 9f a0 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1a0]
     bca:	4c 89 c1             	mov    rcx,r8
     bcd:	48 39 c3             	cmp    rbx,rax
     bd0:	77 03                	ja     0xbd5
     bd2:	48 89 d1             	mov    rcx,rdx
     bd5:	49 b8 c4 36 60 d3 3e 	movabs r8,0x4b9ae63ed36036c4
     bdc:	e6 9a 4b 
     bdf:	48 89 ca             	mov    rdx,rcx
     be2:	4c 31 c2             	xor    rdx,r8
     be5:	48 01 f2             	add    rdx,rsi
     be8:	48 8b b7 68 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb68]
     bef:	4c 8b 87 28 08 00 00 	mov    r8,QWORD PTR [rdi+0x828]
     bf6:	48 8b 87 e8 04 00 00 	mov    rax,QWORD PTR [rdi+0x4e8]
     bfd:	48 8b 9f a8 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1a8]
     c04:	4c 89 c1             	mov    rcx,r8
     c07:	48 39 c3             	cmp    rbx,rax
     c0a:	77 03                	ja     0xc0f
     c0c:	48 89 f1             	mov    rcx,rsi
     c0f:	49 b8 59 26 e3 b1 82 	movabs r8,0x1ccf0b82b1e32659
     c16:	0b cf 1c 
     c19:	48 89 ce             	mov    rsi,rcx
     c1c:	4c 31 c6             	xor    rsi,r8
     c1f:	48 01 d6             	add    rsi,rdx
     c22:	48 8b 97 70 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb70]
     c29:	4c 8b 87 30 08 00 00 	mov    r8,QWORD PTR [rdi+0x830]
     c30:	48 8b 87 f0 04 00 00 	mov    rax,QWORD PTR [rdi+0x4f0]
     c37:	48 8b 9f b0 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1b0]
     c3e:	4c 89 c1             	mov    rcx,r8
     c41:	48 39 c3             	cmp    rbx,rax
     c44:	77 03                	ja     0xc49
     c46:	48 89 d1             	mov    rcx,rdx
     c49:	49 b8 ee 15 66 90 c6 	movabs r8,0xee0330c6906615ee
     c50:	30 03 ee 
     c53:	48 89 ca             	mov    rdx,rcx
     c56:	4c 31 c2             	xor    rdx,r8
     c59:	48 01 f2             	add    rdx,rsi
     c5c:	48 8b b7 78 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb78]
     c63:	4c 8b 87 38 08 00 00 	mov    r8,QWORD PTR [rdi+0x838]
     c6a:	48 8b 87 f8 04 00 00 	mov    rax,QWORD PTR [rdi+0x4f8]
     c71:	48 8b 9f b8 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1b8]
     c78:	4c 89 c1             	mov    rcx,r8
     c7b:	48 39 c3             	cmp    rbx,rax
     c7e:	77 03                	ja     0xc83
     c80:	48 89 f1             	mov    rcx,rsi
     c83:	49 b8 83 05 e9 6e 0a 	movabs r8,0xbf37560a6ee90583
     c8a:	56 37 bf 
     c8d:	48 89 ce             	mov    rsi,rcx
     c90:	4c 31 c6             	xor    rsi,r8
     c93:	48 01 d6             	add    rsi,rdx
     c96:	48 8b 97 80 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb80]
     c9d:	4c 8b 87 40 08 00 00 	mov    r8,QWORD PTR [rdi+0x840]
     ca4:	48 8b 87 00 05 00 00 	mov    rax,QWORD PTR [rdi+0x500]
     cab:	48 8b 9f c0 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1c0]
     cb2:	4c 89 c1             	mov    rcx,r8
     cb5:	48 39 c3             	cmp    rbx,rax
     cb8:	77 03                	ja     0xcbd
     cba:	48 89 d1             	mov    rcx,rdx
     cbd:	49 b8 18 f5 6b 4d 4e 	movabs r8,0x906b7b4e4d6bf518
     cc4:	7b 6b 90 
     cc7:	48 89 ca             	mov    rdx,rcx
     cca:	4c 31 c2             	xor    rdx,r8
     ccd:	48 01 f2             	add    rdx,rsi
     cd0:	48 8b b7 88 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb88]
     cd7:	4c 8b 87 48 08 00 00 	mov    r8,QWORD PTR [rdi+0x848]
     cde:	48 8b 87 08 05 00 00 	mov    rax,QWORD PTR [rdi+0x508]
     ce5:	48 8b 9f c8 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1c8]
     cec:	4c 89 c1             	mov    rcx,r8
     cef:	48 39 c3             	cmp    rbx,rax
     cf2:	77 03                	ja     0xcf7
     cf4:	48 89 f1             	mov    rcx,rsi
     cf7:	49 b8 ad e4 ee 2b 92 	movabs r8,0x619fa0922beee4ad
     cfe:	a0 9f 61 
     d01:	48 89 ce             	mov    rsi,rcx
     d04:	4c 31 c6             	xor    rsi,r8
     d07:	48 01 d6             	add    rsi,rdx
     d0a:	48 8b 97 90 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xb90]
     d11:	4c 8b 87 50 08 00 00 	mov    r8,QWORD PTR [rdi+0x850]
     d18:	48 8b 87 10 05 00 00 	mov    rax,QWORD PTR [rdi+0x510]
     d1f:	48 8b 9f d0 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1d0]
     d26:	4c 89 c1             	mov    rcx,r8
     d29:	48 39 c3             	cmp    rbx,rax
     d2c:	77 03                	ja     0xd31
     d2e:	48 89 d1             	mov    rcx,rdx
     d31:	49 b8 42 d4 71 0a d6 	movabs r8,0x32d3c5d60a71d442
     d38:	c5 d3 32 
     d3b:	48 89 ca             	mov    rdx,rcx
     d3e:	4c 31 c2             	xor    rdx,r8
     d41:	48 01 f2             	add    rdx,rsi
     d44:	48 8b b7 98 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xb98]
     d4b:	4c 8b 87 58 08 00 00 	mov    r8,QWORD PTR [rdi+0x858]
     d52:	48 8b 87 18 05 00 00 	mov    rax,QWORD PTR [rdi+0x518]
     d59:	48 8b 9f d8 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1d8]
     d60:	4c 89 c1             	mov    rcx,r8
     d63:	48 39 c3             	cmp    rbx,rax
     d66:	77 03                	ja     0xd6b
     d68:	48 89 f1             	mov    rcx,rsi
     d6b:	49 b8 d7 c3 f4 e8 19 	movabs r8,0x407eb19e8f4c3d7
     d72:	eb 07 04 
     d75:	48 89 ce             	mov    rsi,rcx
     d78:	4c 31 c6             	xor    rsi,r8
     d7b:	48 01 d6             	add    rsi,rdx
     d7e:	48 8b 97 a0 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xba0]
     d85:	4c 8b 87 60 08 00 00 	mov    r8,QWORD PTR [rdi+0x860]
     d8c:	48 8b 87 20 05 00 00 	mov    rax,QWORD PTR [rdi+0x520]
     d93:	48 8b 9f e0 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1e0]
     d9a:	4c 89 c1             	mov    rcx,r8
     d9d:	48 39 c3             	cmp    rbx,rax
     da0:	77 03                	ja     0xda5
     da2:	48 89 d1             	mov    rcx,rdx
     da5:	49 b8 6c b3 77 c7 5d 	movabs r8,0xd53c105dc777b36c
     dac:	10 3c d5 
     daf:	48 89 ca             	mov    rdx,rcx
     db2:	4c 31 c2             	xor    rdx,r8
     db5:	48 01 f2             	add    rdx,rsi
     db8:	48 8b b7 a8 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xba8]
     dbf:	4c 8b 87 68 08 00 00 	mov    r8,QWORD PTR [rdi+0x868]
     dc6:	48 8b 87 28 05 00 00 	mov    rax,QWORD PTR [rdi+0x528]
     dcd:	48 8b 9f e8 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1e8]
     dd4:	4c 89 c1             	mov    rcx,r8
     dd7:	48 39 c3             	cmp    rbx,rax
     dda:	77 03                	ja     0xddf
     ddc:	48 89 f1             	mov    rcx,rsi
     ddf:	49 b8 01 a3 fa a5 a1 	movabs r8,0xa67035a1a5faa301
     de6:	35 70 a6 
     de9:	48 89 ce             	mov    rsi,rcx
     dec:	4c 31 c6             	xor    rsi,r8
     def:	48 01 d6             	add    rsi,rdx
     df2:	48 8b 97 b0 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xbb0]
     df9:	4c 8b 87 70 08 00 00 	mov    r8,QWORD PTR [rdi+0x870]
     e00:	48 8b 87 30 05 00 00 	mov    rax,QWORD PTR [rdi+0x530]
     e07:	48 8b 9f f0 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1f0]
     e0e:	4c 89 c1             	mov    rcx,r8
     e11:	48 39 c3             	cmp    rbx,rax
     e14:	77 03                	ja     0xe19
     e16:	48 89 d1             	mov    rcx,rdx
     e19:	49 b8 96 92 7d 84 e5 	movabs r8,0x77a45ae5847d9296
     e20:	5a a4 77 
     e23:	48 89 ca             	mov    rdx,rcx
     e26:	4c 31 c2             	xor    rdx,r8
     e29:	48 01 f2             	add    rdx,rsi
     e2c:	48 8b b7 b8 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xbb8]
     e33:	4c 8b 87 78 08 00 00 	mov    r8,QWORD PTR [rdi+0x878]
     e3a:	48 8b 87 38 05 00 00 	mov    rax,QWORD PTR [rdi+0x538]
     e41:	48 8b 9f f8 01 00 00 	mov    rbx,QWORD PTR [rdi+0x1f8]
     e48:	4c 89 c1             	mov    rcx,r8
     e4b:	48 39 c3             	cmp    rbx,rax
     e4e:	77 03                	ja     0xe53
     e50:	48 89 f1             	mov    rcx,rsi
     e53:	49 b8 2b 82 00 63 29 	movabs r8,0x48d880296300822b
     e5a:	80 d8 48 
     e5d:	48 89 ce             	mov    rsi,rcx
     e60:	4c 31 c6             	xor    rsi,r8
     e63:	48 01 d6             	add    rsi,rdx
     e66:	48 8b 97 c0 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xbc0]
     e6d:	4c 8b 87 80 08 00 00 	mov    r8,QWORD PTR [rdi+0x880]
     e74:	48 8b 87 40 05 00 00 	mov    rax,QWORD PTR [rdi+0x540]
     e7b:	48 8b 9f 00 02 00 00 	mov    rbx,QWORD PTR [rdi+0x200]
     e82:	4c 89 c1             	mov    rcx,r8
     e85:	48 39 c3             	cmp    rbx,rax
     e88:	77 03                	ja     0xe8d
     e8a:	48 89 d1             	mov    rcx,rdx
     e8d:	49 b8 c0 71 83 41 6d 	movabs r8,0x1a0ca56d418371c0
     e94:	a5 0c 1a 
     e97:	48 89 ca             	mov    rdx,rcx
     e9a:	4c 31 c2             	xor    rdx,r8
     e9d:	48 01 f2             	add    rdx,rsi
     ea0:	48 8b b7 c8 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xbc8]
     ea7:	4c 8b 87 88 08 00 00 	mov    r8,QWORD PTR [rdi+0x888]
     eae:	48 8b 87 48 05 00 00 	mov    rax,QWORD PTR [rdi+0x548]
     eb5:	48 8b 9f 08 02 00 00 	mov    rbx,QWORD PTR [rdi+0x208]
     ebc:	4c 89 c1             	mov    rcx,r8
     ebf:	48 39 c3             	cmp    rbx,rax
     ec2:	77 03                	ja     0xec7
     ec4:	48 89 f1             	mov    rcx,rsi
     ec7:	49 b8 55 61 06 20 b1 	movabs r8,0xeb40cab120066155
     ece:	ca 40 eb 
     ed1:	48 89 ce             	mov    rsi,rcx
     ed4:	4c 31 c6             	xor    rsi,r8
     ed7:	48 01 d6             	add    rsi,rdx
     eda:	48 8b 97 d0 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xbd0]
     ee1:	4c 8b 87 90 08 00 00 	mov    r8,QWORD PTR [rdi+0x890]
     ee8:	48 8b 87 50 05 00 00 	mov    rax,QWORD PTR [rdi+0x550]
     eef:	48 8b 9f 10 02 00 00 	mov    rbx,QWORD PTR [rdi+0x210]
     ef6:	4c 89 c1             	mov    rcx,r8
     ef9:	48 39 c3             	cmp    rbx,rax
     efc:	77 03                	ja     0xf01
     efe:	48 89 d1             	mov    rcx,rdx
     f01:	49 b8 ea 50 89 fe f4 	movabs r8,0xbc74eff4fe8950ea
     f08:	ef 74 bc 
     f0b:	48 89 ca             	mov    rdx,rcx
     f0e:	4c 31 c2             	xor    rdx,r8
     f11:	48 01 f2             	add    rdx,rsi
     f14:	48 8b b7 d8 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xbd8]
     f1b:	4c 8b 87 98 08 00 00 	mov    r8,QWORD PTR [rdi+0x898]
     f22:	48 8b 87 58 05 00 00 	mov    rax,QWORD PTR [rdi+0x558]
     f29:	48 8b 9f 18 02 00 00 	mov    rbx,QWORD PTR [rdi+0x218]
     f30:	4c 89 c1             	mov    rcx,r8
     f33:	48 39 c3             	cmp    rbx,rax
     f36:	77 03                	ja     0xf3b
     f38:	48 89 f1             	mov    rcx,rsi
     f3b:	49 b8 7f 40 0c dd 38 	movabs r8,0x8da91538dd0c407f
     f42:	15 a9 8d 
     f45:	48 89 ce             	mov    rsi,rcx
     f48:	4c 31 c6             	xor    rsi,r8
     f4b:	48 01 d6             	add    rsi,rdx
     f4e:	48 8b 97 e0 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xbe0]
     f55:	4c 8b 87 a0 08 00 00 	mov    r8,QWORD PTR [rdi+0x8a0]
     f5c:	48 8b 87 60 05 00 00 	mov    rax,QWORD PTR [rdi+0x560]
     f63:	48 8b 9f 20 02 00 00 	mov    rbx,QWORD PTR [rdi+0x220]
     f6a:	4c 89 c1             	mov    rcx,r8
     f6d:	48 39 c3             	cmp    rbx,rax
     f70:	77 03                	ja     0xf75
     f72:	48 89 d1             	mov    rcx,rdx
     f75:	49 b8 14 30 8f bb 7c 	movabs r8,0x5edd3a7cbb8f3014
     f7c:	3a dd 5e 
     f7f:	48 89 ca             	mov    rdx,rcx
     f82:	4c 31 c2             	xor    rdx,r8
     f85:	48 01 f2             	add    rdx,rsi
     f88:	48 8b b7 e8 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xbe8]
     f8f:	4c 8b 87 a8 08 00 00 	mov    r8,QWORD PTR [rdi+0x8a8]
     f96:	48 8b 87 68 05 00 00 	mov    rax,QWORD PTR [rdi+0x568]
     f9d:	48 8b 9f 28 02 00 00 	mov    rbx,QWORD PTR [rdi+0x228]
     fa4:	4c 89 c1             	mov    rcx,r8
     fa7:	48 39 c3             	cmp    rbx,rax
     faa:	77 03                	ja     0xfaf
     fac:	48 89 f1             	mov    rcx,rsi
     faf:	49 b8 a9 1f 12 9a c0 	movabs r8,0x30115fc09a121fa9
     fb6:	5f 11 30 
     fb9:	48 89 ce             	mov    rsi,rcx
     fbc:	4c 31 c6             	xor    rsi,r8
     fbf:	48 01 d6             	add    rsi,rdx
     fc2:	48 8b 97 f0 0b 00 00 	mov    rdx,QWORD PTR [rdi+0xbf0]
     fc9:	4c 8b 87 b0 08 00 00 	mov    r8,QWORD PTR [rdi+0x8b0]
     fd0:	48 8b 87 70 05 00 00 	mov    rax,QWORD PTR [rdi+0x570]
     fd7:	48 8b 9f 30 02 00 00 	mov    rbx,QWORD PTR [rdi+0x230]
     fde:	4c 89 c1             	mov    rcx,r8
     fe1:	48 39 c3             	cmp    rbx,rax
     fe4:	77 03                	ja     0xfe9
     fe6:	48 89 d1             	mov    rcx,rdx
     fe9:	49 b8 3e 0f 95 78 04 	movabs r8,0x145850478950f3e
     ff0:	85 45 01 
     ff3:	48 89 ca             	mov    rdx,rcx
     ff6:	4c 31 c2             	xor    rdx,r8
     ff9:	48 01 f2             	add    rdx,rsi
     ffc:	48 8b b7 f8 0b 00 00 	mov    rsi,QWORD PTR [rdi+0xbf8]
    1003:	4c 8b 87 b8 08 00 00 	mov    r8,QWORD PTR [rdi+0x8b8]
    100a:	48 8b 87 78 05 00 00 	mov    rax,QWORD PTR [rdi+0x578]
    1011:	48 8b 9f 38 02 00 00 	mov    rbx,QWORD PTR [rdi+0x238]
    1018:	4c 89 c1             	mov    rcx,r8
    101b:	48 39 c3             	cmp    rbx,rax
    101e:	77 03                	ja     0x1023
    1020:	48 89 f1             	mov    rcx,rsi
    1023:	49 b8 d3 fe 17 57 48 	movabs r8,0xd279aa485717fed3
    102a:	aa 79 d2 
    102d:	48 89 ce             	mov    rsi,rcx
    1030:	4c 31 c6             	xor    rsi,r8
    1033:	48 01 d6             	add    rsi,rdx
    1036:	48 8b 97 00 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc00]
    103d:	4c 8b 87 c0 08 00 00 	mov    r8,QWORD PTR [rdi+0x8c0]
    1044:	48 8b 87 80 05 00 00 	mov    rax,QWORD PTR [rdi+0x580]
    104b:	48 8b 9f 40 02 00 00 	mov    rbx,QWORD PTR [rdi+0x240]
    1052:	4c 89 c1             	mov    rcx,r8
    1055:	48 39 c3             	cmp    rbx,rax
    1058:	77 03                	ja     0x105d
    105a:	48 89 d1             	mov    rcx,rdx
    105d:	49 b8 68 ee 9a 35 8c 	movabs r8,0xa3adcf8c359aee68
    1064:	cf ad a3 
    1067:	48 89 ca             	mov    rdx,rcx
    106a:	4c 31 c2             	xor    rdx,r8
    106d:	48 01 f2             	add    rdx,rsi
    1070:	48 8b b7 08 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc08]
    1077:	4c 8b 87 c8 08 00 00 	mov    r8,QWORD PTR [rdi+0x8c8]
    107e:	48 8b 87 88 05 00 00 	mov    rax,QWORD PTR [rdi+0x588]
    1085:	48 8b 9f 48 02 00 00 	mov    rbx,QWORD PTR [rdi+0x248]
    108c:	4c 89 c1             	mov    rcx,r8
    108f:	48 39 c3             	cmp    rbx,rax
    1092:	77 03                	ja     0x1097
    1094:	48 89 f1             	mov    rcx,rsi
    1097:	49 b8 fd dd 1d 14 d0 	movabs r8,0x74e1f4d0141dddfd
    109e:	f4 e1 74 
    10a1:	48 89 ce             	mov    rsi,rcx
    10a4:	4c 31 c6             	xor    rsi,r8
    10a7:	48 01 d6             	add    rsi,rdx
    10aa:	48 8b 97 10 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc10]
    10b1:	4c 8b 87 d0 08 00 00 	mov    r8,QWORD PTR [rdi+0x8d0]
    10b8:	48 8b 87 90 05 00 00 	mov    rax,QWORD PTR [rdi+0x590]
    10bf:	48 8b 9f 50 02 00 00 	mov    rbx,QWORD PTR [rdi+0x250]
    10c6:	4c 89 c1             	mov    rcx,r8
    10c9:	48 39 c3             	cmp    rbx,rax
    10cc:	77 03                	ja     0x10d1
    10ce:	48 89 d1             	mov    rcx,rdx
    10d1:	49 b8 92 cd a0 f2 13 	movabs r8,0x46161a13f2a0cd92
    10d8:	1a 16 46 
    10db:	48 89 ca             	mov    rdx,rcx
    10de:	4c 31 c2             	xor    rdx,r8
    10e1:	48 01 f2             	add    rdx,rsi
    10e4:	48 8b b7 18 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc18]
    10eb:	4c 8b 87 d8 08 00 00 	mov    r8,QWORD PTR [rdi+0x8d8]
    10f2:	48 8b 87 98 05 00 00 	mov    rax,QWORD PTR [rdi+0x598]
    10f9:	48 8b 9f 58 02 00 00 	mov    rbx,QWORD PTR [rdi+0x258]
    1100:	4c 89 c1             	mov    rcx,r8
    1103:	48 39 c3             	cmp    rbx,rax
    1106:	77 03                	ja     0x110b
    1108:	48 89 f1             	mov    rcx,rsi
    110b:	49 b8 27 bd 23 d1 57 	movabs r8,0x174a3f57d123bd27
    1112:	3f 4a 17 
    1115:	48 89 ce             	mov    rsi,rcx
    1118:	4c 31 c6             	xor    rsi,r8
    111b:	48 01 d6             	add    rsi,rdx
    111e:	48 8b 97 20 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc20]
    1125:	4c 8b 87 e0 08 00 00 	mov    r8,QWORD PTR [rdi+0x8e0]
    112c:	48 8b 87 a0 05 00 00 	mov    rax,QWORD PTR [rdi+0x5a0]
    1133:	48 8b 9f 60 02 00 00 	mov    rbx,QWORD PTR [rdi+0x260]
    113a:	4c 89 c1             	mov    rcx,r8
    113d:	48 39 c3             	cmp    rbx,rax
    1140:	77 03                	ja     0x1145
    1142:	48 89 d1             	mov    rcx,rdx
    1145:	49 b8 bc ac a6 af 9b 	movabs r8,0xe87e649bafa6acbc
    114c:	64 7e e8 
    114f:	48 89 ca             	mov    rdx,rcx
    1152:	4c 31 c2             	xor    rdx,r8
    1155:	48 01 f2             	add    rdx,rsi
    1158:	48 8b b7 28 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc28]
    115f:	4c 8b 87 e8 08 00 00 	mov    r8,QWORD PTR [rdi+0x8e8]
    1166:	48 8b 87 a8 05 00 00 	mov    rax,QWORD PTR [rdi+0x5a8]
    116d:	48 8b 9f 68 02 00 00 	mov    rbx,QWORD PTR [rdi+0x268]
    1174:	4c 89 c1             	mov    rcx,r8
    1177:	48 39 c3             	cmp    rbx,rax
    117a:	77 03                	ja     0x117f
    117c:	48 89 f1             	mov    rcx,rsi
    117f:	49 b8 51 9c 29 8e df 	movabs r8,0xb9b289df8e299c51
    1186:	89 b2 b9 
    1189:	48 89 ce             	mov    rsi,rcx
    118c:	4c 31 c6             	xor    rsi,r8
    118f:	48 01 d6             	add    rsi,rdx
    1192:	48 8b 97 30 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc30]
    1199:	4c 8b 87 f0 08 00 00 	mov    r8,QWORD PTR [rdi+0x8f0]
    11a0:	48 8b 87 b0 05 00 00 	mov    rax,QWORD PTR [rdi+0x5b0]
    11a7:	48 8b 9f 70 02 00 00 	mov    rbx,QWORD PTR [rdi+0x270]
    11ae:	4c 89 c1             	mov    rcx,r8
    11b1:	48 39 c3             	cmp    rbx,rax
    11b4:	77 03                	ja     0x11b9
    11b6:	48 89 d1             	mov    rcx,rdx
    11b9:	49 b8 e6 8b ac 6c 23 	movabs r8,0x8ae6af236cac8be6
    11c0:	af e6 8a 
    11c3:	48 89 ca             	mov    rdx,rcx
    11c6:	4c 31 c2             	xor    rdx,r8
    11c9:	48 01 f2             	add    rdx,rsi
    11cc:	48 8b b7 38 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc38]
    11d3:	4c 8b 87 f8 08 00 00 	mov    r8,QWORD PTR [rdi+0x8f8]
    11da:	48 8b 87 b8 05 00 00 	mov    rax,QWORD PTR [rdi+0x5b8]
    11e1:	48 8b 9f 78 02 00 00 	mov    rbx,QWORD PTR [rdi+0x278]
    11e8:	4c 89 c1             	mov    rcx,r8
    11eb:	48 39 c3             	cmp    rbx,rax
    11ee:	77 03                	ja     0x11f3
    11f0:	48 89 f1             	mov    rcx,rsi
    11f3:	49 b8 7b 7b 2f 4b 67 	movabs r8,0x5c1ad4674b2f7b7b
    11fa:	d4 1a 5c 
    11fd:	48 89 ce             	mov    rsi,rcx
    1200:	4c 31 c6             	xor    rsi,r8
    1203:	48 01 d6             	add    rsi,rdx
    1206:	48 8b 97 40 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc40]
    120d:	4c 8b 87 00 09 00 00 	mov    r8,QWORD PTR [rdi+0x900]
    1214:	48 8b 87 c0 05 00 00 	mov    rax,QWORD PTR [rdi+0x5c0]
    121b:	48 8b 9f 80 02 00 00 	mov    rbx,QWORD PTR [rdi+0x280]
    1222:	4c 89 c1             	mov    rcx,r8
    1225:	48 39 c3             	cmp    rbx,rax
    1228:	77 03                	ja     0x122d
    122a:	48 89 d1             	mov    rcx,rdx
    122d:	49 b8 10 6b b2 29 ab 	movabs r8,0x2d4ef9ab29b26b10
    1234:	f9 4e 2d 
    1237:	48 89 ca             	mov    rdx,rcx
    123a:	4c 31 c2             	xor    rdx,r8
    123d:	48 01 f2             	add    rdx,rsi
    1240:	48 8b b7 48 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc48]
    1247:	4c 8b 87 08 09 00 00 	mov    r8,QWORD PTR [rdi+0x908]
    124e:	48 8b 87 c8 05 00 00 	mov    rax,QWORD PTR [rdi+0x5c8]
    1255:	48 8b 9f 88 02 00 00 	mov    rbx,QWORD PTR [rdi+0x288]
    125c:	4c 89 c1             	mov    rcx,r8
    125f:	48 39 c3             	cmp    rbx,rax
    1262:	77 03                	ja     0x1267
    1264:	48 89 f1             	mov    rcx,rsi
    1267:	49 b8 a5 5a 35 08 ef 	movabs r8,0xfe831eef08355aa5
    126e:	1e 83 fe 
    1271:	48 89 ce             	mov    rsi,rcx
    1274:	4c 31 c6             	xor    rsi,r8
    1277:	48 01 d6             	add    rsi,rdx
    127a:	48 8b 97 50 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc50]
    1281:	4c 8b 87 10 09 00 00 	mov    r8,QWORD PTR [rdi+0x910]
    1288:	48 8b 87 d0 05 00 00 	mov    rax,QWORD PTR [rdi+0x5d0]
    128f:	48 8b 9f 90 02 00 00 	mov    rbx,QWORD PTR [rdi+0x290]
    1296:	4c 89 c1             	mov    rcx,r8
    1299:	48 39 c3             	cmp    rbx,rax
    129c:	77 03                	ja     0x12a1
    129e:	48 89 d1             	mov    rcx,rdx
    12a1:	49 b8 3a 4a b8 e6 32 	movabs r8,0xcfb74432e6b84a3a
    12a8:	44 b7 cf 
    12ab:	48 89 ca             	mov    rdx,rcx
    12ae:	4c 31 c2             	xor    rdx,r8
    12b1:	48 01 f2             	add    rdx,rsi
    12b4:	48 8b b7 58 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc58]
    12bb:	4c 8b 87 18 09 00 00 	mov    r8,QWORD PTR [rdi+0x918]
    12c2:	48 8b 87 d8 05 00 00 	mov    rax,QWORD PTR [rdi+0x5d8]
    12c9:	48 8b 9f 98 02 00 00 	mov    rbx,QWORD PTR [rdi+0x298]
    12d0:	4c 89 c1             	mov    rcx,r8
    12d3:	48 39 c3             	cmp    rbx,rax
    12d6:	77 03                	ja     0x12db
    12d8:	48 89 f1             	mov    rcx,rsi
    12db:	49 b8 cf 39 3b c5 76 	movabs r8,0xa0eb6976c53b39cf
    12e2:	69 eb a0 
    12e5:	48 89 ce             	mov    rsi,rcx
    12e8:	4c 31 c6             	xor    rsi,r8
    12eb:	48 01 d6             	add    rsi,rdx
    12ee:	48 8b 97 60 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc60]
    12f5:	4c 8b 87 20 09 00 00 	mov    r8,QWORD PTR [rdi+0x920]
    12fc:	48 8b 87 e0 05 00 00 	mov    rax,QWORD PTR [rdi+0x5e0]
    1303:	48 8b 9f a0 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2a0]
    130a:	4c 89 c1             	mov    rcx,r8
    130d:	48 39 c3             	cmp    rbx,rax
    1310:	77 03                	ja     0x1315
    1312:	48 89 d1             	mov    rcx,rdx
    1315:	49 b8 64 29 be a3 ba 	movabs r8,0x721f8ebaa3be2964
    131c:	8e 1f 72 
    131f:	48 89 ca             	mov    rdx,rcx
    1322:	4c 31 c2             	xor    rdx,r8
    1325:	48 01 f2             	add    rdx,rsi
    1328:	48 8b b7 68 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc68]
    132f:	4c 8b 87 28 09 00 00 	mov    r8,QWORD PTR [rdi+0x928]
    1336:	48 8b 87 e8 05 00 00 	mov    rax,QWORD PTR [rdi+0x5e8]
    133d:	48 8b 9f a8 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2a8]
    1344:	4c 89 c1             	mov    rcx,r8
    1347:	48 39 c3             	cmp    rbx,rax
    134a:	77 03                	ja     0x134f
    134c:	48 89 f1             	mov    rcx,rsi
    134f:	49 b8 f9 18 41 82 fe 	movabs r8,0x4353b3fe824118f9
    1356:	b3 53 43 
    1359:	48 89 ce             	mov    rsi,rcx
    135c:	4c 31 c6             	xor    rsi,r8
    135f:	48 01 d6             	add    rsi,rdx
    1362:	48 8b 97 70 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc70]
    1369:	4c 8b 87 30 09 00 00 	mov    r8,QWORD PTR [rdi+0x930]
    1370:	48 8b 87 f0 05 00 00 	mov    rax,QWORD PTR [rdi+0x5f0]
    1377:	48 8b 9f b0 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2b0]
    137e:	4c 89 c1             	mov    rcx,r8
    1381:	48 39 c3             	cmp    rbx,rax
    1384:	77 03                	ja     0x1389
    1386:	48 89 d1             	mov    rcx,rdx
    1389:	49 b8 8e 08 c4 60 42 	movabs r8,0x1487d94260c4088e
    1390:	d9 87 14 
    1393:	48 89 ca             	mov    rdx,rcx
    1396:	4c 31 c2             	xor    rdx,r8
    1399:	48 01 f2             	add    rdx,rsi
    139c:	48 8b b7 78 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc78]
    13a3:	4c 8b 87 38 09 00 00 	mov    r8,QWORD PTR [rdi+0x938]
    13aa:	48 8b 87 f8 05 00 00 	mov    rax,QWORD PTR [rdi+0x5f8]
    13b1:	48 8b 9f b8 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2b8]
    13b8:	4c 89 c1             	mov    rcx,r8
    13bb:	48 39 c3             	cmp    rbx,rax
    13be:	77 03                	ja     0x13c3
    13c0:	48 89 f1             	mov    rcx,rsi
    13c3:	49 b8 23 f8 46 3f 86 	movabs r8,0xe5bbfe863f46f823
    13ca:	fe bb e5 
    13cd:	48 89 ce             	mov    rsi,rcx
    13d0:	4c 31 c6             	xor    rsi,r8
    13d3:	48 01 d6             	add    rsi,rdx
    13d6:	48 8b 97 80 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc80]
    13dd:	4c 8b 87 40 09 00 00 	mov    r8,QWORD PTR [rdi+0x940]
    13e4:	48 8b 87 00 06 00 00 	mov    rax,QWORD PTR [rdi+0x600]
    13eb:	48 8b 9f c0 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2c0]
    13f2:	4c 89 c1             	mov    rcx,r8
    13f5:	48 39 c3             	cmp    rbx,rax
    13f8:	77 03                	ja     0x13fd
    13fa:	48 89 d1             	mov    rcx,rdx
    13fd:	49 b8 b8 e7 c9 1d ca 	movabs r8,0xb6f023ca1dc9e7b8
    1404:	23 f0 b6 
    1407:	48 89 ca             	mov    rdx,rcx
    140a:	4c 31 c2             	xor    rdx,r8
    140d:	48 01 f2             	add    rdx,rsi
    1410:	48 8b b7 88 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc88]
    1417:	4c 8b 87 48 09 00 00 	mov    r8,QWORD PTR [rdi+0x948]
    141e:	48 8b 87 08 06 00 00 	mov    rax,QWORD PTR [rdi+0x608]
    1425:	48 8b 9f c8 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2c8]
    142c:	4c 89 c1             	mov    rcx,r8
    142f:	48 39 c3             	cmp    rbx,rax
    1432:	77 03                	ja     0x1437
    1434:	48 89 f1             	mov    rcx,rsi
    1437:	49 b8 4d d7 4c fc 0d 	movabs r8,0x8824490dfc4cd74d
    143e:	49 24 88 
    1441:	48 89 ce             	mov    rsi,rcx
    1444:	4c 31 c6             	xor    rsi,r8
    1447:	48 01 d6             	add    rsi,rdx
    144a:	48 8b 97 90 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xc90]
    1451:	4c 8b 87 50 09 00 00 	mov    r8,QWORD PTR [rdi+0x950]
    1458:	48 8b 87 10 06 00 00 	mov    rax,QWORD PTR [rdi+0x610]
    145f:	48 8b 9f d0 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2d0]
    1466:	4c 89 c1             	mov    rcx,r8
    1469:	48 39 c3             	cmp    rbx,rax
    146c:	77 03                	ja     0x1471
    146e:	48 89 d1             	mov    rcx,rdx
    1471:	49 b8 e2 c6 cf da 51 	movabs r8,0x59586e51dacfc6e2
    1478:	6e 58 59 
    147b:	48 89 ca             	mov    rdx,rcx
    147e:	4c 31 c2             	xor    rdx,r8
    1481:	48 01 f2             	add    rdx,rsi
    1484:	48 8b b7 98 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xc98]
    148b:	4c 8b 87 58 09 00 00 	mov    r8,QWORD PTR [rdi+0x958]
    1492:	48 8b 87 18 06 00 00 	mov    rax,QWORD PTR [rdi+0x618]
    1499:	48 8b 9f d8 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2d8]
    14a0:	4c 89 c1             	mov    rcx,r8
    14a3:	48 39 c3             	cmp    rbx,rax
    14a6:	77 03                	ja     0x14ab
    14a8:	48 89 f1             	mov    rcx,rsi
    14ab:	49 b8 77 b6 52 b9 95 	movabs r8,0x2a8c9395b952b677
    14b2:	93 8c 2a 
    14b5:	48 89 ce             	mov    rsi,rcx
    14b8:	4c 31 c6             	xor    rsi,r8
    14bb:	48 01 d6             	add    rsi,rdx
    14be:	48 8b 97 a0 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xca0]
    14c5:	4c 8b 87 60 09 00 00 	mov    r8,QWORD PTR [rdi+0x960]
    14cc:	48 8b 87 20 06 00 00 	mov    rax,QWORD PTR [rdi+0x620]
    14d3:	48 8b 9f e0 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2e0]
    14da:	4c 89 c1             	mov    rcx,r8
    14dd:	48 39 c3             	cmp    rbx,rax
    14e0:	77 03                	ja     0x14e5
    14e2:	48 89 d1             	mov    rcx,rdx
    14e5:	49 b8 0c a6 d5 97 d9 	movabs r8,0xfbc0b8d997d5a60c
    14ec:	b8 c0 fb 
    14ef:	48 89 ca             	mov    rdx,rcx
    14f2:	4c 31 c2             	xor    rdx,r8
    14f5:	48 01 f2             	add    rdx,rsi
    14f8:	48 8b b7 a8 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xca8]
    14ff:	4c 8b 87 68 09 00 00 	mov    r8,QWORD PTR [rdi+0x968]
    1506:	48 8b 87 28 06 00 00 	mov    rax,QWORD PTR [rdi+0x628]
    150d:	48 8b 9f e8 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2e8]
    1514:	4c 89 c1             	mov    rcx,r8
    1517:	48 39 c3             	cmp    rbx,rax
    151a:	77 03                	ja     0x151f
    151c:	48 89 f1             	mov    rcx,rsi
    151f:	49 b8 a1 95 58 76 1d 	movabs r8,0xccf4de1d765895a1
    1526:	de f4 cc 
    1529:	48 89 ce             	mov    rsi,rcx
    152c:	4c 31 c6             	xor    rsi,r8
    152f:	48 01 d6             	add    rsi,rdx
    1532:	48 8b 97 b0 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xcb0]
    1539:	4c 8b 87 70 09 00 00 	mov    r8,QWORD PTR [rdi+0x970]
    1540:	48 8b 87 30 06 00 00 	mov    rax,QWORD PTR [rdi+0x630]
    1547:	48 8b 9f f0 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2f0]
    154e:	4c 89 c1             	mov    rcx,r8
    1551:	48 39 c3             	cmp    rbx,rax
    1554:	77 03                	ja     0x1559
    1556:	48 89 d1             	mov    rcx,rdx
    1559:	49 b8 36 85 db 54 61 	movabs r8,0x9e29036154db8536
    1560:	03 29 9e 
    1563:	48 89 ca             	mov    rdx,rcx
    1566:	4c 31 c2             	xor    rdx,r8
    1569:	48 01 f2             	add    rdx,rsi
    156c:	48 8b b7 b8 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xcb8]
    1573:	4c 8b 87 78 09 00 00 	mov    r8,QWORD PTR [rdi+0x978]
    157a:	48 8b 87 38 06 00 00 	mov    rax,QWORD PTR [rdi+0x638]
    1581:	48 8b 9f f8 02 00 00 	mov    rbx,QWORD PTR [rdi+0x2f8]
    1588:	4c 89 c1             	mov    rcx,r8
    158b:	48 39 c3             	cmp    rbx,rax
    158e:	77 03                	ja     0x1593
    1590:	48 89 f1             	mov    rcx,rsi
    1593:	49 b8 cb 74 5e 33 a5 	movabs r8,0x6f5d28a5335e74cb
    159a:	28 5d 6f 
    159d:	48 89 ce             	mov    rsi,rcx
    15a0:	4c 31 c6             	xor    rsi,r8
    15a3:	48 01 d6             	add    rsi,rdx
    15a6:	48 8b 97 c0 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xcc0]
    15ad:	4c 8b 87 80 09 00 00 	mov    r8,QWORD PTR [rdi+0x980]
    15b4:	48 8b 87 40 06 00 00 	mov    rax,QWORD PTR [rdi+0x640]
    15bb:	48 8b 9f 00 03 00 00 	mov    rbx,QWORD PTR [rdi+0x300]
    15c2:	4c 89 c1             	mov    rcx,r8
    15c5:	48 39 c3             	cmp    rbx,rax
    15c8:	77 03                	ja     0x15cd
    15ca:	48 89 d1             	mov    rcx,rdx
    15cd:	49 b8 60 64 e1 11 e9 	movabs r8,0x40914de911e16460
    15d4:	4d 91 40 
    15d7:	48 89 ca             	mov    rdx,rcx
    15da:	4c 31 c2             	xor    rdx,r8
    15dd:	48 01 f2             	add    rdx,rsi
    15e0:	48 8b b7 c8 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xcc8]
    15e7:	4c 8b 87 88 09 00 00 	mov    r8,QWORD PTR [rdi+0x988]
    15ee:	48 8b 87 48 06 00 00 	mov    rax,QWORD PTR [rdi+0x648]
    15f5:	48 8b 9f 08 03 00 00 	mov    rbx,QWORD PTR [rdi+0x308]
    15fc:	4c 89 c1             	mov    rcx,r8
    15ff:	48 39 c3             	cmp    rbx,rax
    1602:	77 03                	ja     0x1607
    1604:	48 89 f1             	mov    rcx,rsi
    1607:	49 b8 f5 53 64 f0 2c 	movabs r8,0x11c5732cf06453f5
    160e:	73 c5 11 
    1611:	48 89 ce             	mov    rsi,rcx
    1614:	4c 31 c6             	xor    rsi,r8
    1617:	48 01 d6             	add    rsi,rdx
    161a:	48 8b 97 d0 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xcd0]
    1621:	4c 8b 87 90 09 00 00 	mov    r8,QWORD PTR [rdi+0x990]
    1628:	48 8b 87 50 06 00 00 	mov    rax,QWORD PTR [rdi+0x650]
    162f:	48 8b 9f 10 03 00 00 	mov    rbx,QWORD PTR [rdi+0x310]
    1636:	4c 89 c1             	mov    rcx,r8
    1639:	48 39 c3             	cmp    rbx,rax
    163c:	77 03                	ja     0x1641
    163e:	48 89 d1             	mov    rcx,rdx
    1641:	49 b8 8a 43 e7 ce 70 	movabs r8,0xe2f99870cee7438a
    1648:	98 f9 e2 
    164b:	48 89 ca             	mov    rdx,rcx
    164e:	4c 31 c2             	xor    rdx,r8
    1651:	48 01 f2             	add    rdx,rsi
    1654:	48 8b b7 d8 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xcd8]
    165b:	4c 8b 87 98 09 00 00 	mov    r8,QWORD PTR [rdi+0x998]
    1662:	48 8b 87 58 06 00 00 	mov    rax,QWORD PTR [rdi+0x658]
    1669:	48 8b 9f 18 03 00 00 	mov    rbx,QWORD PTR [rdi+0x318]
    1670:	4c 89 c1             	mov    rcx,r8
    1673:	48 39 c3             	cmp    rbx,rax
    1676:	77 03                	ja     0x167b
    1678:	48 89 f1             	mov    rcx,rsi
    167b:	49 b8 1f 33 6a ad b4 	movabs r8,0xb42dbdb4ad6a331f
    1682:	bd 2d b4 
    1685:	48 89 ce             	mov    rsi,rcx
    1688:	4c 31 c6             	xor    rsi,r8
    168b:	48 01 d6             	add    rsi,rdx
    168e:	48 8b 97 e0 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xce0]
    1695:	4c 8b 87 a0 09 00 00 	mov    r8,QWORD PTR [rdi+0x9a0]
    169c:	48 8b 87 60 06 00 00 	mov    rax,QWORD PTR [rdi+0x660]
    16a3:	48 8b 9f 20 03 00 00 	mov    rbx,QWORD PTR [rdi+0x320]
    16aa:	4c 89 c1             	mov    rcx,r8
    16ad:	48 39 c3             	cmp    rbx,rax
    16b0:	77 03                	ja     0x16b5
    16b2:	48 89 d1             	mov    rcx,rdx
    16b5:	49 b8 b4 22 ed 8b f8 	movabs r8,0x8561e2f88bed22b4
    16bc:	e2 61 85 
    16bf:	48 89 ca             	mov    rdx,rcx
    16c2:	4c 31 c2             	xor    rdx,r8
    16c5:	48 01 f2             	add    rdx,rsi
    16c8:	48 8b b7 e8 0c 00 00 	mov    rsi,QWORD PTR [rdi+0xce8]
    16cf:	4c 8b 87 a8 09 00 00 	mov    r8,QWORD PTR [rdi+0x9a8]
    16d6:	48 8b 87 68 06 00 00 	mov    rax,QWORD PTR [rdi+0x668]
    16dd:	48 8b 9f 28 03 00 00 	mov    rbx,QWORD PTR [rdi+0x328]
    16e4:	4c 89 c1             	mov    rcx,r8
    16e7:	48 39 c3             	cmp    rbx,rax
    16ea:	77 03                	ja     0x16ef
    16ec:	48 89 f1             	mov    rcx,rsi
    16ef:	49 b8 49 12 70 6a 3c 	movabs r8,0x5696083c6a701249
    16f6:	08 96 56 
    16f9:	48 89 ce             	mov    rsi,rcx
    16fc:	4c 31 c6             	xor    rsi,r8
    16ff:	48 01 d6             	add    rsi,rdx
    1702:	48 8b 97 f0 0c 00 00 	mov    rdx,QWORD PTR [rdi+0xcf0]
    1709:	4c 8b 87 b0 09 00 00 	mov    r8,QWORD PTR [rdi+0x9b0]
    1710:	48 8b 87 70 06 00 00 	mov    rax,QWORD PTR [rdi+0x670]
    1717:	48 8b 9f 30 03 00 00 	mov    rbx,QWORD PTR [rdi+0x330]
    171e:	4c 89 c1             	mov    rcx,r8
    1721:	48 39 c3             	cmp    rbx,rax
    1724:	77 03                	ja     0x1729
    1726:	48 89 d1             	mov    rcx,rdx
    1729:	49 b8 de 01 f3 48 80 	movabs r8,0x27ca2d8048f301de
    1730:	2d ca 27 
    1733:	48 89 ca             	mov    rdx,rcx
    1736:	4c 31 c2             	xor    rdx,r8
    1739:	48 01 f2             	add    rdx,rsi
    173c:	48 8b 8f f8 0c 00 00 	mov    rcx,QWORD PTR [rdi+0xcf8]
    1743:	4c 8b 87 b8 09 00 00 	mov    r8,QWORD PTR [rdi+0x9b8]
    174a:	48 8b 87 78 06 00 00 	mov    rax,QWORD PTR [rdi+0x678]
    1751:	48 8b 9f 38 03 00 00 	mov    rbx,QWORD PTR [rdi+0x338]
    1758:	4c 89 c6             	mov    rsi,r8
    175b:	48 39 c3             	cmp    rbx,rax
    175e:	77 03                	ja     0x1763
    1760:	48 89 ce             	mov    rsi,rcx
    1763:	49 b8 73 f1 75 27 c4 	movabs r8,0xf8fe52c42775f173
    176a:	52 fe f8 
    176d:	48 89 f1             	mov    rcx,rsi
    1770:	4c 31 c1             	xor    rcx,r8
    1773:	48 01 d1             	add    rcx,rdx
    1776:	48 8b b7 00 0d 00 00 	mov    rsi,QWORD PTR [rdi+0xd00]
    177d:	4c 8b 87 c0 09 00 00 	mov    r8,QWORD PTR [rdi+0x9c0]
    1784:	48 8b 87 80 06 00 00 	mov    rax,QWORD PTR [rdi+0x680]
    178b:	48 8b 9f 40 03 00 00 	mov    rbx,QWORD PTR [rdi+0x340]
    1792:	4c 89 c2             	mov    rdx,r8
    1795:	48 39 c3             	cmp    rbx,rax
    1798:	77 03                	ja     0x179d
    179a:	48 89 f2             	mov    rdx,rsi
    179d:	49 b8 08 e1 f8 05 08 	movabs r8,0xca32780805f8e108
    17a4:	78 32 ca 
    17a7:	48 89 d6             	mov    rsi,rdx
    17aa:	4c 31 c6             	xor    rsi,r8
    17ad:	48 01 ce             	add    rsi,rcx
    17b0:	48 89 f2             	mov    rdx,rsi
    17b3:	48 c1 ea 38          	shr    rdx,0x38
    17b7:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
    17ba:	48 89 f2             	mov    rdx,rsi
    17bd:	48 c1 ea 30          	shr    rdx,0x30
    17c1:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
    17c4:	48 89 f2             	mov    rdx,rsi
    17c7:	48 c1 ea 28          	shr    rdx,0x28
    17cb:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
    17ce:	48 89 f2             	mov    rdx,rsi
    17d1:	48 c1 ea 20          	shr    rdx,0x20
    17d5:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
    17d8:	48 89 f2             	mov    rdx,rsi
    17db:	48 c1 ea 18          	shr    rdx,0x18
    17df:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
    17e2:	48 89 f2             	mov    rdx,rsi
    17e5:	48 c1 ea 10          	shr    rdx,0x10
    17e9:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
    17ec:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
    17f0:	48 c1 ee 08          	shr    rsi,0x8
    17f4:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
    17f8:	b8 02 00 00 00       	mov    eax,0x2
    17fd:	5b                   	pop    rbx
    17fe:	c9                   	leave
    17ff:	c3                   	ret
    1800:	cc                   	int3
