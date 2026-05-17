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
  1e:	0f 87 13 04 00 00    	ja     0x437
  24:	48 89 fa             	mov    rdx,rdi
  27:	48 83 c2 08          	add    rdx,0x8
  2b:	48 39 f2             	cmp    rdx,rsi
  2e:	0f 87 03 04 00 00    	ja     0x437
  34:	48 89 fa             	mov    rdx,rdi
  37:	48 83 c2 3e          	add    rdx,0x3e
  3b:	48 39 f2             	cmp    rdx,rsi
  3e:	0f 87 f3 03 00 00    	ja     0x437
  44:	48 0f b6 77 15       	movzx  rsi,BYTE PTR [rdi+0x15]
  49:	48 0f b6 57 14       	movzx  rdx,BYTE PTR [rdi+0x14]
  4e:	48 c1 e2 08          	shl    rdx,0x8
  52:	48 09 f2             	or     rdx,rsi
  55:	48 81 e2 ff ff 00 00 	and    rdx,0xffff
  5c:	48 81 fa 00 08 00 00 	cmp    rdx,0x800
  63:	0f 85 ce 03 00 00    	jne    0x437
  69:	48 0f b6 77 16       	movzx  rsi,BYTE PTR [rdi+0x16]
  6e:	48 83 e6 0f          	and    rsi,0xf
  72:	48 83 fe 05          	cmp    rsi,0x5
  76:	0f 85 bb 03 00 00    	jne    0x437
  7c:	48 0f b6 77 1f       	movzx  rsi,BYTE PTR [rdi+0x1f]
  81:	48 83 fe 06          	cmp    rsi,0x6
  85:	0f 85 ac 03 00 00    	jne    0x437
  8b:	48 89 fa             	mov    rdx,rdi
  8e:	48 83 c2 1f          	add    rdx,0x1f
  92:	31 f6                	xor    esi,esi
  94:	48 89 f9             	mov    rcx,rdi
  97:	48 83 c1 22          	add    rcx,0x22
  9b:	45 31 c0             	xor    r8d,r8d
  9e:	eb 35                	jmp    0xd5
  a0:	41 bd c2 00 00 00    	mov    r13d,0xc2
  a6:	bb 08 00 00 00       	mov    ebx,0x8
  ab:	48 29 c3             	sub    rbx,rax
  ae:	c4 42 e3 f7 ed       	shrx   r13,r13,rbx
  b3:	4d 09 f5             	or     r13,r14
  b6:	49 31 f5             	xor    r13,rsi
  b9:	4c 89 ee             	mov    rsi,r13
  bc:	49 83 c0 01          	add    r8,0x1
  c0:	4c 89 c0             	mov    rax,r8
  c3:	48 c1 e0 20          	shl    rax,0x20
  c7:	48 c1 e8 20          	shr    rax,0x20
  cb:	48 83 f8 68          	cmp    rax,0x68
  cf:	0f 84 4a 02 00 00    	je     0x31f
  d5:	4c 89 c0             	mov    rax,r8
  d8:	48 c1 e0 20          	shl    rax,0x20
  dc:	48 c1 e8 20          	shr    rax,0x20
  e0:	48 89 c3             	mov    rbx,rax
  e3:	48 c1 eb 03          	shr    rbx,0x3
  e7:	48 83 f8 1f          	cmp    rax,0x1f
  eb:	77 02                	ja     0xef
  ed:	eb 24                	jmp    0x113
  ef:	48 83 f8 3f          	cmp    rax,0x3f
  f3:	77 02                	ja     0xf7
  f5:	eb 1c                	jmp    0x113
  f7:	4c 89 c0             	mov    rax,r8
  fa:	48 c1 e0 20          	shl    rax,0x20
  fe:	48 c1 e8 20          	shr    rax,0x20
 102:	48 83 f8 4f          	cmp    rax,0x4f
 106:	77 02                	ja     0x10a
 108:	eb 09                	jmp    0x113
 10a:	49 89 d5             	mov    r13,rdx
 10d:	48 83 f8 5f          	cmp    rax,0x5f
 111:	77 06                	ja     0x119
 113:	49 89 cd             	mov    r13,rcx
 116:	49 01 dd             	add    r13,rbx
 119:	4c 89 c0             	mov    rax,r8
 11c:	48 83 e0 07          	and    rax,0x7
 120:	4d 0f b6 6d 00       	movzx  r13,BYTE PTR [r13+0x0]
 125:	c4 42 f9 f7 ed       	shlx   r13,r13,rax
 12a:	49 81 e5 80 00 00 00 	and    r13,0x80
 131:	4d 85 ed             	test   r13,r13
 134:	74 86                	je     0xbc
 136:	48 83 fb 05          	cmp    rbx,0x5
 13a:	7f 36                	jg     0x172
 13c:	48 83 fb 02          	cmp    rbx,0x2
 140:	7f 70                	jg     0x1b2
 142:	41 bd da 00 00 00    	mov    r13d,0xda
 148:	41 be 00 56 5a 6d    	mov    r14d,0x6d5a5600
 14e:	48 85 db             	test   rbx,rbx
 151:	0f 84 e9 00 00 00    	je     0x240
 157:	48 83 fb 01          	cmp    rbx,0x1
 15b:	0f 84 c5 00 00 00    	je     0x226
 161:	41 bd 5b 00 00 00    	mov    r13d,0x5b
 167:	41 be 00 25 da 56    	mov    r14d,0x56da2500
 16d:	e9 ce 00 00 00       	jmp    0x240
 172:	48 83 fb 08          	cmp    rbx,0x8
 176:	7f 1d                	jg     0x195
 178:	48 83 fb 06          	cmp    rbx,0x6
 17c:	74 62                	je     0x1e0
 17e:	48 83 fb 07          	cmp    rbx,0x7
 182:	74 78                	je     0x1fc
 184:	41 bd 3d 00 00 00    	mov    r13d,0x3d
 18a:	41 be 00 25 67 41    	mov    r14d,0x41672500
 190:	e9 ab 00 00 00       	jmp    0x240
 195:	48 83 fb 0a          	cmp    rbx,0xa
 199:	7f 31                	jg     0x1cc
 19b:	48 83 fb 09          	cmp    rbx,0x9
 19f:	74 69                	je     0x20a
 1a1:	41 bd a3 00 00 00    	mov    r13d,0xa3
 1a7:	41 be 00 43 3d 25    	mov    r14d,0x253d4300
 1ad:	e9 8e 00 00 00       	jmp    0x240
 1b2:	48 83 fb 03          	cmp    rbx,0x3
 1b6:	74 36                	je     0x1ee
 1b8:	48 83 fb 04          	cmp    rbx,0x4
 1bc:	74 76                	je     0x234
 1be:	41 bd 41 00 00 00    	mov    r13d,0x41
 1c4:	41 be 00 c2 0e 5b    	mov    r14d,0x5b0ec200
 1ca:	eb 74                	jmp    0x240
 1cc:	48 83 fb 0b          	cmp    rbx,0xb
 1d0:	74 46                	je     0x218
 1d2:	41 bd b0 00 00 00    	mov    r13d,0xb0
 1d8:	41 be 00 8f a3 43    	mov    r14d,0x43a38f00
 1de:	eb 60                	jmp    0x240
 1e0:	41 bd 67 00 00 00    	mov    r13d,0x67
 1e6:	41 be 00 41 c2 0e    	mov    r14d,0xec24100
 1ec:	eb 52                	jmp    0x240
 1ee:	41 bd 0e 00 00 00    	mov    r13d,0xe
 1f4:	41 be 00 5b 25 da    	mov    r14d,0xda255b00
 1fa:	eb 44                	jmp    0x240
 1fc:	41 bd 25 00 00 00    	mov    r13d,0x25
 202:	41 be 00 67 41 c2    	mov    r14d,0xc2416700
 208:	eb 36                	jmp    0x240
 20a:	41 bd 43 00 00 00    	mov    r13d,0x43
 210:	41 be 00 3d 25 67    	mov    r14d,0x67253d00
 216:	eb 28                	jmp    0x240
 218:	41 bd 8f 00 00 00    	mov    r13d,0x8f
 21e:	41 be 00 a3 43 3d    	mov    r14d,0x3d43a300
 224:	eb 1a                	jmp    0x240
 226:	41 bd 25 00 00 00    	mov    r13d,0x25
 22c:	41 be 00 da 56 5a    	mov    r14d,0x5a56da00
 232:	eb 0c                	jmp    0x240
 234:	41 bd c2 00 00 00    	mov    r13d,0xc2
 23a:	41 be 00 0e 5b 25    	mov    r14d,0x255b0e00
 240:	4d 09 f5             	or     r13,r14
 243:	48 85 c0             	test   rax,rax
 246:	0f 84 6a fe ff ff    	je     0xb6
 24c:	4d 89 ee             	mov    r14,r13
 24f:	c4 42 f9 f7 f6       	shlx   r14,r14,rax
 254:	41 bd 25 00 00 00    	mov    r13d,0x25
 25a:	48 83 fb 05          	cmp    rbx,0x5
 25e:	7f 24                	jg     0x284
 260:	48 83 fb 02          	cmp    rbx,0x2
 264:	7f 56                	jg     0x2bc
 266:	48 85 db             	test   rbx,rbx
 269:	0f 84 37 fe ff ff    	je     0xa6
 26f:	48 83 fb 01          	cmp    rbx,0x1
 273:	0f 84 90 00 00 00    	je     0x309
 279:	41 bd 0e 00 00 00    	mov    r13d,0xe
 27f:	e9 22 fe ff ff       	jmp    0xa6
 284:	48 83 fb 08          	cmp    rbx,0x8
 288:	7f 1b                	jg     0x2a5
 28a:	48 83 fb 06          	cmp    rbx,0x6
 28e:	0f 84 12 fe ff ff    	je     0xa6
 294:	48 83 fb 07          	cmp    rbx,0x7
 298:	74 4e                	je     0x2e8
 29a:	41 bd 43 00 00 00    	mov    r13d,0x43
 2a0:	e9 01 fe ff ff       	jmp    0xa6
 2a5:	48 83 fb 0a          	cmp    rbx,0xa
 2a9:	7f 2c                	jg     0x2d7
 2ab:	48 83 fb 09          	cmp    rbx,0x9
 2af:	74 42                	je     0x2f3
 2b1:	41 bd 8f 00 00 00    	mov    r13d,0x8f
 2b7:	e9 ea fd ff ff       	jmp    0xa6
 2bc:	48 83 fb 03          	cmp    rbx,0x3
 2c0:	0f 84 da fd ff ff    	je     0xa0
 2c6:	48 83 fb 04          	cmp    rbx,0x4
 2ca:	74 48                	je     0x314
 2cc:	41 bd 67 00 00 00    	mov    r13d,0x67
 2d2:	e9 cf fd ff ff       	jmp    0xa6
 2d7:	48 83 fb 0b          	cmp    rbx,0xb
 2db:	74 21                	je     0x2fe
 2dd:	41 bd d0 00 00 00    	mov    r13d,0xd0
 2e3:	e9 be fd ff ff       	jmp    0xa6
 2e8:	41 bd 3d 00 00 00    	mov    r13d,0x3d
 2ee:	e9 b3 fd ff ff       	jmp    0xa6
 2f3:	41 bd a3 00 00 00    	mov    r13d,0xa3
 2f9:	e9 a8 fd ff ff       	jmp    0xa6
 2fe:	41 bd b0 00 00 00    	mov    r13d,0xb0
 304:	e9 9d fd ff ff       	jmp    0xa6
 309:	41 bd 5b 00 00 00    	mov    r13d,0x5b
 30f:	e9 92 fd ff ff       	jmp    0xa6
 314:	41 bd 41 00 00 00    	mov    r13d,0x41
 31a:	e9 87 fd ff ff       	jmp    0xa6
 31f:	48 0f b6 4f 22       	movzx  rcx,BYTE PTR [rdi+0x22]
 324:	48 c1 e1 18          	shl    rcx,0x18
 328:	48 0f b6 57 23       	movzx  rdx,BYTE PTR [rdi+0x23]
 32d:	48 c1 e2 10          	shl    rdx,0x10
 331:	48 09 ca             	or     rdx,rcx
 334:	48 0f b6 4f 24       	movzx  rcx,BYTE PTR [rdi+0x24]
 339:	48 c1 e1 08          	shl    rcx,0x8
 33d:	48 09 ca             	or     rdx,rcx
 340:	48 0f b6 4f 25       	movzx  rcx,BYTE PTR [rdi+0x25]
 345:	48 09 ca             	or     rdx,rcx
 348:	4c 0f b6 47 26       	movzx  r8,BYTE PTR [rdi+0x26]
 34d:	49 c1 e0 18          	shl    r8,0x18
 351:	48 0f b6 4f 27       	movzx  rcx,BYTE PTR [rdi+0x27]
 356:	48 c1 e1 10          	shl    rcx,0x10
 35a:	4c 09 c1             	or     rcx,r8
 35d:	4c 0f b6 47 28       	movzx  r8,BYTE PTR [rdi+0x28]
 362:	49 c1 e0 08          	shl    r8,0x8
 366:	4c 09 c1             	or     rcx,r8
 369:	4c 0f b6 47 29       	movzx  r8,BYTE PTR [rdi+0x29]
 36e:	4c 09 c1             	or     rcx,r8
 371:	48 31 d1             	xor    rcx,rdx
 374:	4c 0f b6 47 2a       	movzx  r8,BYTE PTR [rdi+0x2a]
 379:	49 c1 e0 38          	shl    r8,0x38
 37d:	48 0f b6 57 2b       	movzx  rdx,BYTE PTR [rdi+0x2b]
 382:	48 c1 e2 30          	shl    rdx,0x30
 386:	4c 09 c2             	or     rdx,r8
 389:	4c 0f b6 47 2c       	movzx  r8,BYTE PTR [rdi+0x2c]
 38e:	49 c1 e0 28          	shl    r8,0x28
 392:	4c 09 c2             	or     rdx,r8
 395:	49 89 c8             	mov    r8,rcx
 398:	49 c1 e0 20          	shl    r8,0x20
 39c:	49 c1 e8 20          	shr    r8,0x20
 3a0:	4c 09 c2             	or     rdx,r8
 3a3:	4c 0f b6 47 2d       	movzx  r8,BYTE PTR [rdi+0x2d]
 3a8:	49 c1 e0 20          	shl    r8,0x20
 3ac:	4c 09 c2             	or     rdx,r8
 3af:	49 89 f0             	mov    r8,rsi
 3b2:	49 83 e0 07          	and    r8,0x7
 3b6:	4c 89 c0             	mov    rax,r8
 3b9:	48 83 c0 01          	add    rax,0x1
 3bd:	49 83 f0 3f          	xor    r8,0x3f
 3c1:	48 89 d3             	mov    rbx,rdx
 3c4:	c4 e2 bb f7 db       	shrx   rbx,rbx,r8
 3c9:	c4 e2 f9 f7 d2       	shlx   rdx,rdx,rax
 3ce:	48 09 da             	or     rdx,rbx
 3d1:	48 31 f1             	xor    rcx,rsi
 3d4:	48 c1 e6 20          	shl    rsi,0x20
 3d8:	48 c1 e1 20          	shl    rcx,0x20
 3dc:	48 c1 e9 20          	shr    rcx,0x20
 3e0:	48 09 ce             	or     rsi,rcx
 3e3:	48 31 f2             	xor    rdx,rsi
 3e6:	48 89 d6             	mov    rsi,rdx
 3e9:	48 c1 ee 38          	shr    rsi,0x38
 3ed:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 3f1:	48 89 d6             	mov    rsi,rdx
 3f4:	48 c1 ee 30          	shr    rsi,0x30
 3f8:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 3fc:	48 89 d6             	mov    rsi,rdx
 3ff:	48 c1 ee 28          	shr    rsi,0x28
 403:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 407:	48 89 d6             	mov    rsi,rdx
 40a:	48 c1 ee 20          	shr    rsi,0x20
 40e:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 412:	48 89 d6             	mov    rsi,rdx
 415:	48 c1 ee 18          	shr    rsi,0x18
 419:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 41d:	48 89 d6             	mov    rsi,rdx
 420:	48 c1 ee 10          	shr    rsi,0x10
 424:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 428:	88 57 00             	mov    BYTE PTR [rdi+0x0],dl
 42b:	48 c1 ea 08          	shr    rdx,0x8
 42f:	88 57 01             	mov    BYTE PTR [rdi+0x1],dl
 432:	b8 02 00 00 00       	mov    eax,0x2
 437:	41 5e                	pop    r14
 439:	41 5d                	pop    r13
 43b:	5b                   	pop    rbx
 43c:	c9                   	leave
 43d:	c3                   	ret
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
   d:	0f 87 3a 03 00 00    	ja     0x34d
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 2d 03 00 00    	ja     0x34d
  20:	48 8d 71 3e          	lea    rsi,[rcx+0x3e]
  24:	48 39 d6             	cmp    rsi,rdx
  27:	0f 87 20 03 00 00    	ja     0x34d
  2d:	66 0f 38 f0 41 14    	movbe  ax,WORD PTR [rcx+0x14]
  33:	0f b7 c0             	movzx  eax,ax
  36:	3d 00 08 00 00       	cmp    eax,0x800
  3b:	75 40                	jne    0x7d
  3d:	0f b6 41 16          	movzx  eax,BYTE PTR [rcx+0x16]
  41:	24 0f                	and    al,0xf
  43:	3c 05                	cmp    al,0x5
  45:	75 36                	jne    0x7d
  47:	80 79 1f 06          	cmp    BYTE PTR [rcx+0x1f],0x6
  4b:	75 30                	jne    0x7d
  4d:	55                   	push   rbp
  4e:	41 57                	push   r15
  50:	41 56                	push   r14
  52:	41 55                	push   r13
  54:	41 54                	push   r12
  56:	53                   	push   rbx
  57:	48 8d 71 1f          	lea    rsi,[rcx+0x1f]
  5b:	48 8d 79 22          	lea    rdi,[rcx+0x22]
  5f:	31 c0                	xor    eax,eax
  61:	41 be 3d 00 00 00    	mov    r14d,0x3d
  67:	41 bf 25 00 00 00    	mov    r15d,0x25
  6d:	41 bc 41 00 00 00    	mov    r12d,0x41
  73:	41 bd c2 00 00 00    	mov    r13d,0xc2
  79:	31 d2                	xor    edx,edx
  7b:	eb 3a                	jmp    0xb7
  7d:	31 c0                	xor    eax,eax
  7f:	c3                   	ret
  80:	49 83 f8 04          	cmp    r8,0x4
  84:	bb 67 00 00 00       	mov    ebx,0x67
  89:	49 0f 44 dc          	cmove  rbx,r12
  8d:	49 83 f8 03          	cmp    r8,0x3
  91:	49 0f 44 dd          	cmove  rbx,r13
  95:	c4 42 d1 f7 c2       	shlx   r8,r10,rbp
  9a:	41 b1 08             	mov    r9b,0x8
  9d:	41 28 e9             	sub    r9b,bpl
  a0:	c4 62 b3 f7 d3       	shrx   r10,rbx,r9
  a5:	4d 09 c2             	or     r10,r8
  a8:	4c 31 d0             	xor    rax,r10
  ab:	48 ff c2             	inc    rdx
  ae:	83 fa 68             	cmp    edx,0x68
  b1:	0f 84 22 02 00 00    	je     0x2d9
  b7:	41 89 d1             	mov    r9d,edx
  ba:	41 89 d0             	mov    r8d,edx
  bd:	41 c1 e8 03          	shr    r8d,0x3
  c1:	4e 8d 14 07          	lea    r10,[rdi+r8*1]
  c5:	49 83 f9 60          	cmp    r9,0x60
  c9:	4c 0f 43 d6          	cmovae r10,rsi
  cd:	89 d5                	mov    ebp,edx
  cf:	83 e5 07             	and    ebp,0x7
  d2:	45 0f b6 12          	movzx  r10d,BYTE PTR [r10]
  d6:	c4 42 d1 f7 d2       	shlx   r10,r10,rbp
  db:	45 84 d2             	test   r10b,r10b
  de:	79 cb                	jns    0xab
  e0:	41 83 f9 2f          	cmp    r9d,0x2f
  e4:	76 4a                	jbe    0x130
  e6:	41 83 f9 47          	cmp    r9d,0x47
  ea:	76 7c                	jbe    0x168
  ec:	41 83 f9 57          	cmp    r9d,0x57
  f0:	0f 86 ba 00 00 00    	jbe    0x1b0
  f6:	49 83 f8 0b          	cmp    r8,0xb
  fa:	41 ba b0 00 00 00    	mov    r10d,0xb0
 100:	bb 8f 00 00 00       	mov    ebx,0x8f
 105:	4c 0f 44 d3          	cmove  r10,rbx
 109:	41 83 f8 0b          	cmp    r8d,0xb
 10d:	bb 00 8f a3 43       	mov    ebx,0x43a38f00
 112:	41 bb 00 a3 43 3d    	mov    r11d,0x3d43a300
 118:	49 0f 44 db          	cmove  rbx,r11
 11c:	e9 1f 01 00 00       	jmp    0x240
 121:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 128:	0f 1f 84 00 00 00 00 
 12f:	00 
 130:	41 83 f9 17          	cmp    r9d,0x17
 134:	76 64                	jbe    0x19a
 136:	45 89 c2             	mov    r10d,r8d
 139:	41 80 e2 07          	and    r10b,0x7
 13d:	41 80 fa 03          	cmp    r10b,0x3
 141:	0f 84 b5 00 00 00    	je     0x1fc
 147:	45 89 c2             	mov    r10d,r8d
 14a:	41 83 e2 07          	and    r10d,0x7
 14e:	41 83 fa 04          	cmp    r10d,0x4
 152:	0f 85 c6 00 00 00    	jne    0x21e
 158:	bb 00 0e 5b 25       	mov    ebx,0x255b0e00
 15d:	41 ba c2 00 00 00    	mov    r10d,0xc2
 163:	e9 d8 00 00 00       	jmp    0x240
 168:	45 89 c2             	mov    r10d,r8d
 16b:	41 80 e2 0f          	and    r10b,0xf
 16f:	41 80 fa 06          	cmp    r10b,0x6
 173:	0f 84 98 00 00 00    	je     0x211
 179:	45 89 c2             	mov    r10d,r8d
 17c:	41 83 e2 0f          	and    r10d,0xf
 180:	41 83 fa 07          	cmp    r10d,0x7
 184:	0f 85 a1 00 00 00    	jne    0x22b
 18a:	41 ba 25 00 00 00    	mov    r10d,0x25
 190:	bb 00 67 41 c2       	mov    ebx,0xc2416700
 195:	e9 a6 00 00 00       	jmp    0x240
 19a:	41 83 f9 08          	cmp    r9d,0x8
 19e:	73 39                	jae    0x1d9
 1a0:	bb 00 56 5a 6d       	mov    ebx,0x6d5a5600
 1a5:	41 ba da 00 00 00    	mov    r10d,0xda
 1ab:	e9 90 00 00 00       	jmp    0x240
 1b0:	49 83 f8 09          	cmp    r8,0x9
 1b4:	41 ba a3 00 00 00    	mov    r10d,0xa3
 1ba:	41 bb 43 00 00 00    	mov    r11d,0x43
 1c0:	4d 0f 44 d3          	cmove  r10,r11
 1c4:	41 83 f8 09          	cmp    r8d,0x9
 1c8:	bb 00 43 3d 25       	mov    ebx,0x253d4300
 1cd:	41 bb 00 3d 25 67    	mov    r11d,0x67253d00
 1d3:	49 0f 44 db          	cmove  rbx,r11
 1d7:	eb 67                	jmp    0x240
 1d9:	49 83 f8 01          	cmp    r8,0x1
 1dd:	41 ba 5b 00 00 00    	mov    r10d,0x5b
 1e3:	4d 0f 44 d7          	cmove  r10,r15
 1e7:	41 83 f8 01          	cmp    r8d,0x1
 1eb:	bb 00 25 da 56       	mov    ebx,0x56da2500
 1f0:	41 bb 00 da 56 5a    	mov    r11d,0x5a56da00
 1f6:	49 0f 44 db          	cmove  rbx,r11
 1fa:	eb 44                	jmp    0x240
 1fc:	41 ba 00 67 41 c2    	mov    r10d,0xc2416700
 202:	49 8d 9a 00 f4 e3 17 	lea    rbx,[r10+0x17e3f400]
 209:	41 ba 0e 00 00 00    	mov    r10d,0xe
 20f:	eb 2f                	jmp    0x240
 211:	bb 00 41 c2 0e       	mov    ebx,0xec24100
 216:	41 ba 67 00 00 00    	mov    r10d,0x67
 21c:	eb 22                	jmp    0x240
 21e:	bb 00 c2 0e 5b       	mov    ebx,0x5b0ec200
 223:	41 ba 41 00 00 00    	mov    r10d,0x41
 229:	eb 15                	jmp    0x240
 22b:	bb 00 25 67 41       	mov    ebx,0x41672500
 230:	41 ba 3d 00 00 00    	mov    r10d,0x3d
 236:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
 23d:	00 00 00 
 240:	49 09 da             	or     r10,rbx
 243:	48 85 ed             	test   rbp,rbp
 246:	0f 84 5c fe ff ff    	je     0xa8
 24c:	41 83 f9 2f          	cmp    r9d,0x2f
 250:	76 24                	jbe    0x276
 252:	41 83 f9 47          	cmp    r9d,0x47
 256:	76 4f                	jbe    0x2a7
 258:	41 83 f9 57          	cmp    r9d,0x57
 25c:	76 63                	jbe    0x2c1
 25e:	31 db                	xor    ebx,ebx
 260:	41 83 f8 0b          	cmp    r8d,0xb
 264:	0f 95 c3             	setne  bl
 267:	c1 e3 05             	shl    ebx,0x5
 26a:	48 81 c3 b0 00 00 00 	add    rbx,0xb0
 271:	e9 1f fe ff ff       	jmp    0x95
 276:	41 83 f9 17          	cmp    r9d,0x17
 27a:	0f 87 00 fe ff ff    	ja     0x80
 280:	bb 25 00 00 00       	mov    ebx,0x25
 285:	41 83 f9 08          	cmp    r9d,0x8
 289:	0f 82 06 fe ff ff    	jb     0x95
 28f:	41 83 f8 01          	cmp    r8d,0x1
 293:	bb 0e 00 00 00       	mov    ebx,0xe
 298:	41 b8 5b 00 00 00    	mov    r8d,0x5b
 29e:	49 0f 44 d8          	cmove  rbx,r8
 2a2:	e9 ee fd ff ff       	jmp    0x95
 2a7:	49 83 f8 07          	cmp    r8,0x7
 2ab:	bb 43 00 00 00       	mov    ebx,0x43
 2b0:	49 0f 44 de          	cmove  rbx,r14
 2b4:	49 83 f8 06          	cmp    r8,0x6
 2b8:	49 0f 44 df          	cmove  rbx,r15
 2bc:	e9 d4 fd ff ff       	jmp    0x95
 2c1:	41 83 f8 09          	cmp    r8d,0x9
 2c5:	bb 8f 00 00 00       	mov    ebx,0x8f
 2ca:	41 b8 a3 00 00 00    	mov    r8d,0xa3
 2d0:	49 0f 44 d8          	cmove  rbx,r8
 2d4:	e9 bc fd ff ff       	jmp    0x95
 2d9:	8b 51 26             	mov    edx,DWORD PTR [rcx+0x26]
 2dc:	33 51 22             	xor    edx,DWORD PTR [rcx+0x22]
 2df:	0f ca                	bswap  edx
 2e1:	0f b6 71 2a          	movzx  esi,BYTE PTR [rcx+0x2a]
 2e5:	48 c1 e6 38          	shl    rsi,0x38
 2e9:	0f b6 79 2b          	movzx  edi,BYTE PTR [rcx+0x2b]
 2ed:	48 c1 e7 30          	shl    rdi,0x30
 2f1:	48 09 f7             	or     rdi,rsi
 2f4:	0f b6 71 2c          	movzx  esi,BYTE PTR [rcx+0x2c]
 2f8:	48 c1 e6 28          	shl    rsi,0x28
 2fc:	48 09 fe             	or     rsi,rdi
 2ff:	0f b6 79 2d          	movzx  edi,BYTE PTR [rcx+0x2d]
 303:	48 c1 e7 20          	shl    rdi,0x20
 307:	48 09 f7             	or     rdi,rsi
 30a:	48 09 d7             	or     rdi,rdx
 30d:	89 c6                	mov    esi,eax
 30f:	40 80 e6 07          	and    sil,0x7
 313:	41 89 f0             	mov    r8d,esi
 316:	41 f6 d0             	not    r8b
 319:	c4 62 bb f7 c7       	shrx   r8,rdi,r8
 31e:	40 fe c6             	inc    sil
 321:	c4 e2 c9 f7 f7       	shlx   rsi,rdi,rsi
 326:	4c 09 c6             	or     rsi,r8
 329:	48 89 c7             	mov    rdi,rax
 32c:	48 c1 e7 20          	shl    rdi,0x20
 330:	89 c0                	mov    eax,eax
 332:	48 31 d0             	xor    rax,rdx
 335:	48 09 f8             	or     rax,rdi
 338:	48 31 f0             	xor    rax,rsi
 33b:	48 89 01             	mov    QWORD PTR [rcx],rax
 33e:	b8 02 00 00 00       	mov    eax,0x2
 343:	5b                   	pop    rbx
 344:	41 5c                	pop    r12
 346:	41 5d                	pop    r13
 348:	41 5e                	pop    r14
 34a:	41 5f                	pop    r15
 34c:	5d                   	pop    rbp
 34d:	c3                   	ret
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
    /* 0x1100: mov    rsi,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rsi,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110c: jbe    110f <packet_toeplitz_rss_hash_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_2, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-3) - 1, 0),
    /* 0x1118: lea    rdx,[rsi+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111c: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x111f: ja     110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-6) - 1, 0),
    /* 0x1121: movzx  ecx,WORD PTR [rsi+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1125: rol    cx,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1129: movzx  ecx,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x112c: cmp    ecx,0x800 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1132: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_4, 0, (-13) - 1, 2048),
    /* 0x1134: movzx  ecx,BYTE PTR [rsi+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1138: and    cl,0xf [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 15), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x113b: cmp    cl,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x113e: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_4),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 5),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-24) - 1),
    /* 0x1140: cmp    BYTE PTR [rsi+0x1f],0x6 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1144: jne    110e <packet_toeplitz_rss_hash_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_2, 31),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 6),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-32) - 1),
    /* 0x1146: lea    rdi,[rsi+0x1f] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 31), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114a: lea    r8,[rsi+0x22] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 34), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x114e: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1150: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1153: jmp    117c <packet_toeplitz_rss_hash_xdp+0x7c> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (25) - 1),
    /* 0x1155: mov    r11d,0xc2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 194), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x115b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: mov    dl,0x8 [exact-kinsn: movb immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 8), MICRO_HANDCRAFT_BPF_X86_MOVB),
    /* 0x1162: sub    dl,cl [exact-kinsn: sub8 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SUBB),
    /* 0x1164: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1166: shr    r11d,cl [exact-kinsn: shr32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1169: or     r10d,r11d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x116c: xor    eax,r10d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x116f: inc    r9d [exact-kinsn: incl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x1172: cmp    r9d,0x68 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1176: je     1389 <packet_toeplitz_rss_hash_xdp+0x289> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 104),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (187) - 1),
    /* 0x117c: mov    edx,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x117f: shr    edx,0x3 [exact-kinsn: shr32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 3), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1182: cmp    r9d,0x1f [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x1186: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, 2, 31),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (27) - 1),
    /* 0x1188: cmp    r9d,0x3f [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x118c: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, 2, 63),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (19) - 1),
    /* 0x118e: cmp    r9d,0x4f [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x1192: jbe    11a0 <packet_toeplitz_rss_hash_xdp+0xa0> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_6, 0, 2, 79),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (11) - 1),
    /* 0x1194: mov    rcx,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1197: cmp    r9d,0x5f [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x119b: ja     11a5 <packet_toeplitz_rss_hash_xdp+0xa5> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_6, 0, 2, 95),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (5) - 1),
    /* 0x119d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a2: add    rcx,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11a5: movzx  r10d,BYTE PTR [rcx] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11a9: mov    ecx,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ac: and    ecx,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x11af: shl    r10d,cl [exact-kinsn: shl32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11b2: test   r10b,r10b [absorbed-control-flow: test folded into following ordinary BPF jns] */
    /* 0x11b5: jns    116f <packet_toeplitz_rss_hash_xdp+0x6f> [exact-bpf: jns ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 128),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-66) - 1),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x11b7: cmp    edx,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF jle] */
    /* 0x11ba: jle    11e0 <packet_toeplitz_rss_hash_xdp+0xe0> [exact-bpf: jle ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_3, 0, (9) - 1, 5),
    /* 0x11bc: cmp    edx,0x8 [absorbed-control-flow: cmp folded into following ordinary BPF jle] */
    /* 0x11bf: jle    1203 <packet_toeplitz_rss_hash_xdp+0x103> [exact-bpf: jle ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_3, 0, (17) - 1, 8),
    /* 0x11c1: cmp    edx,0xa [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11c4: jg     123d <packet_toeplitz_rss_hash_xdp+0x13d> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_3, 0, (30) - 1, 10),
    /* 0x11c6: cmp    edx,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11c9: jne    1288 <packet_toeplitz_rss_hash_xdp+0x188> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (55) - 1, 9),
    /* 0x11cf: mov    r11d,0x43 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 67), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11d5: mov    r10d,0x67253d00 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1730493696), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11db: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (69) - 1),
    /* 0x11e0: cmp    edx,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x11e3: jg     121e <packet_toeplitz_rss_hash_xdp+0x11e> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_3, 0, (16) - 1, 2),
    /* 0x11e5: test   edx,edx [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x11e7: je     125e <packet_toeplitz_rss_hash_xdp+0x15e> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_3, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (32) - 1),
    /* 0x11e9: cmp    edx,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11ec: jne    12a4 <packet_toeplitz_rss_hash_xdp+0x1a4> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (56) - 1, 1),
    /* 0x11f2: mov    r11d,0x25 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f8: mov    r10d,0x5a56da00 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1515641344), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11fe: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (60) - 1),
    /* 0x1203: cmp    edx,0x6 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1206: je     1250 <packet_toeplitz_rss_hash_xdp+0x150> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_3, 0, (20) - 1, 6),
    /* 0x1208: cmp    edx,0x7 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x120b: jne    127a <packet_toeplitz_rss_hash_xdp+0x17a> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (34) - 1, 7),
    /* 0x120d: mov    r11d,0x25 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1213: mov    r10d,0xc2416700 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 3259066112), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1219: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (53) - 1),
    /* 0x121e: cmp    edx,0x3 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1221: je     126c <packet_toeplitz_rss_hash_xdp+0x16c> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_3, 0, (23) - 1, 3),
    /* 0x1223: cmp    edx,0x4 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1226: jne    12b2 <packet_toeplitz_rss_hash_xdp+0x1b2> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (47) - 1, 4),
    /* 0x122c: mov    r11d,0xc2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 194), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1232: mov    r10d,0x255b0e00 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 626724352), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1238: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (46) - 1),
    /* 0x123d: cmp    edx,0xb [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1240: jne    1296 <packet_toeplitz_rss_hash_xdp+0x196> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (31) - 1, 11),
    /* 0x1242: mov    r11d,0x8f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 143), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1248: mov    r10d,0x3d43a300 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1027842816), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124e: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (40) - 1),
    /* 0x1250: mov    r11d,0x67 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 103), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1256: mov    r10d,0xec24100 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 247611648), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x125c: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (35) - 1),
    /* 0x125e: mov    r11d,0xda [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 218), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1264: mov    r10d,0x6d5a5600 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1834636800), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x126a: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (30) - 1),
    /* 0x126c: mov    r11d,0xe [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1272: mov    r10d,0xda255b00 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 3659881216), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1278: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (25) - 1),
    /* 0x127a: mov    r11d,0x3d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 61), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1280: mov    r10d,0x41672500 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1097278720), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1286: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (20) - 1),
    /* 0x1288: mov    r11d,0xa3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 163), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x128e: mov    r10d,0x253d4300 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 624771840), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1294: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (15) - 1),
    /* 0x1296: mov    r11d,0xb0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 176), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x129c: mov    r10d,0x43a38f00 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1134792448), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12a2: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (10) - 1),
    /* 0x12a4: mov    r11d,0x5b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 91), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12aa: mov    r10d,0x56da2500 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1457136896), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b0: jmp    12c0 <packet_toeplitz_rss_hash_xdp+0x1c0> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (5) - 1),
    /* 0x12b2: mov    r11d,0x41 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 65), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12b8: mov    r10d,0x5b0ec200 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 1527693824), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12be: xchg   ax,ax [padding: xchg ax,ax is nop padding] */
    /* 0x12c0: or     r10d,r11d [exact-kinsn: or32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12c3: test   ecx,ecx [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x12c5: je     116c <packet_toeplitz_rss_hash_xdp+0x6c> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_4, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-150) - 1),
    /* 0x12cb: shl    r10d,cl [exact-kinsn: shl32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R10, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12ce: mov    r11d,0x25 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 37), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12d4: cmp    edx,0x5 [absorbed-control-flow: cmp folded into following ordinary BPF jle] */
    /* 0x12d7: jle    12f3 <packet_toeplitz_rss_hash_xdp+0x1f3> [exact-bpf: jle ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_3, 0, (7) - 1, 5),
    /* 0x12d9: cmp    edx,0x8 [absorbed-control-flow: cmp folded into following ordinary BPF jle] */
    /* 0x12dc: jle    1310 <packet_toeplitz_rss_hash_xdp+0x210> [exact-bpf: jle ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSLE | BPF_K, BPF_REG_3, 0, (13) - 1, 8),
    /* 0x12de: cmp    edx,0xa [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x12e1: jg     1342 <packet_toeplitz_rss_hash_xdp+0x242> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_3, 0, (22) - 1, 10),
    /* 0x12e3: cmp    edx,0x9 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x12e6: jne    135d <packet_toeplitz_rss_hash_xdp+0x25d> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (28) - 1, 9),
    /* 0x12e8: mov    r11d,0xa3 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 163), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12ee: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-171) - 1),
    /* 0x12f3: cmp    edx,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x12f6: jg     1329 <packet_toeplitz_rss_hash_xdp+0x229> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_3, 0, (12) - 1, 2),
    /* 0x12f8: test   edx,edx [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x12fa: je     1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_3, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-174) - 1),
    /* 0x1300: cmp    edx,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1303: jne    1373 <packet_toeplitz_rss_hash_xdp+0x273> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (27) - 1, 1),
    /* 0x1305: mov    r11d,0x5b [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 91), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x130b: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-178) - 1),
    /* 0x1310: cmp    edx,0x6 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1313: je     1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_3, 0, (-179) - 1, 6),
    /* 0x1319: cmp    edx,0x7 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x131c: jne    1352 <packet_toeplitz_rss_hash_xdp+0x252> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (13) - 1, 7),
    /* 0x131e: mov    r11d,0x3d [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 61), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1324: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-183) - 1),
    /* 0x1329: cmp    edx,0x3 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x132c: je     1155 <packet_toeplitz_rss_hash_xdp+0x55> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_3, 0, (-186) - 1, 3),
    /* 0x1332: cmp    edx,0x4 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1335: jne    137e <packet_toeplitz_rss_hash_xdp+0x27e> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (20) - 1, 4),
    /* 0x1337: mov    r11d,0x41 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 65), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x133d: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-188) - 1),
    /* 0x1342: cmp    edx,0xb [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1345: jne    1368 <packet_toeplitz_rss_hash_xdp+0x268> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_3, 0, (10) - 1, 11),
    /* 0x1347: mov    r11d,0xb0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 176), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x134d: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-192) - 1),
    /* 0x1352: mov    r11d,0x43 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 67), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1358: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-195) - 1),
    /* 0x135d: mov    r11d,0x8f [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 143), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1363: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-198) - 1),
    /* 0x1368: mov    r11d,0xd0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 208), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x136e: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-201) - 1),
    /* 0x1373: mov    r11d,0xe [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 14), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1379: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-204) - 1),
    /* 0x137e: mov    r11d,0x67 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R11, 103), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1384: jmp    1160 <packet_toeplitz_rss_hash_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-207) - 1),
    /* 0x1389: mov    edx,DWORD PTR [rsi+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 38), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x138c: movzx  ecx,BYTE PTR [rsi+0x2a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_4, BPF_REG_2, 42), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1390: movzx  r8d,BYTE PTR [rsi+0x2b] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_5, BPF_REG_2, 43), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1395: movzx  r9d,BYTE PTR [rsi+0x2c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R9, BPF_REG_2, 44), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x139a: movzx  r10d,BYTE PTR [rsi+0x2d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_R10, BPF_REG_2, 45), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x139f: mov    r11,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13a2: shl    r11,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R11, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13a6: xor    edx,DWORD PTR [rsi+0x22] [exact-kinsn: xor32 memory-source kinsn] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_2, 34), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13a9: bswap  edx [exact-kinsn: bswapl kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x13ab: mov    edi,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13ad: xor    edi,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x13af: or     rdi,r11 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_1, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13b2: shl    rcx,0x38 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 56), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13b6: shl    r8,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_5, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13ba: or     r8,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13bd: shl    r9,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R9, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c1: or     r9,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13c4: shl    r10,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R10, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13c8: or     rdx,r9 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13cb: or     rdx,r10 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13ce: and    eax,0x7 [exact-kinsn: and32 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x13d1: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x13d4: mov    r8,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13d7: shl    r8,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x13da: not    al [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x13dc: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13de: shr    rdx,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x13e1: or     rdx,r8 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x13e4: xor    rdx,rdi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x13e7: mov    QWORD PTR [rsi],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x13ea: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x13ef: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
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
   c:	48 81 ec e0 01 00 00 	sub    rsp,0x1e0
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	48 89 eb             	mov    rbx,rbp
  1d:	48 83 c3 80          	add    rbx,0xffffffffffffff80
  21:	48 89 9d 20 fe ff ff 	mov    QWORD PTR [rbp-0x1e0],rbx
  28:	31 db                	xor    ebx,ebx
  2a:	45 31 ed             	xor    r13d,r13d
  2d:	45 31 f6             	xor    r14d,r14d
  30:	45 31 ff             	xor    r15d,r15d
  33:	48 8b 77 00          	mov    rsi,QWORD PTR [rdi+0x0]
  37:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
  3b:	31 c0                	xor    eax,eax
  3d:	48 39 ce             	cmp    rsi,rcx
  40:	76 09                	jbe    0x4b
  42:	41 5f                	pop    r15
  44:	41 5e                	pop    r14
  46:	41 5d                	pop    r13
  48:	5b                   	pop    rbx
  49:	c9                   	leave
  4a:	c3                   	ret
  4b:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  4f:	48 39 ca             	cmp    rdx,rcx
  52:	77 ee                	ja     0x42
  54:	48 8d 56 3e          	lea    rdx,[rsi+0x3e]
  58:	48 39 ca             	cmp    rdx,rcx
  5b:	77 e5                	ja     0x42
  5d:	0f b7 4e 14          	movzx  ecx,WORD PTR [rsi+0x14]
  61:	66 c1 c1 08          	rol    cx,0x8
  65:	0f b7 c9             	movzx  ecx,cx
  68:	81 f9 00 08 00 00    	cmp    ecx,0x800
  6e:	75 d2                	jne    0x42
  70:	0f b6 4e 16          	movzx  ecx,BYTE PTR [rsi+0x16]
  74:	80 e1 0f             	and    cl,0xf
  77:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
  7e:	48 89 cb             	mov    rbx,rcx
  81:	48 83 fb 05          	cmp    rbx,0x5
  85:	75 09                	jne    0x90
  87:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
  8e:	eb 09                	jmp    0x99
  90:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
  97:	eb a9                	jmp    0x42
  99:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
  a0:	48 0f b6 5e 1f       	movzx  rbx,BYTE PTR [rsi+0x1f]
  a5:	48 81 e3 ff 00 00 00 	and    rbx,0xff
  ac:	83 fb 06             	cmp    ebx,0x6
  af:	75 09                	jne    0xba
  b1:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
  b8:	eb 0c                	jmp    0xc6
  ba:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
  c1:	e9 7c ff ff ff       	jmp    0x42
  c6:	48 8d 7e 1f          	lea    rdi,[rsi+0x1f]
  ca:	4c 8d 46 22          	lea    r8,[rsi+0x22]
  ce:	31 c0                	xor    eax,eax
  d0:	45 31 c9             	xor    r9d,r9d
  d3:	eb 3d                	jmp    0x112
  d5:	41 bb c2 00 00 00    	mov    r11d,0xc2
  db:	c6 c2 08             	mov    dl,0x8
  de:	28 ca                	sub    dl,cl
  e0:	89 d1                	mov    ecx,edx
  e2:	41 d3 eb             	shr    r11d,cl
  e5:	45 09 da             	or     r10d,r11d
  e8:	44 31 d0             	xor    eax,r10d
  eb:	41 ff c1             	inc    r9d
  ee:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
  f5:	44 89 cb             	mov    ebx,r9d
  f8:	83 fb 68             	cmp    ebx,0x68
  fb:	74 09                	je     0x106
  fd:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 104:	eb 0c                	jmp    0x112
 106:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 10d:	e9 b3 02 00 00       	jmp    0x3c5
 112:	44 89 ca             	mov    edx,r9d
 115:	c1 ea 03             	shr    edx,0x3
 118:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
 11f:	44 89 cb             	mov    ebx,r9d
 122:	83 fb 1f             	cmp    ebx,0x1f
 125:	76 09                	jbe    0x130
 127:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 12e:	eb 09                	jmp    0x139
 130:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 137:	eb 66                	jmp    0x19f
 139:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
 140:	44 89 cb             	mov    ebx,r9d
 143:	83 fb 3f             	cmp    ebx,0x3f
 146:	76 09                	jbe    0x151
 148:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 14f:	eb 09                	jmp    0x15a
 151:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 158:	eb 45                	jmp    0x19f
 15a:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
 161:	44 89 cb             	mov    ebx,r9d
 164:	83 fb 4f             	cmp    ebx,0x4f
 167:	76 09                	jbe    0x172
 169:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 170:	eb 09                	jmp    0x17b
 172:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 179:	eb 24                	jmp    0x19f
 17b:	48 89 f9             	mov    rcx,rdi
 17e:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
 185:	44 89 cb             	mov    ebx,r9d
 188:	83 fb 5f             	cmp    ebx,0x5f
 18b:	77 09                	ja     0x196
 18d:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 194:	eb 09                	jmp    0x19f
 196:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 19d:	eb 05                	jmp    0x1a4
 19f:	89 d1                	mov    ecx,edx
 1a1:	4c 01 c1             	add    rcx,r8
 1a4:	44 0f b6 11          	movzx  r10d,BYTE PTR [rcx]
 1a8:	44 89 c9             	mov    ecx,r9d
 1ab:	83 e1 07             	and    ecx,0x7
 1ae:	41 d3 e2             	shl    r10d,cl
 1b1:	48 89 9d 88 fe ff ff 	mov    QWORD PTR [rbp-0x178],rbx
 1b8:	44 89 d3             	mov    ebx,r10d
 1bb:	48 81 e3 ff 00 00 00 	and    rbx,0xff
 1c2:	48 f7 c3 80 00 00 00 	test   rbx,0x80
 1c9:	75 0c                	jne    0x1d7
 1cb:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 1d2:	e9 14 ff ff ff       	jmp    0xeb
 1d7:	48 8b 9d 88 fe ff ff 	mov    rbx,QWORD PTR [rbp-0x178]
 1de:	83 fa 05             	cmp    edx,0x5
 1e1:	7e 28                	jle    0x20b
 1e3:	83 fa 08             	cmp    edx,0x8
 1e6:	7e 4d                	jle    0x235
 1e8:	83 fa 0a             	cmp    edx,0xa
 1eb:	0f 8f 7e 00 00 00    	jg     0x26f
 1f1:	83 fa 09             	cmp    edx,0x9
 1f4:	0f 85 c0 00 00 00    	jne    0x2ba
 1fa:	41 bb 43 00 00 00    	mov    r11d,0x43
 200:	41 ba 00 3d 25 67    	mov    r10d,0x67253d00
 206:	e9 e5 00 00 00       	jmp    0x2f0
 20b:	83 fa 02             	cmp    edx,0x2
 20e:	7f 40                	jg     0x250
 210:	48 f7 c2 ff ff ff ff 	test   rdx,0xffffffffffffffff
 217:	75 02                	jne    0x21b
 219:	eb 75                	jmp    0x290
 21b:	83 fa 01             	cmp    edx,0x1
 21e:	0f 85 b2 00 00 00    	jne    0x2d6
 224:	41 bb 25 00 00 00    	mov    r11d,0x25
 22a:	41 ba 00 da 56 5a    	mov    r10d,0x5a56da00
 230:	e9 bb 00 00 00       	jmp    0x2f0
 235:	83 fa 06             	cmp    edx,0x6
 238:	74 48                	je     0x282
 23a:	83 fa 07             	cmp    edx,0x7
 23d:	75 6d                	jne    0x2ac
 23f:	41 bb 25 00 00 00    	mov    r11d,0x25
 245:	41 ba 00 67 41 c2    	mov    r10d,0xc2416700
 24b:	e9 a0 00 00 00       	jmp    0x2f0
 250:	83 fa 03             	cmp    edx,0x3
 253:	74 49                	je     0x29e
 255:	83 fa 04             	cmp    edx,0x4
 258:	0f 85 86 00 00 00    	jne    0x2e4
 25e:	41 bb c2 00 00 00    	mov    r11d,0xc2
 264:	41 ba 00 0e 5b 25    	mov    r10d,0x255b0e00
 26a:	e9 81 00 00 00       	jmp    0x2f0
 26f:	83 fa 0b             	cmp    edx,0xb
 272:	75 54                	jne    0x2c8
 274:	41 bb 8f 00 00 00    	mov    r11d,0x8f
 27a:	41 ba 00 a3 43 3d    	mov    r10d,0x3d43a300
 280:	eb 6e                	jmp    0x2f0
 282:	41 bb 67 00 00 00    	mov    r11d,0x67
 288:	41 ba 00 41 c2 0e    	mov    r10d,0xec24100
 28e:	eb 60                	jmp    0x2f0
 290:	41 bb da 00 00 00    	mov    r11d,0xda
 296:	41 ba 00 56 5a 6d    	mov    r10d,0x6d5a5600
 29c:	eb 52                	jmp    0x2f0
 29e:	41 bb 0e 00 00 00    	mov    r11d,0xe
 2a4:	41 ba 00 5b 25 da    	mov    r10d,0xda255b00
 2aa:	eb 44                	jmp    0x2f0
 2ac:	41 bb 3d 00 00 00    	mov    r11d,0x3d
 2b2:	41 ba 00 25 67 41    	mov    r10d,0x41672500
 2b8:	eb 36                	jmp    0x2f0
 2ba:	41 bb a3 00 00 00    	mov    r11d,0xa3
 2c0:	41 ba 00 43 3d 25    	mov    r10d,0x253d4300
 2c6:	eb 28                	jmp    0x2f0
 2c8:	41 bb b0 00 00 00    	mov    r11d,0xb0
 2ce:	41 ba 00 8f a3 43    	mov    r10d,0x43a38f00
 2d4:	eb 1a                	jmp    0x2f0
 2d6:	41 bb 5b 00 00 00    	mov    r11d,0x5b
 2dc:	41 ba 00 25 da 56    	mov    r10d,0x56da2500
 2e2:	eb 0c                	jmp    0x2f0
 2e4:	41 bb 41 00 00 00    	mov    r11d,0x41
 2ea:	41 ba 00 c2 0e 5b    	mov    r10d,0x5b0ec200
 2f0:	45 09 da             	or     r10d,r11d
 2f3:	48 f7 c1 ff ff ff ff 	test   rcx,0xffffffffffffffff
 2fa:	75 05                	jne    0x301
 2fc:	e9 e7 fd ff ff       	jmp    0xe8
 301:	41 d3 e2             	shl    r10d,cl
 304:	41 bb 25 00 00 00    	mov    r11d,0x25
 30a:	83 fa 05             	cmp    edx,0x5
 30d:	7e 1a                	jle    0x329
 30f:	83 fa 08             	cmp    edx,0x8
 312:	7e 38                	jle    0x34c
 314:	83 fa 0a             	cmp    edx,0xa
 317:	7f 65                	jg     0x37e
 319:	83 fa 09             	cmp    edx,0x9
 31c:	75 7b                	jne    0x399
 31e:	41 bb a3 00 00 00    	mov    r11d,0xa3
 324:	e9 b2 fd ff ff       	jmp    0xdb
 329:	83 fa 02             	cmp    edx,0x2
 32c:	7f 37                	jg     0x365
 32e:	48 f7 c2 ff ff ff ff 	test   rdx,0xffffffffffffffff
 335:	75 05                	jne    0x33c
 337:	e9 9f fd ff ff       	jmp    0xdb
 33c:	83 fa 01             	cmp    edx,0x1
 33f:	75 6e                	jne    0x3af
 341:	41 bb 5b 00 00 00    	mov    r11d,0x5b
 347:	e9 8f fd ff ff       	jmp    0xdb
 34c:	83 fa 06             	cmp    edx,0x6
 34f:	0f 84 86 fd ff ff    	je     0xdb
 355:	83 fa 07             	cmp    edx,0x7
 358:	75 34                	jne    0x38e
 35a:	41 bb 3d 00 00 00    	mov    r11d,0x3d
 360:	e9 76 fd ff ff       	jmp    0xdb
 365:	83 fa 03             	cmp    edx,0x3
 368:	0f 84 67 fd ff ff    	je     0xd5
 36e:	83 fa 04             	cmp    edx,0x4
 371:	75 47                	jne    0x3ba
 373:	41 bb 41 00 00 00    	mov    r11d,0x41
 379:	e9 5d fd ff ff       	jmp    0xdb
 37e:	83 fa 0b             	cmp    edx,0xb
 381:	75 21                	jne    0x3a4
 383:	41 bb b0 00 00 00    	mov    r11d,0xb0
 389:	e9 4d fd ff ff       	jmp    0xdb
 38e:	41 bb 43 00 00 00    	mov    r11d,0x43
 394:	e9 42 fd ff ff       	jmp    0xdb
 399:	41 bb 8f 00 00 00    	mov    r11d,0x8f
 39f:	e9 37 fd ff ff       	jmp    0xdb
 3a4:	41 bb d0 00 00 00    	mov    r11d,0xd0
 3aa:	e9 2c fd ff ff       	jmp    0xdb
 3af:	41 bb 0e 00 00 00    	mov    r11d,0xe
 3b5:	e9 21 fd ff ff       	jmp    0xdb
 3ba:	41 bb 67 00 00 00    	mov    r11d,0x67
 3c0:	e9 16 fd ff ff       	jmp    0xdb
 3c5:	8b 56 26             	mov    edx,DWORD PTR [rsi+0x26]
 3c8:	0f b6 4e 2a          	movzx  ecx,BYTE PTR [rsi+0x2a]
 3cc:	44 0f b6 46 2b       	movzx  r8d,BYTE PTR [rsi+0x2b]
 3d1:	44 0f b6 4e 2c       	movzx  r9d,BYTE PTR [rsi+0x2c]
 3d6:	44 0f b6 56 2d       	movzx  r10d,BYTE PTR [rsi+0x2d]
 3db:	49 89 c3             	mov    r11,rax
 3de:	49 c1 e3 20          	shl    r11,0x20
 3e2:	33 56 22             	xor    edx,DWORD PTR [rsi+0x22]
 3e5:	0f ca                	bswap  edx
 3e7:	89 d7                	mov    edi,edx
 3e9:	31 c7                	xor    edi,eax
 3eb:	4c 09 df             	or     rdi,r11
 3ee:	48 c1 e1 38          	shl    rcx,0x38
 3f2:	49 c1 e0 30          	shl    r8,0x30
 3f6:	49 09 c8             	or     r8,rcx
 3f9:	49 c1 e1 28          	shl    r9,0x28
 3fd:	4d 09 c1             	or     r9,r8
 400:	49 c1 e2 20          	shl    r10,0x20
 404:	4c 09 ca             	or     rdx,r9
 407:	4c 09 d2             	or     rdx,r10
 40a:	83 e0 07             	and    eax,0x7
 40d:	8d 48 01             	lea    ecx,[rax+0x1]
 410:	49 89 d0             	mov    r8,rdx
 413:	49 d3 e0             	shl    r8,cl
 416:	f6 d0                	not    al
 418:	89 c1                	mov    ecx,eax
 41a:	48 d3 ea             	shr    rdx,cl
 41d:	4c 09 c2             	or     rdx,r8
 420:	48 31 fa             	xor    rdx,rdi
 423:	48 89 16             	mov    QWORD PTR [rsi],rdx
 426:	b8 02 00 00 00       	mov    eax,0x2
 42b:	e9 12 fc ff ff       	jmp    0x42
```
