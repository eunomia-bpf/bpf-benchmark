# Kernel Recompile Per-Family Ablation

## Methodology

- Family policies: `wide` via benchmark-local v3 allowlists generated from scanner manifests
- Benchmarks: `4` from `config/micro_pure_jit.yaml`
- Stock sampling: `3 / 10 / 1000` (warmups / iterations / repeat)
- Guest kernel: `7.0.0-rc2-g05a1845490ed-dirty`
- Guest CPU pinning: `taskset -c 0`
- VM command shape: `vng --run /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage --memory 4G --cpus 2 --exec ...`
- Blind all-apply reference: `/home/yunwei37/workspace/bpf-benchmark/micro/results/kernel_recompile_strict_20260312.json` (`1.028x` stock/recompile, strict `2/10/500`)
- Blind/family ratios below are `all-apply exec / single-family exec`; values `>1` mean the single-family run is faster than blind all-apply.

## Per-Family Geomean

| Family | Site-Positive Benches | Applied | Stock/Family | Blind/Fam Exec | Wins | Losses | Ties | Best-Single Wins |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| wide | 4 | 4 | 0.959x | 1.003x | 3 | 1 | 0 | 0 |

## Top Wins / Losses

### `wide`

- Headline: stock/family geomean `0.959x`, blind/family exec geomean `1.003x`, applied `4` benches, selected `13` sites.
- Focus: `load_word32` stock/family `0.656x`, blind/family `0.871x`, status `loss`, sites `2`; `packet_redundant_bounds` stock/family `1.263x`, blind/family `1.034x`, status `win`, sites `8`
- Top wins vs stock: `packet_redundant_bounds` 1.263x, `load_byte` 1.019x, `load_byte_recompose` 1.005x
- Top losses vs stock: `load_word32` 0.656x
- Faster than blind all-apply: `load_byte_recompose` 1.098x, `packet_redundant_bounds` 1.034x, `load_byte` 1.022x
- Slower than blind all-apply: `load_word32` 0.871x

## Family Interaction Analysis

- Benchmarks with at least one valid single-family run and a valid blind all-apply reference: `0`
- Best single-family winner count: n/a
- Strongest positive complementarity: none
- Strongest negative interference: none
