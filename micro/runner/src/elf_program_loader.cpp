#include "micro_exec.hpp"

#include <bpf/libbpf.h>
#include <elf.h>
#include <fcntl.h>
#include <gelf.h>
#include <linux/bpf.h>
#include <unistd.h>

#include <cstring>
#include <memory>
#include <unordered_map>

namespace {

struct object_deleter {
    void operator()(bpf_object *obj) const
    {
        if (obj != nullptr) {
            bpf_object__close(obj);
        }
    }
};

using bpf_object_ptr = std::unique_ptr<bpf_object, object_deleter>;

struct fd_closer {
    void operator()(int *fd) const
    {
        if (fd != nullptr && *fd >= 0) {
            close(*fd);
        }
        delete fd;
    }
};

using unique_fd = std::unique_ptr<int, fd_closer>;

unique_fd open_readonly(const std::filesystem::path &path)
{
    const int fd = open(path.c_str(), O_RDONLY);
    if (fd < 0) {
        fail("unable to open ELF file: " + path.string());
    }
    return unique_fd(new int(fd));
}

std::string libbpf_error_string(int error_code)
{
    char buffer[256];
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    return std::string(buffer);
}

void patch_program_relocations(
    Elf *elf,
    size_t target_section_index,
    const std::unordered_map<std::string, uint32_t> &map_ids,
    std::vector<uint8_t> &code)
{
    auto *insns = reinterpret_cast<bpf_insn *>(code.data());
    const size_t insn_count = code.size() / sizeof(bpf_insn);

    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf, section)) != nullptr) {
        GElf_Shdr shdr {};
        if (gelf_getshdr(section, &shdr) == nullptr) {
            fail("gelf_getshdr failed while walking relocation sections");
        }
        if (shdr.sh_info != target_section_index) {
            continue;
        }
        if (shdr.sh_type != SHT_REL && shdr.sh_type != SHT_RELA) {
            continue;
        }

        Elf_Scn *symtab_scn = elf_getscn(elf, shdr.sh_link);
        if (symtab_scn == nullptr) {
            fail("unable to resolve ELF symbol table");
        }
        GElf_Shdr symtab_shdr {};
        if (gelf_getshdr(symtab_scn, &symtab_shdr) == nullptr) {
            fail("gelf_getshdr failed for symbol table");
        }
        Elf_Data *sym_data = elf_getdata(symtab_scn, nullptr);
        Elf_Data *rel_data = elf_getdata(section, nullptr);
        if (sym_data == nullptr || rel_data == nullptr) {
            fail("unable to read ELF relocation data");
        }

        const size_t entry_count = shdr.sh_size / shdr.sh_entsize;
        for (size_t index = 0; index < entry_count; ++index) {
            size_t offset = 0;
            size_t sym_index = 0;

            if (shdr.sh_type == SHT_REL) {
                GElf_Rel rel {};
                if (gelf_getrel(rel_data, static_cast<int>(index), &rel) == nullptr) {
                    fail("gelf_getrel failed");
                }
                offset = rel.r_offset;
                sym_index = GELF_R_SYM(rel.r_info);
            } else {
                GElf_Rela rela {};
                if (gelf_getrela(rel_data, static_cast<int>(index), &rela) == nullptr) {
                    fail("gelf_getrela failed");
                }
                offset = rela.r_offset;
                sym_index = GELF_R_SYM(rela.r_info);
            }

            GElf_Sym sym {};
            if (gelf_getsym(sym_data, static_cast<int>(sym_index), &sym) == nullptr) {
                fail("gelf_getsym failed");
            }
            const char *symbol_name = elf_strptr(elf, symtab_shdr.sh_link, sym.st_name);
            if (symbol_name == nullptr) {
                continue;
            }
            const auto map_iter = map_ids.find(symbol_name);
            if (map_iter == map_ids.end()) {
                continue;
            }

            const size_t insn_index = offset / sizeof(bpf_insn);
            if (insn_index >= insn_count) {
                continue; // Skip relocations in subprogram code beyond our range
            }
            insns[insn_index].src_reg = BPF_PSEUDO_MAP_FD;
            insns[insn_index].imm = static_cast<int32_t>(map_iter->second);
            if (insn_index + 1 < insn_count) {
                insns[insn_index + 1].imm = 0;
            }
        }
    }
}

} // namespace

program_image load_program_image(const std::filesystem::path &path)
{
    if (elf_version(EV_CURRENT) == EV_NONE) {
        fail("libelf initialization failed");
    }

    bpf_object_open_opts open_opts = {};
    open_opts.sz = sizeof(open_opts);
    bpf_object *raw_object = bpf_object__open_file(path.c_str(), &open_opts);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        fail("bpf_object__open_file failed: " + libbpf_error_string(open_error));
    }
    bpf_object_ptr object(raw_object);

    bpf_program *program = bpf_object__next_program(object.get(), nullptr);
    if (program == nullptr) {
        fail("no program found in object: " + path.string());
    }

    // Use libbpf to identify the program section and extract map metadata.
    const char *section_name = bpf_program__section_name(program);
    if (section_name == nullptr) {
        fail("unable to resolve program section name");
    }

    const auto *insns = bpf_program__insns(program);
    const size_t insn_count = bpf_program__insn_cnt(program);
    if (insns == nullptr || insn_count == 0) {
        fail("program contains no instructions: " + path.string());
    }

    program_image image;
    image.code.resize(insn_count * sizeof(bpf_insn));
    std::memcpy(image.code.data(), insns, image.code.size());

    std::unordered_map<std::string, uint32_t> map_ids;
    const bpf_map *map = nullptr;
    uint32_t next_map_id = 1;
    while ((map = bpf_object__next_map(object.get(), map)) != nullptr) {
        map_spec spec;
        spec.id = next_map_id++;
        spec.name = bpf_map__name(map);
        spec.key_size = bpf_map__key_size(map);
        spec.value_size = bpf_map__value_size(map);
        spec.max_entries = bpf_map__max_entries(map);
        image.maps.push_back(spec);
        map_ids.emplace(spec.name, spec.id);
    }

    auto fd = open_readonly(path);
    Elf *elf = elf_begin(*fd, ELF_C_READ, nullptr);
    if (elf == nullptr) {
        fail("elf_begin failed for " + path.string());
    }

    size_t shstrndx = 0;
    if (elf_getshdrstrndx(elf, &shstrndx) != 0) {
        elf_end(elf);
        fail("elf_getshdrstrndx failed for " + path.string());
    }

    size_t target_section_index = 0;
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf, section)) != nullptr) {
        GElf_Shdr shdr {};
        if (gelf_getshdr(section, &shdr) == nullptr) {
            elf_end(elf);
            fail("gelf_getshdr failed while searching section");
        }
        const char *name = elf_strptr(elf, shstrndx, shdr.sh_name);
        if (name != nullptr && std::string(name) == section_name) {
            target_section_index = elf_ndxscn(section);
            break;
        }
    }

    if (target_section_index == 0) {
        elf_end(elf);
        fail("unable to find target program section in ELF");
    }

    patch_program_relocations(elf, target_section_index, map_ids, image.code);
    elf_end(elf);
    return image;
}
