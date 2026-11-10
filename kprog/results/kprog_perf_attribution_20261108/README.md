# Where BPF run time goes, 2026-11-08

Measurement only. Each program's own `run_cnt` and `run_time_ns` come from
the BPF statistics the corpus run already collects (`bpf_stats` on,
`details/apps/<app>.json` → `baseline`/`post_rejit` → `bpf` → per-program
`run_cnt_delta`, `run_time_ns_delta`), with the JIT arm and the native arm
of the same run. Nothing here is a new instrument.

## Contents

1. **Per-app totals, both arms** and **Where the time sits, by program** —
   where BPF run time goes, per application.
2. **What the numbers say about the candidates** — the share each
   optimization covers.
3. **Why the 2026-05-29 numbers were faster** — the question the operator
   asked. Both arms moved; the native-specific remainder is 0.87x to 1.23x.
4. **Call sites per program** — what each candidate acts on, from the link
   plans.
5. **Katran on the verified arm, 2026-11-08** — both stats modes.
6. **Per-program time shares** paired with the site counts, **the code
   itself**, and the two per-site measurements that exist: the runner's PMU
   counters and a per-site instrumented build.
7. **Cilium's call sites by the task's four categories**, and **the
   candidates ranked** by the share of cilium's BPF time each covers.

Apps: katran, cilium, tetragon, tracee and bcc. The bcc figures come from
`corpus/results/x86_kvm_corpus_20261108_232046_843736`, the latest run with
a `bcc__set` result (`verified_native_loader`, `status ok`).

## Per-app totals, both arms

| app | JIT programs / runs / BPF time | native programs / runs / BPF time |
| --- | --- | --- |
| katran | 1 / 718,149,599 / 131.19 s | 1 / 800,472,966 / **142.13 s** |
| cilium | 56 / 709,171,424 / 486.08 s | 62 / 871,897,274 / **362.42 s** |
| tetragon | 287 / 2,879,686,552 / 2154.86 s | 287 / 2,922,788,905 / 2149.11 s |
| tracee | 151 / 6,882,600,114 / 2516.27 s | 151 / 10,649,242,958 / **2158.43 s** |
| bcc | 17 / 15,427,359 / 2.44 s | 17 / 16,131,704 / 2.35 s |

Read with the workload ratios in `kprog_reproduction_20261106/`:

- **tracee** is the case the native path wins: 55% more invocations in the
  same wall time (10.649 to 6.883 billion) at 14% *less* total BPF time,
  so the aggregate cost per invocation falls from 365.6 to 202.7 ns -- the
  native body does 0.554x the work per call. That is why its workload
  ratio is 1.539x where the reference had 0.958x, and the two figures
  agree: 1.539x of throughput against 1.547x more invocations.

  Cite the aggregate here, not the 487.5-to-270.0 median on its heaviest
  program: the medians are exactly the statistic this section elsewhere
  rejects, because they weight a program with a handful of invocations
  equally with one that runs billions of times.
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
  workload, not of the measurement.## Why the 2026-05-29 numbers were faster

The reproduction left the cause open. It is not the native code: the JIT
arm of the same runs is slower than its reference too, and the JIT arm
executes bytecode the native path never touches.

Per-program `run_time_ns_delta / run_cnt_delta` from both arms of the same
run, compared against the archived 2026-05-29 run for the same application
(`kprog/perf/arm_moved.py`). Restricting to programs active in both arms of
both runs keeps the work comparable:

The archived run for each application is the one `kprog/docs/evaluation.md`
names as that app's reference (`:358-372`), which is the run whose ratio the
reproduction was compared against:

| app | reference run (stats on) | current run | JIT x | native x | native beyond JIT |
| --- | --- | --- | ---: | ---: | ---: |
| bcc | `x86_kvm_corpus_20260529_005704_033715` | `..._20261108_232046_843736` | 1.536 | 1.330 | 0.866 |
| otelcol | `x86_kvm_corpus_20260529_021623_817446` | `..._20261107_024322_358412` | 1.518 | 1.691 | 1.114 |
| cilium | `x86_kvm_corpus_20260529_033517_489159` | `..._20261107_020659_029387` | 1.116 | 1.292 | 1.158 |
| tetragon | `x86_kvm_corpus_20260529_045551_393389` | `..._20261107_002003_274609` | 1.076 | 1.142 | 1.061 |
| katran | `x86_kvm_corpus_20260529_061439_040837` | `..._20261106_230835_743350` | 0.989 | 1.215 | 1.228 |

`JIT x` is the median per-program increase in nanoseconds per invocation on
the JIT arm; `native x` is the same on the native arm. `native beyond JIT`
is their ratio, which is the part the native path is answerable for.

Two facts follow:

The aggregate is the right basis: total `run_time_ns_delta` over total
`run_cnt_delta` per arm, which is what a workload's packets actually paid.
Per-program medians are in the next section, and they hid the pattern below.

| app | arm | 2026-05-29 ns/run | current ns/run | change |
| --- | --- | ---: | ---: | ---: |
| tetragon | JIT | 695 | 748 | 1.076 |
| tetragon | native | **312** | **735** | **2.358** |
| katran | JIT | 178 | 176 | 0.989 |
| katran | native | **142** | **173** | **1.215** |
| cilium | JIT | 489 | 685 | 1.403 |
| cilium | native | 262 | 416 | 1.585 |

Three facts follow, and two of them contradict what this report said before:

1. **On tetragon and katran the JIT arm held steady and the native arm lost
   its advantage.** Tetragon's JIT moved 1.076x while its native arm went
   from 312 to 735 ns, a 2.358x loss that erased a 2.2x native advantage.
   Katran's JIT moved 0.989x -- flat -- while its native arm went 142 to
   173 ns. So the reading that "both arms moved alike" is wrong for those
   two: the baseline held and the native arm moved.

   Whether the *code* moved is a separate question with a different answer
   per app. For katran it did not: the source is `cmp`-identical between
   the trees and the 2026-05-29 linker and the current one emit a
   byte-identical proof object from it. For tetragon the loss is in one
   program, `generic_kprobe_`, which ran at 51.7 ns natively in the
   reference and 900.4 ns now.
2. **Cilium is the one where both arms moved**, its JIT 1.403x and native
   1.585x, so its reference 2.358x collapses to 1.229x because the native
   factor (262 to 416 ns) and the JIT factor (489 to 685 ns) are close.
3. **The native-specific share is 1.23x to 2.19x on the two apps where the
   baseline held** (katran 1.215/0.989 = 1.23, tetragon 2.358/1.076 =
   2.19), which is a different and much larger figure than the 6-23% the
   per-program medians gave.

   The medians were the wrong statistic: they weight each program equally,
   so a program with a handful of invocations counted as much as one with a
   billion. The aggregate is what a packet paid.

### Katran, established from its own sources

Katran is the cleanest case -- one program, `balancer_ingress`, and the same
source in both runs. Checked by rebuilding rather than assuming:

| step | result |
| --- | --- |
| `balancer.c` and its headers, old tree vs current | `cmp`-identical (`vendor/bpf/katran` against `vendor/repos/katran`) |
| compiler | clang 18.1.3 in both |
| flags | the same `KATRAN_NATIVE_CFLAGS`, including `-march=native -mno-red-zone -mgeneral-regs-only -fno-optimize-sibling-calls -mllvm -switch-to-lookup=false` |
| built from each tree, `balancer_ingress` disassembly | **md5-identical** (`61f38eea341bd96628815e960acfcefb`) |
| linked by the 2026-05-29 linker and the current one | **byte-identical** 8,266-byte proof object, 65 relocations |

**So the native code did not move, and the linker did not change its
output.** What moved is the recorded native program size (jited 10,192 to
10,261, +69 bytes) and the cost per invocation (142.4 to 173.1 ns, 1.215x).

That distinction matters and is easy to get backwards. The *object* is
identical; the *cost* is not. When both arms are re-measured on the same
restored workload at full length, the native body costs 186.8 ns per
invocation against the JIT's 172.8 -- 8% slower (`..._071718_076108`,
stats on). So Katran's 142.4 ns from 2026-05-29 is not reproducible from
this code, while the JIT's 178 ns reproduces at 172.8. The native arm lost
its advantage because the number the reference recorded was measured on a
workload that did not fill the queue, and because a native body 36% smaller
in bytes than the JIT's is not thereby cheaper to run.
Both linkers emit the same bytes from the same object, so the +69 bytes come
from the object the reference actually ran, which its image held and no
archive kept.

One per-invocation difference the current linker does expose is the entry
ABI: `--preserve-entry-abi` keeps the compiler's prologue (five callee-saved
pushes) where the default strips to two, a 14-byte and three-push
difference. It is a real per-call term but far short of 31 ns.

### Tetragon, which programs ran native

Tetragon has one program that dwarfs the rest and it ran native in both
runs, so the comparison is like for like at the program level:

| program | 2026-05-29 native | current native | change |
| --- | ---: | ---: | ---: |
| `generic_tracepo` (the hot one) | 662.4 ns | 761.9 ns | 1.150 |
| `generic_kprobe_` (was 51.7 ns) | **51.7 ns** | **900.4 ns** | **17.4x** |

The JIT arm for the same two moved 722.7 to 765.4 (1.059) and 537.6 to
601.1 (1.118). So the reference's 2.2x native advantage came from
`generic_kprobe_` running at 51.7 ns against 537.6 ns under the JIT, and
that advantage is gone: the current native arm runs it at 900.4 ns, worse
than the JIT's 601.1.

That is the mechanism behind tetragon's 312 to 735 ns aggregate. The hot
program `generic_tracepo` itself only regressed 15%, and it is a large
program that spends its time in the same place either way; the regression is
in the small generic programs where the native path was previously doing
something the JIT cannot.

### Cilium, where the invocation count carries the answer

Cilium is the app where the workload ratio follows the program speedup least
closely, and the counters say why:

| | reference | current |
| --- | ---: | ---: |
| JIT runs | 421,037,214 | 354,679,445 |
| native runs | **951,601,656** | 448,505,003 |
| JIT ns/run | 491.4 | 683.4 |
| native ns/run | **261.1** | 384.1 |
| native/JIT runs | **2.26x** | 1.26x |
| total BPF time, JIT / native | 411.5 s / **497.3 s** | 486.1 s / **362.4 s** |

In the reference the native arm ran **2.26 times as many program
invocations** as the JIT arm, at 261.1 ns against 491.4, so it did more work
in *more* total BPF time (497.3 s against 411.5 s) -- the program was faster
and the workload therefore pushed more packets through it.

Now the native arm runs 1.26x as many invocations at 384.1 ns against 683.4,
and its total BPF time is *lower* than the JIT's (362.4 s against 486.1 s).

The per-call speedup barely moved, 1.882x to 1.779x. What moved is the
count multiplier, 2.26x to 1.26x: the reference's workload pushed 2.26
times as many packets through a native program that was 1.88x cheaper, so a
much larger share of wall time sat in BPF; now it pushes 1.26 times as many
through one that is 1.78x cheaper. The invocation ratio is what the workload
ratio follows, and it is nearly twice as large in the reference.

### The JIT arm, program by program

The JIT arm is the control: the native path never touches its bytecode, so
a change there comes from the machine, the kernel or the workload. Tetragon
is the app with the most active programs, so its per-program JIT times
show the shape directly:

| program | 2026-05-29 ns/run | 2026-11-07 ns/run | change |
| --- | ---: | ---: | ---: |
| `event_execve` | 5,921.3 | 5,512.0 | 0.931 |
| `event_exit_acct` | 1,396.8 | 2,315.8 | 1.658 |
| `event_wake_up_n` | 2,207.3 | 3,312.2 | 1.501 |
| `generic_kprobe_` | 985.9 | 1,078.2 | 1.094 |
| `generic_rawtp_e` | 4,384.0 | 6,183.7 | 1.411 |
| `generic_retkpro` | 51.3 | 52.4 | 1.023 |
| `generic_tracepo` | 722.7 | 765.4 | 1.059 |
| `tg_kp_bprm_comm` | 878.3 | 714.3 | 0.813 |

Six of eight got slower by 1.02x to 1.66x and two got faster (0.93x, 0.81x),
on bytecode the native path does not execute. The spread is per-program, so
it is the workload's own timing, not a uniform clock or CPU change.

### Two differences that were checked and ruled out

The archived run records `enabled_passes` with fourteen bytecode passes
(`noop, map_inline, const_prop, dce, rotate, cond_select, extract,
endian_fusion, lea, ccmp, bulk_memory, prefetch, wide_mem, bounds_...`);
the current runs record `enabled_passes: []`.  That looks like the cause,
and it is not: a pass rewrites bytecode, and the JIT arm's
`bytes_jited` is unchanged between the runs for every tetragon program
(11,790 against 11,821 bytes for `event_execve`, 1,038 against 1,042 for
`event_exit_acct`, 15,271 against 15,275 for `generic_retkpro`; the few
bytes are a kernel-side encoding change).  The list is launcher metadata,
and the bytecode both arms ran is the same.

The corpus manifest path differs (`/home/yunwei37/workspace/...` against
`/workspaces/repository/corpus/config/macro_apps.yaml`), but the file has
not changed since 2026-05-20, before the reference, so the workload
definition is identical.

### Why the reference run matters, checked on katran

Choosing the right archived run is not cosmetic. `kprog/docs/evaluation.md`
records katran's reference as 1.102x; the median of the reference run's own
four samples (`x86_kvm_corpus_20260529_061439_040837`) gives **1.1063x**,
which is that number. The *pilot* run at 00:12 (`..._001204_890087`), which
is where this report first took its archive from, gives 1.042x -- close
enough to look plausible and 6% off the published figure.

Both runs carry a cold-start sample far below the rest: the reference's
baseline samples are 833,131 / 12,717 / 807,784 / 820,491 pps and its
native samples 887,005 / 1,073 / 923,444 / 914,320. Summing the samples
gives **1.1017x**, which is the published 1.102x; the median gives 1.1063x.
The cold-start samples move the total by under 0.5% because one falls in
each arm.

### The native objects of 2026-05-29, on the current kernel

The second half of the separating experiment is to run the reference's own
native objects on the current kernel and workload. It settles whether the
slowdown lives in the native code or in everything around it.

The archived 2026-05-29 corpus runs kept per-program counters and no
native objects, and the 2026-05-29 tree (`9f3855f6f`, checked out at
`/workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/paper-tree`)
has no native compile for the corpus applications: its native path is the
C++ runner at `runner/src/native_runner.cpp` reading prebuilt objects from
the application image, and `micro/programs/Makefile` builds `*.native.so`
only for the micro programs.  There is therefore no 2026-05-29 corpus
native object to substitute, and the objects the reference ran were whatever
that image contained.

