#include <bpf/libbpf.h>

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int libbpf_print(enum libbpf_print_level level,
                        const char *format,
                        va_list args)
{
    if (level == LIBBPF_DEBUG) {
        return 0;
    }
    return vfprintf(stderr, format, args);
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "build/multi_prog_smoke.bpf.o";
    libbpf_set_print(libbpf_print);

    struct bpf_object *obj = bpf_object__open_file(path, NULL);
    long open_err = libbpf_get_error(obj);
    if (open_err) {
        fprintf(stderr, "open %s failed: %s\n", path, strerror((int)-open_err));
        return 1;
    }

    struct bpf_program *prog;
    bpf_object__for_each_program(prog, obj) {
        bpf_program__set_autoattach(prog, false);
    }

    if (bpf_object__load(obj) != 0) {
        fprintf(stderr, "load %s failed: %s\n", path, strerror(errno));
        bpf_object__close(obj);
        return 1;
    }

    int count = 0;
    bpf_object__for_each_program(prog, obj) {
        int fd = bpf_program__fd(prog);
        printf("loaded %s fd=%d\n", bpf_program__name(prog), fd);
        if (fd < 0) {
            bpf_object__close(obj);
            return 1;
        }
        count++;
    }

    bpf_object__close(obj);
    if (count != 2) {
        fprintf(stderr, "expected 2 programs, loaded %d\n", count);
        return 1;
    }
    return 0;
}
