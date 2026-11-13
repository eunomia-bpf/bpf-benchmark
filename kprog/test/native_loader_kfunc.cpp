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
    for (const char *name : {"present", "absent"}) {
        if (!external && !present) continue;
        if (!external && std::string(name) == "absent") continue;
        if (!present && std::string(name) == "present") continue;
        const int prototype = btf__add_func_proto(types.get(), result);
        require(prototype > 0 && !btf__add_func_param(types.get(), "value", arg), "add BTF prototype");
        require(btf__add_func(types.get(), name, external ? BTF_FUNC_EXTERN : BTF_FUNC_GLOBAL,
                             prototype) > 0, "add BTF function");
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

int main(int argc, char **argv)
try {
    require(argc == 8, "usage: kfunc host|kernel WEAK_OBJECT STRONG_OBJECT SOURCE_BPF SOURCE_NATIVE KERNEL_BTF OUTPUT");
    const bool kernel_mode = std::string(argv[1]) == "kernel";
    require(kernel_mode || std::string(argv[1]) == "host", "unknown kfunc test mode");
    auto local = fixture_btf(true, false, true);
    auto target = fixture_btf(true, false, false);
    auto empty = fixture_btf(false, false, false);
    auto wrong = fixture_btf(true, true, false);
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
    }
    const auto manifest = std::filesystem::path(argv[7]) / "kfunc-manifest.json";
    bpf_prog_info info{}; std::strcpy(info.name, "entry"); info.type = BPF_PROG_TYPE_KPROBE;
    for (const std::string setting : {"", ",\"kernel_kfunc_context\":false", ",\"kernel_kfunc_context\":true"}) {
        std::ofstream out(manifest);
        out << "{\"objects\":[{\"program\":\"entry\",\"native_object\":\"" << argv[2] << "\"" << setting << "}]}";
        out.close(); require(static_cast<bool>(out), "write kfunc manifest");
        const auto selected = resolve_native_manifest(manifest, info, std::vector<bpf_insn>(1),
            [](int) -> bpf_map_info { fail("unexpected map query"); });
        require(selected && selected->kernel_kfunc_context == (setting.find("true") != std::string::npos),
                "kfunc manifest selection/default changed");
    }
    report.close(); require(static_cast<bool>(report), "write kfunc report");
    std::cout << "kfunc BTF prototype/weak null/strong error/real five declarations/default-off: PASS\n";
    return 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
}
