# Project Final Review — 2026-03-13

## 1. Project Structure

```
bpf-benchmark/
├── micro/          # Isolated micro-benchmark suites (62 benchmarks, YAML-driven)
├── corpus/         # Real-world corpus configs, 23-project fetch/build/measure pipeline
├── e2e/            # End-to-end deployment benchmarks (Tracee, bpftrace, scx, xdp)
├── scanner/        # Standalone bpf-jit-scanner CLI (scan/enumerate/apply/generate-policy)
├── config/         # micro_pure_jit.yaml + config/ablation/ ablation YAML files
├── docs/           # Research plans, paper, tmp experiment notes (organized by date)
├── vendor/         # Kernel submodules (llvmbpf, libbpf, linux-framework, bpftool)
├── legacy/         # Historical userspace benchmark code (ubpf/rbpf/wasmtime)
└── tests/          # Self-test scripts
```

**Assessment: CLEAR.** The three-layer model (micro/corpus/e2e) maps cleanly to directory structure. No confusing top-level clutter. `docs/tmp/` is organized by date subdirectory (`2026-03-07` through `2026-03-13`) plus `active/` for ongoing documents.

## 2. Git Status

```
Branch: main (up to date with origin/main)
Modified: micro/results/smoke_authoritative_20260313.json (from smoke test run during review)
Untracked: micro/results/per_form_ablation_20260313/ablation_{branch_flip,cmov,endian,extract,lea}.json
```

**Assessment: MOSTLY CLEAN.** The 5 untracked ablation JSONs are committed as part of this review. The smoke JSON modification is benign (timestamp update from re-running smoke). No stale scripts, no loose temp files at root.

## 3. Make Targets

All checked:

- `make help` — OK, shows all targets with descriptions
- `make verify-build` — OK (`[verify-build] OK`); warning that kernel source is newer than bzImage (minor, bzImage at 14:42 still works)
- `make smoke` — OK (exec median ~79ns host, result 12345678 correct)

**Assessment: ALL WORKING.** No target failures.

## 4. CLAUDE.md vs Actual State

CLAUDE.md is accurate and up-to-date as of the last cleanup commit (e61c9e8):

- Benchmark count: 62 (correct, `config/micro_pure_jit.yaml` has 62 entries)
- Makefile-first workflow: correctly documented
- `config/ablation/` entry: present
- `corpus/config/macro_corpus.yaml` path: correct
- `legacy/user_bpf_benchmark/`: correct (was fixed in cleanup)
- Codex/Sonnet division of labor: accurate

**Assessment: ACCURATE.**

## 5. README.md Status

Root `README.md` is accurate. References to `micro/driver.py`, `e2e/run.py`, `corpus/build_expanded_corpus.py` all exist and compile cleanly.

**Fixed during review:** `micro/results/README.md` was stale — described `pure_jit_authoritative_YYYYMMDD.json` naming that was never used; actual files are named `micro_62bench_authoritative_YYYYMMDD.json`. Updated to match reality.

**Fixed during review:** `e2e/results/README.md` was missing `tracee.latest.json` and `xdp_forwarding.latest.json` from its alias list; both now added.

## 6. Plan Doc Link Integrity

**Fixed during review:** One broken link was found:
- `docs/tmp/endian-bflip-vm-verification.md` — referenced in #168 description and task table as "pending". File was never produced. Updated both references to "VM verification cancelled — static analysis was sufficient."

After fix: **0 broken links.** All `docs/tmp/**/*.md` references in `docs/kernel-jit-optimization-plan.md` resolve to existing files.

## 7. scanner/README.md Accuracy

**Assessment: ACCURATE AND COMPLETE.** README documents:
- All 5 subcommands: `scan`, `enumerate`, `apply`, `generate-policy`, `compile-policy`, `dump`
- The 8 canonical optimization forms with flags
- v3 policy YAML format
- Cost model (3 default rules: skip same-size, skip cmov, skip dense >128 sites)
- Full family flag reference
- Source layout

No inaccuracies found.

## 8. Results Directory State

### micro/results/
- 9 JSON files (excluding archive/)
- 2 `*.latest.json` symlinks: `smoke.latest.json`, `vm_micro_smoke.latest.json`
- 20 markdown reports (supporting artifacts — by convention, these live here)
- Authoritative full-suite result: `micro_62bench_authoritative_20260313.json`

### corpus/results/
- 18 JSON files (excluding archive/)
- 5 `*.latest.json` symlinks all valid
- Note: `corpus/results/` is gitignored by default; files are checked in explicitly

### e2e/results/
- 9 JSON files (excluding archive/)
- 4 `*.latest.json` symlinks, all valid

**Assessment: ORGANIZED.** Naming convention is consistent across all three layers.

## 9. Python Code Quality

All key files compile cleanly with `py_compile`:

