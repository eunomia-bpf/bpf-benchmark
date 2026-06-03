# payload_prefix_memcmp_scan

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

0000000000001100 <payload_prefix_memcmp_scan_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <payload_prefix_memcmp_scan_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <payload_prefix_memcmp_scan_xdp+0x11>
    111b:	4c 8d 82 cc 00 00 00 	lea    r8,[rdx+0xcc]
    1122:	49 39 f0             	cmp    r8,rsi
    1125:	77 ea                	ja     1111 <payload_prefix_memcmp_scan_xdp+0x11>
    1127:	83 3f 03             	cmp    DWORD PTR [rdi],0x3
    112a:	75 e5                	jne    1111 <payload_prefix_memcmp_scan_xdp+0x11>
    112c:	41 b8 57 00 00 00    	mov    r8d,0x57
    1132:	41 b9 0c 00 00 00    	mov    r9d,0xc
    1138:	31 c0                	xor    eax,eax
    113a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1140:	0f b6 74 02 0c       	movzx  esi,BYTE PTR [rdx+rax*1+0xc]
    1145:	45 8d 50 a9          	lea    r10d,[r8-0x57]
    1149:	41 8d 79 f4          	lea    edi,[r9-0xc]
    114d:	44 31 d7             	xor    edi,r10d
    1150:	81 f7 a5 00 00 00    	xor    edi,0xa5
    1156:	83 c7 11             	add    edi,0x11
    1159:	40 38 fe             	cmp    sil,dil
    115c:	75 7b                	jne    11d9 <payload_prefix_memcmp_scan_xdp+0xd9>
    115e:	0f b6 74 02 0d       	movzx  esi,BYTE PTR [rdx+rax*1+0xd]
    1163:	45 8d 50 c6          	lea    r10d,[r8-0x3a]
    1167:	41 8d 79 f8          	lea    edi,[r9-0x8]
    116b:	44 31 d7             	xor    edi,r10d
    116e:	81 f7 a5 00 00 00    	xor    edi,0xa5
    1174:	83 c7 11             	add    edi,0x11
    1177:	40 38 fe             	cmp    sil,dil
    117a:	75 62                	jne    11de <payload_prefix_memcmp_scan_xdp+0xde>
    117c:	0f b6 74 02 0e       	movzx  esi,BYTE PTR [rdx+rax*1+0xe]
    1181:	45 8d 50 e3          	lea    r10d,[r8-0x1d]
    1185:	41 8d 79 fc          	lea    edi,[r9-0x4]
    1189:	44 31 d7             	xor    edi,r10d
    118c:	81 f7 a5 00 00 00    	xor    edi,0xa5
    1192:	83 c7 11             	add    edi,0x11
    1195:	40 38 fe             	cmp    sil,dil
    1198:	75 4a                	jne    11e4 <payload_prefix_memcmp_scan_xdp+0xe4>
    119a:	0f b6 74 02 0f       	movzx  esi,BYTE PTR [rdx+rax*1+0xf]
    119f:	44 89 cf             	mov    edi,r9d
    11a2:	44 31 c7             	xor    edi,r8d
    11a5:	81 f7 a5 00 00 00    	xor    edi,0xa5
    11ab:	83 c7 11             	add    edi,0x11
    11ae:	48 83 c0 04          	add    rax,0x4
    11b2:	40 38 fe             	cmp    sil,dil
    11b5:	75 31                	jne    11e8 <payload_prefix_memcmp_scan_xdp+0xe8>
    11b7:	41 83 c0 74          	add    r8d,0x74
    11bb:	41 83 c1 10          	add    r9d,0x10
    11bf:	48 83 f8 40          	cmp    rax,0x40
    11c3:	0f 85 77 ff ff ff    	jne    1140 <payload_prefix_memcmp_scan_xdp+0x40>
    11c9:	0f b6 72 4b          	movzx  esi,BYTE PTR [rdx+0x4b]
    11cd:	48 b8 1c b5 f6 8c de 	movabs rax,0xf43e9fde8cf6b51c
    11d4:	9f 3e f4 
    11d7:	eb 2d                	jmp    1206 <payload_prefix_memcmp_scan_xdp+0x106>
    11d9:	48 ff c0             	inc    rax
    11dc:	eb 0a                	jmp    11e8 <payload_prefix_memcmp_scan_xdp+0xe8>
    11de:	48 83 c0 02          	add    rax,0x2
    11e2:	eb 04                	jmp    11e8 <payload_prefix_memcmp_scan_xdp+0xe8>
    11e4:	48 83 c0 03          	add    rax,0x3
    11e8:	89 c0                	mov    eax,eax
    11ea:	48 8d 04 80          	lea    rax,[rax+rax*4]
    11ee:	49 b8 09 c9 bc f3 67 	movabs r8,0x6a09e667f3bcc909
    11f5:	e6 09 6a 
    11f8:	49 01 c0             	add    r8,rax
    11fb:	40 0f b6 f6          	movzx  esi,sil
    11ff:	4c 31 c6             	xor    rsi,r8
    1202:	40 0f b6 c7          	movzx  eax,dil
    1206:	48 01 f0             	add    rax,rsi
    1209:	c4 e3 fb f0 c0 3b    	rorx   rax,rax,0x3b
    120f:	41 b9 57 00 00 00    	mov    r9d,0x57
    1215:	41 ba 0c 00 00 00    	mov    r10d,0xc
    121b:	31 f6                	xor    esi,esi
    121d:	0f 1f 00             	nop    DWORD PTR [rax]
    1220:	0f b6 7c 32 4c       	movzx  edi,BYTE PTR [rdx+rsi*1+0x4c]
    1225:	45 8d 59 a9          	lea    r11d,[r9-0x57]
    1229:	45 8d 42 f4          	lea    r8d,[r10-0xc]
    122d:	45 31 d8             	xor    r8d,r11d
    1230:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    1237:	41 83 c0 11          	add    r8d,0x11
    123b:	44 38 c7             	cmp    dil,r8b
    123e:	0f 85 8d 00 00 00    	jne    12d1 <payload_prefix_memcmp_scan_xdp+0x1d1>
    1244:	0f b6 7c 32 4d       	movzx  edi,BYTE PTR [rdx+rsi*1+0x4d]
    1249:	45 8d 59 c6          	lea    r11d,[r9-0x3a]
    124d:	45 8d 42 f8          	lea    r8d,[r10-0x8]
    1251:	45 31 d8             	xor    r8d,r11d
    1254:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    125b:	41 83 c0 11          	add    r8d,0x11
    125f:	44 38 c7             	cmp    dil,r8b
    1262:	75 72                	jne    12d6 <payload_prefix_memcmp_scan_xdp+0x1d6>
    1264:	0f b6 7c 32 4e       	movzx  edi,BYTE PTR [rdx+rsi*1+0x4e]
    1269:	45 8d 59 e3          	lea    r11d,[r9-0x1d]
    126d:	45 8d 42 fc          	lea    r8d,[r10-0x4]
    1271:	45 31 d8             	xor    r8d,r11d
    1274:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    127b:	41 83 c0 11          	add    r8d,0x11
    127f:	44 38 c7             	cmp    dil,r8b
    1282:	75 58                	jne    12dc <payload_prefix_memcmp_scan_xdp+0x1dc>
    1284:	0f b6 7c 32 4f       	movzx  edi,BYTE PTR [rdx+rsi*1+0x4f]
    1289:	45 89 d0             	mov    r8d,r10d
    128c:	45 31 c8             	xor    r8d,r9d
    128f:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    1296:	41 83 c0 11          	add    r8d,0x11
    129a:	48 83 c6 04          	add    rsi,0x4
    129e:	44 38 c7             	cmp    dil,r8b
    12a1:	75 3d                	jne    12e0 <payload_prefix_memcmp_scan_xdp+0x1e0>
    12a3:	41 83 c1 74          	add    r9d,0x74
    12a7:	41 83 c2 10          	add    r10d,0x10
    12ab:	48 83 fe 40          	cmp    rsi,0x40
    12af:	0f 85 6b ff ff ff    	jne    1220 <payload_prefix_memcmp_scan_xdp+0x120>
    12b5:	48 be 16 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c16
    12bc:	79 37 9e 
    12bf:	48 31 f0             	xor    rax,rsi
    12c2:	0f b6 b2 8b 00 00 00 	movzx  esi,BYTE PTR [rdx+0x8b]
    12c9:	c1 e6 08             	shl    esi,0x8
    12cc:	48 01 c6             	add    rsi,rax
    12cf:	eb 2a                	jmp    12fb <payload_prefix_memcmp_scan_xdp+0x1fb>
    12d1:	48 ff c6             	inc    rsi
    12d4:	eb 0a                	jmp    12e0 <payload_prefix_memcmp_scan_xdp+0x1e0>
    12d6:	48 83 c6 02          	add    rsi,0x2
    12da:	eb 04                	jmp    12e0 <payload_prefix_memcmp_scan_xdp+0x1e0>
    12dc:	48 83 c6 03          	add    rsi,0x3
    12e0:	89 f6                	mov    esi,esi
    12e2:	48 8d 34 76          	lea    rsi,[rsi+rsi*2]
    12e6:	48 8d 04 70          	lea    rax,[rax+rsi*2]
    12ea:	40 0f b6 ff          	movzx  edi,dil
    12ee:	c1 e7 08             	shl    edi,0x8
    12f1:	48 31 c7             	xor    rdi,rax
    12f4:	41 0f b6 f0          	movzx  esi,r8b
    12f8:	48 01 fe             	add    rsi,rdi
    12fb:	c4 e3 fb f0 c6 3a    	rorx   rax,rsi,0x3a
    1301:	41 b9 57 00 00 00    	mov    r9d,0x57
    1307:	41 ba 0c 00 00 00    	mov    r10d,0xc
    130d:	31 f6                	xor    esi,esi
    130f:	90                   	nop
    1310:	0f b6 bc 32 8c 00 00 	movzx  edi,BYTE PTR [rdx+rsi*1+0x8c]
    1317:	00 
    1318:	45 8d 59 a9          	lea    r11d,[r9-0x57]
    131c:	45 8d 42 f4          	lea    r8d,[r10-0xc]
    1320:	45 31 d8             	xor    r8d,r11d
    1323:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    132a:	41 83 c0 11          	add    r8d,0x11
    132e:	44 38 c7             	cmp    dil,r8b
    1331:	0f 85 ab 00 00 00    	jne    13e2 <payload_prefix_memcmp_scan_xdp+0x2e2>
    1337:	0f b6 bc 32 8d 00 00 	movzx  edi,BYTE PTR [rdx+rsi*1+0x8d]
    133e:	00 
    133f:	45 8d 59 c6          	lea    r11d,[r9-0x3a]
    1343:	45 8d 42 f8          	lea    r8d,[r10-0x8]
    1347:	45 31 d8             	xor    r8d,r11d
    134a:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    1351:	41 83 c0 11          	add    r8d,0x11
    1355:	44 38 c7             	cmp    dil,r8b
    1358:	0f 85 89 00 00 00    	jne    13e7 <payload_prefix_memcmp_scan_xdp+0x2e7>
    135e:	0f b6 bc 32 8e 00 00 	movzx  edi,BYTE PTR [rdx+rsi*1+0x8e]
    1365:	00 
    1366:	45 8d 59 e3          	lea    r11d,[r9-0x1d]
    136a:	45 8d 42 fc          	lea    r8d,[r10-0x4]
    136e:	45 31 d8             	xor    r8d,r11d
    1371:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    1378:	41 83 c0 11          	add    r8d,0x11
    137c:	44 38 c7             	cmp    dil,r8b
    137f:	75 6c                	jne    13ed <payload_prefix_memcmp_scan_xdp+0x2ed>
    1381:	0f b6 bc 32 8f 00 00 	movzx  edi,BYTE PTR [rdx+rsi*1+0x8f]
    1388:	00 
    1389:	45 89 d0             	mov    r8d,r10d
    138c:	45 31 c8             	xor    r8d,r9d
    138f:	41 81 f0 a5 00 00 00 	xor    r8d,0xa5
    1396:	41 83 c0 11          	add    r8d,0x11
    139a:	48 83 c6 04          	add    rsi,0x4
    139e:	44 38 c7             	cmp    dil,r8b
    13a1:	75 4e                	jne    13f1 <payload_prefix_memcmp_scan_xdp+0x2f1>
    13a3:	41 83 c1 74          	add    r9d,0x74
    13a7:	41 83 c2 10          	add    r10d,0x10
    13ab:	48 83 fe 40          	cmp    rsi,0x40
    13af:	0f 85 5b ff ff ff    	jne    1310 <payload_prefix_memcmp_scan_xdp+0x210>
    13b5:	48 be 16 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c16
    13bc:	79 37 9e 
    13bf:	48 83 ce 01          	or     rsi,0x1
    13c3:	48 31 f0             	xor    rax,rsi
    13c6:	0f b6 92 cb 00 00 00 	movzx  edx,BYTE PTR [rdx+0xcb]
    13cd:	c1 e2 10             	shl    edx,0x10
    13d0:	48 01 c2             	add    rdx,rax
    13d3:	c4 e3 fb f0 c2 39    	rorx   rax,rdx,0x39
    13d9:	48 89 01             	mov    QWORD PTR [rcx],rax
    13dc:	b8 02 00 00 00       	mov    eax,0x2
    13e1:	c3                   	ret
    13e2:	48 ff c6             	inc    rsi
    13e5:	eb 0a                	jmp    13f1 <payload_prefix_memcmp_scan_xdp+0x2f1>
    13e7:	48 83 c6 02          	add    rsi,0x2
    13eb:	eb 04                	jmp    13f1 <payload_prefix_memcmp_scan_xdp+0x2f1>
    13ed:	48 83 c6 03          	add    rsi,0x3
    13f1:	89 f2                	mov    edx,esi
    13f3:	48 8d 34 d5 00 00 00 	lea    rsi,[rdx*8+0x0]
    13fa:	00 
    13fb:	48 29 d6             	sub    rsi,rdx
    13fe:	48 01 f0             	add    rax,rsi
    1401:	40 0f b6 f7          	movzx  esi,dil
    1405:	c1 e6 10             	shl    esi,0x10
    1408:	48 31 c6             	xor    rsi,rax
    140b:	41 0f b6 d0          	movzx  edx,r8b
    140f:	48 01 f2             	add    rdx,rsi
    1412:	c4 e3 fb f0 c2 39    	rorx   rax,rdx,0x39
    1418:	48 89 01             	mov    QWORD PTR [rcx],rax
    141b:	b8 02 00 00 00       	mov    eax,0x2
    1420:	c3                   	ret

Disassembly of section .fini:

0000000000001424 <_fini>:
    1424:	f3 0f 1e fa          	endbr64
    1428:	48 83 ec 08          	sub    rsp,0x8
    142c:	48 83 c4 08          	add    rsp,0x8
    1430:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
