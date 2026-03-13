# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-g05a1845490ed-dirty`
- Benchmarks: `1` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 2 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `0.780x`
- Applied-only geomean (stock / recompile): `n/a`
- Wins / losses / ties: `0 / 1 / 0`
- Valid / invalid pairs: `1 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| parser | 1 | 1 | 0 | 0.780x | n/a | 0 | 1 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| packet_parse_vlans_tcpopts | parser | 16 ns | 20.5 ns | 0.780x | no | 0 | loss |
