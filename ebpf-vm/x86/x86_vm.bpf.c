#include <linux/bpf.h>
#include <bpf_helpers.h>

#include "xvm_abi.h"

#define XVM_ABORT XDP_ABORTED

struct xvm_insn {
	__u8 op;
	__u8 dst;
	__u8 src;
	__u8 flags;
	__u32 aux;
	__u64 imm;
};

static __always_inline int xvm_load_u8(void *data, void *data_end,
				       __u32 off, __u8 *out)
{
	__u8 *p;

	if (off >= XVM_MAX_PACKET_SIZE)
		return -1;
	p = data + off;
	if (p + 1 > (__u8 *)data_end)
		return -1;
	*out = *p;
	return 0;
}

static __always_inline int xvm_load_u16(void *data, void *data_end,
					__u32 off, __u16 *out)
{
	__u8 b0;
	__u8 b1;

	if (xvm_load_u8(data, data_end, off, &b0) < 0)
		return -1;
	if (xvm_load_u8(data, data_end, off + 1, &b1) < 0)
		return -1;
	*out = (__u16)b0 | ((__u16)b1 << 8);
	return 0;
}

static __always_inline int xvm_load_u32(void *data, void *data_end,
					__u32 off, __u32 *out)
{
	__u8 b0;
	__u8 b1;
	__u8 b2;
	__u8 b3;

	if (xvm_load_u8(data, data_end, off, &b0) < 0)
		return -1;
	if (xvm_load_u8(data, data_end, off + 1, &b1) < 0)
		return -1;
	if (xvm_load_u8(data, data_end, off + 2, &b2) < 0)
		return -1;
	if (xvm_load_u8(data, data_end, off + 3, &b3) < 0)
		return -1;
	*out = (__u32)b0 | ((__u32)b1 << 8) | ((__u32)b2 << 16) |
	       ((__u32)b3 << 24);
	return 0;
}

static __always_inline int xvm_load_u64(void *data, void *data_end,
					__u32 off, __u64 *out)
{
	__u32 lo;
	__u32 hi;

	if (xvm_load_u32(data, data_end, off, &lo) < 0)
		return -1;
	if (xvm_load_u32(data, data_end, off + 4, &hi) < 0)
		return -1;
	*out = (__u64)lo | ((__u64)hi << 32);
	return 0;
}

static __always_inline int xvm_load_insn(void *data, void *data_end,
					 __u32 index, struct xvm_insn *insn)
{
	__u32 off;

	if (index >= XVM_MAX_INSNS)
		return -1;
	off = XVM_CODE_OFF + index * XVM_INSN_SIZE;

	if (xvm_load_u8(data, data_end, off, &insn->op) < 0)
		return -1;
	if (xvm_load_u8(data, data_end, off + 1, &insn->dst) < 0)
		return -1;
	if (xvm_load_u8(data, data_end, off + 2, &insn->src) < 0)
		return -1;
	if (xvm_load_u8(data, data_end, off + 3, &insn->flags) < 0)
		return -1;
	if (xvm_load_u32(data, data_end, off + 4, &insn->aux) < 0)
		return -1;
	if (xvm_load_u64(data, data_end, off + 8, &insn->imm) < 0)
		return -1;
	return 0;
}

static __always_inline int xvm_store_u64(void *data, void *data_end,
					 __u32 off, __u64 value)
{
	__u8 *p;

	if (off >= XVM_MAX_PACKET_SIZE)
		return -1;
	p = data + off;
	if (p + 8 > (__u8 *)data_end)
		return -1;
	p[0] = value;
	p[1] = value >> 8;
	p[2] = value >> 16;
	p[3] = value >> 24;
	p[4] = value >> 32;
	p[5] = value >> 40;
	p[6] = value >> 48;
	p[7] = value >> 56;
	return 0;
}

#define XVM_READ_REG(REGNO, OUT)                                                \
	do {                                                                    \
		switch (REGNO) {                                                \
		case XVM_RAX:                                                   \
			(OUT) = rax;                                            \
			break;                                                   \
		case XVM_RCX:                                                   \
			(OUT) = rcx;                                            \
			break;                                                   \
		case XVM_RDX:                                                   \
			(OUT) = rdx;                                            \
			break;                                                   \
		case XVM_RBX:                                                   \
			(OUT) = rbx;                                            \
			break;                                                   \
		case XVM_RSP:                                                   \
			(OUT) = rsp;                                            \
			break;                                                   \
		case XVM_RBP:                                                   \
			(OUT) = rbp;                                            \
			break;                                                   \
		case XVM_RSI:                                                   \
			(OUT) = rsi;                                            \
			break;                                                   \
		case XVM_RDI:                                                   \
			(OUT) = rdi;                                            \
			break;                                                   \
		case XVM_R8:                                                    \
			(OUT) = r8;                                             \
			break;                                                   \
		case XVM_R9:                                                    \
			(OUT) = r9;                                             \
			break;                                                   \
		case XVM_R10:                                                   \
			(OUT) = r10;                                            \
			break;                                                   \
		case XVM_R11:                                                   \
			(OUT) = r11;                                            \
			break;                                                   \
		case XVM_R12:                                                   \
			(OUT) = r12;                                            \
			break;                                                   \
		case XVM_R13:                                                   \
			(OUT) = r13;                                            \
			break;                                                   \
		case XVM_R14:                                                   \
			(OUT) = r14;                                            \
			break;                                                   \
		case XVM_R15:                                                   \
			(OUT) = r15;                                            \
			break;                                                   \
		default:                                                        \
			return XVM_ABORT;                                       \
		}                                                               \
	} while (0)

