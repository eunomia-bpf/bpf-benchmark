// Reproduce the typed pointer AND and run the repaired CFG's map/null/stack arms.
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <array>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

static void write_file(const std::string &path, const char *data)
{
    std::ofstream output;
    output.exceptions(std::ios::failbit | std::ios::badbit);
    output.open(path);
    output << data;
}

static auto open_object(const char *path, std::vector<char> &log)
{
    bpf_object_open_opts options{};
    options.sz = sizeof(options);
    options.kernel_log_buf = log.data();
    options.kernel_log_size = log.size();
    options.kernel_log_level = 1;
    auto *raw = bpf_object__open_file(path, &options);
    if (libbpf_get_error(raw)) throw std::runtime_error("open BPF fixture failed");
    return std::unique_ptr<bpf_object, decltype(&bpf_object__close)>(raw, bpf_object__close);
}

int main(int argc, char **argv)
{
    try {
        if (argc != 4) throw std::runtime_error("usage: self-compare BEFORE AFTER OUTPUT");
        std::vector<char> log(1024 * 1024);
        auto before = open_object(argv[1], log);
        int status = bpf_object__load(before.get());
        write_file(std::string(argv[3])+"/before-verifier.log", log.data());
        if (status == 0 || !std::strstr(log.data(), "pointer &= pointer prohibited"))
            throw std::runtime_error("before fixture did not reproduce typed pointer AND refusal");
        log.assign(log.size(), 0);
        auto after = open_object(argv[2], log);
        status = bpf_object__load(after.get());
        write_file(std::string(argv[3])+"/after-verifier.log", log.data());
        if (status) throw std::runtime_error("repaired fixture stock load failed");
        auto *program = bpf_object__next_program(after.get(), nullptr);
        int fd = bpf_program__fd(program);
        int map = bpf_object__find_map_fd_by_name(after.get(), "values");
        if (map < 0) throw std::runtime_error("fixture values map missing");
        unsigned key = 0, cases = 0;
        auto run = [&](unsigned mark, unsigned expected) {
            std::array<unsigned char, 64> packet{};
            __sk_buff ctx{};
            ctx.mark = mark;
            bpf_test_run_opts test{};
            test.sz = sizeof(test);
            test.data_in = packet.data();
            test.data_size_in = packet.size();
            test.ctx_in = &ctx;
            test.ctx_size_in = sizeof(ctx);
            if (bpf_prog_test_run_opts(fd, &test)) throw std::runtime_error("socket fixture TEST_RUN failed");
            if (test.retval != expected) throw std::runtime_error("socket fixture result mismatch");
            ++cases;
        };
        for (__u64 value : {7ULL, 19ULL, 0ULL}) {
            if (bpf_map_update_elem(map, &key, &value, BPF_ANY)) throw std::runtime_error("fixture map update failed");
            run(0, 0);
            run(1, value);
        }
        if (bpf_map_delete_elem(map, &key)) throw std::runtime_error("fixture map delete failed");
        run(1, 0);
        run(0, 0);
        std::string result = "{\"before_pointer_and_rejected\":true,\"after_verified\":true,\"execution_cases\":"+std::to_string(cases)+"}\n";
        write_file(std::string(argv[3])+"/result.json", result.c_str());
        std::cout << result;
        return 0;
    } catch (const std::exception &error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
