#include "micro_exec.hpp"
#include "userspace_bpf_runtime.hpp"

#include <llvmbpf.hpp>

#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <memory>
#include <thread>
#include <sys/mman.h>
#include <unistd.h>
#include <utility>

namespace {

using clock_type = std::chrono::steady_clock;

constexpr uint32_t kProgTypeSchedCls = 3;
constexpr uint32_t kProgTypeSchedAct = 4;
constexpr uint32_t kProgTypeXdp = 6;
constexpr uint32_t kProgTypeCgroupSkb = 8;
constexpr size_t kEthernetHeaderSize = 14;
constexpr uintptr_t kLow32SearchStart = 0x10000000ULL;
constexpr uintptr_t kLow32SearchEnd = 0x100000000ULL;

#ifndef MAP_FIXED_NOREPLACE
#define MAP_FIXED_NOREPLACE 0x100000
#endif

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

uint64_t monotonic_now_ns()
{
    timespec ts {};
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        fail("clock_gettime(CLOCK_MONOTONIC) failed: " + std::string(strerror(errno)));
    }

    return (static_cast<uint64_t>(ts.tv_sec) * 1000000000ULL) + static_cast<uint64_t>(ts.tv_nsec);
}

size_t page_size()
{
    const long value = sysconf(_SC_PAGESIZE);
    return value > 0 ? static_cast<size_t>(value) : 4096U;
}

size_t align_up(size_t value, size_t alignment)
{
    if (alignment == 0 || value == 0) {
        return value;
    }
    return ((value + alignment - 1) / alignment) * alignment;
}

bool fits_xdp_md_range(uintptr_t address, size_t size)
{
    if (address > UINT32_MAX) {
        return false;
    }
    if (size == 0) {
        return true;
    }
    return size - 1 <= (static_cast<size_t>(UINT32_MAX) - static_cast<size_t>(address));
}

