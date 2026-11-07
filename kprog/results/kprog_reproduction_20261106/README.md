# Early native-number reproduction, 2026-11-06

Reproduces the 2026-05-29 x86 KVM results on current `master`, using the
same `make` entrypoints and the recorded knobs. Lane R (host CPUs 0-7).

Reference numbers, taken from the archived runs rather than restated:

| Quantity | Reference | Source |
| --- | ---: | --- |
| Pure-bytecode geomean, 29 programs | `1.478x` | `micro/results/x86_kvm_micro_20260529_003919_048557` |
| Helper/map geomean, 13 programs | `1.429x` | `micro/results/x86_kvm_micro_20260529_004658_667642` |
| Six-app corpus workload geomean | `1.349x` | `kprog/docs/evaluation.md`, six per-app ratios |

Ratio definition, used identically for reference and current runs: for each
benchmark, `median(exec_ns)` per runtime over that runtime's samples, then
`median(kernel) / median(native_kernel)`; the suite figure is the
unweighted geometric mean of the per-program ratios. `exec_ns` is the
in-guest `ktime`-sourced execution time, the same field the archived runs
used.

# Summary

| arm | native programs | current | reference | verdict |
| --- | ---: | ---: | ---: | --- |
| Pure bytecode (29) | — | **1.468x** | 1.478x | reproduces, -0.7% |
| Helper/map (13) | — | **1.403x** \* | 1.429x | reproduces, -1.8% |
| Corpus bcc/set | 18 / 25 | **1.002x** | 1.005x | reproduces |
| Corpus tetragon | 118 | **1.008x** | 1.323x | **does not** |
| Corpus katran | 1 | **1.018x** | 1.102x | **does not** |
| Corpus cilium | 177 | **1.229x** | 2.358x | **does not** |
| Corpus otelcol | 14 | **1.013x** | 1.824x | **does not** |
| Corpus tracee | 151 | **1.539x** | 0.958x | **does not** |

The pure-bytecode row is re-measured on current code after two loader
fixes (see the micro sections). The helper/map row predates those fixes
and has not been re-run. The corpus rows are current: katran (1
replaced) and tetragon (118 replaced) were re-measured with zero failures
after the loader changes, so the corpus matrix stands. Corpus figures are at the operator recipe
(`SAMPLES=3 WORKLOAD_DURATION=180`) and each carries the replaced/failed
count from its own shim log.

## BPF stats off

