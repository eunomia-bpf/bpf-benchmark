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
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <limits>
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

/* Stage 2 helpers that native-link can lower. For companion-object loads the
 * helper address usually comes from the companion program's JIT oracle. For
 * already-loaded app programs, the verifier may leave no usable oracle target
 * for map helpers, so native-loader also resolves supported helper symbols
 * through /proc/kallsyms and passes them as explicit per-site targets. */
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
#if defined(__aarch64__)
constexpr const char *kArm64ThreadInfoCpuOffsetHelperKey =
    "__native_arm64_thread_info_cpu_offset";
#endif
constexpr const char *kNativeLinkCacheDir = "/tmp/native_kernel_link_cache";
constexpr const char *kNativeLinkCacheVersion = "native-link-template-cache-v41";
constexpr const char *kKallsymsCachePath = "/tmp/native_kernel_kallsyms.tsv";
constexpr const char *kKallsymsCacheVersion = "native-kallsyms-cache-v3";
constexpr const char *kNativeStubBtfCachePath = "/tmp/native_kernel_stub_btf.tsv";
constexpr const char *kNativeStubBtfCacheVersion = "native-stub-btf-cache-v1";
constexpr const char *kHtabLookupElemSymbol = "__htab_map_lookup_elem";
constexpr const char *kArrayOfMapLookupElemSymbol = "array_of_map_lookup_elem";
constexpr const char *kHtabLruPercpuMapLookupElemSymbol =
    "htab_lru_percpu_map_lookup_elem";
constexpr const char *kHtabLruPercpuMapUpdateElemSymbol =
    "htab_lru_percpu_map_update_elem";
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

uint64_t lookup_native_lab_ptr_by_fd(int map_fd,
                                     const char *path,
                                     const char *label)
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
        fail(std::string("bpf_prog_load (native_lab stub): ")
             + std::strerror(errno));
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

bool has_all_wanted_symbols(const std::unordered_map<std::string, uint64_t> &table,
                            const char *const *wanted,
                            size_t wanted_count)
{
    for (size_t i = 0; i < wanted_count; i++) {
        if (table.find(wanted[i]) == table.end()) {
            return false;
        }
    }
    return true;
}

bool load_kallsyms_cache(std::unordered_map<std::string, uint64_t> &table,
                         const char *const *wanted,
                         size_t wanted_count,
                         const std::string &boot_id)
{
    FILE *f = std::fopen(kKallsymsCachePath, "re");
    if (!f) {
        if (errno == ENOENT) {
            return false;
        }
        fail("open " + std::string(kKallsymsCachePath) + ": " +
             std::strerror(errno));
    }

    bool valid_version = false;
    bool valid_arch = false;
    bool valid_boot = false;
    std::unordered_map<std::string, uint64_t> cached;
    char line[512];
    while (std::fgets(line, sizeof(line), f)) {
        char key[256] = {};
        char value[256] = {};
        if (std::sscanf(line, "%255s %255s", key, value) != 2) {
            std::fclose(f);
            fail("malformed native_kernel kallsyms cache line");
        }
        if (std::strcmp(key, "version") == 0) {
            valid_version = std::strcmp(value, kKallsymsCacheVersion) == 0;
            continue;
        }
        if (std::strcmp(key, "arch") == 0) {
            valid_arch = std::strcmp(value, native_arch_name()) == 0;
            continue;
        }
        if (std::strcmp(key, "boot_id") == 0) {
            valid_boot = boot_id == value;
            continue;
        }
        for (size_t i = 0; i < wanted_count; i++) {
            if (std::strcmp(key, wanted[i]) == 0) {
                cached.emplace(wanted[i], std::strtoull(value, nullptr, 16));
                break;
            }
        }
    }
    std::fclose(f);

    if (!valid_version || !valid_arch || !valid_boot ||
        !has_all_wanted_symbols(cached, wanted, wanted_count)) {
        return false;
    }

    table = std::move(cached);
    return true;
}

