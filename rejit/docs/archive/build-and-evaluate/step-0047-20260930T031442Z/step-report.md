# Step 0047 — KVM corpus `cilium/agent` at `9738ca00f`

Date: 2026-09-30 UTC (make launch 03:14:42Z; in-VM suite
2026-09-30T03:19:29 → 03:25:22Z; VM power-down 03:25:40Z)

## Scope

Fourth corpus-app increment on the KVM line, the heaviest app in the
evaluated corpus: `BPFREJIT_CORPUS_APPS="cilium/agent" make corpus` —
default `PLATFORM=kvm ARCH=x86`, default policy (`SAMPLES=3`,
`WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`), zero extra env vars.
HEAD `9738ca00f` (= `origin/master` after step 0046). x86 image cached
from the step 0041 build. Cilium boots a full two-endpoint LXC datapath
and runs the `cilium_endpoint_pktgen` workload (kernel `pktgen` between
two netns `bpfbench-cepa`/`bpfbench-cepb`), exercising the
two-start load-time ReJIT protocol on a real, multi-program, real-app
BPF graph.

## Result

- Run `corpus/results/x86_kvm_corpus_20260930_031929_336215/`
  `metadata.json` `status: completed` (`progress.json` status
  `completed`); suite `details/result.json` `status: ok`,
  `suite_name: macro_apps`, `samples: 3`. App `details/apps/
  cilium__agent.json` `status: ok`, `error: ''`.
- `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]` (the full default pass chain, incl. the kfunc lowering pass
  `kop`), `selected_workload: cilium_endpoint_pktgen`,
  `runner: cilium`.
- **53 BPF programs** recorded per start (baseline and post_rejit),
  keyed by in-VM program id. Hot pair is `cil_from_container` (the
  LXC endpoint forward program); the two-start raw two-start BPF
  counters (`details/result.json` / `details/apps/cilium__agent.json`,
  raw only, no ratios):

  | program (name, id) | start | `run_cnt_delta` | `run_time_ns_delta` | `bytes_jited` | `bytes_xlated` |
  |---|---|---|---|---|---|
  | `cil_from_container` (id 147) | baseline | 57,263,642 | 40,673,150,028 | 1,093 | 1,720 |
  | `cil_from_container` (id 163) | baseline | 57,273,769 | 40,567,185,435 | 1,093 | 1,720 |
  | `cil_from_container` (id 2058) | post_rejit | 60,692,033 | 38,285,958,028 | 952 | 1,416 |
  | `cil_from_container` (id 2214) | post_rejit | 60,631,769 | 37,389,204,336 | 952 | 1,416 |

  - The full 53-program table (all names/types/ids + all four counters)
    is preserved verbatim in `details/apps/cilium__agent.json` (tracked
    into git this step).
- Raw app-side workload counters (`pkts-sofar`/`errors` from the two
  `kernel_pktgen` components per sample, `rc=0`, `errors: 0` across all
  six runs; raw only):

  | sample | start | `bpfbench-cepa` | `bpfbench-cepb` |
  |---|---|---|---|
  | 0 | baseline | 19,001,255 | 19,007,707 |
  | 1 | baseline | 19,254,010 | 19,253,530 |
  | 2 | baseline | 19,008,281 | 19,012,437 |
  | 0 | post_rejit | 20,853,949 | 20,853,437 |
  | 1 | post_rejit | 20,037,542 | 19,972,009 |
  | 2 | post_rejit | 19,800,446 | 19,806,227 |

  - No ratio, geomean, or win/loss tally is computed here — any
    cross-start comparison is analysis per `rejit/docs/evaluation.md` §5.

## Evidence pointers

- `make-corpus.log` (this dir): retained 458-line host log (clean power-down).
- `run-marker.txt` (this dir).
- `corpus/results/x86_kvm_corpus_20260930_031929_336215/` run dir:
  tracked `metadata.json`, `details/result.json`, `details/progress.json`,
  `details/apps/cilium__agent.json`, `details/loadtime-reports/
  cilium__agent.jsonl`; `details/shim-logs/` and `details/loadtime-plans/`
  stay ignored (verified this run via `git check-ignore`).

## Caveats

- In-VM BPF program ids differ between the two starts (147/163 →
  2058/2214 for the same named program), so the hot pair is matched
  by `name`, not id.
- Single app (`cilium/agent`); the other corpus apps are out of scope for
  this increment.
- `SAMPLES=3` is the default (a full variance sample, unlike the
  `SAMPLES=1` sanity knobs of the micro runs).
- Raw two-start counters + raw workload counters only; no ratio /
  geomean / rollup in the framework — analysis per `rejit/docs/evaluation.md`
  §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from the step
  0041 build. Paper-B speculative evidence stays blocked.

## Open

- `PLATFORM=aws ARCH=arm64` corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host. Genuine
  external blocker; resume when credentials land.
