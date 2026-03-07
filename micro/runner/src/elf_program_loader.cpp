#include "micro_exec.hpp"

#include <bpf/libbpf.h>
#include <elf.h>
#include <fcntl.h>
#include <gelf.h>
#include <linux/bpf.h>
#include <unistd.h>

#include <cstring>
#include <memory>
#include <optional>
#include <unordered_map>
#include <unordered_set>

namespace {

constexpr uint8_t k_bpf_ld_imm64 = BPF_LD | BPF_DW | BPF_IMM;

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

struct section_slice {
    size_t section_index = 0;
    size_t input_offset_bytes = 0;
    size_t size_bytes = 0;
    size_t output_insn_offset = 0;
};

struct function_symbol {
    std::string name;
    size_t section_index = 0;
    size_t offset_bytes = 0;
    size_t size_bytes = 0;
};

struct relocation_record {
    size_t offset = 0;
    size_t sym_index = 0;
    unsigned type = 0;
};

struct symbol_table_view {
    Elf_Data *data = nullptr;
    GElf_Shdr shdr {};
};

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

GElf_Shdr get_section_header_or_fail(Elf_Scn *section, const char *context)
{
    GElf_Shdr shdr {};
    if (gelf_getshdr(section, &shdr) == nullptr) {
        fail(std::string("gelf_getshdr failed while ") + context);
    }
    return shdr;
}

symbol_table_view get_symbol_table_or_fail(Elf *elf)
{
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf, section)) != nullptr) {
        const auto shdr = get_section_header_or_fail(section, "walking sections for symbol table");
        if (shdr.sh_type != SHT_SYMTAB) {
            continue;
        }

        Elf_Data *data = elf_getdata(section, nullptr);
        if (data == nullptr) {
            fail("unable to read ELF symbol table data");
        }
        return {.data = data, .shdr = shdr};
    }

    fail("unable to locate ELF symbol table");
}

std::vector<function_symbol> collect_function_symbols(Elf *elf)
{
    const auto symtab = get_symbol_table_or_fail(elf);
    const size_t entry_count = symtab.shdr.sh_size / symtab.shdr.sh_entsize;

    std::vector<function_symbol> functions;
    functions.reserve(entry_count);
    for (size_t index = 0; index < entry_count; ++index) {
        GElf_Sym sym {};
        if (gelf_getsym(symtab.data, static_cast<int>(index), &sym) == nullptr) {
            fail("gelf_getsym failed while collecting function symbols");
        }
        if (ELF64_ST_TYPE(sym.st_info) != STT_FUNC || sym.st_shndx == SHN_UNDEF || sym.st_size == 0) {
            continue;
        }

        const char *name = elf_strptr(elf, symtab.shdr.sh_link, sym.st_name);
        if (name == nullptr) {
            continue;
        }

        functions.push_back(
            {
                .name = name,
                .section_index = sym.st_shndx,
                .offset_bytes = static_cast<size_t>(sym.st_value),
                .size_bytes = static_cast<size_t>(sym.st_size),
            });
    }
    return functions;
}

const function_symbol *find_function_symbol(
    const std::vector<function_symbol> &functions,
    size_t section_index,
    const std::string &name)
{
    for (const auto &function : functions) {
        if (function.section_index == section_index && function.name == name) {
            return &function;
        }
    }
    return nullptr;
}

Elf_Scn *get_section_or_fail(Elf *elf, size_t section_index, const char *context)
{
    Elf_Scn *section = elf_getscn(elf, section_index);
    if (section == nullptr) {
        fail(std::string("unable to resolve ELF section while ") + context);
    }
    return section;
}

bool is_executable_section(Elf *elf, size_t section_index)
{
    if (section_index == SHN_UNDEF || section_index >= SHN_LORESERVE) {
        return false;
    }

    Elf_Scn *section = elf_getscn(elf, section_index);
    if (section == nullptr) {
        return false;
    }
    const auto shdr = get_section_header_or_fail(section, "checking section flags");
    return (shdr.sh_flags & SHF_EXECINSTR) != 0;
}

std::optional<relocation_record> read_relocation(Elf_Data *rel_data, const GElf_Shdr &shdr, size_t index)
{
    if (shdr.sh_type == SHT_REL) {
        GElf_Rel rel {};
        if (gelf_getrel(rel_data, static_cast<int>(index), &rel) == nullptr) {
            fail("gelf_getrel failed");
        }
        return relocation_record {
            .offset = static_cast<size_t>(rel.r_offset),
            .sym_index = static_cast<size_t>(GELF_R_SYM(rel.r_info)),
            .type = static_cast<unsigned>(GELF_R_TYPE(rel.r_info)),
        };
    }

    if (shdr.sh_type == SHT_RELA) {
        GElf_Rela rela {};
        if (gelf_getrela(rel_data, static_cast<int>(index), &rela) == nullptr) {
            fail("gelf_getrela failed");
        }
        return relocation_record {
            .offset = static_cast<size_t>(rela.r_offset),
            .sym_index = static_cast<size_t>(GELF_R_SYM(rela.r_info)),
            .type = static_cast<unsigned>(GELF_R_TYPE(rela.r_info)),
        };
    }

    return std::nullopt;
}

