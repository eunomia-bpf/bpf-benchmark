// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 native-code lab kop.
 *
 * Test-only escape hatch matching the x86 native_lab shape: userspace
 * uploads an arbitrary AArch64 instruction stream through debugfs, then a
 * BPF kop call splats those instructions inline into the BPF JIT image.
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

#include "kop_common.h"

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
 * single kop callback. The arm64 BPF JIT allocates the callback scratch
 * buffer from this descriptor's max_emit_bytes.
 */
#define NATIVE_LAB_MAX_BLOB_BYTES	(16 * 1024)
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

static int decode_native_lab_payload(u64 payload, u32 *blob_id, u32 *abi_mask)
{
	payload = kop_payload_decode(payload);

	if (payload & 0xf)
		return -EINVAL;
	if (((payload >> 4) & 0xf) & ~NATIVE_LAB_ABI_MASK)
		return -EINVAL;
	if ((payload >> 8) & 0xfff)
		return -EINVAL;

	*blob_id = (u32)(payload >> 20);
	if (*blob_id >= NATIVE_LAB_MAX_BLOBS)
		return -EINVAL;
	if (abi_mask)
		*abi_mask = (u32)((payload >> 4) & 0xf);

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

static void emit_arm64_far_helper_call(u32 *image, size_t slot_index, u64 target)
{
	u64 tmp = target;

	image[slot_index] = a64_movn_x(A64_TMP_REG, (u16)(~tmp & 0xffff), 0);
	tmp >>= 16;
	image[slot_index + 1] = a64_movk_x(A64_TMP_REG, (u16)(tmp & 0xffff), 16);
	tmp >>= 16;
	image[slot_index + 2] = a64_movk_x(A64_TMP_REG, (u16)(tmp & 0xffff), 32);
	image[slot_index + 3] = A64_BLR_X10;
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
	u32 blob_id;
	int err;
	int cnt = 0;

	err = decode_native_lab_payload(payload, &blob_id, &abi_mask);
	if (err)
		return err;

	if (abi_mask & NATIVE_LAB_ABI_X19)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);
	if (abi_mask & NATIVE_LAB_ABI_X20)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_7, BPF_REG_1);
	if (abi_mask & NATIVE_LAB_ABI_X21)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_8, BPF_REG_1);
	if (abi_mask & NATIVE_LAB_ABI_X22)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_9, BPF_REG_1);
	insn_buf[cnt++] = BPF_ST_MEM(BPF_DW, BPF_REG_FP,
				     -NATIVE_LAB_STACK_RESERVE_BYTES, 0);
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MOV, BPF_REG_0, 0);
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
	u32 blob_id;
	size_t i;
	int err;

	(void)prog;

	err = decode_native_lab_payload(payload, &blob_id, NULL);
	if (err)
		return err;
	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;
	start_idx = *idx;

	mutex_lock(&blobs_lock);
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
					emit_arm64_far_helper_call(image, slot_index,
								   r->target);
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

	*idx += snapshot_len / sizeof(u32);
	err = snapshot_len / sizeof(u32);

out_free:
	kfree(snapshot_relocs);
	kfree(snapshot);
	return err;
}

const struct bpf_kop bpf_arm64_native_lab_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 6,
	.max_emit_bytes = NATIVE_LAB_MAX_BLOB_BYTES,
	.instantiate_insn = instantiate_native_lab,
	.emit_arm64 = emit_native_lab_arm64,
};

static const struct bpf_kop * const bpf_arm64_native_lab_kop_descs[] = {
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
	kfree(blobs[priv->id].bytes);
	kfree(blobs[priv->id].relocs);
	blobs[priv->id].relocs = NULL;
	blobs[priv->id].reloc_count = 0;
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
	kfree(blobs[priv->id].relocs);
	blobs[priv->id].relocs = kbuf;
	blobs[priv->id].reloc_count = count;
	mutex_unlock(&blobs_lock);

	*ppos = len;
	return len;
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

	debugfs_root = debugfs_create_dir("bpf_arm64_native_lab", NULL);
	if (IS_ERR(debugfs_root))
		return PTR_ERR(debugfs_root);

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
	}
	return 0;
}

static void bpf_arm64_native_lab_debugfs_exit(void)
{
	int i;

	debugfs_remove_recursive(debugfs_root);
	debugfs_root = NULL;

	mutex_lock(&blobs_lock);
	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		kfree(blobs[i].bytes);
		kfree(blobs[i].relocs);
		blobs[i].bytes = NULL;
		blobs[i].relocs = NULL;
		blobs[i].len = 0;
		blobs[i].reloc_count = 0;
	}
	mutex_unlock(&blobs_lock);
}

static const struct btf_kfunc_id_set bpf_arm64_native_lab_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_arm64_native_lab_kfunc_ids,
	.kop_descs = bpf_arm64_native_lab_kop_descs,
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

MODULE_DESCRIPTION("BpfReJIT arm64 native-code lab kop (test only; bypasses verifier guarantees)");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
MODULE_IMPORT_NS("BPF_INTERNAL");
