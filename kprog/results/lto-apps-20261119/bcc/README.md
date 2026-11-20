# BCC in the main-configuration recipe (2026-11-20 09:03 UTC, source 3ee03baa3)

Run x86_kvm_corpus_20261120_090334_692077, recipe kprog/results/lto-apps-20261119/Makefile (APP=bcc/set,
3 x 180 s per arm, stats on), omp's arm under `flock -x` on locks/timing.

- Coverage: 25 programs, **25 checked native** (B generated and passed the stock verifier), 0 direct native,
  0 failed, 0 kept on eBPF. The shim log records `native-loader replaced` for 25 of 25. This is a full-coverage
  arm with every program on the accepted-B path.
- Per call: geomean **0.998** over the 15 retained pairs, call parity 1.01, so the two arms did equal work.
  `sys_exit` 0.916, `sys_enter` 0.980, `sched_wakeup` 0.872 are ahead; `sched_switch` 1.200 is the largest loss.
- BCC is at parity on this image. Its fastest programs (`sys_exit`, `sys_enter`, `fentry_vfs_open` 0.997) sit at
  37-84 ns/inv, where the remaining time is dominated by the fixed per-invocation work rather than the emitted
  body, so parity is the expected outcome rather than a defect. The three readings of the day (0.964, 0.96,
  0.998) agree within run-to-run spread.

Raw: /workspaces/kprog-raw/omp/lto-bcc-20261120T0903Z (service archive with verifier logs).