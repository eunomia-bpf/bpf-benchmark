#include "micro_exec.hpp"

#include <arpa/inet.h>

#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <cerrno>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <time.h>
#include <memory>
#include <netinet/in.h>
#include <string>
#include <string_view>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <unordered_set>
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

struct live_fixture_map {
    std::string name;
    uint32_t id = 0;
    uint32_t type = 0;
    uint32_t key_size = 0;
    uint32_t value_size = 0;
    int fd = -1;
};

std::string require_scalar_string_field(
    const YAML::Node &node,
    std::string_view field_name)
{
    if (!node || !node.IsScalar()) {
        fail("fixture field '" + std::string(field_name) + "' must be a scalar string");
    }
    try {
        return node.as<std::string>();
    } catch (const YAML::Exception &) {
        fail("fixture field '" + std::string(field_name) + "' must be a scalar string");
    }
}

std::optional<std::string> optional_scalar_string_field(
    const YAML::Node &node,
    std::string_view field_name)
{
    if (!node) {
        return std::nullopt;
    }
    if (!node.IsScalar()) {
        fail("fixture field '" + std::string(field_name) + "' must be a scalar string");
    }
    try {
        return node.as<std::string>();
    } catch (const YAML::Exception &) {
        fail("fixture field '" + std::string(field_name) + "' must be a scalar string");
    }
}

std::optional<uint32_t> optional_u32_field(
    const YAML::Node &node,
    std::string_view field_name)
{
    if (!node) {
        return std::nullopt;
    }
    if (!node.IsScalar()) {
        fail("fixture field '" + std::string(field_name) + "' must be an integer");
    }
    try {
        return node.as<uint32_t>();
    } catch (const YAML::Exception &) {
        fail("fixture field '" + std::string(field_name) + "' must be an integer");
    }
}

int hex_nibble_value(char ch)
{
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    if (ch >= 'a' && ch <= 'f') {
        return 10 + (ch - 'a');
    }
    if (ch >= 'A' && ch <= 'F') {
        return 10 + (ch - 'A');
    }
    return -1;
}

std::vector<uint8_t> decode_hex_bytes(
    std::string_view text,
    std::string_view field_name)
{
    size_t start = 0;
    size_t end = text.size();
    while (start < end &&
           std::isspace(static_cast<unsigned char>(text[start])) != 0) {
        ++start;
    }
    while (end > start &&
           std::isspace(static_cast<unsigned char>(text[end - 1])) != 0) {
        --end;
    }

    std::string_view trimmed = text.substr(start, end - start);
    if (trimmed.starts_with("0x") || trimmed.starts_with("0X")) {
        trimmed.remove_prefix(2);
    }
    if (trimmed.size() % 2 != 0) {
        fail("fixture field '" + std::string(field_name) + "' must have even-length hex");
    }

    std::vector<uint8_t> bytes;
    bytes.reserve(trimmed.size() / 2);
    for (size_t index = 0; index < trimmed.size(); index += 2) {
        const int high = hex_nibble_value(trimmed[index]);
        const int low = hex_nibble_value(trimmed[index + 1]);
        if (high < 0 || low < 0) {
            fail("fixture field '" + std::string(field_name) + "' contains invalid hex");
        }
        bytes.push_back(static_cast<uint8_t>((high << 4) | low));
    }
    return bytes;
}

live_fixture_map describe_live_fixture_map(bpf_map *map)
{
    const int fd = bpf_map__fd(map);
    if (fd < 0) {
        fail("unable to obtain loaded map fd for fixture replay");
    }

    bpf_map_info info = {};
    __u32 info_len = sizeof(info);
    if (bpf_map_get_info_by_fd(fd, &info, &info_len) != 0) {
        fail("bpf_map_get_info_by_fd failed during fixture replay: " +
             std::string(strerror(errno)));
    }

    const char *map_name = bpf_map__name(map);
    return {
        .name = map_name != nullptr ? std::string(map_name) : std::string(),
        .id = info.id,
        .type = info.type,
        .key_size = info.key_size,
        .value_size = info.value_size,
        .fd = fd,
    };
}

bool fixture_value_uses_reference_fd(uint32_t map_type)
{
    return map_type == BPF_MAP_TYPE_PROG_ARRAY ||
           map_type == BPF_MAP_TYPE_ARRAY_OF_MAPS ||
           map_type == BPF_MAP_TYPE_HASH_OF_MAPS;
}

void update_fixture_map_elem(
    const live_fixture_map &map,
    const std::vector<uint8_t> &key,
    const std::vector<uint8_t> &value)
{
    if (fixture_value_uses_reference_fd(map.type)) {
        if (value.size() != sizeof(uint32_t)) {
            fail("fixture value size mismatch for special map '" + map.name + "'");
        }

        uint32_t referenced_id = 0;
        std::memcpy(&referenced_id, value.data(), sizeof(referenced_id));
        int referenced_fd = -1;
        if (map.type == BPF_MAP_TYPE_PROG_ARRAY) {
            referenced_fd = bpf_prog_get_fd_by_id(referenced_id);
        } else {
            referenced_fd = bpf_map_get_fd_by_id(referenced_id);
        }
        if (referenced_fd < 0) {
            fail("unable to resolve referenced object id " +
                 std::to_string(referenced_id) +
                 " for fixture map '" + map.name + "': " +
                 std::string(strerror(errno)));
        }

        scoped_fd referenced_fd_guard(referenced_fd);
        if (bpf_map_update_elem(map.fd, key.data(), &referenced_fd, BPF_ANY) != 0) {
            fail("bpf_map_update_elem(" + map.name + ") failed: " +
                 std::string(strerror(errno)));
        }
        return;
    }

    if (bpf_map_update_elem(map.fd, key.data(), value.data(), BPF_ANY) != 0) {
        fail("bpf_map_update_elem(" + map.name + ") failed: " +
             std::string(strerror(errno)));
    }
}

