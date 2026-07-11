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
    110c:	0f 87 f5 01 00 00    	ja     1307 <flow_5tuple_rss_hash_xdp+0x207>
    1112:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1116:	48 39 d6             	cmp    rsi,rdx
    1119:	0f 87 e8 01 00 00    	ja     1307 <flow_5tuple_rss_hash_xdp+0x207>
    111f:	48 8d 71 16          	lea    rsi,[rcx+0x16]
    1123:	48 39 d6             	cmp    rsi,rdx
    1126:	0f 87 db 01 00 00    	ja     1307 <flow_5tuple_rss_hash_xdp+0x207>
    112c:	55                   	push   rbp
    112d:	41 57                	push   r15
    112f:	41 56                	push   r14
    1131:	53                   	push   rbx
    1132:	0f b7 79 14          	movzx  edi,WORD PTR [rcx+0x14]
    1136:	66 c1 c7 08          	rol    di,0x8
    113a:	0f b7 ff             	movzx  edi,di
    113d:	81 ff 00 08 00 00    	cmp    edi,0x800
    1143:	0f 85 b8 01 00 00    	jne    1301 <flow_5tuple_rss_hash_xdp+0x201>
    1149:	48 8d 79 2a          	lea    rdi,[rcx+0x2a]
    114d:	48 39 d7             	cmp    rdi,rdx
    1150:	0f 87 ab 01 00 00    	ja     1301 <flow_5tuple_rss_hash_xdp+0x201>
    1156:	0f b6 3e             	movzx  edi,BYTE PTR [rsi]
    1159:	41 89 f8             	mov    r8d,edi
    115c:	41 80 e0 f0          	and    r8b,0xf0
    1160:	41 80 f8 40          	cmp    r8b,0x40
    1164:	0f 85 97 01 00 00    	jne    1301 <flow_5tuple_rss_hash_xdp+0x201>
    116a:	83 e7 0f             	and    edi,0xf
    116d:	40 80 ff 05          	cmp    dil,0x5
    1171:	0f 82 8a 01 00 00    	jb     1301 <flow_5tuple_rss_hash_xdp+0x201>
    1177:	48 8d 34 be          	lea    rsi,[rsi+rdi*4]
    117b:	48 39 d6             	cmp    rsi,rdx
    117e:	0f 87 7d 01 00 00    	ja     1301 <flow_5tuple_rss_hash_xdp+0x201>
    1184:	44 0f b6 59 18       	movzx  r11d,BYTE PTR [rcx+0x18]
    1189:	0f b6 79 19          	movzx  edi,BYTE PTR [rcx+0x19]
    118d:	0f b6 59 1f          	movzx  ebx,BYTE PTR [rcx+0x1f]
    1191:	83 fb 11             	cmp    ebx,0x11
    1194:	74 09                	je     119f <flow_5tuple_rss_hash_xdp+0x9f>
    1196:	83 fb 06             	cmp    ebx,0x6
    1199:	0f 85 62 01 00 00    	jne    1301 <flow_5tuple_rss_hash_xdp+0x201>
    119f:	4c 8d 46 04          	lea    r8,[rsi+0x4]
    11a3:	49 39 d0             	cmp    r8,rdx
    11a6:	0f 87 55 01 00 00    	ja     1301 <flow_5tuple_rss_hash_xdp+0x201>
    11ac:	44 89 d8             	mov    eax,r11d
    11af:	c1 e0 08             	shl    eax,0x8
    11b2:	09 f8                	or     eax,edi
    11b4:	44 8b 41 22          	mov    r8d,DWORD PTR [rcx+0x22]
    11b8:	44 8b 51 26          	mov    r10d,DWORD PTR [rcx+0x26]
    11bc:	41 0f ca             	bswap  r10d
    11bf:	41 0f c8             	bswap  r8d
    11c2:	0f b7 16             	movzx  edx,WORD PTR [rsi]
    11c5:	0f b7 7e 02          	movzx  edi,WORD PTR [rsi+0x2]
    11c9:	66 c1 c2 08          	rol    dx,0x8
    11cd:	0f b7 f2             	movzx  esi,dx
    11d0:	66 c1 c7 08          	rol    di,0x8
    11d4:	0f b7 ff             	movzx  edi,di
    11d7:	46 8d 0c 00          	lea    r9d,[rax+r8*1]
    11db:	41 8d aa b9 79 37 9e 	lea    ebp,[r10-0x61c88647]
    11e2:	89 f2                	mov    edx,esi
    11e4:	c1 e2 10             	shl    edx,0x10
    11e7:	09 fa                	or     edx,edi
    11e9:	44 8d 3c 13          	lea    r15d,[rbx+rdx*1]
    11ed:	44 8d 34 13          	lea    r14d,[rbx+rdx*1]
    11f1:	41 81 c6 78 56 34 12 	add    r14d,0x12345678
    11f8:	45 29 f1             	sub    r9d,r14d
    11fb:	41 81 c1 ef be ad de 	add    r9d,0xdeadbeef
    1202:	41 c1 c6 04          	rol    r14d,0x4
    1206:	45 31 ce             	xor    r14d,r9d
    1209:	47 8d 0c 3a          	lea    r9d,[r10+r15*1]
    120d:	41 81 c1 31 d0 6b b0 	add    r9d,0xb06bd031
    1214:	45 89 f7             	mov    r15d,r14d
    1217:	41 c1 c7 06          	rol    r15d,0x6
    121b:	44 29 f5             	sub    ebp,r14d
    121e:	41 31 ef             	xor    r15d,ebp
    1221:	45 01 ce             	add    r14d,r9d
    1224:	45 29 f9             	sub    r9d,r15d
    1227:	44 89 fd             	mov    ebp,r15d
    122a:	c1 c5 08             	rol    ebp,0x8
    122d:	44 31 cd             	xor    ebp,r9d
    1230:	45 01 f7             	add    r15d,r14d
    1233:	41 89 e9             	mov    r9d,ebp
    1236:	41 c1 c1 10          	rol    r9d,0x10
    123a:	41 29 ee             	sub    r14d,ebp
    123d:	45 31 f1             	xor    r9d,r14d
    1240:	44 01 fd             	add    ebp,r15d
    1243:	45 29 cf             	sub    r15d,r9d
    1246:	45 89 ce             	mov    r14d,r9d
    1249:	41 c1 c6 13          	rol    r14d,0x13
    124d:	45 31 fe             	xor    r14d,r15d
    1250:	41 01 e9             	add    r9d,ebp
    1253:	45 31 d0             	xor    r8d,r10d
    1256:	41 c1 c0 07          	rol    r8d,0x7
    125a:	44 29 f5             	sub    ebp,r14d
    125d:	45 01 c8             	add    r8d,r9d
    1260:	41 01 d1             	add    r9d,edx
    1263:	45 01 f1             	add    r9d,r14d
    1266:	41 c1 c6 04          	rol    r14d,0x4
    126a:	41 31 ee             	xor    r14d,ebp
    126d:	89 da                	mov    edx,ebx
    126f:	c1 e2 18             	shl    edx,0x18
    1272:	09 c2                	or     edx,eax
    1274:	44 01 f2             	add    edx,r14d
    1277:	44 31 ca             	xor    edx,r9d
    127a:	45 89 ca             	mov    r10d,r9d
    127d:	41 c1 c2 0e          	rol    r10d,0xe
    1281:	44 29 d2             	sub    edx,r10d
    1284:	41 89 d2             	mov    r10d,edx
    1287:	41 c1 c2 0b          	rol    r10d,0xb
    128b:	41 31 d0             	xor    r8d,edx
    128e:	45 29 d0             	sub    r8d,r10d
    1291:	45 31 c1             	xor    r9d,r8d
    1294:	45 89 c2             	mov    r10d,r8d
    1297:	41 c1 c2 19          	rol    r10d,0x19
    129b:	45 29 d1             	sub    r9d,r10d
    129e:	44 31 ca             	xor    edx,r9d
    12a1:	45 89 ca             	mov    r10d,r9d
    12a4:	41 c1 c2 10          	rol    r10d,0x10
    12a8:	44 29 d2             	sub    edx,r10d
    12ab:	41 31 d0             	xor    r8d,edx
    12ae:	41 89 d2             	mov    r10d,edx
    12b1:	41 c1 c2 04          	rol    r10d,0x4
    12b5:	45 29 d0             	sub    r8d,r10d
    12b8:	45 31 c1             	xor    r9d,r8d
    12bb:	41 c1 c0 0e          	rol    r8d,0xe
    12bf:	45 29 c1             	sub    r9d,r8d
    12c2:	44 31 ca             	xor    edx,r9d
    12c5:	41 c1 c1 18          	rol    r9d,0x18
    12c9:	44 29 ca             	sub    edx,r9d
    12cc:	c1 e0 10             	shl    eax,0x10
    12cf:	c1 e6 08             	shl    esi,0x8
    12d2:	09 f3                	or     ebx,esi
    12d4:	31 fb                	xor    ebx,edi
    12d6:	31 c6                	xor    esi,eax
    12d8:	88 19                	mov    BYTE PTR [rcx],bl
    12da:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
    12dd:	c1 ee 10             	shr    esi,0x10
    12e0:	40 88 71 02          	mov    BYTE PTR [rcx+0x2],sil
    12e4:	44 88 59 03          	mov    BYTE PTR [rcx+0x3],r11b
    12e8:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
    12eb:	88 71 05             	mov    BYTE PTR [rcx+0x5],dh
    12ee:	89 d0                	mov    eax,edx
    12f0:	c1 e8 10             	shr    eax,0x10
    12f3:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
    12f6:	c1 ea 18             	shr    edx,0x18
    12f9:	88 51 07             	mov    BYTE PTR [rcx+0x7],dl
    12fc:	b8 02 00 00 00       	mov    eax,0x2
    1301:	5b                   	pop    rbx
    1302:	41 5e                	pop    r14
    1304:	41 5f                	pop    r15
    1306:	5d                   	pop    rbp
    1307:	c3                   	ret

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
 * native asm to handcraft warnings: 69
 *
 * - 0x1100: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112d: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112f: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1131: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1160: cmp    r8b,0x40 [warning-unmapped: CMP operand form has no current kop selector: cmp    r8b,0x40]
 * - 0x116d: cmp    dil,0x5 [warning-unmapped: CMP operand form has no current kop selector: cmp    dil,0x5]
 * - 0x1184: movzx  r11d,BYTE PTR [rcx+0x18] [warning-reg-remap: direct memory load via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11ac: mov    eax,r11d [warning-reg-remap: 32-bit register move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x11b8: mov    r10d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,DWORD PTR [rcx+0x26]]
 * - 0x11bc: bswap  r10d [warning-unmapped: BSWAP destination r10d is not in the BPF JIT register file]
 * - 0x11d7: lea    r9d,[rax+r8*1] [warning-reg-remap: LEA via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11db: lea    ebp,[r10-0x61c88647] [warning-unmapped: LEA operands are not representable]
 * - 0x11f8: sub    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11fb: add    r9d,0xdeadbeef [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1206: xor    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1209: lea    r9d,[r10+r15*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r15*1]]
 * - 0x120d: add    r9d,0xb06bd031 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x121b: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x121e: xor    r15d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x1221: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1224: sub    r9d,r15d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1227: mov    ebp,r15d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r15d]
 * - 0x122a: rol    ebp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: ebp]
 * - 0x122d: xor    ebp,r9d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1233: mov    r9d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r9d,ebp]
 * - 0x1236: rol    r9d,0x10 [warning-reg-remap: roll imm kop; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x123a: sub    r14d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x123d: xor    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1240: add    ebp,r15d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x1243: sub    r15d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1246: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1250: add    r9d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x1253: xor    r8d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x125a: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x125d: add    r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1260: add    r9d,edx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1263: add    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x126a: xor    r14d,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x1277: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x127a: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d]
 * - 0x127d: rol    r10d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x1281: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1284: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx]
 * - 0x1287: rol    r10d,0xb [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x128e: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1291: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1294: mov    r10d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r8d]
 * - 0x1297: rol    r10d,0x19 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x129b: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x129e: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12a1: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d]
 * - 0x12a4: rol    r10d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x12a8: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x12ae: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx]
 * - 0x12b1: rol    r10d,0x4 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x12b5: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x12b8: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12bf: sub    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c2: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c5: rol    r9d,0x18 [warning-reg-remap: roll imm kop; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c9: sub    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12da: mov    BYTE PTR [rcx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rcx+0x1],bh]
 * - 0x12e4: mov    BYTE PTR [rcx+0x3],r11b [warning-reg-remap: direct memory store via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7]
 * - 0x1301: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1302: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1304: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1306: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
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
    /* 0x110c: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: lowered cmp    rcx,rdx + ja     1307 <flow_5tuple_rss_hash_xdp+0x207> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_3, 152),
    /* 0x1112: lea    rsi,[rcx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rsi,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1119: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: lowered cmp    rsi,rdx + ja     1307 <flow_5tuple_rss_hash_xdp+0x207> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 147),
    /* 0x111f: lea    rsi,[rcx+0x16] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    rsi,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1126: ja     1307 <flow_5tuple_rss_hash_xdp+0x207> [bpf-branch: lowered cmp    rsi,rdx + ja     1307 <flow_5tuple_rss_hash_xdp+0x207> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 142),
    /* 0x112c: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112d: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112f: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1131: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: movzx  edi,WORD PTR [rcx+0x14] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1136: rol    di,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x113a: movzx  edi,di [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x113d: cmp    edi,0x800 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2048), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1143: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    edi,0x800 + jne    1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_1, 0, 133, 2048),
    /* 0x1149: lea    rdi,[rcx+0x2a] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114d: cmp    rdi,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1150: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    rdi,rdx + ja     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_3, 128),
    /* 0x1156: movzx  edi,BYTE PTR [rsi] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1159: mov    r8d,edi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x115c: and    r8b,0xf0 [exact-kop: andb imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_5, 240, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1160: cmp    r8b,0x40 [warning-unmapped: CMP operand form has no current kop selector: cmp    r8b,0x40] */
    /* 0x1164: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    r8b,0x40 + jne    1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, 122, 64),
    /* 0x116a: and    edi,0xf [exact-kop: andl imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_1, 15), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x116d: cmp    dil,0x5 [warning-unmapped: CMP operand form has no current kop selector: cmp    dil,0x5] */
    /* 0x1171: jb     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    dil,0x5 + jb     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_1, 0, 119, 5),
    /* 0x1177: lea    rsi,[rsi+rdi*4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_2, BPF_REG_1, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x117b: cmp    rsi,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x117e: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    rsi,rdx + ja     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 114),
    /* 0x1184: movzx  r11d,BYTE PTR [rcx+0x18] [warning-reg-remap: direct memory load via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_4, 24), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1189: movzx  edi,BYTE PTR [rcx+0x19] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 25), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x118d: movzx  ebx,BYTE PTR [rcx+0x1f] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1191: cmp    ebx,0x11 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_6, 17), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1194: je     119f <flow_5tuple_rss_hash_xdp+0x9f> [bpf-branch: lowered cmp    ebx,0x11 + je     119f <flow_5tuple_rss_hash_xdp+0x9f> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 3, 17),
    /* 0x1196: cmp    ebx,0x6 [exact-kop: cmpl reg,imm32 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_6, 6), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1199: jne    1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    ebx,0x6 + jne    1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 102, 6),
    /* 0x119f: lea    r8,[rsi+0x4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 4), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11a3: cmp    r8,rdx [exact-kop: cmpq reg,reg kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x11a6: ja     1301 <flow_5tuple_rss_hash_xdp+0x201> [bpf-branch: lowered cmp    r8,rdx + ja     1301 <flow_5tuple_rss_hash_xdp+0x201> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_5, BPF_REG_3, 97),
    /* 0x11ac: mov    eax,r11d [warning-reg-remap: 32-bit register move; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_7, 0, 0),
    /* 0x11af: shl    eax,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 8),
    /* 0x11b2: or     eax,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_1, 0, 0),
    /* 0x11b4: mov    r8d,DWORD PTR [rcx+0x22] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11b8: mov    r10d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,DWORD PTR [rcx+0x26]] */
    /* 0x11bc: bswap  r10d [warning-unmapped: BSWAP destination r10d is not in the BPF JIT register file] */
    /* 0x11bf: bswap  r8d [exact-kop: bswapl kop] */
    HC_KOP(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x11c2: movzx  edx,WORD PTR [rsi] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11c5: movzx  edi,WORD PTR [rsi+0x2] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x11c9: rol    dx,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x11cd: movzx  esi,dx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11d0: rol    di,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x11d4: movzx  edi,di [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x11d7: lea    r9d,[rax+r8*1] [warning-reg-remap: LEA via x86 kop selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_0, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11db: lea    ebp,[r10-0x61c88647] [warning-unmapped: LEA operands are not representable] */
    /* 0x11e2: mov    edx,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x11e4: shl    edx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 16),
    /* 0x11e7: or     edx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x11e9: lea    r15d,[rbx+rdx*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_9, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11ed: lea    r14d,[rbx+rdx*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_6, BPF_REG_3, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11f1: add    r14d,0x12345678 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_8, 0, 0, 305419896),
    /* 0x11f8: sub    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x11fb: add    r9d,0xdeadbeef [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 3735928559),
    /* 0x1202: rol    r14d,0x4 [exact-kop: roll imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1206: xor    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1209: lea    r9d,[r10+r15*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r15*1]] */
    /* 0x120d: add    r9d,0xb06bd031 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 2959855665),
    /* 0x1214: mov    r15d,r14d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1217: rol    r15d,0x6 [exact-kop: roll imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 6, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x121b: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x121e: xor    r15d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x1221: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1224: sub    r9d,r15d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_9, 0, 0),
    /* 0x1227: mov    ebp,r15d [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,r15d] */
    /* 0x122a: rol    ebp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: ebp] */
    /* 0x122d: xor    ebp,r9d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1230: add    r15d,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1233: mov    r9d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r9d,ebp] */
    /* 0x1236: rol    r9d,0x10 [warning-reg-remap: roll imm kop; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x123a: sub    r14d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x123d: xor    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1240: add    ebp,r15d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x1243: sub    r15d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_9, 0, 0),
    /* 0x1246: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1249: rol    r14d,0x13 [exact-kop: roll imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 19, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x124d: xor    r14d,r15d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1250: add    r9d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x1253: xor    r8d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1256: rol    r8d,0x7 [exact-kop: roll imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 7, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x125a: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x125d: add    r8d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_9, 0, 0),
    /* 0x1260: add    r9d,edx [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x1263: add    r9d,r14d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_8, 0, 0),
    /* 0x1266: rol    r14d,0x4 [exact-kop: roll imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x126a: xor    r14d,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x126d: mov    edx,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_3, BPF_REG_6, 0, 0),
    /* 0x126f: shl    edx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x1272: or     edx,eax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1274: add    edx,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_8, 0, 0),
    /* 0x1277: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x127a: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d] */
    /* 0x127d: rol    r10d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x1281: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1284: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx] */
    /* 0x1287: rol    r10d,0xb [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x128b: xor    r8d,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_3, 0, 0),
    /* 0x128e: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1291: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1294: mov    r10d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r8d] */
    /* 0x1297: rol    r10d,0x19 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x129b: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x129e: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x12a1: mov    r10d,r9d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r9d] */
    /* 0x12a4: rol    r10d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x12a8: sub    edx,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x12ab: xor    r8d,edx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_5, BPF_REG_3, 0, 0),
    /* 0x12ae: mov    r10d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,edx] */
    /* 0x12b1: rol    r10d,0x4 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x12b5: sub    r8d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x12b8: xor    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x12bb: rol    r8d,0xe [exact-kop: roll imm kop; verifier instantiate uses temp BPF_REG_6] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_5, 14, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x12bf: sub    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x12c2: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x12c5: rol    r9d,0x18 [warning-reg-remap: roll imm kop; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KOP(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 24, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x12c9: sub    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x12cc: shl    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x12cf: shl    esi,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 8),
    /* 0x12d2: or     ebx,esi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_6, BPF_REG_2, 0, 0),
    /* 0x12d4: xor    ebx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x12d6: xor    esi,eax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x12d8: mov    BYTE PTR [rcx],bl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_6, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12da: mov    BYTE PTR [rcx+0x1],bh [warning-unmapped: unsupported mnemonic or operand form: mov    BYTE PTR [rcx+0x1],bh] */
    /* 0x12dd: shr    esi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_2, 0, 0, 16),
    /* 0x12e0: mov    BYTE PTR [rcx+0x2],sil [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 2), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12e4: mov    BYTE PTR [rcx+0x3],r11b [warning-reg-remap: direct memory store via x86 kop selector; native r11 has no exact BPF JIT register; remapped to BPF_REG_7] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_4, 3), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12e8: mov    BYTE PTR [rcx+0x4],dl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 4), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12eb: mov    BYTE PTR [rcx+0x5],dh [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 5), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12ee: mov    eax,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_3, 0, 0),
    /* 0x12f0: shr    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x12f3: mov    BYTE PTR [rcx+0x6],al [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_0, BPF_REG_4, 6), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12f6: shr    edx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x12f9: mov    BYTE PTR [rcx+0x7],dl [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_MOVB_MEM_REG),
    /* 0x12fc: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1301: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1302: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1304: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1306: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1307: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
