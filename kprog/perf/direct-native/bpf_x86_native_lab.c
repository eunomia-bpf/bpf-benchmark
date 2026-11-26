// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT x86 native-code lab.
 *
 * Test-only: userspace uploads a program's linked x86-64 bytes as chunks
 * blob0..blobN-1 with their call relocations, then writes the callee-saved
 * mask to "arm". The module arms the concatenated image for the writing task
 * (bpf_native_image_arm); that task's next BPF_PROG_LOAD with
 * BPF_F_NATIVE_IMAGE binds it and the x86 JIT emits it in place of the loaded
 * program: stock frame, the image, stock return.
 *
 * Safety: the image runs without verifier guarantees. Do NOT load on
 * production kernels. Upload requires CAP_SYS_ADMIN and the debugfs nodes are
 * root-only.
 *
 * ABI the image respects: it falls through to the stock return with the
 * result in rax. native-link may strip RBX/R13-R15 saves only when the mask
 * asks the JIT frame to save those registers.
 */

#include <linux/bpf.h>
#include <linux/debugfs.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/unaligned.h>

#include <linux/bpf_native.h>
/* helper_targets: the function the kernel calls for each helper ID of a loaded program. */
#include "../../stock-path/module/native_lab_helper_query_impl.h"
#include "../../x86/micro-prog/native_hash.h"
#include "native_hash_layout.h"

__KPROG_HASH_CODE

/* Return the element; native-link retains value/LRU/per-CPU/map-in-map handling.
 * Small keys and the larger string keys used by the corpus share the same C.
 */
#define KPROG_HTAB_KEY(N) \
noinline void *kprog_htab_elem_k##N(void *map, const void *key) \
{ return __kprog_hash_elem(map, key, N, KPROG_HASH_LAYOUT); } \
EXPORT_SYMBOL_GPL(kprog_htab_elem_k##N);
#define KPROG_HTAB_KEYS_8(A, B, C, D, E, F, G, H) \
KPROG_HTAB_KEY(A) KPROG_HTAB_KEY(B) KPROG_HTAB_KEY(C) KPROG_HTAB_KEY(D) \
KPROG_HTAB_KEY(E) KPROG_HTAB_KEY(F) KPROG_HTAB_KEY(G) KPROG_HTAB_KEY(H)
KPROG_HTAB_KEYS_8(1, 2, 3, 4, 5, 6, 7, 8)
KPROG_HTAB_KEYS_8(9, 10, 11, 12, 13, 14, 15, 16)
KPROG_HTAB_KEYS_8(17, 18, 19, 20, 21, 22, 23, 24)
KPROG_HTAB_KEYS_8(25, 26, 27, 28, 29, 30, 31, 32)
KPROG_HTAB_KEYS_8(33, 34, 35, 36, 37, 38, 39, 40)
KPROG_HTAB_KEYS_8(41, 42, 43, 44, 45, 46, 47, 48)
KPROG_HTAB_KEYS_8(49, 50, 51, 52, 53, 54, 55, 56)
KPROG_HTAB_KEYS_8(57, 58, 59, 60, 61, 62, 63, 64)
KPROG_HTAB_KEY(224)
KPROG_HTAB_KEY(256)
#undef KPROG_HTAB_KEYS_8
#undef KPROG_HTAB_KEY

#define NATIVE_LAB_MAX_BLOBS	2048
/* Userspace uploads a program as consecutive chunks of at most this size
 * (x86 128, arm64 256). The same source builds bpf_arm64_native_lab.ko (Kbuild).
 */
#define NATIVE_LAB_MAX_BLOB_BYTES	256
#ifdef CONFIG_ARM64
#define NATIVE_LAB_DIRECTORY		"bpf_arm64_native_lab"
#else
#define NATIVE_LAB_DIRECTORY		"bpf_x86_native_lab"
#endif

/*
 * Stage 2 side-band relocations:
 *
 * Userspace native-link can't compute a helper call's rel32 displacement,
 * because that depends on where the JIT places the image. The blob ships a
 * `call rel32` placeholder and a separate `relocs` array describing each
 * patch site; the JIT patches the displacement (BPF_NATIVE_RELOC_CALL_REL32,
 * the same value). Out-of-range targets fail load.
 *
 * relocs are uploaded via a sibling debugfs file blob<N>.relocs whose
 * payload is a tightly packed array of `struct native_lab_reloc_record`.
 */
#define NATIVE_LAB_RELOC_HELPER_CALL_REL32	1
#define NATIVE_LAB_MAX_RELOCS		32
#define NATIVE_LAB_ABI_RBX		(1U << 0)
#define NATIVE_LAB_ABI_R13		(1U << 1)
#define NATIVE_LAB_ABI_R14		(1U << 2)
#define NATIVE_LAB_ABI_R15		(1U << 3)
#define NATIVE_LAB_ABI_MASK		(NATIVE_LAB_ABI_RBX | \
					 NATIVE_LAB_ABI_R13 | \
					 NATIVE_LAB_ABI_R14 | \
					 NATIVE_LAB_ABI_R15)

