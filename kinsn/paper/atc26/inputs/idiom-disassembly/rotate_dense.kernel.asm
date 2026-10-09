
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/rotate_dense.kernel.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
       0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
       5:	0f 1f 00             	nop    DWORD PTR [rax]
       8:	55                   	push   rbp
       9:	48 89 e5             	mov    rbp,rsp
       c:	48 81 ec 28 00 00 00 	sub    rsp,0x28
      13:	53                   	push   rbx
      14:	41 55                	push   r13
      16:	41 56                	push   r14
      18:	41 57                	push   r15
      1a:	31 c0                	xor    eax,eax
      1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
      20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
      24:	48 39 f2             	cmp    rdx,rsi
      27:	0f 87 96 27 00 00    	ja     0x27c3
      2d:	48 89 d7             	mov    rdi,rdx
      30:	48 83 c7 08          	add    rdi,0x8
      34:	48 39 f7             	cmp    rdi,rsi
      37:	0f 87 86 27 00 00    	ja     0x27c3
      3d:	48 89 d7             	mov    rdi,rdx
      40:	48 83 c7 48          	add    rdi,0x48
      44:	48 39 f7             	cmp    rdi,rsi
      47:	0f 87 76 27 00 00    	ja     0x27c3
      4d:	4c 8b 42 18          	mov    r8,QWORD PTR [rdx+0x18]
      51:	48 bf 61 72 65 6e 65 	movabs rdi,0x6c7967656e657261
      58:	67 79 6c 
      5b:	49 31 f8             	xor    r8,rdi
      5e:	48 8b 7a 10          	mov    rdi,QWORD PTR [rdx+0x10]
      62:	48 be 6d 6f 64 6e 61 	movabs rsi,0x646f72616e646f6d
      69:	72 6f 64 
      6c:	48 31 f7             	xor    rdi,rsi
      6f:	49 89 d5             	mov    r13,rdx
      72:	48 89 fa             	mov    rdx,rdi
      75:	4c 31 c2             	xor    rdx,r8
      78:	48 be 15 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c15
      7f:	79 37 9e 
      82:	48 01 f2             	add    rdx,rsi
      85:	48 89 d6             	mov    rsi,rdx
      88:	48 c1 ee 33          	shr    rsi,0x33
      8c:	48 c1 e2 0d          	shl    rdx,0xd
      90:	48 09 f2             	or     rdx,rsi
      93:	49 8b 45 20          	mov    rax,QWORD PTR [r13+0x20]
      97:	48 be 73 65 74 79 62 	movabs rsi,0x7465646279746573
      9e:	64 65 74 
      a1:	48 31 f0             	xor    rax,rsi
      a4:	49 8b 75 08          	mov    rsi,QWORD PTR [r13+0x8]
      a8:	48 b9 75 65 73 70 65 	movabs rcx,0x736f6d6570736575
      af:	6d 6f 73 
      b2:	48 31 ce             	xor    rsi,rcx
      b5:	48 01 f2             	add    rdx,rsi
      b8:	4c 89 c1             	mov    rcx,r8
      bb:	48 01 c1             	add    rcx,rax
      be:	48 be 44 e0 07 f8 1d 	movabs rsi,0x3ead971df807e044
      c5:	97 ad 3e 
      c8:	48 31 f1             	xor    rcx,rsi
      cb:	48 89 ce             	mov    rsi,rcx
      ce:	48 c1 ee 2f          	shr    rsi,0x2f
      d2:	48 c1 e1 11          	shl    rcx,0x11
      d6:	48 09 f1             	or     rcx,rsi
      d9:	48 31 f9             	xor    rcx,rdi
      dc:	48 bf a2 a8 82 e9 e6 	movabs rdi,0x7f99d1e6e982a8a2
      e3:	d1 99 7f 
      e6:	48 89 ce             	mov    rsi,rcx
      e9:	48 01 d6             	add    rsi,rdx
      ec:	48 31 fe             	xor    rsi,rdi
      ef:	48 89 f7             	mov    rdi,rsi
      f2:	48 c1 ef 15          	shr    rdi,0x15
      f6:	48 c1 e6 2b          	shl    rsi,0x2b
      fa:	48 09 fe             	or     rsi,rdi
      fd:	48 31 c6             	xor    rsi,rax
     100:	48 89 d7             	mov    rdi,rdx
     103:	48 31 c7             	xor    rdi,rax
     106:	48 b8 73 44 c5 70 82 	movabs rax,0xdf23b48270c54473
     10d:	b4 23 df 
     110:	48 01 c7             	add    rdi,rax
     113:	48 89 f8             	mov    rax,rdi
     116:	48 c1 e8 23          	shr    rax,0x23
     11a:	48 c1 e7 1d          	shl    rdi,0x1d
     11e:	48 09 c7             	or     rdi,rax
     121:	4c 01 c7             	add    rdi,r8
     124:	4c 89 6d d8          	mov    QWORD PTR [rbp-0x28],r13
     128:	4d 8b 45 28          	mov    r8,QWORD PTR [r13+0x28]
     12c:	4c 89 45 e8          	mov    QWORD PTR [rbp-0x18],r8
     130:	4d 8b 45 38          	mov    r8,QWORD PTR [r13+0x38]
     134:	4c 89 45 f8          	mov    QWORD PTR [rbp-0x8],r8
     138:	49 8b 5d 30          	mov    rbx,QWORD PTR [r13+0x30]
     13c:	49 8b 45 40          	mov    rax,QWORD PTR [r13+0x40]
     140:	49 b8 d1 0c 40 62 4b 	movabs r8,0x200fef4b62400cd1
     147:	ef 0f 20 
     14a:	49 89 ce             	mov    r14,rcx
     14d:	49 31 fe             	xor    r14,rdi
     150:	4d 01 c6             	add    r14,r8
     153:	4d 89 f0             	mov    r8,r14
     156:	49 c1 e8 35          	shr    r8,0x35
     15a:	49 c1 e6 0b          	shl    r14,0xb
     15e:	4d 09 c6             	or     r14,r8
     161:	49 b8 00 71 fd da af 	movabs r8,0xc0860cafdafd7100
     168:	0c 86 c0 
     16b:	49 89 ff             	mov    r15,rdi
     16e:	49 01 f7             	add    r15,rsi
     171:	4d 31 c7             	xor    r15,r8
     174:	4d 89 f8             	mov    r8,r15
     177:	49 c1 e8 2d          	shr    r8,0x2d
     17b:	49 c1 e7 13          	shl    r15,0x13
     17f:	4d 09 c7             	or     r15,r8
     182:	49 31 cf             	xor    r15,rcx
     185:	49 01 d6             	add    r14,rdx
     188:	48 ba 5e 39 78 cc 78 	movabs rdx,0x1724778cc78395e
     18f:	47 72 01 
     192:	4c 89 f1             	mov    rcx,r14
     195:	4c 01 f9             	add    rcx,r15
     198:	48 31 d1             	xor    rcx,rdx
     19b:	48 89 ca             	mov    rdx,rcx
     19e:	48 c1 ea 11          	shr    rdx,0x11
     1a2:	48 c1 e1 2f          	shl    rcx,0x2f
     1a6:	48 09 d1             	or     rcx,rdx
     1a9:	49 b8 2f d5 ba 53 14 	movabs r8,0x60fc2a1453bad52f
     1b0:	2a fc 60 
     1b3:	4c 89 f2             	mov    rdx,r14
     1b6:	48 31 f2             	xor    rdx,rsi
     1b9:	4c 01 c2             	add    rdx,r8
     1bc:	49 89 d0             	mov    r8,rdx
     1bf:	49 c1 e8 21          	shr    r8,0x21
     1c3:	48 c1 e2 1f          	shl    rdx,0x1f
     1c7:	4c 09 c2             	or     rdx,r8
     1ca:	48 31 f1             	xor    rcx,rsi
     1cd:	48 01 fa             	add    rdx,rdi
     1d0:	48 bf 8d 9d 35 45 dd 	movabs rdi,0xa1e864dd45359d8d
     1d7:	64 e8 a1 
     1da:	4d 89 f8             	mov    r8,r15
     1dd:	49 31 d0             	xor    r8,rdx
     1e0:	49 01 f8             	add    r8,rdi
     1e3:	4c 89 c7             	mov    rdi,r8
     1e6:	48 c1 ef 39          	shr    rdi,0x39
     1ea:	49 c1 e0 07          	shl    r8,0x7
     1ee:	49 09 f8             	or     r8,rdi
     1f1:	48 bf bc 01 f3 bd 41 	movabs rdi,0x425e8241bdf301bc
     1f8:	82 5e 42 
     1fb:	48 89 d6             	mov    rsi,rdx
     1fe:	48 01 ce             	add    rsi,rcx
     201:	48 31 fe             	xor    rsi,rdi
     204:	48 89 f7             	mov    rdi,rsi
     207:	48 c1 ef 29          	shr    rdi,0x29
     20b:	48 c1 e6 17          	shl    rsi,0x17
     20f:	48 09 fe             	or     rsi,rdi
     212:	4c 31 fe             	xor    rsi,r15
     215:	4d 01 f0             	add    r8,r14
     218:	48 bf 1a ca 6d af 0a 	movabs rdi,0x834abd0aaf6dca1a
     21f:	bd 4a 83 
     222:	4d 89 c6             	mov    r14,r8
     225:	49 01 f6             	add    r14,rsi
     228:	49 31 fe             	xor    r14,rdi
     22b:	4c 89 f7             	mov    rdi,r14
     22e:	48 c1 ef 0b          	shr    rdi,0xb
     232:	49 c1 e6 35          	shl    r14,0x35
     236:	49 09 fe             	or     r14,rdi
     239:	49 bd eb 65 b0 36 a6 	movabs r13,0xe2d49fa636b065eb
     240:	9f d4 e2 
     243:	4c 89 c7             	mov    rdi,r8
     246:	48 31 cf             	xor    rdi,rcx
     249:	4c 01 ef             	add    rdi,r13
     24c:	49 89 ff             	mov    r15,rdi
     24f:	49 c1 ef 1b          	shr    r15,0x1b
     253:	48 c1 e7 25          	shl    rdi,0x25
     257:	4c 09 ff             	or     rdi,r15
     25a:	49 31 ce             	xor    r14,rcx
     25d:	48 01 d7             	add    rdi,rdx
     260:	48 b9 49 2e 2b 28 6f 	movabs rcx,0x23c0da6f282b2e49
     267:	da c0 23 
     26a:	48 89 f2             	mov    rdx,rsi
     26d:	48 31 fa             	xor    rdx,rdi
     270:	48 01 ca             	add    rdx,rcx
     273:	48 89 d1             	mov    rcx,rdx
     276:	48 c1 e9 3b          	shr    rcx,0x3b
     27a:	48 c1 e2 05          	shl    rdx,0x5
     27e:	48 09 ca             	or     rdx,rcx
     281:	48 b9 78 92 e8 a0 d3 	movabs rcx,0xc436f7d3a0e89278
     288:	f7 36 c4 
     28b:	49 89 ff             	mov    r15,rdi
     28e:	4d 01 f7             	add    r15,r14
     291:	49 31 cf             	xor    r15,rcx
     294:	4c 89 f9             	mov    rcx,r15
     297:	48 c1 e9 25          	shr    rcx,0x25
     29b:	49 c1 e7 1b          	shl    r15,0x1b
     29f:	49 09 cf             	or     r15,rcx
     2a2:	49 31 f7             	xor    r15,rsi
     2a5:	4c 01 c2             	add    rdx,r8
     2a8:	48 be d6 5a 63 92 9c 	movabs rsi,0x523329c92635ad6
     2af:	32 23 05 
     2b2:	48 89 d1             	mov    rcx,rdx
     2b5:	4c 01 f9             	add    rcx,r15
     2b8:	48 31 f1             	xor    rcx,rsi
     2bb:	48 89 ce             	mov    rsi,rcx
     2be:	48 c1 ee 05          	shr    rsi,0x5
     2c2:	48 c1 e1 3b          	shl    rcx,0x3b
     2c6:	48 09 f1             	or     rcx,rsi
     2c9:	49 b8 a7 f6 a5 19 38 	movabs r8,0x64ad153819a5f6a7
     2d0:	15 ad 64 
     2d3:	48 89 d6             	mov    rsi,rdx
     2d6:	4c 31 f6             	xor    rsi,r14
     2d9:	4c 01 c6             	add    rsi,r8
     2dc:	49 89 f0             	mov    r8,rsi
     2df:	49 c1 e8 17          	shr    r8,0x17
     2e3:	48 c1 e6 29          	shl    rsi,0x29
     2e7:	4c 09 c6             	or     rsi,r8
     2ea:	4c 31 f1             	xor    rcx,r14
     2ed:	48 01 fe             	add    rsi,rdi
     2f0:	49 b8 05 bf 20 0b 01 	movabs r8,0xa59950010b20bf05
     2f7:	50 99 a5 
     2fa:	4c 89 ff             	mov    rdi,r15
     2fd:	48 31 f7             	xor    rdi,rsi
     300:	4c 01 c7             	add    rdi,r8
     303:	49 89 f8             	mov    r8,rdi
     306:	49 c1 e8 3d          	shr    r8,0x3d
     30a:	48 c1 e7 03          	shl    rdi,0x3
     30e:	4c 09 c7             	or     rdi,r8
     311:	49 be 34 23 de 83 65 	movabs r14,0x460f6d6583de2334
     318:	6d 0f 46 
     31b:	49 89 f0             	mov    r8,rsi
     31e:	49 01 c8             	add    r8,rcx
     321:	4d 31 f0             	xor    r8,r14
     324:	4d 89 c6             	mov    r14,r8
     327:	49 c1 ee 33          	shr    r14,0x33
     32b:	49 c1 e0 0d          	shl    r8,0xd
     32f:	4d 09 f0             	or     r8,r14
     332:	4d 31 f8             	xor    r8,r15
     335:	48 01 d7             	add    rdi,rdx
     338:	49 be 92 eb 58 75 2e 	movabs r14,0x86fba82e7558eb92
     33f:	a8 fb 86 
     342:	48 89 fa             	mov    rdx,rdi
     345:	4c 01 c2             	add    rdx,r8
     348:	4c 31 f2             	xor    rdx,r14
     34b:	49 89 d6             	mov    r14,rdx
     34e:	49 c1 ee 03          	shr    r14,0x3
     352:	48 c1 e2 3d          	shl    rdx,0x3d
     356:	4c 09 f2             	or     rdx,r14
     359:	49 bf 63 87 9b fc c9 	movabs r15,0xe6858ac9fc9b8763
     360:	8a 85 e6 
     363:	49 89 fe             	mov    r14,rdi
     366:	49 31 ce             	xor    r14,rcx
     369:	4d 01 fe             	add    r14,r15
     36c:	4d 89 f7             	mov    r15,r14
     36f:	49 c1 ef 23          	shr    r15,0x23
     373:	49 c1 e6 1d          	shl    r14,0x1d
     377:	4d 09 fe             	or     r14,r15
     37a:	48 31 ca             	xor    rdx,rcx
     37d:	49 01 f6             	add    r14,rsi
     380:	48 b9 c1 4f 16 ee 92 	movabs rcx,0x2771c592ee164fc1
     387:	c5 71 27 
     38a:	4c 89 c6             	mov    rsi,r8
     38d:	4c 31 f6             	xor    rsi,r14
     390:	48 01 ce             	add    rsi,rcx
     393:	48 89 f1             	mov    rcx,rsi
     396:	48 c1 e9 2f          	shr    rcx,0x2f
     39a:	48 c1 e6 11          	shl    rsi,0x11
     39e:	48 09 ce             	or     rsi,rcx
     3a1:	48 b9 f0 b3 d3 66 f7 	movabs rcx,0xc7e7e2f766d3b3f0
     3a8:	e2 e7 c7 
     3ab:	4d 89 f7             	mov    r15,r14
     3ae:	49 01 d7             	add    r15,rdx
     3b1:	49 31 cf             	xor    r15,rcx
     3b4:	4c 89 f9             	mov    rcx,r15
     3b7:	48 c1 e9 21          	shr    rcx,0x21
     3bb:	49 c1 e7 1f          	shl    r15,0x1f
     3bf:	49 09 cf             	or     r15,rcx
     3c2:	4d 31 c7             	xor    r15,r8
     3c5:	48 01 fe             	add    rsi,rdi
     3c8:	48 b9 4e 7c 4e 58 c0 	movabs rcx,0x8d41dc0584e7c4e
     3cf:	1d d4 08 
     3d2:	48 89 f7             	mov    rdi,rsi
     3d5:	4c 01 ff             	add    rdi,r15
     3d8:	48 31 cf             	xor    rdi,rcx
     3db:	48 89 f9             	mov    rcx,rdi
     3de:	48 c1 e9 35          	shr    rcx,0x35
     3e2:	48 c1 e7 0b          	shl    rdi,0xb
     3e6:	48 09 cf             	or     rdi,rcx
     3e9:	49 b8 1f 18 91 df 5b 	movabs r8,0x685e005bdf91181f
     3f0:	00 5e 68 
     3f3:	48 89 f1             	mov    rcx,rsi
     3f6:	48 31 d1             	xor    rcx,rdx
     3f9:	4c 01 c1             	add    rcx,r8
     3fc:	49 89 c8             	mov    r8,rcx
     3ff:	49 c1 e8 15          	shr    r8,0x15
     403:	48 c1 e1 2b          	shl    rcx,0x2b
     407:	4c 09 c1             	or     rcx,r8
     40a:	48 31 d7             	xor    rdi,rdx
     40d:	4c 01 f1             	add    rcx,r14
     410:	49 b8 7d e0 0b d1 24 	movabs r8,0xa94a3b24d10be07d
     417:	3b 4a a9 
     41a:	4c 89 fa             	mov    rdx,r15
     41d:	48 31 ca             	xor    rdx,rcx
     420:	4c 01 c2             	add    rdx,r8
     423:	49 89 d0             	mov    r8,rdx
     426:	49 c1 e8 2d          	shr    r8,0x2d
     42a:	48 c1 e2 13          	shl    rdx,0x13
     42e:	4c 09 c2             	or     rdx,r8
     431:	49 be ac 44 c9 49 89 	movabs r14,0x49c0588949c944ac
     438:	58 c0 49 
     43b:	49 89 c8             	mov    r8,rcx
     43e:	49 01 f8             	add    r8,rdi
     441:	4d 31 f0             	xor    r8,r14
     444:	4d 89 c6             	mov    r14,r8
     447:	49 c1 ee 1b          	shr    r14,0x1b
     44b:	49 c1 e0 25          	shl    r8,0x25
     44f:	4d 09 f0             	or     r8,r14
     452:	4d 31 f8             	xor    r8,r15
     455:	48 01 f2             	add    rdx,rsi
     458:	48 be 0a 0d 44 3b 52 	movabs rsi,0x8aac93523b440d0a
     45f:	93 ac 8a 
     462:	49 89 d7             	mov    r15,rdx
     465:	4d 01 c7             	add    r15,r8
     468:	49 31 f7             	xor    r15,rsi
     46b:	4c 89 fe             	mov    rsi,r15
     46e:	48 c1 ee 39          	shr    rsi,0x39
     472:	49 c1 e7 07          	shl    r15,0x7
     476:	49 09 f7             	or     r15,rsi
     479:	48 be db a8 86 c2 ed 	movabs rsi,0xea3675edc286a8db
     480:	75 36 ea 
     483:	49 89 d6             	mov    r14,rdx
     486:	49 31 fe             	xor    r14,rdi
     489:	49 01 f6             	add    r14,rsi
     48c:	4c 89 f6             	mov    rsi,r14
     48f:	48 c1 ee 11          	shr    rsi,0x11
     493:	49 c1 e6 2f          	shl    r14,0x2f
     497:	49 09 f6             	or     r14,rsi
     49a:	49 31 ff             	xor    r15,rdi
     49d:	49 01 ce             	add    r14,rcx
     4a0:	48 bf 39 71 01 b4 b6 	movabs rdi,0x2b22b0b6b4017139
     4a7:	b0 22 2b 
     4aa:	4c 89 c1             	mov    rcx,r8
     4ad:	4c 31 f1             	xor    rcx,r14
     4b0:	48 01 f9             	add    rcx,rdi
     4b3:	48 89 cf             	mov    rdi,rcx
     4b6:	48 c1 ef 29          	shr    rdi,0x29
     4ba:	48 c1 e1 17          	shl    rcx,0x17
     4be:	48 09 f9             	or     rcx,rdi
     4c1:	48 be 68 d5 be 2c 1b 	movabs rsi,0xcb98ce1b2cbed568
     4c8:	ce 98 cb 
     4cb:	4c 89 f7             	mov    rdi,r14
     4ce:	4c 01 ff             	add    rdi,r15
     4d1:	48 31 f7             	xor    rdi,rsi
     4d4:	48 89 fe             	mov    rsi,rdi
     4d7:	48 c1 ee 17          	shr    rsi,0x17
     4db:	48 c1 e7 29          	shl    rdi,0x29
     4df:	48 09 f7             	or     rdi,rsi
     4e2:	4c 31 c7             	xor    rdi,r8
     4e5:	48 01 d1             	add    rcx,rdx
     4e8:	48 ba c6 9d 39 1e e4 	movabs rdx,0xc8508e41e399dc6
     4ef:	08 85 0c 
     4f2:	48 89 ce             	mov    rsi,rcx
     4f5:	48 01 fe             	add    rsi,rdi
     4f8:	48 31 d6             	xor    rsi,rdx
     4fb:	48 89 f2             	mov    rdx,rsi
     4fe:	48 c1 ea 3b          	shr    rdx,0x3b
     502:	48 c1 e6 05          	shl    rsi,0x5
     506:	48 09 d6             	or     rsi,rdx
     509:	49 b8 97 39 7c a5 7f 	movabs r8,0x6c0eeb7fa57c3997
     510:	eb 0e 6c 
     513:	48 89 ca             	mov    rdx,rcx
     516:	4c 31 fa             	xor    rdx,r15
     519:	4c 01 c2             	add    rdx,r8
     51c:	49 89 d0             	mov    r8,rdx
     51f:	49 c1 e8 0b          	shr    r8,0xb
     523:	48 c1 e2 35          	shl    rdx,0x35
     527:	4c 09 c2             	or     rdx,r8
     52a:	4c 31 fe             	xor    rsi,r15
     52d:	4c 01 f2             	add    rdx,r14
     530:	49 b8 6c 0c e9 34 cf 	movabs r8,0xbe5466cf34e90c6c
     537:	66 54 be 
     53a:	4c 31 c0             	xor    rax,r8
     53d:	49 b8 89 6c 4e ec 98 	movabs r8,0x82efa98ec4e6c89
     544:	fa 2e 08 
     547:	4c 31 c3             	xor    rbx,r8
     54a:	48 89 5d f0          	mov    QWORD PTR [rbp-0x10],rbx
     54e:	49 b8 04 57 15 48 64 	movabs r8,0x9a0b956448155704
     555:	95 0b 9a 
     558:	4c 8b 75 f8          	mov    r14,QWORD PTR [rbp-0x8]
     55c:	4d 31 c6             	xor    r14,r8
     55f:	49 89 d8             	mov    r8,rbx
     562:	48 bb 44 e0 07 f8 1d 	movabs rbx,0x3ead971df807e044
     569:	97 ad 3e 
     56c:	49 01 d8             	add    r8,rbx
     56f:	48 bb c5 4d d5 56 9b 	movabs rbx,0x3a3e419b56d54dc5
     576:	41 3e 3a 
     579:	4c 8b 6d e8          	mov    r13,QWORD PTR [rbp-0x18]
     57d:	4d 89 ef             	mov    r15,r13
     580:	49 31 df             	xor    r15,rbx
     583:	4c 01 f9             	add    rcx,r15
     586:	4c 31 c7             	xor    rdi,r8
     589:	4c 01 f2             	add    rdx,r14
     58c:	49 89 c0             	mov    r8,rax
     58f:	48 bb a2 a8 82 e9 e6 	movabs rbx,0x7f99d1e6e982a8a2
     596:	d1 99 7f 
     599:	49 01 d8             	add    r8,rbx
     59c:	4c 31 c6             	xor    rsi,r8
     59f:	49 b8 24 66 b4 0f ad 	movabs r8,0x4d7143ad0fb46624
     5a6:	43 71 4d 
     5a9:	48 89 d3             	mov    rbx,rdx
     5ac:	48 01 f3             	add    rbx,rsi
     5af:	4c 31 c3             	xor    rbx,r8
     5b2:	49 89 d8             	mov    r8,rbx
     5b5:	49 c1 e8 2f          	shr    r8,0x2f
     5b9:	48 c1 e3 11          	shl    rbx,0x11
     5bd:	4c 09 c3             	or     rbx,r8
     5c0:	49 b8 f5 01 f7 96 48 	movabs r8,0xacfb264896f701f5
     5c7:	26 fb ac 
     5ca:	48 31 fb             	xor    rbx,rdi
     5cd:	48 31 d7             	xor    rdi,rdx
     5d0:	4c 01 c7             	add    rdi,r8
     5d3:	49 89 f8             	mov    r8,rdi
     5d6:	49 c1 e8 33          	shr    r8,0x33
     5da:	48 c1 e7 0d          	shl    rdi,0xd
     5de:	4c 09 c7             	or     rdi,r8
     5e1:	48 01 cf             	add    rdi,rcx
     5e4:	49 b8 82 2e 2f 01 76 	movabs r8,0x8e5d7e76012f2e82
     5eb:	7e 5d 8e 
     5ee:	48 89 d9             	mov    rcx,rbx
     5f1:	48 01 f9             	add    rcx,rdi
     5f4:	4c 31 c1             	xor    rcx,r8
     5f7:	49 89 c8             	mov    r8,rcx
     5fa:	49 c1 e8 15          	shr    r8,0x15
     5fe:	48 c1 e1 2b          	shl    rcx,0x2b
     602:	4c 09 c1             	or     rcx,r8
     605:	49 b8 53 ca 71 88 11 	movabs r8,0xede761118871ca53
     60c:	61 e7 ed 
     60f:	49 89 fe             	mov    r14,rdi
     612:	49 31 f6             	xor    r14,rsi
     615:	4d 01 c6             	add    r14,r8
     618:	4d 89 f0             	mov    r8,r14
     61b:	49 c1 e8 23          	shr    r8,0x23
     61f:	49 c1 e6 1d          	shl    r14,0x1d
     623:	4d 09 c6             	or     r14,r8
     626:	48 31 f1             	xor    rcx,rsi
     629:	49 01 d6             	add    r14,rdx
     62c:	48 ba b1 92 ec 79 da 	movabs rdx,0x2ed39bda79ec92b1
     633:	9b d3 2e 
     636:	48 89 de             	mov    rsi,rbx
     639:	4c 31 f6             	xor    rsi,r14
     63c:	48 01 d6             	add    rsi,rdx
     63f:	48 89 f2             	mov    rdx,rsi
     642:	48 c1 ea 35          	shr    rdx,0x35
     646:	48 c1 e6 0b          	shl    rsi,0xb
     64a:	48 09 d6             	or     rsi,rdx
     64d:	48 ba e0 f6 a9 f2 3e 	movabs rdx,0xcf49b93ef2a9f6e0
     654:	b9 49 cf 
     657:	4d 89 f0             	mov    r8,r14
     65a:	49 01 c8             	add    r8,rcx
     65d:	49 31 d0             	xor    r8,rdx
     660:	4c 89 c2             	mov    rdx,r8
     663:	48 c1 ea 2d          	shr    rdx,0x2d
     667:	49 c1 e0 13          	shl    r8,0x13
     66b:	49 09 d0             	or     r8,rdx
     66e:	49 31 d8             	xor    r8,rbx
     671:	48 01 fe             	add    rsi,rdi
     674:	48 bf 3e bf 24 e4 07 	movabs rdi,0x1035f407e424bf3e
     67b:	f4 35 10 
     67e:	48 89 f2             	mov    rdx,rsi
     681:	4c 01 c2             	add    rdx,r8
     684:	48 31 fa             	xor    rdx,rdi
     687:	48 89 d7             	mov    rdi,rdx
     68a:	48 c1 ef 11          	shr    rdi,0x11
     68e:	48 c1 e2 2f          	shl    rdx,0x2f
     692:	48 09 fa             	or     rdx,rdi
     695:	48 bf 0f 5b 67 6b a3 	movabs rdi,0x6fbfd6a36b675b0f
     69c:	d6 bf 6f 
     69f:	48 89 f3             	mov    rbx,rsi
     6a2:	48 31 cb             	xor    rbx,rcx
     6a5:	48 01 fb             	add    rbx,rdi
     6a8:	48 89 df             	mov    rdi,rbx
     6ab:	48 c1 ef 21          	shr    rdi,0x21
     6af:	48 c1 e3 1f          	shl    rbx,0x1f
     6b3:	48 09 fb             	or     rbx,rdi
     6b6:	48 31 ca             	xor    rdx,rcx
     6b9:	4c 01 f3             	add    rbx,r14
     6bc:	48 b9 6d 23 e2 5c 6c 	movabs rcx,0xb0ac116c5ce2236d
     6c3:	11 ac b0 
     6c6:	4c 89 c7             	mov    rdi,r8
     6c9:	48 31 df             	xor    rdi,rbx
     6cc:	48 01 cf             	add    rdi,rcx
     6cf:	48 89 f9             	mov    rcx,rdi
     6d2:	48 c1 e9 39          	shr    rcx,0x39
     6d6:	48 c1 e7 07          	shl    rdi,0x7
     6da:	48 09 cf             	or     rdi,rcx
     6dd:	48 b9 9c 87 9f d5 d0 	movabs rcx,0x51222ed0d59f879c
     6e4:	2e 22 51 
     6e7:	49 89 df             	mov    r15,rbx
     6ea:	49 01 d7             	add    r15,rdx
     6ed:	49 31 cf             	xor    r15,rcx
     6f0:	4c 89 f9             	mov    rcx,r15
     6f3:	48 c1 e9 29          	shr    rcx,0x29
     6f7:	49 c1 e7 17          	shl    r15,0x17
     6fb:	49 09 cf             	or     r15,rcx
     6fe:	4d 31 c7             	xor    r15,r8
     701:	48 01 f7             	add    rdi,rsi
     704:	48 be fa 4f 1a c7 99 	movabs rsi,0x920e6999c71a4ffa
     70b:	69 0e 92 
     70e:	48 89 f9             	mov    rcx,rdi
     711:	4c 01 f9             	add    rcx,r15
     714:	48 31 f1             	xor    rcx,rsi
     717:	48 89 ce             	mov    rsi,rcx
     71a:	48 c1 ee 0b          	shr    rsi,0xb
     71e:	48 c1 e1 35          	shl    rcx,0x35
     722:	48 09 f1             	or     rcx,rsi
     725:	48 be cb eb 5c 4e 35 	movabs rsi,0xf1984c354e5cebcb
     72c:	4c 98 f1 
     72f:	49 89 fe             	mov    r14,rdi
     732:	49 31 d6             	xor    r14,rdx
     735:	49 01 f6             	add    r14,rsi
     738:	4c 89 f6             	mov    rsi,r14
     73b:	48 c1 ee 1b          	shr    rsi,0x1b
     73f:	49 c1 e6 25          	shl    r14,0x25
     743:	49 09 f6             	or     r14,rsi
     746:	48 31 d1             	xor    rcx,rdx
     749:	49 01 de             	add    r14,rbx
     74c:	48 ba 29 b4 d7 3f fe 	movabs rdx,0x328486fe3fd7b429
     753:	86 84 32 
     756:	4c 89 fe             	mov    rsi,r15
     759:	4c 31 f6             	xor    rsi,r14
     75c:	48 01 d6             	add    rsi,rdx
     75f:	48 89 f2             	mov    rdx,rsi
     762:	48 c1 ea 3b          	shr    rdx,0x3b
     766:	48 c1 e6 05          	shl    rsi,0x5
     76a:	48 09 d6             	or     rsi,rdx
     76d:	48 ba 58 18 95 b8 62 	movabs rdx,0xd2faa462b8951858
     774:	a4 fa d2 
     777:	4d 89 f0             	mov    r8,r14
     77a:	49 01 c8             	add    r8,rcx
     77d:	49 31 d0             	xor    r8,rdx
     780:	4c 89 c2             	mov    rdx,r8
     783:	48 c1 ea 25          	shr    rdx,0x25
     787:	49 c1 e0 1b          	shl    r8,0x1b
     78b:	49 09 d0             	or     r8,rdx
     78e:	4d 31 f8             	xor    r8,r15
     791:	48 01 fe             	add    rsi,rdi
     794:	48 bf b6 e0 0f aa 2b 	movabs rdi,0x13e6df2baa0fe0b6
     79b:	df e6 13 
     79e:	48 89 f2             	mov    rdx,rsi
     7a1:	4c 01 c2             	add    rdx,r8
     7a4:	48 31 fa             	xor    rdx,rdi
     7a7:	48 89 d7             	mov    rdi,rdx
     7aa:	48 c1 ef 05          	shr    rdi,0x5
     7ae:	48 c1 e2 3b          	shl    rdx,0x3b
     7b2:	48 09 fa             	or     rdx,rdi
     7b5:	48 bf 87 7c 52 31 c7 	movabs rdi,0x7370c1c731527c87
     7bc:	c1 70 73 
     7bf:	48 89 f3             	mov    rbx,rsi
     7c2:	48 31 cb             	xor    rbx,rcx
     7c5:	48 01 fb             	add    rbx,rdi
     7c8:	48 89 df             	mov    rdi,rbx
     7cb:	48 c1 ef 17          	shr    rdi,0x17
     7cf:	48 c1 e3 29          	shl    rbx,0x29
     7d3:	48 09 fb             	or     rbx,rdi
     7d6:	48 31 ca             	xor    rdx,rcx
     7d9:	4c 01 f3             	add    rbx,r14
     7dc:	48 b9 e5 44 cd 22 90 	movabs rcx,0xb45cfc9022cd44e5
     7e3:	fc 5c b4 
     7e6:	4c 89 c7             	mov    rdi,r8
     7e9:	48 31 df             	xor    rdi,rbx
     7ec:	48 01 cf             	add    rdi,rcx
     7ef:	48 89 f9             	mov    rcx,rdi
     7f2:	48 c1 e9 3d          	shr    rcx,0x3d
     7f6:	48 c1 e7 03          	shl    rdi,0x3
     7fa:	48 09 cf             	or     rdi,rcx
     7fd:	48 b9 14 a9 8a 9b f4 	movabs rcx,0x54d319f49b8aa914
     804:	19 d3 54 
     807:	49 89 df             	mov    r15,rbx
     80a:	49 01 d7             	add    r15,rdx
     80d:	49 31 cf             	xor    r15,rcx
     810:	4c 89 f9             	mov    rcx,r15
     813:	48 c1 e9 33          	shr    rcx,0x33
     817:	49 c1 e7 0d          	shl    r15,0xd
     81b:	49 09 cf             	or     r15,rcx
     81e:	4d 31 c7             	xor    r15,r8
     821:	48 01 f7             	add    rdi,rsi
     824:	48 be 72 71 05 8d bd 	movabs rsi,0x95bf54bd8d057172
     82b:	54 bf 95 
     82e:	48 89 f9             	mov    rcx,rdi
     831:	4c 01 f9             	add    rcx,r15
     834:	48 31 f1             	xor    rcx,rsi
     837:	48 89 ce             	mov    rsi,rcx
     83a:	48 c1 ee 03          	shr    rsi,0x3
     83e:	48 c1 e1 3d          	shl    rcx,0x3d
     842:	48 09 f1             	or     rcx,rsi
     845:	48 be 43 0d 48 14 59 	movabs rsi,0xf549375914480d43
     84c:	37 49 f5 
     84f:	49 89 fe             	mov    r14,rdi
     852:	49 31 d6             	xor    r14,rdx
     855:	49 01 f6             	add    r14,rsi
     858:	4c 89 f6             	mov    rsi,r14
     85b:	48 c1 ee 23          	shr    rsi,0x23
     85f:	49 c1 e6 1d          	shl    r14,0x1d
     863:	49 09 f6             	or     r14,rsi
     866:	48 31 d1             	xor    rcx,rdx
     869:	49 01 de             	add    r14,rbx
     86c:	48 ba a1 d5 c2 05 22 	movabs rdx,0x3635722205c2d5a1
     873:	72 35 36 
     876:	4c 89 fe             	mov    rsi,r15
     879:	4c 31 f6             	xor    rsi,r14
     87c:	48 01 d6             	add    rsi,rdx
     87f:	48 89 f2             	mov    rdx,rsi
     882:	48 c1 ea 2f          	shr    rdx,0x2f
     886:	48 c1 e6 11          	shl    rsi,0x11
     88a:	48 09 d6             	or     rsi,rdx
     88d:	48 ba d0 39 80 7e 86 	movabs rdx,0xd6ab8f867e8039d0
     894:	8f ab d6 
     897:	4d 89 f0             	mov    r8,r14
     89a:	49 01 c8             	add    r8,rcx
     89d:	49 31 d0             	xor    r8,rdx
     8a0:	4c 89 c2             	mov    rdx,r8
     8a3:	48 c1 ea 21          	shr    rdx,0x21
     8a7:	49 c1 e0 1f          	shl    r8,0x1f
     8ab:	49 09 d0             	or     r8,rdx
     8ae:	4d 31 f8             	xor    r8,r15
     8b1:	48 01 fe             	add    rsi,rdi
     8b4:	48 ba 2e 02 fb 6f 4f 	movabs rdx,0x1797ca4f6ffb022e
     8bb:	ca 97 17 
     8be:	48 89 f7             	mov    rdi,rsi
     8c1:	4c 01 c7             	add    rdi,r8
     8c4:	48 31 d7             	xor    rdi,rdx
     8c7:	48 89 fa             	mov    rdx,rdi
     8ca:	48 c1 ea 35          	shr    rdx,0x35
     8ce:	48 c1 e7 0b          	shl    rdi,0xb
     8d2:	48 09 d7             	or     rdi,rdx
     8d5:	48 ba ff 9d 3d f7 ea 	movabs rdx,0x7721aceaf73d9dff
     8dc:	ac 21 77 
     8df:	49 89 f7             	mov    r15,rsi
     8e2:	49 31 cf             	xor    r15,rcx
     8e5:	49 01 d7             	add    r15,rdx
     8e8:	4c 89 fa             	mov    rdx,r15
     8eb:	48 c1 ea 15          	shr    rdx,0x15
     8ef:	49 c1 e7 2b          	shl    r15,0x2b
     8f3:	49 09 d7             	or     r15,rdx
     8f6:	48 31 cf             	xor    rdi,rcx
     8f9:	4d 01 f7             	add    r15,r14
     8fc:	48 b9 5d 66 b8 e8 b3 	movabs rcx,0xb80de7b3e8b8665d
     903:	e7 0d b8 
     906:	4c 89 c2             	mov    rdx,r8
     909:	4c 31 fa             	xor    rdx,r15
     90c:	48 01 ca             	add    rdx,rcx
     90f:	48 89 d1             	mov    rcx,rdx
     912:	48 c1 e9 2d          	shr    rcx,0x2d
     916:	48 c1 e2 13          	shl    rdx,0x13
     91a:	48 09 ca             	or     rdx,rcx
     91d:	48 bb 8c ca 75 61 18 	movabs rbx,0x588405186175ca8c
     924:	05 84 58 
     927:	4c 89 f9             	mov    rcx,r15
     92a:	48 01 f9             	add    rcx,rdi
     92d:	48 31 d9             	xor    rcx,rbx
     930:	48 89 cb             	mov    rbx,rcx
     933:	48 c1 eb 1b          	shr    rbx,0x1b
     937:	48 c1 e1 25          	shl    rcx,0x25
     93b:	48 09 d9             	or     rcx,rbx
     93e:	4c 31 c1             	xor    rcx,r8
     941:	48 01 f2             	add    rdx,rsi
     944:	48 be ea 92 f0 52 e1 	movabs rsi,0x99703fe152f092ea
     94b:	3f 70 99 
     94e:	48 89 d3             	mov    rbx,rdx
     951:	48 01 cb             	add    rbx,rcx
     954:	48 31 f3             	xor    rbx,rsi
     957:	48 89 de             	mov    rsi,rbx
     95a:	48 c1 ee 39          	shr    rsi,0x39
     95e:	48 c1 e3 07          	shl    rbx,0x7
     962:	48 09 f3             	or     rbx,rsi
     965:	48 be bb 2e 33 da 7c 	movabs rsi,0xf8fa227cda332ebb
     96c:	22 fa f8 
     96f:	49 89 d6             	mov    r14,rdx
     972:	49 31 fe             	xor    r14,rdi
     975:	49 01 f6             	add    r14,rsi
     978:	4c 89 f6             	mov    rsi,r14
     97b:	48 c1 ee 11          	shr    rsi,0x11
     97f:	49 c1 e6 2f          	shl    r14,0x2f
     983:	49 09 f6             	or     r14,rsi
     986:	48 31 fb             	xor    rbx,rdi
     989:	4d 01 fe             	add    r14,r15
     98c:	48 bf 19 f7 ad cb 45 	movabs rdi,0x39e65d45cbadf719
     993:	5d e6 39 
     996:	48 89 ce             	mov    rsi,rcx
     999:	4c 31 f6             	xor    rsi,r14
     99c:	48 01 fe             	add    rsi,rdi
     99f:	48 89 f7             	mov    rdi,rsi
     9a2:	48 c1 ef 29          	shr    rdi,0x29
     9a6:	48 c1 e6 17          	shl    rsi,0x17
     9aa:	48 09 fe             	or     rsi,rdi
     9ad:	49 b8 48 5b 6b 44 aa 	movabs r8,0xda5c7aaa446b5b48
     9b4:	7a 5c da 
     9b7:	4c 89 f7             	mov    rdi,r14
     9ba:	48 01 df             	add    rdi,rbx
     9bd:	4c 31 c7             	xor    rdi,r8
     9c0:	49 89 f8             	mov    r8,rdi
     9c3:	49 c1 e8 17          	shr    r8,0x17
     9c7:	48 c1 e7 29          	shl    rdi,0x29
     9cb:	4c 09 c7             	or     rdi,r8
     9ce:	48 31 cf             	xor    rdi,rcx
     9d1:	48 01 d6             	add    rsi,rdx
     9d4:	48 b9 a6 23 e6 35 73 	movabs rcx,0x1b48b57335e623a6
     9db:	b5 48 1b 
     9de:	48 89 f2             	mov    rdx,rsi
     9e1:	48 01 fa             	add    rdx,rdi
     9e4:	48 31 ca             	xor    rdx,rcx
     9e7:	48 89 d1             	mov    rcx,rdx
     9ea:	48 c1 e9 3b          	shr    rcx,0x3b
     9ee:	48 c1 e2 05          	shl    rdx,0x5
     9f2:	48 09 ca             	or     rdx,rcx
     9f5:	49 b8 77 bf 28 bd 0e 	movabs r8,0x7ad2980ebd28bf77
     9fc:	98 d2 7a 
     9ff:	48 89 f1             	mov    rcx,rsi
     a02:	48 31 d9             	xor    rcx,rbx
     a05:	4c 01 c1             	add    rcx,r8
     a08:	49 89 c8             	mov    r8,rcx
     a0b:	49 c1 e8 0b          	shr    r8,0xb
     a0f:	48 c1 e1 35          	shl    rcx,0x35
     a13:	4c 09 c1             	or     rcx,r8
     a16:	48 31 da             	xor    rdx,rbx
     a19:	4c 01 f1             	add    rcx,r14
     a1c:	49 b8 d5 bb 52 d1 00 	movabs r8,0x3ab1f000d152bbd5
     a23:	f0 b1 3a 
     a26:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
     a2a:	4c 31 c3             	xor    rbx,r8
     a2d:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
     a31:	49 be 73 44 c5 70 82 	movabs r14,0xdf23b48270c54473
     a38:	b4 23 df 
     a3b:	4d 01 f0             	add    r8,r14
     a3e:	49 be 94 d1 98 d1 3f 	movabs r14,0x9aa4af3fd198d194
     a45:	af a4 9a 
     a48:	4d 89 ef             	mov    r15,r13
     a4b:	4d 31 f7             	xor    r15,r14
     a4e:	4c 01 fe             	add    rsi,r15
     a51:	4c 31 c7             	xor    rdi,r8
     a54:	48 01 d9             	add    rcx,rbx
     a57:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
     a5b:	49 89 c0             	mov    r8,rax
     a5e:	48 bb d1 0c 40 62 4b 	movabs rbx,0x200fef4b62400cd1
     a65:	ef 0f 20 
     a68:	49 01 d8             	add    r8,rbx
     a6b:	4c 31 c2             	xor    rdx,r8
     a6e:	49 b8 04 ec 60 27 3c 	movabs r8,0x5c34f03c2760ec04
     a75:	f0 34 5c 
     a78:	48 89 cb             	mov    rbx,rcx
     a7b:	48 01 d3             	add    rbx,rdx
     a7e:	4c 31 c3             	xor    rbx,r8
     a81:	49 89 d8             	mov    r8,rbx
     a84:	49 c1 e8 2f          	shr    r8,0x2f
     a88:	48 c1 e3 11          	shl    rbx,0x11
     a8c:	4c 09 c3             	or     rbx,r8
     a8f:	49 b8 d5 87 a3 ae d7 	movabs r8,0xbbbed2d7aea387d5
     a96:	d2 be bb 
     a99:	48 31 fb             	xor    rbx,rdi
     a9c:	48 31 cf             	xor    rdi,rcx
     a9f:	4c 01 c7             	add    rdi,r8
     aa2:	49 89 f8             	mov    r8,rdi
     aa5:	49 c1 e8 33          	shr    r8,0x33
     aa9:	48 c1 e7 0d          	shl    rdi,0xd
     aad:	4c 09 c7             	or     rdi,r8
     ab0:	48 01 f7             	add    rdi,rsi
     ab3:	48 be 62 b4 db 18 05 	movabs rsi,0x9d212b0518dbb462
     aba:	2b 21 9d 
     abd:	49 89 df             	mov    r15,rbx
     ac0:	49 01 ff             	add    r15,rdi
     ac3:	49 31 f7             	xor    r15,rsi
     ac6:	4c 89 fe             	mov    rsi,r15
     ac9:	48 c1 ee 15          	shr    rsi,0x15
     acd:	49 c1 e7 2b          	shl    r15,0x2b
     ad1:	49 09 f7             	or     r15,rsi
     ad4:	48 be 33 50 1e a0 a0 	movabs rsi,0xfcab0da0a01e5033
     adb:	0d ab fc 
     ade:	49 89 fe             	mov    r14,rdi
     ae1:	49 31 d6             	xor    r14,rdx
     ae4:	49 01 f6             	add    r14,rsi
     ae7:	4c 89 f6             	mov    rsi,r14
     aea:	48 c1 ee 23          	shr    rsi,0x23
     aee:	49 c1 e6 1d          	shl    r14,0x1d
     af2:	49 09 f6             	or     r14,rsi
     af5:	49 31 d7             	xor    r15,rdx
     af8:	49 01 ce             	add    r14,rcx
     afb:	48 ba 91 18 99 91 69 	movabs rdx,0x3d97486991991891
     b02:	48 97 3d 
     b05:	48 89 de             	mov    rsi,rbx
     b08:	4c 31 f6             	xor    rsi,r14
     b0b:	48 01 d6             	add    rsi,rdx
     b0e:	48 89 f2             	mov    rdx,rsi
     b11:	48 c1 ea 35          	shr    rdx,0x35
     b15:	48 c1 e6 0b          	shl    rsi,0xb
     b19:	48 09 d6             	or     rsi,rdx
     b1c:	48 ba c0 7c 56 0a ce 	movabs rdx,0xde0d65ce0a567cc0
     b23:	65 0d de 
     b26:	4c 89 f1             	mov    rcx,r14
     b29:	4c 01 f9             	add    rcx,r15
     b2c:	48 31 d1             	xor    rcx,rdx
     b2f:	48 89 ca             	mov    rdx,rcx
     b32:	48 c1 ea 2d          	shr    rdx,0x2d
     b36:	48 c1 e1 13          	shl    rcx,0x13
     b3a:	48 09 d1             	or     rcx,rdx
     b3d:	48 31 d9             	xor    rcx,rbx
     b40:	48 01 fe             	add    rsi,rdi
     b43:	48 bf 1e 45 d1 fb 96 	movabs rdi,0x1ef9a096fbd1451e
     b4a:	a0 f9 1e 
     b4d:	48 89 f2             	mov    rdx,rsi
     b50:	48 01 ca             	add    rdx,rcx
     b53:	48 31 fa             	xor    rdx,rdi
     b56:	48 89 d7             	mov    rdi,rdx
     b59:	48 c1 ef 11          	shr    rdi,0x11
     b5d:	48 c1 e2 2f          	shl    rdx,0x2f
     b61:	48 09 fa             	or     rdx,rdi
     b64:	48 bf ef e0 13 83 32 	movabs rdi,0x7e8383328313e0ef
     b6b:	83 83 7e 
     b6e:	48 89 f3             	mov    rbx,rsi
     b71:	4c 31 fb             	xor    rbx,r15
     b74:	48 01 fb             	add    rbx,rdi
     b77:	48 89 df             	mov    rdi,rbx
     b7a:	48 c1 ef 21          	shr    rdi,0x21
     b7e:	48 c1 e3 1f          	shl    rbx,0x1f
     b82:	48 09 fb             	or     rbx,rdi
     b85:	4c 31 fa             	xor    rdx,r15
     b88:	4c 01 f3             	add    rbx,r14
     b8b:	49 b8 4d a9 8e 74 fb 	movabs r8,0xbf6fbdfb748ea94d
     b92:	bd 6f bf 
     b95:	48 89 cf             	mov    rdi,rcx
     b98:	48 31 df             	xor    rdi,rbx
     b9b:	4c 01 c7             	add    rdi,r8
     b9e:	49 89 f8             	mov    r8,rdi
     ba1:	49 c1 e8 39          	shr    r8,0x39
     ba5:	48 c1 e7 07          	shl    rdi,0x7
     ba9:	4c 09 c7             	or     rdi,r8
     bac:	49 be 7c 0d 4c ed 5f 	movabs r14,0x5fe5db5fed4c0d7c
     bb3:	db e5 5f 
     bb6:	49 89 d8             	mov    r8,rbx
     bb9:	49 01 d0             	add    r8,rdx
     bbc:	4d 31 f0             	xor    r8,r14
     bbf:	4d 89 c6             	mov    r14,r8
     bc2:	49 c1 ee 29          	shr    r14,0x29
     bc6:	49 c1 e0 17          	shl    r8,0x17
     bca:	4d 09 f0             	or     r8,r14
     bcd:	49 31 c8             	xor    r8,rcx
     bd0:	48 01 f7             	add    rdi,rsi
     bd3:	48 be da d5 c6 de 28 	movabs rsi,0xa0d21628dec6d5da
     bda:	16 d2 a0 
     bdd:	48 89 f9             	mov    rcx,rdi
     be0:	4c 01 c1             	add    rcx,r8
     be3:	48 31 f1             	xor    rcx,rsi
     be6:	48 89 ce             	mov    rsi,rcx
     be9:	48 c1 ee 0b          	shr    rsi,0xb
     bed:	48 c1 e1 35          	shl    rcx,0x35
     bf1:	48 09 f1             	or     rcx,rsi
     bf4:	48 be ab 71 09 66 c4 	movabs rsi,0x5bf8c4660971ab
     bfb:	f8 5b 00 
     bfe:	49 89 fe             	mov    r14,rdi
     c01:	49 31 d6             	xor    r14,rdx
     c04:	49 01 f6             	add    r14,rsi
     c07:	4c 89 f6             	mov    rsi,r14
     c0a:	48 c1 ee 1b          	shr    rsi,0x1b
     c0e:	49 c1 e6 25          	shl    r14,0x25
     c12:	49 09 f6             	or     r14,rsi
     c15:	48 31 d1             	xor    rcx,rdx
     c18:	49 01 de             	add    r14,rbx
     c1b:	48 ba 09 3a 84 57 8d 	movabs rdx,0x4148338d57843a09
     c22:	33 48 41 
     c25:	4c 89 c6             	mov    rsi,r8
     c28:	4c 31 f6             	xor    rsi,r14
     c2b:	48 01 d6             	add    rsi,rdx
     c2e:	48 89 f2             	mov    rdx,rsi
     c31:	48 c1 ea 3b          	shr    rdx,0x3b
     c35:	48 c1 e6 05          	shl    rsi,0x5
     c39:	48 09 d6             	or     rsi,rdx
     c3c:	48 ba 38 9e 41 d0 f1 	movabs rdx,0xe1be50f1d0419e38
     c43:	50 be e1 
     c46:	4d 89 f7             	mov    r15,r14
     c49:	49 01 cf             	add    r15,rcx
     c4c:	49 31 d7             	xor    r15,rdx
     c4f:	4c 89 fa             	mov    rdx,r15
     c52:	48 c1 ea 25          	shr    rdx,0x25
     c56:	49 c1 e7 1b          	shl    r15,0x1b
     c5a:	49 09 d7             	or     r15,rdx
     c5d:	4d 31 c7             	xor    r15,r8
     c60:	48 01 fe             	add    rsi,rdi
     c63:	48 bf 96 66 bc c1 ba 	movabs rdi,0x22aa8bbac1bc6696
     c6a:	8b aa 22 
     c6d:	48 89 f2             	mov    rdx,rsi
     c70:	4c 01 fa             	add    rdx,r15
     c73:	48 31 fa             	xor    rdx,rdi
     c76:	48 89 d7             	mov    rdi,rdx
     c79:	48 c1 ef 05          	shr    rdi,0x5
     c7d:	48 c1 e2 3b          	shl    rdx,0x3b
     c81:	48 09 fa             	or     rdx,rdi
     c84:	48 bf 67 02 ff 48 56 	movabs rdi,0x82346e5648ff0267
     c8b:	6e 34 82 
     c8e:	48 89 f3             	mov    rbx,rsi
     c91:	48 31 cb             	xor    rbx,rcx
     c94:	48 01 fb             	add    rbx,rdi
     c97:	48 89 df             	mov    rdi,rbx
     c9a:	48 c1 ef 17          	shr    rdi,0x17
     c9e:	48 c1 e3 29          	shl    rbx,0x29
     ca2:	48 09 fb             	or     rbx,rdi
     ca5:	48 31 ca             	xor    rdx,rcx
     ca8:	4c 01 f3             	add    rbx,r14
     cab:	48 b9 c5 ca 79 3a 1f 	movabs rcx,0xc320a91f3a79cac5
     cb2:	a9 20 c3 
     cb5:	4c 89 ff             	mov    rdi,r15
     cb8:	48 31 df             	xor    rdi,rbx
     cbb:	48 01 cf             	add    rdi,rcx
     cbe:	48 89 f9             	mov    rcx,rdi
     cc1:	48 c1 e9 3d          	shr    rcx,0x3d
     cc5:	48 c1 e7 03          	shl    rdi,0x3
     cc9:	48 09 cf             	or     rdi,rcx
     ccc:	48 b9 f4 2e 37 b3 83 	movabs rcx,0x6396c683b3372ef4
     cd3:	c6 96 63 
     cd6:	49 89 d8             	mov    r8,rbx
     cd9:	49 01 d0             	add    r8,rdx
     cdc:	49 31 c8             	xor    r8,rcx
     cdf:	4c 89 c1             	mov    rcx,r8
     ce2:	48 c1 e9 33          	shr    rcx,0x33
     ce6:	49 c1 e0 0d          	shl    r8,0xd
     cea:	49 09 c8             	or     r8,rcx
     ced:	4d 31 f8             	xor    r8,r15
     cf0:	48 01 f7             	add    rdi,rsi
     cf3:	48 be 52 f7 b1 a4 4c 	movabs rsi,0xa483014ca4b1f752
     cfa:	01 83 a4 
     cfd:	48 89 f9             	mov    rcx,rdi
     d00:	4c 01 c1             	add    rcx,r8
     d03:	48 31 f1             	xor    rcx,rsi
     d06:	48 89 ce             	mov    rsi,rcx
     d09:	48 c1 ee 03          	shr    rsi,0x3
     d0d:	48 c1 e1 3d          	shl    rcx,0x3d
     d11:	48 09 f1             	or     rcx,rsi
     d14:	48 be 23 93 f4 2b e8 	movabs rsi,0x40ce3e82bf49323
     d1b:	e3 0c 04 
     d1e:	49 89 fe             	mov    r14,rdi
     d21:	49 31 d6             	xor    r14,rdx
     d24:	49 01 f6             	add    r14,rsi
     d27:	4c 89 f6             	mov    rsi,r14
     d2a:	48 c1 ee 23          	shr    rsi,0x23
     d2e:	49 c1 e6 1d          	shl    r14,0x1d
     d32:	49 09 f6             	or     r14,rsi
     d35:	48 31 d1             	xor    rcx,rdx
     d38:	49 01 de             	add    r14,rbx
     d3b:	48 ba 81 5b 6f 1d b1 	movabs rdx,0x44f91eb11d6f5b81
     d42:	1e f9 44 
     d45:	4c 89 c6             	mov    rsi,r8
     d48:	4c 31 f6             	xor    rsi,r14
     d4b:	48 01 d6             	add    rsi,rdx
     d4e:	48 89 f2             	mov    rdx,rsi
     d51:	48 c1 ea 2f          	shr    rdx,0x2f
     d55:	48 c1 e6 11          	shl    rsi,0x11
     d59:	48 09 d6             	or     rsi,rdx
     d5c:	48 ba b0 bf 2c 96 15 	movabs rdx,0xe56f3c15962cbfb0
     d63:	3c 6f e5 
     d66:	4c 89 f3             	mov    rbx,r14
     d69:	48 01 cb             	add    rbx,rcx
     d6c:	48 31 d3             	xor    rbx,rdx
     d6f:	48 89 da             	mov    rdx,rbx
     d72:	48 c1 ea 21          	shr    rdx,0x21
     d76:	48 c1 e3 1f          	shl    rbx,0x1f
     d7a:	48 09 d3             	or     rbx,rdx
     d7d:	4c 31 c3             	xor    rbx,r8
     d80:	48 01 fe             	add    rsi,rdi
     d83:	48 ba 0e 88 a7 87 de 	movabs rdx,0x265b76de87a7880e
     d8a:	76 5b 26 
     d8d:	48 89 f7             	mov    rdi,rsi
     d90:	48 01 df             	add    rdi,rbx
     d93:	48 31 d7             	xor    rdi,rdx
     d96:	48 89 fa             	mov    rdx,rdi
     d99:	48 c1 ea 35          	shr    rdx,0x35
     d9d:	48 c1 e7 0b          	shl    rdi,0xb
     da1:	48 09 d7             	or     rdi,rdx
     da4:	48 ba df 23 ea 0e 7a 	movabs rdx,0x85e5597a0eea23df
     dab:	59 e5 85 
     dae:	49 89 f7             	mov    r15,rsi
     db1:	49 31 cf             	xor    r15,rcx
     db4:	49 01 d7             	add    r15,rdx
     db7:	4c 89 fa             	mov    rdx,r15
     dba:	48 c1 ea 15          	shr    rdx,0x15
     dbe:	49 c1 e7 2b          	shl    r15,0x2b
     dc2:	49 09 d7             	or     r15,rdx
     dc5:	48 31 cf             	xor    rdi,rcx
     dc8:	4d 01 f7             	add    r15,r14
     dcb:	48 b9 3d ec 64 00 43 	movabs rcx,0xc6d194430064ec3d
     dd2:	94 d1 c6 
     dd5:	48 89 da             	mov    rdx,rbx
     dd8:	4c 31 fa             	xor    rdx,r15
     ddb:	48 01 ca             	add    rdx,rcx
     dde:	48 89 d1             	mov    rcx,rdx
     de1:	48 c1 e9 2d          	shr    rcx,0x2d
     de5:	48 c1 e2 13          	shl    rdx,0x13
     de9:	48 09 ca             	or     rdx,rcx
     dec:	49 b8 6c 50 22 79 a7 	movabs r8,0x6747b1a77922506c
     df3:	b1 47 67 
     df6:	4c 89 f9             	mov    rcx,r15
     df9:	48 01 f9             	add    rcx,rdi
     dfc:	4c 31 c1             	xor    rcx,r8
     dff:	49 89 c8             	mov    r8,rcx
     e02:	49 c1 e8 1b          	shr    r8,0x1b
     e06:	48 c1 e1 25          	shl    rcx,0x25
     e0a:	4c 09 c1             	or     rcx,r8
     e0d:	48 31 d9             	xor    rcx,rbx
     e10:	48 01 f2             	add    rdx,rsi
     e13:	48 be ca 18 9d 6a 70 	movabs rsi,0xa833ec706a9d18ca
     e1a:	ec 33 a8 
     e1d:	48 89 d3             	mov    rbx,rdx
     e20:	48 01 cb             	add    rbx,rcx
     e23:	48 31 f3             	xor    rbx,rsi
     e26:	48 89 de             	mov    rsi,rbx
     e29:	48 c1 ee 39          	shr    rsi,0x39
     e2d:	48 c1 e3 07          	shl    rbx,0x7
     e31:	48 09 f3             	or     rbx,rsi
     e34:	48 be 9b b4 df f1 0b 	movabs rsi,0x7bdcf0bf1dfb49b
     e3b:	cf bd 07 
     e3e:	49 89 d6             	mov    r14,rdx
     e41:	49 31 fe             	xor    r14,rdi
     e44:	49 01 f6             	add    r14,rsi
     e47:	4c 89 f6             	mov    rsi,r14
     e4a:	48 c1 ee 11          	shr    rsi,0x11
     e4e:	49 c1 e6 2f          	shl    r14,0x2f
     e52:	49 09 f6             	or     r14,rsi
     e55:	48 31 fb             	xor    rbx,rdi
     e58:	4d 01 fe             	add    r14,r15
     e5b:	48 bf f9 7c 5a e3 d4 	movabs rdi,0x48aa09d4e35a7cf9
     e62:	09 aa 48 
     e65:	48 89 ce             	mov    rsi,rcx
     e68:	4c 31 f6             	xor    rsi,r14
     e6b:	48 01 fe             	add    rsi,rdi
     e6e:	48 89 f7             	mov    rdi,rsi
     e71:	48 c1 ef 29          	shr    rdi,0x29
     e75:	48 c1 e6 17          	shl    rsi,0x17
     e79:	48 09 fe             	or     rsi,rdi
     e7c:	49 b8 28 e1 17 5c 39 	movabs r8,0xe92027395c17e128
     e83:	27 20 e9 
     e86:	4c 89 f7             	mov    rdi,r14
     e89:	48 01 df             	add    rdi,rbx
     e8c:	4c 31 c7             	xor    rdi,r8
     e8f:	49 89 f8             	mov    r8,rdi
     e92:	49 c1 e8 17          	shr    r8,0x17
     e96:	48 c1 e7 29          	shl    rdi,0x29
     e9a:	4c 09 c7             	or     rdi,r8
     e9d:	48 31 cf             	xor    rdi,rcx
     ea0:	48 01 d6             	add    rsi,rdx
     ea3:	48 b9 86 a9 92 4d 02 	movabs rcx,0x2a0c62024d92a986
     eaa:	62 0c 2a 
     ead:	48 89 f2             	mov    rdx,rsi
     eb0:	48 01 fa             	add    rdx,rdi
     eb3:	48 31 ca             	xor    rdx,rcx
     eb6:	48 89 d1             	mov    rcx,rdx
     eb9:	48 c1 e9 3b          	shr    rcx,0x3b
     ebd:	48 c1 e2 05          	shl    rdx,0x5
     ec1:	48 09 ca             	or     rdx,rcx
     ec4:	49 b8 57 45 d5 d4 9d 	movabs r8,0x8996449dd4d54557
     ecb:	44 96 89 
     ece:	48 89 f1             	mov    rcx,rsi
     ed1:	48 31 d9             	xor    rcx,rbx
     ed4:	4c 01 c1             	add    rcx,r8
     ed7:	49 89 c8             	mov    r8,rcx
     eda:	49 c1 e8 0b          	shr    r8,0xb
     ede:	48 c1 e1 35          	shl    rcx,0x35
     ee2:	4c 09 c1             	or     rcx,r8
     ee5:	48 31 da             	xor    rdx,rbx
     ee8:	4c 01 f1             	add    rcx,r14
     eeb:	49 b8 a6 1f 90 5a ad 	movabs r8,0x6527cead5a901fa6
     ef2:	ce 27 65 
     ef5:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
     ef9:	4c 31 c3             	xor    rbx,r8
     efc:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
     f00:	49 be a2 a8 82 e9 e6 	movabs r14,0x7f99d1e6e982a8a2
     f07:	d1 99 7f 
     f0a:	4d 01 f0             	add    r8,r14
     f0d:	49 be a3 75 5a 59 a0 	movabs r14,0x7b2a8ca0595a75a3
     f14:	8c 2a 7b 
     f17:	4d 31 f5             	xor    r13,r14
     f1a:	4c 01 ee             	add    rsi,r13
     f1d:	4c 31 c7             	xor    rdi,r8
     f20:	48 01 d9             	add    rcx,rbx
     f23:	48 bb 00 71 fd da af 	movabs rbx,0xc0860cafdafd7100
     f2a:	0c 86 c0 
     f2d:	48 01 d8             	add    rax,rbx
     f30:	48 31 c2             	xor    rdx,rax
     f33:	49 b8 e4 71 0d 3f cb 	movabs r8,0x6af89ccb3f0d71e4
     f3a:	9c f8 6a 
     f3d:	48 89 cb             	mov    rbx,rcx
     f40:	48 01 d3             	add    rbx,rdx
     f43:	4c 31 c3             	xor    rbx,r8
     f46:	49 89 d8             	mov    r8,rbx
     f49:	49 c1 e8 2f          	shr    r8,0x2f
     f4d:	48 c1 e3 11          	shl    rbx,0x11
     f51:	4c 09 c3             	or     rbx,r8
     f54:	49 b8 b5 0d 50 c6 66 	movabs r8,0xca827f66c6500db5
     f5b:	7f 82 ca 
     f5e:	48 31 fb             	xor    rbx,rdi
     f61:	48 31 cf             	xor    rdi,rcx
     f64:	4c 01 c7             	add    rdi,r8
     f67:	49 89 f8             	mov    r8,rdi
     f6a:	49 c1 e8 33          	shr    r8,0x33
     f6e:	48 c1 e7 0d          	shl    rdi,0xd
     f72:	4c 09 c7             	or     rdi,r8
     f75:	48 01 f7             	add    rdi,rsi
     f78:	48 be 42 3a 88 30 94 	movabs rsi,0xabe4d79430883a42
     f7f:	d7 e4 ab 
     f82:	49 89 df             	mov    r15,rbx
     f85:	49 01 ff             	add    r15,rdi
     f88:	49 31 f7             	xor    r15,rsi
     f8b:	4c 89 fe             	mov    rsi,r15
     f8e:	48 c1 ee 15          	shr    rsi,0x15
     f92:	49 c1 e7 2b          	shl    r15,0x2b
     f96:	49 09 f7             	or     r15,rsi
     f99:	48 be 13 d6 ca b7 2f 	movabs rsi,0xb6eba2fb7cad613
     fa0:	ba 6e 0b 
     fa3:	49 89 fe             	mov    r14,rdi
     fa6:	49 31 d6             	xor    r14,rdx
     fa9:	49 01 f6             	add    r14,rsi
     fac:	4c 89 f6             	mov    rsi,r14
     faf:	48 c1 ee 23          	shr    rsi,0x23
     fb3:	49 c1 e6 1d          	shl    r14,0x1d
     fb7:	49 09 f6             	or     r14,rsi
     fba:	49 31 d7             	xor    r15,rdx
     fbd:	49 01 ce             	add    r14,rcx
     fc0:	48 ba 71 9e 45 a9 f8 	movabs rdx,0x4c5af4f8a9459e71
     fc7:	f4 5a 4c 
     fca:	48 89 de             	mov    rsi,rbx
     fcd:	4c 31 f6             	xor    rsi,r14
     fd0:	48 01 d6             	add    rsi,rdx
     fd3:	48 89 f2             	mov    rdx,rsi
     fd6:	48 c1 ea 35          	shr    rdx,0x35
     fda:	48 c1 e6 0b          	shl    rsi,0xb
     fde:	48 09 d6             	or     rsi,rdx
     fe1:	48 ba a0 02 03 22 5d 	movabs rdx,0xecd1125d220302a0
     fe8:	12 d1 ec 
     feb:	4c 89 f1             	mov    rcx,r14
     fee:	4c 01 f9             	add    rcx,r15
     ff1:	48 31 d1             	xor    rcx,rdx
     ff4:	48 89 ca             	mov    rdx,rcx
     ff7:	48 c1 ea 2d          	shr    rdx,0x2d
     ffb:	48 c1 e1 13          	shl    rcx,0x13
     fff:	48 09 d1             	or     rcx,rdx
    1002:	48 31 d9             	xor    rcx,rbx
    1005:	48 01 fe             	add    rsi,rdi
    1008:	48 bf fe ca 7d 13 26 	movabs rdi,0x2dbd4d26137dcafe
    100f:	4d bd 2d 
    1012:	48 89 f2             	mov    rdx,rsi
    1015:	48 01 ca             	add    rdx,rcx
    1018:	48 31 fa             	xor    rdx,rdi
    101b:	48 89 d7             	mov    rdi,rdx
    101e:	48 c1 ef 11          	shr    rdi,0x11
    1022:	48 c1 e2 2f          	shl    rdx,0x2f
    1026:	48 09 fa             	or     rdx,rdi
    1029:	48 bf cf 66 c0 9a c1 	movabs rdi,0x8d472fc19ac066cf
    1030:	2f 47 8d 
    1033:	48 89 f3             	mov    rbx,rsi
    1036:	4c 31 fb             	xor    rbx,r15
    1039:	48 01 fb             	add    rbx,rdi
    103c:	48 89 df             	mov    rdi,rbx
    103f:	48 c1 ef 21          	shr    rdi,0x21
    1043:	48 c1 e3 1f          	shl    rbx,0x1f
    1047:	48 09 fb             	or     rbx,rdi
    104a:	4c 31 fa             	xor    rdx,r15
    104d:	4c 01 f3             	add    rbx,r14
    1050:	49 b8 2d 2f 3b 8c 8a 	movabs r8,0xce336a8a8c3b2f2d
    1057:	6a 33 ce 
    105a:	48 89 cf             	mov    rdi,rcx
    105d:	48 31 df             	xor    rdi,rbx
    1060:	4c 01 c7             	add    rdi,r8
    1063:	49 89 f8             	mov    r8,rdi
    1066:	49 c1 e8 39          	shr    r8,0x39
    106a:	48 c1 e7 07          	shl    rdi,0x7
    106e:	4c 09 c7             	or     rdi,r8
    1071:	49 be 5c 93 f8 04 ef 	movabs r14,0x6ea987ef04f8935c
    1078:	87 a9 6e 
    107b:	49 89 d8             	mov    r8,rbx
    107e:	49 01 d0             	add    r8,rdx
    1081:	4d 31 f0             	xor    r8,r14
    1084:	4d 89 c6             	mov    r14,r8
    1087:	49 c1 ee 29          	shr    r14,0x29
    108b:	49 c1 e0 17          	shl    r8,0x17
    108f:	4d 09 f0             	or     r8,r14
    1092:	49 31 c8             	xor    r8,rcx
    1095:	48 01 f7             	add    rdi,rsi
    1098:	48 be ba 5b 73 f6 b7 	movabs rsi,0xaf95c2b7f6735bba
    109f:	c2 95 af 
    10a2:	48 89 f9             	mov    rcx,rdi
    10a5:	4c 01 c1             	add    rcx,r8
    10a8:	48 31 f1             	xor    rcx,rsi
    10ab:	48 89 ce             	mov    rsi,rcx
    10ae:	48 c1 ee 0b          	shr    rsi,0xb
    10b2:	48 c1 e1 35          	shl    rcx,0x35
    10b6:	48 09 f1             	or     rcx,rsi
    10b9:	48 be 8b f7 b5 7d 53 	movabs rsi,0xf1fa5537db5f78b
    10c0:	a5 1f 0f 
    10c3:	49 89 fe             	mov    r14,rdi
    10c6:	49 31 d6             	xor    r14,rdx
    10c9:	49 01 f6             	add    r14,rsi
    10cc:	4c 89 f6             	mov    rsi,r14
    10cf:	48 c1 ee 1b          	shr    rsi,0x1b
    10d3:	49 c1 e6 25          	shl    r14,0x25
    10d7:	49 09 f6             	or     r14,rsi
    10da:	48 31 d1             	xor    rcx,rdx
    10dd:	49 01 de             	add    r14,rbx
    10e0:	48 ba e9 bf 30 6f 1c 	movabs rdx,0x500be01c6f30bfe9
    10e7:	e0 0b 50 
    10ea:	4c 89 c6             	mov    rsi,r8
    10ed:	4c 31 f6             	xor    rsi,r14
    10f0:	48 01 d6             	add    rsi,rdx
    10f3:	48 89 f2             	mov    rdx,rsi
    10f6:	48 c1 ea 3b          	shr    rdx,0x3b
    10fa:	48 c1 e6 05          	shl    rsi,0x5
    10fe:	48 09 d6             	or     rsi,rdx
    1101:	48 ba 18 24 ee e7 80 	movabs rdx,0xf081fd80e7ee2418
    1108:	fd 81 f0 
    110b:	4d 89 f7             	mov    r15,r14
    110e:	49 01 cf             	add    r15,rcx
    1111:	49 31 d7             	xor    r15,rdx
    1114:	4c 89 fa             	mov    rdx,r15
    1117:	48 c1 ea 25          	shr    rdx,0x25
    111b:	49 c1 e7 1b          	shl    r15,0x1b
    111f:	49 09 d7             	or     r15,rdx
    1122:	4d 31 c7             	xor    r15,r8
    1125:	48 01 fe             	add    rsi,rdi
    1128:	48 bf 76 ec 68 d9 49 	movabs rdi,0x316e3849d968ec76
    112f:	38 6e 31 
    1132:	48 89 f2             	mov    rdx,rsi
    1135:	4c 01 fa             	add    rdx,r15
    1138:	48 31 fa             	xor    rdx,rdi
    113b:	48 89 d7             	mov    rdi,rdx
    113e:	48 c1 ef 05          	shr    rdi,0x5
    1142:	48 c1 e2 3b          	shl    rdx,0x3b
    1146:	48 09 fa             	or     rdx,rdi
    1149:	48 bf 47 88 ab 60 e5 	movabs rdi,0x90f81ae560ab8847
    1150:	1a f8 90 
    1153:	48 89 f3             	mov    rbx,rsi
    1156:	48 31 cb             	xor    rbx,rcx
    1159:	48 01 fb             	add    rbx,rdi
    115c:	48 89 df             	mov    rdi,rbx
    115f:	48 c1 ef 17          	shr    rdi,0x17
    1163:	48 c1 e3 29          	shl    rbx,0x29
    1167:	48 09 fb             	or     rbx,rdi
    116a:	48 31 ca             	xor    rdx,rcx
    116d:	4c 01 f3             	add    rbx,r14
    1170:	48 b9 a5 50 26 52 ae 	movabs rcx,0xd1e455ae522650a5
    1177:	55 e4 d1 
    117a:	4c 89 ff             	mov    rdi,r15
    117d:	48 31 df             	xor    rdi,rbx
    1180:	48 01 cf             	add    rdi,rcx
    1183:	48 89 f9             	mov    rcx,rdi
    1186:	48 c1 e9 3d          	shr    rcx,0x3d
    118a:	48 c1 e7 03          	shl    rdi,0x3
    118e:	48 09 cf             	or     rdi,rcx
    1191:	48 b9 d4 b4 e3 ca 12 	movabs rcx,0x725a7312cae3b4d4
    1198:	73 5a 72 
    119b:	49 89 d8             	mov    r8,rbx
    119e:	49 01 d0             	add    r8,rdx
    11a1:	49 31 c8             	xor    r8,rcx
    11a4:	4c 89 c1             	mov    rcx,r8
    11a7:	48 c1 e9 33          	shr    rcx,0x33
    11ab:	49 c1 e0 0d          	shl    r8,0xd
    11af:	49 09 c8             	or     r8,rcx
    11b2:	4d 31 f8             	xor    r8,r15
    11b5:	48 01 f7             	add    rdi,rsi
    11b8:	48 be 32 7d 5e bc db 	movabs rsi,0xb346addbbc5e7d32
    11bf:	ad 46 b3 
    11c2:	48 89 f9             	mov    rcx,rdi
    11c5:	4c 01 c1             	add    rcx,r8
    11c8:	48 31 f1             	xor    rcx,rsi
    11cb:	48 89 ce             	mov    rsi,rcx
    11ce:	48 c1 ee 03          	shr    rsi,0x3
    11d2:	48 c1 e1 3d          	shl    rcx,0x3d
    11d6:	48 09 f1             	or     rcx,rsi
    11d9:	48 be 03 19 a1 43 77 	movabs rsi,0x12d0907743a11903
    11e0:	90 d0 12 
    11e3:	49 89 fe             	mov    r14,rdi
    11e6:	49 31 d6             	xor    r14,rdx
    11e9:	49 01 f6             	add    r14,rsi
    11ec:	4c 89 f6             	mov    rsi,r14
    11ef:	48 c1 ee 23          	shr    rsi,0x23
    11f3:	49 c1 e6 1d          	shl    r14,0x1d
    11f7:	49 09 f6             	or     r14,rsi
    11fa:	48 31 d1             	xor    rcx,rdx
    11fd:	49 01 de             	add    r14,rbx
    1200:	48 ba 61 e1 1b 35 40 	movabs rdx,0x53bccb40351be161
    1207:	cb bc 53 
    120a:	4c 89 c6             	mov    rsi,r8
    120d:	4c 31 f6             	xor    rsi,r14
    1210:	48 01 d6             	add    rsi,rdx
    1213:	48 89 f2             	mov    rdx,rsi
    1216:	48 c1 ea 2f          	shr    rdx,0x2f
    121a:	48 c1 e6 11          	shl    rsi,0x11
    121e:	48 09 d6             	or     rsi,rdx
    1221:	48 ba 90 45 d9 ad a4 	movabs rdx,0xf432e8a4add94590
    1228:	e8 32 f4 
    122b:	4c 89 f3             	mov    rbx,r14
    122e:	48 01 cb             	add    rbx,rcx
    1231:	48 31 d3             	xor    rbx,rdx
    1234:	48 89 da             	mov    rdx,rbx
    1237:	48 c1 ea 21          	shr    rdx,0x21
    123b:	48 c1 e3 1f          	shl    rbx,0x1f
    123f:	48 09 d3             	or     rbx,rdx
    1242:	4c 31 c3             	xor    rbx,r8
    1245:	48 01 fe             	add    rsi,rdi
    1248:	48 ba ee 0d 54 9f 6d 	movabs rdx,0x351f236d9f540dee
    124f:	23 1f 35 
    1252:	48 89 f7             	mov    rdi,rsi
    1255:	48 01 df             	add    rdi,rbx
    1258:	48 31 d7             	xor    rdi,rdx
    125b:	48 89 fa             	mov    rdx,rdi
    125e:	48 c1 ea 35          	shr    rdx,0x35
    1262:	48 c1 e7 0b          	shl    rdi,0xb
    1266:	48 09 d7             	or     rdi,rdx
    1269:	48 ba bf a9 96 26 09 	movabs rdx,0x94a906092696a9bf
    1270:	06 a9 94 
    1273:	49 89 f7             	mov    r15,rsi
    1276:	49 31 cf             	xor    r15,rcx
    1279:	49 01 d7             	add    r15,rdx
    127c:	4c 89 fa             	mov    rdx,r15
    127f:	48 c1 ea 15          	shr    rdx,0x15
    1283:	49 c1 e7 2b          	shl    r15,0x2b
    1287:	49 09 d7             	or     r15,rdx
    128a:	48 31 cf             	xor    rdi,rcx
    128d:	4d 01 f7             	add    r15,r14
    1290:	48 b9 1d 72 11 18 d2 	movabs rcx,0xd59540d21811721d
    1297:	40 95 d5 
    129a:	48 89 da             	mov    rdx,rbx
    129d:	4c 31 fa             	xor    rdx,r15
    12a0:	48 01 ca             	add    rdx,rcx
    12a3:	48 89 d1             	mov    rcx,rdx
    12a6:	48 c1 e9 2d          	shr    rcx,0x2d
    12aa:	48 c1 e2 13          	shl    rdx,0x13
    12ae:	48 09 ca             	or     rdx,rcx
    12b1:	49 b8 4c d6 ce 90 36 	movabs r8,0x760b5e3690ced64c
    12b8:	5e 0b 76 
    12bb:	4c 89 f9             	mov    rcx,r15
    12be:	48 01 f9             	add    rcx,rdi
    12c1:	4c 31 c1             	xor    rcx,r8
    12c4:	49 89 c8             	mov    r8,rcx
    12c7:	49 c1 e8 1b          	shr    r8,0x1b
    12cb:	48 c1 e1 25          	shl    rcx,0x25
    12cf:	4c 09 c1             	or     rcx,r8
    12d2:	48 31 d9             	xor    rcx,rbx
    12d5:	48 01 f2             	add    rdx,rsi
    12d8:	48 be aa 9e 49 82 ff 	movabs rsi,0xb6f798ff82499eaa
    12df:	98 f7 b6 
    12e2:	48 89 d3             	mov    rbx,rdx
    12e5:	48 01 cb             	add    rbx,rcx
    12e8:	48 31 f3             	xor    rbx,rsi
    12eb:	48 89 de             	mov    rsi,rbx
    12ee:	48 c1 ee 39          	shr    rsi,0x39
    12f2:	48 c1 e3 07          	shl    rbx,0x7
    12f6:	48 09 f3             	or     rbx,rsi
    12f9:	48 be 7b 3a 8c 09 9b 	movabs rsi,0x16817b9b098c3a7b
    1300:	7b 81 16 
    1303:	49 89 d6             	mov    r14,rdx
    1306:	49 31 fe             	xor    r14,rdi
    1309:	49 01 f6             	add    r14,rsi
    130c:	4c 89 f6             	mov    rsi,r14
    130f:	48 c1 ee 11          	shr    rsi,0x11
    1313:	49 c1 e6 2f          	shl    r14,0x2f
    1317:	49 09 f6             	or     r14,rsi
    131a:	48 31 fb             	xor    rbx,rdi
    131d:	4d 01 fe             	add    r14,r15
    1320:	48 bf d9 02 07 fb 63 	movabs rdi,0x576db663fb0702d9
    1327:	b6 6d 57 
    132a:	48 89 ce             	mov    rsi,rcx
    132d:	4c 31 f6             	xor    rsi,r14
    1330:	48 01 fe             	add    rsi,rdi
    1333:	48 89 f7             	mov    rdi,rsi
    1336:	48 c1 ef 29          	shr    rdi,0x29
    133a:	48 c1 e6 17          	shl    rsi,0x17
    133e:	48 09 fe             	or     rsi,rdi
    1341:	49 b8 08 67 c4 73 c8 	movabs r8,0xf7e3d3c873c46708
    1348:	d3 e3 f7 
    134b:	4c 89 f7             	mov    rdi,r14
    134e:	48 01 df             	add    rdi,rbx
    1351:	4c 31 c7             	xor    rdi,r8
    1354:	49 89 f8             	mov    r8,rdi
    1357:	49 c1 e8 17          	shr    r8,0x17
    135b:	48 c1 e7 29          	shl    rdi,0x29
    135f:	4c 09 c7             	or     rdi,r8
    1362:	48 31 cf             	xor    rdi,rcx
    1365:	48 01 d6             	add    rsi,rdx
    1368:	48 b9 66 2f 3f 65 91 	movabs rcx,0x38d00e91653f2f66
    136f:	0e d0 38 
    1372:	48 89 f2             	mov    rdx,rsi
    1375:	48 01 fa             	add    rdx,rdi
    1378:	48 31 ca             	xor    rdx,rcx
    137b:	48 89 d1             	mov    rcx,rdx
    137e:	48 c1 e9 3b          	shr    rcx,0x3b
    1382:	48 c1 e2 05          	shl    rdx,0x5
    1386:	48 09 ca             	or     rdx,rcx
    1389:	49 b8 37 cb 81 ec 2c 	movabs r8,0x9859f12cec81cb37
    1390:	f1 59 98 
    1393:	48 89 f1             	mov    rcx,rsi
    1396:	48 31 d9             	xor    rcx,rbx
    1399:	4c 01 c1             	add    rcx,r8
    139c:	49 89 c8             	mov    r8,rcx
    139f:	49 c1 e8 0b          	shr    r8,0xb
    13a3:	48 c1 e1 35          	shl    rcx,0x35
    13a7:	4c 09 c1             	or     rcx,r8
    13aa:	48 31 da             	xor    rdx,rbx
    13ad:	4c 01 f1             	add    rcx,r14
    13b0:	49 b8 77 62 2d e2 49 	movabs r8,0x85ae2d49e22d6277
    13b7:	2d ae 85 
    13ba:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
    13be:	4c 89 eb             	mov    rbx,r13
    13c1:	4c 31 c3             	xor    rbx,r8
    13c4:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
    13c8:	48 b8 d1 0c 40 62 4b 	movabs rax,0x200fef4b62400cd1
    13cf:	ef 0f 20 
    13d2:	49 01 c0             	add    r8,rax
    13d5:	49 be 72 99 1d c0 c4 	movabs r14,0xdb90e9c4c01d9972
    13dc:	e9 90 db 
    13df:	4c 8b 7d e8          	mov    r15,QWORD PTR [rbp-0x18]
    13e3:	4d 31 f7             	xor    r15,r14
    13e6:	4c 01 fe             	add    rsi,r15
    13e9:	4c 31 c7             	xor    rdi,r8
    13ec:	48 01 d9             	add    rcx,rbx
    13ef:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
    13f3:	49 89 c0             	mov    r8,rax
    13f6:	48 bb 2f d5 ba 53 14 	movabs rbx,0x60fc2a1453bad52f
    13fd:	2a fc 60 
    1400:	49 01 d8             	add    r8,rbx
    1403:	4c 31 c2             	xor    rdx,r8
    1406:	49 b8 c4 f7 b9 56 5a 	movabs r8,0x79bc495a56b9f7c4
    140d:	49 bc 79 
    1410:	48 89 cb             	mov    rbx,rcx
    1413:	48 01 d3             	add    rbx,rdx
    1416:	4c 31 c3             	xor    rbx,r8
    1419:	49 89 d8             	mov    r8,rbx
    141c:	49 c1 e8 2f          	shr    r8,0x2f
    1420:	48 c1 e3 11          	shl    rbx,0x11
    1424:	4c 09 c3             	or     rbx,r8
    1427:	49 b8 95 93 fc dd f5 	movabs r8,0xd9462bf5ddfc9395
    142e:	2b 46 d9 
    1431:	48 31 fb             	xor    rbx,rdi
    1434:	48 31 cf             	xor    rdi,rcx
    1437:	4c 01 c7             	add    rdi,r8
    143a:	49 89 f8             	mov    r8,rdi
    143d:	49 c1 e8 33          	shr    r8,0x33
    1441:	48 c1 e7 0d          	shl    rdi,0xd
    1445:	4c 09 c7             	or     rdi,r8
    1448:	48 01 f7             	add    rdi,rsi
    144b:	48 be 22 c0 34 48 23 	movabs rsi,0xbaa884234834c022
    1452:	84 a8 ba 
    1455:	49 89 df             	mov    r15,rbx
    1458:	49 01 ff             	add    r15,rdi
    145b:	49 31 f7             	xor    r15,rsi
    145e:	4c 89 fe             	mov    rsi,r15
    1461:	48 c1 ee 15          	shr    rsi,0x15
    1465:	49 c1 e7 2b          	shl    r15,0x2b
    1469:	49 09 f7             	or     r15,rsi
    146c:	48 be f3 5b 77 cf be 	movabs rsi,0x1a3266becf775bf3
    1473:	66 32 1a 
    1476:	49 89 fe             	mov    r14,rdi
    1479:	49 31 d6             	xor    r14,rdx
    147c:	49 01 f6             	add    r14,rsi
    147f:	4c 89 f6             	mov    rsi,r14
    1482:	48 c1 ee 23          	shr    rsi,0x23
    1486:	49 c1 e6 1d          	shl    r14,0x1d
    148a:	49 09 f6             	or     r14,rsi
    148d:	49 31 d7             	xor    r15,rdx
    1490:	49 01 ce             	add    r14,rcx
    1493:	48 ba 51 24 f2 c0 87 	movabs rdx,0x5b1ea187c0f22451
    149a:	a1 1e 5b 
    149d:	48 89 de             	mov    rsi,rbx
    14a0:	4c 31 f6             	xor    rsi,r14
    14a3:	48 01 d6             	add    rsi,rdx
    14a6:	48 89 f2             	mov    rdx,rsi
    14a9:	48 c1 ea 35          	shr    rdx,0x35
    14ad:	48 c1 e6 0b          	shl    rsi,0xb
    14b1:	48 09 d6             	or     rsi,rdx
    14b4:	48 ba 80 88 af 39 ec 	movabs rdx,0xfb94beec39af8880
    14bb:	be 94 fb 
    14be:	4c 89 f1             	mov    rcx,r14
    14c1:	4c 01 f9             	add    rcx,r15
    14c4:	48 31 d1             	xor    rcx,rdx
    14c7:	48 89 ca             	mov    rdx,rcx
    14ca:	48 c1 ea 2d          	shr    rdx,0x2d
    14ce:	48 c1 e1 13          	shl    rcx,0x13
    14d2:	48 09 d1             	or     rcx,rdx
    14d5:	48 31 d9             	xor    rcx,rbx
    14d8:	48 01 fe             	add    rsi,rdi
    14db:	48 bf de 50 2a 2b b5 	movabs rdi,0x3c80f9b52b2a50de
    14e2:	f9 80 3c 
    14e5:	48 89 f2             	mov    rdx,rsi
    14e8:	48 01 ca             	add    rdx,rcx
    14eb:	48 31 fa             	xor    rdx,rdi
    14ee:	48 89 d7             	mov    rdi,rdx
    14f1:	48 c1 ef 11          	shr    rdi,0x11
    14f5:	48 c1 e2 2f          	shl    rdx,0x2f
    14f9:	48 09 fa             	or     rdx,rdi
    14fc:	48 bf af ec 6c b2 50 	movabs rdi,0x9c0adc50b26cecaf
    1503:	dc 0a 9c 
    1506:	48 89 f3             	mov    rbx,rsi
    1509:	4c 31 fb             	xor    rbx,r15
    150c:	48 01 fb             	add    rbx,rdi
    150f:	48 89 df             	mov    rdi,rbx
    1512:	48 c1 ef 21          	shr    rdi,0x21
    1516:	48 c1 e3 1f          	shl    rbx,0x1f
    151a:	48 09 fb             	or     rbx,rdi
    151d:	4c 31 fa             	xor    rdx,r15
    1520:	4c 01 f3             	add    rbx,r14
    1523:	49 b8 0d b5 e7 a3 19 	movabs r8,0xdcf71719a3e7b50d
    152a:	17 f7 dc 
    152d:	48 89 cf             	mov    rdi,rcx
    1530:	48 31 df             	xor    rdi,rbx
    1533:	4c 01 c7             	add    rdi,r8
    1536:	49 89 f8             	mov    r8,rdi
    1539:	49 c1 e8 39          	shr    r8,0x39
    153d:	48 c1 e7 07          	shl    rdi,0x7
    1541:	4c 09 c7             	or     rdi,r8
    1544:	49 be 3c 19 a5 1c 7e 	movabs r14,0x7d6d347e1ca5193c
    154b:	34 6d 7d 
    154e:	49 89 d8             	mov    r8,rbx
    1551:	49 01 d0             	add    r8,rdx
    1554:	4d 31 f0             	xor    r8,r14
    1557:	4d 89 c6             	mov    r14,r8
    155a:	49 c1 ee 29          	shr    r14,0x29
    155e:	49 c1 e0 17          	shl    r8,0x17
    1562:	4d 09 f0             	or     r8,r14
    1565:	49 31 c8             	xor    r8,rcx
    1568:	48 01 f7             	add    rdi,rsi
    156b:	48 be 9a e1 1f 0e 47 	movabs rsi,0xbe596f470e1fe19a
    1572:	6f 59 be 
    1575:	48 89 f9             	mov    rcx,rdi
    1578:	4c 01 c1             	add    rcx,r8
    157b:	48 31 f1             	xor    rcx,rsi
    157e:	48 89 ce             	mov    rsi,rcx
    1581:	48 c1 ee 0b          	shr    rsi,0xb
    1585:	48 c1 e1 35          	shl    rcx,0x35
    1589:	48 09 f1             	or     rcx,rsi
    158c:	48 be 6b 7d 62 95 e2 	movabs rsi,0x1de351e295627d6b
    1593:	51 e3 1d 
    1596:	49 89 fe             	mov    r14,rdi
    1599:	49 31 d6             	xor    r14,rdx
    159c:	49 01 f6             	add    r14,rsi
    159f:	4c 89 f6             	mov    rsi,r14
    15a2:	48 c1 ee 1b          	shr    rsi,0x1b
    15a6:	49 c1 e6 25          	shl    r14,0x25
    15aa:	49 09 f6             	or     r14,rsi
    15ad:	48 31 d1             	xor    rcx,rdx
    15b0:	49 01 de             	add    r14,rbx
    15b3:	48 ba c9 45 dd 86 ab 	movabs rdx,0x5ecf8cab86dd45c9
    15ba:	8c cf 5e 
    15bd:	4c 89 c6             	mov    rsi,r8
    15c0:	4c 31 f6             	xor    rsi,r14
    15c3:	48 01 d6             	add    rsi,rdx
    15c6:	48 89 f2             	mov    rdx,rsi
    15c9:	48 c1 ea 3b          	shr    rdx,0x3b
    15cd:	48 c1 e6 05          	shl    rsi,0x5
    15d1:	48 09 d6             	or     rsi,rdx
    15d4:	48 ba f8 a9 9a ff 0f 	movabs rdx,0xff45aa0fff9aa9f8
    15db:	aa 45 ff 
    15de:	4d 89 f7             	mov    r15,r14
    15e1:	49 01 cf             	add    r15,rcx
    15e4:	49 31 d7             	xor    r15,rdx
    15e7:	4c 89 fa             	mov    rdx,r15
    15ea:	48 c1 ea 25          	shr    rdx,0x25
    15ee:	49 c1 e7 1b          	shl    r15,0x1b
    15f2:	49 09 d7             	or     r15,rdx
    15f5:	4d 31 c7             	xor    r15,r8
    15f8:	48 01 fe             	add    rsi,rdi
    15fb:	48 bf 56 72 15 f1 d8 	movabs rdi,0x4031e4d8f1157256
    1602:	e4 31 40 
    1605:	48 89 f2             	mov    rdx,rsi
    1608:	4c 01 fa             	add    rdx,r15
    160b:	48 31 fa             	xor    rdx,rdi
    160e:	48 89 d7             	mov    rdi,rdx
    1611:	48 c1 ef 05          	shr    rdi,0x5
    1615:	48 c1 e2 3b          	shl    rdx,0x3b
    1619:	48 09 fa             	or     rdx,rdi
    161c:	48 bf 27 0e 58 78 74 	movabs rdi,0x9fbbc77478580e27
    1623:	c7 bb 9f 
    1626:	48 89 f3             	mov    rbx,rsi
    1629:	48 31 cb             	xor    rbx,rcx
    162c:	48 01 fb             	add    rbx,rdi
    162f:	48 89 df             	mov    rdi,rbx
    1632:	48 c1 ef 17          	shr    rdi,0x17
    1636:	48 c1 e3 29          	shl    rbx,0x29
    163a:	48 09 fb             	or     rbx,rdi
    163d:	48 31 ca             	xor    rdx,rcx
    1640:	4c 01 f3             	add    rbx,r14
    1643:	48 b9 85 d6 d2 69 3d 	movabs rcx,0xe0a8023d69d2d685
    164a:	02 a8 e0 
    164d:	4c 89 ff             	mov    rdi,r15
    1650:	48 31 df             	xor    rdi,rbx
    1653:	48 01 cf             	add    rdi,rcx
    1656:	48 89 f9             	mov    rcx,rdi
    1659:	48 c1 e9 3d          	shr    rcx,0x3d
    165d:	48 c1 e7 03          	shl    rdi,0x3
    1661:	48 09 cf             	or     rdi,rcx
    1664:	48 b9 b4 3a 90 e2 a1 	movabs rcx,0x811e1fa1e2903ab4
    166b:	1f 1e 81 
    166e:	49 89 d8             	mov    r8,rbx
    1671:	49 01 d0             	add    r8,rdx
    1674:	49 31 c8             	xor    r8,rcx
    1677:	4c 89 c1             	mov    rcx,r8
    167a:	48 c1 e9 33          	shr    rcx,0x33
    167e:	49 c1 e0 0d          	shl    r8,0xd
    1682:	49 09 c8             	or     r8,rcx
    1685:	4d 31 f8             	xor    r8,r15
    1688:	48 01 f7             	add    rdi,rsi
    168b:	48 be 12 03 0b d4 6a 	movabs rsi,0xc20a5a6ad40b0312
    1692:	5a 0a c2 
    1695:	48 89 f9             	mov    rcx,rdi
    1698:	4c 01 c1             	add    rcx,r8
    169b:	48 31 f1             	xor    rcx,rsi
    169e:	48 89 ce             	mov    rsi,rcx
    16a1:	48 c1 ee 03          	shr    rsi,0x3
    16a5:	48 c1 e1 3d          	shl    rcx,0x3d
    16a9:	48 09 f1             	or     rcx,rsi
    16ac:	48 be e3 9e 4d 5b 06 	movabs rsi,0x21943d065b4d9ee3
    16b3:	3d 94 21 
    16b6:	49 89 fe             	mov    r14,rdi
    16b9:	49 31 d6             	xor    r14,rdx
    16bc:	49 01 f6             	add    r14,rsi
    16bf:	4c 89 f6             	mov    rsi,r14
    16c2:	48 c1 ee 23          	shr    rsi,0x23
    16c6:	49 c1 e6 1d          	shl    r14,0x1d
    16ca:	49 09 f6             	or     r14,rsi
    16cd:	48 31 d1             	xor    rcx,rdx
    16d0:	49 01 de             	add    r14,rbx
    16d3:	48 ba 41 67 c8 4c cf 	movabs rdx,0x628077cf4cc86741
    16da:	77 80 62 
    16dd:	4c 89 c6             	mov    rsi,r8
    16e0:	4c 31 f6             	xor    rsi,r14
    16e3:	48 01 d6             	add    rsi,rdx
    16e6:	48 89 f2             	mov    rdx,rsi
    16e9:	48 c1 ea 2f          	shr    rdx,0x2f
    16ed:	48 c1 e6 11          	shl    rsi,0x11
    16f1:	48 09 d6             	or     rsi,rdx
    16f4:	48 ba 70 cb 85 c5 33 	movabs rdx,0x2f69533c585cb70
    16fb:	95 f6 02 
    16fe:	4c 89 f3             	mov    rbx,r14
    1701:	48 01 cb             	add    rbx,rcx
    1704:	48 31 d3             	xor    rbx,rdx
    1707:	48 89 da             	mov    rdx,rbx
    170a:	48 c1 ea 21          	shr    rdx,0x21
    170e:	48 c1 e3 1f          	shl    rbx,0x1f
    1712:	48 09 d3             	or     rbx,rdx
    1715:	4c 31 c3             	xor    rbx,r8
    1718:	48 01 fe             	add    rsi,rdi
    171b:	48 ba ce 93 00 b7 fc 	movabs rdx,0x43e2cffcb70093ce
    1722:	cf e2 43 
    1725:	48 89 f7             	mov    rdi,rsi
    1728:	48 01 df             	add    rdi,rbx
    172b:	48 31 d7             	xor    rdi,rdx
    172e:	48 89 fa             	mov    rdx,rdi
    1731:	48 c1 ea 35          	shr    rdx,0x35
    1735:	48 c1 e7 0b          	shl    rdi,0xb
    1739:	48 09 d7             	or     rdi,rdx
    173c:	48 ba 9f 2f 43 3e 98 	movabs rdx,0xa36cb2983e432f9f
    1743:	b2 6c a3 
    1746:	49 89 f7             	mov    r15,rsi
    1749:	49 31 cf             	xor    r15,rcx
    174c:	49 01 d7             	add    r15,rdx
    174f:	4c 89 fa             	mov    rdx,r15
    1752:	48 c1 ea 15          	shr    rdx,0x15
    1756:	49 c1 e7 2b          	shl    r15,0x2b
    175a:	49 09 d7             	or     r15,rdx
    175d:	48 31 cf             	xor    rdi,rcx
    1760:	4d 01 f7             	add    r15,r14
    1763:	48 b9 fd f7 bd 2f 61 	movabs rcx,0xe458ed612fbdf7fd
    176a:	ed 58 e4 
    176d:	48 89 da             	mov    rdx,rbx
    1770:	4c 31 fa             	xor    rdx,r15
    1773:	48 01 ca             	add    rdx,rcx
    1776:	48 89 d1             	mov    rcx,rdx
    1779:	48 c1 e9 2d          	shr    rcx,0x2d
    177d:	48 c1 e2 13          	shl    rdx,0x13
    1781:	48 09 ca             	or     rdx,rcx
    1784:	49 b8 2c 5c 7b a8 c5 	movabs r8,0x84cf0ac5a87b5c2c
    178b:	0a cf 84 
    178e:	4c 89 f9             	mov    rcx,r15
    1791:	48 01 f9             	add    rcx,rdi
    1794:	4c 31 c1             	xor    rcx,r8
    1797:	49 89 c8             	mov    r8,rcx
    179a:	49 c1 e8 1b          	shr    r8,0x1b
    179e:	48 c1 e1 25          	shl    rcx,0x25
    17a2:	4c 09 c1             	or     rcx,r8
    17a5:	48 31 d9             	xor    rcx,rbx
    17a8:	48 01 f2             	add    rdx,rsi
    17ab:	48 be 8a 24 f6 99 8e 	movabs rsi,0xc5bb458e99f6248a
    17b2:	45 bb c5 
    17b5:	48 89 d3             	mov    rbx,rdx
    17b8:	48 01 cb             	add    rbx,rcx
    17bb:	48 31 f3             	xor    rbx,rsi
    17be:	48 89 de             	mov    rsi,rbx
    17c1:	48 c1 ee 39          	shr    rsi,0x39
    17c5:	48 c1 e3 07          	shl    rbx,0x7
    17c9:	48 09 f3             	or     rbx,rsi
    17cc:	48 be 5b c0 38 21 2a 	movabs rsi,0x2545282a2138c05b
    17d3:	28 45 25 
    17d6:	49 89 d6             	mov    r14,rdx
    17d9:	49 31 fe             	xor    r14,rdi
    17dc:	49 01 f6             	add    r14,rsi
    17df:	4c 89 f6             	mov    rsi,r14
    17e2:	48 c1 ee 11          	shr    rsi,0x11
    17e6:	49 c1 e6 2f          	shl    r14,0x2f
    17ea:	49 09 f6             	or     r14,rsi
    17ed:	48 31 fb             	xor    rbx,rdi
    17f0:	4d 01 fe             	add    r14,r15
    17f3:	48 bf b9 88 b3 12 f3 	movabs rdi,0x663162f312b388b9
    17fa:	62 31 66 
    17fd:	48 89 ce             	mov    rsi,rcx
    1800:	4c 31 f6             	xor    rsi,r14
    1803:	48 01 fe             	add    rsi,rdi
    1806:	48 89 f7             	mov    rdi,rsi
    1809:	48 c1 ef 29          	shr    rdi,0x29
    180d:	48 c1 e6 17          	shl    rsi,0x17
    1811:	48 09 fe             	or     rsi,rdi
    1814:	49 b8 e8 ec 70 8b 57 	movabs r8,0x6a780578b70ece8
    181b:	80 a7 06 
    181e:	4c 89 f7             	mov    rdi,r14
    1821:	48 01 df             	add    rdi,rbx
    1824:	4c 31 c7             	xor    rdi,r8
    1827:	49 89 f8             	mov    r8,rdi
    182a:	49 c1 e8 17          	shr    r8,0x17
    182e:	48 c1 e7 29          	shl    rdi,0x29
    1832:	4c 09 c7             	or     rdi,r8
    1835:	48 31 cf             	xor    rdi,rcx
    1838:	48 01 d6             	add    rsi,rdx
    183b:	48 b9 46 b5 eb 7c 20 	movabs rcx,0x4793bb207cebb546
    1842:	bb 93 47 
    1845:	48 89 f2             	mov    rdx,rsi
    1848:	48 01 fa             	add    rdx,rdi
    184b:	48 31 ca             	xor    rdx,rcx
    184e:	48 89 d1             	mov    rcx,rdx
    1851:	48 c1 e9 3b          	shr    rcx,0x3b
    1855:	48 c1 e2 05          	shl    rdx,0x5
    1859:	48 09 ca             	or     rdx,rcx
    185c:	49 b8 17 51 2e 04 bc 	movabs r8,0xa71d9dbc042e5117
    1863:	9d 1d a7 
    1866:	48 89 f1             	mov    rcx,rsi
    1869:	48 31 d9             	xor    rcx,rbx
    186c:	4c 01 c1             	add    rcx,r8
    186f:	49 89 c8             	mov    r8,rcx
    1872:	49 c1 e8 0b          	shr    r8,0xb
    1876:	48 c1 e1 35          	shl    rcx,0x35
    187a:	4c 09 c1             	or     rcx,r8
    187d:	48 31 da             	xor    rdx,rbx
    1880:	4c 01 f1             	add    rcx,r14
    1883:	49 b8 58 c6 6a 6b f2 	movabs r8,0x25d40bf26b6ac658
    188a:	0b d4 25 
    188d:	4c 89 eb             	mov    rbx,r13
    1890:	4c 31 c3             	xor    rbx,r8
    1893:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
    1897:	49 bd 00 71 fd da af 	movabs r13,0xc0860cafdafd7100
    189e:	0c 86 c0 
    18a1:	4d 01 e8             	add    r8,r13
    18a4:	49 be 01 3d df 4b 69 	movabs r14,0x8406d7694bdf3d01
    18ab:	d7 06 84 
    18ae:	4c 8b 6d e8          	mov    r13,QWORD PTR [rbp-0x18]
    18b2:	4d 89 ef             	mov    r15,r13
    18b5:	4d 31 f7             	xor    r15,r14
    18b8:	4c 01 fe             	add    rsi,r15
    18bb:	4c 31 c7             	xor    rdi,r8
    18be:	48 01 d9             	add    rcx,rbx
    18c1:	49 89 c0             	mov    r8,rax
    18c4:	48 b8 5e 39 78 cc 78 	movabs rax,0x1724778cc78395e
    18cb:	47 72 01 
    18ce:	49 01 c0             	add    r8,rax
    18d1:	4c 31 c2             	xor    rdx,r8
    18d4:	49 b8 a4 7d 66 6e e9 	movabs r8,0x887ff5e96e667da4
    18db:	f5 7f 88 
    18de:	48 89 cb             	mov    rbx,rcx
    18e1:	48 01 d3             	add    rbx,rdx
    18e4:	4c 31 c3             	xor    rbx,r8
    18e7:	49 89 d8             	mov    r8,rbx
    18ea:	49 c1 e8 2f          	shr    r8,0x2f
    18ee:	48 c1 e3 11          	shl    rbx,0x11
    18f2:	4c 09 c3             	or     rbx,r8
    18f5:	49 b8 75 19 a9 f5 84 	movabs r8,0xe809d884f5a91975
    18fc:	d8 09 e8 
    18ff:	48 31 fb             	xor    rbx,rdi
    1902:	48 31 cf             	xor    rdi,rcx
    1905:	4c 01 c7             	add    rdi,r8
    1908:	49 89 f8             	mov    r8,rdi
    190b:	49 c1 e8 33          	shr    r8,0x33
    190f:	48 c1 e7 0d          	shl    rdi,0xd
    1913:	4c 09 c7             	or     rdi,r8
    1916:	48 01 f7             	add    rdi,rsi
    1919:	48 be 02 46 e1 5f b2 	movabs rsi,0xc96c30b25fe14602
    1920:	30 6c c9 
    1923:	49 89 df             	mov    r15,rbx
    1926:	49 01 ff             	add    r15,rdi
    1929:	49 31 f7             	xor    r15,rsi
    192c:	4c 89 fe             	mov    rsi,r15
    192f:	48 c1 ee 15          	shr    rsi,0x15
    1933:	49 c1 e7 2b          	shl    r15,0x2b
    1937:	49 09 f7             	or     r15,rsi
    193a:	48 be d3 e1 23 e7 4d 	movabs rsi,0x28f6134de723e1d3
    1941:	13 f6 28 
    1944:	49 89 fe             	mov    r14,rdi
    1947:	49 31 d6             	xor    r14,rdx
    194a:	49 01 f6             	add    r14,rsi
    194d:	4c 89 f6             	mov    rsi,r14
    1950:	48 c1 ee 23          	shr    rsi,0x23
    1954:	49 c1 e6 1d          	shl    r14,0x1d
    1958:	49 09 f6             	or     r14,rsi
    195b:	49 31 d7             	xor    r15,rdx
    195e:	49 01 ce             	add    r14,rcx
    1961:	48 ba 31 aa 9e d8 16 	movabs rdx,0x69e24e16d89eaa31
    1968:	4e e2 69 
    196b:	48 89 de             	mov    rsi,rbx
    196e:	4c 31 f6             	xor    rsi,r14
    1971:	48 01 d6             	add    rsi,rdx
    1974:	48 89 f2             	mov    rdx,rsi
    1977:	48 c1 ea 35          	shr    rdx,0x35
    197b:	48 c1 e6 0b          	shl    rsi,0xb
    197f:	48 09 d6             	or     rsi,rdx
    1982:	48 ba 60 0e 5c 51 7b 	movabs rdx,0xa586b7b515c0e60
    1989:	6b 58 0a 
    198c:	4c 89 f1             	mov    rcx,r14
    198f:	4c 01 f9             	add    rcx,r15
    1992:	48 31 d1             	xor    rcx,rdx
    1995:	48 89 ca             	mov    rdx,rcx
    1998:	48 c1 ea 2d          	shr    rdx,0x2d
    199c:	48 c1 e1 13          	shl    rcx,0x13
    19a0:	48 09 d1             	or     rcx,rdx
    19a3:	48 31 d9             	xor    rcx,rbx
    19a6:	48 01 fe             	add    rsi,rdi
    19a9:	48 bf be d6 d6 42 44 	movabs rdi,0x4b44a64442d6d6be
    19b0:	a6 44 4b 
    19b3:	48 89 f2             	mov    rdx,rsi
    19b6:	48 01 ca             	add    rdx,rcx
    19b9:	48 31 fa             	xor    rdx,rdi
    19bc:	48 89 d7             	mov    rdi,rdx
    19bf:	48 c1 ef 11          	shr    rdi,0x11
    19c3:	48 c1 e2 2f          	shl    rdx,0x2f
    19c7:	48 09 fa             	or     rdx,rdi
    19ca:	48 bf 8f 72 19 ca df 	movabs rdi,0xaace88dfca19728f
    19d1:	88 ce aa 
    19d4:	48 89 f3             	mov    rbx,rsi
    19d7:	4c 31 fb             	xor    rbx,r15
    19da:	48 01 fb             	add    rbx,rdi
    19dd:	48 89 df             	mov    rdi,rbx
    19e0:	48 c1 ef 21          	shr    rdi,0x21
    19e4:	48 c1 e3 1f          	shl    rbx,0x1f
    19e8:	48 09 fb             	or     rbx,rdi
    19eb:	4c 31 fa             	xor    rdx,r15
    19ee:	4c 01 f3             	add    rbx,r14
    19f1:	49 b8 ed 3a 94 bb a8 	movabs r8,0xebbac3a8bb943aed
    19f8:	c3 ba eb 
    19fb:	48 89 cf             	mov    rdi,rcx
    19fe:	48 31 df             	xor    rdi,rbx
    1a01:	4c 01 c7             	add    rdi,r8
    1a04:	49 89 f8             	mov    r8,rdi
    1a07:	49 c1 e8 39          	shr    r8,0x39
    1a0b:	48 c1 e7 07          	shl    rdi,0x7
    1a0f:	4c 09 c7             	or     rdi,r8
    1a12:	49 be 1c 9f 51 34 0d 	movabs r14,0x8c30e10d34519f1c
    1a19:	e1 30 8c 
    1a1c:	49 89 d8             	mov    r8,rbx
    1a1f:	49 01 d0             	add    r8,rdx
    1a22:	4d 31 f0             	xor    r8,r14
    1a25:	4d 89 c6             	mov    r14,r8
    1a28:	49 c1 ee 29          	shr    r14,0x29
    1a2c:	49 c1 e0 17          	shl    r8,0x17
    1a30:	4d 09 f0             	or     r8,r14
    1a33:	49 31 c8             	xor    r8,rcx
    1a36:	48 01 f7             	add    rdi,rsi
    1a39:	48 be 7a 67 cc 25 d6 	movabs rsi,0xcd1d1bd625cc677a
    1a40:	1b 1d cd 
    1a43:	48 89 f9             	mov    rcx,rdi
    1a46:	4c 01 c1             	add    rcx,r8
    1a49:	48 31 f1             	xor    rcx,rsi
    1a4c:	48 89 ce             	mov    rsi,rcx
    1a4f:	48 c1 ee 0b          	shr    rsi,0xb
    1a53:	48 c1 e1 35          	shl    rcx,0x35
    1a57:	48 09 f1             	or     rcx,rsi
    1a5a:	48 be 4b 03 0f ad 71 	movabs rsi,0x2ca6fe71ad0f034b
    1a61:	fe a6 2c 
    1a64:	49 89 fe             	mov    r14,rdi
    1a67:	49 31 d6             	xor    r14,rdx
    1a6a:	49 01 f6             	add    r14,rsi
    1a6d:	4c 89 f6             	mov    rsi,r14
    1a70:	48 c1 ee 1b          	shr    rsi,0x1b
    1a74:	49 c1 e6 25          	shl    r14,0x25
    1a78:	49 09 f6             	or     r14,rsi
    1a7b:	48 31 d1             	xor    rcx,rdx
    1a7e:	49 01 de             	add    r14,rbx
    1a81:	48 ba a9 cb 89 9e 3a 	movabs rdx,0x6d93393a9e89cba9
    1a88:	39 93 6d 
    1a8b:	4c 89 c6             	mov    rsi,r8
    1a8e:	4c 31 f6             	xor    rsi,r14
    1a91:	48 01 d6             	add    rsi,rdx
    1a94:	48 89 f2             	mov    rdx,rsi
    1a97:	48 c1 ea 3b          	shr    rdx,0x3b
    1a9b:	48 c1 e6 05          	shl    rsi,0x5
    1a9f:	48 09 d6             	or     rsi,rdx
    1aa2:	48 ba d8 2f 47 17 9f 	movabs rdx,0xe09569f17472fd8
    1aa9:	56 09 0e 
    1aac:	4d 89 f7             	mov    r15,r14
    1aaf:	49 01 cf             	add    r15,rcx
    1ab2:	49 31 d7             	xor    r15,rdx
    1ab5:	4c 89 fa             	mov    rdx,r15
    1ab8:	48 c1 ea 25          	shr    rdx,0x25
    1abc:	49 c1 e7 1b          	shl    r15,0x1b
    1ac0:	49 09 d7             	or     r15,rdx
    1ac3:	4d 31 c7             	xor    r15,r8
    1ac6:	48 01 fe             	add    rsi,rdi
    1ac9:	48 bf 36 f8 c1 08 68 	movabs rdi,0x4ef5916808c1f836
    1ad0:	91 f5 4e 
    1ad3:	48 89 f2             	mov    rdx,rsi
    1ad6:	4c 01 fa             	add    rdx,r15
    1ad9:	48 31 fa             	xor    rdx,rdi
    1adc:	48 89 d7             	mov    rdi,rdx
    1adf:	48 c1 ef 05          	shr    rdi,0x5
    1ae3:	48 c1 e2 3b          	shl    rdx,0x3b
    1ae7:	48 09 fa             	or     rdx,rdi
    1aea:	48 bf 07 94 04 90 03 	movabs rdi,0xae7f740390049407
    1af1:	74 7f ae 
    1af4:	48 89 f3             	mov    rbx,rsi
    1af7:	48 31 cb             	xor    rbx,rcx
    1afa:	48 01 fb             	add    rbx,rdi
    1afd:	48 89 df             	mov    rdi,rbx
    1b00:	48 c1 ef 17          	shr    rdi,0x17
    1b04:	48 c1 e3 29          	shl    rbx,0x29
    1b08:	48 09 fb             	or     rbx,rdi
    1b0b:	48 31 ca             	xor    rdx,rcx
    1b0e:	4c 01 f3             	add    rbx,r14
    1b11:	48 b9 65 5c 7f 81 cc 	movabs rcx,0xef6baecc817f5c65
    1b18:	ae 6b ef 
    1b1b:	4c 89 ff             	mov    rdi,r15
    1b1e:	48 31 df             	xor    rdi,rbx
    1b21:	48 01 cf             	add    rdi,rcx
    1b24:	48 89 f9             	mov    rcx,rdi
    1b27:	48 c1 e9 3d          	shr    rcx,0x3d
    1b2b:	48 c1 e7 03          	shl    rdi,0x3
    1b2f:	48 09 cf             	or     rdi,rcx
    1b32:	48 b9 94 c0 3c fa 30 	movabs rcx,0x8fe1cc30fa3cc094
    1b39:	cc e1 8f 
    1b3c:	49 89 d8             	mov    r8,rbx
    1b3f:	49 01 d0             	add    r8,rdx
    1b42:	49 31 c8             	xor    r8,rcx
    1b45:	4c 89 c1             	mov    rcx,r8
    1b48:	48 c1 e9 33          	shr    rcx,0x33
    1b4c:	49 c1 e0 0d          	shl    r8,0xd
    1b50:	49 09 c8             	or     r8,rcx
    1b53:	4d 31 f8             	xor    r8,r15
    1b56:	48 01 f7             	add    rdi,rsi
    1b59:	48 be f2 88 b7 eb f9 	movabs rsi,0xd0ce06f9ebb788f2
    1b60:	06 ce d0 
    1b63:	48 89 f9             	mov    rcx,rdi
    1b66:	4c 01 c1             	add    rcx,r8
    1b69:	48 31 f1             	xor    rcx,rsi
    1b6c:	48 89 ce             	mov    rsi,rcx
    1b6f:	48 c1 ee 03          	shr    rsi,0x3
    1b73:	48 c1 e1 3d          	shl    rcx,0x3d
    1b77:	48 09 f1             	or     rcx,rsi
    1b7a:	48 be c3 24 fa 72 95 	movabs rsi,0x3057e99572fa24c3
    1b81:	e9 57 30 
    1b84:	49 89 fe             	mov    r14,rdi
    1b87:	49 31 d6             	xor    r14,rdx
    1b8a:	49 01 f6             	add    r14,rsi
    1b8d:	4c 89 f6             	mov    rsi,r14
    1b90:	48 c1 ee 23          	shr    rsi,0x23
    1b94:	49 c1 e6 1d          	shl    r14,0x1d
    1b98:	49 09 f6             	or     r14,rsi
    1b9b:	48 31 d1             	xor    rcx,rdx
    1b9e:	49 01 de             	add    r14,rbx
    1ba1:	48 ba 21 ed 74 64 5e 	movabs rdx,0x7144245e6474ed21
    1ba8:	24 44 71 
    1bab:	4c 89 c6             	mov    rsi,r8
    1bae:	4c 31 f6             	xor    rsi,r14
    1bb1:	48 01 d6             	add    rsi,rdx
    1bb4:	48 89 f2             	mov    rdx,rsi
    1bb7:	48 c1 ea 2f          	shr    rdx,0x2f
    1bbb:	48 c1 e6 11          	shl    rsi,0x11
    1bbf:	48 09 d6             	or     rsi,rdx
    1bc2:	48 ba 50 51 32 dd c2 	movabs rdx,0x11ba41c2dd325150
    1bc9:	41 ba 11 
    1bcc:	4c 89 f3             	mov    rbx,r14
    1bcf:	48 01 cb             	add    rbx,rcx
    1bd2:	48 31 d3             	xor    rbx,rdx
    1bd5:	48 89 da             	mov    rdx,rbx
    1bd8:	48 c1 ea 21          	shr    rdx,0x21
    1bdc:	48 c1 e3 1f          	shl    rbx,0x1f
    1be0:	48 09 d3             	or     rbx,rdx
    1be3:	4c 31 c3             	xor    rbx,r8
    1be6:	48 01 fe             	add    rsi,rdi
    1be9:	48 ba ae 19 ad ce 8b 	movabs rdx,0x52a67c8bcead19ae
    1bf0:	7c a6 52 
    1bf3:	48 89 f7             	mov    rdi,rsi
    1bf6:	48 01 df             	add    rdi,rbx
    1bf9:	48 31 d7             	xor    rdi,rdx
    1bfc:	48 89 fa             	mov    rdx,rdi
    1bff:	48 c1 ea 35          	shr    rdx,0x35
    1c03:	48 c1 e7 0b          	shl    rdi,0xb
    1c07:	48 09 d7             	or     rdi,rdx
    1c0a:	48 ba 7f b5 ef 55 27 	movabs rdx,0xb2305f2755efb57f
    1c11:	5f 30 b2 
    1c14:	49 89 f7             	mov    r15,rsi
    1c17:	49 31 cf             	xor    r15,rcx
    1c1a:	49 01 d7             	add    r15,rdx
    1c1d:	4c 89 fa             	mov    rdx,r15
    1c20:	48 c1 ea 15          	shr    rdx,0x15
    1c24:	49 c1 e7 2b          	shl    r15,0x2b
    1c28:	49 09 d7             	or     r15,rdx
    1c2b:	48 31 cf             	xor    rdi,rcx
    1c2e:	4d 01 f7             	add    r15,r14
    1c31:	48 b9 dd 7d 6a 47 f0 	movabs rcx,0xf31c99f0476a7ddd
    1c38:	99 1c f3 
    1c3b:	48 89 da             	mov    rdx,rbx
    1c3e:	4c 31 fa             	xor    rdx,r15
    1c41:	48 01 ca             	add    rdx,rcx
    1c44:	48 89 d1             	mov    rcx,rdx
    1c47:	48 c1 e9 2d          	shr    rcx,0x2d
    1c4b:	48 c1 e2 13          	shl    rdx,0x13
    1c4f:	48 09 ca             	or     rdx,rcx
    1c52:	49 b8 0c e2 27 c0 54 	movabs r8,0x9392b754c027e20c
    1c59:	b7 92 93 
    1c5c:	4c 89 f9             	mov    rcx,r15
    1c5f:	48 01 f9             	add    rcx,rdi
    1c62:	4c 31 c1             	xor    rcx,r8
    1c65:	49 89 c8             	mov    r8,rcx
    1c68:	49 c1 e8 1b          	shr    r8,0x1b
    1c6c:	48 c1 e1 25          	shl    rcx,0x25
    1c70:	4c 09 c1             	or     rcx,r8
    1c73:	48 31 d9             	xor    rcx,rbx
    1c76:	48 01 f2             	add    rdx,rsi
    1c79:	48 be 6a aa a2 b1 1d 	movabs rsi,0xd47ef21db1a2aa6a
    1c80:	f2 7e d4 
    1c83:	48 89 d3             	mov    rbx,rdx
    1c86:	48 01 cb             	add    rbx,rcx
    1c89:	48 31 f3             	xor    rbx,rsi
    1c8c:	48 89 de             	mov    rsi,rbx
    1c8f:	48 c1 ee 39          	shr    rsi,0x39
    1c93:	48 c1 e3 07          	shl    rbx,0x7
    1c97:	48 09 f3             	or     rbx,rsi
    1c9a:	48 be 3b 46 e5 38 b9 	movabs rsi,0x3408d4b938e5463b
    1ca1:	d4 08 34 
    1ca4:	49 89 d6             	mov    r14,rdx
    1ca7:	49 31 fe             	xor    r14,rdi
    1caa:	49 01 f6             	add    r14,rsi
    1cad:	4c 89 f6             	mov    rsi,r14
    1cb0:	48 c1 ee 11          	shr    rsi,0x11
    1cb4:	49 c1 e6 2f          	shl    r14,0x2f
    1cb8:	49 09 f6             	or     r14,rsi
    1cbb:	48 31 fb             	xor    rbx,rdi
    1cbe:	4d 01 fe             	add    r14,r15
    1cc1:	48 bf 99 0e 60 2a 82 	movabs rdi,0x74f50f822a600e99
    1cc8:	0f f5 74 
    1ccb:	48 89 ce             	mov    rsi,rcx
    1cce:	4c 31 f6             	xor    rsi,r14
    1cd1:	48 01 fe             	add    rsi,rdi
    1cd4:	48 89 f7             	mov    rdi,rsi
    1cd7:	48 c1 ef 29          	shr    rdi,0x29
    1cdb:	48 c1 e6 17          	shl    rsi,0x17
    1cdf:	48 09 fe             	or     rsi,rdi
    1ce2:	49 b8 c8 72 1d a3 e6 	movabs r8,0x156b2ce6a31d72c8
    1ce9:	2c 6b 15 
    1cec:	4c 89 f7             	mov    rdi,r14
    1cef:	48 01 df             	add    rdi,rbx
    1cf2:	4c 31 c7             	xor    rdi,r8
    1cf5:	49 89 f8             	mov    r8,rdi
    1cf8:	49 c1 e8 17          	shr    r8,0x17
    1cfc:	48 c1 e7 29          	shl    rdi,0x29
    1d00:	4c 09 c7             	or     rdi,r8
    1d03:	48 31 cf             	xor    rdi,rcx
    1d06:	48 01 d6             	add    rsi,rdx
    1d09:	48 b9 26 3b 98 94 af 	movabs rcx,0x565767af94983b26
    1d10:	67 57 56 
    1d13:	48 89 f2             	mov    rdx,rsi
    1d16:	48 01 fa             	add    rdx,rdi
    1d19:	48 31 ca             	xor    rdx,rcx
    1d1c:	48 89 d1             	mov    rcx,rdx
    1d1f:	48 c1 e9 3b          	shr    rcx,0x3b
    1d23:	48 c1 e2 05          	shl    rdx,0x5
    1d27:	48 09 ca             	or     rdx,rcx
    1d2a:	49 b8 f7 d6 da 1b 4b 	movabs r8,0xb5e14a4b1bdad6f7
    1d31:	4a e1 b5 
    1d34:	48 89 f1             	mov    rcx,rsi
    1d37:	48 31 d9             	xor    rcx,rbx
    1d3a:	4c 01 c1             	add    rcx,r8
    1d3d:	49 89 c8             	mov    r8,rcx
    1d40:	49 c1 e8 0b          	shr    r8,0xb
    1d44:	48 c1 e1 35          	shl    rcx,0x35
    1d48:	4c 09 c1             	or     rcx,r8
    1d4b:	48 31 da             	xor    rdx,rbx
    1d4e:	4c 01 f1             	add    rcx,r14
    1d51:	49 b8 29 2a a8 f4 9e 	movabs r8,0x445a669ef4a82a29
    1d58:	66 5a 44 
    1d5b:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
    1d5f:	4c 31 c3             	xor    rbx,r8
    1d62:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
    1d66:	48 b8 2f d5 ba 53 14 	movabs rax,0x60fc2a1453bad52f
    1d6d:	2a fc 60 
    1d70:	49 01 c0             	add    r8,rax
    1d73:	49 be d0 40 62 f3 8d 	movabs r14,0x648f348df36240d0
    1d7a:	34 8f 64 
    1d7d:	4d 31 f5             	xor    r13,r14
    1d80:	4c 01 ee             	add    rsi,r13
    1d83:	4c 31 c7             	xor    rdi,r8
    1d86:	48 01 d9             	add    rcx,rbx
    1d89:	4c 8b 6d e0          	mov    r13,QWORD PTR [rbp-0x20]
    1d8d:	4d 89 e8             	mov    r8,r13
    1d90:	48 b8 8d 9d 35 45 dd 	movabs rax,0xa1e864dd45359d8d
    1d97:	64 e8 a1 
    1d9a:	49 01 c0             	add    r8,rax
    1d9d:	4c 31 c2             	xor    rdx,r8
    1da0:	49 b8 84 03 13 86 78 	movabs r8,0x9743a27886130384
    1da7:	a2 43 97 
    1daa:	48 89 cb             	mov    rbx,rcx
    1dad:	48 01 d3             	add    rbx,rdx
    1db0:	4c 31 c3             	xor    rbx,r8
    1db3:	49 89 d8             	mov    r8,rbx
    1db6:	49 c1 e8 2f          	shr    r8,0x2f
    1dba:	48 c1 e3 11          	shl    rbx,0x11
    1dbe:	4c 09 c3             	or     rbx,r8
    1dc1:	49 b8 55 9f 55 0d 14 	movabs r8,0xf6cd85140d559f55
    1dc8:	85 cd f6 
    1dcb:	48 31 fb             	xor    rbx,rdi
    1dce:	48 31 cf             	xor    rdi,rcx
    1dd1:	4c 01 c7             	add    rdi,r8
    1dd4:	49 89 f8             	mov    r8,rdi
    1dd7:	49 c1 e8 33          	shr    r8,0x33
    1ddb:	48 c1 e7 0d          	shl    rdi,0xd
    1ddf:	4c 09 c7             	or     rdi,r8
    1de2:	48 01 f7             	add    rdi,rsi
    1de5:	48 be e2 cb 8d 77 41 	movabs rsi,0xd82fdd41778dcbe2
    1dec:	dd 2f d8 
    1def:	49 89 df             	mov    r15,rbx
    1df2:	49 01 ff             	add    r15,rdi
    1df5:	49 31 f7             	xor    r15,rsi
    1df8:	4c 89 fe             	mov    rsi,r15
    1dfb:	48 c1 ee 15          	shr    rsi,0x15
    1dff:	49 c1 e7 2b          	shl    r15,0x2b
    1e03:	49 09 f7             	or     r15,rsi
    1e06:	48 be b3 67 d0 fe dc 	movabs rsi,0x37b9bfdcfed067b3
    1e0d:	bf b9 37 
    1e10:	49 89 fe             	mov    r14,rdi
    1e13:	49 31 d6             	xor    r14,rdx
    1e16:	49 01 f6             	add    r14,rsi
    1e19:	4c 89 f6             	mov    rsi,r14
    1e1c:	48 c1 ee 23          	shr    rsi,0x23
    1e20:	49 c1 e6 1d          	shl    r14,0x1d
    1e24:	49 09 f6             	or     r14,rsi
    1e27:	49 31 d7             	xor    r15,rdx
    1e2a:	49 01 ce             	add    r14,rcx
    1e2d:	48 ba 11 30 4b f0 a5 	movabs rdx,0x78a5faa5f04b3011
    1e34:	fa a5 78 
    1e37:	48 89 de             	mov    rsi,rbx
    1e3a:	4c 31 f6             	xor    rsi,r14
    1e3d:	48 01 d6             	add    rsi,rdx
    1e40:	48 89 f2             	mov    rdx,rsi
    1e43:	48 c1 ea 35          	shr    rdx,0x35
    1e47:	48 c1 e6 0b          	shl    rsi,0xb
    1e4b:	48 09 d6             	or     rsi,rdx
    1e4e:	48 ba 40 94 08 69 0a 	movabs rdx,0x191c180a69089440
    1e55:	18 1c 19 
    1e58:	4c 89 f1             	mov    rcx,r14
    1e5b:	4c 01 f9             	add    rcx,r15
    1e5e:	48 31 d1             	xor    rcx,rdx
    1e61:	48 89 ca             	mov    rdx,rcx
    1e64:	48 c1 ea 2d          	shr    rdx,0x2d
    1e68:	48 c1 e1 13          	shl    rcx,0x13
    1e6c:	48 09 d1             	or     rcx,rdx
    1e6f:	48 31 d9             	xor    rcx,rbx
    1e72:	48 01 fe             	add    rsi,rdi
    1e75:	48 bf 9e 5c 83 5a d3 	movabs rdi,0x5a0852d35a835c9e
    1e7c:	52 08 5a 
    1e7f:	48 89 f2             	mov    rdx,rsi
    1e82:	48 01 ca             	add    rdx,rcx
    1e85:	48 31 fa             	xor    rdx,rdi
    1e88:	48 89 d7             	mov    rdi,rdx
    1e8b:	48 c1 ef 11          	shr    rdi,0x11
    1e8f:	48 c1 e2 2f          	shl    rdx,0x2f
    1e93:	48 09 fa             	or     rdx,rdi
    1e96:	48 bf 6f f8 c5 e1 6e 	movabs rdi,0xb992356ee1c5f86f
    1e9d:	35 92 b9 
    1ea0:	48 89 f3             	mov    rbx,rsi
    1ea3:	4c 31 fb             	xor    rbx,r15
    1ea6:	48 01 fb             	add    rbx,rdi
    1ea9:	48 89 df             	mov    rdi,rbx
    1eac:	48 c1 ef 21          	shr    rdi,0x21
    1eb0:	48 c1 e3 1f          	shl    rbx,0x1f
    1eb4:	48 09 fb             	or     rbx,rdi
    1eb7:	4c 31 fa             	xor    rdx,r15
    1eba:	4c 01 f3             	add    rbx,r14
    1ebd:	49 b8 cd c0 40 d3 37 	movabs r8,0xfa7e7037d340c0cd
    1ec4:	70 7e fa 
    1ec7:	48 89 cf             	mov    rdi,rcx
    1eca:	48 31 df             	xor    rdi,rbx
    1ecd:	4c 01 c7             	add    rdi,r8
    1ed0:	49 89 f8             	mov    r8,rdi
    1ed3:	49 c1 e8 39          	shr    r8,0x39
    1ed7:	48 c1 e7 07          	shl    rdi,0x7
    1edb:	4c 09 c7             	or     rdi,r8
    1ede:	49 be fc 24 fe 4b 9c 	movabs r14,0x9af48d9c4bfe24fc
    1ee5:	8d f4 9a 
    1ee8:	49 89 d8             	mov    r8,rbx
    1eeb:	49 01 d0             	add    r8,rdx
    1eee:	4d 31 f0             	xor    r8,r14
    1ef1:	4d 89 c6             	mov    r14,r8
    1ef4:	49 c1 ee 29          	shr    r14,0x29
    1ef8:	49 c1 e0 17          	shl    r8,0x17
    1efc:	4d 09 f0             	or     r8,r14
    1eff:	49 31 c8             	xor    r8,rcx
    1f02:	48 01 f7             	add    rdi,rsi
    1f05:	48 be 5a ed 78 3d 65 	movabs rsi,0xdbe0c8653d78ed5a
    1f0c:	c8 e0 db 
    1f0f:	48 89 f9             	mov    rcx,rdi
    1f12:	4c 01 c1             	add    rcx,r8
    1f15:	48 31 f1             	xor    rcx,rsi
    1f18:	48 89 ce             	mov    rsi,rcx
    1f1b:	48 c1 ee 0b          	shr    rsi,0xb
    1f1f:	48 c1 e1 35          	shl    rcx,0x35
    1f23:	48 09 f1             	or     rcx,rsi
    1f26:	48 be 2b 89 bb c4 00 	movabs rsi,0x3b6aab00c4bb892b
    1f2d:	ab 6a 3b 
    1f30:	49 89 fe             	mov    r14,rdi
    1f33:	49 31 d6             	xor    r14,rdx
    1f36:	49 01 f6             	add    r14,rsi
    1f39:	4c 89 f6             	mov    rsi,r14
    1f3c:	48 c1 ee 1b          	shr    rsi,0x1b
    1f40:	49 c1 e6 25          	shl    r14,0x25
    1f44:	49 09 f6             	or     r14,rsi
    1f47:	48 31 d1             	xor    rcx,rdx
    1f4a:	49 01 de             	add    r14,rbx
    1f4d:	48 ba 89 51 36 b6 c9 	movabs rdx,0x7c56e5c9b6365189
    1f54:	e5 56 7c 
    1f57:	4c 89 c6             	mov    rsi,r8
    1f5a:	4c 31 f6             	xor    rsi,r14
    1f5d:	48 01 d6             	add    rsi,rdx
    1f60:	48 89 f2             	mov    rdx,rsi
    1f63:	48 c1 ea 3b          	shr    rdx,0x3b
    1f67:	48 c1 e6 05          	shl    rsi,0x5
    1f6b:	48 09 d6             	or     rsi,rdx
    1f6e:	48 ba b8 b5 f3 2e 2e 	movabs rdx,0x1ccd032e2ef3b5b8
    1f75:	03 cd 1c 
    1f78:	4d 89 f7             	mov    r15,r14
    1f7b:	49 01 cf             	add    r15,rcx
    1f7e:	49 31 d7             	xor    r15,rdx
    1f81:	4c 89 fa             	mov    rdx,r15
    1f84:	48 c1 ea 25          	shr    rdx,0x25
    1f88:	49 c1 e7 1b          	shl    r15,0x1b
    1f8c:	49 09 d7             	or     r15,rdx
    1f8f:	4d 31 c7             	xor    r15,r8
    1f92:	48 01 fe             	add    rsi,rdi
    1f95:	48 bf 16 7e 6e 20 f7 	movabs rdi,0x5db93df7206e7e16
    1f9c:	3d b9 5d 
    1f9f:	48 89 f2             	mov    rdx,rsi
    1fa2:	4c 01 fa             	add    rdx,r15
    1fa5:	48 31 fa             	xor    rdx,rdi
    1fa8:	48 89 d7             	mov    rdi,rdx
    1fab:	48 c1 ef 05          	shr    rdi,0x5
    1faf:	48 c1 e2 3b          	shl    rdx,0x3b
    1fb3:	48 09 fa             	or     rdx,rdi
    1fb6:	48 bf e7 19 b1 a7 92 	movabs rdi,0xbd432092a7b119e7
    1fbd:	20 43 bd 
    1fc0:	48 89 f3             	mov    rbx,rsi
    1fc3:	48 31 cb             	xor    rbx,rcx
    1fc6:	48 01 fb             	add    rbx,rdi
    1fc9:	48 89 df             	mov    rdi,rbx
    1fcc:	48 c1 ef 17          	shr    rdi,0x17
    1fd0:	48 c1 e3 29          	shl    rbx,0x29
    1fd4:	48 09 fb             	or     rbx,rdi
    1fd7:	48 31 ca             	xor    rdx,rcx
    1fda:	4c 01 f3             	add    rbx,r14
    1fdd:	48 b9 45 e2 2b 99 5b 	movabs rcx,0xfe2f5b5b992be245
    1fe4:	5b 2f fe 
    1fe7:	4c 89 ff             	mov    rdi,r15
    1fea:	48 31 df             	xor    rdi,rbx
    1fed:	48 01 cf             	add    rdi,rcx
    1ff0:	48 89 f9             	mov    rcx,rdi
    1ff3:	48 c1 e9 3d          	shr    rcx,0x3d
    1ff7:	48 c1 e7 03          	shl    rdi,0x3
    1ffb:	48 09 cf             	or     rdi,rcx
    1ffe:	48 b9 74 46 e9 11 c0 	movabs rcx,0x9ea578c011e94674
    2005:	78 a5 9e 
    2008:	49 89 d8             	mov    r8,rbx
    200b:	49 01 d0             	add    r8,rdx
    200e:	49 31 c8             	xor    r8,rcx
    2011:	4c 89 c1             	mov    rcx,r8
    2014:	48 c1 e9 33          	shr    rcx,0x33
    2018:	49 c1 e0 0d          	shl    r8,0xd
    201c:	49 09 c8             	or     r8,rcx
    201f:	4d 31 f8             	xor    r8,r15
    2022:	48 01 f7             	add    rdi,rsi
    2025:	48 be d2 0e 64 03 89 	movabs rsi,0xdf91b38903640ed2
    202c:	b3 91 df 
    202f:	48 89 f9             	mov    rcx,rdi
    2032:	4c 01 c1             	add    rcx,r8
    2035:	48 31 f1             	xor    rcx,rsi
    2038:	48 89 ce             	mov    rsi,rcx
    203b:	48 c1 ee 03          	shr    rsi,0x3
    203f:	48 c1 e1 3d          	shl    rcx,0x3d
    2043:	48 09 f1             	or     rcx,rsi
    2046:	48 be a3 aa a6 8a 24 	movabs rsi,0x3f1b96248aa6aaa3
    204d:	96 1b 3f 
    2050:	49 89 fe             	mov    r14,rdi
    2053:	49 31 d6             	xor    r14,rdx
    2056:	49 01 f6             	add    r14,rsi
    2059:	4c 89 f6             	mov    rsi,r14
    205c:	48 c1 ee 23          	shr    rsi,0x23
    2060:	49 c1 e6 1d          	shl    r14,0x1d
    2064:	49 09 f6             	or     r14,rsi
    2067:	48 31 d1             	xor    rcx,rdx
    206a:	49 01 de             	add    r14,rbx
    206d:	48 ba 01 73 21 7c ed 	movabs rdx,0x8007d0ed7c217301
    2074:	d0 07 80 
    2077:	4c 89 c6             	mov    rsi,r8
    207a:	4c 31 f6             	xor    rsi,r14
    207d:	48 01 d6             	add    rsi,rdx
    2080:	48 89 f2             	mov    rdx,rsi
    2083:	48 c1 ea 2f          	shr    rdx,0x2f
    2087:	48 c1 e6 11          	shl    rsi,0x11
    208b:	48 09 d6             	or     rsi,rdx
    208e:	48 ba 30 d7 de f4 51 	movabs rdx,0x207dee51f4ded730
    2095:	ee 7d 20 
    2098:	4c 89 f3             	mov    rbx,r14
    209b:	48 01 cb             	add    rbx,rcx
    209e:	48 31 d3             	xor    rbx,rdx
    20a1:	48 89 da             	mov    rdx,rbx
    20a4:	48 c1 ea 21          	shr    rdx,0x21
    20a8:	48 c1 e3 1f          	shl    rbx,0x1f
    20ac:	48 09 d3             	or     rbx,rdx
    20af:	4c 31 c3             	xor    rbx,r8
    20b2:	48 01 fe             	add    rsi,rdi
    20b5:	48 ba 8e 9f 59 e6 1a 	movabs rdx,0x616a291ae6599f8e
    20bc:	29 6a 61 
    20bf:	48 89 f7             	mov    rdi,rsi
    20c2:	48 01 df             	add    rdi,rbx
    20c5:	48 31 d7             	xor    rdi,rdx
    20c8:	48 89 fa             	mov    rdx,rdi
    20cb:	48 c1 ea 35          	shr    rdx,0x35
    20cf:	48 c1 e7 0b          	shl    rdi,0xb
    20d3:	48 09 d7             	or     rdi,rdx
    20d6:	48 ba 5f 3b 9c 6d b6 	movabs rdx,0xc0f40bb66d9c3b5f
    20dd:	0b f4 c0 
    20e0:	49 89 f7             	mov    r15,rsi
    20e3:	49 31 cf             	xor    r15,rcx
    20e6:	49 01 d7             	add    r15,rdx
    20e9:	4c 89 fa             	mov    rdx,r15
    20ec:	48 c1 ea 15          	shr    rdx,0x15
    20f0:	49 c1 e7 2b          	shl    r15,0x2b
    20f4:	49 09 d7             	or     r15,rdx
    20f7:	48 31 cf             	xor    rdi,rcx
    20fa:	4d 01 f7             	add    r15,r14
    20fd:	48 b9 bd 03 17 5f 7f 	movabs rcx,0x1e0467f5f1703bd
    2104:	46 e0 01 
    2107:	48 89 da             	mov    rdx,rbx
    210a:	4c 31 fa             	xor    rdx,r15
    210d:	48 01 ca             	add    rdx,rcx
    2110:	48 89 d1             	mov    rcx,rdx
    2113:	48 c1 e9 2d          	shr    rcx,0x2d
    2117:	48 c1 e2 13          	shl    rdx,0x13
    211b:	48 09 ca             	or     rdx,rcx
    211e:	49 b8 ec 67 d4 d7 e3 	movabs r8,0xa25663e3d7d467ec
    2125:	63 56 a2 
    2128:	4c 89 f9             	mov    rcx,r15
    212b:	48 01 f9             	add    rcx,rdi
    212e:	4c 31 c1             	xor    rcx,r8
    2131:	49 89 c8             	mov    r8,rcx
    2134:	49 c1 e8 1b          	shr    r8,0x1b
    2138:	48 c1 e1 25          	shl    rcx,0x25
    213c:	4c 09 c1             	or     rcx,r8
    213f:	48 31 d9             	xor    rcx,rbx
    2142:	48 01 f2             	add    rdx,rsi
    2145:	48 be 4a 30 4f c9 ac 	movabs rsi,0xe3429eacc94f304a
    214c:	9e 42 e3 
    214f:	48 89 d3             	mov    rbx,rdx
    2152:	48 01 cb             	add    rbx,rcx
    2155:	48 31 f3             	xor    rbx,rsi
    2158:	48 89 de             	mov    rsi,rbx
    215b:	48 c1 ee 39          	shr    rsi,0x39
    215f:	48 c1 e3 07          	shl    rbx,0x7
    2163:	48 09 f3             	or     rbx,rsi
    2166:	48 be 1b cc 91 50 48 	movabs rsi,0x42cc81485091cc1b
    216d:	81 cc 42 
    2170:	49 89 d6             	mov    r14,rdx
    2173:	49 31 fe             	xor    r14,rdi
    2176:	49 01 f6             	add    r14,rsi
    2179:	4c 89 f6             	mov    rsi,r14
    217c:	48 c1 ee 11          	shr    rsi,0x11
    2180:	49 c1 e6 2f          	shl    r14,0x2f
    2184:	49 09 f6             	or     r14,rsi
    2187:	48 31 fb             	xor    rbx,rdi
    218a:	4d 01 fe             	add    r14,r15
    218d:	48 bf 79 94 0c 42 11 	movabs rdi,0x83b8bc11420c9479
    2194:	bc b8 83 
    2197:	48 89 ce             	mov    rsi,rcx
    219a:	4c 31 f6             	xor    rsi,r14
    219d:	48 01 fe             	add    rsi,rdi
    21a0:	48 89 f7             	mov    rdi,rsi
    21a3:	48 c1 ef 29          	shr    rdi,0x29
    21a7:	48 c1 e6 17          	shl    rsi,0x17
    21ab:	48 09 fe             	or     rsi,rdi
    21ae:	49 b8 a8 f8 c9 ba 75 	movabs r8,0x242ed975bac9f8a8
    21b5:	d9 2e 24 
    21b8:	4c 89 f7             	mov    rdi,r14
    21bb:	48 01 df             	add    rdi,rbx
    21be:	4c 31 c7             	xor    rdi,r8
    21c1:	49 89 f8             	mov    r8,rdi
    21c4:	49 c1 e8 17          	shr    r8,0x17
    21c8:	48 c1 e7 29          	shl    rdi,0x29
    21cc:	4c 09 c7             	or     rdi,r8
    21cf:	48 31 cf             	xor    rdi,rcx
    21d2:	48 01 d6             	add    rsi,rdx
    21d5:	48 b9 06 c1 44 ac 3e 	movabs rcx,0x651b143eac44c106
    21dc:	14 1b 65 
    21df:	48 89 f2             	mov    rdx,rsi
    21e2:	48 01 fa             	add    rdx,rdi
    21e5:	48 31 ca             	xor    rdx,rcx
    21e8:	48 89 d1             	mov    rcx,rdx
    21eb:	48 c1 e9 3b          	shr    rcx,0x3b
    21ef:	48 c1 e2 05          	shl    rdx,0x5
    21f3:	48 09 ca             	or     rdx,rcx
    21f6:	49 b8 d7 5c 87 33 da 	movabs r8,0xc4a4f6da33875cd7
    21fd:	f6 a4 c4 
    2200:	48 89 f1             	mov    rcx,rsi
    2203:	48 31 d9             	xor    rcx,rbx
    2206:	4c 01 c1             	add    rcx,r8
    2209:	49 89 c8             	mov    r8,rcx
    220c:	49 c1 e8 0b          	shr    r8,0xb
    2210:	48 c1 e1 35          	shl    rcx,0x35
    2214:	4c 09 c1             	or     rcx,r8
    2217:	48 31 da             	xor    rdx,rbx
    221a:	4c 01 f1             	add    rcx,r14
    221d:	4d 89 e8             	mov    r8,r13
    2220:	48 b8 bc 01 f3 bd 41 	movabs rax,0x425e8241bdf301bc
    2227:	82 5e 42 
    222a:	49 01 c0             	add    r8,rax
    222d:	48 bb fa 8e e5 7d 3b 	movabs rbx,0xe4c0453b7de58efa
    2234:	45 c0 e4 
    2237:	4c 8b 75 f8          	mov    r14,QWORD PTR [rbp-0x8]
    223b:	49 31 de             	xor    r14,rbx
    223e:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
    2242:	4c 89 eb             	mov    rbx,r13
    2245:	48 b8 5e 39 78 cc 78 	movabs rax,0x1724778cc78395e
    224c:	47 72 01 
    224f:	48 01 c3             	add    rbx,rax
    2252:	49 bf ff e4 25 7a 36 	movabs r15,0xc4f512367a25e4ff
    2259:	12 f5 c4 
    225c:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
    2260:	4c 31 f8             	xor    rax,r15
    2263:	48 01 c6             	add    rsi,rax
    2266:	48 31 df             	xor    rdi,rbx
    2269:	4c 01 f1             	add    rcx,r14
    226c:	4c 31 c2             	xor    rdx,r8
    226f:	49 b8 64 89 bf 9d 07 	movabs r8,0xa6074f079dbf8964
    2276:	4f 07 a6 
    2279:	48 89 cb             	mov    rbx,rcx
    227c:	48 01 d3             	add    rbx,rdx
    227f:	4c 31 c3             	xor    rbx,r8
    2282:	49 89 d8             	mov    r8,rbx
    2285:	49 c1 e8 2f          	shr    r8,0x2f
    2289:	48 c1 e3 11          	shl    rbx,0x11
    228d:	4c 09 c3             	or     rbx,r8
    2290:	49 b8 35 25 02 25 a3 	movabs r8,0x59131a325022535
    2297:	31 91 05 
    229a:	48 31 fb             	xor    rbx,rdi
    229d:	48 31 cf             	xor    rdi,rcx
    22a0:	4c 01 c7             	add    rdi,r8
    22a3:	49 89 f8             	mov    r8,rdi
    22a6:	49 c1 e8 33          	shr    r8,0x33
    22aa:	48 c1 e7 0d          	shl    rdi,0xd
    22ae:	4c 09 c7             	or     rdi,r8
    22b1:	48 01 f7             	add    rdi,rsi
    22b4:	48 be c2 51 3a 8f d0 	movabs rsi,0xe6f389d08f3a51c2
    22bb:	89 f3 e6 
    22be:	49 89 df             	mov    r15,rbx
    22c1:	49 01 ff             	add    r15,rdi
    22c4:	49 31 f7             	xor    r15,rsi
    22c7:	4c 89 fe             	mov    rsi,r15
    22ca:	48 c1 ee 15          	shr    rsi,0x15
    22ce:	49 c1 e7 2b          	shl    r15,0x2b
    22d2:	49 09 f7             	or     r15,rsi
    22d5:	48 be 93 ed 7c 16 6c 	movabs rsi,0x467d6c6c167ced93
    22dc:	6c 7d 46 
    22df:	49 89 fe             	mov    r14,rdi
    22e2:	49 31 d6             	xor    r14,rdx
    22e5:	49 01 f6             	add    r14,rsi
    22e8:	4c 89 f6             	mov    rsi,r14
    22eb:	48 c1 ee 23          	shr    rsi,0x23
    22ef:	49 c1 e6 1d          	shl    r14,0x1d
    22f3:	49 09 f6             	or     r14,rsi
    22f6:	49 31 d7             	xor    r15,rdx
    22f9:	49 01 ce             	add    r14,rcx
    22fc:	48 ba f1 b5 f7 07 35 	movabs rdx,0x8769a73507f7b5f1
    2303:	a7 69 87 
    2306:	48 89 de             	mov    rsi,rbx
    2309:	4c 31 f6             	xor    rsi,r14
    230c:	48 01 d6             	add    rsi,rdx
    230f:	48 89 f2             	mov    rdx,rsi
    2312:	48 c1 ea 35          	shr    rdx,0x35
    2316:	48 c1 e6 0b          	shl    rsi,0xb
    231a:	48 09 d6             	or     rsi,rdx
    231d:	48 ba 20 1a b5 80 99 	movabs rdx,0x27dfc49980b51a20
    2324:	c4 df 27 
    2327:	4c 89 f1             	mov    rcx,r14
    232a:	4c 01 f9             	add    rcx,r15
    232d:	48 31 d1             	xor    rcx,rdx
    2330:	48 89 ca             	mov    rdx,rcx
    2333:	48 c1 ea 2d          	shr    rdx,0x2d
    2337:	48 c1 e1 13          	shl    rcx,0x13
    233b:	48 09 d1             	or     rcx,rdx
    233e:	48 31 d9             	xor    rcx,rbx
    2341:	48 01 fe             	add    rsi,rdi
    2344:	48 bf 7e e2 2f 72 62 	movabs rdi,0x68cbff62722fe27e
    234b:	ff cb 68 
    234e:	48 89 f2             	mov    rdx,rsi
    2351:	48 01 ca             	add    rdx,rcx
    2354:	48 31 fa             	xor    rdx,rdi
    2357:	48 89 d7             	mov    rdi,rdx
    235a:	48 c1 ef 11          	shr    rdi,0x11
    235e:	48 c1 e2 2f          	shl    rdx,0x2f
    2362:	48 09 fa             	or     rdx,rdi
    2365:	48 bf 4f 7e 72 f9 fd 	movabs rdi,0xc855e1fdf9727e4f
    236c:	e1 55 c8 
    236f:	48 89 f3             	mov    rbx,rsi
    2372:	4c 31 fb             	xor    rbx,r15
    2375:	48 01 fb             	add    rbx,rdi
    2378:	48 89 df             	mov    rdi,rbx
    237b:	48 c1 ef 21          	shr    rdi,0x21
    237f:	48 c1 e3 1f          	shl    rbx,0x1f
    2383:	48 09 fb             	or     rbx,rdi
    2386:	4c 31 fa             	xor    rdx,r15
    2389:	4c 01 f3             	add    rbx,r14
    238c:	49 b8 ad 46 ed ea c6 	movabs r8,0x9421cc6eaed46ad
    2393:	1c 42 09 
    2396:	48 89 cf             	mov    rdi,rcx
    2399:	48 31 df             	xor    rdi,rbx
    239c:	4c 01 c7             	add    rdi,r8
    239f:	49 89 f8             	mov    r8,rdi
    23a2:	49 c1 e8 39          	shr    r8,0x39
    23a6:	48 c1 e7 07          	shl    rdi,0x7
    23aa:	4c 09 c7             	or     rdi,r8
    23ad:	48 b8 dc aa aa 63 2b 	movabs rax,0xa9b83a2b63aaaadc
    23b4:	3a b8 a9 
    23b7:	49 89 d8             	mov    r8,rbx
    23ba:	49 01 d0             	add    r8,rdx
    23bd:	49 31 c0             	xor    r8,rax
    23c0:	4c 89 c0             	mov    rax,r8
    23c3:	48 c1 e8 29          	shr    rax,0x29
    23c7:	49 c1 e0 17          	shl    r8,0x17
    23cb:	49 09 c0             	or     r8,rax
    23ce:	49 31 c8             	xor    r8,rcx
    23d1:	48 01 f7             	add    rdi,rsi
    23d4:	48 be 3a 73 25 55 f4 	movabs rsi,0xeaa474f45525733a
    23db:	74 a4 ea 
    23de:	48 89 f9             	mov    rcx,rdi
    23e1:	4c 01 c1             	add    rcx,r8
    23e4:	48 31 f1             	xor    rcx,rsi
    23e7:	48 89 ce             	mov    rsi,rcx
    23ea:	48 c1 ee 0b          	shr    rsi,0xb
    23ee:	48 c1 e1 35          	shl    rcx,0x35
    23f2:	48 09 f1             	or     rcx,rsi
    23f5:	48 be 0b 0f 68 dc 8f 	movabs rsi,0x4a2e578fdc680f0b
    23fc:	57 2e 4a 
    23ff:	49 89 fe             	mov    r14,rdi
    2402:	49 31 d6             	xor    r14,rdx
    2405:	49 01 f6             	add    r14,rsi
    2408:	4c 89 f6             	mov    rsi,r14
    240b:	48 c1 ee 1b          	shr    rsi,0x1b
    240f:	49 c1 e6 25          	shl    r14,0x25
    2413:	49 09 f6             	or     r14,rsi
    2416:	48 31 d1             	xor    rcx,rdx
    2419:	49 01 de             	add    r14,rbx
    241c:	48 ba 69 d7 e2 cd 58 	movabs rdx,0x8b1a9258cde2d769
    2423:	92 1a 8b 
    2426:	4c 89 c6             	mov    rsi,r8
    2429:	4c 31 f6             	xor    rsi,r14
    242c:	48 01 d6             	add    rsi,rdx
    242f:	48 89 f2             	mov    rdx,rsi
    2432:	48 c1 ea 3b          	shr    rdx,0x3b
    2436:	48 c1 e6 05          	shl    rsi,0x5
    243a:	48 09 d6             	or     rsi,rdx
    243d:	48 ba 98 3b a0 46 bd 	movabs rdx,0x2b90afbd46a03b98
    2444:	af 90 2b 
    2447:	4d 89 f7             	mov    r15,r14
    244a:	49 01 cf             	add    r15,rcx
    244d:	49 31 d7             	xor    r15,rdx
    2450:	4c 89 fa             	mov    rdx,r15
    2453:	48 c1 ea 25          	shr    rdx,0x25
    2457:	49 c1 e7 1b          	shl    r15,0x1b
    245b:	49 09 d7             	or     r15,rdx
    245e:	4d 31 c7             	xor    r15,r8
    2461:	48 01 fe             	add    rsi,rdi
    2464:	48 bf f6 03 1b 38 86 	movabs rdi,0x6c7cea86381b03f6
    246b:	ea 7c 6c 
    246e:	48 89 f2             	mov    rdx,rsi
    2471:	4c 01 fa             	add    rdx,r15
    2474:	48 31 fa             	xor    rdx,rdi
    2477:	48 89 d7             	mov    rdi,rdx
    247a:	48 c1 ef 05          	shr    rdi,0x5
    247e:	48 c1 e2 3b          	shl    rdx,0x3b
    2482:	48 09 fa             	or     rdx,rdi
    2485:	48 bf c7 9f 5d bf 21 	movabs rdi,0xcc06cd21bf5d9fc7
    248c:	cd 06 cc 
    248f:	48 89 f3             	mov    rbx,rsi
    2492:	48 31 cb             	xor    rbx,rcx
    2495:	48 01 fb             	add    rbx,rdi
    2498:	48 89 df             	mov    rdi,rbx
    249b:	48 c1 ef 17          	shr    rdi,0x17
    249f:	48 c1 e3 29          	shl    rbx,0x29
    24a3:	48 09 fb             	or     rbx,rdi
    24a6:	48 31 ca             	xor    rdx,rcx
    24a9:	4c 01 f3             	add    rbx,r14
    24ac:	48 b9 25 68 d8 b0 ea 	movabs rcx,0xcf307eab0d86825
    24b3:	07 f3 0c 
    24b6:	4c 89 ff             	mov    rdi,r15
    24b9:	48 31 df             	xor    rdi,rbx
    24bc:	48 01 cf             	add    rdi,rcx
    24bf:	48 89 f9             	mov    rcx,rdi
    24c2:	48 c1 e9 3d          	shr    rcx,0x3d
    24c6:	48 c1 e7 03          	shl    rdi,0x3
    24ca:	48 09 cf             	or     rdi,rcx
    24cd:	48 b9 54 cc 95 29 4f 	movabs rcx,0xad69254f2995cc54
    24d4:	25 69 ad 
    24d7:	49 89 d8             	mov    r8,rbx
    24da:	49 01 d0             	add    r8,rdx
    24dd:	49 31 c8             	xor    r8,rcx
    24e0:	4c 89 c1             	mov    rcx,r8
    24e3:	48 c1 e9 33          	shr    rcx,0x33
    24e7:	49 c1 e0 0d          	shl    r8,0xd
    24eb:	49 09 c8             	or     r8,rcx
    24ee:	4d 31 f8             	xor    r8,r15
    24f1:	48 01 f7             	add    rdi,rsi
    24f4:	48 be b2 94 10 1b 18 	movabs rsi,0xee5560181b1094b2
    24fb:	60 55 ee 
    24fe:	48 89 f9             	mov    rcx,rdi
    2501:	4c 01 c1             	add    rcx,r8
    2504:	48 31 f1             	xor    rcx,rsi
    2507:	48 89 ce             	mov    rsi,rcx
    250a:	48 c1 ee 03          	shr    rsi,0x3
    250e:	48 c1 e1 3d          	shl    rcx,0x3d
    2512:	48 09 f1             	or     rcx,rsi
    2515:	48 be 83 30 53 a2 b3 	movabs rsi,0x4ddf42b3a2533083
    251c:	42 df 4d 
    251f:	49 89 fe             	mov    r14,rdi
    2522:	49 31 d6             	xor    r14,rdx
    2525:	49 01 f6             	add    r14,rsi
    2528:	4c 89 f6             	mov    rsi,r14
    252b:	48 c1 ee 23          	shr    rsi,0x23
    252f:	49 c1 e6 1d          	shl    r14,0x1d
    2533:	49 09 f6             	or     r14,rsi
    2536:	48 31 d1             	xor    rcx,rdx
    2539:	49 01 de             	add    r14,rbx
    253c:	48 ba e1 f8 cd 93 7c 	movabs rdx,0x8ecb7d7c93cdf8e1
    2543:	7d cb 8e 
    2546:	4c 89 c6             	mov    rsi,r8
    2549:	4c 31 f6             	xor    rsi,r14
    254c:	48 01 d6             	add    rsi,rdx
    254f:	48 89 f2             	mov    rdx,rsi
    2552:	48 c1 ea 2f          	shr    rdx,0x2f
    2556:	48 c1 e6 11          	shl    rsi,0x11
    255a:	48 09 d6             	or     rsi,rdx
    255d:	48 ba 10 5d 8b 0c e1 	movabs rdx,0x2f419ae10c8b5d10
    2564:	9a 41 2f 
    2567:	4d 89 f7             	mov    r15,r14
    256a:	49 01 cf             	add    r15,rcx
    256d:	49 31 d7             	xor    r15,rdx
    2570:	4c 89 fa             	mov    rdx,r15
    2573:	48 c1 ea 21          	shr    rdx,0x21
    2577:	49 c1 e7 1f          	shl    r15,0x1f
    257b:	49 09 d7             	or     r15,rdx
    257e:	4d 31 c7             	xor    r15,r8
    2581:	48 01 fe             	add    rsi,rdi
    2584:	48 bf 6e 25 06 fe a9 	movabs rdi,0x702dd5a9fe06256e
    258b:	d5 2d 70 
    258e:	48 89 f2             	mov    rdx,rsi
    2591:	4c 01 fa             	add    rdx,r15
    2594:	48 31 fa             	xor    rdx,rdi
    2597:	48 89 d7             	mov    rdi,rdx
    259a:	48 c1 ef 35          	shr    rdi,0x35
    259e:	48 c1 e2 0b          	shl    rdx,0xb
    25a2:	48 09 fa             	or     rdx,rdi
    25a5:	48 bf 3f c1 48 85 45 	movabs rdi,0xcfb7b8458548c13f
    25ac:	b8 b7 cf 
    25af:	48 89 f3             	mov    rbx,rsi
    25b2:	48 31 cb             	xor    rbx,rcx
    25b5:	48 01 fb             	add    rbx,rdi
    25b8:	48 89 df             	mov    rdi,rbx
    25bb:	48 c1 ef 15          	shr    rdi,0x15
    25bf:	48 c1 e3 2b          	shl    rbx,0x2b
    25c3:	48 09 fb             	or     rbx,rdi
    25c6:	48 31 ca             	xor    rdx,rcx
    25c9:	4c 01 f3             	add    rbx,r14
    25cc:	48 b9 9d 89 c3 76 0e 	movabs rcx,0x10a3f30e76c3899d
    25d3:	f3 a3 10 
    25d6:	4c 89 ff             	mov    rdi,r15
    25d9:	48 31 df             	xor    rdi,rbx
    25dc:	48 01 cf             	add    rdi,rcx
    25df:	48 89 f9             	mov    rcx,rdi
    25e2:	48 c1 e9 2d          	shr    rcx,0x2d
    25e6:	48 c1 e7 13          	shl    rdi,0x13
    25ea:	48 09 cf             	or     rdi,rcx
    25ed:	48 b9 cc ed 80 ef 72 	movabs rcx,0xb11a1072ef80edcc
    25f4:	10 1a b1 
    25f7:	49 89 d8             	mov    r8,rbx
    25fa:	49 01 d0             	add    r8,rdx
    25fd:	49 31 c8             	xor    r8,rcx
    2600:	4c 89 c1             	mov    rcx,r8
    2603:	48 c1 e9 1b          	shr    rcx,0x1b
    2607:	49 c1 e0 25          	shl    r8,0x25
    260b:	49 09 c8             	or     r8,rcx
    260e:	4d 31 f8             	xor    r8,r15
    2611:	48 01 f7             	add    rdi,rsi
    2614:	48 be 2a b6 fb e0 3b 	movabs rsi,0xf2064b3be0fbb62a
    261b:	4b 06 f2 
    261e:	48 89 f9             	mov    rcx,rdi
    2621:	4c 01 c1             	add    rcx,r8
    2624:	48 31 f1             	xor    rcx,rsi
    2627:	48 89 ce             	mov    rsi,rcx
    262a:	48 c1 ee 39          	shr    rsi,0x39
    262e:	48 c1 e1 07          	shl    rcx,0x7
    2632:	48 09 f1             	or     rcx,rsi
    2635:	48 be fb 51 3e 68 d7 	movabs rsi,0x51902dd7683e51fb
    263c:	2d 90 51 
    263f:	49 89 fe             	mov    r14,rdi
    2642:	49 31 d6             	xor    r14,rdx
    2645:	49 01 f6             	add    r14,rsi
    2648:	4c 89 f6             	mov    rsi,r14
    264b:	48 c1 ee 11          	shr    rsi,0x11
    264f:	49 c1 e6 2f          	shl    r14,0x2f
    2653:	49 09 f6             	or     r14,rsi
    2656:	48 31 d1             	xor    rcx,rdx
    2659:	49 01 de             	add    r14,rbx
    265c:	48 ba 59 1a b9 59 a0 	movabs rdx,0x927c68a059b91a59
    2663:	68 7c 92 
    2666:	4c 89 c6             	mov    rsi,r8
    2669:	4c 31 f6             	xor    rsi,r14
    266c:	48 01 d6             	add    rsi,rdx
    266f:	48 89 f2             	mov    rdx,rsi
    2672:	48 c1 ea 29          	shr    rdx,0x29
    2676:	48 c1 e6 17          	shl    rsi,0x17
    267a:	48 09 d6             	or     rsi,rdx
    267d:	48 b8 88 7e 76 d2 04 	movabs rax,0x32f28604d2767e88
    2684:	86 f2 32 
    2687:	4c 89 f2             	mov    rdx,r14
    268a:	48 01 ca             	add    rdx,rcx
    268d:	48 31 c2             	xor    rdx,rax
    2690:	48 89 d0             	mov    rax,rdx
    2693:	48 c1 e8 17          	shr    rax,0x17
    2697:	48 c1 e2 29          	shl    rdx,0x29
    269b:	48 09 c2             	or     rdx,rax
    269e:	4c 31 c2             	xor    rdx,r8
    26a1:	48 01 fe             	add    rsi,rdi
    26a4:	49 b8 e6 46 f1 c3 cd 	movabs r8,0x73dec0cdc3f146e6
    26ab:	c0 de 73 
    26ae:	48 89 f7             	mov    rdi,rsi
    26b1:	48 01 d7             	add    rdi,rdx
    26b4:	4c 31 c7             	xor    rdi,r8
    26b7:	49 89 f8             	mov    r8,rdi
    26ba:	49 c1 e8 3b          	shr    r8,0x3b
    26be:	48 c1 e7 05          	shl    rdi,0x5
    26c2:	4c 09 c7             	or     rdi,r8
    26c5:	48 b8 b7 e2 33 4b 69 	movabs rax,0xd368a3694b33e2b7
    26cc:	a3 68 d3 
    26cf:	49 89 f0             	mov    r8,rsi
    26d2:	49 31 c8             	xor    r8,rcx
    26d5:	49 01 c0             	add    r8,rax
    26d8:	4c 89 c0             	mov    rax,r8
    26db:	48 c1 e8 0b          	shr    rax,0xb
    26df:	49 c1 e0 35          	shl    r8,0x35
    26e3:	49 09 c0             	or     r8,rax
    26e6:	48 31 cf             	xor    rdi,rcx
    26e9:	4d 01 f0             	add    r8,r14
    26ec:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
    26f0:	48 b8 eb 65 b0 36 a6 	movabs rax,0xe2d49fa636b065eb
    26f7:	9f d4 e2 
    26fa:	48 01 c1             	add    rcx,rax
    26fd:	48 b8 cb 12 23 85 a7 	movabs rax,0x776a3a7852312cb
    2704:	a3 76 07 
    2707:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
    270b:	48 31 c3             	xor    rbx,rax
    270e:	4c 89 e8             	mov    rax,r13
    2711:	49 bd 8d 9d 35 45 dd 	movabs r13,0xa1e864dd45359d8d
    2718:	64 e8 a1 
    271b:	4c 01 e8             	add    rax,r13
    271e:	4c 8b 6d e8          	mov    r13,QWORD PTR [rbp-0x18]
    2722:	4d 89 ef             	mov    r15,r13
    2725:	49 be 8e 08 e7 e5 5a 	movabs r14,0xa57b7f5ae5e7088e
    272c:	7f 7b a5 
    272f:	4d 31 f7             	xor    r15,r14
    2732:	4c 01 fe             	add    rsi,r15
    2735:	48 31 c2             	xor    rdx,rax
    2738:	49 01 d8             	add    r8,rbx
    273b:	48 31 cf             	xor    rdi,rcx
    273e:	4c 31 c7             	xor    rdi,r8
    2741:	48 31 d7             	xor    rdi,rdx
    2744:	48 31 f7             	xor    rdi,rsi
    2747:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
    274b:	48 31 f7             	xor    rdi,rsi
    274e:	4c 31 ef             	xor    rdi,r13
    2751:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
    2755:	48 31 f7             	xor    rdi,rsi
    2758:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
    275c:	48 31 f7             	xor    rdi,rsi
    275f:	48 be e7 22 4f 11 c4 	movabs rsi,0xe12119c4114f22e7
    2766:	19 21 e1 
    2769:	48 31 f7             	xor    rdi,rsi
    276c:	48 89 fe             	mov    rsi,rdi
    276f:	48 c1 ee 38          	shr    rsi,0x38
    2773:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
    2777:	40 88 72 07          	mov    BYTE PTR [rdx+0x7],sil
    277b:	48 89 fe             	mov    rsi,rdi
    277e:	48 c1 ee 30          	shr    rsi,0x30
    2782:	40 88 72 06          	mov    BYTE PTR [rdx+0x6],sil
    2786:	48 89 fe             	mov    rsi,rdi
    2789:	48 c1 ee 28          	shr    rsi,0x28
    278d:	40 88 72 05          	mov    BYTE PTR [rdx+0x5],sil
    2791:	48 89 fe             	mov    rsi,rdi
    2794:	48 c1 ee 20          	shr    rsi,0x20
    2798:	40 88 72 04          	mov    BYTE PTR [rdx+0x4],sil
    279c:	48 89 fe             	mov    rsi,rdi
    279f:	48 c1 ee 18          	shr    rsi,0x18
    27a3:	40 88 72 03          	mov    BYTE PTR [rdx+0x3],sil
    27a7:	48 89 fe             	mov    rsi,rdi
    27aa:	48 c1 ee 10          	shr    rsi,0x10
    27ae:	40 88 72 02          	mov    BYTE PTR [rdx+0x2],sil
    27b2:	40 88 7a 00          	mov    BYTE PTR [rdx+0x0],dil
    27b6:	48 c1 ef 08          	shr    rdi,0x8
    27ba:	40 88 7a 01          	mov    BYTE PTR [rdx+0x1],dil
    27be:	b8 02 00 00 00       	mov    eax,0x2
    27c3:	41 5f                	pop    r15
    27c5:	41 5e                	pop    r14
    27c7:	41 5d                	pop    r13
    27c9:	5b                   	pop    rbx
    27ca:	c9                   	leave
    27cb:	c3                   	ret
    27cc:	cc                   	int3
