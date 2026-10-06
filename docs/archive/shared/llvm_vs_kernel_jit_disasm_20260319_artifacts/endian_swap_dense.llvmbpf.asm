
/home/yunwei37/workspace/bpf-benchmark/docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/endian_swap_dense.llvmbpf.bin:     file format binary


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
  1e:	48 8d 88 08 04 00 00 	lea    rcx,[rax+0x408]
  25:	48 39 f1             	cmp    rcx,rsi
  28:	0f 97 c1             	seta   cl
  2b:	08 d1                	or     cl,dl
  2d:	74 03                	je     0x32
  2f:	31 c0                	xor    eax,eax
  31:	c3                   	ret
  32:	0f 38 f0 48 08       	movbe  ecx,DWORD PTR [rax+0x8]
  37:	0f 38 f0 50 0c       	movbe  edx,DWORD PTR [rax+0xc]
  3c:	48 01 ca             	add    rdx,rcx
  3f:	0f 38 f0 48 10       	movbe  ecx,DWORD PTR [rax+0x10]
  44:	0f 38 f0 70 14       	movbe  esi,DWORD PTR [rax+0x14]
  49:	48 01 ce             	add    rsi,rcx
  4c:	48 01 d6             	add    rsi,rdx
  4f:	0f 38 f0 48 18       	movbe  ecx,DWORD PTR [rax+0x18]
  54:	0f 38 f0 50 1c       	movbe  edx,DWORD PTR [rax+0x1c]
  59:	48 01 ca             	add    rdx,rcx
  5c:	0f 38 f0 48 20       	movbe  ecx,DWORD PTR [rax+0x20]
  61:	48 01 d1             	add    rcx,rdx
  64:	48 01 f1             	add    rcx,rsi
  67:	0f 38 f0 50 24       	movbe  edx,DWORD PTR [rax+0x24]
  6c:	0f 38 f0 70 28       	movbe  esi,DWORD PTR [rax+0x28]
  71:	48 01 d6             	add    rsi,rdx
  74:	0f 38 f0 50 2c       	movbe  edx,DWORD PTR [rax+0x2c]
  79:	48 01 f2             	add    rdx,rsi
  7c:	0f 38 f0 70 30       	movbe  esi,DWORD PTR [rax+0x30]
  81:	48 01 d6             	add    rsi,rdx
  84:	48 01 ce             	add    rsi,rcx
  87:	0f 38 f0 48 34       	movbe  ecx,DWORD PTR [rax+0x34]
  8c:	0f 38 f0 50 38       	movbe  edx,DWORD PTR [rax+0x38]
  91:	48 01 ca             	add    rdx,rcx
  94:	0f 38 f0 48 3c       	movbe  ecx,DWORD PTR [rax+0x3c]
  99:	48 01 d1             	add    rcx,rdx
  9c:	0f 38 f0 50 40       	movbe  edx,DWORD PTR [rax+0x40]
  a1:	48 01 ca             	add    rdx,rcx
  a4:	0f 38 f0 48 44       	movbe  ecx,DWORD PTR [rax+0x44]
  a9:	48 01 d1             	add    rcx,rdx
  ac:	48 01 f1             	add    rcx,rsi
  af:	0f 38 f0 50 48       	movbe  edx,DWORD PTR [rax+0x48]
  b4:	0f 38 f0 70 4c       	movbe  esi,DWORD PTR [rax+0x4c]
  b9:	48 01 d6             	add    rsi,rdx
  bc:	0f 38 f0 50 50       	movbe  edx,DWORD PTR [rax+0x50]
  c1:	48 01 f2             	add    rdx,rsi
  c4:	0f 38 f0 70 54       	movbe  esi,DWORD PTR [rax+0x54]
  c9:	48 01 d6             	add    rsi,rdx
  cc:	0f 38 f0 78 58       	movbe  edi,DWORD PTR [rax+0x58]
  d1:	48 01 f7             	add    rdi,rsi
  d4:	0f 38 f0 50 5c       	movbe  edx,DWORD PTR [rax+0x5c]
  d9:	48 01 fa             	add    rdx,rdi
  dc:	48 01 ca             	add    rdx,rcx
  df:	0f 38 f0 48 60       	movbe  ecx,DWORD PTR [rax+0x60]
  e4:	0f 38 f0 70 64       	movbe  esi,DWORD PTR [rax+0x64]
  e9:	48 01 ce             	add    rsi,rcx
  ec:	0f 38 f0 48 68       	movbe  ecx,DWORD PTR [rax+0x68]
  f1:	48 01 f1             	add    rcx,rsi
  f4:	0f 38 f0 70 6c       	movbe  esi,DWORD PTR [rax+0x6c]
  f9:	48 01 ce             	add    rsi,rcx
  fc:	0f 38 f0 48 70       	movbe  ecx,DWORD PTR [rax+0x70]
 101:	48 01 f1             	add    rcx,rsi
 104:	0f 38 f0 70 74       	movbe  esi,DWORD PTR [rax+0x74]
 109:	48 01 ce             	add    rsi,rcx
 10c:	0f 38 f0 48 78       	movbe  ecx,DWORD PTR [rax+0x78]
 111:	48 01 f1             	add    rcx,rsi
 114:	48 01 d1             	add    rcx,rdx
 117:	0f 38 f0 50 7c       	movbe  edx,DWORD PTR [rax+0x7c]
 11c:	0f 38 f0 b0 80 00 00 	movbe  esi,DWORD PTR [rax+0x80]
 123:	00 
 124:	48 01 d6             	add    rsi,rdx
 127:	0f 38 f0 90 84 00 00 	movbe  edx,DWORD PTR [rax+0x84]
 12e:	00 
 12f:	48 01 f2             	add    rdx,rsi
 132:	0f 38 f0 b0 88 00 00 	movbe  esi,DWORD PTR [rax+0x88]
 139:	00 
 13a:	48 01 d6             	add    rsi,rdx
 13d:	0f 38 f0 90 8c 00 00 	movbe  edx,DWORD PTR [rax+0x8c]
 144:	00 
 145:	48 01 f2             	add    rdx,rsi
 148:	0f 38 f0 b0 90 00 00 	movbe  esi,DWORD PTR [rax+0x90]
 14f:	00 
 150:	48 01 d6             	add    rsi,rdx
 153:	0f 38 f0 b8 94 00 00 	movbe  edi,DWORD PTR [rax+0x94]
 15a:	00 
 15b:	48 01 f7             	add    rdi,rsi
 15e:	0f 38 f0 90 98 00 00 	movbe  edx,DWORD PTR [rax+0x98]
 165:	00 
 166:	48 01 fa             	add    rdx,rdi
 169:	48 01 ca             	add    rdx,rcx
 16c:	0f 38 f0 88 9c 00 00 	movbe  ecx,DWORD PTR [rax+0x9c]
 173:	00 
 174:	0f 38 f0 b0 a0 00 00 	movbe  esi,DWORD PTR [rax+0xa0]
 17b:	00 
 17c:	48 01 ce             	add    rsi,rcx
 17f:	0f 38 f0 88 a4 00 00 	movbe  ecx,DWORD PTR [rax+0xa4]
 186:	00 
 187:	48 01 f1             	add    rcx,rsi
 18a:	0f 38 f0 b0 a8 00 00 	movbe  esi,DWORD PTR [rax+0xa8]
 191:	00 
 192:	48 01 ce             	add    rsi,rcx
 195:	0f 38 f0 88 ac 00 00 	movbe  ecx,DWORD PTR [rax+0xac]
 19c:	00 
 19d:	48 01 f1             	add    rcx,rsi
 1a0:	0f 38 f0 b0 b0 00 00 	movbe  esi,DWORD PTR [rax+0xb0]
 1a7:	00 
 1a8:	48 01 ce             	add    rsi,rcx
 1ab:	0f 38 f0 88 b4 00 00 	movbe  ecx,DWORD PTR [rax+0xb4]
 1b2:	00 
 1b3:	48 01 f1             	add    rcx,rsi
 1b6:	0f 38 f0 b0 b8 00 00 	movbe  esi,DWORD PTR [rax+0xb8]
 1bd:	00 
 1be:	48 01 ce             	add    rsi,rcx
 1c1:	0f 38 f0 88 bc 00 00 	movbe  ecx,DWORD PTR [rax+0xbc]
 1c8:	00 
 1c9:	48 01 f1             	add    rcx,rsi
 1cc:	48 01 d1             	add    rcx,rdx
 1cf:	0f 38 f0 90 c0 00 00 	movbe  edx,DWORD PTR [rax+0xc0]
 1d6:	00 
 1d7:	0f 38 f0 b0 c4 00 00 	movbe  esi,DWORD PTR [rax+0xc4]
 1de:	00 
 1df:	48 01 d6             	add    rsi,rdx
 1e2:	0f 38 f0 90 c8 00 00 	movbe  edx,DWORD PTR [rax+0xc8]
 1e9:	00 
 1ea:	48 01 f2             	add    rdx,rsi
 1ed:	0f 38 f0 b0 cc 00 00 	movbe  esi,DWORD PTR [rax+0xcc]
 1f4:	00 
 1f5:	48 01 d6             	add    rsi,rdx
 1f8:	0f 38 f0 90 d0 00 00 	movbe  edx,DWORD PTR [rax+0xd0]
 1ff:	00 
 200:	48 01 f2             	add    rdx,rsi
 203:	0f 38 f0 b0 d4 00 00 	movbe  esi,DWORD PTR [rax+0xd4]
 20a:	00 
 20b:	48 01 d6             	add    rsi,rdx
 20e:	0f 38 f0 90 d8 00 00 	movbe  edx,DWORD PTR [rax+0xd8]
 215:	00 
 216:	48 01 f2             	add    rdx,rsi
 219:	0f 38 f0 b0 dc 00 00 	movbe  esi,DWORD PTR [rax+0xdc]
 220:	00 
 221:	48 01 d6             	add    rsi,rdx
 224:	0f 38 f0 b8 e0 00 00 	movbe  edi,DWORD PTR [rax+0xe0]
 22b:	00 
 22c:	48 01 f7             	add    rdi,rsi
 22f:	0f 38 f0 90 e4 00 00 	movbe  edx,DWORD PTR [rax+0xe4]
 236:	00 
 237:	48 01 fa             	add    rdx,rdi
 23a:	48 01 ca             	add    rdx,rcx
 23d:	0f 38 f0 88 e8 00 00 	movbe  ecx,DWORD PTR [rax+0xe8]
 244:	00 
 245:	0f 38 f0 b0 ec 00 00 	movbe  esi,DWORD PTR [rax+0xec]
 24c:	00 
 24d:	48 01 ce             	add    rsi,rcx
 250:	0f 38 f0 88 f0 00 00 	movbe  ecx,DWORD PTR [rax+0xf0]
 257:	00 
 258:	48 01 f1             	add    rcx,rsi
 25b:	0f 38 f0 b0 f4 00 00 	movbe  esi,DWORD PTR [rax+0xf4]
 262:	00 
 263:	48 01 ce             	add    rsi,rcx
 266:	0f 38 f0 88 f8 00 00 	movbe  ecx,DWORD PTR [rax+0xf8]
 26d:	00 
 26e:	48 01 f1             	add    rcx,rsi
 271:	0f 38 f0 b0 fc 00 00 	movbe  esi,DWORD PTR [rax+0xfc]
 278:	00 
 279:	48 01 ce             	add    rsi,rcx
 27c:	0f 38 f0 88 00 01 00 	movbe  ecx,DWORD PTR [rax+0x100]
 283:	00 
 284:	48 01 f1             	add    rcx,rsi
 287:	0f 38 f0 b0 04 01 00 	movbe  esi,DWORD PTR [rax+0x104]
 28e:	00 
 28f:	48 01 ce             	add    rsi,rcx
 292:	0f 38 f0 88 08 01 00 	movbe  ecx,DWORD PTR [rax+0x108]
 299:	00 
 29a:	48 01 f1             	add    rcx,rsi
 29d:	0f 38 f0 b0 0c 01 00 	movbe  esi,DWORD PTR [rax+0x10c]
 2a4:	00 
 2a5:	48 01 ce             	add    rsi,rcx
 2a8:	0f 38 f0 88 10 01 00 	movbe  ecx,DWORD PTR [rax+0x110]
 2af:	00 
 2b0:	48 01 f1             	add    rcx,rsi
 2b3:	48 01 d1             	add    rcx,rdx
 2b6:	0f 38 f0 90 14 01 00 	movbe  edx,DWORD PTR [rax+0x114]
 2bd:	00 
 2be:	0f 38 f0 b0 18 01 00 	movbe  esi,DWORD PTR [rax+0x118]
 2c5:	00 
 2c6:	48 01 d6             	add    rsi,rdx
 2c9:	0f 38 f0 90 1c 01 00 	movbe  edx,DWORD PTR [rax+0x11c]
 2d0:	00 
 2d1:	48 01 f2             	add    rdx,rsi
 2d4:	0f 38 f0 b0 20 01 00 	movbe  esi,DWORD PTR [rax+0x120]
 2db:	00 
 2dc:	48 01 d6             	add    rsi,rdx
 2df:	0f 38 f0 90 24 01 00 	movbe  edx,DWORD PTR [rax+0x124]
 2e6:	00 
 2e7:	48 01 f2             	add    rdx,rsi
 2ea:	0f 38 f0 b0 28 01 00 	movbe  esi,DWORD PTR [rax+0x128]
 2f1:	00 
 2f2:	48 01 d6             	add    rsi,rdx
 2f5:	0f 38 f0 90 2c 01 00 	movbe  edx,DWORD PTR [rax+0x12c]
 2fc:	00 
 2fd:	48 01 f2             	add    rdx,rsi
 300:	0f 38 f0 b0 30 01 00 	movbe  esi,DWORD PTR [rax+0x130]
 307:	00 
 308:	48 01 d6             	add    rsi,rdx
 30b:	0f 38 f0 90 34 01 00 	movbe  edx,DWORD PTR [rax+0x134]
 312:	00 
 313:	48 01 f2             	add    rdx,rsi
 316:	0f 38 f0 b0 38 01 00 	movbe  esi,DWORD PTR [rax+0x138]
 31d:	00 
 31e:	48 01 d6             	add    rsi,rdx
 321:	0f 38 f0 b8 3c 01 00 	movbe  edi,DWORD PTR [rax+0x13c]
 328:	00 
 329:	48 01 f7             	add    rdi,rsi
 32c:	0f 38 f0 90 40 01 00 	movbe  edx,DWORD PTR [rax+0x140]
 333:	00 
 334:	48 01 fa             	add    rdx,rdi
 337:	48 01 ca             	add    rdx,rcx
 33a:	0f 38 f0 88 44 01 00 	movbe  ecx,DWORD PTR [rax+0x144]
 341:	00 
 342:	0f 38 f0 b0 48 01 00 	movbe  esi,DWORD PTR [rax+0x148]
 349:	00 
 34a:	48 01 ce             	add    rsi,rcx
 34d:	0f 38 f0 88 4c 01 00 	movbe  ecx,DWORD PTR [rax+0x14c]
 354:	00 
 355:	48 01 f1             	add    rcx,rsi
 358:	0f 38 f0 b0 50 01 00 	movbe  esi,DWORD PTR [rax+0x150]
 35f:	00 
 360:	48 01 ce             	add    rsi,rcx
 363:	0f 38 f0 88 54 01 00 	movbe  ecx,DWORD PTR [rax+0x154]
 36a:	00 
 36b:	48 01 f1             	add    rcx,rsi
 36e:	0f 38 f0 b0 58 01 00 	movbe  esi,DWORD PTR [rax+0x158]
 375:	00 
 376:	48 01 ce             	add    rsi,rcx
 379:	0f 38 f0 88 5c 01 00 	movbe  ecx,DWORD PTR [rax+0x15c]
 380:	00 
 381:	48 01 f1             	add    rcx,rsi
 384:	0f 38 f0 b0 60 01 00 	movbe  esi,DWORD PTR [rax+0x160]
 38b:	00 
 38c:	48 01 ce             	add    rsi,rcx
 38f:	0f 38 f0 88 64 01 00 	movbe  ecx,DWORD PTR [rax+0x164]
 396:	00 
 397:	48 01 f1             	add    rcx,rsi
 39a:	0f 38 f0 b0 68 01 00 	movbe  esi,DWORD PTR [rax+0x168]
 3a1:	00 
 3a2:	48 01 ce             	add    rsi,rcx
 3a5:	0f 38 f0 88 6c 01 00 	movbe  ecx,DWORD PTR [rax+0x16c]
 3ac:	00 
 3ad:	48 01 f1             	add    rcx,rsi
 3b0:	0f 38 f0 b0 70 01 00 	movbe  esi,DWORD PTR [rax+0x170]
 3b7:	00 
 3b8:	48 01 ce             	add    rsi,rcx
 3bb:	0f 38 f0 88 74 01 00 	movbe  ecx,DWORD PTR [rax+0x174]
 3c2:	00 
 3c3:	48 01 f1             	add    rcx,rsi
 3c6:	48 01 d1             	add    rcx,rdx
 3c9:	0f 38 f0 90 78 01 00 	movbe  edx,DWORD PTR [rax+0x178]
 3d0:	00 
 3d1:	0f 38 f0 b0 7c 01 00 	movbe  esi,DWORD PTR [rax+0x17c]
 3d8:	00 
 3d9:	48 01 d6             	add    rsi,rdx
 3dc:	0f 38 f0 90 80 01 00 	movbe  edx,DWORD PTR [rax+0x180]
 3e3:	00 
 3e4:	48 01 f2             	add    rdx,rsi
 3e7:	0f 38 f0 b0 84 01 00 	movbe  esi,DWORD PTR [rax+0x184]
 3ee:	00 
 3ef:	48 01 d6             	add    rsi,rdx
 3f2:	0f 38 f0 90 88 01 00 	movbe  edx,DWORD PTR [rax+0x188]
 3f9:	00 
 3fa:	48 01 f2             	add    rdx,rsi
 3fd:	0f 38 f0 b0 8c 01 00 	movbe  esi,DWORD PTR [rax+0x18c]
 404:	00 
 405:	48 01 d6             	add    rsi,rdx
 408:	0f 38 f0 90 90 01 00 	movbe  edx,DWORD PTR [rax+0x190]
 40f:	00 
 410:	48 01 f2             	add    rdx,rsi
 413:	0f 38 f0 b0 94 01 00 	movbe  esi,DWORD PTR [rax+0x194]
 41a:	00 
 41b:	48 01 d6             	add    rsi,rdx
 41e:	0f 38 f0 90 98 01 00 	movbe  edx,DWORD PTR [rax+0x198]
 425:	00 
 426:	48 01 f2             	add    rdx,rsi
 429:	0f 38 f0 b0 9c 01 00 	movbe  esi,DWORD PTR [rax+0x19c]
 430:	00 
 431:	48 01 d6             	add    rsi,rdx
 434:	0f 38 f0 90 a0 01 00 	movbe  edx,DWORD PTR [rax+0x1a0]
 43b:	00 
 43c:	48 01 f2             	add    rdx,rsi
 43f:	0f 38 f0 b0 a4 01 00 	movbe  esi,DWORD PTR [rax+0x1a4]
 446:	00 
 447:	48 01 d6             	add    rsi,rdx
 44a:	0f 38 f0 b8 a8 01 00 	movbe  edi,DWORD PTR [rax+0x1a8]
 451:	00 
 452:	48 01 f7             	add    rdi,rsi
 455:	0f 38 f0 90 ac 01 00 	movbe  edx,DWORD PTR [rax+0x1ac]
 45c:	00 
 45d:	48 01 fa             	add    rdx,rdi
 460:	48 01 ca             	add    rdx,rcx
 463:	0f 38 f0 88 b0 01 00 	movbe  ecx,DWORD PTR [rax+0x1b0]
 46a:	00 
 46b:	0f 38 f0 b0 b4 01 00 	movbe  esi,DWORD PTR [rax+0x1b4]
 472:	00 
 473:	48 01 ce             	add    rsi,rcx
 476:	0f 38 f0 88 b8 01 00 	movbe  ecx,DWORD PTR [rax+0x1b8]
 47d:	00 
 47e:	48 01 f1             	add    rcx,rsi
 481:	0f 38 f0 b0 bc 01 00 	movbe  esi,DWORD PTR [rax+0x1bc]
 488:	00 
 489:	48 01 ce             	add    rsi,rcx
 48c:	0f 38 f0 88 c0 01 00 	movbe  ecx,DWORD PTR [rax+0x1c0]
 493:	00 
 494:	48 01 f1             	add    rcx,rsi
 497:	0f 38 f0 b0 c4 01 00 	movbe  esi,DWORD PTR [rax+0x1c4]
 49e:	00 
 49f:	48 01 ce             	add    rsi,rcx
 4a2:	0f 38 f0 88 c8 01 00 	movbe  ecx,DWORD PTR [rax+0x1c8]
 4a9:	00 
 4aa:	48 01 f1             	add    rcx,rsi
 4ad:	0f 38 f0 b0 cc 01 00 	movbe  esi,DWORD PTR [rax+0x1cc]
 4b4:	00 
 4b5:	48 01 ce             	add    rsi,rcx
 4b8:	0f 38 f0 88 d0 01 00 	movbe  ecx,DWORD PTR [rax+0x1d0]
 4bf:	00 
 4c0:	48 01 f1             	add    rcx,rsi
 4c3:	0f 38 f0 b0 d4 01 00 	movbe  esi,DWORD PTR [rax+0x1d4]
 4ca:	00 
 4cb:	48 01 ce             	add    rsi,rcx
 4ce:	0f 38 f0 88 d8 01 00 	movbe  ecx,DWORD PTR [rax+0x1d8]
 4d5:	00 
 4d6:	48 01 f1             	add    rcx,rsi
 4d9:	0f 38 f0 b0 dc 01 00 	movbe  esi,DWORD PTR [rax+0x1dc]
 4e0:	00 
 4e1:	48 01 ce             	add    rsi,rcx
 4e4:	0f 38 f0 88 e0 01 00 	movbe  ecx,DWORD PTR [rax+0x1e0]
 4eb:	00 
 4ec:	48 01 f1             	add    rcx,rsi
 4ef:	0f 38 f0 b0 e4 01 00 	movbe  esi,DWORD PTR [rax+0x1e4]
 4f6:	00 
 4f7:	48 01 ce             	add    rsi,rcx
 4fa:	0f 38 f0 88 e8 01 00 	movbe  ecx,DWORD PTR [rax+0x1e8]
 501:	00 
 502:	48 01 f1             	add    rcx,rsi
 505:	48 01 d1             	add    rcx,rdx
 508:	0f 38 f0 90 ec 01 00 	movbe  edx,DWORD PTR [rax+0x1ec]
 50f:	00 
 510:	0f 38 f0 b0 f0 01 00 	movbe  esi,DWORD PTR [rax+0x1f0]
 517:	00 
 518:	48 01 d6             	add    rsi,rdx
 51b:	0f 38 f0 90 f4 01 00 	movbe  edx,DWORD PTR [rax+0x1f4]
 522:	00 
 523:	48 01 f2             	add    rdx,rsi
 526:	0f 38 f0 b0 f8 01 00 	movbe  esi,DWORD PTR [rax+0x1f8]
 52d:	00 
 52e:	48 01 d6             	add    rsi,rdx
 531:	0f 38 f0 90 fc 01 00 	movbe  edx,DWORD PTR [rax+0x1fc]
 538:	00 
 539:	48 01 f2             	add    rdx,rsi
 53c:	0f 38 f0 b0 00 02 00 	movbe  esi,DWORD PTR [rax+0x200]
 543:	00 
 544:	48 01 d6             	add    rsi,rdx
 547:	0f 38 f0 90 04 02 00 	movbe  edx,DWORD PTR [rax+0x204]
 54e:	00 
 54f:	48 01 f2             	add    rdx,rsi
 552:	0f 38 f0 b0 08 02 00 	movbe  esi,DWORD PTR [rax+0x208]
 559:	00 
 55a:	48 01 d6             	add    rsi,rdx
 55d:	0f 38 f0 90 0c 02 00 	movbe  edx,DWORD PTR [rax+0x20c]
 564:	00 
 565:	48 01 f2             	add    rdx,rsi
 568:	0f 38 f0 b0 10 02 00 	movbe  esi,DWORD PTR [rax+0x210]
 56f:	00 
 570:	48 01 d6             	add    rsi,rdx
 573:	0f 38 f0 90 14 02 00 	movbe  edx,DWORD PTR [rax+0x214]
 57a:	00 
 57b:	48 01 f2             	add    rdx,rsi
 57e:	0f 38 f0 b0 18 02 00 	movbe  esi,DWORD PTR [rax+0x218]
 585:	00 
 586:	48 01 d6             	add    rsi,rdx
 589:	0f 38 f0 90 1c 02 00 	movbe  edx,DWORD PTR [rax+0x21c]
 590:	00 
 591:	48 01 f2             	add    rdx,rsi
 594:	0f 38 f0 b0 20 02 00 	movbe  esi,DWORD PTR [rax+0x220]
 59b:	00 
 59c:	48 01 d6             	add    rsi,rdx
 59f:	0f 38 f0 b8 24 02 00 	movbe  edi,DWORD PTR [rax+0x224]
 5a6:	00 
 5a7:	48 01 f7             	add    rdi,rsi
 5aa:	0f 38 f0 90 28 02 00 	movbe  edx,DWORD PTR [rax+0x228]
 5b1:	00 
 5b2:	48 01 fa             	add    rdx,rdi
 5b5:	48 01 ca             	add    rdx,rcx
 5b8:	0f 38 f0 88 2c 02 00 	movbe  ecx,DWORD PTR [rax+0x22c]
 5bf:	00 
 5c0:	0f 38 f0 b0 30 02 00 	movbe  esi,DWORD PTR [rax+0x230]
 5c7:	00 
 5c8:	48 01 ce             	add    rsi,rcx
 5cb:	0f 38 f0 88 34 02 00 	movbe  ecx,DWORD PTR [rax+0x234]
 5d2:	00 
 5d3:	48 01 f1             	add    rcx,rsi
 5d6:	0f 38 f0 b0 38 02 00 	movbe  esi,DWORD PTR [rax+0x238]
 5dd:	00 
 5de:	48 01 ce             	add    rsi,rcx
 5e1:	0f 38 f0 88 3c 02 00 	movbe  ecx,DWORD PTR [rax+0x23c]
 5e8:	00 
 5e9:	48 01 f1             	add    rcx,rsi
 5ec:	0f 38 f0 b0 40 02 00 	movbe  esi,DWORD PTR [rax+0x240]
 5f3:	00 
 5f4:	48 01 ce             	add    rsi,rcx
 5f7:	0f 38 f0 88 44 02 00 	movbe  ecx,DWORD PTR [rax+0x244]
 5fe:	00 
 5ff:	48 01 f1             	add    rcx,rsi
 602:	0f 38 f0 b0 48 02 00 	movbe  esi,DWORD PTR [rax+0x248]
 609:	00 
 60a:	48 01 ce             	add    rsi,rcx
 60d:	0f 38 f0 88 4c 02 00 	movbe  ecx,DWORD PTR [rax+0x24c]
 614:	00 
 615:	48 01 f1             	add    rcx,rsi
 618:	0f 38 f0 b0 50 02 00 	movbe  esi,DWORD PTR [rax+0x250]
 61f:	00 
 620:	48 01 ce             	add    rsi,rcx
 623:	0f 38 f0 88 54 02 00 	movbe  ecx,DWORD PTR [rax+0x254]
 62a:	00 
 62b:	48 01 f1             	add    rcx,rsi
 62e:	0f 38 f0 b0 58 02 00 	movbe  esi,DWORD PTR [rax+0x258]
 635:	00 
 636:	48 01 ce             	add    rsi,rcx
 639:	0f 38 f0 88 5c 02 00 	movbe  ecx,DWORD PTR [rax+0x25c]
 640:	00 
 641:	48 01 f1             	add    rcx,rsi
 644:	0f 38 f0 b0 60 02 00 	movbe  esi,DWORD PTR [rax+0x260]
 64b:	00 
 64c:	48 01 ce             	add    rsi,rcx
 64f:	0f 38 f0 88 64 02 00 	movbe  ecx,DWORD PTR [rax+0x264]
 656:	00 
 657:	48 01 f1             	add    rcx,rsi
 65a:	0f 38 f0 b0 68 02 00 	movbe  esi,DWORD PTR [rax+0x268]
 661:	00 
 662:	48 01 ce             	add    rsi,rcx
 665:	0f 38 f0 88 6c 02 00 	movbe  ecx,DWORD PTR [rax+0x26c]
 66c:	00 
 66d:	48 01 f1             	add    rcx,rsi
 670:	48 01 d1             	add    rcx,rdx
 673:	0f 38 f0 90 70 02 00 	movbe  edx,DWORD PTR [rax+0x270]
 67a:	00 
 67b:	0f 38 f0 b0 74 02 00 	movbe  esi,DWORD PTR [rax+0x274]
 682:	00 
 683:	48 01 d6             	add    rsi,rdx
 686:	0f 38 f0 90 78 02 00 	movbe  edx,DWORD PTR [rax+0x278]
 68d:	00 
 68e:	48 01 f2             	add    rdx,rsi
 691:	0f 38 f0 b0 7c 02 00 	movbe  esi,DWORD PTR [rax+0x27c]
 698:	00 
 699:	48 01 d6             	add    rsi,rdx
 69c:	0f 38 f0 90 80 02 00 	movbe  edx,DWORD PTR [rax+0x280]
 6a3:	00 
 6a4:	48 01 f2             	add    rdx,rsi
 6a7:	0f 38 f0 b0 84 02 00 	movbe  esi,DWORD PTR [rax+0x284]
 6ae:	00 
 6af:	48 01 d6             	add    rsi,rdx
 6b2:	0f 38 f0 90 88 02 00 	movbe  edx,DWORD PTR [rax+0x288]
 6b9:	00 
 6ba:	48 01 f2             	add    rdx,rsi
 6bd:	0f 38 f0 b0 8c 02 00 	movbe  esi,DWORD PTR [rax+0x28c]
 6c4:	00 
 6c5:	48 01 d6             	add    rsi,rdx
 6c8:	0f 38 f0 90 90 02 00 	movbe  edx,DWORD PTR [rax+0x290]
 6cf:	00 
 6d0:	48 01 f2             	add    rdx,rsi
 6d3:	0f 38 f0 b0 94 02 00 	movbe  esi,DWORD PTR [rax+0x294]
 6da:	00 
 6db:	48 01 d6             	add    rsi,rdx
 6de:	0f 38 f0 90 98 02 00 	movbe  edx,DWORD PTR [rax+0x298]
 6e5:	00 
 6e6:	48 01 f2             	add    rdx,rsi
 6e9:	0f 38 f0 b0 9c 02 00 	movbe  esi,DWORD PTR [rax+0x29c]
 6f0:	00 
 6f1:	48 01 d6             	add    rsi,rdx
 6f4:	0f 38 f0 90 a0 02 00 	movbe  edx,DWORD PTR [rax+0x2a0]
 6fb:	00 
 6fc:	48 01 f2             	add    rdx,rsi
 6ff:	0f 38 f0 b0 a4 02 00 	movbe  esi,DWORD PTR [rax+0x2a4]
 706:	00 
 707:	48 01 d6             	add    rsi,rdx
 70a:	0f 38 f0 90 a8 02 00 	movbe  edx,DWORD PTR [rax+0x2a8]
 711:	00 
 712:	48 01 f2             	add    rdx,rsi
 715:	0f 38 f0 b0 ac 02 00 	movbe  esi,DWORD PTR [rax+0x2ac]
 71c:	00 
 71d:	48 01 d6             	add    rsi,rdx
 720:	0f 38 f0 b8 b0 02 00 	movbe  edi,DWORD PTR [rax+0x2b0]
 727:	00 
 728:	48 01 f7             	add    rdi,rsi
 72b:	0f 38 f0 90 b4 02 00 	movbe  edx,DWORD PTR [rax+0x2b4]
 732:	00 
 733:	48 01 fa             	add    rdx,rdi
 736:	48 01 ca             	add    rdx,rcx
 739:	0f 38 f0 88 b8 02 00 	movbe  ecx,DWORD PTR [rax+0x2b8]
 740:	00 
 741:	0f 38 f0 b0 bc 02 00 	movbe  esi,DWORD PTR [rax+0x2bc]
 748:	00 
 749:	48 01 ce             	add    rsi,rcx
 74c:	0f 38 f0 88 c0 02 00 	movbe  ecx,DWORD PTR [rax+0x2c0]
 753:	00 
 754:	48 01 f1             	add    rcx,rsi
 757:	0f 38 f0 b0 c4 02 00 	movbe  esi,DWORD PTR [rax+0x2c4]
 75e:	00 
 75f:	48 01 ce             	add    rsi,rcx
 762:	0f 38 f0 88 c8 02 00 	movbe  ecx,DWORD PTR [rax+0x2c8]
 769:	00 
 76a:	48 01 f1             	add    rcx,rsi
 76d:	0f 38 f0 b0 cc 02 00 	movbe  esi,DWORD PTR [rax+0x2cc]
 774:	00 
 775:	48 01 ce             	add    rsi,rcx
 778:	0f 38 f0 88 d0 02 00 	movbe  ecx,DWORD PTR [rax+0x2d0]
 77f:	00 
 780:	48 01 f1             	add    rcx,rsi
 783:	0f 38 f0 b0 d4 02 00 	movbe  esi,DWORD PTR [rax+0x2d4]
 78a:	00 
 78b:	48 01 ce             	add    rsi,rcx
 78e:	0f 38 f0 88 d8 02 00 	movbe  ecx,DWORD PTR [rax+0x2d8]
 795:	00 
 796:	48 01 f1             	add    rcx,rsi
 799:	0f 38 f0 b0 dc 02 00 	movbe  esi,DWORD PTR [rax+0x2dc]
 7a0:	00 
 7a1:	48 01 ce             	add    rsi,rcx
 7a4:	0f 38 f0 88 e0 02 00 	movbe  ecx,DWORD PTR [rax+0x2e0]
 7ab:	00 
 7ac:	48 01 f1             	add    rcx,rsi
 7af:	0f 38 f0 b0 e4 02 00 	movbe  esi,DWORD PTR [rax+0x2e4]
 7b6:	00 
 7b7:	48 01 ce             	add    rsi,rcx
 7ba:	0f 38 f0 88 e8 02 00 	movbe  ecx,DWORD PTR [rax+0x2e8]
 7c1:	00 
 7c2:	48 01 f1             	add    rcx,rsi
 7c5:	0f 38 f0 b0 ec 02 00 	movbe  esi,DWORD PTR [rax+0x2ec]
 7cc:	00 
 7cd:	48 01 ce             	add    rsi,rcx
 7d0:	0f 38 f0 88 f0 02 00 	movbe  ecx,DWORD PTR [rax+0x2f0]
 7d7:	00 
 7d8:	48 01 f1             	add    rcx,rsi
 7db:	0f 38 f0 b0 f4 02 00 	movbe  esi,DWORD PTR [rax+0x2f4]
 7e2:	00 
 7e3:	48 01 ce             	add    rsi,rcx
 7e6:	0f 38 f0 88 f8 02 00 	movbe  ecx,DWORD PTR [rax+0x2f8]
 7ed:	00 
 7ee:	48 01 f1             	add    rcx,rsi
 7f1:	0f 38 f0 b0 fc 02 00 	movbe  esi,DWORD PTR [rax+0x2fc]
 7f8:	00 
 7f9:	48 01 ce             	add    rsi,rcx
 7fc:	0f 38 f0 88 00 03 00 	movbe  ecx,DWORD PTR [rax+0x300]
 803:	00 
 804:	48 01 f1             	add    rcx,rsi
 807:	48 01 d1             	add    rcx,rdx
 80a:	0f 38 f0 90 04 03 00 	movbe  edx,DWORD PTR [rax+0x304]
 811:	00 
 812:	0f 38 f0 b0 08 03 00 	movbe  esi,DWORD PTR [rax+0x308]
 819:	00 
 81a:	48 01 d6             	add    rsi,rdx
 81d:	0f 38 f0 90 0c 03 00 	movbe  edx,DWORD PTR [rax+0x30c]
 824:	00 
 825:	48 01 f2             	add    rdx,rsi
 828:	0f 38 f0 b0 10 03 00 	movbe  esi,DWORD PTR [rax+0x310]
 82f:	00 
 830:	48 01 d6             	add    rsi,rdx
 833:	0f 38 f0 90 14 03 00 	movbe  edx,DWORD PTR [rax+0x314]
 83a:	00 
 83b:	48 01 f2             	add    rdx,rsi
 83e:	0f 38 f0 b0 18 03 00 	movbe  esi,DWORD PTR [rax+0x318]
 845:	00 
 846:	48 01 d6             	add    rsi,rdx
 849:	0f 38 f0 90 1c 03 00 	movbe  edx,DWORD PTR [rax+0x31c]
 850:	00 
 851:	48 01 f2             	add    rdx,rsi
 854:	0f 38 f0 b0 20 03 00 	movbe  esi,DWORD PTR [rax+0x320]
 85b:	00 
 85c:	48 01 d6             	add    rsi,rdx
 85f:	0f 38 f0 90 24 03 00 	movbe  edx,DWORD PTR [rax+0x324]
 866:	00 
 867:	48 01 f2             	add    rdx,rsi
 86a:	0f 38 f0 b0 28 03 00 	movbe  esi,DWORD PTR [rax+0x328]
 871:	00 
 872:	48 01 d6             	add    rsi,rdx
 875:	0f 38 f0 90 2c 03 00 	movbe  edx,DWORD PTR [rax+0x32c]
 87c:	00 
 87d:	48 01 f2             	add    rdx,rsi
 880:	0f 38 f0 b0 30 03 00 	movbe  esi,DWORD PTR [rax+0x330]
 887:	00 
 888:	48 01 d6             	add    rsi,rdx
 88b:	0f 38 f0 90 34 03 00 	movbe  edx,DWORD PTR [rax+0x334]
 892:	00 
 893:	48 01 f2             	add    rdx,rsi
 896:	0f 38 f0 b0 38 03 00 	movbe  esi,DWORD PTR [rax+0x338]
 89d:	00 
 89e:	48 01 d6             	add    rsi,rdx
 8a1:	0f 38 f0 90 3c 03 00 	movbe  edx,DWORD PTR [rax+0x33c]
 8a8:	00 
 8a9:	48 01 f2             	add    rdx,rsi
 8ac:	0f 38 f0 b0 40 03 00 	movbe  esi,DWORD PTR [rax+0x340]
 8b3:	00 
 8b4:	48 01 d6             	add    rsi,rdx
 8b7:	0f 38 f0 90 44 03 00 	movbe  edx,DWORD PTR [rax+0x344]
 8be:	00 
 8bf:	48 01 f2             	add    rdx,rsi
 8c2:	0f 38 f0 b0 48 03 00 	movbe  esi,DWORD PTR [rax+0x348]
 8c9:	00 
 8ca:	48 01 d6             	add    rsi,rdx
 8cd:	0f 38 f0 b8 4c 03 00 	movbe  edi,DWORD PTR [rax+0x34c]
 8d4:	00 
 8d5:	48 01 f7             	add    rdi,rsi
 8d8:	0f 38 f0 90 50 03 00 	movbe  edx,DWORD PTR [rax+0x350]
 8df:	00 
 8e0:	48 01 fa             	add    rdx,rdi
 8e3:	48 01 ca             	add    rdx,rcx
 8e6:	0f 38 f0 88 54 03 00 	movbe  ecx,DWORD PTR [rax+0x354]
 8ed:	00 
 8ee:	0f 38 f0 b0 58 03 00 	movbe  esi,DWORD PTR [rax+0x358]
 8f5:	00 
 8f6:	48 01 ce             	add    rsi,rcx
 8f9:	0f 38 f0 88 5c 03 00 	movbe  ecx,DWORD PTR [rax+0x35c]
 900:	00 
 901:	48 01 f1             	add    rcx,rsi
 904:	0f 38 f0 b0 60 03 00 	movbe  esi,DWORD PTR [rax+0x360]
 90b:	00 
 90c:	48 01 ce             	add    rsi,rcx
 90f:	0f 38 f0 88 64 03 00 	movbe  ecx,DWORD PTR [rax+0x364]
 916:	00 
 917:	48 01 f1             	add    rcx,rsi
 91a:	0f 38 f0 b0 68 03 00 	movbe  esi,DWORD PTR [rax+0x368]
 921:	00 
 922:	48 01 ce             	add    rsi,rcx
 925:	0f 38 f0 88 6c 03 00 	movbe  ecx,DWORD PTR [rax+0x36c]
 92c:	00 
 92d:	48 01 f1             	add    rcx,rsi
 930:	0f 38 f0 b0 70 03 00 	movbe  esi,DWORD PTR [rax+0x370]
 937:	00 
 938:	48 01 ce             	add    rsi,rcx
 93b:	0f 38 f0 88 74 03 00 	movbe  ecx,DWORD PTR [rax+0x374]
 942:	00 
 943:	48 01 f1             	add    rcx,rsi
 946:	0f 38 f0 b0 78 03 00 	movbe  esi,DWORD PTR [rax+0x378]
 94d:	00 
 94e:	48 01 ce             	add    rsi,rcx
 951:	0f 38 f0 88 7c 03 00 	movbe  ecx,DWORD PTR [rax+0x37c]
 958:	00 
 959:	48 01 f1             	add    rcx,rsi
 95c:	0f 38 f0 b0 80 03 00 	movbe  esi,DWORD PTR [rax+0x380]
 963:	00 
 964:	48 01 ce             	add    rsi,rcx
 967:	0f 38 f0 88 84 03 00 	movbe  ecx,DWORD PTR [rax+0x384]
 96e:	00 
 96f:	48 01 f1             	add    rcx,rsi
 972:	0f 38 f0 b0 88 03 00 	movbe  esi,DWORD PTR [rax+0x388]
 979:	00 
 97a:	48 01 ce             	add    rsi,rcx
 97d:	0f 38 f0 88 8c 03 00 	movbe  ecx,DWORD PTR [rax+0x38c]
 984:	00 
 985:	48 01 f1             	add    rcx,rsi
 988:	0f 38 f0 b0 90 03 00 	movbe  esi,DWORD PTR [rax+0x390]
 98f:	00 
 990:	48 01 ce             	add    rsi,rcx
 993:	0f 38 f0 88 94 03 00 	movbe  ecx,DWORD PTR [rax+0x394]
 99a:	00 
 99b:	48 01 f1             	add    rcx,rsi
 99e:	0f 38 f0 b0 98 03 00 	movbe  esi,DWORD PTR [rax+0x398]
 9a5:	00 
 9a6:	48 01 ce             	add    rsi,rcx
 9a9:	0f 38 f0 88 9c 03 00 	movbe  ecx,DWORD PTR [rax+0x39c]
 9b0:	00 
 9b1:	48 01 f1             	add    rcx,rsi
 9b4:	0f 38 f0 b0 a0 03 00 	movbe  esi,DWORD PTR [rax+0x3a0]
 9bb:	00 
 9bc:	48 01 ce             	add    rsi,rcx
 9bf:	0f 38 f0 88 a4 03 00 	movbe  ecx,DWORD PTR [rax+0x3a4]
 9c6:	00 
 9c7:	48 01 f1             	add    rcx,rsi
 9ca:	48 01 d1             	add    rcx,rdx
 9cd:	0f 38 f0 90 a8 03 00 	movbe  edx,DWORD PTR [rax+0x3a8]
 9d4:	00 
 9d5:	0f 38 f0 b0 ac 03 00 	movbe  esi,DWORD PTR [rax+0x3ac]
 9dc:	00 
 9dd:	48 01 d6             	add    rsi,rdx
 9e0:	0f 38 f0 90 b0 03 00 	movbe  edx,DWORD PTR [rax+0x3b0]
 9e7:	00 
 9e8:	48 01 f2             	add    rdx,rsi
 9eb:	0f 38 f0 b0 b4 03 00 	movbe  esi,DWORD PTR [rax+0x3b4]
 9f2:	00 
 9f3:	48 01 d6             	add    rsi,rdx
 9f6:	0f 38 f0 90 b8 03 00 	movbe  edx,DWORD PTR [rax+0x3b8]
 9fd:	00 
 9fe:	48 01 f2             	add    rdx,rsi
 a01:	0f 38 f0 b0 bc 03 00 	movbe  esi,DWORD PTR [rax+0x3bc]
 a08:	00 
 a09:	48 01 d6             	add    rsi,rdx
 a0c:	0f 38 f0 90 c0 03 00 	movbe  edx,DWORD PTR [rax+0x3c0]
 a13:	00 
 a14:	48 01 f2             	add    rdx,rsi
 a17:	0f 38 f0 b0 c4 03 00 	movbe  esi,DWORD PTR [rax+0x3c4]
 a1e:	00 
 a1f:	48 01 d6             	add    rsi,rdx
 a22:	0f 38 f0 90 c8 03 00 	movbe  edx,DWORD PTR [rax+0x3c8]
 a29:	00 
 a2a:	48 01 f2             	add    rdx,rsi
 a2d:	0f 38 f0 b0 cc 03 00 	movbe  esi,DWORD PTR [rax+0x3cc]
 a34:	00 
 a35:	48 01 d6             	add    rsi,rdx
 a38:	0f 38 f0 90 d0 03 00 	movbe  edx,DWORD PTR [rax+0x3d0]
 a3f:	00 
 a40:	48 01 f2             	add    rdx,rsi
 a43:	0f 38 f0 b0 d4 03 00 	movbe  esi,DWORD PTR [rax+0x3d4]
 a4a:	00 
 a4b:	48 01 d6             	add    rsi,rdx
 a4e:	0f 38 f0 90 d8 03 00 	movbe  edx,DWORD PTR [rax+0x3d8]
 a55:	00 
 a56:	48 01 f2             	add    rdx,rsi
 a59:	0f 38 f0 b0 dc 03 00 	movbe  esi,DWORD PTR [rax+0x3dc]
 a60:	00 
 a61:	48 01 d6             	add    rsi,rdx
 a64:	0f 38 f0 90 e0 03 00 	movbe  edx,DWORD PTR [rax+0x3e0]
 a6b:	00 
 a6c:	48 01 f2             	add    rdx,rsi
 a6f:	0f 38 f0 b0 e4 03 00 	movbe  esi,DWORD PTR [rax+0x3e4]
 a76:	00 
 a77:	48 01 d6             	add    rsi,rdx
 a7a:	0f 38 f0 90 e8 03 00 	movbe  edx,DWORD PTR [rax+0x3e8]
 a81:	00 
 a82:	48 01 f2             	add    rdx,rsi
 a85:	0f 38 f0 b0 ec 03 00 	movbe  esi,DWORD PTR [rax+0x3ec]
 a8c:	00 
 a8d:	48 01 d6             	add    rsi,rdx
 a90:	0f 38 f0 90 f0 03 00 	movbe  edx,DWORD PTR [rax+0x3f0]
 a97:	00 
 a98:	48 01 f2             	add    rdx,rsi
 a9b:	0f 38 f0 b0 f4 03 00 	movbe  esi,DWORD PTR [rax+0x3f4]
 aa2:	00 
 aa3:	48 01 d6             	add    rsi,rdx
 aa6:	0f 38 f0 90 f8 03 00 	movbe  edx,DWORD PTR [rax+0x3f8]
 aad:	00 
 aae:	48 01 f2             	add    rdx,rsi
 ab1:	0f 38 f0 b0 fc 03 00 	movbe  esi,DWORD PTR [rax+0x3fc]
 ab8:	00 
 ab9:	48 01 d6             	add    rsi,rdx
 abc:	48 01 ce             	add    rsi,rcx
 abf:	0f 38 f0 90 00 04 00 	movbe  edx,DWORD PTR [rax+0x400]
 ac6:	00 
 ac7:	0f 38 f0 88 04 04 00 	movbe  ecx,DWORD PTR [rax+0x404]
 ace:	00 
 acf:	48 01 d1             	add    rcx,rdx
 ad2:	48 01 f1             	add    rcx,rsi
 ad5:	48 be 2b fc 14 7e 73 	movabs rsi,0x3c6ef3737e14fc2b
 adc:	f3 6e 3c 
 adf:	48 01 ce             	add    rsi,rcx
 ae2:	66 c7 40 06 6e 3c    	mov    WORD PTR [rax+0x6],0x3c6e
 ae8:	48 89 f2             	mov    rdx,rsi
 aeb:	48 c1 ea 28          	shr    rdx,0x28
 aef:	88 50 05             	mov    BYTE PTR [rax+0x5],dl
 af2:	48 89 f2             	mov    rdx,rsi
 af5:	48 c1 ea 20          	shr    rdx,0x20
 af9:	88 50 04             	mov    BYTE PTR [rax+0x4],dl
 afc:	89 f2                	mov    edx,esi
 afe:	c1 ea 18             	shr    edx,0x18
 b01:	88 50 03             	mov    BYTE PTR [rax+0x3],dl
 b04:	48 ba 2b fc 15 7d 73 	movabs rdx,0x3c6ef3737d15fc2b
 b0b:	f3 6e 3c 
 b0e:	c1 ee 10             	shr    esi,0x10
 b11:	40 88 70 02          	mov    BYTE PTR [rax+0x2],sil
 b15:	48 01 ca             	add    rdx,rcx
 b18:	88 10                	mov    BYTE PTR [rax],dl
 b1a:	88 70 01             	mov    BYTE PTR [rax+0x1],dh
 b1d:	b8 02 00 00 00       	mov    eax,0x2
 b22:	c3                   	ret
