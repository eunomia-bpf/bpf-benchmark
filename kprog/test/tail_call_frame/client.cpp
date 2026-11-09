#include "../../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <unistd.h>
int main(int argc,char **argv) {
    try {
        if(argc!=4&&argc!=5) throw std::runtime_error("client source.bpf.o native.o native-link [image]");
        auto *obj=bpf_object__open_file(argv[1],nullptr);
        if(libbpf_get_error(obj)||bpf_object__load(obj)) throw std::runtime_error("source load");
        auto *program=bpf_object__find_program_by_name(obj,"entry");
        int source=bpf_program__fd(program);
        int jumps=bpf_object__find_map_fd_by_name(obj,"tail_jumps");
        int counter=bpf_object__find_map_fd_by_name(obj,"tail_counter");
        native_loader::FdLoadOptions options;
        options.original_prog_fd=source;options.native_object_path=argv[2];options.symbol_name="entry";
        options.native_link_path=argv[3];
        bpf_map_info map_info{};__u32 map_size=sizeof(map_info);
        if(bpf_obj_get_info_by_fd(counter,&map_info,&map_size))throw std::runtime_error("counter info");
        options.trusted_maps.push_back({"tail_counter_value",map_info.id,0});

        options.source_insns.assign(bpf_program__insns(program),bpf_program__insns(program)+bpf_program__insn_cnt(program));
        setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF","1",1);
        auto native=native_loader::load_from_fd(options);
        if(!native.replaced||native.prog_fd<0)throw std::runtime_error("native load");
        bpf_prog_info info{};__u32 size=sizeof(info);
        if(bpf_obj_get_info_by_fd(native.prog_fd,&info,&size))throw std::runtime_error("native info");
        std::vector<unsigned char> image(info.jited_prog_len);
        info={};size=sizeof(info);info.jited_prog_len=image.size();
        info.jited_prog_insns=reinterpret_cast<__u64>(image.data());
        if(bpf_obj_get_info_by_fd(native.prog_fd,&info,&size))throw std::runtime_error("native image");
        if(argc==5) {
            FILE *output=std::fopen(argv[4],"wb");
            if(!output)throw std::runtime_error("image output");
            auto written=std::fwrite(image.data(),1,image.size(),output);
            auto closed=std::fclose(output);
            if(written!=image.size()||closed)throw std::runtime_error("image write");
        }
        int jit_depth=0,jit_pop=-1;
        for(size_t i=0;i+11<=image.size();i++) {
            if(image[i]==0x48&&image[i+1]==0x8b&&(image[i+2]==0x80||image[i+2]==0x85)&&
               image[i+7]==0x48&&image[i+8]==0x83&&image[i+9]==0x38&&image[i+10]==33) {
                int32_t disp;__builtin_memcpy(&disp,image.data()+i+3,4);jit_depth=-disp-16;
            }
        }
        for(size_t i=0;i+9<=image.size();i++) {
            if(image[i]==0x58&&image[i+1]==0x58&&image[i+2]==0x48&&image[i+3]==0x81&&image[i+4]==0xc4)
                __builtin_memcpy(&jit_pop,image.data()+i+5,4);
        }
        std::printf("{\"jit_stack_depth\":%d,\"jit_stack_pop\":%d}\n",jit_depth,jit_pop);
        if(jit_depth<=0||jit_pop!=jit_depth)throw std::runtime_error("stackful JIT frame");
        __u32 key=0;
        for(int fd:std::vector<int>{source,native.prog_fd}) {
            __u64 count=0;
            if(bpf_map_update_elem(counter,&key,&count,BPF_ANY)||bpf_map_update_elem(jumps,&key,&fd,BPF_ANY))throw std::runtime_error("map update");
            unsigned char packet[64]{};
            bpf_test_run_opts test{};test.sz=sizeof(test);test.data_in=packet;test.data_size_in=sizeof(packet);test.repeat=1;
            if(bpf_prog_test_run_opts(fd,&test)||bpf_map_lookup_elem(counter,&key,&count))throw std::runtime_error("test run");
            std::printf("{\"route\":\"%s\",\"retval\":%u,\"invocations\":%llu,\"tail_transfers\":%llu}\n",fd==source?"stock":"native",test.retval,(unsigned long long)count,(unsigned long long)(count-1));
            if(test.retval!=2||count!=34)throw std::runtime_error("tail count/result");
        }
        bpf_map_delete_elem(jumps,&key);
        native_loader::close_loaded_program(&native);bpf_object__close(obj);
    }catch(const std::exception &e){std::fprintf(stderr,"tail frame: %s\n",e.what());return 1;}
}
