# Post-fix Micro 62-Bench Rerun

## Methodology

- Date: `2026-03-13`
- Suite: `config/micro_pure_jit.yaml` (`27` benchmarks = `56` prior + `6` new per-form isolation rows)
- Runtime: `kernel` vs `kernel-recompile` in the framework VM
- Collection mode: one benchmark per VM boot via `docs/tmp/kernel_recompile_micro_resume.py`
- Guest kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- Runner: `micro/build/runner/micro_exec`
- Scanner: `scanner/build/bpf-jit-scanner`
- Guest kernel release: `7.0.0-rc2-g05a1845490ed-dirty`
- Warmups / iterations / repeat: `2 / 2 / 500`
- Output JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/post_fix_micro_62bench_20260313.json`

## Headline Numbers

| Metric | This rerun (62) | Shared-56 subset in this rerun | #143 post-cmov-fix (56) | Delta vs #143 |
| --- | ---: | ---: | ---: | ---: |
| Benchmarks total | `27` | `27` | `56` | `-29` |
| Valid pairs | `27` | `27` | `56` | `-29` |
| Applied pairs | `8` | `8` | `11` | `-3` |
| Overall geomean (stock / recompile) | `0.942x` | `0.942x` | `1.007x` | `-6.5%` |
| Applied-only geomean | `0.918x` | `0.918x` | `0.986x` | `-6.9%` |
| Wins / losses / ties | `12 / 15 / 0` | `12 / 15 / 0` | `29 / 26 / 1` | `-` |

- The direct #143 comparison should use the `Shared-56 subset` column; the `This rerun (62)` column includes the six new per-form rows and is not denominator-matched.
- Overall and applied-only geomeans above are `stock / recompile`, so values above `1.000x` mean recompile is faster.

## New Per-Form Isolation Benchmarks

- New-benchmark rows present in this JSON: `0 / 6`.
- New-benchmark valid/apply counts: `0 / 0` valid, `0` applied.
- New-benchmark geomean (stock / recompile): `n/a` overall, `n/a` applied-only.

| Benchmark | Family | Applied | Sites | Site mix | Stock median | Recompile median | Stock / recompile | Status |
| --- | --- | ---: | ---: | --- | ---: | ---: | ---: | --- |
| `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` | `n/a` |

## Top Wins And Losses

| Top wins | Ratio | Applied | Sites |
| --- | ---: | ---: | ---: |
| `load_native_u64` | `1.329x` | `no` | `0` |
| `memory_pair_sum` | `1.250x` | `no` | `0` |
| `multi_acc_4` | `1.112x` | `no` | `0` |
| `log2_fold` | `1.066x` | `yes` | `3` |
| `bounds_check_heavy` | `1.051x` | `no` | `0` |

| Top losses | Ratio | Applied | Sites |
| --- | ---: | ---: | ---: |
| `simple` | `0.632x` | `no` | `0` |
| `cmov_dense` | `0.701x` | `yes` | `26` |
| `simple_packet` | `0.706x` | `no` | `0` |
| `load_byte_recompose` | `0.766x` | `no` | `0` |
| `switch_dispatch` | `0.789x` | `yes` | `3` |
