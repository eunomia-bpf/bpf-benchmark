# bcc_runqlat_log2_histogram_bucket

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

0000000000001100 <bcc_runqlat_log2_histogram_bucket_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
    1107:	48 89 ca             	mov    rdx,rcx
    110a:	31 c0                	xor    eax,eax
    110c:	48 39 f2             	cmp    rdx,rsi
    110f:	76 01                	jbe    1112 <bcc_runqlat_log2_histogram_bucket_xdp+0x12>
    1111:	c3                   	ret
    1112:	48 8d 7a 08          	lea    rdi,[rdx+0x8]
    1116:	48 39 f7             	cmp    rdi,rsi
    1119:	77 f6                	ja     1111 <bcc_runqlat_log2_histogram_bucket_xdp+0x11>
    111b:	4c 8d 82 10 04 00 00 	lea    r8,[rdx+0x410]
    1122:	49 39 f0             	cmp    r8,rsi
    1125:	77 ea                	ja     1111 <bcc_runqlat_log2_histogram_bucket_xdp+0x11>
    1127:	81 3f 80 00 00 00    	cmp    DWORD PTR [rdi],0x80
    112d:	75 e2                	jne    1111 <bcc_runqlat_log2_histogram_bucket_xdp+0x11>
    112f:	53                   	push   rbx
    1130:	8b 72 0c             	mov    esi,DWORD PTR [rdx+0xc]
    1133:	31 c0                	xor    eax,eax
    1135:	eb 2d                	jmp    1164 <bcc_runqlat_log2_histogram_bucket_xdp+0x64>
    1137:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    113e:	00 00 
    1140:	48 c1 e0 03          	shl    rax,0x3
    1144:	44 89 d6             	mov    esi,r10d
    1147:	24 38                	and    al,0x38
    1149:	c4 e2 f9 f7 c6       	shlx   rax,rsi,rax
    114e:	49 31 c3             	xor    r11,rax
    1151:	4c 89 de             	mov    rsi,r11
    1154:	4c 89 c0             	mov    rax,r8
    1157:	49 81 f8 80 00 00 00 	cmp    r8,0x80
    115e:	0f 84 e6 00 00 00    	je     124a <bcc_runqlat_log2_histogram_bucket_xdp+0x14a>
    1164:	0f b7 7c c2 10       	movzx  edi,WORD PTR [rdx+rax*8+0x10]
    1169:	44 0f b6 44 c2 12    	movzx  r8d,BYTE PTR [rdx+rax*8+0x12]
    116f:	41 c1 e0 10          	shl    r8d,0x10
    1173:	49 09 f8             	or     r8,rdi
    1176:	45 89 c1             	mov    r9d,r8d
    1179:	41 c1 e9 03          	shr    r9d,0x3
    117d:	bf 00 00 00 00       	mov    edi,0x0
    1182:	41 81 e1 ff ff 0f 00 	and    r9d,0xfffff
    1189:	74 21                	je     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac>
    118b:	49 ff c1             	inc    r9
    118e:	31 ff                	xor    edi,edi
    1190:	41 89 fa             	mov    r10d,edi
    1193:	41 8d 7a 01          	lea    edi,[r10+0x1]
    1197:	41 83 fa 3d          	cmp    r10d,0x3d
    119b:	77 0f                	ja     11ac <bcc_runqlat_log2_histogram_bucket_xdp+0xac>
    119d:	4d 89 ca             	mov    r10,r9
    11a0:	49 d1 ea             	shr    r10,1
    11a3:	49 83 f9 03          	cmp    r9,0x3
    11a7:	4d 89 d1             	mov    r9,r10
    11aa:	77 e4                	ja     1190 <bcc_runqlat_log2_histogram_bucket_xdp+0x90>
    11ac:	44 0f b6 4c c2 13    	movzx  r9d,BYTE PTR [rdx+rax*8+0x13]
    11b2:	41 c1 e1 18          	shl    r9d,0x18
    11b6:	4d 09 c1             	or     r9,r8
    11b9:	44 0f b6 44 c2 14    	movzx  r8d,BYTE PTR [rdx+rax*8+0x14]
    11bf:	49 c1 e0 20          	shl    r8,0x20
    11c3:	44 0f b6 54 c2 15    	movzx  r10d,BYTE PTR [rdx+rax*8+0x15]
    11c9:	49 c1 e2 28          	shl    r10,0x28
    11cd:	4d 09 c2             	or     r10,r8
    11d0:	4d 09 ca             	or     r10,r9
    11d3:	44 0f b6 44 c2 16    	movzx  r8d,BYTE PTR [rdx+rax*8+0x16]
    11d9:	49 c1 e0 30          	shl    r8,0x30
    11dd:	44 0f b6 4c c2 17    	movzx  r9d,BYTE PTR [rdx+rax*8+0x17]
    11e3:	49 c1 e1 38          	shl    r9,0x38
    11e7:	4d 09 c1             	or     r9,r8
    11ea:	4d 09 d1             	or     r9,r10
    11ed:	83 ff 19             	cmp    edi,0x19
    11f0:	41 ba 19 00 00 00    	mov    r10d,0x19
    11f6:	44 0f 42 d7          	cmovb  r10d,edi
    11fa:	45 8d 5a 01          	lea    r11d,[r10+0x1]
    11fe:	4c 8d 40 01          	lea    r8,[rax+0x1]
    1202:	4d 0f af d8          	imul   r11,r8
    1206:	4c 01 de             	add    rsi,r11
    1209:	45 89 d3             	mov    r11d,r10d
    120c:	41 80 e3 07          	and    r11b,0x7
    1210:	41 8d 5b 01          	lea    ebx,[r11+0x1]
    1214:	c4 c2 e1 f7 d9       	shlx   rbx,r9,rbx
    1219:	41 f6 d3             	not    r11b
    121c:	c4 42 a3 f7 d9       	shrx   r11,r9,r11
    1221:	49 09 db             	or     r11,rbx
    1224:	49 31 f3             	xor    r11,rsi
    1227:	83 ff 19             	cmp    edi,0x19
    122a:	0f 82 10 ff ff ff    	jb     1140 <bcc_runqlat_log2_histogram_bucket_xdp+0x40>
    1230:	49 c1 e9 20          	shr    r9,0x20
    1234:	4d 01 cb             	add    r11,r9
    1237:	4c 89 de             	mov    rsi,r11
    123a:	4c 89 c0             	mov    rax,r8
    123d:	49 81 f8 80 00 00 00 	cmp    r8,0x80
    1244:	0f 85 1a ff ff ff    	jne    1164 <bcc_runqlat_log2_histogram_bucket_xdp+0x64>
    124a:	48 89 31             	mov    QWORD PTR [rcx],rsi
    124d:	b8 02 00 00 00       	mov    eax,0x2
    1252:	5b                   	pop    rbx
    1253:	c3                   	ret

Disassembly of section .fini:

0000000000001254 <_fini>:
    1254:	f3 0f 1e fa          	endbr64
    1258:	48 83 ec 08          	sub    rsp,0x8
    125c:	48 83 c4 08          	add    rsp,0x8
    1260:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
