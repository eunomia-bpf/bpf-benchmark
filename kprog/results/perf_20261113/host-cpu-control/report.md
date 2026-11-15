# Frozen host CPU preparation and restoration

2026-11-15T16:50Z:2636bec14 puts the unchanged root `make kvm-host-cpu`
around the existing one-image vng invocation. This restores a skipped
frozen benchmark preparation step. Guest/workload/image/native settings
are unchanged. Each corpus run writes host-cpu-*.json under its LOGS.

The controller captures all24 governors, turbo and24min/max pairs (73
controls). It restores turbo, compatible frequency bounds and governors
after completion, preparation/command failure or SIGTERM, and preserves
child/prepare statuses separately from restoration errors. The timing
caller retains its existing lock; no new result-admission rule is added.

Four filesystem/child-process regressions pass: success0, command failure7,
partial preparation failure5 and SIGTERM143, with original controls restored
and valid min/max write ordering. Real host probe exits0: all governors
performance, no_turbo1 and policies0–7 min=max3700000kHz during the payload;
all73 values match their captured originals afterward (powersave,
no_turbo0, policy0 min800000/max5500000). No guest or timing result was
produced by this short controller probe. Actual before/prepared/restored
values are in host-probe.json; unit.json records the four outcomes.

C was notified to rerun Katran one A/A and one A/B. The earlier1.060x
header-route per-call observation did not include this host preparation;
it remains historical raw data, not this fixed-frequency run's result.

Coordinator16:41 withdrew the workspace-wide work/timing exclusion. The
original100K launcher1069320's timingSH was released by pidfd16:49:42;
its compiler/input/imageSH remained intact. Historical16:23:40–16:49:42
lease explains C's wait. Only an unstarted functional waiter was reordered
without timingSH; its original commands/status remain raw. Timing0–7 and
functional guests18–19 now use their normal separate resource roles.

Raw `/workspaces/kprog-raw/perf/20261115-host-cpu` retains exact commands,
root Make output, dry-run, synthetic case states and actual control values.
Skill: `.agents/skills/kvm-benchmark-workflow/SKILL.md`. No kernel/base/image,
worktree, source copy or paper change; no raw data deleted.
