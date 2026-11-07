/* Exercise the production manifest/loader/binding path; unsafe candidates are load-only. */
#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <stdexcept>
using Object=std::unique_ptr<bpf_object,decltype(&bpf_object__close)>;
#ifndef NATIVE_LINK_PATH
#define NATIVE_LINK_PATH "../x86/native_lab/native_link/target/release/native-link"
#endif
static Object open_original(const char *path)
{
    Object object(bpf_object__open_file(path,nullptr),bpf_object__close);
    if (!object) throw std::runtime_error("open companion BPF object failed");
    if (bpf_object__load(object.get())) throw std::runtime_error("load companion BPF object failed");
    return object;
}
static bpf_program *program(Object &object)
{
    bpf_program *p=bpf_object__next_program(object.get(),nullptr);
    if (!p || bpf_object__next_program(object.get(),p))
        throw std::runtime_error("fixture must have exactly one BPF program");
    return p;
}
static void check_result(int fd,uint64_t expected,uint32_t expected_retval,const char *runtime)
{
    unsigned char input[64]={},output[256]={};
    bpf_test_run_opts run{};
    run.sz=sizeof(run);run.data_in=input;run.data_size_in=sizeof(input);
    run.data_out=output;run.data_size_out=sizeof(output);run.repeat=1;
    if (bpf_prog_test_run_opts(fd,&run)) throw std::runtime_error("BPF_PROG_TEST_RUN failed: "+std::string(std::strerror(errno)));
    if (run.data_size_out<8) throw std::runtime_error("short packet result");
    uint64_t actual;
    std::memcpy(&actual,output,sizeof(actual));
    std::printf("%s result=%llu retval=%u expected_result=%llu expected_retval=%u\n",runtime,
        (unsigned long long)actual,run.retval,(unsigned long long)expected,expected_retval);
    if (actual!=expected || run.retval!=expected_retval) throw std::runtime_error("workload result mismatch");
}
int main(int argc,char **argv)
{
    if (argc!=3 && argc!=5) { std::fprintf(stderr,"usage: bound-probe SOURCE_BPF MANIFEST [EXPECTED_RESULT EXPECTED_RETVAL]\n");return 2; }
    try {
        uint64_t expected=0;uint32_t expected_retval=0;
        if (argc==5) {
            char *end;errno=0;expected=std::strtoull(argv[3],&end,0);
            if (errno || *end) throw std::runtime_error("invalid expected result");
            unsigned long value=std::strtoul(argv[4],&end,0);
            if (errno || *end || value>UINT32_MAX) throw std::runtime_error("invalid expected retval");
            expected_retval=value;
            auto baseline=open_original(argv[1]);
            check_result(bpf_program__fd(program(baseline)),expected,expected_retval,"kernel");
        }
        auto original=open_original(argv[1]);
        bpf_program *p=program(original);
        native_loader::FdLoadOptions options{};
        options.original_prog_fd=bpf_program__fd(p);
        options.expected_attach_type=bpf_program__expected_attach_type(p);
        options.prog_flags=bpf_program__flags(p);
        options.manifest_path=std::filesystem::absolute(argv[2]);
        /* Manifest selection needs the original source locally; it is not a proof. */
        options.source_insns.assign(bpf_program__insns(p),bpf_program__insns(p)+bpf_program__insn_cnt(p));
        options.native_link_path=std::filesystem::absolute(NATIVE_LINK_PATH);
        auto loaded=native_loader::load_from_fd(options);
        if (loaded.prog_fd<0 || !loaded.replaced) throw std::runtime_error("manifest did not produce a native program");
        if (loaded.prebuilt_proof) throw std::runtime_error("expected fresh trusted-service proof");
        bpf_prog_info info{};uint32_t size=sizeof(info);
        if (bpf_obj_get_info_by_fd(loaded.prog_fd,&info,&size)) throw std::runtime_error("bound program info failed");
        std::vector<bpf_insn> image(info.xlated_prog_len/sizeof(bpf_insn));
        if (image.empty() || image.size()*sizeof(bpf_insn)!=info.xlated_prog_len) throw std::runtime_error("invalid bound program length");
        info={};
        info.xlated_prog_len=image.size()*sizeof(bpf_insn);
        info.xlated_prog_insns=(uintptr_t)image.data();
        if (bpf_obj_get_info_by_fd(loaded.prog_fd,&info,&size)) throw std::runtime_error("bound program instructions failed: "+std::string(std::strerror(errno)));
        unsigned generations=0;
        for (const auto &insn:image) if (insn.code==(BPF_ALU64|BPF_MOV|BPF_K) && insn.src_reg==BPF_PSEUDO_KINSN_SIDECAR && insn.imm!=0) generations++;
        if (!generations) throw std::runtime_error("no nonzero-generation native sidecar in loaded program");
        std::printf("bound program id=%u chunks=%u nonzero_generations=%u\n",info.id,loaded.native_chunk_count,generations);
        if (argc==5) check_result(loaded.prog_fd,expected,expected_retval,"native_bound");
        native_loader::close_loaded_program(&loaded);
        if (std::fflush(stdout)) throw std::runtime_error("flush probe output failed");
    } catch (const std::exception &error) {
        std::fprintf(stderr,"bound-probe: %s\n",error.what());return 1;
    }
    return 0;
}
