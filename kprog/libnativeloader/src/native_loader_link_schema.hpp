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
    }
    fail("native_link: unknown lookup kind");
}

NativeLinkArgs::LookupSite make_link_lookup_site(
    const CompanionLoad::LookupSite &site, const MapMeta *meta = nullptr)
{
    return NativeLinkArgs::LookupSite{
        meta && meta->type == BPF_MAP_TYPE_LPM_TRIE && meta->key_size == 16
            ? "lpm12" : lookup_kind_name(site.kind),
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
        add_name_addr(out.helpers, kX86BpfMapMaxEntriesOffsetKey,
                      K_BPF_MAP_MAX_ENTRIES_OFFSET);
        add_name_addr(out.helpers, kX86BpfArrayPtrsOffsetKey,
                      K_BPF_ARRAY_PTRS_OFFSET);
        add_name_addr(out.helpers, kX86BpfProgBpfFuncOffsetKey,
                      K_BPF_PROG_BPF_FUNC_OFFSET);
        add_name_addr(out.helpers, kX86TailCallOffsetKey, 12);
        // A program whose calls stay inside its own blob needs no kernel
        // address at all; scanning kallsyms for them only costs startup.
        if (companion.needs_kernel_symbols) {
            this_cpu_off_addr = kallsyms_lookup("this_cpu_off");
            if (this_cpu_off_addr != 0) {
                add_name_addr(out.helpers, kX86ThisCpuOffHelperKey, this_cpu_off_addr);
            }
            // Kernel symbols P names directly (native-helpers.h), bound by name.
            for (const char *symbol : native_lto::kernel_symbols) {
                const uint64_t address = kallsyms_lookup(symbol);
                if (!address) fail(std::string(symbol) + " not in boot kernel kallsyms");
                add_name_addr(out.helpers, symbol, address);
            }
        }
    }
#elif defined(__aarch64__)
    {
        uint32_t cpu_offset = K_THREAD_INFO_CPU_OFFSET;
        add_name_addr(out.helpers, kArm64ThreadInfoCpuOffsetHelperKey, cpu_offset);
    }
#endif
    if (companion.context_helpers) {
        for (const auto &[name, address] : *companion.context_helpers)
            add_name_addr(out.helpers, name, address);
    } else if (companion.needs_kernel_symbols) {
        for (const auto &helper : kSupportedHelpers) {
            uint64_t addr = kallsyms_lookup(helper.symbol);
            if (addr != 0) {
                add_name_addr(out.helpers, helper.symbol, addr);
                // An upstream object names the UAPI helper, while kallsyms
                // can name its implementation differently. Keep both spellings
                // bound to this helper ID's same implementation and semantics.
                for (const auto &identity : kCanonicalHelperIdentities) {
                    if (identity.id == static_cast<uint32_t>(helper.id))
                        add_name_addr(out.helpers, identity.name, addr);
                }
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
    }
    for (const auto &[name, address] : companion.kernel_functions)
        add_name_addr(out.helpers, name, address);
    if (companion.needs_kernel_symbols) {
        // C helper LTO calls the kernel's existing nofault boundaries.
        for (const char *symbol : native_lto::kernel_symbols) {
            uint64_t addr = kallsyms_lookup(symbol);
            if (addr != 0) add_name_addr(out.helpers, symbol, addr);
        }
        for (const char *symbol : kRuntimeCallSymbols) {
            uint64_t addr = kallsyms_lookup(symbol);
            if (addr != 0) {
                add_name_addr(out.helpers, symbol, addr);
            }
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
    std::vector<std::pair<std::string, std::string>> native_map_symbols(
        companion.native_map_symbols.begin(), companion.native_map_symbols.end());
    std::sort(native_map_symbols.begin(), native_map_symbols.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });
    for (const auto &kv : native_map_symbols) {
        const MapMeta *meta = find_map_meta_by_native_symbol(companion, kv.first);
        if (!meta) {
            fail("native map symbol " + kv.first +
                 " references unknown loaded map " + kv.second);
        }
        CompanionLoad::LookupSite site =
            lookup_site_for_map_meta(*meta, array_offsets, htab_offsets, this_cpu_off_addr);
        site.map_name = kv.first;
        out.lookup_maps.push_back(NativeLinkArgs::LookupMap{
            kv.first,
            make_link_lookup_site(site, meta),
        });
        if (const auto ops = companion.map_ops.find(meta->kernel_id);
            ops != companion.map_ops.end()) {
            out.map_ops.push_back({kv.first, ops->second.update, ops->second.remove});
        }
    }
    return out;
}
