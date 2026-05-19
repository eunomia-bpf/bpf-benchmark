#include "bpf_helpers.hpp"

#include "micro_exec.hpp"

#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <string>

std::string libbpf_error_string(int error_code)
{
    char buffer[256] = {};
    libbpf_strerror(error_code, buffer, sizeof(buffer));
    return std::string(buffer);
}

bpf_prog_info load_prog_info(int program_fd)
{
    bpf_prog_info info = {};
    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd failed: " + libbpf_error_string(err));
    }
    return info;
}

std::vector<uint8_t> load_jited_program(
    int program_fd,
    uint32_t jited_prog_len,
    bool require_non_empty)
{
    if (jited_prog_len == 0) {
        if (require_non_empty) {
            fail("kernel reported an empty JIT image");
        }
        return {};
    }

    std::vector<uint8_t> jited_program(jited_prog_len);
    bpf_prog_info info = {};
    info.jited_prog_len = jited_prog_len;
    info.jited_prog_insns = ptr_to_u64(jited_program.data());

    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (JIT dump) failed: " + libbpf_error_string(err));
    }

    jited_program.resize(info.jited_prog_len);
    return jited_program;
}

std::vector<uint8_t> load_xlated_program(
    int program_fd,
    uint32_t xlated_prog_len,
    bool require_non_empty)
{
    if (xlated_prog_len == 0) {
        if (require_non_empty) {
            fail("kernel reported an empty xlated program");
        }
        return {};
    }

    std::vector<uint8_t> xlated(xlated_prog_len);
    bpf_prog_info info = {};
    info.xlated_prog_len = xlated_prog_len;
    info.xlated_prog_insns = ptr_to_u64(xlated.data());

    __u32 info_len = sizeof(info);
    const int err = bpf_obj_get_info_by_fd(program_fd, &info, &info_len);
    if (err != 0) {
        fail("bpf_obj_get_info_by_fd (xlated dump) failed: " + libbpf_error_string(err));
    }

    xlated.resize(info.xlated_prog_len);
    return xlated;
}

