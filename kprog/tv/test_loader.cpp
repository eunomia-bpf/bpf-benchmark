#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <cassert>
#include <cstdio>
#include <exception>
#include <unistd.h>

int main()
{
    const std::vector<bpf_insn> proof{
        {.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 0,
         .src_reg = 0, .off = 0, .imm = 2},
        {.code = BPF_JMP | BPF_EXIT, .dst_reg = 0,
         .src_reg = 0, .off = 0, .imm = 0},
    };
    int original = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_loader", "GPL",
                                 proof.data(), proof.size(), nullptr);
    if (original < 0) {
        std::perror("original BPF load");
        return 1;
    }
    try {
        for (const char *symbol : {"tv_short_entry", "tv_long_entry"}) {
            native_loader::FdLoadOptions options{};
            options.original_prog_fd = original;
            options.native_object_path = std::filesystem::absolute("build/native-entry.o");
            options.symbol_name = symbol;
            options.source_insns = proof;
            options.proof_insns = proof;
            options.native_link_path = std::filesystem::absolute(
                "../x86/native_lab/native_link/target/release/native-link");
            auto loaded = native_loader::load_from_fd(options);
            assert(loaded.prog_fd >= 0);
            assert(loaded.native_chunk_count > 0);
            if (options.symbol_name == "tv_long_entry")
                assert(loaded.native_chunk_count > 1);
            unsigned char packet[64] = {};
            bpf_test_run_opts run{};
            run.sz = sizeof(run);
            run.data_in = packet;
            run.data_size_in = sizeof(packet);
            run.repeat = 1;
            if (bpf_prog_test_run_opts(loaded.prog_fd, &run)) {
                std::perror("bound loader test run");
                return 1;
            }
            assert(run.retval == 2);
            std::printf("shared loader %s: PASS (%u chunks, native returned 2)\n",
                        symbol, loaded.native_chunk_count);
            native_loader::close_loaded_program(&loaded);
        }
    } catch (const std::exception &error) {
        std::fprintf(stderr, "shared loader: %s\n", error.what());
        return 1;
    }
    if (close(original)) {
        std::perror("close original");
        return 1;
    }
    return 0;
}
