# E2E Single-Pass Sweep Summary

Date: `2026-03-27`

Method:

- All checked-in e2e cases
- Canonical entrypoint: `make vm-e2e`
- One enabled ReJIT pass per sweep
- Unified short run: `--duration 5`

Sweeps completed:

1. `make vm-e2e E2E_ARGS='--rejit-passes map_inline --duration 5'`
2. `make vm-e2e E2E_ARGS='--rejit-passes const_prop --duration 5'`
3. `make vm-e2e E2E_ARGS='--rejit-passes dce --duration 5'`

Artifacts:

- `map_inline`
  - `tracee_20260327_194005`
  - `tetragon_20260327_194123`
  - `bpftrace_20260327_194237`
  - `scx_20260327_194424`
  - `katran_20260327_194445`
  - `bcc_20260327_194558`
- `const_prop`
  - `tracee_20260327_195259`
  - `tetragon_20260327_195418`
  - `bpftrace_20260327_195530`
  - `scx_20260327_195717`
  - `katran_20260327_195744`
  - `bcc_20260327_195830`
- `dce`
  - `tracee_20260327_200105`
  - `tetragon_20260327_200250`
  - `bpftrace_20260327_200402`
  - `scx_20260327_200551`
  - `katran_20260327_200618`
  - `bcc_20260327_200704`

## Result Matrix

| Case | map_inline | const_prop | dce |
| --- | --- | --- | --- |
| tracee | historical skip: `setpriv ... /bin/true` timeout | same historical skip | historical attach ok, but `rejit did not apply successfully` |
| tetragon | attach ok, not comparable | same | same |
| bpftrace | baseline ok, `rejit_successes=0` | same | same |
| scx | attach ok, `post-ReJIT measurements are unavailable` | same | same |
| katran | comparable, BPF speedup ratio `0.981x`, app throughput `+2.78%` | attach ok, no successful rejit | attach ok, no successful rejit |
| bcc | strongest signal: `9/10` rejit successes, geomean `1.016x` | `0/10` rejit successes | `0/10` rejit successes |

## Post-Sweep Updates

1. `make vm-e2e` now supports `E2E_CASE=...`, so follow-up validation no longer needs to rerun the full matrix.
2. Later Tracee validation on `config_read_hotpath.yaml` showed:
   - `target_runs > 0`
   - `apply_runs = 0`
   - final status: `preflight observed zero apply-program executions; skipping invalid optimization benchmark`
3. That means the current Tracee `read_hotpath` line is not just “noisy” or “flaky”; it is an invalid benchmark under the stricter guard, and the sweep-era Tracee results above should be treated as historical rather than actionable.
4. Unified `e2e/run.py` now writes canonical `output_json` / `output_md` files in addition to run-dir artifacts, so metadata output hints now resolve to real files.
5. After the kernel-side `func_info` preload fix and `free_tmp` `btf_put()` cleanup, a minimal VM correctness case (`T17_tracepoint_subprog`) passed, so the old Tetragon blocker `missing btf func_info` is no longer the current root cause.
6. Targeted single-case Tetragon reruns now exist for each isolated pass:
   - `map_inline`: `tetragon_20260328_033535`
   - `const_prop`: `tetragon_20260328_033915`
   - `dce`: `tetragon_20260328_034137`
7. `vm-static-test` now supports `--enabled-passes ...`, so pass-isolated VM correctness checks no longer need to rely on `vm-e2e`. A focused run on `bpf_execve_event` with `map_inline` showed `3/3 verifier_accepted`, but `applied=0`, which confirms that live-object static verify is a correctness control and not a substitute for map-stateful e2e data.

## High-Signal Findings

1. `bcc` is the only e2e suite that currently gives a clean single-pass `map_inline` signal.
   - Aggregate sites: `3165`, with `map_inline=183`
   - ReJIT successes: `9/10`
   - Geomean speedup: `1.0157x`

2. `const_prop` and `dce` do not stand on their own in the current e2e matrix.
   - `bcc` still reports the same aggregate discovered sites, but isolated `const_prop` / `dce` runs produced `0` successful post-ReJIT comparisons.
   - This is consistent with pass dependence: many useful `const_prop` / `dce` opportunities only become realizable after `map_inline`.

