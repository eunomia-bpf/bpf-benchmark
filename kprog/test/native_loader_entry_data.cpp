// Regression: another entry's absent BTF global must not prevent this entry's
// load; a reachable global missing from that same DATASEC must still fail.
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

static void require(bool condition, const std::string &message)
{
    if (!condition) fail(message);
}

int main(int argc, char **argv)
try {
    require(argc == 6, "usage: entry-data host|kernel NATIVE_OBJECT NATIVE_LINK OUTPUT EXISTING_PROOF");
    const bool kernel = std::string(argv[1]) == "kernel";
    require(kernel || std::string(argv[1]) == "host", "unknown mode");
    const std::filesystem::path output = argv[4];
    const auto entry = cached_native_entry_proof(argv[3], argv[2], "entry");
    const auto other = cached_native_entry_proof(argv[3], argv[2], "other_entry");
    const auto entry_names = native_entry_symbol_names(entry);
    const auto other_names = native_entry_symbol_names(other);
    require(entry_names.contains("live_value") && entry_names.contains("shared_read") &&
            !entry_names.contains("other_value"), "callee/global reachability lost entry identity");
    require(other_names.contains("other_value") && !other_names.contains("live_value"),
            "other entry inherited unrelated globals");
    const auto modified = std::filesystem::last_write_time(entry);
    require(cached_native_entry_proof(argv[3], argv[2], "entry") == entry &&
            std::filesystem::last_write_time(entry) == modified, "entry extraction cache rebuilt on a hit");
    std::filesystem::copy_file(entry, output / "entry.proof.o");
    std::filesystem::copy_file(other, output / "other-entry.proof.o");
    // Also exercise the ELF reader on a retained real application artifact.
    const auto actual_names = native_entry_symbol_names(argv[5]);
    std::ofstream names(output / "existing-proof-symbols.txt");
    for (const auto &name : std::set<std::string>(actual_names.begin(), actual_names.end())) names << name << '\n';
    names.close();
    require(static_cast<bool>(names), "write real entry symbol inventory");
    NativeLinkArgs args;
    args.linker = argv[3];
    args.maps.push_back({"live_value", 0}); // Existing address-neutral link template.
    const auto fresh = invoke_native_link(argv[2], "entry", args, output / "fresh", {}, {});
    const auto reused = invoke_native_link(argv[2], "entry", args, output / "reused", {}, entry);
    require(read_binary_file(fresh.proof) == read_binary_file(reused.proof) &&
            read_binary_file(fresh.blob) == read_binary_file(reused.blob) &&
            read_binary_file(fresh.relocs) == read_binary_file(reused.relocs) &&
            read_binary_file(fresh.map_patches) == read_binary_file(reused.map_patches) &&
            read_binary_file(fresh.abi) == read_binary_file(reused.abi),
            "reused entry extraction changed native code or its sidebands");
    if (!kernel) {
        std::cout << "entry/callee/global reachability, cache, real ELF inventory, identical fresh/reused native template: PASS\n";
        return 0;
    }

    std::unique_ptr<btf, decltype(&btf__free)> types(btf__new_empty(), btf__free);
    require(types != nullptr, "create fixture BTF");
    const int word = btf__add_int(types.get(), "unsigned", 4, 0);
    require(word > 0, "create BTF scalar");
    const int variable = btf__add_var(types.get(), "live_value", BTF_VAR_GLOBAL_ALLOCATED, word);
    require(variable > 0, "create live BTF variable");
    const int section = btf__add_datasec(types.get(), ".rodata.config", 8);
    require(section > 0 && !btf__add_datasec_var_info(types.get(), variable, 4, 4), "create live DATASEC");
    require(!btf__load_into_kernel(types.get()), "load fixture BTF");
    bpf_map_create_opts options{};
    options.sz = sizeof(options);
    options.btf_fd = btf__fd(types.get());
    options.btf_key_type_id = word;
    options.btf_value_type_id = section;
    ScopedFd map(bpf_map_create(BPF_MAP_TYPE_ARRAY, "f.rodata.config", 4, 8, 1, &options));
    require(map.get() >= 0, "create config map: " + std::string(std::strerror(errno)));
    const uint32_t key = 0;
    const uint32_t values[2] = {0x12345678, 91};
    require(!bpf_map_update_elem(map.get(), &key, values, 0), "write application config");
    CompanionLoad source;
    add_map_meta(source, load_map_meta_from_fd(map.get()));
    auto legacy = source;
    add_native_data_symbol_addrs(argv[2], legacy);
    require(legacy.native_data_symbols.contains("other_value"), "default data layout unexpectedly filtered globals");
    auto load = source;
    add_native_data_symbol_addrs(argv[2], load, true, &entry_names);
    require(load.native_data_symbols.contains("live_value") &&
            !load.native_data_symbols.contains("other_value"), "unused global became a capability");
    const auto &meta = source.maps.at(0);
    require(load.map_addrs.at("live_value") == meta.value_addr + 4 &&
            load.map_addr_ids.at("live_value") == meta.kernel_id, "lost live symbol BTF offset/map identity");
    for (const auto *selection : {static_cast<const std::unordered_set<std::string> *>(nullptr), &other_names}) {
        bool rejected = false;
        auto invalid = source;
        try { add_native_data_symbol_addrs(argv[2], invalid, true, selection); }
        catch (const std::runtime_error &error) {
            rejected = std::string(error.what()).find("lacks native symbol other_value") != std::string::npos;
        }
        require(rejected, "reachable missing global or whole-object failure disappeared");
    }
    uint32_t actual[2]{};
    require(!bpf_map_lookup_elem(map.get(), &key, actual) && std::equal(actual, actual + 2, values),
            "binding altered application config bytes");
    std::cout << "kernel selected-entry binding, actual BTF offset/map identity, needed-missing error, live bytes: PASS\n";
    return 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
}
