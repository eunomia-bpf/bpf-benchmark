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
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <sys/wait.h>
#include <unordered_map>
#include <vector>

namespace {

struct NativeLabTarget {
    const char *module_name;
    const char *kfunc_name;
    const char *module_btf_path;
    const char *debugfs_dir;
    const char *blob_path_fmt;
    const char *relocs_path_fmt;
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

#ifndef BPF_PSEUDO_KINSN_SIDECAR
#define BPF_PSEUDO_KINSN_SIDECAR 3
#endif
#ifndef BPF_PSEUDO_KINSN_CALL
#define BPF_PSEUDO_KINSN_CALL 4
#endif

void ensure_debugfs_mounted()
{
    struct stat st = {};
    if (stat(kNativeLabTarget.debugfs_dir, &st) == 0 && S_ISDIR(st.st_mode)) {
        return;
    }
    (void)mount("none", kDebugfsDir, "debugfs", 0, nullptr);
}

constexpr size_t kRelocRecordBytes = 16;

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
        if (static_cast<size_t>(global_offset) + 5 > blob_size) {
            fail("native_lab reloc call offset exceeds blob bounds");
        }
        uint32_t chunk_id = global_offset / kNativeLabTarget.chunk_bytes;
        uint32_t local_offset = global_offset % kNativeLabTarget.chunk_bytes;
        if (chunk_id >= chunks) {
            fail("native_lab reloc chunk exceeds uploaded blob count");
        }
        if (local_offset + 5 > kNativeLabTarget.chunk_bytes) {
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

// Walk every loaded kernel BTF and return an fd pointing at the native_lab
// module BTF. The caller owns the fd. libbpf doesn't expose a
// direct "find module btf by name" helper, so we iterate BPF_BTF_GET_NEXT_ID.
int find_module_btf_fd()
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
        bpf_btf_info info = {};
        char name[64] = {};
        info.name = reinterpret_cast<uintptr_t>(name);
        info.name_len = sizeof(name);
        uint32_t info_len = sizeof(info);
        if (bpf_obj_get_info_by_fd(fd, &info, &info_len) == 0
            && std::strcmp(name, kNativeLabTarget.module_name) == 0) {
            return fd;
        }
        close(fd);
    }
    fail(std::string("BTF for module ") + kNativeLabTarget.module_name +
         " is not loaded (insmod " + kNativeLabTarget.module_name + ".ko)");
    return -1;
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

// Build the (sidecar; call kinsn)*N; exit stub and BPF_PROG_LOAD it via
// libbpf's bpf_prog_load + bpf_prog_load_opts.fd_array. Returns prog fd.
int load_stub_prog(int kfunc_btf_id, int mod_btf_fd, uint32_t chunks,
                   uint32_t prog_type_value)
{
    if (chunks == 0) {
        fail("chunks must be > 0");
    }
    std::vector<bpf_insn> insns;
    insns.reserve(static_cast<size_t>(2) * chunks + 1);
    for (uint32_t i = 0; i < chunks; i++) {
        bpf_insn sidecar = {
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = 0,
            .src_reg = BPF_PSEUDO_KINSN_SIDECAR,
            .off = 0,
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

/* Look up a symbol address in /proc/kallsyms. Returns 0 on miss. The
 * caller must enable kallsyms readability (kptr_restrict=0 or CAP_SYSLOG;
 * VM has root). */
uint64_t kallsyms_lookup(const std::string &name)
{
    std::ifstream f("/proc/kallsyms");
    if (!f) {
        fail("open /proc/kallsyms: " + std::string(std::strerror(errno)));
    }
    std::string line;
    while (std::getline(f, line)) {
        /* Format: "<hex_addr> <type> <name> [<module>]" */
        if (line.size() < 17) continue;
        size_t addr_end = line.find(' ');
        if (addr_end == std::string::npos) continue;
        size_t type_pos = addr_end + 1;
        if (type_pos >= line.size()) continue;
        size_t name_start = type_pos + 2;
        if (name_start >= line.size()) continue;
        size_t name_end = line.find_first_of(" \t\n", name_start);
        std::string sym_name = line.substr(
            name_start,
            (name_end == std::string::npos) ? std::string::npos : name_end - name_start);
        if (sym_name == name) {
            uint64_t addr = std::strtoull(line.c_str(), nullptr, 16);
            return addr;
        }
    }
    return 0;
}

const struct btf_type *btf_type_by_id_checked(const btf *btf_obj, uint32_t type_id)
{
    const struct btf_type *t = btf__type_by_id(btf_obj, type_id);
    if (!t) {
        fail("btf__type_by_id failed for type id " + std::to_string(type_id));
    }
    return t;
}

uint32_t btf_member_offset_bits_recursive(const btf *btf_obj,
                                          uint32_t type_id,
                                          const std::string &member_name,
                                          uint32_t base_bits,
                                          uint32_t depth)
{
    if (depth > 8) {
        fail("BTF member recursion too deep while looking for " + member_name);
    }
    const struct btf_type *t = btf_type_by_id_checked(btf_obj, type_id);
    while (btf_kind(t) == BTF_KIND_TYPEDEF || btf_kind(t) == BTF_KIND_CONST
           || btf_kind(t) == BTF_KIND_VOLATILE || btf_kind(t) == BTF_KIND_RESTRICT
           || btf_kind(t) == BTF_KIND_TYPE_TAG) {
        t = btf_type_by_id_checked(btf_obj, t->type);
    }
    uint16_t kind = btf_kind(t);
    if (kind != BTF_KIND_STRUCT && kind != BTF_KIND_UNION) {
        return UINT32_MAX;
    }

    const struct btf_member *members = btf_members(t);
    for (uint16_t i = 0; i < btf_vlen(t); i++) {
        const char *name = btf__name_by_offset(btf_obj, members[i].name_off);
        uint32_t off_bits = base_bits + btf_member_bit_offset(t, i);
        if (name && member_name == name) {
            return off_bits;
        }
        uint32_t nested = btf_member_offset_bits_recursive(
            btf_obj, members[i].type, member_name, off_bits, depth + 1);
        if (nested != UINT32_MAX) {
            return nested;
        }
    }
    return UINT32_MAX;
}

uint32_t kernel_btf_member_offset_bytes(const btf *btf_obj,
                                        const std::string &struct_name,
                                        const std::string &member_name)
{
    int type_id = btf__find_by_name_kind(btf_obj, struct_name.c_str(), BTF_KIND_STRUCT);
    if (type_id < 0) {
        fail("kernel BTF struct not found: " + struct_name);
    }
    uint32_t off_bits = btf_member_offset_bits_recursive(
        btf_obj, static_cast<uint32_t>(type_id), member_name, 0, 0);
    if (off_bits == UINT32_MAX) {
        fail("kernel BTF member not found: " + struct_name + "." + member_name);
    }
    if (off_bits % 8 != 0) {
        fail("kernel BTF member is not byte-aligned: " + struct_name + "." + member_name);
    }
    return off_bits / 8;
}

struct BpfArrayOffsets {
    uint32_t value;
    uint32_t pptrs;
};

BpfArrayOffsets read_bpf_array_offsets()
{
    btf *vmlinux = btf__parse(kVmlinuxBtfPath, nullptr);
    if (libbpf_get_error(vmlinux)) {
        fail(std::string("btf__parse vmlinux: ")
             + std::strerror(static_cast<int>(-libbpf_get_error(vmlinux))));
    }
    BpfArrayOffsets out{
        kernel_btf_member_offset_bytes(vmlinux, "bpf_array", "value"),
        kernel_btf_member_offset_bytes(vmlinux, "bpf_array", "pptrs"),
    };
    btf__free(vmlinux);
    return out;
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
};

/* Libbpf-load the canonical `.bpf.o` companion so the kernel allocates
 * maps and verifier rewrites pseudo_ld_imm64 with kernel pointers. Read
 * those pointers back from xlated bytecode + cross-reference against the
 * original bytecode's fd to produce a (map_name -> kernel ptr) table. The
 * caller MUST keep the returned bpf_object alive while the native_kernel
 * run executes -- closing it frees the maps. */
struct CompanionLoad {
    bpf_object *obj = nullptr;
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
     * per-kernel `offsetof(struct htab_elem, key)` extracted from any
     * one HASH map's JIT-emitted `add rax, imm` immediate. ARRAY and
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
};

/* Walk the JITted x86 bytes of a BPF program. Find any `call rel32`
 * whose post-call bytes match the kernel BPF JIT's inlined HASH lookup
 * sequence:
 *     test rax,rax  ;  je <2f>  ;  add rax, KEY_OFFSET  ;  2:
 * Return the first KEY_OFFSET we observe. We don't need to verify the
 * call target equals __htab_map_lookup_elem (which would require
 * jited_ksyms VA computation); the post-call test/je/add shape is
 * specific enough to kernel `htab_map_gen_lookup`. Returns 0 if the
 * pattern isn't found.
 *
 * KEY_OFFSET = `offsetof(struct htab_elem, key) + roundup(map.key_size,
 * 8)` for the map whose lookup got inlined here. Subtract the rounded
 * key_size of that map to derive the kernel-constant base. */
uint32_t extract_htab_inline_offset(const std::vector<uint8_t> &jit)
{
    for (size_t i = 0; i + 5 <= jit.size(); i++) {
        if (jit[i] != 0xE8) continue;
        size_t p = i + 5;
        if (p + 9 > jit.size()) continue;
        if (jit[p] != 0x48 || jit[p+1] != 0x85 || jit[p+2] != 0xC0) continue;
        size_t je_len;
        if (jit[p+3] == 0x74) {
            je_len = 2;
        } else if (jit[p+3] == 0x0F && jit[p+4] == 0x84) {
            je_len = 6;
        } else {
            continue;
        }
        size_t q = p + 3 + je_len;
        if (q + 4 > jit.size()) continue;
        if (jit[q] == 0x48 && jit[q+1] == 0x83 && jit[q+2] == 0xC0) {
            return jit[q+3];
        }
        if (jit[q] == 0x48 && jit[q+1] == 0x81 && jit[q+2] == 0xC0
            && q + 7 <= jit.size()) {
            uint32_t v;
            std::memcpy(&v, &jit[q+3], 4);
            return v;
        }
        if (jit[q] == 0x48 && jit[q+1] == 0x05 && q + 6 <= jit.size()) {
            uint32_t v;
            std::memcpy(&v, &jit[q+2], 4);
            return v;
        }
    }
    return 0;
}

#if defined(__aarch64__)
bool is_arm64_linear_map_ptr(uint64_t value)
{
    return (value >> 48) == 0xffffULL && ((value >> 47) & 1ULL) == 0;
}

bool a64_is_movz64(uint32_t insn)
{
    return (insn & 0xff800000u) == 0xd2800000u;
}

bool a64_is_movn64(uint32_t insn)
{
    return (insn & 0xff800000u) == 0x92800000u;
}

bool a64_is_movk64(uint32_t insn)
{
    return (insn & 0xff800000u) == 0xf2800000u;
}

uint32_t a64_mov_rd(uint32_t insn)
{
    return insn & 0x1fu;
}

uint32_t a64_mov_shift(uint32_t insn)
{
    return ((insn >> 21) & 0x3u) * 16u;
}

uint64_t a64_mov_imm16(uint32_t insn)
{
    return (insn >> 5) & 0xffffu;
}

std::vector<uint64_t> extract_arm64_kernel_mov_immediates(const std::vector<uint8_t> &jit)
{
    std::vector<uint64_t> values;
    if (jit.size() < sizeof(uint32_t)) {
        return values;
    }

    const size_t words = jit.size() / sizeof(uint32_t);
    for (size_t i = 0; i < words; i++) {
        uint32_t word = 0;
        std::memcpy(&word, jit.data() + i * sizeof(uint32_t), sizeof(word));
        if (!a64_is_movz64(word) && !a64_is_movn64(word)) {
            continue;
        }

        const uint32_t rd = a64_mov_rd(word);
        uint64_t value = a64_is_movn64(word) ? ~0ULL : 0ULL;
        const uint32_t shift = a64_mov_shift(word);
        const uint64_t field_mask = 0xffffULL << shift;
        const uint64_t imm = a64_mov_imm16(word) << shift;
        if (a64_is_movn64(word)) {
            value = (value & ~field_mask) | (((~a64_mov_imm16(word)) & 0xffffULL) << shift);
        } else {
            value = (value & ~field_mask) | imm;
        }

        size_t j = i + 1;
        for (; j < words; j++) {
            uint32_t next = 0;
            std::memcpy(&next, jit.data() + j * sizeof(uint32_t), sizeof(next));
            if (!a64_is_movk64(next) || a64_mov_rd(next) != rd) {
                break;
            }
            const uint32_t next_shift = a64_mov_shift(next);
            const uint64_t next_mask = 0xffffULL << next_shift;
            value = (value & ~next_mask) | (a64_mov_imm16(next) << next_shift);
        }

        if (is_arm64_linear_map_ptr(value)) {
            values.push_back(value);
        }
        i = j == i + 1 ? i : j - 1;
    }
    return values;
}
#endif

std::vector<uint64_t> extract_xlated_ldimm64_kernel_ptrs(const std::vector<bpf_insn> &insns)
{
    std::vector<uint64_t> values;
    for (size_t i = 0; i + 1 < insns.size(); i++) {
        if (insns[i].code != (BPF_LD | BPF_DW | BPF_IMM)) {
            continue;
        }
        uint64_t lo = static_cast<uint32_t>(insns[i].imm);
        uint64_t hi = static_cast<uint32_t>(insns[i + 1].imm);
        uint64_t imm64 = lo | (hi << 32);
        if ((imm64 >> 48) == 0xffffULL) {
            values.push_back(imm64);
        }
        i++;
    }
    return values;
}

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
std::vector<int> walk_lookup_call_maps(const struct bpf_insn *insns, size_t cnt)
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
            if (in.imm == BPF_FUNC_map_lookup_elem) {
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

    bpf_object *obj = bpf_object__open_file(bpf_path.c_str(), nullptr);
    if (!obj || libbpf_get_error(obj)) {
        fail(std::string("bpf_object__open_file ") + bpf_path);
    }
    if (bpf_object__load(obj) != 0) {
        bpf_object__close(obj);
        fail(std::string("bpf_object__load ") + bpf_path + ": "
             + std::strerror(errno));
    }

    std::unordered_map<int, std::string> name_by_fd;
    bpf_map *map = nullptr;
    bpf_object__for_each_map(map, obj) {
        int fd = bpf_map__fd(map);
        if (fd >= 0) {
            name_by_fd[fd] = std::string(bpf_map__name(map));
        }
    }

    bpf_program *prog = nullptr;
    bpf_object__for_each_program(prog, obj) {
        int prog_fd = bpf_program__fd(prog);
        if (prog_fd < 0) continue;
        const struct bpf_insn *orig = bpf_program__insns(prog);
        size_t orig_cnt = bpf_program__insn_cnt(prog);

        /* First call: get xlated_prog_len. */
        bpf_prog_info info = {};
        __u32 info_len = sizeof(info);
        if (bpf_obj_get_info_by_fd(prog_fd, &info, &info_len) < 0) continue;
        size_t xlated_cnt = info.xlated_prog_len / sizeof(bpf_insn);
        if (xlated_cnt == 0) continue;
        std::vector<bpf_insn> xlated(xlated_cnt);
        bpf_prog_info info2 = {};
        info2.xlated_prog_len = (uint32_t)(xlated_cnt * sizeof(bpf_insn));
        info2.xlated_prog_insns = reinterpret_cast<uintptr_t>(xlated.data());
        info_len = sizeof(info2);
        if (bpf_obj_get_info_by_fd(prog_fd, &info2, &info_len) < 0) continue;

        (void)xlated_cnt;
        /* Prefer the JIT image because upstream kernels may sanitize
         * xlated map immediates returned through BPF_OBJ_GET_INFO_BY_FD.
         * If this fork returns real map pointers in xlated bytecode, use
         * it as a fallback; xlated LD_IMM64 sites are map-only here, while
         * arm64 JIT immediates can also contain helper/text addresses. */
        bpf_prog_info info_j = {};
        __u32 info_j_len = sizeof(info_j);
        if (bpf_obj_get_info_by_fd(prog_fd, &info_j, &info_j_len) < 0
            || info_j.jited_prog_len == 0) continue;
        std::vector<uint8_t> jit(info_j.jited_prog_len);
        bpf_prog_info info_j2 = {};
        info_j2.jited_prog_len = info_j.jited_prog_len;
        info_j2.jited_prog_insns = reinterpret_cast<uintptr_t>(jit.data());
        info_j_len = sizeof(info_j2);
        if (bpf_obj_get_info_by_fd(prog_fd, &info_j2, &info_j_len) < 0) continue;

        std::vector<int> orig_fds;
        for (size_t i = 0; i + 1 < orig_cnt; i++) {
            if (orig[i].code == (BPF_LD | BPF_DW | BPF_IMM)
                && orig[i].src_reg == BPF_PSEUDO_MAP_FD) {
                orig_fds.push_back(orig[i].imm);
            }
        }

#if defined(__aarch64__)
        std::vector<uint64_t> jit_map_ptrs = extract_arm64_kernel_mov_immediates(jit);
#else
        std::vector<uint64_t> jit_map_ptrs;
        /* x86_64 movabs reg, imm64 encoding:
         *   REX.W=1 (0x48), B=0 -> registers rax..rdi:  48 b8+r <imm64>
         *   REX.W=1, B=1         -> registers r8..r15: 49 b8+r <imm64>
         * Total length is 10 bytes; imm64 occupies the last 8 bytes. */
        for (size_t i = 0; i + 10 <= jit.size(); i++) {
            uint8_t r1 = jit[i];
            uint8_t r2 = jit[i + 1];
            if ((r1 != 0x48 && r1 != 0x49) || r2 < 0xB8 || r2 > 0xBF) continue;
            uint64_t imm = 0;
            std::memcpy(&imm, jit.data() + i + 2, 8);
            if ((imm >> 47) != 0x1FFFFull) continue; /* not canonical kernel high */
            jit_map_ptrs.push_back(imm);
            i += 9; /* advance past this 10-byte movabs */
        }
#endif
        std::vector<uint64_t> xlated_map_ptrs = extract_xlated_ldimm64_kernel_ptrs(xlated);
        if (jit_map_ptrs.size() != orig_fds.size()
            && xlated_map_ptrs.size() == orig_fds.size()) {
            jit_map_ptrs = std::move(xlated_map_ptrs);
        }

        if (orig_fds.size() != jit_map_ptrs.size()) {
            std::fprintf(stderr,
                "[native_kernel] warning: orig has %zu PSEUDO_MAP_FD ld_imm64 but "
                "resolved %zu kernel map pointers; map mapping may be wrong\n",
                orig_fds.size(), jit_map_ptrs.size());
        }
        for (size_t k = 0; k < std::min(orig_fds.size(), jit_map_ptrs.size()); k++) {
            auto it = name_by_fd.find(orig_fds[k]);
            if (it == name_by_fd.end()) continue;
            out.map_addrs[it->second] = jit_map_ptrs[k];
        }
    }

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

        /* Extract htab_elem.key offset (kernel constant) from JIT once.
         * Search across all programs for the inlined HASH lookup
         * pattern; the first match gives us
         *   add_imm = offsetof(htab_elem, key) + roundup(map.key_size, 8)
         * We then derive `htab_elem_key_offset_base` by subtracting the
         * rounded key_size of the first HASH map. All other HASH maps
         * compute their own key_offset = base + roundup(key_size, 8). */
        uint32_t observed_inline_offset = 0;
        bpf_program *pj = nullptr;
        bpf_object__for_each_program(pj, obj) {
            int pfd = bpf_program__fd(pj);
            if (pfd < 0) continue;
            bpf_prog_info pi = {};
            __u32 pi_len = sizeof(pi);
            if (bpf_obj_get_info_by_fd(pfd, &pi, &pi_len) < 0
                || pi.jited_prog_len == 0) continue;
            std::vector<uint8_t> jit(pi.jited_prog_len);
            bpf_prog_info pi2 = {};
            pi2.jited_prog_len = pi.jited_prog_len;
            pi2.jited_prog_insns = reinterpret_cast<uintptr_t>(jit.data());
            pi_len = sizeof(pi2);
            if (bpf_obj_get_info_by_fd(pfd, &pi2, &pi_len) < 0) continue;
            observed_inline_offset = extract_htab_inline_offset(jit);
            if (observed_inline_offset != 0) break;
        }

        uint64_t htab_addr = kallsyms_lookup("__htab_map_lookup_elem");
        BpfArrayOffsets array_offsets = read_bpf_array_offsets();
        uint64_t this_cpu_off_addr = kallsyms_lookup("this_cpu_off");
        uint64_t plain_addr = kallsyms_lookup("bpf_map_lookup_elem");
        if (plain_addr == 0) {
            fail("bpf_map_lookup_elem not in /proc/kallsyms");
        }

        /* Derive htab_elem.key base from the first HASH map's
         * observed inline offset. If the program has no HASH map (or
         * kernel didn't inline any lookup), `observed_inline_offset`
         * is 0 and we skip all inlining. */
        uint32_t htab_key_base = 0;
        bool have_base = false;
        if (observed_inline_offset != 0) {
            uint32_t first_hash_key_rounded = 0;
            map = nullptr;
            bpf_object__for_each_map(map, obj) {
                if (bpf_map__type(map) == BPF_MAP_TYPE_HASH) {
                    uint32_t ks = bpf_map__key_size(map);
                    first_hash_key_rounded = (ks + 7) & ~7u;
                    break;
                }
            }
            if (first_hash_key_rounded > 0
                && observed_inline_offset >= first_hash_key_rounded) {
                htab_key_base = observed_inline_offset - first_hash_key_rounded;
                have_base = true;
            }
        }

        /* Walk the entry program's BPF source bytecode and build the
         * per-call-site spec list. Entry program is identified by
         * libbpf as the first program in iteration order in our test
         * .bpf.o files; pick it explicitly via the first program. */
        bpf_program *entry_prog = nullptr;
        bpf_object__for_each_program(prog, obj) {
            entry_prog = prog;
            break;
        }
        if (entry_prog) {
            const struct bpf_insn *insns = bpf_program__insns(entry_prog);
            size_t insn_cnt = bpf_program__insn_cnt(entry_prog);
            std::vector<int> call_maps = walk_lookup_call_maps(insns, insn_cnt);
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
                        if (this_cpu_off_addr == 0) {
                            fail("this_cpu_off not in /proc/kallsyms");
                        }
                        site.kind = CompanionLoad::LookupSite::Kind::PerCpuArray;
                        site.map_addr = map_it->second;
                        site.max_entries = it->second.max_entries;
                        site.elem_size = sizeof(void *);
                        site.index_mask = roundup_pow2_mask(it->second.max_entries);
                        site.value_offset = array_offsets.pptrs;
                        site.percpu_base_addr = this_cpu_off_addr;
                    } else if (t == BPF_MAP_TYPE_HASH && have_base && htab_addr != 0) {
                        uint32_t rounded = (it->second.key_size + 7) & ~7u;
                        site.kind = CompanionLoad::LookupSite::Kind::Hash;
                        site.target_addr = htab_addr;
                        site.key_offset = htab_key_base + rounded;
                    }
                }
                out.lookup_sites.push_back(site);
            }
        }
    }

