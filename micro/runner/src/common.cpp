#include "micro_exec.hpp"

#include <algorithm>
#include <cctype>
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

std::optional<std::string> canonical_skip_family_name(std::string_view input)
{
    std::string normalized = lower_ascii(trim(input));
    std::replace(normalized.begin(), normalized.end(), '_', '-');

    if (normalized == "cmov" || normalized == "cond-select") {
        return std::string("cmov");
    }
    if (normalized == "wide" || normalized == "wide-mem" ||
        normalized == "wide-load") {
        return std::string("wide");
    }
    if (normalized == "rotate") {
        return std::string("rotate");
    }
    if (normalized == "lea" || normalized == "addr-calc" ||
        normalized == "addrcalc") {
        return std::string("lea");
    }
    if (normalized == "extract" || normalized == "bitfield" ||
        normalized == "bitfield-extract" || normalized == "bit-extract") {
        return std::string("extract");
    }
    return std::nullopt;
}

void append_unique(std::vector<std::string> &values, std::string value)
{
    if (std::find(values.begin(), values.end(), value) == values.end()) {
        values.push_back(std::move(value));
    }
}

void append_skip_families(std::vector<std::string> &families,
                          std::string_view value)
{
    size_t start = 0;
    while (start <= value.size()) {
        const size_t comma = value.find(',', start);
        const std::string token =
            trim(value.substr(start, comma == std::string_view::npos
                                         ? std::string_view::npos
                                         : comma - start));
        if (!token.empty()) {
            const auto normalized = canonical_skip_family_name(token);
            if (!normalized.has_value()) {
                fail("unknown family in --skip-families: " + token +
                     " (expected cmov, wide, rotate, lea, or extract)");
            }
            append_unique(families, *normalized);
        }

        if (comma == std::string_view::npos) {
            break;
        }
        start = comma + 1;
    }
}

