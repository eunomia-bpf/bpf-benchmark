# tracee_http_method_prefix_detect

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

0000000000001100 <tracee_http_method_prefix_detect_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <tracee_http_method_prefix_detect_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <tracee_http_method_prefix_detect_xdp+0x11>
    111b:	48 8d ba 90 00 00 00 	lea    rdi,[rdx+0x90]
    1122:	48 39 f7             	cmp    rdi,rsi
    1125:	77 ea                	ja     1111 <tracee_http_method_prefix_detect_xdp+0x11>
    1127:	83 7a 08 08          	cmp    DWORD PTR [rdx+0x8],0x8
    112b:	75 e4                	jne    1111 <tracee_http_method_prefix_detect_xdp+0x11>
    112d:	83 7a 0c 10          	cmp    DWORD PTR [rdx+0xc],0x10
    1131:	75 de                	jne    1111 <tracee_http_method_prefix_detect_xdp+0x11>
    1133:	41 56                	push   r14
    1135:	53                   	push   rbx
    1136:	48 83 c2 16          	add    rdx,0x16
    113a:	48 bb 2f 64 bd 78 64 	movabs rbx,0xa0761d6478bd642f
    1141:	1d 76 a0 
    1144:	b8 01 00 00 00       	mov    eax,0x1
    1149:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1150:	48 89 de             	mov    rsi,rbx
    1153:	0f b6 7a fa          	movzx  edi,BYTE PTR [rdx-0x6]
    1157:	44 0f b6 42 fb       	movzx  r8d,BYTE PTR [rdx-0x5]
    115c:	83 ff 47             	cmp    edi,0x47
    115f:	7f 4f                	jg     11b0 <tracee_http_method_prefix_detect_xdp+0xb0>
    1161:	83 ff 44             	cmp    edi,0x44
    1164:	0f 84 a5 00 00 00    	je     120f <tracee_http_method_prefix_detect_xdp+0x10f>
    116a:	83 ff 47             	cmp    edi,0x47
    116d:	0f 85 6d 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1173:	41 80 f8 45          	cmp    r8b,0x45
    1177:	0f 85 63 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    117d:	41 b0 45             	mov    r8b,0x45
    1180:	80 7a fc 54          	cmp    BYTE PTR [rdx-0x4],0x54
    1184:	0f 85 56 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    118a:	41 b2 45             	mov    r10b,0x45
    118d:	80 7a fd 20          	cmp    BYTE PTR [rdx-0x3],0x20
    1191:	0f 85 49 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1197:	41 b9 01 00 00 00    	mov    r9d,0x1
    119d:	e9 09 01 00 00       	jmp    12ab <tracee_http_method_prefix_detect_xdp+0x1ab>
    11a2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11a9:	1f 84 00 00 00 00 00 
    11b0:	45 0f b6 c8          	movzx  r9d,r8b
    11b4:	83 ff 48             	cmp    edi,0x48
    11b7:	0f 84 a4 00 00 00    	je     1261 <tracee_http_method_prefix_detect_xdp+0x161>
    11bd:	83 ff 50             	cmp    edi,0x50
    11c0:	0f 85 1a 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11c6:	41 83 f9 55          	cmp    r9d,0x55
    11ca:	0f 84 c3 00 00 00    	je     1293 <tracee_http_method_prefix_detect_xdp+0x193>
    11d0:	41 83 f9 4f          	cmp    r9d,0x4f
    11d4:	0f 85 06 01 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11da:	41 b0 4f             	mov    r8b,0x4f
    11dd:	80 7a fc 53          	cmp    BYTE PTR [rdx-0x4],0x53
    11e1:	0f 85 f9 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11e7:	80 7a fd 54          	cmp    BYTE PTR [rdx-0x3],0x54
    11eb:	0f 85 ef 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11f1:	41 b2 4f             	mov    r10b,0x4f
    11f4:	80 7a fe 20          	cmp    BYTE PTR [rdx-0x2],0x20
    11f8:	0f 85 e2 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    11fe:	41 b9 02 00 00 00    	mov    r9d,0x2
    1204:	41 b0 53             	mov    r8b,0x53
    1207:	41 b3 54             	mov    r11b,0x54
    120a:	e9 e1 00 00 00       	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    120f:	41 80 f8 45          	cmp    r8b,0x45
    1213:	0f 85 c7 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1219:	41 b0 45             	mov    r8b,0x45
    121c:	80 7a fc 4c          	cmp    BYTE PTR [rdx-0x4],0x4c
    1220:	0f 85 ba 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1226:	80 7a fd 45          	cmp    BYTE PTR [rdx-0x3],0x45
    122a:	0f 85 b0 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1230:	80 7a fe 54          	cmp    BYTE PTR [rdx-0x2],0x54
    1234:	0f 85 a6 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    123a:	80 7a ff 45          	cmp    BYTE PTR [rdx-0x1],0x45
    123e:	0f 85 9c 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1244:	41 b3 45             	mov    r11b,0x45
    1247:	80 3a 20             	cmp    BYTE PTR [rdx],0x20
    124a:	0f 85 90 00 00 00    	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1250:	41 b9 04 00 00 00    	mov    r9d,0x4
    1256:	41 b0 4c             	mov    r8b,0x4c
    1259:	41 b2 45             	mov    r10b,0x45
    125c:	e9 8f 00 00 00       	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    1261:	41 83 f9 54          	cmp    r9d,0x54
    1265:	74 4c                	je     12b3 <tracee_http_method_prefix_detect_xdp+0x1b3>
    1267:	41 83 f9 45          	cmp    r9d,0x45
    126b:	75 73                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    126d:	41 b0 45             	mov    r8b,0x45
    1270:	80 7a fc 41          	cmp    BYTE PTR [rdx-0x4],0x41
    1274:	75 6a                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1276:	80 7a fd 44          	cmp    BYTE PTR [rdx-0x3],0x44
    127a:	75 64                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    127c:	41 b2 45             	mov    r10b,0x45
    127f:	80 7a fe 20          	cmp    BYTE PTR [rdx-0x2],0x20
    1283:	75 5b                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    1285:	41 b9 05 00 00 00    	mov    r9d,0x5
    128b:	41 b0 41             	mov    r8b,0x41
    128e:	41 b3 44             	mov    r11b,0x44
    1291:	eb 5d                	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    1293:	41 b0 55             	mov    r8b,0x55
    1296:	80 7a fc 54          	cmp    BYTE PTR [rdx-0x4],0x54
    129a:	75 44                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    129c:	41 b2 55             	mov    r10b,0x55
    129f:	80 7a fd 20          	cmp    BYTE PTR [rdx-0x3],0x20
    12a3:	75 3b                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12a5:	41 b9 03 00 00 00    	mov    r9d,0x3
    12ab:	41 b0 54             	mov    r8b,0x54
    12ae:	41 b3 20             	mov    r11b,0x20
    12b1:	eb 3d                	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    12b3:	41 b0 54             	mov    r8b,0x54
    12b6:	80 7a fc 54          	cmp    BYTE PTR [rdx-0x4],0x54
    12ba:	75 24                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12bc:	80 7a fd 50          	cmp    BYTE PTR [rdx-0x3],0x50
    12c0:	75 1e                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12c2:	80 7a fe 2f          	cmp    BYTE PTR [rdx-0x2],0x2f
    12c6:	75 18                	jne    12e0 <tracee_http_method_prefix_detect_xdp+0x1e0>
    12c8:	41 b9 06 00 00 00    	mov    r9d,0x6
    12ce:	41 b3 50             	mov    r11b,0x50
    12d1:	41 b2 54             	mov    r10b,0x54
    12d4:	eb 1a                	jmp    12f0 <tracee_http_method_prefix_detect_xdp+0x1f0>
    12d6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    12dd:	00 00 00 
    12e0:	45 89 c2             	mov    r10d,r8d
    12e3:	44 0f b6 42 fc       	movzx  r8d,BYTE PTR [rdx-0x4]
    12e8:	44 0f b6 5a fd       	movzx  r11d,BYTE PTR [rdx-0x3]
    12ed:	45 31 c9             	xor    r9d,r9d
    12f0:	45 0f b6 db          	movzx  r11d,r11b
    12f4:	41 8d 59 01          	lea    ebx,[r9+0x1]
    12f8:	4c 8d 70 0a          	lea    r14,[rax+0xa]
    12fc:	49 0f af de          	imul   rbx,r14
    1300:	48 01 de             	add    rsi,rbx
    1303:	49 c1 e3 20          	shl    r11,0x20
    1307:	45 0f b6 c0          	movzx  r8d,r8b
    130b:	41 c1 e0 18          	shl    r8d,0x18
    130f:	45 0f b6 d2          	movzx  r10d,r10b
    1313:	41 c1 e2 10          	shl    r10d,0x10
    1317:	c1 e7 08             	shl    edi,0x8
    131a:	44 09 d7             	or     edi,r10d
    131d:	44 09 c7             	or     edi,r8d
    1320:	4c 09 df             	or     rdi,r11
    1323:	45 89 c8             	mov    r8d,r9d
    1326:	49 09 f8             	or     r8,rdi
    1329:	c4 c2 f9 f7 d8       	shlx   rbx,r8,rax
    132e:	48 31 f3             	xor    rbx,rsi
    1331:	48 83 c2 10          	add    rdx,0x10
    1335:	48 ff c0             	inc    rax
    1338:	48 83 f8 09          	cmp    rax,0x9
    133c:	0f 85 0e fe ff ff    	jne    1150 <tracee_http_method_prefix_detect_xdp+0x50>
    1342:	40 88 31             	mov    BYTE PTR [rcx],sil
    1345:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    1348:	89 d8                	mov    eax,ebx
    134a:	c1 e8 10             	shr    eax,0x10
    134d:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
    1350:	89 d8                	mov    eax,ebx
    1352:	c1 e8 18             	shr    eax,0x18
    1355:	88 41 03             	mov    BYTE PTR [rcx+0x3],al
    1358:	48 89 d8             	mov    rax,rbx
    135b:	48 c1 e8 20          	shr    rax,0x20
    135f:	88 41 04             	mov    BYTE PTR [rcx+0x4],al
    1362:	48 89 d8             	mov    rax,rbx
    1365:	48 c1 e8 28          	shr    rax,0x28
    1369:	88 41 05             	mov    BYTE PTR [rcx+0x5],al
    136c:	48 89 d8             	mov    rax,rbx
    136f:	48 c1 e8 30          	shr    rax,0x30
    1373:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
    1376:	48 c1 eb 38          	shr    rbx,0x38
    137a:	88 59 07             	mov    BYTE PTR [rcx+0x7],bl
    137d:	b8 02 00 00 00       	mov    eax,0x2
    1382:	5b                   	pop    rbx
    1383:	41 5e                	pop    r14
    1385:	c3                   	ret

Disassembly of section .fini:

0000000000001388 <_fini>:
    1388:	f3 0f 1e fa          	endbr64
    138c:	48 83 ec 08          	sub    rsp,0x8
    1390:	48 83 c4 08          	add    rsp,0x8
    1394:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
