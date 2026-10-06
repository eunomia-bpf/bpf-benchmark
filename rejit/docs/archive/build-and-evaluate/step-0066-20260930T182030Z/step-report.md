# Step 0066: fresh KVM x86 default-policy (zero-knob) `make corpus` full 6-app two-start benchmark

- **Command**: `make corpus` (zero knobs: `PLATFORM=kvm ARCH=x86` defaults, `SAMPLES=3` default, `WORKLOAD_DURATION=30` default; full x86 pass chain `noop,map_inline,const_prop,dce,wide_mem,bounds_check_merge,skb_load_bytes_spec,noop,const_prop,dce,kop`; all 6 apps).
- **Launched**: `Wed Sep 30 18:20:30Z` (run-marker `run-marker.txt` carries the full attempt trail).
- **prev HEAD**: `8d4626452` (docs: step 0065 record + const_mod_reduce stale-prefix fix; `origin/master` in lockstep).
- **Purpose**: determinism/variance re-run paired against 0051 (`corpus/results/x86_kvm_corpus_20260930_053929_108492/`) and 0056 (`corpus/results/x86_kvm_corpus_20260930_084230_227783/`, `metadata: completed`), both the same zero-knob invocation at the same tree.
- **Result token**: `corpus/results/x86_kvm_corpus_20260930_193317_347907/` (attempt 4, detached).

## Launch history and OMP-supervisor reaping (recorded, not patched)

Three launches were reaped by the OMP supervisor before the ~35 min suite could complete. This is an environment/launch-lifecycle fact, not a suite defect.

| attempt | launched (UTC) | outcome | evidence |
|---|---|---|---|
| 1 | 18:20:30 | reaped ~18:26Z during host `modules_install` | log tail `Terminated`; kernel build had finished; VM never booted; no result dir; no OOM (journal clean) |
| 2 | 18:30:14 | booted; **5/6 apps completed `ok` with `post_rejit`**; reaped ~19:03Z | log line 396: `qemu-system-x86_64: terminating on signal 15 from pid 1865444 (omp)`; partial dir `corpus/results/x86_kvm_corpus_20260930_183425_011210/` retained (metadata stuck `status: running`, `apps_done: 5`, `last_app: katran ok`) |
| 3 | 19:14:10 | VM booted, suite just started; reaped ~19:23Z | log line 467: `qemu-system-x86_64: terminating on signal 15 from pid 1881935 (omp)`; partial dir `corpus/results/x86_kvm_corpus_20260930_192224_050834/` (progress `running`, 0 apps) |
| 4 | 19:28:57 (19:33:17 in-VM start) | **completed** | result dir `corpus/results/x86_kvm_corpus_20260930_193317_347907/` |

### Root cause of the reaping

- Every duty poll disposes the prior session; OMP's `cancelAndReapOwnerJobs` (confirmed in `/workspaces/.agent-state/bpf-benchmark-supervisor/bin/omp` — strings show `cancelAndReapOwnerJobs`, `failed to become a Linux child subreaper`, orphan-job naming) SIGTERMs the session's owned process trees. Attempts 1–3 were all launched as session-owned async jobs, so each died at the next session boundary — well before the ~35 min wall.
- Attempt 4 was launched **detached**: `setsid nohup make corpus … & < /dev/null` (new session/pgid, reparents to init). It is not in OMP's owned-job table, so the reaper cannot reach it. It survived three session-boundary restarts of this duty chain and reached clean completion.
- **Finding, not patch**: launch wiring (the frozen `make` target path) was not modified — only the process lifecycle was detached. This is a launch-infrastructure caveat, recorded here as provenance; the benchmark workload, app source, runner, and Makefile targets are unchanged.

## AWS arm64 re-check (read-only, 2026-09-30)

- No `~/.aws`, no `codex-arm64-test-20260319121631.pem` (or any arm64 key) on the host, no `AWS_*` credential env.
- Makefile knobs are wired and correct: `AWS_ARM64_*` → `t4g.micro` (kernel test) / `t4g.small` (bench), region `us-east-1`, profile `codex-ec2` (lines 115–123).
- External blocker: launching = spending money + missing key → **blocked on credentials**; report-only, no action.

## Observed raw facts (attempt 4, completed)

