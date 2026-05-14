#include "micro_exec.hpp"
#include <chrono>
#include <cstring>
#include <dlfcn.h>
namespace { using clock_type = std::chrono::steady_clock; using native_prog_fn = int (*)(void *);
constexpr size_t kEthernetHeaderSize = 14; struct native_xdp_md { uintptr_t data, data_end; };
struct native_skb { uintptr_t data, data_end; uint32_t cb[5]; }; }
sample_result run_native(const cli_options &options) {
    const auto memory_start = clock_type::now(); auto input = materialize_memory(options.memory, options.input_size);
    const auto memory_end = clock_type::now(); auto so = options.program; const auto file = so.filename().string();
    if (file.ends_with(".bpf.o")) so.replace_filename(file.substr(0, file.size() - 6) + ".native.so");
    else so.replace_extension(".native.so");
    const auto load_start = clock_type::now();
    void *handle = dlopen(so.c_str(), RTLD_NOW | RTLD_LOCAL); if (handle == nullptr) fail("dlopen failed for " + so.string() + ": " + dlerror());
    const std::string symbol = options.program_name.value_or(benchmark_name_for_program(options.program) + "_xdp");
    dlerror();
    auto *fn = reinterpret_cast<native_prog_fn>(dlsym(handle, symbol.c_str())); const char *sym_error = dlerror();
    if (sym_error != nullptr) fail("dlsym failed for " + symbol + ": " + sym_error);
    const auto load_end = clock_type::now();
    const bool is_skb = symbol.ends_with("_prog"); const size_t offset = is_skb && symbol.starts_with("cgroup_") ? kEthernetHeaderSize : 0;
    std::vector<uint8_t> packet(offset + sizeof(uint64_t) + input.size(), 0);
    std::memcpy(packet.data() + offset + sizeof(uint64_t), input.data(), input.size());
    native_skb skb {}; native_xdp_md xdp {}; auto *data = packet.data() + offset;
    skb.data = xdp.data = reinterpret_cast<uintptr_t>(data);
    skb.data_end = xdp.data_end = reinterpret_cast<uintptr_t>(packet.data() + packet.size());
    uint32_t retval = 0; const uint32_t repeat = options.repeat > 0 ? options.repeat : 1;
    const perf_counter_options perf_options {.enabled = options.perf_counters, .include_kernel = false, .scope = options.perf_scope};
    const auto exec_start = clock_type::now();
    auto perf = measure_perf_counters(perf_options, [&]() {
        for (uint32_t index = 0; index < repeat; ++index)
            retval = static_cast<uint32_t>(fn(is_skb ? static_cast<void *>(&skb) : static_cast<void *>(&xdp)));
    });
    const auto exec_end = clock_type::now();
    uint64_t packet_result = 0; std::memcpy(&packet_result, data, sizeof(packet_result));
    sample_result sample {.compile_ns = elapsed_ns(load_start, load_end), .exec_ns = elapsed_ns(exec_start, exec_end) / repeat};
    sample.timing_source = "clock_monotonic"; sample.timing_source_wall = "clock_monotonic"; sample.wall_exec_ns = sample.exec_ns;
    sample.result = is_skb ? (static_cast<uint64_t>(skb.cb[0]) | (static_cast<uint64_t>(skb.cb[1]) << 32)) : packet_result;
    sample.retval = retval; sample.code_size = {.bpf_bytecode_bytes = 0, .native_code_bytes = std::filesystem::file_size(so)};
    sample.phases_ns = {{"memory_prepare_ns", elapsed_ns(memory_start, memory_end)}, {"native_load_ns", sample.compile_ns}};
    sample.perf_counters = perf;
    dlclose(handle); return sample;
}
