#include "micro_exec.hpp"

#include <bpf_jit_scanner/pattern_v5.hpp>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>

#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <memory>
#include <string>
#include <string_view>
#include <sys/syscall.h>
#include <thread>
#include <unordered_map>
#include <unistd.h>
#include <utility>
#include <vector>

#ifndef MFD_CLOEXEC
#define MFD_CLOEXEC 0x0001U
#endif

#ifndef MFD_ALLOW_SEALING
#define MFD_ALLOW_SEALING 0x0002U
#endif

#ifndef F_LINUX_SPECIFIC_BASE
#define F_LINUX_SPECIFIC_BASE 1024
#endif

#ifndef F_ADD_SEALS
#define F_ADD_SEALS (F_LINUX_SPECIFIC_BASE + 9)
#endif

#ifndef F_SEAL_SEAL
#define F_SEAL_SEAL 0x0001
#endif

#ifndef F_SEAL_SHRINK
#define F_SEAL_SHRINK 0x0002
#endif

#ifndef F_SEAL_GROW
#define F_SEAL_GROW 0x0004
#endif

#ifndef F_SEAL_WRITE
#define F_SEAL_WRITE 0x0008
#endif

#ifndef BPF_F_JIT_DIRECTIVES_FD
#define BPF_F_JIT_DIRECTIVES_FD (1U << 20)
#endif

/* v4 JIT recompile syscall subcommand (enum bpf_cmd value 39) */
#ifndef BPF_PROG_JIT_RECOMPILE
#define BPF_PROG_JIT_RECOMPILE 39
#endif

namespace {

using clock_type = std::chrono::steady_clock;

#if defined(__x86_64__) || defined(__i386__)
constexpr bool kHasTscMeasurement = true;

static inline uint64_t rdtsc_start()
{
    unsigned int lo, hi;
    asm volatile("lfence; rdtsc" : "=a"(lo), "=d"(hi));
    return (static_cast<uint64_t>(hi) << 32) | lo;
}

static inline uint64_t rdtsc_end()
{
    unsigned int lo, hi;
    asm volatile("rdtscp" : "=a"(lo), "=d"(hi) :: "ecx");
    asm volatile("lfence");
    return (static_cast<uint64_t>(hi) << 32) | lo;
}
#else
constexpr bool kHasTscMeasurement = false;

static inline uint64_t rdtsc_start()
{
    return 0;
}

static inline uint64_t rdtsc_end()
{
    return 0;
}
#endif

std::optional<uint64_t> read_nominal_tsc_freq_hz()
{
    std::ifstream cpuinfo("/proc/cpuinfo");
    if (!cpuinfo.is_open()) {
        return std::nullopt;
    }

    std::string line;
    while (std::getline(cpuinfo, line)) {
        if (!line.starts_with("model name")) {
            continue;
        }

        const auto at_pos = line.rfind('@');
        if (at_pos == std::string::npos) {
            continue;
        }

        const auto value_start = line.find_first_of("0123456789", at_pos);
        if (value_start == std::string::npos) {
            continue;
        }

        const auto value_end = line.find_first_not_of("0123456789.", value_start);
        if (value_end == std::string::npos) {
            continue;
        }

        const auto unit_start = line.find_first_not_of(" \t", value_end);
        if (unit_start == std::string::npos) {
            continue;
        }

        const auto unit_end = line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", unit_start);
        const auto unit = line.substr(
            unit_start,
            unit_end == std::string::npos ? std::string::npos : unit_end - unit_start);

        long double multiplier = 0.0L;
        if (unit == "GHz") {
            multiplier = 1000000000.0L;
        } else if (unit == "MHz") {
            multiplier = 1000000.0L;
        } else if (unit == "KHz") {
            multiplier = 1000.0L;
        } else {
            continue;
        }

        try {
            const auto value = std::stold(line.substr(value_start, value_end - value_start));
            return static_cast<uint64_t>(std::llround(value * multiplier));
        } catch (const std::exception &) {
            continue;
        }
    }

    return std::nullopt;
}

uint64_t calibrate_tsc_freq_hz()
{
    constexpr auto calibration_window = std::chrono::milliseconds(20);

    const auto wall_start = clock_type::now();
    const auto tsc_start = rdtsc_start();
    std::this_thread::sleep_for(calibration_window);
    const auto tsc_end = rdtsc_end();
    const auto wall_end = clock_type::now();

    const uint64_t wall_ns = elapsed_ns(wall_start, wall_end);
    if (wall_ns == 0 || tsc_end <= tsc_start) {
        fail("unable to calibrate TSC frequency");
    }

    const long double freq_hz =
        (static_cast<long double>(tsc_end - tsc_start) * 1000000000.0L) /
        static_cast<long double>(wall_ns);
    return static_cast<uint64_t>(std::llround(freq_hz));
}

uint64_t detect_tsc_freq_hz()
{
    if constexpr (!kHasTscMeasurement) {
        fail("rdtsc timing requires x86/x86_64");
    }

    if (const auto nominal = read_nominal_tsc_freq_hz(); nominal.has_value()) {
        return *nominal;
    }

    return calibrate_tsc_freq_hz();
}

struct object_deleter {
    void operator()(bpf_object *obj) const
    {
        if (obj != nullptr) {
            bpf_object__close(obj);
        }
    }
};

using bpf_object_ptr = std::unique_ptr<bpf_object, object_deleter>;

const char *prepare_phase_name(std::string_view io_mode)
{
    if (io_mode == "packet") {
        return "packet_prepare_ns";
    }
    if (io_mode == "staged") {
        return "input_stage_ns";
    }
    if (io_mode == "context") {
        return "context_prepare_ns";
    }
    return "map_prepare_ns";
}

const char *result_phase_name(std::string_view io_mode)
{
    if (io_mode == "packet" || io_mode == "staged") {
        return "result_extract_ns";
    }
    if (io_mode == "context") {
        return "retval_read_ns";
    }
    return "result_read_ns";
}

std::string resolve_effective_io_mode(std::string_view requested_io_mode,
                                      bpf_object *object)
{
    if (requested_io_mode != "map") {
        return std::string(requested_io_mode);
    }

    const bool has_input_map =
        bpf_object__find_map_by_name(object, "input_map") != nullptr;
    const bool has_result_map =
        bpf_object__find_map_by_name(object, "result_map") != nullptr;
    if (has_input_map && !has_result_map) {
        std::fprintf(stderr,
                     "io-mode: requested map but result_map is absent; "
                     "falling back to staged\n");
        return "staged";
    }
    return std::string(requested_io_mode);
}

class scoped_fd {
  public:
    scoped_fd() = default;

