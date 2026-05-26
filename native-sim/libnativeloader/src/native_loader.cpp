#include "native_loader.hpp"

#include "kernel_offsets.h"

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
#include <cstddef>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <array>
#include <deque>
#include <filesystem>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <string>
#include <string_view>
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

std::string libbpf_error_string(int error_code)
{
    char buffer[256] = {};
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    return std::string(buffer);
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

std::vector<uint8_t> load_jited_program(
    int program_fd,
    uint32_t jited_prog_len,
    bool require_non_empty = true)
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

    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (JIT dump) failed: " + libbpf_error_string(err));
    }

    jited_program.resize(info.jited_prog_len);
    return jited_program;
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
    const char *map_lookup_ptr_path;
    const char *map_lookup_gen_path;
    const char *map_lookup_elem_ptr_path;
    const char *map_update_ptr_path;
    const char *map_delete_ptr_path;
    uint32_t chunk_bytes;
};

#if defined(__aarch64__)
constexpr NativeLabTarget kNativeLabTarget = {
    .module_name = "bpf_arm64_native_lab",
    .kfunc_name = "bpf_arm64_native_lab_emit",
    .module_btf_path = "/sys/kernel/btf/bpf_arm64_native_lab",
    .debugfs_dir = "/sys/kernel/debug/bpf_arm64_native_lab",
    .blob_path_fmt = "/sys/kernel/debug/bpf_arm64_native_lab/blob%u",
    .relocs_path_fmt = nullptr,
    .map_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_ptr",
    .map_value_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_value_ptr",
    .map_lookup_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_lookup_ptr",
    .map_lookup_gen_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_lookup_gen",
    .map_lookup_elem_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_lookup_elem_ptr",
    .map_update_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_update_ptr",
    .map_delete_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_delete_ptr",
    .chunk_bytes = 256,
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
    .map_lookup_ptr_path = "/sys/kernel/debug/bpf_x86_native_lab/map_lookup_ptr",
    .map_lookup_gen_path = "/sys/kernel/debug/bpf_x86_native_lab/map_lookup_gen",
    .map_lookup_elem_ptr_path = "/sys/kernel/debug/bpf_x86_native_lab/map_lookup_elem_ptr",
    .map_update_ptr_path = "/sys/kernel/debug/bpf_x86_native_lab/map_update_ptr",
    .map_delete_ptr_path = "/sys/kernel/debug/bpf_x86_native_lab/map_delete_ptr",
    .chunk_bytes = 128,
};
#endif

constexpr const char *kVmlinuxBtfPath = "/sys/kernel/btf/vmlinux";
constexpr const char *kDebugfsDir = "/sys/kernel/debug";
constexpr uint32_t kMaxBlobs = 512;

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

/* Stage 2 helper names that native-link can match against native relocations.
 * Runtime helper targets come from the loaded program's JIT/xlated oracle, not
 * from kernel symbol lookup. */
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
    {BPF_FUNC_fib_lookup, "bpf_fib_lookup"},
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
    {BPF_FUNC_sk_lookup_tcp, "bpf_sk_lookup_tcp"},
    {BPF_FUNC_sk_lookup_udp, "bpf_sk_lookup_udp"},
    {BPF_FUNC_sk_release, "bpf_sk_release"},
    {BPF_FUNC_map_push_elem, "bpf_map_push_elem"},
    {BPF_FUNC_map_pop_elem, "bpf_map_pop_elem"},
    {BPF_FUNC_sk_fullsock, "bpf_sk_fullsock"},
    {BPF_FUNC_skc_lookup_tcp, "bpf_skc_lookup_tcp"},
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

constexpr const char *kX86BpfMapMaxEntriesOffsetKey =
    "__native_x86_bpf_map_max_entries_offset";
constexpr const char *kX86BpfArrayPtrsOffsetKey = "__native_x86_bpf_array_ptrs_offset";
constexpr const char *kX86BpfProgBpfFuncOffsetKey =
    "__native_x86_bpf_prog_bpf_func_offset";
constexpr const char *kX86TailCallOffsetKey = "__native_x86_tail_call_offset";
constexpr const char *kX86CpuNumberHelperKey = "__native_x86_cpu_number";
constexpr const char *kX86ThisCpuOffHelperKey = "__native_x86_this_cpu_off";
constexpr const char *kX86CurrentTaskHelperKey = "__native_x86_current_task";
#if defined(__aarch64__)
constexpr const char *kArm64ThreadInfoCpuOffsetHelperKey =
    "__native_arm64_thread_info_cpu_offset";
#endif
constexpr const char *kNativeLinkCacheDir = "/tmp/native_kernel_link_cache";
constexpr const char *kNativeLinkCacheVersion = "native-link-template-cache-v47";
constexpr const char *kNativeStubBtfCachePath = "/tmp/native_kernel_stub_btf.tsv";
constexpr const char *kNativeStubBtfCacheVersion = "native-stub-btf-cache-v1";
constexpr int kLibbpfCoreBadRelocPoison = 195896080; // 0xbad2310

#ifndef BPF_PSEUDO_KINSN_SIDECAR
#define BPF_PSEUDO_KINSN_SIDECAR 3
#endif
#ifndef BPF_PSEUDO_KINSN_CALL
#define BPF_PSEUDO_KINSN_CALL 4
#endif
#ifndef K_BPF_MAP_MAX_ENTRIES_OFFSET
#define K_BPF_MAP_MAX_ENTRIES_OFFSET 68u
#endif
#ifndef K_BPF_ARRAY_PTRS_OFFSET
#define K_BPF_ARRAY_PTRS_OFFSET K_BPF_ARRAY_VALUE_OFFSET
#endif
#ifndef K_HTAB_ELEM_KEY_OFFSET
#define K_HTAB_ELEM_KEY_OFFSET 48u
#endif
#ifndef K_HTAB_ELEM_LRU_REF_OFFSET
#define K_HTAB_ELEM_LRU_REF_OFFSET 35u
#endif
#ifndef K_BPF_PROG_BPF_FUNC_OFFSET
#define K_BPF_PROG_BPF_FUNC_OFFSET 72u
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

bool try_query_native_lab_by_fd(int map_fd,
                                const char *path,
                                const char *label,
                                size_t max_response,
                                std::string &out)
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
        if (saved == EOPNOTSUPP) {
            return false;
        }
        fail(std::string("write ") + path + ": " + std::strerror(saved));
    }

    if (lseek(fd, 0, SEEK_SET) < 0) {
        saved = errno;
        close(fd);
        fail(std::string("lseek ") + path + ": " + std::strerror(saved));
    }

    std::vector<char> response(max_response + 1, '\0');
    ssize_t n = read(fd, response.data(), max_response);
    saved = errno;
    close(fd);
    if (n <= 0) {
        if (saved == EOPNOTSUPP) {
            return false;
        }
        fail(std::string("read ") + path + ": " + std::strerror(saved));
    }
    if (static_cast<size_t>(n) == max_response) {
        fail(std::string("native_kernel: truncated ") + label + " response");
    }
    response[static_cast<size_t>(n)] = '\0';
    out.assign(response.data(), static_cast<size_t>(n));
    return true;
}

std::string query_native_lab_by_fd(int map_fd,
                                   const char *path,
                                   const char *label,
                                   size_t max_response)
{
    std::string response;
    if (!try_query_native_lab_by_fd(map_fd, path, label, max_response, response)) {
        fail(std::string("query ") + path + ": " + std::strerror(EOPNOTSUPP));
    }
    return response;
}

bool try_lookup_native_lab_ptr_by_fd(int map_fd,
                                     const char *path,
                                     const char *label,
                                     uint64_t &out);

uint64_t lookup_native_lab_ptr_by_fd(int map_fd,
                                     const char *path,
                                     const char *label)
{
    uint64_t value = 0;
    if (!try_lookup_native_lab_ptr_by_fd(map_fd, path, label, value)) {
        fail(std::string("query ") + path + ": " + std::strerror(EOPNOTSUPP));
    }
    return value;
}

bool try_lookup_native_lab_ptr_by_fd(int map_fd,
                                     const char *path,
                                     const char *label,
                                     uint64_t &out)
{
    std::string response;
    if (!try_query_native_lab_by_fd(map_fd, path, label, 64, response)) {
        return false;
    }

    errno = 0;
    char *end = nullptr;
    unsigned long long value = std::strtoull(response.c_str(), &end, 0);
    if (errno != 0 || end == response.c_str() || value == 0) {
        fail(std::string("native_kernel: invalid ") + label + " response: " + response);
    }
    out = static_cast<uint64_t>(value);
    return true;
}

uint8_t parse_hex_nibble(char ch, const std::string &label)
{
    if (ch >= '0' && ch <= '9') {
        return static_cast<uint8_t>(ch - '0');
    }
    if (ch >= 'a' && ch <= 'f') {
        return static_cast<uint8_t>(ch - 'a' + 10);
    }
    if (ch >= 'A' && ch <= 'F') {
        return static_cast<uint8_t>(ch - 'A' + 10);
    }
    fail("native_kernel: non-hex character in " + label);
}

std::vector<uint8_t> parse_hex_bytes(const std::string &hex,
                                     const std::string &label)
{
    if (hex.size() % 2 != 0) {
        fail("native_kernel: odd-length hex in " + label);
    }
    std::vector<uint8_t> out;
    out.reserve(hex.size() / 2);
    for (size_t i = 0; i < hex.size(); i += 2) {
        uint8_t hi = parse_hex_nibble(hex[i], label);
        uint8_t lo = parse_hex_nibble(hex[i + 1], label);
        out.push_back(static_cast<uint8_t>((hi << 4) | lo));
    }
    return out;
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

uint64_t lookup_kernel_map_lookup_ptr_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_lookup_ptr_path, "map_lookup_ptr");
}

uint64_t lookup_kernel_map_lookup_elem_ptr_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_lookup_elem_ptr_path, "map_lookup_elem_ptr");
}

std::vector<uint8_t> lookup_kernel_map_lookup_gen_by_fd(int map_fd)
{
    std::string response;
    if (!try_query_native_lab_by_fd(
            map_fd, kNativeLabTarget.map_lookup_gen_path, "map_lookup_gen",
            8192, response)) {
        return {};
    }
    std::istringstream input(response);
    size_t insn_count = 0;
    std::string hex;
    if (!(input >> insn_count >> hex)) {
        fail("native_kernel: invalid map_lookup_gen response: " + response);
    }
    if (insn_count == 0) {
        fail("native_kernel: empty map_lookup_gen response");
    }
    if (hex.size() != insn_count * sizeof(bpf_insn) * 2) {
        fail("native_kernel: map_lookup_gen length mismatch in response: " + response);
    }
    return parse_hex_bytes(hex, "map_lookup_gen");
}

uint64_t lookup_kernel_map_update_ptr_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_update_ptr_path, "map_update_ptr");
}

bool try_lookup_kernel_map_update_ptr_by_fd(int map_fd, uint64_t &out)
{
    return try_lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_update_ptr_path, "map_update_ptr", out);
}

uint64_t lookup_kernel_map_delete_ptr_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_delete_ptr_path, "map_delete_ptr");
}

constexpr size_t kRelocRecordBytes = 16;
constexpr size_t kNativeLabRelocBytes = 5;
constexpr uint32_t kNativeLabRelocHelperCallRel32 = 1;

