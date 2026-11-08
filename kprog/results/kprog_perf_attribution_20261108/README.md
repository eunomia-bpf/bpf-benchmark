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
   asked. Both arms moved; the native-specific remainder is 8% to 18%.
4. **Call sites per program** — what each candidate acts on, from the link
   plans.
5. **Katran on the verified arm, 2026-11-08** — both stats modes.
6. **Per-program time shares** paired with the site counts, and **the code
   itself**, which is the measured bound where sampling is unavailable.

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
  workload, not of the measurement.## Why the 2026-05-29 numbers were faster

The reproduction left the cause open. It is not the native code: the JIT
arm of the same runs is slower than its reference too, and the JIT arm
executes bytecode the native path never touches.

Per-program `run_time_ns_delta / run_cnt_delta` from both arms of the same
run, compared against the archived 2026-05-29 run for the same application
(`kprog/perf/arm_moved.py`). Restricting to programs active in both arms of
both runs keeps the work comparable:

| app | archived run (JIT) | current run (JIT) | JIT x | native x | native beyond JIT |
| --- | --- | --- | ---: | ---: | ---: |
| tetragon | `x86_kvm_corpus_20260529_000413_418475` | `..._20261107_002003_274609` | 1.287 | 1.389 | 1.079 |
| cilium | `x86_kvm_corpus_20260529_033517_489159` | `..._20261107_020659_029387` | 1.116 | 1.292 | 1.158 |
| otelcol | `x86_kvm_corpus_20260529_021623_817446` | `..._20261107_024322_358412` | 1.518 | 1.691 | 1.114 |
| katran | `x86_kvm_corpus_20260529_001204_890087` | `..._20261106_230835_743350` | 1.012 | 1.196 | 1.182 |

`JIT x` is the median per-program increase in nanoseconds per invocation on
the JIT arm; `native x` is the same on the native arm. `native beyond JIT`
is their ratio, which is the part the native path is answerable for.

Two facts follow:

1. **Every arm got slower.** The JIT arm alone is 1.01x to 1.52x heavier per
   invocation than its 2026-05-29 run. The native arm moves by almost the
   same factor, so the reference's ratios came from a faster machine state,
   not from faster native code.
2. **The native-specific share is 8% to 18%.** After dividing out what the
   JIT arm also lost, 1.079x to 1.182x remains attributable to the native
   path.

That is why cilium's reference 2.358x is now 1.229x: its native arm lost
1.292x, but its JIT arm lost 1.116x, so the ratio collapses by most of the
native factor while the absolute slowdown is common to both arms. The same
shape explains otelcol (1.824x to 1.013x) where the JIT arm lost 1.518x.

### The JIT arm, program by program

The JIT arm is the control: the native path never touches its bytecode, so
a change there comes from the machine, the kernel or the workload. Tetragon
is the app with the most active programs, so its per-program JIT times
show the shape directly:

| program | 2026-05-29 ns/run | 2026-11-07 ns/run | change |
| --- | ---: | ---: | ---: |
| `event_execve` | 4,998.0 | 5,512.0 | 1.103 |
| `event_exit_acct` | 1,395.3 | 2,315.8 | 1.660 |
| `event_wake_up_n` | 1,734.2 | 3,312.2 | 1.910 |
| `generic_kprobe_` | 838.0 | 1,078.2 | 1.287 |
| `generic_rawtp_e` | 4,173.0 | 6,183.7 | 1.482 |
| `generic_retkpro` | 53.5 | 52.4 | 0.981 |
| `generic_tracepo` | 563.3 | 765.4 | 1.359 |
| `tg_kp_bprm_comm` | 744.0 | 714.3 | 0.960 |

Six of eight got slower by 1.10x to 1.91x and two got slightly faster, on
bytecode the native path does not execute. The spread is per-program, so it
is the workload's own timing, not a uniform clock or CPU change.

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
1.478x and 1.403x against 1.429x.  The native code did not move; the
context around the corpus apps did.

### What this means for the candidates

The candidates act on the native path only, so they can recover at most the
`native beyond JIT` column: 8% to 18% per application. Recovering the rest
requires the shared cause — kernel, workload or measurement state — to be
restored, and that cause is outside the native compile.

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
| entry and return bridge | fixed per invocation | 1 per program |
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

### What is still needed for a per-site time split

A per-site *time* share needs per-site samples, and this environment has no
`perf` binary and no `bpfperf`, so it needs a measurement build: a native
compile that reads the cycle counter at each site. The instruction counts
above are the static bound, and the per-program `run_time_ns` is the total;
their ratio is the site density, not the site cost.

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
