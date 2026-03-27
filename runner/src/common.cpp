#include "micro_exec.hpp"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <unordered_map>
#include <variant>

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
        "usage:\n"
        "  micro_exec\n"
        "    keep-alive mode: read JSON commands from stdin, emit one JSON result per line\n"
        "  micro_exec <"
#if MICRO_EXEC_ENABLE_LLVMBPF
        "run-llvmbpf|"
#endif
        "run-kernel|run-kernel-attach|list-programs> [--program <path>|<path>] [--program-name <name>] "
        "[--memory <path>] [--fixture-path <path>] [--btf-custom-path <path>] "
        "[--rejit] [--rejit-program <path>] [--daemon-socket <path>] "
        "[--manual-load] "
        "[--io-mode map|staged|packet|context] [--raw-packet] [--repeat N] [--warmup N] [--input-size N] "
        "[--attach] [--workload-iterations N] [--workload-type mixed|stress-ng|fio|wrk|getpid|nanosleep|write_devnull] "
        "[--trigger-command <shell>] [--trigger-timeout-seconds N] "
        "[--opt-level 0|1|2|3] [--no-cmov] [--llvm-target-cpu <cpu>] [--llvm-target-features <csv>] [--llvm-disable-pass <name>] [--llvm-log-passes] "
        "[--perf-counters] [--perf-scope full_repeat_raw|full_repeat_avg] "
        "[--dump-jit] [--dump-xlated <path>] [--compile-only]";
}

using json_field =
    std::variant<std::monostate, std::string, int64_t, bool, std::vector<std::string>>;
using json_object = std::unordered_map<std::string, json_field>;

class json_reader {
  public:
    explicit json_reader(std::string_view text) : text_(text) {}

    json_object parse_object()
    {
        skip_whitespace();
        expect('{');
        skip_whitespace();

        json_object result;
        if (consume('}')) {
            return result;
        }

        while (true) {
            const std::string key = parse_string();
            skip_whitespace();
            expect(':');
            skip_whitespace();
            result[key] = parse_value();
            skip_whitespace();
            if (consume('}')) {
                break;
            }
            expect(',');
            skip_whitespace();
        }

        skip_whitespace();
        if (position_ != text_.size()) {
            fail("unexpected trailing characters in keep-alive JSON command");
        }

        return result;
    }

  private:
    bool consume(char expected)
    {
        if (position_ < text_.size() && text_[position_] == expected) {
            ++position_;
            return true;
        }
        return false;
    }

    void expect(char expected)
    {
        if (!consume(expected)) {
            fail("malformed keep-alive JSON command");
        }
    }

    void skip_whitespace()
    {
        while (position_ < text_.size() &&
               std::isspace(static_cast<unsigned char>(text_[position_])) != 0) {
            ++position_;
        }
    }

    char peek() const
    {
        if (position_ >= text_.size()) {
            return '\0';
        }
        return text_[position_];
    }

    std::string parse_string()
    {
        expect('"');
        std::string value;
        while (position_ < text_.size()) {
            const char current = text_[position_++];
            if (current == '"') {
                return value;
            }
            if (current != '\\') {
                value += current;
                continue;
            }

            if (position_ >= text_.size()) {
                fail("unterminated escape sequence in keep-alive JSON command");
            }

            const char escaped = text_[position_++];
            switch (escaped) {
            case '"':
            case '\\':
            case '/':
                value += escaped;
                break;
            case 'b':
                value += '\b';
                break;
            case 'f':
                value += '\f';
                break;
            case 'n':
                value += '\n';
                break;
            case 'r':
                value += '\r';
                break;
            case 't':
                value += '\t';
                break;
            default:
                fail("unsupported escape sequence in keep-alive JSON command");
            }
        }

        fail("unterminated string in keep-alive JSON command");
    }

    int64_t parse_integer()
    {
        const size_t start = position_;
        if (peek() == '-') {
            ++position_;
        }
        if (position_ >= text_.size() ||
            std::isdigit(static_cast<unsigned char>(text_[position_])) == 0) {
            fail("expected integer in keep-alive JSON command");
        }
        while (position_ < text_.size() &&
               std::isdigit(static_cast<unsigned char>(text_[position_])) != 0) {
            ++position_;
        }

        try {
            return std::stoll(std::string(text_.substr(start, position_ - start)));
        } catch (const std::exception &) {
            fail("invalid integer literal in keep-alive JSON command");
        }
    }

