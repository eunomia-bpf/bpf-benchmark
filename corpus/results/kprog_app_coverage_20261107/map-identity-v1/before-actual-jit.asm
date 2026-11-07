
corpus/results/kprog_app_coverage_20261107/map-identity-v1/actual-guest/before/native-lowering-disabled-0.jit.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
       0:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
       5:	0f 1f 00             	nopl   (%rax)
       8:	55                   	push   %rbp
       9:	48 89 e5             	mov    %rsp,%rbp
       c:	55                   	push   %rbp
       d:	41 57                	push   %r15
       f:	41 56                	push   %r14
      11:	41 55                	push   %r13
      13:	41 54                	push   %r12
      15:	53                   	push   %rbx
      16:	48 81 ec b8 00 00 00 	sub    $0xb8,%rsp
      1d:	4c 8b 27             	mov    (%rdi),%r12
      20:	4c 8b 7f 08          	mov    0x8(%rdi),%r15
      24:	49 8d 44 24 0e       	lea    0xe(%r12),%rax
      29:	bb 01 00 00 00       	mov    $0x1,%ebx
      2e:	4c 39 f8             	cmp    %r15,%rax
      31:	0f 87 dd 22 00 00    	ja     0x2314
      37:	49 89 fe             	mov    %rdi,%r14
      3a:	c7 84 24 94 00 00 00 	movl   $0x210,0x94(%rsp)
      41:	10 02 00 00 
      45:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
      4c:	8b ff ff 
      4f:	48 8d b4 24 94 00 00 	lea    0x94(%rsp),%rsi
      56:	00 
      57:	b8 01 00 00 00       	mov    $0x1,%eax
      5c:	8b 06                	mov    (%rsi),%eax
      5e:	3d 00 04 00 00       	cmp    $0x400,%eax
      63:	73 16                	jae    0x7b
      65:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
      6c:	00 
      6d:	48 8b 00             	mov    (%rax),%rax
      70:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
      77:	2b 9e 
      79:	eb 02                	jmp    0x7d
      7b:	31 c0                	xor    %eax,%eax
      7d:	48 85 c0             	test   %rax,%rax
      80:	0f 84 8e 22 00 00    	je     0x2314
      86:	4d 29 e7             	sub    %r12,%r15
      89:	48 ff 00             	incq   (%rax)
      8c:	4c 01 78 08          	add    %r15,0x8(%rax)
      90:	41 0f b7 44 24 0c    	movzwl 0xc(%r12),%eax
      96:	3d 86 dd 00 00       	cmp    $0xdd86,%eax
      9b:	0f 84 5c 01 00 00    	je     0x1fd
      a1:	83 f8 08             	cmp    $0x8,%eax
      a4:	0f 85 02 22 00 00    	jne    0x22ac
      aa:	4d 8b 26             	mov    (%r14),%r12
      ad:	4d 8b 4e 08          	mov    0x8(%r14),%r9
      b1:	48 c7 44 24 68 00 00 	movq   $0x0,0x68(%rsp)
      b8:	00 00 
      ba:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
      c1:	00 00 
      c3:	48 c7 44 24 58 00 00 	movq   $0x0,0x58(%rsp)
      ca:	00 00 
      cc:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
      d3:	00 00 
      d5:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
      dc:	00 00 
      de:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
      e5:	00 00 
      e7:	c7 84 24 90 00 00 00 	movl   $0x0,0x90(%rsp)
      ee:	00 00 00 00 
      f2:	48 c7 84 24 88 00 00 	movq   $0x0,0x88(%rsp)
      f9:	00 00 00 00 00 
      fe:	48 c7 84 24 80 00 00 	movq   $0x0,0x80(%rsp)
     105:	00 00 00 00 00 
     10a:	c7 84 24 a0 00 00 00 	movl   $0x0,0xa0(%rsp)
     111:	00 00 00 00 
     115:	49 8d 6c 24 22       	lea    0x22(%r12),%rbp
     11a:	4c 39 cd             	cmp    %r9,%rbp
     11d:	0f 87 65 21 00 00    	ja     0x2288
     123:	41 0f b6 44 24 0e    	movzbl 0xe(%r12),%eax
     129:	24 0f                	and    $0xf,%al
     12b:	3c 05                	cmp    $0x5,%al
     12d:	0f 85 55 21 00 00    	jne    0x2288
     133:	41 0f b6 44 24 0f    	movzbl 0xf(%r12),%eax
     139:	88 44 24 6d          	mov    %al,0x6d(%rsp)
     13d:	41 0f b6 44 24 17    	movzbl 0x17(%r12),%eax
     143:	88 44 24 64          	mov    %al,0x64(%rsp)
     147:	41 0f b7 4c 24 14    	movzwl 0x14(%r12),%ecx
     14d:	f7 c1 3f ff 00 00    	test   $0xff3f,%ecx
     153:	0f 85 2f 21 00 00    	jne    0x2288
     159:	45 0f b7 44 24 10    	movzwl 0x10(%r12),%r8d
     15f:	3c 01                	cmp    $0x1,%al
     161:	0f 85 dd 03 00 00    	jne    0x544
     167:	4d 8d 6c 24 2a       	lea    0x2a(%r12),%r13
     16c:	4d 39 cd             	cmp    %r9,%r13
     16f:	0f 87 13 21 00 00    	ja     0x2288
     175:	0f b6 45 00          	movzbl 0x0(%rbp),%eax
     179:	83 f8 03             	cmp    $0x3,%eax
     17c:	0f 84 3f 09 00 00    	je     0xac1
     182:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     188:	83 f8 08             	cmp    $0x8,%eax
     18b:	0f 85 fd 20 00 00    	jne    0x228e
     191:	41 c6 44 24 22 00    	movb   $0x0,0x22(%r12)
     197:	66 41 83 44 24 24 08 	addw   $0x8,0x24(%r12)
     19e:	41 0f b7 c0          	movzwl %r8w,%eax
     1a2:	41 c6 44 24 16 40    	movb   $0x40,0x16(%r12)
     1a8:	41 8b 54 24 1a       	mov    0x1a(%r12),%edx
     1ad:	41 8b 74 24 1e       	mov    0x1e(%r12),%esi
     1b2:	41 89 54 24 1e       	mov    %edx,0x1e(%r12)
     1b7:	41 89 74 24 1a       	mov    %esi,0x1a(%r12)
     1bc:	41 0f b7 7c 24 0e    	movzwl 0xe(%r12),%edi
     1c2:	45 0f b7 44 24 12    	movzwl 0x12(%r12),%r8d
     1c8:	49 01 f8             	add    %rdi,%r8
     1cb:	49 01 c8             	add    %rcx,%r8
     1ce:	49 01 c0             	add    %rax,%r8
     1d1:	41 0f b7 44 24 16    	movzwl 0x16(%r12),%eax
     1d7:	0f b7 ce             	movzwl %si,%ecx
     1da:	48 01 c1             	add    %rax,%rcx
     1dd:	41 0f b7 44 24 1c    	movzwl 0x1c(%r12),%eax
     1e3:	48 01 c8             	add    %rcx,%rax
     1e6:	4c 01 c0             	add    %r8,%rax
     1e9:	0f b7 ca             	movzwl %dx,%ecx
     1ec:	41 0f b7 54 24 20    	movzwl 0x20(%r12),%edx
     1f2:	48 01 ca             	add    %rcx,%rdx
     1f5:	48 01 c2             	add    %rax,%rdx
     1f8:	e9 3e 02 00 00       	jmp    0x43b
     1fd:	4d 8b 26             	mov    (%r14),%r12
     200:	49 8b 6e 08          	mov    0x8(%r14),%rbp
     204:	48 c7 44 24 68 00 00 	movq   $0x0,0x68(%rsp)
     20b:	00 00 
     20d:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
     214:	00 00 
     216:	48 c7 44 24 58 00 00 	movq   $0x0,0x58(%rsp)
     21d:	00 00 
     21f:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
     226:	00 00 
     228:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
     22f:	00 00 
     231:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
     238:	00 00 
     23a:	c7 84 24 90 00 00 00 	movl   $0x0,0x90(%rsp)
     241:	00 00 00 00 
     245:	48 c7 84 24 88 00 00 	movq   $0x0,0x88(%rsp)
     24c:	00 00 00 00 00 
     251:	48 c7 84 24 80 00 00 	movq   $0x0,0x80(%rsp)
     258:	00 00 00 00 00 
     25d:	c7 84 24 a0 00 00 00 	movl   $0x0,0xa0(%rsp)
     264:	00 00 00 00 
     268:	4d 8d 44 24 36       	lea    0x36(%r12),%r8
     26d:	49 39 e8             	cmp    %rbp,%r8
     270:	0f 87 12 20 00 00    	ja     0x2288
     276:	41 0f b6 44 24 14    	movzbl 0x14(%r12),%eax
     27c:	88 44 24 64          	mov    %al,0x64(%rsp)
     280:	41 0f b6 4c 24 0e    	movzbl 0xe(%r12),%ecx
     286:	c0 e1 04             	shl    $0x4,%cl
     289:	88 4c 24 6d          	mov    %cl,0x6d(%rsp)
     28d:	41 0f b6 54 24 0f    	movzbl 0xf(%r12),%edx
     293:	c0 ea 04             	shr    $0x4,%dl
     296:	08 ca                	or     %cl,%dl
     298:	88 54 24 6d          	mov    %dl,0x6d(%rsp)
     29c:	83 f8 2c             	cmp    $0x2c,%eax
     29f:	0f 84 e3 1f 00 00    	je     0x2288
     2a5:	66 41 0f 38 f0 7c 24 	movbe  0x12(%r12),%di
     2ac:	12 
     2ad:	83 f8 3a             	cmp    $0x3a,%eax
     2b0:	0f 85 bc 00 00 00    	jne    0x372
     2b6:	49 8d 44 24 3e       	lea    0x3e(%r12),%rax
     2bb:	48 39 e8             	cmp    %rbp,%rax
     2be:	0f 87 c4 1f 00 00    	ja     0x2288
     2c4:	41 0f b6 00          	movzbl (%r8),%eax
     2c8:	83 f8 01             	cmp    $0x1,%eax
     2cb:	0f 84 ec 03 00 00    	je     0x6bd
     2d1:	83 f8 02             	cmp    $0x2,%eax
     2d4:	0f 84 7a 03 00 00    	je     0x654
     2da:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     2e0:	3d 80 00 00 00       	cmp    $0x80,%eax
     2e5:	0f 85 a3 1f 00 00    	jne    0x228e
     2eb:	41 c6 44 24 36 81    	movb   $0x81,0x36(%r12)
     2f1:	66 41 ff 4c 24 38    	decw   0x38(%r12)
     2f7:	41 c6 44 24 15 40    	movb   $0x40,0x15(%r12)
     2fd:	49 8b 44 24 16       	mov    0x16(%r12),%rax
     302:	49 8b 4c 24 1e       	mov    0x1e(%r12),%rcx
     307:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
     30c:	48 89 04 24          	mov    %rax,(%rsp)
     310:	49 8b 44 24 26       	mov    0x26(%r12),%rax
     315:	49 8b 4c 24 2e       	mov    0x2e(%r12),%rcx
     31a:	49 89 44 24 16       	mov    %rax,0x16(%r12)
     31f:	49 89 4c 24 1e       	mov    %rcx,0x1e(%r12)
     324:	48 8b 04 24          	mov    (%rsp),%rax
     328:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
     32d:	49 89 44 24 26       	mov    %rax,0x26(%r12)
     332:	49 89 4c 24 2e       	mov    %rcx,0x2e(%r12)
     337:	41 0f b7 44 24 0a    	movzwl 0xa(%r12),%eax
     33d:	66 89 44 24 20       	mov    %ax,0x20(%rsp)
     342:	41 8b 44 24 06       	mov    0x6(%r12),%eax
     347:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
     34b:	41 8b 04 24          	mov    (%r12),%eax
     34f:	41 89 44 24 06       	mov    %eax,0x6(%r12)
     354:	41 0f b7 44 24 04    	movzwl 0x4(%r12),%eax
     35a:	66 41 89 44 24 0a    	mov    %ax,0xa(%r12)
     360:	8b 44 24 1c          	mov    0x1c(%rsp),%eax
     364:	41 89 04 24          	mov    %eax,(%r12)
     368:	0f b7 44 24 20       	movzwl 0x20(%rsp),%eax
     36d:	e9 52 01 00 00       	jmp    0x4c4
     372:	49 8b 4c 24 16       	mov    0x16(%r12),%rcx
     377:	49 8b 54 24 1e       	mov    0x1e(%r12),%rdx
     37c:	48 89 54 24 48       	mov    %rdx,0x48(%rsp)
     381:	48 89 4c 24 40       	mov    %rcx,0x40(%rsp)
     386:	49 8b 4c 24 26       	mov    0x26(%r12),%rcx
     38b:	49 8b 54 24 2e       	mov    0x2e(%r12),%rdx
     390:	48 89 4c 24 50       	mov    %rcx,0x50(%rsp)
     395:	48 89 54 24 58       	mov    %rdx,0x58(%rsp)
     39a:	3c 01                	cmp    $0x1,%al
     39c:	0f 85 33 01 00 00    	jne    0x4d5
     3a2:	4d 8d 6c 24 3e       	lea    0x3e(%r12),%r13
     3a7:	49 39 ed             	cmp    %rbp,%r13
     3aa:	0f 87 d8 1e 00 00    	ja     0x2288
     3b0:	41 0f b6 00          	movzbl (%r8),%eax
     3b4:	83 f8 03             	cmp    $0x3,%eax
     3b7:	0f 84 c3 05 00 00    	je     0x980
     3bd:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     3c3:	83 f8 08             	cmp    $0x8,%eax
     3c6:	0f 85 c2 1e 00 00    	jne    0x228e
     3cc:	41 c6 44 24 22 00    	movb   $0x0,0x22(%r12)
     3d2:	66 41 83 44 24 24 08 	addw   $0x8,0x24(%r12)
     3d9:	41 c6 44 24 16 40    	movb   $0x40,0x16(%r12)
     3df:	41 8b 44 24 1a       	mov    0x1a(%r12),%eax
     3e4:	41 8b 4c 24 1e       	mov    0x1e(%r12),%ecx
     3e9:	41 89 44 24 1e       	mov    %eax,0x1e(%r12)
     3ee:	41 89 4c 24 1a       	mov    %ecx,0x1a(%r12)
     3f3:	41 0f b7 54 24 0e    	movzwl 0xe(%r12),%edx
     3f9:	41 0f b7 74 24 10    	movzwl 0x10(%r12),%esi
     3ff:	48 01 d6             	add    %rdx,%rsi
     402:	41 0f b7 54 24 12    	movzwl 0x12(%r12),%edx
     408:	41 0f b7 7c 24 14    	movzwl 0x14(%r12),%edi
     40e:	48 01 d7             	add    %rdx,%rdi
     411:	48 01 f7             	add    %rsi,%rdi
     414:	41 0f b7 54 24 16    	movzwl 0x16(%r12),%edx
     41a:	0f b7 c9             	movzwl %cx,%ecx
     41d:	48 01 d1             	add    %rdx,%rcx
     420:	48 01 f9             	add    %rdi,%rcx
     423:	41 0f b7 54 24 1c    	movzwl 0x1c(%r12),%edx
     429:	0f b7 c0             	movzwl %ax,%eax
     42c:	48 01 d0             	add    %rdx,%rax
     42f:	41 0f b7 54 24 20    	movzwl 0x20(%r12),%edx
     435:	48 01 c2             	add    %rax,%rdx
     438:	48 01 ca             	add    %rcx,%rdx
     43b:	48 89 d0             	mov    %rdx,%rax
     43e:	48 c1 e8 10          	shr    $0x10,%rax
     442:	0f b7 ca             	movzwl %dx,%ecx
     445:	48 01 c1             	add    %rax,%rcx
     448:	48 81 fa 00 00 01 00 	cmp    $0x10000,%rdx
     44f:	48 0f 42 ca          	cmovb  %rdx,%rcx
     453:	48 89 c8             	mov    %rcx,%rax
     456:	48 c1 e8 10          	shr    $0x10,%rax
     45a:	0f b7 d1             	movzwl %cx,%edx
     45d:	48 01 c2             	add    %rax,%rdx
     460:	48 81 f9 00 00 01 00 	cmp    $0x10000,%rcx
     467:	48 0f 42 d1          	cmovb  %rcx,%rdx
     46b:	48 89 d0             	mov    %rdx,%rax
     46e:	48 c1 e8 10          	shr    $0x10,%rax
     472:	0f b7 ca             	movzwl %dx,%ecx
     475:	01 c8                	add    %ecx,%eax
     477:	48 81 fa 00 00 01 00 	cmp    $0x10000,%rdx
     47e:	0f 42 c2             	cmovb  %edx,%eax
     481:	89 c1                	mov    %eax,%ecx
     483:	c1 e9 10             	shr    $0x10,%ecx
     486:	01 c1                	add    %eax,%ecx
     488:	f7 d1                	not    %ecx
     48a:	66 41 89 4c 24 18    	mov    %cx,0x18(%r12)
     490:	41 0f b7 44 24 0a    	movzwl 0xa(%r12),%eax
     496:	66 89 44 24 04       	mov    %ax,0x4(%rsp)
     49b:	41 8b 44 24 06       	mov    0x6(%r12),%eax
     4a0:	89 04 24             	mov    %eax,(%rsp)
     4a3:	41 8b 04 24          	mov    (%r12),%eax
     4a7:	41 89 44 24 06       	mov    %eax,0x6(%r12)
     4ac:	41 0f b7 44 24 04    	movzwl 0x4(%r12),%eax
     4b2:	66 41 89 44 24 0a    	mov    %ax,0xa(%r12)
     4b8:	8b 04 24             	mov    (%rsp),%eax
     4bb:	41 89 04 24          	mov    %eax,(%r12)
     4bf:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
     4c4:	66 41 89 44 24 04    	mov    %ax,0x4(%r12)
     4ca:	41 bd 03 00 00 00    	mov    $0x3,%r13d
     4d0:	e9 b9 1d 00 00       	jmp    0x228e
     4d5:	31 c9                	xor    %ecx,%ecx
     4d7:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     4dd:	3c 11                	cmp    $0x11,%al
     4df:	0f 84 c7 00 00 00    	je     0x5ac
     4e5:	0f b6 d0             	movzbl %al,%edx
     4e8:	83 fa 06             	cmp    $0x6,%edx
     4eb:	0f 85 9d 1d 00 00    	jne    0x228e
     4f1:	49 8d 54 24 66       	lea    0x66(%r12),%rdx
     4f6:	f6 c1 01             	test   $0x1,%cl
     4f9:	49 0f 44 d0          	cmove  %r8,%rdx
     4fd:	48 8d 72 14          	lea    0x14(%rdx),%rsi
     501:	48 39 ee             	cmp    %rbp,%rsi
     504:	0f 87 7e 1d 00 00    	ja     0x2288
     50a:	89 7c 24 34          	mov    %edi,0x34(%rsp)
     50e:	0f b7 7a 0c          	movzwl 0xc(%rdx),%edi
     512:	89 ce                	mov    %ecx,%esi
     514:	f7 c7 00 02 00 00    	test   $0x200,%edi
     51a:	74 0f                	je     0x52b
     51c:	89 ce                	mov    %ecx,%esi
     51e:	40 80 ce 02          	or     $0x2,%sil
     522:	40 88 74 24 6c       	mov    %sil,0x6c(%rsp)
     527:	0f b7 7a 0c          	movzwl 0xc(%rdx),%edi
     52b:	f7 c7 00 04 00 00    	test   $0x400,%edi
     531:	74 09                	je     0x53c
     533:	40 80 ce 04          	or     $0x4,%sil
     537:	40 88 74 24 6c       	mov    %sil,0x6c(%rsp)
     53c:	f6 c1 01             	test   $0x1,%cl
     53f:	e9 88 00 00 00       	jmp    0x5cc
     544:	41 8b 4c 24 1a       	mov    0x1a(%r12),%ecx
     549:	89 4c 24 40          	mov    %ecx,0x40(%rsp)
     54d:	41 8b 4c 24 1e       	mov    0x1e(%r12),%ecx
     552:	89 4c 24 50          	mov    %ecx,0x50(%rsp)
     556:	3c 3a                	cmp    $0x3a,%al
     558:	0f 85 8a 00 00 00    	jne    0x5e8
     55e:	49 8d 44 24 2a       	lea    0x2a(%r12),%rax
     563:	4c 39 c8             	cmp    %r9,%rax
     566:	0f 87 1c 1d 00 00    	ja     0x2288
     56c:	0f b6 45 00          	movzbl 0x0(%rbp),%eax
     570:	83 f8 01             	cmp    $0x1,%eax
     573:	0f 84 1c 09 00 00    	je     0xe95
     579:	83 f8 02             	cmp    $0x2,%eax
     57c:	0f 84 aa 08 00 00    	je     0xe2c
     582:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     588:	3d 80 00 00 00       	cmp    $0x80,%eax
     58d:	0f 85 fb 1c 00 00    	jne    0x228e
     593:	49 8d 44 24 3e       	lea    0x3e(%r12),%rax
     598:	41 bd 01 00 00 00    	mov    $0x1,%r13d
     59e:	4c 39 c8             	cmp    %r9,%rax
     5a1:	0f 86 44 fd ff ff    	jbe    0x2eb
     5a7:	e9 e2 1c 00 00       	jmp    0x228e
     5ac:	49 8d 54 24 66       	lea    0x66(%r12),%rdx
     5b1:	f6 c1 01             	test   $0x1,%cl
     5b4:	49 0f 44 d0          	cmove  %r8,%rdx
     5b8:	48 8d 72 08          	lea    0x8(%rdx),%rsi
     5bc:	48 39 ee             	cmp    %rbp,%rsi
     5bf:	0f 87 c3 1c 00 00    	ja     0x2288
     5c5:	f6 c1 01             	test   $0x1,%cl
     5c8:	89 7c 24 34          	mov    %edi,0x34(%rsp)
     5cc:	4c 89 44 24 38       	mov    %r8,0x38(%rsp)
     5d1:	0f 85 37 01 00 00    	jne    0x70e
     5d7:	0f b7 0a             	movzwl (%rdx),%ecx
     5da:	66 89 4c 24 60       	mov    %cx,0x60(%rsp)
     5df:	0f b7 4a 02          	movzwl 0x2(%rdx),%ecx
     5e3:	e9 32 01 00 00       	jmp    0x71a
     5e8:	31 c9                	xor    %ecx,%ecx
     5ea:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     5f0:	3c 11                	cmp    $0x11,%al
     5f2:	0f 84 8b 04 00 00    	je     0xa83
     5f8:	0f b6 d0             	movzbl %al,%edx
     5fb:	83 fa 06             	cmp    $0x6,%edx
     5fe:	0f 85 8a 1c 00 00    	jne    0x228e
     604:	49 8d 54 24 3e       	lea    0x3e(%r12),%rdx
     609:	f6 c1 01             	test   $0x1,%cl
     60c:	48 0f 44 d5          	cmove  %rbp,%rdx
     610:	48 8d 72 14          	lea    0x14(%rdx),%rsi
     614:	4c 39 ce             	cmp    %r9,%rsi
     617:	0f 87 6b 1c 00 00    	ja     0x2288
     61d:	0f b7 7a 0c          	movzwl 0xc(%rdx),%edi
     621:	89 ce                	mov    %ecx,%esi
     623:	f7 c7 00 02 00 00    	test   $0x200,%edi
     629:	74 0f                	je     0x63a
     62b:	89 ce                	mov    %ecx,%esi
     62d:	40 80 ce 02          	or     $0x2,%sil
     631:	40 88 74 24 6c       	mov    %sil,0x6c(%rsp)
     636:	0f b7 7a 0c          	movzwl 0xc(%rdx),%edi
     63a:	f7 c7 00 04 00 00    	test   $0x400,%edi
     640:	0f 84 56 04 00 00    	je     0xa9c
     646:	40 80 ce 04          	or     $0x4,%sil
     64a:	40 88 74 24 6c       	mov    %sil,0x6c(%rsp)
     64f:	e9 48 04 00 00       	jmp    0xa9c
     654:	4c 89 44 24 38       	mov    %r8,0x38(%rsp)
     659:	41 89 fd             	mov    %edi,%r13d
     65c:	c7 04 24 0c 02 00 00 	movl   $0x20c,(%rsp)
     663:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     66a:	8b ff ff 
     66d:	48 89 e6             	mov    %rsp,%rsi
     670:	b8 01 00 00 00       	mov    $0x1,%eax
     675:	8b 06                	mov    (%rsi),%eax
     677:	3d 00 04 00 00       	cmp    $0x400,%eax
     67c:	73 16                	jae    0x694
     67e:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     685:	00 
     686:	48 8b 00             	mov    (%rax),%rax
     689:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     690:	2b 9e 
     692:	eb 02                	jmp    0x696
     694:	31 c0                	xor    %eax,%eax
     696:	48 85 c0             	test   %rax,%rax
     699:	0f 84 e9 1b 00 00    	je     0x2288
     69f:	48 ff 00             	incq   (%rax)
     6a2:	41 0f 38 f0 4c 24 3a 	movbe  0x3a(%r12),%ecx
     6a9:	81 f9 ff 04 00 00    	cmp    $0x4ff,%ecx
     6af:	44 89 ef             	mov    %r13d,%edi
     6b2:	4c 8b 44 24 38       	mov    0x38(%rsp),%r8
     6b7:	77 04                	ja     0x6bd
     6b9:	48 ff 40 08          	incq   0x8(%rax)
     6bd:	49 8d 44 24 66       	lea    0x66(%r12),%rax
     6c2:	48 39 e8             	cmp    %rbp,%rax
     6c5:	0f 87 bd 1b 00 00    	ja     0x2288
     6cb:	41 0f b6 44 24 44    	movzbl 0x44(%r12),%eax
     6d1:	88 44 24 64          	mov    %al,0x64(%rsp)
     6d5:	0f b6 4c 24 6c       	movzbl 0x6c(%rsp),%ecx
     6da:	80 c9 01             	or     $0x1,%cl
     6dd:	88 4c 24 6c          	mov    %cl,0x6c(%rsp)
     6e1:	49 8b 54 24 56       	mov    0x56(%r12),%rdx
     6e6:	49 8b 74 24 5e       	mov    0x5e(%r12),%rsi
     6eb:	48 89 54 24 40       	mov    %rdx,0x40(%rsp)
     6f0:	48 89 74 24 48       	mov    %rsi,0x48(%rsp)
     6f5:	49 8b 54 24 46       	mov    0x46(%r12),%rdx
     6fa:	49 8b 74 24 4e       	mov    0x4e(%r12),%rsi
     6ff:	48 89 54 24 50       	mov    %rdx,0x50(%rsp)
     704:	48 89 74 24 58       	mov    %rsi,0x58(%rsp)
     709:	e9 c9 fd ff ff       	jmp    0x4d7
     70e:	0f b7 4a 02          	movzwl 0x2(%rdx),%ecx
     712:	66 89 4c 24 60       	mov    %cx,0x60(%rsp)
     717:	0f b7 0a             	movzwl (%rdx),%ecx
     71a:	66 89 4c 24 62       	mov    %cx,0x62(%rsp)
     71f:	48 8b 54 24 50       	mov    0x50(%rsp),%rdx
     724:	48 8b 74 24 58       	mov    0x58(%rsp),%rsi
     729:	48 89 b4 24 88 00 00 	mov    %rsi,0x88(%rsp)
     730:	00 
     731:	48 89 94 24 80 00 00 	mov    %rdx,0x80(%rsp)
     738:	00 
     739:	66 89 8c 24 90 00 00 	mov    %cx,0x90(%rsp)
     740:	00 
     741:	88 84 24 92 00 00 00 	mov    %al,0x92(%rsp)
     748:	48 bf 00 58 01 56 10 	movabs $0xffff8b1056015800,%rdi
     74f:	8b ff ff 
     752:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     759:	00 
     75a:	b8 01 00 00 00       	mov    $0x1,%eax
     75f:	e8 40 12 ec da       	call   0xffffffffdaec19a4
     764:	48 85 c0             	test   %rax,%rax
     767:	74 04                	je     0x76d
     769:	48 83 c0 48          	add    $0x48,%rax
     76d:	48 85 c0             	test   %rax,%rax
     770:	0f 84 c0 02 00 00    	je     0xa36
     776:	48 89 e9             	mov    %rbp,%rcx
     779:	4c 29 e1             	sub    %r12,%rcx
     77c:	41 bd 01 00 00 00    	mov    $0x1,%r13d
     782:	48 81 f9 ea 05 00 00 	cmp    $0x5ea,%rcx
     789:	0f 8f ff 1a 00 00    	jg     0x228e
     78f:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
     794:	c7 84 24 9c 00 00 00 	movl   $0x200,0x9c(%rsp)
     79b:	00 02 00 00 
     79f:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     7a6:	8b ff ff 
     7a9:	48 8d b4 24 9c 00 00 	lea    0x9c(%rsp),%rsi
     7b0:	00 
     7b1:	b8 01 00 00 00       	mov    $0x1,%eax
     7b6:	8b 06                	mov    (%rsi),%eax
     7b8:	3d 00 04 00 00       	cmp    $0x400,%eax
     7bd:	73 16                	jae    0x7d5
     7bf:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     7c6:	00 
     7c7:	48 8b 00             	mov    (%rax),%rax
     7ca:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     7d1:	2b 9e 
     7d3:	eb 02                	jmp    0x7d7
     7d5:	31 c0                	xor    %eax,%eax
     7d7:	48 85 c0             	test   %rax,%rax
     7da:	0f 84 a8 1a 00 00    	je     0x2288
     7e0:	48 89 84 24 b0 00 00 	mov    %rax,0xb0(%rsp)
     7e7:	00 
     7e8:	48 ff 00             	incq   (%rax)
     7eb:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
     7f0:	41 f6 45 00 01       	testb  $0x1,0x0(%r13)
     7f5:	74 07                	je     0x7fe
     7f7:	66 c7 44 24 60 00 00 	movw   $0x0,0x60(%rsp)
     7fe:	41 8b 45 04          	mov    0x4(%r13),%eax
     802:	89 44 24 70          	mov    %eax,0x70(%rsp)
     806:	89 84 24 a4 00 00 00 	mov    %eax,0xa4(%rsp)
     80d:	b8 08 00 00 00       	mov    $0x8,%eax
     812:	48 c7 c0 34 10 2b 9e 	mov    $0xffffffff9e2b1034,%rax
     819:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     820:	2b 9e 
     822:	8b 40 00             	mov    0x0(%rax),%eax
     825:	89 84 24 98 00 00 00 	mov    %eax,0x98(%rsp)
     82c:	48 bf 00 d8 2a 56 10 	movabs $0xffff8b10562ad800,%rdi
     833:	8b ff ff 
     836:	48 8d b4 24 98 00 00 	lea    0x98(%rsp),%rsi
     83d:	00 
     83e:	b8 01 00 00 00       	mov    $0x1,%eax
     843:	e8 0c 5d ec da       	call   0xffffffffdaec6554
     848:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     84d:	48 85 c0             	test   %rax,%rax
     850:	75 5a                	jne    0x8ac
     852:	c7 04 24 03 02 00 00 	movl   $0x203,(%rsp)
     859:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     860:	8b ff ff 
     863:	48 89 e6             	mov    %rsp,%rsi
     866:	b8 01 00 00 00       	mov    $0x1,%eax
     86b:	8b 06                	mov    (%rsi),%eax
     86d:	3d 00 04 00 00       	cmp    $0x400,%eax
     872:	73 16                	jae    0x88a
     874:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     87b:	00 
     87c:	48 8b 00             	mov    (%rax),%rax
     87f:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     886:	2b 9e 
     888:	eb 02                	jmp    0x88c
     88a:	31 c0                	xor    %eax,%eax
     88c:	48 85 c0             	test   %rax,%rax
     88f:	0f 84 f3 19 00 00    	je     0x2288
     895:	48 ff 00             	incq   (%rax)
     898:	48 b8 00 50 01 56 10 	movabs $0xffff8b1056015000,%rax
     89f:	8b ff ff 
     8a2:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     8a7:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
     8ac:	41 f6 45 00 04       	testb  $0x4,0x0(%r13)
     8b1:	0f 84 43 08 00 00    	je     0x10fa
     8b7:	f6 44 24 6c 01       	testb  $0x1,0x6c(%rsp)
     8bc:	0f 85 26 06 00 00    	jne    0xee8
     8c2:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%rsp)
     8c9:	00 
     8ca:	48 bf 00 82 20 83 0f 	movabs $0xffff8b0f83208200,%rdi
     8d1:	8b ff ff 
     8d4:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
     8d9:	b8 01 00 00 00       	mov    $0x1,%eax
     8de:	8b 06                	mov    (%rsi),%eax
     8e0:	83 f8 01             	cmp    $0x1,%eax
     8e3:	73 16                	jae    0x8fb
     8e5:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     8ec:	00 
     8ed:	48 8b 00             	mov    (%rax),%rax
     8f0:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     8f7:	2b 9e 
     8f9:	eb 02                	jmp    0x8fd
     8fb:	31 c0                	xor    %eax,%eax
     8fd:	48 85 c0             	test   %rax,%rax
     900:	0f 84 82 19 00 00    	je     0x2288
     906:	49 83 c4 66          	add    $0x66,%r12
     90a:	f6 44 24 6c 01       	testb  $0x1,0x6c(%rsp)
     90f:	4c 0f 44 64 24 38    	cmove  0x38(%rsp),%r12
     915:	49 8d 54 24 09       	lea    0x9(%r12),%rdx
     91a:	48 39 ea             	cmp    %rbp,%rdx
     91d:	0f 87 cf 07 00 00    	ja     0x10f2
     923:	41 0f b6 4c 24 08    	movzbl 0x8(%r12),%ecx
     929:	84 c9                	test   %cl,%cl
     92b:	0f 88 79 06 00 00    	js     0xfaa
     931:	49 83 c4 11          	add    $0x11,%r12
     935:	49 39 ec             	cmp    %rbp,%r12
     938:	0f 87 b4 07 00 00    	ja     0x10f2
     93e:	48 89 c5             	mov    %rax,%rbp
     941:	0f b6 32             	movzbl (%rdx),%esi
     944:	89 f1                	mov    %esi,%ecx
     946:	c1 e9 06             	shr    $0x6,%ecx
     949:	83 f9 03             	cmp    $0x3,%ecx
     94c:	0f 84 4c 07 00 00    	je     0x109e
     952:	83 f9 02             	cmp    $0x2,%ecx
     955:	0f 84 2d 07 00 00    	je     0x1088
     95b:	83 f9 01             	cmp    $0x1,%ecx
     95e:	48 89 e8             	mov    %rbp,%rax
     961:	0f 85 8b 07 00 00    	jne    0x10f2
     967:	83 e6 3f             	and    $0x3f,%esi
     96a:	c1 e6 0a             	shl    $0xa,%esi
     96d:	0f b6 42 01          	movzbl 0x1(%rdx),%eax
     971:	8d 04 86             	lea    (%rsi,%rax,4),%eax
     974:	0f b6 52 02          	movzbl 0x2(%rdx),%edx
     978:	c0 ea 06             	shr    $0x6,%dl
     97b:	e9 3b 07 00 00       	jmp    0x10bb
     980:	41 80 7c 24 37 04    	cmpb   $0x4,0x37(%r12)
     986:	75 64                	jne    0x9ec
     988:	4c 89 44 24 38       	mov    %r8,0x38(%rsp)
     98d:	89 7c 24 34          	mov    %edi,0x34(%rsp)
     991:	c7 04 24 0d 02 00 00 	movl   $0x20d,(%rsp)
     998:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     99f:	8b ff ff 
     9a2:	48 89 e6             	mov    %rsp,%rsi
     9a5:	b8 01 00 00 00       	mov    $0x1,%eax
     9aa:	8b 06                	mov    (%rsi),%eax
     9ac:	3d 00 04 00 00       	cmp    $0x400,%eax
     9b1:	73 16                	jae    0x9c9
     9b3:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     9ba:	00 
     9bb:	48 8b 00             	mov    (%rax),%rax
     9be:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     9c5:	2b 9e 
     9c7:	eb 02                	jmp    0x9cb
     9c9:	31 c0                	xor    %eax,%eax
     9cb:	48 85 c0             	test   %rax,%rax
     9ce:	0f 84 b4 18 00 00    	je     0x2288
     9d4:	48 ff 00             	incq   (%rax)
     9d7:	41 80 7c 24 3c 04    	cmpb   $0x4,0x3c(%r12)
     9dd:	77 04                	ja     0x9e3
     9df:	48 ff 40 08          	incq   0x8(%rax)
     9e3:	8b 7c 24 34          	mov    0x34(%rsp),%edi
     9e7:	4c 8b 44 24 38       	mov    0x38(%rsp),%r8
     9ec:	49 8d 44 24 52       	lea    0x52(%r12),%rax
     9f1:	48 39 e8             	cmp    %rbp,%rax
     9f4:	0f 87 8e 18 00 00    	ja     0x2288
     9fa:	41 0f b6 45 00       	movzbl 0x0(%r13),%eax
     9ff:	24 0f                	and    $0xf,%al
     a01:	3c 05                	cmp    $0x5,%al
     a03:	0f 85 7f 18 00 00    	jne    0x2288
     a09:	41 0f b6 44 24 47    	movzbl 0x47(%r12),%eax
     a0f:	88 44 24 64          	mov    %al,0x64(%rsp)
     a13:	0f b6 4c 24 6c       	movzbl 0x6c(%rsp),%ecx
     a18:	80 c9 01             	or     $0x1,%cl
     a1b:	88 4c 24 6c          	mov    %cl,0x6c(%rsp)
     a1f:	41 8b 54 24 4e       	mov    0x4e(%r12),%edx
     a24:	89 54 24 40          	mov    %edx,0x40(%rsp)
     a28:	41 8b 54 24 4a       	mov    0x4a(%r12),%edx
     a2d:	89 54 24 50          	mov    %edx,0x50(%rsp)
     a31:	e9 a1 fa ff ff       	jmp    0x4d7
     a36:	66 c7 84 24 90 00 00 	movw   $0x0,0x90(%rsp)
     a3d:	00 00 00 
     a40:	48 bf 00 58 01 56 10 	movabs $0xffff8b1056015800,%rdi
     a47:	8b ff ff 
     a4a:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     a51:	00 
     a52:	b8 01 00 00 00       	mov    $0x1,%eax
     a57:	e8 48 0f ec da       	call   0xffffffffdaec19a4
     a5c:	48 85 c0             	test   %rax,%rax
     a5f:	74 04                	je     0xa65
     a61:	48 83 c0 48          	add    $0x48,%rax
     a65:	48 85 c0             	test   %rax,%rax
     a68:	0f 84 20 18 00 00    	je     0x228e
     a6e:	f6 00 88             	testb  $0x88,(%rax)
     a71:	0f 85 ff fc ff ff    	jne    0x776
     a77:	66 c7 44 24 62 00 00 	movw   $0x0,0x62(%rsp)
     a7e:	e9 f3 fc ff ff       	jmp    0x776
     a83:	49 8d 54 24 3e       	lea    0x3e(%r12),%rdx
     a88:	f6 c1 01             	test   $0x1,%cl
     a8b:	48 0f 44 d5          	cmove  %rbp,%rdx
     a8f:	48 8d 72 08          	lea    0x8(%rdx),%rsi
     a93:	4c 39 ce             	cmp    %r9,%rsi
     a96:	0f 87 ec 17 00 00    	ja     0x2288
     a9c:	4c 89 4c 24 38       	mov    %r9,0x38(%rsp)
     aa1:	66 44 89 44 24 34    	mov    %r8w,0x34(%rsp)
     aa7:	f6 c1 01             	test   $0x1,%cl
     aaa:	0f 85 cb 00 00 00    	jne    0xb7b
     ab0:	0f b7 0a             	movzwl (%rdx),%ecx
     ab3:	66 89 4c 24 60       	mov    %cx,0x60(%rsp)
     ab8:	0f b7 4a 02          	movzwl 0x2(%rdx),%ecx
     abc:	e9 c6 00 00 00       	jmp    0xb87
     ac1:	41 80 7c 24 23 04    	cmpb   $0x4,0x23(%r12)
     ac7:	75 68                	jne    0xb31
     ac9:	4c 89 4c 24 38       	mov    %r9,0x38(%rsp)
     ace:	66 44 89 44 24 34    	mov    %r8w,0x34(%rsp)
     ad4:	c7 04 24 0d 02 00 00 	movl   $0x20d,(%rsp)
     adb:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     ae2:	8b ff ff 
     ae5:	48 89 e6             	mov    %rsp,%rsi
     ae8:	b8 01 00 00 00       	mov    $0x1,%eax
     aed:	8b 06                	mov    (%rsi),%eax
     aef:	3d 00 04 00 00       	cmp    $0x400,%eax
     af4:	73 16                	jae    0xb0c
     af6:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     afd:	00 
     afe:	48 8b 00             	mov    (%rax),%rax
     b01:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     b08:	2b 9e 
     b0a:	eb 02                	jmp    0xb0e
     b0c:	31 c0                	xor    %eax,%eax
     b0e:	48 85 c0             	test   %rax,%rax
     b11:	0f 84 71 17 00 00    	je     0x2288
     b17:	48 ff 00             	incq   (%rax)
     b1a:	41 80 7c 24 28 04    	cmpb   $0x4,0x28(%r12)
     b20:	77 04                	ja     0xb26
     b22:	48 ff 40 08          	incq   0x8(%rax)
     b26:	44 0f b7 44 24 34    	movzwl 0x34(%rsp),%r8d
     b2c:	4c 8b 4c 24 38       	mov    0x38(%rsp),%r9
     b31:	49 8d 44 24 3e       	lea    0x3e(%r12),%rax
     b36:	4c 39 c8             	cmp    %r9,%rax
     b39:	0f 87 49 17 00 00    	ja     0x2288
     b3f:	41 0f b6 45 00       	movzbl 0x0(%r13),%eax
     b44:	24 0f                	and    $0xf,%al
     b46:	3c 05                	cmp    $0x5,%al
     b48:	0f 85 3a 17 00 00    	jne    0x2288
     b4e:	41 0f b6 44 24 33    	movzbl 0x33(%r12),%eax
     b54:	88 44 24 64          	mov    %al,0x64(%rsp)
     b58:	0f b6 4c 24 6c       	movzbl 0x6c(%rsp),%ecx
     b5d:	80 c9 01             	or     $0x1,%cl
     b60:	88 4c 24 6c          	mov    %cl,0x6c(%rsp)
     b64:	41 8b 54 24 3a       	mov    0x3a(%r12),%edx
     b69:	89 54 24 40          	mov    %edx,0x40(%rsp)
     b6d:	41 8b 54 24 36       	mov    0x36(%r12),%edx
     b72:	89 54 24 50          	mov    %edx,0x50(%rsp)
     b76:	e9 6f fa ff ff       	jmp    0x5ea
     b7b:	0f b7 4a 02          	movzwl 0x2(%rdx),%ecx
     b7f:	66 89 4c 24 60       	mov    %cx,0x60(%rsp)
     b84:	0f b7 0a             	movzwl (%rdx),%ecx
     b87:	66 89 4c 24 62       	mov    %cx,0x62(%rsp)
     b8c:	8b 54 24 50          	mov    0x50(%rsp),%edx
     b90:	89 94 24 80 00 00 00 	mov    %edx,0x80(%rsp)
     b97:	66 89 8c 24 90 00 00 	mov    %cx,0x90(%rsp)
     b9e:	00 
     b9f:	88 84 24 92 00 00 00 	mov    %al,0x92(%rsp)
     ba6:	48 bf 00 58 01 56 10 	movabs $0xffff8b1056015800,%rdi
     bad:	8b ff ff 
     bb0:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     bb7:	00 
     bb8:	b8 01 00 00 00       	mov    $0x1,%eax
     bbd:	e8 e2 0d ec da       	call   0xffffffffdaec19a4
     bc2:	48 85 c0             	test   %rax,%rax
     bc5:	74 04                	je     0xbcb
     bc7:	48 83 c0 48          	add    $0x48,%rax
     bcb:	48 85 c0             	test   %rax,%rax
     bce:	0f 84 0b 02 00 00    	je     0xddf
     bd4:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
     bd9:	4c 29 e1             	sub    %r12,%rcx
     bdc:	41 bd 01 00 00 00    	mov    $0x1,%r13d
     be2:	48 81 f9 ea 05 00 00 	cmp    $0x5ea,%rcx
     be9:	0f 8f 9f 16 00 00    	jg     0x228e
     bef:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
     bf4:	c7 84 24 9c 00 00 00 	movl   $0x200,0x9c(%rsp)
     bfb:	00 02 00 00 
     bff:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     c06:	8b ff ff 
     c09:	48 8d b4 24 9c 00 00 	lea    0x9c(%rsp),%rsi
     c10:	00 
     c11:	b8 01 00 00 00       	mov    $0x1,%eax
     c16:	8b 06                	mov    (%rsi),%eax
     c18:	3d 00 04 00 00       	cmp    $0x400,%eax
     c1d:	73 16                	jae    0xc35
     c1f:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     c26:	00 
     c27:	48 8b 00             	mov    (%rax),%rax
     c2a:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     c31:	2b 9e 
     c33:	eb 02                	jmp    0xc37
     c35:	31 c0                	xor    %eax,%eax
     c37:	48 85 c0             	test   %rax,%rax
     c3a:	0f 84 48 16 00 00    	je     0x2288
     c40:	48 89 84 24 b0 00 00 	mov    %rax,0xb0(%rsp)
     c47:	00 
     c48:	48 ff 00             	incq   (%rax)
     c4b:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
     c50:	41 f6 45 00 01       	testb  $0x1,0x0(%r13)
     c55:	74 07                	je     0xc5e
     c57:	66 c7 44 24 60 00 00 	movw   $0x0,0x60(%rsp)
     c5e:	41 8b 45 04          	mov    0x4(%r13),%eax
     c62:	89 44 24 70          	mov    %eax,0x70(%rsp)
     c66:	89 84 24 a4 00 00 00 	mov    %eax,0xa4(%rsp)
     c6d:	b8 08 00 00 00       	mov    $0x8,%eax
     c72:	48 c7 c0 34 10 2b 9e 	mov    $0xffffffff9e2b1034,%rax
     c79:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     c80:	2b 9e 
     c82:	8b 40 00             	mov    0x0(%rax),%eax
     c85:	89 84 24 98 00 00 00 	mov    %eax,0x98(%rsp)
     c8c:	48 bf 00 d8 2a 56 10 	movabs $0xffff8b10562ad800,%rdi
     c93:	8b ff ff 
     c96:	48 8d b4 24 98 00 00 	lea    0x98(%rsp),%rsi
     c9d:	00 
     c9e:	b8 01 00 00 00       	mov    $0x1,%eax
     ca3:	e8 ac 58 ec da       	call   0xffffffffdaec6554
     ca8:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     cad:	48 85 c0             	test   %rax,%rax
     cb0:	75 5a                	jne    0xd0c
     cb2:	c7 04 24 03 02 00 00 	movl   $0x203,(%rsp)
     cb9:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     cc0:	8b ff ff 
     cc3:	48 89 e6             	mov    %rsp,%rsi
     cc6:	b8 01 00 00 00       	mov    $0x1,%eax
     ccb:	8b 06                	mov    (%rsi),%eax
     ccd:	3d 00 04 00 00       	cmp    $0x400,%eax
     cd2:	73 16                	jae    0xcea
     cd4:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     cdb:	00 
     cdc:	48 8b 00             	mov    (%rax),%rax
     cdf:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     ce6:	2b 9e 
     ce8:	eb 02                	jmp    0xcec
     cea:	31 c0                	xor    %eax,%eax
     cec:	48 85 c0             	test   %rax,%rax
     cef:	0f 84 93 15 00 00    	je     0x2288
     cf5:	48 ff 00             	incq   (%rax)
     cf8:	48 b8 00 50 01 56 10 	movabs $0xffff8b1056015000,%rax
     cff:	8b ff ff 
     d02:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     d07:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
     d0c:	41 f6 45 00 04       	testb  $0x4,0x0(%r13)
     d11:	0f 84 88 0e 00 00    	je     0x1b9f
     d17:	f6 44 24 6c 01       	testb  $0x1,0x6c(%rsp)
     d1c:	0f 85 27 02 00 00    	jne    0xf49
     d22:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%rsp)
     d29:	00 
     d2a:	48 bf 00 82 20 83 0f 	movabs $0xffff8b0f83208200,%rdi
     d31:	8b ff ff 
     d34:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
     d39:	b8 01 00 00 00       	mov    $0x1,%eax
     d3e:	8b 06                	mov    (%rsi),%eax
     d40:	83 f8 01             	cmp    $0x1,%eax
     d43:	73 16                	jae    0xd5b
     d45:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     d4c:	00 
     d4d:	48 8b 00             	mov    (%rax),%rax
     d50:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     d57:	2b 9e 
     d59:	eb 02                	jmp    0xd5d
     d5b:	31 c0                	xor    %eax,%eax
     d5d:	48 85 c0             	test   %rax,%rax
     d60:	0f 84 22 15 00 00    	je     0x2288
     d66:	49 89 c5             	mov    %rax,%r13
     d69:	49 83 c4 3e          	add    $0x3e,%r12
     d6d:	f6 44 24 6c 01       	testb  $0x1,0x6c(%rsp)
     d72:	4c 0f 44 e5          	cmove  %rbp,%r12
     d76:	49 8d 4c 24 09       	lea    0x9(%r12),%rcx
     d7b:	48 3b 4c 24 38       	cmp    0x38(%rsp),%rcx
     d80:	0f 87 10 0e 00 00    	ja     0x1b96
     d86:	41 0f b6 44 24 08    	movzbl 0x8(%r12),%eax
     d8c:	84 c0                	test   %al,%al
     d8e:	0f 88 79 02 00 00    	js     0x100d
     d94:	49 83 c4 11          	add    $0x11,%r12
     d98:	4c 3b 64 24 38       	cmp    0x38(%rsp),%r12
     d9d:	0f 87 f3 0d 00 00    	ja     0x1b96
     da3:	0f b6 11             	movzbl (%rcx),%edx
     da6:	89 d0                	mov    %edx,%eax
     da8:	c1 e8 06             	shr    $0x6,%eax
     dab:	83 f8 03             	cmp    $0x3,%eax
     dae:	0f 84 cb 0b 00 00    	je     0x197f
     db4:	83 f8 02             	cmp    $0x2,%eax
     db7:	0f 84 ac 0b 00 00    	je     0x1969
     dbd:	83 f8 01             	cmp    $0x1,%eax
     dc0:	0f 85 d0 0d 00 00    	jne    0x1b96
     dc6:	83 e2 3f             	and    $0x3f,%edx
     dc9:	c1 e2 0a             	shl    $0xa,%edx
     dcc:	0f b6 71 01          	movzbl 0x1(%rcx),%esi
     dd0:	8d 14 b2             	lea    (%rdx,%rsi,4),%edx
     dd3:	0f b6 49 02          	movzbl 0x2(%rcx),%ecx
     dd7:	c0 e9 06             	shr    $0x6,%cl
     dda:	e9 bd 0b 00 00       	jmp    0x199c
     ddf:	66 c7 84 24 90 00 00 	movw   $0x0,0x90(%rsp)
     de6:	00 00 00 
     de9:	48 bf 00 58 01 56 10 	movabs $0xffff8b1056015800,%rdi
     df0:	8b ff ff 
     df3:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     dfa:	00 
     dfb:	b8 01 00 00 00       	mov    $0x1,%eax
     e00:	e8 9f 0b ec da       	call   0xffffffffdaec19a4
     e05:	48 85 c0             	test   %rax,%rax
     e08:	74 04                	je     0xe0e
     e0a:	48 83 c0 48          	add    $0x48,%rax
     e0e:	48 85 c0             	test   %rax,%rax
     e11:	0f 84 77 14 00 00    	je     0x228e
     e17:	f6 00 88             	testb  $0x88,(%rax)
     e1a:	0f 85 b4 fd ff ff    	jne    0xbd4
     e20:	66 c7 44 24 62 00 00 	movw   $0x0,0x62(%rsp)
     e27:	e9 a8 fd ff ff       	jmp    0xbd4
     e2c:	4c 89 4c 24 38       	mov    %r9,0x38(%rsp)
     e31:	45 89 c5             	mov    %r8d,%r13d
     e34:	c7 04 24 0c 02 00 00 	movl   $0x20c,(%rsp)
     e3b:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     e42:	8b ff ff 
     e45:	48 89 e6             	mov    %rsp,%rsi
     e48:	b8 01 00 00 00       	mov    $0x1,%eax
     e4d:	8b 06                	mov    (%rsi),%eax
     e4f:	3d 00 04 00 00       	cmp    $0x400,%eax
     e54:	73 16                	jae    0xe6c
     e56:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     e5d:	00 
     e5e:	48 8b 00             	mov    (%rax),%rax
     e61:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     e68:	2b 9e 
     e6a:	eb 02                	jmp    0xe6e
     e6c:	31 c0                	xor    %eax,%eax
     e6e:	48 85 c0             	test   %rax,%rax
     e71:	0f 84 11 14 00 00    	je     0x2288
     e77:	48 ff 00             	incq   (%rax)
     e7a:	41 0f 38 f0 4c 24 26 	movbe  0x26(%r12),%ecx
     e81:	81 f9 ff 04 00 00    	cmp    $0x4ff,%ecx
     e87:	45 89 e8             	mov    %r13d,%r8d
     e8a:	4c 8b 4c 24 38       	mov    0x38(%rsp),%r9
     e8f:	77 04                	ja     0xe95
     e91:	48 ff 40 08          	incq   0x8(%rax)
     e95:	49 8d 44 24 52       	lea    0x52(%r12),%rax
     e9a:	4c 39 c8             	cmp    %r9,%rax
     e9d:	0f 87 e5 13 00 00    	ja     0x2288
     ea3:	41 0f b6 44 24 30    	movzbl 0x30(%r12),%eax
     ea9:	88 44 24 64          	mov    %al,0x64(%rsp)
     ead:	48 8d 54 24 50       	lea    0x50(%rsp),%rdx
     eb2:	0f b6 4c 24 6c       	movzbl 0x6c(%rsp),%ecx
     eb7:	80 c9 01             	or     $0x1,%cl
     eba:	88 4c 24 6c          	mov    %cl,0x6c(%rsp)
     ebe:	49 8b 74 24 42       	mov    0x42(%r12),%rsi
     ec3:	49 8b 7c 24 4a       	mov    0x4a(%r12),%rdi
     ec8:	48 89 7c 24 48       	mov    %rdi,0x48(%rsp)
     ecd:	48 89 74 24 40       	mov    %rsi,0x40(%rsp)
     ed2:	49 8b 74 24 32       	mov    0x32(%r12),%rsi
     ed7:	49 8b 7c 24 3a       	mov    0x3a(%r12),%rdi
     edc:	48 89 32             	mov    %rsi,(%rdx)
     edf:	48 89 7a 08          	mov    %rdi,0x8(%rdx)
     ee3:	e9 02 f7 ff ff       	jmp    0x5ea
     ee8:	c7 04 24 0b 02 00 00 	movl   $0x20b,(%rsp)
     eef:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     ef6:	8b ff ff 
     ef9:	48 89 e6             	mov    %rsp,%rsi
     efc:	b8 01 00 00 00       	mov    $0x1,%eax
     f01:	8b 06                	mov    (%rsi),%eax
     f03:	3d 00 04 00 00       	cmp    $0x400,%eax
     f08:	73 16                	jae    0xf20
     f0a:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     f11:	00 
     f12:	48 8b 00             	mov    (%rax),%rax
     f15:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     f1c:	2b 9e 
     f1e:	eb 02                	jmp    0xf22
     f20:	31 c0                	xor    %eax,%eax
     f22:	48 85 c0             	test   %rax,%rax
     f25:	0f 84 5d 13 00 00    	je     0x2288
     f2b:	48 ff 00             	incq   (%rax)
     f2e:	41 0f b6 4c 24 37    	movzbl 0x37(%r12),%ecx
     f34:	80 c1 fd             	add    $0xfd,%cl
     f37:	80 f9 01             	cmp    $0x1,%cl
     f3a:	0f 87 b5 01 00 00    	ja     0x10f5
     f40:	48 ff 40 08          	incq   0x8(%rax)
     f44:	e9 ac 01 00 00       	jmp    0x10f5
     f49:	c7 04 24 0b 02 00 00 	movl   $0x20b,(%rsp)
     f50:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
     f57:	8b ff ff 
     f5a:	48 89 e6             	mov    %rsp,%rsi
     f5d:	b8 01 00 00 00       	mov    $0x1,%eax
     f62:	8b 06                	mov    (%rsi),%eax
     f64:	3d 00 04 00 00       	cmp    $0x400,%eax
     f69:	73 16                	jae    0xf81
     f6b:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     f72:	00 
     f73:	48 8b 00             	mov    (%rax),%rax
     f76:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     f7d:	2b 9e 
     f7f:	eb 02                	jmp    0xf83
     f81:	31 c0                	xor    %eax,%eax
     f83:	48 85 c0             	test   %rax,%rax
     f86:	0f 84 fc 12 00 00    	je     0x2288
     f8c:	48 ff 00             	incq   (%rax)
     f8f:	41 0f b6 4c 24 23    	movzbl 0x23(%r12),%ecx
     f95:	83 c9 02             	or     $0x2,%ecx
     f98:	83 f9 03             	cmp    $0x3,%ecx
     f9b:	0f 85 f9 0b 00 00    	jne    0x1b9a
     fa1:	48 ff 40 08          	incq   0x8(%rax)
     fa5:	e9 f0 0b 00 00       	jmp    0x1b9a
     faa:	49 8d 54 24 16       	lea    0x16(%r12),%rdx
     faf:	48 39 ea             	cmp    %rbp,%rdx
     fb2:	0f 87 3a 01 00 00    	ja     0x10f2
     fb8:	f6 c1 20             	test   $0x20,%cl
     fbb:	0f 85 b3 00 00 00    	jne    0x1074
     fc1:	48 ff 40 08          	incq   0x8(%rax)
     fc5:	8b 44 24 70          	mov    0x70(%rsp),%eax
     fc9:	89 04 24             	mov    %eax,(%rsp)
     fcc:	48 bf 00 a0 d1 82 0f 	movabs $0xffff8b0f82d1a000,%rdi
     fd3:	8b ff ff 
     fd6:	48 89 e6             	mov    %rsp,%rsi
     fd9:	b8 01 00 00 00       	mov    $0x1,%eax
     fde:	8b 06                	mov    (%rsi),%eax
     fe0:	3d 00 02 00 00       	cmp    $0x200,%eax
     fe5:	73 16                	jae    0xffd
     fe7:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
     fee:	00 
     fef:	48 8b 00             	mov    (%rax),%rax
     ff2:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
     ff9:	2b 9e 
     ffb:	eb 02                	jmp    0xfff
     ffd:	31 c0                	xor    %eax,%eax
     fff:	48 85 c0             	test   %rax,%rax
    1002:	0f 85 ea 00 00 00    	jne    0x10f2
    1008:	e9 e8 00 00 00       	jmp    0x10f5
    100d:	49 8d 4c 24 16       	lea    0x16(%r12),%rcx
    1012:	48 3b 4c 24 38       	cmp    0x38(%rsp),%rcx
    1017:	0f 87 79 0b 00 00    	ja     0x1b96
    101d:	a8 20                	test   $0x20,%al
    101f:	0f 85 23 09 00 00    	jne    0x1948
    1025:	49 ff 45 08          	incq   0x8(%r13)
    1029:	8b 44 24 70          	mov    0x70(%rsp),%eax
    102d:	89 04 24             	mov    %eax,(%rsp)
    1030:	48 bf 00 a0 d1 82 0f 	movabs $0xffff8b0f82d1a000,%rdi
    1037:	8b ff ff 
    103a:	48 89 e6             	mov    %rsp,%rsi
    103d:	b8 01 00 00 00       	mov    $0x1,%eax
    1042:	8b 06                	mov    (%rsi),%eax
    1044:	3d 00 02 00 00       	cmp    $0x200,%eax
    1049:	73 16                	jae    0x1061
    104b:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1052:	00 
    1053:	48 8b 00             	mov    (%rax),%rax
    1056:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    105d:	2b 9e 
    105f:	eb 02                	jmp    0x1063
    1061:	31 c0                	xor    %eax,%eax
    1063:	48 85 c0             	test   %rax,%rax
    1066:	0f 84 2e 0b 00 00    	je     0x1b9a
    106c:	48 ff 00             	incq   (%rax)
    106f:	e9 26 0b 00 00       	jmp    0x1b9a
    1074:	41 80 7c 24 0d 07    	cmpb   $0x7,0xd(%r12)
    107a:	76 76                	jbe    0x10f2
    107c:	49 83 c4 0e          	add    $0xe,%r12
    1080:	4c 89 e2             	mov    %r12,%rdx
    1083:	e9 b6 f8 ff ff       	jmp    0x93e
    1088:	0f b6 72 01          	movzbl 0x1(%rdx),%esi
    108c:	c1 e6 10             	shl    $0x10,%esi
    108f:	0f b6 42 02          	movzbl 0x2(%rdx),%eax
    1093:	c1 e0 08             	shl    $0x8,%eax
    1096:	09 f0                	or     %esi,%eax
    1098:	0f b6 52 03          	movzbl 0x3(%rdx),%edx
    109c:	eb 1d                	jmp    0x10bb
    109e:	0f b6 42 01          	movzbl 0x1(%rdx),%eax
    10a2:	c1 e0 18             	shl    $0x18,%eax
    10a5:	0f b6 72 02          	movzbl 0x2(%rdx),%esi
    10a9:	c1 e6 10             	shl    $0x10,%esi
    10ac:	09 c6                	or     %eax,%esi
    10ae:	0f b6 42 03          	movzbl 0x3(%rdx),%eax
    10b2:	c1 e0 08             	shl    $0x8,%eax
    10b5:	09 f0                	or     %esi,%eax
    10b7:	0f b6 52 04          	movzbl 0x4(%rdx),%edx
    10bb:	44 0f b6 e2          	movzbl %dl,%r12d
    10bf:	49 09 c4             	or     %rax,%r12
    10c2:	45 85 e4             	test   %r12d,%r12d
    10c5:	48 89 e8             	mov    %rbp,%rax
    10c8:	7e 28                	jle    0x10f2
    10ca:	48 89 e8             	mov    %rbp,%rax
    10cd:	48 83 f9 03          	cmp    $0x3,%rcx
    10d1:	0f 84 ab 07 00 00    	je     0x1882
    10d7:	83 f9 02             	cmp    $0x2,%ecx
    10da:	0f 84 9c 07 00 00    	je     0x187c
    10e0:	83 f9 01             	cmp    $0x1,%ecx
    10e3:	0f 85 9f 07 00 00    	jne    0x1888
    10e9:	48 83 c0 38          	add    $0x38,%rax
    10ed:	e9 9a 07 00 00       	jmp    0x188c
    10f2:	48 ff 00             	incq   (%rax)
    10f5:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    10fa:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    10ff:	89 4c 24 38          	mov    %ecx,0x38(%rsp)
    1103:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    1108:	75 67                	jne    0x1171
    110a:	41 f6 45 00 02       	testb  $0x2,0x0(%r13)
    110f:	75 60                	jne    0x1171
    1111:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    1116:	b8 01 00 00 00       	mov    $0x1,%eax
    111b:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    1120:	e8 7f 08 ec da       	call   0xffffffffdaec19a4
    1125:	48 85 c0             	test   %rax,%rax
    1128:	74 14                	je     0x113e
    112a:	80 b8 23 00 00 00 00 	cmpb   $0x0,0x23(%rax)
    1131:	75 07                	jne    0x113a
    1133:	c6 80 23 00 00 00 01 	movb   $0x1,0x23(%rax)
    113a:	48 83 c0 58          	add    $0x58,%rax
    113e:	48 85 c0             	test   %rax,%rax
    1141:	74 2a                	je     0x116d
    1143:	49 89 c5             	mov    %rax,%r13
    1146:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    114b:	75 2c                	jne    0x1179
    114d:	b8 05 00 00 00       	mov    $0x5,%eax
    1152:	e8 ad 2c eb da       	call   0xffffffffdaeb3e04
    1157:	48 89 c1             	mov    %rax,%rcx
    115a:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    115e:	48 ba 00 ac 23 fc 06 	movabs $0x6fc23ac00,%rdx
    1165:	00 00 00 
    1168:	48 39 d1             	cmp    %rdx,%rcx
    116b:	76 08                	jbe    0x1175
    116d:	31 ed                	xor    %ebp,%ebp
    116f:	eb 45                	jmp    0x11b6
    1171:	31 ed                	xor    %ebp,%ebp
    1173:	eb 46                	jmp    0x11bb
    1175:	49 89 45 08          	mov    %rax,0x8(%r13)
    1179:	41 8b 45 00          	mov    0x0(%r13),%eax
    117d:	89 04 24             	mov    %eax,(%rsp)
    1180:	89 44 24 68          	mov    %eax,0x68(%rsp)
    1184:	48 bf 00 00 8c 40 86 	movabs $0xffffd286408c0000,%rdi
    118b:	d2 ff ff 
    118e:	48 89 e6             	mov    %rsp,%rsi
    1191:	b8 01 00 00 00       	mov    $0x1,%eax
    1196:	8b 06                	mov    (%rsi),%eax
    1198:	3d 00 10 00 00       	cmp    $0x1000,%eax
    119d:	73 12                	jae    0x11b1
    119f:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    11a6:	48 01 f8             	add    %rdi,%rax
    11a9:	48 05 30 01 00 00    	add    $0x130,%rax
    11af:	eb 02                	jmp    0x11b3
    11b1:	31 c0                	xor    %eax,%eax
    11b3:	48 89 c5             	mov    %rax,%rbp
    11b6:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    11bb:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    11c0:	0f 85 0f 01 00 00    	jne    0x12d5
    11c6:	41 f6 45 01 02       	testb  $0x2,0x1(%r13)
    11cb:	0f 84 04 01 00 00    	je     0x12d5
    11d1:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    11d8:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    11df:	8b ff ff 
    11e2:	48 89 e6             	mov    %rsp,%rsi
    11e5:	b8 01 00 00 00       	mov    $0x1,%eax
    11ea:	8b 06                	mov    (%rsi),%eax
    11ec:	3d 00 04 00 00       	cmp    $0x400,%eax
    11f1:	73 16                	jae    0x1209
    11f3:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    11fa:	00 
    11fb:	48 8b 00             	mov    (%rax),%rax
    11fe:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1205:	2b 9e 
    1207:	eb 02                	jmp    0x120b
    1209:	31 c0                	xor    %eax,%eax
    120b:	48 85 c0             	test   %rax,%rax
    120e:	0f 84 c1 00 00 00    	je     0x12d5
    1214:	49 89 c5             	mov    %rax,%r13
    1217:	b8 05 00 00 00       	mov    $0x5,%eax
    121c:	e8 e3 2b eb da       	call   0xffffffffdaeb3e04
    1221:	48 89 c1             	mov    %rax,%rcx
    1224:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    1228:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    122f:	72 0e                	jb     0x123f
    1231:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    1238:	00 
    1239:	49 89 45 08          	mov    %rax,0x8(%r13)
    123d:	eb 17                	jmp    0x1256
    123f:	49 8b 45 00          	mov    0x0(%r13),%rax
    1243:	48 ff c0             	inc    %rax
    1246:	49 89 45 00          	mov    %rax,0x0(%r13)
    124a:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    1250:	0f 83 7f 00 00 00    	jae    0x12d5
    1256:	48 bf 00 28 01 56 10 	movabs $0xffff8b1056012800,%rdi
    125d:	8b ff ff 
    1260:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
    1267:	00 
    1268:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    126e:	e8 61 27 eb da       	call   0xffffffffdaeb39d4
    1273:	48 85 c0             	test   %rax,%rax
    1276:	74 5d                	je     0x12d5
    1278:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    127d:	48 89 c7             	mov    %rax,%rdi
    1280:	e8 4f 27 eb da       	call   0xffffffffdaeb39d4
    1285:	48 85 c0             	test   %rax,%rax
    1288:	74 4b                	je     0x12d5
    128a:	c7 04 24 0f 02 00 00 	movl   $0x20f,(%rsp)
    1291:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1298:	8b ff ff 
    129b:	48 89 e6             	mov    %rsp,%rsi
    129e:	b8 01 00 00 00       	mov    $0x1,%eax
    12a3:	8b 06                	mov    (%rsi),%eax
    12a5:	3d 00 04 00 00       	cmp    $0x400,%eax
    12aa:	73 16                	jae    0x12c2
    12ac:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    12b3:	00 
    12b4:	48 8b 00             	mov    (%rax),%rax
    12b7:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    12be:	2b 9e 
    12c0:	eb 02                	jmp    0x12c4
    12c2:	31 c0                	xor    %eax,%eax
    12c4:	48 85 c0             	test   %rax,%rax
    12c7:	0f 84 c9 01 00 00    	je     0x1496
    12cd:	48 ff 00             	incq   (%rax)
    12d0:	e9 c1 01 00 00       	jmp    0x1496
    12d5:	48 85 ed             	test   %rbp,%rbp
    12d8:	0f 84 b8 01 00 00    	je     0x1496
    12de:	48 bf 00 24 8e 83 0f 	movabs $0xffff8b0f838e2400,%rdi
    12e5:	8b ff ff 
    12e8:	48 8d b4 24 a0 00 00 	lea    0xa0(%rsp),%rsi
    12ef:	00 
    12f0:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    12f6:	8b 06                	mov    (%rsi),%eax
    12f8:	83 f8 10             	cmp    $0x10,%eax
    12fb:	73 0a                	jae    0x1307
    12fd:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1304:	00 
    1305:	eb 02                	jmp    0x1309
    1307:	31 c0                	xor    %eax,%eax
    1309:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    130f:	48 85 c0             	test   %rax,%rax
    1312:	0f 84 76 0f 00 00    	je     0x228e
    1318:	48 89 6c 24 70       	mov    %rbp,0x70(%rsp)
    131d:	48 89 c5             	mov    %rax,%rbp
    1320:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1327:	8b ff ff 
    132a:	48 8d b4 24 a4 00 00 	lea    0xa4(%rsp),%rsi
    1331:	00 
    1332:	8b 06                	mov    (%rsi),%eax
    1334:	3d 00 04 00 00       	cmp    $0x400,%eax
    1339:	73 16                	jae    0x1351
    133b:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1342:	00 
    1343:	48 8b 00             	mov    (%rax),%rax
    1346:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    134d:	2b 9e 
    134f:	eb 02                	jmp    0x1353
    1351:	31 c0                	xor    %eax,%eax
    1353:	48 85 c0             	test   %rax,%rax
    1356:	0f 84 32 0f 00 00    	je     0x228e
    135c:	48 ff 00             	incq   (%rax)
    135f:	44 0f b7 64 24 34    	movzwl 0x34(%rsp),%r12d
    1365:	4c 01 60 08          	add    %r12,0x8(%rax)
    1369:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    136e:	48 bf 00 d0 7b 40 86 	movabs $0xffffd286407bd000,%rdi
    1375:	d2 ff ff 
    1378:	b8 01 00 00 00       	mov    $0x1,%eax
    137d:	8b 06                	mov    (%rsi),%eax
    137f:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1384:	73 16                	jae    0x139c
    1386:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    138d:	00 
    138e:	48 8b 00             	mov    (%rax),%rax
    1391:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1398:	2b 9e 
    139a:	eb 02                	jmp    0x139e
    139c:	31 c0                	xor    %eax,%eax
    139e:	48 85 c0             	test   %rax,%rax
    13a1:	0f 84 e7 0e 00 00    	je     0x228e
    13a7:	48 ff 00             	incq   (%rax)
    13aa:	4c 01 60 08          	add    %r12,0x8(%rax)
    13ae:	8b 44 24 38          	mov    0x38(%rsp),%eax
    13b2:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    13b7:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
    13bc:	f6 40 10 01          	testb  $0x1,0x10(%rax)
    13c0:	0f 85 7f 03 00 00    	jne    0x1745
    13c6:	44 0f b7 64 24 42    	movzwl 0x42(%rsp),%r12d
    13cc:	b8 2c 00 00 00       	mov    $0x2c,%eax
    13d1:	4c 89 f7             	mov    %r14,%rdi
    13d4:	be ec ff ff ff       	mov    $0xffffffec,%esi
    13d9:	e8 76 d8 75 db       	call   0xffffffffdb75ec54
    13de:	85 c0                	test   %eax,%eax
    13e0:	0f 85 d8 0a 00 00    	jne    0x1ebe
    13e6:	49 8b 06             	mov    (%r14),%rax
    13e9:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    13ed:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    13f1:	48 39 ca             	cmp    %rcx,%rdx
    13f4:	0f 87 c4 0a 00 00    	ja     0x1ebe
    13fa:	48 8d 50 22          	lea    0x22(%rax),%rdx
    13fe:	48 39 ca             	cmp    %rcx,%rdx
    1401:	0f 87 b7 0a 00 00    	ja     0x1ebe
    1407:	8b 4c 24 38          	mov    0x38(%rsp),%ecx
    140b:	66 c1 c1 08          	rol    $0x8,%cx
    140f:	41 31 cc             	xor    %ecx,%r12d
    1412:	41 c1 e4 10          	shl    $0x10,%r12d
    1416:	0f b7 4d 04          	movzwl 0x4(%rbp),%ecx
    141a:	66 89 48 04          	mov    %cx,0x4(%rax)
    141e:	8b 4d 00             	mov    0x0(%rbp),%ecx
    1421:	89 08                	mov    %ecx,(%rax)
    1423:	8b 48 14             	mov    0x14(%rax),%ecx
    1426:	89 48 06             	mov    %ecx,0x6(%rax)
    1429:	0f b7 48 18          	movzwl 0x18(%rax),%ecx
    142d:	66 89 48 0a          	mov    %cx,0xa(%rax)
    1431:	66 c7 40 0c 08 00    	movw   $0x8,0xc(%rax)
    1437:	41 8d 8c 24 ac 10 00 	lea    0x10ac(%r12),%ecx
    143e:	00 
    143f:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    1444:	48 8b 74 24 70       	mov    0x70(%rsp),%rsi
    1449:	8b 36                	mov    (%rsi),%esi
    144b:	c6 40 0e 45          	movb   $0x45,0xe(%rax)
    144f:	88 50 0f             	mov    %dl,0xf(%rax)
    1452:	8b 54 24 34          	mov    0x34(%rsp),%edx
    1456:	83 c2 14             	add    $0x14,%edx
    1459:	66 0f 38 f1 50 10    	movbe  %dx,0x10(%rax)
    145f:	66 c1 c2 08          	rol    $0x8,%dx
    1463:	c7 40 12 00 00 00 00 	movl   $0x0,0x12(%rax)
    146a:	89 70 1e             	mov    %esi,0x1e(%rax)
    146d:	89 48 1a             	mov    %ecx,0x1a(%rax)
    1470:	66 c7 40 16 40 04    	movw   $0x440,0x16(%rax)
    1476:	0f b7 48 0e          	movzwl 0xe(%rax),%ecx
    147a:	0f b7 d2             	movzwl %dx,%edx
    147d:	0f b7 78 16          	movzwl 0x16(%rax),%edi
    1481:	48 01 cf             	add    %rcx,%rdi
    1484:	41 c1 ec 10          	shr    $0x10,%r12d
    1488:	49 01 fc             	add    %rdi,%r12
    148b:	0f b7 ce             	movzwl %si,%ecx
    148e:	4c 01 e1             	add    %r12,%rcx
    1491:	e9 a8 0f 00 00       	jmp    0x243e
    1496:	80 7c 24 64 06       	cmpb   $0x6,0x64(%rsp)
    149b:	75 51                	jne    0x14ee
    149d:	c7 04 24 01 02 00 00 	movl   $0x201,(%rsp)
    14a4:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    14ab:	8b ff ff 
    14ae:	48 89 e6             	mov    %rsp,%rsi
    14b1:	b8 01 00 00 00       	mov    $0x1,%eax
    14b6:	8b 06                	mov    (%rsi),%eax
    14b8:	3d 00 04 00 00       	cmp    $0x400,%eax
    14bd:	73 16                	jae    0x14d5
    14bf:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    14c6:	00 
    14c7:	48 8b 00             	mov    (%rax),%rax
    14ca:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    14d1:	2b 9e 
    14d3:	eb 02                	jmp    0x14d7
    14d5:	31 c0                	xor    %eax,%eax
    14d7:	48 85 c0             	test   %rax,%rax
    14da:	0f 84 a8 0d 00 00    	je     0x2288
    14e0:	31 c9                	xor    %ecx,%ecx
    14e2:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    14e7:	0f 94 c1             	sete   %cl
    14ea:	48 ff 04 c8          	incq   (%rax,%rcx,8)
    14ee:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    14f5:	00 00 
    14f7:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    14fe:	00 
    14ff:	c7 44 24 1c 02 02 00 	movl   $0x202,0x1c(%rsp)
    1506:	00 
    1507:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    150e:	8b ff ff 
    1511:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    1516:	b8 01 00 00 00       	mov    $0x1,%eax
    151b:	8b 06                	mov    (%rsi),%eax
    151d:	3d 00 04 00 00       	cmp    $0x400,%eax
    1522:	73 16                	jae    0x153a
    1524:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    152b:	00 
    152c:	48 8b 00             	mov    (%rax),%rax
    152f:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1536:	2b 9e 
    1538:	eb 02                	jmp    0x153c
    153a:	31 c0                	xor    %eax,%eax
    153c:	bd 01 00 00 00       	mov    $0x1,%ebp
    1541:	48 85 c0             	test   %rax,%rax
    1544:	74 2f                	je     0x1575
    1546:	49 89 c5             	mov    %rax,%r13
    1549:	b8 05 00 00 00       	mov    $0x5,%eax
    154e:	e8 b1 28 eb da       	call   0xffffffffdaeb3e04
    1553:	49 89 c4             	mov    %rax,%r12
    1556:	49 2b 45 08          	sub    0x8(%r13),%rax
    155a:	48 3d 01 ca 9a 3b    	cmp    $0x3b9aca01,%rax
    1560:	72 1d                	jb     0x157f
    1562:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    1569:	00 
    156a:	4d 89 65 08          	mov    %r12,0x8(%r13)
    156e:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    1573:	eb 22                	jmp    0x1597
    1575:	45 31 e4             	xor    %r12d,%r12d
    1578:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    157d:	eb 1a                	jmp    0x1599
    157f:	49 8b 45 00          	mov    0x0(%r13),%rax
    1583:	48 ff c0             	inc    %rax
    1586:	49 89 45 00          	mov    %rax,0x0(%r13)
    158a:	48 3d 48 e8 01 00    	cmp    $0x1e848,%rax
    1590:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    1595:	77 02                	ja     0x1599
    1597:	31 ed                	xor    %ebp,%ebp
    1599:	f6 00 08             	testb  $0x8,(%rax)
    159c:	74 1c                	je     0x15ba
    159e:	0f b7 44 24 62       	movzwl 0x62(%rsp),%eax
    15a3:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    15a8:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
    15af:	00 00 
    15b1:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
    15b8:	00 00 
    15ba:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
    15bf:	e8 14 11 00 00       	call   0x26d8
    15c4:	8b 74 24 60          	mov    0x60(%rsp),%esi
    15c8:	89 c7                	mov    %eax,%edi
    15ca:	e8 e8 11 00 00       	call   0x27b7
    15cf:	89 c1                	mov    %eax,%ecx
    15d1:	ba 01 00 ff ff       	mov    $0xffff0001,%edx
    15d6:	48 0f af d1          	imul   %rcx,%rdx
    15da:	48 c1 ea 30          	shr    $0x30,%rdx
    15de:	89 d1                	mov    %edx,%ecx
    15e0:	c1 e1 10             	shl    $0x10,%ecx
    15e3:	09 d1                	or     %edx,%ecx
    15e5:	29 c8                	sub    %ecx,%eax
    15e7:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
    15ec:	8b 49 04             	mov    0x4(%rcx),%ecx
    15ef:	89 ca                	mov    %ecx,%edx
    15f1:	c1 e2 10             	shl    $0x10,%edx
    15f4:	01 ca                	add    %ecx,%edx
    15f6:	01 c2                	add    %eax,%edx
    15f8:	89 54 24 24          	mov    %edx,0x24(%rsp)
    15fc:	48 bf 00 90 0d 42 86 	movabs $0xffffd286420d9000,%rdi
    1603:	d2 ff ff 
    1606:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    160b:	b8 01 00 00 00       	mov    $0x1,%eax
    1610:	8b 06                	mov    (%rsi),%eax
    1612:	3d 00 02 00 02       	cmp    $0x2000200,%eax
    1617:	73 0a                	jae    0x1623
    1619:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1620:	00 
    1621:	eb 02                	jmp    0x1625
    1623:	31 c0                	xor    %eax,%eax
    1625:	48 85 c0             	test   %rax,%rax
    1628:	0f 84 5a 0c 00 00    	je     0x2288
    162e:	8b 00                	mov    (%rax),%eax
    1630:	89 44 24 24          	mov    %eax,0x24(%rsp)
    1634:	85 c0                	test   %eax,%eax
    1636:	0f 84 c4 0b 00 00    	je     0x2200
    163c:	4d 89 e5             	mov    %r12,%r13
    163f:	89 44 24 68          	mov    %eax,0x68(%rsp)
    1643:	48 bf 00 00 8c 40 86 	movabs $0xffffd286408c0000,%rdi
    164a:	d2 ff ff 
    164d:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    1652:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    1658:	8b 06                	mov    (%rsi),%eax
    165a:	3d 00 10 00 00       	cmp    $0x1000,%eax
    165f:	73 12                	jae    0x1673
    1661:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    1668:	48 01 f8             	add    %rdi,%rax
    166b:	48 05 30 01 00 00    	add    $0x130,%rax
    1671:	eb 02                	jmp    0x1675
    1673:	31 c0                	xor    %eax,%eax
    1675:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
    167a:	48 85 c0             	test   %rax,%rax
    167d:	0f 84 c5 0b 00 00    	je     0x2248
    1683:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    1688:	0f b6 00             	movzbl (%rax),%eax
    168b:	24 02                	and    $0x2,%al
    168d:	d0 e8                	shr    $1,%al
    168f:	40 08 c5             	or     %al,%bpl
    1692:	75 33                	jne    0x16c7
    1694:	f6 44 24 6c 04       	testb  $0x4,0x6c(%rsp)
    1699:	75 2c                	jne    0x16c7
    169b:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    16a0:	75 05                	jne    0x16a7
    16a2:	4c 89 6c 24 08       	mov    %r13,0x8(%rsp)
    16a7:	8b 44 24 24          	mov    0x24(%rsp),%eax
    16ab:	89 04 24             	mov    %eax,(%rsp)
    16ae:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    16b3:	48 89 e2             	mov    %rsp,%rdx
    16b6:	b8 02 00 00 00       	mov    $0x2,%eax
    16bb:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    16c0:	31 c9                	xor    %ecx,%ecx
    16c2:	e8 2d 26 ec da       	call   0xffffffffdaec3cf4
    16c7:	c7 04 24 00 00 00 00 	movl   $0x0,(%rsp)
    16ce:	48 bf 00 8a 20 83 0f 	movabs $0xffff8b0f83208a00,%rdi
    16d5:	8b ff ff 
    16d8:	48 89 e6             	mov    %rsp,%rsi
    16db:	b8 01 00 00 00       	mov    $0x1,%eax
    16e0:	8b 06                	mov    (%rsi),%eax
    16e2:	83 f8 01             	cmp    $0x1,%eax
    16e5:	73 12                	jae    0x16f9
    16e7:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    16ee:	48 01 f8             	add    %rdi,%rax
    16f1:	48 05 30 01 00 00    	add    $0x130,%rax
    16f7:	eb 02                	jmp    0x16fb
    16f9:	31 c0                	xor    %eax,%eax
    16fb:	48 85 c0             	test   %rax,%rax
    16fe:	0f 84 84 0b 00 00    	je     0x2288
    1704:	8b 08                	mov    (%rax),%ecx
    1706:	3b 8c 24 80 00 00 00 	cmp    0x80(%rsp),%ecx
    170d:	0f 85 e5 00 00 00    	jne    0x17f8
    1713:	8b 48 04             	mov    0x4(%rax),%ecx
    1716:	3b 8c 24 84 00 00 00 	cmp    0x84(%rsp),%ecx
    171d:	0f 85 d5 00 00 00    	jne    0x17f8
    1723:	8b 48 08             	mov    0x8(%rax),%ecx
    1726:	3b 8c 24 88 00 00 00 	cmp    0x88(%rsp),%ecx
    172d:	0f 85 c5 00 00 00    	jne    0x17f8
    1733:	8b 48 0c             	mov    0xc(%rax),%ecx
    1736:	3b 8c 24 8c 00 00 00 	cmp    0x8c(%rsp),%ecx
    173d:	0f 94 c1             	sete   %cl
    1740:	e9 b5 00 00 00       	jmp    0x17fa
    1745:	b8 2c 00 00 00       	mov    $0x2c,%eax
    174a:	4c 89 f7             	mov    %r14,%rdi
    174d:	be d8 ff ff ff       	mov    $0xffffffd8,%esi
    1752:	e8 fd d4 75 db       	call   0xffffffffdb75ec54
    1757:	85 c0                	test   %eax,%eax
    1759:	0f 85 e7 0b 00 00    	jne    0x2346
    175f:	49 8b 06             	mov    (%r14),%rax
    1762:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    1766:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    176a:	48 39 ca             	cmp    %rcx,%rdx
    176d:	0f 87 d3 0b 00 00    	ja     0x2346
    1773:	48 8d 50 36          	lea    0x36(%rax),%rdx
    1777:	48 39 ca             	cmp    %rcx,%rdx
    177a:	0f 87 c6 0b 00 00    	ja     0x2346
    1780:	0f b7 4d 04          	movzwl 0x4(%rbp),%ecx
    1784:	66 89 48 04          	mov    %cx,0x4(%rax)
    1788:	8b 4d 00             	mov    0x0(%rbp),%ecx
    178b:	89 08                	mov    %ecx,(%rax)
    178d:	8b 48 28             	mov    0x28(%rax),%ecx
    1790:	89 48 06             	mov    %ecx,0x6(%rax)
    1793:	0f b7 48 2c          	movzwl 0x2c(%rax),%ecx
    1797:	66 89 48 0a          	mov    %cx,0xa(%rax)
    179b:	66 c7 40 0c 86 dd    	movw   $0xdd86,0xc(%rax)
    17a1:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    17a6:	33 4c 24 4c          	xor    0x4c(%rsp),%ecx
    17aa:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    17af:	66 c7 40 10 00 00    	movw   $0x0,0x10(%rax)
    17b5:	89 d6                	mov    %edx,%esi
    17b7:	40 c0 ee 04          	shr    $0x4,%sil
    17bb:	40 80 ce 60          	or     $0x60,%sil
    17bf:	40 88 70 0e          	mov    %sil,0xe(%rax)
    17c3:	c0 e2 04             	shl    $0x4,%dl
    17c6:	88 50 0f             	mov    %dl,0xf(%rax)
    17c9:	66 c7 40 14 29 40    	movw   $0x4029,0x14(%rax)
    17cf:	8b 54 24 34          	mov    0x34(%rsp),%edx
    17d3:	83 c2 28             	add    $0x28,%edx
    17d6:	66 0f 38 f1 50 12    	movbe  %dx,0x12(%rax)
    17dc:	48 c7 40 16 01 00 00 	movq   $0x1,0x16(%rax)
    17e3:	00 
    17e4:	c7 40 1e 00 00 00 00 	movl   $0x0,0x1e(%rax)
    17eb:	89 48 22             	mov    %ecx,0x22(%rax)
    17ee:	48 8b 54 24 70       	mov    0x70(%rsp),%rdx
    17f3:	e9 4b 0d 00 00       	jmp    0x2543
    17f8:	31 c9                	xor    %ecx,%ecx
    17fa:	0f b7 70 10          	movzwl 0x10(%rax),%esi
    17fe:	0f b7 bc 24 90 00 00 	movzwl 0x90(%rsp),%edi
    1805:	00 
    1806:	0f b6 94 24 92 00 00 	movzbl 0x92(%rsp),%edx
    180d:	00 
    180e:	88 50 12             	mov    %dl,0x12(%rax)
    1811:	84 c9                	test   %cl,%cl
    1813:	74 51                	je     0x1866
    1815:	66 39 fe             	cmp    %di,%si
    1818:	75 4c                	jne    0x1866
    181a:	84 d2                	test   %dl,%dl
    181c:	74 48                	je     0x1866
    181e:	8b 44 24 68          	mov    0x68(%rsp),%eax
    1822:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
    1826:	48 bf 00 50 7d 40 86 	movabs $0xffffd286407d5000,%rdi
    182d:	d2 ff ff 
    1830:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    1835:	b8 01 00 00 00       	mov    $0x1,%eax
    183a:	8b 06                	mov    (%rsi),%eax
    183c:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1841:	73 16                	jae    0x1859
    1843:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    184a:	00 
    184b:	48 8b 00             	mov    (%rax),%rax
    184e:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1855:	2b 9e 
    1857:	eb 02                	jmp    0x185b
    1859:	31 c0                	xor    %eax,%eax
    185b:	48 85 c0             	test   %rax,%rax
    185e:	0f 84 24 0a 00 00    	je     0x2288
    1864:	ff 00                	incl   (%rax)
    1866:	48 8b 84 24 b0 00 00 	mov    0xb0(%rsp),%rax
    186d:	00 
    186e:	48 ff 40 08          	incq   0x8(%rax)
    1872:	48 8b 6c 24 70       	mov    0x70(%rsp),%rbp
    1877:	e9 62 fa ff ff       	jmp    0x12de
    187c:	48 83 c0 40          	add    $0x40,%rax
    1880:	eb 0a                	jmp    0x188c
    1882:	48 83 c0 48          	add    $0x48,%rax
    1886:	eb 04                	jmp    0x188c
    1888:	48 83 c0 30          	add    $0x30,%rax
    188c:	48 ff 00             	incq   (%rax)
    188f:	44 89 64 24 24       	mov    %r12d,0x24(%rsp)
    1894:	48 bf 00 c0 0d 52 86 	movabs $0xffffd286520dc000,%rdi
    189b:	d2 ff ff 
    189e:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    18a3:	b8 01 00 00 00       	mov    $0x1,%eax
    18a8:	8b 06                	mov    (%rsi),%eax
    18aa:	3d fe ff ff 00       	cmp    $0xfffffe,%eax
    18af:	73 0a                	jae    0x18bb
    18b1:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    18b8:	00 
    18b9:	eb 02                	jmp    0x18bd
    18bb:	31 c0                	xor    %eax,%eax
    18bd:	48 85 c0             	test   %rax,%rax
    18c0:	74 75                	je     0x1937
    18c2:	8b 00                	mov    (%rax),%eax
    18c4:	89 44 24 24          	mov    %eax,0x24(%rsp)
    18c8:	85 c0                	test   %eax,%eax
    18ca:	74 6b                	je     0x1937
    18cc:	89 44 24 68          	mov    %eax,0x68(%rsp)
    18d0:	48 bf 00 00 8c 40 86 	movabs $0xffffd286408c0000,%rdi
    18d7:	d2 ff ff 
    18da:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    18df:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    18e5:	8b 06                	mov    (%rsi),%eax
    18e7:	3d 00 10 00 00       	cmp    $0x1000,%eax
    18ec:	73 12                	jae    0x1900
    18ee:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    18f5:	48 01 f8             	add    %rdi,%rax
    18f8:	48 05 30 01 00 00    	add    $0x130,%rax
    18fe:	eb 02                	jmp    0x1902
    1900:	31 c0                	xor    %eax,%eax
    1902:	48 85 c0             	test   %rax,%rax
    1905:	74 59                	je     0x1960
    1907:	49 89 c5             	mov    %rax,%r13
    190a:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    190f:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    1914:	e8 bb 20 eb da       	call   0xffffffffdaeb39d4
    1919:	48 85 c0             	test   %rax,%rax
    191c:	0f 84 b2 00 00 00    	je     0x19d4
    1922:	8b 4c 24 68          	mov    0x68(%rsp),%ecx
    1926:	39 08                	cmp    %ecx,(%rax)
    1928:	0f 85 1d 01 00 00    	jne    0x1a4b
    192e:	48 ff 45 50          	incq   0x50(%rbp)
    1932:	e9 77 0c 00 00       	jmp    0x25ae
    1937:	48 ff 45 10          	incq   0x10(%rbp)
    193b:	4c 89 65 18          	mov    %r12,0x18(%rbp)
    193f:	48 ff 45 00          	incq   0x0(%rbp)
    1943:	e9 ad f7 ff ff       	jmp    0x10f5
    1948:	41 80 7c 24 0d 07    	cmpb   $0x7,0xd(%r12)
    194e:	0f 86 42 02 00 00    	jbe    0x1b96
    1954:	49 83 c4 0e          	add    $0xe,%r12
    1958:	4c 89 e1             	mov    %r12,%rcx
    195b:	e9 43 f4 ff ff       	jmp    0xda3
    1960:	48 ff 45 28          	incq   0x28(%rbp)
    1964:	e9 1f 09 00 00       	jmp    0x2288
    1969:	0f b6 71 01          	movzbl 0x1(%rcx),%esi
    196d:	c1 e6 10             	shl    $0x10,%esi
    1970:	0f b6 51 02          	movzbl 0x2(%rcx),%edx
    1974:	c1 e2 08             	shl    $0x8,%edx
    1977:	09 f2                	or     %esi,%edx
    1979:	0f b6 49 03          	movzbl 0x3(%rcx),%ecx
    197d:	eb 1d                	jmp    0x199c
    197f:	0f b6 51 01          	movzbl 0x1(%rcx),%edx
    1983:	c1 e2 18             	shl    $0x18,%edx
    1986:	0f b6 71 02          	movzbl 0x2(%rcx),%esi
    198a:	c1 e6 10             	shl    $0x10,%esi
    198d:	09 d6                	or     %edx,%esi
    198f:	0f b6 51 03          	movzbl 0x3(%rcx),%edx
    1993:	c1 e2 08             	shl    $0x8,%edx
    1996:	09 f2                	or     %esi,%edx
    1998:	0f b6 49 04          	movzbl 0x4(%rcx),%ecx
    199c:	44 0f b6 e1          	movzbl %cl,%r12d
    19a0:	49 09 d4             	or     %rdx,%r12
    19a3:	45 85 e4             	test   %r12d,%r12d
    19a6:	0f 8e ea 01 00 00    	jle    0x1b96
    19ac:	48 83 f8 03          	cmp    $0x3,%rax
    19b0:	0f 84 f0 00 00 00    	je     0x1aa6
    19b6:	83 f8 02             	cmp    $0x2,%eax
    19b9:	0f 84 de 00 00 00    	je     0x1a9d
    19bf:	83 f8 01             	cmp    $0x1,%eax
    19c2:	0f 85 e7 00 00 00    	jne    0x1aaf
    19c8:	4c 89 e8             	mov    %r13,%rax
    19cb:	48 83 c0 38          	add    $0x38,%rax
    19cf:	e9 e2 00 00 00       	jmp    0x1ab6
    19d4:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    19db:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    19e2:	8b ff ff 
    19e5:	48 89 e6             	mov    %rsp,%rsi
    19e8:	b8 01 00 00 00       	mov    $0x1,%eax
    19ed:	8b 06                	mov    (%rsi),%eax
    19ef:	3d 00 04 00 00       	cmp    $0x400,%eax
    19f4:	73 16                	jae    0x1a0c
    19f6:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    19fd:	00 
    19fe:	48 8b 00             	mov    (%rax),%rax
    1a01:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1a08:	2b 9e 
    1a0a:	eb 02                	jmp    0x1a0e
    1a0c:	31 c0                	xor    %eax,%eax
    1a0e:	48 85 c0             	test   %rax,%rax
    1a11:	0f 84 93 0b 00 00    	je     0x25aa
    1a17:	49 89 c4             	mov    %rax,%r12
    1a1a:	b8 05 00 00 00       	mov    $0x5,%eax
    1a1f:	e8 e0 23 eb da       	call   0xffffffffdaeb3e04
    1a24:	48 89 c1             	mov    %rax,%rcx
    1a27:	49 2b 4c 24 08       	sub    0x8(%r12),%rcx
    1a2c:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    1a33:	0f 82 2d 0b 00 00    	jb     0x2566
    1a39:	49 c7 04 24 01 00 00 	movq   $0x1,(%r12)
    1a40:	00 
    1a41:	49 89 44 24 08       	mov    %rax,0x8(%r12)
    1a46:	e9 2e 0b 00 00       	jmp    0x2579
    1a4b:	89 08                	mov    %ecx,(%rax)
    1a4d:	48 ff 45 58          	incq   0x58(%rbp)
    1a51:	8b 44 24 70          	mov    0x70(%rsp),%eax
    1a55:	89 04 24             	mov    %eax,(%rsp)
    1a58:	48 bf 00 a0 d1 82 0f 	movabs $0xffff8b0f82d1a000,%rdi
    1a5f:	8b ff ff 
    1a62:	48 89 e6             	mov    %rsp,%rsi
    1a65:	b8 01 00 00 00       	mov    $0x1,%eax
    1a6a:	8b 06                	mov    (%rsi),%eax
    1a6c:	3d 00 02 00 00       	cmp    $0x200,%eax
    1a71:	73 16                	jae    0x1a89
    1a73:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1a7a:	00 
    1a7b:	48 8b 00             	mov    (%rax),%rax
    1a7e:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1a85:	2b 9e 
    1a87:	eb 02                	jmp    0x1a8b
    1a89:	31 c0                	xor    %eax,%eax
    1a8b:	48 85 c0             	test   %rax,%rax
    1a8e:	0f 84 1a 0b 00 00    	je     0x25ae
    1a94:	48 ff 40 08          	incq   0x8(%rax)
    1a98:	e9 11 0b 00 00       	jmp    0x25ae
    1a9d:	4c 89 e8             	mov    %r13,%rax
    1aa0:	48 83 c0 40          	add    $0x40,%rax
    1aa4:	eb 10                	jmp    0x1ab6
    1aa6:	4c 89 e8             	mov    %r13,%rax
    1aa9:	48 83 c0 48          	add    $0x48,%rax
    1aad:	eb 07                	jmp    0x1ab6
    1aaf:	4c 89 e8             	mov    %r13,%rax
    1ab2:	48 83 c0 30          	add    $0x30,%rax
    1ab6:	48 ff 00             	incq   (%rax)
    1ab9:	44 89 64 24 24       	mov    %r12d,0x24(%rsp)
    1abe:	48 bf 00 c0 0d 52 86 	movabs $0xffffd286520dc000,%rdi
    1ac5:	d2 ff ff 
    1ac8:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    1acd:	b8 01 00 00 00       	mov    $0x1,%eax
    1ad2:	8b 06                	mov    (%rsi),%eax
    1ad4:	3d fe ff ff 00       	cmp    $0xfffffe,%eax
    1ad9:	73 0a                	jae    0x1ae5
    1adb:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1ae2:	00 
    1ae3:	eb 02                	jmp    0x1ae7
    1ae5:	31 c0                	xor    %eax,%eax
    1ae7:	48 85 c0             	test   %rax,%rax
    1aea:	0f 84 9e 00 00 00    	je     0x1b8e
    1af0:	8b 00                	mov    (%rax),%eax
    1af2:	89 44 24 24          	mov    %eax,0x24(%rsp)
    1af6:	85 c0                	test   %eax,%eax
    1af8:	0f 84 90 00 00 00    	je     0x1b8e
    1afe:	89 44 24 68          	mov    %eax,0x68(%rsp)
    1b02:	48 bf 00 00 8c 40 86 	movabs $0xffffd286408c0000,%rdi
    1b09:	d2 ff ff 
    1b0c:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    1b11:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    1b17:	8b 06                	mov    (%rsi),%eax
    1b19:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1b1e:	73 12                	jae    0x1b32
    1b20:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    1b27:	48 01 f8             	add    %rdi,%rax
    1b2a:	48 05 30 01 00 00    	add    $0x130,%rax
    1b30:	eb 02                	jmp    0x1b34
    1b32:	31 c0                	xor    %eax,%eax
    1b34:	48 89 84 24 a8 00 00 	mov    %rax,0xa8(%rsp)
    1b3b:	00 
    1b3c:	48 85 c0             	test   %rax,%rax
    1b3f:	0f 84 18 0a 00 00    	je     0x255d
    1b45:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    1b4a:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    1b4f:	8b 06                	mov    (%rsi),%eax
    1b51:	3d 00 04 00 00       	cmp    $0x400,%eax
    1b56:	73 16                	jae    0x1b6e
    1b58:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1b5f:	00 
    1b60:	48 8b 00             	mov    (%rax),%rax
    1b63:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1b6a:	2b 9e 
    1b6c:	eb 02                	jmp    0x1b70
    1b6e:	31 c0                	xor    %eax,%eax
    1b70:	48 85 c0             	test   %rax,%rax
    1b73:	0f 84 4a 0a 00 00    	je     0x25c3
    1b79:	8b 4c 24 68          	mov    0x68(%rsp),%ecx
    1b7d:	39 08                	cmp    %ecx,(%rax)
    1b7f:	0f 85 ae 0a 00 00    	jne    0x2633
    1b85:	49 ff 45 50          	incq   0x50(%r13)
    1b89:	e9 38 0b 00 00       	jmp    0x26c6
    1b8e:	49 ff 45 10          	incq   0x10(%r13)
    1b92:	4d 89 65 18          	mov    %r12,0x18(%r13)
    1b96:	49 ff 45 00          	incq   0x0(%r13)
    1b9a:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    1b9f:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    1ba4:	89 4c 24 38          	mov    %ecx,0x38(%rsp)
    1ba8:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    1bad:	75 6a                	jne    0x1c19
    1baf:	41 f6 45 00 02       	testb  $0x2,0x0(%r13)
    1bb4:	75 67                	jne    0x1c1d
    1bb6:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    1bbb:	b8 01 00 00 00       	mov    $0x1,%eax
    1bc0:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    1bc5:	8b 06                	mov    (%rsi),%eax
    1bc7:	3d 00 04 00 00       	cmp    $0x400,%eax
    1bcc:	73 16                	jae    0x1be4
    1bce:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1bd5:	00 
    1bd6:	48 8b 00             	mov    (%rax),%rax
    1bd9:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1be0:	2b 9e 
    1be2:	eb 02                	jmp    0x1be6
    1be4:	31 c0                	xor    %eax,%eax
    1be6:	48 85 c0             	test   %rax,%rax
    1be9:	74 2a                	je     0x1c15
    1beb:	49 89 c5             	mov    %rax,%r13
    1bee:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    1bf3:	75 35                	jne    0x1c2a
    1bf5:	b8 05 00 00 00       	mov    $0x5,%eax
    1bfa:	e8 05 22 eb da       	call   0xffffffffdaeb3e04
    1bff:	48 89 c1             	mov    %rax,%rcx
    1c02:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    1c06:	48 ba 00 ac 23 fc 06 	movabs $0x6fc23ac00,%rdx
    1c0d:	00 00 00 
    1c10:	48 39 d1             	cmp    %rdx,%rcx
    1c13:	76 11                	jbe    0x1c26
    1c15:	31 c0                	xor    %eax,%eax
    1c17:	eb 4b                	jmp    0x1c64
    1c19:	31 ed                	xor    %ebp,%ebp
    1c1b:	eb 4f                	jmp    0x1c6c
    1c1d:	31 ed                	xor    %ebp,%ebp
    1c1f:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    1c24:	eb 46                	jmp    0x1c6c
    1c26:	49 89 45 08          	mov    %rax,0x8(%r13)
    1c2a:	41 8b 45 00          	mov    0x0(%r13),%eax
    1c2e:	89 04 24             	mov    %eax,(%rsp)
    1c31:	89 44 24 68          	mov    %eax,0x68(%rsp)
    1c35:	48 bf 00 00 8c 40 86 	movabs $0xffffd286408c0000,%rdi
    1c3c:	d2 ff ff 
    1c3f:	48 89 e6             	mov    %rsp,%rsi
    1c42:	b8 01 00 00 00       	mov    $0x1,%eax
    1c47:	8b 06                	mov    (%rsi),%eax
    1c49:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1c4e:	73 12                	jae    0x1c62
    1c50:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    1c57:	48 01 f8             	add    %rdi,%rax
    1c5a:	48 05 30 01 00 00    	add    $0x130,%rax
    1c60:	eb 02                	jmp    0x1c64
    1c62:	31 c0                	xor    %eax,%eax
    1c64:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    1c69:	48 89 c5             	mov    %rax,%rbp
    1c6c:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    1c71:	0f 85 28 01 00 00    	jne    0x1d9f
    1c77:	41 f6 45 01 02       	testb  $0x2,0x1(%r13)
    1c7c:	0f 84 1d 01 00 00    	je     0x1d9f
    1c82:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    1c89:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1c90:	8b ff ff 
    1c93:	48 89 e6             	mov    %rsp,%rsi
    1c96:	b8 01 00 00 00       	mov    $0x1,%eax
    1c9b:	8b 06                	mov    (%rsi),%eax
    1c9d:	3d 00 04 00 00       	cmp    $0x400,%eax
    1ca2:	73 16                	jae    0x1cba
    1ca4:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1cab:	00 
    1cac:	48 8b 00             	mov    (%rax),%rax
    1caf:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1cb6:	2b 9e 
    1cb8:	eb 02                	jmp    0x1cbc
    1cba:	31 c0                	xor    %eax,%eax
    1cbc:	48 85 c0             	test   %rax,%rax
    1cbf:	0f 84 da 00 00 00    	je     0x1d9f
    1cc5:	49 89 c5             	mov    %rax,%r13
    1cc8:	b8 05 00 00 00       	mov    $0x5,%eax
    1ccd:	e8 32 21 eb da       	call   0xffffffffdaeb3e04
    1cd2:	48 89 c1             	mov    %rax,%rcx
    1cd5:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    1cd9:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    1ce0:	72 0e                	jb     0x1cf0
    1ce2:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    1ce9:	00 
    1cea:	49 89 45 08          	mov    %rax,0x8(%r13)
    1cee:	eb 17                	jmp    0x1d07
    1cf0:	49 8b 45 00          	mov    0x0(%r13),%rax
    1cf4:	48 ff c0             	inc    %rax
    1cf7:	49 89 45 00          	mov    %rax,0x0(%r13)
    1cfb:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    1d01:	0f 83 98 00 00 00    	jae    0x1d9f
    1d07:	48 bf 00 28 01 56 10 	movabs $0xffff8b1056012800,%rdi
    1d0e:	8b ff ff 
    1d11:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
    1d18:	00 
    1d19:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    1d1f:	e8 b0 1c eb da       	call   0xffffffffdaeb39d4
    1d24:	48 85 c0             	test   %rax,%rax
    1d27:	74 76                	je     0x1d9f
    1d29:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    1d2e:	48 89 c7             	mov    %rax,%rdi
    1d31:	e8 6e fc eb da       	call   0xffffffffdaec19a4
    1d36:	48 85 c0             	test   %rax,%rax
    1d39:	74 14                	je     0x1d4f
    1d3b:	80 b8 23 00 00 00 00 	cmpb   $0x0,0x23(%rax)
    1d42:	75 07                	jne    0x1d4b
    1d44:	c6 80 23 00 00 00 01 	movb   $0x1,0x23(%rax)
    1d4b:	48 83 c0 58          	add    $0x58,%rax
    1d4f:	48 85 c0             	test   %rax,%rax
    1d52:	74 4b                	je     0x1d9f
    1d54:	c7 04 24 0f 02 00 00 	movl   $0x20f,(%rsp)
    1d5b:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1d62:	8b ff ff 
    1d65:	48 89 e6             	mov    %rsp,%rsi
    1d68:	b8 01 00 00 00       	mov    $0x1,%eax
    1d6d:	8b 06                	mov    (%rsi),%eax
    1d6f:	3d 00 04 00 00       	cmp    $0x400,%eax
    1d74:	73 16                	jae    0x1d8c
    1d76:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1d7d:	00 
    1d7e:	48 8b 00             	mov    (%rax),%rax
    1d81:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1d88:	2b 9e 
    1d8a:	eb 02                	jmp    0x1d8e
    1d8c:	31 c0                	xor    %eax,%eax
    1d8e:	48 85 c0             	test   %rax,%rax
    1d91:	0f 84 72 01 00 00    	je     0x1f09
    1d97:	48 ff 00             	incq   (%rax)
    1d9a:	e9 6a 01 00 00       	jmp    0x1f09
    1d9f:	48 85 ed             	test   %rbp,%rbp
    1da2:	0f 84 61 01 00 00    	je     0x1f09
    1da8:	48 89 ac 24 a8 00 00 	mov    %rbp,0xa8(%rsp)
    1daf:	00 
    1db0:	48 bf 00 24 8e 83 0f 	movabs $0xffff8b0f838e2400,%rdi
    1db7:	8b ff ff 
    1dba:	48 8d b4 24 a0 00 00 	lea    0xa0(%rsp),%rsi
    1dc1:	00 
    1dc2:	bd 01 00 00 00       	mov    $0x1,%ebp
    1dc7:	8b 06                	mov    (%rsi),%eax
    1dc9:	83 f8 10             	cmp    $0x10,%eax
    1dcc:	73 0a                	jae    0x1dd8
    1dce:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1dd5:	00 
    1dd6:	eb 02                	jmp    0x1dda
    1dd8:	31 c0                	xor    %eax,%eax
    1dda:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    1de0:	48 85 c0             	test   %rax,%rax
    1de3:	0f 84 a5 04 00 00    	je     0x228e
    1de9:	49 89 c4             	mov    %rax,%r12
    1dec:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1df3:	8b ff ff 
    1df6:	48 8d b4 24 a4 00 00 	lea    0xa4(%rsp),%rsi
    1dfd:	00 
    1dfe:	8b 06                	mov    (%rsi),%eax
    1e00:	3d 00 04 00 00       	cmp    $0x400,%eax
    1e05:	73 16                	jae    0x1e1d
    1e07:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1e0e:	00 
    1e0f:	48 8b 00             	mov    (%rax),%rax
    1e12:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1e19:	2b 9e 
    1e1b:	eb 02                	jmp    0x1e1f
    1e1d:	31 c0                	xor    %eax,%eax
    1e1f:	48 85 c0             	test   %rax,%rax
    1e22:	0f 84 66 04 00 00    	je     0x228e
    1e28:	0f b7 4c 24 34       	movzwl 0x34(%rsp),%ecx
    1e2d:	66 c1 c1 08          	rol    $0x8,%cx
    1e31:	48 ff 00             	incq   (%rax)
    1e34:	89 4c 24 28          	mov    %ecx,0x28(%rsp)
    1e38:	0f b7 e9             	movzwl %cx,%ebp
    1e3b:	48 01 68 08          	add    %rbp,0x8(%rax)
    1e3f:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    1e44:	48 bf 00 d0 7b 40 86 	movabs $0xffffd286407bd000,%rdi
    1e4b:	d2 ff ff 
    1e4e:	b8 01 00 00 00       	mov    $0x1,%eax
    1e53:	8b 06                	mov    (%rsi),%eax
    1e55:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1e5a:	73 16                	jae    0x1e72
    1e5c:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1e63:	00 
    1e64:	48 8b 00             	mov    (%rax),%rax
    1e67:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1e6e:	2b 9e 
    1e70:	eb 02                	jmp    0x1e74
    1e72:	31 c0                	xor    %eax,%eax
    1e74:	48 85 c0             	test   %rax,%rax
    1e77:	0f 84 11 04 00 00    	je     0x228e
    1e7d:	48 ff 00             	incq   (%rax)
    1e80:	48 01 68 08          	add    %rbp,0x8(%rax)
    1e84:	8b 44 24 38          	mov    0x38(%rsp),%eax
    1e88:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    1e8d:	48 8b 84 24 a8 00 00 	mov    0xa8(%rsp),%rax
    1e94:	00 
    1e95:	f6 40 10 01          	testb  $0x1,0x10(%rax)
    1e99:	0f 85 8d 04 00 00    	jne    0x232c
    1e9f:	0f b7 6c 24 42       	movzwl 0x42(%rsp),%ebp
    1ea4:	b8 2c 00 00 00       	mov    $0x2c,%eax
    1ea9:	4c 89 f7             	mov    %r14,%rdi
    1eac:	be ec ff ff ff       	mov    $0xffffffec,%esi
    1eb1:	e8 9e cd 75 db       	call   0xffffffffdb75ec54
    1eb6:	85 c0                	test   %eax,%eax
    1eb8:	0f 84 d4 04 00 00    	je     0x2392
    1ebe:	c7 04 24 07 02 00 00 	movl   $0x207,(%rsp)
    1ec5:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1ecc:	8b ff ff 
    1ecf:	48 89 e6             	mov    %rsp,%rsi
    1ed2:	b8 01 00 00 00       	mov    $0x1,%eax
    1ed7:	8b 06                	mov    (%rsi),%eax
    1ed9:	3d 00 04 00 00       	cmp    $0x400,%eax
    1ede:	73 16                	jae    0x1ef6
    1ee0:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1ee7:	00 
    1ee8:	48 8b 00             	mov    (%rax),%rax
    1eeb:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1ef2:	2b 9e 
    1ef4:	eb 02                	jmp    0x1ef8
    1ef6:	31 c0                	xor    %eax,%eax
    1ef8:	48 85 c0             	test   %rax,%rax
    1efb:	0f 84 8d 03 00 00    	je     0x228e
    1f01:	48 ff 00             	incq   (%rax)
    1f04:	e9 85 03 00 00       	jmp    0x228e
    1f09:	80 7c 24 64 06       	cmpb   $0x6,0x64(%rsp)
    1f0e:	75 51                	jne    0x1f61
    1f10:	c7 04 24 01 02 00 00 	movl   $0x201,(%rsp)
    1f17:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1f1e:	8b ff ff 
    1f21:	48 89 e6             	mov    %rsp,%rsi
    1f24:	b8 01 00 00 00       	mov    $0x1,%eax
    1f29:	8b 06                	mov    (%rsi),%eax
    1f2b:	3d 00 04 00 00       	cmp    $0x400,%eax
    1f30:	73 16                	jae    0x1f48
    1f32:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1f39:	00 
    1f3a:	48 8b 00             	mov    (%rax),%rax
    1f3d:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1f44:	2b 9e 
    1f46:	eb 02                	jmp    0x1f4a
    1f48:	31 c0                	xor    %eax,%eax
    1f4a:	48 85 c0             	test   %rax,%rax
    1f4d:	0f 84 35 03 00 00    	je     0x2288
    1f53:	31 c9                	xor    %ecx,%ecx
    1f55:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    1f5a:	0f 94 c1             	sete   %cl
    1f5d:	48 ff 04 c8          	incq   (%rax,%rcx,8)
    1f61:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    1f68:	00 00 
    1f6a:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    1f71:	00 
    1f72:	c7 44 24 1c 02 02 00 	movl   $0x202,0x1c(%rsp)
    1f79:	00 
    1f7a:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    1f81:	8b ff ff 
    1f84:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    1f89:	b8 01 00 00 00       	mov    $0x1,%eax
    1f8e:	8b 06                	mov    (%rsi),%eax
    1f90:	3d 00 04 00 00       	cmp    $0x400,%eax
    1f95:	73 16                	jae    0x1fad
    1f97:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1f9e:	00 
    1f9f:	48 8b 00             	mov    (%rax),%rax
    1fa2:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1fa9:	2b 9e 
    1fab:	eb 02                	jmp    0x1faf
    1fad:	31 c0                	xor    %eax,%eax
    1faf:	bd 01 00 00 00       	mov    $0x1,%ebp
    1fb4:	48 85 c0             	test   %rax,%rax
    1fb7:	74 34                	je     0x1fed
    1fb9:	49 89 c5             	mov    %rax,%r13
    1fbc:	b8 05 00 00 00       	mov    $0x5,%eax
    1fc1:	e8 3e 1e eb da       	call   0xffffffffdaeb3e04
    1fc6:	48 89 c1             	mov    %rax,%rcx
    1fc9:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
    1fce:	49 2b 45 08          	sub    0x8(%r13),%rax
    1fd2:	48 3d 01 ca 9a 3b    	cmp    $0x3b9aca01,%rax
    1fd8:	72 1c                	jb     0x1ff6
    1fda:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    1fe1:	00 
    1fe2:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
    1fe7:	49 89 45 08          	mov    %rax,0x8(%r13)
    1feb:	eb 1c                	jmp    0x2009
    1fed:	31 c0                	xor    %eax,%eax
    1fef:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
    1ff4:	eb 15                	jmp    0x200b
    1ff6:	49 8b 45 00          	mov    0x0(%r13),%rax
    1ffa:	48 ff c0             	inc    %rax
    1ffd:	49 89 45 00          	mov    %rax,0x0(%r13)
    2001:	48 3d 48 e8 01 00    	cmp    $0x1e848,%rax
    2007:	77 02                	ja     0x200b
    2009:	31 ed                	xor    %ebp,%ebp
    200b:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    2010:	f6 00 08             	testb  $0x8,(%rax)
    2013:	75 06                	jne    0x201b
    2015:	8b 7c 24 40          	mov    0x40(%rsp),%edi
    2019:	eb 1e                	jmp    0x2039
    201b:	0f b7 44 24 62       	movzwl 0x62(%rsp),%eax
    2020:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    2025:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
    202c:	00 00 
    202e:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
    2035:	00 00 
    2037:	31 ff                	xor    %edi,%edi
    2039:	8b 74 24 60          	mov    0x60(%rsp),%esi
    203d:	e8 75 07 00 00       	call   0x27b7
    2042:	89 c1                	mov    %eax,%ecx
    2044:	ba 01 00 ff ff       	mov    $0xffff0001,%edx
    2049:	48 0f af d1          	imul   %rcx,%rdx
    204d:	48 c1 ea 30          	shr    $0x30,%rdx
    2051:	89 d1                	mov    %edx,%ecx
    2053:	c1 e1 10             	shl    $0x10,%ecx
    2056:	09 d1                	or     %edx,%ecx
    2058:	29 c8                	sub    %ecx,%eax
    205a:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
    205f:	8b 49 04             	mov    0x4(%rcx),%ecx
    2062:	89 ca                	mov    %ecx,%edx
    2064:	c1 e2 10             	shl    $0x10,%edx
    2067:	01 ca                	add    %ecx,%edx
    2069:	01 c2                	add    %eax,%edx
    206b:	89 54 24 24          	mov    %edx,0x24(%rsp)
    206f:	48 bf 00 90 0d 42 86 	movabs $0xffffd286420d9000,%rdi
    2076:	d2 ff ff 
    2079:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    207e:	b8 01 00 00 00       	mov    $0x1,%eax
    2083:	8b 06                	mov    (%rsi),%eax
    2085:	3d 00 02 00 02       	cmp    $0x2000200,%eax
    208a:	73 0a                	jae    0x2096
    208c:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    2093:	00 
    2094:	eb 02                	jmp    0x2098
    2096:	31 c0                	xor    %eax,%eax
    2098:	48 85 c0             	test   %rax,%rax
    209b:	0f 84 e7 01 00 00    	je     0x2288
    20a1:	8b 00                	mov    (%rax),%eax
    20a3:	89 44 24 24          	mov    %eax,0x24(%rsp)
    20a7:	85 c0                	test   %eax,%eax
    20a9:	0f 84 51 01 00 00    	je     0x2200
    20af:	89 44 24 68          	mov    %eax,0x68(%rsp)
    20b3:	48 bf 00 00 8c 40 86 	movabs $0xffffd286408c0000,%rdi
    20ba:	d2 ff ff 
    20bd:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    20c2:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    20c8:	8b 06                	mov    (%rsi),%eax
    20ca:	3d 00 10 00 00       	cmp    $0x1000,%eax
    20cf:	73 12                	jae    0x20e3
    20d1:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    20d8:	48 01 f8             	add    %rdi,%rax
    20db:	48 05 30 01 00 00    	add    $0x130,%rax
    20e1:	eb 02                	jmp    0x20e5
    20e3:	31 c0                	xor    %eax,%eax
    20e5:	48 89 84 24 a8 00 00 	mov    %rax,0xa8(%rsp)
    20ec:	00 
    20ed:	48 85 c0             	test   %rax,%rax
    20f0:	0f 84 52 01 00 00    	je     0x2248
    20f6:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    20fb:	0f b6 00             	movzbl (%rax),%eax
    20fe:	24 02                	and    $0x2,%al
    2100:	d0 e8                	shr    $1,%al
    2102:	40 08 c5             	or     %al,%bpl
    2105:	75 38                	jne    0x213f
    2107:	f6 44 24 6c 04       	testb  $0x4,0x6c(%rsp)
    210c:	75 31                	jne    0x213f
    210e:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    2113:	75 0a                	jne    0x211f
    2115:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
    211a:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    211f:	8b 44 24 24          	mov    0x24(%rsp),%eax
    2123:	89 04 24             	mov    %eax,(%rsp)
    2126:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    212b:	48 89 e2             	mov    %rsp,%rdx
    212e:	b8 02 00 00 00       	mov    $0x2,%eax
    2133:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    2138:	31 c9                	xor    %ecx,%ecx
    213a:	e8 b5 1b ec da       	call   0xffffffffdaec3cf4
    213f:	c7 04 24 00 00 00 00 	movl   $0x0,(%rsp)
    2146:	48 bf 00 8a 20 83 0f 	movabs $0xffff8b0f83208a00,%rdi
    214d:	8b ff ff 
    2150:	48 89 e6             	mov    %rsp,%rsi
    2153:	b8 01 00 00 00       	mov    $0x1,%eax
    2158:	8b 06                	mov    (%rsi),%eax
    215a:	83 f8 01             	cmp    $0x1,%eax
    215d:	73 12                	jae    0x2171
    215f:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    2166:	48 01 f8             	add    %rdi,%rax
    2169:	48 05 30 01 00 00    	add    $0x130,%rax
    216f:	eb 02                	jmp    0x2173
    2171:	31 c0                	xor    %eax,%eax
    2173:	48 85 c0             	test   %rax,%rax
    2176:	0f 84 0c 01 00 00    	je     0x2288
    217c:	8b 38                	mov    (%rax),%edi
    217e:	0f b7 50 10          	movzwl 0x10(%rax),%edx
    2182:	0f b7 b4 24 90 00 00 	movzwl 0x90(%rsp),%esi
    2189:	00 
    218a:	0f b6 8c 24 92 00 00 	movzbl 0x92(%rsp),%ecx
    2191:	00 
    2192:	3b bc 24 80 00 00 00 	cmp    0x80(%rsp),%edi
    2199:	88 48 12             	mov    %cl,0x12(%rax)
    219c:	75 51                	jne    0x21ef
    219e:	66 39 f2             	cmp    %si,%dx
    21a1:	75 4c                	jne    0x21ef
    21a3:	84 c9                	test   %cl,%cl
    21a5:	74 48                	je     0x21ef
    21a7:	8b 44 24 68          	mov    0x68(%rsp),%eax
    21ab:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
    21af:	48 bf 00 50 7d 40 86 	movabs $0xffffd286407d5000,%rdi
    21b6:	d2 ff ff 
    21b9:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    21be:	b8 01 00 00 00       	mov    $0x1,%eax
    21c3:	8b 06                	mov    (%rsi),%eax
    21c5:	3d 00 10 00 00       	cmp    $0x1000,%eax
    21ca:	73 16                	jae    0x21e2
    21cc:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    21d3:	00 
    21d4:	48 8b 00             	mov    (%rax),%rax
    21d7:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    21de:	2b 9e 
    21e0:	eb 02                	jmp    0x21e4
    21e2:	31 c0                	xor    %eax,%eax
    21e4:	48 85 c0             	test   %rax,%rax
    21e7:	0f 84 9b 00 00 00    	je     0x2288
    21ed:	ff 00                	incl   (%rax)
    21ef:	48 8b 84 24 b0 00 00 	mov    0xb0(%rsp),%rax
    21f6:	00 
    21f7:	48 ff 40 08          	incq   0x8(%rax)
    21fb:	e9 b0 fb ff ff       	jmp    0x1db0
    2200:	c7 44 24 1c 09 02 00 	movl   $0x209,0x1c(%rsp)
    2207:	00 
    2208:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    220f:	8b ff ff 
    2212:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    2217:	b8 01 00 00 00       	mov    $0x1,%eax
    221c:	8b 06                	mov    (%rsi),%eax
    221e:	3d 00 04 00 00       	cmp    $0x400,%eax
    2223:	73 16                	jae    0x223b
    2225:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    222c:	00 
    222d:	48 8b 00             	mov    (%rax),%rax
    2230:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    2237:	2b 9e 
    2239:	eb 02                	jmp    0x223d
    223b:	31 c0                	xor    %eax,%eax
    223d:	48 85 c0             	test   %rax,%rax
    2240:	74 46                	je     0x2288
    2242:	48 ff 40 08          	incq   0x8(%rax)
    2246:	eb 40                	jmp    0x2288
    2248:	c7 44 24 1c 09 02 00 	movl   $0x209,0x1c(%rsp)
    224f:	00 
    2250:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    2257:	8b ff ff 
    225a:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    225f:	8b 06                	mov    (%rsi),%eax
    2261:	3d 00 04 00 00       	cmp    $0x400,%eax
    2266:	73 16                	jae    0x227e
    2268:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    226f:	00 
    2270:	48 8b 00             	mov    (%rax),%rax
    2273:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    227a:	2b 9e 
    227c:	eb 02                	jmp    0x2280
    227e:	31 c0                	xor    %eax,%eax
    2280:	48 85 c0             	test   %rax,%rax
    2283:	74 03                	je     0x2288
    2285:	48 ff 00             	incq   (%rax)
    2288:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    228e:	41 83 fd 01          	cmp    $0x1,%r13d
    2292:	74 2a                	je     0x22be
    2294:	41 83 fd 03          	cmp    $0x3,%r13d
    2298:	75 12                	jne    0x22ac
    229a:	c7 84 24 94 00 00 00 	movl   $0x211,0x94(%rsp)
    22a1:	11 02 00 00 
    22a5:	bd 03 00 00 00       	mov    $0x3,%ebp
    22aa:	eb 22                	jmp    0x22ce
    22ac:	c7 84 24 94 00 00 00 	movl   $0x213,0x94(%rsp)
    22b3:	13 02 00 00 
    22b7:	bd 02 00 00 00       	mov    $0x2,%ebp
    22bc:	eb 10                	jmp    0x22ce
    22be:	c7 84 24 94 00 00 00 	movl   $0x212,0x94(%rsp)
    22c5:	12 02 00 00 
    22c9:	bd 01 00 00 00       	mov    $0x1,%ebp
    22ce:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    22d5:	8b ff ff 
    22d8:	48 8d b4 24 94 00 00 	lea    0x94(%rsp),%rsi
    22df:	00 
    22e0:	b8 01 00 00 00       	mov    $0x1,%eax
    22e5:	8b 06                	mov    (%rsi),%eax
    22e7:	3d 00 04 00 00       	cmp    $0x400,%eax
    22ec:	73 16                	jae    0x2304
    22ee:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    22f5:	00 
    22f6:	48 8b 00             	mov    (%rax),%rax
    22f9:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    2300:	2b 9e 
    2302:	eb 02                	jmp    0x2306
    2304:	31 c0                	xor    %eax,%eax
    2306:	48 85 c0             	test   %rax,%rax
    2309:	74 09                	je     0x2314
    230b:	48 ff 00             	incq   (%rax)
    230e:	4c 01 78 08          	add    %r15,0x8(%rax)
    2312:	89 eb                	mov    %ebp,%ebx
    2314:	89 d8                	mov    %ebx,%eax
    2316:	48 81 c4 b8 00 00 00 	add    $0xb8,%rsp
    231d:	5b                   	pop    %rbx
    231e:	41 5c                	pop    %r12
    2320:	41 5d                	pop    %r13
    2322:	41 5e                	pop    %r14
    2324:	41 5f                	pop    %r15
    2326:	5d                   	pop    %rbp
    2327:	e9 e3 04 00 00       	jmp    0x280f
    232c:	b8 2c 00 00 00       	mov    $0x2c,%eax
    2331:	4c 89 f7             	mov    %r14,%rdi
    2334:	be d8 ff ff ff       	mov    $0xffffffd8,%esi
    2339:	e8 16 c9 75 db       	call   0xffffffffdb75ec54
    233e:	85 c0                	test   %eax,%eax
    2340:	0f 84 67 01 00 00    	je     0x24ad
    2346:	c7 04 24 07 02 00 00 	movl   $0x207,(%rsp)
    234d:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    2354:	8b ff ff 
    2357:	48 89 e6             	mov    %rsp,%rsi
    235a:	b8 01 00 00 00       	mov    $0x1,%eax
    235f:	8b 06                	mov    (%rsi),%eax
    2361:	3d 00 04 00 00       	cmp    $0x400,%eax
    2366:	73 16                	jae    0x237e
    2368:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    236f:	00 
    2370:	48 8b 00             	mov    (%rax),%rax
    2373:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    237a:	2b 9e 
    237c:	eb 02                	jmp    0x2380
    237e:	31 c0                	xor    %eax,%eax
    2380:	48 85 c0             	test   %rax,%rax
    2383:	0f 84 05 ff ff ff    	je     0x228e
    2389:	48 ff 40 08          	incq   0x8(%rax)
    238d:	e9 fc fe ff ff       	jmp    0x228e
    2392:	49 8b 06             	mov    (%r14),%rax
    2395:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    2399:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    239d:	48 39 ca             	cmp    %rcx,%rdx
    23a0:	0f 87 18 fb ff ff    	ja     0x1ebe
    23a6:	48 8d 50 22          	lea    0x22(%rax),%rdx
    23aa:	48 39 ca             	cmp    %rcx,%rdx
    23ad:	0f 87 0b fb ff ff    	ja     0x1ebe
    23b3:	8b 4c 24 38          	mov    0x38(%rsp),%ecx
    23b7:	66 c1 c1 08          	rol    $0x8,%cx
    23bb:	31 cd                	xor    %ecx,%ebp
    23bd:	c1 e5 10             	shl    $0x10,%ebp
    23c0:	41 0f b7 4c 24 04    	movzwl 0x4(%r12),%ecx
    23c6:	66 89 48 04          	mov    %cx,0x4(%rax)
    23ca:	41 8b 0c 24          	mov    (%r12),%ecx
    23ce:	89 08                	mov    %ecx,(%rax)
    23d0:	8b 48 14             	mov    0x14(%rax),%ecx
    23d3:	89 48 06             	mov    %ecx,0x6(%rax)
    23d6:	0f b7 48 18          	movzwl 0x18(%rax),%ecx
    23da:	66 89 48 0a          	mov    %cx,0xa(%rax)
    23de:	66 c7 40 0c 08 00    	movw   $0x8,0xc(%rax)
    23e4:	8d 8d ac 10 00 00    	lea    0x10ac(%rbp),%ecx
    23ea:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    23ef:	48 8b b4 24 a8 00 00 	mov    0xa8(%rsp),%rsi
    23f6:	00 
    23f7:	8b 36                	mov    (%rsi),%esi
    23f9:	c6 40 0e 45          	movb   $0x45,0xe(%rax)
    23fd:	88 50 0f             	mov    %dl,0xf(%rax)
    2400:	8b 54 24 28          	mov    0x28(%rsp),%edx
    2404:	83 c2 14             	add    $0x14,%edx
    2407:	66 0f 38 f1 50 10    	movbe  %dx,0x10(%rax)
    240d:	66 c1 c2 08          	rol    $0x8,%dx
    2411:	c7 40 12 00 00 00 00 	movl   $0x0,0x12(%rax)
    2418:	89 70 1e             	mov    %esi,0x1e(%rax)
    241b:	89 48 1a             	mov    %ecx,0x1a(%rax)
    241e:	66 c7 40 16 40 04    	movw   $0x440,0x16(%rax)
    2424:	0f b7 48 0e          	movzwl 0xe(%rax),%ecx
    2428:	0f b7 d2             	movzwl %dx,%edx
    242b:	0f b7 78 16          	movzwl 0x16(%rax),%edi
    242f:	48 01 cf             	add    %rcx,%rdi
    2432:	c1 ed 10             	shr    $0x10,%ebp
    2435:	48 01 fd             	add    %rdi,%rbp
    2438:	0f b7 ce             	movzwl %si,%ecx
    243b:	48 01 e9             	add    %rbp,%rcx
    243e:	48 01 d1             	add    %rdx,%rcx
    2441:	0f b7 50 20          	movzwl 0x20(%rax),%edx
    2445:	48 01 d1             	add    %rdx,%rcx
    2448:	48 81 c1 ac 10 00 00 	add    $0x10ac,%rcx
    244f:	48 89 ca             	mov    %rcx,%rdx
    2452:	48 c1 ea 10          	shr    $0x10,%rdx
    2456:	0f b7 f1             	movzwl %cx,%esi
    2459:	48 01 d6             	add    %rdx,%rsi
    245c:	48 81 f9 00 00 01 00 	cmp    $0x10000,%rcx
    2463:	48 0f 42 f1          	cmovb  %rcx,%rsi
    2467:	48 89 f1             	mov    %rsi,%rcx
    246a:	48 c1 e9 10          	shr    $0x10,%rcx
    246e:	0f b7 d6             	movzwl %si,%edx
    2471:	48 01 ca             	add    %rcx,%rdx
    2474:	48 81 fe 00 00 01 00 	cmp    $0x10000,%rsi
    247b:	48 0f 42 d6          	cmovb  %rsi,%rdx
    247f:	48 89 d1             	mov    %rdx,%rcx
    2482:	48 c1 e9 10          	shr    $0x10,%rcx
    2486:	0f b7 f2             	movzwl %dx,%esi
    2489:	01 f1                	add    %esi,%ecx
    248b:	48 81 fa 00 00 01 00 	cmp    $0x10000,%rdx
    2492:	0f 42 ca             	cmovb  %edx,%ecx
    2495:	89 ca                	mov    %ecx,%edx
    2497:	c1 ea 10             	shr    $0x10,%edx
    249a:	01 ca                	add    %ecx,%edx
    249c:	f7 d2                	not    %edx
    249e:	66 89 50 18          	mov    %dx,0x18(%rax)
    24a2:	41 bd 03 00 00 00    	mov    $0x3,%r13d
    24a8:	e9 e1 fd ff ff       	jmp    0x228e
    24ad:	49 8b 06             	mov    (%r14),%rax
    24b0:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    24b4:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    24b8:	48 39 ca             	cmp    %rcx,%rdx
    24bb:	0f 87 85 fe ff ff    	ja     0x2346
    24c1:	48 8d 50 36          	lea    0x36(%rax),%rdx
    24c5:	48 39 ca             	cmp    %rcx,%rdx
    24c8:	0f 87 78 fe ff ff    	ja     0x2346
    24ce:	41 0f b7 4c 24 04    	movzwl 0x4(%r12),%ecx
    24d4:	66 89 48 04          	mov    %cx,0x4(%rax)
    24d8:	41 8b 0c 24          	mov    (%r12),%ecx
    24dc:	89 08                	mov    %ecx,(%rax)
    24de:	8b 48 28             	mov    0x28(%rax),%ecx
    24e1:	89 48 06             	mov    %ecx,0x6(%rax)
    24e4:	0f b7 48 2c          	movzwl 0x2c(%rax),%ecx
    24e8:	66 89 48 0a          	mov    %cx,0xa(%rax)
    24ec:	66 c7 40 0c 86 dd    	movw   $0xdd86,0xc(%rax)
    24f2:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    24f7:	33 4c 24 40          	xor    0x40(%rsp),%ecx
    24fb:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    2500:	66 c7 40 10 00 00    	movw   $0x0,0x10(%rax)
    2506:	89 d6                	mov    %edx,%esi
    2508:	40 c0 ee 04          	shr    $0x4,%sil
    250c:	40 80 ce 60          	or     $0x60,%sil
    2510:	40 88 70 0e          	mov    %sil,0xe(%rax)
    2514:	c0 e2 04             	shl    $0x4,%dl
    2517:	88 50 0f             	mov    %dl,0xf(%rax)
    251a:	66 c7 40 14 04 40    	movw   $0x4004,0x14(%rax)
    2520:	0f b7 54 24 34       	movzwl 0x34(%rsp),%edx
    2525:	66 89 50 12          	mov    %dx,0x12(%rax)
    2529:	48 c7 40 16 01 00 00 	movq   $0x1,0x16(%rax)
    2530:	00 
    2531:	c7 40 1e 00 00 00 00 	movl   $0x0,0x1e(%rax)
    2538:	89 48 22             	mov    %ecx,0x22(%rax)
    253b:	48 8b 94 24 a8 00 00 	mov    0xa8(%rsp),%rdx
    2542:	00 
    2543:	48 8b 0a             	mov    (%rdx),%rcx
    2546:	48 8b 52 08          	mov    0x8(%rdx),%rdx
    254a:	48 89 48 26          	mov    %rcx,0x26(%rax)
    254e:	48 89 50 2e          	mov    %rdx,0x2e(%rax)
    2552:	41 bd 03 00 00 00    	mov    $0x3,%r13d
    2558:	e9 31 fd ff ff       	jmp    0x228e
    255d:	49 ff 45 28          	incq   0x28(%r13)
    2561:	e9 22 fd ff ff       	jmp    0x2288
    2566:	49 8b 04 24          	mov    (%r12),%rax
    256a:	48 ff c0             	inc    %rax
    256d:	49 89 04 24          	mov    %rax,(%r12)
    2571:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    2577:	73 31                	jae    0x25aa
    2579:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    2580:	00 
    2581:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    2588:	00 00 
    258a:	8b 44 24 68          	mov    0x68(%rsp),%eax
    258e:	89 04 24             	mov    %eax,(%rsp)
    2591:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    2596:	48 89 e2             	mov    %rsp,%rdx
    2599:	b8 02 00 00 00       	mov    $0x2,%eax
    259e:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    25a3:	31 c9                	xor    %ecx,%ecx
    25a5:	e8 4a 17 ec da       	call   0xffffffffdaec3cf4
    25aa:	48 ff 45 60          	incq   0x60(%rbp)
    25ae:	48 ff 45 20          	incq   0x20(%rbp)
    25b2:	0f b7 44 24 60       	movzwl 0x60(%rsp),%eax
    25b7:	89 44 24 38          	mov    %eax,0x38(%rsp)
    25bb:	4c 89 ed             	mov    %r13,%rbp
    25be:	e9 1b ed ff ff       	jmp    0x12de
    25c3:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    25ca:	48 bf 00 00 22 56 10 	movabs $0xffff8b1056220000,%rdi
    25d1:	8b ff ff 
    25d4:	48 89 e6             	mov    %rsp,%rsi
    25d7:	b8 01 00 00 00       	mov    $0x1,%eax
    25dc:	8b 06                	mov    (%rsi),%eax
    25de:	3d 00 04 00 00       	cmp    $0x400,%eax
    25e3:	73 16                	jae    0x25fb
    25e5:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    25ec:	00 
    25ed:	48 8b 00             	mov    (%rax),%rax
    25f0:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    25f7:	2b 9e 
    25f9:	eb 02                	jmp    0x25fd
    25fb:	31 c0                	xor    %eax,%eax
    25fd:	48 85 c0             	test   %rax,%rax
    2600:	0f 84 bc 00 00 00    	je     0x26c2
    2606:	49 89 c4             	mov    %rax,%r12
    2609:	b8 05 00 00 00       	mov    $0x5,%eax
    260e:	e8 f1 17 eb da       	call   0xffffffffdaeb3e04
    2613:	48 89 c1             	mov    %rax,%rcx
    2616:	49 2b 4c 24 08       	sub    0x8(%r12),%rcx
    261b:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    2622:	72 5a                	jb     0x267e
    2624:	49 c7 04 24 01 00 00 	movq   $0x1,(%r12)
    262b:	00 
    262c:	49 89 44 24 08       	mov    %rax,0x8(%r12)
    2631:	eb 5e                	jmp    0x2691
    2633:	89 08                	mov    %ecx,(%rax)
    2635:	49 ff 45 58          	incq   0x58(%r13)
    2639:	8b 44 24 70          	mov    0x70(%rsp),%eax
    263d:	89 04 24             	mov    %eax,(%rsp)
    2640:	48 bf 00 a0 d1 82 0f 	movabs $0xffff8b0f82d1a000,%rdi
    2647:	8b ff ff 
    264a:	48 89 e6             	mov    %rsp,%rsi
    264d:	b8 01 00 00 00       	mov    $0x1,%eax
    2652:	8b 06                	mov    (%rsi),%eax
    2654:	3d 00 02 00 00       	cmp    $0x200,%eax
    2659:	73 16                	jae    0x2671
    265b:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    2662:	00 
    2663:	48 8b 00             	mov    (%rax),%rax
    2666:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    266d:	2b 9e 
    266f:	eb 02                	jmp    0x2673
    2671:	31 c0                	xor    %eax,%eax
    2673:	48 85 c0             	test   %rax,%rax
    2676:	74 4e                	je     0x26c6
    2678:	48 ff 40 08          	incq   0x8(%rax)
    267c:	eb 48                	jmp    0x26c6
    267e:	49 8b 04 24          	mov    (%r12),%rax
    2682:	48 ff c0             	inc    %rax
    2685:	49 89 04 24          	mov    %rax,(%r12)
    2689:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    268f:	73 31                	jae    0x26c2
    2691:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    2698:	00 
    2699:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    26a0:	00 00 
    26a2:	8b 44 24 68          	mov    0x68(%rsp),%eax
    26a6:	89 04 24             	mov    %eax,(%rsp)
    26a9:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    26ae:	48 89 e2             	mov    %rsp,%rdx
    26b1:	b8 02 00 00 00       	mov    $0x2,%eax
    26b6:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    26bb:	31 c9                	xor    %ecx,%ecx
    26bd:	e8 42 13 eb da       	call   0xffffffffdaeb3a04
    26c2:	49 ff 45 60          	incq   0x60(%r13)
    26c6:	49 ff 45 20          	incq   0x20(%r13)
    26ca:	0f b7 44 24 60       	movzwl 0x60(%rsp),%eax
    26cf:	89 44 24 38          	mov    %eax,0x38(%rsp)
    26d3:	e9 d8 f6 ff ff       	jmp    0x1db0
    26d8:	8b 07                	mov    (%rdi),%eax
    26da:	8b 4f 04             	mov    0x4(%rdi),%ecx
    26dd:	8d 91 ff c0 ad de    	lea    -0x21523f01(%rcx),%edx
    26e3:	8b 77 08             	mov    0x8(%rdi),%esi
    26e6:	29 f0                	sub    %esi,%eax
    26e8:	44 8d 86 ff c0 ad de 	lea    -0x21523f01(%rsi),%r8d
    26ef:	c4 43 7b f0 c0 1c    	rorx   $0x1c,%r8d,%r8d
    26f5:	41 31 c0             	xor    %eax,%r8d
    26f8:	44 29 c2             	sub    %r8d,%edx
    26fb:	c4 c3 7b f0 c0 1a    	rorx   $0x1a,%r8d,%eax
    2701:	31 d0                	xor    %edx,%eax
    2703:	01 f1                	add    %esi,%ecx
    2705:	81 c1 fe 81 5b bd    	add    $0xbd5b81fe,%ecx
    270b:	41 01 c8             	add    %ecx,%r8d
    270e:	42 8d 34 00          	lea    (%rax,%r8,1),%esi
    2712:	29 c1                	sub    %eax,%ecx
    2714:	c4 63 7b f0 c8 18    	rorx   $0x18,%eax,%r9d
    271a:	41 31 c9             	xor    %ecx,%r9d
    271d:	45 29 c8             	sub    %r9d,%r8d
    2720:	c4 c3 7b f0 d1 10    	rorx   $0x10,%r9d,%edx
    2726:	44 31 c2             	xor    %r8d,%edx
    2729:	41 01 f1             	add    %esi,%r9d
    272c:	29 d6                	sub    %edx,%esi
    272e:	c4 e3 7b f0 ca 0d    	rorx   $0xd,%edx,%ecx
    2734:	31 f1                	xor    %esi,%ecx
    2736:	44 01 ca             	add    %r9d,%edx
    2739:	8d 04 11             	lea    (%rcx,%rdx,1),%eax
    273c:	41 29 c9             	sub    %ecx,%r9d
    273f:	c4 e3 7b f0 c9 1c    	rorx   $0x1c,%ecx,%ecx
    2745:	44 31 c9             	xor    %r9d,%ecx
    2748:	0f b6 77 0f          	movzbl 0xf(%rdi),%esi
    274c:	c1 e6 18             	shl    $0x18,%esi
    274f:	44 0f b6 47 0e       	movzbl 0xe(%rdi),%r8d
    2754:	41 c1 e0 10          	shl    $0x10,%r8d
    2758:	41 01 f0             	add    %esi,%r8d
    275b:	44 0f b6 4f 0d       	movzbl 0xd(%rdi),%r9d
    2760:	41 c1 e1 08          	shl    $0x8,%r9d
    2764:	45 01 c1             	add    %r8d,%r9d
    2767:	0f b6 77 0c          	movzbl 0xc(%rdi),%esi
    276b:	44 01 ce             	add    %r9d,%esi
    276e:	01 d6                	add    %edx,%esi
    2770:	31 c1                	xor    %eax,%ecx
    2772:	c4 e3 7b f0 d0 12    	rorx   $0x12,%eax,%edx
    2778:	29 d1                	sub    %edx,%ecx
    277a:	31 ce                	xor    %ecx,%esi
    277c:	c4 e3 7b f0 d1 15    	rorx   $0x15,%ecx,%edx
    2782:	29 d6                	sub    %edx,%esi
    2784:	31 f0                	xor    %esi,%eax
    2786:	c4 e3 7b f0 d6 07    	rorx   $0x7,%esi,%edx
    278c:	29 d0                	sub    %edx,%eax
    278e:	31 c1                	xor    %eax,%ecx
    2790:	c4 e3 7b f0 d0 10    	rorx   $0x10,%eax,%edx
    2796:	29 d1                	sub    %edx,%ecx
    2798:	31 ce                	xor    %ecx,%esi
    279a:	c4 e3 7b f0 d1 1c    	rorx   $0x1c,%ecx,%edx
    27a0:	29 d6                	sub    %edx,%esi
    27a2:	31 f0                	xor    %esi,%eax
    27a4:	c4 e3 7b f0 d6 12    	rorx   $0x12,%esi,%edx
    27aa:	29 d0                	sub    %edx,%eax
    27ac:	c4 e3 7b f0 d0 08    	rorx   $0x8,%eax,%edx
    27b2:	31 c8                	xor    %ecx,%eax
    27b4:	29 d0                	sub    %edx,%eax
    27b6:	c3                   	ret
    27b7:	81 c7 f7 c0 ad e0    	add    $0xe0adc0f7,%edi
    27bd:	81 c6 f7 c0 ad e0    	add    $0xe0adc0f7,%esi
    27c3:	89 f0                	mov    %esi,%eax
    27c5:	35 f7 c0 ad e0       	xor    $0xe0adc0f7,%eax
    27ca:	c4 e3 7b f0 ce 12    	rorx   $0x12,%esi,%ecx
    27d0:	29 c8                	sub    %ecx,%eax
    27d2:	31 c7                	xor    %eax,%edi
    27d4:	c4 e3 7b f0 c8 15    	rorx   $0x15,%eax,%ecx
    27da:	29 cf                	sub    %ecx,%edi
    27dc:	31 fe                	xor    %edi,%esi
    27de:	c4 e3 7b f0 cf 07    	rorx   $0x7,%edi,%ecx
    27e4:	29 ce                	sub    %ecx,%esi
    27e6:	31 f0                	xor    %esi,%eax
    27e8:	c4 e3 7b f0 ce 10    	rorx   $0x10,%esi,%ecx
    27ee:	29 c8                	sub    %ecx,%eax
    27f0:	31 c7                	xor    %eax,%edi
    27f2:	c4 e3 7b f0 c8 1c    	rorx   $0x1c,%eax,%ecx
    27f8:	29 cf                	sub    %ecx,%edi
    27fa:	31 fe                	xor    %edi,%esi
    27fc:	c4 e3 7b f0 cf 12    	rorx   $0x12,%edi,%ecx
    2802:	29 ce                	sub    %ecx,%esi
    2804:	31 f0                	xor    %esi,%eax
    2806:	c4 e3 7b f0 ce 08    	rorx   $0x8,%esi,%ecx
    280c:	29 c8                	sub    %ecx,%eax
    280e:	c3                   	ret
    280f:	c9                   	leave
    2810:	e9 2f c3 a0 db       	jmp    0xffffffffdba0eb44
