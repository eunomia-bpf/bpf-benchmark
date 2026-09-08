# packet_toeplitz_rss_hash

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

0000000000001100 <packet_toeplitz_rss_hash_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <packet_toeplitz_rss_hash_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <packet_toeplitz_rss_hash_xdp+0x11>
    111b:	48 8d 7a 3e          	lea    rdi,[rdx+0x3e]
    111f:	48 39 f7             	cmp    rdi,rsi
    1122:	77 ed                	ja     1111 <packet_toeplitz_rss_hash_xdp+0x11>
    1124:	66 0f 38 f0 72 14    	movbe  si,WORD PTR [rdx+0x14]
    112a:	0f b7 f6             	movzx  esi,si
    112d:	81 fe 00 08 00 00    	cmp    esi,0x800
    1133:	75 dc                	jne    1111 <packet_toeplitz_rss_hash_xdp+0x11>
    1135:	0f b6 72 16          	movzx  esi,BYTE PTR [rdx+0x16]
    1139:	40 80 e6 0f          	and    sil,0xf
    113d:	40 80 fe 05          	cmp    sil,0x5
    1141:	75 ce                	jne    1111 <packet_toeplitz_rss_hash_xdp+0x11>
    1143:	80 7a 1f 06          	cmp    BYTE PTR [rdx+0x1f],0x6
    1147:	75 c8                	jne    1111 <packet_toeplitz_rss_hash_xdp+0x11>
    1149:	53                   	push   rbx
    114a:	48 8d 72 1f          	lea    rsi,[rdx+0x1f]
    114e:	48 89 d7             	mov    rdi,rdx
    1151:	48 83 c7 22          	add    rdi,0x22
    1155:	31 c0                	xor    eax,eax
    1157:	45 31 c0             	xor    r8d,r8d
    115a:	eb 37                	jmp    1193 <packet_toeplitz_rss_hash_xdp+0x93>
    115c:	bb c2 00 00 00       	mov    ebx,0xc2
    1161:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1168:	0f 1f 84 00 00 00 00 
    116f:	00 
    1170:	c4 42 31 f7 d3       	shlx   r10d,r11d,r9d
    1175:	41 b3 08             	mov    r11b,0x8
    1178:	45 28 cb             	sub    r11b,r9b
    117b:	c4 62 23 f7 db       	shrx   r11d,ebx,r11d
    1180:	45 09 d3             	or     r11d,r10d
    1183:	44 31 d8             	xor    eax,r11d
    1186:	41 ff c0             	inc    r8d
    1189:	41 83 f8 68          	cmp    r8d,0x68
    118d:	0f 84 25 02 00 00    	je     13b8 <packet_toeplitz_rss_hash_xdp+0x2b8>
    1193:	45 89 c2             	mov    r10d,r8d
    1196:	41 c1 ea 03          	shr    r10d,0x3
    119a:	41 83 f8 1f          	cmp    r8d,0x1f
    119e:	76 20                	jbe    11c0 <packet_toeplitz_rss_hash_xdp+0xc0>
    11a0:	41 83 f8 3f          	cmp    r8d,0x3f
    11a4:	76 1a                	jbe    11c0 <packet_toeplitz_rss_hash_xdp+0xc0>
    11a6:	41 83 f8 4f          	cmp    r8d,0x4f
    11aa:	76 14                	jbe    11c0 <packet_toeplitz_rss_hash_xdp+0xc0>
    11ac:	49 89 f1             	mov    r9,rsi
    11af:	41 83 f8 5f          	cmp    r8d,0x5f
    11b3:	77 11                	ja     11c6 <packet_toeplitz_rss_hash_xdp+0xc6>
    11b5:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    11bc:	00 00 00 00 
    11c0:	45 89 d1             	mov    r9d,r10d
    11c3:	49 01 f9             	add    r9,rdi
    11c6:	45 0f b6 19          	movzx  r11d,BYTE PTR [r9]
    11ca:	45 89 c1             	mov    r9d,r8d
    11cd:	41 83 e1 07          	and    r9d,0x7
    11d1:	c4 42 31 f7 db       	shlx   r11d,r11d,r9d
    11d6:	45 84 db             	test   r11b,r11b
    11d9:	79 ab                	jns    1186 <packet_toeplitz_rss_hash_xdp+0x86>
    11db:	41 83 fa 05          	cmp    r10d,0x5
    11df:	7e 2f                	jle    1210 <packet_toeplitz_rss_hash_xdp+0x110>
    11e1:	41 83 fa 08          	cmp    r10d,0x8
    11e5:	7e 4e                	jle    1235 <packet_toeplitz_rss_hash_xdp+0x135>
    11e7:	41 83 fa 0a          	cmp    r10d,0xa
    11eb:	0f 8f 7c 00 00 00    	jg     126d <packet_toeplitz_rss_hash_xdp+0x16d>
    11f1:	41 83 fa 09          	cmp    r10d,0x9
    11f5:	0f 85 b9 00 00 00    	jne    12b4 <packet_toeplitz_rss_hash_xdp+0x1b4>
    11fb:	bb 43 00 00 00       	mov    ebx,0x43
    1200:	41 bb 00 3d 25 67    	mov    r11d,0x67253d00
    1206:	e9 e5 00 00 00       	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    120b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1210:	41 83 fa 02          	cmp    r10d,0x2
    1214:	7f 3b                	jg     1251 <packet_toeplitz_rss_hash_xdp+0x151>
    1216:	45 85 d2             	test   r10d,r10d
    1219:	74 72                	je     128d <packet_toeplitz_rss_hash_xdp+0x18d>
    121b:	41 83 fa 01          	cmp    r10d,0x1
    121f:	0f 85 a9 00 00 00    	jne    12ce <packet_toeplitz_rss_hash_xdp+0x1ce>
    1225:	bb 25 00 00 00       	mov    ebx,0x25
    122a:	41 bb 00 da 56 5a    	mov    r11d,0x5a56da00
    1230:	e9 bb 00 00 00       	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    1235:	41 83 fa 06          	cmp    r10d,0x6
    1239:	74 45                	je     1280 <packet_toeplitz_rss_hash_xdp+0x180>
    123b:	41 83 fa 07          	cmp    r10d,0x7
    123f:	75 66                	jne    12a7 <packet_toeplitz_rss_hash_xdp+0x1a7>
    1241:	bb 25 00 00 00       	mov    ebx,0x25
    1246:	41 bb 00 67 41 c2    	mov    r11d,0xc2416700
    124c:	e9 9f 00 00 00       	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    1251:	41 83 fa 03          	cmp    r10d,0x3
    1255:	74 43                	je     129a <packet_toeplitz_rss_hash_xdp+0x19a>
    1257:	41 83 fa 04          	cmp    r10d,0x4
    125b:	75 7e                	jne    12db <packet_toeplitz_rss_hash_xdp+0x1db>
    125d:	bb c2 00 00 00       	mov    ebx,0xc2
    1262:	41 bb 00 0e 5b 25    	mov    r11d,0x255b0e00
    1268:	e9 83 00 00 00       	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    126d:	41 83 fa 0b          	cmp    r10d,0xb
    1271:	75 4e                	jne    12c1 <packet_toeplitz_rss_hash_xdp+0x1c1>
    1273:	bb 8f 00 00 00       	mov    ebx,0x8f
    1278:	41 bb 00 a3 43 3d    	mov    r11d,0x3d43a300
    127e:	eb 70                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    1280:	bb 67 00 00 00       	mov    ebx,0x67
    1285:	41 bb 00 41 c2 0e    	mov    r11d,0xec24100
    128b:	eb 63                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    128d:	bb da 00 00 00       	mov    ebx,0xda
    1292:	41 bb 00 56 5a 6d    	mov    r11d,0x6d5a5600
    1298:	eb 56                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    129a:	bb 0e 00 00 00       	mov    ebx,0xe
    129f:	41 bb 00 5b 25 da    	mov    r11d,0xda255b00
    12a5:	eb 49                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    12a7:	bb 3d 00 00 00       	mov    ebx,0x3d
    12ac:	41 bb 00 25 67 41    	mov    r11d,0x41672500
    12b2:	eb 3c                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    12b4:	bb a3 00 00 00       	mov    ebx,0xa3
    12b9:	41 bb 00 43 3d 25    	mov    r11d,0x253d4300
    12bf:	eb 2f                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    12c1:	bb b0 00 00 00       	mov    ebx,0xb0
    12c6:	41 bb 00 8f a3 43    	mov    r11d,0x43a38f00
    12cc:	eb 22                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    12ce:	bb 5b 00 00 00       	mov    ebx,0x5b
    12d3:	41 bb 00 25 da 56    	mov    r11d,0x56da2500
    12d9:	eb 15                	jmp    12f0 <packet_toeplitz_rss_hash_xdp+0x1f0>
    12db:	bb 41 00 00 00       	mov    ebx,0x41
    12e0:	41 bb 00 c2 0e 5b    	mov    r11d,0x5b0ec200
    12e6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    12ed:	00 00 00 
    12f0:	41 09 db             	or     r11d,ebx
    12f3:	45 85 c9             	test   r9d,r9d
    12f6:	0f 84 87 fe ff ff    	je     1183 <packet_toeplitz_rss_hash_xdp+0x83>
    12fc:	bb 25 00 00 00       	mov    ebx,0x25
    1301:	41 83 fa 05          	cmp    r10d,0x5
    1305:	7e 1c                	jle    1323 <packet_toeplitz_rss_hash_xdp+0x223>
    1307:	41 83 fa 08          	cmp    r10d,0x8
    130b:	7e 35                	jle    1342 <packet_toeplitz_rss_hash_xdp+0x242>
    130d:	41 83 fa 0a          	cmp    r10d,0xa
    1311:	7f 63                	jg     1376 <packet_toeplitz_rss_hash_xdp+0x276>
    1313:	41 83 fa 09          	cmp    r10d,0x9
    1317:	75 77                	jne    1390 <packet_toeplitz_rss_hash_xdp+0x290>
    1319:	bb a3 00 00 00       	mov    ebx,0xa3
    131e:	e9 4d fe ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    1323:	41 83 fa 02          	cmp    r10d,0x2
    1327:	7f 33                	jg     135c <packet_toeplitz_rss_hash_xdp+0x25c>
    1329:	45 85 d2             	test   r10d,r10d
    132c:	0f 84 3e fe ff ff    	je     1170 <packet_toeplitz_rss_hash_xdp+0x70>
    1332:	41 83 fa 01          	cmp    r10d,0x1
    1336:	75 6c                	jne    13a4 <packet_toeplitz_rss_hash_xdp+0x2a4>
    1338:	bb 5b 00 00 00       	mov    ebx,0x5b
    133d:	e9 2e fe ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    1342:	41 83 fa 06          	cmp    r10d,0x6
    1346:	0f 84 24 fe ff ff    	je     1170 <packet_toeplitz_rss_hash_xdp+0x70>
    134c:	41 83 fa 07          	cmp    r10d,0x7
    1350:	75 34                	jne    1386 <packet_toeplitz_rss_hash_xdp+0x286>
    1352:	bb 3d 00 00 00       	mov    ebx,0x3d
    1357:	e9 14 fe ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    135c:	41 83 fa 03          	cmp    r10d,0x3
    1360:	0f 84 f6 fd ff ff    	je     115c <packet_toeplitz_rss_hash_xdp+0x5c>
    1366:	41 83 fa 04          	cmp    r10d,0x4
    136a:	75 42                	jne    13ae <packet_toeplitz_rss_hash_xdp+0x2ae>
    136c:	bb 41 00 00 00       	mov    ebx,0x41
    1371:	e9 fa fd ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    1376:	41 83 fa 0b          	cmp    r10d,0xb
    137a:	75 1e                	jne    139a <packet_toeplitz_rss_hash_xdp+0x29a>
    137c:	bb b0 00 00 00       	mov    ebx,0xb0
    1381:	e9 ea fd ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    1386:	bb 43 00 00 00       	mov    ebx,0x43
    138b:	e9 e0 fd ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    1390:	bb 8f 00 00 00       	mov    ebx,0x8f
    1395:	e9 d6 fd ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    139a:	bb d0 00 00 00       	mov    ebx,0xd0
    139f:	e9 cc fd ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    13a4:	bb 0e 00 00 00       	mov    ebx,0xe
    13a9:	e9 c2 fd ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    13ae:	bb 67 00 00 00       	mov    ebx,0x67
    13b3:	e9 b8 fd ff ff       	jmp    1170 <packet_toeplitz_rss_hash_xdp+0x70>
    13b8:	8b 72 26             	mov    esi,DWORD PTR [rdx+0x26]
    13bb:	0f b6 7a 2a          	movzx  edi,BYTE PTR [rdx+0x2a]
    13bf:	44 0f b6 42 2b       	movzx  r8d,BYTE PTR [rdx+0x2b]
    13c4:	44 0f b6 4a 2c       	movzx  r9d,BYTE PTR [rdx+0x2c]
    13c9:	44 0f b6 52 2d       	movzx  r10d,BYTE PTR [rdx+0x2d]
    13ce:	49 89 c3             	mov    r11,rax
    13d1:	49 c1 e3 20          	shl    r11,0x20
    13d5:	33 72 22             	xor    esi,DWORD PTR [rdx+0x22]
    13d8:	0f ce                	bswap  esi
    13da:	89 f2                	mov    edx,esi
    13dc:	31 c2                	xor    edx,eax
    13de:	4c 09 da             	or     rdx,r11
    13e1:	48 c1 e7 38          	shl    rdi,0x38
    13e5:	49 c1 e0 30          	shl    r8,0x30
    13e9:	49 09 f8             	or     r8,rdi
    13ec:	49 c1 e1 28          	shl    r9,0x28
    13f0:	4d 09 c1             	or     r9,r8
    13f3:	49 c1 e2 20          	shl    r10,0x20
    13f7:	4c 09 ce             	or     rsi,r9
    13fa:	4c 09 d6             	or     rsi,r10
    13fd:	83 e0 07             	and    eax,0x7
    1400:	8d 78 01             	lea    edi,[rax+0x1]
    1403:	c4 e2 c1 f7 fe       	shlx   rdi,rsi,rdi
    1408:	f6 d0                	not    al
    140a:	c4 e2 fb f7 c6       	shrx   rax,rsi,rax
    140f:	48 09 f8             	or     rax,rdi
    1412:	48 31 d0             	xor    rax,rdx
    1415:	48 89 01             	mov    QWORD PTR [rcx],rax
    1418:	b8 02 00 00 00       	mov    eax,0x2
    141d:	5b                   	pop    rbx
    141e:	c3                   	ret

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
