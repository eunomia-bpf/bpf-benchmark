# E2E Single-Pass Sweep Todo

Date: `2026-03-27`

## Goal

Run every checked-in e2e case serially in the VM, with exactly one ReJIT pass enabled per run, then summarize:

- which cases complete end to end
- which cases skip or fail
- which cases have applicable sites for the selected pass
- whether runtime/perf moves in a meaningful direction or is just noise

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

Other passes:

```bash
make vm-e2e E2E_ARGS='--rejit-passes const_prop --duration 5'
make vm-e2e E2E_ARGS='--rejit-passes dce --duration 5'
```

Rationale:

- `tracee` defaults to a `60s` measurement window.
- `tetragon`, `bpftrace`, and `scx` default to `30s`.
- A three-pass full-duration sweep is too expensive as a first diagnostic pass.
- `--duration 5` keeps the full case matrix while making serial triage practical.

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

1. Fix cases that fail before attach.
2. Fix cases that attach but have broken workloads.
3. Separate “no sites for this pass” from real regressions.
4. Rerun only the impacted cases after each fix.

## Expected Improvement Targets

- `bcc`: confirm `execsnoop` on `exec_loop` and check whether `syscount` is cleaner than `bindsnoop`.
- `tracee`: verify hotpath configs still produce non-zero target-program executions.
- `tetragon`: look for bpftool/attach drift and workload-specific long tails.
- `bpftrace`: likely stable; use as a control group for single-pass sensitivity.
- `scx`: distinguish scheduler noise from real pass effect.
- `katran`: watch for topology/setup variance dominating pass signal.
