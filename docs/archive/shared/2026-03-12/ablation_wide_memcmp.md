# Kernel Recompile Per-Family Ablation

## Methodology

- Family policies: `wide` via benchmark-local v3 allowlists generated from scanner manifests
- Benchmarks: `1` from `config/micro_pure_jit.yaml`
- Stock sampling: `3 / 10 / 1000` (warmups / iterations / repeat)
- Guest kernel: `7.0.0-rc2-g05a1845490ed-dirty`
- Guest CPU pinning: `taskset -c 0`
- VM command shape: `vng --run /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage --memory 4G --cpus 2 --exec ...`
- Blind all-apply reference: `/home/yunwei37/workspace/bpf-benchmark/micro/results/kernel_recompile_strict_20260312.json` (`1.028x` stock/recompile, strict `2/10/500`)
- Blind/family ratios below are `all-apply exec / single-family exec`; values `>1` mean the single-family run is faster than blind all-apply.

## Per-Family Geomean

| Family | Site-Positive Benches | Applied | Stock/Family | Blind/Fam Exec | Wins | Losses | Ties | Best-Single Wins |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| wide | 1 | 1 | 0.886x | 1.298x | 0 | 1 | 0 | 0 |

## Top Wins / Losses

### `wide`

- Headline: stock/family geomean `0.886x`, blind/family exec geomean `1.298x`, applied `1` benches, selected `1` sites.
- Focus: n/a
- Top wins vs stock: n/a
- Top losses vs stock: `memcmp_prefix_64` 0.886x
- Faster than blind all-apply: `memcmp_prefix_64` 1.298x
- Slower than blind all-apply: n/a

## Family Interaction Analysis

- Benchmarks with at least one valid single-family run and a valid blind all-apply reference: `0`
- Best single-family winner count: n/a
- Strongest positive complementarity: none
- Strongest negative interference: none
