/*
 * Standalone test runner for ebpf-vm/test-others/.
 *
 * Does NOT depend on the bench micro framework (no driver.py, no
 * micro_exec, no yaml suite). Uses libbpf C API directly:
 *
 *   1. Open + load a .bpf.o.
 *   2. Auto-attach all programs (libbpf finds the kernel target from
 *      the SEC() name: kprobe/__x64_sys_getpid, uprobe (offset
 *      supplied), raw_tp/sched_switch).
 *   3. Trigger the probe N times.
 *   4. Read the `count_map` single-slot value.
 *   5. Print "<program> kernel: count=<N> expected=<E>".
 *
 * Each test program counts entries into the same `count_map` shape so
 * the runner has a uniform readback path.
 *
 * Build: see Makefile in this directory. Run: ./runner <bpf.o> <mode>
 * where mode is one of: kprobe | uprobe | raw_tp.
 */
#define _GNU_SOURCE
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <errno.h>
#include <inttypes.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

/* Exported symbol for the uprobe test to attach against. Kept
 * non-static + with a side-effect on a volatile global so the
 * optimizer can't inline it away when called from main(). */
volatile int uprobe_sink;
__attribute__((noinline))
void uprobe_target(int x)
{
    uprobe_sink = x;
}

static int trigger_kprobe(int iters)
{
    for (int i = 0; i < iters; i++) {
        (void)syscall(SYS_getpid);
    }
    return iters;
}

static int trigger_uprobe(int iters)
{
    for (int i = 0; i < iters; i++) {
        uprobe_target(i);
    }
    return iters;
}

static int trigger_raw_tp(int iters)
{
    /* sched_yield() is a no-op when there's no other runnable task on
     * the same CPU; usleep(1) actually puts us to sleep so the
     * scheduler picks something else and we see a sched_switch on
     * return. usleep(1) typically rounds up to one timer tick (~1 ms
     * on a 1000 Hz kernel), which is fast enough that 100 iterations
     * complete in well under a second. */
    for (int i = 0; i < iters; i++) {
        usleep(1);
    }
    return iters;
}

static int read_count_map(struct bpf_object *obj, uint64_t *out)
{
    struct bpf_map *map = bpf_object__find_map_by_name(obj, "count_map");
    if (!map) {
        fprintf(stderr, "count_map not found in object\n");
        return -1;
    }
    int map_fd = bpf_map__fd(map);
    if (map_fd < 0) {
        fprintf(stderr, "count_map has no fd: %d\n", map_fd);
        return -1;
    }
    uint32_t key = 0;
    uint64_t val = 0;
    if (bpf_map_lookup_elem(map_fd, &key, &val) != 0) {
        if (errno == ENOENT) {
            *out = 0;
            return 0;
        }
        fprintf(stderr, "bpf_map_lookup_elem: %s\n", strerror(errno));
        return -1;
    }
    *out = val;
    return 0;
}

static int run_kprobe(struct bpf_object *obj)
{
    struct bpf_program *prog =
        bpf_object__find_program_by_name(obj, "kprobe_getpid");
    if (!prog) {
        fprintf(stderr, "kprobe_getpid program not found\n");
        return 1;
    }
    struct bpf_link *link =
        bpf_program__attach_kprobe(prog, /*retprobe=*/false,
                                   "__x64_sys_getpid");
    if (libbpf_get_error(link)) {
        fprintf(stderr, "attach_kprobe: %s\n",
                strerror(-libbpf_get_error(link)));
        return 1;
    }

    const int iters = 100;
    trigger_kprobe(iters);

    uint64_t count = 0;
    if (read_count_map(obj, &count) != 0) {
        bpf_link__destroy(link);
        return 1;
    }
    printf("kprobe_getpid    kernel: count=%" PRIu64 " expected=%d  %s\n",
           count, iters,
           (count == (uint64_t)iters) ? "OK" : "MISMATCH");
    bpf_link__destroy(link);
    return (count == (uint64_t)iters) ? 0 : 1;
}

