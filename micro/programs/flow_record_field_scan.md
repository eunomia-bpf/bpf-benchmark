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

0000000000001208 <_fini>:
    1208:	f3 0f 1e fa          	endbr64
    120c:	48 83 ec 08          	sub    rsp,0x8
    1210:	48 83 c4 08          	add    rsp,0x8
    1214:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 08 00 00 00 	sub    rsp,0x8
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	4c 8b 7f 00          	mov    r15,QWORD PTR [rdi+0x0]
  24:	49 39 f7             	cmp    r15,rsi
  27:	0f 87 55 01 00 00    	ja     0x182
  2d:	4c 89 ff             	mov    rdi,r15
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 45 01 00 00    	ja     0x182
  3d:	4c 89 fa             	mov    rdx,r15
  40:	48 81 c2 10 04 00 00 	add    rdx,0x410
  47:	48 39 f2             	cmp    rdx,rsi
  4a:	0f 87 32 01 00 00    	ja     0x182
  50:	8b 7f 00             	mov    edi,DWORD PTR [rdi+0x0]
  53:	83 ff 20             	cmp    edi,0x20
  56:	0f 85 26 01 00 00    	jne    0x182
  5c:	41 8b 7f 0c          	mov    edi,DWORD PTR [r15+0xc]
  60:	83 ff 20             	cmp    edi,0x20
  63:	0f 85 19 01 00 00    	jne    0x182
  69:	48 bb 15 7c 4a 7f b9 	movabs rbx,0x9e3779b97f4a7c15
  70:	79 37 9e 
  73:	31 f6                	xor    esi,esi
  75:	31 d2                	xor    edx,edx
  77:	45 31 c0             	xor    r8d,r8d
  7a:	4c 89 7d f8          	mov    QWORD PTR [rbp-0x8],r15
  7e:	eb 5b                	jmp    0xdb
  80:	4c 89 c7             	mov    rdi,r8
  83:	48 83 e7 07          	and    rdi,0x7
  87:	c4 42 c3 f7 f6       	shrx   r14,r14,rdi
  8c:	4c 31 f1             	xor    rcx,r14
  8f:	49 01 cd             	add    r13,rcx
  92:	4c 89 e9             	mov    rcx,r13
  95:	48 89 f7             	mov    rdi,rsi
  98:	48 83 e7 18          	and    rdi,0x18
  9c:	48 89 c3             	mov    rbx,rax
  9f:	c4 e2 c1 f7 db       	shlx   rbx,rbx,rdi
  a4:	48 31 d9             	xor    rcx,rbx
  a7:	83 e0 07             	and    eax,0x7
  aa:	89 c7                	mov    edi,eax
  ac:	83 c7 01             	add    edi,0x1
  af:	83 f0 3f             	xor    eax,0x3f
  b2:	49 89 cd             	mov    r13,rcx
  b5:	c4 42 fb f7 ed       	shrx   r13,r13,rax
  ba:	c4 e2 c1 f7 c9       	shlx   rcx,rcx,rdi
  bf:	48 83 c2 20          	add    rdx,0x20
  c3:	48 83 c6 08          	add    rsi,0x8
  c7:	48 89 cb             	mov    rbx,rcx
  ca:	4c 09 eb             	or     rbx,r13
  cd:	49 83 c0 01          	add    r8,0x1
  d1:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
  d5:	49 83 f8 20          	cmp    r8,0x20
  d9:	74 54                	je     0x12f
  db:	49 01 d7             	add    r15,rdx
  de:	49 8b 7f 18          	mov    rdi,QWORD PTR [r15+0x18]
  e2:	4d 8b 77 20          	mov    r14,QWORD PTR [r15+0x20]
  e6:	4c 89 f1             	mov    rcx,r14
  e9:	48 01 f9             	add    rcx,rdi
  ec:	49 0f b7 7f 14       	movzx  rdi,WORD PTR [r15+0x14]
  f1:	41 8b 47 10          	mov    eax,DWORD PTR [r15+0x10]
  f5:	49 89 c5             	mov    r13,rax
  f8:	49 c1 e5 10          	shl    r13,0x10
  fc:	49 09 fd             	or     r13,rdi
  ff:	49 31 cd             	xor    r13,rcx
 102:	49 01 dd             	add    r13,rbx
 105:	41 8b 5f 2c          	mov    ebx,DWORD PTR [r15+0x2c]
 109:	41 8b 4f 28          	mov    ecx,DWORD PTR [r15+0x28]
 10d:	48 c1 e1 20          	shl    rcx,0x20
 111:	48 09 d9             	or     rcx,rbx
 114:	83 e7 01             	and    edi,0x1
 117:	85 ff                	test   edi,edi
 119:	0f 84 61 ff ff ff    	je     0x80
 11f:	49 0f b7 7f 16       	movzx  rdi,WORD PTR [r15+0x16]
 124:	48 01 f9             	add    rcx,rdi
 127:	4c 31 e9             	xor    rcx,r13
 12a:	e9 66 ff ff ff       	jmp    0x95
 12f:	41 88 5f 00          	mov    BYTE PTR [r15+0x0],bl
 133:	48 89 cf             	mov    rdi,rcx
 136:	48 c1 ef 38          	shr    rdi,0x38
 13a:	41 88 7f 07          	mov    BYTE PTR [r15+0x7],dil
 13e:	48 89 cf             	mov    rdi,rcx
 141:	48 c1 ef 30          	shr    rdi,0x30
 145:	41 88 7f 06          	mov    BYTE PTR [r15+0x6],dil
 149:	48 89 cf             	mov    rdi,rcx
 14c:	48 c1 ef 28          	shr    rdi,0x28
 150:	41 88 7f 05          	mov    BYTE PTR [r15+0x5],dil
 154:	48 89 cf             	mov    rdi,rcx
 157:	48 c1 ef 20          	shr    rdi,0x20
 15b:	41 88 7f 04          	mov    BYTE PTR [r15+0x4],dil
 15f:	48 89 cf             	mov    rdi,rcx
 162:	48 c1 ef 18          	shr    rdi,0x18
 166:	41 88 7f 03          	mov    BYTE PTR [r15+0x3],dil
 16a:	48 89 cf             	mov    rdi,rcx
 16d:	48 c1 ef 10          	shr    rdi,0x10
 171:	41 88 7f 02          	mov    BYTE PTR [r15+0x2],dil
 175:	48 c1 e9 08          	shr    rcx,0x8
 179:	41 88 4f 01          	mov    BYTE PTR [r15+0x1],cl
 17d:	b8 02 00 00 00       	mov    eax,0x2
 182:	41 5f                	pop    r15
 184:	41 5e                	pop    r14
 186:	41 5d                	pop    r13
 188:	5b                   	pop    rbx
 189:	c9                   	leave
 18a:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
