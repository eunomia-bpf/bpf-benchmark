/* Cross-check the actual sparse68 helper ladder and typed-call ABI.
 * Preserve whole-register/tag framing and every original register-number case,
 * now covering every armed ID plus gaps, zero and the full64-bit boundary.
 * Typed public-ABI host stubs expose selected identity, normalized arguments,
 * return value and pointer tags. Kernel helper behavior remains an external
 * oracle; this test checks dispatch and SysV-to-helper argument plumbing. */

#define __BPF_HELPERS__ 1
#define X86_SIM_ENABLE_STACK
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

/* Host environment returns retain the original lookup/update/delete/time
 * vectors; typed stubs additionally expose every helper's forwarded ABI. */
#include "x86_helper_environment_host.h"

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>
/* Observe the failure route for dynamic IDs; a separate negative compilation
 * below keeps the actual production error declaration and must fail. */
#ifndef ORA_NEGATIVE_HELPER
#undef X86_SIM_L_UNSUPPORTED_HELPER
#define X86_SIM_L_UNSUPPORTED_HELPER() do { ora_called = 0; } while (0)
#endif


static int failures;
static unsigned long cases;

/* A deterministic per-register pattern, with high bits set so a 64-bit write
 * and a narrow write are distinguishable, and never zero. */
static __u64 pattern_reg(unsigned i)
{
	return 0x9e3779b97f4a7c15ULL * (__u64)(i + 1U) + 0x0123456789abcdefULL;
}

/* A non-scalar tag planted in every cell before a call, so the RAX tag change
 * is observable even when a write leaves the pointer bytes unchanged. */
#define ORA_MARK_TAG 0x7fU

static const char *gpr_names[16] = {
	"rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
	"r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",
};

#define ORA_CAPTURE(REG, NAME)                                             \
	do {                                                               \
		__p[__i] = __x86_##NAME.ptr;                               \
		__t[__i] = __x86_##NAME##_tag;                             \
		__i++;                                                     \
	} while (0);

#define ORA_SNAPSHOT(P, T)                                                 \
	do {                                                               \
		void **__p = (P);                                          \
		__u8 *__t = (T);                                           \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(ORA_CAPTURE)                        \
	} while (0)

#define ORA_SEED(REG, NAME)                                                \
	do {                                                               \
		__x86_##NAME.ptr = (void *)(__u64)pattern_reg(__i);        \
		__x86_##NAME##_tag = ORA_MARK_TAG;                         \
		__i++;                                                     \
	} while (0);

#define ORA_SEED_ALL()                                                     \
	do {                                                               \
		unsigned __i = 0;                                          \
		X86_SIM_L_FOR_EACH_GPR(ORA_SEED)                           \
	} while (0)

/* Public ABI table determines arguments/results independently of the C bodies. */

static void reset_call(void)
{
    unsigned i;
    ora_called = 0;
    ora_argc = 0;
    for (i = 0; i < 5; i++) ora_arguments[i] = 0;
}

static void check_arguments(__u64 id, void *before[16])
{
    static const unsigned registers[5] = {7, 6, 2, 1, 8};
    __u64 raw[5], expected[5] = {0};
    unsigned i, count;
    for (i = 0; i < 5; i++) raw[i] = (__u64)(uintptr_t)before[registers[i]];
    count = ora_x86_armed(id) ? ora_expected_arguments(id, raw, expected) : 0;
    if (ora_called != (ora_x86_armed(id) ? id : 0) || ora_argc != count) {
        printf("MISMATCH helper identity/arity id=%llu called=%u argc=%u want=%u\n",
               (unsigned long long)id, ora_called, ora_argc, count);
        failures++;
    }
    for (i = 0; i < count; i++) {
        if (ora_arguments[i] != expected[i]) {
            printf("MISMATCH helper argument id=%llu arg=%u got=%llx want=%llx\n",
                   (unsigned long long)id, i, (unsigned long long)ora_arguments[i],
                   (unsigned long long)expected[i]);
            failures++;
        }
    }
}

/* SysV caller registers receive the host model's unspecified-value representative;
 * preserved registers retain their full bits and provenance. RAX is checked below. */
static void check_frame(__u64 id, void *before[16], void *after[16],
                        __u8 btag[16], __u8 atag[16])
{
    for (unsigned j = 1; j < 16; j++) {
        int caller = j == 1 || j == 2 || j == 6 || j == 7 || (j >= 8 && j <= 11);
        int clobbered = ora_x86_armed(id) && caller;
        void *value = clobbered ? (void *)0 : before[j];
        __u8 tag = clobbered ? X86_SIM_TAG_SCALAR : btag[j];
        if (after[j] != value || atag[j] != tag) {
            printf("MISMATCH helper frame id=%llu register=%s\n", id, gpr_names[j]);
            failures++;
        }
    }
}

/* Drive `X86_SIM_BPF_CALL_ID(id)`, capture the whole register file, and check
 * that RAX and the caller/callee frame follow the independent ABI model. */
