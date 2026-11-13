// SPDX-License-Identifier: GPL-2.0
/*
 * bpf_x86_native_lab, measurement-only "direct native" variant.
 *
 * For timing only. It skips verification: the native bytes uploaded through
 * debugfs run in the kernel with the verifier seeing only an r0=0 stub. It
 * must never be loaded for anything other than a benchmark guest.
 *
 * Commit 82f8e9e77 removed the blob<N> endpoints from the trusted module in
 * kinsn/module/x86/bpf_x86_native_lab.c. The benchmark shim's unbound path
 * (BPFREJIT_SHIM_NATIVE_LOADER=post, a manifest, and
 * BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF unset) still uploads each 128-byte
 * chunk to blob<N> and its relocations to blob<N>.relocs. This module serves
 * that upload, map queries and original-program helper queries, and carries the same module
 * name, debugfs directory and kfunc so it can stand in for the trusted module
 * in a benchmark image. The verified path has no endpoint here: a non-zero
 * generation in the sidecar payload is rejected.
 *
 * The uploaded bytes are splatted inline by the JIT. A blob reaches the next
 * BPF instruction by falling through (no ret); rax holds the return value.
 * The ABI mask in the payload marks BPF r6-r9 used so the JIT prologue saves
 * rbx/r13-r15 when native-link dropped those saves. This code path has no
 * exception-table entries, so native code must not take faults here.
 */

#include <linux/bpf.h>
#include <linux/btf.h>
#include <linux/bpf_verifier.h>
#include <linux/debugfs.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "../../stock-path/module/native_lab_helper_query_impl.h"
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#if __has_include(<linux/bpf_native.h>)
#include <linux/bpf_native.h>
#endif

#include "kinsn_common.h"

#define NATIVE_LAB_MAX_BLOBS		512
#define NATIVE_LAB_MAX_BLOB_BYTES	128
#define NATIVE_LAB_MAX_RELOCS		32

/* Relocation kinds, same wire values as the blob upload ABI. */
#define NATIVE_LAB_RELOC_HELPER_CALL_REL32	1U
#define NATIVE_LAB_RELOC_MAP_POINTER		5U
#define NATIVE_LAB_RELOC_MAP_VALUE		6U
#define NATIVE_LAB_RELOC_HELPER_POINTER		7U
#define NATIVE_LAB_RELOC_READONLY_DATA		8U
/* x86 JIT frame immediates, resolved from the final physical stack depth. */
#define NATIVE_LAB_RELOC_X86_TAIL_COUNT	10U
#define NATIVE_LAB_RELOC_X86_TAIL_STACK	11U

#define NATIVE_LAB_ABI_RBX		(1U << 0)
#define NATIVE_LAB_ABI_R13		(1U << 1)
#define NATIVE_LAB_ABI_R14		(1U << 2)
#define NATIVE_LAB_ABI_R15		(1U << 3)
#define NATIVE_LAB_ABI_MASK		(NATIVE_LAB_ABI_RBX | \
					 NATIVE_LAB_ABI_R13 | \
					 NATIVE_LAB_ABI_R14 | \
					 NATIVE_LAB_ABI_R15)

struct native_lab_reloc_record {
	__u32 offset;	/* byte offset of the patch site within this blob */
	__u32 kind;	/* NATIVE_LAB_RELOC_* */
	__u64 target;	/* absolute address, or map id | value offset << 32 */
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
/*
 * The BPF stub. The verifier sees an empty void kfunc taking one u64; the JIT
 * never calls it because the kinsn descriptor provides emit_x86.
 */
__bpf_kfunc void bpf_x86_native_lab_emit(u64 arg0)
{
	(void)arg0;
}
__bpf_kfunc_end_defs();

BTF_KFUNCS_START(bpf_x86_native_lab_kfunc_ids)
BTF_ID_FLAGS(func, bpf_x86_native_lab_emit)
BTF_KFUNCS_END(bpf_x86_native_lab_kfunc_ids)

#if !__has_include(<linux/bpf_native.h>)
static int decode_native_lab_payload(u64 payload, u32 *blob_id, u32 *abi_mask)
{
	payload = kinsn_payload_decode(payload);

	if (payload & 0xf)
		return -EINVAL;
	if (((payload >> 4) & 0xf) & ~NATIVE_LAB_ABI_MASK)
		return -EINVAL;
	if ((payload >> 17) & 0x7)
		return -EINVAL;
	/* Generations bind the verified path, which this module does not serve. */
	if (payload >> 20)
		return -EOPNOTSUPP;

	*blob_id = (u32)((payload >> 8) & 0x1ff);
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
	pr_err_ratelimited("bpf_x86_native_lab: emit failed reason=%s err=%d payload=0x%llx blob=%u len=%zu relocs=%zu reloc_index=%zu reloc_offset=%u reloc_kind=%u reloc_target=0x%llx\n",
			   reason, err, (unsigned long long)payload, blob_id,
			   blob_len, reloc_count, reloc_index, reloc_offset,
			   reloc_kind, (unsigned long long)reloc_target);
}

/* The verifier sees r0=0 and the ABI register marks, nothing of the blob. */
static int instantiate_native_lab(u64 payload, struct bpf_insn *insn_buf)
{
	u32 abi_mask = 0;
	u32 blob_id;
	int err;
	int cnt = 0;

	err = decode_native_lab_payload(payload, &blob_id, &abi_mask);
	if (err)
		return err;

	if (!insn_buf)
		return hweight32(abi_mask) + 1;

	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MOV, BPF_REG_0, 0);
	if (abi_mask & NATIVE_LAB_ABI_RBX)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_0);
	if (abi_mask & NATIVE_LAB_ABI_R13)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_7, BPF_REG_0);
	if (abi_mask & NATIVE_LAB_ABI_R14)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_8, BPF_REG_0);
	if (abi_mask & NATIVE_LAB_ABI_R15)
		insn_buf[cnt++] = BPF_MOV64_REG(BPF_REG_9, BPF_REG_0);
	return cnt;
}

