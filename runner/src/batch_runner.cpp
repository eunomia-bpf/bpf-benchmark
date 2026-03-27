#include "micro_exec.hpp"

#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cctype>
#include <ctime>
#include <cstring>
#include <cerrno>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <ostream>
#include <sstream>
#include <string>
#include <string_view>
#include <mutex>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/un.h>
#include <unordered_map>
#include <unistd.h>
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
    std::string prepared_key;
    std::string prepared_ref;
    std::string prepared_group;
    bool release_prepared = true;
    cli_options options;
    std::filesystem::path object_path;
    uint32_t object_index = 0;
    std::string daemon_socket;
    std::vector<std::string> manifest_kinds;
    std::vector<std::string> target_names;
    std::vector<std::string> program_names_from_manifest;
    std::vector<std::string> sections_from_manifest;
    std::vector<std::string> prog_types;
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
    std::string payload_json = "null";
};

struct static_verify_attempt {
    std::string command;
    bool ok = false;
    std::string error;
};

struct static_verify_program_record {
    std::string status;
    std::optional<std::string> prog_name;
    std::optional<uint32_t> prog_id;
    std::optional<uint32_t> prog_type;
    std::optional<std::string> prog_type_name;
    bool verifier_accepted = false;
    bool applied = false;
    bool program_changed = false;
    std::vector<std::string> passes_applied;
    std::string daemon_status;
    std::string daemon_message;
    std::string daemon_error_message;
    std::optional<uint32_t> daemon_verifier_retries;
    std::vector<std::string> daemon_final_disabled_passes;
    std::optional<int64_t> insn_count_before;
    std::optional<int64_t> insn_count_after;
    std::optional<int64_t> code_size_before;
    std::optional<int64_t> code_size_after;
    std::optional<int64_t> insn_delta;
    std::optional<int64_t> daemon_submitted_insn_delta;
    std::optional<int64_t> code_delta_bytes;
    std::string before_xlated;
    std::string after_xlated;
    std::string before_jited;
    std::string after_jited;
    std::optional<int64_t> daemon_submitted_xlated_insn_count;
    std::optional<int64_t> daemon_runtime_final_xlated_insn_count;
    std::optional<int64_t> daemon_runtime_final_jited_size;
    bool after_xlated_count_mismatch = false;
    std::string after_xlated_count_mismatch_note;
    std::vector<static_verify_attempt> loadall_attempts;
    std::string load_command;
    std::string load_error;
    std::string error;
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

class prepared_kernel_store {
  public:
    void put(
        const std::string &key,
        prepared_kernel_handle handle,
        const std::string &group = std::string())
    {
        std::lock_guard<std::mutex> lock(mutex_);
        erase_unlocked(key);
        prepared_.insert_or_assign(key, stored_prepared {
                .handle = std::move(handle),
                .group = group,
            });
        if (!group.empty()) {
            groups_[group].push_back(key);
        }
    }

    prepared_kernel_handle get(const std::string &key) const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        const auto found = prepared_.find(key);
        if (found == prepared_.end()) {
            return {};
        }
        return found->second.handle;
    }

    void erase(const std::string &key)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        erase_unlocked(key);
    }

    void erase_group(const std::string &group)
    {
        if (group.empty()) {
            return;
        }
        std::lock_guard<std::mutex> lock(mutex_);
        const auto found = groups_.find(group);
        if (found == groups_.end()) {
            return;
        }
        const auto keys = found->second;
        groups_.erase(found);
        for (const auto &key : keys) {
            prepared_.erase(key);
        }
    }

    void clear()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        prepared_.clear();
        groups_.clear();
    }

  private:
    struct stored_prepared {
        prepared_kernel_handle handle;
        std::string group;
    };

    void erase_unlocked(const std::string &key)
    {
        const auto found = prepared_.find(key);
        if (found == prepared_.end()) {
            return;
        }
        const std::string group = found->second.group;
        if (!group.empty()) {
            const auto group_found = groups_.find(group);
            if (group_found != groups_.end()) {
                auto &keys = group_found->second;
                keys.erase(
                    std::remove(keys.begin(), keys.end(), key),
                    keys.end());
                if (keys.empty()) {
                    groups_.erase(group_found);
                }
            }
        }
        prepared_.erase(found);
    }

    mutable std::mutex mutex_;
    std::unordered_map<std::string, stored_prepared> prepared_;
    std::unordered_map<std::string, std::vector<std::string>> groups_;
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

void print_json_string_array_local(std::ostream &out, const std::vector<std::string> &values)
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

template <typename T>
void print_optional_json_field(std::ostream &out, const char *field_name, const std::optional<T> &value)
{
    out << ",\"" << field_name << "\":";
    if (value.has_value()) {
        out << *value;
    } else {
        out << "null";
    }
}

template <typename T>
__u64 ptr_to_u64_batch(T *ptr)
{
    return static_cast<__u64>(reinterpret_cast<uintptr_t>(ptr));
}

struct daemon_socket_response_batch {
    bool ok = false;
    bool applied = false;
    bool program_changed = false;
    std::string error;
    std::string status = "error";
    std::string message;
    std::string error_message;
    uint32_t total_sites_applied = 0;
    std::vector<std::string> passes_applied;
    int64_t insn_delta = 0;
    uint32_t verifier_retries = 0;
    std::vector<std::string> final_disabled_passes;
    std::optional<int64_t> final_insn_count;
    std::optional<int64_t> final_jited_size;
};

struct bpf_object_deleter_batch {
    void operator()(bpf_object *object) const
    {
        if (object != nullptr) {
            bpf_object__close(object);
        }
    }
};

