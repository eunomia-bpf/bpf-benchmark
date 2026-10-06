
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/extract_dense.kernel.bin:     file format binary


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
      19:	0f 87 cc 2b 00 00    	ja     0x2beb
      1f:	48 89 fa             	mov    rdx,rdi
      22:	48 83 c2 08          	add    rdx,0x8
      26:	48 39 f2             	cmp    rdx,rsi
      29:	0f 87 bc 2b 00 00    	ja     0x2beb
      2f:	48 89 fa             	mov    rdx,rdi
      32:	48 81 c2 08 08 00 00 	add    rdx,0x808
      39:	48 39 f2             	cmp    rdx,rsi
      3c:	0f 87 a9 2b 00 00    	ja     0x2beb
      42:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
      46:	48 89 d1             	mov    rcx,rdx
      49:	48 c1 e9 05          	shr    rcx,0x5
      4d:	48 83 e1 1f          	and    rcx,0x1f
      51:	49 89 d0             	mov    r8,rdx
      54:	49 c1 e8 11          	shr    r8,0x11
      58:	49 81 e0 ff 03 00 00 	and    r8,0x3ff
      5f:	4c 89 c6             	mov    rsi,r8
      62:	48 01 ce             	add    rsi,rcx
      65:	48 b8 3b af ca 84 85 	movabs rax,0xbb67ae8584caaf3b
      6c:	ae 67 bb 
      6f:	48 01 c6             	add    rsi,rax
      72:	48 8b 57 10          	mov    rdx,QWORD PTR [rdi+0x10]
      76:	48 89 d1             	mov    rcx,rdx
      79:	48 c1 e9 11          	shr    rcx,0x11
      7d:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
      84:	48 01 ce             	add    rsi,rcx
      87:	49 89 d0             	mov    r8,rdx
      8a:	49 c1 e8 05          	shr    r8,0x5
      8e:	49 83 e0 1f          	and    r8,0x1f
      92:	4c 01 c6             	add    rsi,r8
      95:	48 83 c6 01          	add    rsi,0x1
      99:	48 8b 57 18          	mov    rdx,QWORD PTR [rdi+0x18]
      9d:	48 89 d1             	mov    rcx,rdx
      a0:	48 c1 e9 11          	shr    rcx,0x11
      a4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
      ab:	48 01 ce             	add    rsi,rcx
      ae:	49 89 d0             	mov    r8,rdx
      b1:	49 c1 e8 05          	shr    r8,0x5
      b5:	49 83 e0 1f          	and    r8,0x1f
      b9:	4c 01 c6             	add    rsi,r8
      bc:	48 83 c6 02          	add    rsi,0x2
      c0:	48 8b 57 20          	mov    rdx,QWORD PTR [rdi+0x20]
      c4:	48 89 d1             	mov    rcx,rdx
      c7:	48 c1 e9 11          	shr    rcx,0x11
      cb:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
      d2:	48 01 ce             	add    rsi,rcx
      d5:	49 89 d0             	mov    r8,rdx
      d8:	49 c1 e8 05          	shr    r8,0x5
      dc:	49 83 e0 1f          	and    r8,0x1f
      e0:	4c 01 c6             	add    rsi,r8
      e3:	48 83 c6 03          	add    rsi,0x3
      e7:	48 8b 57 28          	mov    rdx,QWORD PTR [rdi+0x28]
      eb:	48 89 d1             	mov    rcx,rdx
      ee:	48 c1 e9 11          	shr    rcx,0x11
      f2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
      f9:	48 01 ce             	add    rsi,rcx
      fc:	49 89 d0             	mov    r8,rdx
      ff:	49 c1 e8 05          	shr    r8,0x5
     103:	49 83 e0 1f          	and    r8,0x1f
     107:	4c 01 c6             	add    rsi,r8
     10a:	48 83 c6 04          	add    rsi,0x4
     10e:	48 8b 57 30          	mov    rdx,QWORD PTR [rdi+0x30]
     112:	48 89 d1             	mov    rcx,rdx
     115:	48 c1 e9 11          	shr    rcx,0x11
     119:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     120:	48 01 ce             	add    rsi,rcx
     123:	49 89 d0             	mov    r8,rdx
     126:	49 c1 e8 05          	shr    r8,0x5
     12a:	49 83 e0 1f          	and    r8,0x1f
     12e:	4c 01 c6             	add    rsi,r8
     131:	48 83 c6 05          	add    rsi,0x5
     135:	48 8b 57 38          	mov    rdx,QWORD PTR [rdi+0x38]
     139:	48 89 d1             	mov    rcx,rdx
     13c:	48 c1 e9 11          	shr    rcx,0x11
     140:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     147:	48 01 ce             	add    rsi,rcx
     14a:	49 89 d0             	mov    r8,rdx
     14d:	49 c1 e8 05          	shr    r8,0x5
     151:	49 83 e0 1f          	and    r8,0x1f
     155:	4c 01 c6             	add    rsi,r8
     158:	48 83 c6 06          	add    rsi,0x6
     15c:	48 8b 57 40          	mov    rdx,QWORD PTR [rdi+0x40]
     160:	48 89 d1             	mov    rcx,rdx
     163:	48 c1 e9 11          	shr    rcx,0x11
     167:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     16e:	48 01 ce             	add    rsi,rcx
     171:	49 89 d0             	mov    r8,rdx
     174:	49 c1 e8 05          	shr    r8,0x5
     178:	49 83 e0 1f          	and    r8,0x1f
     17c:	4c 01 c6             	add    rsi,r8
     17f:	48 83 c6 07          	add    rsi,0x7
     183:	48 8b 57 48          	mov    rdx,QWORD PTR [rdi+0x48]
     187:	48 89 d1             	mov    rcx,rdx
     18a:	48 c1 e9 11          	shr    rcx,0x11
     18e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     195:	48 01 ce             	add    rsi,rcx
     198:	49 89 d0             	mov    r8,rdx
     19b:	49 c1 e8 05          	shr    r8,0x5
     19f:	49 83 e0 1f          	and    r8,0x1f
     1a3:	4c 01 c6             	add    rsi,r8
     1a6:	48 83 c6 08          	add    rsi,0x8
     1aa:	48 8b 57 50          	mov    rdx,QWORD PTR [rdi+0x50]
     1ae:	48 89 d1             	mov    rcx,rdx
     1b1:	48 c1 e9 11          	shr    rcx,0x11
     1b5:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     1bc:	48 01 ce             	add    rsi,rcx
     1bf:	49 89 d0             	mov    r8,rdx
     1c2:	49 c1 e8 05          	shr    r8,0x5
     1c6:	49 83 e0 1f          	and    r8,0x1f
     1ca:	4c 01 c6             	add    rsi,r8
     1cd:	48 83 c6 09          	add    rsi,0x9
     1d1:	48 8b 57 58          	mov    rdx,QWORD PTR [rdi+0x58]
     1d5:	48 89 d1             	mov    rcx,rdx
     1d8:	48 c1 e9 11          	shr    rcx,0x11
     1dc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     1e3:	48 01 ce             	add    rsi,rcx
     1e6:	49 89 d0             	mov    r8,rdx
     1e9:	49 c1 e8 05          	shr    r8,0x5
     1ed:	49 83 e0 1f          	and    r8,0x1f
     1f1:	4c 01 c6             	add    rsi,r8
     1f4:	48 83 c6 0a          	add    rsi,0xa
     1f8:	48 8b 57 60          	mov    rdx,QWORD PTR [rdi+0x60]
     1fc:	48 89 d1             	mov    rcx,rdx
     1ff:	48 c1 e9 11          	shr    rcx,0x11
     203:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     20a:	48 01 ce             	add    rsi,rcx
     20d:	49 89 d0             	mov    r8,rdx
     210:	49 c1 e8 05          	shr    r8,0x5
     214:	49 83 e0 1f          	and    r8,0x1f
     218:	4c 01 c6             	add    rsi,r8
     21b:	48 83 c6 0b          	add    rsi,0xb
     21f:	48 8b 57 68          	mov    rdx,QWORD PTR [rdi+0x68]
     223:	48 89 d1             	mov    rcx,rdx
     226:	48 c1 e9 11          	shr    rcx,0x11
     22a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     231:	48 01 ce             	add    rsi,rcx
     234:	49 89 d0             	mov    r8,rdx
     237:	49 c1 e8 05          	shr    r8,0x5
     23b:	49 83 e0 1f          	and    r8,0x1f
     23f:	4c 01 c6             	add    rsi,r8
     242:	48 83 c6 0c          	add    rsi,0xc
     246:	48 8b 57 70          	mov    rdx,QWORD PTR [rdi+0x70]
     24a:	48 89 d1             	mov    rcx,rdx
     24d:	48 c1 e9 11          	shr    rcx,0x11
     251:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     258:	48 01 ce             	add    rsi,rcx
     25b:	49 89 d0             	mov    r8,rdx
     25e:	49 c1 e8 05          	shr    r8,0x5
     262:	49 83 e0 1f          	and    r8,0x1f
     266:	4c 01 c6             	add    rsi,r8
     269:	48 83 c6 0d          	add    rsi,0xd
     26d:	48 8b 57 78          	mov    rdx,QWORD PTR [rdi+0x78]
     271:	48 89 d1             	mov    rcx,rdx
     274:	48 c1 e9 11          	shr    rcx,0x11
     278:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     27f:	48 01 ce             	add    rsi,rcx
     282:	49 89 d0             	mov    r8,rdx
     285:	49 c1 e8 05          	shr    r8,0x5
     289:	49 83 e0 1f          	and    r8,0x1f
     28d:	4c 01 c6             	add    rsi,r8
     290:	48 83 c6 0e          	add    rsi,0xe
     294:	48 8b 97 80 00 00 00 	mov    rdx,QWORD PTR [rdi+0x80]
     29b:	48 89 d1             	mov    rcx,rdx
     29e:	48 c1 e9 11          	shr    rcx,0x11
     2a2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     2a9:	48 01 ce             	add    rsi,rcx
     2ac:	49 89 d0             	mov    r8,rdx
     2af:	49 c1 e8 05          	shr    r8,0x5
     2b3:	49 83 e0 1f          	and    r8,0x1f
     2b7:	4c 01 c6             	add    rsi,r8
     2ba:	48 83 c6 0f          	add    rsi,0xf
     2be:	48 8b 97 88 00 00 00 	mov    rdx,QWORD PTR [rdi+0x88]
     2c5:	48 89 d1             	mov    rcx,rdx
     2c8:	48 c1 e9 11          	shr    rcx,0x11
     2cc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     2d3:	48 01 ce             	add    rsi,rcx
     2d6:	49 89 d0             	mov    r8,rdx
     2d9:	49 c1 e8 05          	shr    r8,0x5
     2dd:	49 83 e0 1f          	and    r8,0x1f
     2e1:	4c 01 c6             	add    rsi,r8
     2e4:	48 83 c6 10          	add    rsi,0x10
     2e8:	48 8b 97 90 00 00 00 	mov    rdx,QWORD PTR [rdi+0x90]
     2ef:	48 89 d1             	mov    rcx,rdx
     2f2:	48 c1 e9 11          	shr    rcx,0x11
     2f6:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     2fd:	48 01 ce             	add    rsi,rcx
     300:	49 89 d0             	mov    r8,rdx
     303:	49 c1 e8 05          	shr    r8,0x5
     307:	49 83 e0 1f          	and    r8,0x1f
     30b:	4c 01 c6             	add    rsi,r8
     30e:	48 83 c6 11          	add    rsi,0x11
     312:	48 8b 97 98 00 00 00 	mov    rdx,QWORD PTR [rdi+0x98]
     319:	48 89 d1             	mov    rcx,rdx
     31c:	48 c1 e9 11          	shr    rcx,0x11
     320:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     327:	48 01 ce             	add    rsi,rcx
     32a:	49 89 d0             	mov    r8,rdx
     32d:	49 c1 e8 05          	shr    r8,0x5
     331:	49 83 e0 1f          	and    r8,0x1f
     335:	4c 01 c6             	add    rsi,r8
     338:	48 83 c6 12          	add    rsi,0x12
     33c:	48 8b 97 a0 00 00 00 	mov    rdx,QWORD PTR [rdi+0xa0]
     343:	48 89 d1             	mov    rcx,rdx
     346:	48 c1 e9 11          	shr    rcx,0x11
     34a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     351:	48 01 ce             	add    rsi,rcx
     354:	49 89 d0             	mov    r8,rdx
     357:	49 c1 e8 05          	shr    r8,0x5
     35b:	49 83 e0 1f          	and    r8,0x1f
     35f:	4c 01 c6             	add    rsi,r8
     362:	48 83 c6 13          	add    rsi,0x13
     366:	48 8b 97 a8 00 00 00 	mov    rdx,QWORD PTR [rdi+0xa8]
     36d:	48 89 d1             	mov    rcx,rdx
     370:	48 c1 e9 11          	shr    rcx,0x11
     374:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     37b:	48 01 ce             	add    rsi,rcx
     37e:	49 89 d0             	mov    r8,rdx
     381:	49 c1 e8 05          	shr    r8,0x5
     385:	49 83 e0 1f          	and    r8,0x1f
     389:	4c 01 c6             	add    rsi,r8
     38c:	48 83 c6 14          	add    rsi,0x14
     390:	48 8b 97 b0 00 00 00 	mov    rdx,QWORD PTR [rdi+0xb0]
     397:	48 89 d1             	mov    rcx,rdx
     39a:	48 c1 e9 11          	shr    rcx,0x11
     39e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     3a5:	48 01 ce             	add    rsi,rcx
     3a8:	49 89 d0             	mov    r8,rdx
     3ab:	49 c1 e8 05          	shr    r8,0x5
     3af:	49 83 e0 1f          	and    r8,0x1f
     3b3:	4c 01 c6             	add    rsi,r8
     3b6:	48 83 c6 15          	add    rsi,0x15
     3ba:	48 8b 97 b8 00 00 00 	mov    rdx,QWORD PTR [rdi+0xb8]
     3c1:	48 89 d1             	mov    rcx,rdx
     3c4:	48 c1 e9 11          	shr    rcx,0x11
     3c8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     3cf:	48 01 ce             	add    rsi,rcx
     3d2:	49 89 d0             	mov    r8,rdx
     3d5:	49 c1 e8 05          	shr    r8,0x5
     3d9:	49 83 e0 1f          	and    r8,0x1f
     3dd:	4c 01 c6             	add    rsi,r8
     3e0:	48 83 c6 16          	add    rsi,0x16
     3e4:	48 8b 97 c0 00 00 00 	mov    rdx,QWORD PTR [rdi+0xc0]
     3eb:	48 89 d1             	mov    rcx,rdx
     3ee:	48 c1 e9 11          	shr    rcx,0x11
     3f2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     3f9:	48 01 ce             	add    rsi,rcx
     3fc:	49 89 d0             	mov    r8,rdx
     3ff:	49 c1 e8 05          	shr    r8,0x5
     403:	49 83 e0 1f          	and    r8,0x1f
     407:	4c 01 c6             	add    rsi,r8
     40a:	48 83 c6 17          	add    rsi,0x17
     40e:	48 8b 97 c8 00 00 00 	mov    rdx,QWORD PTR [rdi+0xc8]
     415:	48 89 d1             	mov    rcx,rdx
     418:	48 c1 e9 11          	shr    rcx,0x11
     41c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     423:	48 01 ce             	add    rsi,rcx
     426:	49 89 d0             	mov    r8,rdx
     429:	49 c1 e8 05          	shr    r8,0x5
     42d:	49 83 e0 1f          	and    r8,0x1f
     431:	4c 01 c6             	add    rsi,r8
     434:	48 83 c6 18          	add    rsi,0x18
     438:	48 8b 97 d0 00 00 00 	mov    rdx,QWORD PTR [rdi+0xd0]
     43f:	48 89 d1             	mov    rcx,rdx
     442:	48 c1 e9 11          	shr    rcx,0x11
     446:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     44d:	48 01 ce             	add    rsi,rcx
     450:	49 89 d0             	mov    r8,rdx
     453:	49 c1 e8 05          	shr    r8,0x5
     457:	49 83 e0 1f          	and    r8,0x1f
     45b:	4c 01 c6             	add    rsi,r8
     45e:	48 83 c6 19          	add    rsi,0x19
     462:	48 8b 97 d8 00 00 00 	mov    rdx,QWORD PTR [rdi+0xd8]
     469:	48 89 d1             	mov    rcx,rdx
     46c:	48 c1 e9 11          	shr    rcx,0x11
     470:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     477:	48 01 ce             	add    rsi,rcx
     47a:	49 89 d0             	mov    r8,rdx
     47d:	49 c1 e8 05          	shr    r8,0x5
     481:	49 83 e0 1f          	and    r8,0x1f
     485:	4c 01 c6             	add    rsi,r8
     488:	48 83 c6 1a          	add    rsi,0x1a
     48c:	48 8b 97 e0 00 00 00 	mov    rdx,QWORD PTR [rdi+0xe0]
     493:	48 89 d1             	mov    rcx,rdx
     496:	48 c1 e9 11          	shr    rcx,0x11
     49a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     4a1:	48 01 ce             	add    rsi,rcx
     4a4:	49 89 d0             	mov    r8,rdx
     4a7:	49 c1 e8 05          	shr    r8,0x5
     4ab:	49 83 e0 1f          	and    r8,0x1f
     4af:	4c 01 c6             	add    rsi,r8
     4b2:	48 83 c6 1b          	add    rsi,0x1b
     4b6:	48 8b 97 e8 00 00 00 	mov    rdx,QWORD PTR [rdi+0xe8]
     4bd:	48 89 d1             	mov    rcx,rdx
     4c0:	48 c1 e9 11          	shr    rcx,0x11
     4c4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     4cb:	48 01 ce             	add    rsi,rcx
     4ce:	49 89 d0             	mov    r8,rdx
     4d1:	49 c1 e8 05          	shr    r8,0x5
     4d5:	49 83 e0 1f          	and    r8,0x1f
     4d9:	4c 01 c6             	add    rsi,r8
     4dc:	48 83 c6 1c          	add    rsi,0x1c
     4e0:	48 8b 97 f0 00 00 00 	mov    rdx,QWORD PTR [rdi+0xf0]
     4e7:	48 89 d1             	mov    rcx,rdx
     4ea:	48 c1 e9 11          	shr    rcx,0x11
     4ee:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     4f5:	48 01 ce             	add    rsi,rcx
     4f8:	49 89 d0             	mov    r8,rdx
     4fb:	49 c1 e8 05          	shr    r8,0x5
     4ff:	49 83 e0 1f          	and    r8,0x1f
     503:	4c 01 c6             	add    rsi,r8
     506:	48 83 c6 1d          	add    rsi,0x1d
     50a:	48 8b 97 f8 00 00 00 	mov    rdx,QWORD PTR [rdi+0xf8]
     511:	48 89 d1             	mov    rcx,rdx
     514:	48 c1 e9 11          	shr    rcx,0x11
     518:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     51f:	48 01 ce             	add    rsi,rcx
     522:	49 89 d0             	mov    r8,rdx
     525:	49 c1 e8 05          	shr    r8,0x5
     529:	49 83 e0 1f          	and    r8,0x1f
     52d:	4c 01 c6             	add    rsi,r8
     530:	48 83 c6 1e          	add    rsi,0x1e
     534:	48 8b 97 00 01 00 00 	mov    rdx,QWORD PTR [rdi+0x100]
     53b:	48 89 d1             	mov    rcx,rdx
     53e:	48 c1 e9 11          	shr    rcx,0x11
     542:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     549:	48 01 ce             	add    rsi,rcx
     54c:	49 89 d0             	mov    r8,rdx
     54f:	49 c1 e8 05          	shr    r8,0x5
     553:	49 83 e0 1f          	and    r8,0x1f
     557:	4c 01 c6             	add    rsi,r8
     55a:	48 83 c6 1f          	add    rsi,0x1f
     55e:	48 8b 97 08 01 00 00 	mov    rdx,QWORD PTR [rdi+0x108]
     565:	48 89 d1             	mov    rcx,rdx
     568:	48 c1 e9 11          	shr    rcx,0x11
     56c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     573:	48 01 ce             	add    rsi,rcx
     576:	49 89 d0             	mov    r8,rdx
     579:	49 c1 e8 05          	shr    r8,0x5
     57d:	49 83 e0 1f          	and    r8,0x1f
     581:	4c 01 c6             	add    rsi,r8
     584:	48 83 c6 20          	add    rsi,0x20
     588:	48 8b 97 10 01 00 00 	mov    rdx,QWORD PTR [rdi+0x110]
     58f:	48 89 d1             	mov    rcx,rdx
     592:	48 c1 e9 11          	shr    rcx,0x11
     596:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     59d:	48 01 ce             	add    rsi,rcx
     5a0:	49 89 d0             	mov    r8,rdx
     5a3:	49 c1 e8 05          	shr    r8,0x5
     5a7:	49 83 e0 1f          	and    r8,0x1f
     5ab:	4c 01 c6             	add    rsi,r8
     5ae:	48 83 c6 21          	add    rsi,0x21
     5b2:	48 8b 97 18 01 00 00 	mov    rdx,QWORD PTR [rdi+0x118]
     5b9:	48 89 d1             	mov    rcx,rdx
     5bc:	48 c1 e9 11          	shr    rcx,0x11
     5c0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     5c7:	48 01 ce             	add    rsi,rcx
     5ca:	49 89 d0             	mov    r8,rdx
     5cd:	49 c1 e8 05          	shr    r8,0x5
     5d1:	49 83 e0 1f          	and    r8,0x1f
     5d5:	4c 01 c6             	add    rsi,r8
     5d8:	48 83 c6 22          	add    rsi,0x22
     5dc:	48 8b 97 20 01 00 00 	mov    rdx,QWORD PTR [rdi+0x120]
     5e3:	48 89 d1             	mov    rcx,rdx
     5e6:	48 c1 e9 11          	shr    rcx,0x11
     5ea:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     5f1:	48 01 ce             	add    rsi,rcx
     5f4:	49 89 d0             	mov    r8,rdx
     5f7:	49 c1 e8 05          	shr    r8,0x5
     5fb:	49 83 e0 1f          	and    r8,0x1f
     5ff:	4c 01 c6             	add    rsi,r8
     602:	48 83 c6 23          	add    rsi,0x23
     606:	48 8b 97 28 01 00 00 	mov    rdx,QWORD PTR [rdi+0x128]
     60d:	48 89 d1             	mov    rcx,rdx
     610:	48 c1 e9 11          	shr    rcx,0x11
     614:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     61b:	48 01 ce             	add    rsi,rcx
     61e:	49 89 d0             	mov    r8,rdx
     621:	49 c1 e8 05          	shr    r8,0x5
     625:	49 83 e0 1f          	and    r8,0x1f
     629:	4c 01 c6             	add    rsi,r8
     62c:	48 83 c6 24          	add    rsi,0x24
     630:	48 8b 97 30 01 00 00 	mov    rdx,QWORD PTR [rdi+0x130]
     637:	48 89 d1             	mov    rcx,rdx
     63a:	48 c1 e9 11          	shr    rcx,0x11
     63e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     645:	48 01 ce             	add    rsi,rcx
     648:	49 89 d0             	mov    r8,rdx
     64b:	49 c1 e8 05          	shr    r8,0x5
     64f:	49 83 e0 1f          	and    r8,0x1f
     653:	4c 01 c6             	add    rsi,r8
     656:	48 83 c6 25          	add    rsi,0x25
     65a:	48 8b 97 38 01 00 00 	mov    rdx,QWORD PTR [rdi+0x138]
     661:	48 89 d1             	mov    rcx,rdx
     664:	48 c1 e9 11          	shr    rcx,0x11
     668:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     66f:	48 01 ce             	add    rsi,rcx
     672:	49 89 d0             	mov    r8,rdx
     675:	49 c1 e8 05          	shr    r8,0x5
     679:	49 83 e0 1f          	and    r8,0x1f
     67d:	4c 01 c6             	add    rsi,r8
     680:	48 83 c6 26          	add    rsi,0x26
     684:	48 8b 97 40 01 00 00 	mov    rdx,QWORD PTR [rdi+0x140]
     68b:	48 89 d1             	mov    rcx,rdx
     68e:	48 c1 e9 11          	shr    rcx,0x11
     692:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     699:	48 01 ce             	add    rsi,rcx
     69c:	49 89 d0             	mov    r8,rdx
     69f:	49 c1 e8 05          	shr    r8,0x5
     6a3:	49 83 e0 1f          	and    r8,0x1f
     6a7:	4c 01 c6             	add    rsi,r8
     6aa:	48 83 c6 27          	add    rsi,0x27
     6ae:	48 8b 97 48 01 00 00 	mov    rdx,QWORD PTR [rdi+0x148]
     6b5:	48 89 d1             	mov    rcx,rdx
     6b8:	48 c1 e9 11          	shr    rcx,0x11
     6bc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     6c3:	48 01 ce             	add    rsi,rcx
     6c6:	49 89 d0             	mov    r8,rdx
     6c9:	49 c1 e8 05          	shr    r8,0x5
     6cd:	49 83 e0 1f          	and    r8,0x1f
     6d1:	4c 01 c6             	add    rsi,r8
     6d4:	48 83 c6 28          	add    rsi,0x28
     6d8:	48 8b 97 50 01 00 00 	mov    rdx,QWORD PTR [rdi+0x150]
     6df:	48 89 d1             	mov    rcx,rdx
     6e2:	48 c1 e9 11          	shr    rcx,0x11
     6e6:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     6ed:	48 01 ce             	add    rsi,rcx
     6f0:	49 89 d0             	mov    r8,rdx
     6f3:	49 c1 e8 05          	shr    r8,0x5
     6f7:	49 83 e0 1f          	and    r8,0x1f
     6fb:	4c 01 c6             	add    rsi,r8
     6fe:	48 83 c6 29          	add    rsi,0x29
     702:	48 8b 97 58 01 00 00 	mov    rdx,QWORD PTR [rdi+0x158]
     709:	48 89 d1             	mov    rcx,rdx
     70c:	48 c1 e9 11          	shr    rcx,0x11
     710:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     717:	48 01 ce             	add    rsi,rcx
     71a:	49 89 d0             	mov    r8,rdx
     71d:	49 c1 e8 05          	shr    r8,0x5
     721:	49 83 e0 1f          	and    r8,0x1f
     725:	4c 01 c6             	add    rsi,r8
     728:	48 83 c6 2a          	add    rsi,0x2a
     72c:	48 8b 97 60 01 00 00 	mov    rdx,QWORD PTR [rdi+0x160]
     733:	48 89 d1             	mov    rcx,rdx
     736:	48 c1 e9 11          	shr    rcx,0x11
     73a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     741:	48 01 ce             	add    rsi,rcx
     744:	49 89 d0             	mov    r8,rdx
     747:	49 c1 e8 05          	shr    r8,0x5
     74b:	49 83 e0 1f          	and    r8,0x1f
     74f:	4c 01 c6             	add    rsi,r8
     752:	48 83 c6 2b          	add    rsi,0x2b
     756:	48 8b 97 68 01 00 00 	mov    rdx,QWORD PTR [rdi+0x168]
     75d:	48 89 d1             	mov    rcx,rdx
     760:	48 c1 e9 11          	shr    rcx,0x11
     764:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     76b:	48 01 ce             	add    rsi,rcx
     76e:	49 89 d0             	mov    r8,rdx
     771:	49 c1 e8 05          	shr    r8,0x5
     775:	49 83 e0 1f          	and    r8,0x1f
     779:	4c 01 c6             	add    rsi,r8
     77c:	48 83 c6 2c          	add    rsi,0x2c
     780:	48 8b 97 70 01 00 00 	mov    rdx,QWORD PTR [rdi+0x170]
     787:	48 89 d1             	mov    rcx,rdx
     78a:	48 c1 e9 11          	shr    rcx,0x11
     78e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     795:	48 01 ce             	add    rsi,rcx
     798:	49 89 d0             	mov    r8,rdx
     79b:	49 c1 e8 05          	shr    r8,0x5
     79f:	49 83 e0 1f          	and    r8,0x1f
     7a3:	4c 01 c6             	add    rsi,r8
     7a6:	48 83 c6 2d          	add    rsi,0x2d
     7aa:	48 8b 97 78 01 00 00 	mov    rdx,QWORD PTR [rdi+0x178]
     7b1:	48 89 d1             	mov    rcx,rdx
     7b4:	48 c1 e9 11          	shr    rcx,0x11
     7b8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     7bf:	48 01 ce             	add    rsi,rcx
     7c2:	49 89 d0             	mov    r8,rdx
     7c5:	49 c1 e8 05          	shr    r8,0x5
     7c9:	49 83 e0 1f          	and    r8,0x1f
     7cd:	4c 01 c6             	add    rsi,r8
     7d0:	48 83 c6 2e          	add    rsi,0x2e
     7d4:	48 8b 97 80 01 00 00 	mov    rdx,QWORD PTR [rdi+0x180]
     7db:	48 89 d1             	mov    rcx,rdx
     7de:	48 c1 e9 11          	shr    rcx,0x11
     7e2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     7e9:	48 01 ce             	add    rsi,rcx
     7ec:	49 89 d0             	mov    r8,rdx
     7ef:	49 c1 e8 05          	shr    r8,0x5
     7f3:	49 83 e0 1f          	and    r8,0x1f
     7f7:	4c 01 c6             	add    rsi,r8
     7fa:	48 83 c6 2f          	add    rsi,0x2f
     7fe:	48 8b 97 88 01 00 00 	mov    rdx,QWORD PTR [rdi+0x188]
     805:	48 89 d1             	mov    rcx,rdx
     808:	48 c1 e9 11          	shr    rcx,0x11
     80c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     813:	48 01 ce             	add    rsi,rcx
     816:	49 89 d0             	mov    r8,rdx
     819:	49 c1 e8 05          	shr    r8,0x5
     81d:	49 83 e0 1f          	and    r8,0x1f
     821:	4c 01 c6             	add    rsi,r8
     824:	48 83 c6 30          	add    rsi,0x30
     828:	48 8b 97 90 01 00 00 	mov    rdx,QWORD PTR [rdi+0x190]
     82f:	48 89 d1             	mov    rcx,rdx
     832:	48 c1 e9 11          	shr    rcx,0x11
     836:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     83d:	48 01 ce             	add    rsi,rcx
     840:	49 89 d0             	mov    r8,rdx
     843:	49 c1 e8 05          	shr    r8,0x5
     847:	49 83 e0 1f          	and    r8,0x1f
     84b:	4c 01 c6             	add    rsi,r8
     84e:	48 83 c6 31          	add    rsi,0x31
     852:	48 8b 97 98 01 00 00 	mov    rdx,QWORD PTR [rdi+0x198]
     859:	48 89 d1             	mov    rcx,rdx
     85c:	48 c1 e9 11          	shr    rcx,0x11
     860:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     867:	48 01 ce             	add    rsi,rcx
     86a:	49 89 d0             	mov    r8,rdx
     86d:	49 c1 e8 05          	shr    r8,0x5
     871:	49 83 e0 1f          	and    r8,0x1f
     875:	4c 01 c6             	add    rsi,r8
     878:	48 83 c6 32          	add    rsi,0x32
     87c:	48 8b 97 a0 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1a0]
     883:	48 89 d1             	mov    rcx,rdx
     886:	48 c1 e9 11          	shr    rcx,0x11
     88a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     891:	48 01 ce             	add    rsi,rcx
     894:	49 89 d0             	mov    r8,rdx
     897:	49 c1 e8 05          	shr    r8,0x5
     89b:	49 83 e0 1f          	and    r8,0x1f
     89f:	4c 01 c6             	add    rsi,r8
     8a2:	48 83 c6 33          	add    rsi,0x33
     8a6:	48 8b 97 a8 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1a8]
     8ad:	48 89 d1             	mov    rcx,rdx
     8b0:	48 c1 e9 11          	shr    rcx,0x11
     8b4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     8bb:	48 01 ce             	add    rsi,rcx
     8be:	49 89 d0             	mov    r8,rdx
     8c1:	49 c1 e8 05          	shr    r8,0x5
     8c5:	49 83 e0 1f          	and    r8,0x1f
     8c9:	4c 01 c6             	add    rsi,r8
     8cc:	48 83 c6 34          	add    rsi,0x34
     8d0:	48 8b 97 b0 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1b0]
     8d7:	48 89 d1             	mov    rcx,rdx
     8da:	48 c1 e9 11          	shr    rcx,0x11
     8de:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     8e5:	48 01 ce             	add    rsi,rcx
     8e8:	49 89 d0             	mov    r8,rdx
     8eb:	49 c1 e8 05          	shr    r8,0x5
     8ef:	49 83 e0 1f          	and    r8,0x1f
     8f3:	4c 01 c6             	add    rsi,r8
     8f6:	48 83 c6 35          	add    rsi,0x35
     8fa:	48 8b 97 b8 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1b8]
     901:	48 89 d1             	mov    rcx,rdx
     904:	48 c1 e9 11          	shr    rcx,0x11
     908:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     90f:	48 01 ce             	add    rsi,rcx
     912:	49 89 d0             	mov    r8,rdx
     915:	49 c1 e8 05          	shr    r8,0x5
     919:	49 83 e0 1f          	and    r8,0x1f
     91d:	4c 01 c6             	add    rsi,r8
     920:	48 83 c6 36          	add    rsi,0x36
     924:	48 8b 97 c0 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1c0]
     92b:	48 89 d1             	mov    rcx,rdx
     92e:	48 c1 e9 11          	shr    rcx,0x11
     932:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     939:	48 01 ce             	add    rsi,rcx
     93c:	49 89 d0             	mov    r8,rdx
     93f:	49 c1 e8 05          	shr    r8,0x5
     943:	49 83 e0 1f          	and    r8,0x1f
     947:	4c 01 c6             	add    rsi,r8
     94a:	48 83 c6 37          	add    rsi,0x37
     94e:	48 8b 97 c8 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1c8]
     955:	48 89 d1             	mov    rcx,rdx
     958:	48 c1 e9 11          	shr    rcx,0x11
     95c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     963:	48 01 ce             	add    rsi,rcx
     966:	49 89 d0             	mov    r8,rdx
     969:	49 c1 e8 05          	shr    r8,0x5
     96d:	49 83 e0 1f          	and    r8,0x1f
     971:	4c 01 c6             	add    rsi,r8
     974:	48 83 c6 38          	add    rsi,0x38
     978:	48 8b 97 d0 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1d0]
     97f:	48 89 d1             	mov    rcx,rdx
     982:	48 c1 e9 11          	shr    rcx,0x11
     986:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     98d:	48 01 ce             	add    rsi,rcx
     990:	49 89 d0             	mov    r8,rdx
     993:	49 c1 e8 05          	shr    r8,0x5
     997:	49 83 e0 1f          	and    r8,0x1f
     99b:	4c 01 c6             	add    rsi,r8
     99e:	48 83 c6 39          	add    rsi,0x39
     9a2:	48 8b 97 d8 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1d8]
     9a9:	48 89 d1             	mov    rcx,rdx
     9ac:	48 c1 e9 11          	shr    rcx,0x11
     9b0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     9b7:	48 01 ce             	add    rsi,rcx
     9ba:	49 89 d0             	mov    r8,rdx
     9bd:	49 c1 e8 05          	shr    r8,0x5
     9c1:	49 83 e0 1f          	and    r8,0x1f
     9c5:	4c 01 c6             	add    rsi,r8
     9c8:	48 83 c6 3a          	add    rsi,0x3a
     9cc:	48 8b 97 e0 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1e0]
     9d3:	48 89 d1             	mov    rcx,rdx
     9d6:	48 c1 e9 11          	shr    rcx,0x11
     9da:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     9e1:	48 01 ce             	add    rsi,rcx
     9e4:	49 89 d0             	mov    r8,rdx
     9e7:	49 c1 e8 05          	shr    r8,0x5
     9eb:	49 83 e0 1f          	and    r8,0x1f
     9ef:	4c 01 c6             	add    rsi,r8
     9f2:	48 83 c6 3b          	add    rsi,0x3b
     9f6:	48 8b 97 e8 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1e8]
     9fd:	48 89 d1             	mov    rcx,rdx
     a00:	48 c1 e9 11          	shr    rcx,0x11
     a04:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     a0b:	48 01 ce             	add    rsi,rcx
     a0e:	49 89 d0             	mov    r8,rdx
     a11:	49 c1 e8 05          	shr    r8,0x5
     a15:	49 83 e0 1f          	and    r8,0x1f
     a19:	4c 01 c6             	add    rsi,r8
     a1c:	48 83 c6 3c          	add    rsi,0x3c
     a20:	48 8b 97 f0 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1f0]
     a27:	48 89 d1             	mov    rcx,rdx
     a2a:	48 c1 e9 11          	shr    rcx,0x11
     a2e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     a35:	48 01 ce             	add    rsi,rcx
     a38:	49 89 d0             	mov    r8,rdx
     a3b:	49 c1 e8 05          	shr    r8,0x5
     a3f:	49 83 e0 1f          	and    r8,0x1f
     a43:	4c 01 c6             	add    rsi,r8
     a46:	48 83 c6 3d          	add    rsi,0x3d
     a4a:	48 8b 97 f8 01 00 00 	mov    rdx,QWORD PTR [rdi+0x1f8]
     a51:	48 89 d1             	mov    rcx,rdx
     a54:	48 c1 e9 11          	shr    rcx,0x11
     a58:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     a5f:	48 01 ce             	add    rsi,rcx
     a62:	49 89 d0             	mov    r8,rdx
     a65:	49 c1 e8 05          	shr    r8,0x5
     a69:	49 83 e0 1f          	and    r8,0x1f
     a6d:	4c 01 c6             	add    rsi,r8
     a70:	48 83 c6 3e          	add    rsi,0x3e
     a74:	48 8b 97 00 02 00 00 	mov    rdx,QWORD PTR [rdi+0x200]
     a7b:	48 89 d1             	mov    rcx,rdx
     a7e:	48 c1 e9 11          	shr    rcx,0x11
     a82:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     a89:	48 01 ce             	add    rsi,rcx
     a8c:	49 89 d0             	mov    r8,rdx
     a8f:	49 c1 e8 05          	shr    r8,0x5
     a93:	49 83 e0 1f          	and    r8,0x1f
     a97:	4c 01 c6             	add    rsi,r8
     a9a:	48 83 c6 3f          	add    rsi,0x3f
     a9e:	48 8b 97 08 02 00 00 	mov    rdx,QWORD PTR [rdi+0x208]
     aa5:	48 89 d1             	mov    rcx,rdx
     aa8:	48 c1 e9 11          	shr    rcx,0x11
     aac:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     ab3:	48 01 ce             	add    rsi,rcx
     ab6:	49 89 d0             	mov    r8,rdx
     ab9:	49 c1 e8 05          	shr    r8,0x5
     abd:	49 83 e0 1f          	and    r8,0x1f
     ac1:	4c 01 c6             	add    rsi,r8
     ac4:	48 83 c6 40          	add    rsi,0x40
     ac8:	48 8b 97 10 02 00 00 	mov    rdx,QWORD PTR [rdi+0x210]
     acf:	48 89 d1             	mov    rcx,rdx
     ad2:	48 c1 e9 11          	shr    rcx,0x11
     ad6:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     add:	48 01 ce             	add    rsi,rcx
     ae0:	49 89 d0             	mov    r8,rdx
     ae3:	49 c1 e8 05          	shr    r8,0x5
     ae7:	49 83 e0 1f          	and    r8,0x1f
     aeb:	4c 01 c6             	add    rsi,r8
     aee:	48 83 c6 41          	add    rsi,0x41
     af2:	48 8b 97 18 02 00 00 	mov    rdx,QWORD PTR [rdi+0x218]
     af9:	48 89 d1             	mov    rcx,rdx
     afc:	48 c1 e9 11          	shr    rcx,0x11
     b00:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     b07:	48 01 ce             	add    rsi,rcx
     b0a:	49 89 d0             	mov    r8,rdx
     b0d:	49 c1 e8 05          	shr    r8,0x5
     b11:	49 83 e0 1f          	and    r8,0x1f
     b15:	4c 01 c6             	add    rsi,r8
     b18:	48 83 c6 42          	add    rsi,0x42
     b1c:	48 8b 97 20 02 00 00 	mov    rdx,QWORD PTR [rdi+0x220]
     b23:	48 89 d1             	mov    rcx,rdx
     b26:	48 c1 e9 11          	shr    rcx,0x11
     b2a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     b31:	48 01 ce             	add    rsi,rcx
     b34:	49 89 d0             	mov    r8,rdx
     b37:	49 c1 e8 05          	shr    r8,0x5
     b3b:	49 83 e0 1f          	and    r8,0x1f
     b3f:	4c 01 c6             	add    rsi,r8
     b42:	48 83 c6 43          	add    rsi,0x43
     b46:	48 8b 97 28 02 00 00 	mov    rdx,QWORD PTR [rdi+0x228]
     b4d:	48 89 d1             	mov    rcx,rdx
     b50:	48 c1 e9 11          	shr    rcx,0x11
     b54:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     b5b:	48 01 ce             	add    rsi,rcx
     b5e:	49 89 d0             	mov    r8,rdx
     b61:	49 c1 e8 05          	shr    r8,0x5
     b65:	49 83 e0 1f          	and    r8,0x1f
     b69:	4c 01 c6             	add    rsi,r8
     b6c:	48 83 c6 44          	add    rsi,0x44
     b70:	48 8b 97 30 02 00 00 	mov    rdx,QWORD PTR [rdi+0x230]
     b77:	48 89 d1             	mov    rcx,rdx
     b7a:	48 c1 e9 11          	shr    rcx,0x11
     b7e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     b85:	48 01 ce             	add    rsi,rcx
     b88:	49 89 d0             	mov    r8,rdx
     b8b:	49 c1 e8 05          	shr    r8,0x5
     b8f:	49 83 e0 1f          	and    r8,0x1f
     b93:	4c 01 c6             	add    rsi,r8
     b96:	48 83 c6 45          	add    rsi,0x45
     b9a:	48 8b 97 38 02 00 00 	mov    rdx,QWORD PTR [rdi+0x238]
     ba1:	48 89 d1             	mov    rcx,rdx
     ba4:	48 c1 e9 11          	shr    rcx,0x11
     ba8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     baf:	48 01 ce             	add    rsi,rcx
     bb2:	49 89 d0             	mov    r8,rdx
     bb5:	49 c1 e8 05          	shr    r8,0x5
     bb9:	49 83 e0 1f          	and    r8,0x1f
     bbd:	4c 01 c6             	add    rsi,r8
     bc0:	48 83 c6 46          	add    rsi,0x46
     bc4:	48 8b 97 40 02 00 00 	mov    rdx,QWORD PTR [rdi+0x240]
     bcb:	48 89 d1             	mov    rcx,rdx
     bce:	48 c1 e9 11          	shr    rcx,0x11
     bd2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     bd9:	48 01 ce             	add    rsi,rcx
     bdc:	49 89 d0             	mov    r8,rdx
     bdf:	49 c1 e8 05          	shr    r8,0x5
     be3:	49 83 e0 1f          	and    r8,0x1f
     be7:	4c 01 c6             	add    rsi,r8
     bea:	48 83 c6 47          	add    rsi,0x47
     bee:	48 8b 97 48 02 00 00 	mov    rdx,QWORD PTR [rdi+0x248]
     bf5:	48 89 d1             	mov    rcx,rdx
     bf8:	48 c1 e9 11          	shr    rcx,0x11
     bfc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     c03:	48 01 ce             	add    rsi,rcx
     c06:	49 89 d0             	mov    r8,rdx
     c09:	49 c1 e8 05          	shr    r8,0x5
     c0d:	49 83 e0 1f          	and    r8,0x1f
     c11:	4c 01 c6             	add    rsi,r8
     c14:	48 83 c6 48          	add    rsi,0x48
     c18:	48 8b 97 50 02 00 00 	mov    rdx,QWORD PTR [rdi+0x250]
     c1f:	48 89 d1             	mov    rcx,rdx
     c22:	48 c1 e9 11          	shr    rcx,0x11
     c26:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     c2d:	48 01 ce             	add    rsi,rcx
     c30:	49 89 d0             	mov    r8,rdx
     c33:	49 c1 e8 05          	shr    r8,0x5
     c37:	49 83 e0 1f          	and    r8,0x1f
     c3b:	4c 01 c6             	add    rsi,r8
     c3e:	48 83 c6 49          	add    rsi,0x49
     c42:	48 8b 97 58 02 00 00 	mov    rdx,QWORD PTR [rdi+0x258]
     c49:	48 89 d1             	mov    rcx,rdx
     c4c:	48 c1 e9 11          	shr    rcx,0x11
     c50:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     c57:	48 01 ce             	add    rsi,rcx
     c5a:	49 89 d0             	mov    r8,rdx
     c5d:	49 c1 e8 05          	shr    r8,0x5
     c61:	49 83 e0 1f          	and    r8,0x1f
     c65:	4c 01 c6             	add    rsi,r8
     c68:	48 83 c6 4a          	add    rsi,0x4a
     c6c:	48 8b 97 60 02 00 00 	mov    rdx,QWORD PTR [rdi+0x260]
     c73:	48 89 d1             	mov    rcx,rdx
     c76:	48 c1 e9 11          	shr    rcx,0x11
     c7a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     c81:	48 01 ce             	add    rsi,rcx
     c84:	49 89 d0             	mov    r8,rdx
     c87:	49 c1 e8 05          	shr    r8,0x5
     c8b:	49 83 e0 1f          	and    r8,0x1f
     c8f:	4c 01 c6             	add    rsi,r8
     c92:	48 83 c6 4b          	add    rsi,0x4b
     c96:	48 8b 97 68 02 00 00 	mov    rdx,QWORD PTR [rdi+0x268]
     c9d:	48 89 d1             	mov    rcx,rdx
     ca0:	48 c1 e9 11          	shr    rcx,0x11
     ca4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     cab:	48 01 ce             	add    rsi,rcx
     cae:	49 89 d0             	mov    r8,rdx
     cb1:	49 c1 e8 05          	shr    r8,0x5
     cb5:	49 83 e0 1f          	and    r8,0x1f
     cb9:	4c 01 c6             	add    rsi,r8
     cbc:	48 83 c6 4c          	add    rsi,0x4c
     cc0:	48 8b 97 70 02 00 00 	mov    rdx,QWORD PTR [rdi+0x270]
     cc7:	48 89 d1             	mov    rcx,rdx
     cca:	48 c1 e9 11          	shr    rcx,0x11
     cce:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     cd5:	48 01 ce             	add    rsi,rcx
     cd8:	49 89 d0             	mov    r8,rdx
     cdb:	49 c1 e8 05          	shr    r8,0x5
     cdf:	49 83 e0 1f          	and    r8,0x1f
     ce3:	4c 01 c6             	add    rsi,r8
     ce6:	48 83 c6 4d          	add    rsi,0x4d
     cea:	48 8b 97 78 02 00 00 	mov    rdx,QWORD PTR [rdi+0x278]
     cf1:	48 89 d1             	mov    rcx,rdx
     cf4:	48 c1 e9 11          	shr    rcx,0x11
     cf8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     cff:	48 01 ce             	add    rsi,rcx
     d02:	49 89 d0             	mov    r8,rdx
     d05:	49 c1 e8 05          	shr    r8,0x5
     d09:	49 83 e0 1f          	and    r8,0x1f
     d0d:	4c 01 c6             	add    rsi,r8
     d10:	48 83 c6 4e          	add    rsi,0x4e
     d14:	48 8b 97 80 02 00 00 	mov    rdx,QWORD PTR [rdi+0x280]
     d1b:	48 89 d1             	mov    rcx,rdx
     d1e:	48 c1 e9 11          	shr    rcx,0x11
     d22:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     d29:	48 01 ce             	add    rsi,rcx
     d2c:	49 89 d0             	mov    r8,rdx
     d2f:	49 c1 e8 05          	shr    r8,0x5
     d33:	49 83 e0 1f          	and    r8,0x1f
     d37:	4c 01 c6             	add    rsi,r8
     d3a:	48 83 c6 4f          	add    rsi,0x4f
     d3e:	48 8b 97 88 02 00 00 	mov    rdx,QWORD PTR [rdi+0x288]
     d45:	48 89 d1             	mov    rcx,rdx
     d48:	48 c1 e9 11          	shr    rcx,0x11
     d4c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     d53:	48 01 ce             	add    rsi,rcx
     d56:	49 89 d0             	mov    r8,rdx
     d59:	49 c1 e8 05          	shr    r8,0x5
     d5d:	49 83 e0 1f          	and    r8,0x1f
     d61:	4c 01 c6             	add    rsi,r8
     d64:	48 83 c6 50          	add    rsi,0x50
     d68:	48 8b 97 90 02 00 00 	mov    rdx,QWORD PTR [rdi+0x290]
     d6f:	48 89 d1             	mov    rcx,rdx
     d72:	48 c1 e9 11          	shr    rcx,0x11
     d76:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     d7d:	48 01 ce             	add    rsi,rcx
     d80:	49 89 d0             	mov    r8,rdx
     d83:	49 c1 e8 05          	shr    r8,0x5
     d87:	49 83 e0 1f          	and    r8,0x1f
     d8b:	4c 01 c6             	add    rsi,r8
     d8e:	48 83 c6 51          	add    rsi,0x51
     d92:	48 8b 97 98 02 00 00 	mov    rdx,QWORD PTR [rdi+0x298]
     d99:	48 89 d1             	mov    rcx,rdx
     d9c:	48 c1 e9 11          	shr    rcx,0x11
     da0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     da7:	48 01 ce             	add    rsi,rcx
     daa:	49 89 d0             	mov    r8,rdx
     dad:	49 c1 e8 05          	shr    r8,0x5
     db1:	49 83 e0 1f          	and    r8,0x1f
     db5:	4c 01 c6             	add    rsi,r8
     db8:	48 83 c6 52          	add    rsi,0x52
     dbc:	48 8b 97 a0 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2a0]
     dc3:	48 89 d1             	mov    rcx,rdx
     dc6:	48 c1 e9 11          	shr    rcx,0x11
     dca:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     dd1:	48 01 ce             	add    rsi,rcx
     dd4:	49 89 d0             	mov    r8,rdx
     dd7:	49 c1 e8 05          	shr    r8,0x5
     ddb:	49 83 e0 1f          	and    r8,0x1f
     ddf:	4c 01 c6             	add    rsi,r8
     de2:	48 83 c6 53          	add    rsi,0x53
     de6:	48 8b 97 a8 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2a8]
     ded:	48 89 d1             	mov    rcx,rdx
     df0:	48 c1 e9 11          	shr    rcx,0x11
     df4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     dfb:	48 01 ce             	add    rsi,rcx
     dfe:	49 89 d0             	mov    r8,rdx
     e01:	49 c1 e8 05          	shr    r8,0x5
     e05:	49 83 e0 1f          	and    r8,0x1f
     e09:	4c 01 c6             	add    rsi,r8
     e0c:	48 83 c6 54          	add    rsi,0x54
     e10:	48 8b 97 b0 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2b0]
     e17:	48 89 d1             	mov    rcx,rdx
     e1a:	48 c1 e9 11          	shr    rcx,0x11
     e1e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     e25:	48 01 ce             	add    rsi,rcx
     e28:	49 89 d0             	mov    r8,rdx
     e2b:	49 c1 e8 05          	shr    r8,0x5
     e2f:	49 83 e0 1f          	and    r8,0x1f
     e33:	4c 01 c6             	add    rsi,r8
     e36:	48 83 c6 55          	add    rsi,0x55
     e3a:	48 8b 97 b8 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2b8]
     e41:	48 89 d1             	mov    rcx,rdx
     e44:	48 c1 e9 11          	shr    rcx,0x11
     e48:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     e4f:	48 01 ce             	add    rsi,rcx
     e52:	49 89 d0             	mov    r8,rdx
     e55:	49 c1 e8 05          	shr    r8,0x5
     e59:	49 83 e0 1f          	and    r8,0x1f
     e5d:	4c 01 c6             	add    rsi,r8
     e60:	48 83 c6 56          	add    rsi,0x56
     e64:	48 8b 97 c0 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2c0]
     e6b:	48 89 d1             	mov    rcx,rdx
     e6e:	48 c1 e9 11          	shr    rcx,0x11
     e72:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     e79:	48 01 ce             	add    rsi,rcx
     e7c:	49 89 d0             	mov    r8,rdx
     e7f:	49 c1 e8 05          	shr    r8,0x5
     e83:	49 83 e0 1f          	and    r8,0x1f
     e87:	4c 01 c6             	add    rsi,r8
     e8a:	48 83 c6 57          	add    rsi,0x57
     e8e:	48 8b 97 c8 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2c8]
     e95:	48 89 d1             	mov    rcx,rdx
     e98:	48 c1 e9 11          	shr    rcx,0x11
     e9c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     ea3:	48 01 ce             	add    rsi,rcx
     ea6:	49 89 d0             	mov    r8,rdx
     ea9:	49 c1 e8 05          	shr    r8,0x5
     ead:	49 83 e0 1f          	and    r8,0x1f
     eb1:	4c 01 c6             	add    rsi,r8
     eb4:	48 83 c6 58          	add    rsi,0x58
     eb8:	48 8b 97 d0 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2d0]
     ebf:	48 89 d1             	mov    rcx,rdx
     ec2:	48 c1 e9 11          	shr    rcx,0x11
     ec6:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     ecd:	48 01 ce             	add    rsi,rcx
     ed0:	49 89 d0             	mov    r8,rdx
     ed3:	49 c1 e8 05          	shr    r8,0x5
     ed7:	49 83 e0 1f          	and    r8,0x1f
     edb:	4c 01 c6             	add    rsi,r8
     ede:	48 83 c6 59          	add    rsi,0x59
     ee2:	48 8b 97 d8 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2d8]
     ee9:	48 89 d1             	mov    rcx,rdx
     eec:	48 c1 e9 11          	shr    rcx,0x11
     ef0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     ef7:	48 01 ce             	add    rsi,rcx
     efa:	49 89 d0             	mov    r8,rdx
     efd:	49 c1 e8 05          	shr    r8,0x5
     f01:	49 83 e0 1f          	and    r8,0x1f
     f05:	4c 01 c6             	add    rsi,r8
     f08:	48 83 c6 5a          	add    rsi,0x5a
     f0c:	48 8b 97 e0 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2e0]
     f13:	48 89 d1             	mov    rcx,rdx
     f16:	48 c1 e9 11          	shr    rcx,0x11
     f1a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     f21:	48 01 ce             	add    rsi,rcx
     f24:	49 89 d0             	mov    r8,rdx
     f27:	49 c1 e8 05          	shr    r8,0x5
     f2b:	49 83 e0 1f          	and    r8,0x1f
     f2f:	4c 01 c6             	add    rsi,r8
     f32:	48 83 c6 5b          	add    rsi,0x5b
     f36:	48 8b 97 e8 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2e8]
     f3d:	48 89 d1             	mov    rcx,rdx
     f40:	48 c1 e9 11          	shr    rcx,0x11
     f44:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     f4b:	48 01 ce             	add    rsi,rcx
     f4e:	49 89 d0             	mov    r8,rdx
     f51:	49 c1 e8 05          	shr    r8,0x5
     f55:	49 83 e0 1f          	and    r8,0x1f
     f59:	4c 01 c6             	add    rsi,r8
     f5c:	48 83 c6 5c          	add    rsi,0x5c
     f60:	48 8b 97 f0 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2f0]
     f67:	48 89 d1             	mov    rcx,rdx
     f6a:	48 c1 e9 11          	shr    rcx,0x11
     f6e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     f75:	48 01 ce             	add    rsi,rcx
     f78:	49 89 d0             	mov    r8,rdx
     f7b:	49 c1 e8 05          	shr    r8,0x5
     f7f:	49 83 e0 1f          	and    r8,0x1f
     f83:	4c 01 c6             	add    rsi,r8
     f86:	48 83 c6 5d          	add    rsi,0x5d
     f8a:	48 8b 97 f8 02 00 00 	mov    rdx,QWORD PTR [rdi+0x2f8]
     f91:	48 89 d1             	mov    rcx,rdx
     f94:	48 c1 e9 11          	shr    rcx,0x11
     f98:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     f9f:	48 01 ce             	add    rsi,rcx
     fa2:	49 89 d0             	mov    r8,rdx
     fa5:	49 c1 e8 05          	shr    r8,0x5
     fa9:	49 83 e0 1f          	and    r8,0x1f
     fad:	4c 01 c6             	add    rsi,r8
     fb0:	48 83 c6 5e          	add    rsi,0x5e
     fb4:	48 8b 97 00 03 00 00 	mov    rdx,QWORD PTR [rdi+0x300]
     fbb:	48 89 d1             	mov    rcx,rdx
     fbe:	48 c1 e9 11          	shr    rcx,0x11
     fc2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     fc9:	48 01 ce             	add    rsi,rcx
     fcc:	49 89 d0             	mov    r8,rdx
     fcf:	49 c1 e8 05          	shr    r8,0x5
     fd3:	49 83 e0 1f          	and    r8,0x1f
     fd7:	4c 01 c6             	add    rsi,r8
     fda:	48 83 c6 5f          	add    rsi,0x5f
     fde:	48 8b 97 08 03 00 00 	mov    rdx,QWORD PTR [rdi+0x308]
     fe5:	48 89 d1             	mov    rcx,rdx
     fe8:	48 c1 e9 11          	shr    rcx,0x11
     fec:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
     ff3:	48 01 ce             	add    rsi,rcx
     ff6:	49 89 d0             	mov    r8,rdx
     ff9:	49 c1 e8 05          	shr    r8,0x5
     ffd:	49 83 e0 1f          	and    r8,0x1f
    1001:	4c 01 c6             	add    rsi,r8
    1004:	48 83 c6 60          	add    rsi,0x60
    1008:	48 8b 97 10 03 00 00 	mov    rdx,QWORD PTR [rdi+0x310]
    100f:	48 89 d1             	mov    rcx,rdx
    1012:	48 c1 e9 11          	shr    rcx,0x11
    1016:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    101d:	48 01 ce             	add    rsi,rcx
    1020:	49 89 d0             	mov    r8,rdx
    1023:	49 c1 e8 05          	shr    r8,0x5
    1027:	49 83 e0 1f          	and    r8,0x1f
    102b:	4c 01 c6             	add    rsi,r8
    102e:	48 83 c6 61          	add    rsi,0x61
    1032:	48 8b 97 18 03 00 00 	mov    rdx,QWORD PTR [rdi+0x318]
    1039:	48 89 d1             	mov    rcx,rdx
    103c:	48 c1 e9 11          	shr    rcx,0x11
    1040:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1047:	48 01 ce             	add    rsi,rcx
    104a:	49 89 d0             	mov    r8,rdx
    104d:	49 c1 e8 05          	shr    r8,0x5
    1051:	49 83 e0 1f          	and    r8,0x1f
    1055:	4c 01 c6             	add    rsi,r8
    1058:	48 83 c6 62          	add    rsi,0x62
    105c:	48 8b 97 20 03 00 00 	mov    rdx,QWORD PTR [rdi+0x320]
    1063:	48 89 d1             	mov    rcx,rdx
    1066:	48 c1 e9 11          	shr    rcx,0x11
    106a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1071:	48 01 ce             	add    rsi,rcx
    1074:	49 89 d0             	mov    r8,rdx
    1077:	49 c1 e8 05          	shr    r8,0x5
    107b:	49 83 e0 1f          	and    r8,0x1f
    107f:	4c 01 c6             	add    rsi,r8
    1082:	48 83 c6 63          	add    rsi,0x63
    1086:	48 8b 97 28 03 00 00 	mov    rdx,QWORD PTR [rdi+0x328]
    108d:	48 89 d1             	mov    rcx,rdx
    1090:	48 c1 e9 11          	shr    rcx,0x11
    1094:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    109b:	48 01 ce             	add    rsi,rcx
    109e:	49 89 d0             	mov    r8,rdx
    10a1:	49 c1 e8 05          	shr    r8,0x5
    10a5:	49 83 e0 1f          	and    r8,0x1f
    10a9:	4c 01 c6             	add    rsi,r8
    10ac:	48 83 c6 64          	add    rsi,0x64
    10b0:	48 8b 97 30 03 00 00 	mov    rdx,QWORD PTR [rdi+0x330]
    10b7:	48 89 d1             	mov    rcx,rdx
    10ba:	48 c1 e9 11          	shr    rcx,0x11
    10be:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    10c5:	48 01 ce             	add    rsi,rcx
    10c8:	49 89 d0             	mov    r8,rdx
    10cb:	49 c1 e8 05          	shr    r8,0x5
    10cf:	49 83 e0 1f          	and    r8,0x1f
    10d3:	4c 01 c6             	add    rsi,r8
    10d6:	48 83 c6 65          	add    rsi,0x65
    10da:	48 8b 97 38 03 00 00 	mov    rdx,QWORD PTR [rdi+0x338]
    10e1:	48 89 d1             	mov    rcx,rdx
    10e4:	48 c1 e9 11          	shr    rcx,0x11
    10e8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    10ef:	48 01 ce             	add    rsi,rcx
    10f2:	49 89 d0             	mov    r8,rdx
    10f5:	49 c1 e8 05          	shr    r8,0x5
    10f9:	49 83 e0 1f          	and    r8,0x1f
    10fd:	4c 01 c6             	add    rsi,r8
    1100:	48 83 c6 66          	add    rsi,0x66
    1104:	48 8b 97 40 03 00 00 	mov    rdx,QWORD PTR [rdi+0x340]
    110b:	48 89 d1             	mov    rcx,rdx
    110e:	48 c1 e9 11          	shr    rcx,0x11
    1112:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1119:	48 01 ce             	add    rsi,rcx
    111c:	49 89 d0             	mov    r8,rdx
    111f:	49 c1 e8 05          	shr    r8,0x5
    1123:	49 83 e0 1f          	and    r8,0x1f
    1127:	4c 01 c6             	add    rsi,r8
    112a:	48 83 c6 67          	add    rsi,0x67
    112e:	48 8b 97 48 03 00 00 	mov    rdx,QWORD PTR [rdi+0x348]
    1135:	48 89 d1             	mov    rcx,rdx
    1138:	48 c1 e9 11          	shr    rcx,0x11
    113c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1143:	48 01 ce             	add    rsi,rcx
    1146:	49 89 d0             	mov    r8,rdx
    1149:	49 c1 e8 05          	shr    r8,0x5
    114d:	49 83 e0 1f          	and    r8,0x1f
    1151:	4c 01 c6             	add    rsi,r8
    1154:	48 83 c6 68          	add    rsi,0x68
    1158:	48 8b 97 50 03 00 00 	mov    rdx,QWORD PTR [rdi+0x350]
    115f:	48 89 d1             	mov    rcx,rdx
    1162:	48 c1 e9 11          	shr    rcx,0x11
    1166:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    116d:	48 01 ce             	add    rsi,rcx
    1170:	49 89 d0             	mov    r8,rdx
    1173:	49 c1 e8 05          	shr    r8,0x5
    1177:	49 83 e0 1f          	and    r8,0x1f
    117b:	4c 01 c6             	add    rsi,r8
    117e:	48 83 c6 69          	add    rsi,0x69
    1182:	48 8b 97 58 03 00 00 	mov    rdx,QWORD PTR [rdi+0x358]
    1189:	48 89 d1             	mov    rcx,rdx
    118c:	48 c1 e9 11          	shr    rcx,0x11
    1190:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1197:	48 01 ce             	add    rsi,rcx
    119a:	49 89 d0             	mov    r8,rdx
    119d:	49 c1 e8 05          	shr    r8,0x5
    11a1:	49 83 e0 1f          	and    r8,0x1f
    11a5:	4c 01 c6             	add    rsi,r8
    11a8:	48 83 c6 6a          	add    rsi,0x6a
    11ac:	48 8b 97 60 03 00 00 	mov    rdx,QWORD PTR [rdi+0x360]
    11b3:	48 89 d1             	mov    rcx,rdx
    11b6:	48 c1 e9 11          	shr    rcx,0x11
    11ba:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    11c1:	48 01 ce             	add    rsi,rcx
    11c4:	49 89 d0             	mov    r8,rdx
    11c7:	49 c1 e8 05          	shr    r8,0x5
    11cb:	49 83 e0 1f          	and    r8,0x1f
    11cf:	4c 01 c6             	add    rsi,r8
    11d2:	48 83 c6 6b          	add    rsi,0x6b
    11d6:	48 8b 97 68 03 00 00 	mov    rdx,QWORD PTR [rdi+0x368]
    11dd:	48 89 d1             	mov    rcx,rdx
    11e0:	48 c1 e9 11          	shr    rcx,0x11
    11e4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    11eb:	48 01 ce             	add    rsi,rcx
    11ee:	49 89 d0             	mov    r8,rdx
    11f1:	49 c1 e8 05          	shr    r8,0x5
    11f5:	49 83 e0 1f          	and    r8,0x1f
    11f9:	4c 01 c6             	add    rsi,r8
    11fc:	48 83 c6 6c          	add    rsi,0x6c
    1200:	48 8b 97 70 03 00 00 	mov    rdx,QWORD PTR [rdi+0x370]
    1207:	48 89 d1             	mov    rcx,rdx
    120a:	48 c1 e9 11          	shr    rcx,0x11
    120e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1215:	48 01 ce             	add    rsi,rcx
    1218:	49 89 d0             	mov    r8,rdx
    121b:	49 c1 e8 05          	shr    r8,0x5
    121f:	49 83 e0 1f          	and    r8,0x1f
    1223:	4c 01 c6             	add    rsi,r8
    1226:	48 83 c6 6d          	add    rsi,0x6d
    122a:	48 8b 97 78 03 00 00 	mov    rdx,QWORD PTR [rdi+0x378]
    1231:	48 89 d1             	mov    rcx,rdx
    1234:	48 c1 e9 11          	shr    rcx,0x11
    1238:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    123f:	48 01 ce             	add    rsi,rcx
    1242:	49 89 d0             	mov    r8,rdx
    1245:	49 c1 e8 05          	shr    r8,0x5
    1249:	49 83 e0 1f          	and    r8,0x1f
    124d:	4c 01 c6             	add    rsi,r8
    1250:	48 83 c6 6e          	add    rsi,0x6e
    1254:	48 8b 97 80 03 00 00 	mov    rdx,QWORD PTR [rdi+0x380]
    125b:	48 89 d1             	mov    rcx,rdx
    125e:	48 c1 e9 11          	shr    rcx,0x11
    1262:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1269:	48 01 ce             	add    rsi,rcx
    126c:	49 89 d0             	mov    r8,rdx
    126f:	49 c1 e8 05          	shr    r8,0x5
    1273:	49 83 e0 1f          	and    r8,0x1f
    1277:	4c 01 c6             	add    rsi,r8
    127a:	48 83 c6 6f          	add    rsi,0x6f
    127e:	48 8b 97 88 03 00 00 	mov    rdx,QWORD PTR [rdi+0x388]
    1285:	48 89 d1             	mov    rcx,rdx
    1288:	48 c1 e9 11          	shr    rcx,0x11
    128c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1293:	48 01 ce             	add    rsi,rcx
    1296:	49 89 d0             	mov    r8,rdx
    1299:	49 c1 e8 05          	shr    r8,0x5
    129d:	49 83 e0 1f          	and    r8,0x1f
    12a1:	4c 01 c6             	add    rsi,r8
    12a4:	48 83 c6 70          	add    rsi,0x70
    12a8:	48 8b 97 90 03 00 00 	mov    rdx,QWORD PTR [rdi+0x390]
    12af:	48 89 d1             	mov    rcx,rdx
    12b2:	48 c1 e9 11          	shr    rcx,0x11
    12b6:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    12bd:	48 01 ce             	add    rsi,rcx
    12c0:	49 89 d0             	mov    r8,rdx
    12c3:	49 c1 e8 05          	shr    r8,0x5
    12c7:	49 83 e0 1f          	and    r8,0x1f
    12cb:	4c 01 c6             	add    rsi,r8
    12ce:	48 83 c6 71          	add    rsi,0x71
    12d2:	48 8b 97 98 03 00 00 	mov    rdx,QWORD PTR [rdi+0x398]
    12d9:	48 89 d1             	mov    rcx,rdx
    12dc:	48 c1 e9 11          	shr    rcx,0x11
    12e0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    12e7:	48 01 ce             	add    rsi,rcx
    12ea:	49 89 d0             	mov    r8,rdx
    12ed:	49 c1 e8 05          	shr    r8,0x5
    12f1:	49 83 e0 1f          	and    r8,0x1f
    12f5:	4c 01 c6             	add    rsi,r8
    12f8:	48 83 c6 72          	add    rsi,0x72
    12fc:	48 8b 97 a0 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3a0]
    1303:	48 89 d1             	mov    rcx,rdx
    1306:	48 c1 e9 11          	shr    rcx,0x11
    130a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1311:	48 01 ce             	add    rsi,rcx
    1314:	49 89 d0             	mov    r8,rdx
    1317:	49 c1 e8 05          	shr    r8,0x5
    131b:	49 83 e0 1f          	and    r8,0x1f
    131f:	4c 01 c6             	add    rsi,r8
    1322:	48 83 c6 73          	add    rsi,0x73
    1326:	48 8b 97 a8 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3a8]
    132d:	48 89 d1             	mov    rcx,rdx
    1330:	48 c1 e9 11          	shr    rcx,0x11
    1334:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    133b:	48 01 ce             	add    rsi,rcx
    133e:	49 89 d0             	mov    r8,rdx
    1341:	49 c1 e8 05          	shr    r8,0x5
    1345:	49 83 e0 1f          	and    r8,0x1f
    1349:	4c 01 c6             	add    rsi,r8
    134c:	48 83 c6 74          	add    rsi,0x74
    1350:	48 8b 97 b0 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3b0]
    1357:	48 89 d1             	mov    rcx,rdx
    135a:	48 c1 e9 11          	shr    rcx,0x11
    135e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1365:	48 01 ce             	add    rsi,rcx
    1368:	49 89 d0             	mov    r8,rdx
    136b:	49 c1 e8 05          	shr    r8,0x5
    136f:	49 83 e0 1f          	and    r8,0x1f
    1373:	4c 01 c6             	add    rsi,r8
    1376:	48 83 c6 75          	add    rsi,0x75
    137a:	48 8b 97 b8 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3b8]
    1381:	48 89 d1             	mov    rcx,rdx
    1384:	48 c1 e9 11          	shr    rcx,0x11
    1388:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    138f:	48 01 ce             	add    rsi,rcx
    1392:	49 89 d0             	mov    r8,rdx
    1395:	49 c1 e8 05          	shr    r8,0x5
    1399:	49 83 e0 1f          	and    r8,0x1f
    139d:	4c 01 c6             	add    rsi,r8
    13a0:	48 83 c6 76          	add    rsi,0x76
    13a4:	48 8b 97 c0 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3c0]
    13ab:	48 89 d1             	mov    rcx,rdx
    13ae:	48 c1 e9 11          	shr    rcx,0x11
    13b2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    13b9:	48 01 ce             	add    rsi,rcx
    13bc:	49 89 d0             	mov    r8,rdx
    13bf:	49 c1 e8 05          	shr    r8,0x5
    13c3:	49 83 e0 1f          	and    r8,0x1f
    13c7:	4c 01 c6             	add    rsi,r8
    13ca:	48 83 c6 77          	add    rsi,0x77
    13ce:	48 8b 97 c8 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3c8]
    13d5:	48 89 d1             	mov    rcx,rdx
    13d8:	48 c1 e9 11          	shr    rcx,0x11
    13dc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    13e3:	48 01 ce             	add    rsi,rcx
    13e6:	49 89 d0             	mov    r8,rdx
    13e9:	49 c1 e8 05          	shr    r8,0x5
    13ed:	49 83 e0 1f          	and    r8,0x1f
    13f1:	4c 01 c6             	add    rsi,r8
    13f4:	48 83 c6 78          	add    rsi,0x78
    13f8:	48 8b 97 d0 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3d0]
    13ff:	48 89 d1             	mov    rcx,rdx
    1402:	48 c1 e9 11          	shr    rcx,0x11
    1406:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    140d:	48 01 ce             	add    rsi,rcx
    1410:	49 89 d0             	mov    r8,rdx
    1413:	49 c1 e8 05          	shr    r8,0x5
    1417:	49 83 e0 1f          	and    r8,0x1f
    141b:	4c 01 c6             	add    rsi,r8
    141e:	48 83 c6 79          	add    rsi,0x79
    1422:	48 8b 97 d8 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3d8]
    1429:	48 89 d1             	mov    rcx,rdx
    142c:	48 c1 e9 11          	shr    rcx,0x11
    1430:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1437:	48 01 ce             	add    rsi,rcx
    143a:	49 89 d0             	mov    r8,rdx
    143d:	49 c1 e8 05          	shr    r8,0x5
    1441:	49 83 e0 1f          	and    r8,0x1f
    1445:	4c 01 c6             	add    rsi,r8
    1448:	48 83 c6 7a          	add    rsi,0x7a
    144c:	48 8b 97 e0 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3e0]
    1453:	48 89 d1             	mov    rcx,rdx
    1456:	48 c1 e9 11          	shr    rcx,0x11
    145a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1461:	48 01 ce             	add    rsi,rcx
    1464:	49 89 d0             	mov    r8,rdx
    1467:	49 c1 e8 05          	shr    r8,0x5
    146b:	49 83 e0 1f          	and    r8,0x1f
    146f:	4c 01 c6             	add    rsi,r8
    1472:	48 83 c6 7b          	add    rsi,0x7b
    1476:	48 8b 97 e8 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3e8]
    147d:	48 89 d1             	mov    rcx,rdx
    1480:	48 c1 e9 11          	shr    rcx,0x11
    1484:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    148b:	48 01 ce             	add    rsi,rcx
    148e:	49 89 d0             	mov    r8,rdx
    1491:	49 c1 e8 05          	shr    r8,0x5
    1495:	49 83 e0 1f          	and    r8,0x1f
    1499:	4c 01 c6             	add    rsi,r8
    149c:	48 83 c6 7c          	add    rsi,0x7c
    14a0:	48 8b 97 f0 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3f0]
    14a7:	48 89 d1             	mov    rcx,rdx
    14aa:	48 c1 e9 11          	shr    rcx,0x11
    14ae:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    14b5:	48 01 ce             	add    rsi,rcx
    14b8:	49 89 d0             	mov    r8,rdx
    14bb:	49 c1 e8 05          	shr    r8,0x5
    14bf:	49 83 e0 1f          	and    r8,0x1f
    14c3:	4c 01 c6             	add    rsi,r8
    14c6:	48 83 c6 7d          	add    rsi,0x7d
    14ca:	48 8b 97 f8 03 00 00 	mov    rdx,QWORD PTR [rdi+0x3f8]
    14d1:	48 89 d1             	mov    rcx,rdx
    14d4:	48 c1 e9 11          	shr    rcx,0x11
    14d8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    14df:	48 01 ce             	add    rsi,rcx
    14e2:	49 89 d0             	mov    r8,rdx
    14e5:	49 c1 e8 05          	shr    r8,0x5
    14e9:	49 83 e0 1f          	and    r8,0x1f
    14ed:	4c 01 c6             	add    rsi,r8
    14f0:	48 83 c6 7e          	add    rsi,0x7e
    14f4:	48 8b 97 00 04 00 00 	mov    rdx,QWORD PTR [rdi+0x400]
    14fb:	48 89 d1             	mov    rcx,rdx
    14fe:	48 c1 e9 11          	shr    rcx,0x11
    1502:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1509:	48 01 ce             	add    rsi,rcx
    150c:	49 89 d0             	mov    r8,rdx
    150f:	49 c1 e8 05          	shr    r8,0x5
    1513:	49 83 e0 1f          	and    r8,0x1f
    1517:	4c 01 c6             	add    rsi,r8
    151a:	48 83 c6 7f          	add    rsi,0x7f
    151e:	48 8b 97 08 04 00 00 	mov    rdx,QWORD PTR [rdi+0x408]
    1525:	48 89 d1             	mov    rcx,rdx
    1528:	48 c1 e9 11          	shr    rcx,0x11
    152c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1533:	48 01 ce             	add    rsi,rcx
    1536:	49 89 d0             	mov    r8,rdx
    1539:	49 c1 e8 05          	shr    r8,0x5
    153d:	49 83 e0 1f          	and    r8,0x1f
    1541:	4c 01 c6             	add    rsi,r8
    1544:	48 81 c6 80 00 00 00 	add    rsi,0x80
    154b:	48 8b 97 10 04 00 00 	mov    rdx,QWORD PTR [rdi+0x410]
    1552:	48 89 d1             	mov    rcx,rdx
    1555:	48 c1 e9 11          	shr    rcx,0x11
    1559:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1560:	48 01 ce             	add    rsi,rcx
    1563:	49 89 d0             	mov    r8,rdx
    1566:	49 c1 e8 05          	shr    r8,0x5
    156a:	49 83 e0 1f          	and    r8,0x1f
    156e:	4c 01 c6             	add    rsi,r8
    1571:	48 81 c6 81 00 00 00 	add    rsi,0x81
    1578:	48 8b 97 18 04 00 00 	mov    rdx,QWORD PTR [rdi+0x418]
    157f:	48 89 d1             	mov    rcx,rdx
    1582:	48 c1 e9 11          	shr    rcx,0x11
    1586:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    158d:	48 01 ce             	add    rsi,rcx
    1590:	49 89 d0             	mov    r8,rdx
    1593:	49 c1 e8 05          	shr    r8,0x5
    1597:	49 83 e0 1f          	and    r8,0x1f
    159b:	4c 01 c6             	add    rsi,r8
    159e:	48 81 c6 82 00 00 00 	add    rsi,0x82
    15a5:	48 8b 97 20 04 00 00 	mov    rdx,QWORD PTR [rdi+0x420]
    15ac:	48 89 d1             	mov    rcx,rdx
    15af:	48 c1 e9 11          	shr    rcx,0x11
    15b3:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    15ba:	48 01 ce             	add    rsi,rcx
    15bd:	49 89 d0             	mov    r8,rdx
    15c0:	49 c1 e8 05          	shr    r8,0x5
    15c4:	49 83 e0 1f          	and    r8,0x1f
    15c8:	4c 01 c6             	add    rsi,r8
    15cb:	48 81 c6 83 00 00 00 	add    rsi,0x83
    15d2:	48 8b 97 28 04 00 00 	mov    rdx,QWORD PTR [rdi+0x428]
    15d9:	48 89 d1             	mov    rcx,rdx
    15dc:	48 c1 e9 11          	shr    rcx,0x11
    15e0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    15e7:	48 01 ce             	add    rsi,rcx
    15ea:	49 89 d0             	mov    r8,rdx
    15ed:	49 c1 e8 05          	shr    r8,0x5
    15f1:	49 83 e0 1f          	and    r8,0x1f
    15f5:	4c 01 c6             	add    rsi,r8
    15f8:	48 81 c6 84 00 00 00 	add    rsi,0x84
    15ff:	48 8b 97 30 04 00 00 	mov    rdx,QWORD PTR [rdi+0x430]
    1606:	48 89 d1             	mov    rcx,rdx
    1609:	48 c1 e9 11          	shr    rcx,0x11
    160d:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1614:	48 01 ce             	add    rsi,rcx
    1617:	49 89 d0             	mov    r8,rdx
    161a:	49 c1 e8 05          	shr    r8,0x5
    161e:	49 83 e0 1f          	and    r8,0x1f
    1622:	4c 01 c6             	add    rsi,r8
    1625:	48 81 c6 85 00 00 00 	add    rsi,0x85
    162c:	48 8b 97 38 04 00 00 	mov    rdx,QWORD PTR [rdi+0x438]
    1633:	48 89 d1             	mov    rcx,rdx
    1636:	48 c1 e9 11          	shr    rcx,0x11
    163a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1641:	48 01 ce             	add    rsi,rcx
    1644:	49 89 d0             	mov    r8,rdx
    1647:	49 c1 e8 05          	shr    r8,0x5
    164b:	49 83 e0 1f          	and    r8,0x1f
    164f:	4c 01 c6             	add    rsi,r8
    1652:	48 81 c6 86 00 00 00 	add    rsi,0x86
    1659:	48 8b 97 40 04 00 00 	mov    rdx,QWORD PTR [rdi+0x440]
    1660:	48 89 d1             	mov    rcx,rdx
    1663:	48 c1 e9 11          	shr    rcx,0x11
    1667:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    166e:	48 01 ce             	add    rsi,rcx
    1671:	49 89 d0             	mov    r8,rdx
    1674:	49 c1 e8 05          	shr    r8,0x5
    1678:	49 83 e0 1f          	and    r8,0x1f
    167c:	4c 01 c6             	add    rsi,r8
    167f:	48 81 c6 87 00 00 00 	add    rsi,0x87
    1686:	48 8b 97 48 04 00 00 	mov    rdx,QWORD PTR [rdi+0x448]
    168d:	48 89 d1             	mov    rcx,rdx
    1690:	48 c1 e9 11          	shr    rcx,0x11
    1694:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    169b:	48 01 ce             	add    rsi,rcx
    169e:	49 89 d0             	mov    r8,rdx
    16a1:	49 c1 e8 05          	shr    r8,0x5
    16a5:	49 83 e0 1f          	and    r8,0x1f
    16a9:	4c 01 c6             	add    rsi,r8
    16ac:	48 81 c6 88 00 00 00 	add    rsi,0x88
    16b3:	48 8b 97 50 04 00 00 	mov    rdx,QWORD PTR [rdi+0x450]
    16ba:	48 89 d1             	mov    rcx,rdx
    16bd:	48 c1 e9 11          	shr    rcx,0x11
    16c1:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    16c8:	48 01 ce             	add    rsi,rcx
    16cb:	49 89 d0             	mov    r8,rdx
    16ce:	49 c1 e8 05          	shr    r8,0x5
    16d2:	49 83 e0 1f          	and    r8,0x1f
    16d6:	4c 01 c6             	add    rsi,r8
    16d9:	48 81 c6 89 00 00 00 	add    rsi,0x89
    16e0:	48 8b 97 58 04 00 00 	mov    rdx,QWORD PTR [rdi+0x458]
    16e7:	48 89 d1             	mov    rcx,rdx
    16ea:	48 c1 e9 11          	shr    rcx,0x11
    16ee:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    16f5:	48 01 ce             	add    rsi,rcx
    16f8:	49 89 d0             	mov    r8,rdx
    16fb:	49 c1 e8 05          	shr    r8,0x5
    16ff:	49 83 e0 1f          	and    r8,0x1f
    1703:	4c 01 c6             	add    rsi,r8
    1706:	48 81 c6 8a 00 00 00 	add    rsi,0x8a
    170d:	48 8b 97 60 04 00 00 	mov    rdx,QWORD PTR [rdi+0x460]
    1714:	48 89 d1             	mov    rcx,rdx
    1717:	48 c1 e9 11          	shr    rcx,0x11
    171b:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1722:	48 01 ce             	add    rsi,rcx
    1725:	49 89 d0             	mov    r8,rdx
    1728:	49 c1 e8 05          	shr    r8,0x5
    172c:	49 83 e0 1f          	and    r8,0x1f
    1730:	4c 01 c6             	add    rsi,r8
    1733:	48 81 c6 8b 00 00 00 	add    rsi,0x8b
    173a:	48 8b 97 68 04 00 00 	mov    rdx,QWORD PTR [rdi+0x468]
    1741:	48 89 d1             	mov    rcx,rdx
    1744:	48 c1 e9 11          	shr    rcx,0x11
    1748:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    174f:	48 01 ce             	add    rsi,rcx
    1752:	49 89 d0             	mov    r8,rdx
    1755:	49 c1 e8 05          	shr    r8,0x5
    1759:	49 83 e0 1f          	and    r8,0x1f
    175d:	4c 01 c6             	add    rsi,r8
    1760:	48 81 c6 8c 00 00 00 	add    rsi,0x8c
    1767:	48 8b 97 70 04 00 00 	mov    rdx,QWORD PTR [rdi+0x470]
    176e:	48 89 d1             	mov    rcx,rdx
    1771:	48 c1 e9 11          	shr    rcx,0x11
    1775:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    177c:	48 01 ce             	add    rsi,rcx
    177f:	49 89 d0             	mov    r8,rdx
    1782:	49 c1 e8 05          	shr    r8,0x5
    1786:	49 83 e0 1f          	and    r8,0x1f
    178a:	4c 01 c6             	add    rsi,r8
    178d:	48 81 c6 8d 00 00 00 	add    rsi,0x8d
    1794:	48 8b 97 78 04 00 00 	mov    rdx,QWORD PTR [rdi+0x478]
    179b:	48 89 d1             	mov    rcx,rdx
    179e:	48 c1 e9 11          	shr    rcx,0x11
    17a2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    17a9:	48 01 ce             	add    rsi,rcx
    17ac:	49 89 d0             	mov    r8,rdx
    17af:	49 c1 e8 05          	shr    r8,0x5
    17b3:	49 83 e0 1f          	and    r8,0x1f
    17b7:	4c 01 c6             	add    rsi,r8
    17ba:	48 81 c6 8e 00 00 00 	add    rsi,0x8e
    17c1:	48 8b 97 80 04 00 00 	mov    rdx,QWORD PTR [rdi+0x480]
    17c8:	48 89 d1             	mov    rcx,rdx
    17cb:	48 c1 e9 11          	shr    rcx,0x11
    17cf:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    17d6:	48 01 ce             	add    rsi,rcx
    17d9:	49 89 d0             	mov    r8,rdx
    17dc:	49 c1 e8 05          	shr    r8,0x5
    17e0:	49 83 e0 1f          	and    r8,0x1f
    17e4:	4c 01 c6             	add    rsi,r8
    17e7:	48 81 c6 8f 00 00 00 	add    rsi,0x8f
    17ee:	48 8b 97 88 04 00 00 	mov    rdx,QWORD PTR [rdi+0x488]
    17f5:	48 89 d1             	mov    rcx,rdx
    17f8:	48 c1 e9 11          	shr    rcx,0x11
    17fc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1803:	48 01 ce             	add    rsi,rcx
    1806:	49 89 d0             	mov    r8,rdx
    1809:	49 c1 e8 05          	shr    r8,0x5
    180d:	49 83 e0 1f          	and    r8,0x1f
    1811:	4c 01 c6             	add    rsi,r8
    1814:	48 81 c6 90 00 00 00 	add    rsi,0x90
    181b:	48 8b 97 90 04 00 00 	mov    rdx,QWORD PTR [rdi+0x490]
    1822:	48 89 d1             	mov    rcx,rdx
    1825:	48 c1 e9 11          	shr    rcx,0x11
    1829:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1830:	48 01 ce             	add    rsi,rcx
    1833:	49 89 d0             	mov    r8,rdx
    1836:	49 c1 e8 05          	shr    r8,0x5
    183a:	49 83 e0 1f          	and    r8,0x1f
    183e:	4c 01 c6             	add    rsi,r8
    1841:	48 81 c6 91 00 00 00 	add    rsi,0x91
    1848:	48 8b 97 98 04 00 00 	mov    rdx,QWORD PTR [rdi+0x498]
    184f:	48 89 d1             	mov    rcx,rdx
    1852:	48 c1 e9 11          	shr    rcx,0x11
    1856:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    185d:	48 01 ce             	add    rsi,rcx
    1860:	49 89 d0             	mov    r8,rdx
    1863:	49 c1 e8 05          	shr    r8,0x5
    1867:	49 83 e0 1f          	and    r8,0x1f
    186b:	4c 01 c6             	add    rsi,r8
    186e:	48 81 c6 92 00 00 00 	add    rsi,0x92
    1875:	48 8b 97 a0 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4a0]
    187c:	48 89 d1             	mov    rcx,rdx
    187f:	48 c1 e9 11          	shr    rcx,0x11
    1883:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    188a:	48 01 ce             	add    rsi,rcx
    188d:	49 89 d0             	mov    r8,rdx
    1890:	49 c1 e8 05          	shr    r8,0x5
    1894:	49 83 e0 1f          	and    r8,0x1f
    1898:	4c 01 c6             	add    rsi,r8
    189b:	48 81 c6 93 00 00 00 	add    rsi,0x93
    18a2:	48 8b 97 a8 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4a8]
    18a9:	48 89 d1             	mov    rcx,rdx
    18ac:	48 c1 e9 11          	shr    rcx,0x11
    18b0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    18b7:	48 01 ce             	add    rsi,rcx
    18ba:	49 89 d0             	mov    r8,rdx
    18bd:	49 c1 e8 05          	shr    r8,0x5
    18c1:	49 83 e0 1f          	and    r8,0x1f
    18c5:	4c 01 c6             	add    rsi,r8
    18c8:	48 81 c6 94 00 00 00 	add    rsi,0x94
    18cf:	48 8b 97 b0 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4b0]
    18d6:	48 89 d1             	mov    rcx,rdx
    18d9:	48 c1 e9 11          	shr    rcx,0x11
    18dd:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    18e4:	48 01 ce             	add    rsi,rcx
    18e7:	49 89 d0             	mov    r8,rdx
    18ea:	49 c1 e8 05          	shr    r8,0x5
    18ee:	49 83 e0 1f          	and    r8,0x1f
    18f2:	4c 01 c6             	add    rsi,r8
    18f5:	48 81 c6 95 00 00 00 	add    rsi,0x95
    18fc:	48 8b 97 b8 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4b8]
    1903:	48 89 d1             	mov    rcx,rdx
    1906:	48 c1 e9 11          	shr    rcx,0x11
    190a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1911:	48 01 ce             	add    rsi,rcx
    1914:	49 89 d0             	mov    r8,rdx
    1917:	49 c1 e8 05          	shr    r8,0x5
    191b:	49 83 e0 1f          	and    r8,0x1f
    191f:	4c 01 c6             	add    rsi,r8
    1922:	48 81 c6 96 00 00 00 	add    rsi,0x96
    1929:	48 8b 97 c0 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4c0]
    1930:	48 89 d1             	mov    rcx,rdx
    1933:	48 c1 e9 11          	shr    rcx,0x11
    1937:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    193e:	48 01 ce             	add    rsi,rcx
    1941:	49 89 d0             	mov    r8,rdx
    1944:	49 c1 e8 05          	shr    r8,0x5
    1948:	49 83 e0 1f          	and    r8,0x1f
    194c:	4c 01 c6             	add    rsi,r8
    194f:	48 81 c6 97 00 00 00 	add    rsi,0x97
    1956:	48 8b 97 c8 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4c8]
    195d:	48 89 d1             	mov    rcx,rdx
    1960:	48 c1 e9 11          	shr    rcx,0x11
    1964:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    196b:	48 01 ce             	add    rsi,rcx
    196e:	49 89 d0             	mov    r8,rdx
    1971:	49 c1 e8 05          	shr    r8,0x5
    1975:	49 83 e0 1f          	and    r8,0x1f
    1979:	4c 01 c6             	add    rsi,r8
    197c:	48 81 c6 98 00 00 00 	add    rsi,0x98
    1983:	48 8b 97 d0 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4d0]
    198a:	48 89 d1             	mov    rcx,rdx
    198d:	48 c1 e9 11          	shr    rcx,0x11
    1991:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1998:	48 01 ce             	add    rsi,rcx
    199b:	49 89 d0             	mov    r8,rdx
    199e:	49 c1 e8 05          	shr    r8,0x5
    19a2:	49 83 e0 1f          	and    r8,0x1f
    19a6:	4c 01 c6             	add    rsi,r8
    19a9:	48 81 c6 99 00 00 00 	add    rsi,0x99
    19b0:	48 8b 97 d8 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4d8]
    19b7:	48 89 d1             	mov    rcx,rdx
    19ba:	48 c1 e9 11          	shr    rcx,0x11
    19be:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    19c5:	48 01 ce             	add    rsi,rcx
    19c8:	49 89 d0             	mov    r8,rdx
    19cb:	49 c1 e8 05          	shr    r8,0x5
    19cf:	49 83 e0 1f          	and    r8,0x1f
    19d3:	4c 01 c6             	add    rsi,r8
    19d6:	48 81 c6 9a 00 00 00 	add    rsi,0x9a
    19dd:	48 8b 97 e0 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4e0]
    19e4:	48 89 d1             	mov    rcx,rdx
    19e7:	48 c1 e9 11          	shr    rcx,0x11
    19eb:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    19f2:	48 01 ce             	add    rsi,rcx
    19f5:	49 89 d0             	mov    r8,rdx
    19f8:	49 c1 e8 05          	shr    r8,0x5
    19fc:	49 83 e0 1f          	and    r8,0x1f
    1a00:	4c 01 c6             	add    rsi,r8
    1a03:	48 81 c6 9b 00 00 00 	add    rsi,0x9b
    1a0a:	48 8b 97 e8 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4e8]
    1a11:	48 89 d1             	mov    rcx,rdx
    1a14:	48 c1 e9 11          	shr    rcx,0x11
    1a18:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1a1f:	48 01 ce             	add    rsi,rcx
    1a22:	49 89 d0             	mov    r8,rdx
    1a25:	49 c1 e8 05          	shr    r8,0x5
    1a29:	49 83 e0 1f          	and    r8,0x1f
    1a2d:	4c 01 c6             	add    rsi,r8
    1a30:	48 81 c6 9c 00 00 00 	add    rsi,0x9c
    1a37:	48 8b 97 f0 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4f0]
    1a3e:	48 89 d1             	mov    rcx,rdx
    1a41:	48 c1 e9 11          	shr    rcx,0x11
    1a45:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1a4c:	48 01 ce             	add    rsi,rcx
    1a4f:	49 89 d0             	mov    r8,rdx
    1a52:	49 c1 e8 05          	shr    r8,0x5
    1a56:	49 83 e0 1f          	and    r8,0x1f
    1a5a:	4c 01 c6             	add    rsi,r8
    1a5d:	48 81 c6 9d 00 00 00 	add    rsi,0x9d
    1a64:	48 8b 97 f8 04 00 00 	mov    rdx,QWORD PTR [rdi+0x4f8]
    1a6b:	48 89 d1             	mov    rcx,rdx
    1a6e:	48 c1 e9 11          	shr    rcx,0x11
    1a72:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1a79:	48 01 ce             	add    rsi,rcx
    1a7c:	49 89 d0             	mov    r8,rdx
    1a7f:	49 c1 e8 05          	shr    r8,0x5
    1a83:	49 83 e0 1f          	and    r8,0x1f
    1a87:	4c 01 c6             	add    rsi,r8
    1a8a:	48 81 c6 9e 00 00 00 	add    rsi,0x9e
    1a91:	48 8b 97 00 05 00 00 	mov    rdx,QWORD PTR [rdi+0x500]
    1a98:	48 89 d1             	mov    rcx,rdx
    1a9b:	48 c1 e9 11          	shr    rcx,0x11
    1a9f:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1aa6:	48 01 ce             	add    rsi,rcx
    1aa9:	49 89 d0             	mov    r8,rdx
    1aac:	49 c1 e8 05          	shr    r8,0x5
    1ab0:	49 83 e0 1f          	and    r8,0x1f
    1ab4:	4c 01 c6             	add    rsi,r8
    1ab7:	48 81 c6 9f 00 00 00 	add    rsi,0x9f
    1abe:	48 8b 97 08 05 00 00 	mov    rdx,QWORD PTR [rdi+0x508]
    1ac5:	48 89 d1             	mov    rcx,rdx
    1ac8:	48 c1 e9 11          	shr    rcx,0x11
    1acc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1ad3:	48 01 ce             	add    rsi,rcx
    1ad6:	49 89 d0             	mov    r8,rdx
    1ad9:	49 c1 e8 05          	shr    r8,0x5
    1add:	49 83 e0 1f          	and    r8,0x1f
    1ae1:	4c 01 c6             	add    rsi,r8
    1ae4:	48 81 c6 a0 00 00 00 	add    rsi,0xa0
    1aeb:	48 8b 97 10 05 00 00 	mov    rdx,QWORD PTR [rdi+0x510]
    1af2:	48 89 d1             	mov    rcx,rdx
    1af5:	48 c1 e9 11          	shr    rcx,0x11
    1af9:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1b00:	48 01 ce             	add    rsi,rcx
    1b03:	49 89 d0             	mov    r8,rdx
    1b06:	49 c1 e8 05          	shr    r8,0x5
    1b0a:	49 83 e0 1f          	and    r8,0x1f
    1b0e:	4c 01 c6             	add    rsi,r8
    1b11:	48 81 c6 a1 00 00 00 	add    rsi,0xa1
    1b18:	48 8b 97 18 05 00 00 	mov    rdx,QWORD PTR [rdi+0x518]
    1b1f:	48 89 d1             	mov    rcx,rdx
    1b22:	48 c1 e9 11          	shr    rcx,0x11
    1b26:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1b2d:	48 01 ce             	add    rsi,rcx
    1b30:	49 89 d0             	mov    r8,rdx
    1b33:	49 c1 e8 05          	shr    r8,0x5
    1b37:	49 83 e0 1f          	and    r8,0x1f
    1b3b:	4c 01 c6             	add    rsi,r8
    1b3e:	48 81 c6 a2 00 00 00 	add    rsi,0xa2
    1b45:	48 8b 97 20 05 00 00 	mov    rdx,QWORD PTR [rdi+0x520]
    1b4c:	48 89 d1             	mov    rcx,rdx
    1b4f:	48 c1 e9 11          	shr    rcx,0x11
    1b53:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1b5a:	48 01 ce             	add    rsi,rcx
    1b5d:	49 89 d0             	mov    r8,rdx
    1b60:	49 c1 e8 05          	shr    r8,0x5
    1b64:	49 83 e0 1f          	and    r8,0x1f
    1b68:	4c 01 c6             	add    rsi,r8
    1b6b:	48 81 c6 a3 00 00 00 	add    rsi,0xa3
    1b72:	48 8b 97 28 05 00 00 	mov    rdx,QWORD PTR [rdi+0x528]
    1b79:	48 89 d1             	mov    rcx,rdx
    1b7c:	48 c1 e9 11          	shr    rcx,0x11
    1b80:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1b87:	48 01 ce             	add    rsi,rcx
    1b8a:	49 89 d0             	mov    r8,rdx
    1b8d:	49 c1 e8 05          	shr    r8,0x5
    1b91:	49 83 e0 1f          	and    r8,0x1f
    1b95:	4c 01 c6             	add    rsi,r8
    1b98:	48 81 c6 a4 00 00 00 	add    rsi,0xa4
    1b9f:	48 8b 97 30 05 00 00 	mov    rdx,QWORD PTR [rdi+0x530]
    1ba6:	48 89 d1             	mov    rcx,rdx
    1ba9:	48 c1 e9 11          	shr    rcx,0x11
    1bad:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1bb4:	48 01 ce             	add    rsi,rcx
    1bb7:	49 89 d0             	mov    r8,rdx
    1bba:	49 c1 e8 05          	shr    r8,0x5
    1bbe:	49 83 e0 1f          	and    r8,0x1f
    1bc2:	4c 01 c6             	add    rsi,r8
    1bc5:	48 81 c6 a5 00 00 00 	add    rsi,0xa5
    1bcc:	48 8b 97 38 05 00 00 	mov    rdx,QWORD PTR [rdi+0x538]
    1bd3:	48 89 d1             	mov    rcx,rdx
    1bd6:	48 c1 e9 11          	shr    rcx,0x11
    1bda:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1be1:	48 01 ce             	add    rsi,rcx
    1be4:	49 89 d0             	mov    r8,rdx
    1be7:	49 c1 e8 05          	shr    r8,0x5
    1beb:	49 83 e0 1f          	and    r8,0x1f
    1bef:	4c 01 c6             	add    rsi,r8
    1bf2:	48 81 c6 a6 00 00 00 	add    rsi,0xa6
    1bf9:	48 8b 97 40 05 00 00 	mov    rdx,QWORD PTR [rdi+0x540]
    1c00:	48 89 d1             	mov    rcx,rdx
    1c03:	48 c1 e9 11          	shr    rcx,0x11
    1c07:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1c0e:	48 01 ce             	add    rsi,rcx
    1c11:	49 89 d0             	mov    r8,rdx
    1c14:	49 c1 e8 05          	shr    r8,0x5
    1c18:	49 83 e0 1f          	and    r8,0x1f
    1c1c:	4c 01 c6             	add    rsi,r8
    1c1f:	48 81 c6 a7 00 00 00 	add    rsi,0xa7
    1c26:	48 8b 97 48 05 00 00 	mov    rdx,QWORD PTR [rdi+0x548]
    1c2d:	48 89 d1             	mov    rcx,rdx
    1c30:	48 c1 e9 11          	shr    rcx,0x11
    1c34:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1c3b:	48 01 ce             	add    rsi,rcx
    1c3e:	49 89 d0             	mov    r8,rdx
    1c41:	49 c1 e8 05          	shr    r8,0x5
    1c45:	49 83 e0 1f          	and    r8,0x1f
    1c49:	4c 01 c6             	add    rsi,r8
    1c4c:	48 81 c6 a8 00 00 00 	add    rsi,0xa8
    1c53:	48 8b 97 50 05 00 00 	mov    rdx,QWORD PTR [rdi+0x550]
    1c5a:	48 89 d1             	mov    rcx,rdx
    1c5d:	48 c1 e9 11          	shr    rcx,0x11
    1c61:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1c68:	48 01 ce             	add    rsi,rcx
    1c6b:	49 89 d0             	mov    r8,rdx
    1c6e:	49 c1 e8 05          	shr    r8,0x5
    1c72:	49 83 e0 1f          	and    r8,0x1f
    1c76:	4c 01 c6             	add    rsi,r8
    1c79:	48 81 c6 a9 00 00 00 	add    rsi,0xa9
    1c80:	48 8b 97 58 05 00 00 	mov    rdx,QWORD PTR [rdi+0x558]
    1c87:	48 89 d1             	mov    rcx,rdx
    1c8a:	48 c1 e9 11          	shr    rcx,0x11
    1c8e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1c95:	48 01 ce             	add    rsi,rcx
    1c98:	49 89 d0             	mov    r8,rdx
    1c9b:	49 c1 e8 05          	shr    r8,0x5
    1c9f:	49 83 e0 1f          	and    r8,0x1f
    1ca3:	4c 01 c6             	add    rsi,r8
    1ca6:	48 81 c6 aa 00 00 00 	add    rsi,0xaa
    1cad:	48 8b 97 60 05 00 00 	mov    rdx,QWORD PTR [rdi+0x560]
    1cb4:	48 89 d1             	mov    rcx,rdx
    1cb7:	48 c1 e9 11          	shr    rcx,0x11
    1cbb:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1cc2:	48 01 ce             	add    rsi,rcx
    1cc5:	49 89 d0             	mov    r8,rdx
    1cc8:	49 c1 e8 05          	shr    r8,0x5
    1ccc:	49 83 e0 1f          	and    r8,0x1f
    1cd0:	4c 01 c6             	add    rsi,r8
    1cd3:	48 81 c6 ab 00 00 00 	add    rsi,0xab
    1cda:	48 8b 97 68 05 00 00 	mov    rdx,QWORD PTR [rdi+0x568]
    1ce1:	48 89 d1             	mov    rcx,rdx
    1ce4:	48 c1 e9 11          	shr    rcx,0x11
    1ce8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1cef:	48 01 ce             	add    rsi,rcx
    1cf2:	49 89 d0             	mov    r8,rdx
    1cf5:	49 c1 e8 05          	shr    r8,0x5
    1cf9:	49 83 e0 1f          	and    r8,0x1f
    1cfd:	4c 01 c6             	add    rsi,r8
    1d00:	48 81 c6 ac 00 00 00 	add    rsi,0xac
    1d07:	48 8b 97 70 05 00 00 	mov    rdx,QWORD PTR [rdi+0x570]
    1d0e:	48 89 d1             	mov    rcx,rdx
    1d11:	48 c1 e9 11          	shr    rcx,0x11
    1d15:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1d1c:	48 01 ce             	add    rsi,rcx
    1d1f:	49 89 d0             	mov    r8,rdx
    1d22:	49 c1 e8 05          	shr    r8,0x5
    1d26:	49 83 e0 1f          	and    r8,0x1f
    1d2a:	4c 01 c6             	add    rsi,r8
    1d2d:	48 81 c6 ad 00 00 00 	add    rsi,0xad
    1d34:	48 8b 97 78 05 00 00 	mov    rdx,QWORD PTR [rdi+0x578]
    1d3b:	48 89 d1             	mov    rcx,rdx
    1d3e:	48 c1 e9 11          	shr    rcx,0x11
    1d42:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1d49:	48 01 ce             	add    rsi,rcx
    1d4c:	49 89 d0             	mov    r8,rdx
    1d4f:	49 c1 e8 05          	shr    r8,0x5
    1d53:	49 83 e0 1f          	and    r8,0x1f
    1d57:	4c 01 c6             	add    rsi,r8
    1d5a:	48 81 c6 ae 00 00 00 	add    rsi,0xae
    1d61:	48 8b 97 80 05 00 00 	mov    rdx,QWORD PTR [rdi+0x580]
    1d68:	48 89 d1             	mov    rcx,rdx
    1d6b:	48 c1 e9 11          	shr    rcx,0x11
    1d6f:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1d76:	48 01 ce             	add    rsi,rcx
    1d79:	49 89 d0             	mov    r8,rdx
    1d7c:	49 c1 e8 05          	shr    r8,0x5
    1d80:	49 83 e0 1f          	and    r8,0x1f
    1d84:	4c 01 c6             	add    rsi,r8
    1d87:	48 81 c6 af 00 00 00 	add    rsi,0xaf
    1d8e:	48 8b 97 88 05 00 00 	mov    rdx,QWORD PTR [rdi+0x588]
    1d95:	48 89 d1             	mov    rcx,rdx
    1d98:	48 c1 e9 11          	shr    rcx,0x11
    1d9c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1da3:	48 01 ce             	add    rsi,rcx
    1da6:	49 89 d0             	mov    r8,rdx
    1da9:	49 c1 e8 05          	shr    r8,0x5
    1dad:	49 83 e0 1f          	and    r8,0x1f
    1db1:	4c 01 c6             	add    rsi,r8
    1db4:	48 81 c6 b0 00 00 00 	add    rsi,0xb0
    1dbb:	48 8b 97 90 05 00 00 	mov    rdx,QWORD PTR [rdi+0x590]
    1dc2:	48 89 d1             	mov    rcx,rdx
    1dc5:	48 c1 e9 11          	shr    rcx,0x11
    1dc9:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1dd0:	48 01 ce             	add    rsi,rcx
    1dd3:	49 89 d0             	mov    r8,rdx
    1dd6:	49 c1 e8 05          	shr    r8,0x5
    1dda:	49 83 e0 1f          	and    r8,0x1f
    1dde:	4c 01 c6             	add    rsi,r8
    1de1:	48 81 c6 b1 00 00 00 	add    rsi,0xb1
    1de8:	48 8b 97 98 05 00 00 	mov    rdx,QWORD PTR [rdi+0x598]
    1def:	48 89 d1             	mov    rcx,rdx
    1df2:	48 c1 e9 11          	shr    rcx,0x11
    1df6:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1dfd:	48 01 ce             	add    rsi,rcx
    1e00:	49 89 d0             	mov    r8,rdx
    1e03:	49 c1 e8 05          	shr    r8,0x5
    1e07:	49 83 e0 1f          	and    r8,0x1f
    1e0b:	4c 01 c6             	add    rsi,r8
    1e0e:	48 81 c6 b2 00 00 00 	add    rsi,0xb2
    1e15:	48 8b 97 a0 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5a0]
    1e1c:	48 89 d1             	mov    rcx,rdx
    1e1f:	48 c1 e9 11          	shr    rcx,0x11
    1e23:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1e2a:	48 01 ce             	add    rsi,rcx
    1e2d:	49 89 d0             	mov    r8,rdx
    1e30:	49 c1 e8 05          	shr    r8,0x5
    1e34:	49 83 e0 1f          	and    r8,0x1f
    1e38:	4c 01 c6             	add    rsi,r8
    1e3b:	48 81 c6 b3 00 00 00 	add    rsi,0xb3
    1e42:	48 8b 97 a8 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5a8]
    1e49:	48 89 d1             	mov    rcx,rdx
    1e4c:	48 c1 e9 11          	shr    rcx,0x11
    1e50:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1e57:	48 01 ce             	add    rsi,rcx
    1e5a:	49 89 d0             	mov    r8,rdx
    1e5d:	49 c1 e8 05          	shr    r8,0x5
    1e61:	49 83 e0 1f          	and    r8,0x1f
    1e65:	4c 01 c6             	add    rsi,r8
    1e68:	48 81 c6 b4 00 00 00 	add    rsi,0xb4
    1e6f:	48 8b 97 b0 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5b0]
    1e76:	48 89 d1             	mov    rcx,rdx
    1e79:	48 c1 e9 11          	shr    rcx,0x11
    1e7d:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1e84:	48 01 ce             	add    rsi,rcx
    1e87:	49 89 d0             	mov    r8,rdx
    1e8a:	49 c1 e8 05          	shr    r8,0x5
    1e8e:	49 83 e0 1f          	and    r8,0x1f
    1e92:	4c 01 c6             	add    rsi,r8
    1e95:	48 81 c6 b5 00 00 00 	add    rsi,0xb5
    1e9c:	48 8b 97 b8 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5b8]
    1ea3:	48 89 d1             	mov    rcx,rdx
    1ea6:	48 c1 e9 11          	shr    rcx,0x11
    1eaa:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1eb1:	48 01 ce             	add    rsi,rcx
    1eb4:	49 89 d0             	mov    r8,rdx
    1eb7:	49 c1 e8 05          	shr    r8,0x5
    1ebb:	49 83 e0 1f          	and    r8,0x1f
    1ebf:	4c 01 c6             	add    rsi,r8
    1ec2:	48 81 c6 b6 00 00 00 	add    rsi,0xb6
    1ec9:	48 8b 97 c0 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5c0]
    1ed0:	48 89 d1             	mov    rcx,rdx
    1ed3:	48 c1 e9 11          	shr    rcx,0x11
    1ed7:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1ede:	48 01 ce             	add    rsi,rcx
    1ee1:	49 89 d0             	mov    r8,rdx
    1ee4:	49 c1 e8 05          	shr    r8,0x5
    1ee8:	49 83 e0 1f          	and    r8,0x1f
    1eec:	4c 01 c6             	add    rsi,r8
    1eef:	48 81 c6 b7 00 00 00 	add    rsi,0xb7
    1ef6:	48 8b 97 c8 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5c8]
    1efd:	48 89 d1             	mov    rcx,rdx
    1f00:	48 c1 e9 11          	shr    rcx,0x11
    1f04:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1f0b:	48 01 ce             	add    rsi,rcx
    1f0e:	49 89 d0             	mov    r8,rdx
    1f11:	49 c1 e8 05          	shr    r8,0x5
    1f15:	49 83 e0 1f          	and    r8,0x1f
    1f19:	4c 01 c6             	add    rsi,r8
    1f1c:	48 81 c6 b8 00 00 00 	add    rsi,0xb8
    1f23:	48 8b 97 d0 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5d0]
    1f2a:	48 89 d1             	mov    rcx,rdx
    1f2d:	48 c1 e9 11          	shr    rcx,0x11
    1f31:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1f38:	48 01 ce             	add    rsi,rcx
    1f3b:	49 89 d0             	mov    r8,rdx
    1f3e:	49 c1 e8 05          	shr    r8,0x5
    1f42:	49 83 e0 1f          	and    r8,0x1f
    1f46:	4c 01 c6             	add    rsi,r8
    1f49:	48 81 c6 b9 00 00 00 	add    rsi,0xb9
    1f50:	48 8b 97 d8 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5d8]
    1f57:	48 89 d1             	mov    rcx,rdx
    1f5a:	48 c1 e9 11          	shr    rcx,0x11
    1f5e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1f65:	48 01 ce             	add    rsi,rcx
    1f68:	49 89 d0             	mov    r8,rdx
    1f6b:	49 c1 e8 05          	shr    r8,0x5
    1f6f:	49 83 e0 1f          	and    r8,0x1f
    1f73:	4c 01 c6             	add    rsi,r8
    1f76:	48 81 c6 ba 00 00 00 	add    rsi,0xba
    1f7d:	48 8b 97 e0 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5e0]
    1f84:	48 89 d1             	mov    rcx,rdx
    1f87:	48 c1 e9 11          	shr    rcx,0x11
    1f8b:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1f92:	48 01 ce             	add    rsi,rcx
    1f95:	49 89 d0             	mov    r8,rdx
    1f98:	49 c1 e8 05          	shr    r8,0x5
    1f9c:	49 83 e0 1f          	and    r8,0x1f
    1fa0:	4c 01 c6             	add    rsi,r8
    1fa3:	48 81 c6 bb 00 00 00 	add    rsi,0xbb
    1faa:	48 8b 97 e8 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5e8]
    1fb1:	48 89 d1             	mov    rcx,rdx
    1fb4:	48 c1 e9 11          	shr    rcx,0x11
    1fb8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1fbf:	48 01 ce             	add    rsi,rcx
    1fc2:	49 89 d0             	mov    r8,rdx
    1fc5:	49 c1 e8 05          	shr    r8,0x5
    1fc9:	49 83 e0 1f          	and    r8,0x1f
    1fcd:	4c 01 c6             	add    rsi,r8
    1fd0:	48 81 c6 bc 00 00 00 	add    rsi,0xbc
    1fd7:	48 8b 97 f0 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5f0]
    1fde:	48 89 d1             	mov    rcx,rdx
    1fe1:	48 c1 e9 11          	shr    rcx,0x11
    1fe5:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    1fec:	48 01 ce             	add    rsi,rcx
    1fef:	49 89 d0             	mov    r8,rdx
    1ff2:	49 c1 e8 05          	shr    r8,0x5
    1ff6:	49 83 e0 1f          	and    r8,0x1f
    1ffa:	4c 01 c6             	add    rsi,r8
    1ffd:	48 81 c6 bd 00 00 00 	add    rsi,0xbd
    2004:	48 8b 97 f8 05 00 00 	mov    rdx,QWORD PTR [rdi+0x5f8]
    200b:	48 89 d1             	mov    rcx,rdx
    200e:	48 c1 e9 11          	shr    rcx,0x11
    2012:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2019:	48 01 ce             	add    rsi,rcx
    201c:	49 89 d0             	mov    r8,rdx
    201f:	49 c1 e8 05          	shr    r8,0x5
    2023:	49 83 e0 1f          	and    r8,0x1f
    2027:	4c 01 c6             	add    rsi,r8
    202a:	48 81 c6 be 00 00 00 	add    rsi,0xbe
    2031:	48 8b 97 00 06 00 00 	mov    rdx,QWORD PTR [rdi+0x600]
    2038:	48 89 d1             	mov    rcx,rdx
    203b:	48 c1 e9 11          	shr    rcx,0x11
    203f:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2046:	48 01 ce             	add    rsi,rcx
    2049:	49 89 d0             	mov    r8,rdx
    204c:	49 c1 e8 05          	shr    r8,0x5
    2050:	49 83 e0 1f          	and    r8,0x1f
    2054:	4c 01 c6             	add    rsi,r8
    2057:	48 81 c6 bf 00 00 00 	add    rsi,0xbf
    205e:	48 8b 97 08 06 00 00 	mov    rdx,QWORD PTR [rdi+0x608]
    2065:	48 89 d1             	mov    rcx,rdx
    2068:	48 c1 e9 11          	shr    rcx,0x11
    206c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2073:	48 01 ce             	add    rsi,rcx
    2076:	49 89 d0             	mov    r8,rdx
    2079:	49 c1 e8 05          	shr    r8,0x5
    207d:	49 83 e0 1f          	and    r8,0x1f
    2081:	4c 01 c6             	add    rsi,r8
    2084:	48 81 c6 c0 00 00 00 	add    rsi,0xc0
    208b:	48 8b 97 10 06 00 00 	mov    rdx,QWORD PTR [rdi+0x610]
    2092:	48 89 d1             	mov    rcx,rdx
    2095:	48 c1 e9 11          	shr    rcx,0x11
    2099:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    20a0:	48 01 ce             	add    rsi,rcx
    20a3:	49 89 d0             	mov    r8,rdx
    20a6:	49 c1 e8 05          	shr    r8,0x5
    20aa:	49 83 e0 1f          	and    r8,0x1f
    20ae:	4c 01 c6             	add    rsi,r8
    20b1:	48 81 c6 c1 00 00 00 	add    rsi,0xc1
    20b8:	48 8b 97 18 06 00 00 	mov    rdx,QWORD PTR [rdi+0x618]
    20bf:	48 89 d1             	mov    rcx,rdx
    20c2:	48 c1 e9 11          	shr    rcx,0x11
    20c6:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    20cd:	48 01 ce             	add    rsi,rcx
    20d0:	49 89 d0             	mov    r8,rdx
    20d3:	49 c1 e8 05          	shr    r8,0x5
    20d7:	49 83 e0 1f          	and    r8,0x1f
    20db:	4c 01 c6             	add    rsi,r8
    20de:	48 81 c6 c2 00 00 00 	add    rsi,0xc2
    20e5:	48 8b 97 20 06 00 00 	mov    rdx,QWORD PTR [rdi+0x620]
    20ec:	48 89 d1             	mov    rcx,rdx
    20ef:	48 c1 e9 11          	shr    rcx,0x11
    20f3:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    20fa:	48 01 ce             	add    rsi,rcx
    20fd:	49 89 d0             	mov    r8,rdx
    2100:	49 c1 e8 05          	shr    r8,0x5
    2104:	49 83 e0 1f          	and    r8,0x1f
    2108:	4c 01 c6             	add    rsi,r8
    210b:	48 81 c6 c3 00 00 00 	add    rsi,0xc3
    2112:	48 8b 97 28 06 00 00 	mov    rdx,QWORD PTR [rdi+0x628]
    2119:	48 89 d1             	mov    rcx,rdx
    211c:	48 c1 e9 11          	shr    rcx,0x11
    2120:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2127:	48 01 ce             	add    rsi,rcx
    212a:	49 89 d0             	mov    r8,rdx
    212d:	49 c1 e8 05          	shr    r8,0x5
    2131:	49 83 e0 1f          	and    r8,0x1f
    2135:	4c 01 c6             	add    rsi,r8
    2138:	48 81 c6 c4 00 00 00 	add    rsi,0xc4
    213f:	48 8b 97 30 06 00 00 	mov    rdx,QWORD PTR [rdi+0x630]
    2146:	48 89 d1             	mov    rcx,rdx
    2149:	48 c1 e9 11          	shr    rcx,0x11
    214d:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2154:	48 01 ce             	add    rsi,rcx
    2157:	49 89 d0             	mov    r8,rdx
    215a:	49 c1 e8 05          	shr    r8,0x5
    215e:	49 83 e0 1f          	and    r8,0x1f
    2162:	4c 01 c6             	add    rsi,r8
    2165:	48 81 c6 c5 00 00 00 	add    rsi,0xc5
    216c:	48 8b 97 38 06 00 00 	mov    rdx,QWORD PTR [rdi+0x638]
    2173:	48 89 d1             	mov    rcx,rdx
    2176:	48 c1 e9 11          	shr    rcx,0x11
    217a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2181:	48 01 ce             	add    rsi,rcx
    2184:	49 89 d0             	mov    r8,rdx
    2187:	49 c1 e8 05          	shr    r8,0x5
    218b:	49 83 e0 1f          	and    r8,0x1f
    218f:	4c 01 c6             	add    rsi,r8
    2192:	48 81 c6 c6 00 00 00 	add    rsi,0xc6
    2199:	48 8b 97 40 06 00 00 	mov    rdx,QWORD PTR [rdi+0x640]
    21a0:	48 89 d1             	mov    rcx,rdx
    21a3:	48 c1 e9 11          	shr    rcx,0x11
    21a7:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    21ae:	48 01 ce             	add    rsi,rcx
    21b1:	49 89 d0             	mov    r8,rdx
    21b4:	49 c1 e8 05          	shr    r8,0x5
    21b8:	49 83 e0 1f          	and    r8,0x1f
    21bc:	4c 01 c6             	add    rsi,r8
    21bf:	48 81 c6 c7 00 00 00 	add    rsi,0xc7
    21c6:	48 8b 97 48 06 00 00 	mov    rdx,QWORD PTR [rdi+0x648]
    21cd:	48 89 d1             	mov    rcx,rdx
    21d0:	48 c1 e9 11          	shr    rcx,0x11
    21d4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    21db:	48 01 ce             	add    rsi,rcx
    21de:	49 89 d0             	mov    r8,rdx
    21e1:	49 c1 e8 05          	shr    r8,0x5
    21e5:	49 83 e0 1f          	and    r8,0x1f
    21e9:	4c 01 c6             	add    rsi,r8
    21ec:	48 81 c6 c8 00 00 00 	add    rsi,0xc8
    21f3:	48 8b 97 50 06 00 00 	mov    rdx,QWORD PTR [rdi+0x650]
    21fa:	48 89 d1             	mov    rcx,rdx
    21fd:	48 c1 e9 11          	shr    rcx,0x11
    2201:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2208:	48 01 ce             	add    rsi,rcx
    220b:	49 89 d0             	mov    r8,rdx
    220e:	49 c1 e8 05          	shr    r8,0x5
    2212:	49 83 e0 1f          	and    r8,0x1f
    2216:	4c 01 c6             	add    rsi,r8
    2219:	48 81 c6 c9 00 00 00 	add    rsi,0xc9
    2220:	48 8b 97 58 06 00 00 	mov    rdx,QWORD PTR [rdi+0x658]
    2227:	48 89 d1             	mov    rcx,rdx
    222a:	48 c1 e9 11          	shr    rcx,0x11
    222e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2235:	48 01 ce             	add    rsi,rcx
    2238:	49 89 d0             	mov    r8,rdx
    223b:	49 c1 e8 05          	shr    r8,0x5
    223f:	49 83 e0 1f          	and    r8,0x1f
    2243:	4c 01 c6             	add    rsi,r8
    2246:	48 81 c6 ca 00 00 00 	add    rsi,0xca
    224d:	48 8b 97 60 06 00 00 	mov    rdx,QWORD PTR [rdi+0x660]
    2254:	48 89 d1             	mov    rcx,rdx
    2257:	48 c1 e9 11          	shr    rcx,0x11
    225b:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2262:	48 01 ce             	add    rsi,rcx
    2265:	49 89 d0             	mov    r8,rdx
    2268:	49 c1 e8 05          	shr    r8,0x5
    226c:	49 83 e0 1f          	and    r8,0x1f
    2270:	4c 01 c6             	add    rsi,r8
    2273:	48 81 c6 cb 00 00 00 	add    rsi,0xcb
    227a:	48 8b 97 68 06 00 00 	mov    rdx,QWORD PTR [rdi+0x668]
    2281:	48 89 d1             	mov    rcx,rdx
    2284:	48 c1 e9 11          	shr    rcx,0x11
    2288:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    228f:	48 01 ce             	add    rsi,rcx
    2292:	49 89 d0             	mov    r8,rdx
    2295:	49 c1 e8 05          	shr    r8,0x5
    2299:	49 83 e0 1f          	and    r8,0x1f
    229d:	4c 01 c6             	add    rsi,r8
    22a0:	48 81 c6 cc 00 00 00 	add    rsi,0xcc
    22a7:	48 8b 97 70 06 00 00 	mov    rdx,QWORD PTR [rdi+0x670]
    22ae:	48 89 d1             	mov    rcx,rdx
    22b1:	48 c1 e9 11          	shr    rcx,0x11
    22b5:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    22bc:	48 01 ce             	add    rsi,rcx
    22bf:	49 89 d0             	mov    r8,rdx
    22c2:	49 c1 e8 05          	shr    r8,0x5
    22c6:	49 83 e0 1f          	and    r8,0x1f
    22ca:	4c 01 c6             	add    rsi,r8
    22cd:	48 81 c6 cd 00 00 00 	add    rsi,0xcd
    22d4:	48 8b 97 78 06 00 00 	mov    rdx,QWORD PTR [rdi+0x678]
    22db:	48 89 d1             	mov    rcx,rdx
    22de:	48 c1 e9 11          	shr    rcx,0x11
    22e2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    22e9:	48 01 ce             	add    rsi,rcx
    22ec:	49 89 d0             	mov    r8,rdx
    22ef:	49 c1 e8 05          	shr    r8,0x5
    22f3:	49 83 e0 1f          	and    r8,0x1f
    22f7:	4c 01 c6             	add    rsi,r8
    22fa:	48 81 c6 ce 00 00 00 	add    rsi,0xce
    2301:	48 8b 97 80 06 00 00 	mov    rdx,QWORD PTR [rdi+0x680]
    2308:	48 89 d1             	mov    rcx,rdx
    230b:	48 c1 e9 11          	shr    rcx,0x11
    230f:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2316:	48 01 ce             	add    rsi,rcx
    2319:	49 89 d0             	mov    r8,rdx
    231c:	49 c1 e8 05          	shr    r8,0x5
    2320:	49 83 e0 1f          	and    r8,0x1f
    2324:	4c 01 c6             	add    rsi,r8
    2327:	48 81 c6 cf 00 00 00 	add    rsi,0xcf
    232e:	48 8b 97 88 06 00 00 	mov    rdx,QWORD PTR [rdi+0x688]
    2335:	48 89 d1             	mov    rcx,rdx
    2338:	48 c1 e9 11          	shr    rcx,0x11
    233c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2343:	48 01 ce             	add    rsi,rcx
    2346:	49 89 d0             	mov    r8,rdx
    2349:	49 c1 e8 05          	shr    r8,0x5
    234d:	49 83 e0 1f          	and    r8,0x1f
    2351:	4c 01 c6             	add    rsi,r8
    2354:	48 81 c6 d0 00 00 00 	add    rsi,0xd0
    235b:	48 8b 97 90 06 00 00 	mov    rdx,QWORD PTR [rdi+0x690]
    2362:	48 89 d1             	mov    rcx,rdx
    2365:	48 c1 e9 11          	shr    rcx,0x11
    2369:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2370:	48 01 ce             	add    rsi,rcx
    2373:	49 89 d0             	mov    r8,rdx
    2376:	49 c1 e8 05          	shr    r8,0x5
    237a:	49 83 e0 1f          	and    r8,0x1f
    237e:	4c 01 c6             	add    rsi,r8
    2381:	48 81 c6 d1 00 00 00 	add    rsi,0xd1
    2388:	48 8b 97 98 06 00 00 	mov    rdx,QWORD PTR [rdi+0x698]
    238f:	48 89 d1             	mov    rcx,rdx
    2392:	48 c1 e9 11          	shr    rcx,0x11
    2396:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    239d:	48 01 ce             	add    rsi,rcx
    23a0:	49 89 d0             	mov    r8,rdx
    23a3:	49 c1 e8 05          	shr    r8,0x5
    23a7:	49 83 e0 1f          	and    r8,0x1f
    23ab:	4c 01 c6             	add    rsi,r8
    23ae:	48 81 c6 d2 00 00 00 	add    rsi,0xd2
    23b5:	48 8b 97 a0 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6a0]
    23bc:	48 89 d1             	mov    rcx,rdx
    23bf:	48 c1 e9 11          	shr    rcx,0x11
    23c3:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    23ca:	48 01 ce             	add    rsi,rcx
    23cd:	49 89 d0             	mov    r8,rdx
    23d0:	49 c1 e8 05          	shr    r8,0x5
    23d4:	49 83 e0 1f          	and    r8,0x1f
    23d8:	4c 01 c6             	add    rsi,r8
    23db:	48 81 c6 d3 00 00 00 	add    rsi,0xd3
    23e2:	48 8b 97 a8 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6a8]
    23e9:	48 89 d1             	mov    rcx,rdx
    23ec:	48 c1 e9 11          	shr    rcx,0x11
    23f0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    23f7:	48 01 ce             	add    rsi,rcx
    23fa:	49 89 d0             	mov    r8,rdx
    23fd:	49 c1 e8 05          	shr    r8,0x5
    2401:	49 83 e0 1f          	and    r8,0x1f
    2405:	4c 01 c6             	add    rsi,r8
    2408:	48 81 c6 d4 00 00 00 	add    rsi,0xd4
    240f:	48 8b 97 b0 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6b0]
    2416:	48 89 d1             	mov    rcx,rdx
    2419:	48 c1 e9 11          	shr    rcx,0x11
    241d:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2424:	48 01 ce             	add    rsi,rcx
    2427:	49 89 d0             	mov    r8,rdx
    242a:	49 c1 e8 05          	shr    r8,0x5
    242e:	49 83 e0 1f          	and    r8,0x1f
    2432:	4c 01 c6             	add    rsi,r8
    2435:	48 81 c6 d5 00 00 00 	add    rsi,0xd5
    243c:	48 8b 97 b8 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6b8]
    2443:	48 89 d1             	mov    rcx,rdx
    2446:	48 c1 e9 11          	shr    rcx,0x11
    244a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2451:	48 01 ce             	add    rsi,rcx
    2454:	49 89 d0             	mov    r8,rdx
    2457:	49 c1 e8 05          	shr    r8,0x5
    245b:	49 83 e0 1f          	and    r8,0x1f
    245f:	4c 01 c6             	add    rsi,r8
    2462:	48 81 c6 d6 00 00 00 	add    rsi,0xd6
    2469:	48 8b 97 c0 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6c0]
    2470:	48 89 d1             	mov    rcx,rdx
    2473:	48 c1 e9 11          	shr    rcx,0x11
    2477:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    247e:	48 01 ce             	add    rsi,rcx
    2481:	49 89 d0             	mov    r8,rdx
    2484:	49 c1 e8 05          	shr    r8,0x5
    2488:	49 83 e0 1f          	and    r8,0x1f
    248c:	4c 01 c6             	add    rsi,r8
    248f:	48 81 c6 d7 00 00 00 	add    rsi,0xd7
    2496:	48 8b 97 c8 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6c8]
    249d:	48 89 d1             	mov    rcx,rdx
    24a0:	48 c1 e9 11          	shr    rcx,0x11
    24a4:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    24ab:	48 01 ce             	add    rsi,rcx
    24ae:	49 89 d0             	mov    r8,rdx
    24b1:	49 c1 e8 05          	shr    r8,0x5
    24b5:	49 83 e0 1f          	and    r8,0x1f
    24b9:	4c 01 c6             	add    rsi,r8
    24bc:	48 81 c6 d8 00 00 00 	add    rsi,0xd8
    24c3:	48 8b 97 d0 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6d0]
    24ca:	48 89 d1             	mov    rcx,rdx
    24cd:	48 c1 e9 11          	shr    rcx,0x11
    24d1:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    24d8:	48 01 ce             	add    rsi,rcx
    24db:	49 89 d0             	mov    r8,rdx
    24de:	49 c1 e8 05          	shr    r8,0x5
    24e2:	49 83 e0 1f          	and    r8,0x1f
    24e6:	4c 01 c6             	add    rsi,r8
    24e9:	48 81 c6 d9 00 00 00 	add    rsi,0xd9
    24f0:	48 8b 97 d8 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6d8]
    24f7:	48 89 d1             	mov    rcx,rdx
    24fa:	48 c1 e9 11          	shr    rcx,0x11
    24fe:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2505:	48 01 ce             	add    rsi,rcx
    2508:	49 89 d0             	mov    r8,rdx
    250b:	49 c1 e8 05          	shr    r8,0x5
    250f:	49 83 e0 1f          	and    r8,0x1f
    2513:	4c 01 c6             	add    rsi,r8
    2516:	48 81 c6 da 00 00 00 	add    rsi,0xda
    251d:	48 8b 97 e0 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6e0]
    2524:	48 89 d1             	mov    rcx,rdx
    2527:	48 c1 e9 11          	shr    rcx,0x11
    252b:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2532:	48 01 ce             	add    rsi,rcx
    2535:	49 89 d0             	mov    r8,rdx
    2538:	49 c1 e8 05          	shr    r8,0x5
    253c:	49 83 e0 1f          	and    r8,0x1f
    2540:	4c 01 c6             	add    rsi,r8
    2543:	48 81 c6 db 00 00 00 	add    rsi,0xdb
    254a:	48 8b 97 e8 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6e8]
    2551:	48 89 d1             	mov    rcx,rdx
    2554:	48 c1 e9 11          	shr    rcx,0x11
    2558:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    255f:	48 01 ce             	add    rsi,rcx
    2562:	49 89 d0             	mov    r8,rdx
    2565:	49 c1 e8 05          	shr    r8,0x5
    2569:	49 83 e0 1f          	and    r8,0x1f
    256d:	4c 01 c6             	add    rsi,r8
    2570:	48 81 c6 dc 00 00 00 	add    rsi,0xdc
    2577:	48 8b 97 f0 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6f0]
    257e:	48 89 d1             	mov    rcx,rdx
    2581:	48 c1 e9 11          	shr    rcx,0x11
    2585:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    258c:	48 01 ce             	add    rsi,rcx
    258f:	49 89 d0             	mov    r8,rdx
    2592:	49 c1 e8 05          	shr    r8,0x5
    2596:	49 83 e0 1f          	and    r8,0x1f
    259a:	4c 01 c6             	add    rsi,r8
    259d:	48 81 c6 dd 00 00 00 	add    rsi,0xdd
    25a4:	48 8b 97 f8 06 00 00 	mov    rdx,QWORD PTR [rdi+0x6f8]
    25ab:	48 89 d1             	mov    rcx,rdx
    25ae:	48 c1 e9 11          	shr    rcx,0x11
    25b2:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    25b9:	48 01 ce             	add    rsi,rcx
    25bc:	49 89 d0             	mov    r8,rdx
    25bf:	49 c1 e8 05          	shr    r8,0x5
    25c3:	49 83 e0 1f          	and    r8,0x1f
    25c7:	4c 01 c6             	add    rsi,r8
    25ca:	48 81 c6 de 00 00 00 	add    rsi,0xde
    25d1:	48 8b 97 00 07 00 00 	mov    rdx,QWORD PTR [rdi+0x700]
    25d8:	48 89 d1             	mov    rcx,rdx
    25db:	48 c1 e9 11          	shr    rcx,0x11
    25df:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    25e6:	48 01 ce             	add    rsi,rcx
    25e9:	49 89 d0             	mov    r8,rdx
    25ec:	49 c1 e8 05          	shr    r8,0x5
    25f0:	49 83 e0 1f          	and    r8,0x1f
    25f4:	4c 01 c6             	add    rsi,r8
    25f7:	48 81 c6 df 00 00 00 	add    rsi,0xdf
    25fe:	48 8b 97 08 07 00 00 	mov    rdx,QWORD PTR [rdi+0x708]
    2605:	48 89 d1             	mov    rcx,rdx
    2608:	48 c1 e9 11          	shr    rcx,0x11
    260c:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2613:	48 01 ce             	add    rsi,rcx
    2616:	49 89 d0             	mov    r8,rdx
    2619:	49 c1 e8 05          	shr    r8,0x5
    261d:	49 83 e0 1f          	and    r8,0x1f
    2621:	4c 01 c6             	add    rsi,r8
    2624:	48 81 c6 e0 00 00 00 	add    rsi,0xe0
    262b:	48 8b 97 10 07 00 00 	mov    rdx,QWORD PTR [rdi+0x710]
    2632:	48 89 d1             	mov    rcx,rdx
    2635:	48 c1 e9 11          	shr    rcx,0x11
    2639:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2640:	48 01 ce             	add    rsi,rcx
    2643:	49 89 d0             	mov    r8,rdx
    2646:	49 c1 e8 05          	shr    r8,0x5
    264a:	49 83 e0 1f          	and    r8,0x1f
    264e:	4c 01 c6             	add    rsi,r8
    2651:	48 81 c6 e1 00 00 00 	add    rsi,0xe1
    2658:	48 8b 97 18 07 00 00 	mov    rdx,QWORD PTR [rdi+0x718]
    265f:	48 89 d1             	mov    rcx,rdx
    2662:	48 c1 e9 11          	shr    rcx,0x11
    2666:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    266d:	48 01 ce             	add    rsi,rcx
    2670:	49 89 d0             	mov    r8,rdx
    2673:	49 c1 e8 05          	shr    r8,0x5
    2677:	49 83 e0 1f          	and    r8,0x1f
    267b:	4c 01 c6             	add    rsi,r8
    267e:	48 81 c6 e2 00 00 00 	add    rsi,0xe2
    2685:	48 8b 97 20 07 00 00 	mov    rdx,QWORD PTR [rdi+0x720]
    268c:	48 89 d1             	mov    rcx,rdx
    268f:	48 c1 e9 11          	shr    rcx,0x11
    2693:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    269a:	48 01 ce             	add    rsi,rcx
    269d:	49 89 d0             	mov    r8,rdx
    26a0:	49 c1 e8 05          	shr    r8,0x5
    26a4:	49 83 e0 1f          	and    r8,0x1f
    26a8:	4c 01 c6             	add    rsi,r8
    26ab:	48 81 c6 e3 00 00 00 	add    rsi,0xe3
    26b2:	48 8b 97 28 07 00 00 	mov    rdx,QWORD PTR [rdi+0x728]
    26b9:	48 89 d1             	mov    rcx,rdx
    26bc:	48 c1 e9 11          	shr    rcx,0x11
    26c0:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    26c7:	48 01 ce             	add    rsi,rcx
    26ca:	49 89 d0             	mov    r8,rdx
    26cd:	49 c1 e8 05          	shr    r8,0x5
    26d1:	49 83 e0 1f          	and    r8,0x1f
    26d5:	4c 01 c6             	add    rsi,r8
    26d8:	48 81 c6 e4 00 00 00 	add    rsi,0xe4
    26df:	48 8b 97 30 07 00 00 	mov    rdx,QWORD PTR [rdi+0x730]
    26e6:	48 89 d1             	mov    rcx,rdx
    26e9:	48 c1 e9 11          	shr    rcx,0x11
    26ed:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    26f4:	48 01 ce             	add    rsi,rcx
    26f7:	49 89 d0             	mov    r8,rdx
    26fa:	49 c1 e8 05          	shr    r8,0x5
    26fe:	49 83 e0 1f          	and    r8,0x1f
    2702:	4c 01 c6             	add    rsi,r8
    2705:	48 81 c6 e5 00 00 00 	add    rsi,0xe5
    270c:	48 8b 97 38 07 00 00 	mov    rdx,QWORD PTR [rdi+0x738]
    2713:	48 89 d1             	mov    rcx,rdx
    2716:	48 c1 e9 11          	shr    rcx,0x11
    271a:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2721:	48 01 ce             	add    rsi,rcx
    2724:	49 89 d0             	mov    r8,rdx
    2727:	49 c1 e8 05          	shr    r8,0x5
    272b:	49 83 e0 1f          	and    r8,0x1f
    272f:	4c 01 c6             	add    rsi,r8
    2732:	48 81 c6 e6 00 00 00 	add    rsi,0xe6
    2739:	48 8b 97 40 07 00 00 	mov    rdx,QWORD PTR [rdi+0x740]
    2740:	48 89 d1             	mov    rcx,rdx
    2743:	48 c1 e9 11          	shr    rcx,0x11
    2747:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    274e:	48 01 ce             	add    rsi,rcx
    2751:	49 89 d0             	mov    r8,rdx
    2754:	49 c1 e8 05          	shr    r8,0x5
    2758:	49 83 e0 1f          	and    r8,0x1f
    275c:	4c 01 c6             	add    rsi,r8
    275f:	48 81 c6 e7 00 00 00 	add    rsi,0xe7
    2766:	48 8b 97 48 07 00 00 	mov    rdx,QWORD PTR [rdi+0x748]
    276d:	48 89 d1             	mov    rcx,rdx
    2770:	48 c1 e9 11          	shr    rcx,0x11
    2774:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    277b:	48 01 ce             	add    rsi,rcx
    277e:	49 89 d0             	mov    r8,rdx
    2781:	49 c1 e8 05          	shr    r8,0x5
    2785:	49 83 e0 1f          	and    r8,0x1f
    2789:	4c 01 c6             	add    rsi,r8
    278c:	48 81 c6 e8 00 00 00 	add    rsi,0xe8
    2793:	48 8b 97 50 07 00 00 	mov    rdx,QWORD PTR [rdi+0x750]
    279a:	48 89 d1             	mov    rcx,rdx
    279d:	48 c1 e9 11          	shr    rcx,0x11
    27a1:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    27a8:	48 01 ce             	add    rsi,rcx
    27ab:	49 89 d0             	mov    r8,rdx
    27ae:	49 c1 e8 05          	shr    r8,0x5
    27b2:	49 83 e0 1f          	and    r8,0x1f
    27b6:	4c 01 c6             	add    rsi,r8
    27b9:	48 81 c6 e9 00 00 00 	add    rsi,0xe9
    27c0:	48 8b 97 58 07 00 00 	mov    rdx,QWORD PTR [rdi+0x758]
    27c7:	48 89 d1             	mov    rcx,rdx
    27ca:	48 c1 e9 11          	shr    rcx,0x11
    27ce:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    27d5:	48 01 ce             	add    rsi,rcx
    27d8:	49 89 d0             	mov    r8,rdx
    27db:	49 c1 e8 05          	shr    r8,0x5
    27df:	49 83 e0 1f          	and    r8,0x1f
    27e3:	4c 01 c6             	add    rsi,r8
    27e6:	48 81 c6 ea 00 00 00 	add    rsi,0xea
    27ed:	48 8b 97 60 07 00 00 	mov    rdx,QWORD PTR [rdi+0x760]
    27f4:	48 89 d1             	mov    rcx,rdx
    27f7:	48 c1 e9 11          	shr    rcx,0x11
    27fb:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2802:	48 01 ce             	add    rsi,rcx
    2805:	49 89 d0             	mov    r8,rdx
    2808:	49 c1 e8 05          	shr    r8,0x5
    280c:	49 83 e0 1f          	and    r8,0x1f
    2810:	4c 01 c6             	add    rsi,r8
    2813:	48 81 c6 eb 00 00 00 	add    rsi,0xeb
    281a:	48 8b 97 68 07 00 00 	mov    rdx,QWORD PTR [rdi+0x768]
    2821:	48 89 d1             	mov    rcx,rdx
    2824:	48 c1 e9 11          	shr    rcx,0x11
    2828:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    282f:	48 01 ce             	add    rsi,rcx
    2832:	49 89 d0             	mov    r8,rdx
    2835:	49 c1 e8 05          	shr    r8,0x5
    2839:	49 83 e0 1f          	and    r8,0x1f
    283d:	4c 01 c6             	add    rsi,r8
    2840:	48 81 c6 ec 00 00 00 	add    rsi,0xec
    2847:	48 8b 97 70 07 00 00 	mov    rdx,QWORD PTR [rdi+0x770]
    284e:	48 89 d1             	mov    rcx,rdx
    2851:	48 c1 e9 11          	shr    rcx,0x11
    2855:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    285c:	48 01 ce             	add    rsi,rcx
    285f:	49 89 d0             	mov    r8,rdx
    2862:	49 c1 e8 05          	shr    r8,0x5
    2866:	49 83 e0 1f          	and    r8,0x1f
    286a:	4c 01 c6             	add    rsi,r8
    286d:	48 81 c6 ed 00 00 00 	add    rsi,0xed
    2874:	48 8b 97 78 07 00 00 	mov    rdx,QWORD PTR [rdi+0x778]
    287b:	48 89 d1             	mov    rcx,rdx
    287e:	48 c1 e9 11          	shr    rcx,0x11
    2882:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2889:	48 01 ce             	add    rsi,rcx
    288c:	49 89 d0             	mov    r8,rdx
    288f:	49 c1 e8 05          	shr    r8,0x5
    2893:	49 83 e0 1f          	and    r8,0x1f
    2897:	4c 01 c6             	add    rsi,r8
    289a:	48 81 c6 ee 00 00 00 	add    rsi,0xee
    28a1:	48 8b 97 80 07 00 00 	mov    rdx,QWORD PTR [rdi+0x780]
    28a8:	48 89 d1             	mov    rcx,rdx
    28ab:	48 c1 e9 11          	shr    rcx,0x11
    28af:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    28b6:	48 01 ce             	add    rsi,rcx
    28b9:	49 89 d0             	mov    r8,rdx
    28bc:	49 c1 e8 05          	shr    r8,0x5
    28c0:	49 83 e0 1f          	and    r8,0x1f
    28c4:	4c 01 c6             	add    rsi,r8
    28c7:	48 81 c6 ef 00 00 00 	add    rsi,0xef
    28ce:	48 8b 97 88 07 00 00 	mov    rdx,QWORD PTR [rdi+0x788]
    28d5:	48 89 d1             	mov    rcx,rdx
    28d8:	48 c1 e9 11          	shr    rcx,0x11
    28dc:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    28e3:	48 01 ce             	add    rsi,rcx
    28e6:	49 89 d0             	mov    r8,rdx
    28e9:	49 c1 e8 05          	shr    r8,0x5
    28ed:	49 83 e0 1f          	and    r8,0x1f
    28f1:	4c 01 c6             	add    rsi,r8
    28f4:	48 81 c6 f0 00 00 00 	add    rsi,0xf0
    28fb:	48 8b 97 90 07 00 00 	mov    rdx,QWORD PTR [rdi+0x790]
    2902:	48 89 d1             	mov    rcx,rdx
    2905:	48 c1 e9 11          	shr    rcx,0x11
    2909:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2910:	48 01 ce             	add    rsi,rcx
    2913:	49 89 d0             	mov    r8,rdx
    2916:	49 c1 e8 05          	shr    r8,0x5
    291a:	49 83 e0 1f          	and    r8,0x1f
    291e:	4c 01 c6             	add    rsi,r8
    2921:	48 81 c6 f1 00 00 00 	add    rsi,0xf1
    2928:	48 8b 97 98 07 00 00 	mov    rdx,QWORD PTR [rdi+0x798]
    292f:	48 89 d1             	mov    rcx,rdx
    2932:	48 c1 e9 11          	shr    rcx,0x11
    2936:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    293d:	48 01 ce             	add    rsi,rcx
    2940:	49 89 d0             	mov    r8,rdx
    2943:	49 c1 e8 05          	shr    r8,0x5
    2947:	49 83 e0 1f          	and    r8,0x1f
    294b:	4c 01 c6             	add    rsi,r8
    294e:	48 81 c6 f2 00 00 00 	add    rsi,0xf2
    2955:	48 8b 97 a0 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7a0]
    295c:	48 89 d1             	mov    rcx,rdx
    295f:	48 c1 e9 11          	shr    rcx,0x11
    2963:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    296a:	48 01 ce             	add    rsi,rcx
    296d:	49 89 d0             	mov    r8,rdx
    2970:	49 c1 e8 05          	shr    r8,0x5
    2974:	49 83 e0 1f          	and    r8,0x1f
    2978:	4c 01 c6             	add    rsi,r8
    297b:	48 81 c6 f3 00 00 00 	add    rsi,0xf3
    2982:	48 8b 97 a8 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7a8]
    2989:	48 89 d1             	mov    rcx,rdx
    298c:	48 c1 e9 11          	shr    rcx,0x11
    2990:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2997:	48 01 ce             	add    rsi,rcx
    299a:	49 89 d0             	mov    r8,rdx
    299d:	49 c1 e8 05          	shr    r8,0x5
    29a1:	49 83 e0 1f          	and    r8,0x1f
    29a5:	4c 01 c6             	add    rsi,r8
    29a8:	48 81 c6 f4 00 00 00 	add    rsi,0xf4
    29af:	48 8b 97 b0 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7b0]
    29b6:	48 89 d1             	mov    rcx,rdx
    29b9:	48 c1 e9 11          	shr    rcx,0x11
    29bd:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    29c4:	48 01 ce             	add    rsi,rcx
    29c7:	49 89 d0             	mov    r8,rdx
    29ca:	49 c1 e8 05          	shr    r8,0x5
    29ce:	49 83 e0 1f          	and    r8,0x1f
    29d2:	4c 01 c6             	add    rsi,r8
    29d5:	48 81 c6 f5 00 00 00 	add    rsi,0xf5
    29dc:	48 8b 97 b8 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7b8]
    29e3:	48 89 d1             	mov    rcx,rdx
    29e6:	48 c1 e9 11          	shr    rcx,0x11
    29ea:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    29f1:	48 01 ce             	add    rsi,rcx
    29f4:	49 89 d0             	mov    r8,rdx
    29f7:	49 c1 e8 05          	shr    r8,0x5
    29fb:	49 83 e0 1f          	and    r8,0x1f
    29ff:	4c 01 c6             	add    rsi,r8
    2a02:	48 81 c6 f6 00 00 00 	add    rsi,0xf6
    2a09:	48 8b 97 c0 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7c0]
    2a10:	48 89 d1             	mov    rcx,rdx
    2a13:	48 c1 e9 11          	shr    rcx,0x11
    2a17:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2a1e:	48 01 ce             	add    rsi,rcx
    2a21:	49 89 d0             	mov    r8,rdx
    2a24:	49 c1 e8 05          	shr    r8,0x5
    2a28:	49 83 e0 1f          	and    r8,0x1f
    2a2c:	4c 01 c6             	add    rsi,r8
    2a2f:	48 81 c6 f7 00 00 00 	add    rsi,0xf7
    2a36:	48 8b 97 c8 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7c8]
    2a3d:	48 89 d1             	mov    rcx,rdx
    2a40:	48 c1 e9 11          	shr    rcx,0x11
    2a44:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2a4b:	48 01 ce             	add    rsi,rcx
    2a4e:	49 89 d0             	mov    r8,rdx
    2a51:	49 c1 e8 05          	shr    r8,0x5
    2a55:	49 83 e0 1f          	and    r8,0x1f
    2a59:	4c 01 c6             	add    rsi,r8
    2a5c:	48 81 c6 f8 00 00 00 	add    rsi,0xf8
    2a63:	48 8b 97 d0 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7d0]
    2a6a:	48 89 d1             	mov    rcx,rdx
    2a6d:	48 c1 e9 11          	shr    rcx,0x11
    2a71:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2a78:	48 01 ce             	add    rsi,rcx
    2a7b:	49 89 d0             	mov    r8,rdx
    2a7e:	49 c1 e8 05          	shr    r8,0x5
    2a82:	49 83 e0 1f          	and    r8,0x1f
    2a86:	4c 01 c6             	add    rsi,r8
    2a89:	48 81 c6 f9 00 00 00 	add    rsi,0xf9
    2a90:	48 8b 97 d8 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7d8]
    2a97:	48 89 d1             	mov    rcx,rdx
    2a9a:	48 c1 e9 11          	shr    rcx,0x11
    2a9e:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2aa5:	48 01 ce             	add    rsi,rcx
    2aa8:	49 89 d0             	mov    r8,rdx
    2aab:	49 c1 e8 05          	shr    r8,0x5
    2aaf:	49 83 e0 1f          	and    r8,0x1f
    2ab3:	4c 01 c6             	add    rsi,r8
    2ab6:	48 81 c6 fa 00 00 00 	add    rsi,0xfa
    2abd:	48 8b 97 e0 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7e0]
    2ac4:	48 89 d1             	mov    rcx,rdx
    2ac7:	48 c1 e9 11          	shr    rcx,0x11
    2acb:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2ad2:	48 01 ce             	add    rsi,rcx
    2ad5:	49 89 d0             	mov    r8,rdx
    2ad8:	49 c1 e8 05          	shr    r8,0x5
    2adc:	49 83 e0 1f          	and    r8,0x1f
    2ae0:	4c 01 c6             	add    rsi,r8
    2ae3:	48 81 c6 fb 00 00 00 	add    rsi,0xfb
    2aea:	48 8b 97 e8 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7e8]
    2af1:	48 89 d1             	mov    rcx,rdx
    2af4:	48 c1 e9 11          	shr    rcx,0x11
    2af8:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2aff:	48 01 ce             	add    rsi,rcx
    2b02:	49 89 d0             	mov    r8,rdx
    2b05:	49 c1 e8 05          	shr    r8,0x5
    2b09:	49 83 e0 1f          	and    r8,0x1f
    2b0d:	4c 01 c6             	add    rsi,r8
    2b10:	48 81 c6 fc 00 00 00 	add    rsi,0xfc
    2b17:	48 8b 97 f0 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7f0]
    2b1e:	48 89 d1             	mov    rcx,rdx
    2b21:	48 c1 e9 11          	shr    rcx,0x11
    2b25:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2b2c:	48 01 ce             	add    rsi,rcx
    2b2f:	49 89 d0             	mov    r8,rdx
    2b32:	49 c1 e8 05          	shr    r8,0x5
    2b36:	49 83 e0 1f          	and    r8,0x1f
    2b3a:	4c 01 c6             	add    rsi,r8
    2b3d:	48 81 c6 fd 00 00 00 	add    rsi,0xfd
    2b44:	48 8b 97 f8 07 00 00 	mov    rdx,QWORD PTR [rdi+0x7f8]
    2b4b:	48 89 d1             	mov    rcx,rdx
    2b4e:	48 c1 e9 11          	shr    rcx,0x11
    2b52:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2b59:	48 01 ce             	add    rsi,rcx
    2b5c:	49 89 d0             	mov    r8,rdx
    2b5f:	49 c1 e8 05          	shr    r8,0x5
    2b63:	49 83 e0 1f          	and    r8,0x1f
    2b67:	4c 01 c6             	add    rsi,r8
    2b6a:	48 81 c6 fe 00 00 00 	add    rsi,0xfe
    2b71:	48 8b 97 00 08 00 00 	mov    rdx,QWORD PTR [rdi+0x800]
    2b78:	48 89 d1             	mov    rcx,rdx
    2b7b:	48 c1 e9 11          	shr    rcx,0x11
    2b7f:	48 81 e1 ff 03 00 00 	and    rcx,0x3ff
    2b86:	48 01 ce             	add    rsi,rcx
    2b89:	49 89 d0             	mov    r8,rdx
    2b8c:	49 c1 e8 05          	shr    r8,0x5
    2b90:	49 83 e0 1f          	and    r8,0x1f
    2b94:	4c 01 c6             	add    rsi,r8
    2b97:	48 81 c6 ff 00 00 00 	add    rsi,0xff
    2b9e:	48 89 f2             	mov    rdx,rsi
    2ba1:	48 c1 ea 38          	shr    rdx,0x38
    2ba5:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
    2ba8:	48 89 f2             	mov    rdx,rsi
    2bab:	48 c1 ea 30          	shr    rdx,0x30
    2baf:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
    2bb2:	48 89 f2             	mov    rdx,rsi
    2bb5:	48 c1 ea 28          	shr    rdx,0x28
    2bb9:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
    2bbc:	48 89 f2             	mov    rdx,rsi
    2bbf:	48 c1 ea 20          	shr    rdx,0x20
    2bc3:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
    2bc6:	48 89 f2             	mov    rdx,rsi
    2bc9:	48 c1 ea 18          	shr    rdx,0x18
    2bcd:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
    2bd0:	48 89 f2             	mov    rdx,rsi
    2bd3:	48 c1 ea 10          	shr    rdx,0x10
    2bd7:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
    2bda:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
    2bde:	48 c1 ee 08          	shr    rsi,0x8
    2be2:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
    2be6:	b8 02 00 00 00       	mov    eax,0x2
    2beb:	c9                   	leave
    2bec:	c3                   	ret
    2bed:	cc                   	int3
