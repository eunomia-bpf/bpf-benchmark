# packet_checksum_fold

## Original C
```c
#include "common.h"

#define CHECKSUM_MAX_ROUNDS 32U
#define CHECKSUM_MAX_WORDS 512U
#define CHECKSUM_INPUT_SIZE (8U + CHECKSUM_MAX_WORDS * 2U)

static __always_inline int bench_packet_checksum_fold(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);
    u64 acc = 0;

    if (rounds != CHECKSUM_MAX_ROUNDS || word_count != CHECKSUM_MAX_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, CHECKSUM_MAX_WORDS * 2U)) {
        return -1;
    }

    for (u32 round = 0; round < CHECKSUM_MAX_ROUNDS; round++) {
        u32 sum = 0;
        for (u32 i = 0; i < CHECKSUM_MAX_WORDS; i++) {
            sum += micro_read_u16_le(data, 8 + i * 2);
            sum = (sum & 0xFFFFU) + (sum >> 16);
        }
        sum = (sum & 0xFFFFU) + (sum >> 16);
        /*
         * The same checksum value is folded into four 16-bit lanes. With 32
         * rounds each lane toggles eight times, so the final accumulator is
         * intentionally zero even though the staged input is non-zero.
         */
        acc ^= (u64)(~sum & 0xFFFFU) << ((round & 3) * 16);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    packet_checksum_fold_xdp,
    bench_packet_checksum_fold,
    packet_checksum_fold_input_value,
    CHECKSUM_INPUT_SIZE)
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

0000000000001100 <packet_checksum_fold_xdp>:
    1100:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 ca             	cmp    rdx,rcx
    110c:	76 01                	jbe    110f <packet_checksum_fold_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 72 08          	lea    rsi,[rdx+0x8]
    1113:	48 39 ce             	cmp    rsi,rcx
    1116:	77 f6                	ja     110e <packet_checksum_fold_xdp+0xe>
    1118:	48 8d b2 10 04 00 00 	lea    rsi,[rdx+0x410]
    111f:	48 39 ce             	cmp    rsi,rcx
    1122:	77 ea                	ja     110e <packet_checksum_fold_xdp+0xe>
    1124:	83 7a 08 20          	cmp    DWORD PTR [rdx+0x8],0x20
    1128:	75 e4                	jne    110e <packet_checksum_fold_xdp+0xe>
    112a:	81 7a 0c 00 02 00 00 	cmp    DWORD PTR [rdx+0xc],0x200
    1131:	75 db                	jne    110e <packet_checksum_fold_xdp+0xe>
    1133:	31 c0                	xor    eax,eax
    1135:	31 f6                	xor    esi,esi
    1137:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    113e:	00 00 
    1140:	b9 13 00 00 00       	mov    ecx,0x13
    1145:	31 ff                	xor    edi,edi
    1147:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    114e:	00 00 
    1150:	44 0f b7 44 0a fd    	movzx  r8d,WORD PTR [rdx+rcx*1-0x3]
    1156:	41 01 f8             	add    r8d,edi
    1159:	41 0f b7 f8          	movzx  edi,r8w
    115d:	41 c1 e8 10          	shr    r8d,0x10
    1161:	41 01 f8             	add    r8d,edi
    1164:	0f b7 7c 0a ff       	movzx  edi,WORD PTR [rdx+rcx*1-0x1]
    1169:	44 01 c7             	add    edi,r8d
    116c:	44 0f b7 c7          	movzx  r8d,di
    1170:	c1 ef 10             	shr    edi,0x10
    1173:	44 01 c7             	add    edi,r8d
    1176:	48 83 c1 04          	add    rcx,0x4
    117a:	48 81 f9 13 04 00 00 	cmp    rcx,0x413
    1181:	75 cd                	jne    1150 <packet_checksum_fold_xdp+0x50>
    1183:	89 f9                	mov    ecx,edi
    1185:	c1 e9 10             	shr    ecx,0x10
    1188:	01 f9                	add    ecx,edi
    118a:	f7 d1                	not    ecx
    118c:	0f b7 f9             	movzx  edi,cx
    118f:	89 c1                	mov    ecx,eax
    1191:	c1 e1 04             	shl    ecx,0x4
    1194:	48 d3 e7             	shl    rdi,cl
    1197:	48 31 fe             	xor    rsi,rdi
    119a:	ff c0                	inc    eax
    119c:	83 f8 20             	cmp    eax,0x20
    119f:	75 9f                	jne    1140 <packet_checksum_fold_xdp+0x40>
    11a1:	48 89 32             	mov    QWORD PTR [rdx],rsi
    11a4:	b8 02 00 00 00       	mov    eax,0x2
    11a9:	c3                   	ret

Disassembly of section .fini:

00000000000011ac <_fini>:
    11ac:	f3 0f 1e fa          	endbr64
    11b0:	48 83 ec 08          	sub    rsp,0x8
    11b4:	48 83 c4 08          	add    rsp,0x8
    11b8:	c3                   	ret
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
   d:	31 c0                	xor    eax,eax
   f:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  13:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  17:	48 39 f7             	cmp    rdi,rsi
  1a:	0f 87 45 01 00 00    	ja     0x165
  20:	48 89 fa             	mov    rdx,rdi
  23:	48 83 c2 08          	add    rdx,0x8
  27:	48 39 f2             	cmp    rdx,rsi
  2a:	0f 87 35 01 00 00    	ja     0x165
  30:	48 89 fa             	mov    rdx,rdi
  33:	48 81 c2 10 04 00 00 	add    rdx,0x410
  3a:	48 39 f2             	cmp    rdx,rsi
  3d:	0f 87 22 01 00 00    	ja     0x165
  43:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  48:	c1 e6 08             	shl    esi,0x8
  4b:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  50:	09 d6                	or     esi,edx
  52:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  57:	c1 e2 10             	shl    edx,0x10
  5a:	09 d6                	or     esi,edx
  5c:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  61:	c1 e2 18             	shl    edx,0x18
  64:	09 d6                	or     esi,edx
  66:	83 fe 20             	cmp    esi,0x20
  69:	0f 85 f6 00 00 00    	jne    0x165
  6f:	48 0f b6 77 0d       	movzx  rsi,BYTE PTR [rdi+0xd]
  74:	c1 e6 08             	shl    esi,0x8
  77:	48 0f b6 57 0c       	movzx  rdx,BYTE PTR [rdi+0xc]
  7c:	09 d6                	or     esi,edx
  7e:	48 0f b6 57 0e       	movzx  rdx,BYTE PTR [rdi+0xe]
  83:	c1 e2 10             	shl    edx,0x10
  86:	09 d6                	or     esi,edx
  88:	48 0f b6 57 0f       	movzx  rdx,BYTE PTR [rdi+0xf]
  8d:	c1 e2 18             	shl    edx,0x18
  90:	09 d6                	or     esi,edx
  92:	81 fe 00 02 00 00    	cmp    esi,0x200
  98:	0f 85 c7 00 00 00    	jne    0x165
  9e:	31 d2                	xor    edx,edx
  a0:	31 f6                	xor    esi,esi
  a2:	31 c9                	xor    ecx,ecx
  a4:	31 c0                	xor    eax,eax
  a6:	49 89 f8             	mov    r8,rdi
  a9:	49 01 c8             	add    r8,rcx
  ac:	49 0f b6 58 10       	movzx  rbx,BYTE PTR [r8+0x10]
  b1:	4d 0f b6 40 11       	movzx  r8,BYTE PTR [r8+0x11]
  b6:	41 c1 e0 08          	shl    r8d,0x8
  ba:	41 09 d8             	or     r8d,ebx
  bd:	41 01 c0             	add    r8d,eax
  c0:	44 89 c0             	mov    eax,r8d
  c3:	c1 e8 10             	shr    eax,0x10
  c6:	41 81 e0 ff ff 00 00 	and    r8d,0xffff
  cd:	41 01 c0             	add    r8d,eax
  d0:	48 83 c1 02          	add    rcx,0x2
  d4:	44 89 c0             	mov    eax,r8d
  d7:	48 81 f9 00 04 00 00 	cmp    rcx,0x400
  de:	74 02                	je     0xe2
  e0:	eb c4                	jmp    0xa6
  e2:	44 89 c1             	mov    ecx,r8d
  e5:	c1 e9 10             	shr    ecx,0x10
  e8:	44 01 c1             	add    ecx,r8d
  eb:	83 f1 ff             	xor    ecx,0xffffffff
  ee:	81 e1 ff ff 00 00    	and    ecx,0xffff
  f4:	41 89 f0             	mov    r8d,esi
  f7:	41 c1 e0 04          	shl    r8d,0x4
  fb:	41 83 e0 30          	and    r8d,0x30
  ff:	c4 e2 b9 f7 c9       	shlx   rcx,rcx,r8
 104:	48 31 d1             	xor    rcx,rdx
 107:	83 c6 01             	add    esi,0x1
 10a:	48 89 ca             	mov    rdx,rcx
 10d:	83 fe 20             	cmp    esi,0x20
 110:	74 02                	je     0x114
 112:	eb 8e                	jmp    0xa2
 114:	88 4f 00             	mov    BYTE PTR [rdi+0x0],cl
 117:	48 89 ce             	mov    rsi,rcx
 11a:	48 c1 ee 38          	shr    rsi,0x38
 11e:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 122:	48 89 ce             	mov    rsi,rcx
 125:	48 c1 ee 30          	shr    rsi,0x30
 129:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 12d:	48 89 ce             	mov    rsi,rcx
 130:	48 c1 ee 28          	shr    rsi,0x28
 134:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 138:	48 89 ce             	mov    rsi,rcx
 13b:	48 c1 ee 20          	shr    rsi,0x20
 13f:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 143:	48 89 ce             	mov    rsi,rcx
 146:	48 c1 ee 18          	shr    rsi,0x18
 14a:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 14e:	48 89 ce             	mov    rsi,rcx
 151:	48 c1 ee 10          	shr    rsi,0x10
 155:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 159:	48 c1 e9 08          	shr    rcx,0x8
 15d:	88 4f 01             	mov    BYTE PTR [rdi+0x1],cl
 160:	b8 02 00 00 00       	mov    eax,0x2
 165:	5b                   	pop    rbx
 166:	c9                   	leave
 167:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
