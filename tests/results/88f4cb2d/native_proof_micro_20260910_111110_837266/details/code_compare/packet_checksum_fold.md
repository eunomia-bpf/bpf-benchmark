# packet_checksum_fold

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

0000000000001100 <packet_checksum_fold_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <packet_checksum_fold_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <packet_checksum_fold_xdp+0x11>
    111b:	48 8d ba 10 04 00 00 	lea    rdi,[rdx+0x410]
    1122:	48 39 f7             	cmp    rdi,rsi
    1125:	77 ea                	ja     1111 <packet_checksum_fold_xdp+0x11>
    1127:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    112b:	75 e4                	jne    1111 <packet_checksum_fold_xdp+0x11>
    112d:	81 7a 0c 00 02 00 00 	cmp    DWORD PTR [rdx+0xc],0x200
    1134:	75 db                	jne    1111 <packet_checksum_fold_xdp+0x11>
    1136:	31 c0                	xor    eax,eax
    1138:	31 f6                	xor    esi,esi
    113a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1140:	31 ff                	xor    edi,edi
    1142:	45 31 c0             	xor    r8d,r8d
    1145:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    114c:	00 00 00 00 
    1150:	44 0f b7 4c 7a 10    	movzx  r9d,WORD PTR [rdx+rdi*2+0x10]
    1156:	45 01 c1             	add    r9d,r8d
    1159:	45 0f b7 c1          	movzx  r8d,r9w
    115d:	41 c1 e9 10          	shr    r9d,0x10
    1161:	45 01 c1             	add    r9d,r8d
    1164:	44 0f b7 44 7a 12    	movzx  r8d,WORD PTR [rdx+rdi*2+0x12]
    116a:	45 01 c8             	add    r8d,r9d
    116d:	45 0f b7 c8          	movzx  r9d,r8w
    1171:	41 c1 e8 10          	shr    r8d,0x10
    1175:	45 01 c8             	add    r8d,r9d
    1178:	44 0f b7 4c 7a 14    	movzx  r9d,WORD PTR [rdx+rdi*2+0x14]
    117e:	45 01 c1             	add    r9d,r8d
    1181:	45 0f b7 c1          	movzx  r8d,r9w
    1185:	41 c1 e9 10          	shr    r9d,0x10
    1189:	45 01 c1             	add    r9d,r8d
    118c:	44 0f b7 44 7a 16    	movzx  r8d,WORD PTR [rdx+rdi*2+0x16]
    1192:	45 01 c8             	add    r8d,r9d
    1195:	45 0f b7 c8          	movzx  r9d,r8w
    1199:	41 c1 e8 10          	shr    r8d,0x10
    119d:	45 01 c8             	add    r8d,r9d
    11a0:	48 83 c7 04          	add    rdi,0x4
    11a4:	48 81 ff 00 02 00 00 	cmp    rdi,0x200
    11ab:	75 a3                	jne    1150 <packet_checksum_fold_xdp+0x50>
    11ad:	44 89 c7             	mov    edi,r8d
    11b0:	c1 ef 10             	shr    edi,0x10
    11b3:	44 01 c7             	add    edi,r8d
    11b6:	f7 d7                	not    edi
    11b8:	0f b7 ff             	movzx  edi,di
    11bb:	41 89 c0             	mov    r8d,eax
    11be:	41 c1 e0 04          	shl    r8d,0x4
    11c2:	c4 e2 b9 f7 ff       	shlx   rdi,rdi,r8
    11c7:	48 31 fe             	xor    rsi,rdi
    11ca:	ff c0                	inc    eax
    11cc:	83 f8 20             	cmp    eax,0x20
    11cf:	0f 85 6b ff ff ff    	jne    1140 <packet_checksum_fold_xdp+0x40>
    11d5:	48 89 31             	mov    QWORD PTR [rcx],rsi
    11d8:	b8 02 00 00 00       	mov    eax,0x2
    11dd:	c3                   	ret

Disassembly of section .fini:

00000000000011e0 <_fini>:
    11e0:	f3 0f 1e fa          	endbr64
    11e4:	48 83 ec 08          	sub    rsp,0x8
    11e8:	48 83 c4 08          	add    rsp,0x8
    11ec:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
