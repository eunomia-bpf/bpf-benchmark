# flow_5tuple_rss_hash

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
    1040:	48 8d 3d c9 2f 00 00 	lea    rdi,[rip+0x2fc9]        # 4010 <__TMC_END__>
    1047:	48 8d 05 c2 2f 00 00 	lea    rax,[rip+0x2fc2]        # 4010 <__TMC_END__>
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
    1070:	48 8d 3d 99 2f 00 00 	lea    rdi,[rip+0x2f99]        # 4010 <__TMC_END__>
    1077:	48 8d 35 92 2f 00 00 	lea    rsi,[rip+0x2f92]        # 4010 <__TMC_END__>
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
    10b4:	80 3d 51 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f51],0x0        # 400c <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 29 2f 00 00 01 	mov    BYTE PTR [rip+0x2f29],0x1        # 400c <completed.0>
    10e3:	5d                   	pop    rbp
    10e4:	c3                   	ret
    10e5:	0f 1f 00             	nop    DWORD PTR [rax]
    10e8:	c3                   	ret
    10e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010f0 <frame_dummy>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	e9 77 ff ff ff       	jmp    1070 <register_tm_clones>
    10f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001100 <flow_5tuple_rss_hash_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	0f 87 f2 01 00 00    	ja     1304 <flow_5tuple_rss_hash_xdp+0x204>
    1112:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1116:	48 39 d6             	cmp    rsi,rdx
    1119:	0f 87 e5 01 00 00    	ja     1304 <flow_5tuple_rss_hash_xdp+0x204>
    111f:	48 8d 71 16          	lea    rsi,[rcx+0x16]
    1123:	48 39 d6             	cmp    rsi,rdx
    1126:	0f 87 d8 01 00 00    	ja     1304 <flow_5tuple_rss_hash_xdp+0x204>
    112c:	55                   	push   rbp
    112d:	41 57                	push   r15
    112f:	41 56                	push   r14
    1131:	53                   	push   rbx
    1132:	66 0f 38 f0 79 14    	movbe  di,WORD PTR [rcx+0x14]
    1138:	0f b7 ff             	movzx  edi,di
    113b:	81 ff 00 08 00 00    	cmp    edi,0x800
    1141:	0f 85 b7 01 00 00    	jne    12fe <flow_5tuple_rss_hash_xdp+0x1fe>
    1147:	48 8d 79 2a          	lea    rdi,[rcx+0x2a]
    114b:	48 39 d7             	cmp    rdi,rdx
    114e:	0f 87 aa 01 00 00    	ja     12fe <flow_5tuple_rss_hash_xdp+0x1fe>
    1154:	0f b6 3e             	movzx  edi,BYTE PTR [rsi]
    1157:	41 89 f8             	mov    r8d,edi
    115a:	41 80 e0 f0          	and    r8b,0xf0
    115e:	41 80 f8 40          	cmp    r8b,0x40
    1162:	0f 85 96 01 00 00    	jne    12fe <flow_5tuple_rss_hash_xdp+0x1fe>
    1168:	83 e7 0f             	and    edi,0xf
    116b:	40 80 ff 05          	cmp    dil,0x5
    116f:	0f 82 89 01 00 00    	jb     12fe <flow_5tuple_rss_hash_xdp+0x1fe>
    1175:	48 8d 3c be          	lea    rdi,[rsi+rdi*4]
    1179:	48 39 d7             	cmp    rdi,rdx
    117c:	0f 87 7c 01 00 00    	ja     12fe <flow_5tuple_rss_hash_xdp+0x1fe>
    1182:	44 0f b6 41 18       	movzx  r8d,BYTE PTR [rcx+0x18]
    1187:	0f b6 71 19          	movzx  esi,BYTE PTR [rcx+0x19]
    118b:	0f b6 59 1f          	movzx  ebx,BYTE PTR [rcx+0x1f]
    118f:	83 fb 11             	cmp    ebx,0x11
    1192:	74 09                	je     119d <flow_5tuple_rss_hash_xdp+0x9d>
    1194:	83 fb 06             	cmp    ebx,0x6
    1197:	0f 85 61 01 00 00    	jne    12fe <flow_5tuple_rss_hash_xdp+0x1fe>
    119d:	4c 8d 4f 04          	lea    r9,[rdi+0x4]
    11a1:	49 39 d1             	cmp    r9,rdx
    11a4:	0f 87 54 01 00 00    	ja     12fe <flow_5tuple_rss_hash_xdp+0x1fe>
    11aa:	44 89 c0             	mov    eax,r8d
    11ad:	0f 38 f0 51 26       	movbe  edx,DWORD PTR [rcx+0x26]
    11b2:	c1 e0 08             	shl    eax,0x8
    11b5:	44 0f 38 f0 49 22    	movbe  r9d,DWORD PTR [rcx+0x22]
    11bb:	66 44 0f 38 f0 17    	movbe  r10w,WORD PTR [rdi]
    11c1:	09 f0                	or     eax,esi
    11c3:	41 0f b7 f2          	movzx  esi,r10w
    11c7:	66 0f 38 f0 7f 02    	movbe  di,WORD PTR [rdi+0x2]
    11cd:	0f b7 ff             	movzx  edi,di
    11d0:	46 8d 14 08          	lea    r10d,[rax+r9*1]
    11d4:	8d aa b9 79 37 9e    	lea    ebp,[rdx-0x61c88647]
    11da:	41 89 f3             	mov    r11d,esi
    11dd:	41 c1 e3 10          	shl    r11d,0x10
    11e1:	41 09 fb             	or     r11d,edi
    11e4:	46 8d 34 1b          	lea    r14d,[rbx+r11*1]
    11e8:	46 8d 3c 1b          	lea    r15d,[rbx+r11*1]
    11ec:	41 81 c7 78 56 34 12 	add    r15d,0x12345678
    11f3:	45 29 fa             	sub    r10d,r15d
    11f6:	41 81 c2 ef be ad de 	add    r10d,0xdeadbeef
    11fd:	c4 43 7b f0 ff 1c    	rorx   r15d,r15d,0x1c
    1203:	45 31 d7             	xor    r15d,r10d
    1206:	46 8d 14 32          	lea    r10d,[rdx+r14*1]
    120a:	41 81 c2 31 d0 6b b0 	add    r10d,0xb06bd031
    1211:	44 29 fd             	sub    ebp,r15d
    1214:	c4 43 7b f0 f7 1a    	rorx   r14d,r15d,0x1a
    121a:	41 31 ee             	xor    r14d,ebp
    121d:	45 01 d7             	add    r15d,r10d
    1220:	45 29 f2             	sub    r10d,r14d
    1223:	c4 c3 7b f0 ee 18    	rorx   ebp,r14d,0x18
    1229:	44 31 d5             	xor    ebp,r10d
    122c:	45 01 fe             	add    r14d,r15d
    122f:	41 29 ef             	sub    r15d,ebp
    1232:	c4 63 7b f0 d5 10    	rorx   r10d,ebp,0x10
    1238:	45 31 fa             	xor    r10d,r15d
    123b:	44 01 f5             	add    ebp,r14d
    123e:	45 29 d6             	sub    r14d,r10d
    1241:	c4 43 7b f0 fa 0d    	rorx   r15d,r10d,0xd
    1247:	45 31 f7             	xor    r15d,r14d
    124a:	41 01 ea             	add    r10d,ebp
    124d:	44 29 fd             	sub    ebp,r15d
    1250:	c4 43 7b f0 f7 1c    	rorx   r14d,r15d,0x1c
    1256:	41 31 ee             	xor    r14d,ebp
    1259:	41 31 d1             	xor    r9d,edx
    125c:	c4 43 7b f0 c9 19    	rorx   r9d,r9d,0x19
    1262:	45 01 d1             	add    r9d,r10d
    1265:	45 01 da             	add    r10d,r11d
    1268:	45 01 fa             	add    r10d,r15d
    126b:	89 da                	mov    edx,ebx
    126d:	c1 e2 18             	shl    edx,0x18
    1270:	09 c2                	or     edx,eax
    1272:	44 01 f2             	add    edx,r14d
    1275:	44 31 d2             	xor    edx,r10d
    1278:	c4 43 7b f0 da 12    	rorx   r11d,r10d,0x12
    127e:	44 29 da             	sub    edx,r11d
    1281:	41 31 d1             	xor    r9d,edx
    1284:	c4 63 7b f0 da 15    	rorx   r11d,edx,0x15
    128a:	45 29 d9             	sub    r9d,r11d
    128d:	45 31 ca             	xor    r10d,r9d
    1290:	c4 43 7b f0 d9 07    	rorx   r11d,r9d,0x7
    1296:	45 29 da             	sub    r10d,r11d
    1299:	44 31 d2             	xor    edx,r10d
    129c:	c4 43 7b f0 da 10    	rorx   r11d,r10d,0x10
    12a2:	44 29 da             	sub    edx,r11d
    12a5:	41 31 d1             	xor    r9d,edx
    12a8:	c4 63 7b f0 da 1c    	rorx   r11d,edx,0x1c
    12ae:	45 29 d9             	sub    r9d,r11d
    12b1:	45 31 ca             	xor    r10d,r9d
    12b4:	c4 43 7b f0 c9 12    	rorx   r9d,r9d,0x12
    12ba:	45 29 ca             	sub    r10d,r9d
    12bd:	44 31 d2             	xor    edx,r10d
    12c0:	c4 43 7b f0 ca 08    	rorx   r9d,r10d,0x8
    12c6:	c1 e0 10             	shl    eax,0x10
    12c9:	c1 e6 08             	shl    esi,0x8
    12cc:	09 f3                	or     ebx,esi
    12ce:	31 fb                	xor    ebx,edi
    12d0:	88 19                	mov    BYTE PTR [rcx],bl
    12d2:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    12d5:	31 c6                	xor    esi,eax
    12d7:	c1 ee 10             	shr    esi,0x10
    12da:	40 88 71 02          	mov    BYTE PTR [rcx+0x2],sil
    12de:	44 88 41 03          	mov    BYTE PTR [rcx+0x3],r8b
    12e2:	44 29 ca             	sub    edx,r9d
    12e5:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
    12e8:	88 71 05             	mov    BYTE PTR [rcx+0x5],dh
    12eb:	89 d0                	mov    eax,edx
    12ed:	c1 e8 10             	shr    eax,0x10
    12f0:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
    12f3:	c1 ea 18             	shr    edx,0x18
    12f6:	88 51 07             	mov    BYTE PTR [rcx+0x7],dl
    12f9:	b8 02 00 00 00       	mov    eax,0x2
    12fe:	5b                   	pop    rbx
    12ff:	41 5e                	pop    r14
    1301:	41 5f                	pop    r15
    1303:	5d                   	pop    rbp
    1304:	c3                   	ret

Disassembly of section .fini:

0000000000001308 <_fini>:
    1308:	f3 0f 1e fa          	endbr64
    130c:	48 83 ec 08          	sub    rsp,0x8
    1310:	48 83 c4 08          	add    rsp,0x8
    1314:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
not captured
```

## llvmbpf JIT ASM
```asm
not captured
```
