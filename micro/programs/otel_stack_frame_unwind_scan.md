# otel_stack_frame_unwind_scan

## Original C
```c
#include "common.h"

#define OTEL_UNWIND_FRAME_COUNT 24U
#define OTEL_UNWIND_FRAME_SIZE 24U
#define OTEL_UNWIND_INPUT_SIZE \
    (8U + OTEL_UNWIND_FRAME_COUNT * OTEL_UNWIND_FRAME_SIZE)

static __always_inline u32 otel_frame_kind_weight(u16 kind)
{
    switch (kind) {
    case 0U: return 0x21U;
    case 1U: return 0x35U;
    case 2U: return 0x55U;
    case 3U: return 0x89U;
    default: return 0U;
    }
}

static __always_inline int
bench_otel_stack_frame_unwind_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, OTEL_UNWIND_INPUT_SIZE)) {
        return -1;
    }

    u32 frame_count = micro_read_u32_le(data, 0U);
    u32 frame_size = micro_read_u32_le(data, 4U);
    if (frame_count != OTEL_UNWIND_FRAME_COUNT ||
        frame_size != OTEL_UNWIND_FRAME_SIZE) {
        return -1;
    }

    u64 acc = 0x589965CC75374CC3ULL;
    u64 cursor = 0x100000000ULL;
    for (u32 index = 0; index < OTEL_UNWIND_FRAME_COUNT; index++) {
        u32 base = 8U + index * OTEL_UNWIND_FRAME_SIZE;
        u64 ip = micro_read_u64_le(data, base);
        u32 sp_delta = micro_read_u32_le(data, base + 8U);
        u32 fp_delta = micro_read_u32_le(data, base + 12U);
        u16 flags = micro_read_u16_le(data, base + 16U);
        u16 kind = micro_read_u16_le(data, base + 18U);
        u32 symbol_hash = micro_read_u32_le(data, base + 20U);
        u32 weight = otel_frame_kind_weight(kind);
        u32 frame_ok = sp_delta <= 4096U && fp_delta <= 8192U;

        if (weight == 0U || frame_ok == 0U) {
            acc ^= ((u64)kind << 48U) | ip;
            continue;
        }

        cursor += sp_delta + ((flags & 1U) ? fp_delta : 8U);
        u64 frame_sig = ip ^ cursor ^ ((u64)symbol_hash << 32U) ^ weight;
        if ((flags & 2U) != 0U) {
            frame_sig = micro_rotl64(frame_sig, (kind & 7U) + 1U);
        }
        if ((flags & 4U) != 0U) {
            frame_sig += ((u64)fp_delta << 24U) ^ sp_delta;
        }

        acc += micro_rotl64(frame_sig, (index & 7U) + 1U);
        acc ^= ((u64)flags << 40U) | symbol_hash;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    otel_stack_frame_unwind_scan_xdp,
    bench_otel_stack_frame_unwind_scan,
    otel_stack_frame_unwind_scan_input_value,
    OTEL_UNWIND_INPUT_SIZE)
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

0000000000001100 <otel_stack_frame_unwind_scan_xdp>:
    1100:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ce             	cmp    rsi,rcx
    110c:	76 01                	jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 56 08          	lea    rdx,[rsi+0x8]
    1113:	48 39 ca             	cmp    rdx,rcx
    1116:	77 f6                	ja     110e <otel_stack_frame_unwind_scan_xdp+0xe>
    1118:	48 8d 96 50 02 00 00 	lea    rdx,[rsi+0x250]
    111f:	48 39 ca             	cmp    rdx,rcx
    1122:	77 ea                	ja     110e <otel_stack_frame_unwind_scan_xdp+0xe>
    1124:	83 7e 08 18          	cmp    DWORD PTR [rsi+0x8],0x18
    1128:	75 e4                	jne    110e <otel_stack_frame_unwind_scan_xdp+0xe>
    112a:	83 7e 0c 18          	cmp    DWORD PTR [rsi+0xc],0x18
    112e:	75 de                	jne    110e <otel_stack_frame_unwind_scan_xdp+0xe>
    1130:	55                   	push   rbp
    1131:	41 57                	push   r15
    1133:	41 56                	push   r14
    1135:	41 54                	push   r12
    1137:	53                   	push   rbx
    1138:	48 8d 7e 27          	lea    rdi,[rsi+0x27]
    113c:	49 b8 00 00 00 00 01 	movabs r8,0x100000000
    1143:	00 00 00 
    1146:	49 bb c3 4c 37 75 cc 	movabs r11,0x589965cc75374cc3
    114d:	65 99 58 
    1150:	45 31 c9             	xor    r9d,r9d
    1153:	41 ba 08 00 00 00    	mov    r10d,0x8
    1159:	eb 20                	jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b>
    115b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
    1160:	48 c1 e0 30          	shl    rax,0x30
    1164:	48 09 d0             	or     rax,rdx
    1167:	49 31 c3             	xor    r11,rax
    116a:	49 ff c1             	inc    r9
    116d:	48 83 c7 18          	add    rdi,0x18
    1171:	49 83 f9 18          	cmp    r9,0x18
    1175:	0f 84 f7 00 00 00    	je     1272 <otel_stack_frame_unwind_scan_xdp+0x172>
    117b:	48 8b 57 e9          	mov    rdx,QWORD PTR [rdi-0x17]
    117f:	44 8b 77 f1          	mov    r14d,DWORD PTR [rdi-0xf]
    1183:	44 8b 7f f5          	mov    r15d,DWORD PTR [rdi-0xb]
    1187:	0f b7 6f f9          	movzx  ebp,WORD PTR [rdi-0x7]
    118b:	0f b7 47 fb          	movzx  eax,WORD PTR [rdi-0x5]
    118f:	8b 5f fd             	mov    ebx,DWORD PTR [rdi-0x3]
    1192:	83 f8 01             	cmp    eax,0x1
    1195:	7f 19                	jg     11b0 <otel_stack_frame_unwind_scan_xdp+0xb0>
    1197:	85 c0                	test   eax,eax
    1199:	74 2f                	je     11ca <otel_stack_frame_unwind_scan_xdp+0xca>
    119b:	83 f8 01             	cmp    eax,0x1
    119e:	75 c0                	jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11a0:	b9 35 00 00 00       	mov    ecx,0x35
    11a5:	41 81 fe 00 10 00 00 	cmp    r14d,0x1000
    11ac:	76 3e                	jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec>
    11ae:	eb b0                	jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11b0:	83 f8 02             	cmp    eax,0x2
    11b3:	74 25                	je     11da <otel_stack_frame_unwind_scan_xdp+0xda>
    11b5:	83 f8 03             	cmp    eax,0x3
    11b8:	75 a6                	jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11ba:	b9 89 00 00 00       	mov    ecx,0x89
    11bf:	41 81 fe 00 10 00 00 	cmp    r14d,0x1000
    11c6:	76 24                	jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec>
    11c8:	eb 96                	jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11ca:	b9 21 00 00 00       	mov    ecx,0x21
    11cf:	41 81 fe 00 10 00 00 	cmp    r14d,0x1000
    11d6:	76 14                	jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec>
    11d8:	eb 86                	jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11da:	b9 55 00 00 00       	mov    ecx,0x55
    11df:	41 81 fe 00 10 00 00 	cmp    r14d,0x1000
    11e6:	0f 87 74 ff ff ff    	ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11ec:	41 81 ff 01 20 00 00 	cmp    r15d,0x2001
    11f3:	0f 83 67 ff ff ff    	jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60>
    11f9:	40 f6 c5 01          	test   bpl,0x1
    11fd:	45 89 fc             	mov    r12d,r15d
    1200:	45 0f 44 e2          	cmove  r12d,r10d
    1204:	45 01 f4             	add    r12d,r14d
    1207:	4d 01 e0             	add    r8,r12
    120a:	49 89 dc             	mov    r12,rbx
    120d:	49 c1 e4 20          	shl    r12,0x20
    1211:	4c 09 e1             	or     rcx,r12
    1214:	48 31 ca             	xor    rdx,rcx
    1217:	4c 31 c2             	xor    rdx,r8
    121a:	40 f6 c5 02          	test   bpl,0x2
    121e:	74 07                	je     1227 <otel_stack_frame_unwind_scan_xdp+0x127>
    1220:	fe c0                	inc    al
    1222:	89 c1                	mov    ecx,eax
    1224:	48 d3 c2             	rol    rdx,cl
    1227:	44 89 f8             	mov    eax,r15d
    122a:	48 c1 e0 18          	shl    rax,0x18
    122e:	44 89 f1             	mov    ecx,r14d
    1231:	48 31 c1             	xor    rcx,rax
    1234:	40 f6 c5 04          	test   bpl,0x4
    1238:	b8 00 00 00 00       	mov    eax,0x0
    123d:	48 0f 45 c1          	cmovne rax,rcx
    1241:	48 01 d0             	add    rax,rdx
    1244:	44 89 ca             	mov    edx,r9d
    1247:	80 e2 07             	and    dl,0x7
    124a:	8d 4a 01             	lea    ecx,[rdx+0x1]
    124d:	49 89 c6             	mov    r14,rax
    1250:	49 d3 e6             	shl    r14,cl
    1253:	f6 d2                	not    dl
    1255:	89 d1                	mov    ecx,edx
    1257:	48 d3 e8             	shr    rax,cl
    125a:	4c 09 f0             	or     rax,r14
    125d:	4c 01 d8             	add    rax,r11
    1260:	0f b7 cd             	movzx  ecx,bp
    1263:	48 c1 e1 28          	shl    rcx,0x28
    1267:	48 09 cb             	or     rbx,rcx
    126a:	49 89 db             	mov    r11,rbx
    126d:	e9 f5 fe ff ff       	jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67>
    1272:	4c 89 1e             	mov    QWORD PTR [rsi],r11
    1275:	b8 02 00 00 00       	mov    eax,0x2
    127a:	5b                   	pop    rbx
    127b:	41 5c                	pop    r12
    127d:	41 5e                	pop    r14
    127f:	41 5f                	pop    r15
    1281:	5d                   	pop    rbp
    1282:	c3                   	ret

Disassembly of section .fini:

0000000000001284 <_fini>:
    1284:	f3 0f 1e fa          	endbr64
    1288:	48 83 ec 08          	sub    rsp,0x8
    128c:	48 83 c4 08          	add    rsp,0x8
    1290:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 70 00 00 00 	sub    rsp,0x70
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 84 03 00 00    	ja     0x3b1
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 74 03 00 00    	ja     0x3b1
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 50 02 00 00 	add    rdi,0x250
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 61 03 00 00    	ja     0x3b1
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
  73:	83 ff 18             	cmp    edi,0x18
  76:	0f 85 35 03 00 00    	jne    0x3b1
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
  9f:	83 ff 18             	cmp    edi,0x18
  a2:	0f 85 09 03 00 00    	jne    0x3b1
  a8:	48 bf 00 00 00 00 01 	movabs rdi,0x100000000
  af:	00 00 00 
  b2:	48 89 7d 98          	mov    QWORD PTR [rbp-0x68],rdi
  b6:	48 bf c3 4c 37 75 cc 	movabs rdi,0x589965cc75374cc3
  bd:	65 99 58 
  c0:	45 31 c0             	xor    r8d,r8d
  c3:	48 89 55 90          	mov    QWORD PTR [rbp-0x70],rdx
  c7:	48 89 d1             	mov    rcx,rdx
  ca:	48 83 c1 13          	add    rcx,0x13
  ce:	eb 6a                	jmp    0x13a
  d0:	c1 e7 08             	shl    edi,0x8
  d3:	8b 75 e8             	mov    esi,DWORD PTR [rbp-0x18]
  d6:	09 f7                	or     edi,esi
  d8:	c1 e0 10             	shl    eax,0x10
  db:	09 c7                	or     edi,eax
  dd:	c1 e2 18             	shl    edx,0x18
  e0:	09 d7                	or     edi,edx
  e2:	81 ff 00 10 00 00    	cmp    edi,0x1000
  e8:	77 29                	ja     0x113
  ea:	41 c1 e7 08          	shl    r15d,0x8
  ee:	8b 75 d8             	mov    esi,DWORD PTR [rbp-0x28]
  f1:	41 09 f7             	or     r15d,esi
  f4:	8b 75 e0             	mov    esi,DWORD PTR [rbp-0x20]
  f7:	c1 e6 10             	shl    esi,0x10
  fa:	41 09 f7             	or     r15d,esi
  fd:	8b 75 d0             	mov    esi,DWORD PTR [rbp-0x30]
 100:	c1 e6 18             	shl    esi,0x18
 103:	41 09 f7             	or     r15d,esi
 106:	41 81 ff 01 20 00 00 	cmp    r15d,0x2001
 10d:	0f 82 4b 01 00 00    	jb     0x25e
 113:	49 c1 e5 30          	shl    r13,0x30
 117:	4d 09 f5             	or     r13,r14
 11a:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 11e:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 122:	49 31 fd             	xor    r13,rdi
 125:	48 83 c1 18          	add    rcx,0x18
 129:	49 83 c0 01          	add    r8,0x1
 12d:	4c 89 ef             	mov    rdi,r13
 130:	49 83 f8 18          	cmp    r8,0x18
 134:	0f 84 20 02 00 00    	je     0x35a
 13a:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
 13e:	4c 89 45 f8          	mov    QWORD PTR [rbp-0x8],r8
 142:	48 0f b6 79 fd       	movzx  rdi,BYTE PTR [rcx-0x3]
 147:	48 0f b6 71 fe       	movzx  rsi,BYTE PTR [rcx-0x2]
 14c:	48 c1 e6 08          	shl    rsi,0x8
 150:	48 09 fe             	or     rsi,rdi
 153:	48 0f b6 79 ff       	movzx  rdi,BYTE PTR [rcx-0x1]
 158:	48 c1 e7 10          	shl    rdi,0x10
 15c:	48 09 f7             	or     rdi,rsi
 15f:	48 0f b6 71 00       	movzx  rsi,BYTE PTR [rcx+0x0]
 164:	48 c1 e6 18          	shl    rsi,0x18
 168:	48 09 fe             	or     rsi,rdi
 16b:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 170:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 174:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 179:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 17d:	48 0f b6 51 01       	movzx  rdx,BYTE PTR [rcx+0x1]
 182:	48 c1 e2 20          	shl    rdx,0x20
 186:	48 09 f2             	or     rdx,rsi
 189:	4c 0f b6 79 0a       	movzx  r15,BYTE PTR [rcx+0xa]
 18e:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 193:	89 7d d8             	mov    DWORD PTR [rbp-0x28],edi
 196:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 19b:	48 0f b6 71 05       	movzx  rsi,BYTE PTR [rcx+0x5]
 1a0:	89 75 e8             	mov    DWORD PTR [rbp-0x18],esi
 1a3:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
 1a8:	89 75 e0             	mov    DWORD PTR [rbp-0x20],esi
 1ab:	48 0f b6 71 02       	movzx  rsi,BYTE PTR [rcx+0x2]
 1b0:	48 c1 e6 28          	shl    rsi,0x28
 1b4:	48 09 d6             	or     rsi,rdx
 1b7:	48 0f b6 51 13       	movzx  rdx,BYTE PTR [rcx+0x13]
 1bc:	48 89 55 b0          	mov    QWORD PTR [rbp-0x50],rdx
 1c0:	48 0f b6 41 07       	movzx  rax,BYTE PTR [rcx+0x7]
 1c5:	4c 0f b6 41 0e       	movzx  r8,BYTE PTR [rcx+0xe]
 1ca:	48 0f b6 51 0d       	movzx  rdx,BYTE PTR [rcx+0xd]
 1cf:	89 55 a0             	mov    DWORD PTR [rbp-0x60],edx
 1d2:	48 0f b6 51 0c       	movzx  rdx,BYTE PTR [rcx+0xc]
 1d7:	89 55 d0             	mov    DWORD PTR [rbp-0x30],edx
 1da:	48 0f b6 51 08       	movzx  rdx,BYTE PTR [rcx+0x8]
 1df:	48 0f b6 59 14       	movzx  rbx,BYTE PTR [rcx+0x14]
 1e4:	48 89 5d a8          	mov    QWORD PTR [rbp-0x58],rbx
 1e8:	48 0f b6 59 03       	movzx  rbx,BYTE PTR [rcx+0x3]
 1ed:	48 c1 e3 30          	shl    rbx,0x30
 1f1:	48 09 f3             	or     rbx,rsi
 1f4:	4c 0f b6 69 10       	movzx  r13,BYTE PTR [rcx+0x10]
 1f9:	41 c1 e5 08          	shl    r13d,0x8
 1fd:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
 202:	41 09 f5             	or     r13d,esi
 205:	4c 0f b6 71 04       	movzx  r14,BYTE PTR [rcx+0x4]
 20a:	49 c1 e6 38          	shl    r14,0x38
 20e:	49 09 de             	or     r14,rbx
 211:	44 89 ee             	mov    esi,r13d
 214:	81 e6 ff ff 00 00    	and    esi,0xffff
 21a:	83 fe 01             	cmp    esi,0x1
 21d:	7f 1b                	jg     0x23a
 21f:	bb 21 00 00 00       	mov    ebx,0x21
 224:	48 89 5d c8          	mov    QWORD PTR [rbp-0x38],rbx
 228:	4c 89 c3             	mov    rbx,r8
 22b:	85 f6                	test   esi,esi
 22d:	0f 84 9d fe ff ff    	je     0xd0
 233:	be 35 00 00 00       	mov    esi,0x35
 238:	eb 1b                	jmp    0x255
 23a:	83 fe 02             	cmp    esi,0x2
 23d:	0f 84 06 01 00 00    	je     0x349
 243:	4c 89 c3             	mov    rbx,r8
 246:	83 fe 03             	cmp    esi,0x3
 249:	74 05                	je     0x250
 24b:	e9 c3 fe ff ff       	jmp    0x113
 250:	be 89 00 00 00       	mov    esi,0x89
 255:	48 89 75 c8          	mov    QWORD PTR [rbp-0x38],rsi
 259:	e9 72 fe ff ff       	jmp    0xd0
 25e:	c1 e3 08             	shl    ebx,0x8
 261:	8b 75 a0             	mov    esi,DWORD PTR [rbp-0x60]
 264:	09 f3                	or     ebx,esi
 266:	89 da                	mov    edx,ebx
 268:	83 e2 01             	and    edx,0x1
 26b:	be 08 00 00 00       	mov    esi,0x8
 270:	85 d2                	test   edx,edx
 272:	74 03                	je     0x277
 274:	44 89 fe             	mov    esi,r15d
 277:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
 27b:	48 c1 e0 08          	shl    rax,0x8
 27f:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 283:	48 09 d0             	or     rax,rdx
 286:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
 28a:	48 c1 e2 10          	shl    rdx,0x10
 28e:	48 09 d0             	or     rax,rdx
 291:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
 295:	48 c1 e2 18          	shl    rdx,0x18
 299:	48 09 d0             	or     rax,rdx
 29c:	01 fe                	add    esi,edi
 29e:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
 2a2:	48 01 f2             	add    rdx,rsi
 2a5:	48 89 c6             	mov    rsi,rax
 2a8:	48 c1 e6 20          	shl    rsi,0x20
 2ac:	4c 8b 45 c8          	mov    r8,QWORD PTR [rbp-0x38]
 2b0:	49 09 f0             	or     r8,rsi
 2b3:	4d 31 c6             	xor    r14,r8
 2b6:	48 89 55 98          	mov    QWORD PTR [rbp-0x68],rdx
 2ba:	49 31 d6             	xor    r14,rdx
 2bd:	89 de                	mov    esi,ebx
 2bf:	83 e6 02             	and    esi,0x2
 2c2:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 2c6:	85 f6                	test   esi,esi
 2c8:	74 26                	je     0x2f0
 2ca:	41 83 c5 01          	add    r13d,0x1
 2ce:	49 81 e5 ff ff 00 00 	and    r13,0xffff
 2d5:	be 40 00 00 00       	mov    esi,0x40
 2da:	4c 29 ee             	sub    rsi,r13
 2dd:	4c 89 f2             	mov    rdx,r14
 2e0:	c4 e2 91 f7 d2       	shlx   rdx,rdx,r13
 2e5:	c4 42 cb f7 f6       	shrx   r14,r14,rsi
 2ea:	4c 09 f2             	or     rdx,r14
 2ed:	49 89 d6             	mov    r14,rdx
 2f0:	89 de                	mov    esi,ebx
 2f2:	81 e6 ff ff 00 00    	and    esi,0xffff
 2f8:	83 e6 04             	and    esi,0x4
 2fb:	85 f6                	test   esi,esi
 2fd:	74 0d                	je     0x30c
 2ff:	49 c1 e7 18          	shl    r15,0x18
 303:	49 31 ff             	xor    r15,rdi
 306:	4d 01 f7             	add    r15,r14
 309:	4d 89 fe             	mov    r14,r15
 30c:	44 89 c7             	mov    edi,r8d
 30f:	83 e7 07             	and    edi,0x7
 312:	89 fe                	mov    esi,edi
 314:	83 f6 3f             	xor    esi,0x3f
 317:	4c 89 f2             	mov    rdx,r14
 31a:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 31f:	83 c7 01             	add    edi,0x1
 322:	c4 42 c1 f7 f6       	shlx   r14,r14,rdi
 327:	49 09 d6             	or     r14,rdx
 32a:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 32e:	49 01 fe             	add    r14,rdi
 331:	81 e3 ff ff 00 00    	and    ebx,0xffff
 337:	48 c1 e3 28          	shl    rbx,0x28
 33b:	48 09 d8             	or     rax,rbx
 33e:	48 89 c7             	mov    rdi,rax
 341:	4d 89 f5             	mov    r13,r14
 344:	e9 d9 fd ff ff       	jmp    0x122
 349:	be 55 00 00 00       	mov    esi,0x55
 34e:	48 89 75 c8          	mov    QWORD PTR [rbp-0x38],rsi
 352:	4c 89 c3             	mov    rbx,r8
 355:	e9 76 fd ff ff       	jmp    0xd0
 35a:	48 8b 75 90          	mov    rsi,QWORD PTR [rbp-0x70]
 35e:	44 88 6e 00          	mov    BYTE PTR [rsi+0x0],r13b
 362:	4c 89 ef             	mov    rdi,r13
 365:	48 c1 ef 38          	shr    rdi,0x38
 369:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 36d:	4c 89 ef             	mov    rdi,r13
 370:	48 c1 ef 30          	shr    rdi,0x30
 374:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 378:	4c 89 ef             	mov    rdi,r13
 37b:	48 c1 ef 28          	shr    rdi,0x28
 37f:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 383:	4c 89 ef             	mov    rdi,r13
 386:	48 c1 ef 20          	shr    rdi,0x20
 38a:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 38e:	4c 89 ef             	mov    rdi,r13
 391:	48 c1 ef 18          	shr    rdi,0x18
 395:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 399:	4c 89 ef             	mov    rdi,r13
 39c:	48 c1 ef 10          	shr    rdi,0x10
 3a0:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 3a4:	49 c1 ed 08          	shr    r13,0x8
 3a8:	44 88 6e 01          	mov    BYTE PTR [rsi+0x1],r13b
 3ac:	b8 02 00 00 00       	mov    eax,0x2
 3b1:	41 5f                	pop    r15
 3b3:	41 5e                	pop    r14
 3b5:	41 5d                	pop    r13
 3b7:	5b                   	pop    rbx
 3b8:	c9                   	leave
 3b9:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
