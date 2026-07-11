#include "native_loader.hpp"

#include "kernel_offsets.h"

#include "native_loader_manifest.hpp"

#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <dirent.h>
#include <gelf.h>
#include <libelf.h>
#include <linux/bpf.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

extern "C" char **environ;

namespace {

[[noreturn]] void fail(const std::string &message)
{
    throw std::runtime_error(message);
}

template <typename T>
inline __u64 ptr_to_u64(T *ptr)
{
    return static_cast<__u64>(reinterpret_cast<uintptr_t>(ptr));
}

template <typename Clock, typename Duration>
inline uint64_t elapsed_ns(
    const std::chrono::time_point<Clock, Duration> &start,
    const std::chrono::time_point<Clock, Duration> &end)
{
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
}

bool native_loader_env_truthy(const char *name)
{
    const char *value = std::getenv(name);
    return value && value[0] && std::strcmp(value, "0") != 0 &&
        std::strcmp(value, "false") != 0 &&
        std::strcmp(value, "False") != 0 &&
        std::strcmp(value, "FALSE") != 0;
}

void native_loader_kmsg_line(const std::string &message)
{
    if (!native_loader_env_truthy("BPFREJIT_SHIM_NATIVE_KMSG_PROGRESS")) {
        return;
    }

    const int saved_errno = errno;
    std::string line = "bpfrejit-native-loader[" + std::to_string(getpid())
        + "]: " + message;
    if (line.empty() || line.back() != '\n') {
        line.push_back('\n');
    }

    long fd = syscall(SYS_openat, AT_FDCWD, "/dev/kmsg",
                      O_WRONLY | O_CLOEXEC, 0);
    if (fd >= 0) {
        (void)syscall(SYS_write, fd, line.data(), line.size());
        (void)syscall(SYS_close, fd);
    }
    errno = saved_errno;
}

std::string libbpf_error_string(int error_code)
{
    char buffer[256] = {};
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    return std::string(buffer);
}

std::string native_lab_kernel_log_tail()
{
    int fd = open("/dev/kmsg", O_RDONLY | O_NONBLOCK | O_CLOEXEC);
    if (fd < 0) {
        return "\nkernel log unavailable: open /dev/kmsg: "
            + std::string(std::strerror(errno));
    }
    if (lseek(fd, 0, SEEK_SET) < 0) {
        int saved = errno;
        close(fd);
        return "\nkernel log unavailable: seek /dev/kmsg: "
            + std::string(std::strerror(saved));
    }

    std::string raw;
    char buf[4096];
    for (;;) {
        ssize_t n = read(fd, buf, sizeof(buf));
        if (n > 0) {
            raw.append(buf, static_cast<size_t>(n));
            constexpr size_t kMaxRawLog = 128 * 1024;
            if (raw.size() > kMaxRawLog) {
                raw.erase(0, raw.size() - kMaxRawLog);
            }
            continue;
        }
        if (n == 0) {
            break;
        }
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            break;
        }
        if (errno == EPIPE) {
            raw.clear();
            continue;
        }
        const int saved = errno;
        close(fd);
        return "\nkernel log unavailable: read /dev/kmsg: "
            + std::string(std::strerror(saved));
    }
    close(fd);

    std::string filtered;
    size_t line_start = 0;
    while (line_start < raw.size()) {
        size_t line_end = raw.find('\n', line_start);
        if (line_end == std::string::npos) {
            line_end = raw.size();
        }
        std::string line = raw.substr(line_start, line_end - line_start);
        if (line.find("bpf_x86_native_lab") != std::string::npos ||
            line.find("bpf_arm64_native_lab") != std::string::npos ||
            line.find("bpf_jit:") != std::string::npos ||
            line.find("Target call") != std::string::npos) {
            filtered += line;
            filtered += '\n';
            constexpr size_t kMaxFilteredLog = 8192;
            if (filtered.size() > kMaxFilteredLog) {
                filtered.erase(0, filtered.size() - kMaxFilteredLog);
            }
        }
        line_start = line_end + 1;
    }
    if (filtered.empty()) {
        return "";
    }
    return "\nkernel log tail:\n" + filtered;
}

bpf_prog_info load_prog_info(int program_fd)
{
    bpf_prog_info info = {};
    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd failed: " + libbpf_error_string(err));
    }
    return info;
}

std::string prog_info_name_or_stub(const bpf_prog_info &info)
{
    char name[sizeof(info.name) + 1] = {};
    std::memcpy(name, info.name, sizeof(info.name));
    if (name[0] == '\0') {
        return "native_lab_stub";
    }
    return std::string(name, strnlen(name, sizeof(info.name)));
}

std::vector<uint8_t> load_xlated_program(
    int program_fd,
    uint32_t xlated_prog_len,
    bool require_non_empty = true)
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

    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (xlated dump) failed: " + libbpf_error_string(err));
    }

    xlated.resize(info.xlated_prog_len);
    return xlated;
}

std::vector<uint8_t> read_binary_file(const std::filesystem::path &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        fail("unable to open file: " + path.string());
    }
    input.seekg(0, std::ios::end);
    std::streamoff size = input.tellg();
    if (size < 0) {
        fail("unable to read file size: " + path.string());
    }
    input.seekg(0, std::ios::beg);
    std::vector<uint8_t> data(static_cast<size_t>(size));
    if (!data.empty()) {
        input.read(reinterpret_cast<char *>(data.data()), static_cast<std::streamsize>(data.size()));
        if (!input) {
            fail("unable to read file: " + path.string());
        }
    }
    return data;
}

std::vector<bpf_insn> read_bpf_insn_file(const std::filesystem::path &path)
{
    std::vector<uint8_t> bytes = read_binary_file(path);
    if (bytes.empty()) {
        fail("source BPF bytecode file is empty: " + path.string());
    }
    if (bytes.size() % sizeof(bpf_insn) != 0) {
        fail("source BPF bytecode file is not a whole number of bpf_insn records: " +
             path.string());
    }
    std::vector<bpf_insn> insns(bytes.size() / sizeof(bpf_insn));
    std::memcpy(insns.data(), bytes.data(), bytes.size());
    return insns;
}

void write_binary_file(const std::filesystem::path &path, const uint8_t *data, size_t size)
{
    std::ofstream output(path, std::ios::binary | std::ios::trunc);
    if (!output) {
        fail("unable to open file for writing: " + path.string());
    }
    if (size != 0) {
        output.write(reinterpret_cast<const char *>(data), static_cast<std::streamsize>(size));
    }
    if (!output) {
        fail("unable to write file: " + path.string());
    }
}

struct NativeLabTarget {
    const char *module_name;
    const char *kfunc_name;
    const char *module_btf_path;
    const char *debugfs_dir;
    const char *blob_path_fmt;
    const char *relocs_path_fmt;
    const char *map_ptr_path;
    const char *map_value_ptr_path;
    const char *map_update_elem_path;
    uint32_t chunk_bytes;
};

#if defined(__aarch64__)
constexpr NativeLabTarget kNativeLabTarget = {
    .module_name = "bpf_arm64_native_lab",
    .kfunc_name = "bpf_arm64_native_lab_emit",
    .module_btf_path = "/sys/kernel/btf/bpf_arm64_native_lab",
    .debugfs_dir = "/sys/kernel/debug/bpf_arm64_native_lab",
    .blob_path_fmt = "/sys/kernel/debug/bpf_arm64_native_lab/blob%u",
    .relocs_path_fmt = "/sys/kernel/debug/bpf_arm64_native_lab/blob%u.relocs",
    .map_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_ptr",
    .map_value_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_value_ptr",
    .map_update_elem_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_update_elem",
    .chunk_bytes = 16 * 1024,
};
#else
constexpr NativeLabTarget kNativeLabTarget = {
    .module_name = "bpf_x86_native_lab",
    .kfunc_name = "bpf_x86_native_lab_emit",
    .module_btf_path = "/sys/kernel/btf/bpf_x86_native_lab",
    .debugfs_dir = "/sys/kernel/debug/bpf_x86_native_lab",
    .blob_path_fmt = "/sys/kernel/debug/bpf_x86_native_lab/blob%u",
    .relocs_path_fmt = "/sys/kernel/debug/bpf_x86_native_lab/blob%u.relocs",
    .map_ptr_path = "/sys/kernel/debug/bpf_x86_native_lab/map_ptr",
    .map_value_ptr_path = "/sys/kernel/debug/bpf_x86_native_lab/map_value_ptr",
    .map_update_elem_path = "/sys/kernel/debug/bpf_x86_native_lab/map_update_elem",
    .chunk_bytes = 128,
};
#endif

constexpr const char *kVmlinuxBtfPath = "/sys/kernel/btf/vmlinux";
constexpr const char *kDebugfsDir = "/sys/kernel/debug";
constexpr uint32_t kMaxBlobs = 512;

bool native_lab_needs_tail_call_probe()
{
    return true;
}

class NativeLabUploadLock {
public:
    NativeLabUploadLock()
    {
        fd_ = open("/tmp/bpfrejit-native-loader-upload.lock",
                   O_RDWR | O_CREAT | O_CLOEXEC, 0600);
        if (fd_ < 0) {
            fail("open native_lab upload lock: " + std::string(std::strerror(errno)));
        }
        while (flock(fd_, LOCK_EX) != 0) {
            if (errno == EINTR) {
                continue;
            }
            const int saved_errno = errno;
            close(fd_);
            fd_ = -1;
            fail("lock native_lab upload lock: " + std::string(std::strerror(saved_errno)));
        }
    }

    NativeLabUploadLock(const NativeLabUploadLock &) = delete;
    NativeLabUploadLock &operator=(const NativeLabUploadLock &) = delete;

    ~NativeLabUploadLock()
    {
        if (fd_ >= 0) {
            flock(fd_, LOCK_UN);
            close(fd_);
        }
    }

private:
    int fd_ = -1;
};

/* Stage 2 helpers that native-link can lower. The loader passes explicit
 * helper/map targets into native-link; unsupported or missing symbols fail
 * before the native stub is loaded. */
struct SupportedHelper {
    int id;
    const char *symbol;
};

constexpr SupportedHelper kSupportedHelpers[] = {
    {BPF_FUNC_probe_read, "bpf_probe_read_compat"},
    {BPF_FUNC_probe_read_str, "bpf_probe_read_compat_str"},
    {BPF_FUNC_trace_printk, "bpf_trace_printk"},
    {BPF_FUNC_ktime_get_ns, "bpf_ktime_get_ns"},
    {BPF_FUNC_ktime_get_boot_ns, "bpf_ktime_get_boot_ns"},
    {BPF_FUNC_get_current_pid_tgid, "bpf_get_current_pid_tgid"},
    {BPF_FUNC_get_current_uid_gid, "bpf_get_current_uid_gid"},
    {BPF_FUNC_get_smp_processor_id, "bpf_get_smp_processor_id"},
    {BPF_FUNC_get_prandom_u32, "bpf_get_prandom_u32"},
    {BPF_FUNC_probe_read_kernel, "bpf_probe_read_kernel"},
    {BPF_FUNC_probe_read_user, "bpf_probe_read_user"},
    {BPF_FUNC_probe_write_user, "bpf_probe_write_user"},
    {BPF_FUNC_probe_read_kernel_str, "bpf_probe_read_kernel_str"},
    {BPF_FUNC_probe_read_user_str, "bpf_probe_read_user_str"},
    {BPF_FUNC_map_lookup_elem, "bpf_map_lookup_elem"},
    {BPF_FUNC_map_update_elem, "bpf_map_update_elem"},
    {BPF_FUNC_map_delete_elem, "bpf_map_delete_elem"},
    {BPF_FUNC_get_current_comm, "bpf_get_current_comm"},
    {BPF_FUNC_get_current_cgroup_id, "bpf_get_current_cgroup_id"},
    {BPF_FUNC_current_task_under_cgroup, "bpf_current_task_under_cgroup"},
    {BPF_FUNC_get_stackid, "bpf_get_stackid"},
    {BPF_FUNC_get_stack, "bpf_get_stack"},
    {BPF_FUNC_get_current_task, "bpf_get_current_task"},
    {BPF_FUNC_perf_event_output, "bpf_perf_event_output"},
    {BPF_FUNC_ringbuf_output, "bpf_ringbuf_output"},
    {BPF_FUNC_ringbuf_reserve, "bpf_ringbuf_reserve"},
    {BPF_FUNC_ringbuf_submit, "bpf_ringbuf_submit"},
    {BPF_FUNC_ringbuf_discard, "bpf_ringbuf_discard"},
    {BPF_FUNC_ringbuf_query, "bpf_ringbuf_query"},
    {BPF_FUNC_xdp_adjust_meta, "bpf_xdp_adjust_meta"},
    {BPF_FUNC_xdp_adjust_head, "bpf_xdp_adjust_head"},
    {BPF_FUNC_xdp_adjust_tail, "bpf_xdp_adjust_tail"},
    {BPF_FUNC_xdp_get_buff_len, "bpf_xdp_get_buff_len"},
    {BPF_FUNC_xdp_load_bytes, "bpf_xdp_load_bytes"},
    {BPF_FUNC_xdp_store_bytes, "bpf_xdp_store_bytes"},
    {BPF_FUNC_skb_store_bytes, "bpf_skb_store_bytes"},
    {BPF_FUNC_l3_csum_replace, "bpf_l3_csum_replace"},
    {BPF_FUNC_l4_csum_replace, "bpf_l4_csum_replace"},
    {BPF_FUNC_clone_redirect, "bpf_clone_redirect"},
    {BPF_FUNC_get_cgroup_classid, "bpf_get_cgroup_classid"},
    {BPF_FUNC_skb_vlan_push, "bpf_skb_vlan_push"},
    {BPF_FUNC_skb_vlan_pop, "bpf_skb_vlan_pop"},
    {BPF_FUNC_skb_get_tunnel_key, "bpf_skb_get_tunnel_key"},
    {BPF_FUNC_skb_set_tunnel_key, "bpf_skb_set_tunnel_key"},
    {BPF_FUNC_redirect, "bpf_redirect"},
    {BPF_FUNC_get_route_realm, "bpf_get_route_realm"},
    {BPF_FUNC_skb_load_bytes, "bpf_skb_load_bytes"},
    {BPF_FUNC_skb_load_bytes_relative, "bpf_skb_load_bytes_relative"},
    {BPF_FUNC_csum_diff, "bpf_csum_diff"},
    {BPF_FUNC_skb_get_tunnel_opt, "bpf_skb_get_tunnel_opt"},
    {BPF_FUNC_skb_set_tunnel_opt, "bpf_skb_set_tunnel_opt"},
    {BPF_FUNC_skb_change_proto, "bpf_skb_change_proto"},
    {BPF_FUNC_skb_change_type, "bpf_skb_change_type"},
    {BPF_FUNC_skb_under_cgroup, "bpf_skb_under_cgroup"},
    {BPF_FUNC_get_hash_recalc, "bpf_get_hash_recalc"},
    {BPF_FUNC_skb_change_tail, "bpf_skb_change_tail"},
    {BPF_FUNC_skb_pull_data, "bpf_skb_pull_data"},
    {BPF_FUNC_csum_update, "bpf_csum_update"},
    {BPF_FUNC_set_hash_invalid, "bpf_set_hash_invalid"},
    {BPF_FUNC_skb_adjust_room, "bpf_skb_adjust_room"},
    {BPF_FUNC_get_numa_node_id, "bpf_get_numa_node_id"},
    {BPF_FUNC_skb_change_head, "bpf_skb_change_head"},
    {BPF_FUNC_get_socket_cookie, "bpf_get_socket_cookie"},
    {BPF_FUNC_get_socket_uid, "bpf_get_socket_uid"},
    {BPF_FUNC_sk_lookup_udp, "bpf_sk_lookup_udp"},
    {BPF_FUNC_sk_release, "bpf_sk_release"},
    {BPF_FUNC_map_push_elem, "bpf_map_push_elem"},
    {BPF_FUNC_map_pop_elem, "bpf_map_pop_elem"},
    {BPF_FUNC_sk_fullsock, "bpf_sk_fullsock"},
    {BPF_FUNC_override_return, "bpf_override_return"},
    {BPF_FUNC_send_signal, "bpf_send_signal"},
    {BPF_FUNC_seq_write, "bpf_seq_write"},
    {BPF_FUNC_copy_from_user, "bpf_copy_from_user"},
    {BPF_FUNC_jiffies64, "bpf_jiffies64"},
    {BPF_FUNC_sk_assign, "bpf_sk_assign"},
    {BPF_FUNC_get_current_task_btf, "bpf_get_current_task_btf"},
    {BPF_FUNC_ima_inode_hash, "bpf_ima_inode_hash"},
    {BPF_FUNC_get_func_ip, "bpf_get_func_ip"},
    {BPF_FUNC_get_attach_cookie, "bpf_get_attach_cookie"},
    {BPF_FUNC_task_pt_regs, "bpf_task_pt_regs"},
    {BPF_FUNC_loop, "bpf_loop"},
    {BPF_FUNC_get_func_arg, "bpf_get_func_arg"},
    {BPF_FUNC_get_func_ret, "bpf_get_func_ret"},
    {BPF_FUNC_get_func_arg_cnt, "bpf_get_func_arg_cnt"},
    {BPF_FUNC_ima_file_hash, "bpf_ima_file_hash"},
    {BPF_FUNC_set_hash, "bpf_set_hash"},
    {BPF_FUNC_redirect_neigh, "bpf_redirect_neigh"},
    {BPF_FUNC_redirect_peer, "bpf_redirect_peer"},
};

constexpr const char *kRuntimeCallSymbols[] = {
    "memset",
    "memcpy",
    "memmove",
};

constexpr const char *kTypedHelperSymbols[] = {
    "bpf_user_rnd_u32",
    "bpf_perf_event_output_tp",
    "bpf_perf_event_output_raw_tp",
    "bpf_get_stackid_tp",
    "bpf_get_stackid_pe",
    "bpf_get_stackid_raw_tp",
    "bpf_get_stack_tp",
    "bpf_get_stack_pe",
    "bpf_get_stack_raw_tp",
    "bpf_xdp_fib_lookup",
    "bpf_skb_fib_lookup",
    "bpf_xdp_redirect_map",
    "bpf_tc_skc_lookup_tcp",
    "bpf_xdp_skc_lookup_tcp",
    "bpf_skc_lookup_tcp",
    "bpf_tc_sk_lookup_udp",
    "bpf_xdp_sk_lookup_udp",
    "bpf_sock_addr_sk_lookup_udp",
    "bpf_sk_lookup_udp",
};

constexpr const char *kX86CpuNumberHelperKey = "__native_x86_cpu_number";
constexpr const char *kX86ThisCpuOffHelperKey = "__native_x86_this_cpu_off";
constexpr const char *kX86BpfMapMaxEntriesOffsetKey =
    "__native_x86_bpf_map_max_entries_offset";
constexpr const char *kX86BpfArrayPtrsOffsetKey = "__native_x86_bpf_array_ptrs_offset";
constexpr const char *kX86BpfProgBpfFuncOffsetKey =
    "__native_x86_bpf_prog_bpf_func_offset";
constexpr const char *kX86TailCallOffsetKey = "__native_x86_tail_call_offset";
constexpr const char *kArm64ThreadInfoCpuOffsetHelperKey =
    "__native_arm64_thread_info_cpu_offset";
constexpr const char *kArm64BpfMapMaxEntriesOffsetKey =
    "__native_arm64_bpf_map_max_entries_offset";
constexpr const char *kArm64BpfArrayPtrsOffsetKey =
    "__native_arm64_bpf_array_ptrs_offset";
constexpr const char *kArm64BpfProgBpfFuncOffsetKey =
    "__native_arm64_bpf_prog_bpf_func_offset";
constexpr const char *kArm64TailCallOffsetKey = "__native_arm64_tail_call_offset";
constexpr const char *kNativeLinkCacheDir = "/tmp/native_kernel_link_cache";
constexpr const char *kNativeLinkCacheVersion = "native-link-template-cache-v66";
constexpr const char *kNativeStubBtfCachePath = "/tmp/native_kernel_stub_btf.tsv";
constexpr const char *kNativeStubBtfCacheVersion = "native-stub-btf-cache-v1";
constexpr size_t kInitialVerifierLogSize = 256 * 1024;
constexpr size_t kMaxVerifierLogSize = 16 * 1024 * 1024;
constexpr size_t kVerifierLogGrowthSlop = 4096;
constexpr const char *kHtabLookupElemSymbol = "__htab_map_lookup_elem";
constexpr const char *kArrayOfMapLookupElemSymbol = "array_of_map_lookup_elem";
constexpr const char *kHtabLruPercpuMapLookupElemSymbol =
    "htab_lru_percpu_map_lookup_elem";
constexpr int kLibbpfCoreBadRelocPoison = 195896080; // 0xbad2310

