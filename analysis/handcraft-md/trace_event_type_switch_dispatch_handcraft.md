# trace_event_type_switch_dispatch_handcraft

## original c
```c
#include "common.h"

#define SWITCH_DISPATCH_COUNT 128U
#define SWITCH_DISPATCH_INPUT_SIZE (4U + SWITCH_DISPATCH_COUNT * 4U)

static __always_inline u32 switch_value(u32 value)
{
    switch (value) {
    case 0: return 56;
    case 1: return 43;
    case 2: return 57;
    case 3: return 28;
    case 4: return 14;
    case 5: return 61;
    case 6: return 10;
    case 7: return 58;
    case 8: return 2;
    case 9: return 63;
    case 10: return 49;
    case 11: return 36;
    case 12: return 19;
    case 13: return 42;
    case 14: return 37;
    case 15: return 46;
    case 16: return 34;
    case 17: return 62;
    case 18: return 47;
    case 19: return 6;
    case 20: return 29;
    case 21: return 21;
    case 22: return 15;
    case 23: return 40;
    case 24: return 38;
    case 25: return 26;
    case 26: return 17;
    case 27: return 41;
    case 28: return 33;
    case 29: return 31;
    case 30: return 23;
    case 31: return 52;
    case 32: return 25;
    case 33: return 39;
    case 34: return 11;
    case 35: return 27;
    case 36: return 53;
    case 37: return 4;
    case 38: return 24;
    case 39: return 48;
    case 40: return 32;
    case 41: return 50;
    case 42: return 7;
    case 43: return 35;
    case 44: return 8;
    case 45: return 44;
    case 46: return 51;
    case 47: return 59;
    case 48: return 45;
    case 49: return 0;
    case 50: return 9;
    case 51: return 3;
    case 52: return 13;
    case 53: return 20;
    case 54: return 30;
    case 55: return 18;
    case 56: return 1;
    case 57: return 54;
    case 58: return 22;
    case 59: return 16;
    case 60: return 60;
    case 61: return 5;
    case 62: return 12;
    case 63: return 55;
    default: return 114514U;
    }
}

static __always_inline int bench_trace_event_type_switch_dispatch(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 4)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);

    if (count != SWITCH_DISPATCH_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 4, SWITCH_DISPATCH_COUNT * 4U)) {
        return -1;
    }

    u64 hash = 0;
    for (u32 i = 0; i < SWITCH_DISPATCH_COUNT; i++) {
        hash ^= switch_value(micro_read_u32_le(data, 4 + i * 4U));
    }

    *out = hash;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    trace_event_type_switch_dispatch_xdp,
    bench_trace_event_type_switch_dispatch,
    trace_event_type_switch_dispatch_input_value,
    SWITCH_DISPATCH_INPUT_SIZE)

```

