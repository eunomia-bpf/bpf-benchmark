# tc_packet_checksum_fold

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

0000000000001100 <tc_packet_checksum_fold_prog>:
    1100:	48 8b 77 50          	mov    rsi,QWORD PTR [rdi+0x50]
    1104:	48 8b 87 d0 00 00 00 	mov    rax,QWORD PTR [rdi+0xd0]
    110b:	48 39 f0             	cmp    rax,rsi
    110e:	76 15                	jbe    1125 <tc_packet_checksum_fold_prog+0x25>
    1110:	c7 47 30 ff ff ff ff 	mov    DWORD PTR [rdi+0x30],0xffffffff
    1117:	b8 02 00 00 00       	mov    eax,0x2
    111c:	b9 ff ff ff ff       	mov    ecx,0xffffffff
    1121:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
    1124:	c3                   	ret
    1125:	48 8d 48 08          	lea    rcx,[rax+0x8]
    1129:	48 39 f1             	cmp    rcx,rsi
    112c:	77 e2                	ja     1110 <tc_packet_checksum_fold_prog+0x10>
    112e:	48 8d 90 10 04 00 00 	lea    rdx,[rax+0x410]
    1135:	48 39 f2             	cmp    rdx,rsi
    1138:	77 d6                	ja     1110 <tc_packet_checksum_fold_prog+0x10>
    113a:	48 89 ce             	mov    rsi,rcx
    113d:	49 89 d0             	mov    r8,rdx
    1140:	4c 39 c6             	cmp    rsi,r8
    1143:	77 cb                	ja     1110 <tc_packet_checksum_fold_prog+0x10>
    1145:	48 83 c6 08          	add    rsi,0x8
    1149:	4c 39 c6             	cmp    rsi,r8
    114c:	77 c2                	ja     1110 <tc_packet_checksum_fold_prog+0x10>
    114e:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
    1152:	75 bc                	jne    1110 <tc_packet_checksum_fold_prog+0x10>
    1154:	81 78 0c 00 02 00 00 	cmp    DWORD PTR [rax+0xc],0x200
    115b:	75 b3                	jne    1110 <tc_packet_checksum_fold_prog+0x10>
    115d:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1161:	48 39 d6             	cmp    rsi,rdx
    1164:	77 aa                	ja     1110 <tc_packet_checksum_fold_prog+0x10>
    1166:	48 81 c1 08 04 00 00 	add    rcx,0x408
    116d:	48 39 d1             	cmp    rcx,rdx
    1170:	77 9e                	ja     1110 <tc_packet_checksum_fold_prog+0x10>
    1172:	31 d2                	xor    edx,edx
    1174:	31 c9                	xor    ecx,ecx
    1176:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    117d:	00 00 00 
    1180:	31 f6                	xor    esi,esi
    1182:	45 31 c0             	xor    r8d,r8d
    1185:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    118c:	00 00 00 00 
    1190:	44 0f b7 4c 70 10    	movzx  r9d,WORD PTR [rax+rsi*2+0x10]
    1196:	45 01 c1             	add    r9d,r8d
    1199:	45 0f b7 c1          	movzx  r8d,r9w
    119d:	41 c1 e9 10          	shr    r9d,0x10
    11a1:	45 01 c1             	add    r9d,r8d
    11a4:	44 0f b7 44 70 12    	movzx  r8d,WORD PTR [rax+rsi*2+0x12]
    11aa:	45 01 c8             	add    r8d,r9d
    11ad:	45 0f b7 c8          	movzx  r9d,r8w
    11b1:	41 c1 e8 10          	shr    r8d,0x10
    11b5:	45 01 c8             	add    r8d,r9d
    11b8:	44 0f b7 4c 70 14    	movzx  r9d,WORD PTR [rax+rsi*2+0x14]
    11be:	45 01 c1             	add    r9d,r8d
    11c1:	45 0f b7 c1          	movzx  r8d,r9w
    11c5:	41 c1 e9 10          	shr    r9d,0x10
    11c9:	45 01 c1             	add    r9d,r8d
    11cc:	44 0f b7 44 70 16    	movzx  r8d,WORD PTR [rax+rsi*2+0x16]
    11d2:	45 01 c8             	add    r8d,r9d
    11d5:	45 0f b7 c8          	movzx  r9d,r8w
    11d9:	41 c1 e8 10          	shr    r8d,0x10
    11dd:	45 01 c8             	add    r8d,r9d
    11e0:	48 83 c6 04          	add    rsi,0x4
    11e4:	48 81 fe 00 02 00 00 	cmp    rsi,0x200
    11eb:	75 a3                	jne    1190 <tc_packet_checksum_fold_prog+0x90>
    11ed:	44 89 c6             	mov    esi,r8d
    11f0:	c1 ee 10             	shr    esi,0x10
    11f3:	44 01 c6             	add    esi,r8d
    11f6:	f7 d6                	not    esi
    11f8:	0f b7 f6             	movzx  esi,si
    11fb:	41 89 d0             	mov    r8d,edx
    11fe:	41 c1 e0 04          	shl    r8d,0x4
    1202:	c4 e2 b9 f7 f6       	shlx   rsi,rsi,r8
    1207:	48 31 f1             	xor    rcx,rsi
    120a:	ff c2                	inc    edx
    120c:	83 fa 20             	cmp    edx,0x20
    120f:	0f 85 6b ff ff ff    	jne    1180 <tc_packet_checksum_fold_prog+0x80>
    1215:	89 4f 30             	mov    DWORD PTR [rdi+0x30],ecx
    1218:	48 c1 e9 20          	shr    rcx,0x20
    121c:	31 c0                	xor    eax,eax
    121e:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
    1221:	c3                   	ret

Disassembly of section .fini:

0000000000001224 <_fini>:
    1224:	f3 0f 1e fa          	endbr64
    1228:	48 83 ec 08          	sub    rsp,0x8
    122c:	48 83 c4 08          	add    rsp,0x8
    1230:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
