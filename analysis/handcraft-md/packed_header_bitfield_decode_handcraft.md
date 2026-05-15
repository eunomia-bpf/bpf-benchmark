# packed_header_bitfield_decode_handcraft

## original c
```c
#include "common.h"

#define BITFIELD_EXTRACT_RECORDS 32U
#define BITFIELD_EXTRACT_RECORD_WORDS 2U
#define BITFIELD_EXTRACT_HEADER_SIZE 8U
#define BITFIELD_EXTRACT_RECORD_SIZE 16U
#define BITFIELD_EXTRACT_INPUT_SIZE \
    (BITFIELD_EXTRACT_HEADER_SIZE + BITFIELD_EXTRACT_RECORDS * BITFIELD_EXTRACT_RECORD_SIZE)

static __always_inline int
bench_packed_header_bitfield_decode(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BITFIELD_EXTRACT_HEADER_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0);
    u32 record_words = micro_read_u32_le(data, 4);
    if (record_count != BITFIELD_EXTRACT_RECORDS ||
        record_words != BITFIELD_EXTRACT_RECORD_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, BITFIELD_EXTRACT_HEADER_SIZE,
                         record_count * BITFIELD_EXTRACT_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 index = 0; index < BITFIELD_EXTRACT_RECORDS; index++) {
        u32 base = BITFIELD_EXTRACT_HEADER_SIZE + index * BITFIELD_EXTRACT_RECORD_SIZE;
        u64 word0 = micro_read_u64_le(data, base);
        u64 word1 = micro_read_u64_le(data, base + 8U);
        u32 lane0 = (u32)word0;
        u32 lane1 = (u32)(word1 >> 32U);

        u64 field0 = (word0 >> 0U) & 0x3FULL;
        u64 field1 = (word0 >> 6U) & 0x1FULL;
        u64 field2 = (word0 >> 11U) & 0x7FFULL;
        u64 field3 = (word0 >> 22U) & 0xFFULL;
        u64 field4 = (word0 >> 30U) & 0x3FFFULL;
        u64 field5 = (word0 >> 44U) & 0x3FFULL;
        u64 field6 = (word0 >> 54U) & 0x3FFULL;

        u64 field7 = (word1 >> 0U) & 0xFULL;
        u64 field8 = (word1 >> 4U) & 0xFFULL;
        u64 field9 = (word1 >> 12U) & 0xFFFULL;
        u64 field10 = (word1 >> 24U) & 0xFFFFULL;
        u64 field11 = (word1 >> 40U) & 0xFFFFFFULL;
        u64 field12 = (lane0 >> 9U) & 0x1FULL;
        u64 field13 = (lane1 >> 6U) & 0x7FULL;

        u64 sum0 = field0 + field1 + field2 + field3 + field4 + field5 + field6;
        u64 sum1 = field7 + field8 + field9 + field10 + field11 + field12 +
                   field13 + (u64)index;
        u64 mix0 = (field2 * 3U) ^ (field4 * 5U) ^ (field8 * 7U);
        u64 mix1 = (field6 * 11U) ^ (field10 * 13U) ^ (field11 * 9U) ^
                   (field12 * 17U) ^ (field13 * 19U);

        acc += sum0 ^ micro_rotl64(sum1, (field0 & 7U) + 1U);
        acc ^= mix0 + mix1;
        acc = micro_rotl64(acc + field4 + field11 + field12,
                           ((field6 ^ field11) & 15U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    packed_header_bitfield_decode_xdp,
    bench_packed_header_bitfield_decode,
    packed_header_bitfield_decode_input_value,
    BITFIELD_EXTRACT_INPUT_SIZE)

```