3. `bpftrace` is currently a mismatch for these three single-pass sweeps.
   - Across all three runs, `baseline_successes=6`, `rejit_successes=0`
   - Aggregate discovered sites were `wide_mem` only: `wide=21`, `map_inline=0`, `const_prop=0`, `dce=0`
   - This is not a harness crash; it is a pass/script applicability mismatch.

4. `scx` is still blocked by measurement support, not by pass selection.
   - All three runs attached and loaded
   - All three runs remained non-comparable because `post-ReJIT measurements are unavailable`

5. `tetragon` is no longer blocked by `missing btf func_info`; it is now split into three pass-specific verifier problems.
   - `map_inline`: current Tetragon line still does not compare successfully, but the old metadata blocker is gone and the remaining failure is downstream of actual rewrite/apply.
   - `const_prop`: isolated rerun on `event_execve` now fails with `unreachable insn 230`.
   - `dce`: isolated rerun now fails with `call unknown#195896080` followed by `R4 !read_ok`.
   - Across all three reruns, `execve_rate` stayed cold in preflight (`run_cnt_delta = 0`) while `event_execve` was the actually active apply target.

6. `tracee` has an intermittent workload/harness failure.
   - `map_inline` and `const_prop` both skipped with `setpriv --reuid 65534 ... /bin/true` timing out
   - A direct VM probe outside Tracee confirmed both `stress-ng` and `setpriv` work in the same guest
   - `dce` no longer skipped, which suggests this is not a hard kernel incompatibility

7. `katran` only produced one comparable single-pass result.
   - `map_inline`: comparable, app throughput up `2.78%`, but BPF speedup ratio `0.981x` so the gain is not cleanly attributable to BPF execution alone
   - `const_prop` / `dce`: attach ok, but no successful rejit application

## Improvement Priorities

1. Replace Tracee `read_hotpath` with a valid apply-program-active benchmark.
   - The latest guard validation proved that the current `read` workload heats `sys_enter` / `sys_exit` but not the configured `sys_enter_submit` / `sys_exit_submit`.
   - Do not spend more sweep time on this config until the measurement/apply pair is valid.

2. Triage Tetragon as three separate verifier surfaces, not one generic post-verify `EINVAL`.
   - `map_inline`: keep digging on the current rewrite/apply boundary, especially callback/static-subprog interactions.
   - `const_prop`: debug why the isolated rewrite leaves `event_execve` with `unreachable insn 230`.
   - `dce`: debug the active-program verifier state corruption around `call unknown#195896080` and `R4 !read_ok`.
   - Future Tetragon analysis should treat `event_execve` as the real hot/apply program until `execve_rate` is proven active.

3. Make e2e summaries pass-aware.
   - Current summaries still report aggregate site totals for all passes.
   - For single-pass sweeps, the report should surface selected-pass site totals first.
   - This would make `bpftrace` immediately show “no relevant sites for this pass” instead of looking like a generic ReJIT failure.

4. Treat `const_prop` / `dce` isolated sweeps as diagnostic-only.
   - Current data strongly suggests these passes are not useful standalone end-to-end benchmarks.
   - For performance-facing runs, prefer `map_inline` alone or the cascade `map_inline,const_prop,dce`.

5. Improve `bcc` setup amortization.
   - Full-suite wall time is dominated by the last `bcc` phase on every sweep.
   - Reuse already-built tool artifacts more aggressively and skip setup when binaries are already present and validated.

## Practical Next Step

If the goal is targeted harness cleanup rather than another historical full-matrix snapshot, the next runs should be:

```bash
make vm-static-test STATIC_VERIFY_ARGS='--filter bpf_execve_event --max-objects 1 --enabled-passes map_inline'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--config e2e/cases/tetragon/config_execve_rate.yaml --rejit-passes map_inline --duration 5'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--config e2e/cases/tetragon/config_execve_rate.yaml --rejit-passes const_prop --duration 5'
make vm-e2e E2E_CASE=tetragon E2E_ARGS='--config e2e/cases/tetragon/config_execve_rate.yaml --rejit-passes dce --duration 5'
```

and, only after choosing a new valid Tracee config:

```bash
make vm-e2e E2E_CASE=tracee E2E_ARGS='--config <new-tracee-config> --rejit-passes map_inline,const_prop --duration 5'
```
