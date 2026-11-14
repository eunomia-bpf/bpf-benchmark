/* Detect a transform that preserves the LLVM shape but emits rejected BPF. */
#include <bpf/libbpf.h>
#include <stdio.h>
#include <string.h>

static int check(const char *path, const char *name, int expected)
{
    char log[65536] = {};
    LIBBPF_OPTS(bpf_object_open_opts, opts, .kernel_log_buf = log,
                .kernel_log_size = sizeof(log), .kernel_log_level = 2);
    struct bpf_object *object = bpf_object__open_file(path, &opts);
    long error = libbpf_get_error(object);
    if (error) { fprintf(stderr, "open %s: %ld\n", path, error); return 1; }
    struct bpf_program *program;
    bpf_object__for_each_program(program, object) {
        if (bpf_program__set_autoload(program, strcmp(bpf_program__name(program), name) == 0)) {
            fprintf(stderr, "set_autoload failed\n"); bpf_object__close(object); return 1;
        }
    }
    if (!bpf_object__find_program_by_name(object, name)) {
        fprintf(stderr, "missing entry %s\n", name); bpf_object__close(object); return 1;
    }
    int accepted = bpf_object__load(object) == 0;
    int failed = accepted != expected || (!accepted && !strstr(log, "dereference of modified ctx ptr"));
    printf("{\"object\":\"%s\",\"entry\":\"%s\",\"accepted\":%d,\"failed\":%d}\n", path, name, accepted, failed);
    if (failed) fprintf(stderr, "%s\n", log);
    bpf_object__close(object);
    return failed;
}

int main(int argc, char **argv)
{
    if (argc != 3) { fprintf(stderr, "usage: context-load-client OFF ON\n"); return 1; }
    int failed = 0;
    const char *names[] = {"ctx8", "ctx16", "ctx32", "ctx64"};
    for (unsigned i = 0; i < 4; ++i) {
        failed |= check(argv[1], names[i], 0);
        failed |= check(argv[2], names[i], 1);
    }
    return failed;
}
