# flow_5tuple_rss_hash

## Original C
```c
#include "common.h"

#define JHASH_MIX(a, b, c)                                                      \
    do {                                                                        \
        (a) -= (c);                                                             \
        (a) ^= micro_rotl32((c), 4U);                                           \
        (c) += (b);                                                             \
        (b) -= (a);                                                             \
        (b) ^= micro_rotl32((a), 6U);                                           \
        (a) += (c);                                                             \
        (c) -= (b);                                                             \
        (c) ^= micro_rotl32((b), 8U);                                           \
        (b) += (a);                                                             \
        (a) -= (c);                                                             \
        (a) ^= micro_rotl32((c), 16U);                                          \
        (c) += (b);                                                             \
        (b) -= (a);                                                             \
        (b) ^= micro_rotl32((a), 19U);                                          \
        (a) += (c);                                                             \
        (c) -= (b);                                                             \
        (c) ^= micro_rotl32((b), 4U);                                           \
        (b) += (a);                                                             \
    } while (0)

#define JHASH_FINAL(a, b, c)                                                    \
    do {                                                                        \
        (c) ^= (b);                                                             \
        (c) -= micro_rotl32((b), 14U);                                          \
        (a) ^= (c);                                                             \
        (a) -= micro_rotl32((c), 11U);                                          \
        (b) ^= (a);                                                             \
        (b) -= micro_rotl32((a), 25U);                                          \
        (c) ^= (b);                                                             \
        (c) -= micro_rotl32((b), 16U);                                          \
        (a) ^= (c);                                                             \
        (a) -= micro_rotl32((c), 4U);                                           \
        (b) ^= (a);                                                             \
        (b) -= micro_rotl32((a), 14U);                                          \
        (c) ^= (b);                                                             \
        (c) -= micro_rotl32((b), 24U);                                          \
    } while (0)

static __always_inline int
bench_flow_5tuple_rss_hash(const u8 *data, const u8 *data_end, u64 *out)
{
    if (data + 14U > data_end) {
        return -1;
    }

    const u8 *eth = data;
    if (micro_read_u16_be(eth, 12U) != 0x0800U) {
        return -1;
    }

    const u8 *ip = eth + 14U;
    if (ip + 20U > data_end) {
        return -1;
    }

    u8 ver_ihl = ip[0];
    u8 version = ver_ihl >> 4;
    u8 ihl_words = ver_ihl & 0x0FU;
    if (version != 4U || ihl_words < 5U) {
        return -1;
    }

    u32 ip_header_len = (u32)ihl_words * 4U;
    if (ip + ip_header_len > data_end) {
        return -1;
    }

    u16 total_len = micro_read_u16_be(ip, 2U);
    u8 protocol = ip[9U];
    if (protocol != 6U && protocol != 17U) {
        return -1;
    }

    u32 src_ip = micro_read_u32_be(ip, 12U);
    u32 dst_ip = micro_read_u32_be(ip, 16U);
    const u8 *l4 = ip + ip_header_len;
    if (l4 + 4U > data_end) {
        return -1;
    }

    u16 src_port = micro_read_u16_be(l4, 0U);
    u16 dst_port = micro_read_u16_be(l4, 2U);

    u32 a = 0xDEADBEEFU + total_len + src_ip;
    u32 b = 0x9E3779B9U + dst_ip;
    u32 c = 0x12345678U + (((u32)src_port << 16U) | dst_port) + protocol;

    JHASH_MIX(a, b, c);
    a += micro_rotl32(src_ip ^ dst_ip, 7U);
    b += ((u32)src_port << 16U) | dst_port;
    c += total_len ^ ((u32)protocol << 24U);
    JHASH_FINAL(a, b, c);

    *out = ((u64)c << 32U) ^
           ((u64)total_len << 16U) ^
           ((u64)src_port << 8U) ^
           dst_port ^
           protocol;
    return 0;
}

SEC("xdp") int flow_5tuple_rss_hash_xdp(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    u8 *payload;
    u64 result = 0;

    if (data > data_end) {
        return XDP_ABORTED;
    }

    payload = data + 8U;
    if (payload > data_end) {
        return XDP_ABORTED;
    }

    if (bench_flow_5tuple_rss_hash(payload, data_end, &result) < 0) {
        return XDP_ABORTED;
    }

    micro_write_u64_le(data, result);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <flow_5tuple_rss_hash_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	0f 87 fd 01 00 00    	ja     130f <flow_5tuple_rss_hash_xdp+0x20f>
    1112:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1116:	48 39 d6             	cmp    rsi,rdx
    1119:	0f 87 f0 01 00 00    	ja     130f <flow_5tuple_rss_hash_xdp+0x20f>
    111f:	48 8d 71 16          	lea    rsi,[rcx+0x16]
    1123:	48 39 d6             	cmp    rsi,rdx
    1126:	0f 87 e3 01 00 00    	ja     130f <flow_5tuple_rss_hash_xdp+0x20f>
    112c:	55                   	push   rbp
    112d:	48 89 e5             	mov    rbp,rsp
    1130:	41 57                	push   r15
    1132:	41 56                	push   r14
    1134:	41 54                	push   r12
    1136:	53                   	push   rbx
    1137:	0f b7 79 14          	movzx  edi,WORD PTR [rcx+0x14]
    113b:	66 c1 c7 08          	rol    di,0x8
    113f:	0f b7 ff             	movzx  edi,di
    1142:	81 ff 00 08 00 00    	cmp    edi,0x800
    1148:	0f 85 b9 01 00 00    	jne    1307 <flow_5tuple_rss_hash_xdp+0x207>
    114e:	48 8d 79 2a          	lea    rdi,[rcx+0x2a]
    1152:	48 39 d7             	cmp    rdi,rdx
    1155:	0f 87 ac 01 00 00    	ja     1307 <flow_5tuple_rss_hash_xdp+0x207>
    115b:	0f b6 3e             	movzx  edi,BYTE PTR [rsi]
    115e:	41 89 f8             	mov    r8d,edi
    1161:	41 80 e0 f0          	and    r8b,0xf0
    1165:	41 80 f8 40          	cmp    r8b,0x40
    1169:	0f 85 98 01 00 00    	jne    1307 <flow_5tuple_rss_hash_xdp+0x207>
    116f:	83 e7 0f             	and    edi,0xf
    1172:	40 80 ff 05          	cmp    dil,0x5
    1176:	0f 82 8b 01 00 00    	jb     1307 <flow_5tuple_rss_hash_xdp+0x207>
    117c:	48 8d 34 be          	lea    rsi,[rsi+rdi*4]
    1180:	48 39 d6             	cmp    rsi,rdx
    1183:	0f 87 7e 01 00 00    	ja     1307 <flow_5tuple_rss_hash_xdp+0x207>
    1189:	44 0f b6 59 18       	movzx  r11d,BYTE PTR [rcx+0x18]
    118e:	0f b6 79 19          	movzx  edi,BYTE PTR [rcx+0x19]
    1192:	0f b6 59 1f          	movzx  ebx,BYTE PTR [rcx+0x1f]
    1196:	83 fb 11             	cmp    ebx,0x11
    1199:	74 09                	je     11a4 <flow_5tuple_rss_hash_xdp+0xa4>
    119b:	83 fb 06             	cmp    ebx,0x6
    119e:	0f 85 63 01 00 00    	jne    1307 <flow_5tuple_rss_hash_xdp+0x207>
    11a4:	4c 8d 46 04          	lea    r8,[rsi+0x4]
    11a8:	49 39 d0             	cmp    r8,rdx
    11ab:	0f 87 56 01 00 00    	ja     1307 <flow_5tuple_rss_hash_xdp+0x207>
    11b1:	44 89 d8             	mov    eax,r11d
    11b4:	c1 e0 08             	shl    eax,0x8
    11b7:	09 f8                	or     eax,edi
    11b9:	44 8b 41 22          	mov    r8d,DWORD PTR [rcx+0x22]
    11bd:	44 8b 51 26          	mov    r10d,DWORD PTR [rcx+0x26]
    11c1:	41 0f ca             	bswap  r10d
    11c4:	41 0f c8             	bswap  r8d
    11c7:	0f b7 16             	movzx  edx,WORD PTR [rsi]
    11ca:	0f b7 7e 02          	movzx  edi,WORD PTR [rsi+0x2]
    11ce:	66 c1 c2 08          	rol    dx,0x8
    11d2:	0f b7 f2             	movzx  esi,dx
    11d5:	66 c1 c7 08          	rol    di,0x8
    11d9:	0f b7 ff             	movzx  edi,di
    11dc:	46 8d 0c 00          	lea    r9d,[rax+r8*1]
    11e0:	45 8d b2 b9 79 37 9e 	lea    r14d,[r10-0x61c88647]
    11e7:	89 f2                	mov    edx,esi
    11e9:	c1 e2 10             	shl    edx,0x10
    11ec:	09 fa                	or     edx,edi
    11ee:	44 8d 24 13          	lea    r12d,[rbx+rdx*1]
    11f2:	44 8d 3c 13          	lea    r15d,[rbx+rdx*1]
    11f6:	41 81 c7 78 56 34 12 	add    r15d,0x12345678
    11fd:	45 29 f9             	sub    r9d,r15d
    1200:	41 81 c1 ef be ad de 	add    r9d,0xdeadbeef
    1207:	41 c1 c7 04          	rol    r15d,0x4
    120b:	45 31 cf             	xor    r15d,r9d
    120e:	47 8d 0c 22          	lea    r9d,[r10+r12*1]
    1212:	41 81 c1 31 d0 6b b0 	add    r9d,0xb06bd031
    1219:	45 89 fc             	mov    r12d,r15d
    121c:	41 c1 c4 06          	rol    r12d,0x6
    1220:	45 29 fe             	sub    r14d,r15d
    1223:	45 31 f4             	xor    r12d,r14d
    1226:	45 01 cf             	add    r15d,r9d
    1229:	45 29 e1             	sub    r9d,r12d
    122c:	45 89 e6             	mov    r14d,r12d
    122f:	41 c1 c6 08          	rol    r14d,0x8
    1233:	45 31 ce             	xor    r14d,r9d
    1236:	45 01 fc             	add    r12d,r15d
    1239:	45 89 f1             	mov    r9d,r14d
    123c:	41 c1 c1 10          	rol    r9d,0x10
    1240:	45 29 f7             	sub    r15d,r14d
    1243:	45 31 f9             	xor    r9d,r15d
    1246:	45 01 e6             	add    r14d,r12d
    1249:	45 29 cc             	sub    r12d,r9d
    124c:	45 89 cf             	mov    r15d,r9d
    124f:	41 c1 c7 13          	rol    r15d,0x13
    1253:	45 31 e7             	xor    r15d,r12d
    1256:	45 01 f1             	add    r9d,r14d
    1259:	45 31 d0             	xor    r8d,r10d
    125c:	41 c1 c0 07          	rol    r8d,0x7
    1260:	45 29 fe             	sub    r14d,r15d
    1263:	45 01 c8             	add    r8d,r9d
    1266:	41 01 d1             	add    r9d,edx
    1269:	45 01 f9             	add    r9d,r15d
    126c:	41 c1 c7 04          	rol    r15d,0x4
    1270:	45 31 f7             	xor    r15d,r14d
    1273:	89 da                	mov    edx,ebx
    1275:	c1 e2 18             	shl    edx,0x18
    1278:	09 c2                	or     edx,eax
    127a:	44 01 fa             	add    edx,r15d
    127d:	44 31 ca             	xor    edx,r9d
    1280:	45 89 ca             	mov    r10d,r9d
    1283:	41 c1 c2 0e          	rol    r10d,0xe
    1287:	44 29 d2             	sub    edx,r10d
    128a:	41 89 d2             	mov    r10d,edx
    128d:	41 c1 c2 0b          	rol    r10d,0xb
    1291:	41 31 d0             	xor    r8d,edx
    1294:	45 29 d0             	sub    r8d,r10d
    1297:	45 31 c1             	xor    r9d,r8d
    129a:	45 89 c2             	mov    r10d,r8d
    129d:	41 c1 c2 19          	rol    r10d,0x19
    12a1:	45 29 d1             	sub    r9d,r10d
    12a4:	44 31 ca             	xor    edx,r9d
    12a7:	45 89 ca             	mov    r10d,r9d
    12aa:	41 c1 c2 10          	rol    r10d,0x10
    12ae:	44 29 d2             	sub    edx,r10d
    12b1:	41 31 d0             	xor    r8d,edx
    12b4:	41 89 d2             	mov    r10d,edx
    12b7:	41 c1 c2 04          	rol    r10d,0x4
    12bb:	45 29 d0             	sub    r8d,r10d
    12be:	45 31 c1             	xor    r9d,r8d
    12c1:	41 c1 c0 0e          	rol    r8d,0xe
    12c5:	45 29 c1             	sub    r9d,r8d
    12c8:	44 31 ca             	xor    edx,r9d
    12cb:	41 c1 c1 18          	rol    r9d,0x18
    12cf:	44 29 ca             	sub    edx,r9d
    12d2:	c1 e0 10             	shl    eax,0x10
    12d5:	c1 e6 08             	shl    esi,0x8
    12d8:	09 f3                	or     ebx,esi
    12da:	31 fb                	xor    ebx,edi
    12dc:	31 c6                	xor    esi,eax
    12de:	88 19                	mov    BYTE PTR [rcx],bl
    12e0:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    12e3:	c1 ee 10             	shr    esi,0x10
    12e6:	40 88 71 02          	mov    BYTE PTR [rcx+0x2],sil
    12ea:	44 88 59 03          	mov    BYTE PTR [rcx+0x3],r11b
    12ee:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
    12f1:	88 71 05             	mov    BYTE PTR [rcx+0x5],dh
    12f4:	89 d0                	mov    eax,edx
    12f6:	c1 e8 10             	shr    eax,0x10
    12f9:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
    12fc:	c1 ea 18             	shr    edx,0x18
    12ff:	88 51 07             	mov    BYTE PTR [rcx+0x7],dl
    1302:	b8 02 00 00 00       	mov    eax,0x2
    1307:	5b                   	pop    rbx
    1308:	41 5c                	pop    r12
    130a:	41 5e                	pop    r14
    130c:	41 5f                	pop    r15
    130e:	5d                   	pop    rbp
    130f:	c3                   	ret

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
   c:	48 81 ec 10 00 00 00 	sub    rsp,0x10
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 00          	mov    rsi,QWORD PTR [rdi+0x0]
  20:	48 8b 7f 08          	mov    rdi,QWORD PTR [rdi+0x8]
  24:	48 39 fe             	cmp    rsi,rdi
  27:	0f 87 bb 03 00 00    	ja     0x3e8
  2d:	48 89 f2             	mov    rdx,rsi
  30:	48 83 c2 08          	add    rdx,0x8
  34:	48 39 fa             	cmp    rdx,rdi
  37:	0f 87 ab 03 00 00    	ja     0x3e8
  3d:	49 89 f0             	mov    r8,rsi
  40:	49 83 c0 16          	add    r8,0x16
  44:	49 39 f8             	cmp    r8,rdi
  47:	0f 87 9b 03 00 00    	ja     0x3e8
  4d:	48 0f b6 56 14       	movzx  rdx,BYTE PTR [rsi+0x14]
  52:	48 c1 e2 08          	shl    rdx,0x8
  56:	48 0f b6 4e 15       	movzx  rcx,BYTE PTR [rsi+0x15]
  5b:	48 09 ca             	or     rdx,rcx
  5e:	48 81 e2 ff ff 00 00 	and    rdx,0xffff
  65:	48 81 fa 00 08 00 00 	cmp    rdx,0x800
  6c:	0f 85 76 03 00 00    	jne    0x3e8
  72:	48 89 f2             	mov    rdx,rsi
  75:	48 83 c2 2a          	add    rdx,0x2a
  79:	48 39 fa             	cmp    rdx,rdi
  7c:	0f 87 66 03 00 00    	ja     0x3e8
  82:	49 0f b6 50 00       	movzx  rdx,BYTE PTR [r8+0x0]
  87:	48 89 d1             	mov    rcx,rdx
  8a:	48 81 e1 f0 00 00 00 	and    rcx,0xf0
  91:	48 83 f9 40          	cmp    rcx,0x40
  95:	0f 85 4d 03 00 00    	jne    0x3e8
  9b:	48 83 e2 0f          	and    rdx,0xf
  9f:	b9 05 00 00 00       	mov    ecx,0x5
  a4:	48 39 d1             	cmp    rcx,rdx
  a7:	0f 87 3b 03 00 00    	ja     0x3e8
  ad:	48 c1 e2 02          	shl    rdx,0x2
  b1:	49 01 d0             	add    r8,rdx
  b4:	49 39 f8             	cmp    r8,rdi
  b7:	0f 87 2b 03 00 00    	ja     0x3e8
  bd:	48 0f b6 4e 19       	movzx  rcx,BYTE PTR [rsi+0x19]
  c2:	4c 0f b6 6e 18       	movzx  r13,BYTE PTR [rsi+0x18]
  c7:	48 0f b6 56 1f       	movzx  rdx,BYTE PTR [rsi+0x1f]
  cc:	48 83 fa 11          	cmp    rdx,0x11
  d0:	74 0a                	je     0xdc
  d2:	48 83 fa 06          	cmp    rdx,0x6
  d6:	0f 85 0c 03 00 00    	jne    0x3e8
  dc:	4c 89 c3             	mov    rbx,r8
  df:	48 83 c3 04          	add    rbx,0x4
  e3:	48 39 fb             	cmp    rbx,rdi
  e6:	0f 87 fc 02 00 00    	ja     0x3e8
  ec:	4c 89 ef             	mov    rdi,r13
  ef:	48 c1 e7 08          	shl    rdi,0x8
  f3:	48 09 cf             	or     rdi,rcx
  f6:	48 0f b6 46 26       	movzx  rax,BYTE PTR [rsi+0x26]
  fb:	48 c1 e0 18          	shl    rax,0x18
  ff:	48 0f b6 4e 27       	movzx  rcx,BYTE PTR [rsi+0x27]
 104:	48 c1 e1 10          	shl    rcx,0x10
 108:	48 09 c1             	or     rcx,rax
 10b:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 10f:	4d 0f b6 68 00       	movzx  r13,BYTE PTR [r8+0x0]
 114:	49 c1 e5 08          	shl    r13,0x8
 118:	49 0f b6 40 01       	movzx  rax,BYTE PTR [r8+0x1]
 11d:	49 09 c5             	or     r13,rax
 120:	49 0f b6 40 03       	movzx  rax,BYTE PTR [r8+0x3]
 125:	4d 0f b6 40 02       	movzx  r8,BYTE PTR [r8+0x2]
 12a:	49 c1 e0 08          	shl    r8,0x8
 12e:	49 09 c0             	or     r8,rax
 131:	48 0f b6 46 28       	movzx  rax,BYTE PTR [rsi+0x28]
 136:	48 c1 e0 08          	shl    rax,0x8
 13a:	48 09 c1             	or     rcx,rax
 13d:	48 0f b6 46 22       	movzx  rax,BYTE PTR [rsi+0x22]
 142:	48 c1 e0 18          	shl    rax,0x18
 146:	48 0f b6 5e 23       	movzx  rbx,BYTE PTR [rsi+0x23]
 14b:	48 c1 e3 10          	shl    rbx,0x10
 14f:	48 09 c3             	or     rbx,rax
 152:	48 0f b6 46 24       	movzx  rax,BYTE PTR [rsi+0x24]
 157:	48 c1 e0 08          	shl    rax,0x8
 15b:	48 09 c3             	or     rbx,rax
 15e:	48 0f b6 46 25       	movzx  rax,BYTE PTR [rsi+0x25]
 163:	48 09 c3             	or     rbx,rax
 166:	48 0f b6 46 29       	movzx  rax,BYTE PTR [rsi+0x29]
 16b:	48 09 c1             	or     rcx,rax
 16e:	49 81 e0 ff ff 00 00 	and    r8,0xffff
 175:	4c 89 e8             	mov    rax,r13
 178:	49 89 c7             	mov    r15,rax
 17b:	49 81 e7 ff ff 00 00 	and    r15,0xffff
 182:	48 c1 e0 10          	shl    rax,0x10
 186:	4c 09 c0             	or     rax,r8
 189:	49 89 c5             	mov    r13,rax
 18c:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 190:	49 c1 e7 08          	shl    r15,0x8
 194:	48 89 f8             	mov    rax,rdi
 197:	48 c1 e0 10          	shl    rax,0x10
 19b:	4d 89 fe             	mov    r14,r15
 19e:	49 31 c6             	xor    r14,rax
 1a1:	49 09 d7             	or     r15,rdx
 1a4:	4d 31 c7             	xor    r15,r8
 1a7:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 1ab:	44 88 46 03          	mov    BYTE PTR [rsi+0x3],r8b
 1af:	49 89 d0             	mov    r8,rdx
 1b2:	4d 01 e8             	add    r8,r13
 1b5:	49 81 c0 78 56 34 12 	add    r8,0x12345678
 1bc:	41 bd 00 00 00 f0    	mov    r13d,0xf0000000
 1c2:	4c 89 c0             	mov    rax,r8
 1c5:	4c 21 e8             	and    rax,r13
 1c8:	48 c1 e8 1c          	shr    rax,0x1c
 1cc:	49 89 d5             	mov    r13,rdx
 1cf:	4c 89 c2             	mov    rdx,r8
 1d2:	48 c1 e2 04          	shl    rdx,0x4
 1d6:	48 09 c2             	or     rdx,rax
 1d9:	49 c1 e5 18          	shl    r13,0x18
 1dd:	49 09 fd             	or     r13,rdi
 1e0:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 1e4:	48 01 df             	add    rdi,rbx
 1e7:	4c 29 c7             	sub    rdi,r8
 1ea:	48 81 c7 ef be ad de 	add    rdi,0xffffffffdeadbeef
 1f1:	48 31 d7             	xor    rdi,rdx
 1f4:	ba 00 00 00 fc       	mov    edx,0xfc000000
 1f9:	48 89 f8             	mov    rax,rdi
 1fc:	48 21 d0             	and    rax,rdx
 1ff:	48 c1 e8 1a          	shr    rax,0x1a
 203:	48 89 fa             	mov    rdx,rdi
 206:	48 c1 e2 06          	shl    rdx,0x6
 20a:	48 09 c2             	or     rdx,rax
 20d:	49 c1 ee 10          	shr    r14,0x10
 211:	44 88 76 02          	mov    BYTE PTR [rsi+0x2],r14b
 215:	48 31 cb             	xor    rbx,rcx
 218:	48 81 c1 b9 79 37 9e 	add    rcx,0xffffffff9e3779b9
 21f:	49 01 c8             	add    r8,rcx
 222:	48 29 f9             	sub    rcx,rdi
 225:	48 31 d1             	xor    rcx,rdx
 228:	ba 00 00 00 fe       	mov    edx,0xfe000000
 22d:	48 89 d8             	mov    rax,rbx
 230:	48 21 d0             	and    rax,rdx
 233:	48 c1 e3 07          	shl    rbx,0x7
 237:	48 c1 e8 19          	shr    rax,0x19
 23b:	48 09 c3             	or     rbx,rax
 23e:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 242:	49 c1 ef 08          	shr    r15,0x8
 246:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 24a:	ba 00 00 00 ff       	mov    edx,0xff000000
 24f:	48 89 c8             	mov    rax,rcx
 252:	48 21 d0             	and    rax,rdx
 255:	48 c1 e8 18          	shr    rax,0x18
 259:	48 89 ca             	mov    rdx,rcx
 25c:	48 c1 e2 08          	shl    rdx,0x8
 260:	48 09 c2             	or     rdx,rax
 263:	4c 01 c7             	add    rdi,r8
 266:	49 29 c8             	sub    r8,rcx
 269:	49 31 d0             	xor    r8,rdx
 26c:	b8 00 00 ff ff       	mov    eax,0xffff0000
 271:	4c 89 c2             	mov    rdx,r8
 274:	48 21 c2             	and    rdx,rax
 277:	48 c1 ea 10          	shr    rdx,0x10
 27b:	4c 89 c0             	mov    rax,r8
 27e:	48 c1 e0 10          	shl    rax,0x10
 282:	48 09 d0             	or     rax,rdx
 285:	48 01 f9             	add    rcx,rdi
 288:	4c 29 c7             	sub    rdi,r8
 28b:	48 31 c7             	xor    rdi,rax
 28e:	ba 00 e0 ff ff       	mov    edx,0xffffe000
 293:	48 89 f8             	mov    rax,rdi
 296:	48 21 d0             	and    rax,rdx
 299:	48 c1 e8 0d          	shr    rax,0xd
 29d:	48 89 fa             	mov    rdx,rdi
 2a0:	48 c1 e2 13          	shl    rdx,0x13
 2a4:	48 09 c2             	or     rdx,rax
 2a7:	49 01 c8             	add    r8,rcx
 2aa:	48 29 f9             	sub    rcx,rdi
 2ad:	48 31 d1             	xor    rcx,rdx
 2b0:	4c 01 c7             	add    rdi,r8
 2b3:	48 89 f8             	mov    rax,rdi
 2b6:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
 2ba:	48 01 d0             	add    rax,rdx
 2bd:	48 01 c8             	add    rax,rcx
 2c0:	41 be 00 00 fc ff    	mov    r14d,0xfffc0000
 2c6:	48 89 c2             	mov    rdx,rax
 2c9:	4c 21 f2             	and    rdx,r14
 2cc:	48 c1 ea 12          	shr    rdx,0x12
 2d0:	49 89 c7             	mov    r15,rax
 2d3:	49 c1 e7 0e          	shl    r15,0xe
 2d7:	49 09 d7             	or     r15,rdx
 2da:	48 89 ca             	mov    rdx,rcx
 2dd:	41 bd 00 00 00 f0    	mov    r13d,0xf0000000
 2e3:	4c 21 ea             	and    rdx,r13
 2e6:	48 c1 ea 1c          	shr    rdx,0x1c
 2ea:	49 29 c8             	sub    r8,rcx
 2ed:	48 c1 e1 04          	shl    rcx,0x4
 2f1:	48 09 d1             	or     rcx,rdx
 2f4:	49 31 c8             	xor    r8,rcx
 2f7:	48 01 df             	add    rdi,rbx
 2fa:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 2fe:	49 01 d0             	add    r8,rdx
 301:	49 31 c0             	xor    r8,rax
 304:	4d 29 f8             	sub    r8,r15
 307:	ba 00 00 e0 ff       	mov    edx,0xffe00000
 30c:	4c 89 c1             	mov    rcx,r8
 30f:	48 21 d1             	and    rcx,rdx
 312:	48 c1 e9 15          	shr    rcx,0x15
 316:	4c 89 c3             	mov    rbx,r8
 319:	48 c1 e3 0b          	shl    rbx,0xb
 31d:	48 09 cb             	or     rbx,rcx
 320:	4c 89 c2             	mov    rdx,r8
 323:	48 31 fa             	xor    rdx,rdi
 326:	48 29 da             	sub    rdx,rbx
 329:	bf 80 ff ff ff       	mov    edi,0xffffff80
 32e:	48 89 d1             	mov    rcx,rdx
 331:	48 21 f9             	and    rcx,rdi
 334:	48 c1 e9 07          	shr    rcx,0x7
 338:	48 89 d7             	mov    rdi,rdx
 33b:	48 c1 e7 19          	shl    rdi,0x19
 33f:	48 09 cf             	or     rdi,rcx
 342:	48 89 d3             	mov    rbx,rdx
 345:	48 31 c3             	xor    rbx,rax
 348:	48 29 fb             	sub    rbx,rdi
 34b:	48 89 df             	mov    rdi,rbx
 34e:	b9 00 00 ff ff       	mov    ecx,0xffff0000
 353:	48 21 cf             	and    rdi,rcx
 356:	48 c1 ef 10          	shr    rdi,0x10
 35a:	48 89 d9             	mov    rcx,rbx
 35d:	48 c1 e1 10          	shl    rcx,0x10
 361:	48 09 f9             	or     rcx,rdi
 364:	48 89 df             	mov    rdi,rbx
 367:	4c 31 c7             	xor    rdi,r8
 36a:	48 29 cf             	sub    rdi,rcx
 36d:	48 89 f9             	mov    rcx,rdi
 370:	4c 21 e9             	and    rcx,r13
 373:	48 c1 e9 1c          	shr    rcx,0x1c
 377:	49 89 f8             	mov    r8,rdi
 37a:	49 c1 e0 04          	shl    r8,0x4
 37e:	49 09 c8             	or     r8,rcx
 381:	48 89 f9             	mov    rcx,rdi
 384:	48 31 d1             	xor    rcx,rdx
 387:	4c 29 c1             	sub    rcx,r8
 38a:	48 89 ca             	mov    rdx,rcx
 38d:	4c 21 f2             	and    rdx,r14
 390:	48 c1 ea 12          	shr    rdx,0x12
 394:	49 89 c8             	mov    r8,rcx
 397:	49 c1 e0 0e          	shl    r8,0xe
 39b:	49 09 d0             	or     r8,rdx
 39e:	48 31 d9             	xor    rcx,rbx
 3a1:	4c 29 c1             	sub    rcx,r8
 3a4:	ba 00 ff ff ff       	mov    edx,0xffffff00
 3a9:	49 89 c8             	mov    r8,rcx
 3ac:	49 21 d0             	and    r8,rdx
 3af:	49 c1 e8 08          	shr    r8,0x8
 3b3:	48 89 ca             	mov    rdx,rcx
 3b6:	48 c1 e2 18          	shl    rdx,0x18
 3ba:	4c 09 c2             	or     rdx,r8
 3bd:	48 31 f9             	xor    rcx,rdi
 3c0:	48 29 d1             	sub    rcx,rdx
 3c3:	48 89 cf             	mov    rdi,rcx
 3c6:	48 c1 ef 18          	shr    rdi,0x18
 3ca:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3ce:	48 89 cf             	mov    rdi,rcx
 3d1:	48 c1 ef 10          	shr    rdi,0x10
 3d5:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3d9:	88 4e 04             	mov    BYTE PTR [rsi+0x4],cl
 3dc:	48 c1 e9 08          	shr    rcx,0x8
 3e0:	88 4e 05             	mov    BYTE PTR [rsi+0x5],cl
 3e3:	b8 02 00 00 00       	mov    eax,0x2
 3e8:	41 5f                	pop    r15
 3ea:	41 5e                	pop    r14
 3ec:	41 5d                	pop    r13
 3ee:	5b                   	pop    rbx
 3ef:	c9                   	leave
 3f0:	c3                   	ret
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
   d:	0f 87 65 02 00 00    	ja     0x278
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 58 02 00 00    	ja     0x278
  20:	48 8d 71 16          	lea    rsi,[rcx+0x16]
  24:	48 39 d6             	cmp    rsi,rdx
  27:	76 03                	jbe    0x2c
  29:	31 c0                	xor    eax,eax
  2b:	c3                   	ret
  2c:	66 0f 38 f0 41 14    	movbe  ax,WORD PTR [rcx+0x14]
  32:	0f b7 f8             	movzx  edi,ax
  35:	31 c0                	xor    eax,eax
  37:	81 ff 00 08 00 00    	cmp    edi,0x800
  3d:	0f 85 35 02 00 00    	jne    0x278
  43:	48 8d 79 2a          	lea    rdi,[rcx+0x2a]
  47:	48 39 d7             	cmp    rdi,rdx
  4a:	0f 87 28 02 00 00    	ja     0x278
  50:	0f b6 06             	movzx  eax,BYTE PTR [rsi]
  53:	89 c7                	mov    edi,eax
  55:	83 e7 f0             	and    edi,0xfffffff0
  58:	83 ff 40             	cmp    edi,0x40
  5b:	75 cc                	jne    0x29
  5d:	83 e0 0f             	and    eax,0xf
  60:	48 83 f8 05          	cmp    rax,0x5
  64:	72 c3                	jb     0x29
  66:	48 8d 04 86          	lea    rax,[rsi+rax*4]
  6a:	48 39 d0             	cmp    rax,rdx
  6d:	77 ba                	ja     0x29
  6f:	0f b6 79 19          	movzx  edi,BYTE PTR [rcx+0x19]
  73:	44 0f b6 41 18       	movzx  r8d,BYTE PTR [rcx+0x18]
  78:	0f b6 71 1f          	movzx  esi,BYTE PTR [rcx+0x1f]
  7c:	83 fe 11             	cmp    esi,0x11
  7f:	74 05                	je     0x86
  81:	83 fe 06             	cmp    esi,0x6
  84:	75 a3                	jne    0x29
  86:	4c 8d 48 04          	lea    r9,[rax+0x4]
  8a:	49 39 d1             	cmp    r9,rdx
  8d:	77 9a                	ja     0x29
  8f:	41 56                	push   r14
  91:	53                   	push   rbx
  92:	41 0f b6 d0          	movzx  edx,r8b
  96:	66 44 0f 38 f0 08    	movbe  r9w,WORD PTR [rax]
  9c:	66 44 0f 38 f0 50 02 	movbe  r10w,WORD PTR [rax+0x2]
  a3:	44 0f 38 f0 41 22    	movbe  r8d,DWORD PTR [rcx+0x22]
  a9:	0f 38 f0 41 26       	movbe  eax,DWORD PTR [rcx+0x26]
  ae:	88 51 03             	mov    BYTE PTR [rcx+0x3],dl
  b1:	41 89 d3             	mov    r11d,edx
  b4:	41 c1 e3 08          	shl    r11d,0x8
  b8:	49 09 fb             	or     r11,rdi
  bb:	41 0f b7 fa          	movzx  edi,r10w
  bf:	45 0f b7 d1          	movzx  r10d,r9w
  c3:	44 89 d2             	mov    edx,r10d
  c6:	c1 e2 10             	shl    edx,0x10
  c9:	48 09 fa             	or     rdx,rdi
  cc:	41 c1 e2 08          	shl    r10d,0x8
  d0:	45 89 d9             	mov    r9d,r11d
  d3:	41 c1 e1 10          	shl    r9d,0x10
  d7:	45 31 d1             	xor    r9d,r10d
  da:	49 8d 1c 32          	lea    rbx,[r10+rsi*1]
  de:	48 31 fb             	xor    rbx,rdi
  e1:	4c 8d 14 16          	lea    r10,[rsi+rdx*1]
  e5:	48 8d 3c 16          	lea    rdi,[rsi+rdx*1]
  e9:	48 81 c7 78 56 34 12 	add    rdi,0x12345678
  f0:	49 89 fe             	mov    r14,rdi
  f3:	c1 e6 18             	shl    esi,0x18
  f6:	4c 09 de             	or     rsi,r11
  f9:	49 29 fb             	sub    r11,rdi
  fc:	c1 ef 1c             	shr    edi,0x1c
  ff:	49 c1 e6 04          	shl    r14,0x4
 103:	49 09 fe             	or     r14,rdi
 106:	4b 8d 3c 03          	lea    rdi,[r11+r8*1]
 10a:	48 81 c7 ef be ad de 	add    rdi,0xffffffffdeadbeef
 111:	4c 31 f7             	xor    rdi,r14
 114:	41 89 fb             	mov    r11d,edi
 117:	41 c1 eb 1a          	shr    r11d,0x1a
 11b:	49 89 fe             	mov    r14,rdi
 11e:	49 c1 e6 06          	shl    r14,0x6
 122:	4d 09 de             	or     r14,r11
 125:	41 c1 e9 10          	shr    r9d,0x10
 129:	44 88 49 02          	mov    BYTE PTR [rcx+0x2],r9b
 12d:	49 31 c0             	xor    r8,rax
 130:	4e 8d 0c 10          	lea    r9,[rax+r10*1]
 134:	49 81 c1 31 d0 6b b0 	add    r9,0xffffffffb06bd031
 13b:	48 05 b9 79 37 9e    	add    rax,0xffffffff9e3779b9
 141:	48 29 f8             	sub    rax,rdi
 144:	4c 31 f0             	xor    rax,r14
 147:	4d 89 c2             	mov    r10,r8
 14a:	49 c1 e2 07          	shl    r10,0x7
 14e:	41 c1 e8 19          	shr    r8d,0x19
 152:	88 19                	mov    BYTE PTR [rcx],bl
 154:	4d 09 d0             	or     r8,r10
 157:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
 15a:	41 89 c2             	mov    r10d,eax
 15d:	41 c1 ea 18          	shr    r10d,0x18
 161:	49 89 c3             	mov    r11,rax
 164:	49 c1 e3 08          	shl    r11,0x8
 168:	4d 09 d3             	or     r11,r10
 16b:	4c 01 cf             	add    rdi,r9
 16e:	49 29 c1             	sub    r9,rax
 171:	4d 31 d9             	xor    r9,r11
 174:	45 89 ca             	mov    r10d,r9d
 177:	41 c1 ea 10          	shr    r10d,0x10
 17b:	4d 89 cb             	mov    r11,r9
 17e:	49 c1 e3 10          	shl    r11,0x10
 182:	4d 09 d3             	or     r11,r10
 185:	48 01 f8             	add    rax,rdi
 188:	4c 29 cf             	sub    rdi,r9
 18b:	4c 31 df             	xor    rdi,r11
 18e:	41 89 fa             	mov    r10d,edi
 191:	41 c1 ea 0d          	shr    r10d,0xd
 195:	49 89 fb             	mov    r11,rdi
 198:	49 c1 e3 13          	shl    r11,0x13
 19c:	4d 09 d3             	or     r11,r10
 19f:	49 01 c1             	add    r9,rax
 1a2:	48 29 f8             	sub    rax,rdi
 1a5:	4c 31 d8             	xor    rax,r11
 1a8:	4c 01 cf             	add    rdi,r9
 1ab:	48 01 fa             	add    rdx,rdi
 1ae:	48 01 c2             	add    rdx,rax
 1b1:	41 89 d2             	mov    r10d,edx
 1b4:	41 c1 ea 12          	shr    r10d,0x12
 1b8:	49 89 d3             	mov    r11,rdx
 1bb:	49 c1 e3 0e          	shl    r11,0xe
 1bf:	4d 09 d3             	or     r11,r10
 1c2:	41 89 c2             	mov    r10d,eax
 1c5:	41 c1 ea 1c          	shr    r10d,0x1c
 1c9:	49 29 c1             	sub    r9,rax
 1cc:	48 c1 e0 04          	shl    rax,0x4
 1d0:	4c 09 d0             	or     rax,r10
 1d3:	4c 31 c8             	xor    rax,r9
 1d6:	48 01 f0             	add    rax,rsi
 1d9:	4c 01 c7             	add    rdi,r8
 1dc:	48 31 d0             	xor    rax,rdx
 1df:	4c 29 d8             	sub    rax,r11
 1e2:	89 c6                	mov    esi,eax
 1e4:	c1 ee 15             	shr    esi,0x15
 1e7:	48 31 c7             	xor    rdi,rax
 1ea:	49 89 c0             	mov    r8,rax
 1ed:	49 c1 e0 0b          	shl    r8,0xb
 1f1:	49 09 f0             	or     r8,rsi
 1f4:	4c 29 c7             	sub    rdi,r8
 1f7:	89 fe                	mov    esi,edi
 1f9:	c1 ee 07             	shr    esi,0x7
 1fc:	48 31 fa             	xor    rdx,rdi
 1ff:	49 89 f8             	mov    r8,rdi
 202:	49 c1 e0 19          	shl    r8,0x19
 206:	49 09 f0             	or     r8,rsi
 209:	4c 29 c2             	sub    rdx,r8
 20c:	89 d6                	mov    esi,edx
 20e:	c1 ee 10             	shr    esi,0x10
 211:	48 31 d0             	xor    rax,rdx
 214:	49 89 d0             	mov    r8,rdx
 217:	49 c1 e0 10          	shl    r8,0x10
 21b:	49 09 f0             	or     r8,rsi
 21e:	4c 29 c0             	sub    rax,r8
 221:	89 c6                	mov    esi,eax
 223:	c1 ee 1c             	shr    esi,0x1c
 226:	48 31 c7             	xor    rdi,rax
 229:	49 89 c0             	mov    r8,rax
 22c:	49 c1 e0 04          	shl    r8,0x4
 230:	49 09 f0             	or     r8,rsi
 233:	4c 29 c7             	sub    rdi,r8
 236:	89 fe                	mov    esi,edi
 238:	c1 ee 12             	shr    esi,0x12
 23b:	48 31 fa             	xor    rdx,rdi
 23e:	48 c1 e7 0e          	shl    rdi,0xe
 242:	48 09 f7             	or     rdi,rsi
 245:	48 29 fa             	sub    rdx,rdi
 248:	89 d6                	mov    esi,edx
 24a:	c1 ee 08             	shr    esi,0x8
 24d:	48 31 d0             	xor    rax,rdx
 250:	48 c1 e2 18          	shl    rdx,0x18
 254:	48 09 f2             	or     rdx,rsi
 257:	48 29 d0             	sub    rax,rdx
 25a:	89 c2                	mov    edx,eax
 25c:	c1 ea 18             	shr    edx,0x18
 25f:	88 51 07             	mov    BYTE PTR [rcx+0x7],dl
 262:	89 c2                	mov    edx,eax
 264:	c1 ea 10             	shr    edx,0x10
 267:	88 51 06             	mov    BYTE PTR [rcx+0x6],dl
 26a:	88 41 04             	mov    BYTE PTR [rcx+0x4],al
 26d:	88 61 05             	mov    BYTE PTR [rcx+0x5],ah
 270:	b8 02 00 00 00       	mov    eax,0x2
 275:	5b                   	pop    rbx
 276:	41 5e                	pop    r14
 278:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 15
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112d: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1130: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1132: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1134: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1136: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1169: jne    1307 <flow_5tuple_rss_hash_xdp+0x207> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1176: jb     1307 <flow_5tuple_rss_hash_xdp+0x207> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn]
 * - 0x1307: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1308: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x130a: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x130c: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x130e: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x110c: ja     130f <flow_5tuple_rss_hash_xdp+0x20f> [bpf-branch: verifier-visible branch from preceding cmp    rcx,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_4, BPF_REG_3, 264, 0),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1119: ja     130f <flow_5tuple_rss_hash_xdp+0x20f> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, 259, 0),
    /* 0x111f: lea    rsi,[rcx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1126: ja     130f <flow_5tuple_rss_hash_xdp+0x20f> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, 254, 0),
    /* 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112d: mov    rbp,rsp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1130: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1134: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1136: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1137: movzx  edi,WORD PTR [rcx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x113b: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x113f: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1142: cmp    edi,0x800 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1148: jne    1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: verifier-visible branch from preceding cmp    edi,0x800; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_1, 0, 245, 2048),
    /* 0x114e: lea    rdi,[rcx+0x2a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1152: cmp    rdi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1155: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: verifier-visible branch from preceding cmp    rdi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_1, BPF_REG_3, 240, 0),
    /* 0x115b: movzx  edi,BYTE PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x115e: mov    r8d,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1161: and    r8b,0xf0 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 240), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x1165: cmp    r8b,0x40 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_5, 64), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1169: jne    1307 <flow_5tuple_rss_hash_xdp+0x207> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x116f: and    edi,0xf [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1172: cmp    dil,0x5 [exact-kinsn: cmpb reg,imm8 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_1, 5), MICRO_HANDCRAFT_BPF_X86_CMPB),
    /* 0x1176: jb     1307 <flow_5tuple_rss_hash_xdp+0x207> [warning-unmapped: jcc has no immediately preceding branchable cmp/test; needs a machine-level branch kinsn] */
    /* 0x117c: lea    rsi,[rsi+rdi*4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_2, BPF_REG_1, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1180: cmp    rsi,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x1183: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: verifier-visible branch from preceding cmp    rsi,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_2, BPF_REG_3, 223, 0),
    /* 0x1189: movzx  r11d,BYTE PTR [rcx+0x18] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R11, BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x118e: movzx  edi,BYTE PTR [rcx+0x19] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 25), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1192: movzx  ebx,BYTE PTR [rcx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1196: cmp    ebx,0x11 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 17), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x1199: je     11a4 <flow_5tuple_rss_hash_xdp+0xa4> [bpf-branch: verifier-visible branch from preceding cmp    ebx,0x11; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 3, 17),
    /* 0x119b: cmp    ebx,0x6 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_6, 6), MICRO_HANDCRAFT_BPF_X86_CMPL),
    /* 0x119e: jne    1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: verifier-visible branch from preceding cmp    ebx,0x6; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 211, 6),
    /* 0x11a4: lea    r8,[rsi+0x4] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 4), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11a8: cmp    r8,rdx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x11ab: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: verifier-visible branch from preceding cmp    r8,rdx; cmp kinsn is preserved] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_5, BPF_REG_3, 206, 0),
    /* 0x11b1: mov    eax,r11d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b4: shl    eax,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b7: or     eax,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11b9: mov    r8d,DWORD PTR [rcx+0x22] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11bd: mov    r10d,DWORD PTR [rcx+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c1: bswap  r10d [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11c4: bswap  r8d [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11c7: movzx  edx,WORD PTR [rsi] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11ca: movzx  edi,WORD PTR [rsi+0x2] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11ce: rol    dx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11d2: movzx  esi,dx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d5: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11d9: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11dc: lea    r9d,[rax+r8*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, BPF_REG_0, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11e0: lea    r14d,[r10-0x61c88647] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, HC_X86_R10, 0, 0, 1, 0, -1640531527), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11e7: mov    edx,esi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e9: shl    edx,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11ec: or     edx,edi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x11ee: lea    r12d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R12, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f2: lea    r15d,[rbx+rdx*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f6: add    r15d,0x12345678 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_9, 305419896), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x11fd: sub    r9d,r15d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1200: add    r9d,0xdeadbeef [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 3735928559), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1207: rol    r15d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x120b: xor    r15d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x120e: lea    r9d,[r10+r12*1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(HC_X86_R9, HC_X86_R10, HC_X86_R12, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x1212: add    r9d,0xb06bd031 [exact-kinsn: add32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 2959855665), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1219: mov    r12d,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x121c: rol    r12d,0x6 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R12, HC_X86_R12, 6), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1220: sub    r14d,r15d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1223: xor    r12d,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1226: add    r15d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1229: sub    r9d,r12d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x122c: mov    r14d,r12d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122f: rol    r14d,0x8 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 8), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1233: xor    r14d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1236: add    r12d,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1239: mov    r9d,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x123c: rol    r9d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1240: sub    r15d,r14d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1243: xor    r9d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1246: add    r14d,r12d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1249: sub    r12d,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x124c: mov    r15d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124f: rol    r15d,0x13 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 19), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1253: xor    r15d,r12d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1256: add    r9d,r14d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1259: xor    r8d,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x125c: rol    r8d,0x7 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 7), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1260: sub    r14d,r15d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1263: add    r8d,r9d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1266: add    r9d,edx [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1269: add    r9d,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x126c: rol    r15d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1270: xor    r15d,r14d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1273: mov    edx,ebx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1275: shl    edx,0x18 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x1278: or     edx,eax [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x127a: add    edx,r15d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x127d: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1280: mov    r10d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1283: rol    r10d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1287: sub    edx,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x128a: mov    r10d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x128d: rol    r10d,0xb [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 11), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x1291: xor    r8d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1294: sub    r8d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x1297: xor    r9d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x129a: mov    r10d,r8d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x129d: rol    r10d,0x19 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 25), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12a1: sub    r9d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12a4: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12a7: mov    r10d,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12aa: rol    r10d,0x10 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 16), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12ae: sub    edx,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12b1: xor    r8d,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12b4: mov    r10d,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b7: rol    r10d,0x4 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R10, HC_X86_R10, 4), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12bb: sub    r8d,r10d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12be: xor    r9d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12c1: rol    r8d,0xe [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 14), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12c5: sub    r9d,r8d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12c8: xor    edx,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12cb: rol    r9d,0x18 [exact-kinsn: roll imm kinsn] */
    HC_KINSN(HC_ROTATE_PAYLOAD(HC_X86_R9, HC_X86_R9, 24), MICRO_HANDCRAFT_BPF_X86_ROLL),
    /* 0x12cf: sub    edx,r9d [exact-kinsn: sub32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SUBL),
    /* 0x12d2: shl    eax,0x10 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d5: shl    esi,0x8 [exact-kinsn: shl32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12d8: or     ebx,esi [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12da: xor    ebx,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12dc: xor    esi,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_2, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x12de: mov    BYTE PTR [rcx],bl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_6, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12e0: mov    BYTE PTR [rcx+0x1],bh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_6, BPF_REG_4, 1, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12e3: shr    esi,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12e6: mov    BYTE PTR [rcx+0x2],sil [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12ea: mov    BYTE PTR [rcx+0x3],r11b [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, BPF_REG_4, 3), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12ee: mov    BYTE PTR [rcx+0x4],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12f1: mov    BYTE PTR [rcx+0x5],dh [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_BYTE_PAYLOAD(BPF_REG_3, BPF_REG_4, 5, 1), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12f4: mov    eax,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12f6: shr    eax,0x10 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12f9: mov    BYTE PTR [rcx+0x6],al [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_0, BPF_REG_4, 6), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x12fc: shr    edx,0x18 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 24), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x12ff: mov    BYTE PTR [rcx+0x7],dl [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1302: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1307: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1308: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x130a: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x130c: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x130e: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x130f: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec b8 01 00 00 	sub    rsp,0x1b8
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 db                	xor    ebx,ebx
  1c:	45 31 ed             	xor    r13d,r13d
  1f:	45 31 f6             	xor    r14d,r14d
  22:	48 8b 4f 00          	mov    rcx,QWORD PTR [rdi+0x0]
  26:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
  2a:	31 c0                	xor    eax,eax
  2c:	48 39 d1             	cmp    rcx,rdx
  2f:	48 39 d1             	cmp    rcx,rdx
  32:	0f 87 03 02 00 00    	ja     0x23b
  38:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  3c:	48 39 d6             	cmp    rsi,rdx
  3f:	48 39 d6             	cmp    rsi,rdx
  42:	0f 87 f3 01 00 00    	ja     0x23b
  48:	48 8d 71 16          	lea    rsi,[rcx+0x16]
  4c:	48 39 d6             	cmp    rsi,rdx
  4f:	48 39 d6             	cmp    rsi,rdx
  52:	0f 87 e3 01 00 00    	ja     0x23b
  58:	0f b7 79 14          	movzx  edi,WORD PTR [rcx+0x14]
  5c:	66 c1 c7 08          	rol    di,0x8
  60:	0f b7 ff             	movzx  edi,di
  63:	81 ff 00 08 00 00    	cmp    edi,0x800
  69:	81 ff 00 08 00 00    	cmp    edi,0x800
  6f:	0f 85 c6 01 00 00    	jne    0x23b
  75:	48 8d 79 2a          	lea    rdi,[rcx+0x2a]
  79:	48 39 d7             	cmp    rdi,rdx
  7c:	48 39 d7             	cmp    rdi,rdx
  7f:	0f 87 b6 01 00 00    	ja     0x23b
  85:	0f b6 3e             	movzx  edi,BYTE PTR [rsi]
  88:	41 89 f8             	mov    r8d,edi
  8b:	41 80 e0 f0          	and    r8b,0xf0
  8f:	41 80 f8 40          	cmp    r8b,0x40
  93:	81 e7 0f 00 00 00    	and    edi,0xf
  99:	40 80 ff 05          	cmp    dil,0x5
  9d:	48 8d 34 be          	lea    rsi,[rsi+rdi*4]
  a1:	48 39 d6             	cmp    rsi,rdx
  a4:	48 39 d6             	cmp    rsi,rdx
  a7:	0f 87 8e 01 00 00    	ja     0x23b
  ad:	44 0f b6 59 18       	movzx  r11d,BYTE PTR [rcx+0x18]
  b2:	0f b6 79 19          	movzx  edi,BYTE PTR [rcx+0x19]
  b6:	0f b6 59 1f          	movzx  ebx,BYTE PTR [rcx+0x1f]
  ba:	81 fb 11 00 00 00    	cmp    ebx,0x11
  c0:	83 fb 11             	cmp    ebx,0x11
  c3:	74 0f                	je     0xd4
  c5:	81 fb 06 00 00 00    	cmp    ebx,0x6
  cb:	83 fb 06             	cmp    ebx,0x6
  ce:	0f 85 67 01 00 00    	jne    0x23b
  d4:	4c 8d 46 04          	lea    r8,[rsi+0x4]
  d8:	49 39 d0             	cmp    r8,rdx
  db:	49 39 d0             	cmp    r8,rdx
  de:	0f 87 57 01 00 00    	ja     0x23b
  e4:	44 89 d8             	mov    eax,r11d
  e7:	c1 e0 08             	shl    eax,0x8
  ea:	09 f8                	or     eax,edi
  ec:	44 8b 41 22          	mov    r8d,DWORD PTR [rcx+0x22]
  f0:	44 8b 51 26          	mov    r10d,DWORD PTR [rcx+0x26]
  f4:	41 0f ca             	bswap  r10d
  f7:	41 0f c8             	bswap  r8d
  fa:	0f b7 16             	movzx  edx,WORD PTR [rsi]
  fd:	0f b7 7e 02          	movzx  edi,WORD PTR [rsi+0x2]
 101:	66 c1 c2 08          	rol    dx,0x8
 105:	0f b7 f2             	movzx  esi,dx
 108:	66 c1 c7 08          	rol    di,0x8
 10c:	0f b7 ff             	movzx  edi,di
 10f:	46 8d 0c 00          	lea    r9d,[rax+r8*1]
 113:	45 8d b2 b9 79 37 9e 	lea    r14d,[r10-0x61c88647]
 11a:	89 f2                	mov    edx,esi
 11c:	c1 e2 10             	shl    edx,0x10
 11f:	09 fa                	or     edx,edi
 121:	44 8d 24 13          	lea    r12d,[rbx+rdx*1]
 125:	44 8d 3c 13          	lea    r15d,[rbx+rdx*1]
 129:	41 81 c7 78 56 34 12 	add    r15d,0x12345678
 130:	45 29 f9             	sub    r9d,r15d
 133:	41 81 c1 ef be ad de 	add    r9d,0xdeadbeef
 13a:	41 c1 c7 04          	rol    r15d,0x4
 13e:	45 31 cf             	xor    r15d,r9d
 141:	47 8d 0c 22          	lea    r9d,[r10+r12*1]
 145:	41 81 c1 31 d0 6b b0 	add    r9d,0xb06bd031
 14c:	45 89 fc             	mov    r12d,r15d
 14f:	41 c1 c4 06          	rol    r12d,0x6
 153:	45 29 fe             	sub    r14d,r15d
 156:	45 31 f4             	xor    r12d,r14d
 159:	45 01 cf             	add    r15d,r9d
 15c:	45 29 e1             	sub    r9d,r12d
 15f:	45 89 e6             	mov    r14d,r12d
 162:	41 c1 c6 08          	rol    r14d,0x8
 166:	45 31 ce             	xor    r14d,r9d
 169:	45 01 fc             	add    r12d,r15d
 16c:	45 89 f1             	mov    r9d,r14d
 16f:	41 c1 c1 10          	rol    r9d,0x10
 173:	45 29 f7             	sub    r15d,r14d
 176:	45 31 f9             	xor    r9d,r15d
 179:	45 01 e6             	add    r14d,r12d
 17c:	45 29 cc             	sub    r12d,r9d
 17f:	45 89 cf             	mov    r15d,r9d
 182:	41 c1 c7 13          	rol    r15d,0x13
 186:	45 31 e7             	xor    r15d,r12d
 189:	45 01 f1             	add    r9d,r14d
 18c:	45 31 d0             	xor    r8d,r10d
 18f:	41 c1 c0 07          	rol    r8d,0x7
 193:	45 29 fe             	sub    r14d,r15d
 196:	45 01 c8             	add    r8d,r9d
 199:	41 01 d1             	add    r9d,edx
 19c:	45 01 f9             	add    r9d,r15d
 19f:	41 c1 c7 04          	rol    r15d,0x4
 1a3:	45 31 f7             	xor    r15d,r14d
 1a6:	89 da                	mov    edx,ebx
 1a8:	c1 e2 18             	shl    edx,0x18
 1ab:	09 c2                	or     edx,eax
 1ad:	44 01 fa             	add    edx,r15d
 1b0:	44 31 ca             	xor    edx,r9d
 1b3:	45 89 ca             	mov    r10d,r9d
 1b6:	41 c1 c2 0e          	rol    r10d,0xe
 1ba:	44 29 d2             	sub    edx,r10d
 1bd:	41 89 d2             	mov    r10d,edx
 1c0:	41 c1 c2 0b          	rol    r10d,0xb
 1c4:	41 31 d0             	xor    r8d,edx
 1c7:	45 29 d0             	sub    r8d,r10d
 1ca:	45 31 c1             	xor    r9d,r8d
 1cd:	45 89 c2             	mov    r10d,r8d
 1d0:	41 c1 c2 19          	rol    r10d,0x19
 1d4:	45 29 d1             	sub    r9d,r10d
 1d7:	44 31 ca             	xor    edx,r9d
 1da:	45 89 ca             	mov    r10d,r9d
 1dd:	41 c1 c2 10          	rol    r10d,0x10
 1e1:	44 29 d2             	sub    edx,r10d
 1e4:	41 31 d0             	xor    r8d,edx
 1e7:	41 89 d2             	mov    r10d,edx
 1ea:	41 c1 c2 04          	rol    r10d,0x4
 1ee:	45 29 d0             	sub    r8d,r10d
 1f1:	45 31 c1             	xor    r9d,r8d
 1f4:	41 c1 c0 0e          	rol    r8d,0xe
 1f8:	45 29 c1             	sub    r9d,r8d
 1fb:	44 31 ca             	xor    edx,r9d
 1fe:	41 c1 c1 18          	rol    r9d,0x18
 202:	44 29 ca             	sub    edx,r9d
 205:	c1 e0 10             	shl    eax,0x10
 208:	c1 e6 08             	shl    esi,0x8
 20b:	09 f3                	or     ebx,esi
 20d:	31 fb                	xor    ebx,edi
 20f:	31 c6                	xor    esi,eax
 211:	88 19                	mov    BYTE PTR [rcx],bl
 213:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
 216:	c1 ee 10             	shr    esi,0x10
 219:	40 88 71 02          	mov    BYTE PTR [rcx+0x2],sil
 21d:	44 88 59 03          	mov    BYTE PTR [rcx+0x3],r11b
 221:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
 224:	88 71 05             	mov    BYTE PTR [rcx+0x5],dh
 227:	89 d0                	mov    eax,edx
 229:	c1 e8 10             	shr    eax,0x10
 22c:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
 22f:	c1 ea 18             	shr    edx,0x18
 232:	88 51 07             	mov    BYTE PTR [rcx+0x7],dl
 235:	c7 c0 02 00 00 00    	mov    eax,0x2
 23b:	41 5f                	pop    r15
 23d:	41 5e                	pop    r14
 23f:	41 5d                	pop    r13
 241:	5b                   	pop    rbx
 242:	c9                   	leave
 243:	c3                   	ret
```
