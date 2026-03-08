#include "micro_exec.hpp"

#include <llvmbpf.hpp>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <fstream>
#include <memory>
#include <thread>
#include <sys/mman.h>
#include <unordered_map>

namespace {

using clock_type = std::chrono::steady_clock;

constexpr uint32_t kMapTypeHash = 1;
constexpr uint32_t kMapTypeArray = 2;
constexpr uint32_t kMapTypePercpuArray = 6;

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

struct userspace_map {
    map_spec spec;
    std::vector<uint8_t> storage;
    std::unordered_map<uint32_t, std::vector<uint8_t>> hash_storage;
};

struct xdp_md_ctx {
    uint32_t data = 0;
    uint32_t data_end = 0;
    uint32_t data_meta = 0;
    uint32_t ingress_ifindex = 0;
    uint32_t rx_queue_index = 0;
    uint32_t egress_ifindex = 0;
};

struct userspace_map_state {
    std::unordered_map<uint32_t, userspace_map> maps_by_id;

    userspace_map *find_by_name(const std::string &name)
    {
        for (auto &[id, map] : maps_by_id) {
            (void)id;
            if (map.spec.name == name) {
                return &map;
            }
        }
        return nullptr;
    }
};

thread_local userspace_map_state *active_map_state = nullptr;

userspace_map *lookup_map(uint64_t map_id)
{
    if (active_map_state == nullptr) {
        return nullptr;
    }
    const auto iter = active_map_state->maps_by_id.find(static_cast<uint32_t>(map_id));
    if (iter == active_map_state->maps_by_id.end()) {
        return nullptr;
    }
    return &iter->second;
}

uint8_t *lookup_slot(userspace_map *map, uint64_t key_ptr)
{
    if (map == nullptr || key_ptr == 0 || map->spec.key_size != sizeof(uint32_t)) {
        return nullptr;
    }
    uint32_t key = 0;
    std::memcpy(&key, reinterpret_cast<const void *>(key_ptr), sizeof(key));

    if (map->spec.type == kMapTypeArray || map->spec.type == kMapTypePercpuArray) {
        if (key >= map->spec.max_entries) {
            return nullptr;
        }
        return map->storage.data() + static_cast<size_t>(key) * map->spec.value_size;
    }
    if (map->spec.type == kMapTypeHash) {
        const auto iter = map->hash_storage.find(key);
        if (iter == map->hash_storage.end()) {
            return nullptr;
        }
        return iter->second.data();
    }

    return nullptr;
}

bool update_slot(userspace_map *map, uint64_t key_ptr, uint64_t value_ptr)
{
    if (map == nullptr || key_ptr == 0 || value_ptr == 0 || map->spec.key_size != sizeof(uint32_t)) {
        return false;
    }

    uint32_t key = 0;
    std::memcpy(&key, reinterpret_cast<const void *>(key_ptr), sizeof(key));
    if (map->spec.type == kMapTypeArray || map->spec.type == kMapTypePercpuArray) {
        if (key >= map->spec.max_entries) {
            return false;
        }

        auto *slot = map->storage.data() + static_cast<size_t>(key) * map->spec.value_size;
        std::memcpy(slot, reinterpret_cast<const void *>(value_ptr), map->spec.value_size);
        return true;
    }
    if (map->spec.type == kMapTypeHash) {
        if (map->hash_storage.find(key) == map->hash_storage.end() &&
            map->hash_storage.size() >= map->spec.max_entries) {
            return false;
        }

        auto &value = map->hash_storage[key];
        value.resize(map->spec.value_size);
        std::memcpy(value.data(), reinterpret_cast<const void *>(value_ptr), map->spec.value_size);
        return true;
    }

    return false;
}

uint64_t helper_bpf_map_lookup_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t,
    uint64_t,
    uint64_t)
{
    auto *map = lookup_map(map_id);
    auto *slot = lookup_slot(map, key_ptr);
    return reinterpret_cast<uint64_t>(slot);
}

uint64_t helper_bpf_map_update_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t value_ptr,
    uint64_t,
    uint64_t)
{
    auto *map = lookup_map(map_id);
    if (!update_slot(map, key_ptr, value_ptr)) {
        return static_cast<uint64_t>(-1);
    }
    return 0;
}

