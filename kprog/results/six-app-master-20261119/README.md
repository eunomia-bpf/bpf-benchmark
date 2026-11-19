# Six apps on current master, frozen timing entry (2026-11-19)

Coordinator batch (audit 20261119T09Z item 5: current master had no six-app timing of its own). Image
bpf-benchmark/kprog:current built 12:27 UTC from master after 9caea4ed6 (one manifest rule for every app) and
07d9c4c96 (hand-written helper routines deleted); six-app check of that image 14 / 25 / 135 / 288 / 169 / 1 replaced,
0 loader failures (5035abdf5). run.sh runs kprog/perf/one-image/Makefile rotate as it stands: stats off then on,
three 180 s samples per app, breadth first. Raw: /workspaces/kprog-raw/coordinator/six-app-master-20261119.

Withdrawn at 13:24 UTC before it started (coordinator). The native code it would time is the code lean test 1 measured
(helper routines deleted; the common manifest rule changes only which entry a program binds), so its numbers stand
for current master's direct native (operator 2026-11-18: "不要随便重跑"). CPUs 0-7 go to the LTO configuration on the
apps with larger body share.
