#include "daemon_client.hpp"

#include "json_parser.hpp"

#include <cerrno>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

namespace {

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
        build_daemon_optimize_request(prog_id, enabled_passes, enabled_passes_specified);
    const ssize_t written = write(fd, request.c_str(), request.size());
    if (written < 0 || static_cast<size_t>(written) != request.size()) {
        close(fd);
        response.error = "write() failed: " + std::string(strerror(errno));
        return response;
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
            response.error = "read() failed: " + std::string(strerror(read_error));
        } else if (peer_closed) {
            response.error = "daemon closed connection before responding";
        } else {
            response.error = "empty response from daemon";
        }
        return response;
    }

    response.raw_json = line;
    response.status = extract_json_string(line, "status");
    response.ok = response.status == "ok";
    response.message = extract_json_string(line, "message");
    response.error_message = extract_json_string(line, "error_message");
    if (!response.ok) {
        response.error = !response.message.empty()
            ? response.message
            : "daemon returned non-ok status: " + line;
        return response;
    }

    const std::string summary = extract_json_compound(line, "summary", '{', '}');
    if (!summary.empty()) {
        response.applied = extract_json_bool(summary, "applied");
        response.program_changed = extract_json_bool(summary, "program_changed");
        response.total_sites_applied = static_cast<uint32_t>(
            extract_json_int(summary, "total_sites_applied"));
        response.verifier_retries = static_cast<uint32_t>(
            extract_json_int(summary, "verifier_retries"));
        response.final_disabled_passes =
            extract_json_string_array(summary, "final_disabled_passes");
    }

    const std::string program_json = extract_json_compound(line, "program", '{', '}');
    if (!program_json.empty()) {
        response.insn_delta = extract_json_int(program_json, "insn_delta");
        const auto final_insn_count =
            extract_json_int(program_json, "final_insn_count");
        const auto final_jited_size =
            extract_json_int(program_json, "final_jited_size");
        if (final_insn_count > 0) {
            response.final_insn_count = final_insn_count;
        }
        if (final_jited_size > 0) {
            response.final_jited_size = final_jited_size;
        }
    }

    response.pass_details = extract_pass_details(line);
    response.passes_applied = changed_pass_names(response.pass_details);
    return response;
}
