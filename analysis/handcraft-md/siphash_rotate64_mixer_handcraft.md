# siphash_rotate64_mixer_handcraft

## original c
```c
#include "common.h"

/*
 * siphash_rotate64_mixer: SipHash-like hash using 64-bit rotations.
 *
 * Uses micro_rotl64() exclusively in the hot path so clang emits
 * the clean 4-insn rotate pattern (mov+lsh+rsh+or) without masking.
 * This exercises the ROTATE rewrite's 4-insn variant.
 *
 * Input: 8 u64 words (64 bytes) from the packet payload.
 * Output: 64-bit hash result.
 */

/*
 * SipHash-like round: 4 adds, 4 rotates, 2 xors per round.
 * Uses 64-bit rotations with varying amounts to create multiple
 * distinct rotate sites.
 */
#define SIPROUND(v0, v1, v2, v3)                \
    do {                                        \
        (v0) += (v1);                           \
        (v1) = micro_rotl64((v1), 13U);         \
        (v1) ^= (v0);                           \
        (v0) = micro_rotl64((v0), 32U);         \
        (v2) += (v3);                           \
        (v3) = micro_rotl64((v3), 16U);         \
        (v3) ^= (v2);                           \
        (v0) += (v3);                           \
        (v3) = micro_rotl64((v3), 21U);         \
        (v3) ^= (v0);                           \
        (v2) += (v1);                           \
        (v1) = micro_rotl64((v1), 17U);         \
        (v1) ^= (v2);                           \
        (v2) = micro_rotl64((v2), 32U);         \
    } while (0)

static __always_inline int
bench_siphash_rotate64_mixer(const u8 *data, u32 len, u64 *out)
{
    (void)len;

    u64 v0 = 0x736F6D6570736575ULL;
    u64 v1 = 0x646F72616E646F6DULL;
    u64 v2 = 0x6C7967656E657261ULL;
    u64 v3 = 0x7465646279746573ULL;

    /* Read 8 input words */
    u64 m0 = micro_read_u64_le(data, 0);
    u64 m1 = micro_read_u64_le(data, 8);
    u64 m2 = micro_read_u64_le(data, 16);
    u64 m3 = micro_read_u64_le(data, 24);
    u64 m4 = micro_read_u64_le(data, 32);
    u64 m5 = micro_read_u64_le(data, 40);
    u64 m6 = micro_read_u64_le(data, 48);
    u64 m7 = micro_read_u64_le(data, 56);

    /* Process each word: xor into v3, do 2 rounds, xor into v0 */
    v3 ^= m0;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m0;

    v3 ^= m1;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m1;

    v3 ^= m2;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m2;

    v3 ^= m3;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m3;

    v3 ^= m4;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m4;

    v3 ^= m5;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m5;

    v3 ^= m6;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m6;

    v3 ^= m7;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m7;

    /* Finalization: 4 rounds */
    v2 ^= 0xFF;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);

    *out = v0 ^ v1 ^ v2 ^ v3;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(siphash_rotate64_mixer_xdp, bench_siphash_rotate64_mixer,
                              siphash_rotate64_mixer_input, 64)

```