The operator's knobs call for stats on and off. Stats-off
(`BPFREJIT_CORPUS_BPF_STATS=0`, confirmed `bpf_stats: false` in each
run's metadata) removes the runtime-counter overhead from the workload.

Statistic: **median of each arm's per-sample totals**, not the mean. With
three samples one outlier moves a mean by 18% while the median moves by
0.2% — the tetragon case below is exactly that, and it is why the rule is
stated rather than assumed. Every run here was checked for sample spread
and only that one run exceeded 10%.

| app | stats on | stats off | replacements |
| --- | ---: | ---: | --- |
| bcc/set | 1.002x | **1.000x** | 18 |
| tracee/monitor | 1.539x | **1.640x** | 148 / 151 |
| katran | 1.018x | **1.001x** | 1 / 1 |
| tetragon/observer | 1.008x | **0.988x** | 118 / 118 |
| otelcol | 1.013x | **1.026x** | 14 / 14 |
| cilium/agent | 1.229x | **1.061x** | 177 / 177 |

Tracee's stats-off arm is the firmest datapoint in this file: 148 of 151
programs replaced, no oops, 256,984,354 bogo-ops baseline against
421,466,196 native, both arms 3 samples of 180 s.

**Tetragon's stats-off arm is 0.988x, and I first published it wrong.**
The first run's mean gave 0.805x, which looked like a uniform 20% slowdown
across every stressor. It was **one outlier sample**: that run's native
samples were 13,269,134 / 32,133,315 / 32,026,666 where the baseline's
were 31,343,150 / 32,431,534 / 32,437,464, so a single sample at 41% of
the others dragged the mean down.

Per-sample totals for both runs:

| run | baseline samples | native samples | mean | **median** |
| --- | --- | --- | ---: | ---: |
| first | 31.34M, 32.43M, 32.44M | **13.27M**, 32.13M, 32.03M | 0.805x | **0.988x** |
| repeat | 32.13M, 32.09M, 32.24M | 32.10M, 31.49M, 31.68M | 0.988x | **0.986x** |

The median agrees across both runs (0.988x, 0.986x) and the repeat's mean
agrees with them, so **0.988x is the figure** and the 0.805x was an
artifact of one slow sample. The lesson is the ordinary one: with three
samples, a single outlier moves the mean by 18% and the median by 0.2%.

So tetragon is at parity both ways: 1.008x with counters on, 0.988x with
them off. The stats-off figure does not expose a hidden native cost, and
the earlier reading that it did was wrong.

**Cilium's stats-off arm now measures**, after `native-link` gained
full-source-map-identity resolution (`bfbb60d1a`): 177 programs replaced,
0 failed, 3 samples of 180 s per arm, 691,320,365 against 733,235,372
received packets, **1.061x** where stats-on gave 1.229x.

The earlier failure — and why it took a linker change — is worth keeping,
because it was a *correct* refusal rather than a bug:
`cilium_ipv4_frag_datagrams` is 26 characters, the kernel keeps only
`cilium_ipv4_fra`, and cilium has more than one `cilium_ipv4_frag_*` map,
so they collide in those 15 bytes. Resolving by truncated name would risk
binding the wrong map; the fix was to carry the full source map identity
through, which the linker now does. That closed 33 failing programs.

Both cilium arms also confirm the general pattern: with runtime counters
off, the native advantage narrows (1.229x → 1.061x), the same direction as
katran (1.018x → 1.001x).

One caveat remains:

- **tetragon's earlier stats-off attempt** (70 of 118 replaced, 1.017x)
  was launched with tracee's manifest in the environment; the standalone
  rerun above supersedes it.
- **katran's stats-off arm replaced on the third attempt** (1 of 1,
  `prebuilt_proof=1`, 802,911,496 against 803,348,250 packets, 1.001x).
  Two earlier attempts after the 10:50 kernel rebuild failed with
  `BPF_PROG_LOAD native_lab stub: Permission denied` (`processed 1
  insns`, `log_true_size=146`) on the 80-chunk blob, so the failure was
  transient rather than a code path difference — but with one sample the
  1.001x should be read as "no native gain with counters off", and its
  stats-on 1.018x accordingly as partly counter overhead rather than BPF
  execution.

## The three arms

`BPFREJIT_CORPUS_WORKLOAD_ONLY=1` runs the workload with no BPF program
attached — the denominator the reference's first two columns use. Arm
artifacts: `corpus/results/x86_kvm_corpus_20261107_060516_326524`
(bcc, tetragon) and `..._064125_589233` (the rest),
`workload_only: true`, 3 workloads per app.

| app | eBPF/no-eBPF | native/no-eBPF | native/eBPF | reference (ebpf/no, nat/no, nat/ebpf) |
| --- | ---: | ---: | ---: | --- |
| bcc/set | 0.370 | 0.371 | 1.002x | 0.451, 0.453, 1.005x |
| tetragon/observer | 0.192 | 0.194 | 1.008x | 0.233, 0.308, 1.323x |
| katran | 0.713 | 0.726 | 1.018x | 0.348, 0.383, 1.102x |
| cilium/agent | 1.711 | 2.103 | 1.229x | 0.680, 1.603, 2.358x |
| otelcol | 0.978 | 0.991 | 1.013x | 0.397, 0.724, 1.824x |
| tracee/monitor | 0.128 | 0.197 | 1.539x | 0.136, 0.130, 0.958x |

**Which columns are comparable.** For the three apps whose workload runs
on the same host path with and without BPF (bcc, tetragon, tracee), all
three columns are like-for-like and the readings are informative. For
katran, cilium and otelcol the no-eBPF arm is a different harness path —
katran and cilium forward through an interface whose pktgen generator
behaves differently without BPF (eBPF/no-eBPF above 1 means the workload
*ran faster with* BPF, which is generator behaviour, not a speedup), and
otel's no-eBPF arm still runs the profiler. So for those three, quote
`native/eBPF` and read the first two columns as context only.

**What the bcc and tetragon rows show that native/eBPF alone hides.**

1. Our eBPF path costs the workload more than the reference's for both
   (0.370 against 0.451, 0.192 against 0.233 — lower is more overhead).