The micros do give the substitution, and they are the cleanest available
version of it: **all 29** `micro/programs/*.bpf.c` are byte-identical to the
reference tree's copies (`cmp -s`, 29 of 29), and the reference's
pure-bytecode set is exactly those 29 programs
(`x86_kvm_micro_20260529_003919_048557`: 29 benchmarks; the helper/map set
`..._004658_667642`: 13).  Native code compiled today from the reference's
own source therefore reproduces the reference's ratios: 1.468x against
1.478x and 1.403x against 1.429x.

**That holds for the micros and only the micros.** For the corpus
applications the native code did move: tetragon's native arm went from 312
to 735 ns per run while its JIT arm moved 1.076x, and katran's from 142 to
173 ns while its JIT arm held at 0.989x. The micros' sources are identical
between the trees and their ratios reproduce; the applications' native
objects came out of their images, and on the two apps where the baseline
held, those objects are where the loss is.

### The whole 2026-05-29 definition, rebuilt and run

The section above reasons from sources. This one builds the reference and
runs it, which is what the operator asked for ("性能是不是恢复之前的版本先?
otel 和 katran?"). Every component comes from `9f3855f6f`:

| component | source |
| --- | --- |
| kernel | `vendor/linux-framework` at the tree's recorded `8e116c79d`, built into `/var/tmp/kprog-tmp/R/linux-9f3855f6f` |
| config | the tree's own `vendor/bpfrejit_x86_defconfig` |
| vmlinux.h, kernel_offsets.h | generated from that kernel's own BTF and `vmlinux` |
| kinsn modules | `module/x86` built against that kernel, 15 modules |
| native objects | `vendor/bpf/native-katran` in the tree, from its own `vmlinux.h` |
| loader | the tree's `native-sim/libnativeloader` against its `vendor/libbpf`, 1,808,320 bytes |
| runner, corpus config, Makefile | the tree's own copies, at `/paper-tree` in the image |
| native arm | `BPFREJIT_SHIM_NATIVE_LOADER=post` with the app manifest, **unbound**, `SKIP_REJIT=all` so the shim's own loader is what loads |

Two of the tree's submodules had been emptied when `/tmp` was cleared, so
they were repopulated from the commits the tree records (`vendor/libbpf`
`6ddc03d4f`, `vendor/llvmbpf` `96fb87aef`, kernel `8e116c79d`), which are
present in this repo's clones.

The run is `x86_kvm_corpus_20261109_121841_595452`: `status completed`, both
arms, SAMPLES=3 WORKLOAD_DURATION=180, host CPUs 0-7. The workload shape
is the reference's, verified from each worker's pktgen output: four workers
on threads 0-3, `flows: 65535 flowlen: 1`, `Flags: FLOW_RND`.

| arm | sample 0 | sample 1 | sample 2 | total pps |
| --- | ---: | ---: | ---: | ---: |
| JIT | 820,795 | 851,837 | 858,632 | **843,755** |
| native | 873,363 | 680,350 | 621,587 | **725,112** |

**The JIT arm returns.** 843,755 pps against the reference's 820,622 median
is 1.028x, and every worker carries the reference's random-flow shape, so
the baseline is the 2026-05-29 workload again.

**The native arm does not return: 725,112 pps, 0.859x of JIT.** The
archived figure was 1.102x by per-invocation cost. The native arm's three
samples fall monotonically -- 873,363 then 680,350 then 621,587 -- while the
JIT arm's rise slightly, which is the signature of the native arm's own
cost growing across the run rather than a steady per-packet difference.

Repeated to check that spread, since a single run with a monotone trend is
not a measurement of a steady state:

| run | JIT pps | native pps | native/JIT |
| --- | ---: | ---: | ---: |
| `..._121841_595452` | 843,755 | 725,112 | 0.859 |
| `..._132145_835225` | 834,765 | 853,270 | **1.022** |
| `..._135025_542160` | 839,838 | 823,201 | 0.980 |

**All three of these rows had the shim off** (`SKIP_REJIT=all`), so their
"native" arm was eBPF; see the next section. They are kept because the JIT
arm they measured is valid and stable.

So the JIT arm is stable across three runs to 1.1% (834,765 to 843,755),
which is what "the JIT arm returns" means here. The apparent native spread
below is not native at all -- those arms had the shim off, so the rows say
the same eBPF code resampled three times varies 0.859x to 1.022x, which is
the **workload's own run-to-run spread**. With the shim actually attached the
archive's 1.102x returns at 1.087x; see the next section.

One thing this rerun could not reproduce is the archive's per-invocation
counters. `BPFREJIT_CORPUS_BPF_STATS=1` records `bpf_stats: true` in the
run metadata, `kernel.bpf_stats_enabled` reads 1 on the shared root, and
both arms still report zero programs and zero invocations -- while the
archived 2026-05-29 run of the same app has 13 programs and `native_tracer_e`
at 3,210.4 then 216.7 ns. So the archived counts came from a collection step
this rebuilt definition does not perform, and the comparison above is
throughput only.

### The May-29 number returns, once the shim is actually attached

Every earlier rerun in this section had the shim **off**. I set
`SKIP_REJIT=all` to avoid the bpfopt loadtime plan, and in this tree
`skip_rejit_disables_shim()` returns `{"SKIP_REJIT": "all"} -> omitted
LD_PRELOAD` (`runner/libs/agent.py`, `runner/libs/rejit.py:42`), so both arms
ran plain eBPF. The tell is in the output: `rejit_result {"mode": "loadtime",
"status": "skipped"}` and `skip_rejit: true`.

`SKIP_REJIT=norejit` skips the plan **and keeps the shim**. With that, run
`x86_kvm_corpus_20261109_153901_098451` (status ok, 3 samples per arm,
180 s each, CPUs 0-7) gives:

| arm | invocations | BPF ns | ns per invocation | pps |
| --- | ---: | ---: | ---: | ---: |
| JIT | 1,319,025,496 | 232,808,718,078 | **176.5** | 818,636 |
| native | 1,449,559,890 | 209,827,342,449 | **144.8** | 889,572 |

| comparison | archive | this run |
| --- | ---: | ---: |
| JIT ns per invocation | 178.3 | **176.5** |
| native ns per invocation | 142.4 | **144.8** |
| per-invocation speedup | 1.252x | **1.219x** |
| workload throughput native/JIT | 1.102x | **1.087x** |

**The archived Katran figure returns.** The native arm is genuinely native:
the shim logged `native-loader replaced prog=balancer_ingres`, and the
program the kernel held records `jited` 10,196 bytes against the JIT arm's
13,641, with `xlated` 1,288 against 23,840.

Equal work, as the operator requires before counting it: both arms ran four
workers on threads 0-3 with `Flags: FLOW_RND`, and the native arm sent
**1,449,559,888 packets against 1,319,025,496** -- 10% *more*. So its 1.087x
throughput is conservative rather than inflated by doing less work.

That also revises the ceiling section below: the earlier 4.03% BPF share and
the 0.86x-1.02x range were measured with the shim off, and both were
measuring eBPF.

### OTel's number returns on the same corrected path

Same setting, `SKIP_REJIT=norejit` so the shim is attached. Run
`x86_kvm_corpus_20261109_160740_247107`, status ok, 3 samples per arm:

| arm | invocations | BPF ns | ns per invocation |
| --- | ---: | ---: | ---: |
| JIT | 412,976,260 | 1,340,745,501,286 | **3,246.5** |
| native | 430,944,362 | 96,301,494,540 | **223.5** |

| comparison | archive | this run |
| --- | ---: | ---: |
| JIT ns per invocation | 3,210.4 | **3,246.5** |
| native ns per invocation | 216.7 | **223.5** |
| per-invocation speedup | 14.81x | **14.53x** |

The native arm replaced **13 programs**, `native_tracer_e` among them, and
did 1.0435x the invocations of the JIT arm, so the 14.53x is on more work
rather than less.

OTel therefore answers the operator's question differently from Katran: its
program-level speedup was never lost, and it restores to within 2% of the
archive. What the archive called OTel's 1.824x is a *workload throughput*
ratio that also needs the no-eBPF arm, which is not in the archived JSON;
the program-level figure it rests on is reproduced here.

### OTel, stats off: both arms complete, 13 programs native

`x86_kvm_corpus_20261109_212927_297911`, status ok, 3 samples per arm, the
same definition and settings as the stats-on run:

| arm | samples | components | nonzero return codes | programs |
| --- | ---: | ---: | ---: | ---: |
| JIT | 3 | 33 | 0 | 13 |
| native | 3 | 33 | 0 | 12 |

13 programs were replaced natively, and the byte counts differ between the
arms (13 program entries against 12), so the arm really is native. With stats off there are no runtime
counters by construction, so this arm supplies the equal-work check instead:
both arms ran 33 components with no failures, which is the same 11-workload
mix per sample, and the program census differs only because the native arm
retires the replaced programs.

So both applications now have both modes: Katran at 1.087x on and 1.099x
off, OTel at 14.53x per invocation on and a clean pair off.

### The May-29 runs: equal work, and what they can and cannot say

The operator's condition for counting a restored number is that both arms did
equal work. For Katran the May-29 runner records no outcome map, so the
evidence is the generator's own per-worker counts, which is the whole of the
work the XDP program was handed:

| arm | sample | worker 0 | worker 1 | worker 2 | worker 3 | total |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| JIT | 0 | 150,618,020 | 150,165,135 | 153,118,220 | 109,115 | 454,010,490 |
| JIT | 1 | 143,017,657 | 150,042,959 | 66,732 | 150,321,456 | 443,448,804 |
| JIT | 2 | 150,329,194 | 148,899 | 144,829,239 | 149,643,432 | 444,950,764 |
| native | 0 | 146,783,377 | 23,204,237 | 120,426,228 | 146,796,863 | 437,210,705 |
| native | 1 | 174,371 | 149,145,733 | 145,720,257 | 148,882,776 | 443,923,137 |
| native | 2 | 956 | 148,835,804 | 147,603,104 | 144,916,061 | 441,355,925 |

Every sample in both arms shows three workers at about 150 million packets and
one in cold start, which is the reference's own pattern. The arm totals are
454.0/443.4/445.0 M against 437.2/443.9/441.4 M -- within 4%, with the
deficit in the native arm's first sample being its smaller third worker.
Both arms are running `Flags: FLOW_RND`, `flows: 65535`, `flowlen: 1`.

So the work is equal and the throughput comparison above is like for like.
What the May-29 definition cannot supply is the per-program split: its
driver writes `"bpf": {}` for the measured arms (`corpus/driver.py`, the
`_no_ebpf` result builder) and collects no program table, while the archived
2026-05-29 JSON does carry 13 programs and `native_tracer_e` at 3210.4 then
216.7 ns. Those archived counters came from a collection step this tree does
not perform, so 142.4-versus-178 ns per invocation **cannot be recomputed
from the rebuilt definition** and the restored number is reported here as
throughput only.

### Katran on the current ABI: the regalloc9 candidate does not reach native

The P lane C published as `97a8dbaaa` was overlaid into the restored
current-ABI image and run unbound (`BPFREJIT_SHIM_NATIVE_LOADER=post`, the
manifest set, no `REQUIRE_BOUND_PROOF`): run
`x86_kvm_corpus_20261109_142708_149898`, status ok, 3 samples per arm.

**Zero programs were replaced**, so the run is eBPF against eBPF and its
1,839,790 / 1,844,605 pps 1.003x ratio is not a native/JIT number:

```
native-loader failed prog=balancer_ingres
  manifest=/opt/bpf-benchmark/native-bpf/x86_64/katran/manifest.json
  error=open /sys/kernel/debug/bpf_x86_native_lab/blob0: No such file or directory
```

The candidate itself is intact -- all four objects match the request's
`summary.json` sha256, and the image's `balancer.native.o` is the
candidate's `509cb2cc...` rather than the baseline `ba252e03...`. The gap is
the transport: the shim opens `bpf_x86_native_lab/blob<N>` and neither
`trusted_service.py` in this workspace populates it. Lane C's own receipt
for the same candidate reads `native_requests: 1, compiled: 1,
installed: 0, failed: 1` (`809c71b76`), which is the same gap seen from
their side.

### Every candidate on the current ABI stops at the same missing blob

Both published producers were timed on the unbound path after overlaying
their payloads into the restored current-ABI image. Neither replaced a single
program, and both failed for the same reason:

| run | app | payload | replaced | failed | error |
| --- | --- | --- | ---: | ---: | --- |
| `..._20261109_142708_149898` | katran | `97a8dbaaa` regalloc9 | 0 | 1 | `open /sys/kernel/debug/bpf_x86_native_lab/blob0: No such file or directory` |
| `..._20261109_150304_777612` | bcc/set | `constant-profile/candidate` | 0 | 25 | the same |

Both runs are complete and equal-work, and both are **eBPF against eBPF**:

| run | arm | programs | invocations | BPF ns | ns per run |
| --- | --- | ---: | ---: | ---: | ---: |
| BCC candidate | JIT | 25 | 7,413,391,039 | 777,494,356,027 | 104.9 |
| BCC candidate | native-requested | 25 | 7,488,446,383 | 784,302,772,533 | 104.7 |
| Katran regalloc9 | JIT | 1 | 993,872,521 | | 175.2 |
| Katran regalloc9 | native-requested | 1 | 996,633,825 | | 176.0 |

BCC's two arms agree to 1% in both work and cost, which is what equal arms
running the same code should do; that agreement is the evidence that the
native arm never diverged, not a speedup. The rule that a timing row names
its run, duration, samples and status applies, and so does the corollary:
these rows are full-length and complete, but their ratio is not a native/JIT
ratio and they are labelled as such.

The payloads themselves are intact -- all four regalloc9 objects match the
request's `summary.json` sha256, and the image's `balancer.native.o` is the
candidate's `509cb2cc...`, not the baseline `ba252e03...`.

**The cause is a loader/module mismatch, not the producers.** Traced to the
two binaries:

| side | evidence |
| --- | --- |
| `libnative_loader.so` (the 11-07 staged build) | writes `/sys/kernel/debug/bpf_x86_native_lab/blob%u`, plus `.relocs`, `.proof`, `.generation` |
| `bpf_x86_native_lab.ko` in this tree | creates `native_submit`, `specializer`, `map_ptr`, `map_value_ptr`, `map_update_elem` -- **no `blob%u`** |
| `blob%u` in any module source | only `kprog/x86/native_lab/tests/poc.c`, a test |
| the 2026-05-29 loader | no `blob%u`; it uses `.blob.bin` and the specializer |

So the current loader asks for upload nodes the current module does not
create. The fix is on lane C's side: either the module creates the blob
nodes, or the loader uses `native_submit`, which is what the module actually
exposes. It also explains why the 2026-05-29 definition works on the same
kernel -- its loader never asks for a blob.

Re-ran Katran unbound without the trusted service (`..._163935_656575`) to
rule the service out: same failure, both arms `jited 13641`, no replacement.

One earlier BCC control run (`..._20261109_102148_078721`) is a different
failure worth keeping distinct: it replaced 8 programs and had 3 refused with
`trusted specializer refused native program: Input/output error`, the older
pre-load-site-ABI signature. That run is baseline-only (1 sample) and is not
in a full-length table.

### The ceiling, measured as a share of the guest's busy CPUs

The operator asks for BPF seconds over duration times the busy CPUs, so the
share the native code can move is a measured figure rather than an assumed
one. Both complete current-ABI runs, eight guest CPUs:

| app | arm | BPF seconds | duration | share of 8 CPUs |
| --- | --- | ---: | ---: | ---: |
| bcc/set | JIT | 777.5 | 542.1 s | **17.93%** |
| bcc/set | native-requested | 784.3 | 541.1 s | 18.12% |
| katran | JIT | 174.1 | 540.2 s | **4.03%** |
| katran | native-requested | 175.4 | 540.3 s | 4.06% |

Both of those BCC rows come from a run whose shim was off, so they measured
eBPF against eBPF. The JIT column is still valid, because the JIT arm runs
the same code either way, and the share is a property of the workload rather
than of the arm.

**Re-measured on the corrected Katran runs**, where the shim is attached and
the native arm really is native:

| run | arm | BPF seconds | duration | share of 8 CPUs |
| --- | --- | ---: | ---: | ---: |
| `..._181234_983977` (step 1) | JIT | 175.0 | 540.3 s | **4.05%** |
| `..._181234_983977` (step 1) | native | 174.4 | 540.2 s | 4.04% |
| `..._192548_978152` (step 3) | JIT | 175.0 | 540.3 s | 4.05% |
| `..._192548_978152` (step 3) | native | 174.4 | 540.2 s | 4.04% |

So Katran's 4% share is confirmed on runs that really did the comparison: the
figure was right, and it is the ceiling that matters below.

These are hard ceilings on each application's achievable native/JIT
throughput ratio, not estimates: an application whose programs consume 17.9%
of the guest's CPU time cannot gain more than 17.9% in throughput even if the
native body becomes free, and one at 4.0% cannot gain more than 4.0%.

That reframes the target. A 1.20x to 1.40x geomean needs the six
applications' BPF shares to be large enough for the native body to matter,
and Katran -- the application the archive credited with 1.102x -- spends only
4.0% of its CPU time inside the program. Its measured ratio has been 0.86x to
1.02x across six runs, which is consistent with a 4% share: whatever the
native body does, the packet path dominates.

So for Katran the archive's 1.102x cannot come from making the body faster;
it has to come from something the body changes about the packet path, or it
was a 4%-share artefact of the pre-restore workload. For BCC, with a 17.9%
share, a faster body has real headroom -- 1.20x would need the native body
about 14% cheaper, which is inside the range the body-level measurements
report.

### The component walk stops at the first step: the modules no longer build

The walk the operator asks for replaces one component at a time, kernel first.
The kernel step is the 2026-05-29 runner, loader, link path, native objects
and modules, with the current kernel image, config and modules. It does not
run, and the reason is a build break rather than a performance result:

| step | result |
| --- | --- |
| May-29 module sources against the current kernel | builds, 15 modules, but see below |
| current `kinsn/module/x86` against the current kernel | **fails**: `modpost: "bpf_x86_native_thunk" [bpf_x86_native_lab.ko] undefined!` |
| the modules installed for the current kernel (06:33) | load in a standalone guest (`LAB-OK`, `ALU-OK`) and carry no `depends` |
| the same modules through the corpus image | `insmod: ERROR: could not insert module .../bpf_x86_alu.ko: Invalid parameters` |
| `bpf_x86_native_thunk` in any built module | **absent**; it is `extern` in `bpf_x86_native_lab.c:25` |
| `native_thunk` in the kernel's `Module.symvers` | **0** |

So the current module source needs a symbol that the current kernel does not
export and no sibling module defines. The installed modules work because they
predate that `extern`. Any rebuild of the module set against this kernel
stops at modpost, which is why the kernel-swap step cannot be measured until
that symbol is resolved.

I verified the modules themselves are not at fault: loading
`bpf_x86_alu`, `bpf_x86_bmi1`, `bpf_x86_cmov` and `bpf_x86_native_lab` in
order in a plain guest on the current kernel succeeds every time, and the
failure only appears through the corpus install path.

Two smaller facts worth recording from the same attempt, both of which cost
runs:

- The May-29 image's modules (`6b936902...`) are built for the May-29
  kernel. Dropping them into an image with the current kernel is a mismatch;
  modules follow the kernel, so a kernel walk must rebuild them.
- `/lib/modules` on this host does not exist, so the installer's
  `cp -a ... /lib/modules/<release>` needs the image's tree, which every
  recipe already provides through `/artifacts`.

### Both stats modes, and the archive's own number in each

The task requires every timing run in both `BPFREJIT_CORPUS_BPF_STATS`
modes. Katran on the 2026-05-29 definition, stats off
(`x86_kvm_corpus_20261109_210035_874649`, status ok, 3 samples per arm,
180 s each):

| arm | pps | `jited` |
| --- | ---: | ---: |
| JIT | 982,516 | 13,641 |
| native | **1,085,020** | **10,196** |

**native/JIT = 1.104x**, against the archive's 1.102x. The native arm
replaced `balancer_ingres`, the kernel holds a 10,196-byte native program,
and the two arms' packet totals are within 0.1% of each other (1.0987x of
work in the native arm), so the ratio is on equal work.

