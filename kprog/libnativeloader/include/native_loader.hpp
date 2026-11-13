#ifndef NATIVE_LOADER_HPP
#define NATIVE_LOADER_HPP

#include <cstdint>
#include <chrono>
#include <filesystem>
#include <linux/bpf.h>
#include <optional>
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
    uint64_t source_context_ns = 0;
    uint64_t manifest_ns = 0;
    uint64_t companion_total_ns = 0;
    uint64_t data_symbols_ns = 0;
};

struct LoadedProgram {
    int prog_fd = -1;
    bool replaced = false;
    bool prebuilt_proof = false;
    uint32_t original_prog_id = 0;
    uint32_t native_prog_id = 0;
    uint64_t bpf_bytecode_bytes = 0;
    uint64_t native_code_bytes = 0;
    LoadTimings timings;
};

struct TrustedMapBinding {
    std::string native_symbol;
    uint32_t map_id = 0;
    std::optional<uint32_t> value_offset;
};

struct LoadDiagnostics {
    std::string log_path;
    std::chrono::steady_clock::time_point started;
};

struct FdLoadOptions {
    int original_prog_fd = -1;
    int trusted_service_fd = -1;
    uint64_t trusted_request_id = 0;
    std::filesystem::path trusted_native_proof_path;
    std::filesystem::path proof_object_path;
    std::string trusted_simulator_program;
    std::vector<TrustedMapBinding> trusted_maps;
    std::optional<bpf_prog_info> native_context;
    std::optional<bpf_func_info> native_entry_function;
    uint32_t source_btf_id = 0;
    uint32_t prog_flags = 0;
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
    LoadDiagnostics *diagnostics = nullptr;
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