using bpf_object_ptr_batch = std::unique_ptr<bpf_object, bpf_object_deleter_batch>;

std::string extract_json_string_batch(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":\"";
    const std::string pattern2 = "\"" + key + "\": \"";
    auto pos = json.find(pattern1);
    size_t value_start = std::string::npos;
    if (pos != std::string::npos) {
        value_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            value_start = pos + pattern2.size();
        }
    }
    if (value_start == std::string::npos) {
        return {};
    }
    const auto value_end = json.find('"', value_start);
    if (value_end == std::string::npos) {
        return {};
    }
    return json.substr(value_start, value_end - value_start);
}

int64_t extract_json_int_batch(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":";
    const std::string pattern2 = "\"" + key + "\": ";
    size_t value_start = std::string::npos;
    auto pos = json.find(pattern1);
    if (pos != std::string::npos) {
        value_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            value_start = pos + pattern2.size();
        }
    }
    if (value_start == std::string::npos) {
        return 0;
    }
    while (value_start < json.size() && json[value_start] == ' ') {
        ++value_start;
    }
    try {
        return std::stoll(json.substr(value_start));
    } catch (...) {
        return 0;
    }
}

bool extract_json_bool_batch(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":true";
    const std::string pattern2 = "\"" + key + "\": true";
    return json.find(pattern1) != std::string::npos || json.find(pattern2) != std::string::npos;
}

std::vector<std::string> extract_json_string_array_batch(const std::string &json, const std::string &key)
{
    std::vector<std::string> values;
    const std::string pattern1 = "\"" + key + "\":[";
    const std::string pattern2 = "\"" + key + "\": [";
    size_t array_start = std::string::npos;
    auto pos = json.find(pattern1);
    if (pos != std::string::npos) {
        array_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            array_start = pos + pattern2.size();
        }
    }
    if (array_start == std::string::npos) {
        return values;
    }
    const auto array_end = json.find(']', array_start);
    if (array_end == std::string::npos) {
        return values;
    }
    const std::string content = json.substr(array_start, array_end - array_start);
    size_t cursor = 0;
    while (true) {
        const auto q1 = content.find('"', cursor);
        if (q1 == std::string::npos) {
            break;
        }
        const auto q2 = content.find('"', q1 + 1);
        if (q2 == std::string::npos) {
            break;
        }
        values.push_back(content.substr(q1 + 1, q2 - q1 - 1));
        cursor = q2 + 1;
    }
    return values;
}

std::vector<std::string> extract_changed_passes_batch(const std::string &json)
{
    std::vector<std::string> values;
    auto passes_pos = json.find("\"passes\":[");
    if (passes_pos == std::string::npos) {
        passes_pos = json.find("\"passes\": [");
    }
    if (passes_pos == std::string::npos) {
        return values;
    }
    const auto array_open = json.find('[', passes_pos);
    if (array_open == std::string::npos) {
        return values;
    }
    int depth = 1;
    size_t array_close = array_open + 1;
    while (array_close < json.size() && depth > 0) {
        if (json[array_close] == '[') {
            ++depth;
        } else if (json[array_close] == ']') {
            --depth;
        }
        ++array_close;
    }
    size_t cursor = array_open;
    while (true) {
        const auto object_start = json.find('{', cursor + 1);
        if (object_start == std::string::npos || object_start >= array_close) {
            break;
        }
        int object_depth = 1;
        size_t object_end = object_start + 1;
        while (object_end < json.size() && object_depth > 0) {
            if (json[object_end] == '{') {
                ++object_depth;
            } else if (json[object_end] == '}') {
                --object_depth;
            }
            ++object_end;
        }
        if (object_depth != 0) {
            break;
        }
        const std::string pass_object = json.substr(object_start, object_end - object_start);
        if (extract_json_bool_batch(pass_object, "changed")) {
            const auto pass_name = extract_json_string_batch(pass_object, "pass_name");
            if (!pass_name.empty()) {
                values.push_back(pass_name);
            }
        }
        cursor = object_end;
    }
    return values;
}

