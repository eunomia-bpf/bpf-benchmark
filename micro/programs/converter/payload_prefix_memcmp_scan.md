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
   c:	31 c0                	xor    eax,eax
   e:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  12:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  16:	48 39 f7             	cmp    rdi,rsi
  19:	0f 87 14 02 00 00    	ja     0x233
  1f:	48 89 fa             	mov    rdx,rdi
  22:	48 83 c2 08          	add    rdx,0x8
  26:	48 39 f2             	cmp    rdx,rsi
  29:	0f 87 04 02 00 00    	ja     0x233
  2f:	48 89 fa             	mov    rdx,rdi
  32:	48 81 c2 cc 00 00 00 	add    rdx,0xcc
  39:	48 39 f2             	cmp    rdx,rsi
  3c:	0f 87 f1 01 00 00    	ja     0x233
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
  73:	48 83 fe 03          	cmp    rsi,0x3
  77:	0f 85 b6 01 00 00    	jne    0x233
  7d:	31 c9                	xor    ecx,ecx
  7f:	48 be 09 c9 bc f3 67 	movabs rsi,0x6a09e667f3bcc909
  86:	e6 09 6a 
  89:	48 83 f9 40          	cmp    rcx,0x40
  8d:	74 3d                	je     0xcc
  8f:	49 89 c8             	mov    r8,rcx
  92:	49 c1 e0 02          	shl    r8,0x2
  96:	48 89 ca             	mov    rdx,rcx
  99:	48 6b d2 1d          	imul   rdx,rdx,0x1d
  9d:	4c 31 c2             	xor    rdx,r8
  a0:	48 83 c6 05          	add    rsi,0x5
  a4:	49 89 f8             	mov    r8,rdi
  a7:	49 01 c8             	add    r8,rcx
  aa:	48 83 c1 01          	add    rcx,0x1
  ae:	4d 0f b6 40 0c       	movzx  r8,BYTE PTR [r8+0xc]
  b3:	48 83 f2 a5          	xor    rdx,0xffffffffffffffa5
  b7:	48 83 c2 11          	add    rdx,0x11
  bb:	48 81 e2 ff 00 00 00 	and    rdx,0xff
  c2:	49 39 d0             	cmp    r8,rdx
  c5:	74 c2                	je     0x89
  c7:	4c 31 c6             	xor    rsi,r8
  ca:	eb 0f                	jmp    0xdb
  cc:	48 ba 1c b5 f6 8c de 	movabs rdx,0xf43e9fde8cf6b51c
  d3:	9f 3e f4 
  d6:	48 0f b6 77 4b       	movzx  rsi,BYTE PTR [rdi+0x4b]
  db:	48 01 d6             	add    rsi,rdx
  de:	48 89 f2             	mov    rdx,rsi
  e1:	48 c1 ea 3b          	shr    rdx,0x3b
  e5:	48 c1 e6 05          	shl    rsi,0x5
  e9:	48 09 d6             	or     rsi,rdx
  ec:	45 31 c0             	xor    r8d,r8d
  ef:	48 89 f1             	mov    rcx,rsi
  f2:	eb 43                	jmp    0x137
  f4:	4c 89 c2             	mov    rdx,r8
  f7:	48 c1 e2 02          	shl    rdx,0x2
  fb:	4c 89 c0             	mov    rax,r8
  fe:	48 6b c0 1d          	imul   rax,rax,0x1d
 102:	48 31 d0             	xor    rax,rdx
 105:	48 83 c1 06          	add    rcx,0x6
 109:	48 89 fa             	mov    rdx,rdi
 10c:	4c 01 c2             	add    rdx,r8
 10f:	49 83 c0 01          	add    r8,0x1
 113:	48 0f b6 52 4c       	movzx  rdx,BYTE PTR [rdx+0x4c]
 118:	48 83 f0 a5          	xor    rax,0xffffffffffffffa5
 11c:	48 83 c0 11          	add    rax,0x11
 120:	48 25 ff 00 00 00    	and    rax,0xff
 126:	48 39 c2             	cmp    rdx,rax
 129:	74 0c                	je     0x137
 12b:	48 c1 e2 08          	shl    rdx,0x8
 12f:	48 31 ca             	xor    rdx,rcx
 132:	48 01 c2             	add    rdx,rax
 135:	eb 22                	jmp    0x159
 137:	49 83 f8 40          	cmp    r8,0x40
 13b:	75 b7                	jne    0xf4
 13d:	48 ba 16 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c16
 144:	79 37 9e 
 147:	48 31 d6             	xor    rsi,rdx
 14a:	48 0f b6 97 8b 00 00 	movzx  rdx,BYTE PTR [rdi+0x8b]
 151:	00 
 152:	48 c1 e2 08          	shl    rdx,0x8
 156:	48 01 f2             	add    rdx,rsi
 159:	48 89 d6             	mov    rsi,rdx
 15c:	48 c1 ee 3a          	shr    rsi,0x3a
 160:	48 c1 e2 06          	shl    rdx,0x6
 164:	48 09 f2             	or     rdx,rsi
 167:	45 31 c0             	xor    r8d,r8d
 16a:	48 89 d1             	mov    rcx,rdx
 16d:	eb 46                	jmp    0x1b5
 16f:	4c 89 c6             	mov    rsi,r8
 172:	48 c1 e6 02          	shl    rsi,0x2
 176:	4c 89 c0             	mov    rax,r8
 179:	48 6b c0 1d          	imul   rax,rax,0x1d
 17d:	48 31 f0             	xor    rax,rsi
 180:	48 83 c1 07          	add    rcx,0x7
 184:	48 89 fe             	mov    rsi,rdi
 187:	4c 01 c6             	add    rsi,r8
 18a:	49 83 c0 01          	add    r8,0x1
 18e:	48 0f b6 b6 8c 00 00 	movzx  rsi,BYTE PTR [rsi+0x8c]
 195:	00 
 196:	48 83 f0 a5          	xor    rax,0xffffffffffffffa5
 19a:	48 83 c0 11          	add    rax,0x11
 19e:	48 25 ff 00 00 00    	and    rax,0xff
 1a4:	48 39 c6             	cmp    rsi,rax
 1a7:	74 0c                	je     0x1b5
 1a9:	48 c1 e6 10          	shl    rsi,0x10
 1ad:	48 31 ce             	xor    rsi,rcx
 1b0:	48 01 c6             	add    rsi,rax
 1b3:	eb 22                	jmp    0x1d7
 1b5:	49 83 f8 40          	cmp    r8,0x40
 1b9:	75 b4                	jne    0x16f
 1bb:	48 be 17 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c17
 1c2:	79 37 9e 
 1c5:	48 31 f2             	xor    rdx,rsi
 1c8:	48 0f b6 b7 cb 00 00 	movzx  rsi,BYTE PTR [rdi+0xcb]
 1cf:	00 
 1d0:	48 c1 e6 10          	shl    rsi,0x10
 1d4:	48 01 d6             	add    rsi,rdx
 1d7:	48 89 f2             	mov    rdx,rsi
 1da:	48 c1 ea 31          	shr    rdx,0x31
 1de:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 1e1:	48 89 f2             	mov    rdx,rsi
 1e4:	48 c1 ea 29          	shr    rdx,0x29
 1e8:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 1eb:	48 89 f2             	mov    rdx,rsi
 1ee:	48 c1 ea 21          	shr    rdx,0x21
 1f2:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 1f5:	48 89 f2             	mov    rdx,rsi
 1f8:	48 c1 ea 19          	shr    rdx,0x19
 1fc:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 1ff:	48 89 f2             	mov    rdx,rsi
 202:	48 c1 ea 11          	shr    rdx,0x11
 206:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 209:	48 89 f2             	mov    rdx,rsi
 20c:	48 c1 ea 09          	shr    rdx,0x9
 210:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 213:	48 89 f2             	mov    rdx,rsi
 216:	48 d1 ea             	shr    rdx,1
 219:	88 57 01             	mov    BYTE PTR [rdi+0x1],dl
 21c:	48 89 f2             	mov    rdx,rsi
 21f:	48 c1 ea 39          	shr    rdx,0x39
 223:	48 c1 e6 07          	shl    rsi,0x7
 227:	48 09 d6             	or     rsi,rdx
 22a:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
 22e:	b8 02 00 00 00       	mov    eax,0x2
 233:	c9                   	leave
 234:	c3                   	ret
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
   d:	0f 87 c1 01 00 00    	ja     0x1d4
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 b4 01 00 00    	ja     0x1d4
  20:	48 8d b1 cc 00 00 00 	lea    rsi,[rcx+0xcc]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 a4 01 00 00    	ja     0x1d4
  30:	83 79 08 03          	cmp    DWORD PTR [rcx+0x8],0x3
  34:	75 56                	jne    0x8c
  36:	48 ba 09 c9 bc f3 67 	movabs rdx,0x6a09e667f3bcc909
  3d:	e6 09 6a 
  40:	31 c0                	xor    eax,eax
  42:	48 89 ce             	mov    rsi,rcx
  45:	31 ff                	xor    edi,edi
  47:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
  4e:	00 00 
  50:	48 81 ff 00 01 00 00 	cmp    rdi,0x100
  57:	74 36                	je     0x8f
  59:	48 83 c2 05          	add    rdx,0x5
  5d:	44 0f b6 46 0c       	movzx  r8d,BYTE PTR [rsi+0xc]
  62:	41 89 f9             	mov    r9d,edi
  65:	41 31 c1             	xor    r9d,eax
  68:	41 81 f1 a5 00 00 00 	xor    r9d,0xa5
  6f:	41 83 c1 11          	add    r9d,0x11
  73:	45 0f b6 c9          	movzx  r9d,r9b
  77:	48 83 c7 04          	add    rdi,0x4
  7b:	48 83 c0 1d          	add    rax,0x1d
  7f:	48 ff c6             	inc    rsi
  82:	4d 39 c1             	cmp    r9,r8
  85:	74 c9                	je     0x50
  87:	4c 31 c2             	xor    rdx,r8
  8a:	eb 11                	jmp    0x9d
  8c:	31 c0                	xor    eax,eax
  8e:	c3                   	ret
  8f:	0f b6 51 4b          	movzx  edx,BYTE PTR [rcx+0x4b]
  93:	49 b9 1c b5 f6 8c de 	movabs r9,0xf43e9fde8cf6b51c
  9a:	9f 3e f4 
  9d:	4c 01 ca             	add    rdx,r9
  a0:	48 b8 16 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c16
  a7:	79 37 9e 
  aa:	c4 e3 fb f0 d2 3b    	rorx   rdx,rdx,0x3b
  b0:	45 31 c0             	xor    r8d,r8d
  b3:	49 89 c9             	mov    r9,rcx
  b6:	45 31 d2             	xor    r10d,r10d
  b9:	48 89 d7             	mov    rdi,rdx
  bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  c0:	49 81 fa 00 01 00 00 	cmp    r10,0x100
  c7:	74 39                	je     0x102
  c9:	48 83 c7 06          	add    rdi,0x6
  cd:	41 0f b6 71 4c       	movzx  esi,BYTE PTR [r9+0x4c]
  d2:	45 89 d3             	mov    r11d,r10d
  d5:	45 31 c3             	xor    r11d,r8d
  d8:	41 81 f3 a5 00 00 00 	xor    r11d,0xa5
  df:	41 83 c3 11          	add    r11d,0x11
  e3:	45 0f b6 db          	movzx  r11d,r11b
  e7:	49 83 c2 04          	add    r10,0x4
  eb:	49 83 c0 1d          	add    r8,0x1d
  ef:	49 ff c1             	inc    r9
  f2:	49 39 f3             	cmp    r11,rsi
  f5:	74 c9                	je     0xc0
  f7:	c1 e6 08             	shl    esi,0x8
  fa:	48 31 fe             	xor    rsi,rdi
  fd:	4c 01 de             	add    rsi,r11
 100:	eb 10                	jmp    0x112
 102:	48 31 c2             	xor    rdx,rax
 105:	0f b6 b1 8b 00 00 00 	movzx  esi,BYTE PTR [rcx+0x8b]
 10c:	c1 e6 08             	shl    esi,0x8
 10f:	48 01 d6             	add    rsi,rdx
 112:	c4 e3 fb f0 f6 3a    	rorx   rsi,rsi,0x3a
 118:	45 31 c0             	xor    r8d,r8d
 11b:	49 89 c9             	mov    r9,rcx
 11e:	45 31 d2             	xor    r10d,r10d
 121:	48 89 f7             	mov    rdi,rsi
 124:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 12b:	00 00 00 00 00 
 130:	49 81 fa 00 01 00 00 	cmp    r10,0x100
 137:	74 3c                	je     0x175
 139:	48 83 c7 07          	add    rdi,0x7
 13d:	41 0f b6 91 8c 00 00 	movzx  edx,BYTE PTR [r9+0x8c]
 144:	00 
 145:	45 89 d3             	mov    r11d,r10d
 148:	45 31 c3             	xor    r11d,r8d
 14b:	41 81 f3 a5 00 00 00 	xor    r11d,0xa5
 152:	41 83 c3 11          	add    r11d,0x11
 156:	45 0f b6 db          	movzx  r11d,r11b
 15a:	49 83 c2 04          	add    r10,0x4
 15e:	49 83 c0 1d          	add    r8,0x1d
 162:	49 ff c1             	inc    r9
 165:	49 39 d3             	cmp    r11,rdx
 168:	74 c6                	je     0x130
 16a:	c1 e2 10             	shl    edx,0x10
 16d:	48 31 fa             	xor    rdx,rdi
 170:	4c 01 da             	add    rdx,r11
 173:	eb 13                	jmp    0x188
 175:	48 ff c0             	inc    rax
 178:	48 31 c6             	xor    rsi,rax
 17b:	0f b6 91 cb 00 00 00 	movzx  edx,BYTE PTR [rcx+0xcb]
 182:	c1 e2 10             	shl    edx,0x10
 185:	48 01 f2             	add    rdx,rsi
 188:	48 89 d0             	mov    rax,rdx
 18b:	48 c1 e8 31          	shr    rax,0x31
 18f:	88 41 07             	mov    BYTE PTR [rcx+0x7],al
 192:	48 89 d0             	mov    rax,rdx
 195:	48 c1 e8 29          	shr    rax,0x29
 199:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
 19c:	48 89 d0             	mov    rax,rdx
 19f:	48 c1 e8 21          	shr    rax,0x21
 1a3:	88 41 05             	mov    BYTE PTR [rcx+0x5],al
 1a6:	48 89 d0             	mov    rax,rdx
 1a9:	48 c1 e8 19          	shr    rax,0x19
 1ad:	88 41 04             	mov    BYTE PTR [rcx+0x4],al
 1b0:	89 d0                	mov    eax,edx
 1b2:	c1 e8 11             	shr    eax,0x11
 1b5:	88 41 03             	mov    BYTE PTR [rcx+0x3],al
 1b8:	89 d0                	mov    eax,edx
 1ba:	c1 e8 09             	shr    eax,0x9
 1bd:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
 1c0:	89 d0                	mov    eax,edx
 1c2:	d1 e8                	shr    eax,1
 1c4:	88 41 01             	mov    BYTE PTR [rcx+0x1],al
 1c7:	c4 e3 fb f0 c2 39    	rorx   rax,rdx,0x39
 1cd:	88 01                	mov    BYTE PTR [rcx],al
 1cf:	b8 02 00 00 00       	mov    eax,0x2
 1d4:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))
