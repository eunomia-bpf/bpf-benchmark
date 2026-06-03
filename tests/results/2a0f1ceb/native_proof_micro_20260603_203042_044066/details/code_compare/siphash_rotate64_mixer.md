# siphash_rotate64_mixer

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

0000000000001100 <siphash_rotate64_mixer_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	0f 87 4b 05 00 00    	ja     1660 <siphash_rotate64_mixer_xdp+0x560>
    1115:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1119:	48 39 f7             	cmp    rdi,rsi
    111c:	0f 87 3e 05 00 00    	ja     1660 <siphash_rotate64_mixer_xdp+0x560>
    1122:	48 8d 7a 48          	lea    rdi,[rdx+0x48]
    1126:	48 39 f7             	cmp    rdi,rsi
    1129:	0f 87 31 05 00 00    	ja     1660 <siphash_rotate64_mixer_xdp+0x560>
    112f:	41 57                	push   r15
    1131:	41 56                	push   r14
    1133:	41 54                	push   r12
    1135:	53                   	push   rbx
    1136:	4c 8b 5a 08          	mov    r11,QWORD PTR [rdx+0x8]
    113a:	4c 8b 52 10          	mov    r10,QWORD PTR [rdx+0x10]
    113e:	4c 8b 4a 18          	mov    r9,QWORD PTR [rdx+0x18]
    1142:	4c 8b 42 20          	mov    r8,QWORD PTR [rdx+0x20]
    1146:	48 8b 7a 28          	mov    rdi,QWORD PTR [rdx+0x28]
    114a:	48 8b 72 30          	mov    rsi,QWORD PTR [rdx+0x30]
    114e:	48 8b 42 40          	mov    rax,QWORD PTR [rdx+0x40]
    1152:	48 8b 52 38          	mov    rdx,QWORD PTR [rdx+0x38]
    1156:	48 bb 73 65 74 79 62 	movabs rbx,0x7465646279746573
    115d:	64 65 74 
    1160:	4c 31 db             	xor    rbx,r11
    1163:	49 be 61 72 65 6e 65 	movabs r14,0x6c7967656e657261
    116a:	67 79 6c 
    116d:	49 01 de             	add    r14,rbx
    1170:	c4 63 fb f0 fb 30    	rorx   r15,rbx,0x30
    1176:	4d 31 f7             	xor    r15,r14
    1179:	49 be c6 df de d7 e2 	movabs r14,0xded7d4e2d7dedfc6
    1180:	d4 d7 de 
    1183:	4d 01 fe             	add    r14,r15
    1186:	c4 43 fb f0 ff 2b    	rorx   r15,r15,0x2b
    118c:	4d 31 f7             	xor    r15,r14
    118f:	49 bc d0 ea 9f c1 6f 	movabs r12,0xa60c596fc19fead0
    1196:	59 0c a6 
    1199:	49 01 dc             	add    r12,rbx
    119c:	48 bb 25 73 de f0 74 	movabs rbx,0xe414a674f0de7325
    11a3:	a6 14 e4 
    11a6:	4c 31 e3             	xor    rbx,r12
    11a9:	c4 43 fb f0 e4 20    	rorx   r12,r12,0x20
    11af:	49 01 de             	add    r14,rbx
    11b2:	c4 e3 fb f0 db 33    	rorx   rbx,rbx,0x33
    11b8:	4c 31 f3             	xor    rbx,r14
    11bb:	c4 43 fb f0 f6 20    	rorx   r14,r14,0x20
    11c1:	4d 01 fc             	add    r12,r15
    11c4:	c4 43 fb f0 ff 30    	rorx   r15,r15,0x30
    11ca:	4d 31 e7             	xor    r15,r12
    11cd:	4d 01 fe             	add    r14,r15
    11d0:	c4 43 fb f0 ff 2b    	rorx   r15,r15,0x2b
    11d6:	4d 31 f7             	xor    r15,r14
    11d9:	49 01 dc             	add    r12,rbx
    11dc:	c4 e3 fb f0 db 2f    	rorx   rbx,rbx,0x2f
    11e2:	4c 31 e3             	xor    rbx,r12
    11e5:	c4 43 fb f0 e4 20    	rorx   r12,r12,0x20
    11eb:	4d 31 de             	xor    r14,r11
    11ee:	4d 31 d7             	xor    r15,r10
    11f1:	49 01 de             	add    r14,rbx
    11f4:	c4 63 fb f0 db 33    	rorx   r11,rbx,0x33
    11fa:	4d 31 f3             	xor    r11,r14
    11fd:	c4 c3 fb f0 de 20    	rorx   rbx,r14,0x20
    1203:	4d 01 fc             	add    r12,r15
    1206:	c4 43 fb f0 f7 30    	rorx   r14,r15,0x30
    120c:	4d 31 e6             	xor    r14,r12
    120f:	4c 01 f3             	add    rbx,r14
    1212:	c4 43 fb f0 f6 2b    	rorx   r14,r14,0x2b
    1218:	49 31 de             	xor    r14,rbx
    121b:	4d 01 dc             	add    r12,r11
    121e:	c4 43 fb f0 db 2f    	rorx   r11,r11,0x2f
    1224:	4d 31 e3             	xor    r11,r12
    1227:	c4 43 fb f0 fc 20    	rorx   r15,r12,0x20
    122d:	4c 01 db             	add    rbx,r11
    1230:	c4 43 fb f0 db 33    	rorx   r11,r11,0x33
    1236:	49 31 db             	xor    r11,rbx
    1239:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
    123f:	4d 01 f7             	add    r15,r14
    1242:	c4 43 fb f0 f6 30    	rorx   r14,r14,0x30
    1248:	4d 31 fe             	xor    r14,r15
    124b:	4c 01 f3             	add    rbx,r14
    124e:	c4 43 fb f0 f6 2b    	rorx   r14,r14,0x2b
    1254:	49 31 de             	xor    r14,rbx
    1257:	4d 01 df             	add    r15,r11
    125a:	c4 43 fb f0 db 2f    	rorx   r11,r11,0x2f
    1260:	4d 31 fb             	xor    r11,r15
    1263:	c4 43 fb f0 ff 20    	rorx   r15,r15,0x20
    1269:	4c 31 d3             	xor    rbx,r10
    126c:	4d 31 ce             	xor    r14,r9
    126f:	4c 01 db             	add    rbx,r11
    1272:	c4 43 fb f0 d3 33    	rorx   r10,r11,0x33
    1278:	49 31 da             	xor    r10,rbx
    127b:	c4 63 fb f0 db 20    	rorx   r11,rbx,0x20
    1281:	4d 01 f7             	add    r15,r14
    1284:	c4 c3 fb f0 de 30    	rorx   rbx,r14,0x30
    128a:	4c 31 fb             	xor    rbx,r15
    128d:	49 01 db             	add    r11,rbx
    1290:	c4 e3 fb f0 db 2b    	rorx   rbx,rbx,0x2b
    1296:	4c 31 db             	xor    rbx,r11
    1299:	4d 01 d7             	add    r15,r10
    129c:	c4 43 fb f0 d2 2f    	rorx   r10,r10,0x2f
    12a2:	4d 31 fa             	xor    r10,r15
    12a5:	c4 43 fb f0 f7 20    	rorx   r14,r15,0x20
    12ab:	4d 01 d3             	add    r11,r10
    12ae:	c4 43 fb f0 d2 33    	rorx   r10,r10,0x33
    12b4:	4d 31 da             	xor    r10,r11
    12b7:	c4 43 fb f0 db 20    	rorx   r11,r11,0x20
    12bd:	49 01 de             	add    r14,rbx
    12c0:	c4 e3 fb f0 db 30    	rorx   rbx,rbx,0x30
    12c6:	4c 31 f3             	xor    rbx,r14
    12c9:	49 01 db             	add    r11,rbx
    12cc:	c4 e3 fb f0 db 2b    	rorx   rbx,rbx,0x2b
    12d2:	4c 31 db             	xor    rbx,r11
    12d5:	4d 01 d6             	add    r14,r10
    12d8:	c4 43 fb f0 d2 2f    	rorx   r10,r10,0x2f
    12de:	4d 31 f2             	xor    r10,r14
    12e1:	c4 43 fb f0 f6 20    	rorx   r14,r14,0x20
    12e7:	4d 31 cb             	xor    r11,r9
    12ea:	4c 31 c3             	xor    rbx,r8
    12ed:	4d 01 d3             	add    r11,r10
    12f0:	c4 43 fb f0 ca 33    	rorx   r9,r10,0x33
    12f6:	4d 31 d9             	xor    r9,r11
    12f9:	c4 43 fb f0 d3 20    	rorx   r10,r11,0x20
    12ff:	49 01 de             	add    r14,rbx
    1302:	c4 63 fb f0 db 30    	rorx   r11,rbx,0x30
    1308:	4d 31 f3             	xor    r11,r14
    130b:	4d 01 da             	add    r10,r11
    130e:	c4 43 fb f0 db 2b    	rorx   r11,r11,0x2b
    1314:	4d 31 d3             	xor    r11,r10
    1317:	4d 01 ce             	add    r14,r9
    131a:	c4 43 fb f0 c9 2f    	rorx   r9,r9,0x2f
    1320:	4d 31 f1             	xor    r9,r14
    1323:	c4 c3 fb f0 de 20    	rorx   rbx,r14,0x20
    1329:	4d 01 ca             	add    r10,r9
    132c:	c4 43 fb f0 c9 33    	rorx   r9,r9,0x33
    1332:	4d 31 d1             	xor    r9,r10
    1335:	c4 43 fb f0 d2 20    	rorx   r10,r10,0x20
    133b:	4c 01 db             	add    rbx,r11
    133e:	c4 43 fb f0 db 30    	rorx   r11,r11,0x30
    1344:	49 31 db             	xor    r11,rbx
    1347:	4d 01 da             	add    r10,r11
    134a:	c4 43 fb f0 db 2b    	rorx   r11,r11,0x2b
    1350:	4d 31 d3             	xor    r11,r10
    1353:	4c 01 cb             	add    rbx,r9
    1356:	c4 43 fb f0 c9 2f    	rorx   r9,r9,0x2f
    135c:	49 31 d9             	xor    r9,rbx
    135f:	c4 e3 fb f0 db 20    	rorx   rbx,rbx,0x20
    1365:	4d 31 c2             	xor    r10,r8
    1368:	49 31 fb             	xor    r11,rdi
    136b:	4d 01 ca             	add    r10,r9
    136e:	c4 43 fb f0 c1 33    	rorx   r8,r9,0x33
    1374:	4d 31 d0             	xor    r8,r10
    1377:	c4 43 fb f0 ca 20    	rorx   r9,r10,0x20
    137d:	4c 01 db             	add    rbx,r11
    1380:	c4 43 fb f0 d3 30    	rorx   r10,r11,0x30
    1386:	49 31 da             	xor    r10,rbx
    1389:	4d 01 d1             	add    r9,r10
    138c:	c4 43 fb f0 d2 2b    	rorx   r10,r10,0x2b
    1392:	4d 31 ca             	xor    r10,r9
    1395:	4c 01 c3             	add    rbx,r8
    1398:	c4 43 fb f0 c0 2f    	rorx   r8,r8,0x2f
    139e:	49 31 d8             	xor    r8,rbx
    13a1:	c4 63 fb f0 db 20    	rorx   r11,rbx,0x20
    13a7:	4d 01 c1             	add    r9,r8
    13aa:	c4 43 fb f0 c0 33    	rorx   r8,r8,0x33
    13b0:	4d 31 c8             	xor    r8,r9
    13b3:	c4 43 fb f0 c9 20    	rorx   r9,r9,0x20
    13b9:	4d 01 d3             	add    r11,r10
    13bc:	c4 43 fb f0 d2 30    	rorx   r10,r10,0x30
    13c2:	4d 31 da             	xor    r10,r11
    13c5:	4d 01 d1             	add    r9,r10
    13c8:	c4 43 fb f0 d2 2b    	rorx   r10,r10,0x2b
    13ce:	4d 31 ca             	xor    r10,r9
    13d1:	4d 01 c3             	add    r11,r8
    13d4:	c4 43 fb f0 c0 2f    	rorx   r8,r8,0x2f
    13da:	4d 31 d8             	xor    r8,r11
    13dd:	c4 43 fb f0 db 20    	rorx   r11,r11,0x20
    13e3:	49 31 f9             	xor    r9,rdi
    13e6:	49 31 f2             	xor    r10,rsi
    13e9:	4d 01 c1             	add    r9,r8
    13ec:	c4 c3 fb f0 f8 33    	rorx   rdi,r8,0x33
    13f2:	4c 31 cf             	xor    rdi,r9
    13f5:	c4 43 fb f0 c1 20    	rorx   r8,r9,0x20
    13fb:	4d 01 d3             	add    r11,r10
    13fe:	c4 43 fb f0 ca 30    	rorx   r9,r10,0x30
    1404:	4d 31 d9             	xor    r9,r11
    1407:	4d 01 c8             	add    r8,r9
    140a:	c4 43 fb f0 c9 2b    	rorx   r9,r9,0x2b
    1410:	4d 31 c1             	xor    r9,r8
    1413:	49 01 fb             	add    r11,rdi
    1416:	c4 e3 fb f0 ff 2f    	rorx   rdi,rdi,0x2f
    141c:	4c 31 df             	xor    rdi,r11
    141f:	c4 43 fb f0 d3 20    	rorx   r10,r11,0x20
    1425:	49 01 f8             	add    r8,rdi
    1428:	c4 e3 fb f0 ff 33    	rorx   rdi,rdi,0x33
    142e:	4c 31 c7             	xor    rdi,r8
    1431:	c4 43 fb f0 c0 20    	rorx   r8,r8,0x20
    1437:	4d 01 ca             	add    r10,r9
    143a:	c4 43 fb f0 c9 30    	rorx   r9,r9,0x30
    1440:	4d 31 d1             	xor    r9,r10
    1443:	4d 01 c8             	add    r8,r9
    1446:	c4 43 fb f0 c9 2b    	rorx   r9,r9,0x2b
    144c:	4d 31 c1             	xor    r9,r8
    144f:	49 01 fa             	add    r10,rdi
    1452:	c4 e3 fb f0 ff 2f    	rorx   rdi,rdi,0x2f
    1458:	4c 31 d7             	xor    rdi,r10
    145b:	c4 43 fb f0 d2 20    	rorx   r10,r10,0x20
    1461:	49 31 f0             	xor    r8,rsi
    1464:	49 31 d1             	xor    r9,rdx
    1467:	49 01 f8             	add    r8,rdi
    146a:	c4 e3 fb f0 f7 33    	rorx   rsi,rdi,0x33
    1470:	4c 31 c6             	xor    rsi,r8
    1473:	c4 c3 fb f0 f8 20    	rorx   rdi,r8,0x20
    1479:	4d 01 ca             	add    r10,r9
    147c:	c4 43 fb f0 c1 30    	rorx   r8,r9,0x30
    1482:	4d 31 d0             	xor    r8,r10
    1485:	4c 01 c7             	add    rdi,r8
    1488:	c4 43 fb f0 c0 2b    	rorx   r8,r8,0x2b
    148e:	49 31 f8             	xor    r8,rdi
    1491:	49 01 f2             	add    r10,rsi
    1494:	c4 e3 fb f0 f6 2f    	rorx   rsi,rsi,0x2f
    149a:	4c 31 d6             	xor    rsi,r10
    149d:	c4 43 fb f0 ca 20    	rorx   r9,r10,0x20
    14a3:	48 01 f7             	add    rdi,rsi
    14a6:	c4 e3 fb f0 f6 33    	rorx   rsi,rsi,0x33
    14ac:	48 31 fe             	xor    rsi,rdi
    14af:	c4 e3 fb f0 ff 20    	rorx   rdi,rdi,0x20
    14b5:	4d 01 c1             	add    r9,r8
    14b8:	c4 43 fb f0 c0 30    	rorx   r8,r8,0x30
    14be:	4d 31 c8             	xor    r8,r9
    14c1:	4c 01 c7             	add    rdi,r8
    14c4:	c4 43 fb f0 c0 2b    	rorx   r8,r8,0x2b
    14ca:	49 31 f8             	xor    r8,rdi
    14cd:	49 01 f1             	add    r9,rsi
    14d0:	c4 e3 fb f0 f6 2f    	rorx   rsi,rsi,0x2f
    14d6:	4c 31 ce             	xor    rsi,r9
    14d9:	c4 43 fb f0 c9 20    	rorx   r9,r9,0x20
    14df:	48 31 d7             	xor    rdi,rdx
    14e2:	49 31 c0             	xor    r8,rax
    14e5:	48 01 f7             	add    rdi,rsi
    14e8:	c4 e3 fb f0 d6 33    	rorx   rdx,rsi,0x33
    14ee:	48 31 fa             	xor    rdx,rdi
    14f1:	c4 e3 fb f0 f7 20    	rorx   rsi,rdi,0x20
    14f7:	4d 01 c1             	add    r9,r8
    14fa:	c4 c3 fb f0 f8 30    	rorx   rdi,r8,0x30
    1500:	4c 31 cf             	xor    rdi,r9
    1503:	48 01 fe             	add    rsi,rdi
    1506:	c4 e3 fb f0 ff 2b    	rorx   rdi,rdi,0x2b
    150c:	48 31 f7             	xor    rdi,rsi
    150f:	49 01 d1             	add    r9,rdx
    1512:	c4 e3 fb f0 d2 2f    	rorx   rdx,rdx,0x2f
    1518:	4c 31 ca             	xor    rdx,r9
    151b:	c4 43 fb f0 c1 20    	rorx   r8,r9,0x20
    1521:	48 01 d6             	add    rsi,rdx
    1524:	c4 e3 fb f0 d2 33    	rorx   rdx,rdx,0x33
    152a:	48 31 f2             	xor    rdx,rsi
    152d:	c4 e3 fb f0 f6 20    	rorx   rsi,rsi,0x20
    1533:	49 01 f8             	add    r8,rdi
    1536:	c4 e3 fb f0 ff 30    	rorx   rdi,rdi,0x30
    153c:	4c 31 c7             	xor    rdi,r8
    153f:	48 01 fe             	add    rsi,rdi
    1542:	c4 e3 fb f0 ff 2b    	rorx   rdi,rdi,0x2b
    1548:	48 31 f7             	xor    rdi,rsi
    154b:	49 01 d0             	add    r8,rdx
    154e:	c4 e3 fb f0 d2 2f    	rorx   rdx,rdx,0x2f
    1554:	4c 31 c2             	xor    rdx,r8
    1557:	c4 43 fb f0 c0 20    	rorx   r8,r8,0x20
    155d:	48 31 c6             	xor    rsi,rax
    1560:	49 81 f0 ff 00 00 00 	xor    r8,0xff
    1567:	48 01 d6             	add    rsi,rdx
    156a:	c4 e3 fb f0 c2 33    	rorx   rax,rdx,0x33
    1570:	48 31 f0             	xor    rax,rsi
    1573:	c4 e3 fb f0 d6 20    	rorx   rdx,rsi,0x20
    1579:	49 01 f8             	add    r8,rdi
    157c:	c4 e3 fb f0 f7 30    	rorx   rsi,rdi,0x30
    1582:	4c 31 c6             	xor    rsi,r8
    1585:	48 01 f2             	add    rdx,rsi
    1588:	c4 e3 fb f0 f6 2b    	rorx   rsi,rsi,0x2b
    158e:	48 31 d6             	xor    rsi,rdx
    1591:	49 01 c0             	add    r8,rax
    1594:	c4 e3 fb f0 c0 2f    	rorx   rax,rax,0x2f
    159a:	4c 31 c0             	xor    rax,r8
    159d:	c4 c3 fb f0 f8 20    	rorx   rdi,r8,0x20
    15a3:	48 01 c2             	add    rdx,rax
    15a6:	c4 e3 fb f0 c0 33    	rorx   rax,rax,0x33
    15ac:	48 31 d0             	xor    rax,rdx
    15af:	c4 e3 fb f0 d2 20    	rorx   rdx,rdx,0x20
    15b5:	48 01 f7             	add    rdi,rsi
    15b8:	c4 e3 fb f0 f6 30    	rorx   rsi,rsi,0x30
    15be:	48 31 fe             	xor    rsi,rdi
    15c1:	48 01 f2             	add    rdx,rsi
    15c4:	c4 e3 fb f0 f6 2b    	rorx   rsi,rsi,0x2b
    15ca:	48 31 d6             	xor    rsi,rdx
    15cd:	48 01 c7             	add    rdi,rax
    15d0:	c4 e3 fb f0 c0 2f    	rorx   rax,rax,0x2f
    15d6:	48 31 f8             	xor    rax,rdi
    15d9:	c4 e3 fb f0 ff 20    	rorx   rdi,rdi,0x20
    15df:	48 01 c2             	add    rdx,rax
    15e2:	c4 e3 fb f0 c0 33    	rorx   rax,rax,0x33
    15e8:	48 31 d0             	xor    rax,rdx
    15eb:	c4 e3 fb f0 d2 20    	rorx   rdx,rdx,0x20
    15f1:	48 01 f7             	add    rdi,rsi
    15f4:	c4 e3 fb f0 f6 30    	rorx   rsi,rsi,0x30
    15fa:	48 31 fe             	xor    rsi,rdi
    15fd:	48 01 f2             	add    rdx,rsi
    1600:	c4 e3 fb f0 f6 2b    	rorx   rsi,rsi,0x2b
    1606:	48 31 d6             	xor    rsi,rdx
    1609:	48 01 c7             	add    rdi,rax
    160c:	c4 e3 fb f0 c0 2f    	rorx   rax,rax,0x2f
    1612:	48 31 f8             	xor    rax,rdi
    1615:	c4 e3 fb f0 ff 20    	rorx   rdi,rdi,0x20
    161b:	48 01 c2             	add    rdx,rax
    161e:	c4 e3 fb f0 c0 33    	rorx   rax,rax,0x33
    1624:	48 31 d0             	xor    rax,rdx
    1627:	48 01 f7             	add    rdi,rsi
    162a:	c4 e3 fb f0 d6 30    	rorx   rdx,rsi,0x30
    1630:	48 31 fa             	xor    rdx,rdi
    1633:	c4 e3 fb f0 d2 2b    	rorx   rdx,rdx,0x2b
    1639:	48 01 c7             	add    rdi,rax
    163c:	c4 e3 fb f0 c0 2f    	rorx   rax,rax,0x2f
    1642:	48 31 d0             	xor    rax,rdx
    1645:	c4 e3 fb f0 d7 20    	rorx   rdx,rdi,0x20
    164b:	48 31 fa             	xor    rdx,rdi
    164e:	48 31 c2             	xor    rdx,rax
    1651:	48 89 11             	mov    QWORD PTR [rcx],rdx
    1654:	b8 02 00 00 00       	mov    eax,0x2
    1659:	5b                   	pop    rbx
    165a:	41 5c                	pop    r12
    165c:	41 5e                	pop    r14
    165e:	41 5f                	pop    r15
    1660:	c3                   	ret

Disassembly of section .fini:

0000000000001664 <_fini>:
    1664:	f3 0f 1e fa          	endbr64
    1668:	48 83 ec 08          	sub    rsp,0x8
    166c:	48 83 c4 08          	add    rsp,0x8
    1670:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
