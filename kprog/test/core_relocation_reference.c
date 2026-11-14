/* One-time, userspace CO-RE measurement using libbpf's actual ELF records,
 * candidate search and instruction patching. Never loads a BPF program. */
#include <fcntl.h>
#include <gelf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include "libbpf_internal.h"
#include "relo_core.h"

#define REQUIRE(C) do { if (!(C)) { fprintf(stderr, "line %d: %s\n", __LINE__, #C); return 1; } } while (0)

int main(int argc, char **argv)
{
    REQUIRE(argc == 3);
    struct btf_ext *ext = NULL;
    struct btf *local = btf__parse_elf(argv[1], &ext);
    struct btf *target = btf__parse(argv[2], NULL);
    REQUIRE(local && target && !libbpf_get_error(local) && !libbpf_get_error(target));
    REQUIRE(ext && elf_version(EV_CURRENT) != EV_NONE);
    struct bpf_core_cand_list *cache = calloc(btf__type_cnt(local), sizeof(*cache));
    bool *seen = calloc(btf__type_cnt(local), sizeof(*seen));
    REQUIRE(cache && seen);
    int fd = open(argv[1], O_RDONLY);
    REQUIRE(fd >= 0);
    Elf *elf = elf_begin(fd, ELF_C_READ, NULL);
    size_t strings;
    REQUIRE(elf && elf_getshdrstrndx(elf, &strings) == 0);
    puts("section\tinsn_off\tlocal_type_id\troot\tkind\taccess\tspec\toriginal\tresolved\tpoison\toriginal_bytes\ttarget_bytes\tfail_memsz_adjust\tpatched_code\tpatched_offset\tpatched_immediate");
    struct btf_ext_info *segment = &ext->core_relo_info;
    struct btf_ext_info_sec *sec;
    unsigned int i, count = 0;
    struct bpf_core_relo *relo;
    for_each_btf_ext_sec(segment, sec) {
        const char *name = btf__name_by_offset(local, sec->sec_name_off);
        REQUIRE(name);
        Elf_Scn *section = NULL;
        Elf_Data *data = NULL;
        while ((section = elf_nextscn(elf, section))) {
            GElf_Shdr header;
            REQUIRE(gelf_getshdr(section, &header));
            const char *section_name = elf_strptr(elf, strings, header.sh_name);
            REQUIRE(section_name);
            if (!strcmp(section_name, name)) { data = elf_getdata(section, NULL); break; }
        }
        REQUIRE(data && data->d_size % sizeof(struct bpf_insn) == 0);
        struct bpf_insn *code = malloc(data->d_size);
        REQUIRE(code);
        memcpy(code, data->d_buf, data->d_size);
        for_each_btf_ext_rec(segment, sec, i, relo) {
            REQUIRE(relo->type_id < btf__type_cnt(local));
            const struct btf_type *type = btf__type_by_id(local, relo->type_id);
            REQUIRE(type);
            const char *root = btf__name_by_offset(local, type->name_off);
            const char *access = btf__name_by_offset(local, relo->access_str_off);
            REQUIRE(root && access && relo->insn_off % sizeof(*code) == 0);
            REQUIRE(relo->insn_off < data->d_size);
            struct bpf_core_cand_list *candidates = &cache[relo->type_id];
            if (!seen[relo->type_id]) {
                struct bpf_core_cand source = {local, relo->type_id};
                REQUIRE(bpf_core_add_cands(&source, bpf_core_essential_name_len(root),
                                          target, "vmlinux", 1, candidates) == 0);
                seen[relo->type_id] = true;
            }
            struct bpf_core_spec specs[3] = {};
            struct bpf_core_relo_res result = {};
            REQUIRE(bpf_core_calc_relo_insn(name, relo, count, local,
                                           candidates, specs, &result) == 0);
            char spec[4096];
            REQUIRE(bpf_core_format_spec(spec, sizeof(spec), &specs[0]) >= 0);
            unsigned int index = relo->insn_off / sizeof(*code);
            if (code[index].code == (BPF_LD | BPF_DW | BPF_IMM))
                REQUIRE(index + 1 < data->d_size / sizeof(*code));
            REQUIRE(bpf_core_patch_insn(name, code + index, index, relo, count, &result) == 0);
            printf("%s\t%u\t%u\t%s\t%u\t%s\t%s\t%llu\t%llu\t%d\t%u\t%u\t%d\t%u\t%d\t%d\n",
                   name, relo->insn_off, relo->type_id, root, relo->kind, access, spec,
                   (unsigned long long)result.orig_val, (unsigned long long)result.new_val,
                   result.poison, result.orig_sz, result.new_sz, result.fail_memsz_adjust,
                   code[index].code, code[index].off, code[index].imm);
            ++count;
        }
        free(code);
    }
    for (i = 0; i < btf__type_cnt(local); ++i) bpf_core_free_cands(&cache[i]);
    free(cache); free(seen);
    elf_end(elf);
    REQUIRE(close(fd) == 0 && !ferror(stdout));
    btf_ext__free(ext); btf__free(local); btf__free(target);
    return 0;
}