#ifndef BPF_PSEUDO_KOP_SIDECAR
#define BPF_PSEUDO_KOP_SIDECAR 3
#endif
#ifndef BPF_PSEUDO_KOP_CALL
#define BPF_PSEUDO_KOP_CALL 4
#endif
#ifndef K_BPF_ARRAY_VALUE_OFFSET
#error "kernel_offsets.h must define K_BPF_ARRAY_VALUE_OFFSET"
#endif
#ifndef K_BPF_ARRAY_PTRS_OFFSET
#error "kernel_offsets.h must define K_BPF_ARRAY_PTRS_OFFSET"
#endif
#ifndef K_BPF_ARRAY_PPTRS_OFFSET
#error "kernel_offsets.h must define K_BPF_ARRAY_PPTRS_OFFSET"
#endif
#ifndef K_BPF_MAP_MAX_ENTRIES_OFFSET
#error "kernel_offsets.h must define K_BPF_MAP_MAX_ENTRIES_OFFSET"
#endif
#ifndef K_BPF_PROG_BPF_FUNC_OFFSET
#error "kernel_offsets.h must define K_BPF_PROG_BPF_FUNC_OFFSET"
#endif
#if defined(__x86_64__)
#ifndef K_X86_BPF_TAIL_CALL_OFFSET
#error "kernel_offsets.h must define K_X86_BPF_TAIL_CALL_OFFSET"
#endif
#endif
#ifndef K_HTAB_ELEM_KEY_OFFSET
#error "kernel_offsets.h must define K_HTAB_ELEM_KEY_OFFSET"
#endif
#ifndef K_HTAB_ELEM_LRU_REF_OFFSET
#error "kernel_offsets.h must define K_HTAB_ELEM_LRU_REF_OFFSET"
#endif
#if defined(__aarch64__)
#ifndef K_THREAD_INFO_CPU_OFFSET
#error "kernel_offsets.h must define K_THREAD_INFO_CPU_OFFSET"
#endif
#ifndef K_ARM64_BPF_TAIL_CALL_OFFSET
#error "kernel_offsets.h must define K_ARM64_BPF_TAIL_CALL_OFFSET"
#endif
#endif

std::string read_first_line_required(const char *path);
const char *native_arch_name();

void ensure_debugfs_mounted()
{
    struct stat st = {};
    if (stat(kNativeLabTarget.debugfs_dir, &st) == 0 && S_ISDIR(st.st_mode)) {
        return;
    }
    (void)mount("none", kDebugfsDir, "debugfs", 0, nullptr);
}

uint64_t lookup_native_lab_ptr_by_fd(int map_fd,
                                     const char *path,
                                     const char *label,
                                     bool allow_unavailable = false)
{
    ensure_debugfs_mounted();
    int fd = open(path, O_RDWR | O_CLOEXEC);
    if (fd < 0) {
        fail(std::string("open ") + path + ": " + std::strerror(errno));
    }

    char request[32];
    int request_len = std::snprintf(request, sizeof(request), "%d\n", map_fd);
    if (request_len <= 0 || request_len >= static_cast<int>(sizeof(request))) {
        close(fd);
        fail(std::string("native_kernel: invalid map fd for ") + label + " query");
    }

    ssize_t written = write(fd, request, static_cast<size_t>(request_len));
    int saved = errno;
    if (written != request_len) {
        close(fd);
        if (allow_unavailable && written < 0 &&
            (saved == EOPNOTSUPP || saved == EINVAL)) {
            return 0;
        }
        fail(std::string("write ") + path + ": " + std::strerror(saved));
    }

    if (lseek(fd, 0, SEEK_SET) < 0) {
        saved = errno;
        close(fd);
        fail(std::string("lseek ") + path + ": " + std::strerror(saved));
    }

    char response[64] = {};
    ssize_t n = read(fd, response, sizeof(response) - 1);
    saved = errno;
    close(fd);
    if (n <= 0) {
        fail(std::string("read ") + path + ": " + std::strerror(saved));
    }
    response[n] = '\0';

    errno = 0;
    char *end = nullptr;
    unsigned long long value = std::strtoull(response, &end, 0);
    if (errno != 0 || end == response || value == 0) {
        fail(std::string("native_kernel: invalid ") + label + " response: " + response);
    }
    return static_cast<uint64_t>(value);
}

uint64_t lookup_kernel_map_ptr_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_ptr_path, "map_ptr");
}

uint64_t lookup_kernel_map_value_ptr_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_value_ptr_path, "map_value_ptr");
}

uint64_t lookup_kernel_map_update_elem_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_update_elem_path, "map_update_elem");
}

uint64_t lookup_kernel_map_value_ptr_by_fd_if_available(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_value_ptr_path, "map_value_ptr", true);
}

constexpr size_t kRelocRecordBytes = 16;
constexpr size_t kNativeLabRelocHelperCallRel32Bytes = 5;
constexpr size_t kNativeLabRelocHelperCallArm64Bytes = 16;
constexpr size_t kNativeLabRelocHelperCallArm64Bl26Bytes = 4;
constexpr size_t kNativeLabRelocArm64PercpuMrsBytes = 4;
constexpr uint32_t kNativeLabRelocHelperCallRel32 = 1;
constexpr uint32_t kNativeLabRelocHelperCallArm64 = 2;
constexpr uint32_t kNativeLabRelocHelperCallArm64Bl26 = 3;
constexpr uint32_t kNativeLabRelocArm64PercpuMrs = 4;

struct NativeLabReloc {
    uint32_t global_offset;
    uint32_t kind;
    uint64_t target;
};

struct NativeBlobChunk {
    size_t offset;
    size_t len;
};

uint32_t read_u32_le(const uint8_t *p)
{
    return static_cast<uint32_t>(p[0]) |
           (static_cast<uint32_t>(p[1]) << 8) |
           (static_cast<uint32_t>(p[2]) << 16) |
           (static_cast<uint32_t>(p[3]) << 24);
}

uint64_t read_u64_le(const uint8_t *p)
{
    uint64_t v = 0;
    for (unsigned i = 0; i < 8; i++) {
        v |= static_cast<uint64_t>(p[i]) << (i * 8);
    }
    return v;
}

void append_u32_le(std::vector<uint8_t> &out, uint32_t v)
{
    out.push_back(static_cast<uint8_t>(v & 0xff));
    out.push_back(static_cast<uint8_t>((v >> 8) & 0xff));
    out.push_back(static_cast<uint8_t>((v >> 16) & 0xff));
    out.push_back(static_cast<uint8_t>((v >> 24) & 0xff));
}

void append_u64_le(std::vector<uint8_t> &out, uint64_t v)
{
    for (unsigned i = 0; i < 8; i++) {
        out.push_back(static_cast<uint8_t>((v >> (i * 8)) & 0xff));
    }
}

bool native_lab_reloc_kind_supported(uint32_t kind)
{
#if defined(__aarch64__)
    return kind == kNativeLabRelocHelperCallArm64 ||
           kind == kNativeLabRelocHelperCallArm64Bl26 ||
           kind == kNativeLabRelocArm64PercpuMrs;
#else
    return kind == kNativeLabRelocHelperCallRel32;
#endif
}

size_t native_lab_reloc_slot_bytes(uint32_t kind)
{
    switch (kind) {
    case kNativeLabRelocHelperCallRel32:
        return kNativeLabRelocHelperCallRel32Bytes;
    case kNativeLabRelocHelperCallArm64:
        return kNativeLabRelocHelperCallArm64Bytes;
    case kNativeLabRelocHelperCallArm64Bl26:
        return kNativeLabRelocHelperCallArm64Bl26Bytes;
    case kNativeLabRelocArm64PercpuMrs:
        return kNativeLabRelocArm64PercpuMrsBytes;
    default:
        fail("native_lab reloc has unknown kind " + std::to_string(kind));
    }
}

std::string hex_u64(uint64_t value)
{
    char buf[17];
    std::snprintf(buf, sizeof(buf), "%016llx",
                  static_cast<unsigned long long>(value));
    return std::string(buf);
}

std::string offset_or_none(size_t offset)
{
    if (offset == std::numeric_limits<size_t>::max()) {
        return "none";
    }
    return std::to_string(offset);
}

uint64_t native_blob_fnv64(const std::vector<uint8_t> &blob)
{
    uint64_t hash = 1469598103934665603ULL;
    for (uint8_t byte : blob) {
        hash ^= byte;
        hash *= 1099511628211ULL;
    }
    return hash;
}

std::string native_blob_diagnostics(const std::vector<uint8_t> &blob,
                                    const std::vector<NativeBlobChunk> &chunks)
{
    constexpr uint32_t kArm64BreakFault = 0xd4200000;
    uint64_t hash = native_blob_fnv64(blob);

    size_t break_fault_words = 0;
    size_t first_break_fault_offset = std::numeric_limits<size_t>::max();
    size_t zero_words = 0;
    size_t first_zero_offset = std::numeric_limits<size_t>::max();
    const size_t word_bytes = blob.size() - (blob.size() % sizeof(uint32_t));
    for (size_t offset = 0; offset < word_bytes; offset += sizeof(uint32_t)) {
        const uint32_t word = read_u32_le(blob.data() + offset);
        if (word == kArm64BreakFault) {
            if (first_break_fault_offset == std::numeric_limits<size_t>::max()) {
                first_break_fault_offset = offset;
            }
            break_fault_words++;
        }
        if (word == 0) {
            if (first_zero_offset == std::numeric_limits<size_t>::max()) {
                first_zero_offset = offset;
            }
            zero_words++;
        }
    }

    size_t chunk_range_bad = 0;
    size_t first_bad_chunk = std::numeric_limits<size_t>::max();
    size_t chunk_alignment_bad = 0;
    size_t first_unaligned_chunk = std::numeric_limits<size_t>::max();
    size_t chunk_length_bad = 0;
    size_t first_bad_length_chunk = std::numeric_limits<size_t>::max();
    size_t chunk_contiguous_bad = 0;
    size_t first_noncontiguous_chunk = std::numeric_limits<size_t>::max();
    size_t expected_offset = 0;
    for (size_t i = 0; i < chunks.size(); i++) {
        const NativeBlobChunk &chunk = chunks[i];
        if (chunk.offset > blob.size() || chunk.len > blob.size() - chunk.offset) {
            if (first_bad_chunk == std::numeric_limits<size_t>::max()) {
                first_bad_chunk = i;
            }
            chunk_range_bad++;
        }
        if ((chunk.offset % sizeof(uint32_t)) != 0 ||
            (chunk.len % sizeof(uint32_t)) != 0) {
            if (first_unaligned_chunk == std::numeric_limits<size_t>::max()) {
                first_unaligned_chunk = i;
            }
            chunk_alignment_bad++;
        }
        if (chunk.len == 0 || chunk.len > kNativeLabTarget.chunk_bytes) {
            if (first_bad_length_chunk == std::numeric_limits<size_t>::max()) {
                first_bad_length_chunk = i;
            }
            chunk_length_bad++;
        }
        if (chunk.offset != expected_offset) {
            if (first_noncontiguous_chunk == std::numeric_limits<size_t>::max()) {
                first_noncontiguous_chunk = i;
            }
            chunk_contiguous_bad++;
        }
        expected_offset = chunk.offset + chunk.len;
    }
    const bool final_size_matches = expected_offset == blob.size();

    std::ostringstream out;
    out << "native_blob_diag:"
        << " fnv64=" << hex_u64(hash)
        << " word_count=" << (blob.size() / sizeof(uint32_t))
        << " tail_bytes=" << (blob.size() % sizeof(uint32_t))
        << " break_fault_words=" << break_fault_words
        << " first_break_fault_offset=" << offset_or_none(first_break_fault_offset)
        << " zero_words=" << zero_words
        << " first_zero_offset=" << offset_or_none(first_zero_offset)
        << " chunk_range_bad=" << chunk_range_bad
        << " first_bad_chunk=" << offset_or_none(first_bad_chunk)
        << " chunk_alignment_bad=" << chunk_alignment_bad
        << " first_unaligned_chunk=" << offset_or_none(first_unaligned_chunk)
        << " chunk_length_bad=" << chunk_length_bad
        << " first_bad_length_chunk=" << offset_or_none(first_bad_length_chunk)
        << " chunk_contiguous_bad=" << chunk_contiguous_bad
        << " first_noncontiguous_chunk=" << offset_or_none(first_noncontiguous_chunk)
        << " final_chunk_end=" << expected_offset
        << " final_size_matches=" << (final_size_matches ? 1 : 0);
    return out.str();
}

std::vector<NativeLabReloc> parse_native_lab_relocs(const std::vector<uint8_t> &relocs,
                                                    size_t blob_size)
{
    if (relocs.empty()) {
        return {};
    }
    if (relocs.size() % kRelocRecordBytes != 0) {
        fail("native_lab reloc file size is not a multiple of 16 bytes");
    }

    std::vector<NativeLabReloc> out;
    out.reserve(relocs.size() / kRelocRecordBytes);
    for (size_t off = 0; off < relocs.size(); off += kRelocRecordBytes) {
        const uint32_t global_offset = read_u32_le(relocs.data() + off);
        const uint32_t kind = read_u32_le(relocs.data() + off + 4);
        const uint64_t target = read_u64_le(relocs.data() + off + 8);
        if (!native_lab_reloc_kind_supported(kind)) {
            fail("native_lab reloc kind " + std::to_string(kind) +
                 " is not supported by module " + kNativeLabTarget.module_name);
        }
        if (static_cast<size_t>(global_offset) + native_lab_reloc_slot_bytes(kind) > blob_size) {
            fail("native_lab reloc call offset exceeds blob bounds");
        }
        out.push_back(NativeLabReloc{
            global_offset,
            kind,
            target,
        });
    }
    return out;
}

std::vector<NativeBlobChunk> plan_blob_chunks(size_t blob_size,
                                              const std::vector<NativeLabReloc> &relocs)
{
    if (blob_size == 0) {
        fail("native blob is empty");
    }

    std::vector<NativeBlobChunk> chunks;
    size_t offset = 0;
    while (offset < blob_size) {
        size_t end = std::min(offset + kNativeLabTarget.chunk_bytes, blob_size);
        /* A helper-call reloc slot must fit inside one kop emit chunk. */
        for (const NativeLabReloc &reloc : relocs) {
            const size_t reloc_start = reloc.global_offset;
            const size_t reloc_end = reloc_start + native_lab_reloc_slot_bytes(reloc.kind);
            if (offset < reloc_start && reloc_start < end && end < reloc_end) {
                end = reloc_start;
            }
        }
        if (end == offset) {
            fail("native blob chunk planner made no progress at offset " +
                 std::to_string(offset));
        }
        chunks.push_back(NativeBlobChunk{offset, end - offset});
        offset = end;
    }
    if (chunks.size() > kMaxBlobs) {
        fail("native blob requires " + std::to_string(chunks.size()) +
             " chunks but module only supports " + std::to_string(kMaxBlobs));
    }
    return chunks;
}

void upload_reloc_chunk(const std::vector<uint8_t> &relocs, uint32_t chunk_id)
{
    char path[160];
    snprintf(path, sizeof(path), kNativeLabTarget.relocs_path_fmt, chunk_id);
    int fd = open(path, O_WRONLY | O_TRUNC);
    if (fd < 0) {
        fail(std::string("open ") + path + ": " + std::strerror(errno));
    }
    ssize_t n = write(fd, relocs.data(), relocs.size());
    int saved = errno;
    close(fd);
    if (n != static_cast<ssize_t>(relocs.size())) {
        fail(std::string("write ") + path + ": " + std::strerror(saved));
    }
}

void upload_relocs(const std::vector<NativeLabReloc> &relocs,
                   const std::vector<NativeBlobChunk> &chunks)
{
    if (!kNativeLabTarget.relocs_path_fmt) {
        if (relocs.empty()) {
            return;
        }
        fail(std::string("native_lab relocs are not supported by module ")
             + kNativeLabTarget.module_name);
    }

    std::vector<std::vector<uint8_t>> by_chunk(chunks.size());
    for (const NativeLabReloc &reloc : relocs) {
        bool assigned = false;
        for (size_t chunk_id = 0; chunk_id < chunks.size(); chunk_id++) {
            const NativeBlobChunk &chunk = chunks[chunk_id];
            const size_t chunk_end = chunk.offset + chunk.len;
            const size_t reloc_start = reloc.global_offset;
            const size_t reloc_end = reloc_start + native_lab_reloc_slot_bytes(reloc.kind);
            if (reloc_start < chunk.offset || reloc_end > chunk_end) {
                continue;
            }
            const uint32_t local_offset =
                static_cast<uint32_t>(reloc_start - chunk.offset);
            append_u32_le(by_chunk[chunk_id], local_offset);
            append_u32_le(by_chunk[chunk_id], reloc.kind);
            append_u64_le(by_chunk[chunk_id], reloc.target);
            assigned = true;
            break;
        }
        if (!assigned) {
            fail("native_lab reloc at offset " +
                 std::to_string(reloc.global_offset) +
                 " crosses planned blob chunks");
        }
    }

    for (uint32_t i = 0; i < chunks.size(); i++) {
        upload_reloc_chunk(by_chunk[i], i);
    }
}

void upload_blob(const std::vector<uint8_t> &blob,
                 const std::vector<NativeBlobChunk> &chunks)
{
    if (blob.empty()) {
        fail("native blob is empty");
    }
    for (uint32_t i = 0; i < chunks.size(); i++) {
        const NativeBlobChunk &chunk = chunks[i];
        if (chunk.len == 0 || chunk.len > kNativeLabTarget.chunk_bytes ||
            chunk.offset + chunk.len > blob.size()) {
            fail("native blob chunk has invalid bounds");
        }
        char path[128];
        snprintf(path, sizeof(path), kNativeLabTarget.blob_path_fmt, i);
        int fd = open(path, O_WRONLY | O_TRUNC);
        if (fd < 0) {
            fail(std::string("open ") + path + ": " + std::strerror(errno));
        }
        ssize_t n = write(fd, blob.data() + chunk.offset, chunk.len);
        int saved = errno;
        close(fd);
        if (n != static_cast<ssize_t>(chunk.len)) {
            fail(std::string("write ") + path + ": " + std::strerror(saved));
        }
    }
}

bool btf_fd_name_is(int fd, const char *expected_name)
{
    bpf_btf_info info = {};
    char name[64] = {};
    info.name = reinterpret_cast<uintptr_t>(name);
    info.name_len = sizeof(name);
    uint32_t info_len = sizeof(info);
    return bpf_obj_get_info_by_fd(fd, &info, &info_len) == 0 &&
           std::strcmp(name, expected_name) == 0;
}

int open_module_btf_fd_by_id(uint32_t id)
{
    int fd = bpf_btf_get_fd_by_id(id);
    if (fd < 0) {
        fail("bpf_btf_get_fd_by_id(" + std::to_string(id) + "): " +
             std::strerror(errno));
    }
    if (!btf_fd_name_is(fd, kNativeLabTarget.module_name)) {
        close(fd);
        fail("cached BTF id " + std::to_string(id) + " is not module " +
             kNativeLabTarget.module_name);
    }
    return fd;
}

bool module_btf_id_is_current(uint32_t id)
{
    int fd = bpf_btf_get_fd_by_id(id);
    if (fd < 0) {
        return false;
    }
    bool ok = btf_fd_name_is(fd, kNativeLabTarget.module_name);
    close(fd);
    return ok;
}

// Walk every loaded kernel BTF and return the native_lab module BTF id.
// libbpf doesn't expose a direct "find module btf by name" helper, so we
// iterate BPF_BTF_GET_NEXT_ID.
uint32_t find_module_btf_id()
{
    uint32_t id = 0;
    for (;;) {
        uint32_t next = 0;
        if (bpf_btf_get_next_id(id, &next) < 0) {
            if (errno == ENOENT) {
                break;
            }
            fail(std::string("bpf_btf_get_next_id: ") + std::strerror(errno));
        }
        id = next;
        int fd = bpf_btf_get_fd_by_id(id);
        if (fd < 0) {
            continue;
        }
        if (btf_fd_name_is(fd, kNativeLabTarget.module_name)) {
            close(fd);
            return id;
        }
        close(fd);
    }
    fail(std::string("BTF for module ") + kNativeLabTarget.module_name +
         " is not loaded (insmod " + kNativeLabTarget.module_name + ".ko)");
    return 0;
}

int find_kfunc_btf_id()
{
    struct btf *vmlinux = btf__parse(kVmlinuxBtfPath, nullptr);
    if (libbpf_get_error(vmlinux)) {
        fail(std::string("btf__parse vmlinux: ")
             + std::strerror(static_cast<int>(-libbpf_get_error(vmlinux))));
    }
    struct btf *mod = btf__parse_split(kNativeLabTarget.module_btf_path, vmlinux);
    if (libbpf_get_error(mod)) {
        btf__free(vmlinux);
        fail(std::string("btf__parse_split module: ")
             + std::strerror(static_cast<int>(-libbpf_get_error(mod))));
    }
    int id = btf__find_by_name_kind(mod, kNativeLabTarget.kfunc_name, BTF_KIND_FUNC);
    btf__free(mod);
    btf__free(vmlinux);
    if (id < 0) {
        fail(std::string("kfunc ") + kNativeLabTarget.kfunc_name + " not found in module BTF");
    }
    return id;
}

struct NativeStubBtfIds {
    uint32_t module_btf_id = 0;
    int kfunc_btf_id = 0;
};

struct StubLoadAttrs {
    uint32_t expected_attach_type = 0;
    uint32_t attach_btf_id = 0;
    uint32_t attach_btf_obj_id = 0;
    uint32_t attach_prog_id = 0;
};

struct ScopedFd {
    int fd = -1;

    ScopedFd() = default;
    explicit ScopedFd(int value) : fd(value) {}
    ScopedFd(const ScopedFd &) = delete;
    ScopedFd &operator=(const ScopedFd &) = delete;
    ~ScopedFd()
    {
        if (fd >= 0) {
            close(fd);
        }
    }

    int get() const { return fd; }
};

