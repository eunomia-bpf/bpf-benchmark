# cilium_policy_guard_tree_filter

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

0000000000001100 <cilium_policy_guard_tree_filter_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <cilium_policy_guard_tree_filter_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <cilium_policy_guard_tree_filter_xdp+0x11>
    111b:	4c 8d 82 0c 02 00 00 	lea    r8,[rdx+0x20c]
    1122:	49 39 f0             	cmp    r8,rsi
    1125:	77 ea                	ja     1111 <cilium_policy_guard_tree_filter_xdp+0x11>
    1127:	83 3f 20             	cmp    DWORD PTR [rdi],0x20
    112a:	75 e5                	jne    1111 <cilium_policy_guard_tree_filter_xdp+0x11>
    112c:	53                   	push   rbx
    112d:	48 83 c2 1b          	add    rdx,0x1b
    1131:	48 bf db 28 b4 a0 d1 	movabs rdi,0xe7037ed1a0b428db
    1138:	7e 03 e7 
    113b:	31 c0                	xor    eax,eax
    113d:	eb 42                	jmp    1181 <cilium_policy_guard_tree_filter_xdp+0x81>
    113f:	49 c1 e0 30          	shl    r8,0x30
    1143:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    114a:	84 00 00 00 00 00 
    1150:	4c 31 c6             	xor    rsi,r8
    1153:	48 01 fe             	add    rsi,rdi
    1156:	89 c7                	mov    edi,eax
    1158:	40 80 e7 07          	and    dil,0x7
    115c:	44 8d 47 01          	lea    r8d,[rdi+0x1]
    1160:	c4 e2 b9 f7 de       	shlx   rbx,rsi,r8
    1165:	40 f6 d7             	not    dil
    1168:	c4 e2 c3 f7 fe       	shrx   rdi,rsi,rdi
    116d:	48 09 df             	or     rdi,rbx
    1170:	48 ff c0             	inc    rax
    1173:	48 83 c2 10          	add    rdx,0x10
    1177:	48 83 f8 20          	cmp    rax,0x20
    117b:	0f 84 bc 00 00 00    	je     123d <cilium_policy_guard_tree_filter_xdp+0x13d>
    1181:	44 0f b6 42 f1       	movzx  r8d,BYTE PTR [rdx-0xf]
    1186:	48 8b 72 f9          	mov    rsi,QWORD PTR [rdx-0x7]
    118a:	49 83 f8 21          	cmp    r8,0x21
    118e:	72 c0                	jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50>
    1190:	44 0f b6 4a f2       	movzx  r9d,BYTE PTR [rdx-0xe]
    1195:	41 f6 c1 01          	test   r9b,0x1
    1199:	74 66                	je     1201 <cilium_policy_guard_tree_filter_xdp+0x101>
    119b:	44 0f b6 4a f3       	movzx  r9d,BYTE PTR [rdx-0xd]
    11a0:	45 84 c9             	test   r9b,r9b
    11a3:	78 52                	js     11f7 <cilium_policy_guard_tree_filter_xdp+0xf7>
    11a5:	44 0f b6 4a f4       	movzx  r9d,BYTE PTR [rdx-0xc]
    11aa:	45 89 ca             	mov    r10d,r9d
    11ad:	41 31 c2             	xor    r10d,eax
    11b0:	41 80 fa 11          	cmp    r10b,0x11
    11b4:	72 47                	jb     11fd <cilium_policy_guard_tree_filter_xdp+0xfd>
    11b6:	44 0f b6 4a f5       	movzx  r9d,BYTE PTR [rdx-0xb]
    11bb:	45 00 c8             	add    r8b,r9b
    11be:	41 80 f8 bf          	cmp    r8b,0xbf
    11c2:	77 48                	ja     120c <cilium_policy_guard_tree_filter_xdp+0x10c>
    11c4:	44 0f b6 42 f6       	movzx  r8d,BYTE PTR [rdx-0xa]
    11c9:	45 89 c1             	mov    r9d,r8d
    11cc:	41 80 e1 18          	and    r9b,0x18
    11d0:	41 80 f9 10          	cmp    r9b,0x10
    11d4:	75 42                	jne    1218 <cilium_policy_guard_tree_filter_xdp+0x118>
    11d6:	44 0f b6 4a f7       	movzx  r9d,BYTE PTR [rdx-0x9]
    11db:	41 81 f9 aa 00 00 00 	cmp    r9d,0xaa
    11e2:	75 3d                	jne    1221 <cilium_policy_guard_tree_filter_xdp+0x121>
    11e4:	49 31 f0             	xor    r8,rsi
    11e7:	49 0f a4 f0 07       	shld   r8,rsi,0x7
    11ec:	49 01 f8             	add    r8,rdi
    11ef:	4c 89 c6             	mov    rsi,r8
    11f2:	e9 5f ff ff ff       	jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56>
    11f7:	41 c1 e1 08          	shl    r9d,0x8
    11fb:	eb 13                	jmp    1210 <cilium_policy_guard_tree_filter_xdp+0x110>
    11fd:	41 c1 e1 10          	shl    r9d,0x10
    1201:	4c 01 ce             	add    rsi,r9
    1204:	48 31 fe             	xor    rsi,rdi
    1207:	e9 4a ff ff ff       	jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56>
    120c:	41 c1 e1 18          	shl    r9d,0x18
    1210:	4c 31 ce             	xor    rsi,r9
    1213:	e9 3b ff ff ff       	jmp    1153 <cilium_policy_guard_tree_filter_xdp+0x53>
    1218:	49 c1 e0 20          	shl    r8,0x20
    121c:	4c 01 c6             	add    rsi,r8
    121f:	eb e3                	jmp    1204 <cilium_policy_guard_tree_filter_xdp+0x104>
    1221:	44 0f b6 42 f8       	movzx  r8d,BYTE PTR [rdx-0x8]
    1226:	45 89 c2             	mov    r10d,r8d
    1229:	41 80 e2 03          	and    r10b,0x3
    122d:	41 80 fa 01          	cmp    r10b,0x1
    1231:	0f 84 08 ff ff ff    	je     113f <cilium_policy_guard_tree_filter_xdp+0x3f>
    1237:	49 c1 e1 28          	shl    r9,0x28
    123b:	eb c4                	jmp    1201 <cilium_policy_guard_tree_filter_xdp+0x101>
    123d:	40 88 39             	mov    BYTE PTR [rcx],dil
    1240:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    1243:	89 d8                	mov    eax,ebx
    1245:	c1 e8 10             	shr    eax,0x10
    1248:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
    124b:	89 d8                	mov    eax,ebx
    124d:	c1 e8 18             	shr    eax,0x18
    1250:	88 41 03             	mov    BYTE PTR [rcx+0x3],al
    1253:	48 89 d8             	mov    rax,rbx
    1256:	48 c1 e8 20          	shr    rax,0x20
    125a:	88 41 04             	mov    BYTE PTR [rcx+0x4],al
    125d:	48 89 d8             	mov    rax,rbx
    1260:	48 c1 e8 28          	shr    rax,0x28
    1264:	88 41 05             	mov    BYTE PTR [rcx+0x5],al
    1267:	48 89 d8             	mov    rax,rbx
    126a:	48 c1 e8 30          	shr    rax,0x30
    126e:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
    1271:	48 c1 eb 38          	shr    rbx,0x38
    1275:	88 59 07             	mov    BYTE PTR [rcx+0x7],bl
    1278:	b8 02 00 00 00       	mov    eax,0x2
    127d:	5b                   	pop    rbx
    127e:	c3                   	ret

Disassembly of section .fini:

0000000000001280 <_fini>:
    1280:	f3 0f 1e fa          	endbr64
    1284:	48 83 ec 08          	sub    rsp,0x8
    1288:	48 83 c4 08          	add    rsp,0x8
    128c:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
