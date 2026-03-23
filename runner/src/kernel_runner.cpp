#include "micro_exec.hpp"

#include <arpa/inet.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>

#include <algorithm>
#include <array>
#include <cerrno>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <memory>
#include <string>
#include <string_view>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/un.h>
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

/* v2 REJIT syscall subcommand */
#ifndef BPF_PROG_REJIT
#define BPF_PROG_REJIT 39
#endif

namespace {

using clock_type = std::chrono::steady_clock;
constexpr size_t kEthernetHeaderSize = 14;
constexpr std::string_view kKatranBalancerProgramName = "balancer_ingress";
constexpr uint32_t kKatranVipNum = 0;
constexpr uint32_t kKatranRealNum = 1;
constexpr uint32_t kKatranVipFlags = 1U << 1;
constexpr uint32_t kKatranChRingSize = 65537;
constexpr size_t kKatranEncapHeadroom = 64;

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
    asm volatile("rdtsc; lfence" : "=a"(lo), "=d"(hi) :: "memory");
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

struct kernel_test_run_context {
    int program_fd = -1;
    bpf_test_run_opts *test_opts = nullptr;
    uint32_t effective_repeat = 1;
    uint64_t tsc_freq_hz = 0;
    std::vector<uint8_t> *packet_out = nullptr;
    __sk_buff *context_out = nullptr;
    uint32_t context_out_size = 0;
    int result_fd = -1;
    uint32_t result_key = 0;
    bool reset_result_map = false;
};

struct kernel_test_run_measurement {
    uint64_t exec_ns = 0;
    std::optional<uint64_t> wall_exec_ns;
    std::optional<uint64_t> exec_cycles;
    uint32_t retval = 0;
    std::chrono::steady_clock::time_point wall_start {};
    std::chrono::steady_clock::time_point wall_end {};
};

struct kernel_run_pass_result {
    kernel_test_run_measurement measurement {};
    perf_counter_capture perf_counters {};
};

bool katran_balancer_fixture_requested(const cli_options &options)
{
    return options.program_name.has_value() &&
           *options.program_name == kKatranBalancerProgramName;
}

std::array<uint8_t, 4> parse_ipv4_address(std::string_view text)
{
    std::array<uint8_t, 4> address {};
    const std::string rendered(text);
    if (inet_pton(AF_INET, rendered.c_str(), address.data()) != 1) {
        fail("unable to parse IPv4 address: " + rendered);
    }
    return address;
}

std::array<uint8_t, 6> parse_mac_address(std::string_view text)
{
    std::array<uint8_t, 6> mac {};
    unsigned int octets[6] = {};
    const std::string rendered(text);
    if (std::sscanf(
            rendered.c_str(),
            "%2x:%2x:%2x:%2x:%2x:%2x",
            &octets[0],
            &octets[1],
            &octets[2],
            &octets[3],
            &octets[4],
            &octets[5]) != 6) {
        fail("unable to parse MAC address: " + rendered);
    }
    for (size_t index = 0; index < mac.size(); ++index) {
        mac[index] = static_cast<uint8_t>(octets[index] & 0xFFU);
    }
    return mac;
}

void update_map_elem_or_fail(
    int fd,
    const void *key,
    const void *value,
    std::string_view map_name)
{
    if (bpf_map_update_elem(fd, key, value, BPF_ANY) != 0) {
        fail(
            "bpf_map_update_elem(" + std::string(map_name) + ") failed: " +
            std::string(strerror(errno)));
    }
}

std::array<uint8_t, 8> build_katran_ctl_value()
{
    std::array<uint8_t, 8> value {};
    const auto mac = parse_mac_address("02:00:00:00:00:0b");
    std::copy(mac.begin(), mac.end(), value.begin());
    return value;
}

std::array<uint8_t, 20> build_katran_vip_key()
{
    std::array<uint8_t, 20> key {};
    const auto vip = parse_ipv4_address("10.100.1.1");
    std::copy(vip.begin(), vip.end(), key.begin());
    key[16] = static_cast<uint8_t>((8080U >> 8) & 0xFFU);
    key[17] = static_cast<uint8_t>(8080U & 0xFFU);
    key[18] = IPPROTO_TCP;
    return key;
}

std::array<uint8_t, 8> build_katran_vip_value()
{
    std::array<uint8_t, 8> value {};
    const uint32_t flags = kKatranVipFlags;
    const uint32_t vip_num = kKatranVipNum;
    std::memcpy(value.data(), &flags, sizeof(flags));
    std::memcpy(value.data() + sizeof(flags), &vip_num, sizeof(vip_num));
    return value;
}

std::array<uint8_t, 20> build_katran_real_value()
{
    std::array<uint8_t, 20> value {};
    const auto real = parse_ipv4_address("10.200.0.2");
    std::copy(real.begin(), real.end(), value.begin());
    return value;
}

void initialize_katran_test_fixture(bpf_object *object)
{
    bpf_map *vip_map = bpf_object__find_map_by_name(object, "vip_map");
    bpf_map *reals_map = bpf_object__find_map_by_name(object, "reals");
    bpf_map *rings_map = bpf_object__find_map_by_name(object, "ch_rings");
    bpf_map *ctl_array_map = bpf_object__find_map_by_name(object, "ctl_array");
    if (vip_map == nullptr || reals_map == nullptr || rings_map == nullptr ||
        ctl_array_map == nullptr) {
        /* The object has a program named balancer_ingress but lacks the
         * Katran-specific maps.  This happens for linux-selftest programs
         * that reuse the name.  Skip fixture initialization silently. */
        fprintf(stderr, "katran fixture: maps not found, skipping\n");
        return;
    }

    const int vip_fd = bpf_map__fd(vip_map);
    const int reals_fd = bpf_map__fd(reals_map);
    const int rings_fd = bpf_map__fd(rings_map);
    const int ctl_fd = bpf_map__fd(ctl_array_map);
    if (vip_fd < 0 || reals_fd < 0 || rings_fd < 0 || ctl_fd < 0) {
        fail("unable to obtain Katran fixture map fd");
    }

    const uint32_t zero = 0;
    const uint32_t real_num = kKatranRealNum;
    const auto ctl_value = build_katran_ctl_value();
    const auto vip_key = build_katran_vip_key();
    const auto vip_value = build_katran_vip_value();
    const auto real_value = build_katran_real_value();

    update_map_elem_or_fail(ctl_fd, &zero, ctl_value.data(), "ctl_array");
    update_map_elem_or_fail(vip_fd, vip_key.data(), vip_value.data(), "vip_map");
    update_map_elem_or_fail(reals_fd, &real_num, real_value.data(), "reals");
    for (uint32_t ring_pos = 0; ring_pos < kKatranChRingSize; ++ring_pos) {
        const uint32_t key = (kKatranVipNum * kKatranChRingSize) + ring_pos;
        update_map_elem_or_fail(rings_fd, &key, &real_num, "ch_rings");
    }
}

size_t packet_output_capacity(const cli_options &options, size_t packet_size)
{
    if (katran_balancer_fixture_requested(options)) {
        return std::max(packet_size + kKatranEncapHeadroom, static_cast<size_t>(128));
    }
    return packet_size;
}

void reset_kernel_test_run_state(kernel_test_run_context &context)
{
    if (context.test_opts == nullptr) {
        fail("internal error: missing test run options");
    }

    context.test_opts->duration = 0;
    context.test_opts->retval = 0;

    if (context.packet_out != nullptr) {
        std::fill(context.packet_out->begin(), context.packet_out->end(), 0);
        context.test_opts->data_out =
            context.packet_out->empty() ? nullptr : context.packet_out->data();
        context.test_opts->data_size_out =
            static_cast<__u32>(context.packet_out->size());
    }

    if (context.context_out != nullptr) {
        std::memset(context.context_out, 0, sizeof(*context.context_out));
        context.test_opts->ctx_out = context.context_out;
        context.test_opts->ctx_size_out = context.context_out_size;
    }

    if (context.reset_result_map) {
        uint64_t zero = 0;
        if (bpf_map_update_elem(context.result_fd, &context.result_key, &zero,
                                BPF_ANY) != 0) {
            fail("bpf_map_update_elem(result_map) failed: " +
                 std::string(strerror(errno)));
        }
    }
}

kernel_test_run_measurement execute_kernel_test_run(
    kernel_test_run_context &context)
{
    reset_kernel_test_run_state(context);

    kernel_test_run_measurement measurement {};
    uint64_t tsc_before = 0;
    uint64_t tsc_after = 0;

    measurement.wall_start = std::chrono::steady_clock::now();
    tsc_before = rdtsc_start();
    const int run_error =
        bpf_prog_test_run_opts(context.program_fd, context.test_opts);
    tsc_after = rdtsc_end();
    measurement.wall_end = std::chrono::steady_clock::now();

    if (run_error != 0) {
        fail("bpf_prog_test_run_opts failed: " + std::string(strerror(errno)));
    }

    measurement.exec_ns = context.test_opts->duration;
    measurement.retval = context.test_opts->retval;

    if (kHasTscMeasurement && context.tsc_freq_hz > 0 &&
        tsc_after > tsc_before) {
        const uint64_t total_cycles = tsc_after - tsc_before;
        const uint32_t repeat = context.effective_repeat;
        measurement.exec_cycles = static_cast<uint64_t>(std::llround(
            static_cast<long double>(total_cycles) /
            static_cast<long double>(repeat)));
        measurement.wall_exec_ns = static_cast<uint64_t>(std::llround(
            (static_cast<long double>(total_cycles) * 1000000000.0L) /
            (static_cast<long double>(context.tsc_freq_hz) *
             static_cast<long double>(repeat))));
    }

    return measurement;
}

kernel_run_pass_result execute_kernel_measurement_pass(
    kernel_test_run_context &context,
    const cli_options &options,
    uint32_t warmup_repeat,
    bool collect_perf_counters)
{
    for (uint32_t warmup_index = 0; warmup_index < warmup_repeat;
         ++warmup_index) {
        static_cast<void>(execute_kernel_test_run(context));
    }

    kernel_run_pass_result result {};
    if (!collect_perf_counters) {
        result.measurement = execute_kernel_test_run(context);
        return result;
    }

    const perf_counter_options perf_options = {
        .enabled = options.perf_counters,
        .include_kernel = true,
        .scope = options.perf_scope,
    };
    result.perf_counters = measure_perf_counters(
        perf_options,
        [&]() {
            result.measurement = execute_kernel_test_run(context);
        });

    if (options.perf_scope == "full_repeat_avg") {
        const uint32_t repeat = context.effective_repeat;
        for (auto &counter : result.perf_counters.counters) {
            counter.value /= repeat;
        }
    }

    return result;
}

bool context_mode_supports_kernel_repeat(uint32_t prog_type)
{
    switch (prog_type) {
    case BPF_PROG_TYPE_SK_LOOKUP:
    case BPF_PROG_TYPE_NETFILTER:
        return true;
    default:
        return false;
    }
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

enum class packet_context_kind {
    none,
    xdp,
    skb,
};

packet_context_kind resolve_packet_context_kind(uint32_t prog_type)
{
    switch (prog_type) {
    case BPF_PROG_TYPE_XDP:
        return packet_context_kind::xdp;
    case BPF_PROG_TYPE_SCHED_CLS:
    case BPF_PROG_TYPE_SCHED_ACT:
    case BPF_PROG_TYPE_CGROUP_SKB:
        return packet_context_kind::skb;
    default:
        return packet_context_kind::none;
    }
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

/* ================================================================
 * Unix socket client for daemon serve mode
 * ================================================================ */

struct daemon_socket_response {
    bool ok = false;
    bool applied = false;
    std::string error;
    /* Structured fields extracted from daemon's OptimizeOneResult */
    uint32_t total_sites_applied = 0;
    std::vector<std::string> passes_applied;    /* pass names that changed the program */
    int64_t insn_delta = 0;
    uint32_t verifier_retries = 0;
    std::vector<std::string> final_disabled_passes;
    /* Raw daemon JSON response — preserved verbatim for downstream embedding */
    std::string raw_json;
};

/* ---- Minimal JSON helpers (no external library dependency) ---- */

/* Extract a JSON string value for a given key from a flat/nested JSON string.
 * Handles "key":"value" and "key": "value" patterns.
 * Returns empty string if not found. */
static std::string extract_json_string(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":\"";
    const std::string pattern2 = "\"" + key + "\": \"";
    auto pos = json.find(pattern1);
    size_t val_start;
    if (pos != std::string::npos) {
        val_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos == std::string::npos) return {};
        val_start = pos + pattern2.size();
    }
    auto val_end = json.find('"', val_start);
    if (val_end == std::string::npos) return {};
    return json.substr(val_start, val_end - val_start);
}

/* Extract a JSON integer value for a given key.  Returns 0 if not found. */
static int64_t extract_json_int(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":";
    const std::string pattern2 = "\"" + key + "\": ";
    size_t val_start = std::string::npos;
    auto pos = json.find(pattern1);
    if (pos != std::string::npos) {
        val_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            val_start = pos + pattern2.size();
        }
    }
    if (val_start == std::string::npos) return 0;
    /* Skip whitespace */
    while (val_start < json.size() && json[val_start] == ' ') ++val_start;
    if (val_start >= json.size()) return 0;
    /* Handle negative numbers and parse digits */
    try {
        return std::stoll(json.substr(val_start));
    } catch (...) {
        return 0;
    }
}

/* Check if a JSON boolean key is true. */
static bool extract_json_bool(const std::string &json, const std::string &key)
{
    const std::string pat_true1 = "\"" + key + "\":true";
    const std::string pat_true2 = "\"" + key + "\": true";
    return json.find(pat_true1) != std::string::npos ||
           json.find(pat_true2) != std::string::npos;
}

/* Extract pass names that changed from the "passes" array in the JSON.
 * Looks for objects with "changed":true and extracts "pass_name". */
static std::vector<std::string> extract_changed_passes(const std::string &json)
{
    std::vector<std::string> result;
    /* Find "passes":[ section */
    auto passes_pos = json.find("\"passes\":[");
    if (passes_pos == std::string::npos) {
        passes_pos = json.find("\"passes\": [");
    }
    if (passes_pos == std::string::npos) return result;

    /* Walk through the passes array looking for changed:true entries */
    size_t pos = passes_pos;
    while (true) {
        auto obj_start = json.find('{', pos + 1);
        if (obj_start == std::string::npos) break;
        /* Find matching } — handle nesting */
        int depth = 1;
        size_t obj_end = obj_start + 1;
        while (obj_end < json.size() && depth > 0) {
            if (json[obj_end] == '{') ++depth;
            else if (json[obj_end] == '}') --depth;
            ++obj_end;
        }
        if (depth != 0) break;

        std::string pass_obj = json.substr(obj_start, obj_end - obj_start);
        if (extract_json_bool(pass_obj, "changed")) {
            std::string name = extract_json_string(pass_obj, "pass_name");
            if (!name.empty()) {
                result.push_back(name);
            }
        }
        pos = obj_end;
        /* Check if we've left the passes array */
        auto next_bracket = json.find(']', passes_pos);
        if (next_bracket != std::string::npos && pos > next_bracket) break;
    }
    return result;
}

/* Extract a JSON array of strings for a given key.
 * Handles "key":["a","b"] patterns. */
static std::vector<std::string> extract_json_string_array(const std::string &json, const std::string &key)
{
    std::vector<std::string> result;
    const std::string pattern1 = "\"" + key + "\":[";
    const std::string pattern2 = "\"" + key + "\": [";
    size_t arr_start = std::string::npos;
    auto pos = json.find(pattern1);
    if (pos != std::string::npos) {
        arr_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            arr_start = pos + pattern2.size();
        }
    }
    if (arr_start == std::string::npos) return result;

