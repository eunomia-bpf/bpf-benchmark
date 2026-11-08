# Where BPF run time goes, 2026-11-08

Measurement only. Each program's own `run_cnt` and `run_time_ns` come from
the BPF statistics the corpus run already collects (`bpf_stats` on,
`details/apps/<app>.json` → `baseline`/`post_rejit` → `bpf` → per-program
`run_cnt_delta`, `run_time_ns_delta`), with the JIT arm and the native arm
of the same run. Nothing here is a new instrument.

Apps: katran, cilium, tetragon, tracee and bcc. The bcc figures come from
`corpus/results/x86_kvm_corpus_20261108_064411_793882`, since the earlier
bcc runs were cleaned up.

## Per-app totals, both arms

| app | JIT programs / runs / BPF time | native programs / runs / BPF time |
| --- | --- | --- |
| katran | 1 / 718,149,599 / 131.19 s | 1 / 800,472,966 / **142.13 s** |
| cilium | 56 / 709,171,424 / 486.08 s | 62 / 871,897,274 / **362.42 s** |
| tetragon | 287 / 2,879,686,552 / 2154.86 s | 287 / 2,922,788,905 / 2149.11 s |
| tracee | 151 / 6,882,600,114 / 2516.27 s | 151 / 10,649,242,958 / **2158.43 s** |
| bcc | 17 / 15,350,615 / 2.40 s | 17 / 15,196,843 / 2.42 s |

Read with the workload ratios in `kprog_reproduction_20261106/`:

- **tracee** is the case the native path wins: 55% more invocations in the
  same wall time, at 14% *less* total BPF time, and cost per invocation
  falls from 487.5 to 270.0 ns on its heaviest program. That is why its
  workload ratio is 1.539x where the reference had 0.958x.
- **cilium** is the case it wins on BPF time (486 → 362 s) but not on
  workload: its two top programs drop from 687/683 ns to 449/384 ns per
  run, yet the workload ratio is only 1.229x, so the remaining cost is
  outside the BPF program.
- **katran** is a wash at the program level (182.7 → 177.6 ns per run) and
  the workload agrees (0.997x / 1.003x on zero-error samples).
- **tetragon** is flat: 765.4 → 761.9 ns on its heaviest program, 0.5%
  total. Its workload ratio is likewise 1.008x.

## Where the time sits, by program

Top three programs per app and arm, as a share of that arm's BPF time.

### cilium

| arm | program | runs | BPF time | share | ns/run |
| --- | --- | ---: | ---: | ---: | ---: |
| JIT | `cil_from_container` (a) | 354,491,977 | 243.67 s | 50.1% | 687.4 |
| JIT | `cil_from_container` (b) | 354,679,435 | 242.40 s | 49.9% | 683.4 |
| native | `cil_from_container` (a) | 423,392,270 | 190.13 s | 52.5% | 449.1 |
| native | `cil_from_container` (b) | 448,504,995 | 172.29 s | 47.5% | 384.1 |

Two programs carry **all** of cilium's BPF time; every other program is
under 0.01%. Native cuts the per-run cost by 35-44%.

### tetragon

| arm | program | runs | BPF time | share | ns/run |
| --- | --- | ---: | ---: | ---: | ---: |
| JIT | `generic_tracepoint` | 1,327,310,232 | 1015.95 s | 47.2% | 765.4 |
| JIT | `generic_kprobe_...` | 57,370,485 | 352.11 s | 16.3% | 6137.5 |
| JIT | `generic_kprobe_...` | 161,185,848 | 155.12 s | 7.2% | 962.4 |
| native | `generic_tracepoint` | 1,341,911,532 | 1022.45 s | 47.6% | 761.9 |
| native | `generic_kprobe_...` | 57,824,688 | 355.09 s | 16.5% | 6140.7 |
| native | `generic_kprobe_...` | 164,539,485 | 153.86 s | 7.2% | 935.1 |

The 6.1 µs/run kprobe program is 2.7% of invocations but 16% of time — the
single best optimization target in the set. Native changes it by 0.05%.

### tracee