void load_map_fixtures(
    const std::filesystem::path &fixture_json_path,
    bpf_object *object)
{
    YAML::Node root;
    try {
        root = YAML::LoadFile(fixture_json_path.string());
    } catch (const YAML::Exception &error) {
        fail("unable to parse fixture JSON '" + fixture_json_path.string() +
             "': " + error.what());
    }

    const YAML::Node maps = root["maps"];
    if (!maps || !maps.IsSequence()) {
        fail("fixture JSON '" + fixture_json_path.string() +
             "' must contain a 'maps' sequence");
    }

    std::unordered_map<std::string, live_fixture_map> maps_by_name;
    std::unordered_map<uint32_t, live_fixture_map> maps_by_id;
    bpf_map *map = nullptr;
    while ((map = bpf_object__next_map(object, map)) != nullptr) {
        const auto live_map = describe_live_fixture_map(map);
        if (!live_map.name.empty()) {
            maps_by_name.insert_or_assign(live_map.name, live_map);
        }
        maps_by_id.insert_or_assign(live_map.id, live_map);
    }

    size_t loaded_entries = 0;
    std::unordered_set<uint32_t> updated_map_ids;
    for (const auto &map_node : maps) {
        if (!map_node.IsMap()) {
            fail("fixture JSON '" + fixture_json_path.string() +
                 "' contains a non-object map entry");
        }

        std::optional<std::string> map_name =
            optional_scalar_string_field(map_node["map_name"], "map_name");
        if (!map_name.has_value()) {
            map_name = optional_scalar_string_field(map_node["name"], "name");
        }
        const auto map_id = optional_u32_field(map_node["map_id"], "map_id");
        if (!map_name.has_value() && !map_id.has_value()) {
            fail("fixture JSON '" + fixture_json_path.string() +
                 "' requires each map entry to specify map_name or map_id");
        }

        const live_fixture_map *live_map = nullptr;
        if (map_name.has_value()) {
            const auto found = maps_by_name.find(*map_name);
            if (found == maps_by_name.end()) {
                fail("fixture map '" + *map_name + "' not found in loaded object");
            }
            live_map = &found->second;
            if (map_id.has_value() && live_map->id != *map_id) {
                fail("fixture map '" + *map_name + "' id mismatch: fixture=" +
                     std::to_string(*map_id) + " live=" +
                     std::to_string(live_map->id));
            }
        } else {
            const auto found = maps_by_id.find(*map_id);
            if (found == maps_by_id.end()) {
                fail("fixture map id " + std::to_string(*map_id) +
                     " not found in loaded object");
            }
            live_map = &found->second;
        }

        if (const auto declared_key_size =
                optional_u32_field(map_node["key_size"], "key_size");
            declared_key_size.has_value() &&
            *declared_key_size != live_map->key_size) {
            fail("fixture key_size mismatch for map '" + live_map->name + "'");
        }
        if (const auto declared_value_size =
                optional_u32_field(map_node["value_size"], "value_size");
            declared_value_size.has_value() &&
            *declared_value_size != live_map->value_size) {
            fail("fixture value_size mismatch for map '" + live_map->name + "'");
        }

        const YAML::Node entries = map_node["entries"];
        if (!entries || !entries.IsSequence()) {
            fail("fixture map '" + live_map->name + "' must contain an 'entries' sequence");
        }

        for (const auto &entry_node : entries) {
            if (!entry_node.IsMap()) {
                fail("fixture map '" + live_map->name +
                     "' contains a non-object entry");
            }

            const auto key = decode_hex_bytes(
                require_scalar_string_field(entry_node["key_hex"], "key_hex"),
                "key_hex");
            const auto value = decode_hex_bytes(
                require_scalar_string_field(entry_node["value_hex"], "value_hex"),
                "value_hex");
            if (key.size() != live_map->key_size) {
                fail("fixture key size mismatch for map '" + live_map->name + "'");
            }
            if (value.size() != live_map->value_size) {
                fail("fixture value size mismatch for map '" + live_map->name + "'");
            }

            update_fixture_map_elem(*live_map, key, value);
            ++loaded_entries;
            updated_map_ids.insert(live_map->id);
        }
    }

    std::fprintf(
        stderr,
        "loaded %zu entries into %zu maps from fixture %s\n",
        loaded_entries,
        updated_map_ids.size(),
        fixture_json_path.c_str());
}

void maybe_load_map_fixtures(const cli_options &options, bpf_object *object)
{
    if (!options.fixture_path.has_value() || options.compile_only) {
        return;
    }
    load_map_fixtures(*options.fixture_path, object);
}

struct prog_load_attr {
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

struct process_runtime_state {
    process_runtime_state()
    {
        libbpf_set_print(libbpf_log);

        struct btf *loaded_vmlinux_btf = btf__load_vmlinux_btf();
        if (loaded_vmlinux_btf == nullptr) {
            std::fprintf(stderr, "vmlinux btf preload returned null\n");
            return;
        }

        const int load_error = libbpf_get_error(loaded_vmlinux_btf);
        if (load_error != 0) {
            std::fprintf(
                stderr,
                "vmlinux btf preload failed: %s\n",
                libbpf_error_string(load_error).c_str());
            return;
        }

        // Keep the parsed vmlinux BTF alive for the life of the process so
        // subsequent object loads can reuse libbpf's in-process state.
        vmlinux_btf = loaded_vmlinux_btf;
    }

    ~process_runtime_state()
    {
        if (vmlinux_btf != nullptr) {
            btf__free(vmlinux_btf);
        }
    }

