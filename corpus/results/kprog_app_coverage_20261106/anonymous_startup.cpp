/* Real anonymous/name-collision libbpf loads; inspect and run the installed FD. */
#include <bpf/bpf.h>
#include <linux/bpf.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>
#include <unistd.h>
int main(int argc,char **argv) {
    if(argc!=3 && argc!=4)return 2;
    char *end;errno=0;unsigned long expected=std::strtoul(argv[2],&end,0);
    if(errno || *end || expected>UINT32_MAX)return 2;
    std::ifstream file(argv[1],std::ios::binary);
    if(!file){std::fprintf(stderr,"open source failed\n");return 1;}
    std::vector<char> bytes((std::istreambuf_iterator<char>(file)),{});
    if(file.bad() || bytes.empty() || bytes.size()%sizeof(bpf_insn))return 2;
    std::vector<bpf_insn> code(bytes.size()/sizeof(bpf_insn));
    std::memcpy(code.data(),bytes.data(),bytes.size());
    std::vector<char> log(1024*1024);
    bpf_prog_load_opts load{};load.sz=sizeof(load);
    load.log_buf=log.data();load.log_size=log.size();load.log_level=1;
    int source=bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER,argc==4?argv[3]:nullptr,
        "GPL",code.data(),code.size(),&load);
    if(source<0){std::fprintf(stderr,"source load: %s\n%s\n",std::strerror(errno),log.data());return 1;}
    int fd=dup(source);
    if(fd<0){std::fprintf(stderr,"dup source: %s\n",std::strerror(errno));return 1;}
    bpf_prog_info info{};__u32 size=sizeof(info);
    if(bpf_obj_get_info_by_fd(fd,&info,&size)){std::fprintf(stderr,"program info: %s\n",std::strerror(errno));return 1;}
    std::vector<bpf_insn> image(info.xlated_prog_len/sizeof(bpf_insn));
    info={};
    info.xlated_prog_len=image.size()*sizeof(bpf_insn);
    info.xlated_prog_insns=(uintptr_t)image.data();
    if(bpf_obj_get_info_by_fd(fd,&info,&size)){std::fprintf(stderr,"program image: %s\n",std::strerror(errno));return 1;}
    unsigned generations=0;
    for(auto insn:image)
        if(insn.code==(BPF_ALU64|BPF_MOV|BPF_K) &&
            insn.src_reg==BPF_PSEUDO_KINSN_SIDECAR && insn.imm)generations++;
    unsigned char packet[64]{};
    bpf_test_run_opts run{};run.sz=sizeof(run);run.data_in=packet;run.data_size_in=sizeof(packet);run.repeat=1;
    if(bpf_prog_test_run_opts(fd,&run)){std::fprintf(stderr,"test run: %s\n",std::strerror(errno));return 1;}
    std::printf("id=%u type=%u nonzero_generations=%u invocations=1 retval=%u expected=%lu\n",
        info.id,info.type,generations,run.retval,expected);
    if(close(fd)||close(source))return 1;
    return generations && run.retval==expected?0:9;
}