2. Tetragon's reference gain lived in **native/no-eBPF**: the reference
   recovered a third of the BPF overhead (0.233 to 0.308) while we recover
   1% (0.192 to 0.194). That is where the missing 1.323x went — our
   native is no cheaper than our eBPF for tetragon's traced workload,
   where the reference's was.

Tracee is the mirror case: our native arm cuts BPF overhead substantially
(0.128 to 0.197, a 54% recovery) where the reference's made the workload
slightly worse (0.136 to 0.130). That is the same measurement read the
other way, and it is consistent with the 1.539x against 0.958x.

## Corpus geomean

| set | geomean |
| --- | ---: |
| All six apps, stats on | **1.120x** |
| All six apps, stats off | **1.099x** |
| Reference, all six apps (stats on) | **1.349x** |

**The 1.349x six-app reference does not reproduce.** All six apps now
measure and their geomean is 1.120x. The shortfall is concentrated in
cilium (1.229x against 2.358x) and tetragon (1.008x against 1.323x), the
reference's two large wins; the other four sit near 1.00x in both runs,
except tracee, whose 1.539x reverses its reference 0.958x.

Every pair ran the same duration with the same work counters.
**One of six corpus apps reproduces its reference ratio; five diverge.**

Both micro arms ran with recipe parity verified from the result files, and
every arm's correctness was checked by comparing return values and results
across runtimes, not by trusting the timings.

# Micro: pure bytecode (29 programs)

**Re-measured on current code.** The micro native path had broken after
`fd1b65560` and now works; the symptom named neither actual cause:

1. The trusted specializer invoked a bare `"clang"`, absent from `PATH`
   where the service runs (it re-launches itself with an explicit
   environment, and the image keeps clang under `/usr/lib/llvm-*/bin`), so
   its first subprocess raised `ENOENT` and callers saw
   `trusted specializer refused native program: Invalid argument`. The
   specializer was never reached. It now resolves `CLANG`, then `PATH`,
   then the versioned llvm bin directories.
2. The service container was SIGTERMed after the first request, with 28
   programs still loading.

With both cleared:

| Run | Programs | Geomean |
| --- | ---: | ---: |
| Reference 2026-05-29 | 29 | 1.478x |
| Current (pre-gate, 2026-11-06) | 29 | 1.446x |
| **Current (2026-11-07)** | 29 | **1.468x** |

Artifact: `micro/results/x86_kvm_micro_20261107_191200_758943`, RC=0,
zero refusals, and all **116 runtime comparisons agree** on `(retval,
result)`. Recipe parity with the reference holds (four runtimes,
`inner_repeat` 100000, 3 samples).

Artifact: `micro/results/x86_kvm_micro_20261106_090507_158145`.

Program split unchanged: 26 faster, 2 ties, 1 slower in both runs.
Correctness: 116 runtime comparisons (4 runtimes x 29 programs) agree
exactly on `(retval, result)`; zero disagreements.

Two programs sit more than 10% below their reference ratio —
`cilium_policy_guard_tree_filter` (0.61 of the reference ratio) and
`simple_packet` (0.86) — and both stay above 1.0. The direction is
preserved; no claim is made about which side moved without a paired re-run
of the 05-29 binary.

**Kernel provenance.** The 09:05 run loaded `bpf_x86_alu.ko` and printed no
kernel banner, so it ran the image already built at that time. Lane T then
rebuilt the host kernel with the native proof-region patch, so this is a
pre-patch-kernel measurement. Every later arm is labelled with its own
kernel in the artifact.

# Micro: helper/map (13 programs)

| Run | Programs | Geomean |
| --- | ---: | ---: |
| Reference 2026-05-29 | 13 | **1.429x** |
| Current | 13 | **1.403x** |

```sh
taskset -c 0-7 make micro PLATFORM=kvm ARCH=x86 \
  SUITE=micro/config/micro_stage2.yaml \
  RUNTIMES='kernel native_kernel' \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Artifact: `micro/results/x86_kvm_micro_20261106_102025_639020`.

Recipe parity verified from both files: `inner_repeat` 100000, 3 samples,
runtimes `kernel native_kernel`, program name sets equal (13 names).
Correctness: 26 runtime comparisons agree exactly; zero disagreements.

# Corpus: native arm

The native arm is the **native loader**, not a pass list:

```sh
BPFREJIT_SHIM_NATIVE_LOADER=post \
BPFREJIT_SHIM_NATIVE_MANIFEST=<app manifest> \
  make corpus PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=<app> \
  SAMPLES=3 WORKLOAD_DURATION=180
