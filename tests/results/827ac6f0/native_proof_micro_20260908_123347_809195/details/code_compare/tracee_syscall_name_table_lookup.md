# tracee_syscall_name_table_lookup

## Original C
```c
not captured
```

## Native ASM
```asm
Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 c1 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fc1]        # 3fd0 <__gmon_start__@Base>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 ca 2f 00 00    	push   QWORD PTR [rip+0x2fca]        # 3ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 2f 00 00    	jmp    QWORD PTR [rip+0x2fcc]        # 3ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

Disassembly of section .plt.got:

0000000000001030 <__cxa_finalize@plt>:
    1030:	ff 25 aa 2f 00 00    	jmp    QWORD PTR [rip+0x2faa]        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    1036:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000001040 <deregister_tm_clones>:
    1040:	48 8d 3d c1 2f 00 00 	lea    rdi,[rip+0x2fc1]        # 4008 <completed.0>
    1047:	48 8d 05 ba 2f 00 00 	lea    rax,[rip+0x2fba]        # 4008 <completed.0>
    104e:	48 39 f8             	cmp    rax,rdi
    1051:	74 15                	je     1068 <deregister_tm_clones+0x28>
    1053:	48 8b 05 6e 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f6e]        # 3fc8 <_ITM_deregisterTMCloneTable@Base>
    105a:	48 85 c0             	test   rax,rax
    105d:	74 09                	je     1068 <deregister_tm_clones+0x28>
    105f:	ff e0                	jmp    rax
    1061:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1068:	c3                   	ret
    1069:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001070 <register_tm_clones>:
    1070:	48 8d 3d 91 2f 00 00 	lea    rdi,[rip+0x2f91]        # 4008 <completed.0>
    1077:	48 8d 35 8a 2f 00 00 	lea    rsi,[rip+0x2f8a]        # 4008 <completed.0>
    107e:	48 29 fe             	sub    rsi,rdi
    1081:	48 89 f0             	mov    rax,rsi
    1084:	48 c1 ee 3f          	shr    rsi,0x3f
    1088:	48 c1 f8 03          	sar    rax,0x3
    108c:	48 01 c6             	add    rsi,rax
    108f:	48 d1 fe             	sar    rsi,1
    1092:	74 14                	je     10a8 <register_tm_clones+0x38>
    1094:	48 8b 05 3d 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f3d]        # 3fd8 <_ITM_registerTMCloneTable@Base>
    109b:	48 85 c0             	test   rax,rax
    109e:	74 08                	je     10a8 <register_tm_clones+0x38>
    10a0:	ff e0                	jmp    rax
    10a2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    10a8:	c3                   	ret
    10a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010b0 <__do_global_dtors_aux>:
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	80 3d 4d 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f4d],0x0        # 4008 <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 25 2f 00 00 01 	mov    BYTE PTR [rip+0x2f25],0x1        # 4008 <completed.0>
    10e3:	5d                   	pop    rbp
    10e4:	c3                   	ret
    10e5:	0f 1f 00             	nop    DWORD PTR [rax]
    10e8:	c3                   	ret
    10e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010f0 <frame_dummy>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	e9 77 ff ff ff       	jmp    1070 <register_tm_clones>
    10f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001100 <tracee_syscall_name_table_lookup_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <tracee_syscall_name_table_lookup_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <tracee_syscall_name_table_lookup_xdp+0x11>
    111b:	4c 8d 82 0c 01 00 00 	lea    r8,[rdx+0x10c]
    1122:	49 39 f0             	cmp    r8,rsi
    1125:	77 ea                	ja     1111 <tracee_syscall_name_table_lookup_xdp+0x11>
    1127:	83 3f 40             	cmp    DWORD PTR [rdi],0x40
    112a:	75 e5                	jne    1111 <tracee_syscall_name_table_lookup_xdp+0x11>
    112c:	55                   	push   rbp
    112d:	41 57                	push   r15
    112f:	41 56                	push   r14
    1131:	41 55                	push   r13
    1133:	41 54                	push   r12
    1135:	53                   	push   rbx
    1136:	48 bf 09 c9 bc f3 67 	movabs rdi,0x6a09e667f3bcc909
    113d:	e6 09 6a 
    1140:	49 bd 63 6c 6f 73 65 	movabs r13,0x65736f6c63
    1147:	00 00 00 
    114a:	45 31 c9             	xor    r9d,r9d
    114d:	4d 8d 85 14 06 fa 00 	lea    r8,[r13+0xfa0614]
    1154:	49 be 6f 70 65 6e 61 	movabs r14,0x74616e65706f
    115b:	74 00 00 
    115e:	49 ba 75 6e 6c 69 6e 	movabs r10,0x74616b6e696c6e75
    1165:	6b 61 74 
    1168:	49 bb 73 74 61 74 32 	movabs r11,0x74613274617473
    116f:	61 74 00 
    1172:	48 bb 73 69 67 6e 65 	movabs rbx,0x647466656e676973
    1179:	66 74 64 
    117c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1180:	46 0f b6 7c 8a 0c    	movzx  r15d,BYTE PTR [rdx+r9*4+0xc]
    1186:	42 0f b6 44 8a 0d    	movzx  eax,BYTE PTR [rdx+r9*4+0xd]
    118c:	c1 e0 08             	shl    eax,0x8
    118f:	44 09 f8             	or     eax,r15d
    1192:	46 0f b7 64 8a 0e    	movzx  r12d,WORD PTR [rdx+r9*4+0xe]
    1198:	41 c1 e4 10          	shl    r12d,0x10
    119c:	41 09 c4             	or     r12d,eax
    119f:	41 83 fc 4f          	cmp    r12d,0x4f
    11a3:	7f 3b                	jg     11e0 <tracee_syscall_name_table_lookup_xdp+0xe0>
    11a5:	41 83 fc 26          	cmp    r12d,0x26
    11a9:	0f 8f 81 00 00 00    	jg     1230 <tracee_syscall_name_table_lookup_xdp+0x130>
    11af:	41 83 fc 02          	cmp    r12d,0x2
    11b3:	0f 8f f3 00 00 00    	jg     12ac <tracee_syscall_name_table_lookup_xdp+0x1ac>
    11b9:	45 85 e4             	test   r12d,r12d
    11bc:	0f 84 e4 01 00 00    	je     13a6 <tracee_syscall_name_table_lookup_xdp+0x2a6>
    11c2:	41 83 fc 01          	cmp    r12d,0x1
    11c6:	0f 84 97 01 00 00    	je     1363 <tracee_syscall_name_table_lookup_xdp+0x263>
    11cc:	41 83 fc 02          	cmp    r12d,0x2
    11d0:	0f 85 47 02 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    11d6:	b8 6f 70 65 6e       	mov    eax,0x6e65706f
    11db:	e9 00 02 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    11e0:	41 81 fc 00 01 00 00 	cmp    r12d,0x100
    11e7:	0f 8f 83 00 00 00    	jg     1270 <tracee_syscall_name_table_lookup_xdp+0x170>
    11ed:	41 81 fc 9d 00 00 00 	cmp    r12d,0x9d
    11f4:	0f 8f dd 00 00 00    	jg     12d7 <tracee_syscall_name_table_lookup_xdp+0x1d7>
    11fa:	41 83 fc 50          	cmp    r12d,0x50
    11fe:	0f 84 a9 01 00 00    	je     13ad <tracee_syscall_name_table_lookup_xdp+0x2ad>
    1204:	41 83 fc 57          	cmp    r12d,0x57
    1208:	0f 84 5a 01 00 00    	je     1368 <tracee_syscall_name_table_lookup_xdp+0x268>
    120e:	41 83 fc 59          	cmp    r12d,0x59
    1212:	0f 85 05 02 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    1218:	48 b8 55 6c 69 6e 6b 	movabs rax,0x6b6e696c55
    121f:	00 00 00 
    1222:	e9 b9 01 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1227:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    122e:	00 00 
    1230:	41 83 fc 3a          	cmp    r12d,0x3a
    1234:	0f 8f d3 00 00 00    	jg     130d <tracee_syscall_name_table_lookup_xdp+0x20d>
    123a:	41 83 fc 27          	cmp    r12d,0x27
    123e:	0f 84 70 01 00 00    	je     13b4 <tracee_syscall_name_table_lookup_xdp+0x2b4>
    1244:	41 83 fc 38          	cmp    r12d,0x38
    1248:	0f 84 26 01 00 00    	je     1374 <tracee_syscall_name_table_lookup_xdp+0x274>
    124e:	41 83 fc 39          	cmp    r12d,0x39
    1252:	0f 85 c5 01 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    1258:	b8 66 6f 72 6b       	mov    eax,0x6b726f66
    125d:	e9 7e 01 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1262:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1269:	1f 84 00 00 00 00 00 
    1270:	41 81 fc 22 01 00 00 	cmp    r12d,0x122
    1277:	0f 8f b9 00 00 00    	jg     1336 <tracee_syscall_name_table_lookup_xdp+0x236>
    127d:	41 81 fc 01 01 00 00 	cmp    r12d,0x101
    1284:	0f 84 36 01 00 00    	je     13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    128a:	41 81 fc 07 01 00 00 	cmp    r12d,0x107
    1291:	0f 84 e9 00 00 00    	je     1380 <tracee_syscall_name_table_lookup_xdp+0x280>
    1297:	41 81 fc 19 01 00 00 	cmp    r12d,0x119
    129e:	0f 85 79 01 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    12a4:	4c 89 d8             	mov    rax,r11
    12a7:	e9 34 01 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    12ac:	4c 89 e8             	mov    rax,r13
    12af:	41 83 fc 03          	cmp    r12d,0x3
    12b3:	0f 84 27 01 00 00    	je     13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    12b9:	41 83 fc 09          	cmp    r12d,0x9
    12bd:	0f 84 c2 00 00 00    	je     1385 <tracee_syscall_name_table_lookup_xdp+0x285>
    12c3:	41 83 fc 0c          	cmp    r12d,0xc
    12c7:	0f 85 50 01 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    12cd:	b8 6b 62 72 6b       	mov    eax,0x6b72626b
    12d2:	e9 09 01 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    12d7:	41 81 fc 9e 00 00 00 	cmp    r12d,0x9e
    12de:	0f 84 e1 00 00 00    	je     13c5 <tracee_syscall_name_table_lookup_xdp+0x2c5>
    12e4:	41 81 fc ca 00 00 00 	cmp    r12d,0xca
    12eb:	0f 84 9b 00 00 00    	je     138c <tracee_syscall_name_table_lookup_xdp+0x28c>
    12f1:	41 81 fc d9 00 00 00 	cmp    r12d,0xd9
    12f8:	0f 85 1f 01 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    12fe:	48 b8 67 65 74 61 64 	movabs rax,0x646461746567
    1305:	64 00 00 
    1308:	e9 d3 00 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    130d:	41 83 fc 3b          	cmp    r12d,0x3b
    1311:	0f 84 ba 00 00 00    	je     13d1 <tracee_syscall_name_table_lookup_xdp+0x2d1>
    1317:	41 83 fc 3c          	cmp    r12d,0x3c
    131b:	74 7b                	je     1398 <tracee_syscall_name_table_lookup_xdp+0x298>
    131d:	41 83 fc 3d          	cmp    r12d,0x3d
    1321:	0f 85 f6 00 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    1327:	48 b8 55 77 61 69 74 	movabs rax,0x347469617755
    132e:	34 00 00 
    1331:	e9 aa 00 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1336:	41 81 fc 23 01 00 00 	cmp    r12d,0x123
    133d:	0f 84 9a 00 00 00    	je     13dd <tracee_syscall_name_table_lookup_xdp+0x2dd>
    1343:	41 81 fc 41 01 00 00 	cmp    r12d,0x141
    134a:	74 53                	je     139f <tracee_syscall_name_table_lookup_xdp+0x29f>
    134c:	41 81 fc 4c 01 00 00 	cmp    r12d,0x14c
    1353:	0f 85 c4 00 00 00    	jne    141d <tracee_syscall_name_table_lookup_xdp+0x31d>
    1359:	b8 73 61 74 78       	mov    eax,0x78746173
    135e:	e9 7d 00 00 00       	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1363:	4c 89 c0             	mov    rax,r8
    1366:	eb 78                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1368:	48 b8 75 6e 6c 69 6e 	movabs rax,0x6b6e696c6e75
    136f:	6b 00 00 
    1372:	eb 6c                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1374:	48 b8 55 63 6c 6f 6e 	movabs rax,0x656e6f6c6355
    137b:	65 00 00 
    137e:	eb 60                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1380:	4c 89 d0             	mov    rax,r10
    1383:	eb 5b                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1385:	b8 6d 6d 61 70       	mov    eax,0x70616d6d
    138a:	eb 54                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    138c:	48 b8 55 66 75 74 65 	movabs rax,0x786574756655
    1393:	78 00 00 
    1396:	eb 48                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    1398:	b8 65 78 69 74       	mov    eax,0x74697865
    139d:	eb 41                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    139f:	b8 62 66 70 00       	mov    eax,0x706662
    13a4:	eb 3a                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    13a6:	b8 64 61 65 72       	mov    eax,0x72656164
    13ab:	eb 33                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    13ad:	b8 63 68 64 69       	mov    eax,0x69646863
    13b2:	eb 2c                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    13b4:	48 b8 67 74 70 69 64 	movabs rax,0x6469707467
    13bb:	00 00 00 
    13be:	eb 20                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    13c0:	4c 89 f0             	mov    rax,r14
    13c3:	eb 1b                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    13c5:	48 b8 61 72 63 68 5f 	movabs rax,0x6c74635f68637261
    13cc:	63 74 6c 
    13cf:	eb 0f                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    13d1:	48 b8 65 78 65 63 76 	movabs rax,0x657663657865
    13d8:	65 00 00 
    13db:	eb 03                	jmp    13e0 <tracee_syscall_name_table_lookup_xdp+0x2e0>
    13dd:	48 89 d8             	mov    rax,rbx
    13e0:	45 89 e4             	mov    r12d,r12d
    13e3:	49 31 c4             	xor    r12,rax
    13e6:	44 89 ce             	mov    esi,r9d
    13e9:	83 e6 07             	and    esi,0x7
    13ec:	8d 6e 01             	lea    ebp,[rsi+0x1]
    13ef:	c4 c2 d1 f7 ec       	shlx   rbp,r12,rbp
    13f4:	89 f0                	mov    eax,esi
    13f6:	f6 d0                	not    al
    13f8:	c4 c2 fb f7 c4       	shrx   rax,r12,rax
    13fd:	48 09 e8             	or     rax,rbp
    1400:	48 01 f8             	add    rax,rdi
    1403:	c1 e6 03             	shl    esi,0x3
    1406:	c4 c2 c9 f7 ff       	shlx   rdi,r15,rsi
    140b:	48 31 c7             	xor    rdi,rax
    140e:	49 ff c1             	inc    r9
    1411:	49 83 f9 40          	cmp    r9,0x40
    1415:	0f 85 65 fd ff ff    	jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80>
    141b:	eb 21                	jmp    143e <tracee_syscall_name_table_lookup_xdp+0x33e>
    141d:	44 89 e0             	mov    eax,r12d
    1420:	48 be 87 ca eb 85 b1 	movabs rsi,0x9e3779b185ebca87
    1427:	79 37 9e 
    142a:	48 0f af c6          	imul   rax,rsi
    142e:	48 31 c7             	xor    rdi,rax
    1431:	49 ff c1             	inc    r9
    1434:	49 83 f9 40          	cmp    r9,0x40
    1438:	0f 85 42 fd ff ff    	jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80>
    143e:	48 89 39             	mov    QWORD PTR [rcx],rdi
    1441:	b8 02 00 00 00       	mov    eax,0x2
    1446:	5b                   	pop    rbx
    1447:	41 5c                	pop    r12
    1449:	41 5d                	pop    r13
    144b:	41 5e                	pop    r14
    144d:	41 5f                	pop    r15
    144f:	5d                   	pop    rbp
    1450:	c3                   	ret

Disassembly of section .fini:

0000000000001454 <_fini>:
    1454:	f3 0f 1e fa          	endbr64
    1458:	48 83 ec 08          	sub    rsp,0x8
    145c:	48 83 c4 08          	add    rsp,0x8
    1460:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
