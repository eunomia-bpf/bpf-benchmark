# Native Kernel Execution Evaluation

Last updated: 2026-06-14

This is the paper-facing evaluation note for the native-in-kernel execution
path. The benchmark framework records raw counters and workload payloads only;
all ratios, tables, figures, and interpretation below are post-hoc analysis.
Detailed commands, artifact paths, debugging history, and caveats are preserved
in the appendices.

## Paper Framing

Native execution is evaluated at two levels. Microbenchmarks isolate BPF
instruction execution and helper/map boundary costs under controlled test-run
workloads. Corpus benchmarks measure end-to-end application impact after real
production eBPF applications load their own programs through their normal
startup paths.

The current research questions are:

- **RQ1 Correctness:** does native execution preserve microbenchmark outputs
  and load real corpus applications without startup or workload failures?
- **RQ2 Micro execution cost:** how do userspace native, userspace eBPF,
  kernel native, and kernel eBPF compare on pure-bytecode micro cases, and how
  does kernel native compare with kernel eBPF on helper/map cases?
- **RQ3 BPF per-run cost in real apps:** once real apps are running, does
  kernel native reduce measured BPF `ns/run` relative to the kernel eBPF JIT?
- **RQ4 End-to-end workload impact:** does lower BPF execution cost translate
  into higher application workload throughput?

Headline result: **on x86 KVM, kernel-native execution improves workload
throughput by `1.35x` unweighted geomean over eBPF JIT across six real-app
workloads, with four clear wins, one neutral result, and one slight
regression.** On arm64 AWS, the same app-level whole-program native replacement
matrix is now complete and gives a mixed `1.06x` workload geomean: Cilium is a
large win, Tetragon/Katran/BCC are positive to neutral, OTEL is near neutral,
and Tracee is a large regression.

The narrow claim supported by the current data is: native kernel execution is
consistently positive on controlled x86 microbenchmarks, completes real
whole-program corpus replacement on both x86 and arm64, and fixes the previous
Tetragon native-path slowdown at the BPF counter level. The end-to-end workload
result remains app- and architecture-dependent because BPF instruction
execution is only one part of tracing/security/networking application cost.

## Experimental Setup

All runs in this note use the repository `make` entrypoints. Micro and the
original corpus matrix use x86 KVM. The 2026-06-14 portability refresh uses
arm64 AWS (`PLATFORM=aws ARCH=arm64`) on the repository default `t4g.small`
target. The kernel/runtime image is the repository default build used by
`make micro` and `make corpus`.

Micro runs use `SAMPLES=3`, `WARMUPS=0`, and `INNER_REPEAT=100000`. The
pure-bytecode suite tests `kernel` (kernel eBPF JIT), `native_kernel` (native
object loaded into the kernel native path), `llvmbpf` (userspace eBPF), and
`native` (userspace native). The helper/map suite tests `kernel` and
`native_kernel`.

Corpus runs cover six real applications on x86 KVM and arm64 AWS: `bcc/set`,
`otelcol-ebpf-profiler/profiling`, `cilium/agent`, `tetragon/observer`,
`katran`, and `tracee/monitor`. Each corpus workload uses `SAMPLES=3` and
`WORKLOAD_DURATION=180`. The default corpus warmup is one uncounted workload
pass per phase.

Three corpus datasets are used:

- **BPF stats on:** native-post runs with BPF runtime counters enabled, used
  for per-run `ns/run`.
- **BPF stats off:** native-post runs with BPF runtime counters disabled, used
  for workload throughput without BPF stats overhead.
- **Workload-only:** no-eBPF workload runs, used as the workload throughput
  denominator where that mode is semantically comparable.

The Cilium corpus result is a steady-state datapath measurement. The runner
disables runtime reload/regeneration controllers and pauses `cilium-agent`
during measured workload samples after endpoint setup; it is not a Cilium
control-plane throughput benchmark.

## Methodology

Micro analysis follows the same method as `docs/micro-bench-status.md`: each
benchmark/runtime pair records three samples, correctness is gated by exact
expected-result checks, and aggregate runtime ratios are geomeans normalized to
kernel eBPF (`kernel = 1.0`; lower is faster).

Corpus workload throughput is computed only from raw per-app workload payloads.
For `stress-ng`, the analysis sums real-time `bogo ops/s` across configured
stressors in each sample. For kernel `pktgen`, it sums `pps` across components
or threads. For the OTEL mixed workload, it sums each worker's
`ops / elapsed_s` and includes the `stress-ng cpu` component's real-time
`bogo ops/s`. These units are app-local, so only ratios within the same app
are meaningful.

Workload intent and limits:

| App | Domain | Generator | Intended hot path | Interpretation limit |
| --- | --- | --- | --- | --- |
| `bcc/set` | tracing tools | `stress-ng` fast syscalls, cap, set, sockfd | syscall tracepoint/kprobe dispatch | synthetic high-rate syscall mix |
| `otel` | continuous profiling | language interpreter loops plus `stress-ng cpu` | perf-event sampling and unwind tail-call chain | CPU-loop profiler workload, not a full service |
| `cilium` | Kubernetes datapath | bidirectional endpoint `pktgen` | steady-state endpoint datapath | control plane paused during measured phase |
| `tetragon` | runtime security | `stress-ng` eventfd, mmap, UDP, sock, sockfd, sockpair | generic tracepoint/kprobe event path | synthetic policy-hot syscall/socket mix |
| `katran` | L4 XDP load balancer | kernel `pktgen` UDP to VIP | standalone XDP balancer ingress | datapath-only packet generator |
| `tracee` | runtime security | `stress-ng` cap, set, sigfd, eventfd, kill, futex, prctl | syscall tracing/security hooks | synthetic syscall mix |

Corpus BPF per-run cost is computed from the BPF-stats-on artifacts. The
analysis keeps records with `run_cnt_delta >= 100`, then computes aggregate
`ns/run` per phase as:

