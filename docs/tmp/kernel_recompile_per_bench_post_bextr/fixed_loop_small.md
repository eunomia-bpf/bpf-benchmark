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

- Overall geomean (stock / recompile, valid pairs only): `1.019x`
- Applied-only geomean (stock / recompile): `n/a`
- Wins / losses / ties: `1 / 0 / 0`
- Valid / invalid pairs: `1 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| fixed-loop | 1 | 1 | 0 | 1.019x | n/a | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| fixed_loop_small | fixed-loop | 106.5 ns | 104.5 ns | 1.019x | no | 0 | win |
