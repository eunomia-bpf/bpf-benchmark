/* Reproduce verifier precision loss when packing compiler-private u32 spills. */
#include <bpf/bpf.h>
#include <errno.h>
#include <linux/bpf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static struct bpf_insn insn(unsigned char code, unsigned char dst,
                            unsigned char src, short off, int imm)
{
    return (struct bpf_insn){.code = code, .dst_reg = dst, .src_reg = src,
                             .off = off, .imm = imm};
}

static int check(const char *directory, int map, const char *name,
                 short offset, int paired, int expect_accepted)
{
    struct bpf_insn program[20];
    size_t count = 0;
    program[count++] = insn(BPF_ALU64 | BPF_MOV | BPF_X, 6, 1, 0, 0);
    program[count++] = insn(BPF_ALU | BPF_MOV | BPF_K, 1, 0, 0, 1);
    program[count++] = insn(BPF_STX | BPF_MEM | BPF_W, 10, 1, offset, 0);
    if (paired) {
        program[count++] = insn(BPF_ALU | BPF_MOV | BPF_K, 2, 0, 0, 4);
        program[count++] = insn(BPF_STX | BPF_MEM | BPF_W, 10, 2,
                               offset == -8 ? -4 : -8, 0);
    }
    program[count++] = insn(BPF_LDX | BPF_MEM | BPF_W, 1, 10, offset, 0);
    /* Only verifier knowledge of the stored value prunes the invalid ctx. */
    program[count++] = insn(BPF_JMP32 | BPF_JEQ | BPF_K, 1, 0, 1, 1);
    program[count++] = insn(BPF_ALU64 | BPF_MOV | BPF_K, 6, 0, 0, 0);
    program[count++] = insn(BPF_ALU64 | BPF_MOV | BPF_X, 1, 6, 0, 0);
    program[count++] = insn(BPF_LD | BPF_DW | BPF_IMM, 2, BPF_PSEUDO_MAP_FD, 0, map);
    program[count++] = insn(0, 0, 0, 0, 0);
    program[count++] = insn(BPF_ALU | BPF_MOV | BPF_K, 3, 0, 0, 0);
    program[count++] = insn(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_tail_call);
    program[count++] = insn(BPF_ALU | BPF_MOV | BPF_K, 0, 0, 0, XDP_PASS);
    program[count++] = insn(BPF_JMP | BPF_EXIT, 0, 0, 0, 0);
    char log[65536] = {};
    LIBBPF_OPTS(bpf_prog_load_opts, options,
                .log_level = 2, .log_size = sizeof(log), .log_buf = log);
    int fd = bpf_prog_load(BPF_PROG_TYPE_XDP, name, "GPL", program, count, &options);
    int error = fd < 0 ? errno : 0;
    char path[4096];
    int length = snprintf(path, sizeof(path), "%s/%s.verifier.log", directory, name);
    if (length < 0 || (size_t)length >= sizeof(path)) {
        fprintf(stderr, "verifier log path too long\n");
        if (fd >= 0) close(fd);
        return 1;
    }
    FILE *output = fopen(path, "w");
    if (!output) { perror(path); if (fd >= 0) close(fd); return 1; }
    int failed = fwrite(log, 1, strlen(log), output) != strlen(log);
    if (fclose(output)) failed = 1;
    if (fd >= 0 && close(fd)) { perror("close program"); failed = 1; }
    printf("{\"case\":\"%s\",\"offset\":%d,\"paired\":%d,\"accepted\":%s,\"errno\":%d}\n",
           name, offset, paired, error ? "false" : "true", error);
    if ((!error) != expect_accepted ||
        (error && !strstr(log, "R1 type=scalar expected=ctx"))) {
        fprintf(stderr, "%s: unexpected stock verifier outcome\n%s", name, log);
        failed = 1;
    }
    return failed;
}

int main(int argc, char **argv)
{
    if (argc != 2) { fprintf(stderr, "usage: scalar-spill-precision OUTPUT\n"); return 1; }
    int map = bpf_map_create(BPF_MAP_TYPE_PROG_ARRAY, "spill_jumps", 4, 4, 1, NULL);
    if (map < 0) { perror("create prog array"); return 1; }
    int failed = check(argv[1], map, "aligned", -8, 0, 1);
    failed |= check(argv[1], map, "upper", -4, 0, 0);
    failed |= check(argv[1], map, "pair_lower", -8, 1, 0);
    failed |= check(argv[1], map, "pair_upper", -4, 1, 0);
    if (close(map)) { perror("close map"); failed = 1; }
    return failed;
}