static int native_lab_map_target(const struct native_lab_reloc_record *reloc,
				 const struct bpf_prog *prog, u64 *target)
{
	u32 id = (u32)reloc->target, offset = reloc->target >> 32, i;

	for (i = 0; i < prog->aux->used_map_cnt; i++) {
		struct bpf_map *map = prog->aux->used_maps[i];
		int err;

		if (map->id != id)
			continue;
		if (reloc->kind == NATIVE_LAB_RELOC_MAP_POINTER) {
			if (offset)
				return -EINVAL;
			*target = (unsigned long)map;
			return 0;
		}
		if (!map->ops->map_direct_value_addr || offset >= map->value_size)
			return -EINVAL;
		err = map->ops->map_direct_value_addr(map, target, offset);
		if (!err)
			*target += offset;
		return err;
	}
	return -ENOENT;
}

static int native_lab_emit_literal(const struct native_lab_reloc_record *reloc,
				   const u8 *blob, size_t length, u8 *destination,
				   const struct bpf_prog *prog)
{
	u64 target;
	int err = 0;

	if ((size_t)reloc->offset + sizeof(target) > length)
		return -ERANGE;
	if (memchr_inv(blob + reloc->offset, 0, sizeof(target)))
		return -EINVAL;
	if (reloc->kind == NATIVE_LAB_RELOC_HELPER_POINTER)
		target = reloc->target;
	else
		err = native_lab_map_target(reloc, prog, &target);
	if (!err)
		memcpy(destination + reloc->offset, &target, sizeof(target));
	return err;
}

static int native_lab_apply_reloc(const struct native_lab_reloc_record *r,
				  struct native_blob *blob, u8 *emit_at,
				  const u8 *final_emit_at,
				  const struct bpf_prog *prog, u64 payload,
				  u32 blob_id, size_t index)
{
	static const u8 rel32_slot[5] = { 0xe8, 0, 0, 0, 0 };
	s64 disp64;
	s32 disp;
	int err;

	switch (r->kind) {
	case NATIVE_LAB_RELOC_READONLY_DATA:
		return 0;
	case NATIVE_LAB_RELOC_MAP_POINTER:
	case NATIVE_LAB_RELOC_MAP_VALUE:
	case NATIVE_LAB_RELOC_HELPER_POINTER:
		return native_lab_emit_literal(r, blob->bytes, blob->len,
					       emit_at, prog);
	case NATIVE_LAB_RELOC_X86_TAIL_COUNT:
	case NATIVE_LAB_RELOC_X86_TAIL_STACK:
		/* The wrapper's physical BPF stack depth is zero, matching the
		 * stock JIT: a 4-byte slot holds -16 for the tail-call counter
		 * and 0 for the saved frame depth.
		 */
		if ((size_t)r->offset + sizeof(disp) > blob->len) {
			native_lab_emit_error("reloc_slot", -ERANGE, payload,
					      blob_id, blob->len, blob->reloc_count,
					      index, r->offset, r->kind, r->target);
			return -ERANGE;
		}
		disp = r->kind == NATIVE_LAB_RELOC_X86_TAIL_COUNT ? -16 : 0;
		memcpy(emit_at + r->offset, &disp, sizeof(disp));
		return 0;
	case NATIVE_LAB_RELOC_HELPER_CALL_REL32:
		err = 0;
		if ((size_t)r->offset + sizeof(rel32_slot) > blob->len)
			err = -ERANGE;
		else if (memcmp(emit_at + r->offset, rel32_slot, sizeof(rel32_slot)))
			err = -EINVAL;
		else if (!final_emit_at)
			err = -EINVAL;
		if (err) {
			native_lab_emit_error("reloc_slot", err, payload, blob_id,
					      blob->len, blob->reloc_count, index,
					      r->offset, r->kind, r->target);
			return err;
		}
		disp64 = (s64)r->target -
			 (s64)((u64)final_emit_at + r->offset + sizeof(rel32_slot));
		disp = (s32)disp64;
		if ((s64)disp != disp64) {
			native_lab_emit_error("rel32_out_of_range", -ERANGE, payload,
					      blob_id, blob->len, blob->reloc_count,
					      index, r->offset, r->kind, r->target);
			return -ERANGE;
		}
		memcpy(emit_at + r->offset + 1, &disp, sizeof(disp));
		return 0;
	default:
		native_lab_emit_error("unknown_reloc_kind", -EINVAL, payload,
				      blob_id, blob->len, blob->reloc_count,
				      index, r->offset, r->kind, r->target);
		return -EINVAL;
	}
}

