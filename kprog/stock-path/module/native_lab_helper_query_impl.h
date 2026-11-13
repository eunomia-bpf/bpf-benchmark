/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_HELPER_QUERY_IMPL_H
#define NATIVE_LAB_HELPER_QUERY_IMPL_H
#include <linux/bpf.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include "native_lab_helper_query.h"

struct helper_targets_priv {
	u64 *response;
	size_t bytes;
};

static int helper_targets_open(struct inode *inode, struct file *file)
{
	file->private_data = kzalloc(sizeof(struct helper_targets_priv), GFP_KERNEL);
	return file->private_data ? 0 : -ENOMEM;
}

static int helper_targets_release(struct inode *inode, struct file *file)
{
	struct helper_targets_priv *priv = file->private_data;

	kvfree(priv->response);
	kfree(priv);
	return 0;
}

static ssize_t helper_targets_write(struct file *file, const char __user *ubuf,
				    size_t len, loff_t *ppos)
{
	struct helper_targets_priv *priv = file->private_data;
	struct native_lab_helper_query *query;
	const struct bpf_verifier_ops *const *table;
	const struct bpf_verifier_ops *ops;
	struct bpf_prog *prog;
	u64 *response;
	u32 *ids;
	size_t count, i;
	int err;

	if (*ppos || len <= sizeof(*query) ||
	    (len - sizeof(*query)) % sizeof(*ids))
		return -EINVAL;
	query = vmemdup_user(ubuf, len);
	if (IS_ERR(query))
		return PTR_ERR(query);
	if (!query->verifier_ops) {
		err = -EINVAL;
		goto out_query;
	}
	prog = bpf_prog_get_type_dev(query->program_fd, query->program_type, false);
	if (IS_ERR(prog)) {
		err = PTR_ERR(prog);
		goto out_query;
	}
	table = (const struct bpf_verifier_ops *const *)(unsigned long)query->verifier_ops;
	/* Match bpf_check_attach_target(): freplace inherits its target's ops.
	 * The callback still receives the original program, with its attach/aux
	 * metadata, rather than an invented program containing only a type.
	 */
	ops = table[prog->type == BPF_PROG_TYPE_EXT && prog->aux->dst_prog ?
		    prog->aux->dst_prog->type : prog->type];
	count = (len - sizeof(*query)) / sizeof(*ids);
	response = kvmalloc_array(count, sizeof(*response), GFP_KERNEL);
	if (!response) {
		err = -ENOMEM;
		goto out_prog;
	}
	ids = (u32 *)(query + 1);
	for (i = 0; i < count; i++) {
		const struct bpf_func_proto *proto = ops && ops->get_func_proto ?
			ops->get_func_proto(ids[i], prog) : NULL;

		response[i] = proto ? (unsigned long)proto->func : 0;
	}
	kvfree(priv->response);
	priv->response = response;
	priv->bytes = count * sizeof(*response);
	bpf_prog_put(prog);
	kvfree(query);
	*ppos = len;
	return len;
out_prog:
	bpf_prog_put(prog);
out_query:
	kvfree(query);
	return err;
}

static ssize_t helper_targets_read(struct file *file, char __user *ubuf,
				   size_t len, loff_t *ppos)
{
	struct helper_targets_priv *priv = file->private_data;

	return simple_read_from_buffer(ubuf, len, ppos, priv->response, priv->bytes);
}

static const struct file_operations helper_targets_fops = {
	.owner = THIS_MODULE,
	.open = helper_targets_open,
	.release = helper_targets_release,
	.read = helper_targets_read,
	.write = helper_targets_write,
	.llseek = default_llseek,
};

#endif
