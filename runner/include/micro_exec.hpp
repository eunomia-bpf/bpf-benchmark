#ifndef MICRO_EXEC_HPP
#define MICRO_EXEC_HPP

#include <chrono>
#include <cstdint>
#include <filesystem>
#include <functional>
#include <optional>
#include <string>
#include <vector>

struct map_spec {
    uint32_t id = 0;
    std::string name;
    uint32_t type = 0;
    uint32_t key_size = 0;
    uint32_t value_size = 0;
    uint32_t max_entries = 0;
};

struct program_image {
    std::vector<uint8_t> code;
    std::vector<map_spec> maps;
    std::string program_name;
    std::string license;
    uint32_t prog_type = 0;
    uint32_t expected_attach_type = 0;
};

struct program_descriptor {
    std::string name;
    std::string section_name;
    uint64_t insn_count = 0;
    uint32_t prog_type = 0;
    uint32_t expected_attach_type = 0;
    std::string prog_type_name;
    std::string attach_type_name;
};

struct cli_options {
    std::string command;
    std::filesystem::path program;
    std::optional<std::filesystem::path> memory;
    std::optional<std::filesystem::path> btf_custom_path;
    bool rejit = false;                                 // enable REJIT (same-bytecode by default)
    std::optional<std::filesystem::path> rejit_program; // replacement ELF for REJIT
    std::optional<std::filesystem::path> daemon_path;   // --daemon-path <path> for daemon-based REJIT
    std::optional<std::string> program_name;
    std::string io_mode = "map";
    bool manual_load = false;
    bool raw_packet = false;
    uint32_t repeat = 1;
    uint32_t warmup_repeat = 5;
    uint32_t input_size = 0;
    int opt_level = 3;
    bool no_cmov = false;
    std::optional<std::string> llvm_target_cpu;
    std::optional<std::string> llvm_target_features;
    std::vector<std::string> disabled_passes;
    bool log_passes = false;
    bool perf_counters = false;
    std::string perf_scope = "full_repeat_raw";
    bool dump_jit = false;
    std::optional<std::filesystem::path> dump_xlated;
    bool compile_only = false;
};

struct timing_phase {
    std::string name;
    uint64_t ns = 0;
};

struct named_counter {
    std::string name;
    uint64_t value = 0;
};

struct perf_counter_options {
    bool enabled = false;
    bool include_kernel = false;
    std::string scope = "full_repeat_raw";
};

struct perf_counter_capture {
    bool requested = false;
    bool collected = false;
    bool include_kernel = false;
    std::string scope = "full_repeat_raw";
    std::string error;
    std::vector<named_counter> counters;
};

struct code_size_summary {
    uint64_t bpf_bytecode_bytes = 0;
    uint64_t native_code_bytes = 0;
};

struct rejit_summary {
    bool requested = false;
    std::string mode = "none";            // "same-bytecode" or "replacement"
    bool syscall_attempted = false;
    bool applied = false;
    uint32_t insn_cnt = 0;                // number of BPF insns sent to REJIT
    std::string error;
};

struct sample_result {
    std::optional<std::string> phase;
    uint64_t compile_ns = 0;
    uint64_t exec_ns = 0;
    std::string timing_source = "unknown";
    std::string timing_source_wall = "unavailable";
    std::optional<int> opt_level;
    bool no_cmov = false;
    std::optional<uint64_t> wall_exec_ns;
    std::optional<uint64_t> exec_cycles;
    std::optional<uint64_t> tsc_freq_hz;
    uint64_t result = 0;
    uint32_t retval = 0;
    std::optional<uint64_t> jited_prog_len;
    std::optional<uint64_t> xlated_prog_len;
    std::optional<uint64_t> native_code_size;
    std::optional<uint64_t> bpf_insn_count;
    code_size_summary code_size;
    std::vector<std::string> disabled_passes;
    std::vector<timing_phase> phases_ns;
    perf_counter_capture perf_counters;
    rejit_summary rejit;
};

[[noreturn]] void fail(const std::string &message);
cli_options parse_args(int argc, char **argv);
std::vector<uint8_t> read_binary_file(const std::filesystem::path &path);
void write_binary_file(const std::filesystem::path &path, const uint8_t *data, size_t size);
std::string benchmark_name_for_program(const std::filesystem::path &program);
std::vector<uint8_t> materialize_memory(const std::optional<std::filesystem::path> &memory, uint32_t size_hint);
std::vector<program_descriptor> list_programs(const std::filesystem::path &path);
program_image load_program_image(
    const std::filesystem::path &path,
    const std::optional<std::string> &program_name = std::nullopt);
sample_result run_llvmbpf(const cli_options &options);
std::vector<sample_result> run_kernel(const cli_options &options);
void print_json(const sample_result &sample);
void print_json(const std::vector<sample_result> &samples);
void print_program_inventory(const std::vector<program_descriptor> &programs);
perf_counter_capture measure_perf_counters(
    const perf_counter_options &options,
    const std::function<void()> &callback);

template <typename Clock, typename Duration>
inline uint64_t elapsed_ns(
    const std::chrono::time_point<Clock, Duration> &start,
    const std::chrono::time_point<Clock, Duration> &end)
{
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
}

#endif
