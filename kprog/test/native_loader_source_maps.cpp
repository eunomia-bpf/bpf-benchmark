// Regression: user-loader FD substitution must win over a same-named map,
// including references in a separately placed BPF subprogram.
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

static void require(bool condition, const std::string &message) { if (!condition) fail(message); }

// Read known fixture function bytes independently of the production relocation
// walker. The final load layout and FD substitutions below model loader work.
static std::vector<bpf_insn> fixture_function(const char *path, const char *function)
{
    ScopedFd fd(open(path, O_RDONLY));
    require(fd.get() >= 0, "open fixture");
    require(elf_version(EV_CURRENT) != EV_NONE, "initialize ELF");
    std::unique_ptr<Elf, decltype(&elf_end)> elf(elf_begin(fd.get(), ELF_C_READ, nullptr), elf_end);
    require(elf != nullptr, "read fixture ELF");
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf.get(), section))) {
        GElf_Shdr h{};
        require(gelf_getshdr(section, &h), "fixture section");
        if (h.sh_type != SHT_SYMTAB) continue;
        auto *data = elf_getdata(section, nullptr);
        for (size_t i = 0; i < h.sh_size / h.sh_entsize; ++i) {
            GElf_Sym sym{};
            require(gelf_getsym(data, i, &sym), "fixture symbol");
            const char *name = elf_strptr(elf.get(), h.sh_link, sym.st_name);
            require(name != nullptr, "fixture name");
            if (std::strcmp(name, function)) continue;
            auto *code = elf_getdata(elf_getscn(elf.get(), sym.st_shndx), nullptr);
            require(code && sym.st_value + sym.st_size <= code->d_size && sym.st_size % 8 == 0,
                    "fixture function extent");
            std::vector<bpf_insn> result(sym.st_size / 8);
            std::memcpy(result.data(), static_cast<const char *>(code->d_buf) + sym.st_value, sym.st_size);
            return result;
        }
    }
    fail("fixture function not found");
}

static size_t substitute(std::vector<bpf_insn> &code, int fd)
{
    size_t maps = 0;
    for (auto &insn : code) if (insn.code == (BPF_LD | BPF_DW | BPF_IMM)) {
        insn.src_reg = BPF_PSEUDO_MAP_FD; insn.imm = fd; ++maps;
    }
    return maps;
}

static int kernel_binding(const char *original, const char *native,
                          const char *linker, const char *directory)
{
    ScopedFd actual(bpf_map_create(BPF_MAP_TYPE_ARRAY, "substituted", 4, 8, 1, nullptr));
    ScopedFd decoy(bpf_map_create(BPF_MAP_TYPE_ARRAY, "logical", 4, 8, 1, nullptr));
    require(actual.get() >= 0 && decoy.get() >= 0, "create real resource/decoy maps");
    const uint32_t key = 0;
    const uint64_t wrong = 11;
    require(!bpf_map_update_elem(decoy.get(), &key, &wrong, 0), "configure decoy");
    auto code = fixture_function(original, "entry");
    auto shared = fixture_function(original, "shared");
    require(substitute(code, actual.get()) == 1 && substitute(shared, actual.get()) == 1,
            "runtime source map slots changed");
    for (size_t i = 0; i < code.size(); ++i)
        if (code[i].code == (BPF_JMP | BPF_CALL) && code[i].src_reg == BPF_PSEUDO_CALL)
            code[i].imm = code.size() - i - 1;
    code.insert(code.end(), shared.begin(), shared.end());
    std::vector<char> log(1 << 20);
    bpf_prog_load_opts options{};
    options.sz = sizeof(options); options.log_buf = log.data(); options.log_size = log.size(); options.log_level = 1;
    ScopedFd source(bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER, "entry", "GPL", code.data(), code.size(), &options));
    if (source.get() < 0) fail("load actual rewritten source: " + std::string(log.data()));
    const auto output = std::filesystem::path(directory);
    const auto manifest = output / "runtime-manifest.json";
    std::ofstream config(manifest);
    config << "{\"objects\":[{\"program\":\"entry\",\"symbol\":\"entry\",\"native_object\":\""
        << native << "\",\"source_bpf_object\":\"" << original << "\"}]}";
    config.close(); require(static_cast<bool>(config), "write runtime manifest");
    native_loader::FdLoadOptions load;
    load.original_prog_fd = source.get(); load.source_insns = code;
    load.manifest_path = manifest; load.native_link_path = linker;
    require(!setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF", "1", 1), "select registered service");
    auto installed = native_loader::load_from_fd(load);
    require(installed.replaced && installed.prog_fd >= 0, "native resource-binding installation failed");
    std::ofstream results(output / "execution.jsonl");
    for (uint64_t configured : {29, 73}) {
        require(!bpf_map_update_elem(actual.get(), &key, &configured, 0), "update current resource");
        for (const auto &[route, fd] : std::vector<std::pair<const char *, int>>{{"stock",source.get()}, {"native",installed.prog_fd}}) {
            unsigned char packet[64]{};
            bpf_test_run_opts test{}; test.sz = sizeof(test); test.data_in = packet;
            test.data_size_in = sizeof(packet); test.repeat = 1;
            require(!bpf_prog_test_run_opts(fd, &test), "execute real source/native program");
            results << "{\"route\":\"" << route << "\",\"configured\":" << configured
                << ",\"retval\":" << test.retval << "}\n";
            results.flush(); require(static_cast<bool>(results), "write runtime results");
            require(test.retval == configured * 2, "native used decoy or stale map data instead of current source resource");
        }
    }
    native_loader::close_loaded_program(&installed);
    std::cout << "kernel original-load resource substitution, subprogram references and mutable live values: PASS\n";
    return 0;
}

