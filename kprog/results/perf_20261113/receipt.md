# Lane perf P1 subset, 2026-11-13

The host context and CO-RE regressions pass. The selected OTel context and
dynamic-map configuration completes its paired diagnostic. Tetragon runtime
confirmation continues; the official six-application table awaits the assembled fixes.

`context-host.json` records the exact commands, layout, revisions and runtime
selection. `context-host.tar.gz` retains the build logs, all fifteen native
units, intermediate LLVM and the combined candidate. Implementation:
e0939263e, ce863428d, 00c863247.

The selected compiler stage lowers constant public-context loads in inlined
`perf_event` entry functions. The sole kernel's BTF supplies regs size 168,
ctx.regs offset 0, ctx.data offset 8, data.period offset 8 and data.addr offset
184. Register loads dereference ctx.regs; period/address loads dereference
ctx.data. Helper and tail-call arguments retain the incoming physical pointer.
The host fixture covers both register endpoints, period/address, the period's
upper half, helper-pointer identity and the kprobe register view. The original
fixture returns 1 and the corrected fixture returns 0. OTel's entry unit has
ten corrected loads; its other fourteen units have zero matching loads.

Select this configuration through the existing `NATIVE_MANIFEST` argument:
`/workspaces/repository/corpus/results/perf-context-20261113/manifest.json`.
The default image and its object files remain in place. This compiler-stage
trial lives entirely under `kprog/perf/native-context/` and operates on generated
LLVM build outputs from the existing producer sources and flags.

The first paired diagnostic used the existing Make corpus target, CPUs 16–19,
four vCPUs, 32 GiB, one 30-second sample and stats enabled. Launcher 1126468 used
a shared image lock; logs are under
`/workspaces/kprog-raw/perf/20261113-context/run/`, with captures under
`corpus/results/perf-context-capture-20261113/`. Its purpose is ABI behavior and
application-counter confirmation. Floor timing follows the corrected subset.

`tail-dispatch.json` comes from retained Tetragon entry358 and filter362 images
in the one-off investigation's mature capture. Both use max_entries offset 68,
array.ptrs offset 304, bpf_func offset 72, counter-pointer frame offset -16 and
entry offset +12. These match the sole kernel's BTF and IBT-disabled prologue.
Entry358 saves the BPF frame at rsp+64 and filter362 at rsp+240; each dispatch
restores the producer frame, the four kernel callee-saved registers and the
two tail-counter slots. These static observations establish layout agreement;
successful dynamic call counts remain a separate observation.

The source audit additionally found an opt-in relocation aimed at the +12
entry immediate, which the kernel rewrites to -16. Lane verified corrected
that relocation in b433c23be, with a regression covering both saved-frame
locations. The default captured images use their original +12 immediate.
The shared release linker integrates with the assembled batch.

## Runtime follow-up, 03:09 UTC

Both selected-candidate guests completed the eBPF baseline and exited with
Make status 2 / vng status 255 during the native restart or measurement. The
second run used one 10-second sample and verbose guest-console capture. It
reached native measurement and faulted inside `perf_unwind_native+0x5f5`, proving
the corrected entry reaches that previously skipped native path.

The console records a word comparison through RAX after a per-CPU-array lookup
expansion: array slot load followed by GS:this_cpu_off addition. RAX is
`ffff8a613eb18837`, while the per-CPU base is `ffff8a613eae8000`. The producer's
corresponding repeated search uses `bsearch_step(inner_map, &pivot)` over an
ordinary ARRAY of StackDelta values. Treating its value bytes as a per-CPU
pointer explains this fault pattern. The linker owner's causal check must
identify the selected link-plan index and the actual dynamic map.

The source lead is `select_lookup_site`: when native RDI's map identity is
unknown, it chooses the first remaining BPF lookup-site specification. The two
compilers' helper orders can differ. Lane verified received the full fault
request in COORDINATION at 03:07:33 UTC and owns the general linker correction.
The native register/unwinder counter deltas remain unmeasured at this point;
the fault arrived before a mature native snapshot was retained.

