#pragma once

#include <bpf/btf.h>
#include <cstdint>
#include <stdexcept>
#include <string>

inline uint32_t native_data_symbol_offset(const btf *types, uint32_t value_type,
                                          const std::string &section,
                                          const std::string &symbol)
{
    const auto *data = btf__type_by_id(types, value_type);
    if (!data || btf_kind(data) != BTF_KIND_DATASEC)
        throw std::runtime_error("BPF data map lacks DATASEC BTF for " + section);
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
    throw std::runtime_error("BPF DATASEC " + section + " lacks native symbol " + symbol);
}
