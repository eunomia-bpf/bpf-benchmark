// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/pattern_v5.hpp"

#include <algorithm>
#include <cerrno>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fcntl.h>
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

#ifndef BPF_PROG_JIT_RECOMPILE
#define BPF_PROG_JIT_RECOMPILE 39
#endif

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
};

struct CommandOptions {
    std::string subcommand;
    int prog_fd = -1;
    std::string xlated_path;
    std::string output_path;
    bpf_jit_scanner::V5ScanOptions scan_options = {
        .scan_cmov = false,
        .scan_wide = false,
        .scan_rotate = false,
        .scan_lea = false,
        .scan_extract = false,
        .scan_zero_ext = false,
        .scan_endian = false,
        .use_rorx = false,
    };
    bool families_explicit = false;
    bool has_prog_tag = false;
    uint8_t prog_tag[8] = {};
    bool has_insn_cnt = false;
    uint32_t insn_cnt = 0;
};

uint64_t ptr_to_u64(const void *ptr)
{
    return static_cast<uint64_t>(reinterpret_cast<uintptr_t>(ptr));
}

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

void write_file(const std::string &path, const uint8_t *data, uint32_t len)
{
    int fd = open(path.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        die("open(%s): %s", path.c_str(), strerror(errno));
    }

    size_t offset = 0;
    while (offset < len) {
        const ssize_t rc = write(fd, data + offset, len - offset);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            die("write(%s): %s", path.c_str(), strerror(errno));
        }
        offset += static_cast<size_t>(rc);
    }
    close(fd);
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
    } else {
        input.xlated = read_file(options.xlated_path);
        if (input.xlated.size() % 8 != 0) {
            die("xlated file size (%zu) is not a multiple of 8", input.xlated.size());
        }
        input.insn_cnt = static_cast<uint32_t>(input.xlated.size() / 8);
    }

    if (options.has_prog_tag) {
        std::memcpy(input.prog_tag, options.prog_tag, sizeof(input.prog_tag));
    }
    if (options.has_insn_cnt) {
        input.insn_cnt = options.insn_cnt;
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

void print_usage(const char *prog)
{
    std::fprintf(stderr,
        "Usage:\n"
        "  %s scan  (<file> | --prog-fd <fd> | --xlated <file>) [family flags] [--output <blob>]\n"
        "  %s apply --prog-fd <fd> [family flags] [--output <blob>]\n"
        "  %s dump  --prog-fd <fd> [--output <file>]\n"
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
        "  --rorx       Prefer RORX for rotate sites\n"
        "  --v5         Accepted for compatibility; scanner is already v5-only\n"
        "\n"
        "Shared options:\n"
        "  --program-name <name>  Accepted for compatibility; ignored\n"
        "  --prog-tag <hex>       Override prog_tag for blob writing (16 hex chars)\n"
        "  --insn-cnt <n>         Override insn_cnt for blob writing\n"
        "  --output <file>        Output path (scan/apply: blob, dump: xlated)\n"
        "  -h, --help             Show this help\n",
        prog, prog, prog);
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
        options.subcommand != "apply" &&
        options.subcommand != "dump") {
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
            static_cast<void>(need_next());
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
        } else if (arg == "--rorx") {
            options.scan_options.use_rorx = true;
        } else if (arg == "--v5") {
            continue;
        } else if (!arg.empty() && arg[0] != '-' &&
                   options.subcommand == "scan" &&
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
        return options;
    }

    if (options.subcommand == "apply") {
        if (options.prog_fd < 0) {
            die("apply requires --prog-fd");
        }
        if (!options.xlated_path.empty()) {
            die("apply does not accept --xlated");
        }
    } else if ((options.prog_fd < 0) == options.xlated_path.empty()) {
        die("scan requires exactly one of --prog-fd or --xlated");
    }

    if (!options.families_explicit) {
        enable_all_families(options);
    }
    return options;
}

void print_summary(const bpf_jit_scanner::V5ScanSummary &summary)
{
    std::printf("Accepted %zu v5 site(s)\n", summary.rules.size());
    std::printf("  cmov:   %llu\n",
                static_cast<unsigned long long>(summary.cmov_sites));
    std::printf("  wide:   %llu\n",
                static_cast<unsigned long long>(summary.wide_sites));
    std::printf("  rotate: %llu\n",
                static_cast<unsigned long long>(summary.rotate_sites));
    std::printf("  lea:    %llu\n",
                static_cast<unsigned long long>(summary.lea_sites));
    std::printf("  extract:%llu\n",
                static_cast<unsigned long long>(summary.bitfield_sites));
    std::printf("  zeroext:%llu\n",
                static_cast<unsigned long long>(summary.zero_ext_sites));
    std::printf("  endian: %llu\n",
                static_cast<unsigned long long>(summary.endian_sites));
}

void run_scan(const CommandOptions &options)
{
    const InputBundle input = load_input(options);
    const auto summary = bpf_jit_scanner::scan_v5_builtin(
        input.xlated.data(),
        static_cast<uint32_t>(input.xlated.size()),
        options.scan_options);

    print_summary(summary);

    if (!options.output_path.empty()) {
        const auto blob = bpf_jit_scanner::build_policy_blob_v5(
            input.insn_cnt, input.prog_tag, summary.rules);
        write_file(options.output_path, blob.data(), static_cast<uint32_t>(blob.size()));
        std::printf("Wrote %zu-byte v5 policy blob to %s\n",
                    blob.size(), options.output_path.c_str());
    }
}

void run_apply(const CommandOptions &options)
{
    const InputBundle input = load_input(options);
    const auto summary = bpf_jit_scanner::scan_v5_builtin(
        input.xlated.data(),
        static_cast<uint32_t>(input.xlated.size()),
        options.scan_options);
    const auto blob = bpf_jit_scanner::build_policy_blob_v5(
        input.insn_cnt, input.prog_tag, summary.rules);

    print_summary(summary);
    apply_policy_blob(options.prog_fd, blob);
    std::printf("Applied %zu v5 rule(s) via BPF_PROG_JIT_RECOMPILE\n",
                summary.rules.size());

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
    } else if (options.subcommand == "apply") {
        run_apply(options);
    } else {
        run_dump(options);
    }
    return 0;
}
