
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/rotate_dense.llvmbpf.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
       0:	f3 0f 1e fa          	endbr64
       4:	8b 07                	mov    eax,DWORD PTR [rdi]
       6:	8b 4f 04             	mov    ecx,DWORD PTR [rdi+0x4]
       9:	89 ca                	mov    edx,ecx
       b:	41 89 c2             	mov    r10d,eax
       e:	39 c8                	cmp    eax,ecx
      10:	0f 97 c0             	seta   al
      13:	49 8d 4a 08          	lea    rcx,[r10+0x8]
      17:	48 39 d1             	cmp    rcx,rdx
      1a:	0f 97 c1             	seta   cl
      1d:	08 c1                	or     cl,al
      1f:	49 8d 42 48          	lea    rax,[r10+0x48]
      23:	48 39 d0             	cmp    rax,rdx
      26:	0f 97 c0             	seta   al
      29:	08 c8                	or     al,cl
      2b:	74 03                	je     0x30
      2d:	31 c0                	xor    eax,eax
      2f:	c3                   	ret
      30:	55                   	push   rbp
      31:	41 57                	push   r15
      33:	41 56                	push   r14
      35:	41 55                	push   r13
      37:	41 54                	push   r12
      39:	53                   	push   rbx
      3a:	48 b8 61 72 65 6e 65 	movabs rax,0x6c7967656e657261
      41:	67 79 6c 
      44:	49 33 42 18          	xor    rax,QWORD PTR [r10+0x18]
      48:	48 ba 6d 6f 64 6e 61 	movabs rdx,0x646f72616e646f6d
      4f:	72 6f 64 
      52:	49 33 52 10          	xor    rdx,QWORD PTR [r10+0x10]
      56:	48 be 73 65 74 79 62 	movabs rsi,0x7465646279746573
      5d:	64 65 74 
      60:	49 33 72 20          	xor    rsi,QWORD PTR [r10+0x20]
      64:	48 8d 0c 06          	lea    rcx,[rsi+rax*1]
      68:	48 bd 44 e0 07 f8 1d 	movabs rbp,0x3ead971df807e044
      6f:	97 ad 3e 
      72:	48 31 e9             	xor    rcx,rbp
      75:	c4 e3 fb f0 c9 2f    	rorx   rcx,rcx,0x2f
      7b:	48 31 d1             	xor    rcx,rdx
      7e:	48 31 c2             	xor    rdx,rax
      81:	48 bf 15 7c 4a 7f b9 	movabs rdi,0x9e3779b97f4a7c15
      88:	79 37 9e 
      8b:	48 01 d7             	add    rdi,rdx
      8e:	c4 e3 fb f0 d7 33    	rorx   rdx,rdi,0x33
      94:	48 bf 75 65 73 70 65 	movabs rdi,0x736f6d6570736575
      9b:	6d 6f 73 
      9e:	49 33 7a 08          	xor    rdi,QWORD PTR [r10+0x8]
      a2:	48 01 d7             	add    rdi,rdx
      a5:	48 8d 14 39          	lea    rdx,[rcx+rdi*1]
      a9:	49 bc a2 a8 82 e9 e6 	movabs r12,0x7f99d1e6e982a8a2
      b0:	d1 99 7f 
      b3:	4c 31 e2             	xor    rdx,r12
      b6:	c4 e3 fb f0 d2 15    	rorx   rdx,rdx,0x15
      bc:	48 31 f2             	xor    rdx,rsi
      bf:	48 31 fe             	xor    rsi,rdi
      c2:	49 bd 73 44 c5 70 82 	movabs r13,0xdf23b48270c54473
      c9:	b4 23 df 
      cc:	4c 01 ee             	add    rsi,r13
      cf:	c4 63 fb f0 c6 23    	rorx   r8,rsi,0x23
      d5:	49 01 c0             	add    r8,rax
      d8:	4c 89 c0             	mov    rax,r8
      db:	48 31 c8             	xor    rax,rcx
      de:	49 bf d1 0c 40 62 4b 	movabs r15,0x200fef4b62400cd1
      e5:	ef 0f 20 
      e8:	4c 01 f8             	add    rax,r15
      eb:	c4 e3 fb f0 c0 35    	rorx   rax,rax,0x35
      f1:	4a 8d 34 02          	lea    rsi,[rdx+r8*1]
      f5:	49 be 00 71 fd da af 	movabs r14,0xc0860cafdafd7100
      fc:	0c 86 c0 
      ff:	4c 31 f6             	xor    rsi,r14
     102:	c4 63 fb f0 ce 2d    	rorx   r9,rsi,0x2d
     108:	49 31 c9             	xor    r9,rcx
     10b:	48 01 f8             	add    rax,rdi
     10e:	49 8d 0c 01          	lea    rcx,[r9+rax*1]
     112:	48 be 5e 39 78 cc 78 	movabs rsi,0x1724778cc78395e
     119:	47 72 01 
     11c:	48 31 f1             	xor    rcx,rsi
     11f:	c4 e3 fb f0 c9 11    	rorx   rcx,rcx,0x11
     125:	48 89 c6             	mov    rsi,rax
     128:	48 31 d6             	xor    rsi,rdx
     12b:	48 bf 2f d5 ba 53 14 	movabs rdi,0x60fc2a1453bad52f
     132:	2a fc 60 
     135:	48 01 fe             	add    rsi,rdi
     138:	c4 e3 fb f0 f6 21    	rorx   rsi,rsi,0x21
     13e:	48 31 d1             	xor    rcx,rdx
     141:	4c 01 c6             	add    rsi,r8
     144:	48 89 f7             	mov    rdi,rsi
     147:	4c 31 cf             	xor    rdi,r9
     14a:	48 8d 14 31          	lea    rdx,[rcx+rsi*1]
     14e:	49 b8 bc 01 f3 bd 41 	movabs r8,0x425e8241bdf301bc
     155:	82 5e 42 
     158:	4c 31 c2             	xor    rdx,r8
     15b:	c4 e3 fb f0 d2 29    	rorx   rdx,rdx,0x29
     161:	4c 31 ca             	xor    rdx,r9
     164:	49 b8 8d 9d 35 45 dd 	movabs r8,0xa1e864dd45359d8d
     16b:	64 e8 a1 
     16e:	4c 01 c7             	add    rdi,r8
     171:	c4 e3 fb f0 ff 39    	rorx   rdi,rdi,0x39
     177:	48 01 c7             	add    rdi,rax
     17a:	48 8d 04 3a          	lea    rax,[rdx+rdi*1]
     17e:	49 b8 1a ca 6d af 0a 	movabs r8,0x834abd0aaf6dca1a
     185:	bd 4a 83 
     188:	49 31 c0             	xor    r8,rax
     18b:	c4 c3 fb f0 c0 0b    	rorx   rax,r8,0xb
     191:	49 89 f8             	mov    r8,rdi
     194:	49 31 c8             	xor    r8,rcx
     197:	48 31 c8             	xor    rax,rcx
     19a:	48 b9 eb 65 b0 36 a6 	movabs rcx,0xe2d49fa636b065eb
     1a1:	9f d4 e2 
     1a4:	49 01 c8             	add    r8,rcx
     1a7:	c4 43 fb f0 c0 1b    	rorx   r8,r8,0x1b
     1ad:	49 01 f0             	add    r8,rsi
     1b0:	4c 89 c1             	mov    rcx,r8
     1b3:	48 31 d1             	xor    rcx,rdx
     1b6:	49 b9 49 2e 2b 28 6f 	movabs r9,0x23c0da6f282b2e49
     1bd:	da c0 23 
     1c0:	49 01 c9             	add    r9,rcx
     1c3:	4a 8d 0c 00          	lea    rcx,[rax+r8*1]
     1c7:	48 be 78 92 e8 a0 d3 	movabs rsi,0xc436f7d3a0e89278
     1ce:	f7 36 c4 
     1d1:	48 31 ce             	xor    rsi,rcx
     1d4:	c4 e3 fb f0 f6 25    	rorx   rsi,rsi,0x25
     1da:	48 31 d6             	xor    rsi,rdx
     1dd:	c4 c3 fb f0 d1 3b    	rorx   rdx,r9,0x3b
     1e3:	48 01 fa             	add    rdx,rdi
     1e6:	48 8d 0c 16          	lea    rcx,[rsi+rdx*1]
     1ea:	48 bf d6 5a 63 92 9c 	movabs rdi,0x523329c92635ad6
     1f1:	32 23 05 
     1f4:	48 31 cf             	xor    rdi,rcx
     1f7:	48 89 d1             	mov    rcx,rdx
     1fa:	48 31 c1             	xor    rcx,rax
     1fd:	49 b9 a7 f6 a5 19 38 	movabs r9,0x64ad153819a5f6a7
     204:	15 ad 64 
     207:	49 01 c9             	add    r9,rcx
     20a:	c4 e3 fb f0 cf 05    	rorx   rcx,rdi,0x5
     210:	48 31 c1             	xor    rcx,rax
     213:	c4 c3 fb f0 f9 17    	rorx   rdi,r9,0x17
     219:	4c 01 c7             	add    rdi,r8
     21c:	48 89 f8             	mov    rax,rdi
     21f:	48 31 f0             	xor    rax,rsi
     222:	49 b9 05 bf 20 0b 01 	movabs r9,0xa59950010b20bf05
     229:	50 99 a5 
     22c:	49 01 c1             	add    r9,rax
     22f:	48 8d 04 39          	lea    rax,[rcx+rdi*1]
     233:	49 b8 34 23 de 83 65 	movabs r8,0x460f6d6583de2334
     23a:	6d 0f 46 
     23d:	49 31 c0             	xor    r8,rax
     240:	c4 43 fb f0 c0 33    	rorx   r8,r8,0x33
     246:	49 31 f0             	xor    r8,rsi
     249:	c4 c3 fb f0 f1 3d    	rorx   rsi,r9,0x3d
     24f:	48 01 d6             	add    rsi,rdx
     252:	49 8d 04 30          	lea    rax,[r8+rsi*1]
     256:	48 ba 92 eb 58 75 2e 	movabs rdx,0x86fba82e7558eb92
     25d:	a8 fb 86 
     260:	48 31 c2             	xor    rdx,rax
     263:	48 89 f0             	mov    rax,rsi
     266:	48 31 c8             	xor    rax,rcx
     269:	49 b9 63 87 9b fc c9 	movabs r9,0xe6858ac9fc9b8763
     270:	8a 85 e6 
     273:	49 01 c1             	add    r9,rax
     276:	c4 e3 fb f0 c2 03    	rorx   rax,rdx,0x3
     27c:	48 31 c8             	xor    rax,rcx
     27f:	c4 c3 fb f0 d1 23    	rorx   rdx,r9,0x23
     285:	48 01 fa             	add    rdx,rdi
     288:	48 89 d1             	mov    rcx,rdx
     28b:	4c 31 c1             	xor    rcx,r8
     28e:	48 bf c1 4f 16 ee 92 	movabs rdi,0x2771c592ee164fc1
     295:	c5 71 27 
     298:	48 01 cf             	add    rdi,rcx
     29b:	48 8d 0c 10          	lea    rcx,[rax+rdx*1]
     29f:	49 b9 f0 b3 d3 66 f7 	movabs r9,0xc7e7e2f766d3b3f0
     2a6:	e2 e7 c7 
     2a9:	49 31 c9             	xor    r9,rcx
     2ac:	c4 43 fb f0 c9 21    	rorx   r9,r9,0x21
     2b2:	4d 31 c1             	xor    r9,r8
     2b5:	c4 e3 fb f0 ff 2f    	rorx   rdi,rdi,0x2f
     2bb:	48 01 f7             	add    rdi,rsi
     2be:	49 8d 0c 39          	lea    rcx,[r9+rdi*1]
     2c2:	48 be 4e 7c 4e 58 c0 	movabs rsi,0x8d41dc0584e7c4e
     2c9:	1d d4 08 
     2cc:	48 31 ce             	xor    rsi,rcx
     2cf:	48 89 f9             	mov    rcx,rdi
     2d2:	48 31 c1             	xor    rcx,rax
     2d5:	49 b8 1f 18 91 df 5b 	movabs r8,0x685e005bdf91181f
     2dc:	00 5e 68 
     2df:	49 01 c8             	add    r8,rcx
     2e2:	c4 e3 fb f0 ce 35    	rorx   rcx,rsi,0x35
     2e8:	48 31 c1             	xor    rcx,rax
     2eb:	c4 c3 fb f0 c0 15    	rorx   rax,r8,0x15
     2f1:	48 01 d0             	add    rax,rdx
     2f4:	48 89 c2             	mov    rdx,rax
     2f7:	4c 31 ca             	xor    rdx,r9
     2fa:	49 b8 7d e0 0b d1 24 	movabs r8,0xa94a3b24d10be07d
     301:	3b 4a a9 
     304:	49 01 d0             	add    r8,rdx
     307:	48 8d 14 01          	lea    rdx,[rcx+rax*1]
     30b:	48 be ac 44 c9 49 89 	movabs rsi,0x49c0588949c944ac
     312:	58 c0 49 
     315:	48 31 d6             	xor    rsi,rdx
     318:	c4 e3 fb f0 f6 1b    	rorx   rsi,rsi,0x1b
     31e:	4c 31 ce             	xor    rsi,r9
     321:	c4 43 fb f0 c0 2d    	rorx   r8,r8,0x2d
     327:	49 01 f8             	add    r8,rdi
     32a:	4a 8d 14 06          	lea    rdx,[rsi+r8*1]
     32e:	48 bf 0a 0d 44 3b 52 	movabs rdi,0x8aac93523b440d0a
     335:	93 ac 8a 
     338:	48 31 d7             	xor    rdi,rdx
     33b:	4c 89 c2             	mov    rdx,r8
     33e:	48 31 ca             	xor    rdx,rcx
     341:	49 b9 db a8 86 c2 ed 	movabs r9,0xea3675edc286a8db
     348:	75 36 ea 
     34b:	49 01 d1             	add    r9,rdx
     34e:	c4 e3 fb f0 ff 39    	rorx   rdi,rdi,0x39
     354:	48 31 cf             	xor    rdi,rcx
     357:	c4 c3 fb f0 c9 11    	rorx   rcx,r9,0x11
     35d:	48 01 c1             	add    rcx,rax
     360:	48 89 c8             	mov    rax,rcx
     363:	48 31 f0             	xor    rax,rsi
     366:	49 b9 39 71 01 b4 b6 	movabs r9,0x2b22b0b6b4017139
     36d:	b0 22 2b 
     370:	49 01 c1             	add    r9,rax
     373:	4d 8b 5a 38          	mov    r11,QWORD PTR [r10+0x38]
     377:	48 ba 04 57 15 48 64 	movabs rdx,0x9a0b956448155704
     37e:	95 0b 9a 
     381:	4c 31 da             	xor    rdx,r11
     384:	48 01 ca             	add    rdx,rcx
     387:	48 8d 04 0f          	lea    rax,[rdi+rcx*1]
     38b:	48 b9 68 d5 be 2c 1b 	movabs rcx,0xcb98ce1b2cbed568
     392:	ce 98 cb 
     395:	48 31 c1             	xor    rcx,rax
     398:	c4 e3 fb f0 c1 17    	rorx   rax,rcx,0x17
     39e:	48 31 f0             	xor    rax,rsi
     3a1:	c4 c3 fb f0 f1 29    	rorx   rsi,r9,0x29
     3a7:	4c 01 c6             	add    rsi,r8
     3aa:	48 8d 0c 30          	lea    rcx,[rax+rsi*1]
     3ae:	49 b8 c6 9d 39 1e e4 	movabs r8,0xc8508e41e399dc6
     3b5:	08 85 0c 
     3b8:	49 31 c8             	xor    r8,rcx
     3bb:	49 8b 5a 28          	mov    rbx,QWORD PTR [r10+0x28]
     3bf:	48 b9 c5 4d d5 56 9b 	movabs rcx,0x3a3e419b56d54dc5
     3c6:	41 3e 3a 
     3c9:	48 31 d9             	xor    rcx,rbx
     3cc:	48 01 f1             	add    rcx,rsi
     3cf:	48 31 fe             	xor    rsi,rdi
     3d2:	49 b9 97 39 7c a5 7f 	movabs r9,0x6c0eeb7fa57c3997
     3d9:	eb 0e 6c 
     3dc:	49 01 f1             	add    r9,rsi
     3df:	48 be 89 6c 4e ec 98 	movabs rsi,0x82efa98ec4e6c89
     3e6:	fa 2e 08 
     3e9:	4c 89 54 24 f8       	mov    QWORD PTR [rsp-0x8],r10
     3ee:	49 33 72 30          	xor    rsi,QWORD PTR [r10+0x30]
     3f2:	48 89 74 24 f0       	mov    QWORD PTR [rsp-0x10],rsi
     3f7:	48 01 f5             	add    rbp,rsi
     3fa:	48 31 c5             	xor    rbp,rax
     3fd:	c4 c3 fb f0 c1 0b    	rorx   rax,r9,0xb
     403:	48 01 c2             	add    rdx,rax
     406:	48 be 6c 0c e9 34 cf 	movabs rsi,0xbe5466cf34e90c6c
     40d:	66 54 be 
     410:	49 33 72 40          	xor    rsi,QWORD PTR [r10+0x40]
     414:	4a 8d 04 26          	lea    rax,[rsi+r12*1]
     418:	49 89 f2             	mov    r10,rsi
     41b:	48 89 74 24 e8       	mov    QWORD PTR [rsp-0x18],rsi
     420:	48 31 f8             	xor    rax,rdi
     423:	c4 c3 fb f0 f0 3b    	rorx   rsi,r8,0x3b
     429:	48 31 f0             	xor    rax,rsi
     42c:	48 8d 34 10          	lea    rsi,[rax+rdx*1]
     430:	48 bf 24 66 b4 0f ad 	movabs rdi,0x4d7143ad0fb46624
     437:	43 71 4d 
     43a:	48 31 f7             	xor    rdi,rsi
     43d:	c4 63 fb f0 c7 2f    	rorx   r8,rdi,0x2f
     443:	49 31 e8             	xor    r8,rbp
     446:	48 31 d5             	xor    rbp,rdx
     449:	48 be f5 01 f7 96 48 	movabs rsi,0xacfb264896f701f5
     450:	26 fb ac 
     453:	48 01 ee             	add    rsi,rbp
     456:	c4 e3 fb f0 f6 33    	rorx   rsi,rsi,0x33
     45c:	48 01 ce             	add    rsi,rcx
     45f:	49 8d 0c 30          	lea    rcx,[r8+rsi*1]
     463:	48 bf 82 2e 2f 01 76 	movabs rdi,0x8e5d7e76012f2e82
     46a:	7e 5d 8e 
     46d:	48 31 cf             	xor    rdi,rcx
     470:	48 89 f1             	mov    rcx,rsi
     473:	48 31 c1             	xor    rcx,rax
     476:	48 bd 53 ca 71 88 11 	movabs rbp,0xede761118871ca53
     47d:	61 e7 ed 
     480:	48 01 cd             	add    rbp,rcx
     483:	c4 e3 fb f0 cf 15    	rorx   rcx,rdi,0x15
     489:	48 31 c1             	xor    rcx,rax
     48c:	c4 e3 fb f0 fd 23    	rorx   rdi,rbp,0x23
     492:	48 01 d7             	add    rdi,rdx
     495:	48 89 f8             	mov    rax,rdi
     498:	4c 31 c0             	xor    rax,r8
     49b:	48 bd b1 92 ec 79 da 	movabs rbp,0x2ed39bda79ec92b1
     4a2:	9b d3 2e 
     4a5:	48 01 c5             	add    rbp,rax
     4a8:	48 8d 04 39          	lea    rax,[rcx+rdi*1]
     4ac:	48 ba e0 f6 a9 f2 3e 	movabs rdx,0xcf49b93ef2a9f6e0
     4b3:	b9 49 cf 
     4b6:	48 31 c2             	xor    rdx,rax
     4b9:	c4 e3 fb f0 d2 2d    	rorx   rdx,rdx,0x2d
     4bf:	4c 31 c2             	xor    rdx,r8
     4c2:	c4 e3 fb f0 ed 35    	rorx   rbp,rbp,0x35
     4c8:	48 01 f5             	add    rbp,rsi
     4cb:	48 8d 04 2a          	lea    rax,[rdx+rbp*1]
     4cf:	48 be 3e bf 24 e4 07 	movabs rsi,0x1035f407e424bf3e
     4d6:	f4 35 10 
     4d9:	48 31 c6             	xor    rsi,rax
     4dc:	48 89 e8             	mov    rax,rbp
     4df:	48 31 c8             	xor    rax,rcx
     4e2:	49 b8 0f 5b 67 6b a3 	movabs r8,0x6fbfd6a36b675b0f
     4e9:	d6 bf 6f 
     4ec:	49 01 c0             	add    r8,rax
     4ef:	c4 e3 fb f0 c6 11    	rorx   rax,rsi,0x11
     4f5:	48 31 c8             	xor    rax,rcx
     4f8:	c4 c3 fb f0 f0 21    	rorx   rsi,r8,0x21
     4fe:	48 01 fe             	add    rsi,rdi
     501:	48 89 f1             	mov    rcx,rsi
     504:	48 31 d1             	xor    rcx,rdx
     507:	49 b8 6d 23 e2 5c 6c 	movabs r8,0xb0ac116c5ce2236d
     50e:	11 ac b0 
     511:	49 01 c8             	add    r8,rcx
     514:	48 8d 0c 30          	lea    rcx,[rax+rsi*1]
     518:	48 bf 9c 87 9f d5 d0 	movabs rdi,0x51222ed0d59f879c
     51f:	2e 22 51 
     522:	48 31 cf             	xor    rdi,rcx
     525:	c4 e3 fb f0 ff 29    	rorx   rdi,rdi,0x29
     52b:	48 31 d7             	xor    rdi,rdx
     52e:	c4 c3 fb f0 d0 39    	rorx   rdx,r8,0x39
     534:	48 01 ea             	add    rdx,rbp
     537:	48 8d 0c 17          	lea    rcx,[rdi+rdx*1]
     53b:	49 b8 fa 4f 1a c7 99 	movabs r8,0x920e6999c71a4ffa
     542:	69 0e 92 
     545:	49 31 c8             	xor    r8,rcx
     548:	48 89 d1             	mov    rcx,rdx
     54b:	48 31 c1             	xor    rcx,rax
     54e:	48 bd cb eb 5c 4e 35 	movabs rbp,0xf1984c354e5cebcb
     555:	4c 98 f1 
     558:	48 01 cd             	add    rbp,rcx
     55b:	c4 c3 fb f0 c8 0b    	rorx   rcx,r8,0xb
     561:	48 31 c1             	xor    rcx,rax
     564:	c4 e3 fb f0 ed 1b    	rorx   rbp,rbp,0x1b
     56a:	48 01 f5             	add    rbp,rsi
     56d:	48 89 e8             	mov    rax,rbp
     570:	48 31 f8             	xor    rax,rdi
     573:	49 b8 29 b4 d7 3f fe 	movabs r8,0x328486fe3fd7b429
     57a:	86 84 32 
     57d:	49 01 c0             	add    r8,rax
     580:	48 8d 04 29          	lea    rax,[rcx+rbp*1]
     584:	48 be 58 18 95 b8 62 	movabs rsi,0xd2faa462b8951858
     58b:	a4 fa d2 
     58e:	48 31 c6             	xor    rsi,rax
     591:	c4 e3 fb f0 f6 25    	rorx   rsi,rsi,0x25
     597:	48 31 fe             	xor    rsi,rdi
     59a:	c4 c3 fb f0 f8 3b    	rorx   rdi,r8,0x3b
     5a0:	48 01 d7             	add    rdi,rdx
     5a3:	48 8d 04 3e          	lea    rax,[rsi+rdi*1]
     5a7:	48 ba b6 e0 0f aa 2b 	movabs rdx,0x13e6df2baa0fe0b6
     5ae:	df e6 13 
     5b1:	48 31 c2             	xor    rdx,rax
     5b4:	48 89 f8             	mov    rax,rdi
     5b7:	48 31 c8             	xor    rax,rcx
     5ba:	49 b8 87 7c 52 31 c7 	movabs r8,0x7370c1c731527c87
     5c1:	c1 70 73 
     5c4:	49 01 c0             	add    r8,rax
     5c7:	c4 e3 fb f0 c2 05    	rorx   rax,rdx,0x5
     5cd:	48 31 c8             	xor    rax,rcx
     5d0:	c4 c3 fb f0 d0 17    	rorx   rdx,r8,0x17
     5d6:	48 01 ea             	add    rdx,rbp
     5d9:	48 89 d1             	mov    rcx,rdx
     5dc:	48 31 f1             	xor    rcx,rsi
     5df:	49 b8 e5 44 cd 22 90 	movabs r8,0xb45cfc9022cd44e5
     5e6:	fc 5c b4 
     5e9:	49 01 c8             	add    r8,rcx
     5ec:	48 8d 0c 10          	lea    rcx,[rax+rdx*1]
     5f0:	48 bd 14 a9 8a 9b f4 	movabs rbp,0x54d319f49b8aa914
     5f7:	19 d3 54 
     5fa:	48 31 cd             	xor    rbp,rcx
     5fd:	c4 e3 fb f0 ed 33    	rorx   rbp,rbp,0x33
     603:	48 31 f5             	xor    rbp,rsi
     606:	c4 c3 fb f0 f0 3d    	rorx   rsi,r8,0x3d
     60c:	48 01 fe             	add    rsi,rdi
     60f:	48 8d 0c 2e          	lea    rcx,[rsi+rbp*1]
     613:	48 bf 72 71 05 8d bd 	movabs rdi,0x95bf54bd8d057172
     61a:	54 bf 95 
     61d:	48 31 cf             	xor    rdi,rcx
     620:	48 89 f1             	mov    rcx,rsi
     623:	48 31 c1             	xor    rcx,rax
     626:	49 b8 43 0d 48 14 59 	movabs r8,0xf549375914480d43
     62d:	37 49 f5 
     630:	49 01 c8             	add    r8,rcx
     633:	c4 e3 fb f0 cf 03    	rorx   rcx,rdi,0x3
     639:	48 31 c1             	xor    rcx,rax
     63c:	c4 c3 fb f0 f8 23    	rorx   rdi,r8,0x23
     642:	48 01 d7             	add    rdi,rdx
     645:	48 89 f8             	mov    rax,rdi
     648:	48 31 e8             	xor    rax,rbp
     64b:	49 b8 a1 d5 c2 05 22 	movabs r8,0x3635722205c2d5a1
     652:	72 35 36 
     655:	49 01 c0             	add    r8,rax
     658:	48 8d 04 39          	lea    rax,[rcx+rdi*1]
     65c:	48 ba d0 39 80 7e 86 	movabs rdx,0xd6ab8f867e8039d0
     663:	8f ab d6 
     666:	48 31 c2             	xor    rdx,rax
     669:	c4 e3 fb f0 d2 21    	rorx   rdx,rdx,0x21
     66f:	48 31 ea             	xor    rdx,rbp
     672:	c4 c3 fb f0 c0 2f    	rorx   rax,r8,0x2f
     678:	48 01 f0             	add    rax,rsi
     67b:	48 8d 34 02          	lea    rsi,[rdx+rax*1]
     67f:	49 b8 2e 02 fb 6f 4f 	movabs r8,0x1797ca4f6ffb022e
     686:	ca 97 17 
     689:	49 31 f0             	xor    r8,rsi
     68c:	48 89 c6             	mov    rsi,rax
     68f:	48 31 ce             	xor    rsi,rcx
     692:	48 bd ff 9d 3d f7 ea 	movabs rbp,0x7721aceaf73d9dff
     699:	ac 21 77 
     69c:	48 01 f5             	add    rbp,rsi
     69f:	c4 c3 fb f0 f0 35    	rorx   rsi,r8,0x35
     6a5:	48 31 ce             	xor    rsi,rcx
     6a8:	c4 e3 fb f0 cd 15    	rorx   rcx,rbp,0x15
     6ae:	48 01 f9             	add    rcx,rdi
     6b1:	48 89 cf             	mov    rdi,rcx
     6b4:	48 31 d7             	xor    rdi,rdx
     6b7:	49 b8 5d 66 b8 e8 b3 	movabs r8,0xb80de7b3e8b8665d
     6be:	e7 0d b8 
     6c1:	49 01 f8             	add    r8,rdi
     6c4:	48 8d 3c 0e          	lea    rdi,[rsi+rcx*1]
     6c8:	48 bd 8c ca 75 61 18 	movabs rbp,0x588405186175ca8c
     6cf:	05 84 58 
     6d2:	48 31 fd             	xor    rbp,rdi
     6d5:	c4 e3 fb f0 ed 1b    	rorx   rbp,rbp,0x1b
     6db:	48 31 d5             	xor    rbp,rdx
     6de:	c4 c3 fb f0 f8 2d    	rorx   rdi,r8,0x2d
     6e4:	48 01 c7             	add    rdi,rax
     6e7:	48 8d 04 2f          	lea    rax,[rdi+rbp*1]
     6eb:	48 ba ea 92 f0 52 e1 	movabs rdx,0x99703fe152f092ea
     6f2:	3f 70 99 
     6f5:	48 31 c2             	xor    rdx,rax
     6f8:	48 89 f8             	mov    rax,rdi
     6fb:	48 31 f0             	xor    rax,rsi
     6fe:	49 b8 bb 2e 33 da 7c 	movabs r8,0xf8fa227cda332ebb
     705:	22 fa f8 
     708:	49 01 c0             	add    r8,rax
     70b:	c4 e3 fb f0 d2 39    	rorx   rdx,rdx,0x39
     711:	48 31 f2             	xor    rdx,rsi
     714:	c4 c3 fb f0 f0 11    	rorx   rsi,r8,0x11
     71a:	48 01 ce             	add    rsi,rcx
     71d:	48 89 f0             	mov    rax,rsi
     720:	48 31 e8             	xor    rax,rbp
     723:	48 b9 19 f7 ad cb 45 	movabs rcx,0x39e65d45cbadf719
     72a:	5d e6 39 
     72d:	48 01 c1             	add    rcx,rax
     730:	48 b8 d5 bb 52 d1 00 	movabs rax,0x3ab1f000d152bbd5
     737:	f0 b1 3a 
     73a:	4c 31 d8             	xor    rax,r11
     73d:	48 01 f0             	add    rax,rsi
     740:	48 01 d6             	add    rsi,rdx
     743:	49 b8 48 5b 6b 44 aa 	movabs r8,0xda5c7aaa446b5b48
     74a:	7a 5c da 
     74d:	49 31 f0             	xor    r8,rsi
     750:	c4 c3 fb f0 f0 17    	rorx   rsi,r8,0x17
     756:	48 31 ee             	xor    rsi,rbp
     759:	c4 e3 fb f0 c9 29    	rorx   rcx,rcx,0x29
     75f:	48 01 f9             	add    rcx,rdi
     762:	48 8d 3c 0e          	lea    rdi,[rsi+rcx*1]
     766:	48 bd a6 23 e6 35 73 	movabs rbp,0x1b48b57335e623a6
     76d:	b5 48 1b 
     770:	48 31 fd             	xor    rbp,rdi
     773:	49 b8 94 d1 98 d1 3f 	movabs r8,0x9aa4af3fd198d194
     77a:	af a4 9a 
     77d:	49 31 d8             	xor    r8,rbx
     780:	49 01 c8             	add    r8,rcx
     783:	48 31 d1             	xor    rcx,rdx
     786:	48 bf 77 bf 28 bd 0e 	movabs rdi,0x7ad2980ebd28bf77
     78d:	98 d2 7a 
     790:	48 01 cf             	add    rdi,rcx
     793:	4c 8b 4c 24 f0       	mov    r9,QWORD PTR [rsp-0x10]
     798:	4d 01 cd             	add    r13,r9
     79b:	49 31 f5             	xor    r13,rsi
     79e:	c4 e3 fb f0 cf 0b    	rorx   rcx,rdi,0xb
     7a4:	48 01 c8             	add    rax,rcx
     7a7:	4b 8d 3c 3a          	lea    rdi,[r10+r15*1]
     7ab:	48 31 d7             	xor    rdi,rdx
     7ae:	c4 e3 fb f0 cd 3b    	rorx   rcx,rbp,0x3b
     7b4:	48 31 cf             	xor    rdi,rcx
     7b7:	48 8d 0c 07          	lea    rcx,[rdi+rax*1]
     7bb:	48 ba 04 ec 60 27 3c 	movabs rdx,0x5c34f03c2760ec04
     7c2:	f0 34 5c 
     7c5:	48 31 ca             	xor    rdx,rcx
     7c8:	c4 e3 fb f0 ca 2f    	rorx   rcx,rdx,0x2f
     7ce:	4c 31 e9             	xor    rcx,r13
     7d1:	49 31 c5             	xor    r13,rax
     7d4:	48 ba d5 87 a3 ae d7 	movabs rdx,0xbbbed2d7aea387d5
     7db:	d2 be bb 
     7de:	4c 01 ea             	add    rdx,r13
     7e1:	c4 e3 fb f0 f2 33    	rorx   rsi,rdx,0x33
     7e7:	4c 01 c6             	add    rsi,r8
     7ea:	48 8d 14 31          	lea    rdx,[rcx+rsi*1]
     7ee:	49 b8 62 b4 db 18 05 	movabs r8,0x9d212b0518dbb462
     7f5:	2b 21 9d 
     7f8:	49 31 d0             	xor    r8,rdx
     7fb:	48 89 f2             	mov    rdx,rsi
     7fe:	48 31 fa             	xor    rdx,rdi
     801:	49 bd 33 50 1e a0 a0 	movabs r13,0xfcab0da0a01e5033
     808:	0d ab fc 
     80b:	49 01 d5             	add    r13,rdx
     80e:	c4 c3 fb f0 d0 15    	rorx   rdx,r8,0x15
     814:	48 31 fa             	xor    rdx,rdi
     817:	c4 c3 fb f0 fd 23    	rorx   rdi,r13,0x23
     81d:	48 01 c7             	add    rdi,rax
     820:	48 89 f8             	mov    rax,rdi
     823:	48 31 c8             	xor    rax,rcx
     826:	49 b8 91 18 99 91 69 	movabs r8,0x3d97486991991891
     82d:	48 97 3d 
     830:	49 01 c0             	add    r8,rax
     833:	48 8d 04 3a          	lea    rax,[rdx+rdi*1]
     837:	49 bd c0 7c 56 0a ce 	movabs r13,0xde0d65ce0a567cc0
     83e:	65 0d de 
     841:	49 31 c5             	xor    r13,rax
     844:	c4 43 fb f0 ed 2d    	rorx   r13,r13,0x2d
     84a:	49 31 cd             	xor    r13,rcx
     84d:	c4 c3 fb f0 c8 35    	rorx   rcx,r8,0x35
     853:	48 01 f1             	add    rcx,rsi
     856:	4a 8d 04 29          	lea    rax,[rcx+r13*1]
     85a:	48 be 1e 45 d1 fb 96 	movabs rsi,0x1ef9a096fbd1451e
     861:	a0 f9 1e 
     864:	48 31 c6             	xor    rsi,rax
     867:	48 89 c8             	mov    rax,rcx
     86a:	48 31 d0             	xor    rax,rdx
     86d:	49 b8 ef e0 13 83 32 	movabs r8,0x7e8383328313e0ef
     874:	83 83 7e 
     877:	49 01 c0             	add    r8,rax
     87a:	c4 e3 fb f0 c6 11    	rorx   rax,rsi,0x11
     880:	48 31 d0             	xor    rax,rdx
     883:	c4 c3 fb f0 d0 21    	rorx   rdx,r8,0x21
     889:	48 01 fa             	add    rdx,rdi
     88c:	48 89 d6             	mov    rsi,rdx
     88f:	4c 31 ee             	xor    rsi,r13
     892:	48 bf 4d a9 8e 74 fb 	movabs rdi,0xbf6fbdfb748ea94d
     899:	bd 6f bf 
     89c:	48 01 f7             	add    rdi,rsi
     89f:	48 8d 34 10          	lea    rsi,[rax+rdx*1]
     8a3:	49 b8 7c 0d 4c ed 5f 	movabs r8,0x5fe5db5fed4c0d7c
     8aa:	db e5 5f 
     8ad:	49 31 f0             	xor    r8,rsi
     8b0:	c4 c3 fb f0 f0 29    	rorx   rsi,r8,0x29
     8b6:	4c 31 ee             	xor    rsi,r13
     8b9:	c4 e3 fb f0 ff 39    	rorx   rdi,rdi,0x39
     8bf:	48 01 cf             	add    rdi,rcx
     8c2:	48 8d 0c 3e          	lea    rcx,[rsi+rdi*1]
     8c6:	49 b8 da d5 c6 de 28 	movabs r8,0xa0d21628dec6d5da
     8cd:	16 d2 a0 
     8d0:	49 31 c8             	xor    r8,rcx
     8d3:	48 89 f9             	mov    rcx,rdi
     8d6:	48 31 c1             	xor    rcx,rax
     8d9:	49 bd ab 71 09 66 c4 	movabs r13,0x5bf8c4660971ab
     8e0:	f8 5b 00 
     8e3:	49 01 cd             	add    r13,rcx
     8e6:	c4 c3 fb f0 c8 0b    	rorx   rcx,r8,0xb
     8ec:	48 31 c1             	xor    rcx,rax
     8ef:	c4 43 fb f0 ed 1b    	rorx   r13,r13,0x1b
     8f5:	49 01 d5             	add    r13,rdx
     8f8:	4c 89 e8             	mov    rax,r13
     8fb:	48 31 f0             	xor    rax,rsi
     8fe:	49 b8 09 3a 84 57 8d 	movabs r8,0x4148338d57843a09
     905:	33 48 41 
     908:	49 01 c0             	add    r8,rax
     90b:	4a 8d 04 29          	lea    rax,[rcx+r13*1]
     90f:	48 ba 38 9e 41 d0 f1 	movabs rdx,0xe1be50f1d0419e38
     916:	50 be e1 
     919:	48 31 c2             	xor    rdx,rax
     91c:	c4 e3 fb f0 d2 25    	rorx   rdx,rdx,0x25
     922:	48 31 f2             	xor    rdx,rsi
     925:	c4 c3 fb f0 f0 3b    	rorx   rsi,r8,0x3b
     92b:	48 01 fe             	add    rsi,rdi
     92e:	48 8d 04 32          	lea    rax,[rdx+rsi*1]
     932:	48 bf 96 66 bc c1 ba 	movabs rdi,0x22aa8bbac1bc6696
     939:	8b aa 22 
     93c:	48 31 c7             	xor    rdi,rax
     93f:	48 89 f0             	mov    rax,rsi
     942:	48 31 c8             	xor    rax,rcx
     945:	49 b8 67 02 ff 48 56 	movabs r8,0x82346e5648ff0267
     94c:	6e 34 82 
     94f:	49 01 c0             	add    r8,rax
     952:	c4 e3 fb f0 c7 05    	rorx   rax,rdi,0x5
     958:	48 31 c8             	xor    rax,rcx
     95b:	c4 c3 fb f0 f8 17    	rorx   rdi,r8,0x17
     961:	4c 01 ef             	add    rdi,r13
     964:	48 89 f9             	mov    rcx,rdi
     967:	48 31 d1             	xor    rcx,rdx
     96a:	49 b8 c5 ca 79 3a 1f 	movabs r8,0xc320a91f3a79cac5
     971:	a9 20 c3 
     974:	49 01 c8             	add    r8,rcx
     977:	48 8d 0c 38          	lea    rcx,[rax+rdi*1]
     97b:	49 bd f4 2e 37 b3 83 	movabs r13,0x6396c683b3372ef4
     982:	c6 96 63 
     985:	49 31 cd             	xor    r13,rcx
     988:	c4 43 fb f0 ed 33    	rorx   r13,r13,0x33
     98e:	49 31 d5             	xor    r13,rdx
     991:	c4 c3 fb f0 d0 3d    	rorx   rdx,r8,0x3d
     997:	48 01 f2             	add    rdx,rsi
     99a:	4a 8d 0c 2a          	lea    rcx,[rdx+r13*1]
     99e:	48 be 52 f7 b1 a4 4c 	movabs rsi,0xa483014ca4b1f752
     9a5:	01 83 a4 
     9a8:	48 31 ce             	xor    rsi,rcx
     9ab:	48 89 d1             	mov    rcx,rdx
     9ae:	48 31 c1             	xor    rcx,rax
     9b1:	49 b8 23 93 f4 2b e8 	movabs r8,0x40ce3e82bf49323
     9b8:	e3 0c 04 
     9bb:	49 01 c8             	add    r8,rcx
     9be:	c4 e3 fb f0 ce 03    	rorx   rcx,rsi,0x3
     9c4:	48 31 c1             	xor    rcx,rax
     9c7:	c4 c3 fb f0 f0 23    	rorx   rsi,r8,0x23
     9cd:	48 01 fe             	add    rsi,rdi
     9d0:	48 89 f0             	mov    rax,rsi
     9d3:	4c 31 e8             	xor    rax,r13
     9d6:	49 b8 81 5b 6f 1d b1 	movabs r8,0x44f91eb11d6f5b81
     9dd:	1e f9 44 
     9e0:	49 01 c0             	add    r8,rax
     9e3:	48 8d 04 31          	lea    rax,[rcx+rsi*1]
     9e7:	48 bf b0 bf 2c 96 15 	movabs rdi,0xe56f3c15962cbfb0
     9ee:	3c 6f e5 
     9f1:	48 31 c7             	xor    rdi,rax
     9f4:	c4 e3 fb f0 ff 21    	rorx   rdi,rdi,0x21
     9fa:	4c 31 ef             	xor    rdi,r13
     9fd:	c4 c3 fb f0 e8 2f    	rorx   rbp,r8,0x2f
     a03:	48 01 d5             	add    rbp,rdx
     a06:	48 8d 04 2f          	lea    rax,[rdi+rbp*1]
     a0a:	48 ba 0e 88 a7 87 de 	movabs rdx,0x265b76de87a7880e
     a11:	76 5b 26 
     a14:	48 31 c2             	xor    rdx,rax
     a17:	48 89 e8             	mov    rax,rbp
     a1a:	48 31 c8             	xor    rax,rcx
     a1d:	49 b8 df 23 ea 0e 7a 	movabs r8,0x85e5597a0eea23df
     a24:	59 e5 85 
     a27:	49 01 c0             	add    r8,rax
     a2a:	c4 e3 fb f0 c2 35    	rorx   rax,rdx,0x35
     a30:	48 31 c8             	xor    rax,rcx
     a33:	c4 c3 fb f0 d0 15    	rorx   rdx,r8,0x15
     a39:	48 01 f2             	add    rdx,rsi
     a3c:	48 89 d1             	mov    rcx,rdx
     a3f:	48 31 f9             	xor    rcx,rdi
     a42:	48 be 3d ec 64 00 43 	movabs rsi,0xc6d194430064ec3d
     a49:	94 d1 c6 
     a4c:	48 01 ce             	add    rsi,rcx
     a4f:	48 8d 0c 10          	lea    rcx,[rax+rdx*1]
     a53:	49 b8 6c 50 22 79 a7 	movabs r8,0x6747b1a77922506c
     a5a:	b1 47 67 
     a5d:	49 31 c8             	xor    r8,rcx
     a60:	c4 43 fb f0 e8 1b    	rorx   r13,r8,0x1b
     a66:	49 31 fd             	xor    r13,rdi
     a69:	c4 e3 fb f0 ce 2d    	rorx   rcx,rsi,0x2d
     a6f:	48 01 e9             	add    rcx,rbp
     a72:	4a 8d 34 29          	lea    rsi,[rcx+r13*1]
     a76:	48 bf ca 18 9d 6a 70 	movabs rdi,0xa833ec706a9d18ca
     a7d:	ec 33 a8 
     a80:	48 31 f7             	xor    rdi,rsi
     a83:	48 89 ce             	mov    rsi,rcx
     a86:	48 31 c6             	xor    rsi,rax
     a89:	49 b8 9b b4 df f1 0b 	movabs r8,0x7bdcf0bf1dfb49b
     a90:	cf bd 07 
     a93:	49 01 f0             	add    r8,rsi
     a96:	c4 e3 fb f0 ef 39    	rorx   rbp,rdi,0x39
     a9c:	48 31 c5             	xor    rbp,rax
     a9f:	c4 c3 fb f0 f0 11    	rorx   rsi,r8,0x11
     aa5:	48 01 d6             	add    rsi,rdx
     aa8:	48 89 f0             	mov    rax,rsi
     aab:	4c 31 e8             	xor    rax,r13
     aae:	48 bf f9 7c 5a e3 d4 	movabs rdi,0x48aa09d4e35a7cf9
     ab5:	09 aa 48 
     ab8:	48 01 c7             	add    rdi,rax
     abb:	48 b8 a6 1f 90 5a ad 	movabs rax,0x6527cead5a901fa6
     ac2:	ce 27 65 
     ac5:	4c 31 d8             	xor    rax,r11
     ac8:	4d 89 da             	mov    r10,r11
     acb:	48 01 f0             	add    rax,rsi
     ace:	48 8d 14 2e          	lea    rdx,[rsi+rbp*1]
     ad2:	48 be 28 e1 17 5c 39 	movabs rsi,0xe92027395c17e128
     ad9:	27 20 e9 
     adc:	48 31 d6             	xor    rsi,rdx
     adf:	c4 e3 fb f0 f6 17    	rorx   rsi,rsi,0x17
     ae5:	4c 31 ee             	xor    rsi,r13
     ae8:	c4 e3 fb f0 ff 29    	rorx   rdi,rdi,0x29
     aee:	48 01 cf             	add    rdi,rcx
     af1:	48 8d 0c 3e          	lea    rcx,[rsi+rdi*1]
     af5:	49 b8 86 a9 92 4d 02 	movabs r8,0x2a0c62024d92a986
     afc:	62 0c 2a 
     aff:	49 31 c8             	xor    r8,rcx
     b02:	48 ba a3 75 5a 59 a0 	movabs rdx,0x7b2a8ca0595a75a3
     b09:	8c 2a 7b 
     b0c:	48 31 da             	xor    rdx,rbx
     b0f:	48 01 fa             	add    rdx,rdi
     b12:	48 31 ef             	xor    rdi,rbp
     b15:	48 b9 57 45 d5 d4 9d 	movabs rcx,0x8996449dd4d54557
     b1c:	44 96 89 
     b1f:	48 01 f9             	add    rcx,rdi
     b22:	4d 89 cb             	mov    r11,r9
     b25:	4d 01 cc             	add    r12,r9
     b28:	49 31 f4             	xor    r12,rsi
     b2b:	c4 e3 fb f0 c9 0b    	rorx   rcx,rcx,0xb
     b31:	48 01 c8             	add    rax,rcx
     b34:	4c 8b 4c 24 e8       	mov    r9,QWORD PTR [rsp-0x18]
     b39:	4b 8d 3c 31          	lea    rdi,[r9+r14*1]
     b3d:	48 31 ef             	xor    rdi,rbp
     b40:	c4 c3 fb f0 c8 3b    	rorx   rcx,r8,0x3b
     b46:	48 31 cf             	xor    rdi,rcx
     b49:	48 8d 0c 07          	lea    rcx,[rdi+rax*1]
     b4d:	48 be e4 71 0d 3f cb 	movabs rsi,0x6af89ccb3f0d71e4
     b54:	9c f8 6a 
     b57:	48 31 ce             	xor    rsi,rcx
     b5a:	c4 e3 fb f0 ce 2f    	rorx   rcx,rsi,0x2f
     b60:	4c 31 e1             	xor    rcx,r12
     b63:	49 31 c4             	xor    r12,rax
     b66:	48 be b5 0d 50 c6 66 	movabs rsi,0xca827f66c6500db5
     b6d:	7f 82 ca 
     b70:	4c 01 e6             	add    rsi,r12
     b73:	c4 e3 fb f0 f6 33    	rorx   rsi,rsi,0x33
     b79:	48 01 d6             	add    rsi,rdx
     b7c:	48 8d 14 31          	lea    rdx,[rcx+rsi*1]
     b80:	49 b8 42 3a 88 30 94 	movabs r8,0xabe4d79430883a42
     b87:	d7 e4 ab 
     b8a:	49 31 d0             	xor    r8,rdx
     b8d:	48 89 f2             	mov    rdx,rsi
     b90:	48 31 fa             	xor    rdx,rdi
     b93:	49 bc 13 d6 ca b7 2f 	movabs r12,0xb6eba2fb7cad613
     b9a:	ba 6e 0b 
     b9d:	49 01 d4             	add    r12,rdx
     ba0:	c4 c3 fb f0 d0 15    	rorx   rdx,r8,0x15
     ba6:	48 31 fa             	xor    rdx,rdi
     ba9:	c4 c3 fb f0 fc 23    	rorx   rdi,r12,0x23
     baf:	48 01 c7             	add    rdi,rax
     bb2:	48 89 f8             	mov    rax,rdi
     bb5:	48 31 c8             	xor    rax,rcx
     bb8:	49 b8 71 9e 45 a9 f8 	movabs r8,0x4c5af4f8a9459e71
     bbf:	f4 5a 4c 
     bc2:	49 01 c0             	add    r8,rax
     bc5:	48 8d 04 3a          	lea    rax,[rdx+rdi*1]
     bc9:	49 bc a0 02 03 22 5d 	movabs r12,0xecd1125d220302a0
     bd0:	12 d1 ec 
     bd3:	49 31 c4             	xor    r12,rax
     bd6:	c4 43 fb f0 e4 2d    	rorx   r12,r12,0x2d
     bdc:	49 31 cc             	xor    r12,rcx
     bdf:	c4 c3 fb f0 c8 35    	rorx   rcx,r8,0x35
     be5:	48 01 f1             	add    rcx,rsi
     be8:	49 8d 04 0c          	lea    rax,[r12+rcx*1]
     bec:	48 be fe ca 7d 13 26 	movabs rsi,0x2dbd4d26137dcafe
     bf3:	4d bd 2d 
     bf6:	48 31 c6             	xor    rsi,rax
     bf9:	48 89 c8             	mov    rax,rcx
     bfc:	48 31 d0             	xor    rax,rdx
     bff:	49 b8 cf 66 c0 9a c1 	movabs r8,0x8d472fc19ac066cf
     c06:	2f 47 8d 
     c09:	49 01 c0             	add    r8,rax
     c0c:	c4 e3 fb f0 c6 11    	rorx   rax,rsi,0x11
     c12:	48 31 d0             	xor    rax,rdx
     c15:	c4 c3 fb f0 d0 21    	rorx   rdx,r8,0x21
     c1b:	48 01 fa             	add    rdx,rdi
     c1e:	48 89 d6             	mov    rsi,rdx
     c21:	4c 31 e6             	xor    rsi,r12
     c24:	48 bf 2d 2f 3b 8c 8a 	movabs rdi,0xce336a8a8c3b2f2d
     c2b:	6a 33 ce 
     c2e:	48 01 f7             	add    rdi,rsi
     c31:	48 8d 34 10          	lea    rsi,[rax+rdx*1]
     c35:	49 b8 5c 93 f8 04 ef 	movabs r8,0x6ea987ef04f8935c
     c3c:	87 a9 6e 
     c3f:	49 31 f0             	xor    r8,rsi
     c42:	c4 c3 fb f0 f0 29    	rorx   rsi,r8,0x29
     c48:	4c 31 e6             	xor    rsi,r12
     c4b:	c4 e3 fb f0 ff 39    	rorx   rdi,rdi,0x39
     c51:	48 01 cf             	add    rdi,rcx
     c54:	48 8d 0c 3e          	lea    rcx,[rsi+rdi*1]
     c58:	49 b8 ba 5b 73 f6 b7 	movabs r8,0xaf95c2b7f6735bba
     c5f:	c2 95 af 
     c62:	49 31 c8             	xor    r8,rcx
     c65:	48 89 f9             	mov    rcx,rdi
     c68:	48 31 c1             	xor    rcx,rax
     c6b:	49 bc 8b f7 b5 7d 53 	movabs r12,0xf1fa5537db5f78b
     c72:	a5 1f 0f 
     c75:	49 01 cc             	add    r12,rcx
     c78:	c4 c3 fb f0 c8 0b    	rorx   rcx,r8,0xb
     c7e:	48 31 c1             	xor    rcx,rax
     c81:	c4 43 fb f0 e4 1b    	rorx   r12,r12,0x1b
     c87:	49 01 d4             	add    r12,rdx
     c8a:	4c 89 e0             	mov    rax,r12
     c8d:	48 31 f0             	xor    rax,rsi
     c90:	49 b8 e9 bf 30 6f 1c 	movabs r8,0x500be01c6f30bfe9
     c97:	e0 0b 50 
     c9a:	49 01 c0             	add    r8,rax
     c9d:	4a 8d 04 21          	lea    rax,[rcx+r12*1]
     ca1:	48 ba 18 24 ee e7 80 	movabs rdx,0xf081fd80e7ee2418
     ca8:	fd 81 f0 
     cab:	48 31 c2             	xor    rdx,rax
     cae:	c4 e3 fb f0 d2 25    	rorx   rdx,rdx,0x25
     cb4:	48 31 f2             	xor    rdx,rsi
     cb7:	c4 c3 fb f0 f0 3b    	rorx   rsi,r8,0x3b
     cbd:	48 01 fe             	add    rsi,rdi
     cc0:	48 8d 04 32          	lea    rax,[rdx+rsi*1]
     cc4:	48 bf 76 ec 68 d9 49 	movabs rdi,0x316e3849d968ec76
     ccb:	38 6e 31 
     cce:	48 31 c7             	xor    rdi,rax
     cd1:	48 89 f0             	mov    rax,rsi
     cd4:	48 31 c8             	xor    rax,rcx
     cd7:	49 b8 47 88 ab 60 e5 	movabs r8,0x90f81ae560ab8847
     cde:	1a f8 90 
     ce1:	49 01 c0             	add    r8,rax
     ce4:	c4 e3 fb f0 c7 05    	rorx   rax,rdi,0x5
     cea:	48 31 c8             	xor    rax,rcx
     ced:	c4 c3 fb f0 f8 17    	rorx   rdi,r8,0x17
     cf3:	4c 01 e7             	add    rdi,r12
     cf6:	48 89 f9             	mov    rcx,rdi
     cf9:	48 31 d1             	xor    rcx,rdx
     cfc:	49 b8 a5 50 26 52 ae 	movabs r8,0xd1e455ae522650a5
     d03:	55 e4 d1 
     d06:	49 01 c8             	add    r8,rcx
     d09:	48 8d 0c 38          	lea    rcx,[rax+rdi*1]
     d0d:	49 bc d4 b4 e3 ca 12 	movabs r12,0x725a7312cae3b4d4
     d14:	73 5a 72 
     d17:	49 31 cc             	xor    r12,rcx
     d1a:	c4 43 fb f0 e4 33    	rorx   r12,r12,0x33
     d20:	49 31 d4             	xor    r12,rdx
     d23:	c4 c3 fb f0 d0 3d    	rorx   rdx,r8,0x3d
     d29:	48 01 f2             	add    rdx,rsi
     d2c:	49 8d 0c 14          	lea    rcx,[r12+rdx*1]
     d30:	48 be 32 7d 5e bc db 	movabs rsi,0xb346addbbc5e7d32
     d37:	ad 46 b3 
     d3a:	48 31 ce             	xor    rsi,rcx
     d3d:	48 89 d1             	mov    rcx,rdx
     d40:	48 31 c1             	xor    rcx,rax
     d43:	49 b8 03 19 a1 43 77 	movabs r8,0x12d0907743a11903
     d4a:	90 d0 12 
     d4d:	49 01 c8             	add    r8,rcx
     d50:	c4 e3 fb f0 ce 03    	rorx   rcx,rsi,0x3
     d56:	48 31 c1             	xor    rcx,rax
     d59:	c4 c3 fb f0 f0 23    	rorx   rsi,r8,0x23
     d5f:	48 01 fe             	add    rsi,rdi
     d62:	48 89 f0             	mov    rax,rsi
     d65:	4c 31 e0             	xor    rax,r12
     d68:	49 b8 61 e1 1b 35 40 	movabs r8,0x53bccb40351be161
     d6f:	cb bc 53 
     d72:	49 01 c0             	add    r8,rax
     d75:	48 8d 04 31          	lea    rax,[rcx+rsi*1]
     d79:	48 bf 90 45 d9 ad a4 	movabs rdi,0xf432e8a4add94590
     d80:	e8 32 f4 
     d83:	48 31 c7             	xor    rdi,rax
     d86:	c4 e3 fb f0 ff 21    	rorx   rdi,rdi,0x21
     d8c:	4c 31 e7             	xor    rdi,r12
     d8f:	c4 43 fb f0 e8 2f    	rorx   r13,r8,0x2f
     d95:	49 01 d5             	add    r13,rdx
     d98:	4a 8d 04 2f          	lea    rax,[rdi+r13*1]
     d9c:	48 ba ee 0d 54 9f 6d 	movabs rdx,0x351f236d9f540dee
     da3:	23 1f 35 
     da6:	48 31 c2             	xor    rdx,rax
     da9:	4c 89 e8             	mov    rax,r13
     dac:	48 31 c8             	xor    rax,rcx
     daf:	49 b8 bf a9 96 26 09 	movabs r8,0x94a906092696a9bf
     db6:	06 a9 94 
     db9:	49 01 c0             	add    r8,rax
     dbc:	c4 e3 fb f0 c2 35    	rorx   rax,rdx,0x35
     dc2:	48 31 c8             	xor    rax,rcx
     dc5:	c4 c3 fb f0 e8 15    	rorx   rbp,r8,0x15
     dcb:	48 01 f5             	add    rbp,rsi
     dce:	48 89 e9             	mov    rcx,rbp
     dd1:	48 31 f9             	xor    rcx,rdi
     dd4:	48 ba 1d 72 11 18 d2 	movabs rdx,0xd59540d21811721d
     ddb:	40 95 d5 
     dde:	48 01 ca             	add    rdx,rcx
     de1:	48 8d 0c 28          	lea    rcx,[rax+rbp*1]
     de5:	48 be 4c d6 ce 90 36 	movabs rsi,0x760b5e3690ced64c
     dec:	5e 0b 76 
     def:	48 31 ce             	xor    rsi,rcx
     df2:	c4 63 fb f0 e6 1b    	rorx   r12,rsi,0x1b
     df8:	49 31 fc             	xor    r12,rdi
     dfb:	c4 e3 fb f0 ca 2d    	rorx   rcx,rdx,0x2d
     e01:	4c 01 e9             	add    rcx,r13
     e04:	49 8d 14 0c          	lea    rdx,[r12+rcx*1]
     e08:	48 be aa 9e 49 82 ff 	movabs rsi,0xb6f798ff82499eaa
     e0f:	98 f7 b6 
     e12:	48 31 d6             	xor    rsi,rdx
     e15:	48 89 ca             	mov    rdx,rcx
     e18:	48 31 c2             	xor    rdx,rax
     e1b:	48 bf 7b 3a 8c 09 9b 	movabs rdi,0x16817b9b098c3a7b
     e22:	7b 81 16 
     e25:	48 01 d7             	add    rdi,rdx
     e28:	c4 e3 fb f0 d6 39    	rorx   rdx,rsi,0x39
     e2e:	48 31 c2             	xor    rdx,rax
     e31:	c4 e3 fb f0 f7 11    	rorx   rsi,rdi,0x11
     e37:	48 01 ee             	add    rsi,rbp
     e3a:	48 89 f0             	mov    rax,rsi
     e3d:	4c 31 e0             	xor    rax,r12
     e40:	48 bf d9 02 07 fb 63 	movabs rdi,0x576db663fb0702d9
     e47:	b6 6d 57 
     e4a:	48 01 c7             	add    rdi,rax
     e4d:	48 b8 77 62 2d e2 49 	movabs rax,0x85ae2d49e22d6277
     e54:	2d ae 85 
     e57:	4c 31 d0             	xor    rax,r10
     e5a:	48 01 f0             	add    rax,rsi
     e5d:	48 01 d6             	add    rsi,rdx
     e60:	49 b8 08 67 c4 73 c8 	movabs r8,0xf7e3d3c873c46708
     e67:	d3 e3 f7 
     e6a:	49 31 f0             	xor    r8,rsi
     e6d:	c4 c3 fb f0 f0 17    	rorx   rsi,r8,0x17
     e73:	4c 31 e6             	xor    rsi,r12
     e76:	c4 e3 fb f0 ff 29    	rorx   rdi,rdi,0x29
     e7c:	48 01 cf             	add    rdi,rcx
     e7f:	48 8d 0c 3e          	lea    rcx,[rsi+rdi*1]
     e83:	49 bc 66 2f 3f 65 91 	movabs r12,0x38d00e91653f2f66
     e8a:	0e d0 38 
     e8d:	49 31 cc             	xor    r12,rcx
     e90:	49 b8 72 99 1d c0 c4 	movabs r8,0xdb90e9c4c01d9972
     e97:	e9 90 db 
     e9a:	48 89 dd             	mov    rbp,rbx
     e9d:	49 31 d8             	xor    r8,rbx
     ea0:	49 01 f8             	add    r8,rdi
     ea3:	48 31 d7             	xor    rdi,rdx
     ea6:	48 b9 37 cb 81 ec 2c 	movabs rcx,0x9859f12cec81cb37
     ead:	f1 59 98 
     eb0:	48 01 f9             	add    rcx,rdi
     eb3:	4d 01 df             	add    r15,r11
     eb6:	49 31 f7             	xor    r15,rsi
     eb9:	c4 e3 fb f0 c9 0b    	rorx   rcx,rcx,0xb
     ebf:	48 01 c8             	add    rax,rcx
     ec2:	48 bb 2f d5 ba 53 14 	movabs rbx,0x60fc2a1453bad52f
     ec9:	2a fc 60 
     ecc:	49 8d 3c 19          	lea    rdi,[r9+rbx*1]
     ed0:	48 31 d7             	xor    rdi,rdx
     ed3:	c4 c3 fb f0 cc 3b    	rorx   rcx,r12,0x3b
     ed9:	48 31 cf             	xor    rdi,rcx
     edc:	48 8d 0c 07          	lea    rcx,[rdi+rax*1]
     ee0:	48 ba c4 f7 b9 56 5a 	movabs rdx,0x79bc495a56b9f7c4
     ee7:	49 bc 79 
     eea:	48 31 ca             	xor    rdx,rcx
     eed:	c4 e3 fb f0 ca 2f    	rorx   rcx,rdx,0x2f
     ef3:	4c 31 f9             	xor    rcx,r15
     ef6:	49 31 c7             	xor    r15,rax
     ef9:	48 ba 95 93 fc dd f5 	movabs rdx,0xd9462bf5ddfc9395
     f00:	2b 46 d9 
     f03:	4c 01 fa             	add    rdx,r15
     f06:	c4 e3 fb f0 f2 33    	rorx   rsi,rdx,0x33
     f0c:	4c 01 c6             	add    rsi,r8
     f0f:	48 8d 14 31          	lea    rdx,[rcx+rsi*1]
     f13:	49 b8 22 c0 34 48 23 	movabs r8,0xbaa884234834c022
     f1a:	84 a8 ba 
     f1d:	49 31 d0             	xor    r8,rdx
     f20:	48 89 f2             	mov    rdx,rsi
     f23:	48 31 fa             	xor    rdx,rdi
     f26:	49 bf f3 5b 77 cf be 	movabs r15,0x1a3266becf775bf3
     f2d:	66 32 1a 
     f30:	49 01 d7             	add    r15,rdx
     f33:	c4 c3 fb f0 d0 15    	rorx   rdx,r8,0x15
     f39:	48 31 fa             	xor    rdx,rdi
     f3c:	c4 c3 fb f0 ff 23    	rorx   rdi,r15,0x23
     f42:	48 01 c7             	add    rdi,rax
     f45:	48 89 f8             	mov    rax,rdi
     f48:	48 31 c8             	xor    rax,rcx
     f4b:	49 b8 51 24 f2 c0 87 	movabs r8,0x5b1ea187c0f22451
     f52:	a1 1e 5b 
     f55:	49 01 c0             	add    r8,rax
     f58:	48 8d 04 3a          	lea    rax,[rdx+rdi*1]
     f5c:	49 bf 80 88 af 39 ec 	movabs r15,0xfb94beec39af8880
     f63:	be 94 fb 
     f66:	49 31 c7             	xor    r15,rax
     f69:	c4 43 fb f0 ff 2d    	rorx   r15,r15,0x2d
     f6f:	49 31 cf             	xor    r15,rcx
     f72:	c4 c3 fb f0 c8 35    	rorx   rcx,r8,0x35
     f78:	48 01 f1             	add    rcx,rsi
     f7b:	49 8d 04 0f          	lea    rax,[r15+rcx*1]
     f7f:	48 be de 50 2a 2b b5 	movabs rsi,0x3c80f9b52b2a50de
     f86:	f9 80 3c 
     f89:	48 31 c6             	xor    rsi,rax
     f8c:	48 89 c8             	mov    rax,rcx
     f8f:	48 31 d0             	xor    rax,rdx
     f92:	49 b8 af ec 6c b2 50 	movabs r8,0x9c0adc50b26cecaf
     f99:	dc 0a 9c 
     f9c:	49 01 c0             	add    r8,rax
     f9f:	c4 e3 fb f0 c6 11    	rorx   rax,rsi,0x11
     fa5:	48 31 d0             	xor    rax,rdx
     fa8:	c4 c3 fb f0 d0 21    	rorx   rdx,r8,0x21
     fae:	48 01 fa             	add    rdx,rdi
     fb1:	48 89 d6             	mov    rsi,rdx
     fb4:	4c 31 fe             	xor    rsi,r15
     fb7:	48 bf 0d b5 e7 a3 19 	movabs rdi,0xdcf71719a3e7b50d
     fbe:	17 f7 dc 
     fc1:	48 01 f7             	add    rdi,rsi
     fc4:	48 8d 34 10          	lea    rsi,[rax+rdx*1]
     fc8:	49 b8 3c 19 a5 1c 7e 	movabs r8,0x7d6d347e1ca5193c
     fcf:	34 6d 7d 
     fd2:	49 31 f0             	xor    r8,rsi
     fd5:	c4 c3 fb f0 f0 29    	rorx   rsi,r8,0x29
     fdb:	4c 31 fe             	xor    rsi,r15
     fde:	c4 e3 fb f0 ff 39    	rorx   rdi,rdi,0x39
     fe4:	48 01 cf             	add    rdi,rcx
     fe7:	48 8d 0c 3e          	lea    rcx,[rsi+rdi*1]
     feb:	49 b8 9a e1 1f 0e 47 	movabs r8,0xbe596f470e1fe19a
     ff2:	6f 59 be 
     ff5:	49 31 c8             	xor    r8,rcx
     ff8:	48 89 f9             	mov    rcx,rdi
     ffb:	48 31 c1             	xor    rcx,rax
     ffe:	49 bf 6b 7d 62 95 e2 	movabs r15,0x1de351e295627d6b
    1005:	51 e3 1d 
    1008:	49 01 cf             	add    r15,rcx
    100b:	c4 c3 fb f0 c8 0b    	rorx   rcx,r8,0xb
    1011:	48 31 c1             	xor    rcx,rax
    1014:	c4 43 fb f0 ff 1b    	rorx   r15,r15,0x1b
    101a:	49 01 d7             	add    r15,rdx
    101d:	4c 89 f8             	mov    rax,r15
    1020:	48 31 f0             	xor    rax,rsi
    1023:	49 b8 c9 45 dd 86 ab 	movabs r8,0x5ecf8cab86dd45c9
    102a:	8c cf 5e 
    102d:	49 01 c0             	add    r8,rax
    1030:	4a 8d 04 39          	lea    rax,[rcx+r15*1]
    1034:	48 ba f8 a9 9a ff 0f 	movabs rdx,0xff45aa0fff9aa9f8
    103b:	aa 45 ff 
    103e:	48 31 c2             	xor    rdx,rax
    1041:	c4 e3 fb f0 d2 25    	rorx   rdx,rdx,0x25
    1047:	48 31 f2             	xor    rdx,rsi
    104a:	c4 c3 fb f0 f0 3b    	rorx   rsi,r8,0x3b
    1050:	48 01 fe             	add    rsi,rdi
    1053:	48 8d 04 32          	lea    rax,[rdx+rsi*1]
    1057:	48 bf 56 72 15 f1 d8 	movabs rdi,0x4031e4d8f1157256
    105e:	e4 31 40 
    1061:	48 31 c7             	xor    rdi,rax
    1064:	48 89 f0             	mov    rax,rsi
    1067:	48 31 c8             	xor    rax,rcx
    106a:	49 b8 27 0e 58 78 74 	movabs r8,0x9fbbc77478580e27
    1071:	c7 bb 9f 
    1074:	49 01 c0             	add    r8,rax
    1077:	c4 e3 fb f0 c7 05    	rorx   rax,rdi,0x5
    107d:	48 31 c8             	xor    rax,rcx
    1080:	c4 c3 fb f0 f8 17    	rorx   rdi,r8,0x17
    1086:	4c 01 ff             	add    rdi,r15
    1089:	48 89 f9             	mov    rcx,rdi
    108c:	48 31 d1             	xor    rcx,rdx
    108f:	49 b8 85 d6 d2 69 3d 	movabs r8,0xe0a8023d69d2d685
    1096:	02 a8 e0 
    1099:	49 01 c8             	add    r8,rcx
    109c:	48 8d 0c 38          	lea    rcx,[rax+rdi*1]
    10a0:	49 bf b4 3a 90 e2 a1 	movabs r15,0x811e1fa1e2903ab4
    10a7:	1f 1e 81 
    10aa:	49 31 cf             	xor    r15,rcx
    10ad:	c4 43 fb f0 ff 33    	rorx   r15,r15,0x33
    10b3:	49 31 d7             	xor    r15,rdx
    10b6:	c4 c3 fb f0 d0 3d    	rorx   rdx,r8,0x3d
    10bc:	48 01 f2             	add    rdx,rsi
    10bf:	49 8d 0c 17          	lea    rcx,[r15+rdx*1]
    10c3:	48 be 12 03 0b d4 6a 	movabs rsi,0xc20a5a6ad40b0312
    10ca:	5a 0a c2 
    10cd:	48 31 ce             	xor    rsi,rcx
    10d0:	48 89 d1             	mov    rcx,rdx
    10d3:	48 31 c1             	xor    rcx,rax
    10d6:	49 b8 e3 9e 4d 5b 06 	movabs r8,0x21943d065b4d9ee3
    10dd:	3d 94 21 
    10e0:	49 01 c8             	add    r8,rcx
    10e3:	c4 e3 fb f0 ce 03    	rorx   rcx,rsi,0x3
    10e9:	48 31 c1             	xor    rcx,rax
    10ec:	c4 c3 fb f0 f0 23    	rorx   rsi,r8,0x23
    10f2:	48 01 fe             	add    rsi,rdi
    10f5:	48 89 f0             	mov    rax,rsi
    10f8:	4c 31 f8             	xor    rax,r15
    10fb:	49 b8 41 67 c8 4c cf 	movabs r8,0x628077cf4cc86741
    1102:	77 80 62 
    1105:	49 01 c0             	add    r8,rax
    1108:	48 8d 04 31          	lea    rax,[rcx+rsi*1]
    110c:	48 bf 70 cb 85 c5 33 	movabs rdi,0x2f69533c585cb70
    1113:	95 f6 02 
    1116:	48 31 c7             	xor    rdi,rax
    1119:	c4 e3 fb f0 ff 21    	rorx   rdi,rdi,0x21
    111f:	4c 31 ff             	xor    rdi,r15
    1122:	c4 43 fb f0 e0 2f    	rorx   r12,r8,0x2f
    1128:	49 01 d4             	add    r12,rdx
    112b:	4a 8d 04 27          	lea    rax,[rdi+r12*1]
    112f:	48 ba ce 93 00 b7 fc 	movabs rdx,0x43e2cffcb70093ce
    1136:	cf e2 43 
    1139:	48 31 c2             	xor    rdx,rax
    113c:	4c 89 e0             	mov    rax,r12
    113f:	48 31 c8             	xor    rax,rcx
    1142:	49 b8 9f 2f 43 3e 98 	movabs r8,0xa36cb2983e432f9f
    1149:	b2 6c a3 
    114c:	49 01 c0             	add    r8,rax
    114f:	c4 e3 fb f0 c2 35    	rorx   rax,rdx,0x35
    1155:	48 31 c8             	xor    rax,rcx
    1158:	c4 43 fb f0 e8 15    	rorx   r13,r8,0x15
    115e:	49 01 f5             	add    r13,rsi
    1161:	4c 89 e9             	mov    rcx,r13
    1164:	48 31 f9             	xor    rcx,rdi
    1167:	48 ba fd f7 bd 2f 61 	movabs rdx,0xe458ed612fbdf7fd
    116e:	ed 58 e4 
    1171:	48 01 ca             	add    rdx,rcx
    1174:	4a 8d 0c 28          	lea    rcx,[rax+r13*1]
    1178:	48 be 2c 5c 7b a8 c5 	movabs rsi,0x84cf0ac5a87b5c2c
    117f:	0a cf 84 
    1182:	48 31 ce             	xor    rsi,rcx
    1185:	c4 63 fb f0 fe 1b    	rorx   r15,rsi,0x1b
    118b:	49 31 ff             	xor    r15,rdi
    118e:	c4 e3 fb f0 ca 2d    	rorx   rcx,rdx,0x2d
    1194:	4c 01 e1             	add    rcx,r12
    1197:	49 8d 14 0f          	lea    rdx,[r15+rcx*1]
    119b:	48 be 8a 24 f6 99 8e 	movabs rsi,0xc5bb458e99f6248a
    11a2:	45 bb c5 
    11a5:	48 31 d6             	xor    rsi,rdx
    11a8:	48 89 ca             	mov    rdx,rcx
    11ab:	48 31 c2             	xor    rdx,rax
    11ae:	48 bf 5b c0 38 21 2a 	movabs rdi,0x2545282a2138c05b
    11b5:	28 45 25 
    11b8:	48 01 d7             	add    rdi,rdx
    11bb:	c4 e3 fb f0 d6 39    	rorx   rdx,rsi,0x39
    11c1:	48 31 c2             	xor    rdx,rax
    11c4:	c4 e3 fb f0 f7 11    	rorx   rsi,rdi,0x11
    11ca:	4c 01 ee             	add    rsi,r13
    11cd:	48 89 f0             	mov    rax,rsi
    11d0:	4c 31 f8             	xor    rax,r15
    11d3:	48 bf b9 88 b3 12 f3 	movabs rdi,0x663162f312b388b9
    11da:	62 31 66 
    11dd:	48 01 c7             	add    rdi,rax
    11e0:	48 b8 58 c6 6a 6b f2 	movabs rax,0x25d40bf26b6ac658
    11e7:	0b d4 25 
    11ea:	4c 31 d0             	xor    rax,r10
    11ed:	48 01 f0             	add    rax,rsi
    11f0:	48 01 d6             	add    rsi,rdx
    11f3:	49 b8 e8 ec 70 8b 57 	movabs r8,0x6a780578b70ece8
    11fa:	80 a7 06 
    11fd:	49 31 f0             	xor    r8,rsi
    1200:	c4 c3 fb f0 f0 17    	rorx   rsi,r8,0x17
    1206:	4c 31 fe             	xor    rsi,r15
    1209:	c4 e3 fb f0 ff 29    	rorx   rdi,rdi,0x29
    120f:	48 01 cf             	add    rdi,rcx
    1212:	48 8d 0c 3e          	lea    rcx,[rsi+rdi*1]
    1216:	49 bf 46 b5 eb 7c 20 	movabs r15,0x4793bb207cebb546
    121d:	bb 93 47 
    1220:	49 31 cf             	xor    r15,rcx
    1223:	49 b8 01 3d df 4b 69 	movabs r8,0x8406d7694bdf3d01
    122a:	d7 06 84 
    122d:	49 31 e8             	xor    r8,rbp
    1230:	49 89 ec             	mov    r12,rbp
    1233:	49 01 f8             	add    r8,rdi
    1236:	48 31 d7             	xor    rdi,rdx
    1239:	48 b9 17 51 2e 04 bc 	movabs rcx,0xa71d9dbc042e5117
    1240:	9d 1d a7 
    1243:	48 01 f9             	add    rcx,rdi
    1246:	4d 89 dd             	mov    r13,r11
    1249:	4d 01 de             	add    r14,r11
    124c:	49 31 f6             	xor    r14,rsi
    124f:	c4 e3 fb f0 c9 0b    	rorx   rcx,rcx,0xb
    1255:	48 01 c8             	add    rax,rcx
    1258:	48 b9 5e 39 78 cc 78 	movabs rcx,0x1724778cc78395e
    125f:	47 72 01 
    1262:	49 8d 3c 09          	lea    rdi,[r9+rcx*1]
    1266:	48 31 d7             	xor    rdi,rdx
    1269:	c4 c3 fb f0 cf 3b    	rorx   rcx,r15,0x3b
    126f:	48 31 cf             	xor    rdi,rcx
    1272:	48 8d 0c 07          	lea    rcx,[rdi+rax*1]
    1276:	48 ba a4 7d 66 6e e9 	movabs rdx,0x887ff5e96e667da4
    127d:	f5 7f 88 
    1280:	48 31 ca             	xor    rdx,rcx
    1283:	c4 e3 fb f0 ca 2f    	rorx   rcx,rdx,0x2f
    1289:	4c 31 f1             	xor    rcx,r14
    128c:	49 31 c6             	xor    r14,rax
    128f:	48 ba 75 19 a9 f5 84 	movabs rdx,0xe809d884f5a91975
    1296:	d8 09 e8 
    1299:	4c 01 f2             	add    rdx,r14
    129c:	c4 e3 fb f0 f2 33    	rorx   rsi,rdx,0x33
    12a2:	4c 01 c6             	add    rsi,r8
    12a5:	48 8d 14 31          	lea    rdx,[rcx+rsi*1]
    12a9:	49 b8 02 46 e1 5f b2 	movabs r8,0xc96c30b25fe14602
    12b0:	30 6c c9 
    12b3:	49 31 d0             	xor    r8,rdx
    12b6:	48 89 f2             	mov    rdx,rsi
    12b9:	48 31 fa             	xor    rdx,rdi
    12bc:	49 be d3 e1 23 e7 4d 	movabs r14,0x28f6134de723e1d3
    12c3:	13 f6 28 
    12c6:	49 01 d6             	add    r14,rdx
    12c9:	c4 c3 fb f0 d0 15    	rorx   rdx,r8,0x15
    12cf:	48 31 fa             	xor    rdx,rdi
    12d2:	c4 c3 fb f0 fe 23    	rorx   rdi,r14,0x23
    12d8:	48 01 c7             	add    rdi,rax
    12db:	48 89 f8             	mov    rax,rdi
    12de:	48 31 c8             	xor    rax,rcx
    12e1:	49 b8 31 aa 9e d8 16 	movabs r8,0x69e24e16d89eaa31
    12e8:	4e e2 69 
    12eb:	49 01 c0             	add    r8,rax
    12ee:	48 8d 04 3a          	lea    rax,[rdx+rdi*1]
    12f2:	49 be 60 0e 5c 51 7b 	movabs r14,0xa586b7b515c0e60
    12f9:	6b 58 0a 
    12fc:	49 31 c6             	xor    r14,rax
    12ff:	c4 43 fb f0 f6 2d    	rorx   r14,r14,0x2d
    1305:	49 31 ce             	xor    r14,rcx
    1308:	c4 c3 fb f0 c8 35    	rorx   rcx,r8,0x35
    130e:	48 01 f1             	add    rcx,rsi
    1311:	49 8d 04 0e          	lea    rax,[r14+rcx*1]
    1315:	48 be be d6 d6 42 44 	movabs rsi,0x4b44a64442d6d6be
    131c:	a6 44 4b 
    131f:	48 31 c6             	xor    rsi,rax
    1322:	48 89 c8             	mov    rax,rcx
    1325:	48 31 d0             	xor    rax,rdx
    1328:	49 b8 8f 72 19 ca df 	movabs r8,0xaace88dfca19728f
    132f:	88 ce aa 
    1332:	49 01 c0             	add    r8,rax
    1335:	c4 e3 fb f0 c6 11    	rorx   rax,rsi,0x11
    133b:	48 31 d0             	xor    rax,rdx
    133e:	c4 c3 fb f0 d0 21    	rorx   rdx,r8,0x21
    1344:	48 01 fa             	add    rdx,rdi
    1347:	48 89 d6             	mov    rsi,rdx
    134a:	4c 31 f6             	xor    rsi,r14
    134d:	48 bf ed 3a 94 bb a8 	movabs rdi,0xebbac3a8bb943aed
    1354:	c3 ba eb 
    1357:	48 01 f7             	add    rdi,rsi
    135a:	48 8d 34 10          	lea    rsi,[rax+rdx*1]
    135e:	49 b8 1c 9f 51 34 0d 	movabs r8,0x8c30e10d34519f1c
    1365:	e1 30 8c 
    1368:	49 31 f0             	xor    r8,rsi
    136b:	c4 c3 fb f0 f0 29    	rorx   rsi,r8,0x29
    1371:	4c 31 f6             	xor    rsi,r14
    1374:	c4 e3 fb f0 ff 39    	rorx   rdi,rdi,0x39
    137a:	48 01 cf             	add    rdi,rcx
    137d:	48 8d 0c 3e          	lea    rcx,[rsi+rdi*1]
    1381:	49 b8 7a 67 cc 25 d6 	movabs r8,0xcd1d1bd625cc677a
    1388:	1b 1d cd 
    138b:	49 31 c8             	xor    r8,rcx
    138e:	48 89 f9             	mov    rcx,rdi
    1391:	48 31 c1             	xor    rcx,rax
    1394:	49 be 4b 03 0f ad 71 	movabs r14,0x2ca6fe71ad0f034b
    139b:	fe a6 2c 
    139e:	49 01 ce             	add    r14,rcx
    13a1:	c4 c3 fb f0 c8 0b    	rorx   rcx,r8,0xb
    13a7:	48 31 c1             	xor    rcx,rax
    13aa:	c4 43 fb f0 f6 1b    	rorx   r14,r14,0x1b
    13b0:	49 01 d6             	add    r14,rdx
    13b3:	4c 89 f0             	mov    rax,r14
    13b6:	48 31 f0             	xor    rax,rsi
    13b9:	49 b8 a9 cb 89 9e 3a 	movabs r8,0x6d93393a9e89cba9
    13c0:	39 93 6d 
    13c3:	49 01 c0             	add    r8,rax
    13c6:	4a 8d 04 31          	lea    rax,[rcx+r14*1]
    13ca:	48 ba d8 2f 47 17 9f 	movabs rdx,0xe09569f17472fd8
    13d1:	56 09 0e 
    13d4:	48 31 c2             	xor    rdx,rax
    13d7:	c4 e3 fb f0 d2 25    	rorx   rdx,rdx,0x25
    13dd:	48 31 f2             	xor    rdx,rsi
    13e0:	c4 c3 fb f0 f0 3b    	rorx   rsi,r8,0x3b
    13e6:	48 01 fe             	add    rsi,rdi
    13e9:	48 8d 04 32          	lea    rax,[rdx+rsi*1]
    13ed:	48 bf 36 f8 c1 08 68 	movabs rdi,0x4ef5916808c1f836
    13f4:	91 f5 4e 
    13f7:	48 31 c7             	xor    rdi,rax
    13fa:	48 89 f0             	mov    rax,rsi
    13fd:	48 31 c8             	xor    rax,rcx
    1400:	49 b8 07 94 04 90 03 	movabs r8,0xae7f740390049407
    1407:	74 7f ae 
    140a:	49 01 c0             	add    r8,rax
    140d:	c4 e3 fb f0 c7 05    	rorx   rax,rdi,0x5
    1413:	48 31 c8             	xor    rax,rcx
    1416:	c4 c3 fb f0 f8 17    	rorx   rdi,r8,0x17
    141c:	4c 01 f7             	add    rdi,r14
    141f:	48 89 f9             	mov    rcx,rdi
    1422:	48 31 d1             	xor    rcx,rdx
    1425:	49 b8 65 5c 7f 81 cc 	movabs r8,0xef6baecc817f5c65
    142c:	ae 6b ef 
    142f:	49 01 c8             	add    r8,rcx
    1432:	48 8d 0c 38          	lea    rcx,[rax+rdi*1]
    1436:	49 be 94 c0 3c fa 30 	movabs r14,0x8fe1cc30fa3cc094
    143d:	cc e1 8f 
    1440:	49 31 ce             	xor    r14,rcx
    1443:	c4 43 fb f0 f6 33    	rorx   r14,r14,0x33
    1449:	49 31 d6             	xor    r14,rdx
    144c:	c4 c3 fb f0 d0 3d    	rorx   rdx,r8,0x3d
    1452:	48 01 f2             	add    rdx,rsi
    1455:	49 8d 0c 16          	lea    rcx,[r14+rdx*1]
    1459:	48 be f2 88 b7 eb f9 	movabs rsi,0xd0ce06f9ebb788f2
    1460:	06 ce d0 
    1463:	48 31 ce             	xor    rsi,rcx
    1466:	48 89 d1             	mov    rcx,rdx
    1469:	48 31 c1             	xor    rcx,rax
    146c:	49 b8 c3 24 fa 72 95 	movabs r8,0x3057e99572fa24c3
    1473:	e9 57 30 
    1476:	49 01 c8             	add    r8,rcx
    1479:	c4 e3 fb f0 ce 03    	rorx   rcx,rsi,0x3
    147f:	48 31 c1             	xor    rcx,rax
    1482:	c4 c3 fb f0 c0 23    	rorx   rax,r8,0x23
    1488:	48 01 f8             	add    rax,rdi
    148b:	48 89 c6             	mov    rsi,rax
    148e:	4c 31 f6             	xor    rsi,r14
    1491:	48 bf 21 ed 74 64 5e 	movabs rdi,0x7144245e6474ed21
    1498:	24 44 71 
    149b:	48 01 f7             	add    rdi,rsi
    149e:	48 8d 34 01          	lea    rsi,[rcx+rax*1]
    14a2:	49 b8 50 51 32 dd c2 	movabs r8,0x11ba41c2dd325150
    14a9:	41 ba 11 
    14ac:	49 31 f0             	xor    r8,rsi
    14af:	c4 c3 fb f0 f0 21    	rorx   rsi,r8,0x21
    14b5:	4c 31 f6             	xor    rsi,r14
    14b8:	c4 e3 fb f0 ff 2f    	rorx   rdi,rdi,0x2f
    14be:	48 01 d7             	add    rdi,rdx
    14c1:	48 8d 14 3e          	lea    rdx,[rsi+rdi*1]
    14c5:	49 b8 ae 19 ad ce 8b 	movabs r8,0x52a67c8bcead19ae
    14cc:	7c a6 52 
    14cf:	49 31 d0             	xor    r8,rdx
    14d2:	48 89 fa             	mov    rdx,rdi
    14d5:	48 31 ca             	xor    rdx,rcx
    14d8:	49 be 7f b5 ef 55 27 	movabs r14,0xb2305f2755efb57f
    14df:	5f 30 b2 
    14e2:	49 01 d6             	add    r14,rdx
    14e5:	c4 c3 fb f0 d0 35    	rorx   rdx,r8,0x35
    14eb:	48 31 ca             	xor    rdx,rcx
    14ee:	c4 43 fb f0 fe 15    	rorx   r15,r14,0x15
    14f4:	49 01 c7             	add    r15,rax
    14f7:	4c 89 f8             	mov    rax,r15
    14fa:	48 31 f0             	xor    rax,rsi
    14fd:	48 b9 dd 7d 6a 47 f0 	movabs rcx,0xf31c99f0476a7ddd
    1504:	99 1c f3 
    1507:	48 01 c1             	add    rcx,rax
    150a:	4a 8d 04 3a          	lea    rax,[rdx+r15*1]
    150e:	49 b8 0c e2 27 c0 54 	movabs r8,0x9392b754c027e20c
    1515:	b7 92 93 
    1518:	49 31 c0             	xor    r8,rax
    151b:	c4 43 fb f0 f0 1b    	rorx   r14,r8,0x1b
    1521:	49 31 f6             	xor    r14,rsi
    1524:	c4 e3 fb f0 c9 2d    	rorx   rcx,rcx,0x2d
    152a:	48 01 f9             	add    rcx,rdi
    152d:	49 8d 04 0e          	lea    rax,[r14+rcx*1]
    1531:	48 be 6a aa a2 b1 1d 	movabs rsi,0xd47ef21db1a2aa6a
    1538:	f2 7e d4 
    153b:	48 31 c6             	xor    rsi,rax
    153e:	48 89 c8             	mov    rax,rcx
    1541:	48 31 d0             	xor    rax,rdx
    1544:	48 bf 3b 46 e5 38 b9 	movabs rdi,0x3408d4b938e5463b
    154b:	d4 08 34 
    154e:	48 01 c7             	add    rdi,rax
    1551:	c4 e3 fb f0 c6 39    	rorx   rax,rsi,0x39
    1557:	48 31 d0             	xor    rax,rdx
    155a:	c4 e3 fb f0 f7 11    	rorx   rsi,rdi,0x11
    1560:	4c 01 fe             	add    rsi,r15
    1563:	48 89 f2             	mov    rdx,rsi
    1566:	4c 31 f2             	xor    rdx,r14
    1569:	48 bf 99 0e 60 2a 82 	movabs rdi,0x74f50f822a600e99
    1570:	0f f5 74 
    1573:	48 01 d7             	add    rdi,rdx
    1576:	48 ba 29 2a a8 f4 9e 	movabs rdx,0x445a669ef4a82a29
    157d:	66 5a 44 
    1580:	4c 31 d2             	xor    rdx,r10
    1583:	4c 89 d5             	mov    rbp,r10
    1586:	48 01 f2             	add    rdx,rsi
    1589:	48 01 c6             	add    rsi,rax
    158c:	49 b8 c8 72 1d a3 e6 	movabs r8,0x156b2ce6a31d72c8
    1593:	2c 6b 15 
    1596:	49 31 f0             	xor    r8,rsi
    1599:	c4 43 fb f0 c0 17    	rorx   r8,r8,0x17
    159f:	4d 31 f0             	xor    r8,r14
    15a2:	c4 e3 fb f0 ff 29    	rorx   rdi,rdi,0x29
    15a8:	48 01 cf             	add    rdi,rcx
    15ab:	49 8d 0c 38          	lea    rcx,[r8+rdi*1]
    15af:	49 be 26 3b 98 94 af 	movabs r14,0x565767af94983b26
    15b6:	67 57 56 
    15b9:	49 31 ce             	xor    r14,rcx
    15bc:	48 be d0 40 62 f3 8d 	movabs rsi,0x648f348df36240d0
    15c3:	34 8f 64 
    15c6:	4d 89 e2             	mov    r10,r12
    15c9:	4c 31 e6             	xor    rsi,r12
    15cc:	48 01 fe             	add    rsi,rdi
    15cf:	48 31 c7             	xor    rdi,rax
    15d2:	48 b9 f7 d6 da 1b 4b 	movabs rcx,0xb5e14a4b1bdad6f7
    15d9:	4a e1 b5 
    15dc:	48 01 f9             	add    rcx,rdi
    15df:	48 89 df             	mov    rdi,rbx
    15e2:	4c 01 df             	add    rdi,r11
    15e5:	4c 31 c7             	xor    rdi,r8
    15e8:	49 89 f8             	mov    r8,rdi
    15eb:	c4 c3 fb f0 fe 3b    	rorx   rdi,r14,0x3b
    15f1:	c4 e3 fb f0 c9 0b    	rorx   rcx,rcx,0xb
    15f7:	48 01 ca             	add    rdx,rcx
    15fa:	48 b9 8d 9d 35 45 dd 	movabs rcx,0xa1e864dd45359d8d
    1601:	64 e8 a1 
    1604:	4c 01 c9             	add    rcx,r9
    1607:	48 31 c1             	xor    rcx,rax
    160a:	48 31 f9             	xor    rcx,rdi
    160d:	48 8d 04 11          	lea    rax,[rcx+rdx*1]
    1611:	48 bf 84 03 13 86 78 	movabs rdi,0x9743a27886130384
    1618:	a2 43 97 
    161b:	48 31 c7             	xor    rdi,rax
    161e:	c4 e3 fb f0 c7 2f    	rorx   rax,rdi,0x2f
    1624:	4c 31 c0             	xor    rax,r8
    1627:	49 31 d0             	xor    r8,rdx
    162a:	48 bf 55 9f 55 0d 14 	movabs rdi,0xf6cd85140d559f55
    1631:	85 cd f6 
    1634:	4c 01 c7             	add    rdi,r8
    1637:	c4 63 fb f0 c7 33    	rorx   r8,rdi,0x33
    163d:	49 01 f0             	add    r8,rsi
    1640:	4a 8d 34 00          	lea    rsi,[rax+r8*1]
    1644:	48 bf e2 cb 8d 77 41 	movabs rdi,0xd82fdd41778dcbe2
    164b:	dd 2f d8 
    164e:	48 31 f7             	xor    rdi,rsi
    1651:	4c 89 c6             	mov    rsi,r8
    1654:	48 31 ce             	xor    rsi,rcx
    1657:	48 bb b3 67 d0 fe dc 	movabs rbx,0x37b9bfdcfed067b3
    165e:	bf b9 37 
    1661:	48 01 f3             	add    rbx,rsi
    1664:	c4 e3 fb f0 ff 15    	rorx   rdi,rdi,0x15
    166a:	c4 e3 fb f0 f3 23    	rorx   rsi,rbx,0x23
    1670:	48 31 cf             	xor    rdi,rcx
    1673:	48 01 d6             	add    rsi,rdx
    1676:	48 89 f1             	mov    rcx,rsi
    1679:	48 31 c1             	xor    rcx,rax
    167c:	48 ba 11 30 4b f0 a5 	movabs rdx,0x78a5faa5f04b3011
    1683:	fa a5 78 
    1686:	48 01 ca             	add    rdx,rcx
    1689:	48 8d 0c 37          	lea    rcx,[rdi+rsi*1]
    168d:	48 bb 40 94 08 69 0a 	movabs rbx,0x191c180a69089440
    1694:	18 1c 19 
    1697:	48 31 cb             	xor    rbx,rcx
    169a:	c4 e3 fb f0 ca 35    	rorx   rcx,rdx,0x35
    16a0:	c4 63 fb f0 f3 2d    	rorx   r14,rbx,0x2d
    16a6:	49 31 c6             	xor    r14,rax
    16a9:	4c 01 c1             	add    rcx,r8
    16ac:	49 8d 04 0e          	lea    rax,[r14+rcx*1]
    16b0:	48 ba 9e 5c 83 5a d3 	movabs rdx,0x5a0852d35a835c9e
    16b7:	52 08 5a 
    16ba:	48 31 c2             	xor    rdx,rax
    16bd:	48 89 c8             	mov    rax,rcx
    16c0:	48 31 f8             	xor    rax,rdi
    16c3:	49 b8 6f f8 c5 e1 6e 	movabs r8,0xb992356ee1c5f86f
    16ca:	35 92 b9 
    16cd:	49 01 c0             	add    r8,rax
    16d0:	c4 e3 fb f0 da 11    	rorx   rbx,rdx,0x11
    16d6:	c4 c3 fb f0 d0 21    	rorx   rdx,r8,0x21
    16dc:	48 31 fb             	xor    rbx,rdi
    16df:	48 01 f2             	add    rdx,rsi
    16e2:	48 89 d0             	mov    rax,rdx
    16e5:	4c 31 f0             	xor    rax,r14
    16e8:	48 be cd c0 40 d3 37 	movabs rsi,0xfa7e7037d340c0cd
    16ef:	70 7e fa 
    16f2:	48 01 c6             	add    rsi,rax
    16f5:	48 8d 04 13          	lea    rax,[rbx+rdx*1]
    16f9:	48 bf fc 24 fe 4b 9c 	movabs rdi,0x9af48d9c4bfe24fc
    1700:	8d f4 9a 
    1703:	48 31 c7             	xor    rdi,rax
    1706:	c4 e3 fb f0 c6 39    	rorx   rax,rsi,0x39
    170c:	c4 63 fb f0 c7 29    	rorx   r8,rdi,0x29
    1712:	4d 31 f0             	xor    r8,r14
    1715:	48 01 c8             	add    rax,rcx
    1718:	49 8d 0c 00          	lea    rcx,[r8+rax*1]
    171c:	48 be 5a ed 78 3d 65 	movabs rsi,0xdbe0c8653d78ed5a
    1723:	c8 e0 db 
    1726:	48 31 ce             	xor    rsi,rcx
    1729:	48 89 c1             	mov    rcx,rax
    172c:	48 31 d9             	xor    rcx,rbx
    172f:	49 be 2b 89 bb c4 00 	movabs r14,0x3b6aab00c4bb892b
    1736:	ab 6a 3b 
    1739:	49 01 ce             	add    r14,rcx
    173c:	c4 e3 fb f0 fe 0b    	rorx   rdi,rsi,0xb
    1742:	c4 c3 fb f0 f6 1b    	rorx   rsi,r14,0x1b
    1748:	48 31 df             	xor    rdi,rbx
    174b:	48 01 d6             	add    rsi,rdx
    174e:	48 89 f1             	mov    rcx,rsi
    1751:	4c 31 c1             	xor    rcx,r8
    1754:	48 ba 89 51 36 b6 c9 	movabs rdx,0x7c56e5c9b6365189
    175b:	e5 56 7c 
    175e:	48 01 ca             	add    rdx,rcx
    1761:	48 8d 0c 37          	lea    rcx,[rdi+rsi*1]
    1765:	48 bb b8 b5 f3 2e 2e 	movabs rbx,0x1ccd032e2ef3b5b8
    176c:	03 cd 1c 
    176f:	48 31 cb             	xor    rbx,rcx
    1772:	c4 e3 fb f0 ca 3b    	rorx   rcx,rdx,0x3b
    1778:	c4 63 fb f0 f3 25    	rorx   r14,rbx,0x25
    177e:	4d 31 c6             	xor    r14,r8
    1781:	48 01 c1             	add    rcx,rax
    1784:	49 8d 04 0e          	lea    rax,[r14+rcx*1]
    1788:	48 ba 16 7e 6e 20 f7 	movabs rdx,0x5db93df7206e7e16
    178f:	3d b9 5d 
    1792:	48 31 c2             	xor    rdx,rax
    1795:	48 89 c8             	mov    rax,rcx
    1798:	48 31 f8             	xor    rax,rdi
    179b:	49 b8 e7 19 b1 a7 92 	movabs r8,0xbd432092a7b119e7
    17a2:	20 43 bd 
    17a5:	49 01 c0             	add    r8,rax
    17a8:	c4 e3 fb f0 da 05    	rorx   rbx,rdx,0x5
    17ae:	c4 c3 fb f0 d0 17    	rorx   rdx,r8,0x17
    17b4:	48 31 fb             	xor    rbx,rdi
    17b7:	48 01 f2             	add    rdx,rsi
    17ba:	48 89 d0             	mov    rax,rdx
    17bd:	4c 31 f0             	xor    rax,r14
    17c0:	48 be 45 e2 2b 99 5b 	movabs rsi,0xfe2f5b5b992be245
    17c7:	5b 2f fe 
    17ca:	48 01 c6             	add    rsi,rax
    17cd:	48 8d 04 13          	lea    rax,[rbx+rdx*1]
    17d1:	48 bf 74 46 e9 11 c0 	movabs rdi,0x9ea578c011e94674
    17d8:	78 a5 9e 
    17db:	48 31 c7             	xor    rdi,rax
    17de:	c4 e3 fb f0 c6 3d    	rorx   rax,rsi,0x3d
    17e4:	c4 63 fb f0 c7 33    	rorx   r8,rdi,0x33
    17ea:	4d 31 f0             	xor    r8,r14
    17ed:	48 01 c8             	add    rax,rcx
    17f0:	49 8d 0c 00          	lea    rcx,[r8+rax*1]
    17f4:	48 be d2 0e 64 03 89 	movabs rsi,0xdf91b38903640ed2
    17fb:	b3 91 df 
    17fe:	48 31 ce             	xor    rsi,rcx
    1801:	48 89 c1             	mov    rcx,rax
    1804:	48 31 d9             	xor    rcx,rbx
    1807:	49 be a3 aa a6 8a 24 	movabs r14,0x3f1b96248aa6aaa3
    180e:	96 1b 3f 
    1811:	49 01 ce             	add    r14,rcx
    1814:	c4 e3 fb f0 fe 03    	rorx   rdi,rsi,0x3
    181a:	c4 c3 fb f0 f6 23    	rorx   rsi,r14,0x23
    1820:	48 31 df             	xor    rdi,rbx
    1823:	48 01 d6             	add    rsi,rdx
    1826:	48 89 f1             	mov    rcx,rsi
    1829:	4c 31 c1             	xor    rcx,r8
    182c:	48 ba 01 73 21 7c ed 	movabs rdx,0x8007d0ed7c217301
    1833:	d0 07 80 
    1836:	48 01 ca             	add    rdx,rcx
    1839:	48 8d 0c 37          	lea    rcx,[rdi+rsi*1]
    183d:	48 bb 30 d7 de f4 51 	movabs rbx,0x207dee51f4ded730
    1844:	ee 7d 20 
    1847:	48 31 cb             	xor    rbx,rcx
    184a:	c4 e3 fb f0 ca 2f    	rorx   rcx,rdx,0x2f
    1850:	c4 63 fb f0 e3 21    	rorx   r12,rbx,0x21
    1856:	4d 31 c4             	xor    r12,r8
    1859:	48 01 c1             	add    rcx,rax
    185c:	49 8d 04 0c          	lea    rax,[r12+rcx*1]
    1860:	48 ba 8e 9f 59 e6 1a 	movabs rdx,0x616a291ae6599f8e
    1867:	29 6a 61 
    186a:	48 31 c2             	xor    rdx,rax
    186d:	48 89 c8             	mov    rax,rcx
    1870:	48 31 f8             	xor    rax,rdi
    1873:	49 b8 5f 3b 9c 6d b6 	movabs r8,0xc0f40bb66d9c3b5f
    187a:	0b f4 c0 
    187d:	49 01 c0             	add    r8,rax
    1880:	c4 63 fb f0 fa 35    	rorx   r15,rdx,0x35
    1886:	c4 c3 fb f0 d0 15    	rorx   rdx,r8,0x15
    188c:	49 31 ff             	xor    r15,rdi
    188f:	48 01 f2             	add    rdx,rsi
    1892:	48 89 d0             	mov    rax,rdx
    1895:	4c 31 e0             	xor    rax,r12
    1898:	48 be bd 03 17 5f 7f 	movabs rsi,0x1e0467f5f1703bd
    189f:	46 e0 01 
    18a2:	48 01 c6             	add    rsi,rax
    18a5:	49 8d 04 17          	lea    rax,[r15+rdx*1]
    18a9:	48 bf ec 67 d4 d7 e3 	movabs rdi,0xa25663e3d7d467ec
    18b0:	63 56 a2 
    18b3:	48 31 c7             	xor    rdi,rax
    18b6:	c4 e3 fb f0 de 2d    	rorx   rbx,rsi,0x2d
    18bc:	c4 63 fb f0 f7 1b    	rorx   r14,rdi,0x1b
    18c2:	4d 31 e6             	xor    r14,r12
    18c5:	48 01 cb             	add    rbx,rcx
    18c8:	49 8d 04 1e          	lea    rax,[r14+rbx*1]
    18cc:	48 b9 4a 30 4f c9 ac 	movabs rcx,0xe3429eacc94f304a
    18d3:	9e 42 e3 
    18d6:	48 31 c1             	xor    rcx,rax
    18d9:	48 89 d8             	mov    rax,rbx
    18dc:	4c 31 f8             	xor    rax,r15
    18df:	48 be 1b cc 91 50 48 	movabs rsi,0x42cc81485091cc1b
    18e6:	81 cc 42 
    18e9:	48 01 c6             	add    rsi,rax
    18ec:	c4 e3 fb f0 c1 39    	rorx   rax,rcx,0x39
    18f2:	c4 e3 fb f0 ce 11    	rorx   rcx,rsi,0x11
    18f8:	4c 31 f8             	xor    rax,r15
    18fb:	48 01 d1             	add    rcx,rdx
    18fe:	48 89 ca             	mov    rdx,rcx
    1901:	4c 31 f2             	xor    rdx,r14
    1904:	48 be 79 94 0c 42 11 	movabs rsi,0x83b8bc11420c9479
    190b:	bc b8 83 
    190e:	48 01 d6             	add    rsi,rdx
    1911:	48 ba fa 8e e5 7d 3b 	movabs rdx,0xe4c0453b7de58efa
    1918:	45 c0 e4 
    191b:	48 31 ea             	xor    rdx,rbp
    191e:	48 01 ca             	add    rdx,rcx
    1921:	48 01 c1             	add    rcx,rax
    1924:	48 bf a8 f8 c9 ba 75 	movabs rdi,0x242ed975bac9f8a8
    192b:	d9 2e 24 
    192e:	48 31 cf             	xor    rdi,rcx
    1931:	c4 e3 fb f0 ce 29    	rorx   rcx,rsi,0x29
    1937:	c4 e3 fb f0 ff 17    	rorx   rdi,rdi,0x17
    193d:	4c 31 f7             	xor    rdi,r14
    1940:	48 01 d9             	add    rcx,rbx
    1943:	48 8d 34 0f          	lea    rsi,[rdi+rcx*1]
    1947:	49 b8 06 c1 44 ac 3e 	movabs r8,0x651b143eac44c106
    194e:	14 1b 65 
    1951:	49 31 f0             	xor    r8,rsi
    1954:	48 be ff e4 25 7a 36 	movabs rsi,0xc4f512367a25e4ff
    195b:	12 f5 c4 
    195e:	4c 31 d6             	xor    rsi,r10
    1961:	4d 89 d7             	mov    r15,r10
    1964:	48 01 ce             	add    rsi,rcx
    1967:	48 31 c1             	xor    rcx,rax
    196a:	48 bb d7 5c 87 33 da 	movabs rbx,0xc4a4f6da33875cd7
    1971:	f6 a4 c4 
    1974:	48 01 cb             	add    rbx,rcx
    1977:	48 b9 5e 39 78 cc 78 	movabs rcx,0x1724778cc78395e
    197e:	47 72 01 
    1981:	4c 01 d9             	add    rcx,r11
    1984:	48 31 f9             	xor    rcx,rdi
    1987:	49 89 ca             	mov    r10,rcx
    198a:	c4 c3 fb f0 c8 3b    	rorx   rcx,r8,0x3b
    1990:	c4 e3 fb f0 fb 0b    	rorx   rdi,rbx,0xb
    1996:	49 b8 bc 01 f3 bd 41 	movabs r8,0x425e8241bdf301bc
    199d:	82 5e 42 
    19a0:	4d 01 c8             	add    r8,r9
    19a3:	48 01 fa             	add    rdx,rdi
    19a6:	49 31 c0             	xor    r8,rax
    19a9:	49 31 c8             	xor    r8,rcx
    19ac:	49 8d 04 10          	lea    rax,[r8+rdx*1]
    19b0:	4d 89 c3             	mov    r11,r8
    19b3:	48 b9 64 89 bf 9d 07 	movabs rcx,0xa6074f079dbf8964
    19ba:	4f 07 a6 
    19bd:	48 31 c1             	xor    rcx,rax
    19c0:	c4 e3 fb f0 c9 2f    	rorx   rcx,rcx,0x2f
    19c6:	4c 31 d1             	xor    rcx,r10
    19c9:	49 31 d2             	xor    r10,rdx
    19cc:	48 b8 35 25 02 25 a3 	movabs rax,0x59131a325022535
    19d3:	31 91 05 
    19d6:	4c 01 d0             	add    rax,r10
    19d9:	c4 63 fb f0 c0 33    	rorx   r8,rax,0x33
    19df:	49 01 f0             	add    r8,rsi
    19e2:	4a 8d 04 01          	lea    rax,[rcx+r8*1]
    19e6:	48 be c2 51 3a 8f d0 	movabs rsi,0xe6f389d08f3a51c2
    19ed:	89 f3 e6 
    19f0:	48 31 c6             	xor    rsi,rax
    19f3:	c4 e3 fb f0 f6 15    	rorx   rsi,rsi,0x15
    19f9:	4c 89 c0             	mov    rax,r8
    19fc:	4c 31 d8             	xor    rax,r11
    19ff:	48 bf 93 ed 7c 16 6c 	movabs rdi,0x467d6c6c167ced93
    1a06:	6c 7d 46 
    1a09:	48 01 c7             	add    rdi,rax
    1a0c:	c4 e3 fb f0 ff 23    	rorx   rdi,rdi,0x23
    1a12:	4c 31 de             	xor    rsi,r11
    1a15:	48 01 d7             	add    rdi,rdx
    1a18:	48 89 f8             	mov    rax,rdi
    1a1b:	48 31 c8             	xor    rax,rcx
    1a1e:	48 ba f1 b5 f7 07 35 	movabs rdx,0x8769a73507f7b5f1
    1a25:	a7 69 87 
    1a28:	48 01 c2             	add    rdx,rax
    1a2b:	c4 e3 fb f0 c2 35    	rorx   rax,rdx,0x35
    1a31:	48 8d 14 3e          	lea    rdx,[rsi+rdi*1]
    1a35:	49 ba 20 1a b5 80 99 	movabs r10,0x27dfc49980b51a20
    1a3c:	c4 df 27 
    1a3f:	49 31 d2             	xor    r10,rdx
    1a42:	c4 43 fb f0 d2 2d    	rorx   r10,r10,0x2d
    1a48:	49 31 ca             	xor    r10,rcx
    1a4b:	4c 01 c0             	add    rax,r8
    1a4e:	49 8d 0c 02          	lea    rcx,[r10+rax*1]
    1a52:	48 ba 7e e2 2f 72 62 	movabs rdx,0x68cbff62722fe27e
    1a59:	ff cb 68 
    1a5c:	48 31 ca             	xor    rdx,rcx
    1a5f:	c4 e3 fb f0 d2 11    	rorx   rdx,rdx,0x11
    1a65:	48 89 c1             	mov    rcx,rax
    1a68:	48 31 f1             	xor    rcx,rsi
    1a6b:	49 b8 4f 7e 72 f9 fd 	movabs r8,0xc855e1fdf9727e4f
    1a72:	e1 55 c8 
    1a75:	49 01 c8             	add    r8,rcx
    1a78:	c4 43 fb f0 c0 21    	rorx   r8,r8,0x21
    1a7e:	48 31 f2             	xor    rdx,rsi
    1a81:	49 01 f8             	add    r8,rdi
    1a84:	4c 89 c1             	mov    rcx,r8
    1a87:	4c 31 d1             	xor    rcx,r10
    1a8a:	48 be ad 46 ed ea c6 	movabs rsi,0x9421cc6eaed46ad
    1a91:	1c 42 09 
    1a94:	48 01 ce             	add    rsi,rcx
    1a97:	c4 e3 fb f0 ce 39    	rorx   rcx,rsi,0x39
    1a9d:	4a 8d 34 02          	lea    rsi,[rdx+r8*1]
    1aa1:	48 bf dc aa aa 63 2b 	movabs rdi,0xa9b83a2b63aaaadc
    1aa8:	3a b8 a9 
    1aab:	48 31 f7             	xor    rdi,rsi
    1aae:	c4 63 fb f0 df 29    	rorx   r11,rdi,0x29
    1ab4:	4d 31 d3             	xor    r11,r10
    1ab7:	48 01 c1             	add    rcx,rax
    1aba:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
    1abe:	48 be 3a 73 25 55 f4 	movabs rsi,0xeaa474f45525733a
    1ac5:	74 a4 ea 
    1ac8:	48 31 c6             	xor    rsi,rax
    1acb:	c4 e3 fb f0 f6 0b    	rorx   rsi,rsi,0xb
    1ad1:	48 89 c8             	mov    rax,rcx
    1ad4:	48 31 d0             	xor    rax,rdx
    1ad7:	48 bf 0b 0f 68 dc 8f 	movabs rdi,0x4a2e578fdc680f0b
    1ade:	57 2e 4a 
    1ae1:	48 01 c7             	add    rdi,rax
    1ae4:	c4 e3 fb f0 ff 1b    	rorx   rdi,rdi,0x1b
    1aea:	48 31 d6             	xor    rsi,rdx
    1aed:	4c 01 c7             	add    rdi,r8
    1af0:	48 89 f8             	mov    rax,rdi
    1af3:	4c 31 d8             	xor    rax,r11
    1af6:	48 ba 69 d7 e2 cd 58 	movabs rdx,0x8b1a9258cde2d769
    1afd:	92 1a 8b 
    1b00:	48 01 c2             	add    rdx,rax
    1b03:	c4 e3 fb f0 c2 3b    	rorx   rax,rdx,0x3b
    1b09:	48 8d 14 3e          	lea    rdx,[rsi+rdi*1]
    1b0d:	49 b8 98 3b a0 46 bd 	movabs r8,0x2b90afbd46a03b98
    1b14:	af 90 2b 
    1b17:	49 31 d0             	xor    r8,rdx
    1b1a:	c4 43 fb f0 d0 25    	rorx   r10,r8,0x25
    1b20:	4d 31 da             	xor    r10,r11
    1b23:	48 01 c8             	add    rax,rcx
    1b26:	49 8d 0c 02          	lea    rcx,[r10+rax*1]
    1b2a:	48 ba f6 03 1b 38 86 	movabs rdx,0x6c7cea86381b03f6
    1b31:	ea 7c 6c 
    1b34:	48 31 ca             	xor    rdx,rcx
    1b37:	c4 e3 fb f0 d2 05    	rorx   rdx,rdx,0x5
    1b3d:	48 89 c1             	mov    rcx,rax
    1b40:	48 31 f1             	xor    rcx,rsi
    1b43:	49 b8 c7 9f 5d bf 21 	movabs r8,0xcc06cd21bf5d9fc7
    1b4a:	cd 06 cc 
    1b4d:	49 01 c8             	add    r8,rcx
    1b50:	c4 43 fb f0 c0 17    	rorx   r8,r8,0x17
    1b56:	48 31 f2             	xor    rdx,rsi
    1b59:	49 01 f8             	add    r8,rdi
    1b5c:	4c 89 c1             	mov    rcx,r8
    1b5f:	4c 31 d1             	xor    rcx,r10
    1b62:	48 be 25 68 d8 b0 ea 	movabs rsi,0xcf307eab0d86825
    1b69:	07 f3 0c 
    1b6c:	48 01 ce             	add    rsi,rcx
    1b6f:	c4 e3 fb f0 ce 3d    	rorx   rcx,rsi,0x3d
    1b75:	4a 8d 34 02          	lea    rsi,[rdx+r8*1]
    1b79:	48 bf 54 cc 95 29 4f 	movabs rdi,0xad69254f2995cc54
    1b80:	25 69 ad 
    1b83:	48 31 f7             	xor    rdi,rsi
    1b86:	c4 63 fb f0 df 33    	rorx   r11,rdi,0x33
    1b8c:	4d 31 d3             	xor    r11,r10
    1b8f:	48 01 c1             	add    rcx,rax
    1b92:	49 8d 04 0b          	lea    rax,[r11+rcx*1]
    1b96:	48 be b2 94 10 1b 18 	movabs rsi,0xee5560181b1094b2
    1b9d:	60 55 ee 
    1ba0:	48 31 c6             	xor    rsi,rax
    1ba3:	c4 e3 fb f0 c6 03    	rorx   rax,rsi,0x3
    1ba9:	48 89 ce             	mov    rsi,rcx
    1bac:	48 31 d6             	xor    rsi,rdx
    1baf:	48 bf 83 30 53 a2 b3 	movabs rdi,0x4ddf42b3a2533083
    1bb6:	42 df 4d 
    1bb9:	48 01 f7             	add    rdi,rsi
    1bbc:	c4 e3 fb f0 ff 23    	rorx   rdi,rdi,0x23
    1bc2:	48 31 d0             	xor    rax,rdx
    1bc5:	4c 01 c7             	add    rdi,r8
    1bc8:	48 89 fa             	mov    rdx,rdi
    1bcb:	4c 31 da             	xor    rdx,r11
    1bce:	48 be e1 f8 cd 93 7c 	movabs rsi,0x8ecb7d7c93cdf8e1
    1bd5:	7d cb 8e 
    1bd8:	48 01 d6             	add    rsi,rdx
    1bdb:	c4 e3 fb f0 f6 2f    	rorx   rsi,rsi,0x2f
    1be1:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    1be5:	49 b8 10 5d 8b 0c e1 	movabs r8,0x2f419ae10c8b5d10
    1bec:	9a 41 2f 
    1bef:	49 31 d0             	xor    r8,rdx
    1bf2:	c4 43 fb f0 d0 21    	rorx   r10,r8,0x21
    1bf8:	4d 31 da             	xor    r10,r11
    1bfb:	48 01 ce             	add    rsi,rcx
    1bfe:	49 8d 0c 32          	lea    rcx,[r10+rsi*1]
    1c02:	48 ba 6e 25 06 fe a9 	movabs rdx,0x702dd5a9fe06256e
    1c09:	d5 2d 70 
    1c0c:	48 31 ca             	xor    rdx,rcx
    1c0f:	c4 e3 fb f0 ca 35    	rorx   rcx,rdx,0x35
    1c15:	48 89 f2             	mov    rdx,rsi
    1c18:	48 31 c2             	xor    rdx,rax
    1c1b:	49 b8 3f c1 48 85 45 	movabs r8,0xcfb7b8458548c13f
    1c22:	b8 b7 cf 
    1c25:	49 01 d0             	add    r8,rdx
    1c28:	c4 43 fb f0 c0 15    	rorx   r8,r8,0x15
    1c2e:	48 31 c1             	xor    rcx,rax
    1c31:	49 01 f8             	add    r8,rdi
    1c34:	4c 89 c0             	mov    rax,r8
    1c37:	4c 31 d0             	xor    rax,r10
    1c3a:	48 ba 9d 89 c3 76 0e 	movabs rdx,0x10a3f30e76c3899d
    1c41:	f3 a3 10 
    1c44:	48 01 c2             	add    rdx,rax
    1c47:	c4 e3 fb f0 c2 2d    	rorx   rax,rdx,0x2d
    1c4d:	4a 8d 14 01          	lea    rdx,[rcx+r8*1]
    1c51:	48 bf cc ed 80 ef 72 	movabs rdi,0xb11a1072ef80edcc
    1c58:	10 1a b1 
    1c5b:	48 31 d7             	xor    rdi,rdx
    1c5e:	c4 e3 fb f0 d7 1b    	rorx   rdx,rdi,0x1b
    1c64:	4c 31 d2             	xor    rdx,r10
    1c67:	48 01 f0             	add    rax,rsi
    1c6a:	48 8d 34 02          	lea    rsi,[rdx+rax*1]
    1c6e:	48 bf 2a b6 fb e0 3b 	movabs rdi,0xf2064b3be0fbb62a
    1c75:	4b 06 f2 
    1c78:	48 31 f7             	xor    rdi,rsi
    1c7b:	c4 63 fb f0 d7 39    	rorx   r10,rdi,0x39
    1c81:	48 89 c6             	mov    rsi,rax
    1c84:	48 31 ce             	xor    rsi,rcx
    1c87:	48 bf fb 51 3e 68 d7 	movabs rdi,0x51902dd7683e51fb
    1c8e:	2d 90 51 
    1c91:	48 01 f7             	add    rdi,rsi
    1c94:	c4 63 fb f0 df 11    	rorx   r11,rdi,0x11
    1c9a:	49 31 ca             	xor    r10,rcx
    1c9d:	4d 01 c3             	add    r11,r8
    1ca0:	4b 8d 1c 1a          	lea    rbx,[r10+r11*1]
    1ca4:	48 b9 cb 12 23 85 a7 	movabs rcx,0x776a3a7852312cb
    1cab:	a3 76 07 
    1cae:	48 31 e9             	xor    rcx,rbp
    1cb1:	4c 01 d9             	add    rcx,r11
    1cb4:	49 31 d3             	xor    r11,rdx
    1cb7:	48 be 59 1a b9 59 a0 	movabs rsi,0x927c68a059b91a59
    1cbe:	68 7c 92 
    1cc1:	4c 01 de             	add    rsi,r11
    1cc4:	c4 e3 fb f0 fe 29    	rorx   rdi,rsi,0x29
    1cca:	48 be 88 7e 76 d2 04 	movabs rsi,0x32f28604d2767e88
    1cd1:	86 f2 32 
    1cd4:	48 31 de             	xor    rsi,rbx
    1cd7:	c4 e3 fb f0 f6 17    	rorx   rsi,rsi,0x17
    1cdd:	48 31 d6             	xor    rsi,rdx
    1ce0:	48 01 c7             	add    rdi,rax
    1ce3:	48 8d 04 3e          	lea    rax,[rsi+rdi*1]
    1ce7:	48 ba e6 46 f1 c3 cd 	movabs rdx,0x73dec0cdc3f146e6
    1cee:	c0 de 73 
    1cf1:	48 31 c2             	xor    rdx,rax
    1cf4:	48 b8 8e 08 e7 e5 5a 	movabs rax,0xa57b7f5ae5e7088e
    1cfb:	7f 7b a5 
    1cfe:	4c 31 f8             	xor    rax,r15
    1d01:	48 01 f8             	add    rax,rdi
    1d04:	4c 31 d7             	xor    rdi,r10
    1d07:	49 b8 b7 e2 33 4b 69 	movabs r8,0xd368a3694b33e2b7
    1d0e:	a3 68 d3 
    1d11:	49 01 f8             	add    r8,rdi
    1d14:	49 bb eb 65 b0 36 a6 	movabs r11,0xe2d49fa636b065eb
    1d1b:	9f d4 e2 
    1d1e:	4d 01 cb             	add    r11,r9
    1d21:	48 bf 8d 9d 35 45 dd 	movabs rdi,0xa1e864dd45359d8d
    1d28:	64 e8 a1 
    1d2b:	4c 01 ef             	add    rdi,r13
    1d2e:	4c 31 df             	xor    rdi,r11
    1d31:	48 31 f8             	xor    rax,rdi
    1d34:	c4 c3 fb f0 f8 0b    	rorx   rdi,r8,0xb
    1d3a:	48 01 f9             	add    rcx,rdi
    1d3d:	48 31 c1             	xor    rcx,rax
    1d40:	48 31 e9             	xor    rcx,rbp
    1d43:	4c 31 f9             	xor    rcx,r15
    1d46:	c4 e3 fb f0 c2 3b    	rorx   rax,rdx,0x3b
    1d4c:	4c 31 e8             	xor    rax,r13
    1d4f:	4c 31 c9             	xor    rcx,r9
    1d52:	4c 31 d0             	xor    rax,r10
    1d55:	48 31 f1             	xor    rcx,rsi
    1d58:	48 ba e7 22 4f 11 c4 	movabs rdx,0xe12119c4114f22e7
    1d5f:	19 21 e1 
    1d62:	48 31 c2             	xor    rdx,rax
    1d65:	48 31 ca             	xor    rdx,rcx
    1d68:	48 8b 44 24 f8       	mov    rax,QWORD PTR [rsp-0x8]
    1d6d:	48 89 10             	mov    QWORD PTR [rax],rdx
    1d70:	b8 02 00 00 00       	mov    eax,0x2
    1d75:	5b                   	pop    rbx
    1d76:	41 5c                	pop    r12
    1d78:	41 5d                	pop    r13
    1d7a:	41 5e                	pop    r14
    1d7c:	41 5f                	pop    r15
    1d7e:	5d                   	pop    rbp
    1d7f:	c3                   	ret
