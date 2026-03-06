#ifndef MICRO_EXEC_HPP
#define MICRO_EXEC_HPP

#include <cstdint>
#include <filesystem>
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
    uint32_t repeat = 1;
    uint32_t input_size = 0;
};

struct sample_result {
    uint64_t compile_ns = 0;
    uint64_t exec_ns = 0;
    uint64_t result = 0;
    uint32_t retval = 0;
};

[[noreturn]] void fail(const std::string &message);
cli_options parse_args(int argc, char **argv);
std::vector<uint8_t> read_binary_file(const std::filesystem::path &path);
std::vector<uint8_t> materialize_memory(const std::optional<std::filesystem::path> &memory, uint32_t size_hint);
program_image load_program_image(const std::filesystem::path &path);
sample_result run_llvmbpf(const cli_options &options);
sample_result run_kernel(const cli_options &options);
void print_json(const sample_result &sample);

#endif
