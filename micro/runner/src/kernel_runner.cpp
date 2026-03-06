#include "micro_exec.hpp"

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

namespace {

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

    const auto object_load_start = std::chrono::steady_clock::now();
    const int load_error = bpf_object__load(object.get());
    if (load_error != 0) {
        fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
    }
    const auto object_load_end = std::chrono::steady_clock::now();

    bpf_program *program = bpf_object__next_program(object.get(), nullptr);
    if (program == nullptr) {
        fail("no program found in object");
    }

    const int program_fd = bpf_program__fd(program);
    if (program_fd < 0) {
        fail("unable to obtain program fd");
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

    std::chrono::steady_clock::time_point run_wall_start {};
    std::chrono::steady_clock::time_point run_wall_end {};
    int run_error = 0;
    auto perf_counters = measure_perf_counters(
        {.enabled = options.perf_counters, .include_kernel = true, .scope = "exec_window"},
        [&]() {
            run_wall_start = std::chrono::steady_clock::now();
            run_error = bpf_prog_test_run_opts(program_fd, &test_opts);
            run_wall_end = std::chrono::steady_clock::now();
        });
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

    sample_result sample;
    sample.compile_ns = elapsed_ns(object_open_start, object_open_end) + elapsed_ns(object_load_start, object_load_end);
    sample.exec_ns = test_opts.duration;
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
