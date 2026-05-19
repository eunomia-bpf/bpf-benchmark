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
  20:	0f 87 87 03 00 00    	ja     0x3ad
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 77 03 00 00    	ja     0x3ad
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 0c 01 00 00 	add    rdx,0x10c
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 64 03 00 00    	ja     0x3ad
  49:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4e:	c1 e6 08             	shl    esi,0x8
  51:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  56:	09 d6                	or     esi,edx
  58:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  5d:	c1 e2 10             	shl    edx,0x10
  60:	09 d6                	or     esi,edx
  62:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  67:	c1 e2 18             	shl    edx,0x18
  6a:	09 d6                	or     esi,edx
  6c:	83 fe 40             	cmp    esi,0x40
  6f:	0f 85 38 03 00 00    	jne    0x3ad
  75:	49 b8 09 c9 bc f3 67 	movabs r8,0x6a09e667f3bcc909
  7c:	e6 09 6a 
  7f:	31 f6                	xor    esi,esi
  81:	48 89 fa             	mov    rdx,rdi
  84:	48 83 c2 0f          	add    rdx,0xf
  88:	48 b9 87 ca eb 85 b1 	movabs rcx,0x9e3779b185ebca87
  8f:	79 37 9e 
  92:	48 0f b6 5a fe       	movzx  rbx,BYTE PTR [rdx-0x2]
  97:	c1 e3 08             	shl    ebx,0x8
  9a:	48 0f b6 42 fd       	movzx  rax,BYTE PTR [rdx-0x3]
  9f:	09 c3                	or     ebx,eax
  a1:	4c 0f b6 6a ff       	movzx  r13,BYTE PTR [rdx-0x1]
  a6:	41 c1 e5 10          	shl    r13d,0x10
  aa:	44 09 eb             	or     ebx,r13d
  ad:	4c 0f b6 6a 00       	movzx  r13,BYTE PTR [rdx+0x0]
  b2:	41 c1 e5 18          	shl    r13d,0x18
  b6:	44 09 eb             	or     ebx,r13d
  b9:	83 fb 4f             	cmp    ebx,0x4f
  bc:	7f 3a                	jg     0xf8
  be:	83 fb 26             	cmp    ebx,0x26
  c1:	7f 74                	jg     0x137
  c3:	83 fb 02             	cmp    ebx,0x2
  c6:	0f 8f db 00 00 00    	jg     0x1a7
  cc:	41 bd 64 61 65 72    	mov    r13d,0x72656164
  d2:	85 db                	test   ebx,ebx
  d4:	0f 84 2a 02 00 00    	je     0x304
  da:	83 fb 01             	cmp    ebx,0x1
  dd:	0f 84 76 01 00 00    	je     0x259
  e3:	83 fb 02             	cmp    ebx,0x2
  e6:	74 05                	je     0xed
  e8:	e9 61 02 00 00       	jmp    0x34e
  ed:	41 bd 6f 70 65 6e    	mov    r13d,0x6e65706f
  f3:	e9 0c 02 00 00       	jmp    0x304
  f8:	81 fb 00 01 00 00    	cmp    ebx,0x100
  fe:	7f 67                	jg     0x167
 100:	81 fb 9d 00 00 00    	cmp    ebx,0x9d
 106:	0f 8f c2 00 00 00    	jg     0x1ce
 10c:	83 fb 50             	cmp    ebx,0x50
 10f:	0f 84 a1 01 00 00    	je     0x2b6
 115:	83 fb 57             	cmp    ebx,0x57
 118:	0f 84 4a 01 00 00    	je     0x268
 11e:	83 fb 59             	cmp    ebx,0x59
 121:	74 05                	je     0x128
 123:	e9 26 02 00 00       	jmp    0x34e
 128:	49 bd 55 6c 69 6e 6b 	movabs r13,0x6b6e696c55
 12f:	00 00 00 
 132:	e9 cd 01 00 00       	jmp    0x304
 137:	83 fb 3a             	cmp    ebx,0x3a
 13a:	0f 8f c2 00 00 00    	jg     0x202
 140:	83 fb 27             	cmp    ebx,0x27
 143:	0f 84 75 01 00 00    	je     0x2be
 149:	83 fb 38             	cmp    ebx,0x38
 14c:	0f 84 25 01 00 00    	je     0x277
 152:	83 fb 39             	cmp    ebx,0x39
 155:	74 05                	je     0x15c
 157:	e9 f2 01 00 00       	jmp    0x34e
 15c:	41 bd 66 6f 72 6b    	mov    r13d,0x6b726f66
 162:	e9 9d 01 00 00       	jmp    0x304
 167:	81 fb 22 01 00 00    	cmp    ebx,0x122
 16d:	0f 8f ba 00 00 00    	jg     0x22d
 173:	81 fb 01 01 00 00    	cmp    ebx,0x101
 179:	0f 84 4b 01 00 00    	je     0x2ca
 17f:	81 fb 07 01 00 00    	cmp    ebx,0x107
 185:	0f 84 fb 00 00 00    	je     0x286
 18b:	81 fb 19 01 00 00    	cmp    ebx,0x119
 191:	74 05                	je     0x198
 193:	e9 b6 01 00 00       	jmp    0x34e
 198:	49 bd 73 74 61 74 32 	movabs r13,0x74613274617473
 19f:	61 74 00 
 1a2:	e9 5d 01 00 00       	jmp    0x304
 1a7:	83 fb 03             	cmp    ebx,0x3
 1aa:	0f 84 26 01 00 00    	je     0x2d6
 1b0:	83 fb 09             	cmp    ebx,0x9
 1b3:	0f 84 d9 00 00 00    	je     0x292
 1b9:	83 fb 0c             	cmp    ebx,0xc
 1bc:	74 05                	je     0x1c3
 1be:	e9 8b 01 00 00       	jmp    0x34e
 1c3:	41 bd 6b 62 72 6b    	mov    r13d,0x6b72626b
 1c9:	e9 36 01 00 00       	jmp    0x304
 1ce:	81 fb 9e 00 00 00    	cmp    ebx,0x9e
 1d4:	0f 84 08 01 00 00    	je     0x2e2
 1da:	81 fb ca 00 00 00    	cmp    ebx,0xca
 1e0:	0f 84 b4 00 00 00    	je     0x29a
 1e6:	81 fb d9 00 00 00    	cmp    ebx,0xd9
 1ec:	74 05                	je     0x1f3
 1ee:	e9 5b 01 00 00       	jmp    0x34e
 1f3:	49 bd 67 65 74 61 64 	movabs r13,0x646461746567
 1fa:	64 00 00 
 1fd:	e9 02 01 00 00       	jmp    0x304
 202:	83 fb 3b             	cmp    ebx,0x3b
 205:	0f 84 e3 00 00 00    	je     0x2ee
 20b:	83 fb 3c             	cmp    ebx,0x3c
 20e:	0f 84 92 00 00 00    	je     0x2a6
 214:	83 fb 3d             	cmp    ebx,0x3d
 217:	74 05                	je     0x21e
 219:	e9 30 01 00 00       	jmp    0x34e
 21e:	49 bd 55 77 61 69 74 	movabs r13,0x347469617755
 225:	34 00 00 
 228:	e9 d7 00 00 00       	jmp    0x304
 22d:	81 fb 23 01 00 00    	cmp    ebx,0x123
 233:	0f 84 c1 00 00 00    	je     0x2fa
 239:	81 fb 41 01 00 00    	cmp    ebx,0x141
 23f:	74 6d                	je     0x2ae
 241:	81 fb 4c 01 00 00    	cmp    ebx,0x14c
 247:	74 05                	je     0x24e
 249:	e9 00 01 00 00       	jmp    0x34e
 24e:	41 bd 73 61 74 78    	mov    r13d,0x78746173
 254:	e9 ab 00 00 00       	jmp    0x304
 259:	49 bd 77 72 69 74 65 	movabs r13,0x6574697277
 260:	00 00 00 
 263:	e9 9c 00 00 00       	jmp    0x304
 268:	49 bd 75 6e 6c 69 6e 	movabs r13,0x6b6e696c6e75
 26f:	6b 00 00 
 272:	e9 8d 00 00 00       	jmp    0x304
 277:	49 bd 55 63 6c 6f 6e 	movabs r13,0x656e6f6c6355
 27e:	65 00 00 
 281:	e9 7e 00 00 00       	jmp    0x304
 286:	49 bd 75 6e 6c 69 6e 	movabs r13,0x74616b6e696c6e75
 28d:	6b 61 74 
 290:	eb 72                	jmp    0x304
 292:	41 bd 6d 6d 61 70    	mov    r13d,0x70616d6d
 298:	eb 6a                	jmp    0x304
 29a:	49 bd 55 66 75 74 65 	movabs r13,0x786574756655
 2a1:	78 00 00 
 2a4:	eb 5e                	jmp    0x304
 2a6:	41 bd 65 78 69 74    	mov    r13d,0x74697865
 2ac:	eb 56                	jmp    0x304
 2ae:	41 bd 62 66 70 00    	mov    r13d,0x706662
 2b4:	eb 4e                	jmp    0x304
 2b6:	41 bd 63 68 64 69    	mov    r13d,0x69646863
 2bc:	eb 46                	jmp    0x304
 2be:	49 bd 67 74 70 69 64 	movabs r13,0x6469707467
 2c5:	00 00 00 
 2c8:	eb 3a                	jmp    0x304
 2ca:	49 bd 6f 70 65 6e 61 	movabs r13,0x74616e65706f
 2d1:	74 00 00 
 2d4:	eb 2e                	jmp    0x304
 2d6:	49 bd 63 6c 6f 73 65 	movabs r13,0x65736f6c63
 2dd:	00 00 00 
 2e0:	eb 22                	jmp    0x304
 2e2:	49 bd 61 72 63 68 5f 	movabs r13,0x6c74635f68637261
 2e9:	63 74 6c 
 2ec:	eb 16                	jmp    0x304
 2ee:	49 bd 65 78 65 63 76 	movabs r13,0x657663657865
 2f5:	65 00 00 
 2f8:	eb 0a                	jmp    0x304
 2fa:	49 bd 73 69 67 6e 65 	movabs r13,0x647466656e676973
 301:	66 74 64 
 304:	49 31 dd             	xor    r13,rbx
 307:	89 f3                	mov    ebx,esi
 309:	83 e3 07             	and    ebx,0x7
 30c:	41 89 de             	mov    r14d,ebx
 30f:	41 83 f6 3f          	xor    r14d,0x3f
 313:	4d 89 ef             	mov    r15,r13
 316:	c4 42 8b f7 ff       	shrx   r15,r15,r14
 31b:	41 89 de             	mov    r14d,ebx
 31e:	41 83 c6 01          	add    r14d,0x1
 322:	c4 42 89 f7 ed       	shlx   r13,r13,r14
 327:	4d 09 fd             	or     r13,r15
 32a:	4d 01 c5             	add    r13,r8
 32d:	c1 e3 03             	shl    ebx,0x3
 330:	c4 e2 e1 f7 c0       	shlx   rax,rax,rbx
 335:	49 31 c5             	xor    r13,rax
 338:	48 83 c2 04          	add    rdx,0x4
 33c:	48 83 c6 01          	add    rsi,0x1
 340:	4d 89 e8             	mov    r8,r13
 343:	48 83 fe 40          	cmp    rsi,0x40
 347:	74 11                	je     0x35a
 349:	e9 44 fd ff ff       	jmp    0x92
 34e:	48 0f af d9          	imul   rbx,rcx
 352:	4c 31 c3             	xor    rbx,r8
 355:	49 89 dd             	mov    r13,rbx
 358:	eb de                	jmp    0x338
 35a:	44 88 6f 00          	mov    BYTE PTR [rdi+0x0],r13b
 35e:	4c 89 ee             	mov    rsi,r13
 361:	48 c1 ee 38          	shr    rsi,0x38
 365:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 369:	4c 89 ee             	mov    rsi,r13
 36c:	48 c1 ee 30          	shr    rsi,0x30
 370:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 374:	4c 89 ee             	mov    rsi,r13
 377:	48 c1 ee 28          	shr    rsi,0x28
 37b:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 37f:	4c 89 ee             	mov    rsi,r13
 382:	48 c1 ee 20          	shr    rsi,0x20
 386:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 38a:	4c 89 ee             	mov    rsi,r13
 38d:	48 c1 ee 18          	shr    rsi,0x18
 391:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 395:	4c 89 ee             	mov    rsi,r13
 398:	48 c1 ee 10          	shr    rsi,0x10
 39c:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 3a0:	49 c1 ed 08          	shr    r13,0x8
 3a4:	44 88 6f 01          	mov    BYTE PTR [rdi+0x1],r13b
 3a8:	b8 02 00 00 00       	mov    eax,0x2
 3ad:	41 5f                	pop    r15
 3af:	41 5e                	pop    r14
 3b1:	41 5d                	pop    r13
 3b3:	5b                   	pop    rbx
 3b4:	c9                   	leave
 3b5:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
