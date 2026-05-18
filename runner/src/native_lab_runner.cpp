// Native-lab kernel runner.
//
// Mirrors run_kernel's measurement contract but loads a userspace-linked
// x86 byte blob (produced by ebpf-vm/x86/native_lab/native_link) into a
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

    // fd_array[0] is the verifier's pre-scan slot; daemon convention is to
    // duplicate the module BTF fd there. fd_array[1] is what `off=1` in the
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
 * command line"). For now we hard-code the path under the repo build
 * dir; --native-link-binary on the CLI overrides. */
std::filesystem::path native_link_binary(const cli_options &options)
{
    if (!options.native_lab_linker_path.empty()) {
        return options.native_lab_linker_path;
    }
    /* Default: relative to CWD where the runner is invoked from. */
    return "ebpf-vm/x86/native_lab/native_link/target/release/native-link";
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
    /* Set when at least one map in the program is a BPF_MAP_TYPE_HASH;
     * carries the kernel address of __htab_map_lookup_elem and the
     * post-call `add rax, imm` offset (key offset within struct
     * htab_elem) as extracted from the BPF JIT image. Used to feed
     * native-link's --inline-hash-lookup flag so userspace code matches
     * the kernel JIT's inlined HASH lookup sequence and closes the
     * ~3x gap against `call bpf_map_lookup_elem`. */
    bool hash_inline_set = false;
    uint64_t hash_htab_addr = 0;
    uint32_t hash_key_offset = 0;
};

/* Walk the JITted x86 bytes of a BPF program and find the first
 * `call rel32` whose target equals `htab_addr` (the kernel inlines
 * `__htab_map_lookup_elem` here). Read the bytes immediately after that
 * call to extract the `add rax, imm` offset the kernel emitted -- this
 * is exactly the value we need to feed native-link so its inline
 * sequence matches. Returns 0 if no inlined HASH lookup is found in
 * this JIT image. */
