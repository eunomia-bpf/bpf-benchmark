# Shared benchmark framework design

The shared framework connects real application startup, workload execution,
raw counter collection, and result storage. The project-specific optimizer
and simulator implementations are documented in the [project index](../../README.md#research-projects).

## Components

| Component | Role |
| --- | --- |
| [`corpus/`](../../corpus/) | Six supported application definitions and workloads; apps load their own BPF programs |
| [`micro/`](../../micro/) | Isolated BPF program workloads and runtime comparisons |
| [`runner/`](../../runner/) | Make-backed KVM and AWS execution, runtime images, and pass plans |
| [`bpfperf/`](../../bpfperf/) | External per-site PMU collection for profile-guided work |
| [`analysis/`](../../analysis/) | Post-hoc analysis of saved raw results |
| [`.github/workflows/`](../../.github/workflows/) | CI entrypoints |

The root [`Makefile`](../../Makefile) is the supported suite entrypoint.
`make selftest`, `make negative-test`, `make test`, `make micro`, and
`make corpus` select the default x86 KVM target. Set `PLATFORM=aws` and
`ARCH=x86` or `ARCH=arm64` for AWS. The platform defaults and instance
settings live in the root [`Makefile`](../../Makefile) and
[`runner/suites/`](../../runner/suites/).

The runner records raw per-program counters, application workload metrics,
stdout/stderr, and lifecycle events in `result.json`. It does not calculate
paper summaries. [`docs/evaluation.md` §5](../evaluation.md) defines the
post-hoc ratio and aggregation method. The current corpus app list and pass
policy live in [`corpus/config/`](../../corpus/config/); per-pass policy lives
in [`runner/config/passes/`](../../runner/config/passes/).

Build outputs stay next to their owning component as specified in
[`build.md`](../../build.md). Runtime image layering and host boundaries are
described in the [container guide](../../runner/containers/README.md).
Earlier design decisions and investigations are in the
[shared archive](../archive/shared/README.md).
