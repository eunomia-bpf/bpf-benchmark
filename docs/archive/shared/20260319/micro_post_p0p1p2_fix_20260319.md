# Micro Post P0/P1/P2 Fix Verification 2026-03-19

## Run

- Command: `source /home/yunwei37/workspace/.venv/bin/activate && make vm-micro ITERATIONS=5 WARMUPS=3 REPEAT=500`
- Output JSON: `micro/results/dev/vm_micro.json`
- Generated at: `2026-03-20T00:45:06.351455+00:00`
- Parameters: `3 warmups / 5 iterations / 500 repeat`

## Summary

- Valid benchmarks: `62/62`
- Overall geomean (`stock / recompile`): `0.976196x`
- Applied-only geomean (`stock / recompile`): `1.054358x`
- Applied benchmarks: `7`
- Applied regressions: `1`
  - `rotate_dense`: `177ns -> 214ns` (`0.827103x`)

## Applied Benchmarks

| Benchmark | Stock median ns | Recompile median ns | Ratio (`stock / recompile`) |
| --- | ---: | ---: | ---: |
| `cmov_dense` | `59` | `59` | `1.000000x` |
| `bounds_ladder` | `192` | `182` | `1.054945x` |
| `large_mixed_500` | `483` | `446` | `1.082960x` |
| `large_mixed_1000` | `871` | `826` | `1.054479x` |
| `bpf_call_chain` | `314` | `312` | `1.006410x` |
| `rotate64_hash` | `91` | `63` | `1.444444x` |
| `rotate_dense` | `177` | `214` | `0.827103x` |

## Comparison vs Previous Post-DSL-Removal Result

- Previous checkpoint: overall `1.017x`, applied-only `1.078x`, `7` applied, `0` regressions
- Current rerun: overall `0.976196x`, applied-only `1.054358x`, `7` applied, `1` regression
- Delta vs previous:
  - Overall geomean: `-4.01%`
  - Applied-only geomean: `-2.19%`

## Conclusion

This `3warm / 5iter / 500rep` rerun does **not** preserve the previous post-DSL-removal micro result. The applied set size stayed at `7`, but `rotate_dense` regressed materially and pulled the suite-level overall geomean below `1.0x`.
