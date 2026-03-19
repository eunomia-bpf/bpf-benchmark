# Tetragon Authoritative Rerun 2026-03-18

## Run Conditions

- Activated host venv: `source /home/yunwei37/workspace/.venv/bin/activate`
- Precheck before launch: `ps aux | grep -E 'qemu|vng' | grep -v grep`
- Precheck result: no active `qemu` or `vng` processes
- Exactly one VM was started for this rerun
- Guest command used:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --memory 4G \
  --cpus 2 \
  --rwdir /home/yunwei37/workspace/bpf-benchmark \
  -- \
  bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && \
    source /home/yunwei37/workspace/.venv/bin/activate && \
    python3 e2e/run.py tetragon \
      --output-json /home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tetragon_authoritative_20260318.json \
      --output-md /home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tetragon_authoritative_20260318.md'
```

- VM exit status: `0`
- Result artifacts:
  - `e2e/results/dev/tetragon_authoritative_20260318.json`
  - `e2e/results/dev/tetragon_authoritative_20260318.md`

## Run Summary

- mode: `tetragon_daemon`
- comparison comparable: `True`
- setup return code: `0`
- Tetragon binary: `/usr/local/bin/tetragon`
- policy summary: `configured_programs=3`, `fallback_programs=2`
- app throughput geomean: `0.829607x`

Per-workload comparison:

| Workload | Baseline ops/s | Post ops/s | App delta | Events/s delta | BPF avg ns delta |
| --- | ---: | ---: | ---: | ---: | ---: |
| `stress_exec` | `238.76` | `257.71` | `+7.94%` | `+7.88%` | `-1.94%` |
| `file_io` | `1,405,785.12` | `1,495,975.42` | `+6.42%` | `+0.68%` | `-0.60%` |
| `open_storm` | `307,419.20` | `287,881.49` | `-6.36%` | `-25.00%` | `-32.59%` |
| `connect_storm` | `1,472.96` | `648.67` | `-55.96%` | `-0.25%` | `+7.80%` |

Interpretation against the expected direction:

- `stress_exec`: positive as expected
- `file_io`: positive
- `open_storm`: negative, not neutral
- `connect_storm`: severe regression, not an improvement

## Comparison To Archived March 11 Result

Requested historical reference was the archived March 11, 2026 blind all-apply result in `e2e/results/archive/tetragon-real-e2e.md`.

Important caveat:

- March 11 artifact is smoke-sized (`8s`)
- This rerun is the full non-smoke configuration (`30s`)
- So this is a directional comparison, not a perfect apples-to-apples duration match

Historical deltas from March 11:

| Workload | 2026-03-11 archived | 2026-03-18 clean rerun | Swing |
| --- | ---: | ---: | ---: |
| `stress_exec` | `+6.74%` | `+7.94%` | `+1.20 pts` |
| `file_io` | `+4.03%` | `+6.42%` | `+2.39 pts` |
| `open_storm` | `+2.58%` | `-6.36%` | `-8.93 pts` |
| `connect_storm` | `-10.16%` | `-55.96%` | `-45.80 pts` |

Aggregate comparison:

- March 11 app throughput geomean: `1.005759x`
- This rerun app throughput geomean: `0.829607x`
- Relative swing vs March 11 geomean: `-17.51%`

## Comparison To Earlier Same-Day Full Run

There is already an earlier March 18 full Tetragon rerun in:

- `e2e/results/dev/tetragon_20260318.json`

That earlier full run had:

- app throughput geomean: `0.955479x`
- `connect_storm`: `-20.42%`
- `open_storm`: `+0.56%`

This clean rerun is materially worse:

- app throughput geomean fell from `0.955479x` to `0.829607x`
- `connect_storm` worsened from `-20.42%` to `-55.96%`
- `open_storm` worsened from `+0.56%` to `-6.36%`

So even under single-VM conditions, the Tetragon result remains unstable and the latest clean rerun does not support a positive or neutral headline.

## Decision

- This rerun is a clean single-VM measurement and should be treated as the authoritative record of this specific March 18 run.
- It does **not** meet the promotion gate requested for `connect_storm`.
- `connect_storm` is still a severe regression and is substantially worse than both the archived March 11 result and the earlier same-day full rerun.
- I did **not** copy the dev artifact to `e2e/results/tetragon_authoritative_20260318.json`.
