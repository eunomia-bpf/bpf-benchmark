#include "../../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cerrno>
#include <algorithm>
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
    const std::string manifest=std::string(argv[4])+"/runtime-manifest.json";
    std::ofstream config(manifest);
    config << "{\"objects\":[{\"program\":\"entry\",\"symbol\":\"entry\",\"native_object\":"
           <<std::quoted(argv[2])<<",\"source_bpf_object\":"<<std::quoted(argv[1])<<"}]}";
    config.close();require(bool(config),"original-source map binding manifest");
    options.original_prog_fd=source;options.manifest_path=manifest;options.native_link_path=argv[3];
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
    auto execute=[&](unsigned long seed,unsigned prefix,unsigned expected,unsigned sample,unsigned state) {
        for(const auto &route:std::vector<std::pair<const char *,int>>{{"stock",source},{"native",native.prog_fd}}) {
            unsigned long ctx[2]={seed,prefix};
            bpf_test_run_opts run{};run.sz=sizeof(run);run.ctx_in=ctx;run.ctx_size_in=sizeof(ctx);
            int result=bpf_prog_test_run_opts(route.second,&run);
            output<<"{\"kind\":"<<kind<<",\"key_bytes\":"<<size<<",\"sample\":"<<sample
                  <<",\"state\":"<<state<<",\"query_prefix\":"<<prefix<<",\"route\":\""<<route.first<<"\",\"test_exit\":"<<result
                  <<",\"retval\":"<<run.retval<<",\"expected\":"<<expected<<"}"<<std::endl;
            require(bool(output)&&!result&&run.retval==expected,"stock/native value mismatch");++executions;
        }
    };
    if(kind==BPF_MAP_TYPE_LPM_TRIE) {
        const unsigned max=(size-4)*8;
        auto key_for=[&](unsigned seed,unsigned prefix) {
            std::vector<unsigned> key(size/4);key[0]=prefix;
            for(unsigned i=1;i<key.size();++i)key[i]=seed+i*0x1234567U;
            return key;
        };
        auto update=[&](unsigned seed,unsigned prefix,unsigned long value) {
            auto key=key_for(seed,prefix);require(!bpf_map_update_elem(fd,key.data(),&value,BPF_ANY),"LPM update");
        };
        auto erase=[&](unsigned seed,unsigned prefix) {
            auto key=key_for(seed,prefix);require(!bpf_map_delete_elem(fd,key.data()),"LPM delete");
        };
        std::vector<unsigned> prefixes={0,1,7,8,15,16,31,32,63,64,65,95,96,max,max+1};
        std::sort(prefixes.begin(),prefixes.end());prefixes.erase(std::unique(prefixes.begin(),prefixes.end()),prefixes.end());
        auto query=[&](unsigned state) {
            for(unsigned seed:std::vector<unsigned>{100,101,102,0,0xffff0000U})for(unsigned prefix:prefixes) {
                unsigned long expected=0;
                if(prefix<=max) {
                    auto key=key_for(seed,prefix);int result=bpf_map_lookup_elem(fd,key.data(),&expected);
                    require(!result||errno==ENOENT,"LPM syscall reference");if(result)expected=0;
                }
                execute(seed,prefix,expected,seed,state);
            }
        };
        query(0);update(0,0,111);query(1);
        update(100,16,222);update(100,max,333);update(101,max,444);update(102,max-1,555);query(2);
        update(100,max,999);update(0,0,112);query(3);
        erase(0,0);erase(100,16);query(4); /* Intermediate nodes are not values. */
        erase(100,max);erase(101,max);erase(102,max-1);query(5);
    } else for(unsigned sample=0;sample<32;++sample) {
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
            execute(seed,0,expected,sample,state);
        }
    }
    if(inner>=0)close(inner);
    native_loader::close_loaded_program(&native);bpf_object__close(object);
    std::printf("actual kernel map kind=%u key=%u: %u stock/native executions PASS\n",kind,size,executions);
    return 0;
} catch(const std::exception &e) { std::fprintf(stderr,"hash kernel: %s\n",e.what());return 1; }
