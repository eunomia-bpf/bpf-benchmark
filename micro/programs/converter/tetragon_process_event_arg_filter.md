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
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 b6 04 00 00    	ja     0x4e3
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 a6 04 00 00    	ja     0x4e3
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 93 04 00 00    	ja     0x4e3
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 83 ff 20          	cmp    rdi,0x20
  85:	0f 85 58 04 00 00    	jne    0x4e3
  8b:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  90:	48 c1 e7 08          	shl    rdi,0x8
  94:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  99:	48 09 f7             	or     rdi,rsi
  9c:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  a1:	48 c1 e6 10          	shl    rsi,0x10
  a5:	48 09 f7             	or     rdi,rsi
  a8:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  ad:	48 c1 e6 18          	shl    rsi,0x18
  b1:	48 09 f7             	or     rdi,rsi
  b4:	48 c1 e7 20          	shl    rdi,0x20
  b8:	48 c1 ef 20          	shr    rdi,0x20
  bc:	48 83 ff 20          	cmp    rdi,0x20
  c0:	0f 85 1d 04 00 00    	jne    0x4e3
  c6:	49 bf db 28 b4 a0 d1 	movabs r15,0xe7037ed1a0b428db
  cd:	7e 03 e7 
  d0:	48 89 55 88          	mov    QWORD PTR [rbp-0x78],rdx
  d4:	48 89 d1             	mov    rcx,rdx
  d7:	31 d2                	xor    edx,edx
  d9:	48 83 c1 17          	add    rcx,0x17
  dd:	eb 60                	jmp    0x13f
  df:	4c 0f b6 41 fa       	movzx  r8,BYTE PTR [rcx-0x6]
  e4:	49 c1 e0 08          	shl    r8,0x8
  e8:	48 0f b6 59 f9       	movzx  rbx,BYTE PTR [rcx-0x7]
  ed:	49 09 d8             	or     r8,rbx
  f0:	48 0f b6 59 fb       	movzx  rbx,BYTE PTR [rcx-0x5]
  f5:	48 c1 e3 10          	shl    rbx,0x10
  f9:	49 09 d8             	or     r8,rbx
  fc:	48 0f b6 59 fc       	movzx  rbx,BYTE PTR [rcx-0x4]
 101:	48 c1 e3 18          	shl    rbx,0x18
 105:	49 09 d8             	or     r8,rbx
 108:	48 85 ff             	test   rdi,rdi
 10b:	0f 84 a4 00 00 00    	je     0x1b5
 111:	49 c1 e0 20          	shl    r8,0x20
 115:	49 c1 e8 20          	shr    r8,0x20
 119:	49 81 e5 ff ff 00 00 	and    r13,0xffff
 120:	49 c1 e5 20          	shl    r13,0x20
 124:	4d 09 c5             	or     r13,r8
 127:	4d 31 fd             	xor    r13,r15
 12a:	4d 89 ef             	mov    r15,r13
 12d:	48 83 c1 20          	add    rcx,0x20
 131:	48 83 c2 01          	add    rdx,0x1
 135:	48 83 fa 20          	cmp    rdx,0x20
 139:	0f 84 4d 03 00 00    	je     0x48c
 13f:	4c 0f b6 69 06       	movzx  r13,BYTE PTR [rcx+0x6]
 144:	49 c1 e5 08          	shl    r13,0x8
 148:	48 0f b6 79 05       	movzx  rdi,BYTE PTR [rcx+0x5]
 14d:	49 09 fd             	or     r13,rdi
 150:	4c 89 ee             	mov    rsi,r13
 153:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 15a:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
 15e:	48 83 fe 04          	cmp    rsi,0x4
 162:	7f 26                	jg     0x18a
 164:	b8 11 00 00 00       	mov    eax,0x11
 169:	31 ff                	xor    edi,edi
 16b:	48 83 fe 01          	cmp    rsi,0x1
 16f:	0f 84 80 02 00 00    	je     0x3f5
 175:	48 83 fe 02          	cmp    rsi,0x2
 179:	74 05                	je     0x180
 17b:	e9 6e 02 00 00       	jmp    0x3ee
 180:	b8 23 00 00 00       	mov    eax,0x23
 185:	e9 6b 02 00 00       	jmp    0x3f5
 18a:	48 83 fe 05          	cmp    rsi,0x5
 18e:	0f 84 48 02 00 00    	je     0x3dc
 194:	48 83 fe 09          	cmp    rsi,0x9
 198:	0f 84 47 02 00 00    	je     0x3e5
 19e:	48 83 fe 0d          	cmp    rsi,0xd
 1a2:	74 05                	je     0x1a9
 1a4:	e9 45 02 00 00       	jmp    0x3ee
 1a9:	b8 59 00 00 00       	mov    eax,0x59
 1ae:	31 ff                	xor    edi,edi
 1b0:	e9 40 02 00 00       	jmp    0x3f5
 1b5:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
 1b9:	48 89 55 e0          	mov    QWORD PTR [rbp-0x20],rdx
 1bd:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 1c1:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 1c6:	48 89 7d a8          	mov    QWORD PTR [rbp-0x58],rdi
 1ca:	48 0f b6 79 0a       	movzx  rdi,BYTE PTR [rcx+0xa]
 1cf:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
 1d3:	48 0f b6 79 0c       	movzx  rdi,BYTE PTR [rcx+0xc]
 1d8:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 1dc:	48 0f b6 79 0b       	movzx  rdi,BYTE PTR [rcx+0xb]
 1e1:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 1e5:	4c 0f b6 69 fe       	movzx  r13,BYTE PTR [rcx-0x2]
 1ea:	49 c1 e5 08          	shl    r13,0x8
 1ee:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
 1f3:	49 09 fd             	or     r13,rdi
 1f6:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 1fb:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 1ff:	48 0f b6 79 0d       	movzx  rdi,BYTE PTR [rcx+0xd]
 204:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 208:	4c 0f b6 79 01       	movzx  r15,BYTE PTR [rcx+0x1]
 20d:	48 0f b6 79 ff       	movzx  rdi,BYTE PTR [rcx-0x1]
 212:	48 c1 e7 10          	shl    rdi,0x10
 216:	49 09 fd             	or     r13,rdi
 219:	48 0f b6 79 10       	movzx  rdi,BYTE PTR [rcx+0x10]
 21e:	48 89 7d b0          	mov    QWORD PTR [rbp-0x50],rdi
 222:	48 0f b6 79 0f       	movzx  rdi,BYTE PTR [rcx+0xf]
 227:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 22b:	48 0f b6 59 08       	movzx  rbx,BYTE PTR [rcx+0x8]
 230:	48 0f b6 51 00       	movzx  rdx,BYTE PTR [rcx+0x0]
 235:	48 c1 e2 18          	shl    rdx,0x18
 239:	48 0f b6 79 18       	movzx  rdi,BYTE PTR [rcx+0x18]
 23e:	48 89 7d 90          	mov    QWORD PTR [rbp-0x70],rdi
 242:	48 0f b6 79 17       	movzx  rdi,BYTE PTR [rcx+0x17]
 247:	48 0f b6 41 07       	movzx  rax,BYTE PTR [rcx+0x7]
 24c:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
 250:	49 09 d5             	or     r13,rdx
 253:	49 83 ff 42          	cmp    r15,0x42
 257:	74 53                	je     0x2ac
 259:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 25d:	48 83 e2 24          	and    rdx,0x24
 261:	48 85 d2             	test   rdx,rdx
 264:	75 46                	jne    0x2ac
 266:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 26b:	48 c1 e7 08          	shl    rdi,0x8
 26f:	4c 09 ff             	or     rdi,r15
 272:	48 0f b6 71 03       	movzx  rsi,BYTE PTR [rcx+0x3]
 277:	48 c1 e6 10          	shl    rsi,0x10
 27b:	48 09 f7             	or     rdi,rsi
 27e:	48 0f b6 71 04       	movzx  rsi,BYTE PTR [rcx+0x4]
 283:	48 c1 e6 18          	shl    rsi,0x18
 287:	48 09 f7             	or     rdi,rsi
 28a:	49 c1 e5 20          	shl    r13,0x20
 28e:	49 c1 ed 20          	shr    r13,0x20
 292:	49 c1 e5 10          	shl    r13,0x10
 296:	4c 31 ef             	xor    rdi,r13
 299:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 29d:	48 01 f7             	add    rdi,rsi
 2a0:	49 89 ff             	mov    r15,rdi
 2a3:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 2a7:	e9 81 fe ff ff       	jmp    0x12d
 2ac:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 2b0:	48 c1 e3 08          	shl    rbx,0x8
 2b4:	48 8b 55 a0          	mov    rdx,QWORD PTR [rbp-0x60]
 2b8:	48 09 d3             	or     rbx,rdx
 2bb:	48 89 f2             	mov    rdx,rsi
 2be:	48 c1 e2 28          	shl    rdx,0x28
 2c2:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
 2c6:	48 c1 e0 30          	shl    rax,0x30
 2ca:	48 09 d0             	or     rax,rdx
 2cd:	49 89 df             	mov    r15,rbx
 2d0:	49 81 e7 ff ff 00 00 	and    r15,0xffff
 2d7:	4c 89 fa             	mov    rdx,r15
 2da:	48 c1 e2 18          	shl    rdx,0x18
 2de:	48 09 d0             	or     rax,rdx
 2e1:	49 c1 e0 20          	shl    r8,0x20
 2e5:	49 c1 e8 20          	shr    r8,0x20
 2e9:	4c 09 c0             	or     rax,r8
 2ec:	48 83 e3 02          	and    rbx,0x2
 2f0:	48 85 db             	test   rbx,rbx
 2f3:	74 45                	je     0x33a
 2f5:	48 c1 e6 20          	shl    rsi,0x20
 2f9:	48 c1 ee 20          	shr    rsi,0x20
 2fd:	48 85 f6             	test   rsi,rsi
 300:	74 38                	je     0x33a
 302:	48 8b 75 90          	mov    rsi,QWORD PTR [rbp-0x70]
 306:	48 c1 e6 38          	shl    rsi,0x38
 30a:	48 c1 e7 30          	shl    rdi,0x30
 30e:	48 09 f7             	or     rdi,rsi
 311:	4c 09 f7             	or     rdi,r14
 314:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
 318:	49 83 e0 07          	and    r8,0x7
 31c:	4c 89 c6             	mov    rsi,r8
 31f:	48 83 f6 3f          	xor    rsi,0x3f
 323:	48 89 fa             	mov    rdx,rdi
 326:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 32b:	49 83 c0 01          	add    r8,0x1
 32f:	c4 e2 b9 f7 ff       	shlx   rdi,rdi,r8
 334:	48 09 d7             	or     rdi,rdx
 337:	48 31 f8             	xor    rax,rdi
 33a:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 33e:	48 c1 e6 08          	shl    rsi,0x8
 342:	48 8b 7d a8          	mov    rdi,QWORD PTR [rbp-0x58]
 346:	48 09 fe             	or     rsi,rdi
 349:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 34d:	48 c1 e2 18          	shl    rdx,0x18
 351:	48 8b 7d d0          	mov    rdi,QWORD PTR [rbp-0x30]
 355:	48 c1 e7 10          	shl    rdi,0x10
 359:	48 09 d7             	or     rdi,rdx
 35c:	48 09 f7             	or     rdi,rsi
 35f:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 363:	48 c1 e2 28          	shl    rdx,0x28
 367:	48 8b 75 c8          	mov    rsi,QWORD PTR [rbp-0x38]
 36b:	48 c1 e6 20          	shl    rsi,0x20
 36f:	48 09 d6             	or     rsi,rdx
 372:	48 09 fe             	or     rsi,rdi
 375:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
 379:	48 c1 e2 38          	shl    rdx,0x38
 37d:	48 8b 7d d8          	mov    rdi,QWORD PTR [rbp-0x28]
 381:	48 c1 e7 30          	shl    rdi,0x30
 385:	48 09 d7             	or     rdi,rdx
 388:	48 09 f7             	or     rdi,rsi
 38b:	49 c1 e5 20          	shl    r13,0x20
 38f:	49 c1 ed 20          	shr    r13,0x20
 393:	4c 31 ef             	xor    rdi,r13
 396:	49 c1 e7 3d          	shl    r15,0x3d
 39a:	49 c1 ff 3f          	sar    r15,0x3f
 39e:	49 21 ff             	and    r15,rdi
 3a1:	4c 01 f8             	add    rax,r15
 3a4:	4c 8b 45 e0          	mov    r8,QWORD PTR [rbp-0x20]
 3a8:	4c 89 c7             	mov    rdi,r8
 3ab:	48 83 e7 07          	and    rdi,0x7
 3af:	48 89 fe             	mov    rsi,rdi
 3b2:	48 83 f6 3f          	xor    rsi,0x3f
 3b6:	48 89 c2             	mov    rdx,rax
 3b9:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 3be:	48 83 c7 01          	add    rdi,0x1
 3c2:	c4 e2 c1 f7 c0       	shlx   rax,rax,rdi
 3c7:	48 09 d0             	or     rax,rdx
 3ca:	4c 89 c2             	mov    rdx,r8
 3cd:	48 8b 7d e8          	mov    rdi,QWORD PTR [rbp-0x18]
 3d1:	48 31 f8             	xor    rax,rdi
 3d4:	49 89 c7             	mov    r15,rax
 3d7:	e9 51 fd ff ff       	jmp    0x12d
 3dc:	b8 37 00 00 00       	mov    eax,0x37
 3e1:	31 ff                	xor    edi,edi
 3e3:	eb 10                	jmp    0x3f5
 3e5:	b8 41 00 00 00       	mov    eax,0x41
 3ea:	31 ff                	xor    edi,edi
 3ec:	eb 07                	jmp    0x3f5
 3ee:	31 c0                	xor    eax,eax
 3f0:	bf 01 00 00 00       	mov    edi,0x1
 3f5:	48 0f b6 71 12       	movzx  rsi,BYTE PTR [rcx+0x12]
 3fa:	48 c1 e6 08          	shl    rsi,0x8
 3fe:	4c 0f b6 41 11       	movzx  r8,BYTE PTR [rcx+0x11]
 403:	4c 09 c6             	or     rsi,r8
 406:	4c 0f b6 41 16       	movzx  r8,BYTE PTR [rcx+0x16]
 40b:	49 c1 e0 28          	shl    r8,0x28
 40f:	4c 0f b6 71 15       	movzx  r14,BYTE PTR [rcx+0x15]
 414:	49 c1 e6 20          	shl    r14,0x20
 418:	4d 09 c6             	or     r14,r8
 41b:	4c 0f b6 41 13       	movzx  r8,BYTE PTR [rcx+0x13]
 420:	49 c1 e0 10          	shl    r8,0x10
 424:	49 09 f0             	or     r8,rsi
 427:	48 0f b6 59 14       	movzx  rbx,BYTE PTR [rcx+0x14]
 42c:	48 c1 e3 18          	shl    rbx,0x18
 430:	4c 09 c3             	or     rbx,r8
 433:	49 09 de             	or     r14,rbx
 436:	be 01 00 00 00       	mov    esi,0x1
 43b:	48 81 fb 62 61 73 68 	cmp    rbx,0x68736162
 442:	0f 84 97 fc ff ff    	je     0xdf
 448:	48 81 fb 63 75 72 6c 	cmp    rbx,0x6c727563
 44f:	75 0a                	jne    0x45b
 451:	be 02 00 00 00       	mov    esi,0x2
 456:	e9 84 fc ff ff       	jmp    0xdf
 45b:	be 03 00 00 00       	mov    esi,0x3
 460:	48 bb 70 79 74 68 6f 	movabs rbx,0x6e6f68747970
 467:	6e 00 00 
 46a:	49 39 de             	cmp    r14,rbx
 46d:	0f 84 6c fc ff ff    	je     0xdf
 473:	be 01 00 00 00       	mov    esi,0x1
 478:	49 81 f8 73 68 00 00 	cmp    r8,0x6873
 47f:	74 02                	je     0x483
 481:	31 f6                	xor    esi,esi
 483:	48 c1 e6 02          	shl    rsi,0x2
 487:	e9 53 fc ff ff       	jmp    0xdf
 48c:	4c 89 ff             	mov    rdi,r15
 48f:	48 c1 ef 38          	shr    rdi,0x38
 493:	48 8b 75 88          	mov    rsi,QWORD PTR [rbp-0x78]
 497:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 49b:	4c 89 ff             	mov    rdi,r15
 49e:	48 c1 ef 30          	shr    rdi,0x30
 4a2:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 4a6:	4c 89 ff             	mov    rdi,r15
 4a9:	48 c1 ef 28          	shr    rdi,0x28
 4ad:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 4b1:	4c 89 ff             	mov    rdi,r15
 4b4:	48 c1 ef 20          	shr    rdi,0x20
 4b8:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 4bc:	4c 89 ff             	mov    rdi,r15
 4bf:	48 c1 ef 18          	shr    rdi,0x18
 4c3:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 4c7:	4c 89 ff             	mov    rdi,r15
 4ca:	48 c1 ef 10          	shr    rdi,0x10
 4ce:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 4d2:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 4d6:	49 c1 ef 08          	shr    r15,0x8
 4da:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 4de:	b8 02 00 00 00       	mov    eax,0x2
 4e3:	41 5f                	pop    r15
 4e5:	41 5e                	pop    r14
 4e7:	41 5d                	pop    r13
 4e9:	5b                   	pop    rbx
 4ea:	c9                   	leave
 4eb:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 37                	mov    esi,DWORD PTR [rdi]
   6:	8b 4f 04             	mov    ecx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 ce                	cmp    esi,ecx
   d:	0f 87 5a 03 00 00    	ja     0x36d
  13:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  17:	48 39 ca             	cmp    rdx,rcx
  1a:	0f 87 4d 03 00 00    	ja     0x36d
  20:	48 8d 96 10 04 00 00 	lea    rdx,[rsi+0x410]
  27:	48 39 ca             	cmp    rdx,rcx
  2a:	0f 87 3d 03 00 00    	ja     0x36d
  30:	83 7e 08 20          	cmp    DWORD PTR [rsi+0x8],0x20
  34:	0f 85 19 03 00 00    	jne    0x353
  3a:	83 7e 0c 20          	cmp    DWORD PTR [rsi+0xc],0x20
  3e:	0f 85 0f 03 00 00    	jne    0x353
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 89 74 24 c0       	mov    QWORD PTR [rsp-0x40],rsi
  53:	48 8d 56 17          	lea    rdx,[rsi+0x17]
  57:	49 bc db 28 b4 a0 d1 	movabs r12,0xe7037ed1a0b428db
  5e:	7e 03 e7 
  61:	31 f6                	xor    esi,esi
  63:	eb 26                	jmp    0x8b
  65:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  6c:	00 00 00 00 
  70:	49 c1 e7 20          	shl    r15,0x20
  74:	4d 09 f9             	or     r9,r15
  77:	4d 31 cc             	xor    r12,r9
  7a:	48 83 c2 20          	add    rdx,0x20
  7e:	48 ff c6             	inc    rsi
  81:	48 83 fe 20          	cmp    rsi,0x20
  85:	0f 84 cb 02 00 00    	je     0x356
  8b:	44 0f b6 7a 06       	movzx  r15d,BYTE PTR [rdx+0x6]
  90:	41 c1 e7 08          	shl    r15d,0x8
  94:	44 0f b6 72 05       	movzx  r14d,BYTE PTR [rdx+0x5]
  99:	4d 09 f7             	or     r15,r14
  9c:	49 83 ff 04          	cmp    r15,0x4
  a0:	76 2e                	jbe    0xd0
  a2:	41 b0 01             	mov    r8b,0x1
  a5:	49 83 ff 05          	cmp    r15,0x5
  a9:	74 75                	je     0x120
  ab:	41 83 ff 09          	cmp    r15d,0x9
  af:	74 63                	je     0x114
  b1:	49 bb 00 00 00 00 00 	movabs r11,0x59000000000000
  b8:	00 59 00 
  bb:	41 83 ff 0d          	cmp    r15d,0xd
  bf:	74 6f                	je     0x130
  c1:	eb 3d                	jmp    0x100
  c3:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  ca:	84 00 00 00 00 00 
  d0:	44 89 f0             	mov    eax,r14d
  d3:	24 07                	and    al,0x7
  d5:	41 b0 01             	mov    r8b,0x1
  d8:	3c 01                	cmp    al,0x1
  da:	74 2c                	je     0x108
  dc:	44 89 f0             	mov    eax,r14d
  df:	83 e0 07             	and    eax,0x7
  e2:	83 f8 02             	cmp    eax,0x2
  e5:	75 19                	jne    0x100
  e7:	49 bb 00 00 00 00 00 	movabs r11,0x23000000000000
  ee:	00 23 00 
  f1:	eb 3d                	jmp    0x130
  f3:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  fa:	84 00 00 00 00 00 
 100:	45 31 c0             	xor    r8d,r8d
 103:	45 31 db             	xor    r11d,r11d
 106:	eb 28                	jmp    0x130
 108:	49 bb 00 00 00 00 00 	movabs r11,0x11000000000000
 10f:	00 11 00 
 112:	eb 1c                	jmp    0x130
 114:	49 bb 00 00 00 00 00 	movabs r11,0x41000000000000
 11b:	00 41 00 
 11e:	eb 10                	jmp    0x130
 120:	49 bb 00 00 00 00 00 	movabs r11,0x37000000000000
 127:	00 37 00 
 12a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
 130:	0f b7 4a 11          	movzx  ecx,WORD PTR [rdx+0x11]
 134:	0f b6 42 16          	movzx  eax,BYTE PTR [rdx+0x16]
 138:	48 c1 e0 28          	shl    rax,0x28
 13c:	44 0f b6 6a 15       	movzx  r13d,BYTE PTR [rdx+0x15]
 141:	49 c1 e5 20          	shl    r13,0x20
 145:	49 09 c5             	or     r13,rax
 148:	0f b6 42 13          	movzx  eax,BYTE PTR [rdx+0x13]
 14c:	c1 e0 10             	shl    eax,0x10
 14f:	48 09 c8             	or     rax,rcx
 152:	0f b6 4a 14          	movzx  ecx,BYTE PTR [rdx+0x14]
 156:	c1 e1 18             	shl    ecx,0x18
 159:	48 09 c1             	or     rcx,rax
 15c:	49 09 cd             	or     r13,rcx
 15f:	48 81 f9 62 61 73 68 	cmp    rcx,0x68736162
 166:	74 18                	je     0x180
 168:	81 f9 63 75 72 6c    	cmp    ecx,0x6c727563
 16e:	75 20                	jne    0x190
 170:	b9 02 00 00 00       	mov    ecx,0x2
 175:	eb 49                	jmp    0x1c0
 177:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
 17e:	00 00 
 180:	b9 01 00 00 00       	mov    ecx,0x1
 185:	eb 39                	jmp    0x1c0
 187:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
 18e:	00 00 
 190:	b9 03 00 00 00       	mov    ecx,0x3
 195:	48 bf 70 79 74 68 6f 	movabs rdi,0x6e6f68747970
 19c:	6e 00 00 
 19f:	49 39 fd             	cmp    r13,rdi
 1a2:	74 1c                	je     0x1c0
 1a4:	31 c9                	xor    ecx,ecx
 1a6:	3d 73 68 00 00       	cmp    eax,0x6873
 1ab:	0f 94 c1             	sete   cl
 1ae:	c1 e1 02             	shl    ecx,0x2
 1b1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 1b8:	0f 1f 84 00 00 00 00 
 1bf:	00 
 1c0:	44 8b 4a f9          	mov    r9d,DWORD PTR [rdx-0x7]
 1c4:	45 84 c0             	test   r8b,r8b
 1c7:	0f 84 a3 fe ff ff    	je     0x70
 1cd:	0f b6 42 09          	movzx  eax,BYTE PTR [rdx+0x9]
 1d1:	48 89 44 24 d0       	mov    QWORD PTR [rsp-0x30],rax
 1d6:	0f b6 42 0a          	movzx  eax,BYTE PTR [rdx+0xa]
 1da:	44 0f b6 52 0c       	movzx  r10d,BYTE PTR [rdx+0xc]
 1df:	0f b6 7a 0b          	movzx  edi,BYTE PTR [rdx+0xb]
 1e3:	48 89 7c 24 d8       	mov    QWORD PTR [rsp-0x28],rdi
 1e8:	0f b6 7a 0e          	movzx  edi,BYTE PTR [rdx+0xe]
 1ec:	48 89 7c 24 e0       	mov    QWORD PTR [rsp-0x20],rdi
 1f1:	0f b6 7a 0d          	movzx  edi,BYTE PTR [rdx+0xd]
 1f5:	48 89 7c 24 f0       	mov    QWORD PTR [rsp-0x10],rdi
 1fa:	0f b6 7a 01          	movzx  edi,BYTE PTR [rdx+0x1]
 1fe:	44 0f b6 42 10       	movzx  r8d,BYTE PTR [rdx+0x10]
 203:	4c 89 44 24 e8       	mov    QWORD PTR [rsp-0x18],r8
 208:	44 0f b6 42 0f       	movzx  r8d,BYTE PTR [rdx+0xf]
 20d:	4c 89 44 24 f8       	mov    QWORD PTR [rsp-0x8],r8
 212:	44 0f b6 42 18       	movzx  r8d,BYTE PTR [rdx+0x18]
 217:	4c 89 44 24 c8       	mov    QWORD PTR [rsp-0x38],r8
 21c:	0f b6 6a 17          	movzx  ebp,BYTE PTR [rdx+0x17]
 220:	0f b6 5a 07          	movzx  ebx,BYTE PTR [rdx+0x7]
 224:	44 8b 7a fd          	mov    r15d,DWORD PTR [rdx-0x3]
 228:	48 83 ff 42          	cmp    rdi,0x42
 22c:	74 42                	je     0x270
 22e:	41 89 c0             	mov    r8d,eax
 231:	41 83 e0 24          	and    r8d,0x24
 235:	75 39                	jne    0x270
 237:	0f b6 42 02          	movzx  eax,BYTE PTR [rdx+0x2]
 23b:	c1 e0 08             	shl    eax,0x8
 23e:	48 09 f8             	or     rax,rdi
 241:	0f b6 4a 03          	movzx  ecx,BYTE PTR [rdx+0x3]
 245:	c1 e1 10             	shl    ecx,0x10
 248:	48 09 c1             	or     rcx,rax
 24b:	0f b6 42 04          	movzx  eax,BYTE PTR [rdx+0x4]
 24f:	c1 e0 18             	shl    eax,0x18
 252:	48 09 c8             	or     rax,rcx
 255:	49 c1 e7 10          	shl    r15,0x10
 259:	49 31 c7             	xor    r15,rax
 25c:	4d 01 fc             	add    r12,r15
 25f:	e9 16 fe ff ff       	jmp    0x7a
 264:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 26b:	00 00 00 00 00 
 270:	4c 89 64 24 b8       	mov    QWORD PTR [rsp-0x48],r12
 275:	44 0f b6 42 08       	movzx  r8d,BYTE PTR [rdx+0x8]
 27a:	48 89 cf             	mov    rdi,rcx
 27d:	48 c1 e7 28          	shl    rdi,0x28
 281:	4c 09 df             	or     rdi,r11
 284:	49 c1 e0 20          	shl    r8,0x20
 288:	41 89 dc             	mov    r12d,ebx
 28b:	41 c1 e4 18          	shl    r12d,0x18
 28f:	4d 09 c4             	or     r12,r8
 292:	4c 09 cf             	or     rdi,r9
 295:	4c 09 e7             	or     rdi,r12
 298:	48 85 c9             	test   rcx,rcx
 29b:	74 36                	je     0x2d3
 29d:	89 d9                	mov    ecx,ebx
 29f:	83 e1 02             	and    ecx,0x2
 2a2:	74 2f                	je     0x2d3
 2a4:	48 8b 4c 24 c8       	mov    rcx,QWORD PTR [rsp-0x38]
 2a9:	48 c1 e1 38          	shl    rcx,0x38
 2ad:	48 c1 e5 30          	shl    rbp,0x30
 2b1:	48 09 cd             	or     rbp,rcx
 2b4:	4c 09 ed             	or     rbp,r13
 2b7:	41 80 e6 07          	and    r14b,0x7
 2bb:	44 89 f1             	mov    ecx,r14d
 2be:	f6 d1                	not    cl
 2c0:	c4 e2 f3 f7 cd       	shrx   rcx,rbp,rcx
 2c5:	41 fe c6             	inc    r14b
 2c8:	c4 62 89 f7 c5       	shlx   r8,rbp,r14
 2cd:	49 09 c8             	or     r8,rcx
 2d0:	4c 31 c7             	xor    rdi,r8
 2d3:	4c 8b 64 24 b8       	mov    r12,QWORD PTR [rsp-0x48]
 2d8:	c1 e0 08             	shl    eax,0x8
 2db:	48 03 44 24 d0       	add    rax,QWORD PTR [rsp-0x30]
 2e0:	41 c1 e2 18          	shl    r10d,0x18
 2e4:	49 09 c2             	or     r10,rax
 2e7:	4c 8b 44 24 d8       	mov    r8,QWORD PTR [rsp-0x28]
 2ec:	41 c1 e0 10          	shl    r8d,0x10
 2f0:	4d 09 d0             	or     r8,r10
 2f3:	48 8b 4c 24 e0       	mov    rcx,QWORD PTR [rsp-0x20]
 2f8:	48 c1 e1 28          	shl    rcx,0x28
 2fc:	4c 09 c1             	or     rcx,r8
 2ff:	48 8b 44 24 f0       	mov    rax,QWORD PTR [rsp-0x10]
 304:	48 c1 e0 20          	shl    rax,0x20
 308:	48 09 c8             	or     rax,rcx
 30b:	48 8b 4c 24 e8       	mov    rcx,QWORD PTR [rsp-0x18]
 310:	48 c1 e1 38          	shl    rcx,0x38
 314:	48 09 c1             	or     rcx,rax
 317:	48 8b 44 24 f8       	mov    rax,QWORD PTR [rsp-0x8]
 31c:	48 c1 e0 30          	shl    rax,0x30
 320:	48 09 c8             	or     rax,rcx
 323:	49 31 c7             	xor    r15,rax
 326:	48 c1 e3 3d          	shl    rbx,0x3d
 32a:	48 c1 fb 3f          	sar    rbx,0x3f
 32e:	4c 21 fb             	and    rbx,r15
 331:	48 01 fb             	add    rbx,rdi
 334:	89 f0                	mov    eax,esi
 336:	24 07                	and    al,0x7
 338:	89 c1                	mov    ecx,eax
 33a:	f6 d1                	not    cl
 33c:	c4 e2 f3 f7 cb       	shrx   rcx,rbx,rcx
 341:	fe c0                	inc    al
 343:	c4 e2 f9 f7 c3       	shlx   rax,rbx,rax
 348:	48 09 c8             	or     rax,rcx
 34b:	49 31 c4             	xor    r12,rax
 34e:	e9 27 fd ff ff       	jmp    0x7a
 353:	31 c0                	xor    eax,eax
 355:	c3                   	ret
 356:	48 8b 44 24 c0       	mov    rax,QWORD PTR [rsp-0x40]
 35b:	4c 89 20             	mov    QWORD PTR [rax],r12
 35e:	b8 02 00 00 00       	mov    eax,0x2
 363:	5b                   	pop    rbx
 364:	41 5c                	pop    r12
 366:	41 5d                	pop    r13
 368:	41 5e                	pop    r14
 36a:	41 5f                	pop    r15
 36c:	5d                   	pop    rbp
 36d:	c3                   	ret
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
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <tetragon_process_event_arg_filter_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_2, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-3) - 1, 0),
    /* 0x1118: lea    rdx,[rsi+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi+0x8],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1128: jne    110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x112a: cmp    DWORD PTR [rsi+0xc],0x20 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x112e: jne    110e <tetragon_process_event_arg_filter_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 32),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-20) - 1),
    /* 0x1130: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r13 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1139: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113a: sub    rsp,0x40 [exact-kinsn: sub64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 64), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x113e: mov    QWORD PTR [rsp+0x10],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1143: lea    rdi,[rsi+0x2f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1147: movabs r11,0xe7037ed1a0b428db [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xe7037ed1a0b428dbULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -424),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1151: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1154: jmp    117e <tetragon_process_event_arg_filter_xdp+0x7e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (14) - 1),
    /* 0x1156: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x1160: shl    rcx,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1164: mov    eax,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1167: or     rax,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x116a: xor    r11,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x116d: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1170: add    rdi,0x20 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1174: cmp    r8,0x20 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1178: je     1406 <tetragon_process_event_arg_filter_xdp+0x306> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, (325) - 1, 32),
    /* 0x117e: movzx  r14d,BYTE PTR [rdi-0x13] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -19), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1183: movzx  ecx,BYTE PTR [rdi-0x12] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -18), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1187: shl    ecx,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x118a: or     rcx,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x118d: cmp    ecx,0x4 [absorbed-control-flow: cmp folded into following ordinary BPF jle] */
    /* 0x1190: jle    11b0 <tetragon_process_event_arg_filter_xdp+0xb0> [exact-bpf: jle ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_4, 0, (12) - 1, 4),
    /* 0x1192: cmp    ecx,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1195: je     11c8 <tetragon_process_event_arg_filter_xdp+0xc8> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_4, 0, (21) - 1, 5),
    /* 0x1197: cmp    ecx,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x119a: je     11d6 <tetragon_process_event_arg_filter_xdp+0xd6> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_4, 0, (28) - 1, 9),
    /* 0x119c: cmp    ecx,0xd [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x119f: jne    11f2 <tetragon_process_event_arg_filter_xdp+0xf2> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_4, 0, (43) - 1, 13),
    /* 0x11a1: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11a3: movabs r12,0x59000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x59000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11ad: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (39) - 1),
    /* 0x11af: nop [padding: padding is not part of BPF semantics] */
    /* 0x11b0: cmp    ecx,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11b3: je     11e4 <tetragon_process_event_arg_filter_xdp+0xe4> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_4, 0, (26) - 1, 1),
    /* 0x11b5: cmp    ecx,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11b8: jne    11f2 <tetragon_process_event_arg_filter_xdp+0xf2> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_4, 0, (33) - 1, 2),
    /* 0x11ba: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bc: movabs r12,0x23000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x23000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11c6: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (29) - 1),
    /* 0x11c8: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11ca: movabs r12,0x37000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x37000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11d4: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (21) - 1),
    /* 0x11d6: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11d8: movabs r12,0x41000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x41000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11e2: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (13) - 1),
    /* 0x11e4: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e6: movabs r12,0x11000000000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x11000000000000ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -416),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11f0: jmp    1200 <tetragon_process_event_arg_filter_xdp+0x100> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (5) - 1),
    /* 0x11f2: mov    dl,0x1 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11f4: xor    r12d,r12d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11f7: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1200: movzx  esi,WORD PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1204: movzx  r9d,BYTE PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1209: shl    r9d,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x120d: or     r9,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1210: movzx  esi,BYTE PTR [rdi-0x4] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_2, BPF_REG_1, -4), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1214: shl    esi,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1217: or     rsi,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x121a: movzx  r10d,BYTE PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x121f: shl    r10,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1223: movzx  ebx,BYTE PTR [rdi-0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -2), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1227: shl    rbx,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x122b: or     rbx,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x122e: or     rbx,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1231: cmp    rsi,0x68736162 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1238: je     1250 <tetragon_process_event_arg_filter_xdp+0x150> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_2, 0, (5) - 1, 1752392034),
    /* 0x123a: cmp    esi,0x6c727563 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1240: jne    1260 <tetragon_process_event_arg_filter_xdp+0x160> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (7) - 1, 1819440483),
    /* 0x1242: mov    esi,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1247: jmp    1290 <tetragon_process_event_arg_filter_xdp+0x190> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (17) - 1),
    /* 0x1249: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: mov    esi,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1255: jmp    1290 <tetragon_process_event_arg_filter_xdp+0x190> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (14) - 1),
    /* 0x1257: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1260: mov    esi,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1265: movabs rax,0x6e6f68747970 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x6e6f68747970ULL),
    /* 0x126f: cmp    rbx,rax [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1272: je     1290 <tetragon_process_event_arg_filter_xdp+0x190> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_X, BPF_REG_6, BPF_REG_0, (9) - 1, 0),
    /* 0x1274: xor    esi,esi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1276: cmp    r9d,0x6873 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R9, 26739), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x127d: sete   sil [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_STACK_PAYLOAD(BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_SETE),
    /* 0x1281: shl    esi,0x2 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1284: data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1290: mov    r15d,DWORD PTR [rdi-0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -31), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1294: test   dl,dl [absorbed-control-flow: test folded into following ordinary BPF jne] */
    /* 0x1296: jne    1160 <tetragon_process_event_arg_filter_xdp+0x60> [exact-bpf: jne ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_3),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 255),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-127) - 1),
    /* 0x129c: mov    rcx,r12 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x129f: mov    QWORD PTR [rsp+0x20],r14 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_8, HC_X86_RSP, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12a4: mov    QWORD PTR [rsp],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12a8: movzx  r11d,BYTE PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_1, -23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ad: movzx  eax,BYTE PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12b1: mov    QWORD PTR [rsp+0x28],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 40), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12b6: movzx  ebp,BYTE PTR [rdi-0xe] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12ba: movzx  eax,BYTE PTR [rdi-0xd] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12be: mov    DWORD PTR [rsp+0xc],eax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c2: movzx  r13d,BYTE PTR [rdi-0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_7, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12c7: movzx  eax,BYTE PTR [rdi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12cb: mov    QWORD PTR [rsp+0x30],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12d0: movzx  r9d,BYTE PTR [rdi-0xa] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d5: movzx  eax,BYTE PTR [rdi-0x9] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d9: mov    QWORD PTR [rsp+0x38],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12de: movzx  r10d,BYTE PTR [rdi-0x8] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e3: movzx  eax,BYTE PTR [rdi-0x1] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -1), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12e7: mov    QWORD PTR [rsp+0x18],rax [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12ec: movzx  r14d,BYTE PTR [rdi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12f0: movzx  edx,WORD PTR [rdi-0x11] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, -17), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12f4: mov    r12d,DWORD PTR [rdi-0x1b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R12, BPF_REG_1, -27), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f8: cmp    r11b,0x42 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12fc: je     1330 <tetragon_process_event_arg_filter_xdp+0x230> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 66),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (27) - 1),
    /* 0x12fe: mov    eax,ebp [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_0, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1300: and    eax,0x24 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 36), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1303: jne    1330 <tetragon_process_event_arg_filter_xdp+0x230> [exact-bpf: jne ordinary BPF branch from preceding and] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_0, 0, (22) - 1, -1),
    /* 0x1305: movzx  eax,BYTE PTR [rdi-0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1309: shl    eax,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130c: movzx  ecx,WORD PTR [rdi-0x15] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -21), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1310: shl    ecx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1313: or     rax,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1316: or     rax,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1319: shl    r12,0x10 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 16), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x131d: xor    r12,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1320: mov    r11,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1324: add    r11,r12 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1327: jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-195) - 1),
    /* 0x132c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1330: mov    rax,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1333: shl    rax,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1337: or     rax,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x133a: mov    r11,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x133d: shl    r11,0x18 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 24), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1341: or     r11,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1344: mov    r15d,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1347: or     r15,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x134a: movzx  ecx,dx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x134d: test   cl,0x2 [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x1350: je     1391 <tetragon_process_event_arg_filter_xdp+0x291> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_4),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (43) - 1),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1352: test   esi,esi [exact-kinsn: testl reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_TESTL),
    /* 0x1354: mov    r11,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1358: je     1395 <tetragon_process_event_arg_filter_xdp+0x295> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_2, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (38) - 1),
    /* 0x135a: mov    rax,QWORD PTR [rsp+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 24), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x135f: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1363: shl    r14,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_8, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1367: or     r14,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x136a: or     r14,rbx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x136d: mov    rdx,QWORD PTR [rsp+0x20] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, HC_X86_RSP, 32), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1372: and    dl,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1375: mov    esi,ecx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1377: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x137a: mov    rax,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x137d: shl    rax,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1380: not    dl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1382: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1384: shr    r14,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1387: mov    ecx,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1389: or     r14,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x138c: xor    r15,r14 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x138f: jmp    1395 <tetragon_process_event_arg_filter_xdp+0x295> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (3) - 1),
    /* 0x1391: mov    r11,QWORD PTR [rsp] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, HC_X86_RSP, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1395: shl    ebp,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1398: add    rbp,QWORD PTR [rsp+0x28] [exact-kinsn: add64 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RSP, 40), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x139d: mov    eax,DWORD PTR [rsp+0xc] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13a1: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x13a4: shl    r13d,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_7, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x13a8: or     r13d,eax [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x13ab: mov    rax,QWORD PTR [rsp+0x30] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 48), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13b0: shl    rax,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13b4: shl    r9,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13b8: or     r9,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13bb: mov    rax,QWORD PTR [rsp+0x38] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 56), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13c0: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c4: shl    r10,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c8: or     r10,rax [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13cb: or     r13,rbp [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_7, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13ce: or     r13,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13d1: or     r13,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13d4: xor    r12,r13 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13d7: test   cl,0x4 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x13da: mov    edx,0x0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13df: cmovne rdx,r12 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_3, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x13e3: add    rdx,r15 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x13e6: mov    eax,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e9: and    al,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x13eb: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13ee: mov    rsi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13f1: shl    rsi,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13f4: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13f6: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13f8: shr    rdx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13fb: or     rdx,rsi [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13fe: xor    r11,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1401: jmp    116d <tetragon_process_event_arg_filter_xdp+0x6d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-328) - 1),
    /* 0x1406: mov    rax,QWORD PTR [rsp+0x10] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, HC_X86_RSP, 16), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x140b: mov    QWORD PTR [rax],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x140e: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1413: add    rsp,0x40 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_RSP, 64), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1417: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1418: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141a: pop    r13 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141c: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x141e: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1420: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1421: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
