#pragma once

// The selected P carries its own frontend IR. Context conversion happens here,
// after current data binding and before final ABI proof and helper/map LTO.
std::filesystem::path native_context_lto_object(
    const std::filesystem::path &input, const std::string &symbol, uint32_t prog_type,
    const std::filesystem::path &compiler = "/opt/bpf-benchmark/native-bpf/x86_64/kprog-perf-context-lto",
    const std::filesystem::path &kernel_btf = "/sys/kernel/btf/vmlinux",
    const std::filesystem::path &directory = kNativeLinkCacheDir,
    const std::string &function_bodies = {}, const std::string &immutable_globals = {},
    const std::string &map_types = {})
{
    if (prog_type != BPF_PROG_TYPE_PERF_EVENT && prog_type != BPF_PROG_TYPE_XDP &&
        function_bodies.empty() &&
        immutable_globals.empty() && map_types.empty()) return input;
    Hash64 hash;
    hash.add_string("perf-context-lto-v3");
    hash_file_contents(hash, input, "native_elf");
    hash_file_contents(hash, kernel_btf, "boot_kernel_btf");
    hash_file_identity(hash, compiler, "context_lto_compiler");
    hash.add_string(symbol);
    hash.add_u64(prog_type);
    hash.add_string(immutable_globals);
    hash.add_string(map_types);
    if (!function_bodies.empty()) {
        hash.add_string("original-bpf-function-bodies-v1");
        hash.add_string(function_bodies);
        const auto callee_compiler = compiler.parent_path() / "kprog-bpf-callee-ir";
        std::error_code callee_error;
        const bool present = std::filesystem::exists(callee_compiler, callee_error);
        if (callee_error) fail("read BPF callee compiler identity: " + callee_error.message());
        hash.add_u64(present);
        if (present) hash_file_identity(hash, callee_compiler, "bpf_callee_ir_compiler");
    }
    std::error_code ec;
    std::filesystem::create_directories(directory, ec);
    if (ec) fail("create context LTO cache: " + ec.message());
    const auto output = directory / (hash.hex() + ".perf.native.o");
    const bool exists = std::filesystem::exists(output, ec);
    if (ec) fail("read context LTO cache: " + ec.message());
    if (exists) return output;
    const auto temporary = output.string() + ".tmp." + std::to_string(getpid());
    const auto log = temporary + ".stderr.txt";
    // Re-emission must retain vendor/bpf/Makefile's common x86 backend policy.
    std::vector<std::string> argv = {compiler.string(), "--x86-cmov-converter-force-all", input.string(),
        "--symbol", symbol, "--kernel-btf", kernel_btf.string(),
        "--prog-type", std::to_string(prog_type), "-o", temporary};
    if (!immutable_globals.empty()) {
        const auto facts = temporary + ".immutable.json";
        write_binary_file(facts, reinterpret_cast<const uint8_t *>(immutable_globals.data()), immutable_globals.size());
        argv.insert(argv.end(), {"--immutable-globals", facts});
    }
    if (!map_types.empty()) {
        const auto facts = temporary + ".map-types.json";
        write_binary_file(facts, reinterpret_cast<const uint8_t *>(map_types.data()), map_types.size());
        argv.insert(argv.end(), {"--map-types", facts});
    }
    if (!function_bodies.empty()) {
        const auto facts = temporary + ".functions.json";
        write_binary_file(facts, reinterpret_cast<const uint8_t *>(function_bodies.data()), function_bodies.size());
        argv.insert(argv.end(), {"--bpf-function-bodies", facts});
    }
    const int rc = native_loader_detail::run_subprocess(argv, log);
    const int saved_errno = errno;
    if (rc != 0) {
        std::ostringstream message;
        message << "native context/function LTO failed (rc=" << rc << ")";
        if (rc < 0) message << ": " << std::strerror(saved_errno);
        message << '\n' << read_text_file_limited(log, 4096);
        fail(message.str());
    }
    publish_cache_file(temporary, output);
    return output;
}
