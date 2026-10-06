# Kernel Fixed Baselines Test Results

**Date:** 2026-03-10

**Kernel branch:** `vendor/linux` -> `jit-fixed-baselines`

**Committed kernel change:** `1572a4ddb` (`kernel-fixed-baselines: unconditional heuristics for ROTATE/WIDE_MEM/LEA/CMOV`)

**Builds used**

- Fixed-all kernel: `CONFIG_BPF_JIT_FIXED_ROTATE=y`, `CONFIG_BPF_JIT_FIXED_WIDE_MEM=y`, `CONFIG_BPF_JIT_FIXED_LEA=y`, `CONFIG_BPF_JIT_FIXED_CMOV=y`
- Stock comparison kernel: all four `CONFIG_BPF_JIT_FIXED_*` options disabled
- `micro_exec` rebuilt before the VM runs

**Raw parsed outputs**

- `docs/tmp/kernel-fixed-baselines-fixed-all.jsonl`
- `docs/tmp/kernel-fixed-baselines-stock.jsonl`

## Full Comparison Table

| Program | Stock exec_ns | Stock jited_len | Fixed-all exec_ns | Fixed-all jited_len | Delta exec_ns | Delta % | Delta jited_len |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `rotate64_hash` | 143 | 3559 | 119 | 2381 | -24 | -16.8% | -1178 |
| `packet_rss_hash` | 67 | 1021 | 57 | 870 | -10 | -14.9% | -151 |
| `load_byte_recompose` | 409 | 422 | 356 | 410 | -53 | -13.0% | -12 |
| `stride_load_4` | 444 | 517 | 413 | 487 | -31 | -7.0% | -30 |
| `stride_load_16` | 437 | 517 | 499 | 487 | +62 | +14.2% | -30 |
| `log2_fold` | 258 | 648 | 331 | 646 | +73 | +28.3% | -2 |

## Findings

### 1. Fixed-all vs stock

- `rotate64_hash` and `packet_rss_hash` both improved materially under fixed-all, with large native-code shrinkage. This matches the expected ROTATE story from [docs/tmp/v4-round3-test-results.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/v4-round3-test-results.md).
- `load_byte_recompose` improved by `-13.0%` with `jited_prog_len 422 -> 410`, which closely matches the v4 WIDE_MEM summary in [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L524).
- `stride_load_4` also improved and shrank code, but the runtime gain (`-7.0%`) is weaker than the v4 WIDE_MEM summary (`-14%`).
- `stride_load_16` did **not** match the expected LEA-only win. In this fixed-all run it shrank native code (`517 -> 487`) but got slower (`+14.2%`). That means fixed-all does not cleanly reproduce the prior LEA result on this benchmark.

### 2. Go/No-Go Test: fixed CMOV hurts `log2_fold`

- `log2_fold` regressed from `258 ns` to `331 ns` (`+28.3%`) under fixed-all.
- Result correctness stayed intact (`result=9`), so this is a profitability regression, not a semantic bug.
- This is the critical falsification result from the experiment design in [docs/tmp/kernel-fixed-baselines-design.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/kernel-fixed-baselines-design.md): unconditional CMOV hurts a predictable-branch workload, so a fixed kernel heuristic cannot replace a policy-controlled framework in general.

### 3. Does fixed-all match the v4 framework results for ROTATE/WIDE/LEA?

- **ROTATE:** Yes in direction and roughly in magnitude. Fixed-all reproduced the expected code-size reductions and runtime improvements on both rotate benchmarks.
- **WIDE_MEM:** Mostly yes. `load_byte_recompose` is essentially a match; `stride_load_4` still improves, but less than the v4 summary.
- **LEA:** No clear match from this fixed-all run. `stride_load_16` regressed despite smaller native code, so fixed-all does not reproduce the earlier LEA-only outcome here.

### 4. Correctness

- All 12 VM runs completed successfully; no guest boot failure occurred.
- All fixed-all runs returned the same observable program result as stock:
  - `rotate64_hash`: `2666935177028490406`
  - `packet_rss_hash`: `11016707074064960918`
  - `load_byte_recompose`: `1253018829653002637`
  - `stride_load_4`: `1982929226459564480`
  - `stride_load_16`: `17112594108265627168`
  - `log2_fold`: `9`
- These values match the expected outputs already seen in the earlier v4 benchmark records for the same programs, where available.

### 5. `xlated_prog_len` invariant

The verifier output length stayed unchanged between stock and fixed-all for every tested program, so the fixed baselines only changed native emission:

| Program | Stock xlated_prog_len | Fixed-all xlated_prog_len | Delta |
| --- | ---: | ---: | ---: |
| `rotate64_hash` | 7984 | 7984 | 0 |
| `packet_rss_hash` | 2088 | 2088 | 0 |
| `load_byte_recompose` | 744 | 744 | 0 |
| `stride_load_4` | 920 | 920 | 0 |
| `stride_load_16` | 920 | 920 | 0 |
| `log2_fold` | 1112 | 1112 | 0 |

## Bottom Line

- The fixed baselines successfully reproduce the basic ROTATE and WIDE_MEM story.
- The fixed CMOV baseline fails the policy-sensitivity test: it hurts `log2_fold` substantially.
- The fixed-all result on `stride_load_16` does not cleanly match the earlier LEA expectation, so the fixed-all configuration is not simply "v4 results, but hardcoded."
