#include "../../libnativeloader/include/native_loader.hpp"
#include <bpf/btf.h>
#include <bpf/bpf.h>
#include <linux/btf.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>

static unsigned long parameter(const char *name)
{
    std::ifstream input(std::string("/sys/module/native_load_fault_module/parameters/")+name);
    unsigned long value;
    if (!(input >> value)) throw std::runtime_error("read guest fixture result");
    return value;
}
int main(int argc,char **argv)
{
    native_loader::LoadedProgram loaded;
    try {
        if (argc < 3 || argc > 5) return 2;
        btf *vmlinux = btf__load_vmlinux_btf();
        if (!vmlinux) throw std::runtime_error("load guest BTF");
        int target = btf__find_by_name_kind(vmlinux,"bpf_lsm_file_open",BTF_KIND_FUNC);
        btf__free(vmlinux);
        if (target < 0) throw std::runtime_error("resolve file_open target");
        native_loader::FdLoadOptions options;
        bpf_prog_info context{};
        context.type=BPF_PROG_TYPE_LSM;context.gpl_compatible=1;
        context.attach_btf_id=target;
        options.native_context=context;
        options.expected_attach_type=BPF_LSM_MAC;options.attach_btf_id=target;
        options.native_object_path=argv[1];options.symbol_name=argc>=4?argv[3]:"entry";
#if defined(__aarch64__)
        options.native_link_path="/workspaces/repository/kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link";
#else
        options.native_link_path="/workspaces/repository/kprog/x86/native_lab/native_link/target/release/native-link";
#endif
        loaded=native_loader::load_from_fd(options);
        bpf_prog_info info{}; unsigned int info_size=sizeof(info);
        if (bpf_obj_get_info_by_fd(loaded.prog_fd,&info,&info_size))
            throw std::runtime_error("read guest program info");
        int module=open(argv[2],O_RDONLY);
        if (module<0) throw std::runtime_error("open guest fixture module");
        std::string args="prog_id="+std::to_string(loaded.native_prog_id);
        int result=syscall(SYS_finit_module,module,args.c_str(),0);close(module);
        if (result) throw std::runtime_error("load guest fixture module");
        unsigned long control=parameter("observed_control"),zero=parameter("observed_null");
        std::printf("{\"native_prog_id\":%u,\"attach_btf_id\":%d,\"verified_insns\":%u,\"extable_entries\":%lu,\"control\":%lu,\"null_result\":%lu}\n",
                    loaded.native_prog_id,target,info.verified_insns,parameter("extable_count"),control,zero);
        syscall(SYS_delete_module,"native_load_fault_module",0);
        native_loader::close_loaded_program(&loaded);
        unsigned long expected_null=argc==5?std::stoul(argv[4],nullptr,0):0;
        return control==0xffffffffUL && zero==expected_null ? 0 : 1;
    } catch (const std::exception &e) {
        native_loader::close_loaded_program(&loaded);
        std::fprintf(stderr,"native load guest fixture: %s\n",e.what());return 1;
    }
}
