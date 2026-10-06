# Step 0065: KVM x86 isolated `const_mod_reduce` evidence pass (record-only)

- **Command**: `make corpus BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=const_mod_reduce SAMPLES=1 WORKLOAD_DURATION=10` (documented knobs, composed on one invocation).
- **Launched**: `Wed Sep 30 17:13:41 UTC 2026` (run-marker `run-marker.txt`), make PID recorded in marker.
- **prev HEAD**: `85f8154f4` (docs: TEST_MODE propagation mechanism correction).
- **Purpose**: in-VM evidence pass for the `const_mod_reduce*` stale-prefix fix (the `/home/yunwei37/...` → `${BPFREJIT_REPO_ROOT:?...}` change on `default.yaml:10`), closing the 05-14 recorded follow-up.
- **Disposition**: **record-only.** No re-run, no new gate, no framework/app/runner change. This is a raw fail-fast data point, not clean two-start evidence.

## In-VM result window

- In-VM shim-logs: baseline `BPF_PROG_LOAD` window `48.589s → 80.821s` (~32.2 s of in-VM work, incl. the `post_rejit` abort).
- App lifecycle (09-30 `post_rejit`): `17:19:31.614` `Starting Katran` → `17:19:31.646` `Error in bpf_object__probe_loading(): -EINVAL` → `17:19:31` `Signal 6 (SIGABRT)`.
- VM lifecycle: clean `reboot: Power down` (final log line `[85.447]`); make target exits 0 (suite reports the raw app error; no make-level fail-fast).

## Result token

`corpus/results/x86_kvm_corpus_20260930_171858_652950/`

- `metadata.json`: `status: error`, `error_message: "corpus suite reported errors"`, `run_type: x86_kvm_corpus`, `config.enabled_passes: ["const_mod_reduce"]`, `samples: 1`, `workload_seconds: 10.0`, `bpf_stats: true`.
- `details/result.json`: `status: "error"`, `suite_name: "macro_apps"`, `skip_rejit: false`, `samples: 1`, 15/15 kop modules loaded (`status: ok`).
- `details/apps/katran.json`: `status: "error"`, `post_rejit: null`, `error: "native app exited before BPF programs were tracked by shim"`.
- 4 trackable JSONs (`metadata.json`, `result.json`, `progress.json`, `details/apps/katran.json`); the heavy `shim-logs/` + `loadtime-plans/` are gitignored. **Kept untracked** (consistent with the ~94 other untracked result dirs; raw abort, not clean evidence).

## Observed raw facts (09-30 isolated run)

### Baseline (completed)

- `baseline.bpf.9` = `balancer_ingres`, `type: xdp`, `id: 9`, `bytes_jited: 13641`, `bytes_xlated: 23840`, `run_cnt_delta: 24601220`, `run_time_ns_delta: 4212277005` (~171 ns/run).
- No `post_rejit` counters → no two-start ratio from this run.

### rejit_result

- `rejit_result.status: "ok"`, `mode: loadtime` (the loadtime plan pipeline ran to its end — this measures the *pipeline*, not the app; they are independent).
- `plan_path: details/loadtime-plans/katran.json`; `report_path: details/loadtime-reports/katran.jsonl` (report dir **empty** — the step failed before writing a report).

### Path fix validated in-VM (independent of the app error)

- `loadtime-plans/katran.json` step[0].command carries:
  `artifact="${BPFREJIT_REPO_ROOT:?BPFREJIT_REPO_ROOT is required}/runner/config/passes/const_mod_reduce/katran_x86_kvm_balancer_ingress_branchless_mod65537.bin"`
- The stale `/home/yunwei37` prefix is **gone**; `BPFREJIT_REPO_ROOT` resolves in-VM (injected by the runner — see the 09-30 log `native_loader_phase_env` `temporary_set_keys: [BPFREJIT_REPO_ROOT, BPFREJIT_SHIM_LOADTIME_PLAN, BPFREJIT_SHIM_LOG]`).
- `loadtime_plan_done status: "ok"` — the plan built with the correct path.

## Root cause: structural incompatibility (grounded, not build-stale)

The `const_mod_reduce` pass is structurally incompatible with the load-time two-start path as a *global* step.

