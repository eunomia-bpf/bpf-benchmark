/*
 * Standalone test runner for ebpf-vm/test-others/.
 *
 * For each program (kprobe / uprobe / raw_tp), runs four configurations
 * and prints the count + per-call handler overhead:
 *
 *   1. NONE      — trigger the probe point with no BPF attached
 *                  (baseline wall time per trigger).
 *   2. KERNEL    — libbpf-load the .bpf.o, attach via libbpf, trigger.
 *   3. NATIVE    — go through the bpf_x86_native_lab kinsn:
 *                  native-link the .native.o, upload blob, load stub
 *                  prog with prog_type=KPROBE/RAW_TRACEPOINT, attach
 *                  via perf_event_open or bpf_raw_tracepoint_open,
 *                  trigger.
 *
 * Per-call overhead = (mean_with_probe_wall - baseline_wall) / iters.
 * Both runtimes hit the same kernel count_map (libbpf-allocated in
 * config 2; reused by native_lab's stub via fd_array + native-link
 * map_ptr patching in config 3), so the count value should be
 * bit-identical between kernel JIT and native_lab.
 */
#include "native_lab_attach.hpp"

#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cerrno>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <sched.h>
#include <sys/syscall.h>
#include <unistd.h>

/* Exported symbol for the uprobe test to attach against. extern "C"
 * keeps the linker symbol unmangled (just `uprobe_target`) so a name-
 * based attach (uprobe_events / libbpf func_name) can resolve it.
 * Volatile sink + noinline keep the optimizer from inlining it away. */
extern "C" {
volatile int uprobe_sink;
__attribute__((noinline)) void uprobe_target(int x)
{
    uprobe_sink = x;
}
}

static constexpr int kIters   = 100000;
static constexpr int kWarmups = 1000;

static uint64_t now_ns()
{
    auto t = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t).count();
}

static void trigger_kprobe(int n)
{
    for (int i = 0; i < n; i++) {
        (void)syscall(SYS_getpid);
    }
}

static void trigger_uprobe(int n)
{
    for (int i = 0; i < n; i++) {
        uprobe_target(i);
    }
}

static void trigger_raw_tp(int n)
{
    /* usleep(1) actually puts us to sleep; the scheduler picks
     * something else and we see at least one sched_switch on return. */
    for (int i = 0; i < n; i++) {
        usleep(1);
    }
}

static int read_count(int map_fd, uint64_t *out)
{
    uint32_t key = 0;
    uint64_t val = 0;
    if (bpf_map_lookup_elem(map_fd, &key, &val) != 0) {
        if (errno == ENOENT) { *out = 0; return 0; }
        std::fprintf(stderr, "bpf_map_lookup_elem: %s\n", std::strerror(errno));
        return -1;
    }
    *out = val;
    return 0;
}

static int reset_count(int map_fd)
{
    uint32_t key = 0;
    uint64_t zero = 0;
    if (bpf_map_update_elem(map_fd, &key, &zero, 0) != 0) {
        /* HASH map: BPF_ANY = insert if missing; this should always succeed */
        return -1;
    }
    return 0;
}

struct TimedRun {
    uint64_t count;      /* count_map value after run */
    uint64_t wall_ns;    /* trigger-loop wall time */
};

static TimedRun run_kernel(const char *bpf_o, const char *prog_name,
                           const char *mode, const char *target)
{
    TimedRun r = {0, 0};

    bpf_object *obj = bpf_object__open(bpf_o);
    if (libbpf_get_error(obj)) {
        std::fprintf(stderr, "kernel: open %s: %s\n", bpf_o,
                     std::strerror(-libbpf_get_error(obj)));
        return r;
    }
    if (bpf_object__load(obj) != 0) {
        std::fprintf(stderr, "kernel: load: %s\n", std::strerror(errno));
        bpf_object__close(obj);
        return r;
    }
    bpf_program *prog = bpf_object__find_program_by_name(obj, prog_name);
    bpf_map *cm = bpf_object__find_map_by_name(obj, "count_map");
    if (!prog || !cm) {
        std::fprintf(stderr, "kernel: prog/map not found\n");
        bpf_object__close(obj);
        return r;
    }
    int map_fd = bpf_map__fd(cm);
    bpf_link *link = nullptr;
    if (std::strcmp(mode, "kprobe") == 0) {
        link = bpf_program__attach_kprobe(prog, false, target);
    } else if (std::strcmp(mode, "uprobe") == 0) {
        char self_path[PATH_MAX];
        ssize_t n = readlink("/proc/self/exe", self_path, sizeof(self_path) - 1);
        if (n < 0) { bpf_object__close(obj); return r; }
        self_path[n] = 0;
        LIBBPF_OPTS(bpf_uprobe_opts, uopts,
                    .retprobe = false, .func_name = target);
        link = bpf_program__attach_uprobe_opts(prog, getpid(), self_path, 0, &uopts);
    } else if (std::strcmp(mode, "raw_tp") == 0) {
        link = bpf_program__attach_raw_tracepoint(prog, target);
    }
    if (libbpf_get_error(link)) {
        std::fprintf(stderr, "kernel: attach: %s\n",
                     std::strerror(-libbpf_get_error(link)));
        bpf_object__close(obj);
        return r;
    }

    /* Warmup to amortize I-cache cold-start and lazy kprobe handler
     * codegen, then reset counter for the measured run. */
    if (std::strcmp(mode, "kprobe") == 0) trigger_kprobe(kWarmups);
    else if (std::strcmp(mode, "uprobe") == 0) trigger_uprobe(kWarmups);
    else trigger_raw_tp(kWarmups);
    reset_count(map_fd);

    uint64_t t0 = now_ns();
    if (std::strcmp(mode, "kprobe") == 0) trigger_kprobe(kIters);
    else if (std::strcmp(mode, "uprobe") == 0) trigger_uprobe(kIters);
    else trigger_raw_tp(kIters);
    uint64_t t1 = now_ns();
    r.wall_ns = t1 - t0;
    read_count(map_fd, &r.count);

    bpf_link__destroy(link);
    bpf_object__close(obj);
    return r;
}

