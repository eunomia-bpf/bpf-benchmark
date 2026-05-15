# packet_vlan_tcpopt_parser

## Original C
```c
#include "common.h"

static __always_inline int
micro_parse_tcp_options(const u8 *options_cursor, const u8 *options_end, const u8 *data_end, u64 *out)
{
    if (options_cursor + 12U > options_end || options_cursor + 12U > data_end) {
        return -1;
    }

    const u8 *options = options_cursor;
    u64 option_acc = 0;

    if (options[0] != 2U || options[1] < 4U) {
        return -1;
    }
    option_acc += (u64)options[0];
    option_acc += micro_read_u16_be(options, 2U);
    option_acc ^= (u64)options[2U] << 16U;
    option_acc ^= (u64)options[3U] << 24U;

    if (options[4] != 1U) {
        return -1;
    }
    option_acc += (u64)options[4U] << 8U;

    if (options[5] != 3U || options[6] < 3U) {
        return -1;
    }
    option_acc += (u64)options[5U] << 16U;
    option_acc ^= (u64)options[7U] << 32U;
    option_acc ^= (u64)options[7U] << 16U;

    if (options[8] != 4U || options[9] < 2U) {
        return -1;
    }
    option_acc += (u64)options[8U] << 24U;
    option_acc += 0x40000000ULL;

    if (options[10] != 1U) {
        return -1;
    }
    option_acc += (u64)options[10U] << 32U;

    option_acc += (u64)options[11U] << 40U;
    *out = option_acc;
    return 0;
}

static __always_inline int
bench_packet_vlan_tcpopt_parser(const u8 *data, const u8 *data_end, u64 *out)
{
    if (data + 14U > data_end) {
        return -1;
    }

    const u8 *cursor = data + 14U;
    u16 ethertype = micro_read_u16_be(data, 12U);
    u16 vlan0 = 0;
    u16 vlan1 = 0;
    u32 vlan_count = 0;

    for (u32 depth = 0; depth < 2U; depth++) {
        if (ethertype != 0x8100U && ethertype != 0x88A8U) {
            break;
        }
        if (cursor + 4U > data_end) {
            return -1;
        }
        if (vlan_count == 0U) {
            vlan0 = micro_read_u16_be(cursor, 0U);
        } else {
            vlan1 = micro_read_u16_be(cursor, 0U);
        }
        ethertype = micro_read_u16_be(cursor, 2U);
        vlan_count++;
        cursor += 4U;
    }

    if (ethertype != 0x0800U) {
        return -1;
    }

    const u8 *ip = cursor;
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
    u32 src_ip = micro_read_u32_be(ip, 12U);
    u32 dst_ip = micro_read_u32_be(ip, 16U);
    if (protocol != 6U) {
        return -1;
    }

    const u8 *tcp = ip + ip_header_len;
    if (tcp + 20U > data_end) {
        return -1;
    }

    u16 src_port = micro_read_u16_be(tcp, 0U);
    u16 dst_port = micro_read_u16_be(tcp, 2U);
    u8 data_offset_words = tcp[12U] >> 4;
    if (data_offset_words < 5U) {
        return -1;
    }

    u32 tcp_header_len = (u32)data_offset_words * 4U;
    if (tcp + tcp_header_len > data_end) {
        return -1;
    }

    u64 option_acc = 0;
    if (micro_parse_tcp_options(tcp + 20U, tcp + tcp_header_len, data_end, &option_acc) < 0) {
        return -1;
    }

    u64 acc = total_len;
    acc += (u64)src_port + dst_port;
    acc ^= (u64)src_ip;
    acc += (u64)dst_ip;
    acc ^= ((u64)vlan0 << 16U) | vlan1;
    acc += ((u64)vlan_count << 40U) |
           ((u64)protocol << 32U) |
           ((u64)ip_header_len << 8U) |
           tcp_header_len;
    acc ^= micro_rotl64(option_acc, vlan_count + 5U);

    *out = acc;
    return 0;
}

SEC("xdp") int packet_vlan_tcpopt_parser_xdp(struct xdp_md *ctx)
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

    if (bench_packet_vlan_tcpopt_parser(payload, data_end, &result) < 0) {
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

0000000000001100 <packet_vlan_tcpopt_parser_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	4c 8b 57 08          	mov    r10,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	4c 39 d2             	cmp    rdx,r10
    110c:	0f 87 32 01 00 00    	ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144>
    1112:	48 8d 4a 08          	lea    rcx,[rdx+0x8]
    1116:	4c 39 d1             	cmp    rcx,r10
    1119:	0f 87 25 01 00 00    	ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144>
    111f:	4c 8d 4a 16          	lea    r9,[rdx+0x16]
    1123:	4d 39 d1             	cmp    r9,r10
    1126:	0f 87 18 01 00 00    	ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144>
    112c:	55                   	push   rbp
    112d:	41 57                	push   r15
    112f:	41 56                	push   r14
    1131:	53                   	push   rbx
    1132:	0f b7 42 14          	movzx  eax,WORD PTR [rdx+0x14]
    1136:	66 c1 c0 08          	rol    ax,0x8
    113a:	0f b7 c8             	movzx  ecx,ax
    113d:	31 c0                	xor    eax,eax
    113f:	81 f9 00 08 00 00    	cmp    ecx,0x800
    1145:	0f 84 94 00 00 00    	je     11df <packet_vlan_tcpopt_parser_xdp+0xdf>
    114b:	81 f9 a8 88 00 00    	cmp    ecx,0x88a8
    1151:	74 0c                	je     115f <packet_vlan_tcpopt_parser_xdp+0x5f>
    1153:	81 f9 00 81 00 00    	cmp    ecx,0x8100
    1159:	0f 85 df 00 00 00    	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    115f:	4c 8d 4a 1a          	lea    r9,[rdx+0x1a]
    1163:	4d 39 d1             	cmp    r9,r10
    1166:	0f 87 d2 00 00 00    	ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    116c:	0f b7 72 16          	movzx  esi,WORD PTR [rdx+0x16]
    1170:	0f b7 4a 18          	movzx  ecx,WORD PTR [rdx+0x18]
    1174:	66 c1 c6 08          	rol    si,0x8
    1178:	66 c1 c1 08          	rol    cx,0x8
    117c:	0f b7 c9             	movzx  ecx,cx
    117f:	81 f9 00 08 00 00    	cmp    ecx,0x800
    1185:	0f 84 ba 00 00 00    	je     1245 <packet_vlan_tcpopt_parser_xdp+0x145>
    118b:	81 f9 a8 88 00 00    	cmp    ecx,0x88a8
    1191:	74 0c                	je     119f <packet_vlan_tcpopt_parser_xdp+0x9f>
    1193:	81 f9 00 81 00 00    	cmp    ecx,0x8100
    1199:	0f 85 9f 00 00 00    	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    119f:	48 8d 4a 1e          	lea    rcx,[rdx+0x1e]
    11a3:	4c 39 d1             	cmp    rcx,r10
    11a6:	0f 87 92 00 00 00    	ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    11ac:	0f b7 4a 1c          	movzx  ecx,WORD PTR [rdx+0x1c]
    11b0:	66 c1 c1 08          	rol    cx,0x8
    11b4:	0f b7 c9             	movzx  ecx,cx
    11b7:	81 f9 00 08 00 00    	cmp    ecx,0x800
    11bd:	75 7f                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    11bf:	48 8d 4a 32          	lea    rcx,[rdx+0x32]
    11c3:	4c 39 d1             	cmp    rcx,r10
    11c6:	77 76                	ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    11c8:	4c 8d 4a 1e          	lea    r9,[rdx+0x1e]
    11cc:	0f b7 4a 1a          	movzx  ecx,WORD PTR [rdx+0x1a]
    11d0:	66 c1 c1 08          	rol    cx,0x8
    11d4:	44 0f b7 c1          	movzx  r8d,cx
    11d8:	b9 02 00 00 00       	mov    ecx,0x2
    11dd:	eb 10                	jmp    11ef <packet_vlan_tcpopt_parser_xdp+0xef>
    11df:	31 f6                	xor    esi,esi
    11e1:	31 c9                	xor    ecx,ecx
    11e3:	49 8d 79 14          	lea    rdi,[r9+0x14]
    11e7:	4c 39 d7             	cmp    rdi,r10
    11ea:	77 52                	ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    11ec:	45 31 c0             	xor    r8d,r8d
    11ef:	41 0f b6 39          	movzx  edi,BYTE PTR [r9]
    11f3:	41 89 fb             	mov    r11d,edi
    11f6:	41 80 e3 f0          	and    r11b,0xf0
    11fa:	41 80 fb 40          	cmp    r11b,0x40
    11fe:	75 3e                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1200:	83 e7 0f             	and    edi,0xf
    1203:	40 80 ff 05          	cmp    dil,0x5
    1207:	72 35                	jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1209:	49 8d 1c b9          	lea    rbx,[r9+rdi*4]
    120d:	4c 39 d3             	cmp    rbx,r10
    1210:	77 2c                	ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1212:	41 80 79 09 06       	cmp    BYTE PTR [r9+0x9],0x6
    1217:	75 25                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1219:	4c 8d 73 14          	lea    r14,[rbx+0x14]
    121d:	4d 39 d6             	cmp    r14,r10
    1220:	77 1c                	ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1222:	44 0f b6 5b 0c       	movzx  r11d,BYTE PTR [rbx+0xc]
    1227:	49 83 fb 50          	cmp    r11,0x50
    122b:	72 11                	jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    122d:	41 c1 eb 02          	shr    r11d,0x2
    1231:	41 83 e3 fc          	and    r11d,0xfffffffc
    1235:	4e 8d 3c 1b          	lea    r15,[rbx+r11*1]
    1239:	4d 39 d7             	cmp    r15,r10
    123c:	76 0e                	jbe    124c <packet_vlan_tcpopt_parser_xdp+0x14c>
    123e:	5b                   	pop    rbx
    123f:	41 5e                	pop    r14
    1241:	41 5f                	pop    r15
    1243:	5d                   	pop    rbp
    1244:	c3                   	ret
    1245:	b9 01 00 00 00       	mov    ecx,0x1
    124a:	eb 97                	jmp    11e3 <packet_vlan_tcpopt_parser_xdp+0xe3>
    124c:	4c 8d 7b 20          	lea    r15,[rbx+0x20]
    1250:	4d 39 d7             	cmp    r15,r10
    1253:	77 e9                	ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1255:	41 80 fb 20          	cmp    r11b,0x20
    1259:	72 e3                	jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    125b:	41 80 3e 02          	cmp    BYTE PTR [r14],0x2
    125f:	75 dd                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1261:	80 7b 15 04          	cmp    BYTE PTR [rbx+0x15],0x4
    1265:	72 d7                	jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1267:	80 7b 18 01          	cmp    BYTE PTR [rbx+0x18],0x1
    126b:	75 d1                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    126d:	80 7b 19 03          	cmp    BYTE PTR [rbx+0x19],0x3
    1271:	75 cb                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1273:	80 7b 1a 03          	cmp    BYTE PTR [rbx+0x1a],0x3
    1277:	72 c5                	jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1279:	80 7b 1c 04          	cmp    BYTE PTR [rbx+0x1c],0x4
    127d:	75 bf                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    127f:	80 7b 1d 02          	cmp    BYTE PTR [rbx+0x1d],0x2
    1283:	72 b9                	jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    1285:	80 7b 1e 01          	cmp    BYTE PTR [rbx+0x1e],0x1
    1289:	75 b3                	jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e>
    128b:	48 c1 e7 02          	shl    rdi,0x2
    128f:	41 0f b7 41 02       	movzx  eax,WORD PTR [r9+0x2]
    1294:	66 c1 c0 08          	rol    ax,0x8
    1298:	0f b7 c0             	movzx  eax,ax
    129b:	45 8b 51 0c          	mov    r10d,DWORD PTR [r9+0xc]
    129f:	41 0f ca             	bswap  r10d
    12a2:	45 8b 49 10          	mov    r9d,DWORD PTR [r9+0x10]
    12a6:	41 0f c9             	bswap  r9d
    12a9:	0f b7 2b             	movzx  ebp,WORD PTR [rbx]
    12ac:	44 0f b7 73 02       	movzx  r14d,WORD PTR [rbx+0x2]
    12b1:	66 c1 c5 08          	rol    bp,0x8
    12b5:	44 0f b7 fd          	movzx  r15d,bp
    12b9:	49 01 c7             	add    r15,rax
    12bc:	66 41 c1 c6 08       	rol    r14w,0x8
    12c1:	41 0f b7 c6          	movzx  eax,r14w
    12c5:	4c 01 f8             	add    rax,r15
    12c8:	4c 31 d0             	xor    rax,r10
    12cb:	4c 01 c8             	add    rax,r9
    12ce:	44 0f b6 4b 16       	movzx  r9d,BYTE PTR [rbx+0x16]
    12d3:	45 89 ca             	mov    r10d,r9d
    12d6:	41 c1 e2 08          	shl    r10d,0x8
    12da:	44 0f b6 73 17       	movzx  r14d,BYTE PTR [rbx+0x17]
    12df:	45 09 f2             	or     r10d,r14d
    12e2:	49 83 c2 02          	add    r10,0x2
    12e6:	41 c1 e1 10          	shl    r9d,0x10
    12ea:	4d 31 d1             	xor    r9,r10
    12ed:	41 c1 e6 18          	shl    r14d,0x18
    12f1:	4d 01 f1             	add    r9,r14
    12f4:	49 81 c1 00 01 03 00 	add    r9,0x30100
    12fb:	44 0f b6 53 1b       	movzx  r10d,BYTE PTR [rbx+0x1b]
    1300:	4d 89 d6             	mov    r14,r10
    1303:	49 c1 e6 20          	shl    r14,0x20
    1307:	41 c1 e2 10          	shl    r10d,0x10
    130b:	4d 31 f2             	xor    r10,r14
    130e:	4d 31 ca             	xor    r10,r9
    1311:	0f b6 5b 1f          	movzx  ebx,BYTE PTR [rbx+0x1f]
    1315:	48 c1 e3 28          	shl    rbx,0x28
    1319:	4c 09 d3             	or     rbx,r10
    131c:	49 b9 00 00 00 44 01 	movabs r9,0x144000000
    1323:	00 00 00 
    1326:	49 01 d9             	add    r9,rbx
    1329:	c1 e6 10             	shl    esi,0x10
    132c:	4c 09 c6             	or     rsi,r8
    132f:	48 31 c6             	xor    rsi,rax
    1332:	48 89 c8             	mov    rax,rcx
    1335:	48 c1 e0 28          	shl    rax,0x28
    1339:	c1 e7 08             	shl    edi,0x8
    133c:	48 09 c7             	or     rdi,rax
    133f:	4c 09 df             	or     rdi,r11
    1342:	48 b8 00 00 00 00 06 	movabs rax,0x600000000
    1349:	00 00 00 
    134c:	48 01 f8             	add    rax,rdi
    134f:	83 c1 05             	add    ecx,0x5
    1352:	49 d3 c1             	rol    r9,cl
    1355:	48 01 f0             	add    rax,rsi
    1358:	49 31 c1             	xor    r9,rax
    135b:	4c 89 0a             	mov    QWORD PTR [rdx],r9
    135e:	b8 02 00 00 00       	mov    eax,0x2
    1363:	e9 d6 fe ff ff       	jmp    123e <packet_vlan_tcpopt_parser_xdp+0x13e>

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
   c:	48 81 ec 30 00 00 00 	sub    rsp,0x30
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 00          	mov    rsi,QWORD PTR [rdi+0x0]
  20:	4c 8b 77 08          	mov    r14,QWORD PTR [rdi+0x8]
  24:	4c 39 f6             	cmp    rsi,r14
  27:	0f 87 0b 01 00 00    	ja     0x138
  2d:	48 89 f7             	mov    rdi,rsi
  30:	48 83 c7 08          	add    rdi,0x8
  34:	4c 39 f7             	cmp    rdi,r14
  37:	0f 87 fb 00 00 00    	ja     0x138
  3d:	49 89 f0             	mov    r8,rsi
  40:	49 83 c0 16          	add    r8,0x16
  44:	4d 39 f0             	cmp    r8,r14
  47:	0f 87 eb 00 00 00    	ja     0x138
  4d:	48 0f b6 7e 15       	movzx  rdi,BYTE PTR [rsi+0x15]
  52:	48 0f b6 5e 14       	movzx  rbx,BYTE PTR [rsi+0x14]
  57:	48 c1 e3 08          	shl    rbx,0x8
  5b:	48 09 fb             	or     rbx,rdi
  5e:	31 d2                	xor    edx,edx
  60:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
  67:	31 ff                	xor    edi,edi
  69:	31 c9                	xor    ecx,ecx
  6b:	48 81 fb 00 08 00 00 	cmp    rbx,0x800
  72:	0f 84 c9 00 00 00    	je     0x141
  78:	48 81 fb a8 88 00 00 	cmp    rbx,0x88a8
  7f:	74 0d                	je     0x8e
  81:	48 81 fb 00 81 00 00 	cmp    rbx,0x8100
  88:	0f 85 aa 00 00 00    	jne    0x138
  8e:	49 89 f0             	mov    r8,rsi
  91:	49 83 c0 1a          	add    r8,0x1a
  95:	4d 39 f0             	cmp    r8,r14
  98:	0f 87 9a 00 00 00    	ja     0x138
  9e:	48 0f b6 7e 16       	movzx  rdi,BYTE PTR [rsi+0x16]
  a3:	48 c1 e7 08          	shl    rdi,0x8
  a7:	48 0f b6 4e 17       	movzx  rcx,BYTE PTR [rsi+0x17]
  ac:	48 09 cf             	or     rdi,rcx
  af:	48 0f b6 4e 19       	movzx  rcx,BYTE PTR [rsi+0x19]
  b4:	48 0f b6 5e 18       	movzx  rbx,BYTE PTR [rsi+0x18]
  b9:	48 c1 e3 08          	shl    rbx,0x8
  bd:	48 09 cb             	or     rbx,rcx
  c0:	b9 01 00 00 00       	mov    ecx,0x1
  c5:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
  cc:	48 81 fb 00 08 00 00 	cmp    rbx,0x800
  d3:	74 6c                	je     0x141
  d5:	48 81 fb a8 88 00 00 	cmp    rbx,0x88a8
  dc:	74 09                	je     0xe7
  de:	48 81 fb 00 81 00 00 	cmp    rbx,0x8100
  e5:	75 51                	jne    0x138
  e7:	49 89 f0             	mov    r8,rsi
  ea:	49 83 c0 1e          	add    r8,0x1e
  ee:	4d 39 f0             	cmp    r8,r14
  f1:	77 45                	ja     0x138
  f3:	48 0f b6 56 1c       	movzx  rdx,BYTE PTR [rsi+0x1c]
  f8:	48 c1 e2 08          	shl    rdx,0x8
  fc:	48 0f b6 4e 1d       	movzx  rcx,BYTE PTR [rsi+0x1d]
 101:	48 09 ca             	or     rdx,rcx
 104:	48 81 e2 ff ff 00 00 	and    rdx,0xffff
 10b:	48 81 fa 00 08 00 00 	cmp    rdx,0x800
 112:	75 24                	jne    0x138
 114:	48 0f b6 56 1a       	movzx  rdx,BYTE PTR [rsi+0x1a]
 119:	48 c1 e2 08          	shl    rdx,0x8
 11d:	48 0f b6 4e 1b       	movzx  rcx,BYTE PTR [rsi+0x1b]
 122:	48 09 ca             	or     rdx,rcx
 125:	b9 02 00 00 00       	mov    ecx,0x2
 12a:	48 89 f3             	mov    rbx,rsi
 12d:	48 83 c3 32          	add    rbx,0x32
 131:	4c 39 f3             	cmp    rbx,r14
 134:	77 02                	ja     0x138
 136:	eb 15                	jmp    0x14d
 138:	41 5f                	pop    r15
 13a:	41 5e                	pop    r14
 13c:	41 5d                	pop    r13
 13e:	5b                   	pop    rbx
 13f:	c9                   	leave
 140:	c3                   	ret
 141:	4c 89 c3             	mov    rbx,r8
 144:	48 83 c3 14          	add    rbx,0x14
 148:	4c 39 f3             	cmp    rbx,r14
 14b:	77 eb                	ja     0x138
 14d:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 152:	49 89 dd             	mov    r13,rbx
 155:	49 81 e5 f0 00 00 00 	and    r13,0xf0
 15c:	49 83 fd 40          	cmp    r13,0x40
 160:	75 d6                	jne    0x138
 162:	48 83 e3 0f          	and    rbx,0xf
 166:	41 bd 05 00 00 00    	mov    r13d,0x5
 16c:	49 39 dd             	cmp    r13,rbx
 16f:	77 c7                	ja     0x138
 171:	48 c1 e3 02          	shl    rbx,0x2
 175:	4d 89 c5             	mov    r13,r8
 178:	49 01 dd             	add    r13,rbx
 17b:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 17f:	4d 39 f5             	cmp    r13,r14
 182:	77 b4                	ja     0x138
 184:	4d 0f b6 78 09       	movzx  r15,BYTE PTR [r8+0x9]
 189:	49 83 ff 06          	cmp    r15,0x6
 18d:	75 a9                	jne    0x138
 18f:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
 193:	49 83 c7 14          	add    r15,0x14
 197:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 19b:	4d 39 f7             	cmp    r15,r14
 19e:	77 98                	ja     0x138
 1a0:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 1a4:	4d 0f b6 6d 0c       	movzx  r13,BYTE PTR [r13+0xc]
 1a9:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 1ad:	41 bf 50 00 00 00    	mov    r15d,0x50
 1b3:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1b7:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1bb:	4d 39 ef             	cmp    r15,r13
 1be:	0f 87 74 ff ff ff    	ja     0x138
 1c4:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 1c8:	49 c1 ef 02          	shr    r15,0x2
 1cc:	49 83 e7 3c          	and    r15,0x3c
 1d0:	4d 89 fd             	mov    r13,r15
 1d3:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
 1d7:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 1db:	4d 01 ef             	add    r15,r13
 1de:	4d 39 f7             	cmp    r15,r14
 1e1:	0f 87 51 ff ff ff    	ja     0x138
 1e7:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
 1eb:	49 83 c7 20          	add    r15,0x20
 1ef:	4d 39 f7             	cmp    r15,r14
 1f2:	0f 87 40 ff ff ff    	ja     0x138
 1f8:	41 be 20 00 00 00    	mov    r14d,0x20
 1fe:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 202:	4d 39 fe             	cmp    r14,r15
 205:	0f 87 2d ff ff ff    	ja     0x138
 20b:	4c 8b 75 e8          	mov    r14,QWORD PTR [rbp-0x18]
 20f:	4d 0f b6 76 00       	movzx  r14,BYTE PTR [r14+0x0]
 214:	49 83 fe 02          	cmp    r14,0x2
 218:	0f 85 1a ff ff ff    	jne    0x138
 21e:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 222:	4d 0f b6 75 15       	movzx  r14,BYTE PTR [r13+0x15]
 227:	41 bf 04 00 00 00    	mov    r15d,0x4
 22d:	4d 39 f7             	cmp    r15,r14
 230:	0f 87 02 ff ff ff    	ja     0x138
 236:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 23a:	4d 0f b6 75 18       	movzx  r14,BYTE PTR [r13+0x18]
 23f:	49 83 fe 01          	cmp    r14,0x1
 243:	0f 85 ef fe ff ff    	jne    0x138
 249:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 24d:	4d 0f b6 75 19       	movzx  r14,BYTE PTR [r13+0x19]
 252:	49 83 fe 03          	cmp    r14,0x3
 256:	0f 85 dc fe ff ff    	jne    0x138
 25c:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 260:	4d 0f b6 75 1a       	movzx  r14,BYTE PTR [r13+0x1a]
 265:	41 bf 03 00 00 00    	mov    r15d,0x3
 26b:	4d 39 f7             	cmp    r15,r14
 26e:	0f 87 c4 fe ff ff    	ja     0x138
 274:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 278:	4d 0f b6 75 1c       	movzx  r14,BYTE PTR [r13+0x1c]
 27d:	49 83 fe 04          	cmp    r14,0x4
 281:	0f 85 b1 fe ff ff    	jne    0x138
 287:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 28b:	4d 0f b6 75 1d       	movzx  r14,BYTE PTR [r13+0x1d]
 290:	41 bf 02 00 00 00    	mov    r15d,0x2
 296:	4d 39 f7             	cmp    r15,r14
 299:	0f 87 99 fe ff ff    	ja     0x138
 29f:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 2a3:	4d 0f b6 75 1e       	movzx  r14,BYTE PTR [r13+0x1e]
 2a8:	49 83 fe 01          	cmp    r14,0x1
 2ac:	0f 85 86 fe ff ff    	jne    0x138
 2b2:	49 0f b6 40 10       	movzx  rax,BYTE PTR [r8+0x10]
 2b7:	48 c1 e0 18          	shl    rax,0x18
 2bb:	4d 0f b6 70 11       	movzx  r14,BYTE PTR [r8+0x11]
 2c0:	49 c1 e6 10          	shl    r14,0x10
 2c4:	49 09 c6             	or     r14,rax
 2c7:	49 0f b6 40 12       	movzx  rax,BYTE PTR [r8+0x12]
 2cc:	48 c1 e0 08          	shl    rax,0x8
 2d0:	49 09 c6             	or     r14,rax
 2d3:	4d 0f b6 78 02       	movzx  r15,BYTE PTR [r8+0x2]
 2d8:	49 c1 e7 08          	shl    r15,0x8
 2dc:	49 0f b6 40 03       	movzx  rax,BYTE PTR [r8+0x3]
 2e1:	49 09 c7             	or     r15,rax
 2e4:	4c 89 7d e0          	mov    QWORD PTR [rbp-0x20],r15
 2e8:	49 0f b6 40 13       	movzx  rax,BYTE PTR [r8+0x13]
 2ed:	49 09 c6             	or     r14,rax
 2f0:	4c 89 75 e8          	mov    QWORD PTR [rbp-0x18],r14
 2f4:	49 0f b6 40 0c       	movzx  rax,BYTE PTR [r8+0xc]
 2f9:	48 c1 e0 18          	shl    rax,0x18
 2fd:	4d 0f b6 70 0d       	movzx  r14,BYTE PTR [r8+0xd]
 302:	49 c1 e6 10          	shl    r14,0x10
 306:	49 09 c6             	or     r14,rax
 309:	49 0f b6 40 0e       	movzx  rax,BYTE PTR [r8+0xe]
 30e:	48 c1 e0 08          	shl    rax,0x8
 312:	49 09 c6             	or     r14,rax
 315:	4d 0f b6 40 0f       	movzx  r8,BYTE PTR [r8+0xf]
 31a:	4d 09 c6             	or     r14,r8
 31d:	4c 89 75 d8          	mov    QWORD PTR [rbp-0x28],r14
 321:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 325:	49 0f b6 45 02       	movzx  rax,BYTE PTR [r13+0x2]
 32a:	48 c1 e0 08          	shl    rax,0x8
 32e:	4d 0f b6 45 03       	movzx  r8,BYTE PTR [r13+0x3]
 333:	4c 09 c0             	or     rax,r8
 336:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
 33a:	49 0f b6 45 00       	movzx  rax,BYTE PTR [r13+0x0]
 33f:	48 c1 e0 08          	shl    rax,0x8
 343:	4d 0f b6 45 01       	movzx  r8,BYTE PTR [r13+0x1]
 348:	4c 09 c0             	or     rax,r8
 34b:	4d 0f b6 75 17       	movzx  r14,BYTE PTR [r13+0x17]
 350:	4d 0f b6 45 16       	movzx  r8,BYTE PTR [r13+0x16]
 355:	4d 89 c7             	mov    r15,r8
 358:	49 c1 e7 08          	shl    r15,0x8
 35c:	4d 09 f7             	or     r15,r14
 35f:	49 83 c7 02          	add    r15,0x2
 363:	49 c1 e0 10          	shl    r8,0x10
 367:	4d 31 c7             	xor    r15,r8
 36a:	49 c1 e6 18          	shl    r14,0x18
 36e:	4d 01 f7             	add    r15,r14
 371:	49 81 c7 00 01 03 00 	add    r15,0x30100
 378:	4d 0f b6 75 1b       	movzx  r14,BYTE PTR [r13+0x1b]
 37d:	4d 89 f0             	mov    r8,r14
 380:	49 c1 e0 20          	shl    r8,0x20
 384:	4d 31 f8             	xor    r8,r15
 387:	49 c1 e6 10          	shl    r14,0x10
 38b:	4d 31 f0             	xor    r8,r14
 38e:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 395:	48 c1 e7 10          	shl    rdi,0x10
 399:	48 09 d7             	or     rdi,rdx
 39c:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 3a0:	48 01 d0             	add    rax,rdx
 3a3:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 3a7:	48 01 d0             	add    rax,rdx
 3aa:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
 3ae:	48 31 d0             	xor    rax,rdx
 3b1:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 3b5:	48 01 d0             	add    rax,rdx
 3b8:	48 31 f8             	xor    rax,rdi
 3bb:	48 c1 e3 08          	shl    rbx,0x8
 3bf:	48 89 cf             	mov    rdi,rcx
 3c2:	48 c1 e7 28          	shl    rdi,0x28
 3c6:	48 09 df             	or     rdi,rbx
 3c9:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
 3cd:	48 09 d7             	or     rdi,rdx
 3d0:	48 01 f8             	add    rax,rdi
 3d3:	48 bf 00 00 00 00 06 	movabs rdi,0x600000000
 3da:	00 00 00 
 3dd:	48 01 f8             	add    rax,rdi
 3e0:	49 0f b6 7d 1f       	movzx  rdi,BYTE PTR [r13+0x1f]
 3e5:	48 c1 e7 28          	shl    rdi,0x28
 3e9:	49 09 f8             	or     r8,rdi
 3ec:	48 bf 00 00 00 44 01 	movabs rdi,0x144000000
 3f3:	00 00 00 
 3f6:	49 01 f8             	add    r8,rdi
 3f9:	48 83 c1 05          	add    rcx,0x5
 3fd:	49 d3 e0             	shl    r8,cl
 400:	49 31 c0             	xor    r8,rax
 403:	31 ff                	xor    edi,edi
 405:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 409:	4c 89 c7             	mov    rdi,r8
 40c:	48 c1 ef 30          	shr    rdi,0x30
 410:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 414:	4c 89 c7             	mov    rdi,r8
 417:	48 c1 ef 28          	shr    rdi,0x28
 41b:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 41f:	4c 89 c7             	mov    rdi,r8
 422:	48 c1 ef 20          	shr    rdi,0x20
 426:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 42a:	4c 89 c7             	mov    rdi,r8
 42d:	48 c1 ef 18          	shr    rdi,0x18
 431:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 435:	4c 89 c7             	mov    rdi,r8
 438:	48 c1 ef 10          	shr    rdi,0x10
 43c:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 440:	44 88 46 00          	mov    BYTE PTR [rsi+0x0],r8b
 444:	49 c1 e8 08          	shr    r8,0x8
 448:	44 88 46 01          	mov    BYTE PTR [rsi+0x1],r8b
 44c:	b8 02 00 00 00       	mov    eax,0x2
 451:	e9 e2 fc ff ff       	jmp    0x138
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   6:	44 8b 4f 04          	mov    r9d,DWORD PTR [rdi+0x4]
   a:	31 c0                	xor    eax,eax
   c:	44 39 c9             	cmp    ecx,r9d
   f:	77 14                	ja     0x25
  11:	48 8d 51 08          	lea    rdx,[rcx+0x8]
  15:	4c 39 ca             	cmp    rdx,r9
  18:	77 0b                	ja     0x25
  1a:	48 8d 51 16          	lea    rdx,[rcx+0x16]
  1e:	4c 39 ca             	cmp    rdx,r9
  21:	76 03                	jbe    0x26
  23:	31 c0                	xor    eax,eax
  25:	c3                   	ret
  26:	55                   	push   rbp
  27:	41 57                	push   r15
  29:	41 56                	push   r14
  2b:	53                   	push   rbx
  2c:	66 0f 38 f0 41 14    	movbe  ax,WORD PTR [rcx+0x14]
  32:	0f b7 f0             	movzx  esi,ax
  35:	31 c0                	xor    eax,eax
  37:	81 fe 00 08 00 00    	cmp    esi,0x800
  3d:	0f 84 83 00 00 00    	je     0xc6
  43:	81 fe a8 88 00 00    	cmp    esi,0x88a8
  49:	74 0c                	je     0x57
  4b:	81 fe 00 81 00 00    	cmp    esi,0x8100
  51:	0f 85 c3 00 00 00    	jne    0x11a
  57:	48 8d 51 1a          	lea    rdx,[rcx+0x1a]
  5b:	4c 39 ca             	cmp    rdx,r9
  5e:	0f 87 b4 00 00 00    	ja     0x118
  64:	66 0f 38 f0 41 16    	movbe  ax,WORD PTR [rcx+0x16]
  6a:	0f b7 f0             	movzx  esi,ax
  6d:	66 0f 38 f0 41 18    	movbe  ax,WORD PTR [rcx+0x18]
  73:	0f b7 c0             	movzx  eax,ax
  76:	3d 00 08 00 00       	cmp    eax,0x800
  7b:	0f 84 a0 00 00 00    	je     0x121
  81:	3d a8 88 00 00       	cmp    eax,0x88a8
  86:	74 0b                	je     0x93
  88:	3d 00 81 00 00       	cmp    eax,0x8100
  8d:	0f 85 85 00 00 00    	jne    0x118
  93:	48 8d 51 1e          	lea    rdx,[rcx+0x1e]
  97:	4c 39 ca             	cmp    rdx,r9
  9a:	77 7c                	ja     0x118
  9c:	66 0f 38 f0 41 1c    	movbe  ax,WORD PTR [rcx+0x1c]
  a2:	0f b7 c0             	movzx  eax,ax
  a5:	3d 00 08 00 00       	cmp    eax,0x800
  aa:	75 6c                	jne    0x118
  ac:	48 8d 41 32          	lea    rax,[rcx+0x32]
  b0:	4c 39 c8             	cmp    rax,r9
  b3:	77 63                	ja     0x118
  b5:	66 0f 38 f0 41 1a    	movbe  ax,WORD PTR [rcx+0x1a]
  bb:	44 0f b7 c0          	movzx  r8d,ax
  bf:	bf 02 00 00 00       	mov    edi,0x2
  c4:	eb 16                	jmp    0xdc
  c6:	31 f6                	xor    esi,esi
  c8:	48 89 c7             	mov    rdi,rax
  cb:	4c 8d 52 14          	lea    r10,[rdx+0x14]
  cf:	31 c0                	xor    eax,eax
  d1:	41 b8 00 00 00 00    	mov    r8d,0x0
  d7:	4d 39 ca             	cmp    r10,r9
  da:	77 3e                	ja     0x11a
  dc:	44 0f b6 12          	movzx  r10d,BYTE PTR [rdx]
  e0:	44 89 d0             	mov    eax,r10d
  e3:	83 e0 f0             	and    eax,0xfffffff0
  e6:	83 f8 40             	cmp    eax,0x40
  e9:	75 2d                	jne    0x118
  eb:	41 83 e2 0f          	and    r10d,0xf
  ef:	49 83 fa 05          	cmp    r10,0x5
  f3:	72 23                	jb     0x118
  f5:	4a 8d 1c 92          	lea    rbx,[rdx+r10*4]
  f9:	4c 39 cb             	cmp    rbx,r9
  fc:	77 1a                	ja     0x118
  fe:	80 7a 09 06          	cmp    BYTE PTR [rdx+0x9],0x6
 102:	75 14                	jne    0x118
 104:	4c 8d 73 14          	lea    r14,[rbx+0x14]
 108:	4d 39 ce             	cmp    r14,r9
 10b:	77 0b                	ja     0x118
 10d:	44 0f b6 5b 0c       	movzx  r11d,BYTE PTR [rbx+0xc]
 112:	49 83 fb 50          	cmp    r11,0x50
 116:	73 10                	jae    0x128
 118:	31 c0                	xor    eax,eax
 11a:	5b                   	pop    rbx
 11b:	41 5e                	pop    r14
 11d:	41 5f                	pop    r15
 11f:	5d                   	pop    rbp
 120:	c3                   	ret
 121:	b8 01 00 00 00       	mov    eax,0x1
 126:	eb a0                	jmp    0xc8
 128:	41 c1 eb 02          	shr    r11d,0x2
 12c:	41 83 e3 fc          	and    r11d,0xfffffffc
 130:	4e 8d 3c 1b          	lea    r15,[rbx+r11*1]
 134:	31 c0                	xor    eax,eax
 136:	4d 39 cf             	cmp    r15,r9
 139:	77 df                	ja     0x11a
 13b:	41 80 fb 20          	cmp    r11b,0x20
 13f:	72 d9                	jb     0x11a
 141:	41 80 3e 02          	cmp    BYTE PTR [r14],0x2
 145:	75 d1                	jne    0x118
 147:	80 7b 15 04          	cmp    BYTE PTR [rbx+0x15],0x4
 14b:	72 cb                	jb     0x118
 14d:	80 7b 18 01          	cmp    BYTE PTR [rbx+0x18],0x1
 151:	75 c5                	jne    0x118
 153:	80 7b 19 03          	cmp    BYTE PTR [rbx+0x19],0x3
 157:	75 bf                	jne    0x118
 159:	80 7b 1a 03          	cmp    BYTE PTR [rbx+0x1a],0x3
 15d:	72 b9                	jb     0x118
 15f:	80 7b 1c 04          	cmp    BYTE PTR [rbx+0x1c],0x4
 163:	75 b3                	jne    0x118
 165:	80 7b 1d 02          	cmp    BYTE PTR [rbx+0x1d],0x2
 169:	72 ad                	jb     0x118
 16b:	80 7b 1e 01          	cmp    BYTE PTR [rbx+0x1e],0x1
 16f:	75 a7                	jne    0x118
 171:	66 0f 38 f0 42 02    	movbe  ax,WORD PTR [rdx+0x2]
 177:	0f b7 c0             	movzx  eax,ax
 17a:	44 0f 38 f0 4a 10    	movbe  r9d,DWORD PTR [rdx+0x10]
 180:	66 42 0f 38 f0 5c 92 	movbe  bx,WORD PTR [rdx+r10*4+0x2]
 187:	02 
 188:	44 0f 38 f0 72 0c    	movbe  r14d,DWORD PTR [rdx+0xc]
 18e:	0f b7 db             	movzx  ebx,bx
 191:	66 42 0f 38 f0 2c 92 	movbe  bp,WORD PTR [rdx+r10*4]
 198:	48 01 c3             	add    rbx,rax
 19b:	0f b7 c5             	movzx  eax,bp
 19e:	48 01 d8             	add    rax,rbx
 1a1:	4c 31 f0             	xor    rax,r14
 1a4:	4c 01 c8             	add    rax,r9
 1a7:	46 0f b6 4c 92 16    	movzx  r9d,BYTE PTR [rdx+r10*4+0x16]
 1ad:	44 89 cb             	mov    ebx,r9d
 1b0:	c1 e3 08             	shl    ebx,0x8
 1b3:	46 0f b6 74 92 17    	movzx  r14d,BYTE PTR [rdx+r10*4+0x17]
 1b9:	44 09 f3             	or     ebx,r14d
 1bc:	48 83 c3 02          	add    rbx,0x2
 1c0:	41 c1 e1 10          	shl    r9d,0x10
 1c4:	49 31 d9             	xor    r9,rbx
 1c7:	41 c1 e6 18          	shl    r14d,0x18
 1cb:	4b 8d 1c 31          	lea    rbx,[r9+r14*1]
 1cf:	48 81 c3 00 01 03 00 	add    rbx,0x30100
 1d6:	46 0f b6 4c 92 1b    	movzx  r9d,BYTE PTR [rdx+r10*4+0x1b]
 1dc:	4d 89 ce             	mov    r14,r9
 1df:	49 c1 e6 20          	shl    r14,0x20
 1e3:	41 c1 e1 10          	shl    r9d,0x10
 1e7:	4d 09 f1             	or     r9,r14
 1ea:	49 31 d9             	xor    r9,rbx
 1ed:	c1 e6 10             	shl    esi,0x10
 1f0:	4c 09 c6             	or     rsi,r8
 1f3:	48 31 c6             	xor    rsi,rax
 1f6:	44 89 d0             	mov    eax,r10d
 1f9:	c1 e0 0a             	shl    eax,0xa
 1fc:	49 89 f8             	mov    r8,rdi
 1ff:	49 c1 e0 28          	shl    r8,0x28
 203:	49 09 c0             	or     r8,rax
 206:	4d 09 d8             	or     r8,r11
 209:	49 bb 00 00 00 00 06 	movabs r11,0x600000000
 210:	00 00 00 
 213:	4d 01 c3             	add    r11,r8
 216:	49 01 f3             	add    r11,rsi
 219:	42 0f b6 44 92 1f    	movzx  eax,BYTE PTR [rdx+r10*4+0x1f]
 21f:	48 c1 e0 28          	shl    rax,0x28
 223:	4c 09 c8             	or     rax,r9
 226:	48 ba 00 00 00 44 01 	movabs rdx,0x144000000
 22d:	00 00 00 
 230:	48 01 c2             	add    rdx,rax
 233:	40 80 c7 05          	add    dil,0x5
 237:	c4 e2 c1 f7 c2       	shlx   rax,rdx,rdi
 23c:	4c 31 d8             	xor    rax,r11
 23f:	c6 41 07 00          	mov    BYTE PTR [rcx+0x7],0x0
 243:	48 89 c2             	mov    rdx,rax
 246:	48 c1 ea 30          	shr    rdx,0x30
 24a:	88 51 06             	mov    BYTE PTR [rcx+0x6],dl
 24d:	48 89 c2             	mov    rdx,rax
 250:	48 c1 ea 28          	shr    rdx,0x28
 254:	88 51 05             	mov    BYTE PTR [rcx+0x5],dl
 257:	48 89 c2             	mov    rdx,rax
 25a:	48 c1 ea 20          	shr    rdx,0x20
 25e:	88 51 04             	mov    BYTE PTR [rcx+0x4],dl
 261:	89 c2                	mov    edx,eax
 263:	c1 ea 18             	shr    edx,0x18
 266:	88 51 03             	mov    BYTE PTR [rcx+0x3],dl
 269:	89 c2                	mov    edx,eax
 26b:	c1 ea 10             	shr    edx,0x10
 26e:	88 51 02             	mov    BYTE PTR [rcx+0x2],dl
 271:	88 01                	mov    BYTE PTR [rcx],al
 273:	88 61 01             	mov    BYTE PTR [rcx+0x1],ah
 276:	b8 02 00 00 00       	mov    eax,0x2
 27b:	e9 9a fe ff ff       	jmp    0x11a
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * Semantic handcraft for packet_vlan_tcpopt_parser.
 *
 * The native x86 body uses more simultaneously-live host scratch registers
 * than verifier-visible BPF can represent without hidden state. This input
 * therefore starts from the verified kernel xlated BPF and replaces same-PC-count
 * mov+add address calculations with x86 leaq kinsns. Branch offsets stay valid.
 */

static const struct bpf_insn program[] = {
    HC_RAW(0xb7, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 0),
    HC_LDX(BPF_W, BPF_REG_8, BPF_REG_1, 4),
    HC_RAW(0x2d, BPF_REG_2, BPF_REG_8, 51, 0),
    /* pc 4: r1 = r2; r1 += 8; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_1, BPF_REG_8, 48, 0),
    /* pc 7: r5 = r2; r5 += 22; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_5, BPF_REG_8, 45, 0),
    HC_RAW(0x71, BPF_REG_1, BPF_REG_2, 21, 0),
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 20, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_1, 0, 0),
    HC_RAW(0xb7, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0x57, BPF_REG_6, BPF_REG_0, 0, 65535),
    HC_RAW(0xb7, BPF_REG_1, BPF_REG_0, 0, 0),
    HC_RAW(0xb7, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, 37, 2048),
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, 1, 34984),
    HC_RAW(0x55, BPF_REG_6, BPF_REG_0, 34, 33024),
    /* pc 21: r5 = r2; r5 += 26; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 26), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_5, BPF_REG_8, 31, 0),
    HC_RAW(0x71, BPF_REG_1, BPF_REG_2, 22, 0),
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_4, BPF_REG_2, 23, 0),
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_4, 0, 0),
    HC_RAW(0x71, BPF_REG_4, BPF_REG_2, 25, 0),
    HC_RAW(0x71, BPF_REG_6, BPF_REG_2, 24, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_4, 0, 0),
    HC_RAW(0xb7, BPF_REG_4, BPF_REG_0, 0, 1),
    HC_RAW(0x57, BPF_REG_6, BPF_REG_0, 0, 65535),
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, 21, 2048),
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, 1, 34984),
    HC_RAW(0x55, BPF_REG_6, BPF_REG_0, 18, 33024),
    /* pc 37: r5 = r2; r5 += 30; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_2, 0, 0, 1, 0, 30), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_5, BPF_REG_8, 15, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 28, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_4, BPF_REG_2, 29, 0),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0x57, BPF_REG_3, BPF_REG_0, 0, 65535),
    HC_RAW(0x55, BPF_REG_3, BPF_REG_0, 9, 2048),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_2, 26, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_4, BPF_REG_2, 27, 0),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0xb7, BPF_REG_4, BPF_REG_0, 0, 2),
    /* pc 51: r6 = r2; r6 += 50; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_6, BPF_REG_2, 0, 0, 1, 0, 50), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_6, BPF_REG_8, 1, 0),
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, 4, 0),
    HC_RAW(0x95, BPF_REG_0, BPF_REG_0, 0, 0),
    /* pc 56: r6 = r5; r6 += 20; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_6, BPF_REG_5, 0, 0, 1, 0, 20), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_6, BPF_REG_8, -4, 0),
    HC_RAW(0x71, BPF_REG_6, BPF_REG_5, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_6, 0, 0),
    HC_RAW(0x57, BPF_REG_7, BPF_REG_0, 0, 240),
    HC_RAW(0x55, BPF_REG_7, BPF_REG_0, -8, 64),
    HC_RAW(0x57, BPF_REG_6, BPF_REG_0, 0, 15),
    HC_RAW(0xb7, BPF_REG_7, BPF_REG_0, 0, 5),
    HC_RAW(0x2d, BPF_REG_7, BPF_REG_6, -11, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 2),
    /* pc 67: r7 = r5; r7 += r6; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_5, BPF_REG_6, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_7, -8, 0),
    HC_RAW(0x2d, BPF_REG_7, BPF_REG_8, -16, 0),
    HC_RAW(0x71, BPF_REG_9, BPF_REG_5, 9, 0),
    HC_RAW(0x55, BPF_REG_9, BPF_REG_0, -18, 6),
    HC_RAW(0x79, BPF_REG_9, BPF_REG_10, -8, 0),
    HC_RAW(0x07, BPF_REG_9, BPF_REG_0, 0, 20),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_9, -24, 0),
    HC_RAW(0x2d, BPF_REG_9, BPF_REG_8, -22, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_7, BPF_REG_7, 12, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_7, -16, 0),
    HC_RAW(0xb7, BPF_REG_9, BPF_REG_0, 0, 80),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -16, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -16, 0),
    HC_RAW(0x2d, BPF_REG_9, BPF_REG_7, -29, 0),
    HC_RAW(0x79, BPF_REG_9, BPF_REG_10, -16, 0),
    HC_RAW(0x77, BPF_REG_9, BPF_REG_0, 0, 2),
    HC_RAW(0x57, BPF_REG_9, BPF_REG_0, 0, 60),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_9, 0, 0),
    HC_RAW(0x79, BPF_REG_9, BPF_REG_10, -8, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_7, -16, 0),
    HC_RAW(0x0f, BPF_REG_9, BPF_REG_7, 0, 0),
    HC_RAW(0x2d, BPF_REG_9, BPF_REG_8, -37, 0),
    HC_RAW(0x79, BPF_REG_9, BPF_REG_10, -8, 0),
    HC_RAW(0x07, BPF_REG_9, BPF_REG_0, 0, 32),
    HC_RAW(0x2d, BPF_REG_9, BPF_REG_8, -40, 0),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 32),
    HC_RAW(0x79, BPF_REG_9, BPF_REG_10, -16, 0),
    HC_RAW(0x2d, BPF_REG_8, BPF_REG_9, -43, 0),
    HC_RAW(0x79, BPF_REG_8, BPF_REG_10, -24, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_8, 0, 0),
    HC_RAW(0x55, BPF_REG_8, BPF_REG_0, -46, 2),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 21, 0),
    HC_RAW(0xb7, BPF_REG_9, BPF_REG_0, 0, 4),
    HC_RAW(0x2d, BPF_REG_9, BPF_REG_8, -50, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 24, 0),
    HC_RAW(0x55, BPF_REG_8, BPF_REG_0, -53, 1),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 25, 0),
    HC_RAW(0x55, BPF_REG_8, BPF_REG_0, -56, 3),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 26, 0),
    HC_RAW(0xb7, BPF_REG_9, BPF_REG_0, 0, 3),
    HC_RAW(0x2d, BPF_REG_9, BPF_REG_8, -60, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 28, 0),
    HC_RAW(0x55, BPF_REG_8, BPF_REG_0, -63, 4),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 29, 0),
    HC_RAW(0xb7, BPF_REG_9, BPF_REG_0, 0, 2),
    HC_RAW(0x2d, BPF_REG_9, BPF_REG_8, -67, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 30, 0),
    HC_RAW(0x55, BPF_REG_8, BPF_REG_0, -70, 1),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 16, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 24),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_5, 17, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_0, 0, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 18, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_0, 0, 0),
    HC_RAW(0x71, BPF_REG_9, BPF_REG_5, 2, 0),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 3, 0),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_9, -32, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 19, 0),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_8, -24, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 12, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 24),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_5, 13, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_0, 0, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_5, 14, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_0, 0, 0),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_5, 15, 0),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_5, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_8, -40, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_7, 2, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_7, 3, 0),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_5, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_0, -48, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_7, 0, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_7, 1, 0),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_5, 0, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 23, 0),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_7, 22, 0),
    HC_RAW(0xbf, BPF_REG_9, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_8, 0, 0),
    HC_RAW(0x07, BPF_REG_9, BPF_REG_0, 0, 2),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 16),
    HC_RAW(0xaf, BPF_REG_9, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 24),
    HC_RAW(0x0f, BPF_REG_9, BPF_REG_8, 0, 0),
    HC_RAW(0x07, BPF_REG_9, BPF_REG_0, 0, 196864),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_7, 27, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_8, 0, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 32),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_9, 0, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 16),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_8, 0, 0),
    HC_RAW(0x57, BPF_REG_1, BPF_REG_0, 0, 65535),
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -32, 0),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -48, 0),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -40, 0),
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -24, 0),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_3, 0, 0),
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_1, 0, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8),
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_4, 0, 0),
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 40),
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_6, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -16, 0),
    HC_RAW(0x4f, BPF_REG_1, BPF_REG_3, 0, 0),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_1, 0, 0),
    HC_RAW(0x18, BPF_REG_1, BPF_REG_0, 0, 0),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_1, 0, 0),
    HC_RAW(0x71, BPF_REG_1, BPF_REG_7, 31, 0),
    HC_RAW(0x67, BPF_REG_1, BPF_REG_0, 0, 40),
    HC_RAW(0x4f, BPF_REG_5, BPF_REG_1, 0, 0),
    HC_RAW(0x18, BPF_REG_1, BPF_REG_0, 0, 1140850688),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 1),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_1, 0, 0),
    HC_RAW(0x07, BPF_REG_4, BPF_REG_0, 0, 5),
    HC_RAW(0x6f, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_0, 0, 0),
    HC_RAW(0xb7, BPF_REG_1, BPF_REG_0, 0, 0),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_1, 7, 0),
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 48),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_1, 6, 0),
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 40),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_1, 5, 0),
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 32),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_1, 4, 0),
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 24),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_1, 3, 0),
    HC_RAW(0xbf, BPF_REG_1, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_1, BPF_REG_0, 0, 16),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_1, 2, 0),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 8),
    HC_RAW(0x73, BPF_REG_2, BPF_REG_5, 1, 0),
    HC_RAW(0xb7, BPF_REG_0, BPF_REG_0, 0, 2),
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, -177, 0),
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
   c:	48 81 ec 30 00 00 00 	sub    rsp,0x30
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 00          	mov    rsi,QWORD PTR [rdi+0x0]
  20:	4c 8b 77 08          	mov    r14,QWORD PTR [rdi+0x8]
  24:	4c 39 f6             	cmp    rsi,r14
  27:	0f 87 fc 00 00 00    	ja     0x129
  2d:	48 8d 7e 08          	lea    rdi,[rsi+0x8]
  31:	4c 39 f7             	cmp    rdi,r14
  34:	0f 87 ef 00 00 00    	ja     0x129
  3a:	4c 8d 46 16          	lea    r8,[rsi+0x16]
  3e:	4d 39 f0             	cmp    r8,r14
  41:	0f 87 e2 00 00 00    	ja     0x129
  47:	48 0f b6 7e 15       	movzx  rdi,BYTE PTR [rsi+0x15]
  4c:	48 0f b6 5e 14       	movzx  rbx,BYTE PTR [rsi+0x14]
  51:	48 c1 e3 08          	shl    rbx,0x8
  55:	48 09 fb             	or     rbx,rdi
  58:	31 d2                	xor    edx,edx
  5a:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
  61:	31 ff                	xor    edi,edi
  63:	31 c9                	xor    ecx,ecx
  65:	48 81 fb 00 08 00 00 	cmp    rbx,0x800
  6c:	0f 84 c0 00 00 00    	je     0x132
  72:	48 81 fb a8 88 00 00 	cmp    rbx,0x88a8
  79:	74 0d                	je     0x88
  7b:	48 81 fb 00 81 00 00 	cmp    rbx,0x8100
  82:	0f 85 a1 00 00 00    	jne    0x129
  88:	4c 8d 46 1a          	lea    r8,[rsi+0x1a]
  8c:	4d 39 f0             	cmp    r8,r14
  8f:	0f 87 94 00 00 00    	ja     0x129
  95:	48 0f b6 7e 16       	movzx  rdi,BYTE PTR [rsi+0x16]
  9a:	48 c1 e7 08          	shl    rdi,0x8
  9e:	48 0f b6 4e 17       	movzx  rcx,BYTE PTR [rsi+0x17]
  a3:	48 09 cf             	or     rdi,rcx
  a6:	48 0f b6 4e 19       	movzx  rcx,BYTE PTR [rsi+0x19]
  ab:	48 0f b6 5e 18       	movzx  rbx,BYTE PTR [rsi+0x18]
  b0:	48 c1 e3 08          	shl    rbx,0x8
  b4:	48 09 cb             	or     rbx,rcx
  b7:	b9 01 00 00 00       	mov    ecx,0x1
  bc:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
  c3:	48 81 fb 00 08 00 00 	cmp    rbx,0x800
  ca:	74 66                	je     0x132
  cc:	48 81 fb a8 88 00 00 	cmp    rbx,0x88a8
  d3:	74 09                	je     0xde
  d5:	48 81 fb 00 81 00 00 	cmp    rbx,0x8100
  dc:	75 4b                	jne    0x129
  de:	4c 8d 46 1e          	lea    r8,[rsi+0x1e]
  e2:	4d 39 f0             	cmp    r8,r14
  e5:	77 42                	ja     0x129
  e7:	48 0f b6 56 1c       	movzx  rdx,BYTE PTR [rsi+0x1c]
  ec:	48 c1 e2 08          	shl    rdx,0x8
  f0:	48 0f b6 4e 1d       	movzx  rcx,BYTE PTR [rsi+0x1d]
  f5:	48 09 ca             	or     rdx,rcx
  f8:	48 81 e2 ff ff 00 00 	and    rdx,0xffff
  ff:	48 81 fa 00 08 00 00 	cmp    rdx,0x800
 106:	75 21                	jne    0x129
 108:	48 0f b6 56 1a       	movzx  rdx,BYTE PTR [rsi+0x1a]
 10d:	48 c1 e2 08          	shl    rdx,0x8
 111:	48 0f b6 4e 1b       	movzx  rcx,BYTE PTR [rsi+0x1b]
 116:	48 09 ca             	or     rdx,rcx
 119:	b9 02 00 00 00       	mov    ecx,0x2
 11e:	48 8d 5e 32          	lea    rbx,[rsi+0x32]
 122:	4c 39 f3             	cmp    rbx,r14
 125:	77 02                	ja     0x129
 127:	eb 12                	jmp    0x13b
 129:	41 5f                	pop    r15
 12b:	41 5e                	pop    r14
 12d:	41 5d                	pop    r13
 12f:	5b                   	pop    rbx
 130:	c9                   	leave
 131:	c3                   	ret
 132:	49 8d 58 14          	lea    rbx,[r8+0x14]
 136:	4c 39 f3             	cmp    rbx,r14
 139:	77 ee                	ja     0x129
 13b:	49 0f b6 58 00       	movzx  rbx,BYTE PTR [r8+0x0]
 140:	49 89 dd             	mov    r13,rbx
 143:	49 81 e5 f0 00 00 00 	and    r13,0xf0
 14a:	49 83 fd 40          	cmp    r13,0x40
 14e:	75 d9                	jne    0x129
 150:	48 83 e3 0f          	and    rbx,0xf
 154:	41 bd 05 00 00 00    	mov    r13d,0x5
 15a:	49 39 dd             	cmp    r13,rbx
 15d:	77 ca                	ja     0x129
 15f:	48 c1 e3 02          	shl    rbx,0x2
 163:	4d 8d 2c 18          	lea    r13,[r8+rbx*1]
 167:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 16b:	4d 39 f5             	cmp    r13,r14
 16e:	77 b9                	ja     0x129
 170:	4d 0f b6 78 09       	movzx  r15,BYTE PTR [r8+0x9]
 175:	49 83 ff 06          	cmp    r15,0x6
 179:	75 ae                	jne    0x129
 17b:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
 17f:	49 83 c7 14          	add    r15,0x14
 183:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 187:	4d 39 f7             	cmp    r15,r14
 18a:	77 9d                	ja     0x129
 18c:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 190:	4d 0f b6 6d 0c       	movzx  r13,BYTE PTR [r13+0xc]
 195:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 199:	41 bf 50 00 00 00    	mov    r15d,0x50
 19f:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1a3:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1a7:	4d 39 ef             	cmp    r15,r13
 1aa:	0f 87 79 ff ff ff    	ja     0x129
 1b0:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 1b4:	49 c1 ef 02          	shr    r15,0x2
 1b8:	49 83 e7 3c          	and    r15,0x3c
 1bc:	4d 89 fd             	mov    r13,r15
 1bf:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
 1c3:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 1c7:	4d 01 ef             	add    r15,r13
 1ca:	4d 39 f7             	cmp    r15,r14
 1cd:	0f 87 56 ff ff ff    	ja     0x129
 1d3:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
 1d7:	49 83 c7 20          	add    r15,0x20
 1db:	4d 39 f7             	cmp    r15,r14
 1de:	0f 87 45 ff ff ff    	ja     0x129
 1e4:	41 be 20 00 00 00    	mov    r14d,0x20
 1ea:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
 1ee:	4d 39 fe             	cmp    r14,r15
 1f1:	0f 87 32 ff ff ff    	ja     0x129
 1f7:	4c 8b 75 e8          	mov    r14,QWORD PTR [rbp-0x18]
 1fb:	4d 0f b6 76 00       	movzx  r14,BYTE PTR [r14+0x0]
 200:	49 83 fe 02          	cmp    r14,0x2
 204:	0f 85 1f ff ff ff    	jne    0x129
 20a:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 20e:	4d 0f b6 75 15       	movzx  r14,BYTE PTR [r13+0x15]
 213:	41 bf 04 00 00 00    	mov    r15d,0x4
 219:	4d 39 f7             	cmp    r15,r14
 21c:	0f 87 07 ff ff ff    	ja     0x129
 222:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 226:	4d 0f b6 75 18       	movzx  r14,BYTE PTR [r13+0x18]
 22b:	49 83 fe 01          	cmp    r14,0x1
 22f:	0f 85 f4 fe ff ff    	jne    0x129
 235:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 239:	4d 0f b6 75 19       	movzx  r14,BYTE PTR [r13+0x19]
 23e:	49 83 fe 03          	cmp    r14,0x3
 242:	0f 85 e1 fe ff ff    	jne    0x129
 248:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 24c:	4d 0f b6 75 1a       	movzx  r14,BYTE PTR [r13+0x1a]
 251:	41 bf 03 00 00 00    	mov    r15d,0x3
 257:	4d 39 f7             	cmp    r15,r14
 25a:	0f 87 c9 fe ff ff    	ja     0x129
 260:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 264:	4d 0f b6 75 1c       	movzx  r14,BYTE PTR [r13+0x1c]
 269:	49 83 fe 04          	cmp    r14,0x4
 26d:	0f 85 b6 fe ff ff    	jne    0x129
 273:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 277:	4d 0f b6 75 1d       	movzx  r14,BYTE PTR [r13+0x1d]
 27c:	41 bf 02 00 00 00    	mov    r15d,0x2
 282:	4d 39 f7             	cmp    r15,r14
 285:	0f 87 9e fe ff ff    	ja     0x129
 28b:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 28f:	4d 0f b6 75 1e       	movzx  r14,BYTE PTR [r13+0x1e]
 294:	49 83 fe 01          	cmp    r14,0x1
 298:	0f 85 8b fe ff ff    	jne    0x129
 29e:	49 0f b6 40 10       	movzx  rax,BYTE PTR [r8+0x10]
 2a3:	48 c1 e0 18          	shl    rax,0x18
 2a7:	4d 0f b6 70 11       	movzx  r14,BYTE PTR [r8+0x11]
 2ac:	49 c1 e6 10          	shl    r14,0x10
 2b0:	49 09 c6             	or     r14,rax
 2b3:	49 0f b6 40 12       	movzx  rax,BYTE PTR [r8+0x12]
 2b8:	48 c1 e0 08          	shl    rax,0x8
 2bc:	49 09 c6             	or     r14,rax
 2bf:	4d 0f b6 78 02       	movzx  r15,BYTE PTR [r8+0x2]
 2c4:	49 c1 e7 08          	shl    r15,0x8
 2c8:	49 0f b6 40 03       	movzx  rax,BYTE PTR [r8+0x3]
 2cd:	49 09 c7             	or     r15,rax
 2d0:	4c 89 7d e0          	mov    QWORD PTR [rbp-0x20],r15
 2d4:	49 0f b6 40 13       	movzx  rax,BYTE PTR [r8+0x13]
 2d9:	49 09 c6             	or     r14,rax
 2dc:	4c 89 75 e8          	mov    QWORD PTR [rbp-0x18],r14
 2e0:	49 0f b6 40 0c       	movzx  rax,BYTE PTR [r8+0xc]
 2e5:	48 c1 e0 18          	shl    rax,0x18
 2e9:	4d 0f b6 70 0d       	movzx  r14,BYTE PTR [r8+0xd]
 2ee:	49 c1 e6 10          	shl    r14,0x10
 2f2:	49 09 c6             	or     r14,rax
 2f5:	49 0f b6 40 0e       	movzx  rax,BYTE PTR [r8+0xe]
 2fa:	48 c1 e0 08          	shl    rax,0x8
 2fe:	49 09 c6             	or     r14,rax
 301:	4d 0f b6 40 0f       	movzx  r8,BYTE PTR [r8+0xf]
 306:	4d 09 c6             	or     r14,r8
 309:	4c 89 75 d8          	mov    QWORD PTR [rbp-0x28],r14
 30d:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 311:	49 0f b6 45 02       	movzx  rax,BYTE PTR [r13+0x2]
 316:	48 c1 e0 08          	shl    rax,0x8
 31a:	4d 0f b6 45 03       	movzx  r8,BYTE PTR [r13+0x3]
 31f:	4c 09 c0             	or     rax,r8
 322:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
 326:	49 0f b6 45 00       	movzx  rax,BYTE PTR [r13+0x0]
 32b:	48 c1 e0 08          	shl    rax,0x8
 32f:	4d 0f b6 45 01       	movzx  r8,BYTE PTR [r13+0x1]
 334:	4c 09 c0             	or     rax,r8
 337:	4d 0f b6 75 17       	movzx  r14,BYTE PTR [r13+0x17]
 33c:	4d 0f b6 45 16       	movzx  r8,BYTE PTR [r13+0x16]
 341:	4d 89 c7             	mov    r15,r8
 344:	49 c1 e7 08          	shl    r15,0x8
 348:	4d 09 f7             	or     r15,r14
 34b:	49 83 c7 02          	add    r15,0x2
 34f:	49 c1 e0 10          	shl    r8,0x10
 353:	4d 31 c7             	xor    r15,r8
 356:	49 c1 e6 18          	shl    r14,0x18
 35a:	4d 01 f7             	add    r15,r14
 35d:	49 81 c7 00 01 03 00 	add    r15,0x30100
 364:	4d 0f b6 75 1b       	movzx  r14,BYTE PTR [r13+0x1b]
 369:	4d 89 f0             	mov    r8,r14
 36c:	49 c1 e0 20          	shl    r8,0x20
 370:	4d 31 f8             	xor    r8,r15
 373:	49 c1 e6 10          	shl    r14,0x10
 377:	4d 31 f0             	xor    r8,r14
 37a:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 381:	48 c1 e7 10          	shl    rdi,0x10
 385:	48 09 d7             	or     rdi,rdx
 388:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 38c:	48 01 d0             	add    rax,rdx
 38f:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 393:	48 01 d0             	add    rax,rdx
 396:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
 39a:	48 31 d0             	xor    rax,rdx
 39d:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 3a1:	48 01 d0             	add    rax,rdx
 3a4:	48 31 f8             	xor    rax,rdi
 3a7:	48 c1 e3 08          	shl    rbx,0x8
 3ab:	48 89 cf             	mov    rdi,rcx
 3ae:	48 c1 e7 28          	shl    rdi,0x28
 3b2:	48 09 df             	or     rdi,rbx
 3b5:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
 3b9:	48 09 d7             	or     rdi,rdx
 3bc:	48 01 f8             	add    rax,rdi
 3bf:	48 bf 00 00 00 00 06 	movabs rdi,0x600000000
 3c6:	00 00 00 
 3c9:	48 01 f8             	add    rax,rdi
 3cc:	49 0f b6 7d 1f       	movzx  rdi,BYTE PTR [r13+0x1f]
 3d1:	48 c1 e7 28          	shl    rdi,0x28
 3d5:	49 09 f8             	or     r8,rdi
 3d8:	48 bf 00 00 00 44 01 	movabs rdi,0x144000000
 3df:	00 00 00 
 3e2:	49 01 f8             	add    r8,rdi
 3e5:	48 83 c1 05          	add    rcx,0x5
 3e9:	49 d3 e0             	shl    r8,cl
 3ec:	49 31 c0             	xor    r8,rax
 3ef:	31 ff                	xor    edi,edi
 3f1:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3f5:	4c 89 c7             	mov    rdi,r8
 3f8:	48 c1 ef 30          	shr    rdi,0x30
 3fc:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 400:	4c 89 c7             	mov    rdi,r8
 403:	48 c1 ef 28          	shr    rdi,0x28
 407:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 40b:	4c 89 c7             	mov    rdi,r8
 40e:	48 c1 ef 20          	shr    rdi,0x20
 412:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 416:	4c 89 c7             	mov    rdi,r8
 419:	48 c1 ef 18          	shr    rdi,0x18
 41d:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 421:	4c 89 c7             	mov    rdi,r8
 424:	48 c1 ef 10          	shr    rdi,0x10
 428:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 42c:	44 88 46 00          	mov    BYTE PTR [rsi+0x0],r8b
 430:	49 c1 e8 08          	shr    r8,0x8
 434:	44 88 46 01          	mov    BYTE PTR [rsi+0x1],r8b
 438:	b8 02 00 00 00       	mov    eax,0x2
 43d:	e9 e7 fc ff ff       	jmp    0x129
```
