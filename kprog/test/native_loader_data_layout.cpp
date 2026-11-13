/* Exercise the production ELF/BTF binding path and preserve live map bytes. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

struct DataVariable {
    const char *name;
    uint32_t type;
    uint32_t offset;
    uint32_t size;
};

struct DataSection {
    const char *name;
    uint32_t size;
    std::vector<DataVariable> variables;
    uint32_t type = 0;
};

static void require(bool condition, const std::string &message)
{
    if (!condition) fail(message);
}

int main(int argc, char **argv)
try {
    require(argc == 4, "usage: data-layout host|kernel NATIVE_OBJECT OUTPUT");
    const bool kernel = std::string(argv[1]) == "kernel";
    require(kernel || std::string(argv[1]) == "host", "unknown mode");
    const auto output = std::filesystem::path(argv[3]);
    std::unique_ptr<btf, decltype(&btf__free)> types(btf__new_empty(), btf__free);
    require(types != nullptr, "create fixture BTF");
    const int byte = btf__add_int(types.get(), "byte", 1, 0);
    const int half = btf__add_int(types.get(), "half", 2, 0);
    const int word = btf__add_int(types.get(), "word", 4, 0);
    const int wide = btf__add_int(types.get(), "wide", 8, 0);
    require(byte > 0 && half > 0 && word > 0 && wide > 0, "create BTF scalars");
    const int array = btf__add_array(types.get(), word, half, 3);
    require(array > 0, "create BTF array");
    std::vector<DataSection> sections = {
        {".rodata", 16, {{"enabled", static_cast<uint32_t>(byte), 0, 1},
                         {"threshold", static_cast<uint32_t>(word), 4, 4},
                         {"ports", static_cast<uint32_t>(array), 8, 6}}},
        {".data", 8, {{"counter", static_cast<uint32_t>(word), 0, 4},
                      {"limit", static_cast<uint32_t>(word), 4, 4}}},
        {".bss", 16, {{"tracker", static_cast<uint32_t>(wide), 0, 8},
                      {"generation", static_cast<uint32_t>(word), 8, 4}}},
    };
    for (auto &section : sections) {
        std::vector<int> variables;
        for (const auto &variable : section.variables) {
            const int id = btf__add_var(types.get(), variable.name, BTF_VAR_GLOBAL_ALLOCATED, variable.type);
            require(id > 0, "create BTF variable");
            variables.push_back(id);
        }
        const int id = btf__add_datasec(types.get(), section.name, section.size);
        require(id > 0, "create BTF DATASEC");
        section.type = id;
        for (size_t i = 0; i < variables.size(); ++i)
            require(!btf__add_datasec_var_info(types.get(), variables[i],
                    section.variables[i].offset, section.variables[i].size), "add DATASEC variable");
        for (const auto &variable : section.variables)
            require(native_data_symbol_offset(types.get(), section.type, section.name, variable.name)
                    == variable.offset, "wrong BTF variable offset");
    }
    bool missing = false;
    try { native_data_symbol_offset(types.get(), sections[0].type, ".rodata", "missing"); }
    catch (const std::runtime_error &) { missing = true; }
    require(missing, "missing BTF symbol unexpectedly bound");

    // Manifest selection must leave the established data layout off by default.
    const auto manifest = output / "data-manifest.json";
    bpf_prog_info program{};
    std::strcpy(program.name, "entry");
    program.type = BPF_PROG_TYPE_XDP;
    for (const std::string setting : {"", ",\"kernel_data_layout\":false", ",\"kernel_data_layout\":true"}) {
        std::ofstream stream(manifest);
        stream << "{\"objects\":[{\"program\":\"entry\",\"native_object\":\"" << argv[2] << "\"" << setting << "}]}";
        stream.close();
        require(static_cast<bool>(stream), "write fixture manifest");
        const auto match = resolve_native_manifest(manifest, program, std::vector<bpf_insn>(1),
            [](int) -> bpf_map_info { fail("unexpected manifest map lookup"); });
        require(match && match->kernel_data_layout == (setting.find("true") != std::string::npos),
                "data layout manifest default/selection changed");
    }
    if (!kernel) {
        std::cout << "host BTF offsets/array/missing symbol/default-off manifest: PASS\n";
        return 0;
    }

    require(!btf__load_into_kernel(types.get()), "load fixture BTF");
    std::vector<std::unique_ptr<ScopedFd>> maps;
    std::vector<std::vector<uint8_t>> values;
    CompanionLoad load;
    const uint32_t key = 0;
    for (const auto &section : sections) {
        bpf_map_create_opts options{};
        options.sz = sizeof(options);
        options.btf_fd = btf__fd(types.get());
        options.btf_key_type_id = word;
        options.btf_value_type_id = section.type;
        auto fd = std::make_unique<ScopedFd>(bpf_map_create(BPF_MAP_TYPE_ARRAY,
            ("layout" + std::string(section.name)).c_str(), 4, section.size, 1, &options));
        require(fd->get() >= 0, "create fixture map: " + std::string(strerror(errno)));
        std::vector<uint8_t> value(section.size);
        for (size_t i = 0; i < value.size(); ++i) value[i] = 21 + i;
        require(!bpf_map_update_elem(fd->get(), &key, value.data(), 0), "configure fixture map");
        add_map_meta(load, load_map_meta_from_fd(fd->get()));
        maps.push_back(std::move(fd));
        values.push_back(std::move(value));
    }
    CompanionLoad legacy = load;
    add_native_data_symbol_addrs(argv[2], legacy);
    require(!legacy.map_addrs.contains("threshold") && !legacy.map_addrs.contains("limit") &&
            !legacy.map_addrs.contains("generation"), "fixture did not expose native padding mismatch");
    add_native_data_symbol_addrs(argv[2], load, true);
    std::ofstream report(output / "data-layout.jsonl");
    require(static_cast<bool>(report), "open data layout report");
    for (size_t i = 0; i < sections.size(); ++i) {
        const auto &section = sections[i];
        const auto *map = find_singleton_array_data_map(load, section.name, 0);
        require(map != nullptr, "fixture map disappeared");
        for (const auto &variable : section.variables) {
            require(load.map_addrs.at(variable.name) == map->value_addr + variable.offset,
                    "native symbol did not bind to BPF variable offset");
            require(load.map_addr_ids.at(variable.name) == map->kernel_id, "lost data map identity");
            report << "{\"section\":\"" << section.name << "\",\"symbol\":\"" << variable.name
                   << "\",\"map_id\":" << map->kernel_id << ",\"offset\":" << variable.offset << "}\n";
        }
        std::vector<uint8_t> actual(section.size);
        require(!bpf_map_lookup_elem(maps[i]->get(), &key, actual.data()), "read fixture map");
        require(actual == values[i], "binding overwrote application-configured global bytes");
    }
    report.close();
    require(static_cast<bool>(report), "write data layout report");
    // Bad metadata must fail without leaking the native ELF or BTF descriptors.
    const auto fd_count = [] {
        return std::distance(std::filesystem::directory_iterator("/proc/self/fd"),
                             std::filesystem::directory_iterator());
    };
    CompanionLoad invalid = load;
    for (auto &map : invalid.maps) map.btf_value_type_id = word;
    const auto before = fd_count();
    bool rejected = false;
    try { add_native_data_symbol_addrs(argv[2], invalid, true); }
    catch (const std::runtime_error &) { rejected = true; }
    require(rejected && fd_count() == before, "invalid metadata succeeded or leaked descriptors");
    std::cout << "kernel production binding: 7 symbols/3 maps, configured bytes preserved: PASS\n";
    return 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
}