daemon_socket_response_batch daemon_socket_optimize_batch(
    const std::string &socket_path,
    uint32_t prog_id)
{
    daemon_socket_response_batch response;

    const int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        response.error = "socket() failed: " + std::string(strerror(errno));
        return response;
    }

    sockaddr_un address = {};
    address.sun_family = AF_UNIX;
    if (socket_path.size() >= sizeof(address.sun_path)) {
        close(fd);
        response.error = "socket path too long";
        return response;
    }
    std::strncpy(address.sun_path, socket_path.c_str(), sizeof(address.sun_path) - 1);
    if (connect(fd, reinterpret_cast<sockaddr *>(&address), sizeof(address)) != 0) {
        close(fd);
        response.error = "connect() failed: " + std::string(strerror(errno));
        return response;
    }

    const std::string request =
        "{\"cmd\":\"optimize\",\"prog_id\":" + std::to_string(prog_id) + "}\n";
    if (write(fd, request.c_str(), request.size()) < 0) {
        close(fd);
        response.error = "write() failed: " + std::string(strerror(errno));
        return response;
    }

    std::string line;
    char byte = 0;
    while (true) {
        const ssize_t read_result = read(fd, &byte, 1);
        if (read_result <= 0 || byte == '\n') {
            break;
        }
        line.push_back(byte);
    }
    close(fd);
    if (line.empty()) {
        response.error = "empty response from daemon";
        return response;
    }

    response.status = extract_json_string_batch(line, "status");
    response.ok = response.status == "ok";
    response.message = extract_json_string_batch(line, "message");
    response.error_message = extract_json_string_batch(line, "error_message");
    if (!response.ok) {
        response.error = !response.error_message.empty()
            ? response.error_message
            : (!response.message.empty() ? response.message : line);
        return response;
    }

    auto summary_pos = line.find("\"summary\":");
    if (summary_pos != std::string::npos) {
        const auto brace = line.find('{', summary_pos);
        if (brace != std::string::npos) {
            int depth = 1;
            size_t end = brace + 1;
            while (end < line.size() && depth > 0) {
                if (line[end] == '{') {
                    ++depth;
                } else if (line[end] == '}') {
                    --depth;
                }
                ++end;
            }
            const std::string summary = line.substr(brace, end - brace);
            response.applied = extract_json_bool_batch(summary, "applied");
            response.program_changed = extract_json_bool_batch(summary, "program_changed");
            response.total_sites_applied = static_cast<uint32_t>(
                extract_json_int_batch(summary, "total_sites_applied"));
            response.verifier_retries = static_cast<uint32_t>(
                extract_json_int_batch(summary, "verifier_retries"));
            response.final_disabled_passes =
                extract_json_string_array_batch(summary, "final_disabled_passes");
        }
    }

    auto program_pos = line.find("\"program\":");
    if (program_pos != std::string::npos) {
        const auto brace = line.find('{', program_pos);
        if (brace != std::string::npos) {
            int depth = 1;
            size_t end = brace + 1;
            while (end < line.size() && depth > 0) {
                if (line[end] == '{') {
                    ++depth;
                } else if (line[end] == '}') {
                    --depth;
                }
                ++end;
            }
            const std::string program_json = line.substr(brace, end - brace);
            response.insn_delta = extract_json_int_batch(program_json, "insn_delta");
            const auto final_insn_count = extract_json_int_batch(program_json, "final_insn_count");
            const auto final_jited_size = extract_json_int_batch(program_json, "final_jited_size");
            if (final_insn_count > 0) {
                response.final_insn_count = final_insn_count;
            }
            if (final_jited_size > 0) {
                response.final_jited_size = final_jited_size;
            }
        }
    }

    response.passes_applied = extract_changed_passes_batch(line);
    return response;
}

bpf_prog_info load_prog_info_batch(int program_fd)
{
    bpf_prog_info info = {};
    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64_batch(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD failed: " + std::string(strerror(errno)));
    }
    return info;
}

std::vector<uint8_t> load_jited_program_batch(int program_fd, uint32_t length)
{
    if (length == 0) {
        return {};
    }
    std::vector<uint8_t> bytes(length);
    bpf_prog_info info = {};
    info.jited_prog_len = length;
    info.jited_prog_insns = ptr_to_u64_batch(bytes.data());
    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64_batch(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD (JIT dump) failed: " + std::string(strerror(errno)));
    }
    bytes.resize(info.jited_prog_len);
    return bytes;
}

std::vector<uint8_t> load_xlated_program_batch(int program_fd, uint32_t length)
{
    if (length == 0) {
        return {};
    }
    std::vector<uint8_t> bytes(length);
    bpf_prog_info info = {};
    info.xlated_prog_len = length;
    info.xlated_prog_insns = ptr_to_u64_batch(bytes.data());
    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64_batch(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD (xlated dump) failed: " + std::string(strerror(errno)));
    }
    bytes.resize(info.xlated_prog_len);
    return bytes;
}

std::string sanitize_component_batch(std::string_view text)
{
    std::string output;
    output.reserve(text.size());
    for (const char ch : text) {
        if (std::isalnum(static_cast<unsigned char>(ch)) || ch == '_' || ch == '-') {
            output.push_back(ch);
        } else {
            output.push_back('-');
        }
    }
    while (!output.empty() && (output.back() == '-' || output.back() == '.')) {
        output.pop_back();
    }
    while (!output.empty() && (output.front() == '-' || output.front() == '.')) {
        output.erase(output.begin());
    }
    return output.empty() ? "object" : output;
}

std::string format_byte_dump_batch(const std::vector<uint8_t> &bytes, size_t width, bool annotate_pc)
{
    if (bytes.empty()) {
        return {};
    }
    std::ostringstream out;
    for (size_t offset = 0; offset < bytes.size(); offset += width) {
        if (offset != 0) {
            out << "\n";
        }
        if (annotate_pc) {
            out << std::setw(4) << (offset / width) << ": ";
        }
        const size_t line_width = std::min(width, bytes.size() - offset);
        for (size_t index = 0; index < line_width; ++index) {
            if (index != 0) {
                out << " ";
            }
            out << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<unsigned int>(bytes[offset + index])
                << std::dec << std::setfill(' ');
        }
    }
    return out.str();
}

std::string program_name_from_info_batch(const bpf_prog_info &info)
{
    const char *name = reinterpret_cast<const char *>(info.name);
    if (name == nullptr || name[0] == '\0') {
        return {};
    }
    return std::string(name);
}

