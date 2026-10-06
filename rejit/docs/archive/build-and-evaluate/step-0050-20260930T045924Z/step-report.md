# Step 0050 — KVM corpus `otelcol-ebpf-profiler/profiling` at `2d0a0995a`

Date: 2026-09-30 UTC (make launch 04:59:24Z; in-VM suite
2026-09-30T05:04:05 → 05:08:42Z; VM power-down ~05:09Z)

## Scope

Seventh and final corpus-app increment on the KVM line — and the last
unevidenced app in the 6-app supported corpus.
`BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" make corpus` —
default `PLATFORM=kvm ARCH=x86`, default policy (`SAMPLES=3`,
`WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`), zero extra env vars.
HEAD `2d0a0995a` (= `origin/master` after step 0049). x86 image cached
from the step 0041 build. The OpenTelemetry eBPF profiler is a
third app category (uprobe/perf-event based CPU + memory profiling),
distinct from the already-evidenced network apps (`katran`, `bcc/set`,
`cilium/agent`) and security tracers (`tracee/monitor`,
`tetragon/observer`). Its `otel_mixed_workload` runs one 11-component
mixed-language load per sample — two int-loop workers each in
python3/ruby/nodejs/perl/php plus one `stress-ng --cpu 1` (single
cpu stressor, `--metrics-brief`) — all `rc=0`, exercising the two-start
load-time ReJIT protocol on a perf-event/uprobe BPF graph.

## Result

- Run `corpus/results/x86_kvm_corpus_20260930_050405_991692/`
  `metadata.json` `status: completed` (`progress.json` status
  `completed`); suite `details/result.json` `status: ok`,
  `suite_name: macro_apps`, `samples: 3`. App `details/apps/
  otelcol-ebpf-profiler__profiling.json` `status: ok`, `error: ''`.
- `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]`, `selected_workload: otel_mixed_workload`,
  `runner: otelcol-ebpf-profiler`.
- **13 BPF programs** recorded per start (baseline and post_rejit) —
  the smallest program count of the session. 2 hot programs
  (nonzero `run_cnt_delta`) per start; the other 11 (per-language
  `perf_unwind_*` + `perf_go_labels` + `custom__generic`) are loaded
  but zero-run during this workload (their per-language runtimes were
  not hot enough to trigger samples in the int-loop mix). Full 13-program
  table preserved verbatim in `details/apps/
  otelcol-ebpf-profiler__profiling.json` (tracked into git this step).
  Hot programs by `run_cnt_delta` (raw two-start BPF counters, raw
  only, no ratios; in-VM ids differ between starts so pairs are
  matched by `name`; `name` strings are stored truncated to 16 chars):

  | program (name, id) | start | `run_cnt_delta` | `run_time_ns_delta` | `bytes_jited` | `bytes_xlated` |
  |---|---|---|---|---|---|
  | `native_tracer_e` (id 17) | baseline | 723,698 | 3,230,143,971 | 3,815 | 5,904 |
  | `native_tracer_e` (id 192) | post_rejit | 723,217 | 3,540,538,933 | 3,688 | 5,584 |
  | `tracepoint__sch` (id 16) | baseline | 103 | 177,377 | 792 | 1,320 |
  | `tracepoint__sch` (id 179) | post_rejit | 99 | 168,671 | 698 | 1,224 |

  - Zero-run progs (both starts, `bytes_jited`/`bytes_xlated`):
    `perf_unwind_php` 14,983/24,736 → 14,451/22,520;
    `perf_unwind_pyt` 19,605/33,208 → 14,539/24,584;
    `perf_unwind_rub` 17,840/30,280 → 19,610/30,632;
    `perf_unwind_v8` 20,215/33,448 → 20,117/31,504;
    `perf_unwind_dot` 22,797/37,440 (both starts);
    `perf_go_labels` 1,572/2,504 → 1,405/2,184;
    `custom__generic` 3,679/5,712 → 3,549/5,400;
    `perf_unwind_sto` 3,650/6,144 → 3,432/5,616;
    `perf_unwind_nat` 21,868/37,024 → 20,614/33,296;
    `perf_unwind_hot` 18,424/28,080 (both starts);
    `perf_unwind_per` 18,264/29,640 → 17,686/26,752.
    Ids differ between starts for all 13 (e.g. 17 → 192); full
    per-program detail in the tracked JSON.