void store_kallsyms_cache(const std::unordered_map<std::string, uint64_t> &table,
                          const char *const *wanted,
                          size_t wanted_count,
                          const std::string &boot_id)
{
    if (!has_all_wanted_symbols(table, wanted, wanted_count)) {
        return;
    }

    std::filesystem::path tmp =
        std::string(kKallsymsCachePath) + "." + std::to_string(getpid()) + ".tmp";
    std::ofstream out(tmp);
    if (!out) {
        fail("open " + tmp.string() + ": " + std::strerror(errno));
    }
    out << "version " << kKallsymsCacheVersion << "\n";
    out << "arch " << native_arch_name() << "\n";
    out << "boot_id " << boot_id << "\n";
    for (size_t i = 0; i < wanted_count; i++) {
        auto it = table.find(wanted[i]);
        if (it == table.end()) {
            fail("native_kernel kallsyms cache missing " + std::string(wanted[i]));
        }
        char addr[32];
        std::snprintf(addr, sizeof(addr), "0x%llx",
                      static_cast<unsigned long long>(it->second));
        out << wanted[i] << " " << addr << "\n";
    }
    out.close();
    if (!out) {
        fail("write " + tmp.string() + ": " + std::strerror(errno));
    }

    std::error_code ec;
    std::filesystem::rename(tmp, kKallsymsCachePath, ec);
    if (ec) {
        fail("publish " + std::string(kKallsymsCachePath) + ": " + ec.message());
    }
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
    wanted.push_back(kHtabLruPercpuMapUpdateElemSymbol);
    const size_t wanted_count = wanted.size();

    const std::string boot_id =
        read_first_line_required("/proc/sys/kernel/random/boot_id");
    if (load_kallsyms_cache(table, wanted.data(), wanted_count, boot_id)) {
        return table;
    }

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
    store_kallsyms_cache(table, wanted.data(), wanted_count, boot_id);
    return table;
}

/* Look up non-helper kernel implementation details that the current map and
 * per-cpu lowerings still need. BPF helper call targets must come from the
 * companion JIT oracle instead. */
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

uint64_t htab_lookup_elem_kernel_addr()
{
    uint64_t addr = kallsyms_lookup(kHtabLookupElemSymbol);
    if (addr == 0) {
        fail(std::string("native_kernel: ") + kHtabLookupElemSymbol +
             " is missing from /proc/kallsyms");
    }
    return addr;
}

uint64_t array_of_map_lookup_elem_kernel_addr()
{
    uint64_t addr = kallsyms_lookup(kArrayOfMapLookupElemSymbol);
    if (addr == 0) {
        fail(std::string("native_kernel: ") + kArrayOfMapLookupElemSymbol +
             " is missing from /proc/kallsyms");
    }
    return addr;
}

uint64_t htab_lru_percpu_map_lookup_elem_kernel_addr()
{
    uint64_t addr = kallsyms_lookup(kHtabLruPercpuMapLookupElemSymbol);
    if (addr == 0) {
        fail(std::string("native_kernel: ") + kHtabLruPercpuMapLookupElemSymbol +
             " is missing from /proc/kallsyms");
    }
    return addr;
}

