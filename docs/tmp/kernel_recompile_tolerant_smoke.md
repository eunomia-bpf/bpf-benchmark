# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- Benchmarks: `2` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `0 / 1 / 20`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `0.452x`
- Applied-only geomean (stock / recompile): `0.452x`
- Wins / losses / ties: `0 / 1 / 0`
- Valid / invalid pairs: `1 / 1`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| search | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| select-diamond | 1 | 1 | 1 | 0.452x | 0.452x | 0 | 1 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| cmov_select | select-diamond | 700 ns | 1.550 us | 0.452x | yes | 11 | loss |
| binary_search | search | 1.099 us | n/a | n/a | yes | 3 | ok / result-mismatch |
