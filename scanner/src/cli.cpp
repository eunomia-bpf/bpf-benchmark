// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/pattern_v5.hpp"
#include "bpf_jit_scanner/policy_config.hpp"

#include <bpf/libbpf.h>

#include <algorithm>
#include <cerrno>
#include <cctype>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fcntl.h>
#include <exception>
#include <memory>
#include <string>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <vector>

namespace {

#ifndef __NR_bpf
#  if defined(__x86_64__)
#    define __NR_bpf 321
#  elif defined(__aarch64__)
#    define __NR_bpf 280
#  else
#    error "Unknown architecture: add __NR_bpf"
#  endif
#endif

#ifndef __NR_memfd_create
#  if defined(__x86_64__)
#    define __NR_memfd_create 319
#  elif defined(__aarch64__)
#    define __NR_memfd_create 279
#  else
#    error "Unknown architecture: add __NR_memfd_create"
#  endif
#endif

#ifndef BPF_OBJ_GET_INFO_BY_FD
#define BPF_OBJ_GET_INFO_BY_FD 15
#endif

#ifndef BPF_PROG_GET_NEXT_ID
#define BPF_PROG_GET_NEXT_ID 11
#endif

#ifndef BPF_PROG_GET_FD_BY_ID
#define BPF_PROG_GET_FD_BY_ID 13
#endif

#ifndef BPF_PROG_JIT_RECOMPILE
#define BPF_PROG_JIT_RECOMPILE 39
#endif

// Attr for BPF_PROG_GET_NEXT_ID / BPF_PROG_GET_FD_BY_ID.
// Kernel layout: [start_id/prog_id (u32)][next_id/id (u32)][open_flags (u32)]
// start_id and prog_id are the SAME field at offset 0 in the kernel union.
// next_id is written back by the kernel at offset 4 (same slot as "id").
struct mini_bpf_attr_id {
    uint32_t start_id;   // offset 0: input for GET_NEXT_ID; prog_id for GET_FD_BY_ID
    uint32_t next_id;    // offset 4: output for GET_NEXT_ID (kernel writes here)
    uint32_t open_flags; // offset 8
};

struct mini_bpf_prog_info {
    uint32_t type;
    uint32_t id;
    uint8_t tag[8];
    uint32_t jited_prog_len;
    uint32_t xlated_prog_len;
    uint64_t jited_prog_insns;
    uint64_t xlated_prog_insns;
    uint64_t load_time;
    uint32_t created_by_uid;
    uint32_t nr_map_ids;
    uint64_t map_ids;
    char name[16];
    uint32_t ifindex;
    uint32_t gpl_compatible;
    uint64_t netns_dev;
    uint64_t netns_ino;
    uint32_t nr_jited_ksyms;
    uint32_t nr_jited_func_lens;
    uint64_t jited_ksyms;
    uint64_t jited_func_lens;
    uint32_t btf_id;
    uint32_t func_info_rec_size;
    uint64_t func_info;
    uint32_t nr_func_info;
    uint32_t nr_line_info;
    uint64_t line_info;
    uint64_t jited_line_info;
    uint32_t nr_jited_line_info;
    uint32_t line_info_rec_size;
    uint32_t jited_line_info_rec_size;
    uint32_t nr_prog_tags;
    uint64_t prog_tags;
    uint64_t run_time_ns;
    uint64_t run_cnt;
};

struct mini_bpf_attr_info {
    uint32_t bpf_fd;
    uint32_t info_len;
    uint64_t info;
};

union mini_bpf_attr {
    mini_bpf_attr_info info;
    char pad[256];
};

struct InputBundle {
    std::vector<uint8_t> xlated;
    uint32_t insn_cnt = 0;
    uint8_t prog_tag[8] = {};
    std::string program_name;
};

struct CommandOptions {
    std::string subcommand;
    int prog_fd = -1;
    std::string xlated_path;
    std::string output_path;
    std::string program_name;
    std::string config_path;
    bpf_jit_scanner::V5ScanOptions scan_options = {
        .scan_cmov = false,
        .scan_wide = false,
        .scan_rotate = false,
        .scan_lea = false,
        .scan_extract = false,
        .scan_zero_ext = false,
        .scan_endian = false,
        .scan_branch_flip = false,
        .use_rorx = false,
    };
    bool families_explicit = false;
    bool has_prog_tag = false;
    uint8_t prog_tag[8] = {};
    bool has_insn_cnt = false;
    uint32_t insn_cnt = 0;
    bool json_output = false;
    bool per_site_output = false;
    // enumerate subcommand options
    bool enumerate_recompile = false;
    std::string enumerate_policy_dir;
    uint32_t enumerate_prog_id_filter = 0; // 0 = all
};

uint64_t ptr_to_u64(const void *ptr)
{
    return static_cast<uint64_t>(reinterpret_cast<uintptr_t>(ptr));
}

struct bpf_object_deleter {
    void operator()(bpf_object *obj) const
    {
        if (obj != nullptr) {
            bpf_object__close(obj);
        }
    }
};

using bpf_object_ptr = std::unique_ptr<bpf_object, bpf_object_deleter>;

int libbpf_silent(enum libbpf_print_level, const char *, va_list)
{
    return 0;
}

mini_bpf_prog_info fetch_prog_info(int prog_fd);
std::vector<uint8_t> fetch_xlated(int prog_fd, const mini_bpf_prog_info &probe);

[[noreturn]] void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    std::vfprintf(stderr, fmt, ap);
    va_end(ap);
    std::fputc('\n', stderr);
    std::exit(1);
}

std::vector<uint8_t> read_file(const std::string &path)
{
    int fd = open(path.c_str(), O_RDONLY);
    if (fd < 0) {
        die("open(%s): %s", path.c_str(), strerror(errno));
    }

    struct stat st = {};
    if (fstat(fd, &st) != 0) {
        die("fstat(%s): %s", path.c_str(), strerror(errno));
    }

    std::vector<uint8_t> data(static_cast<size_t>(st.st_size));
    size_t offset = 0;
    while (offset < data.size()) {
        const ssize_t rc = read(fd, data.data() + offset, data.size() - offset);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            die("read(%s): %s", path.c_str(), strerror(errno));
        }
        if (rc == 0) {
            break;
        }
        offset += static_cast<size_t>(rc);
    }
    close(fd);
    data.resize(offset);
    return data;
}

