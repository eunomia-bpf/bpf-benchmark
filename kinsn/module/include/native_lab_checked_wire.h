/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_CHECKED_WIRE_H
#define NATIVE_LAB_CHECKED_WIRE_H
#include "native_lab_binding.h"

/* Native-endian on the supported little-endian x86/arm64 hosts. Followed by
 * prog_insns bpf_insns, regions region records, map_refs map records and
 * helper_refs helper records, in that order. This is diagnostic evidence of
 * the expanded virtual program, before proof restoration/context conversion.
 */
struct native_lab_checked_header {
	__u32 version;
	__u32 prog_insns;
	__u32 regions;
	__u32 map_refs;
	__u32 helper_refs;
	__u32 actual_generation;
	struct native_lab_binding binding;
};
struct native_lab_checked_region { __u32 start, insns; __u64 payload; };
struct native_lab_checked_map {
	__u32 insn, id, value_offset, type, key_size, value_size, max_entries, flags;
	__u64 pointer;
};
struct native_lab_checked_helper { __u32 insn, id; __u64 function; };
#endif