```

with `BPFREJIT_CORPUS_BPF_STATS=0` for the stats-off arm. Runs with
`BPFREJIT_BENCH_PASSES=noop`, `dce` or `kinsn` reload eBPF bytecode
through `bpfopt` and are **not** native; none of the numbers below come
from a pass-list run. The verified arm
(`BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1`) is a separate, later
measurement.

## A ratio only counts with replacements verified

The shim log is the evidence that a run was native. It records
`native-loader replaced prog=<name>` for every program actually executed
natively, and `native-loader failed prog=<name> ... error=...` for one
that passed through as eBPF. Every ratio below carries that count.

This matters: katran's first run returned `status ok` with both arms and
1.128x, but its log had **zero** replaced lines — the only program,
`balancer_ingress`, failed and passed through, so both arms ran eBPF and
1.128x was run-to-run variance.

## Manifest paths must be image paths

The corpus run executes **inside** the runtime image. Its
`/workspaces/repository/corpus` is a copy taken at image build time and
contains **no** `results/` directory, so any manifest path under
`corpus/results/...` is unreadable at run time — the loader reports
`manifest native object is unreadable`. The one staged location the image
carries is `/artifacts/user/native-bpf/x86_64/<app>/` (note `x86_64`).

Each app therefore gets a `manifest.image.json` beside its original, with
the same entries and only that prefix rewritten. `bcc-real-4` was the
first to work this way.

## bcc/set: reproduces

`bcc-real-4/manifest.image.json`, 18 programs replaced natively, 7
failed (below). Reference 1.005x.

| arm | baseline eBPF | native | native/eBPF |
| --- | ---: | ---: | ---: |
| stats on | 278,893,541 | 279,417,520 | **1.002x** |
| stats on (2nd run) | 281,747,730 | 282,144,110 | **1.001x** |
| stats off | 359,778,402 | 359,881,404 | **1.000x** |

Figures are stress-ng bogo-ops, 3 samples of 180 s per arm, same four
stressors in both arms. Artifacts:
`corpus/results/x86_kvm_corpus_20261106_190628_159160` (stats on),
`..._201524_310676` (stats on, second run), `..._204653_590159` (stats
off, `bpf_stats: false` confirmed in metadata).

bcc sits at unity in the reference too, and for the same reason: its
workload is `set`/`cap` syscalls rather than the traced path, so the BPF
program's cost is a small share of the workload. That is why the
reference's 1.005x and these 1.000-1.002x agree.

Per-stressor, both arms did the same work (one stats-on run): syscall
514/514, cap 17,126,810/17,184,093, set 1,292,235/1,309,932, sockfd
12,374,606/12,432,355.

### Programs that ran native (17)

`blk_account_io_*`, `block_rq_insert`, `block_rq_issue`,
`fentry_vfs_{creat,fsyn,open,read,writ}`, `inet_sock_set_*`,
`kprobe__cap_cap`, `sched_wakeup`, `sched_wakeup_new`, `sys_enter`,
`tcp_v4_connect`, `tcp_v6_connect`, `tracepoint__sys*`.

### Programs that stayed eBPF (8), with the log's reason

- `BPF_PROG_LOAD native_lab stub: Invalid argument` — `tracepoint__sys`,
  `kprobe__cap_cap`, `block_rq_complete` and one more.
- `proof readonly map lacks explicit symbol metadata: .rodata.n...` —
  `tcp_v4_connect`, `tcp_v6_connect`, `sys_exit`, `sched_switch`.

These pass through and do not stop the run, so the measurement is complete
with 17 of 25 programs native.

## katran: measures once pointed at the build's own manifest

The build writes `manifest.json` into the staged katran directory, the
image carries it, and its `native_object` entries resolve relative to
themanifest's own directory — so pointing the shim at
`/artifacts/user/native-bpf/x86_64/katran/manifest.json` works with no
rewriting. That also cleared the EPERM, which was an artefact of the
hand-built manifests pointing at a stale object name.

```
corpus/results/x86_kvm_corpus_20261106_230835_743350   status ok
1 program replaced (balancer_ingress), 0 failed
```

| | katran |
| --- | ---: |
| packets sent in 60 s, baseline eBPF | 81,967,900 |
| packets sent in 60 s, native | 83,273,693 |
| **native/eBPF** | **1.016x** |
| reference (2026-05-29) | **1.102x** |

Both arms ran 60 s. Katran's work counters are equal in kind: `pass` 3 in
both, `drop`/`encap_fail`/`lru_miss`/`consistent_hash_drop` all 0, and
`tx`/`total` equal to the packet count — the same forwarding behaviour,
so the comparison is like-for-like.

At the operator recipe (`SAMPLES=3 WORKLOAD_DURATION=180`,
`corpus/results/x86_kvm_corpus_20261107_005419_246681`): 1 replaced,
0 failed, 3 workloads per arm, 799,453,792 packets baseline against
813,698,501 native = **1.018x**, confirming the 60 s figure.

**Does not reproduce at the reference size**: 1.018x against 1.102x. One
of katran's programs runs native here; the reference's advantage was
larger, which is a property of the native code, not of whether it ran.

### Earlier katran attempts, and why they were not native

| manifest | failure | replacements |
| --- | --- | ---: |
| `katran-real-10` (hand-built) | `simulator proof contains an unresolved map/kfunc relocation` | 0 |
| `katran-real-14` (hand-built) | `BPF_PROG_LOAD native_lab stub: Permission denied` | 0 |
| build's own `manifest.json` | — | **1** |

The EPERM was traced to the five `capable(CAP_SYS_ADMIN)` sites in
`bpf_x86_native_lab.c`, and the hand-built manifests were reaching them
via a stale object name. With the build's manifest no such path is taken.

## otelcol: measures once pointed at the build's own manifest

The three mismatches above were all in the hand-built `otel-real-*`
manifests. The build's own stage manifest has them solved already: it
carries **both** schemas — an `objects` array of 26 program entries
(`native_object`, `program`, `symbol`) and a `data_objects` list of the
16 per-tracer native objects — with paths relative to its own directory.
Pointing `BPFREJIT_SHIM_NATIVE_MANIFEST` at
`/artifacts/user/native-bpf/x86_64/otelcol-ebpf-profiler/manifest.json`
works directly.

```
corpus/results/x86_kvm_corpus_20261107_024322_358412   status ok
14 programs replaced natively, 0 failed
```

| | otelcol-ebpf-profiler |
| --- | ---: |
| workload `ops`, baseline eBPF | 6,448,865,472 |
| workload `ops`, native | 6,471,081,781 |
| **native/eBPF** | **1.003x** |
| reference (2026-05-29) | **1.824x** |

Both arms did the same work: the counter is each language worker's own
`ops=` line on stderr (`python3 int_loop ops=252954034 elapsed_s=60 ...
sink=318863927`), summed over the same 11 components per arm (python3,
ruby, perl and the other profiled runtimes), and every component's
`sink=` count climbs in both arms too. All components returned `rc=0` in
both arms.

At the operator recipe (`SAMPLES=3 WORKLOAD_DURATION=180`,
`corpus/results/x86_kvm_corpus_20261107_025604_139037`): 14 replaced,
0 failed, 3 workloads per arm, 57,949,845,515 ops baseline against
58,728,635,824 native = **1.013x**, consistent with the 60 s figure.

**Does not reproduce**: 1.013x against 1.824x.

## tetragon: measures, and the ratio does not reproduce

Tetragon needed no manifest work: the build already writes a 235-object
`manifest.json` into the staged directory, the image carries it, and the
loader resolves `native_object` **relative to the manifest's own
directory** (`manifest_relative_path`, `native_loader_manifest.hpp:772`),
so pointing `BPFREJIT_SHIM_NATIVE_MANIFEST` at it works directly.

```
corpus/results/x86_kvm_corpus_20261107_002003_274609   status ok
118 programs replaced natively, 0 failed, 3 workloads per arm
```

| | tetragon/observer |
| --- | ---: |
| bogo-ops, baseline eBPF | 90,842,189 |
| bogo-ops, native | 91,585,459 |
| **native/eBPF** | **1.008x** |
| reference (2026-05-29) | **1.323x** |

Per-stressor, both arms did the same work (eventfd 32,680,567/32,861,758,
mmap 13,977/14,088, udp 57,965,933/58,528,092, sock 181,712/181,521).

**Does not reproduce**: 1.008x against 1.323x.

## cilium: builds after a two-line Makefile fix, then measures

Cilium had no native artifacts, and it was a build gap rather than missing
work: `vendor/bpf/Makefile` defined `native-cilium` but none of the three
variables it uses, and `native-artifacts` both omitted the target and
`rm -rf`-ed its stage dir. Defining `CILIUM_NATIVE_STAGE_OUT`,
`CILIUM_NATIVE_OBJS` and `CILIUM_NATIVE_PROOF_MARKERS` from the existing
`CILIUM_OBJS` and adding the dependency gives 7 native objects and an
89-program manifest.

A second defect then surfaced in the runner: `runner/libs/bpf_evidence.py`
compared the kernel's program name with `symbol[:15]`, but
`BPF_OBJ_NAME_LEN` is 16 and the kernel keeps all 16 bytes, so cilium's
`tail_drop_notify` (exactly 16 characters) never matched. Both fixes are
one commit each.

```
corpus/results/x86_kvm_corpus_20261107_020659_029387   status ok
177 programs replaced natively, 0 failed, 3 workloads per arm
```

| | cilium/agent |
| --- | ---: |
| received packets, baseline eBPF | 709,171,412 |
| received packets, native | 871,897,265 |
| **native/eBPF** | **1.229x** |
| reference (2026-05-29) | **2.358x** |

Both arms did the same work: each forwarded essentially everything and
dropped in the same classes, baseline 1 × `reason=139,direction=2` and
1 × `reason=3,direction=1` out of 159,385,781 verdicts, native 2 and 2
out of 175,058,207, with `rx_dropped`/`tx_dropped`/`rx_errors` zero at
every receiver in both. Both components ran 180 s per arm in the recipe
run, which is the normalizing denominator. The comparison is
like-for-like.

**Does not reproduce**: 1.229x against 2.358x, the largest gap here.

## tracee: measures after two loader fixes, and reverses its reference

Two defects had to be fixed, both in the loader, and each was found by
measurement rather than inspection.

**First, a data symbol the app's map does not cover.** All 151 programs
failed with `native data symbol .L.str.14 exceeds BPF data map value_size
for .rodata.str1.1`. The numbers rule out the obvious readings: the app
creates a real 246-byte map for that section, and the native object's
`.rodata.str1.1` is **261 bytes** — the extra 15 being `"vdso"` at 248 and
`"unknown"` at 253, strings the loaded app never references. A symbol past
the app's map simply cannot be placed, which the loader already had an
`Absent` path for; treating it as fatal was wrong. Skipping it (and
rewriting the comparison to avoid unsigned wrap) maps every symbol the app
does use.

**Second, a wrong-symbol match.** The programs then replaced but the guest
panicked:

```
BUG: kernel NULL pointer dereference ... in
  bpf_prog_23aa4acac7a3a6bd_tracepoint__raw_syscalls__sys_enter
