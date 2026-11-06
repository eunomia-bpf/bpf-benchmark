/* Capture actual clang bytes and kernel context conversion, without executing
 * the programs or substituting application programs/maps.
 */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <vector>

static void write(const std::string &path, const void *bytes, size_t size)
{
    std::ofstream file(path, std::ios::binary);
    file.write(static_cast<const char *>(bytes), size);
    file.close();
    if (!file) throw std::runtime_error("write " + path);
}

int main()
{
    try {
        std::unique_ptr<bpf_object, decltype(&bpf_object__close)> object(
            bpf_object__open_file("build/context-fields.bpf.o", nullptr), bpf_object__close);
        if (!object || libbpf_get_error(object.get())) throw std::runtime_error("open context artifact");
        bpf_program *program;
        bpf_object__for_each_program(program, object.get())
            if (!std::strcmp(bpf_program__name(program), "tv_ctx_egress_ifindex") &&
                bpf_program__set_expected_attach_type(program, BPF_XDP_DEVMAP))
                throw std::runtime_error("set egress context attach type");
        if (bpf_object__load(object.get())) throw std::runtime_error("load context artifact");
        bpf_object__for_each_program(program, object.get()) {
            const std::string base = std::string("build/context-access/") + bpf_program__name(program);
            write(base + ".raw.bin", bpf_program__insns(program),
                bpf_program__insn_cnt(program) * sizeof(bpf_insn));
            bpf_prog_info info{};
            uint32_t size = sizeof(info);
            if (bpf_obj_get_info_by_fd(bpf_program__fd(program), &info, &size))
                throw std::runtime_error("query context conversion size");
            if (!info.xlated_prog_len || info.xlated_prog_len % sizeof(bpf_insn))
                throw std::runtime_error("invalid converted context extent");
            const std::string context = "{\"version\":1,\"program_type\":" + std::to_string(info.type) +
                ",\"expected_attach_type\":" + std::to_string(bpf_program__expected_attach_type(program)) +
                ",\"prog_flags\":" + std::to_string(bpf_program__flags(program)) +
                ",\"source_prog_id\":" + std::to_string(info.id) +
                ",\"attach_btf_id\":" + std::to_string(info.attach_btf_id) + "}\n";
            write(base + ".context.json", context.data(), context.size());
            std::vector<unsigned char> bytes(info.xlated_prog_len);
            info = {};
            info.xlated_prog_len = bytes.size();
            info.xlated_prog_insns = reinterpret_cast<uintptr_t>(bytes.data());
            if (bpf_obj_get_info_by_fd(bpf_program__fd(program), &info, &size))
                throw std::runtime_error("read converted context artifact: " + std::string(std::strerror(errno)));
            if (info.xlated_prog_len != bytes.size()) throw std::runtime_error("context extent changed");
            write(base + ".xlated.bin", bytes.data(), bytes.size());
            std::printf("%s: captured clang %zu bytes, actual kernel %zu bytes\n",
                bpf_program__name(program), bpf_program__insn_cnt(program) * sizeof(bpf_insn), bytes.size());
        }
    } catch (const std::exception &error) {
        std::fprintf(stderr, "%s\n", error.what());
        return 1;
    }
}
