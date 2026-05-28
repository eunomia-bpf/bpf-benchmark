/*
 * Standalone native_lab attach harness implementation.
 *
 * Pipeline (per nl_load_and_attach call):
 *   1. libbpf-load the companion .bpf.o so the kernel allocates the
 *      count_map. We need its fd (for the stub's fd_array) and its
 *      kernel-virtual address (for native-link to patch &count_map
 *      references inside the .native.o).
 *   2. Walk the .bpf.o's JIT image to find the kernel map_ptr embedded
 *      as a `movabs reg, imm64` -- the verifier rewrites PSEUDO_MAP_FD
 *      ld_imm64 to this canonical kernel-half pointer.
 *   3. Resolve every BPF helper used by the program from /proc/kallsyms.
 *   4. Write a typed native-link plan and fork+exec native-link.
 *   5. Upload the resulting blob (and reloc table, if any) into
 *      /sys/kernel/debug/bpf_x86_native_lab/blob<N>[.relocs].
 *   6. Build a stub program `(sidecar; call kinsn)*chunks; exit` with
 *      prog_type set to KPROBE / RAW_TRACEPOINT, fd_array containing
 *      the module BTF fd and the count_map fd, and BPF_PROG_LOAD it.
 *   7. Attach the resulting prog_fd via the perf_event_open ABI
 *      (kprobe / uprobe) or bpf_raw_tracepoint_open (raw_tp).
 *
 * Function bodies for steps (5)-(6) and the helpers in (3)-(4) are
 * copied from runner/src/native_lab_runner.cpp -- the user wanted
 * test-others/ to be standalone, so the duplication is intentional.
 */
#include "native_lab_attach.hpp"

#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <climits>
#include <linux/bpf.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <unistd.h>
#include <unordered_map>
#include <utility>
#include <vector>

#ifndef BPF_PSEUDO_KINSN_SIDECAR
#define BPF_PSEUDO_KINSN_SIDECAR 3
#endif
#ifndef BPF_PSEUDO_KINSN_CALL
#define BPF_PSEUDO_KINSN_CALL 4
#endif

