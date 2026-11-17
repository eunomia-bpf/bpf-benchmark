# BCC remaining helper costs and prototype wiring

Receipts `eb175b24f` and `86cc48be4`; recipes `8da5ddea3` and
`833d59ec5`. The second host reader completed at 2026-11-17T16:06:36Z.
This is todo section 0 item 1e: measure both arms before changing the
remaining helpers. No production source, image, guest or workload changed.

## Cost evidence

The retained 2026-11-14 BCC profile uses cpu-clock at 999 Hz, four vCPUs,
one requested 60-second workload sample per phase. These are sampled
ownership fractions under a recorded BPF callchain, not hardware cycles,
current helper ns/call, or the frozen three-sample timing result.

| Historical BPF-owned category | eBPF | Native |
| --- | ---: | ---: |
| clock | 30.144% | 30.091% |
| perf-event output | 27.068% | 26.606% |
| map writes, including delete | 17.756% | 18.113% |
| map lookup | 12.218% | 12.213% |
| program text | 9.210% | 9.432% |

The actual HASH update operation accounts for 15,623/96,925 baseline
samples (16.119%) and 15,575/95,733 native samples (16.269%). The native
`bpf_map_update_elem` wrapper has 212 samples (0.221% of BPF ownership).
The 18.113% category includes deletes and must not all be called update.
Today's `x86.rs:34-42,1228,1590` already binds proved update/delete sites
to map ops. Reimplementing that historical wrapper fix is not a new gain;
removing a wrapper also cannot be credited with removing the map operation.

Perf-event helper variants differ in the old capture: baseline has
20,804 samples attributed to `bpf_perf_event_output_tp`, 5,431 to the
ordinary helper and one to raw-TP; native has 25,471 attributed to the
ordinary helper. The same data cannot establish present helper parity.

The newer joined clock-batch BCC run `123339_157340` records:

| Program group | eBPF ns/call | Native ns/call | Native/eBPF calls |
| --- | ---: | ---: | ---: |
| sys_enter | 105.004 | 90.362 | 1.238775 |
| sys_exit | 145.220 | 116.559 | 1.238775 |
| sched_switch | 151.679 | 157.170 | 2.083417 |
| sched_wakeup | 160.243 | 102.789 | 2.081544 |

Selected aggregate is 153.990/127.785 ns per call (15 of 25 records per
arm), with installed native/JIT bytes 13,248/7,965. All 25 records remain
in [costs.json](costs.json), with IDs and selection status. Name/type groups
can contain distinct programs; they are not an identity pairing. The
scheduler count mix differs, and this image joins several fixes. Do not
multiply these timings by the old profile shares to invent current helper
costs, or attribute the aggregate to one helper change.

## Pipeline finding: query implementation exists but the standard manifests omit it

The source-only staging audit reports original-prototype queries enabled
for **0 of 346 entries**: BCC 0/29, Cilium 0/81, Katran 0/3, OTel 0/26,
Tetragon 0/94, Tracee 0/113. These are prepared host manifests, not a direct
inspection of the shipped Docker image or every loader invocation.

The normal FD-load chain, at this checkout's source lines, is:

1. `vendor/bpf/write_native_manifest.py:334-360` emits entries without
   `kernel_helper_context`; the staged BCC manifest has no such field.
2. `native_loader_manifest.hpp:652` defaults an absent value to false.
3. `native_loader.cpp:4133,4157,4174-4175` defaults/assigns that flag and
   calls `query_program_helper_targets` only when it is true. The query
   has existed since `6df2a07f6`; its presence does not establish its use.
4. `native_loader_link_schema.hpp:97-129` uses static supported-helper
   names when `companion.context_helpers` is absent. Its contextual override
   list covers five other IDs, not perf-event output or stack helpers.
5. `native_loader.cpp:1695-1740` falls through to the ordinary
   `bpf_perf_event_output` symbol for helper 25.
6. The sole kernel's `bpf_trace.c:1372-1382,1442-1447` instead selects the
   tracepoint output/stack variants. Output-TP obtains pt_regs from the
   hidden first context word; the ordinary helper accepts pt_regs directly.
   `bpf_trace.c:1546-1551` selects additional perf-event-context variants;
   raw tracepoints have another output/stack implementation at 1594 onward.

The actual compiled TP helper starts with `mov (%rdi),%r9`, unlike the
ordinary helper. Disassembly of all three output variants is retained here.
The kernel inline-expands the common output implementation in the TP
function, so it is not merely a removable extra CALL wrapper. A different
context pointer is an ABI/parity issue. The source trace alone does not
prove that the benchmark's chosen perf sample fields expose an output
mismatch, and does not invalidate or discard any run.

