/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_BINDING_H
#define NATIVE_LAB_BINDING_H

#include <linux/types.h>
#include <linux/errno.h>
#ifdef __KERNEL__
#include <linux/string.h>
#else
#include <string.h>
#endif

#define NATIVE_LAB_RELOC_MAP_POINTER 5U
#define NATIVE_LAB_RELOC_MAP_VALUE 6U
#define NATIVE_LAB_RELOC_HELPER_POINTER 7U
/* Metadata only: offset=0, target=map_id | (global native data offset << 32).
 * The service constructs its read-only map from this native byte extent.
 */
#define NATIVE_LAB_RELOC_READONLY_DATA 8U
/* Metadata only: offset is the actual ARM STXR/STLXR byte position in the
 * chunk; target = (source byte PC << 32) | final chunk's proof instruction.
 */
#define NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE 9U

static inline int native_lab_reloc_patch_size(__u32 kind)
{
	switch (kind) {
	case 1: return 5;
	case 2: return 16;
	case 3: case 4: return 4;
	case 5: case 6: case 7: return 8;
	case 8: case 9: return 0;
	default: return -EINVAL;
	}
}

#define NATIVE_LAB_ARCH_X86 1U
#define NATIVE_LAB_ARCH_ARM64 2U

#endif
