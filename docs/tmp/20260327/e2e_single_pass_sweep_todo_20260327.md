# E2E Single-Pass Sweep Todo

Date: `2026-03-27`

## Goal

All three one-pass sweeps are already complete. This file now tracks the targeted follow-up work that should happen after those sweeps, not the first-pass execution itself.

The new goal is:

- rerun only the cases whose blockers are still actionable
- avoid spending VM time on configs already proven invalid
- use single-case entrypoints for focused validation
- convert sweep-era “non-comparable” states into concrete root causes

## Constraints

- Use the VM only for kernel/BPF runtime.
- Do not run `vm-e2e` in parallel with any other perf benchmark.
- Keep each sweep to one pass only.
- Prefer the canonical entrypoint: `make vm-e2e`.

## Sweep Matrix

1. `map_inline`
2. `const_prop`
3. `dce`

Cases included in each sweep:

- `tracee`
- `tetragon`
- `bpftrace`
- `scx`
- `katran`
- `bcc`

## Commands

Single sweep:

```bash
make vm-e2e E2E_ARGS='--rejit-passes map_inline --duration 5'
```

Targeted reruns now preferred:

```bash
make vm-static-test STATIC_VERIFY_ARGS='--filter bpf_execve_event --max-objects 1 --enabled-passes map_inline'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--config e2e/cases/tetragon/config_execve_rate.yaml --rejit-passes map_inline --duration 5'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--config e2e/cases/tetragon/config_execve_rate.yaml --rejit-passes const_prop --duration 5'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--config e2e/cases/tetragon/config_execve_rate.yaml --rejit-passes dce --duration 5'
make vm-e2e E2E_CASE=katran E2E_ARGS='--rejit-passes map_inline,const_prop,dce --duration 5'
```

Rationale:

- `make vm-e2e` now supports `E2E_CASE=...`, so follow-up validation no longer needs to rerun all six suites.
- `make vm-static-test` now supports `--enabled-passes ...` for `static_verify_object`, so pass-isolated VM correctness checks can run without paying for a perf benchmark.
- The current Tracee `read_hotpath` config has already been proven invalid because `apply_programs` never execute during preflight.
- `--duration 5` remains the right default for fast targeted triage before any authoritative rerun.
- Current Tetragon reruns already established that the old `missing btf func_info` blocker is fixed; the remaining work is pass-specific verifier/debugging.

## What To Record Per Case

- final status: `ok` / `skipped` / `failed`
- setup status and missing dependency clues
- attach success and discovered live program count
- aggregate site totals
- baseline vs rejit runtime deltas
- obvious data-quality issues:
  - zero target executions
  - workload timeout
  - stdout/stderr backpressure
  - lost events
  - verifier rollback / pass rejection

## Follow-Up Triage Order

1. Retire invalid Tracee configs and replace them with an apply-program-active benchmark.
2. Split Tetragon follow-up by isolated pass and verifier surface.
   - `map_inline`: current blocker is now downstream of actual rewrite/apply, not missing metadata.
   - `const_prop`: `event_execve` currently rejects with `unreachable insn 230`.
   - `dce`: current active-program reject is `call unknown#195896080` followed by `R4 !read_ok`.
3. Keep Katran on targeted coverage/workload work, not blind sweep reruns.
4. Separate “no sites for this pass” from real regressions in the summary layer.
5. Rerun only the impacted case after each fix, using `E2E_CASE`.

## Expected Improvement Targets

- `bcc`: confirm `execsnoop` on `exec_loop` and check whether `syscount` is cleaner than `bindsnoop`.
- `tracee`: replace `read_hotpath` with a config where `target_programs` and `apply_programs` both show non-zero preflight activity.
- `tetragon`: treat `event_execve` as the active hot/apply target until `execve_rate` stops showing `run_cnt_delta = 0` in preflight; debug each isolated-pass verifier reject separately instead of grouping them under one `EINVAL`.
- `bpftrace`: likely stable; use as a control group for single-pass sensitivity.
- `scx`: distinguish scheduler noise from real pass effect.
- `katran`: prefer configs/workloads that can actually expose `const_prop + dce` wins, instead of repeating already-flat combinations.
