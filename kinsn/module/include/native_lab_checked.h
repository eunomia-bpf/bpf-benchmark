/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_CHECKED_H
#define NATIVE_LAB_CHECKED_H
#include "native_lab_checked_wire.h"

static bool native_lab_capture_checked;
module_param_named(capture_checked, native_lab_capture_checked, bool, 0600);
MODULE_PARM_DESC(capture_checked, "Capture exact verified expanded proof before restoration");
static void *native_lab_checked_bytes;
static size_t native_lab_checked_size;
static struct native_lab_emitted_site native_lab_emitted_sites[NATIVE_LAB_MAX_BLOBS];

/* All callers hold blobs_lock. Mutation invalidates stale program evidence. */
static void native_lab_forget_checked(void)
{
	kvfree(native_lab_checked_bytes);
	native_lab_checked_bytes = NULL;
	native_lab_checked_size = 0;
	memset(native_lab_emitted_sites, 0, sizeof(native_lab_emitted_sites));
}

static bool native_lab_checked_map_insn(const struct bpf_insn *insn)
{
	return insn->code == (BPF_LD | BPF_DW | BPF_IMM) &&
	       (insn->src_reg == BPF_PSEUDO_MAP_FD || insn->src_reg == BPF_PSEUDO_MAP_VALUE);
}

static int native_lab_capture_proof(const struct native_blob *root, u32 generation,
				    const struct bpf_verifier_env *env)
{
	struct native_lab_checked_header header = {
		.version = 1, .prog_insns = env->prog->len,
		.regions = env->kinsn_region_cnt, .actual_generation = generation,
		.binding = root->binding,
	};
	struct native_lab_checked_region *regions;
	struct native_lab_checked_map *maps;
	struct native_lab_checked_helper *helpers;
	void *snapshot;
	size_t size;
	u32 i, m = 0, h = 0;

	if (!native_lab_capture_checked)
		return 0;
	for (i = 0; i < env->prog->len; i++) {
		const struct bpf_insn *insn = &env->prog->insnsi[i];
		if (native_lab_checked_map_insn(insn))
			header.map_refs++;
		if (insn->code == (BPF_JMP | BPF_CALL) && !insn->src_reg)
			header.helper_refs++;
	}
	size = sizeof(header) + (size_t)header.prog_insns * sizeof(struct bpf_insn) +
		(size_t)header.regions * sizeof(*regions) +
		(size_t)header.map_refs * sizeof(*maps) +
		(size_t)header.helper_refs * sizeof(*helpers);
	snapshot = kvzalloc(size, GFP_KERNEL);
	if (!snapshot)
		return -ENOMEM;
	memcpy(snapshot, &header, sizeof(header));
	memcpy((u8 *)snapshot + sizeof(header), env->prog->insnsi,
	       (size_t)header.prog_insns * sizeof(struct bpf_insn));
	regions = snapshot + sizeof(header) + (size_t)header.prog_insns * sizeof(struct bpf_insn);
	maps = (void *)(regions + header.regions);
	helpers = (void *)(maps + header.map_refs);
	for (i = 0; i < header.regions; i++) {
		regions[i].start = env->kinsn_regions[i].start;
		regions[i].insns = env->kinsn_regions[i].proof_len;
		regions[i].payload = env->kinsn_regions[i].payload;
	}
	for (i = 0; i < env->prog->len; i++) {
		const struct bpf_insn *insn = &env->prog->insnsi[i];
		if (native_lab_checked_map_insn(insn)) {
			u32 index = env->insn_aux_data[i].map_index;
			struct bpf_map *map;
			if (i + 1 >= env->prog->len || index >= env->used_map_cnt) {
				kvfree(snapshot);
				return -EINVAL;
			}
			map = env->used_maps[index];
			maps[m++] = (struct native_lab_checked_map) {
				.insn = i, .id = map->id, .value_offset = env->insn_aux_data[i].map_off,
				.type = map->map_type, .key_size = map->key_size, .value_size = map->value_size,
				.max_entries = map->max_entries, .flags = map->map_flags,
				.pointer = (u32)insn->imm | ((u64)(u32)env->prog->insnsi[i + 1].imm << 32),
			};
		}
		if (insn->code == (BPF_JMP | BPF_CALL) && !insn->src_reg) {
			const struct bpf_func_proto *proto = env->ops->get_func_proto(insn->imm, env->prog);
			if (!proto) {
				kvfree(snapshot);
				return -EINVAL;
			}
			helpers[h++] = (struct native_lab_checked_helper) {
				.insn = i, .id = insn->imm, .function = (unsigned long)proto->func,
			};
		}
	}
	native_lab_forget_checked();
	native_lab_checked_bytes = snapshot;
	native_lab_checked_size = size;
	return 0;
}

