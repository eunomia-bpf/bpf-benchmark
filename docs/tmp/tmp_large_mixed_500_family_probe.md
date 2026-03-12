# Kernel Recompile Per-Family Ablation

## Methodology

- Family policies: `wide, rotate, branch-flip` via `micro/policies/per_family/*.yaml` allowlists
- Benchmarks: `1` from `config/micro_pure_jit.yaml`
- Stock sampling: `2 / 5 / 200` (warmups / iterations / repeat)
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- Guest CPU pinning: `taskset -c 0`
- VM command shape: `vng --run /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage --memory 4G --cpus 2 --exec ...`
- Blind all-apply reference: `/home/yunwei37/workspace/bpf-benchmark/micro/results/kernel_recompile_strict_20260312.json` (`1.028x` stock/recompile, strict `2/10/500`)
- Blind/family ratios below are `all-apply exec / single-family exec`; values `>1` mean the single-family run is faster than blind all-apply.

## Per-Family Geomean

| Family | Site-Positive Benches | Applied | Stock/Family | Blind/Fam Exec | Wins | Losses | Ties | Best-Single Wins |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| wide | 1 | 1 | 1.055x | 0.975x | 1 | 0 | 0 | 0 |
| rotate | 1 | 1 | 1.075x | 0.993x | 1 | 0 | 0 | 0 |
| branch-flip | 1 | 1 | 1.202x | 1.110x | 1 | 0 | 0 | 1 |

## Top Wins / Losses

### `wide`

- Headline: stock/family geomean `1.055x`, blind/family exec geomean `0.975x`, applied `1` benches, selected `1` sites.
- Focus: n/a
- Top wins vs stock: `large_mixed_500` 1.055x
- Top losses vs stock: n/a
- Faster than blind all-apply: n/a
- Slower than blind all-apply: `large_mixed_500` 0.975x

### `rotate`

- Headline: stock/family geomean `1.075x`, blind/family exec geomean `0.993x`, applied `1` benches, selected `7` sites.
- Focus: n/a
- Top wins vs stock: `large_mixed_500` 1.075x
- Top losses vs stock: n/a
- Faster than blind all-apply: n/a
- Slower than blind all-apply: `large_mixed_500` 0.993x

### `branch-flip`

- Headline: stock/family geomean `1.202x`, blind/family exec geomean `1.110x`, applied `1` benches, selected `3` sites.
- Focus: n/a
- Top wins vs stock: `large_mixed_500` 1.202x
- Top losses vs stock: n/a
- Faster than blind all-apply: `large_mixed_500` 1.110x
- Slower than blind all-apply: n/a

## Family Interaction Analysis

- Benchmarks with at least one valid single-family run and a valid blind all-apply reference: `1`
- Best single-family winner count: `branch-flip` 1
- Strongest positive complementarity: none
- Strongest negative interference (best single family faster than blind all-apply):
  - `large_mixed_500`: best-single `branch-flip` beat blind by `1.110x`; candidate families `wide, rotate, branch-flip`.