bool load_native_stub_btf_cache(NativeStubBtfIds &ids,
                                const std::string &boot_id)
{
    FILE *f = std::fopen(kNativeStubBtfCachePath, "re");
    if (!f) {
        if (errno == ENOENT) {
            return false;
        }
        fail("open " + std::string(kNativeStubBtfCachePath) + ": " +
             std::strerror(errno));
    }

    bool valid_version = false;
    bool valid_arch = false;
    bool valid_boot = false;
    bool valid_module = false;
    bool valid_kfunc = false;
    NativeStubBtfIds cached{};
    char line[512];
    while (std::fgets(line, sizeof(line), f)) {
        char key[256] = {};
        char value[256] = {};
        if (std::sscanf(line, "%255s %255s", key, value) != 2) {
            std::fclose(f);
            fail("malformed native_kernel stub BTF cache line");
        }
        if (std::strcmp(key, "version") == 0) {
            valid_version = std::strcmp(value, kNativeStubBtfCacheVersion) == 0;
        } else if (std::strcmp(key, "arch") == 0) {
            valid_arch = std::strcmp(value, native_arch_name()) == 0;
        } else if (std::strcmp(key, "boot_id") == 0) {
            valid_boot = boot_id == value;
        } else if (std::strcmp(key, "module_name") == 0) {
            valid_module = std::strcmp(value, kNativeLabTarget.module_name) == 0;
        } else if (std::strcmp(key, "kfunc_name") == 0) {
            valid_kfunc = std::strcmp(value, kNativeLabTarget.kfunc_name) == 0;
        } else if (std::strcmp(key, "module_btf_id") == 0) {
            cached.module_btf_id =
                static_cast<uint32_t>(std::strtoul(value, nullptr, 0));
        } else if (std::strcmp(key, "kfunc_btf_id") == 0) {
            cached.kfunc_btf_id = static_cast<int>(std::strtol(value, nullptr, 0));
        }
    }
    std::fclose(f);

    if (!valid_version || !valid_arch || !valid_boot || !valid_module ||
        !valid_kfunc || cached.module_btf_id == 0 || cached.kfunc_btf_id <= 0 ||
        !module_btf_id_is_current(cached.module_btf_id)) {
        return false;
    }

    ids = cached;
    return true;
}

void store_native_stub_btf_cache(const NativeStubBtfIds &ids,
                                 const std::string &boot_id)
{
    if (ids.module_btf_id == 0 || ids.kfunc_btf_id <= 0) {
        fail("native_kernel stub BTF cache got invalid ids");
    }

    std::filesystem::path tmp =
        std::string(kNativeStubBtfCachePath) + "." + std::to_string(getpid()) + ".tmp";
    std::ofstream out(tmp);
    if (!out) {
        fail("open " + tmp.string() + ": " + std::strerror(errno));
    }
    out << "version " << kNativeStubBtfCacheVersion << "\n";
    out << "arch " << native_arch_name() << "\n";
    out << "boot_id " << boot_id << "\n";
    out << "module_name " << kNativeLabTarget.module_name << "\n";
    out << "kfunc_name " << kNativeLabTarget.kfunc_name << "\n";
    out << "module_btf_id " << ids.module_btf_id << "\n";
    out << "kfunc_btf_id " << ids.kfunc_btf_id << "\n";
    out.close();
    if (!out) {
        fail("write " + tmp.string() + ": " + std::strerror(errno));
    }

    std::error_code ec;
    std::filesystem::rename(tmp, kNativeStubBtfCachePath, ec);
    if (ec) {
        fail("publish " + std::string(kNativeStubBtfCachePath) + ": " +
             ec.message());
    }
}

NativeStubBtfIds find_native_stub_btf_ids()
{
    const std::string boot_id =
        read_first_line_required("/proc/sys/kernel/random/boot_id");
    NativeStubBtfIds ids{};
    if (load_native_stub_btf_cache(ids, boot_id)) {
        return ids;
    }

    ids.module_btf_id = find_module_btf_id();
    ids.kfunc_btf_id = find_kfunc_btf_id();
    store_native_stub_btf_cache(ids, boot_id);
    return ids;
}

int open_btf_fd_by_id_required(uint32_t id, const char *field_name)
{
    if (id == 0) {
        return -1;
    }
    int fd = bpf_btf_get_fd_by_id(id);
    if (fd < 0) {
        fail(std::string(field_name) + " BTF id " + std::to_string(id)
             + " cannot be opened: " + std::strerror(errno));
    }
    return fd;
}

int open_prog_fd_by_id_required(uint32_t id, const char *field_name)
{
    if (id == 0) {
        return -1;
    }
    int fd = bpf_prog_get_fd_by_id(id);
    if (fd < 0) {
        fail(std::string(field_name) + " prog id " + std::to_string(id)
             + " cannot be opened: " + std::strerror(errno));
    }
    return fd;
}

bool verifier_log_was_truncated(const std::vector<char> &verifier_log,
                                uint32_t log_true_size)
{
    return log_true_size > verifier_log.size() ||
           (!verifier_log.empty() && verifier_log.back() != '\0');
}

size_t next_verifier_log_size(size_t current_size, uint32_t log_true_size)
{
    if (current_size >= kMaxVerifierLogSize) {
        return 0;
    }

    size_t requested = log_true_size != 0
        ? static_cast<size_t>(log_true_size)
        : current_size;
    if (requested > kMaxVerifierLogSize - kVerifierLogGrowthSlop) {
        requested = kMaxVerifierLogSize;
    } else {
        requested += kVerifierLogGrowthSlop;
    }

    const size_t doubled = current_size > kMaxVerifierLogSize / 2
        ? kMaxVerifierLogSize
        : current_size * 2;
    const size_t next_size = std::min(kMaxVerifierLogSize,
                                      std::max(requested, doubled));
    return next_size > current_size ? next_size : 0;
}

int bpf_prog_load_native_stub_raw(uint32_t prog_type_value,
                                  const StubLoadAttrs &attrs,
                                  int attach_prog_fd,
                                  int attach_btf_obj_fd,
                                  const std::string &prog_name,
                                  const std::vector<bpf_insn> &insns,
                                  const std::vector<int> &fd_array,
                                  std::vector<char> &verifier_log,
                                  uint32_t &log_true_size)
{
    union bpf_attr attr = {};
    constexpr const char kDefaultName[] = "native_lab_stub";
    constexpr const char kLicense[] = "GPL";
    const char *name_data = prog_name.empty() ? kDefaultName : prog_name.data();
    const size_t name_size = prog_name.empty()
        ? strlen(kDefaultName)
        : prog_name.size();

    attr.prog_type = prog_type_value;
    attr.expected_attach_type = attrs.expected_attach_type;
    attr.attach_btf_id = attrs.attach_btf_id;
    if (attach_prog_fd >= 0) {
        attr.attach_prog_fd = static_cast<uint32_t>(attach_prog_fd);
    } else if (attach_btf_obj_fd >= 0) {
        attr.attach_btf_obj_fd = static_cast<uint32_t>(attach_btf_obj_fd);
    }
    std::memcpy(attr.prog_name,
                name_data,
                std::min(name_size, sizeof(attr.prog_name) - 1));
    attr.license = ptr_to_u64(kLicense);
    attr.insns = ptr_to_u64(insns.data());
    attr.insn_cnt = static_cast<uint32_t>(insns.size());
    attr.fd_array = ptr_to_u64(fd_array.data());
    attr.fd_array_cnt = static_cast<uint32_t>(fd_array.size());
    attr.log_level = 2;

    const unsigned int attr_size =
        static_cast<unsigned int>(offsetof(union bpf_attr, keyring_id) +
                                  sizeof(attr.keyring_id));
    int saved_errno = 0;
    for (int attempt = 0; attempt < 8; attempt++) {
        std::fill(verifier_log.begin(), verifier_log.end(), '\0');
        attr.log_size = static_cast<uint32_t>(verifier_log.size());
        attr.log_buf = ptr_to_u64(verifier_log.data());
        attr.log_true_size = 0;

        const long rc = syscall(SYS_bpf, BPF_PROG_LOAD, &attr, attr_size);
        if (rc >= 0) {
            log_true_size = attr.log_true_size;
            return static_cast<int>(rc);
        }
        saved_errno = errno;
        log_true_size = attr.log_true_size;
        if (saved_errno == EAGAIN) {
            continue;
        }
        if (saved_errno == ENOSPC &&
            verifier_log_was_truncated(verifier_log, log_true_size)) {
            const size_t next_size =
                next_verifier_log_size(verifier_log.size(), log_true_size);
            if (next_size != 0) {
                verifier_log.assign(next_size, '\0');
                continue;
            }
        }
        return -saved_errno;
    }
    return -(saved_errno != 0 ? saved_errno : EAGAIN);
}

int load_stub_prog(int kfunc_btf_id, int mod_btf_fd, uint32_t chunks,
                   uint32_t callee_saved_mask,
                   uint32_t prog_type_value,
                   const StubLoadAttrs &attrs,
                   bool tail_call_reachable,
                   const std::string &prog_name,
                   const std::vector<int> &map_ref_fds)
{
    if (chunks == 0) {
        fail("chunks must be > 0");
    }
    if (callee_saved_mask > 0xf) {
        fail("native_kernel callee-saved mask exceeds 4 bits");
    }
    ScopedFd tail_call_map_fd;
    if (tail_call_reachable) {
        LIBBPF_OPTS(bpf_map_create_opts, map_opts);
        int fd = bpf_map_create(BPF_MAP_TYPE_PROG_ARRAY,
                                "native_tail_call_probe",
                                sizeof(uint32_t),
                                sizeof(uint32_t),
                                1,
                                &map_opts);
        if (fd < 0) {
            fail("bpf_map_create native tail-call probe map: "
                 + std::string(std::strerror(errno)));
        }
        tail_call_map_fd.fd = fd;
    }

    std::vector<bpf_insn> insns;
    insns.reserve(static_cast<size_t>(2) * chunks +
                  (tail_call_reachable ? 8 : 1));
    if (tail_call_reachable) {
        const size_t probe_off = 1 + static_cast<size_t>(2) * chunks;
        if (probe_off > static_cast<size_t>(std::numeric_limits<int16_t>::max())) {
            fail("native_kernel tail-call probe jump offset exceeds int16");
        }
        insns.push_back(bpf_insn{
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = BPF_REG_0,
            .src_reg = 0,
            .off = 0,
            .imm = 0,
        });
        insns.push_back(bpf_insn{
            .code = BPF_JMP | BPF_JNE | BPF_K,
            .dst_reg = BPF_REG_0,
            .src_reg = 0,
            .off = static_cast<int16_t>(probe_off),
            .imm = 0,
        });
    }
    for (uint32_t i = 0; i < chunks; i++) {
        bpf_insn sidecar = {
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = 0,
            .src_reg = BPF_PSEUDO_KOP_SIDECAR,
            .off = static_cast<int16_t>(callee_saved_mask),
            .imm = static_cast<int32_t>(i),
        };
        insns.push_back(sidecar);
        bpf_insn call = {
            .code = BPF_JMP | BPF_CALL,
            .dst_reg = 0,
            .src_reg = BPF_PSEUDO_KOP_CALL,
            .off = 1, // fd_array slot for module BTF
            .imm = kfunc_btf_id,
        };
        insns.push_back(call);
    }
    insns.push_back(bpf_insn{
        .code = BPF_JMP | BPF_EXIT, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0,
    });
    if (tail_call_reachable) {
        insns.push_back(bpf_insn{
            .code = BPF_LD | BPF_DW | BPF_IMM,
            .dst_reg = BPF_REG_2,
            .src_reg = BPF_PSEUDO_MAP_FD,
            .off = 0,
            .imm = tail_call_map_fd.get(),
        });
        insns.push_back(bpf_insn{
            .code = 0, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0,
        });
        insns.push_back(bpf_insn{
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = BPF_REG_3,
            .src_reg = 0,
            .off = 0,
            .imm = 0,
        });
        insns.push_back(bpf_insn{
            .code = BPF_JMP | BPF_CALL,
            .dst_reg = 0,
            .src_reg = 0,
            .off = 0,
            .imm = BPF_FUNC_tail_call,
        });
        insns.push_back(bpf_insn{
            .code = BPF_JMP | BPF_EXIT, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0,
        });
    }

    // fd_array[0] is the verifier pre-scan slot; fd_array[1] is what `off=1`
    // in the kop call resolves to. Retained map fds follow and are bound via
    // fd_array_cnt, so map retention has no runtime BPF instruction cost.
    std::vector<int> fd_array;
    fd_array.reserve(2 + map_ref_fds.size());
    fd_array.push_back(mod_btf_fd);
    fd_array.push_back(mod_btf_fd);
    for (int fd : map_ref_fds) {
        if (fd < 0) {
            fail("native_kernel retained map ref has invalid fd");
        }
        fd_array.push_back(fd);
    }
    if (fd_array.size() > std::numeric_limits<uint32_t>::max()) {
        fail("native_kernel fd_array too large");
    }
    ScopedFd attach_btf_obj_fd(open_btf_fd_by_id_required(
        attrs.attach_btf_obj_id, "attach_btf_obj_id"));
    ScopedFd attach_prog_fd(open_prog_fd_by_id_required(
        attrs.attach_prog_id, "attach_prog_id"));

    std::vector<char> verifier_log(kInitialVerifierLogSize, '\0');
    uint32_t log_true_size = 0;
    {
        std::ostringstream msg;
        msg << "stub-load-syscall-begin"
            << " name=" << (prog_name.empty() ? "native_lab_stub" : prog_name)
            << " type=" << prog_type_value
            << " chunks=" << chunks
            << " callee_saved_mask=" << callee_saved_mask
            << " tail_call_reachable=" << (tail_call_reachable ? 1 : 0)
            << " insns=" << insns.size()
            << " fd_array_cnt=" << fd_array.size()
            << " attach_prog_fd=" << attach_prog_fd.get()
            << " attach_btf_obj_fd=" << attach_btf_obj_fd.get()
            << " expected_attach_type=" << attrs.expected_attach_type
            << " attach_btf_id=" << attrs.attach_btf_id
            << " attach_btf_obj_id=" << attrs.attach_btf_obj_id
            << " attach_prog_id=" << attrs.attach_prog_id;
        native_loader_kmsg_line(msg.str());
    }
    int fd = bpf_prog_load_native_stub_raw(
        prog_type_value, attrs, attach_prog_fd.get(), attach_btf_obj_fd.get(),
        prog_name, insns, fd_array, verifier_log, log_true_size);
    if (fd < 0) {
        {
            std::ostringstream msg;
            msg << "stub-load-syscall-failed"
                << " name=" << (prog_name.empty() ? "native_lab_stub" : prog_name)
                << " err=" << fd
                << " log_true_size=" << log_true_size
                << " log_buf_size=" << verifier_log.size();
            native_loader_kmsg_line(msg.str());
        }
        std::string message = std::string("BPF_PROG_LOAD native_lab stub: ")
            + libbpf_error_string(fd);
        message += "\nstub verifier_log_size=" + std::to_string(verifier_log.size())
            + " log_true_size=" + std::to_string(log_true_size);
        message += "\nstub fd_array_cnt=" + std::to_string(fd_array.size())
            + " fd_array=";
        for (size_t i = 0; i < fd_array.size(); i++) {
            if (i != 0) {
                message += ",";
            }
            message += std::to_string(i) + ":" + std::to_string(fd_array[i]);
        }
        message += "\nstub insns=";
        for (size_t i = 0; i < insns.size(); i++) {
            if (i != 0) {
                message += ";";
            }
            const bpf_insn &insn = insns[i];
            message += std::to_string(i)
                + ":code=" + std::to_string(insn.code)
                + ",dst=" + std::to_string(insn.dst_reg)
                + ",src=" + std::to_string(insn.src_reg)
                + ",off=" + std::to_string(insn.off)
                + ",imm=" + std::to_string(insn.imm);
        }
        size_t log_size = log_true_size != 0
            ? std::min<size_t>(log_true_size, verifier_log.size())
            : strnlen(verifier_log.data(), verifier_log.size());
        while (log_size > 0 && verifier_log[log_size - 1] == '\0') {
            log_size--;
        }
        if (log_size != 0) {
            constexpr size_t kMaxVerifierLogTail = 8192;
            const size_t start = log_size > kMaxVerifierLogTail
                ? log_size - kMaxVerifierLogTail
                : 0;
            message += "\nverifier log tail:\n";
            message.append(verifier_log.data() + start, log_size - start);
        }
        message += native_lab_kernel_log_tail();
        fail(message);
    }
    {
        std::ostringstream msg;
        msg << "stub-load-syscall-done"
            << " name=" << (prog_name.empty() ? "native_lab_stub" : prog_name)
            << " fd=" << fd
            << " log_true_size=" << log_true_size;
        native_loader_kmsg_line(msg.str());
    }
    return fd;
}

struct Hash64 {
    uint64_t value = 1469598103934665603ULL;

    void add_byte(uint8_t byte)
    {
        value ^= byte;
        value *= 1099511628211ULL;
    }

    void add_u64(uint64_t word)
    {
        for (unsigned i = 0; i < 8; i++) {
            add_byte(static_cast<uint8_t>((word >> (i * 8)) & 0xff));
        }
    }

    void add_bytes(const uint8_t *data, size_t size)
    {
        add_u64(size);
        for (size_t i = 0; i < size; i++) {
            add_byte(data[i]);
        }
    }

    void add_string(const std::string &text)
    {
        add_u64(text.size());
        for (unsigned char ch : text) {
            add_byte(ch);
        }
    }

    std::string hex() const
    {
        char buf[17];
        std::snprintf(buf, sizeof(buf), "%016llx",
                      static_cast<unsigned long long>(value));
        return std::string(buf);
    }
};

void hash_file_contents(Hash64 &hash,
                        const std::filesystem::path &path,
                        const std::string &label)
{
    hash.add_string(label);
    hash.add_string(path.string());
    auto bytes = read_binary_file(path);
    hash.add_bytes(bytes.data(), bytes.size());
}

void hash_file_identity(Hash64 &hash,
                        const std::filesystem::path &path,
                        const std::string &label)
{
    std::error_code ec;
    const auto size = std::filesystem::file_size(path, ec);
    if (ec) {
        fail("stat native-link cache input " + path.string() + ": " + ec.message());
    }
    const auto mtime = std::filesystem::last_write_time(path, ec);
    if (ec) {
        fail("mtime native-link cache input " + path.string() + ": " + ec.message());
    }
    hash.add_string(label);
    hash.add_string(path.string());
    hash.add_u64(size);
    hash.add_u64(static_cast<uint64_t>(mtime.time_since_epoch().count()));
}

struct MapPatchSite {
    std::string name;
    size_t offset = 0;
};

uint64_t parse_decimal_u64(const std::string &text, const std::string &context)
{
    errno = 0;
    char *end = nullptr;
    unsigned long long value = std::strtoull(text.c_str(), &end, 10);
    if (errno != 0 || end == text.c_str() || *end != '\0') {
        fail("parse " + context + ": " + text);
    }
    return static_cast<uint64_t>(value);
}

std::vector<MapPatchSite> read_map_patch_file(const std::filesystem::path &path)
{
    std::ifstream f(path);
    if (!f) {
        fail("read native map patch file: " + path.string());
    }
    std::vector<MapPatchSite> patches;
    std::string line;
    uint64_t line_no = 0;
    while (std::getline(f, line)) {
        line_no++;
        if (line.empty()) {
            continue;
        }
        const size_t tab = line.find('\t');
        if (tab == std::string::npos || line.find('\t', tab + 1) != std::string::npos) {
            fail("invalid native map patch line " + std::to_string(line_no)
                 + " in " + path.string());
        }
        MapPatchSite site;
        site.name = line.substr(0, tab);
        if (site.name.empty()) {
            fail("empty native map patch name in " + path.string());
        }
        const uint64_t offset =
            parse_decimal_u64(line.substr(tab + 1), "native map patch offset");
        if (offset > static_cast<uint64_t>(std::numeric_limits<size_t>::max())) {
            fail("native map patch offset exceeds size_t");
        }
        site.offset = static_cast<size_t>(offset);
        patches.push_back(std::move(site));
    }
    return patches;
}

uint32_t read_link_abi_file(const std::filesystem::path &path)
{
    std::ifstream f(path);
    if (!f) {
        fail("read native-link ABI file: " + path.string());
    }
    bool seen_version = false;
    bool seen_mask = false;
    uint64_t mask = 0;
    std::string line;
    uint64_t line_no = 0;
    while (std::getline(f, line)) {
        line_no++;
        if (line.empty()) {
            continue;
        }
        const size_t tab = line.find('\t');
        if (tab == std::string::npos || line.find('\t', tab + 1) != std::string::npos) {
            fail("invalid native-link ABI line " + std::to_string(line_no)
                 + " in " + path.string());
        }
        const std::string key = line.substr(0, tab);
        const std::string value = line.substr(tab + 1);
        if (key == "version") {
            if (value != "native-link-abi-v2") {
                fail("unsupported native-link ABI version in " + path.string()
                     + ": " + value);
            }
            seen_version = true;
        } else if (key == "callee_saved_mask") {
            mask = parse_decimal_u64(value, "native-link callee-saved mask");
            if (mask > 0xf) {
                fail("native-link callee-saved mask exceeds 4 bits");
            }
            seen_mask = true;
        } else {
            fail("unknown native-link ABI key in " + path.string() + ": " + key);
        }
    }
    if (!seen_version || !seen_mask) {
        fail("native-link ABI file missing required keys: " + path.string());
    }
    return static_cast<uint32_t>(mask);
}

