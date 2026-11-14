#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

int main(int argc,char **argv) try {
    if (argc!=6) throw std::runtime_error("client source.bpf.o native.o linker xdp|tc|reject output.jsonl");
    const std::string mode=argv[4],entry=mode=="tc"?"packet_tc":"packet_xdp";
    auto *raw=bpf_object__open_file(argv[1],nullptr);
    if (!raw || libbpf_get_error(raw)) throw std::runtime_error("open source fixture");
    std::unique_ptr<bpf_object,decltype(&bpf_object__close)> object(raw,bpf_object__close);
    bpf_program *program;
    bpf_object__for_each_program(program,object.get())
        if (bpf_program__set_autoload(program,entry==bpf_program__name(program))) throw std::runtime_error("select source fixture");
    if (bpf_object__load(object.get())) throw std::runtime_error("load stock source fixture");
    program=bpf_object__find_program_by_name(object.get(),entry.c_str());
    if (!program) throw std::runtime_error("find source fixture");
    const int source=bpf_program__fd(program);
    if (setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF","1",1)) throw std::runtime_error("set bound route");
    native_loader::FdLoadOptions options;
    options.original_prog_fd=source;options.native_object_path=argv[2];options.native_link_path=argv[3];
    options.symbol_name=mode=="reject"?"packet_bad":entry;
    native_loader::LoadedProgram loaded;
    try { loaded=native_loader::load_from_fd(options); }
    catch (const std::runtime_error &error) {
        if (mode!="reject") throw;
        std::ofstream output(argv[5]); output<<"{\"expected_rejection\":true}\n";
        if (!output) throw std::runtime_error("write rejection receipt");
        std::cerr<<error.what()<<'\n';return 0;
    }
    std::unique_ptr<native_loader::LoadedProgram,void(*)(native_loader::LoadedProgram *)> owner(&loaded,native_loader::close_loaded_program);
    if (mode=="reject") throw std::runtime_error("unsafe candidate was accepted");
    if (!loaded.replaced || loaded.prog_fd<0) throw std::runtime_error("missing installed native program");
    std::ofstream output(argv[5]);
    for (unsigned a:mode=="tc"?std::vector<unsigned>{0,1,0x80000000,0xffffffff}:std::vector<unsigned>{63,64,65}) {
        for (unsigned b:mode=="tc"?std::vector<unsigned>{0,0xfedcba98}:std::vector<unsigned>{0,0x5a,0xff}) {
            __sk_buff context{};context.mark=a;context.priority=b;context.cb[0]=0xfedcba98;
            unsigned char packet[80];std::memset(packet,b,sizeof(packet));
            __sk_buff contexts[2]{};unsigned returns[2]{};
            for (unsigned route=0;route<2;++route) {
                bpf_test_run_opts test{};test.sz=sizeof(test);test.data_in=packet;test.data_size_in=mode=="tc"?64:a;test.repeat=1;
                if (mode=="tc") { test.ctx_in=&context;test.ctx_size_in=sizeof(context);test.ctx_out=&contexts[route];test.ctx_size_out=sizeof(contexts[route]); }
                if (bpf_prog_test_run_opts(route?loaded.prog_fd:source,&test)) throw std::runtime_error("actual stock/native TEST_RUN failed");
                returns[route]=test.retval;
            }
            if (returns[0]!=returns[1]) throw std::runtime_error("stock/native packet verdict differs");
            if (mode=="tc" && (contexts[0].mark!=contexts[1].mark || contexts[0].priority!=contexts[1].priority ||
                std::memcmp(contexts[0].cb,contexts[1].cb,sizeof(contexts[0].cb)))) throw std::runtime_error("stock/native context writes differ");
            output<<"{\"mode\":\""<<mode<<"\",\"a\":"<<a<<",\"b\":"<<b<<",\"stock\":"<<returns[0]<<",\"native\":"<<returns[1];
            if (mode=="tc") output<<",\"context_equal\":true";
            output<<"}\n";
        }
    }
    if (!output) throw std::runtime_error("write execution receipts");
    std::cout<<"actual "<<mode<<" stock/native packet execution PASS\n";
    return 0;
} catch (const std::exception &error) { std::cerr<<error.what()<<'\n';return 1; }
