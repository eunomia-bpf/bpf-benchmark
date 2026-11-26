# P3 attribution: Tetragon and OTel, 2026-11-26

Coordinator assignment 10:21Z: establish whether P3 causes the Tetragon and
OTel short-check native time, fix the evidence-supported cause within the
design, and record kernel memset weight from Tetragon and Tracee profiles.
The full x86 timing run stays frozen.

The first collection uses image fb53150e89ea unchanged. It runs the frozen
check target for Tetragon three times, then OTel three times (one 10 s sample,
stats on each time), followed by host PMU profiles of Tetragon and Tracee.
The first Tetragon case is also the smoke case and contributes to its three
runs. Expected collection time is about 35–50 minutes including startup.
Each job records its command, exit status and raw paths; a heartbeat records
progress during long jobs. Every result is retained and published as it ends.

Profiles reuse profile-host.sh with EVENT=cpu_core/cycles/ and PERIOD=1000000,
call chains, eight guest CPUs and 32 GiB guest memory; the existing profile's
60 s workload and stats-off protocol is unchanged. A 40 GiB outer address-space
limit bounds each profile job. Module text symbols join the phase snapshots,
so the P3 routines are resolved after their module loads. Host monotonic/realtime
offset is captured for phase alignment. Existing staging captures move to
prior-staging rather than being deleted. Timing EX then image SH serializes
guests against other lanes; the separate compile pool retains its own limits.

The analysis compares per-program counts/time as well as aggregate ns/call,
and PMU samples in P3 routines, the kernel hash lookup family, program bodies,
memset and other kernel work. `memset-calls-20261126` receives the observed
memset weight with the denominator and attribution limits. Implementation
changes wait for this evidence; workload/framework definitions stay fixed.

The first collection's six diagnostic launches returned an immediate Make
path error: its relative entry path was resolved from this result directory.
No application ran in those six attempts; their logs and summaries are kept.
The absolute entry path fixes this wrapper error. The independent Tetragon and
Tracee profiles continue, then retry-checks.sh runs the required three
Tetragon and three OTel checks. A launcher failure now stops dependent check
launches while retaining their error; it does not discard measurements or
block independent profiles.

## Historical localization before the repeats

`historical-mix.json` reads the five named raw runs using the same ns/call
calculation and existing >=100-call cutoff as native_eval_20260529.py.
`historical-summary.txt` retains the existing check_summary.py output, including
workload throughput; no framework counter or aggregation code changes.

| Tetragon run | eBPF aggregate ns/call | Native aggregate ns/call | eBPF tracepoint ns/call | Native tracepoint ns/call | Native kprobe group ns/call |
|---|---:|---:|---:|---:|---:|
| 20261125_111939_929854 | 595.1 | 316.6 | 536.8 | 671.1 | 55.2 |
| 20261125_153231_815043 | 1282.3 | 396.0 | none retained | none retained | 482.7 |
| 20261126_072843_366158 | 1137.6 | 1150.8 | 1530.7 | 2609.4 | 54.1 |

The 11:19 and P3 runs each have one retained tracepoint record, with the same
reported byte lengths: eBPF 14,942 B and native 14,003 B. The native kprobe and
return-kprobe groups stay near their earlier costs; the tracepoint drives the
observed native increase. Its eBPF cost also rises substantially. The 15:32 run
has no tracepoint record above the existing cutoff; this does not establish
whether a program was loaded or ran, and its aggregate is a different call mix.
Program-name/type groups can combine several IDs, so the kprobe rows are group
observations rather than a claim of exact program identity.

OTel's one retained perf-event entry rises in both phases: eBPF 3320.4 to
3815.7 ns/call, native 3531.5 to 4220.0. Diagnostic throughput ratios from the
existing evaluator are Tetragon 1.025x/1.415x/0.763x for the three rows above,
and OTel 1.045x/0.993x for Nov 25/P3. This localization neither proves nor
excludes a P3 cause; repeated short checks and phase-resolved PMU samples are
still required before changing implementation.

## Profile capture completed

Both profile guests finished with rc 0 and app status `ok`, error empty:
Tetragon raw run `x86_kvm_corpus_20261126_104304_967169` and Tracee
`x86_kvm_corpus_20261126_105114_881631`. The PMU recorder wrote 11,446,569
Tetragon samples (804.932 MB) and 7,978,939 Tracee samples (559.313 MB).
Each raw profile, dynamic symbol snapshots and linked-code cache is retained
locally and committed as compressed 44 MiB parts in its profile directory.

The wrapper returned an error because the requested SIGINT stop of perf
terminated its sleep child with status 143. Both guest exits and original
recorder/wrapper statuses remain recorded; no app measurement is discarded
or repeated. Future runs record the explicit stop request and accept 143 only
when that stop was requested after guest completion.

