#ifndef MICRO_EXEC_HPP
#define MICRO_EXEC_HPP

#include <chrono>
#include <cstdint>
#include <filesystem>
#include <functional>
#include <iosfwd>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
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
    std::optional<std::filesystem::path> fixture_path;
    std::optional<std::filesystem::path> btf_custom_path;
    bool rejit = false;                                 // enable REJIT (same-bytecode by default)
    std::optional<std::filesystem::path> rejit_program; // replacement ELF for REJIT
    std::optional<std::string> daemon_socket;             // --daemon-socket <path> for Unix socket daemon
    std::optional<std::string> program_name;
    std::optional<std::string> trigger_command;
    std::optional<uint32_t> trigger_timeout_seconds;
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
    bool attach_mode = false;                            // attach + bpf_stats measurement path
    uint32_t workload_iterations = 2;                    // syscall iterations, or duration seconds for mixed/stress-ng/fio/wrk
    std::string workload_type = "mixed";                 // workload: "mixed", "stress-ng", "fio", "wrk", or legacy syscall loops
};

struct keep_alive_request {
    std::string cmd;
    cli_options options;
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

struct daemon_pass_detail {
    std::string pass_name;
    bool changed = false;
    uint32_t sites_found = 0;
    uint32_t sites_applied = 0;
    uint32_t sites_skipped = 0;
    int64_t insns_before = 0;
    int64_t insns_after = 0;
    int64_t insn_delta = 0;
    std::string skip_reasons_json = "{}";
    std::string diagnostics_json = "[]";
};

struct rejit_summary {
    bool requested = false;
    std::string mode = "none";            // "same-bytecode", "replacement", or "daemon"
    bool syscall_attempted = false;
    bool applied = false;
    uint32_t insn_cnt = 0;                // number of BPF insns sent to REJIT
    std::string error;
    /* Extended fields from daemon transform trace (P1) */
    uint32_t total_sites_applied = 0;
    std::vector<std::string> passes_applied;   // pass names that changed the program
    int64_t insn_delta = 0;
    uint32_t verifier_retries = 0;
    std::vector<std::string> final_disabled_passes;
    std::vector<daemon_pass_detail> pass_details;
    std::string daemon_response;               // raw daemon JSON response
    bool daemon_debug_stripped = false;
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
    std::optional<bool> correctness_mismatch;
};

struct paired_test_run_result {
    std::string id;
    bool ok = false;
    std::string error;
    std::optional<sample_result> baseline_compile;
    std::optional<sample_result> baseline_run;
    std::optional<sample_result> rejit_compile;
    std::optional<sample_result> rejit_run;
};

struct prepared_kernel_state;
using prepared_kernel_handle = std::shared_ptr<prepared_kernel_state>;

[[noreturn]] void fail(const std::string &message);
cli_options parse_args(int argc, char **argv);
keep_alive_request parse_keep_alive_request(std::string_view json_line);
int run_batch_cli(int argc, char **argv);
std::vector<uint8_t> read_binary_file(const std::filesystem::path &path);
void write_binary_file(const std::filesystem::path &path, const uint8_t *data, size_t size);
std::string benchmark_name_for_program(const std::filesystem::path &program);
std::vector<uint8_t> materialize_memory(const std::optional<std::filesystem::path> &memory, uint32_t size_hint);
std::vector<program_descriptor> list_programs(const std::filesystem::path &path);
program_image load_program_image(
    const std::filesystem::path &path,
    const std::optional<std::string> &program_name = std::nullopt);
void initialize_micro_exec_process();
sample_result run_llvmbpf(const cli_options &options);
std::vector<sample_result> run_kernel(const cli_options &options);
std::vector<sample_result> run_kernel_attach(const cli_options &options);
prepared_kernel_handle prepare_kernel(const cli_options &options);
sample_result summarize_prepared_kernel_compile(const prepared_kernel_handle &prepared);
std::vector<sample_result> run_prepared_kernel(
    const prepared_kernel_handle &prepared,
    const cli_options &options);
paired_test_run_result run_kernel_paired(
    const cli_options &options,
    uint32_t pgo_warmup_repeat);
void print_json(std::ostream &out, const sample_result &sample);
void print_json(std::ostream &out, const std::vector<sample_result> &samples);
void print_json(const sample_result &sample);
void print_json(const std::vector<sample_result> &samples);
void print_program_listing(const std::vector<program_descriptor> &programs);
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
