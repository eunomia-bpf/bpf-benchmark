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
  19:	0f 87 34 06 00 00    	ja     0x653
  1f:	48 89 fa             	mov    rdx,rdi
  22:	48 83 c2 08          	add    rdx,0x8
  26:	48 39 f2             	cmp    rdx,rsi
  29:	0f 87 24 06 00 00    	ja     0x653
  2f:	48 89 fa             	mov    rdx,rdi
  32:	48 81 c2 0c 02 00 00 	add    rdx,0x20c
  39:	48 39 f2             	cmp    rdx,rsi
  3c:	0f 87 11 06 00 00    	ja     0x653
  42:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  47:	48 c1 e6 08          	shl    rsi,0x8
  4b:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  50:	48 09 d6             	or     rsi,rdx
  53:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  58:	48 c1 e2 10          	shl    rdx,0x10
  5c:	48 09 d6             	or     rsi,rdx
  5f:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  64:	48 c1 e2 18          	shl    rdx,0x18
  68:	48 09 d6             	or     rsi,rdx
  6b:	48 c1 e6 20          	shl    rsi,0x20
  6f:	48 c1 ee 20          	shr    rsi,0x20
  73:	48 81 fe 80 00 00 00 	cmp    rsi,0x80
  7a:	0f 85 d3 05 00 00    	jne    0x653
  80:	31 d2                	xor    edx,edx
  82:	45 31 c0             	xor    r8d,r8d
  85:	eb 1a                	jmp    0xa1
  87:	41 b8 0c 00 00 00    	mov    r8d,0xc
  8d:	49 31 f0             	xor    r8,rsi
  90:	48 83 c2 04          	add    rdx,0x4
  94:	48 81 fa 00 02 00 00 	cmp    rdx,0x200
  9b:	0f 84 66 05 00 00    	je     0x607
  a1:	4c 89 c6             	mov    rsi,r8
  a4:	49 89 f8             	mov    r8,rdi
  a7:	49 01 d0             	add    r8,rdx
  aa:	49 0f b6 48 0d       	movzx  rcx,BYTE PTR [r8+0xd]
  af:	48 c1 e1 08          	shl    rcx,0x8
  b3:	49 0f b6 40 0c       	movzx  rax,BYTE PTR [r8+0xc]
  b8:	48 09 c1             	or     rcx,rax
  bb:	49 0f b6 40 0e       	movzx  rax,BYTE PTR [r8+0xe]
  c0:	48 c1 e0 10          	shl    rax,0x10
  c4:	48 09 c1             	or     rcx,rax
  c7:	4d 0f b6 40 0f       	movzx  r8,BYTE PTR [r8+0xf]
  cc:	49 c1 e0 18          	shl    r8,0x18
  d0:	4c 09 c1             	or     rcx,r8
  d3:	48 c1 e1 20          	shl    rcx,0x20
  d7:	48 c1 e9 20          	shr    rcx,0x20
  db:	48 83 f9 1f          	cmp    rcx,0x1f
  df:	7f 3e                	jg     0x11f
  e1:	48 83 f9 0f          	cmp    rcx,0xf
  e5:	7f 71                	jg     0x158
  e7:	48 83 f9 07          	cmp    rcx,0x7
  eb:	0f 8f ca 00 00 00    	jg     0x1bb
  f1:	48 83 f9 03          	cmp    rcx,0x3
  f5:	0f 8f 64 01 00 00    	jg     0x25f
  fb:	48 83 f9 01          	cmp    rcx,0x1
  ff:	0f 8f 52 02 00 00    	jg     0x357
 105:	41 b8 38 00 00 00    	mov    r8d,0x38
 10b:	48 85 c9             	test   rcx,rcx
 10e:	0f 84 79 ff ff ff    	je     0x8d
 114:	41 b8 2b 00 00 00    	mov    r8d,0x2b
 11a:	e9 6e ff ff ff       	jmp    0x8d
 11f:	48 83 f9 2f          	cmp    rcx,0x2f
 123:	7f 66                	jg     0x18b
 125:	48 83 f9 27          	cmp    rcx,0x27
 129:	0f 8f b5 00 00 00    	jg     0x1e4
 12f:	48 83 f9 23          	cmp    rcx,0x23
 133:	0f 8f 45 01 00 00    	jg     0x27e
 139:	48 83 f9 21          	cmp    rcx,0x21
 13d:	0f 8f 29 02 00 00    	jg     0x36c
 143:	48 83 f9 20          	cmp    rcx,0x20
 147:	0f 84 65 03 00 00    	je     0x4b2
 14d:	41 b8 27 00 00 00    	mov    r8d,0x27
 153:	e9 35 ff ff ff       	jmp    0x8d
 158:	48 83 f9 17          	cmp    rcx,0x17
 15c:	0f 8f ab 00 00 00    	jg     0x20d
 162:	48 83 f9 13          	cmp    rcx,0x13
 166:	0f 8f 31 01 00 00    	jg     0x29d
 16c:	48 83 f9 11          	cmp    rcx,0x11
 170:	0f 8f 0b 02 00 00    	jg     0x381
 176:	48 83 f9 10          	cmp    rcx,0x10
 17a:	0f 84 3d 03 00 00    	je     0x4bd
 180:	41 b8 3e 00 00 00    	mov    r8d,0x3e
 186:	e9 02 ff ff ff       	jmp    0x8d
 18b:	48 83 f9 37          	cmp    rcx,0x37
 18f:	0f 8f a1 00 00 00    	jg     0x236
 195:	48 83 f9 33          	cmp    rcx,0x33
 199:	0f 8f 1d 01 00 00    	jg     0x2bc
 19f:	48 83 f9 31          	cmp    rcx,0x31
 1a3:	0f 8f ed 01 00 00    	jg     0x396
 1a9:	48 83 f9 30          	cmp    rcx,0x30
 1ad:	0f 84 15 03 00 00    	je     0x4c8
 1b3:	45 31 c0             	xor    r8d,r8d
 1b6:	e9 d2 fe ff ff       	jmp    0x8d
 1bb:	48 83 f9 0b          	cmp    rcx,0xb
 1bf:	0f 8f 16 01 00 00    	jg     0x2db
 1c5:	48 83 f9 09          	cmp    rcx,0x9
 1c9:	0f 8f dc 01 00 00    	jg     0x3ab
 1cf:	48 83 f9 08          	cmp    rcx,0x8
 1d3:	0f 84 fa 02 00 00    	je     0x4d3
 1d9:	41 b8 3f 00 00 00    	mov    r8d,0x3f
 1df:	e9 a9 fe ff ff       	jmp    0x8d
 1e4:	48 83 f9 2b          	cmp    rcx,0x2b
 1e8:	0f 8f 0c 01 00 00    	jg     0x2fa
 1ee:	48 83 f9 29          	cmp    rcx,0x29
 1f2:	0f 8f c8 01 00 00    	jg     0x3c0
 1f8:	48 83 f9 28          	cmp    rcx,0x28
 1fc:	0f 84 dc 02 00 00    	je     0x4de
 202:	41 b8 32 00 00 00    	mov    r8d,0x32
 208:	e9 80 fe ff ff       	jmp    0x8d
 20d:	48 83 f9 1b          	cmp    rcx,0x1b
 211:	0f 8f 02 01 00 00    	jg     0x319
 217:	48 83 f9 19          	cmp    rcx,0x19
 21b:	0f 8f b4 01 00 00    	jg     0x3d5
 221:	48 83 f9 18          	cmp    rcx,0x18
 225:	0f 84 be 02 00 00    	je     0x4e9
 22b:	41 b8 1a 00 00 00    	mov    r8d,0x1a
 231:	e9 57 fe ff ff       	jmp    0x8d
 236:	48 83 f9 3b          	cmp    rcx,0x3b
 23a:	0f 8f f8 00 00 00    	jg     0x338
 240:	48 83 f9 39          	cmp    rcx,0x39
 244:	0f 8f a0 01 00 00    	jg     0x3ea
 24a:	48 83 f9 38          	cmp    rcx,0x38
 24e:	0f 84 a0 02 00 00    	je     0x4f4
 254:	41 b8 36 00 00 00    	mov    r8d,0x36
 25a:	e9 2e fe ff ff       	jmp    0x8d
 25f:	48 83 f9 05          	cmp    rcx,0x5
 263:	0f 8f 96 01 00 00    	jg     0x3ff
 269:	48 83 f9 04          	cmp    rcx,0x4
 26d:	0f 84 8c 02 00 00    	je     0x4ff
 273:	41 b8 3d 00 00 00    	mov    r8d,0x3d
 279:	e9 0f fe ff ff       	jmp    0x8d
 27e:	48 83 f9 25          	cmp    rcx,0x25
 282:	0f 8f 8c 01 00 00    	jg     0x414
 288:	48 83 f9 24          	cmp    rcx,0x24
 28c:	0f 84 78 02 00 00    	je     0x50a
 292:	41 b8 04 00 00 00    	mov    r8d,0x4
 298:	e9 f0 fd ff ff       	jmp    0x8d
 29d:	48 83 f9 15          	cmp    rcx,0x15
 2a1:	0f 8f 82 01 00 00    	jg     0x429
 2a7:	48 83 f9 14          	cmp    rcx,0x14
 2ab:	0f 84 64 02 00 00    	je     0x515
 2b1:	41 b8 15 00 00 00    	mov    r8d,0x15
 2b7:	e9 d1 fd ff ff       	jmp    0x8d
 2bc:	48 83 f9 35          	cmp    rcx,0x35
 2c0:	0f 8f 78 01 00 00    	jg     0x43e
 2c6:	48 83 f9 34          	cmp    rcx,0x34
 2ca:	0f 84 50 02 00 00    	je     0x520
 2d0:	41 b8 14 00 00 00    	mov    r8d,0x14
 2d6:	e9 b2 fd ff ff       	jmp    0x8d
 2db:	48 83 f9 0d          	cmp    rcx,0xd
 2df:	0f 8f 6e 01 00 00    	jg     0x453
 2e5:	48 83 f9 0c          	cmp    rcx,0xc
 2e9:	0f 84 3c 02 00 00    	je     0x52b
 2ef:	41 b8 2a 00 00 00    	mov    r8d,0x2a
 2f5:	e9 93 fd ff ff       	jmp    0x8d
 2fa:	48 83 f9 2d          	cmp    rcx,0x2d
 2fe:	0f 8f 64 01 00 00    	jg     0x468
 304:	48 83 f9 2c          	cmp    rcx,0x2c
 308:	0f 84 28 02 00 00    	je     0x536
 30e:	41 b8 2c 00 00 00    	mov    r8d,0x2c
 314:	e9 74 fd ff ff       	jmp    0x8d
 319:	48 83 f9 1d          	cmp    rcx,0x1d
 31d:	0f 8f 5a 01 00 00    	jg     0x47d
 323:	48 83 f9 1c          	cmp    rcx,0x1c
 327:	0f 84 14 02 00 00    	je     0x541
 32d:	41 b8 1f 00 00 00    	mov    r8d,0x1f
 333:	e9 55 fd ff ff       	jmp    0x8d
 338:	48 83 f9 3d          	cmp    rcx,0x3d
 33c:	0f 8f 50 01 00 00    	jg     0x492
 342:	48 83 f9 3c          	cmp    rcx,0x3c
 346:	0f 84 00 02 00 00    	je     0x54c
 34c:	41 b8 05 00 00 00    	mov    r8d,0x5
 352:	e9 36 fd ff ff       	jmp    0x8d
 357:	48 83 f9 02          	cmp    rcx,0x2
 35b:	0f 84 f6 01 00 00    	je     0x557
 361:	41 b8 1c 00 00 00    	mov    r8d,0x1c
 367:	e9 21 fd ff ff       	jmp    0x8d
 36c:	48 83 f9 22          	cmp    rcx,0x22
 370:	0f 84 ec 01 00 00    	je     0x562
 376:	41 b8 1b 00 00 00    	mov    r8d,0x1b
 37c:	e9 0c fd ff ff       	jmp    0x8d
 381:	48 83 f9 12          	cmp    rcx,0x12
 385:	0f 84 e2 01 00 00    	je     0x56d
 38b:	41 b8 06 00 00 00    	mov    r8d,0x6
 391:	e9 f7 fc ff ff       	jmp    0x8d
 396:	48 83 f9 32          	cmp    rcx,0x32
 39a:	0f 84 d8 01 00 00    	je     0x578
 3a0:	41 b8 03 00 00 00    	mov    r8d,0x3
 3a6:	e9 e2 fc ff ff       	jmp    0x8d
 3ab:	48 83 f9 0a          	cmp    rcx,0xa
 3af:	0f 84 ce 01 00 00    	je     0x583
 3b5:	41 b8 24 00 00 00    	mov    r8d,0x24
 3bb:	e9 cd fc ff ff       	jmp    0x8d
 3c0:	48 83 f9 2a          	cmp    rcx,0x2a
 3c4:	0f 84 c4 01 00 00    	je     0x58e
 3ca:	41 b8 23 00 00 00    	mov    r8d,0x23
 3d0:	e9 b8 fc ff ff       	jmp    0x8d
 3d5:	48 83 f9 1a          	cmp    rcx,0x1a
 3d9:	0f 84 ba 01 00 00    	je     0x599
 3df:	41 b8 29 00 00 00    	mov    r8d,0x29
 3e5:	e9 a3 fc ff ff       	jmp    0x8d
 3ea:	48 83 f9 3a          	cmp    rcx,0x3a
 3ee:	0f 84 b0 01 00 00    	je     0x5a4
 3f4:	41 b8 10 00 00 00    	mov    r8d,0x10
 3fa:	e9 8e fc ff ff       	jmp    0x8d
 3ff:	48 83 f9 06          	cmp    rcx,0x6
 403:	0f 84 a6 01 00 00    	je     0x5af
 409:	41 b8 3a 00 00 00    	mov    r8d,0x3a
 40f:	e9 79 fc ff ff       	jmp    0x8d
 414:	48 83 f9 26          	cmp    rcx,0x26
 418:	0f 84 9c 01 00 00    	je     0x5ba
 41e:	41 b8 30 00 00 00    	mov    r8d,0x30
 424:	e9 64 fc ff ff       	jmp    0x8d
 429:	48 83 f9 16          	cmp    rcx,0x16
 42d:	0f 84 92 01 00 00    	je     0x5c5
 433:	41 b8 28 00 00 00    	mov    r8d,0x28
 439:	e9 4f fc ff ff       	jmp    0x8d
 43e:	48 83 f9 36          	cmp    rcx,0x36
 442:	0f 84 88 01 00 00    	je     0x5d0
 448:	41 b8 12 00 00 00    	mov    r8d,0x12
 44e:	e9 3a fc ff ff       	jmp    0x8d
 453:	48 83 f9 0e          	cmp    rcx,0xe
 457:	0f 84 7e 01 00 00    	je     0x5db
 45d:	41 b8 2e 00 00 00    	mov    r8d,0x2e
 463:	e9 25 fc ff ff       	jmp    0x8d
 468:	48 83 f9 2e          	cmp    rcx,0x2e
 46c:	0f 84 74 01 00 00    	je     0x5e6
 472:	41 b8 3b 00 00 00    	mov    r8d,0x3b
 478:	e9 10 fc ff ff       	jmp    0x8d
 47d:	48 83 f9 1e          	cmp    rcx,0x1e
 481:	0f 84 6a 01 00 00    	je     0x5f1
 487:	41 b8 34 00 00 00    	mov    r8d,0x34
 48d:	e9 fb fb ff ff       	jmp    0x8d
 492:	48 83 f9 3e          	cmp    rcx,0x3e
 496:	0f 84 eb fb ff ff    	je     0x87
 49c:	48 83 f9 3f          	cmp    rcx,0x3f
 4a0:	74 05                	je     0x4a7
 4a2:	e9 55 01 00 00       	jmp    0x5fc
 4a7:	41 b8 37 00 00 00    	mov    r8d,0x37
 4ad:	e9 db fb ff ff       	jmp    0x8d
 4b2:	41 b8 19 00 00 00    	mov    r8d,0x19
 4b8:	e9 d0 fb ff ff       	jmp    0x8d
 4bd:	41 b8 22 00 00 00    	mov    r8d,0x22
 4c3:	e9 c5 fb ff ff       	jmp    0x8d
 4c8:	41 b8 2d 00 00 00    	mov    r8d,0x2d
 4ce:	e9 ba fb ff ff       	jmp    0x8d
 4d3:	41 b8 02 00 00 00    	mov    r8d,0x2
 4d9:	e9 af fb ff ff       	jmp    0x8d
 4de:	41 b8 20 00 00 00    	mov    r8d,0x20
 4e4:	e9 a4 fb ff ff       	jmp    0x8d
 4e9:	41 b8 26 00 00 00    	mov    r8d,0x26
 4ef:	e9 99 fb ff ff       	jmp    0x8d
 4f4:	41 b8 01 00 00 00    	mov    r8d,0x1
 4fa:	e9 8e fb ff ff       	jmp    0x8d
 4ff:	41 b8 0e 00 00 00    	mov    r8d,0xe
 505:	e9 83 fb ff ff       	jmp    0x8d
 50a:	41 b8 35 00 00 00    	mov    r8d,0x35
 510:	e9 78 fb ff ff       	jmp    0x8d
 515:	41 b8 1d 00 00 00    	mov    r8d,0x1d
 51b:	e9 6d fb ff ff       	jmp    0x8d
 520:	41 b8 0d 00 00 00    	mov    r8d,0xd
 526:	e9 62 fb ff ff       	jmp    0x8d
 52b:	41 b8 13 00 00 00    	mov    r8d,0x13
 531:	e9 57 fb ff ff       	jmp    0x8d
 536:	41 b8 08 00 00 00    	mov    r8d,0x8
 53c:	e9 4c fb ff ff       	jmp    0x8d
 541:	41 b8 21 00 00 00    	mov    r8d,0x21
 547:	e9 41 fb ff ff       	jmp    0x8d
 54c:	41 b8 3c 00 00 00    	mov    r8d,0x3c
 552:	e9 36 fb ff ff       	jmp    0x8d
 557:	41 b8 39 00 00 00    	mov    r8d,0x39
 55d:	e9 2b fb ff ff       	jmp    0x8d
 562:	41 b8 0b 00 00 00    	mov    r8d,0xb
 568:	e9 20 fb ff ff       	jmp    0x8d
 56d:	41 b8 2f 00 00 00    	mov    r8d,0x2f
 573:	e9 15 fb ff ff       	jmp    0x8d
 578:	41 b8 09 00 00 00    	mov    r8d,0x9
 57e:	e9 0a fb ff ff       	jmp    0x8d
 583:	41 b8 31 00 00 00    	mov    r8d,0x31
 589:	e9 ff fa ff ff       	jmp    0x8d
 58e:	41 b8 07 00 00 00    	mov    r8d,0x7
 594:	e9 f4 fa ff ff       	jmp    0x8d
 599:	41 b8 11 00 00 00    	mov    r8d,0x11
 59f:	e9 e9 fa ff ff       	jmp    0x8d
 5a4:	41 b8 16 00 00 00    	mov    r8d,0x16
 5aa:	e9 de fa ff ff       	jmp    0x8d
 5af:	41 b8 0a 00 00 00    	mov    r8d,0xa
 5b5:	e9 d3 fa ff ff       	jmp    0x8d
 5ba:	41 b8 18 00 00 00    	mov    r8d,0x18
 5c0:	e9 c8 fa ff ff       	jmp    0x8d
 5c5:	41 b8 0f 00 00 00    	mov    r8d,0xf
 5cb:	e9 bd fa ff ff       	jmp    0x8d
 5d0:	41 b8 1e 00 00 00    	mov    r8d,0x1e
 5d6:	e9 b2 fa ff ff       	jmp    0x8d
 5db:	41 b8 25 00 00 00    	mov    r8d,0x25
 5e1:	e9 a7 fa ff ff       	jmp    0x8d
 5e6:	41 b8 33 00 00 00    	mov    r8d,0x33
 5ec:	e9 9c fa ff ff       	jmp    0x8d
 5f1:	41 b8 17 00 00 00    	mov    r8d,0x17
 5f7:	e9 91 fa ff ff       	jmp    0x8d
 5fc:	41 b8 52 bf 01 00    	mov    r8d,0x1bf52
 602:	e9 86 fa ff ff       	jmp    0x8d
 607:	48 89 f2             	mov    rdx,rsi
 60a:	48 c1 ea 38          	shr    rdx,0x38
 60e:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 611:	48 89 f2             	mov    rdx,rsi
 614:	48 c1 ea 30          	shr    rdx,0x30
 618:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 61b:	48 89 f2             	mov    rdx,rsi
 61e:	48 c1 ea 28          	shr    rdx,0x28
 622:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 625:	48 89 f2             	mov    rdx,rsi
 628:	48 c1 ea 20          	shr    rdx,0x20
 62c:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 62f:	48 c1 ee 18          	shr    rsi,0x18
 633:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 637:	4c 89 c6             	mov    rsi,r8
 63a:	48 c1 ee 10          	shr    rsi,0x10
 63e:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 642:	44 88 47 00          	mov    BYTE PTR [rdi+0x0],r8b
 646:	49 c1 e8 08          	shr    r8,0x8
 64a:	44 88 47 01          	mov    BYTE PTR [rdi+0x1],r8b
 64e:	b8 02 00 00 00       	mov    eax,0x2
 653:	c9                   	leave
 654:	c3                   	ret
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
   d:	0f 87 d9 04 00 00    	ja     0x4ec
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 cc 04 00 00    	ja     0x4ec
  20:	48 8d b1 0c 02 00 00 	lea    rsi,[rcx+0x20c]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 bc 04 00 00    	ja     0x4ec
  30:	81 79 08 80 00 00 00 	cmp    DWORD PTR [rcx+0x8],0x80
  37:	75 48                	jne    0x81
  39:	55                   	push   rbp
  3a:	41 57                	push   r15
  3c:	41 56                	push   r14
  3e:	41 55                	push   r13
  40:	41 54                	push   r12
  42:	53                   	push   rbx
  43:	31 c0                	xor    eax,eax
  45:	41 bb 2f 00 00 00    	mov    r11d,0x2f
  4b:	bb 22 00 00 00       	mov    ebx,0x22
  50:	41 be 13 00 00 00    	mov    r14d,0x13
  56:	41 bf 31 00 00 00    	mov    r15d,0x31
  5c:	41 bd 02 00 00 00    	mov    r13d,0x2
  62:	bd 0a 00 00 00       	mov    ebp,0xa
  67:	41 bc 0e 00 00 00    	mov    r12d,0xe
  6d:	be 39 00 00 00       	mov    esi,0x39
  72:	bf 38 00 00 00       	mov    edi,0x38
  77:	31 d2                	xor    edx,edx
  79:	41 ba 37 00 00 00    	mov    r10d,0x37
  7f:	eb 32                	jmp    0xb3
  81:	31 c0                	xor    eax,eax
  83:	c3                   	ret
  84:	41 83 f8 02          	cmp    r8d,0x2
  88:	41 b9 1c 00 00 00    	mov    r9d,0x1c
  8e:	4c 0f 44 ce          	cmove  r9,rsi
  92:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  99:	1f 84 00 00 00 00 00 
  a0:	4c 31 ca             	xor    rdx,r9
  a3:	48 83 c0 04          	add    rax,0x4
  a7:	48 3d 00 02 00 00    	cmp    rax,0x200
  ad:	0f 84 12 04 00 00    	je     0x4c5
  b3:	44 8b 44 01 0c       	mov    r8d,DWORD PTR [rcx+rax*1+0xc]
  b8:	49 83 f8 1f          	cmp    r8,0x1f
  bc:	76 42                	jbe    0x100
  be:	41 83 f8 2f          	cmp    r8d,0x2f
  c2:	76 7c                	jbe    0x140
  c4:	41 83 f8 37          	cmp    r8d,0x37
  c8:	0f 86 e8 00 00 00    	jbe    0x1b6
  ce:	41 83 f8 3b          	cmp    r8d,0x3b
  d2:	0f 86 8c 01 00 00    	jbe    0x264
  d8:	41 83 f8 3d          	cmp    r8d,0x3d
  dc:	0f 86 86 02 00 00    	jbe    0x368
  e2:	49 83 f8 3f          	cmp    r8,0x3f
  e6:	41 b9 52 bf 01 00    	mov    r9d,0x1bf52
  ec:	4d 0f 44 ca          	cmove  r9,r10
  f0:	49 83 f8 3e          	cmp    r8,0x3e
  f4:	41 b8 0c 00 00 00    	mov    r8d,0xc
  fa:	4d 0f 44 c8          	cmove  r9,r8
  fe:	eb a0                	jmp    0xa0
 100:	41 83 f8 0f          	cmp    r8d,0xf
 104:	76 7a                	jbe    0x180
 106:	41 83 f8 17          	cmp    r8d,0x17
 10a:	0f 86 d3 00 00 00    	jbe    0x1e3
 110:	41 83 f8 1b          	cmp    r8d,0x1b
 114:	0f 86 6d 01 00 00    	jbe    0x287
 11a:	41 83 f8 1d          	cmp    r8d,0x1d
 11e:	0f 86 5d 02 00 00    	jbe    0x381
 124:	41 83 f8 1e          	cmp    r8d,0x1e
 128:	41 b9 34 00 00 00    	mov    r9d,0x34
 12e:	41 b8 17 00 00 00    	mov    r8d,0x17
 134:	4d 0f 44 c8          	cmove  r9,r8
 138:	e9 63 ff ff ff       	jmp    0xa0
 13d:	0f 1f 00             	nop    DWORD PTR [rax]
 140:	41 83 f8 27          	cmp    r8d,0x27
 144:	0f 86 c6 00 00 00    	jbe    0x210
 14a:	41 83 f8 2b          	cmp    r8d,0x2b
 14e:	0f 86 56 01 00 00    	jbe    0x2aa
 154:	41 83 f8 2d          	cmp    r8d,0x2d
 158:	0f 86 3b 02 00 00    	jbe    0x399
 15e:	45 31 c9             	xor    r9d,r9d
 161:	41 83 f8 2e          	cmp    r8d,0x2e
 165:	41 0f 95 c1          	setne  r9b
 169:	4e 8d 0c cd 33 00 00 	lea    r9,[r9*8+0x33]
 170:	00 
 171:	e9 2a ff ff ff       	jmp    0xa0
 176:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
 17d:	00 00 00 
 180:	41 83 f8 07          	cmp    r8d,0x7
 184:	0f 86 b3 00 00 00    	jbe    0x23d
 18a:	41 83 f8 0b          	cmp    r8d,0xb
 18e:	0f 86 39 01 00 00    	jbe    0x2cd
 194:	41 83 f8 0d          	cmp    r8d,0xd
 198:	0f 86 14 02 00 00    	jbe    0x3b2
 19e:	45 31 c9             	xor    r9d,r9d
 1a1:	41 83 f8 0e          	cmp    r8d,0xe
 1a5:	41 0f 95 c1          	setne  r9b
 1a9:	4f 8d 0c c9          	lea    r9,[r9+r9*8]
 1ad:	49 83 c1 25          	add    r9,0x25
 1b1:	e9 ea fe ff ff       	jmp    0xa0
 1b6:	41 83 f8 33          	cmp    r8d,0x33
 1ba:	0f 86 2a 01 00 00    	jbe    0x2ea
 1c0:	41 83 f8 35          	cmp    r8d,0x35
 1c4:	0f 86 fb 01 00 00    	jbe    0x3c5
 1ca:	41 83 f8 36          	cmp    r8d,0x36
 1ce:	41 b9 12 00 00 00    	mov    r9d,0x12
 1d4:	41 b8 1e 00 00 00    	mov    r8d,0x1e
 1da:	4d 0f 44 c8          	cmove  r9,r8
 1de:	e9 bd fe ff ff       	jmp    0xa0
 1e3:	41 83 f8 13          	cmp    r8d,0x13
 1e7:	0f 86 20 01 00 00    	jbe    0x30d
 1ed:	41 83 f8 15          	cmp    r8d,0x15
 1f1:	0f 86 e7 01 00 00    	jbe    0x3de
 1f7:	41 83 f8 16          	cmp    r8d,0x16
 1fb:	41 b9 28 00 00 00    	mov    r9d,0x28
 201:	41 b8 0f 00 00 00    	mov    r8d,0xf
 207:	4d 0f 44 c8          	cmove  r9,r8
 20b:	e9 90 fe ff ff       	jmp    0xa0
 210:	41 83 f8 23          	cmp    r8d,0x23
 214:	0f 86 10 01 00 00    	jbe    0x32a
 21a:	41 83 f8 25          	cmp    r8d,0x25
 21e:	0f 86 d2 01 00 00    	jbe    0x3f6
 224:	41 83 f8 26          	cmp    r8d,0x26
 228:	41 b9 30 00 00 00    	mov    r9d,0x30
 22e:	41 b8 18 00 00 00    	mov    r8d,0x18
 234:	4d 0f 44 c8          	cmove  r9,r8
 238:	e9 63 fe ff ff       	jmp    0xa0
 23d:	41 83 f8 03          	cmp    r8d,0x3
 241:	0f 86 05 01 00 00    	jbe    0x34c
 247:	41 83 f8 05          	cmp    r8d,0x5
 24b:	0f 86 be 01 00 00    	jbe    0x40f
 251:	41 83 f8 06          	cmp    r8d,0x6
 255:	41 b9 3a 00 00 00    	mov    r9d,0x3a
 25b:	4c 0f 44 cd          	cmove  r9,rbp
 25f:	e9 3c fe ff ff       	jmp    0xa0
 264:	41 83 f8 39          	cmp    r8d,0x39
 268:	0f 86 b4 01 00 00    	jbe    0x422
 26e:	41 83 f8 3a          	cmp    r8d,0x3a
 272:	41 b9 10 00 00 00    	mov    r9d,0x10
 278:	41 b8 16 00 00 00    	mov    r8d,0x16
 27e:	4d 0f 44 c8          	cmove  r9,r8
 282:	e9 19 fe ff ff       	jmp    0xa0
 287:	41 83 f8 19          	cmp    r8d,0x19
 28b:	0f 86 aa 01 00 00    	jbe    0x43b
 291:	41 83 f8 1a          	cmp    r8d,0x1a
 295:	41 b9 29 00 00 00    	mov    r9d,0x29
 29b:	41 b8 11 00 00 00    	mov    r8d,0x11
 2a1:	4d 0f 44 c8          	cmove  r9,r8
 2a5:	e9 f6 fd ff ff       	jmp    0xa0
 2aa:	41 83 f8 29          	cmp    r8d,0x29
 2ae:	0f 86 a0 01 00 00    	jbe    0x454
 2b4:	41 83 f8 2a          	cmp    r8d,0x2a
 2b8:	41 b9 23 00 00 00    	mov    r9d,0x23
 2be:	41 b8 07 00 00 00    	mov    r8d,0x7
 2c4:	4d 0f 44 c8          	cmove  r9,r8
 2c8:	e9 d3 fd ff ff       	jmp    0xa0
 2cd:	41 83 f8 09          	cmp    r8d,0x9
 2d1:	0f 86 96 01 00 00    	jbe    0x46d
 2d7:	41 83 f8 0a          	cmp    r8d,0xa
 2db:	41 b9 24 00 00 00    	mov    r9d,0x24
 2e1:	4d 0f 44 cf          	cmove  r9,r15
 2e5:	e9 b6 fd ff ff       	jmp    0xa0
 2ea:	41 83 f8 31          	cmp    r8d,0x31
 2ee:	0f 86 8c 01 00 00    	jbe    0x480
 2f4:	41 83 f8 32          	cmp    r8d,0x32
 2f8:	41 b9 03 00 00 00    	mov    r9d,0x3
 2fe:	41 b8 09 00 00 00    	mov    r8d,0x9
 304:	4d 0f 44 c8          	cmove  r9,r8
 308:	e9 93 fd ff ff       	jmp    0xa0
 30d:	41 83 f8 11          	cmp    r8d,0x11
 311:	0f 86 82 01 00 00    	jbe    0x499
 317:	41 83 f8 12          	cmp    r8d,0x12
 31b:	41 b9 06 00 00 00    	mov    r9d,0x6
 321:	4d 0f 44 cb          	cmove  r9,r11
 325:	e9 76 fd ff ff       	jmp    0xa0
 32a:	41 83 f8 21          	cmp    r8d,0x21
 32e:	0f 86 78 01 00 00    	jbe    0x4ac
 334:	45 31 c9             	xor    r9d,r9d
 337:	41 83 f8 22          	cmp    r8d,0x22
 33b:	41 0f 95 c1          	setne  r9b
 33f:	41 c1 e1 04          	shl    r9d,0x4
 343:	49 83 c9 0b          	or     r9,0xb
 347:	e9 54 fd ff ff       	jmp    0xa0
 34c:	41 83 f8 01          	cmp    r8d,0x1
 350:	0f 87 2e fd ff ff    	ja     0x84
 356:	4d 85 c0             	test   r8,r8
 359:	41 b9 2b 00 00 00    	mov    r9d,0x2b
 35f:	4c 0f 44 cf          	cmove  r9,rdi
 363:	e9 38 fd ff ff       	jmp    0xa0
 368:	41 83 f8 3c          	cmp    r8d,0x3c
 36c:	41 b9 05 00 00 00    	mov    r9d,0x5
 372:	41 b8 3c 00 00 00    	mov    r8d,0x3c
 378:	4d 0f 44 c8          	cmove  r9,r8
 37c:	e9 1f fd ff ff       	jmp    0xa0
 381:	45 31 c9             	xor    r9d,r9d
 384:	41 83 f8 1c          	cmp    r8d,0x1c
 388:	41 0f 94 c1          	sete   r9b
 38c:	4e 8d 0c 4d 1f 00 00 	lea    r9,[r9*2+0x1f]
 393:	00 
 394:	e9 07 fd ff ff       	jmp    0xa0
 399:	41 83 f8 2c          	cmp    r8d,0x2c
 39d:	41 b9 2c 00 00 00    	mov    r9d,0x2c
 3a3:	41 b8 08 00 00 00    	mov    r8d,0x8
 3a9:	4d 0f 44 c8          	cmove  r9,r8
 3ad:	e9 ee fc ff ff       	jmp    0xa0
 3b2:	41 83 f8 0c          	cmp    r8d,0xc
 3b6:	41 b9 2a 00 00 00    	mov    r9d,0x2a
 3bc:	4d 0f 44 ce          	cmove  r9,r14
 3c0:	e9 db fc ff ff       	jmp    0xa0
 3c5:	41 83 f8 34          	cmp    r8d,0x34
 3c9:	41 b9 14 00 00 00    	mov    r9d,0x14
 3cf:	41 b8 0d 00 00 00    	mov    r8d,0xd
 3d5:	4d 0f 44 c8          	cmove  r9,r8
 3d9:	e9 c2 fc ff ff       	jmp    0xa0
 3de:	45 31 c9             	xor    r9d,r9d
 3e1:	41 83 f8 14          	cmp    r8d,0x14
 3e5:	41 0f 94 c1          	sete   r9b
 3e9:	4e 8d 0c cd 15 00 00 	lea    r9,[r9*8+0x15]
 3f0:	00 
 3f1:	e9 aa fc ff ff       	jmp    0xa0
 3f6:	41 83 f8 24          	cmp    r8d,0x24
 3fa:	41 b9 04 00 00 00    	mov    r9d,0x4
 400:	41 b8 35 00 00 00    	mov    r8d,0x35
 406:	4d 0f 44 c8          	cmove  r9,r8
 40a:	e9 91 fc ff ff       	jmp    0xa0
 40f:	41 83 f8 04          	cmp    r8d,0x4
 413:	41 b9 3d 00 00 00    	mov    r9d,0x3d
 419:	4d 0f 44 cc          	cmove  r9,r12
 41d:	e9 7e fc ff ff       	jmp    0xa0
 422:	41 83 f8 38          	cmp    r8d,0x38
 426:	41 b9 36 00 00 00    	mov    r9d,0x36
 42c:	41 b8 01 00 00 00    	mov    r8d,0x1
 432:	4d 0f 44 c8          	cmove  r9,r8
 436:	e9 65 fc ff ff       	jmp    0xa0
 43b:	41 83 f8 18          	cmp    r8d,0x18
 43f:	41 b9 1a 00 00 00    	mov    r9d,0x1a
 445:	41 b8 26 00 00 00    	mov    r8d,0x26
 44b:	4d 0f 44 c8          	cmove  r9,r8
 44f:	e9 4c fc ff ff       	jmp    0xa0
 454:	41 83 f8 28          	cmp    r8d,0x28
 458:	41 b9 32 00 00 00    	mov    r9d,0x32
 45e:	41 b8 20 00 00 00    	mov    r8d,0x20
 464:	4d 0f 44 c8          	cmove  r9,r8
 468:	e9 33 fc ff ff       	jmp    0xa0
 46d:	41 83 f8 08          	cmp    r8d,0x8
 471:	41 b9 3f 00 00 00    	mov    r9d,0x3f
 477:	4d 0f 44 cd          	cmove  r9,r13
 47b:	e9 20 fc ff ff       	jmp    0xa0
 480:	41 83 f8 30          	cmp    r8d,0x30
 484:	41 b9 00 00 00 00    	mov    r9d,0x0
 48a:	41 b8 2d 00 00 00    	mov    r8d,0x2d
 490:	4d 0f 44 c8          	cmove  r9,r8
 494:	e9 07 fc ff ff       	jmp    0xa0
 499:	41 83 f8 10          	cmp    r8d,0x10
 49d:	41 b9 3e 00 00 00    	mov    r9d,0x3e
 4a3:	4c 0f 44 cb          	cmove  r9,rbx
 4a7:	e9 f4 fb ff ff       	jmp    0xa0
 4ac:	41 83 f8 20          	cmp    r8d,0x20
 4b0:	41 b9 27 00 00 00    	mov    r9d,0x27
 4b6:	41 b8 19 00 00 00    	mov    r8d,0x19
 4bc:	4d 0f 44 c8          	cmove  r9,r8
 4c0:	e9 db fb ff ff       	jmp    0xa0
 4c5:	89 d0                	mov    eax,edx
 4c7:	c1 e8 10             	shr    eax,0x10
 4ca:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
 4ce:	c7 41 03 00 00 00 00 	mov    DWORD PTR [rcx+0x3],0x0
 4d5:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
 4d8:	88 11                	mov    BYTE PTR [rcx],dl
 4da:	88 71 01             	mov    BYTE PTR [rcx+0x1],dh
 4dd:	b8 02 00 00 00       	mov    eax,0x2
 4e2:	5b                   	pop    rbx
 4e3:	41 5c                	pop    r12
 4e5:	41 5d                	pop    r13
 4e7:	41 5e                	pop    r14
 4e9:	41 5f                	pop    r15
 4eb:	5d                   	pop    rbp
 4ec:	c3                   	ret
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
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <trace_event_type_switch_dispatch_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_4, BPF_REG_3, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, (-3) - 1, 0),
    /* 0x1118: lea    rdi,[rcx+0x20c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 524), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rdx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_3, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x80 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x112a: jne    110e <trace_event_type_switch_dispatch_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 128),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x112c: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112d: mov    edx,0xf [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1132: xor    ebx,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1134: jmp    1154 <trace_event_type_switch_dispatch_xdp+0x54> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (8) - 1),
    /* 0x1136: mov    ebx,0xc [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x113b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: xor    rbx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1143: add    rdx,0x4 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1147: cmp    rdx,0x20f [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x114e: je     172a <trace_event_type_switch_dispatch_xdp+0x62a> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_3, 0, (292) - 1, 527),
    /* 0x1154: mov    rax,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1157: mov    esi,DWORD PTR [rcx+rdx*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_2, BPF_REG_4, BPF_REG_3, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x115b: cmp    esi,0x1f [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x115e: jg     11a0 <trace_event_type_switch_dispatch_xdp+0xa0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (13) - 1, 31),
    /* 0x1160: cmp    esi,0xf [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1163: jg     11e0 <trace_event_type_switch_dispatch_xdp+0xe0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (21) - 1, 15),
    /* 0x1165: cmp    esi,0x7 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1168: jg     1254 <trace_event_type_switch_dispatch_xdp+0x154> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (36) - 1, 7),
    /* 0x116e: cmp    esi,0x3 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1171: jg     130c <trace_event_type_switch_dispatch_xdp+0x20c> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (63) - 1, 3),
    /* 0x1177: cmp    esi,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x117a: jg     1434 <trace_event_type_switch_dispatch_xdp+0x334> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (110) - 1, 1),
    /* 0x1180: mov    ebx,0x38 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1185: test   esi,esi [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x1187: je     1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_2, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-17) - 1),
    /* 0x1189: cmp    esi,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x118c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (275) - 1, 1),
    /* 0x1192: mov    ebx,0x2b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 43), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1197: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-21) - 1),
    /* 0x1199: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: cmp    esi,0x2f [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11a3: jg     1220 <trace_event_type_switch_dispatch_xdp+0x120> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (17) - 1, 47),
    /* 0x11a5: cmp    esi,0x27 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11a8: jg     1282 <trace_event_type_switch_dispatch_xdp+0x182> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (31) - 1, 39),
    /* 0x11ae: cmp    esi,0x23 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11b1: jg     1331 <trace_event_type_switch_dispatch_xdp+0x231> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (57) - 1, 35),
    /* 0x11b7: cmp    esi,0x21 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11ba: jg     1450 <trace_event_type_switch_dispatch_xdp+0x350> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (103) - 1, 33),
    /* 0x11c0: cmp    esi,0x20 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11c3: je     15f4 <trace_event_type_switch_dispatch_xdp+0x4f4> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (177) - 1, 32),
    /* 0x11c9: cmp    esi,0x21 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11cc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (266) - 1, 33),
    /* 0x11d2: mov    ebx,0x27 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 39), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-30) - 1),
    /* 0x11dc: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11e0: cmp    esi,0x17 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11e3: jg     12b0 <trace_event_type_switch_dispatch_xdp+0x1b0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (30) - 1, 23),
    /* 0x11e9: cmp    esi,0x13 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11ec: jg     1356 <trace_event_type_switch_dispatch_xdp+0x256> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (55) - 1, 19),
    /* 0x11f2: cmp    esi,0x11 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11f5: jg     146c <trace_event_type_switch_dispatch_xdp+0x36c> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (100) - 1, 17),
    /* 0x11fb: cmp    esi,0x10 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11fe: je     15fe <trace_event_type_switch_dispatch_xdp+0x4fe> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (172) - 1, 16),
    /* 0x1204: cmp    esi,0x11 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1207: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (258) - 1, 17),
    /* 0x120d: mov    ebx,0x3e [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 62), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1212: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-38) - 1),
    /* 0x1217: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1220: cmp    esi,0x37 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1223: jg     12de <trace_event_type_switch_dispatch_xdp+0x1de> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (29) - 1, 55),
    /* 0x1229: cmp    esi,0x33 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x122c: jg     137b <trace_event_type_switch_dispatch_xdp+0x27b> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (53) - 1, 51),
    /* 0x1232: cmp    esi,0x31 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1235: jg     1488 <trace_event_type_switch_dispatch_xdp+0x388> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (97) - 1, 49),
    /* 0x123b: cmp    esi,0x30 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x123e: je     1608 <trace_event_type_switch_dispatch_xdp+0x508> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (167) - 1, 48),
    /* 0x1244: cmp    esi,0x31 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1247: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (250) - 1, 49),
    /* 0x124d: xor    ebx,ebx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x124f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-46) - 1),
    /* 0x1254: cmp    esi,0xb [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1257: jg     13a0 <trace_event_type_switch_dispatch_xdp+0x2a0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (52) - 1, 11),
    /* 0x125d: cmp    esi,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1260: jg     14a4 <trace_event_type_switch_dispatch_xdp+0x3a4> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (95) - 1, 9),
    /* 0x1266: cmp    esi,0x8 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1269: je     1612 <trace_event_type_switch_dispatch_xdp+0x512> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (163) - 1, 8),
    /* 0x126f: cmp    esi,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1272: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (243) - 1, 9),
    /* 0x1278: mov    ebx,0x3f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 63), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-53) - 1),
    /* 0x1282: cmp    esi,0x2b [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1285: jg     13c5 <trace_event_type_switch_dispatch_xdp+0x2c5> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (51) - 1, 43),
    /* 0x128b: cmp    esi,0x29 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x128e: jg     14c0 <trace_event_type_switch_dispatch_xdp+0x3c0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (93) - 1, 41),
    /* 0x1294: cmp    esi,0x28 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1297: je     161c <trace_event_type_switch_dispatch_xdp+0x51c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (159) - 1, 40),
    /* 0x129d: cmp    esi,0x29 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12a0: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (236) - 1, 41),
    /* 0x12a6: mov    ebx,0x32 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 50), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ab: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-60) - 1),
    /* 0x12b0: cmp    esi,0x1b [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x12b3: jg     13ea <trace_event_type_switch_dispatch_xdp+0x2ea> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (50) - 1, 27),
    /* 0x12b9: cmp    esi,0x19 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x12bc: jg     14dc <trace_event_type_switch_dispatch_xdp+0x3dc> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (91) - 1, 25),
    /* 0x12c2: cmp    esi,0x18 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12c5: je     1626 <trace_event_type_switch_dispatch_xdp+0x526> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (155) - 1, 24),
    /* 0x12cb: cmp    esi,0x19 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12ce: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (229) - 1, 25),
    /* 0x12d4: mov    ebx,0x1a [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 26), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12d9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-67) - 1),
    /* 0x12de: cmp    esi,0x3b [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x12e1: jg     140f <trace_event_type_switch_dispatch_xdp+0x30f> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (49) - 1, 59),
    /* 0x12e7: cmp    esi,0x39 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x12ea: jg     14f8 <trace_event_type_switch_dispatch_xdp+0x3f8> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (89) - 1, 57),
    /* 0x12f0: cmp    esi,0x38 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x12f3: je     1630 <trace_event_type_switch_dispatch_xdp+0x530> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (151) - 1, 56),
    /* 0x12f9: cmp    esi,0x39 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12fc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (222) - 1, 57),
    /* 0x1302: mov    ebx,0x36 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 54), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1307: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-74) - 1),
    /* 0x130c: cmp    esi,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x130f: jg     1514 <trace_event_type_switch_dispatch_xdp+0x414> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (88) - 1, 5),
    /* 0x1315: cmp    esi,0x4 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1318: je     163a <trace_event_type_switch_dispatch_xdp+0x53a> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (148) - 1, 4),
    /* 0x131e: cmp    esi,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1321: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (216) - 1, 5),
    /* 0x1327: mov    ebx,0x3d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 61), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x132c: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-80) - 1),
    /* 0x1331: cmp    esi,0x25 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1334: jg     1530 <trace_event_type_switch_dispatch_xdp+0x430> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (87) - 1, 37),
    /* 0x133a: cmp    esi,0x24 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x133d: je     1644 <trace_event_type_switch_dispatch_xdp+0x544> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (145) - 1, 36),
    /* 0x1343: cmp    esi,0x25 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1346: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (210) - 1, 37),
    /* 0x134c: mov    ebx,0x4 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 4), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1351: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-86) - 1),
    /* 0x1356: cmp    esi,0x15 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1359: jg     154c <trace_event_type_switch_dispatch_xdp+0x44c> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (86) - 1, 21),
    /* 0x135f: cmp    esi,0x14 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1362: je     164e <trace_event_type_switch_dispatch_xdp+0x54e> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (142) - 1, 20),
    /* 0x1368: cmp    esi,0x15 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x136b: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (204) - 1, 21),
    /* 0x1371: mov    ebx,0x15 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 21), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1376: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-92) - 1),
    /* 0x137b: cmp    esi,0x35 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x137e: jg     1568 <trace_event_type_switch_dispatch_xdp+0x468> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (85) - 1, 53),
    /* 0x1384: cmp    esi,0x34 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1387: je     1658 <trace_event_type_switch_dispatch_xdp+0x558> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (139) - 1, 52),
    /* 0x138d: cmp    esi,0x35 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1390: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (198) - 1, 53),
    /* 0x1396: mov    ebx,0x14 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 20), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x139b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-98) - 1),
    /* 0x13a0: cmp    esi,0xd [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x13a3: jg     1584 <trace_event_type_switch_dispatch_xdp+0x484> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (84) - 1, 13),
    /* 0x13a9: cmp    esi,0xc [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x13ac: je     1662 <trace_event_type_switch_dispatch_xdp+0x562> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (136) - 1, 12),
    /* 0x13b2: cmp    esi,0xd [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x13b5: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (192) - 1, 13),
    /* 0x13bb: mov    ebx,0x2a [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 42), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13c0: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-104) - 1),
    /* 0x13c5: cmp    esi,0x2d [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x13c8: jg     15a0 <trace_event_type_switch_dispatch_xdp+0x4a0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (83) - 1, 45),
    /* 0x13ce: cmp    esi,0x2c [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x13d1: je     166c <trace_event_type_switch_dispatch_xdp+0x56c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (133) - 1, 44),
    /* 0x13d7: cmp    esi,0x2d [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x13da: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (186) - 1, 45),
    /* 0x13e0: mov    ebx,0x2c [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 44), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13e5: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-110) - 1),
    /* 0x13ea: cmp    esi,0x1d [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x13ed: jg     15bc <trace_event_type_switch_dispatch_xdp+0x4bc> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (82) - 1, 29),
    /* 0x13f3: cmp    esi,0x1c [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x13f6: je     1676 <trace_event_type_switch_dispatch_xdp+0x576> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (130) - 1, 28),
    /* 0x13fc: cmp    esi,0x1d [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x13ff: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (180) - 1, 29),
    /* 0x1405: mov    ebx,0x1f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 31), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x140a: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-116) - 1),
    /* 0x140f: cmp    esi,0x3d [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1412: jg     15d8 <trace_event_type_switch_dispatch_xdp+0x4d8> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_2, 0, (81) - 1, 61),
    /* 0x1418: cmp    esi,0x3c [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x141b: je     1680 <trace_event_type_switch_dispatch_xdp+0x580> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (127) - 1, 60),
    /* 0x1421: cmp    esi,0x3d [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1424: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (174) - 1, 61),
    /* 0x142a: mov    ebx,0x5 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x142f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-122) - 1),
    /* 0x1434: cmp    esi,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1437: je     168a <trace_event_type_switch_dispatch_xdp+0x58a> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (125) - 1, 2),
    /* 0x143d: cmp    esi,0x3 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1440: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (169) - 1, 3),
    /* 0x1446: mov    ebx,0x1c [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 28), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x144b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-127) - 1),
    /* 0x1450: cmp    esi,0x22 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1453: je     1694 <trace_event_type_switch_dispatch_xdp+0x594> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (123) - 1, 34),
    /* 0x1459: cmp    esi,0x23 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x145c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (164) - 1, 35),
    /* 0x1462: mov    ebx,0x1b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 27), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1467: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-132) - 1),
    /* 0x146c: cmp    esi,0x12 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x146f: je     169e <trace_event_type_switch_dispatch_xdp+0x59e> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (121) - 1, 18),
    /* 0x1475: cmp    esi,0x13 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1478: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (159) - 1, 19),
    /* 0x147e: mov    ebx,0x6 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1483: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-137) - 1),
    /* 0x1488: cmp    esi,0x32 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x148b: je     16a8 <trace_event_type_switch_dispatch_xdp+0x5a8> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (119) - 1, 50),
    /* 0x1491: cmp    esi,0x33 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1494: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (154) - 1, 51),
    /* 0x149a: mov    ebx,0x3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x149f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-142) - 1),
    /* 0x14a4: cmp    esi,0xa [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x14a7: je     16b2 <trace_event_type_switch_dispatch_xdp+0x5b2> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (117) - 1, 10),
    /* 0x14ad: cmp    esi,0xb [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x14b0: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (149) - 1, 11),
    /* 0x14b6: mov    ebx,0x24 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 36), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x14bb: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-147) - 1),
    /* 0x14c0: cmp    esi,0x2a [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x14c3: je     16bc <trace_event_type_switch_dispatch_xdp+0x5bc> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (115) - 1, 42),
    /* 0x14c9: cmp    esi,0x2b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x14cc: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (144) - 1, 43),
    /* 0x14d2: mov    ebx,0x23 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 35), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x14d7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-152) - 1),
    /* 0x14dc: cmp    esi,0x1a [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x14df: je     16c6 <trace_event_type_switch_dispatch_xdp+0x5c6> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (113) - 1, 26),
    /* 0x14e5: cmp    esi,0x1b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x14e8: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (139) - 1, 27),
    /* 0x14ee: mov    ebx,0x29 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 41), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x14f3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-157) - 1),
    /* 0x14f8: cmp    esi,0x3a [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x14fb: je     16d0 <trace_event_type_switch_dispatch_xdp+0x5d0> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (111) - 1, 58),
    /* 0x1501: cmp    esi,0x3b [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1504: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (134) - 1, 59),
    /* 0x150a: mov    ebx,0x10 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 16), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x150f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-162) - 1),
    /* 0x1514: cmp    esi,0x6 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1517: je     16da <trace_event_type_switch_dispatch_xdp+0x5da> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (109) - 1, 6),
    /* 0x151d: cmp    esi,0x7 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1520: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (129) - 1, 7),
    /* 0x1526: mov    ebx,0x3a [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 58), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x152b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-167) - 1),
    /* 0x1530: cmp    esi,0x26 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1533: je     16e4 <trace_event_type_switch_dispatch_xdp+0x5e4> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (107) - 1, 38),
    /* 0x1539: cmp    esi,0x27 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x153c: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (124) - 1, 39),
    /* 0x1542: mov    ebx,0x30 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 48), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1547: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-172) - 1),
    /* 0x154c: cmp    esi,0x16 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x154f: je     16ee <trace_event_type_switch_dispatch_xdp+0x5ee> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (105) - 1, 22),
    /* 0x1555: cmp    esi,0x17 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1558: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (119) - 1, 23),
    /* 0x155e: mov    ebx,0x28 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 40), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1563: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-177) - 1),
    /* 0x1568: cmp    esi,0x36 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x156b: je     16f8 <trace_event_type_switch_dispatch_xdp+0x5f8> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (103) - 1, 54),
    /* 0x1571: cmp    esi,0x37 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1574: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (114) - 1, 55),
    /* 0x157a: mov    ebx,0x12 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 18), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x157f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-182) - 1),
    /* 0x1584: cmp    esi,0xe [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1587: je     1702 <trace_event_type_switch_dispatch_xdp+0x602> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (101) - 1, 14),
    /* 0x158d: cmp    esi,0xf [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1590: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (109) - 1, 15),
    /* 0x1596: mov    ebx,0x2e [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 46), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x159b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-187) - 1),
    /* 0x15a0: cmp    esi,0x2e [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x15a3: je     170c <trace_event_type_switch_dispatch_xdp+0x60c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (99) - 1, 46),
    /* 0x15a9: cmp    esi,0x2f [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x15ac: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (104) - 1, 47),
    /* 0x15b2: mov    ebx,0x3b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 59), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15b7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-192) - 1),
    /* 0x15bc: cmp    esi,0x1e [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x15bf: je     1716 <trace_event_type_switch_dispatch_xdp+0x616> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (97) - 1, 30),
    /* 0x15c5: cmp    esi,0x1f [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x15c8: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (99) - 1, 31),
    /* 0x15ce: mov    ebx,0x34 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15d3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-197) - 1),
    /* 0x15d8: cmp    esi,0x3e [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x15db: je     1136 <trace_event_type_switch_dispatch_xdp+0x36> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_2, 0, (-200) - 1, 62),
    /* 0x15e1: cmp    esi,0x3f [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x15e4: jne    1720 <trace_event_type_switch_dispatch_xdp+0x620> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_2, 0, (94) - 1, 63),
    /* 0x15ea: mov    ebx,0x37 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 55), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15ef: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-202) - 1),
    /* 0x15f4: mov    ebx,0x19 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 25), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x15f9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-205) - 1),
    /* 0x15fe: mov    ebx,0x22 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 34), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1603: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-208) - 1),
    /* 0x1608: mov    ebx,0x2d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 45), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x160d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-211) - 1),
    /* 0x1612: mov    ebx,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1617: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-214) - 1),
    /* 0x161c: mov    ebx,0x20 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 32), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1621: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-217) - 1),
    /* 0x1626: mov    ebx,0x26 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x162b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-220) - 1),
    /* 0x1630: mov    ebx,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1635: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-223) - 1),
    /* 0x163a: mov    ebx,0xe [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x163f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-226) - 1),
    /* 0x1644: mov    ebx,0x35 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 53), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1649: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-229) - 1),
    /* 0x164e: mov    ebx,0x1d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 29), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1653: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-232) - 1),
    /* 0x1658: mov    ebx,0xd [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 13), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x165d: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-235) - 1),
    /* 0x1662: mov    ebx,0x13 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 19), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1667: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-238) - 1),
    /* 0x166c: mov    ebx,0x8 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1671: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-241) - 1),
    /* 0x1676: mov    ebx,0x21 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 33), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x167b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-244) - 1),
    /* 0x1680: mov    ebx,0x3c [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 60), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1685: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-247) - 1),
    /* 0x168a: mov    ebx,0x39 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 57), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x168f: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-250) - 1),
    /* 0x1694: mov    ebx,0xb [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1699: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-253) - 1),
    /* 0x169e: mov    ebx,0x2f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 47), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16a3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-256) - 1),
    /* 0x16a8: mov    ebx,0x9 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16ad: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-259) - 1),
    /* 0x16b2: mov    ebx,0x31 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 49), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16b7: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-262) - 1),
    /* 0x16bc: mov    ebx,0x7 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16c1: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-265) - 1),
    /* 0x16c6: mov    ebx,0x11 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 17), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16cb: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-268) - 1),
    /* 0x16d0: mov    ebx,0x16 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 22), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16d5: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-271) - 1),
    /* 0x16da: mov    ebx,0xa [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16df: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-274) - 1),
    /* 0x16e4: mov    ebx,0x18 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 24), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16e9: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-277) - 1),
    /* 0x16ee: mov    ebx,0xf [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16f3: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-280) - 1),
    /* 0x16f8: mov    ebx,0x1e [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 30), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x16fd: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-283) - 1),
    /* 0x1702: mov    ebx,0x25 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1707: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-286) - 1),
    /* 0x170c: mov    ebx,0x33 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 51), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1711: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-289) - 1),
    /* 0x1716: mov    ebx,0x17 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 23), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x171b: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-292) - 1),
    /* 0x1720: mov    ebx,0x1bf52 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 114514), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1725: jmp    1140 <trace_event_type_switch_dispatch_xdp+0x40> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-295) - 1),
    /* 0x172a: mov    BYTE PTR [rcx],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x172c: mov    BYTE PTR [rcx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_6, BPF_REG_4, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x172f: shr    ebx,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_6, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1732: mov    BYTE PTR [rcx+0x2],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1735: mov    edx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1737: shr    edx,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x173a: mov    BYTE PTR [rcx+0x3],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x173d: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1740: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1744: mov    BYTE PTR [rcx+0x4],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1747: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x174a: shr    rdx,0x28 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x174e: mov    BYTE PTR [rcx+0x5],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 5), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1751: mov    rdx,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1754: shr    rdx,0x30 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x1758: mov    BYTE PTR [rcx+0x6],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x175b: shr    rax,0x38 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x175f: mov    BYTE PTR [rcx+0x7],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1762: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1767: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1768: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
