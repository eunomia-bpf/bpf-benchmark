# packet_toeplitz_rss_hash_handcraft

## original c
```c
#include "common.h"

#define PACKET_TOEPLITZ_RSS_INPUT_SIZE 54U
#define PACKET_TOEPLITZ_TUPLE_BITS 104U

static __always_inline u8 packet_toeplitz_key_byte(u32 index)
{
    switch (index) {
    case 0U: return 0x6DU;
    case 1U: return 0x5AU;
    case 2U: return 0x56U;
    case 3U: return 0xDAU;
    case 4U: return 0x25U;
    case 5U: return 0x5BU;
    case 6U: return 0x0EU;
    case 7U: return 0xC2U;
    case 8U: return 0x41U;
    case 9U: return 0x67U;
    case 10U: return 0x25U;
    case 11U: return 0x3DU;
    case 12U: return 0x43U;
    case 13U: return 0xA3U;
    case 14U: return 0x8FU;
    case 15U: return 0xB0U;
    case 16U: return 0xD0U;
    default: return 0U;
    }
}

static __always_inline u32 packet_toeplitz_word(u32 bit)
{
    u32 byte = bit >> 3U;
    u32 shift = bit & 7U;
    u32 word = ((u32)packet_toeplitz_key_byte(byte) << 24U) |
               ((u32)packet_toeplitz_key_byte(byte + 1U) << 16U) |
               ((u32)packet_toeplitz_key_byte(byte + 2U) << 8U) |
               (u32)packet_toeplitz_key_byte(byte + 3U);

    if (shift != 0U) {
        word = (word << shift) |
               ((u32)packet_toeplitz_key_byte(byte + 4U) >> (8U - shift));
    }
    return word;
}

static __always_inline u8
packet_toeplitz_tuple_byte(const u8 *data, u32 ip, u32 tcp, u32 index)
{
    if (index < 4U) {
        return data[ip + 12U + index];
    }
    if (index < 8U) {
        return data[ip + 16U + (index - 4U)];
    }
    if (index < 10U) {
        return data[tcp + (index - 8U)];
    }
    if (index < 12U) {
        return data[tcp + 2U + (index - 10U)];
    }
    return data[ip + 9U];
}

static __always_inline int
bench_packet_toeplitz_rss_hash(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, PACKET_TOEPLITZ_RSS_INPUT_SIZE)) {
        return -1;
    }
    if (micro_read_u16_be(data, 12U) != 0x0800U) {
        return -1;
    }

    u32 ip = 14U;
    u8 ihl = (data[ip] & 0x0FU) * 4U;
    if (ihl != 20U || data[ip + 9U] != 6U) {
        return -1;
    }
    u32 tcp = ip + ihl;
    if (!micro_has_bytes(len, tcp, 20U)) {
        return -1;
    }

    u32 hash = 0U;
    for (u32 bit = 0; bit < PACKET_TOEPLITZ_TUPLE_BITS; bit++) {
        u8 tuple = packet_toeplitz_tuple_byte(data, ip, tcp, bit >> 3U);
        if ((tuple & (0x80U >> (bit & 7U))) != 0U) {
            hash ^= packet_toeplitz_word(bit);
        }
    }

    u32 src = micro_read_u32_be(data, ip + 12U);
    u32 dst = micro_read_u32_be(data, ip + 16U);
    u16 sport = micro_read_u16_be(data, tcp);
    u16 dport = micro_read_u16_be(data, tcp + 2U);
    u64 acc = ((u64)hash << 32U) | (hash ^ src ^ dst);
    acc ^= micro_rotl64(((u64)sport << 48U) | ((u64)dport << 32U) |
                            ((u64)src ^ dst),
                        (hash & 7U) + 1U);

    *out = acc;
    return 0;
}

DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(
    packet_toeplitz_rss_hash_xdp,
    bench_packet_toeplitz_rss_hash,
    PACKET_TOEPLITZ_RSS_INPUT_SIZE)

```