struct NativeLabReloc {
    uint32_t global_offset;
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
        if (kind != kNativeLabRelocHelperCallRel32) {
            fail("native_lab reloc has unknown kind " + std::to_string(kind));
        }
        if (static_cast<size_t>(global_offset) + kNativeLabRelocBytes > blob_size) {
            fail("native_lab reloc call offset exceeds blob bounds");
        }
        out.push_back(NativeLabReloc{
            global_offset,
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
        /* A helper-call reloc slot must fit inside one kinsn emit chunk. */
        for (const NativeLabReloc &reloc : relocs) {
            const size_t reloc_start = reloc.global_offset;
            const size_t reloc_end = reloc_start + kNativeLabRelocBytes;
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
#if defined(__aarch64__)
    (void)relocs;
    (void)chunk_id;
    fail(std::string("native_lab relocs are not supported by module ")
         + kNativeLabTarget.module_name);
#else
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
#endif
}

void upload_relocs(const std::vector<NativeLabReloc> &relocs,
                   const std::vector<NativeBlobChunk> &chunks)
{
    if (relocs.empty()) {
        return;
    }
    if (!kNativeLabTarget.relocs_path_fmt) {
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
            const size_t reloc_end = reloc_start + kNativeLabRelocBytes;
            if (reloc_start < chunk.offset || reloc_end > chunk_end) {
                continue;
            }
            const uint32_t local_offset =
                static_cast<uint32_t>(reloc_start - chunk.offset);
            append_u32_le(by_chunk[chunk_id], local_offset);
            append_u32_le(by_chunk[chunk_id], kNativeLabRelocHelperCallRel32);
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
        if (!by_chunk[i].empty()) {
            upload_reloc_chunk(by_chunk[i], i);
        }
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
    uint32_t prog_btf_id = 0;
    uint32_t attach_btf_obj_id = 0;
    uint32_t attach_prog_id = 0;
};

struct ScopedFd {
    int fd = -1;

    ScopedFd() = default;
    explicit ScopedFd(int value) : fd(value) {}
    ScopedFd(const ScopedFd &) = delete;
    ScopedFd &operator=(const ScopedFd &) = delete;
    ScopedFd(ScopedFd &&other) noexcept : fd(other.fd) { other.fd = -1; }
    ScopedFd &operator=(ScopedFd &&other) noexcept
    {
        if (this != &other) {
            if (fd >= 0) {
                close(fd);
            }
            fd = other.fd;
            other.fd = -1;
        }
        return *this;
    }
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

// Build the (sidecar; call kinsn)*N; exit stub and BPF_PROG_LOAD it via
// libbpf's bpf_prog_load + bpf_prog_load_opts.fd_array. Returns prog fd.
void append_dummy_map_refs(std::vector<bpf_insn> &insns,
                           const std::vector<int> &map_ref_fds)
{
    if (map_ref_fds.empty()) {
        return;
    }

    if (map_ref_fds.size() >
        static_cast<size_t>(std::numeric_limits<int16_t>::max() / 2)) {
        fail("native_kernel dummy map ref jump offset exceeds int16");
    }
    insns.push_back(bpf_insn{
        .code = BPF_ALU64 | BPF_MOV | BPF_K,
        .dst_reg = BPF_REG_1,
        .src_reg = 0,
        .off = 0,
        .imm = 1,
    });
    insns.push_back(bpf_insn{
        .code = BPF_JMP | BPF_JEQ | BPF_K,
        .dst_reg = BPF_REG_1,
        .src_reg = 0,
        .off = static_cast<int16_t>(map_ref_fds.size() * 2),
        .imm = 1,
    });
    for (int fd : map_ref_fds) {
        if (fd < 0) {
            fail("native_kernel dummy map ref has invalid fd");
        }
        insns.push_back(bpf_insn{
            .code = BPF_LD | BPF_DW | BPF_IMM,
            .dst_reg = BPF_REG_1,
            .src_reg = BPF_PSEUDO_MAP_FD,
            .off = 0,
            .imm = fd,
        });
        insns.push_back(bpf_insn{
            .code = 0, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0,
        });
    }
}

int load_stub_prog(int kfunc_btf_id, int mod_btf_fd, uint32_t chunks,
                   uint32_t callee_saved_mask,
                   uint32_t prog_type_value,
                   const StubLoadAttrs &attrs,
                   bool tail_call_reachable,
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
    const size_t dummy_ref_insns =
        map_ref_fds.empty() ? 0 : 2 + map_ref_fds.size() * 2;
    insns.reserve(static_cast<size_t>(2) * chunks + dummy_ref_insns +
                  (tail_call_reachable ? 8 : 1));
    if (tail_call_reachable) {
        const size_t probe_off = 1 + static_cast<size_t>(2) * chunks +
                                 dummy_ref_insns;
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
            .src_reg = BPF_PSEUDO_KINSN_SIDECAR,
            .off = static_cast<int16_t>(callee_saved_mask),
            .imm = static_cast<int32_t>(i),
        };
        insns.push_back(sidecar);
        bpf_insn call = {
            .code = BPF_JMP | BPF_CALL,
            .dst_reg = 0,
            .src_reg = BPF_PSEUDO_KINSN_CALL,
            .off = 1, // fd_array slot for module BTF
            .imm = kfunc_btf_id,
        };
        insns.push_back(call);
    }
    append_dummy_map_refs(insns, map_ref_fds);
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

    // fd_array[0] is the verifier's pre-scan slot; the ReJIT path duplicates
    // the module BTF fd there. fd_array[1] is what `off=1` in the
    // kinsn call insn resolves to.
    int fd_array[2] = {mod_btf_fd, mod_btf_fd};
    ScopedFd prog_btf_fd(open_btf_fd_by_id_required(
        attrs.prog_btf_id, "prog_btf_id"));
    ScopedFd attach_btf_obj_fd(open_btf_fd_by_id_required(
        attrs.attach_btf_obj_id, "attach_btf_obj_id"));
    ScopedFd attach_prog_fd(open_prog_fd_by_id_required(
        attrs.attach_prog_id, "attach_prog_id"));

    LIBBPF_OPTS(bpf_prog_load_opts, opts,
        .expected_attach_type = static_cast<bpf_attach_type>(attrs.expected_attach_type),
        .prog_btf_fd = static_cast<uint32_t>(prog_btf_fd.get() >= 0 ? prog_btf_fd.get() : 0),
        .attach_btf_id = attrs.attach_btf_id,
        .attach_prog_fd = static_cast<uint32_t>(attach_prog_fd.get() >= 0 ? attach_prog_fd.get() : 0),
        .attach_btf_obj_fd = static_cast<uint32_t>(attach_btf_obj_fd.get() >= 0 ? attach_btf_obj_fd.get() : 0),
        .fd_array = fd_array,
    );
    int fd = bpf_prog_load(static_cast<bpf_prog_type>(prog_type_value),
                           "native_lab_stub", "GPL",
                           insns.data(), insns.size(), &opts);
    if (fd < 0) {
        const int saved_errno = errno;
        std::vector<char> log_buf(256 * 1024);
        auto log_opts = opts;
        log_opts.log_level = 1;
        log_opts.log_size = static_cast<__u32>(log_buf.size());
        log_opts.log_buf = log_buf.data();
        int diag_fd = bpf_prog_load(static_cast<bpf_prog_type>(prog_type_value),
                                    "native_lab_stub", "GPL",
                                    insns.data(), insns.size(), &log_opts);
        if (diag_fd >= 0) {
            close(diag_fd);
        }
        std::string message = std::string("bpf_prog_load (native_lab stub): ")
            + std::strerror(saved_errno);
        if (log_buf[0] != '\0') {
            message += "\nverifier log:\n";
            message += log_buf.data();
        }
        fail(message);
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

struct BpfArrayOffsets {
    uint32_t value;
    uint32_t ptrs;
    uint32_t htab_key;
    uint32_t htab_lru_ref;
    uint64_t this_cpu_off;
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
};

bool ends_with(const std::string &value, const std::string &suffix)
{
    return value.size() >= suffix.size() &&
           value.compare(value.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool starts_with(const std::string &value, const std::string &prefix)
{
    return value.size() >= prefix.size() &&
           value.compare(0, prefix.size(), prefix) == 0;
}

int parse_otel_stack_delta_bucket(const std::string &name)
{
    constexpr std::string_view prefix = "exe_id_to_";
    if (name.compare(0, prefix.size(), prefix) != 0) {
        return -1;
    }
    size_t pos = prefix.size();
    int bucket = 0;
    bool saw_digit = false;
    while (pos < name.size() && std::isdigit(static_cast<unsigned char>(name[pos]))) {
        saw_digit = true;
        bucket = bucket * 10 + (name[pos] - '0');
        pos++;
    }
    if (!saw_digit || pos >= name.size() || name[pos] != '_') {
        return -1;
    }
    if (bucket < 8 || bucket > 23) {
        return -1;
    }
    return bucket;
}

struct NativeMapShape {
    int type = -1;
    uint32_t key_size = 0;
    uint32_t value_size = 0;
    uint32_t max_entries = 0;
};

NativeMapShape expected_native_map_shape(const std::string &name)
{
    if (parse_otel_stack_delta_bucket(name) >= 0) {
        return NativeMapShape{BPF_MAP_TYPE_HASH_OF_MAPS, 8, 4, 0};
    }
    if (ends_with(name, "_fix")) {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 0, 0, 0};
    }
    if (ends_with(name, "_dyn")) {
        return NativeMapShape{BPF_MAP_TYPE_LPM_TRIE, 0, 0, 0};
    }
    if (ends_with(name, "_version")) {
        return NativeMapShape{BPF_MAP_TYPE_HASH_OF_MAPS, 0, 4, 64};
    }
    if (name == "cilium_ratelimit_metrics") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 4, 8, 64};
    }
    if (name == "cilium_ratelimit") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 8, 16, 1024};
    }
    if (name == "cilium_lb4_reverse_nat") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 2, 6, 65536};
    }
    if (name == "cilium_lb6_reverse_nat") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 2, 18, 65536};
    }
    if (name == "cilium_snat_v4_external") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 14, 40, 591428};
    }
    if (name == "cilium_snat_v4_alloc_retries") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4, 33};
    }
    if (name == "cilium_l2_responder_v4") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 8, 4096};
    }
    if (name == "cilium_l2_responder_v6") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 24, 8, 4096};
    }
    if (name == "cilium_devices") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 4, 16, 512};
    }
    if (name == "cilium_policy_v2") {
        return NativeMapShape{BPF_MAP_TYPE_LPM_TRIE, 12, 12, 16384};
    }
    if (name == "cilium_nodeport_nat_buffer") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 18, 1};
    }
    if (name == "cilium_nodeport_neigh4") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 4, 8, 0};
    }
    if (name == "cilium_nodeport_neigh6") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 16, 8, 0};
    }
    if (name == "cilium_tail_call_buffer6") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 60, 1};
    }
    if (name == "cilium_tail_call_buffer4") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 60, 1};
    }
    if (name == "execve_calls") {
        return NativeMapShape{BPF_MAP_TYPE_PROG_ARRAY, 4, 4, 2};
    }
    if (name == "perf_progs" || name == "kprobe_progs") {
        return NativeMapShape{BPF_MAP_TYPE_PROG_ARRAY, 4, 4, 10};
    }
    if (name == "tcpmon_map") {
        return NativeMapShape{BPF_MAP_TYPE_PERF_EVENT_ARRAY, 4, 4, 8};
    }
    if (name == "tg_rb_events") {
        return NativeMapShape{BPF_MAP_TYPE_RINGBUF, 0, 0, 524288};
    }
    if (name == "buffer_heap_map") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4352, 1};
    }
    if (starts_with(name, "string_maps_") && name != "string_maps_heap") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8};
    }
    if (name == "string_maps_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 16384, 1};
    }
    if (name == "substring_map") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 100, 1};
    }
    if (name == "tg_errmetrics_map") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_PERCPU_HASH, 12, 4, 1024};
    }
    if (name == "tg_conf_map") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 48, 1};
    }
    if (name == "policy_conf") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 1, 1};
    }
    if (name == "execve_msg_heap_map") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 6224, 1};
    }
    if (name == "tg_binary_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 792, 1};
    }
    if (name == "tg_parents_bin") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 4, 792, 1};
    }
    if (name == "execve_map") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 4, 896, 32768};
    }
    if (name == "execve_map_stats") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, 3};
    }
    if (name == "execve_val") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 896, 1};
    }
    if (name == "execve_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4112, 1};
    }
    if (name == "tg_execve_joined_info_map") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 8, 16, 8192};
    }
    if (name == "tg_execve_joined_info_map_stats") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, 3};
    }
    if (name == "tg_stats_map") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 14336, 1};
    }
    if (name == "tg_cgrps_tracking_map") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 144, 32768};
    }
    if (name == "tg_cgrps_tracking_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 144, 1};
    }
    if (name == "tg_cgrps_msg_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4312, 1};
    }
    if (name == "tg_cgtracker_map") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 8, 1};
    }
    if (name == "string_prefix_maps") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8};
    }
    if (name == "string_prefix_maps_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 260, 1};
    }
    if (name == "string_postfix_maps") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8};
    }
    if (name == "string_postfix_maps_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 132, 1};
    }
    if (name == "cgroup_rate_options_map") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 16, 1};
    }
    if (name == "cgroup_rate_map") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_HASH, 8, 40, 1};
    }
    if (name == "throttle_heap_map") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 160, 1};
    }
    if (name == "tg_mbset_map") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 256, 8, 1024};
    }
    if (name == "tg_mbset_gen") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 8, 1};
    }
    if (name == "data_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 32768, 1};
    }
    if (name == "heap_ro_zero") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 16384, 1};
    }
    if (name == "heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 4104, 1};
    }
    if (name == "process_call_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 25632, 1};
    }
    if (name == "override_tasks") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 4, 1};
    }
    if (name == "enforcer_data") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 12, 1};
    }
    if (name == "enforcer_missed_notifications") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 12, 4, 128};
    }
    if (name == "ratelimit_map") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 224, 8, 0};
    }
    if (name == "ratelimit_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 352, 1};
    }
    if (name == "retprobe_map") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 16, 24, 1024};
    }
    if (name == "fdinstall_map") {
        return NativeMapShape{BPF_MAP_TYPE_LRU_HASH, 16, 4104, 0};
    }
    if (name == "stack_trace_map") {
        return NativeMapShape{BPF_MAP_TYPE_STACK_TRACE, 4, 1016, 0};
    }
    if (name == "sleepable_preload") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 4100, 0};
    }
    if (name == "tg_ipv6_ext_heap") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 8, 1};
    }
    if (name == "tg_mb_sel_opts") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 12, 10};
    }
    if (name == "tg_mb_paths") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 10};
    }
    if (name == "addr4lpm_maps") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8};
    }
    if (name == "addr6lpm_maps") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8};
    }
    if (name == "policy_stats") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 80, 1};
    }
    if (name == "filter_map") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 4096, 1};
    }
    if (name == "config_map") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 736, 1};
    }
    if (name == "write_offload") {
        return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 16, 1};
    }
    if (name == "argfilter_maps") {
        return NativeMapShape{BPF_MAP_TYPE_ARRAY_OF_MAPS, 4, 4, 8};
    }
    if (name == "policy_filter_maps") {
        return NativeMapShape{BPF_MAP_TYPE_HASH_OF_MAPS, 4, 4, 128};
    }
    if (name == "policy_filter_cgroup_maps") {
        return NativeMapShape{BPF_MAP_TYPE_HASH_OF_MAPS, 8, 4, 1024};
    }
    if (name == "exit_heap_map") {
        return NativeMapShape{BPF_MAP_TYPE_PERCPU_ARRAY, 4, 40, 1};
    }
    return NativeMapShape{};
}

bool newest_open_process_map_is_object_scoped(const std::string &name)
{
    return name == "cilium_devices" ||
           name == "cilium_policy_v2" ||
           name == "cilium_nodeport_nat_buffer" ||
           name == "cilium_nodeport_neigh4" ||
           name == "cilium_nodeport_neigh6" ||
           name == "cilium_tail_call_buffer6" ||
           name == "cilium_tail_call_buffer4" ||
           name == "execve_calls" ||
           name == "tcpmon_map" ||
           name == "tg_rb_events" ||
           name == "buffer_heap_map" ||
           starts_with(name, "string_maps_") ||
           name == "substring_map" ||
           name == "tg_errmetrics_map" ||
           name == "tg_conf_map" ||
           name == "policy_conf" ||
           name == "execve_msg_heap_map" ||
           name == "tg_binary_heap" ||
           name == "tg_parents_bin" ||
           name == "execve_map" ||
           name == "execve_map_stats" ||
           name == "execve_val" ||
           name == "execve_heap" ||
           name == "tg_execve_joined_info_map" ||
           name == "tg_execve_joined_info_map_stats" ||
           name == "tg_stats_map" ||
           name == "tg_cgrps_tracking_map" ||
           name == "tg_cgrps_tracking_heap" ||
           name == "tg_cgrps_msg_heap" ||
           name == "tg_cgtracker_map" ||
           name == "string_prefix_maps" ||
           name == "string_prefix_maps_heap" ||
           name == "string_postfix_maps" ||
           name == "string_postfix_maps_heap" ||
           name == "cgroup_rate_options_map" ||
           name == "cgroup_rate_map" ||
           name == "throttle_heap_map" ||
           name == "tg_mbset_map" ||
           name == "tg_mbset_gen" ||
           name == "data_heap" ||
           name == "heap_ro_zero" ||
           name == "heap" ||
           name == "process_call_heap" ||
           name == "override_tasks" ||
           name == "enforcer_data" ||
           name == "enforcer_missed_notifications" ||
           name == "ratelimit_map" ||
           name == "ratelimit_heap" ||
           name == "retprobe_map" ||
           name == "fdinstall_map" ||
           name == "stack_trace_map" ||
           name == "sleepable_preload" ||
           name == "tg_ipv6_ext_heap" ||
           name == "tg_mb_sel_opts" ||
           name == "tg_mb_paths" ||
           name == "addr4lpm_maps" ||
           name == "addr6lpm_maps" ||
           name == "policy_stats" ||
           name == "filter_map" ||
           name == "config_map" ||
           name == "write_offload" ||
           name == "argfilter_maps" ||
           name == "policy_filter_maps" ||
           name == "policy_filter_cgroup_maps" ||
           name == "exit_heap_map";
}

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
    (void)prog_type;
    if (helper_id == BPF_FUNC_get_prandom_u32) {
        return HelperAlias{helper_id, "bpf_get_prandom_u32"};
    }
    if (helper_id == BPF_FUNC_fib_lookup) {
        return HelperAlias{helper_id, "bpf_fib_lookup"};
    }
    if (helper_id == BPF_FUNC_redirect_map) {
        return HelperAlias{helper_id, "bpf_redirect_map"};
    }
    if (helper_id == BPF_FUNC_skc_lookup_tcp) {
        return HelperAlias{helper_id, "bpf_skc_lookup_tcp"};
    }
    if (helper_id == BPF_FUNC_sk_lookup_udp) {
        return HelperAlias{helper_id, "bpf_sk_lookup_udp"};
    }
    const char *symbol = helper_symbol_for_id(helper_id);
    return HelperAlias{helper_id, symbol};
}

