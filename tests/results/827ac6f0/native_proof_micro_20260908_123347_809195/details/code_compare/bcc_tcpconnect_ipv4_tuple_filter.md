# bcc_tcpconnect_ipv4_tuple_filter

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

0000000000001100 <bcc_tcpconnect_ipv4_tuple_filter_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	48 89 d6             	mov    rsi,rdx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 ce             	cmp    rsi,rcx
    110f:	76 01                	jbe    1112 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7e 08          	lea    rdi,[rsi+0x8]
    1116:	48 39 cf             	cmp    rdi,rcx
    1119:	77 f6                	ja     1111 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11>
    111b:	48 8d be 10 03 00 00 	lea    rdi,[rsi+0x310]
    1122:	48 39 cf             	cmp    rdi,rcx
    1125:	77 ea                	ja     1111 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11>
    1127:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
    112b:	75 e4                	jne    1111 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11>
    112d:	83 7e 0c 18          	cmp    DWORD PTR [rsi+0xc],0x18
    1131:	75 de                	jne    1111 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x11>
    1133:	55                   	push   rbp
    1134:	41 57                	push   r15
    1136:	41 56                	push   r14
    1138:	53                   	push   rbx
    1139:	48 83 c6 27          	add    rsi,0x27
    113d:	48 bf 2f 64 bd 78 64 	movabs rdi,0xa0761d6478bd642f
    1144:	1d 76 a0 
    1147:	31 c0                	xor    eax,eax
    1149:	eb 23                	jmp    116e <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x6e>
    114b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1150:	49 c1 e1 30          	shl    r9,0x30
    1154:	44 89 d9             	mov    ecx,r11d
    1157:	4c 09 c9             	or     rcx,r9
    115a:	48 31 cf             	xor    rdi,rcx
    115d:	48 ff c0             	inc    rax
    1160:	48 83 c6 18          	add    rsi,0x18
    1164:	48 83 f8 20          	cmp    rax,0x20
    1168:	0f 84 61 01 00 00    	je     12cf <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1cf>
    116e:	0f b7 4e fb          	movzx  ecx,WORD PTR [rsi-0x5]
    1172:	81 f9 8f 1f 00 00    	cmp    ecx,0x1f8f
    1178:	7f 26                	jg     11a0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xa0>
    117a:	83 f9 50             	cmp    ecx,0x50
    117d:	74 73                	je     11f2 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xf2>
    117f:	81 f9 bb 01 00 00    	cmp    ecx,0x1bb
    1185:	75 40                	jne    11c7 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xc7>
    1187:	41 b8 02 00 00 00    	mov    r8d,0x2
    118d:	44 8b 5e e9          	mov    r11d,DWORD PTR [rsi-0x17]
    1191:	44 0f b6 4e fd       	movzx  r9d,BYTE PTR [rsi-0x3]
    1196:	41 83 f9 02          	cmp    r9d,0x2
    119a:	75 b4                	jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50>
    119c:	eb 72                	jmp    1210 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x110>
    119e:	66 90                	xchg   ax,ax
    11a0:	81 f9 90 1f 00 00    	cmp    ecx,0x1f90
    11a6:	74 08                	je     11b0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xb0>
    11a8:	81 f9 fb 20 00 00    	cmp    ecx,0x20fb
    11ae:	75 17                	jne    11c7 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0xc7>
    11b0:	41 b8 03 00 00 00    	mov    r8d,0x3
    11b6:	44 8b 5e e9          	mov    r11d,DWORD PTR [rsi-0x17]
    11ba:	44 0f b6 4e fd       	movzx  r9d,BYTE PTR [rsi-0x3]
    11bf:	41 83 f9 02          	cmp    r9d,0x2
    11c3:	75 8b                	jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50>
    11c5:	eb 49                	jmp    1210 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x110>
    11c7:	44 0f bf c9          	movsx  r9d,cx
    11cb:	45 31 c0             	xor    r8d,r8d
    11ce:	41 81 f9 30 75 00 00 	cmp    r9d,0x7530
    11d5:	41 0f 9d c0          	setge  r8b
    11d9:	41 c1 e0 02          	shl    r8d,0x2
    11dd:	44 8b 5e e9          	mov    r11d,DWORD PTR [rsi-0x17]
    11e1:	44 0f b6 4e fd       	movzx  r9d,BYTE PTR [rsi-0x3]
    11e6:	41 83 f9 02          	cmp    r9d,0x2
    11ea:	0f 85 60 ff ff ff    	jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50>
    11f0:	eb 1e                	jmp    1210 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x110>
    11f2:	41 b8 01 00 00 00    	mov    r8d,0x1
    11f8:	44 8b 5e e9          	mov    r11d,DWORD PTR [rsi-0x17]
    11fc:	44 0f b6 4e fd       	movzx  r9d,BYTE PTR [rsi-0x3]
    1201:	41 83 f9 02          	cmp    r9d,0x2
    1205:	0f 85 45 ff ff ff    	jne    1150 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x50>
    120b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1210:	44 8b 4e ed          	mov    r9d,DWORD PTR [rsi-0x13]
    1214:	0f b6 5e fe          	movzx  ebx,BYTE PTR [rsi-0x2]
    1218:	f6 c3 01             	test   bl,0x1
    121b:	0f 84 9f 00 00 00    	je     12c0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1c0>
    1221:	45 85 c0             	test   r8d,r8d
    1224:	0f 84 96 00 00 00    	je     12c0 <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x1c0>
    122a:	0f b6 6e f9          	movzx  ebp,BYTE PTR [rsi-0x7]
    122e:	44 0f b6 76 fa       	movzx  r14d,BYTE PTR [rsi-0x6]
    1233:	c4 63 7b f0 7e f5 19 	rorx   r15d,DWORD PTR [rsi-0xb],0x19
    123a:	44 0f b7 56 ff       	movzx  r10d,WORD PTR [rsi-0x1]
    123f:	44 33 7e f1          	xor    r15d,DWORD PTR [rsi-0xf]
    1243:	41 c1 e6 18          	shl    r14d,0x18
    1247:	c1 e5 10             	shl    ebp,0x10
    124a:	44 09 f5             	or     ebp,r14d
    124d:	0f b7 c9             	movzx  ecx,cx
    1250:	31 e9                	xor    ecx,ebp
    1252:	44 31 f9             	xor    ecx,r15d
    1255:	89 dd                	mov    ebp,ebx
    1257:	c1 e5 1e             	shl    ebp,0x1e
    125a:	c1 fd 1f             	sar    ebp,0x1f
    125d:	47 8d 34 19          	lea    r14d,[r9+r11*1]
    1261:	41 21 ee             	and    r14d,ebp
    1264:	45 31 d6             	xor    r14d,r10d
    1267:	41 31 ce             	xor    r14d,ecx
    126a:	41 8d 48 03          	lea    ecx,[r8+0x3]
    126e:	45 89 f7             	mov    r15d,r14d
    1271:	41 d3 c7             	rol    r15d,cl
    1274:	f6 c3 04             	test   bl,0x4
    1277:	45 0f 44 fe          	cmove  r15d,r14d
    127b:	49 c1 e7 20          	shl    r15,0x20
    127f:	44 89 d9             	mov    ecx,r11d
    1282:	4c 09 f9             	or     rcx,r15
    1285:	41 89 c3             	mov    r11d,eax
    1288:	41 80 e3 07          	and    r11b,0x7
    128c:	41 8d 5b 01          	lea    ebx,[r11+0x1]
    1290:	c4 e2 e1 f7 d9       	shlx   rbx,rcx,rbx
    1295:	41 f6 d3             	not    r11b
    1298:	c4 e2 a3 f7 c9       	shrx   rcx,rcx,r11
    129d:	48 09 d9             	or     rcx,rbx
    12a0:	48 31 f9             	xor    rcx,rdi
    12a3:	49 c1 e0 38          	shl    r8,0x38
    12a7:	41 c1 e2 10          	shl    r10d,0x10
    12ab:	4d 09 c2             	or     r10,r8
    12ae:	44 89 cf             	mov    edi,r9d
    12b1:	4c 31 d7             	xor    rdi,r10
    12b4:	48 01 cf             	add    rdi,rcx
    12b7:	e9 a1 fe ff ff       	jmp    115d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5d>
    12bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    12c0:	49 c1 e1 20          	shl    r9,0x20
    12c4:	49 09 c9             	or     r9,rcx
    12c7:	4c 01 cf             	add    rdi,r9
    12ca:	e9 8e fe ff ff       	jmp    115d <bcc_tcpconnect_ipv4_tuple_filter_xdp+0x5d>
    12cf:	48 89 3a             	mov    QWORD PTR [rdx],rdi
    12d2:	b8 02 00 00 00       	mov    eax,0x2
    12d7:	5b                   	pop    rbx
    12d8:	41 5e                	pop    r14
    12da:	41 5f                	pop    r15
    12dc:	5d                   	pop    rbp
    12dd:	c3                   	ret

Disassembly of section .fini:

00000000000012e0 <_fini>:
    12e0:	f3 0f 1e fa          	endbr64
    12e4:	48 83 ec 08          	sub    rsp,0x8
    12e8:	48 83 c4 08          	add    rsp,0x8
    12ec:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
