// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 native-code lab kinsn.
 *
 * Test-only escape hatch matching the x86 native_lab shape: userspace uploads
 * an AArch64 instruction stream and an optional verifier proof. A non-zero
 * generation in the sidecar binds verifier and JIT callbacks to one upload
 * snapshot; generation zero is the explicit trusted-native lower-bound mode.
 *
 * Safety: this intentionally bypasses verifier guarantees for the emitted
 * native instructions. Do not load on production kernels.
 *
 * ABI contract:
 *  - Blob length must be a non-zero multiple of 4 bytes.
 *  - Blob is emitted in the middle of a JITted BPF function and must fall
 *    through to the next BPF instruction; do not end it with RET.
 *  - Sidecar bits 4..7 mirror x86 native_lab: request BPF r6..r9 use so
 *    the arm64 BPF JIT saves x19..x22 for raw native code.
 *  - BPF r0 is arm64 x7 in the kernel BPF JIT. Set x7 before falling
 *    through if the native blob wants to choose the BPF program retval.
 *  - BPF r1 is arm64 x0 on entry, so an XDP native blob sees the xdp_buff
 *    pointer in x0 when the stub calls this kfunc.
 *  - Kernel-mode arm64 native-link blobs run on the BPF JIT stack. The
 *    wrapper declares 512 bytes of stack use so the BPF JIT reserves enough
 *    frame space for native compiler stack references.
 */

#include <linux/capability.h>
#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/bpf_verifier.h>
#include <linux/debugfs.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/unaligned.h>
#include <asm/cpufeature.h>

#include "kinsn_common.h"

#include "native_lab_binding.h"
#define NATIVE_LAB_BINDING_ARCH NATIVE_LAB_ARCH_ARM64
#include "native_lab_trusted.h"

#define NATIVE_LAB_MAX_BLOBS		512
#define NATIVE_LAB_ABI_X19		(1U << 0)
#define NATIVE_LAB_ABI_X20		(1U << 1)
#define NATIVE_LAB_ABI_X21		(1U << 2)
#define NATIVE_LAB_ABI_X22		(1U << 3)
#define NATIVE_LAB_ABI_MASK		(NATIVE_LAB_ABI_X19 | \
					 NATIVE_LAB_ABI_X20 | \
					 NATIVE_LAB_ABI_X21 | \
					 NATIVE_LAB_ABI_X22)
/*
 * Keep arm64 native chunks large enough that normal programs are emitted as a
 * single kinsn callback. The arm64 BPF JIT allocates the callback scratch
 * buffer from this descriptor's max_emit_bytes.
 */
#define NATIVE_LAB_MAX_BLOB_BYTES	(16 * 1024)
#define NATIVE_LAB_MAX_PROOF_INSNS	1000000
#define NATIVE_LAB_STACK_RESERVE_BYTES	512
/*
 * Stage 2 side-band relocations:
 *
 * Userspace emits near helper calls as a single-instruction slot:
 *
 *   bl #0
 *
 * Once the BPF JIT has chosen the final RX address, this module patches the
 * slot to `bl target`. The legacy four-instruction slot is still accepted for
 * older cached blobs:
 *
 *   bl #0; nop; nop; nop
 *
 * The legacy slot patches either to `bl target; nop; nop; nop` or, for
 * targets outside the BL26 range, the same fixed-length `movn/movk/movk;
 * blr x10` sequence used by the arm64 BPF JIT for far helper calls.
 *
 * Userspace emits TPIDR_EL1 as the per-CPU offset placeholder. The module
 * patches it to TPIDR_EL2 on VHE hosts, matching arch/arm64's BPF JIT.
 */
#define NATIVE_LAB_RELOC_HELPER_CALL_ARM64	2
#define NATIVE_LAB_RELOC_HELPER_CALL_ARM64_BL26	3
#define NATIVE_LAB_RELOC_ARM64_PERCPU_MRS	4
#define NATIVE_LAB_MAX_RELOCS			512
#define A64_BL_IMM26_PLACEHOLDER		0x94000000U
#define A64_BL26_IMM_MASK			0x03ffffffU
#define A64_NOP					0xd503201fU
#define A64_BLR_X10				0xd63f0140U
#define A64_MRS_X10_TPIDR_EL1			0xd538d08aU
#define A64_MRS_X10_TPIDR_EL2			0xd53cd04aU
#define A64_TMP_REG				10U
#define NATIVE_LAB_ARM64_HELPER_CALL_WORDS	4
#define NATIVE_LAB_ARM64_BL26_CALL_WORDS	1

struct native_lab_reloc_record {
	__u32 offset;   /* byte offset of the BL26 helper call placeholder */
	__u32 kind;     /* NATIVE_LAB_RELOC_* */
	__u64 target;   /* absolute kernel address */
};

