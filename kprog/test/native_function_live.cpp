// Exercise original function metadata against live kernel BTF, not saved facts.
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

static int checked(int value, const char *operation)
{
    if (value < 0) fail(std::string(operation) + ": " + std::strerror(-value));
    return value;
}

int main(int argc, char **argv)
{
    if (argc != 5) return 2;
    const std::filesystem::path input = argv[1], compiler = argv[2], directory = argv[3], result = argv[4];
    std::unique_ptr<btf, decltype(&btf__free)> types(btf__new_empty(), btf__free);
    if (!types) fail("create live function BTF");
    const int word = checked(btf__add_int(types.get(), "word", 8, 0), "add word type");
    const int opaque = checked(btf__add_struct(types.get(), "context", 0), "add context type");
    const int pointer = checked(btf__add_ptr(types.get(), opaque), "add context pointer");
    const int entry_proto = checked(btf__add_func_proto(types.get(), word), "add entry prototype");
    checked(btf__add_func_param(types.get(), "ctx", pointer), "add entry argument");
    const int entry_type = checked(btf__add_func(types.get(), "function_entry", BTF_FUNC_GLOBAL, entry_proto), "add entry function");
    const int callee_proto = checked(btf__add_func_proto(types.get(), word), "add callee prototype");
    // Empty Params matches actual generated CEL BTF. Native C still has its
    // own two-argument declaration; no argument count is inferred from BTF.
    const int callee_type = checked(btf__add_func(types.get(), "captured_function", BTF_FUNC_STATIC, callee_proto), "add callee function");
    checked(btf__load_into_kernel(types.get()), "load original function BTF");
    std::vector<bpf_insn> source(6);
    source[0].code = BPF_ALU64 | BPF_MOV | BPF_K; source[0].dst_reg = BPF_REG_1; source[0].imm = 6;
    source[1].code = BPF_ALU64 | BPF_MOV | BPF_K; source[1].dst_reg = BPF_REG_2; source[1].imm = 7;
    source[2].code = BPF_JMP | BPF_CALL; source[2].src_reg = BPF_PSEUDO_CALL; source[2].imm = 1;
    source[3].code = BPF_JMP | BPF_EXIT;
    source[4].code = BPF_ALU64 | BPF_MOV | BPF_K; source[4].imm = 9;
    source[5].code = BPF_JMP | BPF_EXIT;
    const bpf_func_info functions[] = {{0, static_cast<uint32_t>(entry_type)}, {4, static_cast<uint32_t>(callee_type)}};
    std::vector<char> log(1024 * 1024);
    bpf_prog_load_opts options{}; options.sz = sizeof(options);
    options.prog_btf_fd = btf__fd(types.get());
    options.func_info = functions; options.func_info_cnt = 2; options.func_info_rec_size = sizeof(bpf_func_info);
    options.log_buf = log.data(); options.log_size = log.size(); options.log_level = 1;
    ScopedFd program(bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER, "function_entry", "GPL", source.data(), source.size(), &options));
    if (program.get() < 0) fail("load live function program: " + std::string(log.data()));
    const auto info = load_prog_info(program.get());
    const auto source_path = directory / "original.bpf";
    write_binary_file(source_path, reinterpret_cast<const uint8_t *>(source.data()), source.size() * sizeof(bpf_insn));
    const std::string metadata = "{\"version\":1,\"prog_id\":" + std::to_string(info.id) +
        ",\"btf_id\":" + std::to_string(info.btf_id) + ",\"functions\":[{\"insn_off\":0,\"type_id\":" +
        std::to_string(entry_type) + "},{\"insn_off\":4,\"type_id\":" + std::to_string(callee_type) + "}]}\n";
    write_binary_file(source_path.string() + ".functions." + std::to_string(info.id) + ".json",
                      reinterpret_cast<const uint8_t *>(metadata.data()), metadata.size());
    const auto facts = native_source_function_bodies(input, source_path, info, source);
    if (facts != "{\"functions\":{\"captured_function\":\"b7000000090000009500000000000000\"}}\n")
        fail("live original BTF/offsets selected the wrong function body");
    uint8_t packet[64]{};
    bpf_test_run_opts run{}; run.sz = sizeof(run); run.data_in = packet; run.data_size_in = sizeof(packet);
    checked(bpf_prog_test_run_opts(program.get(), &run), "execute original BPF");
    if (run.retval != 9) fail("original BPF body did not execute the supplied constant");
    const auto output = native_context_lto_object(input, "function_entry", info.type,
                                                 compiler, "/sys/kernel/btf/vmlinux", directory / "cache", facts);
    const auto path = output.string() + '\n';
    write_binary_file(result, reinterpret_cast<const uint8_t *>(path.data()), path.size());
    std::cout << "{\"prog_id\":" << info.id << ",\"btf_id\":" << info.btf_id
              << ",\"bpf_result\":" << run.retval << ",\"source_function_offset\":4}\n";
}