std::optional<size_t> translate_output_insn_index(
    const std::vector<section_slice> &slices,
    size_t section_index,
    size_t source_offset_bytes)
{
    for (const auto &slice : slices) {
        if (slice.section_index != section_index) {
            continue;
        }
        if (source_offset_bytes < slice.input_offset_bytes ||
            source_offset_bytes >= slice.input_offset_bytes + slice.size_bytes) {
            continue;
        }

        const size_t local_offset_bytes = source_offset_bytes - slice.input_offset_bytes;
        if (local_offset_bytes % sizeof(bpf_insn) != 0) {
            fail("relocation points to a non-instruction-aligned offset");
        }
        return slice.output_insn_offset + local_offset_bytes / sizeof(bpf_insn);
    }
    return std::nullopt;
}

uint64_t read_ldimm64_immediate(const bpf_insn *insns, size_t insn_index, size_t insn_count)
{
    if (insn_index + 1 >= insn_count) {
        fail("LDDW relocation refers to a truncated instruction pair");
    }

    return static_cast<uint64_t>(static_cast<uint32_t>(insns[insn_index].imm)) |
           (static_cast<uint64_t>(static_cast<uint32_t>(insns[insn_index + 1].imm)) << 32);
}

void write_ldimm64_immediate(bpf_insn *insns, size_t insn_index, size_t insn_count, uint64_t value)
{
    if (insn_index + 1 >= insn_count) {
        fail("LDDW relocation refers to a truncated instruction pair");
    }

    insns[insn_index].imm = static_cast<int32_t>(value & 0xffffffffu);
    insns[insn_index + 1].imm = static_cast<int32_t>(value >> 32);
}

bpf_program *find_program(bpf_object *object, const std::optional<std::string> &program_name)
{
    bpf_program *program = nullptr;
    if (!program_name.has_value()) {
        program = bpf_object__next_program(object, nullptr);
        if (program == nullptr) {
            fail("no program found in object");
        }
        return program;
    }

    while ((program = bpf_object__next_program(object, program)) != nullptr) {
        const char *current_name = bpf_program__name(program);
        if (current_name != nullptr && *program_name == current_name) {
            return program;
        }
    }

    fail("unable to find program named '" + *program_name + "'");
}

void append_section_slice(
    Elf *elf,
    size_t section_index,
    std::vector<section_slice> &slices,
    std::vector<uint8_t> &code)
{
    for (const auto &slice : slices) {
        if (slice.section_index == section_index && slice.input_offset_bytes == 0) {
            return;
        }
    }

    Elf_Scn *section = get_section_or_fail(elf, section_index, "appending referenced code section");
    const auto shdr = get_section_header_or_fail(section, "appending referenced code section");
    Elf_Data *data = elf_getdata(section, nullptr);
    if (data == nullptr || data->d_buf == nullptr || data->d_size == 0) {
        fail("unable to read referenced code section contents");
    }
    if ((shdr.sh_flags & SHF_EXECINSTR) == 0) {
        fail("attempted to append a non-executable section as code");
    }
    if (data->d_size % sizeof(bpf_insn) != 0) {
        fail("referenced code section does not contain aligned BPF instructions");
    }

    const size_t output_insn_offset = code.size() / sizeof(bpf_insn);
    const size_t old_size = code.size();
    code.resize(old_size + data->d_size);
    std::memcpy(code.data() + old_size, data->d_buf, data->d_size);
    slices.push_back(
        {
            .section_index = section_index,
            .input_offset_bytes = 0,
            .size_bytes = data->d_size,
            .output_insn_offset = output_insn_offset,
        });
}

