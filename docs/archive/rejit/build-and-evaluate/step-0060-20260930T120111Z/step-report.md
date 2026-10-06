# Step 0060 — QEMU arm64 `make corpus` determinism re-run (paired against 0059)

- **Command**: `PLATFORM=qemu ARCH=arm64 make corpus` (zero knobs; `SAMPLES=3`,
  `WORKLOAD_DURATION=30s`; full default suite `corpus/config/macro_apps.yaml`,
  all 6 apps; arm64 pass group `full`).
- **Purpose**: arm64 counterpart of the KVM x86 corpus variance re-run
  (0056, `c37b6b539`). Tests whether step 0059's all-6-apps `post_rejit`
  failure is **deterministic** (genuine arm64 capability gap) or a one-off
  flake. Paired against 0059 (`corpus/results/arm64_qemu_corpus_19700101_000006_146493`).
- **Prev HEAD**: `ef51b1a98` (= `origin/master`). Launched 12:01:11Z, make
  PID 881657, qemu PID 894443 (up 12:06 → 12:47).
- **Run dir**: `corpus/results/arm64_qemu_corpus_19700101_000006_022292/`
  (QEMU in-VM clock is 1970 — no RTC; dir suffix is the in-VM pid).

## Verdict: deterministic

Suite `status: error` (`details/progress.json` `error_message: "corpus
suite reported errors"`). **All 6 apps `status: error`, each with the
identical per-app error string as 0059** (1:1 below). `post_rejit: null`
for every app — the `BPFREJIT_SHIM_LOADTIME_PLAN` (post_rejit_start) phase
fails for all 6 on arm64, in two independent full runs.

| app | 0059 error | 0060 error | match |
|---|---|---|---|
| `bcc/set` | `no tracked BPF programs` | `no tracked BPF programs` | ✔ |
| `otelcol-ebpf-profiler/profiling` | `no tracked BPF programs` | `no tracked BPF programs` | ✔ |
| `cilium/agent` | `Remote end closed connection without response; cilium-agent output tail: …` | identical prefix (in-VM timestamps differ) | ✔ |
| `katran` | `Katran server did not expose an attached XDP program on katran0` | identical | ✔ |
| `tetragon/observer` | `Tetragon exited before BPF programs were tracked by shim` | identical (fails at **baseline**, 0 workload samples, 0 bpf progs — same as 0059) | ✔ |
| `tracee/monitor` | `failed to launch Tracee: /artifacts/tracee/bin/tracee --events '*' …` | identical prefix | ✔ |

Raw baseline counters re-captured this run (raw values only — no
ratio/geomean/rollup; they differ numerically from 0059 because they are
timing-dependent, which does not affect the determinism verdict that is
about the failure signature):

- `bcc/set`: `sys_enter` `run_cnt_delta=1934466`, `sys_exit` `1934356`,
  `sched_switch` `882145` (23 progs tracked; 3 workload samples).
- `cilium/agent`: `cil_from_container` `run_cnt_delta=4375226`/`4370154`
  (83 progs; 3 workload samples).
- `katran`: `balancer_ingress` `run_cnt_delta=17192751` (1 prog; 3
  workload samples).
- `otelcol-ebpf-profiler/profiling`: `native_tracer_engine`
  `run_cnt_delta=322503` (12 progs; 3 workload samples).
- `tetragon/observer`: no baseline data (baseline start failed before the
  shim tracked BPF programs).
- `tracee/monitor`: `tracepoint_raw_sys_enter` `run_cnt_delta=1055357`,
  `trace_sys_enter` `1055289`, `trace_sys_exit` `1054367` (151 progs; 3
  workload samples).

## Cross-arch readout (analysis per `docs/evaluation.md` §5, not a gate)

- KVM x86 full-corpus runs (0051 `42e1c4e37`, 0056 `c37b6b539`): all 6
  apps `status: ok`, `post_rejit` carries `run_cnt_delta`/
  `run_time_ns_delta`.
- QEMU arm64 full-corpus runs (0059 `…_146493`, 0060 `…_022292`): baseline
  works 5/6 (shim tracks BPF programs; raw counters captured), the
  `post_rejit_start` phase fails for all 6; `post_rejit` is `null`.
- **The arm64 post-rejit gap is confirmed deterministic** — two full runs,
  6/6 apps, same per-app error strings. Recorded as a cross-arch
  capability gap; no framework/app/runner change, no exclusion lists, no
  re-gating (record-not-patch).

## Make + QEMU hygiene

- Log `make-corpus-arm64-rerun.log`: clean `sysrq: Power Off` /
  `reboot: Power down`; `test "$(cat .cache/qemu-arm64-root/qemu-status)"
  = "0"` passed before the host copy; 0 real make error markers. The make
  target exits 0 even with the suite `status: error` (0059 established
  the same pattern — a recorded suite error is not a make failure).
- 14 trackable files under the run dir committed;
  `details/shim-logs/` + `details/loadtime-plans/` stay gitignored
  (`git check-ignore` verified).