struct native_blob {
	u8 *bytes;
	size_t len;
	struct native_lab_reloc_record *relocs;
	size_t reloc_count;
	struct bpf_insn *proof;
	size_t proof_len;
	u32 generation;
	struct native_lab_binding binding;
	u32 *bound_generations;
	struct bpf_map **bound_maps;
	u32 bound_map_count;
	struct bpf_prog *bound_source;
	struct bpf_prog *bound_target;
	struct native_lab_trusted_capsule *trusted;
};

static struct native_blob blobs[NATIVE_LAB_MAX_BLOBS];
static DEFINE_MUTEX(blobs_lock);
static struct dentry *debugfs_root;

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_native_lab_emit(u64 arg0)
{
	(void)arg0;
}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_arm64_native_lab_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_native_lab_emit)
BTF_KFUNCS_END(bpf_arm64_native_lab_kfunc_ids)

static int decode_native_lab_payload(u64 payload, u32 *blob_id, u32 *abi_mask,
				     u32 *generation)
{
	payload = kinsn_payload_decode(payload);

	if (payload & 0xf)
		return -EINVAL;
	if (((payload >> 4) & 0xf) & ~NATIVE_LAB_ABI_MASK)
		return -EINVAL;
	if ((payload >> 17) & 0x7)
		return -EINVAL;

	*blob_id = (u32)((payload >> 8) & 0x1ff);
	if (*blob_id >= NATIVE_LAB_MAX_BLOBS)
		return -EINVAL;
	if (abi_mask)
		*abi_mask = (u32)((payload >> 4) & 0xf);
	if (generation)
		*generation = (u32)(payload >> 20);

	return 0;
}

#include "native_lab_group.h"

static int native_lab_advance_generation(struct native_blob *blob)
{
	if (blob->generation == U32_MAX)
		return -EOVERFLOW;
	native_lab_forget_checked();
	native_lab_release_binding_objects(blob);
	blob->generation++;
	kfree(blob->bound_generations);
	blob->bound_generations = NULL;
	return 0;
}

static void native_lab_emit_error(const char *reason, int err, u64 payload,
				  u32 blob_id, size_t blob_len,
				  size_t reloc_count, size_t reloc_index,
				  u32 reloc_offset, u32 reloc_kind,
				  u64 reloc_target)
{
	pr_err_ratelimited("bpf_arm64_native_lab: emit failed reason=%s err=%d payload=0x%llx blob=%u len=%zu relocs=%zu reloc_index=%zu reloc_offset=%u reloc_kind=%u reloc_target=0x%llx\n",
			   reason, err, (unsigned long long)payload, blob_id,
			   blob_len, reloc_count, reloc_index, reloc_offset,
			   reloc_kind, (unsigned long long)reloc_target);
}

static u32 a64_movn_x(u32 reg, u16 imm16, u32 shift)
{
	return 0x92800000U | ((shift / 16) << 21) | ((u32)imm16 << 5) | reg;
}

static u32 a64_movk_x(u32 reg, u16 imm16, u32 shift)
{
	return 0xf2800000U | ((shift / 16) << 21) | ((u32)imm16 << 5) | reg;
}

static int emit_arm64_far_helper_call(u32 *image, size_t slot_index, u64 target)
{
	u64 tmp = target;

	/* Three immediate words represent the upper-ones 48-bit address range. */
	if ((target >> 48) != 0xffff)
		return -ERANGE;

	image[slot_index] = a64_movn_x(A64_TMP_REG, (u16)(~tmp & 0xffff), 0);
	tmp >>= 16;
	image[slot_index + 1] = a64_movk_x(A64_TMP_REG, (u16)(tmp & 0xffff), 16);
	tmp >>= 16;
	image[slot_index + 2] = a64_movk_x(A64_TMP_REG, (u16)(tmp & 0xffff), 32);
	image[slot_index + 3] = A64_BLR_X10;
	return 0;
}

static bool arm64_helper_call_slot_matches(const u32 *image, size_t slot_index)
{
	return image[slot_index] == A64_BL_IMM26_PLACEHOLDER &&
	       image[slot_index + 1] == A64_NOP &&
	       image[slot_index + 2] == A64_NOP &&
	       image[slot_index + 3] == A64_NOP;
}

static bool arm64_bl26_call_slot_matches(const u32 *image, size_t slot_index)
{
	return image[slot_index] == A64_BL_IMM26_PLACEHOLDER;
}

static bool native_lab_arm64_is_kernel_addr(u64 target)
{
	return target && (s64)target < 0;
}