bool data_is_elf_object(const std::vector<uint8_t> &data)
{
    return data.size() >= 4 &&
           data[0] == 0x7f &&
           data[1] == 'E' &&
           data[2] == 'L' &&
           data[3] == 'F';
}

[[noreturn]] void die_libbpf(const char *context, int error_code)
{
    char buffer[256] = {};
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    die("%s: %s", context, buffer);
}

bpf_program *find_program(bpf_object *object, const std::string &program_name)
{
    bpf_program *program = nullptr;

    if (program_name.empty()) {
        program = bpf_object__next_program(object, nullptr);
        if (program == nullptr) {
            die("ELF object contains no BPF programs");
        }
        return program;
    }

    while ((program = bpf_object__next_program(object, program)) != nullptr) {
        const char *current_name = bpf_program__name(program);
        if (current_name != nullptr && program_name == current_name) {
            return program;
        }
    }

    die("unable to find program named '%s' in ELF object", program_name.c_str());
}

std::string extract_program_name(bpf_program *program)
{
    const char *current_name = bpf_program__name(program);
    return current_name != nullptr ? current_name : "";
}

std::vector<uint8_t> read_object_program(const std::string &path,
                                         const std::string &program_name,
                                         std::string *resolved_program_name)
{
    bpf_object_open_opts open_opts = {};
    open_opts.sz = sizeof(open_opts);

    bpf_object *raw_object = bpf_object__open_file(path.c_str(), &open_opts);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        die_libbpf("bpf_object__open_file failed", open_error);
    }
    bpf_object_ptr object(raw_object);

    bpf_program *program = find_program(object.get(), program_name);
    if (resolved_program_name != nullptr) {
        *resolved_program_name = extract_program_name(program);
    }
    const bpf_insn *insns = bpf_program__insns(program);
    const size_t insn_cnt = bpf_program__insn_cnt(program);
    if (insns == nullptr || insn_cnt == 0) {
        die("selected ELF program contains no instructions");
    }

    std::vector<uint8_t> xlated(insn_cnt * sizeof(bpf_insn));
    std::memcpy(xlated.data(), insns, xlated.size());
    return xlated;
}

bool try_load_object_xlated(const std::string &path,
                            const std::string &program_name,
                            InputBundle &input)
{
    bpf_object_open_opts open_opts = {};
    open_opts.sz = sizeof(open_opts);

    auto *saved_print = libbpf_set_print(libbpf_silent);
    bpf_object *raw_object = bpf_object__open_file(path.c_str(), &open_opts);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        libbpf_set_print(saved_print);
        return false;
    }
    bpf_object_ptr object(raw_object);

    bpf_program *program = find_program(object.get(), program_name);
    input.program_name = extract_program_name(program);
    bpf_program *iter = nullptr;
    while ((iter = bpf_object__next_program(object.get(), iter)) != nullptr) {
        bpf_program__set_autoload(iter, iter == program);
    }

    if (bpf_object__load(object.get()) != 0) {
        libbpf_set_print(saved_print);
        return false;
    }

    libbpf_set_print(saved_print);

    const int prog_fd = bpf_program__fd(program);
    if (prog_fd < 0) {
        return false;
    }

    const mini_bpf_prog_info info = fetch_prog_info(prog_fd);
    input.xlated = fetch_xlated(prog_fd, info);
    input.insn_cnt = info.xlated_prog_len / 8;
    std::memcpy(input.prog_tag, info.tag, sizeof(input.prog_tag));
    return true;
}

void write_all(int fd, const uint8_t *data, uint32_t len, const char *target)
{
    size_t offset = 0;
    while (offset < len) {
        const ssize_t rc = write(fd, data + offset, len - offset);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            die("write(%s): %s", target, strerror(errno));
        }
        offset += static_cast<size_t>(rc);
    }
}

void write_file(const std::string &path, const uint8_t *data, uint32_t len)
{
    int fd = open(path.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        die("open(%s): %s", path.c_str(), strerror(errno));
    }

    write_all(fd, data, len, path.c_str());
    close(fd);
}

void write_stdout(const uint8_t *data, uint32_t len)
{
    write_all(STDOUT_FILENO, data, len, "stdout");
}

bpf_jit_scanner::V5PolicyConfig load_policy_config_or_die(const std::string &path)
{
    try {
        return bpf_jit_scanner::load_policy_config_file(path);
    } catch (const std::exception &ex) {
        die("%s", ex.what());
    }
}

mini_bpf_prog_info fetch_prog_info(int prog_fd)
{
    mini_bpf_prog_info info = {};
    mini_bpf_attr attr = {};
    attr.info.bpf_fd = static_cast<uint32_t>(prog_fd);
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        die("BPF_OBJ_GET_INFO_BY_FD: %s", strerror(errno));
    }
    return info;
}

std::vector<uint8_t> fetch_xlated(int prog_fd, const mini_bpf_prog_info &probe)
{
    if (probe.xlated_prog_len == 0) {
        die("kernel reported xlated_prog_len = 0");
    }

    std::vector<uint8_t> xlated(probe.xlated_prog_len);
    mini_bpf_prog_info info = {};
    info.xlated_prog_len = probe.xlated_prog_len;
    info.xlated_prog_insns = ptr_to_u64(xlated.data());

    mini_bpf_attr attr = {};
    attr.info.bpf_fd = static_cast<uint32_t>(prog_fd);
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        die("BPF_OBJ_GET_INFO_BY_FD (xlated fetch): %s", strerror(errno));
    }

    xlated.resize(info.xlated_prog_len);
    return xlated;
}

