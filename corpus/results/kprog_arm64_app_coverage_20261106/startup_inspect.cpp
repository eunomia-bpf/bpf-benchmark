/* Diagnose the actual loader-private libbpf view before and after prepare. */
#include <linux/bpf.h>
#include <cstdio>
#include <dlfcn.h>
#include <stdexcept>
#include <string>
struct bpf_object;
struct bpf_program;
template<class T> T symbol(void *library, const char *name)
{
    void *value=dlsym(library,name);
    if (!value) throw std::runtime_error(std::string("missing symbol ")+name);
    return reinterpret_cast<T>(value);
}
int main(int argc,char **argv)
{
    if (argc!=3) return 2;
    try {
        void *library=dlopen("/libnative_loader.so",RTLD_NOW|RTLD_LOCAL);
        if (!library) throw std::runtime_error(dlerror());
        auto open=symbol<bpf_object *(*)(const char *,const void *)>(library,"bpf_object__open_file");
        auto find=symbol<bpf_program *(*)(const bpf_object *,const char *)>(library,"bpf_object__find_program_by_name");
        auto prepare=symbol<int (*)(bpf_object *)>(library,"bpf_object__prepare");
        auto insns=symbol<const bpf_insn *(*)(const bpf_program *)>(library,"bpf_program__insns");
        auto count=symbol<size_t (*)(const bpf_program *)>(library,"bpf_program__insn_cnt");
        auto close=symbol<void (*)(bpf_object *)>(library,"bpf_object__close");
        bpf_object *object=open(argv[1],nullptr);
        if (!object) throw std::runtime_error("open failed");
        for (unsigned stage=0;stage<2;stage++) {
            bpf_program *program=find(object,argv[2]);
            if (!program) throw std::runtime_error("entry missing");
            const auto *code=insns(program);size_t n=count(program);
            if (!code || !n) throw std::runtime_error("empty proof");
            std::printf("stage=%u insns=%zu",stage,n);
            for (size_t i=0;i<n && i<16;i++) std::printf(" %zu:0x%x",i,code[i].code);
            std::puts("");
            if (!stage && prepare(object)) throw std::runtime_error("prepare failed");
        }
        close(object);
        if (dlclose(library)) throw std::runtime_error("dlclose failed");
    } catch (const std::exception &e) {std::fprintf(stderr,"%s\n",e.what());return 1;}
    return 0;
}
