# Step 0051 — KVM corpus full default suite (all 6 apps) at `6a6304a91`

Date: 2026-09-30 UTC (make launch 05:34:48Z; in-VM suite
2026-09-30T05:39:29 → 06:13:38Z, ~34 min; VM power-down ~06:14Z)

## Scope

Canonical full-suite increment on the KVM line — the plain
`make corpus` with **zero knobs** (no `BPFREJIT_CORPUS_APPS`, no
`SAMPLES`/`WORKLOAD_DURATION`/`FUZZ_ROUNDS` overrides; all defaults
from `runner/targets/*.env`: `PLATFORM=kvm`, `ARCH=x86`, `SAMPLES=3`,
`WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`). Runs the entire
supported corpus (`corpus/config/macro_apps.yaml`: `bcc/set`,
`otelcol-ebpf-profiler/profiling`, `cilium/agent`, `tetragon/observer`,
`katran`, `tracee/monitor`) in a single suite invocation — the most
comprehensive Make-backed KVM artifact of the session, proving the
whole supported corpus end-to-end in one run.
HEAD `6a6304a91` (= `origin/master` after step 0050). x86 image cached
from the step 0041 build; host kernel `7.3.0-070300rc3-generic`.

## Result

- Run `corpus/results/x86_kvm_corpus_20260930_053929_108492/`
  `metadata.json` `status: completed`; `details/progress.json` status
  `completed`; suite `details/result.json` `status: ok`,
  `suite_name: macro_apps`, `samples: 3`.
- **All 6 apps `status: ok`, `error: ''`** — bcc/set,
  cilium/agent, katran, otelcol-ebpf-profiler/profiling,
  tetragon/observer, tracee/monitor. `rejit_result` per app:
  `mode: loadtime`, default x86 pass chain `[noop, map_inline,
  const_prop, dce, wide_mem, bounds_check_merge,
  skb_load_bytes_spec, noop, const_prop, dce, kop]`.

  Per-app BPF program counts recorded per start (baseline /
  post_rejit), and top hot programs by `run_cnt_delta` (raw two-start
  BPF counters, raw only, no ratios; in-VM ids differ between starts
  so pairs are matched by `name`; `name` strings truncated to 16
  chars; full per-program tables in the tracked
  `details/apps/*.json`):

  | app | progs B/P | hot B/P | top hot program (name, id) | baseline `run_cnt` | post_rejit `run_cnt` | `bytes_jited` B → P |
  |---|---|---|---|---|---|---|
  | bcc/set | 25 / 25 | 17 / 17 | `sys_exit` (id 50 → 892) | 553,579,529 | 553,357,976 | 406 → 262 |
  | cilium/agent | 53 / 56 | 8 / 4 | `cil_from_container` (id 1467 → 3533) | 60,278,495 | 61,297,916 | 1,093 → 952 |
  | katran | 1 / 1 | 1 / 1 | `balancer_ingress` (id 6691 → 6769) | 222,299,508 | 231,888,637 | 13,641 → 11,778 |
  | otelcol-ebpf-profiler/profiling | 13 / 13 | 2 / 2 | `native_tracer_event` (id 1095 → 1270) | 723,341 | 722,703 | 3,815 → 3,688 |
  | tetragon/observer | 287 / 287 | 33 / 35 | `generic_tracepoint` (id 3868 → 5843) | 221,794,542 | 237,073,117 | 14,942 → 11,895 |
  | tracee/monitor | 151 / 151 | 57 / 54 | `trace_sys_enter` (id 6785 → 7139) | 238,682,419 | 243,075,052 | 8,194 → 7,593 |

  - `bytes_jited` dropped after the ReJIT pass chain on every app's
    hot programs (e.g. katran 13,641 → 11,778; tetragon 14,942 →
    11,895; tracee 8,194 → 7,593); full per-program detail in the
    tracked JSON.
