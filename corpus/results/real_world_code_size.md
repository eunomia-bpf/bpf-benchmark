# Real-World Code-Size Validation

- Generated at: `2026-03-07T01:05:48.958729+00:00`
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/corpus/inventory.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Repos: `libbpf-bootstrap`
- Runtimes: `llvmbpf`, `kernel`

## Summary

| Metric | Value |
| --- | ---: |
| Source files considered | 15 |
| Source builds succeeded | 15 |
| Program inventories succeeded | 15 |
| Programs discovered | 24 |
| Programs with both runtimes ok | 21 |
| Geomean native code-size ratio (llvmbpf/kernel) | 0.575x |

## Runtime Status

| Runtime | ok | error | timeout |
| --- | ---: | ---: | ---: |
| llvmbpf | 22 | 2 | 0 |
| kernel | 23 | 1 | 0 |

## llvmbpf Failures

| Error summary | Count |
| --- | ---: |
| llvmbpf compile failed: Instruction at pc=4 is going to jump to an illegal position 4 | 2 |

## kernel Failures

| Error summary | Count |
| --- | ---: |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/build/real_world_code_size/libbpf-bootstrap/lsm.bpf.o ... | 1 |

## Program-Level Results

| Repo | Source | Program | Section | BPF insns | llvmbpf native B | kernel native B | L/K ratio |
| --- | --- | --- | --- | ---: | ---: | ---: | ---: |
| libbpf-bootstrap | `examples/c/bootstrap.bpf.c` | `handle_exit` | `tp/sched/sched_process_exit` | 85 | 94 | 383 | 0.245x |
| libbpf-bootstrap | `examples/c/bootstrap.bpf.c` | `handle_exec` | `tp/sched/sched_process_exec` | 63 | 103 | 292 | 0.353x |
| libbpf-bootstrap | `examples/c/bootstrap_legacy.bpf.c` | `handle_exit` | `tp/sched/sched_process_exit` | 105 | 215 | 569 | 0.378x |
| libbpf-bootstrap | `examples/c/fentry.bpf.c` | `do_unlinkat` | `fentry/do_unlinkat` | 11 | 36 | 91 | 0.396x |
| libbpf-bootstrap | `examples/c/minimal.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 13 | 30 | 67 | 0.448x |
| libbpf-bootstrap | `examples/c/bootstrap_legacy.bpf.c` | `handle_exec` | `tp/sched/sched_process_exec` | 81 | 212 | 452 | 0.469x |
| libbpf-bootstrap | `examples/c/fentry.bpf.c` | `do_unlinkat_exit` | `fexit/do_unlinkat` | 13 | 55 | 102 | 0.539x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uprobe_add` | `uprobe` | 8 | 25 | 45 | 0.556x |
| libbpf-bootstrap | `examples/c/ksyscall.bpf.c` | `tgkill_entry` | `ksyscall/tgkill` | 84 | 180 | 315 | 0.571x |
| libbpf-bootstrap | `examples/c/minimal_ns.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 21 | 64 | 110 | 0.582x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uretprobe_add` | `uretprobe` | 7 | 24 | 41 | 0.585x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uretprobe_sub` | `uretprobe//proc/self/exe:uprobed_sub` | 7 | 24 | 41 | 0.585x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uprobe_sub` | `uprobe//proc/self/exe:uprobed_sub` | 8 | 28 | 45 | 0.622x |
| libbpf-bootstrap | `examples/c/task_iter.bpf.c` | `get_tasks` | `iter/task` | 45 | 159 | 239 | 0.665x |
| libbpf-bootstrap | `examples/c/kprobe.bpf.c` | `do_unlinkat_exit` | `kretprobe/do_unlinkat` | 11 | 39 | 58 | 0.672x |
| libbpf-bootstrap | `examples/c/ksyscall.bpf.c` | `entry_probe` | `ksyscall/kill` | 57 | 155 | 230 | 0.674x |
| libbpf-bootstrap | `examples/c/tc.bpf.c` | `tc_ingress` | `tc` | 18 | 73 | 100 | 0.730x |
| libbpf-bootstrap | `examples/c/kprobe.bpf.c` | `do_unlinkat` | `kprobe/do_unlinkat` | 19 | 83 | 98 | 0.847x |
| libbpf-bootstrap | `examples/c/profile.bpf.c` | `profile` | `perf_event` | 45 | 198 | 227 | 0.872x |
| libbpf-bootstrap | `examples/c/sockfilter.bpf.c` | `socket_handler` | `socket` | 72 | 336 | 363 | 0.926x |
| libbpf-bootstrap | `examples/c/minimal_legacy.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 33 | 185 | 178 | 1.039x |

## Notes

- Each row is a single program selected from a real `.bpf.o`, not a handcrafted micro benchmark.
- `micro_exec list-programs` enumerates every libbpf-visible program in the object, and both runtimes are invoked with `--program-name` so multi-program objects are measured per program.
- This report is still a first external-validity slice: it currently supports `libbpf-bootstrap` only, because the other harvested repos need extra build adapters or section/prog-type normalization.