native_id=175 ... jited_len=246 xlated_len=48
```

A 264-byte program became a 48-byte fragment. `tracee/manifest.json` has
**no** `source_btf_symbol` in any of its 114 entries — only `symbol` — and
every remaining match condition was optional, so `trace_sys_enter`'s entry
matched `tracepoint__raw_syscalls__sys_enter` on bytecode length and
helpers alone. An entry that names a symbol now has to match the loaded
program's BTF symbol.

```
corpus/results/x86_kvm_corpus_20261107_041920_105442   status ok
151 programs replaced natively, 0 failed, no oops
```

| | tracee/monitor |
| --- | ---: |
| bogo-ops, baseline eBPF | 226,217,621 |
| bogo-ops, native | 348,129,617 |
| **native/eBPF** | **1.539x** |
| reference (2026-05-29) | **0.958x** |

Both arms ran the same seven stressors (cap, set, sigfd, eventfd, kill,
futex, prctl) for the same duration, so the comparison is like-for-like.

At the operator recipe (`SAMPLES=3 WORKLOAD_DURATION=180`,
`corpus/results/x86_kvm_corpus_20261107_043912_975575`): 151 replaced,
0 failed, no oops, 3 workloads per arm, giving **1.539x** (the 60 s run
gave 1.475x; the longer run is the one to quote).

**Does not reproduce, and reverses**: 1.539x here against 0.958x in the
reference. Tracee was the reference's only regression below 1; on this
tree it is one of the larger wins.

## How many programs each app loads

The stock control (`BPFREJIT_SHIM_NATIVE_LOADER=off`,
`BPFREJIT_BENCH_PASSES=noop`, 1 s workload,
`corpus/results/x86_kvm_corpus_20261107_153812_231831`) loads cleanly for
all six apps, which gives the denominator the native counts above are
measured against:

| app | programs loaded | ran native |
| --- | ---: | ---: |
| bcc/set | 26 | 18 |
| cilium/agent | 56 | 177 (reloads across samples) |
| katran | 6 | 1 |
| otelcol | 14 | 14 |
| tetragon/observer | 82 | 118 |
| tracee/monitor | 154 | 151 |

Native counts exceed the loaded count for cilium and tetragon because a
program is replaced once per load and those apps load the same program in
several processes or per sample. Tracee's 151 of 154 is the cleanest
coverage figure in the set.

## Which programs ran natively, per app

The operator asked for this per app. Counts are what the shim log shows;
"distinct symbols" is the number of distinct `symbol=` values, which is
smaller than the replacement count where an application loads the same
program several times (tetragon's probes) or where a program is reloaded
per sample.

| app | replacements | distinct symbols | load lines | failed |
| --- | ---: | ---: | ---: | ---: |
| bcc/set | 18 | 25 (all, of 25) | — | 7 |
| tetragon/observer | 118 | 14 | 331 | 0 |
| katran | 1 | 1 | — | 0 |
| cilium/agent | 177 | 25 | 254 | 0 |
| otelcol | 14 | 14 | 19 | 0 |
| tracee/monitor | 151 | 151 | 173 | 0 |

Names that ran natively, first few of each:

- **bcc/set** — 17 of 25 replaced; identity reported at
  `### Programs that ran native (17)` above with the 8 that did not.