    explicit scoped_fd(int fd) : fd_(fd) {}

    scoped_fd(const scoped_fd &) = delete;
    scoped_fd &operator=(const scoped_fd &) = delete;

    scoped_fd(scoped_fd &&other) noexcept : fd_(std::exchange(other.fd_, -1)) {}

    scoped_fd &operator=(scoped_fd &&other) noexcept
    {
        if (this != &other) {
            reset();
            fd_ = std::exchange(other.fd_, -1);
        }
        return *this;
    }

    ~scoped_fd()
    {
        reset();
    }

    int get() const
    {
        return fd_;
    }

    void reset(int fd = -1)
    {
        if (fd_ >= 0) {
            close(fd_);
        }
        fd_ = fd;
    }

    int release()
    {
        return std::exchange(fd_, -1);
    }

  private:
    int fd_ = -1;
};

// The vendored libbpf UAPI header in micro's build doesn't expose the
// jit_directives tail fields yet, so issue BPF_PROG_LOAD with a local layout.
struct prog_load_attr_with_directives {
    __u32 prog_type;
    __u32 insn_cnt;
    __aligned_u64 insns;
    __aligned_u64 license;
    __u32 log_level;
    __u32 log_size;
    __aligned_u64 log_buf;
    __u32 kern_version;
    __u32 prog_flags;
    char prog_name[BPF_OBJ_NAME_LEN];
    __u32 prog_ifindex;
    __u32 expected_attach_type;
    __u32 prog_btf_fd;
    __u32 func_info_rec_size;
    __aligned_u64 func_info;
    __u32 func_info_cnt;
    __u32 line_info_rec_size;
    __aligned_u64 line_info;
    __u32 line_info_cnt;
    __u32 attach_btf_id;
    union {
        __u32 attach_prog_fd;
        __u32 attach_btf_obj_fd;
    };
    __u32 core_relo_cnt;
    __aligned_u64 fd_array;
    __aligned_u64 core_relos;
    __u32 core_relo_rec_size;
    __u32 log_true_size;
    __s32 prog_token_fd;
    __u32 fd_array_cnt;
    __aligned_u64 signature;
    __u32 signature_size;
    __s32 keyring_id;
    __s32 jit_directives_fd;
    __u32 jit_directives_flags;
};

int libbpf_log(enum libbpf_print_level, const char *fmt, va_list args)
{
    return vfprintf(stderr, fmt, args);
}

std::string libbpf_error_string(int error_code)
{
    char buffer[256];
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    return std::string(buffer);
}

bool has_skip_family(const cli_options &options, std::string_view family)
{
    return std::find(options.skip_families.begin(),
                     options.skip_families.end(),
                     family) != options.skip_families.end();
}

void append_recompile_family(std::vector<std::string> &families,
                             bool enabled,
                             std::string_view family)
{
    if (enabled) {
        families.emplace_back(family);
    }
}

bpf_program *find_program(bpf_object *object, const std::optional<std::string> &program_name)
{
    bpf_program *program = nullptr;
    if (!program_name.has_value()) {
        program = bpf_object__next_program(object, nullptr);
        if (program == nullptr) {
            fail("no program found in object");
        }
        return program;
    }

    while ((program = bpf_object__next_program(object, program)) != nullptr) {
        const char *current_name = bpf_program__name(program);
        if (current_name != nullptr && *program_name == current_name) {
            return program;
        }
    }

    fail("unable to find program named '" + *program_name + "'");
}

void configure_autoload(bpf_object *object, const std::optional<std::string> &program_name)
{
    if (!program_name.has_value()) {
        return;
    }

    bpf_program *program = nullptr;
    while ((program = bpf_object__next_program(object, program)) != nullptr) {
        const char *current_name = bpf_program__name(program);
        const bool autoload = current_name != nullptr && *program_name == current_name;
        if (bpf_program__set_autoload(program, autoload) != 0) {
            fail("unable to configure program autoload");
        }
    }
}

template <typename T>
__u64 ptr_to_u64(T *ptr)
{
    return static_cast<__u64>(reinterpret_cast<uintptr_t>(ptr));
}

bpf_prog_info load_prog_info(int program_fd)
{
    bpf_prog_info info = {};
    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD failed: " + std::string(strerror(errno)));
    }
    return info;
}