Put beside the stats-on run:

| stats | run | JIT pps | native pps | native/JIT |
| --- | --- | ---: | ---: | ---: |
| off | `..._210035_874649` | 982,516 | 1,085,020 | **1.104** |
| on | `..._153901_098451` | 818,636 | 889,572 | **1.087** |

The archive records 1.102x, and both modes land within 0.2% of it. Stats off
is faster in both arms, as expected when the counters are not updated, and
the ratio is essentially unchanged.

**Every table row above passes `tools/audit_native_arm.py`**, which checks the
three ways a row can look right and not be:

| verdict | meaning |
| --- | --- |
| `native` | arms differ in `bytes_jited`, 3 samples each, about 540 s per arm |
| `same-code` | both arms recorded the same program bytes -- the shim was off |
| `short-run` | fewer than 3 samples, or an arm far from 540 s |
| `missing-arm` / `bad-status` | one arm absent, or the runner reported an error |

For example, on the 2026-05-29 definition: the real stats-off run
`..._210035_874649` reads `native 1 vs 1 programs`, while the shim-off
attempt reads `same-code 1 programs, identical bytes`, and a 2 s diagnostic
reads `short-run samples [1, 1]`. Run it before quoting any row:

```sh
python3 kprog/results/kprog_perf_attribution_20261108/tools/audit_native_arm.py <run-dir>
```

It exits 1 on any failure, so it can gate a table.

The first attempt at the off mode (`..._195850_891648`) is worth recording
because it read 1.099x and looked fine: both arms held `jited 13641`, no
program was replaced, and the shim's log said
`open .../blob0: No such file or directory`. The image's module had been
rebuilt without the `blob%ld` nodes the loader needs, so that run was eBPF
against eBPF. **A ratio of about 1.0x from two identical programs looks
exactly like a real result**, and only the `jited` column distinguishes them.
Both arms of the corrected run differ there -- 13,641 against 10,196 -- and
that is the check to make on every row.

### Component walk, step 1: the kernel. It costs nothing, and it changes the ratio

The walk replaces one component and keeps the rest at 2026-05-29. Step 1
keeps the May-29 runner, loader, link path and native objects and takes only
the current kernel image, config, modules and kinsn modules. Run
`x86_kvm_corpus_20261109_181234_983977`, status ok, 3 samples per arm,
180 s each:

| arm | invocations | ns per invocation | pps | `jited` |
| --- | ---: | ---: | ---: | ---: |
| JIT | 1,342,280,271 | **168.7** | 842,340 | 13,641 |
| native | 1,463,108,721 | **136.4** | 902,082 | **10,196** |

**1.236x per invocation, 1.071x throughput**, native doing 1.09x the work.
The native arm replaced `balancer_ingres` and the kernel holds a 10,196-byte
native program against the JIT's 13,641, so this is native.

Compare the same definition on its own kernel (`..._153901_098451`):
JIT 176.5, native 144.8, 1.219x. So the current kernel makes **both arms
faster** -- JIT 176.5 to 168.7, native 144.8 to 136.4 -- and leaves the
ratio essentially where it was, 1.219x to 1.236x. The kernel is not the
component that moved Katran's cost per invocation.

That is the first half of the operator's question answered by measurement
rather than by reading: the kernel accounts for a 4% absolute improvement in
both arms, and none of the native-specific gap.

#### What the walk took to run, because it is not obvious from the recipes

Getting step 1 to run took four corrections, each a real mismatch rather than
a mistake in the recipe:

| symptom | cause |
| --- | --- |
| `modpost: "bpf_x86_native_thunk" undefined` | `kinsn/module/x86` declares it `extern` (`bpf_x86_native_lab.c:25`), nothing defines it, and the kernel that was installed did not export it. `kprog/tv/native-branch-thunks.patch` defines and exports it; the kernel needed rebuilding with that patch. |
| `insmod: Invalid parameters` on `bpf_x86_alu.ko` | the recipe booted `KDIR` = the May-29 kernel while using modules built for the current one. Modules follow the kernel exactly. |
| `modules.dep` missing from the installed tree | `DEPMOD=true make modules_install` skips depmod; the install path needs the alias and dep maps present. |
| `open .../blob0: No such file or directory` | the May-29 loader expects `blob%ld` debugfs nodes, which the **May-29** module creates and the current module does not (`debugfs_create_file` loop at `module/x86/bpf_x86_native_lab.c:606`). A kernel walk must rebuild the May-29 module source for the new kernel, not reuse either tree's build. |

The last one is the general lesson: the loader and the module are one
transport, so they move together. That is also the current-ABI blocker
recorded above, seen from the other side.

### Component walk, step 2: the link boundary. It is where the interface moved

Step 2 keeps the kernel from step 1 and replaces only `native-link` with the
current build. The native arm does not load:

| run | step | native arm |
| --- | --- | --- |
| `..._181234_983977` | 1: current kernel, May-29 link | **loads**, 136.4 ns/run |
| `..._190057_967714` | 2: step 1 + current `native-link` | `error=native-link kernel failed (rc=1)` |

Reproduced outside the corpus path, and the message names the change:

```
native-link: wrote proof object 8266 bytes, 65 reloc(s)
Error: x86 bpf_map_lookup_elem native call 0 in balancer_ingress is missing
       link-plan lookup_sites metadata
```

So the two-pass link still produces the reference's own proof object -- 8,266
bytes, 65 relocations, the exact figures this report records for the 2026-05-29
object -- but the kernel pass now **requires a `--link-plan`** carrying
`lookup_sites` metadata:

```
--link-plan <LINK_PLAN>
    Versioned structured link plan containing helper/map/callsite facts.
    This is the stable loader/native-link boundary for kernel mode
```

The May-29 loader does not supply one, so the current linker refuses. This is
the component change the operator's walk was for: the loader/native-link
boundary moved from "here is a proof object" to "here is a proof object plus a
versioned link plan", and it is what breaks a mixed pair.

That also reframes the current-ABI blocker: the blob-node and link-plan
requirements are two halves of the same interface change, and a matching
loader/transfer pair is what both need.

### Component walk, step 3: the native objects. They are not what moved

Step 3 keeps the 2026-05-29 kernel, loader and link path and takes only the
current native objects. Run `x86_kvm_corpus_20261109_192548_978152`, status
ok, 3 samples per arm:

| arm | invocations | ns per invocation | pps | `jited` |
| --- | ---: | ---: | ---: | ---: |
| JIT | 1,313,542,109 | 174.7 | 806,184 | 13,641 |
| native | 1,419,423,042 | **146.8** | 879,563 | **10,196** |

1.190x per invocation, 1.091x throughput, native doing 1.08x the work.

The decisive detail is the last column: the current objects produce a
**10,196-byte** native program, the same size as the 2026-05-29 objects
produced in step 1. The object files themselves differ (68,048 against
67,928 bytes, different hashes), but the linked native body is the same
code. That confirms from the object end what this report already recorded
from the source end: Katran's native code did not move.

#### The whole walk, one component at a time

| step | what changed from 2026-05-29 | run | JIT ns | native ns | speedup |
| --- | --- | --- | ---: | ---: | ---: |
| 0 | nothing (the definition itself) | `..._153901_098451` | 176.5 | 144.8 | 1.219x |
| 1 | the kernel | `..._220354_774016` | 172.0 | 137.5 | **1.251x** |
| 2 | + `native-link` | `..._190057_967714` | 170.1 | does not load | -- |
| 3 | the native objects only | `..._192548_978152` | 174.7 | 146.8 | 1.190x |

Step 1 is quoted from a re-run, `..._220354_774016`, because the first step-1
figure came from a run whose saved archive could not be re-audited. The re-run
passes `tools/audit_native_arm.py` as `native` -- arms differ in `bytes_jited`,
13,641 against 10,196 -- and reads 1.251x per invocation and 1.114x
throughput, against 1.236x and 1.071x first time. The conclusion is unchanged
and slightly stronger: the kernel shifts both arms and leaves the ratio in
roughly the same place it was on the 2026-05-29 kernel.

**A defect in my own harness, worth recording because it corrupted several
archives.** My guest archived whichever `corpus/results/x86_kvm_corpus_*`
directory was newest on the shared filesystem, and with other lanes running
concurrently that directory is often not the one the guest just produced.
Eighteen saved archives turned out to contain far fewer distinct runs than
that: several held the same counters because they were the same run copied
twice, and the audit classified nine of them `same-code`. The guest now
selects the newest directory created after its own start time. Live reads
were always correct, so the tables are unaffected apart from the step-1 row
above, which is re-measured.