std::optional<enum bpf_prog_type> prog_type_from_string_batch(const std::string &value)
{
    static const std::pair<std::string_view, enum bpf_prog_type> mapping[] = {
        {"xdp", BPF_PROG_TYPE_XDP},
        {"sched_cls", BPF_PROG_TYPE_SCHED_CLS},
        {"sched_act", BPF_PROG_TYPE_SCHED_ACT},
        {"kprobe", BPF_PROG_TYPE_KPROBE},
        {"tracepoint", BPF_PROG_TYPE_TRACEPOINT},
        {"raw_tracepoint", BPF_PROG_TYPE_RAW_TRACEPOINT},
        {"raw_tp", BPF_PROG_TYPE_RAW_TRACEPOINT},
        {"tracing", BPF_PROG_TYPE_TRACING},
        {"perf_event", BPF_PROG_TYPE_PERF_EVENT},
        {"socket_filter", BPF_PROG_TYPE_SOCKET_FILTER},
        {"cgroup_skb", BPF_PROG_TYPE_CGROUP_SKB},
        {"cgroup_sock", BPF_PROG_TYPE_CGROUP_SOCK},
        {"cgroup_device", BPF_PROG_TYPE_CGROUP_DEVICE},
        {"cgroup_sock_addr", BPF_PROG_TYPE_CGROUP_SOCK_ADDR},
        {"cgroup_sysctl", BPF_PROG_TYPE_CGROUP_SYSCTL},
        {"cgroup_sockopt", BPF_PROG_TYPE_CGROUP_SOCKOPT},
        {"sk_msg", BPF_PROG_TYPE_SK_MSG},
        {"sk_skb", BPF_PROG_TYPE_SK_SKB},
        {"flow_dissector", BPF_PROG_TYPE_FLOW_DISSECTOR},
        {"lwt_in", BPF_PROG_TYPE_LWT_IN},
        {"lwt_out", BPF_PROG_TYPE_LWT_OUT},
        {"lwt_xmit", BPF_PROG_TYPE_LWT_XMIT},
        {"lwt_seg6local", BPF_PROG_TYPE_LWT_SEG6LOCAL},
        {"sockops", BPF_PROG_TYPE_SOCK_OPS},
        {"struct_ops", BPF_PROG_TYPE_STRUCT_OPS},
        {"lsm", BPF_PROG_TYPE_LSM},
        {"syscall", BPF_PROG_TYPE_SYSCALL},
    };
    for (const auto &[name, prog_type] : mapping) {
        if (name == value) {
            return prog_type;
        }
    }
    return std::nullopt;
}

std::string prog_type_name_from_enum_batch(enum bpf_prog_type prog_type)
{
    static const std::pair<enum bpf_prog_type, std::string_view> mapping[] = {
        {BPF_PROG_TYPE_SOCKET_FILTER, "socket_filter"},
        {BPF_PROG_TYPE_KPROBE, "kprobe"},
        {BPF_PROG_TYPE_SCHED_CLS, "sched_cls"},
        {BPF_PROG_TYPE_SCHED_ACT, "sched_act"},
        {BPF_PROG_TYPE_TRACEPOINT, "tracepoint"},
        {BPF_PROG_TYPE_XDP, "xdp"},
        {BPF_PROG_TYPE_PERF_EVENT, "perf_event"},
        {BPF_PROG_TYPE_CGROUP_SKB, "cgroup_skb"},
        {BPF_PROG_TYPE_CGROUP_SOCK, "cgroup_sock"},
        {BPF_PROG_TYPE_LWT_IN, "lwt_in"},
        {BPF_PROG_TYPE_LWT_OUT, "lwt_out"},
        {BPF_PROG_TYPE_LWT_XMIT, "lwt_xmit"},
        {BPF_PROG_TYPE_SOCK_OPS, "sock_ops"},
        {BPF_PROG_TYPE_SK_SKB, "sk_skb"},
        {BPF_PROG_TYPE_CGROUP_DEVICE, "cgroup_device"},
        {BPF_PROG_TYPE_SK_MSG, "sk_msg"},
        {BPF_PROG_TYPE_RAW_TRACEPOINT, "raw_tracepoint"},
        {BPF_PROG_TYPE_CGROUP_SOCK_ADDR, "cgroup_sock_addr"},
        {BPF_PROG_TYPE_LWT_SEG6LOCAL, "lwt_seg6local"},
        {BPF_PROG_TYPE_LIRC_MODE2, "lirc_mode2"},
        {BPF_PROG_TYPE_SK_REUSEPORT, "sk_reuseport"},
        {BPF_PROG_TYPE_FLOW_DISSECTOR, "flow_dissector"},
        {BPF_PROG_TYPE_CGROUP_SYSCTL, "cgroup_sysctl"},
        {BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE, "raw_tracepoint_writable"},
        {BPF_PROG_TYPE_CGROUP_SOCKOPT, "cgroup_sockopt"},
        {BPF_PROG_TYPE_TRACING, "tracing"},
        {BPF_PROG_TYPE_STRUCT_OPS, "struct_ops"},
        {BPF_PROG_TYPE_EXT, "ext"},
        {BPF_PROG_TYPE_LSM, "lsm"},
        {BPF_PROG_TYPE_SK_LOOKUP, "sk_lookup"},
        {BPF_PROG_TYPE_SYSCALL, "syscall"},
        {BPF_PROG_TYPE_NETFILTER, "netfilter"},
    };
    for (const auto &[value, name] : mapping) {
        if (value == prog_type) {
            return std::string(name);
        }
    }
    return {};
}

std::string serialize_load_attempts_json(const std::vector<static_verify_attempt> &attempts)
{
    std::ostringstream out;
    out << "[";
    for (size_t index = 0; index < attempts.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        out
            << "{"
            << "\"command\":\"" << json_escape(attempts[index].command) << "\","
            << "\"returncode\":" << (attempts[index].ok ? 0 : 1) << ","
            << "\"stdout_tail\":\"\","
            << "\"stderr_tail\":\"" << json_escape(attempts[index].error) << "\""
            << "}";
    }
    out << "]";
    return out.str();
}