    struct btf *vmlinux_btf = nullptr;
};

process_runtime_state &get_process_runtime_state()
{
    static process_runtime_state state;
    return state;
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

    /* Find the opening '[' of the passes array */
    auto array_open = json.find('[', passes_pos);
    if (array_open == std::string::npos) return result;

    /* Find the matching ']' for the passes array, respecting nesting */
    int arr_depth = 1;
    size_t array_close = array_open + 1;
    while (array_close < json.size() && arr_depth > 0) {
        if (json[array_close] == '[') ++arr_depth;
        else if (json[array_close] == ']') --arr_depth;
        ++array_close;
    }
    /* array_close now points one past the matching ']' */

    /* Walk through the passes array looking for changed:true entries */
    size_t pos = array_open;
    while (true) {
        auto obj_start = json.find('{', pos + 1);
        if (obj_start == std::string::npos || obj_start >= array_close) break;
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

std::string json_escape_for_request(std::string_view input)
{
    std::string output;
    output.reserve(input.size());
    for (const char ch : input) {
        switch (ch) {
        case '\\':
            output += "\\\\";
            break;
        case '"':
            output += "\\\"";
            break;
        case '\n':
            output += "\\n";
            break;
        case '\r':
            output += "\\r";
            break;
        case '\t':
            output += "\\t";
            break;
        default:
            output += ch;
            break;
        }
    }
    return output;
}

std::string build_daemon_optimize_request(
    uint32_t prog_id,
    const std::vector<std::string> &passes)
{
    std::string request = "{\"cmd\":\"optimize\",\"prog_id\":" + std::to_string(prog_id);
    if (!passes.empty()) {
        request += ",\"passes\":[";
        for (size_t index = 0; index < passes.size(); ++index) {
            if (index != 0) {
                request += ",";
            }
            request += "\"";
            request += json_escape_for_request(passes[index]);
            request += "\"";
        }
        request += "]";
    }
    request += "}\n";
    return request;
}

daemon_socket_response daemon_socket_optimize(
    const std::string &socket_path,
    uint32_t prog_id,
    const std::vector<std::string> &passes)
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
    const std::string request = build_daemon_optimize_request(prog_id, passes);
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
            fail("unable to write memfd: " + std::string(strerror(errno)));
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

    prog_load_attr attr = {};
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

/* ================================================================
 * Attach-mode helpers: workload generation and bpf_stats
 * ================================================================ */

bool is_duration_based_workload(std::string_view workload_type)
{
    return workload_type == "mixed" ||
           workload_type == "stress-ng" ||
           workload_type == "fio" ||
           workload_type == "wrk";
}

uint32_t workload_duration_seconds(uint32_t requested_seconds)
{
    return std::max(1u, requested_seconds);
}

std::string shell_escape(std::string_view value)
{
    std::string escaped;
    escaped.reserve(value.size() + 2);
    escaped += '\'';
    for (const char ch : value) {
        if (ch == '\'') {
            escaped += "'\\''";
        } else {
            escaped += ch;
        }
    }
    escaped += '\'';
    return escaped;
}

bool run_shell_workload_command(const std::string &command)
{
    const int status = std::system(command.c_str());
    if (status == -1) {
        return false;
    }
    if (!WIFEXITED(status)) {
        return false;
    }
    return WEXITSTATUS(status) == 0;
}

void run_mixed_syscall_fallback(uint32_t duration_seconds)
{
    const uint32_t seconds = workload_duration_seconds(duration_seconds);
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(seconds);
    const int read_fd = open("/dev/null", O_RDONLY | O_CLOEXEC);
    if (read_fd < 0) {
        fail("unable to open /dev/null for read workload fallback");
    }
    scoped_fd read_fd_guard(read_fd);

    const int write_fd = open("/dev/null", O_WRONLY | O_CLOEXEC);
    if (write_fd < 0) {
        fail("unable to open /dev/null for write workload fallback");
    }
    scoped_fd write_fd_guard(write_fd);

    char read_byte = '\0';
    const char write_byte = 'x';
    const struct timespec ts = {0, 1}; /* 1 nanosecond */
    while (std::chrono::steady_clock::now() < deadline) {
        (void)syscall(__NR_getpid);
        const ssize_t read_ret = read(read_fd_guard.get(), &read_byte, 1);
        const ssize_t write_ret = write(write_fd_guard.get(), &write_byte, 1);
        (void)read_ret;
        (void)write_ret;
        (void)nanosleep(&ts, nullptr);
        const int open_fd = openat(AT_FDCWD, "/dev/null", O_RDONLY | O_CLOEXEC);
        if (open_fd >= 0) {
            close(open_fd);
        }
    }
}

class temporary_directory {
  public:
    explicit temporary_directory(std::string_view prefix)
    {
        std::string template_path = std::filesystem::temp_directory_path().string();
        if (!template_path.empty() && template_path.back() != '/') {
            template_path += '/';
        }
        template_path += std::string(prefix);
        template_path += "XXXXXX";
        template_buffer_.assign(template_path.begin(), template_path.end());
        template_buffer_.push_back('\0');
        char *created = ::mkdtemp(template_buffer_.data());
        if (created == nullptr) {
            fail("mkdtemp failed for workload temp directory: " + std::string(strerror(errno)));
        }
        path_ = created;
    }

    temporary_directory(const temporary_directory &) = delete;
    temporary_directory &operator=(const temporary_directory &) = delete;

    ~temporary_directory()
    {
        std::error_code error;
        std::filesystem::remove_all(path_, error);
    }

    const std::filesystem::path &path() const
    {
        return path_;
    }

  private:
    std::vector<char> template_buffer_;
    std::filesystem::path path_;
};

class local_http_server {
  public:
    local_http_server()
    {
        scoped_fd listener(socket(AF_INET, SOCK_STREAM, 0));
        if (listener.get() < 0) {
            fail("socket failed for wrk workload: " + std::string(strerror(errno)));
        }

        const int reuse = 1;
        (void)setsockopt(listener.get(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

        sockaddr_in addr = {};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_port = 0;
        if (bind(listener.get(), reinterpret_cast<const sockaddr *>(&addr), sizeof(addr)) != 0) {
            fail("bind failed for wrk workload: " + std::string(strerror(errno)));
        }
        if (listen(listener.get(), 64) != 0) {
            fail("listen failed for wrk workload: " + std::string(strerror(errno)));
        }

        socklen_t addr_len = sizeof(addr);
        if (getsockname(listener.get(), reinterpret_cast<sockaddr *>(&addr), &addr_len) != 0) {
            fail("getsockname failed for wrk workload: " + std::string(strerror(errno)));
        }

        port_ = ntohs(addr.sin_port);
        listener_fd_ = std::move(listener);
        server_thread_ = std::thread([this]() { serve(); });
    }

    local_http_server(const local_http_server &) = delete;
    local_http_server &operator=(const local_http_server &) = delete;

    ~local_http_server()
    {
        stop();
    }

    std::string url() const
    {
        return "http://127.0.0.1:" + std::to_string(port_) + "/";
    }

  private:
    void serve()
    {
        static constexpr char kResponse[] =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 23\r\n"
            "Connection: close\r\n"
            "\r\n"
            "kernel-attach-workload\n";

        while (!stop_.load(std::memory_order_relaxed)) {
            const int client_fd = accept(listener_fd_.get(), nullptr, nullptr);
            if (client_fd < 0) {
                if (errno == EINTR) {
                    continue;
                }
                if (stop_.load(std::memory_order_relaxed)) {
                    break;
                }
                continue;
            }

            scoped_fd client(client_fd);
            if (stop_.load(std::memory_order_relaxed)) {
                break;
            }
            std::array<char, 1024> request = {};
            (void)recv(client.get(), request.data(), request.size(), 0);
            (void)send(client.get(), kResponse, sizeof(kResponse) - 1, MSG_NOSIGNAL);
        }
    }

    void stop()
    {
        if (!server_thread_.joinable()) {
            return;
        }

        stop_.store(true, std::memory_order_relaxed);
        wake_accept();
        server_thread_.join();
        listener_fd_.reset();
    }

    void wake_accept() const
    {
        const int wake_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (wake_fd < 0) {
            return;
        }

        sockaddr_in addr = {};
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_port = htons(port_);
        (void)connect(wake_fd, reinterpret_cast<const sockaddr *>(&addr), sizeof(addr));
        close(wake_fd);
    }

    scoped_fd listener_fd_;
    uint16_t port_ = 0;
    std::atomic<bool> stop_ = false;
    std::thread server_thread_;
};

bool run_stress_ng_workload(uint32_t duration_seconds)
{
    const uint32_t seconds = workload_duration_seconds(duration_seconds);
    const std::string command =
        "stress-ng --cpu 1 --io 1 --vm 1 --fork 1 --timeout " +
        std::to_string(seconds) + "s --quiet >/dev/null 2>&1";
    return run_shell_workload_command(command);
}

bool run_fio_workload(uint32_t duration_seconds)
{
    const uint32_t seconds = workload_duration_seconds(duration_seconds);
    temporary_directory tempdir("kernel-attach-fio-");
    const std::filesystem::path data_path = tempdir.path() / "fio.bin";
    const std::string command =
        "fio --name=kernel-attach"
        " --filename=" + shell_escape(data_path.string()) +
        " --rw=randread --bs=4k --size=64M"
        " --runtime=" + std::to_string(seconds) +
        " --time_based=1 --ioengine=sync --direct=0"
        " --output-format=json >/dev/null 2>&1";
    return run_shell_workload_command(command);
}

bool run_wrk_workload(uint32_t duration_seconds)
{
    const uint32_t seconds = workload_duration_seconds(duration_seconds);
    local_http_server server;
    const std::string command =
        "wrk -t2 -c10 -d" + std::to_string(seconds) + "s " +
        shell_escape(server.url()) + " >/dev/null 2>&1";
    return run_shell_workload_command(command);
}

void run_workload(const std::string &workload_type, uint32_t iterations_or_duration)
{
    if (workload_type == "mixed") {
        if (!run_stress_ng_workload(iterations_or_duration)) {
            run_mixed_syscall_fallback(iterations_or_duration);
        }
    } else if (workload_type == "stress-ng") {
        if (!run_stress_ng_workload(iterations_or_duration)) {
            run_mixed_syscall_fallback(iterations_or_duration);
        }
    } else if (workload_type == "fio") {
        if (!run_fio_workload(iterations_or_duration)) {
            run_mixed_syscall_fallback(iterations_or_duration);
        }
    } else if (workload_type == "wrk") {
        if (!run_wrk_workload(iterations_or_duration)) {
            run_mixed_syscall_fallback(iterations_or_duration);
        }
    } else if (workload_type == "getpid") {
        for (uint32_t i = 0; i < iterations_or_duration; ++i) {
            (void)syscall(__NR_getpid);
        }
    } else if (workload_type == "nanosleep") {
        struct timespec ts = {0, 1}; /* 1 nanosecond */
        for (uint32_t i = 0; i < iterations_or_duration; ++i) {
            (void)nanosleep(&ts, nullptr);
        }
    } else if (workload_type == "write_devnull") {
        const int fd = open("/dev/null", O_WRONLY);
        if (fd < 0) {
            fail("unable to open /dev/null for workload");
        }
        const char data = 'x';
        for (uint32_t i = 0; i < iterations_or_duration; ++i) {
            ssize_t ret = write(fd, &data, 1);
            (void)ret;
        }
        close(fd);
    } else {
        fail("unsupported workload type: " + workload_type);
    }
}

struct bpf_stats_snapshot {
    uint64_t run_cnt = 0;
    uint64_t run_time_ns = 0;
};

bpf_stats_snapshot read_bpf_stats(int program_fd)
{
    bpf_prog_info info = {};
    union bpf_attr attr = {};
    attr.info.bpf_fd = program_fd;
    attr.info.info_len = sizeof(info);
    attr.info.info = ptr_to_u64(&info);
    if (syscall(__NR_bpf, BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) != 0) {
        fail("BPF_OBJ_GET_INFO_BY_FD (bpf_stats) failed: " + std::string(strerror(errno)));
    }
    return {info.run_cnt, info.run_time_ns};
}

struct bpf_link_deleter {
    void operator()(bpf_link *link) const
    {
        if (link != nullptr) {
            bpf_link__destroy(link);
        }
    }
};

using bpf_link_ptr = std::unique_ptr<bpf_link, bpf_link_deleter>;

} // namespace

struct prepared_program_state {
    bpf_program *prog = nullptr;
    int program_fd = -1;
    bpf_prog_info program_info = {};
    rejit_summary prepared_rejit {};
    std::vector<bpf_insn> rejit_insns;
    uint64_t rejit_apply_ns = 0;
    bool rejit_applied = false;
    bool katran_fixture_initialized = false;
};

struct prepared_kernel_state {
    cli_options options;
    std::vector<uint8_t> input_bytes;
    bpf_object_ptr object;
    scoped_fd manual_program_fd;
    bpf_program *prog = nullptr;
    int program_fd = -1;
    std::string effective_io_mode;
    bpf_prog_info program_info = {};
    rejit_summary prepared_rejit {};
    std::vector<bpf_insn> rejit_insns;
    uint64_t memory_prepare_ns = 0;
    uint64_t object_open_ns = 0;
    uint64_t object_load_ns = 0;
    uint64_t rejit_apply_ns = 0;
    bool rejit_applied = false;
    bool katran_fixture_initialized = false;
    std::unordered_map<std::string, prepared_program_state> programs;
    std::vector<std::string> program_order;
};

namespace {

void populate_rejit_from_daemon_summary(
    rejit_summary &summary,
    const daemon_socket_response &response)
{
    summary.syscall_attempted = true;
    if (!response.ok) {
        summary.applied = false;
        summary.error = "daemon socket optimize failed: " + response.error;
    } else {
        summary.applied = response.applied;
        summary.total_sites_applied = response.total_sites_applied;
        summary.passes_applied = response.passes_applied;
        summary.insn_delta = response.insn_delta;
        summary.verifier_retries = response.verifier_retries;
        summary.final_disabled_passes = response.final_disabled_passes;
    }
    summary.daemon_response = response.raw_json;
}

prepared_program_state &require_prepared_program(
    prepared_kernel_state &prepared,
    const std::optional<std::string> &program_name)
{
    if (program_name.has_value()) {
        const auto found = prepared.programs.find(*program_name);
        if (found == prepared.programs.end()) {
            fail("prepared kernel state is missing program: " + *program_name);
        }
        return found->second;
    }
    if (prepared.program_order.size() != 1) {
        fail("multi-program prepared kernel state requires --program-name");
    }
    return prepared.programs.at(prepared.program_order.front());
}

prepared_program_state *summary_program_for_prepared(prepared_kernel_state &prepared)
{
    if (prepared.options.program_name.has_value()) {
        return &require_prepared_program(prepared, prepared.options.program_name);
    }
    if (prepared.program_order.size() == 1) {
        return &prepared.programs.at(prepared.program_order.front());
    }
    return nullptr;
}

void maybe_write_prepared_program_dumps(
    const prepared_kernel_state &prepared,
    const prepared_program_state &program)
{
    if (prepared.options.dump_jit) {
        const auto jited_program =
            load_jited_program(program.program_fd, program.program_info.jited_prog_len);
        const auto dump_path = std::filesystem::path(
            benchmark_name_for_program(prepared.options.program) + ".kernel.bin");
        write_binary_file(dump_path, jited_program.data(), jited_program.size());
    }
    if (prepared.options.dump_xlated.has_value()) {
        const auto xlated_program =
            load_xlated_program(program.program_fd, program.program_info.xlated_prog_len);
        write_binary_file(
            *prepared.options.dump_xlated,
            xlated_program.data(),
            xlated_program.size());
    }
}

void maybe_apply_prepared_daemon_rejit(
    prepared_program_state &program,
    const cli_options &options)
{
    if (!options.rejit ||
        !options.daemon_socket.has_value() ||
        !program.prepared_rejit.requested ||
        program.rejit_applied) {
        return;
    }
    const auto rejit_start = std::chrono::steady_clock::now();
    const auto socket_response =
        daemon_socket_optimize(*options.daemon_socket, program.program_info.id, options.passes);
    const auto rejit_end = std::chrono::steady_clock::now();
    program.rejit_apply_ns = elapsed_ns(rejit_start, rejit_end);
    populate_rejit_from_daemon_summary(program.prepared_rejit, socket_response);
    program.rejit_applied = true;
    program.program_info = load_prog_info(program.program_fd);
    if (!socket_response.ok) {
        fprintf(stderr, "daemon socket optimize failed: %s\n", socket_response.error.c_str());
    }
}

void maybe_apply_prepared_bytecode_rejit(
    prepared_program_state &program,
    const cli_options &options)
{
    if (!options.rejit ||
        options.daemon_socket.has_value() ||
        !program.prepared_rejit.requested ||
        program.rejit_applied) {
        return;
    }
    if (program.rejit_insns.empty()) {
        fail("prepared kernel state is missing REJIT instructions");
    }
    auto rejit_start = std::chrono::steady_clock::now();
    auto rejit_end = rejit_start;
    apply_rejit(
        program.program_fd,
        program.rejit_insns.data(),
        static_cast<uint32_t>(program.rejit_insns.size()),
        program.prepared_rejit,
        rejit_start,
        rejit_end);
    program.rejit_apply_ns = elapsed_ns(rejit_start, rejit_end);
    program.rejit_applied = true;
    program.program_info = load_prog_info(program.program_fd);
}

sample_result build_compile_only_sample(prepared_kernel_state &prepared)
{
    sample_result sample;
    sample.compile_ns = prepared.memory_prepare_ns +
                        prepared.object_open_ns +
                        prepared.object_load_ns +
                        prepared.rejit_apply_ns;
    if (auto *program = summary_program_for_prepared(prepared); program != nullptr) {
        sample.compile_ns = prepared.memory_prepare_ns +
                            prepared.object_open_ns +
                            prepared.object_load_ns +
                            program->rejit_apply_ns;
        program->program_info = load_prog_info(program->program_fd);
        maybe_write_prepared_program_dumps(prepared, *program);
        sample.jited_prog_len = program->program_info.jited_prog_len;
        sample.xlated_prog_len = program->program_info.xlated_prog_len;
        sample.code_size = {
            .bpf_bytecode_bytes = program->program_info.xlated_prog_len,
            .native_code_bytes = program->program_info.jited_prog_len,
        };
        sample.rejit = program->prepared_rejit;
    } else {
        sample.rejit.requested = prepared.options.rejit;
        if (prepared.options.daemon_socket.has_value()) {
            sample.rejit.mode = "daemon";
        } else if (prepared.options.rejit_program.has_value()) {
            sample.rejit.mode = "replacement";
        } else if (prepared.options.rejit) {
            sample.rejit.mode = "same-bytecode";
        }
    }
    sample.phases_ns = {
        {"memory_prepare_ns", prepared.memory_prepare_ns},
        {"object_open_ns", prepared.object_open_ns},
        {"object_load_ns", prepared.object_load_ns},
    };
    if (auto *program = summary_program_for_prepared(prepared);
        program != nullptr &&
        (program->prepared_rejit.syscall_attempted || program->rejit_applied)) {
        sample.phases_ns.push_back({"rejit_apply_ns", program->rejit_apply_ns});
    }
    return sample;
}

sample_result build_prepared_program_compile_sample(
    prepared_kernel_state &prepared,
    const cli_options &options)
{
    auto &program = require_prepared_program(prepared, options.program_name);
    if (options.daemon_socket.has_value()) {
        maybe_apply_prepared_daemon_rejit(program, options);
    } else {
        maybe_apply_prepared_bytecode_rejit(program, options);
    }

    program.program_info = load_prog_info(program.program_fd);
    maybe_write_prepared_program_dumps(prepared, program);

    sample_result sample;
    sample.compile_ns = prepared.memory_prepare_ns +
                        prepared.object_open_ns +
                        prepared.object_load_ns +
                        program.rejit_apply_ns;
    sample.jited_prog_len = program.program_info.jited_prog_len;
    sample.xlated_prog_len = program.program_info.xlated_prog_len;
    sample.code_size = {
        .bpf_bytecode_bytes = program.program_info.xlated_prog_len,
        .native_code_bytes = program.program_info.jited_prog_len,
    };
    sample.rejit = program.prepared_rejit;
    sample.phases_ns = {
        {"memory_prepare_ns", prepared.memory_prepare_ns},
        {"object_open_ns", prepared.object_open_ns},
        {"object_load_ns", prepared.object_load_ns},
    };
    if (program.prepared_rejit.syscall_attempted || program.rejit_applied) {
        sample.phases_ns.push_back({"rejit_apply_ns", program.rejit_apply_ns});
    }
    return sample;
}

std::vector<sample_result> execute_prepared_kernel_attach(
    prepared_kernel_state &prepared,
    const cli_options &options)
{
    auto &program = require_prepared_program(prepared, options.program_name);
    maybe_load_map_fixtures(options, prepared.object.get());
    if (options.daemon_socket.has_value()) {
        maybe_apply_prepared_daemon_rejit(program, options);
    }

    const uint64_t base_compile_ns =
        prepared.object_open_ns +
        prepared.object_load_ns;

    const auto attach_start = std::chrono::steady_clock::now();
    bpf_link *raw_link = bpf_program__attach(program.prog);
    const int attach_error = libbpf_get_error(raw_link);
    if (attach_error != 0) {
        fail("bpf_program__attach failed: " + libbpf_error_string(attach_error));
    }
    bpf_link_ptr link(raw_link);
    const auto attach_end = std::chrono::steady_clock::now();

    const int stats_fd = bpf_enable_stats(BPF_STATS_RUN_TIME);
    if (stats_fd < 0) {
        fail("bpf_enable_stats(BPF_STATS_RUN_TIME) failed: " + std::string(strerror(errno)));
    }
    scoped_fd stats_fd_guard(stats_fd);

    const uint32_t warmup_workload_amount = is_duration_based_workload(options.workload_type)
        ? options.workload_iterations
        : options.warmup_repeat * options.workload_iterations;
    const uint32_t measured_workload_amount = is_duration_based_workload(options.workload_type)
        ? options.workload_iterations
        : options.repeat * options.workload_iterations;

    if (options.warmup_repeat > 0) {
        run_workload(options.workload_type, warmup_workload_amount);
    }

    const auto before_stats = read_bpf_stats(program.program_fd);

    const auto exec_wall_start = std::chrono::steady_clock::now();
    const uint64_t tsc_before = rdtsc_start();
    run_workload(options.workload_type, measured_workload_amount);
    const uint64_t tsc_after = rdtsc_end();
    const auto exec_wall_end = std::chrono::steady_clock::now();

    const auto after_stats = read_bpf_stats(program.program_fd);
    stats_fd_guard.reset();
    link.reset();

    const uint64_t run_cnt_delta = after_stats.run_cnt - before_stats.run_cnt;
    const uint64_t run_time_ns_delta = after_stats.run_time_ns - before_stats.run_time_ns;
    const uint64_t exec_ns = run_cnt_delta > 0
        ? run_time_ns_delta / run_cnt_delta
        : 0;

    const uint64_t tsc_freq_hz = kHasTscMeasurement ? detect_tsc_freq_hz() : 0;
    std::optional<uint64_t> wall_exec_ns;
    std::optional<uint64_t> exec_cycles;
    if (kHasTscMeasurement && tsc_freq_hz > 0 && tsc_after > tsc_before && run_cnt_delta > 0) {
        const uint64_t total_cycles = tsc_after - tsc_before;
        exec_cycles = total_cycles / run_cnt_delta;
        wall_exec_ns = static_cast<uint64_t>(std::llround(
            (static_cast<long double>(total_cycles) * 1000000000.0L) /
            (static_cast<long double>(tsc_freq_hz) *
             static_cast<long double>(run_cnt_delta))));
    }

    program.program_info = load_prog_info(program.program_fd);
    sample_result sample;
    if (options.rejit && options.daemon_socket.has_value()) {
        sample.phase = "recompile";
    }
    sample.compile_ns = base_compile_ns + program.rejit_apply_ns;
    sample.exec_ns = exec_ns;
    sample.timing_source = "bpf_stats";
    sample.timing_source_wall =
        wall_exec_ns.has_value() ? "rdtsc" : "unavailable";
    sample.wall_exec_ns = wall_exec_ns;
    sample.exec_cycles = exec_cycles;
    sample.tsc_freq_hz = tsc_freq_hz > 0
        ? std::optional<uint64_t>(tsc_freq_hz)
        : std::nullopt;
    sample.result = run_cnt_delta;
    sample.retval = 0;
    sample.jited_prog_len = program.program_info.jited_prog_len;
    sample.xlated_prog_len = program.program_info.xlated_prog_len;
    sample.code_size = {
        .bpf_bytecode_bytes = program.program_info.xlated_prog_len,
        .native_code_bytes = program.program_info.jited_prog_len,
    };
    sample.rejit = program.prepared_rejit;
    sample.phases_ns = {
        {"object_open_ns", prepared.object_open_ns},
        {"object_load_ns", prepared.object_load_ns},
        {"attach_ns", elapsed_ns(attach_start, attach_end)},
        {"workload_wall_ns", elapsed_ns(exec_wall_start, exec_wall_end)},
    };
    if (program.prepared_rejit.syscall_attempted) {
        sample.phases_ns.push_back({"rejit_apply_ns", program.rejit_apply_ns});
    }
    return {std::move(sample)};
}

std::vector<sample_result> execute_prepared_kernel_run(
    prepared_kernel_state &prepared,
    const cli_options &options)
{
    auto &program = require_prepared_program(prepared, options.program_name);
    if (katran_balancer_fixture_requested(options) &&
        !program.katran_fixture_initialized) {
        initialize_katran_test_fixture(prepared.object.get());
        program.katran_fixture_initialized = true;
    }
    maybe_load_map_fixtures(options, prepared.object.get());

    rejit_summary rejit = program.prepared_rejit;
    uint64_t rejit_apply_ns = program.rejit_apply_ns;
    const bool prepared_rejit_already_applied = program.rejit_applied;
    const auto packet_kind = resolve_packet_context_kind(program.program_info.type);

    if (options.daemon_socket.has_value() &&
        rejit.requested &&
        !prepared_rejit_already_applied) {
        maybe_apply_prepared_daemon_rejit(program, options);
        rejit = program.prepared_rejit;
        rejit_apply_ns = program.rejit_apply_ns;
    }

    std::chrono::steady_clock::time_point exec_input_prepare_start {};
    std::chrono::steady_clock::time_point exec_input_prepare_end {};
    std::chrono::steady_clock::time_point result_read_start {};
    std::chrono::steady_clock::time_point result_read_end {};

    std::vector<uint8_t> input_bytes = prepared.input_bytes;
    std::vector<uint8_t> packet;
    std::vector<uint8_t> packet_out;
    std::vector<uint8_t> context_in;
    __sk_buff context_out = {};
    int result_fd = -1;
    uint32_t key = 0;
    const bool result_from_skb_context =
        packet_kind == packet_context_kind::skb &&
        (prepared.effective_io_mode == "packet" || prepared.effective_io_mode == "staged");

    if (prepared.effective_io_mode == "map") {
        bpf_map *input_map = bpf_object__find_map_by_name(prepared.object.get(), "input_map");
        bpf_map *result_map = bpf_object__find_map_by_name(prepared.object.get(), "result_map");
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
                packet = build_packet_input(input_bytes, program.program_info.type);
            }
            packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        }
        if (bpf_map_update_elem(result_fd, &key, &zero, BPF_ANY) != 0) {
            fail("bpf_map_update_elem(result_map) failed: " + std::string(strerror(errno)));
        }
        exec_input_prepare_end = std::chrono::steady_clock::now();
    } else if (prepared.effective_io_mode == "staged") {
        if (packet_kind == packet_context_kind::none) {
            fail("io-mode staged requires an XDP or skb packet context");
        }
        exec_input_prepare_start = std::chrono::steady_clock::now();
        if (options.raw_packet) {
            packet = input_bytes;
        } else {
            packet = build_packet_input(input_bytes, program.program_info.type);
        }
        packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        exec_input_prepare_end = std::chrono::steady_clock::now();
    } else if (prepared.effective_io_mode == "context") {
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
            packet = build_packet_input(input_bytes, program.program_info.type);
        }
        packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        exec_input_prepare_end = std::chrono::steady_clock::now();
    }

    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    const bool kernel_repeat_supported =
        prepared.effective_io_mode != "context" ||
        context_mode_supports_kernel_repeat(program.program_info.type);
    const uint32_t requested_repeat = kernel_repeat_supported ? options.repeat : 1u;
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
        .program_fd = program.program_fd,
        .test_opts = &test_opts,
        .effective_repeat = requested_repeat,
        .tsc_freq_hz = tsc_freq_hz,
        .packet_out = packet_out.empty() ? nullptr : &packet_out,
        .context_out = result_from_skb_context ? &context_out : nullptr,
        .context_out_size = static_cast<uint32_t>(sizeof(context_out)),
        .result_fd = result_fd,
        .result_key = key,
        .reset_result_map = prepared.effective_io_mode == "map",
    };

    const uint64_t base_compile_ns =
        prepared.memory_prepare_ns +
        prepared.object_open_ns +
        prepared.object_load_ns;
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
                {"memory_prepare_ns", prepared.memory_prepare_ns},
                {"object_open_ns", prepared.object_open_ns},
                {"object_load_ns", prepared.object_load_ns},
            };
            if (include_rejit_apply_phase &&
                measured_rejit.syscall_attempted) {
                sample.phases_ns.push_back({"rejit_apply_ns", rejit_apply_ns});
            }
            sample.phases_ns.push_back(
                {prepare_phase_name(prepared.effective_io_mode),
                 elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)});
            sample.phases_ns.push_back(
                {"prog_run_wall_ns",
                 elapsed_ns(measurement.wall_start, measurement.wall_end)});
            sample.phases_ns.push_back(
                {result_phase_name(prepared.effective_io_mode),
                 elapsed_ns(measured_result_read_start, measured_result_read_end)});
            sample.perf_counters = std::move(perf_counters);
            return sample;
        };

    const bool measure_same_image_pair =
        rejit.requested &&
        !prepared_rejit_already_applied &&
        !options.daemon_socket.has_value();
    std::optional<sample_result> stock_sample;
    if (measure_same_image_pair) {
        const rejit_summary stock_rejit = rejit;
        auto stock_pass = execute_kernel_measurement_pass(
            run_context,
            options,
            options.warmup_repeat,
            options.perf_counters);
        const auto stock_result_read_start = std::chrono::steady_clock::now();
        const uint64_t stock_result = read_kernel_test_run_result(
            prepared.effective_io_mode,
            result_from_skb_context,
            packet_out,
            context_out,
            result_fd,
            key,
            stock_pass.measurement.retval);
        const auto stock_result_read_end = std::chrono::steady_clock::now();
        const auto stock_program_info = load_prog_info(program.program_fd);
        program.program_info = stock_program_info;
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

        auto rejit_start = std::chrono::steady_clock::now();
        auto rejit_end = rejit_start;
        apply_rejit(
            program.program_fd,
            program.rejit_insns.data(),
            static_cast<uint32_t>(program.rejit_insns.size()),
            rejit,
            rejit_start,
            rejit_end);
        rejit_apply_ns = elapsed_ns(rejit_start, rejit_end);
        program.prepared_rejit = rejit;
        program.rejit_apply_ns = rejit_apply_ns;
        program.rejit_applied = true;
        program.program_info = load_prog_info(program.program_fd);
    }

    auto run_pass = execute_kernel_measurement_pass(
        run_context,
        options,
        measure_same_image_pair ? options.warmup_repeat : 0u,
        true);
    const auto &run_measurement = run_pass.measurement;

    const auto result_read_start_now = std::chrono::steady_clock::now();
    const uint64_t result = read_kernel_test_run_result(
        prepared.effective_io_mode,
        result_from_skb_context,
        packet_out,
        context_out,
        result_fd,
        key,
        run_measurement.retval);
    const auto result_read_end_now = std::chrono::steady_clock::now();
    result_read_start = result_read_start_now;
    result_read_end = result_read_end_now;

    const auto final_program_info = load_prog_info(program.program_fd);
    program.program_info = final_program_info;
    maybe_write_prepared_program_dumps(prepared, program);

    auto sample = build_measured_sample(
        measure_same_image_pair ? std::optional<std::string>(std::string("rejit"))
                                : std::nullopt,
        base_compile_ns + rejit_apply_ns,
        run_measurement,
        result,
        final_program_info,
        rejit,
        std::move(run_pass.perf_counters),
        result_read_start,
        result_read_end,
        measure_same_image_pair);
    if (stock_sample.has_value()) {
        const uint32_t stock_retval = stock_sample->retval;
        const uint32_t recompile_retval = sample.retval;
        const bool mismatch = (stock_retval != recompile_retval);
        stock_sample->correctness_mismatch = false;
        sample.correctness_mismatch = mismatch;
        if (mismatch) {
            fprintf(stderr,
                    "CORRECTNESS MISMATCH: stock retval=%u, recompile retval=%u\n",
                    stock_retval, recompile_retval);
        }
        return {std::move(*stock_sample), std::move(sample)};
    }
    return {std::move(sample)};
}

} // namespace

