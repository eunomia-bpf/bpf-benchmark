# sorted_rule_binary_search

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

0000000000001100 <sorted_rule_binary_search_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <sorted_rule_binary_search_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <sorted_rule_binary_search_xdp+0x11>
    111b:	48 8d ba 90 01 00 00 	lea    rdi,[rdx+0x190]
    1122:	48 39 f7             	cmp    rdi,rsi
    1125:	77 ea                	ja     1111 <sorted_rule_binary_search_xdp+0x11>
    1127:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    112b:	75 e4                	jne    1111 <sorted_rule_binary_search_xdp+0x11>
    112d:	83 7a 0c 10          	cmp    DWORD PTR [rdx+0xc],0x10
    1131:	75 de                	jne    1111 <sorted_rule_binary_search_xdp+0x11>
    1133:	53                   	push   rbx
    1134:	31 c0                	xor    eax,eax
    1136:	31 f6                	xor    esi,esi
    1138:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    113f:	00 
    1140:	48 8b bc c2 10 01 00 	mov    rdi,QWORD PTR [rdx+rax*8+0x110]
    1147:	00 
    1148:	45 31 c9             	xor    r9d,r9d
    114b:	45 31 c0             	xor    r8d,r8d
    114e:	45 31 d2             	xor    r10d,r10d
    1151:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1158:	0f 1f 84 00 00 00 00 
    115f:	00 
    1160:	4a 39 7c ca 10       	cmp    QWORD PTR [rdx+r9*8+0x10],rdi
    1165:	41 0f 94 c3          	sete   r11b
    1169:	4c 89 c3             	mov    rbx,r8
    116c:	49 0f 44 d9          	cmove  rbx,r9
    1170:	45 08 d3             	or     r11b,r10b
    1173:	41 f6 c2 01          	test   r10b,0x1
    1177:	49 0f 45 d8          	cmovne rbx,r8
    117b:	4d 8d 41 01          	lea    r8,[r9+0x1]
    117f:	4a 39 7c ca 18       	cmp    QWORD PTR [rdx+r9*8+0x18],rdi
    1184:	41 0f 94 c2          	sete   r10b
    1188:	4c 0f 45 c3          	cmovne r8,rbx
    118c:	45 08 da             	or     r10b,r11b
    118f:	41 f6 c3 01          	test   r11b,0x1
    1193:	4c 0f 45 c3          	cmovne r8,rbx
    1197:	49 83 c1 02          	add    r9,0x2
    119b:	49 83 f9 20          	cmp    r9,0x20
    119f:	75 bf                	jne    1160 <sorted_rule_binary_search_xdp+0x60>
    11a1:	49 01 f0             	add    r8,rsi
    11a4:	48 83 c7 20          	add    rdi,0x20
    11a8:	48 31 fe             	xor    rsi,rdi
    11ab:	41 f6 c2 01          	test   r10b,0x1
    11af:	49 0f 45 f0          	cmovne rsi,r8
    11b3:	48 ff c0             	inc    rax
    11b6:	48 83 f8 10          	cmp    rax,0x10
    11ba:	75 84                	jne    1140 <sorted_rule_binary_search_xdp+0x40>
    11bc:	48 89 31             	mov    QWORD PTR [rcx],rsi
    11bf:	b8 02 00 00 00       	mov    eax,0x2
    11c4:	5b                   	pop    rbx
    11c5:	c3                   	ret

Disassembly of section .fini:

00000000000011c8 <_fini>:
    11c8:	f3 0f 1e fa          	endbr64
    11cc:	48 83 ec 08          	sub    rsp,0x8
    11d0:	48 83 c4 08          	add    rsp,0x8
    11d4:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
