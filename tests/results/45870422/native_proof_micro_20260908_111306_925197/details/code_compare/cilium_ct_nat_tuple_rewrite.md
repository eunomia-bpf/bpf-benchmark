# cilium_ct_nat_tuple_rewrite

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

0000000000001100 <cilium_ct_nat_tuple_rewrite_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <cilium_ct_nat_tuple_rewrite_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <cilium_ct_nat_tuple_rewrite_xdp+0x11>
    111b:	48 8d ba 10 04 00 00 	lea    rdi,[rdx+0x410]
    1122:	48 39 f7             	cmp    rdi,rsi
    1125:	77 ea                	ja     1111 <cilium_ct_nat_tuple_rewrite_xdp+0x11>
    1127:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    112b:	75 e4                	jne    1111 <cilium_ct_nat_tuple_rewrite_xdp+0x11>
    112d:	83 7a 0c 20          	cmp    DWORD PTR [rdx+0xc],0x20
    1131:	75 de                	jne    1111 <cilium_ct_nat_tuple_rewrite_xdp+0x11>
    1133:	55                   	push   rbp
    1134:	41 57                	push   r15
    1136:	41 56                	push   r14
    1138:	41 54                	push   r12
    113a:	53                   	push   rbx
    113b:	48 83 c2 2f          	add    rdx,0x2f
    113f:	48 b8 e3 c6 88 9c f0 	movabs rax,0x8ebc6af09c88c6e3
    1146:	6a bc 8e 
    1149:	31 f6                	xor    esi,esi
    114b:	e9 80 00 00 00       	jmp    11d0 <cilium_ct_nat_tuple_rewrite_xdp+0xd0>
    1150:	41 89 ec             	mov    r12d,ebp
    1153:	44 89 fd             	mov    ebp,r15d
    1156:	c4 63 7b f0 fd 15    	rorx   r15d,ebp,0x15
    115c:	41 c1 e6 10          	shl    r14d,0x10
    1160:	45 31 fe             	xor    r14d,r15d
    1163:	45 0f b7 fc          	movzx  r15d,r12w
    1167:	41 c1 e2 18          	shl    r10d,0x18
    116b:	45 09 d1             	or     r9d,r10d
    116e:	45 31 f9             	xor    r9d,r15d
    1171:	45 31 f1             	xor    r9d,r14d
    1174:	41 31 d9             	xor    r9d,ebx
    1177:	41 c1 e3 1d          	shl    r11d,0x1d
    117b:	41 c1 fb 1f          	sar    r11d,0x1f
    117f:	c1 e7 08             	shl    edi,0x8
    1182:	44 31 c7             	xor    edi,r8d
    1185:	44 21 df             	and    edi,r11d
    1188:	44 01 cf             	add    edi,r9d
    118b:	48 c1 e7 20          	shl    rdi,0x20
    118f:	45 89 c0             	mov    r8d,r8d
    1192:	4c 01 c0             	add    rax,r8
    1195:	48 01 f8             	add    rax,rdi
    1198:	48 c1 e3 20          	shl    rbx,0x20
    119c:	89 ef                	mov    edi,ebp
    119e:	48 09 df             	or     rdi,rbx
    11a1:	41 89 f0             	mov    r8d,esi
    11a4:	41 83 e0 07          	and    r8d,0x7
    11a8:	45 8d 48 01          	lea    r9d,[r8+0x1]
    11ac:	c4 62 b1 f7 cf       	shlx   r9,rdi,r9
    11b1:	41 f6 d0             	not    r8b
    11b4:	c4 e2 bb f7 ff       	shrx   rdi,rdi,r8
    11b9:	4c 09 cf             	or     rdi,r9
    11bc:	48 31 f8             	xor    rax,rdi
    11bf:	48 ff c6             	inc    rsi
    11c2:	48 83 c2 20          	add    rdx,0x20
    11c6:	48 83 fe 20          	cmp    rsi,0x20
    11ca:	0f 84 8f 00 00 00    	je     125f <cilium_ct_nat_tuple_rewrite_xdp+0x15f>
    11d0:	44 0f b6 52 ed       	movzx  r10d,BYTE PTR [rdx-0x13]
    11d5:	0f b7 7a f9          	movzx  edi,WORD PTR [rdx-0x7]
    11d9:	44 0f b7 4a fb       	movzx  r9d,WORD PTR [rdx-0x5]
    11de:	44 8b 42 fd          	mov    r8d,DWORD PTR [rdx-0x3]
    11e2:	41 83 fa 06          	cmp    r10d,0x6
    11e6:	74 06                	je     11ee <cilium_ct_nat_tuple_rewrite_xdp+0xee>
    11e8:	41 83 fa 11          	cmp    r10d,0x11
    11ec:	75 62                	jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150>
    11ee:	48 8d 5a f5          	lea    rbx,[rdx-0xb]
    11f2:	4c 8d 72 f1          	lea    r14,[rdx-0xf]
    11f6:	44 0f b6 5a ef       	movzx  r11d,BYTE PTR [rdx-0x11]
    11fb:	4c 8d 62 e5          	lea    r12,[rdx-0x1b]
    11ff:	4c 8d 7a e1          	lea    r15,[rdx-0x1f]
    1203:	44 89 dd             	mov    ebp,r11d
    1206:	83 e5 01             	and    ebp,0x1
    1209:	0f 45 ef             	cmovne ebp,edi
    120c:	4d 0f 45 fe          	cmovne r15,r14
    1210:	66 33 6a e9          	xor    bp,WORD PTR [rdx-0x17]
    1214:	45 8b 3f             	mov    r15d,DWORD PTR [r15]
    1217:	45 89 de             	mov    r14d,r11d
    121a:	41 83 e6 02          	and    r14d,0x2
    121e:	44 0f 45 f7          	cmovne r14d,edi
    1222:	4c 0f 45 e3          	cmovne r12,rbx
    1226:	66 44 33 72 eb       	xor    r14w,WORD PTR [rdx-0x15]
    122b:	41 8b 1c 24          	mov    ebx,DWORD PTR [r12]
    122f:	f6 42 ee 01          	test   BYTE PTR [rdx-0x12],0x1
    1233:	0f 85 17 ff ff ff    	jne    1150 <cilium_ct_nat_tuple_rewrite_xdp+0x50>
    1239:	45 89 f4             	mov    r12d,r14d
    123c:	41 89 ee             	mov    r14d,ebp
    123f:	89 dd                	mov    ebp,ebx
    1241:	44 89 fb             	mov    ebx,r15d
    1244:	e9 0d ff ff ff       	jmp    1156 <cilium_ct_nat_tuple_rewrite_xdp+0x56>
    1249:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1250:	49 c1 e2 38          	shl    r10,0x38
    1254:	44 89 c7             	mov    edi,r8d
    1257:	4c 09 d7             	or     rdi,r10
    125a:	e9 5d ff ff ff       	jmp    11bc <cilium_ct_nat_tuple_rewrite_xdp+0xbc>
    125f:	48 89 01             	mov    QWORD PTR [rcx],rax
    1262:	b8 02 00 00 00       	mov    eax,0x2
    1267:	5b                   	pop    rbx
    1268:	41 5c                	pop    r12
    126a:	41 5e                	pop    r14
    126c:	41 5f                	pop    r15
    126e:	5d                   	pop    rbp
    126f:	c3                   	ret

Disassembly of section .fini:

0000000000001270 <_fini>:
    1270:	f3 0f 1e fa          	endbr64
    1274:	48 83 ec 08          	sub    rsp,0x8
    1278:	48 83 c4 08          	add    rsp,0x8
    127c:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
