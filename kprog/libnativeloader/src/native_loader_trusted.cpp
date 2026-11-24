// Checked configuration from c1f831983, isolated from the 5/29 performance path.
#include "native_loader.hpp"
#include "../../../kinsn/module/include/native_lab_binding.h"
#include "../../../kinsn/module/include/native_lab_trusted_wire.h"

#include "kernel_offsets.h"

#include "native_loader_internal.hpp"
#include "native_loader_subprocess.hpp"
#include "native_loader_timings.hpp"
#include "native_loader_helper_query.hpp"
#include "native_loader_data_layout.hpp"
#include "native_loader_kfunc.hpp"
#include "native_loader_lto.hpp"

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
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <charconv>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <bit>
#include <optional>
#include <stdexcept>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

extern "C" {
#include "../../../vendor/libbpf/src/relo_core.h"
}

extern "C" char **environ;

namespace native_loader::trusted {
#include "native_loader_manifest.hpp"

using internal::fail;

using internal::ptr_to_u64;

using internal::elapsed_ns;

using internal::libbpf_error_string;

using internal::load_prog_info;

using internal::prog_info_name_or_stub;

using internal::load_xlated_program;

using internal::read_binary_file;

using internal::read_bpf_insn_file;

using internal::write_binary_file;

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
    .relocs_path_fmt = "/sys/kernel/debug/bpf_arm64_native_lab/blob%u.relocs",
    .map_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_ptr",
    .map_value_ptr_path = "/sys/kernel/debug/bpf_arm64_native_lab/map_value_ptr",
    .chunk_bytes = 128,
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

constexpr const char *kX86ThisCpuOffHelperKey = "__native_x86_this_cpu_off";
constexpr const char *kX86BpfMapMaxEntriesOffsetKey =
    "__native_x86_bpf_map_max_entries_offset";
constexpr const char *kX86BpfArrayPtrsOffsetKey = "__native_x86_bpf_array_ptrs_offset";
constexpr const char *kX86BpfProgBpfFuncOffsetKey =
    "__native_x86_bpf_prog_bpf_func_offset";
constexpr const char *kX86TailCallOffsetKey = "__native_x86_tail_call_offset";
constexpr const char *kArm64ThreadInfoCpuOffsetHelperKey =
    "__native_arm64_thread_info_cpu_offset";
constexpr const char *kNativeLinkCacheDir = "/tmp/native_kernel_link_cache";
constexpr const char *kNativeLinkCacheVersion = "native-link-template-cache-v44";

constexpr const char *kHtabLookupElemSymbol = "__htab_map_lookup_elem";
constexpr const char *kArrayOfMapLookupElemSymbol = "array_of_map_lookup_elem";
constexpr const char *kHtabLruPercpuMapLookupElemSymbol =
    "htab_lru_percpu_map_lookup_elem";
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
                                     bool *immutable = nullptr)
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
    if (immutable) {
        char *last = nullptr;
        const auto flag = std::strtoul(end, &last, 10);
        if (last == end || flag > 1)
            fail(std::string("native_kernel: invalid immutable-map metadata: ") + response);
        *immutable = flag != 0;
    }
    return static_cast<uint64_t>(value);
}

uint64_t lookup_kernel_map_ptr_by_fd(int map_fd)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_ptr_path, "map_ptr");
}

uint64_t lookup_kernel_map_value_ptr_by_fd(int map_fd, bool *immutable = nullptr)
{
    return lookup_native_lab_ptr_by_fd(
        map_fd, kNativeLabTarget.map_value_ptr_path, "map_value_ptr", immutable);
}

constexpr size_t kRelocRecordBytes = 16;

struct NativeLabReloc {
    uint32_t global_offset;
    uint32_t kind;
    uint64_t target;
};

using internal::read_u32_le;

using internal::read_u64_le;

using internal::append_u32_le;

using internal::append_u64_le;

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
        const int patch = native_lab_reloc_patch_size(kind);
        if (patch < 0) {
            fail("native_lab reloc has unknown kind " + std::to_string(kind));
        }
        if (static_cast<size_t>(global_offset) + patch > blob_size) {
            fail("native_lab reloc patch exceeds blob bounds");
        }
        out.push_back(NativeLabReloc{
            global_offset,
            kind,
            target,
        });
    }
    return out;
}

using internal::ScopedFd;

using internal::open_btf_fd_by_id_required;

using internal::open_prog_fd_by_id_required;

int create_tail_call_marker_map()
{
    int fd = bpf_map_create(BPF_MAP_TYPE_PROG_ARRAY, "native_tail_call_probe",
                            sizeof(uint32_t), sizeof(uint32_t), 1, nullptr);
    if (fd < 0)
        fail("bpf_map_create native tail-call probe map: " + std::string(std::strerror(errno)));
    return fd;
}

std::vector<bpf_insn> native_stub_program(int tail_map_fd)
{
    // Both native entry paths use this verifier-visible frame description.
    // The JIT emits P in place of these instructions.
    if (tail_map_fd < 0)
        return {{.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0},
                {.code = BPF_JMP | BPF_EXIT}};
    return {
        {.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0},
        {.code = BPF_JMP | BPF_JNE | BPF_K, .dst_reg = BPF_REG_0, .off = 2},
        {.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0},
        {.code = BPF_JMP | BPF_EXIT},
        {.code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_2,
         .src_reg = BPF_PSEUDO_MAP_FD, .imm = tail_map_fd},
        {},
        {.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_3},
        {.code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_tail_call},
        {.code = BPF_JMP | BPF_EXIT},
    };
}

using internal::Hash64;

using internal::hash_file_contents;

using internal::hash_file_identity;

struct MapPatchSite {
    std::string name;
    size_t offset = 0;
};

using internal::parse_decimal_u64;

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

uint32_t read_link_abi_file(const std::filesystem::path &path,
                            std::vector<native_lab_load_site> *load_sites = nullptr)
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
        if (key == "load_site" && load_sites) {
            std::string fields = value;
            std::replace(fields.begin(), fields.end(), ',', ' ');
            std::istringstream row(fields);
            uint32_t offset, length, destination;
            if (!(row >> offset >> length >> destination))
                fail("read native load site: " + path.string());
            load_sites->push_back(native_lab_load_site{
                offset, static_cast<uint16_t>(length), static_cast<uint16_t>(destination)});
        } else if (key == "version") {
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

const char *helper_symbol_for_id(int helper_id);

const std::unordered_map<std::string, uint64_t> &kallsyms_table()
{
    static std::unordered_map<std::string, uint64_t> table;
    if (!table.empty()) {
        return table;
    }

    std::unordered_set<std::string_view> wanted;
#if defined(__x86_64__)
    wanted.insert("this_cpu_off");
#endif
    for (const auto &helper : kSupportedHelpers) {
        wanted.insert(helper.symbol);
    }
    for (const char *symbol : kTypedHelperSymbols) {
        wanted.insert(symbol);
    }
    for (const char *symbol : kRuntimeCallSymbols) {
        wanted.insert(symbol);
    }
    wanted.insert(kHtabLookupElemSymbol);
    wanted.insert(kArrayOfMapLookupElemSymbol);
    wanted.insert(kHtabLruPercpuMapLookupElemSymbol);
    wanted.insert("trie_lookup_elem");
    wanted.insert("bpf_verifier_ops");
#if defined(__x86_64__)
    for (const char *symbol : native_lto::kernel_symbols) {
        wanted.insert(symbol);
    }
#endif

    std::ifstream input("/proc/kallsyms");
    if (!input) {
        fail("open /proc/kallsyms: " + std::string(std::strerror(errno)));
    }
    std::string line;
    while (std::getline(input, line)) {
        const size_t address_end = line.find(' ');
        const size_t type = line.find_first_not_of(" \t", address_end);
        const size_t name_start = line.find_first_not_of(" \t", type + 1);
        if (address_end == std::string::npos || type == std::string::npos ||
            name_start == std::string::npos) {
            fail("malformed /proc/kallsyms record");
        }
        const size_t name_end = line.find_first_of(" \t", name_start);
        const std::string_view name(line.data() + name_start,
            (name_end == std::string::npos ? line.size() : name_end) - name_start);
        if (!wanted.erase(name)) {
            continue;
        }
        uint64_t address = 0;
        const auto parsed = std::from_chars(line.data(), line.data() + address_end,
                                            address, 16);
        if (parsed.ec != std::errc{} || parsed.ptr != line.data() + address_end) {
            fail("invalid address in /proc/kallsyms for " + std::string(name));
        }
        table.emplace(name, address);
        if (wanted.empty()) {
            break;
        }
    }
    if (input.bad()) {
        fail("read /proc/kallsyms failed");
    }
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

std::vector<std::pair<std::string, uint64_t>> query_program_helper_targets(
    int program_fd, uint32_t program_type)
{
    const uint64_t ops = kallsyms_lookup("bpf_verifier_ops");
    if (!ops)
        fail("native_loader: bpf_verifier_ops missing from /proc/kallsyms");
    std::vector<uint32_t> ids;
    std::vector<std::string> names;
    for (const auto &helper : kCanonicalHelperIdentities) {
        if (helper.id == BPF_FUNC_unspec) continue;
        ids.push_back(helper.id);
        names.emplace_back(helper.name);
    }
    const auto request = encode_helper_query(ops, program_fd, program_type, ids);
    const std::string path = std::string(kNativeLabTarget.debugfs_dir) + "/helper_targets";
    ScopedFd fd(open(path.c_str(), O_RDWR | O_CLOEXEC));
    if (fd.get() < 0)
        fail("open " + path + ": " + std::strerror(errno));
    ssize_t written;
    do { written = write(fd.get(), request.data(), request.size()); }
    while (written < 0 && errno == EINTR);
    if (written < 0)
        fail("write " + path + ": " + std::strerror(errno));
    if (static_cast<size_t>(written) != request.size())
        fail("short write " + path);
    if (lseek(fd.get(), 0, SEEK_SET) < 0)
        fail("seek " + path + ": " + std::strerror(errno));
    std::vector<uint8_t> response(ids.size() * sizeof(uint64_t));
    size_t offset = 0;
    while (offset < response.size()) {
        ssize_t n = read(fd.get(), response.data() + offset, response.size() - offset);
        if (n < 0 && errno == EINTR) continue;
        if (n < 0)
            fail("read " + path + ": " + std::strerror(errno));
        if (!n) break;
        offset += static_cast<size_t>(n);
    }
    response.resize(offset);
    const auto targets = decode_helper_targets(response, ids.size());
    std::vector<std::pair<std::string, uint64_t>> result;
    for (size_t i = 0; i < targets.size(); ++i) {
        if (!targets[i]) continue;
        result.emplace_back(names[i], targets[i]);
        // Existing native objects can use an implementation's historical
        // spelling. Bind it to the same actual prototype as the UAPI name.
        for (const auto &legacy : kSupportedHelpers)
            if (legacy.id == static_cast<int>(ids[i]) && names[i] != legacy.symbol)
                result.emplace_back(legacy.symbol, targets[i]);
    }
    return result;
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
    uint32_t btf_id = 0;
    uint32_t btf_value_type_id = 0;
    std::vector<uint8_t> immutable_value;
    uint32_t inner_type = 0;
    uint32_t inner_value_size = 0;
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

bool map_info_matches_shape(const bpf_map_info &info, const NativeMapShape &shape)
{
    if (shape.type >= 0 && static_cast<int>(info.type) != shape.type) {
        return false;
    }
    if (shape.key_size != 0 && info.key_size != shape.key_size) {
        return false;
    }
    if (shape.value_size != 0 && info.value_size != shape.value_size) {
        return false;
    }
    if (shape.max_entries != 0 && info.max_entries != shape.max_entries) {
        return false;
    }
    return true;
}

using internal::fd_is_bpf_map;

using internal::roundup_pow2_mask;

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

using internal::load_prog_btf_symbol_name;

using internal::load_prog_map_ids;

using internal::load_prog_map_ids;

using internal::load_map_info;

uint64_t lookup_array_value_addr_if_direct(const bpf_map_info &info, int map_fd,
                                         bool *immutable = nullptr)
{
    if (info.type != BPF_MAP_TYPE_ARRAY || info.max_entries != 1) {
        return 0;
    }
    return lookup_kernel_map_value_ptr_by_fd(map_fd, immutable);
}

MapMeta load_map_meta_from_fd(int map_fd)
{
    bpf_map_info info = load_map_info(map_fd);
    char name[sizeof(info.name) + 1] = {};
    std::memcpy(name, info.name, sizeof(info.name));
    if (name[0] == '\0') {
        fail("loaded BPF program references unnamed map fd " + std::to_string(map_fd));
    }
    bool immutable = false;
    const auto value_addr = lookup_array_value_addr_if_direct(info, map_fd, &immutable);
    MapMeta meta{
        std::string(name),
        map_fd,
        info.id,
        static_cast<int>(info.type),
        info.key_size,
        info.value_size,
        info.max_entries,
        lookup_kernel_map_ptr_by_fd(map_fd),
        value_addr,
        info.btf_id,
        info.btf_value_type_id,
    };
    if (immutable) {
        uint32_t key = 0;
        meta.immutable_value.resize(info.value_size);
        if (bpf_map_lookup_elem(map_fd, &key, meta.immutable_value.data()))
            fail("read immutable data map " + meta.name + ": " + std::strerror(errno));
    }
    return meta;
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
            info.btf_id,
            info.btf_value_type_id,
        });
    }
    closedir(fd_dir);
    return matches;
}

