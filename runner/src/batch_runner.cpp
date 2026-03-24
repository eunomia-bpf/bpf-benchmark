#include "micro_exec.hpp"

#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

namespace {

using clock_type = std::chrono::steady_clock;

struct batch_cli_options {
    std::filesystem::path spec_path;
    std::filesystem::path result_json_path;
    std::optional<std::filesystem::path> progress_json_path;
};

struct batch_job {
    std::string id;
    std::string type = "test_run";
    std::string execution = "serial";
    std::string runtime;
    cli_options options;
};

struct batch_job_result {
    std::string id;
    std::string type;
    std::string execution;
    std::string runtime;
    bool ok = false;
    std::string error;
    uint64_t wall_time_ns = 0;
    std::vector<sample_result> samples;
};

struct batch_spec {
    size_t schema_version = 1;
    size_t max_parallel_jobs = 1;
    bool retain_daemon_debug = false;
    std::vector<batch_job> jobs;
};

struct batch_progress_state {
    std::string status = "running";
    size_t total_jobs = 0;
    size_t completed_jobs = 0;
    size_t succeeded_jobs = 0;
    size_t failed_jobs = 0;
    std::string last_completed_job;
    std::string error;
};

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

std::string batch_usage_text()
{
    return
        "usage:\n"
        "  micro_exec run-batch --spec <path> --result-json <path> [--progress-json <path>]";
}

std::string format_timestamp(std::chrono::system_clock::time_point time_point)
{
    const std::time_t time_value = std::chrono::system_clock::to_time_t(time_point);
    std::tm utc_time {};
#if defined(_WIN32)
    gmtime_s(&utc_time, &time_value);
#else
    gmtime_r(&time_value, &utc_time);
#endif
    std::ostringstream out;
    out << std::put_time(&utc_time, "%Y-%m-%dT%H:%M:%SZ");
    return out.str();
}

std::string require_scalar_string(const YAML::Node &node, const char *field_name)
{
    if (!node || !node.IsScalar()) {
        fail(std::string("batch spec requires a scalar string field '") + field_name + "'");
    }
    return node.as<std::string>();
}

std::string optional_scalar_string(
    const YAML::Node &node,
    const char *field_name,
    const std::string &default_value = {})
{
    const YAML::Node value = node[field_name];
    if (!value) {
        return default_value;
    }
    if (!value.IsScalar()) {
        fail(std::string("batch spec field '") + field_name + "' must be a scalar");
    }
    return value.as<std::string>();
}

std::optional<std::string> optional_string(const YAML::Node &node, const char *field_name)
{
    const YAML::Node value = node[field_name];
    if (!value) {
        return std::nullopt;
    }
    if (!value.IsScalar()) {
        fail(std::string("batch spec field '") + field_name + "' must be a scalar");
    }
    return value.as<std::string>();
}

std::optional<std::filesystem::path> optional_path(const YAML::Node &node, const char *field_name)
{
    if (const auto value = optional_string(node, field_name); value.has_value()) {
        return std::filesystem::path(*value);
    }
    return std::nullopt;
}

bool optional_bool(const YAML::Node &node, const char *field_name, bool default_value)
{
    const YAML::Node value = node[field_name];
    if (!value) {
        return default_value;
    }
    if (!value.IsScalar()) {
        fail(std::string("batch spec field '") + field_name + "' must be a bool");
    }
    return value.as<bool>();
}

uint32_t optional_u32(const YAML::Node &node, const char *field_name, uint32_t default_value)
{
    const YAML::Node value = node[field_name];
    if (!value) {
        return default_value;
    }
    if (!value.IsScalar()) {
        fail(std::string("batch spec field '") + field_name + "' must be an integer");
    }
    return value.as<uint32_t>();
}

int optional_int(const YAML::Node &node, const char *field_name, int default_value)
{
    const YAML::Node value = node[field_name];
    if (!value) {
        return default_value;
    }
    if (!value.IsScalar()) {
        fail(std::string("batch spec field '") + field_name + "' must be an integer");
    }
    return value.as<int>();
}

std::vector<std::string> optional_string_list(const YAML::Node &node, const char *field_name)
{
    const YAML::Node value = node[field_name];
    if (!value) {
        return {};
    }
    if (!value.IsSequence()) {
        fail(std::string("batch spec field '") + field_name + "' must be a sequence");
    }
    std::vector<std::string> values;
    values.reserve(value.size());
    for (const auto &item : value) {
        if (!item.IsScalar()) {
            fail(std::string("batch spec field '") + field_name + "' must be a string sequence");
        }
        values.push_back(item.as<std::string>());
    }
    return values;
}

void validate_batch_job(const batch_job &job)
{
    if (job.type != "test_run") {
        fail("unsupported batch job type: " + job.type);
    }
    if (job.execution != "serial" && job.execution != "parallel") {
        fail("unsupported batch job execution mode: " + job.execution);
    }
    if (job.options.program.empty()) {
        fail("batch job is missing program path: " + job.id);
    }
    if (job.options.command != "run-kernel" && job.options.command != "run-llvmbpf") {
        fail("unsupported batch job command for job " + job.id + ": " + job.options.command);
    }
    if (job.options.io_mode != "map" &&
        job.options.io_mode != "staged" &&
        job.options.io_mode != "packet" &&
        job.options.io_mode != "context") {
        fail("batch job has invalid io_mode for job " + job.id + ": " + job.options.io_mode);
    }
    if (!job.options.compile_only && job.options.repeat == 0) {
        fail("batch job repeat must be >= 1 for job " + job.id);
    }
}

batch_job parse_job(const YAML::Node &node, size_t index)
{
    if (!node.IsMap()) {
        fail("batch spec jobs entries must be mappings");
    }

    batch_job job;
    job.id = optional_scalar_string(node, "id", "job-" + std::to_string(index + 1));
    job.type = optional_scalar_string(node, "type", "test_run");
    job.execution = optional_scalar_string(
        node,
        "execution",
        optional_bool(node, "compile_only", false) ? "parallel" : "serial");
    job.runtime = require_scalar_string(node["runtime"], "runtime");

    cli_options options;
    const std::string runtime = job.runtime;
    if (runtime == "llvmbpf") {
        options.command = "run-llvmbpf";
    } else if (runtime == "kernel") {
        options.command = "run-kernel";
    } else if (runtime == "kernel-rejit" || runtime == "kernel_rejit") {
        options.command = "run-kernel";
        options.rejit = true;
    } else {
        fail("unsupported batch runtime for job " + job.id + ": " + runtime);
    }

    options.program = std::filesystem::path(require_scalar_string(node["program"], "program"));
    options.program_name = optional_string(node, "program_name");
    options.memory = optional_path(node, "memory");
    options.btf_custom_path = optional_path(node, "btf_custom_path");
    options.daemon_socket = optional_string(node, "daemon_socket");
    options.rejit_program = optional_path(node, "rejit_program");
    if (options.daemon_socket.has_value() || options.rejit_program.has_value()) {
        options.rejit = true;
    }
    options.io_mode = optional_scalar_string(node, "io_mode", "map");
    options.manual_load = optional_bool(node, "manual_load", false);
    options.raw_packet = optional_bool(node, "raw_packet", false);
    options.repeat = optional_u32(node, "repeat", 1);
    options.warmup_repeat = optional_u32(node, "warmup_repeat", 5);
    options.input_size = optional_u32(node, "input_size", 0);
    options.opt_level = optional_int(node, "opt_level", 3);
    options.no_cmov = optional_bool(node, "no_cmov", false);
    options.llvm_target_cpu = optional_string(node, "llvm_target_cpu");
    options.llvm_target_features = optional_string(node, "llvm_target_features");
    options.disabled_passes = optional_string_list(node, "disabled_passes");
    options.log_passes = optional_bool(node, "log_passes", false);
    options.perf_counters = optional_bool(node, "perf_counters", false);
    options.perf_scope = optional_scalar_string(node, "perf_scope", "full_repeat_raw");
    options.dump_jit = optional_bool(node, "dump_jit", false);
    options.dump_xlated = optional_path(node, "dump_xlated");
    options.compile_only = optional_bool(node, "compile_only", false);
    job.options = std::move(options);

    validate_batch_job(job);
    return job;
}

batch_spec load_batch_spec(const std::filesystem::path &spec_path)
{
    const YAML::Node root = YAML::LoadFile(spec_path.string());
    if (!root.IsMap()) {
        fail("batch spec root must be a mapping");
    }

    batch_spec spec;
    spec.schema_version = static_cast<size_t>(root["schema_version"] ? root["schema_version"].as<int>() : 1);
    spec.retain_daemon_debug = optional_bool(root, "retain_daemon_debug", false);
    const YAML::Node scheduler = root["scheduler"];
    if (scheduler) {
        spec.max_parallel_jobs = static_cast<size_t>(
            std::max(1, scheduler["max_parallel_jobs"] ? scheduler["max_parallel_jobs"].as<int>() : 1));
    }

    const YAML::Node jobs = root["jobs"];
    if (!jobs || !jobs.IsSequence() || jobs.size() == 0) {
        fail("batch spec must contain a non-empty jobs sequence");
    }
    spec.jobs.reserve(jobs.size());
    for (size_t index = 0; index < jobs.size(); ++index) {
        spec.jobs.push_back(parse_job(jobs[index], index));
    }
    return spec;
}

batch_job_result execute_job(const batch_job &job)
{
    batch_job_result result;
    result.id = job.id;
    result.type = job.type;
    result.execution = job.execution;
    result.runtime = job.runtime;

    const auto started = clock_type::now();
    try {
        if (job.options.command == "run-llvmbpf") {
            result.samples = {run_llvmbpf(job.options)};
        } else if (job.options.command == "run-kernel") {
            result.samples = run_kernel(job.options);
        } else {
            fail("unsupported batch command: " + job.options.command);
        }
        result.ok = true;
    } catch (const std::exception &error) {
        result.ok = false;
        result.error = error.what();
    }
    result.wall_time_ns = elapsed_ns(started, clock_type::now());
    return result;
}

std::vector<batch_job_result> execute_parallel_chunk(
    const std::vector<batch_job> &jobs,
    size_t max_parallel_jobs)
{
    std::vector<batch_job_result> results(jobs.size());
    std::atomic<size_t> next_index {0};
    const size_t worker_count = std::max<size_t>(
        1,
        std::min(max_parallel_jobs, jobs.size()));

    std::vector<std::thread> workers;
    workers.reserve(worker_count);
    for (size_t worker = 0; worker < worker_count; ++worker) {
        workers.emplace_back([&jobs, &results, &next_index]() {
            while (true) {
                const size_t index = next_index.fetch_add(1);
                if (index >= jobs.size()) {
                    return;
                }
                results[index] = execute_job(jobs[index]);
            }
        });
    }

    for (auto &worker : workers) {
        worker.join();
    }
    return results;
}

void write_progress_json(
    const std::filesystem::path &path,
    const batch_progress_state &state)
{
    std::ofstream out(path, std::ios::trunc);
    if (!out.is_open()) {
        fail("unable to open batch progress file for writing: " + path.string());
    }
    out
        << "{"
        << "\"status\":\"" << json_escape(state.status) << "\","
        << "\"total_jobs\":" << state.total_jobs << ","
        << "\"completed_jobs\":" << state.completed_jobs << ","
        << "\"succeeded_jobs\":" << state.succeeded_jobs << ","
        << "\"failed_jobs\":" << state.failed_jobs << ","
        << "\"last_completed_job\":\"" << json_escape(state.last_completed_job) << "\","
        << "\"error\":\"" << json_escape(state.error) << "\""
        << "}\n";
}

void write_result_json(
    const std::filesystem::path &path,
    const std::filesystem::path &spec_path,
    const std::chrono::system_clock::time_point &started_at,
    const std::chrono::system_clock::time_point &finished_at,
    const std::vector<batch_job_result> &results,
    const batch_progress_state &progress,
    bool retain_daemon_debug)
{
    std::ofstream out(path, std::ios::trunc);
    if (!out.is_open()) {
        fail("unable to open batch result file for writing: " + path.string());
    }

    out
        << "{"
        << "\"schema_version\":1,"
        << "\"spec_path\":\"" << json_escape(spec_path.string()) << "\","
        << "\"started_at\":\"" << json_escape(format_timestamp(started_at)) << "\","
        << "\"finished_at\":\"" << json_escape(format_timestamp(finished_at)) << "\","
        << "\"summary\":{"
        << "\"total_jobs\":" << progress.total_jobs << ","
        << "\"completed_jobs\":" << progress.completed_jobs << ","
        << "\"succeeded_jobs\":" << progress.succeeded_jobs << ","
        << "\"failed_jobs\":" << progress.failed_jobs
        << "},"
        << "\"jobs\":[";

    for (size_t index = 0; index < results.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        const auto &result = results[index];
        out
            << "{"
            << "\"id\":\"" << json_escape(result.id) << "\","
            << "\"type\":\"" << json_escape(result.type) << "\","
            << "\"execution\":\"" << json_escape(result.execution) << "\","
            << "\"runtime\":\"" << json_escape(result.runtime) << "\","
            << "\"ok\":" << (result.ok ? "true" : "false") << ","
            << "\"error\":\"" << json_escape(result.error) << "\","
            << "\"wall_time_ns\":" << result.wall_time_ns << ","
            << "\"samples\":";
        if (retain_daemon_debug) {
            print_json(out, result.samples);
        } else {
            std::vector<sample_result> sanitized_samples = result.samples;
            for (auto &sample : sanitized_samples) {
                if (!sample.rejit.daemon_response.empty()) {
                    sample.rejit.daemon_response.clear();
                    sample.rejit.daemon_debug_stripped = true;
                }
            }
            print_json(out, sanitized_samples);
        }
        out << "}";
    }

    out << "]}\n";
}

batch_cli_options parse_batch_cli_args(int argc, char **argv)
{
    if (argc >= 3 &&
        (std::string_view(argv[2]) == "--help" ||
         std::string_view(argv[2]) == "-h")) {
        std::cout << batch_usage_text() << "\n";
        std::exit(0);
    }
    if (argc < 6) {
        fail(batch_usage_text());
    }

    batch_cli_options options;
    for (int index = 2; index < argc; ++index) {
        const std::string_view current = argv[index];
        if ((current == "--spec") && index + 1 < argc) {
            options.spec_path = argv[++index];
            continue;
        }
        if ((current == "--result-json") && index + 1 < argc) {
            options.result_json_path = argv[++index];
            continue;
        }
        if ((current == "--progress-json") && index + 1 < argc) {
            options.progress_json_path = std::filesystem::path(argv[++index]);
            continue;
        }
        fail("unknown or incomplete run-batch argument: " + std::string(current));
    }

    if (options.spec_path.empty()) {
        fail("--spec is required");
    }
    if (options.result_json_path.empty()) {
        fail("--result-json is required");
    }
    return options;
}

} // namespace

