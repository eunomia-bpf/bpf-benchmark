# otel_stack_frame_unwind_scan

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

0000000000001100 <otel_stack_frame_unwind_scan_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	48 89 d6             	mov    rsi,rdx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 ce             	cmp    rsi,rcx
    110f:	76 01                	jbe    1112 <otel_stack_frame_unwind_scan_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7e 08          	lea    rdi,[rsi+0x8]
    1116:	48 39 cf             	cmp    rdi,rcx
    1119:	77 f6                	ja     1111 <otel_stack_frame_unwind_scan_xdp+0x11>
    111b:	48 8d be 50 02 00 00 	lea    rdi,[rsi+0x250]
    1122:	48 39 cf             	cmp    rdi,rcx
    1125:	77 ea                	ja     1111 <otel_stack_frame_unwind_scan_xdp+0x11>
    1127:	83 7e 08 18          	cmp    DWORD PTR [rsi+0x8],0x18
    112b:	75 e4                	jne    1111 <otel_stack_frame_unwind_scan_xdp+0x11>
    112d:	83 7e 0c 18          	cmp    DWORD PTR [rsi+0xc],0x18
    1131:	75 de                	jne    1111 <otel_stack_frame_unwind_scan_xdp+0x11>
    1133:	55                   	push   rbp
    1134:	41 57                	push   r15
    1136:	41 56                	push   r14
    1138:	41 54                	push   r12
    113a:	53                   	push   rbx
    113b:	48 83 c6 27          	add    rsi,0x27
    113f:	48 b8 00 00 00 00 01 	movabs rax,0x100000000
    1146:	00 00 00 
    1149:	49 b9 c3 4c 37 75 cc 	movabs r9,0x589965cc75374cc3
    1150:	65 99 58 
    1153:	31 ff                	xor    edi,edi
    1155:	41 b8 08 00 00 00    	mov    r8d,0x8
    115b:	eb 1e                	jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b>
    115d:	0f 1f 00             	nop    DWORD PTR [rax]
    1160:	48 c1 e1 30          	shl    rcx,0x30
    1164:	48 09 d9             	or     rcx,rbx
    1167:	49 31 c9             	xor    r9,rcx
    116a:	48 ff c7             	inc    rdi
    116d:	48 83 c6 18          	add    rsi,0x18
    1171:	48 83 ff 18          	cmp    rdi,0x18
    1175:	0f 84 08 01 00 00    	je     1283 <otel_stack_frame_unwind_scan_xdp+0x183>
    117b:	48 8b 5e e9          	mov    rbx,QWORD PTR [rsi-0x17]
    117f:	8b 6e f1             	mov    ebp,DWORD PTR [rsi-0xf]
    1182:	44 8b 76 f5          	mov    r14d,DWORD PTR [rsi-0xb]
    1186:	44 0f b7 5e f9       	movzx  r11d,WORD PTR [rsi-0x7]
    118b:	0f b7 4e fb          	movzx  ecx,WORD PTR [rsi-0x5]
    118f:	44 8b 56 fd          	mov    r10d,DWORD PTR [rsi-0x3]
    1193:	83 f9 01             	cmp    ecx,0x1
    1196:	7f 28                	jg     11c0 <otel_stack_frame_unwind_scan_xdp+0xc0>
    1198:	85 c9                	test   ecx,ecx
    119a:	74 3e                	je     11da <otel_stack_frame_unwind_scan_xdp+0xda>
    119c:	83 f9 01             	cmp    ecx,0x1
    119f:	75 bf                	jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11a1:	41 bf 35 00 00 00    	mov    r15d,0x35
    11a7:	81 fd 00 10 00 00    	cmp    ebp,0x1000
    11ad:	76 50                	jbe    11ff <otel_stack_frame_unwind_scan_xdp+0xff>
    11af:	eb af                	jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11b1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11b8:	0f 1f 84 00 00 00 00 
    11bf:	00 
    11c0:	83 f9 02             	cmp    ecx,0x2
    11c3:	74 28                	je     11ed <otel_stack_frame_unwind_scan_xdp+0xed>
    11c5:	83 f9 03             	cmp    ecx,0x3
    11c8:	75 96                	jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11ca:	41 bf 89 00 00 00    	mov    r15d,0x89
    11d0:	81 fd 00 10 00 00    	cmp    ebp,0x1000
    11d6:	76 27                	jbe    11ff <otel_stack_frame_unwind_scan_xdp+0xff>
    11d8:	eb 86                	jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11da:	41 bf 21 00 00 00    	mov    r15d,0x21
    11e0:	81 fd 00 10 00 00    	cmp    ebp,0x1000
    11e6:	76 17                	jbe    11ff <otel_stack_frame_unwind_scan_xdp+0xff>
    11e8:	e9 73 ff ff ff       	jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11ed:	41 bf 55 00 00 00    	mov    r15d,0x55
    11f3:	81 fd 00 10 00 00    	cmp    ebp,0x1000
    11f9:	0f 87 61 ff ff ff    	ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11ff:	41 81 fe 01 20 00 00 	cmp    r14d,0x2001
    1206:	0f 83 54 ff ff ff    	jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    120c:	41 f6 c3 01          	test   r11b,0x1
    1210:	45 89 f4             	mov    r12d,r14d
    1213:	45 0f 44 e0          	cmove  r12d,r8d
    1217:	41 01 ec             	add    r12d,ebp
    121a:	4c 01 e0             	add    rax,r12
    121d:	4d 89 d4             	mov    r12,r10
    1220:	49 c1 e4 20          	shl    r12,0x20
    1224:	4d 09 e7             	or     r15,r12
    1227:	4c 31 fb             	xor    rbx,r15
    122a:	48 31 c3             	xor    rbx,rax
    122d:	41 f6 c3 02          	test   r11b,0x2
    1231:	74 05                	je     1238 <otel_stack_frame_unwind_scan_xdp+0x138>
    1233:	fe c1                	inc    cl
    1235:	48 d3 c3             	rol    rbx,cl
    1238:	44 89 f1             	mov    ecx,r14d
    123b:	48 c1 e1 18          	shl    rcx,0x18
    123f:	41 89 ee             	mov    r14d,ebp
    1242:	49 31 ce             	xor    r14,rcx
    1245:	41 f6 c3 04          	test   r11b,0x4
    1249:	b9 00 00 00 00       	mov    ecx,0x0
    124e:	49 0f 45 ce          	cmovne rcx,r14
    1252:	48 01 d9             	add    rcx,rbx
    1255:	89 fb                	mov    ebx,edi
    1257:	80 e3 07             	and    bl,0x7
    125a:	44 8d 73 01          	lea    r14d,[rbx+0x1]
    125e:	c4 62 89 f7 f1       	shlx   r14,rcx,r14
    1263:	f6 d3                	not    bl
    1265:	c4 e2 e3 f7 c9       	shrx   rcx,rcx,rbx
    126a:	4c 09 f1             	or     rcx,r14
    126d:	4c 01 c9             	add    rcx,r9
    1270:	45 0f b7 cb          	movzx  r9d,r11w
    1274:	49 c1 e1 28          	shl    r9,0x28
    1278:	4d 09 ca             	or     r10,r9
    127b:	4d 89 d1             	mov    r9,r10
    127e:	e9 e4 fe ff ff       	jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67>
    1283:	4c 89 0a             	mov    QWORD PTR [rdx],r9
    1286:	b8 02 00 00 00       	mov    eax,0x2
    128b:	5b                   	pop    rbx
    128c:	41 5c                	pop    r12
    128e:	41 5e                	pop    r14
    1290:	41 5f                	pop    r15
    1292:	5d                   	pop    rbp
    1293:	c3                   	ret

Disassembly of section .fini:

0000000000001294 <_fini>:
    1294:	f3 0f 1e fa          	endbr64
    1298:	48 83 ec 08          	sub    rsp,0x8
    129c:	48 83 c4 08          	add    rsp,0x8
    12a0:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