## native asm
```asm
	.text
	.file	"trace_event_type_switch_dispatch.bpf.c"
	.file	0 "/home/yunwei37/workspace/bpf-benchmark" "micro/programs/trace_event_type_switch_dispatch.bpf.c" md5 0x7323b402daaceabce8831ad0de6b96d7
	.globl	trace_event_type_switch_dispatch_xdp # -- Begin function trace_event_type_switch_dispatch_xdp
	.p2align	4, 0x90
	.type	trace_event_type_switch_dispatch_xdp,@function
trace_event_type_switch_dispatch_xdp:   # @trace_event_type_switch_dispatch_xdp
.Lfunc_begin0:
	.cfi_startproc
# %bb.0:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- $rdi
	.loc	0 101 1 prologue_end            # micro/programs/trace_event_type_switch_dispatch.bpf.c:101:1
	movq	(%rdi), %rcx
.Ltmp0:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	movq	8(%rdi), %rdx
	xorl	%eax, %eax
.Ltmp1:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data_end <- $rdx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 516
	.file	1 "micro/programs" "common.h" md5 0xfe1014cbc13a25f3c6a9e9adc3125304
	.loc	1 127 14                        # micro/programs/common.h:127:14
	cmpq	%rdx, %rcx
.Ltmp2:
	.loc	1 127 9 is_stmt 0               # micro/programs/common.h:127:9
	jbe	.LBB0_1
.Ltmp3:
.LBB0_9:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data_end <- $rdx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	.loc	0 101 1 is_stmt 1               # micro/programs/trace_event_type_switch_dispatch.bpf.c:101:1
	retq
.Ltmp4:
.LBB0_1:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data_end <- $rdx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 516
	.loc	1 131 24                        # micro/programs/common.h:131:24
	leaq	8(%rcx), %rsi
.Ltmp5:
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rsi
	.loc	1 132 21                        # micro/programs/common.h:132:21
	cmpq	%rdx, %rsi
.Ltmp6:
	.loc	1 132 9 is_stmt 0               # micro/programs/common.h:132:9
	ja	.LBB0_9
.Ltmp7:
# %bb.2:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data_end <- $rdx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: micro_prepare_packet_payload:data <- $rcx
	#DEBUG_VALUE: micro_prepare_packet_payload:data_end <- $rdx
	#DEBUG_VALUE: micro_prepare_packet_payload:input_size <- 516
	#DEBUG_VALUE: micro_prepare_packet_payload:payload_ptr <- $rsi
	.loc	1 0 9                           # micro/programs/common.h:0:9
	leaq	524(%rcx), %rdi
.Ltmp8:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	.loc	1 132 9                         # micro/programs/common.h:132:9
	cmpq	%rdx, %rdi
	ja	.LBB0_9
.Ltmp9:
# %bb.3:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data_end <- $rdx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload_len <- 516
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload <- $rsi
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:data <- $rsi
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:len <- 516
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:out <- undef
	#DEBUG_VALUE: micro_read_u32_le:offset <- 0
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:count <- undef
	.loc	0 85 15 is_stmt 1               # micro/programs/trace_event_type_switch_dispatch.bpf.c:85:15
	cmpl	$128, (%rsi)
.Ltmp10:
	.loc	0 85 9 is_stmt 0                # micro/programs/trace_event_type_switch_dispatch.bpf.c:85:9
	jne	.LBB0_9
.Ltmp11:
# %bb.4:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data_end <- $rdx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload_len <- 516
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload <- $rsi
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:data <- $rsi
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:len <- 516
	.loc	0 0 9                           # micro/programs/trace_event_type_switch_dispatch.bpf.c:0:9
	movl	$15, %esi
.Ltmp12:
	xorl	%edx, %edx
.Ltmp13:
	leaq	.Lswitch.table.trace_event_type_switch_dispatch_xdp(%rip), %rdi
	jmp	.LBB0_5
.Ltmp14:
	.p2align	4, 0x90
.LBB0_7:                                #   in Loop: Header=BB0_5 Depth=1
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload_len <- 516
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:len <- 516
	#DEBUG_VALUE: i <- [DW_OP_consts 15, DW_OP_minus, DW_OP_consts 4, DW_OP_div, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:hash <- $rax
	.loc	0 94 14 is_stmt 1               # micro/programs/trace_event_type_switch_dispatch.bpf.c:94:14
	xorq	%rax, %rdx
.Ltmp15:
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:hash <- [DW_OP_LLVM_arg 0, DW_OP_LLVM_arg 1, DW_OP_xor, DW_OP_stack_value] undef, undef
	#DEBUG_VALUE: i <- [DW_OP_consts 15, DW_OP_minus, DW_OP_consts 4, DW_OP_div, DW_OP_consts 1, DW_OP_plus, DW_OP_stack_value] $rsi
	.loc	0 93 23                         # micro/programs/trace_event_type_switch_dispatch.bpf.c:93:23
	addq	$4, %rsi
.Ltmp16:
	cmpq	$527, %rsi                      # imm = 0x20F
.Ltmp17:
	.loc	0 93 5 is_stmt 0                # micro/programs/trace_event_type_switch_dispatch.bpf.c:93:5
	je	.LBB0_8
.Ltmp18:
.LBB0_5:                                # =>This Inner Loop Header: Depth=1
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload_len <- 516
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:len <- 516
	.loc	0 0 5                           # micro/programs/trace_event_type_switch_dispatch.bpf.c:0:5
	movq	%rdx, %rax
.Ltmp19:
	#DEBUG_VALUE: i <- [DW_OP_consts 15, DW_OP_minus, DW_OP_consts 4, DW_OP_div, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:hash <- $rdx
	#DEBUG_VALUE: micro_read_u32_le:data <- undef
	#DEBUG_VALUE: micro_read_u32_le:offset <- [DW_OP_plus_uconst 4, DW_OP_stack_value] $rsi
	.loc	1 65 42 is_stmt 1               # micro/programs/common.h:65:42
	movl	-3(%rcx,%rsi), %r8d
.Ltmp20:
	#DEBUG_VALUE: switch_value:value <- $r8d
	.loc	1 0 42 is_stmt 0                # micro/programs/common.h:0:42
	movl	$114514, %edx                   # imm = 0x1BF52
.Ltmp21:
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:hash <- $rax
	.loc	0 8 5 is_stmt 1                 # micro/programs/trace_event_type_switch_dispatch.bpf.c:8:5
	cmpl	$63, %r8d
	ja	.LBB0_7
.Ltmp22:
# %bb.6:                                #   in Loop: Header=BB0_5 Depth=1
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload_len <- 516
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:len <- 516
	#DEBUG_VALUE: i <- [DW_OP_consts 15, DW_OP_minus, DW_OP_consts 4, DW_OP_div, DW_OP_stack_value] $rsi
	#DEBUG_VALUE: bench_trace_event_type_switch_dispatch:hash <- $rax
	#DEBUG_VALUE: switch_value:value <- $r8d
	movl	%r8d, %edx
	movq	(%rdi,%rdx,8), %rdx
	jmp	.LBB0_7
.Ltmp23:
.LBB0_8:
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:ctx <- [DW_OP_LLVM_entry_value 1] $rdi
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:data <- $rcx
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:result <- 0
	#DEBUG_VALUE: trace_event_type_switch_dispatch_xdp:payload_len <- 516
	#DEBUG_VALUE: i <- 0
	.loc	1 91 17                         # micro/programs/common.h:91:17
	movb	%dl, (%rcx)
.Ltmp24:
	#DEBUG_VALUE: i <- 2
	#DEBUG_VALUE: i <- 1
	movb	%dh, 1(%rcx)
	.loc	1 91 30 is_stmt 0               # micro/programs/common.h:91:30
	shrl	$16, %edx
	.loc	1 91 17                         # micro/programs/common.h:91:17
	movb	%dl, 2(%rcx)
.Ltmp25:
	#DEBUG_VALUE: i <- 3
	.loc	1 91 30                         # micro/programs/common.h:91:30
	movl	%eax, %edx
	shrl	$24, %edx
	.loc	1 91 17                         # micro/programs/common.h:91:17
	movb	%dl, 3(%rcx)
.Ltmp26:
	#DEBUG_VALUE: i <- 4
	.loc	1 91 30                         # micro/programs/common.h:91:30
	movq	%rax, %rdx
	shrq	$32, %rdx
	.loc	1 91 17                         # micro/programs/common.h:91:17
	movb	%dl, 4(%rcx)
.Ltmp27:
	#DEBUG_VALUE: i <- 5
	.loc	1 91 30                         # micro/programs/common.h:91:30
	movq	%rax, %rdx
	shrq	$40, %rdx
	.loc	1 91 17                         # micro/programs/common.h:91:17
	movb	%dl, 5(%rcx)
.Ltmp28:
	#DEBUG_VALUE: i <- 6
	.loc	1 91 30                         # micro/programs/common.h:91:30
	movq	%rax, %rdx
	shrq	$48, %rdx
	.loc	1 91 17                         # micro/programs/common.h:91:17
	movb	%dl, 6(%rcx)
.Ltmp29:
	#DEBUG_VALUE: i <- 7
	.loc	1 91 30                         # micro/programs/common.h:91:30
	shrq	$56, %rax
	.loc	1 91 17                         # micro/programs/common.h:91:17
	movb	%al, 7(%rcx)
	movl	$2, %eax
.Ltmp30:

```