| File | Status |
|------|--------|
| `micro/run_micro.py` | OK |
| `micro/benchmark_catalog.py` | OK |
| `micro/input_generators.py` | OK |
| `micro/driver.py` | OK |
| `micro/compare_results.py` | OK |
| `micro/results_layout.py` | OK |
| `micro/summarize_rq.py` | OK |
| `e2e/run.py` | OK |
| `corpus/policy_utils.py` | OK |
| `corpus/run_macro_corpus.py` | OK |
| `corpus/build_expanded_corpus.py` | OK |
| `corpus/directive_census.py` | OK |
| `corpus/run_corpus_perf.py` | OK |
| `corpus/run_corpus_v5_framework.py` | OK |
| `corpus/run_tracing_corpus_vm.py` | OK |

**No Python compile errors found.** The only `HACKBENCH_TIME_RE` name in first-party code (`e2e/cases/scx/case.py:54`) is a regex constant naming pattern, not a HACK marker.

## 10. TODO/FIXME/HACK Residuals

Searched all first-party `.py`/`.cpp`/`.c` files (excluding `vendor/`, `corpus/repos/`, `legacy/`):

- **0 critical TODOs/FIXMEs** in first-party Python or scanner C++ code
- One `HACKBENCH_TIME_RE` constant in `e2e/cases/scx/case.py` — this is a regex variable name referencing the `hackbench` tool, not a code smell
- All `corpus/repos/` TODOs are in third-party upstream code (bcc, katran, linux-selftests) — not actionable

**Assessment: CLEAN.**

## 11. Performance Data Summary (Authoritative)

### Pure-JIT (llvmbpf vs kernel, 56-bench strict suite)
- llvmbpf/kernel geomean: **0.609x** (llvmbpf is 1.64x faster)
- llvmbpf wins: 53/56

### BpfReJIT Micro (62-bench, post-BEXTR-fix, build #41)
From `micro_62bench_authoritative_20260313.json`:
- Overall stock/recompile geomean: **1.0035x** (recompile marginally faster)
- Applied-only geomean: **0.9417x** (17 applied benchmarks)
- Valid pairs: 62/62
- Wins: 29, Losses: 29, Ties: 4
- Top win: `cmov_dense` 1.729x, `log2_fold` 1.206x, `addr_calc_stride` 1.053x
- Notable regressions: `endian_swap_dense` 0.640x (same-size I-cache cost), `extract_dense` 0.677x (dense BEXTR overhead), `bpf_call_chain` 0.779x

From `micro_62bench_build40_policy_optimized_20260313.json` (policy-aware, build #40):
- stock/recompile geomean: **1.006x** (62/62 pairs)

### BpfReJIT Corpus (post-fix, 20260313)
From `corpus/results/corpus_recompile_authoritative_20260313.json`:
- Programs measured: 152/166
- Applied programs: 39
- Exec ratio geomean (stock/recompile): **1.046x** (recompile 4.6% faster)
- Exec ratio median: 1.027x
- Improvements: 81, Regressions: 49
- Code size ratio geomean: 1.0019x (near-zero size change)
- Site totals: ROTATE 1840, ENDIAN 874, CMOV 446, WIDE 342, BRANCH_FLIP 282, BITFIELD 86

### E2E Tracee (post-BEXTR-fix, kernel 7.0.0-rc2-gdaca445b1)
From `e2e/results/tracee_authoritative_20260313.json`:
- exec_storm throughput: 160.5 → 170.6 bogo-ops/s (**+6.3%**)
- file_io IOPS: 4332.3 → 4635.6 (**+7.0%**)
- network req/s: 4871.2 → 4941.1 (**+1.4%**)
- Geometric mean speedup: **1.049x**
- Applied programs: 11/13

### Recompile Overhead
- Scanner scan: 4.32ms
- Kernel syscall: 29.89μs

## 12. Open Issues (Priority Order)

From `docs/kernel-jit-optimization-plan.md`:

1. **Policy iteration** — applied-only geomean currently 0.942x; goal >1.0x. Main blockers: cond_select_dense (CMOV predictable-branch), extract_dense (dense BEXTR site overhead), endian_swap_dense (same-size I-cache). Script: `docs/tmp/run-policy-iteration.sh`.
2. **BEXTR without-copy fix** — `emit_bitfield_extract_core` needs `src!=dst` guard to avoid 9B vs 6B code growth. Tracked as note in `docs/tmp/2026-03-13/bextr-without-copy-fix.md`.
3. **Corpus rerun** — `corpus_recompile_authoritative_20260313.json` exists but was run before BEXTR fix confirmed; validity needs checking.
4. **More E2E workloads** — only Tracee has strong post-ReJIT data; Tetragon is smoke-only.
5. **ARM64 backend** (#59), ZERO_EXTEND directive (#58), daemon mode (#171), native code analysis (#172) — longer-term gaps.

## Summary

The project is in a **good state** after the recent cleanup commits. Build is functional, all Python files compile, directory structure is logical, documentation is mostly accurate. Three minor doc inconsistencies were fixed during this review (micro/results README naming, e2e/results README completeness, two broken plan-doc link references). The 5 untracked ablation JSON files were committed. The main outstanding work is policy optimization and corpus rerun to close the applied-only geomean gap.