void print_json_string_array(const std::vector<std::string> &values)
{
    std::cout << "[";
    for (size_t index = 0; index < values.size(); ++index) {
        if (index != 0) {
            std::cout << ",";
        }
        std::cout << "\"" << json_escape(values[index]) << "\"";
    }
    std::cout << "]";
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
    if (argc < 3) {
        fail(
            "usage: micro_exec <run-llvmbpf|run-kernel|list-programs> [--program <path>|<path>] [--program-name <name>] "
            "[--memory|--input <path>] [--btf-custom-path <path>] [--directive-blob <path>] [--policy-blob <path>] "
            "[--manual-load] [--recompile-cmov] [--recompile-wide|--recompile-wide-mem] [--recompile-rotate] [--recompile-rotate-rorx] [--recompile-lea] [--recompile-extract|--recompile-bitfield-extract] [--recompile-all] [--recompile-v5] [--skip-families cmov,wide,rotate,lea,extract] "
            "[--io-mode map|staged|packet|context] [--raw-packet] [--repeat N] [--warmup N] [--input-size|--kernel-input-size N] "
            "[--opt-level 0|1|2|3] [--no-cmov] [--llvm-disable-pass <name>] [--llvm-log-passes] "
            "[--perf-counters] [--perf-scope full_repeat_raw|full_repeat_avg] "
            "[--dump-jit] [--dump-xlated <path>] [--compile-only]");
    }

    cli_options options;
    options.command = argv[1];

    for (int index = 2; index < argc; ++index) {
        const std::string_view current = argv[index];
        if ((current == "--program" || current == "--bpf-object") && index + 1 < argc) {
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
        if (current == "--directive-blob" && index + 1 < argc) {
            options.directive_blob = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--policy-blob" && index + 1 < argc) {
            options.policy_blob = std::filesystem::path(argv[++index]);
            continue;
        }
        if (current == "--recompile-cmov") {
            options.recompile_cmov = true;
            continue;
        }
        if (current == "--recompile-wide" || current == "--recompile-wide-mem") {
            options.recompile_wide = true;
            continue;
        }
        if (current == "--recompile-rotate") {
            options.recompile_rotate = true;
            continue;
        }
        if (current == "--recompile-rotate-rorx") {
            options.recompile_rotate_rorx = true;
            continue;
        }
        if (current == "--recompile-lea") {
            options.recompile_lea = true;
            continue;
        }
        if (current == "--recompile-extract" ||
            current == "--recompile-bitfield-extract") {
            options.recompile_extract = true;
            continue;
        }
        if (current == "--recompile-all") {
            options.recompile_all = true;
            continue;
        }
        if (current == "--recompile-v5") {
            options.recompile_v5 = true;
            continue;
        }
        if (current == "--skip-families" && index + 1 < argc) {
            append_skip_families(options.skip_families, argv[++index]);
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
            static_cast<void>(std::stoul(argv[++index]));
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
    if (options.perf_scope != "full_repeat_raw" && options.perf_scope != "full_repeat_avg") {
        fail("--perf-scope must be one of full_repeat_raw or full_repeat_avg");
    }
    if (options.directive_blob.has_value() && options.command != "run-kernel") {
        fail("--directive-blob is only valid with run-kernel");
    }
    if (options.policy_blob.has_value() && options.command != "run-kernel") {
        fail("--policy-blob is only valid with run-kernel");
    }
    if (options.manual_load && options.command != "run-kernel") {
        fail("--manual-load is only valid with run-kernel");
    }
    if (options.recompile_cmov && options.command != "run-kernel") {
        fail("--recompile-cmov is only valid with run-kernel");
    }
    if (options.recompile_wide && options.command != "run-kernel") {
        fail("--recompile-wide is only valid with run-kernel");
    }
    if (options.recompile_rotate && options.command != "run-kernel") {
        fail("--recompile-rotate is only valid with run-kernel");
    }
    if (options.recompile_lea && options.command != "run-kernel") {
        fail("--recompile-lea is only valid with run-kernel");
    }
    if (options.recompile_extract && options.command != "run-kernel") {
        fail("--recompile-extract is only valid with run-kernel");
    }
    if (options.recompile_rotate_rorx && options.command != "run-kernel") {
        fail("--recompile-rotate-rorx is only valid with run-kernel");
    }
    if (options.recompile_all && options.command != "run-kernel") {
        fail("--recompile-all is only valid with run-kernel");
    }
    if (options.recompile_v5 && options.command != "run-kernel") {
        fail("--recompile-v5 is only valid with run-kernel");
    }
    if (!options.skip_families.empty() && options.command != "run-kernel") {
        fail("--skip-families is only valid with run-kernel");
    }
    if (options.recompile_v5 &&
        !(options.recompile_cmov || options.recompile_rotate ||
          options.recompile_rotate_rorx || options.recompile_wide ||
          options.recompile_lea || options.recompile_extract ||
          options.recompile_all)) {
        fail("--recompile-v5 requires at least one recompile family or --recompile-all");
    }
    if (!options.skip_families.empty() && options.policy_blob.has_value()) {
        fail("--skip-families cannot be used with --policy-blob");
    }
    if (!options.skip_families.empty() &&
        !(options.recompile_cmov || options.recompile_rotate ||
          options.recompile_rotate_rorx || options.recompile_wide ||
          options.recompile_lea || options.recompile_extract ||
          options.recompile_all)) {
        fail("--skip-families requires an auto-scan recompile family or --recompile-all");
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

void print_json(const sample_result &sample)
{
    const double inflation_ratio = sample.code_size.bpf_bytecode_bytes == 0
        ? 0.0
        : static_cast<double>(sample.code_size.native_code_bytes) /
              static_cast<double>(sample.code_size.bpf_bytecode_bytes);
    const uint64_t total_directive_sites =
        sample.directive_scan.cmov_sites +
        sample.directive_scan.wide_sites +
        sample.directive_scan.rotate_sites +
        sample.directive_scan.lea_sites +
        sample.directive_scan.bitfield_sites;

    std::cout
        << "{"
        << "\"compile_ns\":" << sample.compile_ns << ","
        << "\"exec_ns\":" << sample.exec_ns << ","
        << "\"timing_source\":\"" << json_escape(sample.timing_source) << "\""
        << ",\"no_cmov\":" << (sample.no_cmov ? "true" : "false");

    if (sample.opt_level.has_value()) {
        std::cout << ",\"opt_level\":" << *sample.opt_level;
    }
    std::cout << ",\"disabled_passes\":[";
    for (size_t index = 0; index < sample.disabled_passes.size(); ++index) {
        if (index != 0) {
            std::cout << ",";
        }
        std::cout << "\"" << json_escape(sample.disabled_passes[index]) << "\"";
    }
    std::cout << "]";

    if (sample.wall_exec_ns.has_value()) {
        std::cout << ",\"wall_exec_ns\":" << *sample.wall_exec_ns;
    }
    if (sample.exec_cycles.has_value()) {
        std::cout << ",\"exec_cycles\":" << *sample.exec_cycles;
    }
    if (sample.tsc_freq_hz.has_value()) {
        std::cout << ",\"tsc_freq_hz\":" << *sample.tsc_freq_hz;
    }

    std::cout
        << ",\"result\":" << sample.result << ","
        << "\"retval\":" << sample.retval;

    if (sample.jited_prog_len.has_value()) {
        std::cout << ",\"jited_prog_len\":" << *sample.jited_prog_len;
    }
    if (sample.xlated_prog_len.has_value()) {
        std::cout << ",\"xlated_prog_len\":" << *sample.xlated_prog_len;
    }
    if (sample.native_code_size.has_value()) {
        std::cout << ",\"native_code_size\":" << *sample.native_code_size;
    }
    if (sample.bpf_insn_count.has_value()) {
        std::cout << ",\"bpf_insn_count\":" << *sample.bpf_insn_count;
    }

    std::cout
        << ",\"code_size\":{"
        << "\"bpf_bytecode_bytes\":" << sample.code_size.bpf_bytecode_bytes << ","
        << "\"native_code_bytes\":" << sample.code_size.native_code_bytes << ","
        << "\"inflation_ratio\":" << inflation_ratio
        << "},"
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
        << "},"
        << "\"directive_scan\":{"
        << "\"performed\":" << (sample.directive_scan.performed ? "true" : "false") << ","
        << "\"cmov_sites\":" << sample.directive_scan.cmov_sites << ","
        << "\"wide_sites\":" << sample.directive_scan.wide_sites << ","
        << "\"rotate_sites\":" << sample.directive_scan.rotate_sites << ","
        << "\"lea_sites\":" << sample.directive_scan.lea_sites << ","
        << "\"bitfield_sites\":" << sample.directive_scan.bitfield_sites << ","
        << "\"total_sites\":" << total_directive_sites
        << "},"
        << "\"recompile\":{"
        << "\"requested\":" << (sample.recompile.requested ? "true" : "false") << ","
        << "\"mode\":\"" << json_escape(sample.recompile.mode) << "\","
        << "\"requested_families\":";
    print_json_string_array(sample.recompile.requested_families);
    std::cout << ",\"skipped_families\":";
    print_json_string_array(sample.recompile.skipped_families);
    std::cout
        << ",\"policy_generated\":" << (sample.recompile.policy_generated ? "true" : "false") << ","
        << "\"policy_bytes\":" << sample.recompile.policy_bytes << ","
        << "\"syscall_attempted\":" << (sample.recompile.syscall_attempted ? "true" : "false") << ","
        << "\"applied\":" << (sample.recompile.applied ? "true" : "false") << ","
        << "\"error\":\"" << json_escape(sample.recompile.error) << "\""
        << "}"
        << "}\n";
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
