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

static unsigned long long symbol(const char *map, const char *wanted)
{
    FILE *file = fopen(map, "r");
    if (!file) { perror(map); exit(1); }
    char line[1024], name[512], kind;
    unsigned long long address, result = 0;
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%llx %c %511s", &address, &kind, name) != 3) continue;
        if (!strcmp(name, wanted)) { result = address; ++found; }
    }
    if (ferror(file) || fclose(file) || found != 1) {
        fprintf(stderr, "missing/ambiguous target symbol %s in %s\n", wanted, map); exit(1);
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 2 && !(argc == 4 && !strcmp(argv[2], "--probe-read")) && !(argc == 3 && (!strcmp(argv[2], "--hash") || !strcmp(argv[2], "--lpm")))) {
        fprintf(stderr, "expected boot-matched-vmlinux [--probe-read matching-System.map | --hash | --lpm]"); return 1;
    }
    struct btf *btf = btf__parse(argv[1], NULL);
    long error = libbpf_get_error(btf);
    if (error) { fprintf(stderr, "parse BTF %s: %ld\n", argv[1], error); return 1; }
    if (argc == 3 && !strcmp(argv[2], "--lpm")) {
        int id = btf__find_by_name_kind(btf, "bpf_map_type", BTF_KIND_ENUM);
        if (id < 0) { fprintf(stderr, "missing bpf_map_type BTF"); return 1; }
        const struct btf_type *type = btf__type_by_id(btf, id);
        const struct btf_enum *values = btf_enum(type);
        int kind = -1;
        for (unsigned i = 0; i < btf_vlen(type); ++i)
            if (!strcmp(btf__name_by_offset(btf, values[i].name_off), "BPF_MAP_TYPE_LPM_TRIE")) kind = values[i].val;
        if (kind < 0) { fprintf(stderr, "missing LPM trie enum"); return 1; }
        unsigned base = field(btf, "lpm_trie", "map", 0);
        int result = printf("{\"map_type\":%u,\"lpm_type\":%d,\"root\":%u,"
            "\"max_prefixlen\":%u,\"data_size\":%u,\"child\":%u,\"child_stride\":%zu,"
            "\"node_prefixlen\":%u,\"node_flags\":%u,\"node_data\":%u,"
            "\"key_prefixlen\":%u,\"key_data\":%u}",
            field(btf, "bpf_map", "map_type", 1), kind,
            field(btf, "lpm_trie", "root", 0)-base,
            field(btf, "lpm_trie", "max_prefixlen", 0)-base,
            field(btf, "lpm_trie", "data_size", 0)-base,
            field(btf, "lpm_trie_node", "child", 0), btf__pointer_size(btf),
            field(btf, "lpm_trie_node", "prefixlen", 1), field(btf, "lpm_trie_node", "flags", 1),
            field(btf, "lpm_trie_node", "data", 0), field(btf, "bpf_lpm_trie_key_u8", "prefixlen", 1),
            field(btf, "bpf_lpm_trie_key_u8", "data", 0)) < 0;
        putchar(10); btf__free(btf); return result;
    }
    if (argc == 3) {
        int id = btf__find_by_name_kind(btf, "bpf_htab", BTF_KIND_STRUCT);
        if (id < 0) { fprintf(stderr, "missing bpf_htab BTF"); return 1; }
        const struct btf_type *htab = btf__type_by_id(btf, id);
        const struct btf_member *members = btf_members(htab);
        int bucket_id = -1;
        for (unsigned i = 0; i < btf_vlen(htab); ++i) {
            if (strcmp(btf__name_by_offset(btf, members[i].name_off), "buckets")) continue;
            int pointer_id = btf__resolve_type(btf, members[i].type);
            if (pointer_id < 0) break;
            const struct btf_type *pointer = btf__type_by_id(btf, pointer_id);
            if (!btf_is_ptr(pointer)) break;
            bucket_id = btf__resolve_type(btf, pointer->type);
        }
        if (bucket_id < 0) { fprintf(stderr, "missing typed bpf_htab.buckets target"); return 1; }
        const struct btf_type *bucket = btf__type_by_id(btf, bucket_id);
        long bucket_size = btf__resolve_size(btf, bucket_id);
        int head = member_offset(btf, bucket, "head", 0);
        if (bucket_size <= 0 || head < 0) { fprintf(stderr, "unsupported actual bucket layout"); return 1; }
        unsigned map_base = field(btf, "bpf_htab", "map", 0);
        int result = printf("{\"key_size\":%u,\"buckets\":%u,\"n_buckets\":%u,"
            "\"hashrnd\":%u,\"bucket_size\":%ld,\"head\":%d,\"first\":%u,"
            "\"node\":%u,\"next\":%u,\"hash\":%u,\"key\":%u}",
            field(btf, "bpf_map", "key_size", 1), field(btf, "bpf_htab", "buckets", 0)-map_base,
            field(btf, "bpf_htab", "n_buckets", 1)-map_base, field(btf, "bpf_htab", "hashrnd", 1)-map_base,
            bucket_size, head, field(btf, "hlist_nulls_head", "first", 0),
            field(btf, "htab_elem", "hash_node", 0), field(btf, "hlist_nulls_node", "next", 0),
            field(btf, "htab_elem", "hash", 1), field(btf, "htab_elem", "key", 0)) < 0;
        putchar(10); btf__free(btf); return result;
    }
    if (argc == 4) {
        int result = printf("{\"user_helper\":%llu,\"kernel_helper\":%llu,"
            "\"nmi_uaccess_okay\":%llu,\"kernel_allowed\":%llu,\"current_task\":%llu,"
            "\"user_ptr_max\":%llu,\"boot_cpu_data\":%llu,"
            "\"pagefault_disabled\":%u,\"x86_capability\":%u}\n",
            symbol(argv[3], "bpf_probe_read_user"), symbol(argv[3], "bpf_probe_read_kernel"),
            symbol(argv[3], "nmi_uaccess_okay"), symbol(argv[3], "copy_from_kernel_nofault_allowed"),
            symbol(argv[3], "const_current_task"), symbol(argv[3], "USER_PTR_MAX"),
            symbol(argv[3], "boot_cpu_data"), field(btf, "task_struct", "pagefault_disabled", 1),
            field(btf, "cpuinfo_x86", "x86_capability", 0)) < 0;
        btf__free(btf); return result;
    }
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