`context-runtime.json` records both commands, directories, statuses and limits.
`context-runtime.tar.gz` publishes both observer captures, progress outputs,
console, launch logs and producer disassembly. The second guest's captured
filesystem stays on persistent storage at
`/workspaces/kprog-raw/perf/20261113-context/run2-crash-filesystem.img`.

P1 continues with generic dynamic-map lookup repair and general Tetragon CO-RE flavor
resolution. The one-off report's concrete task.thread_pid/loginuid offset
defects and remaining hot-kprobe causal question are tracked together.

## Recovered OTel subset, 03:35 UTC

`otel-recovered.json` and `otel-recovered.tar.gz` retain the successful run
`x86_kvm_corpus_20261113_033039_387780`. It selects context correction 00c863247
and lane verified's default-off runtime-map dispatch 49f464cc6 through the
existing manifest/linker options. Make and the application both complete
successfully, with zero workload errors and zero stub records.

The mature windows below retain one metrics-map generation and one collector
instance within each arm. The restart-crossing snapshot baseline-0008 already
contains native map 360; the analysis preserves it separately.

| Window | eBPF, baseline-0002→0006 | Native, post_rejit-0010→0012 |
| --- | ---: | ---: |
| Metrics map | 29 | 360 |
| Seconds | 39.7492 | 19.744057 |
| Native unwinder attempts | 149663041 | 78100293 |
| Native frames | 136524559 | 71342143 |
| Interpreter calls | 24865249 | 12344454 |
| Frames per attempt | 0.912213 | 0.913468 |
| Exporter batch-size sum | 105563 | 56197 |

Exporter sums count exported pipeline items; the timestamps and window lengths
accompany every delta. These observations establish restored native unwinding,
interpreter activity and exporter activity, and resolve the observed lookup
fault in this subset. Counter-mix differences and the rest of P1's behavior
comparison remain explicit follow-up.

This stats-on, one-sample diagnostic gives throughput **0.975x native/eBPF**
and aggregate BPF cost 5140.6→5119.6 ns/invocation (1.004x). It uses four vCPUs
and shares host resources with builds. These are diagnostic measurements;
the official floor round follows the assembled fixes. The earlier unequal-work
OTel throughput stays separate from this corrected result.

## Target-BTF CO-RE compiler subset

`core-host.json`, `core-build-report.json` and `core-host.tar.gz.part-*` retain the
compiler checks and all 35 Tetragon manifest objects. Every plain executable
section matches its shipped counterpart byte for byte (35/35). The corrected
fork handler forms task+2904 at native PC0x2ff, replacing its synthetic task+96
probe-read source. The host fixture checks loginuid too, together with target
field/type/enum queries, anonymous source aggregates, bitfield reads and
allocation size, and generated-variable name separation. Plain returns 1;
corrected returns 0.

The compiler operates on generated units using Clang AST types and libbpf's
sole-kernel BTF. Existing source files and image objects stay in place.
NATIVE_MANIFEST explicitly selects the corrected object set. The archive uses two parts below the tracked-file size bound; concatenate the
parts to recover the gzip tar. The complete archive also stays under the raw
directory. The all-object build used four workers, each inheriting a 16 GiB
address-space bound. The
follow-up bitfield-temporary regression has its own recorded translator epoch;
the native object build retains its original epoch in the receipt.

Tetragon's selected corrected-CORE/runtime-map diagnostic is running through
the standard Make corpus target: one 120-second sample, stats on, CPUs16–19,
four vCPUs/32 GiB, 48 GiB host address-space bound. Log:
`/workspaces/kprog-raw/perf/20261113-core/tetragon-run/make.log`.

## May29 source/reference-payload audit, P1c