static int instantiate_native_lab(u64 payload, struct bpf_insn *insn_buf)
{
	u32 abi_mask = 0;
	u32 generation = 0;
	u32 blob_id;
	int err;
	int cnt = 0;

	err = decode_native_lab_payload(payload, &blob_id, &abi_mask,
					&generation);
	if (err)
		return err;
	if (generation) {
		mutex_lock(&blobs_lock);
		if (blobs[blob_id].generation != generation ||
		    !blobs[blob_id].proof || !blobs[blob_id].proof_len) {
			mutex_unlock(&blobs_lock);
			return -ESTALE;
		}
		if (!native_lab_trusted_authorized(blobs[blob_id].trusted)) {
			mutex_unlock(&blobs_lock);
			return -EPERM;
		}
		err = native_lab_group_use(blob_id, generation, abi_mask);
		if (err) {
			mutex_unlock(&blobs_lock);
			return err;
		}
		if (blobs[blob_id].proof_len + hweight32(abi_mask) >
		    NATIVE_LAB_MAX_PROOF_INSNS) {
			mutex_unlock(&blobs_lock);
			return -E2BIG;
		}
		if (!insn_buf) {
			cnt = blobs[blob_id].proof_len + hweight32(abi_mask);
			mutex_unlock(&blobs_lock);
			return cnt;
		}
		memcpy(insn_buf, blobs[blob_id].proof,
		       blobs[blob_id].proof_len * sizeof(*insn_buf));
		cnt = blobs[blob_id].proof_len;
		mutex_unlock(&blobs_lock);
	}

	if (!insn_buf)
		return hweight32(abi_mask) + 1;

	/* The unbound stub must define r0 before the ABI marker reads it. */
	if (!generation)
		insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MOV, BPF_REG_0, 0);

	if (abi_mask & NATIVE_LAB_ABI_X19)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_0);
	if (abi_mask & NATIVE_LAB_ABI_X20)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_7, BPF_REG_0);
	if (abi_mask & NATIVE_LAB_ABI_X21)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_8, BPF_REG_0);
	if (abi_mask & NATIVE_LAB_ABI_X22)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_9, BPF_REG_0);
	return cnt;
}