static int run_uprobe(struct bpf_object *obj)
{
    struct bpf_program *prog =
        bpf_object__find_program_by_name(obj, "uprobe_handler");
    if (!prog) {
        fprintf(stderr, "uprobe_handler program not found\n");
        return 1;
    }

    /* libbpf can attach at a function name resolved via the binary's
     * symbol table. self_path = /proc/self/exe. The kernel needs the
     * file offset of `uprobe_target`; libbpf does that via ELF. */
    char self_path[256];
    ssize_t r = readlink("/proc/self/exe", self_path, sizeof(self_path) - 1);
    if (r < 0) {
        fprintf(stderr, "readlink /proc/self/exe: %s\n", strerror(errno));
        return 1;
    }
    self_path[r] = 0;

    /* `bpf_program__attach_uprobe(..., func_offset=0)` attaches at the
     * binary's ELF load offset (the header), not at any symbol. To
     * resolve a symbol name we use `_opts` with `func_name` set and
     * leave `func_offset=0` as the within-symbol offset. */
    LIBBPF_OPTS(bpf_uprobe_opts, uopts,
                .retprobe = false,
                .func_name = "uprobe_target");
    struct bpf_link *link = bpf_program__attach_uprobe_opts(
        prog, getpid(), self_path, /*func_offset=*/0, &uopts);
    if (libbpf_get_error(link)) {
        fprintf(stderr, "attach_uprobe: %s\n",
                strerror(-libbpf_get_error(link)));
        return 1;
    }

    const int iters = 100;
    trigger_uprobe(iters);

    uint64_t count = 0;
    if (read_count_map(obj, &count) != 0) {
        bpf_link__destroy(link);
        return 1;
    }
    printf("uprobe_self      kernel: count=%" PRIu64 " expected=%d  %s\n",
           count, iters,
           (count == (uint64_t)iters) ? "OK" : "MISMATCH");
    bpf_link__destroy(link);
    return (count == (uint64_t)iters) ? 0 : 1;
}

static int run_raw_tp(struct bpf_object *obj)
{
    struct bpf_program *prog =
        bpf_object__find_program_by_name(obj, "raw_tp_sched_switch");
    if (!prog) {
        fprintf(stderr, "raw_tp_sched_switch program not found\n");
        return 1;
    }
    struct bpf_link *link =
        bpf_program__attach_raw_tracepoint(prog, "sched_switch");
    if (libbpf_get_error(link)) {
        fprintf(stderr, "attach_raw_tracepoint: %s\n",
                strerror(-libbpf_get_error(link)));
        return 1;
    }

    const int iters = 100;
    trigger_raw_tp(iters);

    uint64_t count = 0;
    if (read_count_map(obj, &count) != 0) {
        bpf_link__destroy(link);
        return 1;
    }
    /* Context switches can happen for any reason — assert >= iters
     * rather than == (other CPUs / kernel threads fire too). */
    printf("raw_tp_sched_sw  kernel: count=%" PRIu64 " expected>=%d  %s\n",
           count, iters, (count >= (uint64_t)iters) ? "OK" : "MISMATCH");
    bpf_link__destroy(link);
    return (count >= (uint64_t)iters) ? 0 : 1;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr,
                "usage: %s <bpf.o> <kprobe|uprobe|raw_tp>\n", argv[0]);
        return 2;
    }
    const char *bpf_path = argv[1];
    const char *mode = argv[2];

    /* Bumps RLIMIT_MEMLOCK for older kernels; on modern memcg-charged
     * BPF allocations this is a no-op. */
    libbpf_set_strict_mode(LIBBPF_STRICT_ALL);

    struct bpf_object *obj = bpf_object__open(bpf_path);
    if (libbpf_get_error(obj)) {
        fprintf(stderr, "bpf_object__open(%s): %s\n", bpf_path,
                strerror(-libbpf_get_error(obj)));
        return 1;
    }
    if (bpf_object__load(obj) != 0) {
        fprintf(stderr, "bpf_object__load: %s\n", strerror(errno));
        bpf_object__close(obj);
        return 1;
    }

    int rc = 1;
    if (strcmp(mode, "kprobe") == 0) {
        rc = run_kprobe(obj);
    } else if (strcmp(mode, "uprobe") == 0) {
        rc = run_uprobe(obj);
    } else if (strcmp(mode, "raw_tp") == 0) {
        rc = run_raw_tp(obj);
    } else {
        fprintf(stderr, "unknown mode: %s\n", mode);
        rc = 2;
    }

    bpf_object__close(obj);
    return rc;
}
