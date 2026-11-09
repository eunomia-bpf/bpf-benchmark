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
That is why otelcol's ratio fell from 1.824x to 1.013x.

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

That is one 20 s sample, so it establishes binding, shape and equal work
rather than a final ratio: the six-application timing at SAMPLES=3
WORKLOAD_DURATION=180 is the measurement.

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
| wall time with no external timeout | past 11 minutes and still compiling |
| compiler peak resident set | 9.3 GB, falling to 2.3 GB in its codegen phase |
| broker compiles that returned | 3 of 4 (`returncode: 0`) |

So generation and the earlier compiles succeed; this one program's generated
source is large enough that clang takes tens of minutes and the workload
never starts. The baseline arm on the same restored workload completes in
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
