/* Original declarations, not guessed function signatures, drive bindings. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

using TestBtf = std::unique_ptr<btf, decltype(&btf__free)>;

static void require(bool condition, const std::string &message)
{
    if (!condition) fail(message);
}

static TestBtf fixture_btf(bool present, bool wrong_kind, bool external)
{
    TestBtf types(btf__new_empty(), btf__free);
    require(types != nullptr, "create BTF fixture");
    const int result = btf__add_int(types.get(), "signed_word", 8, BTF_INT_SIGNED);
    int arg = btf__add_int(types.get(), "unsigned_word", 8, 0);
    if (wrong_kind) arg = btf__add_ptr(types.get(), arg);
    require(result > 0 && arg > 0, "add fixture BTF scalars");
    if (!external) require(btf__add_int(types.get(), "extra_target_type", 1, 0) > 0, "add target-only type");
    std::vector<uint32_t> kernel_functions;
    for (const char *name : {"present", "absent"}) {
        if (!external && !present) continue;
        if (!external && std::string(name) == "absent") continue;
        if (!present && std::string(name) == "present") continue;
        const int prototype = btf__add_func_proto(types.get(), result);
        require(prototype > 0 && !btf__add_func_param(types.get(), "value", arg), "add BTF prototype");
        const int function = btf__add_func(types.get(), name,
            external ? BTF_FUNC_EXTERN : BTF_FUNC_GLOBAL, prototype);
        require(function > 0, "add BTF function");
        kernel_functions.push_back(function);
    }
    const int ordinary_proto = btf__add_func_proto(types.get(), result);
    require(ordinary_proto > 0 && !btf__add_func_param(types.get(), "value", arg), "add ordinary prototype");
    require(btf__add_func(types.get(), "ordinary", external ? BTF_FUNC_EXTERN : BTF_FUNC_GLOBAL,
                         ordinary_proto) > 0, "add ordinary function");
    if (external) {
        require(btf__add_datasec(types.get(), ".ksyms", 0) > 0, "add .ksyms");
        for (const auto function : kernel_functions)
            require(!btf__add_datasec_var_info(types.get(), function, 0, 0), "add .ksyms function");
    }
    return types;
}

template<typename Function>
static void fails(Function function, const char *reason)
{
    bool failed = false;
    try { function(); }
    catch (const std::runtime_error &) { failed = true; }
    require(failed, reason);
}

static void proof_relocations(const btf *local, const btf *target, const btf *empty)
{
    GElf_Sym weak{};
    weak.st_info = GELF_ST_INFO(STB_WEAK, STT_NOTYPE);
    weak.st_shndx = SHN_UNDEF;
    bpf_insn call{};
    call.code = BPF_JMP | BPF_CALL; call.src_reg = BPF_PSEUDO_CALL; call.imm = -1;
    auto present_call = call, missing_call = call;
    relocate_vmlinux_proof_call(local, target, "present", weak, 0, present_call);
    require(present_call.src_reg == BPF_PSEUDO_KFUNC_CALL && present_call.imm > 0,
            "present weak call did not bind target BTF");
    relocate_vmlinux_proof_call(local, empty, "present", weak, 0, missing_call);
    require(!missing_call.src_reg && missing_call.imm == -1,
            "missing weak call was made executable instead of poisoned");
    bpf_insn low{}, high{};
    low.code = BPF_LD | BPF_DW | BPF_IMM; low.dst_reg = BPF_REG_1;
    auto present_address = low, missing_address = low;
    relocate_vmlinux_proof_function_address(local, target, "present", weak, 0, present_address, high);
    require(present_address.src_reg == BPF_PSEUDO_BTF_ID && present_address.imm == present_call.imm && !high.imm,
            "function address did not use matching vmlinux BTF ID");
    relocate_vmlinux_proof_function_address(local, empty, "present", weak, 0, missing_address, high);
    require(!missing_address.src_reg && !missing_address.imm && !high.imm,
            "missing weak function guard did not retain null");
    GElf_Sym strong = weak;
    strong.st_info = GELF_ST_INFO(STB_GLOBAL, STT_NOTYPE);
    fails([&] { relocate_vmlinux_proof_call(local, empty, "present", strong, 0, call); },
          "missing strong proof call became a poisoned weak call");
    fails([&] { relocate_vmlinux_proof_function_address(local, empty, "present", strong, 0, low, high); },
          "missing strong function address silently became null");
}

static void kernel_proof(const std::filesystem::path &fixture, const std::filesystem::path &output)
{
    std::ofstream results(output / "proof-loads.jsonl");
    require(static_cast<bool>(results), "open proof load report");
    for (const char *name : {"guarded", "unguarded"}) {
        std::unique_ptr<bpf_object, decltype(&bpf_object__close)> object(
            bpf_object__open_file(fixture.c_str(), nullptr), bpf_object__close);
        require(object != nullptr, "open original proof fixture");
        bpf_program *program = bpf_object__find_program_by_name(object.get(), name);
        require(program != nullptr, "find proof fixture entry");
        std::vector<bpf_insn> proof(bpf_program__insns(program),
            bpf_program__insns(program) + bpf_program__insn_cnt(program));
        CompanionLoad companion;
        std::vector<std::unique_ptr<ScopedFd>> pins;
        relocate_trusted_proof(object.get(), fixture, name, companion, proof, pins, {});
        std::ofstream instructions(output / (std::string(name) + ".insns"), std::ios::binary);
        instructions.write(reinterpret_cast<const char *>(proof.data()), proof.size() * sizeof(bpf_insn));
        instructions.close(); require(static_cast<bool>(instructions), "write relocated fixture instructions");
        std::vector<char> log(1024 * 1024);
        bpf_prog_load_opts options{};
        options.sz = sizeof(options); options.log_buf = log.data(); options.log_size = log.size(); options.log_level = 1;
        ScopedFd loaded(bpf_prog_load(BPF_PROG_TYPE_KPROBE, name, "GPL", proof.data(), proof.size(), &options));
        std::ofstream diagnostic(output / (std::string(name) + ".verifier.log"));
        diagnostic << log.data(); diagnostic.close();
        require(static_cast<bool>(diagnostic), "write fixture verifier log");
        const bool expected = std::string(name) == "guarded";
        require((loaded.get() >= 0) == expected, std::string(name) + " verifier outcome differs: " + log.data());
        if (!expected)
            require(std::string(log.data()).find("invalid func unknown#-1") != std::string::npos,
                    "unguarded weak call rejected for unrelated reason");
        results << "{\"program\":\"" << name << "\",\"accepted\":" << (loaded.get() >= 0 ? "true" : "false") << "}\n";
    }
    results.close(); require(static_cast<bool>(results), "write proof load report");
}

static void kernel_model(const std::filesystem::path &fixture, const std::filesystem::path &output)
{
    std::filesystem::create_directories(output);
    ScopedFd input(bpf_map_create(BPF_MAP_TYPE_ARRAY, "kfunc_input", 4, 8, 1, nullptr));
    require(input.get() >= 0, "create model environment input");
    const auto info = load_map_info(input.get());
    MapMeta meta{}; meta.kernel_id = info.id; meta.value_size = info.value_size;
    CompanionLoad companion; companion.maps.push_back(meta);
    std::unique_ptr<bpf_object, decltype(&bpf_object__close)> object(
        bpf_object__open_file(fixture.c_str(), nullptr), bpf_object__close);
    require(object != nullptr, "open generated kfunc model");
    const char *name = "trusted_x86_x86_sim_xdp";
    auto *program = bpf_object__find_program_by_name(object.get(), name);
    require(program != nullptr, "find generated kfunc model");
    std::vector<bpf_insn> proof(bpf_program__insns(program),
        bpf_program__insns(program) + bpf_program__insn_cnt(program));
    std::vector<std::unique_ptr<ScopedFd>> pins;
    relocate_trusted_proof(object.get(), fixture, name, companion, proof, pins,
        {{"kprog_unspecified_input", info.id, 0}});
    std::vector<char> log(1024 * 1024);
    bpf_prog_load_opts options{};
    options.sz = sizeof(options); options.log_buf = log.data(); options.log_size = log.size(); options.log_level = 1;
    ScopedFd loaded(bpf_prog_load(BPF_PROG_TYPE_KPROBE, "kfunc_model", "GPL", proof.data(), proof.size(), &options));
    std::ofstream diagnostic(output / "model.verifier.log");
    diagnostic << log.data(); diagnostic.close(); require(static_cast<bool>(diagnostic), "write model verifier log");
    require(loaded.get() >= 0, "generated kfunc model rejected: " + std::string(log.data()));
}

int main(int argc, char **argv)
try {
    require(argc >= 9, "usage: kfunc host|kernel WEAK_OBJECT STRONG_OBJECT SOURCE_BPF SOURCE_NATIVE KERNEL_BTF OUTPUT PROOF_FIXTURE [MODEL_PROOF...]");
    const bool kernel_mode = std::string(argv[1]) == "kernel";
    require(kernel_mode || std::string(argv[1]) == "host", "unknown kfunc test mode");
    auto local = fixture_btf(true, false, true);
    auto target = fixture_btf(true, false, false);
    auto empty = fixture_btf(false, false, false);
    auto wrong = fixture_btf(true, true, false);
    proof_relocations(local.get(), target.get(), empty.get());
    const auto id = native_kfunc_type_id(local.get(), target.get(), "present", false);
    require(id == static_cast<uint32_t>(btf__find_by_name_kind(target.get(), "present", BTF_KIND_FUNC)),
            "binding used the declaration's ID instead of target ID");
    require(native_kfunc_type_id(local.get(), empty.get(), "present", true) == 0,
            "missing weak function was forced available");
    fails([&] { native_kfunc_type_id(local.get(), empty.get(), "present", false); }, "missing strong function passed");
    fails([&] { native_kfunc_type_id(local.get(), wrong.get(), "present", true); }, "weak prototype mismatch passed");
    fails([&] { native_kfunc_type_id(target.get(), target.get(), "present", true); }, "defined local function passed as kfunc");
    fails([&] { native_kfunc_type_id(local.get(), target.get(), "unknown", true); }, "missing original declaration passed");
    const auto missing = native_kernel_function_targets(argv[2], local.get(), empty.get());
    require(missing.size() == 2 && missing[0].first == "absent" && missing[1].first == "present"
            && !missing[0].second && !missing[1].second, "absent weak ELF bindings did not retain null values");
    require(native_kernel_function_targets(argv[2], target.get(), target.get()).empty(),
            "ordinary function without .ksyms was treated as a kernel extern");
    fails([&] { native_kernel_function_targets(argv[3], local.get(), empty.get()); }, "strong ELF reference silently became null");

    TestBtf source(btf__parse(argv[4], nullptr), btf__free);
    TestBtf running(btf__parse(argv[6], nullptr), btf__free);
    require(source && running, "parse actual original/target BTF");
    std::ofstream report(std::filesystem::path(argv[7]) / "kfunc-types.jsonl");
    require(static_cast<bool>(report), "open kfunc report");
    for (const char *name : {"bpf_strncasestr", "bpf_strnstr", "bpf_iter_num_new",
                            "bpf_iter_num_next", "bpf_iter_num_destroy"}) {
        const auto resolved = native_kfunc_type_id(source.get(), running.get(), name, true);
        require(resolved != 0, "real target function unexpectedly absent");
        report << "{\"name\":\"" << name << "\",\"target_btf_id\":" << resolved << "}\n";
    }
    if (kernel_mode) {
        const auto targets = native_kernel_function_targets(argv[5], source.get(), running.get());
        require(targets.size() == 5, "actual weak kfunc symbol set changed");
        std::ofstream addresses(std::filesystem::path(argv[7]) / "kfunc-addresses.jsonl");
        require(static_cast<bool>(addresses), "open kfunc addresses");
        for (const auto &[name, address] : targets) {
            require(address != 0, "real present kfunc resolved to null");
            addresses << "{\"name\":\"" << name << "\",\"address\":" << address << "}\n";
        }
        addresses.close();
        require(static_cast<bool>(addresses), "write kfunc addresses");
        kernel_proof(argv[8], argv[7]);
        for (int i = 9; i < argc; ++i)
            kernel_model(argv[i], std::filesystem::path(argv[7]) / ("model-" + std::to_string(i - 9)));
    }
    const auto manifest = std::filesystem::path(argv[7]) / "kfunc-manifest.json";
    bpf_prog_info info{}; std::strcpy(info.name, "entry"); info.type = BPF_PROG_TYPE_KPROBE;
    for (const std::string setting : {"", ",\"kernel_kfunc_context\":false", ",\"kernel_kfunc_context\":true"}) {
        std::ofstream out(manifest);
        out << "{\"objects\":[{\"program\":\"entry\",\"native_object\":\"" << argv[2] << "\""
            << setting << ",\"kernel_kfunc_btf\":\"../inputs/source.bpf.o\"}]}";
        out.close(); require(static_cast<bool>(out), "write kfunc manifest");
        const auto selected = resolve_native_manifest(manifest, info, std::vector<bpf_insn>(1),
            [](int) -> bpf_map_info { fail("unexpected map query"); });
        require(selected && selected->kernel_kfunc_context == (setting.find("true") != std::string::npos),
                "kfunc manifest selection/default changed");
        require(selected->kernel_kfunc_btf == manifest.parent_path() / "../inputs/source.bpf.o",
                "original object BTF path was not relative to the manifest");
    }
    report.close(); require(static_cast<bool>(report), "write kfunc report");
    std::cout << "kfunc BTF prototype/weak null/strong error/real five declarations/default-off: PASS\n";
    return 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
}
