
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/cond_select_dense.llvmbpf.bin:     file format binary


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
      1e:	48 8d 88 08 0d 00 00 	lea    rcx,[rax+0xd08]
      25:	48 39 f1             	cmp    rcx,rsi
      28:	0f 97 c1             	seta   cl
      2b:	08 d1                	or     cl,dl
      2d:	74 03                	je     0x32
      2f:	31 c0                	xor    eax,eax
      31:	c3                   	ret
      32:	48 8d 88 c8 09 00 00 	lea    rcx,[rax+0x9c8]
      39:	48 8d 90 88 06 00 00 	lea    rdx,[rax+0x688]
      40:	48 8b 70 08          	mov    rsi,QWORD PTR [rax+0x8]
      44:	48 8b 78 10          	mov    rdi,QWORD PTR [rax+0x10]
      48:	48 3b b0 48 03 00 00 	cmp    rsi,QWORD PTR [rax+0x348]
      4f:	48 0f 47 ca          	cmova  rcx,rdx
      53:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
      5a:	79 37 9e 
      5d:	48 33 11             	xor    rdx,QWORD PTR [rcx]
      60:	48 8d 88 d0 09 00 00 	lea    rcx,[rax+0x9d0]
      67:	48 3b b8 50 03 00 00 	cmp    rdi,QWORD PTR [rax+0x350]
      6e:	48 8d b0 90 06 00 00 	lea    rsi,[rax+0x690]
      75:	48 0f 47 ce          	cmova  rcx,rsi
      79:	48 be aa 6b cd 5d fd 	movabs rsi,0x6f6b9efd5dcd6baa
      80:	9e 6b 6f 
      83:	48 33 31             	xor    rsi,QWORD PTR [rcx]
      86:	48 01 d6             	add    rsi,rdx
      89:	48 8b 48 18          	mov    rcx,QWORD PTR [rax+0x18]
      8d:	48 8d 90 d8 09 00 00 	lea    rdx,[rax+0x9d8]
      94:	48 8d b8 98 06 00 00 	lea    rdi,[rax+0x698]
      9b:	48 3b 88 58 03 00 00 	cmp    rcx,QWORD PTR [rax+0x358]
      a2:	48 0f 47 d7          	cmova  rdx,rdi
      a6:	48 bf 3f 5b 50 3c 41 	movabs rdi,0x409fc4413c505b3f
      ad:	c4 9f 40 
      b0:	48 33 3a             	xor    rdi,QWORD PTR [rdx]
      b3:	48 8b 48 20          	mov    rcx,QWORD PTR [rax+0x20]
      b7:	48 8d 90 e0 09 00 00 	lea    rdx,[rax+0x9e0]
      be:	4c 8d 80 a0 06 00 00 	lea    r8,[rax+0x6a0]
      c5:	48 3b 88 60 03 00 00 	cmp    rcx,QWORD PTR [rax+0x360]
      cc:	49 0f 47 d0          	cmova  rdx,r8
      d0:	48 b9 d4 4a d3 1a 85 	movabs rcx,0x11d3e9851ad34ad4
      d7:	e9 d3 11 
      da:	48 33 0a             	xor    rcx,QWORD PTR [rdx]
      dd:	48 01 f9             	add    rcx,rdi
      e0:	48 01 f1             	add    rcx,rsi
      e3:	48 8b 50 28          	mov    rdx,QWORD PTR [rax+0x28]
      e7:	48 8d b0 e8 09 00 00 	lea    rsi,[rax+0x9e8]
      ee:	48 3b 90 68 03 00 00 	cmp    rdx,QWORD PTR [rax+0x368]
      f5:	48 8d 90 a8 06 00 00 	lea    rdx,[rax+0x6a8]
      fc:	48 0f 47 f2          	cmova  rsi,rdx
     100:	48 ba 69 3a 56 f9 c8 	movabs rdx,0xe3080ec8f9563a69
     107:	0e 08 e3 
     10a:	48 33 16             	xor    rdx,QWORD PTR [rsi]
     10d:	48 8b 70 30          	mov    rsi,QWORD PTR [rax+0x30]
     111:	48 8d b8 f0 09 00 00 	lea    rdi,[rax+0x9f0]
     118:	4c 8d 80 b0 06 00 00 	lea    r8,[rax+0x6b0]
     11f:	48 3b b0 70 03 00 00 	cmp    rsi,QWORD PTR [rax+0x370]
     126:	49 0f 47 f8          	cmova  rdi,r8
     12a:	48 be fe 29 d9 d7 0c 	movabs rsi,0xb43c340cd7d929fe
     131:	34 3c b4 
     134:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     137:	48 01 d6             	add    rsi,rdx
     13a:	48 8b 50 38          	mov    rdx,QWORD PTR [rax+0x38]
     13e:	48 8d b8 f8 09 00 00 	lea    rdi,[rax+0x9f8]
     145:	4c 8d 80 b8 06 00 00 	lea    r8,[rax+0x6b8]
     14c:	48 3b 90 78 03 00 00 	cmp    rdx,QWORD PTR [rax+0x378]
     153:	49 0f 47 f8          	cmova  rdi,r8
     157:	48 ba 93 19 5c b6 50 	movabs rdx,0x85705950b65c1993
     15e:	59 70 85 
     161:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     164:	48 01 f2             	add    rdx,rsi
     167:	48 01 ca             	add    rdx,rcx
     16a:	48 8b 48 40          	mov    rcx,QWORD PTR [rax+0x40]
     16e:	48 8d b0 00 0a 00 00 	lea    rsi,[rax+0xa00]
     175:	48 3b 88 80 03 00 00 	cmp    rcx,QWORD PTR [rax+0x380]
     17c:	48 8d 88 c0 06 00 00 	lea    rcx,[rax+0x6c0]
     183:	48 0f 47 f1          	cmova  rsi,rcx
     187:	48 b9 28 09 df 94 94 	movabs rcx,0x56a47e9494df0928
     18e:	7e a4 56 
     191:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     194:	48 8b 70 48          	mov    rsi,QWORD PTR [rax+0x48]
     198:	48 8d b8 08 0a 00 00 	lea    rdi,[rax+0xa08]
     19f:	4c 8d 80 c8 06 00 00 	lea    r8,[rax+0x6c8]
     1a6:	48 3b b0 88 03 00 00 	cmp    rsi,QWORD PTR [rax+0x388]
     1ad:	49 0f 47 f8          	cmova  rdi,r8
     1b1:	48 be bd f8 61 73 d8 	movabs rsi,0x27d8a3d87361f8bd
     1b8:	a3 d8 27 
     1bb:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     1be:	48 01 ce             	add    rsi,rcx
     1c1:	48 8b 48 50          	mov    rcx,QWORD PTR [rax+0x50]
     1c5:	48 8d b8 10 0a 00 00 	lea    rdi,[rax+0xa10]
     1cc:	4c 8d 80 d0 06 00 00 	lea    r8,[rax+0x6d0]
     1d3:	48 3b 88 90 03 00 00 	cmp    rcx,QWORD PTR [rax+0x390]
     1da:	49 0f 47 f8          	cmova  rdi,r8
     1de:	49 b8 52 e8 e4 51 1c 	movabs r8,0xf90cc91c51e4e852
     1e5:	c9 0c f9 
     1e8:	4c 33 07             	xor    r8,QWORD PTR [rdi]
     1eb:	49 01 f0             	add    r8,rsi
     1ee:	48 8b 48 58          	mov    rcx,QWORD PTR [rax+0x58]
     1f2:	48 8d b0 18 0a 00 00 	lea    rsi,[rax+0xa18]
     1f9:	48 8d b8 d8 06 00 00 	lea    rdi,[rax+0x6d8]
     200:	48 3b 88 98 03 00 00 	cmp    rcx,QWORD PTR [rax+0x398]
     207:	48 0f 47 f7          	cmova  rsi,rdi
     20b:	48 b9 e7 d7 67 30 60 	movabs rcx,0xca40ee603067d7e7
     212:	ee 40 ca 
     215:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     218:	4c 01 c1             	add    rcx,r8
     21b:	48 01 d1             	add    rcx,rdx
     21e:	48 8b 50 60          	mov    rdx,QWORD PTR [rax+0x60]
     222:	48 8d b0 20 0a 00 00 	lea    rsi,[rax+0xa20]
     229:	48 8d b8 e0 06 00 00 	lea    rdi,[rax+0x6e0]
     230:	48 3b 90 a0 03 00 00 	cmp    rdx,QWORD PTR [rax+0x3a0]
     237:	48 0f 47 f7          	cmova  rsi,rdi
     23b:	48 ba 7c c7 ea 0e a4 	movabs rdx,0x9b7513a40eeac77c
     242:	13 75 9b 
     245:	48 33 16             	xor    rdx,QWORD PTR [rsi]
     248:	48 8b 70 68          	mov    rsi,QWORD PTR [rax+0x68]
     24c:	48 8d b8 28 0a 00 00 	lea    rdi,[rax+0xa28]
     253:	4c 8d 80 e8 06 00 00 	lea    r8,[rax+0x6e8]
     25a:	48 3b b0 a8 03 00 00 	cmp    rsi,QWORD PTR [rax+0x3a8]
     261:	49 0f 47 f8          	cmova  rdi,r8
     265:	48 be 11 b7 6d ed e7 	movabs rsi,0x6ca938e7ed6db711
     26c:	38 a9 6c 
     26f:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     272:	48 01 d6             	add    rsi,rdx
     275:	48 8b 50 70          	mov    rdx,QWORD PTR [rax+0x70]
     279:	48 8d b8 30 0a 00 00 	lea    rdi,[rax+0xa30]
     280:	4c 8d 80 f0 06 00 00 	lea    r8,[rax+0x6f0]
     287:	48 3b 90 b0 03 00 00 	cmp    rdx,QWORD PTR [rax+0x3b0]
     28e:	49 0f 47 f8          	cmova  rdi,r8
     292:	48 ba a6 a6 f0 cb 2b 	movabs rdx,0x3ddd5e2bcbf0a6a6
     299:	5e dd 3d 
     29c:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     29f:	48 01 f2             	add    rdx,rsi
     2a2:	48 8b 70 78          	mov    rsi,QWORD PTR [rax+0x78]
     2a6:	48 8d b8 38 0a 00 00 	lea    rdi,[rax+0xa38]
     2ad:	4c 8d 80 f8 06 00 00 	lea    r8,[rax+0x6f8]
     2b4:	48 3b b0 b8 03 00 00 	cmp    rsi,QWORD PTR [rax+0x3b8]
     2bb:	49 0f 47 f8          	cmova  rdi,r8
     2bf:	48 be 3b 96 73 aa 6f 	movabs rsi,0xf11836faa73963b
     2c6:	83 11 0f 
     2c9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     2cc:	48 01 d6             	add    rsi,rdx
     2cf:	48 8b 90 80 00 00 00 	mov    rdx,QWORD PTR [rax+0x80]
     2d6:	48 8d b8 40 0a 00 00 	lea    rdi,[rax+0xa40]
     2dd:	4c 8d 80 00 07 00 00 	lea    r8,[rax+0x700]
     2e4:	48 3b 90 c0 03 00 00 	cmp    rdx,QWORD PTR [rax+0x3c0]
     2eb:	49 0f 47 f8          	cmova  rdi,r8
     2ef:	48 ba d0 85 f6 88 b3 	movabs rdx,0xe045a8b388f685d0
     2f6:	a8 45 e0 
     2f9:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     2fc:	48 01 f2             	add    rdx,rsi
     2ff:	48 01 ca             	add    rdx,rcx
     302:	48 8b 88 88 00 00 00 	mov    rcx,QWORD PTR [rax+0x88]
     309:	48 8d b0 48 0a 00 00 	lea    rsi,[rax+0xa48]
     310:	48 3b 88 c8 03 00 00 	cmp    rcx,QWORD PTR [rax+0x3c8]
     317:	48 8d 88 08 07 00 00 	lea    rcx,[rax+0x708]
     31e:	48 0f 47 f1          	cmova  rsi,rcx
     322:	48 b9 65 75 79 67 f7 	movabs rcx,0xb179cdf767797565
     329:	cd 79 b1 
     32c:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     32f:	48 8b b0 90 00 00 00 	mov    rsi,QWORD PTR [rax+0x90]
     336:	48 8d b8 50 0a 00 00 	lea    rdi,[rax+0xa50]
     33d:	4c 8d 80 10 07 00 00 	lea    r8,[rax+0x710]
     344:	48 3b b0 d0 03 00 00 	cmp    rsi,QWORD PTR [rax+0x3d0]
     34b:	49 0f 47 f8          	cmova  rdi,r8
     34f:	48 be fa 64 fc 45 3b 	movabs rsi,0x82adf33b45fc64fa
     356:	f3 ad 82 
     359:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     35c:	48 01 ce             	add    rsi,rcx
     35f:	48 8b 88 98 00 00 00 	mov    rcx,QWORD PTR [rax+0x98]
     366:	48 8d b8 58 0a 00 00 	lea    rdi,[rax+0xa58]
     36d:	4c 8d 80 18 07 00 00 	lea    r8,[rax+0x718]
     374:	48 3b 88 d8 03 00 00 	cmp    rcx,QWORD PTR [rax+0x3d8]
     37b:	49 0f 47 f8          	cmova  rdi,r8
     37f:	48 b9 8f 54 7f 24 7f 	movabs rcx,0x53e2187f247f548f
     386:	18 e2 53 
     389:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     38c:	48 01 f1             	add    rcx,rsi
     38f:	48 8b b0 a0 00 00 00 	mov    rsi,QWORD PTR [rax+0xa0]
     396:	48 8d b8 60 0a 00 00 	lea    rdi,[rax+0xa60]
     39d:	4c 8d 80 20 07 00 00 	lea    r8,[rax+0x720]
     3a4:	48 3b b0 e0 03 00 00 	cmp    rsi,QWORD PTR [rax+0x3e0]
     3ab:	49 0f 47 f8          	cmova  rdi,r8
     3af:	48 be 24 44 02 03 c3 	movabs rsi,0x25163dc303024424
     3b6:	3d 16 25 
     3b9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     3bc:	48 01 ce             	add    rsi,rcx
     3bf:	48 8b 88 a8 00 00 00 	mov    rcx,QWORD PTR [rax+0xa8]
     3c6:	48 8d b8 68 0a 00 00 	lea    rdi,[rax+0xa68]
     3cd:	4c 8d 80 28 07 00 00 	lea    r8,[rax+0x728]
     3d4:	48 3b 88 e8 03 00 00 	cmp    rcx,QWORD PTR [rax+0x3e8]
     3db:	49 0f 47 f8          	cmova  rdi,r8
     3df:	49 b8 b9 33 85 e1 06 	movabs r8,0xf64a6306e18533b9
     3e6:	63 4a f6 
     3e9:	4c 33 07             	xor    r8,QWORD PTR [rdi]
     3ec:	49 01 f0             	add    r8,rsi
     3ef:	48 8b 88 b0 00 00 00 	mov    rcx,QWORD PTR [rax+0xb0]
     3f6:	48 8d b0 70 0a 00 00 	lea    rsi,[rax+0xa70]
     3fd:	48 8d b8 30 07 00 00 	lea    rdi,[rax+0x730]
     404:	48 3b 88 f0 03 00 00 	cmp    rcx,QWORD PTR [rax+0x3f0]
     40b:	48 0f 47 f7          	cmova  rsi,rdi
     40f:	48 b9 4e 23 08 c0 4a 	movabs rcx,0xc77e884ac008234e
     416:	88 7e c7 
     419:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     41c:	4c 01 c1             	add    rcx,r8
     41f:	48 01 d1             	add    rcx,rdx
     422:	48 8b 90 b8 00 00 00 	mov    rdx,QWORD PTR [rax+0xb8]
     429:	48 8d b0 78 0a 00 00 	lea    rsi,[rax+0xa78]
     430:	48 3b 90 f8 03 00 00 	cmp    rdx,QWORD PTR [rax+0x3f8]
     437:	48 8d 90 38 07 00 00 	lea    rdx,[rax+0x738]
     43e:	48 0f 47 f2          	cmova  rsi,rdx
     442:	48 ba e3 12 8b 9e 8e 	movabs rdx,0x98b2ad8e9e8b12e3
     449:	ad b2 98 
     44c:	48 33 16             	xor    rdx,QWORD PTR [rsi]
     44f:	48 8b b0 c0 00 00 00 	mov    rsi,QWORD PTR [rax+0xc0]
     456:	48 8d b8 80 0a 00 00 	lea    rdi,[rax+0xa80]
     45d:	4c 8d 80 40 07 00 00 	lea    r8,[rax+0x740]
     464:	48 3b b0 00 04 00 00 	cmp    rsi,QWORD PTR [rax+0x400]
     46b:	49 0f 47 f8          	cmova  rdi,r8
     46f:	48 be 78 02 0e 7d d2 	movabs rsi,0x69e6d2d27d0e0278
     476:	d2 e6 69 
     479:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     47c:	48 01 d6             	add    rsi,rdx
     47f:	48 8b 90 c8 00 00 00 	mov    rdx,QWORD PTR [rax+0xc8]
     486:	48 8d b8 88 0a 00 00 	lea    rdi,[rax+0xa88]
     48d:	4c 8d 80 48 07 00 00 	lea    r8,[rax+0x748]
     494:	48 3b 90 08 04 00 00 	cmp    rdx,QWORD PTR [rax+0x408]
     49b:	49 0f 47 f8          	cmova  rdi,r8
     49f:	48 ba 0d f2 90 5b 16 	movabs rdx,0x3b1af8165b90f20d
     4a6:	f8 1a 3b 
     4a9:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     4ac:	48 01 f2             	add    rdx,rsi
     4af:	48 8b b0 d0 00 00 00 	mov    rsi,QWORD PTR [rax+0xd0]
     4b6:	48 8d b8 90 0a 00 00 	lea    rdi,[rax+0xa90]
     4bd:	4c 8d 80 50 07 00 00 	lea    r8,[rax+0x750]
     4c4:	48 3b b0 10 04 00 00 	cmp    rsi,QWORD PTR [rax+0x410]
     4cb:	49 0f 47 f8          	cmova  rdi,r8
     4cf:	48 be a2 e1 13 3a 5a 	movabs rsi,0xc4f1d5a3a13e1a2
     4d6:	1d 4f 0c 
     4d9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     4dc:	48 01 d6             	add    rsi,rdx
     4df:	48 8b 90 d8 00 00 00 	mov    rdx,QWORD PTR [rax+0xd8]
     4e6:	48 8d b8 98 0a 00 00 	lea    rdi,[rax+0xa98]
     4ed:	4c 8d 80 58 07 00 00 	lea    r8,[rax+0x758]
     4f4:	48 3b 90 18 04 00 00 	cmp    rdx,QWORD PTR [rax+0x418]
     4fb:	49 0f 47 f8          	cmova  rdi,r8
     4ff:	48 ba 37 d1 96 18 9e 	movabs rdx,0xdd83429e1896d137
     506:	42 83 dd 
     509:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     50c:	48 01 f2             	add    rdx,rsi
     50f:	48 8b b0 e0 00 00 00 	mov    rsi,QWORD PTR [rax+0xe0]
     516:	48 8d b8 a0 0a 00 00 	lea    rdi,[rax+0xaa0]
     51d:	4c 8d 80 60 07 00 00 	lea    r8,[rax+0x760]
     524:	48 3b b0 20 04 00 00 	cmp    rsi,QWORD PTR [rax+0x420]
     52b:	49 0f 47 f8          	cmova  rdi,r8
     52f:	48 be cc c0 19 f7 e1 	movabs rsi,0xaeb767e1f719c0cc
     536:	67 b7 ae 
     539:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     53c:	48 01 d6             	add    rsi,rdx
     53f:	48 8b 90 e8 00 00 00 	mov    rdx,QWORD PTR [rax+0xe8]
     546:	48 8d b8 a8 0a 00 00 	lea    rdi,[rax+0xaa8]
     54d:	4c 8d 80 68 07 00 00 	lea    r8,[rax+0x768]
     554:	48 3b 90 28 04 00 00 	cmp    rdx,QWORD PTR [rax+0x428]
     55b:	49 0f 47 f8          	cmova  rdi,r8
     55f:	48 ba 61 b0 9c d5 25 	movabs rdx,0x7feb8d25d59cb061
     566:	8d eb 7f 
     569:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     56c:	48 01 f2             	add    rdx,rsi
     56f:	48 01 ca             	add    rdx,rcx
     572:	48 8b 88 f0 00 00 00 	mov    rcx,QWORD PTR [rax+0xf0]
     579:	48 8d b0 b0 0a 00 00 	lea    rsi,[rax+0xab0]
     580:	48 8d b8 70 07 00 00 	lea    rdi,[rax+0x770]
     587:	48 3b 88 30 04 00 00 	cmp    rcx,QWORD PTR [rax+0x430]
     58e:	48 0f 47 f7          	cmova  rsi,rdi
     592:	48 b9 f6 9f 1f b4 69 	movabs rcx,0x511fb269b41f9ff6
     599:	b2 1f 51 
     59c:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     59f:	48 8b b0 f8 00 00 00 	mov    rsi,QWORD PTR [rax+0xf8]
     5a6:	48 8d b8 b8 0a 00 00 	lea    rdi,[rax+0xab8]
     5ad:	4c 8d 80 78 07 00 00 	lea    r8,[rax+0x778]
     5b4:	48 3b b0 38 04 00 00 	cmp    rsi,QWORD PTR [rax+0x438]
     5bb:	49 0f 47 f8          	cmova  rdi,r8
     5bf:	48 be 8b 8f a2 92 ad 	movabs rsi,0x2253d7ad92a28f8b
     5c6:	d7 53 22 
     5c9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     5cc:	48 01 ce             	add    rsi,rcx
     5cf:	48 8b 88 00 01 00 00 	mov    rcx,QWORD PTR [rax+0x100]
     5d6:	48 8d b8 c0 0a 00 00 	lea    rdi,[rax+0xac0]
     5dd:	4c 8d 80 80 07 00 00 	lea    r8,[rax+0x780]
     5e4:	48 3b 88 40 04 00 00 	cmp    rcx,QWORD PTR [rax+0x440]
     5eb:	49 0f 47 f8          	cmova  rdi,r8
     5ef:	48 b9 20 7f 25 71 f1 	movabs rcx,0xf387fcf171257f20
     5f6:	fc 87 f3 
     5f9:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     5fc:	48 01 f1             	add    rcx,rsi
     5ff:	48 8b b0 08 01 00 00 	mov    rsi,QWORD PTR [rax+0x108]
     606:	48 8d b8 c8 0a 00 00 	lea    rdi,[rax+0xac8]
     60d:	4c 8d 80 88 07 00 00 	lea    r8,[rax+0x788]
     614:	48 3b b0 48 04 00 00 	cmp    rsi,QWORD PTR [rax+0x448]
     61b:	49 0f 47 f8          	cmova  rdi,r8
     61f:	48 be b5 6e a8 4f 35 	movabs rsi,0xc4bc22354fa86eb5
     626:	22 bc c4 
     629:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     62c:	48 01 ce             	add    rsi,rcx
     62f:	48 8b 88 10 01 00 00 	mov    rcx,QWORD PTR [rax+0x110]
     636:	48 8d b8 d0 0a 00 00 	lea    rdi,[rax+0xad0]
     63d:	4c 8d 80 90 07 00 00 	lea    r8,[rax+0x790]
     644:	48 3b 88 50 04 00 00 	cmp    rcx,QWORD PTR [rax+0x450]
     64b:	49 0f 47 f8          	cmova  rdi,r8
     64f:	48 b9 4a 5e 2b 2e 79 	movabs rcx,0x95f047792e2b5e4a
     656:	47 f0 95 
     659:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     65c:	48 01 f1             	add    rcx,rsi
     65f:	48 8b b0 18 01 00 00 	mov    rsi,QWORD PTR [rax+0x118]
     666:	48 8d b8 d8 0a 00 00 	lea    rdi,[rax+0xad8]
     66d:	4c 8d 80 98 07 00 00 	lea    r8,[rax+0x798]
     674:	48 3b b0 58 04 00 00 	cmp    rsi,QWORD PTR [rax+0x458]
     67b:	49 0f 47 f8          	cmova  rdi,r8
     67f:	48 be df 4d ae 0c bd 	movabs rsi,0x67246cbd0cae4ddf
     686:	6c 24 67 
     689:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     68c:	48 01 ce             	add    rsi,rcx
     68f:	48 8b 88 20 01 00 00 	mov    rcx,QWORD PTR [rax+0x120]
     696:	48 8d b8 e0 0a 00 00 	lea    rdi,[rax+0xae0]
     69d:	4c 8d 80 a0 07 00 00 	lea    r8,[rax+0x7a0]
     6a4:	48 3b 88 60 04 00 00 	cmp    rcx,QWORD PTR [rax+0x460]
     6ab:	49 0f 47 f8          	cmova  rdi,r8
     6af:	49 b8 74 3d 31 eb 00 	movabs r8,0x38589200eb313d74
     6b6:	92 58 38 
     6b9:	4c 33 07             	xor    r8,QWORD PTR [rdi]
     6bc:	49 01 f0             	add    r8,rsi
     6bf:	48 8b 88 28 01 00 00 	mov    rcx,QWORD PTR [rax+0x128]
     6c6:	48 8d b0 e8 0a 00 00 	lea    rsi,[rax+0xae8]
     6cd:	48 8d b8 a8 07 00 00 	lea    rdi,[rax+0x7a8]
     6d4:	48 3b 88 68 04 00 00 	cmp    rcx,QWORD PTR [rax+0x468]
     6db:	48 0f 47 f7          	cmova  rsi,rdi
     6df:	48 b9 09 2d b4 c9 44 	movabs rcx,0x98cb744c9b42d09
     6e6:	b7 8c 09 
     6e9:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     6ec:	4c 01 c1             	add    rcx,r8
     6ef:	48 01 d1             	add    rcx,rdx
     6f2:	48 8b 90 30 01 00 00 	mov    rdx,QWORD PTR [rax+0x130]
     6f9:	48 8d b0 f0 0a 00 00 	lea    rsi,[rax+0xaf0]
     700:	48 3b 90 70 04 00 00 	cmp    rdx,QWORD PTR [rax+0x470]
     707:	48 8d 90 b0 07 00 00 	lea    rdx,[rax+0x7b0]
     70e:	48 0f 47 f2          	cmova  rsi,rdx
     712:	48 ba 9e 1c 37 a8 88 	movabs rdx,0xdac0dc88a8371c9e
     719:	dc c0 da 
     71c:	48 33 16             	xor    rdx,QWORD PTR [rsi]
     71f:	48 8b b0 38 01 00 00 	mov    rsi,QWORD PTR [rax+0x138]
     726:	48 8d b8 f8 0a 00 00 	lea    rdi,[rax+0xaf8]
     72d:	4c 8d 80 b8 07 00 00 	lea    r8,[rax+0x7b8]
     734:	48 3b b0 78 04 00 00 	cmp    rsi,QWORD PTR [rax+0x478]
     73b:	49 0f 47 f8          	cmova  rdi,r8
     73f:	48 be 33 0c ba 86 cc 	movabs rsi,0xabf501cc86ba0c33
     746:	01 f5 ab 
     749:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     74c:	48 01 d6             	add    rsi,rdx
     74f:	48 8b 90 40 01 00 00 	mov    rdx,QWORD PTR [rax+0x140]
     756:	48 8d b8 00 0b 00 00 	lea    rdi,[rax+0xb00]
     75d:	4c 8d 80 c0 07 00 00 	lea    r8,[rax+0x7c0]
     764:	48 3b 90 80 04 00 00 	cmp    rdx,QWORD PTR [rax+0x480]
     76b:	49 0f 47 f8          	cmova  rdi,r8
     76f:	48 ba c8 fb 3c 65 10 	movabs rdx,0x7d292710653cfbc8
     776:	27 29 7d 
     779:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     77c:	48 01 f2             	add    rdx,rsi
     77f:	48 8b b0 48 01 00 00 	mov    rsi,QWORD PTR [rax+0x148]
     786:	48 8d b8 08 0b 00 00 	lea    rdi,[rax+0xb08]
     78d:	4c 8d 80 c8 07 00 00 	lea    r8,[rax+0x7c8]
     794:	48 3b b0 88 04 00 00 	cmp    rsi,QWORD PTR [rax+0x488]
     79b:	49 0f 47 f8          	cmova  rdi,r8
     79f:	48 be 5d eb bf 43 54 	movabs rsi,0x4e5d4c5443bfeb5d
     7a6:	4c 5d 4e 
     7a9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     7ac:	48 01 d6             	add    rsi,rdx
     7af:	48 8b 90 50 01 00 00 	mov    rdx,QWORD PTR [rax+0x150]
     7b6:	48 8d b8 10 0b 00 00 	lea    rdi,[rax+0xb10]
     7bd:	4c 8d 80 d0 07 00 00 	lea    r8,[rax+0x7d0]
     7c4:	48 3b 90 90 04 00 00 	cmp    rdx,QWORD PTR [rax+0x490]
     7cb:	49 0f 47 f8          	cmova  rdi,r8
     7cf:	48 ba f2 da 42 22 98 	movabs rdx,0x1f9171982242daf2
     7d6:	71 91 1f 
     7d9:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     7dc:	48 01 f2             	add    rdx,rsi
     7df:	48 8b b0 58 01 00 00 	mov    rsi,QWORD PTR [rax+0x158]
     7e6:	48 8d b8 18 0b 00 00 	lea    rdi,[rax+0xb18]
     7ed:	4c 8d 80 d8 07 00 00 	lea    r8,[rax+0x7d8]
     7f4:	48 3b b0 98 04 00 00 	cmp    rsi,QWORD PTR [rax+0x498]
     7fb:	49 0f 47 f8          	cmova  rdi,r8
     7ff:	48 be 87 ca c5 00 dc 	movabs rsi,0xf0c596dc00c5ca87
     806:	96 c5 f0 
     809:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     80c:	48 01 d6             	add    rsi,rdx
     80f:	48 8b 90 60 01 00 00 	mov    rdx,QWORD PTR [rax+0x160]
     816:	48 8d b8 20 0b 00 00 	lea    rdi,[rax+0xb20]
     81d:	4c 8d 80 e0 07 00 00 	lea    r8,[rax+0x7e0]
     824:	48 3b 90 a0 04 00 00 	cmp    rdx,QWORD PTR [rax+0x4a0]
     82b:	49 0f 47 f8          	cmova  rdi,r8
     82f:	48 ba 1c ba 48 df 1f 	movabs rdx,0xc1f9bc1fdf48ba1c
     836:	bc f9 c1 
     839:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     83c:	48 01 f2             	add    rdx,rsi
     83f:	48 8b b0 68 01 00 00 	mov    rsi,QWORD PTR [rax+0x168]
     846:	48 8d b8 28 0b 00 00 	lea    rdi,[rax+0xb28]
     84d:	4c 8d 80 e8 07 00 00 	lea    r8,[rax+0x7e8]
     854:	48 3b b0 a8 04 00 00 	cmp    rsi,QWORD PTR [rax+0x4a8]
     85b:	49 0f 47 f8          	cmova  rdi,r8
     85f:	48 be b1 a9 cb bd 63 	movabs rsi,0x932de163bdcba9b1
     866:	e1 2d 93 
     869:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     86c:	48 01 d6             	add    rsi,rdx
     86f:	48 8b 90 70 01 00 00 	mov    rdx,QWORD PTR [rax+0x170]
     876:	48 8d b8 30 0b 00 00 	lea    rdi,[rax+0xb30]
     87d:	4c 8d 80 f0 07 00 00 	lea    r8,[rax+0x7f0]
     884:	48 3b 90 b0 04 00 00 	cmp    rdx,QWORD PTR [rax+0x4b0]
     88b:	49 0f 47 f8          	cmova  rdi,r8
     88f:	48 ba 46 99 4e 9c a7 	movabs rdx,0x646206a79c4e9946
     896:	06 62 64 
     899:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     89c:	48 01 f2             	add    rdx,rsi
     89f:	48 01 ca             	add    rdx,rcx
     8a2:	48 8b 88 78 01 00 00 	mov    rcx,QWORD PTR [rax+0x178]
     8a9:	48 8d b0 38 0b 00 00 	lea    rsi,[rax+0xb38]
     8b0:	48 3b 88 b8 04 00 00 	cmp    rcx,QWORD PTR [rax+0x4b8]
     8b7:	48 8d 88 f8 07 00 00 	lea    rcx,[rax+0x7f8]
     8be:	48 0f 47 f1          	cmova  rsi,rcx
     8c2:	48 b9 db 88 d1 7a eb 	movabs rcx,0x35962beb7ad188db
     8c9:	2b 96 35 
     8cc:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     8cf:	48 8b b0 80 01 00 00 	mov    rsi,QWORD PTR [rax+0x180]
     8d6:	48 8d b8 40 0b 00 00 	lea    rdi,[rax+0xb40]
     8dd:	4c 8d 80 00 08 00 00 	lea    r8,[rax+0x800]
     8e4:	48 3b b0 c0 04 00 00 	cmp    rsi,QWORD PTR [rax+0x4c0]
     8eb:	49 0f 47 f8          	cmova  rdi,r8
     8ef:	48 be 70 78 54 59 2f 	movabs rsi,0x6ca512f59547870
     8f6:	51 ca 06 
     8f9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     8fc:	48 01 ce             	add    rsi,rcx
     8ff:	48 8b 88 88 01 00 00 	mov    rcx,QWORD PTR [rax+0x188]
     906:	48 8d b8 48 0b 00 00 	lea    rdi,[rax+0xb48]
     90d:	4c 8d 80 08 08 00 00 	lea    r8,[rax+0x808]
     914:	48 3b 88 c8 04 00 00 	cmp    rcx,QWORD PTR [rax+0x4c8]
     91b:	49 0f 47 f8          	cmova  rdi,r8
     91f:	48 b9 05 68 d7 37 73 	movabs rcx,0xd7fe767337d76805
     926:	76 fe d7 
     929:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     92c:	48 01 f1             	add    rcx,rsi
     92f:	48 8b b0 90 01 00 00 	mov    rsi,QWORD PTR [rax+0x190]
     936:	48 8d b8 50 0b 00 00 	lea    rdi,[rax+0xb50]
     93d:	4c 8d 80 10 08 00 00 	lea    r8,[rax+0x810]
     944:	48 3b b0 d0 04 00 00 	cmp    rsi,QWORD PTR [rax+0x4d0]
     94b:	49 0f 47 f8          	cmova  rdi,r8
     94f:	48 be 9a 57 5a 16 b7 	movabs rsi,0xa9329bb7165a579a
     956:	9b 32 a9 
     959:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     95c:	48 01 ce             	add    rsi,rcx
     95f:	48 8b 88 98 01 00 00 	mov    rcx,QWORD PTR [rax+0x198]
     966:	48 8d b8 58 0b 00 00 	lea    rdi,[rax+0xb58]
     96d:	4c 8d 80 18 08 00 00 	lea    r8,[rax+0x818]
     974:	48 3b 88 d8 04 00 00 	cmp    rcx,QWORD PTR [rax+0x4d8]
     97b:	49 0f 47 f8          	cmova  rdi,r8
     97f:	48 b9 2f 47 dd f4 fa 	movabs rcx,0x7a66c0faf4dd472f
     986:	c0 66 7a 
     989:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     98c:	48 01 f1             	add    rcx,rsi
     98f:	48 8b b0 a0 01 00 00 	mov    rsi,QWORD PTR [rax+0x1a0]
     996:	48 8d b8 60 0b 00 00 	lea    rdi,[rax+0xb60]
     99d:	4c 8d 80 20 08 00 00 	lea    r8,[rax+0x820]
     9a4:	48 3b b0 e0 04 00 00 	cmp    rsi,QWORD PTR [rax+0x4e0]
     9ab:	49 0f 47 f8          	cmova  rdi,r8
     9af:	48 be c4 36 60 d3 3e 	movabs rsi,0x4b9ae63ed36036c4
     9b6:	e6 9a 4b 
     9b9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     9bc:	48 01 ce             	add    rsi,rcx
     9bf:	48 8b 88 a8 01 00 00 	mov    rcx,QWORD PTR [rax+0x1a8]
     9c6:	48 8d b8 68 0b 00 00 	lea    rdi,[rax+0xb68]
     9cd:	4c 8d 80 28 08 00 00 	lea    r8,[rax+0x828]
     9d4:	48 3b 88 e8 04 00 00 	cmp    rcx,QWORD PTR [rax+0x4e8]
     9db:	49 0f 47 f8          	cmova  rdi,r8
     9df:	48 b9 59 26 e3 b1 82 	movabs rcx,0x1ccf0b82b1e32659
     9e6:	0b cf 1c 
     9e9:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     9ec:	48 01 f1             	add    rcx,rsi
     9ef:	48 8b b0 b0 01 00 00 	mov    rsi,QWORD PTR [rax+0x1b0]
     9f6:	48 8d b8 70 0b 00 00 	lea    rdi,[rax+0xb70]
     9fd:	4c 8d 80 30 08 00 00 	lea    r8,[rax+0x830]
     a04:	48 3b b0 f0 04 00 00 	cmp    rsi,QWORD PTR [rax+0x4f0]
     a0b:	49 0f 47 f8          	cmova  rdi,r8
     a0f:	48 be ee 15 66 90 c6 	movabs rsi,0xee0330c6906615ee
     a16:	30 03 ee 
     a19:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     a1c:	48 01 ce             	add    rsi,rcx
     a1f:	48 8b 88 b8 01 00 00 	mov    rcx,QWORD PTR [rax+0x1b8]
     a26:	48 8d b8 78 0b 00 00 	lea    rdi,[rax+0xb78]
     a2d:	4c 8d 80 38 08 00 00 	lea    r8,[rax+0x838]
     a34:	48 3b 88 f8 04 00 00 	cmp    rcx,QWORD PTR [rax+0x4f8]
     a3b:	49 0f 47 f8          	cmova  rdi,r8
     a3f:	49 b8 83 05 e9 6e 0a 	movabs r8,0xbf37560a6ee90583
     a46:	56 37 bf 
     a49:	4c 33 07             	xor    r8,QWORD PTR [rdi]
     a4c:	49 01 f0             	add    r8,rsi
     a4f:	48 8b 88 c0 01 00 00 	mov    rcx,QWORD PTR [rax+0x1c0]
     a56:	48 8d b0 80 0b 00 00 	lea    rsi,[rax+0xb80]
     a5d:	48 8d b8 40 08 00 00 	lea    rdi,[rax+0x840]
     a64:	48 3b 88 00 05 00 00 	cmp    rcx,QWORD PTR [rax+0x500]
     a6b:	48 0f 47 f7          	cmova  rsi,rdi
     a6f:	48 b9 18 f5 6b 4d 4e 	movabs rcx,0x906b7b4e4d6bf518
     a76:	7b 6b 90 
     a79:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     a7c:	4c 01 c1             	add    rcx,r8
     a7f:	48 01 d1             	add    rcx,rdx
     a82:	48 8b 90 c8 01 00 00 	mov    rdx,QWORD PTR [rax+0x1c8]
     a89:	48 8d b0 88 0b 00 00 	lea    rsi,[rax+0xb88]
     a90:	48 8d b8 48 08 00 00 	lea    rdi,[rax+0x848]
     a97:	48 3b 90 08 05 00 00 	cmp    rdx,QWORD PTR [rax+0x508]
     a9e:	48 0f 47 f7          	cmova  rsi,rdi
     aa2:	48 ba ad e4 ee 2b 92 	movabs rdx,0x619fa0922beee4ad
     aa9:	a0 9f 61 
     aac:	48 33 16             	xor    rdx,QWORD PTR [rsi]
     aaf:	48 8b b0 d0 01 00 00 	mov    rsi,QWORD PTR [rax+0x1d0]
     ab6:	48 8d b8 90 0b 00 00 	lea    rdi,[rax+0xb90]
     abd:	4c 8d 80 50 08 00 00 	lea    r8,[rax+0x850]
     ac4:	48 3b b0 10 05 00 00 	cmp    rsi,QWORD PTR [rax+0x510]
     acb:	49 0f 47 f8          	cmova  rdi,r8
     acf:	48 be 42 d4 71 0a d6 	movabs rsi,0x32d3c5d60a71d442
     ad6:	c5 d3 32 
     ad9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     adc:	48 01 d6             	add    rsi,rdx
     adf:	48 8b 90 d8 01 00 00 	mov    rdx,QWORD PTR [rax+0x1d8]
     ae6:	48 8d b8 98 0b 00 00 	lea    rdi,[rax+0xb98]
     aed:	4c 8d 80 58 08 00 00 	lea    r8,[rax+0x858]
     af4:	48 3b 90 18 05 00 00 	cmp    rdx,QWORD PTR [rax+0x518]
     afb:	49 0f 47 f8          	cmova  rdi,r8
     aff:	48 ba d7 c3 f4 e8 19 	movabs rdx,0x407eb19e8f4c3d7
     b06:	eb 07 04 
     b09:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     b0c:	48 01 f2             	add    rdx,rsi
     b0f:	48 8b b0 e0 01 00 00 	mov    rsi,QWORD PTR [rax+0x1e0]
     b16:	48 8d b8 a0 0b 00 00 	lea    rdi,[rax+0xba0]
     b1d:	4c 8d 80 60 08 00 00 	lea    r8,[rax+0x860]
     b24:	48 3b b0 20 05 00 00 	cmp    rsi,QWORD PTR [rax+0x520]
     b2b:	49 0f 47 f8          	cmova  rdi,r8
     b2f:	48 be 6c b3 77 c7 5d 	movabs rsi,0xd53c105dc777b36c
     b36:	10 3c d5 
     b39:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     b3c:	48 01 d6             	add    rsi,rdx
     b3f:	48 8b 90 e8 01 00 00 	mov    rdx,QWORD PTR [rax+0x1e8]
     b46:	48 8d b8 a8 0b 00 00 	lea    rdi,[rax+0xba8]
     b4d:	4c 8d 80 68 08 00 00 	lea    r8,[rax+0x868]
     b54:	48 3b 90 28 05 00 00 	cmp    rdx,QWORD PTR [rax+0x528]
     b5b:	49 0f 47 f8          	cmova  rdi,r8
     b5f:	48 ba 01 a3 fa a5 a1 	movabs rdx,0xa67035a1a5faa301
     b66:	35 70 a6 
     b69:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     b6c:	48 01 f2             	add    rdx,rsi
     b6f:	48 8b b0 f0 01 00 00 	mov    rsi,QWORD PTR [rax+0x1f0]
     b76:	48 8d b8 b0 0b 00 00 	lea    rdi,[rax+0xbb0]
     b7d:	4c 8d 80 70 08 00 00 	lea    r8,[rax+0x870]
     b84:	48 3b b0 30 05 00 00 	cmp    rsi,QWORD PTR [rax+0x530]
     b8b:	49 0f 47 f8          	cmova  rdi,r8
     b8f:	48 be 96 92 7d 84 e5 	movabs rsi,0x77a45ae5847d9296
     b96:	5a a4 77 
     b99:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     b9c:	48 01 d6             	add    rsi,rdx
     b9f:	48 8b 90 f8 01 00 00 	mov    rdx,QWORD PTR [rax+0x1f8]
     ba6:	48 8d b8 b8 0b 00 00 	lea    rdi,[rax+0xbb8]
     bad:	4c 8d 80 78 08 00 00 	lea    r8,[rax+0x878]
     bb4:	48 3b 90 38 05 00 00 	cmp    rdx,QWORD PTR [rax+0x538]
     bbb:	49 0f 47 f8          	cmova  rdi,r8
     bbf:	48 ba 2b 82 00 63 29 	movabs rdx,0x48d880296300822b
     bc6:	80 d8 48 
     bc9:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     bcc:	48 01 f2             	add    rdx,rsi
     bcf:	48 8b b0 00 02 00 00 	mov    rsi,QWORD PTR [rax+0x200]
     bd6:	48 8d b8 c0 0b 00 00 	lea    rdi,[rax+0xbc0]
     bdd:	4c 8d 80 80 08 00 00 	lea    r8,[rax+0x880]
     be4:	48 3b b0 40 05 00 00 	cmp    rsi,QWORD PTR [rax+0x540]
     beb:	49 0f 47 f8          	cmova  rdi,r8
     bef:	48 be c0 71 83 41 6d 	movabs rsi,0x1a0ca56d418371c0
     bf6:	a5 0c 1a 
     bf9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     bfc:	48 01 d6             	add    rsi,rdx
     bff:	48 8b 90 08 02 00 00 	mov    rdx,QWORD PTR [rax+0x208]
     c06:	48 8d b8 c8 0b 00 00 	lea    rdi,[rax+0xbc8]
     c0d:	4c 8d 80 88 08 00 00 	lea    r8,[rax+0x888]
     c14:	48 3b 90 48 05 00 00 	cmp    rdx,QWORD PTR [rax+0x548]
     c1b:	49 0f 47 f8          	cmova  rdi,r8
     c1f:	48 ba 55 61 06 20 b1 	movabs rdx,0xeb40cab120066155
     c26:	ca 40 eb 
     c29:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     c2c:	48 01 f2             	add    rdx,rsi
     c2f:	48 8b b0 10 02 00 00 	mov    rsi,QWORD PTR [rax+0x210]
     c36:	48 8d b8 d0 0b 00 00 	lea    rdi,[rax+0xbd0]
     c3d:	4c 8d 80 90 08 00 00 	lea    r8,[rax+0x890]
     c44:	48 3b b0 50 05 00 00 	cmp    rsi,QWORD PTR [rax+0x550]
     c4b:	49 0f 47 f8          	cmova  rdi,r8
     c4f:	48 be ea 50 89 fe f4 	movabs rsi,0xbc74eff4fe8950ea
     c56:	ef 74 bc 
     c59:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     c5c:	48 01 d6             	add    rsi,rdx
     c5f:	48 8b 90 18 02 00 00 	mov    rdx,QWORD PTR [rax+0x218]
     c66:	48 8d b8 d8 0b 00 00 	lea    rdi,[rax+0xbd8]
     c6d:	4c 8d 80 98 08 00 00 	lea    r8,[rax+0x898]
     c74:	48 3b 90 58 05 00 00 	cmp    rdx,QWORD PTR [rax+0x558]
     c7b:	49 0f 47 f8          	cmova  rdi,r8
     c7f:	48 ba 7f 40 0c dd 38 	movabs rdx,0x8da91538dd0c407f
     c86:	15 a9 8d 
     c89:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     c8c:	48 01 f2             	add    rdx,rsi
     c8f:	48 01 ca             	add    rdx,rcx
     c92:	48 8b 88 20 02 00 00 	mov    rcx,QWORD PTR [rax+0x220]
     c99:	48 8d b0 e0 0b 00 00 	lea    rsi,[rax+0xbe0]
     ca0:	48 3b 88 60 05 00 00 	cmp    rcx,QWORD PTR [rax+0x560]
     ca7:	48 8d 88 a0 08 00 00 	lea    rcx,[rax+0x8a0]
     cae:	48 0f 47 f1          	cmova  rsi,rcx
     cb2:	48 b9 14 30 8f bb 7c 	movabs rcx,0x5edd3a7cbb8f3014
     cb9:	3a dd 5e 
     cbc:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     cbf:	48 8b b0 28 02 00 00 	mov    rsi,QWORD PTR [rax+0x228]
     cc6:	48 8d b8 e8 0b 00 00 	lea    rdi,[rax+0xbe8]
     ccd:	4c 8d 80 a8 08 00 00 	lea    r8,[rax+0x8a8]
     cd4:	48 3b b0 68 05 00 00 	cmp    rsi,QWORD PTR [rax+0x568]
     cdb:	49 0f 47 f8          	cmova  rdi,r8
     cdf:	48 be a9 1f 12 9a c0 	movabs rsi,0x30115fc09a121fa9
     ce6:	5f 11 30 
     ce9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     cec:	48 01 ce             	add    rsi,rcx
     cef:	48 8b 88 30 02 00 00 	mov    rcx,QWORD PTR [rax+0x230]
     cf6:	48 8d b8 f0 0b 00 00 	lea    rdi,[rax+0xbf0]
     cfd:	4c 8d 80 b0 08 00 00 	lea    r8,[rax+0x8b0]
     d04:	48 3b 88 70 05 00 00 	cmp    rcx,QWORD PTR [rax+0x570]
     d0b:	49 0f 47 f8          	cmova  rdi,r8
     d0f:	48 b9 3e 0f 95 78 04 	movabs rcx,0x145850478950f3e
     d16:	85 45 01 
     d19:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     d1c:	48 01 f1             	add    rcx,rsi
     d1f:	48 8b b0 38 02 00 00 	mov    rsi,QWORD PTR [rax+0x238]
     d26:	48 8d b8 f8 0b 00 00 	lea    rdi,[rax+0xbf8]
     d2d:	4c 8d 80 b8 08 00 00 	lea    r8,[rax+0x8b8]
     d34:	48 3b b0 78 05 00 00 	cmp    rsi,QWORD PTR [rax+0x578]
     d3b:	49 0f 47 f8          	cmova  rdi,r8
     d3f:	48 be d3 fe 17 57 48 	movabs rsi,0xd279aa485717fed3
     d46:	aa 79 d2 
     d49:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     d4c:	48 01 ce             	add    rsi,rcx
     d4f:	48 8b 88 40 02 00 00 	mov    rcx,QWORD PTR [rax+0x240]
     d56:	48 8d b8 00 0c 00 00 	lea    rdi,[rax+0xc00]
     d5d:	4c 8d 80 c0 08 00 00 	lea    r8,[rax+0x8c0]
     d64:	48 3b 88 80 05 00 00 	cmp    rcx,QWORD PTR [rax+0x580]
     d6b:	49 0f 47 f8          	cmova  rdi,r8
     d6f:	48 b9 68 ee 9a 35 8c 	movabs rcx,0xa3adcf8c359aee68
     d76:	cf ad a3 
     d79:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     d7c:	48 01 f1             	add    rcx,rsi
     d7f:	48 8b b0 48 02 00 00 	mov    rsi,QWORD PTR [rax+0x248]
     d86:	48 8d b8 08 0c 00 00 	lea    rdi,[rax+0xc08]
     d8d:	4c 8d 80 c8 08 00 00 	lea    r8,[rax+0x8c8]
     d94:	48 3b b0 88 05 00 00 	cmp    rsi,QWORD PTR [rax+0x588]
     d9b:	49 0f 47 f8          	cmova  rdi,r8
     d9f:	48 be fd dd 1d 14 d0 	movabs rsi,0x74e1f4d0141dddfd
     da6:	f4 e1 74 
     da9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     dac:	48 01 ce             	add    rsi,rcx
     daf:	48 8b 88 50 02 00 00 	mov    rcx,QWORD PTR [rax+0x250]
     db6:	48 8d b8 10 0c 00 00 	lea    rdi,[rax+0xc10]
     dbd:	4c 8d 80 d0 08 00 00 	lea    r8,[rax+0x8d0]
     dc4:	48 3b 88 90 05 00 00 	cmp    rcx,QWORD PTR [rax+0x590]
     dcb:	49 0f 47 f8          	cmova  rdi,r8
     dcf:	48 b9 92 cd a0 f2 13 	movabs rcx,0x46161a13f2a0cd92
     dd6:	1a 16 46 
     dd9:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     ddc:	48 01 f1             	add    rcx,rsi
     ddf:	48 8b b0 58 02 00 00 	mov    rsi,QWORD PTR [rax+0x258]
     de6:	48 8d b8 18 0c 00 00 	lea    rdi,[rax+0xc18]
     ded:	4c 8d 80 d8 08 00 00 	lea    r8,[rax+0x8d8]
     df4:	48 3b b0 98 05 00 00 	cmp    rsi,QWORD PTR [rax+0x598]
     dfb:	49 0f 47 f8          	cmova  rdi,r8
     dff:	48 be 27 bd 23 d1 57 	movabs rsi,0x174a3f57d123bd27
     e06:	3f 4a 17 
     e09:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     e0c:	48 01 ce             	add    rsi,rcx
     e0f:	48 8b 88 60 02 00 00 	mov    rcx,QWORD PTR [rax+0x260]
     e16:	48 8d b8 20 0c 00 00 	lea    rdi,[rax+0xc20]
     e1d:	4c 8d 80 e0 08 00 00 	lea    r8,[rax+0x8e0]
     e24:	48 3b 88 a0 05 00 00 	cmp    rcx,QWORD PTR [rax+0x5a0]
     e2b:	49 0f 47 f8          	cmova  rdi,r8
     e2f:	48 b9 bc ac a6 af 9b 	movabs rcx,0xe87e649bafa6acbc
     e36:	64 7e e8 
     e39:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
     e3c:	48 01 f1             	add    rcx,rsi
     e3f:	48 8b b0 68 02 00 00 	mov    rsi,QWORD PTR [rax+0x268]
     e46:	48 8d b8 28 0c 00 00 	lea    rdi,[rax+0xc28]
     e4d:	4c 8d 80 e8 08 00 00 	lea    r8,[rax+0x8e8]
     e54:	48 3b b0 a8 05 00 00 	cmp    rsi,QWORD PTR [rax+0x5a8]
     e5b:	49 0f 47 f8          	cmova  rdi,r8
     e5f:	48 be 51 9c 29 8e df 	movabs rsi,0xb9b289df8e299c51
     e66:	89 b2 b9 
     e69:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     e6c:	48 01 ce             	add    rsi,rcx
     e6f:	48 8b 88 70 02 00 00 	mov    rcx,QWORD PTR [rax+0x270]
     e76:	48 8d b8 30 0c 00 00 	lea    rdi,[rax+0xc30]
     e7d:	4c 8d 80 f0 08 00 00 	lea    r8,[rax+0x8f0]
     e84:	48 3b 88 b0 05 00 00 	cmp    rcx,QWORD PTR [rax+0x5b0]
     e8b:	49 0f 47 f8          	cmova  rdi,r8
     e8f:	49 b8 e6 8b ac 6c 23 	movabs r8,0x8ae6af236cac8be6
     e96:	af e6 8a 
     e99:	4c 33 07             	xor    r8,QWORD PTR [rdi]
     e9c:	49 01 f0             	add    r8,rsi
     e9f:	48 8b 88 78 02 00 00 	mov    rcx,QWORD PTR [rax+0x278]
     ea6:	48 8d b0 38 0c 00 00 	lea    rsi,[rax+0xc38]
     ead:	48 8d b8 f8 08 00 00 	lea    rdi,[rax+0x8f8]
     eb4:	48 3b 88 b8 05 00 00 	cmp    rcx,QWORD PTR [rax+0x5b8]
     ebb:	48 0f 47 f7          	cmova  rsi,rdi
     ebf:	48 b9 7b 7b 2f 4b 67 	movabs rcx,0x5c1ad4674b2f7b7b
     ec6:	d4 1a 5c 
     ec9:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
     ecc:	4c 01 c1             	add    rcx,r8
     ecf:	48 01 d1             	add    rcx,rdx
     ed2:	48 8b 90 80 02 00 00 	mov    rdx,QWORD PTR [rax+0x280]
     ed9:	48 8d b0 40 0c 00 00 	lea    rsi,[rax+0xc40]
     ee0:	48 3b 90 c0 05 00 00 	cmp    rdx,QWORD PTR [rax+0x5c0]
     ee7:	48 8d 90 00 09 00 00 	lea    rdx,[rax+0x900]
     eee:	48 0f 47 f2          	cmova  rsi,rdx
     ef2:	48 ba 10 6b b2 29 ab 	movabs rdx,0x2d4ef9ab29b26b10
     ef9:	f9 4e 2d 
     efc:	48 33 16             	xor    rdx,QWORD PTR [rsi]
     eff:	48 8b b0 88 02 00 00 	mov    rsi,QWORD PTR [rax+0x288]
     f06:	48 8d b8 48 0c 00 00 	lea    rdi,[rax+0xc48]
     f0d:	4c 8d 80 08 09 00 00 	lea    r8,[rax+0x908]
     f14:	48 3b b0 c8 05 00 00 	cmp    rsi,QWORD PTR [rax+0x5c8]
     f1b:	49 0f 47 f8          	cmova  rdi,r8
     f1f:	48 be a5 5a 35 08 ef 	movabs rsi,0xfe831eef08355aa5
     f26:	1e 83 fe 
     f29:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     f2c:	48 01 d6             	add    rsi,rdx
     f2f:	48 8b 90 90 02 00 00 	mov    rdx,QWORD PTR [rax+0x290]
     f36:	48 8d b8 50 0c 00 00 	lea    rdi,[rax+0xc50]
     f3d:	4c 8d 80 10 09 00 00 	lea    r8,[rax+0x910]
     f44:	48 3b 90 d0 05 00 00 	cmp    rdx,QWORD PTR [rax+0x5d0]
     f4b:	49 0f 47 f8          	cmova  rdi,r8
     f4f:	48 ba 3a 4a b8 e6 32 	movabs rdx,0xcfb74432e6b84a3a
     f56:	44 b7 cf 
     f59:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     f5c:	48 01 f2             	add    rdx,rsi
     f5f:	48 8b b0 98 02 00 00 	mov    rsi,QWORD PTR [rax+0x298]
     f66:	48 8d b8 58 0c 00 00 	lea    rdi,[rax+0xc58]
     f6d:	4c 8d 80 18 09 00 00 	lea    r8,[rax+0x918]
     f74:	48 3b b0 d8 05 00 00 	cmp    rsi,QWORD PTR [rax+0x5d8]
     f7b:	49 0f 47 f8          	cmova  rdi,r8
     f7f:	48 be cf 39 3b c5 76 	movabs rsi,0xa0eb6976c53b39cf
     f86:	69 eb a0 
     f89:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     f8c:	48 01 d6             	add    rsi,rdx
     f8f:	48 8b 90 a0 02 00 00 	mov    rdx,QWORD PTR [rax+0x2a0]
     f96:	48 8d b8 60 0c 00 00 	lea    rdi,[rax+0xc60]
     f9d:	4c 8d 80 20 09 00 00 	lea    r8,[rax+0x920]
     fa4:	48 3b 90 e0 05 00 00 	cmp    rdx,QWORD PTR [rax+0x5e0]
     fab:	49 0f 47 f8          	cmova  rdi,r8
     faf:	48 ba 64 29 be a3 ba 	movabs rdx,0x721f8ebaa3be2964
     fb6:	8e 1f 72 
     fb9:	48 33 17             	xor    rdx,QWORD PTR [rdi]
     fbc:	48 01 f2             	add    rdx,rsi
     fbf:	48 8b b0 a8 02 00 00 	mov    rsi,QWORD PTR [rax+0x2a8]
     fc6:	48 8d b8 68 0c 00 00 	lea    rdi,[rax+0xc68]
     fcd:	4c 8d 80 28 09 00 00 	lea    r8,[rax+0x928]
     fd4:	48 3b b0 e8 05 00 00 	cmp    rsi,QWORD PTR [rax+0x5e8]
     fdb:	49 0f 47 f8          	cmova  rdi,r8
     fdf:	48 be f9 18 41 82 fe 	movabs rsi,0x4353b3fe824118f9
     fe6:	b3 53 43 
     fe9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
     fec:	48 01 d6             	add    rsi,rdx
     fef:	48 8b 90 b0 02 00 00 	mov    rdx,QWORD PTR [rax+0x2b0]
     ff6:	48 8d b8 70 0c 00 00 	lea    rdi,[rax+0xc70]
     ffd:	4c 8d 80 30 09 00 00 	lea    r8,[rax+0x930]
    1004:	48 3b 90 f0 05 00 00 	cmp    rdx,QWORD PTR [rax+0x5f0]
    100b:	49 0f 47 f8          	cmova  rdi,r8
    100f:	48 ba 8e 08 c4 60 42 	movabs rdx,0x1487d94260c4088e
    1016:	d9 87 14 
    1019:	48 33 17             	xor    rdx,QWORD PTR [rdi]
    101c:	48 01 f2             	add    rdx,rsi
    101f:	48 8b b0 b8 02 00 00 	mov    rsi,QWORD PTR [rax+0x2b8]
    1026:	48 8d b8 78 0c 00 00 	lea    rdi,[rax+0xc78]
    102d:	4c 8d 80 38 09 00 00 	lea    r8,[rax+0x938]
    1034:	48 3b b0 f8 05 00 00 	cmp    rsi,QWORD PTR [rax+0x5f8]
    103b:	49 0f 47 f8          	cmova  rdi,r8
    103f:	48 be 23 f8 46 3f 86 	movabs rsi,0xe5bbfe863f46f823
    1046:	fe bb e5 
    1049:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    104c:	48 01 d6             	add    rsi,rdx
    104f:	48 8b 90 c0 02 00 00 	mov    rdx,QWORD PTR [rax+0x2c0]
    1056:	48 8d b8 80 0c 00 00 	lea    rdi,[rax+0xc80]
    105d:	4c 8d 80 40 09 00 00 	lea    r8,[rax+0x940]
    1064:	48 3b 90 00 06 00 00 	cmp    rdx,QWORD PTR [rax+0x600]
    106b:	49 0f 47 f8          	cmova  rdi,r8
    106f:	48 ba b8 e7 c9 1d ca 	movabs rdx,0xb6f023ca1dc9e7b8
    1076:	23 f0 b6 
    1079:	48 33 17             	xor    rdx,QWORD PTR [rdi]
    107c:	48 01 f2             	add    rdx,rsi
    107f:	48 8b b0 c8 02 00 00 	mov    rsi,QWORD PTR [rax+0x2c8]
    1086:	48 8d b8 88 0c 00 00 	lea    rdi,[rax+0xc88]
    108d:	4c 8d 80 48 09 00 00 	lea    r8,[rax+0x948]
    1094:	48 3b b0 08 06 00 00 	cmp    rsi,QWORD PTR [rax+0x608]
    109b:	49 0f 47 f8          	cmova  rdi,r8
    109f:	48 be 4d d7 4c fc 0d 	movabs rsi,0x8824490dfc4cd74d
    10a6:	49 24 88 
    10a9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    10ac:	48 01 d6             	add    rsi,rdx
    10af:	48 8b 90 d0 02 00 00 	mov    rdx,QWORD PTR [rax+0x2d0]
    10b6:	48 8d b8 90 0c 00 00 	lea    rdi,[rax+0xc90]
    10bd:	4c 8d 80 50 09 00 00 	lea    r8,[rax+0x950]
    10c4:	48 3b 90 10 06 00 00 	cmp    rdx,QWORD PTR [rax+0x610]
    10cb:	49 0f 47 f8          	cmova  rdi,r8
    10cf:	48 ba e2 c6 cf da 51 	movabs rdx,0x59586e51dacfc6e2
    10d6:	6e 58 59 
    10d9:	48 33 17             	xor    rdx,QWORD PTR [rdi]
    10dc:	48 01 f2             	add    rdx,rsi
    10df:	48 8b b0 d8 02 00 00 	mov    rsi,QWORD PTR [rax+0x2d8]
    10e6:	48 8d b8 98 0c 00 00 	lea    rdi,[rax+0xc98]
    10ed:	4c 8d 80 58 09 00 00 	lea    r8,[rax+0x958]
    10f4:	48 3b b0 18 06 00 00 	cmp    rsi,QWORD PTR [rax+0x618]
    10fb:	49 0f 47 f8          	cmova  rdi,r8
    10ff:	48 be 77 b6 52 b9 95 	movabs rsi,0x2a8c9395b952b677
    1106:	93 8c 2a 
    1109:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    110c:	48 01 d6             	add    rsi,rdx
    110f:	48 8b 90 e0 02 00 00 	mov    rdx,QWORD PTR [rax+0x2e0]
    1116:	48 8d b8 a0 0c 00 00 	lea    rdi,[rax+0xca0]
    111d:	4c 8d 80 60 09 00 00 	lea    r8,[rax+0x960]
    1124:	48 3b 90 20 06 00 00 	cmp    rdx,QWORD PTR [rax+0x620]
    112b:	49 0f 47 f8          	cmova  rdi,r8
    112f:	48 ba 0c a6 d5 97 d9 	movabs rdx,0xfbc0b8d997d5a60c
    1136:	b8 c0 fb 
    1139:	48 33 17             	xor    rdx,QWORD PTR [rdi]
    113c:	48 01 f2             	add    rdx,rsi
    113f:	48 01 ca             	add    rdx,rcx
    1142:	48 8b 88 e8 02 00 00 	mov    rcx,QWORD PTR [rax+0x2e8]
    1149:	48 8d b0 a8 0c 00 00 	lea    rsi,[rax+0xca8]
    1150:	48 8d b8 68 09 00 00 	lea    rdi,[rax+0x968]
    1157:	48 3b 88 28 06 00 00 	cmp    rcx,QWORD PTR [rax+0x628]
    115e:	48 0f 47 f7          	cmova  rsi,rdi
    1162:	48 b9 a1 95 58 76 1d 	movabs rcx,0xccf4de1d765895a1
    1169:	de f4 cc 
    116c:	48 33 0e             	xor    rcx,QWORD PTR [rsi]
    116f:	48 8b b0 f0 02 00 00 	mov    rsi,QWORD PTR [rax+0x2f0]
    1176:	48 8d b8 b0 0c 00 00 	lea    rdi,[rax+0xcb0]
    117d:	4c 8d 80 70 09 00 00 	lea    r8,[rax+0x970]
    1184:	48 3b b0 30 06 00 00 	cmp    rsi,QWORD PTR [rax+0x630]
    118b:	49 0f 47 f8          	cmova  rdi,r8
    118f:	48 be 36 85 db 54 61 	movabs rsi,0x9e29036154db8536
    1196:	03 29 9e 
    1199:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    119c:	48 01 ce             	add    rsi,rcx
    119f:	48 8b 88 f8 02 00 00 	mov    rcx,QWORD PTR [rax+0x2f8]
    11a6:	48 8d b8 b8 0c 00 00 	lea    rdi,[rax+0xcb8]
    11ad:	4c 8d 80 78 09 00 00 	lea    r8,[rax+0x978]
    11b4:	48 3b 88 38 06 00 00 	cmp    rcx,QWORD PTR [rax+0x638]
    11bb:	49 0f 47 f8          	cmova  rdi,r8
    11bf:	48 b9 cb 74 5e 33 a5 	movabs rcx,0x6f5d28a5335e74cb
    11c6:	28 5d 6f 
    11c9:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
    11cc:	48 01 f1             	add    rcx,rsi
    11cf:	48 8b b0 00 03 00 00 	mov    rsi,QWORD PTR [rax+0x300]
    11d6:	48 8d b8 c0 0c 00 00 	lea    rdi,[rax+0xcc0]
    11dd:	4c 8d 80 80 09 00 00 	lea    r8,[rax+0x980]
    11e4:	48 3b b0 40 06 00 00 	cmp    rsi,QWORD PTR [rax+0x640]
    11eb:	49 0f 47 f8          	cmova  rdi,r8
    11ef:	48 be 60 64 e1 11 e9 	movabs rsi,0x40914de911e16460
    11f6:	4d 91 40 
    11f9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    11fc:	48 01 ce             	add    rsi,rcx
    11ff:	48 8b 88 08 03 00 00 	mov    rcx,QWORD PTR [rax+0x308]
    1206:	48 8d b8 c8 0c 00 00 	lea    rdi,[rax+0xcc8]
    120d:	4c 8d 80 88 09 00 00 	lea    r8,[rax+0x988]
    1214:	48 3b 88 48 06 00 00 	cmp    rcx,QWORD PTR [rax+0x648]
    121b:	49 0f 47 f8          	cmova  rdi,r8
    121f:	48 b9 f5 53 64 f0 2c 	movabs rcx,0x11c5732cf06453f5
    1226:	73 c5 11 
    1229:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
    122c:	48 01 f1             	add    rcx,rsi
    122f:	48 8b b0 10 03 00 00 	mov    rsi,QWORD PTR [rax+0x310]
    1236:	48 8d b8 d0 0c 00 00 	lea    rdi,[rax+0xcd0]
    123d:	4c 8d 80 90 09 00 00 	lea    r8,[rax+0x990]
    1244:	48 3b b0 50 06 00 00 	cmp    rsi,QWORD PTR [rax+0x650]
    124b:	49 0f 47 f8          	cmova  rdi,r8
    124f:	48 be 8a 43 e7 ce 70 	movabs rsi,0xe2f99870cee7438a
    1256:	98 f9 e2 
    1259:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    125c:	48 01 ce             	add    rsi,rcx
    125f:	48 8b 88 18 03 00 00 	mov    rcx,QWORD PTR [rax+0x318]
    1266:	48 8d b8 d8 0c 00 00 	lea    rdi,[rax+0xcd8]
    126d:	4c 8d 80 98 09 00 00 	lea    r8,[rax+0x998]
    1274:	48 3b 88 58 06 00 00 	cmp    rcx,QWORD PTR [rax+0x658]
    127b:	49 0f 47 f8          	cmova  rdi,r8
    127f:	48 b9 1f 33 6a ad b4 	movabs rcx,0xb42dbdb4ad6a331f
    1286:	bd 2d b4 
    1289:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
    128c:	48 01 f1             	add    rcx,rsi
    128f:	48 8b b0 20 03 00 00 	mov    rsi,QWORD PTR [rax+0x320]
    1296:	48 8d b8 e0 0c 00 00 	lea    rdi,[rax+0xce0]
    129d:	4c 8d 80 a0 09 00 00 	lea    r8,[rax+0x9a0]
    12a4:	48 3b b0 60 06 00 00 	cmp    rsi,QWORD PTR [rax+0x660]
    12ab:	49 0f 47 f8          	cmova  rdi,r8
    12af:	48 be b4 22 ed 8b f8 	movabs rsi,0x8561e2f88bed22b4
    12b6:	e2 61 85 
    12b9:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    12bc:	48 01 ce             	add    rsi,rcx
    12bf:	48 8b 88 28 03 00 00 	mov    rcx,QWORD PTR [rax+0x328]
    12c6:	48 8d b8 e8 0c 00 00 	lea    rdi,[rax+0xce8]
    12cd:	4c 8d 80 a8 09 00 00 	lea    r8,[rax+0x9a8]
    12d4:	48 3b 88 68 06 00 00 	cmp    rcx,QWORD PTR [rax+0x668]
    12db:	49 0f 47 f8          	cmova  rdi,r8
    12df:	48 b9 49 12 70 6a 3c 	movabs rcx,0x5696083c6a701249
    12e6:	08 96 56 
    12e9:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
    12ec:	48 01 f1             	add    rcx,rsi
    12ef:	48 8b b0 30 03 00 00 	mov    rsi,QWORD PTR [rax+0x330]
    12f6:	48 8d b8 f0 0c 00 00 	lea    rdi,[rax+0xcf0]
    12fd:	4c 8d 80 b0 09 00 00 	lea    r8,[rax+0x9b0]
    1304:	48 3b b0 70 06 00 00 	cmp    rsi,QWORD PTR [rax+0x670]
    130b:	49 0f 47 f8          	cmova  rdi,r8
    130f:	48 be de 01 f3 48 80 	movabs rsi,0x27ca2d8048f301de
    1316:	2d ca 27 
    1319:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    131c:	48 01 ce             	add    rsi,rcx
    131f:	48 8b 88 38 03 00 00 	mov    rcx,QWORD PTR [rax+0x338]
    1326:	48 8d b8 f8 0c 00 00 	lea    rdi,[rax+0xcf8]
    132d:	4c 8d 80 b8 09 00 00 	lea    r8,[rax+0x9b8]
    1334:	48 3b 88 78 06 00 00 	cmp    rcx,QWORD PTR [rax+0x678]
    133b:	49 0f 47 f8          	cmova  rdi,r8
    133f:	48 b9 73 f1 75 27 c4 	movabs rcx,0xf8fe52c42775f173
    1346:	52 fe f8 
    1349:	48 33 0f             	xor    rcx,QWORD PTR [rdi]
    134c:	48 01 f1             	add    rcx,rsi
    134f:	48 8b b0 40 03 00 00 	mov    rsi,QWORD PTR [rax+0x340]
    1356:	48 8d b8 00 0d 00 00 	lea    rdi,[rax+0xd00]
    135d:	48 3b b0 80 06 00 00 	cmp    rsi,QWORD PTR [rax+0x680]
    1364:	48 8d b0 c0 09 00 00 	lea    rsi,[rax+0x9c0]
    136b:	48 0f 47 fe          	cmova  rdi,rsi
    136f:	48 be 08 e1 f8 05 08 	movabs rsi,0xca32780805f8e108
    1376:	78 32 ca 
    1379:	48 33 37             	xor    rsi,QWORD PTR [rdi]
    137c:	48 01 ce             	add    rsi,rcx
    137f:	48 b9 d3 05 a3 85 88 	movabs rcx,0x243f6a8885a305d3
    1386:	6a 3f 24 
    1389:	48 01 f1             	add    rcx,rsi
    138c:	48 01 d1             	add    rcx,rdx
    138f:	48 89 08             	mov    QWORD PTR [rax],rcx
    1392:	b8 02 00 00 00       	mov    eax,0x2
    1397:	c3                   	ret
