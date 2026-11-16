#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 5) return 2;
    const std::filesystem::path input = argv[1], compiler = argv[2], kernel = argv[3], cache = argv[4];
    const auto output = native_perf_context_object(input, "perf_entry", BPF_PROG_TYPE_PERF_EVENT,
                                                  compiler, kernel, cache);
    const auto before = std::filesystem::last_write_time(output);
    const auto reused = native_perf_context_object(input, "perf_entry", BPF_PROG_TYPE_PERF_EVENT,
                                                  compiler, kernel, cache);
    if (reused != output || std::filesystem::last_write_time(output) != before)
        throw std::runtime_error("unchanged context LTO input was rebuilt");
    if (native_perf_context_object(input, "perf_entry", BPF_PROG_TYPE_KPROBE,
                                    "/missing/compiler", "/missing/btf", cache) != input)
        throw std::runtime_error("non-perf program changed");
    std::cout << output.string() << '\n';
}