static int emit_native_lab_x86(u8 *image, u32 *off, bool emit, u64 payload,
			       const struct bpf_prog *prog, const u8 *final_ip)
{
	struct native_blob *blob;
	size_t snapshot_len;
	u32 blob_id;
	size_t i;
	int err;

	err = decode_native_lab_payload(payload, &blob_id, NULL);
	if (err) {
		native_lab_emit_error("decode_payload", err, payload, 0, 0, 0,
				      0, 0, 0, 0);
		return err;
	}

	mutex_lock(&blobs_lock);
	blob = &blobs[blob_id];
	if (!blob->bytes || !blob->len) {
		mutex_unlock(&blobs_lock);
		native_lab_emit_error("missing_blob", -ENOENT, payload, blob_id,
				      0, 0, 0, 0, 0, 0);
		return -ENOENT;
	}
	snapshot_len = blob->len;
	if (emit) {
		u8 *emit_at = image + *off;
		const u8 *final_emit_at = final_ip ? final_ip + *off : NULL;

		memcpy(emit_at, blob->bytes, snapshot_len);
		for (i = 0; i < blob->reloc_count; i++) {
			err = native_lab_apply_reloc(&blob->relocs[i], blob, emit_at,
						     final_emit_at, prog, payload,
						     blob_id, i);
			if (err) {
				mutex_unlock(&blobs_lock);
				return err;
			}
		}
	}
	mutex_unlock(&blobs_lock);

	*off += snapshot_len;
	return snapshot_len;
}

#endif
#if __has_include(<linux/bpf_native.h>)
/*
 * Stock native line: the JIT takes one whole image armed for this task
 * (bpf_native_image_arm / bpf_native_image_take) and emits it directly. The
 * loader uploads a program's blob as chunks blob0..blobN-1 in order, so every
 * write re-arms the concatenation of the chunks uploaded so far, each chunk's
 * relocation offsets moved by the chunk's start; the last write before
 * BPF_PROG_LOAD leaves the whole image armed.
 */
static int native_lab_arm_chunks(void)
{
	struct bpf_native_image *image;
	struct bpf_native_reloc *relocs = NULL;
	size_t len = 0, nr = 0, off = 0, k = 0;
	u8 *bytes;
	u32 i, j;

	for (i = 0; i < NATIVE_LAB_MAX_BLOBS && blobs[i].bytes; i++) {
		len += blobs[i].len;
		nr += blobs[i].reloc_count;
	}
	if (!len)
		return 0;
	bytes = kvmalloc(len, GFP_KERNEL);
	if (!bytes)
		return -ENOMEM;
	if (nr) {
		relocs = kvcalloc(nr, sizeof(*relocs), GFP_KERNEL);
		if (!relocs) {
			kvfree(bytes);
			return -ENOMEM;
		}
	}
	for (i = 0; i < NATIVE_LAB_MAX_BLOBS && blobs[i].bytes; i++) {
		memcpy(bytes + off, blobs[i].bytes, blobs[i].len);
		for (j = 0; j < blobs[i].reloc_count; j++, k++) {
			relocs[k].offset = off + blobs[i].relocs[j].offset;
			relocs[k].kind = blobs[i].relocs[j].kind;
			relocs[k].target = blobs[i].relocs[j].target;
		}
		off += blobs[i].len;
	}
	image = kzalloc(sizeof(*image), GFP_KERNEL);
	if (!image) {
		kvfree(bytes);
		kvfree(relocs);
		return -ENOMEM;
	}
	image->bytes = bytes;
	image->len = len;
	image->relocs = relocs;
	image->nr_relocs = nr;
	bpf_native_image_arm(image);
	return 0;
}
#else
const struct bpf_kinsn bpf_x86_native_lab_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 5,
	.native_proof = true,
	.max_emit_bytes = NATIVE_LAB_MAX_BLOB_BYTES,
	.instantiate_insn = instantiate_native_lab,
	.emit_x86 = emit_native_lab_x86,
};

