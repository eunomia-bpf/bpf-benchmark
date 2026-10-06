# Step 0056 — KVM `make corpus` variance re-run (zero knobs) at `674d32748`

Date: 2026-09-30 UTC (make launch 08:37:24Z, make PID 721250; in-VM
suite 08:42:30Z → 09:16:38Z, ~34 min; VM power-down at in-VM ~2090 s)

## Scope

Plain `make corpus` (default `PLATFORM=kvm`, `ARCH=x86`, zero knobs;
`SAMPLES=3`, `WORKLOAD_DURATION=30` defaults). **Purpose: paired
variance data point against the canonical step-0051 full-corpus run
(`42e1c4e37`).** The paper's primary measurement is workload throughput;
`rejit/docs/evaluation.md` §5 analysis (ratios, `min_runs ≥ 100` filter,
geomean, tail-call accounting) needs ≥2 raw runs of the primary metric.
This is the second whole-corpus run on the same host kernel
(`7.3.0-070300rc3-generic`).

## Result

- Run token `46529a8b`; result dir
  `corpus/results/x86_kvm_corpus_20260930_084230_227783/`.
- Top `metadata.json`: `status: completed`, `run_type:
  x86_kvm_corpus`, `samples: 3`, `workload_seconds: 30.0`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce, kinsn]`
  (same pass list as step 0051).
- `details/progress.json`: `status: completed`, `completed_at
  2026-09-30T09:16:38Z`.
- **All 6 apps `status: ok`, 0 `error`**:
  - `bcc/set` — 25 BPF entries/start (25 hot with `run_cnt_delta`);
    sum `run_cnt_delta` 1,264,807,680 (baseline) vs 1,261,697,834
    (post_rejit); sum `run_time_ns_delta` 131,799,998,389 vs
    130,103,656,097.
  - `cilium/agent` — 60 BPF entries/start; sum `run_cnt_delta`
    119,792,066 vs 120,840,657; sum `run_time_ns_delta`
    77,865,616,730 vs 76,816,178,280.
  - `katran` — 1 hot BPF program (`xdp`); `run_cnt_delta`
    219,133,665 vs 233,004,895; `run_time_ns_delta` 37,265,401,864 vs
    34,422,786,269.
  - `otelcol-ebpf-profiler/profiling` — 13 BPF entries/start; sum
    `run_cnt_delta` 723,235 vs 723,477; sum `run_time_ns_delta`
    3,233,580,399 vs 3,468,636,568.
  - `tetragon/observer` — 287 BPF entries/start; sum `run_cnt_delta`
    485,755,566 vs 552,086,889; sum `run_time_ns_delta`
    352,597,966,080 vs 320,901,728,419.
  - `tracee/monitor` — 151 BPF entries/start; sum `run_cnt_delta`
    1,164,270,875 vs 1,163,045,466; sum `run_time_ns_delta`
    418,519,538,380 vs 418,432,584,943.
- Raw workload counters (per-sample, 3 samples/segment; raw values only):
  - `bcc/set` (`stress_ng_bcc_hook_hot`, stress-ng `--metrics-brief`):
    baseline cap ≈ 8.63M / 8.67M / 8.62M, sockfd ≈ 6.48M / 6.50M /
    6.48M; post_rejit cap ≈ 8.51M / 8.40M / 8.49M, sockfd ≈ 6.50M /
    6.54M / 6.53M (syscall=514, set ≈ 652k both starts).
  - `cilium/agent` (`cilium_endpoint_pktgen`, kernel pktgen):
    pkts-sofar ≈ 20.12M / 19.77M / 20.07M (baseline) vs 20.21M /
    19.94M / 20.17M (post_rejit); errors=0 all samples.
  - `katran` (`xdp_pktgen`, kernel pktgen): pkts-sofar ≈ 23.96M /
    24.20M / 24.15M (baseline) vs 26.44M / 25.66M / 16.10M (post_rejit);
    errors ≈ 26.42M / 27.54M / 26.84M vs 26.30M / 24.91M / 15.24M
    (raw values as reported by the workload; recorded as-is, not
    gated on).
  - `otelcol-ebpf-profiler/profiling` (`otel_mixed_workload`,
    `int_loop ops=`): 493,393,552 / 543,141,293 / 639,538,573
    (baseline) vs 548,755,969 / 521,043,509 / 603,085,450
    (post_rejit).
  - `tetragon/observer` (`stress_ng_tetragon_policy_hot`): baseline
    udp ≈ 3.18M / 3.18M / 3.14M, sockfd ≈ 3.52M / 3.31M / 3.46M;
    post_rejit udp ≈ 4.71M / 4.07M / 3.17M, sockfd ≈ 6.74M / 4.76M /
    3.53M.
  - `tracee/monitor` (`stress_ng_tracee_syscall_hot`): cap ≈ 1.85M /
    1.85M / 1.85M (baseline) vs 1.89M / 1.79M / 1.83M (post_rejit);
    futex ≈ 4.42M / 4.64M / 4.45M vs 4.53M / 4.46M / 4.50M.
- Host log: **0 error markers** (no `make ***`, `Error N`, `FAILED`,
  `fatal`, `Aborted`, `Terminated`, `signal 15`); clean VM power-down
  (`reboot: Power down`).

## Evidence pointers

- `make-corpus.log` (this dir): retained host log (clean power-down).
- `run-marker.txt` (this dir).
- `corpus/results/x86_kvm_corpus_20260930_084230_227783/` (15 tracked
  files: top `metadata.json`, `details/progress.json`,
  `details/result.json`, 6× `details/apps/*.json`, 6×
  `details/loadtime-reports/*.jsonl`; `git check-ignore` confirms
  `details/shim-logs/` + `details/loadtime-plans/` stay gitignored via
  `corpus/.gitignore` `results/*/details/*` + negation rules).

## Caveats

- No ratio / geomean / rollup computed here (raw two-start BPF
  counters + raw per-sample workload counters only; cross-run
  comparison — including the step-0051 ↔ step-0056 paired delta — is
  analysis per `rejit/docs/evaluation.md` §5).
- katran's pktgen workload reports a large `errors` counter on both
  starts (raw, ~25–27M); recorded as-is, not treated as a validity
  gate (contention/noise caveat, per working agreement).
- `PLATFORM=aws ARCH=arm64` within caps — **blocked on credentials**:
  no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.
