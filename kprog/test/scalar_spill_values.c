/* Catch packed-half corruption, zero-extension and live-register clobbers. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

static int run(const char *path, int groups, const char *phase)
{
    char verifier_log[1024 * 1024] = {};
    LIBBPF_OPTS(bpf_object_open_opts, open_options, .kernel_log_buf = verifier_log,
                .kernel_log_size = sizeof(verifier_log), .kernel_log_level = 1);
    struct bpf_object *object = bpf_object__open_file(path, groups ? &open_options : NULL);
    long error = libbpf_get_error(object);
    if (error) { fprintf(stderr, "open %s: %ld\n", path, error); return 1; }
    if (bpf_object__load(object)) {
        perror("load spill fixture");
        if (groups) fprintf(stderr, "%s", verifier_log);
        bpf_object__close(object); return 1;
    }
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
        if (groups == 1) {
            expected = mark ^ priority ^ (mark + UINT32_C(1)) ^ (priority + UINT32_C(2))
                ^ (mark ^ UINT32_C(0x80000000)) ^ (priority ^ UINT32_C(0x7fffffff))
                ^ (mark + UINT32_C(74565)) ^ (priority + UINT32_C(344865))
                ^ (priority * UINT32_C(3)) ^ (priority + UINT32_C(11)) ^ (mark + UINT32_C(17));
        } else if (groups >= 2) {
            expected = (mark + UINT32_C(1)) ^ (priority + UINT32_C(9));
            if (groups == 3)
                expected ^= mark + UINT32_C(17);
            else if (groups == 4)
                expected ^= (mark + UINT32_C(17)) + (priority + UINT32_C(9));
            expected += mark;
            expected += priority;
            expected += mark + UINT32_C(1);
            expected += priority + UINT32_C(3);
            expected += mark + UINT32_C(5);
            expected += priority + UINT32_C(7);
            expected += mark ^ UINT32_C(0x80000000);
            expected += priority ^ UINT32_C(0x7fffffff);
        }
        if (options.retval != expected) {
            fprintf(stderr, "value mismatch %s mark=%u priority=%u got=%u expected=%u\n",
                    path, mark, priority, options.retval, expected);
            failed = 1; break;
        }
        ++count;
    }
    bpf_object__close(object);
    printf("{\"object\":\"%s\",\"phase\":\"%s\",\"executions\":%u,\"failed\":%d}\n", path, phase, count, failed);
    return failed;
}

int main(int argc, char **argv)
{
    int groups = argc == 4 ? (!strcmp(argv[1], "--groups") ? 1 :
                              !strcmp(argv[1], "--pressure") ? 2 :
                              !strcmp(argv[1], "--pressure-context") ? 3 :
                              !strcmp(argv[1], "--pressure-all-live") ? 4 : 0) : 0;
    if (argc != 3 && !groups) {
        fprintf(stderr, "usage: scalar-spill-values ORIGINAL LOWERED | --groups/--pressure PHASE OBJECT\n"); return 1;
    }
    if (offsetof(struct __sk_buff, mark) != 8 || offsetof(struct __sk_buff, priority) != 32) {
        fprintf(stderr, "fixture context offsets differ\n"); return 1;
    }
    if (groups) return run(argv[3], groups, argv[2]);
    return run(argv[1], 0, "original") | run(argv[2], 0, "lowered");
}
