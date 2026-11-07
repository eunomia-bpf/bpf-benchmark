/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_GROUP_H
#define NATIVE_LAB_GROUP_H

#include "native_lab_map_offset.h"
#include "native_lab_exclusive.h"
#include "native_lab_checked.h"

/* Included after native_blob/blobs and decode_native_lab_payload in each
 * module. The final chunk owns a generation vector for the entire program.
 * All callers hold blobs_lock.
 */
static void native_lab_put_maps(struct bpf_map **maps, u32 count)
{
	while (count)
		bpf_map_put(maps[--count]);
	kfree(maps);
}

static void native_lab_release_binding_objects(struct native_blob *blob)
{
	native_lab_trusted_put(blob->trusted);
	blob->trusted = NULL;
	native_lab_put_maps(blob->bound_maps, blob->bound_map_count);
	blob->bound_maps = NULL;
	blob->bound_map_count = 0;
	if (blob->bound_source)
		bpf_prog_put(blob->bound_source);
	if (blob->bound_target)
		bpf_prog_put(blob->bound_target);
	blob->bound_source = NULL;
	blob->bound_target = NULL;
}

/* Pinned programs keep the original BTF/token/device context alive. Raw
 * attributes are compared as well as resolved object identities, so FD/ID reuse
 * and identical-looking contexts never replace the sealed objects.
 */
static int native_lab_context_matches(const struct native_lab_binding *b,
		const struct bpf_prog *prog, const struct bpf_prog *source,
		const struct bpf_prog *target)
{
	struct btf *actual_btf, *expected_btf;
	int err = 0;

	if (!prog || !source || b->source_prog_id != source->aux->id ||
	    b->prog_type != prog->type ||
	    b->expected_attach_type != prog->expected_attach_type ||
	    b->prog_flags != prog->aux->native_load_flags ||
	    b->prog_ifindex != prog->aux->native_load_ifindex ||
	    b->gpl_compatible != prog->gpl_compatible ||
	    b->attach_btf_id != prog->aux->attach_btf_id ||
	    prog->aux->token != source->aux->token ||
	    (b->prog_ifindex && !bpf_prog_dev_bound_match(prog, source)))
		return -EINVAL;
	if (!!prog->aux->func_info_cnt != !!source->aux->func_info_cnt ||
	    (source->aux->func_info_cnt &&
	     (prog->aux->btf != source->aux->btf ||
	      prog->aux->func_info[0].insn_off || source->aux->func_info[0].insn_off ||
	      prog->aux->func_info[0].type_id != source->aux->func_info[0].type_id)))
		return -EINVAL;
	mutex_lock(&prog->aux->dst_mutex);
	actual_btf = prog->aux->dst_prog ? prog->aux->dst_prog->aux->btf : prog->aux->attach_btf;
	expected_btf = target ? target->aux->btf : source->aux->attach_btf;
	if (prog->aux->dst_prog != target || actual_btf != expected_btf ||
	    b->attach_btf_obj_id != (actual_btf ? btf_obj_id(actual_btf) : 0) ||
	    b->attach_prog_id != (target ? target->aux->id : 0))
		err = -EINVAL;
	mutex_unlock(&prog->aux->dst_mutex);
	return err;
}

static int native_lab_pin_context(const struct native_lab_binding *b,
		struct bpf_prog **source_out, struct bpf_prog **target_out)
{
	struct bpf_prog *source, *target = NULL;
	int err;

	source = bpf_prog_by_id(b->source_prog_id);
	if (IS_ERR(source))
		return PTR_ERR(source);
	if (b->attach_prog_id) {
		target = bpf_prog_by_id(b->attach_prog_id);
		if (IS_ERR(target)) {
			err = PTR_ERR(target);
			target = NULL;
			goto fail;
		}
	}
	err = native_lab_context_matches(b, source, source, target);
	if (err)
		goto fail;
	*source_out = source;
	*target_out = target;
	return 0;
fail:
	if (target)
		bpf_prog_put(target);
	bpf_prog_put(source);
	return err;
}

static int native_lab_pin_maps(const struct native_blob *blob,
			       struct bpf_map ***maps_out, u32 *count_out)
{
	struct bpf_map **maps;
	u32 count = 0;
	size_t i;

