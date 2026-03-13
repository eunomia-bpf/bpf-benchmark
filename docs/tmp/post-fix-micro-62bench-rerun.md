# Post-fix Micro 62-Bench Rerun

## Methodology

- Date: `2026-03-13`
- Suite target: `config/micro_pure_jit.yaml` (`62` benchmarks = `56` prior + `6` new per-form isolation rows)
- JSON rows currently present: `62`
- Runtime: `kernel` vs `kernel-recompile` in the framework VM
- Collection mode: one benchmark per VM boot via `docs/tmp/kernel_recompile_micro_resume.py`
- Guest kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- Runner: `micro/build/runner/micro_exec`
- Scanner: `scanner/build/bpf-jit-scanner`
- `cond_select_dense` was resized from an `8192`-byte staged payload to `3328` bytes (`104` CMOV sites) before this rerun because the guest XDP `test_run` path exposes only `3512` payload bytes past the 8-byte result prefix; the original form always aborted in-kernel and could not produce a valid pair.
- Guest kernel release: `7.0.0-rc2-g05a1845490ed-dirty`
- Warmups / iterations / repeat: `2 / 2 / 500`
- Output JSON: `/home/yunwei37/workspace/bpf-benchmark/micro/results/post_fix_micro_62bench_20260313.json`

## Headline Numbers

| Metric | This rerun (62) | Shared-56 subset in this rerun | #143 post-cmov-fix (56) | Delta vs #143 |
| --- | ---: | ---: | ---: | ---: |
| Benchmarks total | `62` | `56` | `56` | `+0` |
| Valid pairs | `61` | `55` | `56` | `-1` |
| Applied pairs | `14` | `11` | `11` | `+0` |
| Overall geomean (stock / recompile) | `0.966x` | `0.985x` | `1.007x` | `-2.2%` |
| Applied-only geomean | `1.006x` | `1.039x` | `0.986x` | `+5.4%` |
| Wins / losses / ties | `27 / 32 / 2` | `26 / 27 / 2` | `29 / 26 / 1` | `-` |

- The direct #143 comparison should use the `Shared-56 subset` column; the `This rerun (62)` column includes the six new per-form rows and is not denominator-matched.
- Overall and applied-only geomeans above are `stock / recompile`, so values above `1.000x` mean recompile is faster.

## Key Findings

- Denominator-matched against `#143`, the shared-56 subset regressed on overall geomean (`1.007x -> 0.985x`) but improved on applied-only geomean (`0.986x -> 1.039x`).
- The six new per-form rows are net-negative in this run (`0.809x` geomean overall); only `rotate_dense` is a win, while `cond_select_dense`, `extract_dense`, and the three currently-unapplied rows all lose.

## Invalid Rows

- Invalid pairs in this rerun: `1`.
- `load_byte` failed on both runtimes during warmup because `sudo` in the guest reported `micro/build/runner/micro_exec: command not found`; this is a harness/path issue, not a recompile-policy failure.

## New Per-Form Isolation Benchmarks

- New-benchmark rows present in this JSON: `6 / 6`.
- New-benchmark valid/apply counts: `6 / 6` valid, `3` applied.
- New-benchmark geomean (stock / recompile): `0.809x` overall, `0.894x` applied-only.

| Benchmark | Family | Applied | Sites | Site mix | Stock median | Recompile median | Stock / recompile | Status |
| --- | --- | ---: | ---: | --- | ---: | ---: | ---: | --- |
| `cond_select_dense` | `select-diamond` | `yes` | `1` | `cmov=1` | `56 ns` | `71.5 ns` | `0.783x` | `loss` |
| `rotate_dense` | `rotate-canonical` | `yes` | `5` | `rotate=5` | `234.5 ns` | `202 ns` | `1.161x` | `win` |
| `addr_calc_stride` | `addr-calc` | `no` | `0` | `none` | `134.5 ns` | `200.5 ns` | `0.671x` | `loss` |
| `extract_dense` | `bitfield-extract` | `yes` | `1` | `extract=1` | `147 ns` | `187 ns` | `0.786x` | `loss` |
| `endian_swap_dense` | `endian-fusion` | `no` | `0` | `none` | `144.5 ns` | `185.5 ns` | `0.779x` | `loss` |
| `branch_flip_dense` | `branch-flip` | `no` | `0` | `none` | `178 ns` | `237.5 ns` | `0.749x` | `loss` |

Current policy-match notes for the new rows:
- `cond_select_dense`: aggregate policy insns missed live program; kept 1 of 104 eligible rules
- `rotate_dense`: aggregate policy insns missed live program; kept 5 of 256 eligible rules
- `addr_calc_stride`: policy file currently empty; policy selected 0 of 8 eligible rules
- `extract_dense`: aggregate policy insns missed live program; kept 1 of 512 eligible rules
- `endian_swap_dense`: policy file currently empty; policy selected 0 of 256 eligible rules
- `branch_flip_dense`: aggregate policy insns missed live program; policy selected 0 of 255 eligible rules

## Top Wins And Losses

| Top wins | Ratio | Applied | Sites |
| --- | ---: | ---: | ---: |
| `fixed_loop_small` | `1.505x` | `no` | `0` |
| `packet_parse_vlans_tcpopts` | `1.400x` | `no` | `0` |
| `local_call_fanout` | `1.328x` | `no` | `0` |
| `multi_acc_4` | `1.316x` | `no` | `0` |
| `cmov_dense` | `1.277x` | `yes` | `26` |

| Top losses | Ratio | Applied | Sites |
| --- | ---: | ---: | ---: |
| `packet_rss_hash` | `0.457x` | `no` | `0` |
| `addr_calc_stride` | `0.671x` | `no` | `0` |
| `smallmul_strength_reduce` | `0.727x` | `no` | `0` |
| `memory_pair_sum` | `0.727x` | `no` | `0` |
| `const_fold_chain` | `0.739x` | `no` | `0` |
