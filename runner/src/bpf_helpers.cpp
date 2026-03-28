#include "bpf_helpers.hpp"

#include "micro_exec.hpp"

#include <algorithm>
#include <bpf/libbpf.h>
#include <cerrno>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <sys/syscall.h>
#include <unistd.h>
#include <utility>

std::string libbpf_error_string(int error_code)
{
    char buffer[256] = {};
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    return std::string(buffer);
}

bpf_prog_info load_prog_info(int program_fd)
{
    bpf_prog_info info = {};
    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD failed: " + std::string(strerror(errno)));
    }
    return info;
}

std::vector<uint8_t> load_jited_program(
    int program_fd,
    uint32_t jited_prog_len,
    bool require_non_empty)
{
    if (jited_prog_len == 0) {
        if (require_non_empty) {
            fail("kernel reported an empty JIT image");
        }
        return {};
    }

    std::vector<uint8_t> jited_program(jited_prog_len);
    bpf_prog_info info = {};
    info.jited_prog_len = jited_prog_len;
    info.jited_prog_insns = ptr_to_u64(jited_program.data());

    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD (JIT dump) failed: " + std::string(strerror(errno)));
    }

    jited_program.resize(info.jited_prog_len);
    return jited_program;
}

std::vector<uint8_t> load_xlated_program(
    int program_fd,
    uint32_t xlated_prog_len,
    bool require_non_empty)
{
    if (xlated_prog_len == 0) {
        if (require_non_empty) {
            fail("kernel reported an empty xlated program");
        }
        return {};
    }

    std::vector<uint8_t> xlated(xlated_prog_len);
    bpf_prog_info info = {};
    info.xlated_prog_len = xlated_prog_len;
    info.xlated_prog_insns = ptr_to_u64(xlated.data());

    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD (xlated dump) failed: " + std::string(strerror(errno)));
    }

    xlated.resize(info.xlated_prog_len);
    return xlated;
}

std::string format_byte_dump(
    const std::vector<uint8_t> &bytes,
    size_t width,
    bool annotate_pc)
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

std::string program_name_from_info(const bpf_prog_info &info)
{
    const char *name = reinterpret_cast<const char *>(info.name);
    if (name == nullptr || name[0] == '\0') {
        return {};
    }
    return std::string(name);
}

std::optional<enum bpf_prog_type> prog_type_from_string(
    const std::string &value)
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

std::string prog_type_name_from_enum(enum bpf_prog_type prog_type)
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
