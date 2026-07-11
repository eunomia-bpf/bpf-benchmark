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

0000000000001368 <_fini>:
    1368:	f3 0f 1e fa          	endbr64
    136c:	48 83 ec 08          	sub    rsp,0x8
    1370:	48 83 c4 08          	add    rsp,0x8
    1374:	c3                   	ret
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
#define HC_LEA_ARCH_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | (1ULL << 48))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    r10,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rdx,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (172) - 1, 0),
    /* 0x1112: lea    rcx,[rdx+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1116: cmp    rcx,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1119: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (165) - 1, 0),
    /* 0x111f: lea    r9,[rdx+0x16] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R9, HC_X86_RDX, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1123: cmp    r9,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1126: ja     1244 <packet_vlan_tcpopt_parser_xdp+0x144> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (158) - 1, 0),
    /* 0x112c: push   rbp [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112d: push   r15 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x112f: push   r14 [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   rbx [exact-kop: pushq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1132: movzx  eax,WORD PTR [rdx+0x14] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_RDX, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1136: rol    ax,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RAX, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x113a: movzx  ecx,ax [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x113d: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x113f: cmp    ecx,0x800 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1145: je     11df <packet_vlan_tcpopt_parser_xdp+0xdf> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (67) - 1, 2048),
    /* 0x114b: cmp    ecx,0x88a8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1151: je     115f <packet_vlan_tcpopt_parser_xdp+0x5f> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (4) - 1, 34984),
    /* 0x1153: cmp    ecx,0x8100 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1159: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (125) - 1, 33024),
    /* 0x115f: lea    r9,[rdx+0x1a] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R9, HC_X86_RDX, 0, 0, 1, 0, 26), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1163: cmp    r9,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1166: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (118) - 1, 0),
    /* 0x116c: movzx  esi,WORD PTR [rdx+0x16] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RSI, HC_X86_RDX, 22), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1170: movzx  ecx,WORD PTR [rdx+0x18] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 24), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1174: rol    si,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RSI, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1178: rol    cx,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RCX, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x117c: movzx  ecx,cx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x117f: cmp    ecx,0x800 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1185: je     1245 <packet_vlan_tcpopt_parser_xdp+0x145> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (116) - 1, 2048),
    /* 0x118b: cmp    ecx,0x88a8 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1191: je     119f <packet_vlan_tcpopt_parser_xdp+0x9f> [exact-bpf: je as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_6, 0, (4) - 1, 34984),
    /* 0x1193: cmp    ecx,0x8100 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1199: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (99) - 1, 33024),
    /* 0x119f: lea    rcx,[rdx+0x1e] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 0, 0, 1, 0, 30), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11a3: cmp    rcx,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11a6: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (92) - 1, 0),
    /* 0x11ac: movzx  ecx,WORD PTR [rdx+0x1c] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 28), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b0: rol    cx,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RCX, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11b4: movzx  ecx,cx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11b7: cmp    ecx,0x800 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11bd: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (83) - 1, 2048),
    /* 0x11bf: lea    rcx,[rdx+0x32] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 0, 0, 1, 0, 50), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11c3: cmp    rcx,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11c6: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (76) - 1, 0),
    /* 0x11c8: lea    r9,[rdx+0x1e] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R9, HC_X86_RDX, 0, 0, 1, 0, 30), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11cc: movzx  ecx,WORD PTR [rdx+0x1a] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RCX, HC_X86_RDX, 26), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d0: rol    cx,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RCX, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x11d4: movzx  r8d,cx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11d8: mov    ecx,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11dd: jmp    11ef <packet_vlan_tcpopt_parser_xdp+0xef> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (14) - 1, 0),
    /* 0x11df: xor    esi,esi [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e1: xor    ecx,ecx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11e3: lea    rdi,[r9+0x14] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDI, HC_X86_R9, 0, 0, 1, 0, 20), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11e7: cmp    rdi,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11ea: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (54) - 1, 0),
    /* 0x11ec: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11ef: movzx  edi,BYTE PTR [r9] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RDI, HC_X86_R9, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x11f3: mov    r11d,edi [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11f6: and    r11b,0xf0 [exact-kop: andb imm kop] */
    HC_KOP(HC_REG_IMM_PAYLOAD(HC_X86_R11, 240), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x11fa: cmp    r11b,0x40 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11fe: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (42) - 1, 64),
    /* 0x1200: and    edi,0xf [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 15), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1203: cmp    dil,0x5 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1207: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_6, 0, (36) - 1, 5),
    /* 0x1209: lea    rbx,[r9+rdi*4] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RBX, HC_X86_R9, HC_X86_RDI, 2, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x120d: cmp    rbx,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1210: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (29) - 1, 0),
    /* 0x1212: cmp    BYTE PTR [r9+0x9],0x6 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1217: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 9),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (24) - 1, 6),
    /* 0x1219: lea    r14,[rbx+0x14] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R14, HC_X86_RBX, 0, 0, 1, 0, 20), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x121d: cmp    r14,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1220: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (17) - 1, 0),
    /* 0x1222: movzx  r11d,BYTE PTR [rbx+0xc] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R11, HC_X86_RBX, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1227: cmp    r11,0x50 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x122b: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_6, 0, (12) - 1, 80),
    /* 0x122d: shr    r11d,0x2 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, 2), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1231: and    r11d,0xfffffffc [exact-kop: and32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R11, -4), MICRO_HANDCRAFT_BPF_X86_ANDL),
    /* 0x1235: lea    r15,[rbx+r11*1] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R15, HC_X86_RBX, HC_X86_R11, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1239: cmp    r15,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x123c: jbe    124c <packet_vlan_tcpopt_parser_xdp+0x14c> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (15) - 1, 0),
    /* 0x123e: pop    rbx [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x123f: pop    r14 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1241: pop    r15 [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1243: pop    rbp [exact-kop: popq kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1244: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x1245: mov    ecx,0x1 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x124a: jmp    11e3 <packet_vlan_tcpopt_parser_xdp+0xe3> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-73) - 1, 0),
    /* 0x124c: lea    r15,[rbx+0x20] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_R15, HC_X86_RBX, 0, 0, 1, 0, 32), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1250: cmp    r15,r10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1253: ja     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-20) - 1, 0),
    /* 0x1255: cmp    r11b,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1259: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_6, 0, (-24) - 1, 32),
    /* 0x125b: cmp    BYTE PTR [r14],0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x125f: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 0),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-29) - 1, 2),
    /* 0x1261: cmp    BYTE PTR [rbx+0x15],0x4 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1265: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 21),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_6, 0, (-34) - 1, 4),
    /* 0x1267: cmp    BYTE PTR [rbx+0x18],0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x126b: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 24),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-39) - 1, 1),
    /* 0x126d: cmp    BYTE PTR [rbx+0x19],0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1271: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 25),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-44) - 1, 3),
    /* 0x1273: cmp    BYTE PTR [rbx+0x1a],0x3 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1277: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 26),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_6, 0, (-49) - 1, 3),
    /* 0x1279: cmp    BYTE PTR [rbx+0x1c],0x4 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x127d: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 28),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-54) - 1, 4),
    /* 0x127f: cmp    BYTE PTR [rbx+0x1d],0x2 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1283: jb     123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jb as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 29),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JLT | BPF_K, BPF_REG_6, 0, (-59) - 1, 2),
    /* 0x1285: cmp    BYTE PTR [rbx+0x1e],0x1 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1289: jne    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_B, BPF_REG_6, BPF_REG_6, 30),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-64) - 1, 1),
    /* 0x128b: shl    rdi,0x2 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 2), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x128f: movzx  eax,WORD PTR [r9+0x2] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RAX, HC_X86_R9, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1294: rol    ax,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RAX, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x1298: movzx  eax,ax [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x129b: mov    r10d,DWORD PTR [r9+0xc] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R10, HC_X86_R9, 12), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x129f: bswap  r10d [exact-kop: bswap32 kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x12a2: mov    r9d,DWORD PTR [r9+0x10] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12a6: bswap  r9d [exact-kop: bswap32 kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_BSWAPL),
    /* 0x12a9: movzx  ebp,WORD PTR [rbx] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBP, HC_X86_RBX, 0), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12ac: movzx  r14d,WORD PTR [rbx+0x2] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RBX, 2), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12b1: rol    bp,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_RBP, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x12b5: movzx  r15d,bp [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R15, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12b9: add    r15,rax [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R15, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12bc: rol    r14w,0x8 [exact-kop: rolw imm8 kop] */
    HC_KOP(HC_REG_IMM_ARCH_PAYLOAD(HC_X86_R14, 8), MICRO_HANDCRAFT_BPF_X86_ROLW),
    /* 0x12c1: movzx  eax,r14w [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x12c5: add    rax,r15 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R15), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12c8: xor    rax,r10 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12cb: add    rax,r9 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12ce: movzx  r9d,BYTE PTR [rbx+0x16] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R9, HC_X86_RBX, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12d3: mov    r10d,r9d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x12d6: shl    r10d,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12da: movzx  r14d,BYTE PTR [rbx+0x17] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R14, HC_X86_RBX, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x12df: or     r10d,r14d [exact-kop: or32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ORL),
    /* 0x12e2: add    r10,0x2 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12e6: shl    r9d,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12ea: xor    r9,r10 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x12ed: shl    r14d,0x18 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R14, 24), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x12f1: add    r9,r14 [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12f4: add    r9,0x30100 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 196864), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x12fb: movzx  r10d,BYTE PTR [rbx+0x1b] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_R10, HC_X86_RBX, 27), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1300: mov    r14,r10 [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R14, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1303: shl    r14,0x20 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R14, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1307: shl    r10d,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x130b: xor    r10,r14 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R14), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x130e: xor    r10,r9 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1311: movzx  ebx,BYTE PTR [rbx+0x1f] [exact-kop: direct memory load via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_MEM_PAYLOAD(HC_X86_RBX, HC_X86_RBX, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL),
    /* 0x1315: shl    rbx,0x28 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBX, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1319: or     rbx,r10 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RBX, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x131c: movabs r9,0x144000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x144000000ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_R9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1326: add    r9,rbx [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RBX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1329: shl    esi,0x10 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RSI, 16), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x132c: or     rsi,r8 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x132f: xor    rsi,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1332: mov    rax,rcx [exact-kop: mov64 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1335: shl    rax,0x28 [exact-kop: shl64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1339: shl    edi,0x8 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDI, 8), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x133c: or     rdi,rax [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x133f: or     rdi,r11 [exact-kop: or64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1342: movabs rax,0x600000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x600000000ULL),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RAX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x134c: add    rax,rdi [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x134f: add    ecx,0x5 [exact-kop: add32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 5), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1352: rol    r9,cl [exact-kop: rolq cl kop] */
    HC_KOP(HC_ROTATE_ARCH_CL_PAYLOAD(HC_X86_R9, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1355: add    rax,rsi [exact-kop: add64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1358: xor    r9,rax [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x135b: mov    QWORD PTR [rdx],r9 [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_R9, HC_X86_RDX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x135e: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1363: jmp    123e <packet_vlan_tcpopt_parser_xdp+0x13e> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, (-181) - 1, 0),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
