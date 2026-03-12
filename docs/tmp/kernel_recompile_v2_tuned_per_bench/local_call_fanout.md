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

- Overall geomean (stock / recompile, valid pairs only): `1.104x`
- Applied-only geomean (stock / recompile): `1.104x`
- Wins / losses / ties: `1 / 0 / 0`
- Valid / invalid pairs: `1 / 0`

## Per-Family Breakdown

| Family | Benchmarks | Valid | Applied | Geomean | Applied-only Geomean | Wins | Losses | Ties |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bpf-local-call | 1 | 1 | 1 | 1.104x | 1.104x | 1 | 0 | 0 |

## Per-Benchmark Table

| Benchmark | Family | Stock median | Recompile median | Stock/Recompile | Applied | Sites | Status |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| local_call_fanout | bpf-local-call | 138 ns | 125 ns | 1.104x | yes | 21 | win |
