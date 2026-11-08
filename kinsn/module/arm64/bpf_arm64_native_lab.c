// SPDX-License-Identifier: GPL-2.0
/* Trusted service creates immutable linked P chunks; verifier and JIT use
 * these allocations through ordinary kernel handles. */
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
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/xarray.h>
#include <linux/unaligned.h>
#include <asm/cpufeature.h>
#include "kinsn_common.h"
#include "native_lab_binding.h"
#define NATIVE_LAB_BINDING_ARCH NATIVE_LAB_ARCH_ARM64
#include "native_lab_trusted.h"
#define NATIVE_LAB_MAX_BLOB_BYTES (16 * 1024)
#define NATIVE_LAB_STACK_RESERVE_BYTES 512
#define NATIVE_LAB_RELOC_HELPER_CALL_ARM64	2
#define NATIVE_LAB_RELOC_HELPER_CALL_ARM64_BL26	3
#define NATIVE_LAB_RELOC_ARM64_PERCPU_MRS	4
#define A64_BL_IMM26_PLACEHOLDER		0x94000000U
#define A64_BL26_IMM_MASK			0x03ffffffU
#define A64_NOP					0xd503201fU
#define A64_BLR_X10				0xd63f0140U
#define A64_MRS_X10_TPIDR_EL1			0xd538d08aU
#define A64_MRS_X10_TPIDR_EL2			0xd53cd04aU
#define A64_TMP_REG				10U
#define NATIVE_LAB_ARM64_HELPER_CALL_WORDS	4
#define NATIVE_LAB_ARM64_BL26_CALL_WORDS	1

#define NATIVE_LAB_ABI_X19 1U
#define NATIVE_LAB_ABI_X20 2U
#define NATIVE_LAB_ABI_X21 4U
#define NATIVE_LAB_ABI_X22 8U
struct native_lab_reloc_record { u32 offset, kind; u64 target; };
struct native_blob {
    struct list_head list;
    u32 id;
    u8 *bytes;
    size_t len, reloc_count, proof_len;
    struct native_lab_reloc_record *relocs;
    struct bpf_insn *proof;
    struct bpf_map **maps;
    u32 map_count;
    struct native_lab_trusted_capsule *capsule;
};
static DEFINE_XARRAY_ALLOC(blobs);
static DEFINE_MUTEX(blobs_lock);
static struct dentry *debugfs_root;
#include "native_lab_group.h"

static void native_lab_free_blob(struct native_blob *blob)
{
    while (blob->map_count)
        bpf_map_put(blob->maps[--blob->map_count]);
    kfree(blob->maps);
    kvfree(blob->bytes);
    kvfree(blob->relocs);
    kvfree(blob->proof);
    kfree(blob);
}
static void native_lab_free_chunks(struct native_lab_trusted_capsule *capsule)
{
    struct native_blob *blob, *next;
    mutex_lock(&blobs_lock);
    list_for_each_entry_safe(blob, next, &capsule->chunks, list) {
        xa_erase(&blobs, blob->id);
        list_del(&blob->list);
        native_lab_free_blob(blob);
    }
    mutex_unlock(&blobs_lock);
}
static int native_lab_store_chunk(void __user *argument)
{
    struct native_lab_trusted_chunk input;
    struct native_lab_trusted_capsule *capsule;
    struct native_blob *blob;
    size_t i;
    int err;
    if (copy_from_user(&input, argument, sizeof(input)))
        return -EFAULT;
    capsule = native_lab_active_capsule(input.request_id);
    if (IS_ERR(capsule))
        return PTR_ERR(capsule);
    blob = kzalloc(sizeof(*blob), GFP_KERNEL);
    if (!blob) { err = -ENOMEM; goto out; }
    blob->len = input.native_size;
    blob->proof_len = input.proof_insns;
    blob->reloc_count = input.reloc_count;
    blob->capsule = capsule;
    blob->bytes = vmemdup_user(u64_to_user_ptr(input.native_user), blob->len);
    if (IS_ERR(blob->bytes)) { err = PTR_ERR(blob->bytes); blob->bytes = NULL; goto fail; }
    if (blob->reloc_count) {
        blob->relocs = vmemdup_user(u64_to_user_ptr(input.relocs_user),
            array_size(blob->reloc_count, sizeof(*blob->relocs)));
        if (IS_ERR(blob->relocs)) { err = PTR_ERR(blob->relocs); blob->relocs = NULL; goto fail; }
    }
    blob->proof = vmemdup_user(u64_to_user_ptr(input.proof_user),
        array_size(blob->proof_len, sizeof(*blob->proof)));
    if (IS_ERR(blob->proof)) { err = PTR_ERR(blob->proof); blob->proof = NULL; goto fail; }
    blob->maps = kcalloc(blob->reloc_count, sizeof(*blob->maps), GFP_KERNEL);
    if (!blob->maps && blob->reloc_count) { err = -ENOMEM; goto fail; }
    for (i = 0; i < blob->reloc_count; i++) {
        u32 id = (u32)blob->relocs[i].target;
        struct bpf_map *map;
        if (blob->relocs[i].kind != NATIVE_LAB_RELOC_MAP_POINTER &&
            blob->relocs[i].kind != NATIVE_LAB_RELOC_MAP_VALUE &&
            blob->relocs[i].kind != NATIVE_LAB_RELOC_READONLY_DATA)
            continue;
        map = bpf_map_get_curr_or_next(&id);
        if (!map || id != (u32)blob->relocs[i].target) {
            if (map) bpf_map_put(map);
            err = -ENOENT; goto fail;
        }
        blob->maps[blob->map_count++] = map;
    }
    mutex_lock(&blobs_lock);
    err = xa_alloc(&blobs, &blob->id, blob, XA_LIMIT(1, U32_MAX), GFP_KERNEL);
    if (!err) {
        list_add_tail(&blob->list, &capsule->chunks);
        capsule->release_chunks = native_lab_free_chunks;
        input.chunk_id = blob->id;
    }
    mutex_unlock(&blobs_lock);
    if (err) goto fail;
    err = copy_to_user(argument, &input, sizeof(input)) ? -EFAULT : 0;
    goto out;
fail:
    native_lab_free_blob(blob);
out:
    native_lab_trusted_put(capsule);
    return err;
}

