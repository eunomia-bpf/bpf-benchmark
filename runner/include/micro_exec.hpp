#ifndef MICRO_EXEC_HPP
#define MICRO_EXEC_HPP

#include <chrono>
#include <cstdint>
#include <filesystem>
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

struct kinsn_call_relocation {
    uint64_t insn_index = 0;
    std::string name;
};

struct program_image {
    std::vector<uint8_t> code;
    std::vector<map_spec> maps;
    std::vector<kinsn_call_relocation> kinsn_calls;
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
    std::optional<std::filesystem::path> native_program;
    std::optional<std::filesystem::path> memory;
    std::optional<std::filesystem::path> fixture_path;
    std::optional<std::filesystem::path> btf_custom_path;
    std::string io_mode = "map";
    bool raw_packet = false;
    uint32_t repeat = 1;
    uint32_t warmup_repeat = 5;
    uint32_t input_size = 0;
    bool dump_jit = false;
    std::optional<std::filesystem::path> dump_jit_path;
    std::optional<std::filesystem::path> dump_xlated;
    bool wait_signal = false;
    /* native_kernel-only: xdp | sched_cls | cgroup_skb. Defaults to xdp. */
    std::string native_kernel_prog_type = "xdp";
    /* Override the path of the native-link binary. */
    std::string native_kernel_linker_path;
};

struct timing_phase {
    std::string name;
    uint64_t ns = 0;
};

struct code_size_summary {
    uint64_t bpf_bytecode_bytes = 0;
    uint64_t native_code_bytes = 0;
};

struct sample_result {
    uint64_t compile_ns = 0;
    uint64_t exec_ns = 0;
    std::string timing_source = "unknown";
    std::string timing_source_wall = "unavailable";
    std::optional<uint64_t> wall_exec_ns;
    std::optional<uint64_t> exec_cycles;
    std::optional<uint64_t> tsc_freq_hz;
    uint64_t result = 0;
    uint32_t retval = 0;
    std::optional<uint64_t> jited_prog_len;
    std::optional<uint64_t> xlated_prog_len;
    code_size_summary code_size;
    std::vector<timing_phase> phases_ns;
};

[[noreturn]] void fail(const std::string &message);
cli_options parse_args(int argc, char **argv);
std::vector<uint8_t> read_binary_file(const std::filesystem::path &path);
void write_binary_file(const std::filesystem::path &path, const uint8_t *data, size_t size);
std::string benchmark_name_for_program(const std::filesystem::path &program);
std::vector<uint8_t> materialize_memory(const std::optional<std::filesystem::path> &memory, uint32_t size_hint);
std::vector<program_descriptor> list_programs(const std::filesystem::path &path);
program_image load_program_image(const std::filesystem::path &path);
std::vector<sample_result> run_kernel(const cli_options &options);
sample_result run_llvmbpf(const cli_options &options);
sample_result run_native(const cli_options &options);
std::vector<sample_result> run_native_kernel(const cli_options &options);
void print_json(std::ostream &out, const sample_result &sample);
void print_json(std::ostream &out, const std::vector<sample_result> &samples);
void print_json(const sample_result &sample);
void print_json(const std::vector<sample_result> &samples);
void print_program_listing(const std::vector<program_descriptor> &programs);
std::string json_escape(std::string_view input);

template <typename Clock, typename Duration>
inline uint64_t elapsed_ns(
    const std::chrono::time_point<Clock, Duration> &start,
    const std::chrono::time_point<Clock, Duration> &end)
{
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
}

#endif
