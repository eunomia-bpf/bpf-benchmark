#include "micro_exec.hpp"

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
#include <fstream>
#include <memory>
#include <string>
#include <sys/syscall.h>
#include <thread>
#include <unistd.h>
#include <vector>

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

} // namespace

sample_result run_kernel(const cli_options &options)
{
    libbpf_set_print(libbpf_log);

    const auto memory_prepare_start = std::chrono::steady_clock::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    const auto memory_prepare_end = std::chrono::steady_clock::now();
    if (options.input_size != 0 && input_bytes.size() > options.input_size) {
        fail("input larger than kernel input map size");
    }
    if (options.input_size != 0 && input_bytes.size() < options.input_size) {
        input_bytes.resize(options.input_size, 0);
    }

    const auto object_open_start = std::chrono::steady_clock::now();
    bpf_object_open_opts open_opts = {};
    open_opts.sz = sizeof(open_opts);
    bpf_object *raw_object = bpf_object__open_file(options.program.c_str(), &open_opts);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        fail("bpf_object__open_file failed: " + libbpf_error_string(open_error));
    }
    const auto object_open_end = std::chrono::steady_clock::now();
    bpf_object_ptr object(raw_object);
    configure_autoload(object.get(), options.program_name);

    const auto object_load_start = std::chrono::steady_clock::now();
    const int load_error = bpf_object__load(object.get());
    if (load_error != 0) {
        fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
    }
    const auto object_load_end = std::chrono::steady_clock::now();

    bpf_program *program = find_program(object.get(), options.program_name);

    const int program_fd = bpf_program__fd(program);
    if (program_fd < 0) {
        fail("unable to obtain program fd");
    }

    const auto program_info = load_prog_info(program_fd);
    if (options.dump_jit) {
        const auto jited_program = load_jited_program(program_fd, program_info.jited_prog_len);
        const auto dump_path = std::filesystem::path(benchmark_name_for_program(options.program) + ".kernel.bin");
        write_binary_file(dump_path, jited_program.data(), jited_program.size());
    }

    sample_result sample;
    sample.compile_ns = elapsed_ns(object_open_start, object_open_end) + elapsed_ns(object_load_start, object_load_end);
    sample.jited_prog_len = program_info.jited_prog_len;
    sample.xlated_prog_len = program_info.xlated_prog_len;
    sample.code_size = {
        .bpf_bytecode_bytes = program_info.xlated_prog_len,
        .native_code_bytes = program_info.jited_prog_len,
    };
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
    uint64_t result = 0;
    int result_fd = -1;
    uint32_t key = 0;

    if (options.io_mode == "map") {
        bpf_map *input_map = bpf_object__find_map_by_name(object.get(), "input_map");
        bpf_map *result_map = bpf_object__find_map_by_name(object.get(), "result_map");
        if (input_map == nullptr || result_map == nullptr) {
            fail("required maps input_map/result_map not found");
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
    } else if (options.io_mode == "staged") {
        bpf_map *input_map = bpf_object__find_map_by_name(object.get(), "input_map");
        if (input_map == nullptr) {
            fail("required map input_map not found");
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
        exec_input_prepare_start = std::chrono::steady_clock::now();
        packet = build_packet_input(input_bytes);
        packet_out.assign(packet.size(), 0);
        exec_input_prepare_end = std::chrono::steady_clock::now();
    }

    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    test_opts.repeat = options.repeat;
    test_opts.data_in = packet.data();
    test_opts.data_size_in = packet.size();
    test_opts.data_out = packet_out.data();
    test_opts.data_size_out = packet_out.size();

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
        const uint32_t repeat = options.repeat > 0 ? options.repeat : 1;
        for (auto &counter : perf_counters.counters) {
            counter.value /= repeat;
        }
    }
    if (run_error != 0) {
        fail("bpf_prog_test_run_opts failed: " + std::string(strerror(errno)));
    }

    if (options.io_mode == "packet" || options.io_mode == "staged") {
        result_read_start = std::chrono::steady_clock::now();
        result = read_u64_result(packet_out.data(), packet_out.size());
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
        const uint32_t repeat = options.repeat > 0 ? options.repeat : 1;
        sample.exec_cycles = static_cast<uint64_t>(std::llround(
            static_cast<long double>(total_cycles) / static_cast<long double>(repeat)));
        sample.tsc_freq_hz = tsc_freq_hz;
        sample.wall_exec_ns = static_cast<uint64_t>(std::llround(
            (static_cast<long double>(total_cycles) * 1000000000.0L) /
            (static_cast<long double>(tsc_freq_hz) * static_cast<long double>(repeat))));
    }
    sample.timing_source = "ktime";
    sample.result = result;
    sample.retval = test_opts.retval;
    sample.phases_ns = {
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {"object_open_ns", elapsed_ns(object_open_start, object_open_end)},
        {"object_load_ns", elapsed_ns(object_load_start, object_load_end)},
        {options.io_mode == "packet" ? "packet_prepare_ns"
                                     : (options.io_mode == "staged" ? "input_stage_ns" : "map_prepare_ns"),
         elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)},
        {"prog_run_wall_ns", elapsed_ns(run_wall_start, run_wall_end)},
        {(options.io_mode == "packet" || options.io_mode == "staged") ? "result_extract_ns" : "result_read_ns",
         elapsed_ns(result_read_start, result_read_end)},
    };
    sample.perf_counters = std::move(perf_counters);
    return sample;
}
