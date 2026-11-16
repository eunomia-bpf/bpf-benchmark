Conditional function tail closure, 2026-11-16

The smallest fix retains conditional function tail targets in the existing
closure and routes them through the existing tail-jump rewrite. The condition
must still select the same return value. No new mode, refusal or runtime
check is needed. This follows the real generic_kprobe_filter_arg failure in
host-link-replay-20261116/tetragon-diagnostic.md.

The assembly reproducer branches to a separately aligned local function.
It exercises the conditional tail both in a subprogram (entry) and as the
entry function (choose). Before the fix, proof extraction succeeds for both
while kernel emission rejects their stale conditional displacement: entry
IP0xc targets0x2a; choose IP0x2 targets0x20. The selected callee is absent.
The retained logs and initial outputs are under
/workspaces/kprog-raw/perf/20261116-conditional-tail/before.

The replay target uses the canonical linker and one retained plan's kernel
layout facts. The assembly calls no external helper or map. After successful
kernel emission it executes both conditions and records actual and expected
returns, alongside code bytes. This is a host control-flow regression test;
app installed bytes, per-call costs and B stock verification are separate.

Forward fix, 2026-11-16T22:55:25Z

Recognize conditional Jcc function tails and their actual relocation field,
include their callees in the existing closure, and place the inverse original
condition around the existing unconditional tail rewrite. This preserves
the established proof relocation, entry wrapper and kernel transfer ABI.
The production diff is 22 added and 7 removed lines; no new helper, mode,
refusal or runtime check is introduced. Short and near branches plus a
cross-section PC32 relocation execute correctly as entry and nested tails.

All four proofs and kernel links now pass, and actual returns for inputs
0/1/2/255 are 22/11/11/11 in every case (16 executions). Fixture code sizes
are 31 B for nested entry and 39 B for each direct entry. These are host
fixture bytes, not application installed sizes. The first positive replay
omitted output-abi: it emitted blobs then failed its required metadata step.
That initial result remains in raw/after; corrected outputs are raw/after-abi.

The existing linker tests pass 51 cases with zero failures and three existing
ignored cases. Current P host replay passes 475 candidate entry extractions
and 239 captured kernel emissions across six apps; corpus-summary.json
records the counts. The Tetragon policy/CEL context itself remains a coverage
gap in those retained plans, now exposed by this specific reproducer.

Current image 96a677d6826f predates this source fix. Its frozen check is
running. Application native installation, per-call body/helper/map costs
and B stock verification remain pending; no performance gain is inferred.
