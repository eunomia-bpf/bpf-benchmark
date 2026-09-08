# packed_header_bitfield_decode

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

0000000000001100 <packed_header_bitfield_decode_xdp>:
    1100:	4c 8b 07             	mov    r8,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	4c 89 c2             	mov    rdx,r8
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 ca             	cmp    rdx,rcx
    110f:	76 01                	jbe    1112 <packed_header_bitfield_decode_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1116:	48 39 ce             	cmp    rsi,rcx
    1119:	77 f6                	ja     1111 <packed_header_bitfield_decode_xdp+0x11>
    111b:	48 8d b2 10 02 00 00 	lea    rsi,[rdx+0x210]
    1122:	48 39 ce             	cmp    rsi,rcx
    1125:	77 ea                	ja     1111 <packed_header_bitfield_decode_xdp+0x11>
    1127:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    112b:	75 e4                	jne    1111 <packed_header_bitfield_decode_xdp+0x11>
    112d:	83 7a 0c 02          	cmp    DWORD PTR [rdx+0xc],0x2
    1131:	75 de                	jne    1111 <packed_header_bitfield_decode_xdp+0x11>
    1133:	55                   	push   rbp
    1134:	41 57                	push   r15
    1136:	41 56                	push   r14
    1138:	41 55                	push   r13
    113a:	41 54                	push   r12
    113c:	53                   	push   rbx
    113d:	48 83 ec 18          	sub    rsp,0x18
    1141:	4c 89 44 24 10       	mov    QWORD PTR [rsp+0x10],r8
    1146:	48 83 c2 1f          	add    rdx,0x1f
    114a:	48 b8 09 c9 bc f3 67 	movabs rax,0x6a09e667f3bcc909
    1151:	e6 09 6a 
    1154:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    1158:	31 c0                	xor    eax,eax
    115a:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
    115f:	90                   	nop
    1160:	0f b6 7a f1          	movzx  edi,BYTE PTR [rdx-0xf]
    1164:	0f b6 72 f2          	movzx  esi,BYTE PTR [rdx-0xe]
    1168:	41 89 f5             	mov    r13d,esi
    116b:	41 c1 e5 08          	shl    r13d,0x8
    116f:	0f b6 42 f3          	movzx  eax,BYTE PTR [rdx-0xd]
    1173:	c1 e0 10             	shl    eax,0x10
    1176:	44 0f b6 62 f4       	movzx  r12d,BYTE PTR [rdx-0xc]
    117b:	41 c1 e4 18          	shl    r12d,0x18
    117f:	41 09 c4             	or     r12d,eax
    1182:	44 0f b6 42 f5       	movzx  r8d,BYTE PTR [rdx-0xb]
    1187:	49 c1 e0 20          	shl    r8,0x20
    118b:	0f b6 6a f6          	movzx  ebp,BYTE PTR [rdx-0xa]
    118f:	48 c1 e5 28          	shl    rbp,0x28
    1193:	44 0f b6 4a f7       	movzx  r9d,BYTE PTR [rdx-0x9]
    1198:	49 c1 e1 30          	shl    r9,0x30
    119c:	0f b6 42 fc          	movzx  eax,BYTE PTR [rdx-0x4]
    11a0:	c1 e0 18             	shl    eax,0x18
    11a3:	44 0f b6 7a fd       	movzx  r15d,BYTE PTR [rdx-0x3]
    11a8:	49 c1 e7 20          	shl    r15,0x20
    11ac:	0f b6 4a fe          	movzx  ecx,BYTE PTR [rdx-0x2]
    11b0:	48 c1 e1 28          	shl    rcx,0x28
    11b4:	4d 8d 34 0f          	lea    r14,[r15+rcx*1]
    11b8:	49 09 c7             	or     r15,rax
    11bb:	0f b6 42 ff          	movzx  eax,BYTE PTR [rdx-0x1]
    11bf:	48 c1 e0 30          	shl    rax,0x30
    11c3:	44 0f b6 12          	movzx  r10d,BYTE PTR [rdx]
    11c7:	49 c1 e2 38          	shl    r10,0x38
    11cb:	49 09 c2             	or     r10,rax
    11ce:	44 0f b6 5a f8       	movzx  r11d,BYTE PTR [rdx-0x8]
    11d3:	49 c1 e3 38          	shl    r11,0x38
    11d7:	41 09 fd             	or     r13d,edi
    11da:	49 09 e8             	or     r8,rbp
    11dd:	4d 09 cb             	or     r11,r9
    11e0:	49 09 e9             	or     r9,rbp
    11e3:	43 8d 2c 2c          	lea    ebp,[r12+r13*1]
    11e7:	49 09 ca             	or     r10,rcx
    11ea:	89 f9                	mov    ecx,edi
    11ec:	83 e1 3f             	and    ecx,0x3f
    11ef:	41 c1 ed 06          	shr    r13d,0x6
    11f3:	41 83 e5 1f          	and    r13d,0x1f
    11f7:	49 c1 eb 36          	shr    r11,0x36
    11fb:	4c 01 d9             	add    rcx,r11
    11fe:	4c 01 e9             	add    rcx,r13
    1201:	0f b6 42 f9          	movzx  eax,BYTE PTR [rdx-0x7]
    1205:	49 09 e8             	or     r8,rbp
    1208:	c1 ed 0b             	shr    ebp,0xb
    120b:	81 e5 ff 07 00 00    	and    ebp,0x7ff
    1211:	41 c1 ec 16          	shr    r12d,0x16
    1215:	45 0f b6 e4          	movzx  r12d,r12b
    1219:	48 01 e9             	add    rcx,rbp
    121c:	4c 01 e1             	add    rcx,r12
    121f:	44 0f b6 6a fa       	movzx  r13d,BYTE PTR [rdx-0x6]
    1224:	41 c1 e5 08          	shl    r13d,0x8
    1228:	49 c1 e8 1e          	shr    r8,0x1e
    122c:	41 81 e0 ff 3f 00 00 	and    r8d,0x3fff
    1233:	49 c1 e9 2c          	shr    r9,0x2c
    1237:	41 81 e1 ff 03 00 00 	and    r9d,0x3ff
    123e:	4d 01 c1             	add    r9,r8
    1241:	49 01 c9             	add    r9,rcx
    1244:	44 0f b6 62 fb       	movzx  r12d,BYTE PTR [rdx-0x5]
    1249:	41 c1 e4 10          	shl    r12d,0x10
    124d:	45 09 ec             	or     r12d,r13d
    1250:	41 09 c5             	or     r13d,eax
    1253:	83 e0 0f             	and    eax,0xf
    1256:	49 c1 ef 18          	shr    r15,0x18
    125a:	49 c1 ea 28          	shr    r10,0x28
    125e:	d1 ee                	shr    esi,1
    1260:	83 e6 1f             	and    esi,0x1f
    1263:	49 c1 ee 26          	shr    r14,0x26
    1267:	41 83 e6 7f          	and    r14d,0x7f
    126b:	4c 01 f8             	add    rax,r15
    126e:	4c 01 d0             	add    rax,r10
    1271:	41 c1 ec 0c          	shr    r12d,0xc
    1275:	49 01 c4             	add    r12,rax
    1278:	41 c1 ed 04          	shr    r13d,0x4
    127c:	41 0f b6 c5          	movzx  eax,r13b
    1280:	4d 01 f4             	add    r12,r14
    1283:	49 01 c4             	add    r12,rax
    1286:	48 8b 5c 24 08       	mov    rbx,QWORD PTR [rsp+0x8]
    128b:	49 01 dc             	add    r12,rbx
    128e:	49 01 f4             	add    r12,rsi
    1291:	48 8d 0c 6d 00 00 00 	lea    rcx,[rbp*2+0x0]
    1298:	00 
    1299:	48 01 e9             	add    rcx,rbp
    129c:	4c 8d 2c c5 00 00 00 	lea    r13,[rax*8+0x0]
    12a3:	00 
    12a4:	49 29 c5             	sub    r13,rax
    12a7:	4b 8d 04 80          	lea    rax,[r8+r8*4]
    12ab:	49 31 cd             	xor    r13,rcx
    12ae:	49 31 c5             	xor    r13,rax
    12b1:	4b 8d 04 9b          	lea    rax,[r11+r11*4]
    12b5:	49 8d 04 43          	lea    rax,[r11+rax*2]
    12b9:	4b 8d 0c 7f          	lea    rcx,[r15+r15*2]
    12bd:	49 8d 0c 8f          	lea    rcx,[r15+rcx*4]
    12c1:	4f 8d 3c d2          	lea    r15,[r10+r10*8]
    12c5:	49 31 cf             	xor    r15,rcx
    12c8:	89 f1                	mov    ecx,esi
    12ca:	c1 e1 04             	shl    ecx,0x4
    12cd:	48 01 f1             	add    rcx,rsi
    12d0:	48 31 c1             	xor    rcx,rax
    12d3:	4c 31 f9             	xor    rcx,r15
    12d6:	4b 8d 04 f6          	lea    rax,[r14+r14*8]
    12da:	49 8d 04 46          	lea    rax,[r14+rax*2]
    12de:	48 31 c8             	xor    rax,rcx
    12e1:	4c 01 e8             	add    rax,r13
    12e4:	40 80 e7 07          	and    dil,0x7
    12e8:	8d 4f 01             	lea    ecx,[rdi+0x1]
    12eb:	c4 c2 f1 f7 cc       	shlx   rcx,r12,rcx
    12f0:	40 f6 d7             	not    dil
    12f3:	c4 c2 c3 f7 fc       	shrx   rdi,r12,rdi
    12f8:	48 09 cf             	or     rdi,rcx
    12fb:	4c 31 cf             	xor    rdi,r9
    12fe:	48 03 3c 24          	add    rdi,QWORD PTR [rsp]
    1302:	48 31 c7             	xor    rdi,rax
    1305:	49 8d 04 32          	lea    rax,[r10+rsi*1]
    1309:	4c 01 c0             	add    rax,r8
    130c:	48 01 f8             	add    rax,rdi
    130f:	45 31 da             	xor    r10d,r11d
    1312:	41 80 e2 0f          	and    r10b,0xf
    1316:	41 8d 4a 01          	lea    ecx,[r10+0x1]
    131a:	c4 e2 f1 f7 c8       	shlx   rcx,rax,rcx
    131f:	41 f6 d2             	not    r10b
    1322:	c4 e2 ab f7 c0       	shrx   rax,rax,r10
    1327:	48 09 c8             	or     rax,rcx
    132a:	48 89 04 24          	mov    QWORD PTR [rsp],rax
    132e:	48 ff c3             	inc    rbx
    1331:	48 83 c2 10          	add    rdx,0x10
    1335:	48 89 d8             	mov    rax,rbx
    1338:	48 89 5c 24 08       	mov    QWORD PTR [rsp+0x8],rbx
    133d:	48 83 fb 20          	cmp    rbx,0x20
    1341:	0f 85 19 fe ff ff    	jne    1160 <packed_header_bitfield_decode_xdp+0x60>
    1347:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
    134c:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    1350:	88 02                	mov    BYTE PTR [rdx],al
    1352:	88 62 01             	mov    BYTE PTR [rdx+0x1],ah
    1355:	89 c8                	mov    eax,ecx
    1357:	c1 e8 10             	shr    eax,0x10
    135a:	88 42 02             	mov    BYTE PTR [rdx+0x2],al
    135d:	89 c8                	mov    eax,ecx
    135f:	c1 e8 18             	shr    eax,0x18
    1362:	88 42 03             	mov    BYTE PTR [rdx+0x3],al
    1365:	48 89 c8             	mov    rax,rcx
    1368:	48 c1 e8 20          	shr    rax,0x20
    136c:	88 42 04             	mov    BYTE PTR [rdx+0x4],al
    136f:	48 89 c8             	mov    rax,rcx
    1372:	48 c1 e8 28          	shr    rax,0x28
    1376:	88 42 05             	mov    BYTE PTR [rdx+0x5],al
    1379:	48 89 c8             	mov    rax,rcx
    137c:	48 c1 e8 30          	shr    rax,0x30
    1380:	88 42 06             	mov    BYTE PTR [rdx+0x6],al
    1383:	48 c1 e9 38          	shr    rcx,0x38
    1387:	88 4a 07             	mov    BYTE PTR [rdx+0x7],cl
    138a:	b8 02 00 00 00       	mov    eax,0x2
    138f:	48 83 c4 18          	add    rsp,0x18
    1393:	5b                   	pop    rbx
    1394:	41 5c                	pop    r12
    1396:	41 5d                	pop    r13
    1398:	41 5e                	pop    r14
    139a:	41 5f                	pop    r15
    139c:	5d                   	pop    rbp
    139d:	c3                   	ret

Disassembly of section .fini:

00000000000013a0 <_fini>:
    13a0:	f3 0f 1e fa          	endbr64
    13a4:	48 83 ec 08          	sub    rsp,0x8
    13a8:	48 83 c4 08          	add    rsp,0x8
    13ac:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
