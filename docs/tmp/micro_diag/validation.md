# Kernel Recompile Micro Strict

## Methodology

- Kernel: `7.0.0-rc2-ge52504a75c05-dirty`
- Benchmarks: `6` from `config/micro_pure_jit.yaml`
- Runtimes: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `0 / 1 / 1`
- CPU pinning: `taskset -c 0`
- CPU governor: `unknown`
- Turbo state: `unknown`

## Headline Numbers

- Overall geomean (stock / recompile, valid pairs only): `0.834x`
- Applied-only geomean (stock / recompile): `1.038x`
- Wins / losses / ties: `3 / 3 / 0`
- Valid / invalid pairs: `6 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bounds-density | 1 | 1 | 0 | 0.667x | n/a | 0 | 1 | 0 |
| bpf-local-call | 1 | 1 | 1 | 1.038x | 1.038x | 1 | 0 | 0 |
| branch-density | 1 | 1 | 0 | 0.661x | n/a | 0 | 1 | 0 |
| mixed-alu-mem | 1 | 1 | 0 | 1.036x | n/a | 1 | 0 | 0 |
| search | 1 | 1 | 0 | 0.623x | n/a | 0 | 1 | 0 |
| switch-dispatch | 1 | 1 | 0 | 1.139x | n/a | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| binary_search | search | 1.947 us | 3.125 us | 0.623x | no | 0 | loss |
| switch_dispatch | switch-dispatch | 5.073 us | 4.453 us | 1.139x | no | 0 | win |
| branch_dense | branch-density | 4.717 us | 7.133 us | 0.661x | no | 0 | loss |
| bpf_call_chain | bpf-local-call | 1.322 us | 1.273 us | 1.038x | yes | 2 | win |
| bounds_ladder | bounds-density | 1.192 us | 1.786 us | 0.667x | no | 0 | loss |
| mixed_alu_mem | mixed-alu-mem | 2.178 us | 2.103 us | 1.036x | no | 0 | win |
