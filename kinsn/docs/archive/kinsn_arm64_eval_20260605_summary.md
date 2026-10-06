# arm64 AWS kinsn follow-up 2026-06-05

Artifact: `corpus/results/aws_arm64_corpus_20260605_053223_453376`
Coverage-smoke artifact: `corpus/results/arm64_qemu_corpus_recorded_20260605_vmclock_000005_560691`
Figure: `docs/figures/eval-kinsn-arm64-aws-20260605.png`

## App status and performance

| App | status | sites applied | workload ratio | BPF cost ratio | retained rows | wins/losses/ties | error |
| --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| `bcc/set` | `ok` | 0 | 0.979x | 0.942x | 14 | 9/5/0 | `` |
| `cilium/agent` | `ok` | 0 | 0.974x | 1.003x | 2 | 1/1/0 | `` |
| `katran` | `ok` | 0 | 1.020x | 0.987x | 1 | 1/0/0 | `` |
| `otelcol-ebpf-profiler/profiling` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T05:41:20.124Z info otelconftelemet...` |
| `tetragon/observer` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Starting tetragon" version=v1.8...` |
| `tracee/monitor` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `Tracee exited before BPF programs were tracked by shim stderr tail: {"level":"error","ts":1780639032.0548303,"msg":"e...` |

## Applied families

| Family | sites |
| --- | ---: |

## Applied names

| Kinsn | sites |
| --- | ---: |

## Coverage-smoke upper bound

| Family | sites |
| --- | ---: |

| Kinsn | sites |
| --- | ---: |