uint64_t htab_lru_percpu_map_update_elem_kernel_addr()
{
    uint64_t addr = kallsyms_lookup(kHtabLruPercpuMapUpdateElemSymbol);
    if (addr == 0) {
        fail(std::string("native_kernel: ") + kHtabLruPercpuMapUpdateElemSymbol +
             " is missing from /proc/kallsyms");
    }
    return addr;
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

struct NativeMapShape {
    int type = -1;
    uint32_t key_size = 0;
    uint32_t value_size = 0;
    uint32_t max_entries = 0;
};

NativeMapShape expected_native_map_shape(const std::string &name)
{
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

void add_contextual_helper_alias_if_available(std::vector<std::string> &helpers,
                                              int helper_id,
                                              uint32_t prog_type)
{
    const HelperAlias alias = helper_alias_for_call(helper_id, prog_type);
    if (!alias.link_name || !alias.kernel_symbol) {
        return;
    }
    const uint64_t addr = kallsyms_lookup(alias.kernel_symbol);
    if (addr == 0) {
        return;
    }
    char value_buf[32];
    std::snprintf(value_buf, sizeof(value_buf), "0x%llx",
                  static_cast<unsigned long long>(addr));
    const std::string arg = std::string(alias.link_name) + "=" + value_buf;
    for (const std::string &existing : helpers) {
        if (existing == arg) {
            return;
        }
    }
    helpers.push_back(arg);
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

/* Stage 2: given an ELF .native.o input, pass the companion program's JIT
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
    std::vector<std::string> helpers;
    std::vector<std::string> maps;
    std::vector<std::string> lookup_sites;
    std::vector<std::string> lookup_maps;
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

/* Libbpf-load the canonical `.bpf.o` companion so the kernel allocates
 * maps, then ask the native_lab kernel module to translate map fds into
 * kernel pointers. The caller MUST keep the returned bpf_object alive
 * while the native_kernel run executes -- closing it frees the maps. */
struct CompanionLoad {
    bpf_object *obj = nullptr;
    uint64_t open_ns = 0;
    uint64_t object_load_ns = 0;
    uint64_t map_ptr_extract_ns = 0;
    uint64_t lookup_spec_ns = 0;
    uint64_t oracle_jit_base = 0;
    std::vector<uint8_t> oracle_jited;
    std::vector<uint8_t> oracle_xlated;
    bool use_helper_oracle = true;
    bool allow_kernel_symbol_lookup = true;
    bool has_tail_call = false;
    std::unordered_map<std::string, uint64_t> map_addrs;
    std::unordered_map<std::string, uint32_t> map_addr_ids;
    std::unordered_map<std::string, std::string> native_map_symbols;
    std::unordered_map<std::string, MapMeta> exact_map_addrs;
    std::unordered_set<std::string> ambiguous_exact_maps;
    std::vector<std::string> helper_args;
    uint32_t prog_type = 0;
    std::vector<MapMeta> maps;
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
    };
    std::vector<UpdateSite> update_sites;
};

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

const MapMeta *find_single_cilium_calls_map(const CompanionLoad &load)
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

    MapMeta process_map{};
    if (find_open_process_map_by_name(name, process_map)) {
        add_map_meta(load, process_map);
        add_map_symbol_alias_meta(load, name, process_map);
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

    return NativeMapShape{};
}

bool configure_lookup_site_for_shape(CompanionLoad::LookupSite &site,
                                     const NativeMapShape &shape,
                                     const BpfArrayOffsets &array_offsets,
                                     const BpfHtabOffsets &htab_offsets,
                                     uint64_t this_cpu_off_addr)
{
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
        uint32_t rounded = (shape.key_size + 7) & ~7u;
        site.kind = CompanionLoad::LookupSite::Kind::HashOfMaps;
        site.target_addr = htab_lookup_elem_kernel_addr();
        site.key_offset = htab_offsets.key + rounded;
        return true;
    }
    if (t == BPF_MAP_TYPE_ARRAY_OF_MAPS) {
        site.kind = CompanionLoad::LookupSite::Kind::Call;
        site.target_addr = array_of_map_lookup_elem_kernel_addr();
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

CompanionLoad::LookupSite oracle_call_lookup_site_for_map_meta(const MapMeta &meta)
{
    CompanionLoad::LookupSite site{
        CompanionLoad::LookupSite::Kind::Call,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    site.map_name = meta.name;
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

#include "native_loader_bytecode.hpp"

CompanionLoad load_bpf_companion(const std::filesystem::path &bpf_o_path)
{
    CompanionLoad out{};
    struct stat st {};
    std::string bpf_path = bpf_o_path.string();
    if (stat(bpf_path.c_str(), &st) != 0) {
        fail("native_kernel companion .bpf.o is missing: " + bpf_path);
    }

    const auto open_start = std::chrono::steady_clock::now();
    bpf_object *obj = bpf_object__open_file(bpf_path.c_str(), nullptr);
    if (!obj || libbpf_get_error(obj)) {
        fail(std::string("bpf_object__open_file ") + bpf_path);
    }
    const auto open_end = std::chrono::steady_clock::now();
    out.open_ns = elapsed_ns(open_start, open_end);

    bpf_program *prog = nullptr;
    bpf_program *entry_prog = nullptr;
    bpf_object__for_each_program(prog, obj) {
        if (entry_prog != nullptr) {
            bpf_object__close(obj);
            fail("native_kernel companion .bpf.o has multiple BPF programs: " + bpf_path);
        }
        entry_prog = prog;
    }
    if (!entry_prog) {
        bpf_object__close(obj);
        fail("native_kernel companion .bpf.o has no BPF programs: " + bpf_path);
    }

    const auto object_load_start = std::chrono::steady_clock::now();
    if (bpf_object__load(obj) != 0) {
        bpf_object__close(obj);
        fail(std::string("bpf_object__load ") + bpf_path + ": "
             + std::strerror(errno));
    }
    const auto object_load_end = std::chrono::steady_clock::now();
    out.object_load_ns = elapsed_ns(object_load_start, object_load_end);

    const auto map_ptr_start = std::chrono::steady_clock::now();
    bpf_map *map = nullptr;
    bpf_object__for_each_map(map, obj) {
        int fd = bpf_map__fd(map);
        if (fd >= 0) {
            MapMeta meta = load_map_meta_from_fd(fd);
            add_map_meta(out, meta);
            add_exact_map_meta(out, meta);
        }
    }
    const auto map_ptr_end = std::chrono::steady_clock::now();
    out.map_ptr_extract_ns = elapsed_ns(map_ptr_start, map_ptr_end);

    /* Build per-call-site map specs for the entry program. The runner walks
     * source BPF only to associate helper sites with map metadata; native-link
     * reads the companion JIT/xlated oracle and fills helper call targets. */
    const auto lookup_spec_start = std::chrono::steady_clock::now();
    {
        int entry_fd = bpf_program__fd(entry_prog);
        if (entry_fd < 0) {
            bpf_object__close(obj);
            fail("native_kernel companion entry program has no fd after load: " + bpf_path);
        }

        const bpf_prog_info prog_info = load_prog_info(entry_fd);
        out.prog_type = prog_info.type;
        const auto jited_ksyms = load_jited_ksyms(entry_fd, prog_info.nr_jited_ksyms);
        out.oracle_jit_base = jited_ksyms[0];
        out.oracle_jited = load_jited_program(entry_fd, prog_info.jited_prog_len);
        out.oracle_xlated = load_xlated_program(entry_fd, prog_info.xlated_prog_len);

        /* Collect map metadata by fd for quick lookup. */
        std::unordered_map<int, MapMeta> meta_by_fd;
        map = nullptr;
        bpf_object__for_each_map(map, obj) {
            int fd = bpf_map__fd(map);
            if (fd >= 0) {
                meta_by_fd[fd] = load_map_meta_from_fd(fd);
            }
        }

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

        /* Walk the entry program's BPF source bytecode and build the
         * per-call-site spec list. */
        const struct bpf_insn *insns = bpf_program__insns(entry_prog);
        size_t insn_cnt = bpf_program__insn_cnt(entry_prog);
        std::vector<SourceHelperCall> source_calls =
            collect_source_helper_calls(insns, insn_cnt, &meta_by_fd);
        for (const SourceHelperCall &call : source_calls) {
            if (call.helper_id == BPF_FUNC_tail_call) {
                out.has_tail_call = true;
                continue;
            }
            if (!helper_alias_for_call(call.helper_id, prog_info.type).link_name) {
                bpf_object__close(obj);
                fail("native_kernel: unsupported helper id "
                     + std::to_string(call.helper_id));
            }

            auto map_it = (call.map_fd >= 0) ? meta_by_fd.find(call.map_fd) : meta_by_fd.end();
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
                if (map_it != meta_by_fd.end()) {
                    site.map_name = map_it->second.name;
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
                continue;
            }

            if (call.helper_id == BPF_FUNC_map_update_elem) {
                CompanionLoad::UpdateSite site{
                    CompanionLoad::UpdateSite::Kind::Call,
                    helper_kernel_addr(BPF_FUNC_map_update_elem),
                    0,
                    0,
                    0,
                    0,
                    0,
                };
                if (map_it != meta_by_fd.end()) {
                    const uint32_t value_size = map_it->second.value_size;
                    const bool simple_value =
                        value_size == 1 || value_size == 2 ||
                        value_size == 4 || value_size == 8;
                    int t = map_it->second.type;
                    if (simple_value && t == BPF_MAP_TYPE_ARRAY) {
                        site.kind = CompanionLoad::UpdateSite::Kind::Array;
                        site.max_entries = map_it->second.max_entries;
                        site.elem_size = (value_size + 7u) & ~7u;
                        site.value_size = value_size;
                        site.value_offset = array_offsets.value;
                    } else if (simple_value && t == BPF_MAP_TYPE_PERCPU_ARRAY) {
#if defined(__x86_64__)
                        if (this_cpu_off_addr == 0) {
                            fail("this_cpu_off not in /proc/kallsyms");
                        }
#endif
                        site.kind = CompanionLoad::UpdateSite::Kind::PerCpuArray;
                        site.max_entries = map_it->second.max_entries;
                        site.elem_size = sizeof(void *);
                        site.value_size = value_size;
                        site.value_offset = array_offsets.pptrs;
                        site.percpu_base_addr = this_cpu_off_addr;
                    } else if (t == BPF_MAP_TYPE_LRU_PERCPU_HASH) {
                        site.target_addr =
                            htab_lru_percpu_map_update_elem_kernel_addr();
                    }
                }
                out.update_sites.push_back(site);
                continue;
            }
        }
    }
    const auto lookup_spec_end = std::chrono::steady_clock::now();
    out.lookup_spec_ns = elapsed_ns(lookup_spec_start, lookup_spec_end);

    out.obj = obj;
    return out;
}

CompanionLoad load_from_loaded_program_fd(int program_fd,
                                          const bpf_prog_info &prog_info,
                                          const bpf_insn *source_insns,
                                          size_t source_insn_cnt)
{
    CompanionLoad out{};
    out.use_helper_oracle = true;
    out.allow_kernel_symbol_lookup = false;
    out.prog_type = prog_info.type;

    const auto oracle_start = std::chrono::steady_clock::now();
    const auto jited_ksyms = load_jited_ksyms(program_fd, prog_info.nr_jited_ksyms);
    out.oracle_jit_base = jited_ksyms[0];
    out.oracle_jited = load_jited_program(program_fd, prog_info.jited_prog_len);
    out.oracle_xlated = load_xlated_program(program_fd, prog_info.xlated_prog_len);
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

    for (const SourceHelperCall &call : source_calls) {
        if (call.helper_id == BPF_FUNC_tail_call) {
            out.has_tail_call = true;
            continue;
        }
        if (!helper_alias_for_call(call.helper_id, prog_info.type).link_name) {
            fail("native_kernel: unsupported helper id "
                 + std::to_string(call.helper_id));
        }
        auto map_it = (call.map_fd >= 0) ? meta_by_source_fd.find(call.map_fd) : meta_by_source_fd.end();
        if (call.helper_id == BPF_FUNC_map_lookup_elem) {
            CompanionLoad::LookupSite site{
                CompanionLoad::LookupSite::Kind::Call,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
            };
            if (map_it != meta_by_source_fd.end()) {
                site.map_name = map_it->second.name;
            }
            out.lookup_sites.push_back(site);
        } else if (call.helper_id == BPF_FUNC_map_update_elem) {
            CompanionLoad::UpdateSite site{
                CompanionLoad::UpdateSite::Kind::Call,
                0,
                0,
                0,
                0,
                0,
                0,
            };
            out.update_sites.push_back(site);
        }
    }
    const auto lookup_spec_end = std::chrono::steady_clock::now();
    out.lookup_spec_ns = elapsed_ns(lookup_spec_start, lookup_spec_end);

    return out;
}

#include "native_loader_link_schema.hpp"

std::string native_link_cache_key(const std::filesystem::path &native_elf,
                                  const std::filesystem::path &bpf_obj,
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
    if (bpf_obj.empty()) {
        hash.add_string("loaded_prog_oracle_xlated");
        hash.add_bytes(link_args.oracle_xlated.data(), link_args.oracle_xlated.size());
    } else {
        hash_file_contents(hash, bpf_obj, "companion_bpf");
    }
    hash_file_identity(hash, link_args.linker, "native_linker");
    hash.add_string(symbol_name);
    hash.add_string("oracle_jit_base");
    hash.add_u64(link_args.oracle_jit_base);
    hash.add_string("oracle_jited");
    hash.add_bytes(link_args.oracle_jited.data(), link_args.oracle_jited.size());
    hash.add_string("oracle_xlated");
    hash.add_bytes(link_args.oracle_xlated.data(), link_args.oracle_xlated.size());
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
    for (const auto &arg : link_args.lookup_maps) {
        hash.add_string("lookup_map");
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
        fail("native_kernel: incomplete companion JIT oracle");
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
    for (const auto &arg : link_args.lookup_maps) {
        argv.push_back("--lookup-map");
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
        msg << "\ncommand: ";
        for (auto &a : argv) msg << a << " ";
        const std::string stderr_text = read_text_file_limited(kernel_stderr, 8192);
        if (!stderr_text.empty()) {
            msg << "\nstderr:\n" << stderr_text;
        }
        fail(msg.str());
    }
    std::error_code kernel_ec;
    std::filesystem::remove(kernel_stderr, kernel_ec);
    return out;
}

LinkedBlob load_or_link_native_blob(const native_loader::LoadOptions &options,
                                    const std::filesystem::path &elf_path,
                                    const std::string &symbol_name,
                                    const CompanionLoad &companion)
{
    const auto cache_lookup_start = std::chrono::steady_clock::now();
    NativeLinkArgs link_args =
        build_native_link_args(options, companion.map_addrs, companion);
    const std::filesystem::path cache_dir = kNativeLinkCacheDir;
    std::error_code ec;
    std::filesystem::create_directories(cache_dir, ec);
    if (ec) {
        fail("create native-link cache dir " + cache_dir.string() + ": " + ec.message());
    }

    const std::string key =
        native_link_cache_key(elf_path, options.bpf_object_path, symbol_name, link_args);
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

LoadedProgram load_from_companion_object(const LoadOptions &options)
{
    if (options.bpf_object_path.empty()) {
        fail("native_loader: missing bpf_object_path");
    }
    if (options.native_object_path.empty()) {
        fail("native_loader: missing native_object_path");
    }
    if (options.symbol_name.empty()) {
        fail("native_loader: missing symbol_name");
    }
    if (options.prog_type == 0) {
        fail("native_loader: missing prog_type");
    }

    LoadedProgram out{};
    const auto companion_load_start = std::chrono::steady_clock::now();
    CompanionLoad companion = load_bpf_companion(options.bpf_object_path);
    add_native_data_symbol_addrs(options.native_object_path, companion);
    const auto companion_load_end = std::chrono::steady_clock::now();

    LinkedBlob linked = load_or_link_native_blob(
        options,
        options.native_object_path,
        options.symbol_name,
        companion);

    std::vector<int> map_ref_fds =
        reopen_relocated_map_fds(linked.relocated_map_ids);
    LoadedStub loaded_stub{};
    try {
        loaded_stub = upload_and_load_stub(
            linked,
            options.prog_type,
            StubLoadAttrs{},
            companion.has_tail_call,
            map_ref_fds);
        close_fd_vector(map_ref_fds);
    } catch (...) {
        close_fd_vector(map_ref_fds);
        throw;
    }

    out.prog_fd = loaded_stub.prog_fd;
    out.companion_object = companion.obj;
    out.callee_saved_mask = linked.callee_saved_mask;
    out.bpf_bytecode_bytes = companion.oracle_xlated.size();
    out.native_code_bytes = linked.blob.size();
    out.timings.companion_load_ns = elapsed_ns(companion_load_start, companion_load_end);
    out.timings.companion_open_ns = companion.open_ns;
    out.timings.companion_object_load_ns = companion.object_load_ns;
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

LoadedProgram load_from_fd(const FdLoadOptions &options)
{
    if (options.original_prog_fd < 0) {
        fail("native_loader: missing original_prog_fd");
    }
    if (options.native_object_path.empty()) {
        fail("native_loader: missing native_object_path");
    }
    LoadedProgram out{};
    const auto companion_load_start = std::chrono::steady_clock::now();
    const bpf_prog_info prog_info = load_prog_info(options.original_prog_fd);
    std::string symbol_name = options.symbol_name.empty()
        ? load_prog_btf_symbol_name(options.original_prog_fd, prog_info)
        : options.symbol_name;
    std::vector<bpf_insn> source_insns;
    if (!options.source_bpf_path.empty()) {
        source_insns = read_bpf_insn_file(options.source_bpf_path);
    }
    CompanionLoad companion =
        load_from_loaded_program_fd(
            options.original_prog_fd,
            prog_info,
            source_insns.empty() ? nullptr : source_insns.data(),
            source_insns.size());
    add_native_data_symbol_addrs(options.native_object_path, companion);
    const auto companion_load_end = std::chrono::steady_clock::now();

    LoadOptions link_options{};
    link_options.native_object_path = options.native_object_path;
    link_options.symbol_name = symbol_name;
    link_options.prog_type = prog_info.type;
    link_options.native_link_path = options.native_link_path;

    LinkedBlob linked = load_or_link_native_blob(
        link_options,
        options.native_object_path,
        symbol_name,
        companion);

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

    std::vector<int> map_ref_fds =
        reopen_relocated_map_fds(linked.relocated_map_ids);
    LoadedStub loaded_stub{};
    try {
        loaded_stub = upload_and_load_stub(
            linked,
            prog_info.type,
            stub_attrs,
            companion.has_tail_call,
            map_ref_fds);
        close_fd_vector(map_ref_fds);
    } catch (...) {
        close_fd_vector(map_ref_fds);
        throw;
    }

    out.prog_fd = loaded_stub.prog_fd;
    out.companion_object = nullptr;
    out.callee_saved_mask = linked.callee_saved_mask;
    out.bpf_bytecode_bytes = companion.oracle_xlated.size();
    out.native_code_bytes = linked.blob.size();
    out.timings.companion_load_ns = elapsed_ns(companion_load_start, companion_load_end);
    out.timings.companion_open_ns = companion.open_ns;
    out.timings.companion_object_load_ns = companion.object_load_ns;
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
    if (program->companion_object) {
        bpf_object__close(program->companion_object);
        program->companion_object = nullptr;
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
        native_loader::FdLoadOptions options{};
        options.original_prog_fd = original_prog_fd;
        options.native_object_path = native_object_path;
        if (symbol_name && symbol_name[0]) {
            options.symbol_name = symbol_name;
        }
        options.source_bpf_path = source_bpf_path;
        options.expected_attach_type = expected_attach_type;
        options.attach_btf_id = attach_btf_id;
        options.prog_btf_id = prog_btf_id;
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
