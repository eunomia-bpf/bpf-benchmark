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
