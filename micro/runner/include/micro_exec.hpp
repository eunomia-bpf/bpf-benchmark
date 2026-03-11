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
    std::optional<std::filesystem::path> directive_blob;
    std::optional<std::filesystem::path> policy_blob;    // v4 recompile policy
    bool recompile_cmov = false;                        // v4 auto-scan xlated for cmov
    bool recompile_wide = false;                        // v4 auto-scan xlated for wide_load
    bool recompile_rotate = false;                      // v4 auto-scan xlated for rotate
    bool recompile_rotate_rorx = false;                 // v4 rotate with RORX (BMI2)
    bool recompile_lea = false;                         // v4 auto-scan xlated for lea fusion
    bool recompile_extract = false;                     // v4 auto-scan xlated for bitfield extract
    bool recompile_all = false;                         // auto-scan for all pattern types
    bool recompile_v5 = false;                          // use v5 declarative pattern blob
    std::vector<std::string> skip_families;             // skip selected auto-scan families
    std::optional<std::string> program_name;
    std::string io_mode = "map";
    bool manual_load = false;
    bool raw_packet = false;
    uint32_t repeat = 1;
    uint32_t input_size = 0;
    int opt_level = 3;
    bool no_cmov = false;
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

struct directive_scan_summary {
    bool performed = false;
    uint64_t cmov_sites = 0;
    uint64_t wide_sites = 0;
    uint64_t rotate_sites = 0;
    uint64_t lea_sites = 0;
    uint64_t bitfield_sites = 0;
};

struct recompile_summary {
    bool requested = false;
    std::string mode = "none";
    std::vector<std::string> requested_families;
    std::vector<std::string> skipped_families;
    bool policy_generated = false;
    uint64_t policy_bytes = 0;
    bool syscall_attempted = false;
    bool applied = false;
    std::string error;
};

struct sample_result {
    uint64_t compile_ns = 0;
    uint64_t exec_ns = 0;
    std::string timing_source = "unknown";
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
    directive_scan_summary directive_scan;
    recompile_summary recompile;
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
sample_result run_kernel(const cli_options &options);
void print_json(const sample_result &sample);
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
