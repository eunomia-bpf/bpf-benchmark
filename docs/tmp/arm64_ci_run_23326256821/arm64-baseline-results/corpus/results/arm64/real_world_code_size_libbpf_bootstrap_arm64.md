# Real-World Code-Size Validation

- Generated at: `2026-03-20T02:19:51.589416+00:00`
- Inventory: `/home/runner/work/bpf-benchmark/bpf-benchmark/corpus/inventory.json`
- Runner: `/home/runner/work/bpf-benchmark/bpf-benchmark/micro/build/runner/micro_exec`
- Corpora: `libbpf-bootstrap`
- Runtimes: `llvmbpf`, `kernel`

## Summary

| Metric | Value |
| --- | ---: |
| Input artifacts considered | 15 |
| Artifact prepare/build succeeded | 15 |
| Program inventories succeeded | 15 |
| Programs discovered | 24 |
| Programs with both runtimes ok | 24 |
| Geomean native code-size ratio (llvmbpf/kernel) | 0.310x |

## Runtime Status

| Runtime | ok | error | timeout |
| --- | ---: | ---: | ---: |
| llvmbpf | 24 | 0 | 0 |
| kernel | 24 | 0 | 0 |

## Program-Level Results

| Repo | Artifact | Program | Section | BPF insns | llvmbpf native B | kernel native B | L/K ratio |
| --- | --- | --- | --- | ---: | ---: | ---: | ---: |
| libbpf-bootstrap | `examples/c/ksyscall.bpf.c` | `entry_probe` | `ksyscall/kill` | 66 | 0 | 376 | 0.000x |
| libbpf-bootstrap | `examples/c/ksyscall.bpf.c` | `tgkill_entry` | `ksyscall/tgkill` | 93 | 0 | 440 | 0.000x |
| libbpf-bootstrap | `examples/c/minimal_ns.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 21 | 0 | 208 | 0.000x |
| libbpf-bootstrap | `examples/c/usdt.bpf.c` | `usdt_auto_attach` | `usdt/libc.so.6:libc:setjmp` | 33 | 0 | 944 | 0.000x |
| libbpf-bootstrap | `examples/c/usdt.bpf.c` | `usdt_manual_attach` | `usdt` | 26 | 0 | 888 | 0.000x |
| libbpf-bootstrap | `examples/c/minimal.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 13 | 8 | 152 | 0.053x |
| libbpf-bootstrap | `examples/c/bootstrap.bpf.c` | `handle_exit` | `tp/sched/sched_process_exit` | 85 | 108 | 616 | 0.175x |
| libbpf-bootstrap | `examples/c/bootstrap.bpf.c` | `handle_exec` | `tp/sched/sched_process_exec` | 63 | 100 | 496 | 0.202x |
| libbpf-bootstrap | `examples/c/bootstrap_legacy.bpf.c` | `handle_exit` | `tp/sched/sched_process_exit` | 105 | 164 | 672 | 0.244x |
| libbpf-bootstrap | `examples/c/bootstrap_legacy.bpf.c` | `handle_exec` | `tp/sched/sched_process_exec` | 81 | 140 | 544 | 0.257x |
| libbpf-bootstrap | `examples/c/fentry.bpf.c` | `do_unlinkat` | `fentry/do_unlinkat` | 11 | 44 | 168 | 0.262x |
| libbpf-bootstrap | `examples/c/kprobe.bpf.c` | `do_unlinkat_exit` | `kretprobe/do_unlinkat` | 11 | 44 | 144 | 0.306x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uprobe_add` | `uprobe` | 8 | 32 | 104 | 0.308x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uprobe_sub` | `uprobe//proc/self/exe:uprobed_sub` | 8 | 32 | 104 | 0.308x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uretprobe_add` | `uretprobe` | 7 | 32 | 104 | 0.308x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uretprobe_sub` | `uretprobe//proc/self/exe:uprobed_sub` | 7 | 32 | 104 | 0.308x |
| libbpf-bootstrap | `examples/c/fentry.bpf.c` | `do_unlinkat_exit` | `fexit/do_unlinkat` | 13 | 56 | 176 | 0.318x |
| libbpf-bootstrap | `examples/c/lsm.bpf.c` | `lsm_bpf` | `lsm/bpf` | 12 | 44 | 120 | 0.367x |
| libbpf-bootstrap | `examples/c/kprobe.bpf.c` | `do_unlinkat` | `kprobe/do_unlinkat` | 19 | 96 | 208 | 0.462x |
| libbpf-bootstrap | `examples/c/task_iter.bpf.c` | `get_tasks` | `iter/task` | 45 | 164 | 344 | 0.477x |
| libbpf-bootstrap | `examples/c/tc.bpf.c` | `tc_ingress` | `tc` | 18 | 80 | 160 | 0.500x |
| libbpf-bootstrap | `examples/c/profile.bpf.c` | `profile` | `perf_event` | 45 | 200 | 384 | 0.521x |
| libbpf-bootstrap | `examples/c/sockfilter.bpf.c` | `socket_handler` | `socket` | 72 | 332 | 560 | 0.593x |
| libbpf-bootstrap | `examples/c/minimal_legacy.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 33 | 204 | 304 | 0.671x |

## Notes

- Each row is a single program selected from either a source-built or prebuilt real BPF object, not a handcrafted micro benchmark.
- `micro_exec list-programs` enumerates every libbpf-visible program in the object, and both runtimes are invoked with `--program-name` so multi-program objects are measured per program.
- `libbpf-bootstrap` inputs are compiled from source; the integrated BCF inputs are scanned directly from prebuilt objects under `corpus/bcf/`.
- The curated default set keeps the run focused on corpora that are already loadable by the current tooling: `libbpf-bootstrap`, `bcf/cilium`, `bcf/inspektor-gadget`, and `bcf/collected`.
