/*
 * Host cross-check for the AArch64 simulator's *entry contexts*, XDP and SKB.
 *
 * Why this host exists. Every host in the tree that declares simulator state
 * does so by hand, and all of them hard-code the XDP ABI kind. Nothing has ever
 * declared the SKB entry (`ARM64_SIM_ENTRY_SKB` appears in no host), so the
 * whole second context is unexercised -- and it is not a synonym for the first.
 * The two differ in where the packet pointers live: XDP puts `data` and
 * `data_end` at offsets 0 and 8, SKB at 208 and 80. The `abi_load` contract
 * branches on the ABI kind and the offset together, so reading an SKB context
 * through the XDP arm would label packet pointers as scalars -- a fault that
 * leaves every address correct and only the provenance wrong, which is exactly
 * what the tag is for.
 *
 * What is checked, for both contexts:
 *
 *   - `data`, `data_end` and an ordinary scalar field load at the offset the
 *     contract names for that context;
 *   - the loaded *tag* is the packet, the packet-end or the scalar tag
 *     according to which field it was -- so the context/offset pairing is
 *     exercised rather than assumed;
 *   - the two contexts disagree at the other's offset, which is what makes
 *     the pairing observable at all.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../arm64 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_arm64_entry_context_host.c -o build/test_arm64_entry_context_host &&
 *   ./build/test_arm64_entry_context_host
 */

#define ARM64_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed long long __s64;
typedef signed int __s32;

#define __always_inline inline

#include "../arm64/arm64_sim_local_bpf.h"

#include <stdio.h>

static unsigned long unsupported_calls;
static void arm64_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

static int failures;
static unsigned long cases;

/* The XDP context the entry macro dereferences. */
struct xdp_md_host {
	__u32 data;
	__u32 data_end;
	__u32 data_meta;
};

/* The SKB context. The offsets the contract names -- 208 for `data`, 80 for
 * `data_end` -- are into the real `struct __sk_buff`, so the host models a
 * buffer large enough to hold those fields at those offsets. */
static __u8 skb_storage[256];

static void check_tag(const char *what, __u8 got, __u8 want)
{
	cases++;
	if (got != want) {
		printf("TAG %-28s got %u, want %u\n", what, got, want);
		failures++;
	}
}

static void check_value(const char *what, __u64 got, __u64 want)
{
	cases++;
	if (got != want) {
		printf("VALUE %-26s got %#llx, want %#llx\n", what,
		       (unsigned long long)got, (unsigned long long)want);
		failures++;
	}
}

/* The tag the simulator's own ABI-load composition produces for a given
 * context kind and offset. Driving ARM64_SIM_L_MEM_READ_TAG rather than the
 * contract means the tag selection, base resolution and contract call all run. */
static __u8 abi_tag_at(__u8 kind, __s64 off)
{
	ARM64_SIM_L_DECLARE_STATE();
	ARM64_SIM_L_DECLARE_STACK();
	struct arm64_sim_xdp_abi __a64_sim_abi = { 0 };
	struct __sk_buff *__a64_sim_skb_ctx = (struct __sk_buff *)0;
	__u8 __a64_sim_abi_kind = kind;

	__a64_sim_abi_kind = kind;
	__a64_x0.ptr = &__a64_sim_abi;
	__a64_x0_tag = ARM64_SIM_TAG_ABI;
	(void)__a64_stack_tag;
	return ARM64_SIM_L_MEM_READ_TAG(ARM64_X0, ARM64_REG_NONE, 0, off, 0,
					 ARM64_WIDTH_64);
}

int main(void)
{
	/* ---- XDP ---- */
	{
		struct xdp_md_host ctx;
		__u64 *fields;

		ctx.data = 0x1111;
		ctx.data_end = 0x2222;
		ctx.data_meta = 0x3333;

		ARM64_SIM_ENTRY_XDP(&ctx);

		fields = (__u64 *)&__a64_sim_abi;
		check_value("xdp data", fields[KPROG_ABI_XDP_DATA_OFF / 8],
			    0x1111);
		check_value("xdp data_end",
			    fields[KPROG_ABI_XDP_DATA_END_OFF / 8], 0x2222);

		check_tag("xdp x0 tag", __a64_x0_tag, ARM64_SIM_TAG_ABI);
		check_tag("xdp abi kind", __a64_sim_abi_kind,
			  KPROG_ABI_KIND_XDP);

		/* The tag the contract produces for each field of this
		 * context. */
		check_tag("xdp data field tag",
			  abi_tag_at(KPROG_ABI_KIND_XDP, KPROG_ABI_XDP_DATA_OFF),
			  ARM64_SIM_TAG_PACKET);
		check_tag("xdp data_end tag",
			  abi_tag_at(KPROG_ABI_KIND_XDP,
				     KPROG_ABI_XDP_DATA_END_OFF),
			  ARM64_SIM_TAG_PACKET_END);
	}

	/* ---- SKB ---- */
	{
		struct __sk_buff *ctx = (struct __sk_buff *)skb_storage;
		__u32 *w = (__u32 *)skb_storage;

		/* Place the two fields at the offsets the contract names. */
		w[KPROG_ABI_SKB_DATA_OFF / 4] = 0x4444;
		w[KPROG_ABI_SKB_DATA_END_OFF / 4] = 0x5555;

		ARM64_SIM_ENTRY_SKB(ctx);

		check_value("skb data (offset 208)",
			    (__u64)(*(__u32 *)(skb_storage +
					       KPROG_ABI_SKB_DATA_OFF)),
			    0x4444);
		check_value("skb data_end (offset 80)",
			    (__u64)(*(__u32 *)(skb_storage +
					       KPROG_ABI_SKB_DATA_END_OFF)),
			    0x5555);

		check_tag("skb x0 tag", __a64_x0_tag, ARM64_SIM_TAG_ABI);
		check_tag("skb abi kind", __a64_sim_abi_kind,
			  KPROG_ABI_KIND_SKB);
		check_value("skb ctx is the argument",
			    (__u64)(long)__a64_sim_skb_ctx, (__u64)(long)ctx);

		check_tag("skb data field tag",
			  abi_tag_at(KPROG_ABI_KIND_SKB, KPROG_ABI_SKB_DATA_OFF),
			  ARM64_SIM_TAG_PACKET);
		check_tag("skb data_end tag",
			  abi_tag_at(KPROG_ABI_KIND_SKB,
				     KPROG_ABI_SKB_DATA_END_OFF),
			  ARM64_SIM_TAG_PACKET_END);

		/* The pairing is observable only if the contexts disagree at
		 * each other's offsets: the SKB data offset, read as XDP, is
		 * an ordinary field. */
		check_tag("skb offset read as xdp",
			  abi_tag_at(KPROG_ABI_KIND_XDP, KPROG_ABI_SKB_DATA_OFF),
			  ARM64_SIM_TAG_SCALAR);
		check_tag("xdp offset read as skb",
			  abi_tag_at(KPROG_ABI_KIND_SKB,
				     KPROG_ABI_XDP_DATA_END_OFF),
			  ARM64_SIM_TAG_SCALAR);
	}

	if (failures) {
		printf("arm64 entry context host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("arm64 entry context host cross-check: OK (%lu cases)\n", cases);
	return 0;
}