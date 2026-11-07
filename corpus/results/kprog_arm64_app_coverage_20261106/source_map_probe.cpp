/* Exact captured upstream map-value probe: source, simulator and bound native. */
#include "../../../kprog/libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
static void require(bool value,const char *message) { if (!value) throw std::runtime_error(message); }
int main(int argc,char **argv)
{
    if (argc!=4 && argc!=5) return 2;
    try {
        std::ifstream source(argv[1],std::ios::binary);
        std::vector<char> bytes((std::istreambuf_iterator<char>(source)),{});
        require(!source.bad() && bytes.size()==40,"read captured five-instruction source");
        std::vector<bpf_insn> insns(bytes.size()/sizeof(bpf_insn));
        std::memcpy(insns.data(),bytes.data(),bytes.size());
        require(insns[0].code==0x18 && insns[0].src_reg==BPF_PSEUDO_MAP_VALUE && insns[1].imm==16,"exact source map-value identity");
        int map=bpf_map_create(BPF_MAP_TYPE_ARRAY,"libbpf_global",4,32,1,nullptr);
        require(map>=0,"create exact original map shape");
        unsigned key=0;unsigned char initial[32],expected[32],actual[32];
        std::memset(initial,0xa5,sizeof(initial));std::memcpy(expected,initial,sizeof(expected));
        uint64_t value=42;std::memcpy(expected+16,&value,8);
        require(bpf_map_update_elem(map,&key,initial,BPF_ANY)==0,"initialize original map");
        insns[0].imm=map;
        int original=bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER,nullptr,"GPL",insns.data(),insns.size(),nullptr);
        require(original>=0,"load exact captured source");
        native_loader::FdLoadOptions options{};options.original_prog_fd=original;
        options.source_insns=insns;options.manifest_path=argv[2];options.native_link_path="/native-link";
        auto native=native_loader::load_from_fd(options);
        require(native.prog_fd>=0 && native.replaced,"bind generated simulator and native");
        require(bpf_map_lookup_elem(map,&key,actual)==0 && std::memcmp(actual,initial,32)==0,"binding reset original map");
        bpf_prog_info info{};uint32_t size=sizeof(info);
        require(bpf_obj_get_info_by_fd(native.prog_fd,&info,&size)==0,"query bound native");
        std::vector<bpf_insn> image(info.xlated_prog_len/sizeof(bpf_insn));
        require(!image.empty(),"bound image empty");info={};info.xlated_prog_len=image.size()*sizeof(bpf_insn);info.xlated_prog_insns=(uintptr_t)image.data();
        require(bpf_obj_get_info_by_fd(native.prog_fd,&info,&size)==0,"read bound image");
        unsigned generations=0;
        for (const auto &i:image) if (i.code==0xb7 && i.src_reg==BPF_PSEUDO_KINSN_SIDECAR && i.imm) generations++;
        require(generations>0,"missing bound generation");
        for (int fd:{original,native.prog_fd}) {
            require(bpf_map_update_elem(map,&key,initial,BPF_ANY)==0,"reset exact comparison input");
            unsigned char packet[64]{};bpf_test_run_opts run{};run.sz=sizeof(run);run.data_in=packet;run.data_size_in=64;run.repeat=1;
            require(bpf_prog_test_run_opts(fd,&run)==0 && run.retval==0,"execute original/bound probe");
            require(bpf_map_lookup_elem(map,&key,actual)==0 && std::memcmp(actual,expected,32)==0,"map result or neighbors differ");
        }
        std::printf("source/bound value42 offset16 neighbors preserved; map not reset; nonzero_generations=%u\n",generations);
        native_loader::close_loaded_program(&native);
        options.manifest_path=argv[3];
        bool rejected=false;
        try {
            auto wrong=native_loader::load_from_fd(options);
            native_loader::close_loaded_program(&wrong);
        } catch (const std::exception &error) {
            std::printf("wrong-offset proof rejected: %s\n",error.what());
            rejected=std::strstr(error.what(),"BPF_PROG_LOAD native_lab stub:")!=nullptr;
        }
        require(rejected,"proof that erases source value offset accepted");
        if (argc==5) {
            options.manifest_path=argv[4];
            bool bytes_rejected=false;
            try {
                auto wrong=native_loader::load_from_fd(options);
                native_loader::close_loaded_program(&wrong);
            } catch (const std::exception &error) {
                std::printf("wrong-readonly proof rejected: %s\n",error.what());
                bytes_rejected=std::strstr(error.what(),"readonly proof data does not match native bytes")!=nullptr;
            }
            require(bytes_rejected,"proof with changed readonly bytes accepted");
        }
        require(close(original)==0 && close(map)==0,"close fixture resources");
    } catch (const std::exception &error) {std::fprintf(stderr,"source-map-probe: %s\n",error.what());return 1;}
    return 0;
}