## handcraft kinsn c
```c
#include "handcraft_common.h"

static const struct bpf_insn program[] = {
    HC_XDP_PREFIX(516, 10),
    HC_LDX(BPF_W, BPF_REG_3, BPF_REG_6, 4),
    HC_MOV64_IMM(BPF_REG_0, 43),
    HC_MOV64_IMM(BPF_REG_2, 56),
    HC_KINSN(HC_TEST_PAYLOAD(BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_TESTQ_RR),
    HC_KINSN(HC_CMOV_PAYLOAD(BPF_REG_0, BPF_REG_2, BPF_REG_3),
             MICRO_HANDCRAFT_BPF_X86_CMOVNEQ_RR),
    HC_XDP_SUFFIX(),
};

HC_EXPORT_PROGRAM(program)

```

## handcraft kernel x86 disasm
```asm

micro/results/x86_kvm_micro_20260515_024526_991973/details/jit_dumps/trace_event_type_switch_dispatch_handcraft__kernel__sample00.jited.bin:     file format binary


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
  1e:	48 81 c6 04 02 00 00 	add    $0x204,%rsi
  25:	49 39 f5             	cmp    %rsi,%r13
  28:	73 07                	jae    0x31
  2a:	31 c0                	xor    %eax,%eax
  2c:	41 5d                	pop    %r13
  2e:	5b                   	pop    %rbx
  2f:	c9                   	leave
  30:	c3                   	ret
  31:	8b 53 04             	mov    0x4(%rbx),%edx
  34:	b8 2b 00 00 00       	mov    $0x2b,%eax
  39:	be 38 00 00 00       	mov    $0x38,%esi
  3e:	48 85 d2             	test   %rdx,%rdx
  41:	48 0f 45 c6          	cmovne %rsi,%rax
  45:	48 89 43 f8          	mov    %rax,-0x8(%rbx)
  49:	b8 02 00 00 00       	mov    $0x2,%eax
  4e:	eb dc                	jmp    0x2c

```
