# kinsn ablation follow-up 2026-06-05

Figure: `docs/figures/eval-kinsn-ablation-20260605.png`

## x86 KVM

| Variant | Artifact | total sites | top families |
| --- | --- | ---: | --- |
| Full | `corpus/results/x86_kvm_corpus_20260924_064817_392000` | 4017 | lea=1927, endian_fusion=714, bulk_memory=526, prefetch=505, cond_select=262 |
| No prefetch | `corpus/results/x86_kvm_corpus_20260924_074900_275227` | 3512 | lea=1927, endian_fusion=714, bulk_memory=526, cond_select=262, bitops=81 |
| No bulk | `corpus/results/x86_kvm_corpus_20260924_085901_647044` | 3517 | lea=1929, endian_fusion=714, prefetch=529, cond_select=262, bitops=81 |
| No bulk/pref | `corpus/results/x86_kvm_corpus_20260924_095500_223221` | 2988 | lea=1929, endian_fusion=714, cond_select=262, bitops=81, extract=2 |

| Variant | App | status | sites | workload | BPF cost | retained | wins/losses/ties | error |
| --- | --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| Full | `cilium/agent` | `ok` | 4017 | 1.012x | 0.956x | 2 | 1/1/0 | `` |
| No prefetch | `cilium/agent` | `ok` | 3512 | 1.040x | 0.906x | 2 | 2/0/0 | `` |
| No bulk | `cilium/agent` | `ok` | 3517 | 1.069x | 0.828x | 2 | 2/0/0 | `` |
| No bulk/pref | `cilium/agent` | `ok` | 2988 | 1.138x | 0.722x | 2 | 2/0/0 | `` |

## arm64 AWS

| Variant | Artifact | total sites | top families |
| --- | --- | ---: | --- |
| Conservative | `corpus/results/aws_arm64_corpus_20260605_080836_924256` | 0 |  |
| All selectors | `corpus/results/aws_arm64_corpus_20260605_094729_221231` | 0 |  |
| No prefetch | `corpus/results/aws_arm64_corpus_20260605_173727_537598` | 0 |  |
| No bulk | `corpus/results/aws_arm64_corpus_20260605_181724_716941` | 0 |  |
| No bulk/pref | `corpus/results/aws_arm64_corpus_20260605_185723_289466` | 0 |  |

| Variant | App | status | sites | workload | BPF cost | retained | wins/losses/ties | error |
| --- | --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| Conservative | `bcc/set` | `ok` | 0 | 1.002x | 0.954x | 14 | 10/4/0 | `` |
| Conservative | `cilium/agent` | `ok` | 0 | 0.983x | 0.997x | 2 | 1/1/0 | `` |
| Conservative | `katran` | `ok` | 0 | 1.073x | 0.941x | 1 | 1/0/0 | `` |
| Conservative | `otelcol-ebpf-profiler/profiling` | `ok` | 0 | 0.985x | 1.048x | 2 | 0/2/0 | `` |
| Conservative | `tetragon/observer` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| Conservative | `tracee/monitor` | `ok` | 0 | 1.009x | 1.012x | 60 | 21/39/0 | `` |
| All selectors | `bcc/set` | `ok` | 0 | 0.980x | 1.016x | 14 | 4/10/0 | `` |
| All selectors | `cilium/agent` | `ok` | 0 | 0.978x | 1.066x | 2 | 0/2/0 | `` |
| All selectors | `katran` | `ok` | 0 | 0.995x | 1.006x | 1 | 0/1/0 | `` |
| All selectors | `otelcol-ebpf-profiler/profiling` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T09:56:20.3...` |
| All selectors | `tetragon/observer` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| All selectors | `tracee/monitor` | `ok` | 0 | 0.938x | 1.047x | 60 | 17/43/0 | `` |
| No prefetch | `bcc/set` | `ok` | 0 | 0.950x | 0.984x | 14 | 8/6/0 | `` |
| No prefetch | `cilium/agent` | `ok` | 0 | 0.982x | 1.029x | 2 | 0/2/0 | `` |
| No prefetch | `katran` | `ok` | 0 | 0.965x | 1.046x | 1 | 0/1/0 | `` |
| No prefetch | `otelcol-ebpf-profiler/profiling` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T17:46:23.8...` |
| No prefetch | `tetragon/observer` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No prefetch | `tracee/monitor` | `ok` | 0 | 0.971x | 0.999x | 60 | 40/20/0 | `` |
| No bulk | `bcc/set` | `ok` | 0 | 1.072x | 1.123x | 14 | 1/13/0 | `` |
| No bulk | `cilium/agent` | `ok` | 0 | 0.986x | 1.016x | 2 | 0/2/0 | `` |
| No bulk | `katran` | `ok` | 0 | 0.991x | 1.015x | 1 | 0/1/0 | `` |
| No bulk | `otelcol-ebpf-profiler/profiling` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T18:26:18.8...` |
| No bulk | `tetragon/observer` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No bulk | `tracee/monitor` | `ok` | 0 | 0.982x | 1.036x | 60 | 23/37/0 | `` |
| No bulk/pref | `bcc/set` | `ok` | 0 | 0.933x | 0.966x | 14 | 9/5/0 | `` |
| No bulk/pref | `cilium/agent` | `ok` | 0 | 1.007x | 0.999x | 2 | 1/1/0 | `` |
| No bulk/pref | `katran` | `ok` | 0 | 1.009x | 1.001x | 1 | 0/1/0 | `` |
| No bulk/pref | `otelcol-ebpf-profiler/profiling` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T19:06:21.7...` |
| No bulk/pref | `tetragon/observer` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No bulk/pref | `tracee/monitor` | `ok` | 0 | 0.985x | 1.019x | 60 | 17/43/0 | `` |

