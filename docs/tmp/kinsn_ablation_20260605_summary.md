# kinsn ablation follow-up 2026-06-05

Figure: `docs/figures/eval-kinsn-ablation-20260605.png`

## x86 KVM

| Variant | Artifact | total sites | top families |
| --- | --- | ---: | --- |
| Full | `corpus/results/x86_kvm_corpus_20260605_145112_835705` | 23719 | lea=11559, bulk_memory=8351, prefetch=2260, endian_fusion=892, cond_select=589 |
| No prefetch | `corpus/results/x86_kvm_corpus_20260605_141420_746952` | 21487 | lea=11585, bulk_memory=8353, endian_fusion=892, cond_select=589, extract=48 |
| No bulk | `corpus/results/x86_kvm_corpus_20260605_164411_317423` | 15661 | lea=11690, prefetch=2422, endian_fusion=892, cond_select=589, extract=48 |
| No bulk/pref | `corpus/results/x86_kvm_corpus_20260605_160715_129437` | 13123 | lea=11580, endian_fusion=892, cond_select=583, extract=48, rotate=20 |

| Variant | App | status | sites | workload | BPF cost | retained | wins/losses/ties | error |
| --- | --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| Full | `bcc/set` | `ok` | 80 | 1.006x | 1.064x | 15 | 4/11/0 | `` |
| Full | `cilium/agent` | `ok` | 4697 | 1.114x | 0.776x | 2 | 2/0/0 | `` |
| Full | `katran` | `ok` | 96 | 1.020x | 0.952x | 1 | 1/0/0 | `` |
| Full | `otelcol-ebpf-profiler/profiling` | `ok` | 1824 | 0.985x | 1.103x | 1 | 0/1/0 | `` |
| Full | `tetragon/observer` | `error` | 947 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| Full | `tracee/monitor` | `ok` | 16075 | 1.008x | 0.994x | 40 | 25/15/0 | `` |
| No prefetch | `bcc/set` | `ok` | 77 | 1.005x | 1.027x | 15 | 8/7/0 | `` |
| No prefetch | `cilium/agent` | `ok` | 4086 | 1.055x | 0.871x | 2 | 2/0/0 | `` |
| No prefetch | `katran` | `ok` | 90 | 1.024x | 0.922x | 1 | 1/0/0 | `` |
| No prefetch | `otelcol-ebpf-profiler/profiling` | `ok` | 1475 | 1.000x | 1.063x | 1 | 0/1/0 | `` |
| No prefetch | `tetragon/observer` | `error` | 926 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No prefetch | `tracee/monitor` | `ok` | 14833 | 0.991x | 0.991x | 40 | 24/16/0 | `` |
| No bulk | `bcc/set` | `ok` | 71 | 1.012x | 0.980x | 15 | 12/3/0 | `` |
| No bulk | `cilium/agent` | `ok` | 4136 | 1.037x | 0.918x | 2 | 2/0/0 | `` |
| No bulk | `katran` | `ok` | 77 | 1.032x | 0.932x | 1 | 1/0/0 | `` |
| No bulk | `otelcol-ebpf-profiler/profiling` | `ok` | 1696 | 1.007x | 1.121x | 1 | 0/1/0 | `` |
| No bulk | `tetragon/observer` | `error` | 394 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No bulk | `tracee/monitor` | `ok` | 9287 | 0.988x | 0.996x | 40 | 16/24/0 | `` |
| No bulk/pref | `bcc/set` | `ok` | 68 | 1.011x | 1.005x | 15 | 6/9/0 | `` |
| No bulk/pref | `cilium/agent` | `ok` | 3512 | 0.999x | 0.991x | 2 | 2/0/0 | `` |
| No bulk/pref | `katran` | `ok` | 71 | 1.013x | 0.968x | 1 | 1/0/0 | `` |
| No bulk/pref | `otelcol-ebpf-profiler/profiling` | `ok` | 1348 | 1.026x | 1.156x | 1 | 0/1/0 | `` |
| No bulk/pref | `tetragon/observer` | `error` | 226 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No bulk/pref | `tracee/monitor` | `ok` | 7898 | 1.009x | 1.025x | 40 | 14/26/0 | `` |

## arm64 AWS

