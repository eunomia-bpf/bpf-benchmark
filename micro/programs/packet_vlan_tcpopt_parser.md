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
   c:	48 81 ec 28 00 00 00 	sub    rsp,0x28
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 00          	mov    rsi,QWORD PTR [rdi+0x0]
  20:	4c 8b 7f 08          	mov    r15,QWORD PTR [rdi+0x8]
  24:	4c 39 fe             	cmp    rsi,r15
  27:	0f 87 04 01 00 00    	ja     0x131
  2d:	48 89 f7             	mov    rdi,rsi
  30:	48 83 c7 08          	add    rdi,0x8
  34:	4c 39 ff             	cmp    rdi,r15
  37:	0f 87 f4 00 00 00    	ja     0x131
  3d:	48 89 f1             	mov    rcx,rsi
  40:	48 83 c1 16          	add    rcx,0x16
  44:	4c 39 f9             	cmp    rcx,r15
  47:	0f 87 e4 00 00 00    	ja     0x131
  4d:	48 0f b6 7e 15       	movzx  rdi,BYTE PTR [rsi+0x15]
  52:	4c 0f b6 46 14       	movzx  r8,BYTE PTR [rsi+0x14]
  57:	41 c1 e0 08          	shl    r8d,0x8
  5b:	41 09 f8             	or     r8d,edi
  5e:	31 ff                	xor    edi,edi
  60:	41 81 e0 ff ff 00 00 	and    r8d,0xffff
  67:	31 d2                	xor    edx,edx
  69:	41 81 f8 00 08 00 00 	cmp    r8d,0x800
  70:	0f 84 c4 00 00 00    	je     0x13a
  76:	41 81 f8 a8 88 00 00 	cmp    r8d,0x88a8
  7d:	74 0d                	je     0x8c
  7f:	41 81 f8 00 81 00 00 	cmp    r8d,0x8100
  86:	0f 85 a5 00 00 00    	jne    0x131
  8c:	48 89 f1             	mov    rcx,rsi
  8f:	48 83 c1 1a          	add    rcx,0x1a
  93:	4c 39 f9             	cmp    rcx,r15
  96:	0f 87 95 00 00 00    	ja     0x131
  9c:	48 0f b6 7e 16       	movzx  rdi,BYTE PTR [rsi+0x16]
  a1:	c1 e7 08             	shl    edi,0x8
  a4:	48 0f b6 56 17       	movzx  rdx,BYTE PTR [rsi+0x17]
  a9:	09 d7                	or     edi,edx
  ab:	48 0f b6 56 19       	movzx  rdx,BYTE PTR [rsi+0x19]
  b0:	4c 0f b6 46 18       	movzx  r8,BYTE PTR [rsi+0x18]
  b5:	41 c1 e0 08          	shl    r8d,0x8
  b9:	41 09 d0             	or     r8d,edx
  bc:	ba 01 00 00 00       	mov    edx,0x1
  c1:	41 81 e0 ff ff 00 00 	and    r8d,0xffff
  c8:	41 81 f8 00 08 00 00 	cmp    r8d,0x800
  cf:	74 69                	je     0x13a
  d1:	41 81 f8 a8 88 00 00 	cmp    r8d,0x88a8
  d8:	74 09                	je     0xe3
  da:	41 81 f8 00 81 00 00 	cmp    r8d,0x8100
  e1:	75 4e                	jne    0x131
  e3:	48 89 f1             	mov    rcx,rsi
  e6:	48 83 c1 1e          	add    rcx,0x1e
  ea:	4c 39 f9             	cmp    rcx,r15
  ed:	77 42                	ja     0x131
  ef:	48 0f b6 56 1c       	movzx  rdx,BYTE PTR [rsi+0x1c]
  f4:	c1 e2 08             	shl    edx,0x8
  f7:	4c 0f b6 46 1d       	movzx  r8,BYTE PTR [rsi+0x1d]
  fc:	44 09 c2             	or     edx,r8d
  ff:	81 e2 ff ff 00 00    	and    edx,0xffff
 105:	81 fa 00 08 00 00    	cmp    edx,0x800
 10b:	75 24                	jne    0x131
 10d:	48 0f b6 56 1b       	movzx  rdx,BYTE PTR [rsi+0x1b]
 112:	4c 0f b6 46 1a       	movzx  r8,BYTE PTR [rsi+0x1a]
 117:	49 c1 e0 08          	shl    r8,0x8
 11b:	49 09 d0             	or     r8,rdx
 11e:	ba 02 00 00 00       	mov    edx,0x2
 123:	48 89 f3             	mov    rbx,rsi
 126:	48 83 c3 32          	add    rbx,0x32
 12a:	4c 39 fb             	cmp    rbx,r15
 12d:	77 02                	ja     0x131
 12f:	eb 18                	jmp    0x149
 131:	41 5f                	pop    r15
 133:	41 5e                	pop    r14
 135:	41 5d                	pop    r13
 137:	5b                   	pop    rbx
 138:	c9                   	leave
 139:	c3                   	ret
 13a:	45 31 c0             	xor    r8d,r8d
 13d:	48 89 cb             	mov    rbx,rcx
 140:	48 83 c3 14          	add    rbx,0x14
 144:	4c 39 fb             	cmp    rbx,r15
 147:	77 e8                	ja     0x131
 149:	48 0f b6 59 00       	movzx  rbx,BYTE PTR [rcx+0x0]
 14e:	41 89 dd             	mov    r13d,ebx
 151:	41 81 e5 f0 00 00 00 	and    r13d,0xf0
 158:	41 83 fd 40          	cmp    r13d,0x40
 15c:	75 d3                	jne    0x131
 15e:	83 e3 0f             	and    ebx,0xf
 161:	83 fb 05             	cmp    ebx,0x5
 164:	72 cb                	jb     0x131
 166:	c1 e3 02             	shl    ebx,0x2
 169:	49 89 cd             	mov    r13,rcx
 16c:	49 01 dd             	add    r13,rbx
 16f:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 173:	4d 39 fd             	cmp    r13,r15
 176:	77 b9                	ja     0x131
 178:	4c 0f b6 71 09       	movzx  r14,BYTE PTR [rcx+0x9]
 17d:	41 83 fe 06          	cmp    r14d,0x6
 181:	75 ae                	jne    0x131
 183:	4c 8b 75 f8          	mov    r14,QWORD PTR [rbp-0x8]
 187:	49 83 c6 14          	add    r14,0x14
 18b:	4d 39 fe             	cmp    r14,r15
 18e:	77 a1                	ja     0x131
 190:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 194:	4d 0f b6 6d 0c       	movzx  r13,BYTE PTR [r13+0xc]
 199:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 19d:	41 83 fd 50          	cmp    r13d,0x50
 1a1:	72 8e                	jb     0x131
 1a3:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1a7:	41 c1 ed 02          	shr    r13d,0x2
 1ab:	41 83 e5 3c          	and    r13d,0x3c
 1af:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 1b3:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 1b7:	4c 89 75 e8          	mov    QWORD PTR [rbp-0x18],r14
 1bb:	4c 8b 75 f0          	mov    r14,QWORD PTR [rbp-0x10]
 1bf:	4c 8b 75 f0          	mov    r14,QWORD PTR [rbp-0x10]
 1c3:	4d 01 f5             	add    r13,r14
 1c6:	4c 8b 75 e8          	mov    r14,QWORD PTR [rbp-0x18]
 1ca:	4d 39 fd             	cmp    r13,r15
 1cd:	0f 87 5e ff ff ff    	ja     0x131
 1d3:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 1d7:	49 83 c5 20          	add    r13,0x20
 1db:	4d 39 fd             	cmp    r13,r15
 1de:	0f 87 4d ff ff ff    	ja     0x131
 1e4:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1e8:	41 83 fd 20          	cmp    r13d,0x20
 1ec:	0f 82 3f ff ff ff    	jb     0x131
 1f2:	4d 0f b6 6e 00       	movzx  r13,BYTE PTR [r14+0x0]
 1f7:	41 83 fd 02          	cmp    r13d,0x2
 1fb:	0f 85 30 ff ff ff    	jne    0x131
 201:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 205:	4d 0f b6 6d 15       	movzx  r13,BYTE PTR [r13+0x15]
 20a:	41 83 fd 04          	cmp    r13d,0x4
 20e:	0f 82 1d ff ff ff    	jb     0x131
 214:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 218:	4d 0f b6 6d 18       	movzx  r13,BYTE PTR [r13+0x18]
 21d:	41 83 fd 01          	cmp    r13d,0x1
 221:	0f 85 0a ff ff ff    	jne    0x131
 227:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 22b:	4d 0f b6 6d 19       	movzx  r13,BYTE PTR [r13+0x19]
 230:	41 83 fd 03          	cmp    r13d,0x3
 234:	0f 85 f7 fe ff ff    	jne    0x131
 23a:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 23e:	4d 0f b6 6d 1a       	movzx  r13,BYTE PTR [r13+0x1a]
 243:	41 83 fd 03          	cmp    r13d,0x3
 247:	0f 82 e4 fe ff ff    	jb     0x131
 24d:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 251:	4d 0f b6 6d 1c       	movzx  r13,BYTE PTR [r13+0x1c]
 256:	41 83 fd 04          	cmp    r13d,0x4
 25a:	0f 85 d1 fe ff ff    	jne    0x131
 260:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 264:	4d 0f b6 6d 1d       	movzx  r13,BYTE PTR [r13+0x1d]
 269:	41 83 fd 02          	cmp    r13d,0x2
 26d:	0f 82 be fe ff ff    	jb     0x131
 273:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 277:	4d 0f b6 6d 1e       	movzx  r13,BYTE PTR [r13+0x1e]
 27c:	41 83 fd 01          	cmp    r13d,0x1
 280:	0f 85 ab fe ff ff    	jne    0x131
 286:	48 0f b6 41 10       	movzx  rax,BYTE PTR [rcx+0x10]
 28b:	48 c1 e0 18          	shl    rax,0x18
 28f:	4c 0f b6 69 11       	movzx  r13,BYTE PTR [rcx+0x11]
 294:	49 c1 e5 10          	shl    r13,0x10
 298:	49 09 c5             	or     r13,rax
 29b:	48 0f b6 41 03       	movzx  rax,BYTE PTR [rcx+0x3]
 2a0:	4c 0f b6 71 02       	movzx  r14,BYTE PTR [rcx+0x2]
 2a5:	49 c1 e6 08          	shl    r14,0x8
 2a9:	49 09 c6             	or     r14,rax
 2ac:	4c 89 75 e8          	mov    QWORD PTR [rbp-0x18],r14
 2b0:	48 0f b6 41 0c       	movzx  rax,BYTE PTR [rcx+0xc]
 2b5:	48 c1 e0 18          	shl    rax,0x18
 2b9:	4c 0f b6 79 0d       	movzx  r15,BYTE PTR [rcx+0xd]
 2be:	49 c1 e7 10          	shl    r15,0x10
 2c2:	49 09 c7             	or     r15,rax
 2c5:	48 0f b6 41 12       	movzx  rax,BYTE PTR [rcx+0x12]
 2ca:	48 c1 e0 08          	shl    rax,0x8
 2ce:	49 09 c5             	or     r13,rax
 2d1:	48 0f b6 41 13       	movzx  rax,BYTE PTR [rcx+0x13]
 2d6:	49 09 c5             	or     r13,rax
 2d9:	4c 89 6d e0          	mov    QWORD PTR [rbp-0x20],r13
 2dd:	48 0f b6 41 0e       	movzx  rax,BYTE PTR [rcx+0xe]
 2e2:	48 c1 e0 08          	shl    rax,0x8
 2e6:	49 09 c7             	or     r15,rax
 2e9:	48 0f b6 49 0f       	movzx  rcx,BYTE PTR [rcx+0xf]
 2ee:	49 09 cf             	or     r15,rcx
 2f1:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 2f5:	49 0f b6 4d 03       	movzx  rcx,BYTE PTR [r13+0x3]
 2fa:	49 0f b6 45 02       	movzx  rax,BYTE PTR [r13+0x2]
 2ff:	48 c1 e0 08          	shl    rax,0x8
 303:	48 09 c8             	or     rax,rcx
 306:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
 30a:	49 0f b6 4d 01       	movzx  rcx,BYTE PTR [r13+0x1]
 30f:	49 0f b6 45 00       	movzx  rax,BYTE PTR [r13+0x0]
 314:	48 c1 e0 08          	shl    rax,0x8
 318:	48 09 c8             	or     rax,rcx
 31b:	49 0f b6 4d 17       	movzx  rcx,BYTE PTR [r13+0x17]
 320:	4d 0f b6 6d 16       	movzx  r13,BYTE PTR [r13+0x16]
 325:	4d 89 ee             	mov    r14,r13
 328:	49 c1 e6 08          	shl    r14,0x8
 32c:	49 09 ce             	or     r14,rcx
 32f:	49 83 c6 02          	add    r14,0x2
 333:	49 c1 e5 10          	shl    r13,0x10
 337:	4d 31 ee             	xor    r14,r13
 33a:	48 c1 e1 18          	shl    rcx,0x18
 33e:	49 01 ce             	add    r14,rcx
 341:	49 81 c6 00 01 03 00 	add    r14,0x30100
 348:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 34c:	4c 0f b6 69 1b       	movzx  r13,BYTE PTR [rcx+0x1b]
 351:	4c 89 e9             	mov    rcx,r13
 354:	48 c1 e1 20          	shl    rcx,0x20
 358:	4c 31 f1             	xor    rcx,r14
 35b:	49 c1 e5 10          	shl    r13,0x10
 35f:	4c 31 e9             	xor    rcx,r13
 362:	48 81 e7 ff ff 00 00 	and    rdi,0xffff
 369:	48 c1 e7 10          	shl    rdi,0x10
 36d:	4c 09 c7             	or     rdi,r8
 370:	4c 8b 45 e8          	mov    r8,QWORD PTR [rbp-0x18]
 374:	4c 01 c0             	add    rax,r8
 377:	4c 8b 45 d8          	mov    r8,QWORD PTR [rbp-0x28]
 37b:	4c 01 c0             	add    rax,r8
 37e:	4c 31 f8             	xor    rax,r15
 381:	4c 8b 45 e0          	mov    r8,QWORD PTR [rbp-0x20]
 385:	4c 01 c0             	add    rax,r8
 388:	48 31 f8             	xor    rax,rdi
 38b:	48 89 d7             	mov    rdi,rdx
 38e:	48 c1 e7 28          	shl    rdi,0x28
 392:	48 c1 e3 08          	shl    rbx,0x8
 396:	48 09 df             	or     rdi,rbx
 399:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
 39d:	4c 09 c7             	or     rdi,r8
 3a0:	48 01 f8             	add    rax,rdi
 3a3:	48 bf 00 00 00 00 06 	movabs rdi,0x600000000
 3aa:	00 00 00 
 3ad:	48 01 f8             	add    rax,rdi
 3b0:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
 3b4:	48 0f b6 7f 1f       	movzx  rdi,BYTE PTR [rdi+0x1f]
 3b9:	48 c1 e7 28          	shl    rdi,0x28
 3bd:	48 09 f9             	or     rcx,rdi
 3c0:	48 bf 00 00 00 44 01 	movabs rdi,0x144000000
 3c7:	00 00 00 
 3ca:	48 01 f9             	add    rcx,rdi
 3cd:	83 c2 05             	add    edx,0x5
 3d0:	c4 e2 e9 f7 c9       	shlx   rcx,rcx,rdx
 3d5:	48 31 c1             	xor    rcx,rax
 3d8:	31 ff                	xor    edi,edi
 3da:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3de:	88 4e 00             	mov    BYTE PTR [rsi+0x0],cl
 3e1:	48 89 cf             	mov    rdi,rcx
 3e4:	48 c1 ef 30          	shr    rdi,0x30
 3e8:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3ec:	48 89 cf             	mov    rdi,rcx
 3ef:	48 c1 ef 28          	shr    rdi,0x28
 3f3:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 3f7:	48 89 cf             	mov    rdi,rcx
 3fa:	48 c1 ef 20          	shr    rdi,0x20
 3fe:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 402:	48 89 cf             	mov    rdi,rcx
 405:	48 c1 ef 18          	shr    rdi,0x18
 409:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 40d:	48 89 cf             	mov    rdi,rcx
 410:	48 c1 ef 10          	shr    rdi,0x10
 414:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 418:	48 c1 e9 08          	shr    rcx,0x8
 41c:	88 4e 01             	mov    BYTE PTR [rsi+0x1],cl
 41f:	b8 02 00 00 00       	mov    eax,0x2
 424:	e9 08 fd ff ff       	jmp    0x131
```

## llvmbpf JIT ASM
```asm
not captured
```
