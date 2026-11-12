// Regression: REQUIRE_BOUND_PROOF must submit P and propagate service rejection.
#include "../libnativeloader/include/native_loader.hpp"
#include "../../kinsn/module/include/native_lab_trusted_wire.h"
#include <bpf/bpf.h>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <unistd.h>

static void require(bool value, const char *message)
{
    if (!value) throw std::runtime_error(message);
}

int main(int argc, char **argv)
{
    try {
        require(argc == 2, "expected BCC vfsstat native ELF");
        std::ifstream input(argv[1], std::ios::binary);
        std::vector<unsigned char> native{std::istreambuf_iterator<char>(input), {}};
        require(!input.bad() && !native.empty(), "read native ELF");
        bpf_map_create_opts map_opts{}; map_opts.sz = sizeof(map_opts);
        int map = bpf_map_create(BPF_MAP_TYPE_ARRAY, "vfsstat.bss", 4, 40, 1, &map_opts);
        require(map >= 0, "create actual source map");
        bpf_map_info map_info{}; uint32_t size = sizeof(map_info);
        require(!bpf_obj_get_info_by_fd(map, &map_info, &size), "query map identity");
        bpf_insn code[4]{};
        code[0].code = BPF_LD | BPF_DW | BPF_IMM;
        code[0].dst_reg = 1; code[0].src_reg = BPF_PSEUDO_MAP_VALUE; code[0].imm = map;
        code[2].code = BPF_ALU64 | BPF_MOV | BPF_K; code[2].imm = 2;
        code[3].code = BPF_JMP | BPF_EXIT;
        bpf_prog_load_opts opts{}; opts.sz = sizeof(opts);
        int source = bpf_prog_load(BPF_PROG_TYPE_XDP, "submit_source", "GPL", code, 4, &opts);
        require(source >= 0, "load source program");
        bpf_prog_info info{}; size = sizeof(info);
        require(!bpf_obj_get_info_by_fd(source, &info, &size), "query source identity");
        int ready[2]; require(!pipe(ready), "service readiness pipe");
        pid_t child = fork(); require(child >= 0, "fork registered service");
        if (!child) {
            require(!close(ready[0]), "close service read end");
            int service = open("/sys/kernel/debug/bpf_x86_native_lab/specializer", O_RDWR);
            require(service >= 0, "register service");
            require(write(ready[1], "x", 1) == 1, "announce service");
            require(!close(ready[1]), "close service write end");
            native_lab_trusted_request request{}; request.version = NATIVE_LAB_TRUSTED_VERSION;
            require(ioctl(service, NATIVE_LAB_TRUSTED_NEXT, &request) == -1 && errno == EMSGSIZE,
                    "probe kernel snapshot sizes");
            std::vector<unsigned char> bytes(request.native_size), entry(request.entry_size), metadata(request.metadata_size);
            request.native_user = reinterpret_cast<uintptr_t>(bytes.data());
            request.entry_user = reinterpret_cast<uintptr_t>(entry.data());
            request.metadata_user = reinterpret_cast<uintptr_t>(metadata.data());
            require(!ioctl(service, NATIVE_LAB_TRUSTED_NEXT, &request), "receive kernel snapshot");
            require(bytes == native && std::string(entry.begin(), entry.end()) == "kprobe_vfs_read" &&
                    request.source_prog_id == info.id, "exact P, entry and source identity");
            std::string json(metadata.begin(), metadata.end());
            std::cout << "kernel submission metadata: " << json << std::endl;
            require(json.find("\"name\":\"stats\"") != std::string::npos &&
                    json.find("\"map_id\":" + std::to_string(map_info.id)) != std::string::npos &&
                    json.find("\"value_offset\":0") != std::string::npos,
                    "native data symbol uses actual source map identity and offset");
            native_lab_trusted_map shape{};
            shape.request_id = request.request_id; shape.map_id = map_info.id;
            require(!ioctl(service, NATIVE_LAB_TRUSTED_MAP, &shape) && shape.value_size == 40,
                    "kernel retained the actual map capability");
            native_lab_trusted_result result{}; result.request_id = request.request_id; result.status = -EACCES;
            require(!ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), "complete deliberate rejection");
            require(!close(service), "close service");
            _exit(0);
        }
        require(!close(ready[1]), "close producer write end");
        char marker; require(read(ready[0], &marker, 1) == 1, "await service");
        require(!setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF", "1", 1), "select verified route");
        native_loader::FdLoadOptions options;
        options.original_prog_fd = source; options.native_object_path = argv[1]; options.symbol_name = "kprobe_vfs_read";
        bool rejected = false;
        try {
            auto loaded = native_loader::load_from_fd(options);
            native_loader::close_loaded_program(&loaded);
        } catch (const std::exception &error) {
            rejected = error.what() == std::string("trusted specializer refused native program: ") + std::strerror(EACCES);
            if (!rejected) std::cerr << error.what() << '\n';
        }
        require(rejected, "propagate service rejection without a direct upload");
        int status;
        require(waitpid(child, &status, 0) == child && WIFEXITED(status) && !WEXITSTATUS(status), "service result");
        require(!close(source) && !close(map) && !close(ready[0]), "close source resources");
        std::cout << "PASS: exact kernel P snapshot, map capability and service rejection; no native execution\n";
        return 0;
    } catch (const std::exception &error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