```text
ns_per_run = sum(run_time_ns_delta) / sum(run_cnt_delta)
```

The BPF table also reports `native/eBPF cost` and `speedup =
eBPF_ns_per_run / native_ns_per_run`, but the main corpus figure plots raw
`ns/run` bars for direct inspection. This is a run-weighted aggregate over the
retained counter population, not a per-program paired geomean and not a claim
that every retained BPF program improved.

## Main Results

Latest authoritative datasets are all complete: pure-bytecode micro,
helper/map micro, x86 KVM corpus apps with BPF stats enabled, x86 KVM corpus
apps with BPF stats disabled, x86 KVM no-eBPF workload-only baselines, and the
same three corpus modes for all six apps on arm64 AWS. Corpus artifacts were
collected one app at a time.

![Corpus workload and BPF per-run cost](figures/eval-native-corpus-20260529.png)

*Figure 1: Corpus end-to-end workload throughput and aggregate BPF per-run
cost. The left subplot normalizes workload throughput to the no-eBPF baseline
for each app. The right subplot reports raw aggregate BPF `ns/run`
for the retained counter population (`run_cnt_delta >= 100`). For workload
throughput, higher is better. For BPF `ns/run`, lower is better. Cilium's
workload-only number is not a strict upper bound because workload-only bypasses
the Cilium datapath setup rather than running the same attached datapath with
no BPF program.*

![Micro runtime](figures/eval-native-micro-20260529.png)

*Figure 2: Micro runtime normalized to kernel eBPF. Lower is faster. The
helper/map panel only reports kernel native because the authoritative helper
artifact intentionally compares against the real kernel helper/map ABI rather
than userspace emulation.*

![x86 and arm64 corpus workload and BPF per-run cost](figures/eval-native-corpus-20260614.png)

*Figure 3: Combined x86 KVM and arm64 AWS corpus results. The x86 data is the
2026-05-29 matrix; the arm64 data is the 2026-06-14 matrix. The plotted
quantities match Figure 1.*

Micro runtime result:

| Suite | userspace native | userspace eBPF | kernel native | kernel eBPF |
| --- | ---: | ---: | ---: | ---: |
| Pure bytecode normalized runtime | 0.566x | 0.665x | 0.677x | 1.000x |
| With helpers/maps normalized runtime | n/a | n/a | 0.700x | 1.000x |

Corpus workload throughput. The `native/eBPF` headline is the unweighted
geomean across the six per-app ratios (`1.35x`):

| App | no-eBPF throughput | eBPF/no-eBPF | native/no-eBPF | native/eBPF |
| --- | ---: | ---: | ---: | ---: |
| `bcc` | 1574841 | 0.451x | 0.453x | 1.005x |
| `otel` | 108641288 | 0.397x | 0.724x | 1.824x |
| `cilium` | 2412363 | 0.680x | 1.603x | 2.358x |
| `tetragon` | 1542246 | 0.233x | 0.308x | 1.323x |
| `katran` | 8434635 | 0.348x | 0.383x | 1.102x |
| `tracee` | 3325831 | 0.136x | 0.130x | 0.958x |

Arm64 AWS corpus workload throughput. The `native/eBPF` headline is the
unweighted geomean across the six per-app ratios (`1.06x`):

| App | no-eBPF throughput | eBPF/no-eBPF | native/no-eBPF | native/eBPF |
| --- | ---: | ---: | ---: | ---: |
| `bcc` | 291947 | 0.332x | 0.334x | 1.005x |
| `otel` | 12745658 | 0.987x | 0.976x | 0.989x |
| `cilium` | 1068569 | 0.378x | 1.537x | 4.060x |
| `tetragon` | 145023 | 0.291x | 0.339x | 1.164x |
| `katran` | 1057860 | 0.911x | 0.984x | 1.081x |
| `tracee` | 368241 | 0.083x | 0.023x | 0.273x |

Native/eBPF workload sample spread:

| App | native/eBPF samples | Mean | CV |
| --- | --- | ---: | ---: |
| `bcc` | 1.006x, 1.001x, 1.007x | 1.004x | 0.3% |
| `otel` | 1.796x, 1.824x, 1.823x | 1.815x | 0.9% |
| `cilium` | 2.325x, 2.458x, 2.356x | 2.380x | 2.9% |
| `tetragon` | 1.352x, 1.249x, 1.323x | 1.308x | 4.1% |
| `katran` | 1.128x, 1.099x, 1.102x | 1.110x | 1.4% |
| `tracee` | 0.966x, 0.963x, 0.954x | 0.961x | 0.6% |

Corpus BPF per-run counters, reported as run-weighted aggregate `ns/run` over
retained records:

| App | eBPF ns/run | native ns/run | native/eBPF cost | speedup | retained eBPF/native |
| --- | ---: | ---: | ---: | ---: | ---: |
| `bcc` | 103.6 | 102.5 | 0.99x | 1.01x | 16/15 |
| `otel` | 3210.4 | 216.7 | 0.07x | 14.81x | 2/2 |
| `cilium` | 488.7 | 262.3 | 0.54x | 1.86x | 2/2 |
| `tetragon` | 695.2 | 311.8 | 0.45x | 2.23x | 21/24 |
| `katran` | 178.3 | 142.4 | 0.80x | 1.25x | 1/1 |
| `tracee` | 324.5 | 330.9 | 1.02x | 0.98x | 41/41 |

Arm64 AWS BPF per-run counters:

| App | eBPF ns/run | native ns/run | native/eBPF cost | speedup | retained eBPF/native |
| --- | ---: | ---: | ---: | ---: | ---: |
| `bcc` | 186.8 | 195.0 | 1.04x | 0.96x | 15/15 |
| `otel` | 2555.6 | 2518.9 | 0.99x | 1.02x | 2/2 |
| `cilium` | 2738.8 | 577.2 | 0.21x | 4.75x | 2/2 |
| `tetragon` | 1181.9 | 901.1 | 0.76x | 1.31x | 29/29 |
| `katran` | 403.9 | 367.0 | 0.91x | 1.10x | 1/1 |
| `tracee` | 931.8 | 3435.0 | 3.69x | 0.27x | 70/70 |

## RQ Answers

**RQ1 Correctness.** The authoritative micro artifacts have zero expected
result mismatches across all tested runtimes. The authoritative corpus
artifacts complete for all six apps with status `ok`, empty app error strings,
three measured workload samples per app, and no final-artifact `panic`,
`phase_error`, `load program: no such file`, or incompatible map-spec failures.

**RQ2 Micro execution cost.** Kernel native is faster than kernel eBPF on both
current micro suites: `0.677x` normalized runtime on pure bytecode and `0.700x`
on helpers/maps. On pure bytecode, userspace native (`0.566x`) and userspace
eBPF (`0.665x`) are also faster than kernel eBPF. The helper/map suite only
reports kernel native because helper/map-heavy programs must be evaluated
against the real kernel helper/map ABI.

**RQ3 BPF per-run cost in real apps.** On x86 KVM, native reduces run-weighted
aggregate BPF `ns/run` on five of six retained counter populations and is
neutral/slightly slower on Tracee. Tetragon's previous native slowdown is
fixed: aggregate BPF per-run cost is now `311.8 ns/run` versus `695.2 ns/run`
for eBPF (`0.45x` cost, `2.23x` speedup). On arm64 AWS, native reduces
aggregate BPF `ns/run` for Cilium, Tetragon, Katran, and slightly for OTEL, is
slightly slower for BCC, and is substantially slower for Tracee.

**RQ4 End-to-end workload impact.** On x86 KVM, native improves workload
throughput by `1.35x` unweighted geomean across the six app workloads. It
improves over eBPF on OTEL (`1.82x`), steady-state Cilium datapath (`2.36x`),
Tetragon (`1.32x`), and Katran (`1.10x`), is neutral on BCC (`1.005x`), and is
slightly lower on Tracee (`0.958x`). On arm64 AWS, native improves workload
throughput by `1.06x` geomean, dominated by Cilium (`4.06x`) and offset by
Tracee (`0.273x`). The no-eBPF baseline remains much faster for several
tracing/security workloads, showing that hook frequency, event construction,
map traffic, perf/ring-buffer traffic, and application-side processing remain
major costs outside BPF instruction execution.

## Discussion

The results do not support the blanket claim that native-in-kernel execution is
always faster end to end. They do support a narrower and more defensible claim:
the native path lowers BPF execution cost in the controlled micro suites and in
most real-app retained counter populations, but the amount visible at workload
level depends on how much of the app's critical path is actually BPF
instruction execution.

The Tetragon investigation is the most important corrective result. The earlier
slowdown was not explained by helper indirect calls alone; current hot helper
calls are patched to direct calls. The real blockers exposed by the corpus run
were startup correctness and native-loader/app metadata mismatches: manifest
no-match handling, native replacement fd semantics, app-visible program-info
queries, stale fd reuse, and Tetragon map-id assumptions.

OTEL's `14.81x` aggregate BPF `ns/run` speedup is dominated by the directly
attached `native_tracer_entry` perf-event program. In the BPF-stats artifact,
baseline `native_tracer_e` ran 421.3M times at 3210.4 ns/run, while the native
replacement ran 432.1M times at 216.7 ns/run. The tail-called
`perf_unwind_*` programs still report zero own `run_cnt`, so their work is
charged to this caller. Inspection of the saved BPF bytecode and native object
shows a concrete hot-path cause: `get_pristine_per_cpu_record()` expands in
eBPF into many per-field stores, including the unrolled custom-label clear,
while the native object lowers the same contiguous clear to one kernel
`memset(..., 0x29c)` call. This is a real native-code advantage for this
profiler workload, but it is a caller-accounted OTEL-chain result rather than a
per-tail-target counter result. The tail call itself still matters, but mostly
as accounting and control-flow structure here: the link-time x86 native path
does not leave `bpf_tail_call` as an ordinary helper call; it lowers the
placeholder into an inline prog-array bounds check, tail-call-count check,
native cleanup, and `jmp` to `bpf_prog->bpf_func + X86_TAIL_CALL_OFFSET`.
That cost is real on deep unwind chains, but it is not the dominant explanation
for the observed OTEL entry speedup.

BCC is neutral because its hottest retained programs are already tiny and
kernel-JIT efficient. The dominant `sys_enter`/`sys_exit` tracepoints run about
3.5B times each and stay essentially unchanged (`80.9 -> 81.1 ns/run` and
`85.2 -> 85.1 ns/run`); the expensive `tracepoint__sys` instance is also
unchanged (`1207.5 -> 1226.3 ns/run`). Native shrinks translated bytecode for many
programs, but the remaining cost is hook dispatch, helper/map work, and fixed
entry/exit overhead that native code does not remove.

Tracee is a slight regression for the same reason plus cancellation among hot
raw-tracepoint dispatchers. The four hottest raw tracepoint entries run about
1.6B times each: two improve (`201.0 -> 176.9 ns/run`, `424.3 -> 413.8
ns/run`) and two regress (`363.2 -> 387.5 ns/run`, `358.5 -> 382.3 ns/run`).
Tracee's workload path also includes event construction, tail-call dispatch,
map traffic, and userspace event processing, so a near-neutral BPF `ns/run`
result can still appear as a small workload throughput loss.