    auto arr_end = json.find(']', arr_start);
    if (arr_end == std::string::npos) return result;

    std::string arr_content = json.substr(arr_start, arr_end - arr_start);
    size_t spos = 0;
    while (true) {
        auto q1 = arr_content.find('"', spos);
        if (q1 == std::string::npos) break;
        auto q2 = arr_content.find('"', q1 + 1);
        if (q2 == std::string::npos) break;
        result.push_back(arr_content.substr(q1 + 1, q2 - q1 - 1));
        spos = q2 + 1;
    }
    return result;
}

daemon_socket_response daemon_socket_optimize(const std::string &socket_path, uint32_t prog_id)
{
    daemon_socket_response response;

    const int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        response.error = "socket() failed: " + std::string(strerror(errno));
        return response;
    }

    struct sockaddr_un addr = {};
    addr.sun_family = AF_UNIX;
    if (socket_path.size() >= sizeof(addr.sun_path)) {
        close(fd);
        response.error = "socket path too long";
        return response;
    }
    std::strncpy(addr.sun_path, socket_path.c_str(), sizeof(addr.sun_path) - 1);

    if (connect(fd, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr)) != 0) {
        close(fd);
        response.error = "connect() failed: " + std::string(strerror(errno));
        return response;
    }

    /* Send JSON request line */
    const std::string request =
        "{\"cmd\":\"optimize\",\"prog_id\":" + std::to_string(prog_id) + "}\n";
    const ssize_t written = write(fd, request.c_str(), request.size());
    if (written < 0 || static_cast<size_t>(written) != request.size()) {
        close(fd);
        response.error = "write() failed: " + std::string(strerror(errno));
        return response;
    }

    /* Read JSON response line */
    std::string buf;
    char ch;
    while (true) {
        const ssize_t n = read(fd, &ch, 1);
        if (n <= 0) {
            break;
        }
        if (ch == '\n') {
            break;
        }
        buf.push_back(ch);
    }
    close(fd);

    if (buf.empty()) {
        response.error = "empty response from daemon";
        return response;
    }

    /* Preserve raw JSON for downstream embedding */
    response.raw_json = buf;

    /* Structured JSON parsing of daemon's OptimizeOneResult */
    const std::string status = extract_json_string(buf, "status");
    response.ok = (status == "ok");

    if (response.ok) {
        /* Extract summary.applied (nested in "summary" object) */
        auto summary_pos = buf.find("\"summary\":");
        if (summary_pos != std::string::npos) {
            /* Extract the summary sub-object */
            auto brace = buf.find('{', summary_pos);
            if (brace != std::string::npos) {
                int depth = 1;
                size_t end = brace + 1;
                while (end < buf.size() && depth > 0) {
                    if (buf[end] == '{') ++depth;
                    else if (buf[end] == '}') --depth;
                    ++end;
                }
                std::string summary = buf.substr(brace, end - brace);
                response.applied = extract_json_bool(summary, "applied");
                response.total_sites_applied = static_cast<uint32_t>(
                    extract_json_int(summary, "total_sites_applied"));
                response.verifier_retries = static_cast<uint32_t>(
                    extract_json_int(summary, "verifier_retries"));
                response.final_disabled_passes =
                    extract_json_string_array(summary, "final_disabled_passes");
            }
        } else {
            /* Fallback: check top-level applied for backward compat */
            response.applied = extract_json_bool(buf, "applied");
        }

        /* Extract program.insn_delta */
        auto prog_pos = buf.find("\"program\":");
        if (prog_pos != std::string::npos) {
            auto brace = buf.find('{', prog_pos);
            if (brace != std::string::npos) {
                int depth = 1;
                size_t end = brace + 1;
                while (end < buf.size() && depth > 0) {
                    if (buf[end] == '{') ++depth;
                    else if (buf[end] == '}') --depth;
                    ++end;
                }
                std::string prog_obj = buf.substr(brace, end - brace);
                response.insn_delta = extract_json_int(prog_obj, "insn_delta");
            }
        }

        /* Extract pass names that changed */
        response.passes_applied = extract_changed_passes(buf);
    } else {
        /* Extract error message */
        std::string msg = extract_json_string(buf, "message");
        if (!msg.empty()) {
            response.error = msg;
        } else {
            response.error = "daemon returned non-ok status: " + buf;
        }
    }

    return response;
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