std::vector<uint8_t> load_jited_program(int program_fd, uint32_t jited_prog_len)
{
    if (jited_prog_len == 0) {
        fail("kernel reported an empty JIT image");
    }

    std::vector<uint8_t> jited_program(jited_prog_len);
    bpf_prog_info info = {};
    info.jited_prog_len = jited_prog_len;
    info.jited_prog_insns = ptr_to_u64(jited_program.data());

    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD (JIT dump) failed: " + std::string(strerror(errno)));
    }

    jited_program.resize(info.jited_prog_len);
    return jited_program;
}

/* ================================================================
 * v4: load xlated BPF bytecode from kernel
 * ================================================================ */

std::vector<uint8_t> load_xlated_program(int program_fd, uint32_t xlated_prog_len)
{
    if (xlated_prog_len == 0) {
        fail("kernel reported an empty xlated program");
    }

    std::vector<uint8_t> xlated(xlated_prog_len);
    bpf_prog_info info = {};
    info.xlated_prog_len = xlated_prog_len;
    info.xlated_prog_insns = ptr_to_u64(xlated.data());

    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD (xlated dump) failed: " + std::string(strerror(errno)));
    }

    xlated.resize(info.xlated_prog_len);
    return xlated;
}

std::vector<uint8_t> build_packet_input(const std::vector<uint8_t> &input_bytes)
{
    std::vector<uint8_t> packet(input_bytes.size() + sizeof(uint64_t), 0);
    std::copy(input_bytes.begin(), input_bytes.end(), packet.begin() + sizeof(uint64_t));
    return packet;
}

uint64_t read_u64_result(const uint8_t *data, size_t length)
{
    if (length < sizeof(uint64_t)) {
        fail("result buffer shorter than 8 bytes");
    }
    uint64_t result = 0;
    std::memcpy(&result, data, sizeof(result));
    return result;
}

int sys_memfd_create(const char *name, unsigned int flags)
{
    return static_cast<int>(syscall(__NR_memfd_create, name, flags));
}

void write_full_or_fail(int fd, const uint8_t *data, size_t size)
{
    size_t written = 0;
    while (written < size) {
        const ssize_t rc = write(fd, data + written, size - written);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            fail("unable to write directive memfd: " + std::string(strerror(errno)));
        }
        written += static_cast<size_t>(rc);
    }
}

std::string trim_log_buffer(const std::vector<char> &buffer)
{
    size_t length = 0;
    while (length < buffer.size() && buffer[length] != '\0') {
        ++length;
    }
    while (length > 0 && (buffer[length - 1] == '\n' || buffer[length - 1] == '\r')) {
        --length;
    }
    return std::string(buffer.data(), length);
}

scoped_fd build_sealed_directive_memfd(const std::filesystem::path &path)
{
    const auto blob = read_binary_file(path);

    scoped_fd memfd(sys_memfd_create("bpf-jit-directives", MFD_CLOEXEC | MFD_ALLOW_SEALING));
    if (memfd.get() < 0) {
        fail("memfd_create failed for directive blob: " + std::string(strerror(errno)));
    }

    if (!blob.empty()) {
        write_full_or_fail(memfd.get(), blob.data(), blob.size());
    }

    const int seals = F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK;
    if (fcntl(memfd.get(), F_ADD_SEALS, seals) != 0) {
        fail("unable to seal directive memfd: " + std::string(strerror(errno)));
    }

    return memfd;
}

