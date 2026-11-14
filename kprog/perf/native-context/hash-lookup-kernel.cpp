#include "../../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <unistd.h>
static void require(bool ok,const char *what) { if(!ok)throw std::runtime_error(what); }
int main(int argc,char **argv)
try {
    require(argc==5,"client source.bpf.o native.o linker output");
    auto *object=bpf_object__open_file(argv[1],nullptr);
    require(!libbpf_get_error(object)&&!bpf_object__load(object),"stock source load");
    auto *program=bpf_object__find_program_by_name(object,"entry");require(program,"entry missing");
    auto *map=bpf_object__find_map_by_name(object,"table");require(map,"table missing");
    int source=bpf_program__fd(program),fd=bpf_map__fd(map);
    unsigned size=bpf_map__key_size(map),kind=bpf_map__type(map);
    require(size%4==0 && size<=20,"fixture key size");
    native_loader::FdLoadOptions options;
    options.original_prog_fd=source;options.native_object_path=argv[2];options.symbol_name="entry";options.native_link_path=argv[3];
    bpf_map_info info{};unsigned info_size=sizeof(info);
    require(!bpf_obj_get_info_by_fd(fd,&info,&info_size),"actual table identity");
    options.trusted_maps.push_back({"table",info.id,std::nullopt});
    options.source_insns.assign(bpf_program__insns(program),bpf_program__insns(program)+bpf_program__insn_cnt(program));
    setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF","1",1);
    auto native=native_loader::load_from_fd(options);
    require(native.replaced&&native.prog_fd>=0,"registered native installation");
    int inner=-1;
    if(kind==BPF_MAP_TYPE_HASH_OF_MAPS) {
        inner=bpf_map_create(BPF_MAP_TYPE_ARRAY,"live_inner",4,8,1,nullptr);require(inner>=0,"inner create");
    }
    int cpus=libbpf_num_possible_cpus();require(cpus>0,"possible CPUs");
    bool percpu=kind==BPF_MAP_TYPE_PERCPU_HASH||kind==BPF_MAP_TYPE_LRU_PERCPU_HASH;
    std::ofstream output(std::string(argv[4])+"/execution.jsonl");require(bool(output),"result file");
    unsigned executions=0;
    for(unsigned sample=0;sample<32;++sample) {
        unsigned long seed=sample*0x91abcU+17;std::vector<unsigned> key(size/4);
        for(unsigned i=0;i<key.size();++i)key[i]=seed+i*0x1234567U;
        for(unsigned state=0;state<4;++state) {
            unsigned expected=state==0||state==3 ? 0 : sample*17+state+31;
            if(state==1||state==2) {
                std::vector<unsigned long> values(percpu?cpus:1,expected);
                if(inner>=0) {
                    unsigned zero=0;require(!bpf_map_update_elem(inner,&zero,values.data(),BPF_ANY),"inner update");
                    require(!bpf_map_update_elem(fd,key.data(),&inner,BPF_ANY),"outer update");
                } else require(!bpf_map_update_elem(fd,key.data(),values.data(),BPF_ANY),"live update");
            } else if(state==3)require(!bpf_map_delete_elem(fd,key.data()),"live delete");
            for(const auto &route:std::vector<std::pair<const char *,int>>{{"stock",source},{"native",native.prog_fd}}) {
                bpf_test_run_opts run{};run.sz=sizeof(run);run.ctx_in=&seed;run.ctx_size_in=sizeof(seed);
                int result=bpf_prog_test_run_opts(route.second,&run);
                output<<"{\"kind\":"<<kind<<",\"key_bytes\":"<<size<<",\"sample\":"<<sample
                      <<",\"state\":"<<state<<",\"route\":\""<<route.first<<"\",\"test_exit\":"<<result
                      <<",\"retval\":"<<run.retval<<",\"expected\":"<<expected<<"}\n";
                output.flush();require(bool(output)&&!result&&run.retval==expected,"stock/native value mismatch");++executions;
            }
        }
    }
    if(inner>=0)close(inner);
    native_loader::close_loaded_program(&native);bpf_object__close(object);
    std::printf("actual kernel hash kind=%u key=%u: %u stock/native executions PASS\n",kind,size,executions);
    return 0;
} catch(const std::exception &e) { std::fprintf(stderr,"hash kernel: %s\n",e.what());return 1; }
