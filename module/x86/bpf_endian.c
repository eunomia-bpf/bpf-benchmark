// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT kinsn: ENDIAN_LOAD — fused load-and-byte-swap via MOVBE
 *
 * Registers three kfuncs with KF_KINSN:
 *   bpf_endian_load16(void *addr) -> u64  (16-bit load + bswap)
 *   bpf_endian_load32(void *addr) -> u64  (32-bit load + bswap)
 *   bpf_endian_load64(void *addr) -> u64  (64-bit load + bswap)
 *
 * When inlined by the x86 JIT, emits MOVBE instructions instead of
 * separate MOV + BSWAP sequences.
 *
 * BPF register -> x86 register mapping (from bpf_jit_comp.c):
 *   BPF_REG_0 = RAX (return value)
 *   BPF_REG_1 = RDI (arg1 = addr)
 *
 * MOVBE (Move Data After Swapping Bytes) is available on Haswell+ (CPUID
 * EAX=1, ECX bit 22).  The daemon should check for MOVBE support before
 * emitting this kfunc.
 *
 * Emitted x86-64 sequences:
 *   bpf_endian_load16:  66 0F 38 F0 07  movbe ax, [rdi]    (5 bytes)
 *                        48 0F B7 C0     movzx rax, ax      (4 bytes)
 *   bpf_endian_load32:  0F 38 F0 07     movbe eax, [rdi]   (4 bytes)
 *   bpf_endian_load64:  48 0F 38 F0 07  movbe rax, [rdi]   (5 bytes)
 */

#include "kinsn_common.h"

/* ---- kfunc fallback implementations ---- */

__bpf_kfunc_start_defs();

__bpf_kfunc u64 bpf_endian_load16(const void *addr)
{
	u16 val = *(const u16 *)addr;
	return __builtin_bswap16(val);
}

__bpf_kfunc u64 bpf_endian_load32(const void *addr)
{
	u32 val = *(const u32 *)addr;
	return __builtin_bswap32(val);
}

__bpf_kfunc u64 bpf_endian_load64(const void *addr)
{
	u64 val = *(const u64 *)addr;
	return __builtin_bswap64(val);
}

__bpf_kfunc_end_defs();

/* ---- BTF kfunc set ---- */

KINSN_KFUNC_SET_START(bpf_endian)
KINSN_KFUNC_ID(bpf_endian_load16)
KINSN_KFUNC_ID(bpf_endian_load32)
KINSN_KFUNC_ID(bpf_endian_load64)
KINSN_KFUNC_SET_END(bpf_endian)

/* ---- x86 JIT emit callbacks ---- */

/*
 * bpf_endian_load16: movbe ax, [rdi] + movzx rax, ax
 *
 *   66 0F 38 F0 07     movbe ax, [rdi]     (5 bytes, 16-bit operand override)
 *   48 0F B7 C0        movzx rax, ax       (4 bytes, zero-extend to 64-bit)
 *
 * Total: 9 bytes
 */
static int emit_endian_load16_x86(u8 *image, u32 *off, bool emit,
				  const struct bpf_kinsn_call *call,
				  struct bpf_prog *prog)
{
	static const u8 insns[] = {
		0x66, 0x0F, 0x38, 0xF0, 0x07,	/* movbe ax, [rdi] */
		0x48, 0x0F, 0xB7, 0xC0,	/* movzx rax, ax   */
	};

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)call;
	(void)prog;

	if (emit)
		memcpy(image + *off, insns, sizeof(insns));

	*off += sizeof(insns);
	return sizeof(insns);
}

/*
 * bpf_endian_load32: movbe eax, [rdi]
 *
 *   0F 38 F0 07        movbe eax, [rdi]    (4 bytes)
 *
 * Note: 32-bit operand in 64-bit mode implicitly zero-extends to RAX.
 * Total: 4 bytes
 */
static int emit_endian_load32_x86(u8 *image, u32 *off, bool emit,
				  const struct bpf_kinsn_call *call,
				  struct bpf_prog *prog)
{
	static const u8 insns[] = {
		0x0F, 0x38, 0xF0, 0x07,	/* movbe eax, [rdi] */
	};

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)call;
	(void)prog;

	if (emit)
		memcpy(image + *off, insns, sizeof(insns));

	*off += sizeof(insns);
	return sizeof(insns);
}