	*maps_out = NULL;
	*count_out = 0;
	if (!blob->reloc_count)
		return 0;
	maps = kmalloc_array(blob->reloc_count, sizeof(*maps), GFP_KERNEL);
	if (!maps)
		return -ENOMEM;
	for (i = 0; i < blob->reloc_count; i++) {
		const struct native_lab_reloc_record *reloc = &blob->relocs[i];
		struct bpf_map *map;
		u32 id = (u32)reloc->target;

		if (reloc->kind != NATIVE_LAB_RELOC_MAP_POINTER &&
		    reloc->kind != NATIVE_LAB_RELOC_MAP_VALUE &&
		    reloc->kind != NATIVE_LAB_RELOC_READONLY_DATA)
			continue;
		map = bpf_map_get_curr_or_next(&id);
		if (!map || id != (u32)reloc->target) {
			if (map)
				bpf_map_put(map);
			native_lab_put_maps(maps, count);
			return -ENOENT;
		}
		if (reloc->kind == NATIVE_LAB_RELOC_READONLY_DATA &&
		    (reloc->offset || map->map_type != BPF_MAP_TYPE_ARRAY ||
		     map->key_size != sizeof(u32) || map->max_entries != 1 ||
		     !(map->map_flags & BPF_F_RDONLY_PROG) || !READ_ONCE(map->frozen))) {
			bpf_map_put(map);
			native_lab_put_maps(maps, count);
			return -EINVAL;
		}
		maps[count++] = map;
	}
	*maps_out = maps;
	*count_out = count;
	return 0;
}

/* Called only after checking every group member's immutable generation. A data
 * extent can cross chunk boundaries; its address is relative to the complete
 * consecutive native group, not to a proof-map address or an ELF file offset.
 */
static int native_lab_readonly_data(const struct native_blob *root)
{
	u32 chunk;

	for (chunk = 0; chunk < root->binding.chunk_count; chunk++) {
		const struct native_blob *owner = &blobs[chunk];
		size_t r;

		for (r = 0; r < owner->reloc_count; r++) {
			const struct native_lab_reloc_record *reloc = &owner->relocs[r];
			struct bpf_map *map = NULL;
			const u8 *value;
			u32 key = 0, i, done = 0;
			u64 offset = reloc->target >> 32;

			if (reloc->kind != NATIVE_LAB_RELOC_READONLY_DATA)
				continue;
			for (i = 0; i < owner->bound_map_count; i++)
				if (owner->bound_maps[i]->id == (u32)reloc->target)
					map = owner->bound_maps[i];
			if (!map || offset > root->binding.total_native_size ||
			    map->value_size > root->binding.total_native_size - offset)
				return -EINVAL;
			value = map->ops->map_lookup_elem(map, &key);
			if (!value)
				return -EINVAL;
			for (i = 0; i < root->binding.chunk_count && done < map->value_size; i++) {
				const struct native_blob *part = &blobs[i];
				u32 begin = part->binding.chunk_offset;
				u32 within, count;
				size_t p;

				if (offset < begin || offset >= (u64)begin + part->len)
					continue;
				within = offset - begin;
				count = min_t(u32, part->len - within, map->value_size - done);
				for (p = 0; p < part->reloc_count; p++) {
					const struct native_lab_reloc_record *patch = &part->relocs[p];
					int size = native_lab_reloc_patch_size(patch->kind);

					if (size < 0 || (size && patch->offset < (u64)within + count &&
					    within < (u64)patch->offset + size))
						return -EINVAL;
				}
				if (memcmp(part->bytes + within, value + done, count))
					return -EINVAL;
				done += count;
				offset += count;
			}
			if (done != map->value_size)
				return -EINVAL;
		}
	}
	return 0;
}

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
	    member->expected_attach_type != root->expected_attach_type ||
	    memcmp(&member->prog_flags, &root->prog_flags, 8 * sizeof(u32)))
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

/* A descriptor belongs to its native chunk but names the final chunk's real
 * proof. Earlier chunks contain only the continuation proof, never this one.
 */
