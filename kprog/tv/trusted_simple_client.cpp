/* Application sends native P only; service owns generation and proof loading. */
#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <array>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>

static void require(bool ok, const char *message) { if (!ok) throw std::runtime_error(message); }
static void run(int fd)
{
    for (unsigned length : {14u, 71u, 72u, 128u}) {
        std::array<unsigned char,128> input, output;
        input.fill(0x5a); output.fill(0);
        bpf_test_run_opts test{}; test.sz=sizeof(test);
        test.data_in=input.data(); test.data_size_in=length;
        test.data_out=output.data(); test.data_size_out=output.size(); test.repeat=1;
        require(!bpf_prog_test_run_opts(fd,&test),"simple TEST_RUN failed");
        require(test.retval==(length>=72?2u:0u) && test.data_size_out==length,"simple return/packet extent differs");
        auto expected=input;
        const unsigned char value[8]={0x4e,0x61,0xbc,0,0,0,0,0};
        if (length>=72) std::memcpy(expected.data(),value,8);
        require(!std::memcmp(output.data(),expected.data(),length),"simple stores/untouched packet bytes differ");
    }
}
int main(int argc, char **argv)
{
    native_loader::LoadedProgram loaded;
    try {
        require(argc==3,"original BPF and native ELF arguments required");
        std::unique_ptr<bpf_object,decltype(&bpf_object__close)> object(bpf_object__open_file(argv[1],nullptr),bpf_object__close);
        require(object && !libbpf_get_error(object.get()) && !bpf_object__load(object.get()),"load original simple BPF");
        auto *program=bpf_object__next_program(object.get(),nullptr);
        require(program && !bpf_object__next_program(object.get(),program),"single original simple entry required");
        require(!setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF","1",1) &&
            !setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF","1",1),"select trusted path");
        native_loader::FdLoadOptions options;
        options.original_prog_fd=bpf_program__fd(program); options.native_object_path=argv[2];
        options.symbol_name="simple_xdp"; options.expected_attach_type=bpf_program__expected_attach_type(program);
        options.prog_flags=bpf_program__flags(program);
        loaded=native_loader::load_from_fd(options);
        require(loaded.replaced && loaded.prog_fd>=0 && !loaded.prebuilt_proof,"fresh bound native result required");
        run(options.original_prog_fd); run(loaded.prog_fd);
        std::cout << "{\"ok\":true,\"original_prog_id\":" << loaded.original_prog_id
            << ",\"native_prog_id\":" << loaded.native_prog_id
            << ",\"retval\":2,\"prebuilt_proof\":false,\"packet_lengths\":[14,71,72,128],\"exact_packet_checks\":8}" << std::endl;
        native_loader::close_loaded_program(&loaded); return 0;
    } catch (const std::exception &error) {
        native_loader::close_loaded_program(&loaded); std::cerr << error.what() << std::endl; return 1;
    }
}
