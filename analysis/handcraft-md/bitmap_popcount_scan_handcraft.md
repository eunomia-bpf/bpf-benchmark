# bitmap_popcount_scan_handcraft

## original c
```c
#include "common.h"

#define BITCOUNT_MAX_COUNT 256U
#define BITCOUNT_INPUT_SIZE (8U + BITCOUNT_MAX_COUNT * 8U)

static __always_inline u64 micro_popcount64(u64 value)
{
    u64 count = 0;
    for (u32 bit = 0; bit < 64 && value != 0; bit++) {
        value &= value - 1;
        count++;
    }
    return count;
}

static __always_inline int bench_bitmap_popcount_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);

    if (count != BITCOUNT_MAX_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, BITCOUNT_MAX_COUNT * 8U)) {
        return -1;
    }

    u64 acc = seed;
    for (u32 i = 0; i < BITCOUNT_MAX_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8);
        acc += micro_popcount64(value ^ acc);
        acc ^= value >> (i & 7);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(bitmap_popcount_scan_xdp, bench_bitmap_popcount_scan, bitmap_popcount_scan_input_value, BITCOUNT_INPUT_SIZE)

```

## native asm
```asm
	.text
	.file	"bitmap_popcount_scan.bpf.c"
	.file	0 "/home/yunwei37/workspace/bpf-benchmark" "micro/programs/bitmap_popcount_scan.bpf.c" md5 0x3d08b1718f402835bb54aac821e1791c
	.globl	bitmap_popcount_scan_xdp        # -- Begin function bitmap_popcount_scan_xdp
	.p2align	4, 0x90
	.type	bitmap_popcount_scan_xdp,@function
bitmap_popcount_scan_xdp:               # @bitmap_popcount_scan_xdp
.Lfunc_begin0:
	.cfi_startproc
# %bb.0:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- $rdi
	.loc	0 43 1 prologue_end             # micro/programs/bitmap_popcount_scan.bpf.c:43:1
	movq	(%rdi), %rdx
.Ltmp0:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	movq	8(%rdi), %rcx
	xorl	%eax, %eax
.Ltmp1:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data_end <- $rcx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 2056
	.file	1 "micro/programs" "common.h" md5 0xfe1014cbc13a25f3c6a9e9adc3125304
	.loc	1 127 14                        # micro/programs/common.h:127:14
	cmpq	%rcx, %rdx
.Ltmp2:
	.loc	1 127 9 is_stmt 0               # micro/programs/common.h:127:9
	jbe	.LBB0_1
.Ltmp3:
.LBB0_10:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data_end <- $rcx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	.loc	0 43 1 is_stmt 1                # micro/programs/bitmap_popcount_scan.bpf.c:43:1
	retq
.Ltmp4:
.LBB0_1:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data_end <- $rcx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 2056
	.loc	1 131 24                        # micro/programs/common.h:131:24
	leaq	8(%rdx), %rsi
.Ltmp5:
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rsi
	.loc	1 132 21                        # micro/programs/common.h:132:21
	cmpq	%rcx, %rsi
.Ltmp6:
	.loc	1 132 9 is_stmt 0               # micro/programs/common.h:132:9
	ja	.LBB0_10
.Ltmp7:
# %bb.2:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data_end <- $rcx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 2056
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rsi
	.loc	1 0 9                           # micro/programs/common.h:0:9
	leaq	2064(%rdx), %rdi
.Ltmp8:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	.loc	1 132 9                         # micro/programs/common.h:132:9
	cmpq	%rcx, %rdi
	ja	.LBB0_10
.Ltmp9:
# %bb.3:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data_end <- $rcx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:payload_len <- 2056
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:payload <- $rsi
	#DEBUG_VALUE: bench_bitmap_popcount_scan:data <- $rsi
	#DEBUG_VALUE: bench_bitmap_popcount_scan:len <- 2056
	#DEBUG_VALUE: bench_bitmap_popcount_scan:out <- undef
	#DEBUG_VALUE: micro_read_u32_le:offset <- 0
	#DEBUG_VALUE: bench_bitmap_popcount_scan:count <- undef
	#DEBUG_VALUE: micro_read_u32_le:data <- $rsi
	#DEBUG_VALUE: micro_read_u32_le:offset <- 4
	#DEBUG_VALUE: bench_bitmap_popcount_scan:seed <- undef
	.loc	0 25 15 is_stmt 1               # micro/programs/bitmap_popcount_scan.bpf.c:25:15
	cmpl	$256, (%rsi)                    # imm = 0x100
.Ltmp10:
	.loc	0 25 9 is_stmt 0                # micro/programs/bitmap_popcount_scan.bpf.c:25:9
	jne	.LBB0_10
.Ltmp11:
# %bb.4:
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data_end <- $rcx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:payload_len <- 2056
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:payload <- $rsi
	#DEBUG_VALUE: bench_bitmap_popcount_scan:data <- $rsi
	#DEBUG_VALUE: bench_bitmap_popcount_scan:len <- 2056
	#DEBUG_VALUE: micro_read_u32_le:data <- $rsi
	#DEBUG_VALUE: micro_read_u32_le:offset <- 4
	.loc	1 64 38 is_stmt 1               # micro/programs/common.h:64:38
	movl	12(%rdx), %ecx
.Ltmp12:
	#DEBUG_VALUE: bench_bitmap_popcount_scan:seed <- $ecx
	#DEBUG_VALUE: bench_bitmap_popcount_scan:acc <- $ecx
	.loc	1 0 38 is_stmt 0                # micro/programs/common.h:0:38
	xorl	%eax, %eax
	#DEBUG_VALUE: i <- 0
	jmp	.LBB0_5
.Ltmp13:
	.p2align	4, 0x90
.LBB0_8:                                #   in Loop: Header=BB0_5 Depth=1
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:payload_len <- 2056
	#DEBUG_VALUE: bench_bitmap_popcount_scan:len <- 2056
	#DEBUG_VALUE: bench_bitmap_popcount_scan:acc <- $rcx
	#DEBUG_VALUE: i <- $rax
	#DEBUG_VALUE: value <- $rsi
	.loc	0 35 13 is_stmt 1               # micro/programs/bitmap_popcount_scan.bpf.c:35:13
	addq	%rcx, %rdi
.Ltmp14:
	#DEBUG_VALUE: bench_bitmap_popcount_scan:acc <- $rdi
	.loc	0 36 22                         # micro/programs/bitmap_popcount_scan.bpf.c:36:22
	movl	%eax, %ecx
	andb	$7, %cl
	shrq	%cl, %rsi
.Ltmp15:
	.loc	0 36 13 is_stmt 0               # micro/programs/bitmap_popcount_scan.bpf.c:36:13
	movq	%rsi, %rcx
	xorq	%rdi, %rcx
.Ltmp16:
	#DEBUG_VALUE: bench_bitmap_popcount_scan:acc <- $rcx
	.loc	0 33 46 is_stmt 1               # micro/programs/bitmap_popcount_scan.bpf.c:33:46
	incq	%rax
.Ltmp17:
	#DEBUG_VALUE: i <- $rax
	.loc	0 33 23 is_stmt 0               # micro/programs/bitmap_popcount_scan.bpf.c:33:23
	cmpq	$256, %rax                      # imm = 0x100
.Ltmp18:
	.loc	0 33 5                          # micro/programs/bitmap_popcount_scan.bpf.c:33:5
	je	.LBB0_9
.Ltmp19:
.LBB0_5:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_6 Depth 2
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:payload_len <- 2056
	#DEBUG_VALUE: bench_bitmap_popcount_scan:len <- 2056
	#DEBUG_VALUE: i <- $rax
	#DEBUG_VALUE: bench_bitmap_popcount_scan:acc <- $rcx
	#DEBUG_VALUE: micro_read_u64_le:data <- undef
	#DEBUG_VALUE: micro_read_u64_le:offset <- [DW_OP_constu 3, DW_OP_shl, DW_OP_plus_uconst 8, DW_OP_stack_value] $rax
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
	.loc	1 72 15 is_stmt 1               # micro/programs/common.h:72:15
	movq	16(%rdx,%rax,8), %rsi
.Ltmp20:
	#DEBUG_VALUE: micro_read_u64_le:value <- $rsi
	#DEBUG_VALUE: value <- $rsi
	#DEBUG_VALUE: i <- 8
	#DEBUG_VALUE: micro_popcount64:count <- 0
	#DEBUG_VALUE: bit <- 0
	.loc	0 9 32                          # micro/programs/bitmap_popcount_scan.bpf.c:9:32
	movq	%rsi, %r8
	xorl	%edi, %edi
	xorq	%rcx, %r8
.Ltmp21:
	#DEBUG_VALUE: micro_popcount64:value <- $r8
	.loc	0 9 5 is_stmt 0                 # micro/programs/bitmap_popcount_scan.bpf.c:9:5
	je	.LBB0_8
.Ltmp22:
	.p2align	4, 0x90
.LBB0_6:                                #   Parent Loop BB0_5 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:data <- $rdx
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:result <- 0
	#DEBUG_VALUE: bitmap_popcount_scan_xdp:payload_len <- 2056
	#DEBUG_VALUE: bench_bitmap_popcount_scan:len <- 2056
	#DEBUG_VALUE: bench_bitmap_popcount_scan:acc <- $rcx
	#DEBUG_VALUE: i <- $rax
	#DEBUG_VALUE: value <- $rsi
	#DEBUG_VALUE: micro_popcount64:value <- $r8
	.loc	0 0 5                           # micro/programs/bitmap_popcount_scan.bpf.c:0:5
	movq	%rdi, %r9
.Ltmp23:
	#DEBUG_VALUE: bit <- [DW_OP_LLVM_convert 64 7, DW_OP_LLVM_convert 32 7, DW_OP_stack_value] $rdi
	#DEBUG_VALUE: micro_popcount64:count <- $rdi
	#DEBUG_VALUE: micro_popcount64:value <- $r8
	#DEBUG_VALUE: micro_popcount64:value <- undef
	.loc	0 11 14 is_stmt 1               # micro/programs/bitmap_popcount_scan.bpf.c:11:14
	incq	%rdi
.Ltmp24:
	#DEBUG_VALUE: bit <- [DW_OP_LLVM_convert 64 7, DW_OP_LLVM_convert 32 7, DW_OP_stack_value] $r9
	#DEBUG_VALUE: micro_popcount64:count <- $r9
	#DEBUG_VALUE: micro_popcount64:count <- $rdi
	#DEBUG_VALUE: bit <- [DW_OP_LLVM_convert 64 7, DW_OP_LLVM_convert 32 7, DW_OP_stack_value] $rdi
	.loc	0 9 27                          # micro/programs/bitmap_popcount_scan.bpf.c:9:27
	cmpl	$62, %r9d
.Ltmp25:
	.loc	0 9 5 is_stmt 0                 # micro/programs/bitmap_popcount_scan.bpf.c:9:5
	ja	.LBB0_8
.Ltmp26:
# %bb.7:                                #   in Loop: Header=BB0_6 Depth=2

```

