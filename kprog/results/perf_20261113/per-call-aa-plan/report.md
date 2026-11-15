# Per-call A/A counter route

2026-11-15: the completed 72fb8a71a throughput control used SKIP_REJIT=all.
Its empty BPF dictionaries are the explicit return value at
runner/libs/rejit.py:449–458. This branch bypasses shim measurement regardless
of the enabled kernel stats sysctl. It is not a missing kernel counter.

Existing SKIP_REJIT=norejit keeps the shim and measure_start/measure_finish,
while skipping the load-time bytecode plan. Native loading must independently
be disabled for both arms: BPFREJIT_SHIM_NATIVE_LOADER=0. The shim enables its
native loader only for the literal value 1. The frozen corpus driver changes
post into 1 for the second start, but preserves 0 in both starts.

The C-owned one-image guest recipe currently hardcodes post. PERF posted the
exact fix to COORDINATION at 07:06:10Z: expose that existing mode as one Make
variable, default post, forward it to the guest, select 0 only for A/A. This
requires no change to frozen runner/workload/image definitions or counter
collection code. C owns the timing entry point and shared-disk migration;
PERF will use its posted command, dry-run it, and launch the per-call control
under timing EX plus image SH, alone on CPUs 0–7, 3x180s, stats enabled. All
native LTO remains combined when native mode is selected.

This is a source-backed diagnosis and handoff, not a completed per-call
control. The earlier throughput result remains raw evidence (+17.26% later
arm); program identities, JIT sizes and per-call time were unobserved there.
Read actual program counters and both-arm facts from the next run before
reporting its outcome. No fabricated counters or frozen-runner edits.
