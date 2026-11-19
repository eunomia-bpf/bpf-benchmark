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

PERF 2026-11-19T07:20:02Z: Worker211523 ended with Make exit2. Frontend, bounds,
pre-PEI backend and spill packing completed; final llc object emission fails
with the existing 4096-byte B compiler stack limit. New stock acceptance and
native O3 compilation were not reached for this request. See tetragon-result.json;
all full logs/MIR remain raw. The production limit and service native-first
fallback are unchanged.

Correction to the 07:10 coordination note: the last directly observed packing
process at 07:00:20 had elapsed16m18s; the lowering report file was written
around07:03, and the job had advanced to llc before that note. It was no longer
in packing at07:10. The repeated whole-function/pair scans remain a source
performance finding, but no greater-than20-minute measured duration is claimed.

Diagnostic worker221549 reuses that completed packed MIR with a diagnostic
65536-byte compiler bound solely to reveal actual frame/code size. It does not
repeat frontend or packing and does not change production flags, the kernel's
512-byte stock limit, benchmark settings, or installation policy. Results will
be committed after completion.

PERF 2026-11-19T07:26:12Z: The retained-MIR diagnostic completed (worker221549,
raw `/workspaces/kprog-raw/perf/b-analysis-flags-20261119/stack-20261119T071859Z-221549`): largest direct R10 displacement5776 B and executable
sections10,589,544 B. This is a diagnostic object, not stock verification;
production compiler4096/stock512 limits remain unchanged. Raising the
compiler bound cannot close the actual stack gap.

Experiment af6ef8d95 now tests O3 only after the existing bounds pass has
removed private volatility/opaque identities and described helper memory.
It reuses the completed O1 frontend's .bounds.bc, so it does not repeat the
original slow C frontend or alter production flags. Worker223517 runs on
CPU18, timing SH/image SH,32GiB AS; results will distinguish pass ordering
from simply restoring the original expensive O3 frontend.

PERF 2026-11-19T08:05:59Z: The post-contracts O3 experiment is complete. Its clang backend
succeeded in 756.376s and saved235MiB MIR. The initial packing
child was interrupted solely to release an unnecessary image lease; that
interruption is retained separately. Resuming the immutable MIR with only
timing SH took1322.171s in packing (return0), then
16.463s in final llc (return1): the existing4096-byte
compiler stack limit is still exceeded. O3 after the current IR contracts
alone does not solve this request. The production O1/g policy and limits
stay unchanged; no further relaxed-limit replay was run. Stock verification
and checked-native installation were not reached. See post-contract-result.json;
all raw remains at /workspaces/kprog-raw/perf/b-analysis-flags-20261119/resume-20261119T074139Z-227467. Worker227467 and its leases are terminal.

OMP 2026-11-19T19:05Z: The full-size stock verification the O1 decision owed is
now recorded, from the checked corpus runs rather than from a synthetic object.
18 verified requests were installed with `b_stock_passed=true` after
`be3946f6d`: 14 Cilium (`/workspaces/kprog-raw/verified/20261119-checked-cilium/`,
each B's preprocessed `.i` 3.58-3.89 MiB), 3 OTel
(`/workspaces/kprog-raw/verified/20261119-checked-otel2/`, 3.72-4.53 MiB) and 1
Katran (`/workspaces/kprog-raw/verified/20261119-checked-katran2/`, 4.71 MiB).
Each of the 18 has `request/checked-simulator-verification.json` with
`phase=verify, status=0`, i.e. the stock verifier accepted the whole B and
`BPF_PROG_LOAD` returned a program id, so B opens in libbpf and verifies at
sizes two orders of magnitude past the minimal object that established the g
requirement. The compiler command line inside those archives is
`clang -w -g -O1` (B) and `llc-18 -O1` (native), so the level under test is the
production one. The limit that O1 still does not close is the separate one above:
Tetragon's 5,776-byte direct R10 displacement against the stock 512-byte bound.
