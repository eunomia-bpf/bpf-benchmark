// Stock-load captured B with matching map shapes using production relocations.
// These fresh, empty maps establish verifier acceptance, not live app binding.
#include "../../libnativeloader/src/native_loader_trusted.cpp"
#include <iostream>

using namespace native_loader::trusted;

static int shape_map(const std::string &shape,
                     std::vector<std::unique_ptr<ScopedFd>> &pins)
{
    bpf_map_create_opts opts{}; opts.sz = sizeof(opts);
    opts.map_flags = json_required_u32(shape, "map_flags");
    if (auto inner = json_find_key_value(shape, "inner_map"))
        opts.inner_map_fd = shape_map(shape.substr(*inner, json_skip_value(shape, *inner)-*inner), pins);
    auto fd = std::make_unique<ScopedFd>(bpf_map_create(
        static_cast<bpf_map_type>(json_required_u32(shape, "map_type")), "archived_shape",
        json_required_u32(shape, "key_size"), json_required_u32(shape, "value_size"),
        json_required_u32(shape, "max_entries"), &opts));
    if (fd->get() < 0) fail("create archived map shape: " + std::string(std::strerror(errno)));
    const int result = fd->get(); pins.push_back(std::move(fd)); return result;
}

int main(int argc, char **argv)
try {
    if (argc != 5) fail("usage: archive-stock BPF_OBJECT METADATA FACTS VERIFIER_LOG");
    if (elf_version(EV_CURRENT) == EV_NONE) fail("initialize ELF");
    const auto metadata = read_text_file_required(argv[2]), facts = read_text_file_required(argv[3]);
    CompanionLoad companion{};
    std::vector<std::unique_ptr<ScopedFd>> pins;
    std::vector<native_loader::TrustedMapBinding> bindings;
    for (const auto &shape : json_array_objects(metadata, "maps")) {
        const int fd = shape_map(shape, pins);
        const auto map = load_map_info(fd);
        // Stock relocation needs identity and value extent, not native addresses.
        companion.maps.push_back(MapMeta{.kernel_id=map.id, .value_size=map.value_size});
        auto offset = json_find_key_value(shape, "value_offset");
        if (!offset) fail("missing archived map value_offset");
        const std::optional<uint64_t> value = shape.compare(*offset, 4, "null") == 0 ? std::nullopt :
            std::optional<uint64_t>(json_required_u32(shape, "value_offset"));
        bindings.push_back({json_required_string(shape, "name"), map.id, value});
    }
    ScopedFd unspecified(bpf_map_create(BPF_MAP_TYPE_ARRAY, "kprog_unspec", 4, 8, 1, nullptr));
    if (unspecified.get() < 0) fail("create unspecified input map");
    const auto unspecified_meta = load_map_info(unspecified.get());
    companion.maps.push_back(MapMeta{.kernel_id=unspecified_meta.id, .value_size=unspecified_meta.value_size});
    bindings.push_back({"kprog_unspecified_input", unspecified_meta.id, 0});
    using Object = std::unique_ptr<bpf_object, decltype(&bpf_object__close)>;
    Object object(bpf_object__open_file(argv[1], nullptr), bpf_object__close);
    if (!object || libbpf_get_error(object.get())) fail("open archived B");
    bpf_program *program = bpf_object__next_program(object.get(), nullptr);
    if (!program || bpf_object__next_program(object.get(), program)) fail("expected one archived B entry");
    std::vector<bpf_insn> proof(bpf_program__insns(program),
                              bpf_program__insns(program)+bpf_program__insn_cnt(program));
    std::vector<ProofSubprogram> subprograms;
    ScopedFd proof_btf(-1);
    relocate_trusted_proof(object.get(), argv[1], bpf_program__name(program), companion,
                           proof, pins, bindings, subprograms, proof_btf);
    std::vector<char> log(16 << 20);
    bpf_prog_load_opts opts{}; opts.sz = sizeof(opts);
    opts.log_buf = log.data(); opts.log_size = log.size(); opts.log_level = 1;
    std::vector<bpf_func_info> functions;
    if (subprograms.size() > 1) {
        for (const auto &subprogram : subprograms)
            functions.push_back({subprogram.start, subprogram.type_id});
        opts.prog_btf_fd = proof_btf.get();
        opts.func_info = functions.data(); opts.func_info_cnt = functions.size();
        opts.func_info_rec_size = sizeof(bpf_func_info);
    }
    opts.expected_attach_type = static_cast<bpf_attach_type>(json_required_u32(facts, "expected_attach_type"));
    opts.prog_flags = json_required_u32(facts, "prog_flags");
    opts.prog_ifindex = json_required_u32(facts, "prog_ifindex");
    if (json_required_u32(facts, "attach_prog_id"))
        fail("archived program attachment requires its live resource");
    opts.attach_btf_id = json_required_u32(facts, "attach_btf_id");
    if (const auto id = json_required_u32(facts, "attach_btf_obj_id")) {
        ScopedFd btf(bpf_btf_get_fd_by_id(id));
        char name[128]{};
        bpf_btf_info info{}; info.name = reinterpret_cast<uint64_t>(name);
        info.name_len = sizeof(name); uint32_t size = sizeof(info);
        if (btf.get() < 0 || bpf_obj_get_info_by_fd(btf.get(), &info, &size) ||
            !info.kernel_btf || std::strcmp(name, "vmlinux"))
            fail("archived BTF attachment requires its live module resource");
        // The diagnostic boots the identical kernel; vmlinux uses the default
        // BTF object. Module/program identities cannot be reconstructed here.
    }
    const auto type = static_cast<bpf_prog_type>(json_required_u32(facts, "prog_type"));
    ScopedFd loaded(bpf_prog_load(type, "archived_B", json_required_u32(facts, "gpl_compatible") ? "GPL" : "BSD",
                                proof.data(), proof.size(), &opts));
    const int load_errno = loaded.get() < 0 ? errno : 0;
    std::ofstream output(argv[4]); output << log.data(); output.close();
    if (!output) fail("write archived verifier log");
    std::cout << "{\"stock_loaded\":" << (loaded.get() >= 0 ? "true" : "false")
              << ",\"errno\":" << load_errno << ",\"instructions\":" << proof.size() << "}\n";
    return loaded.get() < 0 ? 2 : 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << '\n'; return 1;
}
