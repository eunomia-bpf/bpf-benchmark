/* Actual stock acceptance only; KPROBE test-run/execution is not claimed. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQUIRE(C) do { if (!(C)) { fprintf(stderr, "line %d: %s\n", __LINE__, #C); return 1; } } while (0)

static int check(const char *path, const char *entry, const char *log_path)
{
    char *log = calloc(1, 1U << 20);
    REQUIRE(log);
    LIBBPF_OPTS(bpf_object_open_opts, opts, .kernel_log_buf = log,
                .kernel_log_size = 1U << 20, .kernel_log_level = 2);
    struct bpf_object *object = bpf_object__open_file(path, &opts);
    REQUIRE(object && !libbpf_get_error(object));
    struct bpf_program *program;
    bpf_object__for_each_program(program, object)
        REQUIRE(bpf_program__set_autoload(program, !strcmp(bpf_program__name(program), entry)) == 0);
    program = bpf_object__find_program_by_name(object, entry);
    REQUIRE(program && bpf_program__type(program) == BPF_PROG_TYPE_KPROBE);
    int status = bpf_object__load(object);
    FILE *output = fopen(log_path, "w");
    REQUIRE(output && fputs(log, output) >= 0 && fclose(output) == 0);
    if (status) fprintf(stderr, "load %s failed: %d\n%s\n", path, status, log);
    REQUIRE(status == 0);
    struct bpf_prog_info info = {};
    unsigned size = sizeof(info);
    REQUIRE(bpf_obj_get_info_by_fd(bpf_program__fd(program), &info, &size) == 0);
    printf("{\"entry\":\"%s\",\"id\":%u,\"type\":%u,\"bytes_jited\":%u,\"bytes_xlated\":%u,\"stock_accepted\":true}\n",
           entry, info.id, info.type, info.jited_prog_len, info.xlated_prog_len);
    bpf_object__close(object);
    free(log);
    return 0;
}

int main(int argc, char **argv)
{
    REQUIRE(argc == 5);
    REQUIRE(check(argv[1], "jump_table", argv[3]) == 0);
    REQUIRE(check(argv[2], "trusted_x86_x86_sim_xdp", argv[4]) == 0);
    return 0;
}