/* ================================================================
 * v2 REJIT: apply BPF_PROG_REJIT with provided bytecode
 * ================================================================ */

void apply_rejit(
    int program_fd,
    const bpf_insn *insns,
    uint32_t insn_cnt,
    rejit_summary &rejit,
    std::chrono::steady_clock::time_point &rejit_start,
    std::chrono::steady_clock::time_point &rejit_end)
{
    rejit.insn_cnt = insn_cnt;
    rejit.syscall_attempted = true;

    /*
     * Build the bpf_attr for BPF_PROG_REJIT.
     * Layout matches kernel's bpf_attr.rejit:
     *   __u32 prog_fd;
     *   __u32 insn_cnt;
     *   __aligned_u64 insns;
     *   __u32 log_level;
     *   __u32 log_size;
     *   __aligned_u64 log_buf;
     *   __aligned_u64 fd_array;
     *   __u32 fd_array_cnt;
     */
    struct {
        __u32 prog_fd;
        __u32 insn_cnt;
        __aligned_u64 insns;
        __u32 log_level;
        __u32 log_size;
        __aligned_u64 log_buf;
        __aligned_u64 fd_array;
        __u32 fd_array_cnt;
    } __attribute__((aligned(8))) rejit_attr = {};

    rejit_attr.prog_fd = static_cast<__u32>(program_fd);
    rejit_attr.insn_cnt = insn_cnt;
    rejit_attr.insns = ptr_to_u64(insns);
    rejit_attr.log_level = 0;
    rejit_attr.log_size = 0;
    rejit_attr.log_buf = 0;
    rejit_attr.fd_array = 0;
    rejit_attr.fd_array_cnt = 0;

    alignas(8) char attr_buf[256] = {};
    static_assert(sizeof(rejit_attr) <= sizeof(attr_buf));
    std::memcpy(attr_buf, &rejit_attr, sizeof(rejit_attr));

    rejit_start = std::chrono::steady_clock::now();
    const int rc = static_cast<int>(
        syscall(__NR_bpf, BPF_PROG_REJIT, attr_buf, sizeof(attr_buf)));
    rejit_end = std::chrono::steady_clock::now();

    if (rc != 0) {
        rejit.error = "BPF_PROG_REJIT failed: " +
                      std::string(strerror(errno)) +
                      " (errno=" + std::to_string(errno) + ")";
        fprintf(stderr, "BPF_PROG_REJIT failed: %s (errno=%d)\n",
                strerror(errno), errno);
        return;
    }

    rejit.applied = true;
}

