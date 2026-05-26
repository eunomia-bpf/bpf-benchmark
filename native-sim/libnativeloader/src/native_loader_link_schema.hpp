#pragma once

std::string format_hex(uint64_t value)
{
    char value_buf[32];
    std::snprintf(value_buf, sizeof(value_buf), "0x%llx",
                  static_cast<unsigned long long>(value));
    return value_buf;
}

std::string format_name_hex(const std::string &name, uint64_t value)
{
    return name + "=" + format_hex(value);
}

std::string format_lookup_site_arg(size_t index,
                                   const ProgramLoadPlan::LookupSite &site)
{
    const char *kind = "call";
    switch (site.kind) {
    case ProgramLoadPlan::LookupSite::Kind::Call:
        kind = "call";
        break;
    case ProgramLoadPlan::LookupSite::Kind::Hash:
        kind = "hash";
        break;
    case ProgramLoadPlan::LookupSite::Kind::LruHash:
        kind = "lru_hash";
        break;
    case ProgramLoadPlan::LookupSite::Kind::PerCpuHash:
        kind = "percpu_hash";
        break;
    case ProgramLoadPlan::LookupSite::Kind::HashOfMaps:
        kind = "hash_of_maps";
        break;
    case ProgramLoadPlan::LookupSite::Kind::Array:
        kind = "array";
        break;
    case ProgramLoadPlan::LookupSite::Kind::PerCpuArray:
        kind = "percpu_array";
        break;
    }

    char buf[384];
    std::snprintf(buf, sizeof(buf), "%zu=%s,0x%llx,%u,%u,%u,%u,%u,0x%llx",
                  index,
                  kind,
                  static_cast<unsigned long long>(site.target_addr),
                  static_cast<unsigned>(site.key_offset),
                  static_cast<unsigned>(site.max_entries),
                  static_cast<unsigned>(site.elem_size),
                  static_cast<unsigned>(site.index_mask),
                  static_cast<unsigned>(site.value_offset),
                  static_cast<unsigned long long>(site.percpu_base_addr));
    std::string out(buf);
    if (!site.map_name.empty()) {
        out.push_back(',');
        out += site.map_name;
    }
    return out;
}

std::string format_lookup_gen_arg(size_t index,
                                  const ProgramLoadPlan::LookupSite &site)
{
    static const char hex_chars[] = "0123456789abcdef";
    std::string out = std::to_string(index) + "=";
    out.reserve(out.size() + site.gen_lookup.size() * 2);
    for (uint8_t byte : site.gen_lookup) {
        out.push_back(hex_chars[byte >> 4]);
        out.push_back(hex_chars[byte & 0xf]);
    }
    return out;
}

std::string format_lookup_map_arg(const std::string &name,
                                  const ProgramLoadPlan::LookupSite &site)
{
    const char *kind = "call";
    switch (site.kind) {
    case ProgramLoadPlan::LookupSite::Kind::Call:
        kind = "call";
        break;
    case ProgramLoadPlan::LookupSite::Kind::Hash:
        kind = "hash";
        break;
    case ProgramLoadPlan::LookupSite::Kind::LruHash:
        kind = "lru_hash";
        break;
    case ProgramLoadPlan::LookupSite::Kind::PerCpuHash:
        kind = "percpu_hash";
        break;
    case ProgramLoadPlan::LookupSite::Kind::HashOfMaps:
        kind = "hash_of_maps";
        break;
    case ProgramLoadPlan::LookupSite::Kind::Array:
        kind = "array";
        break;
    case ProgramLoadPlan::LookupSite::Kind::PerCpuArray:
        kind = "percpu_array";
        break;
    }

    char buf[384];
    std::snprintf(buf, sizeof(buf), "%s=%s,0x%llx,%u,%u,%u,%u,%u,0x%llx",
                  name.c_str(),
                  kind,
                  static_cast<unsigned long long>(site.target_addr),
                  static_cast<unsigned>(site.key_offset),
                  static_cast<unsigned>(site.max_entries),
                  static_cast<unsigned>(site.elem_size),
                  static_cast<unsigned>(site.index_mask),
                  static_cast<unsigned>(site.value_offset),
                  static_cast<unsigned long long>(site.percpu_base_addr));
    return std::string(buf);
}

std::string format_update_site_arg(size_t index,
                                   const ProgramLoadPlan::UpdateSite &site)
{
    const char *kind = "call";
    switch (site.kind) {
    case ProgramLoadPlan::UpdateSite::Kind::Call:
        kind = "call";
        break;
    case ProgramLoadPlan::UpdateSite::Kind::Array:
        kind = "array";
        break;
    case ProgramLoadPlan::UpdateSite::Kind::PerCpuArray:
        kind = "percpu_array";
        break;
    }

    char buf[384];
    std::snprintf(buf, sizeof(buf), "%zu=%s,0x%llx,%u,%u,%u,%u,0x%llx",
                  index,
                  kind,
                  static_cast<unsigned long long>(site.target_addr),
                  static_cast<unsigned>(site.max_entries),
                  static_cast<unsigned>(site.elem_size),
                  static_cast<unsigned>(site.value_size),
                  static_cast<unsigned>(site.value_offset),
                  static_cast<unsigned long long>(site.percpu_base_addr));
    return std::string(buf);
}

