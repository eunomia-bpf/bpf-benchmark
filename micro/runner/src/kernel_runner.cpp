#include "micro_exec.hpp"

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>

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

} // namespace

sample_result run_kernel(const cli_options &options)
{
    libbpf_set_print(libbpf_log);

    auto input_bytes = materialize_memory(options.memory, options.input_size);
    if (options.input_size != 0 && input_bytes.size() > options.input_size) {
        fail("input larger than kernel input map size");
    }
    if (options.input_size != 0 && input_bytes.size() < options.input_size) {
        input_bytes.resize(options.input_size, 0);
    }

    const auto compile_start = std::chrono::steady_clock::now();
    bpf_object_open_opts open_opts = {};
    open_opts.sz = sizeof(open_opts);
    bpf_object *raw_object = bpf_object__open_file(options.program.c_str(), &open_opts);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        fail("bpf_object__open_file failed: " + libbpf_error_string(open_error));
    }
    bpf_object_ptr object(raw_object);

    const int load_error = bpf_object__load(object.get());
    if (load_error != 0) {
        fail("bpf_object__load failed: " + libbpf_error_string(-load_error));
    }
    const auto compile_end = std::chrono::steady_clock::now();

    bpf_program *program = bpf_object__next_program(object.get(), nullptr);
    if (program == nullptr) {
        fail("no program found in object");
    }

    const int program_fd = bpf_program__fd(program);
    if (program_fd < 0) {
        fail("unable to obtain program fd");
    }

    bpf_map *input_map = bpf_object__find_map_by_name(object.get(), "input_map");
    bpf_map *result_map = bpf_object__find_map_by_name(object.get(), "result_map");
    if (input_map == nullptr || result_map == nullptr) {
        fail("required maps input_map/result_map not found");
    }

    const int input_fd = bpf_map__fd(input_map);
    const int result_fd = bpf_map__fd(result_map);
    if (input_fd < 0 || result_fd < 0) {
        fail("unable to obtain map fd");
    }

    const uint32_t key = 0;
    uint64_t zero = 0;
    if (bpf_map_update_elem(input_fd, &key, input_bytes.data(), BPF_ANY) != 0) {
        fail("bpf_map_update_elem(input_map) failed: " + std::string(strerror(errno)));
    }
    if (bpf_map_update_elem(result_fd, &key, &zero, BPF_ANY) != 0) {
        fail("bpf_map_update_elem(result_map) failed: " + std::string(strerror(errno)));
    }

    std::vector<uint8_t> packet(64, 0);
    std::vector<uint8_t> packet_out(packet.size(), 0);
    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    test_opts.repeat = options.repeat;
    test_opts.data_in = packet.data();
    test_opts.data_size_in = packet.size();
    test_opts.data_out = packet_out.data();
    test_opts.data_size_out = packet_out.size();

    const int run_error = bpf_prog_test_run_opts(program_fd, &test_opts);
    if (run_error != 0) {
        fail("bpf_prog_test_run_opts failed: " + std::string(strerror(errno)));
    }

    uint64_t result = 0;
    if (bpf_map_lookup_elem(result_fd, &key, &result) != 0) {
        fail("bpf_map_lookup_elem(result_map) failed: " + std::string(strerror(errno)));
    }

    sample_result sample;
    sample.compile_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(compile_end - compile_start).count();
    sample.exec_ns = test_opts.duration;
    sample.result = result;
    sample.retval = test_opts.retval;
    return sample;
}