std::string serialize_static_verify_record_json(const static_verify_program_record &record)
{
    std::ostringstream out;
    out
        << "{"
        << "\"status\":\"" << json_escape(record.status) << "\","
        << "\"prog_name\":";
    if (record.prog_name.has_value()) {
        out << "\"" << json_escape(*record.prog_name) << "\"";
    } else {
        out << "null";
    }
    print_optional_json_field(out, "prog_id", record.prog_id);
    print_optional_json_field(out, "prog_type", record.prog_type);
    out << ",\"prog_type_name\":";
    if (record.prog_type_name.has_value()) {
        out << "\"" << json_escape(*record.prog_type_name) << "\"";
    } else {
        out << "null";
    }
    out
        << ",\"verifier_accepted\":"
        << (record.status == "skip_load" ? "null" : (record.verifier_accepted ? "true" : "false"))
        << ",\"applied\":" << (record.applied ? "true" : "false")
        << ",\"program_changed\":" << (record.program_changed ? "true" : "false")
        << ",\"passes_applied\":";
    print_json_string_array_local(out, record.passes_applied);
    out
        << ",\"daemon_status\":\"" << json_escape(record.daemon_status) << "\""
        << ",\"daemon_message\":\"" << json_escape(record.daemon_message) << "\""
        << ",\"daemon_error_message\":\"" << json_escape(record.daemon_error_message) << "\"";
    print_optional_json_field(out, "daemon_verifier_retries", record.daemon_verifier_retries);
    out << ",\"daemon_final_disabled_passes\":";
    print_json_string_array_local(out, record.daemon_final_disabled_passes);
    print_optional_json_field(out, "insn_count_before", record.insn_count_before);
    print_optional_json_field(out, "insn_count_after", record.insn_count_after);
    print_optional_json_field(out, "code_size_before", record.code_size_before);
    print_optional_json_field(out, "code_size_after", record.code_size_after);
    out
        << ",\"before_jited_size\":";
    if (record.code_size_before.has_value()) {
        out << *record.code_size_before;
    } else {
        out << "null";
    }
    out << ",\"after_jited_size\":";
    if (record.code_size_after.has_value()) {
        out << *record.code_size_after;
    } else {
        out << "null";
    }
    print_optional_json_field(out, "insn_delta", record.insn_delta);
    print_optional_json_field(out, "daemon_submitted_insn_delta", record.daemon_submitted_insn_delta);
    print_optional_json_field(out, "code_delta_bytes", record.code_delta_bytes);
    out
        << ",\"before_xlated\":\"" << json_escape(record.before_xlated) << "\""
        << ",\"after_xlated\":\"" << json_escape(record.after_xlated) << "\""
        << ",\"before_jited\":\"" << json_escape(record.before_jited) << "\""
        << ",\"after_jited\":\"" << json_escape(record.after_jited) << "\"";
    print_optional_json_field(out, "daemon_submitted_xlated_insn_count", record.daemon_submitted_xlated_insn_count);
    print_optional_json_field(out, "daemon_runtime_final_xlated_insn_count", record.daemon_runtime_final_xlated_insn_count);
    print_optional_json_field(out, "daemon_runtime_final_jited_size", record.daemon_runtime_final_jited_size);
    out
        << ",\"after_xlated_count_mismatch\":"
        << (record.after_xlated_count_mismatch ? "true" : "false")
        << ",\"after_xlated_count_mismatch_note\":";
    if (!record.after_xlated_count_mismatch_note.empty()) {
        out << "\"" << json_escape(record.after_xlated_count_mismatch_note) << "\"";
    } else {
        out << "null";
    }
    out
        << ",\"load_command\":\"" << json_escape(record.load_command) << "\""
        << ",\"loadall_attempts\":"
        << serialize_load_attempts_json(record.loadall_attempts)
        << ",\"load_error\":\"" << json_escape(record.load_error) << "\""
        << ",\"error\":\"" << json_escape(record.error) << "\""
        << "}";
    return out.str();
}

std::string serialize_static_verify_payload_json(
    const std::string &object_status,
    const std::vector<static_verify_program_record> &records)
{
    std::ostringstream out;
    out << "{"
        << "\"object_status\":\"" << json_escape(object_status) << "\","
        << "\"records\":[";
    for (size_t index = 0; index < records.size(); ++index) {
        if (index != 0) {
            out << ",";
        }
        out << serialize_static_verify_record_json(records[index]);
    }
    out << "]}";
    return out.str();
}