std::string format_update_map_arg(const std::string &name, uint64_t target_addr)
{
    return format_name_hex(name, target_addr);
}

NativeLinkArgs build_native_link_args(
    const native_loader::ProgramLoadOptions &options,
    const std::unordered_map<std::string, uint64_t> &map_addrs,
    const ProgramLoadPlan &plan)
{
    NativeLinkArgs out{};
    out.linker = native_link_binary(options.native_link_path);
    out.oracle_jit_base = plan.oracle_jit_base;
    out.oracle_jited = plan.oracle_jited;
    out.oracle_xlated = plan.oracle_xlated;
    out.source_helper_ids = plan.source_helper_ids;
#if defined(__x86_64__)
    out.helpers.push_back(format_name_hex(
        kX86BpfMapMaxEntriesOffsetKey, K_BPF_MAP_MAX_ENTRIES_OFFSET));
    out.helpers.push_back(format_name_hex(
        kX86BpfArrayPtrsOffsetKey, K_BPF_ARRAY_PTRS_OFFSET));
    out.helpers.push_back(format_name_hex(
        kX86BpfProgBpfFuncOffsetKey, K_BPF_PROG_BPF_FUNC_OFFSET));
    out.helpers.push_back(format_name_hex(kX86TailCallOffsetKey, 12));
    if (plan.x86_cpu_number_addr != 0 && plan.x86_this_cpu_off != 0) {
        out.helpers.push_back(format_name_hex(
            kX86CpuNumberHelperKey, plan.x86_cpu_number_addr));
        out.helpers.push_back(format_name_hex(
            kX86ThisCpuOffHelperKey, plan.x86_this_cpu_off));
    }
    if (plan.x86_current_task_addr != 0 && plan.x86_this_cpu_off != 0) {
        out.helpers.push_back(format_name_hex(
            kX86CurrentTaskHelperKey, plan.x86_current_task_addr));
        out.helpers.push_back(format_name_hex(
            kX86ThisCpuOffHelperKey, plan.x86_this_cpu_off));
    }
#elif defined(__aarch64__)
    {
        uint32_t cpu_offset = K_THREAD_INFO_CPU_OFFSET;
        out.helpers.push_back(format_name_hex(kArm64ThreadInfoCpuOffsetHelperKey, cpu_offset));
    }
#endif
    if (plan.map_delete_elem_addr != 0) {
        out.helpers.push_back(format_name_hex(
            "bpf_map_delete_elem", plan.map_delete_elem_addr));
    }
    std::vector<std::pair<std::string, uint64_t>> helpers(
        plan.helper_addrs.begin(), plan.helper_addrs.end());
    std::sort(helpers.begin(), helpers.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });
    for (const auto &kv : helpers) {
        out.helpers.push_back(format_name_hex(kv.first, kv.second));
    }

    std::vector<std::pair<std::string, uint64_t>> maps(
        map_addrs.begin(), map_addrs.end());
    std::sort(maps.begin(), maps.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });
    for (const auto &kv : maps) {
        out.maps.push_back(format_name_hex(kv.first, kv.second));
    }

    for (size_t i = 0; i < plan.lookup_sites.size(); i++) {
        out.lookup_sites.push_back(format_lookup_site_arg(i, plan.lookup_sites[i]));
        if (!plan.lookup_sites[i].gen_lookup.empty()) {
            out.lookup_gens.push_back(format_lookup_gen_arg(i, plan.lookup_sites[i]));
        }
    }
    BpfArrayOffsets array_offsets{
        K_BPF_ARRAY_VALUE_OFFSET,
        K_BPF_ARRAY_PTRS_OFFSET,
        K_HTAB_ELEM_KEY_OFFSET,
        K_HTAB_ELEM_LRU_REF_OFFSET,
        plan.x86_this_cpu_off,
    };
    std::vector<std::pair<std::string, std::string>> native_map_symbols(
        plan.native_map_symbols.begin(), plan.native_map_symbols.end());
    std::sort(native_map_symbols.begin(), native_map_symbols.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });
    for (const auto &kv : native_map_symbols) {
        const MapMeta *meta = find_map_meta_by_loaded_name(plan, kv.second);
        if (!meta) {
            fail("native map symbol " + kv.first +
                 " references unknown loaded map " + kv.second);
        }
        ProgramLoadPlan::LookupSite site =
            native_lookup_site_for_map_meta(*meta, array_offsets);
        site.map_name = kv.first;
        out.lookup_maps.push_back(format_lookup_map_arg(kv.first, site));
        if (fd_is_bpf_map(meta->fd)) {
            uint64_t update_target = 0;
            if (try_lookup_kernel_map_update_ptr_by_fd(meta->fd, update_target)) {
                out.update_maps.push_back(format_update_map_arg(kv.first, update_target));
            }
        }
    }
    for (size_t i = 0; i < plan.update_sites.size(); i++) {
        out.update_sites.push_back(format_update_site_arg(i, plan.update_sites[i]));
    }
    return out;
}
