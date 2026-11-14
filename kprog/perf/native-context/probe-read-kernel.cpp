#include "../../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <sys/mman.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

int main(int argc,char **argv)
try {
    if (argc!=5) throw std::runtime_error("client source.bpf.o native.o linker output");
    auto *object=bpf_object__open_file(argv[1],nullptr);
    if(libbpf_get_error(object)||bpf_object__load(object)) throw std::runtime_error("stock source load");
    auto *program=bpf_object__find_program_by_name(object,"entry");
    if(!program) throw std::runtime_error("stock entry missing");
    int source=bpf_program__fd(program);
    native_loader::FdLoadOptions options;
    options.original_prog_fd=source; options.native_object_path=argv[2];
    options.symbol_name="entry";options.native_link_path=argv[3];
    options.source_insns.assign(bpf_program__insns(program),bpf_program__insns(program)+bpf_program__insn_cnt(program));
    setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF","1",1);
    auto native=native_loader::load_from_fd(options);
    if(!native.replaced||native.prog_fd<0)throw std::runtime_error("registered native installation");
    auto *memory=static_cast<unsigned char *>(mmap(nullptr,8192,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0));
    if(memory==MAP_FAILED||mprotect(memory+4096,4096,PROT_NONE))throw std::runtime_error("guard pages");
    for(unsigned i=0;i<4096;++i) memory[i]=(i*17)^0x5a;
    struct Case {const char *name;unsigned long pointer,kind;unsigned expected;};
    unsigned sum=0;for(unsigned i=4080;i<4096;++i)sum+=memory[i];
    std::vector<Case> cases={
        {"user-valid",reinterpret_cast<unsigned long>(memory+4080),0,sum<<8},
        {"user-partial-fault",reinterpret_cast<unsigned long>(memory+4088),0,242},
        {"user-guard-fault",reinterpret_cast<unsigned long>(memory+4096),0,242},
        {"user-null",0,0,242},{"user-wrap",~0UL,0,242},
        {"kernel-stack",0,2,136<<8},
        {"kernel-denies-user",reinterpret_cast<unsigned long>(memory),1,222},
        {"kernel-denies-null",0,1,222},{"kernel-fault",~0UL,1,242}};
    std::ofstream output(std::string(argv[4])+"/execution.jsonl");
    if(!output)throw std::runtime_error("result file");
    for(const auto &item:cases) for(const auto &route:std::vector<std::pair<const char *,int>>{{"stock",source},{"native",native.prog_fd}}) {
        unsigned long ctx[2]={item.pointer,item.kind};
        bpf_test_run_opts run{};run.sz=sizeof(run);run.ctx_in=ctx;run.ctx_size_in=sizeof(ctx);
        int result=bpf_prog_test_run_opts(route.second,&run);
        output<<"{\"case\":\""<<item.name<<"\",\"route\":\""<<route.first
              <<"\",\"test_exit\":"<<result<<",\"retval\":"<<run.retval
              <<",\"expected\":"<<item.expected<<"}\n";output.flush();
        if(!output||result||run.retval!=item.expected)throw std::runtime_error(std::string(item.name)+" "+route.first+" mismatch");
    }
    native_loader::close_loaded_program(&native);bpf_object__close(object);
    std::puts("actual kernel stock/native probe-read: 18 executions PASS");
    return 0;
} catch(const std::exception &e) { std::fprintf(stderr,"probe-read kernel: %s\n",e.what());return 1; }
