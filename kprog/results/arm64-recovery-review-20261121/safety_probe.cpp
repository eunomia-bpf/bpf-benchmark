/* Current common loader; negative inputs stay load-only. */
#include "../../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
int main(int argc,char **argv) {
    if(argc!=4)return 2;
    bpf_object *obj=nullptr;
    native_loader::LoadedProgram loaded;
    try {
        obj=bpf_object__open_file(argv[1],nullptr);
        if(!obj || libbpf_get_error(obj) || bpf_object__load(obj))
            throw std::runtime_error("load common XDP fixture context");
        auto *p=bpf_object__next_program(obj,nullptr);
        if(!p)throw std::runtime_error("find common XDP context");
        native_loader::FdLoadOptions options{};
        options.original_prog_fd=bpf_program__fd(p);
        options.expected_attach_type=bpf_program__expected_attach_type(p);
        options.source_insns.assign(bpf_program__insns(p),bpf_program__insns(p)+bpf_program__insn_cnt(p));
        options.native_object_path=argv[2];options.symbol_name="entry";
        options.native_link_path=std::getenv("BPFREJIT_NATIVE_LINK_BINARY");
        loaded=native_loader::load_from_fd(options);
        if(loaded.prog_fd<0)throw std::runtime_error("missing native program");
        std::printf("{\"native_prog_id\":%u",loaded.native_prog_id);
        if(std::string(argv[3])=="positive"){
            unsigned char data[64]={};
            bpf_test_run_opts run{};run.sz=sizeof(run);run.data_in=data;run.data_size_in=sizeof(data);run.repeat=1;
            if(bpf_prog_test_run_opts(loaded.prog_fd,&run))throw std::runtime_error("positive TEST_RUN");
            std::printf(",\"retval\":%u",run.retval);
            if(run.retval!=2)throw std::runtime_error("positive return differs");
        }
        std::puts("}");
        native_loader::close_loaded_program(&loaded);bpf_object__close(obj);return 0;
    }catch(const std::exception &e){
        std::fprintf(stderr,"safety-probe: %s\n",e.what());
        native_loader::close_loaded_program(&loaded);
        if(obj && !libbpf_get_error(obj))bpf_object__close(obj);
        return 1;
    }
}