std::vector<uint64_t> load_jited_ksyms(int program_fd, uint32_t count)
{
    if (count == 0) {
        fail("kernel did not report a JIT image base symbol");
    }
    std::vector<uint64_t> ksyms(count);
    bpf_prog_info info = {};
    info.nr_jited_ksyms = count;
    info.jited_ksyms = ptr_to_u64(ksyms.data());
    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (JIT ksyms) failed: " + libbpf_error_string(err));
    }
    ksyms.resize(info.nr_jited_ksyms);
    if (ksyms.empty() || ksyms[0] == 0) {
        fail("kernel returned an empty JIT ksym table");
    }
    return ksyms;
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

    btf *btf_obj = btf__load_from_kernel_by_id(base_info.btf_id);
    const long btf_err = libbpf_get_error(btf_obj);
    if (btf_err) {
        fail("btf__load_from_kernel_by_id(" + std::to_string(base_info.btf_id) +
             "): " + std::strerror(static_cast<int>(-btf_err)));
    }

    const size_t inferred_len = strnlen(inferred_name, sizeof(base_info.name));
    std::string matched_symbol;
    std::string first_symbol;
    for (uint32_t i = 0; i < info.nr_func_info; ++i) {
        bpf_func_info rec = {};
        const uint8_t *record = func_info.data() +
            static_cast<size_t>(i) * info.func_info_rec_size;
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
        if (inferred_len > 0 && std::strncmp(name, inferred_name, inferred_len) == 0) {
            if (!matched_symbol.empty() && matched_symbol != name) {
                btf__free(btf_obj);
                fail("loaded BPF program truncated name '" + std::string(inferred_name) +
                     "' matches multiple BTF functions");
            }
            matched_symbol = name;
        }
    }

    if (!matched_symbol.empty()) {
        btf__free(btf_obj);
        return matched_symbol;
    }
    if (inferred_len > 0 && info.nr_func_info > 1) {
        btf__free(btf_obj);
        fail("loaded BPF program name '" + std::string(inferred_name) +
             "' does not match any BTF function");
    }
    if (first_symbol.empty()) {
        btf__free(btf_obj);
        if (inferred_name[0] == '\0') {
            fail("loaded BPF program func_info does not contain a named BTF_KIND_FUNC");
        }
        return inferred_name;
    }
    btf__free(btf_obj);
    return first_symbol;
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

std::string map_info_name(const bpf_map_info &info)
{
    char name[sizeof(info.name) + 1] = {};
    std::memcpy(name, info.name, sizeof(info.name));
    return std::string(name);
}

std::string format_map_fd(int fd)
{
    if (fd < 0) {
        return "fd=-1";
    }
    bpf_map_info info = {};
    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(fd, &info, &info_len);
    if (err != 0) {
        std::ostringstream out;
        out << "fd=" << fd << "(info_errno=" << errno << ")";
        return out.str();
    }
    std::ostringstream out;
    out << "fd=" << fd
        << ":id=" << info.id
        << ":type=" << info.type
        << ":name=" << map_info_name(info)
        << ":key=" << info.key_size
        << ":value=" << info.value_size
        << ":max=" << info.max_entries;
    return out.str();
}

std::string format_map_id(uint32_t id)
{
    if (id == 0) {
        return "id=0";
    }
    int fd = bpf_map_get_fd_by_id(id);
    if (fd < 0) {
        std::ostringstream out;
        out << "id=" << id << "(open_errno=" << errno << ")";
        return out.str();
    }
    std::string formatted = format_map_fd(fd);
    close(fd);
    return formatted;
}

std::string format_map_ids(const std::vector<uint32_t> &ids)
{
    std::ostringstream out;
    out << "[";
    for (size_t i = 0; i < ids.size(); i++) {
        if (i != 0) {
            out << ", ";
        }
        if (i >= 32) {
            out << "...";
            break;
        }
        out << format_map_id(ids[i]);
    }
    out << "]";
    return out.str();
}

std::string format_map_fds(const std::vector<int> &fds)
{
    std::ostringstream out;
    out << "[";
    for (size_t i = 0; i < fds.size(); i++) {
        if (i != 0) {
            out << ", ";
        }
        if (i >= 32) {
            out << "...";
            break;
        }
        out << format_map_fd(fds[i]);
    }
    out << "]";
    return out.str();
}

