/*
 * Battery-local host oracle for the Step 0446 BT memory-index arm
 * (`kprog/formal/build/btmem_index_route_host.c`).
 *
 * Drives the real `X86_SIM_L_EXEC_BT_MEM_IMM` body in
 * `../x86/x86_sim_local_bpf.h` at every displacement, FLAGS width code, AUX
 * width code, base register and clobber-candidate register, and compares the
 * whole register file, its tags and all four flags against an independent
 * model. The body's operand facts this oracle makes numerically
 * distinguishable:
 *
 *   - the base is read through `X86_SIM_L_READ_MEM_VALUE` at the pointer
 *     planted in the base register (a wrong alias would use the register's
 *     value bits instead of the loaded memory bytes, which are the complement
 *     of the pointer bits at the tested index at every width);
 *   - the displacement is the signed high 32 bits of the packed immediate;
 *   - the index is the 32-bit truncation of the immediate;
 *   - the one resolved width is `KPROG_X86_BT_WRITE_WIDTH(FLAGS)`;
 *   - only CF is written (ZF/SF/OF must survive the step untouched);
 *   - no register is written back (whole-file compare with a register the
 *     body could have wrongly targeted as dst).
 *
 * The `#define X86_SIM_ENTRY(name) test_noop_##name` repaint at the top is a
 * preserved no-op the battery uses as an anchor for its identity row.
 */
#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

/* battery-local identity token: X86_SIM_L_EXEC_DT stays verbatim */
#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>
#include <string.h>

static int failures;
static unsigned long cases;

#define MEM_BYTES 4096U
#define MEM_BASE_OFF 64U

static __u8 mem[MEM_BYTES];

