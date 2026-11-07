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

enum class NativeDataSymbolOffsetKind {
    NativeOffset,
    SourceOffset,
    Absent,
    SectionMismatch,
    SizeMismatch,
    OutOfBounds,
};

struct NativeDataSymbolOffsetResolution {
    NativeDataSymbolOffsetKind kind;
    uint64_t offset;
};

inline NativeDataSymbolOffsetResolution resolve_source_data_symbol_offset(
    const NativeDataSymbolLayout &layout,
    uint64_t native_size,
    uint64_t native_offset,
    uint64_t map_value_size,
    bool local_readonly = false)
{
    if (!layout.is_datasec) {
        if (local_readonly) return {NativeDataSymbolOffsetKind::Absent, 0};
        return {NativeDataSymbolOffsetKind::NativeOffset, native_offset};
    }
    if (!layout.section_matches) {
        return {NativeDataSymbolOffsetKind::SectionMismatch, 0};
    }
    if (!layout.found) {
        return {NativeDataSymbolOffsetKind::Absent, 0};
    }
    if (layout.size != native_size) {
        return {NativeDataSymbolOffsetKind::SizeMismatch, 0};
    }
    if (layout.offset > map_value_size ||
        layout.size > map_value_size - layout.offset) {
        return {NativeDataSymbolOffsetKind::OutOfBounds, 0};
    }
    return {NativeDataSymbolOffsetKind::SourceOffset, layout.offset};
}

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

/* DATASEC layout is part of the simulator's specialization input. Equal map
 * sizes do not make differently named, placed or sized globals interchangeable.
 */
inline bool same_data_layout(const btf *proof_btf, uint32_t proof_id,
                             const btf *source_btf, uint32_t source_id)
{
    if (!proof_btf || !source_btf) return false;
    const btf_type *proof = btf__type_by_id(proof_btf, proof_id);
    const btf_type *source = btf__type_by_id(source_btf, source_id);
    if (!proof || !source || btf_kind(proof) != BTF_KIND_DATASEC ||
        btf_kind(source) != BTF_KIND_DATASEC || proof->size != source->size ||
        btf_vlen(proof) != btf_vlen(source))
        return false;
    const char *section = btf__name_by_offset(proof_btf, proof->name_off);
    const char *source_section = btf__name_by_offset(source_btf, source->name_off);
    if (!section || !*section || !source_section || std::string_view(section) != source_section)
        return false;
    const btf_var_secinfo *vars = btf_var_secinfos(proof);
    const btf_var_secinfo *source_vars = btf_var_secinfos(source);
    for (uint16_t index = 0; index < btf_vlen(proof); ++index) {
        const btf_type *var = btf__type_by_id(proof_btf, vars[index].type);
        const btf_type *source_var = btf__type_by_id(source_btf, source_vars[index].type);
        if (!var || btf_kind(var) != BTF_KIND_VAR || !source_var ||
            btf_kind(source_var) != BTF_KIND_VAR)
            return false;
        const char *name = btf__name_by_offset(proof_btf, var->name_off);
        const char *source_name = btf__name_by_offset(source_btf, source_var->name_off);
        if (!name || !*name || vars[index].offset > proof->size ||
            vars[index].size > proof->size - vars[index].offset ||
            !source_name || std::string_view(name) != source_name ||
            vars[index].offset != source_vars[index].offset ||
            vars[index].size != source_vars[index].size)
            return false;
    }
    return true;
}
