#ifndef NATIVE_LOADER_HPP
#define NATIVE_LOADER_HPP

#include <cstdint>
#include <filesystem>
#include <linux/bpf.h>
#include <string>
#include <vector>

namespace native_loader {

struct LoadTimings {
    uint64_t companion_map_ptr_extract_ns = 0;
    uint64_t companion_lookup_spec_ns = 0;
    uint64_t cache_lookup_ns = 0;
    uint64_t native_link_exec_ns = 0;
    uint64_t native_link_read_ns = 0;
    uint64_t map_patch_ns = 0;
    uint64_t upload_ns = 0;
    uint64_t prog_load_ns = 0;
};

struct LoadedProgram {
    int prog_fd = -1;
    bool replaced = false;
    uint64_t bpf_bytecode_bytes = 0;
    uint64_t native_code_bytes = 0;
    LoadTimings timings;
};

struct FdLoadOptions {
    int original_prog_fd = -1;
    std::filesystem::path manifest_path;
    std::filesystem::path native_object_path;
    std::string symbol_name;
    std::filesystem::path source_bpf_path;
    std::vector<bpf_insn> source_insns;
    std::vector<int> source_fd_array;
    std::filesystem::path native_link_path;
    uint32_t expected_attach_type = 0;
    uint32_t attach_btf_id = 0;
    uint32_t attach_btf_obj_id = 0;
    uint32_t attach_prog_id = 0;
};

LoadedProgram load_from_fd(const FdLoadOptions &options);
void close_loaded_program(LoadedProgram *program);

} // namespace native_loader

extern "C" {

struct native_loader_c_result {
    int prog_fd;
    int replaced;
    char error[65536];
};

int native_loader_load_from_fd_with_manifest_path_and_attach(
    int original_prog_fd,
    const char *manifest_path,
    const char *source_bpf_path,
    const int *source_fd_array,
    uint32_t source_fd_array_count,
    uint32_t expected_attach_type,
    uint32_t attach_btf_id,
    uint32_t attach_btf_obj_id,
    uint32_t attach_prog_id,
    struct native_loader_c_result *out);

}

#endif