void patch_map_literals(std::vector<uint8_t> &blob,
                        const std::vector<MapPatchSite> &patches,
                        const std::unordered_map<std::string, uint64_t> &map_addrs)
{
    for (const auto &patch : patches) {
        if (patch.offset + sizeof(uint64_t) > blob.size()) {
            fail("native map patch offset exceeds blob bounds for " + patch.name);
        }
        auto it = map_addrs.find(patch.name);
        if (it == map_addrs.end()) {
            fail("native map patch references unknown map " + patch.name);
        }
        uint64_t value = it->second;
        for (unsigned i = 0; i < 8; i++) {
            blob[patch.offset + i] = static_cast<uint8_t>((value >> (i * 8)) & 0xff);
        }
    }
}

std::vector<uint32_t> collect_relocated_map_ids(
    const std::vector<MapPatchSite> &patches,
    const std::unordered_map<std::string, uint32_t> &map_addr_ids)
{
    std::vector<uint32_t> ids;
    std::unordered_set<uint32_t> seen;
    for (const auto &patch : patches) {
        auto it = map_addr_ids.find(patch.name);
        if (it == map_addr_ids.end() || it->second == 0) {
            continue;
        }
        if (seen.insert(it->second).second) {
            ids.push_back(it->second);
        }
    }
    return ids;
}

std::string read_first_line_required(const char *path)
{
    FILE *f = std::fopen(path, "re");
    if (!f) {
        fail("open " + std::string(path) + ": " + std::strerror(errno));
    }
    char line[256];
    if (!std::fgets(line, sizeof(line), f)) {
        int saved_errno = errno;
        std::fclose(f);
        fail("read " + std::string(path) + ": " + std::strerror(saved_errno));
    }
    std::fclose(f);
    line[strcspn(line, "\r\n")] = '\0';
    return line;
}

const char *native_arch_name()
{
#if defined(__aarch64__)
    return "arm64";
#else
    return "x86_64";
#endif
}

const char *helper_symbol_for_id(int helper_id);

const std::unordered_map<std::string, uint64_t> &kallsyms_table()
{
    static std::unordered_map<std::string, uint64_t> table;
    if (!table.empty()) {
        return table;
    }

    std::vector<const char *> wanted;
#if defined(__x86_64__)
    wanted.push_back("cpu_number");
    wanted.push_back("this_cpu_off");
#endif
    for (const auto &helper : kSupportedHelpers) {
        wanted.push_back(helper.symbol);
    }
    for (const char *symbol : kTypedHelperSymbols) {
        wanted.push_back(symbol);
    }
    for (const char *symbol : kRuntimeCallSymbols) {
        wanted.push_back(symbol);
    }
    wanted.push_back(kHtabLookupElemSymbol);
    wanted.push_back(kArrayOfMapLookupElemSymbol);
    wanted.push_back(kHtabLruPercpuMapLookupElemSymbol);
    const size_t wanted_count = wanted.size();

    FILE *f = std::fopen("/proc/kallsyms", "re");
    if (!f) {
        fail("open /proc/kallsyms: " + std::string(std::strerror(errno)));
    }
    char line[512];
    size_t found = 0;
    while (std::fgets(line, sizeof(line), f)) {
        char addr_text[32] = {};
        char type = '\0';
        char name[256] = {};
        if (std::sscanf(line, "%31s %c %255s", addr_text, &type, name) != 3) {
            continue;
        }
        (void)type;
        for (size_t i = 0; i < wanted_count; i++) {
            if (std::strcmp(name, wanted[i]) != 0 || table.count(wanted[i])) {
                continue;
            }
            uint64_t addr = std::strtoull(addr_text, nullptr, 16);
            table.emplace(wanted[i], addr);
            found++;
            break;
        }
        if (found == wanted_count) {
            break;
        }
    }
    std::fclose(f);
    return table;
}

/* Look up kernel symbols that the current helper, map and per-cpu lowerings
 * still need. */
uint64_t kallsyms_lookup(const std::string &name)
{
    const auto &table = kallsyms_table();
    auto it = table.find(name);
    if (it != table.end()) {
        return it->second;
    }
    return 0;
}

uint64_t helper_kernel_addr(int helper_id)
{
    const char *symbol = helper_symbol_for_id(helper_id);
    if (!symbol) {
        return 0;
    }
    return kallsyms_lookup(symbol);
}

uint64_t required_kernel_symbol_addr(const char *symbol)
{
    uint64_t addr = kallsyms_lookup(symbol);
    if (addr == 0) {
        fail(std::string("native_kernel: ") + symbol +
             " is missing from /proc/kallsyms");
    }
    return addr;
}

uint64_t htab_lookup_elem_kernel_addr()
{
    return required_kernel_symbol_addr(kHtabLookupElemSymbol);
}

uint64_t array_of_map_lookup_elem_kernel_addr()
{
    return required_kernel_symbol_addr(kArrayOfMapLookupElemSymbol);
}

uint64_t htab_lru_percpu_map_lookup_elem_kernel_addr()
{
    return required_kernel_symbol_addr(kHtabLruPercpuMapLookupElemSymbol);
}

struct BpfArrayOffsets {
    uint32_t value;
    uint32_t pptrs;
};

struct BpfHtabOffsets {
    uint32_t key;
    uint32_t lru_ref;
};

struct MapMeta {
    std::string name;
    int fd;
    uint32_t kernel_id;
    int type;
    uint32_t key_size;
    uint32_t value_size;
    uint32_t max_entries;
    uint64_t kernel_addr;
    uint64_t value_addr;
};

struct HelperAlias {
    int id;
    const char *link_name;
    const char *kernel_symbol;
};

bool map_matches_shape(const MapMeta &meta, const NativeMapShape &shape)
{
    if (shape.type >= 0 && meta.type != shape.type) {
        return false;
    }
    if (shape.key_size != 0 && meta.key_size != shape.key_size) {
        return false;
    }
    if (shape.value_size != 0 && meta.value_size != shape.value_size) {
        return false;
    }
    if (shape.max_entries != 0 && meta.max_entries != shape.max_entries) {
        return false;
    }
    return true;
}

bool fd_is_bpf_map(int fd)
{
    char fdpath[64];
    char link_target[64];
    std::snprintf(fdpath, sizeof(fdpath), "/proc/self/fd/%d", fd);
    ssize_t n = readlink(fdpath, link_target, sizeof(link_target) - 1);
    if (n <= 0) {
        return false;
    }
    link_target[n] = '\0';
    return std::strcmp(link_target, "anon_inode:bpf-map") == 0;
}

uint32_t roundup_pow2_mask(uint32_t max_entries)
{
    if (max_entries == 0) {
        fail("array map max_entries is zero");
    }
    uint64_t v = static_cast<uint64_t>(max_entries) - 1;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    return static_cast<uint32_t>(v);
}

const char *helper_symbol_for_id(int helper_id)
{
    for (const auto &helper : kSupportedHelpers) {
        if (helper.id == helper_id) {
            return helper.symbol;
        }
    }
    return nullptr;
}

HelperAlias helper_alias_for_call(int helper_id, uint32_t prog_type)
{
    if (helper_id == BPF_FUNC_perf_event_output) {
        if (prog_type == BPF_PROG_TYPE_TRACEPOINT ||
            prog_type == BPF_PROG_TYPE_PERF_EVENT) {
            return HelperAlias{helper_id, "bpf_perf_event_output",
                               "bpf_perf_event_output_tp"};
        }
        if (prog_type == BPF_PROG_TYPE_RAW_TRACEPOINT ||
            prog_type == BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE) {
            return HelperAlias{helper_id, "bpf_perf_event_output",
                               "bpf_perf_event_output_raw_tp"};
        }
        return HelperAlias{helper_id, "bpf_perf_event_output",
                           "bpf_perf_event_output"};
    }
    if (helper_id == BPF_FUNC_get_stackid) {
        if (prog_type == BPF_PROG_TYPE_TRACEPOINT) {
            return HelperAlias{helper_id, "bpf_get_stackid",
                               "bpf_get_stackid_tp"};
        }
        if (prog_type == BPF_PROG_TYPE_PERF_EVENT) {
            return HelperAlias{helper_id, "bpf_get_stackid",
                               "bpf_get_stackid_pe"};
        }
        if (prog_type == BPF_PROG_TYPE_RAW_TRACEPOINT ||
            prog_type == BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE) {
            return HelperAlias{helper_id, "bpf_get_stackid",
                               "bpf_get_stackid_raw_tp"};
        }
        return HelperAlias{helper_id, "bpf_get_stackid", "bpf_get_stackid"};
    }
    if (helper_id == BPF_FUNC_get_stack) {
        if (prog_type == BPF_PROG_TYPE_TRACEPOINT) {
            return HelperAlias{helper_id, "bpf_get_stack", "bpf_get_stack_tp"};
        }
        if (prog_type == BPF_PROG_TYPE_PERF_EVENT) {
            return HelperAlias{helper_id, "bpf_get_stack", "bpf_get_stack_pe"};
        }
        if (prog_type == BPF_PROG_TYPE_RAW_TRACEPOINT ||
            prog_type == BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE) {
            return HelperAlias{helper_id, "bpf_get_stack",
                               "bpf_get_stack_raw_tp"};
        }
        return HelperAlias{helper_id, "bpf_get_stack", "bpf_get_stack"};
    }
    if (helper_id == BPF_FUNC_get_prandom_u32) {
        return HelperAlias{helper_id, "bpf_get_prandom_u32", "bpf_user_rnd_u32"};
    }
    if (helper_id == BPF_FUNC_fib_lookup) {
        if (prog_type == BPF_PROG_TYPE_XDP) {
            return HelperAlias{helper_id, "bpf_fib_lookup", "bpf_xdp_fib_lookup"};
        }
        if (prog_type == BPF_PROG_TYPE_SCHED_CLS ||
            prog_type == BPF_PROG_TYPE_SCHED_ACT) {
            return HelperAlias{helper_id, "bpf_fib_lookup", "bpf_skb_fib_lookup"};
        }
        return HelperAlias{helper_id, "bpf_fib_lookup", nullptr};
    }
    if (helper_id == BPF_FUNC_redirect_map) {
        if (prog_type == BPF_PROG_TYPE_XDP) {
            return HelperAlias{helper_id, "bpf_redirect_map", "bpf_xdp_redirect_map"};
        }
        return HelperAlias{helper_id, "bpf_redirect_map", nullptr};
    }
    if (helper_id == BPF_FUNC_skc_lookup_tcp) {
        if (prog_type == BPF_PROG_TYPE_XDP) {
            return HelperAlias{helper_id, "bpf_skc_lookup_tcp", "bpf_xdp_skc_lookup_tcp"};
        }
        if (prog_type == BPF_PROG_TYPE_SCHED_CLS ||
            prog_type == BPF_PROG_TYPE_SCHED_ACT) {
            return HelperAlias{helper_id, "bpf_skc_lookup_tcp", "bpf_tc_skc_lookup_tcp"};
        }
        return HelperAlias{helper_id, "bpf_skc_lookup_tcp", "bpf_skc_lookup_tcp"};
    }
    if (helper_id == BPF_FUNC_sk_lookup_udp) {
        if (prog_type == BPF_PROG_TYPE_XDP) {
            return HelperAlias{helper_id, "bpf_sk_lookup_udp", "bpf_xdp_sk_lookup_udp"};
        }
        if (prog_type == BPF_PROG_TYPE_SCHED_CLS ||
            prog_type == BPF_PROG_TYPE_SCHED_ACT) {
            return HelperAlias{helper_id, "bpf_sk_lookup_udp", "bpf_tc_sk_lookup_udp"};
        }
        if (prog_type == BPF_PROG_TYPE_CGROUP_SOCK_ADDR) {
            return HelperAlias{helper_id, "bpf_sk_lookup_udp", "bpf_sock_addr_sk_lookup_udp"};
        }
        return HelperAlias{helper_id, "bpf_sk_lookup_udp", "bpf_sk_lookup_udp"};
    }
    const char *symbol = helper_symbol_for_id(helper_id);
    return HelperAlias{helper_id, symbol, symbol};
}

std::optional<std::pair<std::string, uint64_t>>
contextual_helper_alias_if_available(int helper_id, uint32_t prog_type)
{
    const HelperAlias alias = helper_alias_for_call(helper_id, prog_type);
    if (!alias.link_name || !alias.kernel_symbol) {
        return std::nullopt;
    }
    const uint64_t addr = kallsyms_lookup(alias.kernel_symbol);
    if (addr == 0) {
        return std::nullopt;
    }
    return std::make_pair(std::string(alias.link_name), addr);
}

std::string btf_symbol_name_from_func_info(uint32_t btf_id,
                                           const uint8_t *func_info_data,
                                           uint32_t nr_func_info,
                                           uint32_t func_info_rec_size,
                                           const char *inferred_name)
{
    const size_t inferred_len =
        inferred_name ? strnlen(inferred_name, BPF_OBJ_NAME_LEN) : 0;
    const std::string inferred(
        inferred_name ? std::string(inferred_name, inferred_len) : std::string{});

    if (btf_id == 0 || nr_func_info == 0 ||
        func_info_rec_size < sizeof(bpf_func_info)) {
        if (inferred.empty()) {
            fail("loaded BPF program has no name and no BTF func_info");
        }
        return inferred;
    }
    if (!func_info_data) {
        fail("loaded BPF program func_info pointer is null");
    }

    btf *btf_obj = btf__load_from_kernel_by_id(btf_id);
    const long btf_err = libbpf_get_error(btf_obj);
    if (btf_err) {
        fail("btf__load_from_kernel_by_id(" + std::to_string(btf_id) +
             "): " + std::strerror(static_cast<int>(-btf_err)));
    }

    std::string matched_symbol;
    std::string first_symbol;
    for (uint32_t i = 0; i < nr_func_info; ++i) {
        bpf_func_info rec = {};
        const uint8_t *record = func_info_data +
            static_cast<size_t>(i) * func_info_rec_size;
        std::memcpy(&rec, record, sizeof(rec));
        if (rec.type_id == 0) {
            continue;
        }

        const btf_type *type = btf__type_by_id(btf_obj, rec.type_id);
        if (!type || btf_kind(type) != BTF_KIND_FUNC) {
            continue;
        }
        const char *name = btf__name_by_offset(btf_obj, type->name_off);
        if (!name || !name[0]) {
            continue;
        }

        if (first_symbol.empty()) {
            first_symbol = name;
        }
        if (rec.insn_off == 0) {
            std::string entry_symbol = name;
            btf__free(btf_obj);
            return entry_symbol;
        }
        if (inferred_len > 0 &&
            std::strncmp(name, inferred.c_str(), inferred_len) == 0) {
            if (!matched_symbol.empty() && matched_symbol != name) {
                btf__free(btf_obj);
                fail("loaded BPF program truncated name '" + inferred +
                     "' matches multiple BTF functions");
            }
            matched_symbol = name;
        }
    }

    if (!matched_symbol.empty()) {
        btf__free(btf_obj);
        return matched_symbol;
    }
    if (inferred_len > 0 && nr_func_info > 1) {
        btf__free(btf_obj);
        fail("loaded BPF program name '" + inferred +
             "' does not match any BTF function");
    }
    if (first_symbol.empty()) {
        btf__free(btf_obj);
        if (inferred.empty()) {
            fail("loaded BPF program func_info does not contain a named BTF_KIND_FUNC");
        }
        return inferred;
    }
    btf__free(btf_obj);
    return first_symbol;
}

std::string load_prog_btf_symbol_name(int program_fd,
                                      const bpf_prog_info &base_info)
{
    char inferred_name[sizeof(base_info.name) + 1] = {};
    std::memcpy(inferred_name, base_info.name, sizeof(base_info.name));

    if (base_info.btf_id == 0 || base_info.nr_func_info == 0 ||
        base_info.func_info_rec_size < sizeof(bpf_func_info)) {
        if (inferred_name[0] == '\0') {
            fail("loaded BPF program has no name and no BTF func_info");
        }
        return inferred_name;
    }

    const uint64_t bytes =
        static_cast<uint64_t>(base_info.func_info_rec_size) *
        static_cast<uint64_t>(base_info.nr_func_info);
    if (bytes > static_cast<uint64_t>(std::numeric_limits<size_t>::max())) {
        fail("loaded BPF program func_info is too large");
    }
    std::vector<uint8_t> func_info(static_cast<size_t>(bytes));

    bpf_prog_info info = {};
    info.nr_func_info = base_info.nr_func_info;
    info.func_info_rec_size = base_info.func_info_rec_size;
    info.func_info = ptr_to_u64(func_info.data());
    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (func_info) failed: " + libbpf_error_string(err));
    }
    if (info.nr_func_info == 0) {
        if (inferred_name[0] == '\0') {
            fail("loaded BPF program has empty func_info and no name");
        }
        return inferred_name;
    }
    return btf_symbol_name_from_func_info(base_info.btf_id,
                                          func_info.data(),
                                          info.nr_func_info,
                                          info.func_info_rec_size,
                                          inferred_name);
}

std::vector<uint32_t> load_prog_map_ids(int program_fd, uint32_t count)
{
    if (count == 0) {
        return {};
    }
    std::vector<uint32_t> ids(count);
    bpf_prog_info info = {};
    info.nr_map_ids = count;
    info.map_ids = ptr_to_u64(ids.data());
    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (map ids) failed: " + libbpf_error_string(err));
    }
    if (info.nr_map_ids > count) {
        fail("loaded BPF program map id list grew during metadata extraction");
    }
    ids.resize(info.nr_map_ids);
    return ids;
}

std::vector<uint32_t> load_prog_map_ids(int program_fd)
{
    const bpf_prog_info info = load_prog_info(program_fd);
    return load_prog_map_ids(program_fd, info.nr_map_ids);
}

void verify_loaded_prog_uses_maps(int program_fd,
                                  const std::vector<uint32_t> &expected_map_ids)
{
    std::unordered_set<uint32_t> expected;
    for (uint32_t id : expected_map_ids) {
        if (id != 0) {
            expected.insert(id);
        }
    }
    if (expected.empty()) {
        return;
    }

    const std::vector<uint32_t> actual_ids = load_prog_map_ids(program_fd);
    std::unordered_set<uint32_t> actual(actual_ids.begin(), actual_ids.end());
    std::vector<uint32_t> missing;
    for (uint32_t id : expected) {
        if (!actual.count(id)) {
            missing.push_back(id);
        }
    }
    if (missing.empty()) {
        return;
    }

    std::sort(missing.begin(), missing.end());
    std::ostringstream msg;
    msg << "native_loader: loaded native stub missing used_maps for relocated map id(s)";
    for (uint32_t id : missing) {
        msg << " " << id;
    }
    fail(msg.str());
}

bpf_map_info load_map_info(int map_fd)
{
    bpf_map_info info = {};
    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(map_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (map info) failed: " + libbpf_error_string(err));
    }
    return info;
}

uint64_t lookup_array_value_addr_if_direct(const bpf_map_info &info, int map_fd)
{
    if (info.type != BPF_MAP_TYPE_ARRAY || info.max_entries != 1) {
        return 0;
    }
    return lookup_kernel_map_value_ptr_by_fd_if_available(map_fd);
}

MapMeta load_map_meta_from_fd(int map_fd)
{
    bpf_map_info info = load_map_info(map_fd);
    char name[sizeof(info.name) + 1] = {};
    std::memcpy(name, info.name, sizeof(info.name));
    if (name[0] == '\0') {
        fail("loaded BPF program references unnamed map fd " + std::to_string(map_fd));
    }
    return MapMeta{
        std::string(name),
        map_fd,
        info.id,
        static_cast<int>(info.type),
        info.key_size,
        info.value_size,
        info.max_entries,
        lookup_kernel_map_ptr_by_fd(map_fd),
        lookup_array_value_addr_if_direct(info, map_fd),
    };
}

template <typename Predicate>
std::vector<MapMeta> collect_open_process_maps(Predicate predicate)
{
    DIR *fd_dir = opendir("/proc/self/fd");
    if (!fd_dir) {
        fail("opendir /proc/self/fd: " + std::string(std::strerror(errno)));
    }

    std::vector<MapMeta> matches;
    struct dirent *de = nullptr;
    while ((de = readdir(fd_dir)) != nullptr) {
        if (de->d_name[0] < '0' || de->d_name[0] > '9') {
            continue;
        }
        int fd = std::atoi(de->d_name);
        if (fd < 0 || !fd_is_bpf_map(fd)) {
            continue;
        }
        bpf_map_info info = {};
        __u32 info_len = sizeof(info);
        if (bpf_obj_get_info_by_fd(fd, &info, &info_len) != 0) {
            continue;
        }
        char map_name_buf[sizeof(info.name) + 1] = {};
        std::memcpy(map_name_buf, info.name, sizeof(info.name));
        std::string map_name(map_name_buf);
        if (map_name.empty() || !predicate(info, map_name)) {
            continue;
        }
        matches.push_back(MapMeta{
            std::move(map_name),
            fd,
            info.id,
            static_cast<int>(info.type),
            info.key_size,
            info.value_size,
            info.max_entries,
            lookup_kernel_map_ptr_by_fd(fd),
            lookup_array_value_addr_if_direct(info, fd),
        });
    }
    closedir(fd_dir);
    return matches;
}

std::string bpf_obj_name_truncation(const std::string &name);

struct OpenProcessMapsCache {
    bool loaded = false;
    std::vector<MapMeta> maps;
};

thread_local OpenProcessMapsCache *active_open_process_maps_cache = nullptr;

class OpenProcessMapsCacheScope {
public:
    explicit OpenProcessMapsCacheScope(OpenProcessMapsCache &cache)
        : previous_(active_open_process_maps_cache)
    {
        active_open_process_maps_cache = &cache;
    }

