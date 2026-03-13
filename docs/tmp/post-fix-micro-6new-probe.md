# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-g05a1845490ed-dirty`
- Benchmarks: `6` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 2 / 500`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `1.045x`
- Applied-only geomean (stock / recompile): `0.979x`
- Wins / losses / ties: `2 / 4 / 0`
- Valid / invalid pairs: `6 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| addr-calc | 1 | 1 | 0 | 0.854x | n/a | 0 | 1 | 0 |
| bitfield-extract | 1 | 1 | 1 | 0.989x | 0.989x | 0 | 1 | 0 |
| branch-flip | 1 | 1 | 0 | 0.989x | n/a | 0 | 1 | 0 |
| endian-fusion | 1 | 1 | 0 | 1.643x | n/a | 1 | 0 | 0 |
| rotate-canonical | 1 | 1 | 1 | 0.897x | 0.897x | 0 | 1 | 0 |
| select-diamond | 1 | 1 | 1 | 1.055x | 1.055x | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| cond_select_dense | select-diamond | 67 ns | 63.5 ns | 1.055x | yes | 1 | win |
| rotate_dense | rotate-canonical | 227.5 ns | 253.5 ns | 0.897x | yes | 5 | loss |
| addr_calc_stride | addr-calc | 178 ns | 208.5 ns | 0.854x | no | 0 | loss |
| extract_dense | bitfield-extract | 235 ns | 237.5 ns | 0.989x | yes | 1 | loss |
| endian_swap_dense | endian-fusion | 232.5 ns | 141.5 ns | 1.643x | no | 0 | win |
| branch_flip_dense | branch-flip | 217.5 ns | 220 ns | 0.989x | no | 0 | loss |