## handcraft kinsn c
```c
#include "handcraft_common.h"

static const struct bpf_insn program[] = {
    HC_XDP_PREFIX(2056, 24),
    HC_LDX(BPF_W, BPF_REG_0, BPF_REG_6, 4),

    HC_LDX(BPF_DW, BPF_REG_1, BPF_REG_6, 8),
    HC_ALU64_REG(BPF_XOR, BPF_REG_1, BPF_REG_0),
    HC_KINSN(HC_POPCNT_PAYLOAD(BPF_REG_2, BPF_REG_1, BPF_REG_3, BPF_REG_4),
             MICRO_HANDCRAFT_BPF_X86_POPCNTQ),
    HC_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_2),

    HC_LDX(BPF_DW, BPF_REG_1, BPF_REG_6, 16),
    HC_ALU64_REG(BPF_XOR, BPF_REG_1, BPF_REG_0),
    HC_KINSN(HC_POPCNT_PAYLOAD(BPF_REG_2, BPF_REG_1, BPF_REG_3, BPF_REG_4),
             MICRO_HANDCRAFT_BPF_X86_POPCNTQ),
    HC_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_2),

    HC_LDX(BPF_DW, BPF_REG_1, BPF_REG_6, 24),
    HC_ALU64_REG(BPF_XOR, BPF_REG_1, BPF_REG_0),
    HC_KINSN(HC_POPCNT_PAYLOAD(BPF_REG_2, BPF_REG_1, BPF_REG_3, BPF_REG_4),
             MICRO_HANDCRAFT_BPF_X86_POPCNTQ),
    HC_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_2),

    HC_LDX(BPF_DW, BPF_REG_1, BPF_REG_6, 32),
    HC_ALU64_REG(BPF_XOR, BPF_REG_1, BPF_REG_0),
    HC_KINSN(HC_POPCNT_PAYLOAD(BPF_REG_2, BPF_REG_1, BPF_REG_3, BPF_REG_4),
             MICRO_HANDCRAFT_BPF_X86_POPCNTQ),
    HC_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_2),
    HC_XDP_SUFFIX(),
};

HC_EXPORT_PROGRAM(program)

```