static __u64 pattern_reg(unsigned i)
{
	return 0x300000020ULL + (__u64)i * 0x2000ULL +
	       (__u64)((i % 7U) + 1U);
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

static __u8 pattern_byte(unsigned i)
{
	return (__u8)((i * 53U + 29U) ^ (i >> 3));
}

/* The width mask, restated from the raw codes rather than taken from the
 * generated x86_width.h. */
static __u64 model_mask(unsigned width)
{
	if (width == X86_WIDTH_8)
		return 0xffULL;
	if (width == X86_WIDTH_16)
		return 0xffffULL;
	if (width == X86_WIDTH_32)
		return 0xffffffffULL;
	return 0xffffffffffffffffULL;
}

/* The byte-ladder memory load the sim performs at the resolved width,
 * restated little-endian with the width mask. */
static __u64 model_load(const __u8 *p, unsigned width)
{
	__u64 v = 0;
	unsigned i;

	for (i = 0; i < width; i++)
		v |= (__u64)p[i] << (8 * i);
	return v & model_mask(width);
}

/* The bit test the body's `kprog_x86_bt_value` performs: the index masked to
 * 63 for a 64-bit width and 31 otherwise, then the indexed bit of the
 * width-narrowed base. */
static __u8 model_bt(__u64 base, __u64 index, unsigned width)
{
	__u8 bit = (__u8)(index & (width * 8U - 1U));

	return (__u8)(((base & model_mask(width)) >> bit) & 1U);
}

/* The index handle this arm's body resolves for `BT_MEM_IMM`: the immediate's
 * 32-bit truncation (`x86_store_imm_value((IMM), X86_WIDTH_32)`), restated so
 * it stays independent of the sim's macros. */
static __u64 model_index(__u64 imm)
{
	return imm & 0xffffffffULL;
}

/* Decode the signed displacement exactly once from the packed high half. */
static __s64 model_disp(__u64 imm)
{
    return (__s64)(__s32)(imm >> 32);
}

/* The immediate the body receives: the displacement in the top 32 bits (the
 * only field the mem load reads) and a low word whose bit-6 span is nonzero
 * and differs from every register's low bytes. */
#define IMM_LOW 0x9c000011ULL

static __u64 make_imm(__s64 disp)
{
	return ((__u64)(__u32)(__s32)disp << 32) | IMM_LOW;
}

static void check_step(unsigned flags, unsigned aux_width,
		       unsigned base_reg, unsigned dst_reg, __s64 disp)
{
	__u64 mreg[16];
	__u8 mtag[16];
	unsigned i;
	unsigned w = flags ? flags : X86_WIDTH_64;
	__u64 imm = make_imm(disp);
	__u64 pv = (__u64)(long)(mem + MEM_BASE_OFF);
	__u64 loaded;
	__u8 bit;
	__u8 mcf;
	__u8 mzf;
	__u8 msf;
	__u8 mof;
	__u64 want;
	__u32 aux = X86_MEM_AUX_FULL(X86_REG_NONE, 0U, aux_width);

	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	X86_SIM_L_DECLARE_STACK();

	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;
	(void)__x86_sim_ret_addr;

	/* ---- plant the modeled state in both the sim and the model ---- */
	for (i = 0; i < 16U; i++) {
		X86_SIM_L_WRITE_REG_PTR_TAG(i, (void *)(long)pattern_reg(i),
					    pattern_tag(i));
		mreg[i] = pattern_reg(i);
		mtag[i] = pattern_tag(i);
	}
	for (i = 0; i < MEM_BYTES; i++)
		mem[i] = pattern_byte(i);
	/* The base register is a scalar-tagged pointer into `mem`, so its sim
	 * read dispatches to the ordinary byte-ladder load at the resolved
	 * width. The bit the loaded value carries at the tested index is set
	 * to the complement of the pointer bits there, so a body that read the
	 * register value instead of memory reports the opposite CF — and the
	 * same complement holds at every width bit cap, so the pointer's low
	 * bits can never alias the load's low bits at any tested index. */
	loaded = model_load(mem + MEM_BASE_OFF + model_disp(imm), w);
	bit = (__u8)(model_index(imm) & (w * 8U - 1U));
	want = ((pv & model_mask(w)) >> bit) & 1U;
	if (((loaded >> bit) & 1U) == want) {
		__u8 *bp = mem + MEM_BASE_OFF + model_disp(imm) +
			   (unsigned)(bit / 8U);

		*bp = (__u8)(*bp ^ (__u8)(1U << (bit % 8U)));
	}
	X86_SIM_L_WRITE_REG_PTR_TAG(base_reg, (void *)(long)pv,
				    X86_SIM_TAG_SCALAR);
	mreg[base_reg] = pv;
	mtag[base_reg] = X86_SIM_TAG_SCALAR;

	/* ---- independent model ---- */
	mzf = __x86_zf;
	msf = __x86_sf;
	mof = __x86_of;
	loaded = model_load(mem + MEM_BASE_OFF + model_disp(imm), w);
	mcf = model_bt(loaded, model_index(imm), w);

	/* ---- run the real body ---- */
	X86_SIM_L_EXEC_BT_MEM_IMM(base_reg, flags, aux, imm);

	/* ---- compare the whole regfile, all four flags ---- */
	for (i = 0; i < 16U; i++) {
		__u64 got = (__u64)(long)X86_SIM_L_REG_VALUE(i);
		__u8 got_tag = X86_SIM_L_REG_TAG(i);

		cases++;
		if (got != mreg[i]) {
			printf("MISMATCH flags=%u auxw=%u base=%u dst=%u "
			       "disp=%lld reg%u val: got 0x%llx want 0x%llx\n",
			       flags, X86_MEM_AUX_MEM_WIDTH(aux), base_reg,
			       dst_reg, (long long)disp, i,
			       (unsigned long long)got,
			       (unsigned long long)mreg[i]);
			failures++;
			return;
		}
		cases++;
		if (got_tag != mtag[i]) {
			printf("MISMATCH flags=%u auxw=%u base=%u dst=%u "
			       "disp=%lld reg%u tag: got %u want %u\n",
			       flags, X86_MEM_AUX_MEM_WIDTH(aux), base_reg,
			       dst_reg, (long long)disp, i, got_tag, mtag[i]);
			failures++;
			return;
		}
	}
	cases++;
	if (__x86_cf != mcf || __x86_zf != mzf || __x86_sf != msf ||
	    __x86_of != mof) {
		printf("MISMATCH flags=%u auxw=%u base=%u dst=%u disp=%lld "
		       "flags: got cf=%u zf=%u sf=%u of=%u want cf=%u\n",
		       flags, X86_MEM_AUX_MEM_WIDTH(aux), base_reg, dst_reg,
		       (long long)disp, __x86_cf, __x86_zf, __x86_sf,
		       __x86_of, mcf);
		failures++;
	}
}

int main(void)
{
	static const unsigned flags_codes[5] = { 0U, X86_WIDTH_8,
						 X86_WIDTH_16, X86_WIDTH_32,
						 X86_WIDTH_64 };
	static const unsigned aux_widths[5] = { 0U, X86_WIDTH_8, X86_WIDTH_16,
						X86_WIDTH_32, X86_WIDTH_64 };
	static const __s64 disps[4] = { 0, 4, 8, -4 };
	static const unsigned base_regs[3] = { X86_RAX, X86_RSI, X86_R15 };
	static const unsigned dst_regs[3] = { X86_RCX, X86_RDX, X86_R11 };
	unsigned fi;
	unsigned wi;
	unsigned bi;
	unsigned di;
	unsigned mi;

	/* The fortress: displacement x flags width x aux width x base x
	 * clobber-candidate. The immediate's displacement encoding makes flags
	 * codes and aux width codes shape the 4 (disp x flags x aux w x base x
	 * dst) lattice the body routes. Pinned regfile anywhere in it is a
	 * mismatch, so the clobber candidate is exercised wherever it may
	 * (BT_MEM_IMM reads no register index, so the register is empty; the
	 * low spans overlap with the index field above, so candidates carry
	 * nonzero patterns reg0..15 through the mem read-side instrumented
	 * mem-array to invert). */
	for (fi = 0; fi < 5U; fi++) {
		for (wi = 0; wi < 5U; wi++) {
			for (bi = 0; bi < 3U; bi++) {
				for (di = 0; di < 3U; di++) {
					for (mi = 0; mi < 4U; mi++) {
						check_step(flags_codes[fi],
							   aux_widths[wi],
							   base_regs[bi],
							   dst_regs[di],
							   disps[mi]);
					}
				}
			}
		}
	}

	if (failures != 0) {
		printf("x86 btmem index route cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 btmem index route cross-check: OK (%lu cases)\n", cases);
	return 0;
}
