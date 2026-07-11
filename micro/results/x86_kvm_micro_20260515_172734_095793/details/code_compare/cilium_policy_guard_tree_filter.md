# cilium_policy_guard_tree_filter

## Original C
```c
#include "common.h"

#define DEEP_GUARD_TREE_8_RECORDS 32U
#define DEEP_GUARD_TREE_8_RECORD_SIZE 16U
#define DEEP_GUARD_TREE_8_INPUT_SIZE \
    (4U + DEEP_GUARD_TREE_8_RECORDS * DEEP_GUARD_TREE_8_RECORD_SIZE)

static __always_inline int bench_cilium_policy_guard_tree_filter(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    if (record_count != DEEP_GUARD_TREE_8_RECORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 4U, DEEP_GUARD_TREE_8_RECORDS * DEEP_GUARD_TREE_8_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0xE7037ED1A0B428DBULL;
    for (u32 index = 0; index < DEEP_GUARD_TREE_8_RECORDS; index++) {
        u32 base = 4U + index * DEEP_GUARD_TREE_8_RECORD_SIZE;
        u8 f0 = data[base + 0U];
        u8 f1 = data[base + 1U];
        u8 f2 = data[base + 2U];
        u8 f3 = data[base + 3U];
        u8 f4 = data[base + 4U];
        u8 f5 = data[base + 5U];
        u8 f6 = data[base + 6U];
        u8 f7 = data[base + 7U];
        u64 payload = micro_read_u64_le(data, base + 8U);

        if (f0 > 0x20U) {
            if ((f1 & 1U) != 0U) {
                if (f2 < 0x80U) {
                    if ((u8)(f3 ^ index) > 0x10U) {
                        if ((u8)(f4 + f0) < 0xC0U) {
                            if ((f5 & 0x18U) == 0x10U) {
                                if (f6 != 0xAAU) {
                                    if ((f7 & 3U) == 1U) {
                                        acc += payload ^ ((u64)f7 << 48U);
                                    } else {
                                        acc ^= payload + ((u64)f6 << 40U);
                                    }
                                } else {
                                    acc += micro_rotl64(payload ^ f5, 7U);
                                }
                            } else {
                                acc ^= payload + ((u64)f5 << 32U);
                            }
                        } else {
                            acc += payload ^ ((u64)f4 << 24U);
                        }
                    } else {
                        acc ^= payload + ((u64)f3 << 16U);
                    }
                } else {
                    acc += payload ^ ((u64)f2 << 8U);
                }
            } else {
                acc ^= payload + f1;
            }
        } else {
            acc += payload ^ f0;
        }

        acc = micro_rotl64(acc, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cilium_policy_guard_tree_filter_xdp,
    bench_cilium_policy_guard_tree_filter,
    cilium_policy_guard_tree_filter_input_value,
    DEEP_GUARD_TREE_8_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <cilium_policy_guard_tree_filter_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <cilium_policy_guard_tree_filter_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <cilium_policy_guard_tree_filter_xdp+0xe>
    1118:	48 8d ba 0c 02 00 00 	lea    rdi,[rdx+0x20c]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <cilium_policy_guard_tree_filter_xdp+0xe>
    1124:	83 3e 20             	cmp    DWORD PTR [rsi],0x20
    1127:	75 e5                	jne    110e <cilium_policy_guard_tree_filter_xdp+0xe>
    1129:	53                   	push   rbx
    112a:	48 8d 7a 1b          	lea    rdi,[rdx+0x1b]
    112e:	48 be db 28 b4 a0 d1 	movabs rsi,0xe7037ed1a0b428db
    1135:	7e 03 e7 
    1138:	45 31 c0             	xor    r8d,r8d
    113b:	eb 42                	jmp    117f <cilium_policy_guard_tree_filter_xdp+0x7f>
    113d:	48 c1 e1 30          	shl    rcx,0x30
    1141:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1148:	0f 1f 84 00 00 00 00 
    114f:	00 
    1150:	48 31 c8             	xor    rax,rcx
    1153:	48 01 c6             	add    rsi,rax
    1156:	44 89 c0             	mov    eax,r8d
    1159:	24 07                	and    al,0x7
    115b:	8d 48 01             	lea    ecx,[rax+0x1]
    115e:	48 89 f3             	mov    rbx,rsi
    1161:	48 d3 e3             	shl    rbx,cl
    1164:	f6 d0                	not    al
    1166:	89 c1                	mov    ecx,eax
    1168:	48 d3 ee             	shr    rsi,cl
    116b:	48 09 de             	or     rsi,rbx
    116e:	49 ff c0             	inc    r8
    1171:	48 83 c7 10          	add    rdi,0x10
    1175:	49 83 f8 20          	cmp    r8,0x20
    1179:	0f 84 b5 00 00 00    	je     1234 <cilium_policy_guard_tree_filter_xdp+0x134>
    117f:	0f b6 4f f1          	movzx  ecx,BYTE PTR [rdi-0xf]
    1183:	48 8b 47 f9          	mov    rax,QWORD PTR [rdi-0x7]
    1187:	48 83 f9 21          	cmp    rcx,0x21
    118b:	72 c3                	jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50>
    118d:	44 0f b6 4f f2       	movzx  r9d,BYTE PTR [rdi-0xe]
    1192:	41 f6 c1 01          	test   r9b,0x1
    1196:	74 61                	je     11f9 <cilium_policy_guard_tree_filter_xdp+0xf9>
    1198:	44 0f b6 4f f3       	movzx  r9d,BYTE PTR [rdi-0xd]
    119d:	45 84 c9             	test   r9b,r9b
    11a0:	78 4d                	js     11ef <cilium_policy_guard_tree_filter_xdp+0xef>
    11a2:	44 0f b6 4f f4       	movzx  r9d,BYTE PTR [rdi-0xc]
    11a7:	45 89 ca             	mov    r10d,r9d
    11aa:	45 31 c2             	xor    r10d,r8d
    11ad:	41 80 fa 11          	cmp    r10b,0x11
    11b1:	72 42                	jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5>
    11b3:	44 0f b6 4f f5       	movzx  r9d,BYTE PTR [rdi-0xb]
    11b8:	44 00 c9             	add    cl,r9b
    11bb:	80 f9 bf             	cmp    cl,0xbf
    11be:	77 44                	ja     1204 <cilium_policy_guard_tree_filter_xdp+0x104>
    11c0:	0f b6 4f f6          	movzx  ecx,BYTE PTR [rdi-0xa]
    11c4:	41 89 c9             	mov    r9d,ecx
    11c7:	41 80 e1 18          	and    r9b,0x18
    11cb:	41 80 f9 10          	cmp    r9b,0x10
    11cf:	75 3f                	jne    1210 <cilium_policy_guard_tree_filter_xdp+0x110>
    11d1:	44 0f b6 4f f7       	movzx  r9d,BYTE PTR [rdi-0x9]
    11d6:	41 81 f9 aa 00 00 00 	cmp    r9d,0xaa
    11dd:	75 3a                	jne    1219 <cilium_policy_guard_tree_filter_xdp+0x119>
    11df:	48 31 c1             	xor    rcx,rax
    11e2:	48 0f a4 c1 07       	shld   rcx,rax,0x7
    11e7:	48 01 ce             	add    rsi,rcx
    11ea:	e9 67 ff ff ff       	jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56>
    11ef:	41 c1 e1 08          	shl    r9d,0x8
    11f3:	eb 13                	jmp    1208 <cilium_policy_guard_tree_filter_xdp+0x108>
    11f5:	41 c1 e1 10          	shl    r9d,0x10
    11f9:	4c 01 c8             	add    rax,r9
    11fc:	48 31 c6             	xor    rsi,rax
    11ff:	e9 52 ff ff ff       	jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56>
    1204:	41 c1 e1 18          	shl    r9d,0x18
    1208:	4c 31 c8             	xor    rax,r9
    120b:	e9 43 ff ff ff       	jmp    1153 <cilium_policy_guard_tree_filter_xdp+0x53>
    1210:	48 c1 e1 20          	shl    rcx,0x20
    1214:	48 01 c8             	add    rax,rcx
    1217:	eb e3                	jmp    11fc <cilium_policy_guard_tree_filter_xdp+0xfc>
    1219:	0f b6 4f f8          	movzx  ecx,BYTE PTR [rdi-0x8]
    121d:	41 89 ca             	mov    r10d,ecx
    1220:	41 80 e2 03          	and    r10b,0x3
    1224:	41 80 fa 01          	cmp    r10b,0x1
    1228:	0f 84 0f ff ff ff    	je     113d <cilium_policy_guard_tree_filter_xdp+0x3d>
    122e:	49 c1 e1 28          	shl    r9,0x28
    1232:	eb c5                	jmp    11f9 <cilium_policy_guard_tree_filter_xdp+0xf9>
    1234:	40 88 32             	mov    BYTE PTR [rdx],sil
    1237:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
    123a:	89 d8                	mov    eax,ebx
    123c:	c1 e8 10             	shr    eax,0x10
    123f:	88 42 02             	mov    BYTE PTR [rdx+0x2],al
    1242:	89 d8                	mov    eax,ebx
    1244:	c1 e8 18             	shr    eax,0x18
    1247:	88 42 03             	mov    BYTE PTR [rdx+0x3],al
    124a:	48 89 d8             	mov    rax,rbx
    124d:	48 c1 e8 20          	shr    rax,0x20
    1251:	88 42 04             	mov    BYTE PTR [rdx+0x4],al
    1254:	48 89 d8             	mov    rax,rbx
    1257:	48 c1 e8 28          	shr    rax,0x28
    125b:	88 42 05             	mov    BYTE PTR [rdx+0x5],al
    125e:	48 89 d8             	mov    rax,rbx
    1261:	48 c1 e8 30          	shr    rax,0x30
    1265:	88 42 06             	mov    BYTE PTR [rdx+0x6],al
    1268:	48 c1 eb 38          	shr    rbx,0x38
    126c:	88 5a 07             	mov    BYTE PTR [rdx+0x7],bl
    126f:	b8 02 00 00 00       	mov    eax,0x2
    1274:	5b                   	pop    rbx
    1275:	c3                   	ret

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
   c:	53                   	push   rbx
   d:	41 55                	push   r13
   f:	41 56                	push   r14
  11:	41 57                	push   r15
  13:	31 c0                	xor    eax,eax
  15:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  19:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  1d:	48 39 f7             	cmp    rdi,rsi
  20:	0f 87 64 02 00 00    	ja     0x28a
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 54 02 00 00    	ja     0x28a
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 0c 02 00 00 	add    rdx,0x20c
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 41 02 00 00    	ja     0x28a
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
  7a:	48 83 fe 20          	cmp    rsi,0x20
  7e:	0f 85 06 02 00 00    	jne    0x28a
  84:	49 bd db 28 b4 a0 d1 	movabs r13,0xe7037ed1a0b428db
  8b:	7e 03 e7 
  8e:	48 89 fa             	mov    rdx,rdi
  91:	48 83 c2 0d          	add    rdx,0xd
  95:	b9 21 00 00 00       	mov    ecx,0x21
  9a:	48 0f b6 5a 08       	movzx  rbx,BYTE PTR [rdx+0x8]
  9f:	48 c1 e3 08          	shl    rbx,0x8
  a3:	4c 0f b6 72 07       	movzx  r14,BYTE PTR [rdx+0x7]
  a8:	4c 09 f3             	or     rbx,r14
  ab:	4c 0f b6 72 09       	movzx  r14,BYTE PTR [rdx+0x9]
  b0:	49 c1 e6 10          	shl    r14,0x10
  b4:	49 09 de             	or     r14,rbx
  b7:	48 0f b6 5a 0a       	movzx  rbx,BYTE PTR [rdx+0xa]
  bc:	48 c1 e3 18          	shl    rbx,0x18
  c0:	4c 09 f3             	or     rbx,r14
  c3:	4c 0f b6 72 0b       	movzx  r14,BYTE PTR [rdx+0xb]
  c8:	49 c1 e6 20          	shl    r14,0x20
  cc:	49 09 de             	or     r14,rbx
  cf:	48 0f b6 5a 0c       	movzx  rbx,BYTE PTR [rdx+0xc]
  d4:	48 c1 e3 28          	shl    rbx,0x28
  d8:	4c 09 f3             	or     rbx,r14
  db:	4c 0f b6 72 0d       	movzx  r14,BYTE PTR [rdx+0xd]
  e0:	49 c1 e6 30          	shl    r14,0x30
  e4:	49 09 de             	or     r14,rbx
  e7:	48 0f b6 5a 0e       	movzx  rbx,BYTE PTR [rdx+0xe]
  ec:	48 c1 e3 38          	shl    rbx,0x38
  f0:	4c 09 f3             	or     rbx,r14
  f3:	4c 0f b6 72 ff       	movzx  r14,BYTE PTR [rdx-0x1]
  f8:	4c 39 f1             	cmp    rcx,r14
  fb:	0f 87 b1 00 00 00    	ja     0x1b2
 101:	4c 0f b6 42 00       	movzx  r8,BYTE PTR [rdx+0x0]
 106:	4d 89 c7             	mov    r15,r8
 109:	49 83 e7 01          	and    r15,0x1
 10d:	4d 85 ff             	test   r15,r15
 110:	0f 84 da 00 00 00    	je     0x1f0
 116:	4c 0f b6 7a 01       	movzx  r15,BYTE PTR [rdx+0x1]
 11b:	4d 89 f8             	mov    r8,r15
 11e:	49 c1 e0 38          	shl    r8,0x38
 122:	49 c1 f8 38          	sar    r8,0x38
 126:	31 f6                	xor    esi,esi
 128:	4c 39 c6             	cmp    rsi,r8
 12b:	0f 8f c4 00 00 00    	jg     0x1f5
 131:	4c 0f b6 7a 02       	movzx  r15,BYTE PTR [rdx+0x2]
 136:	4d 89 f8             	mov    r8,r15
 139:	49 31 c0             	xor    r8,rax
 13c:	49 81 e0 ff 00 00 00 	and    r8,0xff
 143:	be 11 00 00 00       	mov    esi,0x11
 148:	4c 39 c6             	cmp    rsi,r8
 14b:	0f 87 aa 00 00 00    	ja     0x1fb
 151:	4c 0f b6 7a 03       	movzx  r15,BYTE PTR [rdx+0x3]
 156:	4d 89 f8             	mov    r8,r15
 159:	4d 01 f0             	add    r8,r14
 15c:	49 81 e0 ff 00 00 00 	and    r8,0xff
 163:	49 81 f8 bf 00 00 00 	cmp    r8,0xbf
 16a:	0f 87 97 00 00 00    	ja     0x207
 170:	4c 0f b6 72 04       	movzx  r14,BYTE PTR [rdx+0x4]
 175:	4d 89 f0             	mov    r8,r14
 178:	49 83 e0 18          	and    r8,0x18
 17c:	49 83 f8 10          	cmp    r8,0x10
 180:	0f 85 8a 00 00 00    	jne    0x210
 186:	4c 0f b6 7a 05       	movzx  r15,BYTE PTR [rdx+0x5]
 18b:	49 81 ff aa 00 00 00 	cmp    r15,0xaa
 192:	0f 84 81 00 00 00    	je     0x219
 198:	4c 0f b6 72 06       	movzx  r14,BYTE PTR [rdx+0x6]
 19d:	4d 89 f0             	mov    r8,r14
 1a0:	49 83 e0 03          	and    r8,0x3
 1a4:	49 83 f8 01          	cmp    r8,0x1
 1a8:	0f 85 84 00 00 00    	jne    0x232
 1ae:	49 c1 e6 30          	shl    r14,0x30
 1b2:	4c 31 f3             	xor    rbx,r14
 1b5:	4c 01 eb             	add    rbx,r13
 1b8:	49 89 c0             	mov    r8,rax
 1bb:	49 83 e0 07          	and    r8,0x7
 1bf:	4d 89 c5             	mov    r13,r8
 1c2:	49 83 f5 3f          	xor    r13,0x3f
 1c6:	49 89 de             	mov    r14,rbx
 1c9:	c4 42 93 f7 f6       	shrx   r14,r14,r13
 1ce:	49 83 c0 01          	add    r8,0x1
 1d2:	c4 e2 b9 f7 db       	shlx   rbx,rbx,r8
 1d7:	48 83 c2 10          	add    rdx,0x10
 1db:	49 89 dd             	mov    r13,rbx
 1de:	4d 09 f5             	or     r13,r14
 1e1:	48 83 c0 01          	add    rax,0x1
 1e5:	48 83 f8 20          	cmp    rax,0x20
 1e9:	74 4d                	je     0x238
 1eb:	e9 aa fe ff ff       	jmp    0x9a
 1f0:	4c 01 c3             	add    rbx,r8
 1f3:	eb 0d                	jmp    0x202
 1f5:	49 c1 e7 08          	shl    r15,0x8
 1f9:	eb 10                	jmp    0x20b
 1fb:	49 c1 e7 10          	shl    r15,0x10
 1ff:	4c 01 fb             	add    rbx,r15
 202:	4c 31 eb             	xor    rbx,r13
 205:	eb b1                	jmp    0x1b8
 207:	49 c1 e7 18          	shl    r15,0x18
 20b:	4c 31 fb             	xor    rbx,r15
 20e:	eb a5                	jmp    0x1b5
 210:	49 c1 e6 20          	shl    r14,0x20
 214:	4c 01 f3             	add    rbx,r14
 217:	eb e9                	jmp    0x202
 219:	49 89 d8             	mov    r8,rbx
 21c:	4d 31 f0             	xor    r8,r14
 21f:	49 c1 e0 07          	shl    r8,0x7
 223:	48 c1 eb 39          	shr    rbx,0x39
 227:	49 09 d8             	or     r8,rbx
 22a:	4d 01 e8             	add    r8,r13
 22d:	4c 89 c3             	mov    rbx,r8
 230:	eb 86                	jmp    0x1b8
 232:	49 c1 e7 28          	shl    r15,0x28
 236:	eb c7                	jmp    0x1ff
 238:	44 88 6f 00          	mov    BYTE PTR [rdi+0x0],r13b
 23c:	48 89 de             	mov    rsi,rbx
 23f:	48 c1 ee 38          	shr    rsi,0x38
 243:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 247:	48 89 de             	mov    rsi,rbx
 24a:	48 c1 ee 30          	shr    rsi,0x30
 24e:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 252:	48 89 de             	mov    rsi,rbx
 255:	48 c1 ee 28          	shr    rsi,0x28
 259:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 25d:	48 89 de             	mov    rsi,rbx
 260:	48 c1 ee 20          	shr    rsi,0x20
 264:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 268:	48 89 de             	mov    rsi,rbx
 26b:	48 c1 ee 18          	shr    rsi,0x18
 26f:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 273:	48 89 de             	mov    rsi,rbx
 276:	48 c1 ee 10          	shr    rsi,0x10
 27a:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 27e:	48 c1 eb 08          	shr    rbx,0x8
 282:	88 5f 01             	mov    BYTE PTR [rdi+0x1],bl
 285:	b8 02 00 00 00       	mov    eax,0x2
 28a:	41 5f                	pop    r15
 28c:	41 5e                	pop    r14
 28e:	41 5d                	pop    r13
 290:	5b                   	pop    rbx
 291:	c9                   	leave
 292:	c3                   	ret
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
   d:	0f 87 77 01 00 00    	ja     0x18a
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 6a 01 00 00    	ja     0x18a
  20:	48 8d b1 0c 02 00 00 	lea    rsi,[rcx+0x20c]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 5a 01 00 00    	ja     0x18a
  30:	83 79 08 20          	cmp    DWORD PTR [rcx+0x8],0x20
  34:	0f 85 09 01 00 00    	jne    0x143
  3a:	53                   	push   rbx
  3b:	48 8d 41 0d          	lea    rax,[rcx+0xd]
  3f:	48 be db 28 b4 a0 d1 	movabs rsi,0xe7037ed1a0b428db
  46:	7e 03 e7 
  49:	31 d2                	xor    edx,edx
  4b:	eb 39                	jmp    0x86
  4d:	41 c1 e1 08          	shl    r9d,0x8
  51:	4d 89 c8             	mov    r8,r9
  54:	49 31 f8             	xor    r8,rdi
  57:	49 01 f0             	add    r8,rsi
  5a:	89 d7                	mov    edi,edx
  5c:	40 80 e7 07          	and    dil,0x7
  60:	89 fe                	mov    esi,edi
  62:	40 f6 d6             	not    sil
  65:	c4 c2 cb f7 f0       	shrx   rsi,r8,rsi
  6a:	40 fe c7             	inc    dil
  6d:	c4 c2 c1 f7 d8       	shlx   rbx,r8,rdi
  72:	48 83 c0 10          	add    rax,0x10
  76:	48 09 de             	or     rsi,rbx
  79:	48 ff c2             	inc    rdx
  7c:	48 83 fa 20          	cmp    rdx,0x20
  80:	0f 84 c0 00 00 00    	je     0x146
  86:	48 8b 78 07          	mov    rdi,QWORD PTR [rax+0x7]
  8a:	44 0f b6 40 ff       	movzx  r8d,BYTE PTR [rax-0x1]
  8f:	49 83 f8 21          	cmp    r8,0x21
  93:	72 bf                	jb     0x54
  95:	44 0f b6 08          	movzx  r9d,BYTE PTR [rax]
  99:	41 f6 c1 01          	test   r9b,0x1
  9d:	74 1f                	je     0xbe
  9f:	44 0f b6 48 01       	movzx  r9d,BYTE PTR [rax+0x1]
  a4:	45 84 c9             	test   r9b,r9b
  a7:	78 a4                	js     0x4d
  a9:	44 0f b6 48 02       	movzx  r9d,BYTE PTR [rax+0x2]
  ae:	49 89 d2             	mov    r10,rdx
  b1:	4d 31 ca             	xor    r10,r9
  b4:	49 83 fa 11          	cmp    r10,0x11
  b8:	73 0f                	jae    0xc9
  ba:	41 c1 e1 10          	shl    r9d,0x10
  be:	49 01 f9             	add    r9,rdi
  c1:	49 31 f1             	xor    r9,rsi
  c4:	4d 89 c8             	mov    r8,r9
  c7:	eb 91                	jmp    0x5a
  c9:	44 0f b6 48 03       	movzx  r9d,BYTE PTR [rax+0x3]
  ce:	45 01 c8             	add    r8d,r9d
  d1:	41 f7 d0             	not    r8d
  d4:	41 f6 c0 c0          	test   r8b,0xc0
  d8:	75 09                	jne    0xe3
  da:	41 c1 e1 18          	shl    r9d,0x18
  de:	e9 6e ff ff ff       	jmp    0x51
  e3:	44 0f b6 48 04       	movzx  r9d,BYTE PTR [rax+0x4]
  e8:	45 89 c8             	mov    r8d,r9d
  eb:	41 83 e0 18          	and    r8d,0x18
  ef:	41 83 f8 10          	cmp    r8d,0x10
  f3:	75 21                	jne    0x116
  f5:	44 0f b6 50 05       	movzx  r10d,BYTE PTR [rax+0x5]
  fa:	49 81 fa aa 00 00 00 	cmp    r10,0xaa
 101:	75 19                	jne    0x11c
 103:	49 31 f9             	xor    r9,rdi
 106:	49 0f a4 f9 07       	shld   r9,rdi,0x7
 10b:	49 01 f1             	add    r9,rsi
 10e:	4d 89 c8             	mov    r8,r9
 111:	e9 44 ff ff ff       	jmp    0x5a
 116:	49 c1 e1 20          	shl    r9,0x20
 11a:	eb a2                	jmp    0xbe
 11c:	44 0f b6 40 06       	movzx  r8d,BYTE PTR [rax+0x6]
 121:	45 89 c1             	mov    r9d,r8d
 124:	41 83 e1 03          	and    r9d,0x3
 128:	41 83 f9 01          	cmp    r9d,0x1
 12c:	75 09                	jne    0x137
 12e:	49 c1 e0 30          	shl    r8,0x30
 132:	e9 1d ff ff ff       	jmp    0x54
 137:	49 c1 e2 28          	shl    r10,0x28
 13b:	4d 89 d1             	mov    r9,r10
 13e:	e9 7b ff ff ff       	jmp    0xbe
 143:	31 c0                	xor    eax,eax
 145:	c3                   	ret
 146:	40 88 31             	mov    BYTE PTR [rcx],sil
 149:	48 89 d8             	mov    rax,rbx
 14c:	48 c1 e8 38          	shr    rax,0x38
 150:	88 41 07             	mov    BYTE PTR [rcx+0x7],al
 153:	48 89 d8             	mov    rax,rbx
 156:	48 c1 e8 30          	shr    rax,0x30
 15a:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
 15d:	48 89 d8             	mov    rax,rbx
 160:	48 c1 e8 28          	shr    rax,0x28
 164:	88 41 05             	mov    BYTE PTR [rcx+0x5],al
 167:	48 89 d8             	mov    rax,rbx
 16a:	48 c1 e8 20          	shr    rax,0x20
 16e:	88 41 04             	mov    BYTE PTR [rcx+0x4],al
 171:	89 d8                	mov    eax,ebx
 173:	c1 e8 18             	shr    eax,0x18
 176:	88 41 03             	mov    BYTE PTR [rcx+0x3],al
 179:	89 d8                	mov    eax,ebx
 17b:	c1 e8 10             	shr    eax,0x10
 17e:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
 181:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
 184:	b8 02 00 00 00       	mov    eax,0x2
 189:	5b                   	pop    rbx
 18a:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 32
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rsi],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rsi],0x20]
 * - 0x1129: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x118d: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1192: test   r9b,0x1 [warning-reg-remap: testb imm kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1196: je     11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x1198: movzx  r9d,BYTE PTR [rdi-0xd] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x119d: test   r9b,r9b [warning-reg-remap: testb reg,reg kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11a0: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef> [warning-unmapped: unsupported mnemonic or operand form: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef>]
 * - 0x11a2: movzx  r9d,BYTE PTR [rdi-0xc] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11a7: mov    r10d,r9d [warning-reg-remap: 32-bit register move; native r10 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11aa: xor    r10d,r8d [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11ad: cmp    r10b,0x11 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10b,0x11]
 * - 0x11b3: movzx  r9d,BYTE PTR [rdi-0xb] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11b8: add    cl,r9b [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11bb: cmp    cl,0xbf [warning-unmapped: CMP operand form has no current kop selector: cmp    cl,0xbf]
 * - 0x11c4: mov    r9d,ecx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11c7: and    r9b,0x18 [warning-reg-remap: andb imm kop; verifier instantiate uses temp BPF_REG_8; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11cb: cmp    r9b,0x10 [warning-unmapped: CMP operand form has no current kop selector: cmp    r9b,0x10]
 * - 0x11d1: movzx  r9d,BYTE PTR [rdi-0x9] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ef: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f5: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f9: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1204: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1208: xor    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x121d: mov    r10d,ecx [warning-reg-remap: 32-bit register move; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1220: and    r10b,0x3 [warning-reg-remap: andb imm kop; verifier instantiate uses temp BPF_REG_8; native r10 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1224: cmp    r10b,0x1 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10b,0x1]
 * - 0x122e: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1237: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh]
 * - 0x1274: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <cilium_policy_guard_tree_filter_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <cilium_policy_guard_tree_filter_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rdi,[rdx+0x20c] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 524), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> [bpf-branch: lowered cmp    rdi,rcx + ja     110e <cilium_policy_guard_tree_filter_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rsi],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rsi],0x20] */
    /* 0x1127: jne    110e <cilium_policy_guard_tree_filter_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi],0x20 + jne    110e <cilium_policy_guard_tree_filter_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_8, BPF_REG_2, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_8, 0, -13, 32),
    /* 0x1129: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112a: lea    rdi,[rdx+0x1b] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 27), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112e: movabs rsi,0xe7037ed1a0b428db [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0xe7037ed1a0b428dbULL),
    /* 0x1138: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x113b: jmp    117f <cilium_policy_guard_tree_filter_xdp+0x7f> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 22, 0),
    /* 0x113d: shl    rcx,0x30 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 48),
    /* 0x1141: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: xor    rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x1153: add    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x1156: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1159: and    al,0x7 [exact-kop: andb imm kop; verifier instantiate uses temp BPF_REG_8] */
    HC_KOP(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_0, 7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x115b: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x115e: mov    rbx,rsi [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1161: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1164: not    al [exact-kop: notb reg kop; verifier instantiate uses temp BPF_REG_8] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1166: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1168: shr    rsi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x116b: or     rsi,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_X, BPF_REG_2, BPF_REG_6, 0, 0),
    /* 0x116e: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1171: add    rdi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1175: cmp    r8,0x20 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_5, 32), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1179: je     1234 <cilium_policy_guard_tree_filter_xdp+0x134> [bpf-branch: lowered cmp    r8,0x20 + je     1234 <cilium_policy_guard_tree_filter_xdp+0x134> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 60, 32),
    /* 0x117f: movzx  ecx,BYTE PTR [rdi-0xf] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1183: mov    rax,QWORD PTR [rdi-0x7] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM),
    /* 0x1187: cmp    rcx,0x21 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_4, 33), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x118b: jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50> [bpf-branch: lowered cmp    rcx,0x21 + jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_4, 0, -28, 33),
    /* 0x118d: movzx  r9d,BYTE PTR [rdi-0xe] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -14), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1192: test   r9b,0x1 [warning-reg-remap: testb imm kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_9, 1), MICRO_HANDCRAFT_BPF_X86_TESTB_IMM),
    /* 0x1196: je     11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1198: movzx  r9d,BYTE PTR [rdi-0xd] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -13), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x119d: test   r9b,r9b [warning-reg-remap: testb reg,reg kop; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_TESTB_RR),
    /* 0x11a0: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef> [warning-unmapped: unsupported mnemonic or operand form: js     11ef <cilium_policy_guard_tree_filter_xdp+0xef>] */
    /* 0x11a2: movzx  r9d,BYTE PTR [rdi-0xc] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -12), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11a7: mov    r10d,r9d [warning-reg-remap: 32-bit register move; native r10 has no exact BPF JIT register; remapped to BPF_REG_7; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_7, BPF_REG_9, 0, 0),
    /* 0x11aa: xor    r10d,r8d [warning-reg-remap: ALU reg operation; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_7, BPF_REG_5, 0, 0),
    /* 0x11ad: cmp    r10b,0x11 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10b,0x11] */
    /* 0x11b1: jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5> [bpf-branch: lowered cmp    r10b,0x11 + jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_7, 0, 22, 17),
    /* 0x11b3: movzx  r9d,BYTE PTR [rdi-0xb] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11b8: add    cl,r9b [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_4, BPF_REG_9, 0, 0),
    /* 0x11bb: cmp    cl,0xbf [warning-unmapped: CMP operand form has no current kop selector: cmp    cl,0xbf] */
    /* 0x11be: ja     1204 <cilium_policy_guard_tree_filter_xdp+0x104> [bpf-branch: lowered cmp    cl,0xbf + ja     1204 <cilium_policy_guard_tree_filter_xdp+0x104> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_4, 0, 22, 191),
    /* 0x11c0: movzx  ecx,BYTE PTR [rdi-0xa] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -10), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11c4: mov    r9d,ecx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x11c7: and    r9b,0x18 [warning-reg-remap: andb imm kop; verifier instantiate uses temp BPF_REG_8; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_9, 24, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x11cb: cmp    r9b,0x10 [warning-unmapped: CMP operand form has no current kop selector: cmp    r9b,0x10] */
    /* 0x11cf: jne    1210 <cilium_policy_guard_tree_filter_xdp+0x110> [bpf-branch: lowered cmp    r9b,0x10 + jne    1210 <cilium_policy_guard_tree_filter_xdp+0x110> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 19, 16),
    /* 0x11d1: movzx  r9d,BYTE PTR [rdi-0x9] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -9), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11d6: cmp    r9d,0xaa [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_9, 170), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11dd: jne    1219 <cilium_policy_guard_tree_filter_xdp+0x119> [bpf-branch: lowered cmp    r9d,0xaa + jne    1219 <cilium_policy_guard_tree_filter_xdp+0x119> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, 17, 170),
    /* 0x11df: xor    rcx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x11e2: shld   rcx,rax,0x7 [exact-kop: shld imm kop; verifier instantiate uses temp BPF_REG_8] */
    HC_KOP(HC_SHD_PAYLOAD(BPF_REG_4, BPF_REG_0, 7, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SHLDQ_IMM),
    /* 0x11e7: add    rsi,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_4, 0, 0),
    /* 0x11ea: jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -59, 0),
    /* 0x11ef: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 8),
    /* 0x11f3: jmp    1208 <cilium_policy_guard_tree_filter_xdp+0x108> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x11f5: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x11f9: add    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x11fc: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x11ff: jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -65, 0),
    /* 0x1204: shl    r9d,0x18 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 24),
    /* 0x1208: xor    rax,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_0, BPF_REG_9, 0, 0),
    /* 0x120b: jmp    1153 <cilium_policy_guard_tree_filter_xdp+0x53> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -69, 0),
    /* 0x1210: shl    rcx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 32),
    /* 0x1214: add    rax,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x1217: jmp    11fc <cilium_policy_guard_tree_filter_xdp+0xfc> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -8, 0),
    /* 0x1219: movzx  ecx,BYTE PTR [rdi-0x8] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -8), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x121d: mov    r10d,ecx [warning-reg-remap: 32-bit register move; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_7, BPF_REG_4, 0, 0),
    /* 0x1220: and    r10b,0x3 [warning-reg-remap: andb imm kop; verifier instantiate uses temp BPF_REG_8; native r10 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_7, 3, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1224: cmp    r10b,0x1 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10b,0x1] */
    /* 0x1228: je     113d <cilium_policy_guard_tree_filter_xdp+0x3d> [bpf-branch: lowered cmp    r10b,0x1 + je     113d <cilium_policy_guard_tree_filter_xdp+0x3d> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_7, 0, -80, 1),
    /* 0x122e: shl    r9,0x28 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 40),
    /* 0x1232: jmp    11f9 <cilium_policy_guard_tree_filter_xdp+0xf9> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -17, 0),
    /* 0x1234: mov    BYTE PTR [rdx],sil [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1237: mov    BYTE PTR [rdx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rdx+0x1],bh] */
    /* 0x123a: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x123c: shr    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x123f: mov    BYTE PTR [rdx+0x2],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1242: mov    eax,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_6, 0, 0),
    /* 0x1244: shr    eax,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 24),
    /* 0x1247: mov    BYTE PTR [rdx+0x3],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x124a: mov    rax,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x124d: shr    rax,0x20 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1251: mov    BYTE PTR [rdx+0x4],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1254: mov    rax,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1257: shr    rax,0x28 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 40), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x125b: mov    BYTE PTR [rdx+0x5],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x125e: mov    rax,rbx [exact-kop: movq register-to-register kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1261: shr    rax,0x30 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1265: mov    BYTE PTR [rdx+0x6],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_3, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x1268: shr    rbx,0x38 [exact-kop: shrq imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_6, 56), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x126c: mov    BYTE PTR [rdx+0x7],bl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x126f: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1274: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1275: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