int run_batch_cli(int argc, char **argv)
{
    initialize_micro_exec_process();

    const batch_cli_options cli = parse_batch_cli_args(argc, argv);
    const batch_spec spec = load_batch_spec(cli.spec_path);

    batch_progress_state progress;
    progress.total_jobs = spec.jobs.size();
    if (cli.progress_json_path.has_value()) {
        write_progress_json(*cli.progress_json_path, progress);
    }

    const auto started_at = std::chrono::system_clock::now();
    std::vector<batch_job_result> results;
    results.reserve(spec.jobs.size());

    try {
        size_t index = 0;
        while (index < spec.jobs.size()) {
            const auto &job = spec.jobs[index];
            if (job.execution == "parallel") {
                std::vector<batch_job> chunk;
                while (index < spec.jobs.size() && spec.jobs[index].execution == "parallel") {
                    chunk.push_back(spec.jobs[index]);
                    ++index;
                }
                auto chunk_results = execute_parallel_chunk(chunk, spec.max_parallel_jobs);
                for (auto &result : chunk_results) {
                    progress.completed_jobs += 1;
                    progress.last_completed_job = result.id;
                    if (result.ok) {
                        progress.succeeded_jobs += 1;
                    } else {
                        progress.failed_jobs += 1;
                    }
                    results.push_back(std::move(result));
                    if (cli.progress_json_path.has_value()) {
                        write_progress_json(*cli.progress_json_path, progress);
                    }
                }
                continue;
            }

            auto result = execute_job(job);
            progress.completed_jobs += 1;
            progress.last_completed_job = result.id;
            if (result.ok) {
                progress.succeeded_jobs += 1;
            } else {
                progress.failed_jobs += 1;
            }
            results.push_back(std::move(result));
            if (cli.progress_json_path.has_value()) {
                write_progress_json(*cli.progress_json_path, progress);
            }
            ++index;
        }

        progress.status = progress.failed_jobs == 0 ? "completed" : "completed_with_errors";
        if (cli.progress_json_path.has_value()) {
            write_progress_json(*cli.progress_json_path, progress);
        }
        write_result_json(
            cli.result_json_path,
            cli.spec_path,
            started_at,
            std::chrono::system_clock::now(),
            results,
            progress,
            spec.retain_daemon_debug);
        return progress.failed_jobs == 0 ? 0 : 2;
    } catch (const std::exception &error) {
        progress.status = "error";
        progress.error = error.what();
        if (cli.progress_json_path.has_value()) {
            write_progress_json(*cli.progress_json_path, progress);
        }
        write_result_json(
            cli.result_json_path,
            cli.spec_path,
            started_at,
            std::chrono::system_clock::now(),
            results,
            progress,
            spec.retain_daemon_debug);
        throw;
    }
}
