/* Use the production ELF relocation/input-map binding before stock loading. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

static void check(const std::filesystem::path &path, const char *entry,
                  const std::filesystem::path &log_path)
{
    std::unique_ptr<bpf_object, decltype(&bpf_object__close)> object(
        bpf_object__open_file(path.c_str(), nullptr), bpf_object__close);
    if (!object || libbpf_get_error(object.get())) fail("open stock fixture: " + path.string());
    auto *program = bpf_object__find_program_by_name(object.get(), entry);
    if (!program || bpf_program__type(program) != BPF_PROG_TYPE_KPROBE)
        fail("stock fixture lacks KPROBE entry: " + std::string(entry));
    ScopedFd input(bpf_map_create(BPF_MAP_TYPE_ARRAY, "scheduled_input", 4, 8, 1, nullptr));
    if (input.get() < 0) fail("create private input map");
    const auto input_info = load_map_info(input.get());
    MapMeta meta{}; meta.kernel_id=input_info.id; meta.value_size=input_info.value_size;
    CompanionLoad companion; companion.prog_type=BPF_PROG_TYPE_KPROBE;
    companion.maps.push_back(meta);
    std::vector<bpf_insn> instructions(bpf_program__insns(program),
        bpf_program__insns(program)+bpf_program__insn_cnt(program));
    std::vector<std::unique_ptr<ScopedFd>> pins;
    relocate_trusted_proof(object.get(), path, entry, companion, instructions, pins,
        {{"kprog_unspecified_input", input_info.id, 0}});
    std::vector<char> log(1U<<20);
    bpf_prog_load_opts options{};
    options.sz=sizeof(options);options.log_buf=log.data();options.log_size=log.size();options.log_level=2;
    ScopedFd loaded(bpf_prog_load(BPF_PROG_TYPE_KPROBE, "scheduled_model", "GPL",
        instructions.data(), instructions.size(), &options));
    std::ofstream diagnostic(log_path);
    diagnostic << log.data(); diagnostic.close();
    if (!diagnostic) fail("write stock verifier log");
    if (loaded.get() < 0) fail("stock fixture rejected: " + std::string(log.data()));
    const auto info=load_prog_info(loaded.get());
    std::cout << "{\"entry\":\"" << entry << "\",\"id\":" << info.id
        << ",\"type\":" << info.type << ",\"bytes_jited\":" << info.jited_prog_len
        << ",\"bytes_xlated\":" << info.xlated_prog_len
        << ",\"private_input_map_id\":" << input_info.id << ",\"stock_accepted\":true}\n";
}

int main(int argc, char **argv)
try {
    if (argc != 5 && argc != 7) fail("usage: scheduled-stock ORIGINAL B ORIGINAL_LOG B_LOG [ORIGINAL_ENTRY B_ENTRY]");
    check(argv[1], argc == 7 ? argv[5] : "scheduled_table", argv[3]);
    check(argv[2], argc == 7 ? argv[6] : "trusted_x86_x86_sim_xdp", argv[4]);
    return 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
}
