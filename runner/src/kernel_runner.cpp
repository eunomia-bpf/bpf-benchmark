#include "micro_exec.hpp"
#include "bpf_helpers.hpp"

#include <arpa/inet.h>

#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <array>
#include <cerrno>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <netinet/in.h>
#include <string>
#include <string_view>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <thread>
#include <unordered_map>
#include <unistd.h>
#include <utility>
#include <vector>

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
    unsigned int lo = 0;
    unsigned int hi = 0;
    asm volatile("lfence; rdtsc" : "=a"(lo), "=d"(hi));
    return (static_cast<uint64_t>(hi) << 32) | lo;
}

static inline uint64_t rdtsc_end()
{
    unsigned int lo = 0;
    unsigned int hi = 0;
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

struct kernel_probe_context {
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

struct kernel_run_measurement {
    uint64_t exec_ns = 0;
    std::optional<uint64_t> wall_exec_ns;
    std::optional<uint64_t> exec_cycles;
    uint32_t retval = 0;
    std::chrono::steady_clock::time_point wall_start {};
    std::chrono::steady_clock::time_point wall_end {};
};

struct kernel_run_pass_result {
    kernel_run_measurement measurement {};
    perf_counter_capture perf_counters {};
};

struct object_deleter {
    void operator()(bpf_object *obj) const
    {
        if (obj != nullptr) {
            bpf_object__close(obj);
        }
    }
};

using bpf_object_ptr = std::unique_ptr<bpf_object, object_deleter>;

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

  private:
    int fd_ = -1;
};

enum class packet_context_kind {
    none,
    xdp,
    skb,
};

struct live_fixture_map {
    std::string name;
    uint32_t id = 0;
    uint32_t type = 0;
    uint32_t key_size = 0;
    uint32_t value_size = 0;
    uint32_t map_flags = 0;
    int fd = -1;
};

bool katran_balancer_fixture_requested(const cli_options &options)
{
    return options.program_name.has_value() &&
           *options.program_name == kKatranBalancerProgramName;
}

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

        const auto unit_end =
            line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", unit_start);
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
        fail("katran fixture missing required maps");
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

void reset_kernel_probe_state(kernel_probe_context &context)
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
        if (bpf_map_update_elem(context.result_fd, &context.result_key, &zero, BPF_ANY) != 0) {
            fail("bpf_map_update_elem(result_map) failed: " + std::string(strerror(errno)));
        }
    }
}

kernel_run_measurement execute_kernel_probe(kernel_probe_context &context)
{
    reset_kernel_probe_state(context);

    kernel_run_measurement measurement {};
    const auto wall_start = std::chrono::steady_clock::now();
    const uint64_t tsc_before = rdtsc_start();
    const int run_error = bpf_prog_test_run_opts(context.program_fd, context.test_opts);
    const uint64_t tsc_after = rdtsc_end();
    const auto wall_end = std::chrono::steady_clock::now();

    if (run_error != 0) {
        fail("bpf_prog_test_run_opts failed: " + std::string(strerror(errno)));
    }

    measurement.exec_ns = context.test_opts->duration;
    measurement.retval = context.test_opts->retval;
    measurement.wall_start = wall_start;
    measurement.wall_end = wall_end;

    if (kHasTscMeasurement && context.tsc_freq_hz > 0 && tsc_after > tsc_before) {
        const uint64_t total_cycles = tsc_after - tsc_before;
        measurement.exec_cycles = static_cast<uint64_t>(std::llround(
            static_cast<long double>(total_cycles) /
            static_cast<long double>(context.effective_repeat)));
        measurement.wall_exec_ns = static_cast<uint64_t>(std::llround(
            (static_cast<long double>(total_cycles) * 1000000000.0L) /
            (static_cast<long double>(context.tsc_freq_hz) *
             static_cast<long double>(context.effective_repeat))));
    }

    return measurement;
}

