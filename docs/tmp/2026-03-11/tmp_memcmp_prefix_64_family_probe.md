# Kernel Recompile Per-Family Ablation

## Methodology

- Family policies: `wide, rotate` via `micro/policies/per_family/*.yaml` allowlists
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
| wide | 1 | 1 | 1.116x | 1.321x | 1 | 0 | 0 | 1 |
| rotate | 1 | 1 | 1.116x | 1.321x | 1 | 0 | 0 | 0 |

## Top Wins / Losses

### `wide`

- Headline: stock/family geomean `1.116x`, blind/family exec geomean `1.321x`, applied `1` benches, selected `1` sites.
- Focus: n/a
- Top wins vs stock: `memcmp_prefix_64` 1.116x
- Top losses vs stock: n/a
- Faster than blind all-apply: `memcmp_prefix_64` 1.321x
- Slower than blind all-apply: n/a

### `rotate`

- Headline: stock/family geomean `1.116x`, blind/family exec geomean `1.321x`, applied `1` benches, selected `3` sites.
- Focus: n/a
- Top wins vs stock: `memcmp_prefix_64` 1.116x
- Top losses vs stock: n/a
- Faster than blind all-apply: `memcmp_prefix_64` 1.321x
- Slower than blind all-apply: n/a

## Family Interaction Analysis

- Benchmarks with at least one valid single-family run and a valid blind all-apply reference: `1`
- Best single-family winner count: `wide` 1
- Strongest positive complementarity: none
- Strongest negative interference (best single family faster than blind all-apply):
  - `memcmp_prefix_64`: best-single `wide` beat blind by `1.321x`; candidate families `wide, rotate`.
