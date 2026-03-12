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

- Overall geomean (stock / recompile, valid pairs only): `n/a`
- Applied-only geomean (stock / recompile): `n/a`
- Wins / losses / ties: `0 / 0 / 0`
- Valid / invalid pairs: `0 / 6`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bounds-density | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| bpf-local-call | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| branch-density | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| mixed-alu-mem | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| search | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |
| switch-dispatch | 1 | 0 | 0 | n/a | n/a | 0 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| binary_search | search | 2.037 us | n/a | n/a | no | 0 | ok / vm-crash |
| switch_dispatch | switch-dispatch | 4.321 us | n/a | n/a | no | 0 | ok / vm-crash |
| branch_dense | branch-density | 5.102 us | n/a | n/a | no | 0 | ok / vm-crash |
| bpf_call_chain | bpf-local-call | 1.435 us | n/a | n/a | no | 0 | ok / vm-crash |
| bounds_ladder | bounds-density | 1.201 us | n/a | n/a | no | 0 | ok / vm-crash |
| mixed_alu_mem | mixed-alu-mem | 1.889 us | n/a | n/a | no | 0 | ok / vm-crash |
