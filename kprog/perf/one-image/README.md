# One image, one base

Operator, 2026-11-11: "任何时候只允许一个镜像和一个底座", "benchmark 设置也不能改, 除非得到我同意".

`make -f kprog/perf/one-image/Makefile image` builds `bpf-benchmark/kprog:current` from the
2026-05-29 runtime recipe (`runner/mk/build.mk` and `runner/containers/runner-runtime.Dockerfile`,
both equal to 9f3855f6f apart from the `native-sim` to `kprog` rename) with:

- the kernel built by the frozen `host-kernel-x86` rule and the frozen defconfig, in place in the
  one base `/workspaces/.agent-state/kprog-ck/build-x86`;
- `/artifacts/kinsn` holding the stock-line native lab module (`kprog/perf/direct-native`),
  because the kinsn modules the frozen rule builds need the kinsn kernel.

No other image is kept. Removals are listed in `kprog/docs/cleanup-log.md`.

## Two native configurations, one switch

`NATIVE_MANIFEST` selects which native objects a run loads:

- the default, `/opt/bpf-benchmark/native-bpf/x86_64/<app>/manifest.json`, is the
  image's own manifest: the 2026-05-29 path with no load-time specialization;
- a directory under `corpus/results/` built by
  `vendor/bpf/native_specialize_objects.py` holds the specialized objects, where
  frozen `.rodata` globals are plain constants (clang folds their branches) and
  plain-array lookups are address arithmetic.

`scripts/specialized-timing.sh <app> <manifest-dir> <state-dir> <samples>
<seconds> <cpus>` runs one application with either configuration against its own
eBPF baseline in the same run. Measured on BCC (3x180 s, stats on, CPUs 0-7):
per invocation 1.006x with the image's objects and 1.221x with the specialized
ones; `sys_exit` alone goes 85.1 -> 41.9 ns per invocation (2.033x).
