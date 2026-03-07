# Representativeness Analysis

- Suites: `/home/yunwei37/workspace/bpf-benchmark/config/micro_pure_jit.yaml`, `/home/yunwei37/workspace/bpf-benchmark/config/micro_runtime.yaml`
- Corpus: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/bytecode_features.json`
- Corpus programs analyzed: 1588

## Suite Inventory

| Scope | Benchmarks | Category mix |
| --- | ---: | --- |
| micro_pure_jit | 29 | alu-mix:3, baseline:2, call-size:2, control-flow:4, dependency-ilp:5, loop-shape:5, memory-local:6, program-scale:2 |
| micro_runtime | 5 | helper-runtime:3, map-runtime:2 |
| combined | 34 | alu-mix:3, baseline:2, call-size:2, control-flow:4, dependency-ilp:5, helper-runtime:3, loop-shape:5, map-runtime:2, memory-local:6, program-scale:2 |

## Static Feature Ranges

| Feature | Corpus median | Corpus p90 | Corpus p99 | Pure-JIT max | Runtime max | Combined max |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Total insns | 10977 | 22899 | 27119 | 1016 | 1596 | 1596 |
| Branch insns | 1135 | 1458 | 2751 | 196 | 7 | 196 |
| Memory ops | 5203 | 11437 | 13027 | 253 | 171 | 253 |
| Helper calls | 289 | 847 | 1307 | 1 | 101 | 101 |
| BPF-to-BPF calls | 0 | 0 | 5 | 0 | 0 | 0 |

## Corpus Coverage

| Scope | % corpus in insn range | % corpus in helper-call range | % corpus in bpf2bpf range | % corpus inside 5D feature box |
| --- | ---: | ---: | ---: | ---: |
| micro_pure_jit | 1.8% | 0.2% | 96.7% | 0.0% |
| micro_runtime | 3.5% | 4.2% | 96.7% | 0.0% |
| combined | 3.7% | 4.4% | 96.7% | 0.8% |

## Remaining Gaps

- Program scale: combined suite now spans `29..1596` BPF insns, while the BCF median is `10977` and p90 is `22899`.
- Helper-heavy coverage: combined suite reaches `101` static helper calls, which covers 4.4% of the corpus by that feature alone.
- Local subprogram gap: `97.2%` of corpus programs contain multiple functions, while the current benchmark suite contributes `0.0%` such programs because llvmbpf still lacks local-call loader support.
- Multi-dimensional realism: only 0.8% of corpus programs fall inside the combined 5D feature box, so macro-corpus validation remains mandatory.