struct native_lab_checked_reader { void *bytes; size_t size; };
static int native_lab_checked_open(struct inode *inode, struct file *file)
{
	struct native_lab_checked_reader *reader;
	int err = 0;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	reader = kzalloc(sizeof(*reader), GFP_KERNEL);
	if (!reader)
		return -ENOMEM;
	mutex_lock(&blobs_lock);
	if (!native_lab_checked_bytes) {
		err = -ENODATA;
	} else {
		reader->bytes = kvmalloc(native_lab_checked_size, GFP_KERNEL);
		if (!reader->bytes)
			err = -ENOMEM;
		else {
			reader->size = native_lab_checked_size;
			memcpy(reader->bytes, native_lab_checked_bytes, reader->size);
		}
	}
	mutex_unlock(&blobs_lock);
	if (err) {
		kfree(reader);
		return err;
	}
	file->private_data = reader;
	return 0;
}
static ssize_t native_lab_checked_read(struct file *file, char __user *buffer, size_t size, loff_t *offset)
{
	struct native_lab_checked_reader *reader = file->private_data;
	return simple_read_from_buffer(buffer, size, offset, reader->bytes, reader->size);
}
static int native_lab_checked_release(struct inode *inode, struct file *file)
{
	struct native_lab_checked_reader *reader = file->private_data;
	kvfree(reader->bytes);
	kfree(reader);
	return 0;
}
static const struct file_operations native_lab_checked_fops = {
	.owner = THIS_MODULE, .open = native_lab_checked_open, .read = native_lab_checked_read,
	.release = native_lab_checked_release, .llseek = default_llseek,
};

/* Called with blobs_lock after the final generation/context recheck. The
 * address comes from the JIT's final RX image, never its temporary scratch. */
static int native_lab_capture_emit(u32 blob_id, u32 generation, u32 abi_mask,
				   const void *final_ip)
{
	const struct native_lab_checked_header *checked = native_lab_checked_bytes;

	if (!checked || blob_id >= checked->binding.chunk_count ||
	    checked->actual_generation != blobs[checked->binding.blob_id].generation)
		return -ESTALE;
	native_lab_emitted_sites[blob_id] = (struct native_lab_emitted_site) {
		.blob_id = blob_id, .generation = generation,
		.native_size = blobs[blob_id].len, .abi_mask = abi_mask,
		.address = (unsigned long)final_ip,
	};
	return 0;
}

static int native_lab_emitted_open(struct inode *inode, struct file *file)
{
	struct native_lab_checked_reader *reader;
	const struct native_lab_checked_header *checked;
	struct native_lab_emitted_header header;
	u32 i;
	int err = 0;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;
	reader = kzalloc(sizeof(*reader), GFP_KERNEL);
	if (!reader)
		return -ENOMEM;
	mutex_lock(&blobs_lock);
	checked = native_lab_checked_bytes;
	if (!checked) {
		err = -ENODATA;
		goto unlock;
	}
	header = (struct native_lab_emitted_header) {
		.version = 1, .sites = checked->binding.chunk_count,
		.source_prog_id = checked->binding.source_prog_id,
	};
	for (i = 0; i < header.sites; i++) {
		if (!native_lab_emitted_sites[i].address ||
		    native_lab_emitted_sites[i].generation != blobs[i].generation) {
			err = -ENODATA;
			goto unlock;
		}
	}
	reader->size = sizeof(header) + header.sites * sizeof(native_lab_emitted_sites[0]);
	reader->bytes = kvmalloc(reader->size, GFP_KERNEL);
	if (!reader->bytes) {
		err = -ENOMEM;
		goto unlock;
	}
	memcpy(reader->bytes, &header, sizeof(header));
	memcpy(reader->bytes + sizeof(header), native_lab_emitted_sites,
	       header.sites * sizeof(native_lab_emitted_sites[0]));
unlock:
	mutex_unlock(&blobs_lock);
	if (err) {
		kfree(reader);
		return err;
	}
	file->private_data = reader;
	return 0;
}
static const struct file_operations native_lab_emitted_fops = {
	.owner = THIS_MODULE, .open = native_lab_emitted_open, .read = native_lab_checked_read,
	.release = native_lab_checked_release, .llseek = default_llseek,
};

#endif
