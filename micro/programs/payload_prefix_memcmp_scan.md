# payload_prefix_memcmp_scan

## Original C
```c
#include "common.h"

#define MEMCMP_PREFIX_SCENARIOS 3U
#define MEMCMP_PREFIX_LEN 64U
#define MEMCMP_PREFIX_INPUT_SIZE (4U + MEMCMP_PREFIX_SCENARIOS * MEMCMP_PREFIX_LEN)

static __always_inline u8 memcmp_prefix_pattern_byte(u32 index)
{
    return (u8)((((index * 29U) ^ (index << 2U) ^ 0xA5U) + 0x11U) & 0xFFU);
}

static __always_inline int bench_payload_prefix_memcmp_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, MEMCMP_PREFIX_INPUT_SIZE)) {
        return -1;
    }

    u32 scenario_count = micro_read_u32_le(data, 0);
    if (scenario_count != MEMCMP_PREFIX_SCENARIOS) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 scenario = 0; scenario < MEMCMP_PREFIX_SCENARIOS; scenario++) {
        u32 base = 4U + scenario * MEMCMP_PREFIX_LEN;
        u32 mismatch = MEMCMP_PREFIX_LEN;
        u8 observed = 0;
        u8 expected = 0;

        for (u32 index = 0; index < MEMCMP_PREFIX_LEN; index++) {
            observed = data[base + index];
            expected = memcmp_prefix_pattern_byte(index);
            if (observed != expected) {
                mismatch = index;
                break;
            }
        }

        if (mismatch == MEMCMP_PREFIX_LEN) {
            acc ^= 0x9E3779B97F4A7C15ULL + scenario;
            acc += (u64)data[base + MEMCMP_PREFIX_LEN - 1U] << (scenario * 8U);
        } else {
            acc += (u64)(mismatch + 1U) * (u64)(scenario + 5U);
            acc ^= (u64)observed << ((scenario & 7U) * 8U);
            acc += expected;
        }

        acc = micro_rotl64(acc, 5U + scenario);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    payload_prefix_memcmp_scan_xdp,
    bench_payload_prefix_memcmp_scan,
    payload_prefix_memcmp_scan_input_value,
    MEMCMP_PREFIX_INPUT_SIZE)
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

0000000000001100 <payload_prefix_memcmp_scan_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	76 01                	jbe    110f <payload_prefix_memcmp_scan_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1113:	48 39 d6             	cmp    rsi,rdx
    1116:	77 f6                	ja     110e <payload_prefix_memcmp_scan_xdp+0xe>
    1118:	48 8d b9 cc 00 00 00 	lea    rdi,[rcx+0xcc]
    111f:	48 39 d7             	cmp    rdi,rdx
    1122:	77 ea                	ja     110e <payload_prefix_memcmp_scan_xdp+0xe>
    1124:	83 3e 03             	cmp    DWORD PTR [rsi],0x3
    1127:	75 e5                	jne    110e <payload_prefix_memcmp_scan_xdp+0xe>
    1129:	b2 1d                	mov    dl,0x1d
    112b:	40 b7 04             	mov    dil,0x4
    112e:	31 c0                	xor    eax,eax
    1130:	0f b6 74 01 0c       	movzx  esi,BYTE PTR [rcx+rax*1+0xc]
    1135:	44 8d 4a e3          	lea    r9d,[rdx-0x1d]
    1139:	44 8d 47 fc          	lea    r8d,[rdi-0x4]
    113d:	45 30 c8             	xor    r8b,r9b
    1140:	41 80 f0 a5          	xor    r8b,0xa5
    1144:	41 80 c0 11          	add    r8b,0x11
    1148:	44 38 c6             	cmp    sil,r8b
    114b:	75 39                	jne    1186 <payload_prefix_memcmp_scan_xdp+0x86>
    114d:	0f b6 74 01 0d       	movzx  esi,BYTE PTR [rcx+rax*1+0xd]
    1152:	41 89 d0             	mov    r8d,edx
    1155:	41 30 f8             	xor    r8b,dil
    1158:	41 80 f0 a5          	xor    r8b,0xa5
    115c:	41 80 c0 11          	add    r8b,0x11
    1160:	48 83 c0 02          	add    rax,0x2
    1164:	44 38 c6             	cmp    sil,r8b
    1167:	75 20                	jne    1189 <payload_prefix_memcmp_scan_xdp+0x89>
    1169:	80 c2 3a             	add    dl,0x3a
    116c:	40 80 c7 08          	add    dil,0x8
    1170:	48 83 f8 40          	cmp    rax,0x40
    1174:	75 ba                	jne    1130 <payload_prefix_memcmp_scan_xdp+0x30>
    1176:	0f b6 41 4b          	movzx  eax,BYTE PTR [rcx+0x4b]
    117a:	48 ba 1c b5 f6 8c de 	movabs rdx,0xf43e9fde8cf6b51c
    1181:	9f 3e f4 
    1184:	eb 21                	jmp    11a7 <payload_prefix_memcmp_scan_xdp+0xa7>
    1186:	48 ff c0             	inc    rax
    1189:	89 c0                	mov    eax,eax
    118b:	48 8d 04 80          	lea    rax,[rax+rax*4]
    118f:	48 ba 09 c9 bc f3 67 	movabs rdx,0x6a09e667f3bcc909
    1196:	e6 09 6a 
    1199:	48 01 c2             	add    rdx,rax
    119c:	40 0f b6 c6          	movzx  eax,sil
    11a0:	48 31 d0             	xor    rax,rdx
    11a3:	41 0f b6 d0          	movzx  edx,r8b
    11a7:	48 01 c2             	add    rdx,rax
    11aa:	48 c1 c2 05          	rol    rdx,0x5
    11ae:	40 b6 1d             	mov    sil,0x1d
    11b1:	40 b7 04             	mov    dil,0x4
    11b4:	31 c0                	xor    eax,eax
    11b6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    11bd:	00 00 00 
    11c0:	44 0f b6 44 01 4c    	movzx  r8d,BYTE PTR [rcx+rax*1+0x4c]
    11c6:	44 8d 56 e3          	lea    r10d,[rsi-0x1d]
    11ca:	44 8d 4f fc          	lea    r9d,[rdi-0x4]
    11ce:	45 30 d1             	xor    r9b,r10b
    11d1:	41 80 f1 a5          	xor    r9b,0xa5
    11d5:	41 80 c1 11          	add    r9b,0x11
    11d9:	45 38 c8             	cmp    r8b,r9b
    11dc:	75 44                	jne    1222 <payload_prefix_memcmp_scan_xdp+0x122>
    11de:	44 0f b6 44 01 4d    	movzx  r8d,BYTE PTR [rcx+rax*1+0x4d]
    11e4:	41 89 f1             	mov    r9d,esi
    11e7:	41 30 f9             	xor    r9b,dil
    11ea:	41 80 f1 a5          	xor    r9b,0xa5
    11ee:	41 80 c1 11          	add    r9b,0x11
    11f2:	48 83 c0 02          	add    rax,0x2
    11f6:	45 38 c8             	cmp    r8b,r9b
    11f9:	75 2a                	jne    1225 <payload_prefix_memcmp_scan_xdp+0x125>
    11fb:	40 80 c6 3a          	add    sil,0x3a
    11ff:	40 80 c7 08          	add    dil,0x8
    1203:	48 83 f8 40          	cmp    rax,0x40
    1207:	75 b7                	jne    11c0 <payload_prefix_memcmp_scan_xdp+0xc0>
    1209:	48 b8 16 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c16
    1210:	79 37 9e 
    1213:	48 31 c2             	xor    rdx,rax
    1216:	0f b6 81 8b 00 00 00 	movzx  eax,BYTE PTR [rcx+0x8b]
    121d:	c1 e0 08             	shl    eax,0x8
    1220:	eb 1b                	jmp    123d <payload_prefix_memcmp_scan_xdp+0x13d>
    1222:	48 ff c0             	inc    rax
    1225:	89 c0                	mov    eax,eax
    1227:	48 8d 04 40          	lea    rax,[rax+rax*2]
    122b:	48 8d 04 42          	lea    rax,[rdx+rax*2]
    122f:	41 0f b6 d0          	movzx  edx,r8b
    1233:	c1 e2 08             	shl    edx,0x8
    1236:	48 31 c2             	xor    rdx,rax
    1239:	41 0f b6 c1          	movzx  eax,r9b
    123d:	48 01 d0             	add    rax,rdx
    1240:	48 c1 c0 06          	rol    rax,0x6
    1244:	40 b7 1d             	mov    dil,0x1d
    1247:	41 b0 04             	mov    r8b,0x4
    124a:	31 d2                	xor    edx,edx
    124c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
    1250:	0f b6 b4 11 8c 00 00 	movzx  esi,BYTE PTR [rcx+rdx*1+0x8c]
    1257:	00 
    1258:	44 8d 57 e3          	lea    r10d,[rdi-0x1d]
    125c:	45 8d 48 fc          	lea    r9d,[r8-0x4]
    1260:	45 30 d1             	xor    r9b,r10b
    1263:	41 80 f1 a5          	xor    r9b,0xa5
    1267:	41 80 c1 11          	add    r9b,0x11
    126b:	44 38 ce             	cmp    sil,r9b
    126e:	75 4d                	jne    12bd <payload_prefix_memcmp_scan_xdp+0x1bd>
    1270:	0f b6 b4 11 8d 00 00 	movzx  esi,BYTE PTR [rcx+rdx*1+0x8d]
    1277:	00 
    1278:	41 89 f9             	mov    r9d,edi
    127b:	45 30 c1             	xor    r9b,r8b
    127e:	41 80 f1 a5          	xor    r9b,0xa5
    1282:	41 80 c1 11          	add    r9b,0x11
    1286:	48 83 c2 02          	add    rdx,0x2
    128a:	44 38 ce             	cmp    sil,r9b
    128d:	75 31                	jne    12c0 <payload_prefix_memcmp_scan_xdp+0x1c0>
    128f:	40 80 c7 3a          	add    dil,0x3a
    1293:	41 80 c0 08          	add    r8b,0x8
    1297:	48 83 fa 40          	cmp    rdx,0x40
    129b:	75 b3                	jne    1250 <payload_prefix_memcmp_scan_xdp+0x150>
    129d:	48 ba 16 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c16
    12a4:	79 37 9e 
    12a7:	48 83 ca 01          	or     rdx,0x1
    12ab:	48 31 d0             	xor    rax,rdx
    12ae:	0f b6 91 cb 00 00 00 	movzx  edx,BYTE PTR [rcx+0xcb]
    12b5:	c1 e2 10             	shl    edx,0x10
    12b8:	48 01 c2             	add    rdx,rax
    12bb:	eb 24                	jmp    12e1 <payload_prefix_memcmp_scan_xdp+0x1e1>
    12bd:	48 ff c2             	inc    rdx
    12c0:	89 d2                	mov    edx,edx
    12c2:	48 8d 3c d5 00 00 00 	lea    rdi,[rdx*8+0x0]
    12c9:	00 
    12ca:	48 29 d7             	sub    rdi,rdx
    12cd:	48 01 f8             	add    rax,rdi
    12d0:	40 0f b6 f6          	movzx  esi,sil
    12d4:	c1 e6 10             	shl    esi,0x10
    12d7:	48 31 c6             	xor    rsi,rax
    12da:	41 0f b6 d1          	movzx  edx,r9b
    12de:	48 01 f2             	add    rdx,rsi
    12e1:	48 c1 c2 07          	rol    rdx,0x7
    12e5:	48 89 11             	mov    QWORD PTR [rcx],rdx
    12e8:	b8 02 00 00 00       	mov    eax,0x2
    12ed:	c3                   	ret

Disassembly of section .fini:

00000000000012f0 <_fini>:
    12f0:	f3 0f 1e fa          	endbr64
    12f4:	48 83 ec 08          	sub    rsp,0x8
    12f8:	48 83 c4 08          	add    rsp,0x8
    12fc:	c3                   	ret
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
   d:	31 c0                	xor    eax,eax
   f:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  13:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  17:	48 39 f7             	cmp    rdi,rsi
  1a:	0f 87 16 02 00 00    	ja     0x236
  20:	48 89 fa             	mov    rdx,rdi
  23:	48 83 c2 08          	add    rdx,0x8
  27:	48 39 f2             	cmp    rdx,rsi
  2a:	0f 87 06 02 00 00    	ja     0x236
  30:	48 89 fa             	mov    rdx,rdi
  33:	48 81 c2 cc 00 00 00 	add    rdx,0xcc
  3a:	48 39 f2             	cmp    rdx,rsi
  3d:	0f 87 f3 01 00 00    	ja     0x236
  43:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  48:	c1 e6 08             	shl    esi,0x8
  4b:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  50:	09 d6                	or     esi,edx
  52:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  57:	c1 e2 10             	shl    edx,0x10
  5a:	09 d6                	or     esi,edx
  5c:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  61:	c1 e2 18             	shl    edx,0x18
  64:	09 d6                	or     esi,edx
  66:	83 fe 03             	cmp    esi,0x3
  69:	0f 85 c7 01 00 00    	jne    0x236
  6f:	31 c9                	xor    ecx,ecx
  71:	48 be 09 c9 bc f3 67 	movabs rsi,0x6a09e667f3bcc909
  78:	e6 09 6a 
  7b:	48 83 f9 40          	cmp    rcx,0x40
  7f:	74 40                	je     0xc1
  81:	41 89 c8             	mov    r8d,ecx
  84:	41 c1 e0 02          	shl    r8d,0x2
  88:	89 ca                	mov    edx,ecx
  8a:	6b d2 1d             	imul   edx,edx,0x1d
  8d:	44 31 c2             	xor    edx,r8d
  90:	48 83 c6 05          	add    rsi,0x5
  94:	49 89 f8             	mov    r8,rdi
  97:	49 01 c8             	add    r8,rcx
  9a:	48 83 c1 01          	add    rcx,0x1
  9e:	4d 0f b6 40 0c       	movzx  r8,BYTE PTR [r8+0xc]
  a3:	83 f2 a5             	xor    edx,0xffffffa5
  a6:	83 c2 11             	add    edx,0x11
  a9:	89 d0                	mov    eax,edx
  ab:	25 ff 00 00 00       	and    eax,0xff
  b0:	41 39 c0             	cmp    r8d,eax
  b3:	74 c6                	je     0x7b
  b5:	4c 31 c6             	xor    rsi,r8
  b8:	48 81 e2 ff 00 00 00 	and    rdx,0xff
  bf:	eb 0f                	jmp    0xd0
  c1:	48 ba 1c b5 f6 8c de 	movabs rdx,0xf43e9fde8cf6b51c
  c8:	9f 3e f4 
  cb:	48 0f b6 77 4b       	movzx  rsi,BYTE PTR [rdi+0x4b]
  d0:	48 01 d6             	add    rsi,rdx
  d3:	48 89 f2             	mov    rdx,rsi
  d6:	48 c1 ea 3b          	shr    rdx,0x3b
  da:	48 c1 e6 05          	shl    rsi,0x5
  de:	48 09 d6             	or     rsi,rdx
  e1:	31 c0                	xor    eax,eax
  e3:	31 c9                	xor    ecx,ecx
  e5:	eb 4d                	jmp    0x134
  e7:	89 c2                	mov    edx,eax
  e9:	c1 e2 02             	shl    edx,0x2
  ec:	41 89 c0             	mov    r8d,eax
  ef:	45 6b c0 1d          	imul   r8d,r8d,0x1d
  f3:	41 31 d0             	xor    r8d,edx
  f6:	48 83 c1 fa          	add    rcx,0xfffffffffffffffa
  fa:	48 89 fa             	mov    rdx,rdi
  fd:	48 01 c2             	add    rdx,rax
 100:	48 83 c0 01          	add    rax,0x1
 104:	48 0f b6 52 4c       	movzx  rdx,BYTE PTR [rdx+0x4c]
 109:	41 83 f0 a5          	xor    r8d,0xffffffa5
 10d:	41 83 c0 11          	add    r8d,0x11
 111:	44 89 c3             	mov    ebx,r8d
 114:	81 e3 ff 00 00 00    	and    ebx,0xff
 11a:	39 da                	cmp    edx,ebx
 11c:	74 16                	je     0x134
 11e:	48 29 ce             	sub    rsi,rcx
 121:	48 c1 e2 08          	shl    rdx,0x8
 125:	48 31 f2             	xor    rdx,rsi
 128:	49 81 e0 ff 00 00 00 	and    r8,0xff
 12f:	4c 01 c2             	add    rdx,r8
 132:	eb 22                	jmp    0x156
 134:	48 83 f8 40          	cmp    rax,0x40
 138:	75 ad                	jne    0xe7
 13a:	48 ba 16 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c16
 141:	79 37 9e 
 144:	48 31 d6             	xor    rsi,rdx
 147:	48 0f b6 97 8b 00 00 	movzx  rdx,BYTE PTR [rdi+0x8b]
 14e:	00 
 14f:	48 c1 e2 08          	shl    rdx,0x8
 153:	48 01 f2             	add    rdx,rsi
 156:	48 89 d6             	mov    rsi,rdx
 159:	48 c1 ee 3a          	shr    rsi,0x3a
 15d:	48 c1 e2 06          	shl    rdx,0x6
 161:	48 09 f2             	or     rdx,rsi
 164:	31 c0                	xor    eax,eax
 166:	31 c9                	xor    ecx,ecx
 168:	eb 50                	jmp    0x1ba
 16a:	89 c6                	mov    esi,eax
 16c:	c1 e6 02             	shl    esi,0x2
 16f:	41 89 c0             	mov    r8d,eax
 172:	45 6b c0 1d          	imul   r8d,r8d,0x1d
 176:	41 31 f0             	xor    r8d,esi
 179:	48 83 c1 f9          	add    rcx,0xfffffffffffffff9
 17d:	48 89 fe             	mov    rsi,rdi
 180:	48 01 c6             	add    rsi,rax
 183:	48 83 c0 01          	add    rax,0x1
 187:	48 0f b6 b6 8c 00 00 	movzx  rsi,BYTE PTR [rsi+0x8c]
 18e:	00 
 18f:	41 83 f0 a5          	xor    r8d,0xffffffa5
 193:	41 83 c0 11          	add    r8d,0x11
 197:	44 89 c3             	mov    ebx,r8d
 19a:	81 e3 ff 00 00 00    	and    ebx,0xff
 1a0:	39 de                	cmp    esi,ebx
 1a2:	74 16                	je     0x1ba
 1a4:	48 29 ca             	sub    rdx,rcx
 1a7:	48 c1 e6 10          	shl    rsi,0x10
 1ab:	48 31 d6             	xor    rsi,rdx
 1ae:	49 81 e0 ff 00 00 00 	and    r8,0xff
 1b5:	4c 01 c6             	add    rsi,r8
 1b8:	eb 22                	jmp    0x1dc
 1ba:	48 83 f8 40          	cmp    rax,0x40
 1be:	75 aa                	jne    0x16a
 1c0:	48 be 17 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c17
 1c7:	79 37 9e 
 1ca:	48 31 f2             	xor    rdx,rsi
 1cd:	48 0f b6 b7 cb 00 00 	movzx  rsi,BYTE PTR [rdi+0xcb]
 1d4:	00 
 1d5:	48 c1 e6 10          	shl    rsi,0x10
 1d9:	48 01 d6             	add    rsi,rdx
 1dc:	48 89 f2             	mov    rdx,rsi
 1df:	48 c1 ea 31          	shr    rdx,0x31
 1e3:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 1e6:	48 89 f2             	mov    rdx,rsi
 1e9:	48 c1 ea 29          	shr    rdx,0x29
 1ed:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 1f0:	48 89 f2             	mov    rdx,rsi
 1f3:	48 c1 ea 21          	shr    rdx,0x21
 1f7:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 1fa:	48 89 f2             	mov    rdx,rsi
 1fd:	48 c1 ea 19          	shr    rdx,0x19
 201:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 204:	48 89 f2             	mov    rdx,rsi
 207:	48 c1 ea 11          	shr    rdx,0x11
 20b:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 20e:	48 89 f2             	mov    rdx,rsi
 211:	48 c1 ea 09          	shr    rdx,0x9
 215:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 218:	48 89 f2             	mov    rdx,rsi
 21b:	48 d1 ea             	shr    rdx,1
 21e:	88 57 01             	mov    BYTE PTR [rdi+0x1],dl
 221:	48 89 f2             	mov    rdx,rsi
 224:	48 c1 ea 39          	shr    rdx,0x39
 228:	c1 e6 07             	shl    esi,0x7
 22b:	09 d6                	or     esi,edx
 22d:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
 231:	b8 02 00 00 00       	mov    eax,0x2
 236:	5b                   	pop    rbx
 237:	c9                   	leave
 238:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