1. **The plan has no program targeting.** The loadtime plan builder emits a single global step (`cmd: execute_plan`, `steps: [{name: const_mod_reduce}]`) with no per-program filter. In loadtime mode the shim runs this step against **every** `BPF_PROG_LOAD`, including libbpf's trivial probe loads.
2. **The step is a hard input-hash gate.** step[0].command:
   ```
   set -eu;
   expected_input_sha=1d8367af...;
   expected_output_sha=1929357b...;
   artifact="${BPFREJIT_REPO_ROOT:?...}/runner/config/passes/const_mod_reduce/katran_x86_kvm_balancer_ingress_branchless_mod65537.bin";
   actual_input_sha="$(sha256sum "${INPUT}" | awk '{print $1}')";
   if [ "$actual_input_sha" != "$expected_input_sha" ]; then ...; exit 1; fi;
   test -f "$artifact";
   cp "$artifact" "${OUTPUT}";
   ...
   ```
   `set -eu` + `exit 1` on any input-hash mismatch.
3. **The gate fires on libbpf's probe loads.** `details/shim-logs/katran.post_rejit.log` shows 4 probe `BPF_PROG_LOAD`s (`type=1 socket_filter insn_cnt=2` ×3, hashes `39f82ae5`/`58255400910d7827` ×2, and `type=5 tracepoint insn_cnt=2` ×1), each followed by `loadtime optimization failed: loadtime bpfopt step const_mod_reduce failed; log=/tmp/loadtime_2873_N/step0.log`. The probe bytecode hashes never equal `1d8367af` → the step's `exit 1`.
4. **The shim returns `EINVAL` for the probe load** (`bpfopt/shim/libbpfrejit_shim.c:945-955`: `loadtime_optimize_prog_load(...) < 0` → `log_line("loadtime optimization failed: %s", opt_err); errno=EINVAL; return -1;`) → libbpf's `bpf_object__probe_loading(): -EINVAL` → katran `can't load main bpf program` → `SIGABRT` → the app dies **before** `balancer_ingres` loads.

### Decisive contrast: 09-25 `map_inline` (same probes, graceful)

- `map_inline` step is `bpfopt --pass map_inline ...` — when it finds no bytecode changes it logs `loadtime prog=… produced no bytecode changes; passing original BPF_PROG_LOAD through` (graceful no-op) → the app survives → `balancer_ingres` (`type=6 xdp insn_cnt=2542`) loads → clean two-start. The same 4 probe loads are **handled**, not aborted.

### NOT build-stale (target would match if it reached the step)

- 09-30 baseline `balancer_ingres` bytecode `hash=0325eddd38cf33c9` (`insn_cnt=2542`, `bytes_jited=13641`, `bytes_xlated=23840`) is **byte-identical** to 09-25's (same `0325eddd`/13641/23840). The gate's `expected_input_sha=1d8367af` (sha of the 09-25 captured `input.step.0.bin` for `balancer_ingres`) still matches the target bytecode. The target is not stale.
- The abort fires on the *probe* progs, **before** `balancer_ingres` loads — so the gate never actually sees the target in this run.

### 05-14 worked because that mode was per-program, not global

- 05-14 (`x86_kvm_corpus_20260514_*`): `enabled_passes: ['noop', 'const_mod_reduce']`, `rejit_result.mode: None` — **per-program** rejit, only `prog 9` gated. `step[0]` = `noop` (no-op), `step[1]` = `const_mod_reduce` (diagnostics: `host_prepared_artifact=..._branchless_mod65537.bin`, `input_sha256=1d8367af...`, `output_sha256=1929357b...`). The trivial probes were **not** gated in that mode, so libbpf survived. This is a **loadtime-mode-specific finding**, not a regression.

## Disposition

- **Record-only.** A re-run deterministically reproduces the same abort (structural, not flaky).
- **No new gate / skip-on-mismatch logic added** — that would invent a validity gate and change the pass's fail-fast contract (forbidden). A BPF-prog step failure is recorded and surfaces naturally.
- The path fix (the actual increment-26 change) **is** validated in-VM (plan step[0] carries the correct `${BPFREJIT_REPO_ROOT:?...}` prefix; stale prefix gone; `loadtime_plan_done status: ok`).
- No framework/app/runner change; no ratio/geomean/rollup (analysis per `rejit/docs/evaluation.md` §5).
- `.bin` artifacts present and valid (both `const_mod_reduce` and `_branchless_rejected` are byte-identical 20448 B, sha256=`1929357b`=expected_output_sha, tracked in git).
- AWS arm64 line remains **blocked on credentials** (re-checked 2026-09-30: no `~/.aws`, no matching `.pem`); resume when credentials land.