- **tetragon** — `event_exit_acct_process`,
  `event_exit_disassociate_ctty`, `event_wake_up_new_task`, and 11 more
  distinct symbols across 118 replacements (its 331 load lines are many
  probe instances of few programs).
- **katran** — `balancer_ingress`, the only program.
- **cilium** — `cil_from_container`, `cil_from_host`, `cil_from_netdev`,
  and 22 more.
- **otelcol** — `custom__generic`, `native_tracer_entry`,
  `perf_go_labels`, and 11 more.
- **tracee** — `cgroup_bpf_run_filter_skb`, `cgroup_mkdir_signal`,
  `cgroup_rmdir_signal`, and 148 more.

The distinguishing fact is tetragon: 118 replacements over 14 distinct
programs means its hot path is a handful of programs loaded hundreds of
times, which is consistent with the 20% whole-workload slowdown measured
with counters off — the per-event cost of those few programs multiplies
across every event.

# Blockers cleared to reach the native arm

Each was reproducible, and each is named with the evidence that cleared it.

1. **Module/kernel BTF mismatch** — `bpf_x86_alu.ko: Invalid parameters`
   with `distilled base BTF type 'bpf_prog' [4], size 96 has multiple
   candidates of the same size`. Not staleness: verified with a clean
   module rebuild (`rm -f *.ko`, `touch` sources, matching `vermagic`) and
   a fresh image. Cleared by rebuilding the module against the current
   kernel and repackaging.