`profile_summary.py` uses the final 54 seconds before the last shim
measure_finish (the existing phases.py convention), the captured clock conversion and phase-specific module/BPF
snapshots. It reports flat cycle-sample shares for P3, kernel hash lookup,
program bodies, memset and the remaining work. It also counts real stack
frames separately from perf context markers. Flat memset samples alone are
not proof that every memset call came from P; caller attribution and the
chosen denominator must accompany the final memset weight.

The corrected six short checks run after the profiles in
`checks-20261126T104517Z`. PMU summary job 452715 waits for timing SH and writes
phase-summary.json in each profile directory. These analyses and checks remain
pending before causal attribution or a production optimization.

The initial PMU summary used the complete counter-message span. Tetragon's
native span was 131.2 s although its actual workload duration was 60.07 s:
measure_start can precede delayed native loading. That initial summary/log is
retained with an `initial` suffix and is not used as workload-only attribution.
The corrected summary uses the established final 54 s convention without
rerunning a guest. The first corrected 10 s Tetragon check completed app ok,
288 native replacements and no native-load failure, with eBPF/native
1374.3/1242.1 ns/call; its tracepoint costs are 1909.5/2867.2 ns/call.


## Repeats, PMU result and generic-helper control

All three corrected Tetragon checks completed app ok, 288 native replacements
and zero native-load failures. In order, eBPF/native aggregate ns/call are
1374.3/1242.1, 1147.7/856.9 and 1111.2/1647.4; the native tracepoint is
2867.2, 1967.3 and 3866.2 ns/call. The unchanged-image spread is retained.
The first two OTel checks are app ok, 14 replacements and no native-load
failures; the third is still running. The corrected workload-only PMU
summaries are published in 5986a5341. Tetragon native P3 hash is 0.254% of
guest-kernel cycle samples, with 83.15% in the BPF resilient queued-spinlock
slow path; baseline also has 75.66% in that lock routine. Tracee P3 hash is
10.189%. These flat samples identify symbols without their callers.

The memset weights and their caller-attribution limit are recorded in
`../memset-calls-20261126/README.md`: Tetragon native 0.0123% and Tracee native
1.3364% of guest-kernel cycle samples. Guest chains contain no actual frames.

The next causal control uses `generic_control.py` through `make generic-control`.
It holds timing EX, then image EX for each module rebuild (image SH during
checks). It recompiles the sole existing module output with 19 symbol-name
macros, so the existing loader selects `__htab_map_lookup_elem`; there is no
new production knob. It records and compares the module .text dumps before
running the control, runs the same default three Tetragon then three OTel
checks, and rebuilds the normal module in a finally block before releasing
the resource. The image, application P objects, optimization flags and frozen
benchmark entry/settings stay the same. Symbol tables and text dumps are raw
evidence, not second build products. No module binary is copied or retained.
Each control check is published as it completes. This control is needed to
separate helper selection from the large observed temporal/call-mix variation;
no P3 causal conclusion or production optimization is claimed yet.


## Completed unchanged-image checks

All six checks are app ok/error empty with zero native-load failures: Tetragon
288 replacements each, OTel 14 each. Each is stats on, 1 x 10 s.

| app / raw run | eBPF ns/call | native ns/call | eBPF / native |
|---|---:|---:|---:|
| tetragon / 20261126_110044_568071 | 1374.3 | 1242.1 | 1.106x |
| tetragon / 20261126_110852_804800 | 1147.7 | 856.9 | 1.339x |
| tetragon / 20261126_111433_299444 | 1111.2 | 1647.4 | 0.675x |
| otel / 20261126_111900_412998 | 3998.5 | 3720.0 | 1.075x |
| otel / 20261126_112553_192230 | 3683.5 | 3907.9 | 0.943x |
| otel / 20261126_113434_250961 | 3612.3 | 3479.6 | 1.038x |

These diagnostic ratios are not official timing. No steady P3 penalty is
established by this temporal comparison. The generic-helper control remains
necessary for attribution.

The first control attempt, generic-control-20261126T113558Z, stopped before
any app: Make propagated result OUT into the module build. Its canonical
module snapshot therefore still had all specialized symbols. Accidental
build outputs were removed in bebc8dd77 with an exact cleanup inventory and
all raw evidence retained; the sole canonical module stayed unchanged. The
result Makefile now pins the canonical module OUT explicitly. The corrected
finite controller470513 is generic-control-20261126T113705Z; it owns the
resource locks for the control and normal module rebuild and wakes this lane
after publishing its outcome.


## Completed generic-helper control

The corrected control finished controller0 and rebuilt the normal module
identically. All six checks passed with no native-load failures. The per-app
comparison and causal limits are in [control-summary.md](control-summary.md).
The generic helper does not remove Tetragon's slow tracepoint or consistently
improve OTel; this does not constitute a fix of either slow program.
Both uncompressed profiles have now been removed after the coordinator
requested SHA256/size comparisons against their committed archive members
passed. Per-profile profile-archive-verification.json and cleanup-log.md
record the removal; every raw sample remains in the archives.
