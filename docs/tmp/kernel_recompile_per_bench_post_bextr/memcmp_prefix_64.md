# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-ga7ce05b49cb2-dirty`
- Benchmarks: `1` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 2 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `0.937x`
- Applied-only geomean (stock / recompile): `0.937x`
- Wins / losses / ties: `0 / 1 / 0`
- Valid / invalid pairs: `1 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| byte-compare | 1 | 1 | 1 | 0.937x | 0.937x | 0 | 1 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| memcmp_prefix_64 | byte-compare | 134 ns | 143 ns | 0.937x | yes | 3 | loss |