std::unordered_map<uint32_t, int> create_kernel_maps(bpf_object *object, const program_image &image)
{
    std::unordered_map<uint32_t, int> map_fds;
    map_fds.reserve(image.maps.size());

    for (const auto &spec : image.maps) {
        bpf_map_create_opts create_opts = {};
        create_opts.sz = sizeof(create_opts);
        scoped_fd created_map(bpf_map_create(
            static_cast<enum bpf_map_type>(spec.type),
            spec.name.c_str(),
            spec.key_size,
            spec.value_size,
            spec.max_entries,
            &create_opts));
        if (created_map.get() < 0) {
            fail("bpf_map_create(" + spec.name + ") failed: " + libbpf_error_string(-created_map.get()));
        }

        bpf_map *object_map = bpf_object__find_map_by_name(object, spec.name.c_str());
        if (object_map == nullptr) {
            fail("unable to find opened object map named '" + spec.name + "'");
        }

        const int reuse_error = bpf_map__reuse_fd(object_map, created_map.get());
        if (reuse_error != 0) {
            fail("bpf_map__reuse_fd(" + spec.name + ") failed: " + libbpf_error_string(-reuse_error));
        }

        const int object_map_fd = bpf_map__fd(object_map);
        if (object_map_fd < 0) {
            fail("unable to obtain reused map fd for '" + spec.name + "'");
        }

        map_fds.emplace(spec.id, object_map_fd);
    }

    return map_fds;
}

void relocate_map_fds(program_image &image, const std::unordered_map<uint32_t, int> &map_fds)
{
    if (image.code.size() % sizeof(bpf_insn) != 0) {
        fail("program image does not contain aligned BPF instructions");
    }

    auto *insns = reinterpret_cast<bpf_insn *>(image.code.data());
    const size_t insn_count = image.code.size() / sizeof(bpf_insn);
    constexpr uint8_t kLdImm64 = BPF_LD | BPF_DW | BPF_IMM;

    for (size_t index = 0; index < insn_count; ++index) {
        auto &insn = insns[index];
        if (insn.code != kLdImm64 || insn.src_reg != BPF_PSEUDO_MAP_FD) {
            continue;
        }

        const auto map_iter = map_fds.find(static_cast<uint32_t>(insn.imm));
        if (map_iter == map_fds.end()) {
            fail("unable to resolve relocated map fd for synthetic map id " + std::to_string(insn.imm));
        }

        insn.imm = map_iter->second;
    }
}

int manual_bpf_prog_load(program_image &image, int directive_memfd)
{
    if (image.prog_type == 0) {
        fail("unable to determine program type for manual BPF_PROG_LOAD");
    }
    if (image.license.empty()) {
        fail("unable to determine program license for manual BPF_PROG_LOAD");
    }
    if (image.code.size() % sizeof(bpf_insn) != 0) {
        fail("program image does not contain aligned BPF instructions");
    }

    prog_load_attr_with_directives attr = {};
    attr.prog_type = image.prog_type;
    attr.expected_attach_type = image.expected_attach_type;
    attr.insn_cnt = static_cast<__u32>(image.code.size() / sizeof(bpf_insn));
    attr.insns = ptr_to_u64(reinterpret_cast<bpf_insn *>(image.code.data()));
    attr.license = ptr_to_u64(image.license.c_str());
    if (directive_memfd >= 0) {
        attr.prog_flags |= BPF_F_JIT_DIRECTIVES_FD;
        attr.jit_directives_fd = directive_memfd;
        attr.jit_directives_flags = 0;
    }

    std::vector<char> verifier_log(1U << 20, '\0');
    if (!image.program_name.empty()) {
        std::snprintf(attr.prog_name, sizeof(attr.prog_name), "%s", image.program_name.c_str());
    }

    int last_errno = 0;
    constexpr int max_attempts = 5;
    bool with_log = true;
    while (true) {
        attr.log_level = with_log ? 1 : 0;
        attr.log_size = with_log ? static_cast<__u32>(verifier_log.size()) : 0;
        attr.log_buf = with_log ? ptr_to_u64(verifier_log.data()) : 0;

        for (int attempt = 0; attempt < max_attempts; ++attempt) {
            std::fill(verifier_log.begin(), verifier_log.end(), '\0');
            const int fd =
                static_cast<int>(syscall(__NR_bpf, BPF_PROG_LOAD, &attr, sizeof(attr)));
            if (fd >= 0) {
                return fd;
            }

            last_errno = errno;
            if (last_errno != EAGAIN) {
                break;
            }
        }

        if (last_errno == ENOSPC && with_log) {
            with_log = false;
            continue;
        }
        break;
    }

    std::string message = "manual BPF_PROG_LOAD failed: " + std::string(strerror(last_errno));
    if (last_errno == E2BIG) {
        message += " (kernel may not support jit_directives_fd on BPF_PROG_LOAD)";
    }
    const auto verifier_text = trim_log_buffer(verifier_log);
    if (!verifier_text.empty()) {
        message += "\n" + verifier_text;
    }
    fail(message);
}

int manual_load_program(bpf_object *object, const cli_options &options)
{
    auto image = load_program_image(options.program, options.program_name);
    const auto map_fds = create_kernel_maps(object, image);
    relocate_map_fds(image, map_fds);

    scoped_fd directive_memfd;
    if (options.directive_blob.has_value()) {
        directive_memfd = build_sealed_directive_memfd(*options.directive_blob);
    }
    return manual_bpf_prog_load(image, directive_memfd.get());
}

} // namespace

