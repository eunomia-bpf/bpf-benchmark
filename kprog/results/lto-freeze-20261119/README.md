# BCC in the LTO configuration with frozen private unknown inputs (2026-11-19)

Coordinator batch. 2eb36bad9 gives each private unknown input read of the simulator a frozen undefined value on the
native side; offline the 25 BCC requests go from 18 418 to 7 282 B of native code (lto-config-20261119/native-size-bcc.tsv).
run.sh waits until the request-time inputs (simulator headers, generator, service, loader) are committed, so the
lock-prefix work in progress by perf is measured as committed, then installs the checked-sim compiler tools from HEAD
(make -C kprog/libnativeloader checked-sim-stage) and times BCC with the recipe of native-cohort-timing-20261119
(run_lto.sh, 3 x 180 s per arm, stats on, CPUs 0-7, 8 vCPUs, 64 GiB). Raw: /workspaces/kprog-raw/coordinator/lto-freeze-20261119.
Previous measurement of the same recipe before 2eb36bad9: per call 1.016x, throughput 1.018x, installed 20 043 B vs JIT 7 965 B.