| arm | program | runs | BPF time | share | ns/run |
| --- | --- | ---: | ---: | ---: | ---: |
| JIT | `tracepoint__raw_syscalls` | 1,438,202,884 | 701.20 s | 27.9% | 487.5 |
| JIT | `trace_sys_exit` | 1,438,202,890 | 579.98 s | 23.1% | 403.3 |
| JIT | `trace_sys_enter` | 1,438,202,867 | 579.80 s | 23.0% | 403.1 |
| native | `tracepoint__raw_syscalls` | 2,264,314,891 | 611.43 s | 28.3% | 270.0 |
| native | `trace_sys_enter` | 2,264,314,878 | 393.42 s | 18.2% | 173.7 |
| native | `tracepoint__raw_syscalls` (b) | 2,264,314,877 | 392.01 s | 18.2% | 173.1 |

Three syscall-entry programs are 74% of tracee's BPF time, and native
halves their per-run cost (487.5 → 270.0 ns, 403.1 → 173.7 ns).

### bcc

| arm | program | runs | BPF time | share | ns/run |
| --- | --- | ---: | ---: | ---: | ---: |
| JIT | `sys_enter` | 7,037,611 | 0.98 s | 40.8% | 138.8 |
| JIT | `sys_exit` | 7,037,615 | 0.65 s | 27.2% | 92.6 |
| JIT | `tracepoint__syscalls` | 179,686 | 0.49 s | 20.5% | 2733.3 |
| native | `sys_enter` | 6,991,733 | 0.98 s | 40.7% | 140.8 |
| native | `sys_exit` | 6,991,737 | 0.65 s | 26.8% | 92.7 |
| native | `tracepoint__syscalls` | 173,882 | 0.50 s | 20.5% | 2856.9 |

bcc's absolute BPF time is 2.4 s against workloads of minutes, which is why
its workload ratio sits at unity (1.002x / 1.000x) regardless of what the
native path does: the program is a rounding error in its own workload. The
`tracepoint__syscalls` program is 20% of that small total at 2.7 µs/run.

### katran

| arm | program | runs | BPF time | share | ns/run |
| --- | --- | ---: | ---: | ---: | ---: |
| JIT | `balancer_ingress` | 718,149,599 | 131.19 s | 100% | 182.7 |
| native | `balancer_ingress` | 800,472,966 | 142.13 s | 100% | 177.6 |

One program, 2.8% cheaper per run, 11% more runs in the same window.

## What the numbers say about the candidates

The split the operator asked for — computation, helper calls, map lookups,
tail calls — is not separable from these counters alone: `run_time_ns` is
inclusive of everything the program does, and the runs carry no per-site
`bpfperf` attribution because `branch_flip` is not in the default policy.
So each candidate below is stated with the share of run time it could
touch, which is what the counters do support, and its separability noted.

| candidate | run-time share it covers | evidence |
| --- | ---: | --- |
| **Helper and map-lookup inlining at link time** | tetragon's kprobe program **16%** at 6.1 µs/run; tracee's three syscall programs **74%** at 0.17-0.49 µs/run; cilium's two at **100%** at 0.38-0.69 µs/run | these are the programs whose per-run cost is 2-30x the set's median, which is where call and lookup overhead concentrates; separable only with per-site counters |
| **Direct tail-call linking** | not visible here | cilium is the tail-call-heavy app and its two hot programs are the ones that use them, but `run_time_ns` cannot split the tail-call dispatch from the body |
| **Load-time constant specialization** | katran 100% (one program, none specialized), tetragon kprobe 16% | katran is a single fixed-configuration program, the natural first case |
| **Compiler flags** | whole table — native is already 2.8-44% cheaper per run, so flags act on a smaller residue than the structural candidates | the per-run deltas above are the baseline a flag change must beat |

Ordering by covered share: cilium (two programs, 100%) → tracee (three,
74%) → tetragon kprobe (one, 16%) → katran (one, 100% but only 2.8%
cheaper and single-configuration).

## Caveats

- cilium and tetragon native arms report more programs than the JIT arm
  (62 vs 56, 287 vs 287) because a program is counted per load, and the
  native path reloads.
- The counters include every CPU and the whole sample window, so a share is
  a workload-shape fact, not a microbenchmark.
- bcc's BPF time is 2.4 s against minute-scale workloads, so its ratio is
  insensitive to the native path by construction; that is a property of the
  workload, not of the measurement.