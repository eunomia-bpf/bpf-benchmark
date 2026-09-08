# bpf_local_call_fanout_dispatch

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

0000000000001100 <bpf_local_call_fanout_dispatch_xdp>:
    1100:	55                   	push   rbp
    1101:	41 57                	push   r15
    1103:	41 56                	push   r14
    1105:	41 55                	push   r13
    1107:	41 54                	push   r12
    1109:	53                   	push   rbx
    110a:	48 83 ec 18          	sub    rsp,0x18
    110e:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1111:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1115:	49 89 f7             	mov    r15,rsi
    1118:	31 c0                	xor    eax,eax
    111a:	49 39 cf             	cmp    r15,rcx
    111d:	76 0f                	jbe    112e <bpf_local_call_fanout_dispatch_xdp+0x2e>
    111f:	48 83 c4 18          	add    rsp,0x18
    1123:	5b                   	pop    rbx
    1124:	41 5c                	pop    r12
    1126:	41 5d                	pop    r13
    1128:	41 5e                	pop    r14
    112a:	41 5f                	pop    r15
    112c:	5d                   	pop    rbp
    112d:	c3                   	ret
    112e:	49 8d 57 08          	lea    rdx,[r15+0x8]
    1132:	48 89 54 24 08       	mov    QWORD PTR [rsp+0x8],rdx
    1137:	48 39 ca             	cmp    rdx,rcx
    113a:	77 e3                	ja     111f <bpf_local_call_fanout_dispatch_xdp+0x1f>
    113c:	49 8d 97 90 01 00 00 	lea    rdx,[r15+0x190]
    1143:	48 39 ca             	cmp    rdx,rcx
    1146:	77 d7                	ja     111f <bpf_local_call_fanout_dispatch_xdp+0x1f>
    1148:	41 83 7f 08 10       	cmp    DWORD PTR [r15+0x8],0x10
    114d:	75 d0                	jne    111f <bpf_local_call_fanout_dispatch_xdp+0x1f>
    114f:	41 83 7f 0c 18       	cmp    DWORD PTR [r15+0xc],0x18
    1154:	75 c9                	jne    111f <bpf_local_call_fanout_dispatch_xdp+0x1f>
    1156:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
    115b:	48 bf d3 08 a3 85 88 	movabs rdi,0x243f6a8885a308d3
    1162:	6a 3f 24 
    1165:	45 31 e4             	xor    r12d,r12d
    1168:	41 bd 17 00 00 00    	mov    r13d,0x17
    116e:	45 31 f6             	xor    r14d,r14d
    1171:	eb 41                	jmp    11b4 <bpf_local_call_fanout_dispatch_xdp+0xb4>
    1173:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    117a:	84 00 00 00 00 00 
    1180:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
    1185:	89 e9                	mov    ecx,ebp
    1187:	e8 e4 00 00 00       	call   1270 <local_call_pressure>
    118c:	44 89 f1             	mov    ecx,r14d
    118f:	80 e1 38             	and    cl,0x38
    1192:	c4 e2 f1 f7 cb       	shlx   rcx,rbx,rcx
    1197:	89 ef                	mov    edi,ebp
    1199:	48 01 cf             	add    rdi,rcx
    119c:	48 31 c7             	xor    rdi,rax
    119f:	49 83 c6 08          	add    r14,0x8
    11a3:	41 83 c4 10          	add    r12d,0x10
    11a7:	49 83 c5 18          	add    r13,0x18
    11ab:	49 81 fe 80 00 00 00 	cmp    r14,0x80
    11b2:	74 5d                	je     1211 <bpf_local_call_fanout_dispatch_xdp+0x111>
    11b4:	43 0f b6 5c 2f f9    	movzx  ebx,BYTE PTR [r15+r13*1-0x7]
    11ba:	83 e3 03             	and    ebx,0x3
    11bd:	43 8b 6c 2f fd       	mov    ebp,DWORD PTR [r15+r13*1-0x3]
    11c2:	44 31 e5             	xor    ebp,r12d
    11c5:	49 8d 55 f1          	lea    rdx,[r13-0xf]
    11c9:	48 83 fb 02          	cmp    rbx,0x2
    11cd:	74 21                	je     11f0 <bpf_local_call_fanout_dispatch_xdp+0xf0>
    11cf:	83 fb 01             	cmp    ebx,0x1
    11d2:	74 ac                	je     1180 <bpf_local_call_fanout_dispatch_xdp+0x80>
    11d4:	85 db                	test   ebx,ebx
    11d6:	75 28                	jne    1200 <bpf_local_call_fanout_dispatch_xdp+0x100>
    11d8:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
    11dd:	89 e9                	mov    ecx,ebp
    11df:	e8 4c 00 00 00       	call   1230 <local_call_linear>
    11e4:	eb a6                	jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c>
    11e6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    11ed:	00 00 00 
    11f0:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
    11f5:	89 e9                	mov    ecx,ebp
    11f7:	e8 c4 00 00 00       	call   12c0 <local_call_crossload>
    11fc:	eb 8e                	jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c>
    11fe:	66 90                	xchg   ax,ax
    1200:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
    1205:	89 e9                	mov    ecx,ebp
    1207:	e8 34 01 00 00       	call   1340 <local_call_bytes>
    120c:	e9 7b ff ff ff       	jmp    118c <bpf_local_call_fanout_dispatch_xdp+0x8c>
    1211:	48 8b 44 24 10       	mov    rax,QWORD PTR [rsp+0x10]
    1216:	48 89 38             	mov    QWORD PTR [rax],rdi
    1219:	b8 02 00 00 00       	mov    eax,0x2
    121e:	e9 fc fe ff ff       	jmp    111f <bpf_local_call_fanout_dispatch_xdp+0x1f>
    1223:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    122a:	84 00 00 00 00 00 