__bpf_kfunc_start_defs();
__bpf_kfunc void bpf_arm64_native_lab_emit(u64 arg0) { (void)arg0; }
__bpf_kfunc_end_defs();
BTF_KFUNCS_START(bpf_arm64_native_lab_kfunc_ids)
BTF_ID_FLAGS(func, bpf_arm64_native_lab_emit)
BTF_KFUNCS_END(bpf_arm64_native_lab_kfunc_ids)

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

static int instantiate_native_lab(u64 payload, struct bpf_insn *insn_buf)
{
    struct native_blob *blob;
    u32 id, abi;
    int count;
    payload = kinsn_payload_decode(payload);
    id = payload >> 8;
    abi = (payload >> 4) & 15;
    mutex_lock(&blobs_lock);
    blob = xa_load(&blobs, id);
    if (!blob) { mutex_unlock(&blobs_lock); return -ENOENT; }
    count = blob->proof_len;
    if (insn_buf) {
        memcpy(insn_buf, blob->proof, count * sizeof(*insn_buf));
        if (abi & NATIVE_LAB_ABI_X19) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_0);
        if (abi & NATIVE_LAB_ABI_X20) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_7, BPF_REG_0);
        if (abi & NATIVE_LAB_ABI_X21) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_8, BPF_REG_0);
        if (abi & NATIVE_LAB_ABI_X22) insn_buf[count++] = BPF_MOV64_REG(BPF_REG_9, BPF_REG_0);
    } else count += hweight32(abi);
    mutex_unlock(&blobs_lock);
    return count;
}
static int emit_native_lab_arm64(u32 *image, int *idx, bool emit, u64 payload,
                                 const struct bpf_prog *prog, const u32 *final_ip)
{
    struct native_blob *blob;
    const struct native_lab_reloc_record *relocs;
    const u8 *native_bytes;
    size_t native_len, reloc_count, i;
    u32 blob_id;
    int start_idx = *idx, err;

    payload = kinsn_payload_decode(payload);
    blob_id = payload >> 8;
    mutex_lock(&blobs_lock);
    blob = xa_load(&blobs, blob_id);
    if (!blob) { mutex_unlock(&blobs_lock); return -ENOENT; }
    err = native_lab_retain_program(blob->capsule, prog);
    if (err) { mutex_unlock(&blobs_lock); return err; }
    native_bytes = blob->bytes;
    native_len = blob->len;
    relocs = blob->relocs;
    reloc_count = blob->reloc_count;
	if (emit) {
		for (i = 0; i < native_len; i += sizeof(u32))
			image[start_idx + (i / sizeof(u32))] =
				get_unaligned_le32(native_bytes + i);

		for (i = 0; i < reloc_count; i++) {
			const struct native_lab_reloc_record *r = &relocs[i];

			switch (r->kind) {
			case NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE:
			case NATIVE_LAB_RELOC_READONLY_DATA:
				/* Immutable-data binding metadata; emits no patch. */
				break;
			case NATIVE_LAB_RELOC_MAP_POINTER:
			case NATIVE_LAB_RELOC_MAP_VALUE:
			case NATIVE_LAB_RELOC_HELPER_POINTER:
				err = native_lab_emit_literal(r,
					native_bytes, native_len, (u8 *)&image[start_idx], blob->maps, blob->map_count);
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
							      native_len,
							      reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if ((size_t)r->offset +
				    NATIVE_LAB_ARM64_BL26_CALL_WORDS * sizeof(u32) >
				    native_len) {
					err = -ERANGE;
					native_lab_emit_error("reloc_bounds", err,
							      payload, blob_id,
							      native_len,
							      reloc_count,
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
							      blob_id, native_len,
							      reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if (!final_ip) {
					err = -EINVAL;
					native_lab_emit_error("missing_final_ip",
							      err, payload,
							      blob_id, native_len,
							      reloc_count,
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
							      native_len,
							      reloc_count,
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
							      native_len,
							      reloc_count,
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
							      native_len,
							      reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if ((size_t)r->offset +
				    NATIVE_LAB_ARM64_HELPER_CALL_WORDS * sizeof(u32) >
				    native_len) {
					err = -ERANGE;
					native_lab_emit_error("reloc_bounds", err,
							      payload, blob_id,
							      native_len,
							      reloc_count,
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
							      blob_id, native_len,
							      reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if (!final_ip) {
					err = -EINVAL;
					native_lab_emit_error("missing_final_ip",
							      err, payload,
							      blob_id, native_len,
							      reloc_count,
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
							      blob_id, native_len,
							      reloc_count,
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
								      payload, blob_id, native_len,
								      reloc_count, i,
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
							      native_len,
							      reloc_count,
							      i, r->offset,
							      r->kind, r->target);
					break;
				}
				if ((size_t)r->offset + sizeof(u32) > native_len) {
					err = -ERANGE;
					native_lab_emit_error("reloc_bounds", err,
							      payload, blob_id,
							      native_len,
							      reloc_count,
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
							      blob_id, native_len,
							      reloc_count,
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
						      native_len,
						      reloc_count,
						      i, r->offset, r->kind,
						      r->target);
				break;
			}
			if (err)
				goto out;
		}
	}

    *idx += native_len / sizeof(u32);
    err = native_len / sizeof(u32);
out:
    mutex_unlock(&blobs_lock);
    return err;
}
const struct bpf_kinsn bpf_arm64_native_lab_desc = {
    .owner = THIS_MODULE, .max_insn_cnt = U32_MAX,
    .native_proof = true, .native_stack_depth = NATIVE_LAB_STACK_RESERVE_BYTES,
    .max_emit_bytes = NATIVE_LAB_MAX_BLOB_BYTES,
    .instantiate_insn = instantiate_native_lab, .emit_arm64 = emit_native_lab_arm64,
};
static const struct bpf_kinsn * const bpf_arm64_native_lab_kinsn_descs[] = { &bpf_arm64_native_lab_desc };
struct map_ptr_file_priv {
	char response[32];
	size_t len;
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

static const struct btf_kfunc_id_set bpf_arm64_native_lab_kfunc_set = {
    .owner = THIS_MODULE, .set = &bpf_arm64_native_lab_kfunc_ids,
    .kinsn_descs = bpf_arm64_native_lab_kinsn_descs,
};
static int __init bpf_arm64_native_lab_init(void)
{
    int err;
    debugfs_root = debugfs_create_dir("bpf_arm64_native_lab", NULL);
    if (IS_ERR(debugfs_root)) return PTR_ERR(debugfs_root);
    debugfs_create_file("native_submit", 0600, debugfs_root, NULL, &native_lab_trusted_fops);
    debugfs_create_file("specializer", 0600, debugfs_root, (void *)1, &native_lab_trusted_fops);
    debugfs_create_file("map_ptr", 0600, debugfs_root, NULL, &map_ptr_fops);
    debugfs_create_file("map_value_ptr", 0600, debugfs_root, NULL, &map_value_ptr_fops);
    debugfs_create_file("map_update_elem", 0600, debugfs_root, NULL, &map_update_elem_fops);
    err = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC, &bpf_arm64_native_lab_kfunc_set);
    if (err) debugfs_remove_recursive(debugfs_root);
    return err;
}
static void __exit bpf_arm64_native_lab_exit(void)
{
    debugfs_remove_recursive(debugfs_root);
    xa_destroy(&blobs);
}
module_init(bpf_arm64_native_lab_init);
module_exit(bpf_arm64_native_lab_exit);
MODULE_DESCRIPTION("NativeSim trusted native path");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
MODULE_IMPORT_NS("BPF_INTERNAL");
