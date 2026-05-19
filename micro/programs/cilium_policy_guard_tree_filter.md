# cilium_policy_guard_tree_filter

## Original C
```c
#include "common.h"

#define DEEP_GUARD_TREE_8_RECORDS 32U
#define DEEP_GUARD_TREE_8_RECORD_SIZE 16U
#define DEEP_GUARD_TREE_8_INPUT_SIZE \
    (4U + DEEP_GUARD_TREE_8_RECORDS * DEEP_GUARD_TREE_8_RECORD_SIZE)

static __always_inline int bench_cilium_policy_guard_tree_filter(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    if (record_count != DEEP_GUARD_TREE_8_RECORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 4U, DEEP_GUARD_TREE_8_RECORDS * DEEP_GUARD_TREE_8_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0xE7037ED1A0B428DBULL;
    for (u32 index = 0; index < DEEP_GUARD_TREE_8_RECORDS; index++) {
        u32 base = 4U + index * DEEP_GUARD_TREE_8_RECORD_SIZE;
        u8 f0 = data[base + 0U];
        u8 f1 = data[base + 1U];
        u8 f2 = data[base + 2U];
        u8 f3 = data[base + 3U];
        u8 f4 = data[base + 4U];
        u8 f5 = data[base + 5U];
        u8 f6 = data[base + 6U];
        u8 f7 = data[base + 7U];
        u64 payload = micro_read_u64_le(data, base + 8U);

        if (f0 > 0x20U) {
            if ((f1 & 1U) != 0U) {
                if (f2 < 0x80U) {
                    if ((u8)(f3 ^ index) > 0x10U) {
                        if ((u8)(f4 + f0) < 0xC0U) {
                            if ((f5 & 0x18U) == 0x10U) {
                                if (f6 != 0xAAU) {
                                    if ((f7 & 3U) == 1U) {
                                        acc += payload ^ ((u64)f7 << 48U);
                                    } else {
                                        acc ^= payload + ((u64)f6 << 40U);
                                    }
                                } else {
                                    acc += micro_rotl64(payload ^ f5, 7U);
                                }
                            } else {
                                acc ^= payload + ((u64)f5 << 32U);
                            }
                        } else {
                            acc += payload ^ ((u64)f4 << 24U);
                        }
                    } else {
                        acc ^= payload + ((u64)f3 << 16U);
                    }
                } else {
                    acc += payload ^ ((u64)f2 << 8U);
                }
            } else {
                acc ^= payload + f1;
            }
        } else {
            acc += payload ^ f0;
        }

        acc = micro_rotl64(acc, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cilium_policy_guard_tree_filter_xdp,
    bench_cilium_policy_guard_tree_filter,
    cilium_policy_guard_tree_filter_input_value,
    DEEP_GUARD_TREE_8_INPUT_SIZE)
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

0000000000001100 <cilium_policy_guard_tree_filter_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <cilium_policy_guard_tree_filter_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <cilium_policy_guard_tree_filter_xdp+0xe>
    1118:	48 8d ba 0c 02 00 00 	lea    rdi,[rdx+0x20c]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <cilium_policy_guard_tree_filter_xdp+0xe>
    1124:	83 3e 20             	cmp    DWORD PTR [rsi],0x20
    1127:	75 e5                	jne    110e <cilium_policy_guard_tree_filter_xdp+0xe>
    1129:	53                   	push   rbx
    112a:	48 8d 7a 1b          	lea    rdi,[rdx+0x1b]
    112e:	48 be db 28 b4 a0 d1 	movabs rsi,0xe7037ed1a0b428db
    1135:	7e 03 e7 
    1138:	45 31 c0             	xor    r8d,r8d
    113b:	eb 42                	jmp    117f <cilium_policy_guard_tree_filter_xdp+0x7f>
    113d:	48 c1 e1 30          	shl    rcx,0x30
    1141:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    1148:	0f 1f 84 00 00 00 00 
    114f:	00 
    1150:	48 31 c8             	xor    rax,rcx
    1153:	48 01 c6             	add    rsi,rax
    1156:	44 89 c0             	mov    eax,r8d
    1159:	24 07                	and    al,0x7
    115b:	8d 48 01             	lea    ecx,[rax+0x1]
    115e:	48 89 f3             	mov    rbx,rsi
    1161:	48 d3 e3             	shl    rbx,cl
    1164:	f6 d0                	not    al
    1166:	89 c1                	mov    ecx,eax
    1168:	48 d3 ee             	shr    rsi,cl
    116b:	48 09 de             	or     rsi,rbx
    116e:	49 ff c0             	inc    r8
    1171:	48 83 c7 10          	add    rdi,0x10
    1175:	49 83 f8 20          	cmp    r8,0x20
    1179:	0f 84 b5 00 00 00    	je     1234 <cilium_policy_guard_tree_filter_xdp+0x134>
    117f:	0f b6 4f f1          	movzx  ecx,BYTE PTR [rdi-0xf]
    1183:	48 8b 47 f9          	mov    rax,QWORD PTR [rdi-0x7]
    1187:	48 83 f9 21          	cmp    rcx,0x21
    118b:	72 c3                	jb     1150 <cilium_policy_guard_tree_filter_xdp+0x50>
    118d:	44 0f b6 4f f2       	movzx  r9d,BYTE PTR [rdi-0xe]
    1192:	41 f6 c1 01          	test   r9b,0x1
    1196:	74 61                	je     11f9 <cilium_policy_guard_tree_filter_xdp+0xf9>
    1198:	44 0f b6 4f f3       	movzx  r9d,BYTE PTR [rdi-0xd]
    119d:	45 84 c9             	test   r9b,r9b
    11a0:	78 4d                	js     11ef <cilium_policy_guard_tree_filter_xdp+0xef>
    11a2:	44 0f b6 4f f4       	movzx  r9d,BYTE PTR [rdi-0xc]
    11a7:	45 89 ca             	mov    r10d,r9d
    11aa:	45 31 c2             	xor    r10d,r8d
    11ad:	41 80 fa 11          	cmp    r10b,0x11
    11b1:	72 42                	jb     11f5 <cilium_policy_guard_tree_filter_xdp+0xf5>
    11b3:	44 0f b6 4f f5       	movzx  r9d,BYTE PTR [rdi-0xb]
    11b8:	44 00 c9             	add    cl,r9b
    11bb:	80 f9 bf             	cmp    cl,0xbf
    11be:	77 44                	ja     1204 <cilium_policy_guard_tree_filter_xdp+0x104>
    11c0:	0f b6 4f f6          	movzx  ecx,BYTE PTR [rdi-0xa]
    11c4:	41 89 c9             	mov    r9d,ecx
    11c7:	41 80 e1 18          	and    r9b,0x18
    11cb:	41 80 f9 10          	cmp    r9b,0x10
    11cf:	75 3f                	jne    1210 <cilium_policy_guard_tree_filter_xdp+0x110>
    11d1:	44 0f b6 4f f7       	movzx  r9d,BYTE PTR [rdi-0x9]
    11d6:	41 81 f9 aa 00 00 00 	cmp    r9d,0xaa
    11dd:	75 3a                	jne    1219 <cilium_policy_guard_tree_filter_xdp+0x119>
    11df:	48 31 c1             	xor    rcx,rax
    11e2:	48 0f a4 c1 07       	shld   rcx,rax,0x7
    11e7:	48 01 ce             	add    rsi,rcx
    11ea:	e9 67 ff ff ff       	jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56>
    11ef:	41 c1 e1 08          	shl    r9d,0x8
    11f3:	eb 13                	jmp    1208 <cilium_policy_guard_tree_filter_xdp+0x108>
    11f5:	41 c1 e1 10          	shl    r9d,0x10
    11f9:	4c 01 c8             	add    rax,r9
    11fc:	48 31 c6             	xor    rsi,rax
    11ff:	e9 52 ff ff ff       	jmp    1156 <cilium_policy_guard_tree_filter_xdp+0x56>
    1204:	41 c1 e1 18          	shl    r9d,0x18
    1208:	4c 31 c8             	xor    rax,r9
    120b:	e9 43 ff ff ff       	jmp    1153 <cilium_policy_guard_tree_filter_xdp+0x53>
    1210:	48 c1 e1 20          	shl    rcx,0x20
    1214:	48 01 c8             	add    rax,rcx
    1217:	eb e3                	jmp    11fc <cilium_policy_guard_tree_filter_xdp+0xfc>
    1219:	0f b6 4f f8          	movzx  ecx,BYTE PTR [rdi-0x8]
    121d:	41 89 ca             	mov    r10d,ecx
    1220:	41 80 e2 03          	and    r10b,0x3
    1224:	41 80 fa 01          	cmp    r10b,0x1
    1228:	0f 84 0f ff ff ff    	je     113d <cilium_policy_guard_tree_filter_xdp+0x3d>
    122e:	49 c1 e1 28          	shl    r9,0x28
    1232:	eb c5                	jmp    11f9 <cilium_policy_guard_tree_filter_xdp+0xf9>
    1234:	40 88 32             	mov    BYTE PTR [rdx],sil
    1237:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
    123a:	89 d8                	mov    eax,ebx
    123c:	c1 e8 10             	shr    eax,0x10
    123f:	88 42 02             	mov    BYTE PTR [rdx+0x2],al
    1242:	89 d8                	mov    eax,ebx
    1244:	c1 e8 18             	shr    eax,0x18
    1247:	88 42 03             	mov    BYTE PTR [rdx+0x3],al
    124a:	48 89 d8             	mov    rax,rbx
    124d:	48 c1 e8 20          	shr    rax,0x20
    1251:	88 42 04             	mov    BYTE PTR [rdx+0x4],al
    1254:	48 89 d8             	mov    rax,rbx
    1257:	48 c1 e8 28          	shr    rax,0x28
    125b:	88 42 05             	mov    BYTE PTR [rdx+0x5],al
    125e:	48 89 d8             	mov    rax,rbx
    1261:	48 c1 e8 30          	shr    rax,0x30
    1265:	88 42 06             	mov    BYTE PTR [rdx+0x6],al
    1268:	48 c1 eb 38          	shr    rbx,0x38
    126c:	88 5a 07             	mov    BYTE PTR [rdx+0x7],bl
    126f:	b8 02 00 00 00       	mov    eax,0x2
    1274:	5b                   	pop    rbx
    1275:	c3                   	ret

Disassembly of section .fini:

0000000000001278 <_fini>:
    1278:	f3 0f 1e fa          	endbr64
    127c:	48 83 ec 08          	sub    rsp,0x8
    1280:	48 83 c4 08          	add    rsp,0x8
    1284:	c3                   	ret
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
   f:	31 c0                	xor    eax,eax
  11:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  15:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  19:	48 39 f7             	cmp    rdi,rsi
  1c:	0f 87 3f 02 00 00    	ja     0x261
  22:	48 89 fa             	mov    rdx,rdi
  25:	48 83 c2 08          	add    rdx,0x8
  29:	48 39 f2             	cmp    rdx,rsi
  2c:	0f 87 2f 02 00 00    	ja     0x261
  32:	48 89 fa             	mov    rdx,rdi
  35:	48 81 c2 0c 02 00 00 	add    rdx,0x20c
  3c:	48 39 f2             	cmp    rdx,rsi
  3f:	0f 87 1c 02 00 00    	ja     0x261
  45:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4a:	c1 e6 08             	shl    esi,0x8
  4d:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  52:	09 d6                	or     esi,edx
  54:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  59:	c1 e2 10             	shl    edx,0x10
  5c:	09 d6                	or     esi,edx
  5e:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  63:	c1 e2 18             	shl    edx,0x18
  66:	09 d6                	or     esi,edx
  68:	83 fe 20             	cmp    esi,0x20
  6b:	0f 85 f0 01 00 00    	jne    0x261
  71:	49 b8 db 28 b4 a0 d1 	movabs r8,0xe7037ed1a0b428db
  78:	7e 03 e7 
  7b:	31 f6                	xor    esi,esi
  7d:	48 89 fa             	mov    rdx,rdi
  80:	48 83 c2 0d          	add    rdx,0xd
  84:	48 0f b6 4a 07       	movzx  rcx,BYTE PTR [rdx+0x7]
  89:	48 0f b6 42 08       	movzx  rax,BYTE PTR [rdx+0x8]
  8e:	48 c1 e0 08          	shl    rax,0x8
  92:	48 09 c8             	or     rax,rcx
  95:	48 0f b6 4a 09       	movzx  rcx,BYTE PTR [rdx+0x9]
  9a:	48 c1 e1 10          	shl    rcx,0x10
  9e:	48 09 c1             	or     rcx,rax
  a1:	48 0f b6 42 0a       	movzx  rax,BYTE PTR [rdx+0xa]
  a6:	48 c1 e0 18          	shl    rax,0x18
  aa:	48 09 c8             	or     rax,rcx
  ad:	48 0f b6 4a 0b       	movzx  rcx,BYTE PTR [rdx+0xb]
  b2:	48 c1 e1 20          	shl    rcx,0x20
  b6:	48 09 c1             	or     rcx,rax
  b9:	48 0f b6 42 0c       	movzx  rax,BYTE PTR [rdx+0xc]
  be:	48 c1 e0 28          	shl    rax,0x28
  c2:	48 09 c8             	or     rax,rcx
  c5:	48 0f b6 5a 0d       	movzx  rbx,BYTE PTR [rdx+0xd]
  ca:	48 c1 e3 30          	shl    rbx,0x30
  ce:	48 09 c3             	or     rbx,rax
  d1:	48 0f b6 4a 0e       	movzx  rcx,BYTE PTR [rdx+0xe]
  d6:	48 c1 e1 38          	shl    rcx,0x38
  da:	48 09 d9             	or     rcx,rbx
  dd:	48 0f b6 42 ff       	movzx  rax,BYTE PTR [rdx-0x1]
  e2:	48 83 f8 21          	cmp    rax,0x21
  e6:	0f 82 a3 00 00 00    	jb     0x18f
  ec:	48 0f b6 5a 00       	movzx  rbx,BYTE PTR [rdx+0x0]
  f1:	41 89 dd             	mov    r13d,ebx
  f4:	41 83 e5 01          	and    r13d,0x1
  f8:	45 85 ed             	test   r13d,r13d
  fb:	0f 84 d5 00 00 00    	je     0x1d6
 101:	48 0f b6 5a 01       	movzx  rbx,BYTE PTR [rdx+0x1]
 106:	41 89 dd             	mov    r13d,ebx
 109:	41 c1 e5 18          	shl    r13d,0x18
 10d:	41 c1 fd 18          	sar    r13d,0x18
 111:	45 85 ed             	test   r13d,r13d
 114:	0f 8c b2 00 00 00    	jl     0x1cc
 11a:	48 0f b6 5a 02       	movzx  rbx,BYTE PTR [rdx+0x2]
 11f:	41 89 dd             	mov    r13d,ebx
 122:	41 31 f5             	xor    r13d,esi
 125:	41 81 e5 ff 00 00 00 	and    r13d,0xff
 12c:	41 83 fd 11          	cmp    r13d,0x11
 130:	0f 82 9c 00 00 00    	jb     0x1d2
 136:	48 0f b6 5a 03       	movzx  rbx,BYTE PTR [rdx+0x3]
 13b:	41 89 dd             	mov    r13d,ebx
 13e:	41 01 c5             	add    r13d,eax
 141:	41 81 e5 ff 00 00 00 	and    r13d,0xff
 148:	41 81 fd bf 00 00 00 	cmp    r13d,0xbf
 14f:	0f 87 89 00 00 00    	ja     0x1de
 155:	48 0f b6 42 04       	movzx  rax,BYTE PTR [rdx+0x4]
 15a:	89 c3                	mov    ebx,eax
 15c:	83 e3 18             	and    ebx,0x18
 15f:	83 fb 10             	cmp    ebx,0x10
 162:	0f 85 7f 00 00 00    	jne    0x1e7
 168:	48 0f b6 5a 05       	movzx  rbx,BYTE PTR [rdx+0x5]
 16d:	81 fb aa 00 00 00    	cmp    ebx,0xaa
 173:	74 7b                	je     0x1f0
 175:	48 0f b6 42 06       	movzx  rax,BYTE PTR [rdx+0x6]
 17a:	41 89 c5             	mov    r13d,eax
 17d:	41 83 e5 03          	and    r13d,0x3
 181:	41 83 fd 01          	cmp    r13d,0x1
 185:	0f 85 7e 00 00 00    	jne    0x209
 18b:	48 c1 e0 30          	shl    rax,0x30
 18f:	48 31 c1             	xor    rcx,rax
 192:	4c 01 c1             	add    rcx,r8
 195:	41 89 f0             	mov    r8d,esi
 198:	41 83 e0 07          	and    r8d,0x7
 19c:	44 89 c0             	mov    eax,r8d
 19f:	83 f0 3f             	xor    eax,0x3f
 1a2:	48 89 cb             	mov    rbx,rcx
 1a5:	c4 e2 fb f7 db       	shrx   rbx,rbx,rax
 1aa:	41 83 c0 01          	add    r8d,0x1
 1ae:	c4 e2 b9 f7 c9       	shlx   rcx,rcx,r8
 1b3:	48 83 c2 10          	add    rdx,0x10
 1b7:	49 89 c8             	mov    r8,rcx
 1ba:	49 09 d8             	or     r8,rbx
 1bd:	48 83 c6 01          	add    rsi,0x1
 1c1:	48 83 fe 20          	cmp    rsi,0x20
 1c5:	74 48                	je     0x20f
 1c7:	e9 b8 fe ff ff       	jmp    0x84
 1cc:	48 c1 e3 08          	shl    rbx,0x8
 1d0:	eb 10                	jmp    0x1e2
 1d2:	48 c1 e3 10          	shl    rbx,0x10
 1d6:	48 01 d9             	add    rcx,rbx
 1d9:	4c 31 c1             	xor    rcx,r8
 1dc:	eb b7                	jmp    0x195
 1de:	48 c1 e3 18          	shl    rbx,0x18
 1e2:	48 31 d9             	xor    rcx,rbx
 1e5:	eb ab                	jmp    0x192
 1e7:	48 c1 e0 20          	shl    rax,0x20
 1eb:	48 01 c1             	add    rcx,rax
 1ee:	eb e9                	jmp    0x1d9
 1f0:	48 89 cb             	mov    rbx,rcx
 1f3:	48 31 c3             	xor    rbx,rax
 1f6:	48 c1 e3 07          	shl    rbx,0x7
 1fa:	48 c1 e9 39          	shr    rcx,0x39
 1fe:	48 09 cb             	or     rbx,rcx
 201:	4c 01 c3             	add    rbx,r8
 204:	48 89 d9             	mov    rcx,rbx
 207:	eb 8c                	jmp    0x195
 209:	48 c1 e3 28          	shl    rbx,0x28
 20d:	eb c7                	jmp    0x1d6
 20f:	44 88 47 00          	mov    BYTE PTR [rdi+0x0],r8b
 213:	48 89 ce             	mov    rsi,rcx
 216:	48 c1 ee 38          	shr    rsi,0x38
 21a:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 21e:	48 89 ce             	mov    rsi,rcx
 221:	48 c1 ee 30          	shr    rsi,0x30
 225:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 229:	48 89 ce             	mov    rsi,rcx
 22c:	48 c1 ee 28          	shr    rsi,0x28
 230:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 234:	48 89 ce             	mov    rsi,rcx
 237:	48 c1 ee 20          	shr    rsi,0x20
 23b:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 23f:	48 89 ce             	mov    rsi,rcx
 242:	48 c1 ee 18          	shr    rsi,0x18
 246:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 24a:	48 89 ce             	mov    rsi,rcx
 24d:	48 c1 ee 10          	shr    rsi,0x10
 251:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 255:	48 c1 e9 08          	shr    rcx,0x8
 259:	88 4f 01             	mov    BYTE PTR [rdi+0x1],cl
 25c:	b8 02 00 00 00       	mov    eax,0x2
 261:	41 5d                	pop    r13
 263:	5b                   	pop    rbx
 264:	c9                   	leave
 265:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