uint64_t lookup_array_value_addr_if_direct(const bpf_map_info &info, int map_fd)
{
    if (info.type != BPF_MAP_TYPE_ARRAY || info.max_entries != 1) {
        return 0;
    }
    return lookup_kernel_map_value_ptr_by_fd(map_fd);
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

std::string bpf_obj_name_truncation(const std::string &name);

bool find_open_process_map_by_name(const std::string &name, MapMeta &out)
{
    DIR *fd_dir = opendir("/proc/self/fd");
    if (!fd_dir) {
        fail("opendir /proc/self/fd: " + std::string(std::strerror(errno)));
    }

    const std::string truncated = bpf_obj_name_truncation(name);
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
        char map_name[sizeof(info.name) + 1] = {};
        std::memcpy(map_name, info.name, sizeof(info.name));
        if (map_name[0] == '\0' ||
            (map_name != truncated && map_name != name)) {
            continue;
        }

        MapMeta meta{
            std::string(map_name),
            fd,
            info.id,
            static_cast<int>(info.type),
            info.key_size,
            info.value_size,
            info.max_entries,
            lookup_kernel_map_ptr_by_fd(fd),
            lookup_array_value_addr_if_direct(info, fd),
        };
        matches.push_back(std::move(meta));
    }
    closedir(fd_dir);

    if (matches.empty()) {
        return false;
    }

    const NativeMapShape want_shape = expected_native_map_shape(name);
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

    if (shaped.size() > 1 && newest_open_process_map_is_object_scoped(name)) {
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
    DIR *fd_dir = opendir("/proc/self/fd");
    if (!fd_dir) {
        fail("opendir /proc/self/fd: " + std::string(std::strerror(errno)));
    }

    const std::string truncated = bpf_obj_name_truncation(name);
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
        char map_name[sizeof(info.name) + 1] = {};
        std::memcpy(map_name, info.name, sizeof(info.name));
        if (map_name[0] == '\0' ||
            (map_name != truncated && map_name != name) ||
            info.type != BPF_MAP_TYPE_ARRAY ||
            info.key_size != 4 ||
            info.max_entries != 1 ||
            info.value_size < min_value_size) {
            continue;
        }
        matches.push_back(MapMeta{
            std::string(map_name),
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

/* Stage 2: given an ELF .native.o input, pass the loaded program's JIT
 * oracle and map metadata into native-link. native-link owns target decoding
 * and machine-code lowering; the runner only loads kernel facts and uploads
 * the resulting blob + relocs. */
struct LinkerOutput {
    std::filesystem::path proof;
    std::filesystem::path blob;
    std::filesystem::path relocs;
    std::filesystem::path map_patches;
    std::filesystem::path abi;
};

struct NativeLinkArgs {
    std::filesystem::path linker;
    uint64_t oracle_jit_base = 0;
    std::vector<uint8_t> oracle_jited;
    std::vector<uint8_t> oracle_xlated;
    std::vector<int> source_helper_ids;
    std::vector<std::string> helpers;
    std::vector<std::string> maps;
    std::vector<std::string> lookup_sites;
    std::vector<std::string> lookup_gens;
    std::vector<std::string> lookup_maps;
    std::vector<std::string> update_maps;
    std::vector<std::string> update_sites;
};

struct LinkedBlob {
    std::vector<uint8_t> blob;
    std::vector<uint8_t> relocs;
    uint64_t cache_lookup_ns = 0;
    uint64_t native_link_exec_ns = 0;
    uint64_t native_link_read_ns = 0;
    uint64_t map_patch_ns = 0;
    uint32_t callee_saved_mask = 0;
    std::vector<uint32_t> relocated_map_ids;
};

struct ProgramLoadPlan {
    uint64_t object_load_ns = 0;
    uint64_t map_ptr_extract_ns = 0;
    uint64_t lookup_spec_ns = 0;
    uint64_t oracle_jit_base = 0;
    uint64_t x86_cpu_number_addr = 0;
    uint64_t x86_this_cpu_off = 0;
    uint64_t x86_current_task_addr = 0;
    std::vector<uint8_t> oracle_jited;
    std::vector<uint8_t> oracle_xlated;
    std::vector<int> source_helper_ids;
    std::vector<int> native_helper_ids;
    uint64_t map_delete_elem_addr = 0;
    std::unordered_map<std::string, uint64_t> helper_addrs;
    bool has_tail_call = false;
    std::unordered_map<std::string, uint64_t> map_addrs;
    std::unordered_map<std::string, uint32_t> map_addr_ids;
    std::unordered_map<std::string, std::string> native_map_symbols;
    std::unordered_map<std::string, MapMeta> exact_map_addrs;
    std::unordered_set<std::string> ambiguous_exact_maps;
    std::vector<MapMeta> maps;
    std::vector<MapMeta> source_tail_call_maps;
    /* Per-call-site spec for every `bpf_map_lookup_elem` invocation in
     * the entry program, listed in BPF-source order. Each entry is a
     * (target_kernel_address, key_offset) pair. native-link routes the
     * i-th `bpf_map_lookup_elem` call site to this entry. ARRAY/PERCPU_ARRAY
     * sites carry enough metadata for native-link to emit direct pointer
     * arithmetic. Other map types either remain a normal helper-ABI call or
     * fail fast if no helper-ABI target is available.
     *
     * The pair is decided per-call from the map type discovered by
     * walking the program's BPF source bytecode (track r1's binding
     * through the most recent BPF_LD_IMM64 pseudo_map_fd). ARRAY sites
     * carry enough metadata for native-link to emit direct bounds-check
     * + pointer arithmetic. Other map types stay on the helper
     * call unless their lowering can be expressed without private kernel
     * symbol addresses. */
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
        std::vector<uint8_t> gen_lookup;
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
    };
    std::vector<UpdateSite> update_sites;
};

void add_exact_map_meta(ProgramLoadPlan &load, const MapMeta &meta)
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

const MapMeta *find_exact_map_meta(const ProgramLoadPlan &load,
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

void add_map_meta(ProgramLoadPlan &load, const MapMeta &meta)
{
    const bool incoming_fd_valid = fd_is_bpf_map(meta.fd);
    bool duplicate = false;
    for (MapMeta &existing : load.maps) {
        if (existing.name == meta.name &&
            existing.kernel_addr == meta.kernel_addr) {
            if (!fd_is_bpf_map(existing.fd) && incoming_fd_valid) {
                existing.fd = meta.fd;
            }
            if (existing.value_addr == 0 && meta.value_addr != 0) {
                existing.value_addr = meta.value_addr;
            }
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

void add_map_symbol_alias_meta(ProgramLoadPlan &load,
                               const std::string &alias,
                               const MapMeta &meta)
{
    MapMeta alias_meta = meta;
    if (!fd_is_bpf_map(alias_meta.fd)) {
        for (const MapMeta &candidate : load.maps) {
            if (candidate.kernel_addr == meta.kernel_addr &&
                fd_is_bpf_map(candidate.fd)) {
                alias_meta = candidate;
                break;
            }
        }
    }
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
        if (!fd_is_bpf_map(existing->fd) && fd_is_bpf_map(alias_meta.fd)) {
            existing->fd = alias_meta.fd;
            existing->kernel_id = alias_meta.kernel_id;
            existing->type = alias_meta.type;
            existing->key_size = alias_meta.key_size;
            existing->value_size = alias_meta.value_size;
            existing->max_entries = alias_meta.max_entries;
        }
        if (existing->value_addr == 0 && alias_meta.value_addr != 0) {
            existing->value_addr = alias_meta.value_addr;
        }
    } else {
        load.maps.push_back(alias_meta);
    }
    load.map_addrs[alias] = meta.kernel_addr;
    load.map_addr_ids[alias] = meta.kernel_id;
    load.native_map_symbols[alias] = alias;
}

const MapMeta *find_single_cilium_calls_map(const ProgramLoadPlan &load)
{
    const MapMeta *match = nullptr;
    for (const MapMeta &meta : load.maps) {
        if (meta.type != BPF_MAP_TYPE_PROG_ARRAY ||
            !starts_with(meta.name, "cilium_calls")) {
            continue;
        }
        if (match && match->kernel_addr != meta.kernel_addr) {
            fail("native map symbol cilium_calls matches multiple loaded Cilium prog arrays");
        }
        match = &meta;
    }
    return match;
}

const MapMeta *find_source_tail_call_map_alias(const ProgramLoadPlan &load,
                                               const std::string &name)
{
    const NativeMapShape want_shape = expected_native_map_shape(name);
    if (want_shape.type != BPF_MAP_TYPE_PROG_ARRAY) {
        return nullptr;
    }

    const MapMeta *match = nullptr;
    for (const MapMeta &meta : load.source_tail_call_maps) {
        if (!map_matches_shape(meta, want_shape)) {
            continue;
        }
        if (match && match->kernel_addr != meta.kernel_addr) {
            fail("native map symbol " + name +
                 " matches multiple source tail-call prog arrays");
        }
        match = &meta;
    }
    return match;
}

bool find_open_process_cilium_calls_map(MapMeta &out)
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
        char map_name[sizeof(info.name) + 1] = {};
        std::memcpy(map_name, info.name, sizeof(info.name));
        if (!starts_with(map_name, "cilium_calls") ||
            info.type != BPF_MAP_TYPE_PROG_ARRAY ||
            info.key_size != 4 ||
            info.value_size != 4) {
            continue;
        }
        matches.push_back(MapMeta{
            std::string(map_name),
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

    if (matches.empty()) {
        return false;
    }
    out = *std::max_element(matches.begin(), matches.end(),
                            [](const MapMeta &a, const MapMeta &b) {
                                return a.fd < b.fd;
                            });
    return true;
}

const MapMeta *find_singleton_array_data_map(const ProgramLoadPlan &load,
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
    for (const MapMeta *candidate : matches) {
        if (candidate->kernel_addr != match->kernel_addr) {
            fail("multiple ARRAY maps match native data section " + section_name +
                 ": " + match->name + " and " + candidate->name);
        }
        if (candidate->value_addr != match->value_addr) {
            fail("multiple ARRAY maps match native data section " + section_name +
                 " with different value addresses: " + match->name +
                 " and " + candidate->name);
        }
    }
    return match;
}

const MapMeta *find_array_data_map(ProgramLoadPlan &load,
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

const MapMeta *find_singleton_kconfig_map(const ProgramLoadPlan &load)
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

void add_known_kconfig_symbol_addrs(ProgramLoadPlan &load)
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

void add_native_map_symbol_alias(ProgramLoadPlan &load, const std::string &name)
{
    if (load.map_addrs.count(name)) {
        return;
    }

    if (const MapMeta *exact = find_exact_map_meta(load, name)) {
        add_map_symbol_alias_meta(load, name, *exact);
        return;
    }

    if (name == "cilium_calls") {
        if (const MapMeta *match = find_single_cilium_calls_map(load)) {
            add_map_symbol_alias_meta(load, name, *match);
            return;
        }
        MapMeta process_map{};
        if (find_open_process_cilium_calls_map(process_map)) {
            add_map_meta(load, process_map);
            add_map_symbol_alias_meta(load, name, process_map);
        }
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
            const NativeMapShape want_shape = expected_native_map_shape(name);
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
        add_map_symbol_alias_meta(load, name, *match);
        return;
    }

    if (const MapMeta *source_tail_call_map =
            find_source_tail_call_map_alias(load, name)) {
        add_map_symbol_alias_meta(load, name, *source_tail_call_map);
        return;
    }

    MapMeta process_map{};
    if (find_open_process_map_by_name(name, process_map)) {
        add_map_meta(load, process_map);
        add_map_symbol_alias_meta(load, name, process_map);
    }
}

const MapMeta *find_map_meta_by_loaded_name(const ProgramLoadPlan &load,
                                            const std::string &loaded_name)
{
    const MapMeta *match = nullptr;
    for (const MapMeta &meta : load.maps) {
        if (meta.name == loaded_name) {
            if (match && match->kernel_addr != meta.kernel_addr) {
                fail("loaded map name " + loaded_name +
                     " is ambiguous in native metadata");
            }
            if (match && !fd_is_bpf_map(match->fd) && fd_is_bpf_map(meta.fd)) {
                match = &meta;
                continue;
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

uint64_t decode_x86_this_cpu_off_from_jit(const std::vector<uint8_t> &jited)
{
#if defined(__x86_64__)
    constexpr uint8_t kPrefix[] = {0x65, 0x48, 0x03, 0x04, 0x25};
    uint64_t found = 0;
    bool have = false;
    for (size_t i = 0; i + sizeof(kPrefix) + sizeof(uint32_t) <= jited.size(); i++) {
        if (std::memcmp(jited.data() + i, kPrefix, sizeof(kPrefix)) != 0) {
            continue;
        }
        uint32_t disp = 0;
        std::memcpy(&disp, jited.data() + i + sizeof(kPrefix), sizeof(disp));
        if (!have) {
            found = disp;
            have = true;
            continue;
        }
        if (found != disp) {
            fail("native_kernel: original JIT contains multiple gs:this_cpu_off displacements");
        }
    }
    return have ? found : 0;
#else
    (void)jited;
    return 0;
#endif
}

uint64_t decode_x86_cpu_number_from_jit(const std::vector<uint8_t> &jited)
{
#if defined(__x86_64__)
    constexpr uint8_t kMovRaxImm32[] = {0x48, 0xc7, 0xc0};
    constexpr uint8_t kAddGsThisCpuOff[] = {0x65, 0x48, 0x03, 0x04, 0x25};
    constexpr uint8_t kLoadCpuNumber[] = {0x8b, 0x40, 0x00};
    constexpr size_t kAddOffset = sizeof(kMovRaxImm32) + sizeof(uint32_t);
    constexpr size_t kLoadOffset = kAddOffset + sizeof(kAddGsThisCpuOff) + sizeof(uint32_t);
    constexpr size_t kPatternSize = kLoadOffset + sizeof(kLoadCpuNumber);
    uint64_t found = 0;
    bool have = false;
    for (size_t i = 0; i + kPatternSize <= jited.size(); i++) {
        if (std::memcmp(jited.data() + i, kMovRaxImm32, sizeof(kMovRaxImm32)) != 0 ||
            std::memcmp(jited.data() + i + kAddOffset,
                        kAddGsThisCpuOff,
                        sizeof(kAddGsThisCpuOff)) != 0 ||
            std::memcmp(jited.data() + i + kLoadOffset,
                        kLoadCpuNumber,
                        sizeof(kLoadCpuNumber)) != 0) {
            continue;
        }
        uint32_t imm = 0;
        std::memcpy(&imm, jited.data() + i + sizeof(kMovRaxImm32), sizeof(imm));
        const uint64_t value =
            static_cast<uint64_t>(static_cast<int64_t>(static_cast<int32_t>(imm)));
        if (!have) {
            found = value;
            have = true;
            continue;
        }
        if (found != value) {
            fail("native_kernel: original JIT contains multiple cpu_number addresses");
        }
    }
    return have ? found : 0;
#else
    (void)jited;
    return 0;
#endif
}

uint64_t decode_x86_current_task_from_jit(const std::vector<uint8_t> &jited)
{
#if defined(__x86_64__)
    constexpr uint8_t kMovRaxImm32[] = {0x48, 0xc7, 0xc0};
    constexpr uint8_t kAddGsThisCpuOff[] = {0x65, 0x48, 0x03, 0x04, 0x25};
    constexpr uint8_t kLoadCurrentTask[] = {0x48, 0x8b, 0x00};
    constexpr size_t kAddOffset = sizeof(kMovRaxImm32) + sizeof(uint32_t);
    constexpr size_t kLoadOffset = kAddOffset + sizeof(kAddGsThisCpuOff) + sizeof(uint32_t);
    constexpr size_t kPatternSize = kLoadOffset + sizeof(kLoadCurrentTask);
    uint64_t found = 0;
    bool have = false;
    for (size_t i = 0; i + kPatternSize <= jited.size(); i++) {
        if (std::memcmp(jited.data() + i, kMovRaxImm32, sizeof(kMovRaxImm32)) != 0 ||
            std::memcmp(jited.data() + i + kAddOffset,
                        kAddGsThisCpuOff,
                        sizeof(kAddGsThisCpuOff)) != 0 ||
            std::memcmp(jited.data() + i + kLoadOffset,
                        kLoadCurrentTask,
                        sizeof(kLoadCurrentTask)) != 0) {
            continue;
        }
        uint32_t imm = 0;
        std::memcpy(&imm, jited.data() + i + sizeof(kMovRaxImm32), sizeof(imm));
        const uint64_t value =
            static_cast<uint64_t>(static_cast<int64_t>(static_cast<int32_t>(imm)));
        if (!have) {
            found = value;
            have = true;
            continue;
        }
        if (found != value) {
            fail("native_kernel: original JIT contains multiple current_task addresses");
        }
    }
    return have ? found : 0;
#else
    (void)jited;
    return 0;
#endif
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

NativeMapShape inner_map_shape_for_outer_map(const MapMeta &meta)
{
    if (meta.type != BPF_MAP_TYPE_HASH_OF_MAPS &&
        meta.type != BPF_MAP_TYPE_ARRAY_OF_MAPS) {
        return NativeMapShape{};
    }

    /* bpf_map_info in this kernel fork does not expose inner_map_id, so
     * preserve verifier-equivalent lowering for the hot Tetragon policy
     * map-in-map shapes by matching the loaded outer map shape. Map names in
     * bpf_map_info are kernel-truncated, so key/max_entries disambiguate the
     * two policy-filter outers. */
    if (starts_with(meta.name, "policy_filter_") &&
        meta.type == BPF_MAP_TYPE_HASH_OF_MAPS &&
        meta.value_size == 4) {
        if (meta.key_size == 4 && meta.max_entries == 128) {
            return NativeMapShape{BPF_MAP_TYPE_HASH, 8, 1, 1};
        }
        if (meta.key_size == 8 && meta.max_entries == 1024) {
            return NativeMapShape{BPF_MAP_TYPE_HASH, 4, 1, 128};
        }
    }
    if (meta.type == BPF_MAP_TYPE_HASH_OF_MAPS &&
        meta.key_size == 8 &&
        meta.value_size == 4 &&
        meta.max_entries == 65536) {
        const int bucket = parse_otel_stack_delta_bucket(meta.name);
        if (bucket >= 0) {
            return NativeMapShape{BPF_MAP_TYPE_ARRAY, 4, 4, 1u << bucket};
        }
    }

    return NativeMapShape{};
}

bool configure_lookup_site_for_shape(ProgramLoadPlan::LookupSite &site,
                                     const NativeMapShape &shape,
                                     const BpfArrayOffsets &array_offsets)
{
    if (!has_native_map_shape(shape)) {
        return false;
    }

    if (shape.type == BPF_MAP_TYPE_ARRAY) {
        site.kind = ProgramLoadPlan::LookupSite::Kind::Array;
        site.max_entries = shape.max_entries;
        site.elem_size = (shape.value_size + 7u) & ~7u;
        site.index_mask = roundup_pow2_mask(shape.max_entries);
        site.value_offset = array_offsets.value;
        return true;
    }
    if (shape.type == BPF_MAP_TYPE_PERCPU_ARRAY) {
        if (array_offsets.this_cpu_off == 0) {
            fail("native_kernel: PERCPU_ARRAY lookup needs gs:this_cpu_off from original JIT");
        }
        site.kind = ProgramLoadPlan::LookupSite::Kind::PerCpuArray;
        site.max_entries = shape.max_entries;
        site.elem_size = (shape.value_size + 7u) & ~7u;
        site.index_mask = roundup_pow2_mask(shape.max_entries);
        site.value_offset = array_offsets.ptrs;
        site.percpu_base_addr = array_offsets.this_cpu_off;
        return true;
    }
    if (shape.type == BPF_MAP_TYPE_HASH ||
        shape.type == BPF_MAP_TYPE_LRU_HASH ||
        shape.type == BPF_MAP_TYPE_PERCPU_HASH ||
        shape.type == BPF_MAP_TYPE_LRU_PERCPU_HASH ||
        shape.type == BPF_MAP_TYPE_HASH_OF_MAPS) {
        site.kind = ProgramLoadPlan::LookupSite::Kind::Hash;
        if (shape.type == BPF_MAP_TYPE_LRU_HASH) {
            site.kind = ProgramLoadPlan::LookupSite::Kind::LruHash;
            site.value_offset = array_offsets.htab_lru_ref;
        } else if (shape.type == BPF_MAP_TYPE_PERCPU_HASH ||
                   shape.type == BPF_MAP_TYPE_LRU_PERCPU_HASH) {
            if (array_offsets.this_cpu_off == 0) {
                fail("native_kernel: PERCPU_HASH lookup needs gs:this_cpu_off from original JIT");
            }
            site.kind = ProgramLoadPlan::LookupSite::Kind::PerCpuHash;
            site.percpu_base_addr = array_offsets.this_cpu_off;
        } else if (shape.type == BPF_MAP_TYPE_HASH_OF_MAPS) {
            site.kind = ProgramLoadPlan::LookupSite::Kind::HashOfMaps;
        }
        site.key_offset = array_offsets.htab_key + ((shape.key_size + 7u) & ~7u);
        return true;
    }

    return false;
}

ProgramLoadPlan::LookupSite native_lookup_site_for_map_meta(
    const MapMeta &meta,
    const BpfArrayOffsets &array_offsets)
{
    ProgramLoadPlan::LookupSite site{
        ProgramLoadPlan::LookupSite::Kind::Call,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        {},
    };
    site.map_name = meta.name;
    ProgramLoadPlan::LookupSite shaped = site;
    if (configure_lookup_site_for_shape(
            shaped, map_shape_from_meta(meta), array_offsets) &&
        (shaped.kind == ProgramLoadPlan::LookupSite::Kind::Array ||
         shaped.kind == ProgramLoadPlan::LookupSite::Kind::PerCpuArray)) {
        shaped.map_name = meta.name;
        return shaped;
    }
    if (fd_is_bpf_map(meta.fd)) {
        site.target_addr = lookup_kernel_map_lookup_elem_ptr_by_fd(meta.fd);
    }
    return site;
}

void add_native_data_symbol_addrs(const std::filesystem::path &native_object,
                                  ProgramLoadPlan &load)
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
            if (GELF_ST_TYPE(sym.st_info) != STT_OBJECT ||
                sym.st_size == 0 ||
                sym.st_shndx == SHN_UNDEF ||
                sym.st_shndx >= SHN_LORESERVE) {
                continue;
            }
            const char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);
            if (!name || !name[0]) {
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
            const uint64_t section_end =
                std::max<uint64_t>(target_shdr.sh_size, symbol_end);
            const MapMeta *map = find_array_data_map(load, section, section_end);
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
            load.map_addrs[std::string(name)] =
                map->value_addr + off;
            load.map_addr_ids[std::string(name)] = map->kernel_id;
        }
    }
    elf_end(elf);
    close(fd);
    add_known_kconfig_symbol_addrs(load);
}

struct NativeTextSymbol {
    std::string name;
    size_t section_index = 0;
    uint64_t address = 0;
    uint64_t size = 0;
};

struct NativeTextSection {
    uint64_t address = 0;
    std::vector<uint8_t> bytes;
};

std::vector<uint8_t> read_elf_section_bytes(Elf *elf, Elf_Scn *scn,
                                            const GElf_Shdr &shdr,
                                            const std::filesystem::path &path)
{
    std::vector<uint8_t> bytes(shdr.sh_size);
    Elf_Data *data = nullptr;
    while ((data = elf_getdata(scn, data)) != nullptr) {
        if (!data->d_buf || data->d_size == 0) {
            continue;
        }
        if (data->d_off > bytes.size() ||
            data->d_size > bytes.size() - data->d_off) {
            fail("ELF section data exceeds section bounds in " + path.string());
        }
        std::memcpy(bytes.data() + data->d_off, data->d_buf, data->d_size);
    }
    return bytes;
}

std::vector<int> scan_x86_native_helper_calls(
    const NativeTextSymbol &sym,
    const NativeTextSection &section,
    const std::vector<NativeTextSymbol> &symbols,
    std::unordered_set<std::string> &visited)
{
    struct RegImm {
        bool valid = false;
        int64_t value = 0;
    };

    auto clear_call_clobbered = [](std::array<RegImm, 16> &regs) {
        for (int reg : {0, 1, 2, 6, 7, 8, 9, 10, 11}) {
            regs[static_cast<size_t>(reg)] = RegImm{};
        }
    };
    auto helper_id_from_reg = [](const std::array<RegImm, 16> &regs, int reg) -> int {
        const RegImm &state = regs[static_cast<size_t>(reg)];
        if (!state.valid || state.value < 0 ||
            state.value > std::numeric_limits<int>::max()) {
            return -1;
        }
        return static_cast<int>(state.value);
    };
    auto find_symbol_at = [&](uint64_t section_addr,
                              uint64_t target) -> const NativeTextSymbol * {
        for (const NativeTextSymbol &candidate : symbols) {
            if (candidate.section_index == sym.section_index &&
                section_addr + candidate.address == target) {
                return &candidate;
            }
        }
        return nullptr;
    };
    auto decode_prefix = [](const std::vector<uint8_t> &bytes,
                            size_t i,
                            uint8_t &rex) -> size_t {
        rex = 0;
        while (i < bytes.size()) {
            const uint8_t byte = bytes[i];
            if (byte >= 0x40 && byte <= 0x4f) {
                rex = byte;
                i++;
                continue;
            }
            if (byte == 0x66 || byte == 0x67 ||
                byte == 0xf2 || byte == 0xf3 ||
                byte == 0x2e || byte == 0x36 ||
                byte == 0x3e || byte == 0x26 ||
                byte == 0x64 || byte == 0x65) {
                i++;
                continue;
            }
            break;
        }
        return i;
    };

    std::vector<int> helper_ids;
    const uint64_t section_addr = section.address;
    if (sym.address < section_addr) {
        fail("native symbol " + sym.name + " is below executable section base");
    }
    const uint64_t start64 = sym.address - section_addr;
    if (start64 > section.bytes.size()) {
        fail("native symbol " + sym.name + " starts past executable section data");
    }
    const size_t start = static_cast<size_t>(start64);
    const size_t end = static_cast<size_t>(
        std::min<uint64_t>(section.bytes.size(), start64 + sym.size));
    const std::vector<uint8_t> &bytes = section.bytes;

    auto modrm_end_from = [&](size_t modrm_index, size_t imm_size) -> size_t {
        if (modrm_index >= end) {
            return 0;
        }
        const uint8_t modrm = bytes[modrm_index];
        const uint8_t mod = modrm & 0xc0;
        const uint8_t rm = modrm & 0x7;
        size_t idx = modrm_index + 1;
        uint8_t base = rm;
        if (mod != 0xc0 && rm == 4) {
            if (idx >= end) {
                return 0;
            }
            const uint8_t sib = bytes[idx++];
            base = sib & 0x7;
        }
        if (mod == 0x00) {
            if (rm == 5 || (rm == 4 && base == 5)) {
                idx += 4;
            }
        } else if (mod == 0x40) {
            idx += 1;
        } else if (mod == 0x80) {
            idx += 4;
        }
        idx += imm_size;
        return idx <= end ? idx : 0;
    };
    auto modrm_insn_end = [&](size_t opcode_index,
                              size_t opcode_len,
                              size_t imm_size) -> size_t {
        return modrm_end_from(opcode_index + opcode_len, imm_size);
    };
    auto known_insn_end = [&](size_t opcode_index, uint8_t rex) -> size_t {
        const uint8_t op = bytes[opcode_index];
        if ((op >= 0x50 && op <= 0x5f) || op == 0x90 ||
            op == 0xc3 || op == 0xcb || op == 0xf9 ||
            op == 0xfc || op == 0xfd) {
            return opcode_index + 1 <= end ? opcode_index + 1 : 0;
        }
        if (op >= 0x70 && op <= 0x7f) {
            return opcode_index + 2 <= end ? opcode_index + 2 : 0;
        }
        if (op == 0xeb) {
            return opcode_index + 2 <= end ? opcode_index + 2 : 0;
        }
        if (op == 0xe9 || op == 0xe8) {
            return opcode_index + 5 <= end ? opcode_index + 5 : 0;
        }
        if (op == 0x6a) {
            return opcode_index + 2 <= end ? opcode_index + 2 : 0;
        }
        if (op == 0x68) {
            return opcode_index + 5 <= end ? opcode_index + 5 : 0;
        }
        if ((op & 0xf8) == 0xb8) {
            const size_t imm_size = (rex & 0x8) ? 8 : 4;
            return opcode_index + 1 + imm_size <= end
                ? opcode_index + 1 + imm_size
                : 0;
        }
        if (op == 0x04 || op == 0x0c || op == 0x14 || op == 0x1c ||
            op == 0x24 || op == 0x2c || op == 0x34 || op == 0x3c) {
            return opcode_index + 2 <= end ? opcode_index + 2 : 0;
        }
        if (op == 0x05 || op == 0x0d || op == 0x15 || op == 0x1d ||
            op == 0x25 || op == 0x2d || op == 0x35 || op == 0x3d) {
            return opcode_index + 5 <= end ? opcode_index + 5 : 0;
        }
        switch (op) {
        case 0x00: case 0x01: case 0x02: case 0x03:
        case 0x08: case 0x09: case 0x0a: case 0x0b:
        case 0x10: case 0x11: case 0x12: case 0x13:
        case 0x18: case 0x19: case 0x1a: case 0x1b:
        case 0x20: case 0x21: case 0x22: case 0x23:
        case 0x28: case 0x29: case 0x2a: case 0x2b:
        case 0x30: case 0x31: case 0x32: case 0x33:
        case 0x38: case 0x39: case 0x3a: case 0x3b:
        case 0x84: case 0x85: case 0x87:
        case 0x88: case 0x89: case 0x8a: case 0x8b:
        case 0x8d: case 0x8f: case 0x63:
        case 0xd1: case 0xd3: case 0xf6: case 0xf7:
        case 0xfe: case 0xff:
            return modrm_insn_end(opcode_index, 1, 0);
        case 0x80: case 0x82: case 0x83:
        case 0xc0: case 0xc1: case 0xc6:
            return modrm_insn_end(opcode_index, 1, 1);
        case 0x81: case 0xc7:
            return modrm_insn_end(opcode_index, 1, 4);
        default:
            break;
        }
        if (op == 0x0f && opcode_index + 1 < end) {
            const uint8_t op2 = bytes[opcode_index + 1];
            if (op2 >= 0x80 && op2 <= 0x8f) {
                return opcode_index + 6 <= end ? opcode_index + 6 : 0;
            }
            if (op2 == 0x38 && opcode_index + 2 < end) {
                return modrm_insn_end(opcode_index, 3, 0);
            }
            switch (op2) {
            case 0x1f:
            case 0x40: case 0x41: case 0x42: case 0x43:
            case 0x44: case 0x45: case 0x46: case 0x47:
            case 0x48: case 0x49: case 0x4a: case 0x4b:
            case 0x4c: case 0x4d: case 0x4e: case 0x4f:
            case 0xaf:
            case 0xb6: case 0xb7: case 0xbe: case 0xbf:
                return modrm_insn_end(opcode_index, 2, 0);
            case 0xba:
                return modrm_insn_end(opcode_index, 2, 1);
            default:
                break;
            }
        }
        if (op == 0xc5 && opcode_index + 2 < end) {
            return modrm_end_from(opcode_index + 3, 0);
        }
        if (op == 0xc4 && opcode_index + 3 < end) {
            return modrm_end_from(opcode_index + 4, 0);
        }
        return 0;
    };

    const std::string visit_key =
        std::to_string(sym.section_index) + ":" + std::to_string(sym.address);
    if (!visited.insert(visit_key).second) {
        return {};
    }

    std::array<RegImm, 16> regs{};

    for (size_t i = start; i < end;) {
        uint8_t rex = 0;
        const size_t p = decode_prefix(bytes, i, rex);
        if (p >= end) {
            break;
        }
        const uint8_t op = bytes[p];

        if ((op & 0xf8) == 0xb8 && (rex & 0x8) && p + 9 <= end) {
            uint64_t imm = 0;
            std::memcpy(&imm, bytes.data() + p + 1, sizeof(imm));
            const int reg = (op & 0x7) + ((rex & 0x1) ? 8 : 0);
            regs[static_cast<size_t>(reg)] = imm <=
                    static_cast<uint64_t>(std::numeric_limits<int64_t>::max())
                ? RegImm{true, static_cast<int64_t>(imm)}
                : RegImm{};
            i = p + 9;
            continue;
        }

        if ((op & 0xf8) == 0xb8 && p + 5 <= end) {
            int32_t imm = 0;
            std::memcpy(&imm, bytes.data() + p + 1, sizeof(imm));
            const int reg = (op & 0x7) + ((rex & 0x1) ? 8 : 0);
            regs[static_cast<size_t>(reg)] =
                RegImm{true, static_cast<int64_t>(imm)};
            i = p + 5;
            continue;
        }

        if (op == 0xc7 && p + 2 <= end) {
            const size_t insn_end = modrm_insn_end(p, 1, 4);
            if (insn_end == 0) {
                fail("native helper scanner hit truncated x86 C7 instruction in "
                     + sym.name);
            }
            const uint8_t modrm = bytes[p + 1];
            if ((modrm & 0xc0) == 0xc0 && ((modrm >> 3) & 0x7) == 0) {
                int32_t imm = 0;
                std::memcpy(&imm, bytes.data() + p + 2, sizeof(imm));
                const int reg = (modrm & 0x7) + ((rex & 0x1) ? 8 : 0);
                regs[static_cast<size_t>(reg)] =
                    RegImm{true, static_cast<int64_t>(imm)};
            }
            i = insn_end;
            continue;
        }

        if ((op == 0x89 || op == 0x8b) && p + 2 <= end) {
            const size_t insn_end = modrm_insn_end(p, 1, 0);
            if (insn_end == 0) {
                fail("native helper scanner hit truncated x86 mov instruction in "
                     + sym.name);
            }
            const uint8_t modrm = bytes[p + 1];
            const int reg_field = ((modrm >> 3) & 0x7) + ((rex & 0x4) ? 8 : 0);
            if ((modrm & 0xc0) == 0xc0) {
                const int rm_field = (modrm & 0x7) + ((rex & 0x1) ? 8 : 0);
                const int dst = op == 0x89 ? rm_field : reg_field;
                const int src = op == 0x89 ? reg_field : rm_field;
                regs[static_cast<size_t>(dst)] = regs[static_cast<size_t>(src)];
                i = insn_end;
                continue;
            }
            if (op == 0x8b) {
                regs[static_cast<size_t>(reg_field)] = RegImm{};
            }
            i = insn_end;
            continue;
        }

        if ((op == 0x31 || op == 0x33 || op == 0x29 || op == 0x2b ||
             op == 0x01 || op == 0x03 || op == 0x09 || op == 0x0b ||
             op == 0x21 || op == 0x23) &&
            p + 2 <= end) {
            const size_t insn_end = modrm_insn_end(p, 1, 0);
            if (insn_end == 0) {
                fail("native helper scanner hit truncated x86 ALU instruction in "
                     + sym.name);
            }
            const uint8_t modrm = bytes[p + 1];
            const int reg_field =
                ((modrm >> 3) & 0x7) + ((rex & 0x4) ? 8 : 0);
            const bool dst_is_reg_field =
                op == 0x33 || op == 0x2b || op == 0x03 ||
                op == 0x0b || op == 0x23;
            if ((modrm & 0xc0) == 0xc0) {
                const int rm_field = (modrm & 0x7) + ((rex & 0x1) ? 8 : 0);
                const int dst = dst_is_reg_field ? reg_field : rm_field;
                regs[static_cast<size_t>(dst)] = RegImm{};
            } else if (dst_is_reg_field) {
                regs[static_cast<size_t>(reg_field)] = RegImm{};
            }
            i = insn_end;
            continue;
        }

        if (op == 0x8d && p + 2 <= end) {
            const size_t insn_end = modrm_insn_end(p, 1, 0);
            if (insn_end == 0) {
                fail("native helper scanner hit truncated x86 lea instruction in "
                     + sym.name);
            }
            const uint8_t modrm = bytes[p + 1];
            const int dst = ((modrm >> 3) & 0x7) + ((rex & 0x4) ? 8 : 0);
            regs[static_cast<size_t>(dst)] = RegImm{};
            i = insn_end;
            continue;
        }

        if (op == 0xff && p + 2 <= end) {
            const size_t insn_end = modrm_insn_end(p, 1, 0);
            if (insn_end == 0) {
                fail("native helper scanner hit truncated x86 FF instruction in "
                     + sym.name);
            }
            const uint8_t modrm = bytes[p + 1];
            const uint8_t mod = modrm & 0xc0;
            const uint8_t subop = (modrm >> 3) & 0x7;
            if (mod == 0xc0 && subop == 2) {
                const int reg = (modrm & 0x7) + ((rex & 0x1) ? 8 : 0);
                const int helper_id = helper_id_from_reg(regs, reg);
                if (helper_id >= 0) {
                    helper_ids.push_back(helper_id);
                }
                clear_call_clobbered(regs);
            }
            i = insn_end;
            continue;
        }

        if (op == 0xe8 && p + 5 <= end) {
            int32_t disp = 0;
            std::memcpy(&disp, bytes.data() + p + 1, sizeof(disp));
            const uint64_t next = section_addr + p + 5;
            const uint64_t target =
                static_cast<uint64_t>(static_cast<int64_t>(next) + disp);
            const NativeTextSymbol *target_sym = find_symbol_at(section_addr, target);
            if (target_sym) {
                for (int helper_id : scan_x86_native_helper_calls(
                         *target_sym, section, symbols, visited)) {
                    helper_ids.push_back(helper_id);
                }
            }
            clear_call_clobbered(regs);
            i = p + 5;
            continue;
        }

        if (op == 0xc3 || op == 0xcb || op == 0xc2 || op == 0xca) {
            clear_call_clobbered(regs);
        }

        const size_t insn_end = known_insn_end(p, rex);
        i = insn_end != 0 ? insn_end : i + 1;
    }
    return helper_ids;
}

std::vector<int> collect_native_helper_call_ids(
    const std::filesystem::path &native_object,
    const std::string &symbol_name)
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

    std::unordered_map<size_t, NativeTextSection> sections;
    Elf_Scn *scn = nullptr;
    while ((scn = elf_nextscn(elf, scn)) != nullptr) {
        GElf_Shdr shdr = {};
        if (!gelf_getshdr(scn, &shdr)) {
            elf_end(elf);
            close(fd);
            fail("gelf_getshdr " + native_object.string() + ": " + elf_errmsg(-1));
        }
        if ((shdr.sh_flags & SHF_EXECINSTR) == 0 || shdr.sh_size == 0) {
            continue;
        }
        sections.emplace(
            elf_ndxscn(scn),
            NativeTextSection{shdr.sh_addr,
                              read_elf_section_bytes(elf, scn, shdr, native_object)});
    }

    std::vector<NativeTextSymbol> symbols;
    scn = nullptr;
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
            if (GELF_ST_TYPE(sym.st_info) != STT_FUNC ||
                sym.st_size == 0 ||
                sym.st_shndx == SHN_UNDEF ||
                sym.st_shndx >= SHN_LORESERVE) {
                continue;
            }
            if (!sections.count(sym.st_shndx)) {
                continue;
            }
            const char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);
            if (!name || !name[0]) {
                continue;
            }
            symbols.push_back(NativeTextSymbol{
                name,
                static_cast<size_t>(sym.st_shndx),
                sym.st_value,
                sym.st_size,
            });
        }
    }

    std::vector<int> helper_ids;
    bool found_entry = false;
    for (const NativeTextSymbol &sym : symbols) {
        if (sym.name != symbol_name) {
            continue;
        }
        auto sec_it = sections.find(sym.section_index);
        if (sec_it == sections.end()) {
            continue;
        }
        found_entry = true;
#if defined(__x86_64__)
        std::unordered_set<std::string> visited;
        helper_ids = scan_x86_native_helper_calls(
            sym, sec_it->second, symbols, visited);
#endif
        break;
    }
    elf_end(elf);
    close(fd);
    if (!found_entry) {
        fail("native object " + native_object.string() +
             " does not contain entry symbol " + symbol_name);
    }
    return helper_ids;
}

bool native_link_resolves_helper_target(int helper_id)
{
    switch (helper_id) {
    case BPF_FUNC_map_lookup_elem:
    case BPF_FUNC_map_update_elem:
    case BPF_FUNC_map_delete_elem:
    case BPF_FUNC_tail_call:
    case BPF_FUNC_get_smp_processor_id:
    case BPF_FUNC_get_current_task:
    case BPF_FUNC_get_current_task_btf:
        return false;
    default:
        return true;
    }
}

std::vector<int> collect_xlated_call_imms(const std::vector<uint8_t> &xlated)
{
    if (xlated.size() % sizeof(bpf_insn) != 0) {
        fail("native_kernel helper target oracle xlated image is truncated");
    }
    std::vector<int> ids;
    const bpf_insn *insns =
        reinterpret_cast<const bpf_insn *>(xlated.data());
    const size_t cnt = xlated.size() / sizeof(bpf_insn);
    for (size_t i = 0; i < cnt; i++) {
        const bpf_insn &in = insns[i];
        if (in.code == (BPF_LD | BPF_DW | BPF_IMM)) {
            i++;
            continue;
        }
        if (in.code != (BPF_JMP | BPF_CALL)) {
            continue;
        }
        if (in.src_reg == BPF_PSEUDO_CALL ||
            in.src_reg == BPF_PSEUDO_KFUNC_CALL ||
            in.src_reg == BPF_PSEUDO_KINSN_CALL) {
            continue;
        }
        if (in.src_reg != 0) {
            fail("native_kernel helper target oracle has unsupported xlated call src_reg="
                 + std::to_string(static_cast<unsigned>(in.src_reg)));
        }
        ids.push_back(in.imm);
    }
    return ids;
}

bpf_insn bpf_insn_make(uint8_t code, uint8_t dst, uint8_t src,
                       int16_t off, int32_t imm)
{
    return bpf_insn{code, dst, src, off, imm};
}

void emit_mov_imm(std::vector<bpf_insn> &insns, uint8_t dst, int32_t imm)
{
    insns.push_back(
        bpf_insn_make(BPF_ALU64 | BPF_MOV | BPF_K, dst, 0, 0, imm));
}

void emit_mov_reg(std::vector<bpf_insn> &insns, uint8_t dst, uint8_t src)
{
    insns.push_back(
        bpf_insn_make(BPF_ALU64 | BPF_MOV | BPF_X, dst, src, 0, 0));
}

void emit_ld_map_fd(std::vector<bpf_insn> &insns, uint8_t dst, int map_fd)
{
    if (map_fd < 0) {
        fail("native_kernel helper target oracle got invalid map fd");
    }
    insns.push_back(bpf_insn{
        .code = BPF_LD | BPF_DW | BPF_IMM,
        .dst_reg = dst,
        .src_reg = BPF_PSEUDO_MAP_FD,
        .off = 0,
        .imm = map_fd,
    });
    insns.push_back(bpf_insn{
        .code = 0, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0,
    });
}

void emit_add_imm(std::vector<bpf_insn> &insns, uint8_t dst, int32_t imm)
{
    insns.push_back(
        bpf_insn_make(BPF_ALU64 | BPF_ADD | BPF_K, dst, 0, 0, imm));
}

void emit_stack_ptr(std::vector<bpf_insn> &insns, uint8_t dst, int16_t off)
{
    emit_mov_reg(insns, dst, BPF_REG_10);
    emit_add_imm(insns, dst, off);
}

void emit_stack_zero(std::vector<bpf_insn> &insns, int16_t off)
{
    insns.push_back(
        bpf_insn_make(BPF_ST | BPF_MEM | BPF_DW, BPF_REG_10, 0, off, 0));
}

void emit_stack_zero_range(std::vector<bpf_insn> &insns, int16_t first_off,
                           int size)
{
    if (first_off >= 0 || size <= 0 ||
        (static_cast<int>(first_off) + size) > 0) {
        fail("native_kernel helper target oracle got invalid stack range");
    }
    for (int off = first_off; off < first_off + size; off += 8) {
        emit_stack_zero(insns, static_cast<int16_t>(off));
    }
}

void emit_call(std::vector<bpf_insn> &insns, int helper_id)
{
    insns.push_back(
        bpf_insn_make(BPF_JMP | BPF_CALL, 0, 0, 0, helper_id));
}

void emit_jeq_imm(std::vector<bpf_insn> &insns, uint8_t dst, int32_t imm,
                  int16_t off)
{
    insns.push_back(
        bpf_insn_make(BPF_JMP | BPF_JEQ | BPF_K, dst, 0, off, imm));
}

void emit_exit(std::vector<bpf_insn> &insns)
{
    insns.push_back(bpf_insn_make(BPF_JMP | BPF_EXIT, 0, 0, 0, 0));
}

void emit_helper_target_oracle_invocation(int helper_id,
                                          std::vector<bpf_insn> &insns,
                                          int helper_map_fd)
{
    auto finish = [&]() {
        emit_call(insns, helper_id);
    };
    auto prepare_stack = [&]() {
        emit_stack_zero(insns, -8);
        emit_stack_zero(insns, -16);
    };
    auto prepare_sock_tuple = [&]() -> std::pair<int16_t, int> {
        const int tuple_size =
            static_cast<int>(sizeof(((struct bpf_sock_tuple *)0)->ipv4));
        const int tuple_aligned = (tuple_size + 7) & ~7;
        const int16_t tuple_off = static_cast<int16_t>(-tuple_aligned);
        emit_stack_zero_range(insns, tuple_off, tuple_aligned);
        return {tuple_off, tuple_size};
    };

    switch (helper_id) {
    case BPF_FUNC_ktime_get_ns:
    case BPF_FUNC_ktime_get_boot_ns:
    case BPF_FUNC_get_smp_processor_id:
    case BPF_FUNC_get_prandom_u32:
    case BPF_FUNC_get_numa_node_id:
    case BPF_FUNC_jiffies64:
        finish();
        return;
    case BPF_FUNC_xdp_adjust_meta:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, -4);
        finish();
        return;
    case BPF_FUNC_xdp_adjust_head:
    case BPF_FUNC_xdp_adjust_tail:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 1);
        finish();
        return;
    case BPF_FUNC_xdp_get_buff_len:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        finish();
        return;
    case BPF_FUNC_xdp_load_bytes:
    case BPF_FUNC_xdp_store_bytes:
        prepare_stack();
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        emit_stack_ptr(insns, BPF_REG_3, -16);
        emit_mov_imm(insns, BPF_REG_4, 1);
        finish();
        return;
    case BPF_FUNC_perf_event_output:
        prepare_stack();
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_ld_map_fd(insns, BPF_REG_2, helper_map_fd);
        emit_mov_imm(insns, BPF_REG_3, -1);
        emit_stack_ptr(insns, BPF_REG_4, -16);
        emit_mov_imm(insns, BPF_REG_5, 1);
        finish();
        return;
    case BPF_FUNC_skb_load_bytes:
        prepare_stack();
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        emit_stack_ptr(insns, BPF_REG_3, -16);
        emit_mov_imm(insns, BPF_REG_4, 1);
        finish();
        return;
    case BPF_FUNC_skb_store_bytes:
        prepare_stack();
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        emit_stack_ptr(insns, BPF_REG_3, -16);
        emit_mov_imm(insns, BPF_REG_4, 1);
        emit_mov_imm(insns, BPF_REG_5, 0);
        finish();
        return;
    case BPF_FUNC_l3_csum_replace:
    case BPF_FUNC_l4_csum_replace:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        emit_mov_imm(insns, BPF_REG_3, 0);
        emit_mov_imm(insns, BPF_REG_4, 0);
        emit_mov_imm(insns, BPF_REG_5, 0);
        finish();
        return;
    case BPF_FUNC_csum_diff:
        prepare_stack();
        emit_stack_ptr(insns, BPF_REG_1, -16);
        emit_mov_imm(insns, BPF_REG_2, 4);
        emit_stack_ptr(insns, BPF_REG_3, -8);
        emit_mov_imm(insns, BPF_REG_4, 4);
        emit_mov_imm(insns, BPF_REG_5, 0);
        finish();
        return;
    case BPF_FUNC_clone_redirect:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 1);
        emit_mov_imm(insns, BPF_REG_3, 0);
        finish();
        return;
    case BPF_FUNC_redirect:
        emit_mov_imm(insns, BPF_REG_1, 1);
        emit_mov_imm(insns, BPF_REG_2, 0);
        finish();
        return;
    case BPF_FUNC_redirect_neigh:
        emit_mov_imm(insns, BPF_REG_1, 1);
        emit_mov_imm(insns, BPF_REG_2, 0);
        emit_mov_imm(insns, BPF_REG_3, 0);
        emit_mov_imm(insns, BPF_REG_4, 0);
        finish();
        return;
    case BPF_FUNC_redirect_peer:
        emit_mov_imm(insns, BPF_REG_1, 1);
        emit_mov_imm(insns, BPF_REG_2, 0);
        finish();
        return;
    case BPF_FUNC_skb_pull_data:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        finish();
        return;
    case BPF_FUNC_skb_change_tail:
    case BPF_FUNC_skb_change_head:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        emit_mov_imm(insns, BPF_REG_3, 0);
        finish();
        return;
    case BPF_FUNC_skb_change_type:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        finish();
        return;
    case BPF_FUNC_skb_change_proto:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0x0800);
        emit_mov_imm(insns, BPF_REG_3, 0);
        finish();
        return;
    case BPF_FUNC_skb_adjust_room:
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_imm(insns, BPF_REG_2, 0);
        emit_mov_imm(insns, BPF_REG_3, 0);
        emit_mov_imm(insns, BPF_REG_4, 0);
        emit_mov_imm(insns, BPF_REG_5, 0);
        finish();
        return;
    case BPF_FUNC_sk_lookup_tcp:
    case BPF_FUNC_sk_lookup_udp:
    case BPF_FUNC_skc_lookup_tcp: {
        const auto [tuple_off, tuple_size] = prepare_sock_tuple();
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_stack_ptr(insns, BPF_REG_2, tuple_off);
        emit_mov_imm(insns, BPF_REG_3, tuple_size);
        emit_mov_imm(insns, BPF_REG_4, -1);
        emit_mov_imm(insns, BPF_REG_5, 0);
        finish();
        emit_jeq_imm(insns, BPF_REG_0, 0, 2);
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_0);
        emit_call(insns, BPF_FUNC_sk_release);
        return;
    }
    case BPF_FUNC_sk_release: {
        const auto [tuple_off, tuple_size] = prepare_sock_tuple();
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_stack_ptr(insns, BPF_REG_2, tuple_off);
        emit_mov_imm(insns, BPF_REG_3, tuple_size);
        emit_mov_imm(insns, BPF_REG_4, -1);
        emit_mov_imm(insns, BPF_REG_5, 0);
        emit_call(insns, BPF_FUNC_skc_lookup_tcp);
        emit_jeq_imm(insns, BPF_REG_0, 0, 2);
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_0);
        emit_call(insns, BPF_FUNC_sk_release);
        return;
    }
    case BPF_FUNC_sk_assign: {
        const auto [tuple_off, tuple_size] = prepare_sock_tuple();
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_stack_ptr(insns, BPF_REG_2, tuple_off);
        emit_mov_imm(insns, BPF_REG_3, tuple_size);
        emit_mov_imm(insns, BPF_REG_4, -1);
        emit_mov_imm(insns, BPF_REG_5, 0);
        emit_call(insns, BPF_FUNC_skc_lookup_tcp);
        emit_jeq_imm(insns, BPF_REG_0, 0, 7);
        emit_mov_reg(insns, BPF_REG_7, BPF_REG_0);
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_mov_reg(insns, BPF_REG_2, BPF_REG_7);
        emit_mov_imm(insns, BPF_REG_3, 0);
        emit_call(insns, BPF_FUNC_sk_assign);
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_7);
        emit_call(insns, BPF_FUNC_sk_release);
        return;
    }
    case BPF_FUNC_fib_lookup: {
        const int fib_size = static_cast<int>(sizeof(struct bpf_fib_lookup));
        const int fib_aligned = (fib_size + 7) & ~7;
        const int16_t fib_off = static_cast<int16_t>(-fib_aligned);
        emit_stack_zero_range(insns, fib_off, fib_aligned);
        emit_mov_reg(insns, BPF_REG_1, BPF_REG_6);
        emit_stack_ptr(insns, BPF_REG_2, fib_off);
        emit_mov_imm(insns, BPF_REG_3, fib_size);
        emit_mov_imm(insns, BPF_REG_4, 0);
        finish();
        return;
    }
    default:
        fail("native_kernel helper target oracle has no verifier template for helper id "
             + std::to_string(helper_id));
    }
}