int main(int argc, char **argv)
try {
    if (argc == 6 && std::string(argv[1]) == "kernel")
        return kernel_binding(argv[2], argv[3], argv[4], argv[5]);
    require(argc == 4, "usage: source-maps ORIGINAL_BPF NATIVE OUTPUT");
    auto root = fixture_function(argv[1], "entry");
    auto callee = fixture_function(argv[1], "shared");
    auto other = fixture_function(argv[1], "other_entry");
    require(substitute(root, 101) == 1 && substitute(callee, 202) == 1 && substitute(other, 303) == 1,
            "fixture map-reference count changed");
    size_t calls = 0;
    for (size_t i = 0; i < root.size(); ++i) if (root[i].code == (BPF_JMP | BPF_CALL) && root[i].src_reg == BPF_PSEUDO_CALL) {
        root[i].imm = root.size() - i - 1; ++calls;
    }
    require(calls == 1, "fixture lacks its real BPF subprogram call");
    root.insert(root.end(), callee.begin(), callee.end());
    const auto bindings = SourceBpfMaps(argv[1]).bind("entry", root);
    require(bindings.size() == 2 && bindings[0].symbol == "logical" && bindings[1].symbol == "logical" &&
            bindings[0].fd == 101 && bindings[1].fd == 202 && bindings[1].loaded_slot >= root.size() - callee.size(),
            "original relocation/current call layout correspondence lost");
    auto dynamic = fixture_function(argv[1], "dynamic_entry");
    for (size_t i = 0; i < dynamic.size(); ++i)
        if (dynamic[i].code == (BPF_JMP | BPF_CALL) && dynamic[i].src_reg == BPF_PSEUDO_CALL)
            dynamic[i].imm = dynamic.size() - i - 1;
    dynamic.insert(dynamic.end(), callee.begin(), callee.end());
    require(SourceBpfMaps(argv[1]).bind("dynamic_entry", dynamic).size() == 1,
            "undefined generated callee was mistaken for an original local function");
    CompanionLoad load;
    MapMeta actual{}, decoy{}, duplicate{};
    actual.name = "same_name"; actual.kernel_id = 501; actual.kernel_addr = 0x1000;
    actual.type = BPF_MAP_TYPE_ARRAY; actual.key_size = 4; actual.value_size = 8; actual.max_entries = 1;
    decoy = actual; decoy.name = "logical"; decoy.kernel_id = 601; decoy.kernel_addr = 0x2000;
    duplicate = actual; duplicate.kernel_id = 502; duplicate.kernel_addr = 0x3000;
    load.maps = {decoy, actual, duplicate};
    load.source_maps_by_fd = {{101, actual}, {202, actual}, {303, duplicate}};
    load.map_addrs["logical"] = decoy.kernel_addr;
    load.map_addr_ids["logical"] = decoy.kernel_id;
    load.native_map_symbols["logical"] = decoy.name;
    bind_original_source_maps(argv[1], "entry", root, load);
    require(load.map_addrs.at("logical") == actual.kernel_addr && load.map_addr_ids.at("logical") == actual.kernel_id,
            "same-named decoy overrode the original-load FD identity");
    require(find_map_meta_by_native_symbol(load, "logical")->kernel_id == actual.kernel_id,
            "lookup plan fell back to ambiguous loaded-map names");
    bind_original_source_maps(argv[1], "other_entry", other, load);
    require(load.map_addr_ids.at("other") == duplicate.kernel_id, "other entry lost its separate resource");
    auto conflict = load;
    conflict.source_maps_by_fd[202] = duplicate;
    bool failed = false;
    try { bind_original_source_maps(argv[1], "entry", root, conflict); }
    catch (const std::runtime_error &error) { failed = std::string(error.what()).find("different current resource identities") != std::string::npos; }
    require(failed, "incompatible per-reference resources silently collapsed to one native global");
    auto missing = root;
    missing.at(bindings[0].loaded_slot).src_reg = 0;
    const std::unordered_set<std::string> unused;
    require(SourceBpfMaps(argv[1]).bind("entry", missing, &unused).empty(),
            "unused source map imposed a binding requirement on the selected native entry");
    failed = false;
    try { SourceBpfMaps(argv[1]).bind("entry", missing); }
    catch (const std::runtime_error &error) { failed = std::string(error.what()).find("current map FD") != std::string::npos; }
    require(failed, "missing intercepted relocation silently used process-name lookup");

    bpf_prog_info info{}; info.type = BPF_PROG_TYPE_SOCKET_FILTER; std::strcpy(info.name, "entry");
    for (bool enabled : {false, true}) {
        const auto manifest = std::filesystem::path(argv[3]) /
            (enabled ? "enabled-manifest.json" : "disabled-manifest.json");
        std::ofstream f(manifest);
        f << "{\"objects\":[{\"program\":\"entry\",\"native_object\":\"" << argv[2] << "\"";
        if (enabled) f << ",\"source_bpf_object\":\"fixture.bpf.o\"";
        f << "}]}"; f.close(); require(static_cast<bool>(f), "write manifest");
        const auto selected = resolve_native_manifest(manifest, info, std::vector<bpf_insn>(1),
            [](int) -> bpf_map_info { fail("unexpected map resolution"); });
        require(selected && (enabled ? selected->source_bpf_object == manifest.parent_path() / "fixture.bpf.o"
                                     : selected->source_bpf_object.empty()), "optional source object path/default changed");
    }
    std::cout << "original ELF/final FD binding, subprogram layout, resource-ID lookup, conflicts, default-off manifest: PASS\n";
    return 0;
} catch (const std::exception &error) { std::cerr << error.what() << '\n'; return 1; }
