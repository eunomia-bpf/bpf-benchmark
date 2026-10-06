# tracee_syscall_name_table_lookup

## Original C
```c
#include "common.h"

#define TRACEE_SYSCALL_LOOKUP_COUNT 64U
#define TRACEE_SYSCALL_LOOKUP_INPUT_SIZE (4U + TRACEE_SYSCALL_LOOKUP_COUNT * 4U)

static __always_inline u64 tracee_syscall_name_sig(u32 syscall_id)
{
    switch (syscall_id) {
    case 0U: return 0x0000000072656164ULL;
    case 1U: return 0x0000006574697277ULL;
    case 2U: return 0x000000006E65706FULL;
    case 3U: return 0x00000065736F6C63ULL;
    case 9U: return 0x0000000070616D6DULL;
    case 12U: return 0x000000006B72626BULL;
    case 39U: return 0x0000006469707467ULL;
    case 56U: return 0x0000656E6F6C6355ULL;
    case 57U: return 0x000000006B726F66ULL;
    case 59U: return 0x0000657663657865ULL;
    case 60U: return 0x0000000074697865ULL;
    case 61U: return 0x0000347469617755ULL;
    case 80U: return 0x0000000069646863ULL;
    case 87U: return 0x00006B6E696C6E75ULL;
    case 89U: return 0x0000006B6E696C55ULL;
    case 158U: return 0x006C74635F68637261ULL;
    case 202U: return 0x0000786574756655ULL;
    case 217U: return 0x0000646461746567ULL;
    case 257U: return 0x000074616E65706FULL;
    case 263U: return 0x0074616B6E696C6E75ULL;
    case 281U: return 0x0074613274617473ULL;
    case 291U: return 0x647466656E676973ULL;
    case 321U: return 0x0000000000706662ULL;
    case 332U: return 0x0000000078746173ULL;
    default: return 0ULL;
    }
}

static __always_inline int
bench_tracee_syscall_name_table_lookup(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, TRACEE_SYSCALL_LOOKUP_INPUT_SIZE)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    if (count != TRACEE_SYSCALL_LOOKUP_COUNT) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 index = 0; index < TRACEE_SYSCALL_LOOKUP_COUNT; index++) {
        u32 syscall_id = micro_read_u32_le(data, 4U + index * 4U);
        u64 sig = tracee_syscall_name_sig(syscall_id);

        if (sig != 0U) {
            acc += micro_rotl64(sig ^ syscall_id, (index & 7U) + 1U);
            acc ^= (u64)(syscall_id & 0xFFU) << ((index & 7U) * 8U);
        } else {
            acc ^= (u64)syscall_id * 0x9E3779B185EBCA87ULL;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    tracee_syscall_name_table_lookup_xdp,
    bench_tracee_syscall_name_table_lookup,
    tracee_syscall_name_table_lookup_input_value,
    TRACEE_SYSCALL_LOOKUP_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <tracee_syscall_name_table_lookup_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <tracee_syscall_name_table_lookup_xdp+0xe>
    1118:	48 8d ba 0c 01 00 00 	lea    rdi,[rdx+0x10c]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <tracee_syscall_name_table_lookup_xdp+0xe>
    1124:	83 3e 40             	cmp    DWORD PTR [rsi],0x40
    1127:	75 e5                	jne    110e <tracee_syscall_name_table_lookup_xdp+0xe>
    1129:	55                   	push   rbp
    112a:	41 57                	push   r15
    112c:	41 56                	push   r14
    112e:	41 55                	push   r13
    1130:	41 54                	push   r12
    1132:	53                   	push   rbx
    1133:	49 be 09 c9 bc f3 67 	movabs r14,0x6a09e667f3bcc909
    113a:	e6 09 6a 
    113d:	48 be 63 6c 6f 73 65 	movabs rsi,0x65736f6c63
    1144:	00 00 00 
    1147:	45 31 c0             	xor    r8d,r8d
    114a:	4c 8d 15 af 0e 00 00 	lea    r10,[rip+0xeaf]        # 2000 <_fini+0xcb0>
    1151:	4c 8d 9e 14 06 fa 00 	lea    r11,[rsi+0xfa0614]
    1158:	4c 8d 3d 1d 11 00 00 	lea    r15,[rip+0x111d]        # 227c <_fini+0xf2c>
    115f:	49 bd 75 6e 6c 69 6e 	movabs r13,0x74616b6e696c6e75
    1166:	6b 61 74 
    1169:	48 bd 73 74 61 74 32 	movabs rbp,0x74613274617473
    1170:	61 74 00 
    1173:	49 b9 73 69 67 6e 65 	movabs r9,0x647466656e676973
    117a:	66 74 64 
    117d:	0f 1f 00             	nop    DWORD PTR [rax]
    1180:	42 0f b6 7c 82 0c    	movzx  edi,BYTE PTR [rdx+r8*4+0xc]
    1186:	42 0f b6 4c 82 0d    	movzx  ecx,BYTE PTR [rdx+r8*4+0xd]
    118c:	c1 e1 08             	shl    ecx,0x8
    118f:	09 f9                	or     ecx,edi
    1191:	42 0f b7 44 82 0e    	movzx  eax,WORD PTR [rdx+r8*4+0xe]
    1197:	c1 e0 10             	shl    eax,0x10
    119a:	09 c8                	or     eax,ecx
    119c:	3d d8 00 00 00       	cmp    eax,0xd8
    11a1:	7f 1d                	jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0>
    11a3:	3d 9e 00 00 00       	cmp    eax,0x9e
    11a8:	77 6e                	ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118>
    11aa:	89 c1                	mov    ecx,eax
    11ac:	49 63 0c 8a          	movsxd rcx,DWORD PTR [r10+rcx*4]
    11b0:	4c 01 d1             	add    rcx,r10
    11b3:	ff e1                	jmp    rcx
    11b5:	b9 64 61 65 72       	mov    ecx,0x72656164
    11ba:	e9 41 01 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    11bf:	90                   	nop
    11c0:	3d 40 01 00 00       	cmp    eax,0x140
    11c5:	7f 23                	jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea>
    11c7:	8d 88 ff fe ff ff    	lea    ecx,[rax-0x101]
    11cd:	83 f9 22             	cmp    ecx,0x22
    11d0:	77 30                	ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102>
    11d2:	49 63 0c 8f          	movsxd rcx,DWORD PTR [r15+rcx*4]
    11d6:	4c 01 f9             	add    rcx,r15
    11d9:	ff e1                	jmp    rcx
    11db:	48 b9 6f 70 65 6e 61 	movabs rcx,0x74616e65706f
    11e2:	74 00 00 
    11e5:	e9 16 01 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    11ea:	3d 41 01 00 00       	cmp    eax,0x141
    11ef:	74 55                	je     1246 <tracee_syscall_name_table_lookup_xdp+0x146>
    11f1:	3d 4c 01 00 00       	cmp    eax,0x14c
    11f6:	75 58                	jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150>
    11f8:	b9 73 61 74 78       	mov    ecx,0x78746173
    11fd:	e9 fe 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1202:	3d d9 00 00 00       	cmp    eax,0xd9
    1207:	75 47                	jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150>
    1209:	48 b9 67 65 74 61 64 	movabs rcx,0x646461746567
    1210:	64 00 00 
    1213:	e9 e8 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1218:	3d ca 00 00 00       	cmp    eax,0xca
    121d:	75 31                	jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150>
    121f:	48 b9 55 66 75 74 65 	movabs rcx,0x786574756655
    1226:	78 00 00 
    1229:	e9 d2 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    122e:	4c 89 e9             	mov    rcx,r13
    1231:	e9 ca 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1236:	48 89 e9             	mov    rcx,rbp
    1239:	e9 c2 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    123e:	4c 89 c9             	mov    rcx,r9
    1241:	e9 ba 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1246:	b9 62 66 70 00       	mov    ecx,0x706662
    124b:	e9 b0 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1250:	89 c0                	mov    eax,eax
    1252:	48 b9 87 ca eb 85 b1 	movabs rcx,0x9e3779b185ebca87
    1259:	79 37 9e 
    125c:	48 0f af c1          	imul   rax,rcx
    1260:	49 31 c6             	xor    r14,rax
    1263:	e9 c7 00 00 00       	jmp    132f <tracee_syscall_name_table_lookup_xdp+0x22f>
    1268:	48 b9 65 78 65 63 76 	movabs rcx,0x657663657865
    126f:	65 00 00 
    1272:	e9 89 00 00 00       	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1277:	48 b9 67 74 70 69 64 	movabs rcx,0x6469707467
    127e:	00 00 00 
    1281:	eb 7d                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1283:	b9 6d 6d 61 70       	mov    ecx,0x70616d6d
    1288:	eb 76                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    128a:	48 b9 75 6e 6c 69 6e 	movabs rcx,0x6b6e696c6e75
    1291:	6b 00 00 
    1294:	eb 6a                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    1296:	48 b9 55 63 6c 6f 6e 	movabs rcx,0x656e6f6c6355
    129d:	65 00 00 
    12a0:	eb 5e                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12a2:	48 b9 55 77 61 69 74 	movabs rcx,0x347469617755
    12a9:	34 00 00 
    12ac:	eb 52                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12ae:	b9 6f 70 65 6e       	mov    ecx,0x6e65706f
    12b3:	eb 4b                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12b5:	48 89 f1             	mov    rcx,rsi
    12b8:	eb 46                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12ba:	b9 66 6f 72 6b       	mov    ecx,0x6b726f66
    12bf:	eb 3f                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12c1:	b9 65 78 69 74       	mov    ecx,0x74697865
    12c6:	eb 38                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12c8:	4c 89 d9             	mov    rcx,r11
    12cb:	eb 33                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12cd:	48 b9 55 6c 69 6e 6b 	movabs rcx,0x6b6e696c55
    12d4:	00 00 00 
    12d7:	eb 27                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12d9:	b9 6b 62 72 6b       	mov    ecx,0x6b72626b
    12de:	eb 20                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12e0:	b9 63 68 64 69       	mov    ecx,0x69646863
    12e5:	eb 19                	jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200>
    12e7:	48 b9 61 72 63 68 5f 	movabs rcx,0x6c74635f68637261
    12ee:	63 74 6c 
    12f1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    12f8:	0f 1f 84 00 00 00 00 
    12ff:	00 
    1300:	89 c3                	mov    ebx,eax
    1302:	48 31 cb             	xor    rbx,rcx
    1305:	44 89 c0             	mov    eax,r8d
    1308:	83 e0 07             	and    eax,0x7
    130b:	8d 48 01             	lea    ecx,[rax+0x1]
    130e:	49 89 dc             	mov    r12,rbx
    1311:	49 d3 e4             	shl    r12,cl
    1314:	89 c1                	mov    ecx,eax
    1316:	f6 d1                	not    cl
    1318:	48 d3 eb             	shr    rbx,cl
    131b:	c1 e0 03             	shl    eax,0x3
    131e:	89 c1                	mov    ecx,eax
    1320:	48 d3 e7             	shl    rdi,cl
    1323:	4c 09 e3             	or     rbx,r12
    1326:	4c 01 f3             	add    rbx,r14
    1329:	48 31 df             	xor    rdi,rbx
    132c:	49 89 fe             	mov    r14,rdi
    132f:	49 ff c0             	inc    r8
    1332:	49 83 f8 40          	cmp    r8,0x40
    1336:	0f 85 44 fe ff ff    	jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80>
    133c:	4c 89 32             	mov    QWORD PTR [rdx],r14
    133f:	b8 02 00 00 00       	mov    eax,0x2
    1344:	5b                   	pop    rbx
    1345:	41 5c                	pop    r12
    1347:	41 5d                	pop    r13
    1349:	41 5e                	pop    r14
    134b:	41 5f                	pop    r15
    134d:	5d                   	pop    rbp
    134e:	c3                   	ret

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
   c:	53                   	push   rbx
   d:	41 55                	push   r13
   f:	41 56                	push   r14
  11:	41 57                	push   r15
  13:	31 c0                	xor    eax,eax
  15:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  19:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  1d:	48 39 f7             	cmp    rdi,rsi
  20:	0f 87 ca 03 00 00    	ja     0x3f0
  26:	48 89 fa             	mov    rdx,rdi
  29:	48 83 c2 08          	add    rdx,0x8
  2d:	48 39 f2             	cmp    rdx,rsi
  30:	0f 87 ba 03 00 00    	ja     0x3f0
  36:	48 89 fa             	mov    rdx,rdi
  39:	48 81 c2 0c 01 00 00 	add    rdx,0x10c
  40:	48 39 f2             	cmp    rdx,rsi
  43:	0f 87 a7 03 00 00    	ja     0x3f0
  49:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4e:	48 c1 e6 08          	shl    rsi,0x8
  52:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  57:	48 09 d6             	or     rsi,rdx
  5a:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  5f:	48 c1 e2 10          	shl    rdx,0x10
  63:	48 09 d6             	or     rsi,rdx
  66:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  6b:	48 c1 e2 18          	shl    rdx,0x18
  6f:	48 09 d6             	or     rsi,rdx
  72:	48 c1 e6 20          	shl    rsi,0x20
  76:	48 c1 ee 20          	shr    rsi,0x20
  7a:	48 83 fe 40          	cmp    rsi,0x40
  7e:	0f 85 6c 03 00 00    	jne    0x3f0
  84:	49 b8 09 c9 bc f3 67 	movabs r8,0x6a09e667f3bcc909
  8b:	e6 09 6a 
  8e:	31 f6                	xor    esi,esi
  90:	48 89 fa             	mov    rdx,rdi
  93:	48 83 c2 0f          	add    rdx,0xf
  97:	48 b9 87 ca eb 85 b1 	movabs rcx,0x9e3779b185ebca87
  9e:	79 37 9e 
  a1:	48 0f b6 5a fe       	movzx  rbx,BYTE PTR [rdx-0x2]
  a6:	48 c1 e3 08          	shl    rbx,0x8
  aa:	48 0f b6 42 fd       	movzx  rax,BYTE PTR [rdx-0x3]
  af:	48 09 c3             	or     rbx,rax
  b2:	4c 0f b6 6a ff       	movzx  r13,BYTE PTR [rdx-0x1]
  b7:	49 c1 e5 10          	shl    r13,0x10
  bb:	4c 09 eb             	or     rbx,r13
  be:	4c 0f b6 6a 00       	movzx  r13,BYTE PTR [rdx+0x0]
  c3:	49 c1 e5 18          	shl    r13,0x18
  c7:	4c 09 eb             	or     rbx,r13
  ca:	49 89 de             	mov    r14,rbx
  cd:	49 c1 e6 20          	shl    r14,0x20
  d1:	49 c1 ee 20          	shr    r14,0x20
  d5:	49 83 fe 4f          	cmp    r14,0x4f
  d9:	7f 34                	jg     0x10f
  db:	49 83 fe 26          	cmp    r14,0x26
  df:	7f 72                	jg     0x153
  e1:	49 83 fe 02          	cmp    r14,0x2
  e5:	0f 8f e0 00 00 00    	jg     0x1cb
  eb:	41 bd 64 61 65 72    	mov    r13d,0x72656164
  f1:	4d 85 f6             	test   r14,r14
  f4:	0f 84 3a 02 00 00    	je     0x334
  fa:	49 83 fe 01          	cmp    r14,0x1
  fe:	0f 84 85 01 00 00    	je     0x289
 104:	41 bd 6f 70 65 6e    	mov    r13d,0x6e65706f
 10a:	e9 25 02 00 00       	jmp    0x334
 10f:	49 81 fe 00 01 00 00 	cmp    r14,0x100
 116:	7f 6f                	jg     0x187
 118:	49 81 fe 9d 00 00 00 	cmp    r14,0x9d
 11f:	0f 8f d0 00 00 00    	jg     0x1f5
 125:	49 83 fe 50          	cmp    r14,0x50
 129:	0f 84 b7 01 00 00    	je     0x2e6
 12f:	49 83 fe 57          	cmp    r14,0x57
 133:	0f 84 5f 01 00 00    	je     0x298
 139:	49 83 fe 59          	cmp    r14,0x59
 13d:	74 05                	je     0x144
 13f:	e9 45 02 00 00       	jmp    0x389
 144:	49 bd 55 6c 69 6e 6b 	movabs r13,0x6b6e696c55
 14b:	00 00 00 
 14e:	e9 e1 01 00 00       	jmp    0x334
 153:	49 83 fe 3a          	cmp    r14,0x3a
 157:	0f 8f cf 00 00 00    	jg     0x22c
 15d:	49 83 fe 27          	cmp    r14,0x27
 161:	0f 84 87 01 00 00    	je     0x2ee
 167:	49 83 fe 38          	cmp    r14,0x38
 16b:	0f 84 36 01 00 00    	je     0x2a7
 171:	49 83 fe 39          	cmp    r14,0x39
 175:	74 05                	je     0x17c
 177:	e9 0d 02 00 00       	jmp    0x389
 17c:	41 bd 66 6f 72 6b    	mov    r13d,0x6b726f66
 182:	e9 ad 01 00 00       	jmp    0x334
 187:	49 81 fe 22 01 00 00 	cmp    r14,0x122
 18e:	0f 8f c6 00 00 00    	jg     0x25a
 194:	49 81 fe 01 01 00 00 	cmp    r14,0x101
 19b:	0f 84 59 01 00 00    	je     0x2fa
 1a1:	49 81 fe 07 01 00 00 	cmp    r14,0x107
 1a8:	0f 84 08 01 00 00    	je     0x2b6
 1ae:	49 81 fe 19 01 00 00 	cmp    r14,0x119
 1b5:	74 05                	je     0x1bc
 1b7:	e9 cd 01 00 00       	jmp    0x389
 1bc:	49 bd 73 74 61 74 32 	movabs r13,0x74613274617473
 1c3:	61 74 00 
 1c6:	e9 69 01 00 00       	jmp    0x334
 1cb:	49 83 fe 03          	cmp    r14,0x3
 1cf:	0f 84 31 01 00 00    	je     0x306
 1d5:	49 83 fe 09          	cmp    r14,0x9
 1d9:	0f 84 e3 00 00 00    	je     0x2c2
 1df:	49 83 fe 0c          	cmp    r14,0xc
 1e3:	74 05                	je     0x1ea
 1e5:	e9 9f 01 00 00       	jmp    0x389
 1ea:	41 bd 6b 62 72 6b    	mov    r13d,0x6b72626b
 1f0:	e9 3f 01 00 00       	jmp    0x334
 1f5:	49 81 fe 9e 00 00 00 	cmp    r14,0x9e
 1fc:	0f 84 10 01 00 00    	je     0x312
 202:	49 81 fe ca 00 00 00 	cmp    r14,0xca
 209:	0f 84 bb 00 00 00    	je     0x2ca
 20f:	49 81 fe d9 00 00 00 	cmp    r14,0xd9
 216:	74 05                	je     0x21d
 218:	e9 6c 01 00 00       	jmp    0x389
 21d:	49 bd 67 65 74 61 64 	movabs r13,0x646461746567
 224:	64 00 00 
 227:	e9 08 01 00 00       	jmp    0x334
 22c:	49 83 fe 3b          	cmp    r14,0x3b
 230:	0f 84 e8 00 00 00    	je     0x31e
 236:	49 83 fe 3c          	cmp    r14,0x3c
 23a:	0f 84 96 00 00 00    	je     0x2d6
 240:	49 83 fe 3d          	cmp    r14,0x3d
 244:	74 05                	je     0x24b
 246:	e9 3e 01 00 00       	jmp    0x389
 24b:	49 bd 55 77 61 69 74 	movabs r13,0x347469617755
 252:	34 00 00 
 255:	e9 da 00 00 00       	jmp    0x334
 25a:	49 81 fe 23 01 00 00 	cmp    r14,0x123
 261:	0f 84 c3 00 00 00    	je     0x32a
 267:	49 81 fe 41 01 00 00 	cmp    r14,0x141
 26e:	74 6e                	je     0x2de
 270:	49 81 fe 4c 01 00 00 	cmp    r14,0x14c
 277:	74 05                	je     0x27e
 279:	e9 0b 01 00 00       	jmp    0x389
 27e:	41 bd 73 61 74 78    	mov    r13d,0x78746173
 284:	e9 ab 00 00 00       	jmp    0x334
 289:	49 bd 77 72 69 74 65 	movabs r13,0x6574697277
 290:	00 00 00 
 293:	e9 9c 00 00 00       	jmp    0x334
 298:	49 bd 75 6e 6c 69 6e 	movabs r13,0x6b6e696c6e75
 29f:	6b 00 00 
 2a2:	e9 8d 00 00 00       	jmp    0x334
 2a7:	49 bd 55 63 6c 6f 6e 	movabs r13,0x656e6f6c6355
 2ae:	65 00 00 
 2b1:	e9 7e 00 00 00       	jmp    0x334
 2b6:	49 bd 75 6e 6c 69 6e 	movabs r13,0x74616b6e696c6e75
 2bd:	6b 61 74 
 2c0:	eb 72                	jmp    0x334
 2c2:	41 bd 6d 6d 61 70    	mov    r13d,0x70616d6d
 2c8:	eb 6a                	jmp    0x334
 2ca:	49 bd 55 66 75 74 65 	movabs r13,0x786574756655
 2d1:	78 00 00 
 2d4:	eb 5e                	jmp    0x334
 2d6:	41 bd 65 78 69 74    	mov    r13d,0x74697865
 2dc:	eb 56                	jmp    0x334
 2de:	41 bd 62 66 70 00    	mov    r13d,0x706662
 2e4:	eb 4e                	jmp    0x334
 2e6:	41 bd 63 68 64 69    	mov    r13d,0x69646863
 2ec:	eb 46                	jmp    0x334
 2ee:	49 bd 67 74 70 69 64 	movabs r13,0x6469707467
 2f5:	00 00 00 
 2f8:	eb 3a                	jmp    0x334
 2fa:	49 bd 6f 70 65 6e 61 	movabs r13,0x74616e65706f
 301:	74 00 00 
 304:	eb 2e                	jmp    0x334
 306:	49 bd 63 6c 6f 73 65 	movabs r13,0x65736f6c63
 30d:	00 00 00 
 310:	eb 22                	jmp    0x334
 312:	49 bd 61 72 63 68 5f 	movabs r13,0x6c74635f68637261
 319:	63 74 6c 
 31c:	eb 16                	jmp    0x334
 31e:	49 bd 65 78 65 63 76 	movabs r13,0x657663657865
 325:	65 00 00 
 328:	eb 0a                	jmp    0x334
 32a:	49 bd 73 69 67 6e 65 	movabs r13,0x647466656e676973
 331:	66 74 64 
 334:	48 c1 e3 20          	shl    rbx,0x20
 338:	48 c1 eb 20          	shr    rbx,0x20
 33c:	49 31 dd             	xor    r13,rbx
 33f:	48 89 f3             	mov    rbx,rsi
 342:	48 83 e3 07          	and    rbx,0x7
 346:	49 89 de             	mov    r14,rbx
 349:	49 83 f6 3f          	xor    r14,0x3f
 34d:	4d 89 ef             	mov    r15,r13
 350:	c4 42 8b f7 ff       	shrx   r15,r15,r14
 355:	49 89 de             	mov    r14,rbx
 358:	49 83 c6 01          	add    r14,0x1
 35c:	c4 42 89 f7 ed       	shlx   r13,r13,r14
 361:	4d 09 fd             	or     r13,r15
 364:	4d 01 c5             	add    r13,r8
 367:	48 c1 e3 03          	shl    rbx,0x3
 36b:	c4 e2 e1 f7 c0       	shlx   rax,rax,rbx
 370:	49 31 c5             	xor    r13,rax
 373:	48 83 c2 04          	add    rdx,0x4
 377:	48 83 c6 01          	add    rsi,0x1
 37b:	4d 89 e8             	mov    r8,r13
 37e:	48 83 fe 40          	cmp    rsi,0x40
 382:	74 19                	je     0x39d
 384:	e9 18 fd ff ff       	jmp    0xa1
 389:	48 c1 e3 20          	shl    rbx,0x20
 38d:	48 c1 eb 20          	shr    rbx,0x20
 391:	48 0f af d9          	imul   rbx,rcx
 395:	4c 31 c3             	xor    rbx,r8
 398:	49 89 dd             	mov    r13,rbx
 39b:	eb d6                	jmp    0x373
 39d:	4c 89 ee             	mov    rsi,r13
 3a0:	48 c1 ee 38          	shr    rsi,0x38
 3a4:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 3a8:	4c 89 ee             	mov    rsi,r13
 3ab:	48 c1 ee 30          	shr    rsi,0x30
 3af:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 3b3:	4c 89 ee             	mov    rsi,r13
 3b6:	48 c1 ee 28          	shr    rsi,0x28
 3ba:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 3be:	4c 89 ee             	mov    rsi,r13
 3c1:	48 c1 ee 20          	shr    rsi,0x20
 3c5:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 3c9:	4c 89 ee             	mov    rsi,r13
 3cc:	48 c1 ee 18          	shr    rsi,0x18
 3d0:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 3d4:	4c 89 ee             	mov    rsi,r13
 3d7:	48 c1 ee 10          	shr    rsi,0x10
 3db:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 3df:	44 88 6f 00          	mov    BYTE PTR [rdi+0x0],r13b
 3e3:	49 c1 ed 08          	shr    r13,0x8
 3e7:	44 88 6f 01          	mov    BYTE PTR [rdi+0x1],r13b
 3eb:	b8 02 00 00 00       	mov    eax,0x2
 3f0:	41 5f                	pop    r15
 3f2:	41 5e                	pop    r14
 3f4:	41 5d                	pop    r13
 3f6:	5b                   	pop    rbx
 3f7:	c9                   	leave
 3f8:	c3                   	ret
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
   d:	0f 87 8d 03 00 00    	ja     0x3a0
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 80 03 00 00    	ja     0x3a0
  20:	48 8d b1 0c 01 00 00 	lea    rsi,[rcx+0x10c]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 70 03 00 00    	ja     0x3a0
  30:	83 79 08 40          	cmp    DWORD PTR [rcx+0x8],0x40
  34:	0f 85 51 03 00 00    	jne    0x38b
  3a:	55                   	push   rbp
  3b:	41 57                	push   r15
  3d:	41 56                	push   r14
  3f:	41 55                	push   r13
  41:	41 54                	push   r12
  43:	53                   	push   rbx
  44:	49 be 63 6c 6f 73 65 	movabs r14,0x65736f6c63
  4b:	00 00 00 
  4e:	48 8d 51 0f          	lea    rdx,[rcx+0xf]
  52:	49 b9 09 c9 bc f3 67 	movabs r9,0x6a09e667f3bcc909
  59:	e6 09 6a 
  5c:	31 f6                	xor    esi,esi
  5e:	49 bc 55 6c 69 6e 6b 	movabs r12,0x6b6e696c55
  65:	00 00 00 
  68:	48 bd 87 ca eb 85 b1 	movabs rbp,0x9e3779b185ebca87
  6f:	79 37 9e 
  72:	48 bf 55 77 61 69 74 	movabs rdi,0x347469617755
  79:	34 00 00 
  7c:	41 bf 6f 70 65 6e    	mov    r15d,0x6e65706f
  82:	41 bd 64 61 65 72    	mov    r13d,0x72656164
  88:	eb 57                	jmp    0xe1
  8a:	49 8d 86 14 06 fa 00 	lea    rax,[r14+0xfa0614]
  91:	49 83 fb 01          	cmp    r11,0x1
  95:	49 0f 45 c7          	cmovne rax,r15
  99:	4d 85 db             	test   r11,r11
  9c:	49 0f 44 c5          	cmove  rax,r13
  a0:	4c 31 d8             	xor    rax,r11
  a3:	41 89 f0             	mov    r8d,esi
  a6:	41 83 e0 07          	and    r8d,0x7
  aa:	45 89 c3             	mov    r11d,r8d
  ad:	41 f6 d3             	not    r11b
  b0:	c4 62 a3 f7 d8       	shrx   r11,rax,r11
  b5:	41 8d 58 01          	lea    ebx,[r8+0x1]
  b9:	c4 e2 e1 f7 c0       	shlx   rax,rax,rbx
  be:	4c 09 d8             	or     rax,r11
  c1:	4c 01 c8             	add    rax,r9
  c4:	41 c1 e0 03          	shl    r8d,0x3
  c8:	c4 42 b9 f7 ca       	shlx   r9,r10,r8
  cd:	49 31 c1             	xor    r9,rax
  d0:	48 83 c2 04          	add    rdx,0x4
  d4:	48 ff c6             	inc    rsi
  d7:	48 83 fe 40          	cmp    rsi,0x40
  db:	0f 84 ad 02 00 00    	je     0x38e
  e1:	0f b6 42 fe          	movzx  eax,BYTE PTR [rdx-0x2]
  e5:	c1 e0 08             	shl    eax,0x8
  e8:	44 0f b6 52 fd       	movzx  r10d,BYTE PTR [rdx-0x3]
  ed:	44 0f b6 42 ff       	movzx  r8d,BYTE PTR [rdx-0x1]
  f2:	41 c1 e0 10          	shl    r8d,0x10
  f6:	41 09 c0             	or     r8d,eax
  f9:	44 0f b6 1a          	movzx  r11d,BYTE PTR [rdx]
  fd:	41 c1 e3 18          	shl    r11d,0x18
 101:	45 09 c3             	or     r11d,r8d
 104:	4d 09 d3             	or     r11,r10
 107:	49 83 fb 4f          	cmp    r11,0x4f
 10b:	76 53                	jbe    0x160
 10d:	41 81 fb 00 01 00 00 	cmp    r11d,0x100
 114:	0f 86 96 00 00 00    	jbe    0x1b0
 11a:	41 81 fb 22 01 00 00 	cmp    r11d,0x122
 121:	0f 86 1c 01 00 00    	jbe    0x243
 127:	49 81 fb 23 01 00 00 	cmp    r11,0x123
 12e:	0f 84 02 02 00 00    	je     0x336
 134:	41 81 fb 41 01 00 00 	cmp    r11d,0x141
 13b:	0f 84 9b 01 00 00    	je     0x2dc
 141:	b8 73 61 74 78       	mov    eax,0x78746173
 146:	41 81 fb 4c 01 00 00 	cmp    r11d,0x14c
 14d:	0f 84 4d ff ff ff    	je     0xa0
 153:	e9 78 01 00 00       	jmp    0x2d0
 158:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
 15f:	00 
 160:	41 83 fb 26          	cmp    r11d,0x26
 164:	0f 86 96 00 00 00    	jbe    0x200
 16a:	44 89 d0             	mov    eax,r10d
 16d:	41 83 fb 3a          	cmp    r11d,0x3a
 171:	0f 86 09 01 00 00    	jbe    0x280
 177:	24 7f                	and    al,0x7f
 179:	3c 3b                	cmp    al,0x3b
 17b:	0f 84 c4 01 00 00    	je     0x345
 181:	45 89 d0             	mov    r8d,r10d
 184:	41 83 e0 7f          	and    r8d,0x7f
 188:	41 83 f8 3c          	cmp    r8d,0x3c
 18c:	0f 84 54 01 00 00    	je     0x2e6
 192:	48 89 f8             	mov    rax,rdi
 195:	41 83 f8 3d          	cmp    r8d,0x3d
 199:	0f 84 01 ff ff ff    	je     0xa0
 19f:	e9 2c 01 00 00       	jmp    0x2d0
 1a4:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 1ab:	00 00 00 00 00 
 1b0:	41 81 fb 9d 00 00 00 	cmp    r11d,0x9d
 1b7:	0f 86 ef 00 00 00    	jbe    0x2ac
 1bd:	45 89 d8             	mov    r8d,r11d
 1c0:	41 81 e0 ff 01 00 00 	and    r8d,0x1ff
 1c7:	41 81 f8 9e 00 00 00 	cmp    r8d,0x9e
 1ce:	0f 84 80 01 00 00    	je     0x354
 1d4:	41 81 f8 ca 00 00 00 	cmp    r8d,0xca
 1db:	0f 84 0f 01 00 00    	je     0x2f0
 1e1:	48 b8 67 65 74 61 64 	movabs rax,0x646461746567
 1e8:	64 00 00 
 1eb:	41 81 f8 d9 00 00 00 	cmp    r8d,0xd9
 1f2:	0f 84 a8 fe ff ff    	je     0xa0
 1f8:	e9 d3 00 00 00       	jmp    0x2d0
 1fd:	0f 1f 00             	nop    DWORD PTR [rax]
 200:	41 83 fb 02          	cmp    r11d,0x2
 204:	0f 86 80 fe ff ff    	jbe    0x8a
 20a:	45 89 d0             	mov    r8d,r10d
 20d:	41 80 e0 3f          	and    r8b,0x3f
 211:	4c 89 f0             	mov    rax,r14
 214:	41 80 f8 03          	cmp    r8b,0x3
 218:	0f 84 82 fe ff ff    	je     0xa0
 21e:	45 89 d0             	mov    r8d,r10d
 221:	41 83 e0 3f          	and    r8d,0x3f
 225:	41 83 f8 09          	cmp    r8d,0x9
 229:	0f 84 d0 00 00 00    	je     0x2ff
 22f:	b8 6b 62 72 6b       	mov    eax,0x6b72626b
 234:	41 83 f8 0c          	cmp    r8d,0xc
 238:	0f 84 62 fe ff ff    	je     0xa0
 23e:	e9 8d 00 00 00       	jmp    0x2d0
 243:	45 89 d8             	mov    r8d,r11d
 246:	41 81 e0 ff 01 00 00 	and    r8d,0x1ff
 24d:	41 81 f8 01 01 00 00 	cmp    r8d,0x101
 254:	0f 84 09 01 00 00    	je     0x363
 25a:	41 81 f8 07 01 00 00 	cmp    r8d,0x107
 261:	0f 84 a2 00 00 00    	je     0x309
 267:	48 b8 73 74 61 74 32 	movabs rax,0x74613274617473
 26e:	61 74 00 
 271:	41 81 f8 19 01 00 00 	cmp    r8d,0x119
 278:	0f 84 22 fe ff ff    	je     0xa0
 27e:	eb 50                	jmp    0x2d0
 280:	24 3f                	and    al,0x3f
 282:	3c 27                	cmp    al,0x27
 284:	0f 84 e8 00 00 00    	je     0x372
 28a:	45 89 d0             	mov    r8d,r10d
 28d:	41 83 e0 3f          	and    r8d,0x3f
 291:	41 83 f8 38          	cmp    r8d,0x38
 295:	0f 84 7d 00 00 00    	je     0x318
 29b:	b8 66 6f 72 6b       	mov    eax,0x6b726f66
 2a0:	41 83 f8 39          	cmp    r8d,0x39
 2a4:	0f 84 f6 fd ff ff    	je     0xa0
 2aa:	eb 24                	jmp    0x2d0
 2ac:	49 83 fa 50          	cmp    r10,0x50
 2b0:	0f 84 cb 00 00 00    	je     0x381
 2b6:	41 83 fa 57          	cmp    r10d,0x57
 2ba:	74 6b                	je     0x327
 2bc:	4c 89 e0             	mov    rax,r12
 2bf:	41 83 fa 59          	cmp    r10d,0x59
 2c3:	0f 84 d7 fd ff ff    	je     0xa0
 2c9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
 2d0:	4c 0f af dd          	imul   r11,rbp
 2d4:	4d 31 d9             	xor    r9,r11
 2d7:	e9 f4 fd ff ff       	jmp    0xd0
 2dc:	b8 62 66 70 00       	mov    eax,0x706662
 2e1:	e9 ba fd ff ff       	jmp    0xa0
 2e6:	b8 65 78 69 74       	mov    eax,0x74697865
 2eb:	e9 b0 fd ff ff       	jmp    0xa0
 2f0:	48 b8 55 66 75 74 65 	movabs rax,0x786574756655
 2f7:	78 00 00 
 2fa:	e9 a1 fd ff ff       	jmp    0xa0
 2ff:	b8 6d 6d 61 70       	mov    eax,0x70616d6d
 304:	e9 97 fd ff ff       	jmp    0xa0
 309:	48 b8 75 6e 6c 69 6e 	movabs rax,0x74616b6e696c6e75
 310:	6b 61 74 
 313:	e9 88 fd ff ff       	jmp    0xa0
 318:	48 b8 55 63 6c 6f 6e 	movabs rax,0x656e6f6c6355
 31f:	65 00 00 
 322:	e9 79 fd ff ff       	jmp    0xa0
 327:	48 b8 75 6e 6c 69 6e 	movabs rax,0x6b6e696c6e75
 32e:	6b 00 00 
 331:	e9 6a fd ff ff       	jmp    0xa0
 336:	48 b8 73 69 67 6e 65 	movabs rax,0x647466656e676973
 33d:	66 74 64 
 340:	e9 5b fd ff ff       	jmp    0xa0
 345:	48 b8 65 78 65 63 76 	movabs rax,0x657663657865
 34c:	65 00 00 
 34f:	e9 4c fd ff ff       	jmp    0xa0
 354:	48 b8 61 72 63 68 5f 	movabs rax,0x6c74635f68637261
 35b:	63 74 6c 
 35e:	e9 3d fd ff ff       	jmp    0xa0
 363:	48 b8 6f 70 65 6e 61 	movabs rax,0x74616e65706f
 36a:	74 00 00 
 36d:	e9 2e fd ff ff       	jmp    0xa0
 372:	48 b8 67 74 70 69 64 	movabs rax,0x6469707467
 379:	00 00 00 
 37c:	e9 1f fd ff ff       	jmp    0xa0
 381:	b8 63 68 64 69       	mov    eax,0x69646863
 386:	e9 15 fd ff ff       	jmp    0xa0
 38b:	31 c0                	xor    eax,eax
 38d:	c3                   	ret
 38e:	4c 89 09             	mov    QWORD PTR [rcx],r9
 391:	b8 02 00 00 00       	mov    eax,0x2
 396:	5b                   	pop    rbx
 397:	41 5c                	pop    r12
 399:	41 5d                	pop    r13
 39b:	41 5e                	pop    r14
 39d:	41 5f                	pop    r15
 39f:	5d                   	pop    rbp
 3a0:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 30
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rsi],0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rsi],0x40]
 * - 0x1129: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112a: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112c: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x112e: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1130: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x114a: lea    r10,[rip+0xeaf] [warning-unmapped: LEA operands are not representable]
 * - 0x1151: lea    r11,[rsi+0xfa0614] [warning-unmapped: LEA operands are not representable]
 * - 0x1158: lea    r15,[rip+0x111d] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111d]]
 * - 0x1169: movabs rbp,0x74613274617473 [warning-unmapped: unsupported mnemonic or operand form: movabs rbp,0x74613274617473]
 * - 0x1173: movabs r9,0x647466656e676973 [warning-reg-remap: 64-bit immediate load; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11ac: movsxd rcx,DWORD PTR [r10+rcx*4] [warning-unmapped: movsxd SIB operand is not in the BPF register file: DWORD PTR [r10+rcx*4]]
 * - 0x11b0: add    rcx,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x11b3: jmp    rcx [warning-unmapped: cannot parse branch target rcx]
 * - 0x11d9: jmp    rcx [warning-unmapped: cannot parse branch target rcx]
 * - 0x1236: mov    rcx,rbp [warning-unmapped: unsupported mnemonic or operand form: mov    rcx,rbp]
 * - 0x123e: mov    rcx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c8: mov    rcx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rcx,r11]
 * - 0x130e: mov    r12,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r12,rbx]
 * - 0x1311: shl    r12,cl [warning-unmapped: ALU destination r12 is not in the BPF JIT register file]
 * - 0x1323: or     rbx,r12 [warning-unmapped: ALU source r12 is not supported]
 * - 0x1344: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1345: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1347: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1349: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x134b: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x134d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1109: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <tracee_syscall_name_table_lookup_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rdi,[rdx+0x10c] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_3, 0, 0, 1, 0, 268), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> [bpf-branch: lowered cmp    rdi,rcx + ja     110e <tracee_syscall_name_table_lookup_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rsi],0x40 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rsi],0x40] */
    /* 0x1127: jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rsi],0x40 + jne    110e <tracee_syscall_name_table_lookup_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 0),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 64),
    /* 0x1129: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112a: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112c: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x112e: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1130: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1132: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1133: movabs r14,0x6a09e667f3bcc909 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_8, 0, 0x6a09e667f3bcc909ULL),
    /* 0x113d: movabs rsi,0x65736f6c63 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x65736f6c63ULL),
    /* 0x1147: xor    r8d,r8d [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 0),
    /* 0x114a: lea    r10,[rip+0xeaf] [warning-unmapped: LEA operands are not representable] */
    /* 0x1151: lea    r11,[rsi+0xfa0614] [warning-unmapped: LEA operands are not representable] */
    /* 0x1158: lea    r15,[rip+0x111d] [warning-unmapped: LEA base/index not in BPF register file: [rip+0x111d]] */
    /* 0x115f: movabs r13,0x74616b6e696c6e75 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_7, 0, 0x74616b6e696c6e75ULL),
    /* 0x1169: movabs rbp,0x74613274617473 [warning-unmapped: unsupported mnemonic or operand form: movabs rbp,0x74613274617473] */
    /* 0x1173: movabs r9,0x647466656e676973 [warning-reg-remap: 64-bit immediate load; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_LD_IMM64_RAW(BPF_REG_9, 0, 0x647466656e676973ULL),
    /* 0x117d: nop    DWORD PTR [rax] [padding: padding is not part of BPF semantics] */
    /* 0x1180: movzx  edi,BYTE PTR [rdx+r8*4+0xc] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_1, BPF_REG_3, BPF_REG_5, 2, 12), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x1186: movzx  ecx,BYTE PTR [rdx+r8*4+0xd] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_4, BPF_REG_3, BPF_REG_5, 2, 13), MICRO_HANDCRAFT_BPF_X86_MOVZBL_SIB),
    /* 0x118c: shl    ecx,0x8 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 8),
    /* 0x118f: or     ecx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_4, BPF_REG_1, 0, 0),
    /* 0x1191: movzx  eax,WORD PTR [rdx+r8*4+0xe] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_SIB_PAYLOAD(BPF_REG_0, BPF_REG_3, BPF_REG_5, 2, 14), MICRO_HANDCRAFT_BPF_X86_MOVZWL_SIB),
    /* 0x1197: shl    eax,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 16),
    /* 0x119a: or     eax,ecx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_0, BPF_REG_4, 0, 0),
    /* 0x119c: cmp    eax,0xd8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 216), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a1: jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0> [bpf-branch: lowered cmp    eax,0xd8 + jg     11c0 <tracee_syscall_name_table_lookup_xdp+0xc0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_0, 0, 6, 216),
    /* 0x11a3: cmp    eax,0x9e [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 158), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a8: ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118> [bpf-branch: lowered cmp    eax,0x9e + ja     1218 <tracee_syscall_name_table_lookup_xdp+0x118> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_0, 0, 31, 158),
    /* 0x11aa: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x11ac: movsxd rcx,DWORD PTR [r10+rcx*4] [warning-unmapped: movsxd SIB operand is not in the BPF register file: DWORD PTR [r10+rcx*4]] */
    /* 0x11b0: add    rcx,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x11b3: jmp    rcx [warning-unmapped: cannot parse branch target rcx] */
    /* 0x11b5: mov    ecx,0x72656164 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1919246692),
    /* 0x11ba: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 86, 0),
    /* 0x11bf: nop [padding: padding is not part of BPF semantics] */
    /* 0x11c0: cmp    eax,0x140 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 320), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11c5: jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea> [bpf-branch: lowered cmp    eax,0x140 + jg     11ea <tracee_syscall_name_table_lookup_xdp+0xea> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JSGT | BPF_K, BPF_REG_0, 0, 11, 320),
    /* 0x11c7: lea    ecx,[rax-0x101] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, -257), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x11cd: cmp    ecx,0x22 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 34), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11d0: ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102> [bpf-branch: lowered cmp    ecx,0x22 + ja     1202 <tracee_syscall_name_table_lookup_xdp+0x102> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_K, BPF_REG_4, 0, 14, 34),
    /* 0x11d2: movsxd rcx,DWORD PTR [r15+rcx*4] [exact-kinsn: movsxd SIB kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_SIB_TMP_PAYLOAD(BPF_REG_4, BPF_REG_9, BPF_REG_4, 2, 0, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVSXD_SIB),
    /* 0x11d6: add    rcx,r15 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_4, BPF_REG_9, 0, 0),
    /* 0x11d9: jmp    rcx [warning-unmapped: cannot parse branch target rcx] */
    /* 0x11db: movabs rcx,0x74616e65706f [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x74616e65706fULL),
    /* 0x11e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 72, 0),
    /* 0x11ea: cmp    eax,0x141 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 321), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11ef: je     1246 <tracee_syscall_name_table_lookup_xdp+0x146> [bpf-branch: lowered cmp    eax,0x141 + je     1246 <tracee_syscall_name_table_lookup_xdp+0x146> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_0, 0, 24, 321),
    /* 0x11f1: cmp    eax,0x14c [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 332), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11f6: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [bpf-branch: lowered cmp    eax,0x14c + jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 23, 332),
    /* 0x11f8: mov    ecx,0x78746173 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 2020893043),
    /* 0x11fd: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 64, 0),
    /* 0x1202: cmp    eax,0xd9 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 217), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1207: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [bpf-branch: lowered cmp    eax,0xd9 + jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 18, 217),
    /* 0x1209: movabs rcx,0x646461746567 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x646461746567ULL),
    /* 0x1213: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 58, 0),
    /* 0x1218: cmp    eax,0xca [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 202), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x121d: jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> [bpf-branch: lowered cmp    eax,0xca + jne    1250 <tracee_syscall_name_table_lookup_xdp+0x150> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, 12, 202),
    /* 0x121f: movabs rcx,0x786574756655 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x786574756655ULL),
    /* 0x1229: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 52, 0),
    /* 0x122e: mov    rcx,r13 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1231: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 49, 0),
    /* 0x1236: mov    rcx,rbp [warning-unmapped: unsupported mnemonic or operand form: mov    rcx,rbp] */
    /* 0x1239: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 48, 0),
    /* 0x123e: mov    rcx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1241: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 45, 0),
    /* 0x1246: mov    ecx,0x706662 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 7366242),
    /* 0x124b: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 43, 0),
    /* 0x1250: mov    eax,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_0, 0, 0),
    /* 0x1252: movabs rcx,0x9e3779b185ebca87 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x9e3779b185ebca87ULL),
    /* 0x125c: imul   rax,rcx [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_IMULQ_RR),
    /* 0x1260: xor    r14,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_0, 0, 0),
    /* 0x1263: jmp    132f <tracee_syscall_name_table_lookup_xdp+0x22f> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 54, 0),
    /* 0x1268: movabs rcx,0x657663657865 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x657663657865ULL),
    /* 0x1272: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 33, 0),
    /* 0x1277: movabs rcx,0x6469707467 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6469707467ULL),
    /* 0x1281: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 30, 0),
    /* 0x1283: mov    ecx,0x70616d6d [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1885433197),
    /* 0x1288: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 28, 0),
    /* 0x128a: movabs rcx,0x6b6e696c6e75 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c6e75ULL),
    /* 0x1294: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 25, 0),
    /* 0x1296: movabs rcx,0x656e6f6c6355 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x656e6f6c6355ULL),
    /* 0x12a0: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 22, 0),
    /* 0x12a2: movabs rcx,0x347469617755 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x347469617755ULL),
    /* 0x12ac: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 19, 0),
    /* 0x12ae: mov    ecx,0x6e65706f [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1852141679),
    /* 0x12b3: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 17, 0),
    /* 0x12b5: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x12b8: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 14, 0),
    /* 0x12ba: mov    ecx,0x6b726f66 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1802661734),
    /* 0x12bf: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 12, 0),
    /* 0x12c1: mov    ecx,0x74697865 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1953069157),
    /* 0x12c6: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 10, 0),
    /* 0x12c8: mov    rcx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rcx,r11] */
    /* 0x12cb: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 9, 0),
    /* 0x12cd: movabs rcx,0x6b6e696c55 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6b6e696c55ULL),
    /* 0x12d7: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 6, 0),
    /* 0x12d9: mov    ecx,0x6b72626b [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1802658411),
    /* 0x12de: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 4, 0),
    /* 0x12e0: mov    ecx,0x69646863 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 1768188003),
    /* 0x12e5: jmp    1300 <tracee_syscall_name_table_lookup_xdp+0x200> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 2, 0),
    /* 0x12e7: movabs rcx,0x6c74635f68637261 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_4, 0, 0x6c74635f68637261ULL),
    /* 0x12f1: data16 data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1300: mov    ebx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x1302: xor    rbx,rcx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x1305: mov    eax,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_0, BPF_REG_5, 0, 0),
    /* 0x1308: and    eax,0x7 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 7), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x130b: lea    ecx,[rax+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_0, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x130e: mov    r12,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r12,rbx] */
    /* 0x1311: shl    r12,cl [warning-unmapped: ALU destination r12 is not in the BPF JIT register file] */
    /* 0x1314: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1316: not    cl [exact-kinsn: notb reg kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_NOTB_R),
    /* 0x1318: shr    rbx,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_RSH | BPF_X, BPF_REG_6, BPF_REG_4, 0, 0),
    /* 0x131b: shl    eax,0x3 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_0, 0, 0, 3),
    /* 0x131e: mov    ecx,eax [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_4, BPF_REG_0, 0, 0),
    /* 0x1320: shl    rdi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x1323: or     rbx,r12 [warning-unmapped: ALU source r12 is not supported] */
    /* 0x1326: add    rbx,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_8, 0, 0),
    /* 0x1329: xor    rdi,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_6, 0, 0),
    /* 0x132c: mov    r14,rdi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x132f: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1332: cmp    r8,0x40 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 64), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1336: jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> [bpf-branch: lowered cmp    r8,0x40 + jne    1180 <tracee_syscall_name_table_lookup_xdp+0x80> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_5, 0, -128, 64),
    /* 0x133c: mov    QWORD PTR [rdx],r14 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x133f: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1344: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1345: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1347: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1349: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134b: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134d: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x134e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