#define XVM_WRITE_REG(REGNO, VALUE)                                             \
	do {                                                                    \
		switch (REGNO) {                                                \
		case XVM_RAX:                                                   \
			rax = (VALUE);                                          \
			break;                                                   \
		case XVM_RCX:                                                   \
			rcx = (VALUE);                                          \
			break;                                                   \
		case XVM_RDX:                                                   \
			rdx = (VALUE);                                          \
			break;                                                   \
		case XVM_RBX:                                                   \
			rbx = (VALUE);                                          \
			break;                                                   \
		case XVM_RSP:                                                   \
			rsp = (VALUE);                                          \
			break;                                                   \
		case XVM_RBP:                                                   \
			rbp = (VALUE);                                          \
			break;                                                   \
		case XVM_RSI:                                                   \
			rsi = (VALUE);                                          \
			break;                                                   \
		case XVM_RDI:                                                   \
			rdi = (VALUE);                                          \
			break;                                                   \
		case XVM_R8:                                                    \
			r8 = (VALUE);                                           \
			break;                                                   \
		case XVM_R9:                                                    \
			r9 = (VALUE);                                           \
			break;                                                   \
		case XVM_R10:                                                   \
			r10 = (VALUE);                                          \
			break;                                                   \
		case XVM_R11:                                                   \
			r11 = (VALUE);                                          \
			break;                                                   \
		case XVM_R12:                                                   \
			r12 = (VALUE);                                          \
			break;                                                   \
		case XVM_R13:                                                   \
			r13 = (VALUE);                                          \
			break;                                                   \
		case XVM_R14:                                                   \
			r14 = (VALUE);                                          \
			break;                                                   \
		case XVM_R15:                                                   \
			r15 = (VALUE);                                          \
			break;                                                   \
		default:                                                        \
			return XVM_ABORT;                                       \
		}                                                               \
	} while (0)

SEC("xdp")
int x86_vm_xdp(struct xdp_md *ctx)
{
	void *data = (void *)(long)ctx->data;
	void *data_end = (void *)(long)ctx->data_end;
	__u64 rax = 0;
	__u64 rcx = 0;
	__u64 rdx = 0;
	__u64 rbx = 0;
	__u64 rsp = 0;
	__u64 rbp = 0;
	__u64 rsi = 0;
	__u64 rdi = 0;
	__u64 r8 = 0;
	__u64 r9 = 0;
	__u64 r10 = 0;
	__u64 r11 = 0;
	__u64 r12 = 0;
	__u64 r13 = 0;
	__u64 r14 = 0;
	__u64 r15 = 0;
	__u32 magic = 0;
	__u16 insn_count = 0;
	__u32 pc;

	if (xvm_load_u32(data, data_end, XVM_HEADER_OFF, &magic) < 0)
		return XVM_ABORT;
	if (magic != XVM_MAGIC)
		return XVM_ABORT;
	if (xvm_load_u16(data, data_end, XVM_HEADER_OFF + 4, &insn_count) < 0)
		return XVM_ABORT;
	if (insn_count > XVM_MAX_INSNS)
		return XVM_ABORT;

#pragma clang loop unroll(disable)
	for (pc = 0; pc < XVM_MAX_INSNS; pc++) {
		struct xvm_insn insn = {};
		__u64 dst_value;
		__u64 src_value;

		if (pc >= insn_count)
			break;
		if (xvm_load_insn(data, data_end, pc, &insn) < 0)
			return XVM_ABORT;

		if (insn.op == XVM_OP_MOV_IMM64) {
			XVM_WRITE_REG(insn.dst, insn.imm);
		} else if (insn.op == XVM_OP_MOV_REG64) {
			XVM_READ_REG(insn.src, src_value);
			XVM_WRITE_REG(insn.dst, src_value);
		} else if (insn.op == XVM_OP_ADD_IMM64) {
			XVM_READ_REG(insn.dst, dst_value);
			XVM_WRITE_REG(insn.dst, dst_value + insn.imm);
		} else if (insn.op == XVM_OP_ADD_REG64) {
			XVM_READ_REG(insn.dst, dst_value);
			XVM_READ_REG(insn.src, src_value);
			XVM_WRITE_REG(insn.dst, dst_value + src_value);
		} else if (insn.op == XVM_OP_XOR_REG32) {
			XVM_READ_REG(insn.dst, dst_value);
			XVM_READ_REG(insn.src, src_value);
			XVM_WRITE_REG(insn.dst,
				      (__u32)dst_value ^ (__u32)src_value);
		} else if (insn.op == XVM_OP_RET) {
			break;
		} else {
			return XVM_ABORT;
		}
	}

	if (xvm_store_u64(data, data_end, XVM_OUTPUT_OFF, rax) < 0)
		return XVM_ABORT;
	return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