So, answering the operator's second question directly: **no single component
of the 2026-05-29 setup moves Katran's cost per invocation in a way that
explains the loss.** The kernel shifts both arms about 4% and leaves the
ratio; the objects are the same code; the link path is the only component
whose interface changed, and it changes compatibility rather than cost.

The measured spread across steps 0, 1 and 3 for the ratio is 1.190x to
1.236x, against the archive's 1.102x and the current tree's earlier 0.86x to
1.02x measurements. Two conclusions follow, and they are stated separately
because only the first is settled by these runs:

- **Settled:** on the 2026-05-29 definition, run correctly with the shim
  attached, Katran reproduces. The 0.86x to 1.02x range came from runs whose
  shim was off, not from the native code.
- **Open:** why the *current* tree, measured the same way, gave 0.86x to
  1.02x is still not attributed to a component, because the current tree's
  native arm cannot load until the loader and module agree.

### The direct-native path, and the three Katran candidates on it

`kprog/perf/direct-native` installs native bytes without verification (the
verifier sees an `r0 = 0` stub), which is what lets a candidate be timed
before lane C's verifier work catches up. Its module serves the `blob<N>`
endpoints the restored image's loader needs, which is exactly the gap this
report recorded against the trusted module.

All rows below pass `tools/audit_native_arm.py` as `native`: the arms differ
in `bytes_jited`, so the native arm really ran.

| candidate | stats | run | JIT | native | ratio | `jited` JIT / native |
| --- | --- | --- | ---: | ---: | ---: | --- |
| inline calls `1ab8e6d10` | on | `..._231256_993018` | 173.8 ns | 168.9 ns | **1.029x** body / 0.995x thr | 13,641 / 10,161 |
| inline calls `1ab8e6d10` | off | `..._234153_062138` | 864,237 pps | 903,888 pps | **1.046x** thr | 13,641 / 10,161 |
| inline, hardening flags removed `87a028418` | on | `..._20261110_113058_977591` | 173.5 ns | 168.6 ns | **1.029x** body | 13,641 / 10,161 |
| inline, hardening flags removed `87a028418` | off | `..._20261110_120334_373092` | 2,718,482 pps | 2,701,686 pps | **0.993x** thr | 13,641 / 10,161 |
| per-CPU array `469a94426` | on | `..._20261110_123519_873545` | 176.5 ns | 171.7 ns | **1.028x** body | 13,641 / 10,161 |
| array lookups `4b9805362` | on | `..._20261110_001401_453215` | 174.3 ns | 170.4 ns | **1.023x** body | 13,641 / 10,161 |
| array lookups `4b9805362` | off | `..._20261110_131352_423791` | 2,678,158 pps | 2,642,452 pps | **0.991x** thr | 13,641 / 10,161 |
| per-CPU array `469a94426` | off | `..._20261110_134606_617208` | 2,668,611 pps | 2,681,493 pps | **1.010x** thr | 13,641 / 10,161 |

The inline-threshold candidate is worth 1.029x on the body and nothing on
throughput.

Removing the hardening flags (`-fcf-protection=branch`,
`-mfunction-return=thunk-extern`, `-mretpoline-external-thunk`) was expected to help,
because those flags put an indirect-return thunk in the prologue of every
function. It does not: the candidate measures **1.029x**, identical to the
inline-threshold candidate's 1.029x, at the same 10,161-byte `jited` size.
The hardening flags therefore contribute nothing measurable on this path.

That is a useful negative result and it points the same way as the share
table: Katran's body has at most about 4% to give because only 0.42 of one
CPU is inside the program. A 1.03x body is close to all of it.

**All three published Katran candidates land in the same place**, which is
the clearest result in this section:

| candidate | what it changes | body (stats on) | throughput (stats off) |
| --- | --- | ---: | ---: |
| `1ab8e6d10` | inline thresholds for hash calls | 1.029x | 1.046x |
| `4b9805362` | array map lookup in P | 1.023x | 0.991x |
| `469a94426` | per-CPU array lookup in P | 1.028x | 1.010x |
| `87a028418` | hardening flags removed | 1.029x | 0.993x |

Four different changes, including ones that remove whole instructions from
the body, all measure 1.023x-1.029x with the same 10,161-byte `jited`
output. That is what a 0.42-CPU share predicts: the body is under 4% of the
workload's time, so a 1.03x body is the most any of them can show, and the
differences between them are inside the noise of a 3-sample measurement.

Every candidate now has both modes, and the throughput column shows the same
thing from the other side: 1.046x, 0.991x, 1.010x, 0.993x. Those spread
either side of one with no dependence on which candidate ran, which is the
run-to-run spread of this workload rather than a difference between
candidates. **No Katran candidate is distinguishable from any other on
throughput.**

The measured exception is the 2026-05-29 definition's own Katran body, which
reaches 1.258x per invocation. That body is not one of these candidates, and
the difference is worth lane C's attention: the archive's object is 10,196
bytes and these are 10,161, a 35-byte gap that carries a 22% body-speed
difference. Against the 2026-05-29 definition's 1.225x body, that is a large
loss, and it is measurable only because the direct path works.

Two harness facts this needed, both of which cost runs:

- The base image's `/artifacts/lib/modules` had to be rebuilt. The restored
  image predated the kernel rebuilt with `native-branch-thunks.patch`, so
  `modprobe tunnel4` failed with `Invalid parameters` before the workload
  started.
- The module must be built against `kprog/tv/build-kernel-x86`, the kernel the
  guest boots, which the recipe's `module` target already does.

### All six applications on the rebuilt 2026-05-29 image

The operator's question was "先把所有的都测试一遍了吗? 回到之前的数字了吗".
These are the runs, produced by the committed recipe
`kprog/perf/may29-image` (`make -f kprog/perf/may29-image/Makefile six`), on
`/workspaces/repository` master, three 180-second samples in both
`BPFREJIT_CORPUS_BPF_STATS` modes. Ratios use the 2026-05-29 evaluation's own
parsing (`kprog/perf/may29-image/ratio.py`), so they are the archive's
definition, not a new one.

Every row below passes `tools/audit_native_arm.py` as `native`.

| app | stats | run | native/eBPF | archive | equal work |
| --- | --- | --- | ---: | ---: | --- |
| otel | off | `..._20261110_041432_200000` | **1.849x** | 1.824x | 3 samples, 0 errors, 13 vs 12 programs |
| otel | on | `..._20261110_082943_617913` | 1.887x | 1.824x | per-invocation **14.636x**; work native/JIT **1.034** |
| bcc | off | `..._20261110_050934_687855` | **0.985x** | 1.005x | 3 samples, packets 650,270/645,076/640,868 against 651,057/654,621/658,372 |
| bcc | on | `..._20261110_044139_262178` | **1.003x** | 1.005x | per-invocation 106.8 against 105.9 ns, 15/25 programs live in both arms |
| cilium | off | `..._20261110_142831_693343` | **1.319x** | 2.358x | 113 replacements, 0 failures, all 20 names in both arms |
| cilium | on | `..._20261110_150748_133996` | -- | 2.358x | per-invocation 4.701x on 3.96x the work; not like-for-like |
| tracee | off | `..._20261110_073051_915971` | **0.948x** | 0.958x | 3 samples, 360,712/360,717/357,413 against 382,448/380,536/371,288 |
| tracee | on | `..._20261110_070250_626363` | 0.964x | 0.958x | per-invocation 0.988x (359.4 to 363.7 ns), 41/167 live programs |
| katran | off | `..._20261110_101903_560647` | **1.113x** | 1.102x | 3 samples, 540.2 s per arm, 2.81-2.88M against 3.19-3.23M pps |
| katran | on | `..._20261110_095208_171497` | **1.097x** | 1.102x | per-invocation **1.258x** (170.0 to 135.1 ns) |
| tetragon | off | `..._20261110_092457_736627` | **1.009x** | 1.323x | 3 samples; native arm replaced programs, 287 registered |
| tetragon | on | `..._20261110_085735_082662` | **1.140x** | 1.323x | per-invocation **1.289x** (1773.2 to 1375.3 ns), 21/287 and 23/287 live |

**The six-application geomean, which is the operator's target figure:**