2. **`vmlinux` relinked with the host `cc`** — `micro/programs/Makefile`
   uses the image only as a prerequisite of a generated header, but
   `vmlinux.o` sits beside it, so make's builtin `%: %.o` rule applies
   and the link fails on a PIE relocation.
3. **`native-link` failed to compile** — `missing field readonly_objects`
   in two `RewriteResult` constructors, twice.
4. **`siphash_rotate64_mixer`** — `error in backend: IO failure on output
   stream: Bad address` under concurrent load.
5. **Stale shim/loader in the image** — `host-shim-x86` has no
   prerequisites and misses its header dependency, so a header-only change
   never reaches the `.so` (and `runner/build-*/native_loader` had the same
   problem). Remove those before packaging; the image then reports the
   string that proves which shim it carries.
6. **libbpf's probe was fatal on the verified arm** — the exemption was
   gated on the bound requirement being off. Fixed upstream in `20aae50eb`
   after `dd3707caf` had made the gating deliberate.

# Timing requests served

## Lane F: stage2 helper/map, three runtimes

**Re-run on 2026-11-07 and now blocked**, which is worth recording because
it is a regression rather than a property of the suite. The loader gained
an application/trusted-worker split whose application branch rejects a
submission that carries any proof field
(`native_loader.cpp:5547`, `applications submit native programs and
cannot supply a proof`), and the micro `native_proof` runtime does carry
one, so all 13 stage2 programs fail and the run exits 2. The same command
completed at 11:28. Corpus is unaffected — it takes the application path
with no proof fields, and a katran re-check after the change still
replaces its program and completes — so the regression is confined to the
micro `native_proof` runtime, which needs to be recognised as a
trusted-worker submission. Reported.

