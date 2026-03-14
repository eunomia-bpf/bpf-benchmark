# Final Review: Post-All-Changes (2026-03-14)

## 1. Git Status

Branch: `main`, up to date with `origin/main`.

Unstaged changes:
- 7 modified ablation YAML files in `config/ablation/`
- 1 modified smoke result file (`micro/results/smoke_authoritative_20260313.json`)

Untracked files:
- `config/ablation/policies/` (new ablation policy directory)
- `docs/tmp/active/deep-improvement-review.md`
- `micro/results/per_form_ablation_20260313/`

Recent commits (last 15): clean chain of cleanup, unification, and validation work.

## 2. Build System

### `make help` -- OK
All targets documented. Help output covers build, test/smoke, benchmark (VM), and utility targets with tunable parameters and POLICY variants.

### `make verify-build` -- OK
```
Kernel:     7de19ef03
Scanner:    07f492c
micro_exec: Mar 13 20:01
bzImage:    18M Mar 13 20:02
POLICY:     default
[verify-build] OK
```

### `make smoke` -- OK
Runs `driver.py suite --runtime llvmbpf --bench simple` successfully. Result: `compile median 6.059 ms | exec median 62 ns | result 12345678`.

## 3. Python Compilation Check

All key Python files compile without errors:
- `micro/driver.py` -- OK
- `micro/run_micro.py` -- OK
- `micro/compare_results.py` -- OK
- `micro/benchmark_catalog.py` -- OK
- `micro/input_generators.py` -- OK
- `e2e/run.py` -- OK
- `corpus/policy_utils.py` -- OK
- `e2e/common/__init__.py` -- OK
- `e2e/common/vm.py` -- OK

## 4. Authoritative Micro Results Analysis

**Data file**: `micro/results/vm_micro_authoritative_20260314.json`

**Parameters**: 3 iterations, 3 warmups, 500 repeat. VM environment (virtme-ng), kernel 7.0.0-rc2-g7de19ef03692, Intel Core Ultra 9 285K.

### Correct Numbers (verified from actual data)

| Metric | Value |
|--------|-------|
| Total benchmarks | 62 |
| Recompile applied (recompile.applied=True) | **16** |
| Overall K/R geomean | **1.054x** |
| Applied-only K/R geomean (16 benchmarks) | **1.074x** |
| Regressors (K/R < 0.98) | **14** |

### CRITICAL: Plan Doc Had Wrong Numbers (FIXED)

The plan doc (line 12, lines 65-66) previously claimed:
- "36 applied geomean 1.157x, 19 regressors"

Actual verified numbers:
- **16 applied, 1.074x applied geomean, 14 regressors**

The "36" was likely counting benchmarks with any scan sites (32 have scan sites > 0), but only 16 have `recompile.applied=True`. The "1.157x" does not match any valid computation from the data.

**Fix applied**: Updated plan doc lines 12, 65, 66 with correct numbers.

### Applied Benchmarks (16 total)

| Benchmark | K/R | Sites |
|-----------|-----|-------|
| rotate_dense | 1.902x | 256 rotate |
| cmov_dense | 1.462x | 26 rotate+cmov |
| cmov_select | 1.157x | 1 cmov |
| log2_fold | 1.177x | 3 wide |
| mixed_alu_mem | 1.065x | 3 mixed |
| binary_search | 1.058x | 3 mixed |
| multi_acc_4 | 1.049x | 3 mixed |
| switch_dispatch | 1.013x | 3 mixed |
| branch_dense | 1.007x | 7 branch_flip |
| bounds_ladder | 1.000x | 4 mixed |
| bpf_call_chain | 0.982x | 3 mixed |
| large_mixed_500 | 0.975x | 3 mixed |
| multi_acc_8 | 0.970x | 4 mixed |
| addr_calc_stride | 0.947x | 8 lea |
| branch_flip_dense | 0.922x | 255 branch_flip |
| memcmp_prefix_64 | 0.850x | 3 mixed |

### Noise Warning

22 non-applied benchmarks show |K/R - 1.0| > 10%, including:
- `simple_packet`: K/R=1.71x (K=12ns, R=7ns) -- pure noise at sub-15ns scale
- `local_call_fanout`: K/R=0.69x (K=139ns, R=202ns) -- 45% regression with no recompile
- `struct_field_cluster`: K/R=1.38x (K=101ns, R=73ns) -- 38% speedup with no recompile

