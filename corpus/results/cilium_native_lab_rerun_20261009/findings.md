# Evidence and confidence

The source execution is
`/workspaces/.agent-state/bpf-benchmark-supervisor/cilium-lab-20261009/`.
Its primary artifacts are still at
`/workspaces/repository/corpus/results/cilium_native_lab_20261009/`.
Neither directory was moved or modified by this recording task. The
[earlier audit](../cilium_native_audit_20261009/summary.md) remains the source
for interpreting the original May 29 measurements.

## Source identity and protocol

[metadata.json](metadata.json) gives the full commit IDs and guest release
strings. [source-pins.json](evidence/source-pins.json) records the historical
gitlinks. [source-review.json](evidence/supervisor/source-review.json) and
[cilium-source-delta.diff](evidence/supervisor/cilium-source-delta.diff)
record the run's source comparison: the Cilium app runner and workload module
were unchanged between the candidate and the current image; native Cilium
patches, compatibility code, manifest/linker handling and kernel differed.
The copied executable's Go build metadata reports `vcs.modified=true` and an
October 6 revision. Upstream gitlink/version equality therefore does not
certify that executable as an exact build of the May 29 app or current HEAD.
The historical loader/kernel/native objects were rebuilt; the current kernel
and loader were rebuilt, while current native/proof objects were cached.

Build/runtime packaging was task-specific: the existing October Ubuntu
dependency image, GCC 13.3/Clang 18, custom image recipes, rebuilt modules and
shim/loader, and observational wrappers are archived as text in
[evidence/scripts/](evidence/scripts/). Actual per-invocation Make commands
are in `evidence/cases/<series>/<case>/exit.json` or `command.json`, plus
`guest-command.txt` and `make-input.txt`. The historical treatment used
`SKIP_REJIT=norejit` with `BPFREJIT_SHIM_NATIVE_LOADER=post`; current treatment
used its native-post path without that skip flag. Controls omitted the native
flag and used `SKIP_REJIT=norejit`. These were two application starts with a
stop/restart between arms, not running-process live replacement.

The actual primary observer recorded start snapshots after warmup and before
`measure_start`, and end snapshots after `measure_finish`. Observer commands
query programs, links, interfaces, addresses, metrics and program-array maps,
and dump JIT/translated images. Query-time program churn produced ENOENT/dump
errors; their command exit codes and nonempty stderr are retained. Completed
scheduled shim timing rows have JIT and translated dumps according to
[phases.csv](evidence/phases.csv); this does not assert complete image capture
for every transient program ever loaded. Binary images remain at their
original locations, listed in [retained-artifacts.csv](retained-artifacts.csv).

The supervisor's `lab_observer.py` was a separate prepared observer, not the
observer used for the timed primary series. In particular, its six-vCPU
affinity proposal and perf code must not be mistaken for measurements.
[DUPLICATE-EXECUTION.json](evidence/supervisor/DUPLICATE-EXECUTION.json)
records the second execution's coordination: it built/reviewed artifacts,
stopped a redundant kernel build and acknowledged that it launched no guest
and would not commit. The primary owned the serial guest queue.

## Completed phases, timings and controls

[completion.json](evidence/completion.json) lists every completed scheduled
invocation, its exact timestamps and source result location. All 20 historical
and the one current treatment invocations returned zero with app status `ok`.
App status describes runner completion; it does not establish packet-delivery
equivalence. Early smoke 1 panicked in guest command-line setup, smoke 2 used
the wrong selector, smoke 3 reached Cilium but failed pktgen module loading,
and smoke 4 completed a 10-second treatment. Primary packaging was repaired
between attempts. These were setup/guest failures, not observed host reboots.
Smoke 4 snapshots included warmup and are not pooled into the scheduled series.

[analysis.json](evidence/analysis.json) and [phases.csv](evidence/phases.csv)
are the latest saved October 9 analysis, covering 42 completed scheduled
phases. All ratios are offline analysis. ns/run pools each phase's raw runtime
and call deltas; paired distributions pair corresponding invocation arms.
PPS sums the two pktgen generated rates; it is not received-packet throughput.

| Comparison | Pairs | Paired ns ratio median [min, max] | Paired PPS ratio median [min, max] |
| --- | ---: | --- | --- |
| Historical native, stats on | 5 | 6.110122 [5.920816, 7.652175] | 2.233785 [2.135706, 2.577295] |
| Historical native, stats off | 5 | undefined | 2.300165 [2.253656, 2.410222] |
| Historical JIT/JIT, stats on | 5 | 0.967081 [0.936139, 1.021750] | 0.983093 [0.955011, 1.009229] |
| Historical JIT/JIT, stats off | 5 | undefined | 1.001463 [0.976522, 1.042229] |
| Current native, stats on | 1 | 5.054801 | 3.813351 |

Historical treatment stats-on medians [min,max] were JIT
1114.110 [1038.715,1416.002] and native 175.434 [172.777,185.046] ns/run.
Their ratio is 6.350578. Stats-on PPS medians were 1,016,065→2,270,424
(ratio of medians 2.234526). Stats-off medians were
1,046,645 [992,362,1,076,995]→2,407,456 [2,391,813,2,427,897] PPS.
Control ratios of arm medians differ from paired medians: stats-on
1.021750 ns and 1.009229 PPS; stats-off 0.986483 PPS. Q1/Q3 and raw phase
values are retained, so neither aggregation is substituted for the other.

