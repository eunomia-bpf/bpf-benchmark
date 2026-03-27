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
| tracee | skip: `setpriv ... /bin/true` timeout | same skip | attach ok, but `rejit did not apply successfully` |
| tetragon | attach ok, not comparable | same | same |
| bpftrace | baseline ok, `rejit_successes=0` | same | same |
| scx | attach ok, `post-ReJIT measurements are unavailable` | same | same |
| katran | comparable, BPF speedup ratio `0.981x`, app throughput `+2.78%` | attach ok, no successful rejit | attach ok, no successful rejit |
| bcc | strongest signal: `9/10` rejit successes, geomean `1.016x` | `0/10` rejit successes | `0/10` rejit successes |

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

5. `tetragon` is stable at attach/load but unstable at actual apply/compare.
   - All three runs launched and measured baseline
   - All three runs ended with `rejit did not apply successfully`

6. `tracee` has an intermittent workload/harness failure.
   - `map_inline` and `const_prop` both skipped with `setpriv --reuid 65534 ... /bin/true` timing out
   - A direct VM probe outside Tracee confirmed both `stress-ng` and `setpriv` work in the same guest
   - `dce` no longer skipped, which suggests this is not a hard kernel incompatibility

7. `katran` only produced one comparable single-pass result.
   - `map_inline`: comparable, app throughput up `2.78%`, but BPF speedup ratio `0.981x` so the gain is not cleanly attributable to BPF execution alone
   - `const_prop` / `dce`: attach ok, but no successful rejit application

## Improvement Priorities

1. Fix Tracee error attribution and workload robustness.
   - The current top-level skip reason says “could not run on this kernel”, but the observed failure is a workload-side timeout.
   - Split agent-launch failures from workload execution failures.
   - Add explicit logging for whether `stress-ng --exec` ran or the case fell back to the rapid exec loop.

2. Make e2e summaries pass-aware.
   - Current summaries still report aggregate site totals for all passes.
   - For single-pass sweeps, the report should surface selected-pass site totals first.
   - This would make `bpftrace` immediately show “no relevant sites for this pass” instead of looking like a generic ReJIT failure.

3. Treat `const_prop` / `dce` isolated sweeps as diagnostic-only.
   - Current data strongly suggests these passes are not useful standalone end-to-end benchmarks.
   - For performance-facing runs, prefer `map_inline` alone or the cascade `map_inline,const_prop,dce`.

4. Improve `bcc` setup amortization.
   - Full-suite wall time is dominated by the last `bcc` phase on every sweep.
   - Reuse already-built tool artifacts more aggressively and skip setup when binaries are already present and validated.

5. Clarify non-comparable case states in `scx`, `tetragon`, and `katran`.
   - `scx`: measurement path unavailable
   - `tetragon`: apply failed
   - `katran`: apply failed for `const_prop` / `dce`
   - Those should be surfaced as first-class statuses in the summary layer, not buried in per-case markdown.

## Practical Next Step

If the goal is an actionable benchmark profile rather than pure diagnostics, the best next run is:

```bash
make vm-e2e E2E_ARGS='--rejit-passes map_inline,const_prop,dce --duration 5'
```

If the goal is harness cleanup first, start with:

1. Tracee workload failure attribution
2. Pass-aware site reporting
3. `bcc` setup caching
