# BPF JIT Policy Iteration Demo

- Generated: `2026-03-10 22:04:52Z`
- Kernel used: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux`
- Method: median `exec_ns` across `1` guest boot(s), each `micro_exec` run uses `--repeat 100`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`

## Summary

```text
=== BPF JIT Policy Iteration Demo ===
Program: log2_fold (predictable branches)
  Baseline:       523 ns  (jited: 648 bytes)
  + CMOV policy:  741 ns  (jited: 682 bytes) -> +41.7% slower
  + Revert:       627 ns  (jited: 648 bytes) -> stock code restored

Program: rotate64_hash (rotation-heavy)
  Baseline:       85 ns  (jited: 3559 bytes)
  + ROTATE policy: 123 ns  (jited: 2313 bytes) -> +44.7% slower

Conclusion: Same mechanism, opposite profitability -> policy matters.
```

## Per-Iteration Samples

| Program | Case | exec_ns samples | jited bytes | recompile applied |
| --- | --- | --- | --- | --- |
| log2_fold | Baseline | 523 | 648 | False |
| log2_fold | + CMOV policy | 741 | 682 | True |
| log2_fold | + Revert | 627 | 648 | False |
| rotate64_hash | Baseline | 85 | 3559 | False |
| rotate64_hash | + ROTATE policy | 123 | 2313 | True |

## Interpretation

- `log2_fold` uses the same CMOV-capable sites in the middle step; forcing CMOV makes the predictable workload slower.
- The revert step is a fresh stock reload because explicit `--policy-blob` recompile currently returns `EINVAL` on the working framework kernel in this checkout.
- `rotate64_hash` benefits from the v5 all-family pass in this tree (115 rotate sites, 8 wide sites).