void *map_low_u32_region(size_t size)
{
    const size_t mapping_size = std::max<size_t>(size, 1);
    const size_t step = std::max<size_t>(align_up(mapping_size, page_size()), 64U << 20);
    constexpr int prot = PROT_READ | PROT_WRITE;
    constexpr int base_flags = MAP_PRIVATE | MAP_ANONYMOUS;

#if defined(MAP_32BIT) && MAP_32BIT != 0
    if (void *mapping = mmap(nullptr, mapping_size, prot, base_flags | MAP_32BIT, -1, 0);
        mapping != MAP_FAILED) {
        if (fits_xdp_md_range(reinterpret_cast<uintptr_t>(mapping), size)) {
            return mapping;
        }
        munmap(mapping, mapping_size);
    }
#endif

#if UINTPTR_MAX > UINT32_MAX
    const size_t page = page_size();
    for (uintptr_t hint = align_up(kLow32SearchStart, page); hint + mapping_size <= kLow32SearchEnd; hint += step) {
        void *mapping = mmap(
            reinterpret_cast<void *>(hint),
            mapping_size,
            prot,
            base_flags | MAP_FIXED_NOREPLACE,
            -1,
            0);
        if (mapping == MAP_FAILED) {
            continue;
        }
        if (fits_xdp_md_range(reinterpret_cast<uintptr_t>(mapping), size)) {
            return mapping;
        }
        munmap(mapping, mapping_size);
    }
#endif

    if (void *mapping = mmap(nullptr, mapping_size, prot, base_flags, -1, 0);
        mapping != MAP_FAILED) {
        if (fits_xdp_md_range(reinterpret_cast<uintptr_t>(mapping), size)) {
            return mapping;
        }
        munmap(mapping, mapping_size);
    }

    fail("unable to allocate llvmbpf packet buffer below 4 GiB for packet context");
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

template <typename VM>
int configure_no_cmov(VM &vm, bool enabled)
{
    if constexpr (requires(VM &candidate, bool value) { candidate.set_no_cmov(value); }) {
        return vm.set_no_cmov(enabled);
    }

    return enabled ? -1 : 0;
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

std::optional<uint64_t> detect_tsc_freq_hz()
{
    if constexpr (!kHasTscMeasurement) {
        return std::nullopt;
    }

    if (const auto nominal = read_nominal_tsc_freq_hz(); nominal.has_value()) {
        return *nominal;
    }

    return calibrate_tsc_freq_hz();
}

struct xdp_md_ctx {
    uint32_t data = 0;
    uint32_t data_end = 0;
    uint32_t data_meta = 0;
    uint32_t ingress_ifindex = 0;
    uint32_t rx_queue_index = 0;
    uint32_t egress_ifindex = 0;
};

struct sk_buff_ctx {
    uint32_t len = 0;
    uint32_t pkt_type = 0;
    uint32_t mark = 0;
    uint32_t queue_mapping = 0;
    uint32_t protocol = 0;
    uint32_t vlan_present = 0;
    uint32_t vlan_tci = 0;
    uint32_t vlan_proto = 0;
    uint32_t priority = 0;
    uint32_t ingress_ifindex = 0;
    uint32_t ifindex = 0;
    uint32_t tc_index = 0;
    uint32_t cb[5] = {};
    uint32_t hash = 0;
    uint32_t tc_classid = 0;
    uint32_t data = 0;
    uint32_t data_end = 0;
    uint32_t napi_id = 0;
    uint32_t family = 0;
    uint32_t remote_ip4 = 0;
    uint32_t local_ip4 = 0;
    uint32_t remote_ip6[4] = {};
    uint32_t local_ip6[4] = {};
    uint32_t remote_port = 0;
    uint32_t local_port = 0;
    uint32_t data_meta = 0;
    uint64_t flow_keys = 0;
    uint64_t tstamp = 0;
    uint32_t wire_len = 0;
    uint32_t gso_segs = 0;
    uint64_t sk = 0;
    uint32_t gso_size = 0;
    uint8_t tstamp_type = 0;
    uint8_t pad[3] = {};
    uint64_t hwtstamp = 0;
};

static_assert(offsetof(sk_buff_ctx, data) == 76);
static_assert(offsetof(sk_buff_ctx, data_end) == 80);
static_assert(offsetof(sk_buff_ctx, data_meta) == 140);

class lowmem_buffer {
public:
    explicit lowmem_buffer(size_t size)
        : size_(size)
    {
        mapping_size_ = std::max<size_t>(size_, 1);
        data_ = static_cast<uint8_t *>(map_low_u32_region(size_));
    }

    ~lowmem_buffer()
    {
        if (data_ != nullptr) {
            munmap(data_, mapping_size_);
        }
    }

    lowmem_buffer(const lowmem_buffer &) = delete;
    lowmem_buffer &operator=(const lowmem_buffer &) = delete;

    uint8_t *data() { return data_; }
    const uint8_t *data() const { return data_; }
    size_t size() const { return size_; }

private:
    uint8_t *data_ = nullptr;
    size_t size_ = 0;
    size_t mapping_size_ = 0;
};

enum class packet_context_kind {
    none,
    xdp,
    skb,
};

packet_context_kind resolve_packet_context_kind(uint32_t prog_type)
{
    switch (prog_type) {
    case kProgTypeXdp:
        return packet_context_kind::xdp;
    case kProgTypeSchedCls:
    case kProgTypeSchedAct:
    case kProgTypeCgroupSkb:
        return packet_context_kind::skb;
    default:
        return packet_context_kind::none;
    }
}

bool image_has_map(const program_image &image, std::string_view name)
{
    return std::any_of(image.maps.begin(), image.maps.end(), [&](const auto &spec) {
        return spec.name == name;
    });
}

bool skb_payload_starts_after_l2(uint32_t prog_type)
{
    return prog_type == kProgTypeCgroupSkb;
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

uint64_t read_skb_result(const sk_buff_ctx &ctx)
{
    return static_cast<uint64_t>(ctx.cb[0]) |
           (static_cast<uint64_t>(ctx.cb[1]) << 32);
}

const char *prepare_phase_name(std::string_view io_mode)
{
    if (io_mode == "packet") {
        return "packet_prepare_ns";
    }
    if (io_mode == "staged") {
        return "input_stage_ns";
    }
    return "map_prepare_ns";
}

std::string resolve_effective_io_mode(const cli_options &options,
                                      const program_image &image)
{
    if (options.io_mode != "map") {
        return options.io_mode;
    }

    bool has_input_map = false;
    bool has_result_map = false;
    for (const auto &spec : image.maps) {
        has_input_map = has_input_map || spec.name == "input_map";
        has_result_map = has_result_map || spec.name == "result_map";
    }
    if (has_input_map && !has_result_map) {
        fail("io-mode map requires result_map when input_map is present");
    }
    return options.io_mode;
}

} // namespace

sample_result run_llvmbpf(const cli_options &options)
{
    constexpr int kLlvmBpfOptimizationLevel = 3;

    const auto program_image_start = clock_type::now();
    const auto image = load_program_image(options.program);
    const auto program_image_end = clock_type::now();
    const std::string effective_io_mode = resolve_effective_io_mode(options, image);

    const auto memory_prepare_start = clock_type::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    const auto memory_prepare_end = clock_type::now();
    const bool has_input_map = image_has_map(image, "input_map");
    const bool result_from_map = effective_io_mode == "map";
    const bool input_from_packet =
        effective_io_mode == "packet" ||
        effective_io_mode == "staged" ||
        (effective_io_mode == "map" && !has_input_map);
    const auto packet_kind = resolve_packet_context_kind(image.prog_type);

    const auto exec_input_prepare_start = clock_type::now();
    auto map_state = userspace_bpf_map_state {};
    auto packet_input = std::vector<uint8_t> {};
    if (!image.maps.empty()) {
        map_state = initialize_userspace_bpf_map_state(image, input_bytes);
    }
    if (input_from_packet) {
        if (options.raw_packet) {
            packet_input = input_bytes;
        } else {
            packet_input = build_packet_input(input_bytes, image.prog_type);
        }
    }
    const auto exec_input_prepare_end = clock_type::now();

    bpftime::llvmbpf_vm vm;
    if (vm.set_optimization_level(kLlvmBpfOptimizationLevel) < 0) {
        fail("llvmbpf set_optimization_level failed: " + vm.get_error_message());
    }
    if (configure_no_cmov(vm, false) < 0) {
        fail("llvmbpf set_no_cmov failed: " + vm.get_error_message());
    }
    const auto load_code_start = clock_type::now();
    if (vm.load_code(image.code.data(), image.code.size()) < 0) {
        fail("llvmbpf load_code failed: " + vm.get_error_message());
    }
    const auto load_code_end = clock_type::now();
    vm.register_external_function(1, "bpf_map_lookup_elem", (void *)llvmbpf_helper_bpf_map_lookup_elem);
    vm.register_external_function(2, "bpf_map_update_elem", (void *)llvmbpf_helper_bpf_map_update_elem);
    vm.register_external_function(3, "bpf_map_delete_elem", (void *)llvmbpf_helper_bpf_map_delete_elem);
    vm.register_external_function(5, "bpf_ktime_get_ns", (void *)llvmbpf_helper_bpf_ktime_get_ns);
    vm.register_external_function(113, "bpf_probe_read_kernel", (void *)llvmbpf_helper_bpf_probe_read_kernel);
    for (int id = 3; id <= 220; id++) {
        if (id == 3 || id == 5 || id == 113) {
            continue;
        }
        vm.register_external_function(id, "bpf_helper_" + std::to_string(id), (void *)llvmbpf_helper_noop);
    }

    const auto compile_start = clock_type::now();
    auto compiled = vm.compile();
    const auto compile_end = clock_type::now();
    if (!compiled.has_value()) {
        fail("llvmbpf compile failed: " + vm.get_error_message());
    }

    const auto compiled_code = vm.get_compiled_code();
    if (!compiled_code.has_value()) {
        fail("llvmbpf native code inspection failed: " + vm.get_error_message());
    }
    if (options.dump_jit || options.dump_jit_path.has_value()) {
        const auto dump_path = options.dump_jit_path.value_or(
            std::filesystem::path(benchmark_name_for_program(options.program) + ".llvmbpf.bin"));
        write_binary_file(dump_path, compiled_code->data, compiled_code->size);
    }

    sample_result sample;
    sample.compile_ns = elapsed_ns(compile_start, compile_end);
    sample.code_size = {
        .bpf_bytecode_bytes = image.code.size(),
        .native_code_bytes = compiled_code->size,
    };

    uint64_t retval = 0;
    uint64_t result = 0;
    uint64_t total_exec_cycles = 0;
    uint64_t total_exec_ns = 0;
    const auto tsc_freq_hz = detect_tsc_freq_hz();
    const bool use_tsc_timing = tsc_freq_hz.has_value();
    const uint32_t repeat = options.repeat > 0 ? options.repeat : 1;
    set_active_userspace_bpf_map_state(!image.maps.empty() ? &map_state : nullptr);
    clock_type::time_point exec_start {};
    clock_type::time_point exec_end {};
    const auto run_timed_repeat = [&](auto &&exec_once) {
        const uint64_t measure_start =
            use_tsc_timing ? rdtsc_start() : monotonic_now_ns();
        for (uint32_t index = 0; index < repeat; ++index) {
            exec_once();
        }
        const uint64_t measure_end =
            use_tsc_timing ? rdtsc_end() : monotonic_now_ns();
        if (use_tsc_timing) {
            total_exec_cycles += measure_end - measure_start;
        } else {
            total_exec_ns += measure_end - measure_start;
        }
    };
    const auto run_map_repeat = [&](uint8_t *ctx, size_t ctx_size) {
        run_timed_repeat([&]() {
            if (vm.exec(ctx, ctx_size, retval) < 0) {
                fail("llvmbpf exec failed: " + vm.get_error_message());
            }
        });
    };
    const auto run_packet_repeat = [&](xdp_md_ctx &ctx) {
        run_timed_repeat([&]() {
            if (vm.exec(&ctx, sizeof(ctx), retval) < 0) {
                fail("llvmbpf exec failed: " + vm.get_error_message());
            }
        });
    };
    const auto run_skb_repeat = [&](sk_buff_ctx &ctx) {
        run_timed_repeat([&]() {
            if (vm.exec(&ctx, sizeof(ctx), retval) < 0) {
                fail("llvmbpf exec failed: " + vm.get_error_message());
            }
        });
    };
    const auto run_packet_context = [&](lowmem_buffer &packet_buffer)
        -> std::optional<uint64_t> {
        const auto packet_address = reinterpret_cast<uintptr_t>(packet_buffer.data());
        if (packet_kind == packet_context_kind::xdp) {
            xdp_md_ctx ctx = {};
            ctx.data = static_cast<uint32_t>(packet_address);
            ctx.data_end = static_cast<uint32_t>(packet_address + packet_buffer.size());
            run_packet_repeat(ctx);
            return std::nullopt;
        }
        if (packet_kind == packet_context_kind::skb) {
            const size_t data_offset =
                skb_payload_starts_after_l2(image.prog_type) ? kEthernetHeaderSize : 0;
            if (packet_buffer.size() < data_offset) {
                fail("packet buffer shorter than skb L2 offset");
            }
            sk_buff_ctx ctx = {};
            ctx.len = static_cast<uint32_t>(packet_buffer.size() - data_offset);
            ctx.data = static_cast<uint32_t>(packet_address + data_offset);
            ctx.data_end = static_cast<uint32_t>(packet_address + packet_buffer.size());
            ctx.data_meta = ctx.data;
            run_skb_repeat(ctx);
            return read_skb_result(ctx);
        }
        fail("io-mode requires an XDP or skb packet context");
    };

    const perf_counter_options perf_options {
        .enabled = options.perf_counters,
        .include_kernel = false,
    };
    auto perf_counters = measure_perf_counters(perf_options, [&]() {
        exec_start = clock_type::now();
        if (packet_input.empty()) {
            uint8_t dummy_ctx[8] = {};
            run_map_repeat(dummy_ctx, sizeof(dummy_ctx));
        } else {
            lowmem_buffer packet_buffer(packet_input.size());
            std::memcpy(packet_buffer.data(), packet_input.data(), packet_input.size());

            const auto skb_result = run_packet_context(packet_buffer);
            if (!result_from_map) {
                if (skb_result.has_value()) {
                    result = *skb_result;
                } else {
                    result = read_u64_result(
                        packet_buffer.data(),
                        packet_buffer.size());
                }
            }
        }
        exec_end = clock_type::now();
    });
    set_active_userspace_bpf_map_state(nullptr);

    if (tsc_freq_hz.has_value()) {
        sample.exec_ns = static_cast<uint64_t>(std::llround(
            (static_cast<long double>(total_exec_cycles) * 1000000000.0L) /
            (static_cast<long double>(*tsc_freq_hz) * static_cast<long double>(repeat))));
        sample.exec_cycles = static_cast<uint64_t>(std::llround(
            static_cast<long double>(total_exec_cycles) / static_cast<long double>(repeat)));
        sample.tsc_freq_hz = *tsc_freq_hz;
        sample.timing_source = "rdtsc";
    } else {
        sample.exec_ns = static_cast<uint64_t>(std::llround(
            static_cast<long double>(total_exec_ns) / static_cast<long double>(repeat)));
        sample.timing_source = "clock_monotonic";
    }
    sample.wall_exec_ns = elapsed_ns(exec_start, exec_end) / repeat;
    sample.perf_counters = std::move(perf_counters);
    sample.result = result_from_map ? read_userspace_bpf_result_value(map_state) : result;
    sample.retval = static_cast<uint32_t>(retval);
    sample.phases_ns = {
        {"program_image_ns", elapsed_ns(program_image_start, program_image_end)},
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {prepare_phase_name(effective_io_mode),
         elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)},
        {"vm_load_code_ns", elapsed_ns(load_code_start, load_code_end)},
        {"jit_compile_ns", sample.compile_ns},
    };
    return sample;
}