using internal::bpf_obj_name_truncation;

bool find_open_process_map_by_name(const std::string &name,
                                   const std::vector<NativeMapRule> &map_rules,
                                   MapMeta &out)
{
    const std::string truncated = bpf_obj_name_truncation(name);
    std::vector<MapMeta> matches =
        collect_open_process_maps([&](const bpf_map_info &, const std::string &map_name) {
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
        collect_open_process_maps([&](const bpf_map_info &info,
                                      const std::string &map_name) {
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

using internal::read_text_file_limited;

using internal::format_command_limited;

/* Path to the native-link binary. The runner starts it as a child process.
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
    struct MapOps {
        std::string name;
        uint64_t update = 0;
        uint64_t remove = 0;
    };
    std::vector<NameAddr> helpers;
    std::vector<NameAddr> maps;
    std::vector<LookupSite> lookup_sites;
    std::vector<LookupMap> lookup_maps;
    std::vector<MapOps> map_ops;
};

struct LinkedBlob {
    std::vector<uint8_t> blob;
    std::vector<uint8_t> relocs;
    uint64_t cache_lookup_ns = 0;
    uint64_t native_link_exec_ns = 0;
    uint64_t native_link_read_ns = 0;
    uint64_t map_patch_ns = 0;
    uint32_t callee_saved_mask = 0;
    std::vector<native_lab_load_site> load_sites;
    std::vector<uint32_t> relocated_map_ids;
};
/* A proof that calls any kernel helper or kfunc needs the kernel catalogue;
 * a local BPF-to-BPF call stays inside the program. An empty proof keeps the
 * catalogue, since its calls cannot be classified. */
bool proof_needs_kernel_symbols(const std::vector<bpf_insn> &proof)
{
    return proof.empty() || std::any_of(proof.begin(), proof.end(),
        [](const bpf_insn &insn) {
            return insn.code == (BPF_JMP | BPF_CALL) &&
                insn.src_reg != BPF_PSEUDO_CALL;
        });
}

struct CompanionLoad {
    uint64_t map_ptr_extract_ns = 0;
    uint64_t lookup_spec_ns = 0;
    uint64_t source_bytecode_bytes = 0;
    bool has_tail_call = false;
    bool needs_kernel_symbols = false;
    std::unordered_map<std::string, uint64_t> map_addrs;
    std::unordered_map<std::string, uint32_t> map_addr_ids;
    std::unordered_set<std::string> native_data_symbols;
    std::map<std::string, std::string> immutable_globals;
    std::unordered_map<std::string, std::string> native_map_symbols;
    std::unordered_map<std::string, MapMeta> exact_map_addrs;
    std::unordered_set<std::string> ambiguous_exact_maps;
    uint32_t prog_type = 0;
    std::optional<std::vector<std::pair<std::string, uint64_t>>> context_helpers;
    std::vector<std::pair<std::string, uint64_t>> kernel_functions;
    std::vector<MapMeta> maps;
    std::unordered_map<int, MapMeta> source_maps_by_fd;
    std::vector<NativeMapRule> map_rules;
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
    std::unordered_map<uint32_t, NativeLinkArgs::MapOps> map_ops;
};

void add_hash_map_ops(CompanionLoad &load, const MapMeta &meta, int map_fd)
{
    if (meta.type != BPF_MAP_TYPE_HASH && meta.type != BPF_MAP_TYPE_PERCPU_HASH &&
        meta.type != BPF_MAP_TYPE_LRU_HASH && meta.type != BPF_MAP_TYPE_LRU_PERCPU_HASH)
        return;
    auto [entry, inserted] = load.map_ops.try_emplace(meta.kernel_id);
    if (!inserted) return;
    const std::string root = kNativeLabTarget.debugfs_dir;
    entry->second.update = lookup_native_lab_ptr_by_fd(map_fd,
        (root + "/map_update_elem").c_str(), "map_update_elem");
    entry->second.remove = lookup_native_lab_ptr_by_fd(map_fd,
        (root + "/map_delete_elem").c_str(), "map_delete_elem");
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
    return rule.native_symbol == symbol &&
           native_map_rule_matches(rule, map_name) &&
           map_info_matches_shape(info, rule.shape);
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
        collect_open_process_maps([&](const bpf_map_info &info,
                                      const std::string &map_name) {
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

using internal::native_data_section_supported;

using internal::bpf_obj_name_truncation;

void add_native_map_symbol_alias(CompanionLoad &load, const std::string &name)
{
    if (load.map_addrs.count(name)) {
        return;
    }

    if (const MapMeta *exact = find_exact_map_meta(load, name)) {
        add_map_symbol_alias_meta(load, name, *exact);
        return;
    }

    MapMeta manifest_symbol_map{};
    if (find_loaded_manifest_native_symbol_map(load, name, manifest_symbol_map)) {
        add_map_symbol_alias_meta(load, name, manifest_symbol_map);
        return;
    }
    if (find_open_process_manifest_native_symbol_map(load, name,
                                                     manifest_symbol_map)) {
        add_map_meta(load, manifest_symbol_map);
        add_map_symbol_alias_meta(load, name, manifest_symbol_map);
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
        add_map_symbol_alias_meta(load, name, *match);
        return;
    }

    MapMeta process_map{};
    if (find_open_process_map_by_name(name, load.map_rules, process_map)) {
        add_map_meta(load, process_map);
        add_map_symbol_alias_meta(load, name, process_map);
    }
}

const MapMeta *find_map_meta_by_native_symbol(const CompanionLoad &load,
                                             const std::string &symbol)
{
    const auto id = load.map_addr_ids.find(symbol);
    if (id == load.map_addr_ids.end()) return nullptr;
    for (const MapMeta &meta : load.maps) {
        if (meta.kernel_id == id->second) return &meta;
    }
    return nullptr;
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
    if (t == BPF_MAP_TYPE_LPM_TRIE) {
        // This is lpm_trie_map_ops.map_lookup_elem on the sole kernel,
        // selected once from the loaded map type, as in the BPF verifier.
        site.kind = CompanionLoad::LookupSite::Kind::Call;
        site.target_addr = kallsyms_lookup("trie_lookup_elem");
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

std::vector<std::pair<std::string, uint64_t>> native_kernel_function_targets(
    const std::filesystem::path &native_object, const btf *local, const btf *kernel)
{
    if (elf_version(EV_CURRENT) == EV_NONE) fail("initialize kernel-function ELF reader");
    auto bytes = read_binary_file(native_object);
    std::unique_ptr<Elf, decltype(&elf_end)> elf(
        elf_memory(reinterpret_cast<char *>(bytes.data()), bytes.size()), elf_end);
    if (!elf) fail("read native kernel-function symbols: " + native_object.string());
    const auto kernel_declarations = native_kfunc_declarations(local);
    std::unordered_map<std::string, bool> undefined;
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf.get(), section))) {
        GElf_Shdr header{};
        if (!gelf_getshdr(section, &header)) fail("read native function symbol table header");
        if (header.sh_type != SHT_SYMTAB && header.sh_type != SHT_DYNSYM) continue;
        Elf_Data *data = elf_getdata(section, nullptr);
        if (!data || !header.sh_entsize) fail("empty native function symbol table");
        for (size_t i = 0; i < header.sh_size / header.sh_entsize; ++i) {
            GElf_Sym symbol{};
            if (!gelf_getsym(data, i, &symbol)) fail("read native function symbol");
            if (symbol.st_shndx != SHN_UNDEF) continue;
            const char *name = elf_strptr(elf.get(), header.sh_link, symbol.st_name);
            if (!name) fail("read native function name");
            const int id = btf__find_by_name_kind(local, name, BTF_KIND_FUNC);
            if (id <= 0 || !kernel_declarations.contains(id)) continue;
            undefined.emplace(name, GELF_ST_BIND(symbol.st_info) == STB_WEAK);
        }
    }
    std::vector<std::pair<std::string, uint64_t>> bindings;
    std::unordered_set<std::string> present;
    for (const auto &[name, weak] : undefined) {
        const auto id = native_kfunc_type_id(local, kernel, name, weak);
        bindings.emplace_back(name, 0);
        if (id) present.insert(name);
    }
    std::sort(bindings.begin(), bindings.end());
    if (present.empty()) return bindings;
    std::ifstream symbols("/proc/kallsyms");
    if (!symbols) fail("open /proc/kallsyms for BTF kernel functions");
    std::unordered_map<std::string, uint64_t> addresses;
    std::string line;
    while (std::getline(symbols, line)) {
        std::istringstream fields(line);
        uint64_t address;
        char type;
        std::string name;
        if (!(fields >> std::hex >> address >> type >> name)) fail("parse kernel-function kallsyms");
        // Match the stock verifier's first-name kallsyms_lookup_name lookup.
        if (present.contains(name)) addresses.emplace(name, address);
    }
    if (!symbols.eof()) fail("read kernel-function kallsyms");
    for (auto &[name, address] : bindings) {
        if (!present.contains(name)) continue;
        const auto found = addresses.find(name);
        if (found == addresses.end() || !found->second)
            fail("BTF kernel function has no readable kernel address: " + name);
        address = found->second;
    }
    std::sort(bindings.begin(), bindings.end());
    return bindings;
}

void add_native_data_symbol_addrs(const std::filesystem::path &native_object,
                                  CompanionLoad &load,
                                  const std::unordered_set<std::string> *entry_symbols = nullptr)
{
    std::unordered_map<uint32_t, std::unique_ptr<btf, decltype(&btf__free)>> data_types;
    ScopedFd descriptor(open(native_object.c_str(), O_RDONLY | O_CLOEXEC));
    const int fd = descriptor.get();
    if (fd < 0) {
        fail("open native object " + native_object.string() + ": " + std::strerror(errno));
    }
    if (elf_version(EV_CURRENT) == EV_NONE) {
        fail("libelf initialization failed");
    }
    std::unique_ptr<Elf, decltype(&elf_end)> handle(elf_begin(fd, ELF_C_READ, nullptr), elf_end);
    Elf *elf = handle.get();
    if (!elf) {
        fail("elf_begin " + native_object.string() + ": " + elf_errmsg(-1));
    }
    size_t shstrndx = 0;
    if (elf_getshdrstrndx(elf, &shstrndx) != 0) {
        fail("elf_getshdrstrndx " + native_object.string() + ": " + elf_errmsg(-1));
    }

    Elf_Scn *scn = nullptr;
    while ((scn = elf_nextscn(elf, scn)) != nullptr) {
        GElf_Shdr shdr = {};
        if (!gelf_getshdr(scn, &shdr)) {
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
                fail("gelf_getsym " + native_object.string() + ": " + elf_errmsg(-1));
            }
            const char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);
            // The canonical entry extraction already follows native calls and
            // data relocations. Other entries' globals need no map capability.
            if (entry_symbols && (!name || !entry_symbols->contains(name))) continue;
            if (sym.st_shndx == SHN_UNDEF && GELF_ST_TYPE(sym.st_info) != STT_FUNC) {
                if (name && name[0]) {
                    load.needs_kernel_symbols = true;
                    load.native_data_symbols.insert(name);
                }
            }
            if (GELF_ST_TYPE(sym.st_info) != STT_OBJECT ||
                sym.st_size == 0 ||
                sym.st_shndx == SHN_UNDEF ||
                sym.st_shndx >= SHN_LORESERVE) {
                continue;
            }
            if (!name || !name[0]) {
                continue;
            }
            Elf_Scn *target_scn = elf_getscn(elf, sym.st_shndx);
            if (!target_scn) {
                continue;
            }
            GElf_Shdr target_shdr = {};
            if (!gelf_getshdr(target_scn, &target_shdr)) {
                fail("gelf_getshdr target " + native_object.string() + ": " + elf_errmsg(-1));
            }
            const char *section = elf_strptr(elf, shstrndx, target_shdr.sh_name);
            if (!section) {
                continue;
            }
            if (std::strcmp(section, ".maps") == 0) {
                add_native_map_symbol_alias(load, name);
                load.native_data_symbols.insert(name);
                continue;
            }
            if (!native_data_section_supported(section)) {
                continue;
            }
            const MapMeta *map = find_array_data_map(load, section, 0);
            if (!map) {
                continue;
            }
            // Private readonly constants are the native linker's own core
            // readonly storage; compiler string pools carry section offsets
            // rather than source BTF VARs, so both bind by section offset.
            const bool local_readonly =
                ELF64_ST_BIND(sym.st_info) == STB_LOCAL &&
                std::string_view(section).rfind(".rodata", 0) == 0;
            const bool string_pool = (target_shdr.sh_flags & SHF_STRINGS) != 0;
            const uint64_t native_off = sym.st_value - target_shdr.sh_addr;
            std::optional<uint64_t> resolved = string_pool
                ? std::optional<uint64_t>(native_off)
                : std::nullopt;
            if (!string_pool) {
                auto types = data_types.find(map->btf_id);
                if (types == data_types.end()) {
                    if (!map->btf_id) fail("BPF data map " + map->name + " lacks BTF");
                    std::unique_ptr<btf, decltype(&btf__free)> loaded(
                        btf__load_from_kernel_by_id(map->btf_id), btf__free);
                    const long error = libbpf_get_error(loaded.get());
                    if (error || !loaded)
                        fail("load BPF data map BTF: " + libbpf_error_string(error ? error : -errno));
                    types = data_types.emplace(map->btf_id, std::move(loaded)).first;
                }
                resolved = native_data_symbol_offset(types->second.get(),
                    map->btf_value_type_id, section, name, native_off, local_readonly);
            }
            if (!resolved) {
                continue;
            }
            const uint64_t off = *resolved;
            // A symbol that ends past the app's map value cannot be placed,
            // but it is not an error: a native object built from a newer
            // source can carry strings the loaded app never references.
            // Tracee is the case in point: .rodata.str1.1 is 261 bytes where
            // the app's map is 246, the extra bytes being "vdso" at 248 and
            // "unknown" at 253. The app's own bytecode decides which it uses.
            if (off >= map->value_size || sym.st_size > map->value_size - off) {
                continue;
            }
            if (map->value_addr == 0) {
                fail("native data map " + map->name +
                     " has no direct value address for symbol " + std::string(name));
            }
            load.map_addrs[std::string(name)] =
                map->value_addr + off;
            load.map_addr_ids[std::string(name)] = map->kernel_id;
            load.native_data_symbols.insert(name);
            if (!map->immutable_value.empty() &&
                (sym.st_size == 1 || sym.st_size == 2 || sym.st_size == 4 || sym.st_size == 8)) {
                constexpr char hex[] = "0123456789abcdef";
                std::string value;
                for (size_t i = off; i < off + sym.st_size; ++i) {
                    const auto byte = map->immutable_value[i];
                    value += hex[byte >> 4]; value += hex[byte & 15];
                }
                load.immutable_globals[name] = std::move(value);
            }
        }
    }
    add_known_kconfig_symbol_addrs(load);
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

#include "native_loader_bytecode.hpp"
#include "native_loader_source_maps.hpp"

CompanionLoad load_from_loaded_program_fd(int program_fd,
                                          const bpf_prog_info &prog_info,
                                          const bpf_insn *source_insns,
                                          size_t source_insn_cnt,
                                          std::vector<NativeMapRule> map_rules)
{
    CompanionLoad out{};
    out.prog_type = prog_info.type;
    out.context_helpers = query_program_helper_targets(program_fd, prog_info.type);
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
        add_hash_map_ops(out, meta, map_fd);
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
        xlated_bytes = load_xlated_program(program_fd, prog_info.xlated_prog_len, true);
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
    out.needs_kernel_symbols |= !source_calls.empty();

    BpfArrayOffsets array_offsets{
        K_BPF_ARRAY_VALUE_OFFSET,
        K_BPF_ARRAY_PPTRS_OFFSET,
    };
    BpfHtabOffsets htab_offsets{
        K_HTAB_ELEM_KEY_OFFSET,
        K_HTAB_ELEM_LRU_REF_OFFSET,
    };
#if defined(__x86_64__)
    const bool has_percpu_map = std::any_of(out.maps.begin(), out.maps.end(),
        [](const MapMeta &map) {
            return map.type == BPF_MAP_TYPE_PERCPU_ARRAY ||
                   map.type == BPF_MAP_TYPE_PERCPU_HASH ||
                   map.type == BPF_MAP_TYPE_LRU_PERCPU_HASH;
        });
    out.needs_kernel_symbols |= has_percpu_map;
    uint64_t this_cpu_off_addr = has_percpu_map
        ? kallsyms_lookup("this_cpu_off") : 0;
#else
    uint64_t this_cpu_off_addr = 0;
#endif

    for (const SourceHelperCall &call : source_calls) {
        if (call.helper_id == BPF_FUNC_tail_call) {
            out.has_tail_call = true;
            continue;
        }
        auto map_it = (call.map_fd >= 0) ? meta_by_source_fd.find(call.map_fd) : meta_by_source_fd.end();
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
        } else if (call.helper_id == BPF_FUNC_map_update_elem ||
                   call.helper_id == BPF_FUNC_map_delete_elem) {
            if (map_it != meta_by_source_fd.end()) {
                auto &ops = out.map_ops[map_it->second.kernel_id];
                const bool update = call.helper_id == BPF_FUNC_map_update_elem;
                auto &target = update ? ops.update : ops.remove;
                if (!target) {
                    const std::string path = std::string(kNativeLabTarget.debugfs_dir) +
                        (update ? "/map_update_elem" : "/map_delete_elem");
                    target = lookup_native_lab_ptr_by_fd(call.map_fd, path.c_str(),
                        update ? "map_update_elem" : "map_delete_elem");
                }
            }
        }
    }
    const auto lookup_spec_end = std::chrono::steady_clock::now();
    out.lookup_spec_ns = elapsed_ns(lookup_spec_start, lookup_spec_end);
    out.source_maps_by_fd = std::move(meta_by_source_fd);

    return out;
}

#include "native_loader_trusted_link_schema.hpp"
#include "native_loader_trusted_link_plan.hpp"

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
#if defined(__x86_64__)
    hash.add_string("kernel_layout");
    hash.add_string(native_kernel_lto_layout());
#endif
    hash.add_string(symbol_name);
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
    for (const auto &arg : link_args.map_ops) {
        hash.add_string("map_ops");
        hash.add_string(arg.name);
        hash.add_u64(arg.update);
        hash.add_u64(arg.remove);
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

using internal::publish_cache_file;

#include "native_loader_entry_data.hpp"
#include "native_loader_context_lto.hpp"
#include "native_loader_function_bodies.hpp"

LinkerOutput invoke_native_link(const std::filesystem::path &elf_path,
                                const std::string &symbol_name,
                                const NativeLinkArgs &link_args,
                                const std::filesystem::path &base,
                                const std::filesystem::path &trusted_proof,
                                const std::filesystem::path &entry_proof)
{
    LinkerOutput out{};
    out.proof = base.string() + ".proof.o";
    out.blob = base.string() + ".blob.bin";
    out.relocs = base.string() + ".relocs.bin";
    out.map_patches = base.string() + ".map-patches.tsv";
    out.abi = base.string() + ".abi.tsv";

    const auto &prepared = trusted_proof.empty() ? entry_proof : trusted_proof;
    if (!prepared.empty()) {
        std::filesystem::copy_file(prepared, out.proof,
                                  std::filesystem::copy_options::overwrite_existing);
    } else {
        write_native_entry_proof(link_args.linker, elf_path, symbol_name, out.proof,
                                base.string() + ".proof.stderr.txt");
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
    int rc = native_loader_detail::run_subprocess(argv, kernel_stderr);
    const int kernel_errno = errno;
    if (rc != 0) {
        std::ostringstream msg;
        const std::string stderr_text = read_text_file_limited(kernel_stderr, 8192);
        msg << "native-link kernel failed (rc=" << rc << ")";
        if (rc < 0) msg << ": " << std::strerror(kernel_errno);
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

void bind_native_map_relocations(LinkedBlob &linked,
    const std::vector<MapPatchSite> &patches, const CompanionLoad &companion)
{
    for (const auto &site : patches) {
        const auto identity = companion.map_addr_ids.find(site.name);
        const auto address = companion.map_addrs.find(site.name);
        if (identity == companion.map_addr_ids.end() || address == companion.map_addrs.end())
            fail("native map relocation lacks original map identity: " + site.name);
        const auto map = std::find_if(companion.maps.begin(), companion.maps.end(),
            [&](const MapMeta &m) { return m.kernel_id == identity->second; });
        if (map == companion.maps.end())
            fail("native map relocation has no original map layout: " + site.name);
        uint32_t kind = NATIVE_LAB_RELOC_MAP_POINTER;
        uint64_t offset = 0;
        if (address->second != map->kernel_addr) {
            kind = NATIVE_LAB_RELOC_MAP_VALUE;
            if (!map->value_addr || address->second < map->value_addr ||
                address->second - map->value_addr >= map->value_size)
                fail("native map relocation exceeds original value: " + site.name);
            offset = address->second - map->value_addr;
        }
        if (site.offset > std::numeric_limits<uint32_t>::max())
            fail("native map relocation offset exceeds wire format");
        if (site.offset > linked.blob.size() || sizeof(uint64_t) > linked.blob.size() - site.offset)
            fail("native map literal exceeds linked bytes: " + site.name);
        std::fill_n(linked.blob.begin() + site.offset, sizeof(uint64_t), 0);
        append_u32_le(linked.relocs, static_cast<uint32_t>(site.offset));
        append_u32_le(linked.relocs, kind);
        append_u64_le(linked.relocs, identity->second | (offset << 32));
    }
}

LinkedBlob load_or_link_native_blob(const std::filesystem::path &native_link_path,
                                    const std::filesystem::path &elf_path,
                                    const std::string &symbol_name,
                                    const CompanionLoad &companion,
                                    const std::filesystem::path &trusted_proof = {},
                                    const std::filesystem::path &entry_proof = {})
{
    const auto cache_lookup_start = std::chrono::steady_clock::now();
    NativeLinkArgs link_args =
        build_native_link_args(native_link_path, companion.map_addrs, companion);
    const std::filesystem::path cache_dir = trusted_proof.empty()
        ? std::filesystem::path(kNativeLinkCacheDir)
        : trusted_proof.parent_path() / "kernel-link";
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
        LinkerOutput tmp = invoke_native_link(elf_path, symbol_name, link_args, tmp_base, trusted_proof, entry_proof);
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
        linked.callee_saved_mask = read_link_abi_file(source.abi, &linked.load_sites);
        const auto read_end = std::chrono::steady_clock::now();
        publish_cache_file(tmp.proof, cache.proof);
        publish_cache_file(tmp.blob, cache.blob);
        publish_cache_file(tmp.relocs, cache.relocs);
        publish_cache_file(tmp.map_patches, cache.map_patches);
        publish_cache_file(tmp.abi, cache.abi);
        const auto patch_start = std::chrono::steady_clock::now();
        if (trusted_proof.empty()) patch_map_literals(linked.blob, map_patches, companion.map_addrs);
        else bind_native_map_relocations(linked, map_patches, companion);
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
    linked.callee_saved_mask = read_link_abi_file(source.abi, &linked.load_sites);
    const auto read_end = std::chrono::steady_clock::now();
    const auto patch_start = std::chrono::steady_clock::now();
    if (trusted_proof.empty()) patch_map_literals(linked.blob, map_patches, companion.map_addrs);
    else bind_native_map_relocations(linked, map_patches, companion);
    const auto patch_end = std::chrono::steady_clock::now();
    linked.native_link_read_ns = elapsed_ns(read_start, read_end);
    linked.map_patch_ns = elapsed_ns(patch_start, patch_end);
    return linked;
}

using internal::reopen_relocated_map_fds;

native_loader::LoadedProgram submit_trusted_native(
    const native_loader::FdLoadOptions &options, const bpf_prog_info &info,
    const std::filesystem::path &native_path, const std::string &entry,
    const CompanionLoad &companion)
{
    auto native = read_binary_file(native_path);
    if (native.size() > UINT32_MAX || entry.empty() || entry.size() > UINT32_MAX)
        fail("trusted native submission extent exceeds request ABI");
    std::ostringstream metadata;
    metadata << "{\"version\":1,\"load_context\":{\"prog_type\":" << info.type
        << ",\"expected_attach_type\":" << options.expected_attach_type
        << ",\"prog_flags\":0,\"attach_btf_id\":" << (options.attach_btf_id ? options.attach_btf_id : info.attach_btf_id)
        << ",\"attach_btf_obj_id\":" << (options.attach_btf_obj_id ? options.attach_btf_obj_id : info.attach_btf_obj_id)
        << ",\"attach_prog_id\":" << options.attach_prog_id
        << ",\"prog_ifindex\":" << info.ifindex
        << ",\"gpl_compatible\":" << info.gpl_compatible
        << ",\"source_btf_id\":" << info.btf_id
        << ",\"token_present\":0},\"kernel_kfunc_context\":"
        << (companion.kernel_functions.empty() ? "false" : "true") << ",\"maps\":[";
    std::vector<std::unique_ptr<ScopedFd>> retained_maps;
    std::vector<int32_t> map_fds;
    std::unordered_set<uint32_t> retained_ids;
    bool first = true;
    for (const auto &name : companion.native_data_symbols) {
        const auto identity = companion.map_addr_ids.find(name);
        if (identity == companion.map_addr_ids.end()) continue;
        const auto selected = std::find_if(companion.maps.begin(), companion.maps.end(),
            [&](const MapMeta &map) { return map.kernel_id == identity->second; });
        if (selected == companion.maps.end()) fail("native symbol lacks its source map object: " + name);
        const auto &map = *selected;
        auto retained = std::make_unique<ScopedFd>(bpf_map_get_fd_by_id(map.kernel_id));
        if (retained->get() < 0)
            fail("reopen native submission map identity: " + std::string(std::strerror(errno)));
        const auto actual = load_map_info(retained->get());
        if (retained_ids.insert(actual.id).second) {
            map_fds.push_back(retained->get());
            retained_maps.push_back(std::move(retained));
        }
        if (!first) metadata << ',';
        first = false;
        metadata << "{\"name\":"; write_json_string(metadata, name);
        metadata << ",\"map_id\":" << actual.id << ",\"map_type\":" << actual.type
            << ",\"key_size\":" << actual.key_size << ",\"value_size\":" << actual.value_size
            << ",\"max_entries\":" << actual.max_entries << ",\"map_flags\":" << actual.map_flags
            << ",\"value_offset\":";
        const auto address = companion.map_addrs.at(name);
        if (address == map.kernel_addr) metadata << "null";
        else {
            if (!map.value_addr || address < map.value_addr || address - map.value_addr >= map.value_size)
                fail("trusted native direct map value exceeds its object: " + name);
            metadata << address - map.value_addr;
        }
        metadata << '}';
    }
    metadata << "]}";
    const std::string serialized = metadata.str();
    if (serialized.size() > UINT32_MAX || map_fds.size() > UINT32_MAX)
        fail("trusted native metadata exceeds request ABI");
    const std::string endpoint = std::string(kNativeLabTarget.debugfs_dir) + "/native_submit";
    ScopedFd submit(open(endpoint.c_str(), O_RDWR | O_CLOEXEC));
    if (submit.get() < 0) fail("open kernel native submission: " + std::string(std::strerror(errno)));
    native_lab_trusted_submission submission{};
    auto &request = submission.request;
    request.version = NATIVE_LAB_TRUSTED_VERSION;
#if defined(__aarch64__)
    request.arch = NATIVE_LAB_ARCH_ARM64;
#else
    request.arch = NATIVE_LAB_ARCH_X86;
#endif
    request.source_prog_id = info.id;
    request.native_size = native.size();
    request.entry_size = entry.size();
    request.metadata_size = serialized.size();
    request.native_user = ptr_to_u64(native.data());
    request.entry_user = ptr_to_u64(entry.data());
    request.metadata_user = ptr_to_u64(serialized.data());
    submission.map_count = map_fds.size();
    submission.map_fds_user = ptr_to_u64(map_fds.data());
    if (ioctl(submit.get(), NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &submission))
        fail("kernel native submission refused: " + std::string(std::strerror(errno)));
    native_lab_trusted_result result{};
    int status;
    do { status = ioctl(submit.get(), NATIVE_LAB_TRUSTED_WAIT, &result); }
    while (status < 0 && errno == EINTR);
    if (status < 0) fail("wait for trusted specializer: " + std::string(std::strerror(errno)));
    if (result.request_id != request.request_id)
        fail("kernel trusted specializer returned an invalid completion");
    if (result.status)
        fail("trusted specializer refused native program: " + std::string(std::strerror(-result.status)));
    native_loader::LoadedProgram out{};
    out.prog_fd = bpf_prog_get_fd_by_id(result.prog_id);
    if (out.prog_fd < 0) fail("open kernel-owned trusted native result: " + std::string(std::strerror(errno)));
    out.replaced = true;
    out.original_prog_id = info.id;
    out.native_prog_id = result.prog_id;
    out.bpf_bytecode_bytes = companion.source_bytecode_bytes;
    return out;
}

inline uint32_t trusted_map_relocation_offset(std::optional<uint32_t> base,
    uint64_t encoded, int64_t explicit_addend, bool rela, uint32_t value_size)
{
    const int64_t relative = rela ? explicit_addend : std::bit_cast<int64_t>(encoded);
    const __int128 offset = static_cast<__int128>(base.value_or(0)) + relative;
    if ((!base && relative) || offset < 0 || offset > UINT32_MAX ||
        (base && offset >= value_size))
        throw std::runtime_error("trusted proof map addend exceeds original object/value");
    return static_cast<uint32_t>(offset);
}

std::unique_ptr<btf, decltype(&btf__free)> source_proof_btf(Elf *elf)
{
    size_t names = 0;
    if (elf_getshdrstrndx(elf, &names)) fail("read source proof BTF section names");
    std::unique_ptr<btf, decltype(&btf__free)> result(nullptr, btf__free);
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf, section))) {
        GElf_Shdr header{};
        if (!gelf_getshdr(section, &header)) fail("read source proof BTF section");
        const char *name = elf_strptr(elf, names, header.sh_name);
        if (!name || std::strcmp(name, ".BTF")) continue;
        Elf_Data *data = elf_getdata(section, nullptr);
        if (result || header.sh_type != SHT_PROGBITS || !data || data->d_off ||
            !data->d_buf || data->d_size != header.sh_size || data->d_size > UINT32_MAX)
            fail("invalid source proof BTF extent");
        btf *raw = btf__new(data->d_buf, static_cast<uint32_t>(data->d_size));
        if (libbpf_get_error(raw) || !raw) fail("parse original source proof BTF");
        result.reset(raw);
    }
    if (!result) fail("source proof BTF section absent");
    return result;
}

// Use the pinned libbpf prototype matcher for proof-side vmlinux kfuncs.
// Module calls retain their FD-array binding through the ordinary object path.
void relocate_vmlinux_proof_call(const btf *local, const btf *kernel,
    const char *name, const GElf_Sym &symbol, int64_t addend, bpf_insn &insn)
{
    if (!name || symbol.st_shndx != SHN_UNDEF ||
        (GELF_ST_BIND(symbol.st_info) != STB_GLOBAL && GELF_ST_BIND(symbol.st_info) != STB_WEAK) || addend ||
        insn.code != (BPF_JMP | BPF_CALL) || insn.dst_reg ||
        insn.src_reg != BPF_PSEUDO_CALL || insn.off || insn.imm != -1)
        fail("invalid source proof kfunc call relocation");
    const auto kernel_id = native_kfunc_type_id(local, kernel, name,
        GELF_ST_BIND(symbol.st_info) == STB_WEAK);
    // As with libbpf unresolved weak calls, only an eliminated call is safe.
    insn.src_reg = kernel_id ? BPF_PSEUDO_KFUNC_CALL : 0;
    insn.imm = kernel_id ? static_cast<int32_t>(kernel_id) : -1;
}

void relocate_vmlinux_proof_function_address(const btf *local, const btf *kernel,
    const char *name, const GElf_Sym &symbol, int64_t addend,
    bpf_insn &low, bpf_insn &high)
{
    if (!name || symbol.st_shndx != SHN_UNDEF ||
        (GELF_ST_BIND(symbol.st_info) != STB_GLOBAL && GELF_ST_BIND(symbol.st_info) != STB_WEAK) || addend ||
        low.code != (BPF_LD | BPF_DW | BPF_IMM) || low.src_reg || low.off || low.imm ||
        high.code || high.dst_reg || high.src_reg || high.off || high.imm)
        fail("invalid source proof kfunc address relocation");
    const auto id = native_kfunc_type_id(local, kernel, name,
        GELF_ST_BIND(symbol.st_info) == STB_WEAK);
    low.src_reg = id ? BPF_PSEUDO_BTF_ID : 0;
    low.imm = id;
    high.imm = 0; // vmlinux BTF, as opposed to a module BTF FD.
}

/* A proof that calls a BPF-to-BPF subprogram carries one executable section
 * per subprogram (the emitter gives each function its own section), so the
 * kernel needs their bytes appended after the entry and one func_info record
 * per subprogram. Both are built here, where the ELF is already open. */
struct ProofSubprogram {
    uint32_t start;
    uint32_t type_id;
};
void relocate_trusted_proof(bpf_object *object, const std::filesystem::path &path,
    const std::string &entry, const CompanionLoad &companion,
    std::vector<bpf_insn> &proof, std::vector<std::unique_ptr<ScopedFd>> &pins,
    const std::vector<native_loader::TrustedMapBinding> &trusted,
    std::vector<ProofSubprogram> &subprograms, ScopedFd &proof_btf)
{
    auto bytes = read_binary_file(path);
    std::unique_ptr<Elf, decltype(&elf_end)> elf(
        elf_memory(reinterpret_cast<char *>(bytes.data()), bytes.size()), elf_end);
    GElf_Ehdr header{};
    if (!elf || !gelf_getehdr(elf.get(), &header) || header.e_machine != EM_BPF ||
        header.e_type != ET_REL || header.e_ident[EI_DATA] != ELFDATA2LSB)
        fail("proof source maps require a little-endian relocatable BPF ELF");
    struct ProofFunction {
        std::string name;
        size_t section;
        uint64_t address, size;
    };
    std::vector<ProofFunction> functions;
    std::optional<GElf_Sym> selected;
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf.get(), section))) {
        GElf_Shdr table{};
        if (!gelf_getshdr(section, &table)) fail("read source proof symbol table");
        if (table.sh_type != SHT_SYMTAB) continue;
        Elf_Data *data = elf_getdata(section, nullptr);
        if (!data || !table.sh_entsize) fail("empty source proof symbol table");
        for (size_t i = 0; i < table.sh_size / table.sh_entsize; i++) {
            GElf_Sym symbol{};
            if (!gelf_getsym(data, i, &symbol)) fail("read source proof symbol");
            const char *name = elf_strptr(elf.get(), table.sh_link, symbol.st_name);
            if (!name) fail("read source proof symbol name");
            if (GELF_ST_TYPE(symbol.st_info) == STT_FUNC && symbol.st_size &&
                symbol.st_shndx != SHN_UNDEF && symbol.st_shndx < SHN_LORESERVE)
                functions.push_back({name, symbol.st_shndx, symbol.st_value, symbol.st_size});
            if (entry != name) continue;
            if (selected || GELF_ST_TYPE(symbol.st_info) != STT_FUNC || !symbol.st_size ||
                symbol.st_shndx == SHN_UNDEF || symbol.st_shndx >= SHN_LORESERVE)
                fail("ambiguous/invalid source proof entry: " + entry);
            selected = symbol;
        }
    }
    if (!selected) fail("source proof entry absent: " + entry);
    GElf_Shdr code{};
    Elf_Scn *code_section = elf_getscn(elf.get(), selected->st_shndx);
    if (!code_section || !gelf_getshdr(code_section, &code) || !(code.sh_flags & SHF_EXECINSTR) ||
        selected->st_value < code.sh_addr || selected->st_size != proof.size() * sizeof(bpf_insn))
        fail("source proof entry extent differs from selected BPF program");
    const uint64_t begin = selected->st_value - code.sh_addr;
    Elf_Data *code_data = elf_getdata(code_section, nullptr);
    if (!code_data || code_data->d_off || begin > code_data->d_size ||
        selected->st_size > code_data->d_size - begin ||
        std::memcmp(proof.data(), static_cast<const char *>(code_data->d_buf) + begin, selected->st_size))
        fail("source proof entry bytes differ from selected BPF program");
    // One executable section per BPF-to-BPF subprogram: the entry section is
    // the selected program, every other one holds a function the entry calls.
    struct Placement {
        std::string name;
        size_t section;
        uint64_t address, skip, extent;
        uint32_t start, type_id;
    };
    std::vector<Placement> placed{{entry, static_cast<size_t>(selected->st_shndx), code.sh_addr,
        begin, selected->st_size, 0, 0}};
    section = nullptr;
    while ((section = elf_nextscn(elf.get(), section))) {
        GElf_Shdr table{};
        if (!gelf_getshdr(section, &table)) fail("read source proof section header");
        const size_t index = elf_ndxscn(section);
        if (!(table.sh_flags & SHF_EXECINSTR) || index == static_cast<size_t>(selected->st_shndx) ||
            !table.sh_size) continue;
        if (table.sh_size % sizeof(bpf_insn) ||
            proof.size() + table.sh_size / sizeof(bpf_insn) > (1u << 20))
            fail("source proof subprogram section is not whole instructions");
        const ProofFunction *function = nullptr;
        for (const auto &candidate : functions) {
            if (candidate.section != index) continue;
            if (function) fail("source proof subprogram section holds several functions");
            function = &candidate;
        }
        if (!function || function->address != table.sh_addr || function->size != table.sh_size)
            fail("source proof subprogram section is not one whole function");
        Elf_Data *data = elf_getdata(section, nullptr);
        if (!data || data->d_off || data->d_size != table.sh_size)
            fail("source proof subprogram bytes are not contiguous");
        placed.push_back({function->name, index, table.sh_addr, 0, table.sh_size,
            static_cast<uint32_t>(proof.size()), 0});
        const char *source = static_cast<const char *>(data->d_buf);
        for (size_t i = 0; i < table.sh_size; i += sizeof(bpf_insn)) {
            bpf_insn insn{};
            std::memcpy(&insn, source + i, sizeof(insn));
            proof.push_back(insn);
        }
    }
    std::set<uint64_t> patched;
    std::unique_ptr<btf, decltype(&btf__free)> kernel_btf(nullptr, btf__free);
    std::unique_ptr<btf, decltype(&btf__free)> declaration_btf(nullptr, btf__free);
    const auto kernel_types = [&]() -> const btf * {
        if (!kernel_btf) {
            btf *loaded = btf__load_vmlinux_btf();
            if (libbpf_get_error(loaded) || !loaded) fail("load proof kfunc vmlinux BTF");
            kernel_btf.reset(loaded);
        }
        return kernel_btf.get();
    };
    std::unordered_map<uint32_t, int> map_fds, readonly_fds;
    section = nullptr;
    while ((section = elf_nextscn(elf.get(), section))) {
        GElf_Shdr relocations{};
        if (!gelf_getshdr(section, &relocations)) fail("read source proof relocations");
        if (relocations.sh_type != SHT_REL && relocations.sh_type != SHT_RELA) continue;
        const auto placement = std::find_if(placed.begin(), placed.end(),
            [&](const auto &item) { return item.section == relocations.sh_info; });
        if (placement == placed.end()) continue;
        Elf_Data *data = elf_getdata(section, nullptr);
        Elf_Scn *symbols = elf_getscn(elf.get(), relocations.sh_link);
        GElf_Shdr symbol_table{};
        if (!data || !relocations.sh_entsize || !symbols || !gelf_getshdr(symbols, &symbol_table))
            fail("invalid source proof relocation table");
        Elf_Data *symbol_data = elf_getdata(symbols, nullptr);
        if (!symbol_data) fail("source proof relocation symbols absent");
        for (size_t i = 0; i < relocations.sh_size / relocations.sh_entsize; i++) {
            GElf_Rela relocation{};
            if (relocations.sh_type == SHT_RELA) {
                if (!gelf_getrela(data, i, &relocation)) fail("read source proof RELA");
            } else {
                GElf_Rel rel{};
                if (!gelf_getrel(data, i, &rel)) fail("read source proof REL");
                relocation.r_offset = rel.r_offset; relocation.r_info = rel.r_info;
            }
            if (relocation.r_offset < placement->skip ||
                relocation.r_offset - placement->skip >= placement->extent) continue;
            const uint64_t within = relocation.r_offset - placement->skip;
            if (within % sizeof(bpf_insn)) fail("invalid source proof relocation site");
            const uint64_t offset = (placement->start + within / sizeof(bpf_insn)) * sizeof(bpf_insn);
            if (!patched.insert(offset).second) fail("invalid source proof relocation site");
            GElf_Sym symbol{};
            if (!gelf_getsym(symbol_data, GELF_R_SYM(relocation.r_info), &symbol)) fail("read source proof relocation symbol");
            const char *name = elf_strptr(elf.get(), symbol_table.sh_link, symbol.st_name);
            if (GELF_R_TYPE(relocation.r_info) == R_BPF_64_32) {
                // A call into an appended subprogram: the ELF carries imm = -1
                // and relocation against the callee's section (the section
                // symbol for a static function), so the kernel needs the
                // relative displacement libbpf would compute.
                const auto callee = symbol.st_shndx != SHN_UNDEF
                    ? std::find_if(placed.begin(), placed.end(), [&](const auto &item) {
                        return item.section == static_cast<size_t>(symbol.st_shndx); })
                    : placed.end();
                if (callee != placed.end()) {
                    bpf_insn &call = proof[offset / sizeof(bpf_insn)];
                    if (symbol.st_value < callee->address ||
                        (symbol.st_value - callee->address) % sizeof(bpf_insn) ||
                        call.code != (BPF_JMP | BPF_CALL) || call.dst_reg ||
                        call.src_reg != BPF_PSEUDO_CALL || call.off)
                        fail("invalid source proof local call relocation");
                    const int64_t head = static_cast<int64_t>(callee->start) +
                        static_cast<int64_t>((symbol.st_value - callee->address) / sizeof(bpf_insn));
                    if (head + call.imm + 1 != static_cast<int64_t>(callee->start))
                        fail("source proof local call targets the middle of a subprogram");
                    call.imm = static_cast<int32_t>(callee->start) -
                        static_cast<int32_t>(offset / sizeof(bpf_insn)) - 1;
                    continue;
                }
                if (!declaration_btf) declaration_btf = source_proof_btf(elf.get());
                relocate_vmlinux_proof_call(declaration_btf.get(), kernel_types(), name,
                    symbol, relocation.r_addend, proof[offset / sizeof(bpf_insn)]);
                continue;
            }
            if (GELF_R_TYPE(relocation.r_info) != R_BPF_64_64 ||
                offset / sizeof(bpf_insn) + 1 >= proof.size())
                fail("invalid source proof map relocation site/type");
            if (symbol.st_shndx != SHN_UNDEF) {
                GElf_Shdr data_section{};
                Elf_Scn *data_scn = elf_getscn(elf.get(), symbol.st_shndx);
                if (!data_scn || !gelf_getshdr(data_scn, &data_section) ||
                    data_section.sh_type != SHT_PROGBITS ||
                    (data_section.sh_flags & (SHF_ALLOC | SHF_WRITE | SHF_EXECINSTR)) != SHF_ALLOC)
                    fail("defined source proof relocation is not readonly data");
                size_t names = 0;
                if (elf_getshdrstrndx(elf.get(), &names)) fail("read proof section names");
                const char *data_name = elf_strptr(elf.get(), names, data_section.sh_name);
                bpf_map *data_map = nullptr, *candidate;
                btf *types = bpf_object__btf(object);
                if (!types) fail("readonly source proof lacks BTF");
                bpf_object__for_each_map(candidate, object) {
                    const auto *type = btf__type_by_id(types, bpf_map__btf_value_type_id(candidate));
                    if (!type || btf_kind(type) != BTF_KIND_DATASEC) continue;
                    const char *map_section = btf__name_by_offset(types, type->name_off);
                    if (!data_name || !map_section || std::strcmp(data_name, map_section)) continue;
                    if (data_map) fail("ambiguous readonly proof section");
                    data_map = candidate;
                }
                if (!data_map || !bpf_map__is_internal(data_map) ||
                    !(bpf_map__map_flags(data_map) & BPF_F_RDONLY_PROG) ||
                    bpf_map__type(data_map) != BPF_MAP_TYPE_ARRAY ||
                    bpf_map__key_size(data_map) != sizeof(uint32_t) || bpf_map__max_entries(data_map) != 1)
                    fail("defined proof relocation lacks a readonly single-value map");
                if (!readonly_fds.contains(symbol.st_shndx)) {
                    size_t length = 0;
                    const void *initial = bpf_map__initial_value(data_map, &length);
                    if (!initial || length != data_section.sh_size || length != bpf_map__value_size(data_map))
                        fail("readonly proof map extent differs from ELF section");
                    if (btf__fd(types) < 0) {
                        const int err = btf__load_into_kernel(types);
                        if (err) fail("load readonly proof BTF: " + libbpf_error_string(err));
                    }
                    bpf_map_create_opts opts{}; opts.sz = sizeof(opts);
                    opts.map_flags = bpf_map__map_flags(data_map); opts.btf_fd = btf__fd(types);
                    opts.btf_key_type_id = bpf_map__btf_key_type_id(data_map);
                    opts.btf_value_type_id = bpf_map__btf_value_type_id(data_map);
                    auto fd = std::make_unique<ScopedFd>(bpf_map_create(BPF_MAP_TYPE_ARRAY,
                        bpf_map__name(data_map), sizeof(uint32_t), length, 1, &opts));
                    if (fd->get() < 0) fail("create readonly source proof map: " + std::string(std::strerror(errno)));
                    const uint32_t key = 0;
                    if (bpf_map_update_elem(fd->get(), &key, initial, BPF_ANY) || bpf_map_freeze(fd->get()))
                        fail("initialize readonly source proof map: " + std::string(std::strerror(errno)));
                    readonly_fds.emplace(symbol.st_shndx, fd->get()); pins.push_back(std::move(fd));
                }
                bpf_insn &low = proof[offset / sizeof(bpf_insn)], &high = proof[offset / sizeof(bpf_insn) + 1];
                if (low.code != (BPF_LD | BPF_DW | BPF_IMM) || low.src_reg || low.off ||
                    high.code || high.dst_reg || high.src_reg || high.off || relocation.r_addend < 0 ||
                    symbol.st_value < data_section.sh_addr)
                    fail("invalid readonly source proof load");
                const uint64_t immediate = static_cast<uint32_t>(low.imm) |
                    (static_cast<uint64_t>(static_cast<uint32_t>(high.imm)) << 32);
                const uint64_t symbol_offset = symbol.st_value - data_section.sh_addr;
                if (symbol_offset >= data_section.sh_size ||
                    static_cast<uint64_t>(relocation.r_addend) >= data_section.sh_size - symbol_offset ||
                    immediate >= data_section.sh_size - symbol_offset - relocation.r_addend)
                    fail("readonly source proof load exceeds ELF object");
                low.src_reg = BPF_PSEUDO_MAP_VALUE;
                low.imm = readonly_fds.at(symbol.st_shndx);
                high.imm = static_cast<int32_t>(symbol_offset + relocation.r_addend + immediate);
                continue;
            }
            const auto binding = std::find_if(trusted.begin(), trusted.end(),
                [&](const auto &item) { return name && item.native_symbol == name; });
            if (name && binding == trusted.end()) {
                if (!declaration_btf) declaration_btf = source_proof_btf(elf.get());
                const int function_id = btf__find_by_name_kind(declaration_btf.get(), name, BTF_KIND_FUNC);
                if (function_id > 0 && native_kfunc_declarations(declaration_btf.get()).contains(function_id)) {
                    relocate_vmlinux_proof_function_address(declaration_btf.get(), kernel_types(), name,
                        symbol, relocation.r_addend, proof[offset / sizeof(bpf_insn)],
                        proof[offset / sizeof(bpf_insn) + 1]);
                    continue;
                }
            }
            if (!name || GELF_ST_BIND(symbol.st_info) != STB_GLOBAL)
                fail("source map relocation is not a strong explicit extern");
            if (binding == trusted.end()) fail("unbound trusted proof extern: " + std::string(name));
            const uint32_t id = binding->map_id;
            const auto base = binding->value_offset;
            const bool value = base.has_value();
            const auto map = std::find_if(companion.maps.begin(), companion.maps.end(),
                [&](const MapMeta &meta) { return meta.kernel_id == id; });
            if (map == companion.maps.end()) fail("source proof map identity has no original layout");
            bpf_insn &low = proof[offset / sizeof(bpf_insn)], &high = proof[offset / sizeof(bpf_insn) + 1];
            if (low.code != (BPF_LD | BPF_DW | BPF_IMM) || low.src_reg || low.off ||
                high.code || high.dst_reg || high.src_reg || high.off)
                fail("source proof map relocation does not target a plain LDDW");
            const uint64_t immediate = static_cast<uint32_t>(low.imm) |
                (static_cast<uint64_t>(static_cast<uint32_t>(high.imm)) << 32);
            const uint32_t addend = trusted_map_relocation_offset(base, immediate,
                relocation.r_addend, relocations.sh_type == SHT_RELA, map->value_size);
            if (!map_fds.contains(id)) {
                auto fd = std::make_unique<ScopedFd>(bpf_map_get_fd_by_id(id));
                if (fd->get() < 0) fail("pin original source proof map: " + std::string(std::strerror(errno)));
                map_fds.emplace(id, fd->get()); pins.push_back(std::move(fd));
            }
            low.src_reg = value ? BPF_PSEUDO_MAP_VALUE : BPF_PSEUDO_MAP_FD;
            low.imm = map_fds.at(id);
            high.imm = static_cast<int32_t>(addend);
        }
    }
    // The kernel maps func_info[i] onto subprog_info[i], so a proof with
    // appended subprograms needs one record per subprogram, located by name in
    // the object's own BTF. Its BTF must then be the program's BTF.
    std::sort(placed.begin(), placed.end(), [](const auto &left, const auto &right) {
        return left.start < right.start; });
    // Its datasec fixup is what the kernel accepts: the raw .BTF section
    // still carries `linkage=GLOBAL_EXTERN` for extern VARs, which the kernel
    // rejects ("Linkage not supported").
    btf *loaded_btf = bpf_object__btf(object);
    if (!loaded_btf) fail("source proof object carries no BTF");
    for (auto &item : placed) {
        const int id = btf__find_by_name_kind(loaded_btf, item.name.c_str(), BTF_KIND_FUNC);
        if (id <= 0) fail("source proof subprogram lacks a BTF function: " + item.name);
        item.type_id = static_cast<uint32_t>(id);
    }
    if (btf__fd(loaded_btf) < 0) {
        const int err = btf__load_into_kernel(loaded_btf);
        if (err) fail("load source proof BTF: " + libbpf_error_string(err));
    }
    proof_btf.fd = dup(btf__fd(loaded_btf));
    if (proof_btf.fd < 0) fail("duplicate source proof BTF: " + std::string(std::strerror(errno)));
    for (const auto &item : placed) subprograms.push_back({item.start, item.type_id});
}

native_loader::LoadedProgram load_trusted_worker(const native_loader::FdLoadOptions &options)
{
    native_lab_trusted_activate activate{options.trusted_request_id};
    if (ioctl(options.trusted_service_fd, NATIVE_LAB_TRUSTED_ACTIVATE, &activate))
        fail("activate service request: " + std::string(std::strerror(errno)));
    if (options.original_prog_fd < 0 && !options.native_context)
        fail("native_loader: missing original program/context");
    const bpf_prog_info info = options.original_prog_fd >= 0
        ? load_prog_info(options.original_prog_fd) : options.native_context.value();
    CompanionLoad companion{};
    if (options.original_prog_fd >= 0)
        companion = load_from_loaded_program_fd(options.original_prog_fd, info, nullptr, 0, {});
    companion.prog_type = info.type;
    std::vector<native_loader::TrustedMapBinding> bindings = options.trusted_maps;
    ScopedFd unspecified(bpf_map_create(BPF_MAP_TYPE_ARRAY, "kprog_unspec", 4, 8, 1, nullptr));
    if (unspecified.get() < 0) fail("create unspecified input map: " + std::string(std::strerror(errno)));
    bindings.push_back({"kprog_unspecified_input", load_map_info(unspecified.get()).id, 0});
    // The simulator's externs carry their asm label, which differs from the
    // native ELF spelling for a compiler-temporary name like ".L.str.2". Both
    // spellings resolve to the same kernel map identity.
    for (const auto &binding : options.trusted_maps) {
        const std::string label = native_map_label(binding.native_symbol);
        if (label != binding.native_symbol)
            bindings.push_back({label, binding.map_id, binding.value_offset});
    }
    std::vector<std::unique_ptr<ScopedFd>> pins;
    for (const auto &binding : bindings) {
        auto fd = std::make_unique<ScopedFd>(bpf_map_get_fd_by_id(binding.map_id));
        if (fd->get() < 0) fail("reopen kernel-pinned native map: " + std::string(std::strerror(errno)));
        const auto map = load_map_meta_from_fd(fd->get());
        add_map_meta(companion, map);
        add_map_symbol_alias_meta(companion, binding.native_symbol, map);
        add_hash_map_ops(companion, map, fd->get());
        if (binding.value_offset) {
            if (!map.value_addr || *binding.value_offset >= map.value_size)
                fail("trusted direct map value exceeds the original map");
            companion.map_addrs[binding.native_symbol] = map.value_addr + *binding.value_offset;
            companion.native_map_symbols.erase(binding.native_symbol);
        }
        pins.push_back(std::move(fd));
    }
    std::vector<bpf_insn> proof;
    std::vector<ProofSubprogram> subprograms;
    ScopedFd proof_btf;
    if (!options.trusted_direct_native) {
        // These aliases come from kernel-pinned identities, not process-wide map names.
        using Object = std::unique_ptr<bpf_object, decltype(&bpf_object__close)>;
        bpf_object *raw = bpf_object__open_file(options.proof_object_path.c_str(), nullptr);
        const long open_error = libbpf_get_error(raw);
        if (open_error || !raw) fail("open service simulator: " + libbpf_error_string(open_error ? open_error : -errno));
        Object object(raw, bpf_object__close);
        bpf_program *selected = bpf_object__find_program_by_name(raw, options.trusted_simulator_program.c_str());
        if (!selected || static_cast<uint32_t>(bpf_program__type(selected)) != info.type)
            fail("service simulator entry/type differs from original program");
        const auto *instructions = bpf_program__insns(selected);
        const size_t count = bpf_program__insn_cnt(selected);
        if (!instructions || !count) fail("service simulator is empty");
        proof.assign(instructions, instructions + count);
        relocate_trusted_proof(raw, options.proof_object_path, options.trusted_simulator_program,
                               companion, proof, pins, bindings, subprograms, proof_btf);
        // B's typed declarations are generated from the running target BTF. Use
        // those same declarations to resolve the matching calls/addresses in P.
        const auto *loaded_types = bpf_object__btf(raw);
        if (loaded_types && btf__find_by_name_kind(loaded_types, ".ksyms", BTF_KIND_DATASEC) > 0) {
            std::unique_ptr<btf, decltype(&btf__free)> proof_types(
                btf__parse(options.proof_object_path.c_str(), nullptr), btf__free);
            if (!proof_types) fail("read simulator BTF for native kernel functions");
            if (!native_kfunc_declarations(proof_types.get()).empty()) {
                std::unique_ptr<btf, decltype(&btf__free)> kernel(btf__load_vmlinux_btf(), btf__free);
                if (!kernel) fail("read target BTF for native kernel functions");
                companion.kernel_functions = native_kernel_function_targets(options.native_object_path,
                    proof_types.get(), kernel.get());
            }
        }
    }
    bpf_prog_load_opts opts{}; opts.sz = sizeof(opts);
    opts.expected_attach_type = static_cast<bpf_attach_type>(options.expected_attach_type);
    opts.prog_flags = options.prog_flags;
    opts.prog_ifindex = info.ifindex;
    opts.attach_btf_id = options.attach_btf_id;
    ScopedFd attach_program(open_prog_fd_by_id_required(options.attach_prog_id, "attach_prog_id"));
    ScopedFd attach_btf(open_btf_fd_by_id_required(options.attach_btf_obj_id, "attach_btf_obj_id"));
    if (attach_program.get() >= 0) opts.attach_prog_fd = attach_program.get();
    else if (attach_btf.get() >= 0) opts.attach_btf_obj_fd = attach_btf.get();
    bpf_func_info entry{};
    uint32_t source_btf_id = options.source_btf_id;
    if (options.original_prog_fd >= 0 && info.nr_func_info) {
        bpf_prog_info detail{}; detail.nr_func_info = 1;
        detail.func_info_rec_size = sizeof(entry); detail.func_info = ptr_to_u64(&entry);
        uint32_t size = sizeof(detail);
        if (bpf_obj_get_info_by_fd(options.original_prog_fd, &detail, &size))
            fail("query original entry ABI: " + std::string(std::strerror(errno)));
        source_btf_id = detail.btf_id;
    } else if (options.native_entry_function) entry = *options.native_entry_function;
    ScopedFd source_btf(open_btf_fd_by_id_required(source_btf_id, "source_btf_id"));
    std::vector<bpf_func_info> records;
    if (subprograms.size() > 1) {
        // Appended subprograms carry the proof object's own BTF type ids, so
        // the program BTF must be the proof BTF and not the source one.
        for (const auto &subprogram : subprograms) {
            bpf_func_info record{};
            record.insn_off = subprogram.start; record.type_id = subprogram.type_id;
            records.push_back(record);
        }
        opts.prog_btf_fd = proof_btf.get();
        opts.func_info = records.data(); opts.func_info_cnt = records.size();
        opts.func_info_rec_size = sizeof(bpf_func_info);
    } else if (source_btf.get() >= 0) {
        records.assign(1, entry);
        opts.prog_btf_fd = source_btf.get();
        opts.func_info = records.data(); opts.func_info_cnt = 1;
        opts.func_info_rec_size = sizeof(bpf_func_info);
    }
    std::vector<char> log(16 * 1024 * 1024, '\0');
    opts.log_buf = log.data(); opts.log_size = log.size(); opts.log_level = 1;
    const auto name = prog_info_name_or_stub(info);
    if (options.trusted_verify_only) {
        ScopedFd verified(bpf_prog_load(static_cast<bpf_prog_type>(info.type), name.c_str(),
            info.gpl_compatible ? "GPL" : "BSD", proof.data(), proof.size(), &opts));
        if (verified.get() < 0)
            throw native_loader::SimulatorVerificationError("service simulator verification failed before native compilation: " +
                libbpf_error_string(verified.get()) + "\n" + std::string(log.data(), strnlen(log.data(), log.size())));
        native_loader::LoadedProgram out{};
        out.prog_fd = verified.fd; verified.fd = -1;
        out.bpf_bytecode_bytes = proof.size() * sizeof(bpf_insn);
        return out;
    }
    // The simulator's proof is what the kernel verifies, so its calls decide
    // whether the link needs kernel addresses. A direct native image builds
    // its proof after linking, so this keeps the catalogue for it.
    companion.needs_kernel_symbols |= proof_needs_kernel_symbols(proof);
    LinkedBlob linked = load_or_link_native_blob(options.native_link_path, options.native_object_path,
        options.symbol_name, companion, options.trusted_native_proof_path);
    ScopedFd tail_call_marker;
    if (options.trusted_direct_native) {
        const auto relocs = parse_native_lab_relocs(linked.relocs, linked.blob.size());
        const bool tail_call_reachable = companion.has_tail_call ||
            std::any_of(relocs.begin(), relocs.end(), [](const auto &reloc) {
                return reloc.kind == NATIVE_LAB_RELOC_X86_TAIL_COUNT;
            });
        if (tail_call_reachable)
            tail_call_marker.fd = create_tail_call_marker_map();
        proof = native_stub_program(tail_call_marker.get());
        // The stub is one subprogram, so the appended layout no longer applies.
        if (records.size() > 1) {
            records.assign(1, entry);
            opts.prog_btf_fd = source_btf.get();
            opts.func_info = records.data(); opts.func_info_cnt = records.size();
        }
    }
    // P retains its relocated maps; B's LDDW references retain B's maps.
    std::vector<int> fd_array = reopen_relocated_map_fds(linked.relocated_map_ids);
    for (int fd : fd_array)
        pins.push_back(std::make_unique<ScopedFd>(fd));
    opts.fd_array = fd_array.data(); opts.fd_array_cnt = fd_array.size();
    opts.prog_flags |= NATIVE_LAB_PROG_F_NATIVE_IMAGE;
    native_lab_trusted_chunk image{};
    image.request_id = options.trusted_request_id;
    image.native_user = ptr_to_u64(linked.blob.data()); image.native_size = linked.blob.size();
    image.relocs_user = ptr_to_u64(linked.relocs.data()); image.reloc_count = linked.relocs.size() / kRelocRecordBytes;
    image.reserved = linked.callee_saved_mask;
    image.load_sites_user = ptr_to_u64(linked.load_sites.data());
    image.load_site_count = linked.load_sites.size();
    // A prog array P names that its own program does not use can belong to
    // programs of another type (OTel's uprobe custom__generic names
    // perf_progs, owned by perf_event programs): process_fd_array adds every
    // fd to used_maps, and bpf_check_tail_call then refuses this program
    // with a bare -EINVAL after a clean verify, with no log line. Load again
    // without those arrays, which the application itself holds.
    const std::vector<uint32_t> original_ids = options.original_prog_fd >= 0
        ? load_prog_map_ids(options.original_prog_fd) : std::vector<uint32_t>{};
    const std::unordered_set<uint32_t> used(original_ids.begin(), original_ids.end());
    const auto foreign_prog_array = [&](uint32_t id) {
        if (used.count(id)) return false;
        ScopedFd fd(bpf_map_get_fd_by_id(id));
        if (fd.get() < 0) return false;
        const bpf_map_info info = load_map_info(fd.get());
        return info.type == BPF_MAP_TYPE_PROG_ARRAY;
    };
    // collect_relocated_map_ids already drops 0 and repeats, so these two
    // vectors hold one entry per distinct relocated map, in one order.
    std::vector<std::pair<int, uint32_t>> load_fds;
    for (size_t i = 0; i < fd_array.size(); i++)
        load_fds.emplace_back(fd_array[i], linked.relocated_map_ids[i]);
    const auto arm_and_load = [&](const std::vector<std::pair<int, uint32_t>> &pairs) {
        std::vector<int> fds;
        for (const auto &pair : pairs) fds.push_back(pair.first);
        opts.fd_array = fds.data(); opts.fd_array_cnt = fds.size();
        if (ioctl(options.trusted_service_fd, NATIVE_LAB_TRUSTED_CHUNK, &image))
            fail("arm kernel native image: " + std::string(std::strerror(errno)));
        return bpf_prog_load(static_cast<bpf_prog_type>(info.type), name.c_str(),
            info.gpl_compatible ? "GPL" : "BSD", proof.data(), proof.size(), &opts);
    };
    int verified_fd = arm_and_load(load_fds);
    if (verified_fd < 0 && options.original_prog_fd >= 0) {
        std::vector<std::pair<int, uint32_t>> own_fds;
        std::vector<uint32_t> dropped;
        for (const auto &pair : load_fds) {
            if (foreign_prog_array(pair.second)) dropped.push_back(pair.second);
            else own_fds.push_back(pair);
        }
        if (!dropped.empty()) {
            std::string ids;
            for (uint32_t id : dropped) ids += " " + std::to_string(id);
            std::fprintf(stderr, "native: reloading without foreign PROG_ARRAY map(s)%s\n", ids.c_str());
            verified_fd = arm_and_load(own_fds);
        }
    }
    ScopedFd verified(verified_fd);
    if (verified.get() < 0)
        fail("service simulator verification failed: " + libbpf_error_string(verified.get()) +
             "\n" + std::string(log.data(), strnlen(log.data(), log.size())));
    const auto native_info = load_prog_info(verified.get());
    native_lab_trusted_result completed{};
    completed.request_id = options.trusted_request_id; completed.prog_id = native_info.id;
    if (ioctl(options.trusted_service_fd, NATIVE_LAB_TRUSTED_COMPLETE, &completed))
        fail("kernel trusted native completion refused: " + std::string(std::strerror(errno)));
    native_loader::LoadedProgram out{};
    out.prog_fd = verified.fd; verified.fd = -1;
    out.replaced = true; out.original_prog_id = info.id; out.native_prog_id = native_info.id;
    out.native_code_bytes = linked.blob.size(); out.bpf_bytecode_bytes = proof.size() * sizeof(bpf_insn);
    return out;
}

LoadedProgram load_bound_native(const FdLoadOptions &options)
{
    if (options.original_prog_fd < 0) {
        fail("native_loader: missing original_prog_fd");
    }
    if (options.native_object_path.empty() && options.manifest_path.empty()) {
        fail("native_loader: missing native_object_path or manifest_path");
    }
    LoadedProgram out{};
    const auto collecting_timings = [&] { return options.diagnostics && !options.diagnostics->log_path.empty(); };
    const auto diagnostic_now = [&] { return collecting_timings()
        ? std::chrono::steady_clock::now() : std::chrono::steady_clock::time_point{}; };
    const auto context_start = options.diagnostics ? options.diagnostics->started : std::chrono::steady_clock::time_point{};
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
    // Two entry clocks preserve context/manifest attribution when metadata enables logging.
    const auto context_end = options.diagnostics ? std::chrono::steady_clock::now()
        : std::chrono::steady_clock::time_point{};
    std::filesystem::path native_object_path = options.native_object_path;
    std::string symbol_name = options.symbol_name;
    std::vector<NativeMapRule> map_rules;
    bool kernel_kfunc_context = false;
    std::filesystem::path kernel_kfunc_btf;
    std::filesystem::path source_bpf_object;
    if (native_object_path.empty()) {
        if (source_insns.empty()) {
            fail("native_loader: manifest resolution requires source BPF bytecode");
        }
        std::optional<ManifestResolution> resolution =
            resolve_native_manifest(options.manifest_path,
                                    prog_info,
                                    source_insns,
                                    load_map_info);
        if (!resolution) {
            if (collecting_timings()) {
                out.timings.source_context_ns = elapsed_ns(context_start, context_end);
                out.timings.manifest_ns = elapsed_ns(context_end, diagnostic_now());
            }
            return out;
        }
        if (options.diagnostics && options.diagnostics->log_path.empty())
            options.diagnostics->log_path = resolution->loader_timing_log;
        native_object_path = resolution->native_object_path;
        if (!resolution->symbol_name.empty()) symbol_name = resolution->symbol_name;
        kernel_kfunc_context = resolution->kernel_kfunc_context;
        kernel_kfunc_btf = resolution->kernel_kfunc_btf;
        source_bpf_object = resolution->source_bpf_object;
        map_rules = std::move(resolution->map_rules);
    }
    if (symbol_name.empty()) {
        symbol_name = load_prog_btf_symbol_name(options.original_prog_fd, prog_info);
    }
    const auto manifest_end = diagnostic_now();
    CompanionLoad companion =
        load_from_loaded_program_fd(
            options.original_prog_fd,
            prog_info,
            source_insns.empty() ? nullptr : source_insns.data(),
            source_insns.size(),
            std::move(map_rules));
    if (kernel_kfunc_context) {
        // libbpf rewrites .ksyms/linkage before BTF_LOAD. Use the unchanged
        // object's declarations, not the sanitized loaded-program BTF.
        if (kernel_kfunc_btf.empty()) fail("kernel kfunc context requires kernel_kfunc_btf");
        std::unique_ptr<btf, decltype(&btf__free)> local(
            btf__parse(kernel_kfunc_btf.c_str(), nullptr), btf__free);
        std::unique_ptr<btf, decltype(&btf__free)> kernel(btf__load_vmlinux_btf(), btf__free);
        if (!local || !kernel) fail("load object/vmlinux BTF for native kfuncs");
        companion.kernel_functions = native_kernel_function_targets(native_object_path, local.get(), kernel.get());
    }
    const auto data_symbols_start = diagnostic_now();
    auto entry_proof = cached_native_entry_proof(options.native_link_path, native_object_path, symbol_name);
    const auto entry_symbols = native_entry_symbol_names(entry_proof);
    if (!source_bpf_object.empty()) {
        if (source_insns.empty()) fail("source_bpf_object requires intercepted source instructions");
        bind_original_source_maps(source_bpf_object, symbol_name, source_insns, companion, &entry_symbols);
    }
    add_native_data_symbol_addrs(native_object_path, companion, &entry_symbols);
    const char *bound = std::getenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF");
    const bool require_bound = bound && (std::strcmp(bound, "1") == 0 || std::strcmp(bound, "true") == 0 ||
        std::strcmp(bound, "yes") == 0 || std::strcmp(bound, "on") == 0);
#if defined(__x86_64__)
    std::ostringstream immutable;
    immutable << '{';
    bool separator = false;
    for (const auto &[name, value] : companion.immutable_globals) {
        if (separator) immutable << ',';
        write_json_string(immutable, name); immutable << ':';
        write_json_string(immutable, value); separator = true;
    }
    immutable << '}';
    std::ostringstream map_types;
    map_types << '{';
    bool map_separator = false;
    bool typed_lookups = false;
    for (const auto &[name, loaded] : companion.native_map_symbols) {
        if (companion.native_data_symbols.contains(name)) continue;
        const auto *meta = find_map_meta_by_native_symbol(companion, name);
        if (!meta) continue;
        // Checked-sim-c expands LPM from the accepted B helper call in its
        // existing native C stage. Direct native expands the same C body here.
        if (require_bound && (meta->type == BPF_MAP_TYPE_LPM_TRIE ||
                              meta->inner_type == BPF_MAP_TYPE_LPM_TRIE)) continue;
        if (map_separator) map_types << ',';
        write_json_string(map_types, name);
        map_types << ":{\"type\":" << meta->type << ",\"inner_type\":" << meta->inner_type
                  << ",\"key_size\":" << meta->key_size
                  << ",\"value_size\":" << meta->value_size
                  << ",\"inner_value_size\":" << meta->inner_value_size << '}';
        map_separator = true;
        typed_lookups |= meta->inner_type == BPF_MAP_TYPE_ARRAY ||
                         meta->type == BPF_MAP_TYPE_LPM_TRIE || meta->inner_type == BPF_MAP_TYPE_LPM_TRIE;
    }
    map_types << '}';
    const auto function_bodies = native_source_function_bodies(
        native_object_path, options.source_bpf_path, prog_info, source_insns);
    const auto optimized = native_context_lto_object(native_object_path, symbol_name, prog_info.type,
        "/opt/bpf-benchmark/native-bpf/x86_64/kprog-perf-context-lto", "/sys/kernel/btf/vmlinux",
        kNativeLinkCacheDir, function_bodies,
        companion.immutable_globals.empty() ? std::string{} : immutable.str(),
        typed_lookups ? map_types.str() : std::string{});
    if (optimized != native_object_path) {
        native_object_path = optimized;
        entry_proof = cached_native_entry_proof(options.native_link_path, native_object_path, symbol_name);
        const auto optimized_symbols = native_entry_symbol_names(entry_proof);
        // The new closure can eliminate globals and define former function
        // declarations; only its data references belong to the final proof.
        companion.native_data_symbols.clear();
        if (!source_bpf_object.empty())
            bind_original_source_maps(source_bpf_object, symbol_name, source_insns, companion, &optimized_symbols);
        add_native_data_symbol_addrs(native_object_path, companion, &optimized_symbols);
    }
#endif
    const auto data_symbols_end = diagnostic_now();
    const auto with_common_timings = [&](LoadedProgram result) {
        if (collecting_timings()) {
            result.timings.source_context_ns = elapsed_ns(context_start, context_end);
            result.timings.manifest_ns = elapsed_ns(context_end, manifest_end);
            result.timings.companion_total_ns = elapsed_ns(manifest_end, data_symbols_start);
            result.timings.data_symbols_ns = elapsed_ns(data_symbols_start, data_symbols_end);
            result.timings.companion_map_ptr_extract_ns = companion.map_ptr_extract_ns;
            result.timings.companion_lookup_spec_ns = companion.lookup_spec_ns;
        }
        return result;
    };

    {
        for (const auto &name : companion.native_data_symbols)
            if (!companion.map_addr_ids.contains(name)) add_native_map_symbol_alias(companion, name);
        return with_common_timings(submit_trusted_native(options, prog_info, native_object_path, symbol_name, companion));
    }
}

} // namespace native_loader::trusted

namespace native_loader::internal {
bool requires_bound_proof()
{
    const char *value = std::getenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF");
    return value && (std::strcmp(value, "1") == 0 || std::strcmp(value, "true") == 0 ||
                     std::strcmp(value, "yes") == 0 || std::strcmp(value, "on") == 0);
}

LoadedProgram load_checked(const FdLoadOptions &options)
{
    if (options.trusted_service_fd >= 0) return trusted::load_trusted_worker(options);
    if (options.diagnostics) return trusted::load_bound_native(options);
    // Keep checked C-entry diagnostics on this side of the hand-off.
    const char *timing_env = std::getenv("BPFREJIT_NATIVE_LOADER_TIMING_LOG");
    LoadDiagnostics diagnostics{timing_env ? timing_env : "", std::chrono::steady_clock::now()};
    FdLoadOptions checked = options;
    checked.diagnostics = &diagnostics;
    LoadedProgram loaded = trusted::load_bound_native(checked);
    try {
        if (!diagnostics.log_path.empty()) {
            const auto end = std::chrono::steady_clock::now();
            native_loader_detail::append_timing_record(diagnostics.log_path,
                options.original_prog_fd, loaded,
                std::chrono::duration_cast<std::chrono::nanoseconds>(diagnostics.started.time_since_epoch()).count(),
                std::chrono::duration_cast<std::chrono::nanoseconds>(end.time_since_epoch()).count());
        }
    } catch (...) {
        close_loaded_program(&loaded);
        throw;
    }
    return loaded;
}
} // namespace native_loader::internal