0000000000001230 <local_call_linear>:
    1230:	89 d2                	mov    edx,edx
    1232:	48 8b 44 32 08       	mov    rax,QWORD PTR [rdx+rsi*1+0x8]
    1237:	4c 8d 04 40          	lea    r8,[rax+rax*2]
    123b:	41 89 c9             	mov    r9d,ecx
    123e:	4c 01 cf             	add    rdi,r9
    1241:	49 01 f8             	add    r8,rdi
    1244:	4c 03 44 32 10       	add    r8,QWORD PTR [rdx+rsi*1+0x10]
    1249:	49 c1 e1 0b          	shl    r9,0xb
    124d:	4d 01 c1             	add    r9,r8
    1250:	83 e1 07             	and    ecx,0x7
    1253:	8d 51 01             	lea    edx,[rcx+0x1]
    1256:	c4 c2 e9 f7 d1       	shlx   rdx,r9,rdx
    125b:	f6 d1                	not    cl
    125d:	c4 c2 f3 f7 c9       	shrx   rcx,r9,rcx
    1262:	48 09 d1             	or     rcx,rdx
    1265:	4c 31 c1             	xor    rcx,r8
    1268:	48 c1 e8 03          	shr    rax,0x3
    126c:	48 01 c8             	add    rax,rcx
    126f:	c3                   	ret

0000000000001270 <local_call_pressure>:
    1270:	89 d0                	mov    eax,edx
    1272:	48 8b 54 30 08       	mov    rdx,QWORD PTR [rax+rsi*1+0x8]
    1277:	48 8b 74 30 10       	mov    rsi,QWORD PTR [rax+rsi*1+0x10]
    127c:	48 31 d7             	xor    rdi,rdx
    127f:	89 c8                	mov    eax,ecx
    1281:	48 c1 e0 11          	shl    rax,0x11
    1285:	48 01 f0             	add    rax,rsi
    1288:	48 8d 0c fd 00 00 00 	lea    rcx,[rdi*8+0x0]
    128f:	00 
    1290:	48 c1 ee 02          	shr    rsi,0x2
    1294:	48 31 ce             	xor    rsi,rcx
    1297:	48 31 c2             	xor    rdx,rax
    129a:	c4 e3 fb f0 ca 3b    	rorx   rcx,rdx,0x3b
    12a0:	48 8d 14 3e          	lea    rdx,[rsi+rdi*1]
    12a4:	c4 e3 fb f0 d2 35    	rorx   rdx,rdx,0x35
    12aa:	48 01 ca             	add    rdx,rcx
    12ad:	48 31 c7             	xor    rdi,rax
    12b0:	48 c1 e8 07          	shr    rax,0x7
    12b4:	48 31 d0             	xor    rax,rdx
    12b7:	48 01 f0             	add    rax,rsi
    12ba:	48 31 f8             	xor    rax,rdi
    12bd:	c3                   	ret
    12be:	66 90                	xchg   ax,ax

