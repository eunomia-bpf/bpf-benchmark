# AWS x86 Corpus Per-Program Detail - 2026-04-28

Source result: `corpus/results/aws_x86_corpus_20260428_184822_640612/details/result.json`  
Reference note: `docs/tmp/aws-x86-corpus-e2e-20260428.md`

Ratio semantics: `ratio = post_rejit_avg_ns_per_run / baseline_avg_ns_per_run`; lower than `1.0` is faster after ReJIT. The corpus summary includes only programs with `run_cnt_delta > 0` in both baseline and post-ReJIT, which is the mathematical requirement for `avg_ns_per_run`.

## Executive Summary

- Overall per-program geomean: `0.982010648819401` across `148` programs.
- Wins/losses: `61` wins and `87` losses, no ties.
- Result status is `error` because `tracee/monitor` recorded `prog 714: BPF_PROG_REJIT: Invalid argument (os error 22)`.
- Exact ReJIT app-level counts: `127` applied / `519` requested programs; `392` requested programs had no accepted ReJIT change.
- `result.json` is compacted: it preserves app-level `program_counts` and `enabled_passes`, but not per-program `passes[]` or per-pass site totals. Exact pass attribution is therefore not recoverable from this artifact.

## What Moved The Geomean

Losses outnumber wins, but geomean is log-based. The `61` wins have geomean `0.743230` and contribute `-18.101747` log-ratio, while the `87` losses have geomean `1.193852` and contribute `15.415084`. Net log-ratio is `-2.686663`; divided by `148` programs this is `-0.018153`, and `exp()` gives `0.982010648819401`.

The largest single win is `bcc/tcplife/sock__inet_sock` at ratio `0.060344`, but it has no visible size change and the run counts changed from `36` to `1661`. Treat that row as a measurement/workload outlier rather than direct pass evidence. The next largest wins are Tracee programs with visible size changes. The largest regression is `tracee/monitor/tracepoint__sch` at ratio `7.449544`.

## Applied vs Not Applied

The exact artifact data is app-level, not per-program: apps with any accepted ReJIT change contribute `90` comparable programs with geomean `0.983554`; apps with zero accepted ReJIT changes contribute `58` comparable programs with geomean `0.979621`. This is an app bucket, not a per-program causal split.

For a per-program proxy, I compared `bytes_jited` or `bytes_xlated` before/after and ignored BPF name truncation. This identifies size-changing transformations only; same-size accepted rewrites would be counted as unchanged. Under that proxy, `71` comparable programs changed size with geomean `0.971195`, while `77` did not change size with geomean `0.992091`.

## Pass Information In The Artifact

Enabled passes were: `wide_mem, rotate, cond_select, extract, endian_fusion, map_inline, const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory`.

`result.json` does not retain per-program pass records or `sites_applied` by pass. The only supported conclusion is that accepted changes occurred in these app buckets:

| app | status | requested | applied | not_applied | error |
| --- | --- | ---: | ---: | ---: | --- |
| bcc/capable | ok | 1 | 1 | 0 |  |
| bcc/bindsnoop | ok | 3 | 2 | 1 |  |
| bcc/biosnoop | ok | 3 | 1 | 2 |  |
| bcc/runqlat | ok | 3 | 1 | 2 |  |
| tracee/monitor | error | 158 | 122 | 36 | prog 714: BPF_PROG_REJIT: Invalid argument (os error 22) |