    void consume_literal(std::string_view literal)
    {
        if (text_.substr(position_, literal.size()) != literal) {
            fail("malformed keep-alive JSON command");
        }
        position_ += literal.size();
    }

    std::vector<std::string> parse_string_array()
    {
        expect('[');
        skip_whitespace();

        std::vector<std::string> values;
        if (consume(']')) {
            return values;
        }

        while (true) {
            skip_whitespace();
            values.push_back(parse_string());
            skip_whitespace();
            if (consume(']')) {
                break;
            }
            expect(',');
            skip_whitespace();
        }

        return values;
    }

    json_field parse_value()
    {
        switch (peek()) {
        case '"':
            return parse_string();
        case '[':
            return parse_string_array();
        case 't':
            consume_literal("true");
            return true;
        case 'f':
            consume_literal("false");
            return false;
        case 'n':
            consume_literal("null");
            return std::monostate {};
        case '-':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return parse_integer();
        case '{':
            fail("nested JSON objects are not supported in keep-alive commands");
        default:
            fail("unsupported JSON value in keep-alive command");
        }
    }

    std::string_view text_;
    size_t position_ = 0;
};

const json_field *find_field(
    const json_object &fields,
    std::initializer_list<std::string_view> names)
{
    for (const auto name : names) {
        const auto iter = fields.find(std::string(name));
        if (iter != fields.end()) {
            return &iter->second;
        }
    }
    return nullptr;
}

std::optional<std::string> get_optional_string_field(
    const json_object &fields,
    std::initializer_list<std::string_view> names)
{
    const json_field *field = find_field(fields, names);
    if (field == nullptr || std::holds_alternative<std::monostate>(*field)) {
        return std::nullopt;
    }
    if (!std::holds_alternative<std::string>(*field)) {
        fail("keep-alive JSON field must be a string");
    }
    return std::get<std::string>(*field);
}

std::optional<std::vector<std::string>> get_optional_string_array_field(
    const json_object &fields,
    std::initializer_list<std::string_view> names)
{
    const json_field *field = find_field(fields, names);
    if (field == nullptr || std::holds_alternative<std::monostate>(*field)) {
        return std::nullopt;
    }
    if (!std::holds_alternative<std::vector<std::string>>(*field)) {
        fail("keep-alive JSON field must be an array of strings");
    }
    return std::get<std::vector<std::string>>(*field);
}

std::optional<int64_t> get_optional_int_field(
    const json_object &fields,
    std::initializer_list<std::string_view> names)
{
    const json_field *field = find_field(fields, names);
    if (field == nullptr || std::holds_alternative<std::monostate>(*field)) {
        return std::nullopt;
    }
    if (!std::holds_alternative<int64_t>(*field)) {
        fail("keep-alive JSON field must be an integer");
    }
    return std::get<int64_t>(*field);
}

std::optional<bool> get_optional_bool_field(
    const json_object &fields,
    std::initializer_list<std::string_view> names)
{
    const json_field *field = find_field(fields, names);
    if (field == nullptr || std::holds_alternative<std::monostate>(*field)) {
        return std::nullopt;
    }
    if (!std::holds_alternative<bool>(*field)) {
        fail("keep-alive JSON field must be a boolean");
    }
    return std::get<bool>(*field);
}

uint32_t require_u32_value(int64_t value, std::string_view field_name)
{
    if (value < 0 || value > static_cast<int64_t>(std::numeric_limits<uint32_t>::max())) {
        fail("keep-alive JSON field out of range for uint32_t: " + std::string(field_name));
    }
    return static_cast<uint32_t>(value);
}

