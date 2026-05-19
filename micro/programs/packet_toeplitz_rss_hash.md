# packet_toeplitz_rss_hash

## Original C
```c
#include "common.h"

#define PACKET_TOEPLITZ_RSS_INPUT_SIZE 54U
#define PACKET_TOEPLITZ_TUPLE_BITS 104U

static __always_inline u8 packet_toeplitz_key_byte(u32 index)
{
    switch (index) {
    case 0U: return 0x6DU;
    case 1U: return 0x5AU;
    case 2U: return 0x56U;
    case 3U: return 0xDAU;
    case 4U: return 0x25U;
    case 5U: return 0x5BU;
    case 6U: return 0x0EU;
    case 7U: return 0xC2U;
    case 8U: return 0x41U;
    case 9U: return 0x67U;
    case 10U: return 0x25U;
    case 11U: return 0x3DU;
    case 12U: return 0x43U;
    case 13U: return 0xA3U;
    case 14U: return 0x8FU;
    case 15U: return 0xB0U;
    case 16U: return 0xD0U;
    default: return 0U;
    }
}

static __always_inline u32 packet_toeplitz_word(u32 bit)
{
    u32 byte = bit >> 3U;
    u32 shift = bit & 7U;
    u32 word = ((u32)packet_toeplitz_key_byte(byte) << 24U) |
               ((u32)packet_toeplitz_key_byte(byte + 1U) << 16U) |
               ((u32)packet_toeplitz_key_byte(byte + 2U) << 8U) |
               (u32)packet_toeplitz_key_byte(byte + 3U);

    if (shift != 0U) {
        word = (word << shift) |
               ((u32)packet_toeplitz_key_byte(byte + 4U) >> (8U - shift));
    }
    return word;
}

static __always_inline u8
packet_toeplitz_tuple_byte(const u8 *data, u32 ip, u32 tcp, u32 index)
{
    if (index < 4U) {
        return data[ip + 12U + index];
    }
    if (index < 8U) {
        return data[ip + 16U + (index - 4U)];
    }
    if (index < 10U) {
        return data[tcp + (index - 8U)];
    }
    if (index < 12U) {
        return data[tcp + 2U + (index - 10U)];
    }
    return data[ip + 9U];
}

static __always_inline int
bench_packet_toeplitz_rss_hash(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, PACKET_TOEPLITZ_RSS_INPUT_SIZE)) {
        return -1;
    }
    if (micro_read_u16_be(data, 12U) != 0x0800U) {
        return -1;
    }

    u32 ip = 14U;
    u8 ihl = (data[ip] & 0x0FU) * 4U;
    if (ihl != 20U || data[ip + 9U] != 6U) {
        return -1;
    }
    u32 tcp = ip + ihl;
    if (!micro_has_bytes(len, tcp, 20U)) {
        return -1;
    }

    u32 hash = 0U;
    for (u32 bit = 0; bit < PACKET_TOEPLITZ_TUPLE_BITS; bit++) {
        u8 tuple = packet_toeplitz_tuple_byte(data, ip, tcp, bit >> 3U);
        if ((tuple & (0x80U >> (bit & 7U))) != 0U) {
            hash ^= packet_toeplitz_word(bit);
        }
    }

    u32 src = micro_read_u32_be(data, ip + 12U);
    u32 dst = micro_read_u32_be(data, ip + 16U);
    u16 sport = micro_read_u16_be(data, tcp);
    u16 dport = micro_read_u16_be(data, tcp + 2U);
    u64 acc = ((u64)hash << 32U) | (hash ^ src ^ dst);
    acc ^= micro_rotl64(((u64)sport << 48U) | ((u64)dport << 32U) |
                            ((u64)src ^ dst),
                        (hash & 7U) + 1U);

    *out = acc;
    return 0;
}

DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(
    packet_toeplitz_rss_hash_xdp,
    bench_packet_toeplitz_rss_hash,
    PACKET_TOEPLITZ_RSS_INPUT_SIZE)
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

0000000000001100 <packet_toeplitz_rss_hash_xdp>:
    1100:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ce             	cmp    rsi,rcx
    110c:	76 01                	jbe    110f <packet_toeplitz_rss_hash_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 56 08          	lea    rdx,[rsi+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <packet_toeplitz_rss_hash_xdp+0xe>
    1118:	48 8d 56 3e          	lea    rdx,[rsi+0x3e]
    111c:	48 39 ca             	cmp    rdx,rcx
    111f:	77 ed                	ja     110e <packet_toeplitz_rss_hash_xdp+0xe>
    1121:	0f b7 4e 14          	movzx  ecx,WORD PTR [rsi+0x14]
    1125:	66 c1 c1 08          	rol    cx,0x8
    1129:	0f b7 c9             	movzx  ecx,cx
    112c:	81 f9 00 08 00 00    	cmp    ecx,0x800
    1132:	75 da                	jne    110e <packet_toeplitz_rss_hash_xdp+0xe>
    1134:	0f b6 4e 16          	movzx  ecx,BYTE PTR [rsi+0x16]
    1138:	80 e1 0f             	and    cl,0xf
    113b:	80 f9 05             	cmp    cl,0x5
    113e:	75 ce                	jne    110e <packet_toeplitz_rss_hash_xdp+0xe>
    1140:	80 7e 1f 06          	cmp    BYTE PTR [rsi+0x1f],0x6
    1144:	75 c8                	jne    110e <packet_toeplitz_rss_hash_xdp+0xe>
    1146:	48 8d 7e 1f          	lea    rdi,[rsi+0x1f]
    114a:	4c 8d 46 22          	lea    r8,[rsi+0x22]
    114e:	31 c0                	xor    eax,eax
    1150:	45 31 c9             	xor    r9d,r9d
    1153:	eb 27                	jmp    117c <packet_toeplitz_rss_hash_xdp+0x7c>
    1155:	41 bb c2 00 00 00    	mov    r11d,0xc2
    115b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1160:	b2 08                	mov    dl,0x8
    1162:	28 ca                	sub    dl,cl
    1164:	89 d1                	mov    ecx,edx
    1166:	41 d3 eb             	shr    r11d,cl
    1169:	45 09 da             	or     r10d,r11d
    116c:	44 31 d0             	xor    eax,r10d
    116f:	41 ff c1             	inc    r9d
    1172:	41 83 f9 68          	cmp    r9d,0x68
    1176:	0f 84 0d 02 00 00    	je     1389 <packet_toeplitz_rss_hash_xdp+0x289>
    117c:	44 89 ca             	mov    edx,r9d
    117f:	c1 ea 03             	shr    edx,0x3
    1182:	41 83 f9 1f          	cmp    r9d,0x1f
    1186:	76 18                	jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0>
    1188:	41 83 f9 3f          	cmp    r9d,0x3f
    118c:	76 12                	jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0>
    118e:	41 83 f9 4f          	cmp    r9d,0x4f
    1192:	76 0c                	jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0>
    1194:	48 89 f9             	mov    rcx,rdi
    1197:	41 83 f9 5f          	cmp    r9d,0x5f
    119b:	77 08                	ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5>
    119d:	0f 1f 00             	nop    DWORD PTR [rax]
    11a0:	89 d1                	mov    ecx,edx
    11a2:	4c 01 c1             	add    rcx,r8
    11a5:	44 0f b6 11          	movzx  r10d,BYTE PTR [rcx]
    11a9:	44 89 c9             	mov    ecx,r9d
    11ac:	83 e1 07             	and    ecx,0x7
    11af:	41 d3 e2             	shl    r10d,cl
    11b2:	45 84 d2             	test   r10b,r10b
    11b5:	79 b8                	jns    116f <packet_toeplitz_rss_hash_xdp+0x6f>
    11b7:	83 fa 05             	cmp    edx,0x5
    11ba:	7e 24                	jle    11e0 <packet_toeplitz_rss_hash_xdp+0xe0>
    11bc:	83 fa 08             	cmp    edx,0x8
    11bf:	7e 42                	jle    1203 <packet_toeplitz_rss_hash_xdp+0x103>
    11c1:	83 fa 0a             	cmp    edx,0xa
    11c4:	7f 77                	jg     123d <packet_toeplitz_rss_hash_xdp+0x13d>
    11c6:	83 fa 09             	cmp    edx,0x9
    11c9:	0f 85 b9 00 00 00    	jne    1288 <packet_toeplitz_rss_hash_xdp+0x188>
    11cf:	41 bb 43 00 00 00    	mov    r11d,0x43
    11d5:	41 ba 00 3d 25 67    	mov    r10d,0x67253d00
    11db:	e9 e0 00 00 00       	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    11e0:	83 fa 02             	cmp    edx,0x2
    11e3:	7f 39                	jg     121e <packet_toeplitz_rss_hash_xdp+0x11e>
    11e5:	85 d2                	test   edx,edx
    11e7:	74 75                	je     125e <packet_toeplitz_rss_hash_xdp+0x15e>
    11e9:	83 fa 01             	cmp    edx,0x1
    11ec:	0f 85 b2 00 00 00    	jne    12a4 <packet_toeplitz_rss_hash_xdp+0x1a4>
    11f2:	41 bb 25 00 00 00    	mov    r11d,0x25
    11f8:	41 ba 00 da 56 5a    	mov    r10d,0x5a56da00
    11fe:	e9 bd 00 00 00       	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    1203:	83 fa 06             	cmp    edx,0x6
    1206:	74 48                	je     1250 <packet_toeplitz_rss_hash_xdp+0x150>
    1208:	83 fa 07             	cmp    edx,0x7
    120b:	75 6d                	jne    127a <packet_toeplitz_rss_hash_xdp+0x17a>
    120d:	41 bb 25 00 00 00    	mov    r11d,0x25
    1213:	41 ba 00 67 41 c2    	mov    r10d,0xc2416700
    1219:	e9 a2 00 00 00       	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    121e:	83 fa 03             	cmp    edx,0x3
    1221:	74 49                	je     126c <packet_toeplitz_rss_hash_xdp+0x16c>
    1223:	83 fa 04             	cmp    edx,0x4
    1226:	0f 85 86 00 00 00    	jne    12b2 <packet_toeplitz_rss_hash_xdp+0x1b2>
    122c:	41 bb c2 00 00 00    	mov    r11d,0xc2
    1232:	41 ba 00 0e 5b 25    	mov    r10d,0x255b0e00
    1238:	e9 83 00 00 00       	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    123d:	83 fa 0b             	cmp    edx,0xb
    1240:	75 54                	jne    1296 <packet_toeplitz_rss_hash_xdp+0x196>
    1242:	41 bb 8f 00 00 00    	mov    r11d,0x8f
    1248:	41 ba 00 a3 43 3d    	mov    r10d,0x3d43a300
    124e:	eb 70                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    1250:	41 bb 67 00 00 00    	mov    r11d,0x67
    1256:	41 ba 00 41 c2 0e    	mov    r10d,0xec24100
    125c:	eb 62                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    125e:	41 bb da 00 00 00    	mov    r11d,0xda
    1264:	41 ba 00 56 5a 6d    	mov    r10d,0x6d5a5600
    126a:	eb 54                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    126c:	41 bb 0e 00 00 00    	mov    r11d,0xe
    1272:	41 ba 00 5b 25 da    	mov    r10d,0xda255b00
    1278:	eb 46                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    127a:	41 bb 3d 00 00 00    	mov    r11d,0x3d
    1280:	41 ba 00 25 67 41    	mov    r10d,0x41672500
    1286:	eb 38                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    1288:	41 bb a3 00 00 00    	mov    r11d,0xa3
    128e:	41 ba 00 43 3d 25    	mov    r10d,0x253d4300
    1294:	eb 2a                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    1296:	41 bb b0 00 00 00    	mov    r11d,0xb0
    129c:	41 ba 00 8f a3 43    	mov    r10d,0x43a38f00
    12a2:	eb 1c                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    12a4:	41 bb 5b 00 00 00    	mov    r11d,0x5b
    12aa:	41 ba 00 25 da 56    	mov    r10d,0x56da2500
    12b0:	eb 0e                	jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0>
    12b2:	41 bb 41 00 00 00    	mov    r11d,0x41
    12b8:	41 ba 00 c2 0e 5b    	mov    r10d,0x5b0ec200
    12be:	66 90                	xchg   ax,ax
    12c0:	45 09 da             	or     r10d,r11d
    12c3:	85 c9                	test   ecx,ecx
    12c5:	0f 84 a1 fe ff ff    	je     116c <packet_toeplitz_rss_hash_xdp+0x6c>
    12cb:	41 d3 e2             	shl    r10d,cl
    12ce:	41 bb 25 00 00 00    	mov    r11d,0x25
    12d4:	83 fa 05             	cmp    edx,0x5
    12d7:	7e 1a                	jle    12f3 <packet_toeplitz_rss_hash_xdp+0x1f3>
    12d9:	83 fa 08             	cmp    edx,0x8
    12dc:	7e 32                	jle    1310 <packet_toeplitz_rss_hash_xdp+0x210>
    12de:	83 fa 0a             	cmp    edx,0xa
    12e1:	7f 5f                	jg     1342 <packet_toeplitz_rss_hash_xdp+0x242>
    12e3:	83 fa 09             	cmp    edx,0x9
    12e6:	75 75                	jne    135d <packet_toeplitz_rss_hash_xdp+0x25d>
    12e8:	41 bb a3 00 00 00    	mov    r11d,0xa3
    12ee:	e9 6d fe ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    12f3:	83 fa 02             	cmp    edx,0x2
    12f6:	7f 31                	jg     1329 <packet_toeplitz_rss_hash_xdp+0x229>
    12f8:	85 d2                	test   edx,edx
    12fa:	0f 84 60 fe ff ff    	je     1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1300:	83 fa 01             	cmp    edx,0x1
    1303:	75 6e                	jne    1373 <packet_toeplitz_rss_hash_xdp+0x273>
    1305:	41 bb 5b 00 00 00    	mov    r11d,0x5b
    130b:	e9 50 fe ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1310:	83 fa 06             	cmp    edx,0x6
    1313:	0f 84 47 fe ff ff    	je     1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1319:	83 fa 07             	cmp    edx,0x7
    131c:	75 34                	jne    1352 <packet_toeplitz_rss_hash_xdp+0x252>
    131e:	41 bb 3d 00 00 00    	mov    r11d,0x3d
    1324:	e9 37 fe ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1329:	83 fa 03             	cmp    edx,0x3
    132c:	0f 84 23 fe ff ff    	je     1155 <packet_toeplitz_rss_hash_xdp+0x55>
    1332:	83 fa 04             	cmp    edx,0x4
    1335:	75 47                	jne    137e <packet_toeplitz_rss_hash_xdp+0x27e>
    1337:	41 bb 41 00 00 00    	mov    r11d,0x41
    133d:	e9 1e fe ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1342:	83 fa 0b             	cmp    edx,0xb
    1345:	75 21                	jne    1368 <packet_toeplitz_rss_hash_xdp+0x268>
    1347:	41 bb b0 00 00 00    	mov    r11d,0xb0
    134d:	e9 0e fe ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1352:	41 bb 43 00 00 00    	mov    r11d,0x43
    1358:	e9 03 fe ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    135d:	41 bb 8f 00 00 00    	mov    r11d,0x8f
    1363:	e9 f8 fd ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1368:	41 bb d0 00 00 00    	mov    r11d,0xd0
    136e:	e9 ed fd ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1373:	41 bb 0e 00 00 00    	mov    r11d,0xe
    1379:	e9 e2 fd ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    137e:	41 bb 67 00 00 00    	mov    r11d,0x67
    1384:	e9 d7 fd ff ff       	jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60>
    1389:	8b 56 26             	mov    edx,DWORD PTR [rsi+0x26]
    138c:	0f b6 4e 2a          	movzx  ecx,BYTE PTR [rsi+0x2a]
    1390:	44 0f b6 46 2b       	movzx  r8d,BYTE PTR [rsi+0x2b]
    1395:	44 0f b6 4e 2c       	movzx  r9d,BYTE PTR [rsi+0x2c]
    139a:	44 0f b6 56 2d       	movzx  r10d,BYTE PTR [rsi+0x2d]
    139f:	49 89 c3             	mov    r11,rax
    13a2:	49 c1 e3 20          	shl    r11,0x20
    13a6:	33 56 22             	xor    edx,DWORD PTR [rsi+0x22]
    13a9:	0f ca                	bswap  edx
    13ab:	89 d7                	mov    edi,edx
    13ad:	31 c7                	xor    edi,eax
    13af:	4c 09 df             	or     rdi,r11
    13b2:	48 c1 e1 38          	shl    rcx,0x38
    13b6:	49 c1 e0 30          	shl    r8,0x30
    13ba:	49 09 c8             	or     r8,rcx
    13bd:	49 c1 e1 28          	shl    r9,0x28
    13c1:	4d 09 c1             	or     r9,r8
    13c4:	49 c1 e2 20          	shl    r10,0x20
    13c8:	4c 09 ca             	or     rdx,r9
    13cb:	4c 09 d2             	or     rdx,r10
    13ce:	83 e0 07             	and    eax,0x7
    13d1:	8d 48 01             	lea    ecx,[rax+0x1]
    13d4:	49 89 d0             	mov    r8,rdx
    13d7:	49 d3 e0             	shl    r8,cl
    13da:	f6 d0                	not    al
    13dc:	89 c1                	mov    ecx,eax
    13de:	48 d3 ea             	shr    rdx,cl
    13e1:	4c 09 c2             	or     rdx,r8
    13e4:	48 31 fa             	xor    rdx,rdi
    13e7:	48 89 16             	mov    QWORD PTR [rsi],rdx
    13ea:	b8 02 00 00 00       	mov    eax,0x2
    13ef:	c3                   	ret

Disassembly of section .fini:

00000000000013f0 <_fini>:
    13f0:	f3 0f 1e fa          	endbr64
    13f4:	48 83 ec 08          	sub    rsp,0x8
    13f8:	48 83 c4 08          	add    rsp,0x8
    13fc:	c3                   	ret
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
  11:	31 c0                	xor    eax,eax
  13:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  17:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  1b:	48 39 f7             	cmp    rdi,rsi
  1e:	0f 87 b2 03 00 00    	ja     0x3d6
  24:	48 89 fa             	mov    rdx,rdi
  27:	48 83 c2 08          	add    rdx,0x8
  2b:	48 39 f2             	cmp    rdx,rsi
  2e:	0f 87 a2 03 00 00    	ja     0x3d6
  34:	48 89 fa             	mov    rdx,rdi
  37:	48 83 c2 3e          	add    rdx,0x3e
  3b:	48 39 f2             	cmp    rdx,rsi
  3e:	0f 87 92 03 00 00    	ja     0x3d6
  44:	48 0f b6 77 15       	movzx  rsi,BYTE PTR [rdi+0x15]
  49:	48 0f b6 57 14       	movzx  rdx,BYTE PTR [rdi+0x14]
  4e:	c1 e2 08             	shl    edx,0x8
  51:	09 f2                	or     edx,esi
  53:	81 e2 ff ff 00 00    	and    edx,0xffff
  59:	81 fa 00 08 00 00    	cmp    edx,0x800
  5f:	0f 85 71 03 00 00    	jne    0x3d6
  65:	48 0f b6 77 16       	movzx  rsi,BYTE PTR [rdi+0x16]
  6a:	83 e6 0f             	and    esi,0xf
  6d:	83 fe 05             	cmp    esi,0x5
  70:	0f 85 60 03 00 00    	jne    0x3d6
  76:	48 0f b6 77 1f       	movzx  rsi,BYTE PTR [rdi+0x1f]
  7b:	83 fe 06             	cmp    esi,0x6
  7e:	0f 85 52 03 00 00    	jne    0x3d6
  84:	48 89 fa             	mov    rdx,rdi
  87:	48 83 c2 1f          	add    rdx,0x1f
  8b:	31 f6                	xor    esi,esi
  8d:	48 89 f9             	mov    rcx,rdi
  90:	48 83 c1 22          	add    rcx,0x22
  94:	45 31 c0             	xor    r8d,r8d
  97:	eb 29                	jmp    0xc2
  99:	41 bd c2 00 00 00    	mov    r13d,0xc2
  9f:	bb 08 00 00 00       	mov    ebx,0x8
  a4:	29 c3                	sub    ebx,eax
  a6:	c4 42 63 f7 ed       	shrx   r13d,r13d,ebx
  ab:	45 09 f5             	or     r13d,r14d
  ae:	41 31 f5             	xor    r13d,esi
  b1:	44 89 ee             	mov    esi,r13d
  b4:	41 83 c0 01          	add    r8d,0x1
  b8:	41 83 f8 68          	cmp    r8d,0x68
  bc:	0f 84 19 02 00 00    	je     0x2db
  c2:	44 89 c3             	mov    ebx,r8d
  c5:	c1 eb 03             	shr    ebx,0x3
  c8:	41 83 f8 1f          	cmp    r8d,0x1f
  cc:	77 02                	ja     0xd0
  ce:	eb 19                	jmp    0xe9
  d0:	41 83 f8 3f          	cmp    r8d,0x3f
  d4:	77 02                	ja     0xd8
  d6:	eb 11                	jmp    0xe9
  d8:	41 83 f8 4f          	cmp    r8d,0x4f
  dc:	77 02                	ja     0xe0
  de:	eb 09                	jmp    0xe9
  e0:	49 89 d5             	mov    r13,rdx
  e3:	41 83 f8 5f          	cmp    r8d,0x5f
  e7:	77 06                	ja     0xef
  e9:	49 89 cd             	mov    r13,rcx
  ec:	49 01 dd             	add    r13,rbx
  ef:	44 89 c0             	mov    eax,r8d
  f2:	83 e0 07             	and    eax,0x7
  f5:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
  fa:	c4 42 79 f7 ed       	shlx   r13d,r13d,eax
  ff:	41 81 e5 80 00 00 00 	and    r13d,0x80
 106:	45 85 ed             	test   r13d,r13d
 109:	74 a9                	je     0xb4
 10b:	83 fb 05             	cmp    ebx,0x5
 10e:	7f 33                	jg     0x143
 110:	83 fb 02             	cmp    ebx,0x2
 113:	7f 69                	jg     0x17e
 115:	41 bd da 00 00 00    	mov    r13d,0xda
 11b:	41 be 00 56 5a 6d    	mov    r14d,0x6d5a5600
 121:	85 db                	test   ebx,ebx
 123:	0f 84 e0 00 00 00    	je     0x209
 129:	83 fb 01             	cmp    ebx,0x1
 12c:	0f 84 bd 00 00 00    	je     0x1ef
 132:	41 bd 5b 00 00 00    	mov    r13d,0x5b
 138:	41 be 00 25 da 56    	mov    r14d,0x56da2500
 13e:	e9 c6 00 00 00       	jmp    0x209
 143:	83 fb 08             	cmp    ebx,0x8
 146:	7f 1b                	jg     0x163
 148:	83 fb 06             	cmp    ebx,0x6
 14b:	74 5c                	je     0x1a9
 14d:	83 fb 07             	cmp    ebx,0x7
 150:	74 73                	je     0x1c5
 152:	41 bd 3d 00 00 00    	mov    r13d,0x3d
 158:	41 be 00 25 67 41    	mov    r14d,0x41672500
 15e:	e9 a6 00 00 00       	jmp    0x209
 163:	83 fb 0a             	cmp    ebx,0xa
 166:	7f 2e                	jg     0x196
 168:	83 fb 09             	cmp    ebx,0x9
 16b:	74 66                	je     0x1d3
 16d:	41 bd a3 00 00 00    	mov    r13d,0xa3
 173:	41 be 00 43 3d 25    	mov    r14d,0x253d4300
 179:	e9 8b 00 00 00       	jmp    0x209
 17e:	83 fb 03             	cmp    ebx,0x3
 181:	74 34                	je     0x1b7
 183:	83 fb 04             	cmp    ebx,0x4
 186:	74 75                	je     0x1fd
 188:	41 bd 41 00 00 00    	mov    r13d,0x41
 18e:	41 be 00 c2 0e 5b    	mov    r14d,0x5b0ec200
 194:	eb 73                	jmp    0x209
 196:	83 fb 0b             	cmp    ebx,0xb
 199:	74 46                	je     0x1e1
 19b:	41 bd b0 00 00 00    	mov    r13d,0xb0
 1a1:	41 be 00 8f a3 43    	mov    r14d,0x43a38f00
 1a7:	eb 60                	jmp    0x209
 1a9:	41 bd 67 00 00 00    	mov    r13d,0x67
 1af:	41 be 00 41 c2 0e    	mov    r14d,0xec24100
 1b5:	eb 52                	jmp    0x209
 1b7:	41 bd 0e 00 00 00    	mov    r13d,0xe
 1bd:	41 be 00 5b 25 da    	mov    r14d,0xda255b00
 1c3:	eb 44                	jmp    0x209
 1c5:	41 bd 25 00 00 00    	mov    r13d,0x25
 1cb:	41 be 00 67 41 c2    	mov    r14d,0xc2416700
 1d1:	eb 36                	jmp    0x209
 1d3:	41 bd 43 00 00 00    	mov    r13d,0x43
 1d9:	41 be 00 3d 25 67    	mov    r14d,0x67253d00
 1df:	eb 28                	jmp    0x209
 1e1:	41 bd 8f 00 00 00    	mov    r13d,0x8f
 1e7:	41 be 00 a3 43 3d    	mov    r14d,0x3d43a300
 1ed:	eb 1a                	jmp    0x209
 1ef:	41 bd 25 00 00 00    	mov    r13d,0x25
 1f5:	41 be 00 da 56 5a    	mov    r14d,0x5a56da00
 1fb:	eb 0c                	jmp    0x209
 1fd:	41 bd c2 00 00 00    	mov    r13d,0xc2
 203:	41 be 00 0e 5b 25    	mov    r14d,0x255b0e00
 209:	45 09 f5             	or     r13d,r14d
 20c:	85 c0                	test   eax,eax
 20e:	0f 84 9a fe ff ff    	je     0xae
 214:	45 89 ee             	mov    r14d,r13d
 217:	c4 42 79 f7 f6       	shlx   r14d,r14d,eax
 21c:	41 bd 25 00 00 00    	mov    r13d,0x25
 222:	83 fb 05             	cmp    ebx,0x5
 225:	7f 21                	jg     0x248
 227:	83 fb 02             	cmp    ebx,0x2
 22a:	7f 4f                	jg     0x27b
 22c:	85 db                	test   ebx,ebx
 22e:	0f 84 6b fe ff ff    	je     0x9f
 234:	83 fb 01             	cmp    ebx,0x1
 237:	0f 84 88 00 00 00    	je     0x2c5
 23d:	41 bd 0e 00 00 00    	mov    r13d,0xe
 243:	e9 57 fe ff ff       	jmp    0x9f
 248:	83 fb 08             	cmp    ebx,0x8
 24b:	7f 19                	jg     0x266
 24d:	83 fb 06             	cmp    ebx,0x6
 250:	0f 84 49 fe ff ff    	je     0x9f
 256:	83 fb 07             	cmp    ebx,0x7
 259:	74 49                	je     0x2a4
 25b:	41 bd 43 00 00 00    	mov    r13d,0x43
 261:	e9 39 fe ff ff       	jmp    0x9f
 266:	83 fb 0a             	cmp    ebx,0xa
 269:	7f 29                	jg     0x294
 26b:	83 fb 09             	cmp    ebx,0x9
 26e:	74 3f                	je     0x2af
 270:	41 bd 8f 00 00 00    	mov    r13d,0x8f
 276:	e9 24 fe ff ff       	jmp    0x9f
 27b:	83 fb 03             	cmp    ebx,0x3
 27e:	0f 84 15 fe ff ff    	je     0x99
 284:	83 fb 04             	cmp    ebx,0x4
 287:	74 47                	je     0x2d0
 289:	41 bd 67 00 00 00    	mov    r13d,0x67
 28f:	e9 0b fe ff ff       	jmp    0x9f
 294:	83 fb 0b             	cmp    ebx,0xb
 297:	74 21                	je     0x2ba
 299:	41 bd d0 00 00 00    	mov    r13d,0xd0
 29f:	e9 fb fd ff ff       	jmp    0x9f
 2a4:	41 bd 3d 00 00 00    	mov    r13d,0x3d
 2aa:	e9 f0 fd ff ff       	jmp    0x9f
 2af:	41 bd a3 00 00 00    	mov    r13d,0xa3
 2b5:	e9 e5 fd ff ff       	jmp    0x9f
 2ba:	41 bd b0 00 00 00    	mov    r13d,0xb0
 2c0:	e9 da fd ff ff       	jmp    0x9f
 2c5:	41 bd 5b 00 00 00    	mov    r13d,0x5b
 2cb:	e9 cf fd ff ff       	jmp    0x9f
 2d0:	41 bd 41 00 00 00    	mov    r13d,0x41
 2d6:	e9 c4 fd ff ff       	jmp    0x9f
 2db:	48 0f b6 4f 22       	movzx  rcx,BYTE PTR [rdi+0x22]
 2e0:	c1 e1 18             	shl    ecx,0x18
 2e3:	48 0f b6 57 23       	movzx  rdx,BYTE PTR [rdi+0x23]
 2e8:	c1 e2 10             	shl    edx,0x10
 2eb:	09 ca                	or     edx,ecx
 2ed:	48 0f b6 4f 24       	movzx  rcx,BYTE PTR [rdi+0x24]
 2f2:	c1 e1 08             	shl    ecx,0x8
 2f5:	09 ca                	or     edx,ecx
 2f7:	48 0f b6 4f 25       	movzx  rcx,BYTE PTR [rdi+0x25]
 2fc:	09 ca                	or     edx,ecx
 2fe:	4c 0f b6 47 26       	movzx  r8,BYTE PTR [rdi+0x26]
 303:	41 c1 e0 18          	shl    r8d,0x18
 307:	48 0f b6 4f 27       	movzx  rcx,BYTE PTR [rdi+0x27]
 30c:	c1 e1 10             	shl    ecx,0x10
 30f:	44 09 c1             	or     ecx,r8d
 312:	4c 0f b6 47 28       	movzx  r8,BYTE PTR [rdi+0x28]
 317:	41 c1 e0 08          	shl    r8d,0x8
 31b:	44 09 c1             	or     ecx,r8d
 31e:	4c 0f b6 47 29       	movzx  r8,BYTE PTR [rdi+0x29]
 323:	44 09 c1             	or     ecx,r8d
 326:	31 d1                	xor    ecx,edx
 328:	4c 0f b6 47 2a       	movzx  r8,BYTE PTR [rdi+0x2a]
 32d:	49 c1 e0 38          	shl    r8,0x38
 331:	48 0f b6 57 2b       	movzx  rdx,BYTE PTR [rdi+0x2b]
 336:	48 c1 e2 30          	shl    rdx,0x30
 33a:	4c 09 c2             	or     rdx,r8
 33d:	4c 0f b6 47 2c       	movzx  r8,BYTE PTR [rdi+0x2c]
 342:	49 c1 e0 28          	shl    r8,0x28
 346:	4c 09 c2             	or     rdx,r8
 349:	48 09 ca             	or     rdx,rcx
 34c:	4c 0f b6 47 2d       	movzx  r8,BYTE PTR [rdi+0x2d]
 351:	49 c1 e0 20          	shl    r8,0x20
 355:	4c 09 c2             	or     rdx,r8
 358:	41 89 f0             	mov    r8d,esi
 35b:	41 83 e0 07          	and    r8d,0x7
 35f:	44 89 c0             	mov    eax,r8d
 362:	83 c0 01             	add    eax,0x1
 365:	41 83 f0 3f          	xor    r8d,0x3f
 369:	48 89 d3             	mov    rbx,rdx
 36c:	c4 e2 bb f7 db       	shrx   rbx,rbx,r8
 371:	c4 e2 f9 f7 d2       	shlx   rdx,rdx,rax
 376:	48 09 da             	or     rdx,rbx
 379:	31 f1                	xor    ecx,esi
 37b:	48 c1 e6 20          	shl    rsi,0x20
 37f:	48 09 ce             	or     rsi,rcx
 382:	48 31 f2             	xor    rdx,rsi
 385:	88 57 00             	mov    BYTE PTR [rdi+0x0],dl
 388:	48 89 d6             	mov    rsi,rdx
 38b:	48 c1 ee 38          	shr    rsi,0x38
 38f:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 393:	48 89 d6             	mov    rsi,rdx
 396:	48 c1 ee 30          	shr    rsi,0x30
 39a:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 39e:	48 89 d6             	mov    rsi,rdx
 3a1:	48 c1 ee 28          	shr    rsi,0x28
 3a5:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 3a9:	48 89 d6             	mov    rsi,rdx
 3ac:	48 c1 ee 20          	shr    rsi,0x20
 3b0:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 3b4:	48 89 d6             	mov    rsi,rdx
 3b7:	48 c1 ee 18          	shr    rsi,0x18
 3bb:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 3bf:	48 89 d6             	mov    rsi,rdx
 3c2:	48 c1 ee 10          	shr    rsi,0x10
 3c6:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 3ca:	48 c1 ea 08          	shr    rdx,0x8
 3ce:	88 57 01             	mov    BYTE PTR [rdi+0x1],dl
 3d1:	b8 02 00 00 00       	mov    eax,0x2
 3d6:	41 5e                	pop    r14
 3d8:	41 5d                	pop    r13
 3da:	5b                   	pop    rbx
 3db:	c9                   	leave
 3dc:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
