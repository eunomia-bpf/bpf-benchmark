# Micro Authoritative Post-Simplification Baseline (2026-03-19)

## Run

- Command:
  `source /home/yunwei37/workspace/.venv/bin/activate && make vm-micro ITERATIONS=10 WARMUPS=5 REPEAT=1000`
- Result JSON:
  `micro/results/dev/vm_micro.json`
- JSON provenance:
  - `generated_at`: `2026-03-20T01:42:28.052840+00:00`
  - `policy_files_hash`: `667ed0873980368f`
  - `cpu_model`: `Intel(R) Core(TM) Ultra 9 285K`
  - `environment`: `vm`
- Host warnings emitted by the run:
  - CPU governor reported as `unknown`
  - Turbo boost enabled
  - `perf_event_paranoid=2`
  - No CPU affinity pinning

## Metric Definition

- Ratio direction in this note is `stock / recompile` (`kernel` median exec_ns divided by `kernel-recompile` median exec_ns).
- Overall geomean uses all `62` benchmarks in `micro/results/dev/vm_micro.json`.
- Applied-only geomean uses the `7` benchmarks whose `kernel-recompile` run had `recompile.applied=true` in all `10/10` measured samples.

## Baseline Summary

| Metric | Value |
| --- | ---: |
| Overall geomean (`stock / recompile`) | `1.003942x` |
| Applied-only geomean (`stock / recompile`) | `1.151824x` |
| Non-applied geomean (`stock / recompile`) | `0.986536x` |
| Applied benchmarks | `7` |
| Applied regressions | `0` |

## Applied Benchmark Breakdown

| Benchmark | Stock median ns | Recompile median ns | Ratio (`stock / recompile`) | Status |
| --- | ---: | ---: | ---: | --- |
| `cmov_dense` | `66.5` | `39.5` | `1.683544x` | win |
| `rotate_dense` | `164.0` | `130.5` | `1.256705x` | win |
| `large_mixed_500` | `414.0` | `381.5` | `1.085190x` | win |
| `bounds_ladder` | `154.5` | `144.5` | `1.069204x` | win |
| `large_mixed_1000` | `807.0` | `764.0` | `1.056283x` | win |
| `rotate64_hash` | `70.5` | `68.5` | `1.029197x` | win |
| `bpf_call_chain` | `320.5` | `318.0` | `1.007862x` | win |

## Comparison To Previous Results

| Reference | Overall | Applied-only | Applied count | Delta vs current |
| --- | ---: | ---: | ---: | --- |
| Post-DSL early 2026-03-19 | `1.017x` | `1.078x` | `7` | overall `-0.013058x`, applied-only `+0.073824x`, applied count unchanged |
| Authoritative 2026-03-14 | `1.054x` | `1.074x` | `16` | overall `-0.050058x`, applied-only `+0.077824x`, applied count `-9` |

## Takeaway

- Post-simplification baseline keeps the same `7` applied benchmarks as the post-DSL early 2026-03-19 run.
- The applied set is strictly better than both reference points: `1.151824x` vs `1.078x` (post-DSL early) and `1.074x` (2026-03-14).
- No applied benchmark regressed; the weakest applied win is `bpf_call_chain` at `1.007862x`.
- Suite-level overall geomean falls to `1.003942x`, below both comparison points, because the non-applied set is net negative at `0.986536x`.
