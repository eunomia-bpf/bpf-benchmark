/* SPDX-License-Identifier: GPL-2.0 */
#ifndef NATIVE_LAB_GROUP_H
#define NATIVE_LAB_GROUP_H

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
		const u8 *blob, size_t length, u8 *destination, struct bpf_map *const *maps, u32 map_count)
{
	u64 target;
	int err;

	if ((size_t)reloc->offset + sizeof(target) > length)
		return -ERANGE;
	if (reloc->kind == NATIVE_LAB_RELOC_HELPER_POINTER) {
		target = reloc->target;
		err = 0;
	} else {
		err = native_lab_map_target(reloc, maps, map_count, &target);
	}
	if (!err)
		memcpy(destination + reloc->offset, &target, sizeof(target));
	return err;
}


#endif