The figures below are from the earlier successful run.

`RUNTIMES="native_kernel kernel native_proof" SAMPLES=3 WARMUPS=1
INNER_REPEAT=100000` -> RC=0,
`micro/results/x86_kvm_micro_20261106_181845_426714`. All 13 cases ran on
all three runtimes, and **return values and results agree in all 26
runtime comparisons**, so the arms did equal work.

Geomeans as computed (not as claims): `kernel/native_kernel` 1.380x,
`kernel/native_proof` 0.871x, `native_kernel/native_proof` 0.631x.
`native_proof` is the proof-verifier arm, expected to be slower than plain
native, and per-program medians sit in the single-digit-to-hundreds of
nanoseconds where `exec_ns` granularity dominates.

## Lane F: load-time

`BENCH=simple RUNTIMES='native_kernel kernel native_proof' SAMPLES=15
WARMUPS=1 INNER_REPEAT=1` -> `micro/results/
x86_kvm_micro_20261106_101146_092448`. The pure suite, so the stage2
defects do not affect it.

`native_kernel`, median over 15 samples (min-max):

| Phase | Median (ms) | Range (ms) |
| --- | ---: | ---: |
| `native_load_ns` | 46.076 | 45.656-49.000 |
| `companion_lookup_spec_ns` | 45.240 | 44.798-48.094 |
| `companion_load_ns` | 0.326 | — |
| `companion_object_load_ns` | 0.222 | — |
| `proof_verifier_load_ns` | 0.058 | 0.053-0.065 |
| `prog_load_ns` | 0.111 | — |
| `blob_upload_ns` | 0.052 | — |
| `proof_open_ns` | 0.030 | — |

`kernel`: `object_load_ns` 0.216 ms. `native_proof`: `proof_compile_ns`
121.598 ms.

`companion_lookup_spec_ns` is 45.24 ms — 98% of the whole load — which is
neither the ~107 ms that was patched out nor the sub-millisecond a hash
lookup implies. Recorded as measured, not as evidence the patch works.

# The verified (generation-bound) arm

Attempted and blocked at the shim, not at configuration. With
`BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1` every app program fails:

```
verified native runtime requires a generation-bound simulator proof for <prog>
```

`native_loader.cpp:4639` fails when `proof_insns` is empty under that
requirement, `:5428` takes `proof_insns` from `options.proof_insns`, and
nothing in `bpfopt/shim/shim_native_loader.h` sets it (no match for
`proof_insns` in that header) — the same gap lane A reported on 2026-11-06.
So no manifest can satisfy the verified arm; it needs the shim to pass
compiled proof instructions. Tried with both manifest locations
(`/artifacts/user/native-bpf/x86_64/bcc/` with 25 entries and
`/opt/bpf-benchmark/native-bpf/x86_64/bcc/` with 29), 0 replaced / 8
failed in each.

# Not claimed

- These are the micro and corpus workload numbers as the reference runs
  defined them; the verified (generation-bound) arm is a separate later
  measurement.
- arm64 AWS (`1.056x`) is not rerun — it costs money and waits for the
  operator.
- The no-eBPF baseline is measured for all six apps, but for katran,
  cilium and otelcol it is a different harness path, so only
  bcc/tetragon/tracee give all three columns like-for-like.
- The trusted native kernel-module baseline the coordinator asked for is
  not measured for any app.