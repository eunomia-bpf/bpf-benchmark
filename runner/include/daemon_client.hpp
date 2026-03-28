#ifndef DAEMON_CLIENT_HPP
#define DAEMON_CLIENT_HPP

#include "micro_exec.hpp"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

struct daemon_socket_response {
    bool ok = false;
    bool applied = false;
    bool program_changed = false;
    std::string error;
    std::string status = "error";
    std::string message;
    std::string error_message;
    uint32_t total_sites_applied = 0;
    std::vector<std::string> passes_applied;
    std::vector<daemon_pass_detail> pass_details;
    int64_t insn_delta = 0;
    uint32_t verifier_retries = 0;
    std::vector<std::string> final_disabled_passes;
    std::optional<int64_t> final_insn_count;
    std::optional<int64_t> final_jited_size;
    std::string raw_json;
};

daemon_socket_response daemon_socket_optimize(
    const std::string &socket_path,
    uint32_t prog_id,
    const std::vector<std::string> &enabled_passes,
    bool enabled_passes_specified);

#endif
