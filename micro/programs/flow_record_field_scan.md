# flow_record_field_scan

## Original C
```c
#include "common.h"

#define STRUCT_FIELD_CLUSTER_RECORDS 32U

struct flow_record_field_scan_record {
    __u32 tag;
    __u16 flags;
    __u16 length;
    __u64 src;
    __u64 dst;
    __u32 sport;
    __u32 dport;
};

struct flow_record_field_scan_layout {
    __u32 record_count;
    __u32 record_size;
    struct flow_record_field_scan_record records[STRUCT_FIELD_CLUSTER_RECORDS];
};

#define STRUCT_FIELD_CLUSTER_INPUT_SIZE sizeof(struct flow_record_field_scan_layout)

static __always_inline int
bench_flow_record_field_scan(const u8 *data, u32 len, u64 *out)
{
    (void)len;

    const struct flow_record_field_scan_layout *layout =
        (const struct flow_record_field_scan_layout *)(const void *)data;
    if (layout->record_count != STRUCT_FIELD_CLUSTER_RECORDS ||
        layout->record_size != sizeof(struct flow_record_field_scan_record)) {
        return -1;
    }

    u64 acc = 0x9E3779B97F4A7C15ULL;
    for (u32 index = 0; index < STRUCT_FIELD_CLUSTER_RECORDS; index++) {
        const struct flow_record_field_scan_record *record = &layout->records[index];
        u64 tuple = record->src + record->dst;
        u64 ports = ((u64)record->sport << 32U) | record->dport;

        acc += tuple ^ (((u64)record->tag << 16U) | record->flags);
        if ((record->flags & 1U) != 0U) {
            acc ^= ports + record->length;
        } else {
            acc += (record->dst >> (index & 7U)) ^ ports;
        }
        acc ^= (u64)record->tag << ((index & 3U) * 8U);
        acc = micro_rotl64(acc, (record->tag & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    flow_record_field_scan_xdp,
    bench_flow_record_field_scan,
    flow_record_field_scan_input_value,
    STRUCT_FIELD_CLUSTER_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <flow_record_field_scan_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <flow_record_field_scan_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <flow_record_field_scan_xdp+0xe>
    1118:	48 8d ba 10 04 00 00 	lea    rdi,[rdx+0x410]
    111f:	48 39 cf             	cmp    rdi,rcx
    1122:	77 ea                	ja     110e <flow_record_field_scan_xdp+0xe>
    1124:	83 3e 20             	cmp    DWORD PTR [rsi],0x20
    1127:	75 e5                	jne    110e <flow_record_field_scan_xdp+0xe>
    1129:	83 7a 0c 20          	cmp    DWORD PTR [rdx+0xc],0x20
    112d:	75 df                	jne    110e <flow_record_field_scan_xdp+0xe>
    112f:	53                   	push   rbx
    1130:	49 b8 15 7c 4a 7f b9 	movabs r8,0x9e3779b97f4a7c15
    1137:	79 37 9e 
    113a:	31 f6                	xor    esi,esi
    113c:	31 ff                	xor    edi,edi
    113e:	eb 3e                	jmp    117e <flow_record_field_scan_xdp+0x7e>
    1140:	89 f9                	mov    ecx,edi
    1142:	80 e1 07             	and    cl,0x7
    1145:	49 d3 ea             	shr    r10,cl
    1148:	4d 31 d1             	xor    r9,r10
    114b:	4d 01 d9             	add    r9,r11
    114e:	89 f1                	mov    ecx,esi
    1150:	80 e1 18             	and    cl,0x18
    1153:	49 89 c0             	mov    r8,rax
    1156:	49 d3 e0             	shl    r8,cl
    1159:	4d 31 c8             	xor    r8,r9
    115c:	24 07                	and    al,0x7
    115e:	8d 48 01             	lea    ecx,[rax+0x1]
    1161:	4c 89 c3             	mov    rbx,r8
    1164:	48 d3 e3             	shl    rbx,cl
    1167:	f6 d0                	not    al
    1169:	89 c1                	mov    ecx,eax
    116b:	49 d3 e8             	shr    r8,cl
    116e:	49 09 d8             	or     r8,rbx
    1171:	48 ff c7             	inc    rdi
    1174:	48 83 c6 08          	add    rsi,0x8
    1178:	48 83 ff 20          	cmp    rdi,0x20
    117c:	74 48                	je     11c6 <flow_record_field_scan_xdp+0xc6>
    117e:	4c 8b 54 b2 20       	mov    r10,QWORD PTR [rdx+rsi*4+0x20]
    1183:	48 8b 4c b2 18       	mov    rcx,QWORD PTR [rdx+rsi*4+0x18]
    1188:	4c 01 d1             	add    rcx,r10
    118b:	8b 44 b2 28          	mov    eax,DWORD PTR [rdx+rsi*4+0x28]
    118f:	48 c1 e0 20          	shl    rax,0x20
    1193:	44 8b 4c b2 2c       	mov    r9d,DWORD PTR [rdx+rsi*4+0x2c]
    1198:	49 09 c1             	or     r9,rax
    119b:	8b 44 b2 10          	mov    eax,DWORD PTR [rdx+rsi*4+0x10]
    119f:	49 89 c3             	mov    r11,rax
    11a2:	49 c1 e3 10          	shl    r11,0x10
    11a6:	0f b7 5c b2 14       	movzx  ebx,WORD PTR [rdx+rsi*4+0x14]
    11ab:	49 09 db             	or     r11,rbx
    11ae:	49 31 cb             	xor    r11,rcx
    11b1:	4d 01 c3             	add    r11,r8
    11b4:	f6 c3 01             	test   bl,0x1
    11b7:	74 87                	je     1140 <flow_record_field_scan_xdp+0x40>
    11b9:	0f b7 4c b2 16       	movzx  ecx,WORD PTR [rdx+rsi*4+0x16]
    11be:	49 01 c9             	add    r9,rcx
    11c1:	4d 31 d9             	xor    r9,r11
    11c4:	eb 88                	jmp    114e <flow_record_field_scan_xdp+0x4e>
    11c6:	44 88 02             	mov    BYTE PTR [rdx],r8b
    11c9:	88 7a 01             	mov    BYTE PTR [rdx+0x1],bh
    11cc:	89 d8                	mov    eax,ebx
    11ce:	c1 e8 10             	shr    eax,0x10
    11d1:	88 42 02             	mov    BYTE PTR [rdx+0x2],al
    11d4:	89 d8                	mov    eax,ebx
    11d6:	c1 e8 18             	shr    eax,0x18
    11d9:	88 42 03             	mov    BYTE PTR [rdx+0x3],al
    11dc:	48 89 d8             	mov    rax,rbx
    11df:	48 c1 e8 20          	shr    rax,0x20
    11e3:	88 42 04             	mov    BYTE PTR [rdx+0x4],al
    11e6:	48 89 d8             	mov    rax,rbx
    11e9:	48 c1 e8 28          	shr    rax,0x28
    11ed:	88 42 05             	mov    BYTE PTR [rdx+0x5],al
    11f0:	48 89 d8             	mov    rax,rbx
    11f3:	48 c1 e8 30          	shr    rax,0x30
    11f7:	88 42 06             	mov    BYTE PTR [rdx+0x6],al
    11fa:	48 c1 eb 38          	shr    rbx,0x38
    11fe:	88 5a 07             	mov    BYTE PTR [rdx+0x7],bl
    1201:	b8 02 00 00 00       	mov    eax,0x2
    1206:	5b                   	pop    rbx
    1207:	c3                   	ret

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
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	4c 8b 7f 00          	mov    r15,QWORD PTR [rdi+0x0]
  24:	49 39 f7             	cmp    r15,rsi
  27:	0f 87 64 01 00 00    	ja     0x191
  2d:	4c 89 fa             	mov    rdx,r15
  30:	48 83 c2 08          	add    rdx,0x8
  34:	48 39 f2             	cmp    rdx,rsi
  37:	0f 87 54 01 00 00    	ja     0x191
  3d:	4c 89 f9             	mov    rcx,r15
  40:	48 81 c1 10 04 00 00 	add    rcx,0x410
  47:	48 39 f1             	cmp    rcx,rsi
  4a:	0f 87 41 01 00 00    	ja     0x191
  50:	8b 72 00             	mov    esi,DWORD PTR [rdx+0x0]
  53:	48 83 fe 20          	cmp    rsi,0x20
  57:	0f 85 34 01 00 00    	jne    0x191
  5d:	41 8b 77 0c          	mov    esi,DWORD PTR [r15+0xc]
  61:	48 83 fe 20          	cmp    rsi,0x20
  65:	0f 85 26 01 00 00    	jne    0x191
  6b:	48 bb 15 7c 4a 7f b9 	movabs rbx,0x9e3779b97f4a7c15
  72:	79 37 9e 
  75:	31 ff                	xor    edi,edi
  77:	31 d2                	xor    edx,edx
  79:	31 c9                	xor    ecx,ecx
  7b:	4c 89 7d f0          	mov    QWORD PTR [rbp-0x10],r15
  7f:	eb 63                	jmp    0xe4
  81:	48 89 ce             	mov    rsi,rcx
  84:	48 83 e6 07          	and    rsi,0x7
  88:	c4 e2 cb f7 ff       	shrx   rdi,rdi,rsi
  8d:	49 31 f8             	xor    r8,rdi
  90:	4d 01 c5             	add    r13,r8
  93:	4d 89 e8             	mov    r8,r13
  96:	48 89 d7             	mov    rdi,rdx
  99:	48 83 e7 18          	and    rdi,0x18
  9d:	48 89 c6             	mov    rsi,rax
  a0:	c4 e2 c1 f7 f6       	shlx   rsi,rsi,rdi
  a5:	49 31 f0             	xor    r8,rsi
  a8:	48 83 e0 07          	and    rax,0x7
  ac:	48 89 c7             	mov    rdi,rax
  af:	48 83 f7 3f          	xor    rdi,0x3f
  b3:	4c 89 c6             	mov    rsi,r8
  b6:	c4 e2 c3 f7 f6       	shrx   rsi,rsi,rdi
  bb:	48 83 c0 01          	add    rax,0x1
  bf:	c4 42 f9 f7 c0       	shlx   r8,r8,rax
  c4:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
  c8:	48 83 c7 20          	add    rdi,0x20
  cc:	48 83 c2 08          	add    rdx,0x8
  d0:	4c 89 c3             	mov    rbx,r8
  d3:	48 09 f3             	or     rbx,rsi
  d6:	48 83 c1 01          	add    rcx,0x1
  da:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
  de:	48 83 f9 20          	cmp    rcx,0x20
  e2:	74 5a                	je     0x13e
  e4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  e8:	49 01 ff             	add    r15,rdi
  eb:	4d 8b 47 18          	mov    r8,QWORD PTR [r15+0x18]
  ef:	49 8b 7f 20          	mov    rdi,QWORD PTR [r15+0x20]
  f3:	49 89 fe             	mov    r14,rdi
  f6:	4d 01 c6             	add    r14,r8
  f9:	49 0f b7 77 14       	movzx  rsi,WORD PTR [r15+0x14]
  fe:	41 8b 47 10          	mov    eax,DWORD PTR [r15+0x10]
 102:	49 89 c5             	mov    r13,rax
 105:	49 c1 e5 10          	shl    r13,0x10
 109:	49 09 f5             	or     r13,rsi
 10c:	4d 31 f5             	xor    r13,r14
 10f:	49 01 dd             	add    r13,rbx
 112:	41 8b 5f 2c          	mov    ebx,DWORD PTR [r15+0x2c]
 116:	45 8b 47 28          	mov    r8d,DWORD PTR [r15+0x28]
 11a:	49 c1 e0 20          	shl    r8,0x20
 11e:	49 09 d8             	or     r8,rbx
 121:	48 83 e6 01          	and    rsi,0x1
 125:	48 85 f6             	test   rsi,rsi
 128:	0f 84 53 ff ff ff    	je     0x81
 12e:	49 0f b7 7f 16       	movzx  rdi,WORD PTR [r15+0x16]
 133:	49 01 f8             	add    r8,rdi
 136:	4d 31 e8             	xor    r8,r13
 139:	e9 58 ff ff ff       	jmp    0x96
 13e:	41 88 5f 00          	mov    BYTE PTR [r15+0x0],bl
 142:	4c 89 c6             	mov    rsi,r8
 145:	48 c1 ee 38          	shr    rsi,0x38
 149:	41 88 77 07          	mov    BYTE PTR [r15+0x7],sil
 14d:	4c 89 c6             	mov    rsi,r8
 150:	48 c1 ee 30          	shr    rsi,0x30
 154:	41 88 77 06          	mov    BYTE PTR [r15+0x6],sil
 158:	4c 89 c6             	mov    rsi,r8
 15b:	48 c1 ee 28          	shr    rsi,0x28
 15f:	41 88 77 05          	mov    BYTE PTR [r15+0x5],sil
 163:	4c 89 c6             	mov    rsi,r8
 166:	48 c1 ee 20          	shr    rsi,0x20
 16a:	41 88 77 04          	mov    BYTE PTR [r15+0x4],sil
 16e:	4c 89 c6             	mov    rsi,r8
 171:	48 c1 ee 18          	shr    rsi,0x18
 175:	41 88 77 03          	mov    BYTE PTR [r15+0x3],sil
 179:	4c 89 c6             	mov    rsi,r8
 17c:	48 c1 ee 10          	shr    rsi,0x10
 180:	41 88 77 02          	mov    BYTE PTR [r15+0x2],sil
 184:	49 c1 e8 08          	shr    r8,0x8
 188:	45 88 47 01          	mov    BYTE PTR [r15+0x1],r8b
 18c:	b8 02 00 00 00       	mov    eax,0x2
 191:	41 5f                	pop    r15
 193:	41 5e                	pop    r14
 195:	41 5d                	pop    r13
 197:	5b                   	pop    rbx
 198:	c9                   	leave
 199:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   6:	8b 57 04             	mov    edx,DWORD PTR [rdi+0x4]
   9:	39 d1                	cmp    ecx,edx
   b:	76 03                	jbe    0x10
   d:	31 c0                	xor    eax,eax
   f:	c3                   	ret
  10:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  14:	31 c0                	xor    eax,eax
  16:	48 39 d6             	cmp    rsi,rdx
  19:	0f 87 0d 01 00 00    	ja     0x12c
  1f:	48 8d b9 10 04 00 00 	lea    rdi,[rcx+0x410]
  26:	48 39 d7             	cmp    rdi,rdx
  29:	0f 87 fd 00 00 00    	ja     0x12c
  2f:	83 3e 20             	cmp    DWORD PTR [rsi],0x20
  32:	75 d9                	jne    0xd
  34:	83 79 0c 20          	cmp    DWORD PTR [rcx+0xc],0x20
  38:	75 d3                	jne    0xd
  3a:	53                   	push   rbx
  3b:	49 b8 15 7c 4a 7f b9 	movabs r8,0x9e3779b97f4a7c15
  42:	79 37 9e 
  45:	31 c0                	xor    eax,eax
  47:	48 89 ca             	mov    rdx,rcx
  4a:	31 f6                	xor    esi,esi
  4c:	eb 50                	jmp    0x9e
  4e:	66 90                	xchg   ax,ax
  50:	41 89 f3             	mov    r11d,esi
  53:	41 80 e3 07          	and    r11b,0x7
  57:	c4 42 a3 f7 d2       	shrx   r10,r10,r11
  5c:	4d 31 d0             	xor    r8,r10
  5f:	4d 01 c8             	add    r8,r9
  62:	41 89 c1             	mov    r9d,eax
  65:	41 80 e1 18          	and    r9b,0x18
  69:	c4 62 b1 f7 cf       	shlx   r9,rdi,r9
  6e:	4d 31 c1             	xor    r9,r8
  71:	40 80 e7 07          	and    dil,0x7
  75:	41 89 f8             	mov    r8d,edi
  78:	41 f6 d0             	not    r8b
  7b:	c4 42 bb f7 c1       	shrx   r8,r9,r8
  80:	40 fe c7             	inc    dil
  83:	c4 c2 c1 f7 d9       	shlx   rbx,r9,rdi
  88:	48 83 c0 08          	add    rax,0x8
  8c:	49 09 d8             	or     r8,rbx
  8f:	48 ff c6             	inc    rsi
  92:	48 83 c2 20          	add    rdx,0x20
  96:	48 3d 00 01 00 00    	cmp    rax,0x100
  9c:	74 4a                	je     0xe8
  9e:	4c 8b 52 20          	mov    r10,QWORD PTR [rdx+0x20]
  a2:	4c 8b 5a 18          	mov    r11,QWORD PTR [rdx+0x18]
  a6:	4d 01 d3             	add    r11,r10
  a9:	0f b7 5a 14          	movzx  ebx,WORD PTR [rdx+0x14]
  ad:	8b 7a 10             	mov    edi,DWORD PTR [rdx+0x10]
  b0:	49 89 f9             	mov    r9,rdi
  b3:	49 c1 e1 10          	shl    r9,0x10
  b7:	49 09 d9             	or     r9,rbx
  ba:	4d 31 d9             	xor    r9,r11
  bd:	4d 01 c1             	add    r9,r8
  c0:	44 8b 5a 2c          	mov    r11d,DWORD PTR [rdx+0x2c]
  c4:	44 8b 42 28          	mov    r8d,DWORD PTR [rdx+0x28]
  c8:	49 c1 e0 20          	shl    r8,0x20
  cc:	4d 09 d8             	or     r8,r11
  cf:	f6 c3 01             	test   bl,0x1
  d2:	0f 84 78 ff ff ff    	je     0x50
  d8:	44 0f b7 52 16       	movzx  r10d,WORD PTR [rdx+0x16]
  dd:	4d 01 d0             	add    r8,r10
  e0:	4d 31 c8             	xor    r8,r9
  e3:	e9 7a ff ff ff       	jmp    0x62
  e8:	44 88 01             	mov    BYTE PTR [rcx],r8b
  eb:	48 89 d8             	mov    rax,rbx
  ee:	48 c1 e8 38          	shr    rax,0x38
  f2:	88 41 07             	mov    BYTE PTR [rcx+0x7],al
  f5:	48 89 d8             	mov    rax,rbx
  f8:	48 c1 e8 30          	shr    rax,0x30
  fc:	88 41 06             	mov    BYTE PTR [rcx+0x6],al
  ff:	48 89 d8             	mov    rax,rbx
 102:	48 c1 e8 28          	shr    rax,0x28
 106:	88 41 05             	mov    BYTE PTR [rcx+0x5],al
 109:	48 89 d8             	mov    rax,rbx
 10c:	48 c1 e8 20          	shr    rax,0x20
 110:	88 41 04             	mov    BYTE PTR [rcx+0x4],al
 113:	89 d8                	mov    eax,ebx
 115:	c1 e8 18             	shr    eax,0x18
 118:	88 41 03             	mov    BYTE PTR [rcx+0x3],al
 11b:	89 d8                	mov    eax,ebx
 11d:	c1 e8 10             	shr    eax,0x10
 120:	88 41 02             	mov    BYTE PTR [rcx+0x2],al
 123:	88 79 01             	mov    BYTE PTR [rcx+0x1],bh
 126:	b8 02 00 00 00       	mov    eax,0x2
 12b:	5b                   	pop    rbx
 12c:	c3                   	ret
```

## Handcraft C
```c
not captured
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
