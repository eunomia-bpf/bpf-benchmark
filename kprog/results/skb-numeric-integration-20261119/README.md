# Shared SKB field and NUMERIC integration

The NUMERIC component repair0dfa23814 preserves an already supplied value.
This regression tests the preceding public-to-physical context conversion
as well, using the real shared X86_SIM_L_SKB_FIELD and CTX_NUMERIC macros.
The smallest scope is those two compiler stages; no guest or new runtime
validation is involved.

The normal stock frontend feeds compile-sim-ir, then the sole context-lower
with its public/physical layouts, then native O3 execution. Twenty-eight
cases cover data/data_end full bits and low/high lanes, plus a mark-field
control. Actual physical fields are populated in host buffers, with canary
bytes elsewhere. No packet pointer is dereferenced. Both intermediate IRs,
layouts, tool stderr and every executed row are retained.

Source review found an interaction to test: native memory lowering inserts
an opaque register barrier, while context lowering recognizes roots through
LLVM pointer-origin analysis. This is a hypothesis, not a confirmed defect.
A compiler/setup error must be distinguished from an executed mismatch.
The test establishes no corpus path hit, stock-B load or performance result.

The detached recipe waits timing SH/image SH, on CPU18 with4GiB AS. It
changes no production input and starts no image or guest. Heavy work waits
for the coordinator's active Tracee timing to release the lock.

PERF 2026-11-19T14:00:51Z: Committed827e0c601/07df70aea; worker422533 queued at
13:58:47Z, waiting timing SH. Raw:
/workspaces/kprog-raw/perf/skb-numeric-integration-20261119/test-20261119T135847Z-422533.
Launcher: /workspaces/kprog-raw/perf/skb-numeric-integration-launch-20261119.log.
No compilation or execution result yet. The existing Tracee batch owns the
image and timing window; its production inputs remain unchanged.

PERF 2026-11-19T15:42:36Z: While worker422533 is still unstarted (only queued/run.log
exist), the fixture now adds direct C loads for data, data_end and mark.
The same classifier section, sole physical buffers and compiler stages
exercise12 control cases alongside the original28 shared-macro cases,
40 total. The existing context pass explicitly widens complete packet
pointer loads, including their integer zero extensions, so data/end controls
expect physical64-bit values rather than truncated public32-bit fields.
These controls leave the context root visible without memoryAsm's opaque
base barrier. If controls pass but shared cases fail, inspect the retained
IR root chains before choosing a repair. If both fail, the experiment has
not isolated that barrier. No production source, queued launcher, compiler
flag, layout or active Tracee input changed. Actual host execution remains
pending on timing SH; this is a regression improvement, not a test pass.

PERF 2026-11-19T16:39:41Z: The former guest and all three queued readers were absent
at16:36, without terminal files; Tracee's final service.tar.gz is absent
but its completed request capsules remain. Cause of interruption is unknown.
No guest was restarted and no old raw output was removed. This host test
was restarted under timing SH/image SH as16647 and completed with make2
at raw /workspaces/kprog-raw/perf/skb-numeric-integration-20261119/test-20261119T163739Z-16647. All compiler stages succeed; actual execution has18 mismatches
in40cases. All12direct-C controls pass. Shared data/mark read the0xa5 canary
from public positions, and shared data_end loses high bits. The retained
IR shows data_value reading public76/i32 behind an opaque =r,0 barrier,
while data_direct reads physical208/i64. This confirms context-root
recognition is lost at native memory lowering, rather than a wrong layout
or a standalone NUMERIC bit-loss recurrence. Baseline rows and IR excerpt
are committed; full commands/IR/layouts remain raw. No app/path/timing claim.

PERF 2026-11-19T16:45:29Z: Production compile_sim_ir.cpp repairs this class by returning
the externally callable entry-context pointer directly from memory-base
lowering. It is already a runtime register. This avoids both the opaque
barrier and a ptrtoint/inttoptr round trip that also obscures the root.
Other bases retain the exact existing barrier and pointer conversion. No
runtime condition/check, source flag, kernel or context-compiler change.

Canonical checked-sim-stage rebuilt the sole base tools under timing SH /
image EX. Worker21511 completes0 at16:44:18Z:40/40field cases pass, the
absolute0x70control still emits a register-base load, and NUMERIC30cases
plus six plain ABI controls and B emission pass. The faulting absolute
address is inspected, never executed. Fixed rows and IR excerpt are
committed; full raw /workspaces/kprog-raw/perf/skb-numeric-integration-20261119/fix-20261119T164404Z-21511.

Failed attempts remain raw: worker20584 first hit a test-fixture placeholder
error ($$0 rather than a C operand); corrected fixture431282dc8 then exposed
18 mismatches because removing the barrier alone retained the cast pair.
Those are not hidden or counted as passes. Revised pointer-preserving
lowering is what worker21511 tests. No image/guest or app coverage/timing
was run; actual checked Cilium confirmation remains separate.