    OpenProcessMapsCacheScope(const OpenProcessMapsCacheScope &) = delete;
    OpenProcessMapsCacheScope &operator=(const OpenProcessMapsCacheScope &) = delete;

    ~OpenProcessMapsCacheScope()
    {
        active_open_process_maps_cache = previous_;
    }

private:
    OpenProcessMapsCache *previous_;
};

template <typename Predicate>
std::vector<MapMeta> collect_open_process_maps_cached(Predicate predicate)
{
    OpenProcessMapsCache *cache = active_open_process_maps_cache;
    if (!cache) {
        return collect_open_process_maps(predicate);
    }
    if (!cache->loaded) {
        cache->maps = collect_open_process_maps(
            [](const bpf_map_info &, const std::string &) {
                return true;
            });
        cache->loaded = true;
    }

    std::vector<MapMeta> matches;
    for (const MapMeta &meta : cache->maps) {
        bpf_map_info info = {};
        info.id = meta.kernel_id;
        info.type = static_cast<__u32>(meta.type);
        info.key_size = meta.key_size;
        info.value_size = meta.value_size;
        info.max_entries = meta.max_entries;
        if (predicate(info, meta.name)) {
            matches.push_back(meta);
        }
    }
    return matches;
}

bool find_open_process_map_by_name(const std::string &name,
                                   const std::vector<NativeMapRule> &map_rules,
                                   MapMeta &out)
{
    const std::string truncated = bpf_obj_name_truncation(name);
    std::vector<MapMeta> matches =
        collect_open_process_maps_cached(
            [&](const bpf_map_info &, const std::string &map_name) {
                return map_name == truncated || map_name == name;
            });

    if (matches.empty()) {
        return false;
    }

    const NativeMapShape want_shape = expected_native_map_shape(map_rules, name);
    std::vector<MapMeta> shaped;
    for (const MapMeta &meta : matches) {
        if (!map_matches_shape(meta, want_shape)) {
            continue;
        }
        shaped.push_back(meta);
    }
    if (shaped.empty()) {
        return false;
    }

    if (shaped.size() > 1 && native_map_symbol_is_object_scoped(map_rules, name)) {
        out = *std::max_element(shaped.begin(), shaped.end(),
                                [](const MapMeta &a, const MapMeta &b) {
                                    return a.fd < b.fd;
                                });
        return true;
    }

    bool found = false;
    for (const MapMeta &meta : shaped) {
        if (found && out.kernel_addr != meta.kernel_addr) {
            return false;
        }
        out = meta;
        found = true;
    }
    return found;
}

bool find_open_process_array_data_map_by_name(const std::string &name,
                                              uint64_t min_value_size,
                                              MapMeta &out)
{
    const std::string truncated = bpf_obj_name_truncation(name);
    std::vector<MapMeta> matches =
        collect_open_process_maps_cached(
            [&](const bpf_map_info &info, const std::string &map_name) {
                return (map_name == truncated || map_name == name) &&
                       info.type == BPF_MAP_TYPE_ARRAY &&
                       info.key_size == 4 &&
                       info.max_entries == 1 &&
                       info.value_size >= min_value_size;
            });

    if (matches.empty()) {
        return false;
    }
    out = *std::max_element(matches.begin(), matches.end(),
                            [](const MapMeta &a, const MapMeta &b) {
                                return a.fd < b.fd;
                            });
    return true;
}

std::string read_text_file_limited(const std::filesystem::path &path, size_t limit)
{
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        return {};
    }
    std::string out;
    out.resize(limit);
    input.read(out.data(), static_cast<std::streamsize>(out.size()));
    out.resize(static_cast<size_t>(input.gcount()));
    return out;
}

std::string format_command_limited(const std::vector<std::string> &argv, size_t limit)
{
    std::ostringstream out;
    size_t emitted = 0;
    for (size_t i = 0; i < argv.size(); ++i) {
        const std::string piece = (i == 0 ? "" : " ") + argv[i];
        if (emitted + piece.size() > limit) {
            out << " ... [" << (argv.size() - i) << " argv entries omitted]";
            break;
        }
        out << piece;
        emitted += piece.size();
    }
    return out.str();
}

std::vector<char *> environment_without_ld_preload()
{
    std::vector<char *> clean_env;
    for (char **env = environ; env && *env; ++env) {
        if (std::strncmp(*env, "LD_PRELOAD=", 11) != 0) {
            clean_env.push_back(*env);
        }
    }
    clean_env.push_back(nullptr);
    return clean_env;
}

/* Spawn the native-link binary with the supplied argv. Returns
 * subprocess exit code. */
int run_subprocess(const std::vector<std::string> &argv,
                   const std::filesystem::path &stderr_path)
{
    if (argv.empty()) return -1;
    std::vector<char *> raw;
    raw.reserve(argv.size() + 1);
    for (auto &s : argv) {
        raw.push_back(const_cast<char *>(s.c_str()));
    }
    raw.push_back(nullptr);
    std::vector<char *> clean_env = environment_without_ld_preload();

    pid_t pid = fork();
    if (pid < 0) return -1;
    if (pid == 0) {
        if (!stderr_path.empty()) {
            int fd = open(stderr_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0600);
            if (fd >= 0) {
                dup2(fd, STDERR_FILENO);
                dup2(fd, STDOUT_FILENO);
                if (fd != STDERR_FILENO && fd != STDOUT_FILENO) {
                    close(fd);
                }
            }
        }
        execve(raw[0], raw.data(), clean_env.data());
        std::fprintf(stderr, "execve %s failed: %s\n", raw[0], std::strerror(errno));
        _exit(127);
    }
    int status = 0;
    if (waitpid(pid, &status, 0) < 0) return -1;
    if (!WIFEXITED(status)) return -1;
    return WEXITSTATUS(status);
}

/* Path to the native-link binary. The runner invokes it via fork+exec.
 * Resolution order:
 *   1. `--native-kernel-linker` CLI override.
 *   2. `BPFREJIT_NATIVE_LINK_BINARY` env var.
 *   3. `/usr/local/bin/native-link` from the runtime image. */
std::filesystem::path native_link_binary(const std::filesystem::path &override_path)
{
    if (!override_path.empty()) {
        return override_path;
    }
    if (const char *e = std::getenv("BPFREJIT_NATIVE_LINK_BINARY")) {
        if (e[0] != '\0') {
            return e;
        }
    }
    const std::filesystem::path image_path = "/usr/local/bin/native-link";
    std::error_code ec;
    if (std::filesystem::exists(image_path, ec)) {
        return image_path;
    }
    fail("native_kernel: native-link not found; set BPFREJIT_NATIVE_LINK_BINARY or install /usr/local/bin/native-link");
}

/* Stage 2: given an ELF .native.o input, pass explicit helper/map metadata
 * into native-link. native-link owns machine-code lowering; the runner only
 * loads kernel facts and uploads the resulting blob + relocs. */
struct LinkerOutput {
    std::filesystem::path proof;
    std::filesystem::path blob;
    std::filesystem::path relocs;
    std::filesystem::path map_patches;
    std::filesystem::path abi;
    bool prebuilt_proof = false;
};

struct NativeLinkArgs {
    std::filesystem::path linker;
    struct NameAddr {
        std::string name;
        uint64_t addr = 0;
    };
    struct LookupSite {
        std::string kind;
        uint64_t target_addr = 0;
        uint32_t key_offset = 0;
        uint32_t max_entries = 0;
        uint32_t elem_size = 0;
        uint32_t index_mask = 0;
        uint32_t value_offset = 0;
        uint64_t percpu_base_addr = 0;
        std::string map_name;
    };
    struct LookupMap {
        std::string name;
        LookupSite site;
    };
    struct UpdateSite {
        std::string kind;
        uint64_t target_addr = 0;
        uint32_t max_entries = 0;
        uint32_t elem_size = 0;
        uint32_t value_size = 0;
        uint32_t value_offset = 0;
        uint64_t percpu_base_addr = 0;
        std::string map_name;
    };
    std::vector<NameAddr> helpers;
    std::vector<NameAddr> maps;
    std::vector<std::string> tail_call_maps;
    std::vector<LookupSite> lookup_sites;
    std::vector<LookupMap> lookup_maps;
    std::vector<UpdateSite> update_sites;
    std::string arm64_helper_call_slot = "far_safe";
};

struct LinkedBlob {
    std::vector<uint8_t> blob;
    std::vector<uint8_t> relocs;
    uint64_t cache_lookup_ns = 0;
    uint64_t native_link_exec_ns = 0;
    uint64_t native_link_read_ns = 0;
    uint64_t map_patch_ns = 0;
    bool cache_hit = false;
    bool prebuilt_proof = false;
    uint32_t callee_saved_mask = 0;
    std::vector<uint32_t> relocated_map_ids;
    std::string native_link_summary;
};

struct CompanionLoad {
    uint64_t map_ptr_extract_ns = 0;
    uint64_t lookup_spec_ns = 0;
    uint64_t source_bytecode_bytes = 0;
    bool has_tail_call = false;
    std::unordered_map<std::string, uint64_t> map_addrs;
    std::unordered_map<std::string, uint32_t> map_addr_ids;
    std::unordered_map<std::string, std::string> native_map_symbols;
    std::unordered_map<std::string, MapMeta> exact_map_addrs;
    std::unordered_set<std::string> ambiguous_exact_maps;
    uint32_t prog_type = 0;
    std::vector<MapMeta> maps;
    std::vector<NativeMapRule> map_rules;
    std::vector<MapMeta> source_tail_call_maps;
    /* Per-call-site spec for every `bpf_map_lookup_elem` invocation in
     * the entry program, listed in BPF-source order. Each entry is a
     * (target_kernel_address, key_offset) pair. native-link routes the
     * i-th `bpf_map_lookup_elem` call site to this entry; key_offset>0
     * additionally triggers a 9- or 11-byte post-call inline sequence
     * `test rax,rax; je; add rax, KEY_OFFSET` matching the kernel BPF
     * JIT's `map_gen_lookup` expansion.
     *
     * The pair is decided per-call from the map type discovered by
     * walking the program's BPF source bytecode (track r1's binding
     * through the most recent BPF_LD_IMM64 pseudo_map_fd) and the
     * per-kernel `struct htab_elem` offsets read from BTF. ARRAY and
     * PERCPU_ARRAY sites carry enough metadata for native-link to emit
     * the same bounds-check + pointer arithmetic shape that the kernel
     * JIT emits. Other map types stay on the plain helper until they get
     * their own concrete lowering. */
    struct LookupSite {
        enum class Kind {
            Call,
            Hash,
            LruHash,
            PerCpuHash,
            HashOfMaps,
            Array,
            PerCpuArray,
        } kind;
        uint64_t target_addr;
        uint32_t key_offset;
        uint32_t max_entries;
        uint32_t elem_size;
        uint32_t index_mask;
        uint32_t value_offset;
        uint64_t percpu_base_addr;
        std::string map_name;
    };
    std::vector<LookupSite> lookup_sites;
    struct UpdateSite {
        enum class Kind { Call, Array, PerCpuArray } kind;
        uint64_t target_addr;
        uint32_t max_entries;
        uint32_t elem_size;
        uint32_t value_size;
        uint32_t value_offset;
        uint64_t percpu_base_addr;
        std::string map_name;
    };
    std::vector<UpdateSite> update_sites;
};

void add_source_tail_call_map(CompanionLoad &load, const MapMeta &meta)
{
    if (meta.type != BPF_MAP_TYPE_PROG_ARRAY) {
        return;
    }
    for (const MapMeta &existing : load.source_tail_call_maps) {
        if (existing.kernel_id == meta.kernel_id) {
            return;
        }
    }
    load.source_tail_call_maps.push_back(meta);
}

void add_exact_map_meta(CompanionLoad &load, const MapMeta &meta)
{
    const std::string truncated = bpf_obj_name_truncation(meta.name);
    const std::string keys[] = {meta.name, truncated};

    for (const std::string &key : keys) {
        if (key.empty() || load.ambiguous_exact_maps.count(key)) {
            continue;
        }
        auto it = load.exact_map_addrs.find(key);
        if (it == load.exact_map_addrs.end()) {
            load.exact_map_addrs.emplace(key, meta);
            continue;
        }
        if (it->second.kernel_addr != meta.kernel_addr) {
            load.exact_map_addrs.erase(key);
            load.ambiguous_exact_maps.insert(key);
        }
    }
}

const MapMeta *find_exact_map_meta(const CompanionLoad &load,
                                   const std::string &name)
{
    const std::string truncated = bpf_obj_name_truncation(name);
    const std::string keys[] = {name, truncated};

    for (const std::string &key : keys) {
        if (key.empty()) {
            continue;
        }
        if (load.ambiguous_exact_maps.count(key)) {
            continue;
        }
        auto it = load.exact_map_addrs.find(key);
        if (it != load.exact_map_addrs.end()) {
            return &it->second;
        }
    }
    return nullptr;
}

void add_map_meta(CompanionLoad &load, const MapMeta &meta)
{
    bool duplicate = false;
    for (const MapMeta &existing : load.maps) {
        if (existing.name == meta.name &&
            existing.kernel_addr == meta.kernel_addr) {
            duplicate = true;
            break;
        }
    }
    if (!duplicate) {
        load.maps.push_back(meta);
    }

    bool have = false;
    bool ambiguous = false;
    uint64_t addr = 0;
    for (const MapMeta &existing : load.maps) {
        if (existing.name != meta.name) {
            continue;
        }
        if (!have) {
            have = true;
            addr = existing.kernel_addr;
            continue;
        }
        if (addr != existing.kernel_addr) {
            ambiguous = true;
            break;
        }
    }

    if (ambiguous) {
        load.map_addrs.erase(meta.name);
        load.map_addr_ids.erase(meta.name);
        load.native_map_symbols.erase(meta.name);
    } else {
        load.map_addrs[meta.name] = meta.kernel_addr;
        load.map_addr_ids[meta.name] = meta.kernel_id;
        load.native_map_symbols[meta.name] = meta.name;
    }
}

void add_map_symbol_alias_meta(CompanionLoad &load,
                               const std::string &alias,
                               const MapMeta &meta)
{
    MapMeta alias_meta = meta;
    alias_meta.name = alias;

    auto existing = std::find_if(load.maps.begin(), load.maps.end(),
                                 [&](const MapMeta &m) {
                                     return m.name == alias;
                                 });
    if (existing != load.maps.end()) {
        if (existing->kernel_addr != meta.kernel_addr) {
            fail("native map symbol " + alias +
                 " resolves to multiple kernel addresses");
        }
    } else {
        load.maps.push_back(alias_meta);
    }
    load.map_addrs[alias] = meta.kernel_addr;
    load.map_addr_ids[alias] = meta.kernel_id;
    load.native_map_symbols[alias] = alias;
}

const MapMeta *source_tail_call_map_for_native_symbol(const CompanionLoad &load,
                                                      const MapMeta &candidate)
{
    if (candidate.type != BPF_MAP_TYPE_PROG_ARRAY ||
        load.source_tail_call_maps.size() != 1) {
        return nullptr;
    }
    const MapMeta &source = load.source_tail_call_maps.front();
    if (source.type != BPF_MAP_TYPE_PROG_ARRAY) {
        return nullptr;
    }
    return &source;
}

void add_native_map_symbol_alias_meta(CompanionLoad &load,
                                      const std::string &alias,
                                      const MapMeta &candidate)
{
    if (const MapMeta *source_tail_call =
            source_tail_call_map_for_native_symbol(load, candidate)) {
        add_map_symbol_alias_meta(load, alias, *source_tail_call);
        return;
    }
    add_map_symbol_alias_meta(load, alias, candidate);
}

bool map_matches_native_symbol_rule(const NativeMapRule &rule,
                                    const std::string &symbol,
                                    const MapMeta &meta)
{
    return rule.native_symbol == symbol &&
           native_map_rule_matches(rule, meta.name) &&
           map_matches_shape(meta, rule.shape);
}

bool map_info_matches_native_symbol_rule(const NativeMapRule &rule,
                                         const std::string &symbol,
                                         const bpf_map_info &info,
                                         const std::string &map_name)
{
    MapMeta meta{
        map_name,
        -1,
        info.id,
        static_cast<int>(info.type),
        info.key_size,
        info.value_size,
        info.max_entries,
        0,
        0,
    };
    return map_matches_native_symbol_rule(rule, symbol, meta);
}

bool find_loaded_manifest_native_symbol_map(const CompanionLoad &load,
                                            const std::string &symbol,
                                            MapMeta &out)
{
    bool found = false;
    for (const NativeMapRule &rule : load.map_rules) {
        if (rule.native_symbol != symbol) {
            continue;
        }
        for (const MapMeta &meta : load.maps) {
            if (!map_matches_native_symbol_rule(rule, symbol, meta)) {
                continue;
            }
            if (found && out.kernel_addr != meta.kernel_addr) {
                fail("native map symbol " + symbol +
                     " matches multiple loaded maps through manifest");
            }
            out = meta;
            found = true;
        }
    }
    return found;
}

bool find_open_process_manifest_native_symbol_map(const CompanionLoad &load,
                                                  const std::string &symbol,
                                                  MapMeta &out)
{
    bool object_scoped = false;
    std::vector<MapMeta> matches =
        collect_open_process_maps_cached(
            [&](const bpf_map_info &info, const std::string &map_name) {
                for (const NativeMapRule &rule : load.map_rules) {
                    if (!map_info_matches_native_symbol_rule(rule, symbol,
                                                             info, map_name)) {
                        continue;
                    }
                    object_scoped = object_scoped || rule.object_scoped;
                    return true;
                }
                return false;
            });

    if (matches.empty()) {
        return false;
    }
    if (object_scoped && matches.size() > 1) {
        out = *std::max_element(matches.begin(), matches.end(),
                                [](const MapMeta &a, const MapMeta &b) {
                                    return a.fd < b.fd;
                                });
        return true;
    }

    bool found = false;
    for (const MapMeta &meta : matches) {
        if (found && out.kernel_addr != meta.kernel_addr) {
            fail("native map symbol " + symbol +
                 " matches multiple open process maps through manifest");
        }
        out = meta;
        found = true;
    }
    return found;
}

const MapMeta *find_singleton_array_data_map(const CompanionLoad &load,
                                             const std::string &section_name,
                                             uint64_t min_value_size)
{
    std::vector<const MapMeta *> matches;
    for (const MapMeta &meta : load.maps) {
        if (meta.type != BPF_MAP_TYPE_ARRAY ||
            meta.max_entries != 1 ||
            meta.value_size < min_value_size) {
            continue;
        }
        if (meta.name != section_name && !ends_with(meta.name, section_name)) {
            continue;
        }
        matches.push_back(&meta);
    }
    if (matches.empty()) {
        return nullptr;
    }
    const MapMeta *match = matches[0];
    bool same_object = true;
    for (const MapMeta *candidate : matches) {
        if (candidate->kernel_addr != match->kernel_addr) {
            same_object = false;
            continue;
        }
        if (candidate->value_addr != match->value_addr) {
            fail("multiple ARRAY maps match native data section " + section_name +
                 " with different value addresses: " + match->name +
                 " and " + candidate->name);
        }
    }
    if (!same_object) {
        /* libbpf can keep earlier per-object data maps with the same section
         * name open while loading the next object. Bind data symbols to the
         * newest matching map, which is the object currently being loaded. */
        match = *std::max_element(matches.begin(), matches.end(),
                                  [](const MapMeta *a, const MapMeta *b) {
                                      if (a->kernel_id != b->kernel_id) {
                                          return a->kernel_id < b->kernel_id;
                                      }
                                      return a->fd < b->fd;
                                  });
    }
    return match;
}

const MapMeta *find_array_data_map(CompanionLoad &load,
                                   const std::string &section_name,
                                   uint64_t min_value_size)
{
    if (const MapMeta *map =
            find_singleton_array_data_map(load, section_name, min_value_size)) {
        return map;
    }

    MapMeta process_map{};
    if (!find_open_process_array_data_map_by_name(section_name, min_value_size,
                                                  process_map)) {
        return nullptr;
    }
    const uint64_t addr = process_map.kernel_addr;
    add_map_meta(load, process_map);
    for (const MapMeta &meta : load.maps) {
        if (meta.kernel_addr == addr &&
            (meta.name == section_name || ends_with(meta.name, section_name))) {
            return &meta;
        }
    }
    fail("internal error: added native data map disappeared from metadata");
}

const MapMeta *find_singleton_kconfig_map(const CompanionLoad &load)
{
    const MapMeta *match = nullptr;
    for (const MapMeta &meta : load.maps) {
        if (meta.type != BPF_MAP_TYPE_ARRAY || meta.max_entries != 1 ||
            meta.value_size < sizeof(uint32_t)) {
            continue;
        }
        if (meta.name != "kconfig" && !ends_with(meta.name, ".kconfig")) {
            continue;
        }
        if (match && match->name != meta.name) {
            fail("multiple ARRAY maps match BPF kconfig externs: " +
                 match->name + " and " + meta.name);
        }
        match = &meta;
    }
    return match;
}

void add_known_kconfig_symbol_addrs(CompanionLoad &load)
{
    const MapMeta *map = find_singleton_kconfig_map(load);
    if (!map) {
        return;
    }
    if (map->value_addr == 0) {
        fail("BPF kconfig map " + map->name + " has no direct value address");
    }
    load.map_addrs["LINUX_KERNEL_VERSION"] =
        map->value_addr;
    load.map_addr_ids["LINUX_KERNEL_VERSION"] = map->kernel_id;
}

