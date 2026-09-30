# tetragon_process_event_arg_filter

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

0000000000001100 <tetragon_process_event_arg_filter_xdp>:
    1100:	4c 8b 07             	mov    r8,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	4c 89 c2             	mov    rdx,r8
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 ca             	cmp    rdx,rcx
    110f:	76 01                	jbe    1112 <tetragon_process_event_arg_filter_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1116:	48 39 ce             	cmp    rsi,rcx
    1119:	77 f6                	ja     1111 <tetragon_process_event_arg_filter_xdp+0x11>
    111b:	48 8d b2 10 04 00 00 	lea    rsi,[rdx+0x410]
    1122:	48 39 ce             	cmp    rsi,rcx
    1125:	77 ea                	ja     1111 <tetragon_process_event_arg_filter_xdp+0x11>
    1127:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    112b:	75 e4                	jne    1111 <tetragon_process_event_arg_filter_xdp+0x11>
    112d:	83 7a 0c 20          	cmp    DWORD PTR [rdx+0xc],0x20
    1131:	75 de                	jne    1111 <tetragon_process_event_arg_filter_xdp+0x11>
    1133:	55                   	push   rbp
    1134:	41 57                	push   r15
    1136:	41 56                	push   r14
    1138:	41 55                	push   r13
    113a:	41 54                	push   r12
    113c:	53                   	push   rbx
    113d:	48 83 ec 40          	sub    rsp,0x40
    1141:	4c 89 44 24 18       	mov    QWORD PTR [rsp+0x18],r8
    1146:	48 83 c2 2f          	add    rdx,0x2f
    114a:	49 b9 db 28 b4 a0 d1 	movabs r9,0xe7037ed1a0b428db
    1151:	7e 03 e7 
    1154:	31 f6                	xor    esi,esi
    1156:	eb 26                	jmp    117e <tetragon_process_event_arg_filter_xdp+0x7e>
    1158:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    115f:	00 
    1160:	49 c1 e2 20          	shl    r10,0x20
    1164:	44 89 c0             	mov    eax,r8d
    1167:	4c 09 d0             	or     rax,r10
    116a:	49 31 c1             	xor    r9,rax
    116d:	48 ff c6             	inc    rsi
    1170:	48 83 c2 20          	add    rdx,0x20
    1174:	48 83 fe 20          	cmp    rsi,0x20
    1178:	0f 84 7e 02 00 00    	je     13fc <tetragon_process_event_arg_filter_xdp+0x2fc>
    117e:	44 0f b6 5a ed       	movzx  r11d,BYTE PTR [rdx-0x13]
    1183:	44 0f b6 52 ee       	movzx  r10d,BYTE PTR [rdx-0x12]
    1188:	41 c1 e2 08          	shl    r10d,0x8
    118c:	4d 09 da             	or     r10,r11
    118f:	41 83 fa 04          	cmp    r10d,0x4
    1193:	7f 1b                	jg     11b0 <tetragon_process_event_arg_filter_xdp+0xb0>
    1195:	41 83 fa 01          	cmp    r10d,0x1
    1199:	74 3f                	je     11da <tetragon_process_event_arg_filter_xdp+0xda>
    119b:	41 83 fa 02          	cmp    r10d,0x2
    119f:	75 23                	jne    11c4 <tetragon_process_event_arg_filter_xdp+0xc4>
    11a1:	41 be 23 00 00 00    	mov    r14d,0x23
    11a7:	eb 47                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    11b0:	41 83 fa 05          	cmp    r10d,0x5
    11b4:	74 2c                	je     11e2 <tetragon_process_event_arg_filter_xdp+0xe2>
    11b6:	41 83 fa 09          	cmp    r10d,0x9
    11ba:	75 08                	jne    11c4 <tetragon_process_event_arg_filter_xdp+0xc4>
    11bc:	41 be 41 00 00 00    	mov    r14d,0x41
    11c2:	eb 2c                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11c4:	66 41 83 fa 0d       	cmp    r10w,0xd
    11c9:	41 be 00 00 00 00    	mov    r14d,0x0
    11cf:	b8 59 00 00 00       	mov    eax,0x59
    11d4:	44 0f 44 f0          	cmove  r14d,eax
    11d8:	eb 16                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11da:	41 be 11 00 00 00    	mov    r14d,0x11
    11e0:	eb 0e                	jmp    11f0 <tetragon_process_event_arg_filter_xdp+0xf0>
    11e2:	41 be 37 00 00 00    	mov    r14d,0x37
    11e8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    11ef:	00 
    11f0:	0f b7 42 f9          	movzx  eax,WORD PTR [rdx-0x7]
    11f4:	0f b6 4a fb          	movzx  ecx,BYTE PTR [rdx-0x5]
    11f8:	c1 e1 10             	shl    ecx,0x10
    11fb:	48 09 c1             	or     rcx,rax
    11fe:	0f b6 42 fc          	movzx  eax,BYTE PTR [rdx-0x4]
    1202:	c1 e0 18             	shl    eax,0x18
    1205:	48 09 c8             	or     rax,rcx
    1208:	0f b6 7a fd          	movzx  edi,BYTE PTR [rdx-0x3]
    120c:	48 c1 e7 20          	shl    rdi,0x20
    1210:	0f b6 6a fe          	movzx  ebp,BYTE PTR [rdx-0x2]
    1214:	48 c1 e5 28          	shl    rbp,0x28
    1218:	48 09 fd             	or     rbp,rdi
    121b:	48 09 c5             	or     rbp,rax
    121e:	48 3d 62 61 73 68    	cmp    rax,0x68736162
    1224:	74 1a                	je     1240 <tetragon_process_event_arg_filter_xdp+0x140>
    1226:	3d 63 75 72 6c       	cmp    eax,0x6c727563
    122b:	75 23                	jne    1250 <tetragon_process_event_arg_filter_xdp+0x150>
    122d:	b8 02 00 00 00       	mov    eax,0x2
    1232:	eb 4c                	jmp    1280 <tetragon_process_event_arg_filter_xdp+0x180>
    1234:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    123b:	00 00 00 00 00 
    1240:	b8 01 00 00 00       	mov    eax,0x1
    1245:	eb 39                	jmp    1280 <tetragon_process_event_arg_filter_xdp+0x180>
    1247:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    124e:	00 00 
    1250:	b8 03 00 00 00       	mov    eax,0x3
    1255:	48 bf 70 79 74 68 6f 	movabs rdi,0x6e6f68747970
    125c:	6e 00 00 
    125f:	48 39 fd             	cmp    rbp,rdi
    1262:	74 1c                	je     1280 <tetragon_process_event_arg_filter_xdp+0x180>
    1264:	31 c0                	xor    eax,eax
    1266:	81 f9 73 68 00 00    	cmp    ecx,0x6873
    126c:	0f 94 c0             	sete   al
    126f:	c1 e0 02             	shl    eax,0x2
    1272:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1279:	1f 84 00 00 00 00 00 
    1280:	44 8b 42 e1          	mov    r8d,DWORD PTR [rdx-0x1f]
    1284:	45 85 f6             	test   r14d,r14d
    1287:	0f 84 d3 fe ff ff    	je     1160 <tetragon_process_event_arg_filter_xdp+0x60>
    128d:	4c 89 5c 24 20       	mov    QWORD PTR [rsp+0x20],r11
    1292:	4c 89 4c 24 08       	mov    QWORD PTR [rsp+0x8],r9
    1297:	0f b6 4a e9          	movzx  ecx,BYTE PTR [rdx-0x17]
    129b:	0f b7 7a ef          	movzx  edi,WORD PTR [rdx-0x11]
    129f:	89 7c 24 04          	mov    DWORD PTR [rsp+0x4],edi
    12a3:	0f b6 7a f1          	movzx  edi,BYTE PTR [rdx-0xf]
    12a7:	48 89 7c 24 28       	mov    QWORD PTR [rsp+0x28],rdi
    12ac:	44 0f b6 7a f2       	movzx  r15d,BYTE PTR [rdx-0xe]
    12b1:	0f b6 7a f3          	movzx  edi,BYTE PTR [rdx-0xd]
    12b5:	89 7c 24 14          	mov    DWORD PTR [rsp+0x14],edi
    12b9:	0f b6 5a f4          	movzx  ebx,BYTE PTR [rdx-0xc]
    12bd:	0f b6 7a f5          	movzx  edi,BYTE PTR [rdx-0xb]
    12c1:	48 89 7c 24 30       	mov    QWORD PTR [rsp+0x30],rdi
    12c6:	44 0f b6 62 f6       	movzx  r12d,BYTE PTR [rdx-0xa]
    12cb:	0f b6 7a f7          	movzx  edi,BYTE PTR [rdx-0x9]
    12cf:	48 89 7c 24 38       	mov    QWORD PTR [rsp+0x38],rdi
    12d4:	44 0f b6 6a f8       	movzx  r13d,BYTE PTR [rdx-0x8]
    12d9:	0f b6 7a ff          	movzx  edi,BYTE PTR [rdx-0x1]
    12dd:	44 0f b6 1a          	movzx  r11d,BYTE PTR [rdx]
    12e1:	44 8b 52 e5          	mov    r10d,DWORD PTR [rdx-0x1b]
    12e5:	80 f9 42             	cmp    cl,0x42
    12e8:	74 46                	je     1330 <tetragon_process_event_arg_filter_xdp+0x230>
    12ea:	45 89 f9             	mov    r9d,r15d
    12ed:	41 83 e1 24          	and    r9d,0x24
    12f1:	75 3d                	jne    1330 <tetragon_process_event_arg_filter_xdp+0x230>
    12f3:	0f b6 42 ea          	movzx  eax,BYTE PTR [rdx-0x16]
    12f7:	c1 e0 08             	shl    eax,0x8
    12fa:	0f b7 7a eb          	movzx  edi,WORD PTR [rdx-0x15]
    12fe:	c1 e7 10             	shl    edi,0x10
    1301:	48 09 c8             	or     rax,rcx
    1304:	48 09 f8             	or     rax,rdi
    1307:	49 c1 e2 10          	shl    r10,0x10
    130b:	49 31 c2             	xor    r10,rax
    130e:	4c 8b 4c 24 08       	mov    r9,QWORD PTR [rsp+0x8]
    1313:	4d 01 d1             	add    r9,r10
    1316:	48 ff c6             	inc    rsi
    1319:	48 83 c2 20          	add    rdx,0x20
    131d:	48 83 fe 20          	cmp    rsi,0x20
    1321:	0f 85 57 fe ff ff    	jne    117e <tetragon_process_event_arg_filter_xdp+0x7e>
    1327:	e9 d0 00 00 00       	jmp    13fc <tetragon_process_event_arg_filter_xdp+0x2fc>
    132c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1330:	49 c1 e6 30          	shl    r14,0x30
    1334:	48 89 c1             	mov    rcx,rax
    1337:	48 c1 e1 28          	shl    rcx,0x28
    133b:	4c 09 f1             	or     rcx,r14
    133e:	44 8b 74 24 04       	mov    r14d,DWORD PTR [rsp+0x4]
    1343:	45 0f b7 ce          	movzx  r9d,r14w
    1347:	49 c1 e1 18          	shl    r9,0x18
    134b:	49 09 c9             	or     r9,rcx
    134e:	45 89 c0             	mov    r8d,r8d
    1351:	4d 09 c8             	or     r8,r9
    1354:	41 f6 c6 02          	test   r14b,0x2
    1358:	74 2f                	je     1389 <tetragon_process_event_arg_filter_xdp+0x289>
    135a:	85 c0                	test   eax,eax
    135c:	74 2b                	je     1389 <tetragon_process_event_arg_filter_xdp+0x289>
    135e:	48 c1 e7 30          	shl    rdi,0x30
    1362:	49 c1 e3 38          	shl    r11,0x38
    1366:	49 09 fb             	or     r11,rdi
    1369:	49 09 eb             	or     r11,rbp
    136c:	48 8b 4c 24 20       	mov    rcx,QWORD PTR [rsp+0x20]
    1371:	80 e1 07             	and    cl,0x7
    1374:	8d 41 01             	lea    eax,[rcx+0x1]
    1377:	c4 c2 f9 f7 c3       	shlx   rax,r11,rax
    137c:	f6 d1                	not    cl
    137e:	c4 c2 f3 f7 cb       	shrx   rcx,r11,rcx
    1383:	48 09 c1             	or     rcx,rax
    1386:	49 31 c8             	xor    r8,rcx
    1389:	4c 8b 4c 24 08       	mov    r9,QWORD PTR [rsp+0x8]
    138e:	41 c1 e7 08          	shl    r15d,0x8
    1392:	4c 03 7c 24 28       	add    r15,QWORD PTR [rsp+0x28]
    1397:	8b 44 24 14          	mov    eax,DWORD PTR [rsp+0x14]
    139b:	c1 e0 10             	shl    eax,0x10
    139e:	c1 e3 18             	shl    ebx,0x18
    13a1:	09 c3                	or     ebx,eax
    13a3:	48 8b 44 24 30       	mov    rax,QWORD PTR [rsp+0x30]
    13a8:	48 c1 e0 20          	shl    rax,0x20
    13ac:	49 c1 e4 28          	shl    r12,0x28
    13b0:	49 09 c4             	or     r12,rax
    13b3:	48 8b 44 24 38       	mov    rax,QWORD PTR [rsp+0x38]
    13b8:	48 c1 e0 30          	shl    rax,0x30
    13bc:	49 c1 e5 38          	shl    r13,0x38
    13c0:	49 09 c5             	or     r13,rax
    13c3:	4c 09 fb             	or     rbx,r15
    13c6:	4c 09 e3             	or     rbx,r12
    13c9:	4c 09 eb             	or     rbx,r13
    13cc:	49 31 da             	xor    r10,rbx
    13cf:	f6 44 24 04 04       	test   BYTE PTR [rsp+0x4],0x4
    13d4:	b8 00 00 00 00       	mov    eax,0x0
    13d9:	49 0f 45 c2          	cmovne rax,r10
    13dd:	4c 01 c0             	add    rax,r8
    13e0:	89 f1                	mov    ecx,esi
    13e2:	80 e1 07             	and    cl,0x7
    13e5:	8d 79 01             	lea    edi,[rcx+0x1]
    13e8:	c4 e2 c1 f7 f8       	shlx   rdi,rax,rdi
    13ed:	f6 d1                	not    cl
    13ef:	c4 e2 f3 f7 c0       	shrx   rax,rax,rcx
    13f4:	48 09 f8             	or     rax,rdi
    13f7:	e9 6e fd ff ff       	jmp    116a <tetragon_process_event_arg_filter_xdp+0x6a>
    13fc:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
    1401:	4c 89 08             	mov    QWORD PTR [rax],r9
    1404:	b8 02 00 00 00       	mov    eax,0x2
    1409:	48 83 c4 40          	add    rsp,0x40
    140d:	5b                   	pop    rbx
    140e:	41 5c                	pop    r12
    1410:	41 5d                	pop    r13
    1412:	41 5e                	pop    r14
    1414:	41 5f                	pop    r15
    1416:	5d                   	pop    rbp
    1417:	c3                   	ret

Disassembly of section .fini:

0000000000001418 <_fini>:
    1418:	f3 0f 1e fa          	endbr64
    141c:	48 83 ec 08          	sub    rsp,0x8
    1420:	48 83 c4 08          	add    rsp,0x8
    1424:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
