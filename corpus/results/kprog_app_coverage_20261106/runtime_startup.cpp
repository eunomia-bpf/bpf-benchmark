/* Shim integration test only: exercise an application's own libbpf startup. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <vector>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3) return 2;
    bpf_object *obj = bpf_object__open_file(argv[1], nullptr);
    if (!obj) return 3;
    bpf_program *prog = bpf_object__find_program_by_name(obj, "runtime_source");
    if (!prog) return 4;
    if (argc == 3) {
        char *end;
        errno = 0;
        unsigned long flags = std::strtoul(argv[2], &end, 0);
        if (errno || *end || flags > UINT_MAX || bpf_program__set_flags(prog, flags)) return 2;
    }
    if (bpf_object__load(obj)) return 3;
    /* The shim deliberately exposes original metadata on the loader FD.
     * A fresh descriptor lets this test inspect the actual installed program. */
    int fd = dup(bpf_program__fd(prog));
    if (fd < 0) return 5;
    bpf_prog_info info{};
    __u32 size = sizeof(info);
    if (bpf_obj_get_info_by_fd(fd, &info, &size)) return 5;
    std::vector<bpf_insn> image(info.xlated_prog_len / sizeof(bpf_insn));
    if (image.empty()) return 6;
    info = {};
    info.xlated_prog_len = image.size() * sizeof(bpf_insn);
    info.xlated_prog_insns = (uintptr_t)image.data();
    if (bpf_obj_get_info_by_fd(fd, &info, &size)) return 7;
    unsigned generations = 0;
    for (auto insn : image)
        if (insn.code == (BPF_ALU64 | BPF_MOV | BPF_K) &&
            insn.src_reg == BPF_PSEUDO_KINSN_SIDECAR && insn.imm != 0)
            generations++;
    unsigned char input[64]{};
    bpf_test_run_opts run{};
    run.sz = sizeof(run);
    run.data_in = input;
    run.data_size_in = sizeof(input);
    run.repeat = 1;
    if (bpf_prog_test_run_opts(fd, &run)) return 8;
    std::printf("program_id=%u nonzero_generations=%u invocations=1 retval=%u\n",
                info.id, generations, run.retval);
    bpf_object__close(obj);
    if (close(fd)) return 10;
    return run.retval == 127 && generations ? 0 : 9;
}
