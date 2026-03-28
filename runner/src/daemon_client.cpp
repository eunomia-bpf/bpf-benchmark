#include "daemon_client.hpp"

#include "json_parser.hpp"

#include <cerrno>
#include <cstring>
#include <exception>
#include <string>
#include <string_view>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <unistd.h>

namespace {

constexpr int kDaemonSocketTimeoutSeconds = 30;

std::string json_escape_request(std::string_view input)
{
    std::string escaped;
    escaped.reserve(input.size());
    for (const char ch : input) {
        switch (ch) {
        case '\\':
            escaped += "\\\\";
            break;
        case '"':
            escaped += "\\\"";
            break;
        case '\n':
            escaped += "\\n";
            break;
        case '\r':
            escaped += "\\r";
            break;
        case '\t':
            escaped += "\\t";
            break;
        default:
            escaped.push_back(ch);
            break;
        }
    }
    return escaped;
}

std::string build_daemon_optimize_request(
    uint32_t prog_id,
    const std::vector<std::string> &enabled_passes,
    bool enabled_passes_specified)
{
    std::string request =
        "{\"cmd\":\"optimize\",\"prog_id\":" + std::to_string(prog_id);
    if (enabled_passes_specified) {
        request += ",\"enabled_passes\":[";
        for (size_t index = 0; index < enabled_passes.size(); ++index) {
            if (index != 0) {
                request += ",";
            }
            request += "\"" + json_escape_request(enabled_passes[index]) + "\"";
        }
        request += "]";
    }
    request += "}\n";
    return request;
}

bool is_socket_timeout_error(int error_code)
{
    return error_code == EAGAIN ||
           error_code == EWOULDBLOCK ||
           error_code == ETIMEDOUT ||
           error_code == EINPROGRESS;
}

std::string format_socket_error(std::string_view operation, int error_code)
{
    if (is_socket_timeout_error(error_code)) {
        return std::string(operation) + "() timed out after " +
               std::to_string(kDaemonSocketTimeoutSeconds) + "s";
    }
    return std::string(operation) + "() failed: " + std::string(strerror(error_code));
}

bool set_socket_timeout(int fd, int option_name, const char *option_label, std::string &error)
{
    const timeval timeout {
        .tv_sec = kDaemonSocketTimeoutSeconds,
        .tv_usec = 0,
    };
    if (setsockopt(fd, SOL_SOCKET, option_name, &timeout, sizeof(timeout)) != 0) {
        error = std::string("setsockopt(") + option_label + ") failed: " + strerror(errno);
        return false;
    }
    return true;
}

}  // namespace

daemon_socket_response daemon_socket_optimize(
    const std::string &socket_path,
    uint32_t prog_id,
    const std::vector<std::string> &enabled_passes,
    bool enabled_passes_specified)
{
    daemon_socket_response response;

    const int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        response.error = "socket() failed: " + std::string(strerror(errno));
        return response;
    }

    if (!set_socket_timeout(fd, SO_RCVTIMEO, "SO_RCVTIMEO", response.error) ||
        !set_socket_timeout(fd, SO_SNDTIMEO, "SO_SNDTIMEO", response.error)) {
        close(fd);
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
        response.error = format_socket_error("connect", errno);
        return response;
    }

    const std::string request =
        build_daemon_optimize_request(prog_id, enabled_passes, enabled_passes_specified);
    size_t total_written = 0;
    while (total_written < request.size()) {
        const ssize_t written =
            write(fd, request.data() + total_written, request.size() - total_written);
        if (written < 0) {
            close(fd);
            response.error = format_socket_error("write", errno);
            return response;
        }
        if (written == 0) {
            close(fd);
            response.error = "write() failed: daemon closed connection";
            return response;
        }
        total_written += static_cast<size_t>(written);
    }

    std::string line;
    char byte = 0;
    bool peer_closed = false;
    int read_error = 0;
    while (true) {
        const ssize_t read_result = read(fd, &byte, 1);
        if (read_result < 0) {
            read_error = errno;
            break;
        }
        if (read_result == 0) {
            peer_closed = true;
            break;
        }
        if (byte == '\n') {
            break;
        }
        line.push_back(byte);
    }
    close(fd);
    if (line.empty()) {
        if (read_error != 0) {
            response.error = format_socket_error("read", read_error);
        } else if (peer_closed) {
            response.error = "daemon closed connection before responding";
        } else {
            response.error = "empty response from daemon";
        }
        return response;
    }

    response.raw_json = line;
    try {
        response.status = extract_json_string(line, "status");
        response.ok = response.status == "ok";
        if (const auto message = extract_json_string_optional(line, "message");
            message.has_value()) {
            response.message = *message;
        }
        if (const auto error_message = extract_json_string_optional(line, "error_message");
            error_message.has_value()) {
            response.error_message = *error_message;
        }
        if (!response.ok) {
            response.error = !response.error_message.empty()
                ? response.error_message
                : (!response.message.empty()
                    ? response.message
                    : "daemon returned non-ok status: " + line);
            return response;
        }

        const std::string summary = extract_json_compound(line, "summary", '{', '}');
        response.applied = extract_json_bool(summary, "applied");
        response.program_changed = extract_json_bool(summary, "program_changed");
        response.total_sites_applied = static_cast<uint32_t>(
            extract_json_int(summary, "total_sites_applied"));
        if (const auto verifier_retries =
                extract_json_int_optional(summary, "verifier_retries");
            verifier_retries.has_value()) {
            response.verifier_retries = static_cast<uint32_t>(*verifier_retries);
        } else {
            response.verifier_retries = 0;
        }
        response.final_disabled_passes =
            extract_json_string_array(summary, "final_disabled_passes");

        const std::string program_json = extract_json_compound(line, "program", '{', '}');
        response.insn_delta = extract_json_int(program_json, "insn_delta");
        response.final_insn_count = extract_json_int(program_json, "final_insn_count");
        if (const auto final_jited_size =
                extract_json_int_optional(program_json, "final_jited_size");
            final_jited_size.has_value()) {
            response.final_jited_size = *final_jited_size;
        }

        response.pass_details = extract_pass_details(line);
        response.passes_applied = changed_pass_names(response.pass_details);
    } catch (const std::exception &error) {
        response.error = "invalid daemon JSON: " + std::string(error.what());
        response.ok = false;
    }
    return response;
}
