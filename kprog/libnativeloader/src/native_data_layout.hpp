#pragma once

#include <bpf/btf.h>

#include <cstdint>
#include <string_view>

struct NativeDataSymbolLayout {
    bool is_datasec;
    bool section_matches;
    bool found;
    uint32_t offset;
    uint32_t size;
};

inline NativeDataSymbolLayout find_source_data_symbol_layout(
    const btf *btf_obj,
    uint32_t value_type_id,
    std::string_view section_name,
    std::string_view symbol_name)
{
    NativeDataSymbolLayout result{};
    const btf_type *datasec = btf__type_by_id(btf_obj, value_type_id);
    if (!datasec || btf_kind(datasec) != BTF_KIND_DATASEC) {
        return result;
    }

    result.is_datasec = true;
    const char *name = btf__name_by_offset(btf_obj, datasec->name_off);
    result.section_matches = name && section_name == name;
    if (!result.section_matches) {
        return result;
    }

    const btf_var_secinfo *vars = btf_var_secinfos(datasec);
    for (uint16_t i = 0; i < btf_vlen(datasec); ++i) {
        const btf_type *var = btf__type_by_id(btf_obj, vars[i].type);
        if (!var || btf_kind(var) != BTF_KIND_VAR) {
            continue;
        }
        name = btf__name_by_offset(btf_obj, var->name_off);
        if (name && symbol_name == name) {
            result.found = true;
            result.offset = vars[i].offset;
            result.size = vars[i].size;
            return result;
        }
    }
    return result;
}
