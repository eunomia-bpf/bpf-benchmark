/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_GROUP_H
#define NATIVE_LAB_GROUP_H

/* Included after native_blob/blobs and decode_native_lab_payload in each
 * module. The final chunk owns a generation vector for the entire program.
 * All callers hold blobs_lock.
 */
static int native_lab_group_metadata(const struct native_lab_binding *member,
				     const struct native_lab_binding *root,
				     u32 offset)
{
	if (member->chunk_count != root->chunk_count ||
	    member->chunk_offset != offset ||
	    member->total_native_size != root->total_native_size ||
	    member->arch != root->arch || member->abi_version != root->abi_version ||
	    member->abi_mask != root->abi_mask ||
	    member->prog_type != root->prog_type ||
	    member->expected_attach_type != root->expected_attach_type)
		return -EINVAL;
	return 0;
}

/* Prepare the group before changing its final chunk's generation. Earlier
 * chunks must already be sealed and occupy contiguous native byte ranges.
 */
static int native_lab_group_prepare(const struct native_lab_binding *last,
				    u32 **generations)
{
	u32 *snapshot, offset = 0, i;
	int err;

	*generations = NULL;
	if (last->blob_id + 1 != last->chunk_count)
		return 0;
	snapshot = kmalloc_array(last->chunk_count, sizeof(*snapshot), GFP_KERNEL);
	if (!snapshot)
		return -ENOMEM;
	for (i = 0; i < last->chunk_count; i++) {
		const struct native_blob *blob = &blobs[i];
		const struct native_lab_binding *b = i == last->blob_id ? last : &blob->binding;

		if (i != last->blob_id) {
			err = native_lab_binding_use(b, last->arch, i, blob->len,
				blob->reloc_count, blob->proof_len,
				blob->generation, last->abi_mask);
			if (err)
				goto fail;
		}
		err = native_lab_group_metadata(b, last, offset);
		if (err)
			goto fail;
		offset += b->native_size;
		snapshot[i] = blob->generation + (i == last->blob_id);
	}
	if (offset != last->total_native_size) {
		err = -EINVAL;
		goto fail;
	}
	*generations = snapshot;
	return 0;
fail:
	kfree(snapshot);
	return err;
}

static int native_lab_group_use(u32 blob_id, u32 generation, u32 abi_mask)
{
	const struct native_blob *blob = &blobs[blob_id], *root;
	const struct native_lab_binding *b = &blob->binding;
	u32 i, offset = 0;
	int err;

	err = native_lab_binding_use(b, NATIVE_LAB_BINDING_ARCH, blob_id,
		blob->len, blob->reloc_count, blob->proof_len, generation, abi_mask);
	if (err)
		return err;
	root = &blobs[b->chunk_count - 1];
	if (!root->bound_generations ||
	    root->binding.chunk_count != b->chunk_count)
		return -ESTALE;
	for (i = 0; i < b->chunk_count; i++) {
		const struct native_blob *member = &blobs[i];

		if (member->generation != root->bound_generations[i])
			return -ESTALE;
		err = native_lab_binding_use(&member->binding,
			NATIVE_LAB_BINDING_ARCH, i, member->len,
			member->reloc_count, member->proof_len,
			member->generation, abi_mask);
		if (err)
			return err;
		err = native_lab_group_metadata(&member->binding, &root->binding, offset);
		if (err)
			return err;
		offset += member->binding.native_size;
	}
	return offset == root->binding.total_native_size ? 0 : -EINVAL;
}

/* Check the JIT's actual restored BPF stream: exactly one consecutive ordered
 * group, identical call identity, and no BPF edge into a proper suffix. This
 * prevents a proof for [chunk0,chunk1] authorizing [chunk1,chunk0] or [chunk1].
 */
static int native_lab_group_program(const struct bpf_prog *prog, u32 blob_id)
{
	const struct native_lab_binding *b = &blobs[blob_id].binding;
	u32 first = prog->len, end, i;
	const struct bpf_insn *call;

	for (i = 0; i < prog->len; i++)
		if (bpf_kinsn_is_sidecar_insn(&prog->insnsi[i])) {
			first = i;
			break;
		}
	if (first == prog->len || b->chunk_count > (prog->len - first) / 2)
		return -EINVAL;
	end = first + 2 * b->chunk_count;
	call = &prog->insnsi[first + 1];
	for (i = 0; i < b->chunk_count; i++) {
		const struct bpf_insn *sidecar = &prog->insnsi[first + 2 * i];
		const struct bpf_insn *next = sidecar + 1;
		u32 id, abi, gen;
		int err;

		if (!bpf_kinsn_is_sidecar_insn(sidecar) ||
		    next->code != (BPF_JMP | BPF_CALL) ||
		    next->src_reg != BPF_PSEUDO_KINSN_CALL ||
		    next->imm != call->imm || next->off != call->off)
			return -EINVAL;
		err = decode_native_lab_payload(bpf_kinsn_sidecar_payload(sidecar),
						&id, &abi, &gen);
		if (err)
			return err;
		if (id != i || abi != b->abi_mask || gen != blobs[i].generation)
			return -ESTALE;
	}
	for (i = 0; i < prog->len; i++) {
		const struct bpf_insn *insn = &prog->insnsi[i];
		u8 cls = BPF_CLASS(insn->code), op = BPF_OP(insn->code);
		s64 target;

		if (i >= first && i < end)
			continue;
		if (bpf_kinsn_is_sidecar_insn(insn))
			return -EINVAL;
		if ((cls != BPF_JMP && cls != BPF_JMP32) ||
		    op == BPF_CALL || op == BPF_EXIT)
			continue;
		target = (s64)i + 1 +
			(cls == BPF_JMP32 && op == BPF_JA ? insn->imm : insn->off);
		if (target > first && target < end)
			return -EINVAL;
	}
	return 0;
}

#endif
