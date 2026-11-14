/* Catch packed-half corruption, zero-extension and live-register clobbers. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

static int run(const char *path)
{
    struct bpf_object *object = bpf_object__open_file(path, NULL);
    long error = libbpf_get_error(object);
    if (error) { fprintf(stderr, "open %s: %ld\n", path, error); return 1; }
    if (bpf_object__load(object)) { perror("load spill fixture"); bpf_object__close(object); return 1; }
    struct bpf_program *program = bpf_object__find_program_by_name(object, "spill_values");
    if (!program) { fprintf(stderr, "spill_values entry missing\n"); bpf_object__close(object); return 1; }
    const uint32_t edges[] = {0, 1, 0x7fffffff, 0x80000000, 0xffffffff, 0xffffcfc7};
    uint32_t state = 0x7341bc29;
    unsigned count = 0;
    unsigned char packet[64] = {};
    int failed = 0;
    for (unsigned i = 0; i < 1060; ++i) {
        state ^= state << 13; state ^= state >> 17; state ^= state << 5;
        uint32_t mark = i < 36 ? edges[i / 6] : state;
        state ^= state << 13; state ^= state >> 17; state ^= state << 5;
        uint32_t priority = i < 36 ? edges[i % 6] : state;
        struct __sk_buff context = {.mark = mark, .priority = priority};
        LIBBPF_OPTS(bpf_test_run_opts, options,
                    .data_in = packet, .data_size_in = sizeof(packet),
                    .ctx_in = &context, .ctx_size_in = sizeof(context), .repeat = 1);
        if (bpf_prog_test_run_opts(bpf_program__fd(program), &options)) {
            perror("execute spill fixture"); failed = 1; break;
        }
        uint32_t expected = mark ^ (priority + UINT32_C(12345));
        if (options.retval != expected) {
            fprintf(stderr, "value mismatch %s mark=%u priority=%u got=%u expected=%u\n",
                    path, mark, priority, options.retval, expected);
            failed = 1; break;
        }
        ++count;
    }
    bpf_object__close(object);
    printf("{\"object\":\"%s\",\"executions\":%u,\"failed\":%d}\n", path, count, failed);
    return failed;
}

int main(int argc, char **argv)
{
    if (argc != 3) { fprintf(stderr, "usage: scalar-spill-values ORIGINAL LOWERED\n"); return 1; }
    if (offsetof(struct __sk_buff, mark) != 8 || offsetof(struct __sk_buff, priority) != 32) {
        fprintf(stderr, "fixture context offsets differ\n"); return 1;
    }
    return run(argv[1]) | run(argv[2]);
}