    out.obj = obj;
    return out;
}

LinkerOutput invoke_native_link(const cli_options &options,
                                const std::filesystem::path &elf_path,
                                const std::string &symbol_name,
                                const std::unordered_map<std::string, uint64_t> &map_addrs,
                                const CompanionLoad &companion)
{
    std::vector<std::string> argv;
    argv.push_back(native_link_binary(options).string());
    argv.push_back("--input");
    argv.push_back(elf_path.string());
    argv.push_back("--symbol");
    argv.push_back(symbol_name);

    std::string base = "/tmp/native_kernel_" + std::to_string(getpid()) + "_"
                       + elf_path.stem().string();
    LinkerOutput out{};
    out.blob = base + ".blob.bin";
    out.relocs = base + ".relocs.bin";
    argv.push_back("--output");
    argv.push_back(out.blob.string());
    argv.push_back("--output-relocs");
    argv.push_back(out.relocs.string());

    for (const char *h : kSupportedHelpers) {
        uint64_t addr = kallsyms_lookup(h);
        if (addr == 0) continue;
        char buf[128];
        std::snprintf(buf, sizeof(buf), "%s=0x%lx", h, (unsigned long)addr);
        argv.push_back("--helper");
        argv.push_back(buf);
    }
    for (const auto &kv : map_addrs) {
        char buf[160];
        std::snprintf(buf, sizeof(buf), "%s=0x%lx", kv.first.c_str(),
                      (unsigned long)kv.second);
        argv.push_back("--map");
        argv.push_back(buf);
    }
    for (size_t i = 0; i < companion.lookup_sites.size(); i++) {
        const auto &s = companion.lookup_sites[i];
        const char *kind = "call";
        switch (s.kind) {
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
        char buf[256];
        std::snprintf(buf, sizeof(buf), "%zu=%s,0x%lx,%u,0x%lx,%u,%u,%u,%u,0x%lx",
                      i,
                      kind,
                      (unsigned long)s.target_addr,
                      (unsigned)s.key_offset,
                      (unsigned long)s.map_addr,
                      (unsigned)s.max_entries,
                      (unsigned)s.elem_size,
                      (unsigned)s.index_mask,
                      (unsigned)s.value_offset,
                      (unsigned long)s.percpu_base_addr);
        argv.push_back("--lookup-site");
        argv.push_back(buf);
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
    CompanionLoad companion{};
    if (file_is_elf(options.program)) {
        if (!options.native_program.has_value()) {
            fail("native_kernel: ELF --program requires --native-program");
        }
        if (!options.program_name || options.program_name->empty()) {
            fail("native_kernel requires --program-name");
        }
        const std::string &symbol = *options.program_name;

        companion = load_bpf_companion(options.program);
        LinkerOutput lo = invoke_native_link(
            options, *options.native_program, symbol, companion.map_addrs, companion);
        blob = read_blob_file(lo.blob);
        std::ifstream rf(lo.relocs, std::ios::binary);
        if (rf) {
            relocs.assign(std::istreambuf_iterator<char>(rf),
                          std::istreambuf_iterator<char>());
        }
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
    int mod_btf_fd = find_module_btf_fd();
    int kfunc_id = find_kfunc_btf_id();
    int prog_fd = load_stub_prog(kfunc_id, mod_btf_fd, chunks, prog_type_value);
    const auto prog_load_end = std::chrono::steady_clock::now();
    close(mod_btf_fd);

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
        {"blob_upload_ns", elapsed_ns(upload_start, upload_end)},
        {"prog_load_ns", elapsed_ns(prog_load_start, prog_load_end)},
        {"prog_run_wall_ns", elapsed_ns(run_start, run_end)},
    };
    return {std::move(sample)};
}
