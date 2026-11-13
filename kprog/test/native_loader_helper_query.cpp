// Catch FD/type/ID wire-offset drift and losing unavailable targets in a batch.
#include "../libnativeloader/src/native_loader_helper_query.hpp"
#include "../libnativeloader/src/native_loader_manifest.hpp"
#include <cassert>
#include <cstddef>
#include <iostream>

int main(int argc, char **argv)
{
    assert(argc == 2);
    for (uint32_t id = 1; id < __BPF_FUNC_MAX_ID; ++id) {
        size_t matches = 0;
        for (const auto &helper : kCanonicalHelperIdentities)
            matches += helper.id == id;
        assert(matches == 1);
    }
    for (const auto &[id, name] : {NativeHelperIdentity{BPF_FUNC_fib_lookup, "bpf_fib_lookup"},
                                  NativeHelperIdentity{BPF_FUNC_skc_lookup_tcp, "bpf_skc_lookup_tcp"},
                                  NativeHelperIdentity{BPF_FUNC_probe_read, "bpf_probe_read"}}) {
        bool found = false;
        for (const auto &helper : kCanonicalHelperIdentities)
            found |= helper.id == id && std::strcmp(helper.name, name) == 0;
        assert(found);
    }
    static_assert(offsetof(native_lab_helper_query, verifier_ops) == 0);
    static_assert(offsetof(native_lab_helper_query, program_fd) == 8);
    static_assert(offsetof(native_lab_helper_query, program_type) == 12);
    const auto request = encode_helper_query(0x123456789abcdef0ULL, 37, 18, {25, 122, 46});
    assert(request.size() == 28);
    uint64_t address;
    uint32_t fd, type, ids[3];
    std::memcpy(&address, request.data(), 8);
    std::memcpy(&fd, request.data() + 8, 4);
    std::memcpy(&type, request.data() + 12, 4);
    std::memcpy(ids, request.data() + 16, 12);
    assert(address == 0x123456789abcdef0ULL && fd == 37 && type == 18);
    assert(ids[0] == 25 && ids[1] == 122 && ids[2] == 46);
    const uint64_t values[] = {0xffff123456789abcULL, 0, 0xffff876543210000ULL};
    std::vector<uint8_t> reply(sizeof(values));
    std::memcpy(reply.data(), values, sizeof(values));
    const auto targets = decode_helper_targets(reply, 3);
    assert(targets[0] == values[0] && targets[1] == 0 && targets[2] == values[2]);
    reply.pop_back();
    bool rejected = false;
    try { decode_helper_targets(reply, 3); }
    catch (const std::runtime_error &) { rejected = true; }
    assert(rejected);

    const auto path = std::filesystem::path(argv[1]) / "helper-manifest.json";
    std::ofstream object(path.parent_path() / "entry.o");
    object.close();
    assert(object);
    bpf_prog_info info{};
    info.type = BPF_PROG_TYPE_XDP;
    std::strcpy(info.name, "entry");
    const std::vector<bpf_insn> insns(1);
    const auto map_info = [](int) -> bpf_map_info { throw std::runtime_error("unexpected map"); };
    for (const auto &setting : {std::string(""), std::string(",\"kernel_helper_context\":false"),
                                std::string(",\"kernel_helper_context\":true")}) {
        std::ofstream out(path);
        out << "{\"objects\":[{\"program\":\"entry\",\"native_object\":\"entry.o\"" << setting << "}]}";
        out.close();
        assert(out);
        const auto result = resolve_native_manifest(path, info, insns, map_info);
        assert(result && result->kernel_helper_context == (setting.find("true") != std::string::npos));
    }
    std::cout << "helper UAPI identities, FD/type/IDs, target order/zero/short reply, default-off manifest: PASS\n";
}
