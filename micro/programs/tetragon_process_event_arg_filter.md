# tetragon_process_event_arg_filter

## Original C
```c
#include "common.h"

#define TETRAGON_ARG_FILTER_RECORDS 32U
#define TETRAGON_ARG_FILTER_RECORD_SIZE 32U
#define TETRAGON_ARG_FILTER_INPUT_SIZE \
    (8U + TETRAGON_ARG_FILTER_RECORDS * TETRAGON_ARG_FILTER_RECORD_SIZE)

static __always_inline u32 tetragon_event_weight(u16 event_id)
{
    switch (event_id) {
    case 1U: return 0x11U;
    case 2U: return 0x23U;
    case 5U: return 0x37U;
    case 9U: return 0x41U;
    case 13U: return 0x59U;
    default: return 0U;
    }
}

static __always_inline u32 tetragon_arg_prefix_class(u64 arg_sig)
{
    if ((arg_sig & 0xFFFFFFFFULL) == 0x68736162ULL) {
        return 1U;
    }
    if ((arg_sig & 0xFFFFFFFFULL) == 0x6C727563ULL) {
        return 2U;
    }
    if ((arg_sig & 0xFFFFFFFFFFFFULL) == 0x6E6F68747970ULL) {
        return 3U;
    }
    if ((arg_sig & 0xFFFFFFULL) == 0x006873ULL) {
        return 4U;
    }
    return 0U;
}

static __always_inline int
bench_tetragon_process_event_arg_filter(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TETRAGON_ARG_FILTER_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != TETRAGON_ARG_FILTER_RECORDS ||
        record_size != TETRAGON_ARG_FILTER_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0xE7037ED1A0B428DBULL;
    for (u32 index = 0; index < TETRAGON_ARG_FILTER_RECORDS; index++) {
        u32 base = 8U + index * TETRAGON_ARG_FILTER_RECORD_SIZE;
        u32 pid = micro_read_u32_le(data, base);
        u32 tid = micro_read_u32_le(data, base + 4U);
        u32 namespace_id = micro_read_u32_le(data, base + 8U);
        u16 event_id = micro_read_u16_le(data, base + 12U);
        u16 action = micro_read_u16_le(data, base + 14U);
        u64 caps = micro_read_u64_le(data, base + 16U);
        u64 arg_sig = micro_read_u64_le(data, base + 24U);
        u32 weight = tetragon_event_weight(event_id);
        u32 arg_class = tetragon_arg_prefix_class(arg_sig);
        u32 namespace_match = (namespace_id & 0xFFU) == 0x42U;
        u32 cap_match = (caps & 0x0000000000002400ULL) != 0U;

        if (weight == 0U) {
            acc ^= ((u64)event_id << 32U) | pid;
            continue;
        }
        if (namespace_match == 0U && cap_match == 0U) {
            acc += ((u64)tid << 16U) ^ namespace_id;
            continue;
        }

        u64 decision = ((u64)weight << 48U) | ((u64)arg_class << 40U) |
                       ((u64)action << 24U) | pid;
        if ((action & 2U) != 0U && arg_class != 0U) {
            decision ^= micro_rotl64(arg_sig, (event_id & 7U) + 1U);
        }
        if ((action & 4U) != 0U) {
            decision += caps ^ tid;
        }

        acc ^= micro_rotl64(decision, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tetragon_process_event_arg_filter_xdp,
    bench_tetragon_process_event_arg_filter,
    tetragon_process_event_arg_filter_input_value,
    TETRAGON_ARG_FILTER_INPUT_SIZE)
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

0000000000001100 <tetragon_process_event_arg_filter_xdp>:
    1100:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ce             	cmp    rsi,rcx
    110c:	76 01                	jbe    110f <tetragon_process_event_arg_filter_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 56 08          	lea    rdx,[rsi+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <tetragon_process_event_arg_filter_xdp+0xe>
    1118:	48 8d 96 10 04 00 00 	lea    rdx,[rsi+0x410]
    111f:	48 39 ca             	cmp    rdx,rcx
    1122:	77 ea                	ja     110e <tetragon_process_event_arg_filter_xdp+0xe>
    1124:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
    1128:	75 e4                	jne    110e <tetragon_process_event_arg_filter_xdp+0xe>
    112a:	83 7e 0c 20          	cmp    DWORD PTR [rsi+0xc],0x20
    112e:	75 de                	jne    110e <tetragon_process_event_arg_filter_xdp+0xe>
    1130:	55                   	push   rbp
    1131:	41 57                	push   r15
    1133:	41 56                	push   r14
    1135:	41 55                	push   r13
    1137:	41 54                	push   r12
    1139:	53                   	push   rbx
    113a:	48 83 ec 40          	sub    rsp,0x40
    113e:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
    1143:	48 8d 7e 2f          	lea    rdi,[rsi+0x2f]
    1147:	49 bb db 28 b4 a0 d1 	movabs r11,0xe7037ed1a0b428db
    114e:	7e 03 e7 
    1151:	45 31 c0             	xor    r8d,r8d
    1154:	eb 28                	jmp    117e <tetragon_process_event_arg_filter_xdp+0x7e>
    1156:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    115d:	00 00 00 
    1160:	48 c1 e1 20          	shl    rcx,0x20
    1164:	44 89 f8             	mov    eax,r15d
    1167:	48 09 c8             	or     rax,rcx
    116a:	49 31 c3             	xor    r11,rax
    116d:	49 ff c0             	inc    r8
    1170:	48 83 c7 20          	add    rdi,0x20
    1174:	49 83 f8 20          	cmp    r8,0x20
    1178:	0f 84 88 02 00 00    	je     1406 <tetragon_process_event_arg_filter_xdp+0x306>
    117e:	44 0f b6 77 ed       	movzx  r14d,BYTE PTR [rdi-0x13]
    1183:	0f b6 4f ee          	movzx  ecx,BYTE PTR [rdi-0x12]
    1187:	c1 e1 08             	shl    ecx,0x8
    118a:	4c 09 f1             	or     rcx,r14
    118d:	83 f9 04             	cmp    ecx,0x4
    1190:	7e 1e                	jle    11b0 <tetragon_process_event_arg_filter_xdp+0xb0>
    1192:	83 f9 05             	cmp    ecx,0x5
    1195:	74 31                	je     11c8 <tetragon_process_event_arg_filter_xdp+0xc8>
    1197:	83 f9 09             	cmp    ecx,0x9
    119a:	74 3a                	je     11d6 <tetragon_process_event_arg_filter_xdp+0xd6>
    119c:	83 f9 0d             	cmp    ecx,0xd
    119f:	75 51                	jne    11f2 <tetragon_process_event_arg_filter_xdp+0xf2>
    11a1:	31 d2                	xor    edx,edx
    11a3:	49 bc 00 00 00 00 00 	movabs r12,0x59000000000000
    11aa:	00 59 00 
    11ad:	eb 51                	jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100>
    11af:	90                   	nop
    11b0:	83 f9 01             	cmp    ecx,0x1
    11b3:	74 2f                	je     11e4 <tetragon_process_event_arg_filter_xdp+0xe4>
    11b5:	83 f9 02             	cmp    ecx,0x2
    11b8:	75 38                	jne    11f2 <tetragon_process_event_arg_filter_xdp+0xf2>
    11ba:	31 d2                	xor    edx,edx
    11bc:	49 bc 00 00 00 00 00 	movabs r12,0x23000000000000
    11c3:	00 23 00 
    11c6:	eb 38                	jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100>
    11c8:	31 d2                	xor    edx,edx
    11ca:	49 bc 00 00 00 00 00 	movabs r12,0x37000000000000
    11d1:	00 37 00 
    11d4:	eb 2a                	jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100>
    11d6:	31 d2                	xor    edx,edx
    11d8:	49 bc 00 00 00 00 00 	movabs r12,0x41000000000000
    11df:	00 41 00 
    11e2:	eb 1c                	jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100>
    11e4:	31 d2                	xor    edx,edx
    11e6:	49 bc 00 00 00 00 00 	movabs r12,0x11000000000000
    11ed:	00 11 00 
    11f0:	eb 0e                	jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100>
    11f2:	b2 01                	mov    dl,0x1
    11f4:	45 31 e4             	xor    r12d,r12d
    11f7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    11fe:	00 00 
    1200:	0f b7 77 f9          	movzx  esi,WORD PTR [rdi-0x7]
    1204:	44 0f b6 4f fb       	movzx  r9d,BYTE PTR [rdi-0x5]
    1209:	41 c1 e1 10          	shl    r9d,0x10
    120d:	49 09 f1             	or     r9,rsi
    1210:	0f b6 77 fc          	movzx  esi,BYTE PTR [rdi-0x4]
    1214:	c1 e6 18             	shl    esi,0x18
    1217:	4c 09 ce             	or     rsi,r9
    121a:	44 0f b6 57 fd       	movzx  r10d,BYTE PTR [rdi-0x3]
    121f:	49 c1 e2 20          	shl    r10,0x20
    1223:	0f b6 5f fe          	movzx  ebx,BYTE PTR [rdi-0x2]
    1227:	48 c1 e3 28          	shl    rbx,0x28
    122b:	4c 09 d3             	or     rbx,r10
    122e:	48 09 f3             	or     rbx,rsi
    1231:	48 81 fe 62 61 73 68 	cmp    rsi,0x68736162
    1238:	74 16                	je     1250 <tetragon_process_event_arg_filter_xdp+0x150>
    123a:	81 fe 63 75 72 6c    	cmp    esi,0x6c727563
    1240:	75 1e                	jne    1260 <tetragon_process_event_arg_filter_xdp+0x160>
    1242:	be 02 00 00 00       	mov    esi,0x2
    1247:	eb 47                	jmp    1290 <tetragon_process_event_arg_filter_xdp+0x190>
    1249:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1250:	be 01 00 00 00       	mov    esi,0x1
    1255:	eb 39                	jmp    1290 <tetragon_process_event_arg_filter_xdp+0x190>
    1257:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    125e:	00 00 
    1260:	be 03 00 00 00       	mov    esi,0x3
    1265:	48 b8 70 79 74 68 6f 	movabs rax,0x6e6f68747970
    126c:	6e 00 00 
    126f:	48 39 c3             	cmp    rbx,rax
    1272:	74 1c                	je     1290 <tetragon_process_event_arg_filter_xdp+0x190>
    1274:	31 f6                	xor    esi,esi
    1276:	41 81 f9 73 68 00 00 	cmp    r9d,0x6873
    127d:	40 0f 94 c6          	sete   sil
    1281:	c1 e6 02             	shl    esi,0x2
    1284:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    128b:	00 00 00 00 00 
    1290:	44 8b 7f e1          	mov    r15d,DWORD PTR [rdi-0x1f]
    1294:	84 d2                	test   dl,dl
    1296:	0f 85 c4 fe ff ff    	jne    1160 <tetragon_process_event_arg_filter_xdp+0x60>
    129c:	4c 89 e1             	mov    rcx,r12
    129f:	4c 89 74 24 20       	mov    QWORD PTR [rsp+0x20],r14
    12a4:	4c 89 1c 24          	mov    QWORD PTR [rsp],r11
    12a8:	44 0f b6 5f e9       	movzx  r11d,BYTE PTR [rdi-0x17]
    12ad:	0f b6 47 f1          	movzx  eax,BYTE PTR [rdi-0xf]
    12b1:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
    12b6:	0f b6 6f f2          	movzx  ebp,BYTE PTR [rdi-0xe]
    12ba:	0f b6 47 f3          	movzx  eax,BYTE PTR [rdi-0xd]
    12be:	89 44 24 0c          	mov    DWORD PTR [rsp+0xc],eax
    12c2:	44 0f b6 6f f4       	movzx  r13d,BYTE PTR [rdi-0xc]
    12c7:	0f b6 47 f5          	movzx  eax,BYTE PTR [rdi-0xb]
    12cb:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
    12d0:	44 0f b6 4f f6       	movzx  r9d,BYTE PTR [rdi-0xa]
    12d5:	0f b6 47 f7          	movzx  eax,BYTE PTR [rdi-0x9]
    12d9:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
    12de:	44 0f b6 57 f8       	movzx  r10d,BYTE PTR [rdi-0x8]
    12e3:	0f b6 47 ff          	movzx  eax,BYTE PTR [rdi-0x1]
    12e7:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    12ec:	44 0f b6 37          	movzx  r14d,BYTE PTR [rdi]
    12f0:	0f b7 57 ef          	movzx  edx,WORD PTR [rdi-0x11]
    12f4:	44 8b 67 e5          	mov    r12d,DWORD PTR [rdi-0x1b]
    12f8:	41 80 fb 42          	cmp    r11b,0x42
    12fc:	74 32                	je     1330 <tetragon_process_event_arg_filter_xdp+0x230>
    12fe:	89 e8                	mov    eax,ebp
    1300:	83 e0 24             	and    eax,0x24
    1303:	75 2b                	jne    1330 <tetragon_process_event_arg_filter_xdp+0x230>
    1305:	0f b6 47 ea          	movzx  eax,BYTE PTR [rdi-0x16]
    1309:	c1 e0 08             	shl    eax,0x8
    130c:	0f b7 4f eb          	movzx  ecx,WORD PTR [rdi-0x15]
    1310:	c1 e1 10             	shl    ecx,0x10
    1313:	4c 09 d8             	or     rax,r11
    1316:	48 09 c8             	or     rax,rcx
    1319:	49 c1 e4 10          	shl    r12,0x10
    131d:	49 31 c4             	xor    r12,rax
    1320:	4c 8b 1c 24          	mov    r11,QWORD PTR [rsp]
    1324:	4d 01 e3             	add    r11,r12
    1327:	e9 41 fe ff ff       	jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d>
    132c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1330:	48 89 f0             	mov    rax,rsi
    1333:	48 c1 e0 28          	shl    rax,0x28
    1337:	48 09 c8             	or     rax,rcx
    133a:	49 89 d3             	mov    r11,rdx
    133d:	49 c1 e3 18          	shl    r11,0x18
    1341:	49 09 c3             	or     r11,rax
    1344:	45 89 ff             	mov    r15d,r15d
    1347:	4d 09 df             	or     r15,r11
    134a:	0f b7 ca             	movzx  ecx,dx
    134d:	f6 c1 02             	test   cl,0x2
    1350:	74 3f                	je     1391 <tetragon_process_event_arg_filter_xdp+0x291>
    1352:	85 f6                	test   esi,esi
    1354:	4c 8b 1c 24          	mov    r11,QWORD PTR [rsp]
    1358:	74 3b                	je     1395 <tetragon_process_event_arg_filter_xdp+0x295>
    135a:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
    135f:	48 c1 e0 30          	shl    rax,0x30
    1363:	49 c1 e6 38          	shl    r14,0x38
    1367:	49 09 c6             	or     r14,rax
    136a:	49 09 de             	or     r14,rbx
    136d:	48 8b 54 24 20       	mov    rdx,QWORD PTR [rsp+0x20]
    1372:	80 e2 07             	and    dl,0x7
    1375:	89 ce                	mov    esi,ecx
    1377:	8d 4a 01             	lea    ecx,[rdx+0x1]
    137a:	4c 89 f0             	mov    rax,r14
    137d:	48 d3 e0             	shl    rax,cl
    1380:	f6 d2                	not    dl
    1382:	89 d1                	mov    ecx,edx
    1384:	49 d3 ee             	shr    r14,cl
    1387:	89 f1                	mov    ecx,esi
    1389:	49 09 c6             	or     r14,rax
    138c:	4d 31 f7             	xor    r15,r14
    138f:	eb 04                	jmp    1395 <tetragon_process_event_arg_filter_xdp+0x295>
    1391:	4c 8b 1c 24          	mov    r11,QWORD PTR [rsp]
    1395:	c1 e5 08             	shl    ebp,0x8
    1398:	48 03 6c 24 28       	add    rbp,QWORD PTR [rsp+0x28]
    139d:	8b 44 24 0c          	mov    eax,DWORD PTR [rsp+0xc]
    13a1:	c1 e0 10             	shl    eax,0x10
    13a4:	41 c1 e5 18          	shl    r13d,0x18
    13a8:	41 09 c5             	or     r13d,eax
    13ab:	48 8b 44 24 30       	mov    rax,QWORD PTR [rsp+0x30]
    13b0:	48 c1 e0 20          	shl    rax,0x20
    13b4:	49 c1 e1 28          	shl    r9,0x28
    13b8:	49 09 c1             	or     r9,rax
    13bb:	48 8b 44 24 38       	mov    rax,QWORD PTR [rsp+0x38]
    13c0:	48 c1 e0 30          	shl    rax,0x30
    13c4:	49 c1 e2 38          	shl    r10,0x38
    13c8:	49 09 c2             	or     r10,rax
    13cb:	49 09 ed             	or     r13,rbp
    13ce:	4d 09 cd             	or     r13,r9
    13d1:	4d 09 d5             	or     r13,r10
    13d4:	4d 31 ec             	xor    r12,r13
    13d7:	f6 c1 04             	test   cl,0x4
    13da:	ba 00 00 00 00       	mov    edx,0x0
    13df:	49 0f 45 d4          	cmovne rdx,r12
    13e3:	4c 01 fa             	add    rdx,r15
    13e6:	44 89 c0             	mov    eax,r8d
    13e9:	24 07                	and    al,0x7
    13eb:	8d 48 01             	lea    ecx,[rax+0x1]
    13ee:	48 89 d6             	mov    rsi,rdx
    13f1:	48 d3 e6             	shl    rsi,cl
    13f4:	f6 d0                	not    al
    13f6:	89 c1                	mov    ecx,eax
    13f8:	48 d3 ea             	shr    rdx,cl
    13fb:	48 09 f2             	or     rdx,rsi
    13fe:	49 31 d3             	xor    r11,rdx
    1401:	e9 67 fd ff ff       	jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d>
    1406:	48 8b 44 24 10       	mov    rax,QWORD PTR [rsp+0x10]
    140b:	4c 89 18             	mov    QWORD PTR [rax],r11
    140e:	b8 02 00 00 00       	mov    eax,0x2
    1413:	48 83 c4 40          	add    rsp,0x40
    1417:	5b                   	pop    rbx
    1418:	41 5c                	pop    r12
    141a:	41 5d                	pop    r13
    141c:	41 5e                	pop    r14
    141e:	41 5f                	pop    r15
    1420:	5d                   	pop    rbp
    1421:	c3                   	ret

Disassembly of section .fini:

0000000000001424 <_fini>:
    1424:	f3 0f 1e fa          	endbr64
    1428:	48 83 ec 08          	sub    rsp,0x8
    142c:	48 83 c4 08          	add    rsp,0x8
    1430:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 78 00 00 00 	sub    rsp,0x78
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  24:	48 39 f1             	cmp    rcx,rsi
  27:	0f 87 5b 04 00 00    	ja     0x488
  2d:	48 89 cf             	mov    rdi,rcx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 4b 04 00 00    	ja     0x488
  3d:	48 89 cf             	mov    rdi,rcx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 38 04 00 00    	ja     0x488
  50:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
  55:	c1 e7 08             	shl    edi,0x8
  58:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  5d:	09 f7                	or     edi,esi
  5f:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  64:	c1 e6 10             	shl    esi,0x10
  67:	09 f7                	or     edi,esi
  69:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  6e:	c1 e6 18             	shl    esi,0x18
  71:	09 f7                	or     edi,esi
  73:	83 ff 20             	cmp    edi,0x20
  76:	0f 85 0c 04 00 00    	jne    0x488
  7c:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
  81:	c1 e7 08             	shl    edi,0x8
  84:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
  89:	09 f7                	or     edi,esi
  8b:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
  90:	c1 e6 10             	shl    esi,0x10
  93:	09 f7                	or     edi,esi
  95:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
  9a:	c1 e6 18             	shl    esi,0x18
  9d:	09 f7                	or     edi,esi
  9f:	83 ff 20             	cmp    edi,0x20
  a2:	0f 85 e0 03 00 00    	jne    0x488
  a8:	49 bf db 28 b4 a0 d1 	movabs r15,0xe7037ed1a0b428db
  af:	7e 03 e7 
  b2:	31 d2                	xor    edx,edx
  b4:	48 89 4d 88          	mov    QWORD PTR [rbp-0x78],rcx
  b8:	48 83 c1 17          	add    rcx,0x17
  bc:	eb 5a                	jmp    0x118
  be:	4c 0f b6 41 fa       	movzx  r8,BYTE PTR [rcx-0x6]
  c3:	41 c1 e0 08          	shl    r8d,0x8
  c7:	4c 0f b6 69 f9       	movzx  r13,BYTE PTR [rcx-0x7]
  cc:	45 09 e8             	or     r8d,r13d
  cf:	4c 0f b6 69 fb       	movzx  r13,BYTE PTR [rcx-0x5]
  d4:	41 c1 e5 10          	shl    r13d,0x10
  d8:	45 09 e8             	or     r8d,r13d
  db:	4c 0f b6 69 fc       	movzx  r13,BYTE PTR [rcx-0x4]
  e0:	41 c1 e5 18          	shl    r13d,0x18
  e4:	45 09 e8             	or     r8d,r13d
  e7:	85 f6                	test   esi,esi
  e9:	0f 84 d9 00 00 00    	je     0x1c8
  ef:	81 e7 ff ff 00 00    	and    edi,0xffff
  f5:	48 c1 e7 20          	shl    rdi,0x20
  f9:	4c 09 c7             	or     rdi,r8
  fc:	4c 31 ff             	xor    rdi,r15
  ff:	49 89 ff             	mov    r15,rdi
 102:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 106:	48 83 c1 20          	add    rcx,0x20
 10a:	48 83 c2 01          	add    rdx,0x1
 10e:	48 83 fa 20          	cmp    rdx,0x20
 112:	0f 84 19 03 00 00    	je     0x431
 118:	48 0f b6 71 11       	movzx  rsi,BYTE PTR [rcx+0x11]
 11d:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 122:	48 c1 e7 08          	shl    rdi,0x8
 126:	48 09 f7             	or     rdi,rsi
 129:	48 0f b6 71 16       	movzx  rsi,BYTE PTR [rcx+0x16]
 12e:	48 c1 e6 28          	shl    rsi,0x28
 132:	48 0f b6 59 15       	movzx  rbx,BYTE PTR [rcx+0x15]
 137:	48 c1 e3 20          	shl    rbx,0x20
 13b:	48 09 f3             	or     rbx,rsi
 13e:	4c 0f b6 41 13       	movzx  r8,BYTE PTR [rcx+0x13]
 143:	49 c1 e0 10          	shl    r8,0x10
 147:	49 09 f8             	or     r8,rdi
 14a:	31 f6                	xor    esi,esi
 14c:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 151:	c1 e7 08             	shl    edi,0x8
 154:	48 0f b6 41 05       	movzx  rax,BYTE PTR [rcx+0x5]
 159:	09 c7                	or     edi,eax
 15b:	4c 0f b6 71 14       	movzx  r14,BYTE PTR [rcx+0x14]
 160:	49 c1 e6 18          	shl    r14,0x18
 164:	4d 09 c6             	or     r14,r8
 167:	41 89 fd             	mov    r13d,edi
 16a:	41 81 e5 ff ff 00 00 	and    r13d,0xffff
 171:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
 175:	41 83 fd 04          	cmp    r13d,0x4
 179:	7f 24                	jg     0x19f
 17b:	b8 11 00 00 00       	mov    eax,0x11
 180:	41 83 fd 01          	cmp    r13d,0x1
 184:	0f 84 4a 02 00 00    	je     0x3d4
 18a:	41 83 fd 02          	cmp    r13d,0x2
 18e:	74 05                	je     0x195
 190:	e9 38 02 00 00       	jmp    0x3cd
 195:	b8 23 00 00 00       	mov    eax,0x23
 19a:	e9 35 02 00 00       	jmp    0x3d4
 19f:	41 83 fd 05          	cmp    r13d,0x5
 1a3:	0f 84 16 02 00 00    	je     0x3bf
 1a9:	41 83 fd 09          	cmp    r13d,0x9
 1ad:	0f 84 13 02 00 00    	je     0x3c6
 1b3:	41 83 fd 0d          	cmp    r13d,0xd
 1b7:	74 05                	je     0x1be
 1b9:	e9 0f 02 00 00       	jmp    0x3cd
 1be:	b8 59 00 00 00       	mov    eax,0x59
 1c3:	e9 0c 02 00 00       	jmp    0x3d4
 1c8:	4c 89 7d e0          	mov    QWORD PTR [rbp-0x20],r15
 1cc:	48 0f b6 79 0a       	movzx  rdi,BYTE PTR [rcx+0xa]
 1d1:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
 1d5:	48 0f b6 79 0c       	movzx  rdi,BYTE PTR [rcx+0xc]
 1da:	48 89 7d a8          	mov    QWORD PTR [rbp-0x58],rdi
 1de:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 1e3:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 1e7:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 1ec:	48 89 7d a0          	mov    QWORD PTR [rbp-0x60],rdi
 1f0:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 1f5:	48 89 7d b0          	mov    QWORD PTR [rbp-0x50],rdi
 1f9:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
 1fe:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 202:	4c 0f b6 71 fe       	movzx  r14,BYTE PTR [rcx-0x2]
 207:	41 c1 e6 08          	shl    r14d,0x8
 20b:	48 0f b6 79 10       	movzx  rdi,BYTE PTR [rcx+0x10]
 210:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 214:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
 219:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 21d:	4c 0f b6 69 01       	movzx  r13,BYTE PTR [rcx+0x1]
 222:	48 0f b6 79 18       	movzx  rdi,BYTE PTR [rcx+0x18]
 227:	48 89 7d 98          	mov    QWORD PTR [rbp-0x68],rdi
 22b:	48 0f b6 79 17       	movzx  rdi,BYTE PTR [rcx+0x17]
 230:	48 89 7d 90          	mov    QWORD PTR [rbp-0x70],rdi
 234:	48 0f b6 71 fd       	movzx  rsi,BYTE PTR [rcx-0x3]
 239:	41 09 f6             	or     r14d,esi
 23c:	48 0f b6 71 ff       	movzx  rsi,BYTE PTR [rcx-0x1]
 241:	c1 e6 10             	shl    esi,0x10
 244:	41 09 f6             	or     r14d,esi
 247:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
 24c:	4c 0f b6 79 00       	movzx  r15,BYTE PTR [rcx+0x0]
 251:	41 c1 e7 18          	shl    r15d,0x18
 255:	48 0f b6 79 07       	movzx  rdi,BYTE PTR [rcx+0x7]
 25a:	89 7d d8             	mov    DWORD PTR [rbp-0x28],edi
 25d:	45 09 fe             	or     r14d,r15d
 260:	41 83 fd 42          	cmp    r13d,0x42
 264:	74 44                	je     0x2aa
 266:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 26a:	49 83 e7 24          	and    r15,0x24
 26e:	4d 85 ff             	test   r15,r15
 271:	75 37                	jne    0x2aa
 273:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 278:	48 c1 e7 08          	shl    rdi,0x8
 27c:	48 0f b6 71 03       	movzx  rsi,BYTE PTR [rcx+0x3]
 281:	4c 09 ef             	or     rdi,r13
 284:	48 c1 e6 10          	shl    rsi,0x10
 288:	4c 0f b6 41 04       	movzx  r8,BYTE PTR [rcx+0x4]
 28d:	48 09 f7             	or     rdi,rsi
 290:	49 c1 e0 18          	shl    r8,0x18
 294:	4c 09 c7             	or     rdi,r8
 297:	49 c1 e6 10          	shl    r14,0x10
 29b:	4c 31 f7             	xor    rdi,r14
 29e:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 2a2:	48 01 f7             	add    rdi,rsi
 2a5:	e9 55 fe ff ff       	jmp    0xff
 2aa:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 2ae:	c1 e6 08             	shl    esi,0x8
 2b1:	44 8b 6d d8          	mov    r13d,DWORD PTR [rbp-0x28]
 2b5:	44 09 ee             	or     esi,r13d
 2b8:	49 89 d5             	mov    r13,rdx
 2bb:	49 c1 e5 28          	shl    r13,0x28
 2bf:	48 c1 e0 30          	shl    rax,0x30
 2c3:	4c 09 e8             	or     rax,r13
 2c6:	49 89 f5             	mov    r13,rsi
 2c9:	49 81 e5 ff ff 00 00 	and    r13,0xffff
 2d0:	49 c1 e5 18          	shl    r13,0x18
 2d4:	4c 09 e8             	or     rax,r13
 2d7:	4c 09 c0             	or     rax,r8
 2da:	41 89 f0             	mov    r8d,esi
 2dd:	41 83 e0 02          	and    r8d,0x2
 2e1:	45 85 c0             	test   r8d,r8d
 2e4:	74 40                	je     0x326
 2e6:	85 d2                	test   edx,edx
 2e8:	74 3c                	je     0x326
 2ea:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
 2ee:	48 c1 e2 38          	shl    rdx,0x38
 2f2:	48 8b 7d 90          	mov    rdi,QWORD PTR [rbp-0x70]
 2f6:	48 c1 e7 30          	shl    rdi,0x30
 2fa:	48 09 d7             	or     rdi,rdx
 2fd:	48 09 df             	or     rdi,rbx
 300:	4c 8b 6d e8          	mov    r13,QWORD PTR [rbp-0x18]
 304:	41 83 e5 07          	and    r13d,0x7
 308:	45 89 e8             	mov    r8d,r13d
 30b:	41 83 f0 3f          	xor    r8d,0x3f
 30f:	48 89 fb             	mov    rbx,rdi
 312:	c4 e2 bb f7 db       	shrx   rbx,rbx,r8
 317:	41 83 c5 01          	add    r13d,0x1
 31b:	c4 e2 91 f7 ff       	shlx   rdi,rdi,r13
 320:	48 09 df             	or     rdi,rbx
 323:	48 31 f8             	xor    rax,rdi
 326:	81 e6 ff ff 00 00    	and    esi,0xffff
 32c:	83 e6 04             	and    esi,0x4
 32f:	31 ff                	xor    edi,edi
 331:	48 8b 5d e0          	mov    rbx,QWORD PTR [rbp-0x20]
 335:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 339:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 33d:	85 f6                	test   esi,esi
 33f:	74 53                	je     0x394
 341:	49 c1 e7 08          	shl    r15,0x8
 345:	48 8b 7d a8          	mov    rdi,QWORD PTR [rbp-0x58]
 349:	48 c1 e7 18          	shl    rdi,0x18
 34d:	48 8b 75 c8          	mov    rsi,QWORD PTR [rbp-0x38]
 351:	48 c1 e6 10          	shl    rsi,0x10
 355:	4c 8b 45 a0          	mov    r8,QWORD PTR [rbp-0x60]
 359:	4d 09 c7             	or     r15,r8
 35c:	48 09 fe             	or     rsi,rdi
 35f:	4c 8b 45 b0          	mov    r8,QWORD PTR [rbp-0x50]
 363:	49 c1 e0 28          	shl    r8,0x28
 367:	48 8b 7d d0          	mov    rdi,QWORD PTR [rbp-0x30]
 36b:	48 c1 e7 20          	shl    rdi,0x20
 36f:	4c 09 fe             	or     rsi,r15
 372:	4c 09 c7             	or     rdi,r8
 375:	4c 8b 6d b8          	mov    r13,QWORD PTR [rbp-0x48]
 379:	49 c1 e5 38          	shl    r13,0x38
 37d:	4c 8b 45 c0          	mov    r8,QWORD PTR [rbp-0x40]
 381:	49 c1 e0 30          	shl    r8,0x30
 385:	48 09 f7             	or     rdi,rsi
 388:	4d 09 e8             	or     r8,r13
 38b:	49 09 f8             	or     r8,rdi
 38e:	4d 31 f0             	xor    r8,r14
 391:	4c 89 c7             	mov    rdi,r8
 394:	48 01 f8             	add    rax,rdi
 397:	89 d7                	mov    edi,edx
 399:	83 e7 07             	and    edi,0x7
 39c:	89 fe                	mov    esi,edi
 39e:	83 f6 3f             	xor    esi,0x3f
 3a1:	49 89 c0             	mov    r8,rax
 3a4:	c4 42 cb f7 c0       	shrx   r8,r8,rsi
 3a9:	83 c7 01             	add    edi,0x1
 3ac:	c4 e2 c1 f7 c0       	shlx   rax,rax,rdi
 3b1:	4c 09 c0             	or     rax,r8
 3b4:	48 31 d8             	xor    rax,rbx
 3b7:	49 89 c7             	mov    r15,rax
 3ba:	e9 47 fd ff ff       	jmp    0x106
 3bf:	b8 37 00 00 00       	mov    eax,0x37
 3c4:	eb 0e                	jmp    0x3d4
 3c6:	b8 41 00 00 00       	mov    eax,0x41
 3cb:	eb 07                	jmp    0x3d4
 3cd:	31 c0                	xor    eax,eax
 3cf:	be 01 00 00 00       	mov    esi,0x1
 3d4:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 3d8:	4c 09 f3             	or     rbx,r14
 3db:	ba 01 00 00 00       	mov    edx,0x1
 3e0:	41 81 fe 62 61 73 68 	cmp    r14d,0x68736162
 3e7:	0f 84 d1 fc ff ff    	je     0xbe
 3ed:	41 81 fe 63 75 72 6c 	cmp    r14d,0x6c727563
 3f4:	75 0a                	jne    0x400
 3f6:	ba 02 00 00 00       	mov    edx,0x2
 3fb:	e9 be fc ff ff       	jmp    0xbe
 400:	ba 03 00 00 00       	mov    edx,0x3
 405:	49 bd 70 79 74 68 6f 	movabs r13,0x6e6f68747970
 40c:	6e 00 00 
 40f:	4c 39 eb             	cmp    rbx,r13
 412:	0f 84 a6 fc ff ff    	je     0xbe
 418:	ba 04 00 00 00       	mov    edx,0x4
 41d:	49 81 f8 73 68 00 00 	cmp    r8,0x6873
 424:	0f 84 94 fc ff ff    	je     0xbe
 42a:	31 d2                	xor    edx,edx
 42c:	e9 8d fc ff ff       	jmp    0xbe
 431:	48 8b 75 88          	mov    rsi,QWORD PTR [rbp-0x78]
 435:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 439:	4c 89 ff             	mov    rdi,r15
 43c:	48 c1 ef 38          	shr    rdi,0x38
 440:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 444:	4c 89 ff             	mov    rdi,r15
 447:	48 c1 ef 30          	shr    rdi,0x30
 44b:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 44f:	4c 89 ff             	mov    rdi,r15
 452:	48 c1 ef 28          	shr    rdi,0x28
 456:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 45a:	4c 89 ff             	mov    rdi,r15
 45d:	48 c1 ef 20          	shr    rdi,0x20
 461:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 465:	4c 89 ff             	mov    rdi,r15
 468:	48 c1 ef 18          	shr    rdi,0x18
 46c:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 470:	4c 89 ff             	mov    rdi,r15
 473:	48 c1 ef 10          	shr    rdi,0x10
 477:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 47b:	49 c1 ef 08          	shr    r15,0x8
 47f:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 483:	b8 02 00 00 00       	mov    eax,0x2
 488:	41 5f                	pop    r15
 48a:	41 5e                	pop    r14
 48c:	41 5d                	pop    r13
 48e:	5b                   	pop    rbx
 48f:	c9                   	leave
 490:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