static TimedRun run_native(const char *bpf_o, const char *prog_name,
                           const char *mode, const char *target)
{
    TimedRun r = {0, 0};
    NlSession s{};
    int rc;
    if (std::strcmp(mode, "uprobe") == 0) {
        /* Resolve uprobe address at the call site so we don't depend
         * on nm / debug symbols inside the vng overlay. */
        rc = nl_load_and_attach_uprobe_at(bpf_o, prog_name,
                                          reinterpret_cast<void *>(&uprobe_target),
                                          getpid(), &s);
    } else {
        rc = nl_load_and_attach(bpf_o, prog_name, mode, target, getpid(), &s);
    }
    if (rc != 0) {
        std::fprintf(stderr, "native: nl_load_and_attach failed\n");
        return r;
    }
    if (std::strcmp(mode, "kprobe") == 0) trigger_kprobe(kWarmups);
    else if (std::strcmp(mode, "uprobe") == 0) trigger_uprobe(kWarmups);
    else trigger_raw_tp(kWarmups);
    reset_count(s.count_map_fd);

    uint64_t t0 = now_ns();
    if (std::strcmp(mode, "kprobe") == 0) trigger_kprobe(kIters);
    else if (std::strcmp(mode, "uprobe") == 0) trigger_uprobe(kIters);
    else trigger_raw_tp(kIters);
    uint64_t t1 = now_ns();
    r.wall_ns = t1 - t0;
    read_count(s.count_map_fd, &r.count);

    nl_close(&s);
    return r;
}

static uint64_t run_baseline(const char *mode)
{
    uint64_t t0 = now_ns();
    if (std::strcmp(mode, "kprobe") == 0) trigger_kprobe(kIters);
    else if (std::strcmp(mode, "uprobe") == 0) trigger_uprobe(kIters);
    else trigger_raw_tp(kIters);
    return now_ns() - t0;
}

struct Case {
    const char *label;
    const char *bpf_o;
    const char *prog_name;
    const char *mode;
    const char *target;
    bool exact_count;   /* whether count==iters is the bit-exact invariant */
};

static int run_case(const Case &c)
{
    std::printf("\n=== %s ===\n", c.label);

    uint64_t base_ns = run_baseline(c.mode);
    TimedRun k = run_kernel(c.bpf_o, c.prog_name, c.mode, c.target);
    TimedRun n = run_native(c.bpf_o, c.prog_name, c.mode, c.target);

    double base_per_call    = (double)base_ns  / (double)kIters;
    double k_per_call_total = (double)k.wall_ns / (double)kIters;
    double n_per_call_total = (double)n.wall_ns / (double)kIters;
    double k_handler        = k_per_call_total - base_per_call;
    double n_handler        = n_per_call_total - base_per_call;
    double ratio            = (k_handler > 0) ? n_handler / k_handler : 0.0;

    std::printf("  baseline (no BPF):    %8" PRIu64 " ns total / %.1f ns per call\n",
                base_ns, base_per_call);
    std::printf("  kernel JIT attached:  %8" PRIu64 " ns total / %.1f ns per call "
                "(handler ~%.1f ns)  count=%" PRIu64 "\n",
                k.wall_ns, k_per_call_total, k_handler, k.count);
    std::printf("  native_lab attached:  %8" PRIu64 " ns total / %.1f ns per call "
                "(handler ~%.1f ns)  count=%" PRIu64 "\n",
                n.wall_ns, n_per_call_total, n_handler, n.count);
    std::printf("  native_lab / kernel handler ratio: %.2fx  %s\n",
                ratio, (k.count == n.count) ? "(count match)" : "(COUNT MISMATCH)");

    bool count_ok = c.exact_count ? (k.count == (uint64_t)kIters && n.count == (uint64_t)kIters)
                                   : (k.count >= (uint64_t)kIters && n.count >= (uint64_t)kIters);
    bool match = k.count == n.count;
    return (count_ok && match) ? 0 : 1;
}

int main(int argc, char **argv)
{
    /* vng exits the VM as soon as the --exec script returns; line-
     * buffered output via a serial console can drop the last block.
     * Unbuffer stdout/stderr so partial diagnostics still reach the
     * harness even on early exit / kernel panic. */
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);
    libbpf_set_strict_mode(LIBBPF_STRICT_ALL);

    Case all[] = {
        {"kprobe_getpid",
         "build/kprobe_getpid.bpf.o", "kprobe_getpid",
         "kprobe", "__x64_sys_getpid", true},
        {"uprobe_self",
         "build/uprobe_self.bpf.o", "uprobe_handler",
         "uprobe", "uprobe_target", true},
        {"raw_tp_sched_switch",
         "build/tracepoint_sched_switch.bpf.o", "raw_tp_sched_switch",
         "raw_tp", "sched_switch", false},
    };
    int rc = 0;
    if (argc > 1) {
        for (auto &c : all) {
            if (std::strcmp(argv[1], c.label) == 0) return run_case(c);
        }
        std::fprintf(stderr, "unknown case: %s\n", argv[1]);
        return 2;
    }
    for (auto &c : all) rc |= run_case(c);
    return rc;
}
