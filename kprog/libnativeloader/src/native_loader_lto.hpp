#pragma once

#include <bpf/btf.h>
#include <cstdint>
#include <cstring>
#include <ostream>
#include <stdexcept>
#include <string>

// The normal linker consumes these boot-kernel facts as part of its link plan.
// They describe layout and symbol identity, never application source changes.
namespace native_lto {

inline constexpr const char *kernel_symbols[] = {
    "bpf_probe_read_user", "bpf_probe_read_kernel", "cpu_tlbstate",
    "const_current_task", "USER_PTR_MAX", "boot_cpu_data",
    "ktime_get_mono_fast_ns",
};

inline const btf_type *type(const btf *types, uint32_t id)
{
    const auto *result = btf__type_by_id(types, id);
    if (!result) throw std::runtime_error("LTO BTF: missing type " + std::to_string(id));
    return result;
}

inline const btf_type *structure(const btf *types, const char *name)
{
    int id = btf__find_by_name_kind(types, name, BTF_KIND_STRUCT);
    if (id < 0) throw std::runtime_error(std::string("LTO BTF: missing struct ") + name);
    return type(types, id);
}

struct Member {
    uint32_t offset;
    uint32_t type_id;
};

inline bool member(const btf *types, const btf_type *parent,
                   const char *name, Member &result)
{
    const auto *members = btf_members(parent);
    for (unsigned i = 0; i < btf_vlen(parent); ++i) {
        const char *current = btf__name_by_offset(types, members[i].name_off);
        if (!current) throw std::runtime_error("LTO BTF: invalid member name");
        unsigned bits = btf_member_bit_offset(parent, i);
        if (!*current) {
            int child_id = btf__resolve_type(types, members[i].type);
            if (child_id < 0) throw std::runtime_error("LTO BTF: invalid anonymous member type");
            const auto *child = type(types, child_id);
            Member nested{};
            if ((btf_is_struct(child) || btf_is_union(child)) && member(types, child, name, nested)) {
                if (bits % 8) throw std::runtime_error("LTO BTF: unaligned anonymous member");
                result = {bits / 8 + nested.offset, nested.type_id};
                return true;
            }
        }
        if (std::strcmp(current, name)) continue;
        if (bits % 8 || btf_member_bitfield_size(parent, i))
            throw std::runtime_error(std::string("LTO BTF: unsupported bitfield ") + name);
        result = {bits / 8, members[i].type};
        return true;
    }
    return false;
}

inline Member field(const btf *types, const char *parent, const char *name)
{
    Member result{};
    if (!member(types, structure(types, parent), name, result))
        throw std::runtime_error(std::string("LTO BTF: missing field ") + parent + "." + name);
    return result;
}

inline uint32_t offset(const btf *types, const char *parent, const char *name,
                        bool word = false)
{
    auto result = field(types, parent, name);
    if (word && btf__resolve_size(types, result.type_id) != 4)
        throw std::runtime_error(std::string("LTO BTF: field is not u32: ") + parent + "." + name);
    return result.offset;
}

inline uint32_t relative(const btf *types, const char *parent, const char *name,
                          uint32_t base, bool word = false)
{
    uint32_t result = offset(types, parent, name, word);
    if (result < base) throw std::runtime_error("LTO BTF: field precedes its map base");
    return result - base;
}

inline int map_type(const btf *types, const char *wanted)
{
    int id = btf__find_by_name_kind(types, "bpf_map_type", BTF_KIND_ENUM);
    if (id < 0) throw std::runtime_error("LTO BTF: missing bpf_map_type enum");
    const auto *description = type(types, id);
    const auto *values = btf_enum(description);
    for (unsigned i = 0; i < btf_vlen(description); ++i) {
        const char *name = btf__name_by_offset(types, values[i].name_off);
        if (!name) throw std::runtime_error("LTO BTF: invalid enum name");
        if (!std::strcmp(name, wanted)) return values[i].val;
    }
    throw std::runtime_error(std::string("LTO BTF: missing map type ") + wanted);
}

template <typename Resolver>
inline void write_layout(std::ostream &out, const btf *types, Resolver resolve)
{
    auto symbol = [&](const char *name) {
        uint64_t value = resolve(name);
        if (!value) throw std::runtime_error(std::string("LTO: missing kernel symbol ") + name);
        return value;
    };
    uint32_t array = offset(types, "bpf_array", "map");
    out << "{\"array\":{\"map_type\":" << offset(types, "bpf_map", "map_type", true)
        << ",\"max_entries\":" << offset(types, "bpf_map", "max_entries", true)
        << ",\"elem_size\":" << relative(types, "bpf_array", "elem_size", array, true)
        << ",\"index_mask\":" << relative(types, "bpf_array", "index_mask", array, true)
        << ",\"value\":" << relative(types, "bpf_array", "value", array)
        << ",\"array_type\":" << map_type(types, "BPF_MAP_TYPE_ARRAY") << "}";

    uint32_t lpm = offset(types, "lpm_trie", "map");
    out << ",\"lpm\":{\"map_type\":" << offset(types, "bpf_map", "map_type", true)
        << ",\"lpm_type\":" << map_type(types, "BPF_MAP_TYPE_LPM_TRIE")
        << ",\"root\":" << relative(types, "lpm_trie", "root", lpm)
        << ",\"max_prefixlen\":" << relative(types, "lpm_trie", "max_prefixlen", lpm)
        << ",\"data_size\":" << relative(types, "lpm_trie", "data_size", lpm)
        << ",\"child\":" << offset(types, "lpm_trie_node", "child")
        << ",\"child_stride\":" << btf__pointer_size(types)
        << ",\"node_prefixlen\":" << offset(types, "lpm_trie_node", "prefixlen", true)
        << ",\"node_flags\":" << offset(types, "lpm_trie_node", "flags", true)
        << ",\"node_data\":" << offset(types, "lpm_trie_node", "data")
        << ",\"key_prefixlen\":" << offset(types, "bpf_lpm_trie_key_u8", "prefixlen", true)
        << ",\"key_data\":" << offset(types, "bpf_lpm_trie_key_u8", "data") << "}";

    out << ",\"probe_read\":{\"user_helper\":" << symbol("bpf_probe_read_user")
        << ",\"kernel_helper\":" << symbol("bpf_probe_read_kernel")
        << ",\"current_task\":" << symbol("const_current_task")
        << ",\"user_ptr_max\":" << symbol("USER_PTR_MAX")
        << ",\"boot_cpu_data\":" << symbol("boot_cpu_data")
        << ",\"pagefault_disabled\":" << offset(types, "task_struct", "pagefault_disabled", true)
        << ",\"x86_capability\":" << offset(types, "cpuinfo_x86", "x86_capability")
        << ",\"x86_virt_bits\":" << offset(types, "cpuinfo_x86", "x86_virt_bits")
        << ",\"cpu_tlbstate\":" << symbol("cpu_tlbstate")
        << ",\"tlb_loaded_mm\":" << offset(types, "tlb_state", "loaded_mm")
        << ",\"task_mm\":" << offset(types, "task_struct", "mm")
        << ",\"task_flags\":" << offset(types, "task_struct", "thread_info") + offset(types, "thread_info", "flags")
        << ",\"task_personality\":" << offset(types, "task_struct", "personality", true) << "}}";
    if (!out) throw std::runtime_error("write kernel LTO layout");
}

} // namespace native_lto
