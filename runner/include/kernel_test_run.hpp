// Internal helpers shared between run_kernel (libbpf-loaded .bpf.o path)
// and run_kernel_native_lab (debugfs-uploaded native blob path). Declared
// here so the duplicated logic that used to live in native_lab_runner.cpp
// is replaced by direct calls to the kernel_runner originals.
//
// This is an internal header used only by runner/src/*.cpp; it is NOT a
// public micro_exec API and is intentionally separate from micro_exec.hpp.

#ifndef KERNEL_TEST_RUN_HPP
#define KERNEL_TEST_RUN_HPP

#include "micro_exec.hpp"

#include <linux/bpf.h>
#include <cstdint>
#include <string_view>
#include <vector>

size_t packet_output_capacity(const cli_options &options, size_t packet_size);

std::vector<uint8_t> build_packet_input(
    const std::vector<uint8_t> &input_bytes, uint32_t prog_type);

// `result_fd = -1` is valid; it means "no result map" (native_lab path).
// For that case io_mode must be "packet" or "staged" and the result is
// pulled from packet_out[0..8].
uint64_t read_kernel_test_run_result(
    std::string_view effective_io_mode,
    bool result_from_skb_context,
    const std::vector<uint8_t> &packet_out,
    const __sk_buff &context_out,
    int result_fd,
    uint32_t key,
    uint32_t retval);

#endif // KERNEL_TEST_RUN_HPP
