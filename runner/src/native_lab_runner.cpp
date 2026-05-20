// Native-lab kernel runner.
//
// Mirrors run_kernel's measurement contract but loads a userspace-linked
// x86 byte blob (produced by native-sim/x86/native_lab/native_link) into a
// minimal BPF stub via the `bpf_x86_native_lab` kinsn. The kinsn splats
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

constexpr const char *kModuleName = "bpf_x86_native_lab";
constexpr const char *kKfuncName = "bpf_x86_native_lab_emit";
constexpr const char *kModuleBtfPath = "/sys/kernel/btf/bpf_x86_native_lab";
constexpr const char *kVmlinuxBtfPath = "/sys/kernel/btf/vmlinux";
constexpr const char *kDebugfsDir = "/sys/kernel/debug";
constexpr const char *kBlobPathFmt = "/sys/kernel/debug/bpf_x86_native_lab/blob%u";
constexpr const char *kRelocsPathFmt = "/sys/kernel/debug/bpf_x86_native_lab/blob%u.relocs";
constexpr uint32_t kChunkBytes = 128;
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
    if (stat("/sys/kernel/debug/bpf_x86_native_lab", &st) == 0 && S_ISDIR(st.st_mode)) {
        return;
    }
    (void)mount("none", kDebugfsDir, "debugfs", 0, nullptr);
}

void upload_relocs(const std::vector<uint8_t> &relocs, uint32_t chunk_id_for_relocs)
{
    /* The .relocs side-band is bound to blob<id>; we always attach it
     * to blob 0 (chunk 0) since for Stage 2 single-chunk blobs the
     * relocations target only the first chunk. Larger blobs would need
     * per-chunk reloc tables -- defer until needed. */
    if (relocs.empty()) {
        return;
    }
    char path[160];
    snprintf(path, sizeof(path), kRelocsPathFmt, chunk_id_for_relocs);
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

uint32_t upload_blob(const std::vector<uint8_t> &blob)
{
    if (blob.empty()) {
        fail("native blob is empty");
    }
    uint32_t chunks = static_cast<uint32_t>((blob.size() + kChunkBytes - 1) / kChunkBytes);
    if (chunks > kMaxBlobs) {
        fail("native blob requires " + std::to_string(chunks) +
             " chunks but module only supports " + std::to_string(kMaxBlobs));
    }
    for (uint32_t i = 0; i < chunks; i++) {
        char path[128];
        snprintf(path, sizeof(path), kBlobPathFmt, i);
        int fd = open(path, O_WRONLY | O_TRUNC);
        if (fd < 0) {
            fail(std::string("open ") + path + ": " + std::strerror(errno));
        }
        size_t off = static_cast<size_t>(i) * kChunkBytes;
        size_t l = std::min<size_t>(kChunkBytes, blob.size() - off);
        ssize_t n = write(fd, blob.data() + off, l);
        int saved = errno;
        close(fd);
        if (n != static_cast<ssize_t>(l)) {
            fail(std::string("write ") + path + ": " + std::strerror(saved));
        }
    }
    return chunks;
}

// Walk every loaded kernel BTF and return an fd pointing at the one named
// `bpf_x86_native_lab`. The caller owns the fd. libbpf doesn't expose a
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
            && std::strcmp(name, kModuleName) == 0) {
            return fd;
        }
        close(fd);
    }
    fail(std::string("BTF for module ") + kModuleName +
         " is not loaded (insmod " + kModuleName + ".ko)");
    return -1;
}

