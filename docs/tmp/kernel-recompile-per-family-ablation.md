# Kernel Recompile Per-Family Ablation

## Methodology

- Family policies: `cmov, wide, rotate, lea, extract, zero-ext, endian, branch-flip` via `micro/policies/per_family/*.yaml` allowlists
- Benchmarks: `56` from `config/micro_pure_jit.yaml`
- Stock sampling: `2 / 5 / 200` (warmups / iterations / repeat)
- Guest kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- Guest CPU pinning: `taskset -c 0`
- VM command shape: `vng --run /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage --memory 4G --cpus 2 --exec ...`
- Blind all-apply reference: `/home/yunwei37/workspace/bpf-benchmark/micro/results/kernel_recompile_strict_20260312.json` (`1.028x` stock/recompile, strict `2/10/500`)
- Blind/family ratios below are `all-apply exec / single-family exec`; values `>1` mean the single-family run is faster than blind all-apply.

## Per-Family Geomean

| Family | Site-Positive Benches | Applied | Stock/Family | Blind/Fam Exec | Wins | Losses | Ties | Best-Single Wins |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| cmov | 6 | 2 | 0.974x | 0.851x | 19 | 28 | 3 | 0 |
| wide | 49 | 51 | 1.010x | 0.894x | 27 | 25 | 4 | 10 |
| rotate | 15 | 14 | 1.021x | 0.902x | 29 | 24 | 3 | 8 |
| lea | 4 | 4 | 0.992x | 0.873x | 26 | 26 | 4 | 3 |
| extract | 3 | 3 | 1.001x | 0.878x | 20 | 31 | 4 | 1 |
| zero-ext | 0 | 0 | 1.019x | 0.899x | 23 | 30 | 3 | 0 |
| endian | 0 | 0 | 1.003x | 0.892x | 24 | 25 | 7 | 0 |
| branch-flip | 3 | 3 | 0.988x | 0.879x | 23 | 27 | 6 | 0 |

## Top Wins / Losses

### `cmov`

- Headline: stock/family geomean `0.974x`, blind/family exec geomean `0.851x`, applied `2` benches, selected `37` sites.
- Focus: `cmov_dense` stock/family `0.975x`, blind/family `0.919x`, status `loss`, sites `32`; `cmov_select` stock/family `0.940x`, blind/family `0.849x`, status `loss`, sites `1`
- Top wins vs stock: n/a
- Top losses vs stock: `cmov_select` 0.940x, `cmov_dense` 0.975x
- Faster than blind all-apply: n/a
- Slower than blind all-apply: `cmov_select` 0.849x, `cmov_dense` 0.919x

### `wide`

- Headline: stock/family geomean `1.010x`, blind/family exec geomean `0.894x`, applied `51` benches, selected `154` sites.
- Focus: `load_word32` stock/family `1.022x`, blind/family `0.784x`, status `win`, sites `2`; `packet_redundant_bounds` stock/family `1.306x`, blind/family `0.706x`, status `win`, sites `8`
- Top wins vs stock: `memcmp_prefix_64` 1.621x, `cgroup_hash_chain` 1.583x, `stride_load_16` 1.446x
- Top losses vs stock: `bounds_check_heavy` 0.599x, `bounds_ladder` 0.762x, `smallmul_strength_reduce` 0.766x
- Faster than blind all-apply: `memcmp_prefix_64` 1.437x, `packet_parse` 1.390x, `nested_loop_2` 1.270x
- Slower than blind all-apply: `bounds_check_heavy` 0.622x, `multi_acc_4` 0.667x, `rotate64_hash` 0.684x

### `rotate`

- Headline: stock/family geomean `1.021x`, blind/family exec geomean `0.902x`, applied `14` benches, selected `774` sites.
- Focus: `rotate64_hash` stock/family `1.391x`, blind/family `0.942x`, status `win`, sites `116`; `packet_rss_hash` stock/family `1.200x`, blind/family `0.880x`, status `win`, sites `11`
- Top wins vs stock: `rotate64_hash` 1.391x, `large_mixed_500` 1.283x, `cmov_dense` 1.200x
- Top losses vs stock: `alu32_64_pingpong` 0.814x, `cmov_select` 0.875x, `fixed_loop_large` 0.891x
- Faster than blind all-apply: `large_mixed_500` 1.244x, `fixed_loop_small` 1.155x, `cmov_dense` 1.131x
- Slower than blind all-apply: `imm64_storm` 0.699x, `alu32_64_pingpong` 0.770x, `cmov_select` 0.791x

### `lea`