InputBundle load_input(const CommandOptions &options)
{
    InputBundle input;

    if (options.prog_fd >= 0) {
        const mini_bpf_prog_info info = fetch_prog_info(options.prog_fd);
        input.xlated = fetch_xlated(options.prog_fd, info);
        input.insn_cnt = info.xlated_prog_len / 8;
        std::memcpy(input.prog_tag, info.tag, sizeof(input.prog_tag));
        input.program_name.assign(info.name, strnlen(info.name, sizeof(info.name)));
    } else {
        const auto data = read_file(options.xlated_path);
        if (data_is_elf_object(data)) {
            if (!try_load_object_xlated(options.xlated_path, options.program_name, input)) {
                input.xlated = read_object_program(options.xlated_path,
                                                  options.program_name,
                                                  &input.program_name);
                input.insn_cnt = static_cast<uint32_t>(input.xlated.size() / 8);
            }
        } else {
            input.xlated = data;
            input.insn_cnt = static_cast<uint32_t>(input.xlated.size() / 8);
            input.program_name = options.program_name.empty()
                                     ? std::filesystem::path(options.xlated_path).filename().string()
                                     : options.program_name;
        }
        if (input.xlated.size() % 8 != 0) {
            die("offline input size (%zu) is not a multiple of 8", input.xlated.size());
        }
    }

    if (options.has_prog_tag) {
        std::memcpy(input.prog_tag, options.prog_tag, sizeof(input.prog_tag));
    }
    if (options.has_insn_cnt) {
        input.insn_cnt = options.insn_cnt;
    }
    if (!options.program_name.empty()) {
        input.program_name = options.program_name;
    }
    return input;
}

int sys_memfd_create(const char *name, unsigned int flags)
{
    return static_cast<int>(syscall(__NR_memfd_create, name, flags));
}

void apply_policy_blob(int prog_fd, const std::vector<uint8_t> &blob)
{
    constexpr uint32_t kRecompileLogSize = 16 * 1024;
    int memfd = sys_memfd_create("bpf-jit-policy", MFD_CLOEXEC | MFD_ALLOW_SEALING);
    std::vector<char> log_buf(kRecompileLogSize, '\0');
    if (memfd < 0) {
        die("memfd_create: %s", strerror(errno));
    }

    size_t offset = 0;
    while (offset < blob.size()) {
        const ssize_t rc = write(memfd, blob.data() + offset, blob.size() - offset);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            close(memfd);
            die("write(memfd): %s", strerror(errno));
        }
        offset += static_cast<size_t>(rc);
    }

    const int seals = F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK;
    if (fcntl(memfd, F_ADD_SEALS, seals) != 0) {
        close(memfd);
        die("fcntl(F_ADD_SEALS): %s", strerror(errno));
    }

    struct {
        uint32_t prog_fd;
        int32_t policy_fd;
        uint32_t flags;
        uint32_t log_level;
        uint32_t log_size;
        uint64_t log_buf;
    } __attribute__((aligned(8))) attr = {};
    attr.prog_fd = static_cast<uint32_t>(prog_fd);
    attr.policy_fd = memfd;
    attr.flags = 0;
    attr.log_level = 1;
    attr.log_size = static_cast<uint32_t>(log_buf.size());
    attr.log_buf = ptr_to_u64(log_buf.data());

    alignas(8) char attr_buf[256] = {};
    std::memcpy(attr_buf, &attr, sizeof(attr));
    const int rc = static_cast<int>(syscall(__NR_bpf, BPF_PROG_JIT_RECOMPILE,
                                            attr_buf, sizeof(attr_buf)));
    close(memfd);
    if (rc != 0) {
        const std::string kernel_log(log_buf.data());
        if (!kernel_log.empty()) {
            die("BPF_PROG_JIT_RECOMPILE: %s\n%s", strerror(errno),
                kernel_log.c_str());
        }
        die("BPF_PROG_JIT_RECOMPILE: %s", strerror(errno));
    }
}

// -----------------------------------------------------------------------
// enumerate: scan all live BPF programs in the kernel
// -----------------------------------------------------------------------

// Returns -1 on end-of-list, -2 on error (check errno), otherwise next_id
static int bpf_prog_get_next_id(uint32_t start_id, uint32_t *next_id)
{
    alignas(8) char attr_buf[256] = {};
    auto *a = reinterpret_cast<mini_bpf_attr_id *>(attr_buf);
    a->start_id = start_id;
    if (syscall(__NR_bpf, BPF_PROG_GET_NEXT_ID, attr_buf, sizeof(attr_buf)) != 0) {
        if (errno == ENOENT) {
            return -1; // end of list
        }
        return -2; // error
    }
    *next_id = a->next_id;
    return 0;
}

static int bpf_prog_get_fd_by_id(uint32_t prog_id)
{
    alignas(8) char attr_buf[256] = {};
    auto *a = reinterpret_cast<mini_bpf_attr_id *>(attr_buf);
    a->start_id = prog_id; // prog_id is at offset 0 in the kernel union
    int fd = static_cast<int>(syscall(__NR_bpf, BPF_PROG_GET_FD_BY_ID,
                                      attr_buf, sizeof(attr_buf)));
    return fd; // -1 on error
}

struct EnumerateSiteInfo {
    uint32_t insn = 0;
    std::string family;
    std::string pattern_kind;
};

struct EnumerateResult {
    uint32_t prog_id = 0;
    std::string name;
    uint32_t prog_type = 0;
    uint32_t total_sites = 0;
    uint32_t applied_sites = 0;
    bool recompile_ok = false;
    std::string error;
    std::vector<EnumerateSiteInfo> sites;
};

static const char *bpf_prog_type_str(uint32_t t)
{
    switch (t) {
    case 0:  return "unspec";
    case 1:  return "socket_filter";
    case 2:  return "kprobe";
    case 3:  return "sched_cls";
    case 4:  return "sched_act";
    case 5:  return "tracepoint";
    case 6:  return "xdp";
    case 7:  return "perf_event";
    case 8:  return "cgroup_skb";
    case 9:  return "cgroup_sock";
    case 10: return "lwt_in";
    case 11: return "lwt_out";
    case 12: return "lwt_xmit";
    case 13: return "sock_ops";
    case 14: return "sk_skb";
    case 15: return "cgroup_device";
    case 16: return "sk_msg";
    case 17: return "raw_tracepoint";
    case 18: return "cgroup_sock_addr";
    case 19: return "lwt_seg6local";
    case 20: return "lirc_mode2";
    case 21: return "sk_reuseport";
    case 22: return "flow_dissector";
    case 23: return "cgroup_sysctl";
    case 24: return "raw_tracepoint_writable";
    case 25: return "cgroup_sockopt";
    case 26: return "tracing";
    case 27: return "struct_ops";
    case 28: return "ext";
    case 29: return "lsm";
    case 30: return "sk_lookup";
    case 31: return "syscall";
    default: return "unknown";
    }
}