## native asm
```asm
	.text
	.file	"packed_header_bitfield_decode.bpf.c"
	.file	0 "/home/yunwei37/workspace/bpf-benchmark" "micro/programs/packed_header_bitfield_decode.bpf.c" md5 0xefcee0501163a23d9e1222486aad04ba
	.globl	packed_header_bitfield_decode_xdp # -- Begin function packed_header_bitfield_decode_xdp
	.p2align	4, 0x90
	.type	packed_header_bitfield_decode_xdp,@function
packed_header_bitfield_decode_xdp:      # @packed_header_bitfield_decode_xdp
.Lfunc_begin0:
	.cfi_startproc
# %bb.0:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- $rdi
	.loc	0 69 1 prologue_end             # micro/programs/packed_header_bitfield_decode.bpf.c:69:1
	movq	(%rdi), %rsi
.Ltmp0:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- $rsi
	movq	8(%rdi), %rcx
	xorl	%eax, %eax
.Ltmp1:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data_end <- $rcx
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rsi
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 520
	.file	1 "micro/programs" "common.h" md5 0xfe1014cbc13a25f3c6a9e9adc3125304
	.loc	1 127 14                        # micro/programs/common.h:127:14
	cmpq	%rcx, %rsi
.Ltmp2:
	.loc	1 127 9 is_stmt 0               # micro/programs/common.h:127:9
	jbe	.LBB0_1
.Ltmp3:
.LBB0_8:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- $rdi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- $rsi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data_end <- $rcx
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	.loc	0 69 1 is_stmt 1                # micro/programs/packed_header_bitfield_decode.bpf.c:69:1
	retq
.Ltmp4:
.LBB0_1:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- $rdi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- $rsi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data_end <- $rcx
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rsi
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 520
	.loc	1 131 24                        # micro/programs/common.h:131:24
	leaq	8(%rsi), %rdx
.Ltmp5:
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rdx
	.loc	1 132 21                        # micro/programs/common.h:132:21
	cmpq	%rcx, %rdx
.Ltmp6:
	.loc	1 132 9 is_stmt 0               # micro/programs/common.h:132:9
	ja	.LBB0_8
.Ltmp7:
# %bb.2:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- $rdi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- $rsi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data_end <- $rcx
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rsi
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 520
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rdx
	.loc	1 0 9                           # micro/programs/common.h:0:9
	leaq	528(%rsi), %rdx
.Ltmp8:
	.loc	1 132 9                         # micro/programs/common.h:132:9
	cmpq	%rcx, %rdx
	ja	.LBB0_8
.Ltmp9:
# %bb.3:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- $rdi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- $rsi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data_end <- $rcx
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload_len <- 520
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:len <- 520
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:out <- undef
	#DEBUG_VALUE: micro_read_u32_le:offset <- 0
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:record_count <- undef
	#DEBUG_VALUE: micro_read_u32_le:offset <- 4
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:record_words <- undef
	.loc	0 19 22 is_stmt 1               # micro/programs/packed_header_bitfield_decode.bpf.c:19:22
	cmpl	$32, 8(%rsi)
.Ltmp10:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	.loc	0 19 50 is_stmt 0               # micro/programs/packed_header_bitfield_decode.bpf.c:19:50
	jne	.LBB0_8
.Ltmp11:
# %bb.4:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- $rdi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- $rsi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data_end <- $rcx
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload_len <- 520
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:len <- 520
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	cmpl	$2, 12(%rsi)
	jne	.LBB0_8
.Ltmp12:
# %bb.5:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- $rdi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- $rsi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data_end <- $rcx
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload_len <- 520
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:len <- 520
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r15
	.cfi_def_cfa_offset 24
	pushq	%r14
	.cfi_def_cfa_offset 32
	pushq	%r13
	.cfi_def_cfa_offset 40
	pushq	%r12
	.cfi_def_cfa_offset 48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	.cfi_offset %rbp, -16
	movq	%rsi, -16(%rsp)                 # 8-byte Spill
.Ltmp13:
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:data <- [DW_OP_constu 16, DW_OP_minus, DW_OP_deref, DW_OP_plus_uconst 8, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload <- [DW_OP_constu 16, DW_OP_minus, DW_OP_deref, DW_OP_plus_uconst 8, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- [DW_OP_constu 16, DW_OP_minus, DW_OP_deref] $rsp
	.loc	0 29 5 is_stmt 1                # micro/programs/packed_header_bitfield_decode.bpf.c:29:5
	leaq	31(%rsi), %rdi
.Ltmp14:
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	.loc	0 0 5 is_stmt 0                 # micro/programs/packed_header_bitfield_decode.bpf.c:0:5
	movabsq	$7640891576956012809, %rbx      # imm = 0x6A09E667F3BCC909
	xorl	%eax, %eax
	movq	%rax, -24(%rsp)                 # 8-byte Spill
.Ltmp15:
	.p2align	4, 0x90
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:data <- [DW_OP_constu 16, DW_OP_minus, DW_OP_deref] $rsp
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:result <- 0
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload_len <- 520
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:len <- 520
	#DEBUG_VALUE: packed_header_bitfield_decode_xdp:payload <- [DW_OP_constu 16, DW_OP_minus, DW_OP_deref, DW_OP_plus_uconst 8, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:data <- [DW_OP_constu 16, DW_OP_minus, DW_OP_deref, DW_OP_plus_uconst 8, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:acc <- $rbx
	#DEBUG_VALUE: index <- [DW_OP_constu 24, DW_OP_minus, DW_OP_deref_size 8, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: base <- [DW_OP_constu 24, DW_OP_minus, DW_OP_deref_size 8, DW_OP_constu 4, DW_OP_shl, DW_OP_constu 8, DW_OP_or, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: micro_read_u64_le:offset <- [DW_OP_constu 24, DW_OP_minus, DW_OP_deref_size 8, DW_OP_constu 4, DW_OP_shl, DW_OP_constu 8, DW_OP_or, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	movq	%rbx, -8(%rsp)                  # 8-byte Spill
.Ltmp16:
	#DEBUG_VALUE: bench_packed_header_bitfield_decode:acc <- [DW_OP_constu 8, DW_OP_minus, DW_OP_deref] $rsp
	.loc	0 59 42 is_stmt 1               # micro/programs/packed_header_bitfield_decode.bpf.c:59:42
	movzbl	-15(%rdi), %ebx
.Ltmp17:
	#DEBUG_VALUE: i <- 1
	.loc	1 72 24                         # micro/programs/common.h:72:24
	movzbl	-14(%rdi), %r9d
	.loc	1 72 42 is_stmt 0               # micro/programs/common.h:72:42
	movl	%r9d, %r13d
	shll	$8, %r13d
.Ltmp18:
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	.loc	1 72 24                         # micro/programs/common.h:72:24
	movzbl	-13(%rdi), %eax
	.loc	1 72 42                         # micro/programs/common.h:72:42
	shll	$16, %eax
.Ltmp19:
	#DEBUG_VALUE: i <- 3
	movzbl	-12(%rdi), %r12d
	shll	$24, %r12d
.Ltmp20:
	#DEBUG_VALUE: i <- 4
	.loc	1 72 15                         # micro/programs/common.h:72:15
	orl	%eax, %r12d
	.loc	1 72 24                         # micro/programs/common.h:72:24
	movzbl	-11(%rdi), %r10d
	.loc	1 72 42                         # micro/programs/common.h:72:42
	shlq	$32, %r10
.Ltmp21:
	#DEBUG_VALUE: i <- 5
	.loc	1 72 24                         # micro/programs/common.h:72:24
	movzbl	-10(%rdi), %ebp
	.loc	1 72 42                         # micro/programs/common.h:72:42
	shlq	$40, %rbp
.Ltmp22:
	#DEBUG_VALUE: i <- 6
	.loc	1 72 24                         # micro/programs/common.h:72:24
	movzbl	-9(%rdi), %r11d
	.loc	1 72 42                         # micro/programs/common.h:72:42
	shlq	$48, %r11
.Ltmp23:
	#DEBUG_VALUE: i <- 7
	#DEBUG_VALUE: micro_read_u64_le:data <- [DW_OP_constu 16, DW_OP_minus, DW_OP_deref, DW_OP_plus_uconst 8, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: micro_read_u64_le:offset <- [DW_OP_constu 24, DW_OP_minus, DW_OP_deref_size 8, DW_OP_constu 4, DW_OP_shl, DW_OP_plus_uconst 16, DW_OP_stack_value] $rsp
	#DEBUG_VALUE: i <- 0
	#DEBUG_VALUE: micro_read_u64_le:value <- 0
	.loc	1 72 42                         # micro/programs/common.h:72:42
	movzbl	-4(%rdi), %eax
	shll	$24, %eax
.Ltmp24:
	#DEBUG_VALUE: field9 <- [DW_OP_constu 12, DW_OP_shr, DW_OP_constu 4095, DW_OP_and, DW_OP_stack_value] $eax
	#DEBUG_VALUE: micro_read_u64_le:value <- undef
	#DEBUG_VALUE: word1 <- undef
	#DEBUG_VALUE: lane1 <- undef
	#DEBUG_VALUE: i <- 4
	.loc	1 72 24                         # micro/programs/common.h:72:24
	movzbl	-3(%rdi), %r15d

```