On arm64 AWS, Tracee is no longer near-neutral: the BPF-stats-on artifact shows
aggregate native cost of `3435.0 ns/run` versus `931.8 ns/run` for eBPF, and
the BPF-stats-off workload artifact shows `0.273x` native/eBPF throughput. The
first arm64 stats-off attempt failed during baseline after Tracee emitted many
`net_packet_raw` decode errors and exited; an exact retry completed and is the
authoritative artifact. The failed attempt is kept in the manifest as a
non-authoritative debugging artifact rather than filtered out.

Cilium also needs careful interpretation. The measured result is steady-state
datapath throughput after endpoint setup. The runner disables drift checker,
dynamic config, dynamic lifecycle manager, endpoint BPF watchdog, and endpoint
regen interval, and stops `cilium-agent` during measured workload samples.
Those controls suppress runtime reload/regeneration during measurement. They
do not suppress required initial endpoint BPF build/regeneration during
startup, so the earlier repeated post-native loads were fixed as startup-path
and native-loader matching bugs, not as a missing autoreload flag.

## Threats To Validity

- Micro results here are x86 KVM only. The arm64 refresh covers the six-app
  corpus matrix, not micro.
- Arm64 corpus results use AWS `t4g.small`, so CPU credit behavior and cloud
  placement variance are additional threats relative to x86 KVM. The run
  remains within the benchmark's cost-conscious AWS policy; it was not upsized
  to hide variance.
- Workload throughput units differ by app. Cross-app absolute throughput is
  not a single physical unit; compare no-eBPF, eBPF, and native only within the
  same app.
- Native replacement programs are named `native_lab_stub`, so current corpus
  BPF results are app-level aggregates rather than strict program-name paired
  geomeans.
- BPF `ns/run` is a run-weighted aggregate over retained records, not a
  per-program distribution. It can be dominated by the hottest directly
  attached programs.
- Tail-called BPF programs do not increment their own `run_cnt`/`run_time` in
  normal kernel accounting. Their cost is accounted at the directly attached
  caller, so retained counter coverage must be interpreted through the call
  tree.
- Workload throughput uses the BPF-stats-off artifacts to avoid stats overhead;
  BPF per-run uses the BPF-stats-on artifact. These answer different questions
  and should not be mixed as a single run. The x86 artifacts were collected
  one app at a time on the same x86 KVM setup and kernel image during the
  2026-05-29 evaluation window. The arm64 artifacts were collected one app at
  a time on AWS `t4g.small` during the 2026-06-14 evaluation window. Time
  drift remains a possible source of variance even though the three-sample
  workload CVs are small.
- `SAMPLES=3` is sufficient for the current benchmark contract but is not a
  substitute for a full confidence-interval study over independent machine
  restarts. The table reports sample spread to make this limitation explicit.

## Appendix A: Artifact Manifest

