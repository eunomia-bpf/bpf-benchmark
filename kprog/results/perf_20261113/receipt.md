# Lane perf P1 subset, 2026-11-13

The host context regression passes and the complete OTel candidate builds.
Runtime equal-work confirmation continues after the guest fault below. The official six-application
throughput table remains provisional while P1 proceeds.

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