These are VM noise artifacts from only 3 iterations. The overall 1.054x geomean is inflated by noise on non-applied benchmarks. For applied benchmarks, the 1.074x is also affected but less so since those programs actually have different native code.

## 5. CLAUDE.md vs Reality

| Item | Status |
|------|--------|
| Legacy dir path (`legacy/user_bpf_benchmark/`) | OK (exists) |
| Config paths (`config/micro_pure_jit.yaml`, `corpus/config/macro_corpus.yaml`) | OK |
| Archive dir (`micro/programs/archive/runtime/`) | OK (exists) |
| Benchmark count "62 benchmarks as of March 13, 2026" | OK (62 in YAML, 62 in results) |
| `micro/summarize_rq.py` | OK (exists) |
| `make` as canonical entry point | OK (documented) |
| Ablation config (`config/ablation/`) | OK (exists, documented) |
| Runner subcommands (run-llvmbpf, run-kernel) | OK (also has list-programs, minor) |

**No issues found in CLAUDE.md.**

## 6. Scanner README vs Reality

Scanner `--help` output matches README documentation:
- All 6 subcommands documented: `scan`, `enumerate`, `apply`, `generate-policy`, `compile-policy`, `dump`
- All 8 family flags documented correctly
- Cost model rules documented
- v3 policy format documented
- Layout section accurate

**No issues found in scanner README.**

## 7. Plan Doc Broken References

13 broken `docs/tmp/` references found in plan doc:

1. `docs/tmp/bpftrace-e2e-results.json` -- never created
2. `docs/tmp/cmov_extract_blind_apply_validation.log` -- deleted during cleanup
3. `docs/tmp/cmov_extract_policy_validation.log` -- deleted during cleanup
4. `docs/tmp/corpus-8families-persection.json` -- moved to corpus/results/
5. `docs/tmp/corpus-runnability-results.json` -- deleted during cleanup
6. `docs/tmp/corpus-v2-policy-smoke-20260312.{json,md}` -- deleted during cleanup
7. `docs/tmp/gap_decomposition.py` -- deleted during cleanup
8. `docs/tmp/kernel_recompile_micro_resume.py` -- deleted during cleanup
9. `docs/tmp/micro_diag/validation_v2.json` -- deleted during cleanup
10. `docs/tmp/tetragon-e2e-results.json` -- never created
11. `docs/tmp/tracee-real-e2e-host-smoke.json` -- deleted during cleanup
12. `docs/tmp/tracee-real-e2e-vm-smoke.json` -- deleted during cleanup

These are all historical references in completed task entries. The plan doc rule is "NEVER delete old entries" so these broken paths are expected artifacts of the cleanup that moved/deleted files. They don't affect active functionality.

Also: `corpus/results/corpus_post_fix_build39_20260313.json` referenced in plan doc does not exist. The actual file is `corpus/results/corpus_recompile_authoritative_20260313.json`.

## 8. Remaining Issues Summary

### P0: Data Quality Warning
The authoritative 20260314 micro results have significant VM noise (3 iterations only). Non-applied benchmarks show up to 71% variation. The overall 1.054x geomean is not reliable enough for paper-quality claims. A proper run with 10+ iterations and CPU pinning is needed for final paper numbers.

### P1: Stale Untracked Files
- `config/ablation/policies/` -- new directory, should be committed if keeping ablation infrastructure
- `micro/results/per_form_ablation_20260313/` -- ablation results, should be committed or gitignored
- 7 modified ablation YAML files -- should be committed or reverted

### P2: Broken Plan Doc References (13)
Historical references to deleted files. Low priority -- they're in completed task entries and don't affect functionality. Could be annotated with "(file removed during cleanup)" for clarity.

### P3: Corpus Data File Reference
Plan doc references non-existent `corpus/results/corpus_post_fix_build39_20260313.json`. Actual file is `corpus/results/corpus_recompile_authoritative_20260313.json`.

## 9. What's Working Well

- Build system is clean and functional (make help/verify-build/smoke all pass)
- Python codebase compiles cleanly
- CLAUDE.md accurately reflects project structure
- Scanner README accurately reflects scanner capabilities
- 62-benchmark suite is properly configured and runs end-to-end
- E2E Tracee data is present and valid (11/13 applied, exec_storm +6.28%)
- Policy infrastructure (default, all-apply, baseline variants) is properly organized