| Dataset | Status | Generated at (UTC) | Mode | Artifact |
| --- | --- | --- | --- | --- |
| Micro pure bytecode, 4 runtimes | complete | 2026-05-29T00:39:19 | micro | `micro/results/x86_kvm_micro_20260529_003919_048557/metadata.json` |
| Micro helpers/maps, 2 runtimes | complete | 2026-05-29T00:46:58 | micro | `micro/results/x86_kvm_micro_20260529_004658_667642/metadata.json` |
| `bcc/set`, BPF stats on | complete | 2026-05-29T01:21:51 | stats on | `corpus/results/x86_kvm_corpus_20260529_005704_033715/metadata.json` |
| `bcc/set`, BPF stats off | complete | 2026-05-29T01:52:54 | stats off | `corpus/results/x86_kvm_corpus_20260529_012805_826766/metadata.json` |
| `bcc/set`, no-eBPF | complete | 2026-05-29T02:10:46 | workload-only | `corpus/results/x86_kvm_corpus_20260529_015843_382681/metadata.json` |
| `otelcol-ebpf-profiler/profiling`, BPF stats on | complete | 2026-05-29T02:40:37 | stats on | `corpus/results/x86_kvm_corpus_20260529_021623_817446/metadata.json` |
| `otelcol-ebpf-profiler/profiling`, BPF stats off | complete | 2026-05-29T03:11:28 | stats off | `corpus/results/x86_kvm_corpus_20260529_024714_858694/metadata.json` |
| `otelcol-ebpf-profiler/profiling`, no-eBPF | complete | 2026-05-29T03:29:21 | workload-only | `corpus/results/x86_kvm_corpus_20260529_031718_784847/metadata.json` |
| `cilium/agent`, BPF stats on | complete | 2026-05-29T03:59:53 | stats on | `corpus/results/x86_kvm_corpus_20260529_033517_489159/metadata.json` |
| `cilium/agent`, BPF stats off | complete | 2026-05-29T04:30:30 | stats off | `corpus/results/x86_kvm_corpus_20260529_040554_604387/metadata.json` |
| `cilium/agent`, no-eBPF | complete | 2026-05-29T04:49:28 | workload-only | `corpus/results/x86_kvm_corpus_20260529_043720_016160/metadata.json` |
| `tetragon/observer`, BPF stats on | complete | 2026-05-29T05:20:32 | stats on | `corpus/results/x86_kvm_corpus_20260529_045551_393389/metadata.json` |
| `tetragon/observer`, BPF stats off | complete | 2026-05-29T05:51:12 | stats off | `corpus/results/x86_kvm_corpus_20260529_052633_700199/metadata.json` |
| `tetragon/observer`, no-eBPF | complete | 2026-05-29T06:08:47 | workload-only | `corpus/results/x86_kvm_corpus_20260529_055644_747412/metadata.json` |
| `katran`, BPF stats on | complete | 2026-05-29T06:39:05 | stats on | `corpus/results/x86_kvm_corpus_20260529_061439_040837/metadata.json` |
| `katran`, BPF stats off | complete | 2026-05-29T07:09:11 | stats off | `corpus/results/x86_kvm_corpus_20260529_064444_673720/metadata.json` |
| `katran`, no-eBPF | complete | 2026-05-29T07:27:05 | workload-only | `corpus/results/x86_kvm_corpus_20260529_071439_317979/metadata.json` |
| `tracee/monitor`, BPF stats on | complete | 2026-05-29T07:58:33 | stats on | `corpus/results/x86_kvm_corpus_20260529_073309_993570/metadata.json` |
| `tracee/monitor`, BPF stats off | complete | 2026-05-29T08:29:31 | stats off | `corpus/results/x86_kvm_corpus_20260529_080408_588450/metadata.json` |
| `tracee/monitor`, no-eBPF | complete | 2026-05-29T08:48:07 | workload-only | `corpus/results/x86_kvm_corpus_20260529_083605_206833/metadata.json` |
| arm64 AWS `bcc/set`, BPF stats on | complete | 2026-06-14T03:03:20 | stats on | `corpus/results/aws_arm64_corpus_20260614_023819_952378/metadata.json` |
| arm64 AWS `bcc/set`, BPF stats off | complete | 2026-06-14T03:42:29 | stats off | `corpus/results/aws_arm64_corpus_20260614_031732_059541/metadata.json` |
| arm64 AWS `bcc/set`, no-eBPF | complete | 2026-06-14T04:05:25 | workload-only | `corpus/results/aws_arm64_corpus_20260614_035318_089504/metadata.json` |
| arm64 AWS `otelcol-ebpf-profiler/profiling`, BPF stats on | complete | 2026-06-14T04:42:38 | stats on | `corpus/results/aws_arm64_corpus_20260614_041820_542790/metadata.json` |
| arm64 AWS `otelcol-ebpf-profiler/profiling`, BPF stats off | complete | 2026-06-14T05:19:31 | stats off | `corpus/results/aws_arm64_corpus_20260614_045513_431087/metadata.json` |
| arm64 AWS `otelcol-ebpf-profiler/profiling`, no-eBPF | complete | 2026-06-14T05:43:17 | workload-only | `corpus/results/aws_arm64_corpus_20260614_053111_825457/metadata.json` |
| arm64 AWS `cilium/agent`, BPF stats on | complete | 2026-06-14T06:19:54 | stats on | `corpus/results/aws_arm64_corpus_20260614_055518_602472/metadata.json` |
| arm64 AWS `cilium/agent`, BPF stats off | complete | 2026-06-14T06:56:50 | stats off | `corpus/results/aws_arm64_corpus_20260614_063218_115994/metadata.json` |
| arm64 AWS `cilium/agent`, no-eBPF | complete | 2026-06-14T07:20:20 | workload-only | `corpus/results/aws_arm64_corpus_20260614_070813_221543/metadata.json` |
| arm64 AWS `tetragon/observer`, BPF stats on | complete | 2026-06-14T07:57:12 | stats on | `corpus/results/aws_arm64_corpus_20260614_073219_040724/metadata.json` |
| arm64 AWS `tetragon/observer`, BPF stats off | complete | 2026-06-14T08:34:12 | stats off | `corpus/results/aws_arm64_corpus_20260614_080917_564524/metadata.json` |
| arm64 AWS `tetragon/observer`, no-eBPF | complete | 2026-06-14T08:57:27 | workload-only | `corpus/results/aws_arm64_corpus_20260614_084524_401395/metadata.json` |
| arm64 AWS `katran`, BPF stats on | complete | 2026-06-14T09:32:49 | stats on | `corpus/results/aws_arm64_corpus_20260614_090824_742980/metadata.json` |
| arm64 AWS `katran`, BPF stats off | complete | 2026-06-14T10:09:38 | stats off | `corpus/results/aws_arm64_corpus_20260614_094513_587379/metadata.json` |
| arm64 AWS `katran`, no-eBPF | complete | 2026-06-14T18:47:43 | workload-only | `corpus/results/aws_arm64_corpus_20260614_183519_766267/metadata.json` |
| arm64 AWS `tracee/monitor`, BPF stats on | complete | 2026-06-14T19:24:51 | stats on | `corpus/results/aws_arm64_corpus_20260614_185921_546771/metadata.json` |
| arm64 AWS `tracee/monitor`, BPF stats off | complete | 2026-06-14T20:19:52 | stats off | `corpus/results/aws_arm64_corpus_20260614_195421_306838/metadata.json` |
| arm64 AWS `tracee/monitor`, no-eBPF | complete | 2026-06-14T20:43:30 | workload-only | `corpus/results/aws_arm64_corpus_20260614_203128_076343/metadata.json` |

Non-authoritative arm64 debugging artifact:

| Dataset | Status | Generated at (UTC) | Mode | Artifact |
| --- | --- | --- | --- | --- |
| arm64 AWS `tracee/monitor`, first BPF-stats-off attempt | failed | 2026-06-14T19:36:25 | stats off | `corpus/results/aws_arm64_corpus_20260614_193625_357345/metadata.json` |

## Appendix B: Reproduction Commands

Micro pure bytecode:

```sh
RUNTIMES="kernel native_kernel llvmbpf native" \
SUITE="micro/config/micro_pure_jit.yaml" \
SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 TIMEOUT=7200 \
make micro
```

Micro helpers/maps:

```sh
RUNTIMES="kernel native_kernel" \
SUITE="micro/config/micro_stage2.yaml" \
SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 TIMEOUT=7200 \
make micro
```

Corpus native with BPF runtime counters enabled:

```sh
BPFREJIT_CORPUS_APPS="<one of the six apps listed above>" \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=1 \
SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 \
BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 \
TIMEOUT=7200 \
make corpus
```

All corpus modes were collected one app at a time so any loader/startup or
workload failure would surface with a small artifact and could be fixed before
moving to the next app.

For the arm64 AWS corpus matrix, use the same corpus commands with
`PLATFORM=aws ARCH=arm64` before `make corpus`.

Corpus native with BPF runtime counters disabled:

