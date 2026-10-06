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
  27:	0f 87 f3 03 00 00    	ja     0x420
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 e3 03 00 00    	ja     0x420
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 50 02 00 00 	add    rdi,0x250
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 d0 03 00 00    	ja     0x420
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 83 ff 18          	cmp    rdi,0x18
  85:	0f 85 95 03 00 00    	jne    0x420
  8b:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  90:	48 c1 e7 08          	shl    rdi,0x8
  94:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  99:	48 09 f7             	or     rdi,rsi
  9c:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  a1:	48 c1 e6 10          	shl    rsi,0x10
  a5:	48 09 f7             	or     rdi,rsi
  a8:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  ad:	48 c1 e6 18          	shl    rsi,0x18
  b1:	48 09 f7             	or     rdi,rsi
  b4:	48 c1 e7 20          	shl    rdi,0x20
  b8:	48 c1 ef 20          	shr    rdi,0x20
  bc:	48 83 ff 18          	cmp    rdi,0x18
  c0:	0f 85 5a 03 00 00    	jne    0x420
  c6:	48 bf 00 00 00 00 01 	movabs rdi,0x100000000
  cd:	00 00 00 
  d0:	48 89 7d 98          	mov    QWORD PTR [rbp-0x68],rdi
  d4:	48 bf c3 4c 37 75 cc 	movabs rdi,0x589965cc75374cc3
  db:	65 99 58 
  de:	45 31 c0             	xor    r8d,r8d
  e1:	48 89 55 90          	mov    QWORD PTR [rbp-0x70],rdx
  e5:	48 89 d1             	mov    rcx,rdx
  e8:	48 83 c1 13          	add    rcx,0x13
  ec:	e9 8a 00 00 00       	jmp    0x17b
  f1:	48 c1 e7 08          	shl    rdi,0x8
  f5:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
  f9:	48 09 f7             	or     rdi,rsi
  fc:	48 c1 e2 10          	shl    rdx,0x10
 100:	48 09 d7             	or     rdi,rdx
 103:	48 c1 e3 18          	shl    rbx,0x18
 107:	48 09 df             	or     rdi,rbx
 10a:	48 89 fa             	mov    rdx,rdi
 10d:	48 c1 e2 20          	shl    rdx,0x20
 111:	48 c1 ea 20          	shr    rdx,0x20
 115:	48 81 fa 00 10 00 00 	cmp    rdx,0x1000
 11c:	77 36                	ja     0x154
 11e:	49 c1 e5 08          	shl    r13,0x8
 122:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 126:	49 09 f5             	or     r13,rsi
 129:	49 c1 e0 10          	shl    r8,0x10
 12d:	4d 09 c5             	or     r13,r8
 130:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 134:	48 c1 e6 18          	shl    rsi,0x18
 138:	49 09 f5             	or     r13,rsi
 13b:	4c 89 ee             	mov    rsi,r13
 13e:	48 c1 e6 20          	shl    rsi,0x20
 142:	48 c1 ee 20          	shr    rsi,0x20
 146:	ba 01 20 00 00       	mov    edx,0x2001
 14b:	48 39 f2             	cmp    rdx,rsi
 14e:	0f 87 4d 01 00 00    	ja     0x2a1
 154:	49 c1 e6 30          	shl    r14,0x30
 158:	4d 09 fe             	or     r14,r15
 15b:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 15f:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 163:	49 31 fe             	xor    r14,rdi
 166:	48 83 c1 18          	add    rcx,0x18
 16a:	49 83 c0 01          	add    r8,0x1
 16e:	4c 89 f7             	mov    rdi,r14
 171:	49 83 f8 18          	cmp    r8,0x18
 175:	0f 84 4e 02 00 00    	je     0x3c9
 17b:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
 17f:	4c 89 45 f8          	mov    QWORD PTR [rbp-0x8],r8
 183:	48 0f b6 79 fe       	movzx  rdi,BYTE PTR [rcx-0x2]
 188:	48 c1 e7 08          	shl    rdi,0x8
 18c:	48 0f b6 71 fd       	movzx  rsi,BYTE PTR [rcx-0x3]
 191:	48 09 f7             	or     rdi,rsi
 194:	48 0f b6 71 ff       	movzx  rsi,BYTE PTR [rcx-0x1]
 199:	48 c1 e6 10          	shl    rsi,0x10
 19d:	48 09 fe             	or     rsi,rdi
 1a0:	48 0f b6 79 00       	movzx  rdi,BYTE PTR [rcx+0x0]
 1a5:	48 c1 e7 18          	shl    rdi,0x18
 1a9:	48 09 f7             	or     rdi,rsi
 1ac:	48 0f b6 71 01       	movzx  rsi,BYTE PTR [rcx+0x1]
 1b1:	48 c1 e6 20          	shl    rsi,0x20
 1b5:	48 09 fe             	or     rsi,rdi
 1b8:	4c 0f b6 69 0a       	movzx  r13,BYTE PTR [rcx+0xa]
 1bd:	48 0f b6 79 09       	movzx  rdi,BYTE PTR [rcx+0x9]
 1c2:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
 1c6:	4c 0f b6 41 02       	movzx  r8,BYTE PTR [rcx+0x2]
 1cb:	49 c1 e0 28          	shl    r8,0x28
 1cf:	49 09 f0             	or     r8,rsi
 1d2:	48 0f b6 79 12       	movzx  rdi,BYTE PTR [rcx+0x12]
 1d7:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 1db:	48 0f b6 79 11       	movzx  rdi,BYTE PTR [rcx+0x11]
 1e0:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
 1e4:	48 0f b6 79 06       	movzx  rdi,BYTE PTR [rcx+0x6]
 1e9:	48 0f b6 71 05       	movzx  rsi,BYTE PTR [rcx+0x5]
 1ee:	48 89 75 e8          	mov    QWORD PTR [rbp-0x18],rsi
 1f2:	48 0f b6 51 07       	movzx  rdx,BYTE PTR [rcx+0x7]
 1f7:	48 0f b6 71 13       	movzx  rsi,BYTE PTR [rcx+0x13]
 1fc:	48 89 75 b0          	mov    QWORD PTR [rbp-0x50],rsi
 200:	48 0f b6 41 03       	movzx  rax,BYTE PTR [rcx+0x3]
 205:	48 c1 e0 30          	shl    rax,0x30
 209:	4c 09 c0             	or     rax,r8
 20c:	4c 0f b6 41 0b       	movzx  r8,BYTE PTR [rcx+0xb]
 211:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
 216:	48 89 75 c0          	mov    QWORD PTR [rbp-0x40],rsi
 21a:	48 0f b6 71 0d       	movzx  rsi,BYTE PTR [rcx+0xd]
 21f:	48 89 75 a0          	mov    QWORD PTR [rbp-0x60],rsi
 223:	48 0f b6 71 14       	movzx  rsi,BYTE PTR [rcx+0x14]
 228:	48 89 75 a8          	mov    QWORD PTR [rbp-0x58],rsi
 22c:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
 231:	48 89 75 d8          	mov    QWORD PTR [rbp-0x28],rsi
 235:	48 0f b6 59 08       	movzx  rbx,BYTE PTR [rcx+0x8]
 23a:	4c 0f b6 79 04       	movzx  r15,BYTE PTR [rcx+0x4]
 23f:	49 c1 e7 38          	shl    r15,0x38
 243:	49 09 c7             	or     r15,rax
 246:	48 0f b6 41 0f       	movzx  rax,BYTE PTR [rcx+0xf]
 24b:	4c 0f b6 71 10       	movzx  r14,BYTE PTR [rcx+0x10]
 250:	49 c1 e6 08          	shl    r14,0x8
 254:	49 09 c6             	or     r14,rax
 257:	4c 89 f0             	mov    rax,r14
 25a:	48 25 ff ff 00 00    	and    rax,0xffff
 260:	48 83 f8 01          	cmp    rax,0x1
 264:	7f 1c                	jg     0x282
 266:	be 21 00 00 00       	mov    esi,0x21
 26b:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
 26f:	48 85 c0             	test   rax,rax
 272:	0f 84 79 fe ff ff    	je     0xf1
 278:	be 35 00 00 00       	mov    esi,0x35
 27d:	e9 3e 01 00 00       	jmp    0x3c0
 282:	48 83 f8 02          	cmp    rax,0x2
 286:	0f 84 2f 01 00 00    	je     0x3bb
 28c:	48 83 f8 03          	cmp    rax,0x3
 290:	74 05                	je     0x297
 292:	e9 bd fe ff ff       	jmp    0x154
 297:	be 89 00 00 00       	mov    esi,0x89
 29c:	e9 1f 01 00 00       	jmp    0x3c0
 2a1:	48 8b 5d c0          	mov    rbx,QWORD PTR [rbp-0x40]
 2a5:	48 c1 e3 08          	shl    rbx,0x8
 2a9:	48 8b 75 a0          	mov    rsi,QWORD PTR [rbp-0x60]
 2ad:	48 09 f3             	or     rbx,rsi
 2b0:	48 89 da             	mov    rdx,rbx
 2b3:	48 83 e2 01          	and    rdx,0x1
 2b7:	be 08 00 00 00       	mov    esi,0x8
 2bc:	48 85 d2             	test   rdx,rdx
 2bf:	74 03                	je     0x2c4
 2c1:	4c 89 ee             	mov    rsi,r13
 2c4:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
 2c8:	48 c1 e0 08          	shl    rax,0x8
 2cc:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 2d0:	48 09 d0             	or     rax,rdx
 2d3:	48 8b 55 b0          	mov    rdx,QWORD PTR [rbp-0x50]
 2d7:	48 c1 e2 10          	shl    rdx,0x10
 2db:	48 09 d0             	or     rax,rdx
 2de:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
 2e2:	48 c1 e2 18          	shl    rdx,0x18
 2e6:	48 09 d0             	or     rax,rdx
 2e9:	48 01 fe             	add    rsi,rdi
 2ec:	48 c1 e6 20          	shl    rsi,0x20
 2f0:	48 c1 ee 20          	shr    rsi,0x20
 2f4:	48 8b 55 98          	mov    rdx,QWORD PTR [rbp-0x68]
 2f8:	48 01 f2             	add    rdx,rsi
 2fb:	48 89 c6             	mov    rsi,rax
 2fe:	48 c1 e6 20          	shl    rsi,0x20
 302:	4c 8b 45 d0          	mov    r8,QWORD PTR [rbp-0x30]
 306:	49 09 f0             	or     r8,rsi
 309:	4d 31 c7             	xor    r15,r8
 30c:	48 89 55 98          	mov    QWORD PTR [rbp-0x68],rdx
 310:	49 31 d7             	xor    r15,rdx
 313:	48 89 de             	mov    rsi,rbx
 316:	48 83 e6 02          	and    rsi,0x2
 31a:	4c 8b 45 f8          	mov    r8,QWORD PTR [rbp-0x8]
 31e:	48 85 f6             	test   rsi,rsi
 321:	74 26                	je     0x349
 323:	49 83 c6 01          	add    r14,0x1
 327:	49 81 e6 ff ff 00 00 	and    r14,0xffff
 32e:	be 40 00 00 00       	mov    esi,0x40
 333:	4c 29 f6             	sub    rsi,r14
 336:	4c 89 fa             	mov    rdx,r15
 339:	c4 e2 89 f7 d2       	shlx   rdx,rdx,r14
 33e:	c4 42 cb f7 ff       	shrx   r15,r15,rsi
 343:	4c 09 fa             	or     rdx,r15
 346:	49 89 d7             	mov    r15,rdx
 349:	48 89 de             	mov    rsi,rbx
 34c:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 353:	48 83 e6 04          	and    rsi,0x4
 357:	48 85 f6             	test   rsi,rsi
 35a:	74 1d                	je     0x379
 35c:	48 c1 e7 20          	shl    rdi,0x20
 360:	48 c1 ef 20          	shr    rdi,0x20
 364:	49 c1 e5 20          	shl    r13,0x20
 368:	49 c1 ed 20          	shr    r13,0x20
 36c:	49 c1 e5 18          	shl    r13,0x18
 370:	49 31 fd             	xor    r13,rdi
 373:	4d 01 fd             	add    r13,r15
 376:	4d 89 ef             	mov    r15,r13
 379:	4c 89 c7             	mov    rdi,r8
 37c:	48 83 e7 07          	and    rdi,0x7
 380:	48 89 fe             	mov    rsi,rdi
 383:	48 83 f6 3f          	xor    rsi,0x3f
 387:	4c 89 fa             	mov    rdx,r15
 38a:	c4 e2 cb f7 d2       	shrx   rdx,rdx,rsi
 38f:	48 83 c7 01          	add    rdi,0x1
 393:	c4 42 c1 f7 ff       	shlx   r15,r15,rdi
 398:	49 09 d7             	or     r15,rdx
 39b:	48 8b 7d f0          	mov    rdi,QWORD PTR [rbp-0x10]
 39f:	49 01 ff             	add    r15,rdi
 3a2:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 3a9:	48 c1 e3 28          	shl    rbx,0x28
 3ad:	48 09 d8             	or     rax,rbx
 3b0:	48 89 c7             	mov    rdi,rax
 3b3:	4d 89 fe             	mov    r14,r15
 3b6:	e9 a8 fd ff ff       	jmp    0x163
 3bb:	be 55 00 00 00       	mov    esi,0x55
 3c0:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
 3c4:	e9 28 fd ff ff       	jmp    0xf1
 3c9:	4c 89 f7             	mov    rdi,r14
 3cc:	48 c1 ef 38          	shr    rdi,0x38
 3d0:	48 8b 75 90          	mov    rsi,QWORD PTR [rbp-0x70]
 3d4:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 3d8:	4c 89 f7             	mov    rdi,r14
 3db:	48 c1 ef 30          	shr    rdi,0x30
 3df:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 3e3:	4c 89 f7             	mov    rdi,r14
 3e6:	48 c1 ef 28          	shr    rdi,0x28
 3ea:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 3ee:	4c 89 f7             	mov    rdi,r14
 3f1:	48 c1 ef 20          	shr    rdi,0x20
 3f5:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 3f9:	4c 89 f7             	mov    rdi,r14
 3fc:	48 c1 ef 18          	shr    rdi,0x18
 400:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 404:	4c 89 f7             	mov    rdi,r14
 407:	48 c1 ef 10          	shr    rdi,0x10
 40b:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 40f:	44 88 76 00          	mov    BYTE PTR [rsi+0x0],r14b
 413:	49 c1 ee 08          	shr    r14,0x8
 417:	44 88 76 01          	mov    BYTE PTR [rsi+0x1],r14b
 41b:	b8 02 00 00 00       	mov    eax,0x2
 420:	41 5f                	pop    r15
 422:	41 5e                	pop    r14
 424:	41 5d                	pop    r13
 426:	5b                   	pop    rbx
 427:	c9                   	leave
 428:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 37                	mov    esi,DWORD PTR [rdi]
   6:	8b 4f 04             	mov    ecx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 ce                	cmp    esi,ecx
   d:	0f 87 9e 02 00 00    	ja     0x2b1
  13:	48 8d 56 08          	lea    rdx,[rsi+0x8]
  17:	48 39 ca             	cmp    rdx,rcx
  1a:	0f 87 91 02 00 00    	ja     0x2b1
  20:	48 8d 96 50 02 00 00 	lea    rdx,[rsi+0x250]
  27:	48 39 ca             	cmp    rdx,rcx
  2a:	0f 87 81 02 00 00    	ja     0x2b1
  30:	83 7e 08 18          	cmp    DWORD PTR [rsi+0x8],0x18
  34:	0f 85 5d 02 00 00    	jne    0x297
  3a:	83 7e 0c 18          	cmp    DWORD PTR [rsi+0xc],0x18
  3e:	0f 85 53 02 00 00    	jne    0x297
  44:	55                   	push   rbp
  45:	41 57                	push   r15
  47:	41 56                	push   r14
  49:	41 55                	push   r13
  4b:	41 54                	push   r12
  4d:	53                   	push   rbx
  4e:	48 89 74 24 c0       	mov    QWORD PTR [rsp-0x40],rsi
  53:	48 8d 46 13          	lea    rax,[rsi+0x13]
  57:	49 bb c3 4c 37 75 cc 	movabs r11,0x589965cc75374cc3
  5e:	65 99 58 
  61:	48 b9 00 00 00 00 01 	movabs rcx,0x100000000
  68:	00 00 00 
  6b:	48 89 4c 24 b8       	mov    QWORD PTR [rsp-0x48],rcx
  70:	31 ff                	xor    edi,edi
  72:	eb 2d                	jmp    0xa1
  74:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  7b:	00 00 00 00 00 
  80:	49 c1 e2 30          	shl    r10,0x30
  84:	49 09 f2             	or     r10,rsi
  87:	4c 89 d9             	mov    rcx,r11
  8a:	4d 89 d3             	mov    r11,r10
  8d:	49 31 cb             	xor    r11,rcx
  90:	48 83 c0 18          	add    rax,0x18
  94:	48 ff c7             	inc    rdi
  97:	48 83 ff 18          	cmp    rdi,0x18
  9b:	0f 84 f9 01 00 00    	je     0x29a
  a1:	0f b6 58 0a          	movzx  ebx,BYTE PTR [rax+0xa]
  a5:	44 0f b6 40 09       	movzx  r8d,BYTE PTR [rax+0x9]
  aa:	0f b6 48 12          	movzx  ecx,BYTE PTR [rax+0x12]
  ae:	48 89 4c 24 e0       	mov    QWORD PTR [rsp-0x20],rcx
  b3:	0f b6 48 11          	movzx  ecx,BYTE PTR [rax+0x11]
  b7:	48 89 4c 24 d8       	mov    QWORD PTR [rsp-0x28],rcx
  bc:	0f b6 68 06          	movzx  ebp,BYTE PTR [rax+0x6]
  c0:	0f b6 48 05          	movzx  ecx,BYTE PTR [rax+0x5]
  c4:	48 89 4c 24 f8       	mov    QWORD PTR [rsp-0x8],rcx
  c9:	44 0f b6 70 07       	movzx  r14d,BYTE PTR [rax+0x7]
  ce:	0f b6 48 13          	movzx  ecx,BYTE PTR [rax+0x13]
  d2:	48 89 4c 24 e8       	mov    QWORD PTR [rsp-0x18],rcx
  d7:	44 0f b6 48 0b       	movzx  r9d,BYTE PTR [rax+0xb]
  dc:	0f b6 48 0e          	movzx  ecx,BYTE PTR [rax+0xe]
  e0:	48 89 4c 24 f0       	mov    QWORD PTR [rsp-0x10],rcx
  e5:	0f b6 50 0d          	movzx  edx,BYTE PTR [rax+0xd]
  e9:	44 0f b6 60 14       	movzx  r12d,BYTE PTR [rax+0x14]
  ee:	44 0f b6 78 0c       	movzx  r15d,BYTE PTR [rax+0xc]
  f3:	0f b6 48 0f          	movzx  ecx,BYTE PTR [rax+0xf]
  f7:	44 0f b6 50 10       	movzx  r10d,BYTE PTR [rax+0x10]
  fc:	41 c1 e2 08          	shl    r10d,0x8
 100:	48 89 4c 24 d0       	mov    QWORD PTR [rsp-0x30],rcx
 105:	49 09 ca             	or     r10,rcx
 108:	44 0f b6 68 08       	movzx  r13d,BYTE PTR [rax+0x8]
 10d:	48 8b 70 fd          	mov    rsi,QWORD PTR [rax-0x3]
 111:	49 83 fa 01          	cmp    r10,0x1
 115:	76 29                	jbe    0x140
 117:	49 83 fa 02          	cmp    r10,0x2
 11b:	74 70                	je     0x18d
 11d:	b9 89 00 00 00       	mov    ecx,0x89
 122:	48 89 4c 24 b0       	mov    QWORD PTR [rsp-0x50],rcx
 127:	41 83 fa 03          	cmp    r10d,0x3
 12b:	74 73                	je     0x1a0
 12d:	e9 4e ff ff ff       	jmp    0x80
 132:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
 139:	1f 84 00 00 00 00 00 
 140:	4d 85 d2             	test   r10,r10
 143:	4c 89 7c 24 c8       	mov    QWORD PTR [rsp-0x38],r15
 148:	49 89 ff             	mov    r15,rdi
 14b:	4c 89 cf             	mov    rdi,r9
 14e:	49 89 d9             	mov    r9,rbx
 151:	4c 89 c3             	mov    rbx,r8
 154:	41 b8 35 00 00 00    	mov    r8d,0x35
 15a:	48 89 f1             	mov    rcx,rsi
 15d:	4c 89 e6             	mov    rsi,r12
 160:	49 89 d4             	mov    r12,rdx
 163:	ba 21 00 00 00       	mov    edx,0x21
 168:	4c 0f 44 c2          	cmove  r8,rdx
 16c:	4c 89 44 24 b0       	mov    QWORD PTR [rsp-0x50],r8
 171:	49 89 d8             	mov    r8,rbx
 174:	4c 89 cb             	mov    rbx,r9
 177:	49 89 f9             	mov    r9,rdi
 17a:	4c 89 ff             	mov    rdi,r15
 17d:	4c 8b 7c 24 c8       	mov    r15,QWORD PTR [rsp-0x38]
 182:	4c 89 e2             	mov    rdx,r12
 185:	49 89 f4             	mov    r12,rsi
 188:	48 89 ce             	mov    rsi,rcx
 18b:	eb 13                	jmp    0x1a0
 18d:	b9 55 00 00 00       	mov    ecx,0x55
 192:	48 89 4c 24 b0       	mov    QWORD PTR [rsp-0x50],rcx
 197:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
 19e:	00 00 
 1a0:	c1 e5 08             	shl    ebp,0x8
 1a3:	48 03 6c 24 f8       	add    rbp,QWORD PTR [rsp-0x8]
 1a8:	41 c1 e6 10          	shl    r14d,0x10
 1ac:	49 09 ee             	or     r14,rbp
 1af:	41 c1 e5 18          	shl    r13d,0x18
 1b3:	4d 09 f5             	or     r13,r14
 1b6:	49 81 fd 00 10 00 00 	cmp    r13,0x1000
 1bd:	0f 87 bd fe ff ff    	ja     0x80
 1c3:	c1 e3 08             	shl    ebx,0x8
 1c6:	4c 09 c3             	or     rbx,r8
 1c9:	41 c1 e1 10          	shl    r9d,0x10
 1cd:	49 09 d9             	or     r9,rbx
 1d0:	41 c1 e7 18          	shl    r15d,0x18
 1d4:	4d 09 cf             	or     r15,r9
 1d7:	49 81 ff 01 20 00 00 	cmp    r15,0x2001
 1de:	0f 83 9c fe ff ff    	jae    0x80
 1e4:	f6 c2 01             	test   dl,0x1
 1e7:	4d 89 f8             	mov    r8,r15
 1ea:	41 b9 08 00 00 00    	mov    r9d,0x8
 1f0:	4d 0f 44 c1          	cmove  r8,r9
 1f4:	4c 8b 4c 24 e0       	mov    r9,QWORD PTR [rsp-0x20]
 1f9:	41 c1 e1 08          	shl    r9d,0x8
 1fd:	4c 03 4c 24 d8       	add    r9,QWORD PTR [rsp-0x28]
 202:	48 8b 4c 24 e8       	mov    rcx,QWORD PTR [rsp-0x18]
 207:	c1 e1 10             	shl    ecx,0x10
 20a:	4c 09 c9             	or     rcx,r9
 20d:	41 c1 e4 18          	shl    r12d,0x18
 211:	49 09 cc             	or     r12,rcx
 214:	4c 8b 4c 24 b8       	mov    r9,QWORD PTR [rsp-0x48]
 219:	4d 01 e9             	add    r9,r13
 21c:	4d 01 c1             	add    r9,r8
 21f:	4d 89 e0             	mov    r8,r12
 222:	49 c1 e0 20          	shl    r8,0x20
 226:	48 8b 4c 24 b0       	mov    rcx,QWORD PTR [rsp-0x50]
 22b:	4c 09 c1             	or     rcx,r8
 22e:	48 31 ce             	xor    rsi,rcx
 231:	4c 89 4c 24 b8       	mov    QWORD PTR [rsp-0x48],r9
 236:	4c 31 ce             	xor    rsi,r9
 239:	f6 c2 02             	test   dl,0x2
 23c:	74 0a                	je     0x248
 23e:	48 8b 4c 24 d0       	mov    rcx,QWORD PTR [rsp-0x30]
 243:	fe c1                	inc    cl
 245:	48 d3 c6             	rol    rsi,cl
 248:	48 89 d1             	mov    rcx,rdx
 24b:	48 c1 e1 3d          	shl    rcx,0x3d
 24f:	48 c1 f9 3f          	sar    rcx,0x3f
 253:	49 c1 e7 18          	shl    r15,0x18
 257:	4d 09 ef             	or     r15,r13
 25a:	49 21 cf             	and    r15,rcx
 25d:	49 01 f7             	add    r15,rsi
 260:	89 f9                	mov    ecx,edi
 262:	80 e1 07             	and    cl,0x7
 265:	89 ce                	mov    esi,ecx
 267:	40 f6 d6             	not    sil
 26a:	c4 c2 cb f7 f7       	shrx   rsi,r15,rsi
 26f:	fe c1                	inc    cl
 271:	c4 42 f1 f7 d7       	shlx   r10,r15,rcx
 276:	49 09 f2             	or     r10,rsi
 279:	4d 01 da             	add    r10,r11
 27c:	48 8b 4c 24 f0       	mov    rcx,QWORD PTR [rsp-0x10]
 281:	48 c1 e1 30          	shl    rcx,0x30
 285:	48 c1 e2 28          	shl    rdx,0x28
 289:	48 09 ca             	or     rdx,rcx
 28c:	4c 09 e2             	or     rdx,r12
 28f:	49 89 d3             	mov    r11,rdx
 292:	e9 f0 fd ff ff       	jmp    0x87
 297:	31 c0                	xor    eax,eax
 299:	c3                   	ret
 29a:	48 8b 44 24 c0       	mov    rax,QWORD PTR [rsp-0x40]
 29f:	4c 89 18             	mov    QWORD PTR [rax],r11
 2a2:	b8 02 00 00 00       	mov    eax,0x2
 2a7:	5b                   	pop    rbx
 2a8:	41 5c                	pop    r12
 2aa:	41 5d                	pop    r13
 2ac:	41 5e                	pop    r14
 2ae:	41 5f                	pop    r15
 2b0:	5d                   	pop    rbp
 2b1:	c3                   	ret
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
    /* 0x110c: jbe    110f <otel_stack_frame_unwind_scan_xdp+0xf> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_2, BPF_REG_4, (2) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x110f: lea    rdx,[rsi+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1116: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-3) - 1, 0),
    /* 0x1118: lea    rdx,[rsi+0x250] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_2, 0, 0, 1, 0, 592), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1122: ja     110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-6) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rsi+0x8],0x18 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1128: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 24),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-13) - 1),
    /* 0x112a: cmp    DWORD PTR [rsi+0xc],0x18 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x112e: jne    110e <otel_stack_frame_unwind_scan_xdp+0xe> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_2, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 2, 24),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-20) - 1),
    /* 0x1130: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1133: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1135: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1137: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1138: lea    rdi,[rsi+0x27] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_2, 0, 0, 1, 0, 39), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x113c: movabs r8,0x100000000 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 0x100000000ULL),
    /* 0x1146: movabs r11,0x589965cc75374cc3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x589965cc75374cc3ULL),
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -424),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1150: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1153: mov    r10d,0x8 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(HC_X86_R10, 8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1159: jmp    117b <otel_stack_frame_unwind_scan_xdp+0x7b> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (19) - 1),
    /* 0x115b: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: shl    rax,0x30 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 48), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1164: or     rax,rdx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1167: xor    r11,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R11, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x116a: inc    r9 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x116d: add    rdi,0x18 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_1, 24), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1171: cmp    r9,0x18 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x1175: je     1272 <otel_stack_frame_unwind_scan_xdp+0x172> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_6, 0, 2, 24),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (120) - 1),
    /* 0x117b: mov    rdx,QWORD PTR [rdi-0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_3, BPF_REG_1, -23), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x117f: mov    r14d,DWORD PTR [rdi-0xf] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_8, BPF_REG_1, -15), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1183: mov    r15d,DWORD PTR [rdi-0xb] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_9, BPF_REG_1, -11), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1187: movzx  ebp,WORD PTR [rdi-0x7] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(HC_X86_RBP, BPF_REG_1, -7), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x118b: movzx  eax,WORD PTR [rdi-0x5] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_0, BPF_REG_1, -5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x118f: mov    ebx,DWORD PTR [rdi-0x3] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_X86_MEM_PAYLOAD(BPF_REG_6, BPF_REG_1, -3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1192: cmp    eax,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF jg] */
    /* 0x1195: jg     11b0 <otel_stack_frame_unwind_scan_xdp+0xb0> [exact-bpf: jg ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JSGT | BPF_K, BPF_REG_0, 0, (8) - 1, 1),
    /* 0x1197: test   eax,eax [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x1199: je     11ca <otel_stack_frame_unwind_scan_xdp+0xca> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_0, 0, 1, -1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (12) - 1),
    /* 0x119b: cmp    eax,0x1 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x119e: jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (-33) - 1, 1),
    /* 0x11a0: mov    ecx,0x35 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 53), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a5: cmp    r14d,0x1000 [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x11ac: jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_8, 0, (15) - 1, 4096),
    /* 0x11ae: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-37) - 1),
    /* 0x11b0: cmp    eax,0x2 [absorbed-control-flow: cmp folded into following ordinary BPF je] */
    /* 0x11b3: je     11da <otel_stack_frame_unwind_scan_xdp+0xda> [exact-bpf: je ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JEQ | BPF_K, BPF_REG_0, 0, (10) - 1, 2),
    /* 0x11b5: cmp    eax,0x3 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11b8: jne    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_0, 0, (-39) - 1, 3),
    /* 0x11ba: mov    ecx,0x89 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 137), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11bf: cmp    r14d,0x1000 [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x11c6: jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_8, 0, (9) - 1, 4096),
    /* 0x11c8: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-43) - 1),
    /* 0x11ca: mov    ecx,0x21 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 33), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11cf: cmp    r14d,0x1000 [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x11d6: jbe    11ec <otel_stack_frame_unwind_scan_xdp+0xec> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JLE | BPF_K, BPF_REG_8, 0, (5) - 1, 4096),
    /* 0x11d8: jmp    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-47) - 1),
    /* 0x11da: mov    ecx,0x55 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_4, 85), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11df: cmp    r14d,0x1000 [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x11e6: ja     1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JGT | BPF_K, BPF_REG_8, 0, (-50) - 1, 4096),
    /* 0x11ec: cmp    r15d,0x2001 [absorbed-control-flow: cmp folded into following ordinary BPF jae] */
    /* 0x11f3: jae    1160 <otel_stack_frame_unwind_scan_xdp+0x60> [exact-bpf: jae ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP32 | BPF_JGE | BPF_K, BPF_REG_9, 0, (-51) - 1, 8193),
    /* 0x11f9: test   bpl,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x11fd: mov    r12d,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1200: cmove  r12d,r10d [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(HC_X86_R12, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_CMOVEL),
    /* 0x1204: add    r12d,r14d [exact-kinsn: add32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1207: add    r8,r12 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_5, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x120a: mov    r12,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x120d: shl    r12,0x20 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(HC_X86_R12, 32), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1211: or     rcx,r12 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x1214: xor    rdx,rcx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1217: xor    rdx,r8 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x121a: test   bpl,0x2 [absorbed-control-flow: test folded into following ordinary BPF je] */
    /* 0x121e: je     1227 <otel_stack_frame_unwind_scan_xdp+0x127> [exact-bpf: je ordinary BPF branch from preceding test] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_6, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_RAW(BPF_JMP | BPF_JSET | BPF_K, BPF_REG_6, 0, 2, 2),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (14) - 1),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1220: inc    al [exact-bpf: incb via verifier-visible BPF low-byte update] */
    HC_STX(BPF_DW, BPF_REG_10, BPF_REG_6, -376),
    HC_MOV64_REG(BPF_REG_6, BPF_REG_0),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_ADD, BPF_REG_6, 1),
    HC_ALU64_IMM(BPF_AND, BPF_REG_6, 0xff),
    HC_ALU64_IMM(BPF_AND, BPF_REG_0, -256),
    HC_ALU64_REG(BPF_OR, BPF_REG_0, BPF_REG_6),
    HC_LDX(BPF_DW, BPF_REG_6, BPF_REG_10, -376),
    /* 0x1222: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1224: rol    rdx,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x1227: mov    eax,r15d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_0, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x122a: shl    rax,0x18 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_0, 24), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x122e: mov    ecx,r14d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1231: xor    rcx,rax [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1234: test   bpl,0x4 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RBP, 4), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1238: mov    eax,0x0 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x123d: cmovne rax,rcx [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_STACK_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1241: add    rax,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1244: mov    edx,r9d [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1247: and    dl,0x7 [exact-kinsn: andb imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 7), MICRO_HANDCRAFT_BPF_X86_ANDB),
    /* 0x124a: lea    ecx,[rdx+0x1] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_3, 0, 0, 1, 0, 1), MICRO_HANDCRAFT_BPF_X86_LEAL),
    /* 0x124d: mov    r14,rax [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1250: shl    r14,cl [exact-kinsn: shl64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1253: not    dl [exact-kinsn: notb reg kinsn] */
    HC_KINSN(HC_NOT_NARROW_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_NOTB),
    /* 0x1255: mov    ecx,edx [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1257: shr    rax,cl [exact-kinsn: shr64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x125a: or     rax,r14 [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x125d: add    rax,r11 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x1260: movzx  ecx,bp [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(BPF_REG_4, HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1263: shl    rcx,0x28 [exact-kinsn: shl64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 40), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x1267: or     rbx,rcx [exact-kinsn: or64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_6, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ORQ),
    /* 0x126a: mov    r11,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x126d: jmp    1167 <otel_stack_frame_unwind_scan_xdp+0x67> [exact-bpf: native jmp maps to ordinary BPF JA] */
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-132) - 1),
    /* 0x1272: mov    QWORD PTR [rsi],r11 [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(HC_X86_R11, BPF_REG_2, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1275: mov    eax,0x2 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x127a: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x127b: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x127d: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x127f: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1281: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x1282: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