void run_enumerate(const CommandOptions &options)
{
    if (!options.families_explicit) {
        // print notice that all families are enabled
    }

    std::vector<EnumerateResult> results;
    uint32_t total_progs = 0;
    uint32_t total_with_sites = 0;
    uint32_t total_recompiled = 0;

    std::fprintf(stderr, "Enumerating live BPF programs...\n");

    uint32_t id = 0;
    while (true) {
        uint32_t next_id = 0;
        const int rc = bpf_prog_get_next_id(id, &next_id);
        if (rc == -1) {
            break; // end of list
        }
        if (rc == -2) {
            std::fprintf(stderr, "BPF_PROG_GET_NEXT_ID: %s\n", strerror(errno));
            break;
        }
        id = next_id;

        // Filter by prog_id if requested
        if (options.enumerate_prog_id_filter != 0 &&
            id != options.enumerate_prog_id_filter) {
            continue;
        }

        total_progs++;

        EnumerateResult res;
        res.prog_id = id;

        int prog_fd = bpf_prog_get_fd_by_id(id);
        if (prog_fd < 0) {
            res.error = std::string("BPF_PROG_GET_FD_BY_ID: ") + strerror(errno);
            results.push_back(std::move(res));
            continue;
        }

        // fetch info + xlated bytecode
        mini_bpf_prog_info info = {};
        {
            mini_bpf_attr attr = {};
            attr.info.bpf_fd = static_cast<uint32_t>(prog_fd);
            attr.info.info_len = sizeof(info);
            attr.info.info = ptr_to_u64(&info);
            if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
                res.error = std::string("BPF_OBJ_GET_INFO_BY_FD: ") + strerror(errno);
                close(prog_fd);
                results.push_back(std::move(res));
                continue;
            }
        }

        res.prog_type = info.type;
        res.name.assign(info.name, strnlen(info.name, sizeof(info.name)));

        if (info.xlated_prog_len == 0) {
            res.error = "xlated_prog_len=0 (no xlated access or unprivileged)";
            close(prog_fd);
            results.push_back(std::move(res));
            continue;
        }

        // Fetch xlated bytecode
        std::vector<uint8_t> xlated(info.xlated_prog_len);
        {
            mini_bpf_prog_info info2 = {};
            info2.xlated_prog_len = info.xlated_prog_len;
            info2.xlated_prog_insns = ptr_to_u64(xlated.data());
            mini_bpf_attr attr = {};
            attr.info.bpf_fd = static_cast<uint32_t>(prog_fd);
            attr.info.info_len = sizeof(info2);
            attr.info.info = ptr_to_u64(&info2);
            if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
                res.error = std::string("BPF_OBJ_GET_INFO_BY_FD (xlated): ") + strerror(errno);
                close(prog_fd);
                results.push_back(std::move(res));
                continue;
            }
            xlated.resize(info2.xlated_prog_len);
        }

        // Pattern matching
        const auto summary = bpf_jit_scanner::scan_v5_builtin(
            xlated.data(),
            static_cast<uint32_t>(xlated.size()),
            options.scan_options);

        res.total_sites = static_cast<uint32_t>(summary.rules.size());
        res.applied_sites = res.total_sites; // default: apply all

        // Populate per-site manifest for JSON output.
        {
            bpf_jit_scanner::V5ProgramInfo prog_info;
            prog_info.name = res.name;
            prog_info.insn_cnt = info.xlated_prog_len / 8;
            std::memcpy(prog_info.prog_tag.data(), info.tag, sizeof(info.tag));
            const auto manifest = bpf_jit_scanner::build_scan_manifest(prog_info, summary);
            res.sites.reserve(manifest.sites.size());
            for (const auto &site : manifest.sites) {
                res.sites.push_back(EnumerateSiteInfo{
                    .insn = site.start_insn,
                    .family = std::string(bpf_jit_scanner::v5_family_name(site.family)),
                    .pattern_kind = site.pattern_kind,
                });
            }
        }

        if (res.total_sites > 0) {
            total_with_sites++;
        }

        // optionally apply recompile
        if (options.enumerate_recompile && res.total_sites > 0) {
            // Optionally filter by policy if a policy dir / config was given
            std::vector<bpf_jit_scanner::V5PolicyRule> rules_to_apply = summary.rules;

            if (!options.enumerate_policy_dir.empty()) {
                // Try to load <policy_dir>/<name>.policy.yaml
                std::string policy_path =
                    options.enumerate_policy_dir + "/" + res.name + ".policy.yaml";
                std::filesystem::path pp(policy_path);
                if (std::filesystem::exists(pp)) {
                    try {
                        const auto config = bpf_jit_scanner::load_policy_config_file(policy_path);
                        const auto fr = bpf_jit_scanner::filter_rules_by_policy_detailed(
                            summary.rules, config);
                        rules_to_apply = fr.rules;
                        res.applied_sites = static_cast<uint32_t>(rules_to_apply.size());
                    } catch (const std::exception &ex) {
                        std::fprintf(stderr, "  warning: failed to load policy %s: %s\n",
                                     policy_path.c_str(), ex.what());
                    }
                }
            }

            if (!rules_to_apply.empty()) {
                const uint32_t insn_cnt = info.xlated_prog_len / 8;
                const auto blob = bpf_jit_scanner::build_policy_blob_v5(
                    insn_cnt, info.tag, rules_to_apply);

                // memfd + seals + BPF_PROG_JIT_RECOMPILE
                int memfd = sys_memfd_create("bpf-jit-enumerate-policy",
                                              MFD_CLOEXEC | MFD_ALLOW_SEALING);
                if (memfd < 0) {
                    res.error = std::string("memfd_create: ") + strerror(errno);
                } else {
                    size_t off = 0;
                    bool write_ok = true;
                    while (off < blob.size()) {
                        const ssize_t n = write(memfd, blob.data() + off,
                                                blob.size() - off);
                        if (n < 0) {
                            if (errno == EINTR) continue;
                            write_ok = false;
                            break;
                        }
                        off += static_cast<size_t>(n);
                    }
                    if (!write_ok) {
                        res.error = std::string("write(memfd): ") + strerror(errno);
                        close(memfd);
                    } else {
                        const int seals = F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK;
                        if (fcntl(memfd, F_ADD_SEALS, seals) != 0) {
                            res.error = std::string("fcntl(F_ADD_SEALS): ") + strerror(errno);
                            close(memfd);
                        } else {
                            constexpr uint32_t kRecompileLogSize = 16 * 1024;
                            std::vector<char> log_buf(kRecompileLogSize, '\0');
                            struct {
                                uint32_t prog_fd;
                                int32_t policy_fd;
                                uint32_t flags;
                                uint32_t log_level;
                                uint32_t log_size;
                                uint64_t log_buf;
                            } __attribute__((aligned(8))) rcattr = {};
                            rcattr.prog_fd = static_cast<uint32_t>(prog_fd);
                            rcattr.policy_fd = memfd;
                            rcattr.flags = 0;
                            rcattr.log_level = 1;
                            rcattr.log_size = static_cast<uint32_t>(log_buf.size());
                            rcattr.log_buf = ptr_to_u64(log_buf.data());
                            alignas(8) char rcattr_buf[256] = {};
                            std::memcpy(rcattr_buf, &rcattr, sizeof(rcattr));
                            const int rrc = static_cast<int>(
                                syscall(__NR_bpf, BPF_PROG_JIT_RECOMPILE,
                                        rcattr_buf, sizeof(rcattr_buf)));
                            close(memfd);
                            if (rrc == 0) {
                                res.recompile_ok = true;
                                total_recompiled++;
                            } else {
                                const std::string klog(log_buf.data());
                                res.error = std::string("BPF_PROG_JIT_RECOMPILE: ") +
                                             strerror(errno);
                                if (!klog.empty()) {
                                    res.error += "\n  kernel log: " + klog.substr(0, 256);
                                }
                            }
                        }
                    }
                }
            }
        }

        close(prog_fd);
        results.push_back(std::move(res));

        // If filtering to a single prog_id, stop after finding it
        if (options.enumerate_prog_id_filter != 0) {
            break;
        }
    }

    // Print results
    if (options.json_output) {
        std::printf("[\n");
        for (size_t i = 0; i < results.size(); ++i) {
            const auto &r = results[i];
            std::printf("  {\"prog_id\":%u,\"name\":\"%s\",\"type\":\"%s\","
                        "\"total_sites\":%u,\"applied_sites\":%u,"
                        "\"recompile_ok\":%s",
                        r.prog_id, r.name.c_str(),
                        bpf_prog_type_str(r.prog_type),
                        r.total_sites, r.applied_sites,
                        r.recompile_ok ? "true" : "false");
            if (!r.error.empty()) {
                std::printf(",\"error\":\"%s\"", r.error.c_str());
            }
            // Emit per-site manifest array.
            std::printf(",\"sites\":[");
            for (size_t j = 0; j < r.sites.size(); ++j) {
                const auto &s = r.sites[j];
                std::printf("%s{\"insn\":%u,\"family\":\"%s\",\"pattern_kind\":\"%s\"}",
                            j == 0 ? "" : ",",
                            s.insn, s.family.c_str(), s.pattern_kind.c_str());
            }
            std::printf("]");
            std::printf("}%s\n", i + 1 < results.size() ? "," : "");
        }
        std::printf("]\n");
    } else {
        for (const auto &r : results) {
            std::printf("prog_id=%-6u  type=%-20s  name=%-20s  sites=%u",
                        r.prog_id, bpf_prog_type_str(r.prog_type),
                        r.name.empty() ? "(unnamed)" : r.name.c_str(),
                        r.total_sites);
            if (options.enumerate_recompile && r.total_sites > 0) {
                if (r.recompile_ok) {
                    std::printf("  [RECOMPILED %u sites]", r.applied_sites);
                } else if (!r.error.empty()) {
                    std::printf("  [RECOMPILE FAILED]");
                }
            }
            if (!r.error.empty()) {
                std::printf("  error: %s", r.error.c_str());
            }
            std::printf("\n");
        }
        std::fprintf(stderr,
                     "\nSummary: scanned %u programs, %u with optimization sites%s\n",
                     total_progs, total_with_sites,
                     options.enumerate_recompile
                         ? (std::string(", ") + std::to_string(total_recompiled) +
                            " recompiled").c_str()
                         : "");
    }
}