#define HC_LEA_ARCH_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | (1ULL << 48))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <payload_prefix_memcmp_scan_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (4) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <payload_prefix_memcmp_scan_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-9) - 1, 0),
    /* 0x1118: lea    rdi,[rcx+0xcc] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_RCX, 0, 0, 1, 0, 204), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <payload_prefix_memcmp_scan_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-16) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi],0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1127: jne    110e <payload_prefix_memcmp_scan_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 0),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-20) - 1, 3),
    /* 0x1129: mov    dl,0x1d [exact-kop: mov8 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x112b: mov    dil,0x4 [exact-kop: mov8 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x112e: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1130: movzx  esi,BYTE PTR [rcx+rax*1+0xc] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RCX, HC_X86_RAX, 0, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1135: lea    r9d,[rdx-0x1d] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R9, HC_X86_RDX, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1139: lea    r8d,[rdi-0x4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R8, HC_X86_RDI, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x113d: xor    r8b,r9b [exact-kop: xorb reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1140: xor    r8b,0xa5 [exact-kop: xorb imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1144: add    r8b,0x11 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1148: cmp    sil,r8b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x114b: jne    1186 <payload_prefix_memcmp_scan_xdp+0x86> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, (34) - 1, 0),
    /* 0x114d: movzx  esi,BYTE PTR [rcx+rax*1+0xd] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RCX, HC_X86_RAX, 0, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1152: mov    r8d,edx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1155: xor    r8b,dil [exact-kop: xorb reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1158: xor    r8b,0xa5 [exact-kop: xorb imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x115c: add    r8b,0x11 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1160: add    rax,0x2 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1164: cmp    sil,r8b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1167: jne    1189 <payload_prefix_memcmp_scan_xdp+0x89> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, (17) - 1, 0),
    /* 0x1169: add    dl,0x3a [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x116c: add    dil,0x8 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1170: cmp    rax,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1174: jne    1130 <payload_prefix_memcmp_scan_xdp+0x30> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-44) - 1, 64),
    /* 0x1176: movzx  eax,BYTE PTR [rcx+0x4b] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RCX, 75), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x117a: movabs rdx,0xf43e9fde8cf6b51c [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0xf43e9fde8cf6b51cULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1184: jmp    11a7 <payload_prefix_memcmp_scan_xdp+0xa7> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (19) - 1, 0),
    /* 0x1186: inc    rax [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1189: mov    eax,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x118b: lea    rax,[rax+rax*4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, HC_X86_RAX, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x118f: movabs rdx,0x6a09e667f3bcc909 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x6a09e667f3bcc909ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1199: add    rdx,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x119c: movzx  eax,sil [exact-kop: movzx r32,r8 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a0: xor    rax,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11a3: movzx  edx,r8b [exact-kop: movzx r32,r8 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a7: add    rdx,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11aa: rol    rdx,0x5 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 5), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11ae: mov    sil,0x1d [exact-kop: mov8 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RSI, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11b1: mov    dil,0x4 [exact-kop: mov8 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x11b4: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11b6: cs nop WORD PTR [rax+rax*1+0x0] [padding: prefixed nop padding is not part of BPF semantics] */
    /* 0x11c0: movzx  r8d,BYTE PTR [rcx+rax*1+0x4c] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_R8, HC_X86_RCX, HC_X86_RAX, 0, 76), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11c6: lea    r10d,[rsi-0x1d] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R10, HC_X86_RSI, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ca: lea    r9d,[rdi-0x4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R9, HC_X86_RDI, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ce: xor    r9b,r10b [exact-kop: xorb reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11d1: xor    r9b,0xa5 [exact-kop: xorb imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11d5: add    r9b,0x11 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x11d9: cmp    r8b,r9b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11dc: jne    1222 <payload_prefix_memcmp_scan_xdp+0x122> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, (38) - 1, 0),
    /* 0x11de: movzx  r8d,BYTE PTR [rcx+rax*1+0x4d] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_R8, HC_X86_RCX, HC_X86_RAX, 0, 77), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11e4: mov    r9d,esi [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e7: xor    r9b,dil [exact-kop: xorb reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11ea: xor    r9b,0xa5 [exact-kop: xorb imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x11ee: add    r9b,0x11 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x11f2: add    rax,0x2 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11f6: cmp    r8b,r9b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11f9: jne    1225 <payload_prefix_memcmp_scan_xdp+0x125> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, (21) - 1, 0),
    /* 0x11fb: add    sil,0x3a [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RSI, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x11ff: add    dil,0x8 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1203: cmp    rax,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1207: jne    11c0 <payload_prefix_memcmp_scan_xdp+0xc0> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-44) - 1, 64),
    /* 0x1209: movabs rax,0x9e3779b97f4a7c16 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b97f4a7c16ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RAX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1213: xor    rdx,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1216: movzx  eax,BYTE PTR [rcx+0x8b] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RCX, 139), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x121d: shl    eax,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1220: jmp    123d <payload_prefix_memcmp_scan_xdp+0x13d> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (17) - 1, 0),
    /* 0x1222: inc    rax [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1225: mov    eax,eax [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1227: lea    rax,[rax+rax*2] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, HC_X86_RAX, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x122b: lea    rax,[rdx+rax*2] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RDX, HC_X86_RAX, 1, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x122f: movzx  edx,r8b [exact-kop: movzx r32,r8 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1233: shl    edx,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1236: xor    rdx,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1239: movzx  eax,r9b [exact-kop: movzx r32,r8 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x123d: add    rax,rdx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1240: rol    rax,0x6 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RAX, HC_X86_RAX, 6), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1244: mov    dil,0x1d [exact-kop: mov8 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 29), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1247: mov    r8b,0x4 [exact-kop: mov8 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x124a: xor    edx,edx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x124c: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: movzx  esi,BYTE PTR [rcx+rdx*1+0x8c] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RCX, HC_X86_RDX, 0, 140), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1258: lea    r10d,[rdi-0x1d] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R10, HC_X86_RDI, 0, 0, 1, 0, -29), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x125c: lea    r9d,[r8-0x4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R9, HC_X86_R8, 0, 0, 1, 0, -4), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1260: xor    r9b,r10b [exact-kop: xorb reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1263: xor    r9b,0xa5 [exact-kop: xorb imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1267: add    r9b,0x11 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x126b: cmp    sil,r9b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x126e: jne    12bd <payload_prefix_memcmp_scan_xdp+0x1bd> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, (42) - 1, 0),
    /* 0x1270: movzx  esi,BYTE PTR [rcx+rdx*1+0x8d] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RCX, HC_X86_RDX, 0, 141), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1278: mov    r9d,edi [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127b: xor    r9b,r8b [exact-kop: xorb reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x127e: xor    r9b,0xa5 [exact-kop: xorb imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 165), MICRO_HANDCRAFT_BPF_X86_XORB),
    /* 0x1282: add    r9b,0x11 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 17), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1286: add    rdx,0x2 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x128a: cmp    sil,r9b [control-flow-operand: cmp folded into BPF branch] */
    /* 0x128d: jne    12c0 <payload_prefix_memcmp_scan_xdp+0x1c0> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_7, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_X, BPF_REG_6, BPF_REG_7, (25) - 1, 0),
    /* 0x128f: add    dil,0x3a [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 58), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1293: add    r8b,0x8 [exact-kop: add8 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 8), MICRO_HANDCRAFT_BPF_X86_ADDB),
    /* 0x1297: cmp    rdx,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x129b: jne    1250 <payload_prefix_memcmp_scan_xdp+0x150> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-44) - 1, 64),
    /* 0x129d: movabs rdx,0x9e3779b97f4a7c16 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b97f4a7c16ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12a7: or     rdx,0x1 [exact-kop: or64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 1), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x12ab: xor    rax,rdx [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ae: movzx  edx,BYTE PTR [rcx+0xcb] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 203), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12b5: shl    edx,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12b8: add    rdx,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12bb: jmp    12e1 <payload_prefix_memcmp_scan_xdp+0x1e1> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (21) - 1, 0),
    /* 0x12bd: inc    rdx [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x12c0: mov    edx,edx [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12c2: lea    rdi,[rdx*8+0x0] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDI, 0, HC_X86_RDX, 3, 0, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x12ca: sub    rdi,rdx [exact-kop: sub64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_SUBQ),
    /* 0x12cd: add    rax,rdi [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12d0: movzx  esi,sil [exact-kop: movzx r32,r8 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d4: shl    esi,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d7: xor    rsi,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12da: movzx  edx,r9b [exact-kop: movzx r32,r8 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12de: add    rdx,rsi [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12e1: rol    rdx,0x7 [exact-kop: rolq imm kop] */
    HC_KOP(HC_ROTATE_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RDX, 7), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x12e5: mov    QWORD PTR [rcx],rdx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x12e8: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ed: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
