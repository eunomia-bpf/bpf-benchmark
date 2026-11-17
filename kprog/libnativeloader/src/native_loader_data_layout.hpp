#pragma once

#include <bpf/btf.h>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>

// A data symbol's offset inside the loaded app's map value, or nothing when
// the symbol has no place there. Private readonly constants (STB_LOCAL in
// .rodata*) are the native linker's own immutable storage, and a native
// object built from a newer source can name globals the app's DATASEC does
// not declare; both belong to the linker, not to the app's map.
inline std::optional<uint64_t> native_data_symbol_offset(
    const btf *types, uint32_t value_type, const std::string &section,
    const std::string &symbol, uint64_t native_offset, bool local_readonly)
{
    const auto *data = btf__type_by_id(types, value_type);
    if (!data || btf_kind(data) != BTF_KIND_DATASEC) {
        if (local_readonly) return std::nullopt;
        return native_offset;
    }
    const char *section_name = btf__name_by_offset(types, data->name_off);
    if (!section_name || section != section_name)
        throw std::runtime_error("BPF data map section differs from native section " + section);
    const auto *variables = btf_var_secinfos(data);
    for (uint32_t i = 0; i < btf_vlen(data); ++i) {
        const auto *variable = btf__type_by_id(types, variables[i].type);
        if (!variable || btf_kind(variable) != BTF_KIND_VAR)
            throw std::runtime_error("BPF DATASEC contains a non-VAR type");
        const char *name = btf__name_by_offset(types, variable->name_off);
        if (name && symbol == name) return variables[i].offset;
    }
    return std::nullopt;
}