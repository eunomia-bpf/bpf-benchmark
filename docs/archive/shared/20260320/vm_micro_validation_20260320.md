# VM Micro Validation (2026-03-20)

## Scope

Validation run for current local code state, following the requested sequence:

- `source /home/yunwei37/workspace/.venv/bin/activate`
- `make micro`
- `make kernel`
- `make scanner`
- `make vm-micro`

This is a validation run with Makefile default parameters, not an authoritative rerun:

- current validation: `ITERATIONS=3`, `WARMUPS=1`, `REPEAT=200`
- last authoritative reference: `ITERATIONS=10`, `WARMUPS=5`, `REPEAT=1000`

Result artifact:

- `micro/results/dev/vm_micro.json`
- generated at: `2026-03-20T22:38:17.045273+00:00`
- policy hash: `667ed0873980368f`
- guest kernel: `7.0.0-rc2-g0073b5462ce0-dirty`

Reference artifact used for comparison:

- `micro/results/vm_micro_authoritative_20260320.json`
- generated at: `2026-03-20T17:11:49.026733+00:00`
- authoritative baseline: overall `1.057197x`, applied-only `1.192666x`

Ratio direction below is `kernel median exec_ns / kernel-recompile median exec_ns`; values above `1.0x` mean recompile is faster.

## Build Status

- `make micro`: pass
- `make kernel`: pass
- `make scanner`: pass
- `make vm-micro`: pass

## Summary

| Metric | Current validation | Authoritative reference | Delta |
| --- | ---: | ---: | ---: |
| Benchmarks | `62` | `62` | `0` |
| Valid benchmarks | `62` | `62` | `0` |
| Overall geomean | `1.099522x` | `1.057197x` | `+0.042325x` |
| Applied-only geomean | `1.268716x` | `1.192666x` | `+0.076050x` |
| Non-applied geomean | `1.079673x` | `1.041098x` | `+0.038576x` |
| Applied benchmarks | `7` | `7` | `0` |
| Overall regressions | `27` | `18` | `+9` |
| Applied regressions | `3` | `2` | `+1` |
| Result mismatches | `0` | `0` | `0` |
| Crashes / sample errors / recompile errors | `0` | `0` | `0` |

Validity here means:

- all `62` benchmarks completed
- `kernel` and `kernel-recompile` medians were present
- no result mismatch against `expected_result`
- no sample `error`
- no `recompile.error`

## Applied Benchmark Breakdown

| Benchmark | Sites | Kernel ns | Recompile ns | Ratio | Status |
| --- | ---: | ---: | ---: | ---: | --- |
| `cmov_dense` | `26` | `78.0` | `25.0` | `3.120000x` | win |
| `bounds_ladder` | `4` | `245.0` | `113.0` | `2.168142x` | win |
| `large_mixed_500` | `7` | `433.0` | `517.0` | `0.837524x` | regression |
| `large_mixed_1000` | `7` | `941.0` | `777.0` | `1.211068x` | win |
| `bpf_call_chain` | `2` | `446.0` | `495.0` | `0.901010x` | regression |
| `rotate64_hash` | `116` | `93.0` | `67.0` | `1.388060x` | win |
| `rotate_dense` | `256` | `156.0` | `253.0` | `0.616601x` | regression |

## Notes

- No crash or correctness issue was reproduced in this run. The suite finished cleanly and wrote `micro/results/dev/vm_micro.json`.
- Compared with the same-day authoritative run, this validation run is directionally positive at the geomean level, but it is also noisier: overall regressions increased from `18` to `27`, and applied regressions increased from `2` to `3`.
- The largest applied swings versus authoritative are:
  - `cmov_dense`: `0.942857x -> 3.120000x`
  - `rotate_dense`: `1.349206x -> 0.616601x`
  - `large_mixed_500`: `1.072500x -> 0.837524x`
  - `rotate64_hash`: still a win, but weaker: `2.294118x -> 1.388060x`
- Because this validation run used only `3` measured iterations and `repeat=200`, it should be treated as a quick current-state validation, not as a replacement for the `10/5/1000` authoritative dataset.
