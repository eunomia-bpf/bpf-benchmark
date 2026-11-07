#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <unistd.h>

int main(int argc, char **argv)
{
    int source = -1;
    native_loader::LoadedProgram loaded;
    try {
        if (argc != 2) throw std::runtime_error("native ELF argument required");
        bpf_insn code[2]{};
        code[0].code = BPF_ALU64 | BPF_MOV | BPF_K; code[0].imm = 2;
        code[1].code = BPF_JMP | BPF_EXIT;
        bpf_prog_load_opts opts{}; opts.sz = sizeof(opts);
        source = bpf_prog_load(BPF_PROG_TYPE_XDP,"service_source","GPL",code,2,&opts);
        if (source < 0) throw std::runtime_error("load original BPF control");
        if (setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF","1",1) ||
            setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF","1",1))
            throw std::runtime_error("set trusted route");
        native_loader::FdLoadOptions options;
        options.original_prog_fd = source; options.native_object_path = argv[1];
        options.symbol_name = "trusted_entry";
        loaded = native_loader::load_from_fd(options);
        if (!loaded.replaced || loaded.prog_fd < 0 || !loaded.native_prog_id || loaded.prebuilt_proof)
            throw std::runtime_error("result must be freshly generated bound native");
        unsigned char packet[64]{};
        bpf_test_run_opts test{}; test.sz = sizeof(test);
        test.data_in = packet; test.data_size_in = sizeof(packet); test.repeat = 1;
        if (bpf_prog_test_run_opts(loaded.prog_fd,&test) || test.retval != 2)
            throw std::runtime_error("actual bound native TEST_RUN did not return 2");
        std::cout << "{\"ok\":true,\"original_prog_id\":" << loaded.original_prog_id
            << ",\"native_prog_id\":" << loaded.native_prog_id
            << ",\"retval\":" << test.retval << ",\"prebuilt_proof\":false}" << std::endl;
        native_loader::close_loaded_program(&loaded); close(source);
        return 0;
    } catch (const std::exception &e) {
        native_loader::close_loaded_program(&loaded);
        if (source >= 0) close(source);
        std::cerr << "trusted service control: " << e.what() << std::endl;
        return 1;
    }
}