bool native_data_section_supported(const std::string &section_name)
{
    return section_name == ".bss" ||
           section_name == ".data" ||
           section_name.rfind(".rodata", 0) == 0;
}

std::string bpf_obj_name_truncation(const std::string &name)
{
    constexpr size_t kMaxBpfObjNameLen = BPF_OBJ_NAME_LEN - 1;
    if (name.size() <= kMaxBpfObjNameLen) {
        return name;
    }
    return name.substr(0, kMaxBpfObjNameLen);
}

void add_native_map_symbol_alias(CompanionLoad &load, const std::string &name)
{
    if (const MapMeta *exact = find_exact_map_meta(load, name)) {
        add_native_map_symbol_alias_meta(load, name, *exact);
        return;
    }

    MapMeta manifest_symbol_map{};
    if (find_loaded_manifest_native_symbol_map(load, name, manifest_symbol_map)) {
        add_native_map_symbol_alias_meta(load, name, manifest_symbol_map);
        return;
    }
    if (find_open_process_manifest_native_symbol_map(load, name,
                                                     manifest_symbol_map)) {
        if (!source_tail_call_map_for_native_symbol(load, manifest_symbol_map)) {
            add_map_meta(load, manifest_symbol_map);
        }
        add_native_map_symbol_alias_meta(load, name, manifest_symbol_map);
        return;
    }

    const std::string truncated = bpf_obj_name_truncation(name);
    std::vector<const MapMeta *> matches;
    for (const MapMeta &meta : load.maps) {
        if (meta.name != truncated && meta.name != name) {
            continue;
        }
        matches.push_back(&meta);
    }
    if (!matches.empty()) {
        const MapMeta *match = nullptr;
        if (matches.size() == 1) {
            match = matches[0];
        } else {
            const NativeMapShape want_shape =
                expected_native_map_shape(load.map_rules, name);
            if (want_shape.type >= 0) {
                for (const MapMeta *candidate : matches) {
                    if (!map_matches_shape(*candidate, want_shape)) {
                        continue;
                    }
                    if (match && match->kernel_addr != candidate->kernel_addr) {
                        fail("native map symbol " + name +
                             " matches multiple loaded maps of requested shape");
                    }
                    match = candidate;
                }
            }
            if (!match) {
                fail("native map symbol " + name +
                     " matches multiple loaded maps named " + truncated);
            }
        }
        add_native_map_symbol_alias_meta(load, name, *match);
        return;
    }

    MapMeta process_map{};
    if (find_open_process_map_by_name(name, load.map_rules, process_map)) {
        if (!source_tail_call_map_for_native_symbol(load, process_map)) {
            add_map_meta(load, process_map);
        }
        add_native_map_symbol_alias_meta(load, name, process_map);
    }
}

const MapMeta *find_map_meta_by_loaded_name(const CompanionLoad &load,
                                            const std::string &loaded_name)
{
    const MapMeta *match = nullptr;
    for (const MapMeta &meta : load.maps) {
        if (meta.name == loaded_name) {
            if (match && match->kernel_addr != meta.kernel_addr) {
                fail("loaded map name " + loaded_name +
                     " is ambiguous in native metadata");
            }
            match = &meta;
        }
    }
    return match;
}

bool has_native_map_shape(const NativeMapShape &shape)
{
    return shape.type >= 0;
}

bool native_map_lowering_disabled()
{
    const char *raw = std::getenv("BPFREJIT_NATIVE_DISABLE_MAP_LOWERING");
    if (!raw || !raw[0]) {
        return false;
    }
    return std::strcmp(raw, "1") == 0
        || std::strcmp(raw, "true") == 0
        || std::strcmp(raw, "yes") == 0
        || std::strcmp(raw, "on") == 0;
}

NativeMapShape map_shape_from_meta(const MapMeta &meta)
{
    return NativeMapShape{
        meta.type,
        meta.key_size,
        meta.value_size,
        meta.max_entries,
    };
}

std::string source_map_name_from_manifest(const CompanionLoad &load,
                                          const MapMeta &meta)
{
    std::string resolved;
    for (const NativeMapRule &rule : load.map_rules) {
        bool name_match = native_map_rule_matches(rule, meta.name);
        if (!name_match &&
            rule.match == NativeMapRuleMatch::Exact &&
            starts_with(rule.pattern, meta.name)) {
            name_match = true;
        }
        if (!name_match || !map_matches_shape(meta, rule.shape)) {
            continue;
        }

        const std::string &candidate =
            rule.native_symbol.empty() ? rule.pattern : rule.native_symbol;
        if (candidate.empty()) {
            continue;
        }
        if (!resolved.empty() && resolved != candidate) {
            // Same truncated kernel name and shape: keep the runtime name instead of guessing.
            return meta.name;
        }
        resolved = candidate;
    }
    return resolved.empty() ? meta.name : resolved;
}

NativeMapShape inner_map_shape_for_outer_map(
    const MapMeta &meta,
    const std::vector<NativeMapRule> &map_rules)
{
    if (meta.type != BPF_MAP_TYPE_HASH_OF_MAPS &&
        meta.type != BPF_MAP_TYPE_ARRAY_OF_MAPS) {
        return NativeMapShape{};
    }

    NativeMapShape match{};
    for (const NativeMapRule &rule : map_rules) {
        if (rule.inner_shape.type < 0) {
            continue;
        }
        bool name_match = native_map_rule_matches(rule, meta.name);
        if (!name_match &&
            rule.match == NativeMapRuleMatch::Exact &&
            starts_with(rule.pattern, meta.name)) {
            name_match = true;
        }
        if (!name_match || !map_matches_shape(meta, rule.shape)) {
            continue;
        }
        if (match.type >= 0 &&
            !native_map_shape_equal(match, rule.inner_shape)) {
            fail("manifest map_rules provide ambiguous inner map shape for " +
                 meta.name);
        }
        match = rule.inner_shape;
    }
    return match;
}

bool configure_lookup_site_for_shape(CompanionLoad::LookupSite &site,
                                     const NativeMapShape &shape,
                                     const BpfArrayOffsets &array_offsets,
                                     const BpfHtabOffsets &htab_offsets,
                                     uint64_t this_cpu_off_addr)
{
    if (native_map_lowering_disabled()) {
        return false;
    }
    if (!has_native_map_shape(shape)) {
        return false;
    }

    int t = shape.type;
    if (t == BPF_MAP_TYPE_ARRAY) {
        site.kind = CompanionLoad::LookupSite::Kind::Array;
        site.max_entries = shape.max_entries;
        site.elem_size = (shape.value_size + 7u) & ~7u;
        site.index_mask = roundup_pow2_mask(shape.max_entries);
        site.value_offset = array_offsets.value;
        return true;
    }
    if (t == BPF_MAP_TYPE_PERCPU_ARRAY) {
#if defined(__x86_64__)
        if (this_cpu_off_addr == 0) {
            fail("this_cpu_off not in /proc/kallsyms");
        }
#endif
        site.kind = CompanionLoad::LookupSite::Kind::PerCpuArray;
        site.max_entries = shape.max_entries;
        site.elem_size = sizeof(void *);
        site.index_mask = roundup_pow2_mask(shape.max_entries);
        site.value_offset = array_offsets.pptrs;
        site.percpu_base_addr = this_cpu_off_addr;
        return true;
    }
    if (t == BPF_MAP_TYPE_HASH) {
        uint32_t rounded = (shape.key_size + 7) & ~7u;
        site.target_addr = htab_lookup_elem_kernel_addr();
        site.kind = CompanionLoad::LookupSite::Kind::Hash;
        site.key_offset = htab_offsets.key + rounded;
        return true;
    }
    if (t == BPF_MAP_TYPE_LRU_HASH) {
        uint32_t rounded = (shape.key_size + 7) & ~7u;
        site.target_addr = htab_lookup_elem_kernel_addr();
        site.kind = CompanionLoad::LookupSite::Kind::LruHash;
        site.key_offset = htab_offsets.key + rounded;
        site.value_offset = htab_offsets.lru_ref;
        return true;
    }
    if (t == BPF_MAP_TYPE_PERCPU_HASH) {
        uint32_t rounded = (shape.key_size + 7) & ~7u;
        site.target_addr = htab_lookup_elem_kernel_addr();
        site.kind = CompanionLoad::LookupSite::Kind::PerCpuHash;
        site.key_offset = htab_offsets.key + rounded;
#if defined(__x86_64__)
        if (this_cpu_off_addr == 0) {
            fail("this_cpu_off not in /proc/kallsyms");
        }
#endif
        site.percpu_base_addr = this_cpu_off_addr;
        return true;
    }
    if (t == BPF_MAP_TYPE_LRU_PERCPU_HASH) {
        site.kind = CompanionLoad::LookupSite::Kind::Call;
        site.target_addr = htab_lru_percpu_map_lookup_elem_kernel_addr();
        return true;
    }
    if (t == BPF_MAP_TYPE_HASH_OF_MAPS) {
        /*
         * map-in-map lookups must preserve helper-level semantics. The
         * internal htab lookup returns the raw outer value, while
         * bpf_map_lookup_elem() returns the live inner map pointer that BPF
         * programs pass to the next lookup.
         */
        site.kind = CompanionLoad::LookupSite::Kind::Call;
        site.target_addr = helper_kernel_addr(BPF_FUNC_map_lookup_elem);
        return true;
    }
    if (t == BPF_MAP_TYPE_ARRAY_OF_MAPS) {
        site.kind = CompanionLoad::LookupSite::Kind::Call;
        site.target_addr = array_of_map_lookup_elem_kernel_addr();
        return true;
    }

    return false;
}

bool configure_update_site_for_shape(CompanionLoad::UpdateSite &site,
                                     const NativeMapShape &shape,
                                     int map_fd,
                                     const BpfArrayOffsets &array_offsets,
                                     uint64_t this_cpu_off_addr)
{
    if (native_map_lowering_disabled()) {
        return false;
    }
    if (!has_native_map_shape(shape)) {
        return false;
    }

    const uint32_t value_size = shape.value_size;
    const bool simple_value =
        value_size == 1 || value_size == 2 ||
        value_size == 4 || value_size == 8;
    int t = shape.type;
    if (simple_value && t == BPF_MAP_TYPE_ARRAY) {
        site.kind = CompanionLoad::UpdateSite::Kind::Array;
        site.max_entries = shape.max_entries;
        site.elem_size = (value_size + 7u) & ~7u;
        site.value_size = value_size;
        site.value_offset = array_offsets.value;
        return true;
    }
    if (simple_value && t == BPF_MAP_TYPE_PERCPU_ARRAY) {
#if defined(__x86_64__)
        if (this_cpu_off_addr == 0) {
            fail("this_cpu_off not in /proc/kallsyms");
        }
#endif
        site.kind = CompanionLoad::UpdateSite::Kind::PerCpuArray;
        site.max_entries = shape.max_entries;
        site.elem_size = sizeof(void *);
        site.value_size = value_size;
        site.value_offset = array_offsets.pptrs;
        site.percpu_base_addr = this_cpu_off_addr;
        return true;
    }
    if (t == BPF_MAP_TYPE_HASH) {
        site.target_addr = lookup_kernel_map_update_elem_by_fd(map_fd);
        return true;
    }
    if (t == BPF_MAP_TYPE_LRU_HASH ||
        t == BPF_MAP_TYPE_PERCPU_HASH ||
        t == BPF_MAP_TYPE_LRU_PERCPU_HASH) {
        site.target_addr = lookup_kernel_map_update_elem_by_fd(map_fd);
        return true;
    }
    return false;
}

CompanionLoad::LookupSite lookup_site_for_map_meta(const MapMeta &meta,
                                                   const BpfArrayOffsets &array_offsets,
                                                   const BpfHtabOffsets &htab_offsets,
                                                   uint64_t this_cpu_off_addr)
{
    CompanionLoad::LookupSite site{
        CompanionLoad::LookupSite::Kind::Call,
        helper_kernel_addr(BPF_FUNC_map_lookup_elem),
        0,
        0,
        0,
        0,
        0,
        0,
    };
    site.map_name = meta.name;

    configure_lookup_site_for_shape(site, map_shape_from_meta(meta),
                                    array_offsets, htab_offsets,
                                    this_cpu_off_addr);
    return site;
}

void add_native_data_symbol_addrs(const std::filesystem::path &native_object,
                                  CompanionLoad &load)
{
    int fd = open(native_object.c_str(), O_RDONLY | O_CLOEXEC);
    if (fd < 0) {
        fail("open native object " + native_object.string() + ": " + std::strerror(errno));
    }
    if (elf_version(EV_CURRENT) == EV_NONE) {
        close(fd);
        fail("libelf initialization failed");
    }
    Elf *elf = elf_begin(fd, ELF_C_READ, nullptr);
    if (!elf) {
        close(fd);
        fail("elf_begin " + native_object.string() + ": " + elf_errmsg(-1));
    }
    size_t shstrndx = 0;
    if (elf_getshdrstrndx(elf, &shstrndx) != 0) {
        elf_end(elf);
        close(fd);
        fail("elf_getshdrstrndx " + native_object.string() + ": " + elf_errmsg(-1));
    }

    Elf_Scn *scn = nullptr;
    while ((scn = elf_nextscn(elf, scn)) != nullptr) {
        GElf_Shdr shdr = {};
        if (!gelf_getshdr(scn, &shdr)) {
            elf_end(elf);
            close(fd);
            fail("gelf_getshdr " + native_object.string() + ": " + elf_errmsg(-1));
        }
        if (shdr.sh_type != SHT_SYMTAB && shdr.sh_type != SHT_DYNSYM) {
            continue;
        }
        Elf_Data *data = elf_getdata(scn, nullptr);
        if (!data || shdr.sh_entsize == 0) {
            continue;
        }
        const size_t count = shdr.sh_size / shdr.sh_entsize;
        for (size_t i = 0; i < count; i++) {
            GElf_Sym sym = {};
            if (!gelf_getsym(data, static_cast<int>(i), &sym)) {
                elf_end(elf);
                close(fd);
                fail("gelf_getsym " + native_object.string() + ": " + elf_errmsg(-1));
            }
            const char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);
            if (!name || !name[0]) {
                continue;
            }
            if (sym.st_shndx == SHN_UNDEF) {
                add_native_map_symbol_alias(load, name);
                continue;
            }
            if (GELF_ST_TYPE(sym.st_info) != STT_OBJECT ||
                sym.st_size == 0 ||
                sym.st_shndx >= SHN_LORESERVE) {
                continue;
            }
            Elf_Scn *target_scn = elf_getscn(elf, sym.st_shndx);
            if (!target_scn) {
                continue;
            }
            GElf_Shdr target_shdr = {};
            if (!gelf_getshdr(target_scn, &target_shdr)) {
                elf_end(elf);
                close(fd);
                fail("gelf_getshdr target " + native_object.string() + ": " + elf_errmsg(-1));
            }
            const char *section = elf_strptr(elf, shstrndx, target_shdr.sh_name);
            if (!section) {
                continue;
            }
            if (std::strcmp(section, ".maps") == 0) {
                add_native_map_symbol_alias(load, name);
                continue;
            }
            if (!native_data_section_supported(section)) {
                continue;
            }
            if (sym.st_value < target_shdr.sh_addr) {
                elf_end(elf);
                close(fd);
                fail("native data symbol " + std::string(name) + " is below section base");
            }
            const uint64_t off = sym.st_value - target_shdr.sh_addr;
            const uint64_t symbol_end = off + sym.st_size;
            const MapMeta *map = find_array_data_map(load, section, symbol_end);
            if (!map) {
                continue;
            }
            if (off + sym.st_size > map->value_size) {
                elf_end(elf);
                close(fd);
                fail("native data symbol " + std::string(name) +
                     " exceeds BPF data map value_size for " + map->name);
            }
            if (map->value_addr == 0) {
                elf_end(elf);
                close(fd);
                fail("native data map " + map->name +
                     " has no direct value address for symbol " + std::string(name));
            }
            const std::string symbol_name(name);
            /* A BPF map object can share its ELF name with a data-map symbol;
             * helper calls need the existing struct bpf_map * address. */
            if (load.map_addrs.count(symbol_name)) {
                continue;
            }
            load.map_addrs[symbol_name] = map->value_addr + off;
            load.map_addr_ids[symbol_name] = map->kernel_id;
        }
    }
    elf_end(elf);
    close(fd);
    add_known_kconfig_symbol_addrs(load);
}

#include "native_loader_bytecode.hpp"

CompanionLoad load_from_loaded_program_fd(int program_fd,
                                          const bpf_prog_info &prog_info,
                                          const bpf_insn *source_insns,
                                          size_t source_insn_cnt,
                                          std::vector<NativeMapRule> map_rules)
{
    CompanionLoad out{};
    out.prog_type = prog_info.type;
    out.source_bytecode_bytes = source_insn_cnt * sizeof(bpf_insn);
    out.map_rules = std::move(map_rules);

    const auto map_ptr_start = std::chrono::steady_clock::now();
    const std::vector<uint32_t> map_ids =
        load_prog_map_ids(program_fd, prog_info.nr_map_ids);
    for (uint32_t id : map_ids) {
        int map_fd = bpf_map_get_fd_by_id(id);
        if (map_fd < 0) {
            fail("bpf_map_get_fd_by_id(" + std::to_string(id) + "): " +
                 std::strerror(errno));
        }
        MapMeta meta = load_map_meta_from_fd(map_fd);
        add_map_meta(out, meta);
        add_exact_map_meta(out, meta);
        close(map_fd);
    }
    const auto map_ptr_end = std::chrono::steady_clock::now();
    out.map_ptr_extract_ns = elapsed_ns(map_ptr_start, map_ptr_end);

    const auto lookup_spec_start = std::chrono::steady_clock::now();
    const bpf_insn *insns = source_insns;
    size_t insn_cnt = source_insn_cnt;
    std::vector<uint8_t> xlated_bytes;
    const bool source_map_fds_are_process_fds = insns && insn_cnt > 0;
    if (!insns || insn_cnt == 0) {
        xlated_bytes = load_xlated_program(program_fd, prog_info.xlated_prog_len);
        out.source_bytecode_bytes = xlated_bytes.size();
        if (xlated_bytes.size() % sizeof(bpf_insn) != 0) {
            fail("loaded BPF program xlated image is not a whole number of bpf_insn records");
        }
        insns = reinterpret_cast<const bpf_insn *>(xlated_bytes.data());
        insn_cnt = xlated_bytes.size() / sizeof(bpf_insn);
    }
    std::unordered_map<int, MapMeta> meta_by_source_fd;
    if (source_map_fds_are_process_fds) {
        for (int map_fd : collect_source_map_fds(insns, insn_cnt)) {
            if (meta_by_source_fd.count(map_fd)) {
                continue;
            }
            MapMeta meta = load_map_meta_from_fd(map_fd);
            add_map_meta(out, meta);
            add_exact_map_meta(out, meta);
            meta_by_source_fd.emplace(map_fd, meta);
        }
    }
    std::vector<SourceHelperCall> source_calls =
        collect_source_helper_calls(insns, insn_cnt, &meta_by_source_fd,
                                    &out.map_rules);

    BpfArrayOffsets array_offsets{
        K_BPF_ARRAY_VALUE_OFFSET,
        K_BPF_ARRAY_PPTRS_OFFSET,
    };
    BpfHtabOffsets htab_offsets{
        K_HTAB_ELEM_KEY_OFFSET,
        K_HTAB_ELEM_LRU_REF_OFFSET,
    };
#if defined(__x86_64__)
    uint64_t this_cpu_off_addr = kallsyms_lookup("this_cpu_off");
#else
    uint64_t this_cpu_off_addr = 0;
#endif

    for (const SourceHelperCall &call : source_calls) {
        auto map_it = (call.map_fd >= 0) ? meta_by_source_fd.find(call.map_fd) : meta_by_source_fd.end();
        if (call.helper_id == BPF_FUNC_tail_call) {
            out.has_tail_call = true;
            if (map_it != meta_by_source_fd.end()) {
                add_source_tail_call_map(out, map_it->second);
            }
            continue;
        }
        if (call.helper_id == BPF_FUNC_map_lookup_elem) {
            CompanionLoad::LookupSite site{
                CompanionLoad::LookupSite::Kind::Call,
                helper_kernel_addr(BPF_FUNC_map_lookup_elem),
                0,
                0,
                0,
                0,
                0,
                0,
            };
            if (map_it != meta_by_source_fd.end()) {
                site.map_name = source_map_name_from_manifest(out, map_it->second);
                configure_lookup_site_for_shape(site,
                                                map_shape_from_meta(map_it->second),
                                                array_offsets,
                                                htab_offsets,
                                                this_cpu_off_addr);
            } else {
                configure_lookup_site_for_shape(site,
                                                call.dynamic_map_shape,
                                                array_offsets,
                                                htab_offsets,
                                                this_cpu_off_addr);
            }
            out.lookup_sites.push_back(site);
        } else if (call.helper_id == BPF_FUNC_map_update_elem) {
            CompanionLoad::UpdateSite site{
                CompanionLoad::UpdateSite::Kind::Call,
                helper_kernel_addr(BPF_FUNC_map_update_elem),
                0,
                0,
                0,
                0,
                0,
            };
            if (map_it != meta_by_source_fd.end()) {
                site.map_name = source_map_name_from_manifest(out, map_it->second);
                configure_update_site_for_shape(site,
                                                map_shape_from_meta(map_it->second),
                                                map_it->second.fd,
                                                array_offsets,
                                                this_cpu_off_addr);
            }
            out.update_sites.push_back(site);
        }
    }
    const auto lookup_spec_end = std::chrono::steady_clock::now();
    out.lookup_spec_ns = elapsed_ns(lookup_spec_start, lookup_spec_end);

    return out;
}

