/*
 * Host cross-check for the x86 simulator's routing of the `SETCC` body
 * (`X86_OP_SETCC`, `0x16`) through the generated handler-composition contract
 * `KPROG_X86_SETCC_*`.
 *
 * Part 1 pins the routed selectors to the contract's own tables: the lane
 * macro `KPROG_X86_SETCC_LANE` is an equality test on the decoded destination
 * shift (exactly 8 selects the high byte; 9 and 1 do NOT, so it is not a
 * truthiness test), and the lane decoder's code is what the write helper's
 * `== 8` branch consults.
 *
 * Part 2 drives the real body — both directly through `X86_SIM_L_EXEC_SETCC`
 * and through the `X86_OP_SETCC` dispatcher arm — over all 14 accepted
 * condition codes, the two unsupported codes, every destination shift in a
 * dense slice around 8, both register lanes, and every raw flag nibble, while
 * comparing all 16 modeled registers (value and tag) to an independent model
 * of `KPROG_X86_EVAL_CC` + a one-byte little-endian register write.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../native-sim \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_setcc_route_host.c -o /tmp/t_scr && /tmp/t_scr
 */

#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static unsigned long cases;

/* The register file the model tracks, parallel to the simulator's own state so
 * the whole file (value and tag) can be compared after every case. */
static __u64 mreg[16];
static __u8 mtag[16];

/* A deterministic register pattern: distinct per index, with high bits set so a
 * 64-bit-vs-narrow write is observable, and a non-scalar tag so a scalarizing
 * write is observable. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

static __u8 pattern_tag(unsigned i)
{
	return (__u8)(1U + (i % 5U));
}

/* The condition expression table, a restatement of `KPROG_X86_EVAL_CC`'s
 * boolean arms from the raw codes. `cc` is compared as the promoted word, so a
 * value whose bits 8..31 are nonzero matches no arm and yields the C default
 * `0`. */
static unsigned model_cc_true(unsigned cc, unsigned cf, unsigned zf,
			      unsigned sf, unsigned of)
{
	switch (cc) {
	case 0U: return of;
	case 1U: return !of;
	case 2U: return cf;
	case 3U: return !cf;
	case 4U: return zf;
	case 5U: return !zf;
	case 6U: return cf || zf;
	case 7U: return (!cf) && (!zf);
	case 8U: return sf;
	case 9U: return !sf;
	case 12U: return sf != of;
	case 13U: return sf == of;
	case 14U: return zf || (sf != of);
	case 15U: return (!zf) && (sf == of);
	default: return 0U;
	}
}

/* The partial-register write `KPROG_X86_WRITE_REG8` performs: the byte at the
 * lane `byte_shift == 8 ? 1 : 0` is replaced and every other byte is kept. */
static __u64 model_write8(__u64 old, __u8 v, unsigned byte_shift)
{
	__u8 bytes[8];
	unsigned i;

	for (i = 0; i < 8U; i++)
		bytes[i] = (__u8)(old >> (8U * i));
	bytes[byte_shift == 8U ? 1U : 0U] = v;
	old = 0;
	for (i = 0; i < 8U; i++)
		old |= (__u64)bytes[i] << (8U * i);
	return old;
}

#define PLANT_REGS()                                                       \
	do {                                                               \
		unsigned __pl_i;                                          \
		for (__pl_i = 0; __pl_i < 16U; __pl_i++) {                \
			X86_SIM_L_WRITE_REG_PTR_TAG(                      \
				__pl_i,                                   \
				(void *)(long)pattern_reg(__pl_i),        \
				pattern_tag(__pl_i));                     \
			mreg[__pl_i] = pattern_reg(__pl_i);               \
			mtag[__pl_i] = pattern_tag(__pl_i);               \
		}                                                         \
	} while (0)

#define COMPARE_STATE(VIA)                                                 \
	do {                                                               \
		unsigned __cs_i;                                          \
		for (__cs_i = 0; __cs_i < 16U; __cs_i++) {                \
			__u64 __cs_got =                                  \
				(__u64)(long)X86_SIM_L_REG_VALUE(__cs_i); \
			__u8 __cs_tag = X86_SIM_L_REG_TAG(__cs_i);        \
			cases++;                                          \
			if (__cs_got != mreg[__cs_i]) {                   \
				printf("MISMATCH setcc via=%u reg%u: got " \
				       "0x%llx want 0x%llx\n", (VIA),     \
				       (unsigned)__cs_i,                  \
				       (unsigned long long)__cs_got,      \
				       (unsigned long long)mreg[__cs_i]); \
				failures++;                               \
				return;                                   \
			}                                                 \
			cases++;                                          \
			if (__cs_tag != mtag[__cs_i]) {                   \
				printf("MISMATCH setcc via=%u reg%u tag: " \
				       "got %u want %u\n", (VIA),         \
				       (unsigned)__cs_i, __cs_tag,        \
				       mtag[__cs_i]);                     \
				failures++;                               \
				return;                                   \
			}                                                 \
		}                                                         \
	} while (0)

/*
 * One SETCC case. `dst_shift` is the AUX destination-shift byte at bits 8..15;
 * `payload` the condition byte at bits 0..7; `cf`/`zf`/`sf`/`of` the flag
 * nibble; `dst` the destination register; `via` selects the dispatcher arm.
 */
