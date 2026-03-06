#include "micro_exec.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string_view>

namespace {

std::string json_escape(std::string_view input)
{
    std::string output;
    output.reserve(input.size());
    for (const char ch : input) {
        switch (ch) {
        case '\\':
            output += "\\\\";
            break;
        case '"':
            output += "\\\"";
            break;
        case '\n':
            output += "\\n";
            break;
        case '\r':
            output += "\\r";
            break;
        case '\t':
            output += "\\t";
            break;
        default:
            output += ch;
            break;
        }
    }
    return output;
}

} // namespace

[[noreturn]] void fail(const std::string &message)
{
    throw std::runtime_error(message);
}

std::vector<uint8_t> read_binary_file(const std::filesystem::path &path)
{
    std::ifstream stream(path, std::ios::binary | std::ios::ate);
    if (!stream.is_open()) {
        fail("unable to open file: " + path.string());
    }

    const auto size = stream.tellg();
    if (size < 0) {
        fail("unable to read file size: " + path.string());
    }

    std::vector<uint8_t> buffer(static_cast<size_t>(size));
    stream.seekg(0, std::ios::beg);
    if (!buffer.empty() && !stream.read(reinterpret_cast<char *>(buffer.data()), size)) {
        fail("unable to read file: " + path.string());
    }
    return buffer;
}

std::vector<uint8_t> materialize_memory(const std::optional<std::filesystem::path> &memory, uint32_t size_hint)
{
    if (!memory.has_value()) {
        return std::vector<uint8_t>(size_hint, 0);
    }

    auto bytes = read_binary_file(*memory);
    if (size_hint != 0 && bytes.size() < size_hint) {
        bytes.resize(size_hint, 0);
    }
    return bytes;
}

cli_options parse_args(int argc, char **argv)
{
    if (argc < 3) {
        fail(
            "usage: micro_exec <run-llvmbpf|run-kernel> --program <path> [--memory <path>] "
            "[--io-mode map|staged|packet] [--repeat N] [--input-size N]");
    }

    cli_options options;
    options.command = argv[1];

    for (int index = 2; index < argc; ++index) {
        const std::string_view current = argv[index];
        if (current == "--program" && index + 1 < argc) {
            options.program = argv[++index];
            continue;
        }
        if (current == "--memory" && index + 1 < argc) {
            options.memory = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--io-mode" && index + 1 < argc) {
            options.io_mode = argv[++index];
            continue;
        }
        if (current == "--repeat" && index + 1 < argc) {
            options.repeat = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if (current == "--input-size" && index + 1 < argc) {
            options.input_size = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if (current == "--perf-counters") {
            options.perf_counters = true;
            continue;
        }
        fail("unknown or incomplete argument: " + std::string(current));
    }

    if (options.program.empty()) {
        fail("--program is required");
    }
    if (options.io_mode != "map" && options.io_mode != "staged" && options.io_mode != "packet") {
        fail("--io-mode must be one of map, staged, or packet");
    }
    if (options.repeat == 0) {
        fail("--repeat must be >= 1");
    }
    return options;
}

void print_json(const sample_result &sample)
{
    std::cout
        << "{"
        << "\"compile_ns\":" << sample.compile_ns << ","
        << "\"exec_ns\":" << sample.exec_ns << ","
        << "\"result\":" << sample.result << ","
        << "\"retval\":" << sample.retval << ","
        << "\"phases_ns\":{";

    for (size_t index = 0; index < sample.phases_ns.size(); ++index) {
        if (index != 0) {
            std::cout << ",";
        }
        const auto &phase = sample.phases_ns[index];
        std::cout << "\"" << phase.name << "\":" << phase.ns;
    }

    std::cout
        << "},"
        << "\"perf_counters\":{";

    for (size_t index = 0; index < sample.perf_counters.counters.size(); ++index) {
        if (index != 0) {
            std::cout << ",";
        }
        const auto &counter = sample.perf_counters.counters[index];
        std::cout << "\"" << json_escape(counter.name) << "\":" << counter.value;
    }

    std::cout
        << "},"
        << "\"perf_counters_meta\":{"
        << "\"requested\":" << (sample.perf_counters.requested ? "true" : "false") << ","
        << "\"collected\":" << (sample.perf_counters.collected ? "true" : "false") << ","
        << "\"include_kernel\":" << (sample.perf_counters.include_kernel ? "true" : "false") << ","
        << "\"scope\":\"" << json_escape(sample.perf_counters.scope) << "\","
        << "\"error\":\"" << json_escape(sample.perf_counters.error) << "\""
        << "}"
        << "}\n";
}