#include "native_loader_link_schema.hpp"
#include "native_loader_link_plan.hpp"

std::string native_link_cache_key(const std::filesystem::path &native_elf,
                                  const std::string &symbol_name,
                                  const NativeLinkArgs &link_args)
{
    Hash64 hash;
    hash.add_string(kNativeLinkCacheVersion);
#if defined(__aarch64__)
    hash.add_string("arm64");
#else
    hash.add_string("x86_64");
#endif
    hash_file_contents(hash, native_elf, "native_elf");
    hash.add_string("loaded_prog");
    hash_file_identity(hash, link_args.linker, "native_linker");
    hash.add_string(symbol_name);
    hash.add_string("arm64_helper_call_slot");
    hash.add_string(link_args.arm64_helper_call_slot);
    for (const auto &arg : link_args.helpers) {
        hash.add_string("helper");
        hash.add_string(arg.name);
        hash.add_u64(arg.addr);
    }
    for (const auto &arg : link_args.maps) {
        hash.add_string("map");
        hash.add_string(arg.name);
        hash.add_u64(arg.addr);
    }
    for (const std::string &arg : link_args.tail_call_maps) {
        hash.add_string("tail_call_map");
        hash.add_string(arg);
    }
    for (const NativeLinkArgs::LookupSite &arg : link_args.lookup_sites) {
        hash.add_string("lookup");
        hash.add_string(arg.kind);
        hash.add_u64(arg.target_addr);
        hash.add_u64(arg.key_offset);
        hash.add_u64(arg.max_entries);
        hash.add_u64(arg.elem_size);
        hash.add_u64(arg.index_mask);
        hash.add_u64(arg.value_offset);
        hash.add_u64(arg.percpu_base_addr);
        hash.add_string(arg.map_name);
    }
    for (const NativeLinkArgs::LookupMap &arg : link_args.lookup_maps) {
        hash.add_string("lookup_map");
        hash.add_string(arg.name);
        hash.add_string(arg.site.kind);
        hash.add_u64(arg.site.target_addr);
        hash.add_u64(arg.site.key_offset);
        hash.add_u64(arg.site.max_entries);
        hash.add_u64(arg.site.elem_size);
        hash.add_u64(arg.site.index_mask);
        hash.add_u64(arg.site.value_offset);
        hash.add_u64(arg.site.percpu_base_addr);
    }
    for (const NativeLinkArgs::UpdateSite &arg : link_args.update_sites) {
        hash.add_string("update");
        hash.add_string(arg.kind);
        hash.add_u64(arg.target_addr);
        hash.add_u64(arg.max_entries);
        hash.add_u64(arg.elem_size);
        hash.add_u64(arg.value_size);
        hash.add_u64(arg.value_offset);
        hash.add_u64(arg.percpu_base_addr);
    }
    return hash.hex();
}

uint64_t native_link_name_addr(
    const std::vector<NativeLinkArgs::NameAddr> &items,
    const char *name)
{
    for (const NativeLinkArgs::NameAddr &item : items) {
        if (item.name == name) {
            return item.addr;
        }
    }
    return 0;
}

std::string native_link_plan_summary(const NativeLinkArgs &link_args,
                                     const LinkedBlob &linked)
{
    size_t lookup_call = 0;
    size_t lookup_hash = 0;
    size_t lookup_lru_hash = 0;
    size_t lookup_percpu_hash = 0;
    size_t lookup_hash_of_maps = 0;
    size_t lookup_array = 0;
    size_t lookup_percpu_array = 0;
    for (const NativeLinkArgs::LookupSite &site : link_args.lookup_sites) {
        if (site.kind == "call") {
            lookup_call++;
        } else if (site.kind == "hash") {
            lookup_hash++;
        } else if (site.kind == "lru_hash") {
            lookup_lru_hash++;
        } else if (site.kind == "percpu_hash") {
            lookup_percpu_hash++;
        } else if (site.kind == "hash_of_maps") {
            lookup_hash_of_maps++;
        } else if (site.kind == "array") {
            lookup_array++;
        } else if (site.kind == "percpu_array") {
            lookup_percpu_array++;
        }
    }

    size_t update_call = 0;
    size_t update_array = 0;
    size_t update_percpu_array = 0;
    for (const NativeLinkArgs::UpdateSite &site : link_args.update_sites) {
        if (site.kind == "call") {
            update_call++;
        } else if (site.kind == "array") {
            update_array++;
        } else if (site.kind == "percpu_array") {
            update_percpu_array++;
        }
    }

    std::vector<NativeLabReloc> parsed_relocs =
        parse_native_lab_relocs(linked.relocs, linked.blob.size());
    size_t reloc_helper = 0;
    size_t reloc_arm64_slot = 0;
    size_t reloc_arm64_bl26 = 0;
    size_t reloc_x86_rel32 = 0;
    size_t reloc_percpu_mrs = 0;
    std::unordered_map<uint64_t, size_t> reloc_target_counts;
    for (const NativeLabReloc &reloc : parsed_relocs) {
        if (reloc.kind == kNativeLabRelocHelperCallRel32 ||
            reloc.kind == kNativeLabRelocHelperCallArm64 ||
            reloc.kind == kNativeLabRelocHelperCallArm64Bl26) {
            reloc_helper++;
            reloc_target_counts[reloc.target]++;
        }
        if (reloc.kind == kNativeLabRelocHelperCallArm64) {
            reloc_arm64_slot++;
        } else if (reloc.kind == kNativeLabRelocHelperCallArm64Bl26) {
            reloc_arm64_bl26++;
        } else if (reloc.kind == kNativeLabRelocHelperCallRel32) {
            reloc_x86_rel32++;
        } else if (reloc.kind == kNativeLabRelocArm64PercpuMrs) {
            reloc_percpu_mrs++;
        }
    }
    auto helper_reloc_count = [&](const char *name) -> size_t {
        const uint64_t addr = native_link_name_addr(link_args.helpers, name);
        if (addr == 0) {
            return 0;
        }
        auto it = reloc_target_counts.find(addr);
        return it == reloc_target_counts.end() ? 0 : it->second;
    };

    const uint64_t perf_addr =
        native_link_name_addr(link_args.helpers, "bpf_perf_event_output");
    const uint64_t perf_raw_tp_addr =
        kallsyms_lookup("bpf_perf_event_output_raw_tp");
    const uint64_t perf_generic_addr =
        kallsyms_lookup("bpf_perf_event_output");
    const char *perf_alias = "missing";
    if (perf_addr != 0 && perf_addr == perf_raw_tp_addr) {
        perf_alias = "raw_tp";
    } else if (perf_addr != 0 && perf_addr == perf_generic_addr) {
        perf_alias = "generic";
    } else if (perf_addr != 0) {
        perf_alias = "other";
    }

    std::ostringstream out;
    out << "helper_slot=" << link_args.arm64_helper_call_slot
        << " helpers=" << link_args.helpers.size()
        << " maps=" << link_args.maps.size()
        << " tail_call_maps=" << link_args.tail_call_maps.size()
        << " lookup_sites=" << link_args.lookup_sites.size()
        << " lookup_call=" << lookup_call
        << " lookup_hash=" << lookup_hash
        << " lookup_lru_hash=" << lookup_lru_hash
        << " lookup_percpu_hash=" << lookup_percpu_hash
        << " lookup_hash_of_maps=" << lookup_hash_of_maps
        << " lookup_array=" << lookup_array
        << " lookup_percpu_array=" << lookup_percpu_array
        << " lookup_maps=" << link_args.lookup_maps.size()
        << " update_sites=" << link_args.update_sites.size()
        << " update_call=" << update_call
        << " update_array=" << update_array
        << " update_percpu_array=" << update_percpu_array
        << " relocs=" << parsed_relocs.size()
        << " helper_relocs=" << reloc_helper
        << " arm64_slot_relocs=" << reloc_arm64_slot
        << " arm64_bl26_relocs=" << reloc_arm64_bl26
        << " x86_rel32_relocs=" << reloc_x86_rel32
        << " percpu_mrs_relocs=" << reloc_percpu_mrs
        << " reloc_map_lookup_elem=" << helper_reloc_count("bpf_map_lookup_elem")
        << " reloc_map_update_elem=" << helper_reloc_count("bpf_map_update_elem")
        << " reloc_probe_read_kernel=" << helper_reloc_count("bpf_probe_read_kernel")
        << " reloc_probe_read_kernel_str="
        << helper_reloc_count("bpf_probe_read_kernel_str")
        << " reloc_probe_read_compat="
        << helper_reloc_count("bpf_probe_read_compat")
        << " reloc_get_current_task="
        << helper_reloc_count("bpf_get_current_task")
        << " reloc_get_current_task_btf="
        << helper_reloc_count("bpf_get_current_task_btf")
        << " reloc_get_stackid=" << helper_reloc_count("bpf_get_stackid")
        << " reloc_perf_event_output="
        << helper_reloc_count("bpf_perf_event_output")
        << " perf_event_output_addr=0x" << hex_u64(perf_addr)
        << " perf_raw_tp_addr=0x" << hex_u64(perf_raw_tp_addr)
        << " perf_generic_addr=0x" << hex_u64(perf_generic_addr)
        << " perf_alias=" << perf_alias;
    return out.str();
}

bool linker_output_exists(const LinkerOutput &out)
{
    std::error_code ec;
    return std::filesystem::exists(out.proof, ec)
           && std::filesystem::exists(out.blob, ec)
           && std::filesystem::exists(out.relocs, ec)
           && std::filesystem::exists(out.map_patches, ec)
           && std::filesystem::exists(out.abi, ec);
}

bool env_bool_enabled(const char *name)
{
    const char *raw = std::getenv(name);
    if (!raw || !raw[0]) {
        return false;
    }
    return std::strcmp(raw, "1") == 0
        || std::strcmp(raw, "true") == 0
        || std::strcmp(raw, "yes") == 0
        || std::strcmp(raw, "on") == 0;
}

std::string native_object_proof_stem(const std::filesystem::path &elf_path)
{
    std::string name = elf_path.filename().string();
    static constexpr const char *kSuffix = ".native.o";
    static constexpr size_t kSuffixLen = std::char_traits<char>::length(kSuffix);
    if (name.size() > kSuffixLen &&
        name.compare(name.size() - kSuffixLen, kSuffixLen, kSuffix) == 0) {
        name.resize(name.size() - kSuffixLen);
        return name;
    }
    return elf_path.stem().string();
}

std::optional<std::filesystem::path> find_prebuilt_proof(
    const std::filesystem::path &elf_path,
    const std::string &symbol_name)
{
    std::error_code ec;
    const std::filesystem::path dir = elf_path.parent_path();
    const std::string object_stem = native_object_proof_stem(elf_path);
    std::vector<std::filesystem::path> candidates{
        dir / (object_stem + "." + symbol_name + ".proof.o"),
        dir / (symbol_name + ".proof.o"),
    };
    for (const auto &candidate : candidates) {
        if (std::filesystem::is_regular_file(candidate, ec)) {
            return candidate;
        }
        ec.clear();
    }
    return std::nullopt;
}

void publish_cache_file(const std::filesystem::path &tmp,
                        const std::filesystem::path &dst)
{
    std::error_code ec;
    std::filesystem::rename(tmp, dst, ec);
    if (!ec) {
        return;
    }
    ec.clear();
    std::filesystem::copy_file(
        tmp, dst, std::filesystem::copy_options::overwrite_existing, ec);
    if (ec) {
        fail("publish native-link cache file " + dst.string() + ": " + ec.message());
    }
    std::filesystem::remove(tmp, ec);
}

LinkerOutput invoke_native_link(const std::filesystem::path &elf_path,
                                const std::string &symbol_name,
                                const NativeLinkArgs &link_args,
                                const std::filesystem::path &base)
{
    LinkerOutput out{};
    out.proof = base.string() + ".proof.o";
    out.blob = base.string() + ".blob.bin";
    out.relocs = base.string() + ".relocs.bin";
    out.map_patches = base.string() + ".map-patches.tsv";
    out.abi = base.string() + ".abi.tsv";

    std::optional<std::filesystem::path> prebuilt_proof =
        find_prebuilt_proof(elf_path, symbol_name);
    if (prebuilt_proof) {
        out.prebuilt_proof = true;
        std::error_code copy_ec;
        std::filesystem::copy_file(
            *prebuilt_proof,
            out.proof,
            std::filesystem::copy_options::overwrite_existing,
            copy_ec);
        if (copy_ec) {
            fail("copy prebuilt native-link proof " + prebuilt_proof->string() +
                 " to " + out.proof.string() + ": " + copy_ec.message());
        }
    } else {
        if (env_bool_enabled("BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF")) {
            fail("missing prebuilt native-link proof for " + elf_path.string() +
                 " symbol " + symbol_name);
        }

        std::vector<std::string> proof_argv;
        proof_argv.push_back(link_args.linker.string());
        proof_argv.push_back("--input");
        proof_argv.push_back(elf_path.string());
        proof_argv.push_back("--symbol");
        proof_argv.push_back(symbol_name);
        proof_argv.push_back("--output");
        proof_argv.push_back(out.proof.string());
        proof_argv.push_back("--mode");
        proof_argv.push_back("proof");
        proof_argv.push_back("--preserve-entry-abi");

        const std::filesystem::path proof_stderr = base.string() + ".proof.stderr.txt";
        int proof_rc = run_subprocess(proof_argv, proof_stderr);
        if (proof_rc != 0) {
            std::ostringstream msg;
            const std::string stderr_text = read_text_file_limited(proof_stderr, 2048);
            msg << "native-link proof failed (rc=" << proof_rc << ")";
            if (!stderr_text.empty()) {
                msg << "\nstderr:\n" << stderr_text;
            }
            msg << "\ncommand: " << format_command_limited(proof_argv, 4096);
            fail(msg.str());
        }
        std::error_code proof_ec;
        std::filesystem::remove(proof_stderr, proof_ec);
    }

    std::vector<std::string> argv;
    argv.push_back(link_args.linker.string());
    argv.push_back("--input");
    argv.push_back(out.proof.string());
    argv.push_back("--symbol");
    argv.push_back(symbol_name);
    argv.push_back("--mode");
    argv.push_back("kernel");
    argv.push_back("--output");
    argv.push_back(out.blob.string());
    argv.push_back("--output-relocs");
    argv.push_back(out.relocs.string());
    argv.push_back("--output-map-patches");
    argv.push_back(out.map_patches.string());
    argv.push_back("--output-abi");
    argv.push_back(out.abi.string());
    const std::filesystem::path link_plan =
        write_native_link_plan(link_args, base);
    argv.push_back("--link-plan");
    argv.push_back(link_plan.string());

    const std::filesystem::path kernel_stderr = base.string() + ".kernel.stderr.txt";
    int rc = run_subprocess(argv, kernel_stderr);
    if (rc != 0) {
        std::ostringstream msg;
        const std::string stderr_text = read_text_file_limited(kernel_stderr, 8192);
        msg << "native-link kernel failed (rc=" << rc << ")";
        if (!stderr_text.empty()) {
            msg << "\nstderr:\n" << stderr_text;
        }
        msg << "\ncommand: " << format_command_limited(argv, 4096);
        fail(msg.str());
    }
    std::error_code kernel_ec;
    std::filesystem::remove(kernel_stderr, kernel_ec);
    return out;
}

LinkedBlob load_or_link_native_blob(const std::filesystem::path &native_link_path,
                                    const std::filesystem::path &elf_path,
                                    const std::string &symbol_name,
                                    const CompanionLoad &companion)
{
    const auto cache_lookup_start = std::chrono::steady_clock::now();
    NativeLinkArgs link_args =
        build_native_link_args(native_link_path, companion.map_addrs, companion);
    const std::filesystem::path cache_dir = kNativeLinkCacheDir;
    std::error_code ec;
    std::filesystem::create_directories(cache_dir, ec);
    if (ec) {
        fail("create native-link cache dir " + cache_dir.string() + ": " + ec.message());
    }

    const std::string key =
        native_link_cache_key(elf_path, symbol_name, link_args);
    LinkerOutput cache{};
    cache.proof = cache_dir / (key + ".proof.o");
    cache.blob = cache_dir / (key + ".blob.bin");
    cache.relocs = cache_dir / (key + ".relocs.bin");
    cache.map_patches = cache_dir / (key + ".map-patches.tsv");
    cache.abi = cache_dir / (key + ".abi.tsv");
    const bool cache_hit = linker_output_exists(cache);
    const auto cache_lookup_end = std::chrono::steady_clock::now();

    LinkerOutput source = cache;
    if (!cache_hit) {
        const std::filesystem::path tmp_base =
            cache_dir / (key + ".tmp." + std::to_string(getpid()));
        const auto link_start = std::chrono::steady_clock::now();
        LinkerOutput tmp = invoke_native_link(elf_path, symbol_name, link_args, tmp_base);
        const auto link_end = std::chrono::steady_clock::now();
        source = tmp;

        /* Read the freshly linked template before publishing it. The
         * cache stores map-pointer-neutral bytes; the per-run map
         * addresses are patched only in memory below. */
        const auto read_start = std::chrono::steady_clock::now();
        LinkedBlob linked{
            read_binary_file(source.blob),
            read_binary_file(source.relocs),
            elapsed_ns(cache_lookup_start, cache_lookup_end),
            elapsed_ns(link_start, link_end),
        };
        auto map_patches = read_map_patch_file(source.map_patches);
        linked.relocated_map_ids =
            collect_relocated_map_ids(map_patches, companion.map_addr_ids);
        linked.callee_saved_mask = read_link_abi_file(source.abi);
        linked.prebuilt_proof = source.prebuilt_proof;
        linked.native_link_summary = native_link_plan_summary(link_args, linked);
        const auto read_end = std::chrono::steady_clock::now();
        publish_cache_file(tmp.proof, cache.proof);
        publish_cache_file(tmp.blob, cache.blob);
        publish_cache_file(tmp.relocs, cache.relocs);
        publish_cache_file(tmp.map_patches, cache.map_patches);
        publish_cache_file(tmp.abi, cache.abi);
        const auto patch_start = std::chrono::steady_clock::now();
        patch_map_literals(linked.blob, map_patches, companion.map_addrs);
        const auto patch_end = std::chrono::steady_clock::now();
        linked.native_link_read_ns = elapsed_ns(read_start, read_end);
        linked.map_patch_ns = elapsed_ns(patch_start, patch_end);
        return linked;
    }

    const auto read_start = std::chrono::steady_clock::now();
    LinkedBlob linked{
        read_binary_file(source.blob),
        read_binary_file(source.relocs),
        elapsed_ns(cache_lookup_start, cache_lookup_end),
        0,
    };
    auto map_patches = read_map_patch_file(source.map_patches);
    linked.relocated_map_ids =
        collect_relocated_map_ids(map_patches, companion.map_addr_ids);
    linked.callee_saved_mask = read_link_abi_file(source.abi);
    linked.cache_hit = true;
    linked.native_link_summary = native_link_plan_summary(link_args, linked);
    const auto read_end = std::chrono::steady_clock::now();
    const auto patch_start = std::chrono::steady_clock::now();
    patch_map_literals(linked.blob, map_patches, companion.map_addrs);
    const auto patch_end = std::chrono::steady_clock::now();
    linked.native_link_read_ns = elapsed_ns(read_start, read_end);
    linked.map_patch_ns = elapsed_ns(patch_start, patch_end);
    return linked;
}

struct LoadedStub {
    int prog_fd = -1;
    uint64_t upload_ns = 0;
    uint64_t prog_load_ns = 0;
    uint64_t native_blob_fnv64 = 0;
    uint64_t native_first_reloc_target = 0;
    uint64_t native_last_reloc_target = 0;
    uint32_t native_reloc_count = 0;
    uint32_t native_chunk_count = 0;
    uint32_t native_callee_saved_mask = 0;
    uint32_t native_first_reloc_offset = 0;
    uint32_t native_first_reloc_kind = 0;
    uint32_t native_last_reloc_offset = 0;
    uint32_t native_last_reloc_kind = 0;
};