00000000000012c0 <local_call_crossload>:
    12c0:	41 89 d3             	mov    r11d,edx
    12c3:	42 0f b6 04 1e       	movzx  eax,BYTE PTR [rsi+r11*1]
    12c8:	4d 8d 43 04          	lea    r8,[r11+0x4]
    12cc:	42 0f b6 54 1e 04    	movzx  edx,BYTE PTR [rsi+r11*1+0x4]
    12d2:	4d 63 d0             	movsxd r10,r8d
    12d5:	46 0f b6 4c 16 01    	movzx  r9d,BYTE PTR [rsi+r10*1+0x1]
    12db:	46 0f b6 44 16 02    	movzx  r8d,BYTE PTR [rsi+r10*1+0x2]
    12e1:	4a 03 7c 1e 08       	add    rdi,QWORD PTR [rsi+r11*1+0x8]
    12e6:	46 0f b6 54 16 03    	movzx  r10d,BYTE PTR [rsi+r10*1+0x3]
    12ec:	4a 8b 74 1e 10       	mov    rsi,QWORD PTR [rsi+r11*1+0x10]
    12f1:	48 31 fe             	xor    rsi,rdi
    12f4:	24 07                	and    al,0x7
    12f6:	44 8d 58 01          	lea    r11d,[rax+0x1]
    12fa:	c4 62 a1 f7 de       	shlx   r11,rsi,r11
    12ff:	89 c9                	mov    ecx,ecx
    1301:	c4 e2 f9 f7 c9       	shlx   rcx,rcx,rax
    1306:	f6 d0                	not    al
    1308:	c4 e2 fb f7 c6       	shrx   rax,rsi,rax
    130d:	4c 09 d8             	or     rax,r11
    1310:	49 c1 e2 21          	shl    r10,0x21
    1314:	49 c1 e0 19          	shl    r8,0x19
    1318:	41 c1 e1 11          	shl    r9d,0x11
    131c:	c1 e2 09             	shl    edx,0x9
    131f:	44 09 ca             	or     edx,r9d
    1322:	4c 09 c2             	or     rdx,r8
    1325:	4c 09 d2             	or     rdx,r10
    1328:	48 31 fa             	xor    rdx,rdi
    132b:	48 31 c2             	xor    rdx,rax
    132e:	48 01 d1             	add    rcx,rdx
    1331:	48 c1 e8 05          	shr    rax,0x5
    1335:	48 31 c8             	xor    rax,rcx
    1338:	48 01 f8             	add    rax,rdi
    133b:	c3                   	ret
    133c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000001340 <local_call_bytes>:
    1340:	89 c8                	mov    eax,ecx
    1342:	89 d1                	mov    ecx,edx
    1344:	0f b6 14 0e          	movzx  edx,BYTE PTR [rsi+rcx*1]
    1348:	49 b8 eb 11 31 13 bb 	movabs r8,0x94d049bb133111eb
    134f:	49 d0 94 
    1352:	49 31 f8             	xor    r8,rdi
    1355:	49 31 d0             	xor    r8,rdx
    1358:	49 01 c0             	add    r8,rax
    135b:	c4 c3 fb f0 d0 3f    	rorx   rdx,r8,0x3f
    1361:	0f b6 7c 0e 01       	movzx  edi,BYTE PTR [rsi+rcx*1+0x1]
    1366:	c1 e7 08             	shl    edi,0x8
    1369:	48 31 d7             	xor    rdi,rdx
    136c:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    1370:	48 ff c2             	inc    rdx
    1373:	c4 e3 fb f0 d2 3e    	rorx   rdx,rdx,0x3e
    1379:	0f b6 7c 0e 02       	movzx  edi,BYTE PTR [rsi+rcx*1+0x2]
    137e:	c1 e7 10             	shl    edi,0x10
    1381:	48 31 d7             	xor    rdi,rdx
    1384:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    1388:	48 83 c2 02          	add    rdx,0x2
    138c:	c4 e3 fb f0 d2 3d    	rorx   rdx,rdx,0x3d
    1392:	0f b6 7c 0e 03       	movzx  edi,BYTE PTR [rsi+rcx*1+0x3]
    1397:	c1 e7 18             	shl    edi,0x18
    139a:	48 31 d7             	xor    rdi,rdx
    139d:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    13a1:	48 83 c2 03          	add    rdx,0x3
    13a5:	c4 e3 fb f0 d2 3c    	rorx   rdx,rdx,0x3c
    13ab:	0f b6 7c 0e 04       	movzx  edi,BYTE PTR [rsi+rcx*1+0x4]
    13b0:	48 c1 e7 20          	shl    rdi,0x20
    13b4:	48 31 d7             	xor    rdi,rdx
    13b7:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    13bb:	48 83 c2 04          	add    rdx,0x4
    13bf:	c4 e3 fb f0 d2 3b    	rorx   rdx,rdx,0x3b
    13c5:	0f b6 7c 0e 05       	movzx  edi,BYTE PTR [rsi+rcx*1+0x5]
    13ca:	48 c1 e7 28          	shl    rdi,0x28
    13ce:	48 31 d7             	xor    rdi,rdx
    13d1:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    13d5:	48 83 c2 05          	add    rdx,0x5
    13d9:	c4 e3 fb f0 d2 3a    	rorx   rdx,rdx,0x3a
    13df:	0f b6 7c 0e 06       	movzx  edi,BYTE PTR [rsi+rcx*1+0x6]
    13e4:	48 c1 e7 30          	shl    rdi,0x30
    13e8:	48 31 d7             	xor    rdi,rdx
    13eb:	48 8d 14 38          	lea    rdx,[rax+rdi*1]
    13ef:	48 83 c2 06          	add    rdx,0x6
    13f3:	c4 e3 fb f0 d2 39    	rorx   rdx,rdx,0x39
    13f9:	0f b6 7c 0e 07       	movzx  edi,BYTE PTR [rsi+rcx*1+0x7]
    13fe:	48 c1 e7 38          	shl    rdi,0x38
    1402:	48 31 d7             	xor    rdi,rdx
    1405:	48 01 f8             	add    rax,rdi
    1408:	48 83 c0 07          	add    rax,0x7
    140c:	c4 e3 fb f0 c0 38    	rorx   rax,rax,0x38
    1412:	48 03 44 0e 08       	add    rax,QWORD PTR [rsi+rcx*1+0x8]
    1417:	48 33 44 0e 10       	xor    rax,QWORD PTR [rsi+rcx*1+0x10]
    141c:	c3                   	ret

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
