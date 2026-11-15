
vendor/build/native-bpf/x86/7.0.0-rc2+/native/otel/otelcol-ebpf-profiler.native.o:     file format elf64-x86-64


Disassembly of section uprobe/custom__generic:

Disassembly of section perf_event/unwind_dotnet:

Disassembly of section kprobe/unwind_dotnet:

Disassembly of section perf_event/go_labels:

Disassembly of section kprobe/go_labels:

Disassembly of section perf_event/unwind_hotspot:

Disassembly of section kprobe/unwind_hotspot:

0000000000000000 <kprobe_unwind_hotspot>:
       0:	55                   	push   rbp
       1:	41 57                	push   r15
       3:	41 56                	push   r14
       5:	41 55                	push   r13
       7:	41 54                	push   r12
       9:	53                   	push   rbx
       a:	48 81 ec 38 01 00 00 	sub    rsp,0x138
      11:	49 89 fc             	mov    r12,rdi
      14:	c7 44 24 40 00 00 00 	mov    DWORD PTR [rsp+0x40],0x0
      1b:	00 
      1c:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 23 <kprobe_unwind_hotspot+0x23>
			1f: R_X86_64_REX_GOTPCRELX	per_cpu_records-0x4
      23:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
      28:	b8 01 00 00 00       	mov    eax,0x1
      2d:	ff d0                	call   rax
      2f:	48 85 c0             	test   rax,rax
      32:	0f 84 0e 01 00 00    	je     146 <kprobe_unwind_hotspot+0x146>
      38:	49 89 c6             	mov    r14,rax
      3b:	8b 00                	mov    eax,DWORD PTR [rax]
      3d:	89 84 24 34 01 00 00 	mov    DWORD PTR [rsp+0x134],eax
      44:	48 8b 1d 00 00 00 00 	mov    rbx,QWORD PTR [rip+0x0]        # 4b <kprobe_unwind_hotspot+0x4b>
			47: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
      4b:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
      4e:	0f 85 f9 05 00 00    	jne    64d <kprobe_unwind_hotspot+0x64d>
      54:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 5b <kprobe_unwind_hotspot+0x5b>
			57: R_X86_64_PC32	hotspot_procs-0x4
      5b:	48 8d b4 24 34 01 00 	lea    rsi,[rsp+0x134]
      62:	00 
      63:	b8 01 00 00 00       	mov    eax,0x1
      68:	ff d0                	call   rax
      6a:	48 85 c0             	test   rax,rax
      6d:	0f 84 dd 00 00 00    	je     150 <kprobe_unwind_hotspot+0x150>
      73:	49 89 c7             	mov    r15,rax
      76:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x29
      7d:	29 00 00 00 
      81:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 88 <kprobe_unwind_hotspot+0x88>
			84: R_X86_64_REX_GOTPCRELX	metrics-0x4
      88:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
      8f:	00 
      90:	b8 01 00 00 00       	mov    eax,0x1
      95:	ff d0                	call   rax
      97:	48 85 c0             	test   rax,rax
      9a:	4c 89 a4 24 28 01 00 	mov    QWORD PTR [rsp+0x128],r12
      a1:	00 
      a2:	0f 84 14 01 00 00    	je     1bc <kprobe_unwind_hotspot+0x1bc>
      a8:	48 ff 00             	inc    QWORD PTR [rax]
      ab:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
      ae:	49 8b 9e d0 0e 00 00 	mov    rbx,QWORD PTR [r14+0xed0]
      b5:	4d 8b ae d8 0e 00 00 	mov    r13,QWORD PTR [r14+0xed8]
      bc:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
      c3:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
      ca:	00 
      cb:	0f 84 11 01 00 00    	je     1e2 <kprobe_unwind_hotspot+0x1e2>
      d1:	48 b8 6f 66 66 73 65 	movabs rax,0x252074657366666f
      d8:	74 20 25 
      db:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
      e0:	48 b8 72 74 20 25 6c 	movabs rax,0x202c786c25207472
      e7:	78 2c 20 
      ea:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
      ef:	48 b8 63 6f 64 65 20 	movabs rax,0x6174732065646f63
      f6:	73 74 61 
      f9:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
      fe:	48 b8 20 25 6c 78 20 	movabs rax,0x206e6920786c2520
     105:	69 6e 20 
     108:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     10d:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
     114:	20 2d 3e 
     117:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     11c:	c7 44 24 68 6c 78 0a 	mov    DWORD PTR [rsp+0x68],0xa786c
     123:	00 
     124:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
     12b:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
     132:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
     137:	be 2c 00 00 00       	mov    esi,0x2c
     13c:	bf 06 00 00 00       	mov    edi,0x6
     141:	e9 9c 00 00 00       	jmp    1e2 <kprobe_unwind_hotspot+0x1e2>
     146:	b8 ff ff ff ff       	mov    eax,0xffffffff
     14b:	e9 c4 02 00 00       	jmp    414 <kprobe_unwind_hotspot+0x414>
     150:	31 c0                	xor    eax,eax
     152:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     155:	0f 84 b9 02 00 00    	je     414 <kprobe_unwind_hotspot+0x414>
     15b:	48 b8 69 73 20 70 69 	movabs rax,0xa646970207369
     162:	64 0a 00 
     165:	48 89 44 24 5e       	mov    QWORD PTR [rsp+0x5e],rax
     16a:	48 b8 66 6f 72 20 74 	movabs rax,0x7369687420726f66
     171:	68 69 73 
     174:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
     179:	48 b8 72 6f 63 49 6e 	movabs rax,0x206f666e49636f72
     180:	66 6f 20 
     183:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
     188:	48 b8 48 6f 74 73 70 	movabs rax,0x50746f7073746f48
     18f:	6f 74 50 
     192:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     197:	48 b8 6a 76 6d 3a 20 	movabs rax,0x206f6e203a6d766a
     19e:	6e 6f 20 
     1a1:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     1a6:	31 c0                	xor    eax,eax
     1a8:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
     1ad:	ba 26 00 00 00       	mov    edx,0x26
     1b2:	be 06 00 00 00       	mov    esi,0x6
     1b7:	e9 58 02 00 00       	jmp    414 <kprobe_unwind_hotspot+0x414>
     1bc:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     1bf:	0f 85 cf 07 00 00    	jne    994 <kprobe_unwind_hotspot+0x994>
     1c5:	49 8b 9e d0 0e 00 00 	mov    rbx,QWORD PTR [r14+0xed0]
     1cc:	4d 8b ae d8 0e 00 00 	mov    r13,QWORD PTR [r14+0xed8]
     1d3:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
     1da:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
     1e1:	00 
     1e2:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
     1e7:	c4 c2 fb f7 ae 18 0f 	shrx   rbp,QWORD PTR [r14+0xf18],rax
     1ee:	00 00 
     1f0:	b0 38                	mov    al,0x38
     1f2:	c4 42 f8 f5 a6 10 0f 	bzhi   r12,QWORD PTR [r14+0xf10],rax
     1f9:	00 00 
     1fb:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     1ff:	48 89 e7             	mov    rdi,rsp
     202:	b8 01 00 00 00       	mov    eax,0x1
     207:	b9 70 00 00 00       	mov    ecx,0x70
     20c:	be 01 00 00 00       	mov    esi,0x1
     211:	ff d1                	call   rcx
     213:	48 85 c0             	test   rax,rax
     216:	74 45                	je     25d <kprobe_unwind_hotspot+0x25d>
     218:	48 c7 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],0x0
     21f:	00 00 00 00 00 
     224:	48 8b 1d 00 00 00 00 	mov    rbx,QWORD PTR [rip+0x0]        # 22b <kprobe_unwind_hotspot+0x22b>
			227: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     22b:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     22e:	0f 85 19 06 00 00    	jne    84d <kprobe_unwind_hotspot+0x84d>
     234:	c7 04 24 2b 00 00 00 	mov    DWORD PTR [rsp],0x2b
     23b:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 242 <kprobe_unwind_hotspot+0x242>
			23e: R_X86_64_REX_GOTPCRELX	metrics-0x4
     242:	48 89 e6             	mov    rsi,rsp
     245:	b8 01 00 00 00       	mov    eax,0x1
     24a:	ff d0                	call   rax
     24c:	48 85 c0             	test   rax,rax
     24f:	0f 84 d0 00 00 00    	je     325 <kprobe_unwind_hotspot+0x325>
     255:	48 ff 00             	inc    QWORD PTR [rax]
     258:	e9 d1 00 00 00       	jmp    32e <kprobe_unwind_hotspot+0x32e>
     25d:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 264 <kprobe_unwind_hotspot+0x264>
			260: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     264:	83 38 00             	cmp    DWORD PTR [rax],0x0
     267:	0f 85 9e 07 00 00    	jne    a0b <kprobe_unwind_hotspot+0xa0b>
     26d:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     271:	8d 48 01             	lea    ecx,[rax+0x1]
     274:	80 f9 02             	cmp    cl,0x2
     277:	0f 83 ef 07 00 00    	jae    a6c <kprobe_unwind_hotspot+0xa6c>
     27d:	84 c0                	test   al,al
     27f:	75 97                	jne    218 <kprobe_unwind_hotspot+0x218>
     281:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
     286:	c4 e2 f9 f7 cd       	shlx   rcx,rbp,rax
     28b:	49 03 8e 20 0f 00 00 	add    rcx,QWORD PTR [r14+0xf20]
     292:	41 0f b6 47 1b       	movzx  eax,BYTE PTR [r15+0x1b]
     297:	48 01 c8             	add    rax,rcx
     29a:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 2a1 <kprobe_unwind_hotspot+0x2a1>
			29d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     2a1:	83 39 00             	cmp    DWORD PTR [rcx],0x0
     2a4:	0f 85 5e 0e 00 00    	jne    1108 <kprobe_unwind_hotspot+0x1108>
     2aa:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
     2b1:	00 
     2b2:	48 85 c0             	test   rax,rax
     2b5:	0f 84 69 ff ff ff    	je     224 <kprobe_unwind_hotspot+0x224>
     2bb:	4d 89 f4             	mov    r12,r14
     2be:	49 81 c4 80 0f 00 00 	add    r12,0xf80
     2c5:	b9 00 02 00 00       	mov    ecx,0x200
     2ca:	41 b8 70 00 00 00    	mov    r8d,0x70
     2d0:	48 8b 94 24 d0 00 00 	mov    rdx,QWORD PTR [rsp+0xd0]
     2d7:	00 
     2d8:	4c 89 e7             	mov    rdi,r12
     2db:	be 00 02 00 00       	mov    esi,0x200
     2e0:	41 ff d0             	call   r8
     2e3:	48 85 c0             	test   rax,rax
     2e6:	0f 84 3a 01 00 00    	je     426 <kprobe_unwind_hotspot+0x426>
     2ec:	48 8b 1d 00 00 00 00 	mov    rbx,QWORD PTR [rip+0x0]        # 2f3 <kprobe_unwind_hotspot+0x2f3>
			2ef: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     2f3:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     2f6:	0f 85 8d 10 00 00    	jne    1389 <kprobe_unwind_hotspot+0x1389>
     2fc:	c7 04 24 2c 00 00 00 	mov    DWORD PTR [rsp],0x2c
     303:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 30a <kprobe_unwind_hotspot+0x30a>
			306: R_X86_64_REX_GOTPCRELX	metrics-0x4
     30a:	48 89 e6             	mov    rsi,rsp
     30d:	b8 01 00 00 00       	mov    eax,0x1
     312:	ff d0                	call   rax
     314:	48 85 c0             	test   rax,rax
     317:	0f 84 1d 03 00 00    	je     63a <kprobe_unwind_hotspot+0x63a>
     31d:	48 ff 00             	inc    QWORD PTR [rax]
     320:	e9 1e 03 00 00       	jmp    643 <kprobe_unwind_hotspot+0x643>
     325:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     328:	0f 85 52 0a 00 00    	jne    d80 <kprobe_unwind_hotspot+0xd80>
     32e:	b8 e8 03 00 00       	mov    eax,0x3e8
     333:	31 db                	xor    ebx,ebx
     335:	89 c5                	mov    ebp,eax
     337:	4c 8b bc 24 28 01 00 	mov    r15,QWORD PTR [rsp+0x128]
     33e:	00 
     33f:	41 89 ae 2c 0f 00 00 	mov    DWORD PTR [r14+0xf2c],ebp
     346:	c7 44 24 40 00 00 00 	mov    DWORD PTR [rsp+0x40],0x0
     34d:	00 
     34e:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 355 <kprobe_unwind_hotspot+0x355>
			351: R_X86_64_REX_GOTPCRELX	per_cpu_records-0x4
     355:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
     35a:	b8 01 00 00 00       	mov    eax,0x1
     35f:	ff d0                	call   rax
     361:	48 85 c0             	test   rax,rax
     364:	74 4d                	je     3b3 <kprobe_unwind_hotspot+0x3b3>
     366:	0f b6 88 84 13 00 00 	movzx  ecx,BYTE PTR [rax+0x1384]
     36d:	89 da                	mov    edx,ebx
     36f:	80 f9 1d             	cmp    cl,0x1d
     372:	4c 8b 25 00 00 00 00 	mov    r12,QWORD PTR [rip+0x0]        # 379 <kprobe_unwind_hotspot+0x379>
			375: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     379:	72 67                	jb     3e2 <kprobe_unwind_hotspot+0x3e2>
     37b:	49 89 c6             	mov    r14,rax
     37e:	c7 80 2c 0f 00 00 05 	mov    DWORD PTR [rax+0xf2c],0x5
     385:	00 00 00 
     388:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x44
     38f:	44 00 00 00 
     393:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 39a <kprobe_unwind_hotspot+0x39a>
			396: R_X86_64_REX_GOTPCRELX	metrics-0x4
     39a:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
     3a1:	00 
     3a2:	b8 01 00 00 00       	mov    eax,0x1
     3a7:	ff d0                	call   rax
     3a9:	48 85 c0             	test   rax,rax
     3ac:	74 1c                	je     3ca <kprobe_unwind_hotspot+0x3ca>
     3ae:	48 ff 00             	inc    QWORD PTR [rax]
     3b1:	eb 22                	jmp    3d5 <kprobe_unwind_hotspot+0x3d5>
     3b3:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 3ba <kprobe_unwind_hotspot+0x3ba>
			3b6: R_X86_64_REX_GOTPCRELX	perf_progs-0x4
     3ba:	31 d2                	xor    edx,edx
     3bc:	b8 0c 00 00 00       	mov    eax,0xc
     3c1:	4c 8b 25 00 00 00 00 	mov    r12,QWORD PTR [rip+0x0]        # 3c8 <kprobe_unwind_hotspot+0x3c8>
			3c4: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     3c8:	eb 2e                	jmp    3f8 <kprobe_unwind_hotspot+0x3f8>
     3ca:	41 83 3c 24 00       	cmp    DWORD PTR [r12],0x0
     3cf:	0f 85 bc 0c 00 00    	jne    1091 <kprobe_unwind_hotspot+0x1091>
     3d5:	4c 89 f0             	mov    rax,r14
     3d8:	41 0f b6 8e 84 13 00 	movzx  ecx,BYTE PTR [r14+0x1384]
     3df:	00 
     3e0:	31 d2                	xor    edx,edx
     3e2:	fe c1                	inc    cl
     3e4:	88 88 84 13 00 00    	mov    BYTE PTR [rax+0x1384],cl
     3ea:	89 d1                	mov    ecx,edx
     3ec:	48 8b 35 00 00 00 00 	mov    rsi,QWORD PTR [rip+0x0]        # 3f3 <kprobe_unwind_hotspot+0x3f3>
			3ef: R_X86_64_REX_GOTPCRELX	perf_progs-0x4
     3f3:	b8 0c 00 00 00       	mov    eax,0xc
     3f8:	48 8b 35 00 00 00 00 	mov    rsi,QWORD PTR [rip+0x0]        # 3ff <kprobe_unwind_hotspot+0x3ff>
			3fb: R_X86_64_REX_GOTPCRELX	perf_progs-0x4
     3ff:	4c 89 ff             	mov    rdi,r15
     402:	ff d0                	call   rax
     404:	b8 ff ff ff ff       	mov    eax,0xffffffff
     409:	41 83 3c 24 00       	cmp    DWORD PTR [r12],0x0
     40e:	0f 85 8a 02 00 00    	jne    69e <kprobe_unwind_hotspot+0x69e>
     414:	48 81 c4 38 01 00 00 	add    rsp,0x138
     41b:	5b                   	pop    rbx
     41c:	41 5c                	pop    r12
     41e:	41 5d                	pop    r13
     420:	41 5e                	pop    r14
     422:	41 5f                	pop    r15
     424:	5d                   	pop    rbp
     425:	c3                   	ret
     426:	41 0f b7 4f 10       	movzx  ecx,WORD PTR [r15+0x10]
     42b:	b8 01 00 00 00       	mov    eax,0x1
     430:	48 81 f9 f8 01 00 00 	cmp    rcx,0x1f8
     437:	0f 87 f6 fe ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
     43d:	41 0f b7 57 12       	movzx  edx,WORD PTR [r15+0x12]
     442:	48 81 fa fc 01 00 00 	cmp    rdx,0x1fc
     449:	0f 87 e4 fe ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
     44f:	41 0f b7 77 14       	movzx  esi,WORD PTR [r15+0x14]
     454:	48 81 fe f8 01 00 00 	cmp    rsi,0x1f8
     45b:	0f 87 d2 fe ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
     461:	41 0f b6 47 17       	movzx  eax,BYTE PTR [r15+0x17]
     466:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
     46a:	48 89 84 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rax
     471:	00 
     472:	41 0f b6 47 18       	movzx  eax,BYTE PTR [r15+0x18]
     477:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
     47b:	48 89 84 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rax
     482:	00 
     483:	41 0f b6 47 1a       	movzx  eax,BYTE PTR [r15+0x1a]
     488:	41 8b 04 04          	mov    eax,DWORD PTR [r12+rax*1]
     48c:	c1 e0 03             	shl    eax,0x3
     48f:	89 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],eax
     496:	41 0f b6 47 19       	movzx  eax,BYTE PTR [r15+0x19]
     49b:	41 0f b7 04 04       	movzx  eax,WORD PTR [r12+rax*1]
     4a0:	66 89 84 24 00 01 00 	mov    WORD PTR [rsp+0x100],ax
     4a7:	00 
     4a8:	41 8b 04 14          	mov    eax,DWORD PTR [r12+rdx*1]
     4ac:	89 84 24 fc 00 00 00 	mov    DWORD PTR [rsp+0xfc],eax
     4b3:	41 8b 04 34          	mov    eax,DWORD PTR [r12+rsi*1]
     4b7:	89 84 24 f4 00 00 00 	mov    DWORD PTR [rsp+0xf4],eax
     4be:	49 8b 04 0c          	mov    rax,QWORD PTR [r12+rcx*1]
     4c2:	48 89 84 24 e8 00 00 	mov    QWORD PTR [rsp+0xe8],rax
     4c9:	00 
     4ca:	48 8d bc 24 f0 00 00 	lea    rdi,[rsp+0xf0]
     4d1:	00 
     4d2:	41 0f b6 47 16       	movzx  eax,BYTE PTR [r15+0x16]
     4d7:	49 8b 14 04          	mov    rdx,QWORD PTR [r12+rax*1]
     4db:	b8 04 00 00 00       	mov    eax,0x4
     4e0:	b9 70 00 00 00       	mov    ecx,0x70
     4e5:	be 04 00 00 00       	mov    esi,0x4
     4ea:	ff d1                	call   rcx
     4ec:	48 85 c0             	test   rax,rax
     4ef:	0f 85 f7 fd ff ff    	jne    2ec <kprobe_unwind_hotspot+0x2ec>
     4f5:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
     4fa:	74 2c                	je     528 <kprobe_unwind_hotspot+0x528>
     4fc:	48 8b 84 24 d0 00 00 	mov    rax,QWORD PTR [rsp+0xd0]
     503:	00 
     504:	8b 8c 24 d8 00 00 00 	mov    ecx,DWORD PTR [rsp+0xd8]
     50b:	48 01 c1             	add    rcx,rax
     50e:	48 89 8c 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rcx
     515:	00 
     516:	8b 8c 24 e0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xe0]
     51d:	48 01 c1             	add    rcx,rax
     520:	48 89 8c 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rcx
     527:	00 
     528:	48 8b 2d 00 00 00 00 	mov    rbp,QWORD PTR [rip+0x0]        # 52f <kprobe_unwind_hotspot+0x52f>
			52b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     52f:	83 7d 00 00          	cmp    DWORD PTR [rbp+0x0],0x0
     533:	0f 85 72 16 00 00    	jne    1bab <kprobe_unwind_hotspot+0x1bab>
     539:	48 8b b4 24 d0 00 00 	mov    rsi,QWORD PTR [rsp+0xd0]
     540:	00 
     541:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
     548:	00 
     549:	8b 94 24 f0 00 00 00 	mov    edx,DWORD PTR [rsp+0xf0]
     550:	89 d9                	mov    ecx,ebx
     552:	29 c1                	sub    ecx,eax
     554:	81 fa 6d 61 74 69    	cmp    edx,0x6974616d
     55a:	48 89 b4 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rsi
     561:	00 
     562:	48 89 8c 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rcx
     569:	00 
     56a:	0f 8f a9 01 00 00    	jg     719 <kprobe_unwind_hotspot+0x719>
     570:	81 fa 76 74 61 62    	cmp    edx,0x62617476
     576:	0f 84 dc 03 00 00    	je     958 <kprobe_unwind_hotspot+0x958>
     57c:	81 fa 49 6e 74 65    	cmp    edx,0x65746e49
     582:	0f 85 1c 03 00 00    	jne    8a4 <kprobe_unwind_hotspot+0x8a4>
     588:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
     58f:	00 
     590:	4c 39 e9             	cmp    rcx,r13
     593:	0f 82 5a 08 00 00    	jb     df3 <kprobe_unwind_hotspot+0xdf3>
     599:	49 8d 85 00 10 00 00 	lea    rax,[r13+0x1000]
     5a0:	48 39 c1             	cmp    rcx,rax
     5a3:	0f 83 4a 08 00 00    	jae    df3 <kprobe_unwind_hotspot+0xdf3>
     5a9:	48 8d 51 b0          	lea    rdx,[rcx-0x50]
     5ad:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
     5b2:	b8 60 00 00 00       	mov    eax,0x60
     5b7:	b9 70 00 00 00       	mov    ecx,0x70
     5bc:	be 60 00 00 00       	mov    esi,0x60
     5c1:	ff d1                	call   rcx
     5c3:	48 85 c0             	test   rax,rax
     5c6:	0f 84 1c 0c 00 00    	je     11e8 <kprobe_unwind_hotspot+0x11e8>
     5cc:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5d3 <kprobe_unwind_hotspot+0x5d3>
			5cf: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     5d3:	83 38 00             	cmp    DWORD PTR [rax],0x0
     5d6:	0f 84 27 08 00 00    	je     e03 <kprobe_unwind_hotspot+0xe03>
     5dc:	48 b8 20 66 72 61 6d 	movabs rax,0xa656d61726620
     5e3:	65 0a 00 
     5e6:	48 89 44 24 1f       	mov    QWORD PTR [rsp+0x1f],rax
     5eb:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
     5f2:	65 72 20 
     5f5:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
     5fa:	48 b8 65 61 64 20 69 	movabs rax,0x65746e6920646165
     601:	6e 74 65 
     604:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
     609:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
     610:	6f 20 72 
     613:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
     618:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
     61f:	66 61 69 
     622:	48 89 04 24          	mov    QWORD PTR [rsp],rax
     626:	31 c0                	xor    eax,eax
     628:	48 89 e1             	mov    rcx,rsp
     62b:	ba 27 00 00 00       	mov    edx,0x27
     630:	be 06 00 00 00       	mov    esi,0x6
     635:	e9 c9 07 00 00       	jmp    e03 <kprobe_unwind_hotspot+0xe03>
     63a:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     63d:	0f 85 4d 12 00 00    	jne    1890 <kprobe_unwind_hotspot+0x1890>
     643:	b8 eb 03 00 00       	mov    eax,0x3eb
     648:	e9 e6 fc ff ff       	jmp    333 <kprobe_unwind_hotspot+0x333>
     64d:	48 b8 20 25 64 20 3d 	movabs rax,0x3d3d3d3d20642520
     654:	3d 3d 3d 
     657:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
     65c:	48 b8 3a 20 75 6e 77 	movabs rax,0x646e69776e75203a
     663:	69 6e 64 
     666:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     66b:	48 b8 3d 3d 3d 3d 20 	movabs rax,0x6d766a203d3d3d3d
     672:	6a 76 6d 
     675:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     67a:	66 c7 44 24 58 0a 00 	mov    WORD PTR [rsp+0x58],0xa
     681:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
     688:	31 c9                	xor    ecx,ecx
     68a:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
     68f:	be 1a 00 00 00       	mov    esi,0x1a
     694:	bf 06 00 00 00       	mov    edi,0x6
     699:	e9 b6 f9 ff ff       	jmp    54 <kprobe_unwind_hotspot+0x54>
     69e:	48 b9 25 64 29 20 66 	movabs rcx,0x6c69616620296425
     6a5:	61 69 6c 
     6a8:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
     6ad:	48 b9 77 69 6e 64 65 	movabs rcx,0x28207265646e6977
     6b4:	72 20 28 
     6b7:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
     6bc:	48 b9 66 72 61 6d 65 	movabs rcx,0x6e7520656d617266
     6c3:	20 75 6e 
     6c6:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
     6cb:	48 b9 6f 72 20 6e 65 	movabs rcx,0x207478656e20726f
     6d2:	78 74 20 
     6d5:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
     6da:	48 b9 6c 20 63 61 6c 	movabs rcx,0x66206c6c6163206c
     6e1:	6c 20 66 
     6e4:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
     6e9:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x696174203a6d766a
     6f0:	74 61 69 
     6f3:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
     6f8:	c7 44 24 70 65 64 0a 	mov    DWORD PTR [rsp+0x70],0xa6465
     6ff:	00 
     700:	89 d9                	mov    ecx,ebx
     702:	31 d2                	xor    edx,edx
     704:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
     709:	bf 34 00 00 00       	mov    edi,0x34
     70e:	41 b8 06 00 00 00    	mov    r8d,0x6
     714:	e9 fb fc ff ff       	jmp    414 <kprobe_unwind_hotspot+0x414>
     719:	81 fa 6e 6d 65 74    	cmp    edx,0x74656d6e
     71f:	74 0c                	je     72d <kprobe_unwind_hotspot+0x72d>
     721:	81 fa 6e 61 74 69    	cmp    edx,0x6974616e
     727:	0f 85 77 01 00 00    	jne    8a4 <kprobe_unwind_hotspot+0x8a4>
     72d:	41 0f b6 ae 30 0f 00 	movzx  ebp,BYTE PTR [r14+0xf30]
     734:	00 
     735:	8b 8c 24 fc 00 00 00 	mov    ecx,DWORD PTR [rsp+0xfc]
     73c:	48 89 8c 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rcx
     743:	00 
     744:	48 8b 8c 24 e8 00 00 	mov    rcx,QWORD PTR [rsp+0xe8]
     74b:	00 
     74c:	89 ca                	mov    edx,ecx
     74e:	48 01 f2             	add    rdx,rsi
     751:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
     756:	48 0f 44 d1          	cmove  rdx,rcx
     75a:	48 39 d3             	cmp    rbx,rdx
     75d:	75 4b                	jne    7aa <kprobe_unwind_hotspot+0x7aa>
     75f:	8b 84 24 f4 00 00 00 	mov    eax,DWORD PTR [rsp+0xf4]
     766:	4c 01 e8             	add    rax,r13
     769:	48 89 e7             	mov    rdi,rsp
     76c:	b9 08 00 00 00       	mov    ecx,0x8
     771:	41 b8 70 00 00 00    	mov    r8d,0x70
     777:	8b 94 24 f4 00 00 00 	mov    edx,DWORD PTR [rsp+0xf4]
     77e:	4c 01 ea             	add    rdx,r13
     781:	be 08 00 00 00       	mov    esi,0x8
     786:	41 ff d0             	call   r8
     789:	48 85 c0             	test   rax,rax
     78c:	0f 84 06 08 00 00    	je     f98 <kprobe_unwind_hotspot+0xf98>
     792:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 799 <kprobe_unwind_hotspot+0x799>
			795: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     799:	83 38 00             	cmp    DWORD PTR [rax],0x0
     79c:	0f 85 14 19 00 00    	jne    20b6 <kprobe_unwind_hotspot+0x20b6>
     7a2:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
     7a9:	00 
     7aa:	0f b7 8c 24 00 01 00 	movzx  ecx,WORD PTR [rsp+0x100]
     7b1:	00 
     7b2:	48 01 c1             	add    rcx,rax
     7b5:	48 39 cb             	cmp    rbx,rcx
     7b8:	0f 83 1f 01 00 00    	jae    8dd <kprobe_unwind_hotspot+0x8dd>
     7be:	48 83 c1 fc          	add    rcx,0xfffffffffffffffc
     7c2:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7c9 <kprobe_unwind_hotspot+0x7c9>
			7c5: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     7c9:	8b 00                	mov    eax,DWORD PTR [rax]
     7cb:	48 39 cb             	cmp    rbx,rcx
     7ce:	0f 83 61 06 00 00    	jae    e35 <kprobe_unwind_hotspot+0xe35>
     7d4:	b1 03                	mov    cl,0x3
     7d6:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
     7dd:	85 c0                	test   eax,eax
     7df:	0f 84 93 01 00 00    	je     978 <kprobe_unwind_hotspot+0x978>
     7e5:	48 b8 61 6d 65 20 28 	movabs rax,0x2963702820656d61
     7ec:	70 63 29 
     7ef:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
     7f4:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
     7fb:	20 66 72 
     7fe:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
     803:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
     80a:	63 6f 6d 
     80d:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
     812:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
     819:	6e 64 69 
     81c:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     821:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
     828:	20 2d 3e 
     82b:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     830:	66 c7 44 24 68 0a 00 	mov    WORD PTR [rsp+0x68],0xa
     837:	31 c0                	xor    eax,eax
     839:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
     83e:	ba 2a 00 00 00       	mov    edx,0x2a
     843:	be 06 00 00 00       	mov    esi,0x6
     848:	e9 2b 01 00 00       	jmp    978 <kprobe_unwind_hotspot+0x978>
     84d:	48 b8 20 66 6f 72 20 	movabs rax,0xa637020726f6620
     854:	70 63 0a 
     857:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
     85c:	48 b8 20 6d 61 74 63 	movabs rax,0x6465686374616d20
     863:	68 65 64 
     866:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
     86b:	48 b8 63 6f 64 65 62 	movabs rax,0x626f6c6265646f63
     872:	6c 6f 62 
     875:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     87a:	48 b8 6a 76 6d 3a 20 	movabs rax,0x206f6e203a6d766a
     881:	6e 6f 20 
     884:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     889:	c6 44 24 60 00       	mov    BYTE PTR [rsp+0x60],0x0
     88e:	31 c0                	xor    eax,eax
     890:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
     895:	ba 21 00 00 00       	mov    edx,0x21
     89a:	be 06 00 00 00       	mov    esi,0x6
     89f:	e9 90 f9 ff ff       	jmp    234 <kprobe_unwind_hotspot+0x234>
     8a4:	48 89 94 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rdx
     8ab:	00 
     8ac:	83 7d 00 00          	cmp    DWORD PTR [rbp+0x0],0x0
     8b0:	0f 85 63 17 00 00    	jne    2019 <kprobe_unwind_hotspot+0x2019>
     8b6:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
     8bd:	c7 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],0x0
     8c4:	00 00 00 00 
     8c8:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
     8cf:	00 
     8d0:	85 c0                	test   eax,eax
     8d2:	0f 85 8b 05 00 00    	jne    e63 <kprobe_unwind_hotspot+0xe63>
     8d8:	e9 73 05 00 00       	jmp    e50 <kprobe_unwind_hotspot+0xe50>
     8dd:	40 84 ed             	test   bpl,bpl
     8e0:	75 21                	jne    903 <kprobe_unwind_hotspot+0x903>
     8e2:	48 8d 53 ff          	lea    rdx,[rbx-0x1]
     8e6:	48 89 e7             	mov    rdi,rsp
     8e9:	b8 0e 00 00 00       	mov    eax,0xe
     8ee:	b9 70 00 00 00       	mov    ecx,0x70
     8f3:	be 0e 00 00 00       	mov    esi,0xe
     8f8:	ff d1                	call   rcx
     8fa:	48 85 c0             	test   rax,rax
     8fd:	0f 84 de 09 00 00    	je     12e1 <kprobe_unwind_hotspot+0x12e1>
     903:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
     90a:	00 
     90b:	48 89 c8             	mov    rax,rcx
     90e:	8b ac 24 f8 00 00 00 	mov    ebp,DWORD PTR [rsp+0xf8]
     915:	48 8d 14 2d 30 00 00 	lea    rdx,[rbp*1+0x30]
     91c:	00 
     91d:	4c 01 ea             	add    rdx,r13
     920:	4c 29 e8             	sub    rax,r13
     923:	0f 82 d2 05 00 00    	jb     efb <kprobe_unwind_hotspot+0xefb>
     929:	48 39 d1             	cmp    rcx,rdx
     92c:	0f 83 c9 05 00 00    	jae    efb <kprobe_unwind_hotspot+0xefb>
     932:	b1 03                	mov    cl,0x3
     934:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
     93b:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 942 <kprobe_unwind_hotspot+0x942>
			93e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     942:	83 39 00             	cmp    DWORD PTR [rcx],0x0
     945:	0f 85 5b 1b 00 00    	jne    24a6 <kprobe_unwind_hotspot+0x24a6>
     94b:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
     952:	00 
     953:	e9 f1 04 00 00       	jmp    e49 <kprobe_unwind_hotspot+0xe49>
     958:	b0 01                	mov    al,0x1
     95a:	89 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],eax
     961:	b8 76 74 61 62       	mov    eax,0x62617476
     966:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
     96d:	00 
     96e:	83 7d 00 00          	cmp    DWORD PTR [rbp+0x0],0x0
     972:	0f 85 fb 16 00 00    	jne    2073 <kprobe_unwind_hotspot+0x2073>
     978:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x8
     97f:	08 00 00 00 
     983:	b8 08 00 00 00       	mov    eax,0x8
     988:	48 8b 2d 00 00 00 00 	mov    rbp,QWORD PTR [rip+0x0]        # 98f <kprobe_unwind_hotspot+0x98f>
			98b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     98f:	e9 cf 04 00 00       	jmp    e63 <kprobe_unwind_hotspot+0xe63>
     994:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
     99b:	64 0a 00 
     99e:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
     9a3:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
     9aa:	69 63 49 
     9ad:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
     9b2:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
     9b9:	66 6f 72 
     9bc:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
     9c1:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
     9c8:	69 63 73 
     9cb:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
     9d0:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
     9d7:	6b 75 70 
     9da:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     9df:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
     9e6:	64 20 74 
     9e9:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     9ee:	8b 84 24 d0 00 00 00 	mov    eax,DWORD PTR [rsp+0xd0]
     9f5:	31 c9                	xor    ecx,ecx
     9f7:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
     9fc:	be 2e 00 00 00       	mov    esi,0x2e
     a01:	bf 06 00 00 00       	mov    edi,0x6
     a06:	e9 a0 f6 ff ff       	jmp    ab <kprobe_unwind_hotspot+0xab>
     a0b:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
     a12:	75 0a 00 
     a15:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
     a1a:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
     a21:	74 61 67 
     a24:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
     a29:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
     a30:	6e 74 20 
     a33:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     a38:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
     a3f:	20 20 20 
     a42:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     a47:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     a4b:	31 c9                	xor    ecx,ecx
     a4d:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
     a52:	be 1d 00 00 00       	mov    esi,0x1d
     a57:	bf 06 00 00 00       	mov    edi,0x6
     a5c:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     a60:	8d 48 01             	lea    ecx,[rax+0x1]
     a63:	80 f9 02             	cmp    cl,0x2
     a66:	0f 82 11 f8 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     a6c:	0f b6 c0             	movzx  eax,al
     a6f:	48 29 c5             	sub    rbp,rax
     a72:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     a76:	48 89 e7             	mov    rdi,rsp
     a79:	b8 01 00 00 00       	mov    eax,0x1
     a7e:	b9 70 00 00 00       	mov    ecx,0x70
     a83:	be 01 00 00 00       	mov    esi,0x1
     a88:	ff d1                	call   rcx
     a8a:	48 85 c0             	test   rax,rax
     a8d:	0f 85 85 f7 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     a93:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # a9a <kprobe_unwind_hotspot+0xa9a>
			a96: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     a9a:	83 38 00             	cmp    DWORD PTR [rax],0x0
     a9d:	0f 85 68 07 00 00    	jne    120b <kprobe_unwind_hotspot+0x120b>
     aa3:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     aa7:	8d 48 01             	lea    ecx,[rax+0x1]
     aaa:	80 f9 02             	cmp    cl,0x2
     aad:	0f 82 ca f7 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     ab3:	0f b6 c0             	movzx  eax,al
     ab6:	48 29 c5             	sub    rbp,rax
     ab9:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     abd:	48 89 e7             	mov    rdi,rsp
     ac0:	b8 01 00 00 00       	mov    eax,0x1
     ac5:	b9 70 00 00 00       	mov    ecx,0x70
     aca:	be 01 00 00 00       	mov    esi,0x1
     acf:	ff d1                	call   rcx
     ad1:	48 85 c0             	test   rax,rax
     ad4:	0f 85 3e f7 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     ada:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # ae1 <kprobe_unwind_hotspot+0xae1>
			add: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     ae1:	83 38 00             	cmp    DWORD PTR [rax],0x0
     ae4:	0f 85 19 0e 00 00    	jne    1903 <kprobe_unwind_hotspot+0x1903>
     aea:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     aee:	8d 48 01             	lea    ecx,[rax+0x1]
     af1:	80 f9 02             	cmp    cl,0x2
     af4:	0f 82 83 f7 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     afa:	0f b6 c0             	movzx  eax,al
     afd:	48 29 c5             	sub    rbp,rax
     b00:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     b04:	48 89 e7             	mov    rdi,rsp
     b07:	b8 01 00 00 00       	mov    eax,0x1
     b0c:	b9 70 00 00 00       	mov    ecx,0x70
     b11:	be 01 00 00 00       	mov    esi,0x1
     b16:	ff d1                	call   rcx
     b18:	48 85 c0             	test   rax,rax
     b1b:	0f 85 f7 f6 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     b21:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # b28 <kprobe_unwind_hotspot+0xb28>
			b24: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     b28:	83 38 00             	cmp    DWORD PTR [rax],0x0
     b2b:	0f 85 99 0f 00 00    	jne    1aca <kprobe_unwind_hotspot+0x1aca>
     b31:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     b35:	8d 48 01             	lea    ecx,[rax+0x1]
     b38:	80 f9 02             	cmp    cl,0x2
     b3b:	0f 82 3c f7 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     b41:	0f b6 c0             	movzx  eax,al
     b44:	48 29 c5             	sub    rbp,rax
     b47:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     b4b:	48 89 e7             	mov    rdi,rsp
     b4e:	b8 01 00 00 00       	mov    eax,0x1
     b53:	b9 70 00 00 00       	mov    ecx,0x70
     b58:	be 01 00 00 00       	mov    esi,0x1
     b5d:	ff d1                	call   rcx
     b5f:	48 85 c0             	test   rax,rax
     b62:	0f 85 b0 f6 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     b68:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # b6f <kprobe_unwind_hotspot+0xb6f>
			b6b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     b6f:	83 38 00             	cmp    DWORD PTR [rax],0x0
     b72:	0f 85 1f 11 00 00    	jne    1c97 <kprobe_unwind_hotspot+0x1c97>
     b78:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     b7c:	8d 48 01             	lea    ecx,[rax+0x1]
     b7f:	80 f9 02             	cmp    cl,0x2
     b82:	0f 82 f5 f6 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     b88:	0f b6 c0             	movzx  eax,al
     b8b:	48 29 c5             	sub    rbp,rax
     b8e:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     b92:	48 89 e7             	mov    rdi,rsp
     b95:	b8 01 00 00 00       	mov    eax,0x1
     b9a:	b9 70 00 00 00       	mov    ecx,0x70
     b9f:	be 01 00 00 00       	mov    esi,0x1
     ba4:	ff d1                	call   rcx
     ba6:	48 85 c0             	test   rax,rax
     ba9:	0f 85 69 f6 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     baf:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # bb6 <kprobe_unwind_hotspot+0xbb6>
			bb2: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     bb6:	83 38 00             	cmp    DWORD PTR [rax],0x0
     bb9:	0f 85 26 18 00 00    	jne    23e5 <kprobe_unwind_hotspot+0x23e5>
     bbf:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     bc3:	8d 48 01             	lea    ecx,[rax+0x1]
     bc6:	80 f9 02             	cmp    cl,0x2
     bc9:	0f 82 ae f6 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     bcf:	0f b6 c0             	movzx  eax,al
     bd2:	48 29 c5             	sub    rbp,rax
     bd5:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     bd9:	48 89 e7             	mov    rdi,rsp
     bdc:	b8 01 00 00 00       	mov    eax,0x1
     be1:	b9 70 00 00 00       	mov    ecx,0x70
     be6:	be 01 00 00 00       	mov    esi,0x1
     beb:	ff d1                	call   rcx
     bed:	48 85 c0             	test   rax,rax
     bf0:	0f 85 22 f6 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     bf6:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # bfd <kprobe_unwind_hotspot+0xbfd>
			bf9: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     bfd:	83 38 00             	cmp    DWORD PTR [rax],0x0
     c00:	0f 85 5f 1d 00 00    	jne    2965 <kprobe_unwind_hotspot+0x2965>
     c06:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     c0a:	8d 48 01             	lea    ecx,[rax+0x1]
     c0d:	80 f9 02             	cmp    cl,0x2
     c10:	0f 82 67 f6 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     c16:	0f b6 c0             	movzx  eax,al
     c19:	48 29 c5             	sub    rbp,rax
     c1c:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     c20:	48 89 e7             	mov    rdi,rsp
     c23:	b8 01 00 00 00       	mov    eax,0x1
     c28:	b9 70 00 00 00       	mov    ecx,0x70
     c2d:	be 01 00 00 00       	mov    esi,0x1
     c32:	ff d1                	call   rcx
     c34:	48 85 c0             	test   rax,rax
     c37:	0f 85 db f5 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     c3d:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # c44 <kprobe_unwind_hotspot+0xc44>
			c40: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     c44:	83 38 00             	cmp    DWORD PTR [rax],0x0
     c47:	0f 85 60 2e 00 00    	jne    3aad <kprobe_unwind_hotspot+0x3aad>
     c4d:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     c51:	8d 48 01             	lea    ecx,[rax+0x1]
     c54:	80 f9 02             	cmp    cl,0x2
     c57:	0f 82 20 f6 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     c5d:	0f b6 c0             	movzx  eax,al
     c60:	48 29 c5             	sub    rbp,rax
     c63:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     c67:	48 89 e7             	mov    rdi,rsp
     c6a:	b8 01 00 00 00       	mov    eax,0x1
     c6f:	b9 70 00 00 00       	mov    ecx,0x70
     c74:	be 01 00 00 00       	mov    esi,0x1
     c79:	ff d1                	call   rcx
     c7b:	48 85 c0             	test   rax,rax
     c7e:	0f 85 94 f5 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     c84:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # c8b <kprobe_unwind_hotspot+0xc8b>
			c87: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     c8b:	83 38 00             	cmp    DWORD PTR [rax],0x0
     c8e:	0f 85 44 32 00 00    	jne    3ed8 <kprobe_unwind_hotspot+0x3ed8>
     c94:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     c98:	8d 48 01             	lea    ecx,[rax+0x1]
     c9b:	80 f9 02             	cmp    cl,0x2
     c9e:	0f 82 d9 f5 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     ca4:	0f b6 c0             	movzx  eax,al
     ca7:	48 29 c5             	sub    rbp,rax
     caa:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     cae:	48 89 e7             	mov    rdi,rsp
     cb1:	b8 01 00 00 00       	mov    eax,0x1
     cb6:	b9 70 00 00 00       	mov    ecx,0x70
     cbb:	be 01 00 00 00       	mov    esi,0x1
     cc0:	ff d1                	call   rcx
     cc2:	48 85 c0             	test   rax,rax
     cc5:	0f 85 4d f5 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     ccb:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # cd2 <kprobe_unwind_hotspot+0xcd2>
			cce: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     cd2:	83 38 00             	cmp    DWORD PTR [rax],0x0
     cd5:	0f 85 4c 35 00 00    	jne    4227 <kprobe_unwind_hotspot+0x4227>
     cdb:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     cdf:	8d 48 01             	lea    ecx,[rax+0x1]
     ce2:	80 f9 02             	cmp    cl,0x2
     ce5:	0f 82 92 f5 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     ceb:	0f b6 c0             	movzx  eax,al
     cee:	48 29 c5             	sub    rbp,rax
     cf1:	49 8d 14 2c          	lea    rdx,[r12+rbp*1]
     cf5:	48 89 e7             	mov    rdi,rsp
     cf8:	b8 01 00 00 00       	mov    eax,0x1
     cfd:	b9 70 00 00 00       	mov    ecx,0x70
     d02:	be 01 00 00 00       	mov    esi,0x1
     d07:	ff d1                	call   rcx
     d09:	48 85 c0             	test   rax,rax
     d0c:	0f 85 06 f5 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     d12:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # d19 <kprobe_unwind_hotspot+0xd19>
			d15: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     d19:	83 38 00             	cmp    DWORD PTR [rax],0x0
     d1c:	0f 85 4f 3a 00 00    	jne    4771 <kprobe_unwind_hotspot+0x4771>
     d22:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     d26:	8d 48 01             	lea    ecx,[rax+0x1]
     d29:	80 f9 02             	cmp    cl,0x2
     d2c:	0f 82 4b f5 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
     d32:	0f b6 c0             	movzx  eax,al
     d35:	48 29 c5             	sub    rbp,rax
     d38:	49 01 ec             	add    r12,rbp
     d3b:	48 89 e7             	mov    rdi,rsp
     d3e:	b8 01 00 00 00       	mov    eax,0x1
     d43:	b9 70 00 00 00       	mov    ecx,0x70
     d48:	be 01 00 00 00       	mov    esi,0x1
     d4d:	4c 89 e2             	mov    rdx,r12
     d50:	ff d1                	call   rcx
     d52:	48 85 c0             	test   rax,rax
     d55:	0f 85 bd f4 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
     d5b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # d62 <kprobe_unwind_hotspot+0xd62>
			d5e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     d62:	83 38 00             	cmp    DWORD PTR [rax],0x0
     d65:	0f 85 0d 3d 00 00    	jne    4a78 <kprobe_unwind_hotspot+0x4a78>
     d6b:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
     d6f:	8d 48 01             	lea    ecx,[rax+0x1]
     d72:	80 f9 01             	cmp    cl,0x1
     d75:	0f 87 9d f4 ff ff    	ja     218 <kprobe_unwind_hotspot+0x218>
     d7b:	e9 fd f4 ff ff       	jmp    27d <kprobe_unwind_hotspot+0x27d>
     d80:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
     d87:	64 0a 00 
     d8a:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
     d8f:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
     d96:	69 63 49 
     d99:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
     d9e:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
     da5:	66 6f 72 
     da8:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
     dad:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
     db4:	69 63 73 
     db7:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
     dbc:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
     dc3:	6b 75 70 
     dc6:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
     dcb:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
     dd2:	64 20 74 
     dd5:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
     dda:	8b 04 24             	mov    eax,DWORD PTR [rsp]
     ddd:	31 c9                	xor    ecx,ecx
     ddf:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
     de4:	be 2e 00 00 00       	mov    esi,0x2e
     de9:	bf 06 00 00 00       	mov    edi,0x6
     dee:	e9 3b f5 ff ff       	jmp    32e <kprobe_unwind_hotspot+0x32e>
     df3:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # dfa <kprobe_unwind_hotspot+0xdfa>
			df6: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     dfa:	83 38 00             	cmp    DWORD PTR [rax],0x0
     dfd:	0f 85 05 15 00 00    	jne    2308 <kprobe_unwind_hotspot+0x2308>
     e03:	c7 84 24 14 01 00 00 	mov    DWORD PTR [rsp+0x114],0x2d
     e0a:	2d 00 00 00 
     e0e:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # e15 <kprobe_unwind_hotspot+0xe15>
			e11: R_X86_64_REX_GOTPCRELX	metrics-0x4
     e15:	48 8d b4 24 14 01 00 	lea    rsi,[rsp+0x114]
     e1c:	00 
     e1d:	b8 01 00 00 00       	mov    eax,0x1
     e22:	ff d0                	call   rax
     e24:	48 85 c0             	test   rax,rax
     e27:	0f 84 b2 01 00 00    	je     fdf <kprobe_unwind_hotspot+0xfdf>
     e2d:	48 ff 00             	inc    QWORD PTR [rax]
     e30:	e9 ba 01 00 00       	jmp    fef <kprobe_unwind_hotspot+0xfef>
     e35:	b1 03                	mov    cl,0x3
     e37:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
     e3e:	85 c0                	test   eax,eax
     e40:	0f 85 2f 15 00 00    	jne    2375 <kprobe_unwind_hotspot+0x2375>
     e46:	4c 89 e9             	mov    rcx,r13
     e49:	48 8b 2d 00 00 00 00 	mov    rbp,QWORD PTR [rip+0x0]        # e50 <kprobe_unwind_hotspot+0xe50>
			e4c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     e50:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x10
     e57:	10 00 00 00 
     e5b:	b8 10 00 00 00       	mov    eax,0x10
     e60:	49 89 cd             	mov    r13,rcx
     e63:	89 c0                	mov    eax,eax
     e65:	49 01 c5             	add    r13,rax
     e68:	49 8d 55 f0          	lea    rdx,[r13-0x10]
     e6c:	48 89 e7             	mov    rdi,rsp
     e6f:	b8 10 00 00 00       	mov    eax,0x10
     e74:	b9 70 00 00 00       	mov    ecx,0x70
     e79:	be 10 00 00 00       	mov    esi,0x10
     e7e:	ff d1                	call   rcx
     e80:	48 8b 5c 24 08       	mov    rbx,QWORD PTR [rsp+0x8]
     e85:	83 bc 24 f8 00 00 00 	cmp    DWORD PTR [rsp+0xf8],0x10
     e8c:	10 
     e8d:	48 8b bc 24 a8 00 00 	mov    rdi,QWORD PTR [rsp+0xa8]
     e94:	00 
     e95:	72 0e                	jb     ea5 <kprobe_unwind_hotspot+0xea5>
     e97:	83 7d 00 00          	cmp    DWORD PTR [rbp+0x0],0x0
     e9b:	0f 85 15 0f 00 00    	jne    1db6 <kprobe_unwind_hotspot+0x1db6>
     ea1:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
     ea5:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
     eac:	48 83 f8 7f          	cmp    rax,0x7f
     eb0:	0f 82 0f 07 00 00    	jb     15c5 <kprobe_unwind_hotspot+0x15c5>
     eb6:	48 8b 1d 00 00 00 00 	mov    rbx,QWORD PTR [rip+0x0]        # ebd <kprobe_unwind_hotspot+0xebd>
			eb9: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     ebd:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     ec0:	0f 85 37 0e 00 00    	jne    1cfd <kprobe_unwind_hotspot+0x1cfd>
     ec6:	c7 04 24 02 00 00 00 	mov    DWORD PTR [rsp],0x2
     ecd:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # ed4 <kprobe_unwind_hotspot+0xed4>
			ed0: R_X86_64_REX_GOTPCRELX	metrics-0x4
     ed4:	48 89 e6             	mov    rsi,rsp
     ed7:	b8 01 00 00 00       	mov    eax,0x1
     edc:	ff d0                	call   rax
     ede:	48 85 c0             	test   rax,rax
     ee1:	74 05                	je     ee8 <kprobe_unwind_hotspot+0xee8>
     ee3:	48 ff 00             	inc    QWORD PTR [rax]
     ee6:	eb 09                	jmp    ef1 <kprobe_unwind_hotspot+0xef1>
     ee8:	83 3b 00             	cmp    DWORD PTR [rbx],0x0
     eeb:	0f 85 35 12 00 00    	jne    2126 <kprobe_unwind_hotspot+0x2126>
     ef1:	b8 02 00 00 00       	mov    eax,0x2
     ef6:	e9 38 f4 ff ff       	jmp    333 <kprobe_unwind_hotspot+0x333>
     efb:	48 89 94 24 18 01 00 	mov    QWORD PTR [rsp+0x118],rdx
     f02:	00 
     f03:	48 8d 14 2d f8 ff ff 	lea    rdx,[rbp*1-0x8]
     f0a:	ff 
     f0b:	4c 01 ea             	add    rdx,r13
     f0e:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
     f13:	b8 30 00 00 00       	mov    eax,0x30
     f18:	b9 70 00 00 00       	mov    ecx,0x70
     f1d:	be 30 00 00 00       	mov    esi,0x30
     f22:	ff d1                	call   rcx
     f24:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # f2b <kprobe_unwind_hotspot+0xf2b>
			f27: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     f2b:	83 38 00             	cmp    DWORD PTR [rax],0x0
     f2e:	0f 85 17 15 00 00    	jne    244b <kprobe_unwind_hotspot+0x244b>
     f34:	41 8b 06             	mov    eax,DWORD PTR [r14]
     f37:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
     f3e:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
     f44:	49 01 ed             	add    r13,rbp
     f47:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
     f4c:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
     f53:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # f5a <kprobe_unwind_hotspot+0xf5a>
			f56: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
     f5a:	48 89 e6             	mov    rsi,rsp
     f5d:	b8 01 00 00 00       	mov    eax,0x1
     f62:	ff d0                	call   rax
     f64:	48 85 c0             	test   rax,rax
     f67:	0f 84 ac 00 00 00    	je     1019 <kprobe_unwind_hotspot+0x1019>
     f6d:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
     f71:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
     f78:	00 00 ff 
     f7b:	48 21 c8             	and    rax,rcx
     f7e:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
     f85:	00 00 02 
     f88:	48 39 c8             	cmp    rax,rcx
     f8b:	0f 85 88 00 00 00    	jne    1019 <kprobe_unwind_hotspot+0x1019>
     f91:	31 ed                	xor    ebp,ebp
     f93:	e9 89 05 00 00       	jmp    1521 <kprobe_unwind_hotspot+0x1521>
     f98:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
     f9c:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
     fa3:	00 
     fa4:	48 39 c8             	cmp    rax,rcx
     fa7:	0f 82 e5 f7 ff ff    	jb     792 <kprobe_unwind_hotspot+0x792>
     fad:	48 3b 84 24 e0 00 00 	cmp    rax,QWORD PTR [rsp+0xe0]
     fb4:	00 
     fb5:	0f 83 d7 f7 ff ff    	jae    792 <kprobe_unwind_hotspot+0x792>
     fbb:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # fc2 <kprobe_unwind_hotspot+0xfc2>
			fbe: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     fc2:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
     fc5:	0f 85 35 18 00 00    	jne    2800 <kprobe_unwind_hotspot+0x2800>
     fcb:	89 c2                	mov    edx,eax
     fcd:	29 ca                	sub    edx,ecx
     fcf:	48 89 94 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rdx
     fd6:	00 
     fd7:	48 89 c3             	mov    rbx,rax
     fda:	e9 c3 f7 ff ff       	jmp    7a2 <kprobe_unwind_hotspot+0x7a2>
     fdf:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # fe6 <kprobe_unwind_hotspot+0xfe6>
			fe2: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
     fe6:	83 38 00             	cmp    DWORD PTR [rax],0x0
     fe9:	0f 85 94 15 00 00    	jne    2583 <kprobe_unwind_hotspot+0x2583>
     fef:	b8 e9 03 00 00       	mov    eax,0x3e9
     ff4:	31 c9                	xor    ecx,ecx
     ff6:	ba 49 6e 74 65       	mov    edx,0x65746e49
     ffb:	48 89 94 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rdx
    1002:	00 
    1003:	b2 02                	mov    dl,0x2
    1005:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    100c:	85 c0                	test   eax,eax
    100e:	0f 85 1f f3 ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    1014:	e9 40 05 00 00       	jmp    1559 <kprobe_unwind_hotspot+0x1559>
    1019:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1020 <kprobe_unwind_hotspot+0x1020>
			101c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1020:	83 38 00             	cmp    DWORD PTR [rax],0x0
    1023:	0f 85 20 16 00 00    	jne    2649 <kprobe_unwind_hotspot+0x2649>
    1029:	41 8b 06             	mov    eax,DWORD PTR [r14]
    102c:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    1033:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    1039:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    103e:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    1045:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 104c <kprobe_unwind_hotspot+0x104c>
			1048: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    104c:	48 89 e6             	mov    rsi,rsp
    104f:	bd 01 00 00 00       	mov    ebp,0x1
    1054:	b8 01 00 00 00       	mov    eax,0x1
    1059:	ff d0                	call   rax
    105b:	48 85 c0             	test   rax,rax
    105e:	0f 84 0c 01 00 00    	je     1170 <kprobe_unwind_hotspot+0x1170>
    1064:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    1068:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    106f:	00 00 ff 
    1072:	48 21 c8             	and    rax,rcx
    1075:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    107c:	00 00 02 
    107f:	48 39 c8             	cmp    rax,rcx
    1082:	0f 85 e8 00 00 00    	jne    1170 <kprobe_unwind_hotspot+0x1170>
    1088:	49 83 c5 08          	add    r13,0x8
    108c:	e9 90 04 00 00       	jmp    1521 <kprobe_unwind_hotspot+0x1521>
    1091:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    1098:	64 0a 00 
    109b:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    10a0:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    10a7:	69 63 49 
    10aa:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    10af:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    10b6:	66 6f 72 
    10b9:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    10be:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    10c5:	69 63 73 
    10c8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    10cd:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    10d4:	6b 75 70 
    10d7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    10dc:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    10e3:	64 20 74 
    10e6:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    10eb:	8b 84 24 d0 00 00 00 	mov    eax,DWORD PTR [rsp+0xd0]
    10f2:	31 c9                	xor    ecx,ecx
    10f4:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    10f9:	be 2e 00 00 00       	mov    esi,0x2e
    10fe:	bf 06 00 00 00       	mov    edi,0x6
    1103:	e9 cd f2 ff ff       	jmp    3d5 <kprobe_unwind_hotspot+0x3d5>
    1108:	48 b9 6c 6f 62 20 25 	movabs rcx,0xa786c2520626f6c
    110f:	6c 78 0a 
    1112:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    1117:	48 b9 74 6f 20 63 6f 	movabs rcx,0x6265646f63206f74
    111e:	64 65 62 
    1121:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    1126:	48 b9 20 6d 61 70 70 	movabs rcx,0x2064657070616d20
    112d:	65 64 20 
    1130:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    1135:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    113c:	20 2d 3e 
    113f:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    1144:	c6 44 24 60 00       	mov    BYTE PTR [rsp+0x60],0x0
    1149:	31 c9                	xor    ecx,ecx
    114b:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1150:	be 21 00 00 00       	mov    esi,0x21
    1155:	bf 06 00 00 00       	mov    edi,0x6
    115a:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    1161:	00 
    1162:	48 85 c0             	test   rax,rax
    1165:	0f 85 50 f1 ff ff    	jne    2bb <kprobe_unwind_hotspot+0x2bb>
    116b:	e9 b4 f0 ff ff       	jmp    224 <kprobe_unwind_hotspot+0x224>
    1170:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1177 <kprobe_unwind_hotspot+0x1177>
			1173: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1177:	83 38 00             	cmp    DWORD PTR [rax],0x0
    117a:	0f 85 2a 15 00 00    	jne    26aa <kprobe_unwind_hotspot+0x26aa>
    1180:	41 8b 06             	mov    eax,DWORD PTR [r14]
    1183:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    118a:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    1190:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    1195:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    119c:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 11a3 <kprobe_unwind_hotspot+0x11a3>
			119f: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    11a3:	48 89 e6             	mov    rsi,rsp
    11a6:	b8 01 00 00 00       	mov    eax,0x1
    11ab:	ff d0                	call   rax
    11ad:	48 85 c0             	test   rax,rax
    11b0:	0f 84 bb 00 00 00    	je     1271 <kprobe_unwind_hotspot+0x1271>
    11b6:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    11ba:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    11c1:	00 00 ff 
    11c4:	48 21 c8             	and    rax,rcx
    11c7:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    11ce:	00 00 02 
    11d1:	48 39 c8             	cmp    rax,rcx
    11d4:	0f 85 97 00 00 00    	jne    1271 <kprobe_unwind_hotspot+0x1271>
    11da:	49 83 c5 10          	add    r13,0x10
    11de:	bd 02 00 00 00       	mov    ebp,0x2
    11e3:	e9 39 03 00 00       	jmp    1521 <kprobe_unwind_hotspot+0x1521>
    11e8:	41 83 be c0 02 00 00 	cmp    DWORD PTR [r14+0x2c0],0x0
    11ef:	00 
    11f0:	0f 84 af 02 00 00    	je     14a5 <kprobe_unwind_hotspot+0x14a5>
    11f6:	41 80 7f 1f 00       	cmp    BYTE PTR [r15+0x1f],0x0
    11fb:	0f 84 32 05 00 00    	je     1733 <kprobe_unwind_hotspot+0x1733>
    1201:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    1206:	e9 2d 05 00 00       	jmp    1738 <kprobe_unwind_hotspot+0x1738>
    120b:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    1212:	75 0a 00 
    1215:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    121a:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    1221:	74 61 67 
    1224:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1229:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    1230:	6e 74 20 
    1233:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1238:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    123f:	20 20 20 
    1242:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1247:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    124b:	31 c9                	xor    ecx,ecx
    124d:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1252:	be 1d 00 00 00       	mov    esi,0x1d
    1257:	bf 06 00 00 00       	mov    edi,0x6
    125c:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1260:	8d 48 01             	lea    ecx,[rax+0x1]
    1263:	80 f9 02             	cmp    cl,0x2
    1266:	0f 82 11 f0 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    126c:	e9 42 f8 ff ff       	jmp    ab3 <kprobe_unwind_hotspot+0xab3>
    1271:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1278 <kprobe_unwind_hotspot+0x1278>
			1274: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1278:	83 38 00             	cmp    DWORD PTR [rax],0x0
    127b:	0f 85 22 16 00 00    	jne    28a3 <kprobe_unwind_hotspot+0x28a3>
    1281:	41 8b 06             	mov    eax,DWORD PTR [r14]
    1284:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    128b:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    1291:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    1296:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    129d:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 12a4 <kprobe_unwind_hotspot+0x12a4>
			12a0: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    12a4:	48 89 e6             	mov    rsi,rsp
    12a7:	b8 01 00 00 00       	mov    eax,0x1
    12ac:	ff d0                	call   rax
    12ae:	48 85 c0             	test   rax,rax
    12b1:	74 5e                	je     1311 <kprobe_unwind_hotspot+0x1311>
    12b3:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    12b7:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    12be:	00 00 ff 
    12c1:	48 21 c8             	and    rax,rcx
    12c4:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    12cb:	00 00 02 
    12ce:	48 39 c8             	cmp    rax,rcx
    12d1:	75 3e                	jne    1311 <kprobe_unwind_hotspot+0x1311>
    12d3:	49 83 c5 18          	add    r13,0x18
    12d7:	bd 03 00 00 00       	mov    ebp,0x3
    12dc:	e9 40 02 00 00       	jmp    1521 <kprobe_unwind_hotspot+0x1521>
    12e1:	0f b6 44 24 01       	movzx  eax,BYTE PTR [rsp+0x1]
    12e6:	3c c3                	cmp    al,0xc3
    12e8:	0f 85 ed 00 00 00    	jne    13db <kprobe_unwind_hotspot+0x13db>
    12ee:	b9 01 00 00 00       	mov    ecx,0x1
    12f3:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 12fa <kprobe_unwind_hotspot+0x12fa>
			12f6: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    12fa:	83 38 00             	cmp    DWORD PTR [rax],0x0
    12fd:	0f 85 c8 16 00 00    	jne    29cb <kprobe_unwind_hotspot+0x29cb>
    1303:	b0 03                	mov    al,0x3
    1305:	89 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],eax
    130c:	e9 48 02 00 00       	jmp    1559 <kprobe_unwind_hotspot+0x1559>
    1311:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1318 <kprobe_unwind_hotspot+0x1318>
			1314: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1318:	83 38 00             	cmp    DWORD PTR [rax],0x0
    131b:	0f 85 e3 15 00 00    	jne    2904 <kprobe_unwind_hotspot+0x2904>
    1321:	41 8b 06             	mov    eax,DWORD PTR [r14]
    1324:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    132b:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    1331:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    1336:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    133d:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 1344 <kprobe_unwind_hotspot+0x1344>
			1340: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    1344:	48 89 e6             	mov    rsi,rsp
    1347:	b8 01 00 00 00       	mov    eax,0x1
    134c:	ff d0                	call   rax
    134e:	48 85 c0             	test   rax,rax
    1351:	0f 84 5a 01 00 00    	je     14b1 <kprobe_unwind_hotspot+0x14b1>
    1357:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    135b:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    1362:	00 00 ff 
    1365:	48 21 c8             	and    rax,rcx
    1368:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    136f:	00 00 02 
    1372:	48 39 c8             	cmp    rax,rcx
    1375:	0f 85 36 01 00 00    	jne    14b1 <kprobe_unwind_hotspot+0x14b1>
    137b:	49 83 c5 20          	add    r13,0x20
    137f:	bd 04 00 00 00       	mov    ebp,0x4
    1384:	e9 98 01 00 00       	jmp    1521 <kprobe_unwind_hotspot+0x1521>
    1389:	48 b8 64 65 62 6c 6f 	movabs rax,0xa626f6c626564
    1390:	62 0a 00 
    1393:	48 89 44 24 56       	mov    QWORD PTR [rsp+0x56],rax
    1398:	48 b8 65 61 64 20 63 	movabs rax,0x65646f6320646165
    139f:	6f 64 65 
    13a2:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    13a7:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    13ae:	6f 20 72 
    13b1:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    13b6:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    13bd:	66 61 69 
    13c0:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    13c5:	31 c0                	xor    eax,eax
    13c7:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    13cc:	ba 1e 00 00 00       	mov    edx,0x1e
    13d1:	be 06 00 00 00       	mov    esi,0x6
    13d6:	e9 21 ef ff ff       	jmp    2fc <kprobe_unwind_hotspot+0x2fc>
    13db:	0f b6 4c 24 02       	movzx  ecx,BYTE PTR [rsp+0x2]
    13e0:	80 f9 c3             	cmp    cl,0xc3
    13e3:	74 51                	je     1436 <kprobe_unwind_hotspot+0x1436>
    13e5:	80 7c 24 03 c3       	cmp    BYTE PTR [rsp+0x3],0xc3
    13ea:	74 4a                	je     1436 <kprobe_unwind_hotspot+0x1436>
    13ec:	80 7c 24 04 c3       	cmp    BYTE PTR [rsp+0x4],0xc3
    13f1:	74 43                	je     1436 <kprobe_unwind_hotspot+0x1436>
    13f3:	80 7c 24 05 c3       	cmp    BYTE PTR [rsp+0x5],0xc3
    13f8:	74 3c                	je     1436 <kprobe_unwind_hotspot+0x1436>
    13fa:	80 7c 24 06 c3       	cmp    BYTE PTR [rsp+0x6],0xc3
    13ff:	74 35                	je     1436 <kprobe_unwind_hotspot+0x1436>
    1401:	80 7c 24 07 c3       	cmp    BYTE PTR [rsp+0x7],0xc3
    1406:	74 2e                	je     1436 <kprobe_unwind_hotspot+0x1436>
    1408:	80 7c 24 08 c3       	cmp    BYTE PTR [rsp+0x8],0xc3
    140d:	74 27                	je     1436 <kprobe_unwind_hotspot+0x1436>
    140f:	80 7c 24 09 c3       	cmp    BYTE PTR [rsp+0x9],0xc3
    1414:	74 20                	je     1436 <kprobe_unwind_hotspot+0x1436>
    1416:	80 7c 24 0a c3       	cmp    BYTE PTR [rsp+0xa],0xc3
    141b:	74 19                	je     1436 <kprobe_unwind_hotspot+0x1436>
    141d:	80 7c 24 0b c3       	cmp    BYTE PTR [rsp+0xb],0xc3
    1422:	74 12                	je     1436 <kprobe_unwind_hotspot+0x1436>
    1424:	80 7c 24 0c c3       	cmp    BYTE PTR [rsp+0xc],0xc3
    1429:	74 0b                	je     1436 <kprobe_unwind_hotspot+0x1436>
    142b:	80 7c 24 0d c3       	cmp    BYTE PTR [rsp+0xd],0xc3
    1430:	0f 85 cd f4 ff ff    	jne    903 <kprobe_unwind_hotspot+0x903>
    1436:	3c 5d                	cmp    al,0x5d
    1438:	0f 85 47 05 00 00    	jne    1985 <kprobe_unwind_hotspot+0x1985>
    143e:	b9 03 00 00 00       	mov    ecx,0x3
    1443:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 144a <kprobe_unwind_hotspot+0x144a>
			1446: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    144a:	83 38 00             	cmp    DWORD PTR [rax],0x0
    144d:	0f 84 b0 fe ff ff    	je     1303 <kprobe_unwind_hotspot+0x1303>
    1453:	48 b8 70 20 72 62 70 	movabs rax,0xa277062722070
    145a:	27 0a 00 
    145d:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    1462:	48 b8 65 20 6f 6e 20 	movabs rax,0x6f7027206e6f2065
    1469:	27 70 6f 
    146c:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1471:	48 b8 20 65 70 69 6c 	movabs rax,0x75676f6c69706520
    1478:	6f 67 75 
    147b:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1480:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    1487:	20 2d 3e 
    148a:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    148f:	31 c0                	xor    eax,eax
    1491:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1496:	be 20 00 00 00       	mov    esi,0x20
    149b:	bf 06 00 00 00       	mov    edi,0x6
    14a0:	e9 5e fe ff ff       	jmp    1303 <kprobe_unwind_hotspot+0x1303>
    14a5:	49 8b 86 00 0f 00 00 	mov    rax,QWORD PTR [r14+0xf00]
    14ac:	e9 87 02 00 00       	jmp    1738 <kprobe_unwind_hotspot+0x1738>
    14b1:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 14b8 <kprobe_unwind_hotspot+0x14b8>
			14b4: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    14b8:	83 38 00             	cmp    DWORD PTR [rax],0x0
    14bb:	0f 85 e7 15 00 00    	jne    2aa8 <kprobe_unwind_hotspot+0x2aa8>
    14c1:	41 8b 06             	mov    eax,DWORD PTR [r14]
    14c4:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    14cb:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    14d1:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    14d6:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    14dd:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 14e4 <kprobe_unwind_hotspot+0x14e4>
			14e0: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    14e4:	48 89 e6             	mov    rsi,rsp
    14e7:	b8 01 00 00 00       	mov    eax,0x1
    14ec:	ff d0                	call   rax
    14ee:	48 85 c0             	test   rax,rax
    14f1:	0f 84 0a 02 00 00    	je     1701 <kprobe_unwind_hotspot+0x1701>
    14f7:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    14fe:	00 00 ff 
    1501:	48 23 48 08          	and    rcx,QWORD PTR [rax+0x8]
    1505:	48 b8 00 00 00 00 00 	movabs rax,0x200000000000000
    150c:	00 00 02 
    150f:	48 39 c1             	cmp    rcx,rax
    1512:	0f 85 e9 01 00 00    	jne    1701 <kprobe_unwind_hotspot+0x1701>
    1518:	49 83 c5 28          	add    r13,0x28
    151c:	bd 05 00 00 00       	mov    ebp,0x5
    1521:	31 c0                	xor    eax,eax
    1523:	b9 05 00 00 00       	mov    ecx,0x5
    1528:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # 152f <kprobe_unwind_hotspot+0x152f>
			152b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    152f:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
    1532:	0f 85 de 0f 00 00    	jne    2516 <kprobe_unwind_hotspot+0x2516>
    1538:	4c 89 ac 24 18 01 00 	mov    QWORD PTR [rsp+0x118],r13
    153f:	00 
    1540:	b2 03                	mov    dl,0x3
    1542:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    1549:	4c 8b ac 24 18 01 00 	mov    r13,QWORD PTR [rsp+0x118]
    1550:	00 
    1551:	85 c0                	test   eax,eax
    1553:	0f 85 da ed ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    1559:	83 f9 06             	cmp    ecx,0x6
    155c:	77 23                	ja     1581 <kprobe_unwind_hotspot+0x1581>
    155e:	89 c8                	mov    eax,ecx
    1560:	48 8d 0d 00 00 00 00 	lea    rcx,[rip+0x0]        # 1567 <kprobe_unwind_hotspot+0x1567>
			1563: R_X86_64_PC32	.rodata+0x6c
    1567:	48 63 14 81          	movsxd rdx,DWORD PTR [rcx+rax*4]
    156b:	48 01 ca             	add    rdx,rcx
    156e:	b8 01 00 00 00       	mov    eax,0x1
    1573:	ff e2                	jmp    rdx
    1575:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
    157c:	e9 07 f4 ff ff       	jmp    988 <kprobe_unwind_hotspot+0x988>
    1581:	48 8b 2d 00 00 00 00 	mov    rbp,QWORD PTR [rip+0x0]        # 1588 <kprobe_unwind_hotspot+0x1588>
			1584: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1588:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    158f:	8b 45 00             	mov    eax,DWORD PTR [rbp+0x0]
    1592:	4d 85 ed             	test   r13,r13
    1595:	0f 85 24 01 00 00    	jne    16bf <kprobe_unwind_hotspot+0x16bf>
    159b:	e9 7f 0c 00 00       	jmp    221f <kprobe_unwind_hotspot+0x221f>
    15a0:	48 8b 2d 00 00 00 00 	mov    rbp,QWORD PTR [rip+0x0]        # 15a7 <kprobe_unwind_hotspot+0x15a7>
			15a3: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    15a7:	e9 bc f8 ff ff       	jmp    e68 <kprobe_unwind_hotspot+0xe68>
    15ac:	48 8b bc 24 a8 00 00 	mov    rdi,QWORD PTR [rsp+0xa8]
    15b3:	00 
    15b4:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    15bb:	48 83 f8 7f          	cmp    rax,0x7f
    15bf:	0f 83 f1 f8 ff ff    	jae    eb6 <kprobe_unwind_hotspot+0xeb6>
    15c5:	41 0f b6 8e 30 0f 00 	movzx  ecx,BYTE PTR [r14+0xf30]
    15cc:	00 
    15cd:	0f b6 94 24 c8 00 00 	movzx  edx,BYTE PTR [rsp+0xc8]
    15d4:	00 
    15d5:	48 c1 e2 3c          	shl    rdx,0x3c
    15d9:	4c 8b 84 24 b0 00 00 	mov    r8,QWORD PTR [rsp+0xb0]
    15e0:	00 
    15e1:	49 c1 e0 20          	shl    r8,0x20
    15e5:	8b b4 24 b8 00 00 00 	mov    esi,DWORD PTR [rsp+0xb8]
    15ec:	4c 09 c6             	or     rsi,r8
    15ef:	48 09 d6             	or     rsi,rdx
    15f2:	8d 50 01             	lea    edx,[rax+0x1]
    15f5:	41 89 96 c0 02 00 00 	mov    DWORD PTR [r14+0x2c0],edx
    15fc:	48 8d 04 40          	lea    rax,[rax+rax*2]
    1600:	48 8b 94 24 c0 00 00 	mov    rdx,QWORD PTR [rsp+0xc0]
    1607:	00 
    1608:	49 89 94 c6 d0 02 00 	mov    QWORD PTR [r14+rax*8+0x2d0],rdx
    160f:	00 
    1610:	49 89 b4 c6 d8 02 00 	mov    QWORD PTR [r14+rax*8+0x2d8],rsi
    1617:	00 
    1618:	41 c6 84 c6 e0 02 00 	mov    BYTE PTR [r14+rax*8+0x2e0],0x5
    161f:	00 05 
    1621:	41 88 8c c6 e1 02 00 	mov    BYTE PTR [r14+rax*8+0x2e1],cl
    1628:	00 
    1629:	41 c7 84 c6 e2 02 00 	mov    DWORD PTR [r14+rax*8+0x2e2],0x0
    1630:	00 00 00 00 00 
    1635:	66 41 c7 84 c6 e6 02 	mov    WORD PTR [r14+rax*8+0x2e6],0x0
    163c:	00 00 00 00 
    1640:	48 8b 2d 00 00 00 00 	mov    rbp,QWORD PTR [rip+0x0]        # 1647 <kprobe_unwind_hotspot+0x1647>
			1643: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1647:	83 7d 00 00          	cmp    DWORD PTR [rbp+0x0],0x0
    164b:	0f 85 0d 07 00 00    	jne    1d5e <kprobe_unwind_hotspot+0x1d5e>
    1651:	49 89 9e d0 0e 00 00 	mov    QWORD PTR [r14+0xed0],rbx
    1658:	4d 89 ae d8 0e 00 00 	mov    QWORD PTR [r14+0xed8],r13
    165f:	49 89 be e0 0e 00 00 	mov    QWORD PTR [r14+0xee0],rdi
    1666:	41 c6 86 30 0f 00 00 	mov    BYTE PTR [r14+0xf30],0x1
    166d:	01 
    166e:	c7 04 24 2a 00 00 00 	mov    DWORD PTR [rsp],0x2a
    1675:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 167c <kprobe_unwind_hotspot+0x167c>
			1678: R_X86_64_REX_GOTPCRELX	metrics-0x4
    167c:	48 89 e6             	mov    rsi,rsp
    167f:	b8 01 00 00 00       	mov    eax,0x1
    1684:	ff d0                	call   rax
    1686:	48 85 c0             	test   rax,rax
    1689:	74 17                	je     16a2 <kprobe_unwind_hotspot+0x16a2>
    168b:	48 ff 00             	inc    QWORD PTR [rax]
    168e:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    1695:	8b 45 00             	mov    eax,DWORD PTR [rbp+0x0]
    1698:	4d 85 ed             	test   r13,r13
    169b:	75 22                	jne    16bf <kprobe_unwind_hotspot+0x16bf>
    169d:	e9 7d 0b 00 00       	jmp    221f <kprobe_unwind_hotspot+0x221f>
    16a2:	83 7d 00 00          	cmp    DWORD PTR [rbp+0x0],0x0
    16a6:	0f 85 f2 0a 00 00    	jne    219e <kprobe_unwind_hotspot+0x219e>
    16ac:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    16b3:	8b 45 00             	mov    eax,DWORD PTR [rbp+0x0]
    16b6:	4d 85 ed             	test   r13,r13
    16b9:	0f 84 60 0b 00 00    	je     221f <kprobe_unwind_hotspot+0x221f>
    16bf:	49 b8 ff ff ff ff ff 	movabs r8,0xffffffffffffff
    16c6:	ff ff 00 
    16c9:	85 c0                	test   eax,eax
    16cb:	0f 85 28 07 00 00    	jne    1df9 <kprobe_unwind_hotspot+0x1df9>
    16d1:	4d 39 c5             	cmp    r13,r8
    16d4:	0f 86 a6 07 00 00    	jbe    1e80 <kprobe_unwind_hotspot+0x1e80>
    16da:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 16e1 <kprobe_unwind_hotspot+0x16e1>
			16dd: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    16e1:	83 38 00             	cmp    DWORD PTR [rax],0x0
    16e4:	0f 85 c5 0b 00 00    	jne    22af <kprobe_unwind_hotspot+0x22af>
    16ea:	41 c7 86 28 0f 00 00 	mov    DWORD PTR [r14+0xf28],0xb
    16f1:	0b 00 00 00 
    16f5:	bd ab 0f 00 00       	mov    ebp,0xfab
    16fa:	31 db                	xor    ebx,ebx
    16fc:	e9 36 ec ff ff       	jmp    337 <kprobe_unwind_hotspot+0x337>
    1701:	c7 84 24 08 01 00 00 	mov    DWORD PTR [rsp+0x108],0x2e
    1708:	2e 00 00 00 
    170c:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 1713 <kprobe_unwind_hotspot+0x1713>
			170f: R_X86_64_REX_GOTPCRELX	metrics-0x4
    1713:	48 8d b4 24 08 01 00 	lea    rsi,[rsp+0x108]
    171a:	00 
    171b:	b8 01 00 00 00       	mov    eax,0x1
    1720:	ff d0                	call   rax
    1722:	48 85 c0             	test   rax,rax
    1725:	0f 84 3e 02 00 00    	je     1969 <kprobe_unwind_hotspot+0x1969>
    172b:	48 ff 00             	inc    QWORD PTR [rax]
    172e:	e9 46 02 00 00       	jmp    1979 <kprobe_unwind_hotspot+0x1979>
    1733:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    1738:	48 89 84 24 c8 00 00 	mov    QWORD PTR [rsp+0xc8],rax
    173f:	00 
    1740:	48 8b 6c 24 78       	mov    rbp,QWORD PTR [rsp+0x78]
    1745:	4c 8b ac 24 88 00 00 	mov    r13,QWORD PTR [rsp+0x88]
    174c:	00 
    174d:	48 8b 84 24 90 00 00 	mov    rax,QWORD PTR [rsp+0x90]
    1754:	00 
    1755:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    175c:	00 
    175d:	48 8b 9c 24 98 00 00 	mov    rbx,QWORD PTR [rsp+0x98]
    1764:	00 
    1765:	41 0f b6 47 1c       	movzx  eax,BYTE PTR [r15+0x1c]
    176a:	48 01 e8             	add    rax,rbp
    176d:	48 8d bc 24 08 01 00 	lea    rdi,[rsp+0x108]
    1774:	00 
    1775:	b9 08 00 00 00       	mov    ecx,0x8
    177a:	41 b8 70 00 00 00    	mov    r8d,0x70
    1780:	41 0f b6 57 1c       	movzx  edx,BYTE PTR [r15+0x1c]
    1785:	48 01 ea             	add    rdx,rbp
    1788:	be 08 00 00 00       	mov    esi,0x8
    178d:	41 ff d0             	call   r8
    1790:	48 85 c0             	test   rax,rax
    1793:	74 73                	je     1808 <kprobe_unwind_hotspot+0x1808>
    1795:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 179c <kprobe_unwind_hotspot+0x179c>
			1798: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    179c:	83 38 00             	cmp    DWORD PTR [rax],0x0
    179f:	0f 84 5e f6 ff ff    	je     e03 <kprobe_unwind_hotspot+0xe03>
    17a5:	48 b8 63 6d 65 74 68 	movabs rax,0xa646f6874656d63
    17ac:	6f 64 0a 
    17af:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    17b4:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
    17bb:	65 72 20 
    17be:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    17c3:	48 b8 65 61 64 20 69 	movabs rax,0x65746e6920646165
    17ca:	6e 74 65 
    17cd:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    17d2:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    17d9:	6f 20 72 
    17dc:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    17e1:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    17e8:	66 61 69 
    17eb:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    17ef:	c6 44 24 28 00       	mov    BYTE PTR [rsp+0x28],0x0
    17f4:	31 c0                	xor    eax,eax
    17f6:	48 89 e1             	mov    rcx,rsp
    17f9:	ba 29 00 00 00       	mov    edx,0x29
    17fe:	be 06 00 00 00       	mov    esi,0x6
    1803:	e9 fb f5 ff ff       	jmp    e03 <kprobe_unwind_hotspot+0xe03>
    1808:	48 8b 94 24 08 01 00 	mov    rdx,QWORD PTR [rsp+0x108]
    180f:	00 
    1810:	41 0f b6 4f 1d       	movzx  ecx,BYTE PTR [r15+0x1d]
    1815:	48 89 d0             	mov    rax,rdx
    1818:	48 89 94 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rdx
    181f:	00 
    1820:	48 01 d1             	add    rcx,rdx
    1823:	31 c0                	xor    eax,eax
    1825:	4c 8b 84 24 c8 00 00 	mov    r8,QWORD PTR [rsp+0xc8]
    182c:	00 
    182d:	49 39 c8             	cmp    r8,rcx
    1830:	ba 00 00 00 00       	mov    edx,0x0
    1835:	48 0f 43 d1          	cmovae rdx,rcx
    1839:	49 29 d0             	sub    r8,rdx
    183c:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 1843 <kprobe_unwind_hotspot+0x1843>
			183f: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1843:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    1846:	0f 85 ca 11 00 00    	jne    2a16 <kprobe_unwind_hotspot+0x2a16>
    184c:	49 81 f8 ff ff 00 00 	cmp    r8,0xffff
    1853:	b9 ff ff 00 00       	mov    ecx,0xffff
    1858:	49 0f 42 c8          	cmovb  rcx,r8
    185c:	48 89 8c 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rcx
    1863:	00 
    1864:	48 c1 ac 24 b8 00 00 	shr    QWORD PTR [rsp+0xb8],0x3
    186b:	00 03 
    186d:	b9 06 00 00 00       	mov    ecx,0x6
    1872:	b2 02                	mov    dl,0x2
    1874:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    187b:	48 89 ac 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rbp
    1882:	00 
    1883:	85 c0                	test   eax,eax
    1885:	0f 85 a8 ea ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    188b:	e9 c9 fc ff ff       	jmp    1559 <kprobe_unwind_hotspot+0x1559>
    1890:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    1897:	64 0a 00 
    189a:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    189f:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    18a6:	69 63 49 
    18a9:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    18ae:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    18b5:	66 6f 72 
    18b8:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    18bd:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    18c4:	69 63 73 
    18c7:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    18cc:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    18d3:	6b 75 70 
    18d6:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    18db:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    18e2:	64 20 74 
    18e5:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    18ea:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    18ed:	31 c9                	xor    ecx,ecx
    18ef:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    18f4:	be 2e 00 00 00       	mov    esi,0x2e
    18f9:	bf 06 00 00 00       	mov    edi,0x6
    18fe:	e9 40 ed ff ff       	jmp    643 <kprobe_unwind_hotspot+0x643>
    1903:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    190a:	75 0a 00 
    190d:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    1912:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    1919:	74 61 67 
    191c:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1921:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    1928:	6e 74 20 
    192b:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1930:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    1937:	20 20 20 
    193a:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    193f:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1943:	31 c9                	xor    ecx,ecx
    1945:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    194a:	be 1d 00 00 00       	mov    esi,0x1d
    194f:	bf 06 00 00 00       	mov    edi,0x6
    1954:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1958:	8d 48 01             	lea    ecx,[rax+0x1]
    195b:	80 f9 02             	cmp    cl,0x2
    195e:	0f 82 19 e9 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    1964:	e9 91 f1 ff ff       	jmp    afa <kprobe_unwind_hotspot+0xafa>
    1969:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1970 <kprobe_unwind_hotspot+0x1970>
			196c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1970:	83 38 00             	cmp    DWORD PTR [rax],0x0
    1973:	0f 85 c0 20 00 00    	jne    3a39 <kprobe_unwind_hotspot+0x3a39>
    1979:	b8 ea 03 00 00       	mov    eax,0x3ea
    197e:	31 c9                	xor    ecx,ecx
    1980:	e9 bb fb ff ff       	jmp    1540 <kprobe_unwind_hotspot+0x1540>
    1985:	3c 41                	cmp    al,0x41
    1987:	0f 85 8d 00 00 00    	jne    1a1a <kprobe_unwind_hotspot+0x1a1a>
    198d:	80 f9 85             	cmp    cl,0x85
    1990:	0f 85 84 00 00 00    	jne    1a1a <kprobe_unwind_hotspot+0x1a1a>
    1996:	80 7c 24 03 02       	cmp    BYTE PTR [rsp+0x3],0x2
    199b:	75 7d                	jne    1a1a <kprobe_unwind_hotspot+0x1a1a>
    199d:	80 7c 24 04 c3       	cmp    BYTE PTR [rsp+0x4],0xc3
    19a2:	75 76                	jne    1a1a <kprobe_unwind_hotspot+0x1a1a>
    19a4:	b9 01 00 00 00       	mov    ecx,0x1
    19a9:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 19b0 <kprobe_unwind_hotspot+0x19b0>
			19ac: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    19b0:	83 38 00             	cmp    DWORD PTR [rax],0x0
    19b3:	0f 84 4a f9 ff ff    	je     1303 <kprobe_unwind_hotspot+0x1303>
    19b9:	48 b8 63 68 65 63 6b 	movabs rax,0xa276b63656863
    19c0:	27 0a 00 
    19c3:	48 89 44 24 5f       	mov    QWORD PTR [rsp+0x5f],rax
    19c8:	48 b8 65 70 6f 69 6e 	movabs rax,0x6320746e696f7065
    19cf:	74 20 63 
    19d2:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    19d7:	48 b8 65 20 6f 6e 20 	movabs rax,0x666173206e6f2065
    19de:	73 61 66 
    19e1:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    19e6:	48 b8 20 65 70 69 6c 	movabs rax,0x75676f6c69706520
    19ed:	6f 67 75 
    19f0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    19f5:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    19fc:	20 2d 3e 
    19ff:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1a04:	31 c0                	xor    eax,eax
    1a06:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1a0b:	be 27 00 00 00       	mov    esi,0x27
    1a10:	bf 06 00 00 00       	mov    edi,0x6
    1a15:	e9 e9 f8 ff ff       	jmp    1303 <kprobe_unwind_hotspot+0x1303>
    1a1a:	3c 0f                	cmp    al,0xf
    1a1c:	0f 85 0e 01 00 00    	jne    1b30 <kprobe_unwind_hotspot+0x1b30>
    1a22:	80 f9 85             	cmp    cl,0x85
    1a25:	0f 85 05 01 00 00    	jne    1b30 <kprobe_unwind_hotspot+0x1b30>
    1a2b:	80 7c 24 07 c3       	cmp    BYTE PTR [rsp+0x7],0xc3
    1a30:	0f 85 fa 00 00 00    	jne    1b30 <kprobe_unwind_hotspot+0x1b30>
    1a36:	b9 01 00 00 00       	mov    ecx,0x1
    1a3b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1a42 <kprobe_unwind_hotspot+0x1a42>
			1a3e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1a42:	83 38 00             	cmp    DWORD PTR [rax],0x0
    1a45:	0f 84 b8 f8 ff ff    	je     1303 <kprobe_unwind_hotspot+0x1303>
    1a4b:	48 b8 63 68 65 63 6b 	movabs rax,0xa276b63656863
    1a52:	27 0a 00 
    1a55:	48 89 44 24 6e       	mov    QWORD PTR [rsp+0x6e],rax
    1a5a:	48 b8 70 74 69 6f 6e 	movabs rax,0x6863206e6f697470
    1a61:	20 63 68 
    1a64:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    1a69:	48 b8 70 65 72 20 65 	movabs rax,0x6563786520726570
    1a70:	78 63 65 
    1a73:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    1a78:	48 b8 69 76 65 20 77 	movabs rax,0x7061727720657669
    1a7f:	72 61 70 
    1a82:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    1a87:	48 b8 65 20 6f 6e 20 	movabs rax,0x74616e206e6f2065
    1a8e:	6e 61 74 
    1a91:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1a96:	48 b8 20 65 70 69 6c 	movabs rax,0x75676f6c69706520
    1a9d:	6f 67 75 
    1aa0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1aa5:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    1aac:	20 2d 3e 
    1aaf:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1ab4:	31 c0                	xor    eax,eax
    1ab6:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1abb:	be 36 00 00 00       	mov    esi,0x36
    1ac0:	bf 06 00 00 00       	mov    edi,0x6
    1ac5:	e9 39 f8 ff ff       	jmp    1303 <kprobe_unwind_hotspot+0x1303>
    1aca:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    1ad1:	75 0a 00 
    1ad4:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    1ad9:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    1ae0:	74 61 67 
    1ae3:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1ae8:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    1aef:	6e 74 20 
    1af2:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1af7:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    1afe:	20 20 20 
    1b01:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1b06:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1b0a:	31 c9                	xor    ecx,ecx
    1b0c:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1b11:	be 1d 00 00 00       	mov    esi,0x1d
    1b16:	bf 06 00 00 00       	mov    edi,0x6
    1b1b:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1b1f:	8d 48 01             	lea    ecx,[rax+0x1]
    1b22:	80 f9 02             	cmp    cl,0x2
    1b25:	0f 82 52 e7 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    1b2b:	e9 11 f0 ff ff       	jmp    b41 <kprobe_unwind_hotspot+0xb41>
    1b30:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1b34:	3d c9 00 00 00       	cmp    eax,0xc9
    1b39:	74 09                	je     1b44 <kprobe_unwind_hotspot+0x1b44>
    1b3b:	83 f8 5d             	cmp    eax,0x5d
    1b3e:	0f 85 bf ed ff ff    	jne    903 <kprobe_unwind_hotspot+0x903>
    1b44:	b9 01 00 00 00       	mov    ecx,0x1
    1b49:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1b50 <kprobe_unwind_hotspot+0x1b50>
			1b4c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1b50:	83 38 00             	cmp    DWORD PTR [rax],0x0
    1b53:	0f 84 aa f7 ff ff    	je     1303 <kprobe_unwind_hotspot+0x1303>
    1b59:	48 b8 6c 65 61 76 65 	movabs rax,0xa27657661656c
    1b60:	27 0a 00 
    1b63:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    1b68:	48 b8 65 20 61 66 74 	movabs rax,0x2072657466612065
    1b6f:	65 72 20 
    1b72:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1b77:	48 b8 20 65 70 69 6c 	movabs rax,0x75676f6c69706520
    1b7e:	6f 67 75 
    1b81:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1b86:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    1b8d:	20 2d 3e 
    1b90:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1b95:	31 c0                	xor    eax,eax
    1b97:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1b9c:	be 20 00 00 00       	mov    esi,0x20
    1ba1:	bf 06 00 00 00       	mov    edi,0x6
    1ba6:	e9 58 f7 ff ff       	jmp    1303 <kprobe_unwind_hotspot+0x1303>
    1bab:	48 b8 6c 78 2d 25 6c 	movabs rax,0xa786c252d786c
    1bb2:	78 0a 00 
    1bb5:	48 89 44 24 4f       	mov    QWORD PTR [rsp+0x4f],rax
    1bba:	48 b8 20 63 6f 64 65 	movabs rax,0x6c252065646f6320
    1bc1:	20 25 6c 
    1bc4:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1bc9:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    1bd0:	20 2d 3e 
    1bd3:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1bd8:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    1bdf:	00 
    1be0:	48 8b 94 24 e0 00 00 	mov    rdx,QWORD PTR [rsp+0xe0]
    1be7:	00 
    1be8:	31 f6                	xor    esi,esi
    1bea:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    1bef:	41 b8 17 00 00 00    	mov    r8d,0x17
    1bf5:	41 b9 06 00 00 00    	mov    r9d,0x6
    1bfb:	83 7d 00 00          	cmp    DWORD PTR [rbp+0x0],0x0
    1bff:	0f 84 34 e9 ff ff    	je     539 <kprobe_unwind_hotspot+0x539>
    1c05:	48 b9 5f 74 79 70 65 	movabs rcx,0x783020657079745f
    1c0c:	20 30 78 
    1c0f:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    1c14:	48 b9 75 2c 20 66 72 	movabs rcx,0x656d617266202c75
    1c1b:	61 6d 65 
    1c1e:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    1c23:	48 b9 65 5f 73 69 7a 	movabs rcx,0x2520657a69735f65
    1c2a:	65 20 25 
    1c2d:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    1c32:	48 b9 25 75 2c 20 66 	movabs rcx,0x6d617266202c7525
    1c39:	72 61 6d 
    1c3c:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    1c41:	48 b9 6f 6d 70 6c 65 	movabs rcx,0x206574656c706d6f
    1c48:	74 65 20 
    1c4b:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    1c50:	48 b9 20 66 72 61 6d 	movabs rcx,0x635f656d61726620
    1c57:	65 5f 63 
    1c5a:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    1c5f:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1c64:	c7 44 24 78 25 78 0a 	mov    DWORD PTR [rsp+0x78],0xa7825
    1c6b:	00 
    1c6c:	0f b7 84 24 00 01 00 	movzx  eax,WORD PTR [rsp+0x100]
    1c73:	00 
    1c74:	8b 8c 24 f0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xf0]
    1c7b:	8b 94 24 f8 00 00 00 	mov    edx,DWORD PTR [rsp+0xf8]
    1c82:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    1c87:	bf 3c 00 00 00       	mov    edi,0x3c
    1c8c:	41 b8 06 00 00 00    	mov    r8d,0x6
    1c92:	e9 a2 e8 ff ff       	jmp    539 <kprobe_unwind_hotspot+0x539>
    1c97:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    1c9e:	75 0a 00 
    1ca1:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    1ca6:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    1cad:	74 61 67 
    1cb0:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1cb5:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    1cbc:	6e 74 20 
    1cbf:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1cc4:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    1ccb:	20 20 20 
    1cce:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1cd3:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1cd7:	31 c9                	xor    ecx,ecx
    1cd9:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1cde:	be 1d 00 00 00       	mov    esi,0x1d
    1ce3:	bf 06 00 00 00       	mov    edi,0x6
    1ce8:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    1cec:	8d 48 01             	lea    ecx,[rax+0x1]
    1cef:	80 f9 02             	cmp    cl,0x2
    1cf2:	0f 82 85 e5 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    1cf8:	e9 8b ee ff ff       	jmp    b88 <kprobe_unwind_hotspot+0xb88>
    1cfd:	48 b8 73 20 66 75 6c 	movabs rax,0xa6c6c75662073
    1d04:	6c 0a 00 
    1d07:	48 89 44 24 5d       	mov    QWORD PTR [rsp+0x5d],rax
    1d0c:	48 b8 61 63 6b 20 69 	movabs rax,0x66207369206b6361
    1d13:	73 20 66 
    1d16:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    1d1b:	48 b8 72 61 6d 65 3a 	movabs rax,0x7473203a656d6172
    1d22:	20 73 74 
    1d25:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1d2a:	48 b8 6f 20 70 75 73 	movabs rax,0x662068737570206f
    1d31:	68 20 66 
    1d34:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1d39:	48 b8 75 6e 61 62 6c 	movabs rax,0x7420656c62616e75
    1d40:	65 20 74 
    1d43:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1d48:	31 c0                	xor    eax,eax
    1d4a:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    1d4f:	ba 25 00 00 00       	mov    edx,0x25
    1d54:	be 06 00 00 00       	mov    esi,0x6
    1d59:	e9 68 f1 ff ff       	jmp    ec6 <kprobe_unwind_hotspot+0xec6>
    1d5e:	48 b8 78 2c 20 66 70 	movabs rax,0x25203a7066202c78
    1d65:	3a 20 25 
    1d68:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    1d6d:	48 b8 2c 20 73 70 3a 	movabs rax,0x6c25203a7073202c
    1d74:	20 25 6c 
    1d77:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1d7c:	48 b8 20 70 63 3a 20 	movabs rax,0x786c25203a637020
    1d83:	25 6c 78 
    1d86:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1d8b:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    1d92:	20 2d 3e 
    1d95:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1d9a:	c7 44 24 60 6c 78 0a 	mov    DWORD PTR [rsp+0x60],0xa786c
    1da1:	00 
    1da2:	48 8d 44 24 40       	lea    rax,[rsp+0x40]
    1da7:	b9 24 00 00 00       	mov    ecx,0x24
    1dac:	ba 06 00 00 00       	mov    edx,0x6
    1db1:	e9 9b f8 ff ff       	jmp    1651 <kprobe_unwind_hotspot+0x1651>
    1db6:	48 b8 76 65 72 20 66 	movabs rax,0xa706620726576
    1dbd:	70 0a 00 
    1dc0:	48 89 44 24 4d       	mov    QWORD PTR [rsp+0x4d],rax
    1dc5:	48 b8 20 72 65 63 6f 	movabs rax,0x7265766f63657220
    1dcc:	76 65 72 
    1dcf:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1dd4:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    1ddb:	20 2d 3e 
    1dde:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1de3:	31 c0                	xor    eax,eax
    1de5:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    1dea:	ba 15 00 00 00       	mov    edx,0x15
    1def:	be 06 00 00 00       	mov    esi,0x6
    1df4:	e9 a8 f0 ff ff       	jmp    ea1 <kprobe_unwind_hotspot+0xea1>
    1df9:	48 b8 25 64 20 3d 3d 	movabs rax,0xa3d3d3d3d206425
    1e00:	3d 3d 0a 
    1e03:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    1e08:	48 b8 3a 20 66 72 61 	movabs rax,0x20656d617266203a
    1e0f:	6d 65 20 
    1e12:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    1e17:	48 b8 75 6e 77 69 6e 	movabs rax,0x7265646e69776e75
    1e1e:	64 65 72 
    1e21:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    1e26:	48 b8 74 20 66 72 61 	movabs rax,0x20656d6172662074
    1e2d:	6d 65 20 
    1e30:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1e35:	48 b8 6f 6c 76 65 20 	movabs rax,0x78656e2065766c6f
    1e3c:	6e 65 78 
    1e3f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1e44:	48 b8 3d 3d 3d 3d 20 	movabs rax,0x736552203d3d3d3d
    1e4b:	52 65 73 
    1e4e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1e53:	c6 44 24 70 00       	mov    BYTE PTR [rsp+0x70],0x0
    1e58:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    1e5f:	31 c9                	xor    ecx,ecx
    1e61:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    1e66:	be 31 00 00 00       	mov    esi,0x31
    1e6b:	bf 06 00 00 00       	mov    edi,0x6
    1e70:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    1e77:	4d 39 c5             	cmp    r13,r8
    1e7a:	0f 87 5a f8 ff ff    	ja     16da <kprobe_unwind_hotspot+0x16da>
    1e80:	49 81 fd ff 0f 00 00 	cmp    r13,0xfff
    1e87:	77 27                	ja     1eb0 <kprobe_unwind_hotspot+0x1eb0>
    1e89:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1e90 <kprobe_unwind_hotspot+0x1e90>
			1e8c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1e90:	83 38 00             	cmp    DWORD PTR [rax],0x0
    1e93:	0f 85 5e 07 00 00    	jne    25f7 <kprobe_unwind_hotspot+0x25f7>
    1e99:	41 c7 86 28 0f 00 00 	mov    DWORD PTR [r14+0xf28],0x31
    1ea0:	31 00 00 00 
    1ea4:	bd ae 0f 00 00       	mov    ebp,0xfae
    1ea9:	31 db                	xor    ebx,ebx
    1eab:	e9 87 e4 ff ff       	jmp    337 <kprobe_unwind_hotspot+0x337>
    1eb0:	41 8b 06             	mov    eax,DWORD PTR [r14]
    1eb3:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x60
    1eba:	60 00 00 00 
    1ebe:	0f 38 f1 84 24 d4 00 	movbe  DWORD PTR [rsp+0xd4],eax
    1ec5:	00 00 
    1ec7:	4c 0f 38 f1 ac 24 d8 	movbe  QWORD PTR [rsp+0xd8],r13
    1ece:	00 00 00 
    1ed1:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 1ed8 <kprobe_unwind_hotspot+0x1ed8>
			1ed4: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    1ed8:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    1edf:	00 
    1ee0:	b8 01 00 00 00       	mov    eax,0x1
    1ee5:	ff d0                	call   rax
    1ee7:	48 85 c0             	test   rax,rax
    1eea:	0f 84 82 78 00 00    	je     9772 <kprobe_unwind_hotspot+0x9772>
    1ef0:	48 8b 58 08          	mov    rbx,QWORD PTR [rax+0x8]
    1ef4:	48 89 d9             	mov    rcx,rbx
    1ef7:	48 ba ff ff ff ff ff 	movabs rdx,0xffffffffffffff
    1efe:	ff ff 00 
    1f01:	48 21 d1             	and    rcx,rdx
    1f04:	49 89 8e 20 0f 00 00 	mov    QWORD PTR [r14+0xf20],rcx
    1f0b:	48 8b 00             	mov    rax,QWORD PTR [rax]
    1f0e:	49 89 86 10 0f 00 00 	mov    QWORD PTR [r14+0xf10],rax
    1f15:	48 c1 eb 38          	shr    rbx,0x38
    1f19:	4c 89 ea             	mov    rdx,r13
    1f1c:	48 29 ca             	sub    rdx,rcx
    1f1f:	49 89 96 18 0f 00 00 	mov    QWORD PTR [r14+0xf18],rdx
    1f26:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 1f2d <kprobe_unwind_hotspot+0x1f2d>
			1f29: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1f2d:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    1f30:	0f 85 d5 07 00 00    	jne    270b <kprobe_unwind_hotspot+0x270b>
    1f36:	83 fb 01             	cmp    ebx,0x1
    1f39:	0f 85 64 0c 00 00    	jne    2ba3 <kprobe_unwind_hotspot+0x2ba3>
    1f3f:	49 8b 86 10 0f 00 00 	mov    rax,QWORD PTR [r14+0xf10]
    1f46:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    1f4d:	00 
    1f4e:	4d 8b ae 18 0f 00 00 	mov    r13,QWORD PTR [r14+0xf18]
    1f55:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 1f5c <kprobe_unwind_hotspot+0x1f5c>
			1f58: R_X86_64_REX_GOTPCRELX	interpreter_offsets-0x4
    1f5c:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    1f63:	00 
    1f64:	b8 01 00 00 00       	mov    eax,0x1
    1f69:	ff d0                	call   rax
    1f6b:	bb 01 00 00 00       	mov    ebx,0x1
    1f70:	48 85 c0             	test   rax,rax
    1f73:	0f 84 2a 0c 00 00    	je     2ba3 <kprobe_unwind_hotspot+0x2ba3>
    1f79:	48 89 c5             	mov    rbp,rax
    1f7c:	4c 39 28             	cmp    QWORD PTR [rax],r13
    1f7f:	77 06                	ja     1f87 <kprobe_unwind_hotspot+0x1f87>
    1f81:	4c 39 6d 08          	cmp    QWORD PTR [rbp+0x8],r13
    1f85:	73 14                	jae    1f9b <kprobe_unwind_hotspot+0x1f9b>
    1f87:	4c 39 6d 10          	cmp    QWORD PTR [rbp+0x10],r13
    1f8b:	0f 87 12 0c 00 00    	ja     2ba3 <kprobe_unwind_hotspot+0x2ba3>
    1f91:	4c 39 6d 18          	cmp    QWORD PTR [rbp+0x18],r13
    1f95:	0f 82 08 0c 00 00    	jb     2ba3 <kprobe_unwind_hotspot+0x2ba3>
    1f9b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1fa2 <kprobe_unwind_hotspot+0x1fa2>
			1f9e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1fa2:	83 38 00             	cmp    DWORD PTR [rax],0x0
    1fa5:	0f 85 5e 0b 00 00    	jne    2b09 <kprobe_unwind_hotspot+0x2b09>
    1fab:	41 8b 86 80 13 00 00 	mov    eax,DWORD PTR [r14+0x1380]
    1fb2:	8b 4d 20             	mov    ecx,DWORD PTR [rbp+0x20]
    1fb5:	0f a3 c8             	bt     eax,ecx
    1fb8:	0f 83 af 0b 00 00    	jae    2b6d <kprobe_unwind_hotspot+0x2b6d>
    1fbe:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 1fc5 <kprobe_unwind_hotspot+0x1fc5>
			1fc1: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    1fc5:	83 38 00             	cmp    DWORD PTR [rax],0x0
    1fc8:	0f 84 d5 0b 00 00    	je     2ba3 <kprobe_unwind_hotspot+0x2ba3>
    1fce:	48 b8 6e 64 65 72 20 	movabs rax,0x6e6f64207265646e
    1fd5:	64 6f 6e 
    1fd8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    1fdd:	48 b8 74 65 72 20 75 	movabs rax,0x69776e7520726574
    1fe4:	6e 77 69 
    1fe7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    1fec:	48 b8 69 6e 74 65 72 	movabs rax,0x6572707265746e69
    1ff3:	70 72 65 
    1ff6:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    1ffb:	c7 44 24 57 6e 65 0a 	mov    DWORD PTR [rsp+0x57],0xa656e
    2002:	00 
    2003:	31 c0                	xor    eax,eax
    2005:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    200a:	ba 1b 00 00 00       	mov    edx,0x1b
    200f:	be 06 00 00 00       	mov    esi,0x6
    2014:	e9 8a 0b 00 00       	jmp    2ba3 <kprobe_unwind_hotspot+0x2ba3>
    2019:	48 b8 6c 62 61 63 6b 	movabs rax,0x6170206b6361626c
    2020:	20 70 61 
    2023:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    2028:	48 b8 73 74 75 62 20 	movabs rax,0x6c61662062757473
    202f:	66 61 6c 
    2032:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2037:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    203e:	6e 64 20 
    2041:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2046:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    204d:	20 2d 3e 
    2050:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2055:	c7 44 24 60 74 68 0a 	mov    DWORD PTR [rsp+0x60],0xa6874
    205c:	00 
    205d:	31 c0                	xor    eax,eax
    205f:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    2064:	ba 24 00 00 00       	mov    edx,0x24
    2069:	be 06 00 00 00       	mov    esi,0x6
    206e:	e9 43 e8 ff ff       	jmp    8b6 <kprobe_unwind_hotspot+0x8b6>
    2073:	48 b8 76 74 61 62 6c 	movabs rax,0xa656c62617476
    207a:	65 0a 00 
    207d:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2082:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    2089:	6e 64 20 
    208c:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2091:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    2098:	20 2d 3e 
    209b:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    20a0:	31 c0                	xor    eax,eax
    20a2:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    20a7:	ba 18 00 00 00       	mov    edx,0x18
    20ac:	be 06 00 00 00       	mov    esi,0x6
    20b1:	e9 c2 e8 ff ff       	jmp    978 <kprobe_unwind_hotspot+0x978>
    20b6:	48 b8 66 61 69 6c 65 	movabs rax,0xa64656c696166
    20bd:	64 0a 00 
    20c0:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    20c5:	48 b8 65 63 6f 76 65 	movabs rax,0x20797265766f6365
    20cc:	72 79 20 
    20cf:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    20d4:	48 b8 6d 65 2c 20 70 	movabs rax,0x72206370202c656d
    20db:	63 20 72 
    20de:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    20e3:	48 b8 69 7a 65 64 20 	movabs rax,0x6172662064657a69
    20ea:	66 72 61 
    20ed:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    20f2:	48 b8 20 64 65 6f 70 	movabs rax,0x6d6974706f656420
    20f9:	74 69 6d 
    20fc:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2101:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    2108:	20 2d 3e 
    210b:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2110:	31 c0                	xor    eax,eax
    2112:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    2117:	ba 30 00 00 00       	mov    edx,0x30
    211c:	be 06 00 00 00       	mov    esi,0x6
    2121:	e9 7c e6 ff ff       	jmp    7a2 <kprobe_unwind_hotspot+0x7a2>
    2126:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    212d:	64 0a 00 
    2130:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    2135:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    213c:	69 63 49 
    213f:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    2144:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    214b:	66 6f 72 
    214e:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    2153:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    215a:	69 63 73 
    215d:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2162:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    2169:	6b 75 70 
    216c:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2171:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    2178:	64 20 74 
    217b:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2180:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    2183:	31 c9                	xor    ecx,ecx
    2185:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    218a:	be 2e 00 00 00       	mov    esi,0x2e
    218f:	bf 06 00 00 00       	mov    edi,0x6
    2194:	b8 02 00 00 00       	mov    eax,0x2
    2199:	e9 95 e1 ff ff       	jmp    333 <kprobe_unwind_hotspot+0x333>
    219e:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    21a5:	64 0a 00 
    21a8:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    21ad:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    21b4:	69 63 49 
    21b7:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    21bc:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    21c3:	66 6f 72 
    21c6:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    21cb:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    21d2:	69 63 73 
    21d5:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    21da:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    21e1:	6b 75 70 
    21e4:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    21e9:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    21f0:	64 20 74 
    21f3:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    21f8:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    21fb:	31 c9                	xor    ecx,ecx
    21fd:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    2202:	be 2e 00 00 00       	mov    esi,0x2e
    2207:	bf 06 00 00 00       	mov    edi,0x6
    220c:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    2213:	8b 45 00             	mov    eax,DWORD PTR [rbp+0x0]
    2216:	4d 85 ed             	test   r13,r13
    2219:	0f 85 a0 f4 ff ff    	jne    16bf <kprobe_unwind_hotspot+0x16bf>
    221f:	85 c0                	test   eax,eax
    2221:	75 17                	jne    223a <kprobe_unwind_hotspot+0x223a>
    2223:	41 c7 86 28 0f 00 00 	mov    DWORD PTR [r14+0xf28],0x1
    222a:	01 00 00 00 
    222e:	bd ad 0f 00 00       	mov    ebp,0xfad
    2233:	31 db                	xor    ebx,ebx
    2235:	e9 fd e0 ff ff       	jmp    337 <kprobe_unwind_hotspot+0x337>
    223a:	48 b8 43 20 3d 3d 20 	movabs rax,0xa2930203d3d2043
    2241:	30 29 0a 
    2244:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    2249:	48 b8 69 6c 75 72 65 	movabs rax,0x5028206572756c69
    2250:	20 28 50 
    2253:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    2258:	48 b8 6e 77 69 6e 64 	movabs rax,0x616620646e69776e
    225f:	20 66 61 
    2262:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    2267:	48 b8 64 75 65 20 74 	movabs rax,0x75206f7420657564
    226e:	6f 20 75 
    2271:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2276:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    227d:	6e 64 20 
    2280:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2285:	48 b8 53 74 6f 70 70 	movabs rax,0x676e6970706f7453
    228c:	69 6e 67 
    228f:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2294:	c6 44 24 70 00       	mov    BYTE PTR [rsp+0x70],0x0
    2299:	31 c0                	xor    eax,eax
    229b:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    22a0:	ba 31 00 00 00       	mov    edx,0x31
    22a5:	be 06 00 00 00       	mov    esi,0x6
    22aa:	e9 74 ff ff ff       	jmp    2223 <kprobe_unwind_hotspot+0x2223>
    22af:	48 b8 20 61 64 64 72 	movabs rax,0x7373657264646120
    22b6:	65 73 73 
    22b9:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    22be:	48 b8 61 20 6b 65 72 	movabs rax,0x6c656e72656b2061
    22c5:	6e 65 6c 
    22c8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    22cd:	48 b8 20 25 6c 78 20 	movabs rax,0x20736920786c2520
    22d4:	69 73 20 
    22d7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    22dc:	48 b8 50 43 20 76 61 	movabs rax,0x65756c6176204350
    22e3:	6c 75 65 
    22e6:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    22eb:	66 c7 44 24 60 0a 00 	mov    WORD PTR [rsp+0x60],0xa
    22f2:	31 c0                	xor    eax,eax
    22f4:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    22f9:	ba 22 00 00 00       	mov    edx,0x22
    22fe:	be 06 00 00 00       	mov    esi,0x6
    2303:	e9 e2 f3 ff ff       	jmp    16ea <kprobe_unwind_hotspot+0x16ea>
    2308:	48 b8 20 66 72 61 6d 	movabs rax,0xa656d61726620
    230f:	65 0a 00 
    2312:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    2317:	48 b8 70 72 65 74 65 	movabs rax,0x6620726574657270
    231e:	72 20 66 
    2321:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    2326:	48 b8 62 65 20 69 6e 	movabs rax,0x7265746e69206562
    232d:	74 65 72 
    2330:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    2335:	48 b8 61 77 61 79 20 	movabs rax,0x206f742079617761
    233c:	74 6f 20 
    233f:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    2344:	48 b8 74 6f 6f 20 66 	movabs rax,0x20726166206f6f74
    234b:	61 72 20 
    234e:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    2353:	48 b8 6a 76 6d 3a 20 	movabs rax,0x207066203a6d766a
    235a:	66 70 20 
    235d:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    2361:	31 c0                	xor    eax,eax
    2363:	48 89 e1             	mov    rcx,rsp
    2366:	ba 2e 00 00 00       	mov    edx,0x2e
    236b:	be 06 00 00 00       	mov    esi,0x6
    2370:	e9 8e ea ff ff       	jmp    e03 <kprobe_unwind_hotspot+0xe03>
    2375:	48 b8 66 70 2b 70 63 	movabs rax,0xa2963702b7066
    237c:	29 0a 00 
    237f:	48 89 44 24 65       	mov    QWORD PTR [rsp+0x65],rax
    2384:	48 b8 61 6d 65 20 28 	movabs rax,0x2b70662820656d61
    238b:	66 70 2b 
    238e:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    2393:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
    239a:	20 66 72 
    239d:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    23a2:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
    23a9:	63 6f 6d 
    23ac:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    23b1:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    23b8:	6e 64 69 
    23bb:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    23c0:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    23c7:	20 2d 3e 
    23ca:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    23cf:	31 c0                	xor    eax,eax
    23d1:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    23d6:	ba 2d 00 00 00       	mov    edx,0x2d
    23db:	be 06 00 00 00       	mov    esi,0x6
    23e0:	e9 61 ea ff ff       	jmp    e46 <kprobe_unwind_hotspot+0xe46>
    23e5:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    23ec:	75 0a 00 
    23ef:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    23f4:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    23fb:	74 61 67 
    23fe:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2403:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    240a:	6e 74 20 
    240d:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2412:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    2419:	20 20 20 
    241c:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2421:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    2425:	31 c9                	xor    ecx,ecx
    2427:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    242c:	be 1d 00 00 00       	mov    esi,0x1d
    2431:	bf 06 00 00 00       	mov    edi,0x6
    2436:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    243a:	8d 48 01             	lea    ecx,[rax+0x1]
    243d:	80 f9 02             	cmp    cl,0x2
    2440:	0f 82 37 de ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    2446:	e9 84 e7 ff ff       	jmp    bcf <kprobe_unwind_hotspot+0xbcf>
    244b:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    2452:	25 6c 78 
    2455:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    245a:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    2461:	69 64 61 
    2464:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    2469:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    2470:	20 70 63 
    2473:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    2478:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    247f:	20 20 20 
    2482:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    2486:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    248d:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
    2492:	31 c9                	xor    ecx,ecx
    2494:	48 89 e2             	mov    rdx,rsp
    2497:	be 22 00 00 00       	mov    esi,0x22
    249c:	bf 06 00 00 00       	mov    edi,0x6
    24a1:	e9 8e ea ff ff       	jmp    f34 <kprobe_unwind_hotspot+0xf34>
    24a6:	48 b9 65 20 25 6c 64 	movabs rcx,0xa29646c252065
    24ad:	29 0a 00 
    24b0:	48 89 4c 24 67       	mov    QWORD PTR [rsp+0x67],rcx
    24b5:	48 b9 61 6d 65 20 73 	movabs rcx,0x657a697320656d61
    24bc:	69 7a 65 
    24bf:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    24c4:	48 b9 6e 74 65 72 20 	movabs rcx,0x726628207265746e
    24cb:	28 66 72 
    24ce:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    24d3:	48 b9 72 61 6d 65 20 	movabs rcx,0x696f7020656d6172
    24da:	70 6f 69 
    24dd:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    24e2:	48 b9 20 75 73 69 6e 	movabs rcx,0x6620676e69737520
    24e9:	67 20 66 
    24ec:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    24f1:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    24f8:	20 2d 3e 
    24fb:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    2500:	31 c9                	xor    ecx,ecx
    2502:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    2507:	be 2f 00 00 00       	mov    esi,0x2f
    250c:	bf 06 00 00 00       	mov    edi,0x6
    2511:	e9 35 e4 ff ff       	jmp    94b <kprobe_unwind_hotspot+0x94b>
    2516:	48 b8 20 77 6f 72 64 	movabs rax,0xa7364726f7720
    251d:	73 0a 00 
    2520:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    2525:	48 b8 65 20 2b 20 25 	movabs rax,0x77206425202b2065
    252c:	64 20 77 
    252f:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    2534:	48 b8 65 74 65 20 66 	movabs rax,0x6d61726620657465
    253b:	72 61 6d 
    253e:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    2543:	48 b8 6e 67 20 63 6f 	movabs rax,0x6c706d6f6320676e
    254a:	6d 70 6c 
    254d:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    2552:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    2559:	6e 64 69 
    255c:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    2561:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    2568:	20 2d 3e 
    256b:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    256f:	31 c0                	xor    eax,eax
    2571:	48 89 e2             	mov    rdx,rsp
    2574:	be 2e 00 00 00       	mov    esi,0x2e
    2579:	bf 06 00 00 00       	mov    edi,0x6
    257e:	e9 b5 ef ff ff       	jmp    1538 <kprobe_unwind_hotspot+0x1538>
    2583:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    258a:	64 0a 00 
    258d:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    2592:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    2599:	69 63 49 
    259c:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    25a1:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    25a8:	66 6f 72 
    25ab:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    25b0:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    25b7:	69 63 73 
    25ba:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    25bf:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    25c6:	6b 75 70 
    25c9:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    25ce:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    25d5:	64 20 74 
    25d8:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    25dc:	8b 84 24 14 01 00 00 	mov    eax,DWORD PTR [rsp+0x114]
    25e3:	31 c9                	xor    ecx,ecx
    25e5:	48 89 e2             	mov    rdx,rsp
    25e8:	be 2e 00 00 00       	mov    esi,0x2e
    25ed:	bf 06 00 00 00       	mov    edi,0x6
    25f2:	e9 f8 e9 ff ff       	jmp    fef <kprobe_unwind_hotspot+0xfef>
    25f7:	48 b8 6e 6f 72 69 6e 	movabs rax,0xa676e69726f6e
    25fe:	67 0a 00 
    2601:	48 89 44 24 56       	mov    QWORD PTR [rsp+0x56],rax
    2606:	48 b8 6c 78 2c 20 69 	movabs rax,0x6f6e6769202c786c
    260d:	67 6e 6f 
    2610:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2615:	48 b8 20 76 61 6c 75 	movabs rax,0x252065756c617620
    261c:	65 20 25 
    261f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2624:	48 b8 73 6d 61 6c 6c 	movabs rax,0x6370206c6c616d73
    262b:	20 70 63 
    262e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2633:	31 c0                	xor    eax,eax
    2635:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    263a:	ba 1e 00 00 00       	mov    edx,0x1e
    263f:	be 06 00 00 00       	mov    esi,0x6
    2644:	e9 50 f8 ff ff       	jmp    1e99 <kprobe_unwind_hotspot+0x1e99>
    2649:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    2650:	25 6c 78 
    2653:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    2658:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    265f:	69 64 61 
    2662:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    2667:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    266e:	20 70 63 
    2671:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    2676:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    267d:	20 20 20 
    2680:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    2684:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    268b:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    2690:	31 c9                	xor    ecx,ecx
    2692:	48 89 e2             	mov    rdx,rsp
    2695:	be 22 00 00 00       	mov    esi,0x22
    269a:	bf 01 00 00 00       	mov    edi,0x1
    269f:	41 b8 06 00 00 00    	mov    r8d,0x6
    26a5:	e9 7f e9 ff ff       	jmp    1029 <kprobe_unwind_hotspot+0x1029>
    26aa:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    26b1:	25 6c 78 
    26b4:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    26b9:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    26c0:	69 64 61 
    26c3:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    26c8:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    26cf:	20 70 63 
    26d2:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    26d7:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    26de:	20 20 20 
    26e1:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    26e5:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    26ec:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    26f1:	31 c9                	xor    ecx,ecx
    26f3:	48 89 e2             	mov    rdx,rsp
    26f6:	be 22 00 00 00       	mov    esi,0x22
    26fb:	bf 02 00 00 00       	mov    edi,0x2
    2700:	41 b8 06 00 00 00    	mov    r8d,0x6
    2706:	e9 75 ea ff ff       	jmp    1180 <kprobe_unwind_hotspot+0x1180>
    270b:	48 b9 6e 64 65 72 20 	movabs rcx,0x296425207265646e
    2712:	25 64 29 
    2715:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    271a:	48 b9 6c 78 20 28 75 	movabs rcx,0x69776e752820786c
    2721:	6e 77 69 
    2724:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    2729:	48 b9 6c 78 20 69 73 	movabs rcx,0x6c2520736920786c
    2730:	20 25 6c 
    2733:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    2738:	48 b9 66 6f 72 20 50 	movabs rcx,0x2520435020726f66
    273f:	43 20 25 
    2742:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    2747:	48 b9 74 69 6f 6e 20 	movabs rcx,0x206469206e6f6974
    274e:	69 64 20 
    2751:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    2756:	48 b9 54 65 78 74 20 	movabs rcx,0x6365732074786554
    275d:	73 65 63 
    2760:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    2765:	66 c7 44 24 70 0a 00 	mov    WORD PTR [rsp+0x70],0xa
    276c:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    2771:	be 32 00 00 00       	mov    esi,0x32
    2776:	bf 06 00 00 00       	mov    edi,0x6
    277b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2782 <kprobe_unwind_hotspot+0x2782>
			277e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2782:	83 38 00             	cmp    DWORD PTR [rax],0x0
    2785:	0f 84 ab f7 ff ff    	je     1f36 <kprobe_unwind_hotspot+0x1f36>
    278b:	48 b8 73 20 25 6c 6c 	movabs rax,0xa786c6c252073
    2792:	78 0a 00 
    2795:	48 89 44 24 67       	mov    QWORD PTR [rsp+0x67],rax
    279a:	48 b8 66 66 73 65 74 	movabs rax,0x7369207465736666
    27a1:	20 69 73 
    27a4:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    27a9:	48 b8 78 2c 20 61 6e 	movabs rax,0x6f20646e61202c78
    27b0:	64 20 6f 
    27b3:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    27b8:	48 b8 73 20 69 73 20 	movabs rax,0x6c6c252073692073
    27bf:	25 6c 6c 
    27c2:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    27c7:	48 b8 74 69 6f 6e 20 	movabs rax,0x616962206e6f6974
    27ce:	62 69 61 
    27d1:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    27d6:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    27db:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
    27e2:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
    27e9:	31 d2                	xor    edx,edx
    27eb:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    27f0:	bf 2f 00 00 00       	mov    edi,0x2f
    27f5:	41 b8 06 00 00 00    	mov    r8d,0x6
    27fb:	e9 36 f7 ff ff       	jmp    1f36 <kprobe_unwind_hotspot+0x1f36>
    2800:	48 b9 73 70 2b 25 64 	movabs rcx,0xa2964252b7073
    2807:	29 0a 00 
    280a:	48 89 4c 24 78       	mov    QWORD PTR [rsp+0x78],rcx
    280f:	48 b9 78 20 28 66 72 	movabs rcx,0x206d6f7266282078
    2816:	6f 6d 20 
    2819:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    281e:	48 b9 20 61 73 20 30 	movabs rcx,0x6c25783020736120
    2825:	78 25 6c 
    2828:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    282d:	48 b9 65 63 6f 76 65 	movabs rcx,0x64657265766f6365
    2834:	72 65 64 
    2837:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    283c:	48 b9 6d 65 2c 20 70 	movabs rcx,0x72206370202c656d
    2843:	63 20 72 
    2846:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    284b:	48 b9 69 7a 65 64 20 	movabs rcx,0x6172662064657a69
    2852:	66 72 61 
    2855:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    285a:	48 b9 20 64 65 6f 70 	movabs rcx,0x6d6974706f656420
    2861:	74 69 6d 
    2864:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    2869:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    2870:	20 2d 3e 
    2873:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    2878:	48 63 8c 24 f4 00 00 	movsxd rcx,DWORD PTR [rsp+0xf4]
    287f:	00 
    2880:	31 d2                	xor    edx,edx
    2882:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    2887:	bf 40 00 00 00       	mov    edi,0x40
    288c:	41 b8 06 00 00 00    	mov    r8d,0x6
    2892:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    2896:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    289d:	00 
    289e:	e9 28 e7 ff ff       	jmp    fcb <kprobe_unwind_hotspot+0xfcb>
    28a3:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    28aa:	25 6c 78 
    28ad:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    28b2:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    28b9:	69 64 61 
    28bc:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    28c1:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    28c8:	20 70 63 
    28cb:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    28d0:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    28d7:	20 20 20 
    28da:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    28de:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    28e5:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    28ea:	31 c9                	xor    ecx,ecx
    28ec:	48 89 e2             	mov    rdx,rsp
    28ef:	be 22 00 00 00       	mov    esi,0x22
    28f4:	bf 03 00 00 00       	mov    edi,0x3
    28f9:	41 b8 06 00 00 00    	mov    r8d,0x6
    28ff:	e9 7d e9 ff ff       	jmp    1281 <kprobe_unwind_hotspot+0x1281>
    2904:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    290b:	25 6c 78 
    290e:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    2913:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    291a:	69 64 61 
    291d:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    2922:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    2929:	20 70 63 
    292c:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    2931:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    2938:	20 20 20 
    293b:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    293f:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    2946:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    294b:	31 c9                	xor    ecx,ecx
    294d:	48 89 e2             	mov    rdx,rsp
    2950:	be 22 00 00 00       	mov    esi,0x22
    2955:	bf 04 00 00 00       	mov    edi,0x4
    295a:	41 b8 06 00 00 00    	mov    r8d,0x6
    2960:	e9 bc e9 ff ff       	jmp    1321 <kprobe_unwind_hotspot+0x1321>
    2965:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    296c:	75 0a 00 
    296f:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    2974:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    297b:	74 61 67 
    297e:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2983:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    298a:	6e 74 20 
    298d:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2992:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    2999:	20 20 20 
    299c:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    29a1:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    29a5:	31 c9                	xor    ecx,ecx
    29a7:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    29ac:	be 1d 00 00 00       	mov    esi,0x1d
    29b1:	bf 06 00 00 00       	mov    edi,0x6
    29b6:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    29ba:	8d 48 01             	lea    ecx,[rax+0x1]
    29bd:	80 f9 02             	cmp    cl,0x2
    29c0:	0f 82 b7 d8 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    29c6:	e9 4b e2 ff ff       	jmp    c16 <kprobe_unwind_hotspot+0xc16>
    29cb:	48 b8 65 20 6f 6e 20 	movabs rax,0x657227206e6f2065
    29d2:	27 72 65 
    29d5:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    29da:	48 b8 20 65 70 69 6c 	movabs rax,0x75676f6c69706520
    29e1:	6f 67 75 
    29e4:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    29e9:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    29f0:	20 2d 3e 
    29f3:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    29f8:	c7 44 24 58 74 27 0a 	mov    DWORD PTR [rsp+0x58],0xa2774
    29ff:	00 
    2a00:	31 c0                	xor    eax,eax
    2a02:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    2a07:	be 1c 00 00 00       	mov    esi,0x1c
    2a0c:	bf 06 00 00 00       	mov    edi,0x6
    2a11:	e9 ed e8 ff ff       	jmp    1303 <kprobe_unwind_hotspot+0x1303>
    2a16:	48 b9 20 3d 20 25 6c 	movabs rcx,0xa786c25203d20
    2a1d:	78 0a 00 
    2a20:	48 89 4c 24 2d       	mov    QWORD PTR [rsp+0x2d],rcx
    2a25:	48 b9 2c 20 62 63 70 	movabs rcx,0x203d20706362202c
    2a2c:	20 3d 20 
    2a2f:	48 89 4c 24 28       	mov    QWORD PTR [rsp+0x28],rcx
    2a34:	48 b9 20 3d 20 30 78 	movabs rcx,0x786c257830203d20
    2a3b:	25 6c 78 
    2a3e:	48 89 4c 24 20       	mov    QWORD PTR [rsp+0x20],rcx
    2a43:	48 b9 20 63 6d 65 74 	movabs rcx,0x646f6874656d6320
    2a4a:	68 6f 64 
    2a4d:	48 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],rcx
    2a52:	48 b9 3d 20 30 78 25 	movabs rcx,0x2c786c257830203d
    2a59:	6c 78 2c 
    2a5c:	48 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],rcx
    2a61:	48 b9 20 6d 65 74 68 	movabs rcx,0x20646f6874656d20
    2a68:	6f 64 20 
    2a6b:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
    2a70:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    2a77:	20 2d 3e 
    2a7a:	48 89 0c 24          	mov    QWORD PTR [rsp],rcx
    2a7e:	48 89 e1             	mov    rcx,rsp
    2a81:	ba 35 00 00 00       	mov    edx,0x35
    2a86:	be 06 00 00 00       	mov    esi,0x6
    2a8b:	48 8b bc 24 b8 00 00 	mov    rdi,QWORD PTR [rsp+0xb8]
    2a92:	00 
    2a93:	48 8b 8c 24 08 01 00 	mov    rcx,QWORD PTR [rsp+0x108]
    2a9a:	00 
    2a9b:	48 89 8c 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rcx
    2aa2:	00 
    2aa3:	e9 a4 ed ff ff       	jmp    184c <kprobe_unwind_hotspot+0x184c>
    2aa8:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    2aaf:	25 6c 78 
    2ab2:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    2ab7:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    2abe:	69 64 61 
    2ac1:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    2ac6:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    2acd:	20 70 63 
    2ad0:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    2ad5:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    2adc:	20 20 20 
    2adf:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    2ae3:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    2aea:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    2aef:	31 c9                	xor    ecx,ecx
    2af1:	48 89 e2             	mov    rdx,rsp
    2af4:	be 22 00 00 00       	mov    esi,0x22
    2af9:	bf 05 00 00 00       	mov    edi,0x5
    2afe:	41 b8 06 00 00 00    	mov    r8d,0x6
    2b04:	e9 b8 e9 ff ff       	jmp    14c1 <kprobe_unwind_hotspot+0x14c1>
    2b09:	48 b8 74 63 68 20 25 	movabs rax,0xa642520686374
    2b10:	64 0a 00 
    2b13:	48 89 44 24 56       	mov    QWORD PTR [rsp+0x56],rax
    2b18:	48 b8 65 74 73 20 6d 	movabs rax,0x6374616d20737465
    2b1f:	61 74 63 
    2b22:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2b27:	48 b8 74 65 72 5f 6f 	movabs rax,0x7366666f5f726574
    2b2e:	66 66 73 
    2b31:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2b36:	48 b8 69 6e 74 65 72 	movabs rax,0x6572707265746e69
    2b3d:	70 72 65 
    2b40:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2b45:	0f b7 45 20          	movzx  eax,WORD PTR [rbp+0x20]
    2b49:	31 c9                	xor    ecx,ecx
    2b4b:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    2b50:	be 1e 00 00 00       	mov    esi,0x1e
    2b55:	bf 06 00 00 00       	mov    edi,0x6
    2b5a:	41 8b 86 80 13 00 00 	mov    eax,DWORD PTR [r14+0x1380]
    2b61:	8b 4d 20             	mov    ecx,DWORD PTR [rbp+0x20]
    2b64:	0f a3 c8             	bt     eax,ecx
    2b67:	0f 82 51 f4 ff ff    	jb     1fbe <kprobe_unwind_hotspot+0x1fbe>
    2b6d:	c7 04 24 00 00 00 00 	mov    DWORD PTR [rsp],0x0
    2b74:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 2b7b <kprobe_unwind_hotspot+0x2b7b>
			2b77: R_X86_64_REX_GOTPCRELX	metrics-0x4
    2b7b:	48 89 e6             	mov    rsi,rsp
    2b7e:	b8 01 00 00 00       	mov    eax,0x1
    2b83:	ff d0                	call   rax
    2b85:	48 85 c0             	test   rax,rax
    2b88:	74 05                	je     2b8f <kprobe_unwind_hotspot+0x2b8f>
    2b8a:	48 ff 00             	inc    QWORD PTR [rax]
    2b8d:	eb 10                	jmp    2b9f <kprobe_unwind_hotspot+0x2b9f>
    2b8f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2b96 <kprobe_unwind_hotspot+0x2b96>
			2b92: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2b96:	83 38 00             	cmp    DWORD PTR [rax],0x0
    2b99:	0f 85 c6 12 00 00    	jne    3e65 <kprobe_unwind_hotspot+0x3e65>
    2b9f:	0f b7 5d 20          	movzx  ebx,WORD PTR [rbp+0x20]
    2ba3:	31 ed                	xor    ebp,ebp
    2ba5:	83 fb 02             	cmp    ebx,0x2
    2ba8:	0f 85 89 d7 ff ff    	jne    337 <kprobe_unwind_hotspot+0x337>
    2bae:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x29
    2bb5:	29 00 00 00 
    2bb9:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 2bc0 <kprobe_unwind_hotspot+0x2bc0>
			2bbc: R_X86_64_REX_GOTPCRELX	metrics-0x4
    2bc0:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    2bc7:	00 
    2bc8:	b8 01 00 00 00       	mov    eax,0x1
    2bcd:	ff d0                	call   rax
    2bcf:	48 85 c0             	test   rax,rax
    2bd2:	0f 84 ba 00 00 00    	je     2c92 <kprobe_unwind_hotspot+0x2c92>
    2bd8:	48 ff 00             	inc    QWORD PTR [rax]
    2bdb:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2be2 <kprobe_unwind_hotspot+0x2be2>
			2bde: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2be2:	83 38 00             	cmp    DWORD PTR [rax],0x0
    2be5:	49 8b 86 d0 0e 00 00 	mov    rax,QWORD PTR [r14+0xed0]
    2bec:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    2bf3:	00 
    2bf4:	49 8b 86 d8 0e 00 00 	mov    rax,QWORD PTR [r14+0xed8]
    2bfb:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    2c02:	00 
    2c03:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
    2c0a:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    2c11:	00 
    2c12:	0f 84 b7 00 00 00    	je     2ccf <kprobe_unwind_hotspot+0x2ccf>
    2c18:	48 b8 6f 66 66 73 65 	movabs rax,0x252074657366666f
    2c1f:	74 20 25 
    2c22:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    2c27:	48 b8 72 74 20 25 6c 	movabs rax,0x202c786c25207472
    2c2e:	78 2c 20 
    2c31:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    2c36:	48 b8 63 6f 64 65 20 	movabs rax,0x6174732065646f63
    2c3d:	73 74 61 
    2c40:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    2c45:	48 b8 20 25 6c 78 20 	movabs rax,0x206e6920786c2520
    2c4c:	69 6e 20 
    2c4f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    2c54:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    2c5b:	20 2d 3e 
    2c5e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    2c63:	c7 44 24 68 6c 78 0a 	mov    DWORD PTR [rsp+0x68],0xa786c
    2c6a:	00 
    2c6b:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
    2c72:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
    2c79:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    2c7e:	be 2c 00 00 00       	mov    esi,0x2c
    2c83:	bf 06 00 00 00       	mov    edi,0x6
    2c88:	4c 8b 84 24 a8 00 00 	mov    r8,QWORD PTR [rsp+0xa8]
    2c8f:	00 
    2c90:	eb 3d                	jmp    2ccf <kprobe_unwind_hotspot+0x2ccf>
    2c92:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2c99 <kprobe_unwind_hotspot+0x2c99>
			2c95: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2c99:	83 38 00             	cmp    DWORD PTR [rax],0x0
    2c9c:	0f 85 60 05 00 00    	jne    3202 <kprobe_unwind_hotspot+0x3202>
    2ca2:	49 8b 86 d0 0e 00 00 	mov    rax,QWORD PTR [r14+0xed0]
    2ca9:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    2cb0:	00 
    2cb1:	49 8b 86 d8 0e 00 00 	mov    rax,QWORD PTR [r14+0xed8]
    2cb8:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    2cbf:	00 
    2cc0:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
    2cc7:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    2cce:	00 
    2ccf:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
    2cd4:	c4 c2 fb f7 9e 18 0f 	shrx   rbx,QWORD PTR [r14+0xf18],rax
    2cdb:	00 00 
    2cdd:	49 8b 8e 10 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf10]
    2ce4:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    2ceb:	ff ff 00 
    2cee:	48 21 c1             	and    rcx,rax
    2cf1:	49 89 cd             	mov    r13,rcx
    2cf4:	48 8d 14 0b          	lea    rdx,[rbx+rcx*1]
    2cf8:	48 89 e7             	mov    rdi,rsp
    2cfb:	b8 01 00 00 00       	mov    eax,0x1
    2d00:	b9 70 00 00 00       	mov    ecx,0x70
    2d05:	be 01 00 00 00       	mov    esi,0x1
    2d0a:	ff d1                	call   rcx
    2d0c:	48 85 c0             	test   rax,rax
    2d0f:	0f 85 03 d5 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    2d15:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2d1c <kprobe_unwind_hotspot+0x2d1c>
			2d18: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2d1c:	83 38 00             	cmp    DWORD PTR [rax],0x0
    2d1f:	0f 85 54 05 00 00    	jne    3279 <kprobe_unwind_hotspot+0x3279>
    2d25:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    2d29:	8d 48 01             	lea    ecx,[rax+0x1]
    2d2c:	80 f9 02             	cmp    cl,0x2
    2d2f:	0f 83 a5 05 00 00    	jae    32da <kprobe_unwind_hotspot+0x32da>
    2d35:	84 c0                	test   al,al
    2d37:	0f 85 db d4 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    2d3d:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
    2d42:	c4 e2 f9 f7 cb       	shlx   rcx,rbx,rax
    2d47:	49 03 8e 20 0f 00 00 	add    rcx,QWORD PTR [r14+0xf20]
    2d4e:	41 0f b6 47 1b       	movzx  eax,BYTE PTR [r15+0x1b]
    2d53:	48 01 c8             	add    rax,rcx
    2d56:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 2d5d <kprobe_unwind_hotspot+0x2d5d>
			2d59: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2d5d:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    2d60:	0f 85 1c 0f 00 00    	jne    3c82 <kprobe_unwind_hotspot+0x3c82>
    2d66:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    2d6d:	00 
    2d6e:	48 85 c0             	test   rax,rax
    2d71:	0f 84 ad d4 ff ff    	je     224 <kprobe_unwind_hotspot+0x224>
    2d77:	b9 00 02 00 00       	mov    ecx,0x200
    2d7c:	41 b8 70 00 00 00    	mov    r8d,0x70
    2d82:	48 8b 94 24 d0 00 00 	mov    rdx,QWORD PTR [rsp+0xd0]
    2d89:	00 
    2d8a:	4c 89 e7             	mov    rdi,r12
    2d8d:	be 00 02 00 00       	mov    esi,0x200
    2d92:	41 ff d0             	call   r8
    2d95:	48 85 c0             	test   rax,rax
    2d98:	0f 85 4e d5 ff ff    	jne    2ec <kprobe_unwind_hotspot+0x2ec>
    2d9e:	41 0f b7 4f 10       	movzx  ecx,WORD PTR [r15+0x10]
    2da3:	b8 01 00 00 00       	mov    eax,0x1
    2da8:	48 81 f9 f8 01 00 00 	cmp    rcx,0x1f8
    2daf:	0f 87 7e d5 ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    2db5:	41 0f b7 57 12       	movzx  edx,WORD PTR [r15+0x12]
    2dba:	48 81 fa fc 01 00 00 	cmp    rdx,0x1fc
    2dc1:	0f 87 6c d5 ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    2dc7:	41 0f b7 77 14       	movzx  esi,WORD PTR [r15+0x14]
    2dcc:	48 81 fe f8 01 00 00 	cmp    rsi,0x1f8
    2dd3:	0f 87 5a d5 ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    2dd9:	41 0f b6 47 17       	movzx  eax,BYTE PTR [r15+0x17]
    2dde:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
    2de2:	48 89 84 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rax
    2de9:	00 
    2dea:	41 0f b6 47 18       	movzx  eax,BYTE PTR [r15+0x18]
    2def:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
    2df3:	48 89 84 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rax
    2dfa:	00 
    2dfb:	41 0f b6 47 1a       	movzx  eax,BYTE PTR [r15+0x1a]
    2e00:	41 8b 04 04          	mov    eax,DWORD PTR [r12+rax*1]
    2e04:	c1 e0 03             	shl    eax,0x3
    2e07:	89 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],eax
    2e0e:	41 0f b6 47 19       	movzx  eax,BYTE PTR [r15+0x19]
    2e13:	41 0f b7 04 04       	movzx  eax,WORD PTR [r12+rax*1]
    2e18:	66 89 84 24 00 01 00 	mov    WORD PTR [rsp+0x100],ax
    2e1f:	00 
    2e20:	41 8b 04 14          	mov    eax,DWORD PTR [r12+rdx*1]
    2e24:	89 84 24 fc 00 00 00 	mov    DWORD PTR [rsp+0xfc],eax
    2e2b:	41 8b 04 34          	mov    eax,DWORD PTR [r12+rsi*1]
    2e2f:	89 84 24 f4 00 00 00 	mov    DWORD PTR [rsp+0xf4],eax
    2e36:	49 8b 04 0c          	mov    rax,QWORD PTR [r12+rcx*1]
    2e3a:	48 89 84 24 e8 00 00 	mov    QWORD PTR [rsp+0xe8],rax
    2e41:	00 
    2e42:	41 0f b6 47 16       	movzx  eax,BYTE PTR [r15+0x16]
    2e47:	49 8b 14 04          	mov    rdx,QWORD PTR [r12+rax*1]
    2e4b:	b8 04 00 00 00       	mov    eax,0x4
    2e50:	b9 70 00 00 00       	mov    ecx,0x70
    2e55:	48 8d bc 24 f0 00 00 	lea    rdi,[rsp+0xf0]
    2e5c:	00 
    2e5d:	be 04 00 00 00       	mov    esi,0x4
    2e62:	ff d1                	call   rcx
    2e64:	48 85 c0             	test   rax,rax
    2e67:	0f 85 7f d4 ff ff    	jne    2ec <kprobe_unwind_hotspot+0x2ec>
    2e6d:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
    2e72:	74 2c                	je     2ea0 <kprobe_unwind_hotspot+0x2ea0>
    2e74:	48 8b 84 24 d0 00 00 	mov    rax,QWORD PTR [rsp+0xd0]
    2e7b:	00 
    2e7c:	8b 8c 24 d8 00 00 00 	mov    ecx,DWORD PTR [rsp+0xd8]
    2e83:	48 01 c1             	add    rcx,rax
    2e86:	48 89 8c 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rcx
    2e8d:	00 
    2e8e:	8b 8c 24 e0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xe0]
    2e95:	48 01 c1             	add    rcx,rax
    2e98:	48 89 8c 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rcx
    2e9f:	00 
    2ea0:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2ea7 <kprobe_unwind_hotspot+0x2ea7>
			2ea3: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2ea7:	83 38 00             	cmp    DWORD PTR [rax],0x0
    2eaa:	0f 85 27 19 00 00    	jne    47d7 <kprobe_unwind_hotspot+0x47d7>
    2eb0:	48 8b 84 24 d0 00 00 	mov    rax,QWORD PTR [rsp+0xd0]
    2eb7:	00 
    2eb8:	48 89 84 24 18 01 00 	mov    QWORD PTR [rsp+0x118],rax
    2ebf:	00 
    2ec0:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
    2ec7:	00 
    2ec8:	8b 94 24 f0 00 00 00 	mov    edx,DWORD PTR [rsp+0xf0]
    2ecf:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
    2ed6:	00 
    2ed7:	29 c1                	sub    ecx,eax
    2ed9:	48 89 8c 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rcx
    2ee0:	00 
    2ee1:	48 89 d1             	mov    rcx,rdx
    2ee4:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    2eeb:	00 
    2eec:	81 fa 6d 61 74 69    	cmp    edx,0x6974616d
    2ef2:	0f 8f ed 00 00 00    	jg     2fe5 <kprobe_unwind_hotspot+0x2fe5>
    2ef8:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x62617476
    2eff:	76 74 61 62 
    2f03:	0f 84 2b 02 00 00    	je     3134 <kprobe_unwind_hotspot+0x3134>
    2f09:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x65746e49
    2f10:	49 6e 74 65 
    2f14:	0f 85 55 02 00 00    	jne    316f <kprobe_unwind_hotspot+0x316f>
    2f1a:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    2f21:	00 
    2f22:	48 39 84 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],rax
    2f29:	00 
    2f2a:	0f 82 be 06 00 00    	jb     35ee <kprobe_unwind_hotspot+0x35ee>
    2f30:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    2f37:	00 
    2f38:	48 05 00 10 00 00    	add    rax,0x1000
    2f3e:	48 39 84 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],rax
    2f45:	00 
    2f46:	0f 83 a2 06 00 00    	jae    35ee <kprobe_unwind_hotspot+0x35ee>
    2f4c:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
    2f53:	00 
    2f54:	48 8d 50 b0          	lea    rdx,[rax-0x50]
    2f58:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    2f5d:	b8 60 00 00 00       	mov    eax,0x60
    2f62:	b9 70 00 00 00       	mov    ecx,0x70
    2f67:	be 60 00 00 00       	mov    esi,0x60
    2f6c:	ff d1                	call   rcx
    2f6e:	48 85 c0             	test   rax,rax
    2f71:	0f 84 73 0d 00 00    	je     3cea <kprobe_unwind_hotspot+0x3cea>
    2f77:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2f7e <kprobe_unwind_hotspot+0x2f7e>
			2f7a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    2f7e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    2f81:	0f 84 77 06 00 00    	je     35fe <kprobe_unwind_hotspot+0x35fe>
    2f87:	48 b8 20 66 72 61 6d 	movabs rax,0xa656d61726620
    2f8e:	65 0a 00 
    2f91:	48 89 44 24 1f       	mov    QWORD PTR [rsp+0x1f],rax
    2f96:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
    2f9d:	65 72 20 
    2fa0:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    2fa5:	48 b8 65 61 64 20 69 	movabs rax,0x65746e6920646165
    2fac:	6e 74 65 
    2faf:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    2fb4:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    2fbb:	6f 20 72 
    2fbe:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    2fc3:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    2fca:	66 61 69 
    2fcd:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    2fd1:	31 c0                	xor    eax,eax
    2fd3:	48 89 e1             	mov    rcx,rsp
    2fd6:	ba 27 00 00 00       	mov    edx,0x27
    2fdb:	be 06 00 00 00       	mov    esi,0x6
    2fe0:	e9 19 06 00 00       	jmp    35fe <kprobe_unwind_hotspot+0x35fe>
    2fe5:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x6974616e
    2fec:	6e 61 74 69 
    2ff0:	74 11                	je     3003 <kprobe_unwind_hotspot+0x3003>
    2ff2:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x74656d6e
    2ff9:	6e 6d 65 74 
    2ffd:	0f 85 6c 01 00 00    	jne    316f <kprobe_unwind_hotspot+0x316f>
    3003:	8b 8c 24 fc 00 00 00 	mov    ecx,DWORD PTR [rsp+0xfc]
    300a:	48 89 8c 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rcx
    3011:	00 
    3012:	48 8b 8c 24 e8 00 00 	mov    rcx,QWORD PTR [rsp+0xe8]
    3019:	00 
    301a:	89 ca                	mov    edx,ecx
    301c:	48 03 94 24 18 01 00 	add    rdx,QWORD PTR [rsp+0x118]
    3023:	00 
    3024:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
    3029:	48 0f 44 d1          	cmove  rdx,rcx
    302d:	48 39 94 24 a8 00 00 	cmp    QWORD PTR [rsp+0xa8],rdx
    3034:	00 
    3035:	75 53                	jne    308a <kprobe_unwind_hotspot+0x308a>
    3037:	8b 84 24 f4 00 00 00 	mov    eax,DWORD PTR [rsp+0xf4]
    303e:	48 8b b4 24 b0 00 00 	mov    rsi,QWORD PTR [rsp+0xb0]
    3045:	00 
    3046:	48 01 f0             	add    rax,rsi
    3049:	48 89 e7             	mov    rdi,rsp
    304c:	b9 08 00 00 00       	mov    ecx,0x8
    3051:	41 b8 70 00 00 00    	mov    r8d,0x70
    3057:	8b 94 24 f4 00 00 00 	mov    edx,DWORD PTR [rsp+0xf4]
    305e:	48 01 f2             	add    rdx,rsi
    3061:	be 08 00 00 00       	mov    esi,0x8
    3066:	41 ff d0             	call   r8
    3069:	48 85 c0             	test   rax,rax
    306c:	0f 84 a1 0a 00 00    	je     3b13 <kprobe_unwind_hotspot+0x3b13>
    3072:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3079 <kprobe_unwind_hotspot+0x3079>
			3075: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3079:	83 38 00             	cmp    DWORD PTR [rax],0x0
    307c:	0f 85 f9 1a 00 00    	jne    4b7b <kprobe_unwind_hotspot+0x4b7b>
    3082:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
    3089:	00 
    308a:	0f b7 8c 24 00 01 00 	movzx  ecx,WORD PTR [rsp+0x100]
    3091:	00 
    3092:	48 01 c1             	add    rcx,rax
    3095:	48 39 8c 24 a8 00 00 	cmp    QWORD PTR [rsp+0xa8],rcx
    309c:	00 
    309d:	0f 83 03 01 00 00    	jae    31a6 <kprobe_unwind_hotspot+0x31a6>
    30a3:	48 83 c1 fc          	add    rcx,0xfffffffffffffffc
    30a7:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 30ae <kprobe_unwind_hotspot+0x30ae>
			30aa: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    30ae:	8b 00                	mov    eax,DWORD PTR [rax]
    30b0:	48 39 8c 24 a8 00 00 	cmp    QWORD PTR [rsp+0xa8],rcx
    30b7:	00 
    30b8:	0f 83 72 05 00 00    	jae    3630 <kprobe_unwind_hotspot+0x3630>
    30be:	b1 03                	mov    cl,0x3
    30c0:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    30c7:	85 c0                	test   eax,eax
    30c9:	0f 84 8b 00 00 00    	je     315a <kprobe_unwind_hotspot+0x315a>
    30cf:	48 b8 61 6d 65 20 28 	movabs rax,0x2963702820656d61
    30d6:	70 63 29 
    30d9:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    30de:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
    30e5:	20 66 72 
    30e8:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    30ed:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
    30f4:	63 6f 6d 
    30f7:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    30fc:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    3103:	6e 64 69 
    3106:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    310b:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    3112:	20 2d 3e 
    3115:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    311a:	66 c7 44 24 68 0a 00 	mov    WORD PTR [rsp+0x68],0xa
    3121:	31 c0                	xor    eax,eax
    3123:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    3128:	ba 2a 00 00 00       	mov    edx,0x2a
    312d:	be 06 00 00 00       	mov    esi,0x6
    3132:	eb 26                	jmp    315a <kprobe_unwind_hotspot+0x315a>
    3134:	b0 01                	mov    al,0x1
    3136:	89 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],eax
    313d:	b8 76 74 61 62       	mov    eax,0x62617476
    3142:	48 89 84 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rax
    3149:	00 
    314a:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3151 <kprobe_unwind_hotspot+0x3151>
			314d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3151:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3154:	0f 85 84 19 00 00    	jne    4ade <kprobe_unwind_hotspot+0x4ade>
    315a:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x8
    3161:	08 00 00 00 
    3165:	b8 08 00 00 00       	mov    eax,0x8
    316a:	e9 f2 04 00 00       	jmp    3661 <kprobe_unwind_hotspot+0x3661>
    316f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3176 <kprobe_unwind_hotspot+0x3176>
			3172: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3176:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3179:	0f 85 a2 19 00 00    	jne    4b21 <kprobe_unwind_hotspot+0x4b21>
    317f:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
    3186:	c7 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],0x0
    318d:	00 00 00 00 
    3191:	48 8b 8c 24 b8 00 00 	mov    rcx,QWORD PTR [rsp+0xb8]
    3198:	00 
    3199:	85 c0                	test   eax,eax
    319b:	0f 85 c0 04 00 00    	jne    3661 <kprobe_unwind_hotspot+0x3661>
    31a1:	e9 a3 04 00 00       	jmp    3649 <kprobe_unwind_hotspot+0x3649>
    31a6:	8b 9c 24 f8 00 00 00 	mov    ebx,DWORD PTR [rsp+0xf8]
    31ad:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
    31b4:	00 
    31b5:	48 8b 8c 24 b0 00 00 	mov    rcx,QWORD PTR [rsp+0xb0]
    31bc:	00 
    31bd:	4c 8d 2c 19          	lea    r13,[rcx+rbx*1]
    31c1:	49 83 c5 30          	add    r13,0x30
    31c5:	48 29 c8             	sub    rax,rcx
    31c8:	0f 82 cc 07 00 00    	jb     399a <kprobe_unwind_hotspot+0x399a>
    31ce:	4c 39 ac 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],r13
    31d5:	00 
    31d6:	0f 83 be 07 00 00    	jae    399a <kprobe_unwind_hotspot+0x399a>
    31dc:	b1 03                	mov    cl,0x3
    31de:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    31e5:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 31ec <kprobe_unwind_hotspot+0x31ec>
			31e8: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    31ec:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    31ef:	0f 85 69 1a 00 00    	jne    4c5e <kprobe_unwind_hotspot+0x4c5e>
    31f5:	48 8b 8c 24 b8 00 00 	mov    rcx,QWORD PTR [rsp+0xb8]
    31fc:	00 
    31fd:	e9 47 04 00 00       	jmp    3649 <kprobe_unwind_hotspot+0x3649>
    3202:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    3209:	64 0a 00 
    320c:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    3211:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    3218:	69 63 49 
    321b:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    3220:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    3227:	66 6f 72 
    322a:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    322f:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    3236:	69 63 73 
    3239:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    323e:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    3245:	6b 75 70 
    3248:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    324d:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    3254:	64 20 74 
    3257:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    325c:	8b 84 24 d0 00 00 00 	mov    eax,DWORD PTR [rsp+0xd0]
    3263:	31 c9                	xor    ecx,ecx
    3265:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    326a:	be 2e 00 00 00       	mov    esi,0x2e
    326f:	bf 06 00 00 00       	mov    edi,0x6
    3274:	e9 62 f9 ff ff       	jmp    2bdb <kprobe_unwind_hotspot+0x2bdb>
    3279:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    3280:	75 0a 00 
    3283:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    3288:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    328f:	74 61 67 
    3292:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    3297:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    329e:	6e 74 20 
    32a1:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    32a6:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    32ad:	20 20 20 
    32b0:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    32b5:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    32b9:	31 c9                	xor    ecx,ecx
    32bb:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    32c0:	be 1d 00 00 00       	mov    esi,0x1d
    32c5:	bf 06 00 00 00       	mov    edi,0x6
    32ca:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    32ce:	8d 48 01             	lea    ecx,[rax+0x1]
    32d1:	80 f9 02             	cmp    cl,0x2
    32d4:	0f 82 5b fa ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    32da:	0f b6 c0             	movzx  eax,al
    32dd:	48 29 c3             	sub    rbx,rax
    32e0:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    32e4:	48 89 e7             	mov    rdi,rsp
    32e7:	b8 01 00 00 00       	mov    eax,0x1
    32ec:	b9 70 00 00 00       	mov    ecx,0x70
    32f1:	be 01 00 00 00       	mov    esi,0x1
    32f6:	ff d1                	call   rcx
    32f8:	48 85 c0             	test   rax,rax
    32fb:	0f 85 17 cf ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    3301:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3308 <kprobe_unwind_hotspot+0x3308>
			3304: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3308:	83 38 00             	cmp    DWORD PTR [rax],0x0
    330b:	0f 85 fc 09 00 00    	jne    3d0d <kprobe_unwind_hotspot+0x3d0d>
    3311:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3315:	8d 48 01             	lea    ecx,[rax+0x1]
    3318:	80 f9 02             	cmp    cl,0x2
    331b:	0f 82 14 fa ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    3321:	0f b6 c0             	movzx  eax,al
    3324:	48 29 c3             	sub    rbx,rax
    3327:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    332b:	48 89 e7             	mov    rdi,rsp
    332e:	b8 01 00 00 00       	mov    eax,0x1
    3333:	b9 70 00 00 00       	mov    ecx,0x70
    3338:	be 01 00 00 00       	mov    esi,0x1
    333d:	ff d1                	call   rcx
    333f:	48 85 c0             	test   rax,rax
    3342:	0f 85 d0 ce ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    3348:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 334f <kprobe_unwind_hotspot+0x334f>
			334b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    334f:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3352:	0f 85 4d 0e 00 00    	jne    41a5 <kprobe_unwind_hotspot+0x41a5>
    3358:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    335c:	8d 48 01             	lea    ecx,[rax+0x1]
    335f:	80 f9 02             	cmp    cl,0x2
    3362:	0f 82 cd f9 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    3368:	0f b6 c0             	movzx  eax,al
    336b:	48 29 c3             	sub    rbx,rax
    336e:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    3372:	48 89 e7             	mov    rdi,rsp
    3375:	b8 01 00 00 00       	mov    eax,0x1
    337a:	b9 70 00 00 00       	mov    ecx,0x70
    337f:	be 01 00 00 00       	mov    esi,0x1
    3384:	ff d1                	call   rcx
    3386:	48 85 c0             	test   rax,rax
    3389:	0f 85 89 ce ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    338f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3396 <kprobe_unwind_hotspot+0x3396>
			3392: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3396:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3399:	0f 85 10 0f 00 00    	jne    42af <kprobe_unwind_hotspot+0x42af>
    339f:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    33a3:	8d 48 01             	lea    ecx,[rax+0x1]
    33a6:	80 f9 02             	cmp    cl,0x2
    33a9:	0f 82 86 f9 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    33af:	0f b6 c0             	movzx  eax,al
    33b2:	48 29 c3             	sub    rbx,rax
    33b5:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    33b9:	48 89 e7             	mov    rdi,rsp
    33bc:	b8 01 00 00 00       	mov    eax,0x1
    33c1:	b9 70 00 00 00       	mov    ecx,0x70
    33c6:	be 01 00 00 00       	mov    esi,0x1
    33cb:	ff d1                	call   rcx
    33cd:	48 85 c0             	test   rax,rax
    33d0:	0f 85 42 ce ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    33d6:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 33dd <kprobe_unwind_hotspot+0x33dd>
			33d9: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    33dd:	83 38 00             	cmp    DWORD PTR [rax],0x0
    33e0:	0f 85 e3 14 00 00    	jne    48c9 <kprobe_unwind_hotspot+0x48c9>
    33e6:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    33ea:	8d 48 01             	lea    ecx,[rax+0x1]
    33ed:	80 f9 02             	cmp    cl,0x2
    33f0:	0f 82 3f f9 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    33f6:	0f b6 c0             	movzx  eax,al
    33f9:	48 29 c3             	sub    rbx,rax
    33fc:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    3400:	48 89 e7             	mov    rdi,rsp
    3403:	b8 01 00 00 00       	mov    eax,0x1
    3408:	b9 70 00 00 00       	mov    ecx,0x70
    340d:	be 01 00 00 00       	mov    esi,0x1
    3412:	ff d1                	call   rcx
    3414:	48 85 c0             	test   rax,rax
    3417:	0f 85 fb cd ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    341d:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3424 <kprobe_unwind_hotspot+0x3424>
			3420: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3424:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3427:	0f 85 e1 19 00 00    	jne    4e0e <kprobe_unwind_hotspot+0x4e0e>
    342d:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3431:	8d 48 01             	lea    ecx,[rax+0x1]
    3434:	80 f9 02             	cmp    cl,0x2
    3437:	0f 82 f8 f8 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    343d:	0f b6 c0             	movzx  eax,al
    3440:	48 29 c3             	sub    rbx,rax
    3443:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    3447:	48 89 e7             	mov    rdi,rsp
    344a:	b8 01 00 00 00       	mov    eax,0x1
    344f:	b9 70 00 00 00       	mov    ecx,0x70
    3454:	be 01 00 00 00       	mov    esi,0x1
    3459:	ff d1                	call   rcx
    345b:	48 85 c0             	test   rax,rax
    345e:	0f 85 b4 cd ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    3464:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 346b <kprobe_unwind_hotspot+0x346b>
			3467: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    346b:	83 38 00             	cmp    DWORD PTR [rax],0x0
    346e:	0f 85 4f 1f 00 00    	jne    53c3 <kprobe_unwind_hotspot+0x53c3>
    3474:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3478:	8d 48 01             	lea    ecx,[rax+0x1]
    347b:	80 f9 02             	cmp    cl,0x2
    347e:	0f 82 b1 f8 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    3484:	0f b6 c0             	movzx  eax,al
    3487:	48 29 c3             	sub    rbx,rax
    348a:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    348e:	48 89 e7             	mov    rdi,rsp
    3491:	b8 01 00 00 00       	mov    eax,0x1
    3496:	b9 70 00 00 00       	mov    ecx,0x70
    349b:	be 01 00 00 00       	mov    esi,0x1
    34a0:	ff d1                	call   rcx
    34a2:	48 85 c0             	test   rax,rax
    34a5:	0f 85 6d cd ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    34ab:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 34b2 <kprobe_unwind_hotspot+0x34b2>
			34ae: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    34b2:	83 38 00             	cmp    DWORD PTR [rax],0x0
    34b5:	0f 85 1a 29 00 00    	jne    5dd5 <kprobe_unwind_hotspot+0x5dd5>
    34bb:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    34bf:	8d 48 01             	lea    ecx,[rax+0x1]
    34c2:	80 f9 02             	cmp    cl,0x2
    34c5:	0f 82 6a f8 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    34cb:	0f b6 c0             	movzx  eax,al
    34ce:	48 29 c3             	sub    rbx,rax
    34d1:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    34d5:	48 89 e7             	mov    rdi,rsp
    34d8:	b8 01 00 00 00       	mov    eax,0x1
    34dd:	b9 70 00 00 00       	mov    ecx,0x70
    34e2:	be 01 00 00 00       	mov    esi,0x1
    34e7:	ff d1                	call   rcx
    34e9:	48 85 c0             	test   rax,rax
    34ec:	0f 85 26 cd ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    34f2:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 34f9 <kprobe_unwind_hotspot+0x34f9>
			34f5: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    34f9:	83 38 00             	cmp    DWORD PTR [rax],0x0
    34fc:	0f 85 fe 2c 00 00    	jne    6200 <kprobe_unwind_hotspot+0x6200>
    3502:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3506:	8d 48 01             	lea    ecx,[rax+0x1]
    3509:	80 f9 02             	cmp    cl,0x2
    350c:	0f 82 23 f8 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    3512:	0f b6 c0             	movzx  eax,al
    3515:	48 29 c3             	sub    rbx,rax
    3518:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    351c:	48 89 e7             	mov    rdi,rsp
    351f:	b8 01 00 00 00       	mov    eax,0x1
    3524:	b9 70 00 00 00       	mov    ecx,0x70
    3529:	be 01 00 00 00       	mov    esi,0x1
    352e:	ff d1                	call   rcx
    3530:	48 85 c0             	test   rax,rax
    3533:	0f 85 df cc ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    3539:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3540 <kprobe_unwind_hotspot+0x3540>
			353c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3540:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3543:	0f 85 06 30 00 00    	jne    654f <kprobe_unwind_hotspot+0x654f>
    3549:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    354d:	8d 48 01             	lea    ecx,[rax+0x1]
    3550:	80 f9 02             	cmp    cl,0x2
    3553:	0f 82 dc f7 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    3559:	0f b6 c0             	movzx  eax,al
    355c:	48 29 c3             	sub    rbx,rax
    355f:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    3563:	48 89 e7             	mov    rdi,rsp
    3566:	b8 01 00 00 00       	mov    eax,0x1
    356b:	b9 70 00 00 00       	mov    ecx,0x70
    3570:	be 01 00 00 00       	mov    esi,0x1
    3575:	ff d1                	call   rcx
    3577:	48 85 c0             	test   rax,rax
    357a:	0f 85 98 cc ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    3580:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3587 <kprobe_unwind_hotspot+0x3587>
			3583: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3587:	83 38 00             	cmp    DWORD PTR [rax],0x0
    358a:	0f 85 b4 30 00 00    	jne    6644 <kprobe_unwind_hotspot+0x6644>
    3590:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3594:	8d 48 01             	lea    ecx,[rax+0x1]
    3597:	80 f9 02             	cmp    cl,0x2
    359a:	0f 82 95 f7 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    35a0:	0f b6 c0             	movzx  eax,al
    35a3:	48 29 c3             	sub    rbx,rax
    35a6:	49 01 dd             	add    r13,rbx
    35a9:	48 89 e7             	mov    rdi,rsp
    35ac:	b8 01 00 00 00       	mov    eax,0x1
    35b1:	b9 70 00 00 00       	mov    ecx,0x70
    35b6:	be 01 00 00 00       	mov    esi,0x1
    35bb:	4c 89 ea             	mov    rdx,r13
    35be:	ff d1                	call   rcx
    35c0:	48 85 c0             	test   rax,rax
    35c3:	0f 85 4f cc ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    35c9:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 35d0 <kprobe_unwind_hotspot+0x35d0>
			35cc: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    35d0:	83 38 00             	cmp    DWORD PTR [rax],0x0
    35d3:	0f 85 d1 30 00 00    	jne    66aa <kprobe_unwind_hotspot+0x66aa>
    35d9:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    35dd:	8d 48 01             	lea    ecx,[rax+0x1]
    35e0:	80 f9 01             	cmp    cl,0x1
    35e3:	0f 87 2f cc ff ff    	ja     218 <kprobe_unwind_hotspot+0x218>
    35e9:	e9 47 f7 ff ff       	jmp    2d35 <kprobe_unwind_hotspot+0x2d35>
    35ee:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 35f5 <kprobe_unwind_hotspot+0x35f5>
			35f1: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    35f5:	83 38 00             	cmp    DWORD PTR [rax],0x0
    35f8:	0f 85 d8 16 00 00    	jne    4cd6 <kprobe_unwind_hotspot+0x4cd6>
    35fe:	c7 84 24 14 01 00 00 	mov    DWORD PTR [rsp+0x114],0x2d
    3605:	2d 00 00 00 
    3609:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 3610 <kprobe_unwind_hotspot+0x3610>
			360c: R_X86_64_REX_GOTPCRELX	metrics-0x4
    3610:	48 8d b4 24 14 01 00 	lea    rsi,[rsp+0x114]
    3617:	00 
    3618:	b8 01 00 00 00       	mov    eax,0x1
    361d:	ff d0                	call   rax
    361f:	48 85 c0             	test   rax,rax
    3622:	0f 84 37 05 00 00    	je     3b5f <kprobe_unwind_hotspot+0x3b5f>
    3628:	48 ff 00             	inc    QWORD PTR [rax]
    362b:	e9 3f 05 00 00       	jmp    3b6f <kprobe_unwind_hotspot+0x3b6f>
    3630:	b1 03                	mov    cl,0x3
    3632:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    3639:	85 c0                	test   eax,eax
    363b:	0f 85 02 17 00 00    	jne    4d43 <kprobe_unwind_hotspot+0x4d43>
    3641:	48 8b 8c 24 b0 00 00 	mov    rcx,QWORD PTR [rsp+0xb0]
    3648:	00 
    3649:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x10
    3650:	10 00 00 00 
    3654:	b8 10 00 00 00       	mov    eax,0x10
    3659:	48 89 8c 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rcx
    3660:	00 
    3661:	89 c0                	mov    eax,eax
    3663:	48 01 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],rax
    366a:	00 
    366b:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    3672:	00 
    3673:	48 8d 50 f0          	lea    rdx,[rax-0x10]
    3677:	48 89 e7             	mov    rdi,rsp
    367a:	b8 10 00 00 00       	mov    eax,0x10
    367f:	b9 70 00 00 00       	mov    ecx,0x70
    3684:	be 10 00 00 00       	mov    esi,0x10
    3689:	ff d1                	call   rcx
    368b:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    3690:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    3697:	00 
    3698:	83 bc 24 f8 00 00 00 	cmp    DWORD PTR [rsp+0xf8],0x10
    369f:	10 
    36a0:	72 1c                	jb     36be <kprobe_unwind_hotspot+0x36be>
    36a2:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 36a9 <kprobe_unwind_hotspot+0x36a9>
			36a5: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    36a9:	83 38 00             	cmp    DWORD PTR [rax],0x0
    36ac:	0f 85 ed 12 00 00    	jne    499f <kprobe_unwind_hotspot+0x499f>
    36b2:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    36b6:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    36bd:	00 
    36be:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    36c5:	48 83 f8 7e          	cmp    rax,0x7e
    36c9:	0f 87 e7 d7 ff ff    	ja     eb6 <kprobe_unwind_hotspot+0xeb6>
    36cf:	41 0f b6 8e 30 0f 00 	movzx  ecx,BYTE PTR [r14+0xf30]
    36d6:	00 
    36d7:	0f b6 94 24 c8 00 00 	movzx  edx,BYTE PTR [rsp+0xc8]
    36de:	00 
    36df:	48 c1 e2 3c          	shl    rdx,0x3c
    36e3:	48 8b bc 24 20 01 00 	mov    rdi,QWORD PTR [rsp+0x120]
    36ea:	00 
    36eb:	48 c1 e7 20          	shl    rdi,0x20
    36ef:	8b b4 24 c0 00 00 00 	mov    esi,DWORD PTR [rsp+0xc0]
    36f6:	48 09 fe             	or     rsi,rdi
    36f9:	48 09 d6             	or     rsi,rdx
    36fc:	8d 50 01             	lea    edx,[rax+0x1]
    36ff:	41 89 96 c0 02 00 00 	mov    DWORD PTR [r14+0x2c0],edx
    3706:	48 8d 04 40          	lea    rax,[rax+rax*2]
    370a:	48 8b 94 24 18 01 00 	mov    rdx,QWORD PTR [rsp+0x118]
    3711:	00 
    3712:	49 89 94 c6 d0 02 00 	mov    QWORD PTR [r14+rax*8+0x2d0],rdx
    3719:	00 
    371a:	49 89 b4 c6 d8 02 00 	mov    QWORD PTR [r14+rax*8+0x2d8],rsi
    3721:	00 
    3722:	41 c6 84 c6 e0 02 00 	mov    BYTE PTR [r14+rax*8+0x2e0],0x5
    3729:	00 05 
    372b:	41 88 8c c6 e1 02 00 	mov    BYTE PTR [r14+rax*8+0x2e1],cl
    3732:	00 
    3733:	41 c7 84 c6 e2 02 00 	mov    DWORD PTR [r14+rax*8+0x2e2],0x0
    373a:	00 00 00 00 00 
    373f:	66 41 c7 84 c6 e6 02 	mov    WORD PTR [r14+rax*8+0x2e6],0x0
    3746:	00 00 00 00 
    374a:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3751 <kprobe_unwind_hotspot+0x3751>
			374d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3751:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3754:	0f 85 d5 11 00 00    	jne    492f <kprobe_unwind_hotspot+0x492f>
    375a:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    3761:	00 
    3762:	49 89 86 d0 0e 00 00 	mov    QWORD PTR [r14+0xed0],rax
    3769:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    3770:	00 
    3771:	49 89 86 d8 0e 00 00 	mov    QWORD PTR [r14+0xed8],rax
    3778:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
    377f:	00 
    3780:	49 89 86 e0 0e 00 00 	mov    QWORD PTR [r14+0xee0],rax
    3787:	41 c6 86 30 0f 00 00 	mov    BYTE PTR [r14+0xf30],0x1
    378e:	01 
    378f:	c7 04 24 2a 00 00 00 	mov    DWORD PTR [rsp],0x2a
    3796:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 379d <kprobe_unwind_hotspot+0x379d>
			3799: R_X86_64_REX_GOTPCRELX	metrics-0x4
    379d:	48 89 e6             	mov    rsi,rsp
    37a0:	b8 01 00 00 00       	mov    eax,0x1
    37a5:	ff d0                	call   rax
    37a7:	48 85 c0             	test   rax,rax
    37aa:	74 0e                	je     37ba <kprobe_unwind_hotspot+0x37ba>
    37ac:	48 ff 00             	inc    QWORD PTR [rax]
    37af:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 37b6 <kprobe_unwind_hotspot+0x37b6>
			37b2: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    37b6:	8b 00                	mov    eax,DWORD PTR [rax]
    37b8:	eb 12                	jmp    37cc <kprobe_unwind_hotspot+0x37cc>
    37ba:	31 c0                	xor    eax,eax
    37bc:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 37c3 <kprobe_unwind_hotspot+0x37c3>
			37bf: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    37c3:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    37c6:	0f 85 1f 14 00 00    	jne    4beb <kprobe_unwind_hotspot+0x4beb>
    37cc:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    37d3:	4d 85 ed             	test   r13,r13
    37d6:	0f 84 43 ea ff ff    	je     221f <kprobe_unwind_hotspot+0x221f>
    37dc:	85 c0                	test   eax,eax
    37de:	0f 85 fe 11 00 00    	jne    49e2 <kprobe_unwind_hotspot+0x49e2>
    37e4:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    37eb:	ff ff 00 
    37ee:	49 39 c5             	cmp    r13,rax
    37f1:	0f 87 e3 de ff ff    	ja     16da <kprobe_unwind_hotspot+0x16da>
    37f7:	49 81 fd 00 10 00 00 	cmp    r13,0x1000
    37fe:	0f 82 85 e6 ff ff    	jb     1e89 <kprobe_unwind_hotspot+0x1e89>
    3804:	41 8b 06             	mov    eax,DWORD PTR [r14]
    3807:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x60
    380e:	60 00 00 00 
    3812:	0f 38 f1 84 24 d4 00 	movbe  DWORD PTR [rsp+0xd4],eax
    3819:	00 00 
    381b:	4c 0f 38 f1 ac 24 d8 	movbe  QWORD PTR [rsp+0xd8],r13
    3822:	00 00 00 
    3825:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 382c <kprobe_unwind_hotspot+0x382c>
			3828: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    382c:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    3833:	00 
    3834:	b8 01 00 00 00       	mov    eax,0x1
    3839:	ff d0                	call   rax
    383b:	48 85 c0             	test   rax,rax
    383e:	0f 84 2e 5f 00 00    	je     9772 <kprobe_unwind_hotspot+0x9772>
    3844:	48 8b 58 08          	mov    rbx,QWORD PTR [rax+0x8]
    3848:	48 89 d9             	mov    rcx,rbx
    384b:	48 ba ff ff ff ff ff 	movabs rdx,0xffffffffffffff
    3852:	ff ff 00 
    3855:	48 21 d1             	and    rcx,rdx
    3858:	49 89 8e 20 0f 00 00 	mov    QWORD PTR [r14+0xf20],rcx
    385f:	48 8b 00             	mov    rax,QWORD PTR [rax]
    3862:	49 89 86 10 0f 00 00 	mov    QWORD PTR [r14+0xf10],rax
    3869:	48 c1 eb 38          	shr    rbx,0x38
    386d:	4c 89 ea             	mov    rdx,r13
    3870:	48 29 ca             	sub    rdx,rcx
    3873:	49 89 96 18 0f 00 00 	mov    QWORD PTR [r14+0xf18],rdx
    387a:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 3881 <kprobe_unwind_hotspot+0x3881>
			387d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3881:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    3884:	0f 85 8d 17 00 00    	jne    5017 <kprobe_unwind_hotspot+0x5017>
    388a:	83 fb 01             	cmp    ebx,0x1
    388d:	0f 85 9e 0a 00 00    	jne    4331 <kprobe_unwind_hotspot+0x4331>
    3893:	49 8b 86 10 0f 00 00 	mov    rax,QWORD PTR [r14+0xf10]
    389a:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    38a1:	00 
    38a2:	4d 8b ae 18 0f 00 00 	mov    r13,QWORD PTR [r14+0xf18]
    38a9:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 38b0 <kprobe_unwind_hotspot+0x38b0>
			38ac: R_X86_64_REX_GOTPCRELX	interpreter_offsets-0x4
    38b0:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    38b7:	00 
    38b8:	b8 01 00 00 00       	mov    eax,0x1
    38bd:	ff d0                	call   rax
    38bf:	bb 01 00 00 00       	mov    ebx,0x1
    38c4:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    38cb:	00 
    38cc:	48 85 c0             	test   rax,rax
    38cf:	0f 84 5c 0a 00 00    	je     4331 <kprobe_unwind_hotspot+0x4331>
    38d5:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    38dc:	00 
    38dd:	4c 39 28             	cmp    QWORD PTR [rax],r13
    38e0:	77 0e                	ja     38f0 <kprobe_unwind_hotspot+0x38f0>
    38e2:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    38e9:	00 
    38ea:	4c 39 68 08          	cmp    QWORD PTR [rax+0x8],r13
    38ee:	73 24                	jae    3914 <kprobe_unwind_hotspot+0x3914>
    38f0:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    38f7:	00 
    38f8:	4c 39 68 10          	cmp    QWORD PTR [rax+0x10],r13
    38fc:	0f 87 2f 0a 00 00    	ja     4331 <kprobe_unwind_hotspot+0x4331>
    3902:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    3909:	00 
    390a:	4c 39 68 18          	cmp    QWORD PTR [rax+0x18],r13
    390e:	0f 82 1d 0a 00 00    	jb     4331 <kprobe_unwind_hotspot+0x4331>
    3914:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 391b <kprobe_unwind_hotspot+0x391b>
			3917: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    391b:	83 38 00             	cmp    DWORD PTR [rax],0x0
    391e:	0f 85 94 1f 00 00    	jne    58b8 <kprobe_unwind_hotspot+0x58b8>
    3924:	41 8b 86 80 13 00 00 	mov    eax,DWORD PTR [r14+0x1380]
    392b:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
    3932:	00 
    3933:	8b 49 20             	mov    ecx,DWORD PTR [rcx+0x20]
    3936:	0f a3 c8             	bt     eax,ecx
    3939:	0f 83 4e 09 00 00    	jae    428d <kprobe_unwind_hotspot+0x428d>
    393f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3946 <kprobe_unwind_hotspot+0x3946>
			3942: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3946:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3949:	0f 84 e2 09 00 00    	je     4331 <kprobe_unwind_hotspot+0x4331>
    394f:	48 b8 6e 64 65 72 20 	movabs rax,0x6e6f64207265646e
    3956:	64 6f 6e 
    3959:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    395e:	48 b8 74 65 72 20 75 	movabs rax,0x69776e7520726574
    3965:	6e 77 69 
    3968:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    396d:	48 b8 69 6e 74 65 72 	movabs rax,0x6572707265746e69
    3974:	70 72 65 
    3977:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    397c:	c7 44 24 57 6e 65 0a 	mov    DWORD PTR [rsp+0x57],0xa656e
    3983:	00 
    3984:	31 c0                	xor    eax,eax
    3986:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    398b:	ba 1b 00 00 00       	mov    edx,0x1b
    3990:	be 06 00 00 00       	mov    esi,0x6
    3995:	e9 97 09 00 00       	jmp    4331 <kprobe_unwind_hotspot+0x4331>
    399a:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    39a1:	00 
    39a2:	48 8d 14 18          	lea    rdx,[rax+rbx*1]
    39a6:	48 83 c2 f8          	add    rdx,0xfffffffffffffff8
    39aa:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    39af:	b8 30 00 00 00       	mov    eax,0x30
    39b4:	b9 70 00 00 00       	mov    ecx,0x70
    39b9:	be 30 00 00 00       	mov    esi,0x30
    39be:	ff d1                	call   rcx
    39c0:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 39c7 <kprobe_unwind_hotspot+0x39c7>
			39c3: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    39c7:	83 38 00             	cmp    DWORD PTR [rax],0x0
    39ca:	0f 85 e3 13 00 00    	jne    4db3 <kprobe_unwind_hotspot+0x4db3>
    39d0:	41 8b 06             	mov    eax,DWORD PTR [r14]
    39d3:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    39da:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    39e0:	48 01 9c 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],rbx
    39e7:	00 
    39e8:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
    39ed:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    39f4:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 39fb <kprobe_unwind_hotspot+0x39fb>
			39f7: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    39fb:	48 89 e6             	mov    rsi,rsp
    39fe:	b8 01 00 00 00       	mov    eax,0x1
    3a03:	ff d0                	call   rax
    3a05:	48 85 c0             	test   rax,rax
    3a08:	0f 84 82 01 00 00    	je     3b90 <kprobe_unwind_hotspot+0x3b90>
    3a0e:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    3a12:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    3a19:	00 00 ff 
    3a1c:	48 21 c8             	and    rax,rcx
    3a1f:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    3a26:	00 00 02 
    3a29:	48 39 c8             	cmp    rax,rcx
    3a2c:	0f 85 5e 01 00 00    	jne    3b90 <kprobe_unwind_hotspot+0x3b90>
    3a32:	31 db                	xor    ebx,ebx
    3a34:	e9 76 05 00 00       	jmp    3faf <kprobe_unwind_hotspot+0x3faf>
    3a39:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    3a40:	64 0a 00 
    3a43:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    3a48:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    3a4f:	69 63 49 
    3a52:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    3a57:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    3a5e:	66 6f 72 
    3a61:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    3a66:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    3a6d:	69 63 73 
    3a70:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    3a75:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    3a7c:	6b 75 70 
    3a7f:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    3a84:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    3a8b:	64 20 74 
    3a8e:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    3a92:	8b 84 24 08 01 00 00 	mov    eax,DWORD PTR [rsp+0x108]
    3a99:	31 c9                	xor    ecx,ecx
    3a9b:	48 89 e2             	mov    rdx,rsp
    3a9e:	be 2e 00 00 00       	mov    esi,0x2e
    3aa3:	bf 06 00 00 00       	mov    edi,0x6
    3aa8:	e9 cc de ff ff       	jmp    1979 <kprobe_unwind_hotspot+0x1979>
    3aad:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    3ab4:	75 0a 00 
    3ab7:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    3abc:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    3ac3:	74 61 67 
    3ac6:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    3acb:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    3ad2:	6e 74 20 
    3ad5:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    3ada:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    3ae1:	20 20 20 
    3ae4:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    3ae9:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3aed:	31 c9                	xor    ecx,ecx
    3aef:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    3af4:	be 1d 00 00 00       	mov    esi,0x1d
    3af9:	bf 06 00 00 00       	mov    edi,0x6
    3afe:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3b02:	8d 48 01             	lea    ecx,[rax+0x1]
    3b05:	80 f9 02             	cmp    cl,0x2
    3b08:	0f 82 6f c7 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    3b0e:	e9 4a d1 ff ff       	jmp    c5d <kprobe_unwind_hotspot+0xc5d>
    3b13:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    3b17:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    3b1e:	00 
    3b1f:	48 39 c8             	cmp    rax,rcx
    3b22:	0f 82 4a f5 ff ff    	jb     3072 <kprobe_unwind_hotspot+0x3072>
    3b28:	48 3b 84 24 e0 00 00 	cmp    rax,QWORD PTR [rsp+0xe0]
    3b2f:	00 
    3b30:	0f 83 3c f5 ff ff    	jae    3072 <kprobe_unwind_hotspot+0x3072>
    3b36:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # 3b3d <kprobe_unwind_hotspot+0x3b3d>
			3b39: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3b3d:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
    3b40:	0f 85 c6 15 00 00    	jne    510c <kprobe_unwind_hotspot+0x510c>
    3b46:	89 c2                	mov    edx,eax
    3b48:	29 ca                	sub    edx,ecx
    3b4a:	48 89 94 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rdx
    3b51:	00 
    3b52:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    3b59:	00 
    3b5a:	e9 23 f5 ff ff       	jmp    3082 <kprobe_unwind_hotspot+0x3082>
    3b5f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3b66 <kprobe_unwind_hotspot+0x3b66>
			3b62: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3b66:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3b69:	0f 85 72 13 00 00    	jne    4ee1 <kprobe_unwind_hotspot+0x4ee1>
    3b6f:	b8 e9 03 00 00       	mov    eax,0x3e9
    3b74:	31 c9                	xor    ecx,ecx
    3b76:	ba 49 6e 74 65       	mov    edx,0x65746e49
    3b7b:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    3b82:	00 
    3b83:	85 c0                	test   eax,eax
    3b85:	0f 85 a8 c7 ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    3b8b:	e9 5a 04 00 00       	jmp    3fea <kprobe_unwind_hotspot+0x3fea>
    3b90:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3b97 <kprobe_unwind_hotspot+0x3b97>
			3b93: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3b97:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3b9a:	0f 85 b5 13 00 00    	jne    4f55 <kprobe_unwind_hotspot+0x4f55>
    3ba0:	41 8b 06             	mov    eax,DWORD PTR [r14]
    3ba3:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    3baa:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    3bb0:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    3bb5:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    3bbc:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 3bc3 <kprobe_unwind_hotspot+0x3bc3>
			3bbf: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    3bc3:	48 89 e6             	mov    rsi,rsp
    3bc6:	bb 01 00 00 00       	mov    ebx,0x1
    3bcb:	b8 01 00 00 00       	mov    eax,0x1
    3bd0:	ff d0                	call   rax
    3bd2:	48 85 c0             	test   rax,rax
    3bd5:	74 2e                	je     3c05 <kprobe_unwind_hotspot+0x3c05>
    3bd7:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    3bdb:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    3be2:	00 00 ff 
    3be5:	48 21 c8             	and    rax,rcx
    3be8:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    3bef:	00 00 02 
    3bf2:	48 39 c8             	cmp    rax,rcx
    3bf5:	75 0e                	jne    3c05 <kprobe_unwind_hotspot+0x3c05>
    3bf7:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x8
    3bfe:	00 08 
    3c00:	e9 aa 03 00 00       	jmp    3faf <kprobe_unwind_hotspot+0x3faf>
    3c05:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3c0c <kprobe_unwind_hotspot+0x3c0c>
			3c08: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3c0c:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3c0f:	0f 85 a1 13 00 00    	jne    4fb6 <kprobe_unwind_hotspot+0x4fb6>
    3c15:	41 8b 06             	mov    eax,DWORD PTR [r14]
    3c18:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    3c1f:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    3c25:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    3c2a:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    3c31:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 3c38 <kprobe_unwind_hotspot+0x3c38>
			3c34: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    3c38:	48 89 e6             	mov    rsi,rsp
    3c3b:	b8 01 00 00 00       	mov    eax,0x1
    3c40:	ff d0                	call   rax
    3c42:	48 85 c0             	test   rax,rax
    3c45:	0f 84 28 01 00 00    	je     3d73 <kprobe_unwind_hotspot+0x3d73>
    3c4b:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    3c4f:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    3c56:	00 00 ff 
    3c59:	48 21 c8             	and    rax,rcx
    3c5c:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    3c63:	00 00 02 
    3c66:	48 39 c8             	cmp    rax,rcx
    3c69:	0f 85 04 01 00 00    	jne    3d73 <kprobe_unwind_hotspot+0x3d73>
    3c6f:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x10
    3c76:	00 10 
    3c78:	bb 02 00 00 00       	mov    ebx,0x2
    3c7d:	e9 2d 03 00 00       	jmp    3faf <kprobe_unwind_hotspot+0x3faf>
    3c82:	48 b9 6c 6f 62 20 25 	movabs rcx,0xa786c2520626f6c
    3c89:	6c 78 0a 
    3c8c:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    3c91:	48 b9 74 6f 20 63 6f 	movabs rcx,0x6265646f63206f74
    3c98:	64 65 62 
    3c9b:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    3ca0:	48 b9 20 6d 61 70 70 	movabs rcx,0x2064657070616d20
    3ca7:	65 64 20 
    3caa:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    3caf:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    3cb6:	20 2d 3e 
    3cb9:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    3cbe:	c6 44 24 60 00       	mov    BYTE PTR [rsp+0x60],0x0
    3cc3:	31 c9                	xor    ecx,ecx
    3cc5:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    3cca:	be 21 00 00 00       	mov    esi,0x21
    3ccf:	bf 06 00 00 00       	mov    edi,0x6
    3cd4:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    3cdb:	00 
    3cdc:	48 85 c0             	test   rax,rax
    3cdf:	0f 85 92 f0 ff ff    	jne    2d77 <kprobe_unwind_hotspot+0x2d77>
    3ce5:	e9 3a c5 ff ff       	jmp    224 <kprobe_unwind_hotspot+0x224>
    3cea:	41 83 be c0 02 00 00 	cmp    DWORD PTR [r14+0x2c0],0x0
    3cf1:	00 
    3cf2:	0f 84 15 03 00 00    	je     400d <kprobe_unwind_hotspot+0x400d>
    3cf8:	41 80 7f 1f 00       	cmp    BYTE PTR [r15+0x1f],0x0
    3cfd:	0f 84 45 03 00 00    	je     4048 <kprobe_unwind_hotspot+0x4048>
    3d03:	4c 8b 6c 24 50       	mov    r13,QWORD PTR [rsp+0x50]
    3d08:	e9 40 03 00 00       	jmp    404d <kprobe_unwind_hotspot+0x404d>
    3d0d:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    3d14:	75 0a 00 
    3d17:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    3d1c:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    3d23:	74 61 67 
    3d26:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    3d2b:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    3d32:	6e 74 20 
    3d35:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    3d3a:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    3d41:	20 20 20 
    3d44:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    3d49:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3d4d:	31 c9                	xor    ecx,ecx
    3d4f:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    3d54:	be 1d 00 00 00       	mov    esi,0x1d
    3d59:	bf 06 00 00 00       	mov    edi,0x6
    3d5e:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3d62:	8d 48 01             	lea    ecx,[rax+0x1]
    3d65:	80 f9 02             	cmp    cl,0x2
    3d68:	0f 82 c7 ef ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    3d6e:	e9 ae f5 ff ff       	jmp    3321 <kprobe_unwind_hotspot+0x3321>
    3d73:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3d7a <kprobe_unwind_hotspot+0x3d7a>
			3d76: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3d7a:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3d7d:	0f 85 2c 14 00 00    	jne    51af <kprobe_unwind_hotspot+0x51af>
    3d83:	41 8b 06             	mov    eax,DWORD PTR [r14]
    3d86:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    3d8d:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    3d93:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    3d98:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    3d9f:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 3da6 <kprobe_unwind_hotspot+0x3da6>
			3da2: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    3da6:	48 89 e6             	mov    rsi,rsp
    3da9:	b8 01 00 00 00       	mov    eax,0x1
    3dae:	ff d0                	call   rax
    3db0:	48 85 c0             	test   rax,rax
    3db3:	74 33                	je     3de8 <kprobe_unwind_hotspot+0x3de8>
    3db5:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    3db9:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    3dc0:	00 00 ff 
    3dc3:	48 21 c8             	and    rax,rcx
    3dc6:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    3dcd:	00 00 02 
    3dd0:	48 39 c8             	cmp    rax,rcx
    3dd3:	75 13                	jne    3de8 <kprobe_unwind_hotspot+0x3de8>
    3dd5:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x18
    3ddc:	00 18 
    3dde:	bb 03 00 00 00       	mov    ebx,0x3
    3de3:	e9 c7 01 00 00       	jmp    3faf <kprobe_unwind_hotspot+0x3faf>
    3de8:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3def <kprobe_unwind_hotspot+0x3def>
			3deb: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3def:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3df2:	0f 85 18 14 00 00    	jne    5210 <kprobe_unwind_hotspot+0x5210>
    3df8:	41 8b 06             	mov    eax,DWORD PTR [r14]
    3dfb:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    3e02:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    3e08:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    3e0d:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    3e14:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 3e1b <kprobe_unwind_hotspot+0x3e1b>
			3e17: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    3e1b:	48 89 e6             	mov    rsi,rsp
    3e1e:	b8 01 00 00 00       	mov    eax,0x1
    3e23:	ff d0                	call   rax
    3e25:	48 85 c0             	test   rax,rax
    3e28:	0f 84 10 01 00 00    	je     3f3e <kprobe_unwind_hotspot+0x3f3e>
    3e2e:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    3e32:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    3e39:	00 00 ff 
    3e3c:	48 21 c8             	and    rax,rcx
    3e3f:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    3e46:	00 00 02 
    3e49:	48 39 c8             	cmp    rax,rcx
    3e4c:	0f 85 ec 00 00 00    	jne    3f3e <kprobe_unwind_hotspot+0x3f3e>
    3e52:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x20
    3e59:	00 20 
    3e5b:	bb 04 00 00 00       	mov    ebx,0x4
    3e60:	e9 4a 01 00 00       	jmp    3faf <kprobe_unwind_hotspot+0x3faf>
    3e65:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    3e6c:	64 0a 00 
    3e6f:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    3e74:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    3e7b:	69 63 49 
    3e7e:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    3e83:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    3e8a:	66 6f 72 
    3e8d:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    3e92:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    3e99:	69 63 73 
    3e9c:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    3ea1:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    3ea8:	6b 75 70 
    3eab:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    3eb0:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    3eb7:	64 20 74 
    3eba:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    3ebf:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    3ec2:	31 c9                	xor    ecx,ecx
    3ec4:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    3ec9:	be 2e 00 00 00       	mov    esi,0x2e
    3ece:	bf 06 00 00 00       	mov    edi,0x6
    3ed3:	e9 c7 ec ff ff       	jmp    2b9f <kprobe_unwind_hotspot+0x2b9f>
    3ed8:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    3edf:	75 0a 00 
    3ee2:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    3ee7:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    3eee:	74 61 67 
    3ef1:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    3ef6:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    3efd:	6e 74 20 
    3f00:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    3f05:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    3f0c:	20 20 20 
    3f0f:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    3f14:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3f18:	31 c9                	xor    ecx,ecx
    3f1a:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    3f1f:	be 1d 00 00 00       	mov    esi,0x1d
    3f24:	bf 06 00 00 00       	mov    edi,0x6
    3f29:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    3f2d:	8d 48 01             	lea    ecx,[rax+0x1]
    3f30:	80 f9 02             	cmp    cl,0x2
    3f33:	0f 82 44 c3 ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    3f39:	e9 66 cd ff ff       	jmp    ca4 <kprobe_unwind_hotspot+0xca4>
    3f3e:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 3f45 <kprobe_unwind_hotspot+0x3f45>
			3f41: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3f45:	83 38 00             	cmp    DWORD PTR [rax],0x0
    3f48:	0f 85 db 14 00 00    	jne    5429 <kprobe_unwind_hotspot+0x5429>
    3f4e:	41 8b 06             	mov    eax,DWORD PTR [r14]
    3f51:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    3f58:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    3f5e:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    3f63:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    3f6a:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 3f71 <kprobe_unwind_hotspot+0x3f71>
			3f6d: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    3f71:	48 89 e6             	mov    rsi,rsp
    3f74:	b8 01 00 00 00       	mov    eax,0x1
    3f79:	ff d0                	call   rax
    3f7b:	48 85 c0             	test   rax,rax
    3f7e:	0f 84 92 00 00 00    	je     4016 <kprobe_unwind_hotspot+0x4016>
    3f84:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    3f8b:	00 00 ff 
    3f8e:	48 23 48 08          	and    rcx,QWORD PTR [rax+0x8]
    3f92:	48 b8 00 00 00 00 00 	movabs rax,0x200000000000000
    3f99:	00 00 02 
    3f9c:	48 39 c1             	cmp    rcx,rax
    3f9f:	75 75                	jne    4016 <kprobe_unwind_hotspot+0x4016>
    3fa1:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x28
    3fa8:	00 28 
    3faa:	bb 05 00 00 00       	mov    ebx,0x5
    3faf:	31 c0                	xor    eax,eax
    3fb1:	b9 05 00 00 00       	mov    ecx,0x5
    3fb6:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # 3fbd <kprobe_unwind_hotspot+0x3fbd>
			3fb9: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    3fbd:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
    3fc0:	0f 85 ae 0e 00 00    	jne    4e74 <kprobe_unwind_hotspot+0x4e74>
    3fc6:	4c 8b ac 24 b0 00 00 	mov    r13,QWORD PTR [rsp+0xb0]
    3fcd:	00 
    3fce:	b2 03                	mov    dl,0x3
    3fd0:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    3fd7:	4c 89 ea             	mov    rdx,r13
    3fda:	4c 89 ac 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],r13
    3fe1:	00 
    3fe2:	85 c0                	test   eax,eax
    3fe4:	0f 85 49 c3 ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    3fea:	89 c8                	mov    eax,ecx
    3fec:	48 8d 0d 00 00 00 00 	lea    rcx,[rip+0x0]        # 3ff3 <kprobe_unwind_hotspot+0x3ff3>
			3fef: R_X86_64_PC32	.rodata+0x88
    3ff3:	48 63 14 81          	movsxd rdx,DWORD PTR [rcx+rax*4]
    3ff7:	48 01 ca             	add    rdx,rcx
    3ffa:	b8 01 00 00 00       	mov    eax,0x1
    3fff:	ff e2                	jmp    rdx
    4001:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
    4008:	e9 54 f6 ff ff       	jmp    3661 <kprobe_unwind_hotspot+0x3661>
    400d:	4d 8b ae 00 0f 00 00 	mov    r13,QWORD PTR [r14+0xf00]
    4014:	eb 37                	jmp    404d <kprobe_unwind_hotspot+0x404d>
    4016:	c7 84 24 08 01 00 00 	mov    DWORD PTR [rsp+0x108],0x2e
    401d:	2e 00 00 00 
    4021:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 4028 <kprobe_unwind_hotspot+0x4028>
			4024: R_X86_64_REX_GOTPCRELX	metrics-0x4
    4028:	48 8d b4 24 08 01 00 	lea    rsi,[rsp+0x108]
    402f:	00 
    4030:	b8 01 00 00 00       	mov    eax,0x1
    4035:	ff d0                	call   rax
    4037:	48 85 c0             	test   rax,rax
    403a:	0f 84 cb 01 00 00    	je     420b <kprobe_unwind_hotspot+0x420b>
    4040:	48 ff 00             	inc    QWORD PTR [rax]
    4043:	e9 d3 01 00 00       	jmp    421b <kprobe_unwind_hotspot+0x421b>
    4048:	4c 8b 6c 24 58       	mov    r13,QWORD PTR [rsp+0x58]
    404d:	48 8b 5c 24 78       	mov    rbx,QWORD PTR [rsp+0x78]
    4052:	48 8b 84 24 88 00 00 	mov    rax,QWORD PTR [rsp+0x88]
    4059:	00 
    405a:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    4061:	00 
    4062:	48 8b 84 24 90 00 00 	mov    rax,QWORD PTR [rsp+0x90]
    4069:	00 
    406a:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    4071:	00 
    4072:	48 8b 84 24 98 00 00 	mov    rax,QWORD PTR [rsp+0x98]
    4079:	00 
    407a:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    4081:	00 
    4082:	41 0f b6 47 1c       	movzx  eax,BYTE PTR [r15+0x1c]
    4087:	48 01 d8             	add    rax,rbx
    408a:	48 8d bc 24 08 01 00 	lea    rdi,[rsp+0x108]
    4091:	00 
    4092:	b9 08 00 00 00       	mov    ecx,0x8
    4097:	41 b8 70 00 00 00    	mov    r8d,0x70
    409d:	41 0f b6 57 1c       	movzx  edx,BYTE PTR [r15+0x1c]
    40a2:	48 01 da             	add    rdx,rbx
    40a5:	be 08 00 00 00       	mov    esi,0x8
    40aa:	41 ff d0             	call   r8
    40ad:	48 85 c0             	test   rax,rax
    40b0:	74 73                	je     4125 <kprobe_unwind_hotspot+0x4125>
    40b2:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 40b9 <kprobe_unwind_hotspot+0x40b9>
			40b5: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    40b9:	83 38 00             	cmp    DWORD PTR [rax],0x0
    40bc:	0f 84 3c f5 ff ff    	je     35fe <kprobe_unwind_hotspot+0x35fe>
    40c2:	48 b8 63 6d 65 74 68 	movabs rax,0xa646f6874656d63
    40c9:	6f 64 0a 
    40cc:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    40d1:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
    40d8:	65 72 20 
    40db:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    40e0:	48 b8 65 61 64 20 69 	movabs rax,0x65746e6920646165
    40e7:	6e 74 65 
    40ea:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    40ef:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    40f6:	6f 20 72 
    40f9:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    40fe:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    4105:	66 61 69 
    4108:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    410c:	c6 44 24 28 00       	mov    BYTE PTR [rsp+0x28],0x0
    4111:	31 c0                	xor    eax,eax
    4113:	48 89 e1             	mov    rcx,rsp
    4116:	ba 29 00 00 00       	mov    edx,0x29
    411b:	be 06 00 00 00       	mov    esi,0x6
    4120:	e9 d9 f4 ff ff       	jmp    35fe <kprobe_unwind_hotspot+0x35fe>
    4125:	48 8b 94 24 08 01 00 	mov    rdx,QWORD PTR [rsp+0x108]
    412c:	00 
    412d:	41 0f b6 4f 1d       	movzx  ecx,BYTE PTR [r15+0x1d]
    4132:	48 89 d0             	mov    rax,rdx
    4135:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    413c:	00 
    413d:	48 01 d1             	add    rcx,rdx
    4140:	31 c0                	xor    eax,eax
    4142:	49 39 cd             	cmp    r13,rcx
    4145:	ba 00 00 00 00       	mov    edx,0x0
    414a:	48 0f 43 d1          	cmovae rdx,rcx
    414e:	49 29 d5             	sub    r13,rdx
    4151:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 4158 <kprobe_unwind_hotspot+0x4158>
			4154: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    4158:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    415b:	0f 85 29 13 00 00    	jne    548a <kprobe_unwind_hotspot+0x548a>
    4161:	49 81 fd ff ff 00 00 	cmp    r13,0xffff
    4168:	b9 ff ff 00 00       	mov    ecx,0xffff
    416d:	49 0f 42 cd          	cmovb  rcx,r13
    4171:	48 89 8c 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rcx
    4178:	00 
    4179:	48 c1 ac 24 c0 00 00 	shr    QWORD PTR [rsp+0xc0],0x3
    4180:	00 03 
    4182:	b9 06 00 00 00       	mov    ecx,0x6
    4187:	b2 02                	mov    dl,0x2
    4189:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    4190:	48 89 9c 24 18 01 00 	mov    QWORD PTR [rsp+0x118],rbx
    4197:	00 
    4198:	85 c0                	test   eax,eax
    419a:	0f 85 93 c1 ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    41a0:	e9 45 fe ff ff       	jmp    3fea <kprobe_unwind_hotspot+0x3fea>
    41a5:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    41ac:	75 0a 00 
    41af:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    41b4:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    41bb:	74 61 67 
    41be:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    41c3:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    41ca:	6e 74 20 
    41cd:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    41d2:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    41d9:	20 20 20 
    41dc:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    41e1:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    41e5:	31 c9                	xor    ecx,ecx
    41e7:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    41ec:	be 1d 00 00 00       	mov    esi,0x1d
    41f1:	bf 06 00 00 00       	mov    edi,0x6
    41f6:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    41fa:	8d 48 01             	lea    ecx,[rax+0x1]
    41fd:	80 f9 02             	cmp    cl,0x2
    4200:	0f 82 2f eb ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    4206:	e9 5d f1 ff ff       	jmp    3368 <kprobe_unwind_hotspot+0x3368>
    420b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 4212 <kprobe_unwind_hotspot+0x4212>
			420e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    4212:	83 38 00             	cmp    DWORD PTR [rax],0x0
    4215:	0f 85 fb 16 00 00    	jne    5916 <kprobe_unwind_hotspot+0x5916>
    421b:	b8 ea 03 00 00       	mov    eax,0x3ea
    4220:	31 c9                	xor    ecx,ecx
    4222:	e9 a7 fd ff ff       	jmp    3fce <kprobe_unwind_hotspot+0x3fce>
    4227:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    422e:	75 0a 00 
    4231:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    4236:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    423d:	74 61 67 
    4240:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4245:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    424c:	6e 74 20 
    424f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4254:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    425b:	20 20 20 
    425e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4263:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    4267:	31 c9                	xor    ecx,ecx
    4269:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    426e:	be 1d 00 00 00       	mov    esi,0x1d
    4273:	bf 06 00 00 00       	mov    edi,0x6
    4278:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    427c:	8d 48 01             	lea    ecx,[rax+0x1]
    427f:	80 f9 02             	cmp    cl,0x2
    4282:	0f 82 f5 bf ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    4288:	e9 5e ca ff ff       	jmp    ceb <kprobe_unwind_hotspot+0xceb>
    428d:	c7 04 24 00 00 00 00 	mov    DWORD PTR [rsp],0x0
    4294:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 429b <kprobe_unwind_hotspot+0x429b>
			4297: R_X86_64_REX_GOTPCRELX	metrics-0x4
    429b:	48 89 e6             	mov    rsi,rsp
    429e:	b8 01 00 00 00       	mov    eax,0x1
    42a3:	ff d0                	call   rax
    42a5:	48 85 c0             	test   rax,rax
    42a8:	74 6b                	je     4315 <kprobe_unwind_hotspot+0x4315>
    42aa:	48 ff 00             	inc    QWORD PTR [rax]
    42ad:	eb 76                	jmp    4325 <kprobe_unwind_hotspot+0x4325>
    42af:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    42b6:	75 0a 00 
    42b9:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    42be:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    42c5:	74 61 67 
    42c8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    42cd:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    42d4:	6e 74 20 
    42d7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    42dc:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    42e3:	20 20 20 
    42e6:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    42eb:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    42ef:	31 c9                	xor    ecx,ecx
    42f1:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    42f6:	be 1d 00 00 00       	mov    esi,0x1d
    42fb:	bf 06 00 00 00       	mov    edi,0x6
    4300:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    4304:	8d 48 01             	lea    ecx,[rax+0x1]
    4307:	80 f9 02             	cmp    cl,0x2
    430a:	0f 82 25 ea ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    4310:	e9 9a f0 ff ff       	jmp    33af <kprobe_unwind_hotspot+0x33af>
    4315:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 431c <kprobe_unwind_hotspot+0x431c>
			4318: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    431c:	83 38 00             	cmp    DWORD PTR [rax],0x0
    431f:	0f 85 68 1e 00 00    	jne    618d <kprobe_unwind_hotspot+0x618d>
    4325:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    432c:	00 
    432d:	0f b7 58 20          	movzx  ebx,WORD PTR [rax+0x20]
    4331:	83 fb 02             	cmp    ebx,0x2
    4334:	0f 85 fd bf ff ff    	jne    337 <kprobe_unwind_hotspot+0x337>
    433a:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x29
    4341:	29 00 00 00 
    4345:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 434c <kprobe_unwind_hotspot+0x434c>
			4348: R_X86_64_REX_GOTPCRELX	metrics-0x4
    434c:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    4353:	00 
    4354:	b8 01 00 00 00       	mov    eax,0x1
    4359:	ff d0                	call   rax
    435b:	48 85 c0             	test   rax,rax
    435e:	0f 84 ba 00 00 00    	je     441e <kprobe_unwind_hotspot+0x441e>
    4364:	48 ff 00             	inc    QWORD PTR [rax]
    4367:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 436e <kprobe_unwind_hotspot+0x436e>
			436a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    436e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    4371:	49 8b 86 d0 0e 00 00 	mov    rax,QWORD PTR [r14+0xed0]
    4378:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    437f:	00 
    4380:	49 8b 86 d8 0e 00 00 	mov    rax,QWORD PTR [r14+0xed8]
    4387:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    438e:	00 
    438f:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
    4396:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    439d:	00 
    439e:	0f 84 b7 00 00 00    	je     445b <kprobe_unwind_hotspot+0x445b>
    43a4:	48 b8 6f 66 66 73 65 	movabs rax,0x252074657366666f
    43ab:	74 20 25 
    43ae:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    43b3:	48 b8 72 74 20 25 6c 	movabs rax,0x202c786c25207472
    43ba:	78 2c 20 
    43bd:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    43c2:	48 b8 63 6f 64 65 20 	movabs rax,0x6174732065646f63
    43c9:	73 74 61 
    43cc:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    43d1:	48 b8 20 25 6c 78 20 	movabs rax,0x206e6920786c2520
    43d8:	69 6e 20 
    43db:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    43e0:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    43e7:	20 2d 3e 
    43ea:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    43ef:	c7 44 24 68 6c 78 0a 	mov    DWORD PTR [rsp+0x68],0xa786c
    43f6:	00 
    43f7:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
    43fe:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
    4405:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    440a:	be 2c 00 00 00       	mov    esi,0x2c
    440f:	bf 06 00 00 00       	mov    edi,0x6
    4414:	4c 8b 84 24 a8 00 00 	mov    r8,QWORD PTR [rsp+0xa8]
    441b:	00 
    441c:	eb 3d                	jmp    445b <kprobe_unwind_hotspot+0x445b>
    441e:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 4425 <kprobe_unwind_hotspot+0x4425>
			4421: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    4425:	83 38 00             	cmp    DWORD PTR [rax],0x0
    4428:	0f 85 bc 11 00 00    	jne    55ea <kprobe_unwind_hotspot+0x55ea>
    442e:	49 8b 86 d0 0e 00 00 	mov    rax,QWORD PTR [r14+0xed0]
    4435:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    443c:	00 
    443d:	49 8b 86 d8 0e 00 00 	mov    rax,QWORD PTR [r14+0xed8]
    4444:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    444b:	00 
    444c:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
    4453:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    445a:	00 
    445b:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
    4460:	c4 c2 fb f7 9e 18 0f 	shrx   rbx,QWORD PTR [r14+0xf18],rax
    4467:	00 00 
    4469:	49 8b 8e 10 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf10]
    4470:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    4477:	ff ff 00 
    447a:	48 21 c1             	and    rcx,rax
    447d:	49 89 cd             	mov    r13,rcx
    4480:	48 8d 14 0b          	lea    rdx,[rbx+rcx*1]
    4484:	48 89 e7             	mov    rdi,rsp
    4487:	b8 01 00 00 00       	mov    eax,0x1
    448c:	b9 70 00 00 00       	mov    ecx,0x70
    4491:	be 01 00 00 00       	mov    esi,0x1
    4496:	ff d1                	call   rcx
    4498:	48 85 c0             	test   rax,rax
    449b:	0f 85 77 bd ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    44a1:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 44a8 <kprobe_unwind_hotspot+0x44a8>
			44a4: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    44a8:	83 38 00             	cmp    DWORD PTR [rax],0x0
    44ab:	0f 85 b0 11 00 00    	jne    5661 <kprobe_unwind_hotspot+0x5661>
    44b1:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    44b5:	8d 48 01             	lea    ecx,[rax+0x1]
    44b8:	80 f9 02             	cmp    cl,0x2
    44bb:	0f 83 01 12 00 00    	jae    56c2 <kprobe_unwind_hotspot+0x56c2>
    44c1:	84 c0                	test   al,al
    44c3:	0f 85 4f bd ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    44c9:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
    44ce:	c4 e2 f9 f7 cb       	shlx   rcx,rbx,rax
    44d3:	49 03 8e 20 0f 00 00 	add    rcx,QWORD PTR [r14+0xf20]
    44da:	41 0f b6 47 1b       	movzx  eax,BYTE PTR [r15+0x1b]
    44df:	48 01 c8             	add    rax,rcx
    44e2:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 44e9 <kprobe_unwind_hotspot+0x44e9>
			44e5: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    44e9:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    44ec:	0f 85 b8 1a 00 00    	jne    5faa <kprobe_unwind_hotspot+0x5faa>
    44f2:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    44f9:	00 
    44fa:	48 85 c0             	test   rax,rax
    44fd:	0f 84 21 bd ff ff    	je     224 <kprobe_unwind_hotspot+0x224>
    4503:	b9 00 02 00 00       	mov    ecx,0x200
    4508:	41 b8 70 00 00 00    	mov    r8d,0x70
    450e:	48 8b 94 24 d0 00 00 	mov    rdx,QWORD PTR [rsp+0xd0]
    4515:	00 
    4516:	4c 89 e7             	mov    rdi,r12
    4519:	be 00 02 00 00       	mov    esi,0x200
    451e:	41 ff d0             	call   r8
    4521:	48 85 c0             	test   rax,rax
    4524:	0f 85 c2 bd ff ff    	jne    2ec <kprobe_unwind_hotspot+0x2ec>
    452a:	41 0f b7 4f 10       	movzx  ecx,WORD PTR [r15+0x10]
    452f:	b8 01 00 00 00       	mov    eax,0x1
    4534:	48 81 f9 f8 01 00 00 	cmp    rcx,0x1f8
    453b:	0f 87 f2 bd ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    4541:	41 0f b7 57 12       	movzx  edx,WORD PTR [r15+0x12]
    4546:	48 81 fa fc 01 00 00 	cmp    rdx,0x1fc
    454d:	0f 87 e0 bd ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    4553:	41 0f b7 77 14       	movzx  esi,WORD PTR [r15+0x14]
    4558:	48 81 fe f8 01 00 00 	cmp    rsi,0x1f8
    455f:	0f 87 ce bd ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    4565:	41 0f b6 47 17       	movzx  eax,BYTE PTR [r15+0x17]
    456a:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
    456e:	48 89 84 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rax
    4575:	00 
    4576:	41 0f b6 47 18       	movzx  eax,BYTE PTR [r15+0x18]
    457b:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
    457f:	48 89 84 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rax
    4586:	00 
    4587:	41 0f b6 47 1a       	movzx  eax,BYTE PTR [r15+0x1a]
    458c:	41 8b 04 04          	mov    eax,DWORD PTR [r12+rax*1]
    4590:	c1 e0 03             	shl    eax,0x3
    4593:	89 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],eax
    459a:	41 0f b6 47 19       	movzx  eax,BYTE PTR [r15+0x19]
    459f:	41 0f b7 04 04       	movzx  eax,WORD PTR [r12+rax*1]
    45a4:	66 89 84 24 00 01 00 	mov    WORD PTR [rsp+0x100],ax
    45ab:	00 
    45ac:	41 8b 04 14          	mov    eax,DWORD PTR [r12+rdx*1]
    45b0:	89 84 24 fc 00 00 00 	mov    DWORD PTR [rsp+0xfc],eax
    45b7:	41 8b 04 34          	mov    eax,DWORD PTR [r12+rsi*1]
    45bb:	89 84 24 f4 00 00 00 	mov    DWORD PTR [rsp+0xf4],eax
    45c2:	49 8b 04 0c          	mov    rax,QWORD PTR [r12+rcx*1]
    45c6:	48 89 84 24 e8 00 00 	mov    QWORD PTR [rsp+0xe8],rax
    45cd:	00 
    45ce:	41 0f b6 47 16       	movzx  eax,BYTE PTR [r15+0x16]
    45d3:	49 8b 14 04          	mov    rdx,QWORD PTR [r12+rax*1]
    45d7:	b8 04 00 00 00       	mov    eax,0x4
    45dc:	b9 70 00 00 00       	mov    ecx,0x70
    45e1:	48 8d bc 24 f0 00 00 	lea    rdi,[rsp+0xf0]
    45e8:	00 
    45e9:	be 04 00 00 00       	mov    esi,0x4
    45ee:	ff d1                	call   rcx
    45f0:	48 85 c0             	test   rax,rax
    45f3:	0f 85 f3 bc ff ff    	jne    2ec <kprobe_unwind_hotspot+0x2ec>
    45f9:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
    45fe:	74 2c                	je     462c <kprobe_unwind_hotspot+0x462c>
    4600:	48 8b 84 24 d0 00 00 	mov    rax,QWORD PTR [rsp+0xd0]
    4607:	00 
    4608:	8b 8c 24 d8 00 00 00 	mov    ecx,DWORD PTR [rsp+0xd8]
    460f:	48 01 c1             	add    rcx,rax
    4612:	48 89 8c 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rcx
    4619:	00 
    461a:	8b 8c 24 e0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xe0]
    4621:	48 01 c1             	add    rcx,rax
    4624:	48 89 8c 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rcx
    462b:	00 
    462c:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 4633 <kprobe_unwind_hotspot+0x4633>
			462f: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    4633:	83 38 00             	cmp    DWORD PTR [rax],0x0
    4636:	0f 85 d4 20 00 00    	jne    6710 <kprobe_unwind_hotspot+0x6710>
    463c:	48 8b 84 24 d0 00 00 	mov    rax,QWORD PTR [rsp+0xd0]
    4643:	00 
    4644:	48 89 84 24 18 01 00 	mov    QWORD PTR [rsp+0x118],rax
    464b:	00 
    464c:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
    4653:	00 
    4654:	8b 94 24 f0 00 00 00 	mov    edx,DWORD PTR [rsp+0xf0]
    465b:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
    4662:	00 
    4663:	29 c1                	sub    ecx,eax
    4665:	48 89 8c 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rcx
    466c:	00 
    466d:	48 89 d1             	mov    rcx,rdx
    4670:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    4677:	00 
    4678:	81 fa 6d 61 74 69    	cmp    edx,0x6974616d
    467e:	0f 8f ed 0b 00 00    	jg     5271 <kprobe_unwind_hotspot+0x5271>
    4684:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x62617476
    468b:	76 74 61 62 
    468f:	0f 84 87 0e 00 00    	je     551c <kprobe_unwind_hotspot+0x551c>
    4695:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x65746e49
    469c:	49 6e 74 65 
    46a0:	0f 85 b1 0e 00 00    	jne    5557 <kprobe_unwind_hotspot+0x5557>
    46a6:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    46ad:	00 
    46ae:	48 39 84 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],rax
    46b5:	00 
    46b6:	0f 82 ce 12 00 00    	jb     598a <kprobe_unwind_hotspot+0x598a>
    46bc:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    46c3:	00 
    46c4:	48 05 00 10 00 00    	add    rax,0x1000
    46ca:	48 39 84 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],rax
    46d1:	00 
    46d2:	0f 83 b2 12 00 00    	jae    598a <kprobe_unwind_hotspot+0x598a>
    46d8:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
    46df:	00 
    46e0:	48 8d 50 b0          	lea    rdx,[rax-0x50]
    46e4:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    46e9:	b8 60 00 00 00       	mov    eax,0x60
    46ee:	b9 70 00 00 00       	mov    ecx,0x70
    46f3:	be 60 00 00 00       	mov    esi,0x60
    46f8:	ff d1                	call   rcx
    46fa:	48 85 c0             	test   rax,rax
    46fd:	0f 84 0f 19 00 00    	je     6012 <kprobe_unwind_hotspot+0x6012>
    4703:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 470a <kprobe_unwind_hotspot+0x470a>
			4706: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    470a:	83 38 00             	cmp    DWORD PTR [rax],0x0
    470d:	0f 84 87 12 00 00    	je     599a <kprobe_unwind_hotspot+0x599a>
    4713:	48 b8 20 66 72 61 6d 	movabs rax,0xa656d61726620
    471a:	65 0a 00 
    471d:	48 89 44 24 1f       	mov    QWORD PTR [rsp+0x1f],rax
    4722:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
    4729:	65 72 20 
    472c:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    4731:	48 b8 65 61 64 20 69 	movabs rax,0x65746e6920646165
    4738:	6e 74 65 
    473b:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    4740:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    4747:	6f 20 72 
    474a:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    474f:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    4756:	66 61 69 
    4759:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    475d:	31 c0                	xor    eax,eax
    475f:	48 89 e1             	mov    rcx,rsp
    4762:	ba 27 00 00 00       	mov    edx,0x27
    4767:	be 06 00 00 00       	mov    esi,0x6
    476c:	e9 29 12 00 00       	jmp    599a <kprobe_unwind_hotspot+0x599a>
    4771:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    4778:	75 0a 00 
    477b:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    4780:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    4787:	74 61 67 
    478a:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    478f:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    4796:	6e 74 20 
    4799:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    479e:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    47a5:	20 20 20 
    47a8:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    47ad:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    47b1:	31 c9                	xor    ecx,ecx
    47b3:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    47b8:	be 1d 00 00 00       	mov    esi,0x1d
    47bd:	bf 06 00 00 00       	mov    edi,0x6
    47c2:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    47c6:	8d 48 01             	lea    ecx,[rax+0x1]
    47c9:	80 f9 02             	cmp    cl,0x2
    47cc:	0f 82 ab ba ff ff    	jb     27d <kprobe_unwind_hotspot+0x27d>
    47d2:	e9 5b c5 ff ff       	jmp    d32 <kprobe_unwind_hotspot+0xd32>
    47d7:	48 b8 6c 78 2d 25 6c 	movabs rax,0xa786c252d786c
    47de:	78 0a 00 
    47e1:	48 89 44 24 4f       	mov    QWORD PTR [rsp+0x4f],rax
    47e6:	48 b8 20 63 6f 64 65 	movabs rax,0x6c252065646f6320
    47ed:	20 25 6c 
    47f0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    47f5:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    47fc:	20 2d 3e 
    47ff:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4804:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    480b:	00 
    480c:	48 8b 94 24 e0 00 00 	mov    rdx,QWORD PTR [rsp+0xe0]
    4813:	00 
    4814:	31 f6                	xor    esi,esi
    4816:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    481b:	41 b8 17 00 00 00    	mov    r8d,0x17
    4821:	41 b9 06 00 00 00    	mov    r9d,0x6
    4827:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 482e <kprobe_unwind_hotspot+0x482e>
			482a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    482e:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    4831:	0f 84 79 e6 ff ff    	je     2eb0 <kprobe_unwind_hotspot+0x2eb0>
    4837:	48 b9 5f 74 79 70 65 	movabs rcx,0x783020657079745f
    483e:	20 30 78 
    4841:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    4846:	48 b9 75 2c 20 66 72 	movabs rcx,0x656d617266202c75
    484d:	61 6d 65 
    4850:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    4855:	48 b9 65 5f 73 69 7a 	movabs rcx,0x2520657a69735f65
    485c:	65 20 25 
    485f:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    4864:	48 b9 25 75 2c 20 66 	movabs rcx,0x6d617266202c7525
    486b:	72 61 6d 
    486e:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    4873:	48 b9 6f 6d 70 6c 65 	movabs rcx,0x206574656c706d6f
    487a:	74 65 20 
    487d:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    4882:	48 b9 20 66 72 61 6d 	movabs rcx,0x635f656d61726620
    4889:	65 5f 63 
    488c:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    4891:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4896:	c7 44 24 78 25 78 0a 	mov    DWORD PTR [rsp+0x78],0xa7825
    489d:	00 
    489e:	0f b7 84 24 00 01 00 	movzx  eax,WORD PTR [rsp+0x100]
    48a5:	00 
    48a6:	8b 8c 24 f0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xf0]
    48ad:	8b 94 24 f8 00 00 00 	mov    edx,DWORD PTR [rsp+0xf8]
    48b4:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    48b9:	bf 3c 00 00 00       	mov    edi,0x3c
    48be:	41 b8 06 00 00 00    	mov    r8d,0x6
    48c4:	e9 e7 e5 ff ff       	jmp    2eb0 <kprobe_unwind_hotspot+0x2eb0>
    48c9:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    48d0:	75 0a 00 
    48d3:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    48d8:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    48df:	74 61 67 
    48e2:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    48e7:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    48ee:	6e 74 20 
    48f1:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    48f6:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    48fd:	20 20 20 
    4900:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4905:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    4909:	31 c9                	xor    ecx,ecx
    490b:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    4910:	be 1d 00 00 00       	mov    esi,0x1d
    4915:	bf 06 00 00 00       	mov    edi,0x6
    491a:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    491e:	8d 48 01             	lea    ecx,[rax+0x1]
    4921:	80 f9 02             	cmp    cl,0x2
    4924:	0f 82 0b e4 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    492a:	e9 c7 ea ff ff       	jmp    33f6 <kprobe_unwind_hotspot+0x33f6>
    492f:	48 b8 78 2c 20 66 70 	movabs rax,0x25203a7066202c78
    4936:	3a 20 25 
    4939:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    493e:	48 b8 2c 20 73 70 3a 	movabs rax,0x6c25203a7073202c
    4945:	20 25 6c 
    4948:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    494d:	48 b8 20 70 63 3a 20 	movabs rax,0x786c25203a637020
    4954:	25 6c 78 
    4957:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    495c:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    4963:	20 2d 3e 
    4966:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    496b:	c7 44 24 60 6c 78 0a 	mov    DWORD PTR [rsp+0x60],0xa786c
    4972:	00 
    4973:	48 8d 44 24 40       	lea    rax,[rsp+0x40]
    4978:	b9 24 00 00 00       	mov    ecx,0x24
    497d:	ba 06 00 00 00       	mov    edx,0x6
    4982:	48 8b b4 24 b8 00 00 	mov    rsi,QWORD PTR [rsp+0xb8]
    4989:	00 
    498a:	48 8b bc 24 b0 00 00 	mov    rdi,QWORD PTR [rsp+0xb0]
    4991:	00 
    4992:	4c 8b 84 24 a8 00 00 	mov    r8,QWORD PTR [rsp+0xa8]
    4999:	00 
    499a:	e9 bb ed ff ff       	jmp    375a <kprobe_unwind_hotspot+0x375a>
    499f:	48 b8 76 65 72 20 66 	movabs rax,0xa706620726576
    49a6:	70 0a 00 
    49a9:	48 89 44 24 4d       	mov    QWORD PTR [rsp+0x4d],rax
    49ae:	48 b8 20 72 65 63 6f 	movabs rax,0x7265766f63657220
    49b5:	76 65 72 
    49b8:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    49bd:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    49c4:	20 2d 3e 
    49c7:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    49cc:	31 c0                	xor    eax,eax
    49ce:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    49d3:	ba 15 00 00 00       	mov    edx,0x15
    49d8:	be 06 00 00 00       	mov    esi,0x6
    49dd:	e9 d0 ec ff ff       	jmp    36b2 <kprobe_unwind_hotspot+0x36b2>
    49e2:	48 b8 25 64 20 3d 3d 	movabs rax,0xa3d3d3d3d206425
    49e9:	3d 3d 0a 
    49ec:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    49f1:	48 b8 3a 20 66 72 61 	movabs rax,0x20656d617266203a
    49f8:	6d 65 20 
    49fb:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    4a00:	48 b8 75 6e 77 69 6e 	movabs rax,0x7265646e69776e75
    4a07:	64 65 72 
    4a0a:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    4a0f:	48 b8 74 20 66 72 61 	movabs rax,0x20656d6172662074
    4a16:	6d 65 20 
    4a19:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4a1e:	48 b8 6f 6c 76 65 20 	movabs rax,0x78656e2065766c6f
    4a25:	6e 65 78 
    4a28:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4a2d:	48 b8 3d 3d 3d 3d 20 	movabs rax,0x736552203d3d3d3d
    4a34:	52 65 73 
    4a37:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4a3c:	c6 44 24 70 00       	mov    BYTE PTR [rsp+0x70],0x0
    4a41:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    4a48:	31 c9                	xor    ecx,ecx
    4a4a:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    4a4f:	be 31 00 00 00       	mov    esi,0x31
    4a54:	bf 06 00 00 00       	mov    edi,0x6
    4a59:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    4a60:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    4a67:	ff ff 00 
    4a6a:	49 39 c5             	cmp    r13,rax
    4a6d:	0f 87 67 cc ff ff    	ja     16da <kprobe_unwind_hotspot+0x16da>
    4a73:	e9 7f ed ff ff       	jmp    37f7 <kprobe_unwind_hotspot+0x37f7>
    4a78:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    4a7f:	75 0a 00 
    4a82:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    4a87:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    4a8e:	74 61 67 
    4a91:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4a96:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    4a9d:	6e 74 20 
    4aa0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4aa5:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    4aac:	20 20 20 
    4aaf:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4ab4:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    4ab8:	31 c9                	xor    ecx,ecx
    4aba:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    4abf:	be 1d 00 00 00       	mov    esi,0x1d
    4ac4:	bf 06 00 00 00       	mov    edi,0x6
    4ac9:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    4acd:	8d 48 01             	lea    ecx,[rax+0x1]
    4ad0:	80 f9 01             	cmp    cl,0x1
    4ad3:	0f 87 3f b7 ff ff    	ja     218 <kprobe_unwind_hotspot+0x218>
    4ad9:	e9 9f b7 ff ff       	jmp    27d <kprobe_unwind_hotspot+0x27d>
    4ade:	48 b8 76 74 61 62 6c 	movabs rax,0xa656c62617476
    4ae5:	65 0a 00 
    4ae8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4aed:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    4af4:	6e 64 20 
    4af7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4afc:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    4b03:	20 2d 3e 
    4b06:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4b0b:	31 c0                	xor    eax,eax
    4b0d:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    4b12:	ba 18 00 00 00       	mov    edx,0x18
    4b17:	be 06 00 00 00       	mov    esi,0x6
    4b1c:	e9 39 e6 ff ff       	jmp    315a <kprobe_unwind_hotspot+0x315a>
    4b21:	48 b8 6c 62 61 63 6b 	movabs rax,0x6170206b6361626c
    4b28:	20 70 61 
    4b2b:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    4b30:	48 b8 73 74 75 62 20 	movabs rax,0x6c61662062757473
    4b37:	66 61 6c 
    4b3a:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4b3f:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    4b46:	6e 64 20 
    4b49:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4b4e:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    4b55:	20 2d 3e 
    4b58:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4b5d:	c7 44 24 60 74 68 0a 	mov    DWORD PTR [rsp+0x60],0xa6874
    4b64:	00 
    4b65:	31 c0                	xor    eax,eax
    4b67:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    4b6c:	ba 24 00 00 00       	mov    edx,0x24
    4b71:	be 06 00 00 00       	mov    esi,0x6
    4b76:	e9 04 e6 ff ff       	jmp    317f <kprobe_unwind_hotspot+0x317f>
    4b7b:	48 b8 66 61 69 6c 65 	movabs rax,0xa64656c696166
    4b82:	64 0a 00 
    4b85:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    4b8a:	48 b8 65 63 6f 76 65 	movabs rax,0x20797265766f6365
    4b91:	72 79 20 
    4b94:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    4b99:	48 b8 6d 65 2c 20 70 	movabs rax,0x72206370202c656d
    4ba0:	63 20 72 
    4ba3:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    4ba8:	48 b8 69 7a 65 64 20 	movabs rax,0x6172662064657a69
    4baf:	66 72 61 
    4bb2:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4bb7:	48 b8 20 64 65 6f 70 	movabs rax,0x6d6974706f656420
    4bbe:	74 69 6d 
    4bc1:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4bc6:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    4bcd:	20 2d 3e 
    4bd0:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4bd5:	31 c0                	xor    eax,eax
    4bd7:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    4bdc:	ba 30 00 00 00       	mov    edx,0x30
    4be1:	be 06 00 00 00       	mov    esi,0x6
    4be6:	e9 97 e4 ff ff       	jmp    3082 <kprobe_unwind_hotspot+0x3082>
    4beb:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    4bf2:	64 0a 00 
    4bf5:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    4bfa:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    4c01:	69 63 49 
    4c04:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    4c09:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    4c10:	66 6f 72 
    4c13:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    4c18:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    4c1f:	69 63 73 
    4c22:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4c27:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    4c2e:	6b 75 70 
    4c31:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4c36:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    4c3d:	64 20 74 
    4c40:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4c45:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    4c48:	31 c9                	xor    ecx,ecx
    4c4a:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    4c4f:	be 2e 00 00 00       	mov    esi,0x2e
    4c54:	bf 06 00 00 00       	mov    edi,0x6
    4c59:	e9 51 eb ff ff       	jmp    37af <kprobe_unwind_hotspot+0x37af>
    4c5e:	48 b9 65 20 25 6c 64 	movabs rcx,0xa29646c252065
    4c65:	29 0a 00 
    4c68:	48 89 4c 24 67       	mov    QWORD PTR [rsp+0x67],rcx
    4c6d:	48 b9 61 6d 65 20 73 	movabs rcx,0x657a697320656d61
    4c74:	69 7a 65 
    4c77:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    4c7c:	48 b9 6e 74 65 72 20 	movabs rcx,0x726628207265746e
    4c83:	28 66 72 
    4c86:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    4c8b:	48 b9 72 61 6d 65 20 	movabs rcx,0x696f7020656d6172
    4c92:	70 6f 69 
    4c95:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    4c9a:	48 b9 20 75 73 69 6e 	movabs rcx,0x6620676e69737520
    4ca1:	67 20 66 
    4ca4:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    4ca9:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    4cb0:	20 2d 3e 
    4cb3:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    4cb8:	31 c9                	xor    ecx,ecx
    4cba:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    4cbf:	be 2f 00 00 00       	mov    esi,0x2f
    4cc4:	bf 06 00 00 00       	mov    edi,0x6
    4cc9:	48 8b 8c 24 b8 00 00 	mov    rcx,QWORD PTR [rsp+0xb8]
    4cd0:	00 
    4cd1:	e9 73 e9 ff ff       	jmp    3649 <kprobe_unwind_hotspot+0x3649>
    4cd6:	48 b8 20 66 72 61 6d 	movabs rax,0xa656d61726620
    4cdd:	65 0a 00 
    4ce0:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    4ce5:	48 b8 70 72 65 74 65 	movabs rax,0x6620726574657270
    4cec:	72 20 66 
    4cef:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    4cf4:	48 b8 62 65 20 69 6e 	movabs rax,0x7265746e69206562
    4cfb:	74 65 72 
    4cfe:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    4d03:	48 b8 61 77 61 79 20 	movabs rax,0x206f742079617761
    4d0a:	74 6f 20 
    4d0d:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    4d12:	48 b8 74 6f 6f 20 66 	movabs rax,0x20726166206f6f74
    4d19:	61 72 20 
    4d1c:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    4d21:	48 b8 6a 76 6d 3a 20 	movabs rax,0x207066203a6d766a
    4d28:	66 70 20 
    4d2b:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    4d2f:	31 c0                	xor    eax,eax
    4d31:	48 89 e1             	mov    rcx,rsp
    4d34:	ba 2e 00 00 00       	mov    edx,0x2e
    4d39:	be 06 00 00 00       	mov    esi,0x6
    4d3e:	e9 bb e8 ff ff       	jmp    35fe <kprobe_unwind_hotspot+0x35fe>
    4d43:	48 b8 66 70 2b 70 63 	movabs rax,0xa2963702b7066
    4d4a:	29 0a 00 
    4d4d:	48 89 44 24 65       	mov    QWORD PTR [rsp+0x65],rax
    4d52:	48 b8 61 6d 65 20 28 	movabs rax,0x2b70662820656d61
    4d59:	66 70 2b 
    4d5c:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    4d61:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
    4d68:	20 66 72 
    4d6b:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    4d70:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
    4d77:	63 6f 6d 
    4d7a:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4d7f:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    4d86:	6e 64 69 
    4d89:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4d8e:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    4d95:	20 2d 3e 
    4d98:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4d9d:	31 c0                	xor    eax,eax
    4d9f:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    4da4:	ba 2d 00 00 00       	mov    edx,0x2d
    4da9:	be 06 00 00 00       	mov    esi,0x6
    4dae:	e9 8e e8 ff ff       	jmp    3641 <kprobe_unwind_hotspot+0x3641>
    4db3:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    4dba:	25 6c 78 
    4dbd:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    4dc2:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    4dc9:	69 64 61 
    4dcc:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    4dd1:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    4dd8:	20 70 63 
    4ddb:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    4de0:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    4de7:	20 20 20 
    4dea:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    4dee:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    4df5:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
    4dfa:	31 c9                	xor    ecx,ecx
    4dfc:	48 89 e2             	mov    rdx,rsp
    4dff:	be 22 00 00 00       	mov    esi,0x22
    4e04:	bf 06 00 00 00       	mov    edi,0x6
    4e09:	e9 c2 eb ff ff       	jmp    39d0 <kprobe_unwind_hotspot+0x39d0>
    4e0e:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    4e15:	75 0a 00 
    4e18:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    4e1d:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    4e24:	74 61 67 
    4e27:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    4e2c:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    4e33:	6e 74 20 
    4e36:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    4e3b:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    4e42:	20 20 20 
    4e45:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    4e4a:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    4e4e:	31 c9                	xor    ecx,ecx
    4e50:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    4e55:	be 1d 00 00 00       	mov    esi,0x1d
    4e5a:	bf 06 00 00 00       	mov    edi,0x6
    4e5f:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    4e63:	8d 48 01             	lea    ecx,[rax+0x1]
    4e66:	80 f9 02             	cmp    cl,0x2
    4e69:	0f 82 c6 de ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    4e6f:	e9 c9 e5 ff ff       	jmp    343d <kprobe_unwind_hotspot+0x343d>
    4e74:	48 b8 20 77 6f 72 64 	movabs rax,0xa7364726f7720
    4e7b:	73 0a 00 
    4e7e:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    4e83:	48 b8 65 20 2b 20 25 	movabs rax,0x77206425202b2065
    4e8a:	64 20 77 
    4e8d:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    4e92:	48 b8 65 74 65 20 66 	movabs rax,0x6d61726620657465
    4e99:	72 61 6d 
    4e9c:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    4ea1:	48 b8 6e 67 20 63 6f 	movabs rax,0x6c706d6f6320676e
    4ea8:	6d 70 6c 
    4eab:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    4eb0:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    4eb7:	6e 64 69 
    4eba:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    4ebf:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    4ec6:	20 2d 3e 
    4ec9:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    4ecd:	31 c0                	xor    eax,eax
    4ecf:	48 89 e2             	mov    rdx,rsp
    4ed2:	be 2e 00 00 00       	mov    esi,0x2e
    4ed7:	bf 06 00 00 00       	mov    edi,0x6
    4edc:	e9 e5 f0 ff ff       	jmp    3fc6 <kprobe_unwind_hotspot+0x3fc6>
    4ee1:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    4ee8:	64 0a 00 
    4eeb:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    4ef0:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    4ef7:	69 63 49 
    4efa:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    4eff:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    4f06:	66 6f 72 
    4f09:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    4f0e:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    4f15:	69 63 73 
    4f18:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    4f1d:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    4f24:	6b 75 70 
    4f27:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    4f2c:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    4f33:	64 20 74 
    4f36:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    4f3a:	8b 84 24 14 01 00 00 	mov    eax,DWORD PTR [rsp+0x114]
    4f41:	31 c9                	xor    ecx,ecx
    4f43:	48 89 e2             	mov    rdx,rsp
    4f46:	be 2e 00 00 00       	mov    esi,0x2e
    4f4b:	bf 06 00 00 00       	mov    edi,0x6
    4f50:	e9 1a ec ff ff       	jmp    3b6f <kprobe_unwind_hotspot+0x3b6f>
    4f55:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    4f5c:	25 6c 78 
    4f5f:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    4f64:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    4f6b:	69 64 61 
    4f6e:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    4f73:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    4f7a:	20 70 63 
    4f7d:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    4f82:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    4f89:	20 20 20 
    4f8c:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    4f90:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    4f97:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    4f9c:	31 c9                	xor    ecx,ecx
    4f9e:	48 89 e2             	mov    rdx,rsp
    4fa1:	be 22 00 00 00       	mov    esi,0x22
    4fa6:	bf 01 00 00 00       	mov    edi,0x1
    4fab:	41 b8 06 00 00 00    	mov    r8d,0x6
    4fb1:	e9 ea eb ff ff       	jmp    3ba0 <kprobe_unwind_hotspot+0x3ba0>
    4fb6:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    4fbd:	25 6c 78 
    4fc0:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    4fc5:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    4fcc:	69 64 61 
    4fcf:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    4fd4:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    4fdb:	20 70 63 
    4fde:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    4fe3:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    4fea:	20 20 20 
    4fed:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    4ff1:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    4ff8:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    4ffd:	31 c9                	xor    ecx,ecx
    4fff:	48 89 e2             	mov    rdx,rsp
    5002:	be 22 00 00 00       	mov    esi,0x22
    5007:	bf 02 00 00 00       	mov    edi,0x2
    500c:	41 b8 06 00 00 00    	mov    r8d,0x6
    5012:	e9 fe eb ff ff       	jmp    3c15 <kprobe_unwind_hotspot+0x3c15>
    5017:	48 b9 6e 64 65 72 20 	movabs rcx,0x296425207265646e
    501e:	25 64 29 
    5021:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    5026:	48 b9 6c 78 20 28 75 	movabs rcx,0x69776e752820786c
    502d:	6e 77 69 
    5030:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    5035:	48 b9 6c 78 20 69 73 	movabs rcx,0x6c2520736920786c
    503c:	20 25 6c 
    503f:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    5044:	48 b9 66 6f 72 20 50 	movabs rcx,0x2520435020726f66
    504b:	43 20 25 
    504e:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    5053:	48 b9 74 69 6f 6e 20 	movabs rcx,0x206469206e6f6974
    505a:	69 64 20 
    505d:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    5062:	48 b9 54 65 78 74 20 	movabs rcx,0x6365732074786554
    5069:	73 65 63 
    506c:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    5071:	66 c7 44 24 70 0a 00 	mov    WORD PTR [rsp+0x70],0xa
    5078:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    507d:	be 32 00 00 00       	mov    esi,0x32
    5082:	bf 06 00 00 00       	mov    edi,0x6
    5087:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 508e <kprobe_unwind_hotspot+0x508e>
			508a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    508e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5091:	0f 84 f3 e7 ff ff    	je     388a <kprobe_unwind_hotspot+0x388a>
    5097:	48 b8 73 20 25 6c 6c 	movabs rax,0xa786c6c252073
    509e:	78 0a 00 
    50a1:	48 89 44 24 67       	mov    QWORD PTR [rsp+0x67],rax
    50a6:	48 b8 66 66 73 65 74 	movabs rax,0x7369207465736666
    50ad:	20 69 73 
    50b0:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    50b5:	48 b8 78 2c 20 61 6e 	movabs rax,0x6f20646e61202c78
    50bc:	64 20 6f 
    50bf:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    50c4:	48 b8 73 20 69 73 20 	movabs rax,0x6c6c252073692073
    50cb:	25 6c 6c 
    50ce:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    50d3:	48 b8 74 69 6f 6e 20 	movabs rax,0x616962206e6f6974
    50da:	62 69 61 
    50dd:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    50e2:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    50e7:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
    50ee:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
    50f5:	31 d2                	xor    edx,edx
    50f7:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    50fc:	bf 2f 00 00 00       	mov    edi,0x2f
    5101:	41 b8 06 00 00 00    	mov    r8d,0x6
    5107:	e9 7e e7 ff ff       	jmp    388a <kprobe_unwind_hotspot+0x388a>
    510c:	48 b9 73 70 2b 25 64 	movabs rcx,0xa2964252b7073
    5113:	29 0a 00 
    5116:	48 89 4c 24 78       	mov    QWORD PTR [rsp+0x78],rcx
    511b:	48 b9 78 20 28 66 72 	movabs rcx,0x206d6f7266282078
    5122:	6f 6d 20 
    5125:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    512a:	48 b9 20 61 73 20 30 	movabs rcx,0x6c25783020736120
    5131:	78 25 6c 
    5134:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    5139:	48 b9 65 63 6f 76 65 	movabs rcx,0x64657265766f6365
    5140:	72 65 64 
    5143:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    5148:	48 b9 6d 65 2c 20 70 	movabs rcx,0x72206370202c656d
    514f:	63 20 72 
    5152:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    5157:	48 b9 69 7a 65 64 20 	movabs rcx,0x6172662064657a69
    515e:	66 72 61 
    5161:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    5166:	48 b9 20 64 65 6f 70 	movabs rcx,0x6d6974706f656420
    516d:	74 69 6d 
    5170:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    5175:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    517c:	20 2d 3e 
    517f:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    5184:	48 63 8c 24 f4 00 00 	movsxd rcx,DWORD PTR [rsp+0xf4]
    518b:	00 
    518c:	31 d2                	xor    edx,edx
    518e:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    5193:	bf 40 00 00 00       	mov    edi,0x40
    5198:	41 b8 06 00 00 00    	mov    r8d,0x6
    519e:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    51a2:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    51a9:	00 
    51aa:	e9 97 e9 ff ff       	jmp    3b46 <kprobe_unwind_hotspot+0x3b46>
    51af:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    51b6:	25 6c 78 
    51b9:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    51be:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    51c5:	69 64 61 
    51c8:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    51cd:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    51d4:	20 70 63 
    51d7:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    51dc:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    51e3:	20 20 20 
    51e6:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    51ea:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    51f1:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    51f6:	31 c9                	xor    ecx,ecx
    51f8:	48 89 e2             	mov    rdx,rsp
    51fb:	be 22 00 00 00       	mov    esi,0x22
    5200:	bf 03 00 00 00       	mov    edi,0x3
    5205:	41 b8 06 00 00 00    	mov    r8d,0x6
    520b:	e9 73 eb ff ff       	jmp    3d83 <kprobe_unwind_hotspot+0x3d83>
    5210:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    5217:	25 6c 78 
    521a:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    521f:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    5226:	69 64 61 
    5229:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    522e:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    5235:	20 70 63 
    5238:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    523d:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    5244:	20 20 20 
    5247:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    524b:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    5252:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    5257:	31 c9                	xor    ecx,ecx
    5259:	48 89 e2             	mov    rdx,rsp
    525c:	be 22 00 00 00       	mov    esi,0x22
    5261:	bf 04 00 00 00       	mov    edi,0x4
    5266:	41 b8 06 00 00 00    	mov    r8d,0x6
    526c:	e9 87 eb ff ff       	jmp    3df8 <kprobe_unwind_hotspot+0x3df8>
    5271:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x6974616e
    5278:	6e 61 74 69 
    527c:	74 11                	je     528f <kprobe_unwind_hotspot+0x528f>
    527e:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x74656d6e
    5285:	6e 6d 65 74 
    5289:	0f 85 c8 02 00 00    	jne    5557 <kprobe_unwind_hotspot+0x5557>
    528f:	8b 8c 24 fc 00 00 00 	mov    ecx,DWORD PTR [rsp+0xfc]
    5296:	48 89 8c 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rcx
    529d:	00 
    529e:	48 8b 8c 24 e8 00 00 	mov    rcx,QWORD PTR [rsp+0xe8]
    52a5:	00 
    52a6:	89 ca                	mov    edx,ecx
    52a8:	48 03 94 24 18 01 00 	add    rdx,QWORD PTR [rsp+0x118]
    52af:	00 
    52b0:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
    52b5:	48 0f 44 d1          	cmove  rdx,rcx
    52b9:	48 39 94 24 a8 00 00 	cmp    QWORD PTR [rsp+0xa8],rdx
    52c0:	00 
    52c1:	75 53                	jne    5316 <kprobe_unwind_hotspot+0x5316>
    52c3:	8b 84 24 f4 00 00 00 	mov    eax,DWORD PTR [rsp+0xf4]
    52ca:	48 8b b4 24 b0 00 00 	mov    rsi,QWORD PTR [rsp+0xb0]
    52d1:	00 
    52d2:	48 01 f0             	add    rax,rsi
    52d5:	48 89 e7             	mov    rdi,rsp
    52d8:	b9 08 00 00 00       	mov    ecx,0x8
    52dd:	41 b8 70 00 00 00    	mov    r8d,0x70
    52e3:	8b 94 24 f4 00 00 00 	mov    edx,DWORD PTR [rsp+0xf4]
    52ea:	48 01 f2             	add    rdx,rsi
    52ed:	be 08 00 00 00       	mov    esi,0x8
    52f2:	41 ff d0             	call   r8
    52f5:	48 85 c0             	test   rax,rax
    52f8:	0f 84 3d 0b 00 00    	je     5e3b <kprobe_unwind_hotspot+0x5e3b>
    52fe:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5305 <kprobe_unwind_hotspot+0x5305>
			5301: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5305:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5308:	0f 85 f4 14 00 00    	jne    6802 <kprobe_unwind_hotspot+0x6802>
    530e:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
    5315:	00 
    5316:	0f b7 8c 24 00 01 00 	movzx  ecx,WORD PTR [rsp+0x100]
    531d:	00 
    531e:	48 01 c1             	add    rcx,rax
    5321:	48 39 8c 24 a8 00 00 	cmp    QWORD PTR [rsp+0xa8],rcx
    5328:	00 
    5329:	0f 83 5f 02 00 00    	jae    558e <kprobe_unwind_hotspot+0x558e>
    532f:	48 83 c1 fc          	add    rcx,0xfffffffffffffffc
    5333:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 533a <kprobe_unwind_hotspot+0x533a>
			5336: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    533a:	8b 00                	mov    eax,DWORD PTR [rax]
    533c:	48 39 8c 24 a8 00 00 	cmp    QWORD PTR [rsp+0xa8],rcx
    5343:	00 
    5344:	0f 83 82 06 00 00    	jae    59cc <kprobe_unwind_hotspot+0x59cc>
    534a:	b1 03                	mov    cl,0x3
    534c:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    5353:	85 c0                	test   eax,eax
    5355:	0f 84 e7 01 00 00    	je     5542 <kprobe_unwind_hotspot+0x5542>
    535b:	48 b8 61 6d 65 20 28 	movabs rax,0x2963702820656d61
    5362:	70 63 29 
    5365:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    536a:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
    5371:	20 66 72 
    5374:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    5379:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
    5380:	63 6f 6d 
    5383:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    5388:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    538f:	6e 64 69 
    5392:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    5397:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    539e:	20 2d 3e 
    53a1:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    53a6:	66 c7 44 24 68 0a 00 	mov    WORD PTR [rsp+0x68],0xa
    53ad:	31 c0                	xor    eax,eax
    53af:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    53b4:	ba 2a 00 00 00       	mov    edx,0x2a
    53b9:	be 06 00 00 00       	mov    esi,0x6
    53be:	e9 7f 01 00 00       	jmp    5542 <kprobe_unwind_hotspot+0x5542>
    53c3:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    53ca:	75 0a 00 
    53cd:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    53d2:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    53d9:	74 61 67 
    53dc:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    53e1:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    53e8:	6e 74 20 
    53eb:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    53f0:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    53f7:	20 20 20 
    53fa:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    53ff:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    5403:	31 c9                	xor    ecx,ecx
    5405:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    540a:	be 1d 00 00 00       	mov    esi,0x1d
    540f:	bf 06 00 00 00       	mov    edi,0x6
    5414:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    5418:	8d 48 01             	lea    ecx,[rax+0x1]
    541b:	80 f9 02             	cmp    cl,0x2
    541e:	0f 82 11 d9 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    5424:	e9 5b e0 ff ff       	jmp    3484 <kprobe_unwind_hotspot+0x3484>
    5429:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    5430:	25 6c 78 
    5433:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    5438:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    543f:	69 64 61 
    5442:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    5447:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    544e:	20 70 63 
    5451:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    5456:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    545d:	20 20 20 
    5460:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    5464:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    546b:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    5470:	31 c9                	xor    ecx,ecx
    5472:	48 89 e2             	mov    rdx,rsp
    5475:	be 22 00 00 00       	mov    esi,0x22
    547a:	bf 05 00 00 00       	mov    edi,0x5
    547f:	41 b8 06 00 00 00    	mov    r8d,0x6
    5485:	e9 c4 ea ff ff       	jmp    3f4e <kprobe_unwind_hotspot+0x3f4e>
    548a:	48 b9 20 3d 20 25 6c 	movabs rcx,0xa786c25203d20
    5491:	78 0a 00 
    5494:	48 89 4c 24 2d       	mov    QWORD PTR [rsp+0x2d],rcx
    5499:	48 b9 2c 20 62 63 70 	movabs rcx,0x203d20706362202c
    54a0:	20 3d 20 
    54a3:	48 89 4c 24 28       	mov    QWORD PTR [rsp+0x28],rcx
    54a8:	48 b9 20 3d 20 30 78 	movabs rcx,0x786c257830203d20
    54af:	25 6c 78 
    54b2:	48 89 4c 24 20       	mov    QWORD PTR [rsp+0x20],rcx
    54b7:	48 b9 20 63 6d 65 74 	movabs rcx,0x646f6874656d6320
    54be:	68 6f 64 
    54c1:	48 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],rcx
    54c6:	48 b9 3d 20 30 78 25 	movabs rcx,0x2c786c257830203d
    54cd:	6c 78 2c 
    54d0:	48 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],rcx
    54d5:	48 b9 20 6d 65 74 68 	movabs rcx,0x20646f6874656d20
    54dc:	6f 64 20 
    54df:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
    54e4:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    54eb:	20 2d 3e 
    54ee:	48 89 0c 24          	mov    QWORD PTR [rsp],rcx
    54f2:	48 89 e1             	mov    rcx,rsp
    54f5:	ba 35 00 00 00       	mov    edx,0x35
    54fa:	be 06 00 00 00       	mov    esi,0x6
    54ff:	48 8b bc 24 c0 00 00 	mov    rdi,QWORD PTR [rsp+0xc0]
    5506:	00 
    5507:	48 8b 8c 24 08 01 00 	mov    rcx,QWORD PTR [rsp+0x108]
    550e:	00 
    550f:	48 89 8c 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rcx
    5516:	00 
    5517:	e9 45 ec ff ff       	jmp    4161 <kprobe_unwind_hotspot+0x4161>
    551c:	b0 01                	mov    al,0x1
    551e:	89 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],eax
    5525:	b8 76 74 61 62       	mov    eax,0x62617476
    552a:	48 89 84 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rax
    5531:	00 
    5532:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5539 <kprobe_unwind_hotspot+0x5539>
			5535: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5539:	83 38 00             	cmp    DWORD PTR [rax],0x0
    553c:	0f 85 30 13 00 00    	jne    6872 <kprobe_unwind_hotspot+0x6872>
    5542:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x8
    5549:	08 00 00 00 
    554d:	b8 08 00 00 00       	mov    eax,0x8
    5552:	e9 a6 04 00 00       	jmp    59fd <kprobe_unwind_hotspot+0x59fd>
    5557:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 555e <kprobe_unwind_hotspot+0x555e>
			555a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    555e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5561:	0f 85 4e 13 00 00    	jne    68b5 <kprobe_unwind_hotspot+0x68b5>
    5567:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
    556e:	c7 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],0x0
    5575:	00 00 00 00 
    5579:	48 8b 8c 24 b8 00 00 	mov    rcx,QWORD PTR [rsp+0xb8]
    5580:	00 
    5581:	85 c0                	test   eax,eax
    5583:	0f 85 74 04 00 00    	jne    59fd <kprobe_unwind_hotspot+0x59fd>
    5589:	e9 57 04 00 00       	jmp    59e5 <kprobe_unwind_hotspot+0x59e5>
    558e:	8b 9c 24 f8 00 00 00 	mov    ebx,DWORD PTR [rsp+0xf8]
    5595:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
    559c:	00 
    559d:	48 8b 8c 24 b0 00 00 	mov    rcx,QWORD PTR [rsp+0xb0]
    55a4:	00 
    55a5:	4c 8d 2c 19          	lea    r13,[rcx+rbx*1]
    55a9:	49 83 c5 30          	add    r13,0x30
    55ad:	48 29 c8             	sub    rax,rcx
    55b0:	0f 82 80 07 00 00    	jb     5d36 <kprobe_unwind_hotspot+0x5d36>
    55b6:	4c 39 ac 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],r13
    55bd:	00 
    55be:	0f 83 72 07 00 00    	jae    5d36 <kprobe_unwind_hotspot+0x5d36>
    55c4:	b1 03                	mov    cl,0x3
    55c6:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    55cd:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 55d4 <kprobe_unwind_hotspot+0x55d4>
			55d0: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    55d4:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    55d7:	0f 85 32 13 00 00    	jne    690f <kprobe_unwind_hotspot+0x690f>
    55dd:	48 8b 8c 24 b8 00 00 	mov    rcx,QWORD PTR [rsp+0xb8]
    55e4:	00 
    55e5:	e9 fb 03 00 00       	jmp    59e5 <kprobe_unwind_hotspot+0x59e5>
    55ea:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    55f1:	64 0a 00 
    55f4:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    55f9:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    5600:	69 63 49 
    5603:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    5608:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    560f:	66 6f 72 
    5612:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    5617:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    561e:	69 63 73 
    5621:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    5626:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    562d:	6b 75 70 
    5630:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    5635:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    563c:	64 20 74 
    563f:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    5644:	8b 84 24 d0 00 00 00 	mov    eax,DWORD PTR [rsp+0xd0]
    564b:	31 c9                	xor    ecx,ecx
    564d:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    5652:	be 2e 00 00 00       	mov    esi,0x2e
    5657:	bf 06 00 00 00       	mov    edi,0x6
    565c:	e9 06 ed ff ff       	jmp    4367 <kprobe_unwind_hotspot+0x4367>
    5661:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    5668:	75 0a 00 
    566b:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    5670:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    5677:	74 61 67 
    567a:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    567f:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    5686:	6e 74 20 
    5689:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    568e:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    5695:	20 20 20 
    5698:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    569d:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    56a1:	31 c9                	xor    ecx,ecx
    56a3:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    56a8:	be 1d 00 00 00       	mov    esi,0x1d
    56ad:	bf 06 00 00 00       	mov    edi,0x6
    56b2:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    56b6:	8d 48 01             	lea    ecx,[rax+0x1]
    56b9:	80 f9 02             	cmp    cl,0x2
    56bc:	0f 82 ff ed ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    56c2:	0f b6 c0             	movzx  eax,al
    56c5:	48 29 c3             	sub    rbx,rax
    56c8:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    56cc:	48 89 e7             	mov    rdi,rsp
    56cf:	b8 01 00 00 00       	mov    eax,0x1
    56d4:	b9 70 00 00 00       	mov    ecx,0x70
    56d9:	be 01 00 00 00       	mov    esi,0x1
    56de:	ff d1                	call   rcx
    56e0:	48 85 c0             	test   rax,rax
    56e3:	0f 85 2f ab ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    56e9:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 56f0 <kprobe_unwind_hotspot+0x56f0>
			56ec: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    56f0:	83 38 00             	cmp    DWORD PTR [rax],0x0
    56f3:	0f 85 3c 09 00 00    	jne    6035 <kprobe_unwind_hotspot+0x6035>
    56f9:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    56fd:	8d 48 01             	lea    ecx,[rax+0x1]
    5700:	80 f9 02             	cmp    cl,0x2
    5703:	0f 82 b8 ed ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    5709:	0f b6 c0             	movzx  eax,al
    570c:	48 29 c3             	sub    rbx,rax
    570f:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    5713:	48 89 e7             	mov    rdi,rsp
    5716:	b8 01 00 00 00       	mov    eax,0x1
    571b:	b9 70 00 00 00       	mov    ecx,0x70
    5720:	be 01 00 00 00       	mov    esi,0x1
    5725:	ff d1                	call   rcx
    5727:	48 85 c0             	test   rax,rax
    572a:	0f 85 e8 aa ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    5730:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5737 <kprobe_unwind_hotspot+0x5737>
			5733: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5737:	83 38 00             	cmp    DWORD PTR [rax],0x0
    573a:	0f 85 8d 0d 00 00    	jne    64cd <kprobe_unwind_hotspot+0x64cd>
    5740:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    5744:	8d 48 01             	lea    ecx,[rax+0x1]
    5747:	80 f9 02             	cmp    cl,0x2
    574a:	0f 82 71 ed ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    5750:	0f b6 c0             	movzx  eax,al
    5753:	48 29 c3             	sub    rbx,rax
    5756:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    575a:	48 89 e7             	mov    rdi,rsp
    575d:	b8 01 00 00 00       	mov    eax,0x1
    5762:	b9 70 00 00 00       	mov    ecx,0x70
    5767:	be 01 00 00 00       	mov    esi,0x1
    576c:	ff d1                	call   rcx
    576e:	48 85 c0             	test   rax,rax
    5771:	0f 85 a1 aa ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    5777:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 577e <kprobe_unwind_hotspot+0x577e>
			577a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    577e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5781:	0f 85 57 0e 00 00    	jne    65de <kprobe_unwind_hotspot+0x65de>
    5787:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    578b:	8d 48 01             	lea    ecx,[rax+0x1]
    578e:	80 f9 02             	cmp    cl,0x2
    5791:	0f 82 2a ed ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    5797:	0f b6 c0             	movzx  eax,al
    579a:	48 29 c3             	sub    rbx,rax
    579d:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    57a1:	48 89 e7             	mov    rdi,rsp
    57a4:	b8 01 00 00 00       	mov    eax,0x1
    57a9:	b9 70 00 00 00       	mov    ecx,0x70
    57ae:	be 01 00 00 00       	mov    esi,0x1
    57b3:	ff d1                	call   rcx
    57b5:	48 85 c0             	test   rax,rax
    57b8:	0f 85 5a aa ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    57be:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 57c5 <kprobe_unwind_hotspot+0x57c5>
			57c1: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    57c5:	83 38 00             	cmp    DWORD PTR [rax],0x0
    57c8:	0f 85 b9 11 00 00    	jne    6987 <kprobe_unwind_hotspot+0x6987>
    57ce:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    57d2:	8d 48 01             	lea    ecx,[rax+0x1]
    57d5:	80 f9 02             	cmp    cl,0x2
    57d8:	0f 82 e3 ec ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    57de:	0f b6 c0             	movzx  eax,al
    57e1:	48 29 c3             	sub    rbx,rax
    57e4:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    57e8:	48 89 e7             	mov    rdi,rsp
    57eb:	b8 01 00 00 00       	mov    eax,0x1
    57f0:	b9 70 00 00 00       	mov    ecx,0x70
    57f5:	be 01 00 00 00       	mov    esi,0x1
    57fa:	ff d1                	call   rcx
    57fc:	48 85 c0             	test   rax,rax
    57ff:	0f 85 13 aa ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    5805:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 580c <kprobe_unwind_hotspot+0x580c>
			5808: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    580c:	83 38 00             	cmp    DWORD PTR [rax],0x0
    580f:	0f 85 d8 11 00 00    	jne    69ed <kprobe_unwind_hotspot+0x69ed>
    5815:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    5819:	8d 48 01             	lea    ecx,[rax+0x1]
    581c:	80 f9 02             	cmp    cl,0x2
    581f:	0f 82 9c ec ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    5825:	0f b6 c0             	movzx  eax,al
    5828:	48 29 c3             	sub    rbx,rax
    582b:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    582f:	48 89 e7             	mov    rdi,rsp
    5832:	b8 01 00 00 00       	mov    eax,0x1
    5837:	b9 70 00 00 00       	mov    ecx,0x70
    583c:	be 01 00 00 00       	mov    esi,0x1
    5841:	ff d1                	call   rcx
    5843:	48 85 c0             	test   rax,rax
    5846:	0f 85 cc a9 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    584c:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5853 <kprobe_unwind_hotspot+0x5853>
			584f: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5853:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5856:	0f 85 f7 11 00 00    	jne    6a53 <kprobe_unwind_hotspot+0x6a53>
    585c:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    5860:	8d 48 01             	lea    ecx,[rax+0x1]
    5863:	80 f9 02             	cmp    cl,0x2
    5866:	0f 82 55 ec ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    586c:	0f b6 c0             	movzx  eax,al
    586f:	48 29 c3             	sub    rbx,rax
    5872:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    5876:	48 89 e7             	mov    rdi,rsp
    5879:	b8 01 00 00 00       	mov    eax,0x1
    587e:	b9 70 00 00 00       	mov    ecx,0x70
    5883:	be 01 00 00 00       	mov    esi,0x1
    5888:	ff d1                	call   rcx
    588a:	48 85 c0             	test   rax,rax
    588d:	0f 85 85 a9 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    5893:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 589a <kprobe_unwind_hotspot+0x589a>
			5896: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    589a:	83 38 00             	cmp    DWORD PTR [rax],0x0
    589d:	0f 85 16 12 00 00    	jne    6ab9 <kprobe_unwind_hotspot+0x6ab9>
    58a3:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    58a7:	8d 48 01             	lea    ecx,[rax+0x1]
    58aa:	80 f9 02             	cmp    cl,0x2
    58ad:	0f 82 0e ec ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    58b3:	e9 62 12 00 00       	jmp    6b1a <kprobe_unwind_hotspot+0x6b1a>
    58b8:	48 b8 74 63 68 20 25 	movabs rax,0xa642520686374
    58bf:	64 0a 00 
    58c2:	48 89 44 24 56       	mov    QWORD PTR [rsp+0x56],rax
    58c7:	48 b8 65 74 73 20 6d 	movabs rax,0x6374616d20737465
    58ce:	61 74 63 
    58d1:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    58d6:	48 b8 74 65 72 5f 6f 	movabs rax,0x7366666f5f726574
    58dd:	66 66 73 
    58e0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    58e5:	48 b8 69 6e 74 65 72 	movabs rax,0x6572707265746e69
    58ec:	70 72 65 
    58ef:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    58f4:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    58fb:	00 
    58fc:	0f b7 40 20          	movzx  eax,WORD PTR [rax+0x20]
    5900:	31 c9                	xor    ecx,ecx
    5902:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    5907:	be 1e 00 00 00       	mov    esi,0x1e
    590c:	bf 06 00 00 00       	mov    edi,0x6
    5911:	e9 0e e0 ff ff       	jmp    3924 <kprobe_unwind_hotspot+0x3924>
    5916:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    591d:	64 0a 00 
    5920:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    5925:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    592c:	69 63 49 
    592f:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    5934:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    593b:	66 6f 72 
    593e:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    5943:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    594a:	69 63 73 
    594d:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    5952:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    5959:	6b 75 70 
    595c:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    5961:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    5968:	64 20 74 
    596b:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    596f:	8b 84 24 08 01 00 00 	mov    eax,DWORD PTR [rsp+0x108]
    5976:	31 c9                	xor    ecx,ecx
    5978:	48 89 e2             	mov    rdx,rsp
    597b:	be 2e 00 00 00       	mov    esi,0x2e
    5980:	bf 06 00 00 00       	mov    edi,0x6
    5985:	e9 91 e8 ff ff       	jmp    421b <kprobe_unwind_hotspot+0x421b>
    598a:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5991 <kprobe_unwind_hotspot+0x5991>
			598d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5991:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5994:	0f 85 d7 13 00 00    	jne    6d71 <kprobe_unwind_hotspot+0x6d71>
    599a:	c7 84 24 14 01 00 00 	mov    DWORD PTR [rsp+0x114],0x2d
    59a1:	2d 00 00 00 
    59a5:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 59ac <kprobe_unwind_hotspot+0x59ac>
			59a8: R_X86_64_REX_GOTPCRELX	metrics-0x4
    59ac:	48 8d b4 24 14 01 00 	lea    rsi,[rsp+0x114]
    59b3:	00 
    59b4:	b8 01 00 00 00       	mov    eax,0x1
    59b9:	ff d0                	call   rax
    59bb:	48 85 c0             	test   rax,rax
    59be:	0f 84 c3 04 00 00    	je     5e87 <kprobe_unwind_hotspot+0x5e87>
    59c4:	48 ff 00             	inc    QWORD PTR [rax]
    59c7:	e9 cb 04 00 00       	jmp    5e97 <kprobe_unwind_hotspot+0x5e97>
    59cc:	b1 03                	mov    cl,0x3
    59ce:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    59d5:	85 c0                	test   eax,eax
    59d7:	0f 85 01 14 00 00    	jne    6dde <kprobe_unwind_hotspot+0x6dde>
    59dd:	48 8b 8c 24 b0 00 00 	mov    rcx,QWORD PTR [rsp+0xb0]
    59e4:	00 
    59e5:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x10
    59ec:	10 00 00 00 
    59f0:	b8 10 00 00 00       	mov    eax,0x10
    59f5:	48 89 8c 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rcx
    59fc:	00 
    59fd:	89 c0                	mov    eax,eax
    59ff:	48 01 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],rax
    5a06:	00 
    5a07:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    5a0e:	00 
    5a0f:	48 8d 50 f0          	lea    rdx,[rax-0x10]
    5a13:	48 89 e7             	mov    rdi,rsp
    5a16:	b8 10 00 00 00       	mov    eax,0x10
    5a1b:	b9 70 00 00 00       	mov    ecx,0x70
    5a20:	be 10 00 00 00       	mov    esi,0x10
    5a25:	ff d1                	call   rcx
    5a27:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    5a2c:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    5a33:	00 
    5a34:	83 bc 24 f8 00 00 00 	cmp    DWORD PTR [rsp+0xf8],0x10
    5a3b:	10 
    5a3c:	72 1c                	jb     5a5a <kprobe_unwind_hotspot+0x5a5a>
    5a3e:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5a45 <kprobe_unwind_hotspot+0x5a45>
			5a41: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5a45:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5a48:	0f 85 00 14 00 00    	jne    6e4e <kprobe_unwind_hotspot+0x6e4e>
    5a4e:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    5a52:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    5a59:	00 
    5a5a:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    5a61:	48 83 f8 7e          	cmp    rax,0x7e
    5a65:	0f 87 4b b4 ff ff    	ja     eb6 <kprobe_unwind_hotspot+0xeb6>
    5a6b:	41 0f b6 8e 30 0f 00 	movzx  ecx,BYTE PTR [r14+0xf30]
    5a72:	00 
    5a73:	0f b6 94 24 c8 00 00 	movzx  edx,BYTE PTR [rsp+0xc8]
    5a7a:	00 
    5a7b:	48 c1 e2 3c          	shl    rdx,0x3c
    5a7f:	48 8b bc 24 20 01 00 	mov    rdi,QWORD PTR [rsp+0x120]
    5a86:	00 
    5a87:	48 c1 e7 20          	shl    rdi,0x20
    5a8b:	8b b4 24 c0 00 00 00 	mov    esi,DWORD PTR [rsp+0xc0]
    5a92:	48 09 fe             	or     rsi,rdi
    5a95:	48 09 d6             	or     rsi,rdx
    5a98:	8d 50 01             	lea    edx,[rax+0x1]
    5a9b:	41 89 96 c0 02 00 00 	mov    DWORD PTR [r14+0x2c0],edx
    5aa2:	48 8d 04 40          	lea    rax,[rax+rax*2]
    5aa6:	48 8b 94 24 18 01 00 	mov    rdx,QWORD PTR [rsp+0x118]
    5aad:	00 
    5aae:	49 89 94 c6 d0 02 00 	mov    QWORD PTR [r14+rax*8+0x2d0],rdx
    5ab5:	00 
    5ab6:	49 89 b4 c6 d8 02 00 	mov    QWORD PTR [r14+rax*8+0x2d8],rsi
    5abd:	00 
    5abe:	41 c6 84 c6 e0 02 00 	mov    BYTE PTR [r14+rax*8+0x2e0],0x5
    5ac5:	00 05 
    5ac7:	41 88 8c c6 e1 02 00 	mov    BYTE PTR [r14+rax*8+0x2e1],cl
    5ace:	00 
    5acf:	41 c7 84 c6 e2 02 00 	mov    DWORD PTR [r14+rax*8+0x2e2],0x0
    5ad6:	00 00 00 00 00 
    5adb:	66 41 c7 84 c6 e6 02 	mov    WORD PTR [r14+rax*8+0x2e6],0x0
    5ae2:	00 00 00 00 
    5ae6:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5aed <kprobe_unwind_hotspot+0x5aed>
			5ae9: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5aed:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5af0:	0f 85 9b 13 00 00    	jne    6e91 <kprobe_unwind_hotspot+0x6e91>
    5af6:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    5afd:	00 
    5afe:	49 89 86 d0 0e 00 00 	mov    QWORD PTR [r14+0xed0],rax
    5b05:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    5b0c:	00 
    5b0d:	49 89 86 d8 0e 00 00 	mov    QWORD PTR [r14+0xed8],rax
    5b14:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
    5b1b:	00 
    5b1c:	49 89 86 e0 0e 00 00 	mov    QWORD PTR [r14+0xee0],rax
    5b23:	41 c6 86 30 0f 00 00 	mov    BYTE PTR [r14+0xf30],0x1
    5b2a:	01 
    5b2b:	c7 04 24 2a 00 00 00 	mov    DWORD PTR [rsp],0x2a
    5b32:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 5b39 <kprobe_unwind_hotspot+0x5b39>
			5b35: R_X86_64_REX_GOTPCRELX	metrics-0x4
    5b39:	48 89 e6             	mov    rsi,rsp
    5b3c:	b8 01 00 00 00       	mov    eax,0x1
    5b41:	ff d0                	call   rax
    5b43:	48 85 c0             	test   rax,rax
    5b46:	74 0e                	je     5b56 <kprobe_unwind_hotspot+0x5b56>
    5b48:	48 ff 00             	inc    QWORD PTR [rax]
    5b4b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5b52 <kprobe_unwind_hotspot+0x5b52>
			5b4e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5b52:	8b 00                	mov    eax,DWORD PTR [rax]
    5b54:	eb 12                	jmp    5b68 <kprobe_unwind_hotspot+0x5b68>
    5b56:	31 c0                	xor    eax,eax
    5b58:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 5b5f <kprobe_unwind_hotspot+0x5b5f>
			5b5b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5b5f:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    5b62:	0f 85 99 13 00 00    	jne    6f01 <kprobe_unwind_hotspot+0x6f01>
    5b68:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    5b6f:	4d 85 ed             	test   r13,r13
    5b72:	0f 84 a7 c6 ff ff    	je     221f <kprobe_unwind_hotspot+0x221f>
    5b78:	85 c0                	test   eax,eax
    5b7a:	0f 85 f4 13 00 00    	jne    6f74 <kprobe_unwind_hotspot+0x6f74>
    5b80:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    5b87:	ff ff 00 
    5b8a:	49 39 c5             	cmp    r13,rax
    5b8d:	0f 87 47 bb ff ff    	ja     16da <kprobe_unwind_hotspot+0x16da>
    5b93:	49 81 fd 00 10 00 00 	cmp    r13,0x1000
    5b9a:	0f 82 e9 c2 ff ff    	jb     1e89 <kprobe_unwind_hotspot+0x1e89>
    5ba0:	41 8b 06             	mov    eax,DWORD PTR [r14]
    5ba3:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x60
    5baa:	60 00 00 00 
    5bae:	0f 38 f1 84 24 d4 00 	movbe  DWORD PTR [rsp+0xd4],eax
    5bb5:	00 00 
    5bb7:	4c 0f 38 f1 ac 24 d8 	movbe  QWORD PTR [rsp+0xd8],r13
    5bbe:	00 00 00 
    5bc1:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 5bc8 <kprobe_unwind_hotspot+0x5bc8>
			5bc4: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    5bc8:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    5bcf:	00 
    5bd0:	b8 01 00 00 00       	mov    eax,0x1
    5bd5:	ff d0                	call   rax
    5bd7:	48 85 c0             	test   rax,rax
    5bda:	0f 84 92 3b 00 00    	je     9772 <kprobe_unwind_hotspot+0x9772>
    5be0:	48 8b 58 08          	mov    rbx,QWORD PTR [rax+0x8]
    5be4:	48 89 d9             	mov    rcx,rbx
    5be7:	48 ba ff ff ff ff ff 	movabs rdx,0xffffffffffffff
    5bee:	ff ff 00 
    5bf1:	48 21 d1             	and    rcx,rdx
    5bf4:	49 89 8e 20 0f 00 00 	mov    QWORD PTR [r14+0xf20],rcx
    5bfb:	48 8b 00             	mov    rax,QWORD PTR [rax]
    5bfe:	49 89 86 10 0f 00 00 	mov    QWORD PTR [r14+0xf10],rax
    5c05:	48 c1 eb 38          	shr    rbx,0x38
    5c09:	4c 89 ea             	mov    rdx,r13
    5c0c:	48 29 ca             	sub    rdx,rcx
    5c0f:	49 89 96 18 0f 00 00 	mov    QWORD PTR [r14+0xf18],rdx
    5c16:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 5c1d <kprobe_unwind_hotspot+0x5c1d>
			5c19: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5c1d:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    5c20:	0f 85 e4 13 00 00    	jne    700a <kprobe_unwind_hotspot+0x700a>
    5c26:	83 fb 01             	cmp    ebx,0x1
    5c29:	0f 85 7e 1a 00 00    	jne    76ad <kprobe_unwind_hotspot+0x76ad>
    5c2f:	49 8b 86 10 0f 00 00 	mov    rax,QWORD PTR [r14+0xf10]
    5c36:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    5c3d:	00 
    5c3e:	4d 8b ae 18 0f 00 00 	mov    r13,QWORD PTR [r14+0xf18]
    5c45:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 5c4c <kprobe_unwind_hotspot+0x5c4c>
			5c48: R_X86_64_REX_GOTPCRELX	interpreter_offsets-0x4
    5c4c:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    5c53:	00 
    5c54:	b8 01 00 00 00       	mov    eax,0x1
    5c59:	ff d0                	call   rax
    5c5b:	bb 01 00 00 00       	mov    ebx,0x1
    5c60:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    5c67:	00 
    5c68:	48 85 c0             	test   rax,rax
    5c6b:	0f 84 3c 1a 00 00    	je     76ad <kprobe_unwind_hotspot+0x76ad>
    5c71:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    5c78:	00 
    5c79:	4c 39 28             	cmp    QWORD PTR [rax],r13
    5c7c:	77 0e                	ja     5c8c <kprobe_unwind_hotspot+0x5c8c>
    5c7e:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    5c85:	00 
    5c86:	4c 39 68 08          	cmp    QWORD PTR [rax+0x8],r13
    5c8a:	73 24                	jae    5cb0 <kprobe_unwind_hotspot+0x5cb0>
    5c8c:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    5c93:	00 
    5c94:	4c 39 68 10          	cmp    QWORD PTR [rax+0x10],r13
    5c98:	0f 87 0f 1a 00 00    	ja     76ad <kprobe_unwind_hotspot+0x76ad>
    5c9e:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    5ca5:	00 
    5ca6:	4c 39 68 18          	cmp    QWORD PTR [rax+0x18],r13
    5caa:	0f 82 fd 19 00 00    	jb     76ad <kprobe_unwind_hotspot+0x76ad>
    5cb0:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5cb7 <kprobe_unwind_hotspot+0x5cb7>
			5cb3: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5cb7:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5cba:	0f 85 3f 14 00 00    	jne    70ff <kprobe_unwind_hotspot+0x70ff>
    5cc0:	41 8b 86 80 13 00 00 	mov    eax,DWORD PTR [r14+0x1380]
    5cc7:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
    5cce:	00 
    5ccf:	8b 49 20             	mov    ecx,DWORD PTR [rcx+0x20]
    5cd2:	0f a3 c8             	bt     eax,ecx
    5cd5:	0f 83 da 08 00 00    	jae    65b5 <kprobe_unwind_hotspot+0x65b5>
    5cdb:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5ce2 <kprobe_unwind_hotspot+0x5ce2>
			5cde: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5ce2:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5ce5:	0f 84 c2 19 00 00    	je     76ad <kprobe_unwind_hotspot+0x76ad>
    5ceb:	48 b8 6e 64 65 72 20 	movabs rax,0x6e6f64207265646e
    5cf2:	64 6f 6e 
    5cf5:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    5cfa:	48 b8 74 65 72 20 75 	movabs rax,0x69776e7520726574
    5d01:	6e 77 69 
    5d04:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    5d09:	48 b8 69 6e 74 65 72 	movabs rax,0x6572707265746e69
    5d10:	70 72 65 
    5d13:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    5d18:	c7 44 24 57 6e 65 0a 	mov    DWORD PTR [rsp+0x57],0xa656e
    5d1f:	00 
    5d20:	31 c0                	xor    eax,eax
    5d22:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    5d27:	ba 1b 00 00 00       	mov    edx,0x1b
    5d2c:	be 06 00 00 00       	mov    esi,0x6
    5d31:	e9 77 19 00 00       	jmp    76ad <kprobe_unwind_hotspot+0x76ad>
    5d36:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    5d3d:	00 
    5d3e:	48 8d 14 18          	lea    rdx,[rax+rbx*1]
    5d42:	48 83 c2 f8          	add    rdx,0xfffffffffffffff8
    5d46:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    5d4b:	b8 30 00 00 00       	mov    eax,0x30
    5d50:	b9 70 00 00 00       	mov    ecx,0x70
    5d55:	be 30 00 00 00       	mov    esi,0x30
    5d5a:	ff d1                	call   rcx
    5d5c:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5d63 <kprobe_unwind_hotspot+0x5d63>
			5d5f: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5d63:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5d66:	0f 85 f1 13 00 00    	jne    715d <kprobe_unwind_hotspot+0x715d>
    5d6c:	41 8b 06             	mov    eax,DWORD PTR [r14]
    5d6f:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    5d76:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    5d7c:	48 01 9c 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],rbx
    5d83:	00 
    5d84:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
    5d89:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    5d90:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 5d97 <kprobe_unwind_hotspot+0x5d97>
			5d93: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    5d97:	48 89 e6             	mov    rsi,rsp
    5d9a:	b8 01 00 00 00       	mov    eax,0x1
    5d9f:	ff d0                	call   rax
    5da1:	48 85 c0             	test   rax,rax
    5da4:	0f 84 0e 01 00 00    	je     5eb8 <kprobe_unwind_hotspot+0x5eb8>
    5daa:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    5dae:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    5db5:	00 00 ff 
    5db8:	48 21 c8             	and    rax,rcx
    5dbb:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    5dc2:	00 00 02 
    5dc5:	48 39 c8             	cmp    rax,rcx
    5dc8:	0f 85 ea 00 00 00    	jne    5eb8 <kprobe_unwind_hotspot+0x5eb8>
    5dce:	31 db                	xor    ebx,ebx
    5dd0:	e9 02 05 00 00       	jmp    62d7 <kprobe_unwind_hotspot+0x62d7>
    5dd5:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    5ddc:	75 0a 00 
    5ddf:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    5de4:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    5deb:	74 61 67 
    5dee:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    5df3:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    5dfa:	6e 74 20 
    5dfd:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    5e02:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    5e09:	20 20 20 
    5e0c:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    5e11:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    5e15:	31 c9                	xor    ecx,ecx
    5e17:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    5e1c:	be 1d 00 00 00       	mov    esi,0x1d
    5e21:	bf 06 00 00 00       	mov    edi,0x6
    5e26:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    5e2a:	8d 48 01             	lea    ecx,[rax+0x1]
    5e2d:	80 f9 02             	cmp    cl,0x2
    5e30:	0f 82 ff ce ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    5e36:	e9 90 d6 ff ff       	jmp    34cb <kprobe_unwind_hotspot+0x34cb>
    5e3b:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    5e3f:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    5e46:	00 
    5e47:	48 39 c8             	cmp    rax,rcx
    5e4a:	0f 82 ae f4 ff ff    	jb     52fe <kprobe_unwind_hotspot+0x52fe>
    5e50:	48 3b 84 24 e0 00 00 	cmp    rax,QWORD PTR [rsp+0xe0]
    5e57:	00 
    5e58:	0f 83 a0 f4 ff ff    	jae    52fe <kprobe_unwind_hotspot+0x52fe>
    5e5e:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # 5e65 <kprobe_unwind_hotspot+0x5e65>
			5e61: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5e65:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
    5e68:	0f 85 4a 13 00 00    	jne    71b8 <kprobe_unwind_hotspot+0x71b8>
    5e6e:	89 c2                	mov    edx,eax
    5e70:	29 ca                	sub    edx,ecx
    5e72:	48 89 94 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rdx
    5e79:	00 
    5e7a:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    5e81:	00 
    5e82:	e9 87 f4 ff ff       	jmp    530e <kprobe_unwind_hotspot+0x530e>
    5e87:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5e8e <kprobe_unwind_hotspot+0x5e8e>
			5e8a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5e8e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5e91:	0f 85 c4 13 00 00    	jne    725b <kprobe_unwind_hotspot+0x725b>
    5e97:	b8 e9 03 00 00       	mov    eax,0x3e9
    5e9c:	31 c9                	xor    ecx,ecx
    5e9e:	ba 49 6e 74 65       	mov    edx,0x65746e49
    5ea3:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    5eaa:	00 
    5eab:	85 c0                	test   eax,eax
    5ead:	0f 85 80 a4 ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    5eb3:	e9 5a 04 00 00       	jmp    6312 <kprobe_unwind_hotspot+0x6312>
    5eb8:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5ebf <kprobe_unwind_hotspot+0x5ebf>
			5ebb: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5ebf:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5ec2:	0f 85 07 14 00 00    	jne    72cf <kprobe_unwind_hotspot+0x72cf>
    5ec8:	41 8b 06             	mov    eax,DWORD PTR [r14]
    5ecb:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    5ed2:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    5ed8:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    5edd:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    5ee4:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 5eeb <kprobe_unwind_hotspot+0x5eeb>
			5ee7: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    5eeb:	48 89 e6             	mov    rsi,rsp
    5eee:	bb 01 00 00 00       	mov    ebx,0x1
    5ef3:	b8 01 00 00 00       	mov    eax,0x1
    5ef8:	ff d0                	call   rax
    5efa:	48 85 c0             	test   rax,rax
    5efd:	74 2e                	je     5f2d <kprobe_unwind_hotspot+0x5f2d>
    5eff:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    5f03:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    5f0a:	00 00 ff 
    5f0d:	48 21 c8             	and    rax,rcx
    5f10:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    5f17:	00 00 02 
    5f1a:	48 39 c8             	cmp    rax,rcx
    5f1d:	75 0e                	jne    5f2d <kprobe_unwind_hotspot+0x5f2d>
    5f1f:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x8
    5f26:	00 08 
    5f28:	e9 aa 03 00 00       	jmp    62d7 <kprobe_unwind_hotspot+0x62d7>
    5f2d:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 5f34 <kprobe_unwind_hotspot+0x5f34>
			5f30: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    5f34:	83 38 00             	cmp    DWORD PTR [rax],0x0
    5f37:	0f 85 f3 13 00 00    	jne    7330 <kprobe_unwind_hotspot+0x7330>
    5f3d:	41 8b 06             	mov    eax,DWORD PTR [r14]
    5f40:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    5f47:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    5f4d:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    5f52:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    5f59:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 5f60 <kprobe_unwind_hotspot+0x5f60>
			5f5c: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    5f60:	48 89 e6             	mov    rsi,rsp
    5f63:	b8 01 00 00 00       	mov    eax,0x1
    5f68:	ff d0                	call   rax
    5f6a:	48 85 c0             	test   rax,rax
    5f6d:	0f 84 28 01 00 00    	je     609b <kprobe_unwind_hotspot+0x609b>
    5f73:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    5f77:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    5f7e:	00 00 ff 
    5f81:	48 21 c8             	and    rax,rcx
    5f84:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    5f8b:	00 00 02 
    5f8e:	48 39 c8             	cmp    rax,rcx
    5f91:	0f 85 04 01 00 00    	jne    609b <kprobe_unwind_hotspot+0x609b>
    5f97:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x10
    5f9e:	00 10 
    5fa0:	bb 02 00 00 00       	mov    ebx,0x2
    5fa5:	e9 2d 03 00 00       	jmp    62d7 <kprobe_unwind_hotspot+0x62d7>
    5faa:	48 b9 6c 6f 62 20 25 	movabs rcx,0xa786c2520626f6c
    5fb1:	6c 78 0a 
    5fb4:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    5fb9:	48 b9 74 6f 20 63 6f 	movabs rcx,0x6265646f63206f74
    5fc0:	64 65 62 
    5fc3:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    5fc8:	48 b9 20 6d 61 70 70 	movabs rcx,0x2064657070616d20
    5fcf:	65 64 20 
    5fd2:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    5fd7:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    5fde:	20 2d 3e 
    5fe1:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    5fe6:	c6 44 24 60 00       	mov    BYTE PTR [rsp+0x60],0x0
    5feb:	31 c9                	xor    ecx,ecx
    5fed:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    5ff2:	be 21 00 00 00       	mov    esi,0x21
    5ff7:	bf 06 00 00 00       	mov    edi,0x6
    5ffc:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    6003:	00 
    6004:	48 85 c0             	test   rax,rax
    6007:	0f 85 f6 e4 ff ff    	jne    4503 <kprobe_unwind_hotspot+0x4503>
    600d:	e9 12 a2 ff ff       	jmp    224 <kprobe_unwind_hotspot+0x224>
    6012:	41 83 be c0 02 00 00 	cmp    DWORD PTR [r14+0x2c0],0x0
    6019:	00 
    601a:	0f 84 15 03 00 00    	je     6335 <kprobe_unwind_hotspot+0x6335>
    6020:	41 80 7f 1f 00       	cmp    BYTE PTR [r15+0x1f],0x0
    6025:	0f 84 45 03 00 00    	je     6370 <kprobe_unwind_hotspot+0x6370>
    602b:	4c 8b 6c 24 50       	mov    r13,QWORD PTR [rsp+0x50]
    6030:	e9 40 03 00 00       	jmp    6375 <kprobe_unwind_hotspot+0x6375>
    6035:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    603c:	75 0a 00 
    603f:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6044:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    604b:	74 61 67 
    604e:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6053:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    605a:	6e 74 20 
    605d:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6062:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6069:	20 20 20 
    606c:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6071:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6075:	31 c9                	xor    ecx,ecx
    6077:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    607c:	be 1d 00 00 00       	mov    esi,0x1d
    6081:	bf 06 00 00 00       	mov    edi,0x6
    6086:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    608a:	8d 48 01             	lea    ecx,[rax+0x1]
    608d:	80 f9 02             	cmp    cl,0x2
    6090:	0f 82 2b e4 ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    6096:	e9 6e f6 ff ff       	jmp    5709 <kprobe_unwind_hotspot+0x5709>
    609b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 60a2 <kprobe_unwind_hotspot+0x60a2>
			609e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    60a2:	83 38 00             	cmp    DWORD PTR [rax],0x0
    60a5:	0f 85 e6 12 00 00    	jne    7391 <kprobe_unwind_hotspot+0x7391>
    60ab:	41 8b 06             	mov    eax,DWORD PTR [r14]
    60ae:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    60b5:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    60bb:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    60c0:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    60c7:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 60ce <kprobe_unwind_hotspot+0x60ce>
			60ca: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    60ce:	48 89 e6             	mov    rsi,rsp
    60d1:	b8 01 00 00 00       	mov    eax,0x1
    60d6:	ff d0                	call   rax
    60d8:	48 85 c0             	test   rax,rax
    60db:	74 33                	je     6110 <kprobe_unwind_hotspot+0x6110>
    60dd:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    60e1:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    60e8:	00 00 ff 
    60eb:	48 21 c8             	and    rax,rcx
    60ee:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    60f5:	00 00 02 
    60f8:	48 39 c8             	cmp    rax,rcx
    60fb:	75 13                	jne    6110 <kprobe_unwind_hotspot+0x6110>
    60fd:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x18
    6104:	00 18 
    6106:	bb 03 00 00 00       	mov    ebx,0x3
    610b:	e9 c7 01 00 00       	jmp    62d7 <kprobe_unwind_hotspot+0x62d7>
    6110:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 6117 <kprobe_unwind_hotspot+0x6117>
			6113: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    6117:	83 38 00             	cmp    DWORD PTR [rax],0x0
    611a:	0f 85 d2 12 00 00    	jne    73f2 <kprobe_unwind_hotspot+0x73f2>
    6120:	41 8b 06             	mov    eax,DWORD PTR [r14]
    6123:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    612a:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    6130:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    6135:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    613c:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 6143 <kprobe_unwind_hotspot+0x6143>
			613f: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    6143:	48 89 e6             	mov    rsi,rsp
    6146:	b8 01 00 00 00       	mov    eax,0x1
    614b:	ff d0                	call   rax
    614d:	48 85 c0             	test   rax,rax
    6150:	0f 84 10 01 00 00    	je     6266 <kprobe_unwind_hotspot+0x6266>
    6156:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    615a:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    6161:	00 00 ff 
    6164:	48 21 c8             	and    rax,rcx
    6167:	48 b9 00 00 00 00 00 	movabs rcx,0x200000000000000
    616e:	00 00 02 
    6171:	48 39 c8             	cmp    rax,rcx
    6174:	0f 85 ec 00 00 00    	jne    6266 <kprobe_unwind_hotspot+0x6266>
    617a:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x20
    6181:	00 20 
    6183:	bb 04 00 00 00       	mov    ebx,0x4
    6188:	e9 4a 01 00 00       	jmp    62d7 <kprobe_unwind_hotspot+0x62d7>
    618d:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    6194:	64 0a 00 
    6197:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    619c:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    61a3:	69 63 49 
    61a6:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    61ab:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    61b2:	66 6f 72 
    61b5:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    61ba:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    61c1:	69 63 73 
    61c4:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    61c9:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    61d0:	6b 75 70 
    61d3:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    61d8:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    61df:	64 20 74 
    61e2:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    61e7:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    61ea:	31 c9                	xor    ecx,ecx
    61ec:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    61f1:	be 2e 00 00 00       	mov    esi,0x2e
    61f6:	bf 06 00 00 00       	mov    edi,0x6
    61fb:	e9 25 e1 ff ff       	jmp    4325 <kprobe_unwind_hotspot+0x4325>
    6200:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6207:	75 0a 00 
    620a:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    620f:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6216:	74 61 67 
    6219:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    621e:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6225:	6e 74 20 
    6228:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    622d:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6234:	20 20 20 
    6237:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    623c:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6240:	31 c9                	xor    ecx,ecx
    6242:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6247:	be 1d 00 00 00       	mov    esi,0x1d
    624c:	bf 06 00 00 00       	mov    edi,0x6
    6251:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6255:	8d 48 01             	lea    ecx,[rax+0x1]
    6258:	80 f9 02             	cmp    cl,0x2
    625b:	0f 82 d4 ca ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    6261:	e9 ac d2 ff ff       	jmp    3512 <kprobe_unwind_hotspot+0x3512>
    6266:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 626d <kprobe_unwind_hotspot+0x626d>
			6269: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    626d:	83 38 00             	cmp    DWORD PTR [rax],0x0
    6270:	0f 85 dd 11 00 00    	jne    7453 <kprobe_unwind_hotspot+0x7453>
    6276:	41 8b 06             	mov    eax,DWORD PTR [r14]
    6279:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    6280:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    6286:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    628b:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    6292:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 6299 <kprobe_unwind_hotspot+0x6299>
			6295: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    6299:	48 89 e6             	mov    rsi,rsp
    629c:	b8 01 00 00 00       	mov    eax,0x1
    62a1:	ff d0                	call   rax
    62a3:	48 85 c0             	test   rax,rax
    62a6:	0f 84 92 00 00 00    	je     633e <kprobe_unwind_hotspot+0x633e>
    62ac:	48 b9 00 00 00 00 00 	movabs rcx,0xff00000000000000
    62b3:	00 00 ff 
    62b6:	48 23 48 08          	and    rcx,QWORD PTR [rax+0x8]
    62ba:	48 b8 00 00 00 00 00 	movabs rax,0x200000000000000
    62c1:	00 00 02 
    62c4:	48 39 c1             	cmp    rcx,rax
    62c7:	75 75                	jne    633e <kprobe_unwind_hotspot+0x633e>
    62c9:	48 83 84 24 b0 00 00 	add    QWORD PTR [rsp+0xb0],0x28
    62d0:	00 28 
    62d2:	bb 05 00 00 00       	mov    ebx,0x5
    62d7:	31 c0                	xor    eax,eax
    62d9:	b9 05 00 00 00       	mov    ecx,0x5
    62de:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # 62e5 <kprobe_unwind_hotspot+0x62e5>
			62e1: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    62e5:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
    62e8:	0f 85 c6 11 00 00    	jne    74b4 <kprobe_unwind_hotspot+0x74b4>
    62ee:	4c 8b ac 24 b0 00 00 	mov    r13,QWORD PTR [rsp+0xb0]
    62f5:	00 
    62f6:	b2 03                	mov    dl,0x3
    62f8:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    62ff:	4c 89 ea             	mov    rdx,r13
    6302:	4c 89 ac 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],r13
    6309:	00 
    630a:	85 c0                	test   eax,eax
    630c:	0f 85 21 a0 ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    6312:	89 c8                	mov    eax,ecx
    6314:	48 8d 0d 00 00 00 00 	lea    rcx,[rip+0x0]        # 631b <kprobe_unwind_hotspot+0x631b>
			6317: R_X86_64_PC32	.rodata+0xa4
    631b:	48 63 14 81          	movsxd rdx,DWORD PTR [rcx+rax*4]
    631f:	48 01 ca             	add    rdx,rcx
    6322:	b8 01 00 00 00       	mov    eax,0x1
    6327:	ff e2                	jmp    rdx
    6329:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
    6330:	e9 c8 f6 ff ff       	jmp    59fd <kprobe_unwind_hotspot+0x59fd>
    6335:	4d 8b ae 00 0f 00 00 	mov    r13,QWORD PTR [r14+0xf00]
    633c:	eb 37                	jmp    6375 <kprobe_unwind_hotspot+0x6375>
    633e:	c7 84 24 08 01 00 00 	mov    DWORD PTR [rsp+0x108],0x2e
    6345:	2e 00 00 00 
    6349:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 6350 <kprobe_unwind_hotspot+0x6350>
			634c: R_X86_64_REX_GOTPCRELX	metrics-0x4
    6350:	48 8d b4 24 08 01 00 	lea    rsi,[rsp+0x108]
    6357:	00 
    6358:	b8 01 00 00 00       	mov    eax,0x1
    635d:	ff d0                	call   rax
    635f:	48 85 c0             	test   rax,rax
    6362:	0f 84 cb 01 00 00    	je     6533 <kprobe_unwind_hotspot+0x6533>
    6368:	48 ff 00             	inc    QWORD PTR [rax]
    636b:	e9 d3 01 00 00       	jmp    6543 <kprobe_unwind_hotspot+0x6543>
    6370:	4c 8b 6c 24 58       	mov    r13,QWORD PTR [rsp+0x58]
    6375:	48 8b 5c 24 78       	mov    rbx,QWORD PTR [rsp+0x78]
    637a:	48 8b 84 24 88 00 00 	mov    rax,QWORD PTR [rsp+0x88]
    6381:	00 
    6382:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    6389:	00 
    638a:	48 8b 84 24 90 00 00 	mov    rax,QWORD PTR [rsp+0x90]
    6391:	00 
    6392:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    6399:	00 
    639a:	48 8b 84 24 98 00 00 	mov    rax,QWORD PTR [rsp+0x98]
    63a1:	00 
    63a2:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    63a9:	00 
    63aa:	41 0f b6 47 1c       	movzx  eax,BYTE PTR [r15+0x1c]
    63af:	48 01 d8             	add    rax,rbx
    63b2:	48 8d bc 24 08 01 00 	lea    rdi,[rsp+0x108]
    63b9:	00 
    63ba:	b9 08 00 00 00       	mov    ecx,0x8
    63bf:	41 b8 70 00 00 00    	mov    r8d,0x70
    63c5:	41 0f b6 57 1c       	movzx  edx,BYTE PTR [r15+0x1c]
    63ca:	48 01 da             	add    rdx,rbx
    63cd:	be 08 00 00 00       	mov    esi,0x8
    63d2:	41 ff d0             	call   r8
    63d5:	48 85 c0             	test   rax,rax
    63d8:	74 73                	je     644d <kprobe_unwind_hotspot+0x644d>
    63da:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 63e1 <kprobe_unwind_hotspot+0x63e1>
			63dd: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    63e1:	83 38 00             	cmp    DWORD PTR [rax],0x0
    63e4:	0f 84 b0 f5 ff ff    	je     599a <kprobe_unwind_hotspot+0x599a>
    63ea:	48 b8 63 6d 65 74 68 	movabs rax,0xa646f6874656d63
    63f1:	6f 64 0a 
    63f4:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    63f9:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
    6400:	65 72 20 
    6403:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    6408:	48 b8 65 61 64 20 69 	movabs rax,0x65746e6920646165
    640f:	6e 74 65 
    6412:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    6417:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    641e:	6f 20 72 
    6421:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    6426:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    642d:	66 61 69 
    6430:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    6434:	c6 44 24 28 00       	mov    BYTE PTR [rsp+0x28],0x0
    6439:	31 c0                	xor    eax,eax
    643b:	48 89 e1             	mov    rcx,rsp
    643e:	ba 29 00 00 00       	mov    edx,0x29
    6443:	be 06 00 00 00       	mov    esi,0x6
    6448:	e9 4d f5 ff ff       	jmp    599a <kprobe_unwind_hotspot+0x599a>
    644d:	48 8b 94 24 08 01 00 	mov    rdx,QWORD PTR [rsp+0x108]
    6454:	00 
    6455:	41 0f b6 4f 1d       	movzx  ecx,BYTE PTR [r15+0x1d]
    645a:	48 89 d0             	mov    rax,rdx
    645d:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    6464:	00 
    6465:	48 01 d1             	add    rcx,rdx
    6468:	31 c0                	xor    eax,eax
    646a:	49 39 cd             	cmp    r13,rcx
    646d:	ba 00 00 00 00       	mov    edx,0x0
    6472:	48 0f 43 d1          	cmovae rdx,rcx
    6476:	49 29 d5             	sub    r13,rdx
    6479:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 6480 <kprobe_unwind_hotspot+0x6480>
			647c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    6480:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    6483:	0f 85 98 10 00 00    	jne    7521 <kprobe_unwind_hotspot+0x7521>
    6489:	49 81 fd ff ff 00 00 	cmp    r13,0xffff
    6490:	b9 ff ff 00 00       	mov    ecx,0xffff
    6495:	49 0f 42 cd          	cmovb  rcx,r13
    6499:	48 89 8c 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rcx
    64a0:	00 
    64a1:	48 c1 ac 24 c0 00 00 	shr    QWORD PTR [rsp+0xc0],0x3
    64a8:	00 03 
    64aa:	b9 06 00 00 00       	mov    ecx,0x6
    64af:	b2 02                	mov    dl,0x2
    64b1:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    64b8:	48 89 9c 24 18 01 00 	mov    QWORD PTR [rsp+0x118],rbx
    64bf:	00 
    64c0:	85 c0                	test   eax,eax
    64c2:	0f 85 6b 9e ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    64c8:	e9 45 fe ff ff       	jmp    6312 <kprobe_unwind_hotspot+0x6312>
    64cd:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    64d4:	75 0a 00 
    64d7:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    64dc:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    64e3:	74 61 67 
    64e6:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    64eb:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    64f2:	6e 74 20 
    64f5:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    64fa:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6501:	20 20 20 
    6504:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6509:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    650d:	31 c9                	xor    ecx,ecx
    650f:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6514:	be 1d 00 00 00       	mov    esi,0x1d
    6519:	bf 06 00 00 00       	mov    edi,0x6
    651e:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6522:	8d 48 01             	lea    ecx,[rax+0x1]
    6525:	80 f9 02             	cmp    cl,0x2
    6528:	0f 82 93 df ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    652e:	e9 1d f2 ff ff       	jmp    5750 <kprobe_unwind_hotspot+0x5750>
    6533:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 653a <kprobe_unwind_hotspot+0x653a>
			6536: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    653a:	83 38 00             	cmp    DWORD PTR [rax],0x0
    653d:	0f 85 70 10 00 00    	jne    75b3 <kprobe_unwind_hotspot+0x75b3>
    6543:	b8 ea 03 00 00       	mov    eax,0x3ea
    6548:	31 c9                	xor    ecx,ecx
    654a:	e9 a7 fd ff ff       	jmp    62f6 <kprobe_unwind_hotspot+0x62f6>
    654f:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6556:	75 0a 00 
    6559:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    655e:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6565:	74 61 67 
    6568:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    656d:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6574:	6e 74 20 
    6577:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    657c:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6583:	20 20 20 
    6586:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    658b:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    658f:	31 c9                	xor    ecx,ecx
    6591:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6596:	be 1d 00 00 00       	mov    esi,0x1d
    659b:	bf 06 00 00 00       	mov    edi,0x6
    65a0:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    65a4:	8d 48 01             	lea    ecx,[rax+0x1]
    65a7:	80 f9 02             	cmp    cl,0x2
    65aa:	0f 82 85 c7 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    65b0:	e9 a4 cf ff ff       	jmp    3559 <kprobe_unwind_hotspot+0x3559>
    65b5:	c7 04 24 00 00 00 00 	mov    DWORD PTR [rsp],0x0
    65bc:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 65c3 <kprobe_unwind_hotspot+0x65c3>
			65bf: R_X86_64_REX_GOTPCRELX	metrics-0x4
    65c3:	48 89 e6             	mov    rsi,rsp
    65c6:	b8 01 00 00 00       	mov    eax,0x1
    65cb:	ff d0                	call   rax
    65cd:	48 85 c0             	test   rax,rax
    65d0:	0f 84 51 10 00 00    	je     7627 <kprobe_unwind_hotspot+0x7627>
    65d6:	48 ff 00             	inc    QWORD PTR [rax]
    65d9:	e9 c3 10 00 00       	jmp    76a1 <kprobe_unwind_hotspot+0x76a1>
    65de:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    65e5:	75 0a 00 
    65e8:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    65ed:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    65f4:	74 61 67 
    65f7:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    65fc:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6603:	6e 74 20 
    6606:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    660b:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6612:	20 20 20 
    6615:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    661a:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    661e:	31 c9                	xor    ecx,ecx
    6620:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6625:	be 1d 00 00 00       	mov    esi,0x1d
    662a:	bf 06 00 00 00       	mov    edi,0x6
    662f:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6633:	8d 48 01             	lea    ecx,[rax+0x1]
    6636:	80 f9 02             	cmp    cl,0x2
    6639:	0f 82 82 de ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    663f:	e9 53 f1 ff ff       	jmp    5797 <kprobe_unwind_hotspot+0x5797>
    6644:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    664b:	75 0a 00 
    664e:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6653:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    665a:	74 61 67 
    665d:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6662:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6669:	6e 74 20 
    666c:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6671:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6678:	20 20 20 
    667b:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6680:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6684:	31 c9                	xor    ecx,ecx
    6686:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    668b:	be 1d 00 00 00       	mov    esi,0x1d
    6690:	bf 06 00 00 00       	mov    edi,0x6
    6695:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6699:	8d 48 01             	lea    ecx,[rax+0x1]
    669c:	80 f9 02             	cmp    cl,0x2
    669f:	0f 82 90 c6 ff ff    	jb     2d35 <kprobe_unwind_hotspot+0x2d35>
    66a5:	e9 f6 ce ff ff       	jmp    35a0 <kprobe_unwind_hotspot+0x35a0>
    66aa:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    66b1:	75 0a 00 
    66b4:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    66b9:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    66c0:	74 61 67 
    66c3:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    66c8:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    66cf:	6e 74 20 
    66d2:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    66d7:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    66de:	20 20 20 
    66e1:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    66e6:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    66ea:	31 c9                	xor    ecx,ecx
    66ec:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    66f1:	be 1d 00 00 00       	mov    esi,0x1d
    66f6:	bf 06 00 00 00       	mov    edi,0x6
    66fb:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    66ff:	8d 48 01             	lea    ecx,[rax+0x1]
    6702:	80 f9 01             	cmp    cl,0x1
    6705:	0f 87 0d 9b ff ff    	ja     218 <kprobe_unwind_hotspot+0x218>
    670b:	e9 25 c6 ff ff       	jmp    2d35 <kprobe_unwind_hotspot+0x2d35>
    6710:	48 b8 6c 78 2d 25 6c 	movabs rax,0xa786c252d786c
    6717:	78 0a 00 
    671a:	48 89 44 24 4f       	mov    QWORD PTR [rsp+0x4f],rax
    671f:	48 b8 20 63 6f 64 65 	movabs rax,0x6c252065646f6320
    6726:	20 25 6c 
    6729:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    672e:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    6735:	20 2d 3e 
    6738:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    673d:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    6744:	00 
    6745:	48 8b 94 24 e0 00 00 	mov    rdx,QWORD PTR [rsp+0xe0]
    674c:	00 
    674d:	31 f6                	xor    esi,esi
    674f:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    6754:	41 b8 17 00 00 00    	mov    r8d,0x17
    675a:	41 b9 06 00 00 00    	mov    r9d,0x6
    6760:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 6767 <kprobe_unwind_hotspot+0x6767>
			6763: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    6767:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    676a:	0f 84 cc de ff ff    	je     463c <kprobe_unwind_hotspot+0x463c>
    6770:	48 b9 5f 74 79 70 65 	movabs rcx,0x783020657079745f
    6777:	20 30 78 
    677a:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    677f:	48 b9 75 2c 20 66 72 	movabs rcx,0x656d617266202c75
    6786:	61 6d 65 
    6789:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    678e:	48 b9 65 5f 73 69 7a 	movabs rcx,0x2520657a69735f65
    6795:	65 20 25 
    6798:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    679d:	48 b9 25 75 2c 20 66 	movabs rcx,0x6d617266202c7525
    67a4:	72 61 6d 
    67a7:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    67ac:	48 b9 6f 6d 70 6c 65 	movabs rcx,0x206574656c706d6f
    67b3:	74 65 20 
    67b6:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    67bb:	48 b9 20 66 72 61 6d 	movabs rcx,0x635f656d61726620
    67c2:	65 5f 63 
    67c5:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    67ca:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    67cf:	c7 44 24 78 25 78 0a 	mov    DWORD PTR [rsp+0x78],0xa7825
    67d6:	00 
    67d7:	0f b7 84 24 00 01 00 	movzx  eax,WORD PTR [rsp+0x100]
    67de:	00 
    67df:	8b 8c 24 f0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xf0]
    67e6:	8b 94 24 f8 00 00 00 	mov    edx,DWORD PTR [rsp+0xf8]
    67ed:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    67f2:	bf 3c 00 00 00       	mov    edi,0x3c
    67f7:	41 b8 06 00 00 00    	mov    r8d,0x6
    67fd:	e9 3a de ff ff       	jmp    463c <kprobe_unwind_hotspot+0x463c>
    6802:	48 b8 66 61 69 6c 65 	movabs rax,0xa64656c696166
    6809:	64 0a 00 
    680c:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    6811:	48 b8 65 63 6f 76 65 	movabs rax,0x20797265766f6365
    6818:	72 79 20 
    681b:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    6820:	48 b8 6d 65 2c 20 70 	movabs rax,0x72206370202c656d
    6827:	63 20 72 
    682a:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    682f:	48 b8 69 7a 65 64 20 	movabs rax,0x6172662064657a69
    6836:	66 72 61 
    6839:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    683e:	48 b8 20 64 65 6f 70 	movabs rax,0x6d6974706f656420
    6845:	74 69 6d 
    6848:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    684d:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    6854:	20 2d 3e 
    6857:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    685c:	31 c0                	xor    eax,eax
    685e:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    6863:	ba 30 00 00 00       	mov    edx,0x30
    6868:	be 06 00 00 00       	mov    esi,0x6
    686d:	e9 9c ea ff ff       	jmp    530e <kprobe_unwind_hotspot+0x530e>
    6872:	48 b8 76 74 61 62 6c 	movabs rax,0xa656c62617476
    6879:	65 0a 00 
    687c:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6881:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    6888:	6e 64 20 
    688b:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6890:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    6897:	20 2d 3e 
    689a:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    689f:	31 c0                	xor    eax,eax
    68a1:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    68a6:	ba 18 00 00 00       	mov    edx,0x18
    68ab:	be 06 00 00 00       	mov    esi,0x6
    68b0:	e9 8d ec ff ff       	jmp    5542 <kprobe_unwind_hotspot+0x5542>
    68b5:	48 b8 6c 62 61 63 6b 	movabs rax,0x6170206b6361626c
    68bc:	20 70 61 
    68bf:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    68c4:	48 b8 73 74 75 62 20 	movabs rax,0x6c61662062757473
    68cb:	66 61 6c 
    68ce:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    68d3:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    68da:	6e 64 20 
    68dd:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    68e2:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    68e9:	20 2d 3e 
    68ec:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    68f1:	c7 44 24 60 74 68 0a 	mov    DWORD PTR [rsp+0x60],0xa6874
    68f8:	00 
    68f9:	31 c0                	xor    eax,eax
    68fb:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    6900:	ba 24 00 00 00       	mov    edx,0x24
    6905:	be 06 00 00 00       	mov    esi,0x6
    690a:	e9 58 ec ff ff       	jmp    5567 <kprobe_unwind_hotspot+0x5567>
    690f:	48 b9 65 20 25 6c 64 	movabs rcx,0xa29646c252065
    6916:	29 0a 00 
    6919:	48 89 4c 24 67       	mov    QWORD PTR [rsp+0x67],rcx
    691e:	48 b9 61 6d 65 20 73 	movabs rcx,0x657a697320656d61
    6925:	69 7a 65 
    6928:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    692d:	48 b9 6e 74 65 72 20 	movabs rcx,0x726628207265746e
    6934:	28 66 72 
    6937:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    693c:	48 b9 72 61 6d 65 20 	movabs rcx,0x696f7020656d6172
    6943:	70 6f 69 
    6946:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    694b:	48 b9 20 75 73 69 6e 	movabs rcx,0x6620676e69737520
    6952:	67 20 66 
    6955:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    695a:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    6961:	20 2d 3e 
    6964:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    6969:	31 c9                	xor    ecx,ecx
    696b:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6970:	be 2f 00 00 00       	mov    esi,0x2f
    6975:	bf 06 00 00 00       	mov    edi,0x6
    697a:	48 8b 8c 24 b8 00 00 	mov    rcx,QWORD PTR [rsp+0xb8]
    6981:	00 
    6982:	e9 5e f0 ff ff       	jmp    59e5 <kprobe_unwind_hotspot+0x59e5>
    6987:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    698e:	75 0a 00 
    6991:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6996:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    699d:	74 61 67 
    69a0:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    69a5:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    69ac:	6e 74 20 
    69af:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    69b4:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    69bb:	20 20 20 
    69be:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    69c3:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    69c7:	31 c9                	xor    ecx,ecx
    69c9:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    69ce:	be 1d 00 00 00       	mov    esi,0x1d
    69d3:	bf 06 00 00 00       	mov    edi,0x6
    69d8:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    69dc:	8d 48 01             	lea    ecx,[rax+0x1]
    69df:	80 f9 02             	cmp    cl,0x2
    69e2:	0f 82 d9 da ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    69e8:	e9 f1 ed ff ff       	jmp    57de <kprobe_unwind_hotspot+0x57de>
    69ed:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    69f4:	75 0a 00 
    69f7:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    69fc:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6a03:	74 61 67 
    6a06:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6a0b:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6a12:	6e 74 20 
    6a15:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6a1a:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6a21:	20 20 20 
    6a24:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6a29:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6a2d:	31 c9                	xor    ecx,ecx
    6a2f:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6a34:	be 1d 00 00 00       	mov    esi,0x1d
    6a39:	bf 06 00 00 00       	mov    edi,0x6
    6a3e:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6a42:	8d 48 01             	lea    ecx,[rax+0x1]
    6a45:	80 f9 02             	cmp    cl,0x2
    6a48:	0f 82 73 da ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    6a4e:	e9 d2 ed ff ff       	jmp    5825 <kprobe_unwind_hotspot+0x5825>
    6a53:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6a5a:	75 0a 00 
    6a5d:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6a62:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6a69:	74 61 67 
    6a6c:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6a71:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6a78:	6e 74 20 
    6a7b:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6a80:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6a87:	20 20 20 
    6a8a:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6a8f:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6a93:	31 c9                	xor    ecx,ecx
    6a95:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6a9a:	be 1d 00 00 00       	mov    esi,0x1d
    6a9f:	bf 06 00 00 00       	mov    edi,0x6
    6aa4:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6aa8:	8d 48 01             	lea    ecx,[rax+0x1]
    6aab:	80 f9 02             	cmp    cl,0x2
    6aae:	0f 82 0d da ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    6ab4:	e9 b3 ed ff ff       	jmp    586c <kprobe_unwind_hotspot+0x586c>
    6ab9:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6ac0:	75 0a 00 
    6ac3:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6ac8:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6acf:	74 61 67 
    6ad2:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6ad7:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6ade:	6e 74 20 
    6ae1:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6ae6:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6aed:	20 20 20 
    6af0:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6af5:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6af9:	31 c9                	xor    ecx,ecx
    6afb:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6b00:	be 1d 00 00 00       	mov    esi,0x1d
    6b05:	bf 06 00 00 00       	mov    edi,0x6
    6b0a:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6b0e:	8d 48 01             	lea    ecx,[rax+0x1]
    6b11:	80 f9 02             	cmp    cl,0x2
    6b14:	0f 82 a7 d9 ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    6b1a:	0f b6 c0             	movzx  eax,al
    6b1d:	48 29 c3             	sub    rbx,rax
    6b20:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    6b24:	48 89 e7             	mov    rdi,rsp
    6b27:	b8 01 00 00 00       	mov    eax,0x1
    6b2c:	b9 70 00 00 00       	mov    ecx,0x70
    6b31:	be 01 00 00 00       	mov    esi,0x1
    6b36:	ff d1                	call   rcx
    6b38:	48 85 c0             	test   rax,rax
    6b3b:	0f 85 d7 96 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    6b41:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 6b48 <kprobe_unwind_hotspot+0x6b48>
			6b44: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    6b48:	83 38 00             	cmp    DWORD PTR [rax],0x0
    6b4b:	74 51                	je     6b9e <kprobe_unwind_hotspot+0x6b9e>
    6b4d:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6b54:	75 0a 00 
    6b57:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6b5c:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6b63:	74 61 67 
    6b66:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6b6b:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6b72:	6e 74 20 
    6b75:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6b7a:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6b81:	20 20 20 
    6b84:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6b89:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6b8d:	31 c9                	xor    ecx,ecx
    6b8f:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6b94:	be 1d 00 00 00       	mov    esi,0x1d
    6b99:	bf 06 00 00 00       	mov    edi,0x6
    6b9e:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6ba2:	8d 48 01             	lea    ecx,[rax+0x1]
    6ba5:	80 f9 02             	cmp    cl,0x2
    6ba8:	0f 82 13 d9 ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    6bae:	0f b6 c0             	movzx  eax,al
    6bb1:	48 29 c3             	sub    rbx,rax
    6bb4:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    6bb8:	48 89 e7             	mov    rdi,rsp
    6bbb:	b8 01 00 00 00       	mov    eax,0x1
    6bc0:	b9 70 00 00 00       	mov    ecx,0x70
    6bc5:	be 01 00 00 00       	mov    esi,0x1
    6bca:	ff d1                	call   rcx
    6bcc:	48 85 c0             	test   rax,rax
    6bcf:	0f 85 43 96 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    6bd5:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 6bdc <kprobe_unwind_hotspot+0x6bdc>
			6bd8: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    6bdc:	83 38 00             	cmp    DWORD PTR [rax],0x0
    6bdf:	74 51                	je     6c32 <kprobe_unwind_hotspot+0x6c32>
    6be1:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6be8:	75 0a 00 
    6beb:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6bf0:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6bf7:	74 61 67 
    6bfa:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6bff:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6c06:	6e 74 20 
    6c09:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6c0e:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6c15:	20 20 20 
    6c18:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6c1d:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6c21:	31 c9                	xor    ecx,ecx
    6c23:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6c28:	be 1d 00 00 00       	mov    esi,0x1d
    6c2d:	bf 06 00 00 00       	mov    edi,0x6
    6c32:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6c36:	8d 48 01             	lea    ecx,[rax+0x1]
    6c39:	80 f9 02             	cmp    cl,0x2
    6c3c:	0f 82 7f d8 ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    6c42:	0f b6 c0             	movzx  eax,al
    6c45:	48 29 c3             	sub    rbx,rax
    6c48:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    6c4c:	48 89 e7             	mov    rdi,rsp
    6c4f:	b8 01 00 00 00       	mov    eax,0x1
    6c54:	b9 70 00 00 00       	mov    ecx,0x70
    6c59:	be 01 00 00 00       	mov    esi,0x1
    6c5e:	ff d1                	call   rcx
    6c60:	48 85 c0             	test   rax,rax
    6c63:	0f 85 af 95 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    6c69:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 6c70 <kprobe_unwind_hotspot+0x6c70>
			6c6c: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    6c70:	83 38 00             	cmp    DWORD PTR [rax],0x0
    6c73:	74 51                	je     6cc6 <kprobe_unwind_hotspot+0x6cc6>
    6c75:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6c7c:	75 0a 00 
    6c7f:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6c84:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6c8b:	74 61 67 
    6c8e:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6c93:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6c9a:	6e 74 20 
    6c9d:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6ca2:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6ca9:	20 20 20 
    6cac:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6cb1:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6cb5:	31 c9                	xor    ecx,ecx
    6cb7:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6cbc:	be 1d 00 00 00       	mov    esi,0x1d
    6cc1:	bf 06 00 00 00       	mov    edi,0x6
    6cc6:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6cca:	8d 48 01             	lea    ecx,[rax+0x1]
    6ccd:	80 f9 02             	cmp    cl,0x2
    6cd0:	0f 82 eb d7 ff ff    	jb     44c1 <kprobe_unwind_hotspot+0x44c1>
    6cd6:	0f b6 c0             	movzx  eax,al
    6cd9:	48 29 c3             	sub    rbx,rax
    6cdc:	49 01 dd             	add    r13,rbx
    6cdf:	48 89 e7             	mov    rdi,rsp
    6ce2:	b8 01 00 00 00       	mov    eax,0x1
    6ce7:	b9 70 00 00 00       	mov    ecx,0x70
    6cec:	be 01 00 00 00       	mov    esi,0x1
    6cf1:	4c 89 ea             	mov    rdx,r13
    6cf4:	ff d1                	call   rcx
    6cf6:	48 85 c0             	test   rax,rax
    6cf9:	0f 85 19 95 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    6cff:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 6d06 <kprobe_unwind_hotspot+0x6d06>
			6d02: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    6d06:	83 38 00             	cmp    DWORD PTR [rax],0x0
    6d09:	74 51                	je     6d5c <kprobe_unwind_hotspot+0x6d5c>
    6d0b:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    6d12:	75 0a 00 
    6d15:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    6d1a:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    6d21:	74 61 67 
    6d24:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6d29:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    6d30:	6e 74 20 
    6d33:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6d38:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    6d3f:	20 20 20 
    6d42:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6d47:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6d4b:	31 c9                	xor    ecx,ecx
    6d4d:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6d52:	be 1d 00 00 00       	mov    esi,0x1d
    6d57:	bf 06 00 00 00       	mov    edi,0x6
    6d5c:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    6d60:	8d 48 01             	lea    ecx,[rax+0x1]
    6d63:	80 f9 01             	cmp    cl,0x1
    6d66:	0f 87 ac 94 ff ff    	ja     218 <kprobe_unwind_hotspot+0x218>
    6d6c:	e9 50 d7 ff ff       	jmp    44c1 <kprobe_unwind_hotspot+0x44c1>
    6d71:	48 b8 20 66 72 61 6d 	movabs rax,0xa656d61726620
    6d78:	65 0a 00 
    6d7b:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    6d80:	48 b8 70 72 65 74 65 	movabs rax,0x6620726574657270
    6d87:	72 20 66 
    6d8a:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    6d8f:	48 b8 62 65 20 69 6e 	movabs rax,0x7265746e69206562
    6d96:	74 65 72 
    6d99:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    6d9e:	48 b8 61 77 61 79 20 	movabs rax,0x206f742079617761
    6da5:	74 6f 20 
    6da8:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    6dad:	48 b8 74 6f 6f 20 66 	movabs rax,0x20726166206f6f74
    6db4:	61 72 20 
    6db7:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    6dbc:	48 b8 6a 76 6d 3a 20 	movabs rax,0x207066203a6d766a
    6dc3:	66 70 20 
    6dc6:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    6dca:	31 c0                	xor    eax,eax
    6dcc:	48 89 e1             	mov    rcx,rsp
    6dcf:	ba 2e 00 00 00       	mov    edx,0x2e
    6dd4:	be 06 00 00 00       	mov    esi,0x6
    6dd9:	e9 bc eb ff ff       	jmp    599a <kprobe_unwind_hotspot+0x599a>
    6dde:	48 b8 66 70 2b 70 63 	movabs rax,0xa2963702b7066
    6de5:	29 0a 00 
    6de8:	48 89 44 24 65       	mov    QWORD PTR [rsp+0x65],rax
    6ded:	48 b8 61 6d 65 20 28 	movabs rax,0x2b70662820656d61
    6df4:	66 70 2b 
    6df7:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    6dfc:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
    6e03:	20 66 72 
    6e06:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    6e0b:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
    6e12:	63 6f 6d 
    6e15:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6e1a:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    6e21:	6e 64 69 
    6e24:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6e29:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    6e30:	20 2d 3e 
    6e33:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6e38:	31 c0                	xor    eax,eax
    6e3a:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    6e3f:	ba 2d 00 00 00       	mov    edx,0x2d
    6e44:	be 06 00 00 00       	mov    esi,0x6
    6e49:	e9 8f eb ff ff       	jmp    59dd <kprobe_unwind_hotspot+0x59dd>
    6e4e:	48 b8 76 65 72 20 66 	movabs rax,0xa706620726576
    6e55:	70 0a 00 
    6e58:	48 89 44 24 4d       	mov    QWORD PTR [rsp+0x4d],rax
    6e5d:	48 b8 20 72 65 63 6f 	movabs rax,0x7265766f63657220
    6e64:	76 65 72 
    6e67:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6e6c:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    6e73:	20 2d 3e 
    6e76:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6e7b:	31 c0                	xor    eax,eax
    6e7d:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    6e82:	ba 15 00 00 00       	mov    edx,0x15
    6e87:	be 06 00 00 00       	mov    esi,0x6
    6e8c:	e9 bd eb ff ff       	jmp    5a4e <kprobe_unwind_hotspot+0x5a4e>
    6e91:	48 b8 78 2c 20 66 70 	movabs rax,0x25203a7066202c78
    6e98:	3a 20 25 
    6e9b:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    6ea0:	48 b8 2c 20 73 70 3a 	movabs rax,0x6c25203a7073202c
    6ea7:	20 25 6c 
    6eaa:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6eaf:	48 b8 20 70 63 3a 20 	movabs rax,0x786c25203a637020
    6eb6:	25 6c 78 
    6eb9:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6ebe:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    6ec5:	20 2d 3e 
    6ec8:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6ecd:	c7 44 24 60 6c 78 0a 	mov    DWORD PTR [rsp+0x60],0xa786c
    6ed4:	00 
    6ed5:	48 8d 44 24 40       	lea    rax,[rsp+0x40]
    6eda:	b9 24 00 00 00       	mov    ecx,0x24
    6edf:	ba 06 00 00 00       	mov    edx,0x6
    6ee4:	48 8b b4 24 b8 00 00 	mov    rsi,QWORD PTR [rsp+0xb8]
    6eeb:	00 
    6eec:	48 8b bc 24 b0 00 00 	mov    rdi,QWORD PTR [rsp+0xb0]
    6ef3:	00 
    6ef4:	4c 8b 84 24 a8 00 00 	mov    r8,QWORD PTR [rsp+0xa8]
    6efb:	00 
    6efc:	e9 f5 eb ff ff       	jmp    5af6 <kprobe_unwind_hotspot+0x5af6>
    6f01:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    6f08:	64 0a 00 
    6f0b:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    6f10:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    6f17:	69 63 49 
    6f1a:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    6f1f:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    6f26:	66 6f 72 
    6f29:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    6f2e:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    6f35:	69 63 73 
    6f38:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6f3d:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    6f44:	6b 75 70 
    6f47:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6f4c:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    6f53:	64 20 74 
    6f56:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6f5b:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    6f5e:	31 c9                	xor    ecx,ecx
    6f60:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6f65:	be 2e 00 00 00       	mov    esi,0x2e
    6f6a:	bf 06 00 00 00       	mov    edi,0x6
    6f6f:	e9 d7 eb ff ff       	jmp    5b4b <kprobe_unwind_hotspot+0x5b4b>
    6f74:	48 b8 25 64 20 3d 3d 	movabs rax,0xa3d3d3d3d206425
    6f7b:	3d 3d 0a 
    6f7e:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    6f83:	48 b8 3a 20 66 72 61 	movabs rax,0x20656d617266203a
    6f8a:	6d 65 20 
    6f8d:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    6f92:	48 b8 75 6e 77 69 6e 	movabs rax,0x7265646e69776e75
    6f99:	64 65 72 
    6f9c:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    6fa1:	48 b8 74 20 66 72 61 	movabs rax,0x20656d6172662074
    6fa8:	6d 65 20 
    6fab:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    6fb0:	48 b8 6f 6c 76 65 20 	movabs rax,0x78656e2065766c6f
    6fb7:	6e 65 78 
    6fba:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    6fbf:	48 b8 3d 3d 3d 3d 20 	movabs rax,0x736552203d3d3d3d
    6fc6:	52 65 73 
    6fc9:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    6fce:	c6 44 24 70 00       	mov    BYTE PTR [rsp+0x70],0x0
    6fd3:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    6fda:	31 c9                	xor    ecx,ecx
    6fdc:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    6fe1:	be 31 00 00 00       	mov    esi,0x31
    6fe6:	bf 06 00 00 00       	mov    edi,0x6
    6feb:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    6ff2:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    6ff9:	ff ff 00 
    6ffc:	49 39 c5             	cmp    r13,rax
    6fff:	0f 87 d5 a6 ff ff    	ja     16da <kprobe_unwind_hotspot+0x16da>
    7005:	e9 89 eb ff ff       	jmp    5b93 <kprobe_unwind_hotspot+0x5b93>
    700a:	48 b9 6e 64 65 72 20 	movabs rcx,0x296425207265646e
    7011:	25 64 29 
    7014:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    7019:	48 b9 6c 78 20 28 75 	movabs rcx,0x69776e752820786c
    7020:	6e 77 69 
    7023:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    7028:	48 b9 6c 78 20 69 73 	movabs rcx,0x6c2520736920786c
    702f:	20 25 6c 
    7032:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    7037:	48 b9 66 6f 72 20 50 	movabs rcx,0x2520435020726f66
    703e:	43 20 25 
    7041:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    7046:	48 b9 74 69 6f 6e 20 	movabs rcx,0x206469206e6f6974
    704d:	69 64 20 
    7050:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    7055:	48 b9 54 65 78 74 20 	movabs rcx,0x6365732074786554
    705c:	73 65 63 
    705f:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    7064:	66 c7 44 24 70 0a 00 	mov    WORD PTR [rsp+0x70],0xa
    706b:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7070:	be 32 00 00 00       	mov    esi,0x32
    7075:	bf 06 00 00 00       	mov    edi,0x6
    707a:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7081 <kprobe_unwind_hotspot+0x7081>
			707d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7081:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7084:	0f 84 9c eb ff ff    	je     5c26 <kprobe_unwind_hotspot+0x5c26>
    708a:	48 b8 73 20 25 6c 6c 	movabs rax,0xa786c6c252073
    7091:	78 0a 00 
    7094:	48 89 44 24 67       	mov    QWORD PTR [rsp+0x67],rax
    7099:	48 b8 66 66 73 65 74 	movabs rax,0x7369207465736666
    70a0:	20 69 73 
    70a3:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    70a8:	48 b8 78 2c 20 61 6e 	movabs rax,0x6f20646e61202c78
    70af:	64 20 6f 
    70b2:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    70b7:	48 b8 73 20 69 73 20 	movabs rax,0x6c6c252073692073
    70be:	25 6c 6c 
    70c1:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    70c6:	48 b8 74 69 6f 6e 20 	movabs rax,0x616962206e6f6974
    70cd:	62 69 61 
    70d0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    70d5:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    70da:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
    70e1:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
    70e8:	31 d2                	xor    edx,edx
    70ea:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    70ef:	bf 2f 00 00 00       	mov    edi,0x2f
    70f4:	41 b8 06 00 00 00    	mov    r8d,0x6
    70fa:	e9 27 eb ff ff       	jmp    5c26 <kprobe_unwind_hotspot+0x5c26>
    70ff:	48 b8 74 63 68 20 25 	movabs rax,0xa642520686374
    7106:	64 0a 00 
    7109:	48 89 44 24 56       	mov    QWORD PTR [rsp+0x56],rax
    710e:	48 b8 65 74 73 20 6d 	movabs rax,0x6374616d20737465
    7115:	61 74 63 
    7118:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    711d:	48 b8 74 65 72 5f 6f 	movabs rax,0x7366666f5f726574
    7124:	66 66 73 
    7127:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    712c:	48 b8 69 6e 74 65 72 	movabs rax,0x6572707265746e69
    7133:	70 72 65 
    7136:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    713b:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    7142:	00 
    7143:	0f b7 40 20          	movzx  eax,WORD PTR [rax+0x20]
    7147:	31 c9                	xor    ecx,ecx
    7149:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    714e:	be 1e 00 00 00       	mov    esi,0x1e
    7153:	bf 06 00 00 00       	mov    edi,0x6
    7158:	e9 63 eb ff ff       	jmp    5cc0 <kprobe_unwind_hotspot+0x5cc0>
    715d:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    7164:	25 6c 78 
    7167:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    716c:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    7173:	69 64 61 
    7176:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    717b:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    7182:	20 70 63 
    7185:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    718a:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7191:	20 20 20 
    7194:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    7198:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    719f:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
    71a4:	31 c9                	xor    ecx,ecx
    71a6:	48 89 e2             	mov    rdx,rsp
    71a9:	be 22 00 00 00       	mov    esi,0x22
    71ae:	bf 06 00 00 00       	mov    edi,0x6
    71b3:	e9 b4 eb ff ff       	jmp    5d6c <kprobe_unwind_hotspot+0x5d6c>
    71b8:	48 b9 73 70 2b 25 64 	movabs rcx,0xa2964252b7073
    71bf:	29 0a 00 
    71c2:	48 89 4c 24 78       	mov    QWORD PTR [rsp+0x78],rcx
    71c7:	48 b9 78 20 28 66 72 	movabs rcx,0x206d6f7266282078
    71ce:	6f 6d 20 
    71d1:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    71d6:	48 b9 20 61 73 20 30 	movabs rcx,0x6c25783020736120
    71dd:	78 25 6c 
    71e0:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    71e5:	48 b9 65 63 6f 76 65 	movabs rcx,0x64657265766f6365
    71ec:	72 65 64 
    71ef:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    71f4:	48 b9 6d 65 2c 20 70 	movabs rcx,0x72206370202c656d
    71fb:	63 20 72 
    71fe:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    7203:	48 b9 69 7a 65 64 20 	movabs rcx,0x6172662064657a69
    720a:	66 72 61 
    720d:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    7212:	48 b9 20 64 65 6f 70 	movabs rcx,0x6d6974706f656420
    7219:	74 69 6d 
    721c:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    7221:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    7228:	20 2d 3e 
    722b:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    7230:	48 63 8c 24 f4 00 00 	movsxd rcx,DWORD PTR [rsp+0xf4]
    7237:	00 
    7238:	31 d2                	xor    edx,edx
    723a:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    723f:	bf 40 00 00 00       	mov    edi,0x40
    7244:	41 b8 06 00 00 00    	mov    r8d,0x6
    724a:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    724e:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    7255:	00 
    7256:	e9 13 ec ff ff       	jmp    5e6e <kprobe_unwind_hotspot+0x5e6e>
    725b:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    7262:	64 0a 00 
    7265:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    726a:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    7271:	69 63 49 
    7274:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    7279:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    7280:	66 6f 72 
    7283:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    7288:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    728f:	69 63 73 
    7292:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    7297:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    729e:	6b 75 70 
    72a1:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    72a6:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    72ad:	64 20 74 
    72b0:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    72b4:	8b 84 24 14 01 00 00 	mov    eax,DWORD PTR [rsp+0x114]
    72bb:	31 c9                	xor    ecx,ecx
    72bd:	48 89 e2             	mov    rdx,rsp
    72c0:	be 2e 00 00 00       	mov    esi,0x2e
    72c5:	bf 06 00 00 00       	mov    edi,0x6
    72ca:	e9 c8 eb ff ff       	jmp    5e97 <kprobe_unwind_hotspot+0x5e97>
    72cf:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    72d6:	25 6c 78 
    72d9:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    72de:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    72e5:	69 64 61 
    72e8:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    72ed:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    72f4:	20 70 63 
    72f7:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    72fc:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7303:	20 20 20 
    7306:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    730a:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    7311:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    7316:	31 c9                	xor    ecx,ecx
    7318:	48 89 e2             	mov    rdx,rsp
    731b:	be 22 00 00 00       	mov    esi,0x22
    7320:	bf 01 00 00 00       	mov    edi,0x1
    7325:	41 b8 06 00 00 00    	mov    r8d,0x6
    732b:	e9 98 eb ff ff       	jmp    5ec8 <kprobe_unwind_hotspot+0x5ec8>
    7330:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    7337:	25 6c 78 
    733a:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    733f:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    7346:	69 64 61 
    7349:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    734e:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    7355:	20 70 63 
    7358:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    735d:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7364:	20 20 20 
    7367:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    736b:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    7372:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    7377:	31 c9                	xor    ecx,ecx
    7379:	48 89 e2             	mov    rdx,rsp
    737c:	be 22 00 00 00       	mov    esi,0x22
    7381:	bf 02 00 00 00       	mov    edi,0x2
    7386:	41 b8 06 00 00 00    	mov    r8d,0x6
    738c:	e9 ac eb ff ff       	jmp    5f3d <kprobe_unwind_hotspot+0x5f3d>
    7391:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    7398:	25 6c 78 
    739b:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    73a0:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    73a7:	69 64 61 
    73aa:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    73af:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    73b6:	20 70 63 
    73b9:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    73be:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    73c5:	20 20 20 
    73c8:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    73cc:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    73d3:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    73d8:	31 c9                	xor    ecx,ecx
    73da:	48 89 e2             	mov    rdx,rsp
    73dd:	be 22 00 00 00       	mov    esi,0x22
    73e2:	bf 03 00 00 00       	mov    edi,0x3
    73e7:	41 b8 06 00 00 00    	mov    r8d,0x6
    73ed:	e9 b9 ec ff ff       	jmp    60ab <kprobe_unwind_hotspot+0x60ab>
    73f2:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    73f9:	25 6c 78 
    73fc:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    7401:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    7408:	69 64 61 
    740b:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    7410:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    7417:	20 70 63 
    741a:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    741f:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7426:	20 20 20 
    7429:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    742d:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    7434:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    7439:	31 c9                	xor    ecx,ecx
    743b:	48 89 e2             	mov    rdx,rsp
    743e:	be 22 00 00 00       	mov    esi,0x22
    7443:	bf 04 00 00 00       	mov    edi,0x4
    7448:	41 b8 06 00 00 00    	mov    r8d,0x6
    744e:	e9 cd ec ff ff       	jmp    6120 <kprobe_unwind_hotspot+0x6120>
    7453:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    745a:	25 6c 78 
    745d:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    7462:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    7469:	69 64 61 
    746c:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    7471:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    7478:	20 70 63 
    747b:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    7480:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7487:	20 20 20 
    748a:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    748e:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    7495:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    749a:	31 c9                	xor    ecx,ecx
    749c:	48 89 e2             	mov    rdx,rsp
    749f:	be 22 00 00 00       	mov    esi,0x22
    74a4:	bf 05 00 00 00       	mov    edi,0x5
    74a9:	41 b8 06 00 00 00    	mov    r8d,0x6
    74af:	e9 c2 ed ff ff       	jmp    6276 <kprobe_unwind_hotspot+0x6276>
    74b4:	48 b8 20 77 6f 72 64 	movabs rax,0xa7364726f7720
    74bb:	73 0a 00 
    74be:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    74c3:	48 b8 65 20 2b 20 25 	movabs rax,0x77206425202b2065
    74ca:	64 20 77 
    74cd:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    74d2:	48 b8 65 74 65 20 66 	movabs rax,0x6d61726620657465
    74d9:	72 61 6d 
    74dc:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    74e1:	48 b8 6e 67 20 63 6f 	movabs rax,0x6c706d6f6320676e
    74e8:	6d 70 6c 
    74eb:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    74f0:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    74f7:	6e 64 69 
    74fa:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    74ff:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    7506:	20 2d 3e 
    7509:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    750d:	31 c0                	xor    eax,eax
    750f:	48 89 e2             	mov    rdx,rsp
    7512:	be 2e 00 00 00       	mov    esi,0x2e
    7517:	bf 06 00 00 00       	mov    edi,0x6
    751c:	e9 cd ed ff ff       	jmp    62ee <kprobe_unwind_hotspot+0x62ee>
    7521:	48 b9 20 3d 20 25 6c 	movabs rcx,0xa786c25203d20
    7528:	78 0a 00 
    752b:	48 89 4c 24 2d       	mov    QWORD PTR [rsp+0x2d],rcx
    7530:	48 b9 2c 20 62 63 70 	movabs rcx,0x203d20706362202c
    7537:	20 3d 20 
    753a:	48 89 4c 24 28       	mov    QWORD PTR [rsp+0x28],rcx
    753f:	48 b9 20 3d 20 30 78 	movabs rcx,0x786c257830203d20
    7546:	25 6c 78 
    7549:	48 89 4c 24 20       	mov    QWORD PTR [rsp+0x20],rcx
    754e:	48 b9 20 63 6d 65 74 	movabs rcx,0x646f6874656d6320
    7555:	68 6f 64 
    7558:	48 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],rcx
    755d:	48 b9 3d 20 30 78 25 	movabs rcx,0x2c786c257830203d
    7564:	6c 78 2c 
    7567:	48 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],rcx
    756c:	48 b9 20 6d 65 74 68 	movabs rcx,0x20646f6874656d20
    7573:	6f 64 20 
    7576:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
    757b:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    7582:	20 2d 3e 
    7585:	48 89 0c 24          	mov    QWORD PTR [rsp],rcx
    7589:	48 89 e1             	mov    rcx,rsp
    758c:	ba 35 00 00 00       	mov    edx,0x35
    7591:	be 06 00 00 00       	mov    esi,0x6
    7596:	48 8b bc 24 c0 00 00 	mov    rdi,QWORD PTR [rsp+0xc0]
    759d:	00 
    759e:	48 8b 8c 24 08 01 00 	mov    rcx,QWORD PTR [rsp+0x108]
    75a5:	00 
    75a6:	48 89 8c 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rcx
    75ad:	00 
    75ae:	e9 d6 ee ff ff       	jmp    6489 <kprobe_unwind_hotspot+0x6489>
    75b3:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    75ba:	64 0a 00 
    75bd:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    75c2:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    75c9:	69 63 49 
    75cc:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    75d1:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    75d8:	66 6f 72 
    75db:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    75e0:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    75e7:	69 63 73 
    75ea:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    75ef:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    75f6:	6b 75 70 
    75f9:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    75fe:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    7605:	64 20 74 
    7608:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    760c:	8b 84 24 08 01 00 00 	mov    eax,DWORD PTR [rsp+0x108]
    7613:	31 c9                	xor    ecx,ecx
    7615:	48 89 e2             	mov    rdx,rsp
    7618:	be 2e 00 00 00       	mov    esi,0x2e
    761d:	bf 06 00 00 00       	mov    edi,0x6
    7622:	e9 1c ef ff ff       	jmp    6543 <kprobe_unwind_hotspot+0x6543>
    7627:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 762e <kprobe_unwind_hotspot+0x762e>
			762a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    762e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7631:	74 6e                	je     76a1 <kprobe_unwind_hotspot+0x76a1>
    7633:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    763a:	64 0a 00 
    763d:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    7642:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    7649:	69 63 49 
    764c:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    7651:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    7658:	66 6f 72 
    765b:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    7660:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    7667:	69 63 73 
    766a:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    766f:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    7676:	6b 75 70 
    7679:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    767e:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    7685:	64 20 74 
    7688:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    768d:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    7690:	31 c9                	xor    ecx,ecx
    7692:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7697:	be 2e 00 00 00       	mov    esi,0x2e
    769c:	bf 06 00 00 00       	mov    edi,0x6
    76a1:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    76a8:	00 
    76a9:	0f b7 58 20          	movzx  ebx,WORD PTR [rax+0x20]
    76ad:	83 fb 02             	cmp    ebx,0x2
    76b0:	0f 85 81 8c ff ff    	jne    337 <kprobe_unwind_hotspot+0x337>
    76b6:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x29
    76bd:	29 00 00 00 
    76c1:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 76c8 <kprobe_unwind_hotspot+0x76c8>
			76c4: R_X86_64_REX_GOTPCRELX	metrics-0x4
    76c8:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    76cf:	00 
    76d0:	b8 01 00 00 00       	mov    eax,0x1
    76d5:	ff d0                	call   rax
    76d7:	48 85 c0             	test   rax,rax
    76da:	0f 84 ba 00 00 00    	je     779a <kprobe_unwind_hotspot+0x779a>
    76e0:	48 ff 00             	inc    QWORD PTR [rax]
    76e3:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 76ea <kprobe_unwind_hotspot+0x76ea>
			76e6: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    76ea:	83 38 00             	cmp    DWORD PTR [rax],0x0
    76ed:	49 8b 86 d0 0e 00 00 	mov    rax,QWORD PTR [r14+0xed0]
    76f4:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    76fb:	00 
    76fc:	49 8b 86 d8 0e 00 00 	mov    rax,QWORD PTR [r14+0xed8]
    7703:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    770a:	00 
    770b:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
    7712:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    7719:	00 
    771a:	0f 84 b7 00 00 00    	je     77d7 <kprobe_unwind_hotspot+0x77d7>
    7720:	48 b8 6f 66 66 73 65 	movabs rax,0x252074657366666f
    7727:	74 20 25 
    772a:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    772f:	48 b8 72 74 20 25 6c 	movabs rax,0x202c786c25207472
    7736:	78 2c 20 
    7739:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    773e:	48 b8 63 6f 64 65 20 	movabs rax,0x6174732065646f63
    7745:	73 74 61 
    7748:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    774d:	48 b8 20 25 6c 78 20 	movabs rax,0x206e6920786c2520
    7754:	69 6e 20 
    7757:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    775c:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    7763:	20 2d 3e 
    7766:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    776b:	c7 44 24 68 6c 78 0a 	mov    DWORD PTR [rsp+0x68],0xa786c
    7772:	00 
    7773:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
    777a:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
    7781:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7786:	be 2c 00 00 00       	mov    esi,0x2c
    778b:	bf 06 00 00 00       	mov    edi,0x6
    7790:	4c 8b 84 24 b8 00 00 	mov    r8,QWORD PTR [rsp+0xb8]
    7797:	00 
    7798:	eb 3d                	jmp    77d7 <kprobe_unwind_hotspot+0x77d7>
    779a:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 77a1 <kprobe_unwind_hotspot+0x77a1>
			779d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    77a1:	83 38 00             	cmp    DWORD PTR [rax],0x0
    77a4:	0f 85 7e 04 00 00    	jne    7c28 <kprobe_unwind_hotspot+0x7c28>
    77aa:	49 8b 86 d0 0e 00 00 	mov    rax,QWORD PTR [r14+0xed0]
    77b1:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    77b8:	00 
    77b9:	49 8b 86 d8 0e 00 00 	mov    rax,QWORD PTR [r14+0xed8]
    77c0:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    77c7:	00 
    77c8:	49 8b 86 e0 0e 00 00 	mov    rax,QWORD PTR [r14+0xee0]
    77cf:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    77d6:	00 
    77d7:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
    77dc:	c4 42 fb f7 ae 18 0f 	shrx   r13,QWORD PTR [r14+0xf18],rax
    77e3:	00 00 
    77e5:	49 8b 8e 10 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf10]
    77ec:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    77f3:	ff ff 00 
    77f6:	48 21 c1             	and    rcx,rax
    77f9:	48 89 cb             	mov    rbx,rcx
    77fc:	4a 8d 14 29          	lea    rdx,[rcx+r13*1]
    7800:	48 89 e7             	mov    rdi,rsp
    7803:	b8 01 00 00 00       	mov    eax,0x1
    7808:	b9 70 00 00 00       	mov    ecx,0x70
    780d:	be 01 00 00 00       	mov    esi,0x1
    7812:	ff d1                	call   rcx
    7814:	48 85 c0             	test   rax,rax
    7817:	0f 85 fb 89 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    781d:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7824 <kprobe_unwind_hotspot+0x7824>
			7820: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7824:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7827:	0f 85 72 04 00 00    	jne    7c9f <kprobe_unwind_hotspot+0x7c9f>
    782d:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7831:	8d 48 01             	lea    ecx,[rax+0x1]
    7834:	80 f9 02             	cmp    cl,0x2
    7837:	0f 83 c3 04 00 00    	jae    7d00 <kprobe_unwind_hotspot+0x7d00>
    783d:	84 c0                	test   al,al
    783f:	0f 85 d3 89 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    7845:	41 0f b6 47 20       	movzx  eax,BYTE PTR [r15+0x20]
    784a:	c4 c2 f9 f7 cd       	shlx   rcx,r13,rax
    784f:	49 03 8e 20 0f 00 00 	add    rcx,QWORD PTR [r14+0xf20]
    7856:	41 0f b6 47 1b       	movzx  eax,BYTE PTR [r15+0x1b]
    785b:	48 01 c8             	add    rax,rcx
    785e:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 7865 <kprobe_unwind_hotspot+0x7865>
			7861: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7865:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    7868:	74 52                	je     78bc <kprobe_unwind_hotspot+0x78bc>
    786a:	48 b9 6c 6f 62 20 25 	movabs rcx,0xa786c2520626f6c
    7871:	6c 78 0a 
    7874:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    7879:	48 b9 74 6f 20 63 6f 	movabs rcx,0x6265646f63206f74
    7880:	64 65 62 
    7883:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    7888:	48 b9 20 6d 61 70 70 	movabs rcx,0x2064657070616d20
    788f:	65 64 20 
    7892:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    7897:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    789e:	20 2d 3e 
    78a1:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    78a6:	c6 44 24 60 00       	mov    BYTE PTR [rsp+0x60],0x0
    78ab:	31 c9                	xor    ecx,ecx
    78ad:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    78b2:	be 21 00 00 00       	mov    esi,0x21
    78b7:	bf 06 00 00 00       	mov    edi,0x6
    78bc:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    78c3:	00 
    78c4:	48 85 c0             	test   rax,rax
    78c7:	0f 84 57 89 ff ff    	je     224 <kprobe_unwind_hotspot+0x224>
    78cd:	b9 00 02 00 00       	mov    ecx,0x200
    78d2:	41 b8 70 00 00 00    	mov    r8d,0x70
    78d8:	48 8b 94 24 d0 00 00 	mov    rdx,QWORD PTR [rsp+0xd0]
    78df:	00 
    78e0:	4c 89 e7             	mov    rdi,r12
    78e3:	be 00 02 00 00       	mov    esi,0x200
    78e8:	41 ff d0             	call   r8
    78eb:	48 85 c0             	test   rax,rax
    78ee:	0f 85 f8 89 ff ff    	jne    2ec <kprobe_unwind_hotspot+0x2ec>
    78f4:	41 0f b7 4f 10       	movzx  ecx,WORD PTR [r15+0x10]
    78f9:	b8 01 00 00 00       	mov    eax,0x1
    78fe:	48 81 f9 f8 01 00 00 	cmp    rcx,0x1f8
    7905:	0f 87 28 8a ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    790b:	41 0f b7 57 12       	movzx  edx,WORD PTR [r15+0x12]
    7910:	48 81 fa fc 01 00 00 	cmp    rdx,0x1fc
    7917:	0f 87 16 8a ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    791d:	41 0f b7 77 14       	movzx  esi,WORD PTR [r15+0x14]
    7922:	48 81 fe f8 01 00 00 	cmp    rsi,0x1f8
    7929:	0f 87 04 8a ff ff    	ja     333 <kprobe_unwind_hotspot+0x333>
    792f:	41 0f b6 47 17       	movzx  eax,BYTE PTR [r15+0x17]
    7934:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
    7938:	48 89 84 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rax
    793f:	00 
    7940:	41 0f b6 47 18       	movzx  eax,BYTE PTR [r15+0x18]
    7945:	49 8b 04 04          	mov    rax,QWORD PTR [r12+rax*1]
    7949:	48 89 84 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rax
    7950:	00 
    7951:	41 0f b6 47 1a       	movzx  eax,BYTE PTR [r15+0x1a]
    7956:	41 8b 04 04          	mov    eax,DWORD PTR [r12+rax*1]
    795a:	c1 e0 03             	shl    eax,0x3
    795d:	89 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],eax
    7964:	41 0f b6 47 19       	movzx  eax,BYTE PTR [r15+0x19]
    7969:	41 0f b7 04 04       	movzx  eax,WORD PTR [r12+rax*1]
    796e:	66 89 84 24 00 01 00 	mov    WORD PTR [rsp+0x100],ax
    7975:	00 
    7976:	41 8b 04 14          	mov    eax,DWORD PTR [r12+rdx*1]
    797a:	89 84 24 fc 00 00 00 	mov    DWORD PTR [rsp+0xfc],eax
    7981:	41 8b 04 34          	mov    eax,DWORD PTR [r12+rsi*1]
    7985:	89 84 24 f4 00 00 00 	mov    DWORD PTR [rsp+0xf4],eax
    798c:	49 8b 04 0c          	mov    rax,QWORD PTR [r12+rcx*1]
    7990:	48 89 84 24 e8 00 00 	mov    QWORD PTR [rsp+0xe8],rax
    7997:	00 
    7998:	41 0f b6 47 16       	movzx  eax,BYTE PTR [r15+0x16]
    799d:	49 8b 14 04          	mov    rdx,QWORD PTR [r12+rax*1]
    79a1:	b8 04 00 00 00       	mov    eax,0x4
    79a6:	b9 70 00 00 00       	mov    ecx,0x70
    79ab:	48 8d bc 24 f0 00 00 	lea    rdi,[rsp+0xf0]
    79b2:	00 
    79b3:	be 04 00 00 00       	mov    esi,0x4
    79b8:	ff d1                	call   rcx
    79ba:	48 85 c0             	test   rax,rax
    79bd:	0f 85 29 89 ff ff    	jne    2ec <kprobe_unwind_hotspot+0x2ec>
    79c3:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
    79c8:	74 2c                	je     79f6 <kprobe_unwind_hotspot+0x79f6>
    79ca:	48 8b 84 24 d0 00 00 	mov    rax,QWORD PTR [rsp+0xd0]
    79d1:	00 
    79d2:	8b 8c 24 d8 00 00 00 	mov    ecx,DWORD PTR [rsp+0xd8]
    79d9:	48 01 c1             	add    rcx,rax
    79dc:	48 89 8c 24 d8 00 00 	mov    QWORD PTR [rsp+0xd8],rcx
    79e3:	00 
    79e4:	8b 8c 24 e0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xe0]
    79eb:	48 01 c1             	add    rcx,rax
    79ee:	48 89 8c 24 e0 00 00 	mov    QWORD PTR [rsp+0xe0],rcx
    79f5:	00 
    79f6:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 79fd <kprobe_unwind_hotspot+0x79fd>
			79f9: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    79fd:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7a00:	0f 84 ed 00 00 00    	je     7af3 <kprobe_unwind_hotspot+0x7af3>
    7a06:	48 b8 6c 78 2d 25 6c 	movabs rax,0xa786c252d786c
    7a0d:	78 0a 00 
    7a10:	48 89 44 24 4f       	mov    QWORD PTR [rsp+0x4f],rax
    7a15:	48 b8 20 63 6f 64 65 	movabs rax,0x6c252065646f6320
    7a1c:	20 25 6c 
    7a1f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7a24:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    7a2b:	20 2d 3e 
    7a2e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7a33:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    7a3a:	00 
    7a3b:	48 8b 94 24 e0 00 00 	mov    rdx,QWORD PTR [rsp+0xe0]
    7a42:	00 
    7a43:	31 f6                	xor    esi,esi
    7a45:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    7a4a:	41 b8 17 00 00 00    	mov    r8d,0x17
    7a50:	41 b9 06 00 00 00    	mov    r9d,0x6
    7a56:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 7a5d <kprobe_unwind_hotspot+0x7a5d>
			7a59: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7a5d:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    7a60:	0f 84 8d 00 00 00    	je     7af3 <kprobe_unwind_hotspot+0x7af3>
    7a66:	48 b9 5f 74 79 70 65 	movabs rcx,0x783020657079745f
    7a6d:	20 30 78 
    7a70:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    7a75:	48 b9 75 2c 20 66 72 	movabs rcx,0x656d617266202c75
    7a7c:	61 6d 65 
    7a7f:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    7a84:	48 b9 65 5f 73 69 7a 	movabs rcx,0x2520657a69735f65
    7a8b:	65 20 25 
    7a8e:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    7a93:	48 b9 25 75 2c 20 66 	movabs rcx,0x6d617266202c7525
    7a9a:	72 61 6d 
    7a9d:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    7aa2:	48 b9 6f 6d 70 6c 65 	movabs rcx,0x206574656c706d6f
    7aa9:	74 65 20 
    7aac:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    7ab1:	48 b9 20 66 72 61 6d 	movabs rcx,0x635f656d61726620
    7ab8:	65 5f 63 
    7abb:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    7ac0:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7ac5:	c7 44 24 78 25 78 0a 	mov    DWORD PTR [rsp+0x78],0xa7825
    7acc:	00 
    7acd:	0f b7 84 24 00 01 00 	movzx  eax,WORD PTR [rsp+0x100]
    7ad4:	00 
    7ad5:	8b 8c 24 f0 00 00 00 	mov    ecx,DWORD PTR [rsp+0xf0]
    7adc:	8b 94 24 f8 00 00 00 	mov    edx,DWORD PTR [rsp+0xf8]
    7ae3:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    7ae8:	bf 3c 00 00 00       	mov    edi,0x3c
    7aed:	41 b8 06 00 00 00    	mov    r8d,0x6
    7af3:	48 8b 84 24 d0 00 00 	mov    rax,QWORD PTR [rsp+0xd0]
    7afa:	00 
    7afb:	48 89 84 24 18 01 00 	mov    QWORD PTR [rsp+0x118],rax
    7b02:	00 
    7b03:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
    7b0a:	00 
    7b0b:	8b 94 24 f0 00 00 00 	mov    edx,DWORD PTR [rsp+0xf0]
    7b12:	48 8b 8c 24 b8 00 00 	mov    rcx,QWORD PTR [rsp+0xb8]
    7b19:	00 
    7b1a:	29 c1                	sub    ecx,eax
    7b1c:	48 89 8c 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rcx
    7b23:	00 
    7b24:	48 89 d1             	mov    rcx,rdx
    7b27:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    7b2e:	00 
    7b2f:	81 fa 6d 61 74 69    	cmp    edx,0x6974616d
    7b35:	0f 8f 28 08 00 00    	jg     8363 <kprobe_unwind_hotspot+0x8363>
    7b3b:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x62617476
    7b42:	76 74 61 62 
    7b46:	0f 84 92 09 00 00    	je     84de <kprobe_unwind_hotspot+0x84de>
    7b4c:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x65746e49
    7b53:	49 6e 74 65 
    7b57:	0f 85 80 0a 00 00    	jne    85dd <kprobe_unwind_hotspot+0x85dd>
    7b5d:	49 bc 20 66 72 61 6d 	movabs r12,0xa656d61726620
    7b64:	65 0a 00 
    7b67:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    7b6e:	00 
    7b6f:	48 39 84 24 b0 00 00 	cmp    QWORD PTR [rsp+0xb0],rax
    7b76:	00 
    7b77:	0f 82 ca 09 00 00    	jb     8547 <kprobe_unwind_hotspot+0x8547>
    7b7d:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    7b84:	00 
    7b85:	48 05 00 10 00 00    	add    rax,0x1000
    7b8b:	48 39 84 24 b0 00 00 	cmp    QWORD PTR [rsp+0xb0],rax
    7b92:	00 
    7b93:	0f 83 ae 09 00 00    	jae    8547 <kprobe_unwind_hotspot+0x8547>
    7b99:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    7ba0:	00 
    7ba1:	48 8d 50 b0          	lea    rdx,[rax-0x50]
    7ba5:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    7baa:	b8 60 00 00 00       	mov    eax,0x60
    7baf:	b9 70 00 00 00       	mov    ecx,0x70
    7bb4:	be 60 00 00 00       	mov    esi,0x60
    7bb9:	ff d1                	call   rcx
    7bbb:	48 bb 65 61 64 20 69 	movabs rbx,0x65746e6920646165
    7bc2:	6e 74 65 
    7bc5:	48 85 c0             	test   rax,rax
    7bc8:	0f 84 ec 09 00 00    	je     85ba <kprobe_unwind_hotspot+0x85ba>
    7bce:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7bd5 <kprobe_unwind_hotspot+0x7bd5>
			7bd1: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7bd5:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7bd8:	0f 84 8a 0c 00 00    	je     8868 <kprobe_unwind_hotspot+0x8868>
    7bde:	4c 89 64 24 1f       	mov    QWORD PTR [rsp+0x1f],r12
    7be3:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
    7bea:	65 72 20 
    7bed:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    7bf2:	48 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],rbx
    7bf7:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    7bfe:	6f 20 72 
    7c01:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    7c06:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    7c0d:	66 61 69 
    7c10:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    7c14:	31 c0                	xor    eax,eax
    7c16:	48 89 e1             	mov    rcx,rsp
    7c19:	ba 27 00 00 00       	mov    edx,0x27
    7c1e:	be 06 00 00 00       	mov    esi,0x6
    7c23:	e9 40 0c 00 00       	jmp    8868 <kprobe_unwind_hotspot+0x8868>
    7c28:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    7c2f:	64 0a 00 
    7c32:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    7c37:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    7c3e:	69 63 49 
    7c41:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    7c46:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    7c4d:	66 6f 72 
    7c50:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    7c55:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    7c5c:	69 63 73 
    7c5f:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    7c64:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    7c6b:	6b 75 70 
    7c6e:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7c73:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    7c7a:	64 20 74 
    7c7d:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7c82:	8b 84 24 d0 00 00 00 	mov    eax,DWORD PTR [rsp+0xd0]
    7c89:	31 c9                	xor    ecx,ecx
    7c8b:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7c90:	be 2e 00 00 00       	mov    esi,0x2e
    7c95:	bf 06 00 00 00       	mov    edi,0x6
    7c9a:	e9 44 fa ff ff       	jmp    76e3 <kprobe_unwind_hotspot+0x76e3>
    7c9f:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    7ca6:	75 0a 00 
    7ca9:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    7cae:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    7cb5:	74 61 67 
    7cb8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    7cbd:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    7cc4:	6e 74 20 
    7cc7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7ccc:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7cd3:	20 20 20 
    7cd6:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7cdb:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7cdf:	31 c9                	xor    ecx,ecx
    7ce1:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7ce6:	be 1d 00 00 00       	mov    esi,0x1d
    7ceb:	bf 06 00 00 00       	mov    edi,0x6
    7cf0:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7cf4:	8d 48 01             	lea    ecx,[rax+0x1]
    7cf7:	80 f9 02             	cmp    cl,0x2
    7cfa:	0f 82 3d fb ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    7d00:	0f b6 c0             	movzx  eax,al
    7d03:	49 29 c5             	sub    r13,rax
    7d06:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    7d0a:	48 89 e7             	mov    rdi,rsp
    7d0d:	b8 01 00 00 00       	mov    eax,0x1
    7d12:	b9 70 00 00 00       	mov    ecx,0x70
    7d17:	be 01 00 00 00       	mov    esi,0x1
    7d1c:	ff d1                	call   rcx
    7d1e:	48 85 c0             	test   rax,rax
    7d21:	0f 85 f1 84 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    7d27:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7d2e <kprobe_unwind_hotspot+0x7d2e>
			7d2a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7d2e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7d31:	74 51                	je     7d84 <kprobe_unwind_hotspot+0x7d84>
    7d33:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    7d3a:	75 0a 00 
    7d3d:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    7d42:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    7d49:	74 61 67 
    7d4c:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    7d51:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    7d58:	6e 74 20 
    7d5b:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7d60:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7d67:	20 20 20 
    7d6a:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7d6f:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7d73:	31 c9                	xor    ecx,ecx
    7d75:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7d7a:	be 1d 00 00 00       	mov    esi,0x1d
    7d7f:	bf 06 00 00 00       	mov    edi,0x6
    7d84:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7d88:	8d 48 01             	lea    ecx,[rax+0x1]
    7d8b:	80 f9 02             	cmp    cl,0x2
    7d8e:	0f 82 a9 fa ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    7d94:	0f b6 c0             	movzx  eax,al
    7d97:	49 29 c5             	sub    r13,rax
    7d9a:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    7d9e:	48 89 e7             	mov    rdi,rsp
    7da1:	b8 01 00 00 00       	mov    eax,0x1
    7da6:	b9 70 00 00 00       	mov    ecx,0x70
    7dab:	be 01 00 00 00       	mov    esi,0x1
    7db0:	ff d1                	call   rcx
    7db2:	48 85 c0             	test   rax,rax
    7db5:	0f 85 5d 84 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    7dbb:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7dc2 <kprobe_unwind_hotspot+0x7dc2>
			7dbe: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7dc2:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7dc5:	74 51                	je     7e18 <kprobe_unwind_hotspot+0x7e18>
    7dc7:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    7dce:	75 0a 00 
    7dd1:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    7dd6:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    7ddd:	74 61 67 
    7de0:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    7de5:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    7dec:	6e 74 20 
    7def:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7df4:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7dfb:	20 20 20 
    7dfe:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7e03:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7e07:	31 c9                	xor    ecx,ecx
    7e09:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7e0e:	be 1d 00 00 00       	mov    esi,0x1d
    7e13:	bf 06 00 00 00       	mov    edi,0x6
    7e18:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7e1c:	8d 48 01             	lea    ecx,[rax+0x1]
    7e1f:	80 f9 02             	cmp    cl,0x2
    7e22:	0f 82 15 fa ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    7e28:	0f b6 c0             	movzx  eax,al
    7e2b:	49 29 c5             	sub    r13,rax
    7e2e:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    7e32:	48 89 e7             	mov    rdi,rsp
    7e35:	b8 01 00 00 00       	mov    eax,0x1
    7e3a:	b9 70 00 00 00       	mov    ecx,0x70
    7e3f:	be 01 00 00 00       	mov    esi,0x1
    7e44:	ff d1                	call   rcx
    7e46:	48 85 c0             	test   rax,rax
    7e49:	0f 85 c9 83 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    7e4f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7e56 <kprobe_unwind_hotspot+0x7e56>
			7e52: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7e56:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7e59:	74 51                	je     7eac <kprobe_unwind_hotspot+0x7eac>
    7e5b:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    7e62:	75 0a 00 
    7e65:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    7e6a:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    7e71:	74 61 67 
    7e74:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    7e79:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    7e80:	6e 74 20 
    7e83:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7e88:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7e8f:	20 20 20 
    7e92:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7e97:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7e9b:	31 c9                	xor    ecx,ecx
    7e9d:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7ea2:	be 1d 00 00 00       	mov    esi,0x1d
    7ea7:	bf 06 00 00 00       	mov    edi,0x6
    7eac:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7eb0:	8d 48 01             	lea    ecx,[rax+0x1]
    7eb3:	80 f9 02             	cmp    cl,0x2
    7eb6:	0f 82 81 f9 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    7ebc:	0f b6 c0             	movzx  eax,al
    7ebf:	49 29 c5             	sub    r13,rax
    7ec2:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    7ec6:	48 89 e7             	mov    rdi,rsp
    7ec9:	b8 01 00 00 00       	mov    eax,0x1
    7ece:	b9 70 00 00 00       	mov    ecx,0x70
    7ed3:	be 01 00 00 00       	mov    esi,0x1
    7ed8:	ff d1                	call   rcx
    7eda:	48 85 c0             	test   rax,rax
    7edd:	0f 85 35 83 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    7ee3:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7eea <kprobe_unwind_hotspot+0x7eea>
			7ee6: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7eea:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7eed:	74 51                	je     7f40 <kprobe_unwind_hotspot+0x7f40>
    7eef:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    7ef6:	75 0a 00 
    7ef9:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    7efe:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    7f05:	74 61 67 
    7f08:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    7f0d:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    7f14:	6e 74 20 
    7f17:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7f1c:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7f23:	20 20 20 
    7f26:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7f2b:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7f2f:	31 c9                	xor    ecx,ecx
    7f31:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7f36:	be 1d 00 00 00       	mov    esi,0x1d
    7f3b:	bf 06 00 00 00       	mov    edi,0x6
    7f40:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7f44:	8d 48 01             	lea    ecx,[rax+0x1]
    7f47:	80 f9 02             	cmp    cl,0x2
    7f4a:	0f 82 ed f8 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    7f50:	0f b6 c0             	movzx  eax,al
    7f53:	49 29 c5             	sub    r13,rax
    7f56:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    7f5a:	48 89 e7             	mov    rdi,rsp
    7f5d:	b8 01 00 00 00       	mov    eax,0x1
    7f62:	b9 70 00 00 00       	mov    ecx,0x70
    7f67:	be 01 00 00 00       	mov    esi,0x1
    7f6c:	ff d1                	call   rcx
    7f6e:	48 85 c0             	test   rax,rax
    7f71:	0f 85 a1 82 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    7f77:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 7f7e <kprobe_unwind_hotspot+0x7f7e>
			7f7a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    7f7e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    7f81:	74 51                	je     7fd4 <kprobe_unwind_hotspot+0x7fd4>
    7f83:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    7f8a:	75 0a 00 
    7f8d:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    7f92:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    7f99:	74 61 67 
    7f9c:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    7fa1:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    7fa8:	6e 74 20 
    7fab:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    7fb0:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    7fb7:	20 20 20 
    7fba:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    7fbf:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7fc3:	31 c9                	xor    ecx,ecx
    7fc5:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    7fca:	be 1d 00 00 00       	mov    esi,0x1d
    7fcf:	bf 06 00 00 00       	mov    edi,0x6
    7fd4:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    7fd8:	8d 48 01             	lea    ecx,[rax+0x1]
    7fdb:	80 f9 02             	cmp    cl,0x2
    7fde:	0f 82 59 f8 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    7fe4:	0f b6 c0             	movzx  eax,al
    7fe7:	49 29 c5             	sub    r13,rax
    7fea:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    7fee:	48 89 e7             	mov    rdi,rsp
    7ff1:	b8 01 00 00 00       	mov    eax,0x1
    7ff6:	b9 70 00 00 00       	mov    ecx,0x70
    7ffb:	be 01 00 00 00       	mov    esi,0x1
    8000:	ff d1                	call   rcx
    8002:	48 85 c0             	test   rax,rax
    8005:	0f 85 0d 82 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    800b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8012 <kprobe_unwind_hotspot+0x8012>
			800e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8012:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8015:	74 51                	je     8068 <kprobe_unwind_hotspot+0x8068>
    8017:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    801e:	75 0a 00 
    8021:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    8026:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    802d:	74 61 67 
    8030:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    8035:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    803c:	6e 74 20 
    803f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    8044:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    804b:	20 20 20 
    804e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    8053:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    8057:	31 c9                	xor    ecx,ecx
    8059:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    805e:	be 1d 00 00 00       	mov    esi,0x1d
    8063:	bf 06 00 00 00       	mov    edi,0x6
    8068:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    806c:	8d 48 01             	lea    ecx,[rax+0x1]
    806f:	80 f9 02             	cmp    cl,0x2
    8072:	0f 82 c5 f7 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    8078:	0f b6 c0             	movzx  eax,al
    807b:	49 29 c5             	sub    r13,rax
    807e:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    8082:	48 89 e7             	mov    rdi,rsp
    8085:	b8 01 00 00 00       	mov    eax,0x1
    808a:	b9 70 00 00 00       	mov    ecx,0x70
    808f:	be 01 00 00 00       	mov    esi,0x1
    8094:	ff d1                	call   rcx
    8096:	48 85 c0             	test   rax,rax
    8099:	0f 85 79 81 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    809f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 80a6 <kprobe_unwind_hotspot+0x80a6>
			80a2: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    80a6:	83 38 00             	cmp    DWORD PTR [rax],0x0
    80a9:	74 51                	je     80fc <kprobe_unwind_hotspot+0x80fc>
    80ab:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    80b2:	75 0a 00 
    80b5:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    80ba:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    80c1:	74 61 67 
    80c4:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    80c9:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    80d0:	6e 74 20 
    80d3:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    80d8:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    80df:	20 20 20 
    80e2:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    80e7:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    80eb:	31 c9                	xor    ecx,ecx
    80ed:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    80f2:	be 1d 00 00 00       	mov    esi,0x1d
    80f7:	bf 06 00 00 00       	mov    edi,0x6
    80fc:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    8100:	8d 48 01             	lea    ecx,[rax+0x1]
    8103:	80 f9 02             	cmp    cl,0x2
    8106:	0f 82 31 f7 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    810c:	0f b6 c0             	movzx  eax,al
    810f:	49 29 c5             	sub    r13,rax
    8112:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    8116:	48 89 e7             	mov    rdi,rsp
    8119:	b8 01 00 00 00       	mov    eax,0x1
    811e:	b9 70 00 00 00       	mov    ecx,0x70
    8123:	be 01 00 00 00       	mov    esi,0x1
    8128:	ff d1                	call   rcx
    812a:	48 85 c0             	test   rax,rax
    812d:	0f 85 e5 80 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    8133:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 813a <kprobe_unwind_hotspot+0x813a>
			8136: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    813a:	83 38 00             	cmp    DWORD PTR [rax],0x0
    813d:	74 51                	je     8190 <kprobe_unwind_hotspot+0x8190>
    813f:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    8146:	75 0a 00 
    8149:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    814e:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    8155:	74 61 67 
    8158:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    815d:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    8164:	6e 74 20 
    8167:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    816c:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8173:	20 20 20 
    8176:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    817b:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    817f:	31 c9                	xor    ecx,ecx
    8181:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    8186:	be 1d 00 00 00       	mov    esi,0x1d
    818b:	bf 06 00 00 00       	mov    edi,0x6
    8190:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    8194:	8d 48 01             	lea    ecx,[rax+0x1]
    8197:	80 f9 02             	cmp    cl,0x2
    819a:	0f 82 9d f6 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    81a0:	0f b6 c0             	movzx  eax,al
    81a3:	49 29 c5             	sub    r13,rax
    81a6:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    81aa:	48 89 e7             	mov    rdi,rsp
    81ad:	b8 01 00 00 00       	mov    eax,0x1
    81b2:	b9 70 00 00 00       	mov    ecx,0x70
    81b7:	be 01 00 00 00       	mov    esi,0x1
    81bc:	ff d1                	call   rcx
    81be:	48 85 c0             	test   rax,rax
    81c1:	0f 85 51 80 ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    81c7:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 81ce <kprobe_unwind_hotspot+0x81ce>
			81ca: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    81ce:	83 38 00             	cmp    DWORD PTR [rax],0x0
    81d1:	74 51                	je     8224 <kprobe_unwind_hotspot+0x8224>
    81d3:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    81da:	75 0a 00 
    81dd:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    81e2:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    81e9:	74 61 67 
    81ec:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    81f1:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    81f8:	6e 74 20 
    81fb:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    8200:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8207:	20 20 20 
    820a:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    820f:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    8213:	31 c9                	xor    ecx,ecx
    8215:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    821a:	be 1d 00 00 00       	mov    esi,0x1d
    821f:	bf 06 00 00 00       	mov    edi,0x6
    8224:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    8228:	8d 48 01             	lea    ecx,[rax+0x1]
    822b:	80 f9 02             	cmp    cl,0x2
    822e:	0f 82 09 f6 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    8234:	0f b6 c0             	movzx  eax,al
    8237:	49 29 c5             	sub    r13,rax
    823a:	4a 8d 14 2b          	lea    rdx,[rbx+r13*1]
    823e:	48 89 e7             	mov    rdi,rsp
    8241:	b8 01 00 00 00       	mov    eax,0x1
    8246:	b9 70 00 00 00       	mov    ecx,0x70
    824b:	be 01 00 00 00       	mov    esi,0x1
    8250:	ff d1                	call   rcx
    8252:	48 85 c0             	test   rax,rax
    8255:	0f 85 bd 7f ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    825b:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8262 <kprobe_unwind_hotspot+0x8262>
			825e: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8262:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8265:	74 51                	je     82b8 <kprobe_unwind_hotspot+0x82b8>
    8267:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    826e:	75 0a 00 
    8271:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    8276:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    827d:	74 61 67 
    8280:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    8285:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    828c:	6e 74 20 
    828f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    8294:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    829b:	20 20 20 
    829e:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    82a3:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    82a7:	31 c9                	xor    ecx,ecx
    82a9:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    82ae:	be 1d 00 00 00       	mov    esi,0x1d
    82b3:	bf 06 00 00 00       	mov    edi,0x6
    82b8:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    82bc:	8d 48 01             	lea    ecx,[rax+0x1]
    82bf:	80 f9 02             	cmp    cl,0x2
    82c2:	0f 82 75 f5 ff ff    	jb     783d <kprobe_unwind_hotspot+0x783d>
    82c8:	0f b6 c0             	movzx  eax,al
    82cb:	49 29 c5             	sub    r13,rax
    82ce:	4c 01 eb             	add    rbx,r13
    82d1:	48 89 e7             	mov    rdi,rsp
    82d4:	b8 01 00 00 00       	mov    eax,0x1
    82d9:	b9 70 00 00 00       	mov    ecx,0x70
    82de:	be 01 00 00 00       	mov    esi,0x1
    82e3:	48 89 da             	mov    rdx,rbx
    82e6:	ff d1                	call   rcx
    82e8:	48 85 c0             	test   rax,rax
    82eb:	0f 85 27 7f ff ff    	jne    218 <kprobe_unwind_hotspot+0x218>
    82f1:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 82f8 <kprobe_unwind_hotspot+0x82f8>
			82f4: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    82f8:	83 38 00             	cmp    DWORD PTR [rax],0x0
    82fb:	74 51                	je     834e <kprobe_unwind_hotspot+0x834e>
    82fd:	48 b8 74 61 67 20 25 	movabs rax,0xa752520676174
    8304:	75 0a 00 
    8307:	48 89 44 24 55       	mov    QWORD PTR [rsp+0x55],rax
    830c:	48 b8 25 6c 75 2c 20 	movabs rax,0x676174202c756c25
    8313:	74 61 67 
    8316:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    831b:	48 b8 73 65 67 6d 65 	movabs rax,0x20746e656d676573
    8322:	6e 74 20 
    8325:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    832a:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8331:	20 20 20 
    8334:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    8339:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    833d:	31 c9                	xor    ecx,ecx
    833f:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    8344:	be 1d 00 00 00       	mov    esi,0x1d
    8349:	bf 06 00 00 00       	mov    edi,0x6
    834e:	0f b6 04 24          	movzx  eax,BYTE PTR [rsp]
    8352:	8d 48 01             	lea    ecx,[rax+0x1]
    8355:	80 f9 01             	cmp    cl,0x1
    8358:	0f 87 ba 7e ff ff    	ja     218 <kprobe_unwind_hotspot+0x218>
    835e:	e9 da f4 ff ff       	jmp    783d <kprobe_unwind_hotspot+0x783d>
    8363:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x6974616e
    836a:	6e 61 74 69 
    836e:	74 11                	je     8381 <kprobe_unwind_hotspot+0x8381>
    8370:	81 bc 24 c0 00 00 00 	cmp    DWORD PTR [rsp+0xc0],0x74656d6e
    8377:	6e 6d 65 74 
    837b:	0f 85 5c 02 00 00    	jne    85dd <kprobe_unwind_hotspot+0x85dd>
    8381:	8b 8c 24 fc 00 00 00 	mov    ecx,DWORD PTR [rsp+0xfc]
    8388:	48 89 8c 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rcx
    838f:	00 
    8390:	48 8b 8c 24 e8 00 00 	mov    rcx,QWORD PTR [rsp+0xe8]
    8397:	00 
    8398:	89 ca                	mov    edx,ecx
    839a:	48 03 94 24 18 01 00 	add    rdx,QWORD PTR [rsp+0x118]
    83a1:	00 
    83a2:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
    83a7:	48 0f 44 d1          	cmove  rdx,rcx
    83ab:	48 39 94 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],rdx
    83b2:	00 
    83b3:	0f 85 2b 03 00 00    	jne    86e4 <kprobe_unwind_hotspot+0x86e4>
    83b9:	8b 84 24 f4 00 00 00 	mov    eax,DWORD PTR [rsp+0xf4]
    83c0:	48 8b b4 24 a8 00 00 	mov    rsi,QWORD PTR [rsp+0xa8]
    83c7:	00 
    83c8:	48 01 f0             	add    rax,rsi
    83cb:	48 89 e7             	mov    rdi,rsp
    83ce:	b9 08 00 00 00       	mov    ecx,0x8
    83d3:	41 b8 70 00 00 00    	mov    r8d,0x70
    83d9:	8b 94 24 f4 00 00 00 	mov    edx,DWORD PTR [rsp+0xf4]
    83e0:	48 01 f2             	add    rdx,rsi
    83e3:	be 08 00 00 00       	mov    esi,0x8
    83e8:	41 ff d0             	call   r8
    83eb:	48 85 c0             	test   rax,rax
    83ee:	0f 85 71 02 00 00    	jne    8665 <kprobe_unwind_hotspot+0x8665>
    83f4:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    83f8:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    83ff:	00 
    8400:	48 39 c8             	cmp    rax,rcx
    8403:	0f 82 5c 02 00 00    	jb     8665 <kprobe_unwind_hotspot+0x8665>
    8409:	48 3b 84 24 e0 00 00 	cmp    rax,QWORD PTR [rsp+0xe0]
    8410:	00 
    8411:	0f 83 4e 02 00 00    	jae    8665 <kprobe_unwind_hotspot+0x8665>
    8417:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # 841e <kprobe_unwind_hotspot+0x841e>
			841a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    841e:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
    8421:	0f 84 9e 00 00 00    	je     84c5 <kprobe_unwind_hotspot+0x84c5>
    8427:	48 b9 73 70 2b 25 64 	movabs rcx,0xa2964252b7073
    842e:	29 0a 00 
    8431:	48 89 4c 24 78       	mov    QWORD PTR [rsp+0x78],rcx
    8436:	48 b9 78 20 28 66 72 	movabs rcx,0x206d6f7266282078
    843d:	6f 6d 20 
    8440:	48 89 4c 24 70       	mov    QWORD PTR [rsp+0x70],rcx
    8445:	48 b9 20 61 73 20 30 	movabs rcx,0x6c25783020736120
    844c:	78 25 6c 
    844f:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    8454:	48 b9 65 63 6f 76 65 	movabs rcx,0x64657265766f6365
    845b:	72 65 64 
    845e:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    8463:	48 b9 6d 65 2c 20 70 	movabs rcx,0x72206370202c656d
    846a:	63 20 72 
    846d:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    8472:	48 b9 69 7a 65 64 20 	movabs rcx,0x6172662064657a69
    8479:	66 72 61 
    847c:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    8481:	48 b9 20 64 65 6f 70 	movabs rcx,0x6d6974706f656420
    8488:	74 69 6d 
    848b:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    8490:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    8497:	20 2d 3e 
    849a:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    849f:	48 63 8c 24 f4 00 00 	movsxd rcx,DWORD PTR [rsp+0xf4]
    84a6:	00 
    84a7:	31 d2                	xor    edx,edx
    84a9:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    84ae:	bf 40 00 00 00       	mov    edi,0x40
    84b3:	41 b8 06 00 00 00    	mov    r8d,0x6
    84b9:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    84bd:	48 8b 8c 24 d8 00 00 	mov    rcx,QWORD PTR [rsp+0xd8]
    84c4:	00 
    84c5:	89 c2                	mov    edx,eax
    84c7:	29 ca                	sub    edx,ecx
    84c9:	48 89 94 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rdx
    84d0:	00 
    84d1:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    84d8:	00 
    84d9:	e9 fe 01 00 00       	jmp    86dc <kprobe_unwind_hotspot+0x86dc>
    84de:	b0 01                	mov    al,0x1
    84e0:	89 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],eax
    84e7:	b8 76 74 61 62       	mov    eax,0x62617476
    84ec:	48 89 84 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rax
    84f3:	00 
    84f4:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 84fb <kprobe_unwind_hotspot+0x84fb>
			84f7: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    84fb:	83 38 00             	cmp    DWORD PTR [rax],0x0
    84fe:	0f 84 69 0c 00 00    	je     916d <kprobe_unwind_hotspot+0x916d>
    8504:	48 b8 76 74 61 62 6c 	movabs rax,0xa656c62617476
    850b:	65 0a 00 
    850e:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    8513:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    851a:	6e 64 20 
    851d:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    8522:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    8529:	20 2d 3e 
    852c:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    8531:	31 c0                	xor    eax,eax
    8533:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    8538:	ba 18 00 00 00       	mov    edx,0x18
    853d:	be 06 00 00 00       	mov    esi,0x6
    8542:	e9 26 0c 00 00       	jmp    916d <kprobe_unwind_hotspot+0x916d>
    8547:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 854e <kprobe_unwind_hotspot+0x854e>
			854a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    854e:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8551:	0f 84 11 03 00 00    	je     8868 <kprobe_unwind_hotspot+0x8868>
    8557:	4c 89 64 24 26       	mov    QWORD PTR [rsp+0x26],r12
    855c:	48 b8 70 72 65 74 65 	movabs rax,0x6620726574657270
    8563:	72 20 66 
    8566:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    856b:	48 b8 62 65 20 69 6e 	movabs rax,0x7265746e69206562
    8572:	74 65 72 
    8575:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    857a:	48 b8 61 77 61 79 20 	movabs rax,0x206f742079617761
    8581:	74 6f 20 
    8584:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8589:	48 b8 74 6f 6f 20 66 	movabs rax,0x20726166206f6f74
    8590:	61 72 20 
    8593:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8598:	48 b8 6a 76 6d 3a 20 	movabs rax,0x207066203a6d766a
    859f:	66 70 20 
    85a2:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    85a6:	31 c0                	xor    eax,eax
    85a8:	48 89 e1             	mov    rcx,rsp
    85ab:	ba 2e 00 00 00       	mov    edx,0x2e
    85b0:	be 06 00 00 00       	mov    esi,0x6
    85b5:	e9 ae 02 00 00       	jmp    8868 <kprobe_unwind_hotspot+0x8868>
    85ba:	41 83 be c0 02 00 00 	cmp    DWORD PTR [r14+0x2c0],0x0
    85c1:	00 
    85c2:	0f 84 c9 01 00 00    	je     8791 <kprobe_unwind_hotspot+0x8791>
    85c8:	41 80 7f 1f 00       	cmp    BYTE PTR [r15+0x1f],0x0
    85cd:	0f 84 c7 01 00 00    	je     879a <kprobe_unwind_hotspot+0x879a>
    85d3:	4c 8b 64 24 50       	mov    r12,QWORD PTR [rsp+0x50]
    85d8:	e9 c2 01 00 00       	jmp    879f <kprobe_unwind_hotspot+0x879f>
    85dd:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 85e4 <kprobe_unwind_hotspot+0x85e4>
			85e0: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    85e4:	83 38 00             	cmp    DWORD PTR [rax],0x0
    85e7:	74 55                	je     863e <kprobe_unwind_hotspot+0x863e>
    85e9:	48 b8 6c 62 61 63 6b 	movabs rax,0x6170206b6361626c
    85f0:	20 70 61 
    85f3:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    85f8:	48 b8 73 74 75 62 20 	movabs rax,0x6c61662062757473
    85ff:	66 61 6c 
    8602:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    8607:	48 b8 20 75 6e 77 69 	movabs rax,0x20646e69776e7520
    860e:	6e 64 20 
    8611:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    8616:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    861d:	20 2d 3e 
    8620:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    8625:	c7 44 24 60 74 68 0a 	mov    DWORD PTR [rsp+0x60],0xa6874
    862c:	00 
    862d:	31 c0                	xor    eax,eax
    862f:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    8634:	ba 24 00 00 00       	mov    edx,0x24
    8639:	be 06 00 00 00       	mov    esi,0x6
    863e:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
    8645:	c7 84 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],0x0
    864c:	00 00 00 00 
    8650:	48 8b 8c 24 b0 00 00 	mov    rcx,QWORD PTR [rsp+0xb0]
    8657:	00 
    8658:	85 c0                	test   eax,eax
    865a:	0f 85 52 0b 00 00    	jne    91b2 <kprobe_unwind_hotspot+0x91b2>
    8660:	e9 2c 0b 00 00       	jmp    9191 <kprobe_unwind_hotspot+0x9191>
    8665:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 866c <kprobe_unwind_hotspot+0x866c>
			8668: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    866c:	83 38 00             	cmp    DWORD PTR [rax],0x0
    866f:	74 6b                	je     86dc <kprobe_unwind_hotspot+0x86dc>
    8671:	48 b8 66 61 69 6c 65 	movabs rax,0xa64656c696166
    8678:	64 0a 00 
    867b:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    8680:	48 b8 65 63 6f 76 65 	movabs rax,0x20797265766f6365
    8687:	72 79 20 
    868a:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    868f:	48 b8 6d 65 2c 20 70 	movabs rax,0x72206370202c656d
    8696:	63 20 72 
    8699:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    869e:	48 b8 69 7a 65 64 20 	movabs rax,0x6172662064657a69
    86a5:	66 72 61 
    86a8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    86ad:	48 b8 20 64 65 6f 70 	movabs rax,0x6d6974706f656420
    86b4:	74 69 6d 
    86b7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    86bc:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    86c3:	20 2d 3e 
    86c6:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    86cb:	31 c0                	xor    eax,eax
    86cd:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    86d2:	ba 30 00 00 00       	mov    edx,0x30
    86d7:	be 06 00 00 00       	mov    esi,0x6
    86dc:	48 8b 84 24 d8 00 00 	mov    rax,QWORD PTR [rsp+0xd8]
    86e3:	00 
    86e4:	0f b7 8c 24 00 01 00 	movzx  ecx,WORD PTR [rsp+0x100]
    86eb:	00 
    86ec:	48 01 c1             	add    rcx,rax
    86ef:	48 39 8c 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],rcx
    86f6:	00 
    86f7:	0f 83 9d 01 00 00    	jae    889a <kprobe_unwind_hotspot+0x889a>
    86fd:	48 83 c1 fc          	add    rcx,0xfffffffffffffffc
    8701:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8708 <kprobe_unwind_hotspot+0x8708>
			8704: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8708:	8b 00                	mov    eax,DWORD PTR [rax]
    870a:	48 39 8c 24 b8 00 00 	cmp    QWORD PTR [rsp+0xb8],rcx
    8711:	00 
    8712:	0f 83 42 02 00 00    	jae    895a <kprobe_unwind_hotspot+0x895a>
    8718:	b1 03                	mov    cl,0x3
    871a:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    8721:	85 c0                	test   eax,eax
    8723:	0f 84 44 0a 00 00    	je     916d <kprobe_unwind_hotspot+0x916d>
    8729:	48 b8 61 6d 65 20 28 	movabs rax,0x2963702820656d61
    8730:	70 63 29 
    8733:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    8738:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
    873f:	20 66 72 
    8742:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    8747:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
    874e:	63 6f 6d 
    8751:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    8756:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    875d:	6e 64 69 
    8760:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    8765:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    876c:	20 2d 3e 
    876f:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    8774:	66 c7 44 24 68 0a 00 	mov    WORD PTR [rsp+0x68],0xa
    877b:	31 c0                	xor    eax,eax
    877d:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    8782:	ba 2a 00 00 00       	mov    edx,0x2a
    8787:	be 06 00 00 00       	mov    esi,0x6
    878c:	e9 dc 09 00 00       	jmp    916d <kprobe_unwind_hotspot+0x916d>
    8791:	4d 8b a6 00 0f 00 00 	mov    r12,QWORD PTR [r14+0xf00]
    8798:	eb 05                	jmp    879f <kprobe_unwind_hotspot+0x879f>
    879a:	4c 8b 64 24 58       	mov    r12,QWORD PTR [rsp+0x58]
    879f:	4c 8b 6c 24 78       	mov    r13,QWORD PTR [rsp+0x78]
    87a4:	48 8b 84 24 88 00 00 	mov    rax,QWORD PTR [rsp+0x88]
    87ab:	00 
    87ac:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
    87b3:	00 
    87b4:	48 8b 84 24 90 00 00 	mov    rax,QWORD PTR [rsp+0x90]
    87bb:	00 
    87bc:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    87c3:	00 
    87c4:	48 8b 84 24 98 00 00 	mov    rax,QWORD PTR [rsp+0x98]
    87cb:	00 
    87cc:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    87d3:	00 
    87d4:	41 0f b6 47 1c       	movzx  eax,BYTE PTR [r15+0x1c]
    87d9:	4c 01 e8             	add    rax,r13
    87dc:	48 8d bc 24 08 01 00 	lea    rdi,[rsp+0x108]
    87e3:	00 
    87e4:	b9 08 00 00 00       	mov    ecx,0x8
    87e9:	41 b8 70 00 00 00    	mov    r8d,0x70
    87ef:	41 0f b6 57 1c       	movzx  edx,BYTE PTR [r15+0x1c]
    87f4:	4c 01 ea             	add    rdx,r13
    87f7:	be 08 00 00 00       	mov    esi,0x8
    87fc:	41 ff d0             	call   r8
    87ff:	48 85 c0             	test   rax,rax
    8802:	0f 84 d3 01 00 00    	je     89db <kprobe_unwind_hotspot+0x89db>
    8808:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 880f <kprobe_unwind_hotspot+0x880f>
			880b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    880f:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8812:	74 54                	je     8868 <kprobe_unwind_hotspot+0x8868>
    8814:	48 b8 63 6d 65 74 68 	movabs rax,0xa646f6874656d63
    881b:	6f 64 0a 
    881e:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    8823:	48 b8 72 70 72 65 74 	movabs rax,0x2072657465727072
    882a:	65 72 20 
    882d:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8832:	48 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],rbx
    8837:	48 b8 6c 65 64 20 74 	movabs rax,0x72206f742064656c
    883e:	6f 20 72 
    8841:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8846:	48 b8 6a 76 6d 3a 20 	movabs rax,0x696166203a6d766a
    884d:	66 61 69 
    8850:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8854:	c6 44 24 28 00       	mov    BYTE PTR [rsp+0x28],0x0
    8859:	31 c0                	xor    eax,eax
    885b:	48 89 e1             	mov    rcx,rsp
    885e:	ba 29 00 00 00       	mov    edx,0x29
    8863:	be 06 00 00 00       	mov    esi,0x6
    8868:	c7 84 24 14 01 00 00 	mov    DWORD PTR [rsp+0x114],0x2d
    886f:	2d 00 00 00 
    8873:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 887a <kprobe_unwind_hotspot+0x887a>
			8876: R_X86_64_REX_GOTPCRELX	metrics-0x4
    887a:	48 8d b4 24 14 01 00 	lea    rsi,[rsp+0x114]
    8881:	00 
    8882:	b8 01 00 00 00       	mov    eax,0x1
    8887:	ff d0                	call   rax
    8889:	48 85 c0             	test   rax,rax
    888c:	0f 84 4e 02 00 00    	je     8ae0 <kprobe_unwind_hotspot+0x8ae0>
    8892:	48 ff 00             	inc    QWORD PTR [rax]
    8895:	e9 c1 02 00 00       	jmp    8b5b <kprobe_unwind_hotspot+0x8b5b>
    889a:	44 8b a4 24 f8 00 00 	mov    r12d,DWORD PTR [rsp+0xf8]
    88a1:	00 
    88a2:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    88a9:	00 
    88aa:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
    88b1:	00 
    88b2:	4e 8d 3c 21          	lea    r15,[rcx+r12*1]
    88b6:	49 83 c7 30          	add    r15,0x30
    88ba:	48 29 c8             	sub    rax,rcx
    88bd:	0f 82 b1 02 00 00    	jb     8b74 <kprobe_unwind_hotspot+0x8b74>
    88c3:	4c 39 bc 24 b0 00 00 	cmp    QWORD PTR [rsp+0xb0],r15
    88ca:	00 
    88cb:	0f 83 a3 02 00 00    	jae    8b74 <kprobe_unwind_hotspot+0x8b74>
    88d1:	b1 03                	mov    cl,0x3
    88d3:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    88da:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 88e1 <kprobe_unwind_hotspot+0x88e1>
			88dd: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    88e1:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    88e4:	0f 84 95 08 00 00    	je     917f <kprobe_unwind_hotspot+0x917f>
    88ea:	48 b9 65 20 25 6c 64 	movabs rcx,0xa29646c252065
    88f1:	29 0a 00 
    88f4:	48 89 4c 24 67       	mov    QWORD PTR [rsp+0x67],rcx
    88f9:	48 b9 61 6d 65 20 73 	movabs rcx,0x657a697320656d61
    8900:	69 7a 65 
    8903:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    8908:	48 b9 6e 74 65 72 20 	movabs rcx,0x726628207265746e
    890f:	28 66 72 
    8912:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    8917:	48 b9 72 61 6d 65 20 	movabs rcx,0x696f7020656d6172
    891e:	70 6f 69 
    8921:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    8926:	48 b9 20 75 73 69 6e 	movabs rcx,0x6620676e69737520
    892d:	67 20 66 
    8930:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    8935:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    893c:	20 2d 3e 
    893f:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    8944:	31 c9                	xor    ecx,ecx
    8946:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    894b:	be 2f 00 00 00       	mov    esi,0x2f
    8950:	bf 06 00 00 00       	mov    edi,0x6
    8955:	e9 25 08 00 00       	jmp    917f <kprobe_unwind_hotspot+0x917f>
    895a:	b1 03                	mov    cl,0x3
    895c:	89 8c 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],ecx
    8963:	85 c0                	test   eax,eax
    8965:	0f 84 1e 08 00 00    	je     9189 <kprobe_unwind_hotspot+0x9189>
    896b:	48 b8 66 70 2b 70 63 	movabs rax,0xa2963702b7066
    8972:	29 0a 00 
    8975:	48 89 44 24 65       	mov    QWORD PTR [rsp+0x65],rax
    897a:	48 b8 61 6d 65 20 28 	movabs rax,0x2b70662820656d61
    8981:	66 70 2b 
    8984:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    8989:	48 b8 70 6c 65 74 65 	movabs rax,0x7266206574656c70
    8990:	20 66 72 
    8993:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    8998:	48 b8 6e 67 20 69 6e 	movabs rax,0x6d6f636e6920676e
    899f:	63 6f 6d 
    89a2:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    89a7:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    89ae:	6e 64 69 
    89b1:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    89b6:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    89bd:	20 2d 3e 
    89c0:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    89c5:	31 c0                	xor    eax,eax
    89c7:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    89cc:	ba 2d 00 00 00       	mov    edx,0x2d
    89d1:	be 06 00 00 00       	mov    esi,0x6
    89d6:	e9 ae 07 00 00       	jmp    9189 <kprobe_unwind_hotspot+0x9189>
    89db:	48 8b 94 24 08 01 00 	mov    rdx,QWORD PTR [rsp+0x108]
    89e2:	00 
    89e3:	41 0f b6 4f 1d       	movzx  ecx,BYTE PTR [r15+0x1d]
    89e8:	48 89 d0             	mov    rax,rdx
    89eb:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    89f2:	00 
    89f3:	48 01 d1             	add    rcx,rdx
    89f6:	31 c0                	xor    eax,eax
    89f8:	49 39 cc             	cmp    r12,rcx
    89fb:	ba 00 00 00 00       	mov    edx,0x0
    8a00:	48 0f 43 d1          	cmovae rdx,rcx
    8a04:	49 29 d4             	sub    r12,rdx
    8a07:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 8a0e <kprobe_unwind_hotspot+0x8a0e>
			8a0a: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8a0e:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    8a11:	0f 84 8d 00 00 00    	je     8aa4 <kprobe_unwind_hotspot+0x8aa4>
    8a17:	48 b9 20 3d 20 25 6c 	movabs rcx,0xa786c25203d20
    8a1e:	78 0a 00 
    8a21:	48 89 4c 24 2d       	mov    QWORD PTR [rsp+0x2d],rcx
    8a26:	48 b9 2c 20 62 63 70 	movabs rcx,0x203d20706362202c
    8a2d:	20 3d 20 
    8a30:	48 89 4c 24 28       	mov    QWORD PTR [rsp+0x28],rcx
    8a35:	48 b9 20 3d 20 30 78 	movabs rcx,0x786c257830203d20
    8a3c:	25 6c 78 
    8a3f:	48 89 4c 24 20       	mov    QWORD PTR [rsp+0x20],rcx
    8a44:	48 b9 20 63 6d 65 74 	movabs rcx,0x646f6874656d6320
    8a4b:	68 6f 64 
    8a4e:	48 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],rcx
    8a53:	48 b9 3d 20 30 78 25 	movabs rcx,0x2c786c257830203d
    8a5a:	6c 78 2c 
    8a5d:	48 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],rcx
    8a62:	48 b9 20 6d 65 74 68 	movabs rcx,0x20646f6874656d20
    8a69:	6f 64 20 
    8a6c:	48 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],rcx
    8a71:	48 b9 6a 76 6d 3a 20 	movabs rcx,0x3e2d20203a6d766a
    8a78:	20 2d 3e 
    8a7b:	48 89 0c 24          	mov    QWORD PTR [rsp],rcx
    8a7f:	48 89 e1             	mov    rcx,rsp
    8a82:	ba 35 00 00 00       	mov    edx,0x35
    8a87:	be 06 00 00 00       	mov    esi,0x6
    8a8c:	48 8b bc 24 c0 00 00 	mov    rdi,QWORD PTR [rsp+0xc0]
    8a93:	00 
    8a94:	48 8b 8c 24 08 01 00 	mov    rcx,QWORD PTR [rsp+0x108]
    8a9b:	00 
    8a9c:	48 89 8c 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rcx
    8aa3:	00 
    8aa4:	49 81 fc ff ff 00 00 	cmp    r12,0xffff
    8aab:	b9 ff ff 00 00       	mov    ecx,0xffff
    8ab0:	49 0f 42 cc          	cmovb  rcx,r12
    8ab4:	48 89 8c 24 20 01 00 	mov    QWORD PTR [rsp+0x120],rcx
    8abb:	00 
    8abc:	48 c1 ac 24 c0 00 00 	shr    QWORD PTR [rsp+0xc0],0x3
    8ac3:	00 03 
    8ac5:	b9 06 00 00 00       	mov    ecx,0x6
    8aca:	b2 02                	mov    dl,0x2
    8acc:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    8ad3:	4c 89 ac 24 18 01 00 	mov    QWORD PTR [rsp+0x118],r13
    8ada:	00 
    8adb:	e9 6e 06 00 00       	jmp    914e <kprobe_unwind_hotspot+0x914e>
    8ae0:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8ae7 <kprobe_unwind_hotspot+0x8ae7>
			8ae3: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8ae7:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8aea:	74 6f                	je     8b5b <kprobe_unwind_hotspot+0x8b5b>
    8aec:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    8af3:	64 0a 00 
    8af6:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    8afb:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    8b02:	69 63 49 
    8b05:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    8b0a:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    8b11:	66 6f 72 
    8b14:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8b19:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    8b20:	69 63 73 
    8b23:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8b28:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    8b2f:	6b 75 70 
    8b32:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8b37:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    8b3e:	64 20 74 
    8b41:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8b45:	8b 84 24 14 01 00 00 	mov    eax,DWORD PTR [rsp+0x114]
    8b4c:	31 c9                	xor    ecx,ecx
    8b4e:	48 89 e2             	mov    rdx,rsp
    8b51:	be 2e 00 00 00       	mov    esi,0x2e
    8b56:	bf 06 00 00 00       	mov    edi,0x6
    8b5b:	b8 e9 03 00 00       	mov    eax,0x3e9
    8b60:	31 c9                	xor    ecx,ecx
    8b62:	ba 49 6e 74 65       	mov    edx,0x65746e49
    8b67:	48 89 94 24 c0 00 00 	mov    QWORD PTR [rsp+0xc0],rdx
    8b6e:	00 
    8b6f:	e9 da 05 00 00       	jmp    914e <kprobe_unwind_hotspot+0x914e>
    8b74:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    8b7b:	00 
    8b7c:	4a 8d 14 20          	lea    rdx,[rax+r12*1]
    8b80:	48 83 c2 f8          	add    rdx,0xfffffffffffffff8
    8b84:	48 8d 7c 24 40       	lea    rdi,[rsp+0x40]
    8b89:	b8 30 00 00 00       	mov    eax,0x30
    8b8e:	b9 70 00 00 00       	mov    ecx,0x70
    8b93:	be 30 00 00 00       	mov    esi,0x30
    8b98:	ff d1                	call   rcx
    8b9a:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8ba1 <kprobe_unwind_hotspot+0x8ba1>
			8b9d: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8ba1:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8ba4:	74 56                	je     8bfc <kprobe_unwind_hotspot+0x8bfc>
    8ba6:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    8bad:	25 6c 78 
    8bb0:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8bb5:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    8bbc:	69 64 61 
    8bbf:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8bc4:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    8bcb:	20 70 63 
    8bce:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8bd3:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8bda:	20 20 20 
    8bdd:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8be1:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    8be8:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
    8bed:	31 c9                	xor    ecx,ecx
    8bef:	48 89 e2             	mov    rdx,rsp
    8bf2:	be 22 00 00 00       	mov    esi,0x22
    8bf7:	bf 06 00 00 00       	mov    edi,0x6
    8bfc:	41 8b 06             	mov    eax,DWORD PTR [r14]
    8bff:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    8c06:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    8c0c:	4c 01 a4 24 a8 00 00 	add    QWORD PTR [rsp+0xa8],r12
    8c13:	00 
    8c14:	48 8b 44 24 40       	mov    rax,QWORD PTR [rsp+0x40]
    8c19:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    8c20:	49 bd 00 00 00 00 00 	movabs r13,0xff00000000000000
    8c27:	00 00 ff 
    8c2a:	48 bb 00 00 00 00 00 	movabs rbx,0x200000000000000
    8c31:	00 00 02 
    8c34:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 8c3b <kprobe_unwind_hotspot+0x8c3b>
			8c37: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    8c3b:	48 89 e6             	mov    rsi,rsp
    8c3e:	b8 01 00 00 00       	mov    eax,0x1
    8c43:	ff d0                	call   rax
    8c45:	48 85 c0             	test   rax,rax
    8c48:	74 14                	je     8c5e <kprobe_unwind_hotspot+0x8c5e>
    8c4a:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    8c4e:	4c 21 e8             	and    rax,r13
    8c51:	48 39 d8             	cmp    rax,rbx
    8c54:	75 08                	jne    8c5e <kprobe_unwind_hotspot+0x8c5e>
    8c56:	45 31 e4             	xor    r12d,r12d
    8c59:	e9 9a 03 00 00       	jmp    8ff8 <kprobe_unwind_hotspot+0x8ff8>
    8c5e:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8c65 <kprobe_unwind_hotspot+0x8c65>
			8c61: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8c65:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8c68:	74 5c                	je     8cc6 <kprobe_unwind_hotspot+0x8cc6>
    8c6a:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    8c71:	25 6c 78 
    8c74:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8c79:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    8c80:	69 64 61 
    8c83:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8c88:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    8c8f:	20 70 63 
    8c92:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8c97:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8c9e:	20 20 20 
    8ca1:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8ca5:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    8cac:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    8cb1:	31 c9                	xor    ecx,ecx
    8cb3:	48 89 e2             	mov    rdx,rsp
    8cb6:	be 22 00 00 00       	mov    esi,0x22
    8cbb:	bf 01 00 00 00       	mov    edi,0x1
    8cc0:	41 b8 06 00 00 00    	mov    r8d,0x6
    8cc6:	41 8b 06             	mov    eax,DWORD PTR [r14]
    8cc9:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    8cd0:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    8cd6:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
    8cdb:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    8ce2:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 8ce9 <kprobe_unwind_hotspot+0x8ce9>
			8ce5: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    8ce9:	48 89 e6             	mov    rsi,rsp
    8cec:	41 bc 01 00 00 00    	mov    r12d,0x1
    8cf2:	b8 01 00 00 00       	mov    eax,0x1
    8cf7:	ff d0                	call   rax
    8cf9:	48 85 c0             	test   rax,rax
    8cfc:	74 1a                	je     8d18 <kprobe_unwind_hotspot+0x8d18>
    8cfe:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    8d02:	4c 21 e8             	and    rax,r13
    8d05:	48 39 d8             	cmp    rax,rbx
    8d08:	75 0e                	jne    8d18 <kprobe_unwind_hotspot+0x8d18>
    8d0a:	48 83 84 24 a8 00 00 	add    QWORD PTR [rsp+0xa8],0x8
    8d11:	00 08 
    8d13:	e9 e0 02 00 00       	jmp    8ff8 <kprobe_unwind_hotspot+0x8ff8>
    8d18:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8d1f <kprobe_unwind_hotspot+0x8d1f>
			8d1b: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8d1f:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8d22:	74 5c                	je     8d80 <kprobe_unwind_hotspot+0x8d80>
    8d24:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    8d2b:	25 6c 78 
    8d2e:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8d33:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    8d3a:	69 64 61 
    8d3d:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8d42:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    8d49:	20 70 63 
    8d4c:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8d51:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8d58:	20 20 20 
    8d5b:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8d5f:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    8d66:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    8d6b:	31 c9                	xor    ecx,ecx
    8d6d:	48 89 e2             	mov    rdx,rsp
    8d70:	be 22 00 00 00       	mov    esi,0x22
    8d75:	bf 02 00 00 00       	mov    edi,0x2
    8d7a:	41 b8 06 00 00 00    	mov    r8d,0x6
    8d80:	41 8b 06             	mov    eax,DWORD PTR [r14]
    8d83:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    8d8a:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    8d90:	48 8b 44 24 50       	mov    rax,QWORD PTR [rsp+0x50]
    8d95:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    8d9c:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 8da3 <kprobe_unwind_hotspot+0x8da3>
			8d9f: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    8da3:	48 89 e6             	mov    rsi,rsp
    8da6:	b8 01 00 00 00       	mov    eax,0x1
    8dab:	ff d0                	call   rax
    8dad:	48 85 c0             	test   rax,rax
    8db0:	74 20                	je     8dd2 <kprobe_unwind_hotspot+0x8dd2>
    8db2:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    8db6:	4c 21 e8             	and    rax,r13
    8db9:	48 39 d8             	cmp    rax,rbx
    8dbc:	75 14                	jne    8dd2 <kprobe_unwind_hotspot+0x8dd2>
    8dbe:	48 83 84 24 a8 00 00 	add    QWORD PTR [rsp+0xa8],0x10
    8dc5:	00 10 
    8dc7:	41 bc 02 00 00 00    	mov    r12d,0x2
    8dcd:	e9 26 02 00 00       	jmp    8ff8 <kprobe_unwind_hotspot+0x8ff8>
    8dd2:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8dd9 <kprobe_unwind_hotspot+0x8dd9>
			8dd5: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8dd9:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8ddc:	74 5c                	je     8e3a <kprobe_unwind_hotspot+0x8e3a>
    8dde:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    8de5:	25 6c 78 
    8de8:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8ded:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    8df4:	69 64 61 
    8df7:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8dfc:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    8e03:	20 70 63 
    8e06:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8e0b:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8e12:	20 20 20 
    8e15:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8e19:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    8e20:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    8e25:	31 c9                	xor    ecx,ecx
    8e27:	48 89 e2             	mov    rdx,rsp
    8e2a:	be 22 00 00 00       	mov    esi,0x22
    8e2f:	bf 03 00 00 00       	mov    edi,0x3
    8e34:	41 b8 06 00 00 00    	mov    r8d,0x6
    8e3a:	41 8b 06             	mov    eax,DWORD PTR [r14]
    8e3d:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    8e44:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    8e4a:	48 8b 44 24 58       	mov    rax,QWORD PTR [rsp+0x58]
    8e4f:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    8e56:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 8e5d <kprobe_unwind_hotspot+0x8e5d>
			8e59: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    8e5d:	48 89 e6             	mov    rsi,rsp
    8e60:	b8 01 00 00 00       	mov    eax,0x1
    8e65:	ff d0                	call   rax
    8e67:	48 85 c0             	test   rax,rax
    8e6a:	74 20                	je     8e8c <kprobe_unwind_hotspot+0x8e8c>
    8e6c:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    8e70:	4c 21 e8             	and    rax,r13
    8e73:	48 39 d8             	cmp    rax,rbx
    8e76:	75 14                	jne    8e8c <kprobe_unwind_hotspot+0x8e8c>
    8e78:	48 83 84 24 a8 00 00 	add    QWORD PTR [rsp+0xa8],0x18
    8e7f:	00 18 
    8e81:	41 bc 03 00 00 00    	mov    r12d,0x3
    8e87:	e9 6c 01 00 00       	jmp    8ff8 <kprobe_unwind_hotspot+0x8ff8>
    8e8c:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8e93 <kprobe_unwind_hotspot+0x8e93>
			8e8f: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8e93:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8e96:	74 5c                	je     8ef4 <kprobe_unwind_hotspot+0x8ef4>
    8e98:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    8e9f:	25 6c 78 
    8ea2:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8ea7:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    8eae:	69 64 61 
    8eb1:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8eb6:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    8ebd:	20 70 63 
    8ec0:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8ec5:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8ecc:	20 20 20 
    8ecf:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8ed3:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    8eda:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    8edf:	31 c9                	xor    ecx,ecx
    8ee1:	48 89 e2             	mov    rdx,rsp
    8ee4:	be 22 00 00 00       	mov    esi,0x22
    8ee9:	bf 04 00 00 00       	mov    edi,0x4
    8eee:	41 b8 06 00 00 00    	mov    r8d,0x6
    8ef4:	41 8b 06             	mov    eax,DWORD PTR [r14]
    8ef7:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    8efe:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    8f04:	48 8b 44 24 60       	mov    rax,QWORD PTR [rsp+0x60]
    8f09:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    8f10:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 8f17 <kprobe_unwind_hotspot+0x8f17>
			8f13: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    8f17:	48 89 e6             	mov    rsi,rsp
    8f1a:	b8 01 00 00 00       	mov    eax,0x1
    8f1f:	ff d0                	call   rax
    8f21:	48 85 c0             	test   rax,rax
    8f24:	74 20                	je     8f46 <kprobe_unwind_hotspot+0x8f46>
    8f26:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
    8f2a:	4c 21 e8             	and    rax,r13
    8f2d:	48 39 d8             	cmp    rax,rbx
    8f30:	75 14                	jne    8f46 <kprobe_unwind_hotspot+0x8f46>
    8f32:	48 83 84 24 a8 00 00 	add    QWORD PTR [rsp+0xa8],0x20
    8f39:	00 20 
    8f3b:	41 bc 04 00 00 00    	mov    r12d,0x4
    8f41:	e9 b2 00 00 00       	jmp    8ff8 <kprobe_unwind_hotspot+0x8ff8>
    8f46:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 8f4d <kprobe_unwind_hotspot+0x8f4d>
			8f49: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    8f4d:	83 38 00             	cmp    DWORD PTR [rax],0x0
    8f50:	74 5c                	je     8fae <kprobe_unwind_hotspot+0x8fae>
    8f52:	48 b8 74 65 20 30 78 	movabs rax,0x786c257830206574
    8f59:	25 6c 78 
    8f5c:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    8f61:	48 b8 20 63 61 6e 64 	movabs rax,0x616469646e616320
    8f68:	69 64 61 
    8f6b:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    8f70:	48 b8 2d 3e 20 25 75 	movabs rax,0x6370207525203e2d
    8f77:	20 70 63 
    8f7a:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    8f7f:	48 b8 6a 76 6d 3a 20 	movabs rax,0x202020203a6d766a
    8f86:	20 20 20 
    8f89:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    8f8d:	66 c7 44 24 20 0a 00 	mov    WORD PTR [rsp+0x20],0xa
    8f94:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    8f99:	31 c9                	xor    ecx,ecx
    8f9b:	48 89 e2             	mov    rdx,rsp
    8f9e:	be 22 00 00 00       	mov    esi,0x22
    8fa3:	bf 05 00 00 00       	mov    edi,0x5
    8fa8:	41 b8 06 00 00 00    	mov    r8d,0x6
    8fae:	41 8b 06             	mov    eax,DWORD PTR [r14]
    8fb1:	c7 04 24 60 00 00 00 	mov    DWORD PTR [rsp],0x60
    8fb8:	0f 38 f1 44 24 04    	movbe  DWORD PTR [rsp+0x4],eax
    8fbe:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
    8fc3:	48 0f 38 f1 44 24 08 	movbe  QWORD PTR [rsp+0x8],rax
    8fca:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 8fd1 <kprobe_unwind_hotspot+0x8fd1>
			8fcd: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    8fd1:	48 89 e6             	mov    rsi,rsp
    8fd4:	b8 01 00 00 00       	mov    eax,0x1
    8fd9:	ff d0                	call   rax
    8fdb:	48 85 c0             	test   rax,rax
    8fde:	74 38                	je     9018 <kprobe_unwind_hotspot+0x9018>
    8fe0:	4c 23 68 08          	and    r13,QWORD PTR [rax+0x8]
    8fe4:	49 39 dd             	cmp    r13,rbx
    8fe7:	75 2f                	jne    9018 <kprobe_unwind_hotspot+0x9018>
    8fe9:	48 83 84 24 a8 00 00 	add    QWORD PTR [rsp+0xa8],0x28
    8ff0:	00 28 
    8ff2:	41 bc 05 00 00 00    	mov    r12d,0x5
    8ff8:	31 c0                	xor    eax,eax
    8ffa:	b9 05 00 00 00       	mov    ecx,0x5
    8fff:	48 8b 15 00 00 00 00 	mov    rdx,QWORD PTR [rip+0x0]        # 9006 <kprobe_unwind_hotspot+0x9006>
			9002: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    9006:	83 3a 00             	cmp    DWORD PTR [rdx],0x0
    9009:	75 3b                	jne    9046 <kprobe_unwind_hotspot+0x9046>
    900b:	4c 8b bc 24 a8 00 00 	mov    r15,QWORD PTR [rsp+0xa8]
    9012:	00 
    9013:	e9 25 01 00 00       	jmp    913d <kprobe_unwind_hotspot+0x913d>
    9018:	c7 84 24 08 01 00 00 	mov    DWORD PTR [rsp+0x108],0x2e
    901f:	2e 00 00 00 
    9023:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 902a <kprobe_unwind_hotspot+0x902a>
			9026: R_X86_64_REX_GOTPCRELX	metrics-0x4
    902a:	48 8d b4 24 08 01 00 	lea    rsi,[rsp+0x108]
    9031:	00 
    9032:	b8 01 00 00 00       	mov    eax,0x1
    9037:	ff d0                	call   rax
    9039:	48 85 c0             	test   rax,rax
    903c:	74 7d                	je     90bb <kprobe_unwind_hotspot+0x90bb>
    903e:	48 ff 00             	inc    QWORD PTR [rax]
    9041:	e9 f0 00 00 00       	jmp    9136 <kprobe_unwind_hotspot+0x9136>
    9046:	48 b8 20 77 6f 72 64 	movabs rax,0xa7364726f7720
    904d:	73 0a 00 
    9050:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    9055:	48 b8 65 20 2b 20 25 	movabs rax,0x77206425202b2065
    905c:	64 20 77 
    905f:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    9064:	48 b8 65 74 65 20 66 	movabs rax,0x6d61726620657465
    906b:	72 61 6d 
    906e:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    9073:	48 b8 6e 67 20 63 6f 	movabs rax,0x6c706d6f6320676e
    907a:	6d 70 6c 
    907d:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    9082:	48 b8 20 75 6e 77 69 	movabs rax,0x69646e69776e7520
    9089:	6e 64 69 
    908c:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    9091:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    9098:	20 2d 3e 
    909b:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    909f:	31 c0                	xor    eax,eax
    90a1:	48 89 e2             	mov    rdx,rsp
    90a4:	be 2e 00 00 00       	mov    esi,0x2e
    90a9:	bf 06 00 00 00       	mov    edi,0x6
    90ae:	4c 8b bc 24 a8 00 00 	mov    r15,QWORD PTR [rsp+0xa8]
    90b5:	00 
    90b6:	e9 82 00 00 00       	jmp    913d <kprobe_unwind_hotspot+0x913d>
    90bb:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 90c2 <kprobe_unwind_hotspot+0x90c2>
			90be: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    90c2:	83 38 00             	cmp    DWORD PTR [rax],0x0
    90c5:	74 6f                	je     9136 <kprobe_unwind_hotspot+0x9136>
    90c7:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    90ce:	64 0a 00 
    90d1:	48 89 44 24 26       	mov    QWORD PTR [rsp+0x26],rax
    90d6:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    90dd:	69 63 49 
    90e0:	48 89 44 24 20       	mov    QWORD PTR [rsp+0x20],rax
    90e5:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    90ec:	66 6f 72 
    90ef:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    90f4:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    90fb:	69 63 73 
    90fe:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
    9103:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    910a:	6b 75 70 
    910d:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    9112:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    9119:	64 20 74 
    911c:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    9120:	8b 84 24 08 01 00 00 	mov    eax,DWORD PTR [rsp+0x108]
    9127:	31 c9                	xor    ecx,ecx
    9129:	48 89 e2             	mov    rdx,rsp
    912c:	be 2e 00 00 00       	mov    esi,0x2e
    9131:	bf 06 00 00 00       	mov    edi,0x6
    9136:	b8 ea 03 00 00       	mov    eax,0x3ea
    913b:	31 c9                	xor    ecx,ecx
    913d:	b2 03                	mov    dl,0x3
    913f:	89 94 24 c8 00 00 00 	mov    DWORD PTR [rsp+0xc8],edx
    9146:	4c 89 bc 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],r15
    914d:	00 
    914e:	85 c0                	test   eax,eax
    9150:	0f 85 dd 71 ff ff    	jne    333 <kprobe_unwind_hotspot+0x333>
    9156:	89 c8                	mov    eax,ecx
    9158:	48 8d 0d 00 00 00 00 	lea    rcx,[rip+0x0]        # 915f <kprobe_unwind_hotspot+0x915f>
			915b: R_X86_64_PC32	.rodata+0xc0
    915f:	48 63 14 81          	movsxd rdx,DWORD PTR [rcx+rax*4]
    9163:	48 01 ca             	add    rdx,rcx
    9166:	b8 01 00 00 00       	mov    eax,0x1
    916b:	ff e2                	jmp    rdx
    916d:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x8
    9174:	08 00 00 00 
    9178:	b8 08 00 00 00       	mov    eax,0x8
    917d:	eb 33                	jmp    91b2 <kprobe_unwind_hotspot+0x91b2>
    917f:	48 8b 8c 24 b0 00 00 	mov    rcx,QWORD PTR [rsp+0xb0]
    9186:	00 
    9187:	eb 08                	jmp    9191 <kprobe_unwind_hotspot+0x9191>
    9189:	48 8b 8c 24 a8 00 00 	mov    rcx,QWORD PTR [rsp+0xa8]
    9190:	00 
    9191:	c7 84 24 f8 00 00 00 	mov    DWORD PTR [rsp+0xf8],0x10
    9198:	10 00 00 00 
    919c:	b8 10 00 00 00       	mov    eax,0x10
    91a1:	48 89 8c 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rcx
    91a8:	00 
    91a9:	eb 07                	jmp    91b2 <kprobe_unwind_hotspot+0x91b2>
    91ab:	8b 84 24 f8 00 00 00 	mov    eax,DWORD PTR [rsp+0xf8]
    91b2:	89 c0                	mov    eax,eax
    91b4:	48 01 84 24 a8 00 00 	add    QWORD PTR [rsp+0xa8],rax
    91bb:	00 
    91bc:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    91c3:	00 
    91c4:	48 8d 50 f0          	lea    rdx,[rax-0x10]
    91c8:	48 89 e7             	mov    rdi,rsp
    91cb:	b8 10 00 00 00       	mov    eax,0x10
    91d0:	b9 70 00 00 00       	mov    ecx,0x70
    91d5:	be 10 00 00 00       	mov    esi,0x10
    91da:	ff d1                	call   rcx
    91dc:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    91e1:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
    91e8:	00 
    91e9:	83 bc 24 f8 00 00 00 	cmp    DWORD PTR [rsp+0xf8],0x10
    91f0:	10 
    91f1:	72 56                	jb     9249 <kprobe_unwind_hotspot+0x9249>
    91f3:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 91fa <kprobe_unwind_hotspot+0x91fa>
			91f6: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    91fa:	83 38 00             	cmp    DWORD PTR [rax],0x0
    91fd:	74 3e                	je     923d <kprobe_unwind_hotspot+0x923d>
    91ff:	48 b8 76 65 72 20 66 	movabs rax,0xa706620726576
    9206:	70 0a 00 
    9209:	48 89 44 24 4d       	mov    QWORD PTR [rsp+0x4d],rax
    920e:	48 b8 20 72 65 63 6f 	movabs rax,0x7265766f63657220
    9215:	76 65 72 
    9218:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    921d:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    9224:	20 2d 3e 
    9227:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    922c:	31 c0                	xor    eax,eax
    922e:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    9233:	ba 15 00 00 00       	mov    edx,0x15
    9238:	be 06 00 00 00       	mov    esi,0x6
    923d:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    9241:	48 89 84 24 b0 00 00 	mov    QWORD PTR [rsp+0xb0],rax
    9248:	00 
    9249:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    9250:	48 83 f8 7e          	cmp    rax,0x7e
    9254:	0f 87 5c 7c ff ff    	ja     eb6 <kprobe_unwind_hotspot+0xeb6>
    925a:	41 0f b6 8e 30 0f 00 	movzx  ecx,BYTE PTR [r14+0xf30]
    9261:	00 
    9262:	0f b6 94 24 c8 00 00 	movzx  edx,BYTE PTR [rsp+0xc8]
    9269:	00 
    926a:	48 c1 e2 3c          	shl    rdx,0x3c
    926e:	48 8b bc 24 20 01 00 	mov    rdi,QWORD PTR [rsp+0x120]
    9275:	00 
    9276:	48 c1 e7 20          	shl    rdi,0x20
    927a:	8b b4 24 c0 00 00 00 	mov    esi,DWORD PTR [rsp+0xc0]
    9281:	48 09 fe             	or     rsi,rdi
    9284:	48 09 d6             	or     rsi,rdx
    9287:	8d 50 01             	lea    edx,[rax+0x1]
    928a:	41 89 96 c0 02 00 00 	mov    DWORD PTR [r14+0x2c0],edx
    9291:	48 8d 04 40          	lea    rax,[rax+rax*2]
    9295:	48 8b 94 24 18 01 00 	mov    rdx,QWORD PTR [rsp+0x118]
    929c:	00 
    929d:	49 89 94 c6 d0 02 00 	mov    QWORD PTR [r14+rax*8+0x2d0],rdx
    92a4:	00 
    92a5:	49 89 b4 c6 d8 02 00 	mov    QWORD PTR [r14+rax*8+0x2d8],rsi
    92ac:	00 
    92ad:	41 c6 84 c6 e0 02 00 	mov    BYTE PTR [r14+rax*8+0x2e0],0x5
    92b4:	00 05 
    92b6:	41 88 8c c6 e1 02 00 	mov    BYTE PTR [r14+rax*8+0x2e1],cl
    92bd:	00 
    92be:	41 c7 84 c6 e2 02 00 	mov    DWORD PTR [r14+rax*8+0x2e2],0x0
    92c5:	00 00 00 00 00 
    92ca:	66 41 c7 84 c6 e6 02 	mov    WORD PTR [r14+rax*8+0x2e6],0x0
    92d1:	00 00 00 00 
    92d5:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 92dc <kprobe_unwind_hotspot+0x92dc>
			92d8: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    92dc:	83 38 00             	cmp    DWORD PTR [rax],0x0
    92df:	74 6b                	je     934c <kprobe_unwind_hotspot+0x934c>
    92e1:	48 b8 78 2c 20 66 70 	movabs rax,0x25203a7066202c78
    92e8:	3a 20 25 
    92eb:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    92f0:	48 b8 2c 20 73 70 3a 	movabs rax,0x6c25203a7073202c
    92f7:	20 25 6c 
    92fa:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    92ff:	48 b8 20 70 63 3a 20 	movabs rax,0x786c25203a637020
    9306:	25 6c 78 
    9309:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    930e:	48 b8 6a 76 6d 3a 20 	movabs rax,0x3e2d20203a6d766a
    9315:	20 2d 3e 
    9318:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    931d:	c7 44 24 60 6c 78 0a 	mov    DWORD PTR [rsp+0x60],0xa786c
    9324:	00 
    9325:	48 8d 44 24 40       	lea    rax,[rsp+0x40]
    932a:	b9 24 00 00 00       	mov    ecx,0x24
    932f:	ba 06 00 00 00       	mov    edx,0x6
    9334:	48 8b b4 24 b0 00 00 	mov    rsi,QWORD PTR [rsp+0xb0]
    933b:	00 
    933c:	48 8b bc 24 b8 00 00 	mov    rdi,QWORD PTR [rsp+0xb8]
    9343:	00 
    9344:	4c 8b 84 24 a8 00 00 	mov    r8,QWORD PTR [rsp+0xa8]
    934b:	00 
    934c:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
    9353:	00 
    9354:	49 89 86 d0 0e 00 00 	mov    QWORD PTR [r14+0xed0],rax
    935b:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
    9362:	00 
    9363:	49 89 86 d8 0e 00 00 	mov    QWORD PTR [r14+0xed8],rax
    936a:	48 8b 84 24 b0 00 00 	mov    rax,QWORD PTR [rsp+0xb0]
    9371:	00 
    9372:	49 89 86 e0 0e 00 00 	mov    QWORD PTR [r14+0xee0],rax
    9379:	41 c6 86 30 0f 00 00 	mov    BYTE PTR [r14+0xf30],0x1
    9380:	01 
    9381:	c7 04 24 2a 00 00 00 	mov    DWORD PTR [rsp],0x2a
    9388:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 938f <kprobe_unwind_hotspot+0x938f>
			938b: R_X86_64_REX_GOTPCRELX	metrics-0x4
    938f:	48 89 e6             	mov    rsi,rsp
    9392:	b8 01 00 00 00       	mov    eax,0x1
    9397:	ff d0                	call   rax
    9399:	48 85 c0             	test   rax,rax
    939c:	74 05                	je     93a3 <kprobe_unwind_hotspot+0x93a3>
    939e:	48 ff 00             	inc    QWORD PTR [rax]
    93a1:	eb 7c                	jmp    941f <kprobe_unwind_hotspot+0x941f>
    93a3:	31 c0                	xor    eax,eax
    93a5:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 93ac <kprobe_unwind_hotspot+0x93ac>
			93a8: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    93ac:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    93af:	74 77                	je     9428 <kprobe_unwind_hotspot+0x9428>
    93b1:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    93b8:	64 0a 00 
    93bb:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    93c0:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    93c7:	69 63 49 
    93ca:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    93cf:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    93d6:	66 6f 72 
    93d9:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    93de:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    93e5:	69 63 73 
    93e8:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    93ed:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    93f4:	6b 75 70 
    93f7:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    93fc:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    9403:	64 20 74 
    9406:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    940b:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    940e:	31 c9                	xor    ecx,ecx
    9410:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    9415:	be 2e 00 00 00       	mov    esi,0x2e
    941a:	bf 06 00 00 00       	mov    edi,0x6
    941f:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 9426 <kprobe_unwind_hotspot+0x9426>
			9422: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    9426:	8b 00                	mov    eax,DWORD PTR [rax]
    9428:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    942f:	4d 85 ed             	test   r13,r13
    9432:	0f 84 e7 8d ff ff    	je     221f <kprobe_unwind_hotspot+0x221f>
    9438:	85 c0                	test   eax,eax
    943a:	74 7e                	je     94ba <kprobe_unwind_hotspot+0x94ba>
    943c:	48 b8 25 64 20 3d 3d 	movabs rax,0xa3d3d3d3d206425
    9443:	3d 3d 0a 
    9446:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    944b:	48 b8 3a 20 66 72 61 	movabs rax,0x20656d617266203a
    9452:	6d 65 20 
    9455:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    945a:	48 b8 75 6e 77 69 6e 	movabs rax,0x7265646e69776e75
    9461:	64 65 72 
    9464:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    9469:	48 b8 74 20 66 72 61 	movabs rax,0x20656d6172662074
    9470:	6d 65 20 
    9473:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    9478:	48 b8 6f 6c 76 65 20 	movabs rax,0x78656e2065766c6f
    947f:	6e 65 78 
    9482:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    9487:	48 b8 3d 3d 3d 3d 20 	movabs rax,0x736552203d3d3d3d
    948e:	52 65 73 
    9491:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    9496:	c6 44 24 70 00       	mov    BYTE PTR [rsp+0x70],0x0
    949b:	41 8b 86 c0 02 00 00 	mov    eax,DWORD PTR [r14+0x2c0]
    94a2:	31 c9                	xor    ecx,ecx
    94a4:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    94a9:	be 31 00 00 00       	mov    esi,0x31
    94ae:	bf 06 00 00 00       	mov    edi,0x6
    94b3:	4d 8b ae d0 0e 00 00 	mov    r13,QWORD PTR [r14+0xed0]
    94ba:	48 b8 ff ff ff ff ff 	movabs rax,0xffffffffffffff
    94c1:	ff ff 00 
    94c4:	49 39 c5             	cmp    r13,rax
    94c7:	0f 87 0d 82 ff ff    	ja     16da <kprobe_unwind_hotspot+0x16da>
    94cd:	49 81 fd 00 10 00 00 	cmp    r13,0x1000
    94d4:	0f 82 af 89 ff ff    	jb     1e89 <kprobe_unwind_hotspot+0x1e89>
    94da:	41 8b 06             	mov    eax,DWORD PTR [r14]
    94dd:	c7 84 24 d0 00 00 00 	mov    DWORD PTR [rsp+0xd0],0x60
    94e4:	60 00 00 00 
    94e8:	0f 38 f1 84 24 d4 00 	movbe  DWORD PTR [rsp+0xd4],eax
    94ef:	00 00 
    94f1:	4c 0f 38 f1 ac 24 d8 	movbe  QWORD PTR [rsp+0xd8],r13
    94f8:	00 00 00 
    94fb:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 9502 <kprobe_unwind_hotspot+0x9502>
			94fe: R_X86_64_REX_GOTPCRELX	pid_page_to_mapping_info-0x4
    9502:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    9509:	00 
    950a:	b8 01 00 00 00       	mov    eax,0x1
    950f:	ff d0                	call   rax
    9511:	48 85 c0             	test   rax,rax
    9514:	0f 84 58 02 00 00    	je     9772 <kprobe_unwind_hotspot+0x9772>
    951a:	48 8b 58 08          	mov    rbx,QWORD PTR [rax+0x8]
    951e:	48 ba ff ff ff ff ff 	movabs rdx,0xffffffffffffff
    9525:	ff ff 00 
    9528:	48 21 da             	and    rdx,rbx
    952b:	49 89 96 20 0f 00 00 	mov    QWORD PTR [r14+0xf20],rdx
    9532:	48 8b 00             	mov    rax,QWORD PTR [rax]
    9535:	49 89 86 10 0f 00 00 	mov    QWORD PTR [r14+0xf10],rax
    953c:	48 c1 eb 38          	shr    rbx,0x38
    9540:	4c 89 e9             	mov    rcx,r13
    9543:	48 29 d1             	sub    rcx,rdx
    9546:	49 89 8e 18 0f 00 00 	mov    QWORD PTR [r14+0xf18],rcx
    954d:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 9554 <kprobe_unwind_hotspot+0x9554>
			9550: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    9554:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    9557:	0f 84 ec 00 00 00    	je     9649 <kprobe_unwind_hotspot+0x9649>
    955d:	48 b9 6e 64 65 72 20 	movabs rcx,0x296425207265646e
    9564:	25 64 29 
    9567:	48 89 4c 24 68       	mov    QWORD PTR [rsp+0x68],rcx
    956c:	48 b9 6c 78 20 28 75 	movabs rcx,0x69776e752820786c
    9573:	6e 77 69 
    9576:	48 89 4c 24 60       	mov    QWORD PTR [rsp+0x60],rcx
    957b:	48 b9 6c 78 20 69 73 	movabs rcx,0x6c2520736920786c
    9582:	20 25 6c 
    9585:	48 89 4c 24 58       	mov    QWORD PTR [rsp+0x58],rcx
    958a:	48 b9 66 6f 72 20 50 	movabs rcx,0x2520435020726f66
    9591:	43 20 25 
    9594:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    9599:	48 b9 74 69 6f 6e 20 	movabs rcx,0x206469206e6f6974
    95a0:	69 64 20 
    95a3:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    95a8:	48 b9 54 65 78 74 20 	movabs rcx,0x6365732074786554
    95af:	73 65 63 
    95b2:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    95b7:	66 c7 44 24 70 0a 00 	mov    WORD PTR [rsp+0x70],0xa
    95be:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    95c3:	be 32 00 00 00       	mov    esi,0x32
    95c8:	bf 06 00 00 00       	mov    edi,0x6
    95cd:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 95d4 <kprobe_unwind_hotspot+0x95d4>
			95d0: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    95d4:	83 38 00             	cmp    DWORD PTR [rax],0x0
    95d7:	74 70                	je     9649 <kprobe_unwind_hotspot+0x9649>
    95d9:	48 b8 73 20 25 6c 6c 	movabs rax,0xa786c6c252073
    95e0:	78 0a 00 
    95e3:	48 89 44 24 67       	mov    QWORD PTR [rsp+0x67],rax
    95e8:	48 b8 66 66 73 65 74 	movabs rax,0x7369207465736666
    95ef:	20 69 73 
    95f2:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    95f7:	48 b8 78 2c 20 61 6e 	movabs rax,0x6f20646e61202c78
    95fe:	64 20 6f 
    9601:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    9606:	48 b8 73 20 69 73 20 	movabs rax,0x6c6c252073692073
    960d:	25 6c 6c 
    9610:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    9615:	48 b8 74 69 6f 6e 20 	movabs rax,0x616962206e6f6974
    961c:	62 69 61 
    961f:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    9624:	48 89 4c 24 40       	mov    QWORD PTR [rsp+0x40],rcx
    9629:	49 8b 86 18 0f 00 00 	mov    rax,QWORD PTR [r14+0xf18]
    9630:	49 8b 8e 20 0f 00 00 	mov    rcx,QWORD PTR [r14+0xf20]
    9637:	31 d2                	xor    edx,edx
    9639:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    963e:	bf 2f 00 00 00       	mov    edi,0x2f
    9643:	41 b8 06 00 00 00    	mov    r8d,0x6
    9649:	83 fb 01             	cmp    ebx,0x1
    964c:	0f 85 e5 6c ff ff    	jne    337 <kprobe_unwind_hotspot+0x337>
    9652:	49 8b 86 10 0f 00 00 	mov    rax,QWORD PTR [r14+0xf10]
    9659:	48 89 84 24 d0 00 00 	mov    QWORD PTR [rsp+0xd0],rax
    9660:	00 
    9661:	4d 8b a6 18 0f 00 00 	mov    r12,QWORD PTR [r14+0xf18]
    9668:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 966f <kprobe_unwind_hotspot+0x966f>
			966b: R_X86_64_REX_GOTPCRELX	interpreter_offsets-0x4
    966f:	48 8d b4 24 d0 00 00 	lea    rsi,[rsp+0xd0]
    9676:	00 
    9677:	b8 01 00 00 00       	mov    eax,0x1
    967c:	ff d0                	call   rax
    967e:	bb 01 00 00 00       	mov    ebx,0x1
    9683:	48 85 c0             	test   rax,rax
    9686:	0f 84 ab 6c ff ff    	je     337 <kprobe_unwind_hotspot+0x337>
    968c:	49 89 c7             	mov    r15,rax
    968f:	4c 39 20             	cmp    QWORD PTR [rax],r12
    9692:	77 06                	ja     969a <kprobe_unwind_hotspot+0x969a>
    9694:	4d 39 67 08          	cmp    QWORD PTR [r15+0x8],r12
    9698:	73 14                	jae    96ae <kprobe_unwind_hotspot+0x96ae>
    969a:	4d 39 67 10          	cmp    QWORD PTR [r15+0x10],r12
    969e:	0f 87 93 6c ff ff    	ja     337 <kprobe_unwind_hotspot+0x337>
    96a4:	4d 39 67 18          	cmp    QWORD PTR [r15+0x18],r12
    96a8:	0f 82 89 6c ff ff    	jb     337 <kprobe_unwind_hotspot+0x337>
    96ae:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 96b5 <kprobe_unwind_hotspot+0x96b5>
			96b1: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    96b5:	83 38 00             	cmp    DWORD PTR [rax],0x0
    96b8:	48 b8 69 6e 74 65 72 	movabs rax,0x6572707265746e69
    96bf:	70 72 65 
    96c2:	74 49                	je     970d <kprobe_unwind_hotspot+0x970d>
    96c4:	48 b9 74 63 68 20 25 	movabs rcx,0xa642520686374
    96cb:	64 0a 00 
    96ce:	48 89 4c 24 56       	mov    QWORD PTR [rsp+0x56],rcx
    96d3:	48 b9 65 74 73 20 6d 	movabs rcx,0x6374616d20737465
    96da:	61 74 63 
    96dd:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    96e2:	48 b9 74 65 72 5f 6f 	movabs rcx,0x7366666f5f726574
    96e9:	66 66 73 
    96ec:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    96f1:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    96f6:	41 0f b7 4f 20       	movzx  ecx,WORD PTR [r15+0x20]
    96fb:	31 d2                	xor    edx,edx
    96fd:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
    9702:	bf 1e 00 00 00       	mov    edi,0x1e
    9707:	41 b8 06 00 00 00    	mov    r8d,0x6
    970d:	41 8b 8e 80 13 00 00 	mov    ecx,DWORD PTR [r14+0x1380]
    9714:	41 8b 57 20          	mov    edx,DWORD PTR [r15+0x20]
    9718:	0f a3 d1             	bt     ecx,edx
    971b:	0f 83 f8 00 00 00    	jae    9819 <kprobe_unwind_hotspot+0x9819>
    9721:	48 8b 0d 00 00 00 00 	mov    rcx,QWORD PTR [rip+0x0]        # 9728 <kprobe_unwind_hotspot+0x9728>
			9724: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    9728:	83 39 00             	cmp    DWORD PTR [rcx],0x0
    972b:	0f 84 06 6c ff ff    	je     337 <kprobe_unwind_hotspot+0x337>
    9731:	48 b9 6e 64 65 72 20 	movabs rcx,0x6e6f64207265646e
    9738:	64 6f 6e 
    973b:	48 89 4c 24 50       	mov    QWORD PTR [rsp+0x50],rcx
    9740:	48 b9 74 65 72 20 75 	movabs rcx,0x69776e7520726574
    9747:	6e 77 69 
    974a:	48 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],rcx
    974f:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    9754:	c7 44 24 57 6e 65 0a 	mov    DWORD PTR [rsp+0x57],0xa656e
    975b:	00 
    975c:	31 c0                	xor    eax,eax
    975e:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    9763:	ba 1b 00 00 00       	mov    edx,0x1b
    9768:	be 06 00 00 00       	mov    esi,0x6
    976d:	e9 c5 6b ff ff       	jmp    337 <kprobe_unwind_hotspot+0x337>
    9772:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 9779 <kprobe_unwind_hotspot+0x9779>
			9775: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    9779:	83 38 00             	cmp    DWORD PTR [rax],0x0
    977c:	75 17                	jne    9795 <kprobe_unwind_hotspot+0x9795>
    977e:	41 c7 86 28 0f 00 00 	mov    DWORD PTR [r14+0xf28],0xc
    9785:	0c 00 00 00 
    9789:	bd ac 0f 00 00       	mov    ebp,0xfac
    978e:	31 db                	xor    ebx,ebx
    9790:	e9 a2 6b ff ff       	jmp    337 <kprobe_unwind_hotspot+0x337>
    9795:	48 b8 43 20 30 78 25 	movabs rax,0xa786c2578302043
    979c:	6c 78 0a 
    979f:	48 89 44 24 70       	mov    QWORD PTR [rsp+0x70],rax
    97a4:	48 b8 6e 67 20 66 6f 	movabs rax,0x5020726f6620676e
    97ab:	72 20 50 
    97ae:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
    97b3:	48 b8 72 79 20 6d 61 	movabs rax,0x697070616d207972
    97ba:	70 70 69 
    97bd:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    97c2:	48 b8 76 61 6c 20 6d 	movabs rax,0x6f6d656d206c6176
    97c9:	65 6d 6f 
    97cc:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    97d1:	48 b8 75 70 20 69 6e 	movabs rax,0x7265746e69207075
    97d8:	74 65 72 
    97db:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    97e0:	48 b8 74 6f 20 6c 6f 	movabs rax,0x206b6f6f6c206f74
    97e7:	6f 6b 20 
    97ea:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    97ef:	48 b8 46 61 69 6c 75 	movabs rax,0x206572756c696146
    97f6:	72 65 20 
    97f9:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    97fe:	c6 44 24 78 00       	mov    BYTE PTR [rsp+0x78],0x0
    9803:	31 c0                	xor    eax,eax
    9805:	48 8d 4c 24 40       	lea    rcx,[rsp+0x40]
    980a:	ba 39 00 00 00       	mov    edx,0x39
    980f:	be 06 00 00 00       	mov    esi,0x6
    9814:	e9 65 ff ff ff       	jmp    977e <kprobe_unwind_hotspot+0x977e>
    9819:	c7 04 24 00 00 00 00 	mov    DWORD PTR [rsp],0x0
    9820:	48 8b 3d 00 00 00 00 	mov    rdi,QWORD PTR [rip+0x0]        # 9827 <kprobe_unwind_hotspot+0x9827>
			9823: R_X86_64_REX_GOTPCRELX	metrics-0x4
    9827:	48 89 e6             	mov    rsi,rsp
    982a:	b8 01 00 00 00       	mov    eax,0x1
    982f:	ff d0                	call   rax
    9831:	48 85 c0             	test   rax,rax
    9834:	74 0d                	je     9843 <kprobe_unwind_hotspot+0x9843>
    9836:	48 ff 00             	inc    QWORD PTR [rax]
    9839:	41 0f b7 5f 20       	movzx  ebx,WORD PTR [r15+0x20]
    983e:	e9 f4 6a ff ff       	jmp    337 <kprobe_unwind_hotspot+0x337>
    9843:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 984a <kprobe_unwind_hotspot+0x984a>
			9846: R_X86_64_REX_GOTPCRELX	with_debug_output-0x4
    984a:	83 38 00             	cmp    DWORD PTR [rax],0x0
    984d:	74 6e                	je     98bd <kprobe_unwind_hotspot+0x98bd>
    984f:	48 b8 63 49 44 20 25 	movabs rax,0xa642520444963
    9856:	64 0a 00 
    9859:	48 89 44 24 66       	mov    QWORD PTR [rsp+0x66],rax
    985e:	48 b8 20 6d 65 74 72 	movabs rax,0x4963697274656d20
    9865:	69 63 49 
    9868:	48 89 44 24 60       	mov    QWORD PTR [rsp+0x60],rax
    986d:	48 b8 20 6d 61 70 20 	movabs rax,0x726f662070616d20
    9874:	66 6f 72 
    9877:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
    987c:	48 b8 20 6d 65 74 72 	movabs rax,0x7363697274656d20
    9883:	69 63 73 
    9886:	48 89 44 24 50       	mov    QWORD PTR [rsp+0x50],rax
    988b:	48 b8 6f 20 6c 6f 6f 	movabs rax,0x70756b6f6f6c206f
    9892:	6b 75 70 
    9895:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    989a:	48 b8 46 61 69 6c 65 	movabs rax,0x742064656c696146
    98a1:	64 20 74 
    98a4:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
    98a9:	8b 04 24             	mov    eax,DWORD PTR [rsp]
    98ac:	31 c9                	xor    ecx,ecx
    98ae:	48 8d 54 24 40       	lea    rdx,[rsp+0x40]
    98b3:	be 2e 00 00 00       	mov    esi,0x2e
    98b8:	bf 06 00 00 00       	mov    edi,0x6
    98bd:	41 0f b7 5f 20       	movzx  ebx,WORD PTR [r15+0x20]
    98c2:	e9 70 6a ff ff       	jmp    337 <kprobe_unwind_hotspot+0x337>

Disassembly of section perf_event/unwind_stop:

Disassembly of section kprobe/unwind_stop:

Disassembly of section perf_event/native_tracer_entry:

Disassembly of section perf_event/unwind_native:

Disassembly of section kprobe/unwind_native:

Disassembly of section tracepoint/sched/sched_switch:

Disassembly of section kprobe/dummy:

Disassembly of section kprobe/finish_task_switch:

Disassembly of section perf_event/unwind_perl:

Disassembly of section kprobe/unwind_perl:

Disassembly of section perf_event/unwind_php:

Disassembly of section kprobe/unwind_php:

Disassembly of section perf_event/unwind_python:

Disassembly of section kprobe/unwind_python:

Disassembly of section perf_event/unwind_ruby:

Disassembly of section kprobe/unwind_ruby:

Disassembly of section tracepoint/sched/sched_process_free/v2:

Disassembly of section tracepoint/sched/sched_process_free/v1:

Disassembly of section tracepoint/syscalls/sys_enter_bpf:

Disassembly of section raw_tracepoint/sys_enter:

Disassembly of section uprobe/generic:

Disassembly of section perf_event/unwind_v8:

Disassembly of section kprobe/unwind_v8:
