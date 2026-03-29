#include "micro_exec.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace {

std::string usage_text()
{
    return
        "usage:\n"
        "  micro_exec test-run [--program <path>|<path>] [--program-name <name>] "
        "[--memory <path>] [--fixture-path <path>] [--btf-custom-path <path>] "
        "[--io-mode map|staged|packet|context] [--raw-packet] [--repeat N] "
        "[--warmup N] [--input-size N] [--perf-counters] "
        "[--perf-scope full_repeat_raw|full_repeat_avg] [--dump-jit] "
        "[--dump-xlated <path>]\n"
        "  micro_exec list-programs [--program <path>|<path>]";
}

void validate_cli_options(const cli_options &options)
{
    if (options.command != "test-run" && options.command != "list-programs") {
        fail("unsupported command: " + options.command);
    }
    if (options.program.empty()) {
        fail("--program is required");
    }
    if (options.perf_scope != "full_repeat_raw" &&
        options.perf_scope != "full_repeat_avg") {
        fail("--perf-scope must be one of full_repeat_raw or full_repeat_avg");
    }
    if (options.command == "test-run" && options.repeat == 0) {
        fail("--repeat must be >= 1");
    }
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
        << "\"error\":\"" << json_escape(sample.rejit.error) << "\","
        << "\"total_sites_applied\":" << sample.rejit.total_sites_applied << ","
        << "\"passes_applied\":";
    print_json_string_array(out, sample.rejit.passes_applied);
    out << ","
        << "\"insn_delta\":" << sample.rejit.insn_delta << ","
        << "\"verifier_retries\":" << sample.rejit.verifier_retries << ","
        << "\"final_disabled_passes\":";
    print_json_string_array(out, sample.rejit.final_disabled_passes);
    out << ",\"pass_details\":";
    print_json_daemon_pass_details(out, sample.rejit.pass_details);
    if (sample.rejit.daemon_debug_stripped) {
        out << ",\"daemon_debug_stripped\":true";
    }
    if (!sample.rejit.daemon_response.empty()) {
        out << ",\"daemon_response\":" << sample.rejit.daemon_response;
    }
    out << "}";
    if (sample.correctness_mismatch.has_value()) {
        out << ",\"correctness_mismatch\":"
            << (*sample.correctness_mismatch ? "true" : "false");
    }
    out << "}";
}

} // namespace

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

void print_json_string_array(std::ostream &out, const std::vector<std::string> &values)
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

void print_json_daemon_pass_details(
    std::ostream &out,
    const std::vector<daemon_pass_detail> &details)
{
    out << "[";
    for (size_t index = 0; index < details.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        const auto &detail = details[index];
        out
            << "{"
            << "\"pass_name\":\"" << json_escape(detail.pass_name) << "\","
            << "\"changed\":" << (detail.changed ? "true" : "false") << ","
            << "\"verify\":{"
            << "\"status\":\"" << json_escape(detail.verify_status) << "\"";
        if (!detail.verify_error_message.empty()) {
            out << ",\"error_message\":\"" << json_escape(detail.verify_error_message) << "\"";
        }
        out << "},"
            << "\"rollback\":";
        if (!detail.rollback_applied) {
            out << "null";
        } else {
            out
                << "{"
                << "\"action\":\"" << json_escape(detail.rollback_action) << "\","
                << "\"restored_insn_count\":" << detail.rollback_restored_insn_count
                << "}";
        }
        out
            << ","
            << "\"sites_found\":" << detail.sites_found << ","
            << "\"sites_applied\":" << detail.sites_applied << ","
            << "\"sites_skipped\":" << detail.sites_skipped << ","
            << "\"insns_before\":" << detail.insns_before << ","
            << "\"insns_after\":" << detail.insns_after << ","
            << "\"insn_delta\":" << detail.insn_delta << ","
            << "\"skip_reasons\":"
            << (detail.skip_reasons_json.empty() ? "{}" : detail.skip_reasons_json) << ","
            << "\"diagnostics\":"
            << (detail.diagnostics_json.empty() ? "[]" : detail.diagnostics_json)
            << "}";
    }
    out << "]";
}

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
    if (size != 0 &&
        !stream.write(
            reinterpret_cast<const char *>(data),
            static_cast<std::streamsize>(size))) {
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

std::vector<uint8_t> materialize_memory(
    const std::optional<std::filesystem::path> &memory,
    uint32_t size_hint)
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
    if (argc < 2) {
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
        if (current == "--program" && index + 1 < argc) {
            options.program = argv[++index];
            continue;
        }
        if (!current.empty() && current.front() != '-' && options.program.empty()) {
            options.program = std::filesystem::path(current);
            continue;
        }
        if (current == "--memory" && index + 1 < argc) {
            options.memory = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--fixture-path" && index + 1 < argc) {
            options.fixture_path = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--btf-custom-path" && index + 1 < argc) {
            options.btf_custom_path = std::filesystem::path(argv[++index]);
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
        if (current == "--raw-packet") {
            options.raw_packet = true;
            continue;
        }
        if (current == "--repeat" && index + 1 < argc) {
            options.repeat = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if (current == "--warmup" && index + 1 < argc) {
            options.warmup_repeat = static_cast<uint32_t>(std::stoul(argv[++index]));
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
        fail("unknown or incomplete argument: " + std::string(current));
    }

    validate_cli_options(options);
    return options;
}

void print_json(std::ostream &out, const sample_result &sample)
{
    print_sample_json(out, sample);
}

void print_json(std::ostream &out, const std::vector<sample_result> &samples)
{
    out << "[";
    for (size_t index = 0; index < samples.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        print_sample_json(out, samples[index]);
    }
    out << "]";
}

void print_json(const sample_result &sample)
{
    print_json(std::cout, sample);
    std::cout << "\n";
}

void print_json(const std::vector<sample_result> &samples)
{
    for (const auto &sample : samples) {
        print_json(sample);
    }
}

void print_program_listing(const std::vector<program_descriptor> &programs)
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
