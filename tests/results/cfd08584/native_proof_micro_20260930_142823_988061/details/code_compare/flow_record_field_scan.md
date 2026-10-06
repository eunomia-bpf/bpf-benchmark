# flow_record_field_scan

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

0000000000001100 <flow_record_field_scan_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <flow_record_field_scan_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <flow_record_field_scan_xdp+0x11>
    111b:	4c 8d 82 10 04 00 00 	lea    r8,[rdx+0x410]
    1122:	49 39 f0             	cmp    r8,rsi
    1125:	77 ea                	ja     1111 <flow_record_field_scan_xdp+0x11>
    1127:	83 3f 20             	cmp    DWORD PTR [rdi],0x20
    112a:	75 e5                	jne    1111 <flow_record_field_scan_xdp+0x11>
    112c:	83 7a 0c 20          	cmp    DWORD PTR [rdx+0xc],0x20
    1130:	75 df                	jne    1111 <flow_record_field_scan_xdp+0x11>
    1132:	41 56                	push   r14
    1134:	53                   	push   rbx
    1135:	49 b8 15 7c 4a 7f b9 	movabs r8,0x9e3779b97f4a7c15
    113c:	79 37 9e 
    113f:	31 c0                	xor    eax,eax
    1141:	31 f6                	xor    esi,esi
    1143:	eb 51                	jmp    1196 <flow_record_field_scan_xdp+0x96>
    1145:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    114c:	00 00 00 00 
    1150:	41 89 f0             	mov    r8d,esi
    1153:	41 80 e0 07          	and    r8b,0x7
    1157:	c4 42 bb f7 c2       	shrx   r8,r10,r8
    115c:	4d 31 c1             	xor    r9,r8
    115f:	4d 01 d9             	add    r9,r11
    1162:	41 89 c0             	mov    r8d,eax
    1165:	41 80 e0 18          	and    r8b,0x18
    1169:	c4 62 b9 f7 c7       	shlx   r8,rdi,r8
    116e:	4d 31 c8             	xor    r8,r9
    1171:	40 80 e7 07          	and    dil,0x7
    1175:	44 8d 4f 01          	lea    r9d,[rdi+0x1]
    1179:	c4 c2 b1 f7 d8       	shlx   rbx,r8,r9
    117e:	40 f6 d7             	not    dil
    1181:	c4 42 c3 f7 c0       	shrx   r8,r8,rdi
    1186:	49 09 d8             	or     r8,rbx
    1189:	48 ff c6             	inc    rsi
    118c:	48 83 c0 08          	add    rax,0x8
    1190:	48 83 fe 20          	cmp    rsi,0x20
    1194:	74 52                	je     11e8 <flow_record_field_scan_xdp+0xe8>
    1196:	4c 8b 54 82 20       	mov    r10,QWORD PTR [rdx+rax*4+0x20]
    119b:	48 8b 5c 82 18       	mov    rbx,QWORD PTR [rdx+rax*4+0x18]
    11a0:	4c 01 d3             	add    rbx,r10
    11a3:	8b 7c 82 28          	mov    edi,DWORD PTR [rdx+rax*4+0x28]
    11a7:	48 c1 e7 20          	shl    rdi,0x20
    11ab:	44 8b 4c 82 2c       	mov    r9d,DWORD PTR [rdx+rax*4+0x2c]
    11b0:	49 09 f9             	or     r9,rdi
    11b3:	8b 7c 82 10          	mov    edi,DWORD PTR [rdx+rax*4+0x10]
    11b7:	49 89 fb             	mov    r11,rdi
    11ba:	49 c1 e3 10          	shl    r11,0x10
    11be:	44 0f b7 74 82 14    	movzx  r14d,WORD PTR [rdx+rax*4+0x14]
    11c4:	4d 09 f3             	or     r11,r14
    11c7:	49 31 db             	xor    r11,rbx
    11ca:	4d 01 c3             	add    r11,r8
    11cd:	41 f6 c6 01          	test   r14b,0x1
    11d1:	0f 84 79 ff ff ff    	je     1150 <flow_record_field_scan_xdp+0x50>
    11d7:	44 0f b7 44 82 16    	movzx  r8d,WORD PTR [rdx+rax*4+0x16]
    11dd:	4d 01 c1             	add    r9,r8
    11e0:	4d 31 d9             	xor    r9,r11
    11e3:	e9 7a ff ff ff       	jmp    1162 <flow_record_field_scan_xdp+0x62>
    11e8:	44 88 01             	mov    BYTE PTR [rcx],r8b
    11eb:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    11ee:	89 d8                	mov    eax,ebx
    11f0:	c1 e8 10             	shr    eax,0x10
    11f3:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
    11f6:	89 d8                	mov    eax,ebx
    11f8:	c1 e8 18             	shr    eax,0x18
    11fb:	88 41 03             	mov    BYTE PTR [rcx+0x3],al
    11fe:	48 89 d8             	mov    rax,rbx
    1201:	48 c1 e8 20          	shr    rax,0x20
    1205:	88 41 04             	mov    BYTE PTR [rcx+0x4],al
    1208:	48 89 d8             	mov    rax,rbx
    120b:	48 c1 e8 28          	shr    rax,0x28
    120f:	88 41 05             	mov    BYTE PTR [rcx+0x5],al
    1212:	48 89 d8             	mov    rax,rbx
    1215:	48 c1 e8 30          	shr    rax,0x30
    1219:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
    121c:	48 c1 eb 38          	shr    rbx,0x38
    1220:	88 59 07             	mov    BYTE PTR [rcx+0x7],bl
    1223:	b8 02 00 00 00       	mov    eax,0x2
    1228:	5b                   	pop    rbx
    1229:	41 5e                	pop    r14
    122b:	c3                   	ret

Disassembly of section .fini:

000000000000122c <_fini>:
    122c:	f3 0f 1e fa          	endbr64
    1230:	48 83 ec 08          	sub    rsp,0x8
    1234:	48 83 c4 08          	add    rsp,0x8
    1238:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