// -----------------------------------------------------------------------

void print_usage(const char *prog)
{
    std::fprintf(stderr,
        "Usage:\n"
        "  %s scan  (<file> | --prog-fd <fd> | --xlated <file>) [family flags] [--json] [--per-site] [--output <blob>]\n"
        "  %s generate-policy (<file> | --prog-fd <fd> | --xlated <file>) [family flags] [--program-name <name>] [--output <yaml>|-]\n"
        "  %s compile-policy (<file> | --prog-fd <fd> | --xlated <file>) --config <policy-v3.{yaml,json}> [family flags] [--output <blob>|-]\n"
        "  %s apply (<file> | --prog-fd <fd> | --xlated <file>) [family flags] [--config <policy-v3.{yaml,json}>] [--program-name <name>] [--output <blob>|-]\n"
        "  %s dump  --prog-fd <fd> [--output <file>]\n"
        "  %s enumerate [family flags] [--recompile] [--policy-dir <dir>] [--prog-id <id>] [--json]\n"
        "\n"
        "Family flags:\n"
        "  --all        Enable all builtin families (default when omitted)\n"
        "  --cmov       Conditional-select sites\n"
        "  --wide-mem   Byte-ladder wide-load sites\n"
        "  --rotate     Rotate idioms\n"
        "  --lea        Address-calculation sites\n"
        "  --bitfield-extract, --extract\n"
        "               Bitfield extract sites\n"
        "  --zero-ext   Redundant zero-extension sites\n"
        "  --endian     Endian fusion sites\n"
        "  --branch-flip Branch flip sites\n"
        "  --rorx       Prefer RORX for rotate sites\n"
        "  --v5         Accepted for compatibility; scanner is already v5-only\n"
        "\n"
        "Shared options:\n"
        "  --program-name <name>  Select a program when scanning an ELF object path\n"
        "  --config <file>        Version 3 policy YAML/JSON used by compile-policy or apply\n"
        "  --json                 Emit scan manifest JSON instead of text summary\n"
        "  --per-site             Accepted for compatibility; scan --json is already per-site\n"
        "  --prog-tag <hex>       Override prog_tag for blob writing (16 hex chars)\n"
        "  --insn-cnt <n>         Override insn_cnt for blob writing\n"
        "  --output <file>        Output path (scan/apply/compile-policy: blob, dump: xlated)\n"
        "  --recompile            (enumerate) Apply BPF_PROG_JIT_RECOMPILE for found sites\n"
        "  --policy-dir <dir>     (enumerate) Per-program policy YAML directory\n"
        "  --prog-id <id>         (enumerate) Scan only a specific prog_id\n"
        "  -h, --help             Show this help\n",
        prog, prog, prog, prog, prog, prog);
}

