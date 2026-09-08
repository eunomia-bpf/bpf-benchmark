# bpftrace_comm_key_fnv_hash

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

0000000000001100 <bpftrace_comm_key_fnv_hash_xdp>:
    1100:	4c 8b 07             	mov    r8,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	4c 89 c2             	mov    rdx,r8
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 ca             	cmp    rdx,rcx
    110f:	76 01                	jbe    1112 <bpftrace_comm_key_fnv_hash_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1116:	48 39 ce             	cmp    rsi,rcx
    1119:	77 f6                	ja     1111 <bpftrace_comm_key_fnv_hash_xdp+0x11>
    111b:	48 8d b2 10 04 00 00 	lea    rsi,[rdx+0x410]
    1122:	48 39 ce             	cmp    rsi,rcx
    1125:	77 ea                	ja     1111 <bpftrace_comm_key_fnv_hash_xdp+0x11>
    1127:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    112b:	75 e4                	jne    1111 <bpftrace_comm_key_fnv_hash_xdp+0x11>
    112d:	83 7a 0c 20          	cmp    DWORD PTR [rdx+0xc],0x20
    1131:	75 de                	jne    1111 <bpftrace_comm_key_fnv_hash_xdp+0x11>
    1133:	55                   	push   rbp
    1134:	41 57                	push   r15
    1136:	41 56                	push   r14
    1138:	41 55                	push   r13
    113a:	41 54                	push   r12
    113c:	53                   	push   rbx
    113d:	48 83 ec 48          	sub    rsp,0x48
    1141:	4c 89 44 24 08       	mov    QWORD PTR [rsp+0x8],r8
    1146:	49 be b3 01 00 00 00 	movabs r14,0x100000001b3
    114d:	01 00 00 
    1150:	48 83 c2 2f          	add    rdx,0x2f
    1154:	49 b8 eb 11 31 13 bb 	movabs r8,0x94d049bb133111eb
    115b:	49 d0 94 
    115e:	31 f6                	xor    esi,esi
    1160:	eb 5b                	jmp    11bd <bpftrace_comm_key_fnv_hash_xdp+0xbd>
    1162:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1169:	1f 84 00 00 00 00 00 
    1170:	c1 e5 08             	shl    ebp,0x8
    1173:	c1 e3 10             	shl    ebx,0x10
    1176:	09 eb                	or     ebx,ebp
    1178:	41 c1 e2 18          	shl    r10d,0x18
    117c:	41 09 da             	or     r10d,ebx
    117f:	41 09 fa             	or     r10d,edi
    1182:	89 f1                	mov    ecx,esi
    1184:	80 e1 07             	and    cl,0x7
    1187:	8d 79 01             	lea    edi,[rcx+0x1]
    118a:	c4 c2 c1 f7 f9       	shlx   rdi,r9,rdi
    118f:	f6 d1                	not    cl
    1191:	c4 c2 f3 f7 c9       	shrx   rcx,r9,rcx
    1196:	48 09 f9             	or     rcx,rdi
    1199:	4c 89 c7             	mov    rdi,r8
    119c:	48 31 cf             	xor    rdi,rcx
    119f:	49 c1 e3 38          	shl    r11,0x38
    11a3:	45 89 d0             	mov    r8d,r10d
    11a6:	4d 09 d8             	or     r8,r11
    11a9:	49 01 f8             	add    r8,rdi
    11ac:	48 ff c6             	inc    rsi
    11af:	48 83 c2 20          	add    rdx,0x20
    11b3:	48 83 fe 20          	cmp    rsi,0x20
    11b7:	0f 84 47 02 00 00    	je     1404 <bpftrace_comm_key_fnv_hash_xdp+0x304>
    11bd:	48 89 74 24 40       	mov    QWORD PTR [rsp+0x40],rsi
    11c2:	44 0f b6 7a e1       	movzx  r15d,BYTE PTR [rdx-0x1f]
    11c7:	44 0f b6 62 e2       	movzx  r12d,BYTE PTR [rdx-0x1e]
    11cc:	0f b6 4a e3          	movzx  ecx,BYTE PTR [rdx-0x1d]
    11d0:	0f b6 7a e4          	movzx  edi,BYTE PTR [rdx-0x1c]
    11d4:	0f b6 6a e5          	movzx  ebp,BYTE PTR [rdx-0x1b]
    11d8:	0f b6 42 e6          	movzx  eax,BYTE PTR [rdx-0x1a]
    11dc:	0f b6 72 e7          	movzx  esi,BYTE PTR [rdx-0x19]
    11e0:	48 89 74 24 38       	mov    QWORD PTR [rsp+0x38],rsi
    11e5:	0f b6 72 e8          	movzx  esi,BYTE PTR [rdx-0x18]
    11e9:	48 89 74 24 30       	mov    QWORD PTR [rsp+0x30],rsi
    11ee:	44 0f b6 6a e9       	movzx  r13d,BYTE PTR [rdx-0x17]
    11f3:	0f b6 72 ea          	movzx  esi,BYTE PTR [rdx-0x16]
    11f7:	0f b6 5a eb          	movzx  ebx,BYTE PTR [rdx-0x15]
    11fb:	44 0f b6 52 ec       	movzx  r10d,BYTE PTR [rdx-0x14]
    1200:	4d 89 f9             	mov    r9,r15
    1203:	49 bb 25 23 22 84 e4 	movabs r11,0xcbf29ce484222325
    120a:	9c f2 cb 
    120d:	4d 31 d9             	xor    r9,r11
    1210:	4d 0f af ce          	imul   r9,r14
    1214:	4c 89 64 24 10       	mov    QWORD PTR [rsp+0x10],r12
    1219:	4d 31 e1             	xor    r9,r12
    121c:	4d 0f af ce          	imul   r9,r14
    1220:	48 89 4c 24 20       	mov    QWORD PTR [rsp+0x20],rcx
    1225:	49 31 c9             	xor    r9,rcx
    1228:	4d 0f af ce          	imul   r9,r14
    122c:	48 89 7c 24 18       	mov    QWORD PTR [rsp+0x18],rdi
    1231:	49 31 f9             	xor    r9,rdi
    1234:	4d 0f af ce          	imul   r9,r14
    1238:	48 89 6c 24 28       	mov    QWORD PTR [rsp+0x28],rbp
    123d:	49 31 e9             	xor    r9,rbp
    1240:	48 8b 7c 24 30       	mov    rdi,QWORD PTR [rsp+0x30]
    1245:	4c 8b 5c 24 38       	mov    r11,QWORD PTR [rsp+0x38]
    124a:	48 89 f5             	mov    rbp,rsi
    124d:	4d 0f af ce          	imul   r9,r14
    1251:	49 31 c1             	xor    r9,rax
    1254:	4d 0f af ce          	imul   r9,r14
    1258:	4c 89 de             	mov    rsi,r11
    125b:	4d 31 d9             	xor    r9,r11
    125e:	4d 0f af ce          	imul   r9,r14
    1262:	49 31 f9             	xor    r9,rdi
    1265:	4d 0f af ce          	imul   r9,r14
    1269:	4c 89 2c 24          	mov    QWORD PTR [rsp],r13
    126d:	4d 31 e9             	xor    r9,r13
    1270:	4d 0f af ce          	imul   r9,r14
    1274:	49 31 e9             	xor    r9,rbp
    1277:	4d 0f af ce          	imul   r9,r14
    127b:	49 31 d9             	xor    r9,rbx
    127e:	4d 0f af ce          	imul   r9,r14
    1282:	4d 89 d3             	mov    r11,r10
    1285:	4d 31 cb             	xor    r11,r9
    1288:	4d 0f af de          	imul   r11,r14
    128c:	44 0f b6 4a f1       	movzx  r9d,BYTE PTR [rdx-0xf]
    1291:	4d 31 d9             	xor    r9,r11
    1294:	4d 0f af ce          	imul   r9,r14
    1298:	44 0f b6 5a f2       	movzx  r11d,BYTE PTR [rdx-0xe]
    129d:	4d 31 cb             	xor    r11,r9
    12a0:	4d 0f af de          	imul   r11,r14
    12a4:	44 0f b6 4a f3       	movzx  r9d,BYTE PTR [rdx-0xd]
    12a9:	4d 31 d9             	xor    r9,r11
    12ac:	4d 0f af ce          	imul   r9,r14
    12b0:	44 0f b6 5a f4       	movzx  r11d,BYTE PTR [rdx-0xc]
    12b5:	4d 31 cb             	xor    r11,r9
    12b8:	4d 0f af de          	imul   r11,r14
    12bc:	44 0f b6 4a f5       	movzx  r9d,BYTE PTR [rdx-0xb]
    12c1:	4d 31 d9             	xor    r9,r11
    12c4:	4d 0f af ce          	imul   r9,r14
    12c8:	44 0f b6 5a f6       	movzx  r11d,BYTE PTR [rdx-0xa]
    12cd:	4d 31 cb             	xor    r11,r9
    12d0:	4d 0f af de          	imul   r11,r14
    12d4:	44 0f b6 4a f7       	movzx  r9d,BYTE PTR [rdx-0x9]
    12d9:	4d 31 d9             	xor    r9,r11
    12dc:	4d 0f af ce          	imul   r9,r14
    12e0:	44 0f b6 5a f8       	movzx  r11d,BYTE PTR [rdx-0x8]
    12e5:	4d 31 cb             	xor    r11,r9
    12e8:	4d 0f af de          	imul   r11,r14
    12ec:	44 0f b6 4a f9       	movzx  r9d,BYTE PTR [rdx-0x7]
    12f1:	4d 31 d9             	xor    r9,r11
    12f4:	4d 0f af ce          	imul   r9,r14
    12f8:	44 0f b6 5a fa       	movzx  r11d,BYTE PTR [rdx-0x6]
    12fd:	4d 31 cb             	xor    r11,r9
    1300:	4d 0f af de          	imul   r11,r14
    1304:	44 0f b6 4a fb       	movzx  r9d,BYTE PTR [rdx-0x5]
    1309:	4d 31 d9             	xor    r9,r11
    130c:	4d 0f af ce          	imul   r9,r14
    1310:	44 0f b6 5a fc       	movzx  r11d,BYTE PTR [rdx-0x4]
    1315:	4d 31 cb             	xor    r11,r9
    1318:	4d 0f af de          	imul   r11,r14
    131c:	44 0f b6 4a fd       	movzx  r9d,BYTE PTR [rdx-0x3]
    1321:	4d 31 d9             	xor    r9,r11
    1324:	4d 0f af ce          	imul   r9,r14
    1328:	44 0f b6 5a fe       	movzx  r11d,BYTE PTR [rdx-0x2]
    132d:	4d 31 cb             	xor    r11,r9
    1330:	4d 0f af de          	imul   r11,r14
    1334:	44 0f b6 6a ff       	movzx  r13d,BYTE PTR [rdx-0x1]
    1339:	4d 31 dd             	xor    r13,r11
    133c:	4d 0f af ee          	imul   r13,r14
    1340:	44 0f b6 0a          	movzx  r9d,BYTE PTR [rdx]
    1344:	4d 31 e9             	xor    r9,r13
    1347:	44 0f b6 5a ed       	movzx  r11d,BYTE PTR [rdx-0x13]
    134c:	4d 0f af ce          	imul   r9,r14
    1350:	41 f6 c3 01          	test   r11b,0x1
    1354:	75 1a                	jne    1370 <bpftrace_comm_key_fnv_hash_xdp+0x270>
    1356:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
    135a:	41 f6 c3 02          	test   r11b,0x2
    135e:	48 8b 74 24 40       	mov    rsi,QWORD PTR [rsp+0x40]
    1363:	0f 84 07 fe ff ff    	je     1170 <bpftrace_comm_key_fnv_hash_xdp+0x70>
    1369:	e9 7c 00 00 00       	jmp    13ea <bpftrace_comm_key_fnv_hash_xdp+0x2ea>
    136e:	66 90                	xchg   ax,ax
    1370:	48 89 c1             	mov    rcx,rax
    1373:	48 89 f8             	mov    rax,rdi
    1376:	c1 e0 18             	shl    eax,0x18
    1379:	c1 e6 10             	shl    esi,0x10
    137c:	49 89 cd             	mov    r13,rcx
    137f:	41 c1 e5 08          	shl    r13d,0x8
    1383:	48 8b 4c 24 20       	mov    rcx,QWORD PTR [rsp+0x20]
    1388:	48 c1 e1 30          	shl    rcx,0x30
    138c:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
    1391:	48 c1 e7 38          	shl    rdi,0x38
    1395:	4c 8b 64 24 10       	mov    r12,QWORD PTR [rsp+0x10]
    139a:	49 c1 e4 28          	shl    r12,0x28
    139e:	49 c1 e7 20          	shl    r15,0x20
    13a2:	4d 09 e7             	or     r15,r12
    13a5:	49 09 cf             	or     r15,rcx
    13a8:	49 09 ff             	or     r15,rdi
    13ab:	4d 09 ef             	or     r15,r13
    13ae:	49 09 f7             	or     r15,rsi
    13b1:	49 09 c7             	or     r15,rax
    13b4:	4c 0b 7c 24 28       	or     r15,QWORD PTR [rsp+0x28]
    13b9:	4c 8b 24 24          	mov    r12,QWORD PTR [rsp]
    13bd:	44 89 e1             	mov    ecx,r12d
    13c0:	80 e1 07             	and    cl,0x7
    13c3:	8d 79 01             	lea    edi,[rcx+0x1]
    13c6:	c4 c2 c1 f7 ff       	shlx   rdi,r15,rdi
    13cb:	f6 d1                	not    cl
    13cd:	c4 c2 f3 f7 cf       	shrx   rcx,r15,rcx
    13d2:	48 09 f9             	or     rcx,rdi
    13d5:	49 31 c9             	xor    r9,rcx
    13d8:	4c 89 e7             	mov    rdi,r12
    13db:	41 f6 c3 02          	test   r11b,0x2
    13df:	48 8b 74 24 40       	mov    rsi,QWORD PTR [rsp+0x40]
    13e4:	0f 84 86 fd ff ff    	je     1170 <bpftrace_comm_key_fnv_hash_xdp+0x70>
    13ea:	48 b9 87 ca eb 85 b1 	movabs rcx,0x9e3779b185ebca87
    13f1:	79 37 9e 
    13f4:	4c 01 c9             	add    rcx,r9
    13f7:	80 7a f1 70          	cmp    BYTE PTR [rdx-0xf],0x70
    13fb:	4c 0f 44 c9          	cmove  r9,rcx
    13ff:	e9 6c fd ff ff       	jmp    1170 <bpftrace_comm_key_fnv_hash_xdp+0x70>
    1404:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    1409:	4c 89 00             	mov    QWORD PTR [rax],r8
    140c:	b8 02 00 00 00       	mov    eax,0x2
    1411:	48 83 c4 48          	add    rsp,0x48
    1415:	5b                   	pop    rbx
    1416:	41 5c                	pop    r12
    1418:	41 5d                	pop    r13
    141a:	41 5e                	pop    r14
    141c:	41 5f                	pop    r15
    141e:	5d                   	pop    rbp
    141f:	c3                   	ret

Disassembly of section .fini:

0000000000001420 <_fini>:
    1420:	f3 0f 1e fa          	endbr64
    1424:	48 83 ec 08          	sub    rsp,0x8
    1428:	48 83 c4 08          	add    rsp,0x8
    142c:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
