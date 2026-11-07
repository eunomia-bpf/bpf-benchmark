
corpus/results/kprog_app_coverage_20261107/map-identity-v1/actual-guest/fixed/native-lowering-disabled-0.jit.bin:     file format binary


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
      31:	0f 87 6f 22 00 00    	ja     0x22a6
      37:	49 89 fe             	mov    %rdi,%r14
      3a:	c7 84 24 94 00 00 00 	movl   $0x210,0x94(%rsp)
      41:	10 02 00 00 
      45:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
      80:	0f 84 20 22 00 00    	je     0x22a6
      86:	4d 29 e7             	sub    %r12,%r15
      89:	48 ff 00             	incq   (%rax)
      8c:	4c 01 78 08          	add    %r15,0x8(%rax)
      90:	41 0f b7 44 24 0c    	movzwl 0xc(%r12),%eax
      96:	3d 86 dd 00 00       	cmp    $0xdd86,%eax
      9b:	0f 84 5c 01 00 00    	je     0x1fd
      a1:	83 f8 08             	cmp    $0x8,%eax
      a4:	0f 85 94 21 00 00    	jne    0x223e
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
     11d:	0f 87 f7 20 00 00    	ja     0x221a
     123:	41 0f b6 44 24 0e    	movzbl 0xe(%r12),%eax
     129:	24 0f                	and    $0xf,%al
     12b:	3c 05                	cmp    $0x5,%al
     12d:	0f 85 e7 20 00 00    	jne    0x221a
     133:	41 0f b6 44 24 0f    	movzbl 0xf(%r12),%eax
     139:	88 44 24 6d          	mov    %al,0x6d(%rsp)
     13d:	41 0f b6 44 24 17    	movzbl 0x17(%r12),%eax
     143:	88 44 24 64          	mov    %al,0x64(%rsp)
     147:	41 0f b7 4c 24 14    	movzwl 0x14(%r12),%ecx
     14d:	f7 c1 3f ff 00 00    	test   $0xff3f,%ecx
     153:	0f 85 c1 20 00 00    	jne    0x221a
     159:	45 0f b7 44 24 10    	movzwl 0x10(%r12),%r8d
     15f:	3c 01                	cmp    $0x1,%al
     161:	0f 85 dd 03 00 00    	jne    0x544
     167:	4d 8d 6c 24 2a       	lea    0x2a(%r12),%r13
     16c:	4d 39 cd             	cmp    %r9,%r13
     16f:	0f 87 a5 20 00 00    	ja     0x221a
     175:	0f b6 45 00          	movzbl 0x0(%rbp),%eax
     179:	83 f8 03             	cmp    $0x3,%eax
     17c:	0f 84 3f 09 00 00    	je     0xac1
     182:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     188:	83 f8 08             	cmp    $0x8,%eax
     18b:	0f 85 8f 20 00 00    	jne    0x2220
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
     270:	0f 87 a4 1f 00 00    	ja     0x221a
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
     29f:	0f 84 75 1f 00 00    	je     0x221a
     2a5:	66 41 0f 38 f0 7c 24 	movbe  0x12(%r12),%di
     2ac:	12 
     2ad:	83 f8 3a             	cmp    $0x3a,%eax
     2b0:	0f 85 bc 00 00 00    	jne    0x372
     2b6:	49 8d 44 24 3e       	lea    0x3e(%r12),%rax
     2bb:	48 39 e8             	cmp    %rbp,%rax
     2be:	0f 87 56 1f 00 00    	ja     0x221a
     2c4:	41 0f b6 00          	movzbl (%r8),%eax
     2c8:	83 f8 01             	cmp    $0x1,%eax
     2cb:	0f 84 ec 03 00 00    	je     0x6bd
     2d1:	83 f8 02             	cmp    $0x2,%eax
     2d4:	0f 84 7a 03 00 00    	je     0x654
     2da:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     2e0:	3d 80 00 00 00       	cmp    $0x80,%eax
     2e5:	0f 85 35 1f 00 00    	jne    0x2220
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
     3aa:	0f 87 6a 1e 00 00    	ja     0x221a
     3b0:	41 0f b6 00          	movzbl (%r8),%eax
     3b4:	83 f8 03             	cmp    $0x3,%eax
     3b7:	0f 84 c3 05 00 00    	je     0x980
     3bd:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     3c3:	83 f8 08             	cmp    $0x8,%eax
     3c6:	0f 85 54 1e 00 00    	jne    0x2220
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
     4d0:	e9 4b 1d 00 00       	jmp    0x2220
     4d5:	31 c9                	xor    %ecx,%ecx
     4d7:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     4dd:	3c 11                	cmp    $0x11,%al
     4df:	0f 84 c7 00 00 00    	je     0x5ac
     4e5:	0f b6 d0             	movzbl %al,%edx
     4e8:	83 fa 06             	cmp    $0x6,%edx
     4eb:	0f 85 2f 1d 00 00    	jne    0x2220
     4f1:	49 8d 54 24 66       	lea    0x66(%r12),%rdx
     4f6:	f6 c1 01             	test   $0x1,%cl
     4f9:	49 0f 44 d0          	cmove  %r8,%rdx
     4fd:	48 8d 72 14          	lea    0x14(%rdx),%rsi
     501:	48 39 ee             	cmp    %rbp,%rsi
     504:	0f 87 10 1d 00 00    	ja     0x221a
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
     566:	0f 87 ae 1c 00 00    	ja     0x221a
     56c:	0f b6 45 00          	movzbl 0x0(%rbp),%eax
     570:	83 f8 01             	cmp    $0x1,%eax
     573:	0f 84 1c 09 00 00    	je     0xe95
     579:	83 f8 02             	cmp    $0x2,%eax
     57c:	0f 84 aa 08 00 00    	je     0xe2c
     582:	41 bd 02 00 00 00    	mov    $0x2,%r13d
     588:	3d 80 00 00 00       	cmp    $0x80,%eax
     58d:	0f 85 8d 1c 00 00    	jne    0x2220
     593:	49 8d 44 24 3e       	lea    0x3e(%r12),%rax
     598:	41 bd 01 00 00 00    	mov    $0x1,%r13d
     59e:	4c 39 c8             	cmp    %r9,%rax
     5a1:	0f 86 44 fd ff ff    	jbe    0x2eb
     5a7:	e9 74 1c 00 00       	jmp    0x2220
     5ac:	49 8d 54 24 66       	lea    0x66(%r12),%rdx
     5b1:	f6 c1 01             	test   $0x1,%cl
     5b4:	49 0f 44 d0          	cmove  %r8,%rdx
     5b8:	48 8d 72 08          	lea    0x8(%rdx),%rsi
     5bc:	48 39 ee             	cmp    %rbp,%rsi
     5bf:	0f 87 55 1c 00 00    	ja     0x221a
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
     5fe:	0f 85 1c 1c 00 00    	jne    0x2220
     604:	49 8d 54 24 3e       	lea    0x3e(%r12),%rdx
     609:	f6 c1 01             	test   $0x1,%cl
     60c:	48 0f 44 d5          	cmove  %rbp,%rdx
     610:	48 8d 72 14          	lea    0x14(%rdx),%rsi
     614:	4c 39 ce             	cmp    %r9,%rsi
     617:	0f 87 fd 1b 00 00    	ja     0x221a
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
     663:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     699:	0f 84 7b 1b 00 00    	je     0x221a
     69f:	48 ff 00             	incq   (%rax)
     6a2:	41 0f 38 f0 4c 24 3a 	movbe  0x3a(%r12),%ecx
     6a9:	81 f9 ff 04 00 00    	cmp    $0x4ff,%ecx
     6af:	44 89 ef             	mov    %r13d,%edi
     6b2:	4c 8b 44 24 38       	mov    0x38(%rsp),%r8
     6b7:	77 04                	ja     0x6bd
     6b9:	48 ff 40 08          	incq   0x8(%rax)
     6bd:	49 8d 44 24 66       	lea    0x66(%r12),%rax
     6c2:	48 39 e8             	cmp    %rbp,%rax
     6c5:	0f 87 4f 1b 00 00    	ja     0x221a
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
     748:	48 bf 00 08 9e 47 10 	movabs $0xffff8b10479e0800,%rdi
     74f:	8b ff ff 
     752:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     759:	00 
     75a:	b8 01 00 00 00       	mov    $0x1,%eax
     75f:	e8 48 12 ec da       	call   0xffffffffdaec19ac
     764:	48 85 c0             	test   %rax,%rax
     767:	74 04                	je     0x76d
     769:	48 83 c0 48          	add    $0x48,%rax
     76d:	48 85 c0             	test   %rax,%rax
     770:	0f 84 c0 02 00 00    	je     0xa36
     776:	48 89 e9             	mov    %rbp,%rcx
     779:	4c 29 e1             	sub    %r12,%rcx
     77c:	41 bd 01 00 00 00    	mov    $0x1,%r13d
     782:	48 81 f9 ea 05 00 00 	cmp    $0x5ea,%rcx
     789:	0f 8f 91 1a 00 00    	jg     0x2220
     78f:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
     794:	c7 84 24 9c 00 00 00 	movl   $0x200,0x9c(%rsp)
     79b:	00 02 00 00 
     79f:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     7da:	0f 84 3a 1a 00 00    	je     0x221a
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
     82c:	48 bf 00 60 27 56 10 	movabs $0xffff8b1056276000,%rdi
     833:	8b ff ff 
     836:	48 8d b4 24 98 00 00 	lea    0x98(%rsp),%rsi
     83d:	00 
     83e:	b8 01 00 00 00       	mov    $0x1,%eax
     843:	e8 14 5d ec da       	call   0xffffffffdaec655c
     848:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     84d:	48 85 c0             	test   %rax,%rax
     850:	75 5a                	jne    0x8ac
     852:	c7 04 24 03 02 00 00 	movl   $0x203,(%rsp)
     859:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     88f:	0f 84 85 19 00 00    	je     0x221a
     895:	48 ff 00             	incq   (%rax)
     898:	48 b8 00 5c 01 56 10 	movabs $0xffff8b1056015c00,%rax
     89f:	8b ff ff 
     8a2:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     8a7:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
     8ac:	41 f6 45 00 04       	testb  $0x4,0x0(%r13)
     8b1:	0f 84 43 08 00 00    	je     0x10fa
     8b7:	f6 44 24 6c 01       	testb  $0x1,0x6c(%rsp)
     8bc:	0f 85 26 06 00 00    	jne    0xee8
     8c2:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%rsp)
     8c9:	00 
     8ca:	48 bf 00 20 8e 83 0f 	movabs $0xffff8b0f838e2000,%rdi
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
     900:	0f 84 14 19 00 00    	je     0x221a
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
     998:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     9ce:	0f 84 46 18 00 00    	je     0x221a
     9d4:	48 ff 00             	incq   (%rax)
     9d7:	41 80 7c 24 3c 04    	cmpb   $0x4,0x3c(%r12)
     9dd:	77 04                	ja     0x9e3
     9df:	48 ff 40 08          	incq   0x8(%rax)
     9e3:	8b 7c 24 34          	mov    0x34(%rsp),%edi
     9e7:	4c 8b 44 24 38       	mov    0x38(%rsp),%r8
     9ec:	49 8d 44 24 52       	lea    0x52(%r12),%rax
     9f1:	48 39 e8             	cmp    %rbp,%rax
     9f4:	0f 87 20 18 00 00    	ja     0x221a
     9fa:	41 0f b6 45 00       	movzbl 0x0(%r13),%eax
     9ff:	24 0f                	and    $0xf,%al
     a01:	3c 05                	cmp    $0x5,%al
     a03:	0f 85 11 18 00 00    	jne    0x221a
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
     a40:	48 bf 00 08 9e 47 10 	movabs $0xffff8b10479e0800,%rdi
     a47:	8b ff ff 
     a4a:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     a51:	00 
     a52:	b8 01 00 00 00       	mov    $0x1,%eax
     a57:	e8 50 0f ec da       	call   0xffffffffdaec19ac
     a5c:	48 85 c0             	test   %rax,%rax
     a5f:	74 04                	je     0xa65
     a61:	48 83 c0 48          	add    $0x48,%rax
     a65:	48 85 c0             	test   %rax,%rax
     a68:	0f 84 b2 17 00 00    	je     0x2220
     a6e:	f6 00 88             	testb  $0x88,(%rax)
     a71:	0f 85 ff fc ff ff    	jne    0x776
     a77:	66 c7 44 24 62 00 00 	movw   $0x0,0x62(%rsp)
     a7e:	e9 f3 fc ff ff       	jmp    0x776
     a83:	49 8d 54 24 3e       	lea    0x3e(%r12),%rdx
     a88:	f6 c1 01             	test   $0x1,%cl
     a8b:	48 0f 44 d5          	cmove  %rbp,%rdx
     a8f:	48 8d 72 08          	lea    0x8(%rdx),%rsi
     a93:	4c 39 ce             	cmp    %r9,%rsi
     a96:	0f 87 7e 17 00 00    	ja     0x221a
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
     adb:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     b11:	0f 84 03 17 00 00    	je     0x221a
     b17:	48 ff 00             	incq   (%rax)
     b1a:	41 80 7c 24 28 04    	cmpb   $0x4,0x28(%r12)
     b20:	77 04                	ja     0xb26
     b22:	48 ff 40 08          	incq   0x8(%rax)
     b26:	44 0f b7 44 24 34    	movzwl 0x34(%rsp),%r8d
     b2c:	4c 8b 4c 24 38       	mov    0x38(%rsp),%r9
     b31:	49 8d 44 24 3e       	lea    0x3e(%r12),%rax
     b36:	4c 39 c8             	cmp    %r9,%rax
     b39:	0f 87 db 16 00 00    	ja     0x221a
     b3f:	41 0f b6 45 00       	movzbl 0x0(%r13),%eax
     b44:	24 0f                	and    $0xf,%al
     b46:	3c 05                	cmp    $0x5,%al
     b48:	0f 85 cc 16 00 00    	jne    0x221a
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
     ba6:	48 bf 00 08 9e 47 10 	movabs $0xffff8b10479e0800,%rdi
     bad:	8b ff ff 
     bb0:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     bb7:	00 
     bb8:	b8 01 00 00 00       	mov    $0x1,%eax
     bbd:	e8 ea 0d ec da       	call   0xffffffffdaec19ac
     bc2:	48 85 c0             	test   %rax,%rax
     bc5:	74 04                	je     0xbcb
     bc7:	48 83 c0 48          	add    $0x48,%rax
     bcb:	48 85 c0             	test   %rax,%rax
     bce:	0f 84 0b 02 00 00    	je     0xddf
     bd4:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
     bd9:	4c 29 e1             	sub    %r12,%rcx
     bdc:	41 bd 01 00 00 00    	mov    $0x1,%r13d
     be2:	48 81 f9 ea 05 00 00 	cmp    $0x5ea,%rcx
     be9:	0f 8f 31 16 00 00    	jg     0x2220
     bef:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
     bf4:	c7 84 24 9c 00 00 00 	movl   $0x200,0x9c(%rsp)
     bfb:	00 02 00 00 
     bff:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     c3a:	0f 84 da 15 00 00    	je     0x221a
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
     c8c:	48 bf 00 60 27 56 10 	movabs $0xffff8b1056276000,%rdi
     c93:	8b ff ff 
     c96:	48 8d b4 24 98 00 00 	lea    0x98(%rsp),%rsi
     c9d:	00 
     c9e:	b8 01 00 00 00       	mov    $0x1,%eax
     ca3:	e8 b4 58 ec da       	call   0xffffffffdaec655c
     ca8:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     cad:	48 85 c0             	test   %rax,%rax
     cb0:	75 5a                	jne    0xd0c
     cb2:	c7 04 24 03 02 00 00 	movl   $0x203,(%rsp)
     cb9:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     cef:	0f 84 25 15 00 00    	je     0x221a
     cf5:	48 ff 00             	incq   (%rax)
     cf8:	48 b8 00 5c 01 56 10 	movabs $0xffff8b1056015c00,%rax
     cff:	8b ff ff 
     d02:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
     d07:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
     d0c:	41 f6 45 00 04       	testb  $0x4,0x0(%r13)
     d11:	0f 84 4f 0e 00 00    	je     0x1b66
     d17:	f6 44 24 6c 01       	testb  $0x1,0x6c(%rsp)
     d1c:	0f 85 27 02 00 00    	jne    0xf49
     d22:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%rsp)
     d29:	00 
     d2a:	48 bf 00 20 8e 83 0f 	movabs $0xffff8b0f838e2000,%rdi
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
     d60:	0f 84 b4 14 00 00    	je     0x221a
     d66:	49 89 c5             	mov    %rax,%r13
     d69:	49 83 c4 3e          	add    $0x3e,%r12
     d6d:	f6 44 24 6c 01       	testb  $0x1,0x6c(%rsp)
     d72:	4c 0f 44 e5          	cmove  %rbp,%r12
     d76:	49 8d 4c 24 09       	lea    0x9(%r12),%rcx
     d7b:	48 3b 4c 24 38       	cmp    0x38(%rsp),%rcx
     d80:	0f 87 d7 0d 00 00    	ja     0x1b5d
     d86:	41 0f b6 44 24 08    	movzbl 0x8(%r12),%eax
     d8c:	84 c0                	test   %al,%al
     d8e:	0f 88 79 02 00 00    	js     0x100d
     d94:	49 83 c4 11          	add    $0x11,%r12
     d98:	4c 3b 64 24 38       	cmp    0x38(%rsp),%r12
     d9d:	0f 87 ba 0d 00 00    	ja     0x1b5d
     da3:	0f b6 11             	movzbl (%rcx),%edx
     da6:	89 d0                	mov    %edx,%eax
     da8:	c1 e8 06             	shr    $0x6,%eax
     dab:	83 f8 03             	cmp    $0x3,%eax
     dae:	0f 84 b2 0b 00 00    	je     0x1966
     db4:	83 f8 02             	cmp    $0x2,%eax
     db7:	0f 84 93 0b 00 00    	je     0x1950
     dbd:	83 f8 01             	cmp    $0x1,%eax
     dc0:	0f 85 97 0d 00 00    	jne    0x1b5d
     dc6:	83 e2 3f             	and    $0x3f,%edx
     dc9:	c1 e2 0a             	shl    $0xa,%edx
     dcc:	0f b6 71 01          	movzbl 0x1(%rcx),%esi
     dd0:	8d 14 b2             	lea    (%rdx,%rsi,4),%edx
     dd3:	0f b6 49 02          	movzbl 0x2(%rcx),%ecx
     dd7:	c0 e9 06             	shr    $0x6,%cl
     dda:	e9 a4 0b 00 00       	jmp    0x1983
     ddf:	66 c7 84 24 90 00 00 	movw   $0x0,0x90(%rsp)
     de6:	00 00 00 
     de9:	48 bf 00 08 9e 47 10 	movabs $0xffff8b10479e0800,%rdi
     df0:	8b ff ff 
     df3:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
     dfa:	00 
     dfb:	b8 01 00 00 00       	mov    $0x1,%eax
     e00:	e8 a7 0b ec da       	call   0xffffffffdaec19ac
     e05:	48 85 c0             	test   %rax,%rax
     e08:	74 04                	je     0xe0e
     e0a:	48 83 c0 48          	add    $0x48,%rax
     e0e:	48 85 c0             	test   %rax,%rax
     e11:	0f 84 09 14 00 00    	je     0x2220
     e17:	f6 00 88             	testb  $0x88,(%rax)
     e1a:	0f 85 b4 fd ff ff    	jne    0xbd4
     e20:	66 c7 44 24 62 00 00 	movw   $0x0,0x62(%rsp)
     e27:	e9 a8 fd ff ff       	jmp    0xbd4
     e2c:	4c 89 4c 24 38       	mov    %r9,0x38(%rsp)
     e31:	45 89 c5             	mov    %r8d,%r13d
     e34:	c7 04 24 0c 02 00 00 	movl   $0x20c,(%rsp)
     e3b:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     e71:	0f 84 a3 13 00 00    	je     0x221a
     e77:	48 ff 00             	incq   (%rax)
     e7a:	41 0f 38 f0 4c 24 26 	movbe  0x26(%r12),%ecx
     e81:	81 f9 ff 04 00 00    	cmp    $0x4ff,%ecx
     e87:	45 89 e8             	mov    %r13d,%r8d
     e8a:	4c 8b 4c 24 38       	mov    0x38(%rsp),%r9
     e8f:	77 04                	ja     0xe95
     e91:	48 ff 40 08          	incq   0x8(%rax)
     e95:	49 8d 44 24 52       	lea    0x52(%r12),%rax
     e9a:	4c 39 c8             	cmp    %r9,%rax
     e9d:	0f 87 77 13 00 00    	ja     0x221a
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
     eef:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     f25:	0f 84 ef 12 00 00    	je     0x221a
     f2b:	48 ff 00             	incq   (%rax)
     f2e:	41 0f b6 4c 24 37    	movzbl 0x37(%r12),%ecx
     f34:	80 c1 fd             	add    $0xfd,%cl
     f37:	80 f9 01             	cmp    $0x1,%cl
     f3a:	0f 87 b5 01 00 00    	ja     0x10f5
     f40:	48 ff 40 08          	incq   0x8(%rax)
     f44:	e9 ac 01 00 00       	jmp    0x10f5
     f49:	c7 04 24 0b 02 00 00 	movl   $0x20b,(%rsp)
     f50:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
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
     f86:	0f 84 8e 12 00 00    	je     0x221a
     f8c:	48 ff 00             	incq   (%rax)
     f8f:	41 0f b6 4c 24 23    	movzbl 0x23(%r12),%ecx
     f95:	83 c9 02             	or     $0x2,%ecx
     f98:	83 f9 03             	cmp    $0x3,%ecx
     f9b:	0f 85 c0 0b 00 00    	jne    0x1b61
     fa1:	48 ff 40 08          	incq   0x8(%rax)
     fa5:	e9 b7 0b 00 00       	jmp    0x1b61
     faa:	49 8d 54 24 16       	lea    0x16(%r12),%rdx
     faf:	48 39 ea             	cmp    %rbp,%rdx
     fb2:	0f 87 3a 01 00 00    	ja     0x10f2
     fb8:	f6 c1 20             	test   $0x20,%cl
     fbb:	0f 85 b3 00 00 00    	jne    0x1074
     fc1:	48 ff 40 08          	incq   0x8(%rax)
     fc5:	8b 44 24 70          	mov    0x70(%rsp),%eax
     fc9:	89 04 24             	mov    %eax,(%rsp)
     fcc:	48 bf 00 c0 2a 83 0f 	movabs $0xffff8b0f832ac000,%rdi
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
    1017:	0f 87 40 0b 00 00    	ja     0x1b5d
    101d:	a8 20                	test   $0x20,%al
    101f:	0f 85 0a 09 00 00    	jne    0x192f
    1025:	49 ff 45 08          	incq   0x8(%r13)
    1029:	8b 44 24 70          	mov    0x70(%rsp),%eax
    102d:	89 04 24             	mov    %eax,(%rsp)
    1030:	48 bf 00 c0 2a 83 0f 	movabs $0xffff8b0f832ac000,%rdi
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
    1066:	0f 84 f5 0a 00 00    	je     0x1b61
    106c:	48 ff 00             	incq   (%rax)
    106f:	e9 ed 0a 00 00       	jmp    0x1b61
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
    10d1:	0f 84 92 07 00 00    	je     0x1869
    10d7:	83 f9 02             	cmp    $0x2,%ecx
    10da:	0f 84 83 07 00 00    	je     0x1863
    10e0:	83 f9 01             	cmp    $0x1,%ecx
    10e3:	0f 85 86 07 00 00    	jne    0x186f
    10e9:	48 83 c0 38          	add    $0x38,%rax
    10ed:	e9 81 07 00 00       	jmp    0x1873
    10f2:	48 ff 00             	incq   (%rax)
    10f5:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    10fa:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    10ff:	89 4c 24 38          	mov    %ecx,0x38(%rsp)
    1103:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    1108:	75 4e                	jne    0x1158
    110a:	41 f6 45 00 02       	testb  $0x2,0x0(%r13)
    110f:	75 47                	jne    0x1158
    1111:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    1116:	b8 01 00 00 00       	mov    $0x1,%eax
    111b:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    1120:	e8 b7 28 eb da       	call   0xffffffffdaeb39dc
    1125:	48 85 c0             	test   %rax,%rax
    1128:	74 2a                	je     0x1154
    112a:	49 89 c5             	mov    %rax,%r13
    112d:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    1132:	75 2c                	jne    0x1160
    1134:	b8 05 00 00 00       	mov    $0x5,%eax
    1139:	e8 ce 2c eb da       	call   0xffffffffdaeb3e0c
    113e:	48 89 c1             	mov    %rax,%rcx
    1141:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    1145:	48 ba 00 ac 23 fc 06 	movabs $0x6fc23ac00,%rdx
    114c:	00 00 00 
    114f:	48 39 d1             	cmp    %rdx,%rcx
    1152:	76 08                	jbe    0x115c
    1154:	31 ed                	xor    %ebp,%ebp
    1156:	eb 45                	jmp    0x119d
    1158:	31 ed                	xor    %ebp,%ebp
    115a:	eb 46                	jmp    0x11a2
    115c:	49 89 45 08          	mov    %rax,0x8(%r13)
    1160:	41 8b 45 00          	mov    0x0(%r13),%eax
    1164:	89 04 24             	mov    %eax,(%rsp)
    1167:	89 44 24 68          	mov    %eax,0x68(%rsp)
    116b:	48 bf 00 50 87 40 86 	movabs $0xffffd28640875000,%rdi
    1172:	d2 ff ff 
    1175:	48 89 e6             	mov    %rsp,%rsi
    1178:	b8 01 00 00 00       	mov    $0x1,%eax
    117d:	8b 06                	mov    (%rsi),%eax
    117f:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1184:	73 12                	jae    0x1198
    1186:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    118d:	48 01 f8             	add    %rdi,%rax
    1190:	48 05 30 01 00 00    	add    $0x130,%rax
    1196:	eb 02                	jmp    0x119a
    1198:	31 c0                	xor    %eax,%eax
    119a:	48 89 c5             	mov    %rax,%rbp
    119d:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    11a2:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    11a7:	0f 85 0f 01 00 00    	jne    0x12bc
    11ad:	41 f6 45 01 02       	testb  $0x2,0x1(%r13)
    11b2:	0f 84 04 01 00 00    	je     0x12bc
    11b8:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    11bf:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    11c6:	8b ff ff 
    11c9:	48 89 e6             	mov    %rsp,%rsi
    11cc:	b8 01 00 00 00       	mov    $0x1,%eax
    11d1:	8b 06                	mov    (%rsi),%eax
    11d3:	3d 00 04 00 00       	cmp    $0x400,%eax
    11d8:	73 16                	jae    0x11f0
    11da:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    11e1:	00 
    11e2:	48 8b 00             	mov    (%rax),%rax
    11e5:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    11ec:	2b 9e 
    11ee:	eb 02                	jmp    0x11f2
    11f0:	31 c0                	xor    %eax,%eax
    11f2:	48 85 c0             	test   %rax,%rax
    11f5:	0f 84 c1 00 00 00    	je     0x12bc
    11fb:	49 89 c5             	mov    %rax,%r13
    11fe:	b8 05 00 00 00       	mov    $0x5,%eax
    1203:	e8 04 2c eb da       	call   0xffffffffdaeb3e0c
    1208:	48 89 c1             	mov    %rax,%rcx
    120b:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    120f:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    1216:	72 0e                	jb     0x1226
    1218:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    121f:	00 
    1220:	49 89 45 08          	mov    %rax,0x8(%r13)
    1224:	eb 17                	jmp    0x123d
    1226:	49 8b 45 00          	mov    0x0(%r13),%rax
    122a:	48 ff c0             	inc    %rax
    122d:	49 89 45 00          	mov    %rax,0x0(%r13)
    1231:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    1237:	0f 83 7f 00 00 00    	jae    0x12bc
    123d:	48 bf 00 24 01 56 10 	movabs $0xffff8b1056012400,%rdi
    1244:	8b ff ff 
    1247:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
    124e:	00 
    124f:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    1255:	e8 82 27 eb da       	call   0xffffffffdaeb39dc
    125a:	48 85 c0             	test   %rax,%rax
    125d:	74 5d                	je     0x12bc
    125f:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    1264:	48 89 c7             	mov    %rax,%rdi
    1267:	e8 70 27 eb da       	call   0xffffffffdaeb39dc
    126c:	48 85 c0             	test   %rax,%rax
    126f:	74 4b                	je     0x12bc
    1271:	c7 04 24 0f 02 00 00 	movl   $0x20f,(%rsp)
    1278:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    127f:	8b ff ff 
    1282:	48 89 e6             	mov    %rsp,%rsi
    1285:	b8 01 00 00 00       	mov    $0x1,%eax
    128a:	8b 06                	mov    (%rsi),%eax
    128c:	3d 00 04 00 00       	cmp    $0x400,%eax
    1291:	73 16                	jae    0x12a9
    1293:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    129a:	00 
    129b:	48 8b 00             	mov    (%rax),%rax
    129e:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    12a5:	2b 9e 
    12a7:	eb 02                	jmp    0x12ab
    12a9:	31 c0                	xor    %eax,%eax
    12ab:	48 85 c0             	test   %rax,%rax
    12ae:	0f 84 c9 01 00 00    	je     0x147d
    12b4:	48 ff 00             	incq   (%rax)
    12b7:	e9 c1 01 00 00       	jmp    0x147d
    12bc:	48 85 ed             	test   %rbp,%rbp
    12bf:	0f 84 b8 01 00 00    	je     0x147d
    12c5:	48 bf 00 f2 17 56 10 	movabs $0xffff8b105617f200,%rdi
    12cc:	8b ff ff 
    12cf:	48 8d b4 24 a0 00 00 	lea    0xa0(%rsp),%rsi
    12d6:	00 
    12d7:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    12dd:	8b 06                	mov    (%rsi),%eax
    12df:	83 f8 10             	cmp    $0x10,%eax
    12e2:	73 0a                	jae    0x12ee
    12e4:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    12eb:	00 
    12ec:	eb 02                	jmp    0x12f0
    12ee:	31 c0                	xor    %eax,%eax
    12f0:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    12f6:	48 85 c0             	test   %rax,%rax
    12f9:	0f 84 21 0f 00 00    	je     0x2220
    12ff:	48 89 6c 24 70       	mov    %rbp,0x70(%rsp)
    1304:	48 89 c5             	mov    %rax,%rbp
    1307:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    130e:	8b ff ff 
    1311:	48 8d b4 24 a4 00 00 	lea    0xa4(%rsp),%rsi
    1318:	00 
    1319:	8b 06                	mov    (%rsi),%eax
    131b:	3d 00 04 00 00       	cmp    $0x400,%eax
    1320:	73 16                	jae    0x1338
    1322:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1329:	00 
    132a:	48 8b 00             	mov    (%rax),%rax
    132d:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1334:	2b 9e 
    1336:	eb 02                	jmp    0x133a
    1338:	31 c0                	xor    %eax,%eax
    133a:	48 85 c0             	test   %rax,%rax
    133d:	0f 84 dd 0e 00 00    	je     0x2220
    1343:	48 ff 00             	incq   (%rax)
    1346:	44 0f b7 64 24 34    	movzwl 0x34(%rsp),%r12d
    134c:	4c 01 60 08          	add    %r12,0x8(%rax)
    1350:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    1355:	48 bf 00 d0 6d 40 86 	movabs $0xffffd286406dd000,%rdi
    135c:	d2 ff ff 
    135f:	b8 01 00 00 00       	mov    $0x1,%eax
    1364:	8b 06                	mov    (%rsi),%eax
    1366:	3d 00 10 00 00       	cmp    $0x1000,%eax
    136b:	73 16                	jae    0x1383
    136d:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1374:	00 
    1375:	48 8b 00             	mov    (%rax),%rax
    1378:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    137f:	2b 9e 
    1381:	eb 02                	jmp    0x1385
    1383:	31 c0                	xor    %eax,%eax
    1385:	48 85 c0             	test   %rax,%rax
    1388:	0f 84 92 0e 00 00    	je     0x2220
    138e:	48 ff 00             	incq   (%rax)
    1391:	4c 01 60 08          	add    %r12,0x8(%rax)
    1395:	8b 44 24 38          	mov    0x38(%rsp),%eax
    1399:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    139e:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
    13a3:	f6 40 10 01          	testb  $0x1,0x10(%rax)
    13a7:	0f 85 7f 03 00 00    	jne    0x172c
    13ad:	44 0f b7 64 24 42    	movzwl 0x42(%rsp),%r12d
    13b3:	b8 2c 00 00 00       	mov    $0x2c,%eax
    13b8:	4c 89 f7             	mov    %r14,%rdi
    13bb:	be ec ff ff ff       	mov    $0xffffffec,%esi
    13c0:	e8 97 d8 75 db       	call   0xffffffffdb75ec5c
    13c5:	85 c0                	test   %eax,%eax
    13c7:	0f 85 83 0a 00 00    	jne    0x1e50
    13cd:	49 8b 06             	mov    (%r14),%rax
    13d0:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    13d4:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    13d8:	48 39 ca             	cmp    %rcx,%rdx
    13db:	0f 87 6f 0a 00 00    	ja     0x1e50
    13e1:	48 8d 50 22          	lea    0x22(%rax),%rdx
    13e5:	48 39 ca             	cmp    %rcx,%rdx
    13e8:	0f 87 62 0a 00 00    	ja     0x1e50
    13ee:	8b 4c 24 38          	mov    0x38(%rsp),%ecx
    13f2:	66 c1 c1 08          	rol    $0x8,%cx
    13f6:	41 31 cc             	xor    %ecx,%r12d
    13f9:	41 c1 e4 10          	shl    $0x10,%r12d
    13fd:	0f b7 4d 04          	movzwl 0x4(%rbp),%ecx
    1401:	66 89 48 04          	mov    %cx,0x4(%rax)
    1405:	8b 4d 00             	mov    0x0(%rbp),%ecx
    1408:	89 08                	mov    %ecx,(%rax)
    140a:	8b 48 14             	mov    0x14(%rax),%ecx
    140d:	89 48 06             	mov    %ecx,0x6(%rax)
    1410:	0f b7 48 18          	movzwl 0x18(%rax),%ecx
    1414:	66 89 48 0a          	mov    %cx,0xa(%rax)
    1418:	66 c7 40 0c 08 00    	movw   $0x8,0xc(%rax)
    141e:	41 8d 8c 24 ac 10 00 	lea    0x10ac(%r12),%ecx
    1425:	00 
    1426:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    142b:	48 8b 74 24 70       	mov    0x70(%rsp),%rsi
    1430:	8b 36                	mov    (%rsi),%esi
    1432:	c6 40 0e 45          	movb   $0x45,0xe(%rax)
    1436:	88 50 0f             	mov    %dl,0xf(%rax)
    1439:	8b 54 24 34          	mov    0x34(%rsp),%edx
    143d:	83 c2 14             	add    $0x14,%edx
    1440:	66 0f 38 f1 50 10    	movbe  %dx,0x10(%rax)
    1446:	66 c1 c2 08          	rol    $0x8,%dx
    144a:	c7 40 12 00 00 00 00 	movl   $0x0,0x12(%rax)
    1451:	89 70 1e             	mov    %esi,0x1e(%rax)
    1454:	89 48 1a             	mov    %ecx,0x1a(%rax)
    1457:	66 c7 40 16 40 04    	movw   $0x440,0x16(%rax)
    145d:	0f b7 48 0e          	movzwl 0xe(%rax),%ecx
    1461:	0f b7 d2             	movzwl %dx,%edx
    1464:	0f b7 78 16          	movzwl 0x16(%rax),%edi
    1468:	48 01 cf             	add    %rcx,%rdi
    146b:	41 c1 ec 10          	shr    $0x10,%r12d
    146f:	49 01 fc             	add    %rdi,%r12
    1472:	0f b7 ce             	movzwl %si,%ecx
    1475:	4c 01 e1             	add    %r12,%rcx
    1478:	e9 53 0f 00 00       	jmp    0x23d0
    147d:	80 7c 24 64 06       	cmpb   $0x6,0x64(%rsp)
    1482:	75 51                	jne    0x14d5
    1484:	c7 04 24 01 02 00 00 	movl   $0x201,(%rsp)
    148b:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    1492:	8b ff ff 
    1495:	48 89 e6             	mov    %rsp,%rsi
    1498:	b8 01 00 00 00       	mov    $0x1,%eax
    149d:	8b 06                	mov    (%rsi),%eax
    149f:	3d 00 04 00 00       	cmp    $0x400,%eax
    14a4:	73 16                	jae    0x14bc
    14a6:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    14ad:	00 
    14ae:	48 8b 00             	mov    (%rax),%rax
    14b1:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    14b8:	2b 9e 
    14ba:	eb 02                	jmp    0x14be
    14bc:	31 c0                	xor    %eax,%eax
    14be:	48 85 c0             	test   %rax,%rax
    14c1:	0f 84 53 0d 00 00    	je     0x221a
    14c7:	31 c9                	xor    %ecx,%ecx
    14c9:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    14ce:	0f 94 c1             	sete   %cl
    14d1:	48 ff 04 c8          	incq   (%rax,%rcx,8)
    14d5:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    14dc:	00 00 
    14de:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    14e5:	00 
    14e6:	c7 44 24 1c 02 02 00 	movl   $0x202,0x1c(%rsp)
    14ed:	00 
    14ee:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    14f5:	8b ff ff 
    14f8:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    14fd:	b8 01 00 00 00       	mov    $0x1,%eax
    1502:	8b 06                	mov    (%rsi),%eax
    1504:	3d 00 04 00 00       	cmp    $0x400,%eax
    1509:	73 16                	jae    0x1521
    150b:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1512:	00 
    1513:	48 8b 00             	mov    (%rax),%rax
    1516:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    151d:	2b 9e 
    151f:	eb 02                	jmp    0x1523
    1521:	31 c0                	xor    %eax,%eax
    1523:	bd 01 00 00 00       	mov    $0x1,%ebp
    1528:	48 85 c0             	test   %rax,%rax
    152b:	74 2f                	je     0x155c
    152d:	49 89 c5             	mov    %rax,%r13
    1530:	b8 05 00 00 00       	mov    $0x5,%eax
    1535:	e8 d2 28 eb da       	call   0xffffffffdaeb3e0c
    153a:	49 89 c4             	mov    %rax,%r12
    153d:	49 2b 45 08          	sub    0x8(%r13),%rax
    1541:	48 3d 01 ca 9a 3b    	cmp    $0x3b9aca01,%rax
    1547:	72 1d                	jb     0x1566
    1549:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    1550:	00 
    1551:	4d 89 65 08          	mov    %r12,0x8(%r13)
    1555:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    155a:	eb 22                	jmp    0x157e
    155c:	45 31 e4             	xor    %r12d,%r12d
    155f:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    1564:	eb 1a                	jmp    0x1580
    1566:	49 8b 45 00          	mov    0x0(%r13),%rax
    156a:	48 ff c0             	inc    %rax
    156d:	49 89 45 00          	mov    %rax,0x0(%r13)
    1571:	48 3d 48 e8 01 00    	cmp    $0x1e848,%rax
    1577:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    157c:	77 02                	ja     0x1580
    157e:	31 ed                	xor    %ebp,%ebp
    1580:	f6 00 08             	testb  $0x8,(%rax)
    1583:	74 1c                	je     0x15a1
    1585:	0f b7 44 24 62       	movzwl 0x62(%rsp),%eax
    158a:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    158f:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
    1596:	00 00 
    1598:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
    159f:	00 00 
    15a1:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
    15a6:	e8 bf 10 00 00       	call   0x266a
    15ab:	8b 74 24 60          	mov    0x60(%rsp),%esi
    15af:	89 c7                	mov    %eax,%edi
    15b1:	e8 93 11 00 00       	call   0x2749
    15b6:	89 c1                	mov    %eax,%ecx
    15b8:	ba 01 00 ff ff       	mov    $0xffff0001,%edx
    15bd:	48 0f af d1          	imul   %rcx,%rdx
    15c1:	48 c1 ea 30          	shr    $0x30,%rdx
    15c5:	89 d1                	mov    %edx,%ecx
    15c7:	c1 e1 10             	shl    $0x10,%ecx
    15ca:	09 d1                	or     %edx,%ecx
    15cc:	29 c8                	sub    %ecx,%eax
    15ce:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
    15d3:	8b 49 04             	mov    0x4(%rcx),%ecx
    15d6:	89 ca                	mov    %ecx,%edx
    15d8:	c1 e2 10             	shl    $0x10,%edx
    15db:	01 ca                	add    %ecx,%edx
    15dd:	01 c2                	add    %eax,%edx
    15df:	89 54 24 24          	mov    %edx,0x24(%rsp)
    15e3:	48 bf 00 90 0d 42 86 	movabs $0xffffd286420d9000,%rdi
    15ea:	d2 ff ff 
    15ed:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    15f2:	b8 01 00 00 00       	mov    $0x1,%eax
    15f7:	8b 06                	mov    (%rsi),%eax
    15f9:	3d 00 02 00 02       	cmp    $0x2000200,%eax
    15fe:	73 0a                	jae    0x160a
    1600:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1607:	00 
    1608:	eb 02                	jmp    0x160c
    160a:	31 c0                	xor    %eax,%eax
    160c:	48 85 c0             	test   %rax,%rax
    160f:	0f 84 05 0c 00 00    	je     0x221a
    1615:	8b 00                	mov    (%rax),%eax
    1617:	89 44 24 24          	mov    %eax,0x24(%rsp)
    161b:	85 c0                	test   %eax,%eax
    161d:	0f 84 6f 0b 00 00    	je     0x2192
    1623:	4d 89 e5             	mov    %r12,%r13
    1626:	89 44 24 68          	mov    %eax,0x68(%rsp)
    162a:	48 bf 00 50 87 40 86 	movabs $0xffffd28640875000,%rdi
    1631:	d2 ff ff 
    1634:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    1639:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    163f:	8b 06                	mov    (%rsi),%eax
    1641:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1646:	73 12                	jae    0x165a
    1648:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    164f:	48 01 f8             	add    %rdi,%rax
    1652:	48 05 30 01 00 00    	add    $0x130,%rax
    1658:	eb 02                	jmp    0x165c
    165a:	31 c0                	xor    %eax,%eax
    165c:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
    1661:	48 85 c0             	test   %rax,%rax
    1664:	0f 84 70 0b 00 00    	je     0x21da
    166a:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    166f:	0f b6 00             	movzbl (%rax),%eax
    1672:	24 02                	and    $0x2,%al
    1674:	d0 e8                	shr    $1,%al
    1676:	40 08 c5             	or     %al,%bpl
    1679:	75 33                	jne    0x16ae
    167b:	f6 44 24 6c 04       	testb  $0x4,0x6c(%rsp)
    1680:	75 2c                	jne    0x16ae
    1682:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    1687:	75 05                	jne    0x168e
    1689:	4c 89 6c 24 08       	mov    %r13,0x8(%rsp)
    168e:	8b 44 24 24          	mov    0x24(%rsp),%eax
    1692:	89 04 24             	mov    %eax,(%rsp)
    1695:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    169a:	48 89 e2             	mov    %rsp,%rdx
    169d:	b8 02 00 00 00       	mov    $0x2,%eax
    16a2:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    16a7:	31 c9                	xor    %ecx,%ecx
    16a9:	e8 5e 23 eb da       	call   0xffffffffdaeb3a0c
    16ae:	c7 04 24 00 00 00 00 	movl   $0x0,(%rsp)
    16b5:	48 bf 00 fc 17 56 10 	movabs $0xffff8b105617fc00,%rdi
    16bc:	8b ff ff 
    16bf:	48 89 e6             	mov    %rsp,%rsi
    16c2:	b8 01 00 00 00       	mov    $0x1,%eax
    16c7:	8b 06                	mov    (%rsi),%eax
    16c9:	83 f8 01             	cmp    $0x1,%eax
    16cc:	73 12                	jae    0x16e0
    16ce:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    16d5:	48 01 f8             	add    %rdi,%rax
    16d8:	48 05 30 01 00 00    	add    $0x130,%rax
    16de:	eb 02                	jmp    0x16e2
    16e0:	31 c0                	xor    %eax,%eax
    16e2:	48 85 c0             	test   %rax,%rax
    16e5:	0f 84 2f 0b 00 00    	je     0x221a
    16eb:	8b 08                	mov    (%rax),%ecx
    16ed:	3b 8c 24 80 00 00 00 	cmp    0x80(%rsp),%ecx
    16f4:	0f 85 e5 00 00 00    	jne    0x17df
    16fa:	8b 48 04             	mov    0x4(%rax),%ecx
    16fd:	3b 8c 24 84 00 00 00 	cmp    0x84(%rsp),%ecx
    1704:	0f 85 d5 00 00 00    	jne    0x17df
    170a:	8b 48 08             	mov    0x8(%rax),%ecx
    170d:	3b 8c 24 88 00 00 00 	cmp    0x88(%rsp),%ecx
    1714:	0f 85 c5 00 00 00    	jne    0x17df
    171a:	8b 48 0c             	mov    0xc(%rax),%ecx
    171d:	3b 8c 24 8c 00 00 00 	cmp    0x8c(%rsp),%ecx
    1724:	0f 94 c1             	sete   %cl
    1727:	e9 b5 00 00 00       	jmp    0x17e1
    172c:	b8 2c 00 00 00       	mov    $0x2c,%eax
    1731:	4c 89 f7             	mov    %r14,%rdi
    1734:	be d8 ff ff ff       	mov    $0xffffffd8,%esi
    1739:	e8 1e d5 75 db       	call   0xffffffffdb75ec5c
    173e:	85 c0                	test   %eax,%eax
    1740:	0f 85 92 0b 00 00    	jne    0x22d8
    1746:	49 8b 06             	mov    (%r14),%rax
    1749:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    174d:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    1751:	48 39 ca             	cmp    %rcx,%rdx
    1754:	0f 87 7e 0b 00 00    	ja     0x22d8
    175a:	48 8d 50 36          	lea    0x36(%rax),%rdx
    175e:	48 39 ca             	cmp    %rcx,%rdx
    1761:	0f 87 71 0b 00 00    	ja     0x22d8
    1767:	0f b7 4d 04          	movzwl 0x4(%rbp),%ecx
    176b:	66 89 48 04          	mov    %cx,0x4(%rax)
    176f:	8b 4d 00             	mov    0x0(%rbp),%ecx
    1772:	89 08                	mov    %ecx,(%rax)
    1774:	8b 48 28             	mov    0x28(%rax),%ecx
    1777:	89 48 06             	mov    %ecx,0x6(%rax)
    177a:	0f b7 48 2c          	movzwl 0x2c(%rax),%ecx
    177e:	66 89 48 0a          	mov    %cx,0xa(%rax)
    1782:	66 c7 40 0c 86 dd    	movw   $0xdd86,0xc(%rax)
    1788:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    178d:	33 4c 24 4c          	xor    0x4c(%rsp),%ecx
    1791:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    1796:	66 c7 40 10 00 00    	movw   $0x0,0x10(%rax)
    179c:	89 d6                	mov    %edx,%esi
    179e:	40 c0 ee 04          	shr    $0x4,%sil
    17a2:	40 80 ce 60          	or     $0x60,%sil
    17a6:	40 88 70 0e          	mov    %sil,0xe(%rax)
    17aa:	c0 e2 04             	shl    $0x4,%dl
    17ad:	88 50 0f             	mov    %dl,0xf(%rax)
    17b0:	66 c7 40 14 29 40    	movw   $0x4029,0x14(%rax)
    17b6:	8b 54 24 34          	mov    0x34(%rsp),%edx
    17ba:	83 c2 28             	add    $0x28,%edx
    17bd:	66 0f 38 f1 50 12    	movbe  %dx,0x12(%rax)
    17c3:	48 c7 40 16 01 00 00 	movq   $0x1,0x16(%rax)
    17ca:	00 
    17cb:	c7 40 1e 00 00 00 00 	movl   $0x0,0x1e(%rax)
    17d2:	89 48 22             	mov    %ecx,0x22(%rax)
    17d5:	48 8b 54 24 70       	mov    0x70(%rsp),%rdx
    17da:	e9 f6 0c 00 00       	jmp    0x24d5
    17df:	31 c9                	xor    %ecx,%ecx
    17e1:	0f b7 70 10          	movzwl 0x10(%rax),%esi
    17e5:	0f b7 bc 24 90 00 00 	movzwl 0x90(%rsp),%edi
    17ec:	00 
    17ed:	0f b6 94 24 92 00 00 	movzbl 0x92(%rsp),%edx
    17f4:	00 
    17f5:	88 50 12             	mov    %dl,0x12(%rax)
    17f8:	84 c9                	test   %cl,%cl
    17fa:	74 51                	je     0x184d
    17fc:	66 39 fe             	cmp    %di,%si
    17ff:	75 4c                	jne    0x184d
    1801:	84 d2                	test   %dl,%dl
    1803:	74 48                	je     0x184d
    1805:	8b 44 24 68          	mov    0x68(%rsp),%eax
    1809:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
    180d:	48 bf 00 d0 6e 40 86 	movabs $0xffffd286406ed000,%rdi
    1814:	d2 ff ff 
    1817:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    181c:	b8 01 00 00 00       	mov    $0x1,%eax
    1821:	8b 06                	mov    (%rsi),%eax
    1823:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1828:	73 16                	jae    0x1840
    182a:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1831:	00 
    1832:	48 8b 00             	mov    (%rax),%rax
    1835:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    183c:	2b 9e 
    183e:	eb 02                	jmp    0x1842
    1840:	31 c0                	xor    %eax,%eax
    1842:	48 85 c0             	test   %rax,%rax
    1845:	0f 84 cf 09 00 00    	je     0x221a
    184b:	ff 00                	incl   (%rax)
    184d:	48 8b 84 24 b0 00 00 	mov    0xb0(%rsp),%rax
    1854:	00 
    1855:	48 ff 40 08          	incq   0x8(%rax)
    1859:	48 8b 6c 24 70       	mov    0x70(%rsp),%rbp
    185e:	e9 62 fa ff ff       	jmp    0x12c5
    1863:	48 83 c0 40          	add    $0x40,%rax
    1867:	eb 0a                	jmp    0x1873
    1869:	48 83 c0 48          	add    $0x48,%rax
    186d:	eb 04                	jmp    0x1873
    186f:	48 83 c0 30          	add    $0x30,%rax
    1873:	48 ff 00             	incq   (%rax)
    1876:	44 89 64 24 24       	mov    %r12d,0x24(%rsp)
    187b:	48 bf 00 c0 0d 52 86 	movabs $0xffffd286520dc000,%rdi
    1882:	d2 ff ff 
    1885:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    188a:	b8 01 00 00 00       	mov    $0x1,%eax
    188f:	8b 06                	mov    (%rsi),%eax
    1891:	3d fe ff ff 00       	cmp    $0xfffffe,%eax
    1896:	73 0a                	jae    0x18a2
    1898:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    189f:	00 
    18a0:	eb 02                	jmp    0x18a4
    18a2:	31 c0                	xor    %eax,%eax
    18a4:	48 85 c0             	test   %rax,%rax
    18a7:	74 75                	je     0x191e
    18a9:	8b 00                	mov    (%rax),%eax
    18ab:	89 44 24 24          	mov    %eax,0x24(%rsp)
    18af:	85 c0                	test   %eax,%eax
    18b1:	74 6b                	je     0x191e
    18b3:	89 44 24 68          	mov    %eax,0x68(%rsp)
    18b7:	48 bf 00 50 87 40 86 	movabs $0xffffd28640875000,%rdi
    18be:	d2 ff ff 
    18c1:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    18c6:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    18cc:	8b 06                	mov    (%rsi),%eax
    18ce:	3d 00 10 00 00       	cmp    $0x1000,%eax
    18d3:	73 12                	jae    0x18e7
    18d5:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    18dc:	48 01 f8             	add    %rdi,%rax
    18df:	48 05 30 01 00 00    	add    $0x130,%rax
    18e5:	eb 02                	jmp    0x18e9
    18e7:	31 c0                	xor    %eax,%eax
    18e9:	48 85 c0             	test   %rax,%rax
    18ec:	74 59                	je     0x1947
    18ee:	49 89 c5             	mov    %rax,%r13
    18f1:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    18f6:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    18fb:	e8 dc 20 eb da       	call   0xffffffffdaeb39dc
    1900:	48 85 c0             	test   %rax,%rax
    1903:	0f 84 b2 00 00 00    	je     0x19bb
    1909:	8b 4c 24 68          	mov    0x68(%rsp),%ecx
    190d:	39 08                	cmp    %ecx,(%rax)
    190f:	0f 85 1d 01 00 00    	jne    0x1a32
    1915:	48 ff 45 50          	incq   0x50(%rbp)
    1919:	e9 22 0c 00 00       	jmp    0x2540
    191e:	48 ff 45 10          	incq   0x10(%rbp)
    1922:	4c 89 65 18          	mov    %r12,0x18(%rbp)
    1926:	48 ff 45 00          	incq   0x0(%rbp)
    192a:	e9 c6 f7 ff ff       	jmp    0x10f5
    192f:	41 80 7c 24 0d 07    	cmpb   $0x7,0xd(%r12)
    1935:	0f 86 22 02 00 00    	jbe    0x1b5d
    193b:	49 83 c4 0e          	add    $0xe,%r12
    193f:	4c 89 e1             	mov    %r12,%rcx
    1942:	e9 5c f4 ff ff       	jmp    0xda3
    1947:	48 ff 45 28          	incq   0x28(%rbp)
    194b:	e9 ca 08 00 00       	jmp    0x221a
    1950:	0f b6 71 01          	movzbl 0x1(%rcx),%esi
    1954:	c1 e6 10             	shl    $0x10,%esi
    1957:	0f b6 51 02          	movzbl 0x2(%rcx),%edx
    195b:	c1 e2 08             	shl    $0x8,%edx
    195e:	09 f2                	or     %esi,%edx
    1960:	0f b6 49 03          	movzbl 0x3(%rcx),%ecx
    1964:	eb 1d                	jmp    0x1983
    1966:	0f b6 51 01          	movzbl 0x1(%rcx),%edx
    196a:	c1 e2 18             	shl    $0x18,%edx
    196d:	0f b6 71 02          	movzbl 0x2(%rcx),%esi
    1971:	c1 e6 10             	shl    $0x10,%esi
    1974:	09 d6                	or     %edx,%esi
    1976:	0f b6 51 03          	movzbl 0x3(%rcx),%edx
    197a:	c1 e2 08             	shl    $0x8,%edx
    197d:	09 f2                	or     %esi,%edx
    197f:	0f b6 49 04          	movzbl 0x4(%rcx),%ecx
    1983:	44 0f b6 e1          	movzbl %cl,%r12d
    1987:	49 09 d4             	or     %rdx,%r12
    198a:	45 85 e4             	test   %r12d,%r12d
    198d:	0f 8e ca 01 00 00    	jle    0x1b5d
    1993:	48 83 f8 03          	cmp    $0x3,%rax
    1997:	0f 84 f0 00 00 00    	je     0x1a8d
    199d:	83 f8 02             	cmp    $0x2,%eax
    19a0:	0f 84 de 00 00 00    	je     0x1a84
    19a6:	83 f8 01             	cmp    $0x1,%eax
    19a9:	0f 85 e7 00 00 00    	jne    0x1a96
    19af:	4c 89 e8             	mov    %r13,%rax
    19b2:	48 83 c0 38          	add    $0x38,%rax
    19b6:	e9 e2 00 00 00       	jmp    0x1a9d
    19bb:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    19c2:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    19c9:	8b ff ff 
    19cc:	48 89 e6             	mov    %rsp,%rsi
    19cf:	b8 01 00 00 00       	mov    $0x1,%eax
    19d4:	8b 06                	mov    (%rsi),%eax
    19d6:	3d 00 04 00 00       	cmp    $0x400,%eax
    19db:	73 16                	jae    0x19f3
    19dd:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    19e4:	00 
    19e5:	48 8b 00             	mov    (%rax),%rax
    19e8:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    19ef:	2b 9e 
    19f1:	eb 02                	jmp    0x19f5
    19f3:	31 c0                	xor    %eax,%eax
    19f5:	48 85 c0             	test   %rax,%rax
    19f8:	0f 84 3e 0b 00 00    	je     0x253c
    19fe:	49 89 c4             	mov    %rax,%r12
    1a01:	b8 05 00 00 00       	mov    $0x5,%eax
    1a06:	e8 01 24 eb da       	call   0xffffffffdaeb3e0c
    1a0b:	48 89 c1             	mov    %rax,%rcx
    1a0e:	49 2b 4c 24 08       	sub    0x8(%r12),%rcx
    1a13:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    1a1a:	0f 82 d8 0a 00 00    	jb     0x24f8
    1a20:	49 c7 04 24 01 00 00 	movq   $0x1,(%r12)
    1a27:	00 
    1a28:	49 89 44 24 08       	mov    %rax,0x8(%r12)
    1a2d:	e9 d9 0a 00 00       	jmp    0x250b
    1a32:	89 08                	mov    %ecx,(%rax)
    1a34:	48 ff 45 58          	incq   0x58(%rbp)
    1a38:	8b 44 24 70          	mov    0x70(%rsp),%eax
    1a3c:	89 04 24             	mov    %eax,(%rsp)
    1a3f:	48 bf 00 c0 2a 83 0f 	movabs $0xffff8b0f832ac000,%rdi
    1a46:	8b ff ff 
    1a49:	48 89 e6             	mov    %rsp,%rsi
    1a4c:	b8 01 00 00 00       	mov    $0x1,%eax
    1a51:	8b 06                	mov    (%rsi),%eax
    1a53:	3d 00 02 00 00       	cmp    $0x200,%eax
    1a58:	73 16                	jae    0x1a70
    1a5a:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1a61:	00 
    1a62:	48 8b 00             	mov    (%rax),%rax
    1a65:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1a6c:	2b 9e 
    1a6e:	eb 02                	jmp    0x1a72
    1a70:	31 c0                	xor    %eax,%eax
    1a72:	48 85 c0             	test   %rax,%rax
    1a75:	0f 84 c5 0a 00 00    	je     0x2540
    1a7b:	48 ff 40 08          	incq   0x8(%rax)
    1a7f:	e9 bc 0a 00 00       	jmp    0x2540
    1a84:	4c 89 e8             	mov    %r13,%rax
    1a87:	48 83 c0 40          	add    $0x40,%rax
    1a8b:	eb 10                	jmp    0x1a9d
    1a8d:	4c 89 e8             	mov    %r13,%rax
    1a90:	48 83 c0 48          	add    $0x48,%rax
    1a94:	eb 07                	jmp    0x1a9d
    1a96:	4c 89 e8             	mov    %r13,%rax
    1a99:	48 83 c0 30          	add    $0x30,%rax
    1a9d:	48 ff 00             	incq   (%rax)
    1aa0:	44 89 64 24 24       	mov    %r12d,0x24(%rsp)
    1aa5:	48 bf 00 c0 0d 52 86 	movabs $0xffffd286520dc000,%rdi
    1aac:	d2 ff ff 
    1aaf:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    1ab4:	b8 01 00 00 00       	mov    $0x1,%eax
    1ab9:	8b 06                	mov    (%rsi),%eax
    1abb:	3d fe ff ff 00       	cmp    $0xfffffe,%eax
    1ac0:	73 0a                	jae    0x1acc
    1ac2:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1ac9:	00 
    1aca:	eb 02                	jmp    0x1ace
    1acc:	31 c0                	xor    %eax,%eax
    1ace:	48 85 c0             	test   %rax,%rax
    1ad1:	0f 84 7e 00 00 00    	je     0x1b55
    1ad7:	8b 00                	mov    (%rax),%eax
    1ad9:	89 44 24 24          	mov    %eax,0x24(%rsp)
    1add:	85 c0                	test   %eax,%eax
    1adf:	74 74                	je     0x1b55
    1ae1:	89 44 24 68          	mov    %eax,0x68(%rsp)
    1ae5:	48 bf 00 50 87 40 86 	movabs $0xffffd28640875000,%rdi
    1aec:	d2 ff ff 
    1aef:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    1af4:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    1afa:	8b 06                	mov    (%rsi),%eax
    1afc:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1b01:	73 12                	jae    0x1b15
    1b03:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    1b0a:	48 01 f8             	add    %rdi,%rax
    1b0d:	48 05 30 01 00 00    	add    $0x130,%rax
    1b13:	eb 02                	jmp    0x1b17
    1b15:	31 c0                	xor    %eax,%eax
    1b17:	48 89 84 24 a8 00 00 	mov    %rax,0xa8(%rsp)
    1b1e:	00 
    1b1f:	48 85 c0             	test   %rax,%rax
    1b22:	0f 84 c7 09 00 00    	je     0x24ef
    1b28:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    1b2d:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    1b32:	e8 a5 1e eb da       	call   0xffffffffdaeb39dc
    1b37:	48 85 c0             	test   %rax,%rax
    1b3a:	0f 84 15 0a 00 00    	je     0x2555
    1b40:	8b 4c 24 68          	mov    0x68(%rsp),%ecx
    1b44:	39 08                	cmp    %ecx,(%rax)
    1b46:	0f 85 79 0a 00 00    	jne    0x25c5
    1b4c:	49 ff 45 50          	incq   0x50(%r13)
    1b50:	e9 03 0b 00 00       	jmp    0x2658
    1b55:	49 ff 45 10          	incq   0x10(%r13)
    1b59:	4d 89 65 18          	mov    %r12,0x18(%r13)
    1b5d:	49 ff 45 00          	incq   0x0(%r13)
    1b61:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    1b66:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    1b6b:	89 4c 24 38          	mov    %ecx,0x38(%rsp)
    1b6f:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    1b74:	75 4e                	jne    0x1bc4
    1b76:	41 f6 45 00 02       	testb  $0x2,0x0(%r13)
    1b7b:	75 4b                	jne    0x1bc8
    1b7d:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    1b82:	b8 01 00 00 00       	mov    $0x1,%eax
    1b87:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    1b8c:	e8 4b 1e eb da       	call   0xffffffffdaeb39dc
    1b91:	48 85 c0             	test   %rax,%rax
    1b94:	74 2a                	je     0x1bc0
    1b96:	49 89 c5             	mov    %rax,%r13
    1b99:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    1b9e:	75 35                	jne    0x1bd5
    1ba0:	b8 05 00 00 00       	mov    $0x5,%eax
    1ba5:	e8 62 22 eb da       	call   0xffffffffdaeb3e0c
    1baa:	48 89 c1             	mov    %rax,%rcx
    1bad:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    1bb1:	48 ba 00 ac 23 fc 06 	movabs $0x6fc23ac00,%rdx
    1bb8:	00 00 00 
    1bbb:	48 39 d1             	cmp    %rdx,%rcx
    1bbe:	76 11                	jbe    0x1bd1
    1bc0:	31 c0                	xor    %eax,%eax
    1bc2:	eb 4b                	jmp    0x1c0f
    1bc4:	31 ed                	xor    %ebp,%ebp
    1bc6:	eb 4f                	jmp    0x1c17
    1bc8:	31 ed                	xor    %ebp,%ebp
    1bca:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    1bcf:	eb 46                	jmp    0x1c17
    1bd1:	49 89 45 08          	mov    %rax,0x8(%r13)
    1bd5:	41 8b 45 00          	mov    0x0(%r13),%eax
    1bd9:	89 04 24             	mov    %eax,(%rsp)
    1bdc:	89 44 24 68          	mov    %eax,0x68(%rsp)
    1be0:	48 bf 00 50 87 40 86 	movabs $0xffffd28640875000,%rdi
    1be7:	d2 ff ff 
    1bea:	48 89 e6             	mov    %rsp,%rsi
    1bed:	b8 01 00 00 00       	mov    $0x1,%eax
    1bf2:	8b 06                	mov    (%rsi),%eax
    1bf4:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1bf9:	73 12                	jae    0x1c0d
    1bfb:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    1c02:	48 01 f8             	add    %rdi,%rax
    1c05:	48 05 30 01 00 00    	add    $0x130,%rax
    1c0b:	eb 02                	jmp    0x1c0f
    1c0d:	31 c0                	xor    %eax,%eax
    1c0f:	4c 8b 6c 24 28       	mov    0x28(%rsp),%r13
    1c14:	48 89 c5             	mov    %rax,%rbp
    1c17:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    1c1c:	0f 85 0f 01 00 00    	jne    0x1d31
    1c22:	41 f6 45 01 02       	testb  $0x2,0x1(%r13)
    1c27:	0f 84 04 01 00 00    	je     0x1d31
    1c2d:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    1c34:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    1c3b:	8b ff ff 
    1c3e:	48 89 e6             	mov    %rsp,%rsi
    1c41:	b8 01 00 00 00       	mov    $0x1,%eax
    1c46:	8b 06                	mov    (%rsi),%eax
    1c48:	3d 00 04 00 00       	cmp    $0x400,%eax
    1c4d:	73 16                	jae    0x1c65
    1c4f:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1c56:	00 
    1c57:	48 8b 00             	mov    (%rax),%rax
    1c5a:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1c61:	2b 9e 
    1c63:	eb 02                	jmp    0x1c67
    1c65:	31 c0                	xor    %eax,%eax
    1c67:	48 85 c0             	test   %rax,%rax
    1c6a:	0f 84 c1 00 00 00    	je     0x1d31
    1c70:	49 89 c5             	mov    %rax,%r13
    1c73:	b8 05 00 00 00       	mov    $0x5,%eax
    1c78:	e8 8f 21 eb da       	call   0xffffffffdaeb3e0c
    1c7d:	48 89 c1             	mov    %rax,%rcx
    1c80:	49 2b 4d 08          	sub    0x8(%r13),%rcx
    1c84:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    1c8b:	72 0e                	jb     0x1c9b
    1c8d:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    1c94:	00 
    1c95:	49 89 45 08          	mov    %rax,0x8(%r13)
    1c99:	eb 17                	jmp    0x1cb2
    1c9b:	49 8b 45 00          	mov    0x0(%r13),%rax
    1c9f:	48 ff c0             	inc    %rax
    1ca2:	49 89 45 00          	mov    %rax,0x0(%r13)
    1ca6:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    1cac:	0f 83 7f 00 00 00    	jae    0x1d31
    1cb2:	48 bf 00 24 01 56 10 	movabs $0xffff8b1056012400,%rdi
    1cb9:	8b ff ff 
    1cbc:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
    1cc3:	00 
    1cc4:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    1cca:	e8 0d 1d eb da       	call   0xffffffffdaeb39dc
    1ccf:	48 85 c0             	test   %rax,%rax
    1cd2:	74 5d                	je     0x1d31
    1cd4:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    1cd9:	48 89 c7             	mov    %rax,%rdi
    1cdc:	e8 fb 1c eb da       	call   0xffffffffdaeb39dc
    1ce1:	48 85 c0             	test   %rax,%rax
    1ce4:	74 4b                	je     0x1d31
    1ce6:	c7 04 24 0f 02 00 00 	movl   $0x20f,(%rsp)
    1ced:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    1cf4:	8b ff ff 
    1cf7:	48 89 e6             	mov    %rsp,%rsi
    1cfa:	b8 01 00 00 00       	mov    $0x1,%eax
    1cff:	8b 06                	mov    (%rsi),%eax
    1d01:	3d 00 04 00 00       	cmp    $0x400,%eax
    1d06:	73 16                	jae    0x1d1e
    1d08:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1d0f:	00 
    1d10:	48 8b 00             	mov    (%rax),%rax
    1d13:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1d1a:	2b 9e 
    1d1c:	eb 02                	jmp    0x1d20
    1d1e:	31 c0                	xor    %eax,%eax
    1d20:	48 85 c0             	test   %rax,%rax
    1d23:	0f 84 72 01 00 00    	je     0x1e9b
    1d29:	48 ff 00             	incq   (%rax)
    1d2c:	e9 6a 01 00 00       	jmp    0x1e9b
    1d31:	48 85 ed             	test   %rbp,%rbp
    1d34:	0f 84 61 01 00 00    	je     0x1e9b
    1d3a:	48 89 ac 24 a8 00 00 	mov    %rbp,0xa8(%rsp)
    1d41:	00 
    1d42:	48 bf 00 f2 17 56 10 	movabs $0xffff8b105617f200,%rdi
    1d49:	8b ff ff 
    1d4c:	48 8d b4 24 a0 00 00 	lea    0xa0(%rsp),%rsi
    1d53:	00 
    1d54:	bd 01 00 00 00       	mov    $0x1,%ebp
    1d59:	8b 06                	mov    (%rsi),%eax
    1d5b:	83 f8 10             	cmp    $0x10,%eax
    1d5e:	73 0a                	jae    0x1d6a
    1d60:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1d67:	00 
    1d68:	eb 02                	jmp    0x1d6c
    1d6a:	31 c0                	xor    %eax,%eax
    1d6c:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    1d72:	48 85 c0             	test   %rax,%rax
    1d75:	0f 84 a5 04 00 00    	je     0x2220
    1d7b:	49 89 c4             	mov    %rax,%r12
    1d7e:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    1d85:	8b ff ff 
    1d88:	48 8d b4 24 a4 00 00 	lea    0xa4(%rsp),%rsi
    1d8f:	00 
    1d90:	8b 06                	mov    (%rsi),%eax
    1d92:	3d 00 04 00 00       	cmp    $0x400,%eax
    1d97:	73 16                	jae    0x1daf
    1d99:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1da0:	00 
    1da1:	48 8b 00             	mov    (%rax),%rax
    1da4:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1dab:	2b 9e 
    1dad:	eb 02                	jmp    0x1db1
    1daf:	31 c0                	xor    %eax,%eax
    1db1:	48 85 c0             	test   %rax,%rax
    1db4:	0f 84 66 04 00 00    	je     0x2220
    1dba:	0f b7 4c 24 34       	movzwl 0x34(%rsp),%ecx
    1dbf:	66 c1 c1 08          	rol    $0x8,%cx
    1dc3:	48 ff 00             	incq   (%rax)
    1dc6:	89 4c 24 28          	mov    %ecx,0x28(%rsp)
    1dca:	0f b7 e9             	movzwl %cx,%ebp
    1dcd:	48 01 68 08          	add    %rbp,0x8(%rax)
    1dd1:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
    1dd6:	48 bf 00 d0 6d 40 86 	movabs $0xffffd286406dd000,%rdi
    1ddd:	d2 ff ff 
    1de0:	b8 01 00 00 00       	mov    $0x1,%eax
    1de5:	8b 06                	mov    (%rsi),%eax
    1de7:	3d 00 10 00 00       	cmp    $0x1000,%eax
    1dec:	73 16                	jae    0x1e04
    1dee:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1df5:	00 
    1df6:	48 8b 00             	mov    (%rax),%rax
    1df9:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1e00:	2b 9e 
    1e02:	eb 02                	jmp    0x1e06
    1e04:	31 c0                	xor    %eax,%eax
    1e06:	48 85 c0             	test   %rax,%rax
    1e09:	0f 84 11 04 00 00    	je     0x2220
    1e0f:	48 ff 00             	incq   (%rax)
    1e12:	48 01 68 08          	add    %rbp,0x8(%rax)
    1e16:	8b 44 24 38          	mov    0x38(%rsp),%eax
    1e1a:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    1e1f:	48 8b 84 24 a8 00 00 	mov    0xa8(%rsp),%rax
    1e26:	00 
    1e27:	f6 40 10 01          	testb  $0x1,0x10(%rax)
    1e2b:	0f 85 8d 04 00 00    	jne    0x22be
    1e31:	0f b7 6c 24 42       	movzwl 0x42(%rsp),%ebp
    1e36:	b8 2c 00 00 00       	mov    $0x2c,%eax
    1e3b:	4c 89 f7             	mov    %r14,%rdi
    1e3e:	be ec ff ff ff       	mov    $0xffffffec,%esi
    1e43:	e8 14 ce 75 db       	call   0xffffffffdb75ec5c
    1e48:	85 c0                	test   %eax,%eax
    1e4a:	0f 84 d4 04 00 00    	je     0x2324
    1e50:	c7 04 24 07 02 00 00 	movl   $0x207,(%rsp)
    1e57:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    1e5e:	8b ff ff 
    1e61:	48 89 e6             	mov    %rsp,%rsi
    1e64:	b8 01 00 00 00       	mov    $0x1,%eax
    1e69:	8b 06                	mov    (%rsi),%eax
    1e6b:	3d 00 04 00 00       	cmp    $0x400,%eax
    1e70:	73 16                	jae    0x1e88
    1e72:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1e79:	00 
    1e7a:	48 8b 00             	mov    (%rax),%rax
    1e7d:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1e84:	2b 9e 
    1e86:	eb 02                	jmp    0x1e8a
    1e88:	31 c0                	xor    %eax,%eax
    1e8a:	48 85 c0             	test   %rax,%rax
    1e8d:	0f 84 8d 03 00 00    	je     0x2220
    1e93:	48 ff 00             	incq   (%rax)
    1e96:	e9 85 03 00 00       	jmp    0x2220
    1e9b:	80 7c 24 64 06       	cmpb   $0x6,0x64(%rsp)
    1ea0:	75 51                	jne    0x1ef3
    1ea2:	c7 04 24 01 02 00 00 	movl   $0x201,(%rsp)
    1ea9:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    1eb0:	8b ff ff 
    1eb3:	48 89 e6             	mov    %rsp,%rsi
    1eb6:	b8 01 00 00 00       	mov    $0x1,%eax
    1ebb:	8b 06                	mov    (%rsi),%eax
    1ebd:	3d 00 04 00 00       	cmp    $0x400,%eax
    1ec2:	73 16                	jae    0x1eda
    1ec4:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1ecb:	00 
    1ecc:	48 8b 00             	mov    (%rax),%rax
    1ecf:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1ed6:	2b 9e 
    1ed8:	eb 02                	jmp    0x1edc
    1eda:	31 c0                	xor    %eax,%eax
    1edc:	48 85 c0             	test   %rax,%rax
    1edf:	0f 84 35 03 00 00    	je     0x221a
    1ee5:	31 c9                	xor    %ecx,%ecx
    1ee7:	f6 44 24 6c 02       	testb  $0x2,0x6c(%rsp)
    1eec:	0f 94 c1             	sete   %cl
    1eef:	48 ff 04 c8          	incq   (%rax,%rcx,8)
    1ef3:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    1efa:	00 00 
    1efc:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    1f03:	00 
    1f04:	c7 44 24 1c 02 02 00 	movl   $0x202,0x1c(%rsp)
    1f0b:	00 
    1f0c:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    1f13:	8b ff ff 
    1f16:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    1f1b:	b8 01 00 00 00       	mov    $0x1,%eax
    1f20:	8b 06                	mov    (%rsi),%eax
    1f22:	3d 00 04 00 00       	cmp    $0x400,%eax
    1f27:	73 16                	jae    0x1f3f
    1f29:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    1f30:	00 
    1f31:	48 8b 00             	mov    (%rax),%rax
    1f34:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    1f3b:	2b 9e 
    1f3d:	eb 02                	jmp    0x1f41
    1f3f:	31 c0                	xor    %eax,%eax
    1f41:	bd 01 00 00 00       	mov    $0x1,%ebp
    1f46:	48 85 c0             	test   %rax,%rax
    1f49:	74 34                	je     0x1f7f
    1f4b:	49 89 c5             	mov    %rax,%r13
    1f4e:	b8 05 00 00 00       	mov    $0x5,%eax
    1f53:	e8 b4 1e eb da       	call   0xffffffffdaeb3e0c
    1f58:	48 89 c1             	mov    %rax,%rcx
    1f5b:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
    1f60:	49 2b 45 08          	sub    0x8(%r13),%rax
    1f64:	48 3d 01 ca 9a 3b    	cmp    $0x3b9aca01,%rax
    1f6a:	72 1c                	jb     0x1f88
    1f6c:	49 c7 45 00 01 00 00 	movq   $0x1,0x0(%r13)
    1f73:	00 
    1f74:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
    1f79:	49 89 45 08          	mov    %rax,0x8(%r13)
    1f7d:	eb 1c                	jmp    0x1f9b
    1f7f:	31 c0                	xor    %eax,%eax
    1f81:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
    1f86:	eb 15                	jmp    0x1f9d
    1f88:	49 8b 45 00          	mov    0x0(%r13),%rax
    1f8c:	48 ff c0             	inc    %rax
    1f8f:	49 89 45 00          	mov    %rax,0x0(%r13)
    1f93:	48 3d 48 e8 01 00    	cmp    $0x1e848,%rax
    1f99:	77 02                	ja     0x1f9d
    1f9b:	31 ed                	xor    %ebp,%ebp
    1f9d:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    1fa2:	f6 00 08             	testb  $0x8,(%rax)
    1fa5:	75 06                	jne    0x1fad
    1fa7:	8b 7c 24 40          	mov    0x40(%rsp),%edi
    1fab:	eb 1e                	jmp    0x1fcb
    1fad:	0f b7 44 24 62       	movzwl 0x62(%rsp),%eax
    1fb2:	66 89 44 24 60       	mov    %ax,0x60(%rsp)
    1fb7:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
    1fbe:	00 00 
    1fc0:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
    1fc7:	00 00 
    1fc9:	31 ff                	xor    %edi,%edi
    1fcb:	8b 74 24 60          	mov    0x60(%rsp),%esi
    1fcf:	e8 75 07 00 00       	call   0x2749
    1fd4:	89 c1                	mov    %eax,%ecx
    1fd6:	ba 01 00 ff ff       	mov    $0xffff0001,%edx
    1fdb:	48 0f af d1          	imul   %rcx,%rdx
    1fdf:	48 c1 ea 30          	shr    $0x30,%rdx
    1fe3:	89 d1                	mov    %edx,%ecx
    1fe5:	c1 e1 10             	shl    $0x10,%ecx
    1fe8:	09 d1                	or     %edx,%ecx
    1fea:	29 c8                	sub    %ecx,%eax
    1fec:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
    1ff1:	8b 49 04             	mov    0x4(%rcx),%ecx
    1ff4:	89 ca                	mov    %ecx,%edx
    1ff6:	c1 e2 10             	shl    $0x10,%edx
    1ff9:	01 ca                	add    %ecx,%edx
    1ffb:	01 c2                	add    %eax,%edx
    1ffd:	89 54 24 24          	mov    %edx,0x24(%rsp)
    2001:	48 bf 00 90 0d 42 86 	movabs $0xffffd286420d9000,%rdi
    2008:	d2 ff ff 
    200b:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    2010:	b8 01 00 00 00       	mov    $0x1,%eax
    2015:	8b 06                	mov    (%rsi),%eax
    2017:	3d 00 02 00 02       	cmp    $0x2000200,%eax
    201c:	73 0a                	jae    0x2028
    201e:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    2025:	00 
    2026:	eb 02                	jmp    0x202a
    2028:	31 c0                	xor    %eax,%eax
    202a:	48 85 c0             	test   %rax,%rax
    202d:	0f 84 e7 01 00 00    	je     0x221a
    2033:	8b 00                	mov    (%rax),%eax
    2035:	89 44 24 24          	mov    %eax,0x24(%rsp)
    2039:	85 c0                	test   %eax,%eax
    203b:	0f 84 51 01 00 00    	je     0x2192
    2041:	89 44 24 68          	mov    %eax,0x68(%rsp)
    2045:	48 bf 00 50 87 40 86 	movabs $0xffffd28640875000,%rdi
    204c:	d2 ff ff 
    204f:	48 8d 74 24 24       	lea    0x24(%rsp),%rsi
    2054:	41 bc 01 00 00 00    	mov    $0x1,%r12d
    205a:	8b 06                	mov    (%rsi),%eax
    205c:	3d 00 10 00 00       	cmp    $0x1000,%eax
    2061:	73 12                	jae    0x2075
    2063:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    206a:	48 01 f8             	add    %rdi,%rax
    206d:	48 05 30 01 00 00    	add    $0x130,%rax
    2073:	eb 02                	jmp    0x2077
    2075:	31 c0                	xor    %eax,%eax
    2077:	48 89 84 24 a8 00 00 	mov    %rax,0xa8(%rsp)
    207e:	00 
    207f:	48 85 c0             	test   %rax,%rax
    2082:	0f 84 52 01 00 00    	je     0x21da
    2088:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
    208d:	0f b6 00             	movzbl (%rax),%eax
    2090:	24 02                	and    $0x2,%al
    2092:	d0 e8                	shr    $1,%al
    2094:	40 08 c5             	or     %al,%bpl
    2097:	75 38                	jne    0x20d1
    2099:	f6 44 24 6c 04       	testb  $0x4,0x6c(%rsp)
    209e:	75 31                	jne    0x20d1
    20a0:	80 7c 24 64 11       	cmpb   $0x11,0x64(%rsp)
    20a5:	75 0a                	jne    0x20b1
    20a7:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
    20ac:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
    20b1:	8b 44 24 24          	mov    0x24(%rsp),%eax
    20b5:	89 04 24             	mov    %eax,(%rsp)
    20b8:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    20bd:	48 89 e2             	mov    %rsp,%rdx
    20c0:	b8 02 00 00 00       	mov    $0x2,%eax
    20c5:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    20ca:	31 c9                	xor    %ecx,%ecx
    20cc:	e8 3b 19 eb da       	call   0xffffffffdaeb3a0c
    20d1:	c7 04 24 00 00 00 00 	movl   $0x0,(%rsp)
    20d8:	48 bf 00 fc 17 56 10 	movabs $0xffff8b105617fc00,%rdi
    20df:	8b ff ff 
    20e2:	48 89 e6             	mov    %rsp,%rsi
    20e5:	b8 01 00 00 00       	mov    $0x1,%eax
    20ea:	8b 06                	mov    (%rsi),%eax
    20ec:	83 f8 01             	cmp    $0x1,%eax
    20ef:	73 12                	jae    0x2103
    20f1:	48 69 c0 18 00 00 00 	imul   $0x18,%rax,%rax
    20f8:	48 01 f8             	add    %rdi,%rax
    20fb:	48 05 30 01 00 00    	add    $0x130,%rax
    2101:	eb 02                	jmp    0x2105
    2103:	31 c0                	xor    %eax,%eax
    2105:	48 85 c0             	test   %rax,%rax
    2108:	0f 84 0c 01 00 00    	je     0x221a
    210e:	8b 38                	mov    (%rax),%edi
    2110:	0f b7 50 10          	movzwl 0x10(%rax),%edx
    2114:	0f b7 b4 24 90 00 00 	movzwl 0x90(%rsp),%esi
    211b:	00 
    211c:	0f b6 8c 24 92 00 00 	movzbl 0x92(%rsp),%ecx
    2123:	00 
    2124:	3b bc 24 80 00 00 00 	cmp    0x80(%rsp),%edi
    212b:	88 48 12             	mov    %cl,0x12(%rax)
    212e:	75 51                	jne    0x2181
    2130:	66 39 f2             	cmp    %si,%dx
    2133:	75 4c                	jne    0x2181
    2135:	84 c9                	test   %cl,%cl
    2137:	74 48                	je     0x2181
    2139:	8b 44 24 68          	mov    0x68(%rsp),%eax
    213d:	89 44 24 1c          	mov    %eax,0x1c(%rsp)
    2141:	48 bf 00 d0 6e 40 86 	movabs $0xffffd286406ed000,%rdi
    2148:	d2 ff ff 
    214b:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    2150:	b8 01 00 00 00       	mov    $0x1,%eax
    2155:	8b 06                	mov    (%rsi),%eax
    2157:	3d 00 10 00 00       	cmp    $0x1000,%eax
    215c:	73 16                	jae    0x2174
    215e:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    2165:	00 
    2166:	48 8b 00             	mov    (%rax),%rax
    2169:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    2170:	2b 9e 
    2172:	eb 02                	jmp    0x2176
    2174:	31 c0                	xor    %eax,%eax
    2176:	48 85 c0             	test   %rax,%rax
    2179:	0f 84 9b 00 00 00    	je     0x221a
    217f:	ff 00                	incl   (%rax)
    2181:	48 8b 84 24 b0 00 00 	mov    0xb0(%rsp),%rax
    2188:	00 
    2189:	48 ff 40 08          	incq   0x8(%rax)
    218d:	e9 b0 fb ff ff       	jmp    0x1d42
    2192:	c7 44 24 1c 09 02 00 	movl   $0x209,0x1c(%rsp)
    2199:	00 
    219a:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    21a1:	8b ff ff 
    21a4:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    21a9:	b8 01 00 00 00       	mov    $0x1,%eax
    21ae:	8b 06                	mov    (%rsi),%eax
    21b0:	3d 00 04 00 00       	cmp    $0x400,%eax
    21b5:	73 16                	jae    0x21cd
    21b7:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    21be:	00 
    21bf:	48 8b 00             	mov    (%rax),%rax
    21c2:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    21c9:	2b 9e 
    21cb:	eb 02                	jmp    0x21cf
    21cd:	31 c0                	xor    %eax,%eax
    21cf:	48 85 c0             	test   %rax,%rax
    21d2:	74 46                	je     0x221a
    21d4:	48 ff 40 08          	incq   0x8(%rax)
    21d8:	eb 40                	jmp    0x221a
    21da:	c7 44 24 1c 09 02 00 	movl   $0x209,0x1c(%rsp)
    21e1:	00 
    21e2:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    21e9:	8b ff ff 
    21ec:	48 8d 74 24 1c       	lea    0x1c(%rsp),%rsi
    21f1:	8b 06                	mov    (%rsi),%eax
    21f3:	3d 00 04 00 00       	cmp    $0x400,%eax
    21f8:	73 16                	jae    0x2210
    21fa:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    2201:	00 
    2202:	48 8b 00             	mov    (%rax),%rax
    2205:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    220c:	2b 9e 
    220e:	eb 02                	jmp    0x2212
    2210:	31 c0                	xor    %eax,%eax
    2212:	48 85 c0             	test   %rax,%rax
    2215:	74 03                	je     0x221a
    2217:	48 ff 00             	incq   (%rax)
    221a:	41 bd 01 00 00 00    	mov    $0x1,%r13d
    2220:	41 83 fd 01          	cmp    $0x1,%r13d
    2224:	74 2a                	je     0x2250
    2226:	41 83 fd 03          	cmp    $0x3,%r13d
    222a:	75 12                	jne    0x223e
    222c:	c7 84 24 94 00 00 00 	movl   $0x211,0x94(%rsp)
    2233:	11 02 00 00 
    2237:	bd 03 00 00 00       	mov    $0x3,%ebp
    223c:	eb 22                	jmp    0x2260
    223e:	c7 84 24 94 00 00 00 	movl   $0x213,0x94(%rsp)
    2245:	13 02 00 00 
    2249:	bd 02 00 00 00       	mov    $0x2,%ebp
    224e:	eb 10                	jmp    0x2260
    2250:	c7 84 24 94 00 00 00 	movl   $0x212,0x94(%rsp)
    2257:	12 02 00 00 
    225b:	bd 01 00 00 00       	mov    $0x1,%ebp
    2260:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    2267:	8b ff ff 
    226a:	48 8d b4 24 94 00 00 	lea    0x94(%rsp),%rsi
    2271:	00 
    2272:	b8 01 00 00 00       	mov    $0x1,%eax
    2277:	8b 06                	mov    (%rsi),%eax
    2279:	3d 00 04 00 00       	cmp    $0x400,%eax
    227e:	73 16                	jae    0x2296
    2280:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    2287:	00 
    2288:	48 8b 00             	mov    (%rax),%rax
    228b:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    2292:	2b 9e 
    2294:	eb 02                	jmp    0x2298
    2296:	31 c0                	xor    %eax,%eax
    2298:	48 85 c0             	test   %rax,%rax
    229b:	74 09                	je     0x22a6
    229d:	48 ff 00             	incq   (%rax)
    22a0:	4c 01 78 08          	add    %r15,0x8(%rax)
    22a4:	89 eb                	mov    %ebp,%ebx
    22a6:	89 d8                	mov    %ebx,%eax
    22a8:	48 81 c4 b8 00 00 00 	add    $0xb8,%rsp
    22af:	5b                   	pop    %rbx
    22b0:	41 5c                	pop    %r12
    22b2:	41 5d                	pop    %r13
    22b4:	41 5e                	pop    %r14
    22b6:	41 5f                	pop    %r15
    22b8:	5d                   	pop    %rbp
    22b9:	e9 e3 04 00 00       	jmp    0x27a1
    22be:	b8 2c 00 00 00       	mov    $0x2c,%eax
    22c3:	4c 89 f7             	mov    %r14,%rdi
    22c6:	be d8 ff ff ff       	mov    $0xffffffd8,%esi
    22cb:	e8 8c c9 75 db       	call   0xffffffffdb75ec5c
    22d0:	85 c0                	test   %eax,%eax
    22d2:	0f 84 67 01 00 00    	je     0x243f
    22d8:	c7 04 24 07 02 00 00 	movl   $0x207,(%rsp)
    22df:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    22e6:	8b ff ff 
    22e9:	48 89 e6             	mov    %rsp,%rsi
    22ec:	b8 01 00 00 00       	mov    $0x1,%eax
    22f1:	8b 06                	mov    (%rsi),%eax
    22f3:	3d 00 04 00 00       	cmp    $0x400,%eax
    22f8:	73 16                	jae    0x2310
    22fa:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    2301:	00 
    2302:	48 8b 00             	mov    (%rax),%rax
    2305:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    230c:	2b 9e 
    230e:	eb 02                	jmp    0x2312
    2310:	31 c0                	xor    %eax,%eax
    2312:	48 85 c0             	test   %rax,%rax
    2315:	0f 84 05 ff ff ff    	je     0x2220
    231b:	48 ff 40 08          	incq   0x8(%rax)
    231f:	e9 fc fe ff ff       	jmp    0x2220
    2324:	49 8b 06             	mov    (%r14),%rax
    2327:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    232b:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    232f:	48 39 ca             	cmp    %rcx,%rdx
    2332:	0f 87 18 fb ff ff    	ja     0x1e50
    2338:	48 8d 50 22          	lea    0x22(%rax),%rdx
    233c:	48 39 ca             	cmp    %rcx,%rdx
    233f:	0f 87 0b fb ff ff    	ja     0x1e50
    2345:	8b 4c 24 38          	mov    0x38(%rsp),%ecx
    2349:	66 c1 c1 08          	rol    $0x8,%cx
    234d:	31 cd                	xor    %ecx,%ebp
    234f:	c1 e5 10             	shl    $0x10,%ebp
    2352:	41 0f b7 4c 24 04    	movzwl 0x4(%r12),%ecx
    2358:	66 89 48 04          	mov    %cx,0x4(%rax)
    235c:	41 8b 0c 24          	mov    (%r12),%ecx
    2360:	89 08                	mov    %ecx,(%rax)
    2362:	8b 48 14             	mov    0x14(%rax),%ecx
    2365:	89 48 06             	mov    %ecx,0x6(%rax)
    2368:	0f b7 48 18          	movzwl 0x18(%rax),%ecx
    236c:	66 89 48 0a          	mov    %cx,0xa(%rax)
    2370:	66 c7 40 0c 08 00    	movw   $0x8,0xc(%rax)
    2376:	8d 8d ac 10 00 00    	lea    0x10ac(%rbp),%ecx
    237c:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    2381:	48 8b b4 24 a8 00 00 	mov    0xa8(%rsp),%rsi
    2388:	00 
    2389:	8b 36                	mov    (%rsi),%esi
    238b:	c6 40 0e 45          	movb   $0x45,0xe(%rax)
    238f:	88 50 0f             	mov    %dl,0xf(%rax)
    2392:	8b 54 24 28          	mov    0x28(%rsp),%edx
    2396:	83 c2 14             	add    $0x14,%edx
    2399:	66 0f 38 f1 50 10    	movbe  %dx,0x10(%rax)
    239f:	66 c1 c2 08          	rol    $0x8,%dx
    23a3:	c7 40 12 00 00 00 00 	movl   $0x0,0x12(%rax)
    23aa:	89 70 1e             	mov    %esi,0x1e(%rax)
    23ad:	89 48 1a             	mov    %ecx,0x1a(%rax)
    23b0:	66 c7 40 16 40 04    	movw   $0x440,0x16(%rax)
    23b6:	0f b7 48 0e          	movzwl 0xe(%rax),%ecx
    23ba:	0f b7 d2             	movzwl %dx,%edx
    23bd:	0f b7 78 16          	movzwl 0x16(%rax),%edi
    23c1:	48 01 cf             	add    %rcx,%rdi
    23c4:	c1 ed 10             	shr    $0x10,%ebp
    23c7:	48 01 fd             	add    %rdi,%rbp
    23ca:	0f b7 ce             	movzwl %si,%ecx
    23cd:	48 01 e9             	add    %rbp,%rcx
    23d0:	48 01 d1             	add    %rdx,%rcx
    23d3:	0f b7 50 20          	movzwl 0x20(%rax),%edx
    23d7:	48 01 d1             	add    %rdx,%rcx
    23da:	48 81 c1 ac 10 00 00 	add    $0x10ac,%rcx
    23e1:	48 89 ca             	mov    %rcx,%rdx
    23e4:	48 c1 ea 10          	shr    $0x10,%rdx
    23e8:	0f b7 f1             	movzwl %cx,%esi
    23eb:	48 01 d6             	add    %rdx,%rsi
    23ee:	48 81 f9 00 00 01 00 	cmp    $0x10000,%rcx
    23f5:	48 0f 42 f1          	cmovb  %rcx,%rsi
    23f9:	48 89 f1             	mov    %rsi,%rcx
    23fc:	48 c1 e9 10          	shr    $0x10,%rcx
    2400:	0f b7 d6             	movzwl %si,%edx
    2403:	48 01 ca             	add    %rcx,%rdx
    2406:	48 81 fe 00 00 01 00 	cmp    $0x10000,%rsi
    240d:	48 0f 42 d6          	cmovb  %rsi,%rdx
    2411:	48 89 d1             	mov    %rdx,%rcx
    2414:	48 c1 e9 10          	shr    $0x10,%rcx
    2418:	0f b7 f2             	movzwl %dx,%esi
    241b:	01 f1                	add    %esi,%ecx
    241d:	48 81 fa 00 00 01 00 	cmp    $0x10000,%rdx
    2424:	0f 42 ca             	cmovb  %edx,%ecx
    2427:	89 ca                	mov    %ecx,%edx
    2429:	c1 ea 10             	shr    $0x10,%edx
    242c:	01 ca                	add    %ecx,%edx
    242e:	f7 d2                	not    %edx
    2430:	66 89 50 18          	mov    %dx,0x18(%rax)
    2434:	41 bd 03 00 00 00    	mov    $0x3,%r13d
    243a:	e9 e1 fd ff ff       	jmp    0x2220
    243f:	49 8b 06             	mov    (%r14),%rax
    2442:	49 8b 4e 08          	mov    0x8(%r14),%rcx
    2446:	48 8d 50 0e          	lea    0xe(%rax),%rdx
    244a:	48 39 ca             	cmp    %rcx,%rdx
    244d:	0f 87 85 fe ff ff    	ja     0x22d8
    2453:	48 8d 50 36          	lea    0x36(%rax),%rdx
    2457:	48 39 ca             	cmp    %rcx,%rdx
    245a:	0f 87 78 fe ff ff    	ja     0x22d8
    2460:	41 0f b7 4c 24 04    	movzwl 0x4(%r12),%ecx
    2466:	66 89 48 04          	mov    %cx,0x4(%rax)
    246a:	41 8b 0c 24          	mov    (%r12),%ecx
    246e:	89 08                	mov    %ecx,(%rax)
    2470:	8b 48 28             	mov    0x28(%rax),%ecx
    2473:	89 48 06             	mov    %ecx,0x6(%rax)
    2476:	0f b7 48 2c          	movzwl 0x2c(%rax),%ecx
    247a:	66 89 48 0a          	mov    %cx,0xa(%rax)
    247e:	66 c7 40 0c 86 dd    	movw   $0xdd86,0xc(%rax)
    2484:	0f b7 4c 24 60       	movzwl 0x60(%rsp),%ecx
    2489:	33 4c 24 40          	xor    0x40(%rsp),%ecx
    248d:	0f b6 54 24 6d       	movzbl 0x6d(%rsp),%edx
    2492:	66 c7 40 10 00 00    	movw   $0x0,0x10(%rax)
    2498:	89 d6                	mov    %edx,%esi
    249a:	40 c0 ee 04          	shr    $0x4,%sil
    249e:	40 80 ce 60          	or     $0x60,%sil
    24a2:	40 88 70 0e          	mov    %sil,0xe(%rax)
    24a6:	c0 e2 04             	shl    $0x4,%dl
    24a9:	88 50 0f             	mov    %dl,0xf(%rax)
    24ac:	66 c7 40 14 04 40    	movw   $0x4004,0x14(%rax)
    24b2:	0f b7 54 24 34       	movzwl 0x34(%rsp),%edx
    24b7:	66 89 50 12          	mov    %dx,0x12(%rax)
    24bb:	48 c7 40 16 01 00 00 	movq   $0x1,0x16(%rax)
    24c2:	00 
    24c3:	c7 40 1e 00 00 00 00 	movl   $0x0,0x1e(%rax)
    24ca:	89 48 22             	mov    %ecx,0x22(%rax)
    24cd:	48 8b 94 24 a8 00 00 	mov    0xa8(%rsp),%rdx
    24d4:	00 
    24d5:	48 8b 0a             	mov    (%rdx),%rcx
    24d8:	48 8b 52 08          	mov    0x8(%rdx),%rdx
    24dc:	48 89 48 26          	mov    %rcx,0x26(%rax)
    24e0:	48 89 50 2e          	mov    %rdx,0x2e(%rax)
    24e4:	41 bd 03 00 00 00    	mov    $0x3,%r13d
    24ea:	e9 31 fd ff ff       	jmp    0x2220
    24ef:	49 ff 45 28          	incq   0x28(%r13)
    24f3:	e9 22 fd ff ff       	jmp    0x221a
    24f8:	49 8b 04 24          	mov    (%r12),%rax
    24fc:	48 ff c0             	inc    %rax
    24ff:	49 89 04 24          	mov    %rax,(%r12)
    2503:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    2509:	73 31                	jae    0x253c
    250b:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    2512:	00 
    2513:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    251a:	00 00 
    251c:	8b 44 24 68          	mov    0x68(%rsp),%eax
    2520:	89 04 24             	mov    %eax,(%rsp)
    2523:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    2528:	48 89 e2             	mov    %rsp,%rdx
    252b:	b8 02 00 00 00       	mov    $0x2,%eax
    2530:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    2535:	31 c9                	xor    %ecx,%ecx
    2537:	e8 d0 14 eb da       	call   0xffffffffdaeb3a0c
    253c:	48 ff 45 60          	incq   0x60(%rbp)
    2540:	48 ff 45 20          	incq   0x20(%rbp)
    2544:	0f b7 44 24 60       	movzwl 0x60(%rsp),%eax
    2549:	89 44 24 38          	mov    %eax,0x38(%rsp)
    254d:	4c 89 ed             	mov    %r13,%rbp
    2550:	e9 70 ed ff ff       	jmp    0x12c5
    2555:	c7 04 24 02 02 00 00 	movl   $0x202,(%rsp)
    255c:	48 bf 00 00 1f 56 10 	movabs $0xffff8b10561f0000,%rdi
    2563:	8b ff ff 
    2566:	48 89 e6             	mov    %rsp,%rsi
    2569:	b8 01 00 00 00       	mov    $0x1,%eax
    256e:	8b 06                	mov    (%rsi),%eax
    2570:	3d 00 04 00 00       	cmp    $0x400,%eax
    2575:	73 16                	jae    0x258d
    2577:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    257e:	00 
    257f:	48 8b 00             	mov    (%rax),%rax
    2582:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    2589:	2b 9e 
    258b:	eb 02                	jmp    0x258f
    258d:	31 c0                	xor    %eax,%eax
    258f:	48 85 c0             	test   %rax,%rax
    2592:	0f 84 bc 00 00 00    	je     0x2654
    2598:	49 89 c4             	mov    %rax,%r12
    259b:	b8 05 00 00 00       	mov    $0x5,%eax
    25a0:	e8 67 18 eb da       	call   0xffffffffdaeb3e0c
    25a5:	48 89 c1             	mov    %rax,%rcx
    25a8:	49 2b 4c 24 08       	sub    0x8(%r12),%rcx
    25ad:	48 81 f9 01 ca 9a 3b 	cmp    $0x3b9aca01,%rcx
    25b4:	72 5a                	jb     0x2610
    25b6:	49 c7 04 24 01 00 00 	movq   $0x1,(%r12)
    25bd:	00 
    25be:	49 89 44 24 08       	mov    %rax,0x8(%r12)
    25c3:	eb 5e                	jmp    0x2623
    25c5:	89 08                	mov    %ecx,(%rax)
    25c7:	49 ff 45 58          	incq   0x58(%r13)
    25cb:	8b 44 24 70          	mov    0x70(%rsp),%eax
    25cf:	89 04 24             	mov    %eax,(%rsp)
    25d2:	48 bf 00 c0 2a 83 0f 	movabs $0xffff8b0f832ac000,%rdi
    25d9:	8b ff ff 
    25dc:	48 89 e6             	mov    %rsp,%rsi
    25df:	b8 01 00 00 00       	mov    $0x1,%eax
    25e4:	8b 06                	mov    (%rsi),%eax
    25e6:	3d 00 02 00 00       	cmp    $0x200,%eax
    25eb:	73 16                	jae    0x2603
    25ed:	48 8d 84 c7 30 01 00 	lea    0x130(%rdi,%rax,8),%rax
    25f4:	00 
    25f5:	48 8b 00             	mov    (%rax),%rax
    25f8:	65 48 03 04 25 28 10 	add    %gs:0xffffffff9e2b1028,%rax
    25ff:	2b 9e 
    2601:	eb 02                	jmp    0x2605
    2603:	31 c0                	xor    %eax,%eax
    2605:	48 85 c0             	test   %rax,%rax
    2608:	74 4e                	je     0x2658
    260a:	48 ff 40 08          	incq   0x8(%rax)
    260e:	eb 48                	jmp    0x2658
    2610:	49 8b 04 24          	mov    (%r12),%rax
    2614:	48 ff c0             	inc    %rax
    2617:	49 89 04 24          	mov    %rax,(%r12)
    261b:	48 3d 49 e8 01 00    	cmp    $0x1e849,%rax
    2621:	73 31                	jae    0x2654
    2623:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    262a:	00 
    262b:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
    2632:	00 00 
    2634:	8b 44 24 68          	mov    0x68(%rsp),%eax
    2638:	89 04 24             	mov    %eax,(%rsp)
    263b:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
    2640:	48 89 e2             	mov    %rsp,%rdx
    2643:	b8 02 00 00 00       	mov    $0x2,%eax
    2648:	48 8b 7c 24 78       	mov    0x78(%rsp),%rdi
    264d:	31 c9                	xor    %ecx,%ecx
    264f:	e8 b8 13 eb da       	call   0xffffffffdaeb3a0c
    2654:	49 ff 45 60          	incq   0x60(%r13)
    2658:	49 ff 45 20          	incq   0x20(%r13)
    265c:	0f b7 44 24 60       	movzwl 0x60(%rsp),%eax
    2661:	89 44 24 38          	mov    %eax,0x38(%rsp)
    2665:	e9 d8 f6 ff ff       	jmp    0x1d42
    266a:	8b 07                	mov    (%rdi),%eax
    266c:	8b 4f 04             	mov    0x4(%rdi),%ecx
    266f:	8d 91 ff c0 ad de    	lea    -0x21523f01(%rcx),%edx
    2675:	8b 77 08             	mov    0x8(%rdi),%esi
    2678:	29 f0                	sub    %esi,%eax
    267a:	44 8d 86 ff c0 ad de 	lea    -0x21523f01(%rsi),%r8d
    2681:	c4 43 7b f0 c0 1c    	rorx   $0x1c,%r8d,%r8d
    2687:	41 31 c0             	xor    %eax,%r8d
    268a:	44 29 c2             	sub    %r8d,%edx
    268d:	c4 c3 7b f0 c0 1a    	rorx   $0x1a,%r8d,%eax
    2693:	31 d0                	xor    %edx,%eax
    2695:	01 f1                	add    %esi,%ecx
    2697:	81 c1 fe 81 5b bd    	add    $0xbd5b81fe,%ecx
    269d:	41 01 c8             	add    %ecx,%r8d
    26a0:	42 8d 34 00          	lea    (%rax,%r8,1),%esi
    26a4:	29 c1                	sub    %eax,%ecx
    26a6:	c4 63 7b f0 c8 18    	rorx   $0x18,%eax,%r9d
    26ac:	41 31 c9             	xor    %ecx,%r9d
    26af:	45 29 c8             	sub    %r9d,%r8d
    26b2:	c4 c3 7b f0 d1 10    	rorx   $0x10,%r9d,%edx
    26b8:	44 31 c2             	xor    %r8d,%edx
    26bb:	41 01 f1             	add    %esi,%r9d
    26be:	29 d6                	sub    %edx,%esi
    26c0:	c4 e3 7b f0 ca 0d    	rorx   $0xd,%edx,%ecx
    26c6:	31 f1                	xor    %esi,%ecx
    26c8:	44 01 ca             	add    %r9d,%edx
    26cb:	8d 04 11             	lea    (%rcx,%rdx,1),%eax
    26ce:	41 29 c9             	sub    %ecx,%r9d
    26d1:	c4 e3 7b f0 c9 1c    	rorx   $0x1c,%ecx,%ecx
    26d7:	44 31 c9             	xor    %r9d,%ecx
    26da:	0f b6 77 0f          	movzbl 0xf(%rdi),%esi
    26de:	c1 e6 18             	shl    $0x18,%esi
    26e1:	44 0f b6 47 0e       	movzbl 0xe(%rdi),%r8d
    26e6:	41 c1 e0 10          	shl    $0x10,%r8d
    26ea:	41 01 f0             	add    %esi,%r8d
    26ed:	44 0f b6 4f 0d       	movzbl 0xd(%rdi),%r9d
    26f2:	41 c1 e1 08          	shl    $0x8,%r9d
    26f6:	45 01 c1             	add    %r8d,%r9d
    26f9:	0f b6 77 0c          	movzbl 0xc(%rdi),%esi
    26fd:	44 01 ce             	add    %r9d,%esi
    2700:	01 d6                	add    %edx,%esi
    2702:	31 c1                	xor    %eax,%ecx
    2704:	c4 e3 7b f0 d0 12    	rorx   $0x12,%eax,%edx
    270a:	29 d1                	sub    %edx,%ecx
    270c:	31 ce                	xor    %ecx,%esi
    270e:	c4 e3 7b f0 d1 15    	rorx   $0x15,%ecx,%edx
    2714:	29 d6                	sub    %edx,%esi
    2716:	31 f0                	xor    %esi,%eax
    2718:	c4 e3 7b f0 d6 07    	rorx   $0x7,%esi,%edx
    271e:	29 d0                	sub    %edx,%eax
    2720:	31 c1                	xor    %eax,%ecx
    2722:	c4 e3 7b f0 d0 10    	rorx   $0x10,%eax,%edx
    2728:	29 d1                	sub    %edx,%ecx
    272a:	31 ce                	xor    %ecx,%esi
    272c:	c4 e3 7b f0 d1 1c    	rorx   $0x1c,%ecx,%edx
    2732:	29 d6                	sub    %edx,%esi
    2734:	31 f0                	xor    %esi,%eax
    2736:	c4 e3 7b f0 d6 12    	rorx   $0x12,%esi,%edx
    273c:	29 d0                	sub    %edx,%eax
    273e:	c4 e3 7b f0 d0 08    	rorx   $0x8,%eax,%edx
    2744:	31 c8                	xor    %ecx,%eax
    2746:	29 d0                	sub    %edx,%eax
    2748:	c3                   	ret
    2749:	81 c7 f7 c0 ad e0    	add    $0xe0adc0f7,%edi
    274f:	81 c6 f7 c0 ad e0    	add    $0xe0adc0f7,%esi
    2755:	89 f0                	mov    %esi,%eax
    2757:	35 f7 c0 ad e0       	xor    $0xe0adc0f7,%eax
    275c:	c4 e3 7b f0 ce 12    	rorx   $0x12,%esi,%ecx
    2762:	29 c8                	sub    %ecx,%eax
    2764:	31 c7                	xor    %eax,%edi
    2766:	c4 e3 7b f0 c8 15    	rorx   $0x15,%eax,%ecx
    276c:	29 cf                	sub    %ecx,%edi
    276e:	31 fe                	xor    %edi,%esi
    2770:	c4 e3 7b f0 cf 07    	rorx   $0x7,%edi,%ecx
    2776:	29 ce                	sub    %ecx,%esi
    2778:	31 f0                	xor    %esi,%eax
    277a:	c4 e3 7b f0 ce 10    	rorx   $0x10,%esi,%ecx
    2780:	29 c8                	sub    %ecx,%eax
    2782:	31 c7                	xor    %eax,%edi
    2784:	c4 e3 7b f0 c8 1c    	rorx   $0x1c,%eax,%ecx
    278a:	29 cf                	sub    %ecx,%edi
    278c:	31 fe                	xor    %edi,%esi
    278e:	c4 e3 7b f0 cf 12    	rorx   $0x12,%edi,%ecx
    2794:	29 ce                	sub    %ecx,%esi
    2796:	31 f0                	xor    %esi,%eax
    2798:	c4 e3 7b f0 ce 08    	rorx   $0x8,%esi,%ecx
    279e:	29 c8                	sub    %ecx,%eax
    27a0:	c3                   	ret
    27a1:	c9                   	leave
    27a2:	e9 a5 c3 a0 db       	jmp    0xffffffffdba0eb4c
