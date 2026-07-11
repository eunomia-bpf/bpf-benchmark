# cilium_ct_nat_tuple_rewrite

## Original C
```c
#include "common.h"

#define CILIUM_CT_NAT_RECORDS 32U
#define CILIUM_CT_NAT_RECORD_SIZE 32U
#define CILIUM_CT_NAT_INPUT_SIZE \
    (8U + CILIUM_CT_NAT_RECORDS * CILIUM_CT_NAT_RECORD_SIZE)

static __always_inline int
bench_cilium_ct_nat_tuple_rewrite(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, CILIUM_CT_NAT_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != CILIUM_CT_NAT_RECORDS ||
        record_size != CILIUM_CT_NAT_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0x8EBC6AF09C88C6E3ULL;
    for (u32 index = 0; index < CILIUM_CT_NAT_RECORDS; index++) {
        u32 base = 8U + index * CILIUM_CT_NAT_RECORD_SIZE;
        u32 src = micro_read_u32_le(data, base);
        u32 dst = micro_read_u32_le(data, base + 4U);
        u16 sport = micro_read_u16_le(data, base + 8U);
        u16 dport = micro_read_u16_le(data, base + 10U);
        u8 proto = data[base + 12U];
        u8 direction = data[base + 13U];
        u16 flags = micro_read_u16_le(data, base + 14U);
        u32 nat_src = micro_read_u32_le(data, base + 16U);
        u32 nat_dst = micro_read_u32_le(data, base + 20U);
        u16 rev_nat_id = micro_read_u16_le(data, base + 24U);
        u16 identity = micro_read_u16_le(data, base + 26U);
        u32 lifetime = micro_read_u32_le(data, base + 28U);

        if (proto != 6U && proto != 17U) {
            acc ^= ((u64)proto << 56U) | lifetime;
            continue;
        }

        if ((flags & 1U) != 0U) {
            src = nat_src;
            sport ^= rev_nat_id;
        }
        if ((flags & 2U) != 0U) {
            dst = nat_dst;
            dport ^= rev_nat_id;
        }
        if ((direction & 1U) != 0U) {
            u32 tmp_ip = src;
            u16 tmp_port = sport;
            src = dst;
            dst = tmp_ip;
            sport = dport;
            dport = tmp_port;
        }

        u32 tuple_hash = src ^ micro_rotl32(dst, 11U) ^
                         ((u32)sport << 16U) ^ dport ^
                         ((u32)proto << 24U) ^ identity;
        if ((flags & 4U) != 0U) {
            tuple_hash += lifetime ^ ((u32)rev_nat_id << 8U);
        }

        acc += ((u64)tuple_hash << 32U) | lifetime;
        acc ^= micro_rotl64(((u64)src << 32U) | dst, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cilium_ct_nat_tuple_rewrite_xdp,
    bench_cilium_ct_nat_tuple_rewrite,
    cilium_ct_nat_tuple_rewrite_input_value,
    CILIUM_CT_NAT_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <cilium_ct_nat_tuple_rewrite_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <cilium_ct_nat_tuple_rewrite_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe>
    1118:	48 8d b2 10 04 00 00 	lea    rsi,[rdx+0x410]
    111f:	48 39 ce             	cmp    rsi,rcx
    1122:	77 ea                	ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe>
    1124:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    1128:	75 e4                	jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe>
    112a:	83 7a 0c 20          	cmp    DWORD PTR [rdx+0xc],0x20
    112e:	75 de                	jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe>
    1130:	55                   	push   rbp
    1131:	41 57                	push   r15
    1133:	41 56                	push   r14
    1135:	41 54                	push   r12
    1137:	53                   	push   rbx
    1138:	48 8d 7a 2f          	lea    rdi,[rdx+0x2f]
    113c:	48 be e3 c6 88 9c f0 	movabs rsi,0x8ebc6af09c88c6e3
    1143:	6a bc 8e 
    1146:	45 31 c0             	xor    r8d,r8d
    1149:	e9 82 00 00 00       	jmp    11d0 <cilium_ct_nat_tuple_rewrite_xdp+0xd0>
    114e:	66 90                	xchg   ax,ax
    1150:	41 89 ef             	mov    r15d,ebp
    1153:	44 89 e5             	mov    ebp,r12d
    1156:	41 89 ec             	mov    r12d,ebp
    1159:	41 c1 c4 0b          	rol    r12d,0xb
    115d:	41 c1 e6 10          	shl    r14d,0x10
    1161:	45 31 e6             	xor    r14d,r12d
    1164:	45 0f b7 ff          	movzx  r15d,r15w
    1168:	41 c1 e2 18          	shl    r10d,0x18
    116c:	44 09 d1             	or     ecx,r10d
    116f:	44 31 f9             	xor    ecx,r15d
    1172:	44 31 f1             	xor    ecx,r14d
    1175:	31 d9                	xor    ecx,ebx
    1177:	41 c1 e3 1d          	shl    r11d,0x1d
    117b:	41 c1 fb 1f          	sar    r11d,0x1f
    117f:	41 c1 e1 08          	shl    r9d,0x8
    1183:	41 31 c1             	xor    r9d,eax
    1186:	45 21 d9             	and    r9d,r11d
    1189:	41 01 c9             	add    r9d,ecx
    118c:	49 c1 e1 20          	shl    r9,0x20
    1190:	41 89 c2             	mov    r10d,eax
    1193:	48 c1 e3 20          	shl    rbx,0x20
    1197:	41 89 eb             	mov    r11d,ebp
    119a:	49 09 db             	or     r11,rbx
    119d:	44 89 c0             	mov    eax,r8d
    11a0:	83 e0 07             	and    eax,0x7
    11a3:	8d 48 01             	lea    ecx,[rax+0x1]
    11a6:	4c 89 db             	mov    rbx,r11
    11a9:	48 d3 e3             	shl    rbx,cl
    11ac:	f6 d0                	not    al
    11ae:	89 c1                	mov    ecx,eax
    11b0:	49 d3 eb             	shr    r11,cl
    11b3:	4c 01 d6             	add    rsi,r10
    11b6:	4c 01 ce             	add    rsi,r9
    11b9:	49 09 db             	or     r11,rbx
    11bc:	4c 31 de             	xor    rsi,r11
    11bf:	49 ff c0             	inc    r8
    11c2:	48 83 c7 20          	add    rdi,0x20
    11c6:	49 83 f8 20          	cmp    r8,0x20
    11ca:	0f 84 91 00 00 00    	je     1261 <cilium_ct_nat_tuple_rewrite_xdp+0x161>
    11d0:	44 0f b6 57 ed       	movzx  r10d,BYTE PTR [rdi-0x13]
    11d5:	44 0f b7 4f f9       	movzx  r9d,WORD PTR [rdi-0x7]
    11da:	0f b7 4f fb          	movzx  ecx,WORD PTR [rdi-0x5]
    11de:	8b 47 fd             	mov    eax,DWORD PTR [rdi-0x3]
    11e1:	41 83 fa 06          	cmp    r10d,0x6
    11e5:	74 06                	je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed>
    11e7:	41 83 fa 11          	cmp    r10d,0x11
    11eb:	75 63                	jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150>
    11ed:	48 8d 5f f5          	lea    rbx,[rdi-0xb]
    11f1:	4c 8d 77 f1          	lea    r14,[rdi-0xf]
    11f5:	44 0f b6 5f ef       	movzx  r11d,BYTE PTR [rdi-0x11]
    11fa:	4c 8d 7f e5          	lea    r15,[rdi-0x1b]
    11fe:	4c 8d 67 e1          	lea    r12,[rdi-0x1f]
    1202:	44 89 dd             	mov    ebp,r11d
    1205:	83 e5 01             	and    ebp,0x1
    1208:	41 0f 45 e9          	cmovne ebp,r9d
    120c:	4d 0f 45 e6          	cmovne r12,r14
    1210:	66 33 6f e9          	xor    bp,WORD PTR [rdi-0x17]
    1214:	45 89 de             	mov    r14d,r11d
    1217:	41 83 e6 02          	and    r14d,0x2
    121b:	45 0f 45 f1          	cmovne r14d,r9d
    121f:	4c 0f 45 fb          	cmovne r15,rbx
    1223:	66 44 33 77 eb       	xor    r14w,WORD PTR [rdi-0x15]
    1228:	45 8b 24 24          	mov    r12d,DWORD PTR [r12]
    122c:	41 8b 1f             	mov    ebx,DWORD PTR [r15]
    122f:	f6 47 ee 01          	test   BYTE PTR [rdi-0x12],0x1
    1233:	0f 85 17 ff ff ff    	jne    1150 <cilium_ct_nat_tuple_rewrite_xdp+0x50>
    1239:	45 89 f7             	mov    r15d,r14d
    123c:	41 89 ee             	mov    r14d,ebp
    123f:	89 dd                	mov    ebp,ebx
    1241:	44 89 e3             	mov    ebx,r12d
    1244:	e9 0d ff ff ff       	jmp    1156 <cilium_ct_nat_tuple_rewrite_xdp+0x56>
    1249:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1250:	49 c1 e2 38          	shl    r10,0x38
    1254:	89 c0                	mov    eax,eax
    1256:	4c 09 d0             	or     rax,r10
    1259:	48 31 c6             	xor    rsi,rax
    125c:	e9 5e ff ff ff       	jmp    11bf <cilium_ct_nat_tuple_rewrite_xdp+0xbf>
    1261:	48 89 32             	mov    QWORD PTR [rdx],rsi
    1264:	b8 02 00 00 00       	mov    eax,0x2
    1269:	5b                   	pop    rbx
    126a:	41 5c                	pop    r12
    126c:	41 5e                	pop    r14
    126e:	41 5f                	pop    r15
    1270:	5d                   	pop    rbp
    1271:	c3                   	ret

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
   c:	48 81 ec 38 00 00 00 	sub    rsp,0x38
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 88 03 00 00    	ja     0x3b5
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 78 03 00 00    	ja     0x3b5
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 65 03 00 00    	ja     0x3b5
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
  85:	0f 85 2a 03 00 00    	jne    0x3b5
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
  c0:	0f 85 ef 02 00 00    	jne    0x3b5
  c6:	48 bb e3 c6 88 9c f0 	movabs rbx,0x8ebc6af09c88c6e3
  cd:	6a bc 8e 
  d0:	45 31 ed             	xor    r13d,r13d
  d3:	48 89 55 c8          	mov    QWORD PTR [rbp-0x38],rdx
  d7:	48 89 d1             	mov    rcx,rdx
  da:	48 83 c1 17          	add    rcx,0x17
  de:	e9 be 00 00 00       	jmp    0x1a1
  e3:	4c 89 ef             	mov    rdi,r13
  e6:	48 c1 e7 0b          	shl    rdi,0xb
  ea:	49 c1 e5 20          	shl    r13,0x20
  ee:	49 c1 ed 20          	shr    r13,0x20
  f2:	4c 89 ee             	mov    rsi,r13
  f5:	48 c1 ee 15          	shr    rsi,0x15
  f9:	48 09 f7             	or     rdi,rsi
  fc:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 100:	48 c1 e6 18          	shl    rsi,0x18
 104:	48 09 f0             	or     rax,rsi
 107:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 10e:	48 31 d8             	xor    rax,rbx
 111:	48 c1 e2 10          	shl    rdx,0x10
 115:	48 31 d0             	xor    rax,rdx
 118:	48 31 f8             	xor    rax,rdi
 11b:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 11f:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 126:	48 c1 e6 08          	shl    rsi,0x8
 12a:	4c 89 c7             	mov    rdi,r8
 12d:	48 31 f7             	xor    rdi,rsi
 130:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 134:	48 c1 e3 3d          	shl    rbx,0x3d
 138:	48 c1 fb 20          	sar    rbx,0x20
 13c:	48 c1 eb 1f          	shr    rbx,0x1f
 140:	48 21 fb             	and    rbx,rdi
 143:	4c 31 f8             	xor    rax,r15
 146:	49 c1 e7 20          	shl    r15,0x20
 14a:	4d 09 ef             	or     r15,r13
 14d:	4c 8b 6d e8          	mov    r13,QWORD PTR [rbp-0x18]
 151:	4c 89 ef             	mov    rdi,r13
 154:	48 83 e7 07          	and    rdi,0x7
 158:	48 89 fe             	mov    rsi,rdi
 15b:	48 83 f6 3f          	xor    rsi,0x3f
 15f:	4c 89 fa             	mov    rdx,r15
 162:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 167:	48 83 c7 01          	add    rdi,0x1
 16b:	c4 42 c1 f7 ff       	shlx   r15,r15,rdi
 170:	49 09 d7             	or     r15,rdx
 173:	48 01 d8             	add    rax,rbx
 176:	49 c1 e0 20          	shl    r8,0x20
 17a:	49 c1 e8 20          	shr    r8,0x20
 17e:	48 8b 5d f0          	mov    rbx,QWORD PTR [rbp-0x10]
 182:	4c 01 c3             	add    rbx,r8
 185:	48 c1 e0 20          	shl    rax,0x20
 189:	48 01 c3             	add    rbx,rax
 18c:	4c 31 fb             	xor    rbx,r15
 18f:	48 83 c1 20          	add    rcx,0x20
 193:	49 83 c5 01          	add    r13,0x1
 197:	49 83 fd 20          	cmp    r13,0x20
 19b:	0f 84 bf 01 00 00    	je     0x360
 1a1:	48 0f b6 41 14       	movzx  rax,BYTE PTR [rcx+0x14]
 1a6:	48 0f b6 51 13       	movzx  rdx,BYTE PTR [rcx+0x13]
 1ab:	4c 0f b6 71 12       	movzx  r14,BYTE PTR [rcx+0x12]
 1b0:	48 0f b6 71 11       	movzx  rsi,BYTE PTR [rcx+0x11]
 1b5:	4c 0f b6 41 16       	movzx  r8,BYTE PTR [rcx+0x16]
 1ba:	49 c1 e0 08          	shl    r8,0x8
 1be:	48 0f b6 79 15       	movzx  rdi,BYTE PTR [rcx+0x15]
 1c3:	49 09 f8             	or     r8,rdi
 1c6:	48 0f b6 79 17       	movzx  rdi,BYTE PTR [rcx+0x17]
 1cb:	48 c1 e7 10          	shl    rdi,0x10
 1cf:	49 09 f8             	or     r8,rdi
 1d2:	48 0f b6 79 18       	movzx  rdi,BYTE PTR [rcx+0x18]
 1d7:	48 c1 e7 18          	shl    rdi,0x18
 1db:	49 09 f8             	or     r8,rdi
 1de:	48 0f b6 79 05       	movzx  rdi,BYTE PTR [rcx+0x5]
 1e3:	48 83 ff 06          	cmp    rdi,0x6
 1e7:	74 1d                	je     0x206
 1e9:	48 83 ff 11          	cmp    rdi,0x11
 1ed:	74 17                	je     0x206
 1ef:	48 c1 e7 38          	shl    rdi,0x38
 1f3:	49 c1 e0 20          	shl    r8,0x20
 1f7:	49 c1 e8 20          	shr    r8,0x20
 1fb:	4c 09 c7             	or     rdi,r8
 1fe:	48 31 df             	xor    rdi,rbx
 201:	48 89 fb             	mov    rbx,rdi
 204:	eb 89                	jmp    0x18f
 206:	48 89 55 d0          	mov    QWORD PTR [rbp-0x30],rdx
 20a:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
 20e:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 212:	4c 89 6d e8          	mov    QWORD PTR [rbp-0x18],r13
 216:	48 0f b6 79 fe       	movzx  rdi,BYTE PTR [rcx-0x2]
 21b:	48 c1 e7 08          	shl    rdi,0x8
 21f:	48 0f b6 71 fd       	movzx  rsi,BYTE PTR [rcx-0x3]
 224:	48 09 f7             	or     rdi,rsi
 227:	48 0f b6 71 ff       	movzx  rsi,BYTE PTR [rcx-0x1]
 22c:	48 c1 e6 10          	shl    rsi,0x10
 230:	48 09 f7             	or     rdi,rsi
 233:	48 0f b6 71 00       	movzx  rsi,BYTE PTR [rcx+0x0]
 238:	48 c1 e6 18          	shl    rsi,0x18
 23c:	48 09 f7             	or     rdi,rsi
 23f:	48 0f b6 51 07       	movzx  rdx,BYTE PTR [rcx+0x7]
 244:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 248:	48 83 e2 02          	and    rdx,0x2
 24c:	48 85 d2             	test   rdx,rdx
 24f:	74 29                	je     0x27a
 251:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 256:	48 c1 e7 08          	shl    rdi,0x8
 25a:	48 0f b6 51 0d       	movzx  rdx,BYTE PTR [rcx+0xd]
 25f:	48 09 d7             	or     rdi,rdx
 262:	48 0f b6 51 0f       	movzx  rdx,BYTE PTR [rcx+0xf]
 267:	48 c1 e2 10          	shl    rdx,0x10
 26b:	48 09 d7             	or     rdi,rdx
 26e:	48 0f b6 51 10       	movzx  rdx,BYTE PTR [rcx+0x10]
 273:	48 c1 e2 18          	shl    rdx,0x18
 277:	48 09 d7             	or     rdi,rdx
 27a:	48 89 5d f0          	mov    QWORD PTR [rbp-0x10],rbx
 27e:	4c 0f b6 79 fa       	movzx  r15,BYTE PTR [rcx-0x6]
 283:	49 c1 e7 08          	shl    r15,0x8
 287:	48 0f b6 51 f9       	movzx  rdx,BYTE PTR [rcx-0x7]
 28c:	49 09 d7             	or     r15,rdx
 28f:	48 0f b6 51 fb       	movzx  rdx,BYTE PTR [rcx-0x5]
 294:	48 c1 e2 10          	shl    rdx,0x10
 298:	49 09 d7             	or     r15,rdx
 29b:	48 0f b6 51 fc       	movzx  rdx,BYTE PTR [rcx-0x4]
 2a0:	48 c1 e2 18          	shl    rdx,0x18
 2a4:	49 09 d7             	or     r15,rdx
 2a7:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 2ab:	49 83 e5 01          	and    r13,0x1
 2af:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 2b3:	4d 85 ed             	test   r13,r13
 2b6:	74 29                	je     0x2e1
 2b8:	4c 0f b6 79 0a       	movzx  r15,BYTE PTR [rcx+0xa]
 2bd:	49 c1 e7 08          	shl    r15,0x8
 2c1:	48 0f b6 51 09       	movzx  rdx,BYTE PTR [rcx+0x9]
 2c6:	49 09 d7             	or     r15,rdx
 2c9:	48 0f b6 51 0b       	movzx  rdx,BYTE PTR [rcx+0xb]
 2ce:	48 c1 e2 10          	shl    rdx,0x10
 2d2:	49 09 d7             	or     r15,rdx
 2d5:	48 0f b6 51 0c       	movzx  rdx,BYTE PTR [rcx+0xc]
 2da:	48 c1 e2 18          	shl    rdx,0x18
 2de:	49 09 d7             	or     r15,rdx
 2e1:	48 c1 e0 08          	shl    rax,0x8
 2e5:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 2e9:	48 09 d0             	or     rax,rdx
 2ec:	49 c1 e6 08          	shl    r14,0x8
 2f0:	49 09 f6             	or     r14,rsi
 2f3:	4c 89 f6             	mov    rsi,r14
 2f6:	4c 0f b6 71 04       	movzx  r14,BYTE PTR [rcx+0x4]
 2fb:	49 c1 e6 08          	shl    r14,0x8
 2ff:	48 0f b6 51 03       	movzx  rdx,BYTE PTR [rcx+0x3]
 304:	49 09 d6             	or     r14,rdx
 307:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 30b:	48 c1 e2 3e          	shl    rdx,0x3e
 30f:	48 c1 fa 3f          	sar    rdx,0x3f
 313:	48 21 f2             	and    rdx,rsi
 316:	49 31 d6             	xor    r14,rdx
 319:	48 0f b6 51 02       	movzx  rdx,BYTE PTR [rcx+0x2]
 31e:	48 c1 e2 08          	shl    rdx,0x8
 322:	48 0f b6 59 01       	movzx  rbx,BYTE PTR [rcx+0x1]
 327:	48 09 da             	or     rdx,rbx
 32a:	49 f7 dd             	neg    r13
 32d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
 331:	49 21 f5             	and    r13,rsi
 334:	4c 31 ea             	xor    rdx,r13
 337:	48 0f b6 71 06       	movzx  rsi,BYTE PTR [rcx+0x6]
 33c:	48 83 e6 01          	and    rsi,0x1
 340:	4c 89 f3             	mov    rbx,r14
 343:	49 89 fd             	mov    r13,rdi
 346:	48 85 f6             	test   rsi,rsi
 349:	0f 84 94 fd ff ff    	je     0xe3
 34f:	48 89 d3             	mov    rbx,rdx
 352:	4c 89 f2             	mov    rdx,r14
 355:	4d 89 fd             	mov    r13,r15
 358:	49 89 ff             	mov    r15,rdi
 35b:	e9 83 fd ff ff       	jmp    0xe3
 360:	48 89 df             	mov    rdi,rbx
 363:	48 c1 ef 38          	shr    rdi,0x38
 367:	48 8b 75 c8          	mov    rsi,QWORD PTR [rbp-0x38]
 36b:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 36f:	48 89 df             	mov    rdi,rbx
 372:	48 c1 ef 30          	shr    rdi,0x30
 376:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 37a:	48 89 df             	mov    rdi,rbx
 37d:	48 c1 ef 28          	shr    rdi,0x28
 381:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 385:	48 89 df             	mov    rdi,rbx
 388:	48 c1 ef 20          	shr    rdi,0x20
 38c:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 390:	48 89 df             	mov    rdi,rbx
 393:	48 c1 ef 18          	shr    rdi,0x18
 397:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 39b:	48 89 df             	mov    rdi,rbx
 39e:	48 c1 ef 10          	shr    rdi,0x10
 3a2:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 3a6:	88 5e 00             	mov    BYTE PTR [rsi+0x0],bl
 3a9:	48 c1 eb 08          	shr    rbx,0x8
 3ad:	88 5e 01             	mov    BYTE PTR [rsi+0x1],bl
 3b0:	b8 02 00 00 00       	mov    eax,0x2
 3b5:	41 5f                	pop    r15
 3b7:	41 5e                	pop    r14
 3b9:	41 5d                	pop    r13
 3bb:	5b                   	pop    rbx
 3bc:	c9                   	leave
 3bd:	c3                   	ret
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
   d:	0f 87 b1 01 00 00    	ja     0x1c4
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 a4 01 00 00    	ja     0x1c4
  20:	48 8d b1 10 04 00 00 	lea    rsi,[rcx+0x410]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 94 01 00 00    	ja     0x1c4
  30:	83 79 08 20          	cmp    DWORD PTR [rcx+0x8],0x20
  34:	0f 85 75 01 00 00    	jne    0x1af
  3a:	83 79 0c 20          	cmp    DWORD PTR [rcx+0xc],0x20
  3e:	0f 85 6b 01 00 00    	jne    0x1af
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 8d 41 17          	lea    rax,[rcx+0x17]
  52:	48 be e3 c6 88 9c f0 	movabs rsi,0x8ebc6af09c88c6e3
  59:	6a bc 8e 
  5c:	31 d2                	xor    edx,edx
  5e:	e9 9f 00 00 00       	jmp    0x102
  63:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  6a:	84 00 00 00 00 00 
  70:	4d 89 f7             	mov    r15,r14
  73:	4d 89 ee             	mov    r14,r13
  76:	44 0f b6 68 13       	movzx  r13d,BYTE PTR [rax+0x13]
  7b:	41 c1 e3 08          	shl    r11d,0x8
  7f:	c4 c3 7b f0 ee 15    	rorx   ebp,r14d,0x15
  85:	c1 e3 18             	shl    ebx,0x18
  88:	41 09 db             	or     r11d,ebx
  8b:	45 09 dd             	or     r13d,r11d
  8e:	45 31 ec             	xor    r12d,r13d
  91:	41 c1 e7 10          	shl    r15d,0x10
  95:	45 31 e7             	xor    r15d,r12d
  98:	41 c1 e2 08          	shl    r10d,0x8
  9c:	41 89 fb             	mov    r11d,edi
  9f:	45 31 d3             	xor    r11d,r10d
  a2:	49 c1 e1 3d          	shl    r9,0x3d
  a6:	49 c1 f9 20          	sar    r9,0x20
  aa:	49 c1 e9 1f          	shr    r9,0x1f
  ae:	45 21 d9             	and    r9d,r11d
  b1:	45 89 c2             	mov    r10d,r8d
  b4:	41 31 ea             	xor    r10d,ebp
  b7:	45 31 fa             	xor    r10d,r15d
  ba:	45 01 ca             	add    r10d,r9d
  bd:	49 c1 e0 20          	shl    r8,0x20
  c1:	4d 09 f0             	or     r8,r14
  c4:	41 89 d1             	mov    r9d,edx
  c7:	41 80 e1 07          	and    r9b,0x7
  cb:	45 89 cb             	mov    r11d,r9d
  ce:	41 f6 d3             	not    r11b
  d1:	c4 42 a3 f7 d8       	shrx   r11,r8,r11
  d6:	41 fe c1             	inc    r9b
  d9:	c4 42 b1 f7 c0       	shlx   r8,r8,r9
  de:	4d 09 d8             	or     r8,r11
  e1:	48 01 fe             	add    rsi,rdi
  e4:	49 c1 e2 20          	shl    r10,0x20
  e8:	49 01 f2             	add    r10,rsi
  eb:	4d 31 c2             	xor    r10,r8
  ee:	4c 89 d6             	mov    rsi,r10
  f1:	48 83 c0 20          	add    rax,0x20
  f5:	48 ff c2             	inc    rdx
  f8:	48 83 fa 20          	cmp    rdx,0x20
  fc:	0f 84 b0 00 00 00    	je     0x1b2
 102:	44 0f b6 58 14       	movzx  r11d,BYTE PTR [rax+0x14]
 107:	44 0f b6 50 12       	movzx  r10d,BYTE PTR [rax+0x12]
 10c:	8b 78 15             	mov    edi,DWORD PTR [rax+0x15]
 10f:	0f b6 58 05          	movzx  ebx,BYTE PTR [rax+0x5]
 113:	83 fb 06             	cmp    ebx,0x6
 116:	74 09                	je     0x121
 118:	83 fb 11             	cmp    ebx,0x11
 11b:	0f 85 7f 00 00 00    	jne    0x1a0
 121:	44 0f b6 48 07       	movzx  r9d,BYTE PTR [rax+0x7]
 126:	41 f6 c1 02          	test   r9b,0x2
 12a:	75 14                	jne    0x140
 12c:	44 8b 40 fd          	mov    r8d,DWORD PTR [rax-0x3]
 130:	41 f6 c1 01          	test   r9b,0x1
 134:	74 14                	je     0x14a
 136:	44 8b 68 09          	mov    r13d,DWORD PTR [rax+0x9]
 13a:	eb 12                	jmp    0x14e
 13c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
 140:	44 8b 40 0d          	mov    r8d,DWORD PTR [rax+0xd]
 144:	41 f6 c1 01          	test   r9b,0x1
 148:	75 ec                	jne    0x136
 14a:	44 8b 68 f9          	mov    r13d,DWORD PTR [rax-0x7]
 14e:	44 0f b6 78 11       	movzx  r15d,BYTE PTR [rax+0x11]
 153:	4d 89 ce             	mov    r14,r9
 156:	49 c1 e6 3e          	shl    r14,0x3e
 15a:	49 c1 fe 3f          	sar    r14,0x3f
 15e:	41 c1 e2 08          	shl    r10d,0x8
 162:	4d 09 fa             	or     r10,r15
 165:	44 0f b7 78 03       	movzx  r15d,WORD PTR [rax+0x3]
 16a:	45 21 d6             	and    r14d,r10d
 16d:	4d 31 fe             	xor    r14,r15
 170:	44 0f b7 78 01       	movzx  r15d,WORD PTR [rax+0x1]
 175:	45 89 cc             	mov    r12d,r9d
 178:	41 83 e4 01          	and    r12d,0x1
 17c:	41 f7 dc             	neg    r12d
 17f:	45 21 d4             	and    r12d,r10d
 182:	4d 31 fc             	xor    r12,r15
 185:	f6 40 06 01          	test   BYTE PTR [rax+0x6],0x1
 189:	0f 85 e1 fe ff ff    	jne    0x70
 18f:	4d 89 e7             	mov    r15,r12
 192:	4d 89 f4             	mov    r12,r14
 195:	4d 89 c6             	mov    r14,r8
 198:	4d 89 e8             	mov    r8,r13
 19b:	e9 d6 fe ff ff       	jmp    0x76
 1a0:	48 c1 e3 38          	shl    rbx,0x38
 1a4:	48 09 fb             	or     rbx,rdi
 1a7:	48 31 de             	xor    rsi,rbx
 1aa:	e9 42 ff ff ff       	jmp    0xf1
 1af:	31 c0                	xor    eax,eax
 1b1:	c3                   	ret
 1b2:	48 89 31             	mov    QWORD PTR [rcx],rsi
 1b5:	b8 02 00 00 00       	mov    eax,0x2
 1ba:	5b                   	pop    rbx
 1bb:	41 5c                	pop    r12
 1bd:	41 5d                	pop    r13
 1bf:	41 5e                	pop    r14
 1c1:	41 5f                	pop    r15
 1c3:	5d                   	pop    rbp
 1c4:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 61
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0x8],0x20]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0xc],0x20]
 * - 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1135: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1137: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1150: mov    r15d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r15d,ebp]
 * - 0x1153: mov    ebp,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r12d]
 * - 0x1156: mov    r12d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,ebp]
 * - 0x1159: rol    r12d,0xb [warning-reg-remap: roll imm kop; verifier instantiate uses temp BPF_REG_6; native r12 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1161: xor    r14d,r12d [warning-reg-remap: ALU reg operation; native r12 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1168: shl    r10d,0x18 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x116c: or     ecx,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1177: shl    r11d,0x1d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x117b: sar    r11d,0x1f [warning-unmapped: SAR destination r11d is not in the BPF JIT register file]
 * - 0x117f: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1183: xor    r9d,eax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1186: and    r9d,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x1189: add    r9d,ecx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x118c: shl    r9,0x20 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1190: mov    r10d,eax [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,eax]
 * - 0x1197: mov    r11d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,ebp]
 * - 0x119a: or     r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11a6: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11]
 * - 0x11b0: shr    r11,cl [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11b3: add    rsi,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x11b6: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11b9: or     r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x11bc: xor    rsi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x11d0: movzx  r10d,BYTE PTR [rdi-0x13] [warning-unmapped: destination register r10d is not in the BPF JIT register file]
 * - 0x11d5: movzx  r9d,WORD PTR [rdi-0x7] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11e1: cmp    r10d,0x6 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x6]
 * - 0x11e5: je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> [warning-unmapped: cannot lower cmp    r10d,0x6 + je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> to BPF branch]
 * - 0x11e7: cmp    r10d,0x11 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x11]
 * - 0x11eb: jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> [warning-unmapped: cannot lower cmp    r10d,0x11 + jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> to BPF branch]
 * - 0x11f5: movzx  r11d,BYTE PTR [rdi-0x11] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x11fe: lea    r12,[rdi-0x1f] [warning-reg-remap: LEA via x86 kop selector; native r12 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1202: mov    ebp,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r11d]
 * - 0x1205: and    ebp,0x1 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1208: cmovne ebp,r9d [warning-unmapped: cmovne operands are not supported]
 * - 0x120c: cmovne r12,r14 [warning-unmapped: cmovne needs an adjacent test/cmp proof payload]
 * - 0x1210: xor    bp,WORD PTR [rdi-0x17] [warning-unmapped: ALU destination bp is not in the BPF JIT register file]
 * - 0x1214: mov    r14d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r11d]
 * - 0x121b: cmovne r14d,r9d [warning-unmapped: cmovne needs an adjacent test/cmp proof payload]
 * - 0x121f: cmovne r15,rbx [warning-unmapped: cmovne needs an adjacent test/cmp proof payload]
 * - 0x1228: mov    r12d,DWORD PTR [r12] [warning-reg-remap: direct memory load via x86 kop selector; native r12 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x122f: test   BYTE PTR [rdi-0x12],0x1 [warning-unmapped: only testq reg,same-reg is supported]
 * - 0x1233: jne    1150 <cilium_ct_nat_tuple_rewrite_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp]
 * - 0x123c: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp]
 * - 0x123f: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx]
 * - 0x1241: mov    ebx,r12d [warning-reg-remap: 32-bit register move; native r12 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1250: shl    r10,0x38 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1256: or     rax,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x1269: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126c: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x126e: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1270: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    /* 0x110c: jbe    110f <cilium_ct_nat_tuple_rewrite_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <cilium_ct_nat_tuple_rewrite_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x410] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0x8],0x20] */
    /* 0x1128: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 32),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x20 [warning-unmapped: CMP operand form has no current kop selector: cmp    DWORD PTR [rdx+0xc],0x20] */
    /* 0x112e: jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x20 + jne    110e <cilium_ct_nat_tuple_rewrite_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -15, 32),
    /* 0x1130: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1135: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1138: lea    rdi,[rdx+0x2f] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 47), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: movabs rsi,0x8ebc6af09c88c6e3 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x8ebc6af09c88c6e3ULL),
    /* 0x1146: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x1149: jmp    11d0 <cilium_ct_nat_tuple_rewrite_xdp+0xd0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 30, 0),
    /* 0x114e: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x1150: mov    r15d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r15d,ebp] */
    /* 0x1153: mov    ebp,r12d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r12d] */
    /* 0x1156: mov    r12d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,ebp] */
    /* 0x1159: rol    r12d,0xb [warning-reg-remap: roll imm kop; verifier instantiate uses temp BPF_REG_6; native r12 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_7, BPF_REG_7, 11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x115d: shl    r14d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_8, 0, 0, 16),
    /* 0x1161: xor    r14d,r12d [warning-reg-remap: ALU reg operation; native r12 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_7, 0, 0),
    /* 0x1164: movzx  r15d,r15w [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1168: shl    r10d,0x18 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x116c: or     ecx,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x116f: xor    ecx,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_9, 0, 0),
    /* 0x1172: xor    ecx,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_8, 0, 0),
    /* 0x1175: xor    ecx,ebx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_4, BPF_REG_6, 0, 0),
    /* 0x1177: shl    r11d,0x1d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x117b: sar    r11d,0x1f [warning-unmapped: SAR destination r11d is not in the BPF JIT register file] */
    /* 0x117f: shl    r9d,0x8 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 8),
    /* 0x1183: xor    r9d,eax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x1186: and    r9d,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x1189: add    r9d,ecx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_4, 0, 0),
    /* 0x118c: shl    r9,0x20 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 32),
    /* 0x1190: mov    r10d,eax [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,eax] */
    /* 0x1193: shl    rbx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 32),
    /* 0x1197: mov    r11d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,ebp] */
    /* 0x119a: or     r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x119d: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x11a0: and    eax,0x7 [exact-kop: andl imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x11a3: lea    ecx,[rax+0x1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11a6: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11] */
    /* 0x11a9: shl    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x11ac: not    al [exact-kop: notb reg kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_NOT_NARROW_PAYLOAD(BPF_REG_0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x11ae: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x11b0: shr    r11,cl [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11b3: add    rsi,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x11b6: add    rsi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_9, 0, 0),
    /* 0x11b9: or     r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x11bc: xor    rsi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x11bf: inc    r8 [exact-kop: incq reg kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11c2: add    rdi,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 32),
    /* 0x11c6: cmp    r8,0x20 [exact-kop: cmpq reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_5, 32), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x11ca: je     1261 <cilium_ct_nat_tuple_rewrite_xdp+0x161> [bpf-branch: lowered cmp    r8,0x20 + je     1261 <cilium_ct_nat_tuple_rewrite_xdp+0x161> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_5, 0, 28, 32),
    /* 0x11d0: movzx  r10d,BYTE PTR [rdi-0x13] [warning-unmapped: destination register r10d is not in the BPF JIT register file] */
    /* 0x11d5: movzx  r9d,WORD PTR [rdi-0x7] [warning-reg-remap: direct memory load via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11da: movzx  ecx,WORD PTR [rdi-0x5] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_4, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11de: mov    eax,DWORD PTR [rdi-0x3] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11e1: cmp    r10d,0x6 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x6] */
    /* 0x11e5: je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> [warning-unmapped: cannot lower cmp    r10d,0x6 + je     11ed <cilium_ct_nat_tuple_rewrite_xdp+0xed> to BPF branch] */
    /* 0x11e7: cmp    r10d,0x11 [warning-unmapped: CMP operand form has no current kop selector: cmp    r10d,0x11] */
    /* 0x11eb: jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> [warning-unmapped: cannot lower cmp    r10d,0x11 + jne    1250 <cilium_ct_nat_tuple_rewrite_xdp+0x150> to BPF branch] */
    /* 0x11ed: lea    rbx,[rdi-0xb] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_6, BPF_REG_1, 0, 0, 1, 0, -11), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11f1: lea    r14,[rdi-0xf] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_1, 0, 0, 1, 0, -15), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11f5: movzx  r11d,BYTE PTR [rdi-0x11] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x11fa: lea    r15,[rdi-0x1b] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_1, 0, 0, 1, 0, -27), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11fe: lea    r12,[rdi-0x1f] [warning-reg-remap: LEA via x86 kop selector; native r12 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_1, 0, 0, 1, 0, -31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1202: mov    ebp,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r11d] */
    /* 0x1205: and    ebp,0x1 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1208: cmovne ebp,r9d [warning-unmapped: cmovne operands are not supported] */
    /* 0x120c: cmovne r12,r14 [warning-unmapped: cmovne needs an adjacent test/cmp proof payload] */
    /* 0x1210: xor    bp,WORD PTR [rdi-0x17] [warning-unmapped: ALU destination bp is not in the BPF JIT register file] */
    /* 0x1214: mov    r14d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r11d] */
    /* 0x1217: and    r14d,0x2 [exact-kop: andl imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x121b: cmovne r14d,r9d [warning-unmapped: cmovne needs an adjacent test/cmp proof payload] */
    /* 0x121f: cmovne r15,rbx [warning-unmapped: cmovne needs an adjacent test/cmp proof payload] */
    /* 0x1223: xor    r14w,WORD PTR [rdi-0x15] [exact-kop: xorw memory-source kop; verifier instantiate uses temps BPF_REG_6/BPF_REG_7] */
    HC_KOP(HC_ALU_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -21, BPF_REG_6, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_XORW_MEM),
    /* 0x1228: mov    r12d,DWORD PTR [r12] [warning-reg-remap: direct memory load via x86 kop selector; native r12 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_7, 0), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x122c: mov    ebx,DWORD PTR [r15] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_9, 0), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x122f: test   BYTE PTR [rdi-0x12],0x1 [warning-unmapped: only testq reg,same-reg is supported] */
    /* 0x1233: jne    1150 <cilium_ct_nat_tuple_rewrite_xdp+0x50> [warning-unmapped: standalone x86 branch needs an immediately preceding cmp] */
    /* 0x1239: mov    r15d,r14d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x123c: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp] */
    /* 0x123f: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx] */
    /* 0x1241: mov    ebx,r12d [warning-reg-remap: 32-bit register move; native r12 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_6, BPF_REG_7, 0, 0),
    /* 0x1244: jmp    1156 <cilium_ct_nat_tuple_rewrite_xdp+0x56> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -55, 0),
    /* 0x1249: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1250: shl    r10,0x38 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1254: mov    eax,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_0, 0, 0),
    /* 0x1256: or     rax,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1259: xor    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x125c: jmp    11bf <cilium_ct_nat_tuple_rewrite_xdp+0xbf> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -34, 0),
    /* 0x1261: mov    QWORD PTR [rdx],rsi [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x1264: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1269: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126a: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126c: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x126e: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1270: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1271: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