- Raw app-side workload counters (`otel_mixed_workload`, 3 samples ×
  11 components, all `rc=0`; per-language raw `int_loop ops=`
  counters from stderr, 2 workers per sample, raw only):

  | language (worker 0 / worker 1) | baseline s0 | baseline s1 | baseline s2 | post_rejit s0 | post_rejit s1 | post_rejit s2 |
  |---|---|---|---|---|---|---|
  | python3 | 136,732,043 / 142,841,193 | 119,095,556 / 161,105,052 | 172,740,653 / 158,097,665 | 129,962,456 / 157,633,531 | 142,851,384 / 173,417,323 | 119,438,991 / 162,475,486 |
  | ruby | 358,220,751 / 427,129,736 | 381,323,499 / 396,586,544 | 284,929,481 / 366,698,446 | 379,956,660 / 327,097,648 | 327,539,260 / 309,377,022 | 362,363,039 / 339,476,110 |
  | nodejs | 371,542,141 / 326,937,393 | 360,851,851 / 354,774,918 | 338,538,363 / 384,881,116 | 382,425,809 / 355,494,800 | 362,055,085 / 364,167,603 | 341,915,438 / 325,222,523 |
  | perl | 148,781,768 / 145,156,042 | 162,934,308 / 193,509,254 | 179,163,377 / 142,303,898 | 146,652,385 / 184,680,612 | 161,120,153 / 180,777,379 | 128,496,521 / 179,997,159 |
  | php | 674,924,279 / 626,775,779 | 572,562,162 / 504,417,485 | 572,620,368 / 571,359,687 | 631,166,935 / 507,325,964 | 599,540,707 / 525,054,643 | 696,122,711 / 610,816,875 |
  | stress-ng cpu (bogo-ops) | 40,256 | 41,006 | 43,036 | 40,477 | 38,962 | 48,372 |

  - No ratio, geomean, or win/loss tally is computed here — any
    cross-start comparison is analysis per `rejit/docs/evaluation.md` §5.

## Evidence pointers

- `make-corpus.log` (this dir): retained 439-line host log (clean power-down).
- `run-marker.txt` (this dir).
- `corpus/results/x86_kvm_corpus_20260930_050405_991692/` run dir:
  tracked `metadata.json`, `details/result.json`, `details/progress.json`,
  `details/apps/otelcol-ebpf-profiler__profiling.json`, `details/
  loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl`;
  `details/shim-logs/` and `details/loadtime-plans/` stay ignored.

## Caveats

- In-VM BPF program ids differ between the two starts (e.g. 17 → 192
  for `native_tracer_e`), so hot progs are matched by `name`, not id.
  Program `name` strings are stored truncated to 16 chars (kernel
  convention).
- 11 of the 13 progs are zero-run for this workload (per-language
  unwind stacks not sampled by the int-loop mix) — recorded as raw
  zero counters, not excluded.
- `SAMPLES=3` is the default (a full variance sample).
- Raw two-start counters + raw workload counters only; no ratio /
  geomean / rollup in the framework — analysis per `rejit/docs/evaluation.md`
  §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from the
  step 0041 build. Paper-B speculative evidence stays blocked.
- **Completes evidence for all 6 supported corpus apps**
  (`bcc/set`, `cilium/agent`, `katran`, `otelcol-ebpf-profiler/
  profiling`, `tetragon/observer`, `tracee/monitor`) on the KVM
  x86 line.

## Open

- `PLATFORM=aws ARCH=arm64` corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host. Genuine
  external blocker; resume when credentials land.