static void check_reg(unsigned payload, unsigned dst_shift, unsigned dst,
		      unsigned cf, unsigned zf, unsigned sf, unsigned of,
		      unsigned via)
{
	__u32 aux = ((__u32)payload & 0xffU) |
		    (((__u32)dst_shift & 0xffU) << 8);
	unsigned taken;

	X86_SIM_L_DECLARE_STATE();
	struct x86_sim_xdp_abi __x86_sim_abi = {};
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __x86_sim_abi_kind = KPROG_ABI_KIND_XDP;
	(void)__x86_sim_abi;
	(void)__x86_sim_skb_ctx;
	(void)__x86_sim_abi_kind;
	(void)__x86_sim_ret_addr;
	X86_SIM_L_DECLARE_STACK();
	(void)__x86_xmm0_lo;
	(void)__x86_xmm0_hi;

	PLANT_REGS();
	__x86_cf = (__u8)cf;
	__x86_zf = (__u8)zf;
	__x86_sf = (__u8)sf;
	__x86_of = (__u8)of;

	/* ---- independent model ---- */
	taken = model_cc_true(payload, cf, zf, sf, of);
	mreg[dst] = model_write8(mreg[dst], (__u8)taken,
				 dst_shift == 8U ? 8U : 0U);
	mtag[dst] = X86_SIM_TAG_SCALAR;

	/* ---- run the real body ---- */
	if (via)
		X86_SIM_L_EXEC(X86_OP_SETCC, dst, X86_REG_NONE, 0, aux, 0ULL);
	else
		X86_SIM_L_EXEC_SETCC(dst, aux);

	COMPARE_STATE(via);

	cases++;
	if (__x86_cf != cf || __x86_zf != zf || __x86_sf != sf ||
	    __x86_of != of) {
		printf("MISMATCH setcc via=%u flags: cf=%u zf=%u sf=%u of=%u "
		       "want cf=%u zf=%u sf=%u of=%u\n", via, __x86_cf,
		       __x86_zf, __x86_sf, __x86_of, cf, zf, sf, of);
		failures++;
	}
}

/* The routed selectors must agree with the contract's tables. */
static void check_selectors(void)
{
	static const unsigned shifts[] = { 0U, 1U, 8U, 9U, 16U, 0xffU };
	unsigned i;

	for (i = 0; i < sizeof(shifts) / sizeof(shifts[0]); i++) {
		__u8 s = (__u8)shifts[i];
		__u8 lane = KPROG_X86_SETCC_LANE(s);
		__u8 want = s == 8U ? KPROG_X86_SETCC_LANE_HIGH
				    : KPROG_X86_SETCC_LANE_LOW;

		cases++;
		if (lane != want) {
			printf("MISMATCH setcc lane shift=%u got %u want %u\n",
			       shifts[i], lane, want);
			failures++;
		}
		/* The lane code selects the high byte exactly when the
		 * destination shift is 8: the write helper's equality branch. */
		cases++;
		if ((lane == KPROG_X86_SETCC_LANE_HIGH) != (s == 8U)) {
			printf("MISMATCH setcc lane equality shift=%u\n",
			       shifts[i]);
			failures++;
		}
	}

	/* The lane code is not a truthiness test: 9 and 1 are nonzero and
	 * still select the low byte. */
	cases++;
	if (KPROG_X86_SETCC_LANE(9U) != KPROG_X86_SETCC_LANE_LOW ||
	    KPROG_X86_SETCC_LANE(1U) != KPROG_X86_SETCC_LANE_LOW) {
		printf("MISMATCH setcc lane truthiness\n");
		failures++;
	}
	/* The high lane code is exactly the value that makes the write
	 * helper choose byte 1. */
	cases++;
	if (KPROG_X86_SETCC_LANE_HIGH != 1U ||
	    KPROG_X86_SETCC_LANE_LOW != 0U) {
		printf("MISMATCH setcc lane codes\n");
		failures++;
	}
}

int main(void)
{
	static const unsigned cc_codes[] = {
		X86_CC_O, X86_CC_NO, X86_CC_B, X86_CC_AE, X86_CC_E,
		X86_CC_NE, X86_CC_BE, X86_CC_A, X86_CC_S, X86_CC_NS,
		X86_CC_L, X86_CC_GE, X86_CC_LE, X86_CC_G,
		10U, 11U, 16U, 0xffU,   /* unsupported / out-of-range */
	};
	static const unsigned shift_slice[] = { 0U, 1U, 7U, 8U, 9U, 15U, 16U,
						0xffU };
	unsigned via;
	unsigned c;
	unsigned s;
	unsigned d;
	unsigned fb;

	for (via = 0; via < 2U; via++)
		for (c = 0; c < sizeof(cc_codes) / sizeof(cc_codes[0]); c++)
			for (s = 0; s < sizeof(shift_slice) /
						sizeof(shift_slice[0]); s++)
				for (d = 0; d < 16U; d++)
					for (fb = 0; fb < 16U; fb++)
						check_reg(cc_codes[c],
							  shift_slice[s], d,
							  fb & 1U,
							  (fb >> 1) & 1U,
							  (fb >> 2) & 1U,
							  (fb >> 3) & 1U,
							  via);

	check_selectors();

	if (failures != 0) {
		printf("x86 setcc route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 setcc route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
