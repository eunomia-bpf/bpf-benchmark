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
