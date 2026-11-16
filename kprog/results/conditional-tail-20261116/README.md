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