void parse_hex_tag(const char *hex, uint8_t tag[8])
{
    if (std::strlen(hex) != 16) {
        die("--prog-tag must be 16 hex chars");
    }
    for (int i = 0; i < 8; ++i) {
        char byte[3] = {hex[i * 2], hex[i * 2 + 1], '\0'};
        tag[i] = static_cast<uint8_t>(std::strtoul(byte, nullptr, 16));
    }
}

void enable_all_families(CommandOptions &options)
{
    options.scan_options.scan_cmov = true;
    options.scan_options.scan_wide = true;
    options.scan_options.scan_rotate = true;
    options.scan_options.scan_lea = true;
    options.scan_options.scan_extract = true;
    options.scan_options.scan_zero_ext = true;
    options.scan_options.scan_endian = true;
    options.scan_options.scan_branch_flip = true;
}

CommandOptions parse_args(int argc, char **argv)
{
    if (argc < 2) {
        print_usage(argv[0]);
        std::exit(1);
    }

    CommandOptions options = {};
    options.subcommand = argv[1];
    if (options.subcommand == "-h" || options.subcommand == "--help") {
        print_usage(argv[0]);
        std::exit(0);
    }
    if (options.subcommand != "scan" &&
        options.subcommand != "generate-policy" &&
        options.subcommand != "compile-policy" &&
        options.subcommand != "apply" &&
        options.subcommand != "dump" &&
        options.subcommand != "enumerate") {
        die("unknown subcommand: %s", options.subcommand.c_str());
    }

    for (int i = 2; i < argc; ++i) {
        const std::string arg = argv[i];
        auto need_next = [&]() -> const char * {
            if (i + 1 >= argc) {
                die("option %s requires an argument", argv[i]);
            }
            return argv[++i];
        };

        if (arg == "-h" || arg == "--help") {
            print_usage(argv[0]);
            std::exit(0);
        } else if (arg == "--prog-fd") {
            options.prog_fd = std::atoi(need_next());
        } else if (arg == "--xlated") {
            options.xlated_path = need_next();
        } else if (arg == "--output") {
            options.output_path = need_next();
        } else if (arg == "--program-name") {
            options.program_name = need_next();
        } else if (arg == "--config") {
            options.config_path = need_next();
        } else if (arg == "--default") {
            die("--default was removed; version 3 policies are explicit site allowlists");
        } else if (arg == "--json") {
            options.json_output = true;
        } else if (arg == "--per-site") {
            options.per_site_output = true;
        } else if (arg == "--policy") {
            die("--policy was removed; scanner is v5-only");
        } else if (arg == "--prog-tag") {
            parse_hex_tag(need_next(), options.prog_tag);
            options.has_prog_tag = true;
        } else if (arg == "--insn-cnt") {
            options.insn_cnt = static_cast<uint32_t>(
                std::strtoul(need_next(), nullptr, 0));
            options.has_insn_cnt = true;
        } else if (arg == "--all") {
            options.families_explicit = false;
            options.scan_options.scan_cmov = false;
            options.scan_options.scan_wide = false;
            options.scan_options.scan_rotate = false;
            options.scan_options.scan_lea = false;
            options.scan_options.scan_extract = false;
            options.scan_options.scan_zero_ext = false;
            options.scan_options.scan_endian = false;
            options.scan_options.scan_branch_flip = false;
        } else if (arg == "--cmov") {
            options.scan_options.scan_cmov = true;
            options.families_explicit = true;
        } else if (arg == "--wide-mem") {
            options.scan_options.scan_wide = true;
            options.families_explicit = true;
        } else if (arg == "--rotate") {
            options.scan_options.scan_rotate = true;
            options.families_explicit = true;
        } else if (arg == "--lea") {
            options.scan_options.scan_lea = true;
            options.families_explicit = true;
        } else if (arg == "--bitfield-extract" || arg == "--extract") {
            options.scan_options.scan_extract = true;
            options.families_explicit = true;
        } else if (arg == "--zero-ext") {
            options.scan_options.scan_zero_ext = true;
            options.families_explicit = true;
        } else if (arg == "--endian") {
            options.scan_options.scan_endian = true;
            options.families_explicit = true;
        } else if (arg == "--branch-flip") {
            options.scan_options.scan_branch_flip = true;
            options.families_explicit = true;
        } else if (arg == "--rorx") {
            options.scan_options.use_rorx = true;
        } else if (arg == "--v5") {
            continue;
        } else if (arg == "--recompile") {
            if (options.subcommand != "enumerate") {
                die("--recompile is only valid with the enumerate subcommand");
            }
            options.enumerate_recompile = true;
        } else if (arg == "--policy-dir") {
            if (options.subcommand != "enumerate") {
                die("--policy-dir is only valid with the enumerate subcommand");
            }
            options.enumerate_policy_dir = need_next();
        } else if (arg == "--prog-id") {
            if (options.subcommand != "enumerate") {
                die("--prog-id is only valid with the enumerate subcommand");
            }
            options.enumerate_prog_id_filter = static_cast<uint32_t>(
                std::strtoul(need_next(), nullptr, 0));
        } else if (!arg.empty() && arg[0] != '-' &&
                   (options.subcommand == "scan" ||
                    options.subcommand == "generate-policy" ||
                    options.subcommand == "compile-policy" ||
                    options.subcommand == "apply") &&
                   options.prog_fd < 0 &&
                   options.xlated_path.empty()) {
            options.xlated_path = arg;
        } else {
            die("unknown option: %s", argv[i]);
        }
    }

    if (options.subcommand == "dump") {
        if (options.prog_fd < 0) {
            die("dump requires --prog-fd");
        }
        if (!options.xlated_path.empty()) {
            die("dump does not accept --xlated");
        }
        if (!options.config_path.empty()) {
            die("dump does not accept --config");
        }
        if (options.json_output) {
            die("dump does not accept --json");
        }
        if (options.per_site_output) {
            die("dump does not accept --per-site");
        }
        return options;
    }

    if (options.subcommand == "enumerate") {
        // enumerate does not take a positional file argument or --prog-fd
        if (options.prog_fd >= 0) {
            die("enumerate does not accept --prog-fd; use scan --prog-fd instead");
        }
        if (!options.xlated_path.empty()) {
            die("enumerate does not accept a positional file argument");
        }
        if (!options.config_path.empty()) {
            die("enumerate does not accept --config (use --policy-dir)");
        }
        if (options.per_site_output) {
            die("enumerate does not accept --per-site");
        }
        if (!options.families_explicit) {
            enable_all_families(options);
        }
        return options;
    }

    const bool requires_input =
        options.subcommand == "scan" ||
        options.subcommand == "generate-policy" ||
        options.subcommand == "compile-policy" ||
        options.subcommand == "apply";
    if (requires_input &&
        ((options.prog_fd < 0) == options.xlated_path.empty())) {
        if (options.subcommand == "scan") {
            die("scan requires exactly one of --prog-fd or --xlated");
        }
        if (options.subcommand == "generate-policy") {
            die("generate-policy requires exactly one of --prog-fd or --xlated");
        }
        if (options.subcommand == "compile-policy") {
            die("compile-policy requires exactly one of --prog-fd or --xlated");
        }
        die("apply requires exactly one of --prog-fd or --xlated");
    }

    if (options.subcommand == "scan" && !options.config_path.empty()) {
        die("scan does not accept --config; use compile-policy instead");
    }
    if (options.subcommand == "scan" && options.output_path == "-") {
        die("scan does not support --output -");
    }
    if (options.subcommand == "compile-policy" && options.config_path.empty()) {
        die("compile-policy requires --config");
    }
    if ((options.subcommand == "generate-policy" ||
         options.subcommand == "compile-policy" ||
         options.subcommand == "apply") &&
        options.json_output) {
        die("%s does not accept --json", options.subcommand.c_str());
    }
    if (options.subcommand != "scan" && options.per_site_output) {
        die("%s does not accept --per-site", options.subcommand.c_str());
    }
    if (options.subcommand == "scan" && options.per_site_output &&
        !options.json_output) {
        die("scan --per-site requires --json");
    }
    if ((options.subcommand == "scan" || options.subcommand == "apply") &&
        options.prog_fd >= 0 &&
        options.output_path == "-") {
        die("%s does not support --output -", options.subcommand.c_str());
    }
    if ((options.subcommand == "scan" || options.subcommand == "generate-policy") &&
        !options.config_path.empty()) {
        die("%s does not accept --config", options.subcommand.c_str());
    }

    if (!options.families_explicit) {
        enable_all_families(options);
    }
    return options;
}