uint64_t helper_bpf_probe_read_kernel(
    uint64_t dst_ptr,
    uint64_t size,
    uint64_t src_ptr,
    uint64_t,
    uint64_t)
{
    if (dst_ptr == 0 || src_ptr == 0) {
        return static_cast<uint64_t>(-1);
    }
    std::memcpy(
        reinterpret_cast<void *>(dst_ptr),
        reinterpret_cast<const void *>(src_ptr),
        static_cast<size_t>(size));
    return 0;
}

uint64_t helper_bpf_ktime_get_ns(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t)
{
    const auto now = std::chrono::steady_clock::now().time_since_epoch();
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(now).count());
}

static uint64_t helper_noop(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t)
{
    return 0;
}

class lowmem_buffer {
public:
    explicit lowmem_buffer(size_t size)
        : size_(size)
    {
        int flags = MAP_PRIVATE | MAP_ANONYMOUS;
#ifdef MAP_32BIT
        flags |= MAP_32BIT;
#endif
        void *mapping = mmap(nullptr, size_, PROT_READ | PROT_WRITE, flags, -1, 0);
        if (mapping == MAP_FAILED) {
            fail("mmap failed while preparing llvmbpf packet buffer");
        }
        data_ = static_cast<uint8_t *>(mapping);

        const auto address = reinterpret_cast<uintptr_t>(data_);
        if (address > UINT32_MAX || (size_ != 0 && address + size_ - 1 > UINT32_MAX)) {
            munmap(data_, size_);
            fail("llvmbpf packet buffer address exceeds 32-bit xdp_md range");
        }
    }