## native asm
```asm
	.text
	.file	"siphash_rotate64_mixer.bpf.c"
	.file	0 "/home/yunwei37/workspace/bpf-benchmark" "micro/programs/siphash_rotate64_mixer.bpf.c" md5 0xebb1e76d55130105e44b8d3cb79885c5
	.globl	siphash_rotate64_mixer_xdp      # -- Begin function siphash_rotate64_mixer_xdp
	.p2align	4, 0x90
	.type	siphash_rotate64_mixer_xdp,@function
siphash_rotate64_mixer_xdp:             # @siphash_rotate64_mixer_xdp
.Lfunc_begin0:
	.cfi_startproc
# %bb.0:
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:ctx <- $rdi
	.loc	0 109 1 prologue_end            # micro/programs/siphash_rotate64_mixer.bpf.c:109:1
	movq	(%rdi), %rcx
.Ltmp0:
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data <- $rcx
	movq	8(%rdi), %rdx
	xorl	%eax, %eax
.Ltmp1:
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data_end <- $rdx
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 64
	.file	1 "micro/programs" "common.h" md5 0xfe1014cbc13a25f3c6a9e9adc3125304
	.loc	1 127 14                        # micro/programs/common.h:127:14
	cmpq	%rdx, %rcx
.Ltmp2:
	.loc	1 127 9 is_stmt 0               # micro/programs/common.h:127:9
	ja	.LBB0_4
.Ltmp3:
# %bb.1:
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:ctx <- $rdi
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data <- $rcx
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data_end <- $rdx
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 64
	.loc	1 131 24 is_stmt 1              # micro/programs/common.h:131:24
	leaq	8(%rcx), %rsi
.Ltmp4:
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rsi
	.loc	1 132 21                        # micro/programs/common.h:132:21
	cmpq	%rdx, %rsi
.Ltmp5:
	.loc	1 132 9 is_stmt 0               # micro/programs/common.h:132:9
	ja	.LBB0_4
.Ltmp6:
# %bb.2:
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:ctx <- $rdi
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data <- $rcx
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data_end <- $rdx
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 64
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rsi
	.loc	1 0 9                           # micro/programs/common.h:0:9
	leaq	72(%rcx), %rsi
.Ltmp7:
	.loc	1 132 9                         # micro/programs/common.h:132:9
	cmpq	%rdx, %rsi
	ja	.LBB0_4
.Ltmp8:
# %bb.3:
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:ctx <- $rdi
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data <- $rcx
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:data_end <- $rdx
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:result <- 0
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	.loc	1 72 15 is_stmt 1               # micro/programs/common.h:72:15
	movq	8(%rcx), %r9
.Ltmp9:
	#DEBUG_VALUE: micro_read_u64_le:value <- $r9
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	#DEBUG_VALUE: i <- 1
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 3
	#DEBUG_VALUE: i <- 4
	#DEBUG_VALUE: i <- 5
	#DEBUG_VALUE: i <- 6
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	.loc	1 0 15 is_stmt 0                # micro/programs/common.h:0:15
	movabsq	$8387220255154660723, %rdi      # imm = 0x7465646279746573
.Ltmp10:
	#DEBUG_VALUE: siphash_rotate64_mixer_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:m7 <- undef
	.loc	0 58 8 is_stmt 1                # micro/programs/siphash_rotate64_mixer.bpf.c:58:8
	xorq	%r9, %rdi
.Ltmp11:
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v3 <- $rdi
	.loc	0 0 8 is_stmt 0                 # micro/programs/siphash_rotate64_mixer.bpf.c:0:8
	movabsq	$7816392313619706465, %rdx      # imm = 0x6C7967656E657261
.Ltmp12:
	#DEBUG_VALUE: micro_rotl64:value <- 7237128888997146477
	#DEBUG_VALUE: micro_rotl64:shift <- 13
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v1 <- 4148644332921583727
	#DEBUG_VALUE: micro_rotl64:value <- -2891627865490074398
	#DEBUG_VALUE: micro_rotl64:shift <- 32
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v0 <- -2389207006547353658
	.loc	0 59 5 is_stmt 1                # micro/programs/siphash_rotate64_mixer.bpf.c:59:5
	addq	%rdi, %rdx
.Ltmp13:
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v2 <- $rdx
	#DEBUG_VALUE: micro_rotl64:value <- $rdi
	#DEBUG_VALUE: micro_rotl64:shift <- 16
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v3 <- undef
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v3 <- undef
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v0 <- undef
	#DEBUG_VALUE: micro_rotl64:value <- undef
	#DEBUG_VALUE: micro_rotl64:shift <- 21
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v3 <- undef
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v3 <- undef
	.loc	0 0 5 is_stmt 0                 # micro/programs/siphash_rotate64_mixer.bpf.c:0:5
	movabsq	$-6481707427168261424, %rax     # imm = 0xA60C596FC19FEAD0
	.loc	0 59 5                          # micro/programs/siphash_rotate64_mixer.bpf.c:59:5
	addq	%rdi, %rax
.Ltmp14:
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v2 <- $rax
	.loc	1 104 9 is_stmt 1               # micro/programs/common.h:104:9
	rolq	$16, %rdi
.Ltmp15:
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v3 <- $rdi
	.loc	0 59 5                          # micro/programs/siphash_rotate64_mixer.bpf.c:59:5
	xorq	%rdx, %rdi
.Ltmp16:
	#DEBUG_VALUE: micro_rotl64:value <- $rdi
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v3 <- $rdi
	.loc	0 0 5 is_stmt 0                 # micro/programs/siphash_rotate64_mixer.bpf.c:0:5
	movabsq	$-2389207006547353658, %r8      # imm = 0xDED7D4E2D7DEDFC6
	.loc	0 59 5                          # micro/programs/siphash_rotate64_mixer.bpf.c:59:5
	addq	%rdi, %r8
.Ltmp17:
	#DEBUG_VALUE: bench_siphash_rotate64_mixer:v0 <- $r8

```

