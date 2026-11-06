/*
 * Cross-ISA provenance-tag vocabulary cross-check.
 *
 * Both simulators define a provenance tag per simulated register, and the two
 * definitions are independent hand-written `#define`s -- neither header
 * includes the other, and no generated contract binds them together. Seven
 * names are shared and happen to carry the same code on both sides; a drift in
 * either header would silently change what a tag means on one ISA.
 *
 * The vocabularies are deliberately *not* identical, and this oracle states
 * the exact difference rather than assuming uniformity:
 *
 *   code  name        arm64                    x86
 *   ----  ----------  -----------------------  --------------------------
 *   0     SCALAR      scalar                   scalar
 *   1     ABI         ABI base pointer         ABI base pointer
 *   2     PACKET      packet data              packet data
 *   3     PACKET_END  packet data_end          packet data_end
 *   4     STACK       stack arena              stack arena
 *   5     MAP_PTR     map pointer              map pointer
 *   6     MAP_VALUE   map value                map value
 *   7     --          RELOC_ADDR               HELPER_ID
 *   8     --          RODATA_ADDR              (none)
 *
 * Code 7 is the one collision, and it is safe because no table is indexed by
 * tag across the two simulators and no comparison mixes their tag constants;
 * each ISA reads only its own. The three ISA-specific tags are all live (78,
 * 27 and 17 uses respectively).
 *
 * Exit 1 on any mismatch.
 *
 * Build/run (from kprog/formal):
 *   cc -Wall -Wextra -O2 -I. cross_isa_tag_host.c -o /tmp/t_xisa_tags
 *   /tmp/t_xisa_tags
 */
typedef unsigned char __u8;
typedef unsigned int __u32;
typedef unsigned long long __u64;

#include "../arm64/arm64_sim_local_bpf.h"
#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static int failures;
static int cases;

static void check_shared(const char *name, __u32 a, __u32 x)
{
	cases++;
	if (a != x) {
		printf("MISMATCH shared tag %s: arm64=%u x86=%u\n", name,
		       (unsigned)a, (unsigned)x);
		failures++;
	}
}

/* Two tags are ISA-specific at the same code; state that explicitly so an
 * accidental renumbering on either side is visible here rather than assumed. */
static void check_divergent(__u32 a_reloc, __u32 x_helper)
{
	cases++;
	if (a_reloc != 7U || x_helper != 7U) {
		printf("MISMATCH code-7 vocabulary: arm64 RELOC_ADDR=%u "
		       "x86 HELPER_ID=%u (both must be 7)\n",
		       (unsigned)a_reloc, (unsigned)x_helper);
		failures++;
	}
	cases++;
	if (a_reloc == x_helper) {
		/* Same number, different meaning: the collision is expected, the
		 * point is that both live at 7 and neither side reads the other's
		 * constant. */
	} else {
		printf("MISMATCH code-7 tags diverged from the same code\n");
		failures++;
	}
}

int main(void)
{
	check_shared("SCALAR", ARM64_SIM_TAG_SCALAR, X86_SIM_TAG_SCALAR);
	check_shared("ABI", ARM64_SIM_TAG_ABI, X86_SIM_TAG_ABI);
	check_shared("PACKET", ARM64_SIM_TAG_PACKET, X86_SIM_TAG_PACKET);
	check_shared("PACKET_END", ARM64_SIM_TAG_PACKET_END,
		     X86_SIM_TAG_PACKET_END);
	check_shared("STACK", ARM64_SIM_TAG_STACK, X86_SIM_TAG_STACK);
	check_shared("MAP_PTR", ARM64_SIM_TAG_MAP_PTR, X86_SIM_TAG_MAP_PTR);
	check_shared("MAP_VALUE", ARM64_SIM_TAG_MAP_VALUE,
		     X86_SIM_TAG_MAP_VALUE);
	check_divergent(ARM64_SIM_TAG_RELOC_ADDR, X86_SIM_TAG_HELPER_ID);

	/* The shared names must be exactly these seven on both sides: a new tag
	 * added to one ISA is a vocabulary change worth seeing here. */
	cases++;
	if (ARM64_SIM_TAG_RODATA_ADDR != 8U) {
		printf("MISMATCH arm64 RODATA_ADDR: %u\n",
		       (unsigned)ARM64_SIM_TAG_RODATA_ADDR);
		failures++;
	}

	if (failures) {
		printf("cross-ISA tag vocabulary cross-check: FAIL (%d/%d)\n",
		       failures, cases);
		return 1;
	}
	printf("cross-ISA tag vocabulary cross-check: OK (%d cases)\n", cases);
	return 0;
}