static int native_lab_exclusive_environment(const struct native_blob *root)
{
	u32 chunk, i;
	size_t r;

	for (chunk = 0; chunk < root->binding.chunk_count; chunk++) {
		const struct native_blob *owner = &blobs[chunk];

		for (r = 0; r < owner->reloc_count; r++) {
			const struct native_lab_reloc_record *reloc = &owner->relocs[r];

			if (reloc->kind != NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE)
				continue;
			if (root->binding.arch != NATIVE_LAB_ARCH_ARM64 ||
			    !native_lab_exclusive_match(owner->bytes, owner->len,
				reloc->offset, root->proof, root->proof_len,
				(u32)reloc->target, reloc->target >> 32))
				return -EINVAL;
		}
	}
	for (i = 0; i < root->proof_len; i++) {
		u32 matches = 0;

		if (root->proof[i].code == (BPF_LD | BPF_DW | BPF_IMM)) {
			i++;
			continue;
		}
		if (!native_lab_exclusive_marker(&root->proof[i]))
			continue;
		for (chunk = 0; chunk < root->binding.chunk_count; chunk++) {
			const struct native_blob *owner = &blobs[chunk];

			for (r = 0; r < owner->reloc_count; r++)
				if (owner->relocs[r].kind == NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE &&
				    (u32)owner->relocs[r].target == i)
					matches++;
		}
		if (matches != 1)
			return -EINVAL;
	}
	return 0;
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
	if (!root->trusted || !root->bound_generations ||
	    root->binding.chunk_count != b->chunk_count)
		return -ESTALE;
	for (i = 0; i < b->chunk_count; i++) {
		const struct native_blob *member = &blobs[i];

		if (member->trusted != root->trusted)
			return -EXDEV;
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
	if (offset != root->binding.total_native_size)
		return -EINVAL;
	err = native_lab_exclusive_environment(root);
	if (err)
		return err;
	return native_lab_readonly_data(root);
}

/* Check the JIT's actual restored BPF stream: exactly one consecutive ordered
 * group plus EXIT, with identical call identity and no surrounding code. This
 * prevents a proof for [chunk0,chunk1] authorizing [chunk1,chunk0] or [chunk1].
 */
static int native_lab_group_program(const struct bpf_prog *prog, u32 blob_id)
{
	const struct native_lab_binding *b = &blobs[blob_id].binding;
	u32 first = 0, i;
	const struct bpf_insn *call;
	int context_err = native_lab_context_matches(b, prog,
		blobs[blob_id].bound_source, blobs[blob_id].bound_target);

	if (context_err)
		return context_err;
	if (prog->len != 2 * b->chunk_count + 1 ||
	    prog->insnsi[prog->len - 1].code != (BPF_JMP | BPF_EXIT))
		return -EINVAL;
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
	return 0;
}


/* Run before proof lowering as well as checking the restored JIT stream.
 * Generation-zero explicitly unbound experiments retain their legacy ABI.
 */
static int native_lab_validate_program(u64 payload, const struct bpf_prog *prog)
{
	u32 blob_id, abi_mask, generation;
	int err = decode_native_lab_payload(payload, &blob_id, &abi_mask, &generation);

	if (err || !generation)
		return err;
	mutex_lock(&blobs_lock);
	err = native_lab_group_use(blob_id, generation, abi_mask);
	if (!err)
		err = native_lab_group_program(prog, blob_id);
	mutex_unlock(&blobs_lock);
	return err;
}

/* Stable kernel map ID and optional value offset, never a userspace FD. */
static int native_lab_map_target(const struct native_lab_reloc_record *reloc,
				struct bpf_map *const *maps, u32 count, u64 *target)
{
	u32 id = (u32)reloc->target, offset = reloc->target >> 32, i;

	for (i = 0; i < count; i++) {
		struct bpf_map *map = maps[i];
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
		const u8 *blob, size_t length, u8 *destination, const struct bpf_prog *prog)
{
	u64 target;
	int err;

	if ((size_t)reloc->offset + sizeof(target) > length)
		return -ERANGE;
	if (memchr_inv(blob + reloc->offset, 0, sizeof(target)))
		return -EINVAL;
	if (reloc->kind == NATIVE_LAB_RELOC_HELPER_POINTER) {
		target = reloc->target;
		err = 0;
	} else {
		err = native_lab_map_target(reloc, prog->aux->used_maps,
					    prog->aux->used_map_cnt, &target);
	}
	if (!err)
		memcpy(destination + reloc->offset, &target, sizeof(target));
	return err;
}

/* Use the same map operations/generator as verifier do_misc_fixups, including
 * its generated internal hash lookup call. No second specialization table. */
static int native_lab_map_helper_target(const struct bpf_verifier_env *env,
					u32 index, u64 target)
{
	const struct bpf_insn_aux_data *aux = &env->insn_aux_data[index];
	const struct bpf_insn *call = &env->prog->insnsi[index];
	struct bpf_map *map = aux->map_ptr_state.map_ptr;
	struct bpf_insn *generated;
	bool found = false;
	int count, i;

	if (aux->map_ptr_state.poison || !map)
		return false;
	if (call->imm == BPF_FUNC_map_update_elem)
		return (unsigned long)map->ops->map_update_elem == target;
	if (call->imm != BPF_FUNC_map_lookup_elem)
		return false;
	if ((unsigned long)map->ops->map_lookup_elem == target)
		return true;
	if (!map->ops->map_gen_lookup)
		return false;
	generated = kcalloc(INSN_BUF_SIZE, sizeof(*generated), GFP_KERNEL);
	if (!generated)
		return -ENOMEM;
	count = map->ops->map_gen_lookup(map, generated);
	if (count > 0 && count < INSN_BUF_SIZE)
		for (i = 0; i < count; i++)
			if (generated[i].code == (BPF_JMP | BPF_CALL) &&
			    !generated[i].src_reg &&
			    (u64)((s64)(unsigned long)__bpf_call_base + generated[i].imm) == target)
				found = true;
	kfree(generated);
	if (count < 0 && count != -EOPNOTSUPP)
		return count;
	if (count != -EOPNOTSUPP && (count <= 0 || count >= INSN_BUF_SIZE))
		return -EFAULT;
	return found;
}

/* Called once for the final generation while all expanded proofs and resolved
 * map identities remain present. fd_array retention alone is insufficient.
 */
static int native_lab_validate_proof(u64 payload, const struct bpf_verifier_env *env)
{
	u32 blob_id, abi_mask, generation, chunk;
	int err = decode_native_lab_payload(payload, &blob_id, &abi_mask, &generation);

	if (err || !generation)
		return err;
	mutex_lock(&blobs_lock);
	err = native_lab_group_use(blob_id, generation, abi_mask);
	if (err || blob_id + 1 != blobs[blob_id].binding.chunk_count)
		goto out;
	for (chunk = 0; chunk <= blob_id; chunk++) {
		const struct native_blob *blob = &blobs[chunk];
		size_t r;

		for (r = 0; r < blob->reloc_count; r++) {
			const struct native_lab_reloc_record *reloc = &blob->relocs[r];
			bool found = false;
			u32 i;

			if (reloc->kind == NATIVE_LAB_RELOC_READONLY_DATA) {
				for (i = 0; i + 1 < env->prog->len; i++) {
					const struct bpf_insn *insn = &env->prog->insnsi[i];
					u32 index;

					if (insn->code != (BPF_LD | BPF_DW | BPF_IMM) ||
					    insn->src_reg != BPF_PSEUDO_MAP_VALUE)
						continue;
					index = env->insn_aux_data[i].map_index;
					if (index < env->used_map_cnt &&
					    env->used_maps[index]->id == (u32)reloc->target)
						found = true;
					i++;
				}
			} else if (reloc->kind == NATIVE_LAB_RELOC_MAP_POINTER ||
			    reloc->kind == NATIVE_LAB_RELOC_MAP_VALUE) {
				u64 target;

				err = native_lab_map_target(reloc, env->used_maps,
							    env->used_map_cnt, &target);
				if (err)
					goto out;
				for (i = 0; i + 1 < env->prog->len; i++) {
					const struct bpf_insn *insn = &env->prog->insnsi[i];
					u32 index;

					if (insn->code != (BPF_LD | BPF_DW | BPF_IMM) ||
					    (reloc->kind == NATIVE_LAB_RELOC_MAP_POINTER ?
					     insn->src_reg != BPF_PSEUDO_MAP_FD :
					     insn->src_reg != BPF_PSEUDO_MAP_VALUE ||
					     !native_lab_map_offset_matches(env->prog->insnsi, env->prog->len, i,
						env->insn_aux_data[i].map_off, reloc->target >> 32)))
						continue;
					index = env->insn_aux_data[i].map_index;
					if (index < env->used_map_cnt &&
					    env->used_maps[index]->id == (u32)reloc->target)
						found = true;
					i++;
				}
			} else if ((reloc->kind >= 1 && reloc->kind <= 3) ||
				   reloc->kind == NATIVE_LAB_RELOC_HELPER_POINTER) {
				for (i = 0; i < env->prog->len; i++) {
					const struct bpf_insn *insn = &env->prog->insnsi[i];
					const struct bpf_func_proto *proto;

					if (insn->code != (BPF_JMP | BPF_CALL) || insn->src_reg)
						continue;
					proto = env->ops->get_func_proto(insn->imm, env->prog);
					if (proto && (unsigned long)proto->func == reloc->target) {
						found = true;
						break;
					}
					if (reloc->kind == NATIVE_LAB_RELOC_HELPER_POINTER)
						continue;
					err = native_lab_map_helper_target(env, i, reloc->target);
					if (err < 0)
						goto out;
					if (err) {
						found = true;
						err = 0;
						break;
					}
				}
			} else if (reloc->kind == NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE) {
				/* Actual code/marker match was checked across the sealed group. */
				continue;
			} else if (reloc->kind == 4) {
				/* Architecture-owned per-CPU MRS encoding, not a helper. */
				continue;
			}
			if (!found) {
				err = -EINVAL;
				goto out;
			}
		}
	}
	if (!err)
		err = native_lab_capture_proof(&blobs[blob_id], generation, env);
out:
	mutex_unlock(&blobs_lock);
	return err;
}

#endif