## handcraft kernel x86 disasm
```asm

micro/results/x86_kvm_micro_20260515_024526_991973/details/jit_dumps/bitmap_popcount_scan_handcraft__kernel__sample00.jited.bin:     file format binary


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
  1e:	48 81 c6 08 08 00 00 	add    $0x808,%rsi
  25:	49 39 f5             	cmp    %rsi,%r13
  28:	73 07                	jae    0x31
  2a:	31 c0                	xor    %eax,%eax
  2c:	41 5d                	pop    %r13
  2e:	5b                   	pop    %rbx
  2f:	c9                   	leave
  30:	c3                   	ret
  31:	8b 43 04             	mov    0x4(%rbx),%eax
  34:	48 8b 7b 08          	mov    0x8(%rbx),%rdi
  38:	48 31 c7             	xor    %rax,%rdi
  3b:	f3 48 0f b8 f7       	popcnt %rdi,%rsi
  40:	48 01 f0             	add    %rsi,%rax
  43:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
  47:	48 31 c7             	xor    %rax,%rdi
  4a:	f3 48 0f b8 f7       	popcnt %rdi,%rsi
  4f:	48 01 f0             	add    %rsi,%rax
  52:	48 8b 7b 18          	mov    0x18(%rbx),%rdi
  56:	48 31 c7             	xor    %rax,%rdi
  59:	f3 48 0f b8 f7       	popcnt %rdi,%rsi
  5e:	48 01 f0             	add    %rsi,%rax
  61:	48 8b 7b 20          	mov    0x20(%rbx),%rdi
  65:	48 31 c7             	xor    %rax,%rdi
  68:	f3 48 0f b8 f7       	popcnt %rdi,%rsi
  6d:	48 01 f0             	add    %rsi,%rax
  70:	48 89 43 f8          	mov    %rax,-0x8(%rbx)
  74:	b8 02 00 00 00       	mov    $0x2,%eax
  79:	eb b1                	jmp    0x2c

```