static const struct bpf_kinsn * const bpf_x86_native_lab_kinsn_descs[] = {
	&bpf_x86_native_lab_desc,
};
#endif

/* ---- debugfs: bpf_x86_native_lab/blob<N> and blob<N>.relocs ---- */

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
		return -EINVAL; /* whole-file writes only */
	if (len > NATIVE_LAB_MAX_BLOB_BYTES)
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
#if __has_include(<linux/bpf_native.h>)
	/* Chunk 0 starts a new program: drop the chunks a longer one left. */
	if (priv->id == 0) {
		int k;

		for (k = 1; k < NATIVE_LAB_MAX_BLOBS; k++) {
			kfree(blobs[k].bytes);
			kfree(blobs[k].relocs);
			memset(&blobs[k], 0, sizeof(blobs[k]));
		}
	}
#endif
	kfree(blobs[priv->id].bytes);
	/* Reuploading the blob invalidates any previously uploaded relocs. */
	kfree(blobs[priv->id].relocs);
	blobs[priv->id].relocs = NULL;
	blobs[priv->id].reloc_count = 0;
	blobs[priv->id].bytes = kbuf;
	blobs[priv->id].len = len;
#if __has_include(<linux/bpf_native.h>)
	{
		int err = native_lab_arm_chunks();

		if (err) {
			mutex_unlock(&blobs_lock);
			return err;
		}
	}
#endif
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
#if __has_include(<linux/bpf_native.h>)
	{
		int err = native_lab_arm_chunks();

		if (err) {
			mutex_unlock(&blobs_lock);
			return err;
		}
	}
#endif
	mutex_unlock(&blobs_lock);

	*ppos = len;
	return len;
}

static ssize_t blob_read(struct file *file, char __user *ubuf, size_t len,
			 loff_t *ppos)
{
	struct blob_file_priv *priv = file->private_data;
	u8 stash[NATIVE_LAB_MAX_BLOB_BYTES];
	size_t copy_len;
	size_t blen;

	mutex_lock(&blobs_lock);
	blen = blobs[priv->id].len;
	if (blen)
		memcpy(stash, blobs[priv->id].bytes, blen);
	mutex_unlock(&blobs_lock);

	if (*ppos >= blen)
		return 0;
	copy_len = min(len, blen - (size_t)*ppos);
	if (copy_to_user(ubuf, stash + *ppos, copy_len))
		return -EFAULT;
	*ppos += copy_len;
	return copy_len;
}

static int blob_open(struct inode *inode, struct file *file)
{
	struct blob_file_priv *priv;

	priv = kmalloc(sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;
	priv->id = (u32)(long)inode->i_private;
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

static void native_lab_free_blobs(void)
{
	int i;

	mutex_lock(&blobs_lock);
	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		kfree(blobs[i].bytes);
		kfree(blobs[i].relocs);
		memset(&blobs[i], 0, sizeof(blobs[i]));
	}
	mutex_unlock(&blobs_lock);
}

static const struct btf_kfunc_id_set bpf_x86_native_lab_kfunc_set = {
	.owner = THIS_MODULE,
	.set = &bpf_x86_native_lab_kfunc_ids,
#if !__has_include(<linux/bpf_native.h>)
	.kinsn_descs = bpf_x86_native_lab_kinsn_descs,
#endif
};

static int __init bpf_x86_native_lab_init(void)
{
	long i;
	int err;

	debugfs_root = debugfs_create_dir("bpf_x86_native_lab", NULL);
	if (IS_ERR(debugfs_root))
		return PTR_ERR(debugfs_root);

	debugfs_create_file("map_ptr", 0600, debugfs_root, NULL, &map_ptr_fops);
	debugfs_create_file("helper_targets", 0600, debugfs_root, NULL, &helper_targets_fops);
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

	err = register_btf_kfunc_id_set(BPF_PROG_TYPE_UNSPEC,
					&bpf_x86_native_lab_kfunc_set);
	if (err) {
		debugfs_remove_recursive(debugfs_root);
		native_lab_free_blobs();
		return err;
	}

	pr_warn("bpf_x86_native_lab: measurement-only direct-native module loaded; native code skips verification, for timing only\n");
	return 0;
}

static void __exit bpf_x86_native_lab_exit(void)
{
	debugfs_remove_recursive(debugfs_root);
	native_lab_free_blobs();
}

module_init(bpf_x86_native_lab_init);
module_exit(bpf_x86_native_lab_exit);

MODULE_DESCRIPTION("BpfReJIT x86 native-code lab, measurement-only direct-native blob path (timing only; skips verification)");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
MODULE_IMPORT_NS("BPF_INTERNAL");