```sh
BPFREJIT_CORPUS_APPS="<one of the six apps listed above>" \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 \
BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 \
TIMEOUT=7200 \
make corpus
```

Corpus workload-only no-eBPF baseline:

```sh
BPFREJIT_CORPUS_APPS="<one of the six apps listed above>" \
BPFREJIT_CORPUS_WORKLOAD_ONLY=1 BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 \
BPFREJIT_CORPUS_APP_TIMEOUT=3600 TIMEOUT=7200 \
make corpus
```

Post-hoc table/figure generator:

```sh
python3 docs/tmp/native_eval_20260529.py
python3 docs/tmp/native_eval_20260614.py
```

## Appendix C: Implementation Fixes In This Evaluation

- Native-loader manifest no-match handling now passes through the original
  `BPF_PROG_LOAD` fd when a manifest exists but has no matching native entry.
  This fixed Cilium short/special program variants that were previously turned
  into post-startup endpoint regeneration failures.
- The shim preserves the original program fd for native replacements and
  redirects app-visible `BPF_OBJ_GET_INFO_BY_FD` queries for replacement fds
  back to the original program metadata. This fixed Tetragon observing
  native-loader stub map ids instead of original BPF program map ids.
- The shim validates current fd type and kernel program id before redirecting
  info queries, and forgets stale loader-fd associations on fd reuse while
  preserving historical program records for runner discovery.
- Tetragon's loader now tolerates map ids that are absent from `coll.Maps` by
  falling back to map-id based metadata lookup, with a nil guard in the map
  helper path.

## Appendix D: Progress Log

- 2026-06-14: Completed the arm64 AWS app-level whole-program native
  replacement corpus matrix for all six apps, one app at a time, using
  `PLATFORM=aws ARCH=arm64`, `SAMPLES=3`, `WORKLOAD_DURATION=180`, and
  `WARMUPS=1`. The matrix includes BPF-stats-on, BPF-stats-off, and no-eBPF
  workload-only artifacts. The authoritative arm64 workload geomean is
  `1.06x` native/eBPF, with a large Cilium win (`4.06x`) and a large Tracee
  regression (`0.273x`). The first Tracee stats-off attempt failed during
  baseline with a shim socket disconnect after Tracee exited; an exact retry
  completed successfully and is the authoritative stats-off artifact. Added
  `docs/tmp/native_eval_20260614.py`,
  `docs/tmp/native_eval_20260614_summary.md`, and
  `docs/figures/eval-native-corpus-20260614.png`.
- 2026-05-29: Re-ran the authoritative x86 KVM native evaluation one app at a
  time for all six corpus apps, collecting BPF-stats-on, BPF-stats-off, and
  no-eBPF workload-only artifacts with `SAMPLES=3` and
  `WORKLOAD_DURATION=180`. Updated the paper-facing headline to `1.35x`
  workload geomean over kernel eBPF, refreshed the corpus and micro figures,
  and added `docs/tmp/native_eval_20260529.py` as the post-hoc analysis script.
- 2026-05-27: Added OSDI-reviewer-facing clarifications: a precise workload
  headline (`1.23x` unweighted geomean across six apps), workload intent and
  limitation table, native/eBPF three-sample spread, run-weighted aggregate
  wording for BPF `ns/run`, explicit no-agent/no-eBPF baseline terminology,
  Cilium steady-state datapath scope, and artifact timing/mode metadata.
- 2026-05-27: Added the OTEL native-speedup interpretation: the `15.21x`
  aggregate BPF `ns/run` speedup is dominated by directly attached
  `native_tracer_entry`; tail-call descendants are charged to that caller; and
  the native object compacts the hot-path per-CPU record clear from unrolled
  eBPF stores into a `memset(..., 0x29c)` call. Clarified that x86 native
  tail calls are lowered inline at link time, so tail-call accounting/chain
  cost matters but does not explain the OTEL speedup by itself.
- 2026-05-27: Added the BCC/Tracee neutral-regression interpretation. BCC's
  hottest tracepoints remain around the same `ns/run`, while Tracee's hottest
  raw tracepoint dispatchers contain both wins and losses that cancel at the
  aggregate counter level and leave workload throughput slightly lower.
- 2026-05-27: Reorganized this document into a paper-facing structure modeled
  after `docs/micro-bench-status.md`: framing, research questions,
  methodology, main results, RQ answers, discussion, and threats to validity.
  The previous status tables, commands, implementation fixes, caveats, and
  detailed debug history were preserved as appendices rather than removed.
- 2026-05-26: Micro stage2 completed for 13 benchmarks across
  `native`, `llvmbpf`, `native_kernel`, and `kernel`; all runtimes returned
  matching results. Geomean normalized runtime vs kernel eBPF:
  userspace native `2.29x`, userspace eBPF `1.01x`, kernel native `0.71x`,
  kernel eBPF `1.00x`.
- 2026-05-26: Micro stage1 completed for 29 benchmarks across
  `native`, `llvmbpf`, `native_kernel`, and `kernel`; all runtimes returned
  matching results. Geomean normalized runtime vs kernel eBPF:
  userspace native `0.58x`, userspace eBPF `0.65x`, kernel native `0.68x`,
  kernel eBPF `1.00x`.
- 2026-05-26: `bcc/set` corpus native-post run with BPF stats enabled
  completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_211758_813406/metadata.json`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  3 post-native workloads, and 25 BPF counter records in each phase.
- 2026-05-26: `otelcol-ebpf-profiler/profiling` corpus native-post run with
  BPF stats enabled completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_214808_410996/metadata.json`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  and 3 post-native workloads. Baseline has 13 BPF counter records; post-native
  has 12 because the zero-run `custom__generic` kprobe record is absent in the
  post app instance.