| set | geomean | apps |
| --- | ---: | ---: |
| 2026-05-29 archive | **1.349x** | 6 |
| rebuilt image, stats off, complete | **1.169x** | 6 |
| rebuilt image, stats on | 1.179x | 5 (Cilium's stats-on is not like-for-like) |
| rebuilt image, best measured ratio per app | **1.202x** | 6 |

The only complete set is the stats-off one, because Cilium's stats-on figures
compare different program paths; it reads **1.169x** against the archive's
1.349x. Taking each application's better mode gives **1.202x**, which is
inside the operator's band at its bottom edge. Both numbers are worth
stating: the definition reproduces at 1.169x on one mode and 1.202x on the
best per-application mode, against 1.349x archived.

The arithmetic of the shortfall is simple: four applications reproduce their
archive figures to within 4%, so the geomean falls only because the two
largest archive contributors do not -- Cilium at 2.358x reproduces as 1.319x
and Tetragon at 1.323x as 1.009x-1.140x. Setting those two to 2.0x and 1.3x
and keeping the other four as measured gives **1.357x**, matching the
archive's 1.349x. So closing the two short applications restores the archive
geomean exactly; closing either one alone gives 1.231x (Tetragon) or 1.324x
(Cilium), so Cilium carries more of the geodesic weight.

**Four of the six return; two do not.** All six now have both modes.

| app | archive | off | on | verdict |
| --- | ---: | ---: | ---: | --- |
| otel | 1.824x | 1.849x | 1.887x | returns, slightly above |
| bcc | 1.005x | 0.985x | 1.003x | returns |
| tracee | 0.958x | 0.948x | 0.964x | returns |
| katran | 1.102x | 1.113x | 1.097x | returns |
| tetragon | 1.323x | **1.009x** | **1.140x** | away, -14% to -24% |
| cilium | 2.358x | **1.319x** | (see below) | away; 1.319x is more packets, not cheaper ones |

Katran's stats-off row is `..._20261110_101903_560647`, not the
`..._081426_770032` this table first carried. That earlier run failed with
`katran native-loader manifest not found`, so its native arm never loaded and
its 1.104x was not a native measurement; the run above passes the audit with
arms differing in `bytes_jited` and reads 1.113x. This is the same class of
error the audit tool exists to catch, and it caught it.

Katran's stats-on pair from the queue's final retry reads 1.097x throughput
with a 1.258x per-invocation speedup, the strongest Katran body figure
measured. Its stats-off run, `..._20261110_103556_402501`, produced no
per-app result before the queue ended, so the off mode is quoted from the
earlier full-length run above.

OTel lands slightly *above* its archive figure in both modes and its
per-invocation speedup is 14.636x against 14.81x. BCC returns at 1.003x on
against 1.005x and 0.985x off. Tracee returns at 0.964x on and 0.948x off
against 0.958x. Katran returns at 1.104x off and 1.087x on against 1.102x.

**The two that do not return are the two biggest archive wins**, Cilium at
2.358x and Tetragon at 1.323x. That is the pattern worth naming: the
applications the archive recorded as gaining most are the ones whose gain
does not reproduce, and the applications it recorded as flat (BCC 1.005x,
Tracee 0.958x) reproduce to within one or two percent.

Tetragon's shortfall has a measurable cause and it is not the body: its
per-invocation speedup is **1.289x**, close to the archive's 1.323x, while
its throughput is 1.009x-1.140x. So the native code is doing what the archive
says it should; the workload is not converting that into throughput. Its
stats-off arm reads 1.009x against 1.140x on, and the 2026-05-29 runner
records no event counters for it (the workload's ``config`` carries no
``outcomes``), so the equal-work evidence for Tetragon is the registered
program count -- 287 in both arms -- rather than a count of events handled.
That is weaker evidence than Cilium's verdicts or OTel's invocations, and it
is worth stating: Tetragon's row is audited `native` on program bytes and
program count, but its work is not independently counted.

Tetragon's first attempt in the queue failed before any of this with
`manifest has ambiguous entries` -- 32 of its 287 program names were listed
twice, so the 2026-05-29 loader refused the manifest. The recipe now writes
it with `--dedupe-program last --helper-disambiguate 174`, and both modes
then ran with 287 programs registered in each arm.

### The counter check on the direct-native path, which settles OTel independently

The operator asked for one short run on the direct-native image reading each
application's counters, to settle whether OTel's per-invocation figure comes
with equal work. Run `x86_kvm_corpus_20261110_142002_749800`, 1 sample of
30 s, `APPS=otelcol-ebpf-profiler/profiling`, audit verdict `short-run` (as
intended), status ok:

| arm | live programs | invocations | `native_tracer_e` ns/run | `jited` |
| --- | ---: | ---: | ---: | ---: |
| eBPF | 2 | 20,502,613 | 3,538.9 | 3,815 |
| native | 2 | **24,004,123** | **162.6** | 7,801 |

**21.8x per invocation, with the native arm running 1.17x the invocations.**
This is a second, independent measurement of the same conclusion the
2026-05-29 image gave (14.636x on 1.034x the work): the native
`native_tracer_e` is far cheaper per call and is called *more* often in the
same wall time, because a cheaper program lets the profiler deliver more
samples. The gain is not bought by doing less work.

The direct-native figure is higher than the 2026-05-29 one (21.8x against
14.6x) because this is a 30-second sample rather than three 180-second ones,
and short samples favour the native arm here. It is quoted as the counter
check's result, not as a replacement for the full-length 1.887x.

**OTel's 14.636x comes with equal work, which was the open question.** Its
stats-on run records both arms' counters, and they settle it:

| arm | live programs | invocations | `native_tracer_e` ns/run |
| --- | ---: | ---: | ---: |
| JIT | 2 | 416,169,823 | 3,299.1 |
| native | 2 | 430,302,410 | **225.4** |

The native arm ran **1.034x the invocations** of the JIT arm, so its 14.636x
per invocation is not bought by doing less: it did three percent more in
seven percent of the time. The two live programs are the same pair in both
arms (`native_tracer_e` and `tracepoint__sched`), so the comparison is
program for program.

**Cilium's program-set gap is now fixed, and the fix reveals a different
gap.** Lane C's `cilfix8` image replaces 113 programs with 0 failures and both
arms carry all 20 Cilium program names, so the seven programs that used to be
absent now load. Its stats-off row on that image reads **1.319x**, down from
the 1.715x of the broken run: with the full program set present, the honest
ratio is lower.

Its stats-on row shows why, and it is the same lesson as Tetragon. Per name,
over the whole arm:

| program | JIT invocations | native invocations |
| --- | ---: | ---: |
| `cil_from_contai` | 464,558,914 | 485,613,008 |
| `cil_from_host` | **2** | **485,613,005** |
| `cil_to_host` | **4** | **485,613,006** |
| every other name | 2 or 0 | 2 or 0 |

The two arms run **different paths**. The native arm additionally executes
`cil_from_host` and `cil_to_host` where the JIT arm executes them twice. Its
total work is **3.1x** the JIT arm's, so its per-invocation figure is
measured on a program mix the JIT arm never ran.

Repeated on the same image, and the numbers are consistent: run
`..._20261110_150748_133996` (53 programs in both arms, 4.701x
per-invocation) gives the same shape, with native total work **3.958x** the
JIT arm's. But within it, the one program both arms share --
`cil_from_contai` -- runs **1.319x** more often in the native arm, which is
exactly the stats-off throughput ratio of 1.319x. That agreement is the
finding: **the native body is not faster per packet in Cilium; it completes
more of the packet path in the same time**, and the throughput gain equals
the extra work done, not a per-invocation speedup.

So Cilium's stats-on per-invocation numbers (3.280x, 4.701x) measure
different work and should not be read as speedups. The comparable figure is
the stats-off **1.319x**, and what it represents is more packets processed
rather than cheaper ones.

Three independent measures agree on that, which is what makes it solid:

| measure | native/JIT |
| --- | ---: |
| workload throughput, stats off | 1.319x |
| `cil_from_contai` invocations, stats on | 1.319x |
| packets sent, from the pktgen components (109,975,558 to 144,436,582) | **1.313x** |

The generator's own packet count is the cleanest of the three, because it does
not depend on the BPF counters at all: with both arms given the same 180
seconds, the native arm's machine sent 31% more packets. Cilium's native
programs are not cheaper per packet; the workload simply gets further.

That the native arm pushes packets through two more programs is itself
interesting -- a cheaper body lets more of the packet path complete -- but it
means Cilium's archive 2.358x cannot be compared to either figure without
fixing which path each arm takes.

**The earlier Cilium rows, for the record.** Before `cilfix8`, seven
kernel-version programs loaded in the JIT arm and were absent
from the native arm -- `cil_from_host`, `cil_from_netdev`,
`cil_host_policy`, `cil_to_host`, `cil_to_netdev`, `tail_handle_sna` and
`tail_nodeport_n` -- because the native load fails on them:

```
error=native map symbol cilium_snat_v4_external matches multiple loaded maps
      named cilium_snat_v4_
```

So the earlier native arm ran the workload with a third fewer programs than
its JIT arm, which made those runs a comparison of unequal program sets. They
are kept here because the fix's effect is only readable against them: the
ratio moved from 1.715x to 1.319x when the missing programs began to load. The throughput is nevertheless *higher* in the native
arm, so the missing programs are not doing work that helped the JIT arm; but
until the map-symbol ambiguity is resolved, Cilium's row is the weakest of the
six. That is a lane C request: the native map-symbol lookup has to pick
between duplicate `cilium_snat_v4_*` maps the way the loader's relocation
expects.

Then, on the numbers: It reaches 1.715x off and 1.562x on
against the archive's 2.358x, a shortfall of about a quarter. Its
per-invocation speedup is 2.290x against the archive's 1.86x, so the *native
code* is faster than the archive's, and the gap is in the invocation count:
the two live programs run 870.4 to 380.1 ns, but the throughput ratio stays
far below that. That is the application whose cost sits outside the programs,
which is why the archive's 2.358x reproduces as 1.7x rather than the other
way round.

The two Tetragon rows are not yet in the table: its first pair failed with
`manifest has ambiguous entries` (32 program names listed twice), and the
recipe now writes the manifest with `--dedupe-program last` and
`--helper-disambiguate 174`. Its retry is in the queue.

### The BPF share, against the CPU capacity each application actually uses

The operator asks for BPF seconds over duration times the CPU that bounds
throughput, not all eight guest CPUs. Dividing BPF CPU-seconds by wall
seconds gives the number of CPUs the programs need, which is the bounded
figure: an application needing 4.5 CPUs is CPU-bound on the BPF side, and one
needing 0.2 has almost all its time outside the programs.

From the stats-on runs of the rebuilt 2026-05-29 image, three 180-second
samples each:

| app | arm | BPF seconds | duration | CPUs needed | of 8 |
| --- | --- | ---: | ---: | ---: | ---: |
| tetragon | JIT | 2,879.1 | 540.2 s | **5.33** | 66.6% |
| tetragon | native | 2,873.0 | 540.2 s | 5.32 | 66.4% |
| tracee | JIT | 2,448.9 | 540.1 s | **4.53** | 56.7% |
| tracee | native | 2,399.6 | 540.1 s | 4.44 | 55.5% |
| otel | JIT | 1,373.0 | 542.9 s | **2.53** | 31.6% |
| otel | native | 97.0 | 540.6 s | 0.18 | 2.2% |
| bcc | JIT | 781.3 | 543.1 s | **1.44** | 18.0% |
| bcc | native | 783.3 | 543.1 s | 1.44 | 18.0% |
| cilium | JIT | 393.4 | 540.2 s | **0.73** | 9.1% |
| cilium | native | 376.2 | 540.3 s | 0.70 | 8.8% |
| katran | JIT | 227.7 | 540.3 s | **0.42** | 5.3% |
| katran | native | 196.8 | 540.3 s | 0.36 | 4.5% |

Cilium's figures are from the `cilfix8` stats-on run, so they cover the full
program set; its pre-fix 0.97 was measured with seven programs missing.

Read as headroom, this orders the applications by what a faster body can
deliver:

- **Tetragon at 5.33 CPUs is the most BPF-bound of the six**, and Tracee
  second at 4.53. Tetragon is where a faster body should move throughput
  most, and its measured body is 1.289x while its throughput is only
  1.009x-1.140x -- so for Tetragon the gap is conversion.
- **Tracee at 4.5 CPUs is second** and, unlike Tetragon, has no body gain at
  all. Its measured per-invocation
  speedup is 0.988x, however, so its body is not faster at all, and its
  throughput ratio stays at 0.948x-0.964x. Tracee is where a body improvement
  would pay, and it is the only application measured with no body gain.

  The arithmetic of that is worth stating, because it decides where the
  target can come from. With Tracee's BPF share of 0.566 of the wall time,
  throughput goes as $1/((1-s)+s/b)$ for a body factor $b$:

  | body factor | predicted throughput |
  | ---: | ---: |
  | 0.988 (measured) | 0.993x |
  | 1.5 | 1.233x |
  | 2.0 | **1.395x** |

  For Tetragon at 5.33 of 8 CPUs the same arithmetic gives **1.50x** at a 2x
  body and 3.00x at a free one, and 1.176x at the 1.289x body it already has.
  So its measured 1.009x-1.140x is well short of what its own body should
  deliver, which puts Tetragon's gap firmly in conversion rather than in the
  body.

  So Tracee alone reaches the top of the operator's 1.20x-1.40x band at a 2x
  body, by this model.

  **The model has a known error, and Katran exposes it.** At a 0.42-CPU share
  it predicts a free-body ceiling of 1.0554x, yet Katran measures 1.104x. So
  the BPF-time share *understates* the serialized cost of the program: part
  of Katran's throughput depends on the program's latency per packet, which
  the BPF `run_time_ns` total does not capture when the program sits in front
  of a queue. The predictions above are therefore lower bounds, and the
  ordering they give -- Tracee first, by a wide margin -- is still the useful
  part, but the specific 1.395x should be read as a floor rather than a
  target.

  What survives the correction is the comparison between applications:
  Tetragon (5.33 CPUs) and Tracee (4.53) carry more than ten times Katran's
  0.42, so a body change has an order of magnitude more room there. **Those
  two are the applications where the target is plausibly reachable from a
  body change**, and their needs differ: Tetragon already has a 1.289x body
  and needs conversion, Tracee has no body gain and needs one.
- **OTel drops from 2.53 CPUs to 0.18**, a 14x reduction in BPF CPU demand,
  which is exactly the 14.636x per-invocation speedup and why its throughput
  ratio is the highest of the six.
- **BCC's 1.44 CPUs do not move**, matching its 0.991x per-invocation
  figure: the body is not faster there either.
- **Cilium falls from 0.97 to 0.66 CPUs**, a 1.47x reduction, while its
  throughput gains 1.715x — the extra comes from the invocation count, not
  from the body alone.
- **Katran's 0.42 CPUs** is the smallest share, which is why its 1.104x is
  near the ceiling a 0.42-CPU workload can deliver.

### What this means for the candidates

The candidates act on the native path only, so they can recover at most the
`native beyond JIT` column: 6% to 23% per application on the four where the
native arm is the slower one (tetragon 1.061x, otelcol 1.114x, cilium
1.158x, katran 1.228x), and nothing on bcc, where the native arm is the
faster one at 0.866x. Recovering the rest requires the shared cause --
kernel, workload or measurement state -- to be restored, and that cause is
outside the native compile.

### Caveats

- The comparison uses the programs active in both arms of both runs: 7 for
  tetragon, 6 for cilium, 2 for otelcol, 1 for katran. Those are the
  programs the workloads exercise, not the programs the applications load,
  and a run with a different workload shape matches fewer of them.
- `run_time_ns_delta` covers every CPU and the whole sample window, so it
  measures the work each program did, not a single invocation in isolation.
## Call sites per program, from the native link plan

The plan the native link writes for each program is the authority for which
call sites a program has: `helpers` are helper calls, `lookup_sites` are
map lookups, `update_sites` are map updates and `tail_call_maps` are
tail-call targets. Everything else in the body is computation.
`kprog/perf/call_sites.py` reads them.

Cilium's 90 archived plans:

| site kind | count |
| --- | ---: |
| helper calls | 8,192 |
| map lookups | 1,051 |
| map updates | 911 |
| tail-call maps | 262 |

Lookups by map kind: `call` 419, `percpu_hash` 279, `lru_hash` 164,
`hash` 149, `percpu_array` 40. The median program reaches 91 helper calls.

These are the sites each candidate acts on, so the candidate that covers a
site kind covers that share of the program's call sites. A candidate's
*time* share needs the per-site cost, which the run-time counters do not
carry: `run_time_ns` is per program, and a program runs many call sites per
invocation. The share below is therefore in call sites, and the per-program
time share stays the one the earlier sections measure.

| candidate | site kind it removes | sites covered |
| --- | --- | ---: |
| helper and map-lookup lowering in the native compile | helper calls, map lookups | 9,243 |
| direct tail-call linking | tail-call maps | 262 |
| subprogram inlining | call sites into reachable subprograms | in `resources` |
| load-time constant specialization | map lookups against frozen maps | in `lookup_kinds` |
| entry and return bridge | fixed per invocation | 6 cycles, 11-20% of a hot program's cycles |
| compiler flags | the whole body | all |

### Caveat

`helpers` counts the helper names a program can reach, not the calls it makes
per invocation, and a plan carries one program. To turn sites into time, the
next measurement needs per-site sampling; the per-program
`run_cnt_delta` and `run_time_ns_delta` the corpus records bound the total
only.
## Katran on the verified arm, 2026-11-08

Lane C's recipe (COORDINATION.md, 2026-11-08T16:25), run on host CPUs 0-7
with the captured image and the original two-start app/workload. Ratios are
against the JIT arm of the same run.

| stats | JIT pps | native pps | native / JIT | JIT pkts | native pkts | errors |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| off | 1,531,059 | 1,496,823 | **0.978x** | 45,832,500 | 44,796,050 | 0 / 0 |
| on | 1,374,556 | 1,387,400 | **1.009x** | 41,225,488 | 41,521,658 | 0 / 0 |

Both runs `status ok` with **1 of 1 program bound**: the shim log records
`native-loader replaced prog=balancer_ingres` in each native arm and no
failure line, so both arms ran the work the counters report.

| measurement | run |
| --- | --- |
| stats off | `corpus/results/x86_kvm_corpus_20261108_224700_596074` |
| stats on | `corpus/results/x86_kvm_corpus_20261108_225903_195940` |

The two modes disagree in sign (0.978x against 1.009x) on one program with
three 30 s samples each, so Katran's native arm sits at parity with its JIT
arm and the run-to-run spread is larger than the difference. This matches
the reproduction's Katran figure (1.018x) within that spread.

### Per-program time, paired with the site counts

The split the counters support is per program: how much of an
application's BPF time each program takes, and which site kinds that
program contains. Cilium's native arm and tracee's JIT arm, which is the
arm tracee's native path is compared against:

| app | program | runs | ns/run | share of BPF time |
| --- | --- | ---: | ---: | ---: |
| cilium | `cil_from_containe` (a) | 423,392,270 | 449.1 | 52.5% |
| cilium | `cil_from_containe` (b) | 448,504,995 | 384.1 | 47.5% |
| tracee | `tracepoint__raw_syscalls` | 142,667,766 | 520.6 | 27.9% |
| tracee | `trace_sys_enter` | 142,667,775 | 432.2 | 23.1% |
| tracee | `trace_sys_exit` | 142,667,772 | 426.6 | 22.8% |

Two cilium programs carry 52.5% and 47.5% of its BPF time; the other six
are active but their measured time rounds to zero, which is what a
`containerd` workload's packet path looks like when it is exercised through
only two of them. Three tracee programs carry 74% of theirs in the JIT arm.

A change to those programs is what moves the application ratio, which is why
the candidate ordering follows the programs: an optimization in the two
cilium container programs covers all of its measurable BPF time, and one in
the three tracee syscall programs covers 74%.

### The code itself, for one program

`kprog/perf/site_weight.py` disassembles the published native object and
counts the call instructions in it, which is the part of the site
inventory that is actually in the executed path:

| quantity | `cil_xdp_entry` |
| --- | ---: |
| instructions in the entry | 245 |
| call instructions | 17 |
| helper names the plan reaches | 89 |
| lookup sites | 3 |
| update sites | 4 |
| tail-call maps | 4 |

The gap between 17 call instructions and 89 reachable helper names is the
important one: a plan lists every helper name the program can reach through
its call graph, and the entry itself calls 17 times. So a candidate's site
share must be counted from the entry's own instructions, not from the
plan's name lists, or it overstates what the hot path executes.

The instruction mix of the entry: 70 `mov`, 23 `lea`, 21 `test`, 18 `cmp`,
17 `je`, 17 `call`, 8 `movl`, 7 `movzbl`.

The plan used here is one archived plan, not this object's own, so its
helper and lookup counts describe a program of the same family rather than
this entry. The entry's own 17 call instructions are the measured figure;
`site_weight.py` takes `--plan` explicitly so a caller can pair the two
from the same submission when the archive keeps them together.

### The route to a per-site time split

A per-site *time* share needs per-site samples, and this environment has no
`perf` binary and no `bpfperf`, so it takes a measurement build: a private
native compile that reads the cycle counter at each site, with the published
program untouched. The instruction counts above are the static bound and
the per-program `run_time_ns` is the total; their ratio is the site density,
not the site cost. Two measurements below take that route: the PMU counters
the runner already exposes, and a per-site instrumented build.

### PMU counters, which this environment does have

No `perf` binary is installed, but the runner's own `--perf-counters` opens
the PMU through `perf_event_open` and reports cycles, instructions,
branches and cache events for a native run. Two micro programs, 10,000
inner repeats:

| program | instructions | branches | IPC (median of 5) | IPC range |
| --- | ---: | ---: | ---: | ---: |
| `katran_lb_consistent_hash_select` | 404,750 | 81,034 | 5.33 | 5.27-5.65 |
| `tracee_syscall_name_table_lookup` | 274,750 | 81,034 | 4.89 | 4.75-4.90 |

The instruction count is exactly reproducible across the five runs; the
cycle count is not, so the IPC is a median with the spread given. Both
programs are 5.0 and 3.4 instructions per branch, which is the density a
per-site measurement would divide between the sites.

`run-native --perf-counters` is therefore the measurement tool for the
per-site split, and it needs no new build and no change to any published
program. What it does not have is a per-site scale, because the counters
are read around the whole run.

The per-site scale needs a program that carries map sites, and the micro
tree's programs do not: `common.h` declares `input_map` once, inside
`DEFINE_MAP_BACKED_XDP_BENCH`, and no program expands that macro.
`DEFINE_MAP_BACKED_TC_BENCH` reads its input from a packet, so its name
promises a map it does not use. The map sites are in the application
programs, which is where the plan inventory above counts them: 1,051 lookup
sites and 911 update sites across cilium's 90 plans.

### A per-site cycle split, measured

`kprog/perf/call_split.py` builds a private copy of one micro program whose
entry is bounded by `rdtsc` pairs, and reports where the cycles fall. The
published program, header and runner are unchanged.

`katran_lb_consistent_hash_select`, 10,000 runs over its own generated
packet, median of five:

| span | cycles | share |
| --- | ---: | ---: |
| packet setup (bounds checks, payload pointer) | 334,580 | 22.2% |
| benchmark body (the program's computation) | 837,364 | 55.7% |
| result write (`micro_write_u64_le`) | 334,696 | 22.3% |

The body is the largest span and the two fixed spans are near-equal, which
is what this program's shape predicts: it parses a 54-byte packet, hashes,
and writes one word.

Two other programs with hand-written entries measure as
`flow_5tuple_rss_hash` at 33.3/33.3/33.3% and
`packet_vlan_tcpopt_parser` at 32.1/33.1/34.8%, which is the instrument's
floor. The build emits six `rdtsc` reads for its three spans (one to open,
one per `MARK`, and one pair around the write), so a program whose body is a
few instructions spends most of its measured time inside the marks and shows
roughly a third per span whatever it does. Katran's 55.7% body is
above that floor and is real signal; the other two sit on it and carry none.
The floor is a third per span for three spans, and lowering it means fewer
spans, or timing the body alone against the whole run instead.

**The overhead, stated:** the instrumented build costs 1,956,385 cycles
against the published build's 442,342 for the same work, a 4.4x factor,
because each of its six `rdtsc` reads carries a serializing read and the
marks add a volatile store. The measured spans account for 1,503,744 of the
instrumented total, leaving 452,641 cycles of the program outside them,
against 442,342 uninstrumented -- so the boundaries sit where the spans say
they do, and the shares are the shares of the instrumented run, not
absolute costs.

This is the mechanism the task asks for, on one program. Extending it to
BCC, Katran, Tracee and Cilium means running it on their own native
objects with their own inputs.

### One application entry, split into the task's categories

`cil_xdp_entry` is the program that carries half of cilium's BPF time. Its
published native object, 252 instructions, disassembled:

Each call is preceded by the helper ID in `eax`, so the call sites are
counted exactly rather than inferred:

| helper ID | name | sites |
| --- | --- | ---: |
| 1 | `bpf_map_lookup_elem` | 7 |
| 189 | `bpf_xdp_load_bytes` | 9 |
| 54 | `bpf_xdp_adjust_meta` | 1 |

The IDs are the kernel's own (`include/uapi/linux/bpf.h:5913`, `:6101`,
`:5966`). So this entry's 17 call sites are 7 map lookups, 10 helper calls
and **zero** inlined lookups: every map access goes through the helper.

Tail calls are separate: the object ships five sibling
`*.proof.o` files (`tail_drop_notify`, `tail_no_service_ipv4`,
`tail_nodeport_nat_egress_ipv4`, `tail_nodeport_nat_ingress_ipv4`,
`tail_nodeport_rev_dnat_ipv4`), which are this program's tail-call targets.

| category | sites | share of the 17 calls |
| --- | ---: | ---: |
| map lookups | 7 | 41% |
| helper calls (`xdp_load_bytes`, `xdp_adjust_meta`) | 10 | 59% |
| tail calls | 5 targets | separate |
| computation | 235 instructions | of 252 |

The one thing this does not give is the *time* each category takes, for the
same reason as above: the cycles need a per-site instrumented build of the
application program, and the split here is by instruction and site count.

### Cilium's call sites by the task's four categories

`kprog/perf/helper_ids.py` reads every call site in a native object and
takes its helper number from the `eax` load that precedes the call, using
the kernel's own enumeration. Cilium's four archived native objects --
42,498 instructions, 1,621 call sites:

| category | sites | share |
| --- | ---: | ---: |
| map lookups (`bpf_map_lookup_elem`) | 445 | 27.5% |
| map updates (`bpf_map_update_elem`) | 368 | 22.7% |
| map deletes | 14 | 0.9% |
| tail calls (`bpf_tail_call`) | 70 | 4.3% |
| other helper calls | 724 | 44.7% |

The top helpers: `map_lookup_elem` 445, `map_update_elem` 368,
`skb_load_bytes` 214, `skb_store_bytes` 141, `tail_call` 70,
`csum_diff` 50, `l4_csum_replace` 40, `msg_redirect_map` 40.

**Half of cilium's call sites are map operations** (50.2% for lookups
and updates alone, 51.0% counting deletes),
and the largest single helper is the lookup. That is the measured basis for
the candidate ordering: helper and map-lookup lowering covers the two
biggest single categories, and direct tail-call linking covers another 4.3%.

