OTel regression audit, 2026-11-16

The 18:24 coordinator notice requests a stage-compiler regression investigation.
Retained measurement-window program records give 330,814 installed native bytes
in 102445_806916 and 125155_179400, and 303,930 in 172620_968192. The reduction
is exactly eleven copies of 2,444 bytes, matching the removed custom hash
routine. Two programs keep their sizes. There are thirteen programs in each
measurement window; shim replacement counts include an additional temporary
feature-test program. Thus replacement counts and window inventories have
different scopes. The assumption of equal installed size needs correction.

The committed audit compares original counters, integer-loop sample series,
and current stage output against three retained pre-publication physical
objects. It compares instruction bytes and relocation identities, without
rebuilding old tools or creating source copies. These are host source/static
facts, not a conclusion about the throughput cause.

The diagnostic profile uses the existing profiling tool on CPUs 20-23 with
four vCPUs and 32 GiB guest RAM, under image SH and without the 0-7 timing lock.
It uses the profiling tool's one-sample 60-second two-arm workflow, not the
three-sample timing protocol. The timed image and C's baseline round remain
in place. Different CPU count, sampling overhead and concurrent host load are
caveats for this profile; its throughput is not a new official timing number.

Run the committed Makefile's audit/profile targets. Raw evidence remains under
`/workspaces/kprog-raw/perf/20261116-otel-regression`. Per-call counters alone
do not separate body, helpers and maps. The corresponding profile split and
an affected-app stats-on run after publication remain work in progress.

Host audit result: the current stage compiler produces byte-identical selected
functions and identical relocation identities against retained physical objects:

| Selected function | Native function bytes | Relocations |
|---|---:|---:|
| native_tracer_entry | 6,434 | 44 |
| perf_unwind_native | 27,689 | 171 |
| perf_unwind_v8 | 34,346 | 225 |

This compares current producer P with the retained 12:13 replay objects. Those
objects are not a capture of the stage executable inside the 08:xx image, so
this does not alone exclude every historical compiler discrepancy. The source
changes have the following scopes:

| Change | Relevant behavior |
|---|---|
| 2294b0463 | Preserve a selected static entry across O3 and set its linkage. |
| 0f5c55894 | Conditional PERF_EVENT lowering plus optional supplied function bodies. With type 7 and no supplied bodies, context conversion is retained. |
| 63547fcfe | Generalize the supplied BPF callee lowering callback. The host comparisons supply no such bodies. |
| f45bb2485 | Change typed hash calls from a copied native routine to the raw kernel hash implementation; delete 2,444 appended bytes per using program. |

The last change's signature matches all thirteen measurement-window size deltas:
eleven shrink by exactly 2,444 B; perf_unwind_native and perf_unwind_hotspot
retain their sizes. It is a distinct linker change, not a context-compiler edit.
The current sampling entry has two raw hash call sites (retained shared-hash
audit offsets 1383 and 4482). Hash-call cost is therefore a concrete candidate
to measure, not yet an established cause or reason to restore duplicated code.

Available stats-on counters give the following total BPF times per invocation:

| Run and scope | eBPF ns/call | Native ns/call |
|---|---:|---:|
| 125155_179400, three 180-second samples | 3,189.196 | 3,571.941 |
| 163206_529710, one 10-second cleanup check | 3,574.743 | 3,746.349 |

The latter is a short diagnostic, not the current full round. Its native time
rose 4.9%, while eBPF time rose 12.1%; those two runs alone do not establish a
native-relative regression. custom__generic records zero invocations in both
arms of the available stats-on runs; its replacement-set presence cannot explain
a measured per-call cost there. Stats-off zero counters are uninformative.

Integer-loop sum ratios differ from other throughput summaries; audit.json
labels its exact calculation and retains each language's series. The existing
official May-comparison metric is unchanged. No body/helper/map split is
fabricated from aggregate program counters or instruction counts.

The software CPU-clock profile completed (controller 1842845, exit 0). Its
counter-window analysis exposes a sampling limitation: the recorded BPF runtime
is about 103–132 seconds, but virtually no root samples land in BPF text.
The resulting near-zero attributed costs are not estimates of absent work.
OTel's BPF executes in perf-event context; that context is a concrete explanation
for why this guest software-event sampler cannot provide the requested split.
Both recordings, JIT bytes and counter windows remain retained.

