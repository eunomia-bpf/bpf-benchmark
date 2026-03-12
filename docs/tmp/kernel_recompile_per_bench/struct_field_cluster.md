# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- Benchmarks: `1` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 10 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `0.924x`
- Applied-only geomean (stock / recompile): `n/a`
- Wins / losses / ties: `0 / 1 / 0`
- Valid / invalid pairs: `1 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| field-access | 1 | 1 | 0 | 0.924x | n/a | 0 | 1 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| struct_field_cluster | field-access | 97 ns | 105 ns | 0.924x | no | 0 | loss |
