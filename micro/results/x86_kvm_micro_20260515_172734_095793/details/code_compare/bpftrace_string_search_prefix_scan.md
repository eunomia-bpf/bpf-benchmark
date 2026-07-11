# bpftrace_string_search_prefix_scan

## Original C
```c
#include "common.h"

#define BPFTRACE_HAYSTACK_SIZE 96U
#define BPFTRACE_NEEDLE_SIZE 8U
#define BPFTRACE_SCAN_LIMIT (BPFTRACE_HAYSTACK_SIZE - BPFTRACE_NEEDLE_SIZE + 1U)
#define BPFTRACE_STRING_INPUT_SIZE (8U + BPFTRACE_HAYSTACK_SIZE + BPFTRACE_NEEDLE_SIZE)

static __always_inline u32 bpftrace_bounded_strlen(const u8 *data, u32 base)
{
    u32 len = 0;

    for (u32 index = 0; index < BPFTRACE_NEEDLE_SIZE; index++) {
        if (data[base + index] == 0) {
            break;
        }
        len++;
    }
    return len;
}

static __always_inline int
bench_bpftrace_string_search_prefix_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BPFTRACE_STRING_INPUT_SIZE)) {
        return -1;
    }

    u32 haystack_len = micro_read_u32_le(data, 0U);
    u32 declared_needle_len = micro_read_u32_le(data, 4U);
    u32 needle_base = 8U + BPFTRACE_HAYSTACK_SIZE;
    u32 needle_len = bpftrace_bounded_strlen(data, needle_base);
    if (haystack_len > BPFTRACE_HAYSTACK_SIZE ||
        declared_needle_len != needle_len ||
        needle_len == 0U) {
        return -1;
    }

    u64 acc = 0xD1B54A32D192ED03ULL;
    u32 found = BPFTRACE_HAYSTACK_SIZE;
    for (u32 pos = 0; pos < BPFTRACE_SCAN_LIMIT; pos++) {
        u32 diff = 0;

        if (pos + needle_len > haystack_len) {
            continue;
        }
        for (u32 index = 0; index < BPFTRACE_NEEDLE_SIZE; index++) {
            if (index < needle_len) {
                diff |= (u32)data[8U + pos + index] ^ data[needle_base + index];
            }
        }
        if (diff == 0U) {
            found = pos;
            break;
        }
    }

    if (found != BPFTRACE_HAYSTACK_SIZE) {
        acc += (u64)(found + 1U) * (u64)(needle_len + 3U);
        acc ^= micro_rotl64(((u64)needle_len << 32U) | found, 3U);
    } else {
        acc ^= 0x9E3779B97F4A7C15ULL;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bpftrace_string_search_prefix_scan_xdp,
    bench_bpftrace_string_search_prefix_scan,
    bpftrace_string_search_prefix_scan_input_value,
    BPFTRACE_STRING_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <bpftrace_string_search_prefix_scan_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	0f 87 b6 01 00 00    	ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    1112:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1116:	48 39 d6             	cmp    rsi,rdx
    1119:	0f 87 a9 01 00 00    	ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    111f:	48 8d 71 78          	lea    rsi,[rcx+0x78]
    1123:	48 39 d6             	cmp    rsi,rdx
    1126:	0f 87 9c 01 00 00    	ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    112c:	53                   	push   rbx
    112d:	8b 79 08             	mov    edi,DWORD PTR [rcx+0x8]
    1130:	0f b6 51 70          	movzx  edx,BYTE PTR [rcx+0x70]
    1134:	31 c0                	xor    eax,eax
    1136:	41 b8 00 00 00 00    	mov    r8d,0x0
    113c:	84 d2                	test   dl,dl
    113e:	74 62                	je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1140:	80 79 71 00          	cmp    BYTE PTR [rcx+0x71],0x0
    1144:	74 2e                	je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74>
    1146:	80 79 72 00          	cmp    BYTE PTR [rcx+0x72],0x0
    114a:	74 30                	je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c>
    114c:	80 79 73 00          	cmp    BYTE PTR [rcx+0x73],0x0
    1150:	74 32                	je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84>
    1152:	80 79 74 00          	cmp    BYTE PTR [rcx+0x74],0x0
    1156:	74 34                	je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c>
    1158:	80 79 75 00          	cmp    BYTE PTR [rcx+0x75],0x0
    115c:	74 36                	je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94>
    115e:	80 79 76 00          	cmp    BYTE PTR [rcx+0x76],0x0
    1162:	74 38                	je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c>
    1164:	80 79 77 01          	cmp    BYTE PTR [rcx+0x77],0x1
    1168:	41 b8 08 00 00 00    	mov    r8d,0x8
    116e:	41 83 d8 00          	sbb    r8d,0x0
    1172:	eb 2e                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1174:	41 b8 01 00 00 00    	mov    r8d,0x1
    117a:	eb 26                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    117c:	41 b8 02 00 00 00    	mov    r8d,0x2
    1182:	eb 1e                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1184:	41 b8 03 00 00 00    	mov    r8d,0x3
    118a:	eb 16                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    118c:	41 b8 04 00 00 00    	mov    r8d,0x4
    1192:	eb 0e                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1194:	41 b8 05 00 00 00    	mov    r8d,0x5
    119a:	eb 06                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    119c:	41 b8 06 00 00 00    	mov    r8d,0x6
    11a2:	83 ff 60             	cmp    edi,0x60
    11a5:	0f 87 1c 01 00 00    	ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7>
    11ab:	8b 71 0c             	mov    esi,DWORD PTR [rcx+0xc]
    11ae:	44 39 c6             	cmp    esi,r8d
    11b1:	0f 85 10 01 00 00    	jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7>
    11b7:	84 d2                	test   dl,dl
    11b9:	0f 84 08 01 00 00    	je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7>
    11bf:	48 b8 16 91 d8 ae 8b 	movabs rax,0x4f82338baed89116
    11c6:	33 82 4f 
    11c9:	41 89 f9             	mov    r9d,edi
    11cc:	44 8d 56 03          	lea    r10d,[rsi+0x3]
    11d0:	48 bf 03 ed 92 d1 32 	movabs rdi,0xd1b54a32d192ed03
    11d7:	4a b5 d1 
    11da:	4c 01 d7             	add    rdi,r10
    11dd:	45 31 c0             	xor    r8d,r8d
    11e0:	eb 27                	jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109>
    11e2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11e9:	1f 84 00 00 00 00 00 
    11f0:	45 84 db             	test   r11b,r11b
    11f3:	0f 84 af 00 00 00    	je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8>
    11f9:	49 ff c0             	inc    r8
    11fc:	4c 01 d7             	add    rdi,r10
    11ff:	49 83 f8 59          	cmp    r8,0x59
    1203:	0f 84 b6 00 00 00    	je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf>
    1209:	4e 8d 1c 06          	lea    r11,[rsi+r8*1]
    120d:	4d 39 cb             	cmp    r11,r9
    1210:	77 e7                	ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9>
    1212:	48 85 f6             	test   rsi,rsi
    1215:	0f 84 8d 00 00 00    	je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8>
    121b:	46 0f b6 5c 01 10    	movzx  r11d,BYTE PTR [rcx+r8*1+0x10]
    1221:	41 30 d3             	xor    r11b,dl
    1224:	83 fe 02             	cmp    esi,0x2
    1227:	72 c7                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1229:	0f b6 59 71          	movzx  ebx,BYTE PTR [rcx+0x71]
    122d:	42 32 5c 01 11       	xor    bl,BYTE PTR [rcx+r8*1+0x11]
    1232:	41 08 db             	or     r11b,bl
    1235:	83 fe 03             	cmp    esi,0x3
    1238:	72 b6                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    123a:	0f b6 59 72          	movzx  ebx,BYTE PTR [rcx+0x72]
    123e:	42 32 5c 01 12       	xor    bl,BYTE PTR [rcx+r8*1+0x12]
    1243:	41 08 db             	or     r11b,bl
    1246:	83 fe 04             	cmp    esi,0x4
    1249:	72 a5                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    124b:	0f b6 59 73          	movzx  ebx,BYTE PTR [rcx+0x73]
    124f:	42 32 5c 01 13       	xor    bl,BYTE PTR [rcx+r8*1+0x13]
    1254:	41 08 db             	or     r11b,bl
    1257:	83 fe 05             	cmp    esi,0x5
    125a:	72 94                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    125c:	0f b6 59 74          	movzx  ebx,BYTE PTR [rcx+0x74]
    1260:	42 32 5c 01 14       	xor    bl,BYTE PTR [rcx+r8*1+0x14]
    1265:	41 08 db             	or     r11b,bl
    1268:	83 fe 06             	cmp    esi,0x6
    126b:	72 83                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    126d:	0f b6 59 75          	movzx  ebx,BYTE PTR [rcx+0x75]
    1271:	42 32 5c 01 15       	xor    bl,BYTE PTR [rcx+r8*1+0x15]
    1276:	41 08 db             	or     r11b,bl
    1279:	83 fe 07             	cmp    esi,0x7
    127c:	0f 82 6e ff ff ff    	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1282:	0f b6 59 76          	movzx  ebx,BYTE PTR [rcx+0x76]
    1286:	42 32 5c 01 16       	xor    bl,BYTE PTR [rcx+r8*1+0x16]
    128b:	41 08 db             	or     r11b,bl
    128e:	83 fe 08             	cmp    esi,0x8
    1291:	0f 82 59 ff ff ff    	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1297:	0f b6 59 77          	movzx  ebx,BYTE PTR [rcx+0x77]
    129b:	42 32 5c 01 17       	xor    bl,BYTE PTR [rcx+r8*1+0x17]
    12a0:	41 08 db             	or     r11b,bl
    12a3:	e9 48 ff ff ff       	jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    12a8:	49 83 f8 60          	cmp    r8,0x60
    12ac:	74 11                	je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf>
    12ae:	48 c1 e6 20          	shl    rsi,0x20
    12b2:	4c 01 c6             	add    rsi,r8
    12b5:	48 c1 c6 03          	rol    rsi,0x3
    12b9:	48 31 f7             	xor    rdi,rsi
    12bc:	48 89 f8             	mov    rax,rdi
    12bf:	48 89 01             	mov    QWORD PTR [rcx],rax
    12c2:	b8 02 00 00 00       	mov    eax,0x2
    12c7:	5b                   	pop    rbx
    12c8:	c3                   	ret

Disassembly of section .fini:
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 20 00 00 00 	sub    rsp,0x20
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  24:	48 39 f7             	cmp    rdi,rsi
  27:	0f 87 6d 03 00 00    	ja     0x39a
  2d:	48 89 fa             	mov    rdx,rdi
  30:	48 83 c2 08          	add    rdx,0x8
  34:	48 39 f2             	cmp    rdx,rsi
  37:	0f 87 5d 03 00 00    	ja     0x39a
  3d:	48 89 fa             	mov    rdx,rdi
  40:	48 83 c2 78          	add    rdx,0x78
  44:	48 39 f2             	cmp    rdx,rsi
  47:	0f 87 4d 03 00 00    	ja     0x39a
  4d:	4c 0f b6 7f 70       	movzx  r15,BYTE PTR [rdi+0x70]
  52:	4d 85 ff             	test   r15,r15
  55:	0f 84 3f 03 00 00    	je     0x39a
  5b:	48 0f b6 57 09       	movzx  rdx,BYTE PTR [rdi+0x9]
  60:	48 c1 e2 08          	shl    rdx,0x8
  64:	48 0f b6 77 08       	movzx  rsi,BYTE PTR [rdi+0x8]
  69:	48 09 f2             	or     rdx,rsi
  6c:	48 0f b6 77 0a       	movzx  rsi,BYTE PTR [rdi+0xa]
  71:	48 c1 e6 10          	shl    rsi,0x10
  75:	48 09 f2             	or     rdx,rsi
  78:	48 0f b6 77 0b       	movzx  rsi,BYTE PTR [rdi+0xb]
  7d:	48 c1 e6 18          	shl    rsi,0x18
  81:	48 09 f2             	or     rdx,rsi
  84:	be 01 00 00 00       	mov    esi,0x1
  89:	48 0f b6 4f 71       	movzx  rcx,BYTE PTR [rdi+0x71]
  8e:	48 85 c9             	test   rcx,rcx
  91:	74 5f                	je     0xf2
  93:	be 02 00 00 00       	mov    esi,0x2
  98:	48 0f b6 4f 72       	movzx  rcx,BYTE PTR [rdi+0x72]
  9d:	48 85 c9             	test   rcx,rcx
  a0:	74 50                	je     0xf2
  a2:	be 03 00 00 00       	mov    esi,0x3
  a7:	48 0f b6 4f 73       	movzx  rcx,BYTE PTR [rdi+0x73]
  ac:	48 85 c9             	test   rcx,rcx
  af:	74 41                	je     0xf2
  b1:	be 04 00 00 00       	mov    esi,0x4
  b6:	48 0f b6 4f 74       	movzx  rcx,BYTE PTR [rdi+0x74]
  bb:	48 85 c9             	test   rcx,rcx
  be:	74 32                	je     0xf2
  c0:	be 05 00 00 00       	mov    esi,0x5
  c5:	48 0f b6 4f 75       	movzx  rcx,BYTE PTR [rdi+0x75]
  ca:	48 85 c9             	test   rcx,rcx
  cd:	74 23                	je     0xf2
  cf:	be 06 00 00 00       	mov    esi,0x6
  d4:	48 0f b6 4f 76       	movzx  rcx,BYTE PTR [rdi+0x76]
  d9:	48 85 c9             	test   rcx,rcx
  dc:	74 14                	je     0xf2
  de:	be 07 00 00 00       	mov    esi,0x7
  e3:	48 0f b6 4f 77       	movzx  rcx,BYTE PTR [rdi+0x77]
  e8:	48 85 c9             	test   rcx,rcx
  eb:	74 05                	je     0xf2
  ed:	be 08 00 00 00       	mov    esi,0x8
  f2:	48 89 d1             	mov    rcx,rdx
  f5:	48 c1 e1 20          	shl    rcx,0x20
  f9:	48 c1 e9 20          	shr    rcx,0x20
  fd:	48 83 f9 60          	cmp    rcx,0x60
 101:	0f 87 93 02 00 00    	ja     0x39a
 107:	48 0f b6 5f 0d       	movzx  rbx,BYTE PTR [rdi+0xd]
 10c:	48 c1 e3 08          	shl    rbx,0x8
 110:	4c 0f b6 6f 0c       	movzx  r13,BYTE PTR [rdi+0xc]
 115:	4c 0f b6 77 0e       	movzx  r14,BYTE PTR [rdi+0xe]
 11a:	48 89 d9             	mov    rcx,rbx
 11d:	4c 09 e9             	or     rcx,r13
 120:	49 c1 e6 10          	shl    r14,0x10
 124:	4c 0f b6 47 0f       	movzx  r8,BYTE PTR [rdi+0xf]
 129:	4c 09 f1             	or     rcx,r14
 12c:	49 c1 e0 18          	shl    r8,0x18
 130:	4c 09 c1             	or     rcx,r8
 133:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
 137:	48 c1 e1 20          	shl    rcx,0x20
 13b:	48 c1 e9 20          	shr    rcx,0x20
 13f:	48 39 f1             	cmp    rcx,rsi
 142:	0f 85 52 02 00 00    	jne    0x39a
 148:	4d 85 ff             	test   r15,r15
 14b:	0f 84 49 02 00 00    	je     0x39a
 151:	4d 01 f0             	add    r8,r14
 154:	49 01 d8             	add    r8,rbx
 157:	4d 01 e8             	add    r8,r13
 15a:	31 db                	xor    ebx,ebx
 15c:	48 c1 e2 20          	shl    rdx,0x20
 160:	48 c1 ea 20          	shr    rdx,0x20
 164:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 168:	48 c1 e6 20          	shl    rsi,0x20
 16c:	48 c1 ee 20          	shr    rsi,0x20
 170:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
 174:	4c 89 c0             	mov    rax,r8
 177:	48 c1 e0 20          	shl    rax,0x20
 17b:	48 c1 e8 20          	shr    rax,0x20
 17f:	49 83 c0 03          	add    r8,0x3
 183:	49 c1 e0 20          	shl    r8,0x20
 187:	49 c1 e8 20          	shr    r8,0x20
 18b:	48 be 03 ed 92 d1 32 	movabs rsi,0xd1b54a32d192ed03
 192:	4a b5 d1 
 195:	4d 89 c5             	mov    r13,r8
 198:	49 01 f5             	add    r13,rsi
 19b:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 19f:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
 1a3:	eb 2f                	jmp    0x1d4
 1a5:	48 81 e6 ff 00 00 00 	and    rsi,0xff
 1ac:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 1b0:	48 85 f6             	test   rsi,rsi
 1b3:	0f 84 65 01 00 00    	je     0x31e
 1b9:	4d 01 c5             	add    r13,r8
 1bc:	48 be 16 91 d8 ae 8b 	movabs rsi,0x4f82338baed89116
 1c3:	33 82 4f 
 1c6:	48 83 c3 01          	add    rbx,0x1
 1ca:	48 83 fb 59          	cmp    rbx,0x59
 1ce:	0f 84 79 01 00 00    	je     0x34d
 1d4:	48 89 c6             	mov    rsi,rax
 1d7:	48 01 de             	add    rsi,rbx
 1da:	48 39 d6             	cmp    rsi,rdx
 1dd:	77 da                	ja     0x1b9
 1df:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 1e3:	48 c1 e1 20          	shl    rcx,0x20
 1e7:	48 c1 e9 20          	shr    rcx,0x20
 1eb:	48 85 c9             	test   rcx,rcx
 1ee:	0f 84 2a 01 00 00    	je     0x31e
 1f4:	48 89 f8             	mov    rax,rdi
 1f7:	48 01 d8             	add    rax,rbx
 1fa:	4c 0f b6 70 10       	movzx  r14,BYTE PTR [rax+0x10]
 1ff:	4c 89 fe             	mov    rsi,r15
 202:	4c 31 f6             	xor    rsi,r14
 205:	41 be 02 00 00 00    	mov    r14d,0x2
 20b:	49 39 ce             	cmp    r14,rcx
 20e:	77 95                	ja     0x1a5
 210:	48 0f b6 48 11       	movzx  rcx,BYTE PTR [rax+0x11]
 215:	48 0f b6 47 71       	movzx  rax,BYTE PTR [rdi+0x71]
 21a:	48 31 c8             	xor    rax,rcx
 21d:	48 09 c6             	or     rsi,rax
 220:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 224:	48 c1 e1 20          	shl    rcx,0x20
 228:	48 c1 e9 20          	shr    rcx,0x20
 22c:	b8 03 00 00 00       	mov    eax,0x3
 231:	48 39 c8             	cmp    rax,rcx
 234:	0f 87 6b ff ff ff    	ja     0x1a5
 23a:	48 89 f8             	mov    rax,rdi
 23d:	48 01 d8             	add    rax,rbx
 240:	4c 0f b6 70 12       	movzx  r14,BYTE PTR [rax+0x12]
 245:	4c 0f b6 7f 72       	movzx  r15,BYTE PTR [rdi+0x72]
 24a:	4d 31 f7             	xor    r15,r14
 24d:	4c 09 fe             	or     rsi,r15
 250:	4c 8b 7d e8          	mov    r15,QWORD PTR [rbp-0x18]
 254:	41 be 04 00 00 00    	mov    r14d,0x4
 25a:	49 39 ce             	cmp    r14,rcx
 25d:	0f 87 42 ff ff ff    	ja     0x1a5
 263:	48 0f b6 48 13       	movzx  rcx,BYTE PTR [rax+0x13]
 268:	48 0f b6 47 73       	movzx  rax,BYTE PTR [rdi+0x73]
 26d:	48 31 c8             	xor    rax,rcx
 270:	48 09 c6             	or     rsi,rax
 273:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 277:	48 c1 e1 20          	shl    rcx,0x20
 27b:	48 c1 e9 20          	shr    rcx,0x20
 27f:	b8 05 00 00 00       	mov    eax,0x5
 284:	48 39 c8             	cmp    rax,rcx
 287:	0f 87 18 ff ff ff    	ja     0x1a5
 28d:	48 89 f8             	mov    rax,rdi
 290:	48 01 d8             	add    rax,rbx
 293:	4c 0f b6 70 14       	movzx  r14,BYTE PTR [rax+0x14]
 298:	4c 0f b6 7f 74       	movzx  r15,BYTE PTR [rdi+0x74]
 29d:	4d 31 f7             	xor    r15,r14
 2a0:	4c 09 fe             	or     rsi,r15
 2a3:	4c 8b 7d e8          	mov    r15,QWORD PTR [rbp-0x18]
 2a7:	41 be 06 00 00 00    	mov    r14d,0x6
 2ad:	49 39 ce             	cmp    r14,rcx
 2b0:	0f 87 ef fe ff ff    	ja     0x1a5
 2b6:	48 0f b6 48 15       	movzx  rcx,BYTE PTR [rax+0x15]
 2bb:	48 0f b6 47 75       	movzx  rax,BYTE PTR [rdi+0x75]
 2c0:	48 31 c8             	xor    rax,rcx
 2c3:	48 09 c6             	or     rsi,rax
 2c6:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 2ca:	48 c1 e1 20          	shl    rcx,0x20
 2ce:	48 c1 e9 20          	shr    rcx,0x20
 2d2:	b8 07 00 00 00       	mov    eax,0x7
 2d7:	48 39 c8             	cmp    rax,rcx
 2da:	0f 87 c5 fe ff ff    	ja     0x1a5
 2e0:	48 89 f8             	mov    rax,rdi
 2e3:	48 01 d8             	add    rax,rbx
 2e6:	4c 0f b6 70 16       	movzx  r14,BYTE PTR [rax+0x16]
 2eb:	4c 0f b6 7f 76       	movzx  r15,BYTE PTR [rdi+0x76]
 2f0:	4d 31 f7             	xor    r15,r14
 2f3:	4c 09 fe             	or     rsi,r15
 2f6:	4c 8b 7d e8          	mov    r15,QWORD PTR [rbp-0x18]
 2fa:	41 be 08 00 00 00    	mov    r14d,0x8
 300:	49 39 ce             	cmp    r14,rcx
 303:	0f 87 9c fe ff ff    	ja     0x1a5
 309:	48 0f b6 48 17       	movzx  rcx,BYTE PTR [rax+0x17]
 30e:	48 0f b6 47 77       	movzx  rax,BYTE PTR [rdi+0x77]
 313:	48 31 c8             	xor    rax,rcx
 316:	48 09 c6             	or     rsi,rax
 319:	e9 87 fe ff ff       	jmp    0x1a5
 31e:	48 be 16 91 d8 ae 8b 	movabs rsi,0x4f82338baed89116
 325:	33 82 4f 
 328:	48 83 fb 60          	cmp    rbx,0x60
 32c:	74 1f                	je     0x34d
 32e:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 332:	48 c1 e2 20          	shl    rdx,0x20
 336:	48 01 da             	add    rdx,rbx
 339:	48 89 d6             	mov    rsi,rdx
 33c:	48 c1 ee 3d          	shr    rsi,0x3d
 340:	48 c1 e2 03          	shl    rdx,0x3
 344:	48 09 f2             	or     rdx,rsi
 347:	49 31 d5             	xor    r13,rdx
 34a:	4c 89 ee             	mov    rsi,r13
 34d:	48 89 f2             	mov    rdx,rsi
 350:	48 c1 ea 38          	shr    rdx,0x38
 354:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 357:	48 89 f2             	mov    rdx,rsi
 35a:	48 c1 ea 30          	shr    rdx,0x30
 35e:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 361:	48 89 f2             	mov    rdx,rsi
 364:	48 c1 ea 28          	shr    rdx,0x28
 368:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 36b:	48 89 f2             	mov    rdx,rsi
 36e:	48 c1 ea 20          	shr    rdx,0x20
 372:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 375:	48 89 f2             	mov    rdx,rsi
 378:	48 c1 ea 18          	shr    rdx,0x18
 37c:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 37f:	48 89 f2             	mov    rdx,rsi
 382:	48 c1 ea 10          	shr    rdx,0x10
 386:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 389:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
 38d:	48 c1 ee 08          	shr    rsi,0x8
 391:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
 395:	b8 02 00 00 00       	mov    eax,0x2
 39a:	41 5f                	pop    r15
 39c:	41 5e                	pop    r14
 39e:	41 5d                	pop    r13
 3a0:	5b                   	pop    rbx
 3a1:	c9                   	leave
 3a2:	c3                   	ret
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
   d:	0f 87 1a 01 00 00    	ja     0x12d
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 0d 01 00 00    	ja     0x12d
  20:	48 8d 71 78          	lea    rsi,[rcx+0x78]
  24:	48 39 d6             	cmp    rsi,rdx
  27:	0f 87 00 01 00 00    	ja     0x12d
  2d:	55                   	push   rbp
  2e:	41 57                	push   r15
  30:	41 56                	push   r14
  32:	53                   	push   rbx
  33:	0f b6 41 70          	movzx  eax,BYTE PTR [rcx+0x70]
  37:	84 c0                	test   al,al
  39:	0f 84 e6 00 00 00    	je     0x125
  3f:	0f b6 51 09          	movzx  edx,BYTE PTR [rcx+0x9]
  43:	44 0f b6 41 08       	movzx  r8d,BYTE PTR [rcx+0x8]
  48:	44 0f b6 51 0a       	movzx  r10d,BYTE PTR [rcx+0xa]
  4d:	44 0f b6 49 0b       	movzx  r9d,BYTE PTR [rcx+0xb]
  52:	0f b6 79 71          	movzx  edi,BYTE PTR [rcx+0x71]
  56:	40 84 ff             	test   dil,dil
  59:	74 2d                	je     0x88
  5b:	80 79 72 00          	cmp    BYTE PTR [rcx+0x72],0x0
  5f:	74 2e                	je     0x8f
  61:	80 79 73 00          	cmp    BYTE PTR [rcx+0x73],0x0
  65:	74 2f                	je     0x96
  67:	80 79 74 00          	cmp    BYTE PTR [rcx+0x74],0x0
  6b:	74 30                	je     0x9d
  6d:	80 79 75 00          	cmp    BYTE PTR [rcx+0x75],0x0
  71:	74 31                	je     0xa4
  73:	80 79 76 00          	cmp    BYTE PTR [rcx+0x76],0x0
  77:	74 32                	je     0xab
  79:	80 79 77 01          	cmp    BYTE PTR [rcx+0x77],0x1
  7d:	be 08 00 00 00       	mov    esi,0x8
  82:	48 83 de 00          	sbb    rsi,0x0
  86:	eb 28                	jmp    0xb0
  88:	be 01 00 00 00       	mov    esi,0x1
  8d:	eb 21                	jmp    0xb0
  8f:	be 02 00 00 00       	mov    esi,0x2
  94:	eb 1a                	jmp    0xb0
  96:	be 03 00 00 00       	mov    esi,0x3
  9b:	eb 13                	jmp    0xb0
  9d:	be 04 00 00 00       	mov    esi,0x4
  a2:	eb 0c                	jmp    0xb0
  a4:	be 05 00 00 00       	mov    esi,0x5
  a9:	eb 05                	jmp    0xb0
  ab:	be 06 00 00 00       	mov    esi,0x6
  b0:	41 c1 e1 18          	shl    r9d,0x18
  b4:	41 c1 e2 10          	shl    r10d,0x10
  b8:	c1 e2 08             	shl    edx,0x8
  bb:	4c 09 c2             	or     rdx,r8
  be:	4c 09 d2             	or     rdx,r10
  c1:	4c 09 ca             	or     rdx,r9
  c4:	48 83 fa 60          	cmp    rdx,0x60
  c8:	77 5b                	ja     0x125
  ca:	44 8b 41 0c          	mov    r8d,DWORD PTR [rcx+0xc]
  ce:	49 39 f0             	cmp    r8,rsi
  d1:	75 52                	jne    0x125
  d3:	49 b9 fa 12 6d 2e cd 	movabs r9,0x2e4ab5cd2e6d12fa
  da:	b5 4a 2e 
  dd:	48 83 fe 01          	cmp    rsi,0x1
  e1:	75 4b                	jne    0x12e
  e3:	48 c7 c7 fd ff ff ff 	mov    rdi,0xfffffffffffffffd
  ea:	4c 29 c7             	sub    rdi,r8
  ed:	45 31 d2             	xor    r10d,r10d
  f0:	eb 1e                	jmp    0x110
  f2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  f9:	1f 84 00 00 00 00 00 
 100:	49 ff c2             	inc    r10
 103:	49 01 f9             	add    r9,rdi
 106:	49 83 fa 59          	cmp    r10,0x59
 10a:	0f 84 ab 00 00 00    	je     0x1bb
 110:	4f 8d 1c 10          	lea    r11,[r8+r10*1]
 114:	49 39 d3             	cmp    r11,rdx
 117:	77 e7                	ja     0x100
 119:	42 38 44 11 10       	cmp    BYTE PTR [rcx+r10*1+0x10],al
 11e:	75 e0                	jne    0x100
 120:	e9 89 00 00 00       	jmp    0x1ae
 125:	31 c0                	xor    eax,eax
 127:	5b                   	pop    rbx
 128:	41 5e                	pop    r14
 12a:	41 5f                	pop    r15
 12c:	5d                   	pop    rbp
 12d:	c3                   	ret
 12e:	49 c7 c3 fd ff ff ff 	mov    r11,0xfffffffffffffffd
 135:	4d 29 c3             	sub    r11,r8
 138:	45 31 d2             	xor    r10d,r10d
 13b:	48 83 fe 02          	cmp    rsi,0x2
 13f:	76 1b                	jbe    0x15c
 141:	48 83 fe 03          	cmp    rsi,0x3
 145:	0f 85 bd 00 00 00    	jne    0x208
 14b:	eb 3f                	jmp    0x18c
 14d:	0f 1f 00             	nop    DWORD PTR [rax]
 150:	49 ff c2             	inc    r10
 153:	4d 01 d9             	add    r9,r11
 156:	49 83 fa 59          	cmp    r10,0x59
 15a:	74 5f                	je     0x1bb
 15c:	4b 8d 1c 10          	lea    rbx,[r8+r10*1]
 160:	48 39 d3             	cmp    rbx,rdx
 163:	77 eb                	ja     0x150
 165:	42 38 7c 11 11       	cmp    BYTE PTR [rcx+r10*1+0x11],dil
 16a:	75 e4                	jne    0x150
 16c:	42 38 44 11 10       	cmp    BYTE PTR [rcx+r10*1+0x10],al
 171:	75 dd                	jne    0x150
 173:	eb 39                	jmp    0x1ae
 175:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
 17c:	00 00 00 00 
 180:	49 ff c2             	inc    r10
 183:	4d 01 d9             	add    r9,r11
 186:	49 83 fa 59          	cmp    r10,0x59
 18a:	74 2f                	je     0x1bb
 18c:	4b 8d 1c 10          	lea    rbx,[r8+r10*1]
 190:	48 39 d3             	cmp    rbx,rdx
 193:	77 eb                	ja     0x180
 195:	42 38 7c 11 11       	cmp    BYTE PTR [rcx+r10*1+0x11],dil
 19a:	75 e4                	jne    0x180
 19c:	42 38 44 11 10       	cmp    BYTE PTR [rcx+r10*1+0x10],al
 1a1:	75 dd                	jne    0x180
 1a3:	42 0f b6 5c 11 12    	movzx  ebx,BYTE PTR [rcx+r10*1+0x12]
 1a9:	38 59 72             	cmp    BYTE PTR [rcx+0x72],bl
 1ac:	75 d2                	jne    0x180
 1ae:	4d 29 c8             	sub    r8,r9
 1b1:	49 83 fa 60          	cmp    r10,0x60
 1b5:	0f 85 d5 00 00 00    	jne    0x290
 1bb:	b0 4f                	mov    al,0x4f
 1bd:	b2 82                	mov    dl,0x82
 1bf:	40 b6 33             	mov    sil,0x33
 1c2:	40 b7 8b             	mov    dil,0x8b
 1c5:	41 b0 ae             	mov    r8b,0xae
 1c8:	41 b2 d8             	mov    r10b,0xd8
 1cb:	41 b1 91             	mov    r9b,0x91
 1ce:	41 b3 16             	mov    r11b,0x16
 1d1:	88 41 07             	mov    BYTE PTR [rcx+0x7],al
 1d4:	88 51 06             	mov    BYTE PTR [rcx+0x6],dl
 1d7:	40 88 71 05          	mov    BYTE PTR [rcx+0x5],sil
 1db:	40 88 79 04          	mov    BYTE PTR [rcx+0x4],dil
 1df:	44 88 41 03          	mov    BYTE PTR [rcx+0x3],r8b
 1e3:	44 88 51 02          	mov    BYTE PTR [rcx+0x2],r10b
 1e7:	44 88 19             	mov    BYTE PTR [rcx],r11b
 1ea:	44 88 49 01          	mov    BYTE PTR [rcx+0x1],r9b
 1ee:	b8 02 00 00 00       	mov    eax,0x2
 1f3:	e9 2f ff ff ff       	jmp    0x127
 1f8:	84 db                	test   bl,bl
 1fa:	74 b2                	je     0x1ae
 1fc:	49 ff c2             	inc    r10
 1ff:	4d 01 d9             	add    r9,r11
 202:	49 83 fa 59          	cmp    r10,0x59
 206:	74 b3                	je     0x1bb
 208:	4b 8d 1c 10          	lea    rbx,[r8+r10*1]
 20c:	48 39 d3             	cmp    rbx,rdx
 20f:	77 eb                	ja     0x1fc
 211:	42 0f b6 6c 11 10    	movzx  ebp,BYTE PTR [rcx+r10*1+0x10]
 217:	40 30 c5             	xor    bpl,al
 21a:	46 0f b6 74 11 11    	movzx  r14d,BYTE PTR [rcx+r10*1+0x11]
 220:	41 30 fe             	xor    r14b,dil
 223:	44 0f b6 79 72       	movzx  r15d,BYTE PTR [rcx+0x72]
 228:	0f b6 59 73          	movzx  ebx,BYTE PTR [rcx+0x73]
 22c:	46 32 7c 11 12       	xor    r15b,BYTE PTR [rcx+r10*1+0x12]
 231:	41 08 ee             	or     r14b,bpl
 234:	42 32 5c 11 13       	xor    bl,BYTE PTR [rcx+r10*1+0x13]
 239:	44 08 fb             	or     bl,r15b
 23c:	44 08 f3             	or     bl,r14b
 23f:	48 83 fe 05          	cmp    rsi,0x5
 243:	72 b3                	jb     0x1f8
 245:	0f b6 69 74          	movzx  ebp,BYTE PTR [rcx+0x74]
 249:	42 32 6c 11 14       	xor    bpl,BYTE PTR [rcx+r10*1+0x14]
 24e:	40 08 eb             	or     bl,bpl
 251:	48 83 fe 05          	cmp    rsi,0x5
 255:	74 a1                	je     0x1f8
 257:	0f b6 69 75          	movzx  ebp,BYTE PTR [rcx+0x75]
 25b:	42 32 6c 11 15       	xor    bpl,BYTE PTR [rcx+r10*1+0x15]
 260:	40 08 eb             	or     bl,bpl
 263:	48 83 fe 07          	cmp    rsi,0x7
 267:	72 8f                	jb     0x1f8
 269:	0f b6 69 76          	movzx  ebp,BYTE PTR [rcx+0x76]
 26d:	42 32 6c 11 16       	xor    bpl,BYTE PTR [rcx+r10*1+0x16]
 272:	40 08 eb             	or     bl,bpl
 275:	48 83 fe 07          	cmp    rsi,0x7
 279:	0f 84 79 ff ff ff    	je     0x1f8
 27f:	0f b6 69 77          	movzx  ebp,BYTE PTR [rcx+0x77]
 283:	42 32 6c 11 17       	xor    bpl,BYTE PTR [rcx+r10*1+0x17]
 288:	40 08 eb             	or     bl,bpl
 28b:	e9 68 ff ff ff       	jmp    0x1f8
 290:	48 c1 e6 20          	shl    rsi,0x20
 294:	49 01 f2             	add    r10,rsi
 297:	c4 43 fb f0 da 3d    	rorx   r11,r10,0x3d
 29d:	4d 31 c3             	xor    r11,r8
 2a0:	45 89 d9             	mov    r9d,r11d
 2a3:	41 c1 e9 08          	shr    r9d,0x8
 2a7:	45 89 da             	mov    r10d,r11d
 2aa:	41 c1 ea 10          	shr    r10d,0x10
 2ae:	45 89 d8             	mov    r8d,r11d
 2b1:	41 c1 e8 18          	shr    r8d,0x18
 2b5:	4c 89 df             	mov    rdi,r11
 2b8:	48 c1 ef 20          	shr    rdi,0x20
 2bc:	4c 89 de             	mov    rsi,r11
 2bf:	48 c1 ee 28          	shr    rsi,0x28
 2c3:	4c 89 da             	mov    rdx,r11
 2c6:	48 c1 ea 30          	shr    rdx,0x30
 2ca:	4c 89 d8             	mov    rax,r11
 2cd:	48 c1 e8 38          	shr    rax,0x38
 2d1:	e9 fb fe ff ff       	jmp    0x1d1
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 31
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x113e: je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1140: cmp    BYTE PTR [rcx+0x71],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x71],0x0]
 * - 0x1146: cmp    BYTE PTR [rcx+0x72],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x72],0x0]
 * - 0x114c: cmp    BYTE PTR [rcx+0x73],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x73],0x0]
 * - 0x1152: cmp    BYTE PTR [rcx+0x74],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x74],0x0]
 * - 0x1158: cmp    BYTE PTR [rcx+0x75],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x75],0x0]
 * - 0x115e: cmp    BYTE PTR [rcx+0x76],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x76],0x0]
 * - 0x1164: cmp    BYTE PTR [rcx+0x77],0x1 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x77],0x1]
 * - 0x116e: sbb    r8d,0x0 [warning-unmapped: sbb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x11b9: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11c9: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11cc: lea    r10d,[rsi+0x3] [warning-reg-remap: LEA via x86 kop selector; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11da: add    rdi,r10 [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11f0: test   r11b,r11b [warning-reg-remap: testb reg,reg kop; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x11fc: add    rdi,r10 [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1209: lea    r11,[rsi+r8*1] [warning-reg-remap: LEA via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] [warning-reg-remap: indexed memory load via x86 SIB kop; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x1221: xor    r11b,dl [warning-reg-remap: xorb reg kop; verifier instantiate uses temp BPF_REG_6; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x1232: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x1243: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x1254: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x1265: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x1276: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x128b: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x12a0: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8]
 * - 0x12c7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rcx,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [bpf-branch: lowered cmp    rcx,rdx + ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_3, 152),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1119: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [bpf-branch: lowered cmp    rsi,rdx + ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 147),
    /* 0x111f: lea    rsi,[rcx+0x78] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 120), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1126: ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> [bpf-branch: lowered cmp    rsi,rdx + ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 142),
    /* 0x112c: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112d: mov    edi,DWORD PTR [rcx+0x8] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x1130: movzx  edx,BYTE PTR [rcx+0x70] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 112), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1134: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1136: mov    r8d,0x0 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x113c: test   dl,dl [exact-kop: testb reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x113e: je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1140: cmp    BYTE PTR [rcx+0x71],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x71],0x0] */
    /* 0x1144: je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x71],0x0 + je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 113),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 12, 0),
    /* 0x1146: cmp    BYTE PTR [rcx+0x72],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x72],0x0] */
    /* 0x114a: je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x72],0x0 + je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 114),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 12, 0),
    /* 0x114c: cmp    BYTE PTR [rcx+0x73],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x73],0x0] */
    /* 0x1150: je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x73],0x0 + je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 115),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 12, 0),
    /* 0x1152: cmp    BYTE PTR [rcx+0x74],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x74],0x0] */
    /* 0x1156: je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x74],0x0 + je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 116),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 12, 0),
    /* 0x1158: cmp    BYTE PTR [rcx+0x75],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x75],0x0] */
    /* 0x115c: je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x75],0x0 + je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 117),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 12, 0),
    /* 0x115e: cmp    BYTE PTR [rcx+0x76],0x0 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x76],0x0] */
    /* 0x1162: je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c> [bpf-branch: lowered cmp    BYTE PTR [rcx+0x76],0x0 + je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c> to verifier-visible load+branch] */
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_4, 118),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 12, 0),
    /* 0x1164: cmp    BYTE PTR [rcx+0x77],0x1 [warning-unmapped: CMP operand form has no current kop selector: cmp    BYTE PTR [rcx+0x77],0x1] */
    /* 0x1168: mov    r8d,0x8 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 8),
    /* 0x116e: sbb    r8d,0x0 [warning-unmapped: sbb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1172: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 11, 0),
    /* 0x1174: mov    r8d,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 1),
    /* 0x117a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 9, 0),
    /* 0x117c: mov    r8d,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 2),
    /* 0x1182: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 7, 0),
    /* 0x1184: mov    r8d,0x3 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 3),
    /* 0x118a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x118c: mov    r8d,0x4 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 4),
    /* 0x1192: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 3, 0),
    /* 0x1194: mov    r8d,0x5 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 5),
    /* 0x119a: jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 1, 0),
    /* 0x119c: mov    r8d,0x6 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 6),
    /* 0x11a2: cmp    edi,0x60 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_1, 96), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a5: ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [bpf-branch: lowered cmp    edi,0x60 + ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_1, 0, 106, 96),
    /* 0x11ab: mov    esi,DWORD PTR [rcx+0xc] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 12), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11ae: cmp    esi,r8d [exact-kop: cmpl reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_CMPL_RR),
    /* 0x11b1: jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [bpf-branch: lowered cmp    esi,r8d + jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JNE, BPF_REG_2, BPF_REG_5, 101),
    /* 0x11b7: test   dl,dl [exact-kop: testb reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x11b9: je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11bf: movabs rax,0x4f82338baed89116 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x4f82338baed89116ULL),
    /* 0x11c9: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x11cc: lea    r10d,[rsi+0x3] [warning-reg-remap: LEA via x86 kop selector; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_2, 0, 0, 1, 0, 3), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11d0: movabs rdi,0xd1b54a32d192ed03 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_1, 0, 0xd1b54a32d192ed03ULL),
    /* 0x11da: add    rdi,r10 [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_7, 0, 0),
    /* 0x11dd: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x11e0: jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 8, 0),
    /* 0x11e2: data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11f0: test   r11b,r11b [warning-reg-remap: testb reg,reg kop; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x11f3: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x11f9: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11fc: add    rdi,r10 [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_7, 0, 0),
    /* 0x11ff: cmp    r8,0x59 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_5, 89), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1203: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [bpf-branch: lowered cmp    r8,0x59 + je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 78, 89),
    /* 0x1209: lea    r11,[rsi+r8*1] [warning-reg-remap: LEA via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_2, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x120d: cmp    r11,r9 [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1210: ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> [bpf-branch: lowered cmp    r11,r9 + ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_8, BPF_REG_9, -11),
    /* 0x1212: test   rsi,rsi [exact-kop: testq reg,reg kop] */
    HC_KOP(HC_TEST_PAYLOAD(BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_TESTQ_RR),
    /* 0x1215: je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x121b: movzx  r11d,BYTE PTR [rcx+r8*1+0x10] [warning-reg-remap: indexed memory load via x86 SIB kop; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_KOP(HC_SIB_PAYLOAD(BPF_REG_8, BPF_REG_4, BPF_REG_5, 0, 16), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x1221: xor    r11b,dl [warning-reg-remap: xorb reg kop; verifier instantiate uses temp BPF_REG_6; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_KOP(HC_REG_REG_TMP_PAYLOAD(BPF_REG_8, BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORB_RR),
    /* 0x1224: cmp    esi,0x2 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1227: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x2 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -22, 2),
    /* 0x1229: movzx  ebx,BYTE PTR [rcx+0x71] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 113), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x122d: xor    bl,BYTE PTR [rcx+r8*1+0x11] [exact-kop: xorb SIB memory-source kop; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KOP(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 17, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1232: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x1235: cmp    esi,0x3 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_2, 3), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1238: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x3 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -30, 3),
    /* 0x123a: movzx  ebx,BYTE PTR [rcx+0x72] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 114), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x123e: xor    bl,BYTE PTR [rcx+r8*1+0x12] [exact-kop: xorb SIB memory-source kop; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KOP(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 18, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1243: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x1246: cmp    esi,0x4 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_2, 4), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1249: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x4 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -38, 4),
    /* 0x124b: movzx  ebx,BYTE PTR [rcx+0x73] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 115), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x124f: xor    bl,BYTE PTR [rcx+r8*1+0x13] [exact-kop: xorb SIB memory-source kop; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KOP(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 19, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1254: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x1257: cmp    esi,0x5 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_2, 5), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x125a: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x5 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -46, 5),
    /* 0x125c: movzx  ebx,BYTE PTR [rcx+0x74] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 116), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1260: xor    bl,BYTE PTR [rcx+r8*1+0x14] [exact-kop: xorb SIB memory-source kop; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KOP(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 20, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1265: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x1268: cmp    esi,0x6 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_2, 6), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x126b: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x6 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -54, 6),
    /* 0x126d: movzx  ebx,BYTE PTR [rcx+0x75] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 117), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1271: xor    bl,BYTE PTR [rcx+r8*1+0x15] [exact-kop: xorb SIB memory-source kop; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KOP(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 21, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x1276: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x1279: cmp    esi,0x7 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_2, 7), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x127c: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x7 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -62, 7),
    /* 0x1282: movzx  ebx,BYTE PTR [rcx+0x76] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 118), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1286: xor    bl,BYTE PTR [rcx+r8*1+0x16] [exact-kop: xorb SIB memory-source kop; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KOP(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 22, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x128b: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x128e: cmp    esi,0x8 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1291: jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered cmp    esi,0x8 + jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_2, 0, -70, 8),
    /* 0x1297: movzx  ebx,BYTE PTR [rcx+0x77] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 119), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x129b: xor    bl,BYTE PTR [rcx+r8*1+0x17] [exact-kop: xorb SIB memory-source kop; verifier instantiate uses temps BPF_REG_7/BPF_REG_8] */
    HC_KOP(HC_ALU_SIB_PAYLOAD(BPF_REG_6, BPF_REG_4, BPF_REG_5, 0, 23, BPF_REG_7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORB_SIB),
    /* 0x12a0: or     r11b,bl [warning-reg-remap: ALU reg operation; native r11 has no exact BPF JIT register; remapped to BPF_REG_8] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x12a3: jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -76, 0),
    /* 0x12a8: cmp    r8,0x60 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_5, 96), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x12ac: je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> [bpf-branch: lowered cmp    r8,0x60 + je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 7, 96),
    /* 0x12ae: shl    rsi,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 32),
    /* 0x12b2: add    rsi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_5, 0, 0),
    /* 0x12b5: rol    rsi,0x3 [exact-kop: rolq imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_2, BPF_REG_2, 3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    /* 0x12b9: xor    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x12bc: mov    rax,rdi [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x12bf: mov    QWORD PTR [rcx],rax [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x12c2: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x12c7: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x12c8: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
