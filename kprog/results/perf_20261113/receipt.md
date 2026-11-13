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
