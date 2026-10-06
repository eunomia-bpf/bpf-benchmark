# Microarchitectural Experiments

## Setup
- Host CPU: Intel(R) Core(TM) Ultra 9 285K
- CPUs / SMT: 24 CPUs, 1 thread(s) per core, `/sys/devices/system/cpu/smt/active=0`
- cpufreq driver: intel_pstate (`intel_pstate` status: active)
- `cpupower` was not usable on this kernel build, so frequency control used the cpufreq sysfs interface directly.
- `--strict-env` requires `performance` governor and `no_turbo=1` in this harness, so the requested max/min/mid sweep was implemented as fixed `performance`-governor clamps rather than a literal `powersave` run.
- Fixed frequency points: low 800000 kHz, mid 2250000 kHz, high 3700000 kHz.

## Experiment 1: CPU Frequency Sweep
| benchmark | low L/K | mid L/K | high L/K | ratio spread | classification |
| --- | --- | --- | --- | --- | --- |
| simple | 2.421x | 0.946x | 0.605x | 300.0% | timer-limited |
| binary_search | 0.475x | 0.462x | 0.361x | 31.7% | material |
| bitcount | 0.562x | 0.507x | 0.563x | 11.2% | minor |
| load_byte_recompose | 0.485x | 0.412x | 0.364x | 33.2% | material |
| switch_dispatch | 0.806x | 0.828x | 0.706x | 17.3% | material |
| mega_basic_block_2048 | 0.968x | 0.941x | 0.953x | 2.8% | flat |

Frequency notes:
- `simple` is timer-limited here: at least one runtime stayed below ~100 ns, so the ratio swing is mostly quantization noise.
- `binary_search` moved materially across frequency points (31.7% ratio spread); llvmbpf gained relative to kernel as frequency increased.
- `load_byte_recompose` moved materially across frequency points (33.2% ratio spread); llvmbpf gained relative to kernel as frequency increased.
- `switch_dispatch` moved materially across frequency points (17.3% ratio spread); llvmbpf gained relative to kernel as frequency increased.

## Experiment 2: Input Distribution Sweep
- `branch_layout` predictable input keeps all values on the hot `< hot_threshold` path; random input uses a pseudorandom hot/cold split.
- `branch_fanout_32` predictable input repeats a single tag; random input uses a pseudorandom 32-way tag mix.
| benchmark | predictable L/K | random L/K | ratio delta | classification |
| --- | --- | --- | --- | --- |
| branch_layout | 0.225x | 0.326x | 44.6% | material |
| branch_fanout_32 | 0.775x | 0.696x | 10.2% | minor |

Distribution notes:
- `branch_layout` was distribution-sensitive: predictable 0.225x vs random 0.326x.
- `branch_fanout_32` only moved modestly under the predictable/random switch (10.2% ratio delta).

## Experiment 3: SMT Effects
- Skipped. This host reports `Thread(s) per core: 1` and `/sys/devices/system/cpu/smt/active=0`, so there is no sibling logical CPU to stress.

## Experiment 4: PMU Counter Collection
| benchmark | runtime | exec median | IPC | branch miss rate | cache miss rate |
| --- | --- | --- | --- | --- | --- |
| simple | llvmbpf | 20 ns | 0.872 | 0.20% | 15.23% |
| simple | kernel | 8 ns | 0.135 | 0.91% | 10.08% |
| binary_search | llvmbpf | 255 ns | 6.856 | 0.04% | 17.71% |
| binary_search | kernel | 633 ns | 2.408 | 0.14% | 9.75% |
| bitcount | llvmbpf | 2.5 us | 4.796 | 0.12% | 13.35% |
| bitcount | kernel | 4.5 us | 4.781 | 0.13% | 11.30% |
| load_byte_recompose | llvmbpf | 91 ns | 3.419 | 0.70% | 13.89% |
| load_byte_recompose | kernel | 283 ns | 1.196 | 0.70% | 10.18% |
| switch_dispatch | llvmbpf | 256 ns | 2.635 | 0.17% | 13.29% |
| switch_dispatch | kernel | 326 ns | 1.417 | 0.43% | 9.65% |
| mega_basic_block_2048 | llvmbpf | 893 ns | 2.260 | 0.25% | 65.85% |
| mega_basic_block_2048 | kernel | 960 ns | 1.595 | 1.19% | 9.68% |

PMU notes:
- `simple`: timer-limited benchmark, so treat PMU-vs-time comparisons as qualitative only.
- `binary_search`: faster runtime was `llvmbpf`; higher IPC belonged to `llvmbpf`.
- `bitcount`: faster runtime was `llvmbpf`; higher IPC belonged to `llvmbpf`.
- `load_byte_recompose`: faster runtime was `llvmbpf`; higher IPC belonged to `llvmbpf`.
- `switch_dispatch`: faster runtime was `llvmbpf`; higher IPC belonged to `llvmbpf`.
- `mega_basic_block_2048`: faster runtime was `llvmbpf`; higher IPC belonged to `llvmbpf`.

## Conclusions
- Frequency changed the L/K ratio materially for `binary_search`, `load_byte_recompose`, `switch_dispatch`.
- Branch predictability changed the L/K ratio materially for `branch_layout`.
- `simple` remained timer-limited across the sweep and should not be used to infer real frequency sensitivity.
- SMT interference could not be evaluated because SMT is disabled or unavailable on this machine.
- PMU counters are most useful here for explaining why a ratio changed; they should not be over-interpreted when the benchmark itself is near timer resolution.

## Artifacts
- Frequency sweep JSONs: `/home/yunwei37/workspace/bpf-benchmark/tmp/freq_sweep_low.json`, `/home/yunwei37/workspace/bpf-benchmark/tmp/freq_sweep_mid.json`, `/home/yunwei37/workspace/bpf-benchmark/tmp/freq_sweep_high.json`
- Branch distribution JSONs: `/home/yunwei37/workspace/bpf-benchmark/tmp/branch_distribution_predictable.json`, `/home/yunwei37/workspace/bpf-benchmark/tmp/branch_distribution_random.json`
- PMU JSON: `/home/yunwei37/workspace/bpf-benchmark/tmp/pmu_microarch.json`
- Metadata: `/home/yunwei37/workspace/bpf-benchmark/tmp/microarch_meta.json`

