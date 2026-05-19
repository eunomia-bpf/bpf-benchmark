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

0000000000001100 <cgroup_skb_hash_chain_prog>:
    1100:	48 8b 87 d0 00 00 00 	mov    rax,QWORD PTR [rdi+0xd0]
    1107:	83 7f 70 4f          	cmp    DWORD PTR [rdi+0x70],0x4f
    110b:	77 0a                	ja     1117 <cgroup_skb_hash_chain_prog+0x17>
    110d:	48 c7 00 ff ff ff ff 	mov    QWORD PTR [rax],0xffffffffffffffff
    1114:	31 c0                	xor    eax,eax
    1116:	c3                   	ret
    1117:	83 78 08 10          	cmp    DWORD PTR [rax+0x8],0x10
    111b:	75 f0                	jne    110d <cgroup_skb_hash_chain_prog+0xd>
    111d:	83 78 0c 08          	cmp    DWORD PTR [rax+0xc],0x8
    1121:	75 ea                	jne    110d <cgroup_skb_hash_chain_prog+0xd>
    1123:	41 57                	push   r15
    1125:	41 56                	push   r14
    1127:	53                   	push   rbx
    1128:	48 ba 25 23 22 84 e4 	movabs rdx,0xcbf29ce484222325
    112f:	9c f2 cb 
    1132:	bf 07 00 00 00       	mov    edi,0x7
    1137:	49 b8 95 ef 82 de 43 	movabs r8,0xd1342543de82ef95
    113e:	25 34 d1 
    1141:	45 31 c9             	xor    r9d,r9d
    1144:	49 ba 15 7c 4a 7f b9 	movabs r10,0x9e3779b97f4a7c15
    114b:	79 37 9e 
    114e:	49 bb b3 01 00 00 00 	movabs r11,0x100000001b3
    1155:	01 00 00 
    1158:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    115f:	00 
    1160:	49 ff c1             	inc    r9
    1163:	4c 89 cb             	mov    rbx,r9
    1166:	49 0f af da          	imul   rbx,r10
    116a:	41 be 17 00 00 00    	mov    r14d,0x17
    1170:	4d 89 c7             	mov    r15,r8
    1173:	48 89 f9             	mov    rcx,rdi
    1176:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    117d:	00 00 00 
    1180:	4c 89 fe             	mov    rsi,r15
    1183:	48 31 de             	xor    rsi,rbx
    1186:	4a 03 74 30 f9       	add    rsi,QWORD PTR [rax+r14*1-0x7]
    118b:	48 31 d6             	xor    rsi,rdx
    118e:	48 d3 c6             	rol    rsi,cl
    1191:	49 0f af f3          	imul   rsi,r11
    1195:	48 89 f2             	mov    rdx,rsi
    1198:	48 c1 ea 1d          	shr    rdx,0x1d
    119c:	48 31 f2             	xor    rdx,rsi
    119f:	49 83 c6 08          	add    r14,0x8
    11a3:	48 83 c1 0b          	add    rcx,0xb
    11a7:	4d 01 c7             	add    r15,r8
    11aa:	49 83 fe 57          	cmp    r14,0x57
    11ae:	75 d0                	jne    1180 <cgroup_skb_hash_chain_prog+0x80>
    11b0:	48 83 c7 05          	add    rdi,0x5
    11b4:	49 83 f9 10          	cmp    r9,0x10
    11b8:	75 a6                	jne    1160 <cgroup_skb_hash_chain_prog+0x60>
    11ba:	88 10                	mov    BYTE PTR [rax],dl
    11bc:	88 70 01             	mov    BYTE PTR [rax+0x1],dh
    11bf:	89 d1                	mov    ecx,edx
    11c1:	c1 e9 10             	shr    ecx,0x10
    11c4:	88 48 02             	mov    BYTE PTR [rax+0x2],cl
    11c7:	89 d1                	mov    ecx,edx
    11c9:	c1 e9 18             	shr    ecx,0x18
    11cc:	88 48 03             	mov    BYTE PTR [rax+0x3],cl
    11cf:	48 c1 ea 20          	shr    rdx,0x20
    11d3:	88 50 04             	mov    BYTE PTR [rax+0x4],dl
    11d6:	48 89 f1             	mov    rcx,rsi
    11d9:	48 c1 e9 28          	shr    rcx,0x28
    11dd:	88 48 05             	mov    BYTE PTR [rax+0x5],cl
    11e0:	48 89 f1             	mov    rcx,rsi
    11e3:	48 c1 e9 30          	shr    rcx,0x30
    11e7:	88 48 06             	mov    BYTE PTR [rax+0x6],cl
    11ea:	48 c1 ee 38          	shr    rsi,0x38
    11ee:	40 88 70 07          	mov    BYTE PTR [rax+0x7],sil
    11f2:	b8 01 00 00 00       	mov    eax,0x1
    11f7:	5b                   	pop    rbx
    11f8:	41 5e                	pop    r14
    11fa:	41 5f                	pop    r15
    11fc:	c3                   	ret

