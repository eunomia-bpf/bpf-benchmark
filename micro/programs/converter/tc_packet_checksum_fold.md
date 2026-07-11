# tc_packet_checksum_fold

## Original C
```c
#include "common.h"

#define TC_CHECKSUM_MAX_ROUNDS 32U
#define TC_CHECKSUM_MAX_WORDS 512U
#define TC_CHECKSUM_INPUT_SIZE (8U + TC_CHECKSUM_MAX_WORDS * 2U)

static __always_inline int bench_checksum(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);
    u64 acc = 0;

    if (rounds != TC_CHECKSUM_MAX_ROUNDS || word_count != TC_CHECKSUM_MAX_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, TC_CHECKSUM_MAX_WORDS * 2U)) {
        return -1;
    }

    for (u32 round = 0; round < TC_CHECKSUM_MAX_ROUNDS; round++) {
        u32 sum = 0;
        for (u32 i = 0; i < TC_CHECKSUM_MAX_WORDS; i++) {
            sum += micro_read_u16_le(data, 8 + i * 2U);
            sum = (sum & 0xFFFFU) + (sum >> 16);
        }
        sum = (sum & 0xFFFFU) + (sum >> 16);
        /*
         * The same checksum value is folded into four 16-bit lanes. With 32
         * rounds each lane toggles eight times, so the final accumulator is
         * intentionally zero even though the staged input is non-zero.
         */
        acc ^= (u64)(~sum & 0xFFFFU) << ((round & 3U) * 16U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_TC_BENCH(
    tc_packet_checksum_fold_prog,
    bench_checksum,
    tc_packet_checksum_fold_input_value,
    TC_CHECKSUM_INPUT_SIZE)
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

0000000000001100 <tc_packet_checksum_fold_prog>:
    1100:	48 8b 07             	mov    rax,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	48 39 c8             	cmp    rax,rcx
    110a:	76 15                	jbe    1121 <tc_packet_checksum_fold_prog+0x21>
    110c:	c7 47 10 ff ff ff ff 	mov    DWORD PTR [rdi+0x10],0xffffffff
    1113:	b8 02 00 00 00       	mov    eax,0x2
    1118:	ba ff ff ff ff       	mov    edx,0xffffffff
    111d:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    1120:	c3                   	ret
    1121:	48 8d 50 08          	lea    rdx,[rax+0x8]
    1125:	48 39 ca             	cmp    rdx,rcx
    1128:	77 e2                	ja     110c <tc_packet_checksum_fold_prog+0xc>
    112a:	48 8d 90 10 04 00 00 	lea    rdx,[rax+0x410]
    1131:	48 39 ca             	cmp    rdx,rcx
    1134:	77 d6                	ja     110c <tc_packet_checksum_fold_prog+0xc>
    1136:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
    113a:	75 d0                	jne    110c <tc_packet_checksum_fold_prog+0xc>
    113c:	81 78 0c 00 02 00 00 	cmp    DWORD PTR [rax+0xc],0x200
    1143:	75 c7                	jne    110c <tc_packet_checksum_fold_prog+0xc>
    1145:	31 f6                	xor    esi,esi
    1147:	31 d2                	xor    edx,edx
    1149:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1150:	31 c9                	xor    ecx,ecx
    1152:	45 31 c0             	xor    r8d,r8d
    1155:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    115c:	00 00 00 00 
    1160:	44 0f b7 4c 48 10    	movzx  r9d,WORD PTR [rax+rcx*2+0x10]
    1166:	45 01 c1             	add    r9d,r8d
    1169:	45 0f b7 c1          	movzx  r8d,r9w
    116d:	41 c1 e9 10          	shr    r9d,0x10
    1171:	45 01 c1             	add    r9d,r8d
    1174:	44 0f b7 44 48 12    	movzx  r8d,WORD PTR [rax+rcx*2+0x12]
    117a:	45 01 c8             	add    r8d,r9d
    117d:	45 0f b7 c8          	movzx  r9d,r8w
    1181:	41 c1 e8 10          	shr    r8d,0x10
    1185:	45 01 c8             	add    r8d,r9d
    1188:	48 83 c1 02          	add    rcx,0x2
    118c:	48 81 f9 00 02 00 00 	cmp    rcx,0x200
    1193:	75 cb                	jne    1160 <tc_packet_checksum_fold_prog+0x60>
    1195:	44 89 c1             	mov    ecx,r8d
    1198:	c1 e9 10             	shr    ecx,0x10
    119b:	44 01 c1             	add    ecx,r8d
    119e:	f7 d1                	not    ecx
    11a0:	44 0f b7 c1          	movzx  r8d,cx
    11a4:	89 f1                	mov    ecx,esi
    11a6:	c1 e1 04             	shl    ecx,0x4
    11a9:	49 d3 e0             	shl    r8,cl
    11ac:	4c 31 c2             	xor    rdx,r8
    11af:	ff c6                	inc    esi
    11b1:	83 fe 20             	cmp    esi,0x20
    11b4:	75 9a                	jne    1150 <tc_packet_checksum_fold_prog+0x50>
    11b6:	89 57 10             	mov    DWORD PTR [rdi+0x10],edx
    11b9:	48 c1 ea 20          	shr    rdx,0x20
    11bd:	31 c0                	xor    eax,eax
    11bf:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    11c2:	c3                   	ret

Disassembly of section .fini:

00000000000011c4 <_fini>:
    11c4:	f3 0f 1e fa          	endbr64
    11c8:	48 83 ec 08          	sub    rsp,0x8
    11cc:	48 83 c4 08          	add    rsp,0x8
    11d0:	c3                   	ret
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
  11:	48 8b 57 50          	mov    rdx,QWORD PTR [rdi+0x50]
  15:	48 8b b7 d0 00 00 00 	mov    rsi,QWORD PTR [rdi+0xd0]
  1c:	48 39 d6             	cmp    rsi,rdx
  1f:	77 1b                	ja     0x3c
  21:	48 89 f1             	mov    rcx,rsi
  24:	48 83 c1 08          	add    rcx,0x8
  28:	48 39 d1             	cmp    rcx,rdx
  2b:	77 0f                	ja     0x3c
  2d:	48 89 f1             	mov    rcx,rsi
  30:	48 81 c1 10 04 00 00 	add    rcx,0x410
  37:	48 39 ca             	cmp    rdx,rcx
  3a:	73 17                	jae    0x53
  3c:	bb ff ff ff ff       	mov    ebx,0xffffffff
  41:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
  44:	b8 02 00 00 00       	mov    eax,0x2
  49:	89 5f 34             	mov    DWORD PTR [rdi+0x34],ebx
  4c:	41 5e                	pop    r14
  4e:	41 5d                	pop    r13
  50:	5b                   	pop    rbx
  51:	c9                   	leave
  52:	c3                   	ret
  53:	48 0f b6 56 09       	movzx  rdx,BYTE PTR [rsi+0x9]
  58:	48 c1 e2 08          	shl    rdx,0x8
  5c:	48 0f b6 4e 08       	movzx  rcx,BYTE PTR [rsi+0x8]
  61:	48 09 ca             	or     rdx,rcx
  64:	48 0f b6 4e 0a       	movzx  rcx,BYTE PTR [rsi+0xa]
  69:	48 c1 e1 10          	shl    rcx,0x10
  6d:	48 09 ca             	or     rdx,rcx
  70:	48 0f b6 4e 0b       	movzx  rcx,BYTE PTR [rsi+0xb]
  75:	48 c1 e1 18          	shl    rcx,0x18
  79:	48 09 ca             	or     rdx,rcx
  7c:	48 c1 e2 20          	shl    rdx,0x20
  80:	48 c1 ea 20          	shr    rdx,0x20
  84:	48 83 fa 20          	cmp    rdx,0x20
  88:	75 b2                	jne    0x3c
  8a:	48 0f b6 56 0d       	movzx  rdx,BYTE PTR [rsi+0xd]
  8f:	48 c1 e2 08          	shl    rdx,0x8
  93:	48 0f b6 4e 0c       	movzx  rcx,BYTE PTR [rsi+0xc]
  98:	48 09 ca             	or     rdx,rcx
  9b:	48 0f b6 4e 0e       	movzx  rcx,BYTE PTR [rsi+0xe]
  a0:	48 c1 e1 10          	shl    rcx,0x10
  a4:	48 09 ca             	or     rdx,rcx
  a7:	48 0f b6 4e 0f       	movzx  rcx,BYTE PTR [rsi+0xf]
  ac:	48 c1 e1 18          	shl    rcx,0x18
  b0:	48 09 ca             	or     rdx,rcx
  b3:	48 c1 e2 20          	shl    rdx,0x20
  b7:	48 c1 ea 20          	shr    rdx,0x20
  bb:	48 81 fa 00 02 00 00 	cmp    rdx,0x200
  c2:	0f 85 74 ff ff ff    	jne    0x3c
  c8:	31 d2                	xor    edx,edx
  ca:	b9 00 00 ff ff       	mov    ecx,0xffff0000
  cf:	45 31 c0             	xor    r8d,r8d
  d2:	31 c0                	xor    eax,eax
  d4:	31 db                	xor    ebx,ebx
  d6:	49 89 f5             	mov    r13,rsi
  d9:	49 01 c5             	add    r13,rax
  dc:	4d 0f b6 75 10       	movzx  r14,BYTE PTR [r13+0x10]
  e1:	4d 0f b6 6d 11       	movzx  r13,BYTE PTR [r13+0x11]
  e6:	49 c1 e5 08          	shl    r13,0x8
  ea:	4d 09 f5             	or     r13,r14
  ed:	49 01 dd             	add    r13,rbx
  f0:	4c 89 eb             	mov    rbx,r13
  f3:	48 21 cb             	and    rbx,rcx
  f6:	49 81 e5 ff ff 00 00 	and    r13,0xffff
  fd:	48 c1 eb 10          	shr    rbx,0x10
 101:	49 01 dd             	add    r13,rbx
 104:	48 83 c0 02          	add    rax,0x2
 108:	4c 89 eb             	mov    rbx,r13
 10b:	48 81 f8 00 04 00 00 	cmp    rax,0x400
 112:	74 02                	je     0x116
 114:	eb c0                	jmp    0xd6
 116:	4c 89 eb             	mov    rbx,r13
 119:	48 c1 eb 10          	shr    rbx,0x10
 11d:	4c 01 eb             	add    rbx,r13
 120:	48 83 f3 ff          	xor    rbx,0xffffffffffffffff
 124:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 12b:	48 89 d0             	mov    rax,rdx
 12e:	48 c1 e0 04          	shl    rax,0x4
 132:	48 83 e0 30          	and    rax,0x30
 136:	c4 e2 f9 f7 db       	shlx   rbx,rbx,rax
 13b:	4c 31 c3             	xor    rbx,r8
 13e:	48 83 c2 01          	add    rdx,0x1
 142:	48 89 d0             	mov    rax,rdx
 145:	48 c1 e0 20          	shl    rax,0x20
 149:	48 c1 e8 20          	shr    rax,0x20
 14d:	49 89 d8             	mov    r8,rbx
 150:	48 83 f8 20          	cmp    rax,0x20
 154:	74 05                	je     0x15b
 156:	e9 77 ff ff ff       	jmp    0xd2
 15b:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
 15e:	31 c0                	xor    eax,eax
 160:	48 c1 eb 20          	shr    rbx,0x20
 164:	e9 e0 fe ff ff       	jmp    0x49
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 47 4c             	mov    eax,DWORD PTR [rdi+0x4c]
   7:	8b 4f 50             	mov    ecx,DWORD PTR [rdi+0x50]
   a:	39 c8                	cmp    eax,ecx
   c:	0f 87 a4 00 00 00    	ja     0xb6
  12:	48 8d 50 08          	lea    rdx,[rax+0x8]
  16:	48 39 ca             	cmp    rdx,rcx
  19:	0f 87 97 00 00 00    	ja     0xb6
  1f:	48 8d 90 10 04 00 00 	lea    rdx,[rax+0x410]
  26:	48 39 ca             	cmp    rdx,rcx
  29:	0f 87 87 00 00 00    	ja     0xb6
  2f:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
  33:	0f 85 7d 00 00 00    	jne    0xb6
  39:	81 78 0c 00 02 00 00 	cmp    DWORD PTR [rax+0xc],0x200
  40:	75 74                	jne    0xb6
  42:	31 c9                	xor    ecx,ecx
  44:	31 d2                	xor    edx,edx
  46:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  4d:	00 00 00 
  50:	45 31 c0             	xor    r8d,r8d
  53:	31 f6                	xor    esi,esi
  55:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
  5c:	00 00 00 00 
  60:	44 0f b7 4c 30 10    	movzx  r9d,WORD PTR [rax+rsi*1+0x10]
  66:	4d 01 c1             	add    r9,r8
  69:	45 0f b7 d1          	movzx  r10d,r9w
  6d:	41 c1 e9 10          	shr    r9d,0x10
  71:	4d 89 c8             	mov    r8,r9
  74:	4d 01 d0             	add    r8,r10
  77:	48 83 c6 02          	add    rsi,0x2
  7b:	48 81 fe 00 04 00 00 	cmp    rsi,0x400
  82:	75 dc                	jne    0x60
  84:	44 89 c6             	mov    esi,r8d
  87:	c1 ee 10             	shr    esi,0x10
  8a:	44 01 c6             	add    esi,r8d
  8d:	f7 d6                	not    esi
  8f:	0f b7 f6             	movzx  esi,si
  92:	41 89 d0             	mov    r8d,edx
  95:	41 c1 e0 04          	shl    r8d,0x4
  99:	c4 e2 b9 f7 f6       	shlx   rsi,rsi,r8
  9e:	48 31 f1             	xor    rcx,rsi
  a1:	48 ff c2             	inc    rdx
  a4:	83 fa 20             	cmp    edx,0x20
  a7:	75 a7                	jne    0x50
  a9:	89 4f 30             	mov    DWORD PTR [rdi+0x30],ecx
  ac:	48 c1 e9 20          	shr    rcx,0x20
  b0:	31 c0                	xor    eax,eax
  b2:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
  b5:	c3                   	ret
  b6:	c7 47 30 ff ff ff ff 	mov    DWORD PTR [rdi+0x30],0xffffffff
  bd:	b8 02 00 00 00       	mov    eax,0x2
  c2:	b9 ff ff ff ff       	mov    ecx,0xffffffff
  c7:	89 4f 34             	mov    DWORD PTR [rdi+0x34],ecx
  ca:	c3                   	ret
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
    /* 0x1100: mov    rax,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RAX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KOP(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: cmp    rax,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110a: jbe    1121 <tc_packet_checksum_fold_prog+0x21> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (12) - 1, 0),
    /* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff [exact-kop: mov immediate memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_IMM_PAYLOAD(HC_X86_RDI, 16, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1113: mov    eax,0x2 [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1118: mov    edx,0xffffffff [exact-kop: mov32 immediate kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111d: mov    DWORD PTR [rdi+0x14],edx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 20), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1120: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x1121: lea    rdx,[rax+0x8] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RAX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1125: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: ja     110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-17) - 1, 0),
    /* 0x112a: lea    rdx,[rax+0x410] [exact-kop: LEA via x86 kop selector] */
    HC_KOP(HC_LEA_ARCH_PAYLOAD(HC_X86_RDX, HC_X86_RAX, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1131: cmp    rdx,rcx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1134: ja     110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: ja as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-24) - 1, 0),
    /* 0x1136: cmp    DWORD PTR [rax+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x113a: jne    110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-28) - 1, 32),
    /* 0x113c: cmp    DWORD PTR [rax+0xc],0x200 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1143: jne    110c <tc_packet_checksum_fold_prog+0xc> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-32) - 1, 512),
    /* 0x1145: xor    esi,esi [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RSI, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1147: xor    edx,edx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1149: nop    DWORD PTR [rax+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: xor    ecx,ecx [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1152: xor    r8d,r8d [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1155: data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1160: movzx  r9d,WORD PTR [rax+rcx*2+0x10] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_R9, HC_X86_RAX, HC_X86_RCX, 1, 16), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1166: add    r9d,r8d [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1169: movzx  r8d,r9w [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x116d: shr    r9d,0x10 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1171: add    r9d,r8d [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1174: movzx  r8d,WORD PTR [rax+rcx*2+0x12] [exact-kop: indexed memory load via x86 SIB kop] */
    HC_KOP(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_R8, HC_X86_RAX, HC_X86_RCX, 1, 18), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x117a: add    r8d,r9d [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x117d: movzx  r9d,r8w [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1181: shr    r8d,0x10 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R8, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x1185: add    r8d,r9d [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x1188: add    rcx,0x2 [exact-kop: add64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 2), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x118c: cmp    rcx,0x200 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1193: jne    1160 <tc_packet_checksum_fold_prog+0x60> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-24) - 1, 512),
    /* 0x1195: mov    ecx,r8d [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1198: shr    ecx,0x10 [exact-kop: shr32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 16), MICRO_HANDCRAFT_BPF_X86_SHRL),
    /* 0x119b: add    ecx,r8d [exact-kop: add32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_ADDL),
    /* 0x119e: not    ecx [exact-kop: not32 reg kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_NOTL),
    /* 0x11a0: movzx  r8d,cx [exact-kop: movzx r32,r16 kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x11a4: mov    ecx,esi [exact-kop: mov32 register-to-register kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RCX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11a6: shl    ecx,0x4 [exact-kop: shl32 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RCX, 4), MICRO_HANDCRAFT_BPF_X86_SHLL),
    /* 0x11a9: shl    r8,cl [exact-kop: shl64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_SHLQ),
    /* 0x11ac: xor    rdx,r8 [exact-kop: xor64 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11af: inc    esi [exact-kop: incl reg kop] */
    HC_KOP(HC_REG_PAYLOAD(HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_INCL),
    /* 0x11b1: cmp    esi,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x11b4: jne    1150 <tc_packet_checksum_fold_prog+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVL),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-51) - 1, 32),
    /* 0x11b6: mov    DWORD PTR [rdi+0x10],edx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 16), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11b9: shr    rdx,0x20 [exact-kop: shr64 imm kop] */
    HC_KOP(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RDX, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11bd: xor    eax,eax [exact-kop: xor32 reg kop] */
    HC_KOP(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x11bf: mov    DWORD PTR [rdi+0x14],edx [exact-kop: direct memory store via x86 kop selector] */
    HC_KOP(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RDI, 20), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11c2: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KOP(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
