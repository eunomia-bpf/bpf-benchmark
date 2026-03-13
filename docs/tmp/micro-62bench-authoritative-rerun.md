# 62-Benchmark Authoritative Micro Rerun

## Methodology

- Plan reference read first: `docs/kernel-jit-optimization-plan.md`
- Kernel image: `vendor/linux-framework/arch/x86/boot/bzImage`
- Kernel version context: `7.0.0-rc2-g05a1845490ed-dirty`
- Suite: `config/micro_pure_jit.yaml`
- Active benchmarks collected: `62`
- Runtimes compared: `kernel` vs `kernel-recompile`
- Parameters: `--warmups 2 --iterations 2 --repeat 500`
- Runner: `docs/tmp/kernel_recompile_micro_resume.py`
- Isolation model: one benchmark per VM boot via `vng`
- Output JSON: `micro/results/micro_62bench_authoritative_20260313.json`
- Per-benchmark artifacts: `docs/tmp/micro_62bench_authoritative_per_bench/`
- Live log: `docs/tmp/micro_62bench_authoritative_20260313.run.log`

Interpretation: all reported ratios are `stock / recompile`, so values greater than `1.0x` mean the recompiled kernel is faster.

## Headline Numbers vs #160

Comparison target: `micro/results/post_fix_micro_62bench_20260313.json`

| Metric | #160 existing | Authoritative rerun | Delta / note |
| --- | ---: | ---: | --- |
| Benchmarks total | 62 | 62 | unchanged |
| Valid pairs | 61 | 62 | `+1` |
| Invalid pairs | 1 | 0 | fixed |
| Applied pairs | 14 | 17 | `+3` |
| Overall geomean | 0.9660x | 1.0035x | from overall slowdown to slight speedup |
| Applied-only geomean | 1.0064x | 0.9417x | applied set regressed |
| Wins / losses / ties | 27 / 32 / 2 | 29 / 29 / 4 | slightly more balanced |

Main readout: the authoritative rerun is marginally net-positive overall (`1.0035x`), but the applied subset is clearly net-negative (`0.9417x`). The applied-pair count increased from `14` to `17` because `addr_calc_stride`, `endian_swap_dense`, and `branch_flip_dense` now show applied recompile sites in the final dataset.

## Per-Form Benchmarks

| Benchmark | Form | Stock median | Recompile median | Ratio | #160 ratio | Applied sites | Result |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `rotate_dense` | rotate | 243.5 ns | 230.0 ns | 1.0587x | 1.1609x | 256 | win |
| `cond_select_dense` | cmov/select | 87.0 ns | 99.5 ns | 0.8744x | 0.7832x | 104 | loss |
| `addr_calc_stride` | lea/addr-calc | 158.5 ns | 150.5 ns | 1.0532x | 0.6708x | 8 | win |
| `extract_dense` | bitfield extract | 148.5 ns | 219.5 ns | 0.6765x | 0.7861x | 512 | loss |
| `endian_swap_dense` | endian fusion | 129.0 ns | 201.5 ns | 0.6402x | 0.7790x | 256 | loss |
| `branch_flip_dense` | branch flip | 258.5 ns | 305.5 ns | 0.8462x | 0.7495x | 255 | loss |

Per-form summary:

- Positive: `rotate_dense` and `addr_calc_stride`
- Negative: `cond_select_dense`, `extract_dense`, `endian_swap_dense`, `branch_flip_dense`
- Best per-form outcome: `rotate_dense` at `1.0587x`
- Worst per-form outcome: `endian_swap_dense` at `0.6402x`

## Top Wins and Losses

Applied-only wins are the most relevant view here because they isolate cases where the recompile path actually changed code.

### Top Applied Wins

| Benchmark | Ratio | Applied sites |
| --- | ---: | ---: |
| `cmov_dense` | 1.7286x | 26 |
| `log2_fold` | 1.2064x | 3 |
| `bounds_ladder` | 1.1228x | 4 |
| `rotate_dense` | 1.0587x | 256 |
| `addr_calc_stride` | 1.0532x | 8 |

### Top Applied Losses

| Benchmark | Ratio | Applied sites |
| --- | ---: | ---: |
| `endian_swap_dense` | 0.6402x | 256 |
| `extract_dense` | 0.6765x | 512 |
| `bpf_call_chain` | 0.7788x | 3 |
| `switch_dispatch` | 0.8404x | 3 |
| `branch_flip_dense` | 0.8462x | 255 |

Interpretation: the applied-only regression is dominated by the dense new forms, especially `extract_dense` and `endian_swap_dense`. `cmov_dense` remains the strongest positive result by a wide margin.

## Issues Encountered

- The first invocation used the script default `--timeout 300` and aborted on `mixed_alu_mem` with uncaught `subprocess.TimeoutExpired`.
- Resume worked as intended. Re-running the same collection with `--timeout 900` resumed from `23` completed benchmarks and finished the full `62/62`.
- The final authoritative JSON contains `62` benchmarks, `62` valid pairs, and `0` synthetic failure rows.

## Final Verification

- Output JSON benchmark count: `62`
- Output JSON valid pairs: `62`
- Output JSON applied pairs: `17`
- Overall geomean: `1.0035267416761544x`
- Applied-only geomean: `0.9416527179875053x`
