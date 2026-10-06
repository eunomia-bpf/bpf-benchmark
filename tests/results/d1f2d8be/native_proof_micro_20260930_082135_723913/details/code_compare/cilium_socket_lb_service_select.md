# cilium_socket_lb_service_select

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

0000000000001100 <cilium_socket_lb_service_select_xdp>:
    1100:	4c 8b 07             	mov    r8,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	4c 89 c7             	mov    rdi,r8
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 cf             	cmp    rdi,rcx
    110f:	76 01                	jbe    1112 <cilium_socket_lb_service_select_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 57 08          	lea    rdx,[rdi+0x8]
    1116:	48 39 ca             	cmp    rdx,rcx
    1119:	77 f6                	ja     1111 <cilium_socket_lb_service_select_xdp+0x11>
    111b:	48 8d 97 10 06 00 00 	lea    rdx,[rdi+0x610]
    1122:	48 39 ca             	cmp    rdx,rcx
    1125:	77 ea                	ja     1111 <cilium_socket_lb_service_select_xdp+0x11>
    1127:	83 7f 08 40          	cmp    DWORD PTR [rdi+0x8],0x40
    112b:	75 e4                	jne    1111 <cilium_socket_lb_service_select_xdp+0x11>
    112d:	83 7f 0c 18          	cmp    DWORD PTR [rdi+0xc],0x18
    1131:	75 de                	jne    1111 <cilium_socket_lb_service_select_xdp+0x11>
    1133:	55                   	push   rbp
    1134:	41 57                	push   r15
    1136:	41 56                	push   r14
    1138:	41 54                	push   r12
    113a:	53                   	push   rbx
    113b:	48 83 c7 27          	add    rdi,0x27
    113f:	49 b9 d3 08 a3 85 88 	movabs r9,0x243f6a8885a308d3
    1146:	6a 3f 24 
    1149:	45 31 d2             	xor    r10d,r10d
    114c:	eb 20                	jmp    116e <cilium_socket_lb_service_select_xdp+0x6e>
    114e:	66 90                	xchg   ax,ax
    1150:	49 c1 e3 20          	shl    r11,0x20
    1154:	0f b7 c3             	movzx  eax,bx
    1157:	4c 09 d8             	or     rax,r11
    115a:	49 31 c1             	xor    r9,rax
    115d:	49 ff c2             	inc    r10
    1160:	48 83 c7 18          	add    rdi,0x18
    1164:	49 83 fa 40          	cmp    r10,0x40
    1168:	0f 84 ea 00 00 00    	je     1258 <cilium_socket_lb_service_select_xdp+0x158>
    116e:	8b 47 ed             	mov    eax,DWORD PTR [rdi-0x13]
    1171:	44 0f b6 5f f5       	movzx  r11d,BYTE PTR [rdi-0xb]
    1176:	49 83 fb 11          	cmp    r11,0x11
    117a:	0f 95 c1             	setne  cl
    117d:	49 83 fb 06          	cmp    r11,0x6
    1181:	0f 95 c2             	setne  dl
    1184:	0f b7 5f f3          	movzx  ebx,WORD PTR [rdi-0xd]
    1188:	44 0f b6 7f f6       	movzx  r15d,BYTE PTR [rdi-0xa]
    118d:	41 f6 c7 02          	test   r15b,0x2
    1191:	bd 00 00 00 00       	mov    ebp,0x0
    1196:	0f 44 e8             	cmove  ebp,eax
    1199:	84 ca                	test   dl,cl
    119b:	75 b3                	jne    1150 <cilium_socket_lb_service_select_xdp+0x50>
    119d:	44 0f b7 67 f7       	movzx  r12d,WORD PTR [rdi-0x9]
    11a2:	66 45 85 e4          	test   r12w,r12w
    11a6:	74 a8                	je     1150 <cilium_socket_lb_service_select_xdp+0x50>
    11a8:	0f b7 4f f1          	movzx  ecx,WORD PTR [rdi-0xf]
    11ac:	89 ca                	mov    edx,ecx
    11ae:	c1 e2 10             	shl    edx,0x10
    11b1:	33 57 e9             	xor    edx,DWORD PTR [rdi-0x17]
    11b4:	44 8b 77 fd          	mov    r14d,DWORD PTR [rdi-0x3]
    11b8:	31 da                	xor    edx,ebx
    11ba:	33 57 f9             	xor    edx,DWORD PTR [rdi-0x7]
    11bd:	0f bf f3             	movsx  esi,bx
    11c0:	81 fe 2f 75 00 00    	cmp    esi,0x752f
    11c6:	7f 28                	jg     11f0 <cilium_socket_lb_service_select_xdp+0xf0>
    11c8:	44 89 fe             	mov    esi,r15d
    11cb:	83 e6 02             	and    esi,0x2
    11ce:	75 20                	jne    11f0 <cilium_socket_lb_service_select_xdp+0xf0>
    11d0:	89 c0                	mov    eax,eax
    11d2:	48 c1 e0 10          	shl    rax,0x10
    11d6:	0f b7 c9             	movzx  ecx,cx
    11d9:	48 09 c1             	or     rcx,rax
    11dc:	49 01 c9             	add    r9,rcx
    11df:	49 ff c2             	inc    r10
    11e2:	48 83 c7 18          	add    rdi,0x18
    11e6:	49 83 fa 40          	cmp    r10,0x40
    11ea:	75 82                	jne    116e <cilium_socket_lb_service_select_xdp+0x6e>
    11ec:	eb 6a                	jmp    1258 <cilium_socket_lb_service_select_xdp+0x158>
    11ee:	66 90                	xchg   ax,ax
    11f0:	31 ea                	xor    edx,ebp
    11f2:	43 8d 34 3e          	lea    esi,[r14+r15*1]
    11f6:	01 d6                	add    esi,edx
    11f8:	44 89 d9             	mov    ecx,r11d
    11fb:	83 e1 07             	and    ecx,0x7
    11fe:	ff c1                	inc    ecx
    1200:	d3 c6                	rol    esi,cl
    1202:	31 d6                	xor    esi,edx
    1204:	89 f0                	mov    eax,esi
    1206:	31 d2                	xor    edx,edx
    1208:	41 f7 f4             	div    r12d
    120b:	ff c2                	inc    edx
    120d:	41 c1 e7 1d          	shl    r15d,0x1d
    1211:	41 c1 ff 1f          	sar    r15d,0x1f
    1215:	41 ff c6             	inc    r14d
    1218:	45 21 fe             	and    r14d,r15d
    121b:	41 31 d6             	xor    r14d,edx
    121e:	89 e8                	mov    eax,ebp
    1220:	48 c1 e0 10          	shl    rax,0x10
    1224:	0f b7 cb             	movzx  ecx,bx
    1227:	48 c1 e1 20          	shl    rcx,0x20
    122b:	48 31 c1             	xor    rcx,rax
    122e:	4d 01 d9             	add    r9,r11
    1231:	49 01 c9             	add    r9,rcx
    1234:	49 c1 e6 30          	shl    r14,0x30
    1238:	4c 09 f6             	or     rsi,r14
    123b:	44 89 d0             	mov    eax,r10d
    123e:	83 e0 07             	and    eax,0x7
    1241:	8d 48 01             	lea    ecx,[rax+0x1]
    1244:	c4 e2 f1 f7 ce       	shlx   rcx,rsi,rcx
    1249:	f6 d0                	not    al
    124b:	c4 e2 fb f7 c6       	shrx   rax,rsi,rax
    1250:	48 09 c8             	or     rax,rcx
    1253:	e9 02 ff ff ff       	jmp    115a <cilium_socket_lb_service_select_xdp+0x5a>
    1258:	4d 89 08             	mov    QWORD PTR [r8],r9
    125b:	b8 02 00 00 00       	mov    eax,0x2
    1260:	5b                   	pop    rbx
    1261:	41 5c                	pop    r12
    1263:	41 5e                	pop    r14
    1265:	41 5f                	pop    r15
    1267:	5d                   	pop    rbp
    1268:	c3                   	ret

Disassembly of section .fini:

000000000000126c <_fini>:
    126c:	f3 0f 1e fa          	endbr64
    1270:	48 83 ec 08          	sub    rsp,0x8
    1274:	48 83 c4 08          	add    rsp,0x8
    1278:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
