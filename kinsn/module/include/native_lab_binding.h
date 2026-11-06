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
 * The entire frozen read-only map value must equal that native byte extent.
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

#define NATIVE_LAB_BINDING_VERSION 2U
#define NATIVE_LAB_ARCH_X86 1U
#define NATIVE_LAB_ARCH_ARM64 2U
/* Inline kinsn entry at byte zero; context in the architecture's BPF r1. */
#define NATIVE_LAB_INLINE_ABI_VERSION 1U

/* Native-endian, fixed 96-byte record, followed by exact native bytes,
 * relocation records (16 bytes each), then proof bpf_insns (8 bytes each).
 * The kernel compares all three against the snapshot before sealing it.
 */
struct native_lab_binding {
	__u32 version;
	__u32 arch;
	__u32 entry_offset;
	__u32 abi_version;
	__u32 abi_mask;
	__u32 blob_id;
	__u32 chunk_offset;
	__u32 total_native_size;
	__u32 chunk_count;
	__u32 native_size;
	__u32 reloc_count;
	__u32 proof_insns;
	__u32 prog_type;
	__u32 expected_attach_type;
	__u32 snapshot_generation;
	__u32 reserved;
	__u32 prog_flags;
	__u32 attach_btf_id;
	__u32 attach_btf_obj_id;
	__u32 attach_prog_id;
	__u32 prog_ifindex;
	__u32 source_prog_id;
	__u32 gpl_compatible;
	__u32 context_reserved;
};

static inline int native_lab_binding_validate(
	const struct native_lab_binding *b, __u32 arch, __u32 blob_id,
	__u32 native_size, __u32 reloc_count, __u32 proof_insns,
	__u32 generation)
{
	if (b->version != NATIVE_LAB_BINDING_VERSION || b->arch != arch ||
	    b->abi_version != NATIVE_LAB_INLINE_ABI_VERSION ||
	    b->entry_offset || b->reserved || (b->abi_mask & ~0xfU) ||
	    b->context_reserved || !b->source_prog_id || b->gpl_compatible > 1)
		return -EINVAL;
	if (!b->chunk_count || b->chunk_count > 512 ||
	    b->blob_id != blob_id || blob_id >= b->chunk_count ||
	    !native_size || !proof_insns || !b->prog_type ||
	    b->native_size != native_size || b->reloc_count != reloc_count ||
	    b->proof_insns != proof_insns ||
	    b->chunk_offset > b->total_native_size ||
	    native_size > b->total_native_size - b->chunk_offset ||
	    (!blob_id && b->chunk_offset) ||
	    (blob_id + 1 == b->chunk_count &&
	     native_size != b->total_native_size - b->chunk_offset))
		return -EINVAL;
	if (arch == NATIVE_LAB_ARCH_ARM64 &&
	    ((b->chunk_offset | b->total_native_size | native_size) & 3))
		return -EINVAL;
	if (!generation || generation == (__u32)-1 ||
	    b->snapshot_generation != generation)
		return -ESTALE;
	return 0;
}

/* Called under the blob mutex by both verifier instantiation and every JIT
 * sizing/emission pass. Any mutation after the seal advances generation.
 */
static inline int native_lab_binding_use(
	const struct native_lab_binding *b, __u32 arch, __u32 blob_id,
	__u32 native_size, __u32 reloc_count, __u32 proof_insns,
	__u32 generation, __u32 abi_mask)
{
	int err = native_lab_binding_validate(b, arch, blob_id, native_size,
					    reloc_count, proof_insns,
					    b->snapshot_generation);
	if (err)
		return err;
	if (generation != b->snapshot_generation + 1)
		return -ESTALE;
	if (abi_mask != b->abi_mask)
		return -EINVAL;
	return 0;
}

/* Compare the envelope against kernel-owned bytes before advancing generation.
 * Counts have already been checked by native_lab_binding_validate().
 */
static inline int native_lab_binding_snapshot(
	const struct native_lab_binding *b, const unsigned char *data,
	__u64 size, const void *native, const void *relocs, const void *proof)
{
	__u64 offset = sizeof(*b);
	__u64 reloc_bytes = (__u64)b->reloc_count * 16;
	__u64 proof_bytes = (__u64)b->proof_insns * 8;

	if (size != offset + b->native_size + reloc_bytes + proof_bytes)
		return -EINVAL;
	if (memcmp(data + offset, native, b->native_size))
		return -EINVAL;
	offset += b->native_size;
	if (reloc_bytes && memcmp(data + offset, relocs, reloc_bytes))
		return -EINVAL;
	offset += reloc_bytes;
	if (memcmp(data + offset, proof, proof_bytes))
		return -EINVAL;
	return 0;
}

#endif
