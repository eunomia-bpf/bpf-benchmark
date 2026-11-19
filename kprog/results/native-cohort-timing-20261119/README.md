# Combined checked-native BCC timing batch

The cohort through ff02957cc passed the canonical BCC functional check:
25 programs/native/B-generated/B-stock, zero fallback/failure, app ok
(native-cohort-check-20261119). This batch measures those changes together.

Hold batch EX from the frozen one-image image recipe through its six-app
check and the final BCC timing. Build under timing SH/image EX; guests under
timing EX/image SH. The sole image/base is replaced in place. Source/helper
changes stay enabled together; no new producer, kernel or benchmark change.

BCC uses the coordinator's existing main-config guest entry
lto-config-20261119/run_lto.sh (checked-sim-c), with three 180-second samples
per arm, stats enabled, CPUs 0–7, eight vCPUs and 64 GiB, including the frozen
kvm-host-cpu step. Only the functional six-app check uses its existing 1x10s
definition. Direct-only corpus timing would not exercise the C helpers.

Each stage has its own log and completion status under the persistent raw
directory. Expect roughly 30–50 minutes depending on cached build/startup
work. Read the actual app/coverage results and sample series when complete;
no speed gain is claimed from the earlier functional run.

PERF 2026-11-19T08:23:26Z: Timing-wrapper dry run passed. The full image dry run entered
forced recursive kernel recipes despite make -n; only owned make244102 was
stopped (143), with no guest using the base. Its log stays at
/workspaces/kprog-raw/perf/native-cohort-timing-20261119/image-dry-run-20261119T0819Z.txt.
Normal batch254724 then started the frozen build under image EX at08:22:12Z,
raw batch-20261119T082212Z-254724. No source/kernel version or benchmark
setting changed during this correction.