static int emit_native_lab_arm64(u32 *image, int *idx, bool emit, u64 payload,
				 const struct bpf_prog *prog,
				 const u32 *final_ip)
{
	struct native_lab_reloc_record *snapshot_relocs = NULL;
	size_t snapshot_reloc_count = 0;
	size_t snapshot_len = 0;
	u8 *snapshot = NULL;
	int start_idx;
	u32 abi_mask = 0;
	u32 generation = 0;
	u32 blob_id;
	size_t i;
	int err;


	err = decode_native_lab_payload(payload, &blob_id, &abi_mask, &generation);
	if (err)
		return err;
	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;
	start_idx = *idx;

	mutex_lock(&blobs_lock);
	if (generation && blobs[blob_id].generation != generation) {
		mutex_unlock(&blobs_lock);
		native_lab_emit_error("stale_generation", -ESTALE, payload,
				      blob_id, 0, 0, 0, 0, 0, 0);
		return -ESTALE;
	}
	if (generation) {
		err = native_lab_group_use(blob_id, generation, abi_mask);
		if (!err)
			err = native_lab_group_program(prog, blob_id);
		if (!err)
			err = native_lab_trusted_bind_program(blobs[blob_id].trusted, prog);
		if (err) {
			mutex_unlock(&blobs_lock);
			return err;
		}
	}
	if (blobs[blob_id].bytes && blobs[blob_id].len) {
		snapshot_len = blobs[blob_id].len;
		if (snapshot_len > NATIVE_LAB_MAX_BLOB_BYTES) {
			mutex_unlock(&blobs_lock);
			return -E2BIG;
		}
		if (snapshot_len & 3) {
			mutex_unlock(&blobs_lock);
			return -EINVAL;
		}
		if (blobs[blob_id].reloc_count > NATIVE_LAB_MAX_RELOCS) {
			mutex_unlock(&blobs_lock);
			return -E2BIG;
		}
		if (blobs[blob_id].reloc_count && !blobs[blob_id].relocs) {
			mutex_unlock(&blobs_lock);
			return -EINVAL;
		}
		snapshot_reloc_count = blobs[blob_id].reloc_count;
		if (snapshot_reloc_count) {
			snapshot_relocs = kmemdup(blobs[blob_id].relocs,
						  snapshot_reloc_count *
						  sizeof(snapshot_relocs[0]),
						  GFP_KERNEL);
			if (!snapshot_relocs) {
				mutex_unlock(&blobs_lock);
				return -ENOMEM;
			}
		}
		snapshot = kmemdup(blobs[blob_id].bytes, snapshot_len,
				   GFP_KERNEL);
		if (!snapshot) {
			kfree(snapshot_relocs);
			mutex_unlock(&blobs_lock);
			return -ENOMEM;
		}
	}
	mutex_unlock(&blobs_lock);

	if (!snapshot_len) {
		native_lab_emit_error("missing_blob", -ENOENT, payload, blob_id,
				      0, 0, 0, 0, 0, 0);
		return -ENOENT;
	}

	if (emit) {
		for (i = 0; i < snapshot_len; i += sizeof(u32))
			image[start_idx + (i / sizeof(u32))] =
				get_unaligned_le32(snapshot + i);

		for (i = 0; i < snapshot_reloc_count; i++) {
			const struct native_lab_reloc_record *r = &snapshot_relocs[i];

			switch (r->kind) {
			case NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE:
			case NATIVE_LAB_RELOC_READONLY_DATA:
				/* Immutable-data binding metadata; emits no patch. */
				break;
			case NATIVE_LAB_RELOC_MAP_POINTER:
			case NATIVE_LAB_RELOC_MAP_VALUE:
			case NATIVE_LAB_RELOC_HELPER_POINTER:
				err = native_lab_emit_literal(r,
					snapshot, snapshot_len, (u8 *)&image[start_idx], prog);
				break;

			case NATIVE_LAB_RELOC_HELPER_CALL_ARM64_BL26: {
				size_t word_offset;
				size_t slot_index;
				u64 slot_va;
				s64 disp64;
				s64 imm26;

				if (r->offset & (sizeof(u32) - 1)) {
					err = -EINVAL;
					native_lab_emit_error("reloc_unaligned", err,
							      payload, blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if ((size_t)r->offset +
				    NATIVE_LAB_ARM64_BL26_CALL_WORDS * sizeof(u32) >
				    snapshot_len) {
					err = -ERANGE;
					native_lab_emit_error("reloc_bounds", err,
							      payload, blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				word_offset = r->offset / sizeof(u32);
				slot_index = start_idx + word_offset;
				if (!arm64_bl26_call_slot_matches(image, slot_index)) {
					err = -EINVAL;
					native_lab_emit_error("reloc_slot_mismatch",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if (!native_lab_arm64_is_kernel_addr(r->target)) {
					err = -EINVAL;
					native_lab_emit_error("helper_target_not_kernel",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if (!final_ip) {
					err = -EINVAL;
					native_lab_emit_error("missing_final_ip",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				slot_va = (u64)(unsigned long)(final_ip + word_offset);
				disp64 = (s64)r->target - (s64)slot_va;
				if (disp64 & 3) {
					err = -EINVAL;
					native_lab_emit_error("bl26_unaligned_target",
							      err, payload,
							      blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				imm26 = disp64 / 4;
				if (imm26 < -(1LL << 25) ||
				    imm26 > ((1LL << 25) - 1)) {
					err = -ERANGE;
					native_lab_emit_error("bl26_out_of_range",
							      err, payload,
							      blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				image[slot_index] = A64_BL_IMM26_PLACEHOLDER |
					((u32)imm26 & A64_BL26_IMM_MASK);
				break;
			}
			case NATIVE_LAB_RELOC_HELPER_CALL_ARM64: {
				size_t word_offset;
				size_t slot_index;
				u64 slot_va;
				s64 disp64;
				s64 imm26;

				if (r->offset & (sizeof(u32) - 1)) {
					err = -EINVAL;
					native_lab_emit_error("reloc_unaligned", err,
							      payload, blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if ((size_t)r->offset +
				    NATIVE_LAB_ARM64_HELPER_CALL_WORDS * sizeof(u32) >
				    snapshot_len) {
					err = -ERANGE;
					native_lab_emit_error("reloc_bounds", err,
							      payload, blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				word_offset = r->offset / sizeof(u32);
				slot_index = start_idx + word_offset;
				if (!arm64_helper_call_slot_matches(image, slot_index)) {
					err = -EINVAL;
					native_lab_emit_error("reloc_slot_mismatch",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if (!native_lab_arm64_is_kernel_addr(r->target)) {
					err = -EINVAL;
					native_lab_emit_error("helper_target_not_kernel",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if (!final_ip) {
					err = -EINVAL;
					native_lab_emit_error("missing_final_ip",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				slot_va = (u64)(unsigned long)(final_ip + word_offset);
				disp64 = (s64)r->target - (s64)slot_va;
				if (disp64 & 3) {
					err = -EINVAL;
					native_lab_emit_error("bl26_unaligned_target",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				imm26 = disp64 / 4;
				if (imm26 < -(1LL << 25) ||
				    imm26 > ((1LL << 25) - 1)) {
					err = emit_arm64_far_helper_call(image, slot_index,
								     r->target);
					if (err)
						native_lab_emit_error("helper_target_encoding", err,
								      payload, blob_id, snapshot_len,
								      snapshot_reloc_count, i,
								      r->offset, r->kind, r->target);
					break;
				}
				image[slot_index] = A64_BL_IMM26_PLACEHOLDER |
					((u32)imm26 & A64_BL26_IMM_MASK);
				break;
			}
			case NATIVE_LAB_RELOC_ARM64_PERCPU_MRS: {
				size_t word_offset;
				size_t slot_index;

				if (r->offset & (sizeof(u32) - 1)) {
					err = -EINVAL;
					native_lab_emit_error("reloc_unaligned", err,
							      payload, blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if ((size_t)r->offset + sizeof(u32) > snapshot_len) {
					err = -ERANGE;
					native_lab_emit_error("reloc_bounds", err,
							      payload, blob_id,
							      snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				word_offset = r->offset / sizeof(u32);
				slot_index = start_idx + word_offset;
				if (image[slot_index] != A64_MRS_X10_TPIDR_EL1) {
					err = -EINVAL;
					native_lab_emit_error("reloc_slot_mismatch",
							      err, payload,
							      blob_id, snapshot_len,
							      snapshot_reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				image[slot_index] =
					cpus_have_cap(ARM64_HAS_VIRT_HOST_EXTN) ?
					A64_MRS_X10_TPIDR_EL2 :
					A64_MRS_X10_TPIDR_EL1;
				break;
			}
			default:
				err = -EINVAL;
				native_lab_emit_error("unknown_reloc_kind", err,
						      payload, blob_id,
						      snapshot_len,
						      snapshot_reloc_count,
						      i, r->offset, r->kind,
						      r->target);
				break;
			}
			if (err)
				goto out_free;
		}
	}

	if (emit && final_ip && generation && native_lab_capture_checked) {
		mutex_lock(&blobs_lock);
		err = native_lab_group_use(blob_id, generation, abi_mask);
		if (!err)
			err = native_lab_group_program(prog, blob_id);
		if (!err)
			err = native_lab_trusted_bind_program(blobs[blob_id].trusted, prog);
		if (!err)
			err = native_lab_capture_emit(blob_id, generation, abi_mask, final_ip);
		mutex_unlock(&blobs_lock);
		if (err)
			goto out_free;
	}

	*idx += snapshot_len / sizeof(u32);
	err = snapshot_len / sizeof(u32);

out_free:
	kfree(snapshot_relocs);
	kfree(snapshot);
	return err;
}

const struct bpf_kinsn bpf_arm64_native_lab_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = NATIVE_LAB_MAX_PROOF_INSNS,
	.native_proof = true,
	.validate_native_program = native_lab_validate_program,
	.validate_native_proof = native_lab_validate_proof,
	.native_stack_depth = NATIVE_LAB_STACK_RESERVE_BYTES,
	.max_emit_bytes = NATIVE_LAB_MAX_BLOB_BYTES,
	.instantiate_insn = instantiate_native_lab,
	.emit_arm64 = emit_native_lab_arm64,
};

static const struct bpf_kinsn * const bpf_arm64_native_lab_kinsn_descs[] = {
	&bpf_arm64_native_lab_desc,
};

struct blob_file_priv {
	u32 id;
};

struct map_ptr_file_priv {
	char response[32];
	size_t len;
};

static ssize_t blob_write(struct file *file, const char __user *ubuf,
			  size_t len, loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	u8 *kbuf = NULL;
	int err;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	if (*ppos)
		return -EINVAL;
	if (len > NATIVE_LAB_MAX_BLOB_BYTES)
		return -E2BIG;
	if (len & 3)
		return -EINVAL;

	if (len) {
		kbuf = kmalloc(len, GFP_KERNEL);
		if (!kbuf)
			return -ENOMEM;
		if (copy_from_user(kbuf, ubuf, len)) {
			kfree(kbuf);
			return -EFAULT;
		}
	}

	mutex_lock(&blobs_lock);
	err = native_lab_advance_generation(&blobs[priv->id]);
	if (err) {
		mutex_unlock(&blobs_lock);
		kfree(kbuf);
		return err;
	}
	kfree(blobs[priv->id].bytes);
	kfree(blobs[priv->id].relocs);
	kvfree(blobs[priv->id].proof);
	blobs[priv->id].relocs = NULL;
	blobs[priv->id].reloc_count = 0;
	blobs[priv->id].proof = NULL;
	blobs[priv->id].proof_len = 0;
	blobs[priv->id].bytes = kbuf;
	blobs[priv->id].len = len;
	mutex_unlock(&blobs_lock);

	*ppos = len;
	return len;
}

static ssize_t relocs_write(struct file *file, const char __user *ubuf,
			    size_t len, loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	struct native_lab_reloc_record *kbuf = NULL;
	size_t count;
	int err;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	if (*ppos)
		return -EINVAL;
	if (len % sizeof(struct native_lab_reloc_record))
		return -EINVAL;
	count = len / sizeof(struct native_lab_reloc_record);
	if (count > NATIVE_LAB_MAX_RELOCS)
		return -E2BIG;

	if (len) {
		kbuf = kmalloc(len, GFP_KERNEL);
		if (!kbuf)
			return -ENOMEM;
		if (copy_from_user(kbuf, ubuf, len)) {
			kfree(kbuf);
			return -EFAULT;
		}
	}

	mutex_lock(&blobs_lock);
	err = native_lab_advance_generation(&blobs[priv->id]);
	if (err) {
		mutex_unlock(&blobs_lock);
		kfree(kbuf);
		return err;
	}
	kfree(blobs[priv->id].relocs);
	blobs[priv->id].relocs = kbuf;
	blobs[priv->id].reloc_count = count;
	mutex_unlock(&blobs_lock);

	*ppos = len;
	return len;
}

static ssize_t proof_write(struct file *file, const char __user *ubuf,
			   size_t len, loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	struct bpf_insn *kbuf;
	size_t count;
	int err;

	if (!capable(CAP_SYS_ADMIN) || !native_lab_trusted_writer())
		return -EPERM;
	if (*ppos)
		return -EINVAL;
	if (!len || len % sizeof(*kbuf))
		return -EINVAL;
	count = len / sizeof(*kbuf);
	if (count > NATIVE_LAB_MAX_PROOF_INSNS)
		return -E2BIG;
	kbuf = vmemdup_user(ubuf, len);
	if (IS_ERR(kbuf))
		return PTR_ERR(kbuf);

	mutex_lock(&blobs_lock);
	err = native_lab_advance_generation(&blobs[priv->id]);
	if (err) {
		mutex_unlock(&blobs_lock);
		kvfree(kbuf);
		return err;
	}
	kvfree(blobs[priv->id].proof);
	blobs[priv->id].proof = kbuf;
	blobs[priv->id].proof_len = count;
	mutex_unlock(&blobs_lock);
	*ppos = len;
	return len;
}

/* Seal only an exact snapshot. All writes, including this seal, advance the
 * generation, so a stale or partially reuploaded artifact cannot be reused.
 */
static ssize_t binding_write(struct file *file, const char __user *ubuf,
			     size_t len, loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	struct native_lab_binding header;
	struct native_blob *blob = &blobs[priv->id];
	u8 *data;
	u32 *group_generations = NULL;
	struct bpf_map **pinned_maps = NULL;
	u32 pinned_map_count = 0;
	struct bpf_prog *source = NULL, *target = NULL;
	struct native_lab_trusted_capsule *trusted = NULL;
	int err;

	if (!capable(CAP_SYS_ADMIN) || !native_lab_trusted_writer())
		return -EPERM;
	if (*ppos || len < sizeof(header))
		return -EINVAL;
	if (len > sizeof(header) + NATIVE_LAB_MAX_BLOB_BYTES +
	    NATIVE_LAB_MAX_RELOCS * sizeof(struct native_lab_reloc_record) +
	    NATIVE_LAB_MAX_PROOF_INSNS * sizeof(struct bpf_insn))
		return -E2BIG;
	data = vmemdup_user(ubuf, len);
	if (IS_ERR(data))
		return PTR_ERR(data);
	memcpy(&header, data, sizeof(header));

	mutex_lock(&blobs_lock);
	err = native_lab_binding_validate(&header, NATIVE_LAB_ARCH_ARM64,
		priv->id, blob->len, blob->reloc_count, blob->proof_len,
		blob->generation);
	if (err)
		goto out;
	if (header.prog_type >= __MAX_BPF_PROG_TYPE ||
	    header.expected_attach_type >= __MAX_BPF_ATTACH_TYPE) {
		err = -EINVAL;
		goto out;
	}
	BUILD_BUG_ON(sizeof(header) != 96);
	BUILD_BUG_ON(sizeof(*blob->relocs) != 16);
	BUILD_BUG_ON(sizeof(*blob->proof) != 8);
	err = native_lab_binding_snapshot(&header, data, len, blob->bytes,
					  blob->relocs, blob->proof);
	if (err)
		goto out;
	err = native_lab_group_prepare(&header, &group_generations);
	if (err)
		goto out;
	err = native_lab_pin_maps(blob, &pinned_maps, &pinned_map_count);
	if (err)
		goto out;
	err = native_lab_pin_context(&header, &source, &target);
	if (err)
		goto out;
	err = native_lab_trusted_seal(&header, &trusted);
	if (err)
		goto out;
	err = native_lab_advance_generation(blob);
	if (err)
		goto out;
	blob->binding = header;
	blob->trusted = trusted;
	trusted = NULL;
	blob->bound_source = source;
	blob->bound_target = target;
	source = NULL;
	target = NULL;
	blob->bound_maps = pinned_maps;
	blob->bound_map_count = pinned_map_count;
	blob->bound_generations = group_generations;
	pinned_maps = NULL;
	pinned_map_count = 0;
	group_generations = NULL;
out:
	native_lab_trusted_put(trusted);
	if (source)
		bpf_prog_put(source);
	if (target)
		bpf_prog_put(target);
	kfree(group_generations);
	native_lab_put_maps(pinned_maps, pinned_map_count);
	mutex_unlock(&blobs_lock);
	kvfree(data);
	if (err)
		return err;
	*ppos = len;
	return len;
}

static ssize_t generation_read(struct file *file, char __user *ubuf,
			       size_t len, loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	char buf[16];
	u32 generation;
	int n;

	mutex_lock(&blobs_lock);
	generation = blobs[priv->id].generation;
	mutex_unlock(&blobs_lock);
	n = scnprintf(buf, sizeof(buf), "%u\n", generation);
	return simple_read_from_buffer(ubuf, len, ppos, buf, n);
}

static ssize_t blob_read(struct file *file, char __user *ubuf, size_t len,
			 loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	u8 *stash = NULL;
	size_t copy_len;
	size_t blen;
	ssize_t ret;

	mutex_lock(&blobs_lock);
	blen = blobs[priv->id].len;
	if (blen) {
		stash = kmemdup(blobs[priv->id].bytes, blen, GFP_KERNEL);
		if (!stash) {
			mutex_unlock(&blobs_lock);
			return -ENOMEM;
		}
	}
	mutex_unlock(&blobs_lock);

	if (*ppos >= blen) {
		ret = 0;
		goto out_free;
	}
	copy_len = min(len, blen - (size_t)*ppos);
	if (copy_to_user(ubuf, stash + *ppos, copy_len)) {
		ret = -EFAULT;
		goto out_free;
	}
	*ppos += copy_len;
	ret = copy_len;

out_free:
	kfree(stash);
	return ret;
}

static int blob_open(struct inode *inode, struct file *file)
{
	struct blob_file_priv *priv;
	long id = (long)inode->i_private;

	priv = kmalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	priv->id = (u32)id;
	file->private_data = priv;
	return 0;
}

static int blob_release(struct inode *inode, struct file *file)
{
	kfree(file->private_data);
	return 0;
}

static const struct file_operations blob_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.read = blob_read,
	.write = blob_write,
	.llseek = default_llseek,
};

static const struct file_operations relocs_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.write = relocs_write,
	.llseek = default_llseek,
};

static const struct file_operations proof_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.write = proof_write,
	.llseek = default_llseek,
};

static const struct file_operations binding_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.write = binding_write,
	.llseek = default_llseek,
};

static const struct file_operations generation_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.read = generation_read,
	.llseek = default_llseek,
};

static int map_ptr_open(struct inode *inode, struct file *file)
{
	struct map_ptr_file_priv *priv;

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	file->private_data = priv;
	return 0;
}

static int map_ptr_release(struct inode *inode, struct file *file)
{
	kfree(file->private_data);
	return 0;
}

static ssize_t map_ptr_query_write(struct file *file, const char __user *ubuf,
				   size_t len, loff_t *ppos, bool direct_value,
				   bool update_elem)
{
	struct map_ptr_file_priv *priv = file->private_data;
	struct bpf_map *map;
	unsigned long ptr;
	unsigned int fd;
	char buf[32];
	int err;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	if (*ppos)
		return -EINVAL;
	if (!len || len >= sizeof(buf))
		return -EINVAL;
	if (copy_from_user(buf, ubuf, len))
		return -EFAULT;
	buf[len] = '\0';

	err = kstrtouint(buf, 0, &fd);
	if (err)
		return err;

	map = bpf_map_get(fd);
	if (IS_ERR(map))
		return PTR_ERR(map);

	ptr = (unsigned long)map;
	if (direct_value) {
		u64 value = 0;

		if (!map->ops || !map->ops->map_direct_value_addr) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		err = map->ops->map_direct_value_addr(map, &value, 0);
		if (err)
			goto out_put;
		ptr = (unsigned long)value;
	} else if (update_elem) {
		if (!map->ops || !map->ops->map_update_elem) {
			err = -EOPNOTSUPP;
			goto out_put;
		}
		ptr = (unsigned long)map->ops->map_update_elem;
	}

	priv->len = scnprintf(priv->response, sizeof(priv->response),
			      "0x%llx\n", (unsigned long long)ptr);
	err = len;
out_put:
	bpf_map_put(map);
	if (err < 0)
		return err;
	*ppos = len;
	return err;
}

static ssize_t map_ptr_write(struct file *file, const char __user *ubuf,
			     size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos, false, false);
}

static ssize_t map_value_ptr_write(struct file *file, const char __user *ubuf,
				   size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos, true, false);
}

static ssize_t map_update_elem_write(struct file *file, const char __user *ubuf,
				     size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos, false, true);
}

static ssize_t map_ptr_read(struct file *file, char __user *ubuf, size_t len,
			    loff_t *ppos)
{
	struct map_ptr_file_priv *priv = file->private_data;

	return simple_read_from_buffer(ubuf, len, ppos, priv->response,
				       priv->len);
}

static const struct file_operations map_ptr_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_ptr_write,
	.llseek = default_llseek,
};

static const struct file_operations map_value_ptr_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_value_ptr_write,
	.llseek = default_llseek,
};

static const struct file_operations map_update_elem_fops = {
	.owner = THIS_MODULE,
	.open = map_ptr_open,
	.release = map_ptr_release,
	.read = map_ptr_read,
	.write = map_update_elem_write,
	.llseek = default_llseek,
};

static int __init bpf_arm64_native_lab_debugfs_init(void)
{
	long i;
	struct dentry *checked;

	debugfs_root = debugfs_create_dir("bpf_arm64_native_lab", NULL);
	if (IS_ERR(debugfs_root))
		return PTR_ERR(debugfs_root);

	debugfs_create_file("native_submit", 0600, debugfs_root, NULL,
			    &native_lab_trusted_fops);
	debugfs_create_file("specializer", 0600, debugfs_root, (void *)1,
			    &native_lab_trusted_fops);

	checked = debugfs_create_file("checked_proof", 0400, debugfs_root, NULL,
			      &native_lab_checked_fops);
	if (IS_ERR(checked)) {
		debugfs_remove_recursive(debugfs_root);
		debugfs_root = NULL;
		return PTR_ERR(checked);
	}
	checked = debugfs_create_file("emitted_native", 0400, debugfs_root, NULL,
			      &native_lab_emitted_fops);
	if (IS_ERR(checked)) {
		debugfs_remove_recursive(debugfs_root);
		debugfs_root = NULL;
		return PTR_ERR(checked);
	}
	debugfs_create_file("map_ptr", 0600, debugfs_root, NULL,
			    &map_ptr_fops);
	debugfs_create_file("map_value_ptr", 0600, debugfs_root, NULL,
			    &map_value_ptr_fops);
	debugfs_create_file("map_update_elem", 0600, debugfs_root, NULL,
			    &map_update_elem_fops);

	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		char name[24];

		scnprintf(name, sizeof(name), "blob%ld", i);
		debugfs_create_file(name, 0600, debugfs_root, (void *)i,
				    &blob_fops);
		scnprintf(name, sizeof(name), "blob%ld.relocs", i);
		debugfs_create_file(name, 0600, debugfs_root, (void *)i,
				    &relocs_fops);
		scnprintf(name, sizeof(name), "blob%ld.proof", i);
		debugfs_create_file(name, 0600, debugfs_root, (void *)i,
				    &proof_fops);
		scnprintf(name, sizeof(name), "blob%ld.binding", i);
		debugfs_create_file(name, 0600, debugfs_root, (void *)i,
				    &binding_fops);
		scnprintf(name, sizeof(name), "blob%ld.generation", i);
		debugfs_create_file(name, 0400, debugfs_root, (void *)i,
				    &generation_fops);
	}
	return 0;
}

static void bpf_arm64_native_lab_debugfs_exit(void)
{
	int i;

	debugfs_remove_recursive(debugfs_root);
	debugfs_root = NULL;

	mutex_lock(&blobs_lock);
	native_lab_forget_checked();
	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		kfree(blobs[i].bytes);
		kfree(blobs[i].relocs);
		kvfree(blobs[i].proof);
		native_lab_release_binding_objects(&blobs[i]);
		kfree(blobs[i].bound_generations);
		blobs[i].bound_generations = NULL;
		blobs[i].bytes = NULL;
		blobs[i].relocs = NULL;
		blobs[i].len = 0;
		blobs[i].reloc_count = 0;
		blobs[i].proof = NULL;
		blobs[i].proof_len = 0;
		blobs[i].generation = 0;
	}
	mutex_unlock(&blobs_lock);
}

static const struct btf_kfunc_id_set bpf_arm64_native_lab_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_arm64_native_lab_kfunc_ids,
	.kinsn_descs = bpf_arm64_native_lab_kinsn_descs,
};

static int __init bpf_arm64_native_lab_init(void)
{
	int err;

	err = bpf_arm64_native_lab_debugfs_init();
	if (err)
		return err;

	err = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,
					&bpf_arm64_native_lab_kfunc_set);
	if (err) {
		bpf_arm64_native_lab_debugfs_exit();
		return err;
	}

	return 0;
}

static void __exit bpf_arm64_native_lab_exit(void)
{
	bpf_arm64_native_lab_debugfs_exit();
}

module_init(bpf_arm64_native_lab_init);
module_exit(bpf_arm64_native_lab_exit);

MODULE_DESCRIPTION("BpfReJIT arm64 native-code lab kinsn (test only; optional bound proof)");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
MODULE_IMPORT_NS("BPF_INTERNAL");
