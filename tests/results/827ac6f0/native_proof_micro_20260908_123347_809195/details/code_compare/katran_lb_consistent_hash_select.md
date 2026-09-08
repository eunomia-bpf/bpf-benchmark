# katran_lb_consistent_hash_select

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
    1040:	48 8d 3d c9 2f 00 00 	lea    rdi,[rip+0x2fc9]        # 4010 <__TMC_END__>
    1047:	48 8d 05 c2 2f 00 00 	lea    rax,[rip+0x2fc2]        # 4010 <__TMC_END__>
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
    1070:	48 8d 3d 99 2f 00 00 	lea    rdi,[rip+0x2f99]        # 4010 <__TMC_END__>
    1077:	48 8d 35 92 2f 00 00 	lea    rsi,[rip+0x2f92]        # 4010 <__TMC_END__>
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
    10b4:	80 3d 51 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f51],0x0        # 400c <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 29 2f 00 00 01 	mov    BYTE PTR [rip+0x2f29],0x1        # 400c <completed.0>
    10e3:	5d                   	pop    rbp
    10e4:	c3                   	ret
    10e5:	0f 1f 00             	nop    DWORD PTR [rax]
    10e8:	c3                   	ret
    10e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010f0 <frame_dummy>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	e9 77 ff ff ff       	jmp    1070 <register_tm_clones>
    10f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001100 <katran_lb_consistent_hash_select_xdp>:
    1100:	55                   	push   rbp
    1101:	41 57                	push   r15
    1103:	41 56                	push   r14
    1105:	41 55                	push   r13
    1107:	41 54                	push   r12
    1109:	53                   	push   rbx
    110a:	50                   	push   rax
    110b:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    110e:	48 8b 5f 08          	mov    rbx,QWORD PTR [rdi+0x8]
    1112:	31 c0                	xor    eax,eax
    1114:	48 39 d9             	cmp    rcx,rbx
    1117:	0f 87 f1 04 00 00    	ja     160e <katran_lb_consistent_hash_select_xdp+0x50e>
    111d:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1121:	48 39 de             	cmp    rsi,rbx
    1124:	0f 87 e4 04 00 00    	ja     160e <katran_lb_consistent_hash_select_xdp+0x50e>
    112a:	48 8d 51 16          	lea    rdx,[rcx+0x16]
    112e:	48 39 da             	cmp    rdx,rbx
    1131:	0f 87 d7 04 00 00    	ja     160e <katran_lb_consistent_hash_select_xdp+0x50e>
    1137:	48 b8 15 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c15
    113e:	79 37 9e 
    1141:	49 89 da             	mov    r10,rbx
    1144:	49 29 f2             	sub    r10,rsi
    1147:	0f b7 71 14          	movzx  esi,WORD PTR [rcx+0x14]
    114b:	81 fe 86 dd 00 00    	cmp    esi,0xdd86
    1151:	0f 84 91 00 00 00    	je     11e8 <katran_lb_consistent_hash_select_xdp+0xe8>
    1157:	83 fe 08             	cmp    esi,0x8
    115a:	0f 85 b7 00 00 00    	jne    1217 <katran_lb_consistent_hash_select_xdp+0x117>
    1160:	48 8d 71 2a          	lea    rsi,[rcx+0x2a]
    1164:	41 b9 01 00 00 00    	mov    r9d,0x1
    116a:	48 39 de             	cmp    rsi,rbx
    116d:	0f 87 74 04 00 00    	ja     15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    1173:	0f b6 12             	movzx  edx,BYTE PTR [rdx]
    1176:	80 e2 0f             	and    dl,0xf
    1179:	80 fa 05             	cmp    dl,0x5
    117c:	0f 85 65 04 00 00    	jne    15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    1182:	0f b6 51 1c          	movzx  edx,BYTE PTR [rcx+0x1c]
    1186:	0f b6 71 1d          	movzx  esi,BYTE PTR [rcx+0x1d]
    118a:	83 e2 3f             	and    edx,0x3f
    118d:	66 09 f2             	or     dx,si
    1190:	0f 85 51 04 00 00    	jne    15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    1196:	44 0f b6 71 1f       	movzx  r14d,BYTE PTR [rcx+0x1f]
    119b:	be 02 00 00 00       	mov    esi,0x2
    11a0:	41 83 fe 01          	cmp    r14d,0x1
    11a4:	0f 84 8b 00 00 00    	je     1235 <katran_lb_consistent_hash_select_xdp+0x135>
    11aa:	66 0f 38 f0 69 18    	movbe  bp,WORD PTR [rcx+0x18]
    11b0:	0f b6 79 17          	movzx  edi,BYTE PTR [rcx+0x17]
    11b4:	44 0f b7 59 22       	movzx  r11d,WORD PTR [rcx+0x22]
    11b9:	44 0f b6 41 24       	movzx  r8d,BYTE PTR [rcx+0x24]
    11be:	0f b6 51 25          	movzx  edx,BYTE PTR [rcx+0x25]
    11c2:	44 8b 79 26          	mov    r15d,DWORD PTR [rcx+0x26]
    11c6:	41 83 fe 11          	cmp    r14d,0x11
    11ca:	0f 84 0e 04 00 00    	je     15de <katran_lb_consistent_hash_select_xdp+0x4de>
    11d0:	41 83 fe 06          	cmp    r14d,0x6
    11d4:	75 5f                	jne    1235 <katran_lb_consistent_hash_select_xdp+0x135>
    11d6:	4c 8d 61 3e          	lea    r12,[rcx+0x3e]
    11da:	49 39 dc             	cmp    r12,rbx
    11dd:	0f 87 04 04 00 00    	ja     15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    11e3:	e9 35 04 00 00       	jmp    161d <katran_lb_consistent_hash_select_xdp+0x51d>
    11e8:	48 8d 51 3e          	lea    rdx,[rcx+0x3e]
    11ec:	41 b9 01 00 00 00    	mov    r9d,0x1
    11f2:	48 39 da             	cmp    rdx,rbx
    11f5:	0f 87 ec 03 00 00    	ja     15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    11fb:	44 0f b6 61 1c       	movzx  r12d,BYTE PTR [rcx+0x1c]
    1200:	41 83 fc 2c          	cmp    r12d,0x2c
    1204:	0f 84 dd 03 00 00    	je     15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    120a:	41 83 fc 3a          	cmp    r12d,0x3a
    120e:	75 30                	jne    1240 <katran_lb_consistent_hash_select_xdp+0x140>
    1210:	be 02 00 00 00       	mov    esi,0x2
    1215:	eb 1e                	jmp    1235 <katran_lb_consistent_hash_select_xdp+0x135>
    1217:	49 01 c2             	add    r10,rax
    121a:	4c 89 d2             	mov    rdx,r10
    121d:	48 c1 e2 06          	shl    rdx,0x6
    1221:	48 01 c2             	add    rdx,rax
    1224:	4c 89 d6             	mov    rsi,r10
    1227:	48 c1 ee 02          	shr    rsi,0x2
    122b:	48 01 d6             	add    rsi,rdx
    122e:	48 83 c6 02          	add    rsi,0x2
    1232:	4c 31 d6             	xor    rsi,r10
    1235:	41 b9 02 00 00 00    	mov    r9d,0x2
    123b:	e9 ac 03 00 00       	jmp    15ec <katran_lb_consistent_hash_select_xdp+0x4ec>
    1240:	0f b6 51 16          	movzx  edx,BYTE PTR [rcx+0x16]
    1244:	44 0f b6 79 17       	movzx  r15d,BYTE PTR [rcx+0x17]
    1249:	66 0f 38 f0 69 1a    	movbe  bp,WORD PTR [rcx+0x1a]
    124f:	8b 79 1e             	mov    edi,DWORD PTR [rcx+0x1e]
    1252:	44 8b 71 26          	mov    r14d,DWORD PTR [rcx+0x26]
    1256:	44 8b 41 2a          	mov    r8d,DWORD PTR [rcx+0x2a]
    125a:	44 8b 69 2e          	mov    r13d,DWORD PTR [rcx+0x2e]
    125e:	41 bb ff c0 ad de    	mov    r11d,0xdeadc0ff
    1264:	44 03 59 22          	add    r11d,DWORD PTR [rcx+0x22]
    1268:	be 02 00 00 00       	mov    esi,0x2
    126d:	41 83 fc 11          	cmp    r12d,0x11
    1271:	74 19                	je     128c <katran_lb_consistent_hash_select_xdp+0x18c>
    1273:	41 83 fc 06          	cmp    r12d,0x6
    1277:	75 bc                	jne    1235 <katran_lb_consistent_hash_select_xdp+0x135>
    1279:	48 89 3c 24          	mov    QWORD PTR [rsp],rdi
    127d:	48 8d 79 52          	lea    rdi,[rcx+0x52]
    1281:	48 39 df             	cmp    rdi,rbx
    1284:	0f 87 5d 03 00 00    	ja     15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    128a:	eb 11                	jmp    129d <katran_lb_consistent_hash_select_xdp+0x19d>
    128c:	48 89 3c 24          	mov    QWORD PTR [rsp],rdi
    1290:	48 8d 79 46          	lea    rdi,[rcx+0x46]
    1294:	48 39 df             	cmp    rdi,rbx
    1297:	0f 87 4a 03 00 00    	ja     15e7 <katran_lb_consistent_hash_select_xdp+0x4e7>
    129d:	41 83 fc 06          	cmp    r12d,0x6
    12a1:	75 92                	jne    1235 <katran_lb_consistent_hash_select_xdp+0x135>
    12a3:	41 81 fd 0a 64 01 01 	cmp    r13d,0x101640a
    12aa:	75 89                	jne    1235 <katran_lb_consistent_hash_select_xdp+0x135>
    12ac:	0f b7 79 40          	movzx  edi,WORD PTR [rcx+0x40]
    12b0:	41 b9 02 00 00 00    	mov    r9d,0x2
    12b6:	81 ff 1f 90 00 00    	cmp    edi,0x901f
    12bc:	0f 85 2a 03 00 00    	jne    15ec <katran_lb_consistent_hash_select_xdp+0x4ec>
    12c2:	be 01 00 00 00       	mov    esi,0x1
    12c7:	41 b9 01 00 00 00    	mov    r9d,0x1
    12cd:	49 81 fa ea 05 00 00 	cmp    r10,0x5ea
    12d4:	0f 8f 12 03 00 00    	jg     15ec <katran_lb_consistent_hash_select_xdp+0x4ec>
    12da:	41 c0 ef 04          	shr    r15b,0x4
    12de:	41 89 d4             	mov    r12d,edx
    12e1:	41 c0 e4 04          	shl    r12b,0x4
    12e5:	45 08 fc             	or     r12b,r15b
    12e8:	0f b7 f5             	movzx  esi,bp
    12eb:	44 89 c7             	mov    edi,r8d
    12ee:	81 e7 00 00 00 ff    	and    edi,0xff000000
    12f4:	45 8d 96 ff c0 ad de 	lea    r10d,[r14-0x21523f01]
    12fb:	45 89 c1             	mov    r9d,r8d
    12fe:	41 81 e1 00 00 ff 00 	and    r9d,0xff0000
    1305:	41 01 f9             	add    r9d,edi
    1308:	44 89 c7             	mov    edi,r8d
    130b:	81 e7 00 ff 00 00    	and    edi,0xff00
    1311:	44 01 cf             	add    edi,r9d
    1314:	45 0f b6 c8          	movzx  r9d,r8b
    1318:	41 01 f9             	add    r9d,edi
    131b:	44 0f b7 41 3e       	movzx  r8d,WORD PTR [rcx+0x3e]
    1320:	48 8b 14 24          	mov    rdx,QWORD PTR [rsp]
    1324:	89 d7                	mov    edi,edx
    1326:	44 29 f7             	sub    edi,r14d
    1329:	c4 c3 7b f0 da 1c    	rorx   ebx,r10d,0x1c
    132f:	31 fb                	xor    ebx,edi
    1331:	45 01 da             	add    r10d,r11d
    1334:	41 29 db             	sub    r11d,ebx
    1337:	c4 e3 7b f0 fb 1a    	rorx   edi,ebx,0x1a
    133d:	44 31 df             	xor    edi,r11d
    1340:	44 01 d3             	add    ebx,r10d
    1343:	8d 2c 1f             	lea    ebp,[rdi+rbx*1]
    1346:	41 29 fa             	sub    r10d,edi
    1349:	c4 e3 7b f0 ff 18    	rorx   edi,edi,0x18
    134f:	44 31 d7             	xor    edi,r10d
    1352:	29 fb                	sub    ebx,edi
    1354:	c4 63 7b f0 df 10    	rorx   r11d,edi,0x10
    135a:	41 31 db             	xor    r11d,ebx
    135d:	01 ef                	add    edi,ebp
    135f:	44 29 dd             	sub    ebp,r11d
    1362:	c4 c3 7b f0 db 0d    	rorx   ebx,r11d,0xd
    1368:	31 eb                	xor    ebx,ebp
    136a:	41 01 fb             	add    r11d,edi
    136d:	46 8d 14 1b          	lea    r10d,[rbx+r11*1]
    1371:	29 df                	sub    edi,ebx
    1373:	c4 e3 7b f0 db 1c    	rorx   ebx,ebx,0x1c
    1379:	31 fb                	xor    ebx,edi
    137b:	45 01 cb             	add    r11d,r9d
    137e:	44 31 d3             	xor    ebx,r10d
    1381:	c4 c3 7b f0 fa 12    	rorx   edi,r10d,0x12
    1387:	29 fb                	sub    ebx,edi
    1389:	41 31 db             	xor    r11d,ebx
    138c:	c4 e3 7b f0 fb 15    	rorx   edi,ebx,0x15
    1392:	41 29 fb             	sub    r11d,edi
    1395:	45 31 da             	xor    r10d,r11d
    1398:	c4 c3 7b f0 fb 07    	rorx   edi,r11d,0x7
    139e:	41 29 fa             	sub    r10d,edi
    13a1:	44 31 d3             	xor    ebx,r10d
    13a4:	c4 c3 7b f0 fa 10    	rorx   edi,r10d,0x10
    13aa:	29 fb                	sub    ebx,edi
    13ac:	41 31 db             	xor    r11d,ebx
    13af:	c4 e3 7b f0 fb 1c    	rorx   edi,ebx,0x1c
    13b5:	41 29 fb             	sub    r11d,edi
    13b8:	45 31 da             	xor    r10d,r11d
    13bb:	c4 c3 7b f0 fb 12    	rorx   edi,r11d,0x12
    13c1:	41 29 fa             	sub    r10d,edi
    13c4:	c4 c3 7b f0 fa 08    	rorx   edi,r10d,0x8
    13ca:	41 31 da             	xor    r10d,ebx
    13cd:	41 29 fa             	sub    r10d,edi
    13d0:	41 81 c2 f7 c0 ad e0 	add    r10d,0xe0adc0f7
    13d7:	45 89 c3             	mov    r11d,r8d
    13da:	41 81 c3 f7 c0 cc 70 	add    r11d,0x70ccc0f7
    13e1:	45 89 d9             	mov    r9d,r11d
    13e4:	41 81 f1 f7 c0 ad e0 	xor    r9d,0xe0adc0f7
    13eb:	bf 00 00 cc 70       	mov    edi,0x70cc0000
    13f0:	44 0f ac df 12       	shrd   edi,r11d,0x12
    13f5:	41 29 f9             	sub    r9d,edi
    13f8:	45 31 ca             	xor    r10d,r9d
    13fb:	c4 c3 7b f0 f9 15    	rorx   edi,r9d,0x15
    1401:	41 29 fa             	sub    r10d,edi
    1404:	45 31 d3             	xor    r11d,r10d
    1407:	c4 c3 7b f0 fa 07    	rorx   edi,r10d,0x7
    140d:	41 29 fb             	sub    r11d,edi
    1410:	45 31 d9             	xor    r9d,r11d
    1413:	c4 c3 7b f0 fb 10    	rorx   edi,r11d,0x10
    1419:	41 29 f9             	sub    r9d,edi
    141c:	45 31 ca             	xor    r10d,r9d
    141f:	c4 c3 7b f0 f9 1c    	rorx   edi,r9d,0x1c
    1425:	41 29 fa             	sub    r10d,edi
    1428:	45 31 d3             	xor    r11d,r10d
    142b:	c4 c3 7b f0 fa 12    	rorx   edi,r10d,0x12
    1431:	41 29 fb             	sub    r11d,edi
    1434:	45 31 d9             	xor    r9d,r11d
    1437:	c4 c3 7b f0 fb 08    	rorx   edi,r11d,0x8
    143d:	41 29 f9             	sub    r9d,edi
    1440:	bf 01 00 ff ff       	mov    edi,0xffff0001
    1445:	49 0f af f9          	imul   rdi,r9
    1449:	48 c1 ef 30          	shr    rdi,0x30
    144d:	41 89 fa             	mov    r10d,edi
    1450:	41 c1 e2 10          	shl    r10d,0x10
    1454:	41 09 fa             	or     r10d,edi
    1457:	45 29 d1             	sub    r9d,r10d
    145a:	48 89 d7             	mov    rdi,rdx
    145d:	48 01 c7             	add    rdi,rax
    1460:	49 89 fa             	mov    r10,rdi
    1463:	49 c1 e2 06          	shl    r10,0x6
    1467:	49 01 c2             	add    r10,rax
    146a:	49 89 fb             	mov    r11,rdi
    146d:	49 c1 eb 02          	shr    r11,0x2
    1471:	4d 01 da             	add    r10,r11
    1474:	49 81 c2 0a 64 01 01 	add    r10,0x101640a
    147b:	49 31 fa             	xor    r10,rdi
    147e:	4d 89 d3             	mov    r11,r10
    1481:	49 c1 e3 06          	shl    r11,0x6
    1485:	4d 01 c3             	add    r11,r8
    1488:	49 01 c3             	add    r11,rax
    148b:	4c 89 d7             	mov    rdi,r10
    148e:	48 c1 ef 02          	shr    rdi,0x2
    1492:	bb 00 00 1f 90       	mov    ebx,0x901f0000
    1497:	48 01 fb             	add    rbx,rdi
    149a:	4c 01 db             	add    rbx,r11
    149d:	4c 31 d3             	xor    rbx,r10
    14a0:	48 89 df             	mov    rdi,rbx
    14a3:	48 c1 e7 06          	shl    rdi,0x6
    14a7:	49 89 da             	mov    r10,rbx
    14aa:	49 c1 ea 02          	shr    r10,0x2
    14ae:	48 01 c7             	add    rdi,rax
    14b1:	4c 01 d7             	add    rdi,r10
    14b4:	4c 01 cf             	add    rdi,r9
    14b7:	48 31 df             	xor    rdi,rbx
    14ba:	49 89 f9             	mov    r9,rdi
    14bd:	49 c1 e1 06          	shl    r9,0x6
    14c1:	49 01 c1             	add    r9,rax
    14c4:	49 89 fa             	mov    r10,rdi
    14c7:	49 c1 ea 02          	shr    r10,0x2
    14cb:	4d 01 d1             	add    r9,r10
    14ce:	49 ff c1             	inc    r9
    14d1:	49 31 f9             	xor    r9,rdi
    14d4:	4c 89 cf             	mov    rdi,r9
    14d7:	48 c1 e7 06          	shl    rdi,0x6
    14db:	48 01 c7             	add    rdi,rax
    14de:	4d 89 ca             	mov    r10,r9
    14e1:	49 c1 ea 02          	shr    r10,0x2
    14e5:	49 01 fa             	add    r10,rdi
    14e8:	4d 31 ca             	xor    r10,r9
    14eb:	4d 89 d3             	mov    r11,r10
    14ee:	49 c1 e3 06          	shl    r11,0x6
    14f2:	49 01 f3             	add    r11,rsi
    14f5:	49 01 c3             	add    r11,rax
    14f8:	4d 89 d1             	mov    r9,r10
    14fb:	49 c1 e9 02          	shr    r9,0x2
    14ff:	4d 01 d9             	add    r9,r11
    1502:	66 41 c1 c0 08       	rol    r8w,0x8
    1507:	41 c1 e0 10          	shl    r8d,0x10
    150b:	81 e2 00 00 ff ff    	and    edx,0xffff0000
    1511:	44 31 c2             	xor    edx,r8d
    1514:	89 f7                	mov    edi,esi
    1516:	83 c7 14             	add    edi,0x14
    1519:	66 c1 c7 08          	rol    di,0x8
    151d:	45 0f b6 c4          	movzx  r8d,r12b
    1521:	0f b7 ff             	movzx  edi,di
    1524:	41 89 d3             	mov    r11d,edx
    1527:	41 c1 eb 10          	shr    r11d,0x10
    152b:	4c 01 c7             	add    rdi,r8
    152e:	4c 01 df             	add    rdi,r11
    1531:	48 81 c7 3b df 00 00 	add    rdi,0xdf3b
    1538:	41 89 f8             	mov    r8d,edi
    153b:	41 c1 e8 10          	shr    r8d,0x10
    153f:	44 0f b7 df          	movzx  r11d,di
    1543:	4d 01 c3             	add    r11,r8
    1546:	48 81 ff 00 00 01 00 	cmp    rdi,0x10000
    154d:	4c 0f 42 df          	cmovb  r11,rdi
    1551:	44 89 df             	mov    edi,r11d
    1554:	c1 ef 10             	shr    edi,0x10
    1557:	45 0f b7 c3          	movzx  r8d,r11w
    155b:	49 01 f8             	add    r8,rdi
    155e:	49 81 fb 00 00 01 00 	cmp    r11,0x10000
    1565:	4d 0f 42 c3          	cmovb  r8,r11
    1569:	44 89 c7             	mov    edi,r8d
    156c:	c1 ef 10             	shr    edi,0x10
    156f:	45 0f b7 d8          	movzx  r11d,r8w
    1573:	49 01 fb             	add    r11,rdi
    1576:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
    157d:	4d 0f 42 d8          	cmovb  r11,r8
    1581:	44 89 df             	mov    edi,r11d
    1584:	c1 ef 10             	shr    edi,0x10
    1587:	44 01 df             	add    edi,r11d
    158a:	4d 31 d1             	xor    r9,r10
    158d:	81 ca ac 10 00 00    	or     edx,0x10ac
    1593:	48 c1 e2 20          	shl    rdx,0x20
    1597:	48 81 ca 0a c8 00 02 	or     rdx,0x200c80a
    159e:	49 81 fb 00 00 01 00 	cmp    r11,0x10000
    15a5:	41 0f 42 fb          	cmovb  edi,r11d
    15a9:	c1 e7 10             	shl    edi,0x10
    15ac:	48 31 f2             	xor    rdx,rsi
    15af:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
    15b6:	02 00 00 
    15b9:	48 31 d6             	xor    rsi,rdx
    15bc:	48 31 fe             	xor    rsi,rdi
    15bf:	4c 89 ca             	mov    rdx,r9
    15c2:	48 c1 e2 06          	shl    rdx,0x6
    15c6:	4c 89 cf             	mov    rdi,r9
    15c9:	48 c1 ef 02          	shr    rdi,0x2
    15cd:	48 01 f7             	add    rdi,rsi
    15d0:	48 01 c2             	add    rdx,rax
    15d3:	48 01 fa             	add    rdx,rdi
    15d6:	4c 31 ca             	xor    rdx,r9
    15d9:	e9 93 02 00 00       	jmp    1871 <katran_lb_consistent_hash_select_xdp+0x771>
    15de:	4c 8d 61 32          	lea    r12,[rcx+0x32]
    15e2:	49 39 dc             	cmp    r12,rbx
    15e5:	76 36                	jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d>
    15e7:	be 01 00 00 00       	mov    esi,0x1
    15ec:	48 89 f2             	mov    rdx,rsi
    15ef:	48 c1 e2 06          	shl    rdx,0x6
    15f3:	48 89 f7             	mov    rdi,rsi
    15f6:	48 c1 ef 02          	shr    rdi,0x2
    15fa:	4c 01 cf             	add    rdi,r9
    15fd:	48 01 c2             	add    rdx,rax
    1600:	48 01 fa             	add    rdx,rdi
    1603:	48 31 f2             	xor    rdx,rsi
    1606:	48 89 11             	mov    QWORD PTR [rcx],rdx
    1609:	b8 02 00 00 00       	mov    eax,0x2
    160e:	48 83 c4 08          	add    rsp,0x8
    1612:	5b                   	pop    rbx
    1613:	41 5c                	pop    r12
    1615:	41 5d                	pop    r13
    1617:	41 5e                	pop    r14
    1619:	41 5f                	pop    r15
    161b:	5d                   	pop    rbp
    161c:	c3                   	ret
    161d:	41 81 ff 0a 64 01 01 	cmp    r15d,0x101640a
    1624:	0f 85 0b fc ff ff    	jne    1235 <katran_lb_consistent_hash_select_xdp+0x135>
    162a:	44 0f b7 49 2c       	movzx  r9d,WORD PTR [rcx+0x2c]
    162f:	41 81 f9 1f 90 00 00 	cmp    r9d,0x901f
    1636:	0f 85 f9 fb ff ff    	jne    1235 <katran_lb_consistent_hash_select_xdp+0x135>
    163c:	41 b9 02 00 00 00    	mov    r9d,0x2
    1642:	41 80 fe 06          	cmp    r14b,0x6
    1646:	75 a4                	jne    15ec <katran_lb_consistent_hash_select_xdp+0x4ec>
    1648:	be 01 00 00 00       	mov    esi,0x1
    164d:	41 b9 01 00 00 00    	mov    r9d,0x1
    1653:	49 81 fa ea 05 00 00 	cmp    r10,0x5ea
    165a:	7f 90                	jg     15ec <katran_lb_consistent_hash_select_xdp+0x4ec>
    165c:	0f b7 f5             	movzx  esi,bp
    165f:	41 c1 e0 10          	shl    r8d,0x10
    1663:	c1 e2 18             	shl    edx,0x18
    1666:	45 09 c3             	or     r11d,r8d
    1669:	41 09 d3             	or     r11d,edx
    166c:	44 0f b7 49 2a       	movzx  r9d,WORD PTR [rcx+0x2a]
    1671:	44 89 cb             	mov    ebx,r9d
    1674:	81 c3 f7 c0 cc 70    	add    ebx,0x70ccc0f7
    167a:	41 89 da             	mov    r10d,ebx
    167d:	41 81 f2 f7 c0 ad e0 	xor    r10d,0xe0adc0f7
    1684:	bd 00 00 cc 70       	mov    ebp,0x70cc0000
    1689:	0f ac dd 12          	shrd   ebp,ebx,0x12
    168d:	41 29 ea             	sub    r10d,ebp
    1690:	41 8d ab f7 c0 ad e0 	lea    ebp,[r11-0x1f523f09]
    1697:	44 31 d5             	xor    ebp,r10d
    169a:	c4 43 7b f0 f2 15    	rorx   r14d,r10d,0x15
    16a0:	44 29 f5             	sub    ebp,r14d
    16a3:	31 eb                	xor    ebx,ebp
    16a5:	c4 63 7b f0 f5 07    	rorx   r14d,ebp,0x7
    16ab:	44 29 f3             	sub    ebx,r14d
    16ae:	41 31 da             	xor    r10d,ebx
    16b1:	c4 63 7b f0 f3 10    	rorx   r14d,ebx,0x10
    16b7:	45 29 f2             	sub    r10d,r14d
    16ba:	44 31 d5             	xor    ebp,r10d
    16bd:	c4 43 7b f0 f2 1c    	rorx   r14d,r10d,0x1c
    16c3:	44 29 f5             	sub    ebp,r14d
    16c6:	31 eb                	xor    ebx,ebp
    16c8:	c4 e3 7b f0 ed 12    	rorx   ebp,ebp,0x12
    16ce:	29 eb                	sub    ebx,ebp
    16d0:	41 31 da             	xor    r10d,ebx
    16d3:	c4 e3 7b f0 db 08    	rorx   ebx,ebx,0x8
    16d9:	41 29 da             	sub    r10d,ebx
    16dc:	bb 01 00 ff ff       	mov    ebx,0xffff0001
    16e1:	49 0f af da          	imul   rbx,r10
    16e5:	48 c1 eb 30          	shr    rbx,0x30
    16e9:	89 dd                	mov    ebp,ebx
    16eb:	c1 e5 10             	shl    ebp,0x10
    16ee:	09 dd                	or     ebp,ebx
    16f0:	41 29 ea             	sub    r10d,ebp
    16f3:	45 89 db             	mov    r11d,r11d
    16f6:	49 01 c3             	add    r11,rax
    16f9:	4c 89 db             	mov    rbx,r11
    16fc:	48 c1 e3 06          	shl    rbx,0x6
    1700:	4d 89 de             	mov    r14,r11
    1703:	49 c1 ee 02          	shr    r14,0x2
    1707:	48 01 c3             	add    rbx,rax
    170a:	4c 01 f3             	add    rbx,r14
    170d:	48 81 c3 0a 64 01 01 	add    rbx,0x101640a
    1714:	4c 31 db             	xor    rbx,r11
    1717:	49 89 db             	mov    r11,rbx
    171a:	49 c1 e3 06          	shl    r11,0x6
    171e:	49 89 de             	mov    r14,rbx
    1721:	49 c1 ee 02          	shr    r14,0x2
    1725:	4d 01 ce             	add    r14,r9
    1728:	49 01 c3             	add    r11,rax
    172b:	4d 01 f3             	add    r11,r14
    172e:	41 be 00 00 1f 90    	mov    r14d,0x901f0000
    1734:	4d 01 de             	add    r14,r11
    1737:	49 31 de             	xor    r14,rbx
    173a:	4d 89 f3             	mov    r11,r14
    173d:	49 c1 e3 06          	shl    r11,0x6
    1741:	4c 89 f3             	mov    rbx,r14
    1744:	48 c1 eb 02          	shr    rbx,0x2
    1748:	49 01 c3             	add    r11,rax
    174b:	49 01 db             	add    r11,rbx
    174e:	4d 01 d3             	add    r11,r10
    1751:	4d 31 f3             	xor    r11,r14
    1754:	4d 89 da             	mov    r10,r11
    1757:	49 c1 e2 06          	shl    r10,0x6
    175b:	49 01 c2             	add    r10,rax
    175e:	4c 89 db             	mov    rbx,r11
    1761:	48 c1 eb 02          	shr    rbx,0x2
    1765:	49 01 da             	add    r10,rbx
    1768:	49 ff c2             	inc    r10
    176b:	4d 31 da             	xor    r10,r11
    176e:	4c 89 d3             	mov    rbx,r10
    1771:	48 c1 e3 06          	shl    rbx,0x6
    1775:	48 01 c3             	add    rbx,rax
    1778:	4d 89 d3             	mov    r11,r10
    177b:	49 c1 eb 02          	shr    r11,0x2
    177f:	49 01 db             	add    r11,rbx
    1782:	4d 31 d3             	xor    r11,r10
    1785:	4c 89 db             	mov    rbx,r11
    1788:	48 c1 e3 06          	shl    rbx,0x6
    178c:	48 01 f3             	add    rbx,rsi
    178f:	48 01 c3             	add    rbx,rax
    1792:	4d 89 da             	mov    r10,r11
    1795:	49 c1 ea 02          	shr    r10,0x2
    1799:	49 01 da             	add    r10,rbx
    179c:	66 41 c1 c1 08       	rol    r9w,0x8
    17a1:	41 c1 e1 10          	shl    r9d,0x10
    17a5:	44 09 c2             	or     edx,r8d
    17a8:	44 31 ca             	xor    edx,r9d
    17ab:	41 89 f0             	mov    r8d,esi
    17ae:	41 83 c0 14          	add    r8d,0x14
    17b2:	66 41 c1 c0 08       	rol    r8w,0x8
    17b7:	45 0f b7 c0          	movzx  r8d,r8w
    17bb:	41 89 d1             	mov    r9d,edx
    17be:	41 c1 e9 10          	shr    r9d,0x10
    17c2:	49 01 f8             	add    r8,rdi
    17c5:	4b 8d 3c 01          	lea    rdi,[r9+r8*1]
    17c9:	48 81 c7 3b df 00 00 	add    rdi,0xdf3b
    17d0:	41 89 f8             	mov    r8d,edi
    17d3:	41 c1 e8 10          	shr    r8d,0x10
    17d7:	44 0f b7 cf          	movzx  r9d,di
    17db:	4d 01 c1             	add    r9,r8
    17de:	48 81 ff 00 00 01 00 	cmp    rdi,0x10000
    17e5:	4c 0f 42 cf          	cmovb  r9,rdi
    17e9:	44 89 cf             	mov    edi,r9d
    17ec:	c1 ef 10             	shr    edi,0x10
    17ef:	45 0f b7 c1          	movzx  r8d,r9w
    17f3:	49 01 f8             	add    r8,rdi
    17f6:	49 81 f9 00 00 01 00 	cmp    r9,0x10000
    17fd:	4d 0f 42 c1          	cmovb  r8,r9
    1801:	44 89 c7             	mov    edi,r8d
    1804:	c1 ef 10             	shr    edi,0x10
    1807:	45 0f b7 c8          	movzx  r9d,r8w
    180b:	49 01 f9             	add    r9,rdi
    180e:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
    1815:	4d 0f 42 c8          	cmovb  r9,r8
    1819:	44 89 cf             	mov    edi,r9d
    181c:	c1 ef 10             	shr    edi,0x10
    181f:	44 01 cf             	add    edi,r9d
    1822:	4d 31 da             	xor    r10,r11
    1825:	81 ca ac 10 00 00    	or     edx,0x10ac
    182b:	48 c1 e2 20          	shl    rdx,0x20
    182f:	48 81 ca 0a c8 00 02 	or     rdx,0x200c80a
    1836:	49 81 f9 00 00 01 00 	cmp    r9,0x10000
    183d:	41 0f 42 f9          	cmovb  edi,r9d
    1841:	c1 e7 10             	shl    edi,0x10
    1844:	48 31 f2             	xor    rdx,rsi
    1847:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
    184e:	02 00 00 
    1851:	48 31 d6             	xor    rsi,rdx
    1854:	48 31 fe             	xor    rsi,rdi
    1857:	4c 89 d2             	mov    rdx,r10
    185a:	48 c1 e2 06          	shl    rdx,0x6
    185e:	4c 89 d7             	mov    rdi,r10
    1861:	48 c1 ef 02          	shr    rdi,0x2
    1865:	48 01 f7             	add    rdi,rsi
    1868:	48 01 c2             	add    rdx,rax
    186b:	48 01 fa             	add    rdx,rdi
    186e:	4c 31 d2             	xor    rdx,r10
    1871:	48 89 d6             	mov    rsi,rdx
    1874:	48 c1 e6 06          	shl    rsi,0x6
    1878:	48 01 c6             	add    rsi,rax
    187b:	48 89 d7             	mov    rdi,rdx
    187e:	48 c1 ef 02          	shr    rdi,0x2
    1882:	48 01 fe             	add    rsi,rdi
    1885:	48 83 c6 03          	add    rsi,0x3
    1889:	48 31 d6             	xor    rsi,rdx
    188c:	41 b9 03 00 00 00    	mov    r9d,0x3
    1892:	e9 55 fd ff ff       	jmp    15ec <katran_lb_consistent_hash_select_xdp+0x4ec>

Disassembly of section .fini:

0000000000001898 <_fini>:
    1898:	f3 0f 1e fa          	endbr64
    189c:	48 83 ec 08          	sub    rsp,0x8
    18a0:	48 83 c4 08          	add    rsp,0x8
    18a4:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