`may29-source-audit.json` and its archive establish both defect mechanisms in
commit 9f3855f6f and the retained reference-reproduction payload. OTel's entry
compares SS at incoming ctx+160. Tetragon's archived v511 fork forms task+96,
while its own main task_struct DWARF places thread_pid at2904 and loginuid at3552;
the flavor DWARF puts them at96 and112.

The retained ART belongs to the later reference reproduction. The original
dated May29 run's exact object identity still requires a matching archived
payload or provenance receipt. Source and native disassembly establish the
mechanisms; historical per-arm unwinding/emission totals remain unmeasured.
P1c stays open for that identity link. Paper decisions remain with the operator.

## Tetragon first runtime, startup overlap

`x86_kvm_corpus_20261113_033825_557252` completes with Make/application status
0/ok, zero workload errors and zero stub records. It selects all35 CORE-corrected
objects and runtime map dispatch. Raw measured throughput is1.796x native/eBPF;
aggregate BPF cost is700.2→215.2ns/invocation. These numbers remain an unequal-work
startup observation.

The result records287 eBPF programs versus245 native programs. Missing native
entries concentrate in generic kprobe/return-probe policy chains (231→193 and
36→32). Native live inventory continues growing from183 at03:43:12 to571 at
03:47:59; total live inventory includes retained originals and other programs.
The selected debug linker is a concrete load-time cost lead. Its optimization
and a repeat of the affected startup are coordinated with lane verified; the
frozen runner stays in place.

The observer's first-stage program/map/counter timeline, original app/result
files and all captures are retained in `tetragon-first-runtime.json` and its
archive. A default-off observer extension now builds upstream `tetra` and can
query loaded-policy state and sample successful gRPC event payloads. The
legacy send-failure analysis note now accurately describes native counter
writers; its existing raw fixture still decodes successfully.

## Optimized Tetragon startup and policy observation

`tetragon-observed-runtime.json`, `tetragon-observed-inventory.json`,
`tetragon-observed-loads.json` and `tetragon-observed-runtime.tar.gz` retain
run `x86_kvm_corpus_20261113_041136_182808`. It completes Make/application
0/ok, with zero workload errors and zero stub records. This is one 60-second
sample with stats on, four vCPUs/32 GiB on CPUs16–19, host address space
bounded at48 GiB. The selected linker was rebuilt with Cargo dev optimization3
and debug0; all three focused map-dispatch tests pass. Shared release, image,
base, default objects and frozen runner stay unchanged.

Raw throughput is2.106x native/eBPF and aggregate BPF cost705.6→140.1ns/inv.
The startup imbalance persists: the result inventories287 baseline programs
versus202 native programs. Mature baseline queries report all15 enabled
policies, while native has9 policies with rawtp still LOADING at04:15:55.
The baseline raw-syscalls action counter grows; the native snapshot is still
empty. These measurements remain unequal-work startup observations.

The existing shim log contains311 completed loads in each arm and no unmatched
requests. Pairing by PID/TID yields308 successful baseline loads with a median
37.19ms and a duration sum32.74s. There are288 native replacements with median
815.34ms and sum256.48s; they finish at shim monotonic498.006927s. These times
cover the whole intercepted load, including original loading and replacement;
they do not isolate linker cost. Lane verified owns the load-time investigation.
The offline parser's regression covers interleaved threads, failed loads and
unfinished requests. Existing logs and all288 replacement records are retained.

Eight one-second upstream tetra GetEvents subscriptions return empty output
with timeout124 on both arms. This is a short delivered-event sample, not an
emission total. Policy query results, action counters, errors and process/map
generations are retained without interpreting connection refusals during
shutdown as measurement-time failures. PID5119/map3566 already appears in
baseline-labelled restart snapshots.

