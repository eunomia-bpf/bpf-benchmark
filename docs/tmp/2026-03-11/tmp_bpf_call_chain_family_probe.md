# Kernel Recompile Per-Family Ablation

## Methodology

- Family policies: `cmov, wide` via `micro/policies/per_family/*.yaml` allowlists
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
| cmov | 1 | 0 | n/a | n/a | 0 | 0 | 0 | 0 |
| wide | 1 | 1 | 1.006x | n/a | 1 | 0 | 0 | 0 |

## Top Wins / Losses

### `cmov`

- Headline: stock/family geomean `n/a`, blind/family exec geomean `n/a`, applied `0` benches, selected `1` sites.
- Focus: n/a
- Top wins vs stock: n/a
- Top losses vs stock: n/a
- Faster than blind all-apply: n/a
- Slower than blind all-apply: n/a

### `wide`

- Headline: stock/family geomean `1.006x`, blind/family exec geomean `n/a`, applied `1` benches, selected `2` sites.
- Focus: n/a
- Top wins vs stock: `bpf_call_chain` 1.006x
- Top losses vs stock: n/a
- Faster than blind all-apply: n/a
- Slower than blind all-apply: n/a

## Family Interaction Analysis

- Benchmarks with at least one valid single-family run and a valid blind all-apply reference: `0`
- Best single-family winner count: n/a
- Strongest positive complementarity: none
- Strongest negative interference: none