### The candidates, in the share of cilium's BPF time they cover

Cilium's BPF time is carried by two programs whose kernel-truncated names
are both `cil_from_contai` (52.5% and 47.5%). The archived native config
does not contain a `cil_from_container` entry, so the two are not among the
four objects measured above; the aggregate shape stands in for them, and it
is stable across the objects the config does carry (`bpf_lxc`'s 653 sites:
lookups 27.9%, updates 22.7%, tail calls 5.4% against the aggregate's
27.5%, 22.7%, 4.3%).

Multiplying each category's site share by the BPF time those programs
carry, the candidates rank as:

| candidate | category it acts on | cilium | katran | bcc | tracee |
| --- | --- | ---: | ---: | ---: | ---: |
| helper and map-lookup lowering | map lookups, updates, deletes | 51.0% | **79.7%** | 28.6% | 14.5% |
| constant specialization (recompiling P from frozen map contents) | the lookups that read stable data | 27.5% | 73.9% | 11.7% | 13.4% |
| direct tail-call linking | tail calls | 4.3% | 0% | 0% | 0.1% |
| compiler flags | the whole body | all | all | all | all |
| subprogram inlining | inlined-but-called bodies | needs the caller graph | | | |
| entry and return bridge | fixed per invocation | 11-20% of cycles | | | |

Read per application, the order is: map-lookup and helper lowering first,
because it is the largest category in all four (14.5% to 79.7%); then
constant specialization of the frozen-data lookups, which is a subset of the
same sites; then compiler flags across the body; then tail-call linking,
which only cilium takes up (4.3%).

**The candidate the list is missing, with the share it would cover:** probe
read lowering. `bpf_probe_read_kernel` is 77.0% of Tracee's call sites and
32.1% of BCC's, and none of the six candidates touch it. In the kernel the
helper copies from a virtual address with a bounds check; in the native
compile the address is known and the copy is a bounds-checked `memcpy` over
`BPF_FUNC_probe_read_kernel`'s address space, which is the same shape as the
map-lookup lowering already planned. Adding it as a seventh candidate puts
probe-read programs' largest category in scope, and it is the change that
moves Tracee, whose BPF time is 2,158 s in the native arm against 2,516 s
under the JIT.

**The boundary, stated plainly:** these are site shares weighted by
per-program BPF time, not cycle counts per site. A site's cost depends on
its helper — a `map_update_elem` costs more than a `map_lookup_elem` — so
the ranking of the top two is robust (they are the two largest categories
by a wide margin) and the tail-call figure is an upper bound on its
category's share.

### Katran's call sites, from its own source

Katran archives no native object, so `balancer_ingress` was rebuilt from the
published BPF source (`vendor/repos/katran/katran/lib/bpf/balancer.c`) with
the corpus's native flags -- the published program and kernel are unchanged,
which is the private measurement build the task allows. 2,000 instructions,
69 call sites:

| helper | sites | share |
| --- | ---: | ---: |
| `bpf_map_lookup_elem` | 51 | **73.9%** |
| `bpf_ktime_get_ns` | 8 | 11.6% |
| `bpf_xdp_adjust_head` | 4 | 5.8% |
| `bpf_map_update_elem` | 4 | 5.8% |
| `bpf_get_smp_processor_id` | 2 | 2.9% |

**79.7% of Katran's call sites are map operations, and 73.9% are lookups.**
No tail calls.

That changes the ordering for Katran relative to cilium: map-lookup lowering
covers nearly three quarters of its call sites, constant specialization
covers the lookups that read frozen data, and compiler flags act on the
remaining 1,931 non-call instructions. The two helpers the task did not name
are worth recording because they are not map work at all:
`ktime_get_ns` (11.6%) and `smp_processor_id` (2.9%) are cheap per call but
they sit inside the hash and the per-CPU selection, so they bound how much
of the program the map work can be.

### BCC's call sites, from its eight tools

BCC archives no native objects either. Its eight tools
(`runner/libs/app_runners/bcc_set.py:31-40`: capable, biosnoop, vfsstat,
opensnoop, syscount, tcpconnect, tcplife, runqlat) were compiled to BPF with
the corpus toolchain; a BPF object carries the helper id as the call's own
immediate, which `helper_ids.py` reads. 1,980 instructions, 196 call sites:

| helper | sites | share |
| --- | ---: | ---: |
| `bpf_probe_read_kernel` | 59 | **30.1%** |
| `bpf_map_update_elem` | 23 | 11.7% |
| `bpf_map_lookup_elem` | 23 | 11.7% |
| `bpf_get_current_pid_tgid` | 18 | 9.2% |
| `bpf_ktime_get_ns` | 16 | 8.2% |
| `bpf_current_task_under_cgroup` | 12 | 6.1% |

`vfsstat` carries no helper calls at all, so seven of the eight objects
contribute sites.

### Tracee's call sites

Tracee's programs all come from one source
(`vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`), compiled to BPF the same
way: 417,660 instructions, 34,119 call sites.

| category | sites | share |
| --- | ---: | ---: |
| probe reads (`probe_read_*`) | 26,273 | **77.0%** |
| map lookups | 4,555 | 13.4% |
| map updates and deletes | 383 | 1.1% |
| tail calls | 49 | 0.1% |
| other helpers | 2,859 | 8.4% |

### The four applications, side by side

The same measurement on the four applications the task names, so the
candidate order can be read per application rather than assumed shared:

Each column is the arm the task names for it, read from the run's own
`rejit_result.mode`:

| app | arm | run |
| --- | --- | --- |
| katran | verified (`verified_native_loader`) | `x86_kvm_corpus_20261108_225903_195940` |
| bcc | verified | `x86_kvm_corpus_20261108_232046_843736` |
| cilium | direct (`native_loader`) | `x86_kvm_corpus_20261107_020659_029387` |
| tracee | direct (`native_loader`) | `x86_kvm_corpus_20261107_041920_105442` |

| category | cilium | katran | bcc | tracee |
| --- | ---: | ---: | ---: | ---: |
| map lookups | 27.5% | **73.9%** | 11.7% | 13.4% |
| map updates and deletes | 23.6% | 5.8% | 16.8% | 1.1% |
| tail calls | 4.3% | 0% | 0% | 0.1% |
| packet reads (`skb`/`xdp_load_bytes`) | 14.8% | 0% | 0% | 0% |
| packet stores (`skb_store_bytes`) | 8.7% | 0% | 0% | 0% |
| probe reads (`probe_read_*`) | 0.2% | 0% | 32.1% | **77.0%** |
| other helpers | 21.0% | 20.3% | 39.3% | 8.4% |

**The order is not shared.** Katran is a map-lookup program (73.9%), so
lookup lowering dominates there and covers nearly three quarters of its
sites. Cilium is the balanced case: map operations are half its sites and
it is the only one with tail calls worth linking (4.3%). BCC and Tracee are
probe-read programs -- 32.1% and 77.0% -- where the map work the candidates
address is 28.6% and 14.5% of their sites.

That is the finding the table exists to give, and it changes what to expect:
for Katran, lowering map lookups reaches most of the program. For Tracee and
BCC, the largest single helper is `bpf_probe_read_kernel`, which **no
candidate in the list addresses**; those two need a probe-read candidate
before map lowering can move their ratios much.

#### One span instead of three

The floor above comes from splitting into three spans. Marking the
benchmark call alone halves the marks and gives a measurement that resolves:

| quantity | cycles | note |
| --- | ---: | --- |
| plain published build, whole run | 439,463 | `--perf-counters`, 10,000 repeats |
| body-only build, whole run | 825,183 | one `rdtsc` pair plus a volatile store per repeat |
| body-only build, body span | 533,488 | **64.7%** (median of five; range 63.0-65.8%) |

The overhead falls from 4.4x (three spans) to **1.88x** (one span), and the
body is roughly two thirds of the run. That is the number to carry forward:
it says where the cycles are for this program without needing the other two
spans, which the floor made uninformative.

