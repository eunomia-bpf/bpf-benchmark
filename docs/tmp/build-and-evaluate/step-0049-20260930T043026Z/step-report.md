# Step 0049 — KVM corpus `tetragon/observer` at `7c01f1340`

Date: 2026-09-30 UTC (make launch 04:30:26Z; in-VM suite
2026-09-30T04:35:16 → 04:40:23Z; VM power-down 04:40:32Z)

## Scope

Sixth corpus-app increment on the KVM line — the fourth *runtime-security
tracer* app (kprobe/raw_tracepoint attachments; a different app from the
already-evidenced `tracee/monitor`):
`BPFREJIT_CORPUS_APPS="tetragon/observer" make corpus` — default
`PLATFORM=kvm ARCH=x86`, default policy (`SAMPLES=3`,
`WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`), zero extra env vars.
HEAD `7c01f1340` (= `origin/master` after step 0048). x86 image cached
from the step 0041 build. Tetragon boots a full `observer` BPF graph
(287 programs — the largest program count of the session, vs. 151 for
tracee and 53 for cilium) and the `stress_ng_tetragon_policy_hot`
workload drives syscalls through a 6-stressor `stress-ng` run
(eventfd/mmap/udp/sock/sockfd/sockpair), exercising the two-start
load-time ReJIT protocol on a real, multi-attachment BPF graph.

## Result

- Run `corpus/results/x86_kvm_corpus_20260930_043516_570740/`
  `metadata.json` `status: completed` (`progress.json` status
  `completed`); suite `details/result.json` `status: ok`,
  `suite_name: macro_apps`, `samples: 3`. App `details/apps/
  tetragon__observer.json` `status: ok`, `error: ''`.
- `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]`, `selected_workload: stress_ng_tetragon_policy_hot`,
  `runner: tetragon`.
- **287 BPF programs** recorded per start (baseline and post_rejit).
  32 programs had a nonzero `run_cnt_delta` at baseline, 35 at
  post_rejit. The full 287-program table is preserved verbatim in
  `details/apps/tetragon__observer.json` (tracked into git this step).
  Top hot programs by `run_cnt_delta` (raw two-start BPF counters, raw
  only, no ratios; in-VM ids differ between starts so pairs are
  matched by `name`; `name` strings are stored truncated to 16 chars):

  | program (name, id) | start | `run_cnt_delta` | `run_time_ns_delta` | `bytes_jited` | `bytes_xlated` |
  |---|---|---|---|---|---|
  | `generic_tracepoint` (id 214) | baseline | 224,546,563 | 163,445,837,000 | 14,942 | 26,568 |
  | `generic_tracepoint` (id 2152) | post_rejit | 236,028,705 | 122,954,311,472 | 11,895 | 21,888 |
  | `generic_retkprobe` (id 142) | baseline | 40,927,410 | 1,976,902,600 | 15,275 | 26,384 |
  | `generic_retkprobe` (id 1569) | post_rejit | 50,892,497 | 2,392,676,083 | 15,275 | 26,384 |
  | `generic_kprobe_*` (id 136) | baseline | 40,927,410 | 24,859,691,600 | 1,879 | 3,304 |
  | `generic_kprobe_*` (id 1564) | post_rejit | 50,892,497 | 30,508,232,057 | 1,371 | 2,336 |

  - `bytes_jited` dropped for the hottest tracepoint and kprobe progs
    after the ReJIT pass chain (e.g. 14,942 → 11,895; 1,879 → 1,371);
    full per-program detail is in the tracked JSON.
- Raw app-side workload counters (`stress_ng_tetragon_policy_hot`,
  6-stressor `stress-ng` run, all six runs `rc=0`, `failed: 0`;
  per-stressor raw bogo-ops, raw only):

  | stressor | baseline s0 | baseline s1 | baseline s2 | post_rejit s0 | post_rejit s1 | post_rejit s2 |
  |---|---|---|---|---|---|---|
  | eventfd | 1,935,185 | 1,787,637 | 1,858,339 | 2,696,439 | 2,236,132 | 1,842,316 |
  | mmap | 805 | 796 | 769 | 963 | 898 | 816 |
  | udp | 3,306,826 | 3,193,481 | 3,230,045 | 5,543,632 | 4,992,934 | 3,388,677 |
  | sock | 9,344 | 8,770 | 9,776 | 43,216 | 21,924 | 9,688 |
  | sockfd | 3,481,844 | 3,418,449 | 3,414,332 | 7,394,907 | 4,764,568 | 3,409,259 |
  | sockpair | 1,212,312 | 1,230,939 | 1,273,602 | 2,167,331 | 1,584,325 | 1,127,976 |

  - No ratio, geomean, or win/loss tally is computed here — any
    cross-start comparison is analysis per `docs/evaluation.md` §5.

## Evidence pointers

- `make-corpus.log` (this dir): retained 449-line host log (clean power-down).
- `run-marker.txt` (this dir).
- `corpus/results/x86_kvm_corpus_20260930_043516_570740/` run dir:
  tracked `metadata.json`, `details/result.json`, `details/progress.json`,
  `details/apps/tetragon__observer.json`, `details/loadtime-reports/
  tetragon__observer.jsonl`; `details/shim-logs/` and `details/
  loadtime-plans/` stay ignored.

## Caveats

- In-VM BPF program ids differ between the two starts (e.g. 214 → 2152
  for `generic_tracepoint`), so hot progs are matched by `name`, not
  id. Program `name` strings are stored truncated to 16 chars (kernel
  convention), and the generic `generic_kprobe_*` names collide across
  distinct programs — the id distinguishes them in the full JSON.
- Single app (`tetragon/observer`); the remaining corpus app
  (`otelcol-ebpf-profiler/profiling`) is out of scope for this
  increment.
- `SAMPLES=3` is the default (a full variance sample).
- Raw two-start counters + raw workload counters only; no ratio /
  geomean / rollup in the framework — analysis per `docs/evaluation.md`
  §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from the
  step 0041 build. Paper-B speculative evidence stays blocked.

## Open

- `PLATFORM=aws ARCH=arm64` corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host. Genuine
  external blocker; resume when credentials land.