void append_referenced_code_sections(
    Elf *elf,
    const symbol_table_view &symtab,
    size_t source_section_index,
    std::vector<section_slice> &slices,
    std::vector<uint8_t> &code)
{
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf, section)) != nullptr) {
        const auto shdr = get_section_header_or_fail(section, "walking relocation sections");
        if (shdr.sh_info != source_section_index) {
            continue;
        }
        if (shdr.sh_type != SHT_REL && shdr.sh_type != SHT_RELA) {
            continue;
        }

        Elf_Data *rel_data = elf_getdata(section, nullptr);
        if (rel_data == nullptr) {
            fail("unable to read ELF relocation data");
        }

        const size_t entry_count = shdr.sh_size / shdr.sh_entsize;
        for (size_t index = 0; index < entry_count; ++index) {
            const auto relocation = read_relocation(rel_data, shdr, index);
            if (!relocation.has_value()) {
                continue;
            }

            GElf_Sym sym {};
            if (gelf_getsym(symtab.data, static_cast<int>(relocation->sym_index), &sym) == nullptr) {
                fail("gelf_getsym failed while walking code references");
            }
            if (!is_executable_section(elf, sym.st_shndx) || sym.st_shndx == source_section_index) {
                continue;
            }

            const unsigned symbol_type = ELF64_ST_TYPE(sym.st_info);
            if (symbol_type != STT_SECTION && symbol_type != STT_FUNC) {
                continue;
            }

            append_section_slice(elf, sym.st_shndx, slices, code);
        }
    }
}

std::unordered_map<size_t, std::unordered_set<size_t>> collect_function_entries_by_section(
    const std::vector<function_symbol> &functions,
    const std::vector<section_slice> &slices)
{
    std::unordered_map<size_t, std::unordered_set<size_t>> entries;
    for (const auto &function : functions) {
        for (const auto &slice : slices) {
            if (slice.section_index != function.section_index) {
                continue;
            }
            if (function.offset_bytes < slice.input_offset_bytes ||
                function.offset_bytes >= slice.input_offset_bytes + slice.size_bytes) {
                continue;
            }

            entries[function.section_index].insert(function.offset_bytes / sizeof(bpf_insn));
            break;
        }
    }
    return entries;
}

void mark_same_section_local_calls(
    const std::vector<section_slice> &slices,
    const std::unordered_map<size_t, std::unordered_set<size_t>> &function_entries_by_section,
    std::vector<uint8_t> &code)
{
    auto *insns = reinterpret_cast<bpf_insn *>(code.data());
    const size_t insn_count = code.size() / sizeof(bpf_insn);

    for (const auto &slice : slices) {
        const auto function_iter = function_entries_by_section.find(slice.section_index);
        if (function_iter == function_entries_by_section.end() || function_iter->second.size() <= 1) {
            continue;
        }

        const size_t section_start_insn = slice.input_offset_bytes / sizeof(bpf_insn);
        const size_t section_end_insn = section_start_insn + slice.size_bytes / sizeof(bpf_insn);
        const size_t slice_insn_count = slice.size_bytes / sizeof(bpf_insn);
        for (size_t local_index = 0; local_index < slice_insn_count; ++local_index) {
            const size_t insn_index = slice.output_insn_offset + local_index;
            if (insn_index >= insn_count) {
                fail("section slice extends beyond copied code");
            }

            auto &insn = insns[insn_index];
            if (insn.code != (BPF_JMP | BPF_CALL) || insn.src_reg == BPF_PSEUDO_CALL) {
                continue;
            }

            const int64_t target_section_insn = static_cast<int64_t>(section_start_insn + local_index) + insn.imm + 1;
            if (target_section_insn < static_cast<int64_t>(section_start_insn) ||
                target_section_insn >= static_cast<int64_t>(section_end_insn)) {
                continue;
            }
            if (!function_iter->second.contains(static_cast<size_t>(target_section_insn))) {
                continue;
            }

            insn.src_reg = BPF_PSEUDO_CALL;
        }
    }
}

