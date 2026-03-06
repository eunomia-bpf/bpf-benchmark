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
    uint32_t key_size = 0;
    uint32_t value_size = 0;
    uint32_t max_entries = 0;
};

struct program_image {
    std::vector<uint8_t> code;
    std::vector<map_spec> maps;
};

struct cli_options {
    std::string command;
    std::filesystem::path program;
    std::optional<std::filesystem::path> memory;
    std::string io_mode = "map";
    uint32_t repeat = 1;
    uint32_t input_size = 0;
    bool perf_counters = false;
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
    std::string scope = "exec_window";
};

struct perf_counter_capture {
    bool requested = false;
    bool collected = false;
    bool include_kernel = false;
    std::string scope = "exec_window";
    std::string error;
    std::vector<named_counter> counters;
};

struct sample_result {
    uint64_t compile_ns = 0;
    uint64_t exec_ns = 0;
    uint64_t result = 0;
    uint32_t retval = 0;
    std::vector<timing_phase> phases_ns;
    perf_counter_capture perf_counters;
};

[[noreturn]] void fail(const std::string &message);
cli_options parse_args(int argc, char **argv);
std::vector<uint8_t> read_binary_file(const std::filesystem::path &path);
std::vector<uint8_t> materialize_memory(const std::optional<std::filesystem::path> &memory, uint32_t size_hint);
program_image load_program_image(const std::filesystem::path &path);
sample_result run_llvmbpf(const cli_options &options);
sample_result run_kernel(const cli_options &options);
void print_json(const sample_result &sample);
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