An earlier attempt panicked in early boot before application execution. Its
console and exact own-QEMU stop record remain in the archive. Replacing the
expanded guest command with a short invocation reading an explicit plan file
boots successfully. Two focused tests cover long commands, exact arguments,
workload exit status and observer cleanup; the precise boot overflow cause is
not independently established. The successful observer exits by its controller's
SIGTERM after the workload completes; collected snapshots are present.

## Exact historical source chain and table runs, P1c

`may29-chain-audit.json` and its archive extend the earlier source audit using
the frozen parent's actual kernel gitlink
`8e116c79d1043f8e4dadd708f3a1ee5a26d19246`. That kernel's PERF_EVENT handler
passes a physical context containing a regs pointer; its verifier dereferences
the pointer before register-field reads. The old chunked loader stub preserves
the incoming context, and the old module copies native bytes without adapting
the context by program type. The frozen Tetragon native recipe force-includes
the compatibility header that makes preserve-access an identity operation.
Both mechanisms therefore predate the current stock-kernel reconstruction.

The archive includes the exact four runs named by the original table script:
OTel stats on/off021623_817446/024714_858694 and Tetragon
045551_393389/052633_700199, all dated2026-05-29. Their metadata and raw counters
are preserved. The exact objects used by those original runs and their own
unwinding/emission counters remain unestablished. The retained later reference
objects and source chain support the defect mechanism, not a claim that these
historical raw counters prove zero work. P1c remains open for the exact artifact
link; this does not delay corrected measurements. Paper decisions stay with
the operator.

## OTel counter mix and observation time bounds

`otel-counter-mix.json`, `otel-counter-mix-adjacent.json` and the accompanying
archive retain every adjacent same-generation window from the recovered run.
The earlier broad comparison remains published. Within the eBPF generation,
Ruby frames per Ruby attempt vary from0.35 to0.76; native windows include0.35,
0.60 and0.376. The previous broad eBPF0.555/native0.376 difference therefore
does not isolate a native Ruby defect. The later baseline window gives0.353,
and PHP frame yield is1.8821 versus native1.8822. V8 yields4.7231 versus4.6057.
These are temporal observations, not identical sampled inputs or an equality
threshold. The full retained window set prevents selecting only a favorable
comparison. Python and Perl still have zero frames and TSD errors in both arms;
their dispatch counters establish calls, not successful frame collection.

The shim's actual measure_start markers are monotonic130.852852 and244.497752,
after each45-second warmup; measure_finish is180.872462 and295.719993. The
progress measurement_start comes before warmup. Earlier receipts used mature
to mean stable map generation, without proving exact measured-window containment.
Their counter deltas stay as recorded. Historical snapshots have wall-clock
start/end bounds only, and the read sequence can take seconds or longer.
`b07cb025c` now records wall and CLOCK_MONOTONIC bounds around each observer
command, including a timed-out command. The shim uses the same monotonic clock.
Four focused observer/guest-control tests pass; the new counter-mix regression
checks family denominators and null zero-attempt ratios. This adds observation
metadata only; no benchmark lifecycle, workload or admission condition changes.

## Tetragon linker child attribution started

`9025380bb` adds an explicitly selected wrapper that invokes the existing
runtime-map linker unchanged, preserving arguments, output and failure status.
A real-child regression passes. Each child invocation records its wall/monotonic
interval and user/system CPU, memory faults and context switches. Python wrapper
startup adds overhead and is excluded from the child timing; full intercepted
load time still comes from the original shim log. The linker owns native output.

The short standard Make corpus job is running on CPUs16–19 with4vCPU/8 GiB,
hard host address-space limit16 GiB, stats on and one1-second sample. It selects
the same35 corrected CORE objects and optimized runtime-map payload through
the wrapper. Raw root: `/workspaces/kprog-raw/perf/20261113-link-load-profile`;
invocations: `corpus/results/perf-link-load-profile-20261113`. This is startup
component attribution with no throughput claim. Lane verified owns the fixes;
kernel, image, base, default objects and frozen runner stay unchanged.
