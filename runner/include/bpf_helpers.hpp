#ifndef BPF_HELPERS_HPP
#define BPF_HELPERS_HPP

#include <linux/bpf.h>

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
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
std::string format_byte_dump(
    const std::vector<uint8_t> &bytes,
    size_t width,
    bool annotate_pc);
std::string program_name_from_info(const bpf_prog_info &info);
std::optional<enum bpf_prog_type> prog_type_from_string(
    const std::string &value);
std::string prog_type_name_from_enum(enum bpf_prog_type prog_type);

#endif
