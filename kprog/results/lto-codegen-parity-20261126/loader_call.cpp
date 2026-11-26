#include <cstdint>
#include <filesystem>
#include <iostream>
#include <string>

namespace native_loader::trusted {
std::filesystem::path native_context_lto_object(
    const std::filesystem::path &, const std::string &, uint32_t,
    const std::filesystem::path &, const std::filesystem::path &,
    const std::filesystem::path &, const std::string &, const std::string &,
    const std::string &);
}

int main(int argc, char **argv)
{
    if (argc != 4) return 2;
    std::cout << native_loader::trusted::native_context_lto_object(
        argv[1], "entry", 5, argv[2], "/sys/kernel/btf/vmlinux", argv[3],
        {}, "{}", {}).string() << '\n';
    return 0;
}