uint32_t extract_htab_key_offset(const std::vector<uint8_t> &jit, uint64_t jit_va_base,
                                 uint64_t htab_addr)
{
    if (htab_addr == 0) return 0;
    /* The runner doesn't know jit_va_base (the kernel VA of the JIT
     * image start); since we only need ABSOLUTE_TARGET = (jit_va_base +
     * call_offset + 5 + rel32), and rel32 is a signed 32-bit offset
     * from the byte AFTER the call, we instead search for the
     * post-call `add rax, imm` pattern paired with the `call`-to-
     * absolute-symbol mapping the kernel module gave us via the JIT
     * image's actual VA. For Stage 2 POC we approximate: the BPF JIT
     * emits a SINGLE inlined `bpf_map_lookup_elem` site per program in
     * our test cases, and it is the only `call rel32` whose immediate
     * `add rax, imm` follows. Scan for that shape. */
    (void)jit_va_base;
    for (size_t i = 0; i + 5 <= jit.size(); i++) {
        if (jit[i] != 0xE8) continue;
        /* candidate `call rel32` site; check whether bytes immediately
         * after the 5-byte call match the inlined `test rax, rax; je;
         * add rax, imm` sequence the kernel BPF JIT emits for an
         * inlined HASH map lookup. */
        size_t p = i + 5;
        if (p + 9 > jit.size()) continue;
        /* test rax, rax = 48 85 c0 */
        if (jit[p] != 0x48 || jit[p+1] != 0x85 || jit[p+2] != 0xC0) continue;
        /* je rel8 = 74 NN  -or-  je rel32 = 0f 84 NN NN NN NN */
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
        /* add rax, imm8  = 48 83 c0 imm8         (4 bytes)
         * add rax, imm32 = 48 81 c0 imm32        (7 bytes, /0 form)
         *               or 48 05 imm32           (6 bytes, rax-special) */
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

CompanionLoad load_bpf_companion(const std::filesystem::path &elf_path)
{
    /* Derive sibling: replace ".native.o" suffix with ".bpf.o". */
    CompanionLoad out{};
    std::string s = elf_path.string();
    const std::string from = ".native.o";
    auto pos = s.rfind(from);
    if (pos == std::string::npos) {
        return out; /* not a .native.o; no companion */
    }
    std::string bpf_path = s.substr(0, pos) + ".bpf.o";
    struct stat st {};
    if (stat(bpf_path.c_str(), &st) != 0) {
        return out; /* no sibling; native blob must be helper-only */
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

    /* Inline-hash detection: if the program contains exactly ONE map
     * AND that map is BPF_MAP_TYPE_HASH, record the inline metadata so
     * native-link can rewrite `bpf_map_lookup_elem` into the inlined
     * `__htab_map_lookup_elem` + `test rax,rax; je; add rax, KEY_OFFSET`
     * sequence the kernel BPF JIT emits.
     *
     * Why the single-map restriction (POC): every
     * `bpf_map_lookup_elem` call site in the program shares ONE
     * literal-pool entry (keyed by the symbol name in native-link).
     * Replacing that pool's value with `__htab_map_lookup_elem`'s
     * address routes EVERY call site to the htab function -- which is
     * correct only if all those call sites target HASH maps. With a
     * single HASH map per program that's guaranteed; with a mixed
     * map population an ARRAY/PERCPU lookup would be misrouted into
     * `__htab_map_lookup_elem` followed by `add rax, KEY_OFFSET`
     * (wrong target + wrong post-call arithmetic). Per-call-site map
     * resolution (rdi def-use backtrace) would lift this restriction,
     * but is out of scope for the Stage 2 POC. */
    bool has_hash_map = false;
    bool has_non_hash_map = false;
    int map_count = 0;
    map = nullptr;
    bpf_object__for_each_map(map, obj) {
        map_count++;
        auto t = bpf_map__type(map);
        if (t == BPF_MAP_TYPE_HASH) {
            has_hash_map = true;
        } else {
            has_non_hash_map = true;
        }
    }
    bool inline_eligible = (map_count == 1) && has_hash_map && !has_non_hash_map;
    if (inline_eligible) {
        uint64_t htab_addr = kallsyms_lookup("__htab_map_lookup_elem");
        if (htab_addr == 0) {
            fail("__htab_map_lookup_elem not in /proc/kallsyms; "
                 "is kallsyms restricted? need CAP_SYSLOG or "
                 "sysctl kernel.kptr_restrict=0");
        }
        /* Walk every program and look for the inlined HASH lookup
         * sequence in its JIT image. We take the first hit; in our
         * test corpus there's exactly one HASH lookup per program. */
        uint32_t key_offset = 0;
        bpf_program *p2 = nullptr;
        bpf_object__for_each_program(p2, obj) {
            int pfd = bpf_program__fd(p2);
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
            key_offset = extract_htab_key_offset(jit, 0, htab_addr);
            if (key_offset != 0) break;
        }
        if (key_offset == 0) {
            fail("HASH map present but could not extract htab key offset "
                 "from JIT image -- the kernel BPF JIT may not have "
                 "inlined the lookup");
        }
        out.hash_inline_set = true;
        out.hash_htab_addr = htab_addr;
        out.hash_key_offset = key_offset;
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
    if (companion.hash_inline_set) {
        char buf[96];
        std::snprintf(buf, sizeof(buf), "0x%lx,%u",
                      (unsigned long)companion.hash_htab_addr,
                      (unsigned)companion.hash_key_offset);
        argv.push_back("--inline-hash-lookup");
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
    initialize_micro_exec_process();

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
        std::string symbol = options.native_lab_symbol;
        if (symbol.empty()) {
            symbol = options.program.stem().string();
        }
        /* Load sibling .bpf.o as an address oracle (if it exists). The
         * bpf_object stays open for the entire native_lab run so the
         * kernel maps it owns remain valid -- our blob references them
         * by raw kernel pointer through a literal-pool slot. */
        companion = load_bpf_companion(options.program);
        LinkerOutput lo = invoke_native_link(
            options, options.program, symbol, companion.map_addrs, companion);
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

    // Warmup (1 iteration to populate caches + verify mechanism).
    bpf_test_run_opts warm = {};
    warm.sz = sizeof(warm);
    warm.repeat = 1;
    warm.data_in = packet.data();
    warm.data_size_in = packet.size();
    warm.data_out = packet_out.data();
    warm.data_size_out = packet_out.size();
    if (bpf_prog_test_run_opts(prog_fd, &warm) < 0) {
        close(prog_fd);
        fail(std::string("warmup test_run failed: ") + std::strerror(errno));
    }

    // Measured run.
    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    test_opts.repeat = options.repeat;
    test_opts.data_in = packet.data();
    test_opts.data_size_in = packet.size();
    test_opts.data_out = packet_out.data();
    test_opts.data_size_out = packet_out.size();
    const auto run_start = std::chrono::steady_clock::now();
    const int run_err = bpf_prog_test_run_opts(prog_fd, &test_opts);
    const auto run_end = std::chrono::steady_clock::now();
    if (run_err) {
        close(prog_fd);
        fail(std::string("bpf_prog_test_run_opts failed: ") + std::strerror(errno));
    }

    // Extract the u64 result from packet_out. For XDP/sched_cls the BPF
    // program sees skb->data at offset 0 of the user packet, so native_lab
    // writes (and we read) at offset 0. For cgroup_skb the kernel
    // bpf_prog_test_run_skb path strips the L2 header during prog setup
    // (`is_l2 = false`) and pushes it back afterwards -- both runtimes write
    // their u64 at byte 14 of the returned packet buffer, which is the
    // start of the L3 payload `build_packet_input` reserves for the result.
    size_t result_off = 0;
    if (prog_type_value == BPF_PROG_TYPE_CGROUP_SKB) {
        result_off = 14; /* kEthernetHeaderSize */
    }
    if (packet_out.size() < result_off + sizeof(uint64_t)) {
        close(prog_fd);
        fail("native_lab: packet_out too small to hold u64 result at offset "
             + std::to_string(result_off));
    }
    uint64_t result_word = 0;
    std::memcpy(&result_word, packet_out.data() + result_off, sizeof(result_word));

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
