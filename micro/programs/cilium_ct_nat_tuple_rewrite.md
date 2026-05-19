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

0000000000001274 <_fini>:
    1274:	f3 0f 1e fa          	endbr64
    1278:	48 83 ec 08          	sub    rsp,0x8
    127c:	48 83 c4 08          	add    rsp,0x8
    1280:	c3                   	ret
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
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 12 03 00 00    	ja     0x33f
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 02 03 00 00    	ja     0x33f
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 10 04 00 00 	add    rdi,0x410
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 ef 02 00 00    	ja     0x33f
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	c1 e7 08             	shl    edi,0x8
  58:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5d:	09 f7                	or     edi,esi
  5f:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  64:	c1 e6 10             	shl    esi,0x10
  67:	09 f7                	or     edi,esi
  69:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  6e:	c1 e6 18             	shl    esi,0x18
  71:	09 f7                	or     edi,esi
  73:	83 ff 20             	cmp    edi,0x20
  76:	0f 85 c3 02 00 00    	jne    0x33f
  7c:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  81:	c1 e7 08             	shl    edi,0x8
  84:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  89:	09 f7                	or     edi,esi
  8b:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  90:	c1 e6 10             	shl    esi,0x10
  93:	09 f7                	or     edi,esi
  95:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  9a:	c1 e6 18             	shl    esi,0x18
  9d:	09 f7                	or     edi,esi
  9f:	83 ff 20             	cmp    edi,0x20
  a2:	0f 85 97 02 00 00    	jne    0x33f
  a8:	48 bb e3 c6 88 9c f0 	movabs rbx,0x8ebc6af09c88c6e3
  af:	6a bc 8e 
  b2:	45 31 ed             	xor    r13d,r13d
  b5:	48 89 55 d0          	mov    QWORD PTR [rbp-0x30],rdx
  b9:	48 89 d1             	mov    rcx,rdx
  bc:	48 83 c1 17          	add    rcx,0x17
  c0:	e9 98 00 00 00       	jmp    0x15d
  c5:	44 89 ef             	mov    edi,r13d
  c8:	c1 ef 15             	shr    edi,0x15
  cb:	44 89 ee             	mov    esi,r13d
  ce:	c1 e6 0b             	shl    esi,0xb
  d1:	09 fe                	or     esi,edi
  d3:	48 8b 7d d8          	mov    rdi,QWORD PTR [rbp-0x28]
  d7:	c1 e7 18             	shl    edi,0x18
  da:	41 09 f8             	or     r8d,edi
  dd:	41 81 e6 ff ff 00 00 	and    r14d,0xffff
  e4:	45 31 f0             	xor    r8d,r14d
  e7:	c1 e2 10             	shl    edx,0x10
  ea:	41 31 d0             	xor    r8d,edx
  ed:	41 31 f0             	xor    r8d,esi
  f0:	8b 75 e8             	mov    esi,DWORD PTR [rbp-0x18]
  f3:	81 e6 ff ff 00 00    	and    esi,0xffff
  f9:	c1 e6 08             	shl    esi,0x8
  fc:	89 c7                	mov    edi,eax
  fe:	31 f7                	xor    edi,esi
 100:	8b 5d e0             	mov    ebx,DWORD PTR [rbp-0x20]
 103:	c1 e3 1d             	shl    ebx,0x1d
 106:	c1 fb 1f             	sar    ebx,0x1f
 109:	21 fb                	and    ebx,edi
 10b:	45 31 f8             	xor    r8d,r15d
 10e:	49 c1 e7 20          	shl    r15,0x20
 112:	4d 09 ef             	or     r15,r13
 115:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 119:	44 89 ef             	mov    edi,r13d
 11c:	83 e7 07             	and    edi,0x7
 11f:	89 fe                	mov    esi,edi
 121:	83 f6 3f             	xor    esi,0x3f
 124:	4c 89 fa             	mov    rdx,r15
 127:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 12c:	83 c7 01             	add    edi,0x1
 12f:	c4 42 c1 f7 ff       	shlx   r15,r15,rdi
 134:	49 09 d7             	or     r15,rdx
 137:	41 01 d8             	add    r8d,ebx
 13a:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 13e:	48 01 c3             	add    rbx,rax
 141:	49 c1 e0 20          	shl    r8,0x20
 145:	4c 01 c3             	add    rbx,r8
 148:	4c 31 fb             	xor    rbx,r15
 14b:	48 83 c1 20          	add    rcx,0x20
 14f:	49 83 c5 01          	add    r13,0x1
 153:	49 83 fd 20          	cmp    r13,0x20
 157:	0f 84 8d 01 00 00    	je     0x2ea
 15d:	4c 0f b6 41 14       	movzx  r8,BYTE PTR [rcx+0x14]
 162:	4c 0f b6 71 13       	movzx  r14,BYTE PTR [rcx+0x13]
 167:	48 0f b6 51 12       	movzx  rdx,BYTE PTR [rcx+0x12]
 16c:	48 0f b6 71 11       	movzx  rsi,BYTE PTR [rcx+0x11]
 171:	48 0f b6 41 16       	movzx  rax,BYTE PTR [rcx+0x16]
 176:	c1 e0 08             	shl    eax,0x8
 179:	48 0f b6 79 15       	movzx  rdi,BYTE PTR [rcx+0x15]
 17e:	09 f8                	or     eax,edi
 180:	48 0f b6 79 17       	movzx  rdi,BYTE PTR [rcx+0x17]
 185:	c1 e7 10             	shl    edi,0x10
 188:	09 f8                	or     eax,edi
 18a:	48 0f b6 79 18       	movzx  rdi,BYTE PTR [rcx+0x18]
 18f:	c1 e7 18             	shl    edi,0x18
 192:	09 f8                	or     eax,edi
 194:	48 0f b6 79 05       	movzx  rdi,BYTE PTR [rcx+0x5]
 199:	83 ff 06             	cmp    edi,0x6
 19c:	74 14                	je     0x1b2
 19e:	83 ff 11             	cmp    edi,0x11
 1a1:	74 0f                	je     0x1b2
 1a3:	48 c1 e7 38          	shl    rdi,0x38
 1a7:	48 09 c7             	or     rdi,rax
 1aa:	48 31 df             	xor    rdi,rbx
 1ad:	48 89 fb             	mov    rbx,rdi
 1b0:	eb 99                	jmp    0x14b
 1b2:	44 89 75 e0          	mov    DWORD PTR [rbp-0x20],r14d
 1b6:	89 75 e8             	mov    DWORD PTR [rbp-0x18],esi
 1b9:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 1bd:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 1c1:	48 0f b6 79 fe       	movzx  rdi,BYTE PTR [rcx-0x2]
 1c6:	c1 e7 08             	shl    edi,0x8
 1c9:	48 0f b6 71 fd       	movzx  rsi,BYTE PTR [rcx-0x3]
 1ce:	09 f7                	or     edi,esi
 1d0:	48 0f b6 71 ff       	movzx  rsi,BYTE PTR [rcx-0x1]
 1d5:	c1 e6 10             	shl    esi,0x10
 1d8:	09 f7                	or     edi,esi
 1da:	48 0f b6 71 00       	movzx  rsi,BYTE PTR [rcx+0x0]
 1df:	c1 e6 18             	shl    esi,0x18
 1e2:	09 f7                	or     edi,esi
 1e4:	4c 0f b6 71 07       	movzx  r14,BYTE PTR [rcx+0x7]
 1e9:	44 89 f6             	mov    esi,r14d
 1ec:	83 e6 02             	and    esi,0x2
 1ef:	85 f6                	test   esi,esi
 1f1:	74 23                	je     0x216
 1f3:	48 0f b6 79 0e       	movzx  rdi,BYTE PTR [rcx+0xe]
 1f8:	c1 e7 08             	shl    edi,0x8
 1fb:	48 0f b6 71 0d       	movzx  rsi,BYTE PTR [rcx+0xd]
 200:	09 f7                	or     edi,esi
 202:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
 207:	c1 e6 10             	shl    esi,0x10
 20a:	09 f7                	or     edi,esi
 20c:	48 0f b6 71 10       	movzx  rsi,BYTE PTR [rcx+0x10]
 211:	c1 e6 18             	shl    esi,0x18
 214:	09 f7                	or     edi,esi
 216:	48 89 5d f8          	mov    QWORD PTR [rbp-0x8],rbx
 21a:	4c 0f b6 79 fa       	movzx  r15,BYTE PTR [rcx-0x6]
 21f:	41 c1 e7 08          	shl    r15d,0x8
 223:	48 0f b6 71 f9       	movzx  rsi,BYTE PTR [rcx-0x7]
 228:	41 09 f7             	or     r15d,esi
 22b:	48 0f b6 71 fb       	movzx  rsi,BYTE PTR [rcx-0x5]
 230:	c1 e6 10             	shl    esi,0x10
 233:	41 09 f7             	or     r15d,esi
 236:	48 0f b6 71 fc       	movzx  rsi,BYTE PTR [rcx-0x4]
 23b:	c1 e6 18             	shl    esi,0x18
 23e:	41 09 f7             	or     r15d,esi
 241:	45 89 f5             	mov    r13d,r14d
 244:	41 83 e5 01          	and    r13d,0x1
 248:	45 85 ed             	test   r13d,r13d
 24b:	74 27                	je     0x274
 24d:	4c 0f b6 79 0a       	movzx  r15,BYTE PTR [rcx+0xa]
 252:	41 c1 e7 08          	shl    r15d,0x8
 256:	48 0f b6 71 09       	movzx  rsi,BYTE PTR [rcx+0x9]
 25b:	41 09 f7             	or     r15d,esi
 25e:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
 263:	c1 e6 10             	shl    esi,0x10
 266:	41 09 f7             	or     r15d,esi
 269:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
 26e:	c1 e6 18             	shl    esi,0x18
 271:	41 09 f7             	or     r15d,esi
 274:	41 c1 e0 08          	shl    r8d,0x8
 278:	8b 75 e0             	mov    esi,DWORD PTR [rbp-0x20]
 27b:	41 09 f0             	or     r8d,esi
 27e:	c1 e2 08             	shl    edx,0x8
 281:	8b 75 e8             	mov    esi,DWORD PTR [rbp-0x18]
 284:	09 f2                	or     edx,esi
 286:	48 0f b6 71 04       	movzx  rsi,BYTE PTR [rcx+0x4]
 28b:	c1 e6 08             	shl    esi,0x8
 28e:	89 d3                	mov    ebx,edx
 290:	48 0f b6 51 03       	movzx  rdx,BYTE PTR [rcx+0x3]
 295:	09 d6                	or     esi,edx
 297:	44 89 75 e0          	mov    DWORD PTR [rbp-0x20],r14d
 29b:	44 89 f2             	mov    edx,r14d
 29e:	c1 e2 1e             	shl    edx,0x1e
 2a1:	c1 fa 1f             	sar    edx,0x1f
 2a4:	21 da                	and    edx,ebx
 2a6:	31 d6                	xor    esi,edx
 2a8:	48 0f b6 51 02       	movzx  rdx,BYTE PTR [rcx+0x2]
 2ad:	c1 e2 08             	shl    edx,0x8
 2b0:	4c 0f b6 71 01       	movzx  r14,BYTE PTR [rcx+0x1]
 2b5:	44 09 f2             	or     edx,r14d
 2b8:	41 f7 dd             	neg    r13d
 2bb:	89 5d e8             	mov    DWORD PTR [rbp-0x18],ebx
 2be:	41 21 dd             	and    r13d,ebx
 2c1:	44 31 ea             	xor    edx,r13d
 2c4:	48 0f b6 59 06       	movzx  rbx,BYTE PTR [rcx+0x6]
 2c9:	83 e3 01             	and    ebx,0x1
 2cc:	41 89 f6             	mov    r14d,esi
 2cf:	41 89 fd             	mov    r13d,edi
 2d2:	85 db                	test   ebx,ebx
 2d4:	0f 84 eb fd ff ff    	je     0xc5
 2da:	41 89 d6             	mov    r14d,edx
 2dd:	89 f2                	mov    edx,esi
 2df:	45 89 fd             	mov    r13d,r15d
 2e2:	41 89 ff             	mov    r15d,edi
 2e5:	e9 db fd ff ff       	jmp    0xc5
 2ea:	48 8b 75 d0          	mov    rsi,QWORD PTR [rbp-0x30]
 2ee:	88 5e 00             	mov    BYTE PTR [rsi+0x0],bl
 2f1:	48 89 df             	mov    rdi,rbx
 2f4:	48 c1 ef 38          	shr    rdi,0x38
 2f8:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 2fc:	48 89 df             	mov    rdi,rbx
 2ff:	48 c1 ef 30          	shr    rdi,0x30
 303:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 307:	48 89 df             	mov    rdi,rbx
 30a:	48 c1 ef 28          	shr    rdi,0x28
 30e:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 312:	48 89 df             	mov    rdi,rbx
 315:	48 c1 ef 20          	shr    rdi,0x20
 319:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 31d:	48 89 df             	mov    rdi,rbx
 320:	48 c1 ef 18          	shr    rdi,0x18
 324:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 328:	48 89 df             	mov    rdi,rbx
 32b:	48 c1 ef 10          	shr    rdi,0x10
 32f:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 333:	48 c1 eb 08          	shr    rbx,0x8
 337:	88 5e 01             	mov    BYTE PTR [rsi+0x1],bl
 33a:	b8 02 00 00 00       	mov    eax,0x2
 33f:	41 5f                	pop    r15
 341:	41 5e                	pop    r14
 343:	41 5d                	pop    r13
 345:	5b                   	pop    rbx
 346:	c9                   	leave
 347:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