## handcraft kinsn c
```c
#include "handcraft_common.h"

static const struct bpf_insn program[] = {
    HC_XDP_PREFIX(520, 15),
    HC_LDX(BPF_DW, BPF_REG_1, BPF_REG_6, 8),
    HC_MOV64_REG(BPF_REG_0, BPF_REG_1),
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 11), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_0, 0x7ff), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    HC_MOV64_REG(BPF_REG_2, BPF_REG_1),
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 30), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 0x3fff), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    HC_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_2),
    HC_XDP_SUFFIX(),
};

HC_EXPORT_PROGRAM(program)

```

## handcraft kernel x86 disasm
```asm

micro/results/x86_kvm_micro_20260515_024805_706825/details/jit_dumps/packed_header_bitfield_decode_handcraft__kernel__sample00.jited.bin:     file format binary


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
  1e:	48 81 c6 08 02 00 00 	add    $0x208,%rsi
  25:	49 39 f5             	cmp    %rsi,%r13
  28:	73 07                	jae    0x31
  2a:	31 c0                	xor    %eax,%eax
  2c:	41 5d                	pop    %r13
  2e:	5b                   	pop    %rbx
  2f:	c9                   	leave
  30:	c3                   	ret
  31:	48 8b 7b 08          	mov    0x8(%rbx),%rdi
  35:	48 89 f8             	mov    %rdi,%rax
  38:	48 c1 e8 0b          	shr    $0xb,%rax
  3c:	81 e0 ff 07 00 00    	and    $0x7ff,%eax
  42:	48 89 fe             	mov    %rdi,%rsi
  45:	48 c1 ee 1e          	shr    $0x1e,%rsi
  49:	81 e6 ff 3f 00 00    	and    $0x3fff,%esi
  4f:	48 01 f0             	add    %rsi,%rax
  52:	48 89 43 f8          	mov    %rax,-0x8(%rbx)
  56:	b8 02 00 00 00       	mov    $0x2,%eax
  5b:	eb cf                	jmp    0x2c

```