- VM lifecycle: in-VM `7.0.0-rc2+` kernel, hostname `virtme-ng`, 8 cpus / 64 GiB. `virtme-ng-init: Setting hostname to virtme-ng` at t≈0.656s; `reboot: Power down` at t≈2091.9s (final in-VM line, log line 390/390); clean `kvm: exiting hardware virtualization` immediately before. **Zero `signal 15`/`terminating`/`Terminated` lines in the attempt-4 log** (vs. attempts 1–3). ~35 min in-VM window.
- `metadata.json`: `status: completed`, `run_type: x86_kvm_corpus`, `samples: 3`, `workload_seconds: 30.0`, `bpf_stats: true`, `completed_at: 2026-09-30T20:07:27.350675+00:00`, no `error_message`.
- `details/result.json`: `status: ok`, `suite_name: macro_apps`, `samples: 3`, `skip_rejit: false`.
- `details/progress.json`: `status: completed`, `completed_at: 2026-09-30T20:07:27.350671+00:00`.
- 6/6 apps `status: ok`, `post_rejit` present, `rejit_result.status: ok` / `mode: loadtime`. Six `app_done` lines in the in-VM log (bcc/set, otelcol, cilium/agent, tetragon/observer, katran, tracee/monitor all `ok`).

### Per-app representative raw counters (0066 post vs. baseline; raw, no ratios — analysis per `rejit/docs/evaluation.md` §5)

| app | representative `post_rejit` prog | post `run_cnt_delta` | baseline `run_cnt_delta` | progs | jit/xlat (B) |
|---|---|---|---|---|---|
| bcc/set | `sys_exit` (id 913, tracepoint) | 552,276,514 | 553,208,188 | 25 | 262/408 |
| cilium/agent | `cil_from_contai` (id 3377, sched_cls) | 60,003,594 | 58,347,470 | 53 | 952/1416 |
| katran | `balancer_ingres` (id 6769, xdp) | 234,540,480 | 222,602,879 | 1 | 11778/19392 |
| otelcol/profiling | `native_tracer_e` (id 1270, perf_event) | 722,726 | 723,144 | 13 | 3688/5584 |
| tetragon/observer | `generic_tracepo` (id 5838, tracepoint) | 239,664,899 | 0 | 287 | 11895/21888 |
| tracee/monitor | `trace_sys_exit` (id 7152, raw_tracepoint) | 244,714,905 | 242,894,771 | 151 | 7618/12016 |

### Determinism pairing vs. 0051 / 0056 (same-prog post `run_cnt_delta`; raw triplets, no ratios)

| app | 0066 | 0051 | 0056 |
|---|---|---|---|
| bcc/set | 552,276,514 | 553,357,976 | 552,143,062 |
| cilium/agent | 60,003,594 | 61,297,916 | 60,516,106 |
| katran | 234,540,480 | 231,888,637 | 233,004,895 |
| otelcol/profiling | 722,726 | 722,703 | 723,381 |
| tetragon/observer | 239,664,899 | 237,073,117 | 240,231,431 |
| tracee/monitor | 244,714,905 | 243,075,067 | 242,999,914 |

- Same-order-of-magnitude, sub-percent to low-single-percent spread across the three same-tree zero-knob runs for all 6 apps — consistent determinism signal. **Raw triplets only; no ratio/geomean/rollup computed here** (forbidden in framework code; analysis is `rejit/docs/evaluation.md` §5).
- Tracee caveat (recorded, not a conclusion): the largest post-counter prog is named `trace_sys_exit` in 0066 but `tracepoint__raw` in 0051/0056 (same magnitude, ~243–245M counts).

## Validation

- 6/6 `post_rejit` present; all 6 apps `ok`; `rejit_result: ok` ×6 (loadtime mode).
- Clean VM teardown (`reboot: Power down` final line; `kvm: exiting hardware virtualization` before it); no reaping lines in the attempt-4 log.
- `metadata.json`/`result.json`/`progress.json` all `completed`/`ok`/`completed`.
- Honest gap: the actual launch command did **not** append an `exit=` marker line, so make's literal exit code was not captured; completion is established by the clean power-down + the three status files + the process tree having exited. No effect on the raw-counter evidence.

## Disposition

- **Clean completed 0066** — the first full 6/6 KVM x86 default-policy two-start benchmark at `8d4626452` in this duty chain, paired against 0051/0056. Valid benchmark evidence (not record-only).
- No framework/app/runner/Makefile change; no new gate/skip/validity logic; no ratio/geomean/rollup. The `setsid` detachment is a launch-infrastructure finding (process-lifecycle only), recorded as provenance, not a patch to the frozen launch wiring.
- Trackable JSON subset committed per the 0051 precedent (`42e1c4e37`): 6 `details/apps/*.json` + 6 `details/loadtime-reports/*.jsonl` + `details/result.json` + `details/progress.json` + `metadata.json` + this report + research-log append. `shim-logs/` + `loadtime-plans/` stay gitignored; the ~95 other untracked result dirs stay untracked.
