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

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

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
  1c:	0f 87 81 01 00 00    	ja     0x1a3
  22:	48 89 fa             	mov    rdx,rdi
  25:	48 83 c2 08          	add    rdx,0x8
  29:	48 39 f2             	cmp    rdx,rsi
  2c:	0f 87 71 01 00 00    	ja     0x1a3
  32:	48 89 fa             	mov    rdx,rdi
  35:	48 81 c2 10 04 00 00 	add    rdx,0x410
  3c:	48 39 f2             	cmp    rdx,rsi
  3f:	0f 87 5e 01 00 00    	ja     0x1a3
  45:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  4a:	48 c1 e6 08          	shl    rsi,0x8
  4e:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  53:	48 09 d6             	or     rsi,rdx
  56:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  5b:	48 c1 e2 10          	shl    rdx,0x10
  5f:	48 09 d6             	or     rsi,rdx
  62:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  67:	48 c1 e2 18          	shl    rdx,0x18
  6b:	48 09 d6             	or     rsi,rdx
  6e:	48 c1 e6 20          	shl    rsi,0x20
  72:	48 c1 ee 20          	shr    rsi,0x20
  76:	48 83 fe 20          	cmp    rsi,0x20
  7a:	0f 85 23 01 00 00    	jne    0x1a3
  80:	48 0f b6 77 0d       	movzx  rsi,BYTE PTR [rdi+0xd]
  85:	48 c1 e6 08          	shl    rsi,0x8
  89:	48 0f b6 57 0c       	movzx  rdx,BYTE PTR [rdi+0xc]
  8e:	48 09 d6             	or     rsi,rdx
  91:	48 0f b6 57 0e       	movzx  rdx,BYTE PTR [rdi+0xe]
  96:	48 c1 e2 10          	shl    rdx,0x10
  9a:	48 09 d6             	or     rsi,rdx
  9d:	48 0f b6 57 0f       	movzx  rdx,BYTE PTR [rdi+0xf]
  a2:	48 c1 e2 18          	shl    rdx,0x18
  a6:	48 09 d6             	or     rsi,rdx
  a9:	48 c1 e6 20          	shl    rsi,0x20
  ad:	48 c1 ee 20          	shr    rsi,0x20
  b1:	48 81 fe 00 02 00 00 	cmp    rsi,0x200
  b8:	0f 85 e5 00 00 00    	jne    0x1a3
  be:	31 f6                	xor    esi,esi
  c0:	ba 00 00 ff ff       	mov    edx,0xffff0000
  c5:	31 c9                	xor    ecx,ecx
  c7:	45 31 c0             	xor    r8d,r8d
  ca:	31 db                	xor    ebx,ebx
  cc:	48 89 f8             	mov    rax,rdi
  cf:	4c 01 c0             	add    rax,r8
  d2:	4c 0f b6 68 10       	movzx  r13,BYTE PTR [rax+0x10]
  d7:	48 0f b6 40 11       	movzx  rax,BYTE PTR [rax+0x11]
  dc:	48 c1 e0 08          	shl    rax,0x8
  e0:	4c 09 e8             	or     rax,r13
  e3:	48 01 d8             	add    rax,rbx
  e6:	48 89 c3             	mov    rbx,rax
  e9:	48 21 d3             	and    rbx,rdx
  ec:	48 25 ff ff 00 00    	and    rax,0xffff
  f2:	48 c1 eb 10          	shr    rbx,0x10
  f6:	48 01 d8             	add    rax,rbx
  f9:	49 83 c0 02          	add    r8,0x2
  fd:	48 89 c3             	mov    rbx,rax
 100:	49 81 f8 00 04 00 00 	cmp    r8,0x400
 107:	74 02                	je     0x10b
 109:	eb c1                	jmp    0xcc
 10b:	49 89 c0             	mov    r8,rax
 10e:	49 c1 e8 10          	shr    r8,0x10
 112:	49 01 c0             	add    r8,rax
 115:	49 83 f0 ff          	xor    r8,0xffffffffffffffff
 119:	49 81 e0 ff ff 00 00 	and    r8,0xffff
 120:	48 89 f0             	mov    rax,rsi
 123:	48 c1 e0 04          	shl    rax,0x4
 127:	48 83 e0 30          	and    rax,0x30
 12b:	c4 42 f9 f7 c0       	shlx   r8,r8,rax
 130:	49 31 c8             	xor    r8,rcx
 133:	48 83 c6 01          	add    rsi,0x1
 137:	48 89 f0             	mov    rax,rsi
 13a:	48 c1 e0 20          	shl    rax,0x20
 13e:	48 c1 e8 20          	shr    rax,0x20
 142:	4c 89 c1             	mov    rcx,r8
 145:	48 83 f8 20          	cmp    rax,0x20
 149:	74 05                	je     0x150
 14b:	e9 77 ff ff ff       	jmp    0xc7
 150:	4c 89 c6             	mov    rsi,r8
 153:	48 c1 ee 38          	shr    rsi,0x38
 157:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 15b:	4c 89 c6             	mov    rsi,r8
 15e:	48 c1 ee 30          	shr    rsi,0x30
 162:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 166:	4c 89 c6             	mov    rsi,r8
 169:	48 c1 ee 28          	shr    rsi,0x28
 16d:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 171:	4c 89 c6             	mov    rsi,r8
 174:	48 c1 ee 20          	shr    rsi,0x20
 178:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 17c:	4c 89 c6             	mov    rsi,r8
 17f:	48 c1 ee 18          	shr    rsi,0x18
 183:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 187:	4c 89 c6             	mov    rsi,r8
 18a:	48 c1 ee 10          	shr    rsi,0x10
 18e:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 192:	44 88 47 00          	mov    BYTE PTR [rdi+0x0],r8b
 196:	49 c1 e8 08          	shr    r8,0x8
 19a:	44 88 47 01          	mov    BYTE PTR [rdi+0x1],r8b
 19e:	b8 02 00 00 00       	mov    eax,0x2
 1a3:	41 5d                	pop    r13
 1a5:	5b                   	pop    rbx
 1a6:	c9                   	leave
 1a7:	c3                   	ret
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
   d:	0f 87 8a 00 00 00    	ja     0x9d
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 7d 00 00 00    	ja     0x9d
  20:	48 8d b1 10 04 00 00 	lea    rsi,[rcx+0x410]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	77 71                	ja     0x9d
  2c:	83 79 08 20          	cmp    DWORD PTR [rcx+0x8],0x20
  30:	75 6c                	jne    0x9e
  32:	81 79 0c 00 02 00 00 	cmp    DWORD PTR [rcx+0xc],0x200
  39:	75 63                	jne    0x9e
  3b:	31 c0                	xor    eax,eax
  3d:	31 d2                	xor    edx,edx
  3f:	90                   	nop
  40:	31 f6                	xor    esi,esi
  42:	31 ff                	xor    edi,edi
  44:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  4b:	00 00 00 00 00 
  50:	44 0f b7 44 31 10    	movzx  r8d,WORD PTR [rcx+rsi*1+0x10]
  56:	49 01 f8             	add    r8,rdi
  59:	45 0f b7 c8          	movzx  r9d,r8w
  5d:	41 c1 e8 10          	shr    r8d,0x10
  61:	4c 89 c7             	mov    rdi,r8
  64:	4c 01 cf             	add    rdi,r9
  67:	48 83 c6 02          	add    rsi,0x2
  6b:	48 81 fe 00 04 00 00 	cmp    rsi,0x400
  72:	75 dc                	jne    0x50
  74:	89 fe                	mov    esi,edi
  76:	c1 ee 10             	shr    esi,0x10
  79:	01 fe                	add    esi,edi
  7b:	f7 d6                	not    esi
  7d:	0f b7 f6             	movzx  esi,si
  80:	89 d7                	mov    edi,edx
  82:	c1 e7 04             	shl    edi,0x4
  85:	c4 e2 c1 f7 f6       	shlx   rsi,rsi,rdi
  8a:	48 31 f0             	xor    rax,rsi
  8d:	48 ff c2             	inc    rdx
  90:	83 fa 20             	cmp    edx,0x20
  93:	75 ab                	jne    0x40
  95:	48 89 01             	mov    QWORD PTR [rcx],rax
  98:	b8 02 00 00 00       	mov    eax,0x2
  9d:	c3                   	ret
  9e:	31 c0                	xor    eax,eax
  a0:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * native asm to handcraft warnings: 4
 *
 * - 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20]
 * - 0x112a: cmp    DWORD PTR [rdx+0xc],0x200 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x200]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: mov    rdx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_1, 0),
    /* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 4),
    /* 0x1107: xor    eax,eax [exact-kinsn: xorl zero-idiom kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL_RR),
    /* 0x1109: cmp    rdx,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x110c: jbe    110f <packet_checksum_fold_xdp+0xf> [bpf-branch: lowered cmp    rdx,rcx + jbe    110f <packet_checksum_fold_xdp+0xf> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JLE, BPF_REG_3, BPF_REG_4, 1),
    /* 0x110e: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rdx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     110e <packet_checksum_fold_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_checksum_fold_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -6),
    /* 0x1118: lea    rsi,[rdx+0x410] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 1040), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rcx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1122: ja     110e <packet_checksum_fold_xdp+0xe> [bpf-branch: lowered cmp    rsi,rcx + ja     110e <packet_checksum_fold_xdp+0xe> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_4, -11),
    /* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0x8],0x20] */
    /* 0x1128: jne    110e <packet_checksum_fold_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0x8],0x20 + jne    110e <packet_checksum_fold_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 8),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -13, 32),
    /* 0x112a: cmp    DWORD PTR [rdx+0xc],0x200 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    DWORD PTR [rdx+0xc],0x200] */
    /* 0x1131: jne    110e <packet_checksum_fold_xdp+0xe> [bpf-branch: lowered cmp    DWORD PTR [rdx+0xc],0x200 + jne    110e <packet_checksum_fold_xdp+0xe> to verifier-visible load+branch] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_3, 12),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, -15, 512),
    /* 0x1133: xor    eax,eax [exact-kinsn: xorl zero-idiom kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_0, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_XORL_RR),
    /* 0x1135: xor    esi,esi [exact-kinsn: xorl zero-idiom kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_XORL_RR),
    /* 0x1137: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: mov    ecx,0x13 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_4, 0, 0, 19),
    /* 0x1145: xor    edi,edi [exact-kinsn: xorl zero-idiom kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_XORL_RR),
    /* 0x1147: nop    WORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1150: movzx  r8d,WORD PTR [rdx+rcx*1-0x3] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_5, BPF_REG_3, BPF_REG_4, 0, -3), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1156: add    r8d,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x1159: movzx  edi,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x115d: shr    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x1161: add    r8d,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x1164: movzx  edi,WORD PTR [rdx+rcx*1-0x1] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_SIB_PAYLOAD(BPF_REG_1, BPF_REG_3, BPF_REG_4, 0, -1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1169: add    edi,r8d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x116c: movzx  r8d,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_5, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x1170: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1173: add    edi,r8d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1176: add    rcx,0x4 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_4, 0, 0, 4),
    /* 0x117a: cmp    rcx,0x413 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_4, 1043), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1181: jne    1150 <packet_checksum_fold_xdp+0x50> [bpf-branch: lowered cmp    rcx,0x413 + jne    1150 <packet_checksum_fold_xdp+0x50> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_4, 0, -18, 1043),
    /* 0x1183: mov    ecx,edi [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1185: shr    ecx,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_4, 0, 0, 16),
    /* 0x1188: add    ecx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_4, BPF_REG_1, 0, 0),
    /* 0x118a: not    ecx [exact-kinsn: notl reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_NOTL_R),
    /* 0x118c: movzx  edi,cx [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_1, BPF_REG_4), MICRO_HANDCRAFT_BPF_X86_MOVZWL),
    /* 0x118f: mov    ecx,eax [exact-kinsn: movl register-to-register kinsn] */
    HC_KINSN(HC_X86_RR_PAYLOAD(BPF_REG_4, BPF_REG_0), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1191: shl    ecx,0x4 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_4, 0, 0, 4),
    /* 0x1194: shl    rdi,cl [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_X, BPF_REG_1, BPF_REG_4, 0, 0),
    /* 0x1197: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x119a: inc    eax [bpf-jit: inc lowered to add immediate] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_0, 0, 0, 1),
    /* 0x119c: cmp    eax,0x20 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 32), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x119f: jne    1140 <packet_checksum_fold_xdp+0x40> [bpf-branch: lowered cmp    eax,0x20 + jne    1140 <packet_checksum_fold_xdp+0x40> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_0, 0, -38, 32),
    /* 0x11a1: mov    QWORD PTR [rdx],rsi [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_STORE_PAYLOAD(BPF_REG_2, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x11a4: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x11a9: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
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
   c:	48 81 ec 80 01 00 00 	sub    rsp,0x180
  13:	53                   	push   rbx
  14:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  18:	48 8b 4f 08          	mov    rcx,QWORD PTR [rdi+0x8]
  1c:	31 c0                	xor    eax,eax
  1e:	48 39 ca             	cmp    rdx,rcx
  21:	48 39 ca             	cmp    rdx,rcx
  24:	76 03                	jbe    0x29
  26:	5b                   	pop    rbx
  27:	c9                   	leave
  28:	c3                   	ret
  29:	48 8d 72 08          	lea    rsi,[rdx+0x8]
  2d:	48 39 ce             	cmp    rsi,rcx
  30:	48 39 ce             	cmp    rsi,rcx
  33:	77 f1                	ja     0x26
  35:	48 8d b2 10 04 00 00 	lea    rsi,[rdx+0x410]
  3c:	48 39 ce             	cmp    rsi,rcx
  3f:	48 39 ce             	cmp    rsi,rcx
  42:	77 e2                	ja     0x26
  44:	8b 5a 08             	mov    ebx,DWORD PTR [rdx+0x8]
  47:	48 83 fb 20          	cmp    rbx,0x20
  4b:	75 d9                	jne    0x26
  4d:	8b 5a 0c             	mov    ebx,DWORD PTR [rdx+0xc]
  50:	48 81 fb 00 02 00 00 	cmp    rbx,0x200
  57:	75 cd                	jne    0x26
  59:	31 c0                	xor    eax,eax
  5b:	31 f6                	xor    esi,esi
  5d:	b9 13 00 00 00       	mov    ecx,0x13
  62:	31 ff                	xor    edi,edi
  64:	44 0f b7 44 0a fd    	movzx  r8d,WORD PTR [rdx+rcx*1-0x3]
  6a:	41 01 f8             	add    r8d,edi
  6d:	41 0f b7 f8          	movzx  edi,r8w
  71:	41 c1 e8 10          	shr    r8d,0x10
  75:	41 01 f8             	add    r8d,edi
  78:	0f b7 7c 0a ff       	movzx  edi,WORD PTR [rdx+rcx*1-0x1]
  7d:	44 01 c7             	add    edi,r8d
  80:	44 0f b7 c7          	movzx  r8d,di
  84:	c1 ef 10             	shr    edi,0x10
  87:	44 01 c7             	add    edi,r8d
  8a:	48 83 c1 04          	add    rcx,0x4
  8e:	48 81 f9 13 04 00 00 	cmp    rcx,0x413
  95:	48 81 f9 13 04 00 00 	cmp    rcx,0x413
  9c:	75 c6                	jne    0x64
  9e:	89 f9                	mov    ecx,edi
  a0:	c1 e9 10             	shr    ecx,0x10
  a3:	01 f9                	add    ecx,edi
  a5:	f7 d1                	not    ecx
  a7:	0f b7 f9             	movzx  edi,cx
  aa:	89 c1                	mov    ecx,eax
  ac:	c1 e1 04             	shl    ecx,0x4
  af:	48 d3 e7             	shl    rdi,cl
  b2:	48 31 fe             	xor    rsi,rdi
  b5:	83 c0 01             	add    eax,0x1
  b8:	81 f8 20 00 00 00    	cmp    eax,0x20
  be:	48 83 f8 20          	cmp    rax,0x20
  c2:	75 99                	jne    0x5d
  c4:	48 89 32             	mov    QWORD PTR [rdx],rsi
  c7:	b8 02 00 00 00       	mov    eax,0x2
  cc:	e9 55 ff ff ff       	jmp    0x26
```