void build_helper_target_oracle_program(int helper_id,
                                        std::vector<bpf_insn> &insns,
                                        int helper_map_fd)
{
    emit_mov_reg(insns, BPF_REG_6, BPF_REG_1);
    emit_helper_target_oracle_invocation(helper_id, insns, helper_map_fd);
    emit_helper_target_oracle_invocation(
        helper_id == BPF_FUNC_get_prandom_u32
            ? BPF_FUNC_ktime_get_ns
            : BPF_FUNC_get_prandom_u32,
        insns,
        -1);
    emit_exit(insns);
}

bool jit_target_is_inside_image(uint64_t target, uint64_t base, size_t len)
{
    if (target < base) {
        return false;
    }
    return target - base < len;
}

#if defined(__x86_64__)
void clear_x86_oracle_call_clobbered(std::unordered_map<int, uint64_t> &regs)
{
    for (int reg : {0, 1, 2, 6, 7, 8, 9, 10, 11}) {
        regs.erase(reg);
    }
}

std::vector<uint64_t> decode_external_call_targets_from_jit(
    const std::vector<uint8_t> &jited,
    uint64_t base)
{
    std::vector<uint64_t> targets;
    std::unordered_map<int, uint64_t> regs;
    for (size_t i = 0; i < jited.size();) {
        const uint8_t b0 = jited[i];
        if (b0 == 0xe8 && i + 5 <= jited.size()) {
            int32_t disp = 0;
            std::memcpy(&disp, jited.data() + i + 1, sizeof(disp));
            const uint64_t ip_after = base + i + 5;
            const uint64_t target =
                static_cast<uint64_t>(static_cast<int64_t>(ip_after) + disp);
            if (!jit_target_is_inside_image(target, base, jited.size())) {
                targets.push_back(target);
            }
            clear_x86_oracle_call_clobbered(regs);
            i += 5;
            continue;
        }
        if ((b0 == 0x48 || b0 == 0x49) && i + 10 <= jited.size() &&
            (jited[i + 1] & 0xf8) == 0xb8) {
            uint64_t imm = 0;
            std::memcpy(&imm, jited.data() + i + 2, sizeof(imm));
            const int reg = (jited[i + 1] & 0x7) + (b0 == 0x49 ? 8 : 0);
            regs[reg] = imm;
            i += 10;
            continue;
        }
        if ((b0 == 0x48 || b0 == 0x49) && i + 7 <= jited.size() &&
            jited[i + 1] == 0xc7 && (jited[i + 2] & 0xf8) == 0xc0) {
            int32_t imm = 0;
            std::memcpy(&imm, jited.data() + i + 3, sizeof(imm));
            const int reg = (jited[i + 2] & 0x7) + (b0 == 0x49 ? 8 : 0);
            regs[reg] = static_cast<uint64_t>(static_cast<int64_t>(imm));
            i += 7;
            continue;
        }
        if (b0 == 0xff && i + 2 <= jited.size() &&
            (jited[i + 1] & 0xf8) == 0xd0) {
            const int reg = jited[i + 1] & 0x7;
            auto it = regs.find(reg);
            if (it != regs.end() &&
                !jit_target_is_inside_image(it->second, base, jited.size())) {
                targets.push_back(it->second);
            }
            clear_x86_oracle_call_clobbered(regs);
            i += 2;
            continue;
        }
        if (b0 == 0x41 && i + 3 <= jited.size() && jited[i + 1] == 0xff &&
            (jited[i + 2] & 0xf8) == 0xd0) {
            const int reg = 8 + (jited[i + 2] & 0x7);
            auto it = regs.find(reg);
            if (it != regs.end() &&
                !jit_target_is_inside_image(it->second, base, jited.size())) {
                targets.push_back(it->second);
            }
            clear_x86_oracle_call_clobbered(regs);
            i += 3;
            continue;
        }
        i++;
    }
    return targets;
}
#elif defined(__aarch64__)
struct Arm64OracleReg {
    bool valid = false;
    uint64_t value = 0;
};