- Raw app-side workload counters (all six workloads, `samples: 3`;
  raw only, no ratios; katran's `errors=` is a raw pktgen counter,
  not a validity gate):
  - **bcc/set** (`stress_ng_bcc_hook_hot`): raw bogo-ops per sample,
    `syscall`/`cap`/`set`/`sockfd` — e.g. baseline s0 `514` /
    `8,673,910` / `655,412` / `6,476,303`; post_rejit s0 `514` /
    `8,484,606` / `663,286` / `6,455,066`. All `failed: 0`.
  - **cilium/agent** (`cilium_endpoint_pktgen`): raw `pkts-sofar`
    per endpoint, `errors=0` — baseline `19.74M`/`19.74M`/`20.00M`/
    `20.06M`/`20.39M`/`20.48M`; post_rejit `20.53M`/`20.53M`/
    `20.38M`/`20.39M`/`20.38M`/`20.38M`.
  - **katran** (`xdp_pktgen`): raw `pkts-sofar` + raw `errors`
    per endpoint — baseline s0 `22.69M`/`1.95M`/`24.66M`/`24.73M`
    (errors `27.08M`/`2.17M`/`29.27M`/`29.01M`); post_rejit s0
    `20.56M`/`25.91M`/`25.09M`/`5.39M` (errors `19.43M`/`23.87M`/
    `23.91M`/`4.40M`).
  - **otelcol-ebpf-profiler/profiling** (`otel_mixed_workload`):
    raw per-language `int_loop ops=` (python3/ruby/nodejs/perl/php,
    2 workers each) + raw stress-ng cpu bogo-ops — e.g. baseline s0
    php `529,307,125`/`529,624,103`, cpu `39,926`; post_rejit s0
    php `563,051,693`/`657,638,370`, cpu `39,142`.
  - **tetragon/observer** (`stress_ng_tetragon_policy_hot`): raw
    bogo-ops per stressor (eventfd/mmap/udp/sock/sockfd/sockpair) —
    e.g. baseline s0 eventfd `1,898,361`, udp `3,227,082`, sockfd
    `3,491,941`; post_rejit s0 eventfd `2,642,769`, udp `5,286,053`,
    sockfd `6,483,858`. All `failed: 0`.
  - **tracee/monitor** (`stress_ng_tracee_syscall_hot`): raw
    bogo-ops per stressor (cap/set/sigfd/eventfd/kill/futex/prctl) —
    e.g. baseline s0 cap `1,777,597`, futex `4,537,498`; post_rejit
    s0 cap `1,823,916`, futex `4,590,194`. All `failed: 0`.
  - No ratio, geomean, or win/loss tally is computed here — any
    cross-start comparison is analysis per `docs/evaluation.md` §5.

## Evidence pointers

- `make-corpus.log` (this dir): retained 390-line host log (clean power-down).
- `run-marker.txt` (this dir).
- `corpus/results/x86_kvm_corpus_20260930_053929_108492/` run dir:
  tracked `metadata.json`, `details/result.json`, `details/progress.json`,
  all six `details/apps/*.json`, all six `details/loadtime-reports/*.jsonl`;
  `details/shim-logs/` and `details/loadtime-plans/` stay ignored.

## Caveats

- In-VM BPF program ids differ between the two starts (e.g. katran
  6691 → 6769; tetragon 3868 → 5843), so hot progs are matched by
  `name`, not id. Program `name` strings are stored truncated to 16
  chars (kernel convention); generic names collide across distinct
  programs, distinguished by id in the full JSON.
- cilium/agent recorded 56 progs post_rejit vs. 53 baseline (a few
  extra progs appeared in the second start) — recorded as-is, not
  excluded.
- `SAMPLES=3` is the default (a full variance sample).
- Raw two-start counters + raw workload counters only; no ratio /
  geomean / rollup in the framework — analysis per `docs/evaluation.md`
  §5.
- Dirty `llvm_mapinline.hpp` (+3) in tree; image inherited from the
  step 0041 build. Paper-B speculative evidence stays blocked.
- This is the canonical **full-default** suite: the whole supported
  6-app corpus in one invocation, zero knobs — the most comprehensive
  single Make-backed KVM artifact of the session.

## Open

- `PLATFORM=aws ARCH=arm64` corpus within caps — **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host. Genuine
  external blocker; resume when credentials land.
