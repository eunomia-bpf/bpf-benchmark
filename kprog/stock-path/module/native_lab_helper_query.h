/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_HELPER_QUERY_H
#define NATIVE_LAB_HELPER_QUERY_H
#include <linux/types.h>

/* Native-endian trusted-service request, followed by u32 helper IDs.
 * The reply contains one u64 function address per ID; zero means unavailable.
 * verifier_ops is the sole running kernel's bpf_verifier_ops table address.
 */
struct native_lab_helper_query {
	__u64 verifier_ops;
	__u32 program_fd;
	__u32 program_type;
};
#endif
