# packet_record_bounds_window

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

0000000000001100 <packet_record_bounds_window_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <packet_record_bounds_window_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <packet_record_bounds_window_xdp+0x11>
    111b:	48 8d ba 10 03 00 00 	lea    rdi,[rdx+0x310]
    1122:	48 39 f7             	cmp    rdi,rsi
    1125:	77 ea                	ja     1111 <packet_record_bounds_window_xdp+0x11>
    1127:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    112b:	75 e4                	jne    1111 <packet_record_bounds_window_xdp+0x11>
    112d:	83 7a 0c 18          	cmp    DWORD PTR [rdx+0xc],0x18
    1131:	75 de                	jne    1111 <packet_record_bounds_window_xdp+0x11>
    1133:	41 56                	push   r14
    1135:	53                   	push   rbx
    1136:	48 83 c2 27          	add    rdx,0x27
    113a:	49 b9 93 fd 59 66 b8 	movabs r9,0xd6e8feb86659fd93
    1141:	fe e8 d6 
    1144:	b8 00 03 00 00       	mov    eax,0x300
    1149:	31 f6                	xor    esi,esi
    114b:	eb 5e                	jmp    11ab <packet_record_bounds_window_xdp+0xab>
    114d:	0f 1f 00             	nop    DWORD PTR [rax]
    1150:	48 c1 e3 20          	shl    rbx,0x20
    1154:	45 89 db             	mov    r11d,r11d
    1157:	49 09 db             	or     r11,rbx
    115a:	4d 01 da             	add    r10,r11
    115d:	44 0f b7 5a ff       	movzx  r11d,WORD PTR [rdx-0x1]
    1162:	8d 1c bd 00 00 00 00 	lea    ebx,[rdi*4+0x0]
    1169:	80 e3 1c             	and    bl,0x1c
    116c:	c4 42 e1 f7 c9       	shlx   r9,r9,rbx
    1171:	4d 31 d1             	xor    r9,r10
    1174:	41 89 f2             	mov    r10d,esi
    1177:	41 80 e2 18          	and    r10b,0x18
    117b:	c4 42 a9 f7 d3       	shlx   r10,r11,r10
    1180:	4d 01 ca             	add    r10,r9
    1183:	83 e7 07             	and    edi,0x7
    1186:	44 31 c7             	xor    edi,r8d
    1189:	44 8d 47 01          	lea    r8d,[rdi+0x1]
    118d:	c4 42 b9 f7 c2       	shlx   r8,r10,r8
    1192:	40 f6 d7             	not    dil
    1195:	c4 42 c3 f7 ca       	shrx   r9,r10,rdi
    119a:	4d 09 c1             	or     r9,r8
    119d:	48 83 c6 08          	add    rsi,0x8
    11a1:	48 83 c2 18          	add    rdx,0x18
    11a5:	48 83 c0 e8          	add    rax,0xffffffffffffffe8
    11a9:	74 4c                	je     11f7 <packet_record_bounds_window_xdp+0xf7>
    11ab:	44 0f b6 42 e9       	movzx  r8d,BYTE PTR [rdx-0x17]
    11b0:	41 83 e0 03          	and    r8d,0x3
    11b4:	49 8d 78 18          	lea    rdi,[r8+0x18]
    11b8:	48 39 f8             	cmp    rax,rdi
    11bb:	72 e0                	jb     119d <packet_record_bounds_window_xdp+0x9d>
    11bd:	0f b6 7a ea          	movzx  edi,BYTE PTR [rdx-0x16]
    11c1:	44 8b 72 ed          	mov    r14d,DWORD PTR [rdx-0x13]
    11c5:	8b 5a f1             	mov    ebx,DWORD PTR [rdx-0xf]
    11c8:	44 8b 5a f5          	mov    r11d,DWORD PTR [rdx-0xb]
    11cc:	44 0f b7 52 fd       	movzx  r10d,WORD PTR [rdx-0x3]
    11d1:	4d 01 ce             	add    r14,r9
    11d4:	49 01 da             	add    r10,rbx
    11d7:	4d 01 f2             	add    r10,r14
    11da:	44 8b 4a f9          	mov    r9d,DWORD PTR [rdx-0x7]
    11de:	40 f6 c7 01          	test   dil,0x1
    11e2:	0f 84 68 ff ff ff    	je     1150 <packet_record_bounds_window_xdp+0x50>
    11e8:	49 c1 e3 20          	shl    r11,0x20
    11ec:	4d 09 cb             	or     r11,r9
    11ef:	4d 31 da             	xor    r10,r11
    11f2:	e9 66 ff ff ff       	jmp    115d <packet_record_bounds_window_xdp+0x5d>
    11f7:	4c 89 09             	mov    QWORD PTR [rcx],r9
    11fa:	b8 02 00 00 00       	mov    eax,0x2
    11ff:	5b                   	pop    rbx
    1200:	41 5e                	pop    r14
    1202:	c3                   	ret

Disassembly of section .fini:

0000000000001204 <_fini>:
    1204:	f3 0f 1e fa          	endbr64
    1208:	48 83 ec 08          	sub    rsp,0x8
    120c:	48 83 c4 08          	add    rsp,0x8
    1210:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
