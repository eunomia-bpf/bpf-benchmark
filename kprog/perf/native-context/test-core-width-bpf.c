// Use the original ELF's actual relocation records and instructions as the
// reference for resizing. This test never loads a BPF program into the kernel.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <gelf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include "libbpf_internal.h"
#include "relo_core.h"
#define REQUIRE(C) do { if (!(C)) { fprintf(stderr, "failed at line %d: %s\n", __LINE__, #C); return 1; } } while (0)
int main(int argc, char **argv) {
    REQUIRE(argc == 5);
    int signed_case = atoi(argv[4]);
    struct btf_ext *ext = NULL;
    struct btf *local = btf__parse_elf(argv[1], &ext), *target = btf__parse(argv[2], NULL);
    REQUIRE(local && target && ext && !libbpf_get_error(local) && !libbpf_get_error(target));
    int target_id = btf__find_by_name_kind(target, "task_struct", BTF_KIND_STRUCT);
    REQUIRE(target_id > 0 && elf_version(EV_CURRENT) != EV_NONE);
    int fd = open(argv[1], O_RDONLY);
    REQUIRE(fd >= 0);
    Elf *elf = elf_begin(fd, ELF_C_READ, NULL);
    size_t strings;
    REQUIRE(elf && elf_getshdrstrndx(elf, &strings) == 0);
    Elf_Scn *section = NULL;
    Elf_Data *data = NULL;
    while ((section = elf_nextscn(elf, section))) {
        GElf_Shdr header;
        REQUIRE(gelf_getshdr(section, &header));
        const char *name = elf_strptr(elf, strings, header.sh_name);
        REQUIRE(name);
        if (!strcmp(name, "test")) { data = elf_getdata(section, NULL); break; }
    }
    REQUIRE(data && data->d_size % sizeof(struct bpf_insn) == 0);
    struct bpf_insn *code = malloc(data->d_size);
    REQUIRE(code);
    memcpy(code, data->d_buf, data->d_size);
    struct btf_ext_info *segment = &ext->core_relo_info;
    struct btf_ext_info_sec *sec;
    unsigned int i, count = 0, loads = 0, stores = 0, immediates = 0, poisons = 0;
    struct bpf_core_relo *relo;
    for_each_btf_ext_sec(segment, sec) {
        REQUIRE(!strcmp(btf__name_by_offset(local, sec->sec_name_off), "test"));
        for_each_btf_ext_rec(segment, sec, i, relo) {
            REQUIRE(relo->insn_off % sizeof(*code) == 0 && relo->insn_off < data->d_size);
            struct bpf_core_spec specs[3] = {};
            struct bpf_core_relo_res result;
            struct bpf_core_cand candidate = { target, target_id };
            struct bpf_core_cand_list candidates = { &candidate, 1 };
            REQUIRE(bpf_core_calc_relo_insn("width-reference", relo, count, local, &candidates, specs, &result) == 0);
            unsigned int index = relo->insn_off / sizeof(*code);
            unsigned int old_code = code[index].code;
            REQUIRE(bpf_core_patch_insn("width-reference", code + index, index, relo, count, &result) == 0);
            printf("instruction=%u old_code=0x%x new_code=0x%x offset=%d immediate=%d original_bytes=%u target_bytes=%u fail_memsz_adjust=%d\n",
                   index, old_code, code[index].code, code[index].off, code[index].imm,
                   result.orig_sz, result.new_sz, result.fail_memsz_adjust);
            if (signed_case) {
                REQUIRE(result.fail_memsz_adjust && code[index].code == (BPF_JMP | BPF_CALL));
                ++poisons;
            } else if (BPF_CLASS(old_code) == BPF_LDX || BPF_CLASS(old_code) == BPF_STX) {
                REQUIRE(!result.fail_memsz_adjust && code[index].off == result.new_val);
                int bytes = BPF_SIZE(code[index].code) == BPF_DW ? 8 :
                            BPF_SIZE(code[index].code) == BPF_W ? 4 :
                            BPF_SIZE(code[index].code) == BPF_H ? 2 : 1;
                REQUIRE(bytes == result.new_sz);
                if (BPF_CLASS(old_code) == BPF_LDX) ++loads; else ++stores;
            } else {
                REQUIRE(BPF_CLASS(old_code) == BPF_ALU64 && old_code == code[index].code &&
                        code[index].imm == result.new_val);
                ++immediates;
            }
            ++count;
        }
    }
    REQUIRE(signed_case ? poisons == 1 && count == 1 : loads == 2 && stores == 2 && immediates == 1 && count == 5);
    FILE *out = fopen(argv[3], "wb");
    REQUIRE(out && fwrite(code, 1, data->d_size, out) == data->d_size && fclose(out) == 0);
    free(code); elf_end(elf); REQUIRE(close(fd) == 0);
    btf_ext__free(ext); btf__free(local); btf__free(target);
    return 0;
}