| Variant | Artifact | total sites | top families |
| --- | --- | ---: | --- |
| Conservative | `corpus/results/aws_arm64_corpus_20260605_080836_924256` | 24 | rotate=20, extract=4 |
| All selectors | `corpus/results/aws_arm64_corpus_20260605_094729_221231` | 11309 | bulk_memory=8685, prefetch=1810, endian_fusion=791, rotate=20, extract=3 |
| No prefetch | `corpus/results/aws_arm64_corpus_20260605_173727_537598` | 9518 | bulk_memory=8704, endian_fusion=791, rotate=20, extract=3 |
| No bulk | `corpus/results/aws_arm64_corpus_20260605_181724_716941` | 2896 | prefetch=2075, endian_fusion=796, rotate=20, extract=5 |
| No bulk/pref | `corpus/results/aws_arm64_corpus_20260605_185723_289466` | 821 | endian_fusion=796, rotate=20, extract=5 |

| Variant | App | status | sites | workload | BPF cost | retained | wins/losses/ties | error |
| --- | --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| Conservative | `bcc/set` | `ok` | 0 | 1.002x | 0.954x | 14 | 10/4/0 | `` |
| Conservative | `cilium/agent` | `ok` | 2 | 0.983x | 0.997x | 2 | 1/1/0 | `` |
| Conservative | `katran` | `ok` | 21 | 1.073x | 0.941x | 1 | 1/0/0 | `` |
| Conservative | `otelcol-ebpf-profiler/profiling` | `ok` | 0 | 0.985x | 1.048x | 2 | 0/2/0 | `` |
| Conservative | `tetragon/observer` | `error` | 1 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| Conservative | `tracee/monitor` | `ok` | 0 | 1.009x | 1.012x | 60 | 21/39/0 | `` |
| All selectors | `bcc/set` | `ok` | 50 | 0.980x | 1.016x | 14 | 4/10/0 | `` |
| All selectors | `cilium/agent` | `ok` | 2976 | 0.978x | 1.066x | 2 | 0/2/0 | `` |
| All selectors | `katran` | `ok` | 62 | 0.995x | 1.006x | 1 | 0/1/0 | `` |
| All selectors | `otelcol-ebpf-profiler/profiling` | `error` | 12 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T09:56:20.3...` |
| All selectors | `tetragon/observer` | `error` | 139 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| All selectors | `tracee/monitor` | `ok` | 8070 | 0.938x | 1.047x | 60 | 17/43/0 | `` |
| No prefetch | `bcc/set` | `ok` | 47 | 0.950x | 0.984x | 14 | 8/6/0 | `` |
| No prefetch | `cilium/agent` | `ok` | 2361 | 0.982x | 1.029x | 2 | 0/2/0 | `` |
| No prefetch | `katran` | `ok` | 56 | 0.965x | 1.046x | 1 | 0/1/0 | `` |
| No prefetch | `otelcol-ebpf-profiler/profiling` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T17:46:23.8...` |
| No prefetch | `tetragon/observer` | `error` | 121 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No prefetch | `tracee/monitor` | `ok` | 6933 | 0.971x | 0.999x | 60 | 40/20/0 | `` |
| No bulk | `bcc/set` | `ok` | 3 | 1.072x | 1.123x | 14 | 1/13/0 | `` |
| No bulk | `cilium/agent` | `ok` | 1383 | 0.986x | 1.016x | 2 | 0/2/0 | `` |
| No bulk | `katran` | `ok` | 36 | 0.991x | 1.015x | 1 | 0/1/0 | `` |
| No bulk | `otelcol-ebpf-profiler/profiling` | `error` | 12 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T18:26:18.8...` |
| No bulk | `tetragon/observer` | `error` | 56 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No bulk | `tracee/monitor` | `ok` | 1406 | 0.982x | 1.036x | 60 | 23/37/0 | `` |
| No bulk/pref | `bcc/set` | `ok` | 0 | 0.933x | 0.966x | 14 | 9/5/0 | `` |
| No bulk/pref | `cilium/agent` | `ok` | 768 | 1.007x | 0.999x | 2 | 1/1/0 | `` |
| No bulk/pref | `katran` | `ok` | 30 | 1.009x | 1.001x | 1 | 0/1/0 | `` |
| No bulk/pref | `otelcol-ebpf-profiler/profiling` | `error` | 0 | n/a | n/a | 0 | 0/0/0 | `native app exited before BPF programs were tracked by shim stderr tail: 2026-06-05T19:06:21.7...` |
| No bulk/pref | `tetragon/observer` | `error` | 7 | n/a | n/a | 0 | 0/0/0 | `Tetragon exited before BPF programs were tracked by shim stdout tail: level=info msg="Startin...` |
| No bulk/pref | `tracee/monitor` | `ok` | 16 | 0.985x | 1.019x | 60 | 17/43/0 | `` |