void print_summary(FILE *stream, const bpf_jit_scanner::V5ScanSummary &summary)
{
    std::fprintf(stream, "Accepted %zu v5 site(s)\n", summary.rules.size());
    std::fprintf(stream, "  cmov:   %llu\n",
                 static_cast<unsigned long long>(summary.cmov_sites));
    std::fprintf(stream, "  wide:   %llu\n",
                 static_cast<unsigned long long>(summary.wide_sites));
    std::fprintf(stream, "  rotate: %llu\n",
                 static_cast<unsigned long long>(summary.rotate_sites));
    std::fprintf(stream, "  lea:    %llu\n",
                 static_cast<unsigned long long>(summary.lea_sites));
    std::fprintf(stream, "  extract:%llu\n",
                 static_cast<unsigned long long>(summary.bitfield_sites));
    std::fprintf(stream, "  zeroext:%llu\n",
                 static_cast<unsigned long long>(summary.zero_ext_sites));
    std::fprintf(stream, "  endian: %llu\n",
                 static_cast<unsigned long long>(summary.endian_sites));
    std::fprintf(stream, "  bflip:  %llu\n",
                 static_cast<unsigned long long>(summary.branch_flip_sites));
}

void print_policy_warnings(
    const bpf_jit_scanner::V5PolicyFilterResult &filter_result)
{
    for (const auto &warning : filter_result.warnings) {
        std::fprintf(stderr, "warning: %s\n", warning.c_str());
    }
}

void maybe_warn_program_mismatch(const InputBundle &input,
                                 const bpf_jit_scanner::V5PolicyConfig &config)
{
    if (config.program.empty() || input.program_name.empty() ||
        config.program == input.program_name) {
        return;
    }
    std::fprintf(stderr,
                 "warning: policy program '%s' does not match input program "
                 "'%s'\n",
                 config.program.c_str(), input.program_name.c_str());
}

bpf_jit_scanner::V5ProgramInfo build_program_info(const InputBundle &input)
{
    bpf_jit_scanner::V5ProgramInfo program;
    program.name = input.program_name;
    program.insn_cnt = input.insn_cnt;
    std::memcpy(program.prog_tag.data(), input.prog_tag, sizeof(input.prog_tag));
    return program;
}

