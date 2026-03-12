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

- Overall geomean (stock / recompile, valid pairs only): `0.931x`
- Applied-only geomean (stock / recompile): `0.956x`
- Wins / losses / ties: `2 / 4 / 0`
- Valid / invalid pairs: `6 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bounds-density | 1 | 1 | 1 | 1.036x | 1.036x | 1 | 0 | 0 |
| bpf-local-call | 1 | 1 | 1 | 0.874x | 0.874x | 0 | 1 | 0 |
| branch-density | 1 | 1 | 0 | 0.723x | n/a | 0 | 1 | 0 |
| mixed-alu-mem | 1 | 1 | 1 | 0.967x | 0.967x | 0 | 1 | 0 |
| search | 1 | 1 | 0 | 1.231x | n/a | 1 | 0 | 0 |
| switch-dispatch | 1 | 1 | 0 | 0.834x | n/a | 0 | 1 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| binary_search | search | 2.808 us | 2.281 us | 1.231x | no | 0 | win |
| switch_dispatch | switch-dispatch | 4.240 us | 5.082 us | 0.834x | no | 0 | loss |
| branch_dense | branch-density | 5.595 us | 7.737 us | 0.723x | no | 0 | loss |
| bpf_call_chain | bpf-local-call | 1.600 us | 1.831 us | 0.874x | yes | 2 | loss |
| bounds_ladder | bounds-density | 1.481 us | 1.430 us | 1.036x | yes | 2 | win |
| mixed_alu_mem | mixed-alu-mem | 2.477 us | 2.562 us | 0.967x | yes | 2 | loss |