    ~lowmem_buffer()
    {
        if (data_ != nullptr) {
            munmap(data_, size_);
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
};

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

std::vector<uint8_t> build_result_packet()
{
    return std::vector<uint8_t>(64, 0);
}

userspace_map_state initialize_map_state(const program_image &image, const std::vector<uint8_t> &input_bytes)
{
    userspace_map_state state;
    for (const auto &spec : image.maps) {
        userspace_map map;
        map.spec = spec;
        if (spec.type == kMapTypeArray || spec.type == kMapTypePercpuArray) {
            map.storage.assign(static_cast<size_t>(spec.value_size) * spec.max_entries, 0);
        } else if (spec.type == kMapTypeHash) {
            map.hash_storage.reserve(spec.max_entries);
        } else {
            fail("unsupported llvmbpf map type: " + std::to_string(spec.type));
        }
        state.maps_by_id.emplace(spec.id, std::move(map));
    }

    if (auto *input_map = state.find_by_name("input_map"); input_map != nullptr) {
        const size_t copy_len = std::min(input_map->storage.size(), input_bytes.size());
        std::memcpy(input_map->storage.data(), input_bytes.data(), copy_len);
    }
    if (auto *result_map = state.find_by_name("result_map"); result_map != nullptr) {
        std::fill(result_map->storage.begin(), result_map->storage.end(), 0);
    }
    return state;
}

uint64_t read_result_value(const userspace_map_state &state)
{
    for (const auto &[id, map] : state.maps_by_id) {
        (void)id;
        if (map.spec.name != "result_map") {
            continue;
        }
        uint64_t result = 0;
        const size_t copy_len = std::min(sizeof(result), map.storage.size());
        std::memcpy(&result, map.storage.data(), copy_len);
        return result;
    }
    fail("result_map not found in llvmbpf map state");
}

} // namespace

sample_result run_llvmbpf(const cli_options &options)
{
    const auto program_image_start = clock_type::now();
    const auto image = load_program_image(options.program, options.program_name);
    const auto program_image_end = clock_type::now();

    const auto memory_prepare_start = clock_type::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    const auto memory_prepare_end = clock_type::now();

    const auto exec_input_prepare_start = clock_type::now();
    auto map_state = userspace_map_state {};
    auto packet_input = std::vector<uint8_t> {};
    if (options.io_mode == "map") {
        map_state = initialize_map_state(image, input_bytes);
    } else if (options.io_mode == "staged") {
        map_state = initialize_map_state(image, input_bytes);
        packet_input = build_result_packet();
    } else {
        if (options.raw_packet) {
            packet_input = input_bytes;
        } else {
            packet_input = build_packet_input(input_bytes);
        }
    }
    const auto exec_input_prepare_end = clock_type::now();

    bpftime::llvmbpf_vm vm;
    if (vm.set_optimization_level(options.opt_level) < 0) {
        fail("llvmbpf set_optimization_level failed: " + vm.get_error_message());
    }
    if (configure_no_cmov(vm, options.no_cmov) < 0) {
        if (options.no_cmov) {
            fail("llvmbpf build does not support --no-cmov");
        }
        fail("llvmbpf set_no_cmov failed: " + vm.get_error_message());
    }
    if (!options.disabled_passes.empty() &&
        vm.set_disabled_passes(options.disabled_passes) < 0) {
        fail("llvmbpf set_disabled_passes failed: " + vm.get_error_message());
    }
    if (options.log_passes && vm.set_log_passes(true) < 0) {
        fail("llvmbpf set_log_passes failed: " + vm.get_error_message());
    }
    const auto load_code_start = clock_type::now();
    if (vm.load_code(image.code.data(), image.code.size()) < 0) {
        fail("llvmbpf load_code failed: " + vm.get_error_message());
    }
    const auto load_code_end = clock_type::now();
    vm.register_external_function(1, "bpf_map_lookup_elem", (void *)helper_bpf_map_lookup_elem);
    vm.register_external_function(2, "bpf_map_update_elem", (void *)helper_bpf_map_update_elem);
    vm.register_external_function(5, "bpf_ktime_get_ns", (void *)helper_bpf_ktime_get_ns);
    vm.register_external_function(113, "bpf_probe_read_kernel", (void *)helper_bpf_probe_read_kernel);
    for (int id = 3; id <= 220; id++) {
        if (id == 5 || id == 113) {
            continue;
        }
        vm.register_external_function(id, "bpf_helper_" + std::to_string(id), (void *)helper_noop);
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
    if (options.dump_jit) {
        const auto dump_path = std::filesystem::path(benchmark_name_for_program(options.program) + ".llvmbpf.bin");
        write_binary_file(dump_path, compiled_code->data, compiled_code->size);
    }

    sample_result sample;
    sample.compile_ns = elapsed_ns(compile_start, compile_end);
    sample.opt_level = options.opt_level;
    sample.no_cmov = options.no_cmov;
    sample.native_code_size = compiled_code->size;
    sample.bpf_insn_count = image.code.size() / sizeof(ebpf_inst);
    sample.disabled_passes = options.disabled_passes;
    sample.code_size = {
        .bpf_bytecode_bytes = image.code.size(),
        .native_code_bytes = compiled_code->size,
    };
    if (options.compile_only) {
        sample.phases_ns = {
            {"program_image_ns", elapsed_ns(program_image_start, program_image_end)},
            {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
            {options.io_mode == "packet" ? "packet_prepare_ns"
                                         : (options.io_mode == "staged" ? "input_stage_ns" : "map_prepare_ns"),
             elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)},
            {"vm_load_code_ns", elapsed_ns(load_code_start, load_code_end)},
            {"jit_compile_ns", sample.compile_ns},
        };
        return sample;
    }

    uint64_t retval = 0;
    uint64_t result = 0;
    uint64_t total_exec_cycles = 0;
    const uint64_t tsc_freq_hz = detect_tsc_freq_hz();
    active_map_state = &map_state;
    clock_type::time_point exec_start {};
    clock_type::time_point exec_end {};
    const perf_counter_options perf_options = {
        .enabled = options.perf_counters,
        .include_kernel = false,
        .scope = options.perf_scope,
    };
    const auto run_map_repeat = [&](uint8_t *ctx, size_t ctx_size) {
        for (uint32_t index = 0; index < options.repeat; ++index) {
            const uint64_t cycle_start = rdtsc_start();
            if (vm.exec(ctx, ctx_size, retval) < 0) {
                fail("llvmbpf exec failed: " + vm.get_error_message());
            }
            total_exec_cycles += rdtsc_end() - cycle_start;
        }
    };
    const auto run_packet_repeat = [&](xdp_md_ctx &ctx) {
        for (uint32_t index = 0; index < options.repeat; ++index) {
            const uint64_t cycle_start = rdtsc_start();
            if (vm.exec(&ctx, sizeof(ctx), retval) < 0) {
                fail("llvmbpf exec failed: " + vm.get_error_message());
            }
            total_exec_cycles += rdtsc_end() - cycle_start;
        }
    };

    perf_counter_capture perf_counters;
    if (options.perf_scope == "full_repeat_avg") {
        exec_start = clock_type::now();
        if (options.io_mode == "map") {
            uint8_t dummy_ctx[8] = {};
            perf_counters = measure_perf_counters(perf_options, [&]() {
                run_map_repeat(dummy_ctx, sizeof(dummy_ctx));
            });
        } else {
            lowmem_buffer packet_buffer(packet_input.size());
            std::memcpy(packet_buffer.data(), packet_input.data(), packet_input.size());

            xdp_md_ctx ctx = {};
            const auto packet_address = reinterpret_cast<uintptr_t>(packet_buffer.data());
            ctx.data = static_cast<uint32_t>(packet_address);
            ctx.data_end = static_cast<uint32_t>(packet_address + packet_input.size());

            perf_counters = measure_perf_counters(perf_options, [&]() {
                run_packet_repeat(ctx);
            });
            result = read_u64_result(
                packet_buffer.data(),
                packet_buffer.size());
        }
        exec_end = clock_type::now();

        const uint32_t repeat = options.repeat > 0 ? options.repeat : 1;
        for (auto &counter : perf_counters.counters) {
            counter.value /= repeat;
        }
    } else {
        perf_counters = measure_perf_counters(
            perf_options,
            [&]() {
                exec_start = clock_type::now();
                if (options.io_mode == "map") {
                    uint8_t dummy_ctx[8] = {};
                    run_map_repeat(dummy_ctx, sizeof(dummy_ctx));
                } else {
                    lowmem_buffer packet_buffer(packet_input.size());
                    std::memcpy(packet_buffer.data(), packet_input.data(), packet_input.size());

                    xdp_md_ctx ctx = {};
                    const auto packet_address = reinterpret_cast<uintptr_t>(packet_buffer.data());
                    ctx.data = static_cast<uint32_t>(packet_address);
                    ctx.data_end = static_cast<uint32_t>(packet_address + packet_input.size());

                    run_packet_repeat(ctx);
                    result = read_u64_result(
                        packet_buffer.data(),
                        packet_buffer.size());
                }
                exec_end = clock_type::now();
            });
    }
    active_map_state = nullptr;

    sample.exec_ns = static_cast<uint64_t>(std::llround(
        (static_cast<long double>(total_exec_cycles) * 1000000000.0L) /
        (static_cast<long double>(tsc_freq_hz) * static_cast<long double>(options.repeat))));
    sample.wall_exec_ns = elapsed_ns(exec_start, exec_end) / options.repeat;
    sample.exec_cycles = static_cast<uint64_t>(std::llround(
        static_cast<long double>(total_exec_cycles) / static_cast<long double>(options.repeat)));
    sample.tsc_freq_hz = tsc_freq_hz;
    sample.timing_source = "rdtsc";
    sample.result = options.io_mode == "map" ? read_result_value(map_state) : result;
    sample.retval = static_cast<uint32_t>(retval);
    sample.phases_ns = {
        {"program_image_ns", elapsed_ns(program_image_start, program_image_end)},
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {options.io_mode == "packet" ? "packet_prepare_ns"
                                     : (options.io_mode == "staged" ? "input_stage_ns" : "map_prepare_ns"),
         elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)},
        {"vm_load_code_ns", elapsed_ns(load_code_start, load_code_end)},
        {"jit_compile_ns", sample.compile_ns},
    };
    sample.perf_counters = std::move(perf_counters);
    return sample;
}