int find_kfunc_btf_id()
{
    struct btf *vmlinux = btf__parse(kVmlinuxBtfPath, nullptr);
    if (libbpf_get_error(vmlinux)) {
        fail(std::string("btf__parse vmlinux: ")
             + std::strerror(static_cast<int>(-libbpf_get_error(vmlinux))));
    }
    struct btf *mod = btf__parse_split(kModuleBtfPath, vmlinux);
    if (libbpf_get_error(mod)) {
        btf__free(vmlinux);
        fail(std::string("btf__parse_split module: ")
             + std::strerror(static_cast<int>(-libbpf_get_error(mod))));
    }
    int id = btf__find_by_name_kind(mod, kKfuncName, BTF_KIND_FUNC);
    btf__free(mod);
    btf__free(vmlinux);
    if (id < 0) {
        fail(std::string("kfunc ") + kKfuncName + " not found in module BTF");
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

/* Path to the native-link binary. The runner invokes it via fork+exec
 * (per project rule "native_lab_runner can only call linker from the
 * command line"). Resolution order:
 *   1. `--native-lab-linker` CLI override.
 *   2. `BPFREJIT_NATIVE_LINK_BINARY` env var.
 *   3. `/usr/local/bin/native-link` if it exists (runtime container
 *      installs the host-built binary here).
 *   4. host repo build path (local non-container debugging). */
std::filesystem::path native_link_binary(const cli_options &options)
{
    if (!options.native_lab_linker_path.empty()) {
        return options.native_lab_linker_path;
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
    return "native-sim/x86/native_lab/native_link/target/release/native-link";
}

/* Stage 2: given an ELF .native.o input, resolve helper kernel addresses
 * via /proc/kallsyms, invoke native-link as a subprocess to produce
 * blob + relocs files. Returns paths to those files. */
struct LinkerOutput {
    std::filesystem::path blob;
    std::filesystem::path relocs;
};

/* If a sibling `.bpf.o` lives next to the `.native.o`, libbpf-load it
 * so the kernel allocates the maps and verifier rewrites pseudo_ld_imm64
 * with kernel pointers. Read those pointers back from xlated bytecode +
 * cross-reference against the original bytecode's fd to produce a
 * (map_name -> kernel ptr) table. The caller MUST keep the returned
 * bpf_object alive while the native_lab runs -- closing it frees the
 * maps. */
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
     * one HASH map's JIT-emitted `add rax, imm` immediate. Maps whose
     * type is ARRAY / PERCPU_ARRAY / LRU_HASH / PERCPU_HASH / dynamic
     * stay on the plain helper (target=bpf_map_lookup_elem, offset=0)
     * since (a) kernel either fully inlines them away into LEA (ARRAY)
     * or (b) doesn't have a map_gen_lookup callback for them. */
    struct LookupSite {
        uint64_t target_addr;
        uint32_t key_offset;
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

/* Normalize the `--program` argument to (companion_bpf_o, native_input).
 *
 * The `make micro` pipeline passes the canonical `.bpf.o` path; the
 * legacy direct-invocation pattern (deprecated, no scripts use it any
 * more) passed `.native.o` or `.native.so` directly. Both work:
 *   - `.bpf.o`        → companion = arg;   native_input = sibling `.native.o` if present, else `.native.so`.
 *   - `.native.{o,so}` → native_input = arg; companion = sibling `.bpf.o` if present, else empty.
 *
 * `companion_bpf_o` may be empty when no `.bpf.o` exists alongside; that
 * is fine for pure-compute programs (Stage 1 of the micro suite) which
 * have no maps or helpers and thus need no kernel-address resolution. */
struct NativeLabPaths {
    std::filesystem::path companion_bpf_o;
    std::filesystem::path native_input;
};

NativeLabPaths resolve_native_lab_paths(const std::filesystem::path &program)
{
    NativeLabPaths out;
    std::string s = program.string();

    auto strip_suffix = [](std::string &str, const char *sfx) -> bool {
        size_t n = std::strlen(sfx);
        if (str.size() >= n && std::memcmp(str.data() + str.size() - n, sfx, n) == 0) {
            str.resize(str.size() - n);
            return true;
        }
        return false;
    };

    std::string base = s;
    if (strip_suffix(base, ".bpf.o")) {
        out.companion_bpf_o = program;
        std::filesystem::path no = base + ".native.o";
        std::filesystem::path nso = base + ".native.so";
        if (std::filesystem::exists(no)) {
            out.native_input = no;
        } else if (std::filesystem::exists(nso)) {
            out.native_input = nso;
        } else {
            fail("native_lab: no .native.o or .native.so sibling for " + s);
        }
    } else if (strip_suffix(base, ".native.o") || strip_suffix(base, ".native.so")) {
        out.native_input = program;
        std::filesystem::path bpfo = base + ".bpf.o";
        if (std::filesystem::exists(bpfo)) {
            out.companion_bpf_o = bpfo;
        }
    } else {
        fail("native_lab: --program must end in .bpf.o, .native.o, or .native.so: " + s);
    }
    return out;
}

CompanionLoad load_bpf_companion(const std::filesystem::path &bpf_o_path)
{
    /* `bpf_o_path` is the `.bpf.o` companion directly. Returns an empty
     * CompanionLoad if the file doesn't exist (pure-compute programs
     * without maps/helpers don't need a companion). */
    CompanionLoad out{};
    struct stat st {};
    std::string bpf_path = bpf_o_path.string();
    if (stat(bpf_path.c_str(), &st) != 0) {
        return out; /* no companion; native blob must be helper-free */
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

        (void)xlated_cnt; (void)xlated; /* xlated path retained for future use */
        /* Kernel sanitizes xlated bytecode for ld_imm64 map refs (the
         * imm is overwritten with map->id, not the kernel ptr). Read
         * the JITted x86 bytes instead -- they aren't sanitized -- and
         * find every `movabs reg, imm64` whose imm64 lies in the
         * canonical kernel upper half. JIT emits exactly one such
         * movabs per PSEUDO_MAP_FD ld_imm64 (helpers go through
         * `call rel32`, not movabs). Pair them with the corresponding
         * map fd in ORIG by ordinal position. */
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

        if (orig_fds.size() != jit_map_ptrs.size()) {
            std::fprintf(stderr,
                "[native_lab] warning: orig has %zu PSEUDO_MAP_FD ld_imm64 but "
                "jited has %zu kernel-half movabs imm64; map mapping may be wrong\n",
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
        struct MapMeta { std::string name; int type; uint32_t key_size; };
        std::unordered_map<int, MapMeta> meta_by_fd;
        map = nullptr;
        bpf_object__for_each_map(map, obj) {
            int fd = bpf_map__fd(map);
            if (fd >= 0) {
                meta_by_fd[fd] = MapMeta{
                    std::string(bpf_map__name(map)),
                    (int)bpf_map__type(map),
                    bpf_map__key_size(map),
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
                CompanionLoad::LookupSite site{plain_addr, 0};
                auto it = (fd >= 0) ? meta_by_fd.find(fd) : meta_by_fd.end();
                if (it != meta_by_fd.end()) {
                    int t = it->second.type;
                    if (t == BPF_MAP_TYPE_HASH && have_base && htab_addr != 0) {
                        uint32_t rounded = (it->second.key_size + 7) & ~7u;
                        site.target_addr = htab_addr;
                        site.key_offset = htab_key_base + rounded;
                    }
                    /* Other map types: kernel may have inline expansions
                     * (LRU_HASH on >=5.7, PERCPU_HASH on some kernels,
                     * ARRAY fully inlined to LEA). For POC we keep
                     * the plain bpf_map_lookup_elem call site (no
                     * inline) for everything except plain HASH; the
                     * cost is correctness-preserving and bounded
                     * (~20-30 ns per non-HASH lookup vs the
                     * kernel JIT). Extending to LRU_HASH/PERCPU_HASH
                     * is a follow-up. */
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

    std::string base = "/tmp/native_lab_" + std::to_string(getpid()) + "_"
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
        char buf[96];
        std::snprintf(buf, sizeof(buf), "%zu=0x%lx,%u",
                      i,
                      (unsigned long)s.target_addr,
                      (unsigned)s.key_offset);
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
    fail("unsupported --native-lab-prog-type: " + name);
    return 0; // unreachable
}

} // namespace

std::vector<sample_result> run_kernel_native_lab(const cli_options &options)
{
    const auto memory_prepare_start = std::chrono::steady_clock::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    if (options.input_size != 0 && input_bytes.size() < options.input_size) {
        input_bytes.resize(options.input_size, 0);
    }
    const auto memory_prepare_end = std::chrono::steady_clock::now();

    const uint32_t prog_type_value = prog_type_from_option(options.native_lab_prog_type);

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
        /* Resolve `.bpf.o` (companion, for map-ptr + per-call lookup
         * spec) and `.native.{o,so}` (native-link input) from whichever
         * suffix the caller passed. The micro pipeline passes `.bpf.o`;
         * direct invocations may pass `.native.{o,so}`. */
        auto paths = resolve_native_lab_paths(options.program);

        /* Symbol selection precedence:
         *   1. `--program-name <X>` (micro pipeline canonical)
         *   2. `--native-lab-symbol <X>` (legacy flag, still accepted)
         *   3. derive from native_input filename stem, stripping a
         *      trailing `.native` segment if present. */
        std::string symbol;
        if (options.program_name && !options.program_name->empty()) {
            symbol = *options.program_name;
        } else if (!options.native_lab_symbol.empty()) {
            symbol = options.native_lab_symbol;
        } else {
            std::string stem = paths.native_input.stem().string();
            const std::string nat = ".native";
            if (stem.size() >= nat.size()
                && stem.compare(stem.size() - nat.size(), nat.size(), nat) == 0) {
                stem.resize(stem.size() - nat.size());
            }
            symbol = stem;
        }

        if (!paths.companion_bpf_o.empty()) {
            companion = load_bpf_companion(paths.companion_bpf_o);
        }
        LinkerOutput lo = invoke_native_link(
            options, paths.native_input, symbol, companion.map_addrs, companion);
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
    upload_relocs(relocs, /*chunk_id_for_relocs=*/0);
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
            fail("native_lab: packet_out too small to hold u64 result");
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
