2026-11-16T11:31:29Z

BCC stats-off run 105138_635552 completed app OK, 25 tracked programs in each
arm. Sum of the retained stress-ng real-time rates gives phase series:
eBPF 556323.46 / 578672.30 / 565756.07 and native 560216.04 / 518896.18 /
482902.35 ops/s; ratio of phase medians 0.917172979. Each sample is the frozen
180-second workload. All samples and raw workload metrics are retained.

The native decline is accompanied by falling accounted process CPU time:

| Native stressor | Wall ops/s, first → last | User+system s, first → last | CPU-normalized ops/s, first → last |
|---|---:|---:|---:|
| cap | 358235.21 → 317767.02 | 167.86 → 150.85 | 384136.68 → 379153.42 |
| set | 28007.16 → 25402.35 | 170.10 → 155.63 | 29638.07 → 29381.12 |
| sockfd | 173970.84 → 139730.17 | 172.99 → 136.74 | 181021.32 → 183943.10 |

Thus the large wall-rate loss is primarily associated with less accounted CPU
work per wall interval; these metrics do not show a similarly increasing CPU
cost per operation. Stress-ng CPU accounting is rounded and may include its
workers/children. This observation does not distinguish host vCPU scheduling,
guest contention, blocking or other work. Stats-off program counters contain
no per-program time, so the queued stats-1 BCC case is still needed to locate
BPF cost. No causal attribution or performance-target completion is claimed.

The retained shim log has 25 native replacements from boot second 831.373238
to 831.470017, one startup burst of 0.096779 seconds. It shows no continuing
native replacement accumulation across measured samples. That narrows one
possible growth mechanism without excluding map/app/kernel state growth.

Analysis entry: make -r -f kprog/test/katran-accounting.mk bcc-series
OUTPUT=/workspaces/kprog-raw/perf/20261116-bcc-series. Source is
bcc_series_analysis.py; analysis.json retains all parsed rows and arithmetic.
Core raw metadata/result/progress/app files are committed next to the run;
bulky shim details remain under corpus/results in this sole checkout.


2026-11-16T11:54:25Z: retained stats-on comparison preserves all program identities.
Kernel names are truncated: four tracepoint programs share tracepoint__sys,
and two capability programs share kprobe__cap_cap. Grouped rows below retain
all original IDs/counters; they are not individual function identities. All
25 records in each arm are retained, with count/time sums conserved. An initial
read-only inspection keyed by name lost colliding rows; this analysis corrects
that inspection and makes no per-body attribution for a colliding name.

Reference 20261116_060435_731340, three 180-second samples, stats on:

| Kernel name group | Programs/arm | Calls eBPF → native | ns/call eBPF → native |
|---|---:|---:|---:|
| sys_enter | 1 | 2809617249 → 3174498794 | 85.47 → 82.68 |
| sys_exit | 1 | 2809617254 → 3174498797 | 113.08 → 88.23 |
| tracepoint__sys | 4 | 157019044 → 215801850 | 857.78 → 666.75 |
| kprobe__cap_cap | 2 | 248640198 → 257830413 | 208.34 → 196.44 |
| sched_switch | 1 | 70242816 → 176296084 | 124.08 → 158.85 |

The reference native arm performs 1.374x as many opensnoop-group calls and
2.510x as many scheduler-switch calls. sched_switch accounts for 8.716 to
28.004 seconds, a 19.288-second increase; the four opensnoop programs account
for 134.688 to 143.887 seconds despite lower average time per call. The main
syscall groups are faster per call. Across all programs, times are 761.072 and
777.340 seconds. This is evidence of changed event volume and a scheduler-cost
lead in that older run, not a measured explanation of temporal decay in the
current stats-off run. Name-group averages can also hide branch/event mix.

Earlier 20261114_141724_941055 has near-equal counts (opensnoop 1.006x,
scheduler switch 1.016x). Its timings are not pooled with this reference.
The native installed-size multiset (type/name/size with multiplicity) in
060435_731340 and current 105138_635552 matches for all 25 entries, totaling
38841 B in each. Equal sizes do not prove equal machine code. Nothing in these
records establishes a growing number of native installations or code bytes.

Source leads, without editing the frozen workload or upstream application:
runner/libs/app_runners/bcc_set.py runs syscount with -L -i 1, and drains tool
output through bounded 8000-character captures. syscount's start map retains
per-thread timestamps until teardown (10240-entry limit); its data map is read
and cleared each interval. runqlat normally uses one global histogram key and
deletes start entries after scheduling. opensnoop deletes its start entry after
an exit. These lifetimes narrow potential state-growth mechanisms but map
occupancy was not retained, so none is asserted to cause this run's decay.

The workload uses fast75. The upstream implementation ranks syscall tests by
measured test duration, so a fixed option need not imply a fixed syscall mix.
This is source context from [upstream V0.17.08](https://raw.githubusercontent.com/ColinIanKing/stress-ng/V0.17.08/stress-syscall.c), not confirmation of the exact
container package revision. The captured syscall worker reports 294 tested,
220 selected and 514 bogo operations in every sample; that coarse count does
not reconstruct the observed BPF event volume. These observations add no
admission rule and do not discard the measured 0.917x result.

Reproduction: make -r -f kprog/test/katran-accounting.mk bcc-series
BCC_REFERENCES='/workspaces/repository/corpus/results/x86_kvm_corpus_20261116_060435_731340 /workspaces/repository/corpus/results/x86_kvm_corpus_20261114_141724_941055'
OUTPUT=/workspaces/kprog-raw/perf/20261116-bcc-series-references.
Current stats-1 BCC is still queued. Its aggregate program counters can locate
cost/volume shifts but cannot by themselves reconstruct within-phase growth.
