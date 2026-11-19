/* The guarded pointer subtraction must pass the stock verifier. */
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <net/if.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3) return 1;
    char log[1 << 20] = {};
    struct bpf_object_open_opts open_opts = {};
    open_opts.sz = sizeof(open_opts);
    open_opts.kernel_log_buf = log;
    open_opts.kernel_log_size = sizeof(log);
    open_opts.kernel_log_level = 2;
    struct bpf_object *object = bpf_object__open_file(argv[1], &open_opts);
    if (!object) { perror("open B fixture"); return 1; }
    int result = bpf_object__load(object);
    FILE *output = fopen(argv[2], "w");
    if (!output) { perror("open verifier log"); bpf_object__close(object); return 1; }
    int written = fputs(log, output);
    int closed = fclose(output);
    if (written == EOF || closed) {
        perror("write verifier log"); bpf_object__close(object); return 1;
    }
    if (result) { fprintf(stderr, "stock B load failed: %d\n", result); bpf_object__close(object); return 1; }
    struct bpf_program *program = bpf_object__find_program_by_name(object, "guarded_difference");
    if (!program) { fprintf(stderr, "missing fixture program\n"); bpf_object__close(object); return 1; }
    unsigned char packet[64] = {};
    struct bpf_test_run_opts run = {};
    run.sz = sizeof(run); run.data_in = packet;
    run.data_size_in = sizeof(packet); run.repeat = 1;
    result = bpf_prog_test_run_opts(bpf_program__fd(program), &run);
    bpf_object__close(object);
    /* test_run.c uses loopback queue zero when no XDP ctx_in is supplied. */
    unsigned expected = if_nametoindex("lo");
    if (!expected) { fprintf(stderr,"missing loopback interface\n"); return 1; }
    if (result || run.retval != expected) {
        fprintf(stderr, "scalar-path TEST_RUN failed: %d, retval %u\n", result, run.retval); return 1;
    }
    printf("{\"stock_accepted\":true,\"test_run_retval\":%u,\"default_ingress_ifindex\":%u,"
           "\"scope\":\"Focused B fixture only; no application coverage or timing\"}\n",run.retval,expected);
    return 0;
}