- Headline: stock/family geomean `0.992x`, blind/family exec geomean `0.873x`, applied `4` benches, selected `5` sites.
- Focus: `stride_load_16` stock/family `1.389x`, blind/family `0.971x`, status `win`, sites `1`; `multi_acc_8` stock/family `1.062x`, blind/family `0.927x`, status `win`, sites `2`
- Top wins vs stock: `stride_load_16` 1.389x, `multi_acc_4` 1.209x, `stride_load_4` 1.184x
- Top losses vs stock: n/a
- Faster than blind all-apply: `stride_load_4` 1.076x
- Slower than blind all-apply: `multi_acc_4` 0.881x, `multi_acc_8` 0.927x, `stride_load_16` 0.971x

### `extract`

- Headline: stock/family geomean `1.001x`, blind/family exec geomean `0.878x`, applied `3` benches, selected `11` sites.
- Focus: `bitfield_extract` stock/family `0.846x`, blind/family `0.570x`, status `loss`, sites `9`; `bounds_check_heavy` stock/family `0.760x`, blind/family `0.789x`, status `loss`, sites `1`
- Top wins vs stock: n/a
- Top losses vs stock: `bounds_check_heavy` 0.760x, `bitfield_extract` 0.846x
- Faster than blind all-apply: n/a
- Slower than blind all-apply: `bitfield_extract` 0.570x, `bounds_check_heavy` 0.789x, `packet_parse_vlans_tcpopts` 0.897x

### `zero-ext`

- Headline: stock/family geomean `1.019x`, blind/family exec geomean `0.899x`, applied `0` benches, selected `0` sites.
- Focus: `alu32_64_pingpong` stock/family `0.870x`, blind/family `0.823x`, status `loss`, sites `0`
- Top wins vs stock: n/a
- Top losses vs stock: n/a
- Faster than blind all-apply: n/a
- Slower than blind all-apply: n/a

### `endian`

- Headline: stock/family geomean `1.003x`, blind/family exec geomean `0.892x`, applied `0` benches, selected `0` sites.
- Focus: `packet_parse_vlans_tcpopts` stock/family `1.000x`, blind/family `0.897x`, status `tie`, sites `0`; `packet_parse` stock/family `0.926x`, blind/family `1.403x`, status `loss`, sites `0`
- Top wins vs stock: n/a
- Top losses vs stock: n/a
- Faster than blind all-apply: n/a
- Slower than blind all-apply: n/a

### `branch-flip`

- Headline: stock/family geomean `0.988x`, blind/family exec geomean `0.879x`, applied `3` benches, selected `15` sites.
- Focus: `branch_dense` stock/family `0.969x`, blind/family `n/a`, status `loss`, sites `4`; `large_mixed_1000` stock/family `1.137x`, blind/family `0.916x`, status `win`, sites `8`
- Top wins vs stock: `large_mixed_1000` 1.137x, `large_mixed_500` 1.074x
- Top losses vs stock: `branch_dense` 0.969x
- Faster than blind all-apply: `large_mixed_500` 1.041x
- Slower than blind all-apply: `large_mixed_1000` 0.916x

## Family Interaction Analysis

- Benchmarks with at least one valid single-family run and a valid blind all-apply reference: `22`
- Best single-family winner count: `wide` 10, `rotate` 8, `lea` 3, `extract` 1
- Strongest positive complementarity (blind all-apply faster than the best single family):
  - `branch_fanout_32`: blind beat best-single `wide` by `1.365x`; candidate families `wide, rotate`.
  - `bounds_check_heavy`: blind beat best-single `extract` by `1.267x`; candidate families `wide, extract`.
  - `bitfield_extract`: blind beat best-single `wide` by `1.262x`; candidate families `wide, extract`.
  - `alu32_64_pingpong`: blind beat best-single `wide` by `1.203x`; candidate families `wide, rotate`.
  - `imm64_storm`: blind beat best-single `wide` by `1.175x`; candidate families `wide, rotate`.
- Strongest negative interference (best single family faster than blind all-apply):
  - `memcmp_prefix_64`: best-single `wide` beat blind by `1.437x`; candidate families `wide, rotate`.
  - `large_mixed_500`: best-single `rotate` beat blind by `1.244x`; candidate families `wide, rotate, branch-flip`.
  - `fixed_loop_small`: best-single `rotate` beat blind by `1.155x`; candidate families `wide, rotate`.
  - `stride_load_4`: best-single `lea` beat blind by `1.076x`; candidate families `wide, lea`.
  - `fixed_loop_large`: best-single `wide` beat blind by `1.043x`; candidate families `wide, rotate`.