sample_result run_kernel(const cli_options &options)
{
    libbpf_set_print(libbpf_log);

    const auto memory_prepare_start = std::chrono::steady_clock::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    const auto memory_prepare_end = std::chrono::steady_clock::now();
    if (options.input_size != 0 && input_bytes.size() < options.input_size) {
        input_bytes.resize(options.input_size, 0);
    }

    const auto object_open_start = std::chrono::steady_clock::now();
    bpf_object_open_opts open_opts = {};
    open_opts.sz = sizeof(open_opts);
    if (options.btf_custom_path.has_value()) {
        open_opts.btf_custom_path = options.btf_custom_path->c_str();
    }
    bpf_object *raw_object = bpf_object__open_file(options.program.c_str(), &open_opts);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        fail("bpf_object__open_file failed: " + libbpf_error_string(open_error));
    }
    const auto object_open_end = std::chrono::steady_clock::now();
    bpf_object_ptr object(raw_object);
    configure_autoload(object.get(), options.program_name);

    scoped_fd manual_program_fd;
    int program_fd = -1;
    const auto object_load_start = std::chrono::steady_clock::now();
    if (options.directive_blob.has_value() || options.manual_load) {
        program_fd = manual_load_program(object.get(), options);
        manual_program_fd.reset(program_fd);
    } else {
        const int load_error = bpf_object__load(object.get());
        if (load_error != 0) {
            fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
        }

        bpf_program *program = find_program(object.get(), options.program_name);
        program_fd = bpf_program__fd(program);
        if (program_fd < 0) {
            fail("unable to obtain program fd");
        }
    }
    const auto object_load_end = std::chrono::steady_clock::now();
    const std::string effective_io_mode =
        resolve_effective_io_mode(options.io_mode, object.get());

    /* v4 post-load re-JIT: apply policy blob via BPF_PROG_JIT_RECOMPILE */
    std::chrono::steady_clock::time_point recompile_start {};
    std::chrono::steady_clock::time_point recompile_end {};
    const bool want_recompile_cmov =
        options.recompile_cmov || options.recompile_all;
    const bool want_recompile_wide =
        options.recompile_wide || options.recompile_all;
    const bool want_recompile_rotate =
        options.recompile_rotate || options.recompile_rotate_rorx ||
        options.recompile_all;
    const bool want_recompile_lea =
        options.recompile_lea || options.recompile_all;
    const bool want_recompile_extract =
        options.recompile_extract || options.recompile_all;
    const bool skip_cmov = has_skip_family(options, "cmov");
    const bool skip_wide = has_skip_family(options, "wide");
    const bool skip_rotate = has_skip_family(options, "rotate");
    const bool skip_lea = has_skip_family(options, "lea");
    const bool skip_extract = has_skip_family(options, "extract");
    const bool do_recompile_cmov = want_recompile_cmov && !skip_cmov;
    const bool do_recompile_wide = want_recompile_wide && !skip_wide;
    const bool do_recompile_rotate = want_recompile_rotate && !skip_rotate;
    const bool do_recompile_lea = want_recompile_lea && !skip_lea;
    const bool do_recompile_extract =
        want_recompile_extract && !skip_extract;
    directive_scan_summary directive_scan {};
    recompile_summary recompile {};
    recompile.skipped_families = options.skip_families;
    append_recompile_family(recompile.requested_families, do_recompile_cmov,
                            "cmov");
    append_recompile_family(recompile.requested_families, do_recompile_wide,
                            "wide");
    append_recompile_family(recompile.requested_families, do_recompile_rotate,
                            "rotate");
    append_recompile_family(recompile.requested_families, do_recompile_lea,
                            "lea");
    append_recompile_family(recompile.requested_families,
                            do_recompile_extract, "extract");
    recompile.requested =
        do_recompile_cmov || do_recompile_wide || do_recompile_rotate ||
        do_recompile_lea || do_recompile_extract ||
        options.policy_blob.has_value();
    if (options.policy_blob.has_value()) {
        recompile.mode = "policy-blob";
    } else if (do_recompile_cmov || do_recompile_wide || do_recompile_rotate ||
               do_recompile_lea || do_recompile_extract) {
        recompile.mode = "auto-scan-v5";
    }
    if (do_recompile_cmov || do_recompile_wide || do_recompile_rotate ||
        do_recompile_lea || do_recompile_extract ||
        options.policy_blob.has_value()) {
        auto pre_info = load_prog_info(program_fd);

        std::vector<uint8_t> policy_data;

        if (do_recompile_cmov || do_recompile_wide || do_recompile_rotate ||
            do_recompile_lea || do_recompile_extract) {
            /*
             * Auto-scan the xlated BPF program for enabled pattern types
             * and build the combined policy blob from post-verifier bytecode.
             */
            auto xlated = load_xlated_program(program_fd, pre_info.xlated_prog_len);

            if (want_recompile_cmov && skip_cmov) {
                fprintf(stderr, "recompile-cmov: skipped by --skip-families\n");
            }
            if (want_recompile_wide && skip_wide) {
                fprintf(stderr, "recompile-wide: skipped by --skip-families\n");
            }
            if (want_recompile_rotate && skip_rotate) {
                fprintf(stderr, "recompile-rotate: skipped by --skip-families\n");
            }
            if (want_recompile_lea && skip_lea) {
                fprintf(stderr, "recompile-lea: skipped by --skip-families\n");
            }
            if (want_recompile_extract && skip_extract) {
                fprintf(stderr, "recompile-extract: skipped by --skip-families\n");
            }

            /*
             * Scan the full translated program, including subprogs.
             * Kernel-side validators reject any directive site that would
             * cross a subprog boundary, so userspace does not need to trim
             * scanning to the main entry subprog.
             */
            directive_scan.performed = true;
            uint32_t scan_len = static_cast<uint32_t>(xlated.size());
            const auto summary = bpf_jit_scanner::scan_v5_builtin(
                xlated.data(), scan_len,
                bpf_jit_scanner::V5ScanOptions {
                    .scan_cmov = do_recompile_cmov,
                    .scan_wide = do_recompile_wide,
                    .scan_rotate = do_recompile_rotate,
                    .scan_lea = do_recompile_lea,
                    .scan_extract = do_recompile_extract,
                    .use_rorx = options.recompile_rotate_rorx,
                });

            directive_scan.cmov_sites = summary.cmov_sites;
            directive_scan.wide_sites = summary.wide_sites;
            directive_scan.rotate_sites = summary.rotate_sites;
            directive_scan.lea_sites = summary.lea_sites;
            directive_scan.bitfield_sites = summary.bitfield_sites;

            auto print_v5_scan_status = [&](bool enabled,
                                            uint64_t site_count,
                                            const char *label,
                                            const char *site_name) {
                if (!enabled) {
                    return;
                }
                if (site_count == 0) {
                    fprintf(stderr, "%s: no %s sites found in xlated program (%u insns)\n",
                            label, site_name, scan_len / 8);
                    return;
                }
                fprintf(stderr, "%s: found %llu %s sites in xlated program (%u insns)\n",
                        label,
                        static_cast<unsigned long long>(site_count),
                        site_name,
                        scan_len / 8);
            };

            print_v5_scan_status(do_recompile_cmov, directive_scan.cmov_sites,
                                 "recompile-cmov", "cmov");
            print_v5_scan_status(do_recompile_wide, directive_scan.wide_sites,
                                 "recompile-wide", "wide_load");
            print_v5_scan_status(do_recompile_rotate, directive_scan.rotate_sites,
                                 "recompile-rotate", "rotate");
            print_v5_scan_status(do_recompile_lea, directive_scan.lea_sites,
                                 "recompile-lea", "addr_calc");
            print_v5_scan_status(do_recompile_extract,
                                 directive_scan.bitfield_sites,
                                 "recompile-extract", "bitfield_extract");

            if (!summary.rules.empty()) {
                policy_data = bpf_jit_scanner::build_policy_blob_v5(
                    pre_info.xlated_prog_len / 8,
                    pre_info.tag,
                    summary.rules);
            }
        } else {
            /*
             * Use explicit policy blob file, patching prog_tag and insn_cnt
             * to match the kernel's view.
             */
            policy_data = read_binary_file(*options.policy_blob);
            if (policy_data.size() >= 28) {
                const uint32_t xlated_insn_cnt = pre_info.xlated_prog_len / 8;
                std::memcpy(policy_data.data() + 16, &xlated_insn_cnt, sizeof(xlated_insn_cnt));
                std::memcpy(policy_data.data() + 20, pre_info.tag, 8);
            }
        }

        if (!policy_data.empty()) {
            recompile.policy_generated = true;
            recompile.policy_bytes = policy_data.size();
            /* Build a sealed memfd from the policy data */
            scoped_fd patched_memfd(sys_memfd_create("bpf-jit-policy", MFD_CLOEXEC | MFD_ALLOW_SEALING));
            if (patched_memfd.get() < 0) {
                fail("memfd_create failed for policy blob: " + std::string(strerror(errno)));
            }
            write_full_or_fail(patched_memfd.get(), policy_data.data(), policy_data.size());
            const int seals = F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK;
            if (fcntl(patched_memfd.get(), F_ADD_SEALS, seals) != 0) {
                fail("unable to seal policy memfd: " + std::string(strerror(errno)));
            }

            recompile_start = std::chrono::steady_clock::now();
            recompile.syscall_attempted = true;

            /*
             * BPF_PROG_JIT_RECOMPILE syscall.
             * Use raw struct since host bpf.h doesn't have jit_recompile member.
             */
            struct {
                __u32 prog_fd;
                __s32 policy_fd;
                __u32 flags;
            } __attribute__((aligned(8))) recompile_attr = {};
            recompile_attr.prog_fd = static_cast<__u32>(program_fd);
            recompile_attr.policy_fd = patched_memfd.get();
            recompile_attr.flags = 0;

            /* Pad to sizeof(union bpf_attr) */
            alignas(8) char attr_buf[256] = {};
            static_assert(sizeof(recompile_attr) <= sizeof(attr_buf));
            std::memcpy(attr_buf, &recompile_attr, sizeof(recompile_attr));

            const int rc = static_cast<int>(syscall(__NR_bpf, BPF_PROG_JIT_RECOMPILE,
                                                    attr_buf, sizeof(attr_buf)));
            recompile_end = std::chrono::steady_clock::now();
            if (rc != 0) {
                recompile.error =
                    "BPF_PROG_JIT_RECOMPILE failed: " + std::string(strerror(errno)) +
                    " (errno=" + std::to_string(errno) + ")";
                fprintf(stderr, "BPF_PROG_JIT_RECOMPILE failed: %s (errno=%d)\n",
                        strerror(errno), errno);
                /* Non-fatal: continue with stock JIT */
            } else {
                recompile.applied = true;
            }
        }
    }

    const auto program_info = load_prog_info(program_fd);
    if (options.dump_jit) {
        const auto jited_program = load_jited_program(program_fd, program_info.jited_prog_len);
        const auto dump_path = std::filesystem::path(benchmark_name_for_program(options.program) + ".kernel.bin");
        write_binary_file(dump_path, jited_program.data(), jited_program.size());
    }
    if (options.dump_xlated.has_value()) {
        const auto xlated_program = load_xlated_program(program_fd, program_info.xlated_prog_len);
        write_binary_file(*options.dump_xlated, xlated_program.data(), xlated_program.size());
    }

    sample_result sample;
    sample.compile_ns = elapsed_ns(object_open_start, object_open_end) +
                        elapsed_ns(object_load_start, object_load_end) +
                        elapsed_ns(recompile_start, recompile_end);
    sample.jited_prog_len = program_info.jited_prog_len;
    sample.xlated_prog_len = program_info.xlated_prog_len;
    sample.code_size = {
        .bpf_bytecode_bytes = program_info.xlated_prog_len,
        .native_code_bytes = program_info.jited_prog_len,
    };
    sample.directive_scan = directive_scan;
    sample.recompile = recompile;
    if (options.compile_only) {
        sample.phases_ns = {
            {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
            {"object_open_ns", elapsed_ns(object_open_start, object_open_end)},
            {"object_load_ns", elapsed_ns(object_load_start, object_load_end)},
        };
        return sample;
    }

    std::chrono::steady_clock::time_point exec_input_prepare_start {};
    std::chrono::steady_clock::time_point exec_input_prepare_end {};
    std::chrono::steady_clock::time_point result_read_start {};
    std::chrono::steady_clock::time_point result_read_end {};

    std::vector<uint8_t> packet;
    std::vector<uint8_t> packet_out;
    std::vector<uint8_t> context_in;
    uint64_t result = 0;
    int result_fd = -1;
    uint32_t key = 0;

    if (effective_io_mode == "map") {
        bpf_map *input_map = bpf_object__find_map_by_name(object.get(), "input_map");
        bpf_map *result_map = bpf_object__find_map_by_name(object.get(), "result_map");
        if (input_map == nullptr || result_map == nullptr) {
            fail("required maps input_map/result_map not found");
        }

        const uint32_t input_value_size = bpf_map__value_size(input_map);
        if (input_bytes.size() < input_value_size) {
            input_bytes.resize(input_value_size, 0);
        }

        const int input_fd = bpf_map__fd(input_map);
        result_fd = bpf_map__fd(result_map);
        if (input_fd < 0 || result_fd < 0) {
            fail("unable to obtain map fd");
        }

        uint64_t zero = 0;
        exec_input_prepare_start = std::chrono::steady_clock::now();
        if (bpf_map_update_elem(input_fd, &key, input_bytes.data(), BPF_ANY) != 0) {
            fail("bpf_map_update_elem(input_map) failed: " + std::string(strerror(errno)));
        }
        if (bpf_map_update_elem(result_fd, &key, &zero, BPF_ANY) != 0) {
            fail("bpf_map_update_elem(result_map) failed: " + std::string(strerror(errno)));
        }
        exec_input_prepare_end = std::chrono::steady_clock::now();

        packet.assign(64, 0);
        packet_out.assign(packet.size(), 0);
    } else if (effective_io_mode == "staged") {
        bpf_map *input_map = bpf_object__find_map_by_name(object.get(), "input_map");
        if (input_map != nullptr) {
            const uint32_t input_value_size = bpf_map__value_size(input_map);
            if (input_bytes.size() < input_value_size) {
                input_bytes.resize(input_value_size, 0);
            }

            const int input_fd = bpf_map__fd(input_map);
            if (input_fd < 0) {
                fail("unable to obtain input_map fd");
            }

            exec_input_prepare_start = std::chrono::steady_clock::now();
            if (bpf_map_update_elem(input_fd, &key, input_bytes.data(), BPF_ANY) != 0) {
                fail("bpf_map_update_elem(input_map) failed: " + std::string(strerror(errno)));
            }
            exec_input_prepare_end = std::chrono::steady_clock::now();

            packet.assign(64, 0);
            packet_out.assign(packet.size(), 0);
        } else {
            // Packet-backed XDP programs use the same result path, but their
            // input is carried by the test packet rather than an input map.
            exec_input_prepare_start = std::chrono::steady_clock::now();
            if (options.raw_packet) {
                packet = input_bytes;
            } else {
                packet = build_packet_input(input_bytes);
            }
            packet_out.assign(packet.size(), 0);
            exec_input_prepare_end = std::chrono::steady_clock::now();
        }
    } else if (effective_io_mode == "context") {
        exec_input_prepare_start = std::chrono::steady_clock::now();
        context_in = input_bytes;
        exec_input_prepare_end = std::chrono::steady_clock::now();
    } else {
        exec_input_prepare_start = std::chrono::steady_clock::now();
        if (options.raw_packet) {
            packet = input_bytes;
        } else {
            packet = build_packet_input(input_bytes);
        }
        packet_out.assign(packet.size(), 0);
        exec_input_prepare_end = std::chrono::steady_clock::now();
    }

    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    const uint32_t effective_repeat =
        effective_io_mode == "context" ? 1u : options.repeat;
    test_opts.repeat = effective_io_mode == "context" ? 0u : options.repeat;
    if (!packet.empty()) {
        test_opts.data_in = packet.data();
        test_opts.data_size_in = packet.size();
        test_opts.data_out = packet_out.data();
        test_opts.data_size_out = packet_out.size();
    }
    if (!context_in.empty()) {
        test_opts.ctx_in = context_in.data();
        test_opts.ctx_size_in = context_in.size();
    }

    const uint64_t tsc_freq_hz = kHasTscMeasurement ? detect_tsc_freq_hz() : 0;

    std::chrono::steady_clock::time_point run_wall_start {};
    std::chrono::steady_clock::time_point run_wall_end {};
    uint64_t tsc_before = 0;
    uint64_t tsc_after = 0;
    int run_error = 0;
    const perf_counter_options perf_options = {
        .enabled = options.perf_counters,
        .include_kernel = true,
        .scope = options.perf_scope,
    };
    auto perf_counters = measure_perf_counters(
        perf_options,
        [&]() {
            run_wall_start = std::chrono::steady_clock::now();
            tsc_before = rdtsc_start();
            run_error = bpf_prog_test_run_opts(program_fd, &test_opts);
            tsc_after = rdtsc_end();
            run_wall_end = std::chrono::steady_clock::now();
        });
    if (options.perf_scope == "full_repeat_avg") {
        const uint32_t repeat = effective_repeat;
        for (auto &counter : perf_counters.counters) {
            counter.value /= repeat;
        }
    }
    if (run_error != 0) {
        fail("bpf_prog_test_run_opts failed: " + std::string(strerror(errno)));
    }

    if (effective_io_mode == "packet" || effective_io_mode == "staged") {
        result_read_start = std::chrono::steady_clock::now();
        result = read_u64_result(packet_out.data(), packet_out.size());
        result_read_end = std::chrono::steady_clock::now();
    } else if (effective_io_mode == "context") {
        result_read_start = std::chrono::steady_clock::now();
        result = test_opts.retval;
        result_read_end = std::chrono::steady_clock::now();
    } else {
        result_read_start = std::chrono::steady_clock::now();
        if (bpf_map_lookup_elem(result_fd, &key, &result) != 0) {
            fail("bpf_map_lookup_elem(result_map) failed: " + std::string(strerror(errno)));
        }
        result_read_end = std::chrono::steady_clock::now();
    }

    sample.exec_ns = test_opts.duration;
    if (kHasTscMeasurement && tsc_freq_hz > 0 && tsc_after > tsc_before) {
        const uint64_t total_cycles = tsc_after - tsc_before;
        const uint32_t repeat = effective_repeat;
        sample.exec_cycles = static_cast<uint64_t>(std::llround(
            static_cast<long double>(total_cycles) / static_cast<long double>(repeat)));
        sample.tsc_freq_hz = tsc_freq_hz;
        sample.wall_exec_ns = static_cast<uint64_t>(std::llround(
            (static_cast<long double>(total_cycles) * 1000000000.0L) /
            (static_cast<long double>(tsc_freq_hz) * static_cast<long double>(repeat))));
    }
    if (sample.exec_ns == 0 && sample.wall_exec_ns.has_value()) {
        sample.exec_ns = *sample.wall_exec_ns;
        sample.timing_source = "wall_tsc";
    } else {
        sample.timing_source = "ktime";
    }
    sample.result = result;
    sample.retval = test_opts.retval;
    sample.phases_ns = {
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {"object_open_ns", elapsed_ns(object_open_start, object_open_end)},
        {"object_load_ns", elapsed_ns(object_load_start, object_load_end)},
        {prepare_phase_name(effective_io_mode),
         elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)},
        {"prog_run_wall_ns", elapsed_ns(run_wall_start, run_wall_end)},
        {result_phase_name(effective_io_mode),
         elapsed_ns(result_read_start, result_read_end)},
    };
    sample.perf_counters = std::move(perf_counters);
    return sample;
}