## native asm
```asm
	.text
	.file	"packet_toeplitz_rss_hash.bpf.c"
	.file	0 "/home/yunwei37/workspace/bpf-benchmark" "micro/programs/packet_toeplitz_rss_hash.bpf.c" md5 0x19854a4e23e8714342a15e8da2a1fe6f
	.globl	packet_toeplitz_rss_hash_xdp    # -- Begin function packet_toeplitz_rss_hash_xdp
	.p2align	4, 0x90
	.type	packet_toeplitz_rss_hash_xdp,@function
packet_toeplitz_rss_hash_xdp:           # @packet_toeplitz_rss_hash_xdp
.Lfunc_begin0:
	.cfi_startproc
# %bb.0:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	.loc	0 105 1 prologue_end            # micro/programs/packet_toeplitz_rss_hash.bpf.c:105:1
	movq	(%rdi), %rsi
.Ltmp0:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	movq	8(%rdi), %rcx
	xorl	%eax, %eax
.Ltmp1:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data_end <- $rcx
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rsi
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 54
	.file	1 "micro/programs" "common.h" md5 0xfe1014cbc13a25f3c6a9e9adc3125304
	.loc	1 127 14                        # micro/programs/common.h:127:14
	cmpq	%rcx, %rsi
.Ltmp2:
	.loc	1 127 9 is_stmt 0               # micro/programs/common.h:127:9
	jbe	.LBB0_1
.Ltmp3:
.LBB0_18:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	.loc	0 105 1 is_stmt 1               # micro/programs/packet_toeplitz_rss_hash.bpf.c:105:1
	retq
.Ltmp4:
.LBB0_1:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data_end <- $rcx
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rsi
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 54
	.loc	1 131 24                        # micro/programs/common.h:131:24
	leaq	8(%rsi), %rdx
.Ltmp5:
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rdx
	.loc	1 132 21                        # micro/programs/common.h:132:21
	cmpq	%rcx, %rdx
.Ltmp6:
	.loc	1 132 9 is_stmt 0               # micro/programs/common.h:132:9
	ja	.LBB0_18
.Ltmp7:
# %bb.2:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data_end <- $rcx
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rsi
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 54
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rdx
	.loc	1 0 9                           # micro/programs/common.h:0:9
	leaq	62(%rsi), %rdx
.Ltmp8:
	.loc	1 132 9                         # micro/programs/common.h:132:9
	cmpq	%rcx, %rdx
	ja	.LBB0_18
.Ltmp9:
# %bb.3:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data_end <- $rcx
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload_len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:out <- undef
	#DEBUG_VALUE: micro_read_u16_be:offset <- 12
	.loc	1 79 43 is_stmt 1               # micro/programs/common.h:79:43
	movzwl	20(%rsi), %ecx
.Ltmp10:
	rolw	$8, %cx
.Ltmp11:
	.loc	0 70 38                         # micro/programs/packet_toeplitz_rss_hash.bpf.c:70:38
	movzwl	%cx, %ecx
	cmpl	$2048, %ecx                     # imm = 0x800
.Ltmp12:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: micro_read_u16_be:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	.loc	0 70 9 is_stmt 0                # micro/programs/packet_toeplitz_rss_hash.bpf.c:70:9
	jne	.LBB0_18
.Ltmp13:
# %bb.4:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload_len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:len <- 54
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:ip <- 14
	.loc	0 75 15 is_stmt 1               # micro/programs/packet_toeplitz_rss_hash.bpf.c:75:15
	movzbl	22(%rsi), %ecx
.Ltmp14:
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:ihl <- [DW_OP_constu 2, DW_OP_shl, DW_OP_constu 60, DW_OP_and, DW_OP_stack_value] $cl
	.loc	0 76 13                         # micro/programs/packet_toeplitz_rss_hash.bpf.c:76:13
	andb	$15, %cl
.Ltmp15:
	cmpb	$5, %cl
	.loc	0 76 20 is_stmt 0               # micro/programs/packet_toeplitz_rss_hash.bpf.c:76:20
	jne	.LBB0_18
.Ltmp16:
# %bb.5:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload_len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:len <- 54
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:ip <- 14
	.loc	0 76 37                         # micro/programs/packet_toeplitz_rss_hash.bpf.c:76:37
	cmpb	$6, 31(%rsi)
.Ltmp17:
	.loc	0 76 9                          # micro/programs/packet_toeplitz_rss_hash.bpf.c:76:9
	jne	.LBB0_18
.Ltmp18:
# %bb.6:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload_len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:len <- 54
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:ip <- 14
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%r14
	.cfi_def_cfa_offset 24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -32
	.cfi_offset %r14, -24
	.cfi_offset %rbp, -16
	.loc	0 0 0                           # micro/programs/packet_toeplitz_rss_hash.bpf.c:0:0
	leaq	31(%rsi), %rdi
.Ltmp19:
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	.loc	0 85 5 is_stmt 1                # micro/programs/packet_toeplitz_rss_hash.bpf.c:85:5
	leaq	34(%rsi), %r8
	xorl	%eax, %eax
.Ltmp20:
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:hash <- 0
	#DEBUG_VALUE: bit <- 0
	.loc	0 0 5 is_stmt 0                 # micro/programs/packet_toeplitz_rss_hash.bpf.c:0:5
	leaq	.Lswitch.table.packet_toeplitz_rss_hash_xdp(%rip), %r9
	leaq	.Lswitch.table.packet_toeplitz_rss_hash_xdp.1(%rip), %r10
	leaq	.Lswitch.table.packet_toeplitz_rss_hash_xdp.2(%rip), %r11
	xorl	%ebx, %ebx
	jmp	.LBB0_7
.Ltmp21:
	.p2align	4, 0x90
.LBB0_15:                               #   in Loop: Header=BB0_7 Depth=1
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload_len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:len <- 54
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:ip <- 14
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:hash <- $eax
	#DEBUG_VALUE: bit <- $ebx
	#DEBUG_VALUE: packet_toeplitz_word:bit <- $ebx
	#DEBUG_VALUE: packet_toeplitz_word:word <- $ebp
	#DEBUG_VALUE: packet_toeplitz_word:word <- $ebp
	.loc	0 88 18 is_stmt 1               # micro/programs/packet_toeplitz_rss_hash.bpf.c:88:18
	xorl	%ebp, %eax
.Ltmp22:
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:hash <- $eax
.LBB0_16:                               #   in Loop: Header=BB0_7 Depth=1
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload_len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:len <- 54
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:ip <- 14
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:hash <- $eax
	#DEBUG_VALUE: bit <- $ebx
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:hash <- $eax
	.loc	0 85 60                         # micro/programs/packet_toeplitz_rss_hash.bpf.c:85:60
	incl	%ebx
.Ltmp23:
	#DEBUG_VALUE: bit <- $ebx
	.loc	0 85 27 is_stmt 0               # micro/programs/packet_toeplitz_rss_hash.bpf.c:85:27
	cmpl	$104, %ebx
.Ltmp24:
	.loc	0 85 5                          # micro/programs/packet_toeplitz_rss_hash.bpf.c:85:5
	je	.LBB0_17
.Ltmp25:
.LBB0_7:                                # =>This Inner Loop Header: Depth=1
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:data <- $rsi
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:result <- 0
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload_len <- 54
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:len <- 54
	#DEBUG_VALUE: packet_toeplitz_rss_hash_xdp:payload <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:data <- [DW_OP_plus_uconst 8, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:ip <- 14
	#DEBUG_VALUE: bench_packet_toeplitz_rss_hash:hash <- $eax
	#DEBUG_VALUE: bit <- $ebx
	.loc	0 86 66 is_stmt 1               # micro/programs/packet_toeplitz_rss_hash.bpf.c:86:66
	movl	%ebx, %edx
	shrl	$3, %edx

```

