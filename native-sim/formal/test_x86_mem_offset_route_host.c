/*
 * Host cross-check for the x86 simulator's routing of effective-address offsets
 * through the generated KPROG_X86_MEM_OFFSET contract (STEP 0076).
 *
 * `X86_SIM_L_MEM_OFFSET(AUX, DISP)` in `x86_sim_local_bpf.h` formerly restated
 * the offset arithmetic inline. It now resolves the AUX index register through
 * `X86_SIM_L_READ_REG` and delegates to the machine-checked
 * `KPROG_X86_MEM_OFFSET` macro, so the sim's LEA/MOV/CMP/STORE/test/base-offset
 * arms and the Lean refinement share one implementation.
 *
 * This oracle includes the *simulator* header (so the real `X86_SIM_L_MEM_OFFSET`
 * is the macro under test), drives it over register-AUX forms, and compares the
 * result against an independent signed accumulator built from the same source
 * register value; it also checks the no-index form ignores a poisoned register
 * file and that the two routing helpers agree. Exit 1 on mismatch.
 *
 * Build/run:
 *   cd native-sim/formal
 *   cc -Wall -Wextra -O2 -I. -I../x86 test_x86_mem_offset_route_host.c \
 *      -o /tmp/t_mor && /tmp/t_mor
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

/* Independent oracle: signed 64-bit accumulate, index term as an explicit
 * power-of-two multiply (never the macro's shift), reduced modulo 64 like the
 * C `<<` and Lean `<<<`. */
static __s64 offset_oracle(int has_index, __u8 scale, __s64 disp, __u64 index)
{
	__int128 acc = (__int128)disp;

	if (has_index) {
		unsigned shift = (unsigned)scale & 63U;
		__u64 scaled = index;

		if (shift != 0)
			scaled = index * ((__u64)1 << shift);
		acc += (__int128)(__s64)scaled;
	}
	return (__s64)(acc & (__int128)0xffffffffffffffffULL);
}

static __u32 mem_aux_reg(__u8 reg, __u8 scale_log2)
{
	return X86_MEM_AUX(reg, scale_log2);
}

int main(void)
{
	static const __u64 reg_values[] = {
		0x0ULL, 1ULL, 8ULL, 0x10ULL, 0xffffffffffffffffULL,
		0x8000000000000000ULL, 0xfffffffffffffff8ULL,
		0xffffffffffffffffULL - 12345ULL,
	};
	static const __s64 disps[] = { 0, 8, -4, -64, 0x7fffffff, -0x80000000LL };
	static const __u8 scales[] = { 1, 2, 4, 8 };
	static const __u8 index_regs[] = { X86_RAX, X86_RSP, X86_RBP, X86_RDI,
					   X86_R15, X86_REG_NONE };
	unsigned long cases = 0;
	size_t i, j, k, m;

	for (i = 0; i < sizeof(index_regs) / sizeof(index_regs[0]); i++) {
		__u8 reg = index_regs[i];
		int has_index = reg != X86_REG_NONE;

		for (j = 0; j < sizeof(scales) / sizeof(scales[0]); j++) {
			__u8 scale_log2 = scales[j];
			__u32 aux = mem_aux_reg(reg, scale_log2);

			/* Install a known value into every register so the read
			 * path is exercised regardless of which one AUX names. */
			for (m = 0; m < sizeof(reg_values) / sizeof(reg_values[0]);
			     m++) {
				__u64 rv = reg_values[m];
				__u8 base_reg = has_index ? reg : X86_RAX;

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
				X86_SIM_L_WRITE_REG_WIDTH(base_reg, rv,
							  X86_WIDTH_64);

				for (k = 0; k < sizeof(disps) / sizeof(disps[0]);
				     k++) {
					__s64 disp = disps[k];
					__s64 got = X86_SIM_L_MEM_OFFSET(aux, disp);
					__s64 want = offset_oracle(
						has_index, scale_log2, disp,
						has_index ? rv : 0);

					cases++;
					if (got != want) {
						printf("MISMATCH routed reg=%u scale=%u "
						       "disp=%lld rv=%llu got=%lld want=%lld\n",
						       reg, scale_log2, disp, rv,
						       (long long)got,
						       (long long)want);
						failures++;
					}

					/* The indexed helper must agree with the
					 * public helper for an explicit value. */
					cases++;
					if (X86_SIM_L_MEM_OFFSET_INDEXED(
						    aux, disp, rv, has_index) !=
					    got) {
						printf("MISMATCH route mismatch reg=%u "
						       "scale=%u disp=%lld\n",
						       reg, scale_log2, disp);
						failures++;
					}
				}
			}
		}
	}

	/* The no-index form must ignore whatever sits in a poisoned register
	 * file: only DISP survives. */
	{
		__u32 aux = mem_aux_reg(X86_REG_NONE, 3);
		__s64 disp = -123;

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
			printf("MISMATCH no-index not disp-only\n");
			failures++;
		}
	}

	if (failures != 0) {
		printf("x86 mem offset route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 mem offset route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}
