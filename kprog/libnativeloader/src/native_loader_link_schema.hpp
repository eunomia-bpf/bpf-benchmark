#pragma once

void add_name_addr(std::vector<NativeLinkArgs::NameAddr> &items,
                   const std::string &name,
                   uint64_t addr)
{
    for (NativeLinkArgs::NameAddr &item : items) {
        if (item.name == name) {
            item.addr = addr;
            return;
        }
    }
    items.push_back(NativeLinkArgs::NameAddr{name, addr});
}

const char *lookup_kind_name(CompanionLoad::LookupSite::Kind kind)
{
    switch (kind) {
    case CompanionLoad::LookupSite::Kind::Call:
        return "call";
    case CompanionLoad::LookupSite::Kind::Hash:
        return "hash";
    case CompanionLoad::LookupSite::Kind::LruHash:
        return "lru_hash";
    case CompanionLoad::LookupSite::Kind::PerCpuHash:
        return "percpu_hash";
    case CompanionLoad::LookupSite::Kind::HashOfMaps:
        return "hash_of_maps";
    case CompanionLoad::LookupSite::Kind::Array:
        return "array";
    case CompanionLoad::LookupSite::Kind::PerCpuArray:
        return "percpu_array";
    case CompanionLoad::LookupSite::Kind::ArrayOfMaps:
        return "array_of_maps";
    }
    fail("native_link: unknown lookup kind");
}

NativeLinkArgs::LookupSite make_link_lookup_site(
    const CompanionLoad::LookupSite &site)
{
    return NativeLinkArgs::LookupSite{
        lookup_kind_name(site.kind),
        site.target_addr,
        site.key_offset,
        site.max_entries,
        site.elem_size,
        site.index_mask,
        site.value_offset,
        site.percpu_base_addr,
        site.map_name,
    };
}

const char *update_kind_name(CompanionLoad::UpdateSite::Kind kind)
{
    switch (kind) {
    case CompanionLoad::UpdateSite::Kind::Call:
        return "call";
    case CompanionLoad::UpdateSite::Kind::Array:
        return "array";
    case CompanionLoad::UpdateSite::Kind::PerCpuArray:
        return "percpu_array";
    }
    fail("native_link: unknown update kind");
}

NativeLinkArgs::UpdateSite make_link_update_site(
    const CompanionLoad::UpdateSite &site)
{
    return NativeLinkArgs::UpdateSite{
        update_kind_name(site.kind),
        site.target_addr,
        site.max_entries,
        site.elem_size,
        site.value_size,
        site.value_offset,
        site.percpu_base_addr,
    };
}