int64_t sign_extend_bits(uint64_t value, unsigned bits)
{
    const uint64_t sign = 1ULL << (bits - 1);
    const uint64_t mask = (1ULL << bits) - 1;
    return static_cast<int64_t>(((value & mask) ^ sign) - sign);
}

std::vector<uint64_t> decode_external_call_targets_from_jit(
    const std::vector<uint8_t> &jited,
    uint64_t base)
{
    if (jited.size() % 4 != 0) {
        fail("native_kernel helper target oracle arm64 JIT length is not 4-byte aligned");
    }
    std::vector<uint64_t> targets;
    Arm64OracleReg regs[32];
    for (size_t idx = 0; idx < jited.size() / 4; idx++) {
        uint32_t word = 0;
        std::memcpy(&word, jited.data() + idx * 4, sizeof(word));
        const uint32_t kind = word & 0xff80'0000u;
        if (kind == 0x9280'0000u || kind == 0xd280'0000u ||
            kind == 0xf280'0000u) {
            const size_t rd = word & 0x1fu;
            const unsigned shift = ((word >> 21) & 0x3u) * 16u;
            const uint64_t imm = (word >> 5) & 0xffffu;
            const bool movk = kind == 0xf280'0000u;
            const uint64_t value =
                kind == 0x9280'0000u ? ~(imm << shift) : (imm << shift);
            if (movk) {
                if (regs[rd].valid) {
                    const uint64_t mask = 0xffffULL << shift;
                    regs[rd].value = (regs[rd].value & ~mask) | value;
                }
            } else {
                regs[rd] = Arm64OracleReg{true, value};
            }
            continue;
        }
        if ((word & 0xfc00'0000u) == 0x9400'0000u) {
            const int64_t disp = sign_extend_bits(word & 0x03ff'ffffu, 26) << 2;
            const uint64_t pc = base + idx * 4;
            const uint64_t target = static_cast<uint64_t>(
                static_cast<int64_t>(pc) + disp);
            if (!jit_target_is_inside_image(target, base, jited.size())) {
                targets.push_back(target);
            }
            continue;
        }
        if ((word & 0xffff'fc1fu) == 0xd63f'0000u) {
            const size_t rn = (word >> 5) & 0x1fu;
            if (regs[rn].valid &&
                !jit_target_is_inside_image(regs[rn].value, base, jited.size())) {
                targets.push_back(regs[rn].value);
            }
            regs[rn].valid = false;
        }
    }
    return targets;
}
#endif

std::vector<size_t> match_jit_targets_to_xlated_calls(
    const std::vector<uint64_t> &jit_targets,
    const std::vector<int> &xlated_call_imms)
{
    std::vector<size_t> matched;
    if (xlated_call_imms.empty()) {
        return matched;
    }
    if (jit_targets.size() < xlated_call_imms.size()) {
        fail("native_kernel helper target oracle found fewer native calls than xlated BPF calls");
    }
    for (size_t start = 0; start < jit_targets.size(); start++) {
        const int64_t first_imm = xlated_call_imms[0];
        const uint64_t call_base = first_imm >= 0
            ? jit_targets[start] - static_cast<uint64_t>(first_imm)
            : jit_targets[start] + static_cast<uint64_t>(-first_imm);
        std::vector<size_t> candidate;
        candidate.reserve(xlated_call_imms.size());
        candidate.push_back(start);
        size_t next_jit = start + 1;
        bool ok = true;
        for (size_t i = 1; i < xlated_call_imms.size(); i++) {
            const int64_t imm = xlated_call_imms[i];
            const uint64_t expected = imm >= 0
                ? call_base + static_cast<uint64_t>(imm)
                : call_base - static_cast<uint64_t>(-imm);
            bool found = false;
            while (next_jit < jit_targets.size()) {
                if (jit_targets[next_jit] == expected) {
                    candidate.push_back(next_jit);
                    next_jit++;
                    found = true;
                    break;
                }
                next_jit++;
            }
            if (!found) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return candidate;
        }
    }
    fail("native_kernel helper target oracle could not align xlated BPF calls with native calls");
}

size_t helper_target_oracle_call_index(int helper_id)
{
    if (helper_id == BPF_FUNC_sk_release ||
        helper_id == BPF_FUNC_sk_assign) {
        return 1;
    }
    return 0;
}

uint64_t decode_helper_target_oracle(int prog_fd, int helper_id)
{
    const bpf_prog_info info = load_prog_info(prog_fd);
    const auto ksyms = load_jited_ksyms(prog_fd, info.nr_jited_ksyms);
    const uint64_t base = ksyms[0];
    const std::vector<uint8_t> jited =
        load_jited_program(prog_fd, info.jited_prog_len);
    const std::vector<uint8_t> xlated =
        load_xlated_program(prog_fd, info.xlated_prog_len);
    const std::vector<int> xlated_call_imms = collect_xlated_call_imms(xlated);
    const std::vector<uint64_t> targets =
        decode_external_call_targets_from_jit(jited, base);
    const std::vector<size_t> matched =
        match_jit_targets_to_xlated_calls(targets, xlated_call_imms);
    const size_t call_index = helper_target_oracle_call_index(helper_id);
    if (call_index < matched.size()) {
        return targets[matched[call_index]];
    }
    std::ostringstream msg;
    msg << "native_kernel helper target oracle did not retain helper call index "
        << call_index << " for helper id " << helper_id << " xlated_calls=[";
    for (size_t i = 0; i < xlated_call_imms.size(); i++) {
        if (i != 0) {
            msg << ",";
        }
        msg << xlated_call_imms[i];
    }
    msg << "] external_targets=" << targets.size()
        << " matched_calls=" << matched.size();
    fail(msg.str());
}

uint64_t load_helper_target_oracle(uint32_t prog_type_value,
                                   const StubLoadAttrs &attrs,
                                   int helper_id)
{
    ScopedFd helper_map_fd;
    if (helper_id == BPF_FUNC_perf_event_output) {
        LIBBPF_OPTS(bpf_map_create_opts, map_opts);
        int fd = bpf_map_create(BPF_MAP_TYPE_PERF_EVENT_ARRAY,
                                "native_perf_oracle",
                                sizeof(uint32_t),
                                sizeof(uint32_t),
                                1,
                                &map_opts);
        if (fd < 0) {
            fail("bpf_map_create native helper target perf-event map: "
                 + std::string(std::strerror(errno)));
        }
        helper_map_fd.fd = fd;
    }

    std::vector<bpf_insn> insns;
    build_helper_target_oracle_program(helper_id, insns, helper_map_fd.get());

    ScopedFd prog_btf_fd(open_btf_fd_by_id_required(
        attrs.prog_btf_id, "prog_btf_id"));
    ScopedFd attach_btf_obj_fd(open_btf_fd_by_id_required(
        attrs.attach_btf_obj_id, "attach_btf_obj_id"));
    ScopedFd attach_prog_fd(open_prog_fd_by_id_required(
        attrs.attach_prog_id, "attach_prog_id"));

    LIBBPF_OPTS(bpf_prog_load_opts, opts,
        .expected_attach_type = static_cast<bpf_attach_type>(attrs.expected_attach_type),
        .prog_btf_fd = static_cast<uint32_t>(prog_btf_fd.get() >= 0 ? prog_btf_fd.get() : 0),
        .attach_btf_id = attrs.attach_btf_id,
        .attach_prog_fd = static_cast<uint32_t>(attach_prog_fd.get() >= 0 ? attach_prog_fd.get() : 0),
        .attach_btf_obj_fd = static_cast<uint32_t>(attach_btf_obj_fd.get() >= 0 ? attach_btf_obj_fd.get() : 0),
    );
    int fd = bpf_prog_load(static_cast<bpf_prog_type>(prog_type_value),
                           "native_h_target", "GPL",
                           insns.data(), insns.size(), &opts);
    if (fd < 0) {
        fail("bpf_prog_load native helper target oracle id "
             + std::to_string(helper_id) + ": " + std::strerror(errno));
    }
    ScopedFd oracle_prog(fd);
    return decode_helper_target_oracle(oracle_prog.get(), helper_id);
}

void add_native_helper_target_addrs(const std::filesystem::path &native_object,
                                    const std::string &symbol_name,
                                    uint32_t prog_type_value,
                                    const StubLoadAttrs &attrs,
                                    ProgramLoadPlan &plan)
{
    const std::vector<int> native_helper_ids =
        collect_native_helper_call_ids(native_object, symbol_name);
    plan.native_helper_ids = native_helper_ids;
    std::unordered_set<int> native_helpers;
    for (int helper_id : native_helper_ids) {
        if (native_link_resolves_helper_target(helper_id)) {
            native_helpers.insert(helper_id);
        }
    }

    for (int helper_id : native_helpers) {
        const char *symbol = helper_symbol_for_id(helper_id);
        if (!symbol) {
            fail("native_kernel: unsupported native helper id "
                 + std::to_string(helper_id) + " in " + symbol_name);
        }
        if (plan.helper_addrs.count(symbol)) {
            continue;
        }
        const uint64_t target =
            load_helper_target_oracle(prog_type_value, attrs, helper_id);
        plan.helper_addrs.emplace(symbol, target);
    }
}

#include "native_loader_bytecode.hpp"

ProgramLoadPlan load_from_loaded_program_fd(int program_fd,
                                          const bpf_prog_info &prog_info,
                                          const bpf_insn *source_insns,
                                          size_t source_insn_cnt,
                                          const StubLoadAttrs &attrs)
{
    ProgramLoadPlan out{};
    const auto oracle_start = std::chrono::steady_clock::now();
    const auto jited_ksyms = load_jited_ksyms(program_fd, prog_info.nr_jited_ksyms);
    out.oracle_jit_base = jited_ksyms[0];
    out.oracle_jited = load_jited_program(program_fd, prog_info.jited_prog_len);
    out.oracle_xlated = load_xlated_program(program_fd, prog_info.xlated_prog_len);
    out.x86_cpu_number_addr = decode_x86_cpu_number_from_jit(out.oracle_jited);
    out.x86_this_cpu_off = decode_x86_this_cpu_off_from_jit(out.oracle_jited);
    out.x86_current_task_addr = decode_x86_current_task_from_jit(out.oracle_jited);
    const auto oracle_end = std::chrono::steady_clock::now();
    out.object_load_ns = elapsed_ns(oracle_start, oracle_end);

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
    const bool source_map_fds_are_process_fds = insns && insn_cnt > 0;
    if (!insns || insn_cnt == 0) {
        if (out.oracle_xlated.size() % sizeof(bpf_insn) != 0) {
            fail("loaded BPF program xlated image is not a whole number of bpf_insn records");
        }
        insns = reinterpret_cast<const bpf_insn *>(out.oracle_xlated.data());
        insn_cnt = out.oracle_xlated.size() / sizeof(bpf_insn);
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
        collect_source_helper_calls(insns, insn_cnt, &meta_by_source_fd);
    BpfArrayOffsets array_offsets{
        K_BPF_ARRAY_VALUE_OFFSET,
        K_BPF_ARRAY_PTRS_OFFSET,
        K_HTAB_ELEM_KEY_OFFSET,
        K_HTAB_ELEM_LRU_REF_OFFSET,
        out.x86_this_cpu_off,
    };

    auto remember_source_tail_call_map = [&](const MapMeta &meta) {
        if (meta.type != BPF_MAP_TYPE_PROG_ARRAY) {
            fail("native_kernel: source tail_call uses non-PROG_ARRAY map "
                 + meta.name);
        }
        for (const MapMeta &existing : out.source_tail_call_maps) {
            if (existing.kernel_addr == meta.kernel_addr) {
                return;
            }
        }
        out.source_tail_call_maps.push_back(meta);
    };

    for (const SourceHelperCall &call : source_calls) {
        out.source_helper_ids.push_back(call.helper_id);
        auto map_it = (call.map_fd >= 0) ? meta_by_source_fd.find(call.map_fd) : meta_by_source_fd.end();
        if (call.helper_id == BPF_FUNC_tail_call) {
            out.has_tail_call = true;
            if (map_it != meta_by_source_fd.end()) {
                remember_source_tail_call_map(map_it->second);
            }
            continue;
        }
        if (!helper_alias_for_call(call.helper_id, prog_info.type).link_name) {
            fail("native_kernel: unsupported helper id "
                 + std::to_string(call.helper_id));
        }
        if (call.helper_id == BPF_FUNC_map_lookup_elem) {
            ProgramLoadPlan::LookupSite site{
                ProgramLoadPlan::LookupSite::Kind::Call,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                {},
            };
            if (map_it != meta_by_source_fd.end()) {
                site.map_name = map_it->second.name;
                const bool configured = configure_lookup_site_for_shape(
                    site, map_shape_from_meta(map_it->second), array_offsets);
                if (configured) {
                    site.gen_lookup =
                        lookup_kernel_map_lookup_gen_by_fd(call.map_fd);
                }
                if (!site.gen_lookup.empty()) {
                    if (site.kind != ProgramLoadPlan::LookupSite::Kind::Array &&
                        site.kind != ProgramLoadPlan::LookupSite::Kind::PerCpuArray) {
                        site.target_addr =
                            lookup_kernel_map_lookup_ptr_by_fd(call.map_fd);
                    }
                } else if (site.kind != ProgramLoadPlan::LookupSite::Kind::Array &&
                           site.kind != ProgramLoadPlan::LookupSite::Kind::PerCpuArray) {
                    site.kind = ProgramLoadPlan::LookupSite::Kind::Call;
                    site.target_addr =
                        lookup_kernel_map_lookup_elem_ptr_by_fd(call.map_fd);
                }
            } else {
                configure_lookup_site_for_shape(
                    site, call.dynamic_map_shape, array_offsets);
            }
            out.lookup_sites.push_back(site);
        } else if (call.helper_id == BPF_FUNC_map_update_elem) {
            ProgramLoadPlan::UpdateSite site{
                ProgramLoadPlan::UpdateSite::Kind::Call,
                0,
                0,
                0,
                0,
                0,
                0,
            };
            if (map_it != meta_by_source_fd.end()) {
                site.target_addr = lookup_kernel_map_update_ptr_by_fd(call.map_fd);
                const uint32_t value_size = map_it->second.value_size;
                const bool simple_value =
                    value_size == 1 || value_size == 2 ||
                    value_size == 4 || value_size == 8;
                if (simple_value && (map_it->second.type == BPF_MAP_TYPE_ARRAY ||
                                     map_it->second.type == BPF_MAP_TYPE_PERCPU_ARRAY)) {
                    if (map_it->second.type == BPF_MAP_TYPE_PERCPU_ARRAY) {
                        if (array_offsets.this_cpu_off == 0) {
                            fail("native_kernel: PERCPU_ARRAY update needs gs:this_cpu_off from original JIT");
                        }
                        site.kind = ProgramLoadPlan::UpdateSite::Kind::PerCpuArray;
                        site.value_offset = array_offsets.ptrs;
                        site.percpu_base_addr = array_offsets.this_cpu_off;
                    } else {
                        site.kind = ProgramLoadPlan::UpdateSite::Kind::Array;
                        site.value_offset = array_offsets.value;
                    }
                    site.max_entries = map_it->second.max_entries;
                    site.elem_size = (value_size + 7u) & ~7u;
                    site.value_size = value_size;
                }
            }
            out.update_sites.push_back(site);
        } else if (call.helper_id == BPF_FUNC_map_delete_elem) {
            if (map_it == meta_by_source_fd.end()) {
                continue;
            }
            const uint64_t delete_addr =
                lookup_kernel_map_delete_ptr_by_fd(call.map_fd);
            if (out.map_delete_elem_addr != 0 &&
                out.map_delete_elem_addr != delete_addr) {
                fail("native_kernel: one program deletes from maps with "
                     "different map_delete_elem targets; per-site delete "
                     "metadata is required");
            }
            out.map_delete_elem_addr = delete_addr;
        }
    }
    const auto lookup_spec_end = std::chrono::steady_clock::now();
    out.lookup_spec_ns = elapsed_ns(lookup_spec_start, lookup_spec_end);

    return out;
}

#include "native_loader_link_schema.hpp"

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
    hash.add_string("loaded_prog_oracle_xlated");
    hash.add_bytes(link_args.oracle_xlated.data(), link_args.oracle_xlated.size());
    hash_file_identity(hash, link_args.linker, "native_linker");
    hash.add_string(symbol_name);
    hash.add_string("oracle_jit_base");
    hash.add_u64(link_args.oracle_jit_base);
    hash.add_string("oracle_jited");
    hash.add_bytes(link_args.oracle_jited.data(), link_args.oracle_jited.size());
    hash.add_string("oracle_xlated");
    hash.add_bytes(link_args.oracle_xlated.data(), link_args.oracle_xlated.size());
    for (int helper_id : link_args.source_helper_ids) {
        hash.add_string("source_helper");
        hash.add_u64(static_cast<uint64_t>(helper_id));
    }
    for (const auto &arg : link_args.helpers) {
        hash.add_string("helper");
        hash.add_string(arg);
    }
    for (const auto &arg : link_args.maps) {
        hash.add_string("map");
        hash.add_string(arg);
    }
    for (const auto &arg : link_args.lookup_sites) {
        hash.add_string("lookup");
        hash.add_string(arg);
    }
    for (const auto &arg : link_args.lookup_gens) {
        hash.add_string("lookup_gen");
        hash.add_string(arg);
    }
    for (const auto &arg : link_args.lookup_maps) {
        hash.add_string("lookup_map");
        hash.add_string(arg);
    }
    for (const auto &arg : link_args.update_maps) {
        hash.add_string("update_map");
        hash.add_string(arg);
    }
    for (const auto &arg : link_args.update_sites) {
        hash.add_string("update");
        hash.add_string(arg);
    }
    return hash.hex();
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

    const std::filesystem::path proof_stderr = base.string() + ".proof.stderr.txt";
    int proof_rc = run_subprocess(proof_argv, proof_stderr);
    if (proof_rc != 0) {
        std::ostringstream msg;
        msg << "native-link proof failed (rc=" << proof_rc << "): ";
        for (auto &a : proof_argv) msg << a << " ";
        const std::string stderr_text = read_text_file_limited(proof_stderr, 2048);
        if (!stderr_text.empty()) {
            msg << "\nstderr:\n" << stderr_text;
        }
        fail(msg.str());
    }
    std::error_code proof_ec;
    std::filesystem::remove(proof_stderr, proof_ec);

    const bool has_oracle = link_args.oracle_jit_base != 0 &&
                            !link_args.oracle_jited.empty() &&
                            !link_args.oracle_xlated.empty();
    const bool partial_oracle = link_args.oracle_jit_base != 0 ||
                                !link_args.oracle_jited.empty() ||
                                !link_args.oracle_xlated.empty();
    if (partial_oracle && !has_oracle) {
        fail("native_kernel: incomplete plan JIT oracle");
    }
    std::filesystem::path oracle_jited;
    std::filesystem::path oracle_xlated;
    if (has_oracle) {
        oracle_jited = base.string() + ".oracle.jited.bin";
        oracle_xlated = base.string() + ".oracle.xlated.bin";
        write_binary_file(
            oracle_jited,
            link_args.oracle_jited.data(),
            link_args.oracle_jited.size());
        write_binary_file(
            oracle_xlated,
            link_args.oracle_xlated.data(),
            link_args.oracle_xlated.size());
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
    if (has_oracle) {
        argv.push_back("--oracle-jited");
        argv.push_back(oracle_jited.string());
        argv.push_back("--oracle-jit-base");
        argv.push_back(format_hex(link_args.oracle_jit_base));
        argv.push_back("--oracle-xlated");
        argv.push_back(oracle_xlated.string());
        for (int helper_id : link_args.source_helper_ids) {
            argv.push_back("--source-helper");
            argv.push_back(std::to_string(helper_id));
        }
    }

    for (const auto &arg : link_args.helpers) {
        argv.push_back("--helper");
        argv.push_back(arg);
    }
    for (const auto &arg : link_args.maps) {
        argv.push_back("--map");
        argv.push_back(arg);
    }
    for (const auto &arg : link_args.lookup_sites) {
        argv.push_back("--lookup-site");
        argv.push_back(arg);
    }
    for (const auto &arg : link_args.lookup_gens) {
        argv.push_back("--lookup-gen");
        argv.push_back(arg);
    }
    for (const auto &arg : link_args.lookup_maps) {
        argv.push_back("--lookup-map");
        argv.push_back(arg);
    }
    for (const auto &arg : link_args.update_maps) {
        argv.push_back("--update-map");
        argv.push_back(arg);
    }
    for (const auto &arg : link_args.update_sites) {
        argv.push_back("--update-site");
        argv.push_back(arg);
    }

    const std::filesystem::path kernel_stderr = base.string() + ".kernel.stderr.txt";
    int rc = run_subprocess(argv, kernel_stderr);
    if (rc != 0) {
        std::ostringstream msg;
        msg << "native-link kernel failed (rc=" << rc << ")";
        const std::string stderr_text = read_text_file_limited(kernel_stderr, 8192);
        if (!stderr_text.empty()) {
            msg << "\nstderr:\n" << stderr_text;
        }
        msg << "\ncommand: ";
        for (auto &a : argv) msg << a << " ";
        fail(msg.str());
    }
    std::error_code kernel_ec;
    std::filesystem::remove(kernel_stderr, kernel_ec);
    return out;
}

LinkedBlob load_or_link_native_blob(const native_loader::ProgramLoadOptions &options,
                                    const std::filesystem::path &elf_path,
                                    const std::string &symbol_name,
                                    const ProgramLoadPlan &plan)
{
    const auto cache_lookup_start = std::chrono::steady_clock::now();
    NativeLinkArgs link_args =
        build_native_link_args(options, plan.map_addrs, plan);
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
            collect_relocated_map_ids(map_patches, plan.map_addr_ids);
        linked.callee_saved_mask = read_link_abi_file(source.abi);
        const auto read_end = std::chrono::steady_clock::now();
        publish_cache_file(tmp.proof, cache.proof);
        publish_cache_file(tmp.blob, cache.blob);
        publish_cache_file(tmp.relocs, cache.relocs);
        publish_cache_file(tmp.map_patches, cache.map_patches);
        publish_cache_file(tmp.abi, cache.abi);
        const auto patch_start = std::chrono::steady_clock::now();
        patch_map_literals(linked.blob, map_patches, plan.map_addrs);
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
        collect_relocated_map_ids(map_patches, plan.map_addr_ids);
    linked.callee_saved_mask = read_link_abi_file(source.abi);
    const auto read_end = std::chrono::steady_clock::now();
    const auto patch_start = std::chrono::steady_clock::now();
    patch_map_literals(linked.blob, map_patches, plan.map_addrs);
    const auto patch_end = std::chrono::steady_clock::now();
    linked.native_link_read_ns = elapsed_ns(read_start, read_end);
    linked.map_patch_ns = elapsed_ns(patch_start, patch_end);
    return linked;
}

struct LoadedStub {
    int prog_fd = -1;
    uint64_t upload_ns = 0;
    uint64_t prog_load_ns = 0;
};

LoadedStub upload_and_load_stub(const LinkedBlob &linked,
                                uint32_t prog_type,
                                const StubLoadAttrs &attrs,
                                bool tail_call_reachable,
                                const std::vector<int> &map_ref_fds)
{
    LoadedStub out{};

    const auto upload_start = std::chrono::steady_clock::now();
    auto upload_end = upload_start;
    {
        NativeLabUploadLock upload_lock;
        ensure_debugfs_mounted();
        std::vector<NativeLabReloc> relocs =
            parse_native_lab_relocs(linked.relocs, linked.blob.size());
        std::vector<NativeBlobChunk> chunks =
            plan_blob_chunks(linked.blob.size(), relocs);
        upload_blob(linked.blob, chunks);
        upload_relocs(relocs, chunks);
        upload_end = std::chrono::steady_clock::now();

        const auto prog_load_start = std::chrono::steady_clock::now();
        NativeStubBtfIds stub_btf = find_native_stub_btf_ids();
        ScopedFd mod_btf_fd(open_module_btf_fd_by_id(stub_btf.module_btf_id));
        out.prog_fd = load_stub_prog(
            stub_btf.kfunc_btf_id,
            mod_btf_fd.get(),
            static_cast<uint32_t>(chunks.size()),
            linked.callee_saved_mask,
            prog_type,
            attrs,
            tail_call_reachable,
            map_ref_fds);
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

LoadedProgram load_from_program_fd(const ProgramLoadOptions &options)
{
    if (options.original_prog_fd < 0) {
        fail("native_loader: missing original_prog_fd");
    }
    if (options.native_object_path.empty()) {
        fail("native_loader: missing native_object_path");
    }
    if (!options.source_insns || options.source_insn_cnt == 0) {
        fail("native_loader: missing source BPF bytecode");
    }
    LoadedProgram out{};
    const auto companion_load_start = std::chrono::steady_clock::now();
    const bpf_prog_info prog_info = load_prog_info(options.original_prog_fd);
    std::string symbol_name = options.symbol_name.empty()
        ? load_prog_btf_symbol_name(options.original_prog_fd, prog_info)
        : options.symbol_name;
    StubLoadAttrs stub_attrs{};
    stub_attrs.expected_attach_type = options.expected_attach_type;
    stub_attrs.attach_btf_id = options.attach_btf_id
        ? options.attach_btf_id
        : prog_info.attach_btf_id;
    stub_attrs.prog_btf_id = options.prog_btf_id;
    stub_attrs.attach_btf_obj_id = options.attach_btf_obj_id
        ? options.attach_btf_obj_id
        : prog_info.attach_btf_obj_id;
    stub_attrs.attach_prog_id = options.attach_prog_id;
    ProgramLoadPlan plan =
        load_from_loaded_program_fd(
            options.original_prog_fd,
            prog_info,
            options.source_insns,
            options.source_insn_cnt,
            stub_attrs);
    add_native_data_symbol_addrs(options.native_object_path, plan);
    add_native_helper_target_addrs(
        options.native_object_path,
        symbol_name,
        prog_info.type,
        stub_attrs,
        plan);
    const auto companion_load_end = std::chrono::steady_clock::now();

    LinkedBlob linked = load_or_link_native_blob(
        options,
        options.native_object_path,
        symbol_name,
        plan);

    std::vector<uint32_t> original_map_ids =
        load_prog_map_ids(options.original_prog_fd);
    std::vector<int> map_ref_fds =
        reopen_relocated_map_fds(linked.relocated_map_ids);
    LoadedStub loaded_stub{};
    try {
        loaded_stub = upload_and_load_stub(
            linked,
            prog_info.type,
            stub_attrs,
            plan.has_tail_call,
            map_ref_fds);
        close_fd_vector(map_ref_fds);
    } catch (const std::exception &e) {
        std::ostringstream msg;
        msg << e.what()
            << "\nnative_loader context: prog_type=" << prog_info.type
            << " expected_attach=" << stub_attrs.expected_attach_type
            << " attach_btf_id=" << stub_attrs.attach_btf_id
            << " prog_btf_id=" << stub_attrs.prog_btf_id
            << " attach_btf_obj_id=" << stub_attrs.attach_btf_obj_id
            << " attach_prog_id=" << stub_attrs.attach_prog_id
            << " tail_call_reachable=" << (plan.has_tail_call ? 1 : 0)
            << " native_blob_bytes=" << linked.blob.size()
            << " native_reloc_bytes=" << linked.relocs.size()
            << " original_map_ids=" << format_map_ids(original_map_ids)
            << " relocated_map_ids=" << format_map_ids(linked.relocated_map_ids)
            << " map_ref_fds=" << format_map_fds(map_ref_fds);
        close_fd_vector(map_ref_fds);
        fail(msg.str());
    } catch (...) {
        close_fd_vector(map_ref_fds);
        throw;
    }

    out.prog_fd = loaded_stub.prog_fd;
    out.callee_saved_mask = linked.callee_saved_mask;
    out.bpf_bytecode_bytes = plan.oracle_xlated.size();
    out.native_code_bytes = linked.blob.size();
    out.timings.companion_load_ns = elapsed_ns(companion_load_start, companion_load_end);
    out.timings.companion_object_load_ns = plan.object_load_ns;
    out.timings.companion_map_ptr_extract_ns = plan.map_ptr_extract_ns;
    out.timings.companion_lookup_spec_ns = plan.lookup_spec_ns;
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
    loaded.prog_fd = -1;
}

} // namespace

extern "C" int native_loader_load_from_fd_with_source_path_and_attach(
    int original_prog_fd,
    const char *native_object_path,
    const char *symbol_name,
    const char *source_bpf_path,
    uint32_t expected_attach_type,
    uint32_t attach_btf_id,
    uint32_t prog_btf_id,
    uint32_t attach_btf_obj_id,
    uint32_t attach_prog_id,
    struct native_loader_c_result *out)
{
    if (out) {
        out->prog_fd = -1;
        out->error[0] = '\0';
    }
    if (original_prog_fd < 0 || !native_object_path || !native_object_path[0] ||
        !source_bpf_path || !source_bpf_path[0]) {
        if (out) {
            std::snprintf(out->error, sizeof(out->error),
                          "native_loader_load_from_fd_with_source_path_and_attach requires fd, native object, and source BPF path");
        }
        errno = EINVAL;
        return -1;
    }

    try {
        std::vector<bpf_insn> source_insns = read_bpf_insn_file(source_bpf_path);
        native_loader::ProgramLoadOptions options{};
        options.original_prog_fd = original_prog_fd;
        options.native_object_path = native_object_path;
        if (symbol_name && symbol_name[0]) {
            options.symbol_name = symbol_name;
        }
        options.source_insns = source_insns.data();
        options.source_insn_cnt = source_insns.size();
        options.expected_attach_type = expected_attach_type;
        options.attach_btf_id = attach_btf_id;
        options.prog_btf_id = prog_btf_id;
        options.attach_btf_obj_id = attach_btf_obj_id;
        options.attach_prog_id = attach_prog_id;
        native_loader::LoadedProgram loaded =
            native_loader::load_from_program_fd(options);
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
