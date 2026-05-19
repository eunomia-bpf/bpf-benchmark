# trace_event_type_switch_dispatch

## Original C
```c
#include "common.h"

#define SWITCH_DISPATCH_COUNT 128U
#define SWITCH_DISPATCH_INPUT_SIZE (4U + SWITCH_DISPATCH_COUNT * 4U)

static __always_inline u32 switch_value(u32 value)
{
    switch (value) {
    case 0: return 56;
    case 1: return 43;
    case 2: return 57;
    case 3: return 28;
    case 4: return 14;
    case 5: return 61;
    case 6: return 10;
    case 7: return 58;
    case 8: return 2;
    case 9: return 63;
    case 10: return 49;
    case 11: return 36;
    case 12: return 19;
    case 13: return 42;
    case 14: return 37;
    case 15: return 46;
    case 16: return 34;
    case 17: return 62;
    case 18: return 47;
    case 19: return 6;
    case 20: return 29;
    case 21: return 21;
    case 22: return 15;
    case 23: return 40;
    case 24: return 38;
    case 25: return 26;
    case 26: return 17;
    case 27: return 41;
    case 28: return 33;
    case 29: return 31;
    case 30: return 23;
    case 31: return 52;
    case 32: return 25;
    case 33: return 39;
    case 34: return 11;
    case 35: return 27;
    case 36: return 53;
    case 37: return 4;
    case 38: return 24;
    case 39: return 48;
    case 40: return 32;
    case 41: return 50;
    case 42: return 7;
    case 43: return 35;
    case 44: return 8;
    case 45: return 44;
    case 46: return 51;
    case 47: return 59;
    case 48: return 45;
    case 49: return 0;
    case 50: return 9;
    case 51: return 3;
    case 52: return 13;
    case 53: return 20;
    case 54: return 30;
    case 55: return 18;
    case 56: return 1;
    case 57: return 54;
    case 58: return 22;
    case 59: return 16;
    case 60: return 60;
    case 61: return 5;
    case 62: return 12;
    case 63: return 55;
    default: return 114514U;
    }
}

static __always_inline int bench_trace_event_type_switch_dispatch(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);

    if (count != SWITCH_DISPATCH_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 4, SWITCH_DISPATCH_COUNT * 4U)) {
        return -1;
    }

    u64 hash = 0;
    for (u32 i = 0; i < SWITCH_DISPATCH_COUNT; i++) {
        hash ^= switch_value(micro_read_u32_le(data, 4 + i * 4U));
    }

    *out = hash;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    trace_event_type_switch_dispatch_xdp,
    bench_trace_event_type_switch_dispatch,
    trace_event_type_switch_dispatch_input_value,
    SWITCH_DISPATCH_INPUT_SIZE)
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

0000000000001100 <trace_event_type_switch_dispatch_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	76 01                	jbe    110f <trace_event_type_switch_dispatch_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1113:	48 39 d6             	cmp    rsi,rdx
    1116:	77 f6                	ja     110e <trace_event_type_switch_dispatch_xdp+0xe>
    1118:	48 8d b9 0c 02 00 00 	lea    rdi,[rcx+0x20c]
    111f:	48 39 d7             	cmp    rdi,rdx
    1122:	77 ea                	ja     110e <trace_event_type_switch_dispatch_xdp+0xe>
    1124:	81 3e 80 00 00 00    	cmp    DWORD PTR [rsi],0x80
    112a:	75 e2                	jne    110e <trace_event_type_switch_dispatch_xdp+0xe>
    112c:	53                   	push   rbx
    112d:	ba 0f 00 00 00       	mov    edx,0xf
    1132:	31 db                	xor    ebx,ebx
    1134:	eb 1e                	jmp    1154 <trace_event_type_switch_dispatch_xdp+0x54>
    1136:	bb 0c 00 00 00       	mov    ebx,0xc
    113b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1140:	48 31 c3             	xor    rbx,rax
    1143:	48 83 c2 04          	add    rdx,0x4
    1147:	48 81 fa 0f 02 00 00 	cmp    rdx,0x20f
    114e:	0f 84 d6 05 00 00    	je     172a <trace_event_type_switch_dispatch_xdp+0x62a>
    1154:	48 89 d8             	mov    rax,rbx
    1157:	8b 74 11 fd          	mov    esi,DWORD PTR [rcx+rdx*1-0x3]
    115b:	83 fe 1f             	cmp    esi,0x1f
    115e:	7f 40                	jg     11a0 <trace_event_type_switch_dispatch_xdp+0xa0>
    1160:	83 fe 0f             	cmp    esi,0xf
    1163:	7f 7b                	jg     11e0 <trace_event_type_switch_dispatch_xdp+0xe0>
    1165:	83 fe 07             	cmp    esi,0x7
    1168:	0f 8f e6 00 00 00    	jg     1254 <trace_event_type_switch_dispatch_xdp+0x154>
    116e:	83 fe 03             	cmp    esi,0x3
    1171:	0f 8f 95 01 00 00    	jg     130c <trace_event_type_switch_dispatch_xdp+0x20c>
    1177:	83 fe 01             	cmp    esi,0x1
    117a:	0f 8f b4 02 00 00    	jg     1434 <trace_event_type_switch_dispatch_xdp+0x334>
    1180:	bb 38 00 00 00       	mov    ebx,0x38
    1185:	85 f6                	test   esi,esi
    1187:	74 b7                	je     1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1189:	83 fe 01             	cmp    esi,0x1
    118c:	0f 85 8e 05 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1192:	bb 2b 00 00 00       	mov    ebx,0x2b
    1197:	eb a7                	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1199:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    11a0:	83 fe 2f             	cmp    esi,0x2f
    11a3:	7f 7b                	jg     1220 <trace_event_type_switch_dispatch_xdp+0x120>
    11a5:	83 fe 27             	cmp    esi,0x27
    11a8:	0f 8f d4 00 00 00    	jg     1282 <trace_event_type_switch_dispatch_xdp+0x182>
    11ae:	83 fe 23             	cmp    esi,0x23
    11b1:	0f 8f 7a 01 00 00    	jg     1331 <trace_event_type_switch_dispatch_xdp+0x231>
    11b7:	83 fe 21             	cmp    esi,0x21
    11ba:	0f 8f 90 02 00 00    	jg     1450 <trace_event_type_switch_dispatch_xdp+0x350>
    11c0:	83 fe 20             	cmp    esi,0x20
    11c3:	0f 84 2b 04 00 00    	je     15f4 <trace_event_type_switch_dispatch_xdp+0x4f4>
    11c9:	83 fe 21             	cmp    esi,0x21
    11cc:	0f 85 4e 05 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    11d2:	bb 27 00 00 00       	mov    ebx,0x27
    11d7:	e9 64 ff ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    11dc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    11e0:	83 fe 17             	cmp    esi,0x17
    11e3:	0f 8f c7 00 00 00    	jg     12b0 <trace_event_type_switch_dispatch_xdp+0x1b0>
    11e9:	83 fe 13             	cmp    esi,0x13
    11ec:	0f 8f 64 01 00 00    	jg     1356 <trace_event_type_switch_dispatch_xdp+0x256>
    11f2:	83 fe 11             	cmp    esi,0x11
    11f5:	0f 8f 71 02 00 00    	jg     146c <trace_event_type_switch_dispatch_xdp+0x36c>
    11fb:	83 fe 10             	cmp    esi,0x10
    11fe:	0f 84 fa 03 00 00    	je     15fe <trace_event_type_switch_dispatch_xdp+0x4fe>
    1204:	83 fe 11             	cmp    esi,0x11
    1207:	0f 85 13 05 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    120d:	bb 3e 00 00 00       	mov    ebx,0x3e
    1212:	e9 29 ff ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1217:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    121e:	00 00 
    1220:	83 fe 37             	cmp    esi,0x37
    1223:	0f 8f b5 00 00 00    	jg     12de <trace_event_type_switch_dispatch_xdp+0x1de>
    1229:	83 fe 33             	cmp    esi,0x33
    122c:	0f 8f 49 01 00 00    	jg     137b <trace_event_type_switch_dispatch_xdp+0x27b>
    1232:	83 fe 31             	cmp    esi,0x31
    1235:	0f 8f 4d 02 00 00    	jg     1488 <trace_event_type_switch_dispatch_xdp+0x388>
    123b:	83 fe 30             	cmp    esi,0x30
    123e:	0f 84 c4 03 00 00    	je     1608 <trace_event_type_switch_dispatch_xdp+0x508>
    1244:	83 fe 31             	cmp    esi,0x31
    1247:	0f 85 d3 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    124d:	31 db                	xor    ebx,ebx
    124f:	e9 ec fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1254:	83 fe 0b             	cmp    esi,0xb
    1257:	0f 8f 43 01 00 00    	jg     13a0 <trace_event_type_switch_dispatch_xdp+0x2a0>
    125d:	83 fe 09             	cmp    esi,0x9
    1260:	0f 8f 3e 02 00 00    	jg     14a4 <trace_event_type_switch_dispatch_xdp+0x3a4>
    1266:	83 fe 08             	cmp    esi,0x8
    1269:	0f 84 a3 03 00 00    	je     1612 <trace_event_type_switch_dispatch_xdp+0x512>
    126f:	83 fe 09             	cmp    esi,0x9
    1272:	0f 85 a8 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1278:	bb 3f 00 00 00       	mov    ebx,0x3f
    127d:	e9 be fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1282:	83 fe 2b             	cmp    esi,0x2b
    1285:	0f 8f 3a 01 00 00    	jg     13c5 <trace_event_type_switch_dispatch_xdp+0x2c5>
    128b:	83 fe 29             	cmp    esi,0x29
    128e:	0f 8f 2c 02 00 00    	jg     14c0 <trace_event_type_switch_dispatch_xdp+0x3c0>
    1294:	83 fe 28             	cmp    esi,0x28
    1297:	0f 84 7f 03 00 00    	je     161c <trace_event_type_switch_dispatch_xdp+0x51c>
    129d:	83 fe 29             	cmp    esi,0x29
    12a0:	0f 85 7a 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    12a6:	bb 32 00 00 00       	mov    ebx,0x32
    12ab:	e9 90 fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    12b0:	83 fe 1b             	cmp    esi,0x1b
    12b3:	0f 8f 31 01 00 00    	jg     13ea <trace_event_type_switch_dispatch_xdp+0x2ea>
    12b9:	83 fe 19             	cmp    esi,0x19
    12bc:	0f 8f 1a 02 00 00    	jg     14dc <trace_event_type_switch_dispatch_xdp+0x3dc>
    12c2:	83 fe 18             	cmp    esi,0x18
    12c5:	0f 84 5b 03 00 00    	je     1626 <trace_event_type_switch_dispatch_xdp+0x526>
    12cb:	83 fe 19             	cmp    esi,0x19
    12ce:	0f 85 4c 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    12d4:	bb 1a 00 00 00       	mov    ebx,0x1a
    12d9:	e9 62 fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    12de:	83 fe 3b             	cmp    esi,0x3b
    12e1:	0f 8f 28 01 00 00    	jg     140f <trace_event_type_switch_dispatch_xdp+0x30f>
    12e7:	83 fe 39             	cmp    esi,0x39
    12ea:	0f 8f 08 02 00 00    	jg     14f8 <trace_event_type_switch_dispatch_xdp+0x3f8>
    12f0:	83 fe 38             	cmp    esi,0x38
    12f3:	0f 84 37 03 00 00    	je     1630 <trace_event_type_switch_dispatch_xdp+0x530>
    12f9:	83 fe 39             	cmp    esi,0x39
    12fc:	0f 85 1e 04 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1302:	bb 36 00 00 00       	mov    ebx,0x36
    1307:	e9 34 fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    130c:	83 fe 05             	cmp    esi,0x5
    130f:	0f 8f ff 01 00 00    	jg     1514 <trace_event_type_switch_dispatch_xdp+0x414>
    1315:	83 fe 04             	cmp    esi,0x4
    1318:	0f 84 1c 03 00 00    	je     163a <trace_event_type_switch_dispatch_xdp+0x53a>
    131e:	83 fe 05             	cmp    esi,0x5
    1321:	0f 85 f9 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1327:	bb 3d 00 00 00       	mov    ebx,0x3d
    132c:	e9 0f fe ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1331:	83 fe 25             	cmp    esi,0x25
    1334:	0f 8f f6 01 00 00    	jg     1530 <trace_event_type_switch_dispatch_xdp+0x430>
    133a:	83 fe 24             	cmp    esi,0x24
    133d:	0f 84 01 03 00 00    	je     1644 <trace_event_type_switch_dispatch_xdp+0x544>
    1343:	83 fe 25             	cmp    esi,0x25
    1346:	0f 85 d4 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    134c:	bb 04 00 00 00       	mov    ebx,0x4
    1351:	e9 ea fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1356:	83 fe 15             	cmp    esi,0x15
    1359:	0f 8f ed 01 00 00    	jg     154c <trace_event_type_switch_dispatch_xdp+0x44c>
    135f:	83 fe 14             	cmp    esi,0x14
    1362:	0f 84 e6 02 00 00    	je     164e <trace_event_type_switch_dispatch_xdp+0x54e>
    1368:	83 fe 15             	cmp    esi,0x15
    136b:	0f 85 af 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1371:	bb 15 00 00 00       	mov    ebx,0x15
    1376:	e9 c5 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    137b:	83 fe 35             	cmp    esi,0x35
    137e:	0f 8f e4 01 00 00    	jg     1568 <trace_event_type_switch_dispatch_xdp+0x468>
    1384:	83 fe 34             	cmp    esi,0x34
    1387:	0f 84 cb 02 00 00    	je     1658 <trace_event_type_switch_dispatch_xdp+0x558>
    138d:	83 fe 35             	cmp    esi,0x35
    1390:	0f 85 8a 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1396:	bb 14 00 00 00       	mov    ebx,0x14
    139b:	e9 a0 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    13a0:	83 fe 0d             	cmp    esi,0xd
    13a3:	0f 8f db 01 00 00    	jg     1584 <trace_event_type_switch_dispatch_xdp+0x484>
    13a9:	83 fe 0c             	cmp    esi,0xc
    13ac:	0f 84 b0 02 00 00    	je     1662 <trace_event_type_switch_dispatch_xdp+0x562>
    13b2:	83 fe 0d             	cmp    esi,0xd
    13b5:	0f 85 65 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    13bb:	bb 2a 00 00 00       	mov    ebx,0x2a
    13c0:	e9 7b fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    13c5:	83 fe 2d             	cmp    esi,0x2d
    13c8:	0f 8f d2 01 00 00    	jg     15a0 <trace_event_type_switch_dispatch_xdp+0x4a0>
    13ce:	83 fe 2c             	cmp    esi,0x2c
    13d1:	0f 84 95 02 00 00    	je     166c <trace_event_type_switch_dispatch_xdp+0x56c>
    13d7:	83 fe 2d             	cmp    esi,0x2d
    13da:	0f 85 40 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    13e0:	bb 2c 00 00 00       	mov    ebx,0x2c
    13e5:	e9 56 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    13ea:	83 fe 1d             	cmp    esi,0x1d
    13ed:	0f 8f c9 01 00 00    	jg     15bc <trace_event_type_switch_dispatch_xdp+0x4bc>
    13f3:	83 fe 1c             	cmp    esi,0x1c
    13f6:	0f 84 7a 02 00 00    	je     1676 <trace_event_type_switch_dispatch_xdp+0x576>
    13fc:	83 fe 1d             	cmp    esi,0x1d
    13ff:	0f 85 1b 03 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1405:	bb 1f 00 00 00       	mov    ebx,0x1f
    140a:	e9 31 fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    140f:	83 fe 3d             	cmp    esi,0x3d
    1412:	0f 8f c0 01 00 00    	jg     15d8 <trace_event_type_switch_dispatch_xdp+0x4d8>
    1418:	83 fe 3c             	cmp    esi,0x3c
    141b:	0f 84 5f 02 00 00    	je     1680 <trace_event_type_switch_dispatch_xdp+0x580>
    1421:	83 fe 3d             	cmp    esi,0x3d
    1424:	0f 85 f6 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    142a:	bb 05 00 00 00       	mov    ebx,0x5
    142f:	e9 0c fd ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1434:	83 fe 02             	cmp    esi,0x2
    1437:	0f 84 4d 02 00 00    	je     168a <trace_event_type_switch_dispatch_xdp+0x58a>
    143d:	83 fe 03             	cmp    esi,0x3
    1440:	0f 85 da 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1446:	bb 1c 00 00 00       	mov    ebx,0x1c
    144b:	e9 f0 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1450:	83 fe 22             	cmp    esi,0x22
    1453:	0f 84 3b 02 00 00    	je     1694 <trace_event_type_switch_dispatch_xdp+0x594>
    1459:	83 fe 23             	cmp    esi,0x23
    145c:	0f 85 be 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1462:	bb 1b 00 00 00       	mov    ebx,0x1b
    1467:	e9 d4 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    146c:	83 fe 12             	cmp    esi,0x12
    146f:	0f 84 29 02 00 00    	je     169e <trace_event_type_switch_dispatch_xdp+0x59e>
    1475:	83 fe 13             	cmp    esi,0x13
    1478:	0f 85 a2 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    147e:	bb 06 00 00 00       	mov    ebx,0x6
    1483:	e9 b8 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1488:	83 fe 32             	cmp    esi,0x32
    148b:	0f 84 17 02 00 00    	je     16a8 <trace_event_type_switch_dispatch_xdp+0x5a8>
    1491:	83 fe 33             	cmp    esi,0x33
    1494:	0f 85 86 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    149a:	bb 03 00 00 00       	mov    ebx,0x3
    149f:	e9 9c fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14a4:	83 fe 0a             	cmp    esi,0xa
    14a7:	0f 84 05 02 00 00    	je     16b2 <trace_event_type_switch_dispatch_xdp+0x5b2>
    14ad:	83 fe 0b             	cmp    esi,0xb
    14b0:	0f 85 6a 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    14b6:	bb 24 00 00 00       	mov    ebx,0x24
    14bb:	e9 80 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14c0:	83 fe 2a             	cmp    esi,0x2a
    14c3:	0f 84 f3 01 00 00    	je     16bc <trace_event_type_switch_dispatch_xdp+0x5bc>
    14c9:	83 fe 2b             	cmp    esi,0x2b
    14cc:	0f 85 4e 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    14d2:	bb 23 00 00 00       	mov    ebx,0x23
    14d7:	e9 64 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14dc:	83 fe 1a             	cmp    esi,0x1a
    14df:	0f 84 e1 01 00 00    	je     16c6 <trace_event_type_switch_dispatch_xdp+0x5c6>
    14e5:	83 fe 1b             	cmp    esi,0x1b
    14e8:	0f 85 32 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    14ee:	bb 29 00 00 00       	mov    ebx,0x29
    14f3:	e9 48 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    14f8:	83 fe 3a             	cmp    esi,0x3a
    14fb:	0f 84 cf 01 00 00    	je     16d0 <trace_event_type_switch_dispatch_xdp+0x5d0>
    1501:	83 fe 3b             	cmp    esi,0x3b
    1504:	0f 85 16 02 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    150a:	bb 10 00 00 00       	mov    ebx,0x10
    150f:	e9 2c fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1514:	83 fe 06             	cmp    esi,0x6
    1517:	0f 84 bd 01 00 00    	je     16da <trace_event_type_switch_dispatch_xdp+0x5da>
    151d:	83 fe 07             	cmp    esi,0x7
    1520:	0f 85 fa 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1526:	bb 3a 00 00 00       	mov    ebx,0x3a
    152b:	e9 10 fc ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1530:	83 fe 26             	cmp    esi,0x26
    1533:	0f 84 ab 01 00 00    	je     16e4 <trace_event_type_switch_dispatch_xdp+0x5e4>
    1539:	83 fe 27             	cmp    esi,0x27
    153c:	0f 85 de 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1542:	bb 30 00 00 00       	mov    ebx,0x30
    1547:	e9 f4 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    154c:	83 fe 16             	cmp    esi,0x16
    154f:	0f 84 99 01 00 00    	je     16ee <trace_event_type_switch_dispatch_xdp+0x5ee>
    1555:	83 fe 17             	cmp    esi,0x17
    1558:	0f 85 c2 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    155e:	bb 28 00 00 00       	mov    ebx,0x28
    1563:	e9 d8 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1568:	83 fe 36             	cmp    esi,0x36
    156b:	0f 84 87 01 00 00    	je     16f8 <trace_event_type_switch_dispatch_xdp+0x5f8>
    1571:	83 fe 37             	cmp    esi,0x37
    1574:	0f 85 a6 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    157a:	bb 12 00 00 00       	mov    ebx,0x12
    157f:	e9 bc fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1584:	83 fe 0e             	cmp    esi,0xe
    1587:	0f 84 75 01 00 00    	je     1702 <trace_event_type_switch_dispatch_xdp+0x602>
    158d:	83 fe 0f             	cmp    esi,0xf
    1590:	0f 85 8a 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    1596:	bb 2e 00 00 00       	mov    ebx,0x2e
    159b:	e9 a0 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15a0:	83 fe 2e             	cmp    esi,0x2e
    15a3:	0f 84 63 01 00 00    	je     170c <trace_event_type_switch_dispatch_xdp+0x60c>
    15a9:	83 fe 2f             	cmp    esi,0x2f
    15ac:	0f 85 6e 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    15b2:	bb 3b 00 00 00       	mov    ebx,0x3b
    15b7:	e9 84 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15bc:	83 fe 1e             	cmp    esi,0x1e
    15bf:	0f 84 51 01 00 00    	je     1716 <trace_event_type_switch_dispatch_xdp+0x616>
    15c5:	83 fe 1f             	cmp    esi,0x1f
    15c8:	0f 85 52 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    15ce:	bb 34 00 00 00       	mov    ebx,0x34
    15d3:	e9 68 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15d8:	83 fe 3e             	cmp    esi,0x3e
    15db:	0f 84 55 fb ff ff    	je     1136 <trace_event_type_switch_dispatch_xdp+0x36>
    15e1:	83 fe 3f             	cmp    esi,0x3f
    15e4:	0f 85 36 01 00 00    	jne    1720 <trace_event_type_switch_dispatch_xdp+0x620>
    15ea:	bb 37 00 00 00       	mov    ebx,0x37
    15ef:	e9 4c fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15f4:	bb 19 00 00 00       	mov    ebx,0x19
    15f9:	e9 42 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    15fe:	bb 22 00 00 00       	mov    ebx,0x22
    1603:	e9 38 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1608:	bb 2d 00 00 00       	mov    ebx,0x2d
    160d:	e9 2e fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1612:	bb 02 00 00 00       	mov    ebx,0x2
    1617:	e9 24 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    161c:	bb 20 00 00 00       	mov    ebx,0x20
    1621:	e9 1a fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1626:	bb 26 00 00 00       	mov    ebx,0x26
    162b:	e9 10 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1630:	bb 01 00 00 00       	mov    ebx,0x1
    1635:	e9 06 fb ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    163a:	bb 0e 00 00 00       	mov    ebx,0xe
    163f:	e9 fc fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1644:	bb 35 00 00 00       	mov    ebx,0x35
    1649:	e9 f2 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    164e:	bb 1d 00 00 00       	mov    ebx,0x1d
    1653:	e9 e8 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1658:	bb 0d 00 00 00       	mov    ebx,0xd
    165d:	e9 de fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1662:	bb 13 00 00 00       	mov    ebx,0x13
    1667:	e9 d4 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    166c:	bb 08 00 00 00       	mov    ebx,0x8
    1671:	e9 ca fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1676:	bb 21 00 00 00       	mov    ebx,0x21
    167b:	e9 c0 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1680:	bb 3c 00 00 00       	mov    ebx,0x3c
    1685:	e9 b6 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    168a:	bb 39 00 00 00       	mov    ebx,0x39
    168f:	e9 ac fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1694:	bb 0b 00 00 00       	mov    ebx,0xb
    1699:	e9 a2 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    169e:	bb 2f 00 00 00       	mov    ebx,0x2f
    16a3:	e9 98 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16a8:	bb 09 00 00 00       	mov    ebx,0x9
    16ad:	e9 8e fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16b2:	bb 31 00 00 00       	mov    ebx,0x31
    16b7:	e9 84 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16bc:	bb 07 00 00 00       	mov    ebx,0x7
    16c1:	e9 7a fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16c6:	bb 11 00 00 00       	mov    ebx,0x11
    16cb:	e9 70 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16d0:	bb 16 00 00 00       	mov    ebx,0x16
    16d5:	e9 66 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16da:	bb 0a 00 00 00       	mov    ebx,0xa
    16df:	e9 5c fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16e4:	bb 18 00 00 00       	mov    ebx,0x18
    16e9:	e9 52 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16ee:	bb 0f 00 00 00       	mov    ebx,0xf
    16f3:	e9 48 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    16f8:	bb 1e 00 00 00       	mov    ebx,0x1e
    16fd:	e9 3e fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1702:	bb 25 00 00 00       	mov    ebx,0x25
    1707:	e9 34 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    170c:	bb 33 00 00 00       	mov    ebx,0x33
    1711:	e9 2a fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1716:	bb 17 00 00 00       	mov    ebx,0x17
    171b:	e9 20 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    1720:	bb 52 bf 01 00       	mov    ebx,0x1bf52
    1725:	e9 16 fa ff ff       	jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40>
    172a:	88 19                	mov    BYTE PTR [rcx],bl
    172c:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    172f:	c1 eb 10             	shr    ebx,0x10
    1732:	88 59 02             	mov    BYTE PTR [rcx+0x2],bl
    1735:	89 c2                	mov    edx,eax
    1737:	c1 ea 18             	shr    edx,0x18
    173a:	88 51 03             	mov    BYTE PTR [rcx+0x3],dl
    173d:	48 89 c2             	mov    rdx,rax
    1740:	48 c1 ea 20          	shr    rdx,0x20
    1744:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
    1747:	48 89 c2             	mov    rdx,rax
    174a:	48 c1 ea 28          	shr    rdx,0x28
    174e:	88 51 05             	mov    BYTE PTR [rcx+0x5],dl
    1751:	48 89 c2             	mov    rdx,rax
    1754:	48 c1 ea 30          	shr    rdx,0x30
    1758:	88 51 06             	mov    BYTE PTR [rcx+0x6],dl
    175b:	48 c1 e8 38          	shr    rax,0x38
    175f:	88 41 07             	mov    BYTE PTR [rcx+0x7],al
    1762:	b8 02 00 00 00       	mov    eax,0x2
    1767:	5b                   	pop    rbx
    1768:	c3                   	ret

Disassembly of section .fini:

000000000000176c <_fini>:
    176c:	f3 0f 1e fa          	endbr64
    1770:	48 83 ec 08          	sub    rsp,0x8
    1774:	48 83 c4 08          	add    rsp,0x8
    1778:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	31 c0                	xor    eax,eax
   e:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  12:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  16:	48 39 f7             	cmp    rdi,rsi
  19:	0f 87 df 05 00 00    	ja     0x5fe
  1f:	48 89 fa             	mov    rdx,rdi
  22:	48 83 c2 08          	add    rdx,0x8
  26:	48 39 f2             	cmp    rdx,rsi
  29:	0f 87 cf 05 00 00    	ja     0x5fe
  2f:	48 89 fa             	mov    rdx,rdi
  32:	48 81 c2 0c 02 00 00 	add    rdx,0x20c
  39:	48 39 f2             	cmp    rdx,rsi
  3c:	0f 87 bc 05 00 00    	ja     0x5fe
  42:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  47:	c1 e6 08             	shl    esi,0x8
  4a:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  4f:	09 d6                	or     esi,edx
  51:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  56:	c1 e2 10             	shl    edx,0x10
  59:	09 d6                	or     esi,edx
  5b:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  60:	c1 e2 18             	shl    edx,0x18
  63:	09 d6                	or     esi,edx
  65:	81 fe 80 00 00 00    	cmp    esi,0x80
  6b:	0f 85 8d 05 00 00    	jne    0x5fe
  71:	45 31 c0             	xor    r8d,r8d
  74:	31 d2                	xor    edx,edx
  76:	eb 1a                	jmp    0x92
  78:	41 b8 0c 00 00 00    	mov    r8d,0xc
  7e:	49 31 f0             	xor    r8,rsi
  81:	48 83 c2 04          	add    rdx,0x4
  85:	48 81 fa 00 02 00 00 	cmp    rdx,0x200
  8c:	0f 84 20 05 00 00    	je     0x5b2
  92:	4c 89 c6             	mov    rsi,r8
  95:	49 89 f8             	mov    r8,rdi
  98:	49 01 d0             	add    r8,rdx
  9b:	49 0f b6 48 0d       	movzx  rcx,BYTE PTR [r8+0xd]
  a0:	c1 e1 08             	shl    ecx,0x8
  a3:	49 0f b6 40 0c       	movzx  rax,BYTE PTR [r8+0xc]
  a8:	09 c1                	or     ecx,eax
  aa:	49 0f b6 40 0e       	movzx  rax,BYTE PTR [r8+0xe]
  af:	c1 e0 10             	shl    eax,0x10
  b2:	09 c1                	or     ecx,eax
  b4:	4d 0f b6 40 0f       	movzx  r8,BYTE PTR [r8+0xf]
  b9:	41 c1 e0 18          	shl    r8d,0x18
  bd:	44 09 c1             	or     ecx,r8d
  c0:	83 f9 1f             	cmp    ecx,0x1f
  c3:	7f 3f                	jg     0x104
  c5:	83 f9 0f             	cmp    ecx,0xf
  c8:	7f 6e                	jg     0x138
  ca:	83 f9 07             	cmp    ecx,0x7
  cd:	0f 8f c0 00 00 00    	jg     0x193
  d3:	83 f9 03             	cmp    ecx,0x3
  d6:	0f 8f 4f 01 00 00    	jg     0x22b
  dc:	83 f9 01             	cmp    ecx,0x1
  df:	0f 8f 2e 02 00 00    	jg     0x313
  e5:	41 b8 38 00 00 00    	mov    r8d,0x38
  eb:	85 c9                	test   ecx,ecx
  ed:	74 8f                	je     0x7e
  ef:	83 f9 01             	cmp    ecx,0x1
  f2:	74 05                	je     0xf9
  f4:	e9 ae 04 00 00       	jmp    0x5a7
  f9:	41 b8 2b 00 00 00    	mov    r8d,0x2b
  ff:	e9 7a ff ff ff       	jmp    0x7e
 104:	83 f9 2f             	cmp    ecx,0x2f
 107:	7f 5e                	jg     0x167
 109:	83 f9 27             	cmp    ecx,0x27
 10c:	0f 8f a7 00 00 00    	jg     0x1b9
 112:	83 f9 23             	cmp    ecx,0x23
 115:	0f 8f 2d 01 00 00    	jg     0x248
 11b:	83 f9 21             	cmp    ecx,0x21
 11e:	0f 8f 03 02 00 00    	jg     0x327
 124:	83 f9 20             	cmp    ecx,0x20
 127:	0f 84 30 03 00 00    	je     0x45d
 12d:	41 b8 27 00 00 00    	mov    r8d,0x27
 133:	e9 46 ff ff ff       	jmp    0x7e
 138:	83 f9 17             	cmp    ecx,0x17
 13b:	0f 8f 9e 00 00 00    	jg     0x1df
 141:	83 f9 13             	cmp    ecx,0x13
 144:	0f 8f 1b 01 00 00    	jg     0x265
 14a:	83 f9 11             	cmp    ecx,0x11
 14d:	0f 8f e8 01 00 00    	jg     0x33b
 153:	83 f9 10             	cmp    ecx,0x10
 156:	0f 84 0c 03 00 00    	je     0x468
 15c:	41 b8 3e 00 00 00    	mov    r8d,0x3e
 162:	e9 17 ff ff ff       	jmp    0x7e
 167:	83 f9 37             	cmp    ecx,0x37
 16a:	0f 8f 95 00 00 00    	jg     0x205
 170:	83 f9 33             	cmp    ecx,0x33
 173:	0f 8f 09 01 00 00    	jg     0x282
 179:	83 f9 31             	cmp    ecx,0x31
 17c:	0f 8f cd 01 00 00    	jg     0x34f
 182:	83 f9 30             	cmp    ecx,0x30
 185:	0f 84 e8 02 00 00    	je     0x473
 18b:	45 31 c0             	xor    r8d,r8d
 18e:	e9 eb fe ff ff       	jmp    0x7e
 193:	83 f9 0b             	cmp    ecx,0xb
 196:	0f 8f 03 01 00 00    	jg     0x29f
 19c:	83 f9 09             	cmp    ecx,0x9
 19f:	0f 8f be 01 00 00    	jg     0x363
 1a5:	83 f9 08             	cmp    ecx,0x8
 1a8:	0f 84 d0 02 00 00    	je     0x47e
 1ae:	41 b8 3f 00 00 00    	mov    r8d,0x3f
 1b4:	e9 c5 fe ff ff       	jmp    0x7e
 1b9:	83 f9 2b             	cmp    ecx,0x2b
 1bc:	0f 8f fa 00 00 00    	jg     0x2bc
 1c2:	83 f9 29             	cmp    ecx,0x29
 1c5:	0f 8f ac 01 00 00    	jg     0x377
 1cb:	83 f9 28             	cmp    ecx,0x28
 1ce:	0f 84 b5 02 00 00    	je     0x489
 1d4:	41 b8 32 00 00 00    	mov    r8d,0x32
 1da:	e9 9f fe ff ff       	jmp    0x7e
 1df:	83 f9 1b             	cmp    ecx,0x1b
 1e2:	0f 8f f1 00 00 00    	jg     0x2d9
 1e8:	83 f9 19             	cmp    ecx,0x19
 1eb:	0f 8f 9a 01 00 00    	jg     0x38b
 1f1:	83 f9 18             	cmp    ecx,0x18
 1f4:	0f 84 9a 02 00 00    	je     0x494
 1fa:	41 b8 1a 00 00 00    	mov    r8d,0x1a
 200:	e9 79 fe ff ff       	jmp    0x7e
 205:	83 f9 3b             	cmp    ecx,0x3b
 208:	0f 8f e8 00 00 00    	jg     0x2f6
 20e:	83 f9 39             	cmp    ecx,0x39
 211:	0f 8f 88 01 00 00    	jg     0x39f
 217:	83 f9 38             	cmp    ecx,0x38
 21a:	0f 84 7f 02 00 00    	je     0x49f
 220:	41 b8 36 00 00 00    	mov    r8d,0x36
 226:	e9 53 fe ff ff       	jmp    0x7e
 22b:	83 f9 05             	cmp    ecx,0x5
 22e:	0f 8f 7f 01 00 00    	jg     0x3b3
 234:	83 f9 04             	cmp    ecx,0x4
 237:	0f 84 6d 02 00 00    	je     0x4aa
 23d:	41 b8 3d 00 00 00    	mov    r8d,0x3d
 243:	e9 36 fe ff ff       	jmp    0x7e
 248:	83 f9 25             	cmp    ecx,0x25
 24b:	0f 8f 76 01 00 00    	jg     0x3c7
 251:	83 f9 24             	cmp    ecx,0x24
 254:	0f 84 5b 02 00 00    	je     0x4b5
 25a:	41 b8 04 00 00 00    	mov    r8d,0x4
 260:	e9 19 fe ff ff       	jmp    0x7e
 265:	83 f9 15             	cmp    ecx,0x15
 268:	0f 8f 6d 01 00 00    	jg     0x3db
 26e:	83 f9 14             	cmp    ecx,0x14
 271:	0f 84 49 02 00 00    	je     0x4c0
 277:	41 b8 15 00 00 00    	mov    r8d,0x15
 27d:	e9 fc fd ff ff       	jmp    0x7e
 282:	83 f9 35             	cmp    ecx,0x35
 285:	0f 8f 64 01 00 00    	jg     0x3ef
 28b:	83 f9 34             	cmp    ecx,0x34
 28e:	0f 84 37 02 00 00    	je     0x4cb
 294:	41 b8 14 00 00 00    	mov    r8d,0x14
 29a:	e9 df fd ff ff       	jmp    0x7e
 29f:	83 f9 0d             	cmp    ecx,0xd
 2a2:	0f 8f 5b 01 00 00    	jg     0x403
 2a8:	83 f9 0c             	cmp    ecx,0xc
 2ab:	0f 84 25 02 00 00    	je     0x4d6
 2b1:	41 b8 2a 00 00 00    	mov    r8d,0x2a
 2b7:	e9 c2 fd ff ff       	jmp    0x7e
 2bc:	83 f9 2d             	cmp    ecx,0x2d
 2bf:	0f 8f 52 01 00 00    	jg     0x417
 2c5:	83 f9 2c             	cmp    ecx,0x2c
 2c8:	0f 84 13 02 00 00    	je     0x4e1
 2ce:	41 b8 2c 00 00 00    	mov    r8d,0x2c
 2d4:	e9 a5 fd ff ff       	jmp    0x7e
 2d9:	83 f9 1d             	cmp    ecx,0x1d
 2dc:	0f 8f 49 01 00 00    	jg     0x42b
 2e2:	83 f9 1c             	cmp    ecx,0x1c
 2e5:	0f 84 01 02 00 00    	je     0x4ec
 2eb:	41 b8 1f 00 00 00    	mov    r8d,0x1f
 2f1:	e9 88 fd ff ff       	jmp    0x7e
 2f6:	83 f9 3d             	cmp    ecx,0x3d
 2f9:	0f 8f 40 01 00 00    	jg     0x43f
 2ff:	83 f9 3c             	cmp    ecx,0x3c
 302:	0f 84 ef 01 00 00    	je     0x4f7
 308:	41 b8 05 00 00 00    	mov    r8d,0x5
 30e:	e9 6b fd ff ff       	jmp    0x7e
 313:	83 f9 02             	cmp    ecx,0x2
 316:	0f 84 e6 01 00 00    	je     0x502
 31c:	41 b8 1c 00 00 00    	mov    r8d,0x1c
 322:	e9 57 fd ff ff       	jmp    0x7e
 327:	83 f9 22             	cmp    ecx,0x22
 32a:	0f 84 dd 01 00 00    	je     0x50d
 330:	41 b8 1b 00 00 00    	mov    r8d,0x1b
 336:	e9 43 fd ff ff       	jmp    0x7e
 33b:	83 f9 12             	cmp    ecx,0x12
 33e:	0f 84 d4 01 00 00    	je     0x518
 344:	41 b8 06 00 00 00    	mov    r8d,0x6
 34a:	e9 2f fd ff ff       	jmp    0x7e
 34f:	83 f9 32             	cmp    ecx,0x32
 352:	0f 84 cb 01 00 00    	je     0x523
 358:	41 b8 03 00 00 00    	mov    r8d,0x3
 35e:	e9 1b fd ff ff       	jmp    0x7e
 363:	83 f9 0a             	cmp    ecx,0xa
 366:	0f 84 c2 01 00 00    	je     0x52e
 36c:	41 b8 24 00 00 00    	mov    r8d,0x24
 372:	e9 07 fd ff ff       	jmp    0x7e
 377:	83 f9 2a             	cmp    ecx,0x2a
 37a:	0f 84 b9 01 00 00    	je     0x539
 380:	41 b8 23 00 00 00    	mov    r8d,0x23
 386:	e9 f3 fc ff ff       	jmp    0x7e
 38b:	83 f9 1a             	cmp    ecx,0x1a
 38e:	0f 84 b0 01 00 00    	je     0x544
 394:	41 b8 29 00 00 00    	mov    r8d,0x29
 39a:	e9 df fc ff ff       	jmp    0x7e
 39f:	83 f9 3a             	cmp    ecx,0x3a
 3a2:	0f 84 a7 01 00 00    	je     0x54f
 3a8:	41 b8 10 00 00 00    	mov    r8d,0x10
 3ae:	e9 cb fc ff ff       	jmp    0x7e
 3b3:	83 f9 06             	cmp    ecx,0x6
 3b6:	0f 84 9e 01 00 00    	je     0x55a
 3bc:	41 b8 3a 00 00 00    	mov    r8d,0x3a
 3c2:	e9 b7 fc ff ff       	jmp    0x7e
 3c7:	83 f9 26             	cmp    ecx,0x26
 3ca:	0f 84 95 01 00 00    	je     0x565
 3d0:	41 b8 30 00 00 00    	mov    r8d,0x30
 3d6:	e9 a3 fc ff ff       	jmp    0x7e
 3db:	83 f9 16             	cmp    ecx,0x16
 3de:	0f 84 8c 01 00 00    	je     0x570
 3e4:	41 b8 28 00 00 00    	mov    r8d,0x28
 3ea:	e9 8f fc ff ff       	jmp    0x7e
 3ef:	83 f9 36             	cmp    ecx,0x36
 3f2:	0f 84 83 01 00 00    	je     0x57b
 3f8:	41 b8 12 00 00 00    	mov    r8d,0x12
 3fe:	e9 7b fc ff ff       	jmp    0x7e
 403:	83 f9 0e             	cmp    ecx,0xe
 406:	0f 84 7a 01 00 00    	je     0x586
 40c:	41 b8 2e 00 00 00    	mov    r8d,0x2e
 412:	e9 67 fc ff ff       	jmp    0x7e
 417:	83 f9 2e             	cmp    ecx,0x2e
 41a:	0f 84 71 01 00 00    	je     0x591
 420:	41 b8 3b 00 00 00    	mov    r8d,0x3b
 426:	e9 53 fc ff ff       	jmp    0x7e
 42b:	83 f9 1e             	cmp    ecx,0x1e
 42e:	0f 84 68 01 00 00    	je     0x59c
 434:	41 b8 34 00 00 00    	mov    r8d,0x34
 43a:	e9 3f fc ff ff       	jmp    0x7e
 43f:	83 f9 3e             	cmp    ecx,0x3e
 442:	0f 84 30 fc ff ff    	je     0x78
 448:	83 f9 3f             	cmp    ecx,0x3f
 44b:	74 05                	je     0x452
 44d:	e9 55 01 00 00       	jmp    0x5a7
 452:	41 b8 37 00 00 00    	mov    r8d,0x37
 458:	e9 21 fc ff ff       	jmp    0x7e
 45d:	41 b8 19 00 00 00    	mov    r8d,0x19
 463:	e9 16 fc ff ff       	jmp    0x7e
 468:	41 b8 22 00 00 00    	mov    r8d,0x22
 46e:	e9 0b fc ff ff       	jmp    0x7e
 473:	41 b8 2d 00 00 00    	mov    r8d,0x2d
 479:	e9 00 fc ff ff       	jmp    0x7e
 47e:	41 b8 02 00 00 00    	mov    r8d,0x2
 484:	e9 f5 fb ff ff       	jmp    0x7e
 489:	41 b8 20 00 00 00    	mov    r8d,0x20
 48f:	e9 ea fb ff ff       	jmp    0x7e
 494:	41 b8 26 00 00 00    	mov    r8d,0x26
 49a:	e9 df fb ff ff       	jmp    0x7e
 49f:	41 b8 01 00 00 00    	mov    r8d,0x1
 4a5:	e9 d4 fb ff ff       	jmp    0x7e
 4aa:	41 b8 0e 00 00 00    	mov    r8d,0xe
 4b0:	e9 c9 fb ff ff       	jmp    0x7e
 4b5:	41 b8 35 00 00 00    	mov    r8d,0x35
 4bb:	e9 be fb ff ff       	jmp    0x7e
 4c0:	41 b8 1d 00 00 00    	mov    r8d,0x1d
 4c6:	e9 b3 fb ff ff       	jmp    0x7e
 4cb:	41 b8 0d 00 00 00    	mov    r8d,0xd
 4d1:	e9 a8 fb ff ff       	jmp    0x7e
 4d6:	41 b8 13 00 00 00    	mov    r8d,0x13
 4dc:	e9 9d fb ff ff       	jmp    0x7e
 4e1:	41 b8 08 00 00 00    	mov    r8d,0x8
 4e7:	e9 92 fb ff ff       	jmp    0x7e
 4ec:	41 b8 21 00 00 00    	mov    r8d,0x21
 4f2:	e9 87 fb ff ff       	jmp    0x7e
 4f7:	41 b8 3c 00 00 00    	mov    r8d,0x3c
 4fd:	e9 7c fb ff ff       	jmp    0x7e
 502:	41 b8 39 00 00 00    	mov    r8d,0x39
 508:	e9 71 fb ff ff       	jmp    0x7e
 50d:	41 b8 0b 00 00 00    	mov    r8d,0xb
 513:	e9 66 fb ff ff       	jmp    0x7e
 518:	41 b8 2f 00 00 00    	mov    r8d,0x2f
 51e:	e9 5b fb ff ff       	jmp    0x7e
 523:	41 b8 09 00 00 00    	mov    r8d,0x9
 529:	e9 50 fb ff ff       	jmp    0x7e
 52e:	41 b8 31 00 00 00    	mov    r8d,0x31
 534:	e9 45 fb ff ff       	jmp    0x7e
 539:	41 b8 07 00 00 00    	mov    r8d,0x7
 53f:	e9 3a fb ff ff       	jmp    0x7e
 544:	41 b8 11 00 00 00    	mov    r8d,0x11
 54a:	e9 2f fb ff ff       	jmp    0x7e
 54f:	41 b8 16 00 00 00    	mov    r8d,0x16
 555:	e9 24 fb ff ff       	jmp    0x7e
 55a:	41 b8 0a 00 00 00    	mov    r8d,0xa
 560:	e9 19 fb ff ff       	jmp    0x7e
 565:	41 b8 18 00 00 00    	mov    r8d,0x18
 56b:	e9 0e fb ff ff       	jmp    0x7e
 570:	41 b8 0f 00 00 00    	mov    r8d,0xf
 576:	e9 03 fb ff ff       	jmp    0x7e
 57b:	41 b8 1e 00 00 00    	mov    r8d,0x1e
 581:	e9 f8 fa ff ff       	jmp    0x7e
 586:	41 b8 25 00 00 00    	mov    r8d,0x25
 58c:	e9 ed fa ff ff       	jmp    0x7e
 591:	41 b8 33 00 00 00    	mov    r8d,0x33
 597:	e9 e2 fa ff ff       	jmp    0x7e
 59c:	41 b8 17 00 00 00    	mov    r8d,0x17
 5a2:	e9 d7 fa ff ff       	jmp    0x7e
 5a7:	41 b8 52 bf 01 00    	mov    r8d,0x1bf52
 5ad:	e9 cc fa ff ff       	jmp    0x7e
 5b2:	44 88 47 00          	mov    BYTE PTR [rdi+0x0],r8b
 5b6:	48 89 f2             	mov    rdx,rsi
 5b9:	48 c1 ea 38          	shr    rdx,0x38
 5bd:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 5c0:	48 89 f2             	mov    rdx,rsi
 5c3:	48 c1 ea 30          	shr    rdx,0x30
 5c7:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 5ca:	48 89 f2             	mov    rdx,rsi
 5cd:	48 c1 ea 28          	shr    rdx,0x28
 5d1:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 5d4:	48 89 f2             	mov    rdx,rsi
 5d7:	48 c1 ea 20          	shr    rdx,0x20
 5db:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 5de:	48 c1 ee 18          	shr    rsi,0x18
 5e2:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 5e6:	4c 89 c6             	mov    rsi,r8
 5e9:	48 c1 ee 10          	shr    rsi,0x10
 5ed:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 5f1:	49 c1 e8 08          	shr    r8,0x8
 5f5:	44 88 47 01          	mov    BYTE PTR [rdi+0x1],r8b
 5f9:	b8 02 00 00 00       	mov    eax,0x2
 5fe:	c9                   	leave
 5ff:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