The next diagnostic uses the existing host guest-only `cycles:G` mode on CPUs
20-23, with the same four-vCPU 60-second workload profile, image SH and a hard
address-space limit. It does not change C's official timing entry or round.
Offline decoding disables remote debuginfo lookup; the guest's recorded symbols
and JIT bytes are the relevant identities. The ordinary profile reporter spent
several minutes in debuginfod lookup and then completed; no process was stopped.

The software run's raw app counters are committed at
`corpus/results/x86_kvm_corpus_20261116_184518_934200`.
`software-sampling.json` records the actual shim windows: baseline has
102.549 seconds of BPF time and native has 132.432 seconds, while program-text
root samples are zero in both. The native profile has only one attributed
external map sample. These facts explain the need for a different sampler.
Host guest-only PMU preflight passed; controller 1850880 started at
19:06:56Z with raw output in `otel-regression/pmu`. Its native recording began
at 19:13:00Z. It uses the same diagnostic CPU/memory scope as the software run.
Both PMU guest arms completed at 19:15:05Z; the controller returned zero at
19:15:07Z. The 37 MiB host recording is retained for offline guest-kernel
decoding with the recorded clock pairs and symbols. The regression cause and
production optimization remain open.

Live frame detail: native sampling-entry JIT program 48 shows four outer kernel
saves and only the remaining RBP/R12 saves in its body. The preserved-ABI replay
used for the earlier duplicate-save review retains all C saves and has a
different entry contract. It does not demonstrate four duplicated saves in this
timing path. The new mask contract's conditional 14-byte accounting for mask
zero is not an installed-byte or speed gain for this captured entry.


PMU result (19:08 diagnostic, image 6641a7e1)

`pmu-sampling.json` and `pmu.py` use the actual shim windows and live JIT
ranges. Unlike CPU-clock, hardware cycles provide thousands of samples inside
OTel. The 60-second workload diagnostic gives 4,543.127 to 7,463.351 counter
ns/call, and 167,504 to 303,930 installed bytes. This is a four-vCPU profile on
CPUs 20-23, with sampling and concurrent host work; it is not the official
three-by-180-second result or a comparison with the earlier image.

| Component | eBPF sampled cycles/root invocation | Native sampled cycles/root invocation |
|---|---:|---:|
| Program text before separating inline routines | 2,446.33 | 11,811.64 |
| Native remaining text after separating the routines below | — | 3,679.12 |
| LPM lookup, kernel symbol / native inline routine | 3,439.94 | 4,286.97 |
| ARRAY lookup / native ARRAY dispatcher | 259.39 | 1,279.95 |
| User copy / native user probe routine | 2,636.44 | 2,560.64 |
| Native kernel probe routine | — | 4.96 |
| External hash symbols, including raw hash and bucket walk | 1,520.98 | 2,022.39 |

The native rows identify complete inline routines by captured instruction
bytes, masking only their external-call rel32 displacement. They include
samples in tail programs: tail execution time is charged to the invoking
program's counter. For perf_unwind_native, ARRAY is [29,516, 29,583), user probe
[29,583, 29,909), and LPM [29,909, 30,239). The largest individual LPM roots
are offsets 30,042 (child load) and 30,050 (node-data load). The ARRAY hot
root at 29,526 is the key load immediately after the type test. Its period
may include skid from the preceding map-type load; instruction addresses
alone do not prove that a particular load missed cache.

These are cycle periods, never nanoseconds. The recording has no callchains:
external kernel roots include other guest activity, and cannot be assigned
wholly to OTel. Remaining text still includes tail/context/percpu operations,
so it is not pure application body. Neither external copies nor shared hash
are hidden in a claimed body speedup. Hardware sampling/skid also prevents
converting this table into an exact accounting of BPF counter time.

The result puts map dispatch/LPM ahead of further body-only work. It does
not by itself establish which historical change caused the throughput drop.
Source confirms an avoidable class: select_lookup_site discards a proven
named map's complete `call` target; the loader also leaves LPM maps at the
generic helper. Those calls enter ARRAY then LPM dispatch rather than using
the verifier's once-selected lookup operation. Resolve those facts at link
time, retaining actual dynamic-map semantics, and measure after publication.
