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
 *  - Sidecar bits 4..7 mirror x86 native_lab: request BPF r6..r9 use so
 *    the arm64 BPF JIT saves x19..x22 for raw native code.
 *  - BPF r0 is arm64 x7 in the kernel BPF JIT. Set x7 before falling
 *    through if the native blob wants to choose the BPF program retval.
 *  - BPF r1 is arm64 x0 on entry, so an XDP native blob sees the xdp_buff
 *    pointer in x0 when the stub calls this kfunc.
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

#include "kinsn_common.h"

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

static int decode_native_lab_payload(u64 payload, u32 *blob_id, u32 *abi_mask)
{
	payload = kinsn_payload_decode(payload);

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
	insn_buf[cnt++] = BPF_ALU64_IMM(BPF_MOV, BPF_REG_0, 0);
	return cnt;
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

	err = decode_native_lab_payload(payload, &blob_id, NULL);
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
	.max_insn_cnt = 5,
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
				   size_t len, loff_t *ppos, bool direct_value)
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
	return map_ptr_query_write(file, ubuf, len, ppos, false);
}

static ssize_t map_value_ptr_write(struct file *file, const char __user *ubuf,
				   size_t len, loff_t *ppos)
{
	return map_ptr_query_write(file, ubuf, len, ppos, true);
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
MODULE_IMPORT_NS("BPF_INTERNAL");
