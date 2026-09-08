# trace_event_type_switch_dispatch

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

0000000000001100 <trace_event_type_switch_dispatch_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <trace_event_type_switch_dispatch_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <trace_event_type_switch_dispatch_xdp+0x11>
    111b:	4c 8d 82 0c 02 00 00 	lea    r8,[rdx+0x20c]
    1122:	49 39 f0             	cmp    r8,rsi
    1125:	77 ea                	ja     1111 <trace_event_type_switch_dispatch_xdp+0x11>
    1127:	81 3f 80 00 00 00    	cmp    DWORD PTR [rdi],0x80
    112d:	75 e2                	jne    1111 <trace_event_type_switch_dispatch_xdp+0x11>
    112f:	53                   	push   rbx
    1130:	31 f6                	xor    esi,esi
    1132:	31 db                	xor    ebx,ebx
    1134:	eb 1d                	jmp    1153 <trace_event_type_switch_dispatch_xdp+0x53>
    1136:	bb 0c 00 00 00       	mov    ebx,0xc
    113b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1140:	48 31 c3             	xor    rbx,rax
    1143:	48 ff c6             	inc    rsi
    1146:	48 81 fe 80 00 00 00 	cmp    rsi,0x80
    114d:	0f 84 d7 05 00 00    	je     172a <trace_event_type_switch_dispatch_xdp+0x62a>
    1153:	48 89 d8             	mov    rax,rbx
    1156:	8b 7c b2 0c          	mov    edi,DWORD PTR [rdx+rsi*4+0xc]
    115a:	83 ff 1f             	cmp    edi,0x1f
    115d:	7f 41                	jg     11a0 <trace_event_type_switch_dispatch_xdp+0xa0>
    115f:	83 ff 0f             	cmp    edi,0xf
    1162:	7f 7c                	jg     11e0 <trace_event_type_switch_dispatch_xdp+0xe0>
    1164:	83 ff 07             	cmp    edi,0x7
    1167:	0f 8f e7 00 00 00    	jg     1254 <trace_event_type_switch_dispatch_xdp+0x154>
    116d:	83 ff 03             	cmp    edi,0x3
    1170:	0f 8f 96 01 00 00    	jg     130c <trace_event_type_switch_dispatch_xdp+0x20c>
    1176:	83 ff 01             	cmp    edi,0x1
    1179:	0f 8f b5 02 00 00    	jg     1434 <trace_event_type_switch_dispatch_xdp+0x334>
    117f:	bb 38 00 00 00       	mov    ebx,0x38
    1184:	85 ff                	test   edi,edi
    1186:	74 b8                	je     1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1188:	83 ff 01             	cmp    edi,0x1
    118b:	0f 85 8f 05 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1191:	bb 2b 00 00 00       	mov    ebx,0x2b
    1196:	eb a8                	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1198:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    119f:	00 
    11a0:	83 ff 2f             	cmp    edi,0x2f
    11a3:	7f 7b                	jg     1220 <trace_event_type_switch_dispatch_xdp+0x120>
    11a5:	83 ff 27             	cmp    edi,0x27
    11a8:	0f 8f d4 00 00 00    	jg     1282 <trace_event_type_switch_dispatch_xdp+0x182>
    11ae:	83 ff 23             	cmp    edi,0x23
    11b1:	0f 8f 7a 01 00 00    	jg     1331 <trace_event_type_switch_dispatch_xdp+0x231>
    11b7:	83 ff 21             	cmp    edi,0x21
    11ba:	0f 8f 90 02 00 00    	jg     1450 <trace_event_type_switch_dispatch_xdp+0x350>
    11c0:	83 ff 20             	cmp    edi,0x20
    11c3:	0f 84 2b 04 00 00    	je     15f4 <trace_event_type_switch_dispatch_xdp+0x4f4>
    11c9:	83 ff 21             	cmp    edi,0x21
    11cc:	0f 85 4e 05 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    11d2:	bb 27 00 00 00       	mov    ebx,0x27
    11d7:	e9 64 ff ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    11dc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    11e0:	83 ff 17             	cmp    edi,0x17
    11e3:	0f 8f c7 00 00 00    	jg     12b0 <trace_event_type_switch_dispatch_xdp+0x1b0>
    11e9:	83 ff 13             	cmp    edi,0x13
    11ec:	0f 8f 64 01 00 00    	jg     1356 <trace_event_type_switch_dispatch_xdp+0x256>
    11f2:	83 ff 11             	cmp    edi,0x11
    11f5:	0f 8f 71 02 00 00    	jg     146c <trace_event_type_switch_dispatch_xdp+0x36c>
    11fb:	83 ff 10             	cmp    edi,0x10
    11fe:	0f 84 fa 03 00 00    	je     15fe <trace_event_type_switch_dispatch_xdp+0x4fe>
    1204:	83 ff 11             	cmp    edi,0x11
    1207:	0f 85 13 05 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    120d:	bb 3e 00 00 00       	mov    ebx,0x3e
    1212:	e9 29 ff ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1217:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    121e:	00 00 
    1220:	83 ff 37             	cmp    edi,0x37
    1223:	0f 8f b5 00 00 00    	jg     12de <trace_event_type_switch_dispatch_xdp+0x1de>
    1229:	83 ff 33             	cmp    edi,0x33
    122c:	0f 8f 49 01 00 00    	jg     137b <trace_event_type_switch_dispatch_xdp+0x27b>
    1232:	83 ff 31             	cmp    edi,0x31
    1235:	0f 8f 4d 02 00 00    	jg     1488 <trace_event_type_switch_dispatch_xdp+0x388>
    123b:	83 ff 30             	cmp    edi,0x30
    123e:	0f 84 c4 03 00 00    	je     1608 <trace_event_type_switch_dispatch_xdp+0x508>
    1244:	83 ff 31             	cmp    edi,0x31
    1247:	0f 85 d3 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    124d:	31 db                	xor    ebx,ebx
    124f:	e9 ec fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1254:	83 ff 0b             	cmp    edi,0xb
    1257:	0f 8f 43 01 00 00    	jg     13a0 <trace_event_type_switch_dispatch_xdp+0x2a0>
    125d:	83 ff 09             	cmp    edi,0x9
    1260:	0f 8f 3e 02 00 00    	jg     14a4 <trace_event_type_switch_dispatch_xdp+0x3a4>
    1266:	83 ff 08             	cmp    edi,0x8
    1269:	0f 84 a3 03 00 00    	je     1612 <trace_event_type_switch_dispatch_xdp+0x512>
    126f:	83 ff 09             	cmp    edi,0x9
    1272:	0f 85 a8 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1278:	bb 3f 00 00 00       	mov    ebx,0x3f
    127d:	e9 be fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1282:	83 ff 2b             	cmp    edi,0x2b
    1285:	0f 8f 3a 01 00 00    	jg     13c5 <trace_event_type_switch_dispatch_xdp+0x2c5>
    128b:	83 ff 29             	cmp    edi,0x29
    128e:	0f 8f 2c 02 00 00    	jg     14c0 <trace_event_type_switch_dispatch_xdp+0x3c0>
    1294:	83 ff 28             	cmp    edi,0x28
    1297:	0f 84 7f 03 00 00    	je     161c <trace_event_type_switch_dispatch_xdp+0x51c>
    129d:	83 ff 29             	cmp    edi,0x29
    12a0:	0f 85 7a 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    12a6:	bb 32 00 00 00       	mov    ebx,0x32
    12ab:	e9 90 fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    12b0:	83 ff 1b             	cmp    edi,0x1b
    12b3:	0f 8f 31 01 00 00    	jg     13ea <trace_event_type_switch_dispatch_xdp+0x2ea>
    12b9:	83 ff 19             	cmp    edi,0x19
    12bc:	0f 8f 1a 02 00 00    	jg     14dc <trace_event_type_switch_dispatch_xdp+0x3dc>
    12c2:	83 ff 18             	cmp    edi,0x18
    12c5:	0f 84 5b 03 00 00    	je     1626 <trace_event_type_switch_dispatch_xdp+0x526>
    12cb:	83 ff 19             	cmp    edi,0x19
    12ce:	0f 85 4c 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    12d4:	bb 1a 00 00 00       	mov    ebx,0x1a
    12d9:	e9 62 fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    12de:	83 ff 3b             	cmp    edi,0x3b
    12e1:	0f 8f 28 01 00 00    	jg     140f <trace_event_type_switch_dispatch_xdp+0x30f>
    12e7:	83 ff 39             	cmp    edi,0x39
    12ea:	0f 8f 08 02 00 00    	jg     14f8 <trace_event_type_switch_dispatch_xdp+0x3f8>
    12f0:	83 ff 38             	cmp    edi,0x38
    12f3:	0f 84 37 03 00 00    	je     1630 <trace_event_type_switch_dispatch_xdp+0x530>
    12f9:	83 ff 39             	cmp    edi,0x39
    12fc:	0f 85 1e 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1302:	bb 36 00 00 00       	mov    ebx,0x36
    1307:	e9 34 fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    130c:	83 ff 05             	cmp    edi,0x5
    130f:	0f 8f ff 01 00 00    	jg     1514 <trace_event_type_switch_dispatch_xdp+0x414>
    1315:	83 ff 04             	cmp    edi,0x4
    1318:	0f 84 1c 03 00 00    	je     163a <trace_event_type_switch_dispatch_xdp+0x53a>
    131e:	83 ff 05             	cmp    edi,0x5
    1321:	0f 85 f9 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1327:	bb 3d 00 00 00       	mov    ebx,0x3d
    132c:	e9 0f fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1331:	83 ff 25             	cmp    edi,0x25
    1334:	0f 8f f6 01 00 00    	jg     1530 <trace_event_type_switch_dispatch_xdp+0x430>
    133a:	83 ff 24             	cmp    edi,0x24
    133d:	0f 84 01 03 00 00    	je     1644 <trace_event_type_switch_dispatch_xdp+0x544>
    1343:	83 ff 25             	cmp    edi,0x25
    1346:	0f 85 d4 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    134c:	bb 04 00 00 00       	mov    ebx,0x4
    1351:	e9 ea fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1356:	83 ff 15             	cmp    edi,0x15
    1359:	0f 8f ed 01 00 00    	jg     154c <trace_event_type_switch_dispatch_xdp+0x44c>
    135f:	83 ff 14             	cmp    edi,0x14
    1362:	0f 84 e6 02 00 00    	je     164e <trace_event_type_switch_dispatch_xdp+0x54e>
    1368:	83 ff 15             	cmp    edi,0x15
    136b:	0f 85 af 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1371:	bb 15 00 00 00       	mov    ebx,0x15
    1376:	e9 c5 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    137b:	83 ff 35             	cmp    edi,0x35
    137e:	0f 8f e4 01 00 00    	jg     1568 <trace_event_type_switch_dispatch_xdp+0x468>
    1384:	83 ff 34             	cmp    edi,0x34
    1387:	0f 84 cb 02 00 00    	je     1658 <trace_event_type_switch_dispatch_xdp+0x558>
    138d:	83 ff 35             	cmp    edi,0x35
    1390:	0f 85 8a 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1396:	bb 14 00 00 00       	mov    ebx,0x14
    139b:	e9 a0 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    13a0:	83 ff 0d             	cmp    edi,0xd
    13a3:	0f 8f db 01 00 00    	jg     1584 <trace_event_type_switch_dispatch_xdp+0x484>
    13a9:	83 ff 0c             	cmp    edi,0xc
    13ac:	0f 84 b0 02 00 00    	je     1662 <trace_event_type_switch_dispatch_xdp+0x562>
    13b2:	83 ff 0d             	cmp    edi,0xd
    13b5:	0f 85 65 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    13bb:	bb 2a 00 00 00       	mov    ebx,0x2a
    13c0:	e9 7b fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    13c5:	83 ff 2d             	cmp    edi,0x2d
    13c8:	0f 8f d2 01 00 00    	jg     15a0 <trace_event_type_switch_dispatch_xdp+0x4a0>
    13ce:	83 ff 2c             	cmp    edi,0x2c
    13d1:	0f 84 95 02 00 00    	je     166c <trace_event_type_switch_dispatch_xdp+0x56c>
    13d7:	83 ff 2d             	cmp    edi,0x2d
    13da:	0f 85 40 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    13e0:	bb 2c 00 00 00       	mov    ebx,0x2c
    13e5:	e9 56 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    13ea:	83 ff 1d             	cmp    edi,0x1d
    13ed:	0f 8f c9 01 00 00    	jg     15bc <trace_event_type_switch_dispatch_xdp+0x4bc>
    13f3:	83 ff 1c             	cmp    edi,0x1c
    13f6:	0f 84 7a 02 00 00    	je     1676 <trace_event_type_switch_dispatch_xdp+0x576>
    13fc:	83 ff 1d             	cmp    edi,0x1d
    13ff:	0f 85 1b 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1405:	bb 1f 00 00 00       	mov    ebx,0x1f
    140a:	e9 31 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    140f:	83 ff 3d             	cmp    edi,0x3d
    1412:	0f 8f c0 01 00 00    	jg     15d8 <trace_event_type_switch_dispatch_xdp+0x4d8>
    1418:	83 ff 3c             	cmp    edi,0x3c
    141b:	0f 84 5f 02 00 00    	je     1680 <trace_event_type_switch_dispatch_xdp+0x580>
    1421:	83 ff 3d             	cmp    edi,0x3d
    1424:	0f 85 f6 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    142a:	bb 05 00 00 00       	mov    ebx,0x5
    142f:	e9 0c fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1434:	83 ff 02             	cmp    edi,0x2
    1437:	0f 84 4d 02 00 00    	je     168a <trace_event_type_switch_dispatch_xdp+0x58a>
    143d:	83 ff 03             	cmp    edi,0x3
    1440:	0f 85 da 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1446:	bb 1c 00 00 00       	mov    ebx,0x1c
    144b:	e9 f0 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1450:	83 ff 22             	cmp    edi,0x22
    1453:	0f 84 3b 02 00 00    	je     1694 <trace_event_type_switch_dispatch_xdp+0x594>
    1459:	83 ff 23             	cmp    edi,0x23
    145c:	0f 85 be 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1462:	bb 1b 00 00 00       	mov    ebx,0x1b
    1467:	e9 d4 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    146c:	83 ff 12             	cmp    edi,0x12
    146f:	0f 84 29 02 00 00    	je     169e <trace_event_type_switch_dispatch_xdp+0x59e>
    1475:	83 ff 13             	cmp    edi,0x13
    1478:	0f 85 a2 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    147e:	bb 06 00 00 00       	mov    ebx,0x6
    1483:	e9 b8 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1488:	83 ff 32             	cmp    edi,0x32
    148b:	0f 84 17 02 00 00    	je     16a8 <trace_event_type_switch_dispatch_xdp+0x5a8>
    1491:	83 ff 33             	cmp    edi,0x33
    1494:	0f 85 86 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    149a:	bb 03 00 00 00       	mov    ebx,0x3
    149f:	e9 9c fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14a4:	83 ff 0a             	cmp    edi,0xa
    14a7:	0f 84 05 02 00 00    	je     16b2 <trace_event_type_switch_dispatch_xdp+0x5b2>
    14ad:	83 ff 0b             	cmp    edi,0xb
    14b0:	0f 85 6a 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    14b6:	bb 24 00 00 00       	mov    ebx,0x24
    14bb:	e9 80 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14c0:	83 ff 2a             	cmp    edi,0x2a
    14c3:	0f 84 f3 01 00 00    	je     16bc <trace_event_type_switch_dispatch_xdp+0x5bc>
    14c9:	83 ff 2b             	cmp    edi,0x2b
    14cc:	0f 85 4e 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    14d2:	bb 23 00 00 00       	mov    ebx,0x23
    14d7:	e9 64 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14dc:	83 ff 1a             	cmp    edi,0x1a
    14df:	0f 84 e1 01 00 00    	je     16c6 <trace_event_type_switch_dispatch_xdp+0x5c6>
    14e5:	83 ff 1b             	cmp    edi,0x1b
    14e8:	0f 85 32 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    14ee:	bb 29 00 00 00       	mov    ebx,0x29
    14f3:	e9 48 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14f8:	83 ff 3a             	cmp    edi,0x3a
    14fb:	0f 84 cf 01 00 00    	je     16d0 <trace_event_type_switch_dispatch_xdp+0x5d0>
    1501:	83 ff 3b             	cmp    edi,0x3b
    1504:	0f 85 16 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    150a:	bb 10 00 00 00       	mov    ebx,0x10
    150f:	e9 2c fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1514:	83 ff 06             	cmp    edi,0x6
    1517:	0f 84 bd 01 00 00    	je     16da <trace_event_type_switch_dispatch_xdp+0x5da>
    151d:	83 ff 07             	cmp    edi,0x7
    1520:	0f 85 fa 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1526:	bb 3a 00 00 00       	mov    ebx,0x3a
    152b:	e9 10 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1530:	83 ff 26             	cmp    edi,0x26
    1533:	0f 84 ab 01 00 00    	je     16e4 <trace_event_type_switch_dispatch_xdp+0x5e4>
    1539:	83 ff 27             	cmp    edi,0x27
    153c:	0f 85 de 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1542:	bb 30 00 00 00       	mov    ebx,0x30
    1547:	e9 f4 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    154c:	83 ff 16             	cmp    edi,0x16
    154f:	0f 84 99 01 00 00    	je     16ee <trace_event_type_switch_dispatch_xdp+0x5ee>
    1555:	83 ff 17             	cmp    edi,0x17
    1558:	0f 85 c2 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    155e:	bb 28 00 00 00       	mov    ebx,0x28
    1563:	e9 d8 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1568:	83 ff 36             	cmp    edi,0x36
    156b:	0f 84 87 01 00 00    	je     16f8 <trace_event_type_switch_dispatch_xdp+0x5f8>
    1571:	83 ff 37             	cmp    edi,0x37
    1574:	0f 85 a6 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    157a:	bb 12 00 00 00       	mov    ebx,0x12
    157f:	e9 bc fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1584:	83 ff 0e             	cmp    edi,0xe
    1587:	0f 84 75 01 00 00    	je     1702 <trace_event_type_switch_dispatch_xdp+0x602>
    158d:	83 ff 0f             	cmp    edi,0xf
    1590:	0f 85 8a 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1596:	bb 2e 00 00 00       	mov    ebx,0x2e
    159b:	e9 a0 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15a0:	83 ff 2e             	cmp    edi,0x2e
    15a3:	0f 84 63 01 00 00    	je     170c <trace_event_type_switch_dispatch_xdp+0x60c>
    15a9:	83 ff 2f             	cmp    edi,0x2f
    15ac:	0f 85 6e 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    15b2:	bb 3b 00 00 00       	mov    ebx,0x3b
    15b7:	e9 84 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15bc:	83 ff 1e             	cmp    edi,0x1e
    15bf:	0f 84 51 01 00 00    	je     1716 <trace_event_type_switch_dispatch_xdp+0x616>
    15c5:	83 ff 1f             	cmp    edi,0x1f
    15c8:	0f 85 52 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    15ce:	bb 34 00 00 00       	mov    ebx,0x34
    15d3:	e9 68 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15d8:	83 ff 3e             	cmp    edi,0x3e
    15db:	0f 84 55 fb ff ff    	je     1136 <trace_event_type_switch_dispatch_xdp+0x36>
    15e1:	83 ff 3f             	cmp    edi,0x3f
    15e4:	0f 85 36 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    15ea:	bb 37 00 00 00       	mov    ebx,0x37
    15ef:	e9 4c fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15f4:	bb 19 00 00 00       	mov    ebx,0x19
    15f9:	e9 42 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15fe:	bb 22 00 00 00       	mov    ebx,0x22
    1603:	e9 38 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1608:	bb 2d 00 00 00       	mov    ebx,0x2d
    160d:	e9 2e fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1612:	bb 02 00 00 00       	mov    ebx,0x2
    1617:	e9 24 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    161c:	bb 20 00 00 00       	mov    ebx,0x20
    1621:	e9 1a fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1626:	bb 26 00 00 00       	mov    ebx,0x26
    162b:	e9 10 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1630:	bb 01 00 00 00       	mov    ebx,0x1
    1635:	e9 06 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    163a:	bb 0e 00 00 00       	mov    ebx,0xe
    163f:	e9 fc fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1644:	bb 35 00 00 00       	mov    ebx,0x35
    1649:	e9 f2 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    164e:	bb 1d 00 00 00       	mov    ebx,0x1d
    1653:	e9 e8 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1658:	bb 0d 00 00 00       	mov    ebx,0xd
    165d:	e9 de fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1662:	bb 13 00 00 00       	mov    ebx,0x13
    1667:	e9 d4 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    166c:	bb 08 00 00 00       	mov    ebx,0x8
    1671:	e9 ca fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1676:	bb 21 00 00 00       	mov    ebx,0x21
    167b:	e9 c0 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1680:	bb 3c 00 00 00       	mov    ebx,0x3c
    1685:	e9 b6 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    168a:	bb 39 00 00 00       	mov    ebx,0x39
    168f:	e9 ac fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1694:	bb 0b 00 00 00       	mov    ebx,0xb
    1699:	e9 a2 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    169e:	bb 2f 00 00 00       	mov    ebx,0x2f
    16a3:	e9 98 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16a8:	bb 09 00 00 00       	mov    ebx,0x9
    16ad:	e9 8e fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16b2:	bb 31 00 00 00       	mov    ebx,0x31
    16b7:	e9 84 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16bc:	bb 07 00 00 00       	mov    ebx,0x7
    16c1:	e9 7a fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16c6:	bb 11 00 00 00       	mov    ebx,0x11
    16cb:	e9 70 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16d0:	bb 16 00 00 00       	mov    ebx,0x16
    16d5:	e9 66 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16da:	bb 0a 00 00 00       	mov    ebx,0xa
    16df:	e9 5c fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16e4:	bb 18 00 00 00       	mov    ebx,0x18
    16e9:	e9 52 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16ee:	bb 0f 00 00 00       	mov    ebx,0xf
    16f3:	e9 48 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16f8:	bb 1e 00 00 00       	mov    ebx,0x1e
    16fd:	e9 3e fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1702:	bb 25 00 00 00       	mov    ebx,0x25
    1707:	e9 34 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    170c:	bb 33 00 00 00       	mov    ebx,0x33
    1711:	e9 2a fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1716:	bb 17 00 00 00       	mov    ebx,0x17
    171b:	e9 20 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1720:	bb 52 bf 01 00       	mov    ebx,0x1bf52
    1725:	e9 16 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    172a:	88 19                	mov    BYTE PTR [rcx],bl
    172c:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    172f:	c1 eb 10             	shr    ebx,0x10
    1732:	88 59 02             	mov    BYTE PTR [rcx+0x2],bl
    1735:	89 c2                	mov    edx,eax
    1737:	c1 ea 18             	shr    edx,0x18
    173a:	88 51 03             	mov    BYTE PTR [rcx+0x3],dl
    173d:	48 89 c2             	mov    rdx,rax
    1740:	48 c1 ea 20          	shr    rdx,0x20
    1744:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
    1747:	48 89 c2             	mov    rdx,rax
    174a:	48 c1 ea 28          	shr    rdx,0x28
    174e:	88 51 05             	mov    BYTE PTR [rcx+0x5],dl
    1751:	48 89 c2             	mov    rdx,rax
    1754:	48 c1 ea 30          	shr    rdx,0x30
    1758:	88 51 06             	mov    BYTE PTR [rcx+0x6],dl
    175b:	48 c1 e8 38          	shr    rax,0x38
    175f:	88 41 07             	mov    BYTE PTR [rcx+0x7],al
    1762:	b8 02 00 00 00       	mov    eax,0x2
    1767:	5b                   	pop    rbx
    1768:	c3                   	ret

Disassembly of section .fini:

000000000000176c <_fini>:
    176c:	f3 0f 1e fa          	endbr64
    1770:	48 83 ec 08          	sub    rsp,0x8
    1774:	48 83 c4 08          	add    rsp,0x8
    1778:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