/*
 * bpf_endian_load64: movbe rax, [rdi]
 *
 *   48 0F 38 F0 07     movbe rax, [rdi]    (5 bytes, REX.W prefix)
 *
 * Total: 5 bytes
 */
static int emit_endian_load64_x86(u8 *image, u32 *off, bool emit,
				  const struct bpf_kinsn_call *call,
				  struct bpf_prog *prog)
{
	static const u8 insns[] = {
		0x48, 0x0F, 0x38, 0xF0, 0x07,	/* movbe rax, [rdi] */
	};

	if (!off)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

	(void)call;
	(void)prog;

	if (emit)
		memcpy(image + *off, insns, sizeof(insns));

	*off += sizeof(insns);
	return sizeof(insns);
}

static void model_endian_load(struct bpf_kinsn_effect *effect, u8 size)
{
	u64 umax;

	effect->input_mask = BIT(BPF_REG_1);
	effect->clobber_mask = BIT(BPF_REG_0);
	effect->result_type = BPF_KINSN_RES_SCALAR;
	effect->result_reg = BPF_REG_0;
	effect->result_size = size == sizeof(u32) ? sizeof(u32) : sizeof(u64);
	effect->nr_mem_accesses = 1;
	effect->mem_accesses[0].base_reg = BPF_REG_1;
	effect->mem_accesses[0].size = size;
	effect->mem_accesses[0].access_type = BPF_READ;
	effect->mem_accesses[0].flags = BPF_KINSN_MEM_RESULT;

	umax = size == sizeof(u64) ? U64_MAX : ((1ULL << (size * 8)) - 1);
	effect->umin_value = 0;
	effect->umax_value = umax;
	effect->smin_value = 0;
	effect->smax_value = umax;
	if (umax != U64_MAX) {
		effect->flags |= BPF_KINSN_EFFECT_HAS_TNUM;
		effect->result_tnum = kinsn_tnum_low_bits(umax);
	}
}

static int model_endian_load16_call(const struct bpf_kinsn_call *call,
				    const struct bpf_kinsn_scalar_state *scalar_regs,
				    struct bpf_kinsn_effect *effect)
{
	(void)call;
	(void)scalar_regs;
	model_endian_load(effect, sizeof(u16));
	return 0;
}

static int model_endian_load32_call(const struct bpf_kinsn_call *call,
				    const struct bpf_kinsn_scalar_state *scalar_regs,
				    struct bpf_kinsn_effect *effect)
{
	(void)call;
	(void)scalar_regs;
	model_endian_load(effect, sizeof(u32));
	return 0;
}

static int model_endian_load64_call(const struct bpf_kinsn_call *call,
				    const struct bpf_kinsn_scalar_state *scalar_regs,
				    struct bpf_kinsn_effect *effect)
{
	(void)call;
	(void)scalar_regs;
	model_endian_load(effect, sizeof(u64));
	return 0;
}

static const struct bpf_kinsn_ops endian_load16_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC,
	.model_call = model_endian_load16_call,
	.emit_x86 = emit_endian_load16_x86,
	.max_emit_bytes = 16,
};

static const struct bpf_kinsn_ops endian_load32_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC,
	.model_call = model_endian_load32_call,
	.emit_x86 = emit_endian_load32_x86,
	.max_emit_bytes = 16,
};

static const struct bpf_kinsn_ops endian_load64_ops = {
	.owner = THIS_MODULE,
	.api_version = 1,
	.supported_encodings = BPF_KINSN_ENC_LEGACY_KFUNC,
	.model_call = model_endian_load64_call,
	.emit_x86 = emit_endian_load64_x86,
	.max_emit_bytes = 16,
};

/* ---- module definition ---- */

static const struct kinsn_ops_entry endian_entries[] = {
	{ "bpf_endian_load16", &endian_load16_ops },
	{ "bpf_endian_load32", &endian_load32_ops },
	{ "bpf_endian_load64", &endian_load64_ops },
};

DEFINE_KINSN_MODULE_MULTI(bpf_endian, endian_entries,
			  "BpfReJIT kinsn: ENDIAN_LOAD (MOVBE) inline kfunc");
