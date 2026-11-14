#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int member_offset(const struct btf *btf, const struct btf_type *type,
                         const char *member, int load)
{
    const struct btf_member *members = btf_members(type);
    for (unsigned i = 0; i < btf_vlen(type); ++i) {
        const char *name = btf__name_by_offset(btf, members[i].name_off);
        unsigned bits = btf_member_bit_offset(type, i);
        if (!*name) {
            const struct btf_type *child = btf__type_by_id(btf, members[i].type);
            if (btf_is_struct(child) || btf_is_union(child)) {
                int offset = member_offset(btf, child, member, load);
                if (offset >= 0 && bits % 8 == 0) return bits / 8 + offset;
            }
        }
        if (strcmp(name, member)) continue;
        if (bits % 8 || btf_member_bitfield_size(type, i) ||
            (load && btf__resolve_size(btf, members[i].type) != 4)) {
            fprintf(stderr, "unsupported BTF field layout %s\n", member); exit(1);
        }
        return bits / 8;
    }
    return -1;
}

static unsigned field(const struct btf *btf, const char *name, const char *member, int load)
{
    int id = btf__find_by_name_kind(btf, name, BTF_KIND_STRUCT);
    if (id < 0) { fprintf(stderr, "missing BTF struct %s: %d\n", name, id); exit(1); }
    int offset = member_offset(btf, btf__type_by_id(btf, id), member, load);
    if (offset < 0) { fprintf(stderr, "missing BTF field %s.%s\n", name, member); exit(1); }
    return offset;
}

int main(int argc, char **argv)
{
    if (argc != 2) { fprintf(stderr, "usage: %s boot-matched-vmlinux\n", argv[0]); return 1; }
    struct btf *btf = btf__parse(argv[1], NULL);
    long error = libbpf_get_error(btf);
    if (error) { fprintf(stderr, "parse BTF %s: %ld\n", argv[1], error); return 1; }
    int id = btf__find_by_name_kind(btf, "bpf_map_type", BTF_KIND_ENUM);
    if (id < 0) { fprintf(stderr, "missing BTF enum bpf_map_type: %d\n", id); return 1; }
    const struct btf_type *type = btf__type_by_id(btf, id);
    const struct btf_enum *values = btf_enum(type);
    unsigned map_base = field(btf, "bpf_array", "map", 0);
    for (unsigned i = 0; i < btf_vlen(type); ++i) {
        if (strcmp(btf__name_by_offset(btf, values[i].name_off), "BPF_MAP_TYPE_ARRAY")) continue;
        int result = printf("{\"map_type\":%u,\"max_entries\":%u,\"elem_size\":%u,"
                            "\"index_mask\":%u,\"value\":%u,\"array_type\":%d}\n",
                            field(btf, "bpf_map", "map_type", 1),
                            field(btf, "bpf_map", "max_entries", 1),
                            field(btf, "bpf_array", "elem_size", 1) - map_base,
                            field(btf, "bpf_array", "index_mask", 1) - map_base,
                            field(btf, "bpf_array", "value", 0) - map_base, values[i].val) < 0;
        btf__free(btf);
        return result;
    }
    fprintf(stderr, "missing BTF enum value BPF_MAP_TYPE_ARRAY\n"); btf__free(btf); return 1;
}