- 2026-05-26: `cilium/agent` corpus native-post run with BPF stats enabled
  failed during post-native endpoint setup, before workload measurement.
  Artifact:
  `corpus/results/x86_kvm_corpus_20260526_221732_763158/metadata.json`.
  The baseline phase completed; the post phase returned HTTP 500 from
  `PUT /v1/endpoint/0` with `timeout while waiting for initial endpoint
  generation to complete`. Shim logs show baseline loading 179 programs over
  9.1 seconds, while post-native attempted 287 program loads and 163 native
  replacements over 315.8 seconds. No individual shimmed `BPF_PROG_LOAD` call
  took seconds, so the immediate debug target is Cilium endpoint regeneration
  behavior and native object/config matching rather than one slow syscall.
- 2026-05-26: Short `cilium/agent` debug run reproduced the post-native
  endpoint timeout and captured cilium-agent logs. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_224438_925300/metadata.json`.
  The agent repeatedly failed endpoint regeneration with
  `program tail_drop_notify: load program: no such file or directory`,
  `program cil_host_policy: load program: no such file or directory`, and
  `program cil_lxc_policy_egress: load program: no such file or directory`.
  The shim logged `native-loader enabled but no manifest object` for the same
  programs even though the symbols exist in the native objects; the miss came
  from `source_map_prefix` disambiguation on short/special Cilium variants.
  Fixed the shim so a present manifest with no matching entry keeps the
  original `BPF_PROG_LOAD` fd, while true manifest/object/native-loader errors
  still fail.
- 2026-05-26: Short `cilium/agent` verification run after the shim fix
  completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_225719_943967/metadata.json`.
  The app payload has status `ok`, empty error string, one baseline workload,
  one post-native workload, 53 baseline BPF counter records, and 50 post-native
  BPF counter records. The post shim log shows 113 native replacements and
  22 explicit `no manifest match` pass-throughs for the short/special Cilium
  variants; the previous `load program: no such file or directory` endpoint
  failures are gone.
- 2026-05-26: Checked the Cilium reload controls in the corpus runner.
  `CiliumRunner` already starts `cilium-agent` with
  `--enable-drift-checker=false`, `--enable-dynamic-config=false`,
  `--enable-dynamic-lifecycle-manager=false`,
  `--endpoint-bpf-prog-watchdog-interval=0`, and
  `--endpoint-regen-interval=0`; it also sends `SIGSTOP` to the agent during
  workload samples after endpoint setup. These controls suppress continuous
  userspace reload/regeneration during measurement. They do not suppress the
  required initial endpoint BPF build/regeneration that happens while creating
  endpoints in baseline and post-native startup, so the earlier post-native
  repeated loads are being treated as startup-path failures or manifest
  mismatches, not as a missing autoreload flag.
- 2026-05-26: Authoritative `cilium/agent` corpus native-post run with BPF
  stats enabled completed successfully after the shim manifest no-match fix.
  Artifact:
  `corpus/results/x86_kvm_corpus_20260526_230251_020975/metadata.json`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  3 post-native workloads, 62 baseline BPF counter records, and 62 post-native
  BPF counter records. The post shim log shows 201 `BPF_PROG_LOAD` calls,
  113 native replacements, and 22 explicit manifest no-match pass-throughs.
  No `load program: no such file`, `phase_error`, or endpoint regeneration
  failure string was found in the app payload or post shim log.
- 2026-05-26: Authoritative `tetragon/observer` corpus native-post run with
  BPF stats enabled failed during post-native startup, before workload
  measurement. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_233252_573223/metadata.json`.
  The baseline phase completed with 3 workload samples and 171 BPF counter
  records. The post phase exited after 31 `BPF_PROG_LOAD` calls, 6 native
  replacements, and 4 manifest no-match pass-throughs. Tetragon panicked in
  `ExtendedInfoFromMap(collMaps[id])` because `Program.Info().MapIDs()`
  returned a map id not present in the libbpf collection map table. Root cause:
  the shim returned the native-loader stub fd to the app, so app-visible
  `BPF_OBJ_GET_INFO_BY_FD` observed native-loader program metadata instead of
  original BPF program metadata. Fix target: preserve the original loaded BPF
  prog fd inside the shim and redirect app-visible prog info queries for the
  replacement fd back to that original fd.
- 2026-05-26: Short `tetragon/observer` verification run after adding the
  shim program-info redirect still failed with the same loader panic. Artifact:
  `corpus/results/x86_kvm_corpus_20260526_235351_389554/metadata.json`.
  The shim log confirms `BPF_OBJ_GET_INFO_BY_FD` redirects were active for
  replaced program fds, so the remaining bug is Tetragon's loader assuming
  every `ProgramInfo.MapIDs()` entry has a non-nil entry in `coll.Maps`.
  That assumption is not valid for all loaded program/map combinations. Fixed
  Tetragon's loader to fall back to `ExtendedInfoFromMapID(id)` when the map id
  is absent from `coll.Maps`, and added a nil guard in
  `ExtendedInfoFromMap()`.
- 2026-05-27: Short `tetragon/observer` verification run progressed past the
  previous nil dereference and loaded the base sensor, then failed while loading
  the generic kprobe sensor. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_000124_646747/metadata.json`.
  The error showed `tg_stats_map` map metadata as impossible values
  (`Hash` with random key/value sizes instead of the expected `PerCPUArray`).
  Shim log confirmed fd reuse: a closed native program fd was later reused by a
  map, but stale program state still caused the map's
  `BPF_OBJ_GET_INFO_BY_FD` query to be redirected to the old original program
  fd. Fixed the shim to remove stale same-fd state whenever a new BPF/perf fd
  is recorded, and to redirect object-info queries only when the current fd is
  still a BPF program with the expected kernel program id.
