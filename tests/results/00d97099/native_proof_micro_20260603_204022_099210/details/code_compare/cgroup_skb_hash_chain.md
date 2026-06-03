# cgroup_skb_hash_chain

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

0000000000001100 <cgroup_skb_hash_chain_prog>:
    1100:	48 8b 77 50          	mov    rsi,QWORD PTR [rdi+0x50]
    1104:	48 8b 87 d0 00 00 00 	mov    rax,QWORD PTR [rdi+0xd0]
    110b:	48 39 f0             	cmp    rax,rsi
    110e:	76 12                	jbe    1122 <cgroup_skb_hash_chain_prog+0x22>
    1110:	c7 47 30 ff ff ff ff 	mov    DWORD PTR [rdi+0x30],0xffffffff
    1117:	31 c0                	xor    eax,eax
    1119:	b9 ff ff ff ff       	mov    ecx,0xffffffff
    111e:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
    1121:	c3                   	ret
    1122:	48 8d 48 08          	lea    rcx,[rax+0x8]
    1126:	48 39 f1             	cmp    rcx,rsi
    1129:	77 e5                	ja     1110 <cgroup_skb_hash_chain_prog+0x10>
    112b:	48 8d 50 50          	lea    rdx,[rax+0x50]
    112f:	48 39 f2             	cmp    rdx,rsi
    1132:	77 dc                	ja     1110 <cgroup_skb_hash_chain_prog+0x10>
    1134:	48 89 ce             	mov    rsi,rcx
    1137:	49 89 d0             	mov    r8,rdx
    113a:	4c 39 c6             	cmp    rsi,r8
    113d:	77 d1                	ja     1110 <cgroup_skb_hash_chain_prog+0x10>
    113f:	48 83 c6 08          	add    rsi,0x8
    1143:	4c 39 c6             	cmp    rsi,r8
    1146:	77 c8                	ja     1110 <cgroup_skb_hash_chain_prog+0x10>
    1148:	83 78 08 10          	cmp    DWORD PTR [rax+0x8],0x10
    114c:	75 c2                	jne    1110 <cgroup_skb_hash_chain_prog+0x10>
    114e:	83 78 0c 08          	cmp    DWORD PTR [rax+0xc],0x8
    1152:	75 bc                	jne    1110 <cgroup_skb_hash_chain_prog+0x10>
    1154:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1158:	48 39 d6             	cmp    rsi,rdx
    115b:	77 b3                	ja     1110 <cgroup_skb_hash_chain_prog+0x10>
    115d:	48 83 c1 48          	add    rcx,0x48
    1161:	48 39 d1             	cmp    rcx,rdx
    1164:	77 aa                	ja     1110 <cgroup_skb_hash_chain_prog+0x10>
    1166:	55                   	push   rbp
    1167:	41 57                	push   r15
    1169:	41 56                	push   r14
    116b:	41 55                	push   r13
    116d:	41 54                	push   r12
    116f:	53                   	push   rbx
    1170:	49 bd 15 7c 4a 7f b9 	movabs r13,0x9e3779b97f4a7c15
    1177:	79 37 9e 
    117a:	48 be b3 01 00 00 00 	movabs rsi,0x100000001b3
    1181:	01 00 00 
    1184:	4c 8b 40 10          	mov    r8,QWORD PTR [rax+0x10]
    1188:	4c 8b 48 18          	mov    r9,QWORD PTR [rax+0x18]
    118c:	4c 8b 50 20          	mov    r10,QWORD PTR [rax+0x20]
    1190:	4c 8b 58 28          	mov    r11,QWORD PTR [rax+0x28]
    1194:	48 8b 58 30          	mov    rbx,QWORD PTR [rax+0x30]
    1198:	4c 8b 70 38          	mov    r14,QWORD PTR [rax+0x38]
    119c:	4c 8b 78 40          	mov    r15,QWORD PTR [rax+0x40]
    11a0:	4c 8b 60 48          	mov    r12,QWORD PTR [rax+0x48]
    11a4:	48 b9 25 23 22 84 e4 	movabs rcx,0xcbf29ce484222325
    11ab:	9c f2 cb 
    11ae:	b8 3e 00 00 00       	mov    eax,0x3e
    11b3:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11ba:	84 00 00 00 00 00 
    11c0:	4c 89 ea             	mov    rdx,r13
    11c3:	48 bd 95 ef 82 de 43 	movabs rbp,0xd1342543de82ef95
    11ca:	25 34 d1 
    11cd:	48 31 ea             	xor    rdx,rbp
    11d0:	4c 01 c2             	add    rdx,r8
    11d3:	48 31 ca             	xor    rdx,rcx
    11d6:	8d 48 c9             	lea    ecx,[rax-0x37]
    11d9:	48 d3 c2             	rol    rdx,cl
    11dc:	48 0f af d6          	imul   rdx,rsi
    11e0:	4c 89 e9             	mov    rcx,r13
    11e3:	48 bd 2a df 05 bd 87 	movabs rbp,0xa2684a87bd05df2a
    11ea:	4a 68 a2 
    11ed:	48 31 e9             	xor    rcx,rbp
    11f0:	4c 01 c9             	add    rcx,r9
    11f3:	48 31 d1             	xor    rcx,rdx
    11f6:	48 c1 ea 1d          	shr    rdx,0x1d
    11fa:	48 31 ca             	xor    rdx,rcx
    11fd:	8d 48 d4             	lea    ecx,[rax-0x2c]
    1200:	48 d3 c2             	rol    rdx,cl
    1203:	48 0f af d6          	imul   rdx,rsi
    1207:	4c 89 e9             	mov    rcx,r13
    120a:	48 bd bf ce 88 9b cb 	movabs rbp,0x739c6fcb9b88cebf
    1211:	6f 9c 73 
    1214:	48 31 e9             	xor    rcx,rbp
    1217:	4c 01 d1             	add    rcx,r10
    121a:	48 31 d1             	xor    rcx,rdx
    121d:	48 c1 ea 1d          	shr    rdx,0x1d
    1221:	48 31 ca             	xor    rdx,rcx
    1224:	8d 48 df             	lea    ecx,[rax-0x21]
    1227:	48 d3 c2             	rol    rdx,cl
    122a:	48 0f af d6          	imul   rdx,rsi
    122e:	4c 89 e9             	mov    rcx,r13
    1231:	48 bd 54 be 0b 7a 0f 	movabs rbp,0x44d0950f7a0bbe54
    1238:	95 d0 44 
    123b:	48 31 e9             	xor    rcx,rbp
    123e:	4c 01 d9             	add    rcx,r11
    1241:	48 31 d1             	xor    rcx,rdx
    1244:	48 c1 ea 1d          	shr    rdx,0x1d
    1248:	48 31 ca             	xor    rdx,rcx
    124b:	8d 48 ea             	lea    ecx,[rax-0x16]
    124e:	48 d3 c2             	rol    rdx,cl
    1251:	48 0f af d6          	imul   rdx,rsi
    1255:	4c 89 e9             	mov    rcx,r13
    1258:	48 bd e9 ad 8e 58 53 	movabs rbp,0x1604ba53588eade9
    125f:	ba 04 16 
    1262:	48 31 e9             	xor    rcx,rbp
    1265:	48 01 d9             	add    rcx,rbx
    1268:	48 31 d1             	xor    rcx,rdx
    126b:	48 c1 ea 1d          	shr    rdx,0x1d
    126f:	48 31 ca             	xor    rdx,rcx
    1272:	8d 48 f5             	lea    ecx,[rax-0xb]
    1275:	48 d3 c2             	rol    rdx,cl
    1278:	48 0f af d6          	imul   rdx,rsi
    127c:	4c 89 e9             	mov    rcx,r13
    127f:	48 bd 7e 9d 11 37 97 	movabs rbp,0xe738df9737119d7e
    1286:	df 38 e7 
    1289:	48 31 e9             	xor    rcx,rbp
    128c:	4c 01 f1             	add    rcx,r14
    128f:	48 31 d1             	xor    rcx,rdx
    1292:	48 c1 ea 1d          	shr    rdx,0x1d
    1296:	48 31 ca             	xor    rdx,rcx
    1299:	89 c1                	mov    ecx,eax
    129b:	48 d3 c2             	rol    rdx,cl
    129e:	48 0f af d6          	imul   rdx,rsi
    12a2:	4c 89 e9             	mov    rcx,r13
    12a5:	48 bd 13 8d 94 15 db 	movabs rbp,0xb86d04db15948d13
    12ac:	04 6d b8 
    12af:	48 31 e9             	xor    rcx,rbp
    12b2:	4c 01 f9             	add    rcx,r15
    12b5:	48 31 d1             	xor    rcx,rdx
    12b8:	48 c1 ea 1d          	shr    rdx,0x1d
    12bc:	48 31 ca             	xor    rdx,rcx
    12bf:	8d 48 cb             	lea    ecx,[rax-0x35]
    12c2:	48 d3 c2             	rol    rdx,cl
    12c5:	48 0f af d6          	imul   rdx,rsi
    12c9:	4c 89 e9             	mov    rcx,r13
    12cc:	48 bd a8 7c 17 f4 1e 	movabs rbp,0x89a12a1ef4177ca8
    12d3:	2a a1 89 
    12d6:	48 31 e9             	xor    rcx,rbp
    12d9:	4c 01 e1             	add    rcx,r12
    12dc:	48 31 d1             	xor    rcx,rdx
    12df:	48 c1 ea 1d          	shr    rdx,0x1d
    12e3:	48 31 ca             	xor    rdx,rcx
    12e6:	8d 48 d6             	lea    ecx,[rax-0x2a]
    12e9:	48 d3 c2             	rol    rdx,cl
    12ec:	48 0f af d6          	imul   rdx,rsi
    12f0:	48 89 d1             	mov    rcx,rdx
    12f3:	48 c1 e9 1d          	shr    rcx,0x1d
    12f7:	48 31 d1             	xor    rcx,rdx
    12fa:	48 83 c0 05          	add    rax,0x5
    12fe:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
    1305:	79 37 9e 
    1308:	49 01 d5             	add    r13,rdx
    130b:	48 3d 8e 00 00 00    	cmp    rax,0x8e
    1311:	0f 85 a9 fe ff ff    	jne    11c0 <cgroup_skb_hash_chain_prog+0xc0>
    1317:	89 4f 30             	mov    DWORD PTR [rdi+0x30],ecx
    131a:	48 c1 e9 20          	shr    rcx,0x20
    131e:	b8 01 00 00 00       	mov    eax,0x1
    1323:	5b                   	pop    rbx
    1324:	41 5c                	pop    r12
    1326:	41 5d                	pop    r13
    1328:	41 5e                	pop    r14
    132a:	41 5f                	pop    r15
    132c:	5d                   	pop    rbp
    132d:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
    1330:	c3                   	ret

Disassembly of section .fini:

0000000000001334 <_fini>:
    1334:	f3 0f 1e fa          	endbr64
    1338:	48 83 ec 08          	sub    rsp,0x8
    133c:	48 83 c4 08          	add    rsp,0x8
    1340:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
