# packet_vlan_tcpopt_parser

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

0000000000001100 <packet_vlan_tcpopt_parser_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	4c 8b 57 08          	mov    r10,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	4c 39 d2             	cmp    rdx,r10
    110c:	0f 87 98 02 00 00    	ja     13aa <packet_vlan_tcpopt_parser_xdp+0x2aa>
    1112:	48 8d 4a 08          	lea    rcx,[rdx+0x8]
    1116:	4c 39 d1             	cmp    rcx,r10
    1119:	0f 87 8b 02 00 00    	ja     13aa <packet_vlan_tcpopt_parser_xdp+0x2aa>
    111f:	4c 8d 4a 16          	lea    r9,[rdx+0x16]
    1123:	4d 39 d1             	cmp    r9,r10
    1126:	0f 87 7e 02 00 00    	ja     13aa <packet_vlan_tcpopt_parser_xdp+0x2aa>
    112c:	55                   	push   rbp
    112d:	41 57                	push   r15
    112f:	41 56                	push   r14
    1131:	53                   	push   rbx
    1132:	66 0f 38 f0 42 14    	movbe  ax,WORD PTR [rdx+0x14]
    1138:	0f b7 c8             	movzx  ecx,ax
    113b:	31 c0                	xor    eax,eax
    113d:	81 f9 00 08 00 00    	cmp    ecx,0x800
    1143:	0f 84 94 00 00 00    	je     11dd <packet_vlan_tcpopt_parser_xdp+0xdd>
    1149:	81 f9 a8 88 00 00    	cmp    ecx,0x88a8
    114f:	74 0c                	je     115d <packet_vlan_tcpopt_parser_xdp+0x5d>
    1151:	81 f9 00 81 00 00    	cmp    ecx,0x8100
    1157:	0f 85 47 02 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    115d:	4c 8d 4a 1a          	lea    r9,[rdx+0x1a]
    1161:	4d 39 d1             	cmp    r9,r10
    1164:	0f 87 3a 02 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    116a:	66 0f 38 f0 72 16    	movbe  si,WORD PTR [rdx+0x16]
    1170:	66 0f 38 f0 4a 18    	movbe  cx,WORD PTR [rdx+0x18]
    1176:	0f b7 c9             	movzx  ecx,cx
    1179:	81 f9 00 08 00 00    	cmp    ecx,0x800
    117f:	0f 84 0d 02 00 00    	je     1392 <packet_vlan_tcpopt_parser_xdp+0x292>
    1185:	81 f9 a8 88 00 00    	cmp    ecx,0x88a8
    118b:	74 0c                	je     1199 <packet_vlan_tcpopt_parser_xdp+0x99>
    118d:	81 f9 00 81 00 00    	cmp    ecx,0x8100
    1193:	0f 85 0b 02 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1199:	48 8d 4a 1e          	lea    rcx,[rdx+0x1e]
    119d:	4c 39 d1             	cmp    rcx,r10
    11a0:	0f 87 fe 01 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    11a6:	66 0f 38 f0 4a 1c    	movbe  cx,WORD PTR [rdx+0x1c]
    11ac:	0f b7 c9             	movzx  ecx,cx
    11af:	81 f9 00 08 00 00    	cmp    ecx,0x800
    11b5:	0f 85 e9 01 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    11bb:	48 8d 4a 32          	lea    rcx,[rdx+0x32]
    11bf:	4c 39 d1             	cmp    rcx,r10
    11c2:	0f 87 dc 01 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    11c8:	4c 8d 4a 1e          	lea    r9,[rdx+0x1e]
    11cc:	66 0f 38 f0 4a 1a    	movbe  cx,WORD PTR [rdx+0x1a]
    11d2:	44 0f b7 c1          	movzx  r8d,cx
    11d6:	b9 02 00 00 00       	mov    ecx,0x2
    11db:	eb 14                	jmp    11f1 <packet_vlan_tcpopt_parser_xdp+0xf1>
    11dd:	31 f6                	xor    esi,esi
    11df:	31 c9                	xor    ecx,ecx
    11e1:	49 8d 79 14          	lea    rdi,[r9+0x14]
    11e5:	4c 39 d7             	cmp    rdi,r10
    11e8:	0f 87 b6 01 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    11ee:	45 31 c0             	xor    r8d,r8d
    11f1:	41 0f b6 39          	movzx  edi,BYTE PTR [r9]
    11f5:	41 89 fb             	mov    r11d,edi
    11f8:	41 80 e3 f0          	and    r11b,0xf0
    11fc:	41 80 fb 40          	cmp    r11b,0x40
    1200:	0f 85 9e 01 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1206:	83 e7 0f             	and    edi,0xf
    1209:	40 80 ff 05          	cmp    dil,0x5
    120d:	0f 82 91 01 00 00    	jb     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1213:	49 8d 1c b9          	lea    rbx,[r9+rdi*4]
    1217:	4c 39 d3             	cmp    rbx,r10
    121a:	0f 87 84 01 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1220:	41 80 79 09 06       	cmp    BYTE PTR [r9+0x9],0x6
    1225:	0f 85 79 01 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    122b:	4c 8d 73 14          	lea    r14,[rbx+0x14]
    122f:	4d 39 d6             	cmp    r14,r10
    1232:	0f 87 6c 01 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1238:	44 0f b6 5b 0c       	movzx  r11d,BYTE PTR [rbx+0xc]
    123d:	49 83 fb 50          	cmp    r11,0x50
    1241:	0f 82 5d 01 00 00    	jb     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1247:	41 c1 eb 02          	shr    r11d,0x2
    124b:	41 83 e3 fc          	and    r11d,0xfffffffc
    124f:	4e 8d 3c 1b          	lea    r15,[rbx+r11*1]
    1253:	4d 39 d7             	cmp    r15,r10
    1256:	0f 87 48 01 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    125c:	4c 8d 7b 20          	lea    r15,[rbx+0x20]
    1260:	4d 39 d7             	cmp    r15,r10
    1263:	0f 87 3b 01 00 00    	ja     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1269:	41 80 fb 20          	cmp    r11b,0x20
    126d:	0f 82 31 01 00 00    	jb     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1273:	41 80 3e 02          	cmp    BYTE PTR [r14],0x2
    1277:	0f 85 27 01 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    127d:	80 7b 15 04          	cmp    BYTE PTR [rbx+0x15],0x4
    1281:	0f 82 1d 01 00 00    	jb     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1287:	80 7b 18 01          	cmp    BYTE PTR [rbx+0x18],0x1
    128b:	0f 85 13 01 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1291:	80 7b 19 03          	cmp    BYTE PTR [rbx+0x19],0x3
    1295:	0f 85 09 01 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    129b:	80 7b 1a 03          	cmp    BYTE PTR [rbx+0x1a],0x3
    129f:	0f 82 ff 00 00 00    	jb     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    12a5:	80 7b 1c 04          	cmp    BYTE PTR [rbx+0x1c],0x4
    12a9:	0f 85 f5 00 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    12af:	80 7b 1d 02          	cmp    BYTE PTR [rbx+0x1d],0x2
    12b3:	0f 82 eb 00 00 00    	jb     13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    12b9:	80 7b 1e 01          	cmp    BYTE PTR [rbx+0x1e],0x1
    12bd:	0f 85 e1 00 00 00    	jne    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    12c3:	66 41 0f 38 f0 41 02 	movbe  ax,WORD PTR [r9+0x2]
    12ca:	48 c1 e7 02          	shl    rdi,0x2
    12ce:	45 0f 38 f0 51 0c    	movbe  r10d,DWORD PTR [r9+0xc]
    12d4:	66 0f 38 f0 2b       	movbe  bp,WORD PTR [rbx]
    12d9:	0f b7 c0             	movzx  eax,ax
    12dc:	44 0f b7 f5          	movzx  r14d,bp
    12e0:	49 01 c6             	add    r14,rax
    12e3:	66 0f 38 f0 43 02    	movbe  ax,WORD PTR [rbx+0x2]
    12e9:	45 0f 38 f0 49 10    	movbe  r9d,DWORD PTR [r9+0x10]
    12ef:	0f b7 c0             	movzx  eax,ax
    12f2:	4c 01 f0             	add    rax,r14
    12f5:	4c 31 d0             	xor    rax,r10
    12f8:	4c 01 c8             	add    rax,r9
    12fb:	44 0f b6 4b 16       	movzx  r9d,BYTE PTR [rbx+0x16]
    1300:	45 89 ca             	mov    r10d,r9d
    1303:	41 c1 e2 08          	shl    r10d,0x8
    1307:	44 0f b6 73 17       	movzx  r14d,BYTE PTR [rbx+0x17]
    130c:	45 09 f2             	or     r10d,r14d
    130f:	49 83 c2 02          	add    r10,0x2
    1313:	41 c1 e1 10          	shl    r9d,0x10
    1317:	4d 31 d1             	xor    r9,r10
    131a:	41 c1 e6 18          	shl    r14d,0x18
    131e:	4d 01 f1             	add    r9,r14
    1321:	49 81 c1 00 01 03 00 	add    r9,0x30100
    1328:	44 0f b6 53 1b       	movzx  r10d,BYTE PTR [rbx+0x1b]
    132d:	4d 89 d6             	mov    r14,r10
    1330:	49 c1 e6 20          	shl    r14,0x20
    1334:	41 c1 e2 10          	shl    r10d,0x10
    1338:	4d 31 f2             	xor    r10,r14
    133b:	4d 31 ca             	xor    r10,r9
    133e:	0f b6 5b 1f          	movzx  ebx,BYTE PTR [rbx+0x1f]
    1342:	48 c1 e3 28          	shl    rbx,0x28
    1346:	4c 09 d3             	or     rbx,r10
    1349:	49 b9 00 00 00 44 01 	movabs r9,0x144000000
    1350:	00 00 00 
    1353:	49 01 d9             	add    r9,rbx
    1356:	c1 e6 10             	shl    esi,0x10
    1359:	4c 09 c6             	or     rsi,r8
    135c:	48 31 c6             	xor    rsi,rax
    135f:	48 89 c8             	mov    rax,rcx
    1362:	48 c1 e0 28          	shl    rax,0x28
    1366:	c1 e7 08             	shl    edi,0x8
    1369:	48 09 c7             	or     rdi,rax
    136c:	4c 09 df             	or     rdi,r11
    136f:	48 b8 00 00 00 00 06 	movabs rax,0x600000000
    1376:	00 00 00 
    1379:	48 01 f8             	add    rax,rdi
    137c:	48 01 f0             	add    rax,rsi
    137f:	83 c1 05             	add    ecx,0x5
    1382:	49 d3 c1             	rol    r9,cl
    1385:	49 31 c1             	xor    r9,rax
    1388:	4c 89 0a             	mov    QWORD PTR [rdx],r9
    138b:	b8 02 00 00 00       	mov    eax,0x2
    1390:	eb 12                	jmp    13a4 <packet_vlan_tcpopt_parser_xdp+0x2a4>
    1392:	b9 01 00 00 00       	mov    ecx,0x1
    1397:	49 8d 79 14          	lea    rdi,[r9+0x14]
    139b:	4c 39 d7             	cmp    rdi,r10
    139e:	0f 86 4a fe ff ff    	jbe    11ee <packet_vlan_tcpopt_parser_xdp+0xee>
    13a4:	5b                   	pop    rbx
    13a5:	41 5e                	pop    r14
    13a7:	41 5f                	pop    r15
    13a9:	5d                   	pop    rbp
    13aa:	c3                   	ret

Disassembly of section .fini:

00000000000013ac <_fini>:
    13ac:	f3 0f 1e fa          	endbr64
    13b0:	48 83 ec 08          	sub    rsp,0x8
    13b4:	48 83 c4 08          	add    rsp,0x8
    13b8:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
