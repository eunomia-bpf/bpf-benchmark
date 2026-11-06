/* Catch selecting the wrong full BTF entry after the kernel truncates its name. */
#include "../libnativeloader/src/native_loader_manifest.hpp"
#include <cassert>
#include <iostream>

int main()
{
    const std::filesystem::path path = "build/btf-manifest.json";
    bpf_prog_info info{};
    info.type = BPF_PROG_TYPE_XDP;
    std::strcpy(info.name, "tracepoint__sys");
    std::vector<bpf_insn> insns(1);
    insns[0].code = BPF_JMP | BPF_EXIT;
    const auto load_map = [](int) -> bpf_map_info { throw std::runtime_error("unexpected map access"); };
    const auto manifest = [&](const std::string &first, const std::string &second) {
        std::ofstream output(path);
        output << "{\"objects\":[{\"program\":\"tracepoint__sys\",\"native_object\":\"manifest-object.o\","
            "\"symbol\":\"enter\"" << first << "},{\"program\":\"tracepoint__sys\","
            "\"native_object\":\"manifest-object.o\",\"symbol\":\"exit\"" << second << "}]}";
        output.close();
        assert(output);
    };
    std::ofstream object("build/manifest-object.o");
    object.close();
    assert(object);
    manifest(",\"source_btf_symbol\":\"tracepoint__sys_enter_openat\"",
             ",\"source_btf_symbol\":\"tracepoint__sys_exit_openat\"");
    for (const auto &pair : {std::pair{"tracepoint__sys_enter_openat", "enter"},
                            std::pair{"tracepoint__sys_exit_openat", "exit"}}) {
        auto result = resolve_native_manifest(path, info, insns, load_map, pair.first);
        assert(result && result->symbol_name == pair.second);
    }
    assert(!resolve_native_manifest(path, info, insns, load_map, "tracepoint__sys"));
    assert(!resolve_native_manifest(path, info, insns, load_map, "tracepoint__sys_enter_other"));
    const auto rejects = [&](const std::string &expected) {
        try {
            resolve_native_manifest(path, info, insns, load_map);
        } catch (const std::runtime_error &error) {
            assert(std::string(error.what()).find(expected) != std::string::npos);
            return;
        }
        throw std::runtime_error("invalid BTF manifest accepted");
    };
    rejects("requires source entry BTF");
    manifest(",\"source_btf_symbol\":\"\"", "");
    rejects("empty source_btf_symbol");
    manifest("", "");
    rejects("ambiguous entries");
    std::cout << "full BTF selector collision/missing/truncated/unknown/empty/ambiguous regressions: PASS\n";
}