void validate_cli_options(const cli_options &options)
{
    if (options.program.empty()) {
        fail("--program is required");
    }

    const bool is_kernel_command = options.command == "run-kernel";
    if (options.perf_scope != "full_repeat_raw" &&
        options.perf_scope != "full_repeat_avg") {
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
        if (current == "--program" && index + 1 < argc) {
            options.program = argv[++index];
            continue;
        }
        if (!current.empty() && current.front() != '-' && options.program.empty() &&
            options.command != "list-programs") {
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
        if (current == "--rejit") {
            options.rejit = true;
            continue;
        }
        if (current == "--rejit-program" && index + 1 < argc) {
            options.rejit_program = std::filesystem::path(argv[++index]);
            options.rejit = true;
            continue;
        }
        if (current == "--daemon-socket" && index + 1 < argc) {
            options.daemon_socket = std::string(argv[++index]);
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
        if (current == "--warmup" && index + 1 < argc) {
            options.warmup_repeat = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if (current == "--input-size" && index + 1 < argc) {
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
        if (current == "--attach") {
            options.attach_mode = true;
            continue;
        }
        if (current == "--workload-iterations" && index + 1 < argc) {
            options.workload_iterations = static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        if (current == "--workload-type" && index + 1 < argc) {
            options.workload_type = argv[++index];
            continue;
        }
        if (current == "--trigger-command" && index + 1 < argc) {
            options.trigger_command = std::string(argv[++index]);
            continue;
        }
        if (current == "--trigger-timeout-seconds" && index + 1 < argc) {
            options.trigger_timeout_seconds =
                static_cast<uint32_t>(std::stoul(argv[++index]));
            continue;
        }
        fail("unknown or incomplete argument: " + std::string(current));
    }

    validate_cli_options(options);
    return options;
}

keep_alive_request parse_keep_alive_request(std::string_view json_line)
{
    const json_object fields = json_reader(json_line).parse_object();
    keep_alive_request request;

    const auto cmd = get_optional_string_field(fields, {"cmd"});
    if (!cmd.has_value()) {
        fail("keep-alive JSON command requires a string field named 'cmd'");
    }
    request.cmd = lower_ascii(*cmd);
    if (request.cmd == "exit") {
        return request;
    }

    cli_options options;
    if (request.cmd == "list-programs") {
        options.command = "list-programs";
    } else if (request.cmd == "run") {
        const auto runtime = get_optional_string_field(fields, {"runtime"});
        if (!runtime.has_value()) {
            fail("keep-alive run command requires a string field named 'runtime'");
        }
        const std::string runtime_name = lower_ascii(*runtime);
        const bool runtime_implies_rejit = runtime_name == "kernel-rejit";
        const bool runtime_implies_attach = runtime_name == "kernel-attach" ||
                                            runtime_name == "kernel-attach-rejit";
        if (runtime_implies_attach) {
            options.command = "run-kernel-attach";
            options.attach_mode = true;
            options.rejit = runtime_name == "kernel-attach-rejit";
        } else if (runtime_name == "kernel" ||
            runtime_implies_rejit) {
            options.command = "run-kernel";
            options.rejit = runtime_implies_rejit;
        } else if (runtime_name == "llvmbpf") {
            options.command = "run-llvmbpf";
        } else {
            fail("unsupported keep-alive runtime: " + *runtime);
        }
    } else {
        fail("unsupported keep-alive command: " + request.cmd);
    }

    const auto program = get_optional_string_field(fields, {"program"});
    if (!program.has_value()) {
        fail("keep-alive command requires a program path in 'program'");
    }
    options.program = std::filesystem::path(*program);

    if (const auto memory = get_optional_string_field(fields, {"memory"});
        memory.has_value()) {
        options.memory = std::filesystem::path(*memory);
    }
    if (const auto fixture_path = get_optional_string_field(fields, {"fixture_path"});
        fixture_path.has_value()) {
        options.fixture_path = std::filesystem::path(*fixture_path);
    }
    if (const auto btf_path = get_optional_string_field(fields, {"btf_custom_path"});
        btf_path.has_value()) {
        options.btf_custom_path = std::filesystem::path(*btf_path);
    }
    if (const auto program_name = get_optional_string_field(fields, {"program_name"});
        program_name.has_value()) {
        options.program_name = *program_name;
    }
    if (const auto trigger_command = get_optional_string_field(fields, {"trigger_command"});
        trigger_command.has_value()) {
        options.trigger_command = *trigger_command;
    }
    if (const auto trigger_timeout = get_optional_int_field(fields, {"trigger_timeout_seconds"});
        trigger_timeout.has_value()) {
        options.trigger_timeout_seconds =
            require_u32_value(*trigger_timeout, "trigger_timeout_seconds");
    }
    if (const auto io_mode = get_optional_string_field(fields, {"io_mode"});
        io_mode.has_value()) {
        options.io_mode = *io_mode;
    }
    if (const auto repeat = get_optional_int_field(fields, {"repeat"});
        repeat.has_value()) {
        options.repeat = require_u32_value(*repeat, "repeat");
    }
    if (const auto warmup = get_optional_int_field(fields, {"warmup_repeat"});
        warmup.has_value()) {
        options.warmup_repeat = require_u32_value(*warmup, "warmup_repeat");
    }
    if (const auto input_size = get_optional_int_field(fields, {"input_size"});
        input_size.has_value()) {
        options.input_size = require_u32_value(*input_size, "input_size");
    }
    if (const auto opt_level = get_optional_int_field(fields, {"opt_level"});
        opt_level.has_value()) {
        if (*opt_level < 0 || *opt_level > 3) {
            fail("--opt-level must be between 0 and 3");
        }
        options.opt_level = static_cast<int>(*opt_level);
    }
    if (const auto no_cmov = get_optional_bool_field(fields, {"no_cmov"});
        no_cmov.has_value()) {
        options.no_cmov = *no_cmov;
    }
    if (const auto raw_packet = get_optional_bool_field(fields, {"raw_packet"});
        raw_packet.has_value()) {
        options.raw_packet = *raw_packet;
    }
    if (const auto manual_load = get_optional_bool_field(fields, {"manual_load"});
        manual_load.has_value()) {
        options.manual_load = *manual_load;
    }
    if (const auto compile_only = get_optional_bool_field(fields, {"compile_only"});
        compile_only.has_value()) {
        options.compile_only = *compile_only;
    }
    if (const auto dump_jit = get_optional_bool_field(fields, {"dump_jit"});
        dump_jit.has_value()) {
        options.dump_jit = *dump_jit;
    }
    if (const auto dump_xlated = get_optional_string_field(fields, {"dump_xlated"});
        dump_xlated.has_value()) {
        options.dump_xlated = std::filesystem::path(*dump_xlated);
    }
    if (const auto target_cpu = get_optional_string_field(fields, {"llvm_target_cpu"});
        target_cpu.has_value()) {
        options.llvm_target_cpu = *target_cpu;
    }
    if (const auto target_features = get_optional_string_field(
            fields, {"llvm_target_features"});
        target_features.has_value()) {
        options.llvm_target_features = *target_features;
    }
    if (const auto disabled_passes = get_optional_string_array_field(fields, {"disabled_passes"});
        disabled_passes.has_value()) {
        options.disabled_passes = *disabled_passes;
    }
    if (const auto log_passes = get_optional_bool_field(fields, {"log_passes"});
        log_passes.has_value()) {
        options.log_passes = *log_passes;
    }
    if (const auto perf_counters = get_optional_bool_field(fields, {"perf_counters"});
        perf_counters.has_value()) {
        options.perf_counters = *perf_counters;
    }
    if (const auto perf_scope = get_optional_string_field(fields, {"perf_scope"});
        perf_scope.has_value()) {
        options.perf_scope = *perf_scope;
    }
    if (const auto rejit = get_optional_bool_field(fields, {"rejit"});
        rejit.has_value()) {
        options.rejit = *rejit;
    }
    if (const auto rejit_program = get_optional_string_field(fields, {"rejit_program"});
        rejit_program.has_value()) {
        options.rejit_program = std::filesystem::path(*rejit_program);
        options.rejit = true;
    }
    if (const auto daemon_socket = get_optional_string_field(fields, {"daemon_socket"});
        daemon_socket.has_value()) {
        options.daemon_socket = *daemon_socket;
        options.rejit = true;
    }
    if (const auto attach_mode = get_optional_bool_field(fields, {"attach_mode"});
        attach_mode.has_value()) {
        options.attach_mode = *attach_mode;
    }
    if (const auto workload_iterations = get_optional_int_field(fields, {"workload_iterations"});
        workload_iterations.has_value()) {
        options.workload_iterations = require_u32_value(*workload_iterations, "workload_iterations");
    }
    if (const auto workload_type = get_optional_string_field(fields, {"workload_type"});
        workload_type.has_value()) {
        options.workload_type = *workload_type;
    }

    validate_cli_options(options);
    request.options = std::move(options);
    return request;
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
    if (sample.rejit.daemon_debug_stripped) {
        out << ",\"daemon_debug_stripped\":true";
    }
    if (!sample.rejit.daemon_response.empty()) {
        /* Embed daemon_response as pre-serialized JSON value (not re-escaped) */
        out << ",\"daemon_response\":" << sample.rejit.daemon_response;
    }
    out << "}";
    if (sample.correctness_mismatch.has_value()) {
        out << ",\"correctness_mismatch\":"
            << (*sample.correctness_mismatch ? "true" : "false");
    }
    out << "}";
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