| Hot attachment | Historical JIT/native median ns/run | Historical paired ns ratio median [min,max] | Current JIT/native ns/run (IDs) |
| --- | --- | --- | --- |
| `lxcbench0` ingress | 1121.088 / 177.550 | 6.080015 [5.847834,7.539286] | 1195.415 / 238.127 (153 / 570) |
| `lxcbench1` ingress | 1107.137 / 174.141 | 6.140757 [5.995250,7.767457] | 1201.671 / 236.098 (166 / 596) |

[programs.csv](evidence/programs.csv) contains every measured program ID,
full/truncated name, attachment role, count/runtime delta and code size.
[program-summary.csv](evidence/program-summary.csv) retains all program
groups, spreads and zero-count entries; no minimum-count filter was applied.
Entry runtime includes the tail-call chain; zero tail counters do not prove
that the chain was unused. The tiny XDP/host-entry counts are not workload
timing evidence. Per-site or helper cycle attribution cannot be recovered
without the unfinished profiling work.

## Inventories, attachments and packet work

[inventories.csv](evidence/inventories.csv) distinguishes shim timing rows
from complete bpftool snapshots. [inventory-differences.csv](evidence/inventory-differences.csv)
records name/type multiplicities in each pair and snapshot. Truncated-name
equality is not bytecode equality. Native snapshots retain original programs
and native replacements; observer iterator/system programs are also included.

| Treatment arm | Shim rows | All-loaded end snapshot counts | TCX attachment locations |
| --- | --- | --- | ---: |
| Historical JIT | 53,56,60,62 across pairs | 56,59,63,65 | 7 |
| Historical native | 27 in every pair | 63,65,66,68,70,73,75,78 | 2 |
| Current JIT | 56 | 59 | 7 |
| Current native | 60 | 198 | 7 |

Every historical treatment native end snapshot loses `bpfbench0` ingress
(`cil_from_netdev`) and egress (`cil_to_netdev`), `cilium_net` ingress
(`cil_to_host`), and `cilium_host` ingress (`cil_to_host`) and egress
(`cil_from_host`). Both endpoint ingress attachments remain, using native
`cil_from_contai` programs; XDP on `bpfbench0` remains in both arms. Current
native retains all these locations. IDs and ifindexes change on restart.
Exact attachments, program-array contents and full program inventories are
in each case's `observations.json`; timing rows alone cannot establish the
active program set.

Reason 133 is Cilium `DROP_POLICY`; direction 2 is egress. Historical native
policy-drop medians [min,max] were 67,944,078 [66,325,203,68,855,331]
stats-on and 72,140,463 [71,603,673,72,685,416] stats-off. JIT policy drops
were zero in treatments and controls. Historical JIT peer RX medians were
30,397,019 stats-on and 31,356,976 stats-off; native peer RX was only 1–2.

Current JIT generated 28,916,729 packets with zero pktgen errors, recorded
28,916,795 ingress and 28,916,798 egress reason-0 forwards and zero
policy drops; endpoint RX deltas sum to 28,916,799. Current native generated
110,502,719 packets with zero pktgen errors and recorded exactly that many
reason-133 egress drops. Reason-0 native forwards total two, endpoint RX
totals two, and native reason-139 egress drops also total two. Small residual
counters can include control traffic. Reason-0 ingress and egress must not be
summed as unique delivered packets. [verdicts.csv](evidence/verdicts.csv) and
before/after metric maps preserve the keys, packet/byte totals and deltas.

This is positive evidence of unequal packet work. The native arm's shorter
time per entry and faster generated rate cannot quantify faster equivalent
forwarding. Keeping seven attachment locations on current master did not fix
the policy outcome. Native map/policy/compatibility behavior needs diagnosis;
these artifacts alone do not prove a particular root cause or establish what
the original May 29 native arm forwarded.

## Interruption, profiling and certainty limits

The current control retained complete JIT start/end snapshots and a second
JIT start snapshot finishing at 16:03:51.413873 UTC. Its end files are empty
or truncated, no `exit.json` or final app result exists, and its host-load
gzip raises `invalid stored block lengths`. A truncated end snapshot does
not establish whether its timed workload had finished. No complete control
ratio is inferred from this partial invocation. The recording preserves its
partial content as `incomplete_json_files` in `observations.json`.

The host reboot window of approximately 16:04–16:05 UTC is the operator's
report. The full run log's preserved mtime is 16:04:14.167738 UTC; its last
explicit error timestamps are 16:03:24.233. The persisted checker still has
the October 5 PID-1 start and old host boot ID, with no reboot entries.
It never saved a post-reboot observation. Exact reboot time, cause and
number of later restarts cannot be established from this run's logs. The
present Workspace PID-1 start is later still and cannot date this event.

Perf installation and observer-image preparation are recorded, but no
phase perf-stat CSV, perf-record data/report or completed profile is present.
No cycles, IPC, branch-miss, instruction-cache, helper/stack fractions or
top-symbol findings are claimed. Source inspection noted that the native
module copies code into the BPF JIT image, making BPF symbols/ranges a
possible future attribution method; that was not a completed attribution.

The historical replay differs in binaries, packaging, guest size, sample
duration, endpoints and program population from the paper. Its 2.300×
stats-off generated PPS is numerically near the audited old 2.357974×;
its 6.110× paired ns ratio does not reproduce old 1.863055×. Neither this
nor the single current pair establishes a paper speedup reproduction.
Contention and missing supplementary checks remain caveats; the completed
raw runs are retained. A future forwarding comparison needs repaired native
semantics and a documented equivalent packet path, then the requested
interleaved measurements, controls and separate profiling on identical pins.
No such rerun was attempted during this recording task.
