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

- Overall geomean (stock / recompile, valid pairs only): `n/a`
- Applied-only geomean (stock / recompile): `n/a`
- Wins / losses / ties: `0 / 0 / 0`
- Valid / invalid pairs: `0 / 1`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| select-diamond | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| cmov_dense | select-diamond | n/a | n/a | n/a | no | 0 | command-failed / command-failed |
