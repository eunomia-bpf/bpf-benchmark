// Simple program that loads a BPF program and holds it loaded (sleeps)
// Usage: hold_bpf_prog <program.bpf.o> [sleep_seconds]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bpf/libbpf.h>
#include <bpf/bpf.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <program.bpf.o> [sleep_seconds]\n", argv[0]);
        return 1;
    }

    const char *prog_path = argv[1];
    int sleep_sec = argc > 2 ? atoi(argv[2]) : 60;

    struct bpf_object *obj = bpf_object__open(prog_path);
    if (!obj) {
        fprintf(stderr, "Failed to open %s\n", prog_path);
        return 1;
    }

    int err = bpf_object__load(obj);
    if (err) {
        fprintf(stderr, "Failed to load %s: %d\n", prog_path, err);
        bpf_object__close(obj);
        return 1;
    }

    struct bpf_program *prog;
    bpf_object__for_each_program(prog, obj) {
        fprintf(stderr, "Loaded: %s (fd=%d)\n",
                bpf_program__name(prog), bpf_program__fd(prog));
    }

    fprintf(stderr, "Holding program loaded for %d seconds...\n", sleep_sec);
    fflush(stderr);
    sleep(sleep_sec);

    bpf_object__close(obj);
    return 0;
}
