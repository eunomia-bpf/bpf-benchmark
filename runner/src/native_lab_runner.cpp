// Native-lab kernel runner.
//
// Mirrors run_kernel's measurement contract but delegates native linking,
// native blob upload, and native_lab stub loading to libnativeloader. The
// runner accepts only the Stage 2 form: a companion `.bpf.o` plus the matching
// `.native.o`. Pre-linked blob loading intentionally lives nowhere in the
// runner now, so native_kernel has a single load path shared with the shim.

#include "micro_exec.hpp"
#include "kernel_test_run.hpp"
#include "bpf_helpers.hpp"
#include "native_loader.hpp"

#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <errno.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace {

bool file_is_elf(const std::filesystem::path &path)
{
    std::ifstream f(path, std::ios::binary);
    if (!f) {
        return false;
    }
    char magic[4] = {};
    f.read(magic, sizeof(magic));
    return magic[0] == 0x7f && magic[1] == 'E' &&
           magic[2] == 'L' && magic[3] == 'F';
}

uint32_t prog_type_from_option(const std::string &name)
{
    if (name == "xdp") return BPF_PROG_TYPE_XDP;
    if (name == "sched_cls") return BPF_PROG_TYPE_SCHED_CLS;
    if (name == "cgroup_skb") return BPF_PROG_TYPE_CGROUP_SKB;
    fail("unsupported --native-kernel-prog-type: " + name);
}

struct object_deleter {
    void operator()(bpf_object *obj) const
    {
        if (obj != nullptr) {
            bpf_object__close(obj);
        }
    }
};

using bpf_object_ptr = std::unique_ptr<bpf_object, object_deleter>;

struct LoadedCompanion {
    bpf_object_ptr object;
    int program_fd = -1;
    std::vector<bpf_insn> source_insns;
    uint64_t open_ns = 0;
    uint64_t object_load_ns = 0;
};

LoadedCompanion load_native_companion_object(const std::filesystem::path &path)
{
    LoadedCompanion out{};
    const auto open_start = std::chrono::steady_clock::now();
    bpf_object *raw_object = bpf_object__open_file(path.c_str(), nullptr);
    const int open_error = libbpf_get_error(raw_object);
    if (open_error != 0) {
        fail("native_kernel companion bpf_object__open_file failed: " +
             libbpf_error_string(open_error));
    }
    out.object.reset(raw_object);
    const auto open_end = std::chrono::steady_clock::now();
    out.open_ns = elapsed_ns(open_start, open_end);

    bpf_program *entry_prog = nullptr;
    bpf_program *prog = nullptr;
    bpf_object__for_each_program(prog, out.object.get()) {
        if (entry_prog != nullptr) {
            fail("native_kernel companion .bpf.o has multiple BPF programs: " +
                 path.string());
        }
        entry_prog = prog;
    }
    if (entry_prog == nullptr) {
        fail("native_kernel companion .bpf.o has no BPF programs: " +
             path.string());
    }

    const auto load_start = std::chrono::steady_clock::now();
    const int load_error = bpf_object__load(out.object.get());
    if (load_error != 0) {
        fail("native_kernel companion bpf_object__load failed: " +
             libbpf_error_string(-load_error));
    }
    const auto load_end = std::chrono::steady_clock::now();
    out.object_load_ns = elapsed_ns(load_start, load_end);

    out.program_fd = bpf_program__fd(entry_prog);
    if (out.program_fd < 0) {
        fail("native_kernel companion entry program has no fd after load: " +
             path.string());
    }
    const bpf_insn *insns = bpf_program__insns(entry_prog);
    const size_t insn_count = bpf_program__insn_cnt(entry_prog);
    if (insns == nullptr || insn_count == 0) {
        fail("native_kernel companion entry program has no source instructions: " +
             path.string());
    }
    out.source_insns.assign(insns, insns + insn_count);
    return out;
}

} // namespace

