/*
 * Host cross-check for the x86 simulator's routing of index-register presence
 * through the generated KPROG_X86_MEM_INDEX_PRESENT contract (STEP 0101).
 *
 * `X86_SIM_L_MEM_OFFSET(AUX, DISP)` in `x86_sim_local_bpf.h` formerly tested
 * `X86_MEM_AUX_INDEX(AUX) != X86_REG_NONE` inline, twice, for the presence flag
 * and the index value selector. Both now come from the machine-checked
 * `KPROG_X86_MEM_INDEX_PRESENT`, whose selector `KProgFormal/X86MemIndex.lean`
 * proves equals an independent `decide (indexByte != 0xff)`.
 *
 * This oracle includes the *simulator* header (so the real `X86_SIM_L_MEM_OFFSET`
 * is the macro under test), constructs AUX words across the full index-byte
 * range including the sentinel and its immediate neighbours, and checks the
 * routed result against an independent presence/value oracle. Exit 1 on
 * mismatch.
 *
 * Build/run:
 *   cd kprog/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_mem_index_route_host.c -o /tmp/t_mir && /tmp/t_mir
 */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;

/* DECLARE_STATE's tag initializers are written by the register-write path but
 * not read back here, so reference them to keep the build warning-free. */
#define X86_SIM_TEST_VOID_TAG(REG, NAME) (void)__x86_##NAME##_tag;

/* Independent oracle: the mode carries an index register exactly when its AUX
 * index byte differs from the sentinel, and then contributes
 * index_value * 2^scale modulo 64. */
static __u8 index_present_oracle(__u8 index_byte)
{
	return index_byte != 0xffU ? 1U : 0U;
}

static __s64 offset_oracle(__u8 index_byte, __u8 scale, __s64 disp, __u64 index)
{
	__int128 acc = (__int128)disp;

	if (index_present_oracle(index_byte)) {
		unsigned shift = (unsigned)scale & 63U;
		__u64 scaled = index;

		if (shift != 0)
			scaled = index * ((__u64)1 << shift);
		acc += (__int128)(__s64)scaled;
	}
	return (__s64)(acc & (__int128)0xffffffffffffffffULL);
}

int main(void)
{
	/* Every index byte in AUX: full range plus the sentinel neighbourhood
	 * already covered, so presence is checked at and around the boundary. */
	unsigned long cases = 0;
	__u32 index_byte;
	size_t m, s, d;

	static const __u64 reg_values[] = {
		0x0ULL, 1ULL, 8ULL, 0xffffffffffffffffULL,
		0x8000000000000000ULL, 0xfffffffffffffff8ULL,
	};
	static const __s64 disps[] = { 0, 8, -4, 64, 0x7fffffff, -0x80000000LL };
	static const __u8 scales[] = { 0, 1, 2, 3 };
	static const __u8 index_regs[] = { X86_RAX, X86_RSP, X86_R15 };

	for (index_byte = 0; index_byte <= 0xffU; index_byte++) {
		__u8 want_present = index_present_oracle((__u8)index_byte);

		cases++;
		if (KPROG_X86_MEM_INDEX_PRESENT((__u8)index_byte) != want_present) {
			printf("MISMATCH routed present byte=%u got=%u want=%u\n",
			       index_byte,
			       KPROG_X86_MEM_INDEX_PRESENT((__u8)index_byte),
			       want_present);
			failures++;
		}

		/* The sentinel picks the absent arm; a plain register byte the
		 * present arm. Both routed through the generated arm macro. */
		cases++;
		if (KPROG_X86_MEM_INDEX_ARM((__u8)index_byte) !=
		    (want_present ? KPROG_X86_MEM_INDEX_ARM_PRESENT
				  : KPROG_X86_MEM_INDEX_ARM_ABSENT)) {
			printf("MISMATCH routed arm byte=%u\n", index_byte);
			failures++;
		}
	}

	/* Register-AUX forms: the byte in AUX is the register, and the routed
	 * presence must agree with the sentinel test at that byte. */
	for (s = 0; s < sizeof(index_regs) / sizeof(index_regs[0]); s++) {
		__u8 reg = index_regs[s];

		for (d = 0; d < sizeof(scales) / sizeof(scales[0]); d++) {
			__u8 scale = scales[d];
			__u32 aux = X86_MEM_AUX(reg, scale);
			__u8 index_byte = X86_MEM_AUX_INDEX(aux);

			cases++;
			if (KPROG_X86_MEM_INDEX_PRESENT(index_byte) !=
			    index_present_oracle(index_byte)) {
				printf("MISMATCH routed AUX present reg=%u\n", reg);
				failures++;
			}

			for (m = 0; m < sizeof(reg_values) /
						sizeof(reg_values[0]); m++) {
				__u64 rv = reg_values[m];
				size_t k;

				for (k = 0; k < sizeof(disps) /
							sizeof(disps[0]); k++) {
					__s64 disp = disps[k];
					__s64 got, want;

					X86_SIM_L_DECLARE_STATE();
					X86_SIM_L_DECLARE_STACK();
					(void)__x86_stack_mem;
					(void)__x86_cf;
					(void)__x86_zf;
					(void)__x86_sf;
					(void)__x86_of;
					(void)__x86_xmm0_lo;
					(void)__x86_xmm0_hi;
					(void)__x86_sim_ret_addr;
					X86_SIM_L_FOR_EACH_GPR(X86_SIM_TEST_VOID_TAG)
					X86_SIM_L_WRITE_REG_WIDTH(reg, rv,
								  X86_WIDTH_64);

					got = X86_SIM_L_MEM_OFFSET(aux, disp);
					want = offset_oracle(index_byte, scale,
							     disp, rv);
					cases++;
					if (got != want) {
						printf("MISMATCH routed offset "
						       "reg=%u scale=%u disp=%lld "
						       "rv=%llu got=%lld want=%lld\n",
						       reg, scale, disp, rv,
						       (long long)got,
						       (long long)want);
						failures++;
					}
				}
			}
		}
	}

	/* The sentinel must take the displacement-only arm and ignore a poisoned
	 * register file. */
	{
		__u32 aux = X86_MEM_AUX(X86_REG_NONE, 3);
		__s64 disp = -123;

		if (X86_MEM_AUX_INDEX(aux) != X86_REG_NONE) {
			printf("MISMATCH sentinel padded with a register\n");
			failures++;
		}

		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_stack_mem;
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		X86_SIM_L_FOR_EACH_GPR(X86_SIM_TEST_VOID_TAG)
		X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0xdeadbeefcafef00dULL,
					  X86_WIDTH_64);
		X86_SIM_L_WRITE_REG_WIDTH(X86_RSP, 0x123456789ULL,
					  X86_WIDTH_64);
		cases++;
		if (X86_SIM_L_MEM_OFFSET(aux, disp) != disp) {
			printf("MISMATCH sentinel not disp-only\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("x86 mem index route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 mem index route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