- 2026-05-27: The first smoke after that fd-reuse fix was interrupted because
  baseline `tetragon/observer` stayed in runner-side `list_progs` polling.
  Artifact directory:
  `corpus/results/x86_kvm_corpus_20260527_000825_189724/`.
  The bug was an over-fix in the shim: when a new map/link/perf/raw-tracepoint
  fd reused a closed program fd, the shim deleted the old `prog_entry`
  entirely. That prevents bad app-visible info redirects, but it also removes
  the historical program record that the corpus runner needs from
  `list_progs`. Fixed forward by changing the fd-reuse handling to call
  `prog_forget_loader_fd()`: the current fd is no longer treated as that
  program for future fd-based lookups, while the kernel program id,
  bytecode path, and map snapshot remain available for runner discovery.
- 2026-05-27: Short `tetragon/observer` smoke after preserving historical
  program records completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_001857_499465/metadata.json`.
  The app payload has status `ok`, empty error string, one baseline workload,
  one post-native workload, 111 baseline BPF counter records, and 101
  post-native BPF counter records. The post shim log shows 316
  `BPF_PROG_LOAD` calls, 288 native replacements, 5 manifest no-match
  pass-throughs, and 864 program-info redirects. No `panic`,
  `map spec is incompatible`, `load program: no such file`, or `phase_error`
  string was found in the artifact. This verifies the startup correctness
  chain: native replacement keeps original program info visible to the app,
  Tetragon handles map ids absent from `coll.Maps`, and fd reuse no longer
  redirects map info queries to stale program fds.
- 2026-05-27: Authoritative `tetragon/observer` corpus native-post run with
  BPF stats enabled completed successfully after the startup correctness
  fixes. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_002557_893190/metadata.json`.
  The metadata status is `completed`, with `samples=3`,
  `workload_seconds=180.0`, `bpf_stats=true`, and `workload_only=false`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  3 post-native workloads, 287 baseline BPF counter records, and 287
  post-native BPF counter records. The post shim log shows 316
  `BPF_PROG_LOAD` calls, 288 native replacements, 5 manifest no-match
  pass-throughs, and 864 program-info redirects. No `panic`,
  `map spec is incompatible`, `load program: no such file`,
  `native-loader enabled but no manifest object`, or `phase_error` string was
  found in the artifact.
- 2026-05-27: Authoritative `katran` corpus native-post run with BPF stats
  enabled completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_005602_704153/metadata.json`.
  The metadata status is `completed`, with `samples=3`,
  `workload_seconds=180.0`, `bpf_stats=true`, and `workload_only=false`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  3 post-native workloads, 1 baseline BPF counter record, and 1 post-native
  BPF counter record. The post shim log shows the expected replacement of the
  standalone XDP program `balancer_ingres` with native symbol
  `balancer_ingress`; feature-probe programs were skipped. No `panic`,
  `map spec is incompatible`, `load program: no such file`,
  `native-loader enabled but no manifest object`, `phase_error`, or endpoint
  regeneration failure string was found in the artifact.
- 2026-05-27: Authoritative `tracee/monitor` corpus native-post run with BPF
  stats enabled completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_012602_194852/metadata.json`.
  The metadata status is `completed`, with `samples=3`,
  `workload_seconds=180.0`, `bpf_stats=true`, and `workload_only=false`.
  The app payload has status `ok`, empty error string, 3 baseline workloads,
  3 post-native workloads, 167 baseline BPF counter records, and 167
  post-native BPF counter records. The post shim log shows 183
  `BPF_PROG_LOAD` calls and 169 native replacements. No `panic`,
  `map spec is incompatible`, `load program: no such file`,
  `native-loader enabled but no manifest object`, `phase_error`, or endpoint
  regeneration failure string was found in the artifact.
- 2026-05-27: Authoritative six-app corpus native-post run with BPF stats
  disabled completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_015711_134639/metadata.json`.
  Command knobs: `BPFREJIT_CORPUS_BPF_STATS=0`,
  `BPFREJIT_SHIM_NATIVE_LOADER=post`, `SKIP_REJIT=norejit`, `SAMPLES=3`,
  and `WORKLOAD_DURATION=180`. Metadata status is `completed`, with
  `bpf_stats=false` and `workload_only=false`. All six app payloads have
  status `ok`, empty error strings, and 3 baseline plus 3 post-native stored
  workload samples. Program metadata lists are still present in app JSON, but
  all BPF `run_cnt_delta` and `run_time_ns_delta` values sum to zero, so this
  artifact is for workload raw-metric comparison only. No `panic`,
  `map spec is incompatible`, `load program: no such file`,
  `native-loader enabled but no manifest object`, `phase_error`, or endpoint
  regeneration failure string was found in the artifact.
- 2026-05-27: Authoritative six-app corpus workload-only no-eBPF run
  completed successfully. Artifact:
  `corpus/results/x86_kvm_corpus_20260527_043130_139245/metadata.json`.
  Command knobs: `BPFREJIT_CORPUS_WORKLOAD_ONLY=1`,
  `BPFREJIT_CORPUS_BPF_STATS=0`, `SAMPLES=3`, and
  `WORKLOAD_DURATION=180`. Metadata status is `completed`, with
  `bpf_stats=false` and `workload_only=true`. All six app payloads have
  status `ok`, empty error strings, and 3 stored workload samples. In
  workload-only mode those samples are stored under `.baseline.workloads[]`;
  `.post_rejit.workloads[]` is empty, `rejit_result.mode` is
  `workload_only`, and no BPF program counter records are present. This
  artifact is the no-eBPF workload baseline.
- 2026-05-27: Generated the combined corpus figure requested for result
  inspection:
  `docs/figures/eval-native-corpus-combined-side-by-side-ns-bars.png`. The
  left subplot is workload throughput normalized to no eBPF with three
  vertical bars per app; the right subplot is raw BPF per-run cost in ns/run
  with two vertical bars per app, eBPF JIT and native-in-kernel. Older corpus
  figure files were kept in place.
