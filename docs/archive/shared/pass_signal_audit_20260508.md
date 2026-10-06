# Pass Signal Audit 2026-05-08

Scope: completed `corpus/results/x86_kvm_corpus_2026050[78]_*` runs. Metric: Method B per-program geomean with `min_runs >= 100`. Wins/losses/ties are counted on retained programs. Split app payloads under `details/apps/*.json` were stitched in memory and analyzed with the same functions used by `analysis/corpus_analyze.py`.

Short answer: no standalone pass has a paper-ready measurable improvement in the completed runs. There are two app-level low marks worth follow-up: `map_inline` on otel in the earlier 7-app run, and the combined kinsn Run 4 on otel. Neither is sufficient as a standalone pass claim without another completed ablation/reproduction.

Signal rule used below: for each app, Q1 and P1 define the noise interval `[B_min, B_max]`. The suite noise amplitude is `abs(Q1_B - P1_B) = 0.0431`. A speed signal must have `applied > 0` and `B < B_min - 0.0431`. A regression suspect must have `applied > 0` and `B > max(1.0, B_max) + 0.0431`.

## 1. Completed Runs And Noise Floor

### Completed run metadata

| label | dir | started_at | status | passes | samples | workload_s | app payloads | skip_rejit | retained | Method B | W/L/T |
|---|---|---:|---|---|---:|---:|---:|---|---:|---:|---:|
|  | `x86_kvm_corpus_20260507_002840_650501` | 2026-05-07T00:28:40.650501+00:00 | completed | wide_mem, rotate, cond_select, extract, endian_fusion, noop, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch | 1 | 3.0 | 1 | n/a | 28 | 1.0495 | 16/12/0 |
|  | `x86_kvm_corpus_20260507_012156_877431` | 2026-05-07T01:21:56.877431+00:00 | completed | wide_mem, rotate, cond_select, extract, endian_fusion, noop, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch | 1 | 3.0 | 1 | n/a | 28 | 1.0218 | 12/16/0 |
|  | `x86_kvm_corpus_20260507_013928_648047` | 2026-05-07T01:39:28.648047+00:00 | completed | wide_mem, rotate, cond_select, extract, endian_fusion, noop, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch | 1 | 3.0 | 1 | n/a | 28 | 0.9341 | 24/4/0 |
|  | `x86_kvm_corpus_20260507_020655_713061` | 2026-05-07T02:06:55.713061+00:00 | completed | wide_mem, rotate, cond_select, extract, endian_fusion, noop, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch | 1 | 3.0 | 1 | n/a | 28 | 1.1020 | 5/23/0 |
|  | `x86_kvm_corpus_20260507_021534_990130` | 2026-05-07T02:15:34.990130+00:00 | completed | wide_mem, rotate, cond_select, extract, endian_fusion, noop, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch | 1 | 3.0 | 1 | n/a | 28 | 0.9340 | 21/7/0 |
|  | `x86_kvm_corpus_20260507_031724_078597` | 2026-05-07T03:17:24.078597+00:00 | completed | noop, map_inline | 1 | 3.0 | 1 | n/a | 6 | 0.9500 | 6/0/0 |
|  | `x86_kvm_corpus_20260507_033246_154754` | 2026-05-07T03:32:46.154754+00:00 | completed | wide_mem, rotate, cond_select, extract, endian_fusion, noop, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch | 1 | 3.0 | 1 | n/a | 1 | 1.0244 | 0/1/0 |
|  | `x86_kvm_corpus_20260507_033859_357762` | 2026-05-07T03:38:59.357762+00:00 | completed | noop, map_inline | 1 | 3.0 | 1 | n/a | 28 | 0.9817 | 15/13/0 |
|  | `x86_kvm_corpus_20260507_034154_267803` | 2026-05-07T03:41:54.267803+00:00 | completed | wide_mem, rotate, cond_select, extract, endian_fusion, noop, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory, prefetch | 1 | 3.0 | 1 | n/a | 1 | 1.1313 | 0/1/0 |
|  | `x86_kvm_corpus_20260507_034456_818538` | 2026-05-07T03:44:56.818538+00:00 | completed | noop, map_inline, branch_flip | 1 | 3.0 | 1 | n/a | 28 | 1.0148 | 13/15/0 |
|  | `x86_kvm_corpus_20260507_041416_267486` | 2026-05-07T04:14:16.267486+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 20 | 0.9912 | 12/8/0 |
|  | `x86_kvm_corpus_20260507_041921_907527` | 2026-05-07T04:19:21.907527+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 1.0938 | 0/1/0 |
|  | `x86_kvm_corpus_20260507_042606_783135` | 2026-05-07T04:26:06.783135+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 1.0961 | 0/1/0 |
|  | `x86_kvm_corpus_20260507_043115_146422` | 2026-05-07T04:31:15.146422+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 0.9065 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_043713_781335` | 2026-05-07T04:37:13.781335+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 1.0030 | 0/1/0 |
|  | `x86_kvm_corpus_20260507_044440_988755` | 2026-05-07T04:44:40.988755+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 0.9908 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_045442_372726` | 2026-05-07T04:54:42.372726+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 1.0049 | 0/1/0 |
|  | `x86_kvm_corpus_20260507_050113_313282` | 2026-05-07T05:01:13.313282+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 0.9900 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_053628_910782` | 2026-05-07T05:36:28.910782+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 0.9881 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_054015_850632` | 2026-05-07T05:40:15.850632+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 74 | 1.0269 | 26/48/0 |
|  | `x86_kvm_corpus_20260507_054425_678012` | 2026-05-07T05:44:25.678012+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 28 | 1.0265 | 7/21/0 |
|  | `x86_kvm_corpus_20260507_054923_997897` | 2026-05-07T05:49:23.997897+00:00 | completed | noop | 1 | 3.0 | 1 | n/a | 1 | 0.9843 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_063334_788203` | 2026-05-07T06:33:34.788203+00:00 | completed | noop, map_inline | 3 | 3.0 | 1 | n/a | 30 | 1.0560 | 9/21/0 |
|  | `x86_kvm_corpus_20260507_063703_046039` | 2026-05-07T06:37:03.046039+00:00 | completed | noop, map_inline | 3 | 3.0 | 1 | n/a | 1 | 0.9587 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_063954_002537` | 2026-05-07T06:39:54.002537+00:00 | completed | noop, map_inline | 3 | 3.0 | 1 | n/a | 80 | 0.9633 | 54/26/0 |
|  | `x86_kvm_corpus_20260507_071728_879774` | 2026-05-07T07:17:28.879774+00:00 | completed | noop, map_inline | 3 | 30.0 | 1 | n/a | 6 | 1.0041 | 3/3/0 |
| earlier map_inline 7-app | `x86_kvm_corpus_20260507_072543_601953` | 2026-05-07T07:25:43.601953+00:00 | completed | noop, map_inline | 3 | 30.0 | 7 | n/a | 148 | 0.8965 | 54/94/0 |
| earlier kinsn+prefetch 7-app | `x86_kvm_corpus_20260507_081532_470100` | 2026-05-07T08:15:32.470100+00:00 | completed | rotate, cond_select, extract, endian_fusion, bulk_memory, prefetch, skb_load_bytes_spec, wide_mem | 3 | 30.0 | 7 | n/a | 147 | 0.8897 | 61/86/0 |
| Q1 noop ReJIT floor | `x86_kvm_corpus_20260507_190554_205137` | 2026-05-07T19:05:54.205137+00:00 | completed | noop | 3 | 30.0 | 7 | n/a | 147 | 0.9019 | 73/74/0 |
| Run 3 noop+map_inline | `x86_kvm_corpus_20260507_195045_528717` | 2026-05-07T19:50:45.528717+00:00 | completed | noop, map_inline | 3 | 30.0 | 3 | n/a | 88 | 0.8258 | 50/38/0 |
| Run 4 kinsn ablation | `x86_kvm_corpus_20260507_200821_664435` | 2026-05-07T20:08:21.664435+00:00 | completed | rotate, cond_select, extract, endian_fusion, bulk_memory, skb_load_bytes_spec, wide_mem | 3 | 30.0 | 7 | n/a | 148 | 0.8953 | 66/82/0 |
|  | `x86_kvm_corpus_20260507_220015_257694` | 2026-05-07T22:00:15.257694+00:00 | completed | noop | 1 | 30.0 | 1 | false | 1 | 0.9597 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_222403_693079` | 2026-05-07T22:24:03.693079+00:00 | completed | noop | 1 | 30.0 | 1 | false | 1 | 0.9511 | 1/0/0 |
|  | `x86_kvm_corpus_20260507_223952_925103` | 2026-05-07T22:39:52.925103+00:00 | completed | noop | 1 | 30.0 | 1 | false | 1 | 1.0213 | 0/1/0 |
| Q6 prefetch otel-only | `x86_kvm_corpus_20260507_233849_941280` | 2026-05-07T23:38:49.941280+00:00 | completed | prefetch | 3 | 30.0 | 1 | false | 1 | 1.0107 | 0/1/0 |
| Q7 bulk_memory otel-only | `x86_kvm_corpus_20260507_234451_435352` | 2026-05-07T23:44:51.435352+00:00 | completed | bulk_memory | 3 | 30.0 | 1 | false | 1 | 0.9901 | 1/0/0 |
| Q8 cond_select otel-only | `x86_kvm_corpus_20260507_235044_006554` | 2026-05-07T23:50:44.006554+00:00 | completed | cond_select | 3 | 30.0 | 1 | false | 1 | 1.0212 | 0/1/0 |
| Q9 bulk_memory+prefetch otel-only | `x86_kvm_corpus_20260507_235643_087384` | 2026-05-07T23:56:43.087384+00:00 | completed | bulk_memory, prefetch | 3 | 30.0 | 1 | false | 1 | 0.9895 | 1/0/0 |
| P1 noop SKIP_REJIT floor | `x86_kvm_corpus_20260508_000244_131324` | 2026-05-08T00:02:44.131324+00:00 | completed | noop | 3 | 30.0 | 7 | true | 147 | 0.8587 | 75/72/0 |

Notes from metadata: the completed `2026-05-07T23:38:49` prefetch run has one app payload (`otelcol-ebpf-profiler/profiling`), not seven. The `2026-05-07T19:50:45` noop+map_inline run has three app payloads. The wide_mem-only run at `2026-05-07T23:18:37` is not completed and is not used for verdicts.

### Q1/P1 noise floor

| floor | dir | skip_rejit | retained | Method B | W/L/T |
|---|---|---:|---:|---:|---:|
| Q1 noop ReJIT | `x86_kvm_corpus_20260507_190554_205137` | n/a | 147 | 0.9019 | 73/74/0 |
| P1 noop SKIP_REJIT | `x86_kvm_corpus_20260508_000244_131324` | true | 147 | 0.8587 | 75/72/0 |

Suite noise amplitude: `|0.9019 - 0.8587| = 0.0431`.

| app | Q1 B | P1 B | noise interval | interval width | speed threshold | regression threshold | retained Q1/P1 |
|---|---:|---:|---:|---:|---:|---:|---:|
| bcc/set | 0.9818 | 0.9836 | [0.9818, 0.9836] | 0.0018 | 0.9387 | 1.0431 | 20/20 |
| bpftrace/set | 1.0217 | 1.0281 | [1.0217, 1.0281] | 0.0064 | 0.9786 | 1.0712 | 8/8 |
| cilium/agent | 0.9921 | 0.9783 | [0.9783, 0.9921] | 0.0138 | 0.9352 | 1.0431 | 6/6 |
| katran | 0.9811 | 0.9957 | [0.9811, 0.9957] | 0.0146 | 0.9380 | 1.0431 | 1/1 |
| otelcol-ebpf-profiler/profiling | 0.9887 | 1.1023 | [0.9887, 1.1023] | 0.1136 | 0.9456 | 1.1454 | 1/1 |
| tetragon/observer | 1.0336 | 0.9042 | [0.9042, 1.0336] | 0.1294 | 0.8611 | 1.0768 | 30/30 |
| tracee/monitor | 0.8218 | 0.7888 | [0.7888, 0.8218] | 0.0330 | 0.7457 | 1.0431 | 81/81 |

## 2. Pass x App Signal Matrix

Legend: `inside` means inside the Q1/P1 app interval. `low-near` or `high-near` is outside that interval but not beyond the suite noise amplitude. `clear-low` is the only acceleration mark. `applied=0` means the pass did not rewrite that app in the run.

| pass | run | app | applied | retained | Method B | floor | mark | conclusion |
|---|---|---|---:|---:|---:|---:|---|---|
| map_inline | Run 3 noop+map_inline | bcc/set | 0 | 0 | n/a | [0.9818, 0.9836] | no payload | no completed app payload |
| map_inline | Run 3 noop+map_inline | bpftrace/set | 0 | 0 | n/a | [1.0217, 1.0281] | no payload | no completed app payload |
| map_inline | Run 3 noop+map_inline | cilium/agent | 1454 | 6 | 0.9728 | [0.9783, 0.9921] | low-near | below floor, not beyond noise amplitude |
| map_inline | Run 3 noop+map_inline | katran | 0 | 0 | n/a | [0.9811, 0.9957] | no payload | no completed app payload |
| map_inline | Run 3 noop+map_inline | otelcol-ebpf-profiler/profiling | 1192 | 1 | 0.9790 | [0.9887, 1.1023] | low-near | below floor, not beyond noise amplitude |
| map_inline | Run 3 noop+map_inline | tetragon/observer | 0 | 0 | n/a | [0.9042, 1.0336] | no payload | no completed app payload |
| map_inline | Run 3 noop+map_inline | tracee/monitor | 5 | 81 | 0.8141 | [0.7888, 0.8218] | inside | no measurable signal |
| map_inline | earlier map_inline 7-app | bcc/set | 0 | 20 | 1.0097 | [0.9818, 0.9836] | applied=0 | no opportunity |
| map_inline | earlier map_inline 7-app | bpftrace/set | 0 | 8 | 1.0118 | [1.0217, 1.0281] | applied=0 | no opportunity |
| map_inline | earlier map_inline 7-app | cilium/agent | 1458 | 6 | 1.0344 | [0.9783, 0.9921] | high-near | above floor, not beyond noise amplitude |
| map_inline | earlier map_inline 7-app | katran | 0 | 1 | 0.9915 | [0.9811, 0.9957] | applied=0 | no opportunity |
| map_inline | earlier map_inline 7-app | otelcol-ebpf-profiler/profiling | 1192 | 2 | 0.6567 | [0.9887, 1.1023] | clear-low | speed signal at app level |
| map_inline | earlier map_inline 7-app | tetragon/observer | 0 | 30 | 1.0256 | [0.9042, 1.0336] | applied=0 | no opportunity |
| map_inline | earlier map_inline 7-app | tracee/monitor | 5 | 81 | 0.8150 | [0.7888, 0.8218] | inside | no measurable signal |
| rotate | Run 4 kinsn ablation | bcc/set | 0 | 20 | 1.0153 | [0.9818, 0.9836] | applied=0 | no opportunity |
| rotate | Run 4 kinsn ablation | bpftrace/set | 0 | 8 | 1.0205 | [1.0217, 1.0281] | applied=0 | no opportunity |
| rotate | Run 4 kinsn ablation | cilium/agent | 0 | 6 | 0.9791 | [0.9783, 0.9921] | applied=0 | no opportunity |
| rotate | Run 4 kinsn ablation | katran | 0 | 1 | 0.9821 | [0.9811, 0.9957] | applied=0 | no opportunity |
| rotate | Run 4 kinsn ablation | otelcol-ebpf-profiler/profiling | 0 | 2 | 0.6258 | [0.9887, 1.1023] | applied=0 | no opportunity |
| rotate | Run 4 kinsn ablation | tetragon/observer | 0 | 30 | 0.9920 | [0.9042, 1.0336] | applied=0 | no opportunity |
| rotate | Run 4 kinsn ablation | tracee/monitor | 0 | 81 | 0.8257 | [0.7888, 0.8218] | applied=0 | no opportunity |
| cond_select | Run 4 kinsn ablation | bcc/set | 8 | 20 | 1.0153 | [0.9818, 0.9836] | high-near | above floor, not beyond noise amplitude |
| cond_select | Run 4 kinsn ablation | bpftrace/set | 4 | 8 | 1.0205 | [1.0217, 1.0281] | low-near | below floor, not beyond noise amplitude |
| cond_select | Run 4 kinsn ablation | cilium/agent | 208 | 6 | 0.9791 | [0.9783, 0.9921] | inside | no measurable signal |
| cond_select | Run 4 kinsn ablation | katran | 7 | 1 | 0.9821 | [0.9811, 0.9957] | inside | no measurable signal |
| cond_select | Run 4 kinsn ablation | otelcol-ebpf-profiler/profiling | 45 | 2 | 0.6258 | [0.9887, 1.1023] | clear-low | speed signal at app level |
| cond_select | Run 4 kinsn ablation | tetragon/observer | 1331 | 30 | 0.9920 | [0.9042, 1.0336] | inside | no measurable signal |
| cond_select | Run 4 kinsn ablation | tracee/monitor | 391 | 81 | 0.8257 | [0.7888, 0.8218] | high-near | above floor, not beyond noise amplitude |
| extract | Run 4 kinsn ablation | bcc/set | 1 | 20 | 1.0153 | [0.9818, 0.9836] | high-near | above floor, not beyond noise amplitude |
| extract | Run 4 kinsn ablation | bpftrace/set | 0 | 8 | 1.0205 | [1.0217, 1.0281] | applied=0 | no opportunity |
| extract | Run 4 kinsn ablation | cilium/agent | 0 | 6 | 0.9791 | [0.9783, 0.9921] | applied=0 | no opportunity |
| extract | Run 4 kinsn ablation | katran | 0 | 1 | 0.9821 | [0.9811, 0.9957] | applied=0 | no opportunity |
| extract | Run 4 kinsn ablation | otelcol-ebpf-profiler/profiling | 36 | 2 | 0.6258 | [0.9887, 1.1023] | clear-low | speed signal at app level |
| extract | Run 4 kinsn ablation | tetragon/observer | 112 | 30 | 0.9920 | [0.9042, 1.0336] | inside | no measurable signal |
| extract | Run 4 kinsn ablation | tracee/monitor | 37 | 81 | 0.8257 | [0.7888, 0.8218] | high-near | above floor, not beyond noise amplitude |
| endian_fusion | Run 4 kinsn ablation | bcc/set | 1 | 20 | 1.0153 | [0.9818, 0.9836] | high-near | above floor, not beyond noise amplitude |
| endian_fusion | Run 4 kinsn ablation | bpftrace/set | 1 | 8 | 1.0205 | [1.0217, 1.0281] | low-near | below floor, not beyond noise amplitude |
| endian_fusion | Run 4 kinsn ablation | cilium/agent | 24 | 6 | 0.9791 | [0.9783, 0.9921] | inside | no measurable signal |
| endian_fusion | Run 4 kinsn ablation | katran | 6 | 1 | 0.9821 | [0.9811, 0.9957] | inside | no measurable signal |
| endian_fusion | Run 4 kinsn ablation | otelcol-ebpf-profiler/profiling | 4 | 2 | 0.6258 | [0.9887, 1.1023] | clear-low | speed signal at app level |
| endian_fusion | Run 4 kinsn ablation | tetragon/observer | 210 | 30 | 0.9920 | [0.9042, 1.0336] | inside | no measurable signal |
| endian_fusion | Run 4 kinsn ablation | tracee/monitor | 4 | 81 | 0.8257 | [0.7888, 0.8218] | high-near | above floor, not beyond noise amplitude |
| bulk_memory | Run 4 kinsn ablation | bcc/set | 0 | 20 | 1.0153 | [0.9818, 0.9836] | applied=0 | no opportunity |
| bulk_memory | Run 4 kinsn ablation | bpftrace/set | 0 | 8 | 1.0205 | [1.0217, 1.0281] | applied=0 | no opportunity |
| bulk_memory | Run 4 kinsn ablation | cilium/agent | 5 | 6 | 0.9791 | [0.9783, 0.9921] | inside | no measurable signal |
| bulk_memory | Run 4 kinsn ablation | katran | 0 | 1 | 0.9821 | [0.9811, 0.9957] | applied=0 | no opportunity |
| bulk_memory | Run 4 kinsn ablation | otelcol-ebpf-profiler/profiling | 1 | 2 | 0.6258 | [0.9887, 1.1023] | clear-low | speed signal at app level |
| bulk_memory | Run 4 kinsn ablation | tetragon/observer | 163 | 30 | 0.9920 | [0.9042, 1.0336] | inside | no measurable signal |
| bulk_memory | Run 4 kinsn ablation | tracee/monitor | 117 | 81 | 0.8257 | [0.7888, 0.8218] | high-near | above floor, not beyond noise amplitude |
| skb_load_bytes_spec | Run 4 kinsn ablation | bcc/set | 0 | 20 | 1.0153 | [0.9818, 0.9836] | applied=0 | no opportunity |
| skb_load_bytes_spec | Run 4 kinsn ablation | bpftrace/set | 0 | 8 | 1.0205 | [1.0217, 1.0281] | applied=0 | no opportunity |
| skb_load_bytes_spec | Run 4 kinsn ablation | cilium/agent | 4 | 6 | 0.9791 | [0.9783, 0.9921] | inside | no measurable signal |
| skb_load_bytes_spec | Run 4 kinsn ablation | katran | 0 | 1 | 0.9821 | [0.9811, 0.9957] | applied=0 | no opportunity |
| skb_load_bytes_spec | Run 4 kinsn ablation | otelcol-ebpf-profiler/profiling | 0 | 2 | 0.6258 | [0.9887, 1.1023] | applied=0 | no opportunity |
| skb_load_bytes_spec | Run 4 kinsn ablation | tetragon/observer | 0 | 30 | 0.9920 | [0.9042, 1.0336] | applied=0 | no opportunity |
| skb_load_bytes_spec | Run 4 kinsn ablation | tracee/monitor | 0 | 81 | 0.8257 | [0.7888, 0.8218] | applied=0 | no opportunity |
| wide_mem | Run 4 kinsn ablation | bcc/set | 0 | 20 | 1.0153 | [0.9818, 0.9836] | applied=0 | no opportunity |
| wide_mem | Run 4 kinsn ablation | bpftrace/set | 10 | 8 | 1.0205 | [1.0217, 1.0281] | low-near | below floor, not beyond noise amplitude |
| wide_mem | Run 4 kinsn ablation | cilium/agent | 0 | 6 | 0.9791 | [0.9783, 0.9921] | applied=0 | no opportunity |
| wide_mem | Run 4 kinsn ablation | katran | 4 | 1 | 0.9821 | [0.9811, 0.9957] | inside | no measurable signal |
| wide_mem | Run 4 kinsn ablation | otelcol-ebpf-profiler/profiling | 132 | 2 | 0.6258 | [0.9887, 1.1023] | clear-low | speed signal at app level |
| wide_mem | Run 4 kinsn ablation | tetragon/observer | 2826 | 30 | 0.9920 | [0.9042, 1.0336] | inside | no measurable signal |
| wide_mem | Run 4 kinsn ablation | tracee/monitor | 179 | 81 | 0.8257 | [0.7888, 0.8218] | high-near | above floor, not beyond noise amplitude |
| prefetch | Q6 prefetch otel-only | otelcol-ebpf-profiler/profiling | 415 | 1 | 1.0107 | [0.9887, 1.1023] | inside | no measurable signal |
| bulk_memory | Q7 bulk_memory otel-only | otelcol-ebpf-profiler/profiling | 1 | 1 | 0.9901 | [0.9887, 1.1023] | inside | no measurable signal |
| cond_select | Q8 cond_select otel-only | otelcol-ebpf-profiler/profiling | 45 | 1 | 1.0212 | [0.9887, 1.1023] | inside | no measurable signal |
| bulk_memory | Q9 bulk_memory+prefetch | otelcol-ebpf-profiler/profiling | 1 | 1 | 0.9895 | [0.9887, 1.1023] | inside | no measurable signal |
| prefetch | Q9 bulk_memory+prefetch | otelcol-ebpf-profiler/profiling | 415 | 1 | 0.9895 | [0.9887, 1.1023] | inside | no measurable signal |

### Applied totals across completed runs

| pass | total applied | completed runs with applied>0 | apps with applied sites |
|---|---:|---:|---|
| bounds_check_merge | 0 | 0 | none |
| branch_flip | 0 | 0 | none |
| bulk_memory | 588 | 9 | cilium/agent:11, otelcol-ebpf-profiler/profiling:4, tetragon/observer:339, tracee/monitor:234 |
| cond_select | 10428 | 10 | bcc/set:16, bpftrace/set:8, cilium/agent:453, katran:28, otelcol-ebpf-profiler/profiling:135, tetragon/observer:9006, tracee/monitor:782 |
| const_prop | 39346 | 7 | katran:320, tetragon/observer:39026 |
| dce | 2665 | 5 | tetragon/observer:2665 |
| endian_fusion | 1608 | 9 | bcc/set:2, bpftrace/set:2, cilium/agent:69, katran:24, otelcol-ebpf-profiler/profiling:8, tetragon/observer:1495, tracee/monitor:8 |
| extract | 912 | 7 | bcc/set:2, otelcol-ebpf-profiler/profiling:72, tetragon/observer:764, tracee/monitor:74 |
| map_inline | 9601 | 6 | cilium/agent:6010, otelcol-ebpf-profiler/profiling:3576, tracee/monitor:15 |
| noop | 0 | 0 | none |
| prefetch | 5740 | 8 | bcc/set:3, bpftrace/set:9, cilium/agent:473, katran:42, otelcol-ebpf-profiler/profiling:1245, tetragon/observer:2209, tracee/monitor:1759 |
| rotate | 0 | 0 | none |
| skb_load_bytes_spec | 6 | 2 | cilium/agent:6 |
| wide_mem | 20973 | 9 | bpftrace/set:20, katran:12, otelcol-ebpf-profiler/profiling:264, tetragon/observer:20319, tracee/monitor:358 |

## 3. Per-Pass Verdicts

**map_inline.** Run 3 (`2026-05-07T19:50:45`) has applied sites in cilium, otel, and tracee, but all three app results are inside the floor or only `low-near`: cilium `B=0.9728` vs speed threshold `0.9352`, otel `B=0.9790` vs `0.9456`, tracee `B=0.8141` inside `[0.7888, 0.8218]`. The earlier completed 7-app map_inline run shows otel `B=0.6567` with `applied=1192`, which is a real app-level low mark, but it is not reproduced by the named Run 3 because the low-frequency `tracepoint__sched_process_free` program falls below the retained threshold there.

**rotate.** Applied count is zero in every completed run. Current corpus has no opportunity to measure it.

**cond_select.** It applies broadly in Run 4, but no 7-app cell has a clear pass-attributable speed signal. The otel-only single-pass run has `B=1.0212`, inside the otel floor `[0.9887, 1.1023]`; no measurable standalone improvement.

**extract.** It applies in bcc, otel, tetragon, and tracee in combined runs. There is no extract-only completed 30s ablation, so the current data cannot isolate an extract signal.

**endian_fusion.** It applies in the combined kinsn run, but all non-otel app Bs are inside or near the floor. No standalone ablation exists, so no pass-specific claim.

**bulk_memory.** Run 4 otel combined has `B=0.6258`, but the bulk_memory-only otel run has `B=0.9901`, inside the otel floor. The current completed data does not show a standalone bulk_memory speedup.

**prefetch.** The completed prefetch-only run is otel-only and has `B=1.0107`, inside the otel floor. The earlier kinsn+prefetch 7-app run has no clear prefetch-attributable app result. The expected 7-app prefetch-only result is not completed on disk.

**skb_load_bytes_spec.** It applies only in cilium in completed 30s runs (`applied=4` in Run 4), and cilium is inside the floor (`B=0.9791` inside `[0.9783, 0.9921]`). No measurable signal.

**wide_mem.** It applies in bpftrace, katran, otel, tetragon, and tracee in Run 4, but there is no completed wide_mem-only run. The combined Run 4 otel low mark cannot be assigned to wide_mem from current data.

**const_prop and dce.** They apply in completed short 3s single-app runs, not in a completed 30s ablation against Q1/P1. They are not adjudicated by the current floor.

**bounds_check_merge and branch_flip.** Applied count is zero across completed runs, so current corpus has no opportunity to measure them.

**Regression suspects.** No completed 30s pass/app cell with `applied>0` crosses the regression thresholds defined in Section 1. Some cells are `high-near` but remain within the suite noise amplitude.

Program-level check for the two strongest app-level low marks:

| run | program | min_runs | ratio | self pass applied/matched |
|---|---|---:|---:|---|
| `x86_kvm_corpus_20260507_072543_601953` | tracepoint__sched_process_free | 163 | 0.4225 | map_inline 6/9 |
| `x86_kvm_corpus_20260507_072543_601953` | native_tracer_entry | 142864 | 1.0208 | map_inline 30/34 |
| `x86_kvm_corpus_20260507_200821_664435` | tracepoint__sched_process_free | 103 | 0.3872 | self applied 0 |
| `x86_kvm_corpus_20260507_200821_664435` | native_tracer_entry | 142880 | 1.0116 | cond_select 2/2; bulk_memory 1/1 |

This shows why the otel lows need follow-up: the earlier map_inline 7-app run has a self-applied low-frequency program (`min_runs=163`, ratio `0.4225`), while Run 4 combined kinsn has the strongest low ratio on `tracepoint__sched_process_free` with self applied 0 and only `min_runs=103`.

## 4. Paper Claim Candidates

No pass has a paper-ready standalone claim from the completed runs scanned here.

The closest follow-up candidate is `map_inline` on `otelcol-ebpf-profiler/profiling`: the earlier completed 7-app run reports app `B=0.6567` with `applied=1192`, below the otel speed threshold `0.9456`. It is not yet paper-ready because the named Run 3 does not retain the same low-frequency program under `min_runs >= 100`; Run 3 otel is `B=0.9790`, below the floor but not beyond the suite noise amplitude.

The combined kinsn Run 4 otel result (`B=0.6258`) is also not paper-ready as a pass claim: single-pass otel runs for `prefetch`, `bulk_memory`, and `cond_select` are all inside the otel floor, and no completed single-pass `wide_mem`, `extract`, or `endian_fusion` otel run is available.

## 5. Gap List

- Need a completed 7-app prefetch-only run. The on-disk `2026-05-07T23:38:49` completed prefetch run is otel-only; `2026-05-07T22:44:41` is status `error`.
- Need a completed wide_mem-only 7-app run; `2026-05-07T23:18:37` is not completed and appears to contain only partial data.
- Need a repeated noop+map_inline 7-app run at `SAMPLES=3`, `workload=30s` to check whether the otel `tracepoint__sched_process_free` low mark is reproducible while retained.
- Need single-pass 30s ablations for `wide_mem`, `extract`, `endian_fusion`, and `skb_load_bytes_spec` to attribute the Run 4 combined result.
- Need 30s ablations for `const_prop` and `dce` if they are still candidates; current applied data for them is only from short single-app runs.
- `rotate`, `bounds_check_merge`, and `branch_flip` need corpus workloads that produce applied sites before any performance conclusion is possible.