static void check_id(unsigned long long id)
{
	void *before[16], *after[16];
	__u8 btag[16], atag[16];
	__u64 want_val;
	__u8 want_tag;

	cases++;
	{
		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		(void)__x86_stack_mem;

		ORA_SEED_ALL();
		ORA_SNAPSHOT(before, btag);

		reset_call();
		X86_SIM_BPF_CALL_ID((__u64)id);
		check_arguments(id, before);
		ORA_SNAPSHOT(after, atag);

		check_frame(id, before, after, btag, atag);

		want_val = ora_x86_armed(id) ? ora_expected_result(id) : (__u64)(uintptr_t)before[0];
		want_tag = ora_x86_armed(id) ? (ora_pointer_result(id) ? X86_SIM_TAG_MAP_VALUE : X86_SIM_TAG_SCALAR) : btag[0];
		if ((__u64)(long)after[0] != want_val || atag[0] != want_tag) {
			printf("MISMATCH id=%llu rax=0x%llx tag=%u want=0x%llx "
			       "tag=%u\n", id,
			       (unsigned long long)(__u64)(long)after[0],
			       atag[0], (unsigned long long)want_val,
			       want_tag);
			failures++;
		}
	}
}

/* Drive `X86_SIM_BPF_CALL_REG(REG)` with the register planted to `id`, and
 * check the same RAX result. This is the exact body the chain's
 * `X86_OP_CALL_REG` arm runs. */
static void check_reg(unsigned reg, unsigned long long id)
{
	void *before[16], *after[16];
	__u8 btag[16], atag[16];
	__u64 want_val;
	__u8 want_tag;
	unsigned long long eff_id = (reg < 16U) ? id : 0ULL;

	cases++;
	{
		X86_SIM_L_DECLARE_STATE();
		X86_SIM_L_DECLARE_STACK();
		(void)__x86_cf;
		(void)__x86_zf;
		(void)__x86_sf;
		(void)__x86_of;
		(void)__x86_xmm0_lo;
		(void)__x86_xmm0_hi;
		(void)__x86_sim_ret_addr;
		(void)__x86_stack_mem;

		ORA_SEED_ALL();
		X86_SIM_L_WRITE_REG_PTR_TAG(reg, (void *)(__u64)id,
					    ORA_MARK_TAG);
		ORA_SNAPSHOT(before, btag);
		reset_call();
		X86_SIM_BPF_CALL_REG(reg);
		check_arguments(eff_id, before);
		ORA_SNAPSHOT(after, atag);

		check_frame(eff_id, before, after, btag, atag);

		want_val = ora_x86_armed(eff_id) ? ora_expected_result(eff_id) : (__u64)(uintptr_t)before[0];
		want_tag = ora_x86_armed(eff_id) ? (ora_pointer_result(eff_id) ? X86_SIM_TAG_MAP_VALUE : X86_SIM_TAG_SCALAR) : btag[0];
		if ((__u64)(long)after[0] != want_val || atag[0] != want_tag) {
			printf("MISMATCH reg=%u id=%llu rax=0x%llx tag=%u "
			       "want=0x%llx tag=%u\n", reg, id,
			       (unsigned long long)(__u64)(long)after[0],
			       atag[0], (unsigned long long)want_val,
			       want_tag);
			failures++;
		}
	}
}

int main(void)
{
#ifdef ORA_NEGATIVE_HELPER
    X86_SIM_L_DECLARE_STATE();
    X86_SIM_L_DECLARE_STACK();
    X86_SIM_BPF_CALL_ID(ORA_NEGATIVE_HELPER);
    return 0;
#else
	unsigned long long id;
	unsigned reg;

	/* The generated count and the slot selector must line up with the
	 * sim's hand-written ladder. */
	cases++;
	if (KPROG_X86_HELPER_COUNT != 68U ||
	    KPROG_X86_HELPER_SLOT(1ULL) != 0U ||
	    KPROG_X86_HELPER_SLOT(5ULL) != 4U ||
	    KPROG_X86_HELPER_SLOT(13ULL) != KPROG_X86_HELPER_SLOT_NONE) {
		printf("MISMATCH helper dispatch constant drift\n");
		failures++;
	}

	/* Drive the ladder over the whole named id space and a way past it. */
	for (id = 0; id <= 256ULL; id++)
		check_id(id);

	/* Drive the routed call-register body for every register number, each
	 * planted to every armed id plus a default id. */
	{
		static const unsigned long long ids[] = {
			0ULL, 1ULL, 2ULL, 3ULL, 4ULL, 5ULL, 6ULL, 7ULL, 8ULL, 9ULL, 10ULL, 11ULL, 12ULL, 13ULL, 14ULL, 15ULL, 16ULL, 20ULL, 21ULL, 22ULL, 23ULL, 25ULL, 26ULL, 27ULL, 28ULL, 32ULL, 35ULL, 36ULL, 37ULL, 38ULL, 39ULL, 43ULL, 44ULL, 45ULL, 46ULL, 50ULL, 54ULL, 58ULL, 65ULL, 67ULL, 68ULL, 69ULL, 80ULL, 85ULL, 86ULL, 87ULL, 88ULL, 95ULL, 99ULL, 109ULL, 112ULL, 113ULL, 114ULL, 115ULL, 118ULL, 122ULL, 124ULL, 125ULL, 130ULL, 148ULL, 152ULL, 155ULL, 158ULL, 160ULL, 173ULL, 174ULL, 175ULL, 181ULL, 184ULL, 189ULL, 193ULL, 194ULL, 18446744073709551615ULL
		};
		size_t ii;

		for (reg = 0; reg <= 0xffU; reg++)
			for (ii = 0; ii < sizeof(ids) / sizeof(ids[0]); ii++)
				check_reg(reg, ids[ii]);
	}

	if (failures != 0) {
		printf("x86 helper dispatch route host cross-check: FAIL (%d)\n",
		       failures);
		return 1;
	}
	printf("x86 helper dispatch route host cross-check: OK (%lu cases)\n",
	       cases);
	return 0;
#endif
}
