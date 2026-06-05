# arm64 AWS kinsn follow-up 2026-06-05

Artifact: `corpus/results/aws_arm64_corpus_20260605_094729_221231`
Coverage-smoke artifact: `corpus/results/aws_arm64_corpus_20260605_085337_334187`
Figure: `docs/figures/eval-kinsn-arm64-aws-20260605.png`

## App status and performance

| App | status | sites applied | workload ratio | BPF cost ratio | retained rows | wins/losses/ties | error |
| --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| `bcc/set` | `ok` | 50 | 0.980x | 1.016x | 14 | 4/10/0 | `` |
| `cilium/agent` | `ok` | 2976 | 0.978x | 1.066x | 2 | 0/2/0 | `` |
| `katran` | `ok` | 62 | 0.995x | 1.006x | 1 | 0/1/0 | `` |
| `otelcol-ebpf-profiler/profiling` | `error` | 12 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T09:56:20.362Z info otelconftelemet...` |
| `tetragon/observer` | `error` | 139 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Starting tetragon" version=v1.8...` |
| `tracee/monitor` | `ok` | 8070 | 0.938x | 1.047x | 60 | 17/43/0 | `` |

## Applied families

| Family | sites |
| --- | ---: |
| `bulk_memory` | 8685 |
| `prefetch` | 1810 |
| `endian_fusion` | 791 |
| `rotate` | 20 |
| `extract` | 3 |

## Applied names

| Kinsn | sites |
| --- | ---: |
| `bpf_arm64_stp_x` | 6656 |
| `bpf_arm64_ldp_x` | 2029 |
| `bpf_arm64_prfm_pldl1keep` | 1810 |
| `bpf_arm64_rev16_w` | 699 |
| `bpf_arm64_rev_w` | 46 |
| `bpf_arm64_rev_x` | 46 |
| `bpf_arm64_extr_w` | 20 |
| `bpf_arm64_ubfm_x` | 3 |

## Coverage-smoke upper bound

| Family | sites |
| --- | ---: |
| `bulk_memory` | 8704 |
| `prefetch` | 1821 |
| `endian_fusion` | 791 |
| `rotate` | 20 |
| `extract` | 3 |

| Kinsn | sites |
| --- | ---: |
| `bpf_arm64_stp_x` | 6664 |
| `bpf_arm64_ldp_x` | 2040 |
| `bpf_arm64_prfm_pldl1keep` | 1821 |
| `bpf_arm64_rev16_w` | 699 |
| `bpf_arm64_rev_w` | 46 |
| `bpf_arm64_rev_x` | 46 |
| `bpf_arm64_extr_w` | 20 |
| `bpf_arm64_ubfm_x` | 3 |