## handcraft kinsn c
```c
#include "handcraft_common.h"

static const struct bpf_insn program[] = {
    HC_XDP_PREFIX(54, 12),
    HC_MOV64_IMM(BPF_REG_9, 0),
    HC_KINSN(HC_MOVBE_SIB_PAYLOAD(BPF_REG_0, BPF_REG_6, BPF_REG_9, 0, 26, BPF_REG_5),
             MICRO_HANDCRAFT_BPF_X86_MOVBE32_SIB),
    HC_KINSN(HC_MOVBE_SIB_PAYLOAD(BPF_REG_1, BPF_REG_6, BPF_REG_9, 0, 30, BPF_REG_5),
             MICRO_HANDCRAFT_BPF_X86_MOVBE32_SIB),
    HC_ALU64_REG(BPF_XOR, BPF_REG_0, BPF_REG_1),
    HC_KINSN(HC_MOVBE_SIB_PAYLOAD(BPF_REG_2, BPF_REG_6, BPF_REG_9, 0, 34, BPF_REG_5),
             MICRO_HANDCRAFT_BPF_X86_MOVBE32_SIB),
    HC_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_2),
    HC_XDP_SUFFIX(),
};

HC_EXPORT_PROGRAM(program)

```

## handcraft kernel x86 disasm
```asm
not captured

```
