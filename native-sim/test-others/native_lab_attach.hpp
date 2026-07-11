/*
 * Standalone native_lab attach harness for test-others/.
 *
 * Mirrors the kop pipeline in runner/src/native_lab_runner.cpp but
 * targets EVENT-DRIVEN attach (kprobe / uprobe / raw_tracepoint) rather
 * than BPF_PROG_TEST_RUN. Code is deliberately duplicated rather than
 * shared via a library because the user requested test-others/ stay
 * standalone -- no dependency on the micro bench framework or its
 * cli_options/sample_result types.
 */
#ifndef NATIVE_LAB_ATTACH_HPP
#define NATIVE_LAB_ATTACH_HPP

#include <cstdint>
#include <string>

struct bpf_object;

struct NlSession {
    /* Stub program fd loaded with prog_type matching the attach target.
     * For kprobe/uprobe this is BPF_PROG_TYPE_KPROBE; for raw_tp it is
     * BPF_PROG_TYPE_RAW_TRACEPOINT. */
    int prog_fd = -1;
    /* Attach handle. For kprobe/uprobe this is the perf_event fd
     * (already ENABLEd, SET_BPF'd). For raw_tp it is the link fd from
     * bpf_raw_tracepoint_open. Both are closed by nl_close. */
    int attach_fd = -1;
    /* count_map (from the .bpf.o companion). Caller reads results via
     * this fd; bit-exact equality to kernel-JIT load proves both
     * runtimes hit the same kernel map. */
    int count_map_fd = -1;
    /* Companion .bpf.o object. Owned by the session; kept alive so the
     * maps the verifier allocated for it stay live (the same map fds
     * back native_lab side via fd_array + map_ptr literal patching). */
    bpf_object *companion = nullptr;
    /* Per-instance scratch paths for native-link inputs/outputs.
     * Allocated under /tmp; removed by nl_close. */
    std::string link_plan_path;
    std::string blob_path;
    std::string relocs_path;
    /* The /sys/kernel/debug/tracing/kprobe_events or uprobe_events
     * line we wrote; nl_close uses this to remove the probe. Empty
     * for raw_tp. */
    std::string probe_events_line;
    std::string probe_events_path;
};

/* `bpf_o_path` is the path to the companion .bpf.o (e.g.
 * `build/kprobe_getpid.bpf.o`); the sibling `.native.o` next to it is
 * the input to native-link. `prog_name` selects which BPF program
 * inside the .bpf.o we mirror (also the symbol name native-link looks
 * up inside the .native.o).
 *
 * `mode` is one of "kprobe" / "uprobe" / "raw_tp". `target` is the
 * attachment target -- kprobe sym name, uprobe func name (always
 * against /proc/self/exe in this POC), raw_tp name. `pid` is used for
 * uprobe only (kernel restricts the attach to one pid; -1 = any).
 *
 * Returns 0 on success, -1 on failure (prints diagnostic to stderr).
 */
int nl_load_and_attach(const char *bpf_o_path,
                       const char *prog_name,
                       const char *mode,
                       const char *target,
                       int pid,
                       NlSession *out);

/* uprobe convenience: like nl_load_and_attach with mode="uprobe", but
 * caller supplies the function's runtime address (e.g. &uprobe_target)
 * and the harness converts it to a file offset via /proc/self/maps
 * instead of relying on `nm` / debug symbols being present in the VM. */
int nl_load_and_attach_uprobe_at(const char *bpf_o_path,
                                 const char *prog_name,
                                 void *func_addr,
                                 int pid,
                                 NlSession *out);

void nl_close(NlSession *s);

#endif
