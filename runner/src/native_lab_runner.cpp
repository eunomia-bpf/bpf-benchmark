// Native-lab kernel runner.
//
// Mirrors run_kernel's measurement contract but loads a userspace-linked
// native byte blob into a minimal BPF stub via the native_lab kinsn. The
// kinsn splats
// the blob bytes into the JIT image so the native function runs in place
// of the BPF body. Input prep, packet construction, and result extraction
// reuse the shared kernel_test_run helpers; the only logic that lives in
// this file is the parts that are genuinely native_lab-specific:
//   * locate the module's kernel BTF fd and the emit kfunc's btf_id,
//   * upload the blob in <=128-byte chunks through debugfs,
//   * construct the tiny `(sidecar; call kinsn)*N; exit` stub program.

#include "micro_exec.hpp"
#include "kernel_test_run.hpp"
#include "bpf_helpers.hpp"
#include "kernel_offsets.h"

#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <sys/wait.h>
#include <unordered_map>
#include <utility>
#include <vector>

namespace {

struct NativeLabTarget {
    const char *module_name;
    const char *kfunc_name;
    const char *module_btf_path;
    const char *debugfs_dir;
    const char *blob_path_fmt;
    const char *relocs_path_fmt;
    const char *map_ptr_path;
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
    .chunk_bytes = 128,
};
#endif

constexpr const char *kVmlinuxBtfPath = "/sys/kernel/btf/vmlinux";
constexpr const char *kDebugfsDir = "/sys/kernel/debug";
constexpr uint32_t kMaxBlobs = 64;

/* Stage 2: BPF helpers whose addresses we resolve from /proc/kallsyms
 * and pass to native-link. This is the smallest set our POC test
 * programs need; expand as new helpers show up in new tests. */
constexpr const char *kSupportedHelpers[] = {
    "bpf_ktime_get_ns",
    "bpf_ktime_get_boot_ns",
    "bpf_get_current_pid_tgid",
    "bpf_get_current_uid_gid",
    "bpf_get_smp_processor_id",
    "bpf_get_prandom_u32",
    "bpf_probe_read_kernel",
    "bpf_map_lookup_elem",
    "bpf_map_update_elem",
    "bpf_map_delete_elem",
};

constexpr const char *kX86CpuNumberHelperKey = "__native_x86_cpu_number";
constexpr const char *kX86ThisCpuOffHelperKey = "__native_x86_this_cpu_off";
constexpr const char *kArm64ThreadInfoCpuOffsetHelperKey =
    "__native_arm64_thread_info_cpu_offset";
constexpr const char *kNativeLinkCacheDir = "/tmp/native_kernel_link_cache";
constexpr const char *kNativeLinkCacheVersion = "native-link-template-cache-v18";
constexpr const char *kKallsymsCachePath = "/tmp/native_kernel_kallsyms.tsv";
constexpr const char *kKallsymsCacheVersion = "native-kallsyms-cache-v1";
constexpr const char *kNativeStubBtfCachePath = "/tmp/native_kernel_stub_btf.tsv";
constexpr const char *kNativeStubBtfCacheVersion = "native-stub-btf-cache-v1";

#ifndef BPF_PSEUDO_KINSN_SIDECAR
#define BPF_PSEUDO_KINSN_SIDECAR 3
#endif
#ifndef BPF_PSEUDO_KINSN_CALL
#define BPF_PSEUDO_KINSN_CALL 4
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

uint64_t lookup_kernel_map_ptr_by_fd(int map_fd)
{
    ensure_debugfs_mounted();
    int fd = open(kNativeLabTarget.map_ptr_path, O_RDWR | O_CLOEXEC);
    if (fd < 0) {
        fail(std::string("open ") + kNativeLabTarget.map_ptr_path + ": "
             + std::strerror(errno));
    }

    char request[32];
    int request_len = std::snprintf(request, sizeof(request), "%d\n", map_fd);
    if (request_len <= 0 || request_len >= static_cast<int>(sizeof(request))) {
        close(fd);
        fail("native_kernel: invalid map fd for map_ptr query");
    }

    ssize_t written = write(fd, request, static_cast<size_t>(request_len));
    int saved = errno;
    if (written != request_len) {
        close(fd);
        fail(std::string("write ") + kNativeLabTarget.map_ptr_path + ": "
             + std::strerror(saved));
    }

    if (lseek(fd, 0, SEEK_SET) < 0) {
        saved = errno;
        close(fd);
        fail(std::string("lseek ") + kNativeLabTarget.map_ptr_path + ": "
             + std::strerror(saved));
    }

    char response[64] = {};
    ssize_t n = read(fd, response, sizeof(response) - 1);
    saved = errno;
    close(fd);
    if (n <= 0) {
        fail(std::string("read ") + kNativeLabTarget.map_ptr_path + ": "
             + std::strerror(saved));
    }
    response[n] = '\0';

    errno = 0;
    char *end = nullptr;
    unsigned long long value = std::strtoull(response, &end, 0);
    if (errno != 0 || end == response || value == 0) {
        fail(std::string("native_kernel: invalid map_ptr response: ") + response);
    }
    return static_cast<uint64_t>(value);
}

constexpr size_t kRelocRecordBytes = 16;
constexpr uint32_t kNativeLabRelocCallRel32 = 1;

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

void upload_relocs(const std::vector<uint8_t> &relocs, size_t blob_size, uint32_t chunks)
{
    if (relocs.empty()) {
        return;
    }
    if (!kNativeLabTarget.relocs_path_fmt) {
        fail(std::string("native_lab relocs are not supported by module ")
             + kNativeLabTarget.module_name);
    }
    if (relocs.size() % kRelocRecordBytes != 0) {
        fail("native_lab reloc file size is not a multiple of 16 bytes");
    }

    std::vector<std::vector<uint8_t>> by_chunk(chunks);
    for (size_t off = 0; off < relocs.size(); off += kRelocRecordBytes) {
        uint32_t global_offset = read_u32_le(relocs.data() + off);
        uint32_t kind = read_u32_le(relocs.data() + off + 4);
        uint64_t target = read_u64_le(relocs.data() + off + 8);
        size_t reloc_bytes = 0;
        switch (kind) {
        case kNativeLabRelocCallRel32:
            reloc_bytes = 5;
            break;
        default:
            fail("native_lab reloc has unknown kind " + std::to_string(kind));
        }
        if (static_cast<size_t>(global_offset) + reloc_bytes > blob_size) {
            fail("native_lab reloc call offset exceeds blob bounds");
        }
        uint32_t chunk_id = global_offset / kNativeLabTarget.chunk_bytes;
        uint32_t local_offset = global_offset % kNativeLabTarget.chunk_bytes;
        if (chunk_id >= chunks) {
            fail("native_lab reloc chunk exceeds uploaded blob count");
        }
        if (local_offset + reloc_bytes > kNativeLabTarget.chunk_bytes) {
            fail("native_lab call relocation crosses a blob chunk boundary");
        }
        append_u32_le(by_chunk[chunk_id], local_offset);
        append_u32_le(by_chunk[chunk_id], kind);
        append_u64_le(by_chunk[chunk_id], target);
    }

    for (uint32_t i = 0; i < chunks; i++) {
        if (!by_chunk[i].empty()) {
            upload_reloc_chunk(by_chunk[i], i);
        }
    }
}

uint32_t upload_blob(const std::vector<uint8_t> &blob)
{
    if (blob.empty()) {
        fail("native blob is empty");
    }
    uint32_t chunks = static_cast<uint32_t>(
        (blob.size() + kNativeLabTarget.chunk_bytes - 1) / kNativeLabTarget.chunk_bytes);
    if (chunks > kMaxBlobs) {
        fail("native blob requires " + std::to_string(chunks) +
             " chunks but module only supports " + std::to_string(kMaxBlobs));
    }
    for (uint32_t i = 0; i < chunks; i++) {
        char path[128];
        snprintf(path, sizeof(path), kNativeLabTarget.blob_path_fmt, i);
        int fd = open(path, O_WRONLY | O_TRUNC);
        if (fd < 0) {
            fail(std::string("open ") + path + ": " + std::strerror(errno));
        }
        size_t off = static_cast<size_t>(i) * kNativeLabTarget.chunk_bytes;
        size_t l = std::min<size_t>(kNativeLabTarget.chunk_bytes, blob.size() - off);
        ssize_t n = write(fd, blob.data() + off, l);
        int saved = errno;
        close(fd);
        if (n != static_cast<ssize_t>(l)) {
            fail(std::string("write ") + path + ": " + std::strerror(saved));
        }
    }
    return chunks;
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

// Build the (sidecar; call kinsn)*N; exit stub and BPF_PROG_LOAD it via
// libbpf's bpf_prog_load + bpf_prog_load_opts.fd_array. Returns prog fd.
int load_stub_prog(int kfunc_btf_id, int mod_btf_fd, uint32_t chunks,
                   uint32_t x86_callee_saved_mask,
                   uint32_t prog_type_value)
{
    if (chunks == 0) {
        fail("chunks must be > 0");
    }
    if (x86_callee_saved_mask > 0xf) {
        fail("native_kernel x86 callee-saved mask exceeds 4 bits");
    }
    std::vector<bpf_insn> insns;
    insns.reserve(static_cast<size_t>(2) * chunks + 1);
    for (uint32_t i = 0; i < chunks; i++) {
        bpf_insn sidecar = {
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = 0,
            .src_reg = BPF_PSEUDO_KINSN_SIDECAR,
            .off = static_cast<int16_t>(x86_callee_saved_mask),
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
    insns.push_back(bpf_insn{
        .code = BPF_JMP | BPF_EXIT, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0,
    });

    // fd_array[0] is the verifier's pre-scan slot; the ReJIT path duplicates
    // the module BTF fd there. fd_array[1] is what `off=1` in the
    // kinsn call insn resolves to.
    int fd_array[2] = {mod_btf_fd, mod_btf_fd};
    std::vector<char> log_buf(32 * 1024, '\0');

    LIBBPF_OPTS(bpf_prog_load_opts, opts,
        .fd_array = fd_array,
        .log_level = 1,
        .log_size = static_cast<uint32_t>(log_buf.size()),
        .log_buf = log_buf.data(),
    );
    int fd = bpf_prog_load(static_cast<bpf_prog_type>(prog_type_value),
                           "native_lab_stub", "GPL",
                           insns.data(), insns.size(), &opts);
    if (fd < 0) {
        fail(std::string("bpf_prog_load (native_lab stub): ")
             + std::strerror(errno) + "\nverifier log:\n" + log_buf.data());
    }
    return fd;
}

std::vector<uint8_t> read_blob_file(const std::filesystem::path &path)
{
    std::ifstream f(path, std::ios::binary);
    if (!f) {
        fail("read native blob: " + path.string());
    }
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(f)),
                                std::istreambuf_iterator<char>());
}

bool file_is_elf(const std::filesystem::path &path)
{
    std::ifstream f(path, std::ios::binary);
    if (!f) return false;
    char m[4] = {};
    f.read(m, 4);
    return m[0] == 0x7f && m[1] == 'E' && m[2] == 'L' && m[3] == 'F';
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
            if (value != "native-link-abi-v1") {
                fail("unsupported native-link ABI version in " + path.string()
                     + ": " + value);
            }
            seen_version = true;
        } else if (key == "x86_callee_saved_mask") {
            mask = parse_decimal_u64(value, "native-link x86 callee-saved mask");
            if (mask > 0xf) {
                fail("native-link x86 callee-saved mask exceeds 4 bits");
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

const std::unordered_map<std::string, uint64_t> &kallsyms_table()
{
    static std::unordered_map<std::string, uint64_t> table;
    if (!table.empty()) {
        return table;
    }

    const char *const wanted[] = {
        "__htab_map_lookup_elem",
        "bpf_get_current_pid_tgid",
        "bpf_get_current_uid_gid",
        "bpf_get_smp_processor_id",
        "bpf_ktime_get_boot_ns",
        "bpf_ktime_get_ns",
        "bpf_map_delete_elem",
        "bpf_map_lookup_elem",
        "bpf_map_update_elem",
        "bpf_probe_read_kernel",
        "htab_lru_map_lookup_elem",
        "htab_percpu_map_lookup_elem",
#if defined(__x86_64__)
        "cpu_number",
        "this_cpu_off",
#endif
    };
    constexpr size_t wanted_count = sizeof(wanted) / sizeof(wanted[0]);

    const std::string boot_id =
        read_first_line_required("/proc/sys/kernel/random/boot_id");
    if (load_kallsyms_cache(table, wanted, wanted_count, boot_id)) {
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
    store_kallsyms_cache(table, wanted, wanted_count, boot_id);
    return table;
}

/* Look up a symbol address in /proc/kallsyms. Returns 0 on miss. The
 * caller must enable kallsyms readability (kptr_restrict=0 or CAP_SYSLOG;
 * VM has root). */
uint64_t kallsyms_lookup(const std::string &name)
{
    const auto &table = kallsyms_table();
    auto it = table.find(name);
    if (it != table.end()) {
        return it->second;
    }
    return 0;
}

struct BpfArrayOffsets {
    uint32_t value;
    uint32_t pptrs;
};

struct BpfHtabOffsets {
    uint32_t key;
};

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

/* Spawn the native-link binary with the supplied argv. Returns
 * subprocess exit code. */
int run_subprocess(const std::vector<std::string> &argv)
{
    if (argv.empty()) return -1;
    std::vector<char *> raw;
    raw.reserve(argv.size() + 1);
    for (auto &s : argv) {
        raw.push_back(const_cast<char *>(s.c_str()));
    }
    raw.push_back(nullptr);

    pid_t pid = fork();
    if (pid < 0) return -1;
    if (pid == 0) {
        /* child */
        execv(raw[0], raw.data());
        std::fprintf(stderr, "execv %s failed: %s\n", raw[0], std::strerror(errno));
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
std::filesystem::path native_link_binary(const cli_options &options)
{
    if (!options.native_kernel_linker_path.empty()) {
        return options.native_kernel_linker_path;
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

/* Stage 2: given an ELF .native.o input, resolve helper kernel addresses
 * via /proc/kallsyms, invoke native-link as a subprocess to produce
 * blob + relocs files. Returns paths to those files. */
struct LinkerOutput {
    std::filesystem::path blob;
    std::filesystem::path relocs;
    std::filesystem::path map_patches;
    std::filesystem::path abi;
};

struct NativeLinkArgs {
    std::filesystem::path linker;
    std::vector<std::string> helpers;
    std::vector<std::string> maps;
    std::vector<std::string> lookup_sites;
    std::vector<std::string> update_sites;
};

struct LinkedBlob {
    std::vector<uint8_t> blob;
    std::vector<uint8_t> relocs;
    uint64_t cache_lookup_ns = 0;
    uint64_t native_link_exec_ns = 0;
    uint64_t native_link_read_ns = 0;
    uint64_t map_patch_ns = 0;
    uint32_t x86_callee_saved_mask = 0;
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
    std::unordered_map<std::string, uint64_t> map_addrs;
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
        enum class Kind { Call, Hash, Array, PerCpuArray } kind;
        uint64_t target_addr;
        uint32_t key_offset;
        uint64_t map_addr;
        uint32_t max_entries;
        uint32_t elem_size;
        uint32_t index_mask;
        uint32_t value_offset;
        uint64_t percpu_base_addr;
    };
    std::vector<LookupSite> lookup_sites;
    struct UpdateSite {
        enum class Kind { Call, Array, PerCpuArray } kind;
        uint32_t max_entries;
        uint32_t elem_size;
        uint32_t value_size;
        uint32_t value_offset;
        uint64_t percpu_base_addr;
    };
    std::vector<UpdateSite> update_sites;
};

/* Walk a BPF program's original (pre-verifier) bytecode and identify,
 * for each `BPF_CALL bpf_map_lookup_elem`, which map fd is currently
 * bound to r1 (the map argument). Returns -1 in the slot when the
 * binding is ambiguous (dynamic / spilled / unrecognized pattern); the
 * caller treats that as "kernel BPF JIT couldn't inline either, so
 * fall back to the plain bpf_map_lookup_elem helper" -- which is what
 * the kernel does too.
 *
 * Tracking is intentionally minimal:
 *   - LD_IMM64 with src_reg=BPF_PSEUDO_MAP_FD binds dst_reg -> imm (map fd).
 *   - ALU64|MOV|X copies the binding from src_reg to dst_reg.
 *   - Any other write to a register clears that register's binding.
 *   - CALL clobbers r0..r5.
 * This matches the simple "load map fd into r1 just before the call"
 * pattern clang emits at -O2 for the test programs and most real
 * BPF code. Anything fancier (spill/reload via stack, conditional
 * map selection) falls through to fd=-1 -> no inline. */
std::vector<int> walk_map_helper_call_maps(const struct bpf_insn *insns,
                                           size_t cnt,
                                           int helper_id)
{
    std::vector<int> sites;
    int reg_map_fd[11];
    for (int i = 0; i < 11; i++) reg_map_fd[i] = -1;
    for (size_t i = 0; i < cnt; i++) {
        const struct bpf_insn &in = insns[i];
        uint8_t code = in.code;
        if (code == (BPF_LD | BPF_DW | BPF_IMM)) {
            if (in.dst_reg < 11) {
                reg_map_fd[in.dst_reg] =
                    (in.src_reg == BPF_PSEUDO_MAP_FD) ? (int)in.imm : -1;
            }
            i++; /* skip second slot (high 32 bits of imm64) */
            continue;
        }
        if (code == (BPF_ALU64 | BPF_MOV | BPF_X)) {
            if (in.dst_reg < 11 && in.src_reg < 11) {
                reg_map_fd[in.dst_reg] = reg_map_fd[in.src_reg];
            } else if (in.dst_reg < 11) {
                reg_map_fd[in.dst_reg] = -1;
            }
            continue;
        }
        if (code == (BPF_JMP | BPF_CALL)) {
            if (in.imm == helper_id) {
                sites.push_back(reg_map_fd[1]);
            }
            for (int r = 0; r <= 5; r++) reg_map_fd[r] = -1;
            continue;
        }
        /* Conservative: invalidate dst_reg for any other ALU/LDX/JMP-class
         * insn that writes a reg. Stores (BPF_STX/BPF_ST) don't write
         * dst_reg, conditional jumps don't either. */
        uint8_t cls = BPF_CLASS(code);
        if (cls == BPF_ALU || cls == BPF_ALU64 || cls == BPF_LDX) {
            if (in.dst_reg < 11) reg_map_fd[in.dst_reg] = -1;
        }
    }
    return sites;
}

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

    bool has_maps = false;
    bpf_map *map = nullptr;
    bpf_object__for_each_map(map, obj) {
        has_maps = true;
        break;
    }
    if (!has_maps) {
        bpf_object__close(obj);
        return out;
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
    map = nullptr;
    bpf_object__for_each_map(map, obj) {
        int fd = bpf_map__fd(map);
        if (fd >= 0) {
            out.map_addrs[std::string(bpf_map__name(map))] =
                lookup_kernel_map_ptr_by_fd(fd);
        }
    }
    const auto map_ptr_end = std::chrono::steady_clock::now();
    out.map_ptr_extract_ns = elapsed_ns(map_ptr_start, map_ptr_end);

    /* Build per-call-site lookup spec for the entry program. We walk
     * the BPF source bytecode in order (verifier-friendly programs
     * have explicit BPF_LD_IMM64 pseudo_map_fd bindings just before
     * each lookup call), pair each `bpf_map_lookup_elem` call with
     * the map fd in r1, look up that map's type, and emit a per-site
     * (target_addr, key_offset) pair. native-link consumes the list
     * via repeatable --lookup-site flags and uses each entry to route
     * the i-th call to its own literal-pool entry (avoiding the
     * single-shared-pool limitation that previously forced every
     * `bpf_map_lookup_elem` site to share one target). */
    const auto lookup_spec_start = std::chrono::steady_clock::now();
    {
        /* Collect map metadata by fd for quick lookup. */
        struct MapMeta {
            std::string name;
            int type;
            uint32_t key_size;
            uint32_t value_size;
            uint32_t max_entries;
        };
        std::unordered_map<int, MapMeta> meta_by_fd;
        map = nullptr;
        bpf_object__for_each_map(map, obj) {
            int fd = bpf_map__fd(map);
            if (fd >= 0) {
                meta_by_fd[fd] = MapMeta{
                    std::string(bpf_map__name(map)),
                    (int)bpf_map__type(map),
                    bpf_map__key_size(map),
                    bpf_map__value_size(map),
                    bpf_map__max_entries(map),
                };
            }
        }

        uint64_t htab_addr = kallsyms_lookup("__htab_map_lookup_elem");
        uint64_t htab_lru_addr = kallsyms_lookup("htab_lru_map_lookup_elem");
        uint64_t htab_percpu_addr = kallsyms_lookup("htab_percpu_map_lookup_elem");
        BpfArrayOffsets array_offsets{
            K_BPF_ARRAY_VALUE_OFFSET,
            K_BPF_ARRAY_PPTRS_OFFSET,
        };
        BpfHtabOffsets htab_offsets{
            K_HTAB_ELEM_KEY_OFFSET,
        };
#if defined(__x86_64__)
        uint64_t this_cpu_off_addr = kallsyms_lookup("this_cpu_off");
#else
        uint64_t this_cpu_off_addr = 0;
#endif
        uint64_t plain_addr = kallsyms_lookup("bpf_map_lookup_elem");
        if (plain_addr == 0) {
            fail("bpf_map_lookup_elem not in /proc/kallsyms");
        }

        /* Walk the entry program's BPF source bytecode and build the
         * per-call-site spec list. Entry program is identified by
         * libbpf as the first program in iteration order in our test
         * .bpf.o files; pick it explicitly via the first program. */
        bpf_program *prog = nullptr;
        bpf_program *entry_prog = nullptr;
        bpf_object__for_each_program(prog, obj) {
            entry_prog = prog;
            break;
        }
        if (entry_prog) {
            const struct bpf_insn *insns = bpf_program__insns(entry_prog);
            size_t insn_cnt = bpf_program__insn_cnt(entry_prog);
            std::vector<int> call_maps =
                walk_map_helper_call_maps(insns, insn_cnt, BPF_FUNC_map_lookup_elem);
            for (int fd : call_maps) {
                CompanionLoad::LookupSite site{
                    CompanionLoad::LookupSite::Kind::Call,
                    plain_addr,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                };
                auto it = (fd >= 0) ? meta_by_fd.find(fd) : meta_by_fd.end();
                if (it != meta_by_fd.end()) {
                    int t = it->second.type;
                    if (t == BPF_MAP_TYPE_ARRAY) {
                        auto map_it = out.map_addrs.find(it->second.name);
                        if (map_it == out.map_addrs.end()) {
                            fail("native_kernel: missing kernel map pointer for ARRAY map " + it->second.name);
                        }
                        site.kind = CompanionLoad::LookupSite::Kind::Array;
                        site.map_addr = map_it->second;
                        site.max_entries = it->second.max_entries;
                        site.elem_size = (it->second.value_size + 7u) & ~7u;
                        site.index_mask = roundup_pow2_mask(it->second.max_entries);
                        site.value_offset = array_offsets.value;
                    } else if (t == BPF_MAP_TYPE_PERCPU_ARRAY) {
                        auto map_it = out.map_addrs.find(it->second.name);
                        if (map_it == out.map_addrs.end()) {
                            fail("native_kernel: missing kernel map pointer for PERCPU_ARRAY map " + it->second.name);
                        }
#if defined(__x86_64__)
                        if (this_cpu_off_addr == 0) {
                            fail("this_cpu_off not in /proc/kallsyms");
                        }
#endif
                        site.kind = CompanionLoad::LookupSite::Kind::PerCpuArray;
                        site.map_addr = map_it->second;
                        site.max_entries = it->second.max_entries;
                        site.elem_size = sizeof(void *);
                        site.index_mask = roundup_pow2_mask(it->second.max_entries);
                        site.value_offset = array_offsets.pptrs;
                        site.percpu_base_addr = this_cpu_off_addr;
                    } else if (t == BPF_MAP_TYPE_HASH) {
                        if (htab_addr == 0) {
                            fail("__htab_map_lookup_elem not in /proc/kallsyms");
                        }
                        uint32_t rounded = (it->second.key_size + 7) & ~7u;
                        site.kind = CompanionLoad::LookupSite::Kind::Hash;
                        site.target_addr = htab_addr;
                        site.key_offset = htab_offsets.key + rounded;
                    } else if (t == BPF_MAP_TYPE_LRU_HASH) {
                        if (htab_lru_addr == 0) {
                            fail("htab_lru_map_lookup_elem not in /proc/kallsyms");
                        }
                        site.target_addr = htab_lru_addr;
                    } else if (t == BPF_MAP_TYPE_PERCPU_HASH) {
                        if (htab_percpu_addr == 0) {
                            fail("htab_percpu_map_lookup_elem not in /proc/kallsyms");
                        }
                        site.target_addr = htab_percpu_addr;
                    }
                }
                out.lookup_sites.push_back(site);
            }

            std::vector<int> update_maps =
                walk_map_helper_call_maps(insns, insn_cnt, BPF_FUNC_map_update_elem);
            for (int fd : update_maps) {
                CompanionLoad::UpdateSite site{
                    CompanionLoad::UpdateSite::Kind::Call,
                    0,
                    0,
                    0,
                    0,
                    0,
                };
                auto it = (fd >= 0) ? meta_by_fd.find(fd) : meta_by_fd.end();
                if (it != meta_by_fd.end()) {
                    const uint32_t value_size = it->second.value_size;
                    const bool simple_value =
                        value_size == 1 || value_size == 2 ||
                        value_size == 4 || value_size == 8;
                    int t = it->second.type;
                    if (simple_value && t == BPF_MAP_TYPE_ARRAY) {
                        site.kind = CompanionLoad::UpdateSite::Kind::Array;
                        site.max_entries = it->second.max_entries;
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
                        site.max_entries = it->second.max_entries;
                        site.elem_size = sizeof(void *);
                        site.value_size = value_size;
                        site.value_offset = array_offsets.pptrs;
                        site.percpu_base_addr = this_cpu_off_addr;
                    }
                }
                out.update_sites.push_back(site);
            }
        }
    }
    const auto lookup_spec_end = std::chrono::steady_clock::now();
    out.lookup_spec_ns = elapsed_ns(lookup_spec_start, lookup_spec_end);

    out.obj = obj;
    return out;
}

std::string format_name_hex(const std::string &name, uint64_t value)
{
    char value_buf[32];
    std::snprintf(value_buf, sizeof(value_buf), "0x%llx",
                  static_cast<unsigned long long>(value));
    return name + "=" + value_buf;
}

std::string format_lookup_site_arg(size_t index,
                                   const CompanionLoad::LookupSite &site)
{
    const char *kind = "call";
    switch (site.kind) {
    case CompanionLoad::LookupSite::Kind::Call:
        kind = "call";
        break;
    case CompanionLoad::LookupSite::Kind::Hash:
        kind = "hash";
        break;
    case CompanionLoad::LookupSite::Kind::Array:
        kind = "array";
        break;
    case CompanionLoad::LookupSite::Kind::PerCpuArray:
        kind = "percpu_array";
        break;
    }

    char buf[320];
    std::snprintf(buf, sizeof(buf), "%zu=%s,0x%llx,%u,0x0,%u,%u,%u,%u,0x%llx",
                  index,
                  kind,
                  static_cast<unsigned long long>(site.target_addr),
                  static_cast<unsigned>(site.key_offset),
                  static_cast<unsigned>(site.max_entries),
                  static_cast<unsigned>(site.elem_size),
                  static_cast<unsigned>(site.index_mask),
                  static_cast<unsigned>(site.value_offset),
                  static_cast<unsigned long long>(site.percpu_base_addr));
    return std::string(buf);
}

std::string format_update_site_arg(size_t index,
                                   const CompanionLoad::UpdateSite &site)
{
    const char *kind = "call";
    switch (site.kind) {
    case CompanionLoad::UpdateSite::Kind::Call:
        kind = "call";
        break;
    case CompanionLoad::UpdateSite::Kind::Array:
        kind = "array";
        break;
    case CompanionLoad::UpdateSite::Kind::PerCpuArray:
        kind = "percpu_array";
        break;
    }

    char buf[240];
    std::snprintf(buf, sizeof(buf), "%zu=%s,%u,%u,%u,%u,0x%llx",
                  index,
                  kind,
                  static_cast<unsigned>(site.max_entries),
                  static_cast<unsigned>(site.elem_size),
                  static_cast<unsigned>(site.value_size),
                  static_cast<unsigned>(site.value_offset),
                  static_cast<unsigned long long>(site.percpu_base_addr));
    return std::string(buf);
}

NativeLinkArgs build_native_link_args(
    const cli_options &options,
    const std::unordered_map<std::string, uint64_t> &map_addrs,
    const CompanionLoad &companion)
{
    NativeLinkArgs out{};
    out.linker = native_link_binary(options);

    for (const char *h : kSupportedHelpers) {
        uint64_t addr = kallsyms_lookup(h);
        if (addr != 0) {
            out.helpers.push_back(format_name_hex(h, addr));
        }
    }
#if defined(__x86_64__)
    {
        uint64_t cpu_number_addr = kallsyms_lookup("cpu_number");
        uint64_t this_cpu_off_addr = kallsyms_lookup("this_cpu_off");
        if (cpu_number_addr != 0 && this_cpu_off_addr != 0) {
            out.helpers.push_back(format_name_hex(kX86CpuNumberHelperKey, cpu_number_addr));
            out.helpers.push_back(format_name_hex(kX86ThisCpuOffHelperKey, this_cpu_off_addr));
        }
    }
#elif defined(__aarch64__)
    {
        uint32_t cpu_offset = K_THREAD_INFO_CPU_OFFSET;
        out.helpers.push_back(format_name_hex(kArm64ThreadInfoCpuOffsetHelperKey, cpu_offset));
    }
#endif

    std::vector<std::pair<std::string, uint64_t>> maps(
        map_addrs.begin(), map_addrs.end());
    std::sort(maps.begin(), maps.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });
    for (const auto &kv : maps) {
        out.maps.push_back(format_name_hex(kv.first, 0));
    }

    for (size_t i = 0; i < companion.lookup_sites.size(); i++) {
        out.lookup_sites.push_back(format_lookup_site_arg(i, companion.lookup_sites[i]));
    }
    for (size_t i = 0; i < companion.update_sites.size(); i++) {
        out.update_sites.push_back(format_update_site_arg(i, companion.update_sites[i]));
    }
    return out;
}

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
    hash_file_contents(hash, bpf_obj, "companion_bpf");
    hash_file_identity(hash, link_args.linker, "native_linker");
    hash.add_string(symbol_name);
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
    for (const auto &arg : link_args.update_sites) {
        hash.add_string("update");
        hash.add_string(arg);
    }
    return hash.hex();
}

bool linker_output_exists(const LinkerOutput &out)
{
    std::error_code ec;
    return std::filesystem::exists(out.blob, ec)
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
    std::vector<std::string> argv;
    argv.push_back(link_args.linker.string());
    argv.push_back("--input");
    argv.push_back(elf_path.string());
    argv.push_back("--symbol");
    argv.push_back(symbol_name);

    LinkerOutput out{};
    out.blob = base.string() + ".blob.bin";
    out.relocs = base.string() + ".relocs.bin";
    out.map_patches = base.string() + ".map-patches.tsv";
    out.abi = base.string() + ".abi.tsv";
    argv.push_back("--output");
    argv.push_back(out.blob.string());
    argv.push_back("--output-relocs");
    argv.push_back(out.relocs.string());
    argv.push_back("--output-map-patches");
    argv.push_back(out.map_patches.string());
    argv.push_back("--output-abi");
    argv.push_back(out.abi.string());

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
    for (const auto &arg : link_args.update_sites) {
        argv.push_back("--update-site");
        argv.push_back(arg);
    }

    int rc = run_subprocess(argv);
    if (rc != 0) {
        std::ostringstream msg;
        msg << "native-link failed (rc=" << rc << "): ";
        for (auto &a : argv) msg << a << " ";
        fail(msg.str());
    }
    return out;
}

LinkedBlob load_or_link_native_blob(const cli_options &options,
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
        native_link_cache_key(elf_path, options.program, symbol_name, link_args);
    LinkerOutput cache{};
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
        linked.x86_callee_saved_mask = read_link_abi_file(source.abi);
        const auto read_end = std::chrono::steady_clock::now();
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
    linked.x86_callee_saved_mask = read_link_abi_file(source.abi);
    const auto read_end = std::chrono::steady_clock::now();
    const auto patch_start = std::chrono::steady_clock::now();
    patch_map_literals(linked.blob, map_patches, companion.map_addrs);
    const auto patch_end = std::chrono::steady_clock::now();
    linked.native_link_read_ns = elapsed_ns(read_start, read_end);
    linked.map_patch_ns = elapsed_ns(patch_start, patch_end);
    return linked;
}

uint32_t prog_type_from_option(const std::string &name)
{
    if (name == "xdp") return BPF_PROG_TYPE_XDP;
    if (name == "sched_cls") return BPF_PROG_TYPE_SCHED_CLS;
    if (name == "cgroup_skb") return BPF_PROG_TYPE_CGROUP_SKB;
    fail("unsupported --native-kernel-prog-type: " + name);
    return 0; // unreachable
}

} // namespace

std::vector<sample_result> run_native_kernel(const cli_options &options)
{
    const auto memory_prepare_start = std::chrono::steady_clock::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    if (options.input_size != 0 && input_bytes.size() < options.input_size) {
        input_bytes.resize(options.input_size, 0);
    }
    const auto memory_prepare_end = std::chrono::steady_clock::now();

    const uint32_t prog_type_value = prog_type_from_option(options.native_kernel_prog_type);

    // Packet layout matches what kernel_runner builds for the same prog
    // type (8-byte result prefix for staged/packet xdp, ethernet prefix
    // for skb-context programs).
    const auto pkt_prepare_start = std::chrono::steady_clock::now();
    std::vector<uint8_t> packet = build_packet_input(input_bytes, prog_type_value);
    std::vector<uint8_t> packet_out(packet_output_capacity(options, packet.size()), 0);
    const auto pkt_prepare_end = std::chrono::steady_clock::now();

    /* Stage 2: if the input is an ELF .o, invoke native-link as a
     * subprocess to resolve helper relocations against /proc/kallsyms
     * and produce a blob+relocs pair. Otherwise (Stage 1 path) read the
     * pre-linked blob.bin directly. */
    const auto blob_read_start = std::chrono::steady_clock::now();
    std::vector<uint8_t> blob;
    std::vector<uint8_t> relocs;
    uint32_t x86_callee_saved_mask = 0;
    CompanionLoad companion{};
    uint64_t companion_load_ns = 0;
    uint64_t companion_open_ns = 0;
    uint64_t companion_object_load_ns = 0;
    uint64_t companion_map_ptr_extract_ns = 0;
    uint64_t companion_lookup_spec_ns = 0;
    uint64_t native_link_cache_lookup_ns = 0;
    uint64_t native_link_exec_ns = 0;
    uint64_t native_link_read_ns = 0;
    uint64_t native_link_map_patch_ns = 0;
    if (file_is_elf(options.program)) {
        if (!options.native_program.has_value()) {
            fail("native_kernel: ELF --program requires --native-program");
        }
        if (!options.program_name || options.program_name->empty()) {
            fail("native_kernel requires --program-name");
        }
        const std::string &symbol = *options.program_name;

        const auto companion_load_start = std::chrono::steady_clock::now();
        companion = load_bpf_companion(options.program);
        const auto companion_load_end = std::chrono::steady_clock::now();
        LinkedBlob linked =
            load_or_link_native_blob(options, *options.native_program, symbol, companion);
        companion_load_ns = elapsed_ns(companion_load_start, companion_load_end);
        companion_open_ns = companion.open_ns;
        companion_object_load_ns = companion.object_load_ns;
        companion_map_ptr_extract_ns = companion.map_ptr_extract_ns;
        companion_lookup_spec_ns = companion.lookup_spec_ns;
        native_link_cache_lookup_ns = linked.cache_lookup_ns;
        native_link_exec_ns = linked.native_link_exec_ns;
        native_link_read_ns = linked.native_link_read_ns;
        native_link_map_patch_ns = linked.map_patch_ns;
        x86_callee_saved_mask = linked.x86_callee_saved_mask;
        blob = std::move(linked.blob);
        relocs = std::move(linked.relocs);
    } else {
        blob = read_blob_file(options.program);
    }
    const auto blob_read_end = std::chrono::steady_clock::now();

    const auto upload_start = std::chrono::steady_clock::now();
    ensure_debugfs_mounted();
    uint32_t chunks = upload_blob(blob);
    upload_relocs(relocs, blob.size(), chunks);
    const auto upload_end = std::chrono::steady_clock::now();

    const auto prog_load_start = std::chrono::steady_clock::now();
    NativeStubBtfIds stub_btf = find_native_stub_btf_ids();
    int mod_btf_fd = open_module_btf_fd_by_id(stub_btf.module_btf_id);
    int prog_fd =
        load_stub_prog(stub_btf.kfunc_btf_id, mod_btf_fd, chunks,
                       x86_callee_saved_mask, prog_type_value);
    const auto prog_load_end = std::chrono::steady_clock::now();
    close(mod_btf_fd);

    if (options.dump_jit || options.dump_jit_path.has_value()) {
        const bpf_prog_info prog_info = load_prog_info(prog_fd);
        const auto jited_program = load_jited_program(prog_fd, prog_info.jited_prog_len);
        const auto dump_path = options.dump_jit_path.value_or(
            std::filesystem::path(benchmark_name_for_program(options.program) + ".native_kernel.bin"));
        write_binary_file(dump_path, jited_program.data(), jited_program.size());
    }

    const bool result_from_skb_context =
        prog_type_value == BPF_PROG_TYPE_SCHED_CLS ||
        prog_type_value == BPF_PROG_TYPE_CGROUP_SKB;
    __sk_buff context_out = {};

    // Warmup (1 iteration to populate caches + verify mechanism).
    bpf_test_run_opts warm = {};
    warm.sz = sizeof(warm);
    warm.repeat = 1;
    warm.data_in = packet.data();
    warm.data_size_in = packet.size();
    warm.data_out = packet_out.data();
    warm.data_size_out = packet_out.size();
    if (result_from_skb_context) {
        warm.ctx_out = &context_out;
        warm.ctx_size_out = sizeof(context_out);
    }
    if (bpf_prog_test_run_opts(prog_fd, &warm) < 0) {
        close(prog_fd);
        fail(std::string("warmup test_run failed: ") + std::strerror(errno));
    }

    // Measured run.
    std::fill(packet_out.begin(), packet_out.end(), 0);
    std::memset(&context_out, 0, sizeof(context_out));
    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    test_opts.repeat = options.repeat;
    test_opts.data_in = packet.data();
    test_opts.data_size_in = packet.size();
    test_opts.data_out = packet_out.data();
    test_opts.data_size_out = packet_out.size();
    if (result_from_skb_context) {
        test_opts.ctx_out = &context_out;
        test_opts.ctx_size_out = sizeof(context_out);
    }
    const auto run_start = std::chrono::steady_clock::now();
    const int run_err = bpf_prog_test_run_opts(prog_fd, &test_opts);
    const auto run_end = std::chrono::steady_clock::now();
    if (run_err) {
        close(prog_fd);
        fail(std::string("bpf_prog_test_run_opts failed: ") + std::strerror(errno));
    }

    uint64_t result_word = 0;
    if (result_from_skb_context) {
        result_word = static_cast<uint64_t>(context_out.cb[0]) |
                      (static_cast<uint64_t>(context_out.cb[1]) << 32);
    } else {
        if (packet_out.size() < sizeof(uint64_t)) {
            close(prog_fd);
            fail("native_kernel: packet_out too small to hold u64 result");
        }
        std::memcpy(&result_word, packet_out.data(), sizeof(result_word));
    }

    close(prog_fd);
    /* Companion bpf_object stays open until here so the maps it owns
     * remain valid for the entire test_run. Close now that we have
     * read out the result. */
    if (companion.obj) {
        bpf_object__close(companion.obj);
    }

    sample_result sample;
    sample.compile_ns = elapsed_ns(blob_read_start, blob_read_end)
                      + elapsed_ns(upload_start, upload_end)
                      + elapsed_ns(prog_load_start, prog_load_end);
    sample.exec_ns = test_opts.duration;  // kernel reports per-iter ns
    sample.timing_source = "ktime";
    sample.timing_source_wall = "wall_steady";
    sample.wall_exec_ns = elapsed_ns(run_start, run_end);
    sample.result = result_word;
    sample.retval = test_opts.retval;
    sample.code_size = { .bpf_bytecode_bytes = 0, .native_code_bytes = blob.size() };
    sample.phases_ns = {
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {"packet_prepare_ns", elapsed_ns(pkt_prepare_start, pkt_prepare_end)},
        {"blob_read_ns", elapsed_ns(blob_read_start, blob_read_end)},
        {"companion_load_ns", companion_load_ns},
        {"companion_open_ns", companion_open_ns},
        {"companion_object_load_ns", companion_object_load_ns},
        {"companion_map_ptr_extract_ns", companion_map_ptr_extract_ns},
        {"companion_lookup_spec_ns", companion_lookup_spec_ns},
        {"native_link_cache_lookup_ns", native_link_cache_lookup_ns},
        {"native_link_exec_ns", native_link_exec_ns},
        {"native_link_read_ns", native_link_read_ns},
        {"native_link_map_patch_ns", native_link_map_patch_ns},
        {"blob_upload_ns", elapsed_ns(upload_start, upload_end)},
        {"prog_load_ns", elapsed_ns(prog_load_start, prog_load_end)},
        {"prog_run_wall_ns", elapsed_ns(run_start, run_end)},
    };
    return {std::move(sample)};
}
