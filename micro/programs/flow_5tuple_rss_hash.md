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

0000000000001308 <_fini>:
    1308:	f3 0f 1e fa          	endbr64
    130c:	48 83 ec 08          	sub    rsp,0x8
    1310:	48 83 c4 08          	add    rsp,0x8
    1314:	c3                   	ret
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
  20:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
  24:	48 39 d6             	cmp    rsi,rdx
  27:	0f 87 fd 02 00 00    	ja     0x32a
  2d:	48 89 f7             	mov    rdi,rsi
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 d7             	cmp    rdi,rdx
  37:	0f 87 ed 02 00 00    	ja     0x32a
  3d:	48 89 f1             	mov    rcx,rsi
  40:	48 83 c1 16          	add    rcx,0x16
  44:	48 39 d1             	cmp    rcx,rdx
  47:	0f 87 dd 02 00 00    	ja     0x32a
  4d:	48 0f b6 7e 14       	movzx  rdi,BYTE PTR [rsi+0x14]
  52:	c1 e7 08             	shl    edi,0x8
  55:	4c 0f b6 46 15       	movzx  r8,BYTE PTR [rsi+0x15]
  5a:	44 09 c7             	or     edi,r8d
  5d:	81 e7 ff ff 00 00    	and    edi,0xffff
  63:	81 ff 00 08 00 00    	cmp    edi,0x800
  69:	0f 85 bb 02 00 00    	jne    0x32a
  6f:	48 89 f7             	mov    rdi,rsi
  72:	48 83 c7 2a          	add    rdi,0x2a
  76:	48 39 d7             	cmp    rdi,rdx
  79:	0f 87 ab 02 00 00    	ja     0x32a
  7f:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
  84:	41 89 f8             	mov    r8d,edi
  87:	41 81 e0 f0 00 00 00 	and    r8d,0xf0
  8e:	41 83 f8 40          	cmp    r8d,0x40
  92:	0f 85 92 02 00 00    	jne    0x32a
  98:	83 e7 0f             	and    edi,0xf
  9b:	83 ff 05             	cmp    edi,0x5
  9e:	0f 82 86 02 00 00    	jb     0x32a
  a4:	c1 e7 02             	shl    edi,0x2
  a7:	48 01 f9             	add    rcx,rdi
  aa:	48 39 d1             	cmp    rcx,rdx
  ad:	0f 87 77 02 00 00    	ja     0x32a
  b3:	48 0f b6 7e 19       	movzx  rdi,BYTE PTR [rsi+0x19]
  b8:	4c 0f b6 6e 18       	movzx  r13,BYTE PTR [rsi+0x18]
  bd:	4c 0f b6 46 1f       	movzx  r8,BYTE PTR [rsi+0x1f]
  c2:	41 83 f8 11          	cmp    r8d,0x11
  c6:	74 0a                	je     0xd2
  c8:	41 83 f8 06          	cmp    r8d,0x6
  cc:	0f 85 58 02 00 00    	jne    0x32a
  d2:	48 89 cb             	mov    rbx,rcx
  d5:	48 83 c3 04          	add    rbx,0x4
  d9:	48 39 d3             	cmp    rbx,rdx
  dc:	0f 87 48 02 00 00    	ja     0x32a
  e2:	44 89 e8             	mov    eax,r13d
  e5:	c1 e0 08             	shl    eax,0x8
  e8:	09 f8                	or     eax,edi
  ea:	48 0f b6 7e 26       	movzx  rdi,BYTE PTR [rsi+0x26]
  ef:	c1 e7 18             	shl    edi,0x18
  f2:	48 0f b6 56 27       	movzx  rdx,BYTE PTR [rsi+0x27]
  f7:	c1 e2 10             	shl    edx,0x10
  fa:	09 fa                	or     edx,edi
  fc:	48 0f b6 7e 28       	movzx  rdi,BYTE PTR [rsi+0x28]
 101:	c1 e7 08             	shl    edi,0x8
 104:	09 fa                	or     edx,edi
 106:	48 0f b6 59 00       	movzx  rbx,BYTE PTR [rcx+0x0]
 10b:	c1 e3 08             	shl    ebx,0x8
 10e:	48 0f b6 79 01       	movzx  rdi,BYTE PTR [rcx+0x1]
 113:	09 fb                	or     ebx,edi
 115:	4c 0f b6 71 03       	movzx  r14,BYTE PTR [rcx+0x3]
 11a:	48 0f b6 79 02       	movzx  rdi,BYTE PTR [rcx+0x2]
 11f:	c1 e7 08             	shl    edi,0x8
 122:	44 09 f7             	or     edi,r14d
 125:	89 f9                	mov    ecx,edi
 127:	81 e1 ff ff 00 00    	and    ecx,0xffff
 12d:	41 89 de             	mov    r14d,ebx
 130:	41 c1 e6 10          	shl    r14d,0x10
 134:	41 09 ce             	or     r14d,ecx
 137:	44 89 75 f0          	mov    DWORD PTR [rbp-0x10],r14d
 13b:	48 0f b6 4e 29       	movzx  rcx,BYTE PTR [rsi+0x29]
 140:	09 ca                	or     edx,ecx
 142:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 149:	48 c1 e3 08          	shl    rbx,0x8
 14d:	49 89 df             	mov    r15,rbx
 150:	4d 09 c7             	or     r15,r8
 153:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 15a:	49 31 ff             	xor    r15,rdi
 15d:	89 c7                	mov    edi,eax
 15f:	c1 e7 10             	shl    edi,0x10
 162:	31 fb                	xor    ebx,edi
 164:	44 88 6e 03          	mov    BYTE PTR [rsi+0x3],r13b
 168:	44 89 c1             	mov    ecx,r8d
 16b:	44 01 f1             	add    ecx,r14d
 16e:	81 c1 78 56 34 12    	add    ecx,0x12345678
 174:	41 89 cd             	mov    r13d,ecx
 177:	41 c1 ed 1c          	shr    r13d,0x1c
 17b:	89 cf                	mov    edi,ecx
 17d:	c1 e7 04             	shl    edi,0x4
 180:	44 09 ef             	or     edi,r13d
 183:	4c 0f b6 76 22       	movzx  r14,BYTE PTR [rsi+0x22]
 188:	41 c1 e6 18          	shl    r14d,0x18
 18c:	4c 0f b6 6e 23       	movzx  r13,BYTE PTR [rsi+0x23]
 191:	41 c1 e5 10          	shl    r13d,0x10
 195:	45 09 f5             	or     r13d,r14d
 198:	4c 0f b6 76 24       	movzx  r14,BYTE PTR [rsi+0x24]
 19d:	41 c1 e6 08          	shl    r14d,0x8
 1a1:	45 09 f5             	or     r13d,r14d
 1a4:	4c 0f b6 76 25       	movzx  r14,BYTE PTR [rsi+0x25]
 1a9:	45 09 f5             	or     r13d,r14d
 1ac:	41 89 c6             	mov    r14d,eax
 1af:	45 01 ee             	add    r14d,r13d
 1b2:	41 29 ce             	sub    r14d,ecx
 1b5:	41 81 c6 ef be ad de 	add    r14d,0xdeadbeef
 1bc:	41 31 fe             	xor    r14d,edi
 1bf:	44 89 f7             	mov    edi,r14d
 1c2:	c1 ef 1a             	shr    edi,0x1a
 1c5:	4c 89 45 f8          	mov    QWORD PTR [rbp-0x8],r8
 1c9:	45 89 f0             	mov    r8d,r14d
 1cc:	41 c1 e0 06          	shl    r8d,0x6
 1d0:	41 09 f8             	or     r8d,edi
 1d3:	41 31 d5             	xor    r13d,edx
 1d6:	81 c2 b9 79 37 9e    	add    edx,0x9e3779b9
 1dc:	01 d1                	add    ecx,edx
 1de:	44 29 f2             	sub    edx,r14d
 1e1:	44 31 c2             	xor    edx,r8d
 1e4:	89 d7                	mov    edi,edx
 1e6:	c1 ef 18             	shr    edi,0x18
 1e9:	41 89 d0             	mov    r8d,edx
 1ec:	41 c1 e0 08          	shl    r8d,0x8
 1f0:	41 09 f8             	or     r8d,edi
 1f3:	41 01 ce             	add    r14d,ecx
 1f6:	29 d1                	sub    ecx,edx
 1f8:	44 31 c1             	xor    ecx,r8d
 1fb:	44 89 ef             	mov    edi,r13d
 1fe:	c1 ef 19             	shr    edi,0x19
 201:	41 c1 e5 07          	shl    r13d,0x7
 205:	41 09 fd             	or     r13d,edi
 208:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 20c:	c1 e7 18             	shl    edi,0x18
 20f:	09 c7                	or     edi,eax
 211:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
 215:	44 88 7e 00          	mov    BYTE PTR [rsi+0x0],r15b
 219:	49 c1 ef 08          	shr    r15,0x8
 21d:	44 88 7e 01          	mov    BYTE PTR [rsi+0x1],r15b
 221:	89 cf                	mov    edi,ecx
 223:	c1 ef 10             	shr    edi,0x10
 226:	41 89 c8             	mov    r8d,ecx
 229:	41 c1 e0 10          	shl    r8d,0x10
 22d:	41 09 f8             	or     r8d,edi
 230:	c1 eb 10             	shr    ebx,0x10
 233:	88 5e 02             	mov    BYTE PTR [rsi+0x2],bl
 236:	44 01 f2             	add    edx,r14d
 239:	41 29 ce             	sub    r14d,ecx
 23c:	45 31 c6             	xor    r14d,r8d
 23f:	44 89 f7             	mov    edi,r14d
 242:	c1 ef 0d             	shr    edi,0xd
 245:	45 89 f0             	mov    r8d,r14d
 248:	41 c1 e0 13          	shl    r8d,0x13
 24c:	41 09 f8             	or     r8d,edi
 24f:	01 d1                	add    ecx,edx
 251:	44 29 f2             	sub    edx,r14d
 254:	44 31 c2             	xor    edx,r8d
 257:	41 01 ce             	add    r14d,ecx
 25a:	44 89 f0             	mov    eax,r14d
 25d:	8b 7d f0             	mov    edi,DWORD PTR [rbp-0x10]
 260:	01 f8                	add    eax,edi
 262:	01 d0                	add    eax,edx
 264:	41 89 c0             	mov    r8d,eax
 267:	41 c1 e8 12          	shr    r8d,0x12
 26b:	89 c7                	mov    edi,eax
 26d:	c1 e7 0e             	shl    edi,0xe
 270:	44 09 c7             	or     edi,r8d
 273:	41 89 d0             	mov    r8d,edx
 276:	41 c1 e8 1c          	shr    r8d,0x1c
 27a:	29 d1                	sub    ecx,edx
 27c:	c1 e2 04             	shl    edx,0x4
 27f:	44 09 c2             	or     edx,r8d
 282:	31 d1                	xor    ecx,edx
 284:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
 288:	01 d1                	add    ecx,edx
 28a:	45 01 ee             	add    r14d,r13d
 28d:	31 c1                	xor    ecx,eax
 28f:	29 f9                	sub    ecx,edi
 291:	89 cf                	mov    edi,ecx
 293:	c1 ef 15             	shr    edi,0x15
 296:	41 89 c8             	mov    r8d,ecx
 299:	41 c1 e0 0b          	shl    r8d,0xb
 29d:	41 09 f8             	or     r8d,edi
 2a0:	89 ca                	mov    edx,ecx
 2a2:	44 31 f2             	xor    edx,r14d
 2a5:	44 29 c2             	sub    edx,r8d
 2a8:	89 d7                	mov    edi,edx
 2aa:	c1 ef 07             	shr    edi,0x7
 2ad:	89 d3                	mov    ebx,edx
 2af:	c1 e3 19             	shl    ebx,0x19
 2b2:	09 fb                	or     ebx,edi
 2b4:	41 89 d0             	mov    r8d,edx
 2b7:	41 31 c0             	xor    r8d,eax
 2ba:	41 29 d8             	sub    r8d,ebx
 2bd:	44 89 c7             	mov    edi,r8d
 2c0:	c1 ef 10             	shr    edi,0x10
 2c3:	44 89 c3             	mov    ebx,r8d
 2c6:	c1 e3 10             	shl    ebx,0x10
 2c9:	09 fb                	or     ebx,edi
 2cb:	44 89 c0             	mov    eax,r8d
 2ce:	31 c8                	xor    eax,ecx
 2d0:	29 d8                	sub    eax,ebx
 2d2:	89 c7                	mov    edi,eax
 2d4:	c1 ef 1c             	shr    edi,0x1c
 2d7:	89 c1                	mov    ecx,eax
 2d9:	c1 e1 04             	shl    ecx,0x4
 2dc:	09 f9                	or     ecx,edi
 2de:	89 c7                	mov    edi,eax
 2e0:	31 d7                	xor    edi,edx
 2e2:	29 cf                	sub    edi,ecx
 2e4:	89 fa                	mov    edx,edi
 2e6:	c1 ea 12             	shr    edx,0x12
 2e9:	89 f9                	mov    ecx,edi
 2eb:	c1 e1 0e             	shl    ecx,0xe
 2ee:	09 d1                	or     ecx,edx
 2f0:	44 31 c7             	xor    edi,r8d
 2f3:	29 cf                	sub    edi,ecx
 2f5:	89 fa                	mov    edx,edi
 2f7:	c1 ea 08             	shr    edx,0x8
 2fa:	89 f9                	mov    ecx,edi
 2fc:	c1 e1 18             	shl    ecx,0x18
 2ff:	09 d1                	or     ecx,edx
 301:	31 c7                	xor    edi,eax
 303:	29 cf                	sub    edi,ecx
 305:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 309:	48 89 fa             	mov    rdx,rdi
 30c:	48 c1 ea 18          	shr    rdx,0x18
 310:	88 56 07             	mov    BYTE PTR [rsi+0x7],dl
 313:	48 89 fa             	mov    rdx,rdi
 316:	48 c1 ea 10          	shr    rdx,0x10
 31a:	88 56 06             	mov    BYTE PTR [rsi+0x6],dl
 31d:	48 c1 ef 08          	shr    rdi,0x8
 321:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 325:	b8 02 00 00 00       	mov    eax,0x2
 32a:	41 5f                	pop    r15
 32c:	41 5e                	pop    r14
 32e:	41 5d                	pop    r13
 330:	5b                   	pop    rbx
 331:	c9                   	leave
 332:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
