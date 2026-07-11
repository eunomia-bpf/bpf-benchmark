# tracee_syscall_name_table_lookup

## Original C
```c
#include "common.h"

#define TRACEE_SYSCALL_LOOKUP_COUNT 64U
#define TRACEE_SYSCALL_LOOKUP_INPUT_SIZE (4U + TRACEE_SYSCALL_LOOKUP_COUNT * 4U)

static __always_inline u64 tracee_syscall_name_sig(u32 syscall_id)
{
    switch (syscall_id) {
    case 0U: return 0x0000000072656164ULL;
    case 1U: return 0x0000006574697277ULL;
    case 2U: return 0x000000006E65706FULL;
    case 3U: return 0x00000065736F6C63ULL;
    case 9U: return 0x0000000070616D6DULL;
    case 12U: return 0x000000006B72626BULL;
    case 39U: return 0x0000006469707467ULL;
    case 56U: return 0x0000656E6F6C6355ULL;
    case 57U: return 0x000000006B726F66ULL;
    case 59U: return 0x0000657663657865ULL;
    case 60U: return 0x0000000074697865ULL;
    case 61U: return 0x0000347469617755ULL;
    case 80U: return 0x0000000069646863ULL;
    case 87U: return 0x00006B6E696C6E75ULL;
    case 89U: return 0x0000006B6E696C55ULL;
    case 158U: return 0x006C74635F68637261ULL;
    case 202U: return 0x0000786574756655ULL;
    case 217U: return 0x0000646461746567ULL;
    case 257U: return 0x000074616E65706FULL;
    case 263U: return 0x0074616B6E696C6E75ULL;
    case 281U: return 0x0074613274617473ULL;
    case 291U: return 0x647466656E676973ULL;
    case 321U: return 0x0000000000706662ULL;
    case 332U: return 0x0000000078746173ULL;
    default: return 0ULL;
    }
}

static __always_inline int
bench_tracee_syscall_name_table_lookup(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TRACEE_SYSCALL_LOOKUP_INPUT_SIZE)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    if (count != TRACEE_SYSCALL_LOOKUP_COUNT) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 index = 0; index < TRACEE_SYSCALL_LOOKUP_COUNT; index++) {
        u32 syscall_id = micro_read_u32_le(data, 4U + index * 4U);
        u64 sig = tracee_syscall_name_sig(syscall_id);

        if (sig != 0U) {
            acc += micro_rotl64(sig ^ syscall_id, (index & 7U) + 1U);
            acc ^= (u64)(syscall_id & 0xFFU) << ((index & 7U) * 8U);
        } else {
            acc ^= (u64)syscall_id * 0x9E3779B185EBCA87ULL;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tracee_syscall_name_table_lookup_xdp,
    bench_tracee_syscall_name_table_lookup,
    tracee_syscall_name_table_lookup_input_value,
    TRACEE_SYSCALL_LOOKUP_INPUT_SIZE)
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

0000000000001100 <tracee_syscall_name_table_lookup_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <tracee_syscall_name_table_lookup_xdp+0xe>
    1118:	48 8d ba 0c 01 00 00 	lea    rdi,[rdx+0x10c]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <tracee_syscall_name_table_lookup_xdp+0xe>
    1124:	83 3e 40             	cmp    DWORD PTR [rsi],0x40
    1127:	75 e5                	jne    110e <tracee_syscall_name_table_lookup_xdp+0xe>
    1129:	55                   	push   rbp
    112a:	41 57                	push   r15
    112c:	41 56                	push   r14
    112e:	41 55                	push   r13
    1130:	41 54                	push   r12
    1132:	53                   	push   rbx
    1133:	49 bd 09 c9 bc f3 67 	movabs r13,0x6a09e667f3bcc909
    113a:	e6 09 6a 
    113d:	48 be 63 6c 6f 73 65 	movabs rsi,0x65736f6c63
    1144:	00 00 00 
    1147:	45 31 c0             	xor    r8d,r8d
    114a:	4c 8d 8e 14 06 fa 00 	lea    r9,[rsi+0xfa0614]
    1151:	49 bf 67 65 74 61 64 	movabs r15,0x646461746567
    1158:	64 00 00 
    115b:	49 bb 6f 70 65 6e 61 	movabs r11,0x74616e65706f
    1162:	74 00 00 
    1165:	48 bb 75 6e 6c 69 6e 	movabs rbx,0x74616b6e696c6e75
    116c:	6b 61 74 
    116f:	49 be 73 74 61 74 32 	movabs r14,0x74613274617473
    1176:	61 74 00 
    1179:	49 bc 73 69 67 6e 65 	movabs r12,0x647466656e676973
    1180:	66 74 64 
    1183:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    118a:	84 00 00 00 00 00 
    1190:	42 0f b6 7c 82 0c    	movzx  edi,BYTE PTR [rdx+r8*4+0xc]
    1196:	42 0f b6 4c 82 0d    	movzx  ecx,BYTE PTR [rdx+r8*4+0xd]
    119c:	c1 e1 08             	shl    ecx,0x8
    119f:	09 f9                	or     ecx,edi
    11a1:	42 0f b7 44 82 0e    	movzx  eax,WORD PTR [rdx+r8*4+0xe]
    11a7:	c1 e0 10             	shl    eax,0x10
    11aa:	09 c8                	or     eax,ecx
    11ac:	83 f8 4f             	cmp    eax,0x4f
    11af:	7f 3f                	jg     11f0 <tracee_syscall_name_table_lookup_xdp+0xf0>
    11b1:	83 f8 26             	cmp    eax,0x26
    11b4:	7f 7a                	jg     1230 <tracee_syscall_name_table_lookup_xdp+0x130>
    11b6:	83 f8 02             	cmp    eax,0x2
    11b9:	0f 8f d5 00 00 00    	jg     1294 <tracee_syscall_name_table_lookup_xdp+0x194>
    11bf:	85 c0                	test   eax,eax
    11c1:	0f 84 b1 01 00 00    	je     1378 <tracee_syscall_name_table_lookup_xdp+0x278>
    11c7:	83 f8 01             	cmp    eax,0x1
    11ca:	0f 84 62 01 00 00    	je     1332 <tracee_syscall_name_table_lookup_xdp+0x232>
    11d0:	83 f8 02             	cmp    eax,0x2
    11d3:	0f 85 25 02 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    11d9:	b9 6f 70 65 6e       	mov    ecx,0x6e65706f
    11de:	e9 dd 01 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    11e3:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11ea:	84 00 00 00 00 00 
    11f0:	3d 00 01 00 00       	cmp    eax,0x100
    11f5:	7f 69                	jg     1260 <tracee_syscall_name_table_lookup_xdp+0x160>
    11f7:	3d 9d 00 00 00       	cmp    eax,0x9d
    11fc:	0f 8f ba 00 00 00    	jg     12bc <tracee_syscall_name_table_lookup_xdp+0x1bc>
    1202:	83 f8 50             	cmp    eax,0x50
    1205:	0f 84 74 01 00 00    	je     137f <tracee_syscall_name_table_lookup_xdp+0x27f>
    120b:	83 f8 57             	cmp    eax,0x57
    120e:	0f 84 26 01 00 00    	je     133a <tracee_syscall_name_table_lookup_xdp+0x23a>
    1214:	83 f8 59             	cmp    eax,0x59
    1217:	0f 85 e1 01 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    121d:	48 b9 55 6c 69 6e 6b 	movabs rcx,0x6b6e696c55
    1224:	00 00 00 
    1227:	e9 94 01 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    122c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1230:	83 f8 3a             	cmp    eax,0x3a
    1233:	0f 8f ac 00 00 00    	jg     12e5 <tracee_syscall_name_table_lookup_xdp+0x1e5>
    1239:	83 f8 27             	cmp    eax,0x27
    123c:	0f 84 44 01 00 00    	je     1386 <tracee_syscall_name_table_lookup_xdp+0x286>
    1242:	83 f8 38             	cmp    eax,0x38
    1245:	0f 84 fb 00 00 00    	je     1346 <tracee_syscall_name_table_lookup_xdp+0x246>
    124b:	83 f8 39             	cmp    eax,0x39
    124e:	0f 85 aa 01 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    1254:	b9 66 6f 72 6b       	mov    ecx,0x6b726f66
    1259:	e9 62 01 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    125e:	66 90                	xchg   ax,ax
    1260:	3d 22 01 00 00       	cmp    eax,0x122
    1265:	0f 8f a0 00 00 00    	jg     130b <tracee_syscall_name_table_lookup_xdp+0x20b>
    126b:	3d 01 01 00 00       	cmp    eax,0x101
    1270:	0f 84 1c 01 00 00    	je     1392 <tracee_syscall_name_table_lookup_xdp+0x292>
    1276:	3d 07 01 00 00       	cmp    eax,0x107
    127b:	0f 84 d1 00 00 00    	je     1352 <tracee_syscall_name_table_lookup_xdp+0x252>
    1281:	3d 19 01 00 00       	cmp    eax,0x119
    1286:	0f 85 72 01 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    128c:	4c 89 f1             	mov    rcx,r14
    128f:	e9 2c 01 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1294:	48 89 f1             	mov    rcx,rsi
    1297:	83 f8 03             	cmp    eax,0x3
    129a:	0f 84 20 01 00 00    	je     13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    12a0:	83 f8 09             	cmp    eax,0x9
    12a3:	0f 84 ae 00 00 00    	je     1357 <tracee_syscall_name_table_lookup_xdp+0x257>
    12a9:	83 f8 0c             	cmp    eax,0xc
    12ac:	0f 85 4c 01 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    12b2:	b9 6b 62 72 6b       	mov    ecx,0x6b72626b
    12b7:	e9 04 01 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    12bc:	3d 9e 00 00 00       	cmp    eax,0x9e
    12c1:	0f 84 d0 00 00 00    	je     1397 <tracee_syscall_name_table_lookup_xdp+0x297>
    12c7:	3d ca 00 00 00       	cmp    eax,0xca
    12cc:	0f 84 8c 00 00 00    	je     135e <tracee_syscall_name_table_lookup_xdp+0x25e>
    12d2:	3d d9 00 00 00       	cmp    eax,0xd9
    12d7:	0f 85 21 01 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    12dd:	4c 89 f9             	mov    rcx,r15
    12e0:	e9 db 00 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    12e5:	83 f8 3b             	cmp    eax,0x3b
    12e8:	0f 84 b5 00 00 00    	je     13a3 <tracee_syscall_name_table_lookup_xdp+0x2a3>
    12ee:	83 f8 3c             	cmp    eax,0x3c
    12f1:	74 77                	je     136a <tracee_syscall_name_table_lookup_xdp+0x26a>
    12f3:	83 f8 3d             	cmp    eax,0x3d
    12f6:	0f 85 02 01 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    12fc:	48 b9 55 77 61 69 74 	movabs rcx,0x347469617755
    1303:	34 00 00 
    1306:	e9 b5 00 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    130b:	3d 23 01 00 00       	cmp    eax,0x123
    1310:	0f 84 99 00 00 00    	je     13af <tracee_syscall_name_table_lookup_xdp+0x2af>
    1316:	3d 41 01 00 00       	cmp    eax,0x141
    131b:	74 54                	je     1371 <tracee_syscall_name_table_lookup_xdp+0x271>
    131d:	3d 4c 01 00 00       	cmp    eax,0x14c
    1322:	0f 85 d6 00 00 00    	jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe>
    1328:	b9 73 61 74 78       	mov    ecx,0x78746173
    132d:	e9 8e 00 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1332:	4c 89 c9             	mov    rcx,r9
    1335:	e9 86 00 00 00       	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    133a:	48 b9 75 6e 6c 69 6e 	movabs rcx,0x6b6e696c6e75
    1341:	6b 00 00 
    1344:	eb 7a                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1346:	48 b9 55 63 6c 6f 6e 	movabs rcx,0x656e6f6c6355
    134d:	65 00 00 
    1350:	eb 6e                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1352:	48 89 d9             	mov    rcx,rbx
    1355:	eb 69                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1357:	b9 6d 6d 61 70       	mov    ecx,0x70616d6d
    135c:	eb 62                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    135e:	48 b9 55 66 75 74 65 	movabs rcx,0x786574756655
    1365:	78 00 00 
    1368:	eb 56                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    136a:	b9 65 78 69 74       	mov    ecx,0x74697865
    136f:	eb 4f                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1371:	b9 62 66 70 00       	mov    ecx,0x706662
    1376:	eb 48                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1378:	b9 64 61 65 72       	mov    ecx,0x72656164
    137d:	eb 41                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    137f:	b9 63 68 64 69       	mov    ecx,0x69646863
    1384:	eb 3a                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1386:	48 b9 67 74 70 69 64 	movabs rcx,0x6469707467
    138d:	00 00 00 
    1390:	eb 2e                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1392:	4c 89 d9             	mov    rcx,r11
    1395:	eb 29                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    1397:	48 b9 61 72 63 68 5f 	movabs rcx,0x6c74635f68637261
    139e:	63 74 6c 
    13a1:	eb 1d                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    13a3:	48 b9 65 78 65 63 76 	movabs rcx,0x657663657865
    13aa:	65 00 00 
    13ad:	eb 11                	jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0>
    13af:	4c 89 e1             	mov    rcx,r12
    13b2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    13b9:	1f 84 00 00 00 00 00 
    13c0:	89 c5                	mov    ebp,eax
    13c2:	48 31 cd             	xor    rbp,rcx
    13c5:	44 89 c0             	mov    eax,r8d
    13c8:	83 e0 07             	and    eax,0x7
    13cb:	8d 48 01             	lea    ecx,[rax+0x1]
    13ce:	49 89 ea             	mov    r10,rbp
    13d1:	49 d3 e2             	shl    r10,cl
    13d4:	89 c1                	mov    ecx,eax
    13d6:	f6 d1                	not    cl
    13d8:	48 d3 ed             	shr    rbp,cl
    13db:	c1 e0 03             	shl    eax,0x3
    13de:	89 c1                	mov    ecx,eax
    13e0:	48 d3 e7             	shl    rdi,cl
    13e3:	4c 09 d5             	or     rbp,r10
    13e6:	4c 01 ed             	add    rbp,r13
    13e9:	48 31 ef             	xor    rdi,rbp
    13ec:	49 89 fd             	mov    r13,rdi
    13ef:	49 ff c0             	inc    r8
    13f2:	49 83 f8 40          	cmp    r8,0x40
    13f6:	0f 85 94 fd ff ff    	jne    1190 <tracee_syscall_name_table_lookup_xdp+0x90>
    13fc:	eb 15                	jmp    1413 <tracee_syscall_name_table_lookup_xdp+0x313>
    13fe:	89 c0                	mov    eax,eax
    1400:	48 b9 87 ca eb 85 b1 	movabs rcx,0x9e3779b185ebca87
    1407:	79 37 9e 
    140a:	48 0f af c1          	imul   rax,rcx
    140e:	49 31 c5             	xor    r13,rax
    1411:	eb dc                	jmp    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef>
    1413:	4c 89 2a             	mov    QWORD PTR [rdx],r13
    1416:	b8 02 00 00 00       	mov    eax,0x2
    141b:	5b                   	pop    rbx
    141c:	41 5c                	pop    r12
    141e:	41 5d                	pop    r13
    1420:	41 5e                	pop    r14
    1422:	41 5f                	pop    r15
    1424:	5d                   	pop    rbp
    1425:	c3                   	ret

Disassembly of section .fini:

0000000000001428 <_fini>:
    1428:	f3 0f 1e fa          	endbr64
    142c:	48 83 ec 08          	sub    rsp,0x8
    1430:	48 83 c4 08          	add    rsp,0x8
    1434:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	53                   	push   rbx
   d:	41 55                	push   r13
   f:	41 56                	push   r14
  11:	41 57                	push   r15
  13:	31 c0                	xor    eax,eax
  15:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  19:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  1d:	48 39 f7             	cmp    rdi,rsi
  20:	0f 87 ca 03 00 00    	ja     0x3f0
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 ba 03 00 00    	ja     0x3f0
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 0c 01 00 00 	add    rdx,0x10c
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 a7 03 00 00    	ja     0x3f0
  49:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4e:	48 c1 e6 08          	shl    rsi,0x8
  52:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  57:	48 09 d6             	or     rsi,rdx
  5a:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  5f:	48 c1 e2 10          	shl    rdx,0x10
  63:	48 09 d6             	or     rsi,rdx
  66:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  6b:	48 c1 e2 18          	shl    rdx,0x18
  6f:	48 09 d6             	or     rsi,rdx
  72:	48 c1 e6 20          	shl    rsi,0x20
  76:	48 c1 ee 20          	shr    rsi,0x20
  7a:	48 83 fe 40          	cmp    rsi,0x40
  7e:	0f 85 6c 03 00 00    	jne    0x3f0
  84:	49 b8 09 c9 bc f3 67 	movabs r8,0x6a09e667f3bcc909
  8b:	e6 09 6a 
  8e:	31 f6                	xor    esi,esi
  90:	48 89 fa             	mov    rdx,rdi
  93:	48 83 c2 0f          	add    rdx,0xf
  97:	48 b9 87 ca eb 85 b1 	movabs rcx,0x9e3779b185ebca87
  9e:	79 37 9e 
  a1:	48 0f b6 5a fe       	movzx  rbx,BYTE PTR [rdx-0x2]
  a6:	48 c1 e3 08          	shl    rbx,0x8
  aa:	48 0f b6 42 fd       	movzx  rax,BYTE PTR [rdx-0x3]
  af:	48 09 c3             	or     rbx,rax
  b2:	4c 0f b6 6a ff       	movzx  r13,BYTE PTR [rdx-0x1]
  b7:	49 c1 e5 10          	shl    r13,0x10
  bb:	4c 09 eb             	or     rbx,r13
  be:	4c 0f b6 6a 00       	movzx  r13,BYTE PTR [rdx+0x0]
  c3:	49 c1 e5 18          	shl    r13,0x18
  c7:	4c 09 eb             	or     rbx,r13
  ca:	49 89 de             	mov    r14,rbx
  cd:	49 c1 e6 20          	shl    r14,0x20
  d1:	49 c1 ee 20          	shr    r14,0x20
  d5:	49 83 fe 4f          	cmp    r14,0x4f
  d9:	7f 34                	jg     0x10f
  db:	49 83 fe 26          	cmp    r14,0x26
  df:	7f 72                	jg     0x153
  e1:	49 83 fe 02          	cmp    r14,0x2
  e5:	0f 8f e0 00 00 00    	jg     0x1cb
  eb:	41 bd 64 61 65 72    	mov    r13d,0x72656164
  f1:	4d 85 f6             	test   r14,r14
  f4:	0f 84 3a 02 00 00    	je     0x334
  fa:	49 83 fe 01          	cmp    r14,0x1
  fe:	0f 84 85 01 00 00    	je     0x289
 104:	41 bd 6f 70 65 6e    	mov    r13d,0x6e65706f
 10a:	e9 25 02 00 00       	jmp    0x334
 10f:	49 81 fe 00 01 00 00 	cmp    r14,0x100
 116:	7f 6f                	jg     0x187
 118:	49 81 fe 9d 00 00 00 	cmp    r14,0x9d
 11f:	0f 8f d0 00 00 00    	jg     0x1f5
 125:	49 83 fe 50          	cmp    r14,0x50
 129:	0f 84 b7 01 00 00    	je     0x2e6
 12f:	49 83 fe 57          	cmp    r14,0x57
 133:	0f 84 5f 01 00 00    	je     0x298
 139:	49 83 fe 59          	cmp    r14,0x59
 13d:	74 05                	je     0x144
 13f:	e9 45 02 00 00       	jmp    0x389
 144:	49 bd 55 6c 69 6e 6b 	movabs r13,0x6b6e696c55
 14b:	00 00 00 
 14e:	e9 e1 01 00 00       	jmp    0x334
 153:	49 83 fe 3a          	cmp    r14,0x3a
 157:	0f 8f cf 00 00 00    	jg     0x22c
 15d:	49 83 fe 27          	cmp    r14,0x27
 161:	0f 84 87 01 00 00    	je     0x2ee
 167:	49 83 fe 38          	cmp    r14,0x38
 16b:	0f 84 36 01 00 00    	je     0x2a7
 171:	49 83 fe 39          	cmp    r14,0x39
 175:	74 05                	je     0x17c
 177:	e9 0d 02 00 00       	jmp    0x389
 17c:	41 bd 66 6f 72 6b    	mov    r13d,0x6b726f66
 182:	e9 ad 01 00 00       	jmp    0x334
 187:	49 81 fe 22 01 00 00 	cmp    r14,0x122
 18e:	0f 8f c6 00 00 00    	jg     0x25a
 194:	49 81 fe 01 01 00 00 	cmp    r14,0x101
 19b:	0f 84 59 01 00 00    	je     0x2fa
 1a1:	49 81 fe 07 01 00 00 	cmp    r14,0x107
 1a8:	0f 84 08 01 00 00    	je     0x2b6
 1ae:	49 81 fe 19 01 00 00 	cmp    r14,0x119
 1b5:	74 05                	je     0x1bc
 1b7:	e9 cd 01 00 00       	jmp    0x389
 1bc:	49 bd 73 74 61 74 32 	movabs r13,0x74613274617473
 1c3:	61 74 00 
 1c6:	e9 69 01 00 00       	jmp    0x334
 1cb:	49 83 fe 03          	cmp    r14,0x3
 1cf:	0f 84 31 01 00 00    	je     0x306
 1d5:	49 83 fe 09          	cmp    r14,0x9
 1d9:	0f 84 e3 00 00 00    	je     0x2c2
 1df:	49 83 fe 0c          	cmp    r14,0xc
 1e3:	74 05                	je     0x1ea
 1e5:	e9 9f 01 00 00       	jmp    0x389
 1ea:	41 bd 6b 62 72 6b    	mov    r13d,0x6b72626b
 1f0:	e9 3f 01 00 00       	jmp    0x334
 1f5:	49 81 fe 9e 00 00 00 	cmp    r14,0x9e
 1fc:	0f 84 10 01 00 00    	je     0x312
 202:	49 81 fe ca 00 00 00 	cmp    r14,0xca
 209:	0f 84 bb 00 00 00    	je     0x2ca
 20f:	49 81 fe d9 00 00 00 	cmp    r14,0xd9
 216:	74 05                	je     0x21d
 218:	e9 6c 01 00 00       	jmp    0x389
 21d:	49 bd 67 65 74 61 64 	movabs r13,0x646461746567
 224:	64 00 00 
 227:	e9 08 01 00 00       	jmp    0x334
 22c:	49 83 fe 3b          	cmp    r14,0x3b
 230:	0f 84 e8 00 00 00    	je     0x31e
 236:	49 83 fe 3c          	cmp    r14,0x3c
 23a:	0f 84 96 00 00 00    	je     0x2d6
 240:	49 83 fe 3d          	cmp    r14,0x3d
 244:	74 05                	je     0x24b
 246:	e9 3e 01 00 00       	jmp    0x389
 24b:	49 bd 55 77 61 69 74 	movabs r13,0x347469617755
 252:	34 00 00 
 255:	e9 da 00 00 00       	jmp    0x334
 25a:	49 81 fe 23 01 00 00 	cmp    r14,0x123
 261:	0f 84 c3 00 00 00    	je     0x32a
 267:	49 81 fe 41 01 00 00 	cmp    r14,0x141
 26e:	74 6e                	je     0x2de
 270:	49 81 fe 4c 01 00 00 	cmp    r14,0x14c
 277:	74 05                	je     0x27e
 279:	e9 0b 01 00 00       	jmp    0x389
 27e:	41 bd 73 61 74 78    	mov    r13d,0x78746173
 284:	e9 ab 00 00 00       	jmp    0x334
 289:	49 bd 77 72 69 74 65 	movabs r13,0x6574697277
 290:	00 00 00 
 293:	e9 9c 00 00 00       	jmp    0x334
 298:	49 bd 75 6e 6c 69 6e 	movabs r13,0x6b6e696c6e75
 29f:	6b 00 00 
 2a2:	e9 8d 00 00 00       	jmp    0x334
 2a7:	49 bd 55 63 6c 6f 6e 	movabs r13,0x656e6f6c6355
 2ae:	65 00 00 
 2b1:	e9 7e 00 00 00       	jmp    0x334
 2b6:	49 bd 75 6e 6c 69 6e 	movabs r13,0x74616b6e696c6e75
 2bd:	6b 61 74 
 2c0:	eb 72                	jmp    0x334
 2c2:	41 bd 6d 6d 61 70    	mov    r13d,0x70616d6d
 2c8:	eb 6a                	jmp    0x334
 2ca:	49 bd 55 66 75 74 65 	movabs r13,0x786574756655
 2d1:	78 00 00 
 2d4:	eb 5e                	jmp    0x334
 2d6:	41 bd 65 78 69 74    	mov    r13d,0x74697865
 2dc:	eb 56                	jmp    0x334
 2de:	41 bd 62 66 70 00    	mov    r13d,0x706662
 2e4:	eb 4e                	jmp    0x334
 2e6:	41 bd 63 68 64 69    	mov    r13d,0x69646863
 2ec:	eb 46                	jmp    0x334
 2ee:	49 bd 67 74 70 69 64 	movabs r13,0x6469707467
 2f5:	00 00 00 
 2f8:	eb 3a                	jmp    0x334
 2fa:	49 bd 6f 70 65 6e 61 	movabs r13,0x74616e65706f
 301:	74 00 00 
 304:	eb 2e                	jmp    0x334
 306:	49 bd 63 6c 6f 73 65 	movabs r13,0x65736f6c63
 30d:	00 00 00 
 310:	eb 22                	jmp    0x334
 312:	49 bd 61 72 63 68 5f 	movabs r13,0x6c74635f68637261
 319:	63 74 6c 
 31c:	eb 16                	jmp    0x334
 31e:	49 bd 65 78 65 63 76 	movabs r13,0x657663657865
 325:	65 00 00 
 328:	eb 0a                	jmp    0x334
 32a:	49 bd 73 69 67 6e 65 	movabs r13,0x647466656e676973
 331:	66 74 64 
 334:	48 c1 e3 20          	shl    rbx,0x20
 338:	48 c1 eb 20          	shr    rbx,0x20
 33c:	49 31 dd             	xor    r13,rbx
 33f:	48 89 f3             	mov    rbx,rsi
 342:	48 83 e3 07          	and    rbx,0x7
 346:	49 89 de             	mov    r14,rbx
 349:	49 83 f6 3f          	xor    r14,0x3f
 34d:	4d 89 ef             	mov    r15,r13
 350:	c4 42 8b f7 ff       	shrx   r15,r15,r14
 355:	49 89 de             	mov    r14,rbx
 358:	49 83 c6 01          	add    r14,0x1
 35c:	c4 42 89 f7 ed       	shlx   r13,r13,r14
 361:	4d 09 fd             	or     r13,r15
 364:	4d 01 c5             	add    r13,r8
 367:	48 c1 e3 03          	shl    rbx,0x3
 36b:	c4 e2 e1 f7 c0       	shlx   rax,rax,rbx
 370:	49 31 c5             	xor    r13,rax
 373:	48 83 c2 04          	add    rdx,0x4
 377:	48 83 c6 01          	add    rsi,0x1
 37b:	4d 89 e8             	mov    r8,r13
 37e:	48 83 fe 40          	cmp    rsi,0x40
 382:	74 19                	je     0x39d
 384:	e9 18 fd ff ff       	jmp    0xa1
 389:	48 c1 e3 20          	shl    rbx,0x20
 38d:	48 c1 eb 20          	shr    rbx,0x20
 391:	48 0f af d9          	imul   rbx,rcx
 395:	4c 31 c3             	xor    rbx,r8
 398:	49 89 dd             	mov    r13,rbx
 39b:	eb d6                	jmp    0x373
 39d:	4c 89 ee             	mov    rsi,r13
 3a0:	48 c1 ee 38          	shr    rsi,0x38
 3a4:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 3a8:	4c 89 ee             	mov    rsi,r13
 3ab:	48 c1 ee 30          	shr    rsi,0x30
 3af:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 3b3:	4c 89 ee             	mov    rsi,r13
 3b6:	48 c1 ee 28          	shr    rsi,0x28
 3ba:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 3be:	4c 89 ee             	mov    rsi,r13
 3c1:	48 c1 ee 20          	shr    rsi,0x20
 3c5:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 3c9:	4c 89 ee             	mov    rsi,r13
 3cc:	48 c1 ee 18          	shr    rsi,0x18
 3d0:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 3d4:	4c 89 ee             	mov    rsi,r13
 3d7:	48 c1 ee 10          	shr    rsi,0x10
 3db:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 3df:	44 88 6f 00          	mov    BYTE PTR [rdi+0x0],r13b
 3e3:	49 c1 ed 08          	shr    r13,0x8
 3e7:	44 88 6f 01          	mov    BYTE PTR [rdi+0x1],r13b
 3eb:	b8 02 00 00 00       	mov    eax,0x2
 3f0:	41 5f                	pop    r15
 3f2:	41 5e                	pop    r14
 3f4:	41 5d                	pop    r13
 3f6:	5b                   	pop    rbx
 3f7:	c9                   	leave
 3f8:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   6:	8b 57 04             	mov    edx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 d1                	cmp    ecx,edx
   d:	0f 87 8d 03 00 00    	ja     0x3a0
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 80 03 00 00    	ja     0x3a0
  20:	48 8d b1 0c 01 00 00 	lea    rsi,[rcx+0x10c]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 70 03 00 00    	ja     0x3a0
  30:	83 79 08 40          	cmp    DWORD PTR [rcx+0x8],0x40
  34:	0f 85 51 03 00 00    	jne    0x38b
  3a:	55                   	push   rbp
  3b:	41 57                	push   r15
  3d:	41 56                	push   r14
  3f:	41 55                	push   r13
  41:	41 54                	push   r12
  43:	53                   	push   rbx
  44:	49 be 63 6c 6f 73 65 	movabs r14,0x65736f6c63
  4b:	00 00 00 
  4e:	48 8d 51 0f          	lea    rdx,[rcx+0xf]
  52:	49 b9 09 c9 bc f3 67 	movabs r9,0x6a09e667f3bcc909
  59:	e6 09 6a 
  5c:	31 f6                	xor    esi,esi
  5e:	49 bc 55 6c 69 6e 6b 	movabs r12,0x6b6e696c55
  65:	00 00 00 
  68:	48 bd 87 ca eb 85 b1 	movabs rbp,0x9e3779b185ebca87
  6f:	79 37 9e 
  72:	48 bf 55 77 61 69 74 	movabs rdi,0x347469617755
  79:	34 00 00 
  7c:	41 bf 6f 70 65 6e    	mov    r15d,0x6e65706f
  82:	41 bd 64 61 65 72    	mov    r13d,0x72656164
  88:	eb 57                	jmp    0xe1
  8a:	49 8d 86 14 06 fa 00 	lea    rax,[r14+0xfa0614]
  91:	49 83 fb 01          	cmp    r11,0x1
  95:	49 0f 45 c7          	cmovne rax,r15
  99:	4d 85 db             	test   r11,r11
  9c:	49 0f 44 c5          	cmove  rax,r13
  a0:	4c 31 d8             	xor    rax,r11
  a3:	41 89 f0             	mov    r8d,esi
  a6:	41 83 e0 07          	and    r8d,0x7
  aa:	45 89 c3             	mov    r11d,r8d
  ad:	41 f6 d3             	not    r11b
  b0:	c4 62 a3 f7 d8       	shrx   r11,rax,r11
  b5:	41 8d 58 01          	lea    ebx,[r8+0x1]
  b9:	c4 e2 e1 f7 c0       	shlx   rax,rax,rbx
  be:	4c 09 d8             	or     rax,r11
  c1:	4c 01 c8             	add    rax,r9
  c4:	41 c1 e0 03          	shl    r8d,0x3
  c8:	c4 42 b9 f7 ca       	shlx   r9,r10,r8
  cd:	49 31 c1             	xor    r9,rax
  d0:	48 83 c2 04          	add    rdx,0x4
  d4:	48 ff c6             	inc    rsi
  d7:	48 83 fe 40          	cmp    rsi,0x40
  db:	0f 84 ad 02 00 00    	je     0x38e
  e1:	0f b6 42 fe          	movzx  eax,BYTE PTR [rdx-0x2]
  e5:	c1 e0 08             	shl    eax,0x8
  e8:	44 0f b6 52 fd       	movzx  r10d,BYTE PTR [rdx-0x3]
  ed:	44 0f b6 42 ff       	movzx  r8d,BYTE PTR [rdx-0x1]
  f2:	41 c1 e0 10          	shl    r8d,0x10
  f6:	41 09 c0             	or     r8d,eax
  f9:	44 0f b6 1a          	movzx  r11d,BYTE PTR [rdx]
  fd:	41 c1 e3 18          	shl    r11d,0x18
 101:	45 09 c3             	or     r11d,r8d
 104:	4d 09 d3             	or     r11,r10
 107:	49 83 fb 4f          	cmp    r11,0x4f
 10b:	76 53                	jbe    0x160
 10d:	41 81 fb 00 01 00 00 	cmp    r11d,0x100
 114:	0f 86 96 00 00 00    	jbe    0x1b0
 11a:	41 81 fb 22 01 00 00 	cmp    r11d,0x122
 121:	0f 86 1c 01 00 00    	jbe    0x243
 127:	49 81 fb 23 01 00 00 	cmp    r11,0x123
 12e:	0f 84 02 02 00 00    	je     0x336
 134:	41 81 fb 41 01 00 00 	cmp    r11d,0x141
 13b:	0f 84 9b 01 00 00    	je     0x2dc
 141:	b8 73 61 74 78       	mov    eax,0x78746173
 146:	41 81 fb 4c 01 00 00 	cmp    r11d,0x14c
 14d:	0f 84 4d ff ff ff    	je     0xa0
 153:	e9 78 01 00 00       	jmp    0x2d0
 158:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
 15f:	00 
 160:	41 83 fb 26          	cmp    r11d,0x26
 164:	0f 86 96 00 00 00    	jbe    0x200
 16a:	44 89 d0             	mov    eax,r10d
 16d:	41 83 fb 3a          	cmp    r11d,0x3a
 171:	0f 86 09 01 00 00    	jbe    0x280
 177:	24 7f                	and    al,0x7f
 179:	3c 3b                	cmp    al,0x3b
 17b:	0f 84 c4 01 00 00    	je     0x345
 181:	45 89 d0             	mov    r8d,r10d
 184:	41 83 e0 7f          	and    r8d,0x7f
 188:	41 83 f8 3c          	cmp    r8d,0x3c
 18c:	0f 84 54 01 00 00    	je     0x2e6
 192:	48 89 f8             	mov    rax,rdi
 195:	41 83 f8 3d          	cmp    r8d,0x3d
 199:	0f 84 01 ff ff ff    	je     0xa0
 19f:	e9 2c 01 00 00       	jmp    0x2d0
 1a4:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 1ab:	00 00 00 00 00 
 1b0:	41 81 fb 9d 00 00 00 	cmp    r11d,0x9d
 1b7:	0f 86 ef 00 00 00    	jbe    0x2ac
 1bd:	45 89 d8             	mov    r8d,r11d
 1c0:	41 81 e0 ff 01 00 00 	and    r8d,0x1ff
 1c7:	41 81 f8 9e 00 00 00 	cmp    r8d,0x9e
 1ce:	0f 84 80 01 00 00    	je     0x354
 1d4:	41 81 f8 ca 00 00 00 	cmp    r8d,0xca
 1db:	0f 84 0f 01 00 00    	je     0x2f0
 1e1:	48 b8 67 65 74 61 64 	movabs rax,0x646461746567
 1e8:	64 00 00 
 1eb:	41 81 f8 d9 00 00 00 	cmp    r8d,0xd9
 1f2:	0f 84 a8 fe ff ff    	je     0xa0
 1f8:	e9 d3 00 00 00       	jmp    0x2d0
 1fd:	0f 1f 00             	nop    DWORD PTR [rax]
 200:	41 83 fb 02          	cmp    r11d,0x2
 204:	0f 86 80 fe ff ff    	jbe    0x8a
 20a:	45 89 d0             	mov    r8d,r10d
 20d:	41 80 e0 3f          	and    r8b,0x3f
 211:	4c 89 f0             	mov    rax,r14
 214:	41 80 f8 03          	cmp    r8b,0x3
 218:	0f 84 82 fe ff ff    	je     0xa0
 21e:	45 89 d0             	mov    r8d,r10d
 221:	41 83 e0 3f          	and    r8d,0x3f
 225:	41 83 f8 09          	cmp    r8d,0x9
 229:	0f 84 d0 00 00 00    	je     0x2ff
 22f:	b8 6b 62 72 6b       	mov    eax,0x6b72626b
 234:	41 83 f8 0c          	cmp    r8d,0xc
 238:	0f 84 62 fe ff ff    	je     0xa0
 23e:	e9 8d 00 00 00       	jmp    0x2d0
 243:	45 89 d8             	mov    r8d,r11d
 246:	41 81 e0 ff 01 00 00 	and    r8d,0x1ff
 24d:	41 81 f8 01 01 00 00 	cmp    r8d,0x101
 254:	0f 84 09 01 00 00    	je     0x363
 25a:	41 81 f8 07 01 00 00 	cmp    r8d,0x107
 261:	0f 84 a2 00 00 00    	je     0x309
 267:	48 b8 73 74 61 74 32 	movabs rax,0x74613274617473
 26e:	61 74 00 
 271:	41 81 f8 19 01 00 00 	cmp    r8d,0x119
 278:	0f 84 22 fe ff ff    	je     0xa0
 27e:	eb 50                	jmp    0x2d0
 280:	24 3f                	and    al,0x3f
 282:	3c 27                	cmp    al,0x27
 284:	0f 84 e8 00 00 00    	je     0x372
 28a:	45 89 d0             	mov    r8d,r10d
 28d:	41 83 e0 3f          	and    r8d,0x3f
 291:	41 83 f8 38          	cmp    r8d,0x38
 295:	0f 84 7d 00 00 00    	je     0x318
 29b:	b8 66 6f 72 6b       	mov    eax,0x6b726f66
 2a0:	41 83 f8 39          	cmp    r8d,0x39
 2a4:	0f 84 f6 fd ff ff    	je     0xa0
 2aa:	eb 24                	jmp    0x2d0
 2ac:	49 83 fa 50          	cmp    r10,0x50
 2b0:	0f 84 cb 00 00 00    	je     0x381
 2b6:	41 83 fa 57          	cmp    r10d,0x57
 2ba:	74 6b                	je     0x327
 2bc:	4c 89 e0             	mov    rax,r12
 2bf:	41 83 fa 59          	cmp    r10d,0x59
 2c3:	0f 84 d7 fd ff ff    	je     0xa0
 2c9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
 2d0:	4c 0f af dd          	imul   r11,rbp
 2d4:	4d 31 d9             	xor    r9,r11
 2d7:	e9 f4 fd ff ff       	jmp    0xd0
 2dc:	b8 62 66 70 00       	mov    eax,0x706662
 2e1:	e9 ba fd ff ff       	jmp    0xa0
 2e6:	b8 65 78 69 74       	mov    eax,0x74697865
 2eb:	e9 b0 fd ff ff       	jmp    0xa0
 2f0:	48 b8 55 66 75 74 65 	movabs rax,0x786574756655
 2f7:	78 00 00 
 2fa:	e9 a1 fd ff ff       	jmp    0xa0
 2ff:	b8 6d 6d 61 70       	mov    eax,0x70616d6d
 304:	e9 97 fd ff ff       	jmp    0xa0
 309:	48 b8 75 6e 6c 69 6e 	movabs rax,0x74616b6e696c6e75
 310:	6b 61 74 
 313:	e9 88 fd ff ff       	jmp    0xa0
 318:	48 b8 55 63 6c 6f 6e 	movabs rax,0x656e6f6c6355
 31f:	65 00 00 
 322:	e9 79 fd ff ff       	jmp    0xa0
 327:	48 b8 75 6e 6c 69 6e 	movabs rax,0x6b6e696c6e75
 32e:	6b 00 00 
 331:	e9 6a fd ff ff       	jmp    0xa0
 336:	48 b8 73 69 67 6e 65 	movabs rax,0x647466656e676973
 33d:	66 74 64 
 340:	e9 5b fd ff ff       	jmp    0xa0
 345:	48 b8 65 78 65 63 76 	movabs rax,0x657663657865
 34c:	65 00 00 
 34f:	e9 4c fd ff ff       	jmp    0xa0
 354:	48 b8 61 72 63 68 5f 	movabs rax,0x6c74635f68637261
 35b:	63 74 6c 
 35e:	e9 3d fd ff ff       	jmp    0xa0
 363:	48 b8 6f 70 65 6e 61 	movabs rax,0x74616e65706f
 36a:	74 00 00 
 36d:	e9 2e fd ff ff       	jmp    0xa0
 372:	48 b8 67 74 70 69 64 	movabs rax,0x6469707467
 379:	00 00 00 
 37c:	e9 1f fd ff ff       	jmp    0xa0
 381:	b8 63 68 64 69       	mov    eax,0x69646863
 386:	e9 15 fd ff ff       	jmp    0xa0
 38b:	31 c0                	xor    eax,eax
 38d:	c3                   	ret
 38e:	4c 89 09             	mov    QWORD PTR [rcx],r9
 391:	b8 02 00 00 00       	mov    eax,0x2
 396:	5b                   	pop    rbx
 397:	41 5c                	pop    r12
 399:	41 5d                	pop    r13
 39b:	41 5e                	pop    r14
 39d:	41 5f                	pop    r15
 39f:	5d                   	pop    rbp
 3a0:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_3, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_4, (-3) - 1, 0),
    /* 0x1118: lea    rdi,[rdx+0x10c] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 268), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_4, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x40 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 64),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x1129: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112a: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112c: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112e: push   r13 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1130: push   r12 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: movabs r13,0x6a09e667f3bcc909 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_7, 0, 0x6a09e667f3bcc909ULL),
    /* 0x113d: movabs rsi,0x65736f6c63 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x65736f6c63ULL),
    /* 0x1147: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114a: lea    r9,[rsi+0xfa0614] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_2, 0, 0, 1, 0, 16385556), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1151: movabs r15,0x646461746567 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_9, 0, 0x646461746567ULL),
    /* 0x115b: movabs r11,0x74616e65706f [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74616e65706fULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -424),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1165: movabs rbx,0x74616b6e696c6e75 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x74616b6e696c6e75ULL),
    /* 0x116f: movabs r14,0x74613274617473 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x74613274617473ULL),
    /* 0x1179: movabs r12,0x647466656e676973 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x647466656e676973ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1183: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1190: movzx  edi,BYTE PTR [rdx+r8*4+0xc] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_3, BPF_REG_5, 2, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1196: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_5, 2, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x119c: shl    ecx,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x119f: or     ecx,edi [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11a1: movzx  eax,WORD PTR [rdx+r8*4+0xe] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_SIB_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_5, 2, 14), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a7: shl    eax,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11aa: or     eax,ecx [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11ac: cmp    eax,0x4f [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11af: jg     11f0 <tracee_syscall_name_table_lookup_xdp+0xf0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (10) - 1, 79),
    /* 0x11b1: cmp    eax,0x26 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11b4: jg     1230 <tracee_syscall_name_table_lookup_xdp+0x130> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (17) - 1, 38),
    /* 0x11b6: cmp    eax,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11b9: jg     1294 <tracee_syscall_name_table_lookup_xdp+0x194> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (30) - 1, 2),
    /* 0x11bf: test   eax,eax [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x11c1: je     1378 <tracee_syscall_name_table_lookup_xdp+0x278> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_0, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (78) - 1),
    /* 0x11c7: cmp    eax,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11ca: je     1332 <tracee_syscall_name_table_lookup_xdp+0x232> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (53) - 1, 1),
    /* 0x11d0: cmp    eax,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11d3: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (134) - 1, 2),
    /* 0x11d9: mov    ecx,0x6e65706f [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1852141679), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11de: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (93) - 1),
    /* 0x11e3: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: cmp    eax,0x100 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11f5: jg     1260 <tracee_syscall_name_table_lookup_xdp+0x160> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (15) - 1, 256),
    /* 0x11f7: cmp    eax,0x9d [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11fc: jg     12bc <tracee_syscall_name_table_lookup_xdp+0x1bc> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (29) - 1, 157),
    /* 0x1202: cmp    eax,0x50 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1205: je     137f <tracee_syscall_name_table_lookup_xdp+0x27f> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (73) - 1, 80),
    /* 0x120b: cmp    eax,0x57 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x120e: je     133a <tracee_syscall_name_table_lookup_xdp+0x23a> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (48) - 1, 87),
    /* 0x1214: cmp    eax,0x59 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1217: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (126) - 1, 89),
    /* 0x121d: movabs rcx,0x6b6e696c55 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c55ULL),
    /* 0x1227: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (85) - 1),
    /* 0x122c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1230: cmp    eax,0x3a [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1233: jg     12e5 <tracee_syscall_name_table_lookup_xdp+0x1e5> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (28) - 1, 58),
    /* 0x1239: cmp    eax,0x27 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x123c: je     1386 <tracee_syscall_name_table_lookup_xdp+0x286> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (69) - 1, 39),
    /* 0x1242: cmp    eax,0x38 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1245: je     1346 <tracee_syscall_name_table_lookup_xdp+0x246> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (44) - 1, 56),
    /* 0x124b: cmp    eax,0x39 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x124e: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (119) - 1, 57),
    /* 0x1254: mov    ecx,0x6b726f66 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802661734), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1259: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (78) - 1),
    /* 0x125e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1260: cmp    eax,0x122 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1265: jg     130b <tracee_syscall_name_table_lookup_xdp+0x20b> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (27) - 1, 290),
    /* 0x126b: cmp    eax,0x101 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1270: je     1392 <tracee_syscall_name_table_lookup_xdp+0x292> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (65) - 1, 257),
    /* 0x1276: cmp    eax,0x107 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x127b: je     1352 <tracee_syscall_name_table_lookup_xdp+0x252> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (40) - 1, 263),
    /* 0x1281: cmp    eax,0x119 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1286: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (112) - 1, 281),
    /* 0x128c: mov    rcx,r14 [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x128f: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (71) - 1),
    /* 0x1294: mov    rcx,rsi [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1297: cmp    eax,0x3 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x129a: je     13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (68) - 1, 3),
    /* 0x12a0: cmp    eax,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12a3: je     1357 <tracee_syscall_name_table_lookup_xdp+0x257> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (35) - 1, 9),
    /* 0x12a9: cmp    eax,0xc [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12ac: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (104) - 1, 12),
    /* 0x12b2: mov    ecx,0x6b72626b [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1802658411), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b7: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (63) - 1),
    /* 0x12bc: cmp    eax,0x9e [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12c1: je     1397 <tracee_syscall_name_table_lookup_xdp+0x297> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (54) - 1, 158),
    /* 0x12c7: cmp    eax,0xca [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12cc: je     135e <tracee_syscall_name_table_lookup_xdp+0x25e> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (32) - 1, 202),
    /* 0x12d2: cmp    eax,0xd9 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12d7: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (98) - 1, 217),
    /* 0x12dd: mov    rcx,r15 [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12e0: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (57) - 1),
    /* 0x12e5: cmp    eax,0x3b [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12e8: je     13a3 <tracee_syscall_name_table_lookup_xdp+0x2a3> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (51) - 1, 59),
    /* 0x12ee: cmp    eax,0x3c [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12f1: je     136a <tracee_syscall_name_table_lookup_xdp+0x26a> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (29) - 1, 60),
    /* 0x12f3: cmp    eax,0x3d [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12f6: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (92) - 1, 61),
    /* 0x12fc: movabs rcx,0x347469617755 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x347469617755ULL),
    /* 0x1306: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (51) - 1),
    /* 0x130b: cmp    eax,0x123 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1310: je     13af <tracee_syscall_name_table_lookup_xdp+0x2af> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (48) - 1, 291),
    /* 0x1316: cmp    eax,0x141 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x131b: je     1371 <tracee_syscall_name_table_lookup_xdp+0x271> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (26) - 1, 321),
    /* 0x131d: cmp    eax,0x14c [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1322: jne    13fe <tracee_syscall_name_table_lookup_xdp+0x2fe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (86) - 1, 332),
    /* 0x1328: mov    ecx,0x78746173 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 2020893043), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x132d: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (45) - 1),
    /* 0x1332: mov    rcx,r9 [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1335: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (42) - 1),
    /* 0x133a: movabs rcx,0x6b6e696c6e75 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c6e75ULL),
    /* 0x1344: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (39) - 1),
    /* 0x1346: movabs rcx,0x656e6f6c6355 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x656e6f6c6355ULL),
    /* 0x1350: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (36) - 1),
    /* 0x1352: mov    rcx,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1355: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (33) - 1),
    /* 0x1357: mov    ecx,0x70616d6d [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1885433197), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x135c: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (30) - 1),
    /* 0x135e: movabs rcx,0x786574756655 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x786574756655ULL),
    /* 0x1368: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (27) - 1),
    /* 0x136a: mov    ecx,0x74697865 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1953069157), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x136f: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (24) - 1),
    /* 0x1371: mov    ecx,0x706662 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 7366242), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1376: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (21) - 1),
    /* 0x1378: mov    ecx,0x72656164 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1919246692), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x137d: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (18) - 1),
    /* 0x137f: mov    ecx,0x69646863 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_4, 1768188003), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1384: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (15) - 1),
    /* 0x1386: movabs rcx,0x6469707467 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6469707467ULL),
    /* 0x1390: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (12) - 1),
    /* 0x1392: mov    rcx,r11 [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1395: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (9) - 1),
    /* 0x1397: movabs rcx,0x6c74635f68637261 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6c74635f68637261ULL),
    /* 0x13a1: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (6) - 1),
    /* 0x13a3: movabs rcx,0x657663657865 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x657663657865ULL),
    /* 0x13ad: jmp    13c0 <tracee_syscall_name_table_lookup_xdp+0x2c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (3) - 1),
    /* 0x13af: mov    rcx,r12 [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13b2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x13c0: mov    ebp,eax [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c2: xor    rbp,rcx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13c5: mov    eax,r8d [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c8: and    eax,0x7 [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x13cb: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13ce: mov    r10,rbp [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13d1: shl    r10,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13d4: mov    ecx,eax [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13d6: not    cl [exact-kop: notb reg kop] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13d8: shr    rbp,cl [exact-kop: shr64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13db: shl    eax,0x3 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 3), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x13de: mov    ecx,eax [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e0: shl    rdi,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13e3: or     rbp,r10 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13e6: add    rbp,r13 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBP, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e9: xor    rdi,rbp [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_1, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13ec: mov    r13,rdi [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_7, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ef: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x13f2: cmp    r8,0x40 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x13f6: jne    1190 <tracee_syscall_name_table_lookup_xdp+0x90> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, (-152) - 1, 64),
    /* 0x13fc: jmp    1413 <tracee_syscall_name_table_lookup_xdp+0x313> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (10) - 1),
    /* 0x13fe: mov    eax,eax [exact-kop: movl register-to-register kop] */
    HC_KOP(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1400: movabs rcx,0x9e3779b185ebca87 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x9e3779b185ebca87ULL),
    /* 0x140a: imul   rax,rcx [exact-kop: imulq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x140e: xor    r13,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1411: jmp    13ef <tracee_syscall_name_table_lookup_xdp+0x2ef> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-12) - 1),
    /* 0x1413: mov    QWORD PTR [rdx],r13 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_STORE_PAYLOAD(BPF_REG_7, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1416: mov    eax,0x2 [exact-kop: movl immediate kop] */
    HC_KOP(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x141b: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141c: pop    r12 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141e: pop    r13 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1420: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1422: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1424: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1425: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
