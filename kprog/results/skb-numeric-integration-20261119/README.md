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