kernel_run_pass_result execute_kernel_measurement_pass(
    kernel_probe_context &context,
    const cli_options &options)
{
    for (uint32_t warmup_index = 0; warmup_index < options.warmup_repeat; ++warmup_index) {
        static_cast<void>(execute_kernel_probe(context));
    }

    kernel_run_pass_result result {};
    if (!options.perf_counters) {
        result.measurement = execute_kernel_probe(context);
        return result;
    }

    const perf_counter_options perf_options = {
        .enabled = true,
        .include_kernel = true,
        .scope = options.perf_scope,
    };
    result.perf_counters = measure_perf_counters(
        perf_options,
        [&]() {
            result.measurement = execute_kernel_probe(context);
        });

    if (options.perf_scope == "full_repeat_avg") {
        for (auto &counter : result.perf_counters.counters) {
            counter.value /= context.effective_repeat;
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

std::string resolve_effective_io_mode(std::string_view requested_io_mode, bpf_object *object)
{
    if (requested_io_mode != "map") {
        return std::string(requested_io_mode);
    }

    const bool has_input_map = bpf_object__find_map_by_name(object, "input_map") != nullptr;
    const bool has_result_map = bpf_object__find_map_by_name(object, "result_map") != nullptr;
    if (has_input_map && !has_result_map) {
        fail("io-mode map requires result_map when input_map is present");
    }
    return std::string(requested_io_mode);
}

bool fixture_map_is_userspace_readonly(const live_fixture_map &map)
{
    if ((map.map_flags & BPF_F_RDONLY) != 0) {
        return true;
    }
    return map.name.rfind(".rodata", 0) == 0 ||
           map.name.rfind(".kconfig", 0) == 0 ||
           map.name.rfind(".ksyms", 0) == 0;
}

std::string require_scalar_string_field(const YAML::Node &node, std::string_view field_name)
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

std::optional<uint32_t> optional_u32_field(const YAML::Node &node, std::string_view field_name)
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

std::vector<uint8_t> decode_hex_bytes(std::string_view text, std::string_view field_name)
{
    size_t start = 0;
    size_t end = text.size();
    while (start < end && std::isspace(static_cast<unsigned char>(text[start])) != 0) {
        ++start;
    }
    while (end > start && std::isspace(static_cast<unsigned char>(text[end - 1])) != 0) {
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
        fail("bpf_map_get_info_by_fd failed during fixture replay: " + std::string(strerror(errno)));
    }

    const char *map_name = bpf_map__name(map);
    return {
        .name = map_name != nullptr ? std::string(map_name) : std::string(),
        .id = info.id,
        .type = info.type,
        .key_size = info.key_size,
        .value_size = info.value_size,
        .map_flags = info.map_flags,
        .fd = fd,
    };
}

void load_map_fixtures(const std::filesystem::path &fixture_json_path, bpf_object *object)
{
    YAML::Node root;
    try {
        root = YAML::LoadFile(fixture_json_path.string());
    } catch (const YAML::Exception &error) {
        fail("unable to parse fixture JSON '" + fixture_json_path.string() + "': " + error.what());
    }

    const YAML::Node maps = root["maps"];
    if (!maps || !maps.IsSequence()) {
        fail("fixture JSON '" + fixture_json_path.string() + "' must contain a 'maps' sequence");
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
    for (const auto &map_node : maps) {
        if (!map_node.IsMap()) {
            fail("fixture JSON '" + fixture_json_path.string() + "' contains a non-object map entry");
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
        } else {
            const auto found = maps_by_id.find(*map_id);
            if (found == maps_by_id.end()) {
                fail("fixture map id " + std::to_string(*map_id) + " not found in loaded object");
            }
            live_map = &found->second;
        }

        if (fixture_map_is_userspace_readonly(*live_map)) {
            fail("fixture map '" + live_map->name + "' is read-only to userspace");
        }
        if (live_map->type == BPF_MAP_TYPE_PROG_ARRAY ||
            live_map->type == BPF_MAP_TYPE_ARRAY_OF_MAPS ||
            live_map->type == BPF_MAP_TYPE_HASH_OF_MAPS) {
            fail("fixture map '" + live_map->name + "' uses unsupported reference-valued map type");
        }

        const YAML::Node entries = map_node["entries"];
        if (!entries || !entries.IsSequence()) {
            fail("fixture map '" + live_map->name + "' must contain an 'entries' sequence");
        }

        for (const auto &entry_node : entries) {
            if (!entry_node.IsMap()) {
                fail("fixture map '" + live_map->name + "' contains a non-object entry");
            }

            const auto key = decode_hex_bytes(
                require_scalar_string_field(entry_node["key_hex"], "key_hex"),
                "key_hex");
            const auto value = decode_hex_bytes(
                require_scalar_string_field(entry_node["value_hex"], "value_hex"),
                "value_hex");
            if (key.size() != live_map->key_size) {
                fail("fixture map '" + live_map->name + "' key size mismatch");
            }
            if (value.size() != live_map->value_size) {
                fail("fixture map '" + live_map->name + "' value size mismatch");
            }

            if (bpf_map_update_elem(live_map->fd, key.data(), value.data(), BPF_ANY) != 0) {
                fail("bpf_map_update_elem(" + live_map->name + ") failed: " +
                     std::string(strerror(errno)));
            }
            ++loaded_entries;
        }
    }

    std::fprintf(
        stderr,
        "loaded %zu fixture entries from %s\n",
        loaded_entries,
        fixture_json_path.c_str());
}

void maybe_load_map_fixtures(const cli_options &options, bpf_object *object)
{
    if (!options.fixture_path.has_value()) {
        return;
    }
    load_map_fixtures(*options.fixture_path, object);
}

int libbpf_log(enum libbpf_print_level, const char *fmt, va_list args)
{
    return vfprintf(stderr, fmt, args);
}

struct process_runtime_state {
    process_runtime_state()
    {
        libbpf_set_print(libbpf_log);

        struct btf *loaded_vmlinux_btf = btf__load_vmlinux_btf();
        if (loaded_vmlinux_btf == nullptr) {
            fail("vmlinux btf preload returned null");
        }

        const int load_error = libbpf_get_error(loaded_vmlinux_btf);
        if (load_error != 0) {
            fail("vmlinux btf preload failed: " + libbpf_error_string(load_error));
        }

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

void configure_autoload(bpf_object *object, const cli_options &options)
{
    if (!options.program_name.has_value() || options.program_name->empty()) {
        return;
    }

    bpf_map *map = nullptr;
    while ((map = bpf_object__next_map(object, map)) != nullptr) {
        if (bpf_map__type(map) == BPF_MAP_TYPE_PROG_ARRAY) {
            return;
        }
    }

    bpf_program *program = nullptr;
    while ((program = bpf_object__next_program(object, program)) != nullptr) {
        const char *current_name = bpf_program__name(program);
        const bool autoload = current_name != nullptr && *options.program_name == current_name;
        if (bpf_program__set_autoload(program, autoload) != 0) {
            fail("unable to configure program autoload");
        }
    }
}

bool skb_payload_starts_after_l2(uint32_t prog_type)
{
    return prog_type == BPF_PROG_TYPE_CGROUP_SKB;
}

std::vector<uint8_t> build_packet_input(const std::vector<uint8_t> &input_bytes, uint32_t prog_type)
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

uint64_t read_kernel_test_run_result(
    std::string_view effective_io_mode,
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
        fail("bpf_map_lookup_elem(result_map) failed: " + std::string(strerror(errno)));
    }
    return result;
}

void maybe_write_program_dumps(const cli_options &options, int program_fd, const bpf_prog_info &program_info)
{
    if (options.dump_jit) {
        const auto jited_program = load_jited_program(program_fd, program_info.jited_prog_len);
        const auto dump_path = std::filesystem::path(
            benchmark_name_for_program(options.program) + ".kernel.bin");
        write_binary_file(dump_path, jited_program.data(), jited_program.size());
    }
    if (options.dump_xlated.has_value()) {
        const auto xlated_program = load_xlated_program(program_fd, program_info.xlated_prog_len);
        write_binary_file(*options.dump_xlated, xlated_program.data(), xlated_program.size());
    }
}

} // namespace

void initialize_micro_exec_process()
{
    (void)get_process_runtime_state();
}

std::vector<sample_result> run_kernel(const cli_options &options)
{
    // TODO: moved to Python orchestrator (§5.6)
    // C++ no longer owns prepared state, daemon REJIT, attach-trigger workloads,
    // or batch orchestration. This path is a single load -> TEST_RUN -> JSON exit.

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
    configure_autoload(object.get(), options);

    const auto object_load_start = std::chrono::steady_clock::now();
    const int load_error = bpf_object__load(object.get());
    if (load_error != 0) {
        fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
    }
    const auto object_load_end = std::chrono::steady_clock::now();

    const std::string effective_io_mode = resolve_effective_io_mode(options.io_mode, object.get());

    if (katran_balancer_fixture_requested(options)) {
        initialize_katran_test_fixture(object.get());
    }
    maybe_load_map_fixtures(options, object.get());

    bpf_program *prog = find_program(object.get(), options.program_name);
    const int program_fd = bpf_program__fd(prog);
    if (program_fd < 0) {
        fail("unable to obtain program fd");
    }
    const auto program_info = load_prog_info(program_fd);

    std::chrono::steady_clock::time_point exec_input_prepare_start {};
    std::chrono::steady_clock::time_point exec_input_prepare_end {};
    std::chrono::steady_clock::time_point result_read_start {};
    std::chrono::steady_clock::time_point result_read_end {};

    std::vector<uint8_t> packet;
    std::vector<uint8_t> packet_out;
    std::vector<uint8_t> context_in;
    __sk_buff context_out = {};
    int result_fd = -1;
    uint32_t key = 0;

    const auto packet_kind = resolve_packet_context_kind(program_info.type);
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
            packet = options.raw_packet ? input_bytes : build_packet_input(input_bytes, program_info.type);
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
        packet = options.raw_packet ? input_bytes : build_packet_input(input_bytes, program_info.type);
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
        packet = options.raw_packet ? input_bytes : build_packet_input(input_bytes, program_info.type);
        packet_out.assign(packet_output_capacity(options, packet.size()), 0);
        exec_input_prepare_end = std::chrono::steady_clock::now();
    }

    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    const bool kernel_repeat_supported =
        effective_io_mode != "context" || context_mode_supports_kernel_repeat(program_info.type);
    const uint32_t effective_repeat = kernel_repeat_supported ? options.repeat : 1u;
    test_opts.repeat = kernel_repeat_supported ? effective_repeat : 0u;
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
    kernel_probe_context run_context = {
        .program_fd = program_fd,
        .test_opts = &test_opts,
        .effective_repeat = effective_repeat,
        .tsc_freq_hz = tsc_freq_hz,
        .packet_out = packet_out.empty() ? nullptr : &packet_out,
        .context_out = result_from_skb_context ? &context_out : nullptr,
        .context_out_size = static_cast<uint32_t>(sizeof(context_out)),
        .result_fd = result_fd,
        .result_key = key,
        .reset_result_map = effective_io_mode == "map",
    };

    auto run_pass = execute_kernel_measurement_pass(run_context, options);
    const auto &run_measurement = run_pass.measurement;

    result_read_start = std::chrono::steady_clock::now();
    const uint64_t result = read_kernel_test_run_result(
        effective_io_mode,
        result_from_skb_context,
        packet_out,
        context_out,
        result_fd,
        key,
        run_measurement.retval);
    result_read_end = std::chrono::steady_clock::now();

    const auto final_program_info = load_prog_info(program_fd);
    maybe_write_program_dumps(options, program_fd, final_program_info);

    sample_result sample;
    sample.compile_ns =
        elapsed_ns(object_open_start, object_open_end) +
        elapsed_ns(object_load_start, object_load_end);
    sample.exec_ns = run_measurement.exec_ns;
    sample.timing_source = "ktime";
    sample.timing_source_wall =
        run_measurement.wall_exec_ns.has_value() ? "rdtsc" : "unavailable";
    sample.wall_exec_ns = run_measurement.wall_exec_ns;
    sample.exec_cycles = run_measurement.exec_cycles;
    sample.tsc_freq_hz =
        tsc_freq_hz > 0 ? std::optional<uint64_t>(tsc_freq_hz) : std::nullopt;
    sample.result = result;
    sample.retval = run_measurement.retval;
    sample.jited_prog_len = final_program_info.jited_prog_len;
    sample.xlated_prog_len = final_program_info.xlated_prog_len;
    sample.code_size = {
        .bpf_bytecode_bytes = final_program_info.xlated_prog_len,
        .native_code_bytes = final_program_info.jited_prog_len,
    };
    sample.phases_ns = {
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {"object_open_ns", elapsed_ns(object_open_start, object_open_end)},
        {"object_load_ns", elapsed_ns(object_load_start, object_load_end)},
        {prepare_phase_name(effective_io_mode), elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)},
        {"prog_run_wall_ns", elapsed_ns(run_measurement.wall_start, run_measurement.wall_end)},
        {result_phase_name(effective_io_mode), elapsed_ns(result_read_start, result_read_end)},
    };
    sample.perf_counters = std::move(run_pass.perf_counters);
    return {std::move(sample)};
}