This means the run shows accepted ReJIT changes, but not which of `wide_mem`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`, or `bulk_memory` produced those changes. To answer exact per-pass effectiveness, the next run needs to preserve `rejit_result.per_program.*.passes` or at least per-pass site totals before artifact compaction.

## App Aggregation

`geomean programs` is the number of per-program rows included in the corpus geomean for that app.

| app | status | geomean programs | sub-geomean | wins | losses | requested | applied | not_applied | comparable size-changed | size-changed geomean | unchanged geomean |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| bcc/capable | ok | 1 | 1.272128 | 0 | 1 | 1 | 1 | 0 | 1 | 1.272128 |  |
| bcc/execsnoop | ok | 2 | 0.994949 | 1 | 1 | 2 | 0 | 2 | 0 |  | 0.994949 |
| bcc/bindsnoop | ok | 2 | 1.062832 | 1 | 1 | 3 | 2 | 1 | 1 | 0.871298 | 1.296471 |
| bcc/biosnoop | ok | 3 | 1.036937 | 1 | 2 | 3 | 1 | 2 | 1 | 1.067352 | 1.022055 |
| bcc/vfsstat | ok | 3 | 1.043952 | 1 | 2 | 5 | 0 | 5 | 0 |  | 1.043952 |
| bcc/opensnoop | ok | 3 | 1.068441 | 1 | 2 | 3 | 0 | 3 | 0 |  | 1.068441 |
| bcc/syscount | ok | 2 | 0.961560 | 1 | 1 | 2 | 0 | 2 | 0 |  | 0.961560 |
| bcc/tcpconnect | ok | 2 | 0.924676 | 1 | 1 | 3 | 0 | 3 | 0 |  | 0.924676 |
| bcc/tcplife | ok | 1 | 0.060344 | 1 | 0 | 1 | 0 | 1 | 0 |  | 0.060344 |
| bcc/runqlat | ok | 3 | 1.082627 | 0 | 3 | 3 | 1 | 2 | 1 | 1.049549 | 1.099555 |
| calico/felix | ok | 0 |  | 0 | 0 | 6 | 0 | 6 | 0 |  |  |
| otelcol-ebpf-profiler/profiling | ok | 2 | 1.070360 | 1 | 1 | 13 | 0 | 13 | 0 |  | 1.070360 |
| cilium/agent | ok | 0 |  | 0 | 0 | 2 | 0 | 2 | 0 |  |  |
| tetragon/observer | ok | 33 | 1.042236 | 11 | 22 | 301 | 0 | 301 | 0 |  | 1.042236 |
| katran | ok | 1 | 0.903886 | 1 | 0 | 3 | 0 | 3 | 0 |  | 0.903886 |
| tracee/monitor | error | 81 | 0.973181 | 35 | 46 | 158 | 122 | 36 | 67 | 0.966374 | 1.006425 |
| bpftrace/capable | ok | 1 | 1.363142 | 0 | 1 | 1 | 0 | 1 | 0 |  | 1.363142 |
| bpftrace/biosnoop | ok | 2 | 0.917631 | 2 | 0 | 2 | 0 | 2 | 0 |  | 0.917631 |
| bpftrace/vfsstat | ok | 2 | 0.983822 | 1 | 1 | 2 | 0 | 2 | 0 |  | 0.983822 |
| bpftrace/runqlat | ok | 3 | 1.011216 | 1 | 2 | 3 | 0 | 3 | 0 |  | 1.011216 |
| bpftrace/tcplife | ok | 1 | 0.992218 | 1 | 0 | 1 | 0 | 1 | 0 |  | 0.992218 |
| bpftrace/tcpretrans | ok | 0 |  | 0 | 0 | 1 | 0 | 1 | 0 |  |  |

## Top Improvements

| rank | app | program | type | ratio | avg drop | speedup | baseline ns/run | post ns/run | runs base/post | size-changed |
| ---: | --- | --- | --- | ---: | ---: | ---: | ---: | ---: | --- | ---: |
| 1 | bcc/tcplife | sock__inet_sock | tracepoint | 0.060344 | 93.97% | 16.57x | 1458.250 | 87.997 | 36/1661 | no |
| 2 | tracee/monitor | trace_ret_inoti | kprobe | 0.062500 | 93.75% | 16.00x | 4120.000 | 257.500 | 2/2 | yes |
| 3 | tracee/monitor | trace_ret_file_ | kprobe | 0.074804 | 92.52% | 13.37x | 1717.496 | 128.475 | 530/419 | yes |
| 4 | tracee/monitor | trace_ret_vfs_w | kprobe | 0.101702 | 89.83% | 9.83x | 2104.827 | 214.064 | 76627/73347 | yes |
| 5 | tracee/monitor | trace_ret_do_mm | kprobe | 0.124410 | 87.56% | 8.04x | 2707.063 | 336.785 | 2232/2780 | yes |
| 6 | tracee/monitor | trace_ret_vfs_r | kprobe | 0.478000 | 52.20% | 2.09x | 2825.653 | 1350.663 | 22109/10742 | yes |
| 7 | tracee/monitor | trace_security_ | kprobe | 0.562412 | 43.76% | 1.78x | 713.000 | 401.000 | 1/1 | no |
| 8 | tracee/monitor | trace_dup | kprobe | 0.635480 | 36.45% | 1.57x | 1203.500 | 764.800 | 2/20 | yes |
| 9 | tracee/monitor | trace_exec_binp | kprobe | 0.713797 | 28.62% | 1.40x | 216.081 | 154.238 | 37/42 | yes |
| 10 | tracee/monitor | tracepoint__cgr | raw_tracepoint | 0.795869 | 20.41% | 1.26x | 2905.000 | 2312.000 | 1/1 | yes |
| 11 | tracee/monitor | trace_security_ | kprobe | 0.838924 | 16.11% | 1.19x | 3820.350 | 3204.985 | 217/259 | yes |
| 12 | tracee/monitor | trace_file_upda | kprobe | 0.843673 | 15.63% | 1.19x | 468.830 | 395.539 | 530/419 | yes |
| 13 | bcc/tcpconnect | trace_connect_v | kprobe | 0.848020 | 15.20% | 1.18x | 10029.250 | 8505.000 | 8/1 | no |
| 14 | bcc/syscount | raw_syscalls__s | tracepoint | 0.859596 | 14.04% | 1.16x | 181.744 | 156.226 | 599642/569375 | no |
| 15 | tracee/monitor | tracepoint__cgr | raw_tracepoint | 0.869019 | 13.10% | 1.15x | 5058.000 | 4395.500 | 1/2 | yes |
| 16 | tetragon/observer | generic_retkprobe_event | kprobe | 0.870465 | 12.95% | 1.15x | 3479.750 | 3029.000 | 4/3 | no |
| 17 | bcc/bindsnoop | bindsnoop_v4_re | kprobe | 0.871298 | 12.87% | 1.15x | 12393.000 | 10798.000 | 2/2 | yes |
| 18 | bpftrace/biosnoop | block_io_done | tracepoint | 0.881708 | 11.83% | 1.13x | 383.148 | 337.824 | 17138/18289 | no |
| 19 | tracee/monitor | trace_mmap_aler | kprobe | 0.889818 | 11.02% | 1.12x | 715.581 | 636.737 | 2947/2954 | yes |
| 20 | bpftrace/vfsstat | 1 | perf_event | 0.897208 | 10.28% | 1.11x | 1436.250 | 1288.615 | 12/13 | no |

## Top Regressions

| rank | app | program | type | ratio | avg increase | baseline ns/run | post ns/run | runs base/post | size-changed |
| ---: | --- | --- | --- | ---: | ---: | ---: | ---: | --- | ---: |
| 1 | tracee/monitor | tracepoint__sch | raw_tracepoint | 7.449544 | 644.95% | 6437.603 | 47957.201 | 302/293 | yes |
| 2 | tracee/monitor | trace_security_ | kprobe | 2.989423 | 198.94% | 714.836 | 2136.947 | 1408/282 | yes |
| 3 | tracee/monitor | trace_security_ | kprobe | 2.964321 | 196.43% | 903.371 | 2677.882 | 1205/363 | yes |
| 4 | tracee/monitor | tracepoint__sch | raw_tracepoint | 2.616507 | 161.65% | 8086.132 | 21157.420 | 302/293 | yes |
| 5 | tracee/monitor | trace_security_ | kprobe | 2.463336 | 146.33% | 1317.761 | 3246.089 | 712/291 | yes |
| 6 | tracee/monitor | trace_ret_dup3 | kprobe | 1.639167 | 63.92% | 3015.861 | 4943.500 | 36/2 | yes |
| 7 | tracee/monitor | cgroup_bpf_run_ | kprobe | 1.616914 | 61.69% | 1781.028 | 2879.770 | 892/539 | yes |
| 8 | tracee/monitor | trace_dup3 | kprobe | 1.610469 | 61.05% | 638.944 | 1029.000 | 36/2 | yes |
| 9 | tracee/monitor | trace_ret_dup2 | kprobe | 1.446453 | 44.65% | 3091.438 | 4471.620 | 89/50 | yes |
| 10 | tracee/monitor | tracepoint__tas | raw_tracepoint | 1.405354 | 40.54% | 3506.719 | 4928.180 | 331/316 | yes |
| 11 | tracee/monitor | trace_filp_clos | kprobe | 1.390201 | 39.02% | 1788.775 | 2486.757 | 2585/1328 | yes |
| 12 | bpftrace/capable | cap_capable | kprobe | 1.363142 | 36.31% | 833.677 | 1136.420 | 18747/18383 | no |
| 13 | tracee/monitor | cgroup_mkdir_si | raw_tracepoint | 1.362536 | 36.25% | 2808.000 | 3826.000 | 1/1 | yes |
| 14 | tracee/monitor | empty_kprobe | kprobe | 1.318383 | 31.84% | 119.050 | 156.953 | 40/43 | no |
| 15 | bcc/bindsnoop | bindsnoop_entry | kprobe | 1.296471 | 29.65% | 850.000 | 1102.000 | 2/2 | no |
| 16 | tracee/monitor | trace_do_trunca | kprobe | 1.288716 | 28.87% | 4319.250 | 5566.286 | 12/7 | yes |
| 17 | tracee/monitor | trace_security_ | kprobe | 1.278632 | 27.86% | 3595.444 | 4597.250 | 9/4 | yes |
| 18 | bcc/capable | cap_capable | kprobe | 1.272128 | 27.21% | 1324.602 | 1685.063 | 18359/18209 | yes |
| 19 | tetragon/observer | generic_retkprobe_event | kprobe | 1.249179 | 24.92% | 154.714 | 193.266 | 22740/22833 | no |
| 20 | tetragon/observer | generic_retkprobe_event | kprobe | 1.231777 | 23.18% | 161.856 | 199.371 | 22741/22869 | no |

## Full Per-Program Table

Sorted by ratio ascending.

| rank | app | program | type | ratio | baseline ns/run | post ns/run | runs base/post | size-changed |
| ---: | --- | --- | --- | ---: | ---: | ---: | --- | ---: |
| 1 | bcc/tcplife | sock__inet_sock | tracepoint | 0.060344 | 1458.250 | 87.997 | 36/1661 | no |
| 2 | tracee/monitor | trace_ret_inoti | kprobe | 0.062500 | 4120.000 | 257.500 | 2/2 | yes |
| 3 | tracee/monitor | trace_ret_file_ | kprobe | 0.074804 | 1717.496 | 128.475 | 530/419 | yes |
| 4 | tracee/monitor | trace_ret_vfs_w | kprobe | 0.101702 | 2104.827 | 214.064 | 76627/73347 | yes |
| 5 | tracee/monitor | trace_ret_do_mm | kprobe | 0.124410 | 2707.063 | 336.785 | 2232/2780 | yes |
| 6 | tracee/monitor | trace_ret_vfs_r | kprobe | 0.478000 | 2825.653 | 1350.663 | 22109/10742 | yes |
| 7 | tracee/monitor | trace_security_ | kprobe | 0.562412 | 713.000 | 401.000 | 1/1 | no |
| 8 | tracee/monitor | trace_dup | kprobe | 0.635480 | 1203.500 | 764.800 | 2/20 | yes |
| 9 | tracee/monitor | trace_exec_binp | kprobe | 0.713797 | 216.081 | 154.238 | 37/42 | yes |
| 10 | tracee/monitor | tracepoint__cgr | raw_tracepoint | 0.795869 | 2905.000 | 2312.000 | 1/1 | yes |
| 11 | tracee/monitor | trace_security_ | kprobe | 0.838924 | 3820.350 | 3204.985 | 217/259 | yes |
| 12 | tracee/monitor | trace_file_upda | kprobe | 0.843673 | 468.830 | 395.539 | 530/419 | yes |
| 13 | bcc/tcpconnect | trace_connect_v | kprobe | 0.848020 | 10029.250 | 8505.000 | 8/1 | no |
| 14 | bcc/syscount | raw_syscalls__s | tracepoint | 0.859596 | 181.744 | 156.226 | 599642/569375 | no |
| 15 | tracee/monitor | tracepoint__cgr | raw_tracepoint | 0.869019 | 5058.000 | 4395.500 | 1/2 | yes |
| 16 | tetragon/observer | generic_retkprobe_event | kprobe | 0.870465 | 3479.750 | 3029.000 | 4/3 | no |
| 17 | bcc/bindsnoop | bindsnoop_v4_re | kprobe | 0.871298 | 12393.000 | 10798.000 | 2/2 | yes |
| 18 | bpftrace/biosnoop | block_io_done | tracepoint | 0.881708 | 383.148 | 337.824 | 17138/18289 | no |
| 19 | tracee/monitor | trace_mmap_aler | kprobe | 0.889818 | 715.581 | 636.737 | 2947/2954 | yes |
| 20 | bpftrace/vfsstat | 1 | perf_event | 0.897208 | 1436.250 | 1288.615 | 12/13 | no |
| 21 | tracee/monitor | trace_do_mmap | kprobe | 0.897488 | 242.100 | 217.282 | 2232/2780 | no |
| 22 | tracee/monitor | trace_ret_dup | kprobe | 0.898840 | 5562.000 | 4999.350 | 2/20 | yes |
| 23 | tracee/monitor | trace_set_fs_pw | kprobe | 0.899946 | 5478.800 | 4930.625 | 10/16 | yes |
| 24 | katran | balancer_ingress | xdp | 0.903886 | 88.368 | 79.875 | 1536/1536 | no |
| 25 | tetragon/observer | generic_kprobe_ | kprobe | 0.908435 | 2724.231 | 2474.786 | 15161/21117 | no |
| 26 | tracee/monitor | trace_security_ | kprobe | 0.910661 | 5100.641 | 4644.953 | 538/537 | yes |
| 27 | tetragon/observer | generic_kprobe_ | kprobe | 0.920177 | 2966.943 | 2730.113 | 8271/11371 | no |
| 28 | bcc/vfsstat | vfs_read | tracing | 0.927404 | 73.320 | 67.997 | 41316/34622 | no |
| 29 | tracee/monitor | cgroup_skb_ingr | cgroup_skb | 0.937452 | 2917.353 | 2734.879 | 249/273 | yes |
| 30 | tracee/monitor | cgroup_skb_egre | cgroup_skb | 0.937784 | 3914.024 | 3670.507 | 252/276 | yes |
| 31 | tracee/monitor | trace_filldir64 | kprobe | 0.938596 | 50.873 | 47.749 | 4493/6641 | yes |
| 32 | tetragon/observer | generic_kprobe_ | kprobe | 0.941196 | 2897.460 | 2727.077 | 6886/9746 | no |
| 33 | bcc/opensnoop | __x64_sys_opena | tracing | 0.941647 | 2327.906 | 2192.066 | 16692/17621 | no |
| 34 | bcc/execsnoop | do_ret_sys_exec | kprobe | 0.950685 | 324.444 | 308.444 | 9/9 | no |
| 35 | bpftrace/biosnoop | block_io_start | tracepoint | 0.955017 | 1467.331 | 1401.326 | 19187/20301 | no |
| 36 | tracee/monitor | trace_do_exit | kprobe | 0.956929 | 2562.656 | 2452.280 | 302/293 | yes |
| 37 | tetragon/observer | generic_kprobe_ | kprobe | 0.957039 | 1834.784 | 1755.961 | 22740/22833 | no |
| 38 | tracee/monitor | tracepoint__cgr | raw_tracepoint | 0.959112 | 3962.000 | 3800.000 | 1/1 | yes |
| 39 | tracee/monitor | trace_security_ | kprobe | 0.961326 | 1592.961 | 1531.355 | 6346/6162 | yes |
| 40 | tracee/monitor | trace_switch_ta | kprobe | 0.961506 | 1484.066 | 1426.939 | 302/294 | yes |
| 41 | tracee/monitor | trace_security_ | kprobe | 0.964140 | 1772.564 | 1709.000 | 39/3 | yes |
| 42 | tetragon/observer | generic_retkprobe_event | kprobe | 0.965664 | 189.998 | 183.475 | 6864/5268 | no |
| 43 | tracee/monitor | trace_security_ | kprobe | 0.966685 | 182.930 | 176.836 | 111678/106642 | yes |
| 44 | tracee/monitor | trace_vfs_write | kprobe | 0.967022 | 250.706 | 242.438 | 76648/73366 | no |
| 45 | bpftrace/runqlat | sched_switch | tracepoint | 0.967457 | 435.194 | 421.031 | 96361/87273 | no |
| 46 | tracee/monitor | trace_security_ | kprobe | 0.968038 | 3511.764 | 3399.522 | 288/270 | yes |
| 47 | tracee/monitor | trace_security_ | kprobe | 0.969245 | 1694.341 | 1642.231 | 29011/27687 | yes |
| 48 | tetragon/observer | generic_kprobe_ | kprobe | 0.972327 | 6768.120 | 6580.824 | 75/51 | no |
| 49 | tracee/monitor | tracepoint__exe | raw_tracepoint | 0.975444 | 1705.108 | 1663.238 | 37/42 | yes |
| 50 | tetragon/observer | generic_kprobe_ | kprobe | 0.975937 | 7783.286 | 7596.000 | 14/8 | no |
| 51 | bcc/biosnoop | trace_req_start | kprobe | 0.979520 | 696.556 | 682.291 | 21750/19687 | no |
| 52 | tetragon/observer | generic_kprobe_ | kprobe | 0.980186 | 1703.539 | 1669.786 | 22741/22869 | no |
| 53 | tracee/monitor | trace_cap_capab | kprobe | 0.987698 | 979.970 | 967.914 | 46508/42640 | yes |
| 54 | tracee/monitor | trace_security_file_open | kprobe | 0.990363 | 3381.791 | 3349.202 | 12791/12853 | no |
| 55 | tetragon/observer | generic_kprobe_ | kprobe | 0.991537 | 1692.720 | 1678.394 | 22741/22869 | no |
| 56 | bpftrace/tcplife | tcp_set_state | kprobe | 0.992218 | 2289.053 | 2271.238 | 19/21 | no |
| 57 | otelcol-ebpf-profiler/profiling | native_tracer_e | perf_event | 0.994065 | 28460.797 | 28291.883 | 251/239 | no |
| 58 | tracee/monitor | trace_vfs_read | kprobe | 0.996179 | 265.607 | 264.592 | 34179/32335 | no |
| 59 | tetragon/observer | generic_kprobe_ | kprobe | 0.997296 | 1069.514 | 1066.622 | 43419/41723 | no |
| 60 | tracee/monitor | trace_security_mmap_file | kprobe | 0.997571 | 2807.235 | 2800.417 | 2232/2780 | no |
| 61 | tracee/monitor | tracepoint__sch | raw_tracepoint | 0.997900 | 1746.618 | 1742.949 | 213718/198424 | yes |
| 62 | tracee/monitor | trace_security_ | kprobe | 1.001320 | 1573.743 | 1575.820 | 19829/19727 | yes |
| 63 | tracee/monitor | trace_commit_cr | kprobe | 1.002811 | 1454.602 | 1458.692 | 10160/10134 | yes |
| 64 | tracee/monitor | trace_execute_f | kprobe | 1.002899 | 7840.297 | 7863.024 | 37/42 | yes |
| 65 | tetragon/observer | generic_rawtp_e | raw_tracepoint | 1.005368 | 6180.080 | 6213.255 | 75/51 | no |
| 66 | tracee/monitor | trace_security_file_mprotect | kprobe | 1.006475 | 3737.675 | 3761.876 | 425/467 | no |
| 67 | bcc/tcpconnect | trace_connect_e | kprobe | 1.008263 | 1134.625 | 1144.000 | 8/1 | no |
| 68 | tracee/monitor | trace_sock_allo | kprobe | 1.009537 | 834.706 | 842.667 | 527/423 | yes |
| 69 | bpftrace/runqlat | sched_wakeup | tracepoint | 1.013891 | 260.849 | 264.473 | 48689/42476 | no |
| 70 | tetragon/observer | generic_kprobe_ | kprobe | 1.015301 | 5745.750 | 5833.667 | 4/3 | no |
| 71 | bcc/vfsstat | vfs_open | tracing | 1.016926 | 59.839 | 60.852 | 18242/18212 | no |
| 72 | tetragon/observer | generic_kprobe_ | kprobe | 1.022549 | 11067.752 | 11317.322 | 4331/3558 | no |
| 73 | tracee/monitor | trace_arch_prct | kprobe | 1.024000 | 187.942 | 192.453 | 66331/60830 | yes |
| 74 | tracee/monitor | trace_sys_exit | raw_tracepoint | 1.024020 | 1287.921 | 1318.857 | 1390376/1198695 | yes |
| 75 | tracee/monitor | trace_sys_enter | raw_tracepoint | 1.024086 | 1285.498 | 1316.460 | 1390269/1198914 | yes |
| 76 | tetragon/observer | event_wake_up_n | kprobe | 1.024583 | 4564.490 | 4676.698 | 198/149 | no |
| 77 | bcc/runqlat | sched_wakeup | raw_tracepoint | 1.025542 | 365.813 | 375.156 | 55126/49901 | no |
| 78 | tracee/monitor | trace_security_ | kprobe | 1.027938 | 7395.459 | 7602.071 | 37/42 | yes |
| 79 | tracee/monitor | trace_fd_instal | kprobe | 1.028051 | 1153.089 | 1185.435 | 21141/20549 | yes |
| 80 | tetragon/observer | generic_kprobe_ | kprobe | 1.028162 | 4698.074 | 4830.379 | 54/29 | no |
| 81 | tracee/monitor | trace_load_elf_ | kprobe | 1.029018 | 3810.324 | 3920.893 | 74/84 | yes |
| 82 | tracee/monitor | vfs_write_magic | kprobe | 1.032501 | 117.369 | 121.183 | 76673/73371 | yes |
| 83 | tracee/monitor | trace_security_task_prctl | kprobe | 1.033066 | 1042.703 | 1077.181 | 21741/20083 | no |
| 84 | tracee/monitor | trace_ret_arch_ | kprobe | 1.037384 | 752.636 | 780.772 | 66331/60830 | yes |
| 85 | tetragon/observer | generic_kprobe_ | kprobe | 1.037658 | 2460.212 | 2552.858 | 112573/94162 | no |
| 86 | tetragon/observer | generic_kprobe_ | kprobe | 1.039384 | 2264.496 | 2353.680 | 22822/23265 | no |
| 87 | bcc/execsnoop | syscall__execve | kprobe | 1.041274 | 495.333 | 515.778 | 9/9 | no |
| 88 | tracee/monitor | lsm_file_open_t | lsm | 1.042614 | 1496.541 | 1560.314 | 12793/12853 | yes |
| 89 | tetragon/observer | generic_kprobe_ | kprobe | 1.046718 | 1952.228 | 2043.432 | 22822/23265 | no |
| 90 | tetragon/observer | generic_kprobe_ | kprobe | 1.047906 | 1892.422 | 1983.079 | 23552/19962 | no |
| 91 | tetragon/observer | generic_kprobe_ | kprobe | 1.048922 | 2303.781 | 2416.486 | 22821/23229 | no |
| 92 | tracee/monitor | tracepoint__raw | raw_tracepoint | 1.048973 | 709.130 | 743.859 | 1389863/1197857 | no |
| 93 | bcc/runqlat | sched_switch | raw_tracepoint | 1.049549 | 470.702 | 494.025 | 102073/93137 | yes |
| 94 | tracee/monitor | trace_security_ | kprobe | 1.052959 | 3227.834 | 3398.777 | 356/273 | yes |
| 95 | bpftrace/runqlat | sched_wakeup_ne | tracepoint | 1.054167 | 423.046 | 445.961 | 502/486 | no |
| 96 | tracee/monitor | tracepoint__raw | raw_tracepoint | 1.055290 | 1636.206 | 1726.672 | 1389748/1199145 | no |
| 97 | tracee/monitor | tracepoint__sch | raw_tracepoint | 1.057534 | 9867.973 | 10435.714 | 37/42 | yes |
| 98 | tracee/monitor | trace_security_ | kprobe | 1.058239 | 5394.830 | 5709.020 | 171/148 | yes |
| 99 | tetragon/observer | event_exit_acct | kprobe | 1.062286 | 1503.645 | 1597.301 | 186/146 | no |
| 100 | tetragon/observer | generic_tracepo | tracepoint | 1.062609 | 1471.253 | 1563.366 | 1723393/1558825 | no |
| 101 | bcc/biosnoop | trace_pid_start | tracepoint | 1.066438 | 588.434 | 627.528 | 21750/19687 | no |
| 102 | bcc/biosnoop | trace_req_compl | tracepoint | 1.067352 | 319.980 | 341.531 | 19801/17751 | yes |
| 103 | tracee/monitor | cgroup_rmdir_si | raw_tracepoint | 1.068651 | 2083.000 | 2226.000 | 1/1 | yes |
| 104 | tracee/monitor | trace_security_ | kprobe | 1.072275 | 3879.600 | 4160.000 | 5/11 | yes |
| 105 | bcc/syscount | raw_syscalls__s | tracepoint | 1.075619 | 206.791 | 222.429 | 599646/569362 | no |
| 106 | bpftrace/vfsstat | vfs_create | kprobe | 1.078798 | 135.177 | 145.828 | 136845/143357 | no |
| 107 | tracee/monitor | trace_dup2 | kprobe | 1.083283 | 872.090 | 944.720 | 89/50 | yes |
| 108 | tetragon/observer | event_execve | tracepoint | 1.087993 | 9078.253 | 9877.077 | 75/52 | no |
| 109 | tracee/monitor | trace_do_sigact | kprobe | 1.088363 | 3264.768 | 3553.251 | 2034/2226 | yes |
| 110 | bcc/opensnoop | __x64_sys_opena | tracing | 1.107901 | 2625.286 | 2908.556 | 14/18 | no |
| 111 | tetragon/observer | tg_kp_bprm_comm | kprobe | 1.112194 | 894.040 | 994.346 | 75/52 | no |
| 112 | tracee/monitor | trace_security_ | kprobe | 1.115921 | 4378.000 | 4885.500 | 2/2 | yes |
| 113 | tetragon/observer | generic_retkprobe_event | kprobe | 1.115924 | 130.562 | 145.697 | 112591/94186 | no |
| 114 | tetragon/observer | generic_kprobe_ | kprobe | 1.122270 | 7266.857 | 8155.375 | 14/8 | no |
| 115 | tracee/monitor | tracepoint__sch | raw_tracepoint | 1.134287 | 2292.262 | 2600.082 | 302/293 | no |
| 116 | tracee/monitor | trace_ret_sock_ | kprobe | 1.135774 | 2737.036 | 3108.655 | 527/423 | yes |
| 117 | tracee/monitor | trace_inotify_f | kprobe | 1.138462 | 715.000 | 814.000 | 2/2 | no |
| 118 | tetragon/observer | generic_kprobe_ | kprobe | 1.142658 | 8123.600 | 9282.500 | 10/4 | no |
| 119 | tracee/monitor | trace_security_ | kprobe | 1.151117 | 5949.550 | 6848.628 | 40/43 | yes |
| 120 | otelcol-ebpf-profiler/profiling | tracepoint__sch | tracepoint | 1.152510 | 10537.000 | 12144.000 | 1/2 | no |
| 121 | tetragon/observer | generic_kprobe_ | kprobe | 1.158490 | 4106.100 | 4756.876 | 1364/1093 | no |
| 122 | tetragon/observer | generic_kprobe_ | kprobe | 1.158961 | 7506.706 | 8699.977 | 6864/5268 | no |
| 123 | tracee/monitor | vfs_write_magic | kprobe | 1.161967 | 137.112 | 159.320 | 76639/73347 | no |
| 124 | bcc/opensnoop | __x64_sys_open | tracing | 1.169130 | 1860.961 | 2175.705 | 103/95 | no |
| 125 | tracee/monitor | trace_security_ | kprobe | 1.176303 | 3857.000 | 4537.000 | 1/1 | yes |
| 126 | bcc/runqlat | sched_wakeup_ne | raw_tracepoint | 1.178909 | 478.008 | 563.528 | 491/496 | no |
| 127 | bcc/vfsstat | vfs_write | tracing | 1.206377 | 55.952 | 67.499 | 89552/83860 | no |
| 128 | tetragon/observer | generic_retkprobe_event | kprobe | 1.221039 | 151.904 | 185.481 | 22741/22869 | no |
| 129 | tetragon/observer | generic_retkprobe_event | kprobe | 1.231777 | 161.856 | 199.371 | 22741/22869 | no |
| 130 | tetragon/observer | generic_retkprobe_event | kprobe | 1.249179 | 154.714 | 193.266 | 22740/22833 | no |
| 131 | bcc/capable | cap_capable | kprobe | 1.272128 | 1324.602 | 1685.063 | 18359/18209 | yes |
| 132 | tracee/monitor | trace_security_ | kprobe | 1.278632 | 3595.444 | 4597.250 | 9/4 | yes |
| 133 | tracee/monitor | trace_do_trunca | kprobe | 1.288716 | 4319.250 | 5566.286 | 12/7 | yes |
| 134 | bcc/bindsnoop | bindsnoop_entry | kprobe | 1.296471 | 850.000 | 1102.000 | 2/2 | no |
| 135 | tracee/monitor | empty_kprobe | kprobe | 1.318383 | 119.050 | 156.953 | 40/43 | no |
| 136 | tracee/monitor | cgroup_mkdir_si | raw_tracepoint | 1.362536 | 2808.000 | 3826.000 | 1/1 | yes |
| 137 | bpftrace/capable | cap_capable | kprobe | 1.363142 | 833.677 | 1136.420 | 18747/18383 | no |
| 138 | tracee/monitor | trace_filp_clos | kprobe | 1.390201 | 1788.775 | 2486.757 | 2585/1328 | yes |
| 139 | tracee/monitor | tracepoint__tas | raw_tracepoint | 1.405354 | 3506.719 | 4928.180 | 331/316 | yes |
| 140 | tracee/monitor | trace_ret_dup2 | kprobe | 1.446453 | 3091.438 | 4471.620 | 89/50 | yes |
| 141 | tracee/monitor | trace_dup3 | kprobe | 1.610469 | 638.944 | 1029.000 | 36/2 | yes |
| 142 | tracee/monitor | cgroup_bpf_run_ | kprobe | 1.616914 | 1781.028 | 2879.770 | 892/539 | yes |
| 143 | tracee/monitor | trace_ret_dup3 | kprobe | 1.639167 | 3015.861 | 4943.500 | 36/2 | yes |
| 144 | tracee/monitor | trace_security_ | kprobe | 2.463336 | 1317.761 | 3246.089 | 712/291 | yes |
| 145 | tracee/monitor | tracepoint__sch | raw_tracepoint | 2.616507 | 8086.132 | 21157.420 | 302/293 | yes |
| 146 | tracee/monitor | trace_security_ | kprobe | 2.964321 | 903.371 | 2677.882 | 1205/363 | yes |
| 147 | tracee/monitor | trace_security_ | kprobe | 2.989423 | 714.836 | 2136.947 | 1408/282 | yes |
| 148 | tracee/monitor | tracepoint__sch | raw_tracepoint | 7.449544 | 6437.603 | 47957.201 | 302/293 | yes |
