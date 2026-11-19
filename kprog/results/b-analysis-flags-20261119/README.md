# Analysis-only B compile flags

The 2026-11-19T06:20 audit calls for O1/g0 for B after the retained Tetragon
frontend's superlinear O3/GVN compile. P and final native LTO stay O3.
First check the loader metadata contract: the simulator declares typed .ksyms
map externs, which libbpf must open before the stock verifier can inspect B.
The minimal real B object tests O1 with g0, line tables, and full type debug.
This is a host ELF/libbpf-open check, not a stock load or app timing run.

PERF 2026-11-19T06:35:06Z: Metadata test completes: O1/g0 returns libbpf open
error -3 and no .BTF; O1/line-tables has no usable extern type and also returns
-3; O1/g opens successfully. The actual loader opens B before relocation
(native_loader.cpp:4013), so dropping all type debug prevents verification.
The implemented policy is O1 for B's frontend/backend with g retained for
BTF. P and final native compilation stay O3. This follows the audit's
compilation-cost goal while retaining its required loader metadata.

Fresh production generation from retained P passes for BCC fentry_vfs_read
and inet_sock_set_state. Both B objects open in libbpf, the checked frontend
is reused, and native compilation/proof linking succeeds with O3 and both
C helper classes enabled. See bcc-subset.json for measured generation times
and direct R10 displacements; those are not stock acceptance or a full
interprocedural stack proof. No guest or image is started.

Tetragon request 6's fresh generation/native compile continues under timing
SH/image SH on CPU19 with a 32GiB AS bound. Raw: `/workspaces/kprog-raw/perf/b-analysis-flags-20261119/production-20261119T063351Z-210433`;
worker 210433. The production recipe uses the same stock-input CLANG wrapper
as checked-corpus. Initial trials are retained: the first precreated the
specializer's request directory, and the second used unwrapped Clang, whose
private-input .8byte assembly the native converter correctly refused.
Recipes 314f258e0 and eb9bee618 fix those host-test setup errors. The first
metadata fixture also used the wrong libbpf include path; 61b642be2 fixes it
and preserves compiler diagnostics. No converter capability or source app
is changed to accommodate those test mistakes.

Per-call/native installed bytes/stock coverage remain for OMP's combined
checked-sim-c batch, which the audit now targets at Tetragon and Tracee.

PERF 2026-11-19T06:42:34Z, status correction: worker 210433 completed the BCC subset
but stopped before Tetragon because its prior generation-failure archive has
no generated/artifacts.json. d71b7f19b reads the canonical capsule kernel.entry
instead. The Tetragon-only retry is worker 211523, raw
`/workspaces/kprog-raw/perf/b-analysis-flags-20261119/production-20261119T063707Z-211523`.
Its O1 frontend has completed successfully (34 MiB frontend IR), and the
bounds stage completes (22 MiB IR), removing 2,667 unused private inputs and
230,724 debug-variable intrinsics. The B machine backend is still running;
no complete Tetragon B/native/stock claim is made. The already-committed BCC
subset passed with generation 1.052/3.246 s and native O3 compilation
0.046/0.408 s. g is retained for BTF; existing bounds lowering removes the
non-executing scalar debug intrinsics before the B machine backend.