namespace {

constexpr const char *kModuleName = "bpf_x86_native_lab";
constexpr const char *kKfuncName = "bpf_x86_native_lab_emit";
constexpr const char *kModuleBtfPath = "/sys/kernel/btf/bpf_x86_native_lab";
constexpr const char *kVmlinuxBtfPath = "/sys/kernel/btf/vmlinux";
constexpr const char *kBlobPathFmt = "/sys/kernel/debug/bpf_x86_native_lab/blob%u";
constexpr const char *kRelocsPathFmt = "/sys/kernel/debug/bpf_x86_native_lab/blob%u.relocs";
constexpr uint32_t kChunkBytes = 128;

/* Helper set required by every test-others program. (kprobe_getpid /
 * uprobe_self / tracepoint_sched_switch all use lookup+update on a
 * single HASH map; the atomic add compiles to a pointer-deref add, not
 * a helper.) */
const std::vector<const char *> kHelpers = {
    "bpf_map_lookup_elem",
    "bpf_map_update_elem",
};

void perror_fail(const char *what)
{
    std::fprintf(stderr, "nl: %s: %s\n", what, std::strerror(errno));
}

int ensure_debugfs_mounted()
{
    struct stat st = {};
    if (stat("/sys/kernel/debug/bpf_x86_native_lab", &st) == 0 && S_ISDIR(st.st_mode)) {
        return 0;
    }
    /* debugfs is usually already mounted in the runtime container; the
     * runner mounts it explicitly only when running as root in a fresh
     * VM. Don't fail if mount returns EBUSY/EPERM -- a missing
     * blob<N> path will surface a clearer error later. */
    (void)mount("none", "/sys/kernel/debug", "debugfs", 0, nullptr);
    return 0;
}

int upload_blob(const std::vector<uint8_t> &blob, uint32_t *chunks_out)
{
    if (blob.empty()) {
        std::fprintf(stderr, "nl: native blob is empty\n");
        return -1;
    }
    uint32_t chunks = static_cast<uint32_t>((blob.size() + kChunkBytes - 1) / kChunkBytes);
    for (uint32_t i = 0; i < chunks; i++) {
        char path[128];
        std::snprintf(path, sizeof(path), kBlobPathFmt, i);
        int fd = open(path, O_WRONLY | O_TRUNC);
        if (fd < 0) {
            std::fprintf(stderr, "nl: open %s: %s\n", path, std::strerror(errno));
            return -1;
        }
        size_t off = static_cast<size_t>(i) * kChunkBytes;
        size_t l = std::min<size_t>(kChunkBytes, blob.size() - off);
        ssize_t n = write(fd, blob.data() + off, l);
        int saved = errno;
        close(fd);
        if (n != static_cast<ssize_t>(l)) {
            std::fprintf(stderr, "nl: write %s: %s\n", path, std::strerror(saved));
            return -1;
        }
    }
    *chunks_out = chunks;
    return 0;
}

int upload_relocs(const std::vector<uint8_t> &relocs)
{
    if (relocs.empty()) return 0;
    char path[160];
    std::snprintf(path, sizeof(path), kRelocsPathFmt, 0u);
    int fd = open(path, O_WRONLY | O_TRUNC);
    if (fd < 0) {
        std::fprintf(stderr, "nl: open %s: %s\n", path, std::strerror(errno));
        return -1;
    }
    ssize_t n = write(fd, relocs.data(), relocs.size());
    int saved = errno;
    close(fd);
    if (n != static_cast<ssize_t>(relocs.size())) {
        std::fprintf(stderr, "nl: write %s: %s\n", path, std::strerror(saved));
        return -1;
    }
    return 0;
}

int find_module_btf_fd()
{
    uint32_t id = 0;
    for (;;) {
        uint32_t next = 0;
        if (bpf_btf_get_next_id(id, &next) < 0) {
            if (errno == ENOENT) break;
            perror_fail("bpf_btf_get_next_id");
            return -1;
        }
        id = next;
        int fd = bpf_btf_get_fd_by_id(id);
        if (fd < 0) continue;
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
    std::fprintf(stderr, "nl: module %s BTF not loaded (insmod %s.ko?)\n",
                 kModuleName, kModuleName);
    return -1;
}

int find_kfunc_btf_id()
{
    struct btf *vmlinux = btf__parse(kVmlinuxBtfPath, nullptr);
    if (libbpf_get_error(vmlinux)) {
        std::fprintf(stderr, "nl: btf__parse vmlinux failed\n");
        return -1;
    }
    struct btf *mod = btf__parse_split(kModuleBtfPath, vmlinux);
    if (libbpf_get_error(mod)) {
        btf__free(vmlinux);
        std::fprintf(stderr, "nl: btf__parse_split module failed\n");
        return -1;
    }
    int id = btf__find_by_name_kind(mod, kKfuncName, BTF_KIND_FUNC);
    btf__free(mod);
    btf__free(vmlinux);
    return id;
}

int load_stub_prog(int kfunc_btf_id, int mod_btf_fd, uint32_t chunks,
                   uint32_t prog_type_value, int count_map_fd)
{
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

    /* fd_array layout: [mod_btf_fd, mod_btf_fd, count_map_fd]. The
     * verifier-side fd_array[0] is the module BTF for pseudo_btf_id
     * resolution; fd_array[1] is what `off=1` in the kinsn call insn
     * resolves to (same module BTF); fd_array[2] keeps count_map
     * alive across BPF_PROG_LOAD even though the stub bytecode itself
     * doesn't reference it -- the inner native blob does, via the
     * map_ptr literal native-link patched in. */
    int fd_array[3] = {mod_btf_fd, mod_btf_fd, count_map_fd};
    std::vector<char> log_buf(64 * 1024, '\0');

    LIBBPF_OPTS(bpf_prog_load_opts, opts,
        .fd_array = fd_array,
        .log_level = 1,
        .log_size = static_cast<uint32_t>(log_buf.size()),
        .log_buf = log_buf.data(),
        .fd_array_cnt = 3,
    );
    int fd = bpf_prog_load(static_cast<bpf_prog_type>(prog_type_value),
                           "nl_others_stub", "GPL",
                           insns.data(), insns.size(), &opts);
    if (fd < 0) {
        std::fprintf(stderr, "nl: bpf_prog_load: %s\nverifier log:\n%s\n",
                     std::strerror(errno), log_buf.data());
        return -1;
    }
    return fd;
}

void write_json_string(std::ostream &out, const std::string &s)
{
    out << '"';
    for (unsigned char c : s) {
        switch (c) {
        case '"': out << "\\\""; break;
        case '\\': out << "\\\\"; break;
        case '\b': out << "\\b"; break;
        case '\f': out << "\\f"; break;
        case '\n': out << "\\n"; break;
        case '\r': out << "\\r"; break;
        case '\t': out << "\\t"; break;
        default:
            if (c < 0x20) {
                char buf[8];
                std::snprintf(buf, sizeof(buf), "\\u%04x", c);
                out << buf;
            } else {
                out << static_cast<char>(c);
            }
            break;
        }
    }
    out << '"';
}

int write_link_plan(const std::string &path,
                    const std::vector<std::pair<std::string, uint64_t>> &helpers,
                    uint64_t count_map_addr)
{
    std::ofstream out(path, std::ios::trunc);
    if (!out) {
        std::fprintf(stderr, "nl: open %s: %s\n", path.c_str(), std::strerror(errno));
        return -1;
    }
    out << "{\n  \"version\": 1,\n  \"helpers\": [\n";
    for (size_t i = 0; i < helpers.size(); i++) {
        out << "    {\"name\": ";
        write_json_string(out, helpers[i].first);
        out << ", \"addr\": " << helpers[i].second << "}";
        if (i + 1 != helpers.size()) out << ",";
        out << "\n";
    }
    out << "  ],\n  \"maps\": [\n    {\"name\": \"count_map\", \"addr\": "
        << count_map_addr << "}\n  ]\n}\n";
    if (!out) {
        std::fprintf(stderr, "nl: write %s failed\n", path.c_str());
        return -1;
    }
    return 0;
}

uint64_t kallsyms_lookup(const std::string &name)
{
    std::ifstream f("/proc/kallsyms");
    if (!f) return 0;
    std::string line;
    while (std::getline(f, line)) {
        size_t sp1 = line.find(' ');
        if (sp1 == std::string::npos) continue;
        size_t name_start = sp1 + 3;  /* skip "X " where X is type letter */
        if (name_start >= line.size()) continue;
        size_t name_end = line.find_first_of(" \t\n", name_start);
        std::string sym = (name_end == std::string::npos)
            ? line.substr(name_start)
            : line.substr(name_start, name_end - name_start);
        if (sym == name) {
            return std::strtoull(line.c_str(), nullptr, 16);
        }
    }
    return 0;
}

int run_subprocess(const std::vector<std::string> &argv)
{
    if (argv.empty()) return -1;
    std::vector<char *> raw;
    for (auto &s : argv) raw.push_back(const_cast<char *>(s.c_str()));
    raw.push_back(nullptr);
    pid_t pid = fork();
    if (pid < 0) return -1;
    if (pid == 0) {
        execv(raw[0], raw.data());
        std::fprintf(stderr, "execv %s: %s\n", raw[0], std::strerror(errno));
        _exit(127);
    }
    int status = 0;
    if (waitpid(pid, &status, 0) < 0) return -1;
    return WIFEXITED(status) ? WEXITSTATUS(status) : -1;
}

std::string native_link_binary()
{
    if (const char *e = std::getenv("BPFREJIT_NATIVE_LINK_BINARY")) {
        if (e[0]) return e;
    }
    struct stat st{};
    if (stat("/usr/local/bin/native-link", &st) == 0) {
        return "/usr/local/bin/native-link";
    }
    /* Test-others runs against a host-side build; resolve relative to
     * the repo root via the well-known path. */
    return "native-sim/x86/native_lab/native_link/target/release/native-link";
}

/* Walk the JIT image of a libbpf-loaded program and return the kernel
 * virtual address that the verifier rewrote PSEUDO_MAP_FD references
 * to. Test-others programs have exactly one map per program. */
int extract_single_map_kernel_addr(int prog_fd, uint64_t *addr_out)
{
    bpf_prog_info info = {};
    uint32_t info_len = sizeof(info);
    if (bpf_obj_get_info_by_fd(prog_fd, &info, &info_len) < 0) {
        perror_fail("bpf_obj_get_info_by_fd (size probe)");
        return -1;
    }
    if (info.jited_prog_len == 0) {
        std::fprintf(stderr, "nl: program has no JIT (BPF_JIT_ALWAYS_ON?)\n");
        return -1;
    }
    std::vector<uint8_t> jit(info.jited_prog_len);
    bpf_prog_info info2 = {};
    info2.jited_prog_len = info.jited_prog_len;
    info2.jited_prog_insns = reinterpret_cast<uintptr_t>(jit.data());
    info_len = sizeof(info2);
    if (bpf_obj_get_info_by_fd(prog_fd, &info2, &info_len) < 0) {
        perror_fail("bpf_obj_get_info_by_fd (jit fetch)");
        return -1;
    }
    /* x86_64 `movabs reg, imm64` is 10 bytes. We look for any
     * movabs whose imm64 lies in the canonical kernel upper half
     * (bits 63..47 all set). JIT emits exactly one of these per
     * PSEUDO_MAP_FD ld_imm64 (helpers go through `call rel32`, not
     * movabs); test-others programs have a single map. */
    for (size_t i = 0; i + 10 <= jit.size(); i++) {
        uint8_t r1 = jit[i];
        uint8_t r2 = jit[i + 1];
        if ((r1 != 0x48 && r1 != 0x49) || r2 < 0xB8 || r2 > 0xBF) continue;
        uint64_t imm = 0;
        std::memcpy(&imm, jit.data() + i + 2, 8);
        if ((imm >> 47) != 0x1FFFFull) continue;
        *addr_out = imm;
        return 0;
    }
    std::fprintf(stderr, "nl: no kernel map_ptr movabs found in JIT image\n");
    return -1;
}

/* Build the `.native.o` path from the `.bpf.o` path (sibling). */
std::string native_o_from_bpf_o(const std::string &bpf_o)
{
    std::string s = bpf_o;
    const std::string suffix = ".bpf.o";
    if (s.size() >= suffix.size()
        && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0) {
        s.resize(s.size() - suffix.size());
        s += ".native.o";
        return s;
    }
    return bpf_o + ".native.o";
}

uint32_t map_prog_type(const char *mode)
{
    if (std::strcmp(mode, "kprobe") == 0 || std::strcmp(mode, "uprobe") == 0) {
        return BPF_PROG_TYPE_KPROBE;
    }
    if (std::strcmp(mode, "raw_tp") == 0) {
        return BPF_PROG_TYPE_RAW_TRACEPOINT;
    }
    std::fprintf(stderr, "nl: unknown mode %s\n", mode);
    return 0;
}

/* perf_event_open syscall wrapper (no glibc stub). */
long perf_event_open_syscall(struct perf_event_attr *attr, pid_t pid, int cpu,
                             int group_fd, unsigned long flags)
{
    return syscall(__NR_perf_event_open, attr, pid, cpu, group_fd, flags);
}

/* Attach `prog_fd` to a kernel kprobe on `sym`. Uses the kernel's
 * dynamic kprobe-events sysfs interface so we don't need
 * KPROBE_MULTI / fd-based BPF_LINK_CREATE (works on older 5.x kernels).
 * Writes the events line to `out->probe_events_line` so nl_close can
 * remove it. */
int attach_kprobe(int prog_fd, const char *sym, NlSession *out)
{
    std::ostringstream name_oss;
    name_oss << "nl_others_kp_" << getpid() << "_" << sym;
    std::string name = name_oss.str();
    std::ostringstream line_oss;
    line_oss << "p:" << name << " " << sym;
    std::string events_line = line_oss.str();

    const char *events_path = "/sys/kernel/debug/tracing/kprobe_events";
    int fd = open(events_path, O_WRONLY | O_APPEND);
    if (fd < 0) {
        std::fprintf(stderr, "nl: open %s: %s\n", events_path, std::strerror(errno));
        return -1;
    }
    if (write(fd, events_line.c_str(), events_line.size()) < 0) {
        std::fprintf(stderr, "nl: write kprobe_events: %s\n", std::strerror(errno));
        close(fd);
        return -1;
    }
    close(fd);
    out->probe_events_line = "-:" + name;
    out->probe_events_path = events_path;

    std::ostringstream id_path_oss;
    id_path_oss << "/sys/kernel/debug/tracing/events/kprobes/" << name << "/id";
    std::ifstream id_f(id_path_oss.str());
    if (!id_f) {
        std::fprintf(stderr, "nl: open %s\n", id_path_oss.str().c_str());
        return -1;
    }
    uint64_t tp_id = 0;
    id_f >> tp_id;

    perf_event_attr attr = {};
    attr.type = PERF_TYPE_TRACEPOINT;
    attr.size = sizeof(attr);
    attr.config = tp_id;
    attr.sample_period = 1;
    long perf_fd = perf_event_open_syscall(&attr, -1, 0, -1, PERF_FLAG_FD_CLOEXEC);
    if (perf_fd < 0) { perror_fail("perf_event_open(kprobe)"); return -1; }
    if (ioctl(perf_fd, PERF_EVENT_IOC_SET_BPF, prog_fd) < 0) {
        perror_fail("ioctl PERF_EVENT_IOC_SET_BPF");
        close(perf_fd);
        return -1;
    }
    if (ioctl(perf_fd, PERF_EVENT_IOC_ENABLE, 0) < 0) {
        perror_fail("ioctl PERF_EVENT_IOC_ENABLE");
        close(perf_fd);
        return -1;
    }
    out->attach_fd = static_cast<int>(perf_fd);
    return 0;
}

/* Convert a process-virtual address (e.g. &uprobe_target) to the
 * corresponding file offset within /proc/self/exe by scanning
 * /proc/self/maps. Returns 0 on miss. */
uint64_t addr_to_self_exe_offset(uint64_t addr)
{
    std::ifstream f("/proc/self/maps");
    std::string line;
    char self_path[PATH_MAX];
    ssize_t r = readlink("/proc/self/exe", self_path, sizeof(self_path) - 1);
    if (r < 0) return 0;
    self_path[r] = 0;
    while (std::getline(f, line)) {
        unsigned long start = 0, end = 0, off = 0;
        char perms[8] = {0};
        char path_buf[PATH_MAX] = {0};
        int n = std::sscanf(line.c_str(), "%lx-%lx %7s %lx %*x:%*x %*u %[^\n]",
                            &start, &end, perms, &off, path_buf);
        if (n < 5) continue;
        if (std::strcmp(path_buf, self_path) != 0) continue;
        if (perms[2] != 'x') continue;
        if (addr >= start && addr < end) {
            return off + (addr - start);
        }
    }
    return 0;
}

/* Attach kprobe-type prog as a uprobe via /sys/kernel/debug/tracing/
 * uprobe_events. Uses a runtime address (from &symbol) instead of nm
 * symbol-table lookup -- the test-others harness picks the address
 * directly via &uprobe_target, which works regardless of whether the
 * vng overlay ships binutils. */
int attach_uprobe_at(int prog_fd, uint64_t addr, int pid, NlSession *out)
{
    uint64_t off = addr_to_self_exe_offset(addr);
    if (off == 0) {
        std::fprintf(stderr, "nl: cannot map addr 0x%lx to /proc/self/exe offset\n",
                     static_cast<unsigned long>(addr));
        return -1;
    }
    char self_path[PATH_MAX];
    ssize_t r = readlink("/proc/self/exe", self_path, sizeof(self_path) - 1);
    if (r < 0) { perror_fail("readlink /proc/self/exe"); return -1; }
    self_path[r] = 0;
    char func_name[32];
    std::snprintf(func_name, sizeof(func_name), "off_0x%lx",
                  static_cast<unsigned long>(off));

    std::ostringstream name_oss;
    name_oss << "nl_others_up_" << getpid() << "_" << func_name;
    std::string name = name_oss.str();
    std::ostringstream line_oss;
    line_oss << "p:" << name << " " << self_path << ":0x" << std::hex << off;
    std::string events_line = line_oss.str();

    const char *events_path = "/sys/kernel/debug/tracing/uprobe_events";
    int fd = open(events_path, O_WRONLY | O_APPEND);
    if (fd < 0) {
        std::fprintf(stderr, "nl: open %s: %s\n", events_path, std::strerror(errno));
        return -1;
    }
    if (write(fd, events_line.c_str(), events_line.size()) < 0) {
        std::fprintf(stderr, "nl: write uprobe_events: %s\n", std::strerror(errno));
        close(fd);
        return -1;
    }
    close(fd);
    out->probe_events_line = "-:" + name;
    out->probe_events_path = events_path;

    std::ostringstream id_path_oss;
    id_path_oss << "/sys/kernel/debug/tracing/events/uprobes/" << name << "/id";
    std::ifstream id_f(id_path_oss.str());
    if (!id_f) {
        std::fprintf(stderr, "nl: open %s\n", id_path_oss.str().c_str());
        return -1;
    }
    uint64_t tp_id = 0;
    id_f >> tp_id;

    perf_event_attr attr = {};
    attr.type = PERF_TYPE_TRACEPOINT;
    attr.size = sizeof(attr);
    attr.config = tp_id;
    attr.sample_period = 1;
    long perf_fd = perf_event_open_syscall(&attr, pid, -1, -1, PERF_FLAG_FD_CLOEXEC);
    if (perf_fd < 0) {
        perror_fail("perf_event_open(uprobe)");
        return -1;
    }
    if (ioctl(perf_fd, PERF_EVENT_IOC_SET_BPF, prog_fd) < 0) {
        perror_fail("ioctl PERF_EVENT_IOC_SET_BPF (uprobe)");
        close(perf_fd);
        return -1;
    }
    if (ioctl(perf_fd, PERF_EVENT_IOC_ENABLE, 0) < 0) {
        perror_fail("ioctl PERF_EVENT_IOC_ENABLE (uprobe)");
        close(perf_fd);
        return -1;
    }
    out->attach_fd = static_cast<int>(perf_fd);
    return 0;
}

int attach_raw_tp(int prog_fd, const char *tp_name, NlSession *out)
{
    int rtp_fd = bpf_raw_tracepoint_open(tp_name, prog_fd);
    if (rtp_fd < 0) {
        perror_fail("bpf_raw_tracepoint_open");
        return -1;
    }
    out->attach_fd = rtp_fd;
    return 0;
}

/* Steps (1)-(6) of the native_lab attach pipeline: load the companion
 * .bpf.o, extract the map's kernel address from its JIT image, resolve
 * helpers via kallsyms, invoke native-link, upload the blob+relocs into
 * the kinsn module's debugfs, and BPF_PROG_LOAD the (sidecar; call
 * kinsn)*N; exit stub program with the supplied prog_type. The caller
 * runs the attach step appropriate for its event type. */
int nl_load_only(const char *bpf_o_path, const char *prog_name,
                 uint32_t prog_type, NlSession *out)
{
    *out = NlSession{};

    bpf_object *obj = bpf_object__open_file(bpf_o_path, nullptr);
    if (!obj || libbpf_get_error(obj)) {
        std::fprintf(stderr, "nl: bpf_object__open_file %s\n", bpf_o_path);
        return -1;
    }
    if (bpf_object__load(obj) != 0) {
        std::fprintf(stderr, "nl: bpf_object__load: %s\n", std::strerror(errno));
        bpf_object__close(obj);
        return -1;
    }
    out->companion = obj;

    bpf_map *cm = bpf_object__find_map_by_name(obj, "count_map");
    if (!cm) {
        std::fprintf(stderr, "nl: count_map not in companion .bpf.o\n");
        return -1;
    }
    out->count_map_fd = bpf_map__fd(cm);

    bpf_program *prog = bpf_object__find_program_by_name(obj, prog_name);
    if (!prog) {
        std::fprintf(stderr, "nl: program %s not in companion .bpf.o\n", prog_name);
        return -1;
    }
    int companion_prog_fd = bpf_program__fd(prog);
    uint64_t map_kaddr = 0;
    if (extract_single_map_kernel_addr(companion_prog_fd, &map_kaddr) != 0) {
        return -1;
    }

    std::vector<std::pair<std::string, uint64_t>> helper_addrs;
    for (const char *h : kHelpers) {
        uint64_t addr = kallsyms_lookup(h);
        if (addr == 0) {
            std::fprintf(stderr, "nl: kallsyms miss %s\n", h);
            return -1;
        }
        helper_addrs.emplace_back(h, addr);
    }

    std::string native_o = native_o_from_bpf_o(bpf_o_path);
    char tmpl_plan[] = "/tmp/nl_others_XXXXXX.link-plan.json";
    char tmpl_blob[] = "/tmp/nl_others_XXXXXX.blob";
    char tmpl_rel[] = "/tmp/nl_others_XXXXXX.relocs";
    int p_fd = mkstemps(tmpl_plan, 15);
    int b_fd = mkstemps(tmpl_blob, 5);
    int r_fd = mkstemps(tmpl_rel, 7);
    if (p_fd < 0 || b_fd < 0 || r_fd < 0) {
        std::fprintf(stderr, "nl: mkstemps failed\n");
        return -1;
    }
    close(p_fd); close(b_fd); close(r_fd);
    out->link_plan_path = tmpl_plan;
    out->blob_path = tmpl_blob;
    out->relocs_path = tmpl_rel;
    if (write_link_plan(out->link_plan_path, helper_addrs, map_kaddr) != 0) {
        return -1;
    }

    std::vector<std::string> argv = {
        native_link_binary(),
        "--input", native_o,
        "--symbol", prog_name,
        "--output", out->blob_path,
        "--output-relocs", out->relocs_path,
        "--link-plan", out->link_plan_path,
    };
    if (run_subprocess(argv) != 0) {
        std::fprintf(stderr, "nl: native-link failed\n");
        return -1;
    }

    ensure_debugfs_mounted();
    std::vector<uint8_t> blob, relocs;
    {
        std::ifstream f(out->blob_path, std::ios::binary);
        blob.assign(std::istreambuf_iterator<char>(f),
                    std::istreambuf_iterator<char>());
    }
    {
        std::ifstream f(out->relocs_path, std::ios::binary);
        relocs.assign(std::istreambuf_iterator<char>(f),
                      std::istreambuf_iterator<char>());
    }
    uint32_t chunks = 0;
    if (upload_blob(blob, &chunks) != 0) return -1;
    if (upload_relocs(relocs) != 0) return -1;

    int mod_btf_fd = find_module_btf_fd();
    if (mod_btf_fd < 0) return -1;
    int kfunc_id = find_kfunc_btf_id();
    if (kfunc_id < 0) {
        close(mod_btf_fd);
        return -1;
    }
    out->prog_fd = load_stub_prog(kfunc_id, mod_btf_fd, chunks,
                                  prog_type, out->count_map_fd);
    close(mod_btf_fd);
    return (out->prog_fd < 0) ? -1 : 0;
}

} // namespace

int nl_load_and_attach(const char *bpf_o_path,
                       const char *prog_name,
                       const char *mode,
                       const char *target,
                       int pid,
                       NlSession *out)
{
    uint32_t pt = map_prog_type(mode);
    if (pt == 0) return -1;
    if (nl_load_only(bpf_o_path, prog_name, pt, out) != 0) return -1;

    /* (7) Attach via the event-driven path for the requested mode.
     *
     * For uprobe, the caller is expected to use the _at variant since
     * symbol resolution at this layer is fragile inside the VM overlay.
     * We keep the name-based mode rejected with a clear error rather
     * than silently failing. */
    if (std::strcmp(mode, "kprobe") == 0) {
        return attach_kprobe(out->prog_fd, target, out);
    } else if (std::strcmp(mode, "raw_tp") == 0) {
        return attach_raw_tp(out->prog_fd, target, out);
    } else if (std::strcmp(mode, "uprobe") == 0) {
        std::fprintf(stderr, "nl: uprobe-by-name not supported; "
                             "use nl_load_and_attach_uprobe_at(&symbol)\n");
        return -1;
    }
    std::fprintf(stderr, "nl: unknown mode %s\n", mode);
    return -1;
}

int nl_load_and_attach_uprobe_at(const char *bpf_o_path,
                                 const char *prog_name,
                                 void *func_addr,
                                 int pid,
                                 NlSession *out)
{
    /* uprobe stub programs share prog_type=BPF_PROG_TYPE_KPROBE with
     * kprobe (the perf_event_open path differentiates the two, not the
     * verifier). Load via the shared loader and run the addr-based
     * uprobe attach. */
    if (nl_load_only(bpf_o_path, prog_name,
                     BPF_PROG_TYPE_KPROBE, out) != 0) return -1;
    return attach_uprobe_at(out->prog_fd,
                            reinterpret_cast<uint64_t>(func_addr), pid, out);
}

void nl_close(NlSession *s)
{
    if (!s) return;
    if (s->attach_fd >= 0) {
        close(s->attach_fd);
        s->attach_fd = -1;
    }
    if (s->prog_fd >= 0) {
        close(s->prog_fd);
        s->prog_fd = -1;
    }
    if (!s->probe_events_path.empty() && !s->probe_events_line.empty()) {
        int fd = open(s->probe_events_path.c_str(), O_WRONLY | O_APPEND);
        if (fd >= 0) {
            (void)write(fd, s->probe_events_line.c_str(),
                        s->probe_events_line.size());
            close(fd);
        }
    }
    if (!s->blob_path.empty()) (void)unlink(s->blob_path.c_str());
    if (!s->relocs_path.empty()) (void)unlink(s->relocs_path.c_str());
    if (!s->link_plan_path.empty()) (void)unlink(s->link_plan_path.c_str());
    if (s->companion) {
        bpf_object__close(s->companion);
        s->companion = nullptr;
    }
}