struct native_lab_reloc_record {
	__u32 offset;   /* byte offset of the helper call placeholder */
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

/* A memory read of the image: global offset, instruction length, GPR number. */
struct native_lab_load_site {
	__u32 offset;
	__u16 insn_len;
	__u16 destination;
};
static struct native_lab_load_site *load_sites;
static size_t load_site_count;
static DEFINE_MUTEX(blobs_lock);
static struct dentry *debugfs_root;

static u32 callee_saved_mask;

/* Arm the concatenation of the uploaded chunks for the calling task. The
 * caller holds blobs_lock.
 */
static int native_lab_arm(void)
{
	struct bpf_native_image *image;
	struct bpf_native_reloc *relocs = NULL;
	struct bpf_native_site *sites = NULL;
	size_t len = 0, nr = 0, off = 0, k = 0, ns = 0;
	u8 *bytes;
	u32 i, j;

	for (i = 0; i < NATIVE_LAB_MAX_BLOBS && blobs[i].bytes; i++) {
		len += blobs[i].len;
		nr += blobs[i].reloc_count;
	}
	if (!len)
		return -ENOENT;
	image = kzalloc(sizeof(*image), GFP_KERNEL);
	bytes = kvmalloc(len, GFP_KERNEL);
	if (nr)
		relocs = kvcalloc(nr, sizeof(*relocs), GFP_KERNEL);
	if (load_site_count)
		sites = kvcalloc(load_site_count, sizeof(*sites), GFP_KERNEL);
	if (!image || !bytes || (nr && !relocs) || (load_site_count && !sites)) {
		kfree(image);
		kvfree(bytes);
		kvfree(relocs);
		kvfree(sites);
		return -ENOMEM;
	}
#ifdef CONFIG_X86_64
	/* x86 EX_TYPE_BPF fixup: skip insn_len bytes, zero the pt_regs slot. */
	for (i = 0; i < load_site_count; i++) {
		static const u16 regs[] = {
			offsetof(struct pt_regs, ax), offsetof(struct pt_regs, cx),
			offsetof(struct pt_regs, dx), offsetof(struct pt_regs, bx),
			offsetof(struct pt_regs, sp), offsetof(struct pt_regs, bp),
			offsetof(struct pt_regs, si), offsetof(struct pt_regs, di),
			offsetof(struct pt_regs, r8), offsetof(struct pt_regs, r9),
			offsetof(struct pt_regs, r10), offsetof(struct pt_regs, r11),
			offsetof(struct pt_regs, r12), offsetof(struct pt_regs, r13),
			offsetof(struct pt_regs, r14), offsetof(struct pt_regs, r15),
		};
		const struct native_lab_load_site *s = &load_sites[i];

		if (s->destination >= ARRAY_SIZE(regs) || s->offset >= len ||
		    s->insn_len > len - s->offset)
			continue;
		sites[ns].offset = s->offset;
		sites[ns].fixup = s->insn_len | ((u32)regs[s->destination] << 8);
		ns++;
	}
#endif
	for (i = 0; i < NATIVE_LAB_MAX_BLOBS && blobs[i].bytes; i++) {
		memcpy(bytes + off, blobs[i].bytes, blobs[i].len);
		for (j = 0; j < blobs[i].reloc_count; j++, k++) {
			relocs[k].offset = off + blobs[i].relocs[j].offset;
			relocs[k].kind = blobs[i].relocs[j].kind;
			relocs[k].target = blobs[i].relocs[j].target;
		}
		off += blobs[i].len;
	}
#ifdef CONFIG_ARM64
	/* arm64 EX_TYPE_BPF fixup for a native load (BPF_NATIVE_ARM64_LOAD): zero the
	 * destination, both registers of a pair load, and skip the instruction
	 * (5e3836051, lost in 3aa496416).
	 */
	for (i = 0; i < load_site_count; i++) {
		const struct native_lab_load_site *s = &load_sites[i];
		u32 word, reg, fixup;

		if (s->offset >= len || len - s->offset < AARCH64_INSN_SIZE)
			continue;
		word = get_unaligned_le32(bytes + s->offset);
		reg = s->destination < 31 ? s->destination : 31;
		fixup = BPF_NATIVE_ARM64_LOAD | (reg << 27);
		if ((word & 0x3e400000U) == 0x28400000U || (word & 0x3fe00000U) == 0x08600000U)
			fixup |= BPF_NATIVE_ARM64_PAIR | (((word >> 10) & 31) << 16);
		else if ((word & 0xbfa07c00U) == 0x08207c00U)
			fixup |= BPF_NATIVE_ARM64_PAIR | (((reg + 1) & 31) << 16);
		sites[ns].offset = s->offset;
		sites[ns].fixup = fixup;
		ns++;
	}
#endif
	image->bytes = bytes;
	image->len = len;
	image->relocs = relocs;
	image->nr_relocs = nr;
	image->sites = sites;
	image->nr_sites = ns;
	image->callee_saved_mask = callee_saved_mask;
	bpf_native_image_arm(image);
	return 0;
}

/* ---- debugfs: /sys/kernel/debug/bpf_x86_native_lab/blob<id> ----
 *
 * Write: overwrite blob N with raw bytes (max NATIVE_LAB_MAX_BLOB_BYTES).
 * Truncate to zero length: unregister blob N.
 * Read: read back current blob bytes (debug aid).
 */

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
	/* Chunk 0 starts a new program: drop the chunks a longer one left. */
	if (priv->id == 0) {
		int k;

		for (k = 1; k < NATIVE_LAB_MAX_BLOBS; k++) {
			kfree(blobs[k].bytes);
			kfree(blobs[k].relocs);
			memset(&blobs[k], 0, sizeof(blobs[k]));
		}
		kvfree(load_sites);
		load_sites = NULL;
		load_site_count = 0;
	}
	kfree(blobs[priv->id].bytes);
	/* Reuploading the blob invalidates any previously uploaded relocs. */
	kfree(blobs[priv->id].relocs);
	blobs[priv->id].relocs = NULL;
	blobs[priv->id].reloc_count = 0;
	blobs[priv->id].bytes = kbuf;
	blobs[priv->id].len = len;
	mutex_unlock(&blobs_lock);

