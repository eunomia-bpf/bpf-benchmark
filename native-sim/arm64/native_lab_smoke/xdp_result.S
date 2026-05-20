// SPDX-License-Identifier: GPL-2.0
//
// Tiny native_kernel smoke blob for arm64.
//
// Contract when emitted from run-native-kernel's XDP stub:
//   x0 = struct xdp_buff *
//   x7 = BPF r0 / eventual program retval
// The blob writes 12345678 to the packet result prefix and falls through to
// the BPF EXIT instruction.

	.text
	.global arm64_native_kernel_xdp_result
	.type arm64_native_kernel_xdp_result, %function
arm64_native_kernel_xdp_result:
	ldr	x1, [x0]
	movz	x2, #0x614e
	movk	x2, #0x00bc, lsl #16
	str	x2, [x1]
	movz	x7, #2
	.size arm64_native_kernel_xdp_result, . - arm64_native_kernel_xdp_result
