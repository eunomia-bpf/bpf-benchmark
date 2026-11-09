// SPDX-License-Identifier: GPL-2.0
/* kprog stock-path native submission: the trusted service stores P's linked
 * image here, the stock verifier checks B, and the JIT emits the stored copy.
 * Same transport as the native-lab module; no kfunc, sidecar or proof region. */
#include <linux/bpf.h>
#include <linux/bpf_native.h>
#include <linux/btf.h>
#include <linux/debugfs.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/ptrace.h>
#define NATIVE_LAB_ARCH_X86 1U
#define NATIVE_LAB_BINDING_ARCH NATIVE_LAB_ARCH_X86
#include "native_lab_trusted.h"

static struct dentry *debugfs_root;

static void free_partial_image(struct bpf_native_image *image)
{
	kvfree(image->bytes);
	kvfree(image->relocs);
	kvfree(image->sites);
	kfree(image);
}

/* Registers are indexed by x86 encoding; fixup matches the stock handler. */
static u32 site_fixup(const struct native_lab_load_site *site)
{
	static const u16 registers[] = {
		offsetof(struct pt_regs, ax), offsetof(struct pt_regs, cx),
		offsetof(struct pt_regs, dx), offsetof(struct pt_regs, bx),
		offsetof(struct pt_regs, sp), offsetof(struct pt_regs, bp),
		offsetof(struct pt_regs, si), offsetof(struct pt_regs, di),
		offsetof(struct pt_regs, r8), offsetof(struct pt_regs, r9),
		offsetof(struct pt_regs, r10), offsetof(struct pt_regs, r11),
		offsetof(struct pt_regs, r12), offsetof(struct pt_regs, r13),
		offsetof(struct pt_regs, r14), offsetof(struct pt_regs, r15),
	};
	u32 reg = site->destination < ARRAY_SIZE(registers) ?
		registers[site->destination] : 1; /* stock DONT_CLEAR */

	return site->insn_len | (reg << 8);
}

static int native_lab_store_chunk(void __user *argument)
{
	struct native_lab_trusted_chunk input;
	struct native_lab_trusted_capsule *capsule;
	struct native_lab_load_site *sites = NULL;
	struct bpf_native_site *image_sites = NULL;
	struct bpf_native_image *image;
	const void *copy;
	u32 i;
	int err = 0;

	if (copy_from_user(&input, argument, sizeof(input)))
		return -EFAULT;
	capsule = native_lab_active_capsule(input.request_id);
	if (IS_ERR(capsule))
		return PTR_ERR(capsule);
	image = kzalloc(sizeof(*image), GFP_KERNEL);
	if (!image) {
		err = -ENOMEM;
		goto out;
	}
	image->len = input.native_size;
	copy = vmemdup_user(u64_to_user_ptr(input.native_user), input.native_size);
	if (IS_ERR(copy)) {
		err = PTR_ERR(copy);
		goto fail;
	}
	image->bytes = copy;
	if (input.reloc_count) {
		copy = vmemdup_user(u64_to_user_ptr(input.relocs_user),
			array_size(input.reloc_count, sizeof(*image->relocs)));
		if (IS_ERR(copy)) {
			err = PTR_ERR(copy);
			goto fail;
		}
		image->relocs = copy;
		image->nr_relocs = input.reloc_count;
	}
	if (input.load_site_count) {
		sites = vmemdup_user(u64_to_user_ptr(input.load_sites_user),
			array_size(input.load_site_count, sizeof(*sites)));
		if (IS_ERR(sites)) {
			err = PTR_ERR(sites);
			sites = NULL;
			goto fail;
		}
		image_sites = kvmalloc_array(input.load_site_count, sizeof(*image_sites),
					     GFP_KERNEL);
		if (!image_sites) {
			err = -ENOMEM;
			goto fail;
		}
		for (i = 0; i < input.load_site_count; i++) {
			image_sites[i].offset = sites[i].offset;
			image_sites[i].fixup = site_fixup(&sites[i]);
		}
		image->sites = image_sites;
		image->nr_sites = input.load_site_count;
		kvfree(sites);
		sites = NULL;
	}
	bpf_native_image_arm(image);
	input.chunk_id = 1;
	err = copy_to_user(argument, &input, sizeof(input)) ? -EFAULT : 0;
	goto out;
fail:
	kvfree(sites);
	free_partial_image(image);
out:
	native_lab_trusted_put(capsule);
	return err;
}

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


static int __init kprog_stock_init(void)
{
	debugfs_root = debugfs_create_dir("bpf_x86_native_lab", NULL);
	if (IS_ERR(debugfs_root))
		return PTR_ERR(debugfs_root);
	debugfs_create_file("native_submit", 0600, debugfs_root, NULL, &native_lab_trusted_fops);
	debugfs_create_file("specializer", 0600, debugfs_root, (void *)1, &native_lab_trusted_fops);
	debugfs_create_file("map_ptr", 0600, debugfs_root, NULL, &map_ptr_fops);
	debugfs_create_file("map_value_ptr", 0600, debugfs_root, NULL, &map_value_ptr_fops);
	debugfs_create_file("map_update_elem", 0600, debugfs_root, NULL, &map_update_elem_fops);
	return 0;
}

static void __exit kprog_stock_exit(void)
{
	debugfs_remove_recursive(debugfs_root);
}

module_init(kprog_stock_init);
module_exit(kprog_stock_exit);
MODULE_DESCRIPTION("kprog stock-path trusted native submission");
MODULE_LICENSE("GPL");
MODULE_IMPORT_NS("BPF_INTERNAL");
