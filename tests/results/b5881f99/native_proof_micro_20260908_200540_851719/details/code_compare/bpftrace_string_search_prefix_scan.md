# bpftrace_string_search_prefix_scan

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

0000000000001100 <bpftrace_string_search_prefix_scan_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	0f 87 b5 01 00 00    	ja     12ca <bpftrace_string_search_prefix_scan_xdp+0x1ca>
    1115:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1119:	48 39 f7             	cmp    rdi,rsi
    111c:	0f 87 a8 01 00 00    	ja     12ca <bpftrace_string_search_prefix_scan_xdp+0x1ca>
    1122:	48 8d 7a 78          	lea    rdi,[rdx+0x78]
    1126:	48 39 f7             	cmp    rdi,rsi
    1129:	0f 87 9b 01 00 00    	ja     12ca <bpftrace_string_search_prefix_scan_xdp+0x1ca>
    112f:	55                   	push   rbp
    1130:	53                   	push   rbx
    1131:	44 8b 42 08          	mov    r8d,DWORD PTR [rdx+0x8]
    1135:	0f b6 72 70          	movzx  esi,BYTE PTR [rdx+0x70]
    1139:	31 c0                	xor    eax,eax
    113b:	41 b9 00 00 00 00    	mov    r9d,0x0
    1141:	40 84 f6             	test   sil,sil
    1144:	74 62                	je     11a8 <bpftrace_string_search_prefix_scan_xdp+0xa8>
    1146:	80 7a 71 00          	cmp    BYTE PTR [rdx+0x71],0x0
    114a:	74 2e                	je     117a <bpftrace_string_search_prefix_scan_xdp+0x7a>
    114c:	80 7a 72 00          	cmp    BYTE PTR [rdx+0x72],0x0
    1150:	74 30                	je     1182 <bpftrace_string_search_prefix_scan_xdp+0x82>
    1152:	80 7a 73 00          	cmp    BYTE PTR [rdx+0x73],0x0
    1156:	74 32                	je     118a <bpftrace_string_search_prefix_scan_xdp+0x8a>
    1158:	80 7a 74 00          	cmp    BYTE PTR [rdx+0x74],0x0
    115c:	74 34                	je     1192 <bpftrace_string_search_prefix_scan_xdp+0x92>
    115e:	80 7a 75 00          	cmp    BYTE PTR [rdx+0x75],0x0
    1162:	74 36                	je     119a <bpftrace_string_search_prefix_scan_xdp+0x9a>
    1164:	80 7a 76 00          	cmp    BYTE PTR [rdx+0x76],0x0
    1168:	74 38                	je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    116a:	80 7a 77 01          	cmp    BYTE PTR [rdx+0x77],0x1
    116e:	41 b9 08 00 00 00    	mov    r9d,0x8
    1174:	41 83 d9 00          	sbb    r9d,0x0
    1178:	eb 2e                	jmp    11a8 <bpftrace_string_search_prefix_scan_xdp+0xa8>
    117a:	41 b9 01 00 00 00    	mov    r9d,0x1
    1180:	eb 26                	jmp    11a8 <bpftrace_string_search_prefix_scan_xdp+0xa8>
    1182:	41 b9 02 00 00 00    	mov    r9d,0x2
    1188:	eb 1e                	jmp    11a8 <bpftrace_string_search_prefix_scan_xdp+0xa8>
    118a:	41 b9 03 00 00 00    	mov    r9d,0x3
    1190:	eb 16                	jmp    11a8 <bpftrace_string_search_prefix_scan_xdp+0xa8>
    1192:	41 b9 04 00 00 00    	mov    r9d,0x4
    1198:	eb 0e                	jmp    11a8 <bpftrace_string_search_prefix_scan_xdp+0xa8>
    119a:	41 b9 05 00 00 00    	mov    r9d,0x5
    11a0:	eb 06                	jmp    11a8 <bpftrace_string_search_prefix_scan_xdp+0xa8>
    11a2:	41 b9 06 00 00 00    	mov    r9d,0x6
    11a8:	41 83 f8 60          	cmp    r8d,0x60
    11ac:	0f 87 16 01 00 00    	ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    11b2:	8b 7a 0c             	mov    edi,DWORD PTR [rdx+0xc]
    11b5:	44 39 cf             	cmp    edi,r9d
    11b8:	0f 85 0a 01 00 00    	jne    12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    11be:	40 84 f6             	test   sil,sil
    11c1:	0f 84 01 01 00 00    	je     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    11c7:	48 b8 16 91 d8 ae 8b 	movabs rax,0x4f82338baed89116
    11ce:	33 82 4f 
    11d1:	45 89 c2             	mov    r10d,r8d
    11d4:	44 8d 5f 03          	lea    r11d,[rdi+0x3]
    11d8:	49 b8 03 ed 92 d1 32 	movabs r8,0xd1b54a32d192ed03
    11df:	4a b5 d1 
    11e2:	4d 01 d8             	add    r8,r11
    11e5:	45 31 c9             	xor    r9d,r9d
    11e8:	eb 1e                	jmp    1208 <bpftrace_string_search_prefix_scan_xdp+0x108>
    11ea:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    11f0:	84 db                	test   bl,bl
    11f2:	0f 84 af 00 00 00    	je     12a7 <bpftrace_string_search_prefix_scan_xdp+0x1a7>
    11f8:	49 ff c1             	inc    r9
    11fb:	4d 01 d8             	add    r8,r11
    11fe:	49 83 f9 59          	cmp    r9,0x59
    1202:	0f 84 b8 00 00 00    	je     12c0 <bpftrace_string_search_prefix_scan_xdp+0x1c0>
    1208:	4a 8d 1c 0f          	lea    rbx,[rdi+r9*1]
    120c:	4c 39 d3             	cmp    rbx,r10
    120f:	77 e7                	ja     11f8 <bpftrace_string_search_prefix_scan_xdp+0xf8>
    1211:	48 85 ff             	test   rdi,rdi
    1214:	0f 84 8d 00 00 00    	je     12a7 <bpftrace_string_search_prefix_scan_xdp+0x1a7>
    121a:	42 0f b6 5c 0a 10    	movzx  ebx,BYTE PTR [rdx+r9*1+0x10]
    1220:	40 30 f3             	xor    bl,sil
    1223:	83 ff 02             	cmp    edi,0x2
    1226:	72 c8                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1228:	0f b6 6a 71          	movzx  ebp,BYTE PTR [rdx+0x71]
    122c:	42 32 6c 0a 11       	xor    bpl,BYTE PTR [rdx+r9*1+0x11]
    1231:	40 08 eb             	or     bl,bpl
    1234:	83 ff 03             	cmp    edi,0x3
    1237:	72 b7                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1239:	0f b6 6a 72          	movzx  ebp,BYTE PTR [rdx+0x72]
    123d:	42 32 6c 0a 12       	xor    bpl,BYTE PTR [rdx+r9*1+0x12]
    1242:	40 08 eb             	or     bl,bpl
    1245:	83 ff 04             	cmp    edi,0x4
    1248:	72 a6                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    124a:	0f b6 6a 73          	movzx  ebp,BYTE PTR [rdx+0x73]
    124e:	42 32 6c 0a 13       	xor    bpl,BYTE PTR [rdx+r9*1+0x13]
    1253:	40 08 eb             	or     bl,bpl
    1256:	83 ff 05             	cmp    edi,0x5
    1259:	72 95                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    125b:	0f b6 6a 74          	movzx  ebp,BYTE PTR [rdx+0x74]
    125f:	42 32 6c 0a 14       	xor    bpl,BYTE PTR [rdx+r9*1+0x14]
    1264:	40 08 eb             	or     bl,bpl
    1267:	83 ff 06             	cmp    edi,0x6
    126a:	72 84                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    126c:	0f b6 6a 75          	movzx  ebp,BYTE PTR [rdx+0x75]
    1270:	42 32 6c 0a 15       	xor    bpl,BYTE PTR [rdx+r9*1+0x15]
    1275:	40 08 eb             	or     bl,bpl
    1278:	83 ff 07             	cmp    edi,0x7
    127b:	0f 82 6f ff ff ff    	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1281:	0f b6 6a 76          	movzx  ebp,BYTE PTR [rdx+0x76]
    1285:	42 32 6c 0a 16       	xor    bpl,BYTE PTR [rdx+r9*1+0x16]
    128a:	40 08 eb             	or     bl,bpl
    128d:	83 ff 08             	cmp    edi,0x8
    1290:	0f 82 5a ff ff ff    	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1296:	0f b6 6a 77          	movzx  ebp,BYTE PTR [rdx+0x77]
    129a:	42 32 6c 0a 17       	xor    bpl,BYTE PTR [rdx+r9*1+0x17]
    129f:	40 08 eb             	or     bl,bpl
    12a2:	e9 49 ff ff ff       	jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    12a7:	49 83 f9 60          	cmp    r9,0x60
    12ab:	74 13                	je     12c0 <bpftrace_string_search_prefix_scan_xdp+0x1c0>
    12ad:	48 c1 e7 20          	shl    rdi,0x20
    12b1:	4c 01 cf             	add    rdi,r9
    12b4:	c4 e3 fb f0 c7 3d    	rorx   rax,rdi,0x3d
    12ba:	49 31 c0             	xor    r8,rax
    12bd:	4c 89 c0             	mov    rax,r8
    12c0:	48 89 01             	mov    QWORD PTR [rcx],rax
    12c3:	b8 02 00 00 00       	mov    eax,0x2
    12c8:	5b                   	pop    rbx
    12c9:	5d                   	pop    rbp
    12ca:	c3                   	ret

Disassembly of section .fini:

00000000000012cc <_fini>:
    12cc:	f3 0f 1e fa          	endbr64
    12d0:	48 83 ec 08          	sub    rsp,0x8
    12d4:	48 83 c4 08          	add    rsp,0x8
    12d8:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