void validate_batch_job(const batch_job &job)
{
    if (job.execution != "serial" && job.execution != "parallel") {
        fail("unsupported batch job execution mode: " + job.execution);
    }
    if (job.type == "test_run") {
        if (job.options.program.empty()) {
            fail("batch job is missing program path: " + job.id);
        }
        if (job.options.command != "run-kernel" &&
            job.options.command != "run-kernel-attach" &&
            job.options.command != "run-llvmbpf") {
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
        if (!job.prepared_key.empty() && !job.prepared_ref.empty()) {
            fail("batch job cannot set both prepared_key and prepared_ref: " + job.id);
        }
        if (!job.prepared_key.empty()) {
            if (job.options.command != "run-kernel" &&
                job.options.command != "run-kernel-attach") {
                fail("prepared_key is only supported for prepared kernel jobs: " + job.id);
            }
            if (!job.options.compile_only) {
                fail("prepared_key requires compile_only=true: " + job.id);
            }
        }
        if (!job.prepared_ref.empty()) {
            if (job.options.command != "run-kernel" &&
                job.options.command != "run-kernel-attach") {
                fail("prepared_ref is only supported for prepared kernel jobs: " + job.id);
            }
        }
        if (!job.prepared_group.empty() &&
            job.prepared_key.empty() &&
            job.prepared_ref.empty()) {
            fail("prepared_group requires prepared_key or prepared_ref: " + job.id);
        }
        return;
    }
    if (job.type == "static_verify_object") {
        if (job.object_path.empty()) {
            fail("static_verify_object job is missing object path: " + job.id);
        }
        if (job.daemon_socket.empty()) {
            fail("static_verify_object job is missing daemon_socket: " + job.id);
        }
        return;
    }
    fail("unsupported batch job type: " + job.type);
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
    job.prepared_key = optional_scalar_string(node, "prepared_key");
    job.prepared_ref = optional_scalar_string(node, "prepared_ref");
    job.prepared_group = optional_scalar_string(node, "prepared_group");
    job.release_prepared = optional_bool(node, "release_prepared", true);

    if (job.type == "static_verify_object") {
        job.object_path = std::filesystem::path(require_scalar_string(node["object"], "object"));
        job.object_index = optional_u32(node, "object_index", 0);
        job.daemon_socket = optional_scalar_string(node, "daemon_socket");
        job.manifest_kinds = optional_string_list(node, "manifest_kinds");
        job.target_names = optional_string_list(node, "target_names");
        job.program_names_from_manifest = optional_string_list(node, "program_names_from_manifest");
        job.sections_from_manifest = optional_string_list(node, "sections_from_manifest");
        job.prog_types = optional_string_list(node, "prog_types");
        validate_batch_job(job);
        return job;
    }

    job.runtime = require_scalar_string(node["runtime"], "runtime");

    cli_options options;
    const std::string runtime = job.runtime;
    if (runtime == "llvmbpf") {
        options.command = "run-llvmbpf";
    } else if (runtime == "kernel") {
        options.command = "run-kernel";
    } else if (runtime == "kernel-rejit") {
        options.command = "run-kernel";
        options.rejit = true;
    } else if (runtime == "kernel-attach") {
        options.command = "run-kernel-attach";
        options.attach_mode = true;
    } else if (runtime == "kernel-attach-rejit") {
        options.command = "run-kernel-attach";
        options.attach_mode = true;
        options.rejit = true;
    } else {
        fail("unsupported batch runtime for job " + job.id + ": " + runtime);
    }

    options.program = std::filesystem::path(require_scalar_string(node["program"], "program"));
    options.program_name = optional_string(node, "program_name");
    options.memory = optional_path(node, "memory");
    options.fixture_path = optional_path(node, "fixture_path");
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
    options.attach_mode = optional_bool(node, "attach_mode", options.attach_mode);
    options.workload_iterations = optional_u32(node, "workload_iterations", options.workload_iterations);
    options.workload_type = optional_scalar_string(node, "workload_type", options.workload_type);
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

std::string libbpf_error_string_batch(int error_code)
{
    char buffer[256] = {};
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    return std::string(buffer);
}

std::optional<enum bpf_prog_type> unique_prog_type_hint_batch(const std::vector<std::string> &prog_types)
{
    std::optional<std::string> unique_name;
    for (const auto &prog_type : prog_types) {
        if (prog_type.empty()) {
            continue;
        }
        if (!unique_name.has_value()) {
            unique_name = prog_type;
            continue;
        }
        if (*unique_name != prog_type) {
            return std::nullopt;
        }
    }
    if (!unique_name.has_value()) {
        return std::nullopt;
    }
    return prog_type_from_string_batch(*unique_name);
}

std::pair<bpf_object_ptr_batch, std::string> try_open_static_verify_object(
    const std::filesystem::path &object_path)
{
    bpf_object *raw_object = bpf_object__open_file(object_path.c_str(), nullptr);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        return {
            bpf_object_ptr_batch(),
            "bpf_object__open_file failed: " + libbpf_error_string_batch(open_error),
        };
    }
    return {bpf_object_ptr_batch(raw_object), std::string()};
}

std::pair<bpf_object_ptr_batch, std::vector<static_verify_attempt>> load_static_verify_object(
    const batch_job &job)
{
    std::vector<static_verify_attempt> attempts;

    {
        auto [object, open_error] = try_open_static_verify_object(job.object_path);
        if (!object) {
            attempts.push_back({
                .command = "libbpf_object__open_file",
                .ok = false,
                .error = std::move(open_error),
            });
            return {bpf_object_ptr_batch(), attempts};
        }
        const int load_error = bpf_object__load(object.get());
        attempts.push_back({
            .command = "libbpf_object__load",
            .ok = load_error == 0,
            .error = load_error == 0 ? std::string() : libbpf_error_string_batch(-load_error),
        });
        if (load_error == 0) {
            return {std::move(object), attempts};
        }
    }

    const auto prog_type_hint = unique_prog_type_hint_batch(job.prog_types);
    if (prog_type_hint.has_value()) {
        auto [object, open_error] = try_open_static_verify_object(job.object_path);
        if (!object) {
            attempts.push_back({
                .command = "libbpf_object__open_file type_hint",
                .ok = false,
                .error = std::move(open_error),
            });
            return {bpf_object_ptr_batch(), attempts};
        }
        bpf_program *program = nullptr;
        while ((program = bpf_object__next_program(object.get(), program)) != nullptr) {
            const int type_error = bpf_program__set_type(program, *prog_type_hint);
            if (type_error != 0) {
                fail("bpf_program__set_type failed: " + libbpf_error_string_batch(-type_error));
            }
        }
        const int load_error = bpf_object__load(object.get());
        std::string command = "libbpf_object__load type_hint";
        attempts.push_back({
            .command = std::move(command),
            .ok = load_error == 0,
            .error = load_error == 0 ? std::string() : libbpf_error_string_batch(-load_error),
        });
        if (load_error == 0) {
            return {std::move(object), attempts};
        }
    }

    return {bpf_object_ptr_batch(), attempts};
}

static_verify_program_record make_skip_load_record(
    const std::vector<static_verify_attempt> &attempts,
    std::string load_error)
{
    static_verify_program_record record;
    record.status = "skip_load";
    record.load_command = attempts.empty() ? "libbpf_object__load" : attempts.back().command;
    record.loadall_attempts = attempts;
    record.load_error = std::move(load_error);
    record.daemon_status = "skip_load";
    return record;
}

static_verify_program_record make_error_record(
    std::string error,
    const std::vector<static_verify_attempt> &attempts = {},
    std::string load_command = {})
{
    static_verify_program_record record;
    record.status = "error";
    record.daemon_status = "error";
    record.error = std::move(error);
    record.loadall_attempts = attempts;
    record.load_command = std::move(load_command);
    return record;
}

static_verify_program_record execute_static_verify_program(
    const batch_job &job,
    const std::vector<static_verify_attempt> &attempts,
    const std::string &load_command,
    bpf_program *program)
{
    static_verify_program_record record;
    record.status = "ok";
    record.loadall_attempts = attempts;
    record.load_command = load_command;

    const int program_fd = bpf_program__fd(program);
    if (program_fd < 0) {
        record.status = "error";
        record.error = "unable to obtain program fd";
        record.daemon_status = "error";
        return record;
    }

    const auto before_info = load_prog_info_batch(program_fd);
    record.prog_id = before_info.id;
    record.prog_type = before_info.type;
    const std::string prog_type_name = prog_type_name_from_enum_batch(static_cast<enum bpf_prog_type>(before_info.type));
    if (!prog_type_name.empty()) {
        record.prog_type_name = prog_type_name;
    }
    std::string program_name = program_name_from_info_batch(before_info);
    if (program_name.empty()) {
        const char *fallback_name = bpf_program__name(program);
        if (fallback_name != nullptr) {
            program_name = fallback_name;
        }
    }
    if (!program_name.empty()) {
        record.prog_name = program_name;
    }

    const auto before_xlated_bytes = load_xlated_program_batch(program_fd, before_info.xlated_prog_len);
    const auto before_jited_bytes = load_jited_program_batch(program_fd, before_info.jited_prog_len);
    record.before_xlated = format_byte_dump_batch(before_xlated_bytes, sizeof(bpf_insn), true);
    record.before_jited = format_byte_dump_batch(before_jited_bytes, 16, false);
    record.insn_count_before = static_cast<int64_t>(before_info.xlated_prog_len / sizeof(bpf_insn));
    record.code_size_before = static_cast<int64_t>(before_info.jited_prog_len);

    const auto daemon_response = daemon_socket_optimize_batch(job.daemon_socket, before_info.id);
    record.daemon_status = daemon_response.status;
    record.daemon_message = daemon_response.message;
    record.daemon_error_message = daemon_response.error_message;
    record.daemon_verifier_retries = daemon_response.verifier_retries;
    record.daemon_final_disabled_passes = daemon_response.final_disabled_passes;
    record.passes_applied = daemon_response.passes_applied;
    record.applied = daemon_response.applied;
    record.program_changed = daemon_response.program_changed;

    if (!daemon_response.ok) {
        record.status = "error";
        record.error = daemon_response.error;
        return record;
    }

    const auto after_info = load_prog_info_batch(program_fd);
    const auto after_xlated_bytes = load_xlated_program_batch(program_fd, after_info.xlated_prog_len);
    const auto after_jited_bytes = load_jited_program_batch(program_fd, after_info.jited_prog_len);
    record.after_xlated = format_byte_dump_batch(after_xlated_bytes, sizeof(bpf_insn), true);
    record.after_jited = format_byte_dump_batch(after_jited_bytes, 16, false);
    record.insn_count_after = static_cast<int64_t>(after_info.xlated_prog_len / sizeof(bpf_insn));
    record.code_size_after = static_cast<int64_t>(after_info.jited_prog_len);
    record.verifier_accepted = true;
    record.insn_delta = record.insn_count_after.value_or(0) - record.insn_count_before.value_or(0);
    record.code_delta_bytes = record.code_size_after.value_or(0) - record.code_size_before.value_or(0);
    record.daemon_submitted_insn_delta = daemon_response.insn_delta;
    record.daemon_submitted_xlated_insn_count = daemon_response.final_insn_count;
    record.daemon_runtime_final_xlated_insn_count = daemon_response.final_insn_count;
    record.daemon_runtime_final_jited_size = daemon_response.final_jited_size;
    record.after_xlated_count_mismatch =
        daemon_response.final_insn_count.has_value() &&
        record.insn_count_after.has_value() &&
        *record.insn_count_after != *daemon_response.final_insn_count;
    if (record.after_xlated_count_mismatch) {
        record.after_xlated_count_mismatch_note =
            "runtime xlated count differs from daemon-submitted final_insn_count";
    }
    return record;
}

batch_job_result execute_static_verify_object_job(const batch_job &job)
{
    batch_job_result result;
    result.id = job.id;
    result.type = job.type;
    result.execution = job.execution;

    auto [object, attempts] = load_static_verify_object(job);
    if (!object) {
        const std::string load_error =
            attempts.empty() ? "unable to load object" : attempts.back().error;
        std::vector<static_verify_program_record> records = {
            make_skip_load_record(attempts, load_error),
        };
        result.ok = true;
        result.payload_json = serialize_static_verify_payload_json("skip_load", records);
        return result;
    }

    std::vector<static_verify_program_record> records;
    bpf_program *program = nullptr;
    while ((program = bpf_object__next_program(object.get(), program)) != nullptr) {
        if (bpf_program__fd(program) < 0) {
            continue;
        }
        try {
            records.push_back(
                execute_static_verify_program(job, attempts, attempts.back().command, program));
        } catch (const std::exception &error) {
            static_verify_program_record record;
            record.status = "error";
            const char *name = bpf_program__name(program);
            if (name != nullptr) {
                record.prog_name = std::string(name);
            }
            record.error = error.what();
            record.daemon_status = "error";
            record.loadall_attempts = attempts;
            record.load_command = attempts.empty() ? "libbpf_object__load" : attempts.back().command;
            records.push_back(std::move(record));
        }
    }

    if (records.empty()) {
        records.push_back(make_skip_load_record(
            attempts,
            "libbpf object load succeeded but produced no loaded programs"));
        result.ok = true;
        result.payload_json = serialize_static_verify_payload_json("skip_load", records);
        return result;
    }

    const bool all_ok = std::all_of(records.begin(), records.end(), [](const auto &record) {
        return record.status == "ok";
    });
    result.ok = true;
    result.payload_json = serialize_static_verify_payload_json(all_ok ? "ok" : "partial", records);
    return result;
}

batch_job_result execute_job(
    const batch_job &job,
    prepared_kernel_store &prepared_store)
{
    batch_job_result result;
    result.id = job.id;
    result.type = job.type;
    result.execution = job.execution;
    result.runtime = job.runtime;

    const auto started = clock_type::now();
    try {
        if (job.type == "static_verify_object") {
            result = execute_static_verify_object_job(job);
            result.wall_time_ns = elapsed_ns(started, clock_type::now());
            return result;
        }
        if (job.options.command == "run-llvmbpf") {
            result.samples = {run_llvmbpf(job.options)};
        } else if (job.options.command == "run-kernel-attach") {
            result.samples = run_kernel_attach(job.options);
        } else if (job.options.command == "run-kernel") {
            if (!job.prepared_ref.empty()) {
                auto prepared = prepared_store.get(job.prepared_ref);
                if (!prepared) {
                    fail("missing prepared kernel state for ref: " + job.prepared_ref);
                }
                result.samples = run_prepared_kernel(prepared, job.options);
                if (job.release_prepared && job.prepared_group.empty()) {
                    prepared_store.erase(job.prepared_ref);
                }
            } else if (!job.prepared_key.empty()) {
                auto prepared = prepare_kernel(job.options);
                result.samples = {summarize_prepared_kernel_compile(prepared)};
                prepared_store.put(job.prepared_key, std::move(prepared), job.prepared_group);
            } else {
                result.samples = run_kernel(job.options);
            }
        } else {
            fail("unsupported batch command: " + job.options.command);
        }
        result.ok = true;
    } catch (const std::exception &error) {
        result.ok = false;
        result.error = error.what();
        if (job.type == "static_verify_object" && result.payload_json == "null") {
            std::vector<static_verify_program_record> records = {
                make_error_record(result.error),
            };
            result.payload_json = serialize_static_verify_payload_json("partial", records);
        }
    }
    result.wall_time_ns = elapsed_ns(started, clock_type::now());
    return result;
}

std::vector<batch_job_result> execute_parallel_chunk(
    const std::vector<batch_job> &jobs,
    size_t max_parallel_jobs,
    prepared_kernel_store &prepared_store)
{
    std::vector<batch_job_result> results(jobs.size());
    std::atomic<size_t> next_index {0};
    const size_t worker_count = std::max<size_t>(
        1,
        std::min(max_parallel_jobs, jobs.size()));

    std::vector<std::thread> workers;
    workers.reserve(worker_count);
    for (size_t worker = 0; worker < worker_count; ++worker) {
        workers.emplace_back([&jobs, &results, &next_index, &prepared_store]() {
            while (true) {
                const size_t index = next_index.fetch_add(1);
                if (index >= jobs.size()) {
                    return;
                }
                results[index] = execute_job(jobs[index], prepared_store);
            }
        });
    }

    for (auto &worker : workers) {
        worker.join();
    }
    return results;
}

std::string group_for_chunk(const std::vector<batch_job> &jobs)
{
    std::string group;
    for (const auto &job : jobs) {
        if (job.prepared_group.empty()) {
            continue;
        }
        if (group.empty()) {
            group = job.prepared_group;
            continue;
        }
        if (group != job.prepared_group) {
            fail("parallel chunk contains multiple prepared_group values");
        }
    }
    return group;
}

void flush_prepared_group(
    std::string &active_group,
    const std::string &next_group,
    prepared_kernel_store &prepared_store)
{
    if (!active_group.empty() && active_group != next_group) {
        prepared_store.erase_group(active_group);
        active_group.clear();
    }
    if (!next_group.empty()) {
        active_group = next_group;
    }
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
            << "\"wall_time_ns\":" << result.wall_time_ns;
        if (result.type == "test_run") {
            out << ",\"samples\":";
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
        } else {
            out << ",\"payload\":" << result.payload_json;
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
    prepared_kernel_store prepared_store;
    std::string active_prepared_group;

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
                flush_prepared_group(
                    active_prepared_group,
                    group_for_chunk(chunk),
                    prepared_store);
                auto chunk_results = execute_parallel_chunk(
                    chunk,
                    spec.max_parallel_jobs,
                    prepared_store);
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

            flush_prepared_group(
                active_prepared_group,
                job.prepared_group,
                prepared_store);
            auto result = execute_job(job, prepared_store);
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

        if (!active_prepared_group.empty()) {
            prepared_store.erase_group(active_prepared_group);
        }
        prepared_store.clear();

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
