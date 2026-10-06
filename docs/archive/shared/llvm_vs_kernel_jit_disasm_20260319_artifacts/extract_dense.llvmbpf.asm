
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/extract_dense.llvmbpf.bin:     file format binary


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
      1e:	48 8d 88 08 08 00 00 	lea    rcx,[rax+0x808]
      25:	48 39 f1             	cmp    rcx,rsi
      28:	0f 97 c1             	seta   cl
      2b:	08 d1                	or     cl,dl
      2d:	74 03                	je     0x32
      2f:	31 c0                	xor    eax,eax
      31:	c3                   	ret
      32:	8b 50 08             	mov    edx,DWORD PTR [rax+0x8]
      35:	8b 48 10             	mov    ecx,DWORD PTR [rax+0x10]
      38:	89 d6                	mov    esi,edx
      3a:	c1 ee 05             	shr    esi,0x5
      3d:	83 e6 1f             	and    esi,0x1f
      40:	c1 ea 11             	shr    edx,0x11
      43:	81 e2 ff 03 00 00    	and    edx,0x3ff
      49:	48 01 f2             	add    rdx,rsi
      4c:	89 ce                	mov    esi,ecx
      4e:	c1 ee 11             	shr    esi,0x11
      51:	81 e6 ff 03 00 00    	and    esi,0x3ff
      57:	c1 e9 05             	shr    ecx,0x5
      5a:	83 e1 1f             	and    ecx,0x1f
      5d:	48 01 f1             	add    rcx,rsi
      60:	48 01 d1             	add    rcx,rdx
      63:	8b 70 18             	mov    esi,DWORD PTR [rax+0x18]
      66:	89 f2                	mov    edx,esi
      68:	c1 ea 11             	shr    edx,0x11
      6b:	81 e2 ff 03 00 00    	and    edx,0x3ff
      71:	c1 ee 05             	shr    esi,0x5
      74:	83 e6 1f             	and    esi,0x1f
      77:	48 01 d6             	add    rsi,rdx
      7a:	8b 78 20             	mov    edi,DWORD PTR [rax+0x20]
      7d:	89 fa                	mov    edx,edi
      7f:	c1 ea 11             	shr    edx,0x11
      82:	81 e2 ff 03 00 00    	and    edx,0x3ff
      88:	48 01 f2             	add    rdx,rsi
      8b:	48 01 ca             	add    rdx,rcx
      8e:	c1 ef 05             	shr    edi,0x5
      91:	83 e7 1f             	and    edi,0x1f
      94:	8b 70 28             	mov    esi,DWORD PTR [rax+0x28]
      97:	89 f1                	mov    ecx,esi
      99:	c1 e9 11             	shr    ecx,0x11
      9c:	81 e1 ff 03 00 00    	and    ecx,0x3ff
      a2:	48 01 f9             	add    rcx,rdi
      a5:	c1 ee 05             	shr    esi,0x5
      a8:	83 e6 1f             	and    esi,0x1f
      ab:	48 01 ce             	add    rsi,rcx
      ae:	8b 78 30             	mov    edi,DWORD PTR [rax+0x30]
      b1:	89 f9                	mov    ecx,edi
      b3:	c1 e9 11             	shr    ecx,0x11
      b6:	81 e1 ff 03 00 00    	and    ecx,0x3ff
      bc:	48 01 f1             	add    rcx,rsi
      bf:	48 01 d1             	add    rcx,rdx
      c2:	c1 ef 05             	shr    edi,0x5
      c5:	83 e7 1f             	and    edi,0x1f
      c8:	8b 70 38             	mov    esi,DWORD PTR [rax+0x38]
      cb:	89 f2                	mov    edx,esi
      cd:	c1 ea 11             	shr    edx,0x11
      d0:	81 e2 ff 03 00 00    	and    edx,0x3ff
      d6:	48 01 fa             	add    rdx,rdi
      d9:	c1 ee 05             	shr    esi,0x5
      dc:	83 e6 1f             	and    esi,0x1f
      df:	48 01 d6             	add    rsi,rdx
      e2:	8b 50 40             	mov    edx,DWORD PTR [rax+0x40]
      e5:	89 d7                	mov    edi,edx
      e7:	c1 ef 11             	shr    edi,0x11
      ea:	81 e7 ff 03 00 00    	and    edi,0x3ff
      f0:	48 01 f7             	add    rdi,rsi
      f3:	c1 ea 05             	shr    edx,0x5
      f6:	83 e2 1f             	and    edx,0x1f
      f9:	48 01 fa             	add    rdx,rdi
      fc:	48 01 ca             	add    rdx,rcx
      ff:	8b 48 48             	mov    ecx,DWORD PTR [rax+0x48]
     102:	89 ce                	mov    esi,ecx
     104:	c1 ee 11             	shr    esi,0x11
     107:	81 e6 ff 03 00 00    	and    esi,0x3ff
     10d:	c1 e9 05             	shr    ecx,0x5
     110:	83 e1 1f             	and    ecx,0x1f
     113:	48 01 f1             	add    rcx,rsi
     116:	8b 70 50             	mov    esi,DWORD PTR [rax+0x50]
     119:	89 f7                	mov    edi,esi
     11b:	c1 ef 11             	shr    edi,0x11
     11e:	81 e7 ff 03 00 00    	and    edi,0x3ff
     124:	48 01 cf             	add    rdi,rcx
     127:	c1 ee 05             	shr    esi,0x5
     12a:	83 e6 1f             	and    esi,0x1f
     12d:	48 01 fe             	add    rsi,rdi
     130:	8b 48 58             	mov    ecx,DWORD PTR [rax+0x58]
     133:	89 cf                	mov    edi,ecx
     135:	c1 ef 11             	shr    edi,0x11
     138:	81 e7 ff 03 00 00    	and    edi,0x3ff
     13e:	48 01 f7             	add    rdi,rsi
     141:	c1 e9 05             	shr    ecx,0x5
     144:	83 e1 1f             	and    ecx,0x1f
     147:	48 01 f9             	add    rcx,rdi
     14a:	48 01 d1             	add    rcx,rdx
     14d:	8b 50 60             	mov    edx,DWORD PTR [rax+0x60]
     150:	89 d6                	mov    esi,edx
     152:	c1 ee 11             	shr    esi,0x11
     155:	81 e6 ff 03 00 00    	and    esi,0x3ff
     15b:	c1 ea 05             	shr    edx,0x5
     15e:	83 e2 1f             	and    edx,0x1f
     161:	48 01 f2             	add    rdx,rsi
     164:	8b 70 68             	mov    esi,DWORD PTR [rax+0x68]
     167:	89 f7                	mov    edi,esi
     169:	c1 ef 11             	shr    edi,0x11
     16c:	81 e7 ff 03 00 00    	and    edi,0x3ff
     172:	48 01 d7             	add    rdi,rdx
     175:	c1 ee 05             	shr    esi,0x5
     178:	83 e6 1f             	and    esi,0x1f
     17b:	48 01 fe             	add    rsi,rdi
     17e:	8b 78 70             	mov    edi,DWORD PTR [rax+0x70]
     181:	89 fa                	mov    edx,edi
     183:	c1 ea 11             	shr    edx,0x11
     186:	81 e2 ff 03 00 00    	and    edx,0x3ff
     18c:	48 01 f2             	add    rdx,rsi
     18f:	c1 ef 05             	shr    edi,0x5
     192:	83 e7 1f             	and    edi,0x1f
     195:	48 01 d7             	add    rdi,rdx
     198:	8b 70 78             	mov    esi,DWORD PTR [rax+0x78]
     19b:	89 f2                	mov    edx,esi
     19d:	c1 ea 11             	shr    edx,0x11
     1a0:	81 e2 ff 03 00 00    	and    edx,0x3ff
     1a6:	48 01 fa             	add    rdx,rdi
     1a9:	48 01 ca             	add    rdx,rcx
     1ac:	c1 ee 05             	shr    esi,0x5
     1af:	83 e6 1f             	and    esi,0x1f
     1b2:	8b 88 80 00 00 00    	mov    ecx,DWORD PTR [rax+0x80]
     1b8:	89 cf                	mov    edi,ecx
     1ba:	c1 ef 11             	shr    edi,0x11
     1bd:	81 e7 ff 03 00 00    	and    edi,0x3ff
     1c3:	48 01 f7             	add    rdi,rsi
     1c6:	c1 e9 05             	shr    ecx,0x5
     1c9:	83 e1 1f             	and    ecx,0x1f
     1cc:	48 01 f9             	add    rcx,rdi
     1cf:	8b b0 88 00 00 00    	mov    esi,DWORD PTR [rax+0x88]
     1d5:	89 f7                	mov    edi,esi
     1d7:	c1 ef 11             	shr    edi,0x11
     1da:	81 e7 ff 03 00 00    	and    edi,0x3ff
     1e0:	48 01 cf             	add    rdi,rcx
     1e3:	c1 ee 05             	shr    esi,0x5
     1e6:	83 e6 1f             	and    esi,0x1f
     1e9:	48 01 fe             	add    rsi,rdi
     1ec:	8b b8 90 00 00 00    	mov    edi,DWORD PTR [rax+0x90]
     1f2:	89 f9                	mov    ecx,edi
     1f4:	c1 e9 11             	shr    ecx,0x11
     1f7:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     1fd:	48 01 f1             	add    rcx,rsi
     200:	c1 ef 05             	shr    edi,0x5
     203:	83 e7 1f             	and    edi,0x1f
     206:	48 01 cf             	add    rdi,rcx
     209:	8b b0 98 00 00 00    	mov    esi,DWORD PTR [rax+0x98]
     20f:	89 f1                	mov    ecx,esi
     211:	c1 e9 11             	shr    ecx,0x11
     214:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     21a:	48 01 f9             	add    rcx,rdi
     21d:	48 01 d1             	add    rcx,rdx
     220:	c1 ee 05             	shr    esi,0x5
     223:	83 e6 1f             	and    esi,0x1f
     226:	8b 90 a0 00 00 00    	mov    edx,DWORD PTR [rax+0xa0]
     22c:	89 d7                	mov    edi,edx
     22e:	c1 ef 11             	shr    edi,0x11
     231:	81 e7 ff 03 00 00    	and    edi,0x3ff
     237:	48 01 f7             	add    rdi,rsi
     23a:	c1 ea 05             	shr    edx,0x5
     23d:	83 e2 1f             	and    edx,0x1f
     240:	48 01 fa             	add    rdx,rdi
     243:	8b b0 a8 00 00 00    	mov    esi,DWORD PTR [rax+0xa8]
     249:	89 f7                	mov    edi,esi
     24b:	c1 ef 11             	shr    edi,0x11
     24e:	81 e7 ff 03 00 00    	and    edi,0x3ff
     254:	48 01 d7             	add    rdi,rdx
     257:	c1 ee 05             	shr    esi,0x5
     25a:	83 e6 1f             	and    esi,0x1f
     25d:	48 01 fe             	add    rsi,rdi
     260:	8b b8 b0 00 00 00    	mov    edi,DWORD PTR [rax+0xb0]
     266:	89 fa                	mov    edx,edi
     268:	c1 ea 11             	shr    edx,0x11
     26b:	81 e2 ff 03 00 00    	and    edx,0x3ff
     271:	48 01 f2             	add    rdx,rsi
     274:	c1 ef 05             	shr    edi,0x5
     277:	83 e7 1f             	and    edi,0x1f
     27a:	48 01 d7             	add    rdi,rdx
     27d:	8b 90 b8 00 00 00    	mov    edx,DWORD PTR [rax+0xb8]
     283:	89 d6                	mov    esi,edx
     285:	c1 ee 11             	shr    esi,0x11
     288:	81 e6 ff 03 00 00    	and    esi,0x3ff
     28e:	48 01 fe             	add    rsi,rdi
     291:	c1 ea 05             	shr    edx,0x5
     294:	83 e2 1f             	and    edx,0x1f
     297:	48 01 f2             	add    rdx,rsi
     29a:	48 01 ca             	add    rdx,rcx
     29d:	8b 88 c0 00 00 00    	mov    ecx,DWORD PTR [rax+0xc0]
     2a3:	89 ce                	mov    esi,ecx
     2a5:	c1 ee 11             	shr    esi,0x11
     2a8:	81 e6 ff 03 00 00    	and    esi,0x3ff
     2ae:	c1 e9 05             	shr    ecx,0x5
     2b1:	83 e1 1f             	and    ecx,0x1f
     2b4:	48 01 f1             	add    rcx,rsi
     2b7:	8b b0 c8 00 00 00    	mov    esi,DWORD PTR [rax+0xc8]
     2bd:	89 f7                	mov    edi,esi
     2bf:	c1 ef 11             	shr    edi,0x11
     2c2:	81 e7 ff 03 00 00    	and    edi,0x3ff
     2c8:	48 01 cf             	add    rdi,rcx
     2cb:	c1 ee 05             	shr    esi,0x5
     2ce:	83 e6 1f             	and    esi,0x1f
     2d1:	48 01 fe             	add    rsi,rdi
     2d4:	8b 88 d0 00 00 00    	mov    ecx,DWORD PTR [rax+0xd0]
     2da:	89 cf                	mov    edi,ecx
     2dc:	c1 ef 11             	shr    edi,0x11
     2df:	81 e7 ff 03 00 00    	and    edi,0x3ff
     2e5:	48 01 f7             	add    rdi,rsi
     2e8:	c1 e9 05             	shr    ecx,0x5
     2eb:	83 e1 1f             	and    ecx,0x1f
     2ee:	48 01 f9             	add    rcx,rdi
     2f1:	8b b0 d8 00 00 00    	mov    esi,DWORD PTR [rax+0xd8]
     2f7:	89 f7                	mov    edi,esi
     2f9:	c1 ef 11             	shr    edi,0x11
     2fc:	81 e7 ff 03 00 00    	and    edi,0x3ff
     302:	48 01 cf             	add    rdi,rcx
     305:	c1 ee 05             	shr    esi,0x5
     308:	83 e6 1f             	and    esi,0x1f
     30b:	48 01 fe             	add    rsi,rdi
     30e:	8b 88 e0 00 00 00    	mov    ecx,DWORD PTR [rax+0xe0]
     314:	89 cf                	mov    edi,ecx
     316:	c1 ef 11             	shr    edi,0x11
     319:	81 e7 ff 03 00 00    	and    edi,0x3ff
     31f:	48 01 f7             	add    rdi,rsi
     322:	c1 e9 05             	shr    ecx,0x5
     325:	83 e1 1f             	and    ecx,0x1f
     328:	48 01 f9             	add    rcx,rdi
     32b:	48 01 d1             	add    rcx,rdx
     32e:	8b 90 e8 00 00 00    	mov    edx,DWORD PTR [rax+0xe8]
     334:	89 d6                	mov    esi,edx
     336:	c1 ee 11             	shr    esi,0x11
     339:	81 e6 ff 03 00 00    	and    esi,0x3ff
     33f:	c1 ea 05             	shr    edx,0x5
     342:	83 e2 1f             	and    edx,0x1f
     345:	48 01 f2             	add    rdx,rsi
     348:	8b b0 f0 00 00 00    	mov    esi,DWORD PTR [rax+0xf0]
     34e:	89 f7                	mov    edi,esi
     350:	c1 ef 11             	shr    edi,0x11
     353:	81 e7 ff 03 00 00    	and    edi,0x3ff
     359:	48 01 d7             	add    rdi,rdx
     35c:	c1 ee 05             	shr    esi,0x5
     35f:	83 e6 1f             	and    esi,0x1f
     362:	48 01 fe             	add    rsi,rdi
     365:	8b 90 f8 00 00 00    	mov    edx,DWORD PTR [rax+0xf8]
     36b:	89 d7                	mov    edi,edx
     36d:	c1 ef 11             	shr    edi,0x11
     370:	81 e7 ff 03 00 00    	and    edi,0x3ff
     376:	48 01 f7             	add    rdi,rsi
     379:	c1 ea 05             	shr    edx,0x5
     37c:	83 e2 1f             	and    edx,0x1f
     37f:	48 01 fa             	add    rdx,rdi
     382:	8b b0 00 01 00 00    	mov    esi,DWORD PTR [rax+0x100]
     388:	89 f7                	mov    edi,esi
     38a:	c1 ef 11             	shr    edi,0x11
     38d:	81 e7 ff 03 00 00    	and    edi,0x3ff
     393:	48 01 d7             	add    rdi,rdx
     396:	c1 ee 05             	shr    esi,0x5
     399:	83 e6 1f             	and    esi,0x1f
     39c:	48 01 fe             	add    rsi,rdi
     39f:	8b b8 08 01 00 00    	mov    edi,DWORD PTR [rax+0x108]
     3a5:	89 fa                	mov    edx,edi
     3a7:	c1 ea 11             	shr    edx,0x11
     3aa:	81 e2 ff 03 00 00    	and    edx,0x3ff
     3b0:	48 01 f2             	add    rdx,rsi
     3b3:	c1 ef 05             	shr    edi,0x5
     3b6:	83 e7 1f             	and    edi,0x1f
     3b9:	48 01 d7             	add    rdi,rdx
     3bc:	8b b0 10 01 00 00    	mov    esi,DWORD PTR [rax+0x110]
     3c2:	89 f2                	mov    edx,esi
     3c4:	c1 ea 11             	shr    edx,0x11
     3c7:	81 e2 ff 03 00 00    	and    edx,0x3ff
     3cd:	48 01 fa             	add    rdx,rdi
     3d0:	48 01 ca             	add    rdx,rcx
     3d3:	c1 ee 05             	shr    esi,0x5
     3d6:	83 e6 1f             	and    esi,0x1f
     3d9:	8b 88 18 01 00 00    	mov    ecx,DWORD PTR [rax+0x118]
     3df:	89 cf                	mov    edi,ecx
     3e1:	c1 ef 11             	shr    edi,0x11
     3e4:	81 e7 ff 03 00 00    	and    edi,0x3ff
     3ea:	48 01 f7             	add    rdi,rsi
     3ed:	c1 e9 05             	shr    ecx,0x5
     3f0:	83 e1 1f             	and    ecx,0x1f
     3f3:	48 01 f9             	add    rcx,rdi
     3f6:	8b b0 20 01 00 00    	mov    esi,DWORD PTR [rax+0x120]
     3fc:	89 f7                	mov    edi,esi
     3fe:	c1 ef 11             	shr    edi,0x11
     401:	81 e7 ff 03 00 00    	and    edi,0x3ff
     407:	48 01 cf             	add    rdi,rcx
     40a:	c1 ee 05             	shr    esi,0x5
     40d:	83 e6 1f             	and    esi,0x1f
     410:	48 01 fe             	add    rsi,rdi
     413:	8b 88 28 01 00 00    	mov    ecx,DWORD PTR [rax+0x128]
     419:	89 cf                	mov    edi,ecx
     41b:	c1 ef 11             	shr    edi,0x11
     41e:	81 e7 ff 03 00 00    	and    edi,0x3ff
     424:	48 01 f7             	add    rdi,rsi
     427:	c1 e9 05             	shr    ecx,0x5
     42a:	83 e1 1f             	and    ecx,0x1f
     42d:	48 01 f9             	add    rcx,rdi
     430:	8b b0 30 01 00 00    	mov    esi,DWORD PTR [rax+0x130]
     436:	89 f7                	mov    edi,esi
     438:	c1 ef 11             	shr    edi,0x11
     43b:	81 e7 ff 03 00 00    	and    edi,0x3ff
     441:	48 01 cf             	add    rdi,rcx
     444:	c1 ee 05             	shr    esi,0x5
     447:	83 e6 1f             	and    esi,0x1f
     44a:	48 01 fe             	add    rsi,rdi
     44d:	8b b8 38 01 00 00    	mov    edi,DWORD PTR [rax+0x138]
     453:	89 f9                	mov    ecx,edi
     455:	c1 e9 11             	shr    ecx,0x11
     458:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     45e:	48 01 f1             	add    rcx,rsi
     461:	c1 ef 05             	shr    edi,0x5
     464:	83 e7 1f             	and    edi,0x1f
     467:	48 01 cf             	add    rdi,rcx
     46a:	8b b0 40 01 00 00    	mov    esi,DWORD PTR [rax+0x140]
     470:	89 f1                	mov    ecx,esi
     472:	c1 e9 11             	shr    ecx,0x11
     475:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     47b:	48 01 f9             	add    rcx,rdi
     47e:	48 01 d1             	add    rcx,rdx
     481:	c1 ee 05             	shr    esi,0x5
     484:	83 e6 1f             	and    esi,0x1f
     487:	8b 90 48 01 00 00    	mov    edx,DWORD PTR [rax+0x148]
     48d:	89 d7                	mov    edi,edx
     48f:	c1 ef 11             	shr    edi,0x11
     492:	81 e7 ff 03 00 00    	and    edi,0x3ff
     498:	48 01 f7             	add    rdi,rsi
     49b:	c1 ea 05             	shr    edx,0x5
     49e:	83 e2 1f             	and    edx,0x1f
     4a1:	48 01 fa             	add    rdx,rdi
     4a4:	8b b0 50 01 00 00    	mov    esi,DWORD PTR [rax+0x150]
     4aa:	89 f7                	mov    edi,esi
     4ac:	c1 ef 11             	shr    edi,0x11
     4af:	81 e7 ff 03 00 00    	and    edi,0x3ff
     4b5:	48 01 d7             	add    rdi,rdx
     4b8:	c1 ee 05             	shr    esi,0x5
     4bb:	83 e6 1f             	and    esi,0x1f
     4be:	48 01 fe             	add    rsi,rdi
     4c1:	8b 90 58 01 00 00    	mov    edx,DWORD PTR [rax+0x158]
     4c7:	89 d7                	mov    edi,edx
     4c9:	c1 ef 11             	shr    edi,0x11
     4cc:	81 e7 ff 03 00 00    	and    edi,0x3ff
     4d2:	48 01 f7             	add    rdi,rsi
     4d5:	c1 ea 05             	shr    edx,0x5
     4d8:	83 e2 1f             	and    edx,0x1f
     4db:	48 01 fa             	add    rdx,rdi
     4de:	8b b0 60 01 00 00    	mov    esi,DWORD PTR [rax+0x160]
     4e4:	89 f7                	mov    edi,esi
     4e6:	c1 ef 11             	shr    edi,0x11
     4e9:	81 e7 ff 03 00 00    	and    edi,0x3ff
     4ef:	48 01 d7             	add    rdi,rdx
     4f2:	c1 ee 05             	shr    esi,0x5
     4f5:	83 e6 1f             	and    esi,0x1f
     4f8:	48 01 fe             	add    rsi,rdi
     4fb:	8b b8 68 01 00 00    	mov    edi,DWORD PTR [rax+0x168]
     501:	89 fa                	mov    edx,edi
     503:	c1 ea 11             	shr    edx,0x11
     506:	81 e2 ff 03 00 00    	and    edx,0x3ff
     50c:	48 01 f2             	add    rdx,rsi
     50f:	c1 ef 05             	shr    edi,0x5
     512:	83 e7 1f             	and    edi,0x1f
     515:	48 01 d7             	add    rdi,rdx
     518:	8b 90 70 01 00 00    	mov    edx,DWORD PTR [rax+0x170]
     51e:	89 d6                	mov    esi,edx
     520:	c1 ee 11             	shr    esi,0x11
     523:	81 e6 ff 03 00 00    	and    esi,0x3ff
     529:	48 01 fe             	add    rsi,rdi
     52c:	c1 ea 05             	shr    edx,0x5
     52f:	83 e2 1f             	and    edx,0x1f
     532:	48 01 f2             	add    rdx,rsi
     535:	48 01 ca             	add    rdx,rcx
     538:	8b 88 78 01 00 00    	mov    ecx,DWORD PTR [rax+0x178]
     53e:	89 ce                	mov    esi,ecx
     540:	c1 ee 11             	shr    esi,0x11
     543:	81 e6 ff 03 00 00    	and    esi,0x3ff
     549:	c1 e9 05             	shr    ecx,0x5
     54c:	83 e1 1f             	and    ecx,0x1f
     54f:	48 01 f1             	add    rcx,rsi
     552:	8b b0 80 01 00 00    	mov    esi,DWORD PTR [rax+0x180]
     558:	89 f7                	mov    edi,esi
     55a:	c1 ef 11             	shr    edi,0x11
     55d:	81 e7 ff 03 00 00    	and    edi,0x3ff
     563:	48 01 cf             	add    rdi,rcx
     566:	c1 ee 05             	shr    esi,0x5
     569:	83 e6 1f             	and    esi,0x1f
     56c:	48 01 fe             	add    rsi,rdi
     56f:	8b 88 88 01 00 00    	mov    ecx,DWORD PTR [rax+0x188]
     575:	89 cf                	mov    edi,ecx
     577:	c1 ef 11             	shr    edi,0x11
     57a:	81 e7 ff 03 00 00    	and    edi,0x3ff
     580:	48 01 f7             	add    rdi,rsi
     583:	c1 e9 05             	shr    ecx,0x5
     586:	83 e1 1f             	and    ecx,0x1f
     589:	48 01 f9             	add    rcx,rdi
     58c:	8b b0 90 01 00 00    	mov    esi,DWORD PTR [rax+0x190]
     592:	89 f7                	mov    edi,esi
     594:	c1 ef 11             	shr    edi,0x11
     597:	81 e7 ff 03 00 00    	and    edi,0x3ff
     59d:	48 01 cf             	add    rdi,rcx
     5a0:	c1 ee 05             	shr    esi,0x5
     5a3:	83 e6 1f             	and    esi,0x1f
     5a6:	48 01 fe             	add    rsi,rdi
     5a9:	8b 88 98 01 00 00    	mov    ecx,DWORD PTR [rax+0x198]
     5af:	89 cf                	mov    edi,ecx
     5b1:	c1 ef 11             	shr    edi,0x11
     5b4:	81 e7 ff 03 00 00    	and    edi,0x3ff
     5ba:	48 01 f7             	add    rdi,rsi
     5bd:	c1 e9 05             	shr    ecx,0x5
     5c0:	83 e1 1f             	and    ecx,0x1f
     5c3:	48 01 f9             	add    rcx,rdi
     5c6:	8b b0 a0 01 00 00    	mov    esi,DWORD PTR [rax+0x1a0]
     5cc:	89 f7                	mov    edi,esi
     5ce:	c1 ef 11             	shr    edi,0x11
     5d1:	81 e7 ff 03 00 00    	and    edi,0x3ff
     5d7:	48 01 cf             	add    rdi,rcx
     5da:	c1 ee 05             	shr    esi,0x5
     5dd:	83 e6 1f             	and    esi,0x1f
     5e0:	48 01 fe             	add    rsi,rdi
     5e3:	8b 88 a8 01 00 00    	mov    ecx,DWORD PTR [rax+0x1a8]
     5e9:	89 cf                	mov    edi,ecx
     5eb:	c1 ef 11             	shr    edi,0x11
     5ee:	81 e7 ff 03 00 00    	and    edi,0x3ff
     5f4:	48 01 f7             	add    rdi,rsi
     5f7:	c1 e9 05             	shr    ecx,0x5
     5fa:	83 e1 1f             	and    ecx,0x1f
     5fd:	48 01 f9             	add    rcx,rdi
     600:	48 01 d1             	add    rcx,rdx
     603:	8b 90 b0 01 00 00    	mov    edx,DWORD PTR [rax+0x1b0]
     609:	89 d6                	mov    esi,edx
     60b:	c1 ee 11             	shr    esi,0x11
     60e:	81 e6 ff 03 00 00    	and    esi,0x3ff
     614:	c1 ea 05             	shr    edx,0x5
     617:	83 e2 1f             	and    edx,0x1f
     61a:	48 01 f2             	add    rdx,rsi
     61d:	8b b0 b8 01 00 00    	mov    esi,DWORD PTR [rax+0x1b8]
     623:	89 f7                	mov    edi,esi
     625:	c1 ef 11             	shr    edi,0x11
     628:	81 e7 ff 03 00 00    	and    edi,0x3ff
     62e:	48 01 d7             	add    rdi,rdx
     631:	c1 ee 05             	shr    esi,0x5
     634:	83 e6 1f             	and    esi,0x1f
     637:	48 01 fe             	add    rsi,rdi
     63a:	8b 90 c0 01 00 00    	mov    edx,DWORD PTR [rax+0x1c0]
     640:	89 d7                	mov    edi,edx
     642:	c1 ef 11             	shr    edi,0x11
     645:	81 e7 ff 03 00 00    	and    edi,0x3ff
     64b:	48 01 f7             	add    rdi,rsi
     64e:	c1 ea 05             	shr    edx,0x5
     651:	83 e2 1f             	and    edx,0x1f
     654:	48 01 fa             	add    rdx,rdi
     657:	8b b0 c8 01 00 00    	mov    esi,DWORD PTR [rax+0x1c8]
     65d:	89 f7                	mov    edi,esi
     65f:	c1 ef 11             	shr    edi,0x11
     662:	81 e7 ff 03 00 00    	and    edi,0x3ff
     668:	48 01 d7             	add    rdi,rdx
     66b:	c1 ee 05             	shr    esi,0x5
     66e:	83 e6 1f             	and    esi,0x1f
     671:	48 01 fe             	add    rsi,rdi
     674:	8b 90 d0 01 00 00    	mov    edx,DWORD PTR [rax+0x1d0]
     67a:	89 d7                	mov    edi,edx
     67c:	c1 ef 11             	shr    edi,0x11
     67f:	81 e7 ff 03 00 00    	and    edi,0x3ff
     685:	48 01 f7             	add    rdi,rsi
     688:	c1 ea 05             	shr    edx,0x5
     68b:	83 e2 1f             	and    edx,0x1f
     68e:	48 01 fa             	add    rdx,rdi
     691:	8b b0 d8 01 00 00    	mov    esi,DWORD PTR [rax+0x1d8]
     697:	89 f7                	mov    edi,esi
     699:	c1 ef 11             	shr    edi,0x11
     69c:	81 e7 ff 03 00 00    	and    edi,0x3ff
     6a2:	48 01 d7             	add    rdi,rdx
     6a5:	c1 ee 05             	shr    esi,0x5
     6a8:	83 e6 1f             	and    esi,0x1f
     6ab:	48 01 fe             	add    rsi,rdi
     6ae:	8b b8 e0 01 00 00    	mov    edi,DWORD PTR [rax+0x1e0]
     6b4:	89 fa                	mov    edx,edi
     6b6:	c1 ea 11             	shr    edx,0x11
     6b9:	81 e2 ff 03 00 00    	and    edx,0x3ff
     6bf:	48 01 f2             	add    rdx,rsi
     6c2:	c1 ef 05             	shr    edi,0x5
     6c5:	83 e7 1f             	and    edi,0x1f
     6c8:	48 01 d7             	add    rdi,rdx
     6cb:	8b b0 e8 01 00 00    	mov    esi,DWORD PTR [rax+0x1e8]
     6d1:	89 f2                	mov    edx,esi
     6d3:	c1 ea 11             	shr    edx,0x11
     6d6:	81 e2 ff 03 00 00    	and    edx,0x3ff
     6dc:	48 01 fa             	add    rdx,rdi
     6df:	48 01 ca             	add    rdx,rcx
     6e2:	c1 ee 05             	shr    esi,0x5
     6e5:	83 e6 1f             	and    esi,0x1f
     6e8:	8b 88 f0 01 00 00    	mov    ecx,DWORD PTR [rax+0x1f0]
     6ee:	89 cf                	mov    edi,ecx
     6f0:	c1 ef 11             	shr    edi,0x11
     6f3:	81 e7 ff 03 00 00    	and    edi,0x3ff
     6f9:	48 01 f7             	add    rdi,rsi
     6fc:	c1 e9 05             	shr    ecx,0x5
     6ff:	83 e1 1f             	and    ecx,0x1f
     702:	48 01 f9             	add    rcx,rdi
     705:	8b b0 f8 01 00 00    	mov    esi,DWORD PTR [rax+0x1f8]
     70b:	89 f7                	mov    edi,esi
     70d:	c1 ef 11             	shr    edi,0x11
     710:	81 e7 ff 03 00 00    	and    edi,0x3ff
     716:	48 01 cf             	add    rdi,rcx
     719:	c1 ee 05             	shr    esi,0x5
     71c:	83 e6 1f             	and    esi,0x1f
     71f:	48 01 fe             	add    rsi,rdi
     722:	8b 88 00 02 00 00    	mov    ecx,DWORD PTR [rax+0x200]
     728:	89 cf                	mov    edi,ecx
     72a:	c1 ef 11             	shr    edi,0x11
     72d:	81 e7 ff 03 00 00    	and    edi,0x3ff
     733:	48 01 f7             	add    rdi,rsi
     736:	c1 e9 05             	shr    ecx,0x5
     739:	83 e1 1f             	and    ecx,0x1f
     73c:	48 01 f9             	add    rcx,rdi
     73f:	8b b0 08 02 00 00    	mov    esi,DWORD PTR [rax+0x208]
     745:	89 f7                	mov    edi,esi
     747:	c1 ef 11             	shr    edi,0x11
     74a:	81 e7 ff 03 00 00    	and    edi,0x3ff
     750:	48 01 cf             	add    rdi,rcx
     753:	c1 ee 05             	shr    esi,0x5
     756:	83 e6 1f             	and    esi,0x1f
     759:	48 01 fe             	add    rsi,rdi
     75c:	8b 88 10 02 00 00    	mov    ecx,DWORD PTR [rax+0x210]
     762:	89 cf                	mov    edi,ecx
     764:	c1 ef 11             	shr    edi,0x11
     767:	81 e7 ff 03 00 00    	and    edi,0x3ff
     76d:	48 01 f7             	add    rdi,rsi
     770:	c1 e9 05             	shr    ecx,0x5
     773:	83 e1 1f             	and    ecx,0x1f
     776:	48 01 f9             	add    rcx,rdi
     779:	8b b0 18 02 00 00    	mov    esi,DWORD PTR [rax+0x218]
     77f:	89 f7                	mov    edi,esi
     781:	c1 ef 11             	shr    edi,0x11
     784:	81 e7 ff 03 00 00    	and    edi,0x3ff
     78a:	48 01 cf             	add    rdi,rcx
     78d:	c1 ee 05             	shr    esi,0x5
     790:	83 e6 1f             	and    esi,0x1f
     793:	48 01 fe             	add    rsi,rdi
     796:	8b b8 20 02 00 00    	mov    edi,DWORD PTR [rax+0x220]
     79c:	89 f9                	mov    ecx,edi
     79e:	c1 e9 11             	shr    ecx,0x11
     7a1:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     7a7:	48 01 f1             	add    rcx,rsi
     7aa:	c1 ef 05             	shr    edi,0x5
     7ad:	83 e7 1f             	and    edi,0x1f
     7b0:	48 01 cf             	add    rdi,rcx
     7b3:	8b b0 28 02 00 00    	mov    esi,DWORD PTR [rax+0x228]
     7b9:	89 f1                	mov    ecx,esi
     7bb:	c1 e9 11             	shr    ecx,0x11
     7be:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     7c4:	48 01 f9             	add    rcx,rdi
     7c7:	48 01 d1             	add    rcx,rdx
     7ca:	c1 ee 05             	shr    esi,0x5
     7cd:	83 e6 1f             	and    esi,0x1f
     7d0:	8b 90 30 02 00 00    	mov    edx,DWORD PTR [rax+0x230]
     7d6:	89 d7                	mov    edi,edx
     7d8:	c1 ef 11             	shr    edi,0x11
     7db:	81 e7 ff 03 00 00    	and    edi,0x3ff
     7e1:	48 01 f7             	add    rdi,rsi
     7e4:	c1 ea 05             	shr    edx,0x5
     7e7:	83 e2 1f             	and    edx,0x1f
     7ea:	48 01 fa             	add    rdx,rdi
     7ed:	8b b0 38 02 00 00    	mov    esi,DWORD PTR [rax+0x238]
     7f3:	89 f7                	mov    edi,esi
     7f5:	c1 ef 11             	shr    edi,0x11
     7f8:	81 e7 ff 03 00 00    	and    edi,0x3ff
     7fe:	48 01 d7             	add    rdi,rdx
     801:	c1 ee 05             	shr    esi,0x5
     804:	83 e6 1f             	and    esi,0x1f
     807:	48 01 fe             	add    rsi,rdi
     80a:	8b 90 40 02 00 00    	mov    edx,DWORD PTR [rax+0x240]
     810:	89 d7                	mov    edi,edx
     812:	c1 ef 11             	shr    edi,0x11
     815:	81 e7 ff 03 00 00    	and    edi,0x3ff
     81b:	48 01 f7             	add    rdi,rsi
     81e:	c1 ea 05             	shr    edx,0x5
     821:	83 e2 1f             	and    edx,0x1f
     824:	48 01 fa             	add    rdx,rdi
     827:	8b b0 48 02 00 00    	mov    esi,DWORD PTR [rax+0x248]
     82d:	89 f7                	mov    edi,esi
     82f:	c1 ef 11             	shr    edi,0x11
     832:	81 e7 ff 03 00 00    	and    edi,0x3ff
     838:	48 01 d7             	add    rdi,rdx
     83b:	c1 ee 05             	shr    esi,0x5
     83e:	83 e6 1f             	and    esi,0x1f
     841:	48 01 fe             	add    rsi,rdi
     844:	8b 90 50 02 00 00    	mov    edx,DWORD PTR [rax+0x250]
     84a:	89 d7                	mov    edi,edx
     84c:	c1 ef 11             	shr    edi,0x11
     84f:	81 e7 ff 03 00 00    	and    edi,0x3ff
     855:	48 01 f7             	add    rdi,rsi
     858:	c1 ea 05             	shr    edx,0x5
     85b:	83 e2 1f             	and    edx,0x1f
     85e:	48 01 fa             	add    rdx,rdi
     861:	8b b0 58 02 00 00    	mov    esi,DWORD PTR [rax+0x258]
     867:	89 f7                	mov    edi,esi
     869:	c1 ef 11             	shr    edi,0x11
     86c:	81 e7 ff 03 00 00    	and    edi,0x3ff
     872:	48 01 d7             	add    rdi,rdx
     875:	c1 ee 05             	shr    esi,0x5
     878:	83 e6 1f             	and    esi,0x1f
     87b:	48 01 fe             	add    rsi,rdi
     87e:	8b b8 60 02 00 00    	mov    edi,DWORD PTR [rax+0x260]
     884:	89 fa                	mov    edx,edi
     886:	c1 ea 11             	shr    edx,0x11
     889:	81 e2 ff 03 00 00    	and    edx,0x3ff
     88f:	48 01 f2             	add    rdx,rsi
     892:	c1 ef 05             	shr    edi,0x5
     895:	83 e7 1f             	and    edi,0x1f
     898:	48 01 d7             	add    rdi,rdx
     89b:	8b 90 68 02 00 00    	mov    edx,DWORD PTR [rax+0x268]
     8a1:	89 d6                	mov    esi,edx
     8a3:	c1 ee 11             	shr    esi,0x11
     8a6:	81 e6 ff 03 00 00    	and    esi,0x3ff
     8ac:	48 01 fe             	add    rsi,rdi
     8af:	c1 ea 05             	shr    edx,0x5
     8b2:	83 e2 1f             	and    edx,0x1f
     8b5:	48 01 f2             	add    rdx,rsi
     8b8:	48 01 ca             	add    rdx,rcx
     8bb:	8b 88 70 02 00 00    	mov    ecx,DWORD PTR [rax+0x270]
     8c1:	89 ce                	mov    esi,ecx
     8c3:	c1 ee 11             	shr    esi,0x11
     8c6:	81 e6 ff 03 00 00    	and    esi,0x3ff
     8cc:	c1 e9 05             	shr    ecx,0x5
     8cf:	83 e1 1f             	and    ecx,0x1f
     8d2:	48 01 f1             	add    rcx,rsi
     8d5:	8b b0 78 02 00 00    	mov    esi,DWORD PTR [rax+0x278]
     8db:	89 f7                	mov    edi,esi
     8dd:	c1 ef 11             	shr    edi,0x11
     8e0:	81 e7 ff 03 00 00    	and    edi,0x3ff
     8e6:	48 01 cf             	add    rdi,rcx
     8e9:	c1 ee 05             	shr    esi,0x5
     8ec:	83 e6 1f             	and    esi,0x1f
     8ef:	48 01 fe             	add    rsi,rdi
     8f2:	8b 88 80 02 00 00    	mov    ecx,DWORD PTR [rax+0x280]
     8f8:	89 cf                	mov    edi,ecx
     8fa:	c1 ef 11             	shr    edi,0x11
     8fd:	81 e7 ff 03 00 00    	and    edi,0x3ff
     903:	48 01 f7             	add    rdi,rsi
     906:	c1 e9 05             	shr    ecx,0x5
     909:	83 e1 1f             	and    ecx,0x1f
     90c:	48 01 f9             	add    rcx,rdi
     90f:	8b b0 88 02 00 00    	mov    esi,DWORD PTR [rax+0x288]
     915:	89 f7                	mov    edi,esi
     917:	c1 ef 11             	shr    edi,0x11
     91a:	81 e7 ff 03 00 00    	and    edi,0x3ff
     920:	48 01 cf             	add    rdi,rcx
     923:	c1 ee 05             	shr    esi,0x5
     926:	83 e6 1f             	and    esi,0x1f
     929:	48 01 fe             	add    rsi,rdi
     92c:	8b 88 90 02 00 00    	mov    ecx,DWORD PTR [rax+0x290]
     932:	89 cf                	mov    edi,ecx
     934:	c1 ef 11             	shr    edi,0x11
     937:	81 e7 ff 03 00 00    	and    edi,0x3ff
     93d:	48 01 f7             	add    rdi,rsi
     940:	c1 e9 05             	shr    ecx,0x5
     943:	83 e1 1f             	and    ecx,0x1f
     946:	48 01 f9             	add    rcx,rdi
     949:	8b b0 98 02 00 00    	mov    esi,DWORD PTR [rax+0x298]
     94f:	89 f7                	mov    edi,esi
     951:	c1 ef 11             	shr    edi,0x11
     954:	81 e7 ff 03 00 00    	and    edi,0x3ff
     95a:	48 01 cf             	add    rdi,rcx
     95d:	c1 ee 05             	shr    esi,0x5
     960:	83 e6 1f             	and    esi,0x1f
     963:	48 01 fe             	add    rsi,rdi
     966:	8b 88 a0 02 00 00    	mov    ecx,DWORD PTR [rax+0x2a0]
     96c:	89 cf                	mov    edi,ecx
     96e:	c1 ef 11             	shr    edi,0x11
     971:	81 e7 ff 03 00 00    	and    edi,0x3ff
     977:	48 01 f7             	add    rdi,rsi
     97a:	c1 e9 05             	shr    ecx,0x5
     97d:	83 e1 1f             	and    ecx,0x1f
     980:	48 01 f9             	add    rcx,rdi
     983:	8b b0 a8 02 00 00    	mov    esi,DWORD PTR [rax+0x2a8]
     989:	89 f7                	mov    edi,esi
     98b:	c1 ef 11             	shr    edi,0x11
     98e:	81 e7 ff 03 00 00    	and    edi,0x3ff
     994:	48 01 cf             	add    rdi,rcx
     997:	c1 ee 05             	shr    esi,0x5
     99a:	83 e6 1f             	and    esi,0x1f
     99d:	48 01 fe             	add    rsi,rdi
     9a0:	8b 88 b0 02 00 00    	mov    ecx,DWORD PTR [rax+0x2b0]
     9a6:	89 cf                	mov    edi,ecx
     9a8:	c1 ef 11             	shr    edi,0x11
     9ab:	81 e7 ff 03 00 00    	and    edi,0x3ff
     9b1:	48 01 f7             	add    rdi,rsi
     9b4:	c1 e9 05             	shr    ecx,0x5
     9b7:	83 e1 1f             	and    ecx,0x1f
     9ba:	48 01 f9             	add    rcx,rdi
     9bd:	48 01 d1             	add    rcx,rdx
     9c0:	8b 90 b8 02 00 00    	mov    edx,DWORD PTR [rax+0x2b8]
     9c6:	89 d6                	mov    esi,edx
     9c8:	c1 ee 11             	shr    esi,0x11
     9cb:	81 e6 ff 03 00 00    	and    esi,0x3ff
     9d1:	c1 ea 05             	shr    edx,0x5
     9d4:	83 e2 1f             	and    edx,0x1f
     9d7:	48 01 f2             	add    rdx,rsi
     9da:	8b b0 c0 02 00 00    	mov    esi,DWORD PTR [rax+0x2c0]
     9e0:	89 f7                	mov    edi,esi
     9e2:	c1 ef 11             	shr    edi,0x11
     9e5:	81 e7 ff 03 00 00    	and    edi,0x3ff
     9eb:	48 01 d7             	add    rdi,rdx
     9ee:	c1 ee 05             	shr    esi,0x5
     9f1:	83 e6 1f             	and    esi,0x1f
     9f4:	48 01 fe             	add    rsi,rdi
     9f7:	8b 90 c8 02 00 00    	mov    edx,DWORD PTR [rax+0x2c8]
     9fd:	89 d7                	mov    edi,edx
     9ff:	c1 ef 11             	shr    edi,0x11
     a02:	81 e7 ff 03 00 00    	and    edi,0x3ff
     a08:	48 01 f7             	add    rdi,rsi
     a0b:	c1 ea 05             	shr    edx,0x5
     a0e:	83 e2 1f             	and    edx,0x1f
     a11:	48 01 fa             	add    rdx,rdi
     a14:	8b b0 d0 02 00 00    	mov    esi,DWORD PTR [rax+0x2d0]
     a1a:	89 f7                	mov    edi,esi
     a1c:	c1 ef 11             	shr    edi,0x11
     a1f:	81 e7 ff 03 00 00    	and    edi,0x3ff
     a25:	48 01 d7             	add    rdi,rdx
     a28:	c1 ee 05             	shr    esi,0x5
     a2b:	83 e6 1f             	and    esi,0x1f
     a2e:	48 01 fe             	add    rsi,rdi
     a31:	8b 90 d8 02 00 00    	mov    edx,DWORD PTR [rax+0x2d8]
     a37:	89 d7                	mov    edi,edx
     a39:	c1 ef 11             	shr    edi,0x11
     a3c:	81 e7 ff 03 00 00    	and    edi,0x3ff
     a42:	48 01 f7             	add    rdi,rsi
     a45:	c1 ea 05             	shr    edx,0x5
     a48:	83 e2 1f             	and    edx,0x1f
     a4b:	48 01 fa             	add    rdx,rdi
     a4e:	8b b0 e0 02 00 00    	mov    esi,DWORD PTR [rax+0x2e0]
     a54:	89 f7                	mov    edi,esi
     a56:	c1 ef 11             	shr    edi,0x11
     a59:	81 e7 ff 03 00 00    	and    edi,0x3ff
     a5f:	48 01 d7             	add    rdi,rdx
     a62:	c1 ee 05             	shr    esi,0x5
     a65:	83 e6 1f             	and    esi,0x1f
     a68:	48 01 fe             	add    rsi,rdi
     a6b:	8b 90 e8 02 00 00    	mov    edx,DWORD PTR [rax+0x2e8]
     a71:	89 d7                	mov    edi,edx
     a73:	c1 ef 11             	shr    edi,0x11
     a76:	81 e7 ff 03 00 00    	and    edi,0x3ff
     a7c:	48 01 f7             	add    rdi,rsi
     a7f:	c1 ea 05             	shr    edx,0x5
     a82:	83 e2 1f             	and    edx,0x1f
     a85:	48 01 fa             	add    rdx,rdi
     a88:	8b b0 f0 02 00 00    	mov    esi,DWORD PTR [rax+0x2f0]
     a8e:	89 f7                	mov    edi,esi
     a90:	c1 ef 11             	shr    edi,0x11
     a93:	81 e7 ff 03 00 00    	and    edi,0x3ff
     a99:	48 01 d7             	add    rdi,rdx
     a9c:	c1 ee 05             	shr    esi,0x5
     a9f:	83 e6 1f             	and    esi,0x1f
     aa2:	48 01 fe             	add    rsi,rdi
     aa5:	8b b8 f8 02 00 00    	mov    edi,DWORD PTR [rax+0x2f8]
     aab:	89 fa                	mov    edx,edi
     aad:	c1 ea 11             	shr    edx,0x11
     ab0:	81 e2 ff 03 00 00    	and    edx,0x3ff
     ab6:	48 01 f2             	add    rdx,rsi
     ab9:	c1 ef 05             	shr    edi,0x5
     abc:	83 e7 1f             	and    edi,0x1f
     abf:	48 01 d7             	add    rdi,rdx
     ac2:	8b b0 00 03 00 00    	mov    esi,DWORD PTR [rax+0x300]
     ac8:	89 f2                	mov    edx,esi
     aca:	c1 ea 11             	shr    edx,0x11
     acd:	81 e2 ff 03 00 00    	and    edx,0x3ff
     ad3:	48 01 fa             	add    rdx,rdi
     ad6:	48 01 ca             	add    rdx,rcx
     ad9:	c1 ee 05             	shr    esi,0x5
     adc:	83 e6 1f             	and    esi,0x1f
     adf:	8b 88 08 03 00 00    	mov    ecx,DWORD PTR [rax+0x308]
     ae5:	89 cf                	mov    edi,ecx
     ae7:	c1 ef 11             	shr    edi,0x11
     aea:	81 e7 ff 03 00 00    	and    edi,0x3ff
     af0:	48 01 f7             	add    rdi,rsi
     af3:	c1 e9 05             	shr    ecx,0x5
     af6:	83 e1 1f             	and    ecx,0x1f
     af9:	48 01 f9             	add    rcx,rdi
     afc:	8b b0 10 03 00 00    	mov    esi,DWORD PTR [rax+0x310]
     b02:	89 f7                	mov    edi,esi
     b04:	c1 ef 11             	shr    edi,0x11
     b07:	81 e7 ff 03 00 00    	and    edi,0x3ff
     b0d:	48 01 cf             	add    rdi,rcx
     b10:	c1 ee 05             	shr    esi,0x5
     b13:	83 e6 1f             	and    esi,0x1f
     b16:	48 01 fe             	add    rsi,rdi
     b19:	8b 88 18 03 00 00    	mov    ecx,DWORD PTR [rax+0x318]
     b1f:	89 cf                	mov    edi,ecx
     b21:	c1 ef 11             	shr    edi,0x11
     b24:	81 e7 ff 03 00 00    	and    edi,0x3ff
     b2a:	48 01 f7             	add    rdi,rsi
     b2d:	c1 e9 05             	shr    ecx,0x5
     b30:	83 e1 1f             	and    ecx,0x1f
     b33:	48 01 f9             	add    rcx,rdi
     b36:	8b b0 20 03 00 00    	mov    esi,DWORD PTR [rax+0x320]
     b3c:	89 f7                	mov    edi,esi
     b3e:	c1 ef 11             	shr    edi,0x11
     b41:	81 e7 ff 03 00 00    	and    edi,0x3ff
     b47:	48 01 cf             	add    rdi,rcx
     b4a:	c1 ee 05             	shr    esi,0x5
     b4d:	83 e6 1f             	and    esi,0x1f
     b50:	48 01 fe             	add    rsi,rdi
     b53:	8b 88 28 03 00 00    	mov    ecx,DWORD PTR [rax+0x328]
     b59:	89 cf                	mov    edi,ecx
     b5b:	c1 ef 11             	shr    edi,0x11
     b5e:	81 e7 ff 03 00 00    	and    edi,0x3ff
     b64:	48 01 f7             	add    rdi,rsi
     b67:	c1 e9 05             	shr    ecx,0x5
     b6a:	83 e1 1f             	and    ecx,0x1f
     b6d:	48 01 f9             	add    rcx,rdi
     b70:	8b b0 30 03 00 00    	mov    esi,DWORD PTR [rax+0x330]
     b76:	89 f7                	mov    edi,esi
     b78:	c1 ef 11             	shr    edi,0x11
     b7b:	81 e7 ff 03 00 00    	and    edi,0x3ff
     b81:	48 01 cf             	add    rdi,rcx
     b84:	c1 ee 05             	shr    esi,0x5
     b87:	83 e6 1f             	and    esi,0x1f
     b8a:	48 01 fe             	add    rsi,rdi
     b8d:	8b 88 38 03 00 00    	mov    ecx,DWORD PTR [rax+0x338]
     b93:	89 cf                	mov    edi,ecx
     b95:	c1 ef 11             	shr    edi,0x11
     b98:	81 e7 ff 03 00 00    	and    edi,0x3ff
     b9e:	48 01 f7             	add    rdi,rsi
     ba1:	c1 e9 05             	shr    ecx,0x5
     ba4:	83 e1 1f             	and    ecx,0x1f
     ba7:	48 01 f9             	add    rcx,rdi
     baa:	8b b0 40 03 00 00    	mov    esi,DWORD PTR [rax+0x340]
     bb0:	89 f7                	mov    edi,esi
     bb2:	c1 ef 11             	shr    edi,0x11
     bb5:	81 e7 ff 03 00 00    	and    edi,0x3ff
     bbb:	48 01 cf             	add    rdi,rcx
     bbe:	c1 ee 05             	shr    esi,0x5
     bc1:	83 e6 1f             	and    esi,0x1f
     bc4:	48 01 fe             	add    rsi,rdi
     bc7:	8b b8 48 03 00 00    	mov    edi,DWORD PTR [rax+0x348]
     bcd:	89 f9                	mov    ecx,edi
     bcf:	c1 e9 11             	shr    ecx,0x11
     bd2:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     bd8:	48 01 f1             	add    rcx,rsi
     bdb:	c1 ef 05             	shr    edi,0x5
     bde:	83 e7 1f             	and    edi,0x1f
     be1:	48 01 cf             	add    rdi,rcx
     be4:	8b b0 50 03 00 00    	mov    esi,DWORD PTR [rax+0x350]
     bea:	89 f1                	mov    ecx,esi
     bec:	c1 e9 11             	shr    ecx,0x11
     bef:	81 e1 ff 03 00 00    	and    ecx,0x3ff
     bf5:	48 01 f9             	add    rcx,rdi
     bf8:	48 01 d1             	add    rcx,rdx
     bfb:	c1 ee 05             	shr    esi,0x5
     bfe:	83 e6 1f             	and    esi,0x1f
     c01:	8b 90 58 03 00 00    	mov    edx,DWORD PTR [rax+0x358]
     c07:	89 d7                	mov    edi,edx
     c09:	c1 ef 11             	shr    edi,0x11
     c0c:	81 e7 ff 03 00 00    	and    edi,0x3ff
     c12:	48 01 f7             	add    rdi,rsi
     c15:	c1 ea 05             	shr    edx,0x5
     c18:	83 e2 1f             	and    edx,0x1f
     c1b:	48 01 fa             	add    rdx,rdi
     c1e:	8b b0 60 03 00 00    	mov    esi,DWORD PTR [rax+0x360]
     c24:	89 f7                	mov    edi,esi
     c26:	c1 ef 11             	shr    edi,0x11
     c29:	81 e7 ff 03 00 00    	and    edi,0x3ff
     c2f:	48 01 d7             	add    rdi,rdx
     c32:	c1 ee 05             	shr    esi,0x5
     c35:	83 e6 1f             	and    esi,0x1f
     c38:	48 01 fe             	add    rsi,rdi
     c3b:	8b 90 68 03 00 00    	mov    edx,DWORD PTR [rax+0x368]
     c41:	89 d7                	mov    edi,edx
     c43:	c1 ef 11             	shr    edi,0x11
     c46:	81 e7 ff 03 00 00    	and    edi,0x3ff
     c4c:	48 01 f7             	add    rdi,rsi
     c4f:	c1 ea 05             	shr    edx,0x5
     c52:	83 e2 1f             	and    edx,0x1f
     c55:	48 01 fa             	add    rdx,rdi
     c58:	8b b0 70 03 00 00    	mov    esi,DWORD PTR [rax+0x370]
     c5e:	89 f7                	mov    edi,esi
     c60:	c1 ef 11             	shr    edi,0x11
     c63:	81 e7 ff 03 00 00    	and    edi,0x3ff
     c69:	48 01 d7             	add    rdi,rdx
     c6c:	c1 ee 05             	shr    esi,0x5
     c6f:	83 e6 1f             	and    esi,0x1f
     c72:	48 01 fe             	add    rsi,rdi
     c75:	8b 90 78 03 00 00    	mov    edx,DWORD PTR [rax+0x378]
     c7b:	89 d7                	mov    edi,edx
     c7d:	c1 ef 11             	shr    edi,0x11
     c80:	81 e7 ff 03 00 00    	and    edi,0x3ff
     c86:	48 01 f7             	add    rdi,rsi
     c89:	c1 ea 05             	shr    edx,0x5
     c8c:	83 e2 1f             	and    edx,0x1f
     c8f:	48 01 fa             	add    rdx,rdi
     c92:	8b b0 80 03 00 00    	mov    esi,DWORD PTR [rax+0x380]
     c98:	89 f7                	mov    edi,esi
     c9a:	c1 ef 11             	shr    edi,0x11
     c9d:	81 e7 ff 03 00 00    	and    edi,0x3ff
     ca3:	48 01 d7             	add    rdi,rdx
     ca6:	c1 ee 05             	shr    esi,0x5
     ca9:	83 e6 1f             	and    esi,0x1f
     cac:	48 01 fe             	add    rsi,rdi
     caf:	8b 90 88 03 00 00    	mov    edx,DWORD PTR [rax+0x388]
     cb5:	89 d7                	mov    edi,edx
     cb7:	c1 ef 11             	shr    edi,0x11
     cba:	81 e7 ff 03 00 00    	and    edi,0x3ff
     cc0:	48 01 f7             	add    rdi,rsi
     cc3:	c1 ea 05             	shr    edx,0x5
     cc6:	83 e2 1f             	and    edx,0x1f
     cc9:	48 01 fa             	add    rdx,rdi
     ccc:	8b b0 90 03 00 00    	mov    esi,DWORD PTR [rax+0x390]
     cd2:	89 f7                	mov    edi,esi
     cd4:	c1 ef 11             	shr    edi,0x11
     cd7:	81 e7 ff 03 00 00    	and    edi,0x3ff
     cdd:	48 01 d7             	add    rdi,rdx
     ce0:	c1 ee 05             	shr    esi,0x5
     ce3:	83 e6 1f             	and    esi,0x1f
     ce6:	48 01 fe             	add    rsi,rdi
     ce9:	8b b8 98 03 00 00    	mov    edi,DWORD PTR [rax+0x398]
     cef:	89 fa                	mov    edx,edi
     cf1:	c1 ea 11             	shr    edx,0x11
     cf4:	81 e2 ff 03 00 00    	and    edx,0x3ff
     cfa:	48 01 f2             	add    rdx,rsi
     cfd:	c1 ef 05             	shr    edi,0x5
     d00:	83 e7 1f             	and    edi,0x1f
     d03:	48 01 d7             	add    rdi,rdx
     d06:	8b 90 a0 03 00 00    	mov    edx,DWORD PTR [rax+0x3a0]
     d0c:	89 d6                	mov    esi,edx
     d0e:	c1 ee 11             	shr    esi,0x11
     d11:	81 e6 ff 03 00 00    	and    esi,0x3ff
     d17:	48 01 fe             	add    rsi,rdi
     d1a:	c1 ea 05             	shr    edx,0x5
     d1d:	83 e2 1f             	and    edx,0x1f
     d20:	48 01 f2             	add    rdx,rsi
     d23:	48 01 ca             	add    rdx,rcx
     d26:	8b 88 a8 03 00 00    	mov    ecx,DWORD PTR [rax+0x3a8]
     d2c:	89 ce                	mov    esi,ecx
     d2e:	c1 ee 11             	shr    esi,0x11
     d31:	81 e6 ff 03 00 00    	and    esi,0x3ff
     d37:	c1 e9 05             	shr    ecx,0x5
     d3a:	83 e1 1f             	and    ecx,0x1f
     d3d:	48 01 f1             	add    rcx,rsi
     d40:	8b b0 b0 03 00 00    	mov    esi,DWORD PTR [rax+0x3b0]
     d46:	89 f7                	mov    edi,esi
     d48:	c1 ef 11             	shr    edi,0x11
     d4b:	81 e7 ff 03 00 00    	and    edi,0x3ff
     d51:	48 01 cf             	add    rdi,rcx
     d54:	c1 ee 05             	shr    esi,0x5
     d57:	83 e6 1f             	and    esi,0x1f
     d5a:	48 01 fe             	add    rsi,rdi
     d5d:	8b 88 b8 03 00 00    	mov    ecx,DWORD PTR [rax+0x3b8]
     d63:	89 cf                	mov    edi,ecx
     d65:	c1 ef 11             	shr    edi,0x11
     d68:	81 e7 ff 03 00 00    	and    edi,0x3ff
     d6e:	48 01 f7             	add    rdi,rsi
     d71:	c1 e9 05             	shr    ecx,0x5
     d74:	83 e1 1f             	and    ecx,0x1f
     d77:	48 01 f9             	add    rcx,rdi
     d7a:	8b b0 c0 03 00 00    	mov    esi,DWORD PTR [rax+0x3c0]
     d80:	89 f7                	mov    edi,esi
     d82:	c1 ef 11             	shr    edi,0x11
     d85:	81 e7 ff 03 00 00    	and    edi,0x3ff
     d8b:	48 01 cf             	add    rdi,rcx
     d8e:	c1 ee 05             	shr    esi,0x5
     d91:	83 e6 1f             	and    esi,0x1f
     d94:	48 01 fe             	add    rsi,rdi
     d97:	8b 88 c8 03 00 00    	mov    ecx,DWORD PTR [rax+0x3c8]
     d9d:	89 cf                	mov    edi,ecx
     d9f:	c1 ef 11             	shr    edi,0x11
     da2:	81 e7 ff 03 00 00    	and    edi,0x3ff
     da8:	48 01 f7             	add    rdi,rsi
     dab:	c1 e9 05             	shr    ecx,0x5
     dae:	83 e1 1f             	and    ecx,0x1f
     db1:	48 01 f9             	add    rcx,rdi
     db4:	8b b0 d0 03 00 00    	mov    esi,DWORD PTR [rax+0x3d0]
     dba:	89 f7                	mov    edi,esi
     dbc:	c1 ef 11             	shr    edi,0x11
     dbf:	81 e7 ff 03 00 00    	and    edi,0x3ff
     dc5:	48 01 cf             	add    rdi,rcx
     dc8:	c1 ee 05             	shr    esi,0x5
     dcb:	83 e6 1f             	and    esi,0x1f
     dce:	48 01 fe             	add    rsi,rdi
     dd1:	8b 88 d8 03 00 00    	mov    ecx,DWORD PTR [rax+0x3d8]
     dd7:	89 cf                	mov    edi,ecx
     dd9:	c1 ef 11             	shr    edi,0x11
     ddc:	81 e7 ff 03 00 00    	and    edi,0x3ff
     de2:	48 01 f7             	add    rdi,rsi
     de5:	c1 e9 05             	shr    ecx,0x5
     de8:	83 e1 1f             	and    ecx,0x1f
     deb:	48 01 f9             	add    rcx,rdi
     dee:	8b b0 e0 03 00 00    	mov    esi,DWORD PTR [rax+0x3e0]
     df4:	89 f7                	mov    edi,esi
     df6:	c1 ef 11             	shr    edi,0x11
     df9:	81 e7 ff 03 00 00    	and    edi,0x3ff
     dff:	48 01 cf             	add    rdi,rcx
     e02:	c1 ee 05             	shr    esi,0x5
     e05:	83 e6 1f             	and    esi,0x1f
     e08:	48 01 fe             	add    rsi,rdi
     e0b:	8b 88 e8 03 00 00    	mov    ecx,DWORD PTR [rax+0x3e8]
     e11:	89 cf                	mov    edi,ecx
     e13:	c1 ef 11             	shr    edi,0x11
     e16:	81 e7 ff 03 00 00    	and    edi,0x3ff
     e1c:	48 01 f7             	add    rdi,rsi
     e1f:	c1 e9 05             	shr    ecx,0x5
     e22:	83 e1 1f             	and    ecx,0x1f
     e25:	48 01 f9             	add    rcx,rdi
     e28:	8b b0 f0 03 00 00    	mov    esi,DWORD PTR [rax+0x3f0]
     e2e:	89 f7                	mov    edi,esi
     e30:	c1 ef 11             	shr    edi,0x11
     e33:	81 e7 ff 03 00 00    	and    edi,0x3ff
     e39:	48 01 cf             	add    rdi,rcx
     e3c:	c1 ee 05             	shr    esi,0x5
     e3f:	83 e6 1f             	and    esi,0x1f
     e42:	48 01 fe             	add    rsi,rdi
     e45:	8b 88 f8 03 00 00    	mov    ecx,DWORD PTR [rax+0x3f8]
     e4b:	89 cf                	mov    edi,ecx
     e4d:	c1 ef 11             	shr    edi,0x11
     e50:	81 e7 ff 03 00 00    	and    edi,0x3ff
     e56:	48 01 f7             	add    rdi,rsi
     e59:	c1 e9 05             	shr    ecx,0x5
     e5c:	83 e1 1f             	and    ecx,0x1f
     e5f:	48 01 f9             	add    rcx,rdi
     e62:	48 01 d1             	add    rcx,rdx
     e65:	8b 90 00 04 00 00    	mov    edx,DWORD PTR [rax+0x400]
     e6b:	89 d6                	mov    esi,edx
     e6d:	c1 ee 11             	shr    esi,0x11
     e70:	81 e6 ff 03 00 00    	and    esi,0x3ff
     e76:	c1 ea 05             	shr    edx,0x5
     e79:	83 e2 1f             	and    edx,0x1f
     e7c:	48 01 f2             	add    rdx,rsi
     e7f:	8b b0 08 04 00 00    	mov    esi,DWORD PTR [rax+0x408]
     e85:	89 f7                	mov    edi,esi
     e87:	c1 ef 11             	shr    edi,0x11
     e8a:	81 e7 ff 03 00 00    	and    edi,0x3ff
     e90:	48 01 d7             	add    rdi,rdx
     e93:	c1 ee 05             	shr    esi,0x5
     e96:	83 e6 1f             	and    esi,0x1f
     e99:	48 01 fe             	add    rsi,rdi
     e9c:	8b 90 10 04 00 00    	mov    edx,DWORD PTR [rax+0x410]
     ea2:	89 d7                	mov    edi,edx
     ea4:	c1 ef 11             	shr    edi,0x11
     ea7:	81 e7 ff 03 00 00    	and    edi,0x3ff
     ead:	48 01 f7             	add    rdi,rsi
     eb0:	c1 ea 05             	shr    edx,0x5
     eb3:	83 e2 1f             	and    edx,0x1f
     eb6:	48 01 fa             	add    rdx,rdi
     eb9:	8b b0 18 04 00 00    	mov    esi,DWORD PTR [rax+0x418]
     ebf:	89 f7                	mov    edi,esi
     ec1:	c1 ef 11             	shr    edi,0x11
     ec4:	81 e7 ff 03 00 00    	and    edi,0x3ff
     eca:	48 01 d7             	add    rdi,rdx
     ecd:	c1 ee 05             	shr    esi,0x5
     ed0:	83 e6 1f             	and    esi,0x1f
     ed3:	48 01 fe             	add    rsi,rdi
     ed6:	8b 90 20 04 00 00    	mov    edx,DWORD PTR [rax+0x420]
     edc:	89 d7                	mov    edi,edx
     ede:	c1 ef 11             	shr    edi,0x11
     ee1:	81 e7 ff 03 00 00    	and    edi,0x3ff
     ee7:	48 01 f7             	add    rdi,rsi
     eea:	c1 ea 05             	shr    edx,0x5
     eed:	83 e2 1f             	and    edx,0x1f
     ef0:	48 01 fa             	add    rdx,rdi
     ef3:	8b b0 28 04 00 00    	mov    esi,DWORD PTR [rax+0x428]
     ef9:	89 f7                	mov    edi,esi
     efb:	c1 ef 11             	shr    edi,0x11
     efe:	81 e7 ff 03 00 00    	and    edi,0x3ff
     f04:	48 01 d7             	add    rdi,rdx
     f07:	c1 ee 05             	shr    esi,0x5
     f0a:	83 e6 1f             	and    esi,0x1f
     f0d:	48 01 fe             	add    rsi,rdi
     f10:	8b 90 30 04 00 00    	mov    edx,DWORD PTR [rax+0x430]
     f16:	89 d7                	mov    edi,edx
     f18:	c1 ef 11             	shr    edi,0x11
     f1b:	81 e7 ff 03 00 00    	and    edi,0x3ff
     f21:	48 01 f7             	add    rdi,rsi
     f24:	c1 ea 05             	shr    edx,0x5
     f27:	83 e2 1f             	and    edx,0x1f
     f2a:	48 01 fa             	add    rdx,rdi
     f2d:	8b b0 38 04 00 00    	mov    esi,DWORD PTR [rax+0x438]
     f33:	89 f7                	mov    edi,esi
     f35:	c1 ef 11             	shr    edi,0x11
     f38:	81 e7 ff 03 00 00    	and    edi,0x3ff
     f3e:	48 01 d7             	add    rdi,rdx
     f41:	c1 ee 05             	shr    esi,0x5
     f44:	83 e6 1f             	and    esi,0x1f
     f47:	48 01 fe             	add    rsi,rdi
     f4a:	8b 90 40 04 00 00    	mov    edx,DWORD PTR [rax+0x440]
     f50:	89 d7                	mov    edi,edx
     f52:	c1 ef 11             	shr    edi,0x11
     f55:	81 e7 ff 03 00 00    	and    edi,0x3ff
     f5b:	48 01 f7             	add    rdi,rsi
     f5e:	c1 ea 05             	shr    edx,0x5
     f61:	83 e2 1f             	and    edx,0x1f
     f64:	48 01 fa             	add    rdx,rdi
     f67:	8b b0 48 04 00 00    	mov    esi,DWORD PTR [rax+0x448]
     f6d:	89 f7                	mov    edi,esi
     f6f:	c1 ef 11             	shr    edi,0x11
     f72:	81 e7 ff 03 00 00    	and    edi,0x3ff
     f78:	48 01 d7             	add    rdi,rdx
     f7b:	c1 ee 05             	shr    esi,0x5
     f7e:	83 e6 1f             	and    esi,0x1f
     f81:	48 01 fe             	add    rsi,rdi
     f84:	8b b8 50 04 00 00    	mov    edi,DWORD PTR [rax+0x450]
     f8a:	89 fa                	mov    edx,edi
     f8c:	c1 ea 11             	shr    edx,0x11
     f8f:	81 e2 ff 03 00 00    	and    edx,0x3ff
     f95:	48 01 f2             	add    rdx,rsi
     f98:	c1 ef 05             	shr    edi,0x5
     f9b:	83 e7 1f             	and    edi,0x1f
     f9e:	48 01 d7             	add    rdi,rdx
     fa1:	8b b0 58 04 00 00    	mov    esi,DWORD PTR [rax+0x458]
     fa7:	89 f2                	mov    edx,esi
     fa9:	c1 ea 11             	shr    edx,0x11
     fac:	81 e2 ff 03 00 00    	and    edx,0x3ff
     fb2:	48 01 fa             	add    rdx,rdi
     fb5:	48 01 ca             	add    rdx,rcx
     fb8:	c1 ee 05             	shr    esi,0x5
     fbb:	83 e6 1f             	and    esi,0x1f
     fbe:	8b 88 60 04 00 00    	mov    ecx,DWORD PTR [rax+0x460]
     fc4:	89 cf                	mov    edi,ecx
     fc6:	c1 ef 11             	shr    edi,0x11
     fc9:	81 e7 ff 03 00 00    	and    edi,0x3ff
     fcf:	48 01 f7             	add    rdi,rsi
     fd2:	c1 e9 05             	shr    ecx,0x5
     fd5:	83 e1 1f             	and    ecx,0x1f
     fd8:	48 01 f9             	add    rcx,rdi
     fdb:	8b b0 68 04 00 00    	mov    esi,DWORD PTR [rax+0x468]
     fe1:	89 f7                	mov    edi,esi
     fe3:	c1 ef 11             	shr    edi,0x11
     fe6:	81 e7 ff 03 00 00    	and    edi,0x3ff
     fec:	48 01 cf             	add    rdi,rcx
     fef:	c1 ee 05             	shr    esi,0x5
     ff2:	83 e6 1f             	and    esi,0x1f
     ff5:	48 01 fe             	add    rsi,rdi
     ff8:	8b 88 70 04 00 00    	mov    ecx,DWORD PTR [rax+0x470]
     ffe:	89 cf                	mov    edi,ecx
    1000:	c1 ef 11             	shr    edi,0x11
    1003:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1009:	48 01 f7             	add    rdi,rsi
    100c:	c1 e9 05             	shr    ecx,0x5
    100f:	83 e1 1f             	and    ecx,0x1f
    1012:	48 01 f9             	add    rcx,rdi
    1015:	8b b0 78 04 00 00    	mov    esi,DWORD PTR [rax+0x478]
    101b:	89 f7                	mov    edi,esi
    101d:	c1 ef 11             	shr    edi,0x11
    1020:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1026:	48 01 cf             	add    rdi,rcx
    1029:	c1 ee 05             	shr    esi,0x5
    102c:	83 e6 1f             	and    esi,0x1f
    102f:	48 01 fe             	add    rsi,rdi
    1032:	8b 88 80 04 00 00    	mov    ecx,DWORD PTR [rax+0x480]
    1038:	89 cf                	mov    edi,ecx
    103a:	c1 ef 11             	shr    edi,0x11
    103d:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1043:	48 01 f7             	add    rdi,rsi
    1046:	c1 e9 05             	shr    ecx,0x5
    1049:	83 e1 1f             	and    ecx,0x1f
    104c:	48 01 f9             	add    rcx,rdi
    104f:	8b b0 88 04 00 00    	mov    esi,DWORD PTR [rax+0x488]
    1055:	89 f7                	mov    edi,esi
    1057:	c1 ef 11             	shr    edi,0x11
    105a:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1060:	48 01 cf             	add    rdi,rcx
    1063:	c1 ee 05             	shr    esi,0x5
    1066:	83 e6 1f             	and    esi,0x1f
    1069:	48 01 fe             	add    rsi,rdi
    106c:	8b 88 90 04 00 00    	mov    ecx,DWORD PTR [rax+0x490]
    1072:	89 cf                	mov    edi,ecx
    1074:	c1 ef 11             	shr    edi,0x11
    1077:	81 e7 ff 03 00 00    	and    edi,0x3ff
    107d:	48 01 f7             	add    rdi,rsi
    1080:	c1 e9 05             	shr    ecx,0x5
    1083:	83 e1 1f             	and    ecx,0x1f
    1086:	48 01 f9             	add    rcx,rdi
    1089:	8b b0 98 04 00 00    	mov    esi,DWORD PTR [rax+0x498]
    108f:	89 f7                	mov    edi,esi
    1091:	c1 ef 11             	shr    edi,0x11
    1094:	81 e7 ff 03 00 00    	and    edi,0x3ff
    109a:	48 01 cf             	add    rdi,rcx
    109d:	c1 ee 05             	shr    esi,0x5
    10a0:	83 e6 1f             	and    esi,0x1f
    10a3:	48 01 fe             	add    rsi,rdi
    10a6:	8b 88 a0 04 00 00    	mov    ecx,DWORD PTR [rax+0x4a0]
    10ac:	89 cf                	mov    edi,ecx
    10ae:	c1 ef 11             	shr    edi,0x11
    10b1:	81 e7 ff 03 00 00    	and    edi,0x3ff
    10b7:	48 01 f7             	add    rdi,rsi
    10ba:	c1 e9 05             	shr    ecx,0x5
    10bd:	83 e1 1f             	and    ecx,0x1f
    10c0:	48 01 f9             	add    rcx,rdi
    10c3:	8b b0 a8 04 00 00    	mov    esi,DWORD PTR [rax+0x4a8]
    10c9:	89 f7                	mov    edi,esi
    10cb:	c1 ef 11             	shr    edi,0x11
    10ce:	81 e7 ff 03 00 00    	and    edi,0x3ff
    10d4:	48 01 cf             	add    rdi,rcx
    10d7:	c1 ee 05             	shr    esi,0x5
    10da:	83 e6 1f             	and    esi,0x1f
    10dd:	48 01 fe             	add    rsi,rdi
    10e0:	8b b8 b0 04 00 00    	mov    edi,DWORD PTR [rax+0x4b0]
    10e6:	89 f9                	mov    ecx,edi
    10e8:	c1 e9 11             	shr    ecx,0x11
    10eb:	81 e1 ff 03 00 00    	and    ecx,0x3ff
    10f1:	48 01 f1             	add    rcx,rsi
    10f4:	c1 ef 05             	shr    edi,0x5
    10f7:	83 e7 1f             	and    edi,0x1f
    10fa:	48 01 cf             	add    rdi,rcx
    10fd:	8b b0 b8 04 00 00    	mov    esi,DWORD PTR [rax+0x4b8]
    1103:	89 f1                	mov    ecx,esi
    1105:	c1 e9 11             	shr    ecx,0x11
    1108:	81 e1 ff 03 00 00    	and    ecx,0x3ff
    110e:	48 01 f9             	add    rcx,rdi
    1111:	48 01 d1             	add    rcx,rdx
    1114:	c1 ee 05             	shr    esi,0x5
    1117:	83 e6 1f             	and    esi,0x1f
    111a:	8b 90 c0 04 00 00    	mov    edx,DWORD PTR [rax+0x4c0]
    1120:	89 d7                	mov    edi,edx
    1122:	c1 ef 11             	shr    edi,0x11
    1125:	81 e7 ff 03 00 00    	and    edi,0x3ff
    112b:	48 01 f7             	add    rdi,rsi
    112e:	c1 ea 05             	shr    edx,0x5
    1131:	83 e2 1f             	and    edx,0x1f
    1134:	48 01 fa             	add    rdx,rdi
    1137:	8b b0 c8 04 00 00    	mov    esi,DWORD PTR [rax+0x4c8]
    113d:	89 f7                	mov    edi,esi
    113f:	c1 ef 11             	shr    edi,0x11
    1142:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1148:	48 01 d7             	add    rdi,rdx
    114b:	c1 ee 05             	shr    esi,0x5
    114e:	83 e6 1f             	and    esi,0x1f
    1151:	48 01 fe             	add    rsi,rdi
    1154:	8b 90 d0 04 00 00    	mov    edx,DWORD PTR [rax+0x4d0]
    115a:	89 d7                	mov    edi,edx
    115c:	c1 ef 11             	shr    edi,0x11
    115f:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1165:	48 01 f7             	add    rdi,rsi
    1168:	c1 ea 05             	shr    edx,0x5
    116b:	83 e2 1f             	and    edx,0x1f
    116e:	48 01 fa             	add    rdx,rdi
    1171:	8b b0 d8 04 00 00    	mov    esi,DWORD PTR [rax+0x4d8]
    1177:	89 f7                	mov    edi,esi
    1179:	c1 ef 11             	shr    edi,0x11
    117c:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1182:	48 01 d7             	add    rdi,rdx
    1185:	c1 ee 05             	shr    esi,0x5
    1188:	83 e6 1f             	and    esi,0x1f
    118b:	48 01 fe             	add    rsi,rdi
    118e:	8b 90 e0 04 00 00    	mov    edx,DWORD PTR [rax+0x4e0]
    1194:	89 d7                	mov    edi,edx
    1196:	c1 ef 11             	shr    edi,0x11
    1199:	81 e7 ff 03 00 00    	and    edi,0x3ff
    119f:	48 01 f7             	add    rdi,rsi
    11a2:	c1 ea 05             	shr    edx,0x5
    11a5:	83 e2 1f             	and    edx,0x1f
    11a8:	48 01 fa             	add    rdx,rdi
    11ab:	8b b0 e8 04 00 00    	mov    esi,DWORD PTR [rax+0x4e8]
    11b1:	89 f7                	mov    edi,esi
    11b3:	c1 ef 11             	shr    edi,0x11
    11b6:	81 e7 ff 03 00 00    	and    edi,0x3ff
    11bc:	48 01 d7             	add    rdi,rdx
    11bf:	c1 ee 05             	shr    esi,0x5
    11c2:	83 e6 1f             	and    esi,0x1f
    11c5:	48 01 fe             	add    rsi,rdi
    11c8:	8b 90 f0 04 00 00    	mov    edx,DWORD PTR [rax+0x4f0]
    11ce:	89 d7                	mov    edi,edx
    11d0:	c1 ef 11             	shr    edi,0x11
    11d3:	81 e7 ff 03 00 00    	and    edi,0x3ff
    11d9:	48 01 f7             	add    rdi,rsi
    11dc:	c1 ea 05             	shr    edx,0x5
    11df:	83 e2 1f             	and    edx,0x1f
    11e2:	48 01 fa             	add    rdx,rdi
    11e5:	8b b0 f8 04 00 00    	mov    esi,DWORD PTR [rax+0x4f8]
    11eb:	89 f7                	mov    edi,esi
    11ed:	c1 ef 11             	shr    edi,0x11
    11f0:	81 e7 ff 03 00 00    	and    edi,0x3ff
    11f6:	48 01 d7             	add    rdi,rdx
    11f9:	c1 ee 05             	shr    esi,0x5
    11fc:	83 e6 1f             	and    esi,0x1f
    11ff:	48 01 fe             	add    rsi,rdi
    1202:	8b 90 00 05 00 00    	mov    edx,DWORD PTR [rax+0x500]
    1208:	89 d7                	mov    edi,edx
    120a:	c1 ef 11             	shr    edi,0x11
    120d:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1213:	48 01 f7             	add    rdi,rsi
    1216:	c1 ea 05             	shr    edx,0x5
    1219:	83 e2 1f             	and    edx,0x1f
    121c:	48 01 fa             	add    rdx,rdi
    121f:	8b b0 08 05 00 00    	mov    esi,DWORD PTR [rax+0x508]
    1225:	89 f7                	mov    edi,esi
    1227:	c1 ef 11             	shr    edi,0x11
    122a:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1230:	48 01 d7             	add    rdi,rdx
    1233:	c1 ee 05             	shr    esi,0x5
    1236:	83 e6 1f             	and    esi,0x1f
    1239:	48 01 fe             	add    rsi,rdi
    123c:	8b b8 10 05 00 00    	mov    edi,DWORD PTR [rax+0x510]
    1242:	89 fa                	mov    edx,edi
    1244:	c1 ea 11             	shr    edx,0x11
    1247:	81 e2 ff 03 00 00    	and    edx,0x3ff
    124d:	48 01 f2             	add    rdx,rsi
    1250:	c1 ef 05             	shr    edi,0x5
    1253:	83 e7 1f             	and    edi,0x1f
    1256:	48 01 d7             	add    rdi,rdx
    1259:	8b 90 18 05 00 00    	mov    edx,DWORD PTR [rax+0x518]
    125f:	89 d6                	mov    esi,edx
    1261:	c1 ee 11             	shr    esi,0x11
    1264:	81 e6 ff 03 00 00    	and    esi,0x3ff
    126a:	48 01 fe             	add    rsi,rdi
    126d:	c1 ea 05             	shr    edx,0x5
    1270:	83 e2 1f             	and    edx,0x1f
    1273:	48 01 f2             	add    rdx,rsi
    1276:	48 01 ca             	add    rdx,rcx
    1279:	8b 88 20 05 00 00    	mov    ecx,DWORD PTR [rax+0x520]
    127f:	89 ce                	mov    esi,ecx
    1281:	c1 ee 11             	shr    esi,0x11
    1284:	81 e6 ff 03 00 00    	and    esi,0x3ff
    128a:	c1 e9 05             	shr    ecx,0x5
    128d:	83 e1 1f             	and    ecx,0x1f
    1290:	48 01 f1             	add    rcx,rsi
    1293:	8b b0 28 05 00 00    	mov    esi,DWORD PTR [rax+0x528]
    1299:	89 f7                	mov    edi,esi
    129b:	c1 ef 11             	shr    edi,0x11
    129e:	81 e7 ff 03 00 00    	and    edi,0x3ff
    12a4:	48 01 cf             	add    rdi,rcx
    12a7:	c1 ee 05             	shr    esi,0x5
    12aa:	83 e6 1f             	and    esi,0x1f
    12ad:	48 01 fe             	add    rsi,rdi
    12b0:	8b 88 30 05 00 00    	mov    ecx,DWORD PTR [rax+0x530]
    12b6:	89 cf                	mov    edi,ecx
    12b8:	c1 ef 11             	shr    edi,0x11
    12bb:	81 e7 ff 03 00 00    	and    edi,0x3ff
    12c1:	48 01 f7             	add    rdi,rsi
    12c4:	c1 e9 05             	shr    ecx,0x5
    12c7:	83 e1 1f             	and    ecx,0x1f
    12ca:	48 01 f9             	add    rcx,rdi
    12cd:	8b b0 38 05 00 00    	mov    esi,DWORD PTR [rax+0x538]
    12d3:	89 f7                	mov    edi,esi
    12d5:	c1 ef 11             	shr    edi,0x11
    12d8:	81 e7 ff 03 00 00    	and    edi,0x3ff
    12de:	48 01 cf             	add    rdi,rcx
    12e1:	c1 ee 05             	shr    esi,0x5
    12e4:	83 e6 1f             	and    esi,0x1f
    12e7:	48 01 fe             	add    rsi,rdi
    12ea:	8b 88 40 05 00 00    	mov    ecx,DWORD PTR [rax+0x540]
    12f0:	89 cf                	mov    edi,ecx
    12f2:	c1 ef 11             	shr    edi,0x11
    12f5:	81 e7 ff 03 00 00    	and    edi,0x3ff
    12fb:	48 01 f7             	add    rdi,rsi
    12fe:	c1 e9 05             	shr    ecx,0x5
    1301:	83 e1 1f             	and    ecx,0x1f
    1304:	48 01 f9             	add    rcx,rdi
    1307:	8b b0 48 05 00 00    	mov    esi,DWORD PTR [rax+0x548]
    130d:	89 f7                	mov    edi,esi
    130f:	c1 ef 11             	shr    edi,0x11
    1312:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1318:	48 01 cf             	add    rdi,rcx
    131b:	c1 ee 05             	shr    esi,0x5
    131e:	83 e6 1f             	and    esi,0x1f
    1321:	48 01 fe             	add    rsi,rdi
    1324:	8b 88 50 05 00 00    	mov    ecx,DWORD PTR [rax+0x550]
    132a:	89 cf                	mov    edi,ecx
    132c:	c1 ef 11             	shr    edi,0x11
    132f:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1335:	48 01 f7             	add    rdi,rsi
    1338:	c1 e9 05             	shr    ecx,0x5
    133b:	83 e1 1f             	and    ecx,0x1f
    133e:	48 01 f9             	add    rcx,rdi
    1341:	8b b0 58 05 00 00    	mov    esi,DWORD PTR [rax+0x558]
    1347:	89 f7                	mov    edi,esi
    1349:	c1 ef 11             	shr    edi,0x11
    134c:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1352:	48 01 cf             	add    rdi,rcx
    1355:	c1 ee 05             	shr    esi,0x5
    1358:	83 e6 1f             	and    esi,0x1f
    135b:	48 01 fe             	add    rsi,rdi
    135e:	8b 88 60 05 00 00    	mov    ecx,DWORD PTR [rax+0x560]
    1364:	89 cf                	mov    edi,ecx
    1366:	c1 ef 11             	shr    edi,0x11
    1369:	81 e7 ff 03 00 00    	and    edi,0x3ff
    136f:	48 01 f7             	add    rdi,rsi
    1372:	c1 e9 05             	shr    ecx,0x5
    1375:	83 e1 1f             	and    ecx,0x1f
    1378:	48 01 f9             	add    rcx,rdi
    137b:	8b b0 68 05 00 00    	mov    esi,DWORD PTR [rax+0x568]
    1381:	89 f7                	mov    edi,esi
    1383:	c1 ef 11             	shr    edi,0x11
    1386:	81 e7 ff 03 00 00    	and    edi,0x3ff
    138c:	48 01 cf             	add    rdi,rcx
    138f:	c1 ee 05             	shr    esi,0x5
    1392:	83 e6 1f             	and    esi,0x1f
    1395:	48 01 fe             	add    rsi,rdi
    1398:	8b 88 70 05 00 00    	mov    ecx,DWORD PTR [rax+0x570]
    139e:	89 cf                	mov    edi,ecx
    13a0:	c1 ef 11             	shr    edi,0x11
    13a3:	81 e7 ff 03 00 00    	and    edi,0x3ff
    13a9:	48 01 f7             	add    rdi,rsi
    13ac:	c1 e9 05             	shr    ecx,0x5
    13af:	83 e1 1f             	and    ecx,0x1f
    13b2:	48 01 f9             	add    rcx,rdi
    13b5:	8b b0 78 05 00 00    	mov    esi,DWORD PTR [rax+0x578]
    13bb:	89 f7                	mov    edi,esi
    13bd:	c1 ef 11             	shr    edi,0x11
    13c0:	81 e7 ff 03 00 00    	and    edi,0x3ff
    13c6:	48 01 cf             	add    rdi,rcx
    13c9:	c1 ee 05             	shr    esi,0x5
    13cc:	83 e6 1f             	and    esi,0x1f
    13cf:	48 01 fe             	add    rsi,rdi
    13d2:	8b 88 80 05 00 00    	mov    ecx,DWORD PTR [rax+0x580]
    13d8:	89 cf                	mov    edi,ecx
    13da:	c1 ef 11             	shr    edi,0x11
    13dd:	81 e7 ff 03 00 00    	and    edi,0x3ff
    13e3:	48 01 f7             	add    rdi,rsi
    13e6:	c1 e9 05             	shr    ecx,0x5
    13e9:	83 e1 1f             	and    ecx,0x1f
    13ec:	48 01 f9             	add    rcx,rdi
    13ef:	48 01 d1             	add    rcx,rdx
    13f2:	8b 90 88 05 00 00    	mov    edx,DWORD PTR [rax+0x588]
    13f8:	89 d6                	mov    esi,edx
    13fa:	c1 ee 11             	shr    esi,0x11
    13fd:	81 e6 ff 03 00 00    	and    esi,0x3ff
    1403:	c1 ea 05             	shr    edx,0x5
    1406:	83 e2 1f             	and    edx,0x1f
    1409:	48 01 f2             	add    rdx,rsi
    140c:	8b b0 90 05 00 00    	mov    esi,DWORD PTR [rax+0x590]
    1412:	89 f7                	mov    edi,esi
    1414:	c1 ef 11             	shr    edi,0x11
    1417:	81 e7 ff 03 00 00    	and    edi,0x3ff
    141d:	48 01 d7             	add    rdi,rdx
    1420:	c1 ee 05             	shr    esi,0x5
    1423:	83 e6 1f             	and    esi,0x1f
    1426:	48 01 fe             	add    rsi,rdi
    1429:	8b 90 98 05 00 00    	mov    edx,DWORD PTR [rax+0x598]
    142f:	89 d7                	mov    edi,edx
    1431:	c1 ef 11             	shr    edi,0x11
    1434:	81 e7 ff 03 00 00    	and    edi,0x3ff
    143a:	48 01 f7             	add    rdi,rsi
    143d:	c1 ea 05             	shr    edx,0x5
    1440:	83 e2 1f             	and    edx,0x1f
    1443:	48 01 fa             	add    rdx,rdi
    1446:	8b b0 a0 05 00 00    	mov    esi,DWORD PTR [rax+0x5a0]
    144c:	89 f7                	mov    edi,esi
    144e:	c1 ef 11             	shr    edi,0x11
    1451:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1457:	48 01 d7             	add    rdi,rdx
    145a:	c1 ee 05             	shr    esi,0x5
    145d:	83 e6 1f             	and    esi,0x1f
    1460:	48 01 fe             	add    rsi,rdi
    1463:	8b 90 a8 05 00 00    	mov    edx,DWORD PTR [rax+0x5a8]
    1469:	89 d7                	mov    edi,edx
    146b:	c1 ef 11             	shr    edi,0x11
    146e:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1474:	48 01 f7             	add    rdi,rsi
    1477:	c1 ea 05             	shr    edx,0x5
    147a:	83 e2 1f             	and    edx,0x1f
    147d:	48 01 fa             	add    rdx,rdi
    1480:	8b b0 b0 05 00 00    	mov    esi,DWORD PTR [rax+0x5b0]
    1486:	89 f7                	mov    edi,esi
    1488:	c1 ef 11             	shr    edi,0x11
    148b:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1491:	48 01 d7             	add    rdi,rdx
    1494:	c1 ee 05             	shr    esi,0x5
    1497:	83 e6 1f             	and    esi,0x1f
    149a:	48 01 fe             	add    rsi,rdi
    149d:	8b 90 b8 05 00 00    	mov    edx,DWORD PTR [rax+0x5b8]
    14a3:	89 d7                	mov    edi,edx
    14a5:	c1 ef 11             	shr    edi,0x11
    14a8:	81 e7 ff 03 00 00    	and    edi,0x3ff
    14ae:	48 01 f7             	add    rdi,rsi
    14b1:	c1 ea 05             	shr    edx,0x5
    14b4:	83 e2 1f             	and    edx,0x1f
    14b7:	48 01 fa             	add    rdx,rdi
    14ba:	8b b0 c0 05 00 00    	mov    esi,DWORD PTR [rax+0x5c0]
    14c0:	89 f7                	mov    edi,esi
    14c2:	c1 ef 11             	shr    edi,0x11
    14c5:	81 e7 ff 03 00 00    	and    edi,0x3ff
    14cb:	48 01 d7             	add    rdi,rdx
    14ce:	c1 ee 05             	shr    esi,0x5
    14d1:	83 e6 1f             	and    esi,0x1f
    14d4:	48 01 fe             	add    rsi,rdi
    14d7:	8b 90 c8 05 00 00    	mov    edx,DWORD PTR [rax+0x5c8]
    14dd:	89 d7                	mov    edi,edx
    14df:	c1 ef 11             	shr    edi,0x11
    14e2:	81 e7 ff 03 00 00    	and    edi,0x3ff
    14e8:	48 01 f7             	add    rdi,rsi
    14eb:	c1 ea 05             	shr    edx,0x5
    14ee:	83 e2 1f             	and    edx,0x1f
    14f1:	48 01 fa             	add    rdx,rdi
    14f4:	8b b0 d0 05 00 00    	mov    esi,DWORD PTR [rax+0x5d0]
    14fa:	89 f7                	mov    edi,esi
    14fc:	c1 ef 11             	shr    edi,0x11
    14ff:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1505:	48 01 d7             	add    rdi,rdx
    1508:	c1 ee 05             	shr    esi,0x5
    150b:	83 e6 1f             	and    esi,0x1f
    150e:	48 01 fe             	add    rsi,rdi
    1511:	8b 90 d8 05 00 00    	mov    edx,DWORD PTR [rax+0x5d8]
    1517:	89 d7                	mov    edi,edx
    1519:	c1 ef 11             	shr    edi,0x11
    151c:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1522:	48 01 f7             	add    rdi,rsi
    1525:	c1 ea 05             	shr    edx,0x5
    1528:	83 e2 1f             	and    edx,0x1f
    152b:	48 01 fa             	add    rdx,rdi
    152e:	8b b0 e0 05 00 00    	mov    esi,DWORD PTR [rax+0x5e0]
    1534:	89 f7                	mov    edi,esi
    1536:	c1 ef 11             	shr    edi,0x11
    1539:	81 e7 ff 03 00 00    	and    edi,0x3ff
    153f:	48 01 d7             	add    rdi,rdx
    1542:	c1 ee 05             	shr    esi,0x5
    1545:	83 e6 1f             	and    esi,0x1f
    1548:	48 01 fe             	add    rsi,rdi
    154b:	8b b8 e8 05 00 00    	mov    edi,DWORD PTR [rax+0x5e8]
    1551:	89 fa                	mov    edx,edi
    1553:	c1 ea 11             	shr    edx,0x11
    1556:	81 e2 ff 03 00 00    	and    edx,0x3ff
    155c:	48 01 f2             	add    rdx,rsi
    155f:	c1 ef 05             	shr    edi,0x5
    1562:	83 e7 1f             	and    edi,0x1f
    1565:	48 01 d7             	add    rdi,rdx
    1568:	8b b0 f0 05 00 00    	mov    esi,DWORD PTR [rax+0x5f0]
    156e:	89 f2                	mov    edx,esi
    1570:	c1 ea 11             	shr    edx,0x11
    1573:	81 e2 ff 03 00 00    	and    edx,0x3ff
    1579:	48 01 fa             	add    rdx,rdi
    157c:	48 01 ca             	add    rdx,rcx
    157f:	c1 ee 05             	shr    esi,0x5
    1582:	83 e6 1f             	and    esi,0x1f
    1585:	8b 88 f8 05 00 00    	mov    ecx,DWORD PTR [rax+0x5f8]
    158b:	89 cf                	mov    edi,ecx
    158d:	c1 ef 11             	shr    edi,0x11
    1590:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1596:	48 01 f7             	add    rdi,rsi
    1599:	c1 e9 05             	shr    ecx,0x5
    159c:	83 e1 1f             	and    ecx,0x1f
    159f:	48 01 f9             	add    rcx,rdi
    15a2:	8b b0 00 06 00 00    	mov    esi,DWORD PTR [rax+0x600]
    15a8:	89 f7                	mov    edi,esi
    15aa:	c1 ef 11             	shr    edi,0x11
    15ad:	81 e7 ff 03 00 00    	and    edi,0x3ff
    15b3:	48 01 cf             	add    rdi,rcx
    15b6:	c1 ee 05             	shr    esi,0x5
    15b9:	83 e6 1f             	and    esi,0x1f
    15bc:	48 01 fe             	add    rsi,rdi
    15bf:	8b 88 08 06 00 00    	mov    ecx,DWORD PTR [rax+0x608]
    15c5:	89 cf                	mov    edi,ecx
    15c7:	c1 ef 11             	shr    edi,0x11
    15ca:	81 e7 ff 03 00 00    	and    edi,0x3ff
    15d0:	48 01 f7             	add    rdi,rsi
    15d3:	c1 e9 05             	shr    ecx,0x5
    15d6:	83 e1 1f             	and    ecx,0x1f
    15d9:	48 01 f9             	add    rcx,rdi
    15dc:	8b b0 10 06 00 00    	mov    esi,DWORD PTR [rax+0x610]
    15e2:	89 f7                	mov    edi,esi
    15e4:	c1 ef 11             	shr    edi,0x11
    15e7:	81 e7 ff 03 00 00    	and    edi,0x3ff
    15ed:	48 01 cf             	add    rdi,rcx
    15f0:	c1 ee 05             	shr    esi,0x5
    15f3:	83 e6 1f             	and    esi,0x1f
    15f6:	48 01 fe             	add    rsi,rdi
    15f9:	8b 88 18 06 00 00    	mov    ecx,DWORD PTR [rax+0x618]
    15ff:	89 cf                	mov    edi,ecx
    1601:	c1 ef 11             	shr    edi,0x11
    1604:	81 e7 ff 03 00 00    	and    edi,0x3ff
    160a:	48 01 f7             	add    rdi,rsi
    160d:	c1 e9 05             	shr    ecx,0x5
    1610:	83 e1 1f             	and    ecx,0x1f
    1613:	48 01 f9             	add    rcx,rdi
    1616:	8b b0 20 06 00 00    	mov    esi,DWORD PTR [rax+0x620]
    161c:	89 f7                	mov    edi,esi
    161e:	c1 ef 11             	shr    edi,0x11
    1621:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1627:	48 01 cf             	add    rdi,rcx
    162a:	c1 ee 05             	shr    esi,0x5
    162d:	83 e6 1f             	and    esi,0x1f
    1630:	48 01 fe             	add    rsi,rdi
    1633:	8b 88 28 06 00 00    	mov    ecx,DWORD PTR [rax+0x628]
    1639:	89 cf                	mov    edi,ecx
    163b:	c1 ef 11             	shr    edi,0x11
    163e:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1644:	48 01 f7             	add    rdi,rsi
    1647:	c1 e9 05             	shr    ecx,0x5
    164a:	83 e1 1f             	and    ecx,0x1f
    164d:	48 01 f9             	add    rcx,rdi
    1650:	8b b0 30 06 00 00    	mov    esi,DWORD PTR [rax+0x630]
    1656:	89 f7                	mov    edi,esi
    1658:	c1 ef 11             	shr    edi,0x11
    165b:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1661:	48 01 cf             	add    rdi,rcx
    1664:	c1 ee 05             	shr    esi,0x5
    1667:	83 e6 1f             	and    esi,0x1f
    166a:	48 01 fe             	add    rsi,rdi
    166d:	8b 88 38 06 00 00    	mov    ecx,DWORD PTR [rax+0x638]
    1673:	89 cf                	mov    edi,ecx
    1675:	c1 ef 11             	shr    edi,0x11
    1678:	81 e7 ff 03 00 00    	and    edi,0x3ff
    167e:	48 01 f7             	add    rdi,rsi
    1681:	c1 e9 05             	shr    ecx,0x5
    1684:	83 e1 1f             	and    ecx,0x1f
    1687:	48 01 f9             	add    rcx,rdi
    168a:	8b b0 40 06 00 00    	mov    esi,DWORD PTR [rax+0x640]
    1690:	89 f7                	mov    edi,esi
    1692:	c1 ef 11             	shr    edi,0x11
    1695:	81 e7 ff 03 00 00    	and    edi,0x3ff
    169b:	48 01 cf             	add    rdi,rcx
    169e:	c1 ee 05             	shr    esi,0x5
    16a1:	83 e6 1f             	and    esi,0x1f
    16a4:	48 01 fe             	add    rsi,rdi
    16a7:	8b 88 48 06 00 00    	mov    ecx,DWORD PTR [rax+0x648]
    16ad:	89 cf                	mov    edi,ecx
    16af:	c1 ef 11             	shr    edi,0x11
    16b2:	81 e7 ff 03 00 00    	and    edi,0x3ff
    16b8:	48 01 f7             	add    rdi,rsi
    16bb:	c1 e9 05             	shr    ecx,0x5
    16be:	83 e1 1f             	and    ecx,0x1f
    16c1:	48 01 f9             	add    rcx,rdi
    16c4:	8b b0 50 06 00 00    	mov    esi,DWORD PTR [rax+0x650]
    16ca:	89 f7                	mov    edi,esi
    16cc:	c1 ef 11             	shr    edi,0x11
    16cf:	81 e7 ff 03 00 00    	and    edi,0x3ff
    16d5:	48 01 cf             	add    rdi,rcx
    16d8:	c1 ee 05             	shr    esi,0x5
    16db:	83 e6 1f             	and    esi,0x1f
    16de:	48 01 fe             	add    rsi,rdi
    16e1:	8b b8 58 06 00 00    	mov    edi,DWORD PTR [rax+0x658]
    16e7:	89 f9                	mov    ecx,edi
    16e9:	c1 e9 11             	shr    ecx,0x11
    16ec:	81 e1 ff 03 00 00    	and    ecx,0x3ff
    16f2:	48 01 f1             	add    rcx,rsi
    16f5:	c1 ef 05             	shr    edi,0x5
    16f8:	83 e7 1f             	and    edi,0x1f
    16fb:	48 01 cf             	add    rdi,rcx
    16fe:	8b b0 60 06 00 00    	mov    esi,DWORD PTR [rax+0x660]
    1704:	89 f1                	mov    ecx,esi
    1706:	c1 e9 11             	shr    ecx,0x11
    1709:	81 e1 ff 03 00 00    	and    ecx,0x3ff
    170f:	48 01 f9             	add    rcx,rdi
    1712:	48 01 d1             	add    rcx,rdx
    1715:	c1 ee 05             	shr    esi,0x5
    1718:	83 e6 1f             	and    esi,0x1f
    171b:	8b 90 68 06 00 00    	mov    edx,DWORD PTR [rax+0x668]
    1721:	89 d7                	mov    edi,edx
    1723:	c1 ef 11             	shr    edi,0x11
    1726:	81 e7 ff 03 00 00    	and    edi,0x3ff
    172c:	48 01 f7             	add    rdi,rsi
    172f:	c1 ea 05             	shr    edx,0x5
    1732:	83 e2 1f             	and    edx,0x1f
    1735:	48 01 fa             	add    rdx,rdi
    1738:	8b b0 70 06 00 00    	mov    esi,DWORD PTR [rax+0x670]
    173e:	89 f7                	mov    edi,esi
    1740:	c1 ef 11             	shr    edi,0x11
    1743:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1749:	48 01 d7             	add    rdi,rdx
    174c:	c1 ee 05             	shr    esi,0x5
    174f:	83 e6 1f             	and    esi,0x1f
    1752:	48 01 fe             	add    rsi,rdi
    1755:	8b 90 78 06 00 00    	mov    edx,DWORD PTR [rax+0x678]
    175b:	89 d7                	mov    edi,edx
    175d:	c1 ef 11             	shr    edi,0x11
    1760:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1766:	48 01 f7             	add    rdi,rsi
    1769:	c1 ea 05             	shr    edx,0x5
    176c:	83 e2 1f             	and    edx,0x1f
    176f:	48 01 fa             	add    rdx,rdi
    1772:	8b b0 80 06 00 00    	mov    esi,DWORD PTR [rax+0x680]
    1778:	89 f7                	mov    edi,esi
    177a:	c1 ef 11             	shr    edi,0x11
    177d:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1783:	48 01 d7             	add    rdi,rdx
    1786:	c1 ee 05             	shr    esi,0x5
    1789:	83 e6 1f             	and    esi,0x1f
    178c:	48 01 fe             	add    rsi,rdi
    178f:	8b 90 88 06 00 00    	mov    edx,DWORD PTR [rax+0x688]
    1795:	89 d7                	mov    edi,edx
    1797:	c1 ef 11             	shr    edi,0x11
    179a:	81 e7 ff 03 00 00    	and    edi,0x3ff
    17a0:	48 01 f7             	add    rdi,rsi
    17a3:	c1 ea 05             	shr    edx,0x5
    17a6:	83 e2 1f             	and    edx,0x1f
    17a9:	48 01 fa             	add    rdx,rdi
    17ac:	8b b0 90 06 00 00    	mov    esi,DWORD PTR [rax+0x690]
    17b2:	89 f7                	mov    edi,esi
    17b4:	c1 ef 11             	shr    edi,0x11
    17b7:	81 e7 ff 03 00 00    	and    edi,0x3ff
    17bd:	48 01 d7             	add    rdi,rdx
    17c0:	c1 ee 05             	shr    esi,0x5
    17c3:	83 e6 1f             	and    esi,0x1f
    17c6:	48 01 fe             	add    rsi,rdi
    17c9:	8b 90 98 06 00 00    	mov    edx,DWORD PTR [rax+0x698]
    17cf:	89 d7                	mov    edi,edx
    17d1:	c1 ef 11             	shr    edi,0x11
    17d4:	81 e7 ff 03 00 00    	and    edi,0x3ff
    17da:	48 01 f7             	add    rdi,rsi
    17dd:	c1 ea 05             	shr    edx,0x5
    17e0:	83 e2 1f             	and    edx,0x1f
    17e3:	48 01 fa             	add    rdx,rdi
    17e6:	8b b0 a0 06 00 00    	mov    esi,DWORD PTR [rax+0x6a0]
    17ec:	89 f7                	mov    edi,esi
    17ee:	c1 ef 11             	shr    edi,0x11
    17f1:	81 e7 ff 03 00 00    	and    edi,0x3ff
    17f7:	48 01 d7             	add    rdi,rdx
    17fa:	c1 ee 05             	shr    esi,0x5
    17fd:	83 e6 1f             	and    esi,0x1f
    1800:	48 01 fe             	add    rsi,rdi
    1803:	8b 90 a8 06 00 00    	mov    edx,DWORD PTR [rax+0x6a8]
    1809:	89 d7                	mov    edi,edx
    180b:	c1 ef 11             	shr    edi,0x11
    180e:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1814:	48 01 f7             	add    rdi,rsi
    1817:	c1 ea 05             	shr    edx,0x5
    181a:	83 e2 1f             	and    edx,0x1f
    181d:	48 01 fa             	add    rdx,rdi
    1820:	8b b0 b0 06 00 00    	mov    esi,DWORD PTR [rax+0x6b0]
    1826:	89 f7                	mov    edi,esi
    1828:	c1 ef 11             	shr    edi,0x11
    182b:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1831:	48 01 d7             	add    rdi,rdx
    1834:	c1 ee 05             	shr    esi,0x5
    1837:	83 e6 1f             	and    esi,0x1f
    183a:	48 01 fe             	add    rsi,rdi
    183d:	8b 90 b8 06 00 00    	mov    edx,DWORD PTR [rax+0x6b8]
    1843:	89 d7                	mov    edi,edx
    1845:	c1 ef 11             	shr    edi,0x11
    1848:	81 e7 ff 03 00 00    	and    edi,0x3ff
    184e:	48 01 f7             	add    rdi,rsi
    1851:	c1 ea 05             	shr    edx,0x5
    1854:	83 e2 1f             	and    edx,0x1f
    1857:	48 01 fa             	add    rdx,rdi
    185a:	8b b0 c0 06 00 00    	mov    esi,DWORD PTR [rax+0x6c0]
    1860:	89 f7                	mov    edi,esi
    1862:	c1 ef 11             	shr    edi,0x11
    1865:	81 e7 ff 03 00 00    	and    edi,0x3ff
    186b:	48 01 d7             	add    rdi,rdx
    186e:	c1 ee 05             	shr    esi,0x5
    1871:	83 e6 1f             	and    esi,0x1f
    1874:	48 01 fe             	add    rsi,rdi
    1877:	8b b8 c8 06 00 00    	mov    edi,DWORD PTR [rax+0x6c8]
    187d:	89 fa                	mov    edx,edi
    187f:	c1 ea 11             	shr    edx,0x11
    1882:	81 e2 ff 03 00 00    	and    edx,0x3ff
    1888:	48 01 f2             	add    rdx,rsi
    188b:	c1 ef 05             	shr    edi,0x5
    188e:	83 e7 1f             	and    edi,0x1f
    1891:	48 01 d7             	add    rdi,rdx
    1894:	8b 90 d0 06 00 00    	mov    edx,DWORD PTR [rax+0x6d0]
    189a:	89 d6                	mov    esi,edx
    189c:	c1 ee 11             	shr    esi,0x11
    189f:	81 e6 ff 03 00 00    	and    esi,0x3ff
    18a5:	48 01 fe             	add    rsi,rdi
    18a8:	c1 ea 05             	shr    edx,0x5
    18ab:	83 e2 1f             	and    edx,0x1f
    18ae:	48 01 f2             	add    rdx,rsi
    18b1:	48 01 ca             	add    rdx,rcx
    18b4:	8b 88 d8 06 00 00    	mov    ecx,DWORD PTR [rax+0x6d8]
    18ba:	89 ce                	mov    esi,ecx
    18bc:	c1 ee 11             	shr    esi,0x11
    18bf:	81 e6 ff 03 00 00    	and    esi,0x3ff
    18c5:	c1 e9 05             	shr    ecx,0x5
    18c8:	83 e1 1f             	and    ecx,0x1f
    18cb:	48 01 f1             	add    rcx,rsi
    18ce:	8b b0 e0 06 00 00    	mov    esi,DWORD PTR [rax+0x6e0]
    18d4:	89 f7                	mov    edi,esi
    18d6:	c1 ef 11             	shr    edi,0x11
    18d9:	81 e7 ff 03 00 00    	and    edi,0x3ff
    18df:	48 01 cf             	add    rdi,rcx
    18e2:	c1 ee 05             	shr    esi,0x5
    18e5:	83 e6 1f             	and    esi,0x1f
    18e8:	48 01 fe             	add    rsi,rdi
    18eb:	8b 88 e8 06 00 00    	mov    ecx,DWORD PTR [rax+0x6e8]
    18f1:	89 cf                	mov    edi,ecx
    18f3:	c1 ef 11             	shr    edi,0x11
    18f6:	81 e7 ff 03 00 00    	and    edi,0x3ff
    18fc:	48 01 f7             	add    rdi,rsi
    18ff:	c1 e9 05             	shr    ecx,0x5
    1902:	83 e1 1f             	and    ecx,0x1f
    1905:	48 01 f9             	add    rcx,rdi
    1908:	8b b0 f0 06 00 00    	mov    esi,DWORD PTR [rax+0x6f0]
    190e:	89 f7                	mov    edi,esi
    1910:	c1 ef 11             	shr    edi,0x11
    1913:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1919:	48 01 cf             	add    rdi,rcx
    191c:	c1 ee 05             	shr    esi,0x5
    191f:	83 e6 1f             	and    esi,0x1f
    1922:	48 01 fe             	add    rsi,rdi
    1925:	8b 88 f8 06 00 00    	mov    ecx,DWORD PTR [rax+0x6f8]
    192b:	89 cf                	mov    edi,ecx
    192d:	c1 ef 11             	shr    edi,0x11
    1930:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1936:	48 01 f7             	add    rdi,rsi
    1939:	c1 e9 05             	shr    ecx,0x5
    193c:	83 e1 1f             	and    ecx,0x1f
    193f:	48 01 f9             	add    rcx,rdi
    1942:	8b b0 00 07 00 00    	mov    esi,DWORD PTR [rax+0x700]
    1948:	89 f7                	mov    edi,esi
    194a:	c1 ef 11             	shr    edi,0x11
    194d:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1953:	48 01 cf             	add    rdi,rcx
    1956:	c1 ee 05             	shr    esi,0x5
    1959:	83 e6 1f             	and    esi,0x1f
    195c:	48 01 fe             	add    rsi,rdi
    195f:	8b 88 08 07 00 00    	mov    ecx,DWORD PTR [rax+0x708]
    1965:	89 cf                	mov    edi,ecx
    1967:	c1 ef 11             	shr    edi,0x11
    196a:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1970:	48 01 f7             	add    rdi,rsi
    1973:	c1 e9 05             	shr    ecx,0x5
    1976:	83 e1 1f             	and    ecx,0x1f
    1979:	48 01 f9             	add    rcx,rdi
    197c:	8b b0 10 07 00 00    	mov    esi,DWORD PTR [rax+0x710]
    1982:	89 f7                	mov    edi,esi
    1984:	c1 ef 11             	shr    edi,0x11
    1987:	81 e7 ff 03 00 00    	and    edi,0x3ff
    198d:	48 01 cf             	add    rdi,rcx
    1990:	c1 ee 05             	shr    esi,0x5
    1993:	83 e6 1f             	and    esi,0x1f
    1996:	48 01 fe             	add    rsi,rdi
    1999:	8b 88 18 07 00 00    	mov    ecx,DWORD PTR [rax+0x718]
    199f:	89 cf                	mov    edi,ecx
    19a1:	c1 ef 11             	shr    edi,0x11
    19a4:	81 e7 ff 03 00 00    	and    edi,0x3ff
    19aa:	48 01 f7             	add    rdi,rsi
    19ad:	c1 e9 05             	shr    ecx,0x5
    19b0:	83 e1 1f             	and    ecx,0x1f
    19b3:	48 01 f9             	add    rcx,rdi
    19b6:	8b b0 20 07 00 00    	mov    esi,DWORD PTR [rax+0x720]
    19bc:	89 f7                	mov    edi,esi
    19be:	c1 ef 11             	shr    edi,0x11
    19c1:	81 e7 ff 03 00 00    	and    edi,0x3ff
    19c7:	48 01 cf             	add    rdi,rcx
    19ca:	c1 ee 05             	shr    esi,0x5
    19cd:	83 e6 1f             	and    esi,0x1f
    19d0:	48 01 fe             	add    rsi,rdi
    19d3:	8b 88 28 07 00 00    	mov    ecx,DWORD PTR [rax+0x728]
    19d9:	89 cf                	mov    edi,ecx
    19db:	c1 ef 11             	shr    edi,0x11
    19de:	81 e7 ff 03 00 00    	and    edi,0x3ff
    19e4:	48 01 f7             	add    rdi,rsi
    19e7:	c1 e9 05             	shr    ecx,0x5
    19ea:	83 e1 1f             	and    ecx,0x1f
    19ed:	48 01 f9             	add    rcx,rdi
    19f0:	8b b0 30 07 00 00    	mov    esi,DWORD PTR [rax+0x730]
    19f6:	89 f7                	mov    edi,esi
    19f8:	c1 ef 11             	shr    edi,0x11
    19fb:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1a01:	48 01 cf             	add    rdi,rcx
    1a04:	c1 ee 05             	shr    esi,0x5
    1a07:	83 e6 1f             	and    esi,0x1f
    1a0a:	48 01 fe             	add    rsi,rdi
    1a0d:	8b 88 38 07 00 00    	mov    ecx,DWORD PTR [rax+0x738]
    1a13:	89 cf                	mov    edi,ecx
    1a15:	c1 ef 11             	shr    edi,0x11
    1a18:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1a1e:	48 01 f7             	add    rdi,rsi
    1a21:	c1 e9 05             	shr    ecx,0x5
    1a24:	83 e1 1f             	and    ecx,0x1f
    1a27:	48 01 f9             	add    rcx,rdi
    1a2a:	8b b0 40 07 00 00    	mov    esi,DWORD PTR [rax+0x740]
    1a30:	89 f7                	mov    edi,esi
    1a32:	c1 ef 11             	shr    edi,0x11
    1a35:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1a3b:	48 01 cf             	add    rdi,rcx
    1a3e:	c1 ee 05             	shr    esi,0x5
    1a41:	83 e6 1f             	and    esi,0x1f
    1a44:	48 01 fe             	add    rsi,rdi
    1a47:	8b 88 48 07 00 00    	mov    ecx,DWORD PTR [rax+0x748]
    1a4d:	89 cf                	mov    edi,ecx
    1a4f:	c1 ef 11             	shr    edi,0x11
    1a52:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1a58:	48 01 f7             	add    rdi,rsi
    1a5b:	c1 e9 05             	shr    ecx,0x5
    1a5e:	83 e1 1f             	and    ecx,0x1f
    1a61:	48 01 f9             	add    rcx,rdi
    1a64:	48 01 d1             	add    rcx,rdx
    1a67:	8b 90 50 07 00 00    	mov    edx,DWORD PTR [rax+0x750]
    1a6d:	89 d6                	mov    esi,edx
    1a6f:	c1 ee 11             	shr    esi,0x11
    1a72:	81 e6 ff 03 00 00    	and    esi,0x3ff
    1a78:	c1 ea 05             	shr    edx,0x5
    1a7b:	83 e2 1f             	and    edx,0x1f
    1a7e:	48 01 f2             	add    rdx,rsi
    1a81:	8b b0 58 07 00 00    	mov    esi,DWORD PTR [rax+0x758]
    1a87:	89 f7                	mov    edi,esi
    1a89:	c1 ef 11             	shr    edi,0x11
    1a8c:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1a92:	48 01 d7             	add    rdi,rdx
    1a95:	c1 ee 05             	shr    esi,0x5
    1a98:	83 e6 1f             	and    esi,0x1f
    1a9b:	48 01 fe             	add    rsi,rdi
    1a9e:	8b 90 60 07 00 00    	mov    edx,DWORD PTR [rax+0x760]
    1aa4:	89 d7                	mov    edi,edx
    1aa6:	c1 ef 11             	shr    edi,0x11
    1aa9:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1aaf:	48 01 f7             	add    rdi,rsi
    1ab2:	c1 ea 05             	shr    edx,0x5
    1ab5:	83 e2 1f             	and    edx,0x1f
    1ab8:	48 01 fa             	add    rdx,rdi
    1abb:	8b b0 68 07 00 00    	mov    esi,DWORD PTR [rax+0x768]
    1ac1:	89 f7                	mov    edi,esi
    1ac3:	c1 ef 11             	shr    edi,0x11
    1ac6:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1acc:	48 01 d7             	add    rdi,rdx
    1acf:	c1 ee 05             	shr    esi,0x5
    1ad2:	83 e6 1f             	and    esi,0x1f
    1ad5:	48 01 fe             	add    rsi,rdi
    1ad8:	8b 90 70 07 00 00    	mov    edx,DWORD PTR [rax+0x770]
    1ade:	89 d7                	mov    edi,edx
    1ae0:	c1 ef 11             	shr    edi,0x11
    1ae3:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1ae9:	48 01 f7             	add    rdi,rsi
    1aec:	c1 ea 05             	shr    edx,0x5
    1aef:	83 e2 1f             	and    edx,0x1f
    1af2:	48 01 fa             	add    rdx,rdi
    1af5:	8b b0 78 07 00 00    	mov    esi,DWORD PTR [rax+0x778]
    1afb:	89 f7                	mov    edi,esi
    1afd:	c1 ef 11             	shr    edi,0x11
    1b00:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1b06:	48 01 d7             	add    rdi,rdx
    1b09:	c1 ee 05             	shr    esi,0x5
    1b0c:	83 e6 1f             	and    esi,0x1f
    1b0f:	48 01 fe             	add    rsi,rdi
    1b12:	8b 90 80 07 00 00    	mov    edx,DWORD PTR [rax+0x780]
    1b18:	89 d7                	mov    edi,edx
    1b1a:	c1 ef 11             	shr    edi,0x11
    1b1d:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1b23:	48 01 f7             	add    rdi,rsi
    1b26:	c1 ea 05             	shr    edx,0x5
    1b29:	83 e2 1f             	and    edx,0x1f
    1b2c:	48 01 fa             	add    rdx,rdi
    1b2f:	8b b0 88 07 00 00    	mov    esi,DWORD PTR [rax+0x788]
    1b35:	89 f7                	mov    edi,esi
    1b37:	c1 ef 11             	shr    edi,0x11
    1b3a:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1b40:	48 01 d7             	add    rdi,rdx
    1b43:	c1 ee 05             	shr    esi,0x5
    1b46:	83 e6 1f             	and    esi,0x1f
    1b49:	48 01 fe             	add    rsi,rdi
    1b4c:	8b 90 90 07 00 00    	mov    edx,DWORD PTR [rax+0x790]
    1b52:	89 d7                	mov    edi,edx
    1b54:	c1 ef 11             	shr    edi,0x11
    1b57:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1b5d:	48 01 f7             	add    rdi,rsi
    1b60:	c1 ea 05             	shr    edx,0x5
    1b63:	83 e2 1f             	and    edx,0x1f
    1b66:	48 01 fa             	add    rdx,rdi
    1b69:	8b b0 98 07 00 00    	mov    esi,DWORD PTR [rax+0x798]
    1b6f:	89 f7                	mov    edi,esi
    1b71:	c1 ef 11             	shr    edi,0x11
    1b74:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1b7a:	48 01 d7             	add    rdi,rdx
    1b7d:	c1 ee 05             	shr    esi,0x5
    1b80:	83 e6 1f             	and    esi,0x1f
    1b83:	48 01 fe             	add    rsi,rdi
    1b86:	8b 90 a0 07 00 00    	mov    edx,DWORD PTR [rax+0x7a0]
    1b8c:	89 d7                	mov    edi,edx
    1b8e:	c1 ef 11             	shr    edi,0x11
    1b91:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1b97:	48 01 f7             	add    rdi,rsi
    1b9a:	c1 ea 05             	shr    edx,0x5
    1b9d:	83 e2 1f             	and    edx,0x1f
    1ba0:	48 01 fa             	add    rdx,rdi
    1ba3:	8b b0 a8 07 00 00    	mov    esi,DWORD PTR [rax+0x7a8]
    1ba9:	89 f7                	mov    edi,esi
    1bab:	c1 ef 11             	shr    edi,0x11
    1bae:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1bb4:	48 01 d7             	add    rdi,rdx
    1bb7:	c1 ee 05             	shr    esi,0x5
    1bba:	83 e6 1f             	and    esi,0x1f
    1bbd:	48 01 fe             	add    rsi,rdi
    1bc0:	8b 90 b0 07 00 00    	mov    edx,DWORD PTR [rax+0x7b0]
    1bc6:	89 d7                	mov    edi,edx
    1bc8:	c1 ef 11             	shr    edi,0x11
    1bcb:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1bd1:	48 01 f7             	add    rdi,rsi
    1bd4:	c1 ea 05             	shr    edx,0x5
    1bd7:	83 e2 1f             	and    edx,0x1f
    1bda:	48 01 fa             	add    rdx,rdi
    1bdd:	8b b0 b8 07 00 00    	mov    esi,DWORD PTR [rax+0x7b8]
    1be3:	89 f7                	mov    edi,esi
    1be5:	c1 ef 11             	shr    edi,0x11
    1be8:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1bee:	48 01 d7             	add    rdi,rdx
    1bf1:	c1 ee 05             	shr    esi,0x5
    1bf4:	83 e6 1f             	and    esi,0x1f
    1bf7:	48 01 fe             	add    rsi,rdi
    1bfa:	8b b8 c0 07 00 00    	mov    edi,DWORD PTR [rax+0x7c0]
    1c00:	89 fa                	mov    edx,edi
    1c02:	c1 ea 11             	shr    edx,0x11
    1c05:	81 e2 ff 03 00 00    	and    edx,0x3ff
    1c0b:	48 01 f2             	add    rdx,rsi
    1c0e:	c1 ef 05             	shr    edi,0x5
    1c11:	83 e7 1f             	and    edi,0x1f
    1c14:	48 01 d7             	add    rdi,rdx
    1c17:	8b b0 c8 07 00 00    	mov    esi,DWORD PTR [rax+0x7c8]
    1c1d:	89 f2                	mov    edx,esi
    1c1f:	c1 ea 11             	shr    edx,0x11
    1c22:	81 e2 ff 03 00 00    	and    edx,0x3ff
    1c28:	48 01 fa             	add    rdx,rdi
    1c2b:	48 01 ca             	add    rdx,rcx
    1c2e:	c1 ee 05             	shr    esi,0x5
    1c31:	83 e6 1f             	and    esi,0x1f
    1c34:	8b 88 d0 07 00 00    	mov    ecx,DWORD PTR [rax+0x7d0]
    1c3a:	89 cf                	mov    edi,ecx
    1c3c:	c1 ef 11             	shr    edi,0x11
    1c3f:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1c45:	48 01 f7             	add    rdi,rsi
    1c48:	c1 e9 05             	shr    ecx,0x5
    1c4b:	83 e1 1f             	and    ecx,0x1f
    1c4e:	48 01 f9             	add    rcx,rdi
    1c51:	8b b0 d8 07 00 00    	mov    esi,DWORD PTR [rax+0x7d8]
    1c57:	89 f7                	mov    edi,esi
    1c59:	c1 ef 11             	shr    edi,0x11
    1c5c:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1c62:	48 01 cf             	add    rdi,rcx
    1c65:	c1 ee 05             	shr    esi,0x5
    1c68:	83 e6 1f             	and    esi,0x1f
    1c6b:	48 01 fe             	add    rsi,rdi
    1c6e:	8b 88 e0 07 00 00    	mov    ecx,DWORD PTR [rax+0x7e0]
    1c74:	89 cf                	mov    edi,ecx
    1c76:	c1 ef 11             	shr    edi,0x11
    1c79:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1c7f:	48 01 f7             	add    rdi,rsi
    1c82:	c1 e9 05             	shr    ecx,0x5
    1c85:	83 e1 1f             	and    ecx,0x1f
    1c88:	48 01 f9             	add    rcx,rdi
    1c8b:	8b b0 e8 07 00 00    	mov    esi,DWORD PTR [rax+0x7e8]
    1c91:	89 f7                	mov    edi,esi
    1c93:	c1 ef 11             	shr    edi,0x11
    1c96:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1c9c:	48 01 cf             	add    rdi,rcx
    1c9f:	c1 ee 05             	shr    esi,0x5
    1ca2:	83 e6 1f             	and    esi,0x1f
    1ca5:	48 01 fe             	add    rsi,rdi
    1ca8:	8b 88 f0 07 00 00    	mov    ecx,DWORD PTR [rax+0x7f0]
    1cae:	89 cf                	mov    edi,ecx
    1cb0:	c1 ef 11             	shr    edi,0x11
    1cb3:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1cb9:	48 01 f7             	add    rdi,rsi
    1cbc:	c1 e9 05             	shr    ecx,0x5
    1cbf:	83 e1 1f             	and    ecx,0x1f
    1cc2:	48 01 f9             	add    rcx,rdi
    1cc5:	8b b0 f8 07 00 00    	mov    esi,DWORD PTR [rax+0x7f8]
    1ccb:	89 f7                	mov    edi,esi
    1ccd:	c1 ef 11             	shr    edi,0x11
    1cd0:	81 e7 ff 03 00 00    	and    edi,0x3ff
    1cd6:	48 01 cf             	add    rdi,rcx
    1cd9:	c1 ee 05             	shr    esi,0x5
    1cdc:	83 e6 1f             	and    esi,0x1f
    1cdf:	48 01 fe             	add    rsi,rdi
    1ce2:	8b b8 00 08 00 00    	mov    edi,DWORD PTR [rax+0x800]
    1ce8:	89 f9                	mov    ecx,edi
    1cea:	c1 e9 11             	shr    ecx,0x11
    1ced:	81 e1 ff 03 00 00    	and    ecx,0x3ff
    1cf3:	48 01 f1             	add    rcx,rsi
    1cf6:	c1 ef 05             	shr    edi,0x5
    1cf9:	83 e7 1f             	and    edi,0x1f
    1cfc:	48 01 cf             	add    rdi,rcx
    1cff:	48 b9 bb 2e cb 84 85 	movabs rcx,0xbb67ae8584cb2ebb
    1d06:	ae 67 bb 
    1d09:	48 01 f9             	add    rcx,rdi
    1d0c:	c6 40 07 bb          	mov    BYTE PTR [rax+0x7],0xbb
    1d10:	48 01 d1             	add    rcx,rdx
    1d13:	c7 40 03 84 85 ae 67 	mov    DWORD PTR [rax+0x3],0x67ae8584
    1d1a:	89 ca                	mov    edx,ecx
    1d1c:	c1 ea 10             	shr    edx,0x10
    1d1f:	88 50 02             	mov    BYTE PTR [rax+0x2],dl
    1d22:	88 08                	mov    BYTE PTR [rax],cl
    1d24:	88 68 01             	mov    BYTE PTR [rax+0x1],ch
    1d27:	b8 02 00 00 00       	mov    eax,0x2
    1d2c:	c3                   	ret