LoadedStub upload_and_load_stub(const LinkedBlob &linked,
                                uint32_t prog_type,
                                const StubLoadAttrs &attrs,
                                bool tail_call_reachable,
                                const std::string &prog_name,
                                const std::vector<int> &map_ref_fds)
{
    LoadedStub out{};
    std::vector<NativeLabReloc> relocs;
    std::vector<NativeBlobChunk> chunks;

    const auto upload_start = std::chrono::steady_clock::now();
    auto upload_end = upload_start;
    {
        NativeLabUploadLock upload_lock;
        ensure_debugfs_mounted();
        relocs = parse_native_lab_relocs(linked.relocs, linked.blob.size());
        chunks = plan_blob_chunks(linked.blob.size(), relocs);
        out.native_blob_fnv64 = native_blob_fnv64(linked.blob);
        out.native_reloc_count = static_cast<uint32_t>(relocs.size());
        out.native_chunk_count = static_cast<uint32_t>(chunks.size());
        out.native_callee_saved_mask = linked.callee_saved_mask;
        if (!relocs.empty()) {
            const NativeLabReloc &first = relocs.front();
            const NativeLabReloc &last = relocs.back();
            out.native_first_reloc_offset = first.global_offset;
            out.native_first_reloc_kind = first.kind;
            out.native_first_reloc_target = first.target;
            out.native_last_reloc_offset = last.global_offset;
            out.native_last_reloc_kind = last.kind;
            out.native_last_reloc_target = last.target;
        }
        {
            std::ostringstream msg;
            msg << "upload-begin"
                << " name=" << prog_name
                << " type=" << prog_type
                << " blob_bytes=" << linked.blob.size()
                << " blob_fnv=" << hex_u64(out.native_blob_fnv64)
                << " reloc_records=" << relocs.size()
                << " reloc_bytes=" << linked.relocs.size()
                << " chunks=" << chunks.size()
                << " callee_saved_mask=" << linked.callee_saved_mask
                << " tail_call_reachable=" << (tail_call_reachable ? 1 : 0)
                << " retained_map_fds=" << map_ref_fds.size()
                << " relocated_map_ids=" << linked.relocated_map_ids.size()
                << " expected_attach_type=" << attrs.expected_attach_type
                << " attach_btf_id=" << attrs.attach_btf_id
                << " attach_btf_obj_id=" << attrs.attach_btf_obj_id
                << " attach_prog_id=" << attrs.attach_prog_id;
            if (!chunks.empty()) {
                msg << " first_chunk=" << chunks.front().offset << "+"
                    << chunks.front().len
                    << " last_chunk=" << chunks.back().offset << "+"
                    << chunks.back().len;
            }
            if (!relocs.empty()) {
                msg << " first_reloc=" << out.native_first_reloc_offset
                    << ":" << out.native_first_reloc_kind
                    << ":0x" << hex_u64(out.native_first_reloc_target)
                    << " last_reloc=" << out.native_last_reloc_offset
                    << ":" << out.native_last_reloc_kind
                    << ":0x" << hex_u64(out.native_last_reloc_target);
            }
            native_loader_kmsg_line(msg.str());
        }
        upload_blob(linked.blob, chunks);
        upload_relocs(relocs, chunks);
        upload_end = std::chrono::steady_clock::now();
        {
            std::ostringstream msg;
            msg << "upload-done"
                << " name=" << prog_name
                << " blob_bytes=" << linked.blob.size()
                << " reloc_records=" << relocs.size()
                << " chunks=" << chunks.size()
                << " upload_ns=" << elapsed_ns(upload_start, upload_end);
            native_loader_kmsg_line(msg.str());
        }

        const auto prog_load_start = std::chrono::steady_clock::now();
        native_loader_kmsg_line("stub-btf-lookup-begin name=" + prog_name);
        NativeStubBtfIds stub_btf = find_native_stub_btf_ids();
        ScopedFd mod_btf_fd(open_module_btf_fd_by_id(stub_btf.module_btf_id));
        {
            std::ostringstream msg;
            msg << "stub-btf-lookup-done"
                << " name=" << prog_name
                << " module_btf_id=" << stub_btf.module_btf_id
                << " kfunc_btf_id=" << stub_btf.kfunc_btf_id
                << " mod_btf_fd=" << mod_btf_fd.get();
            native_loader_kmsg_line(msg.str());
        }
        try {
            out.prog_fd = load_stub_prog(
                stub_btf.kfunc_btf_id,
                mod_btf_fd.get(),
                static_cast<uint32_t>(chunks.size()),
                linked.callee_saved_mask,
                prog_type,
                attrs,
                tail_call_reachable,
                prog_name,
                map_ref_fds);
        } catch (const std::exception &e) {
            std::ostringstream msg;
            msg << e.what()
                << "\nnative_lab stub context:"
                << " prog_type=" << prog_type
                << " blob_bytes=" << linked.blob.size()
                << " reloc_records=" << relocs.size()
                << " reloc_bytes=" << linked.relocs.size()
                << " chunks=" << chunks.size()
                << " callee_saved_mask=" << linked.callee_saved_mask
                << " tail_call_reachable=" << (tail_call_reachable ? 1 : 0)
                << " retained_map_fds=" << map_ref_fds.size()
                << " relocated_map_ids=" << linked.relocated_map_ids.size()
                << " expected_attach_type=" << attrs.expected_attach_type
                << " attach_btf_id=" << attrs.attach_btf_id
                << " attach_btf_obj_id=" << attrs.attach_btf_obj_id
                << " attach_prog_id=" << attrs.attach_prog_id
                << " module_btf_id=" << stub_btf.module_btf_id
                << " kfunc_btf_id=" << stub_btf.kfunc_btf_id;
            if (!map_ref_fds.empty()) {
                msg << "\nretained_map_info=";
                for (size_t i = 0; i < map_ref_fds.size(); i++) {
                    if (i != 0) {
                        msg << ",";
                    }
                    bpf_map_info info = {};
                    __u32 info_len = sizeof(info);
                    int fd = map_ref_fds[i];
                    if (bpf_obj_get_info_by_fd(fd, &info, &info_len) == 0) {
                        char map_name[sizeof(info.name) + 1] = {};
                        std::memcpy(map_name, info.name, sizeof(info.name));
                        msg << fd << ":id=" << info.id
                            << ":type=" << info.type
                            << ":name=" << map_name;
                    } else {
                        msg << fd << ":info_errno=" << errno;
                    }
                }
            }
            msg << "\n" << native_blob_diagnostics(linked.blob, chunks);
            if (!chunks.empty()) {
                msg << "\nchunk_bytes=";
                for (size_t i = 0; i < chunks.size(); i++) {
                    if (i != 0) {
                        msg << ",";
                    }
                    msg << chunks[i].offset << ":" << chunks[i].len;
                }
            }
            if (!relocs.empty()) {
                msg << "\nreloc_targets=";
                for (size_t i = 0; i < relocs.size(); i++) {
                    if (i != 0) {
                        msg << ",";
                    }
                    msg << relocs[i].global_offset << ":0x"
                        << std::hex << relocs[i].target << std::dec;
                }
            }
            fail(msg.str());
        }
        try {
            verify_loaded_prog_uses_maps(out.prog_fd, linked.relocated_map_ids);
        } catch (...) {
            close(out.prog_fd);
            out.prog_fd = -1;
            throw;
        }
        const auto prog_load_end = std::chrono::steady_clock::now();
        out.prog_load_ns = elapsed_ns(prog_load_start, prog_load_end);
    }
    out.upload_ns = elapsed_ns(upload_start, upload_end);
    return out;
}

std::vector<int> reopen_relocated_map_fds(const std::vector<uint32_t> &map_ids)
{
    std::vector<int> fds;
    std::unordered_set<uint32_t> seen;
    for (uint32_t id : map_ids) {
        if (id == 0 || !seen.insert(id).second) {
            continue;
        }
        int fd = bpf_map_get_fd_by_id(id);
        if (fd < 0) {
            for (int retained_fd : fds) {
                close(retained_fd);
            }
            fail("bpf_map_get_fd_by_id(" + std::to_string(id) +
                 ") for native relocation lifetime: " + std::strerror(errno));
        }
        fcntl(fd, F_SETFD, FD_CLOEXEC);
        fds.push_back(fd);
    }
    return fds;
}

void close_fd_vector(std::vector<int> &fds)
{
    for (int fd : fds) {
        if (fd >= 0) {
            close(fd);
        }
    }
    fds.clear();
}


} // namespace

namespace native_loader {

LoadedProgram load_from_fd(const FdLoadOptions &options)
{
    const auto total_start = std::chrono::steady_clock::now();
    if (options.original_prog_fd < 0) {
        fail("native_loader: missing original_prog_fd");
    }
    if (options.native_object_path.empty() && options.manifest_path.empty()) {
        fail("native_loader: missing native_object_path or manifest_path");
    }
    LoadedProgram out{};
    const bpf_prog_info prog_info = load_prog_info(options.original_prog_fd);
    std::vector<bpf_insn> source_insns;
    if (!options.source_bpf_path.empty() && !options.source_insns.empty()) {
        fail("native_loader: source_bpf_path and source_insns are mutually exclusive");
    }
    if (!options.source_bpf_path.empty()) {
        source_insns = read_bpf_insn_file(options.source_bpf_path);
    } else {
        source_insns = options.source_insns;
    }
    if (!source_insns.empty() && !options.source_fd_array.empty()) {
        canonicalize_source_fd_array(source_insns, options.source_fd_array);
    }
    std::filesystem::path native_object_path = options.native_object_path;
    std::string symbol_name = options.symbol_name;
    std::string source_btf_symbol_name;
    if (symbol_name.empty() && options.source_btf_id != 0 &&
        !options.source_func_info.empty()) {
        if (options.source_func_info_rec_size < sizeof(bpf_func_info) ||
            options.source_func_info.size() %
                options.source_func_info_rec_size != 0) {
            fail("native_loader: invalid source func_info record layout");
        }
        char inferred_name[sizeof(prog_info.name) + 1] = {};
        std::memcpy(inferred_name, prog_info.name, sizeof(prog_info.name));
        source_btf_symbol_name = btf_symbol_name_from_func_info(
            options.source_btf_id,
            options.source_func_info.data(),
            static_cast<uint32_t>(
                options.source_func_info.size() /
                options.source_func_info_rec_size),
            options.source_func_info_rec_size,
            inferred_name);
    }
    std::vector<std::filesystem::path> native_data_object_paths;
    std::vector<NativeMapRule> map_rules;
    uint64_t manifest_resolve_ns = 0;
    if (native_object_path.empty()) {
        if (source_insns.empty()) {
            fail("native_loader: manifest resolution requires source BPF bytecode");
        }
        const auto manifest_start = std::chrono::steady_clock::now();
        std::optional<ManifestResolution> resolution =
            resolve_native_manifest(options.manifest_path,
                                    prog_info,
                                    source_insns,
                                    load_map_info);
        const auto manifest_end = std::chrono::steady_clock::now();
        manifest_resolve_ns = elapsed_ns(manifest_start, manifest_end);
        if (!resolution) {
            out.timings.manifest_resolve_ns = manifest_resolve_ns;
            out.timings.total_ns =
                elapsed_ns(total_start, std::chrono::steady_clock::now());
            return out;
        }
        native_object_path = resolution->native_object_path;
        if (!resolution->symbol_name.empty()) {
            symbol_name = resolution->symbol_name;
        } else if (symbol_name.empty() && !source_btf_symbol_name.empty()) {
            symbol_name = source_btf_symbol_name;
        }
        native_data_object_paths = std::move(resolution->native_data_object_paths);
        map_rules = std::move(resolution->map_rules);
    }
    if (native_data_object_paths.empty()) {
        native_data_object_paths.push_back(native_object_path);
    }
    if (symbol_name.empty()) {
        if (!source_btf_symbol_name.empty()) {
            symbol_name = source_btf_symbol_name;
        } else {
            symbol_name = load_prog_btf_symbol_name(options.original_prog_fd, prog_info);
        }
    }
    CompanionLoad companion =
        load_from_loaded_program_fd(
            options.original_prog_fd,
            prog_info,
            source_insns.empty() ? nullptr : source_insns.data(),
            source_insns.size(),
            std::move(map_rules));
    const auto native_data_symbols_start = std::chrono::steady_clock::now();
    {
        OpenProcessMapsCache open_maps_cache;
        OpenProcessMapsCacheScope open_maps_scope(open_maps_cache);
        for (const std::filesystem::path &path : native_data_object_paths) {
            add_native_data_symbol_addrs(path, companion);
        }
    }
    const auto native_data_symbols_end = std::chrono::steady_clock::now();

    LinkedBlob linked = load_or_link_native_blob(
        options.native_link_path,
        native_object_path,
        symbol_name,
        companion);
    out.selected_native_object = native_object_path.string();
    out.selected_symbol = symbol_name;

    StubLoadAttrs stub_attrs{};
    stub_attrs.expected_attach_type = options.expected_attach_type;
    stub_attrs.attach_btf_id = options.attach_btf_id
        ? options.attach_btf_id
        : prog_info.attach_btf_id;
    stub_attrs.attach_btf_obj_id = options.attach_btf_obj_id
        ? options.attach_btf_obj_id
        : prog_info.attach_btf_obj_id;
    stub_attrs.attach_prog_id = options.attach_prog_id;

    std::vector<int> map_ref_fds =
        reopen_relocated_map_fds(linked.relocated_map_ids);
    const std::string stub_prog_name = prog_info_name_or_stub(prog_info);
    LoadedStub loaded_stub{};
    try {
            loaded_stub = upload_and_load_stub(
                linked,
                prog_info.type,
                stub_attrs,
                companion.has_tail_call && native_lab_needs_tail_call_probe(),
                stub_prog_name,
                map_ref_fds);
        close_fd_vector(map_ref_fds);
    } catch (...) {
        close_fd_vector(map_ref_fds);
        throw;
    }

    out.prog_fd = loaded_stub.prog_fd;
    out.replaced = true;
    out.original_prog_id = prog_info.id;
    out.native_prog_id = load_prog_info(loaded_stub.prog_fd).id;
    out.cache_hit = linked.cache_hit;
    out.prebuilt_proof = linked.prebuilt_proof;
    out.bpf_bytecode_bytes = companion.source_bytecode_bytes;
    out.native_code_bytes = linked.blob.size();
    out.native_blob_fnv64 = loaded_stub.native_blob_fnv64;
    out.native_first_reloc_target = loaded_stub.native_first_reloc_target;
    out.native_last_reloc_target = loaded_stub.native_last_reloc_target;
    out.native_reloc_count = loaded_stub.native_reloc_count;
    out.native_chunk_count = loaded_stub.native_chunk_count;
    out.native_callee_saved_mask = loaded_stub.native_callee_saved_mask;
    out.native_first_reloc_offset = loaded_stub.native_first_reloc_offset;
    out.native_first_reloc_kind = loaded_stub.native_first_reloc_kind;
    out.native_last_reloc_offset = loaded_stub.native_last_reloc_offset;
    out.native_last_reloc_kind = loaded_stub.native_last_reloc_kind;
    out.native_link_summary = linked.native_link_summary;
    out.timings.total_ns =
        elapsed_ns(total_start, std::chrono::steady_clock::now());
    out.timings.manifest_resolve_ns = manifest_resolve_ns;
    out.timings.native_data_symbols_ns =
        elapsed_ns(native_data_symbols_start, native_data_symbols_end);
    out.timings.companion_map_ptr_extract_ns = companion.map_ptr_extract_ns;
    out.timings.companion_lookup_spec_ns = companion.lookup_spec_ns;
    out.timings.cache_lookup_ns = linked.cache_lookup_ns;
    out.timings.native_link_exec_ns = linked.native_link_exec_ns;
    out.timings.native_link_read_ns = linked.native_link_read_ns;
    out.timings.map_patch_ns = linked.map_patch_ns;
    out.timings.upload_ns = loaded_stub.upload_ns;
    out.timings.prog_load_ns = loaded_stub.prog_load_ns;
    return out;
}

void close_loaded_program(LoadedProgram *program)
{
    if (!program) {
        return;
    }
    if (program->prog_fd >= 0) {
        close(program->prog_fd);
        program->prog_fd = -1;
    }
}

} // namespace native_loader

namespace {

void transfer_loaded_program_to_c_result(native_loader::LoadedProgram &loaded,
                                         native_loader_c_result *out)
{
    if (!out) {
        native_loader::close_loaded_program(&loaded);
        return;
    }

    out->prog_fd = loaded.prog_fd;
    out->replaced = loaded.replaced ? 1 : 0;
    out->cache_hit = loaded.cache_hit ? 1 : 0;
    out->prebuilt_proof = loaded.prebuilt_proof ? 1 : 0;
    out->bpf_bytecode_bytes = loaded.bpf_bytecode_bytes;
    out->native_code_bytes = loaded.native_code_bytes;
    out->native_blob_fnv64 = loaded.native_blob_fnv64;
    out->native_first_reloc_target = loaded.native_first_reloc_target;
    out->native_last_reloc_target = loaded.native_last_reloc_target;
    out->native_reloc_count = loaded.native_reloc_count;
    out->native_chunk_count = loaded.native_chunk_count;
    out->native_callee_saved_mask = loaded.native_callee_saved_mask;
    out->native_first_reloc_offset = loaded.native_first_reloc_offset;
    out->native_first_reloc_kind = loaded.native_first_reloc_kind;
    out->native_last_reloc_offset = loaded.native_last_reloc_offset;
    out->native_last_reloc_kind = loaded.native_last_reloc_kind;
    out->original_prog_id = loaded.original_prog_id;
    out->native_prog_id = loaded.native_prog_id;
    std::snprintf(out->selected_native_object,
                  sizeof(out->selected_native_object),
                  "%s",
                  loaded.selected_native_object.c_str());
    std::snprintf(out->selected_symbol,
                  sizeof(out->selected_symbol),
                  "%s",
                  loaded.selected_symbol.c_str());
    std::snprintf(out->native_link_summary,
                  sizeof(out->native_link_summary),
                  "%s",
                  loaded.native_link_summary.c_str());
    out->total_ns = loaded.timings.total_ns;
    out->manifest_resolve_ns = loaded.timings.manifest_resolve_ns;
    out->native_data_symbols_ns = loaded.timings.native_data_symbols_ns;
    out->companion_map_ptr_extract_ns =
        loaded.timings.companion_map_ptr_extract_ns;
    out->companion_lookup_spec_ns = loaded.timings.companion_lookup_spec_ns;
    out->cache_lookup_ns = loaded.timings.cache_lookup_ns;
    out->native_link_exec_ns = loaded.timings.native_link_exec_ns;
    out->native_link_read_ns = loaded.timings.native_link_read_ns;
    out->map_patch_ns = loaded.timings.map_patch_ns;
    out->upload_ns = loaded.timings.upload_ns;
    out->prog_load_ns = loaded.timings.prog_load_ns;
    loaded.prog_fd = -1;
}

} // namespace

extern "C" int native_loader_load_from_fd_with_manifest_path_and_attach(
    int original_prog_fd,
    const char *manifest_path,
    const char *source_bpf_path,
    const int *source_fd_array,
    uint32_t source_fd_array_count,
    uint32_t expected_attach_type,
    uint32_t attach_btf_id,
    uint32_t attach_btf_obj_id,
    uint32_t attach_prog_id,
    struct native_loader_c_result *out)
{
    return native_loader_load_from_fd_with_manifest_path_btf_and_attach(
        original_prog_fd,
        manifest_path,
        source_bpf_path,
        source_fd_array,
        source_fd_array_count,
        0,
        nullptr,
        0,
        0,
        expected_attach_type,
        attach_btf_id,
        attach_btf_obj_id,
        attach_prog_id,
        out);
}

extern "C" int native_loader_load_from_fd_with_manifest_path_btf_and_attach(
    int original_prog_fd,
    const char *manifest_path,
    const char *source_bpf_path,
    const int *source_fd_array,
    uint32_t source_fd_array_count,
    uint32_t source_btf_id,
    const void *source_func_info,
    uint32_t source_func_info_count,
    uint32_t source_func_info_rec_size,
    uint32_t expected_attach_type,
    uint32_t attach_btf_id,
    uint32_t attach_btf_obj_id,
    uint32_t attach_prog_id,
    struct native_loader_c_result *out)
{
    if (out) {
        out->prog_fd = -1;
        out->replaced = 0;
        out->error[0] = '\0';
    }
    if (original_prog_fd < 0 || !manifest_path || !manifest_path[0] ||
        !source_bpf_path || !source_bpf_path[0]) {
        if (out) {
            std::snprintf(out->error, sizeof(out->error),
                          "native_loader_load_from_fd_with_manifest_path_and_attach requires fd, manifest, and source BPF path");
        }
        errno = EINVAL;
        return -1;
    }

    try {
        native_loader::FdLoadOptions options{};
        options.original_prog_fd = original_prog_fd;
        options.manifest_path = manifest_path;
        options.source_bpf_path = source_bpf_path;
        if (source_fd_array_count > 0) {
            if (!source_fd_array) {
                fail("native_loader: source_fd_array_count is non-zero with null fd array");
            }
            options.source_fd_array.assign(
                source_fd_array, source_fd_array + source_fd_array_count);
        }
        if (source_func_info_count > 0 || source_func_info_rec_size > 0 ||
            source_func_info) {
            if (source_btf_id == 0 || !source_func_info ||
                source_func_info_count == 0 ||
                source_func_info_rec_size < sizeof(bpf_func_info)) {
                fail("native_loader: invalid source BTF func_info arguments");
            }
            const uint64_t bytes =
                static_cast<uint64_t>(source_func_info_count) *
                static_cast<uint64_t>(source_func_info_rec_size);
            if (bytes > static_cast<uint64_t>(
                    std::numeric_limits<size_t>::max())) {
                fail("native_loader: source func_info is too large");
            }
            const uint8_t *begin =
                static_cast<const uint8_t *>(source_func_info);
            options.source_btf_id = source_btf_id;
            options.source_func_info_rec_size = source_func_info_rec_size;
            options.source_func_info.assign(
                begin, begin + static_cast<size_t>(bytes));
        }
        options.expected_attach_type = expected_attach_type;
        options.attach_btf_id = attach_btf_id;
        options.attach_btf_obj_id = attach_btf_obj_id;
        options.attach_prog_id = attach_prog_id;
        native_loader::LoadedProgram loaded = native_loader::load_from_fd(options);
        transfer_loaded_program_to_c_result(loaded, out);
        return 0;
    } catch (const std::exception &e) {
        if (out) {
            std::snprintf(out->error, sizeof(out->error), "%s", e.what());
        }
        errno = EINVAL;
        return -1;
    } catch (...) {
        if (out) {
            std::snprintf(out->error, sizeof(out->error), "unknown native-loader error");
        }
        errno = EINVAL;
        return -1;
    }
}