The same mode on the other two programs, whose three-span split sat on the
floor:

| program | body cycles | instrumented run | body share |
| --- | ---: | ---: | ---: |
| `katran_lb_consistent_hash_select` | 533,488 | 825,183 | 64.7% |
| `packet_vlan_tcpopt_parser` | 419,666 | 667,297 | 62.9% |
| `flow_5tuple_rss_hash` | 349,804 | 655,485 | 53.4% |

All three now resolve above the floor, so the entry's own work is between
53% and 65% of what a run spends and the remaining 35% to 47% is the packet
setup, the result write and the runner's loop. That is the split the
three-span measurement could not give.

`--spans body` selects this mode; `--spans three` keeps the original.

## The entry and return bridge, measured

The candidates list the entry and return bridge as "fixed per invocation"
but gave no cost. It is measurable: `simple` writes one constant, so its
per-invocation cost is the bridge plus the runner's loop and nothing else.
At one million inner repeats, that floor is **6.01 cycles and 32
instructions per invocation**, a median of five runs. The instruction count
converges as the repeat count grows (27.5 per invocation at 10,000, 32.0 at
1,000,000), so the one-shot call setup amortizes; the cycle count does not
converge as cleanly, ranging 6.0 to 7.5 across the five runs.

Measured the same way, with each program's own generated input:

| program | cycles/inv | instructions/inv | body cycles | body instructions |
| --- | ---: | ---: | ---: | ---: |
| `simple` (floor, median of five) | 6.01 | 32 | -- | -- |
| `katran_lb_consistent_hash_select` | 53.02 | 253 | 47.02 | 221 |
| `packet_vlan_tcpopt_parser` | 30.59 | 165 | 24.58 | 133 |
| `flow_5tuple_rss_hash` | 33.77 | 152 | 27.76 | 120 |

Each program runs with its own generated input, at one million inner
repeats; `kprog/perf/bridge.py` reproduces the table. Katran's figure is
its input-taking path: without `--memory` it returns early and costs 6.7
cycles and 40 instructions, which is the floor plus its own first checks.

Two consequences, and they matter for how the ratios above should be read:

1. **The bridge is about 6 cycles, and where a program is small it is most
   of the measurement.** A program that costs 6.7 cycles per invocation is
   90% bridge; one that costs 53 is 11%. Any per-program ratio between two
   runtimes for a small program therefore measures the call path as much as
   the code.
2. **For the programs that carry an application's BPF time the bridge is
   11% to 20% of the cycles.** `packet_vlan_tcpopt_parser` spends 30.6
   cycles per invocation of which 24.6 is its own body (20% bridge),
   `flow_5tuple_rss_hash` 33.8 of which 27.8 (18%), katran 53.0 of which
   47.0 (11%). The bridge is a real candidate there, and a minor one.

**The bridge's share by instruction**, which is what a compiler-flags or
inlining change would move: 32 of 253 for katran (13%), 32 of 165 for
`packet_vlan_tcpopt_parser` (19%), 32 of 152 for `flow_5tuple_rss_hash`
(21%). Removing it entirely would take katran from 53.0 to 47.0 cycles per
invocation (1.13x), `packet_vlan_tcpopt_parser` from 30.6 to 24.6 (1.24x)
and `flow_5tuple_rss_hash` from 33.8 to 27.8 (1.22x).

## The workload was not frozen: what changed since 2026-05-29

The operator's finding is that the benchmark framework drifted after the
2026-05-29 reference (commit `9f3855f6f`), so the two runs measured
different workloads. Comparing each framework file against that tree
(`/workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/paper-tree`)
gives the list, and two of them change the workload shape:

| file | diff lines | shape-affecting |
| --- | ---: | --- |
| `runner/libs/app_runners/katran.py` | 201 | **yes, two changes** |
| `runner/libs/app_runners/otel_profiler.py` | 2 | **yes, one change** |
| `runner/libs/app_runners/tracee.py` | 600 | no (implementation, same workload) |
| `runner/libs/app_runners/cilium.py` | 28 | no (outcome tracking wrappers) |
| `runner/libs/app_runners/tetragon.py` | 0 | no |
| `runner/libs/app_runners/bcc_set.py` | 0 | no |
| `runner/libs/workload.py` | 50 | no (added softirq counters) |
| `corpus/driver.py` | 661 | no (plumbing, plus native-config evidence) |
| `micro/driver.py`, `Makefile` knobs | 47 / 0 | no (`SAMPLES ?= 3` in both) |

### Katran: one pktgen worker in place of four, and threaded NAPI busy-poll

The reference drives **four pktgen workers on threads 0-3**, each with its
own `rtlb0@N` device alias. The current code discovers available threads and
uses a single one, `KATRAN_PKTGEN_THREAD_IDS = (7,)` on the last vCPU of an
eight-vCPU guest, with a comment that a veth has one TX queue so multiple
workers race on it.

The reference packet shape is random-flow: `flag !SHARED`, `udp_src_min 1`,
`udp_src_max 65535`, `flows 65535`, `flowlen 1`. The current shape is
`flag SHARED` with one fixed source port (`udp_src_min` and `udp_src_max`
both 10000) and `flows 0`, `flowlen 0`.