This corrects the initial inference that the query's existence made the
historical helper difference obsolete. The normal current prepared path
still omits its enablement. The registered-service entry has its own setup;
this audit does not claim its query use from the normal FD path's source.

## Concrete next fix and ownership

Use the existing original-program prototype query for the normal native
FD-load route, rather than maintaining more handwritten type-specific
helper aliases. That preserves kernel-selected helpers and all their
checks, event writes, map operations and context semantics. It is startup
linkage, not a new per-call check or a speculative helper-body speedup.
No speedup or installed-byte reduction is claimed for it.

The minimal loader direction is to make the existing query assignment
unconditional for the original FD and remove the now-unused manifest flag
plumbing. A one-field producer change could enable the existing mechanism,
but would retain the misleading default-off path and would not cover the
registered-service route. Audit that route separately before claiming the
whole helper class fixed. Do not add another helper resolver or change the
kernel/module. Validate actual helper targets on the app's native load,
then time the targeted app through the frozen entry with all LTO on.

`AGENTS.md` Freeze permits dead-code deletion only in loader core and the
manifest writer. Removing a live conditional to change behavior is not
classified here as dead-code deletion. The coordinator owns the active
loader-core changes and the documented decision to open a frozen class when
it changes timing or equal work (todo 2026-11-17T12:4x). The exact evidence
and proposed class are posted in COORDINATION; PERF has left both frozen
paths and peer WIP unchanged. This is a concrete source-parity finding,
not a new result-admission gate or a requirement to stop other work.

## Reproduction

Committed `run-host.sh` runs `analyze.py` and objdump under timing SH on
CPU 19, with a 2 GiB address-space limit, and commits/pushes only this
result directory under Git EX. The inputs, exact raw locations and all
per-program counters are in [costs.json](costs.json), [readout](readout.txt)
and [host location](host-location.txt). Both reader runs remain under
`/workspaces/kprog-raw/perf/bcc-helper-costs-20261117`. All workers exited 0.
No tests were added for this reversible analysis; the regenerated category
and aggregate counters agree with the retained source readouts.

## Next output-helper work, 2026-11-17T23:03:07Z

The source review distinguishes the output machinery from a removable wrapper:

- kernel/trace/bpf_trace.c:615-643 defines __bpf_perf_event_output as
  static always_inline. It selects the live CPU slot, checks the live bound,
  empty entry, event type/config and event CPU, saves raw sample data, then
  calls perf_event_output. The sole build's System.map contains the public
  ordinary/TP/raw-TP helpers and perf_event_output, with no separate
  __bpf_perf_event_output entry to bind as a smaller kernel leaf.
- bpf_trace.c:657-695 prepares the raw record, uses per-CPU sample storage,
  maintains nested normal/IRQ/NMI ownership and preemption, initializes the
  sample and runs the common body. The TP helper at1372-1382 unwraps the first
  context word and calls the always-inlined C body. It does not add another
  runtime CALL to the ordinary helper. Raw-TP at1594-1607 additionally obtains
  and fills the correct saved registers with its own nesting contract.
- kernel/bpf/arraymap.c:1264-1286 accepts perf-event FDs whose local-read
  operation is supported. It does not require software/BPF_OUTPUT attributes.
  A known PERF_EVENT_ARRAY map therefore does not establish that every current
  or later entry can skip the output helper's event type/config/CPU checks.
  Slots remain live across updates/deletes. Do not freeze an initially read
  event pointer or remove those existing semantics from an LTO candidate.
- include/linux/perf_event.h:1360-1372 initializes sample_flags, period and
  dyn_size;1392 onward handles raw-sample selection and fragment sizes. These
  stores and downstream event output are part of the actual work, not loader
  or verifier checks. Constant current-CPU flags can eliminate only the known
  flags/index selection paths; that does not eliminate the sample/output work.

The old27% output ownership includes this machinery, so it is not an estimate
of removable prefix cost. Actual context-family binding remains the first
correctness change: ordinary/TP/raw-TP helper targets are not interchangeable.
Copying the whole output helper into each program has no demonstrated gain to
pay for its size. The next useful comparison uses correct helper targets and
current per-call/profile evidence from the all-LTO batch, separating wrapper,
map-slot/sample preparation and perf-event output time. This is an analysis
priority, not a new admission gate or refusal; no source, check, image, guest
or benchmark change was made for this review.