	*ppos = len;
	return len;
}

/*
 * relocs debugfs file: whole-file write of a packed array of
 * native_lab_reloc_record. Truncate to 0 to clear.
 */
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

static const struct file_operations relocs_fops = {
	.owner = THIS_MODULE,
	.open = blob_open,
	.release = blob_release,
	.write = relocs_write,
	.llseek = default_llseek,
};

/* "sites": whole-file write of the program's load sites, global offsets. */
static ssize_t sites_write(struct file *file, const char __user *ubuf,
			   size_t len, loff_t *ppos)
{
	struct native_lab_load_site *sites;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	if (*ppos || !len || len % sizeof(*sites) ||
	    len > NATIVE_LAB_MAX_BLOBS * NATIVE_LAB_MAX_BLOB_BYTES * sizeof(*sites))
		return -EINVAL;
	sites = vmemdup_user(ubuf, len);
	if (IS_ERR(sites))
		return PTR_ERR(sites);
	mutex_lock(&blobs_lock);
	kvfree(load_sites);
	load_sites = sites;
	load_site_count = len / sizeof(*sites);
	mutex_unlock(&blobs_lock);
	*ppos = len;
	return len;
}

static const struct file_operations sites_fops = {
	.owner = THIS_MODULE,
	.write = sites_write,
	.llseek = default_llseek,
};

/* "arm": write the callee-saved mask after the last chunk. */
static ssize_t arm_write(struct file *file, const char __user *ubuf,
			 size_t len, loff_t *ppos)
{
	u32 mask;
	int err;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	err = kstrtou32_from_user(ubuf, len, 0, &mask);
	if (err)
		return err;
	if (mask & ~NATIVE_LAB_ABI_MASK)
		return -EINVAL;
	mutex_lock(&blobs_lock);
	callee_saved_mask = mask;
	err = native_lab_arm();
	mutex_unlock(&blobs_lock);
	return err ? err : len;
}

static const struct file_operations arm_fops = {
	.owner = THIS_MODULE,
	.write = arm_write,
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

static int __init bpf_x86_native_lab_debugfs_init(void)
{
	long i;

	debugfs_root = debugfs_create_dir(NATIVE_LAB_DIRECTORY, NULL);
	if (IS_ERR(debugfs_root))
		return PTR_ERR(debugfs_root);

	debugfs_create_file("map_ptr", 0600, debugfs_root, NULL,
			    &map_ptr_fops);
	debugfs_create_file("map_value_ptr", 0600, debugfs_root, NULL,
			    &map_value_ptr_fops);
	debugfs_create_file("arm", 0200, debugfs_root, NULL, &arm_fops);
	debugfs_create_file("sites", 0200, debugfs_root, NULL, &sites_fops);
	debugfs_create_file("helper_targets", 0600, debugfs_root, NULL, &helper_targets_fops);

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

static void bpf_x86_native_lab_debugfs_exit(void)
{
	int i;

	debugfs_remove_recursive(debugfs_root);
	debugfs_root = NULL;

	mutex_lock(&blobs_lock);
	for (i = 0; i < NATIVE_LAB_MAX_BLOBS; i++) {
		kfree(blobs[i].bytes);
		kfree(blobs[i].relocs);
		blobs[i].bytes = NULL;
		blobs[i].len = 0;
		blobs[i].relocs = NULL;
		blobs[i].reloc_count = 0;
	}
	mutex_unlock(&blobs_lock);
}

static int __init bpf_x86_native_lab_init(void)
{
	return bpf_x86_native_lab_debugfs_init();
}

static void __exit bpf_x86_native_lab_exit(void)
{
	bpf_x86_native_lab_debugfs_exit();
}

module_init(bpf_x86_native_lab_init);
module_exit(bpf_x86_native_lab_exit);

MODULE_DESCRIPTION("BpfReJIT x86 native-code lab (test only; bypasses verifier guarantees)");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BpfReJIT");
MODULE_IMPORT_NS("BPF_INTERNAL");