std::vector<sample_result> run_native_kernel(const cli_options &options)
{
    const auto memory_prepare_start = std::chrono::steady_clock::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    if (options.input_size != 0 && input_bytes.size() < options.input_size) {
        input_bytes.resize(options.input_size, 0);
    }
    const auto memory_prepare_end = std::chrono::steady_clock::now();

    if (!file_is_elf(options.program)) {
        fail("native_kernel requires an ELF companion .bpf.o; pre-linked native blobs are no longer supported");
    }
    if (!options.native_program.has_value()) {
        fail("native_kernel requires --native-program");
    }

    const uint32_t prog_type_value =
        prog_type_from_option(options.native_kernel_prog_type);

    // Packet layout matches what kernel_runner builds for the same prog type
    // (8-byte result prefix for staged/packet xdp, ethernet prefix for
    // skb-context programs).
    const auto pkt_prepare_start = std::chrono::steady_clock::now();
    std::vector<uint8_t> packet = build_packet_input(input_bytes, prog_type_value);
    std::vector<uint8_t> packet_out(
        packet_output_capacity(options, packet.size()), 0);
    const auto pkt_prepare_end = std::chrono::steady_clock::now();

    const auto native_load_start = std::chrono::steady_clock::now();
    const auto image = load_program_image(options.program);
    const std::string &symbol = image.program_name;

    const auto companion_load_start = std::chrono::steady_clock::now();
    LoadedCompanion companion = load_native_companion_object(options.program);
    const auto companion_load_end = std::chrono::steady_clock::now();

    native_loader::FdLoadOptions load_options{
        .original_prog_fd = companion.program_fd,
        .manifest_path = {},
        .native_object_path = *options.native_program,
        .symbol_name = symbol,
        .source_bpf_path = {},
        .source_insns = companion.source_insns,
        .source_fd_array = {},
        .native_link_path = options.native_kernel_linker_path,
    };
    native_loader::LoadedProgram native_loaded =
        native_loader::load_from_fd(load_options);
    const auto native_load_end = std::chrono::steady_clock::now();

    int prog_fd = native_loaded.prog_fd;
    if (prog_fd < 0) {
        native_loader::close_loaded_program(&native_loaded);
        fail("native_kernel: native_loader returned no program fd");
    }

    const uint64_t native_load_ns =
        elapsed_ns(native_load_start, native_load_end);
    const uint64_t companion_load_ns =
        elapsed_ns(companion_load_start, companion_load_end);
    const uint64_t companion_open_ns = companion.open_ns;
    const uint64_t companion_object_load_ns = companion.object_load_ns;
    const uint64_t companion_map_ptr_extract_ns =
        native_loaded.timings.companion_map_ptr_extract_ns;
    const uint64_t companion_lookup_spec_ns =
        native_loaded.timings.companion_lookup_spec_ns;
    const uint64_t native_link_cache_lookup_ns =
        native_loaded.timings.cache_lookup_ns;
    const uint64_t native_link_exec_ns =
        native_loaded.timings.native_link_exec_ns;
    const uint64_t native_link_read_ns =
        native_loaded.timings.native_link_read_ns;
    const uint64_t native_link_map_patch_ns =
        native_loaded.timings.map_patch_ns;
    const uint64_t blob_upload_ns = native_loaded.timings.upload_ns;
    const uint64_t prog_load_ns = native_loaded.timings.prog_load_ns;
    const uint64_t bpf_bytecode_bytes =
        native_loaded.bpf_bytecode_bytes != 0
            ? native_loaded.bpf_bytecode_bytes
            : static_cast<uint64_t>(image.code.size());
    const uint64_t native_code_bytes = native_loaded.native_code_bytes;

    if (options.dump_jit || options.dump_jit_path.has_value()) {
        const bpf_prog_info prog_info = load_prog_info(prog_fd);
        const auto jited_program =
            load_jited_program(prog_fd, prog_info.jited_prog_len);
        const auto dump_path = options.dump_jit_path.value_or(
            std::filesystem::path(
                benchmark_name_for_program(options.program) + ".native_kernel.bin"));
        write_binary_file(dump_path, jited_program.data(), jited_program.size());
    }

    auto close_native_program = [&]() {
        if (prog_fd >= 0) {
            native_loader::close_loaded_program(&native_loaded);
            prog_fd = -1;
        }
    };

    const bool result_from_skb_context =
        prog_type_value == BPF_PROG_TYPE_SCHED_CLS ||
        prog_type_value == BPF_PROG_TYPE_CGROUP_SKB;
    __sk_buff context_out = {};

    // Warmup (1 iteration to populate caches + verify mechanism).
    bpf_test_run_opts warm = {};
    warm.sz = sizeof(warm);
    warm.repeat = 1;
    warm.data_in = packet.data();
    warm.data_size_in = packet.size();
    warm.data_out = packet_out.data();
    warm.data_size_out = packet_out.size();
    if (result_from_skb_context) {
        warm.ctx_out = &context_out;
        warm.ctx_size_out = sizeof(context_out);
    }
    if (bpf_prog_test_run_opts(prog_fd, &warm) < 0) {
        close_native_program();
        fail(std::string("warmup test_run failed: ") + std::strerror(errno));
    }

    // Measured run.
    std::fill(packet_out.begin(), packet_out.end(), 0);
    std::memset(&context_out, 0, sizeof(context_out));
    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    test_opts.repeat = options.repeat;
    test_opts.data_in = packet.data();
    test_opts.data_size_in = packet.size();
    test_opts.data_out = packet_out.data();
    test_opts.data_size_out = packet_out.size();
    if (result_from_skb_context) {
        test_opts.ctx_out = &context_out;
        test_opts.ctx_size_out = sizeof(context_out);
    }
    std::chrono::steady_clock::time_point run_start {};
    std::chrono::steady_clock::time_point run_end {};
    int run_err = 0;
    const perf_counter_options perf_options {
        .enabled = options.perf_counters,
        .include_kernel = true,
    };
    auto perf_counters = measure_perf_counters(perf_options, [&]() {
        run_start = std::chrono::steady_clock::now();
        run_err = bpf_prog_test_run_opts(prog_fd, &test_opts);
        run_end = std::chrono::steady_clock::now();
    });
    if (run_err) {
        close_native_program();
        fail(std::string("bpf_prog_test_run_opts failed: ") + std::strerror(errno));
    }

    uint64_t result_word = 0;
    if (result_from_skb_context) {
        result_word = static_cast<uint64_t>(context_out.cb[0]) |
                      (static_cast<uint64_t>(context_out.cb[1]) << 32);
    } else {
        if (packet_out.size() < sizeof(uint64_t)) {
            close_native_program();
            fail("native_kernel: packet_out too small to hold u64 result");
        }
        std::memcpy(&result_word, packet_out.data(), sizeof(result_word));
    }

    close_native_program();

    sample_result sample;
    sample.compile_ns = native_load_ns;
    sample.exec_ns = test_opts.duration;  // kernel reports per-iter ns
    sample.timing_source = "ktime";
    sample.timing_source_wall = "wall_steady";
    sample.wall_exec_ns = elapsed_ns(run_start, run_end);
    sample.result = result_word;
    sample.retval = test_opts.retval;
    sample.perf_counters = std::move(perf_counters);
    sample.code_size = {
        .bpf_bytecode_bytes = bpf_bytecode_bytes,
        .native_code_bytes = native_code_bytes,
    };
    sample.phases_ns = {
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {"packet_prepare_ns", elapsed_ns(pkt_prepare_start, pkt_prepare_end)},
        {"native_load_ns", native_load_ns},
        {"companion_load_ns", companion_load_ns},
        {"companion_open_ns", companion_open_ns},
        {"companion_object_load_ns", companion_object_load_ns},
        {"companion_map_ptr_extract_ns", companion_map_ptr_extract_ns},
        {"companion_lookup_spec_ns", companion_lookup_spec_ns},
        {"native_link_cache_lookup_ns", native_link_cache_lookup_ns},
        {"native_link_exec_ns", native_link_exec_ns},
        {"native_link_read_ns", native_link_read_ns},
        {"native_link_map_patch_ns", native_link_map_patch_ns},
        {"blob_upload_ns", blob_upload_ns},
        {"prog_load_ns", prog_load_ns},
        {"prog_run_wall_ns", elapsed_ns(run_start, run_end)},
    };
    return {std::move(sample)};
}
