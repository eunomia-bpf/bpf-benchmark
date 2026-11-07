/* Real public loader -> kernel native-only queue; no native execution. */
#include "../libnativeloader/include/native_loader.hpp"
#include "../../kinsn/module/include/native_lab_trusted_wire.h"
#include <bpf/bpf.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <stdexcept>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <unistd.h>

static void require(bool ok, const char *what)
{
    if (!ok) throw std::runtime_error(std::string(what)+": "+std::strerror(errno));
}
static void refuses(const native_loader::FdLoadOptions &options, const char *expected)
{
    bool rejected = false;
    try {
        auto loaded = native_loader::load_from_fd(options);
        native_loader::close_loaded_program(&loaded);
    } catch (const std::exception &error) {
        rejected = std::string(error.what()).find(expected) != std::string::npos;
        if (!rejected) std::fprintf(stderr,"unexpected loader failure: %s\n",error.what());
    }
    require(rejected, expected);
    std::printf("%s: REJECTED\n", expected);
}
int main(int argc, char **argv)
{
    try {
        setbuf(stdout, nullptr);
        require(argc == 3, "native ELF and entry arguments");
        std::ifstream input(argv[1], std::ios::binary);
        require(bool(input), "read native source fixture");
        std::vector<unsigned char> native{std::istreambuf_iterator<char>(input), {}};
        require(!input.bad() && !native.empty(), "complete native source fixture");
        bpf_map_create_opts map_options{}; map_options.sz=sizeof(map_options);
        int first_map=bpf_map_create(BPF_MAP_TYPE_ARRAY,"same_name",4,8,1,&map_options);
        int second_map=bpf_map_create(BPF_MAP_TYPE_ARRAY,"same_name",4,8,1,&map_options);
        int known_map=bpf_map_create(BPF_MAP_TYPE_ARRAY,"source_data",4,40,1,&map_options);
        require(first_map>=0 && second_map>=0 && known_map>=0, "create same-name and resolvable source maps");
        bpf_map_info known_info{}; uint32_t known_size=sizeof(known_info);
        require(!bpf_obj_get_info_by_fd(known_map,&known_info,&known_size),"known source map identity");
        bpf_insn instructions[8]{};
        instructions[0].code=BPF_LD|BPF_DW|BPF_IMM; instructions[0].dst_reg=1;
        instructions[0].src_reg=BPF_PSEUDO_MAP_FD; instructions[0].imm=first_map;
        instructions[2].code=BPF_LD|BPF_DW|BPF_IMM; instructions[2].dst_reg=2;
        instructions[2].src_reg=BPF_PSEUDO_MAP_FD; instructions[2].imm=second_map;
        instructions[4].code=BPF_LD|BPF_DW|BPF_IMM; instructions[4].dst_reg=3;
        instructions[4].src_reg=BPF_PSEUDO_MAP_VALUE; instructions[4].imm=known_map;
        instructions[5].imm=8;
        instructions[6].code=BPF_ALU64|BPF_MOV|BPF_K; instructions[6].imm=2;
        instructions[7].code=BPF_JMP|BPF_EXIT;
        bpf_prog_load_opts load{}; load.sz=sizeof(load);
        int original=bpf_prog_load(BPF_PROG_TYPE_XDP, "client_source", "GPL", instructions, 8, &load);
        require(original>=0, "load original BPF source");
        bpf_prog_info info{}; uint32_t length=sizeof(info);
        require(!bpf_obj_get_info_by_fd(original, &info, &length) && info.nr_map_ids==3, "source program and all three map identities");
        require(!setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF", "1", 1) &&
            !setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_PREBUILT_PROOF", "1", 1), "select native-only trusted route");
        native_loader::FdLoadOptions options{};
        char manifest_path[]="/tmp/trusted-client-manifest.XXXXXX";
        int manifest_fd=mkstemp(manifest_path); require(manifest_fd>=0 && !close(manifest_fd), "create native manifest");
        std::ofstream manifest(manifest_path);
        manifest << "{\"objects\":[{\"program\":\"client_source\",\"native_object\":"
            << std::quoted(std::filesystem::absolute(argv[1]).string())
            << ",\"source_map_bindings\":[{\"native_symbol\":\"stats\",\"source_insn\":4}],"
            << "\"simulator_object\":\"/nonexistent/application-proof.bpf.o\",\"simulator_program\":\"app_proof\"}]}";
        manifest.close(); require(bool(manifest), "write native-only manifest with forbidden proof sibling");
        options.original_prog_fd=original; options.manifest_path=manifest_path; options.symbol_name=argv[2];
        options.source_insns.assign(std::begin(instructions), std::end(instructions));
        options.proof_insns.assign(std::begin(instructions), std::end(instructions));
        refuses(options, "applications submit native programs and cannot supply a proof");
        options.proof_insns.clear(); options.proof_object_path="/nonexistent/application-proof.o";
        refuses(options, "applications submit native programs and cannot supply a proof");
        options.proof_object_path.clear();
        const char *root="/sys/kernel/debug/bpf_x86_native_lab/";
        std::string submit_path=std::string(root)+"native_submit", service_path=std::string(root)+"specializer";
        int app_cap=open(submit_path.c_str(), O_RDWR|O_CLOEXEC); require(app_cap>=0, "open application endpoint");
        options.trusted_service_fd=app_cap; options.trusted_request_id=1;
        refuses(options, "trusted worker capability/request activation refused");
        require(!close(app_cap), "close forged worker capability");
        options.trusted_service_fd=-1; options.trusted_request_id=0;
        int ready[2]; require(!pipe(ready), "service ready pipe");
        pid_t child=fork(); require(child>=0, "fork isolated service control");
        if (!child) {
            try {
                int service=open(service_path.c_str(), O_RDWR|O_CLOEXEC); require(service>=0, "register test service");
                require(write(ready[1], "x", 1)==1, "announce registered service");
                native_lab_trusted_request request{}; request.version=NATIVE_LAB_TRUSTED_VERSION;
                require(ioctl(service, NATIVE_LAB_TRUSTED_NEXT, &request)==-1 && errno==EMSGSIZE,
                    "request capacity probe");
                std::vector<unsigned char> code(request.native_size), entry(request.entry_size), metadata(request.metadata_size);
                request.native_user=reinterpret_cast<uintptr_t>(code.data());
                request.entry_user=reinterpret_cast<uintptr_t>(entry.data());
                request.metadata_user=reinterpret_cast<uintptr_t>(metadata.data());
                require(!ioctl(service, NATIVE_LAB_TRUSTED_NEXT, &request), "receive actual loader native request");
                require(code==native && std::string(entry.begin(),entry.end())==argv[2] && request.source_prog_id==info.id,
                    "public loader submits exact native ELF/entry/kernel source");
                std::string json(metadata.begin(),metadata.end());
                require(json.find("\"load_context\":")!=std::string::npos && json.find("\"name\":\"stats\"")!=std::string::npos &&
                    json.find("\"map_id\":"+std::to_string(known_info.id))!=std::string::npos && json.find("same_name")==std::string::npos && json.find("source_data")==std::string::npos &&
                    json.find("\"value_offset\":8")!=std::string::npos &&
                    json.find("proof")==std::string::npos && json.find("path")==std::string::npos,
                    "public loader submits typed metadata without proof/path");
                native_lab_trusted_result result{}; result.request_id=request.request_id; result.status=-EACCES;
                require(!ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), "return actual controlled generation rejection");
                require(!close(service), "close test service");
                _exit(0);
            } catch (const std::exception &error) {
                std::fprintf(stderr,"service control: %s\n", error.what()); _exit(1);
            }
        }
        char marker; require(read(ready[0],&marker,1)==1, "await trusted service registration");
        refuses(options, (std::string("trusted specializer refused native program: ")+std::strerror(EACCES)).c_str());
        int status; require(waitpid(child,&status,0)==child && WIFEXITED(status) && !WEXITSTATUS(status), "service control result");
        require(!unlink(manifest_path), "remove temporary native manifest");
        require(!close(original) && !close(first_map) && !close(second_map) && !close(known_map), "close original program/maps");
        std::puts("ambiguous unused source map names cannot block a native-only submission: PASS");
        std::puts("public native-only loader: exact kernel request, proof/prebuilt separation, capability and failure propagation PASS");
        return 0;
    } catch (const std::exception &error) {
        std::fprintf(stderr,"trusted client: %s\n",error.what()); return 1;
    }
}
