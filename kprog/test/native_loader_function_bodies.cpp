// Catch wrong original offsets, invented bodies and stale generated-code caches.
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

static void require(bool condition, const char *message)
{
    if (!condition) fail(message);
}

int main(int argc, char **argv)
{
    if (argc != 5) return 2;
    const std::filesystem::path input = argv[1], compiler = argv[2], kernel = argv[3], cache = argv[4];
    std::filesystem::create_directories(cache);
    std::unique_ptr<btf, decltype(&btf__free)> types(btf__new_empty(), btf__free);
    require(types != nullptr, "create function BTF");
    const int scalar = btf__add_int(types.get(), "word", 8, BTF_INT_SIGNED);
    require(scalar > 0, "add function scalar type");
    const int prototype = btf__add_func_proto(types.get(), scalar);
    require(prototype > 0, "add function prototype");
    // Actual generated CEL prototypes have empty Params even when the native
    // declaration has arguments. Names and source offsets determine the body.
    const std::vector<const char *> names = {"main", "supplied64", "supplied32", "supplied_i32",
                                            "supplied16", "supplied_ptr", "supplied_void", "not_in_native"};
    std::vector<bpf_func_info> functions;
    for (size_t i = 0; i < names.size(); ++i) {
        const int id = btf__add_func(types.get(), names[i], BTF_FUNC_STATIC, prototype);
        require(id > 0, "add source BTF function");
        functions.push_back({static_cast<uint32_t>(i * 2), static_cast<uint32_t>(id)});
    }
    std::vector<std::filesystem::path> outputs;
    for (const int32_t value : {0, -1}) {
        std::vector<bpf_insn> source;
        for (const auto *name : names) {
            bpf_insn mov{}, exit{};
            mov.code = (std::string(name) == "supplied32" || std::string(name) == "supplied_void")
                ? BPF_ALU | BPF_MOV | BPF_K : BPF_ALU64 | BPF_MOV | BPF_K;
            mov.imm = value; exit.code = BPF_JMP | BPF_EXIT;
            source.push_back(mov); source.push_back(exit);
        }
        const auto facts = native_function_body_facts(input, source, types.get(), functions);
        require(!facts.empty(), "captured functions were lost");
        require(facts.find("\"main\"") == std::string::npos, "defined native entry was replaced");
        require(facts.find("not_in_native") == std::string::npos, "unused BTF function was invented");
        require(facts.find("strtoull") == std::string::npos, "ordinary external became a BPF function");
        for (size_t i = 1; i + 1 < names.size(); ++i) {
            const auto body = json_required_string(facts.substr(facts.find('{', 1)), names[i]);
            require(body.size() == sizeof(bpf_insn) * 4, "wrong original function extent");
            auto expected = source[i * 2];
            const auto *bytes = reinterpret_cast<const uint8_t *>(&expected);
            constexpr char hex[] = "0123456789abcdef";
            for (size_t j = 0; j < sizeof(expected); ++j)
                require(body[j * 2] == hex[bytes[j] >> 4] && body[j * 2 + 1] == hex[bytes[j] & 15],
                        "function body used another offset or value");
        }
        const auto output = native_context_lto_object(input, "main", BPF_PROG_TYPE_KPROBE,
                                                     compiler, kernel, cache, facts);
        const auto timestamp = std::filesystem::last_write_time(output);
        const auto reused = native_context_lto_object(input, "main", BPF_PROG_TYPE_KPROBE,
                                                     compiler, kernel, cache, facts);
        require(reused == output && std::filesystem::last_write_time(reused) == timestamp,
                "unchanged original bodies rebuilt the native object");
        outputs.push_back(output);
        std::cout << value << ' ' << output.string() << '\n';
    }
    require(outputs[0] != outputs[1], "different original bodies reused stale native code");

    // A bytecode hash can be shared by loads with different metadata. The
    // program-specific filename prevents the second record overwriting the first.
    const auto source_path = cache / "same-bytecode.bpf";
    bpf_prog_info program{}; program.id = 71;
    require(native_source_function_bodies(input, source_path, program, {}).empty(),
            "absent capture metadata invented a body");
    const std::string first = "{\"version\":1,\"prog_id\":71,\"btf_id\":0,\"functions\":[]}";
    const std::string second = "{\"version\":1,\"prog_id\":73,\"btf_id\":0,\"functions\":[]}";
    write_binary_file(source_path.string() + ".functions.71.json",
                      reinterpret_cast<const uint8_t *>(first.data()), first.size());
    write_binary_file(source_path.string() + ".functions.72.json",
                      reinterpret_cast<const uint8_t *>(second.data()), second.size());
    require(native_source_function_bodies(input, source_path, program, {}).empty(), "first load metadata changed");
    program.id = 72;
    bool mismatch = false;
    try { native_source_function_bodies(input, source_path, program, {}); }
    catch (const std::runtime_error &error) {
        mismatch = std::string(error.what()).find("loaded program identity") != std::string::npos;
    }
    require(mismatch, "foreign load metadata was accepted");
    program.id = 71;
    require(native_source_function_bodies(input, source_path, program, {}).empty(), "second metadata overwrote first");
}