bool skb_payload_starts_after_l2(uint32_t prog_type)
{
    return prog_type == BPF_PROG_TYPE_CGROUP_SKB;
}

std::vector<uint8_t> build_packet_input(const std::vector<uint8_t> &input_bytes,
                                        uint32_t prog_type)
{
    const size_t prefix_offset =
        skb_payload_starts_after_l2(prog_type) ? kEthernetHeaderSize : 0;
    std::vector<uint8_t> packet(prefix_offset + input_bytes.size() + sizeof(uint64_t), 0);

    if (prefix_offset == kEthernetHeaderSize) {
        packet[12] = 0x08;
        packet[13] = 0x00;
    }

    std::copy(
        input_bytes.begin(),
        input_bytes.end(),
        packet.begin() + prefix_offset + sizeof(uint64_t));
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

uint64_t read_skb_result(const __sk_buff &ctx)
{
    return static_cast<uint64_t>(ctx.cb[0]) |
           (static_cast<uint64_t>(ctx.cb[1]) << 32);
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

scoped_fd build_sealed_memfd_from_blob(const char *name,
                                       const std::vector<uint8_t> &blob,
                                       std::string_view description)
{
    scoped_fd memfd(sys_memfd_create(name, MFD_CLOEXEC | MFD_ALLOW_SEALING));
    if (memfd.get() < 0) {
        fail("memfd_create failed for " + std::string(description) + ": " +
             std::string(strerror(errno)));
    }

    if (!blob.empty()) {
        write_full_or_fail(memfd.get(), blob.data(), blob.size());
    }

    const int seals = F_SEAL_WRITE | F_SEAL_GROW | F_SEAL_SHRINK;
    if (fcntl(memfd.get(), F_ADD_SEALS, seals) != 0) {
        fail("unable to seal " + std::string(description) +
             " memfd: " + std::string(strerror(errno)));
    }

    return memfd;
}

uint64_t read_kernel_test_run_result(std::string_view effective_io_mode,
                                     bool result_from_skb_context,
                                     const std::vector<uint8_t> &packet_out,
                                     const __sk_buff &context_out,
                                     int result_fd,
                                     uint32_t key,
                                     uint32_t retval)
{
    if (effective_io_mode == "packet" || effective_io_mode == "staged") {
        if (result_from_skb_context) {
            return read_skb_result(context_out);
        }
        return read_u64_result(packet_out.data(), packet_out.size());
    }

    if (effective_io_mode == "context") {
        return retval;
    }

    uint64_t result = 0;
    if (bpf_map_lookup_elem(result_fd, &key, &result) != 0) {
        fail("bpf_map_lookup_elem(result_map) failed: " +
             std::string(strerror(errno)));
    }
    return result;
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

int manual_bpf_prog_load(program_image &image)
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

    return manual_bpf_prog_load(image);
}

} // namespace

std::vector<sample_result> run_kernel(const cli_options &options)
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
    bpf_program *prog = nullptr;
    const auto object_load_start = std::chrono::steady_clock::now();
    if (options.manual_load) {
        program_fd = manual_load_program(object.get(), options);
        manual_program_fd.reset(program_fd);
    } else {
        const int load_error = bpf_object__load(object.get());
        if (load_error != 0) {
            fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
        }

        prog = find_program(object.get(), options.program_name);
        program_fd = bpf_program__fd(prog);
        if (program_fd < 0) {
            fail("unable to obtain program fd");
        }
    }
    const auto object_load_end = std::chrono::steady_clock::now();
    const std::string effective_io_mode =
        resolve_effective_io_mode(options.io_mode, object.get());
    if (!options.compile_only && katran_balancer_fixture_requested(options)) {
        initialize_katran_test_fixture(object.get());
    }
    const auto program_info = load_prog_info(program_fd);

    /* v2 REJIT: prepare bytecode for BPF_PROG_REJIT if requested */
    std::chrono::steady_clock::time_point rejit_start {};
    std::chrono::steady_clock::time_point rejit_end {};
    rejit_summary rejit {};
    std::vector<bpf_insn> rejit_insns;

    if (options.rejit) {
        rejit.requested = true;
        if (options.daemon_socket.has_value()) {
            /* Socket daemon mode: connect to running daemon serve */
            rejit.mode = "daemon";
            fprintf(stderr, "rejit: mode=daemon-socket socket=%s prog_id=%u\n",
                    options.daemon_socket->c_str(), program_info.id);
        } else if (options.rejit_program.has_value()) {
            /* Replacement mode: extract bytecode from a second ELF */
            rejit.mode = "replacement";
            auto replacement_image = load_program_image(
                *options.rejit_program, options.program_name);
            if (replacement_image.code.size() % sizeof(bpf_insn) != 0) {
                fail("replacement program image does not contain aligned BPF instructions");
            }
            const size_t cnt = replacement_image.code.size() / sizeof(bpf_insn);
            rejit_insns.resize(cnt);
            std::memcpy(rejit_insns.data(), replacement_image.code.data(),
                        replacement_image.code.size());
        } else {
            /* Same-bytecode mode: use original ELF insns from libbpf
             * (not xlated insns from kernel, which cannot be re-verified) */
            rejit.mode = "same-bytecode";
            if (prog == nullptr) {
                fail("same-bytecode REJIT requires a program loaded via bpf_object__load "
                     "(not manual_load_program)");
            }
            const size_t cnt = bpf_program__insn_cnt(prog);
            if (cnt == 0) {
                fail("bpf_program__insn_cnt returned 0 for REJIT");
            }
            const bpf_insn *raw = bpf_program__insns(prog);
            rejit_insns.assign(raw, raw + cnt);
        }
        if (rejit.mode != "daemon") {
            fprintf(stderr, "rejit: mode=%s insn_cnt=%zu\n",
                    rejit.mode.c_str(), rejit_insns.size());
        }
    }

    const auto packet_kind = resolve_packet_context_kind(program_info.type);

    /* Daemon-socket mode: apply optimization BEFORE any measurement.
     * This avoids the CPU-frequency regression caused by the idle gap
     * between stock and rejit measurement phases.  The separate
     * 'kernel' runtime already provides the stock baseline, so
     * in-process stock measurement is unnecessary. */
    /* Helper lambda: populate rejit_summary from daemon_socket_response */
    auto populate_rejit_from_daemon = [](rejit_summary &r, const daemon_socket_response &resp) {
        r.syscall_attempted = true;
        if (!resp.ok) {
            r.applied = false;
            r.error = "daemon socket optimize failed: " + resp.error;
        } else {
            r.applied = resp.applied;
            r.total_sites_applied = resp.total_sites_applied;
            r.passes_applied = resp.passes_applied;
            r.insn_delta = resp.insn_delta;
            r.verifier_retries = resp.verifier_retries;
            r.final_disabled_passes = resp.final_disabled_passes;
        }
        r.daemon_response = resp.raw_json;
    };

    if (options.daemon_socket.has_value() && rejit.requested && !options.compile_only) {
        rejit_start = std::chrono::steady_clock::now();
        const auto sock_resp = daemon_socket_optimize(*options.daemon_socket, program_info.id);
        rejit_end = std::chrono::steady_clock::now();
        populate_rejit_from_daemon(rejit, sock_resp);
        if (!sock_resp.ok) {
            fprintf(stderr, "daemon socket optimize failed: %s\n", sock_resp.error.c_str());
        }
    }
    /* Only do in-process stock+rejit paired measurement for non-daemon
     * modes (replacement, same-bytecode) where the REJIT is instant
     * and does not introduce a frequency-scaling gap. */
    const bool measure_same_image_pair =
        rejit.requested && !options.compile_only && !options.daemon_socket.has_value();
    if (options.compile_only && rejit.requested) {
        if (options.daemon_socket.has_value()) {
            rejit_start = std::chrono::steady_clock::now();
            const auto sock_resp = daemon_socket_optimize(*options.daemon_socket, program_info.id);
            rejit_end = std::chrono::steady_clock::now();
            populate_rejit_from_daemon(rejit, sock_resp);
        } else {
            apply_rejit(program_fd, rejit_insns.data(),
                        static_cast<uint32_t>(rejit_insns.size()),
                        rejit, rejit_start, rejit_end);
        }
    }

    if (options.compile_only) {
        const auto final_program_info = load_prog_info(program_fd);
        if (options.dump_jit) {
            const auto jited_program =
                load_jited_program(program_fd, final_program_info.jited_prog_len);
            const auto dump_path = std::filesystem::path(
                benchmark_name_for_program(options.program) + ".kernel.bin");
            write_binary_file(dump_path, jited_program.data(),
                              jited_program.size());
        }
        if (options.dump_xlated.has_value()) {
            const auto xlated_program = load_xlated_program(
                program_fd, final_program_info.xlated_prog_len);
            write_binary_file(*options.dump_xlated, xlated_program.data(),
                              xlated_program.size());
        }

        sample_result sample;
        sample.compile_ns = elapsed_ns(object_open_start, object_open_end) +
                            elapsed_ns(object_load_start, object_load_end) +
                            elapsed_ns(rejit_start, rejit_end);
        sample.jited_prog_len = final_program_info.jited_prog_len;
        sample.xlated_prog_len = final_program_info.xlated_prog_len;
        sample.code_size = {
            .bpf_bytecode_bytes = final_program_info.xlated_prog_len,
            .native_code_bytes = final_program_info.jited_prog_len,
        };
        sample.rejit = rejit;
        sample.phases_ns = {
            {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
            {"object_open_ns", elapsed_ns(object_open_start, object_open_end)},
            {"object_load_ns", elapsed_ns(object_load_start, object_load_end)},
        };
        return {std::move(sample)};
    }

    std::chrono::steady_clock::time_point exec_input_prepare_start {};
    std::chrono::steady_clock::time_point exec_input_prepare_end {};
    std::chrono::steady_clock::time_point result_read_start {};
    std::chrono::steady_clock::time_point result_read_end {};

    std::vector<uint8_t> packet;
    std::vector<uint8_t> packet_out;
    std::vector<uint8_t> context_in;
    __sk_buff context_out = {};
    uint64_t result = 0;
    int result_fd = -1;
    uint32_t key = 0;
    const bool result_from_skb_context =
        packet_kind == packet_context_kind::skb &&
        (effective_io_mode == "packet" || effective_io_mode == "staged");

    if (effective_io_mode == "map") {
        bpf_map *input_map = bpf_object__find_map_by_name(object.get(), "input_map");
        bpf_map *result_map = bpf_object__find_map_by_name(object.get(), "result_map");
        if (result_map == nullptr) {
            fail("required result_map not found");
        }

        result_fd = bpf_map__fd(result_map);
        if (result_fd < 0) {
            fail("unable to obtain map fd");
        }

        uint64_t zero = 0;
        exec_input_prepare_start = std::chrono::steady_clock::now();
        if (input_map != nullptr) {
            const uint32_t input_value_size = bpf_map__value_size(input_map);
            if (input_bytes.size() < input_value_size) {
                input_bytes.resize(input_value_size, 0);
            }

            const int input_fd = bpf_map__fd(input_map);
            if (input_fd < 0) {
                fail("unable to obtain input_map fd");
            }

            if (bpf_map_update_elem(input_fd, &key, input_bytes.data(), BPF_ANY) != 0) {
                fail("bpf_map_update_elem(input_map) failed: " + std::string(strerror(errno)));
            }
            packet.assign(64, 0);
            packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        } else {
            if (packet_kind == packet_context_kind::none) {
                fail("io-mode map without input_map requires an XDP or skb packet context");
            }
            if (options.raw_packet) {
                packet = input_bytes;
            } else {
                packet = build_packet_input(input_bytes, program_info.type);
            }
            packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        }
        if (bpf_map_update_elem(result_fd, &key, &zero, BPF_ANY) != 0) {
            fail("bpf_map_update_elem(result_map) failed: " + std::string(strerror(errno)));
        }
        exec_input_prepare_end = std::chrono::steady_clock::now();
    } else if (effective_io_mode == "staged") {
        if (packet_kind == packet_context_kind::none) {
            fail("io-mode staged requires an XDP or skb packet context");
        }
        exec_input_prepare_start = std::chrono::steady_clock::now();
        if (options.raw_packet) {
            packet = input_bytes;
        } else {
            packet = build_packet_input(input_bytes, program_info.type);
        }
        packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        exec_input_prepare_end = std::chrono::steady_clock::now();
    } else if (effective_io_mode == "context") {
        exec_input_prepare_start = std::chrono::steady_clock::now();
        context_in = input_bytes;
        exec_input_prepare_end = std::chrono::steady_clock::now();
    } else {
        exec_input_prepare_start = std::chrono::steady_clock::now();
        if (packet_kind == packet_context_kind::none) {
            fail("io-mode packet requires an XDP or skb packet context");
        }
        if (options.raw_packet) {
            packet = input_bytes;
        } else {
            packet = build_packet_input(input_bytes, program_info.type);
        }
        packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        exec_input_prepare_end = std::chrono::steady_clock::now();
    }

    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    const bool kernel_repeat_supported =
        effective_io_mode != "context" ||
        context_mode_supports_kernel_repeat(program_info.type);
    const uint32_t requested_repeat =
        kernel_repeat_supported ? options.repeat : 1u;
    /*
     * Keep repeat=0 on unsupported context paths: raw_tp/syscall reject a
     * non-zero repeat outright, while tracing/struct_ops do not batch the
     * timed execution path. sk_lookup and netfilter do support kernel-side
     * batching, so let them use repeat like packet-backed runs do.
     */
    test_opts.repeat = kernel_repeat_supported ? requested_repeat : 0u;
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
    if (result_from_skb_context) {
        test_opts.ctx_out = &context_out;
        test_opts.ctx_size_out = sizeof(context_out);
    }

    const uint64_t tsc_freq_hz = kHasTscMeasurement ? detect_tsc_freq_hz() : 0;
    kernel_test_run_context run_context = {
        .program_fd = program_fd,
        .test_opts = &test_opts,
        .effective_repeat = requested_repeat,
        .tsc_freq_hz = tsc_freq_hz,
        .packet_out = packet_out.empty() ? nullptr : &packet_out,
        .context_out = result_from_skb_context ? &context_out : nullptr,
        .context_out_size = static_cast<uint32_t>(sizeof(context_out)),
        .result_fd = result_fd,
        .result_key = key,
        .reset_result_map = effective_io_mode == "map",
    };

    const uint32_t effective_repeat = requested_repeat;
    run_context.effective_repeat = effective_repeat;
    test_opts.repeat = kernel_repeat_supported ? effective_repeat : 0u;

    const uint64_t base_compile_ns =
        elapsed_ns(object_open_start, object_open_end) +
        elapsed_ns(object_load_start, object_load_end);
    auto build_measured_sample =
        [&](std::optional<std::string> phase,
            uint64_t compile_ns,
            const kernel_test_run_measurement &measurement,
            uint64_t measured_result,
            const bpf_prog_info &measured_program_info,
            const rejit_summary &measured_rejit,
            perf_counter_capture perf_counters,
            const std::chrono::steady_clock::time_point &measured_result_read_start,
            const std::chrono::steady_clock::time_point &measured_result_read_end,
            bool include_rejit_apply_phase) {
            sample_result sample;
            sample.phase = std::move(phase);
            sample.compile_ns = compile_ns;
            sample.exec_ns = measurement.exec_ns;
            sample.timing_source = "ktime";
            sample.timing_source_wall =
                measurement.wall_exec_ns.has_value() ? "rdtsc" : "unavailable";
            sample.wall_exec_ns = measurement.wall_exec_ns;
            sample.exec_cycles = measurement.exec_cycles;
            sample.tsc_freq_hz = tsc_freq_hz > 0
                                     ? std::optional<uint64_t>(tsc_freq_hz)
                                     : std::nullopt;
            sample.result = measured_result;
            sample.retval = measurement.retval;
            sample.jited_prog_len = measured_program_info.jited_prog_len;
            sample.xlated_prog_len = measured_program_info.xlated_prog_len;
            sample.code_size = {
                .bpf_bytecode_bytes = measured_program_info.xlated_prog_len,
                .native_code_bytes = measured_program_info.jited_prog_len,
            };
            sample.rejit = measured_rejit;
            sample.phases_ns = {
                {"memory_prepare_ns",
                 elapsed_ns(memory_prepare_start, memory_prepare_end)},
                {"object_open_ns", elapsed_ns(object_open_start, object_open_end)},
                {"object_load_ns", elapsed_ns(object_load_start, object_load_end)},
            };
            if (include_rejit_apply_phase &&
                measured_rejit.syscall_attempted) {
                sample.phases_ns.push_back(
                    {"rejit_apply_ns",
                     elapsed_ns(rejit_start, rejit_end)});
            }
            sample.phases_ns.push_back(
                {prepare_phase_name(effective_io_mode),
                 elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)});
            sample.phases_ns.push_back(
                {"prog_run_wall_ns",
                 elapsed_ns(measurement.wall_start, measurement.wall_end)});
            sample.phases_ns.push_back(
                {result_phase_name(effective_io_mode),
                 elapsed_ns(measured_result_read_start,
                            measured_result_read_end)});
            sample.perf_counters = std::move(perf_counters);
            return sample;
        };
    std::optional<sample_result> stock_sample;
    if (measure_same_image_pair) {
        const rejit_summary stock_rejit = rejit;
        auto stock_pass = execute_kernel_measurement_pass(
            run_context, options, options.warmup_repeat, options.perf_counters);
        const auto stock_result_read_start = std::chrono::steady_clock::now();
        const uint64_t stock_result = read_kernel_test_run_result(
            effective_io_mode,
            result_from_skb_context,
            packet_out,
            context_out,
            result_fd,
            key,
            stock_pass.measurement.retval);
        const auto stock_result_read_end = std::chrono::steady_clock::now();
        const auto stock_program_info = load_prog_info(program_fd);
        stock_sample = build_measured_sample(
            std::string("stock"),
            base_compile_ns,
            stock_pass.measurement,
            stock_result,
            stock_program_info,
            stock_rejit,
            std::move(stock_pass.perf_counters),
            stock_result_read_start,
            stock_result_read_end,
            false);
        apply_rejit(program_fd, rejit_insns.data(),
                    static_cast<uint32_t>(rejit_insns.size()),
                    rejit, rejit_start, rejit_end);
    }

    auto run_pass = execute_kernel_measurement_pass(
        run_context,
        options,
        measure_same_image_pair ? options.warmup_repeat : 0u,
        true);
    const auto &run_measurement = run_pass.measurement;

    result_read_start = std::chrono::steady_clock::now();
    result = read_kernel_test_run_result(effective_io_mode,
                                         result_from_skb_context,
                                         packet_out,
                                         context_out,
                                         result_fd,
                                         key,
                                         run_measurement.retval);
    result_read_end = std::chrono::steady_clock::now();

    const auto final_program_info = load_prog_info(program_fd);
    if (options.dump_jit) {
        const auto jited_program =
            load_jited_program(program_fd, final_program_info.jited_prog_len);
        const auto dump_path = std::filesystem::path(
            benchmark_name_for_program(options.program) + ".kernel.bin");
        write_binary_file(dump_path, jited_program.data(), jited_program.size());
    }
    if (options.dump_xlated.has_value()) {
        const auto xlated_program = load_xlated_program(
            program_fd, final_program_info.xlated_prog_len);
        write_binary_file(*options.dump_xlated, xlated_program.data(),
                          xlated_program.size());
    }

    auto sample = build_measured_sample(
        measure_same_image_pair ? std::optional<std::string>(std::string("rejit"))
                                : std::nullopt,
        base_compile_ns + elapsed_ns(rejit_start, rejit_end),
        run_measurement,
        result,
        final_program_info,
        rejit,
        std::move(run_pass.perf_counters),
        result_read_start,
        result_read_end,
        measure_same_image_pair);
    if (stock_sample.has_value()) {
        return {std::move(*stock_sample), std::move(sample)};
    }
    return {std::move(sample)};
}
