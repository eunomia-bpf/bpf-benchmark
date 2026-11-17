# Short encodings inside native tail transitions

The smallest production change uses the existing routine compactor before
turning the tail stub into opaque chunks. Existing operand emission selects
short map-bound and program-function displacements; the known entry offset uses
imm8 when its signed value fits. All live checks, slot loads, count updates,
register/frame cleanup and indirect target transfer stay. No target cache,
new runtime check, flag, module/kernel change or new optimizer framework.

Kind10 remains a four-byte displacement. The compactor maps its instruction
start, then the field's existing three-byte prefix is added back. A temporary
NOP anchors the common miss target during compaction and is removed afterward.
The existing first-chunk source label and field_chunk/field_delta mapping stay.

This follows actual retained inventory38cc97063/d12934d61:206 stubs with21B
encoding opportunity each. Those are static facts, not this change's measured
savings or performance. The existing counter-patch regression is extended to
24 narrow/wide/zero-layout, saved/live-frame, mask and long-cleanup shapes;
it checks branch targets/widths, physical four-byte patch offset and unchanged
target entry. One existing full-object assertion accepts either signed ADD
encoding. The full suite, unchanged helper bytes and295 real requests follow.

The one-shot host recipe waits for the existing fusion host2776222 and its
publisher2776223 before touching x86.rs, then uses timing SH/image EX onCPU19,
one Cargo worker/AS32GiB, source commit/push and canonical main build/replay.
No second build tree/product, image or guest. Omp owns later image/check/
affected-app timing, all LTO on. Installed bytes, body/helper/map/per-call and
throughput remain pending. Scripts stay stable while live; never reapply.

## Active unit-entry route, 2026-11-17

Waiting host2782317/publisher2782318 ended143 at22:37:29Z before applying source,
with all raw retained. Recipe now uses timingSH/imageSH and the same production
link(Args) function in the existing Cargo unit executable (99a3a5e72), preserving
the checked guest's canonical CLI. It starts after the replacement fusion run
has actually completed; no old PID waits remain. Before reapplying a recipe,
inspect actual source and stage because source application is one-shot.

The full subset, byte comparison, source commit/push and295-request replay stay.
Test/unit source/build receipts are named accurately; canonical CLI is rebuilt
once later by the frozen image recipe under imageEX. Comparator baseline follows
the actual preceding fusion unit replay through its current-raw.txt. No new
benchmark setting, helper catalogue, product or module change. Omp owns timing.

2026-11-17T22:47:12Z — Tail encoding source and full host tests completed; actual logs and source.patch committed. Raw: /workspaces/kprog-raw/perf/tail-short-encodings-20261117/host-20261117T224510Z-2795880. Production unit-entry build and captured-request emission follow; canonical CLI stays unchanged; installed/time results remain pending.

2026-11-17T22:47:27Z — Tail encoding actual host comparison: bcc/set: 25/25 emit, 11028 -> 11028 neutral B, 0 tail slots, 0 counter-slot multiset differences; cilium/agent: 47/47 emit, 180609 -> 178766 neutral B, 87 tail slots, 0 counter-slot multiset differences; katran: 1/1 emit, 9241 -> 9241 neutral B, 0 tail slots, 0 counter-slot multiset differences; otelcol-ebpf-profiler/profiling: 14/14 emit, 130593 -> 130320 neutral B, 13 tail slots, 0 counter-slot multiset differences; tetragon/observer: 39/39 emit, 285659 -> 284403 neutral B, 59 tail slots, 0 counter-slot multiset differences; tracee/monitor: 169/169 emit, 1745934 -> 1744902 neutral B, 47 tail slots, 0 counter-slot multiset differences. Requests/errors and helper-target observations retained in comparison.json. No installed/per-call/body/helper/map/throughput gain claimed; Omp owns image/check/affected-app timing with all LTO on.

## Complete encoding attribution, 2026-11-17T22:58:51Z

Reader e8c96f9b3 completed against all295 paired actual requests under
timing SH/CPU19. All206 actual new stubs match the independently executed
short-encoding candidate byte-for-byte, including mapped four-byte counter
fields. Stub reduction is exactly4,326B. No guessed synthetic source rows
are used: the remaining78B is21 actual retained source-map width changes.

| App | Stub sites | Stub B removed | Outer Jcc shrinks | Outer JMP shrinks | Outer B removed | Total B removed |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Cilium | 87 | 1827 | 4 | 0 | 16 | 1843 |
| OTel | 13 | 273 | 0 | 0 | 0 | 273 |
| Tetragon | 59 | 1239 | 2 | 3 | 17 | 1256 |
| Tracee | 47 | 987 | 9 | 3 | 45 | 1032 |
| BCC/Katran | 0 | 0 | 0 | 0 | 0 | 0 |

Every outer conditional preserves its condition code and shrinks6->2B;
every outer JMP shrinks5->2B. All21 branch targets map to the same retained
source instruction in the after image. No source-map rows are lost/gained,
no other width changes, no mapped-target mismatch and no unattributed request
bytes. This explains78 =15*4 +6*3, and4,404 =4,326 +78 exactly. It is ordinary
existing block-encoder relaxation made possible by shorter inline stubs,
not another source optimization or removal of work.

Raw: /workspaces/kprog-raw/perf/tail-short-encodings-20261117/layout-delta.
All295 request/status records stay in the paired comparison; these are
neutral request-set byte observations, not installed bytes, hot frequencies,
stock proof or per-call measurements. No source change, rebuild, new guest
or repeated59-test/295-replay suite was needed for this classification.