Disassembly of section .fini:

0000000000001200 <_fini>:
    1200:	f3 0f 1e fa          	endbr64
    1204:	48 83 ec 08          	sub    rsp,0x8
    1208:	48 83 c4 08          	add    rsp,0x8
    120c:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 20 00 00 00 	sub    rsp,0x20
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
  3d:	48 39 d6             	cmp    rsi,rdx
  40:	76 19                	jbe    0x5b
  42:	41 bd ff ff ff ff    	mov    r13d,0xffffffff
  48:	44 89 6f 30          	mov    DWORD PTR [rdi+0x30],r13d
  4c:	31 c0                	xor    eax,eax
  4e:	44 89 6f 34          	mov    DWORD PTR [rdi+0x34],r13d
  52:	41 5f                	pop    r15
  54:	41 5e                	pop    r14
  56:	41 5d                	pop    r13
  58:	5b                   	pop    rbx
  59:	c9                   	leave
  5a:	c3                   	ret
  5b:	48 0f b6 51 09       	movzx  rdx,BYTE PTR [rcx+0x9]
  60:	c1 e2 08             	shl    edx,0x8
  63:	48 0f b6 71 08       	movzx  rsi,BYTE PTR [rcx+0x8]
  68:	09 f2                	or     edx,esi
  6a:	48 0f b6 71 0a       	movzx  rsi,BYTE PTR [rcx+0xa]
  6f:	c1 e6 10             	shl    esi,0x10
  72:	09 f2                	or     edx,esi
  74:	48 0f b6 71 0b       	movzx  rsi,BYTE PTR [rcx+0xb]
  79:	c1 e6 18             	shl    esi,0x18
  7c:	09 f2                	or     edx,esi
  7e:	83 fa 10             	cmp    edx,0x10
  81:	75 bf                	jne    0x42
  83:	48 0f b6 51 0d       	movzx  rdx,BYTE PTR [rcx+0xd]
  88:	c1 e2 08             	shl    edx,0x8
  8b:	48 0f b6 71 0c       	movzx  rsi,BYTE PTR [rcx+0xc]
  90:	09 f2                	or     edx,esi
  92:	48 0f b6 71 0e       	movzx  rsi,BYTE PTR [rcx+0xe]
  97:	c1 e6 10             	shl    esi,0x10
  9a:	09 f2                	or     edx,esi
  9c:	48 0f b6 71 0f       	movzx  rsi,BYTE PTR [rcx+0xf]
  a1:	c1 e6 18             	shl    esi,0x18
  a4:	09 f2                	or     edx,esi
  a6:	83 fa 08             	cmp    edx,0x8
  a9:	75 97                	jne    0x42
  ab:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
  af:	49 bd 25 23 22 84 e4 	movabs r13,0xcbf29ce484222325
  b6:	9c f2 cb 
  b9:	31 ff                	xor    edi,edi
  bb:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  bf:	48 83 c1 17          	add    rcx,0x17
  c3:	45 31 ff             	xor    r15d,r15d
  c6:	48 89 4d e8          	mov    QWORD PTR [rbp-0x18],rcx
  ca:	eb 1e                	jmp    0xea
  cc:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
  d0:	48 83 c7 05          	add    rdi,0x5
  d4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  d8:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
  dc:	4c 8b 7d f0          	mov    r15,QWORD PTR [rbp-0x10]
  e0:	49 83 ff 10          	cmp    r15,0x10
  e4:	0f 84 f8 00 00 00    	je     0x1e2
  ea:	41 be 07 00 00 00    	mov    r14d,0x7
  f0:	49 83 c7 01          	add    r15,0x1
  f4:	4c 89 7d f0          	mov    QWORD PTR [rbp-0x10],r15
  f8:	48 bf 15 7c 4a 7f b9 	movabs rdi,0x9e3779b97f4a7c15
  ff:	79 37 9e 
 102:	4c 0f af ff          	imul   r15,rdi
 106:	48 89 ce             	mov    rsi,rcx
 109:	49 b8 95 ef 82 de 43 	movabs r8,0xd1342543de82ef95
 110:	25 34 d1 
 113:	eb 33                	jmp    0x148
 115:	48 bf b3 01 00 00 00 	movabs rdi,0x100000001b3
 11c:	01 00 00 
 11f:	48 0f af d7          	imul   rdx,rdi
 123:	49 89 d5             	mov    r13,rdx
 126:	49 c1 ed 1d          	shr    r13,0x1d
 12a:	49 31 d5             	xor    r13,rdx
 12d:	48 bf 95 ef 82 de 43 	movabs rdi,0xd1342543de82ef95
 134:	25 34 d1 
 137:	49 01 f8             	add    r8,rdi
 13a:	48 83 c6 08          	add    rsi,0x8
 13e:	49 83 c6 0b          	add    r14,0xb
 142:	49 83 fe 5f          	cmp    r14,0x5f
 146:	74 84                	je     0xcc
 148:	48 0f b6 56 fd       	movzx  rdx,BYTE PTR [rsi-0x3]
 14d:	48 c1 e2 20          	shl    rdx,0x20
 151:	48 0f b6 4e fb       	movzx  rcx,BYTE PTR [rsi-0x5]
 156:	48 c1 e1 10          	shl    rcx,0x10
 15a:	48 09 d1             	or     rcx,rdx
 15d:	48 0f b6 46 fc       	movzx  rax,BYTE PTR [rsi-0x4]
 162:	48 c1 e0 18          	shl    rax,0x18
 166:	48 0f b6 56 fa       	movzx  rdx,BYTE PTR [rsi-0x6]
 16b:	48 c1 e2 08          	shl    rdx,0x8
 16f:	48 09 c2             	or     rdx,rax
 172:	48 09 ca             	or     rdx,rcx
 175:	48 0f b6 4e fe       	movzx  rcx,BYTE PTR [rsi-0x2]
 17a:	48 c1 e1 28          	shl    rcx,0x28
 17e:	48 09 ca             	or     rdx,rcx
 181:	48 0f b6 4e 00       	movzx  rcx,BYTE PTR [rsi+0x0]
 186:	48 c1 e1 38          	shl    rcx,0x38
 18a:	48 0f b6 46 ff       	movzx  rax,BYTE PTR [rsi-0x1]
 18f:	48 c1 e0 30          	shl    rax,0x30
 193:	48 09 c8             	or     rax,rcx
 196:	48 09 c2             	or     rdx,rax
 199:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 19d:	4c 01 f1             	add    rcx,r14
 1a0:	4c 89 c0             	mov    rax,r8
 1a3:	4c 31 f8             	xor    rax,r15
 1a6:	48 0f b6 5e f9       	movzx  rbx,BYTE PTR [rsi-0x7]
 1ab:	48 09 da             	or     rdx,rbx
 1ae:	48 01 c2             	add    rdx,rax
 1b1:	4c 31 ea             	xor    rdx,r13
 1b4:	89 cf                	mov    edi,ecx
 1b6:	83 e7 3f             	and    edi,0x3f
 1b9:	85 ff                	test   edi,edi
 1bb:	0f 84 54 ff ff ff    	je     0x115
 1c1:	b8 40 00 00 00       	mov    eax,0x40
 1c6:	29 f8                	sub    eax,edi
 1c8:	48 83 e1 3f          	and    rcx,0x3f
 1cc:	48 89 d7             	mov    rdi,rdx
 1cf:	48 d3 e7             	shl    rdi,cl
 1d2:	c4 e2 fb f7 d2       	shrx   rdx,rdx,rax
 1d7:	48 09 d7             	or     rdi,rdx
 1da:	48 89 fa             	mov    rdx,rdi
 1dd:	e9 33 ff ff ff       	jmp    0x115
 1e2:	48 8b 7d e0          	mov    rdi,QWORD PTR [rbp-0x20]
 1e6:	44 89 6f 30          	mov    DWORD PTR [rdi+0x30],r13d
 1ea:	b8 01 00 00 00       	mov    eax,0x1
 1ef:	49 c1 ed 20          	shr    r13,0x20
 1f3:	e9 56 fe ff ff       	jmp    0x4e
```

## llvmbpf JIT ASM
```asm
not captured
```