## handcraft kinsn c
```c
#include "handcraft_common.h"

static const struct bpf_insn program[] = {
    HC_XDP_PREFIX(64, 16),
    HC_LDX(BPF_DW, BPF_REG_0, BPF_REG_6, 0),
    HC_LDX(BPF_DW, BPF_REG_1, BPF_REG_6, 8),
    HC_ALU64_REG(BPF_XOR, BPF_REG_0, BPF_REG_1),
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 13, BPF_REG_5),
             MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    HC_LDX(BPF_DW, BPF_REG_2, BPF_REG_6, 16),
    HC_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_2),
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 17, BPF_REG_5),
             MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    HC_LDX(BPF_DW, BPF_REG_3, BPF_REG_6, 24),
    HC_ALU64_REG(BPF_XOR, BPF_REG_0, BPF_REG_3),
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_0, 32, BPF_REG_5),
             MICRO_HANDCRAFT_BPF_X86_ROLQ_IMM),
    HC_XDP_SUFFIX(),
};

HC_EXPORT_PROGRAM(program)

```

## handcraft kernel x86 disasm
```asm

micro/results/x86_kvm_micro_20260515_024526_991973/details/jit_dumps/siphash_rotate64_mixer_handcraft__kernel__sample00.jited.bin:     file format binary


Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
   5:	0f 1f 00             	nopl   (%rax)
   8:	55                   	push   %rbp
   9:	48 89 e5             	mov    %rsp,%rbp
   c:	53                   	push   %rbx
   d:	41 55                	push   %r13
   f:	48 8b 5f 00          	mov    0x0(%rdi),%rbx
  13:	4c 8b 6f 08          	mov    0x8(%rdi),%r13
  17:	48 83 c3 08          	add    $0x8,%rbx
  1b:	48 89 de             	mov    %rbx,%rsi
  1e:	48 83 c6 40          	add    $0x40,%rsi
  22:	49 39 f5             	cmp    %rsi,%r13
  25:	73 07                	jae    0x2e
  27:	31 c0                	xor    %eax,%eax
  29:	41 5d                	pop    %r13
  2b:	5b                   	pop    %rbx
  2c:	c9                   	leave
  2d:	c3                   	ret
  2e:	48 8b 43 00          	mov    0x0(%rbx),%rax
  32:	48 8b 7b 08          	mov    0x8(%rbx),%rdi
  36:	48 31 f8             	xor    %rdi,%rax
  39:	c4 e3 7b f0 c0 13    	rorx   $0x13,%eax,%eax
  3f:	48 8b 73 10          	mov    0x10(%rbx),%rsi
  43:	48 01 f0             	add    %rsi,%rax
  46:	c4 e3 7b f0 c0 0f    	rorx   $0xf,%eax,%eax
  4c:	48 8b 53 18          	mov    0x18(%rbx),%rdx
  50:	48 31 d0             	xor    %rdx,%rax
  53:	c4 e3 7b f0 c0 00    	rorx   $0x0,%eax,%eax
  59:	48 89 43 f8          	mov    %rax,-0x8(%rbx)
  5d:	b8 02 00 00 00       	mov    $0x2,%eax
  62:	eb c5                	jmp    0x29

```
