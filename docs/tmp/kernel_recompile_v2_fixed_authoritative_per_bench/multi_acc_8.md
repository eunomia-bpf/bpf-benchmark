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

- Overall geomean (stock / recompile, valid pairs only): `1.023x`
- Applied-only geomean (stock / recompile): `n/a`
- Wins / losses / ties: `1 / 0 / 0`
- Valid / invalid pairs: `1 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| multi-acc | 1 | 1 | 0 | 1.023x | n/a | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| multi_acc_8 | multi-acc | 594 ns | 580.5 ns | 1.023x | no | 0 | win |
