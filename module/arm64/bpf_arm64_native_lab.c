// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT arm64 native-code lab kinsn.
 *
 * Test-only escape hatch matching the x86 native_lab shape: userspace
 * uploads an arbitrary AArch64 instruction stream through debugfs, then a
 * BPF kinsn call splats those instructions inline into the BPF JIT image.
 *
 * Safety: this intentionally bypasses verifier guarantees for the emitted
 * native instructions. Do not load on production kernels.
 *
 * ABI contract:
 *  - Blob length must be a non-zero multiple of 4 bytes.
 *  - Blob is emitted in the middle of a JITted BPF function and must fall
 *    through to the next BPF instruction; do not end it with RET.
 *  - BPF r0 is arm64 x7 in the kernel BPF JIT. Set x7 before falling
 *    through if the native blob wants to choose the BPF program retval.
 *  - BPF r1 is arm64 x0 on entry, so an XDP native blob sees the xdp_buff
 *    pointer in x0 when the stub calls this kfunc.
 */

#include <linux/capability.h>
#include <linux/debugfs.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/unaligned.h>

#include "kinsn_common.h"

#define NATIVE_LAB_MAX_BLOBS		64
/*
 * arch/arm64/net/bpf_jit_comp.c currently allows at most 64 arm64
 * instructions from one kinsn callback.
 */
#define NATIVE_LAB_MAX_BLOB_BYTES	256

struct native_blob {
	u8 *bytes;
	size_t len;
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

static int decode_native_lab_payload(u64 payload, u32 *blob_id)
{
	payload = kinsn_payload_decode(payload);

	if (payload & 0xf)
		return -EINVAL;
	if ((payload >> 4) & 0xffff)
		return -EINVAL;

	*blob_id = (u32)(payload >> 20);
	if (*blob_id >= NATIVE_LAB_MAX_BLOBS)
		return -EINVAL;

	return 0;
}

static int instantiate_native_lab(u64 payload, struct bpf_insn *insn_buf)
{
	u32 blob_id;
	int err;

	err = decode_native_lab_payload(payload, &blob_id);
	if (err)
		return err;

	insn_buf[0] = BPF_ALU64_IMM(BPF_MOV, BPF_REG_0, 0);
	return 1;
}

static int emit_native_lab_arm64(u32 *image, int *idx, bool emit, u64 payload,
				 const struct bpf_prog *prog)
{
	size_t snapshot_len = 0;
	u8 snapshot[NATIVE_LAB_MAX_BLOB_BYTES];
	u32 blob_id;
	size_t i;
	int err;

	(void)prog;

	err = decode_native_lab_payload(payload, &blob_id);
	if (err)
		return err;
	if (!idx)
		return -EINVAL;
	if (emit && !image)
		return -EINVAL;

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
		memcpy(snapshot, blobs[blob_id].bytes, snapshot_len);
	}
	mutex_unlock(&blobs_lock);

	if (!snapshot_len)
		return -ENOENT;

	if (emit) {
		for (i = 0; i < snapshot_len; i += sizeof(u32))
			image[*idx + (i / sizeof(u32))] =
				get_unaligned_le32(snapshot + i);
	}

	*idx += snapshot_len / sizeof(u32);
	return snapshot_len / sizeof(u32);
}

const struct bpf_kinsn bpf_arm64_native_lab_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
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
	blobs[priv->id].bytes = kbuf;
	blobs[priv->id].len = len;
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

static int __init bpf_arm64_native_lab_debugfs_init(void)
{
	long i;

	debugfs_root = debugfs_create_dir("bpf_arm64_native_lab", NULL);
	if (IS_ERR(debugfs_root))
		return PTR_ERR(debugfs_root);

	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		char name[24];

		scnprintf(name, sizeof(name), "blob%ld", i);
		debugfs_create_file(name, 0600, debugfs_root, (void *)i,
				    &blob_fops);
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
		blobs[i].bytes = NULL;
		blobs[i].len = 0;
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

MODULE_DESCRIPTION("BpfReJIT arm64 native-code lab kinsn (test only; bypasses verifier guarantees)");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