void run_scan(const CommandOptions &options)
{
    const InputBundle input = load_input(options);
    const auto summary = bpf_jit_scanner::scan_v5_builtin(
        input.xlated.data(),
        static_cast<uint32_t>(input.xlated.size()),
        options.scan_options);

    if (options.json_output) {
        const auto manifest = bpf_jit_scanner::build_scan_manifest(
            build_program_info(input), summary);
        const auto json = bpf_jit_scanner::scan_manifest_to_json(manifest);
        write_stdout(reinterpret_cast<const uint8_t *>(json.data()),
                     static_cast<uint32_t>(json.size()));
    } else {
        print_summary(stdout, summary);
    }

    if (!options.output_path.empty()) {
        const auto blob = bpf_jit_scanner::build_policy_blob_v5(
            input.insn_cnt, input.prog_tag, summary.rules);
        write_file(options.output_path, blob.data(), static_cast<uint32_t>(blob.size()));
        if (options.json_output) {
            std::fprintf(stderr, "Wrote %zu-byte v5 policy blob to %s\n",
                         blob.size(), options.output_path.c_str());
        } else {
            std::printf("Wrote %zu-byte v5 policy blob to %s\n",
                        blob.size(), options.output_path.c_str());
        }
    }
}

void run_generate_policy(const CommandOptions &options)
{
    const InputBundle input = load_input(options);
    const auto summary = bpf_jit_scanner::scan_v5_builtin(
        input.xlated.data(),
        static_cast<uint32_t>(input.xlated.size()),
        options.scan_options);
    const auto yaml = bpf_jit_scanner::render_policy_v3_yaml(
        build_program_info(input), summary);

    if (options.output_path.empty() || options.output_path == "-") {
        write_stdout(reinterpret_cast<const uint8_t *>(yaml.data()),
                     static_cast<uint32_t>(yaml.size()));
        return;
    }

    write_file(options.output_path,
               reinterpret_cast<const uint8_t *>(yaml.data()),
               static_cast<uint32_t>(yaml.size()));
    std::printf("Wrote version 3 policy template (%zu site entries) to %s\n",
                summary.rules.size(), options.output_path.c_str());
}

void run_compile_policy(const CommandOptions &options)
{
    const InputBundle input = load_input(options);
    const auto summary = bpf_jit_scanner::scan_v5_builtin(
        input.xlated.data(),
        static_cast<uint32_t>(input.xlated.size()),
        options.scan_options);
    const auto config = load_policy_config_or_die(options.config_path);
    maybe_warn_program_mismatch(input, config);
    const auto filter_result =
        bpf_jit_scanner::filter_rules_by_policy_detailed(
            summary.rules, config);
    print_policy_warnings(filter_result);
    const auto &filtered_rules = filter_result.rules;
    const auto blob = bpf_jit_scanner::build_policy_blob_v5(
        input.insn_cnt, input.prog_tag, filtered_rules);

    if (options.output_path.empty() || options.output_path == "-") {
        write_stdout(blob.data(), static_cast<uint32_t>(blob.size()));
        return;
    }

    write_file(options.output_path, blob.data(), static_cast<uint32_t>(blob.size()));
    std::printf("Wrote %zu-byte filtered v5 policy blob (%zu/%zu rules) to %s\n",
                blob.size(), filtered_rules.size(), summary.rules.size(),
                options.output_path.c_str());
}

void run_apply(const CommandOptions &options)
{
    const InputBundle input = load_input(options);
    const auto discovered = bpf_jit_scanner::scan_v5_builtin(
        input.xlated.data(),
        static_cast<uint32_t>(input.xlated.size()),
        options.scan_options);
    bpf_jit_scanner::V5PolicyFilterResult filter_result;
    filter_result.rules = discovered.rules;
    if (!options.config_path.empty()) {
        const auto config = load_policy_config_or_die(options.config_path);
        maybe_warn_program_mismatch(input, config);
        filter_result = bpf_jit_scanner::filter_rules_by_policy_detailed(
            discovered.rules, config);
        print_policy_warnings(filter_result);
    }
    const auto selected_summary =
        bpf_jit_scanner::summarize_rules(filter_result.rules);
    const auto blob = bpf_jit_scanner::build_policy_blob_v5(
        input.insn_cnt, input.prog_tag, filter_result.rules);

    const bool live_apply = options.prog_fd >= 0;
    if (!live_apply) {
        if (options.output_path.empty() || options.output_path == "-") {
            write_stdout(blob.data(), static_cast<uint32_t>(blob.size()));
            return;
        }
        write_file(options.output_path, blob.data(), static_cast<uint32_t>(blob.size()));
        std::printf("Wrote %zu-byte filtered v5 policy blob (%zu/%zu rules) to %s\n",
                    blob.size(), filter_result.rules.size(),
                    discovered.rules.size(), options.output_path.c_str());
        return;
    }

    print_summary(stdout, selected_summary);
    if (!options.config_path.empty()) {
        std::printf("Policy filter kept %zu of %zu v5 rule(s)\n",
                    filter_result.rules.size(), discovered.rules.size());
    }
    apply_policy_blob(options.prog_fd, blob);
    std::printf("Applied %zu v5 rule(s) via BPF_PROG_JIT_RECOMPILE\n",
                filter_result.rules.size());

    if (!options.output_path.empty()) {
        write_file(options.output_path, blob.data(), static_cast<uint32_t>(blob.size()));
        std::printf("Saved applied v5 blob to %s\n", options.output_path.c_str());
    }
}

void run_dump(const CommandOptions &options)
{
    const mini_bpf_prog_info info = fetch_prog_info(options.prog_fd);
    const auto xlated = fetch_xlated(options.prog_fd, info);

    std::string output = options.output_path;
    if (output.empty()) {
        const std::string program_name(info.name,
                                       strnlen(info.name, sizeof(info.name)));
        output = program_name.empty() ? "xlated.bin" : program_name + ".xlated.bin";
    }

    write_file(output, xlated.data(), static_cast<uint32_t>(xlated.size()));
    std::printf("Wrote %zu-byte xlated dump to %s\n", xlated.size(), output.c_str());
}

} // namespace

int main(int argc, char **argv)
{
    const CommandOptions options = parse_args(argc, argv);
    if (options.subcommand == "scan") {
        run_scan(options);
    } else if (options.subcommand == "generate-policy") {
        run_generate_policy(options);
    } else if (options.subcommand == "compile-policy") {
        run_compile_policy(options);
    } else if (options.subcommand == "apply") {
        run_apply(options);
    } else if (options.subcommand == "enumerate") {
        run_enumerate(options);
    } else {
        run_dump(options);
    }
    return 0;
}