void patch_program_relocations(
    Elf *elf,
    const std::vector<section_slice> &slices,
    const std::unordered_map<std::string, uint32_t> &map_ids,
    const std::unordered_map<size_t, std::unordered_set<size_t>> &function_entries_by_section,
    std::vector<uint8_t> &code)
{
    auto *insns = reinterpret_cast<bpf_insn *>(code.data());
    const size_t insn_count = code.size() / sizeof(bpf_insn);
    const auto symtab = get_symbol_table_or_fail(elf);

    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf, section)) != nullptr) {
        const auto shdr = get_section_header_or_fail(section, "walking relocation sections");
        if (shdr.sh_type != SHT_REL && shdr.sh_type != SHT_RELA) {
            continue;
        }

        Elf_Data *rel_data = elf_getdata(section, nullptr);
        if (rel_data == nullptr) {
            fail("unable to read ELF relocation data");
        }

        const size_t entry_count = shdr.sh_size / shdr.sh_entsize;
        for (size_t index = 0; index < entry_count; ++index) {
            const auto relocation = read_relocation(rel_data, shdr, index);
            if (!relocation.has_value()) {
                continue;
            }

            const auto insn_index = translate_output_insn_index(slices, shdr.sh_info, relocation->offset);
            if (!insn_index.has_value()) {
                continue;
            }
            if (*insn_index >= insn_count) {
                fail("translated relocation points beyond copied code");
            }

            GElf_Sym sym {};
            if (gelf_getsym(symtab.data, static_cast<int>(relocation->sym_index), &sym) == nullptr) {
                fail("gelf_getsym failed");
            }
            const char *symbol_name = elf_strptr(elf, symtab.shdr.sh_link, sym.st_name);

            if (symbol_name != nullptr) {
                const auto map_iter = map_ids.find(symbol_name);
                if (map_iter != map_ids.end()) {
                    insns[*insn_index].src_reg = BPF_PSEUDO_MAP_FD;
                    insns[*insn_index].imm = static_cast<int32_t>(map_iter->second);
                    if (*insn_index + 1 < insn_count) {
                        insns[*insn_index + 1].imm = 0;
                    }
                    continue;
                }
            }

            const bool executable_target = is_executable_section(elf, sym.st_shndx);
            if (relocation->type == R_BPF_64_32 &&
                insns[*insn_index].code == (BPF_JMP | BPF_CALL) &&
                executable_target) {
                const int64_t target_offset_bytes =
                    static_cast<int64_t>(sym.st_value) +
                    static_cast<int64_t>(insns[*insn_index].imm + 1) * static_cast<int64_t>(sizeof(bpf_insn));
                if (target_offset_bytes < 0) {
                    fail("local call relocation resolved to a negative target");
                }

                const auto target_index = translate_output_insn_index(
                    slices,
                    sym.st_shndx,
                    static_cast<size_t>(target_offset_bytes));
                if (!target_index.has_value()) {
                    fail("unable to resolve local call target into copied code");
                }

                insns[*insn_index].src_reg = BPF_PSEUDO_CALL;
                insns[*insn_index].imm = static_cast<int32_t>(*target_index) - static_cast<int32_t>(*insn_index + 1);
                continue;
            }

            if (relocation->type == R_BPF_64_64 &&
                executable_target &&
                insns[*insn_index].code == k_bpf_ld_imm64) {
                const uint64_t raw_target_offset = read_ldimm64_immediate(insns, *insn_index, insn_count);
                const uint64_t target_offset_bytes = static_cast<uint64_t>(sym.st_value) + raw_target_offset;
                const auto target_index = translate_output_insn_index(slices, sym.st_shndx, target_offset_bytes);
                if (!target_index.has_value()) {
                    fail("unable to resolve subprogram address relocation into copied code");
                }

                write_ldimm64_immediate(
                    insns,
                    *insn_index,
                    insn_count,
                    static_cast<uint64_t>(*target_index * sizeof(bpf_insn)));
                insns[*insn_index].src_reg = 0;
            }
        }
    }

    mark_same_section_local_calls(slices, function_entries_by_section, code);
}

} // namespace

std::vector<program_descriptor> list_programs(const std::filesystem::path &path)
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

    std::vector<program_descriptor> programs;
    bpf_program *program = nullptr;
    while ((program = bpf_object__next_program(object.get(), program)) != nullptr) {
        const char *program_name = bpf_program__name(program);
        const char *section_name = bpf_program__section_name(program);
        programs.push_back(
            {
                .name = program_name == nullptr ? "" : program_name,
                .section_name = section_name == nullptr ? "" : section_name,
                .insn_count = bpf_program__insn_cnt(program),
            });
    }

    if (programs.empty()) {
        fail("no program found in object: " + path.string());
    }
    return programs;
}

program_image load_program_image(const std::filesystem::path &path, const std::optional<std::string> &program_name)
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

    bpf_program *program = find_program(object.get(), program_name);
    const char *selected_program_name = bpf_program__name(program);
    if (selected_program_name == nullptr) {
        fail("unable to resolve selected program name");
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
        spec.type = bpf_map__type(map);
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

    const auto function_symbols = collect_function_symbols(elf);
    const function_symbol *selected_symbol =
        find_function_symbol(function_symbols, target_section_index, selected_program_name);
    if (selected_symbol == nullptr) {
        elf_end(elf);
        fail("unable to find selected program symbol in ELF");
    }

    std::vector<section_slice> code_slices;
    code_slices.push_back(
        {
            .section_index = target_section_index,
            .input_offset_bytes = selected_symbol->offset_bytes,
            .size_bytes = image.code.size(),
            .output_insn_offset = 0,
        });

    const auto symtab = get_symbol_table_or_fail(elf);
    for (size_t index = 0; index < code_slices.size(); ++index) {
        append_referenced_code_sections(elf, symtab, code_slices[index].section_index, code_slices, image.code);
    }

    const auto function_entries_by_section = collect_function_entries_by_section(function_symbols, code_slices);
    patch_program_relocations(elf, code_slices, map_ids, function_entries_by_section, image.code);
    elf_end(elf);
    return image;
}