prepared_kernel_handle prepare_kernel(const cli_options &options)
{
    initialize_micro_exec_process();

    if (options.manual_load && !options.program_name.has_value()) {
        fail("prepare_kernel with --manual-load requires --program-name");
    }

    auto prepared = std::make_shared<prepared_kernel_state>();
    prepared->options = options;

    const auto memory_prepare_start = std::chrono::steady_clock::now();
    prepared->input_bytes = materialize_memory(options.memory, options.input_size);
    const auto memory_prepare_end = std::chrono::steady_clock::now();
    prepared->memory_prepare_ns = elapsed_ns(memory_prepare_start, memory_prepare_end);
    if (options.input_size != 0 && prepared->input_bytes.size() < options.input_size) {
        prepared->input_bytes.resize(options.input_size, 0);
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
    prepared->object_open_ns = elapsed_ns(object_open_start, object_open_end);
    prepared->object = bpf_object_ptr(raw_object);
    configure_autoload(prepared->object.get(), options.program_name);

    const auto object_load_start = std::chrono::steady_clock::now();
    if (options.manual_load) {
        prepared->program_fd = manual_load_program(prepared->object.get(), options);
        prepared->manual_program_fd.reset(prepared->program_fd);
        prepared_program_state state;
        state.program_fd = prepared->program_fd;
        state.program_info = load_prog_info(prepared->program_fd);
        const std::string selected_name = *options.program_name;
        prepared->program_order.push_back(selected_name);
        prepared->programs.emplace(selected_name, std::move(state));
    } else {
        const int load_error = bpf_object__load(prepared->object.get());
        if (load_error != 0) {
            fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
        }

        bpf_program *program = nullptr;
        bpf_object__for_each_program(program, prepared->object.get()) {
            const char *name = bpf_program__name(program);
            if (name == nullptr || name[0] == '\0') {
                continue;
            }
            const int program_fd = bpf_program__fd(program);
            if (program_fd < 0) {
                continue;
            }
            prepared_program_state state;
            state.prog = program;
            state.program_fd = program_fd;
            state.program_info = load_prog_info(program_fd);
            prepared->program_order.emplace_back(name);
            prepared->programs.emplace(name, std::move(state));
        }
        if (prepared->programs.empty()) {
            fail("prepared kernel state did not load any programs");
        }
    }
    const auto object_load_end = std::chrono::steady_clock::now();
    prepared->object_load_ns = elapsed_ns(object_load_start, object_load_end);
    prepared->effective_io_mode =
        resolve_effective_io_mode(options.io_mode, prepared->object.get());

    if (options.program_name.has_value()) {
        auto &selected = require_prepared_program(*prepared, options.program_name);
        prepared->prog = selected.prog;
        prepared->program_fd = selected.program_fd;
        prepared->program_info = selected.program_info;
    } else if (prepared->program_order.size() == 1) {
        auto &selected = prepared->programs.at(prepared->program_order.front());
        prepared->prog = selected.prog;
        prepared->program_fd = selected.program_fd;
        prepared->program_info = selected.program_info;
    }

    if (options.rejit) {
        if (options.rejit_program.has_value() && !options.program_name.has_value()) {
            fail("replacement REJIT requires --program-name for prepared kernel state");
        }
        if (!options.daemon_socket.has_value() &&
            !options.program_name.has_value() &&
            prepared->program_order.size() > 1) {
            fail("multi-program prepared kernel state only supports daemon REJIT");
        }

        for (const auto &program_name : prepared->program_order) {
            auto &program = prepared->programs.at(program_name);
            program.prepared_rejit.requested = true;
            if (options.daemon_socket.has_value()) {
                program.prepared_rejit.mode = "daemon";
            } else if (options.rejit_program.has_value()) {
                program.prepared_rejit.mode = "replacement";
                auto replacement_image = load_program_image(
                    *options.rejit_program, std::optional<std::string>(program_name));
                if (replacement_image.code.size() % sizeof(bpf_insn) != 0) {
                    fail("replacement program image does not contain aligned BPF instructions");
                }
                const size_t cnt = replacement_image.code.size() / sizeof(bpf_insn);
                program.rejit_insns.resize(cnt);
                std::memcpy(
                    program.rejit_insns.data(),
                    replacement_image.code.data(),
                    replacement_image.code.size());
            } else {
                program.prepared_rejit.mode = "same-bytecode";
                if (program.prog == nullptr) {
                    fail("same-bytecode REJIT requires a program loaded via bpf_object__load "
                         "(not manual_load_program)");
                }
                const size_t cnt = bpf_program__insn_cnt(program.prog);
                if (cnt == 0) {
                    fail("bpf_program__insn_cnt returned 0 for REJIT");
                }
                const bpf_insn *raw = bpf_program__insns(program.prog);
                program.rejit_insns.assign(raw, raw + cnt);
            }
        }

        if (options.program_name.has_value()) {
            auto &selected = require_prepared_program(*prepared, options.program_name);
            prepared->prepared_rejit = selected.prepared_rejit;
            prepared->rejit_insns = selected.rejit_insns;
            if (options.daemon_socket.has_value()) {
                fprintf(stderr, "rejit: mode=daemon-socket socket=%s prog_id=%u\n",
                        options.daemon_socket->c_str(), selected.program_info.id);
            } else {
                fprintf(stderr, "rejit: mode=%s insn_cnt=%zu\n",
                        selected.prepared_rejit.mode.c_str(),
                        selected.rejit_insns.size());
            }
        }
    }

    if (options.compile_only && options.rejit && options.program_name.has_value()) {
        auto &selected = require_prepared_program(*prepared, options.program_name);
        if (options.daemon_socket.has_value()) {
            maybe_apply_prepared_daemon_rejit(selected, options);
        } else {
            maybe_apply_prepared_bytecode_rejit(selected, options);
        }
        prepared->prepared_rejit = selected.prepared_rejit;
        prepared->rejit_insns = selected.rejit_insns;
        prepared->rejit_apply_ns = selected.rejit_apply_ns;
        prepared->rejit_applied = selected.rejit_applied;
        prepared->program_info = selected.program_info;
    }

    return prepared;
}

sample_result summarize_prepared_kernel_compile(const prepared_kernel_handle &prepared)
{
    if (!prepared) {
        fail("summarize_prepared_kernel_compile requires a prepared kernel handle");
    }
    return build_compile_only_sample(*prepared);
}

std::vector<sample_result> run_prepared_kernel(
    const prepared_kernel_handle &prepared,
    const cli_options &options)
{
    if (!prepared) {
        fail("run_prepared_kernel requires a prepared kernel handle");
    }
    if (options.compile_only) {
        if (options.program_name.has_value()) {
            return {build_prepared_program_compile_sample(*prepared, options)};
        }
        return {build_compile_only_sample(*prepared)};
    }
    if (options.attach_mode) {
        return execute_prepared_kernel_attach(*prepared, options);
    }
    return execute_prepared_kernel_run(*prepared, options);
}

void initialize_micro_exec_process()
{
    (void)get_process_runtime_state();
}

std::vector<sample_result> run_kernel(const cli_options &options)
{
    initialize_micro_exec_process();

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
    maybe_load_map_fixtures(options, object.get());
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
        const auto sock_resp = daemon_socket_optimize(*options.daemon_socket, program_info.id, options.passes);
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
            const auto sock_resp = daemon_socket_optimize(*options.daemon_socket, program_info.id, options.passes);
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
        const uint32_t stock_retval = stock_sample->retval;
        const uint32_t recompile_retval = sample.retval;
        const bool mismatch = (stock_retval != recompile_retval);
        stock_sample->correctness_mismatch = false;
        sample.correctness_mismatch = mismatch;
        if (mismatch) {
            fprintf(stderr,
                    "CORRECTNESS MISMATCH: stock retval=%u, recompile retval=%u\n",
                    stock_retval, recompile_retval);
        }
        return {std::move(*stock_sample), std::move(sample)};
    }
    return {std::move(sample)};
}

