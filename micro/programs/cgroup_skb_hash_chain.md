# cgroup_skb_hash_chain

## Original C
```c
#include "common.h"

#define HASH_CHAIN_ROUNDS 16U
#define HASH_CHAIN_WORDS 8U
#define HASH_CHAIN_INPUT_SIZE (8U + HASH_CHAIN_WORDS * 8U)

static __always_inline int bench_hash_chain(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);

    if (rounds != HASH_CHAIN_ROUNDS || word_count != HASH_CHAIN_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, HASH_CHAIN_WORDS * 8U)) {
        return -1;
    }

    u64 acc = 0xCBF29CE484222325ULL;
    for (u32 round = 0; round < HASH_CHAIN_ROUNDS; round++) {
        for (u32 i = 0; i < HASH_CHAIN_WORDS; i++) {
            u64 word = micro_read_u64_le(data, 8 + i * 8U);
            u64 salt = ((u64)(round + 1U) * 0x9E3779B97F4A7C15ULL) ^
                       ((u64)(i + 1U) * 0xD1342543DE82EF95ULL);

            acc ^= word + salt;
            acc = micro_rotl64(acc, (round * 5U + i * 11U + 7U) & 63U);
            acc *= 0x100000001B3ULL;
            acc ^= acc >> 29U;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_CGROUP_SKB_BENCH(
    cgroup_skb_hash_chain_prog,
    bench_hash_chain,
    cgroup_skb_hash_chain_input_value,
    HASH_CHAIN_INPUT_SIZE)
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

0000000000001100 <cgroup_skb_hash_chain_prog>:
    1100:	48 8b 07             	mov    rax,QWORD PTR [rdi]
    1103:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
    1107:	48 39 c8             	cmp    rax,rcx
    110a:	76 12                	jbe    111e <cgroup_skb_hash_chain_prog+0x1e>
    110c:	c7 47 10 ff ff ff ff 	mov    DWORD PTR [rdi+0x10],0xffffffff
    1113:	31 c0                	xor    eax,eax
    1115:	ba ff ff ff ff       	mov    edx,0xffffffff
    111a:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    111d:	c3                   	ret
    111e:	48 8d 50 08          	lea    rdx,[rax+0x8]
    1122:	48 39 ca             	cmp    rdx,rcx
    1125:	77 e5                	ja     110c <cgroup_skb_hash_chain_prog+0xc>
    1127:	48 8d 50 50          	lea    rdx,[rax+0x50]
    112b:	48 39 ca             	cmp    rdx,rcx
    112e:	77 dc                	ja     110c <cgroup_skb_hash_chain_prog+0xc>
    1130:	83 78 08 10          	cmp    DWORD PTR [rax+0x8],0x10
    1134:	75 d6                	jne    110c <cgroup_skb_hash_chain_prog+0xc>
    1136:	83 78 0c 08          	cmp    DWORD PTR [rax+0xc],0x8
    113a:	75 d0                	jne    110c <cgroup_skb_hash_chain_prog+0xc>
    113c:	41 57                	push   r15
    113e:	41 56                	push   r14
    1140:	41 54                	push   r12
    1142:	53                   	push   rbx
    1143:	48 ba 25 23 22 84 e4 	movabs rdx,0xcbf29ce484222325
    114a:	9c f2 cb 
    114d:	be 07 00 00 00       	mov    esi,0x7
    1152:	49 b8 95 ef 82 de 43 	movabs r8,0xd1342543de82ef95
    1159:	25 34 d1 
    115c:	45 31 c9             	xor    r9d,r9d
    115f:	49 ba 15 7c 4a 7f b9 	movabs r10,0x9e3779b97f4a7c15
    1166:	79 37 9e 
    1169:	49 bb b3 01 00 00 00 	movabs r11,0x100000001b3
    1170:	01 00 00 
    1173:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    117a:	84 00 00 00 00 00 
    1180:	49 ff c1             	inc    r9
    1183:	4c 89 cb             	mov    rbx,r9
    1186:	49 0f af da          	imul   rbx,r10
    118a:	4d 89 c6             	mov    r14,r8
    118d:	48 89 f1             	mov    rcx,rsi
    1190:	45 31 ff             	xor    r15d,r15d
    1193:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    119a:	84 00 00 00 00 00 
    11a0:	4d 89 f4             	mov    r12,r14
    11a3:	49 31 dc             	xor    r12,rbx
    11a6:	4e 03 64 f8 10       	add    r12,QWORD PTR [rax+r15*8+0x10]
    11ab:	49 31 d4             	xor    r12,rdx
    11ae:	49 d3 c4             	rol    r12,cl
    11b1:	49 ff c7             	inc    r15
    11b4:	4d 0f af e3          	imul   r12,r11
    11b8:	4c 89 e2             	mov    rdx,r12
    11bb:	48 c1 ea 1d          	shr    rdx,0x1d
    11bf:	4c 31 e2             	xor    rdx,r12
    11c2:	48 83 c1 0b          	add    rcx,0xb
    11c6:	4d 01 c6             	add    r14,r8
    11c9:	49 83 ff 08          	cmp    r15,0x8
    11cd:	75 d1                	jne    11a0 <cgroup_skb_hash_chain_prog+0xa0>
    11cf:	48 83 c6 05          	add    rsi,0x5
    11d3:	49 83 f9 10          	cmp    r9,0x10
    11d7:	75 a7                	jne    1180 <cgroup_skb_hash_chain_prog+0x80>
    11d9:	89 57 10             	mov    DWORD PTR [rdi+0x10],edx
    11dc:	48 c1 ea 20          	shr    rdx,0x20
    11e0:	b8 01 00 00 00       	mov    eax,0x1
    11e5:	5b                   	pop    rbx
    11e6:	41 5c                	pop    r12
    11e8:	41 5e                	pop    r14
    11ea:	41 5f                	pop    r15
    11ec:	89 57 14             	mov    DWORD PTR [rdi+0x14],edx
    11ef:	c3                   	ret

Disassembly of section .fini:

00000000000011f0 <_fini>:
    11f0:	f3 0f 1e fa          	endbr64
    11f4:	48 83 ec 08          	sub    rsp,0x8
    11f8:	48 83 c4 08          	add    rsp,0x8
    11fc:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 18 00 00 00 	sub    rsp,0x18
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	48 8b 57 50          	mov    rdx,QWORD PTR [rdi+0x50]
  1e:	48 8b 8f d0 00 00 00 	mov    rcx,QWORD PTR [rdi+0xd0]
  25:	48 39 d1             	cmp    rcx,rdx
  28:	77 18                	ja     0x42
  2a:	48 89 ce             	mov    rsi,rcx
  2d:	48 83 c6 08          	add    rsi,0x8
  31:	48 39 d6             	cmp    rsi,rdx
  34:	77 0c                	ja     0x42
  36:	48 89 ce             	mov    rsi,rcx
  39:	48 83 c6 50          	add    rsi,0x50
  3d:	48 39 f2             	cmp    rdx,rsi
  40:	73 16                	jae    0x58
  42:	bb ff ff ff ff       	mov    ebx,0xffffffff
  47:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
  4a:	31 c0                	xor    eax,eax
  4c:	89 5f 34             	mov    DWORD PTR [rdi+0x34],ebx
  4f:	41 5f                	pop    r15
  51:	41 5e                	pop    r14
  53:	41 5d                	pop    r13
  55:	5b                   	pop    rbx
  56:	c9                   	leave
  57:	c3                   	ret
  58:	48 0f b6 51 09       	movzx  rdx,BYTE PTR [rcx+0x9]
  5d:	48 c1 e2 08          	shl    rdx,0x8
  61:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  66:	48 09 f2             	or     rdx,rsi
  69:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  6e:	48 c1 e6 10          	shl    rsi,0x10
  72:	48 09 f2             	or     rdx,rsi
  75:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  7a:	48 c1 e6 18          	shl    rsi,0x18
  7e:	48 09 f2             	or     rdx,rsi
  81:	48 c1 e2 20          	shl    rdx,0x20
  85:	48 c1 ea 20          	shr    rdx,0x20
  89:	48 83 fa 10          	cmp    rdx,0x10
  8d:	75 b3                	jne    0x42
  8f:	48 0f b6 51 0d       	movzx  rdx,BYTE PTR [rcx+0xd]
  94:	48 c1 e2 08          	shl    rdx,0x8
  98:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
  9d:	48 09 f2             	or     rdx,rsi
  a0:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
  a5:	48 c1 e6 10          	shl    rsi,0x10
  a9:	48 09 f2             	or     rdx,rsi
  ac:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
  b1:	48 c1 e6 18          	shl    rsi,0x18
  b5:	48 09 f2             	or     rdx,rsi
  b8:	48 c1 e2 20          	shl    rdx,0x20
  bc:	48 c1 ea 20          	shr    rdx,0x20
  c0:	48 83 fa 08          	cmp    rdx,0x8
  c4:	0f 85 78 ff ff ff    	jne    0x42
  ca:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  ce:	48 bb 25 23 22 84 e4 	movabs rbx,0xcbf29ce484222325
  d5:	9c f2 cb 
  d8:	45 31 ed             	xor    r13d,r13d
  db:	48 83 c1 17          	add    rcx,0x17
  df:	45 31 ff             	xor    r15d,r15d
  e2:	48 89 4d f0          	mov    QWORD PTR [rbp-0x10],rcx
  e6:	eb 16                	jmp    0xfe
  e8:	49 83 c5 05          	add    r13,0x5
  ec:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  f0:	4c 8b 7d f8          	mov    r15,QWORD PTR [rbp-0x8]
  f4:	49 83 ff 10          	cmp    r15,0x10
  f8:	0f 84 f1 00 00 00    	je     0x1ef
  fe:	41 be 07 00 00 00    	mov    r14d,0x7
 104:	49 83 c7 01          	add    r15,0x1
 108:	4c 89 7d f8          	mov    QWORD PTR [rbp-0x8],r15
 10c:	48 bf 15 7c 4a 7f b9 	movabs rdi,0x9e3779b97f4a7c15
 113:	79 37 9e 
 116:	4c 0f af ff          	imul   r15,rdi
 11a:	48 89 ce             	mov    rsi,rcx
 11d:	49 b8 95 ef 82 de 43 	movabs r8,0xd1342543de82ef95
 124:	25 34 d1 
 127:	eb 33                	jmp    0x15c
 129:	48 bf b3 01 00 00 00 	movabs rdi,0x100000001b3
 130:	01 00 00 
 133:	48 0f af d7          	imul   rdx,rdi
 137:	48 89 d3             	mov    rbx,rdx
 13a:	48 c1 eb 1d          	shr    rbx,0x1d
 13e:	48 31 d3             	xor    rbx,rdx
 141:	48 bf 95 ef 82 de 43 	movabs rdi,0xd1342543de82ef95
 148:	25 34 d1 
 14b:	49 01 f8             	add    r8,rdi
 14e:	48 83 c6 08          	add    rsi,0x8
 152:	49 83 c6 0b          	add    r14,0xb
 156:	49 83 fe 5f          	cmp    r14,0x5f
 15a:	74 8c                	je     0xe8
 15c:	48 0f b6 56 fd       	movzx  rdx,BYTE PTR [rsi-0x3]
 161:	48 c1 e2 20          	shl    rdx,0x20
 165:	48 0f b6 4e fb       	movzx  rcx,BYTE PTR [rsi-0x5]
 16a:	48 c1 e1 10          	shl    rcx,0x10
 16e:	48 09 d1             	or     rcx,rdx
 171:	48 0f b6 46 fc       	movzx  rax,BYTE PTR [rsi-0x4]
 176:	48 c1 e0 18          	shl    rax,0x18
 17a:	48 0f b6 56 fa       	movzx  rdx,BYTE PTR [rsi-0x6]
 17f:	48 c1 e2 08          	shl    rdx,0x8
 183:	48 09 c2             	or     rdx,rax
 186:	48 09 ca             	or     rdx,rcx
 189:	48 0f b6 4e fe       	movzx  rcx,BYTE PTR [rsi-0x2]
 18e:	48 c1 e1 28          	shl    rcx,0x28
 192:	48 09 ca             	or     rdx,rcx
 195:	48 0f b6 4e 00       	movzx  rcx,BYTE PTR [rsi+0x0]
 19a:	48 c1 e1 38          	shl    rcx,0x38
 19e:	48 0f b6 46 ff       	movzx  rax,BYTE PTR [rsi-0x1]
 1a3:	48 c1 e0 30          	shl    rax,0x30
 1a7:	48 09 c8             	or     rax,rcx
 1aa:	48 09 c2             	or     rdx,rax
 1ad:	48 0f b6 4e f9       	movzx  rcx,BYTE PTR [rsi-0x7]
 1b2:	48 09 ca             	or     rdx,rcx
 1b5:	4c 89 e9             	mov    rcx,r13
 1b8:	4c 01 f1             	add    rcx,r14
 1bb:	4c 89 c0             	mov    rax,r8
 1be:	4c 31 f8             	xor    rax,r15
 1c1:	48 01 c2             	add    rdx,rax
 1c4:	48 31 da             	xor    rdx,rbx
 1c7:	48 83 e1 3f          	and    rcx,0x3f
 1cb:	48 85 c9             	test   rcx,rcx
 1ce:	0f 84 55 ff ff ff    	je     0x129
 1d4:	bf 40 00 00 00       	mov    edi,0x40
 1d9:	48 29 cf             	sub    rdi,rcx
 1dc:	48 89 d0             	mov    rax,rdx
 1df:	c4 e2 c3 f7 c0       	shrx   rax,rax,rdi
 1e4:	48 d3 e2             	shl    rdx,cl
 1e7:	48 09 c2             	or     rdx,rax
 1ea:	e9 3a ff ff ff       	jmp    0x129
 1ef:	48 8b 7d e8          	mov    rdi,QWORD PTR [rbp-0x18]
 1f3:	89 5f 30             	mov    DWORD PTR [rdi+0x30],ebx
 1f6:	b8 01 00 00 00       	mov    eax,0x1
 1fb:	48 c1 eb 20          	shr    rbx,0x20
 1ff:	e9 48 fe ff ff       	jmp    0x4c
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 47 4c             	mov    eax,DWORD PTR [rdi+0x4c]
   7:	8b 4f 50             	mov    ecx,DWORD PTR [rdi+0x50]
   a:	39 c8                	cmp    eax,ecx
   c:	0f 87 ef 00 00 00    	ja     0x101
  12:	48 8d 50 08          	lea    rdx,[rax+0x8]
  16:	48 39 ca             	cmp    rdx,rcx
  19:	0f 87 e2 00 00 00    	ja     0x101
  1f:	48 8d 50 50          	lea    rdx,[rax+0x50]
  23:	48 39 ca             	cmp    rdx,rcx
  26:	0f 87 d5 00 00 00    	ja     0x101
  2c:	83 78 08 10          	cmp    DWORD PTR [rax+0x8],0x10
  30:	0f 85 cb 00 00 00    	jne    0x101
  36:	83 78 0c 08          	cmp    DWORD PTR [rax+0xc],0x8
  3a:	0f 85 c1 00 00 00    	jne    0x101
  40:	55                   	push   rbp
  41:	41 57                	push   r15
  43:	41 56                	push   r14
  45:	41 55                	push   r13
  47:	41 54                	push   r12
  49:	53                   	push   rbx
  4a:	48 be 95 ef 82 de 43 	movabs rsi,0xd1342543de82ef95
  51:	25 34 d1 
  54:	48 83 c0 17          	add    rax,0x17
  58:	48 ba 25 23 22 84 e4 	movabs rdx,0xcbf29ce484222325
  5f:	9c f2 cb 
  62:	45 31 c0             	xor    r8d,r8d
  65:	49 b9 15 7c 4a 7f b9 	movabs r9,0x9e3779b97f4a7c15
  6c:	79 37 9e 
  6f:	49 ba b3 01 00 00 00 	movabs r10,0x100000001b3
  76:	01 00 00 
  79:	45 31 db             	xor    r11d,r11d
  7c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
  80:	49 ff c3             	inc    r11
  83:	4c 89 db             	mov    rbx,r11
  86:	49 0f af d9          	imul   rbx,r9
  8a:	41 be 07 00 00 00    	mov    r14d,0x7
  90:	49 89 c7             	mov    r15,rax
  93:	49 89 f4             	mov    r12,rsi
  96:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
  9d:	00 00 00 
  a0:	4b 8d 0c 30          	lea    rcx,[r8+r14*1]
  a4:	4d 89 e5             	mov    r13,r12
  a7:	49 31 dd             	xor    r13,rbx
  aa:	4d 03 6f f9          	add    r13,QWORD PTR [r15-0x7]
  ae:	49 31 d5             	xor    r13,rdx
  b1:	4c 89 ed             	mov    rbp,r13
  b4:	48 d3 c5             	rol    rbp,cl
  b7:	f6 c1 3f             	test   cl,0x3f
  ba:	49 0f 44 ed          	cmove  rbp,r13
  be:	49 0f af ea          	imul   rbp,r10
  c2:	48 89 ea             	mov    rdx,rbp
  c5:	48 c1 ea 1d          	shr    rdx,0x1d
  c9:	48 31 ea             	xor    rdx,rbp
  cc:	49 01 f4             	add    r12,rsi
  cf:	49 83 c7 08          	add    r15,0x8
  d3:	49 83 c6 0b          	add    r14,0xb
  d7:	49 83 fe 5f          	cmp    r14,0x5f
  db:	75 c3                	jne    0xa0
  dd:	49 83 c0 05          	add    r8,0x5
  e1:	49 83 fb 10          	cmp    r11,0x10
  e5:	75 99                	jne    0x80
  e7:	89 57 30             	mov    DWORD PTR [rdi+0x30],edx
  ea:	48 c1 ea 20          	shr    rdx,0x20
  ee:	b8 01 00 00 00       	mov    eax,0x1
  f3:	5b                   	pop    rbx
  f4:	41 5c                	pop    r12
  f6:	41 5d                	pop    r13
  f8:	41 5e                	pop    r14
  fa:	41 5f                	pop    r15
  fc:	5d                   	pop    rbp
  fd:	89 57 34             	mov    DWORD PTR [rdi+0x34],edx
 100:	c3                   	ret
 101:	c7 47 30 ff ff ff ff 	mov    DWORD PTR [rdi+0x30],0xffffffff
 108:	ba ff ff ff ff       	mov    edx,0xffffffff
 10d:	31 c0                	xor    eax,eax
 10f:	89 57 34             	mov    DWORD PTR [rdi+0x34],edx
 112:	c3                   	ret
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
    /* 0x1100: mov    rax,QWORD PTR [rdi] [context-abi: native skb shim field at off 0 maps to __sk_buff u32 ctx field at off 76] */
    HC_LDX(BPF_W, BPF_REG_0, BPF_REG_1, 76),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [context-abi: native skb shim field at off 8 maps to __sk_buff u32 ctx field at off 80] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 80),
    /* 0x1107: cmp    rax,rcx [absorbed-control-flow: cmp folded into following ordinary BPF jbe] */
    /* 0x110a: jbe    111e <cgroup_skb_hash_chain_prog+0x1e> [exact-bpf: jbe ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_0, BPF_REG_4, (10) - 1, 0),
    /* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff [context-abi: native skb shim cb store at off 16 maps to __sk_buff cb field at off 48] */
    HC_KINSN(HC_X86_STORE_IMM_PAYLOAD(BPF_REG_1, 48, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1113: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1115: mov    edx,0xffffffff [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_3, 4294967295), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111a: mov    DWORD PTR [rdi+0x14],edx [context-abi: native skb shim cb store at off 20 maps to __sk_buff cb field at off 52] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_1, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x111d: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
    /* 0x111e: lea    rdx,[rax+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1122: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x1125: ja     110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-11) - 1, 0),
    /* 0x1127: lea    rdx,[rax+0x50] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_0, 0, 0, 1, 0, 80), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112b: cmp    rdx,rcx [absorbed-control-flow: cmp folded into following ordinary BPF ja] */
    /* 0x112e: ja     110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: ja ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_3, BPF_REG_4, (-14) - 1, 0),
    /* 0x1130: cmp    DWORD PTR [rax+0x8],0x10 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x1134: jne    110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_0, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 1, 16),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-18) - 1),
    /* 0x1136: cmp    DWORD PTR [rax+0xc],0x8 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x113a: jne    110c <cgroup_skb_hash_chain_prog+0xc> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_0, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, 1, 8),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-22) - 1),
    /* 0x113c: push   r15 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x113e: push   r14 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1140: push   r12 [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1142: push   rbx [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1143: movabs rdx,0xcbf29ce484222325 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_3, 0, 0xcbf29ce484222325ULL),
    /* 0x114d: mov    esi,0x7 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_2, 7), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1152: movabs r8,0xd1342543de82ef95 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_5, 0, 0xd1342543de82ef95ULL),
    /* 0x115c: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x115f: movabs r10,0x9e3779b97f4a7c15 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x9e3779b97f4a7c15ULL),
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R10, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1169: movabs r11,0x100000001b3 [exact-bpf: movabs via verifier-visible BPF immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_6, 0, 0x100000001b3ULL),
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1173: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1180: inc    r9 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1183: mov    rbx,r9 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1186: imul   rbx,r10 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x118a: mov    r14,r8 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_8, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x118d: mov    rcx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1190: xor    r15d,r15d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_9, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1193: data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x11a0: mov    r12,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(HC_X86_R12, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a3: xor    r12,rbx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11a6: add    r12,QWORD PTR [rax+r15*8+0x10] [exact-kinsn: add64 SIB memory-source kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(HC_X86_R12, BPF_REG_0, BPF_REG_9, 3, 16), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11ab: xor    r12,rdx [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(HC_X86_R12, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11ae: rol    r12,cl [exact-kinsn: rolq cl kinsn] */
    HC_KINSN(HC_ROTATE_CL_PAYLOAD(HC_X86_R12, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_ROLQ),
    /* 0x11b1: inc    r15 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x11b4: imul   r12,r11 [exact-kinsn: imulq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R12, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_IMULQ),
    /* 0x11b8: mov    rdx,r12 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_3, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11bb: shr    rdx,0x1d [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 29), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11bf: xor    rdx,r12 [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_3, HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x11c2: add    rcx,0xb [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_4, 11), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c6: add    r14,r8 [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ALU_RR_PAYLOAD(BPF_REG_8, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11c9: cmp    r15,0x8 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11cd: jne    11a0 <cgroup_skb_hash_chain_prog+0xa0> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, (-24) - 1, 8),
    /* 0x11cf: add    rsi,0x5 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_2, 5), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x11d3: cmp    r9,0x10 [absorbed-control-flow: cmp folded into following ordinary BPF jne] */
    /* 0x11d7: jne    1180 <cgroup_skb_hash_chain_prog+0x80> [exact-bpf: jne ordinary BPF branch from preceding cmp] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_6, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, 1, 16),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, 1),
    HC_RAW(BPF_JMP32 | BPF_JA, 0, 0, 0, (-43) - 1),
    /* 0x11d9: mov    DWORD PTR [rdi+0x10],edx [context-abi: native skb shim cb store at off 16 maps to __sk_buff cb field at off 48] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_1, 48), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11dc: shr    rdx,0x20 [exact-kinsn: shr64 imm kinsn] */
    HC_KINSN(HC_X86_ALU_IMM_PAYLOAD(BPF_REG_3, 32), MICRO_HANDCRAFT_BPF_X86_SHRQ),
    /* 0x11e0: mov    eax,0x1 [exact-kinsn: movl immediate kinsn] */
    HC_KINSN(HC_X86_IMM_PAYLOAD(BPF_REG_0, 1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11e5: pop    rbx [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11e6: pop    r12 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R12), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11e8: pop    r14 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11ea: pop    r15 [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x11ec: mov    DWORD PTR [rdi+0x14],edx [context-abi: native skb shim cb store at off 20 maps to __sk_buff cb field at off 52] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_3, BPF_REG_1, 52), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x11ef: ret [abi-boundary: native ret maps to the BPF program exit boundary] */
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec e0 01 00 00 	sub    rsp,0x1e0
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	48 89 eb             	mov    rbx,rbp
  1d:	48 83 c3 80          	add    rbx,0xffffffffffffff80
  21:	48 89 9d 20 fe ff ff 	mov    QWORD PTR [rbp-0x1e0],rbx
  28:	31 db                	xor    ebx,ebx
  2a:	45 31 ed             	xor    r13d,r13d
  2d:	45 31 f6             	xor    r14d,r14d
  30:	45 31 ff             	xor    r15d,r15d
  33:	48 8b 87 d0 00 00 00 	mov    rax,QWORD PTR [rdi+0xd0]
  3a:	48 8b 4f 50          	mov    rcx,QWORD PTR [rdi+0x50]
  3e:	48 39 c8             	cmp    rax,rcx
  41:	76 1a                	jbe    0x5d
  43:	c7 47 30 ff ff ff 0f 	mov    DWORD PTR [rdi+0x30],0xfffffff
  4a:	31 c0                	xor    eax,eax
  4c:	ba ff ff ff ff       	mov    edx,0xffffffff
  51:	89 57 34             	mov    DWORD PTR [rdi+0x34],edx
  54:	41 5f                	pop    r15
  56:	41 5e                	pop    r14
  58:	41 5d                	pop    r13
  5a:	5b                   	pop    rbx
  5b:	c9                   	leave
  5c:	c3                   	ret
  5d:	48 8d 50 08          	lea    rdx,[rax+0x8]
  61:	48 39 ca             	cmp    rdx,rcx
  64:	77 dd                	ja     0x43
  66:	48 8d 50 50          	lea    rdx,[rax+0x50]
  6a:	48 39 ca             	cmp    rdx,rcx
  6d:	77 d4                	ja     0x43
  6f:	8b 58 08             	mov    ebx,DWORD PTR [rax+0x8]
  72:	83 fb 10             	cmp    ebx,0x10
  75:	75 02                	jne    0x79
  77:	eb 02                	jmp    0x7b
  79:	eb c8                	jmp    0x43
  7b:	8b 58 0c             	mov    ebx,DWORD PTR [rax+0xc]
  7e:	83 fb 08             	cmp    ebx,0x8
  81:	75 02                	jne    0x85
  83:	eb 02                	jmp    0x87
  85:	eb bc                	jmp    0x43
  87:	41 57                	push   r15
  89:	41 56                	push   r14
  8b:	41 54                	push   r12
  8d:	53                   	push   rbx
  8e:	48 ba 25 23 22 84 e4 	movabs rdx,0xcbf29ce484222325
  95:	9c f2 cb 
  98:	be 07 00 00 00       	mov    esi,0x7
  9d:	49 b8 95 ef 82 de 43 	movabs r8,0xd1342543de82ef95
  a4:	25 34 d1 
  a7:	45 31 c9             	xor    r9d,r9d
  aa:	48 bb 15 7c 4a 7f b9 	movabs rbx,0x9e3779b97f4a7c15
  b1:	79 37 9e 
  b4:	49 89 da             	mov    r10,rbx
  b7:	48 bb b3 01 00 00 00 	movabs rbx,0x100000001b3
  be:	01 00 00 
  c1:	49 89 db             	mov    r11,rbx
  c4:	49 ff c1             	inc    r9
  c7:	4c 89 cb             	mov    rbx,r9
  ca:	49 0f af da          	imul   rbx,r10
  ce:	4d 89 c6             	mov    r14,r8
  d1:	48 89 f1             	mov    rcx,rsi
  d4:	45 31 ff             	xor    r15d,r15d
  d7:	4d 89 f4             	mov    r12,r14
  da:	49 31 dc             	xor    r12,rbx
  dd:	4e 03 64 f8 10       	add    r12,QWORD PTR [rax+r15*8+0x10]
  e2:	49 31 d4             	xor    r12,rdx
  e5:	49 d3 c4             	rol    r12,cl
  e8:	49 ff c7             	inc    r15
  eb:	4d 0f af e3          	imul   r12,r11
  ef:	4c 89 e2             	mov    rdx,r12
  f2:	48 c1 ea 1d          	shr    rdx,0x1d
  f6:	4c 31 e2             	xor    rdx,r12
  f9:	48 83 c1 0b          	add    rcx,0xb
  fd:	4d 01 c6             	add    r14,r8
 100:	49 83 ff 08          	cmp    r15,0x8
 104:	75 d1                	jne    0xd7
 106:	48 83 c6 05          	add    rsi,0x5
 10a:	4c 89 cb             	mov    rbx,r9
 10d:	48 83 fb 10          	cmp    rbx,0x10
 111:	75 02                	jne    0x115
 113:	eb 02                	jmp    0x117
 115:	eb ad                	jmp    0xc4
 117:	89 57 30             	mov    DWORD PTR [rdi+0x30],edx
 11a:	48 c1 ea 20          	shr    rdx,0x20
 11e:	b8 01 00 00 00       	mov    eax,0x1
 123:	5b                   	pop    rbx
 124:	41 5c                	pop    r12
 126:	41 5e                	pop    r14
 128:	41 5f                	pop    r15
 12a:	89 57 34             	mov    DWORD PTR [rdi+0x34],edx
 12d:	e9 22 ff ff ff       	jmp    0x54
```
