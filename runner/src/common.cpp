#include "micro_exec.hpp"

#include <algorithm>
#include <cctype>
#include <cstdlib>
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

std::string trim(std::string_view input)
{
    size_t start = 0;
    while (start < input.size() &&
           std::isspace(static_cast<unsigned char>(input[start])) != 0) {
        ++start;
    }

    size_t end = input.size();
    while (end > start &&
           std::isspace(static_cast<unsigned char>(input[end - 1])) != 0) {
        --end;
    }

    return std::string(input.substr(start, end - start));
}

std::string lower_ascii(std::string_view input)
{
    std::string output(input);
    for (char &ch : output) {
        ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    }
    return output;
}

void print_json_string_array(std::ostream &out,
                             const std::vector<std::string> &values)
{
    out << "[";
    for (size_t index = 0; index < values.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        out << "\"" << json_escape(values[index]) << "\"";
    }
    out << "]";
}

std::string usage_text()
{
    return
        "usage: micro_exec <"
#if MICRO_EXEC_ENABLE_LLVMBPF
        "run-llvmbpf|"
#endif
        "run-kernel|list-programs> [--program <path>|<path>] [--program-name <name>] "
        "[--memory|--input <path>] [--btf-custom-path <path>] "
        "[--rejit] [--rejit-program <path>] [--daemon-path <path>] "
        "[--manual-load] "
        "[--io-mode map|staged|packet|context] [--raw-packet] [--repeat N] [--warmup N] [--input-size|--kernel-input-size N] "
        "[--opt-level 0|1|2|3] [--no-cmov] [--llvm-target-cpu <cpu>] [--llvm-target-features <csv>] [--llvm-disable-pass <name>] [--llvm-log-passes] "
        "[--perf-counters] [--perf-scope full_repeat_raw|full_repeat_avg] "
        "[--dump-jit] [--dump-xlated <path>] [--compile-only]";
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

void write_binary_file(const std::filesystem::path &path, const uint8_t *data, size_t size)
{
    std::ofstream stream(path, std::ios::binary | std::ios::trunc);
    if (!stream.is_open()) {
        fail("unable to open file for writing: " + path.string());
    }
    if (size != 0 && !stream.write(reinterpret_cast<const char *>(data), static_cast<std::streamsize>(size))) {
        fail("unable to write file: " + path.string());
    }
}

std::string benchmark_name_for_program(const std::filesystem::path &program)
{
    std::string name = program.filename().string();
    if (name.ends_with(".bpf.o")) {
        name.resize(name.size() - std::string(".bpf.o").size());
        return name;
    }
    if (name.ends_with(".o")) {
        name.resize(name.size() - std::string(".o").size());
        return name;
    }
    return program.stem().string();
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
    if (argc >= 2 &&
        (std::string_view(argv[1]) == "--help" ||
         std::string_view(argv[1]) == "-h")) {
        std::cout << usage_text() << "\n";
        std::exit(0);
    }
    if (argc < 3) {
        fail(usage_text());
    }

    cli_options options;
    options.command = argv[1];

    for (int index = 2; index < argc; ++index) {
        const std::string_view current = argv[index];
        if (current == "--help" || current == "-h") {
            std::cout << usage_text() << "\n";
            std::exit(0);
        }
        if ((current == "--program" || current == "--bpf-object" ||
             current == "--bpf-obj") && index + 1 < argc) {
            options.program = argv[++index];
            continue;
        }
        if (!current.empty() && current.front() != '-' && options.program.empty() &&
            options.command != "list-programs") {
            options.program = std::filesystem::path(current);
            continue;
        }
        if ((current == "--memory" || current == "--input") && index + 1 < argc) {
            options.memory = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--btf-custom-path" && index + 1 < argc) {
            options.btf_custom_path = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--rejit") {
            options.rejit = true;
            continue;
        }
        if (current == "--rejit-program" && index + 1 < argc) {
            options.rejit_program = std::filesystem::path(argv[++index]);
            options.rejit = true;
            continue;
        }
        if (current == "--daemon-path" && index + 1 < argc) {
            options.daemon_path = std::filesystem::path(argv[++index]);
            options.rejit = true;
            continue;
        }
        if (current == "--program-name" && index + 1 < argc) {
            options.program_name = std::string(argv[++index]);
            continue;
        }
        if (current == "--io-mode" && index + 1 < argc) {
            options.io_mode = argv[++index];
            continue;
        }
        if (current == "--manual-load") {
            options.manual_load = true;
            continue;
        }
        if (current == "--raw-packet") {
            options.raw_packet = true;
            continue;
        }
        if (current == "--repeat" && index + 1 < argc) {
            options.repeat = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if ((current == "--warmup" || current == "--warmups") && index + 1 < argc) {
            options.warmup_repeat = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if ((current == "--input-size" || current == "--kernel-input-size") &&
            index + 1 < argc) {
            options.input_size = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if (current == "--opt-level" && index + 1 < argc) {
            const int opt_level = std::stoi(argv[++index]);
            if (opt_level < 0 || opt_level > 3) {
                fail("--opt-level must be between 0 and 3");
            }
            options.opt_level = opt_level;
            continue;
        }
        if (current == "--no-cmov") {
            options.no_cmov = true;
            continue;
        }
        if (current == "--llvm-target-cpu" && index + 1 < argc) {
            options.llvm_target_cpu = std::string(argv[++index]);
            continue;
        }
        if (current == "--llvm-target-features" && index + 1 < argc) {
            options.llvm_target_features = std::string(argv[++index]);
            continue;
        }
        if (current == "--llvm-disable-pass" && index + 1 < argc) {
            options.disabled_passes.emplace_back(argv[++index]);
            continue;
        }
        if (current == "--llvm-log-passes") {
            options.log_passes = true;
            continue;
        }
        if (current == "--perf-counters") {
            options.perf_counters = true;
            continue;
        }
        if (current == "--perf-scope" && index + 1 < argc) {
            options.perf_scope = std::string(argv[++index]);
            continue;
        }
        if (current == "--dump-jit") {
            options.dump_jit = true;
            continue;
        }
        if (current == "--dump-xlated" && index + 1 < argc) {
            options.dump_xlated = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--compile-only") {
            options.compile_only = true;
            continue;
        }
        fail("unknown or incomplete argument: " + std::string(current));
    }

    if (options.program.empty()) {
        fail("--program is required");
    }
    const bool is_kernel_command = options.command == "run-kernel";
    if (options.perf_scope != "full_repeat_raw" && options.perf_scope != "full_repeat_avg") {
        fail("--perf-scope must be one of full_repeat_raw or full_repeat_avg");
    }
    if (options.manual_load && !is_kernel_command) {
        fail("--manual-load is only valid with run-kernel");
    }
    if (options.rejit && !is_kernel_command) {
        fail("--rejit is only valid with run-kernel");
    }
    if (options.command != "list-programs") {
        if (options.io_mode != "map" &&
            options.io_mode != "staged" &&
            options.io_mode != "packet" &&
            options.io_mode != "context") {
            fail("--io-mode must be one of map, staged, packet, or context");
        }
        if (!options.compile_only && options.repeat == 0) {
            fail("--repeat must be >= 1");
        }
    }
    return options;
}

void print_sample_json(std::ostream &out, const sample_result &sample)
{
    const double inflation_ratio = sample.code_size.bpf_bytecode_bytes == 0
        ? 0.0
        : static_cast<double>(sample.code_size.native_code_bytes) /
              static_cast<double>(sample.code_size.bpf_bytecode_bytes);

    out
        << "{"
        << "\"compile_ns\":" << sample.compile_ns << ","
        << "\"exec_ns\":" << sample.exec_ns;
    if (sample.phase.has_value()) {
        out << ",\"phase\":\"" << json_escape(*sample.phase) << "\"";
    }
    out
        << ",\"timing_source\":\"" << json_escape(sample.timing_source) << "\""
        << ",\"timing_source_wall\":\"" << json_escape(sample.timing_source_wall) << "\""
        << ",\"no_cmov\":" << (sample.no_cmov ? "true" : "false");

    if (sample.opt_level.has_value()) {
        out << ",\"opt_level\":" << *sample.opt_level;
    }
    out << ",\"disabled_passes\":[";
    for (size_t index = 0; index < sample.disabled_passes.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        out << "\"" << json_escape(sample.disabled_passes[index]) << "\"";
    }
    out << "]";

    out << ",\"wall_exec_ns\":";
    if (sample.wall_exec_ns.has_value()) {
        out << *sample.wall_exec_ns;
    } else {
        out << "null";
    }
    if (sample.exec_cycles.has_value()) {
        out << ",\"exec_cycles\":" << *sample.exec_cycles;
    }
    if (sample.tsc_freq_hz.has_value()) {
        out << ",\"tsc_freq_hz\":" << *sample.tsc_freq_hz;
    }

    out
        << ",\"result\":" << sample.result << ","
        << "\"retval\":" << sample.retval;

    if (sample.jited_prog_len.has_value()) {
        out << ",\"jited_prog_len\":" << *sample.jited_prog_len;
    }
    if (sample.xlated_prog_len.has_value()) {
        out << ",\"xlated_prog_len\":" << *sample.xlated_prog_len;
    }
    if (sample.native_code_size.has_value()) {
        out << ",\"native_code_size\":" << *sample.native_code_size;
    }
    if (sample.bpf_insn_count.has_value()) {
        out << ",\"bpf_insn_count\":" << *sample.bpf_insn_count;
    }

    out
        << ",\"code_size\":{"
        << "\"bpf_bytecode_bytes\":" << sample.code_size.bpf_bytecode_bytes << ","
        << "\"native_code_bytes\":" << sample.code_size.native_code_bytes << ","
        << "\"inflation_ratio\":" << inflation_ratio
        << "},"
        << "\"phases_ns\":{";

    for (size_t index = 0; index < sample.phases_ns.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        const auto &phase = sample.phases_ns[index];
        out << "\"" << phase.name << "\":" << phase.ns;
    }

    out
        << "},"
        << "\"perf_counters\":{";

    for (size_t index = 0; index < sample.perf_counters.counters.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        const auto &counter = sample.perf_counters.counters[index];
        out << "\"" << json_escape(counter.name) << "\":" << counter.value;
    }

    out
        << "},"
        << "\"perf_counters_meta\":{"
        << "\"requested\":" << (sample.perf_counters.requested ? "true" : "false") << ","
        << "\"collected\":" << (sample.perf_counters.collected ? "true" : "false") << ","
        << "\"include_kernel\":" << (sample.perf_counters.include_kernel ? "true" : "false") << ","
        << "\"scope\":\"" << json_escape(sample.perf_counters.scope) << "\","
        << "\"error\":\"" << json_escape(sample.perf_counters.error) << "\""
        << "},"
        << "\"rejit\":{"
        << "\"requested\":" << (sample.rejit.requested ? "true" : "false") << ","
        << "\"mode\":\"" << json_escape(sample.rejit.mode) << "\","
        << "\"syscall_attempted\":" << (sample.rejit.syscall_attempted ? "true" : "false") << ","
        << "\"applied\":" << (sample.rejit.applied ? "true" : "false") << ","
        << "\"insn_cnt\":" << sample.rejit.insn_cnt << ","
        << "\"error\":\"" << json_escape(sample.rejit.error) << "\""
        << "}"
        << "}";
}

void print_json(const sample_result &sample)
{
    print_sample_json(std::cout, sample);
    std::cout << "\n";
}

void print_json(const std::vector<sample_result> &samples)
{
    for (const auto &sample : samples) {
        print_json(sample);
    }
}

void print_program_inventory(const std::vector<program_descriptor> &programs)
{
    std::cout << "[";
    for (size_t index = 0; index < programs.size(); ++index) {
        if (index != 0) {
            std::cout << ",";
        }
        const auto &program = programs[index];
        std::cout
            << "{"
            << "\"name\":\"" << json_escape(program.name) << "\","
            << "\"section_name\":\"" << json_escape(program.section_name) << "\","
            << "\"insn_count\":" << program.insn_count << ","
            << "\"prog_type\":" << program.prog_type << ","
            << "\"expected_attach_type\":" << program.expected_attach_type << ","
            << "\"prog_type_name\":\"" << json_escape(program.prog_type_name) << "\","
            << "\"attach_type_name\":\"" << json_escape(program.attach_type_name) << "\""
            << "}";
    }
    std::cout << "]\n";
}