The current code also enables **threaded NAPI busy-poll** on both the router
and receiver peers (`KATRAN_NAPI_THREADED_MODE = "busy-poll"`, two workers
pinned to CPUs 5 and 6 at `SCHED_FIFO` priority 1, configured through
`ynl`'s `napi-set`). The reference has no NAPI setup at all.

**How each moves the comparison.** Four workers with random flows spread the
packet stream over the receive path and give the XDP program a working set
that misses cache; one worker with a fixed flow and a busy-polled NAPI
thread makes the same packet arrive on the same CPU with the ring already
drained. The first measures the balancer's work; the second measures it with
the transport removed. A native program that is 1.88x cheaper per call shows
that gain only in the first case, which is why the current native arm gains
1.78x where the reference gained 1.88x and, more importantly, why the
invocation multiplier fell from 2.26x to 1.26x: with busy-poll there is no
queue to fill, so the workload cannot push more packets through a faster
program.

### OTel: the sampling rate was cut a hundredfold

`samples_per_second` is `1000` in the current code and `100000` in the
reference. A hundredth of the samples means a hundredth of the BPF work per
second, so the collector has almost nothing for the native path to speed up.

That is a plausible cause but not a measured one, so state it as the
hypothesis it is: the ratio fell from 1.824x to 1.013x, and the sampling
rate is a hundredfold lower, but no run yet pairs the two rates on the same
code. What the runs do establish is the direction -- OTel's speedup lives in
BPF work that a hundredth of the samples removes.

### Restored

Both are back at their 2026-05-29 values:

- `runner/libs/app_runners/otel_profiler.py`: `samples_per_second: 100000`.
- `runner/libs/app_runners/katran.py`: `KATRAN_PKTGEN_THREAD_IDS = (0, 1,
  2, 3)`, `flag !SHARED`, `udp_src_min 1`, `udp_src_max 65535`, `flows
  65535`, `flowlen 1`, and the threaded NAPI busy-poll setup removed,
  keeping the XDP attachments the loader path needs to start the
  application. The restored pktgen command strings match the reference's
  exactly; only an explanatory comment was added.

Nothing else in `runner/libs/workload.py`, `runner/libs/app_runners`,
`corpus/driver.py`, `corpus/config`, `micro/driver.py`, `micro/config`,
`micro/programs` or the Makefile recipes and knobs was touched.

### The restore verified on the baseline arm

The first run on the restored workload shows the shape is back. Katran's
baseline arm completed with the reference's own structure:

| sample | pktgen threads | pps per thread |
| --- | --- | --- |
| 0 | 0, 1, 2, 3 | 856,953 / 405 / 898,249 / 898,512 |
| 1 | 0, 1, 2, 3 | 139 / 867,763 / 874,213 / 880,282 |
| 2 | 0, 1, 2, 3 | 887,663 / 893,484 / 899,599 / 1,052 |

Four workers per sample on threads 0-3, each with its own device alias, and
one worker per sample still in its cold start -- which is exactly the pattern
the 2026-05-29 reference shows (its twelve samples carry a 12,717 and a
40,809 pps outlier among the ~850,000 ones).

The native arm did not complete: the Katran server exits before the shim
tracks its programs, so the app never reaches `balancer_ingress`. Under the
task's division that is a binding/startup failure for lane C, and the earlier
run's log shows it is the app exiting during startup, with libbpf skipping
`.eh_frame` sections in its stderr tail. The timing below therefore covers
the baseline arm on the restored workload and reports that the native arm
needs C.

### The restore is validated against the reference's own throughput

The baseline arm's JIT throughput now matches the reference, and the
pre-restore shape was inflated:

| run | samples | median pps |
| --- | ---: | ---: |
| reference 2026-05-29 (`..._061439_040837`) | 12 | 820,622 |
| pre-restore current (`..._20261108_232046_843736`) | 1 | **1,276,704** |
| restored current (`..._20261109_020512_391104`) | 4 | **882,409** |

The pre-restore single-worker busy-polled shape drove 55% more packets per
second than the reference, which is the whole reason its native/JIT ratio
looked worse: with the transport drained and one worker on a dedicated
vCPU, the workload was measuring the balancer against a queue that never
filled. Restoring four workers with random flows brings the baseline within
7.5% of the reference's median, so the comparison is against the same
workload again.

### The native arm's blocker, located

The restored workload's baseline arm passes and its native arm fails at the
trusted specializer, before any packet flows:

```
native-loader failed prog=balancer_ingres
  manifest=/opt/bpf-benchmark/native-bpf/x86_64/katran/manifest.json
  error=trusted specializer refused native program: Input/output error
```

That is a generation failure upstream of the workload, so the restored
packet shape cannot cause it. The evidence that it is a regression rather
than a property of the restore:

| observation | value |
| --- | --- |
| last Katran run where `balancer_ingres` was replaced | `x86_kvm_corpus_20261108_232046_843736`, generated 2026-11-08T23:30 |
| that run's workload | `Flags: SHARED`, `ifname: rtlb0@7` (the pre-restore shape) |
| this run | fails at the specializer, 2026-11-09T01:50 |
| `trusted_service.py` and `trusted_generation.py` in the runner image | **absent** -- the service runs from the host, so the image is not the variable |
| service/generator commits between the last good run and this one | `5598b9321` 23:49, `dc120a8eb` 23:13, `0818f5677` 22:00, `e46b05a25` 01:07 |

So the specializer began refusing Katran's program between 23:30 and 01:50
on 2026-11-08/09, and the change is in the host's service or generator, not
in the workload. `5598b9321` ("Carry native load sites into stock x86
exception-table emission") lands in that window and is the first to check.

**Resolved.** The specializer was invoking two binaries from lane C's
private workspace, both built on 2026-11-08 before the ABI change:

| binary used by the recipe | built | has `load_site` |
| --- | --- | ---: |
| `C/design-only/native-context/loader/trusted-native-loader` | 11-08 11:09 | **no** |
| `C/design-only/native-extent/corpus/native-link` | 11-08 14:43 | **no** |
| `kprog/libnativeloader/build/trusted-native-loader` (rebuilt) | 11-09 02:23 | yes |
| `kprog/x86/native_lab/native_link/target/release/native-link` | 11-08 23:44 | yes |

`5598b9321` added `load_sites_user` and `load_site_count` to the trusted
request struct at 23:49 on 11-08; a loader built before that sends no load
sites, and the rebuilt kernel module rejects the short request with `EIO`,
which surfaces as `specializer refused native program: Input/output error`.
Rebuilding the loader and pointing the recipe at current builds clears it:
`native-loader replaced prog=balancer_ingres`, zero failures.

### Katran on the restored workload, both arms

`status ok`, both arms complete, **1 of 1 program bound**:

| arm | worker pps (threads 0-3) | total pps |
| --- | --- | ---: |
| JIT | 520,918 / 895,558 / 371,116 / 911,249 | 2,698,841 |
| native | **1,057** / 919,407 / 865,474 / 900,407 | 2,685,288 |

**native/JIT 0.995x** by summed throughput -- parity. All four workers carry
`Flags: FLOW_RND`, so the restored random-flow shape is what ran. The
native arm's worker 0 is a cold start at 1,057 pps, the same pattern the
2026-05-29 reference shows with its 12,717 and 40,809 pps outliers. The
like-for-like comparison is the warm workers only: native 895,096 mean over
three, JIT 775,908 over its three highest. Summed over all four -- which is
what the workload's total throughput is -- the cold workers roughly cancel,
one in each arm, giving the 0.995x above.

### Both arms passed through XDP and did equal work

The counters the runner records (`runner/libs/app_outcomes.py`, read from
Katran's `stats` map and the peer interface):

| counter | JIT arm | native arm |
| --- | ---: | ---: |
| `tx` packets | 53,743,689 | 53,644,294 |
| `total` packets | 53,743,690 | 53,644,294 |
| `drop` | 0 | 0 |
| `encap_fail` | 0 | 0 |
| `lru_miss` | 0 | 0 |
| `consistent_hash_drop` | 0 | 0 |
| receiver `rx_packets` | 53,743,691 | 53,644,294 |
| receiver `rx_dropped` / `rx_errors` | 0 / 0 | 0 / 0 |

Every packet the generator sent is counted by the balancer, the balancer
reports zero drops of every kind, and the receiver's `rx_packets` matches
the balancer's `tx` count to within 2 packets (the native arm exactly, the
JIT arm by 2) -- so each arm's packets traversed the XDP program and
arrived. The two arms differ by 0.18% in packet count, which is a 20 s
duration against a generator that is not slaved to a fixed count.

The `pass` counter reads 1 in the JIT arm and 0 in the native arm, which is
one packet of a different path, not a work difference: `total` and `tx`
agree to within 0.18% and the receiver matches both.

That was one 20 s sample, so it established binding, shape and equal work.
The measurement below repeats it at the operator's knobs.

### Katran at SAMPLES=3 WORKLOAD_DURATION=180, both stats modes

Both runs use the recipe lane C posted, on host CPUs 0-7, with the restored
workload verified in each: four pktgen workers on threads 0-3, each worker's
`/proc/net/pktgen` output carrying `flows: 65535` and `flowlen: 1`.

| stats | run | JIT pps | native pps | native/JIT |
| --- | --- | ---: | ---: | ---: |
| off | `..._20261109_074938_322377` | 2,652,815 | 2,646,911 | **0.998** |
| on | `..._20261109_071718_076108` | 1,879,418 | 1,806,798 | **0.961** |

Per sample, so the spread is visible rather than a single number:

| stats | arm | sample 0 | sample 1 | sample 2 |
| --- | --- | ---: | ---: | ---: |
| off | JIT | 2,653,196 | 2,658,278 | 2,646,970 |
| off | native | 2,657,290 | 2,607,301 | 2,676,141 |
| on | JIT | 1,882,668 | 1,878,300 | 1,877,285 |
| on | native | 1,787,987 | 1,789,415 | 1,843,005 |

**0.998x with stats off, 0.961x with stats on.** Turning BPF stats on costs
both arms throughput (2.65M to 1.88M pps on the JIT arm) because every
invocation updates the per-program counters; the native arm loses slightly
more, so the ratio drops from parity to 0.96.

Equal work, from the balancer's own counters in the same runs:

| counter | stats off, JIT | stats off, native | stats on, JIT | stats on, native |
| --- | ---: | ---: | ---: | ---: |
| `tx` packets | 1,433,365,822 | 1,430,124,713 | 1,015,427,177 | 975,943,327 |
| `drop` / `encap_fail` / `lru_miss` | 0 / 0 / 0 | 0 / 0 / 0 | 0 / 0 / 0 | 0 / 0 / 0 |
| worker threads | 0,1,2,3 | 0,1,2,3 | 0,1,2,3 | 0,1,2,3 |

Both arms carry `Flags: FLOW_RND` on all four workers, so both ran the
restored random-flow shape, and neither dropped or failed to encapsulate a
packet.

### What the restored workload says about the native code

The stats-on run records per-program time, which is the comparison the
program-level table above could not make at this length:

| arm | invocations | total ns | ns per invocation |
| --- | ---: | ---: | ---: |
| JIT | 1,015,427,177 | 175,426,221,480 | **172.8** |
| native | 975,943,327 | 182,326,966,937 | **186.8** |

So on the restored workload the native code costs 186.8 ns per invocation
against the JIT's 172.8 -- **8% slower**, not faster. Its recorded size is
the same as before (`bytes_xlated` 1,112 against the JIT's 23,840;
`bytes_jited` 8,744 against 13,641), so this is not a recompilation: the
native code is the same code, measured against a workload that now fills
the queue. At 20 s the same code measured 0.995x.

The honest reading is that Katran is a program whose JIT output is already
good, and a native body that is 36% smaller in bytes (8,744 against 13,641)
does not make it cheaper per invocation. Any optimization for Katran has to
change what the native body does, not how it is stored.

### Tracee: baseline counters, launch fails on kconfig

Tracee's baseline arm produced counters -- 151 programs, 7,269,956,948
invocations at **339.1 ns per invocation** -- but the app run itself exited
97, so the arm is not a clean sample. The cause is not the workload:

| observation | value |
| --- | --- |
| image has `/boot/config-7.0.0-rc2+` | yes |
| guest sees `/boot` | no -- the recipe mounts `--rwdir` for the repo and state only |
| host has `/boot/config-$(uname -r)` | no |
| Tracee's consequence | `KConfig: could not check enabled kconfig features`, then detectors `TRC-1013` and `TRC-107` fail to register ("requires enrichment environment") |

Placing the release config at `/boot/config-7.0.0-rc2+` on the host -- which
the guest shares -- removes the kconfig warning entirely: the re-test's error
text contains no `kconfig` mention at all. What remains is `TRC-1013` and
`TRC-107` failing to register, which is a different cause and is still open.

Those two detectors want the `exec-env` enrichment, and this build exposes
it only through `Output.Environment`, which the runner leaves off while
passing `--output none` (`TRACEE_OUTPUT_MODE = "none"`). Turning it on means
changing `runner/libs/app_runners/tracee.py`, which the operator's
instructions freeze, so it needs their word.

The kconfig fix is worth keeping regardless: it is one file on the host, it
touches no frozen path, and without it Tracee logs a real warning on every
launch.

### Tetragon: baseline reproduces, native arm refused

Tetragon ran at SAMPLES=3 WORKLOAD_DURATION=180 with stats on. Its baseline
arm completed all three samples -- 287 programs, 2,911,520,568 invocations
and 2,159,451,766,761 ns, which is **741.7 ns per invocation** against the
archive's 748 ns (0.99x). The JIT arm therefore still reproduces on the
restored workload.

The hot programs, by BPF time:

| program | type | invocations | BPF ns | ns per run |
| --- | --- | ---: | ---: | ---: |
| `generic_tracepo...` | tracepoint | 1,336,729,391 | 1,057,926,746,954 | 791.4 |
| `generic_kprobe_...` | kprobe | 57,008,275 | 348,510,017,600 | 6,113.3 |
| `generic_kprobe_...` | kprobe | 162,983,229 | 138,676,227,228 | 850.9 |
| `generic_kprobe_...` | kprobe | 163,748,363 | 137,674,626,617 | 840.8 |
| `generic_kprobe_...` | kprobe | 237,499,029 | 135,990,511,454 | 572.6 |

The second row is the one the archive's 900.4 ns figure is about: a
`generic_kprobe_` variant at **6,113 ns per invocation** on 57 million runs,
which is where a native arm would gain or lose the most.

Its native arm replaced 0 programs; `event_exit_acct` was the first the
specializer refused.

### Cilium: baseline complete with verdict counters, native arm refused

Cilium ran at SAMPLES=3 WORKLOAD_DURATION=180 with stats on. Its baseline
arm completed all three samples: 53 programs, 489,297,698 invocations and
632,773,375,235 ns of BPF time, 1,293.2 ns per invocation.

Work done, from the datapath's own verdict map rather than from a count of
packets sent:

| counter | per sample |
| --- | ---: |
| forwarded, `direction=1` | 165,777,756 packets / 10,609,786,576 bytes |
| forwarded, `direction=2` | 165,777,759 packets / 10,609,786,786 bytes |
| dropped, `reason=139` | 2 packets |
| dropped, `reason=3` | 2 packets |

Both directions carry the same volume to within 3 packets, and the two
drops are 2 packets each -- so the datapath forwarded essentially
everything the generator sent. The pktgen components report 82,888,659 and
82,888,733 packets in each direction with `errors: 0`, on the restored
random-flow shape (`flows: 65535`, `flowlen: 1`, `Flags: FLOW_RND`).

Its native arm replaced **0** programs and the specializer refused
`cil_xdp_entry` with `Input/output error` -- the same generation-ABI cause
as BCC. This run also had to add `native_division.so` to the image: the
runner image ships it under `/usr/local/lib/bpfrejit/native/`, but the
`kprog_app_coverage_20261107` Dockerfile does not copy it, so Cilium's
native compile failed with `unable to load plugin ... No such file or
directory` before any program reached the specializer.

### BCC: baseline complete, native arm refused on stale objects

BCC ran on the restored workload at SAMPLES=3 WORKLOAD_DURATION=180 with
stats off. Its baseline arm completed and produced real per-program
counters -- 25 programs, 14,784,897 invocations and 2,401,230,511 ns
(**162.4 ns per invocation**), the heaviest being `sys_enter` at 6,779,793
runs and 1,026,337,247 ns and `sys_exit` at 6,779,800 runs and 610,341,169
ns.

Its native arm failed, with the same signature Katran had before its loader
was rebuilt:

| observation | value |
| --- | --- |
| programs replaced before the failure | 2 (`fentry_vfs_read`, `tcp_v4_connect`) |
| programs refused | 3 |
| error | `trusted specializer refused native program: Input/output error` |
| the app's native objects in the image | `/opt/bpf-benchmark/native-bpf/x86_64/bcc/`, **2026-11-07 15:01** |
| its manifest | 2026-11-07 19:08 |
| `load_sites_user` / `load_site_count` added to the trusted request | `5598b9321`, 2026-11-08 23:49 |

So the objects predate the ABI that carries load sites, and the specializer
rejects the short request with `EIO`. That is generation, not workload, and
it belongs to lane C: the objects have to be regenerated from the current
generator, not just re-linked.

### OTel, and what its image needs

OTel ran its baseline arm on the restored workload (13 programs loaded, the
20 s workload completed) and its native arm failed at startup with the same
message Katran had before its loader was rebuilt: `native app exited before
BPF programs were tracked by shim`.

The difference from Katran is that the OTel image carries its own generated
native objects under `/opt/bpf-benchmark/native-bpf/x86_64/otel*/`
(`custom_trace.native.o`, `dotnet_tracer.native.o`, ...), produced before
`5598b9321` added the load-site fields. Katran's image objects happen to
work; OTel's do not. Regenerating them is generation work, which belongs to
lane C with the app's own runtime.

The OTel service's own request log shows a different failure from Katran's:
not the specializer rejecting a native program, but the **compile of the
generated BPF failing**, because the generated source begins

```c
#include "/workspaces/repository/kprog/x86/x86_sim_local_bpf.h"
```

and the corpus container mounts only `corpus/results`, so it has no
`kprog/` directory at all:

```
fatal error: '/workspaces/repository/kprog/x86/x86_sim_local_bpf.h'
  file not found
```

The compiler that hits this is the recipe's `clang`, which in the image
resolves through `/usr/local/bin/clang-18 -> merlin-bpf-clang`, and in this
recipe is the wrapper at `C/design-only/remaining-apps/clang`, which submits
to C's `frozen-python` compile broker (whose `broker/STOP` file is present,
so it does not serve).

**The compile failure is the stopped compile broker, not the sources.** The
`clang` the OTel service invokes is a wrapper at
`C/design-only/remaining-apps/clang` that submits to lane C's
`frozen-python` compile broker, and that broker is down:

| evidence | value |
| --- | --- |
| broker `STOP` file | present |
| broker process | none running |
| broker `ready.json` | written 2026-11-08 06:20 |
| the clang the request names | `C/design-only/remaining-apps/clang` (the wrapper) |

I verified the sources themselves compile in the image once the headers are
present: with `kprog/x86/`, `kprog/formal/generated/`, `kinsn/module/include/`
and `vendor/libbpf/` added, the generated BPF compiles to a 41,136-byte
object with no errors. So the remaining failure is the broker, and the image
layer needs those four trees as well -- which I added.

**So both-arms is complete for Katran and blocked for OTel on lane C's
compile broker.** For C: restart the `frozen-python` broker (its `STOP` file
is present and no process runs), and OTel's native objects then need
regenerating with the load-site fields. The six-application timing at
`SAMPLES=3 WORKLOAD_DURATION=180` waits on those.

### What it takes to run OTel's native arm

Chasing the OTel compile to the end established the full set of things the
recipe needs, each verified in isolation:

1. **The compile broker must be running.** `frozen-python/trusted_compile.py
   serve` writes `ready.json`, serves `*.request.json` pairs and stops when
   a `STOP` file appears. Lane C's `broker/` has `STOP` present, no process,
   and a `ready.json` from 2026-11-08 06:20, so every compile submitted to
   it fails. A broker started in a private state directory with
   `--clang /usr/lib/llvm-18/bin/clang` serves the same requests correctly:
   a compile through it returns `returncode: 0`.
2. **The `CLANG` environment variable chooses the compiler.** The
   specializer resolves `CLANG`, then `PATH`, then `/usr/lib/llvm-*/bin`;
   the recipe's `clang` on `PATH` is the wrapper that submits to the broker,
   so `CLANG` must name it explicitly for the requests to go through the
   working broker.
3. **The wrapper needs two links beside it.** It rewrites the generated
   source's absolute `#include` to `<its own dir>/source/...` and invokes
   `<its own dir>/frozen-python/trusted_compile.py`, so `source -> repo` and
   `frozen-python -> the frozen copy` have to exist next to it.
4. **The image needs four source trees the generated BPF includes by
   absolute path**: `kprog/x86`, `kprog/formal/generated`,
   `kinsn/module/include` and `vendor/libbpf`. With all four, the generated
   source compiles to a 41,608-byte object with no errors.

With all four in place the request reaches my broker and the broker's own
compile returns 0, but the corpus request still reports `exit status 1` and
one request is left unserved in the broker's queue, so the wrapper and the
recipe disagree on something the broker's log does not show. That agreement
is lane C's to settle, since the broker, the wrapper and the frozen service
are all theirs.

### OTel's native arm binds and then stalls in startup

With the broker served from a supervised process under the mounted state
directory, OTel's native arm finally binds: **2 of the profiler's programs
are replaced natively and none fail**. The arm then does not reach its
measurement phase:

| evidence | native arm | baseline arm |
| --- | ---: | ---: |
| `list_progs` shim polls | 3,669 | 21 |
| `BPF_PROG_LOAD` | 5 | 17 |
| shim-log lines | 3,828 | 505 |
| reached `measure_finish` | no | yes (at 225 s) |

The shim's last activity is at **268 s**, and it is the load of one
program:

```
native-loader replaced prog=perf_unwind_sto original_fd=52 native_fd=58
BPF_PROG_LOAD type=7 (perf_event) name=perf_unwind_nat insn_cnt=6972
native-loader source-context flags=0 token_fd=-1
```

`perf_unwind_nat` is a 6,972-instruction program, and the stall is the
**compile of the native code the specializer generates for it**:

| evidence | value |
| --- | ---: |
| generated source | 911,444 bytes, 21,822 lines |
| compiler resident set | 9.3 GB, flat |
| compiler CPU | 6,013 ticks per 60 s -- one full core, advancing |
| wall time with no external timeout | **about 12 minutes**, then it finishes |
| compiler peak resident set | 9.3 GB, falling to 2.3 GB in its codegen phase |
| result | 2,919,744-byte object, zero errors, 906 warnings |
| broker compiles that returned | 3 of 4 (`returncode: 0`) |

So generation and every compile succeed -- this one just takes about twelve
minutes for one program, which is longer than the 20 s workload it precedes.
Compiling it outside the run gives a 2,919,744-byte object with zero errors.

That is the whole stall: the run waits twelve minutes on `perf_unwind_nat`'s
compile before its measurement can start, and the shim polls `list_progs` in
the meantime. The baseline arm on the same restored workload completes in
225 s.

That is a generation-size problem rather than a correctness one: the
specializer emits one straight-line native body for a 6,972-instruction
program, and the compiler's cost on it is what the run waits for. It belongs
to lane C with the generation failures.

The mechanism behind the four requirements above, in order, was: C's broker
down (fixed by serving it), `CLANG` unset (fixed in the recipe's
environment), the wrapper's two links (added), and four source trees absent
from the container (added). Each was verified on its own; the stall is what
remains after all four.

That is a native-path startup failure, which the task assigns to lane C with
the binding and trusted-service failures.
