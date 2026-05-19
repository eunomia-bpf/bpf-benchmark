#ifndef BPF_HELPERS_HPP
#define BPF_HELPERS_HPP

#include <linux/bpf.h>

#include <cstdint>
#include <string>
#include <vector>

template <typename T>
inline __u64 ptr_to_u64(T *ptr)
{
    return static_cast<__u64>(reinterpret_cast<uintptr_t>(ptr));
}

std::string libbpf_error_string(int error_code);
bpf_prog_info load_prog_info(int program_fd);
std::vector<uint8_t> load_jited_program(
    int program_fd,
    uint32_t jited_prog_len,
    bool require_non_empty = true);
std::vector<uint8_t> load_xlated_program(
    int program_fd,
    uint32_t xlated_prog_len,
    bool require_non_empty = true);

#endif