/* ================================================================
 * run_kernel_attach: attach-based execution measurement using
 * bpf_stats (run_cnt / run_time_ns) for program types that
 * cannot use BPF_PROG_TEST_RUN (kprobe, tracepoint, fentry, etc.)
 * ================================================================ */
std::vector<sample_result> run_kernel_attach(const cli_options &options)
{
    initialize_micro_exec_process();

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

    /* If a specific program is requested, disable autoload for others */
    configure_autoload(object.get(), options.program_name);

    /* Load all programs into the kernel */
    const auto object_load_start = std::chrono::steady_clock::now();
    const int load_error = bpf_object__load(object.get());
    if (load_error != 0) {
        fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
    }
    const auto object_load_end = std::chrono::steady_clock::now();
    maybe_load_map_fixtures(options, object.get());

    /* Find the target program */
    bpf_program *prog = find_program(object.get(), options.program_name);
    const int program_fd = bpf_program__fd(prog);
    if (program_fd < 0) {
        fail("unable to obtain program fd");
    }
    const auto program_info_before = load_prog_info(program_fd);
    const uint64_t base_compile_ns =
        elapsed_ns(object_open_start, object_open_end) +
        elapsed_ns(object_load_start, object_load_end);

    /* v2 REJIT: optionally optimize before measurement */
    std::chrono::steady_clock::time_point rejit_start {};
    std::chrono::steady_clock::time_point rejit_end {};
    rejit_summary rejit {};
    if (options.rejit && options.daemon_socket.has_value()) {
        rejit.requested = true;
        rejit.mode = "daemon";
        rejit_start = std::chrono::steady_clock::now();
        const auto sock_resp =
            daemon_socket_optimize(*options.daemon_socket, program_info_before.id, options.passes);
        rejit_end = std::chrono::steady_clock::now();
        rejit.syscall_attempted = true;
        if (!sock_resp.ok) {
            rejit.applied = false;
            rejit.error = "daemon socket optimize failed: " + sock_resp.error;
            fprintf(stderr, "daemon socket optimize failed: %s\n", sock_resp.error.c_str());
        } else {
            rejit.applied = sock_resp.applied;
            rejit.total_sites_applied = sock_resp.total_sites_applied;
            rejit.passes_applied = sock_resp.passes_applied;
            rejit.insn_delta = sock_resp.insn_delta;
            rejit.verifier_retries = sock_resp.verifier_retries;
            rejit.final_disabled_passes = sock_resp.final_disabled_passes;
        }
        rejit.daemon_response = sock_resp.raw_json;
    }

    /* Attach the program */
    const auto attach_start = std::chrono::steady_clock::now();
    bpf_link *raw_link = bpf_program__attach(prog);
    const int attach_error = libbpf_get_error(raw_link);
    if (attach_error != 0) {
        fail("bpf_program__attach failed: " + libbpf_error_string(attach_error));
    }
    bpf_link_ptr link(raw_link);
    const auto attach_end = std::chrono::steady_clock::now();
    fprintf(stderr, "attach: program '%s' attached successfully\n",
            bpf_program__name(prog));

    /* Enable bpf_stats (run_cnt / run_time_ns tracking) */
    const int stats_fd = bpf_enable_stats(BPF_STATS_RUN_TIME);
    if (stats_fd < 0) {
        fail("bpf_enable_stats(BPF_STATS_RUN_TIME) failed: " + std::string(strerror(errno)));
    }
    scoped_fd stats_fd_guard(stats_fd);

    const uint32_t warmup_workload_amount = is_duration_based_workload(options.workload_type)
        ? options.workload_iterations
        : options.warmup_repeat * options.workload_iterations;
    const uint32_t measured_workload_amount = is_duration_based_workload(options.workload_type)
        ? options.workload_iterations
        : options.repeat * options.workload_iterations;

    /* Warmup: duration-based workloads treat workload_iterations as total seconds. */
    if (options.warmup_repeat > 0) {
        run_workload(options.workload_type, warmup_workload_amount);
    }

    /* Read stats before the measured workload */
    const auto before_stats = read_bpf_stats(program_fd);

    /* Execute the measured workload */
    const auto exec_wall_start = std::chrono::steady_clock::now();
    const uint64_t tsc_before = rdtsc_start();
    run_workload(options.workload_type, measured_workload_amount);
    const uint64_t tsc_after = rdtsc_end();
    const auto exec_wall_end = std::chrono::steady_clock::now();

    /* Read stats after the measured workload */
    const auto after_stats = read_bpf_stats(program_fd);

    /* Close stats fd to stop accounting */
    stats_fd_guard.reset();

    /* Detach and cleanup the link */
    link.reset();

    /* Compute deltas */
    const uint64_t run_cnt_delta = after_stats.run_cnt - before_stats.run_cnt;
    const uint64_t run_time_ns_delta = after_stats.run_time_ns - before_stats.run_time_ns;

    fprintf(stderr, "attach: run_cnt=%lu run_time_ns=%lu (delta: cnt=%lu time=%lu)\n",
            static_cast<unsigned long>(after_stats.run_cnt),
            static_cast<unsigned long>(after_stats.run_time_ns),
            static_cast<unsigned long>(run_cnt_delta),
            static_cast<unsigned long>(run_time_ns_delta));

    /* Compute per-invocation exec_ns (avoid division by zero) */
    const uint64_t exec_ns = run_cnt_delta > 0
        ? run_time_ns_delta / run_cnt_delta
        : 0;

    /* TSC-derived wall time */
    const uint64_t tsc_freq_hz = kHasTscMeasurement ? detect_tsc_freq_hz() : 0;
    std::optional<uint64_t> wall_exec_ns;
    std::optional<uint64_t> exec_cycles;
    if (kHasTscMeasurement && tsc_freq_hz > 0 && tsc_after > tsc_before && run_cnt_delta > 0) {
        const uint64_t total_cycles = tsc_after - tsc_before;
        exec_cycles = total_cycles / run_cnt_delta;
        wall_exec_ns = static_cast<uint64_t>(std::llround(
            (static_cast<long double>(total_cycles) * 1000000000.0L) /
            (static_cast<long double>(tsc_freq_hz) *
             static_cast<long double>(run_cnt_delta))));
    }

    const auto final_program_info = load_prog_info(program_fd);

    /* Build sample result */
    sample_result sample;
    if (options.rejit && options.daemon_socket.has_value()) {
        sample.phase = "recompile";
    }
    sample.compile_ns = base_compile_ns + elapsed_ns(rejit_start, rejit_end);
    sample.exec_ns = exec_ns;
    sample.timing_source = "bpf_stats";
    sample.timing_source_wall =
        wall_exec_ns.has_value() ? "rdtsc" : "unavailable";
    sample.wall_exec_ns = wall_exec_ns;
    sample.exec_cycles = exec_cycles;
    sample.tsc_freq_hz = tsc_freq_hz > 0
        ? std::optional<uint64_t>(tsc_freq_hz)
        : std::nullopt;
    sample.result = run_cnt_delta;
    sample.retval = 0;
    sample.jited_prog_len = final_program_info.jited_prog_len;
    sample.xlated_prog_len = final_program_info.xlated_prog_len;
    sample.code_size = {
        .bpf_bytecode_bytes = final_program_info.xlated_prog_len,
        .native_code_bytes = final_program_info.jited_prog_len,
    };
    sample.rejit = rejit;
    sample.phases_ns = {
        {"object_open_ns", elapsed_ns(object_open_start, object_open_end)},
        {"object_load_ns", elapsed_ns(object_load_start, object_load_end)},
        {"attach_ns", elapsed_ns(attach_start, attach_end)},
        {"workload_wall_ns", elapsed_ns(exec_wall_start, exec_wall_end)},
    };
    if (rejit.syscall_attempted) {
        sample.phases_ns.push_back(
            {"rejit_apply_ns", elapsed_ns(rejit_start, rejit_end)});
    }

    return {std::move(sample)};
}