NativeLinkArgs build_native_link_args(
    const std::filesystem::path &native_link_path,
    const std::unordered_map<std::string, uint64_t> &map_addrs,
    const CompanionLoad &companion)
{
    NativeLinkArgs out{};
    out.linker = native_link_binary(native_link_path);
    BpfArrayOffsets array_offsets{
        K_BPF_ARRAY_VALUE_OFFSET,
        K_BPF_ARRAY_PPTRS_OFFSET,
    };
    BpfHtabOffsets htab_offsets{
        K_HTAB_ELEM_KEY_OFFSET,
        K_HTAB_ELEM_LRU_REF_OFFSET,
    };
    uint64_t this_cpu_off_addr = 0;
#if defined(__x86_64__)
    {
        uint64_t cpu_number_addr = kallsyms_lookup("cpu_number");
        this_cpu_off_addr = kallsyms_lookup("this_cpu_off");
        if (cpu_number_addr != 0 && this_cpu_off_addr != 0) {
            add_name_addr(out.helpers, kX86CpuNumberHelperKey, cpu_number_addr);
            add_name_addr(out.helpers, kX86ThisCpuOffHelperKey, this_cpu_off_addr);
        }
        add_name_addr(out.helpers, kX86BpfMapMaxEntriesOffsetKey,
                      K_BPF_MAP_MAX_ENTRIES_OFFSET);
        add_name_addr(out.helpers, kX86BpfArrayPtrsOffsetKey,
                      K_BPF_ARRAY_PTRS_OFFSET);
        add_name_addr(out.helpers, kX86BpfProgBpfFuncOffsetKey,
                      K_BPF_PROG_BPF_FUNC_OFFSET);
        add_name_addr(out.helpers, kX86TailCallOffsetKey, 12);
    }
#elif defined(__aarch64__)
    {
        uint32_t cpu_offset = K_THREAD_INFO_CPU_OFFSET;
        add_name_addr(out.helpers, kArm64ThreadInfoCpuOffsetHelperKey, cpu_offset);
        add_name_addr(out.helpers, "__native_arm64_bpf_map_max_entries_offset",
                      K_BPF_MAP_MAX_ENTRIES_OFFSET);
        add_name_addr(out.helpers, "__native_arm64_bpf_array_ptrs_offset", K_BPF_ARRAY_PTRS_OFFSET);
        add_name_addr(out.helpers, "__native_arm64_bpf_prog_bpf_func_offset",
                      K_BPF_PROG_BPF_FUNC_OFFSET);
        // PROLOGUE_OFFSET of arch/arm64/net/bpf_jit_comp.c on the one kernel (BTI off, PAC on):
        // (0 + 2 + 1 + 4) instructions.
        add_name_addr(out.helpers, "__native_arm64_tail_call_offset", 28);
    }
#endif

    for (const auto &helper : kSupportedHelpers) {
        uint64_t addr = kallsyms_lookup(helper.symbol);
        if (addr != 0) {
            add_name_addr(out.helpers, helper.symbol, addr);
        }
    }
    static constexpr int kContextualHelperIds[] = {
        BPF_FUNC_get_prandom_u32,
        BPF_FUNC_fib_lookup,
        BPF_FUNC_redirect_map,
        BPF_FUNC_skc_lookup_tcp,
        BPF_FUNC_sk_lookup_udp,
    };
    for (int helper_id : kContextualHelperIds) {
        std::optional<std::pair<std::string, uint64_t>> alias =
            contextual_helper_alias_if_available(helper_id, companion.prog_type);
        if (!alias) {
            continue;
        }
        add_name_addr(out.helpers, alias->first, alias->second);
    }
    for (const auto &[name, address] : companion.context_helpers) {
        add_name_addr(out.helpers, name, address);
    }
    for (const char *symbol : kRuntimeCallSymbols) {
        uint64_t addr = kallsyms_lookup(symbol);
        if (addr != 0) {
            add_name_addr(out.helpers, symbol, addr);
        }
    }

    std::vector<std::pair<std::string, uint64_t>> maps(
        map_addrs.begin(), map_addrs.end());
    std::sort(maps.begin(), maps.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });
    for (const auto &kv : maps) {
        add_name_addr(out.maps, kv.first, 0);
    }

    for (size_t i = 0; i < companion.lookup_sites.size(); i++) {
        out.lookup_sites.push_back(make_link_lookup_site(companion.lookup_sites[i]));
    }
    // Inner templates the shim recorded at BPF_MAP_CREATE in this process, by outer map id.
    std::unordered_map<uint32_t, std::pair<NativeMapShape, uint32_t>> inner_templates;
    {
        std::ifstream in("/tmp/native_kernel_inner_maps." + std::to_string(getpid()) + ".tsv");
        uint32_t id, type, key, value, max, flags;
        while (in >> id >> type >> key >> value >> max >> flags) {
            NativeMapShape shape;
            shape.type = static_cast<int>(type);
            shape.key_size = key;
            shape.value_size = value;
            shape.max_entries = max;
            inner_templates[id] = {shape, flags};
        }
    }
    std::vector<std::pair<std::string, std::string>> native_map_symbols(
        companion.native_map_symbols.begin(), companion.native_map_symbols.end());
    std::sort(native_map_symbols.begin(), native_map_symbols.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });
    for (const auto &kv : native_map_symbols) {
        const MapMeta *meta = find_map_meta_by_loaded_name(companion, kv.second);
        if (!meta) {
            fail("native map symbol " + kv.first +
                 " references unknown loaded map " + kv.second);
        }
        CompanionLoad::LookupSite site =
            lookup_site_for_map_meta(*meta, array_offsets, htab_offsets, this_cpu_off_addr);
        site.map_name = kv.first;
        // ops->map_update_elem / ops->map_delete_elem of the map type, which the verifier's
        // fixup calls directly; native-link binds `<helper>@<map>` the same way.
        static const std::unordered_map<int, std::pair<const char *, const char *>> kMapUpdateDelete = {
            {BPF_MAP_TYPE_HASH, {"htab_map_update_elem", "htab_map_delete_elem"}},
            {BPF_MAP_TYPE_LRU_HASH, {"htab_lru_map_update_elem", "htab_lru_map_delete_elem"}},
            {BPF_MAP_TYPE_PERCPU_HASH, {"htab_percpu_map_update_elem", "htab_map_delete_elem"}},
            {BPF_MAP_TYPE_LRU_PERCPU_HASH, {"htab_lru_percpu_map_update_elem", "htab_lru_map_delete_elem"}},
            {BPF_MAP_TYPE_ARRAY, {"array_map_update_elem", "array_map_delete_elem"}},
            {BPF_MAP_TYPE_PERCPU_ARRAY, {"array_map_update_elem", "array_map_delete_elem"}},
            {BPF_MAP_TYPE_LPM_TRIE, {"trie_update_elem", "trie_delete_elem"}},
        };
        if (auto ops = kMapUpdateDelete.find(meta->type); ops != kMapUpdateDelete.end()) {
            uint64_t update = kallsyms_lookup(ops->second.first);
            uint64_t del = kallsyms_lookup(ops->second.second);
            if (update != 0 && del != 0) {
                add_name_addr(out.helpers, "bpf_map_update_elem@" + kv.first, update);
                add_name_addr(out.helpers, "bpf_map_delete_elem@" + kv.first, del);
            }
        }
        out.lookup_maps.push_back(NativeLinkArgs::LookupMap{
            kv.first,
            make_link_lookup_site(site),
        });
        // A lookup on the value of a map-in-map lookup reaches an inner map: the verifier gives
        // it the form of the outer map's inner template; native-link names it `<map>#inner`.
        if (auto inner = inner_templates.find(meta->kernel_id); inner != inner_templates.end()) {
            const auto &[shape, flags] = inner->second;
            const bool array = shape.type == BPF_MAP_TYPE_ARRAY ||
                               shape.type == BPF_MAP_TYPE_PERCPU_ARRAY;
            CompanionLoad::LookupSite inner_site{
                CompanionLoad::LookupSite::Kind::Call,
                helper_kernel_addr(BPF_FUNC_map_lookup_elem), 0, 0, 0, 0, 0, 0,
            };
            // BPF_F_INNER_MAP lets inner arrays differ in size, so they keep the helper.
            if (!(array && (flags & BPF_F_INNER_MAP)) &&
                configure_lookup_site_for_shape(inner_site, shape, array_offsets, htab_offsets,
                                                this_cpu_off_addr)) {
                const std::string inner_name = kv.first + "#inner";
                inner_site.map_name = inner_name;
                if (auto ops = kMapUpdateDelete.find(shape.type); ops != kMapUpdateDelete.end()) {
                    uint64_t update = kallsyms_lookup(ops->second.first);
                    uint64_t del = kallsyms_lookup(ops->second.second);
                    if (update != 0 && del != 0) {
                        add_name_addr(out.helpers, "bpf_map_update_elem@" + inner_name, update);
                        add_name_addr(out.helpers, "bpf_map_delete_elem@" + inner_name, del);
                    }
                }
                out.lookup_maps.push_back(NativeLinkArgs::LookupMap{
                    inner_name,
                    make_link_lookup_site(inner_site),
                });
            }
        }
    }
    for (const auto &[name, hex] : companion.const_values) {
        out.const_values.push_back(NativeLinkArgs::ConstValue{name, hex});
    }
    for (size_t i = 0; i < companion.update_sites.size(); i++) {
        out.update_sites.push_back(make_link_update_site(companion.update_sites[i]));
    }
    return out;
}
