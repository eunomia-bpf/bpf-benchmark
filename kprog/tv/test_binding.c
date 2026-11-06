/* Regression purposes: reject entry/ABI/metadata drift at sealing and use;
 * reject any native, relocation or proof-byte mismatch; detect wire-layout drift.
 * These are the same functions called by both production kernel modules.
 */
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include "../../kinsn/module/include/native_lab_binding.h"

static void layout(void)
{
#define OFFSET(field, expected) _Static_assert(offsetof(struct native_lab_binding, field) == expected, #field)
	OFFSET(version, 0); OFFSET(arch, 4); OFFSET(entry_offset, 8);
	OFFSET(abi_version, 12); OFFSET(abi_mask, 16); OFFSET(blob_id, 20);
	OFFSET(chunk_offset, 24); OFFSET(total_native_size, 28);
	OFFSET(chunk_count, 32); OFFSET(native_size, 36); OFFSET(reloc_count, 40);
	OFFSET(proof_insns, 44); OFFSET(prog_type, 48);
	OFFSET(expected_attach_type, 52); OFFSET(snapshot_generation, 56);
	OFFSET(reserved, 60); OFFSET(prog_flags, 64); OFFSET(attach_btf_id, 68);
	OFFSET(attach_btf_obj_id, 72); OFFSET(attach_prog_id, 76);
	OFFSET(prog_ifindex, 80); OFFSET(source_prog_id, 84);
	OFFSET(gpl_compatible, 88); OFFSET(context_reserved, 92);
	_Static_assert(sizeof(struct native_lab_binding) == 96, "binding wire size");
#undef OFFSET
}

static void reject_drift(__u32 arch)
{
	struct native_lab_binding good = {
		.version = NATIVE_LAB_BINDING_VERSION, .arch = arch, .abi_version = 1, .abi_mask = 3,
		.chunk_count = 1, .native_size = 8, .total_native_size = 8,
		.reloc_count = 1, .proof_insns = 2, .prog_type = 6,
		.snapshot_generation = 10, .source_prog_id = 7, .gpl_compatible = 1,
	};
	struct native_lab_binding b;
#define SEAL(record) native_lab_binding_validate(&(record), arch, 0, 8, 1, 2, 10)
#define USE(record, generation, mask) native_lab_binding_use(&(record), arch, 0, 8, 1, 2, generation, mask)
#define REJECT(field, value, error) do { b = good; b.field = value; \
	assert(SEAL(b) == error); assert(USE(b, 11, 3) == error); } while (0)
	assert(SEAL(good) == 0);
	assert(USE(good, 11, 3) == 0);
	REJECT(version, NATIVE_LAB_BINDING_VERSION + 1, -EINVAL);
	REJECT(arch, arch == 1 ? 2 : 1, -EINVAL);
	REJECT(entry_offset, 4, -EINVAL);
	REJECT(abi_version, 2, -EINVAL);
	REJECT(abi_mask, 16, -EINVAL);
	REJECT(blob_id, 1, -EINVAL);
	REJECT(chunk_offset, 1, -EINVAL);
	REJECT(total_native_size, 7, -EINVAL);
	REJECT(total_native_size, 9, -EINVAL);
	REJECT(chunk_count, 0, -EINVAL);
	REJECT(chunk_count, 513, -EINVAL);
	REJECT(native_size, 9, -EINVAL);
	REJECT(reloc_count, 2, -EINVAL);
	REJECT(proof_insns, 1, -EINVAL);
	REJECT(prog_type, 0, -EINVAL);
	REJECT(reserved, 1, -EINVAL);
	REJECT(source_prog_id, 0, -EINVAL);
	REJECT(gpl_compatible, 2, -EINVAL);
	REJECT(context_reserved, 1, -EINVAL);
	b = good; b.snapshot_generation = 9;
	assert(SEAL(b) == -ESTALE);
	assert(USE(b, 11, 3) == -ESTALE);
	assert(USE(good, 10, 3) == -ESTALE); /* unsealed */
	assert(USE(good, 12, 3) == -ESTALE); /* changed native/proof/relocs */
	assert(USE(good, 11, 2) == -EINVAL); /* supported but different ABI mask */
	b = good; b.snapshot_generation = (__u32)-1;
	assert(USE(b, 0, 3) == -ESTALE); /* wrap cannot revive a seal */
	b = good; b.snapshot_generation = (__u32)-2;
	assert(USE(b, (__u32)-1, 3) == 0); /* last generation still usable */
	assert(native_lab_binding_validate(&good, arch, 0, 0, 1, 2, 10) == -EINVAL);
	assert(native_lab_binding_validate(&good, arch, 0, 8, 1, 0, 10) == -EINVAL);
	assert(native_lab_binding_validate(&good, arch, 0, 8, 1, 2, 0) == -ESTALE);
#undef SEAL
#undef USE
#undef REJECT
	/* A non-first chunk must end at the declared program end if it is last. */
	b = good; b.blob_id = 1; b.chunk_count = 2;
	b.chunk_offset = 8; b.total_native_size = 16;
	assert(native_lab_binding_validate(&b, arch, 1, 8, 1, 2, 10) == 0);
	b.chunk_offset = (__u32)-1;
	assert(native_lab_binding_validate(&b, arch, 1, 8, 1, 2, 10) == -EINVAL);
}

static void reject_bytes(void)
{
	struct native_lab_binding b = { .native_size = 8, .reloc_count = 1, .proof_insns = 2 };
	unsigned char data[sizeof(b) + 8 + 16 + 16] = {0};
	unsigned char native[8] = {1};
	unsigned char relocs[16] = {2};
	unsigned char proof[16] = {3};
	memcpy(data, &b, sizeof(b));
	memcpy(data + sizeof(b), native, sizeof(native));
	memcpy(data + sizeof(b) + 8, relocs, sizeof(relocs));
	memcpy(data + sizeof(b) + 24, proof, sizeof(proof));
	assert(native_lab_binding_snapshot(&b, data, sizeof(data), native, relocs, proof) == 0);
	for (size_t i = sizeof(b); i < sizeof(data); i++) {
		data[i] ^= 1;
		assert(native_lab_binding_snapshot(&b, data, sizeof(data), native, relocs, proof) == -EINVAL);
		data[i] ^= 1;
	}
	assert(native_lab_binding_snapshot(&b, data, sizeof(data)-1, native, relocs, proof) == -EINVAL);
	assert(native_lab_binding_snapshot(&b, data, sizeof(data)+1, native, relocs, proof) == -EINVAL);
}

int main(void)
{
	layout();
	reject_drift(NATIVE_LAB_ARCH_X86);
	reject_drift(NATIVE_LAB_ARCH_ARM64);
	reject_bytes();
	puts("binding entry/ABI/metadata/generation and exact-byte rejection tests: PASS");
	return 0;
}
