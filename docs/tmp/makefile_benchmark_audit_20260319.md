# Makefile + Benchmark Pipeline Audit

Date: 2026-03-19

Scope:
- Requested files: `CLAUDE.md`, root `Makefile`, `micro/Makefile`, `micro/driver.py`, `micro/_driver_impl_run_micro.py`, `docs/kernel-jit-optimization-plan.md` (§5, §6.4), `config/micro_pure_jit.yaml`
- Additional audit context: `micro/orchestrator/*`, selected `corpus/` drivers, `micro/run_corpus_tracing.sh`
- Constraint observed: no kernel code changes, no commit, no branch

## Executive Summary

- The active root Makefile pipeline is mostly coherent and matches the current micro defaults.
- I fixed one real footgun: `make -C micro clean` was deleting checked-in authoritative JSON under `micro/results/`.
- I fixed the local smoke usability gap: `make smoke` now prints a one-line human-readable summary to stdout in addition to writing JSON.
- I fixed several stale result-path defaults that still pointed at removed `*.latest.json` aliases.
- The active micro/corpus pipeline is effectively v3-only; I did not find active v1/v2 policy-schema usage in the audited driver path.
- The paper’s “62 benchmarks” claim is correct, but the stronger claim that the active micro suite currently represents all 8 canonical forms is overstated for current x86_64 micro artifacts: scanner-visible `ZERO_EXT_ELIDE` sites are still `0`.
- Verification after fixes: `make -C micro micro_exec` passed, `make smoke` passed, `make scanner-tests` failed in scanner unit tests unrelated to the files changed here.

## Fixes Applied

- `micro/Makefile`
  - `clean` now deletes only disposable files under `micro/results/dev/`, not authoritative checked-in JSON.
  - Removed two unused local variables: `BPFTOOL_BIN`, `RUNNER_BIN`.
- `Makefile`
  - `make smoke` now prints `SMOKE OK: ...` with benchmark name, runtime, exec ns, compile ms, and result.
  - Removed unused `SCANNER_TEST_PATH`.
- `corpus/run_real_world_exec_time.py`
  - Default input now resolves the newest existing authoritative `real_world_code_size_*.json` instead of the removed `real_world_code_size.latest.json`.
  - Added a clear missing-input error.
  - Updated help/report text to stop referring to removed aliases.
- `corpus/_driver_impl_run_macro_corpus.py`
  - Default output now uses authoritative dated output instead of `macro_corpus.latest.json`.
- `micro/summarize_rq.py`
  - Default results lookup now prefers authoritative candidates instead of a removed `pure_jit.latest.json` alias.
- `micro/orchestrator/inventory.py`
  - Default corpus build-report discovery now checks authoritative `expanded_corpus_build_*.json` candidates instead of only `expanded_corpus_build.latest.json`.
- `corpus/_driver_impl_run_corpus_tracing_exec.py`
  - Same authoritative-candidate fix for corpus build-report discovery.
- `corpus/_driver_impl_run_corpus_perf.py`
  - Removed clearly-unused local wrappers.
  - Updated stale help text about `expanded_corpus_build.latest.json`.
- `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
  - Removed clearly-unused local wrappers.
- `corpus/_driver_impl_run_corpus_tracing.py`
  - Updated stale help text about `expanded_corpus_build.latest.json`.
- `corpus/_driver_impl_run_tracing_corpus_vm.py`
  - Updated stale help text about `expanded_corpus_build.latest.json`.
- `micro/run_corpus_tracing.sh`
  - Removed hardcoded `/home/yunwei37/workspace/.venv` activation path; now probes common relative/home venv locations.

Syntax check:
- `python3 -m py_compile` passed for all touched Python files.

## 1. Makefile Audit

### Confirmed Good

- Root defaults are internally consistent with the active micro suite:
  - Root `Makefile` sets `ITERATIONS ?= 10`, `WARMUPS ?= 2`, `REPEAT ?= 200`.
  - `config/micro_pure_jit.yaml` defaults and runtime repeats also use `10 / 2 / 200`.
- Root file-based dependencies are reasonable:
  - `vm-micro`, `vm-corpus`, and `vm-e2e` require scanner and built artifacts.
  - `smoke` only depends on `micro_exec` and BPF objects, which is correct for llvmbpf-only smoke.
- Root paths are already relative/repo-root based; I did not find broken hardcoded absolute paths in the root Makefile.

### Fixed

- `micro/Makefile:73-78`
  - `clean` previously ran `rm -f $(ROOT_DIR)/results/*.json`, which deleted authoritative checked-in JSON such as `micro/results/vm_micro_authoritative_20260318.json`.
  - This directly violated the results layout described in `CLAUDE.md` and the plan’s result-directory cleanup work.

- `Makefile:330-337`
  - `make smoke` previously produced only JSON output.
  - It now prints a concise summary line after the JSON is written.

### Dead / Redundant / Report-Only

- `micro/Makefile:22`
  - `deps` is largely redundant with `all`; the only extra work is `vendor_bpftool`.
  - It is not referenced by the root Makefile. It is still referenced indirectly by config/docs, so I did not remove it.

- `micro/Makefile:20` and `micro/Makefile:58-66`
  - `all` always builds `directive_hint`.
  - I found no active root Makefile target or active Python driver path that consumes `micro/build/tools/directive_hint`.
  - It looks like a legacy/dev helper rather than part of the canonical benchmark pipeline.
  - I did not remove it because docs still mention it and it still builds cleanly.

### Missing Dependency / Doc Drift

- Root `Makefile:397-416` runs `tracee`, `tetragon`, `bpftrace`, `scx`, and `katran`.
- `docs/kernel-jit-optimization-plan.md`
  - Top-of-file summary still says Katran is a future replacement target.
  - §6.4 `make vm-e2e` description still omits Katran.
- This is documentation drift, not a Makefile bug.

## 2. Benchmark Pipeline Audit

### Active Entry Points

- `micro/driver.py` is the real dispatch point for active benchmarking:
  - `suite` -> micro or macro/corpus depending on manifest kind
  - `corpus` -> explicit mode dispatch
- I did not find broken imports to deleted modules in the audited active micro/corpus driver path.

### Correctness Checks Already Present

- `micro/_driver_impl_run_micro.py:571-575` already validates `expected_result` for every sample and raises on mismatch.
- Therefore local smoke already validates correctness semantically; the missing piece was only human-readable output.

### Dead Code / Cleanup

- Removed unused wrappers from:
  - `corpus/_driver_impl_run_corpus_perf.py`
  - `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
- These were local dead helpers, not externally imported symbols.

### Stale Result-Layout References

- The repo policy after task `#190` is that `*.latest.json` aliases are gone and alias refresh is a no-op.
- I found active driver/helper code still depending on those aliases and fixed the low-risk cases:
  - `corpus/run_real_world_exec_time.py`
  - `corpus/_driver_impl_run_macro_corpus.py`
  - `micro/summarize_rq.py`
  - `micro/orchestrator/inventory.py`
  - `corpus/_driver_impl_run_corpus_tracing_exec.py`
  - related tracing/corpus help strings

### v1 / v2 Policy References

- In the active audited micro/corpus pipeline, I did not find live v1/v2 policy-schema use.
- Current active policy utilities and YAML use version 3.
- Remaining v1/v2 mentions are historical docs/archive naming, not active pipeline behavior.

### Leftover / Non-Canonical Entrypoints

- `micro/run_corpus_tracing.sh` is not part of the canonical root Makefile flow.
- It had a hardcoded absolute venv path; I fixed that.
- It still looks like a convenience wrapper, not a primary pipeline entry point.

## 3. Smoke Output Evaluation

### Should `make smoke` print a one-line stdout summary?

Yes.

Reason:
- Local smoke is used as a fast sanity check, so the first thing a human wants is “did it work and what was the rough magnitude?”
- The JSON artifact remains useful for scripts, but hiding all useful information in a file slows down manual iteration.

Minimal change implemented:
- Keep the existing JSON output.
- Print one line after success:
  - `SMOKE OK: simple llvmbpf exec 47 ns, compile 4.249 ms, result 12345678`

### Should `make smoke` also run kernel runtime?

No, not for the local `smoke` target.

Reason:
- Local `smoke` is explicitly the fast, no-VM, no-kernel-path sanity check.
- Adding kernel runtime would introduce `sudo -n` and host-kernel dependency into the local quick loop.
- The repo already has a dedicated kernel-path smoke target:
  - `make vm-micro-smoke`

### Should `make smoke` validate `expected_result`?

It already does.

Evidence:
- `micro/_driver_impl_run_micro.py:571-575`

Recommendation:
- Keep local `smoke` as llvmbpf-only.
- Keep `vm-micro-smoke` as the kernel/recompile path.
- Optionally later add a similar one-line stdout summary to `vm-micro-smoke`.

## 4. Paper Conformance

### 62 Benchmarks Claim

Confirmed.

Evidence:
- `config/micro_pure_jit.yaml` contains `62` benchmark entries.
- `micro/programs/` contains `62` `.bpf.c` files.

### Structural Suite Shape

The active suite shape broadly matches `CLAUDE.md`:
- `54` staged-input XDP programs
- `5` packet-context XDP controls
  - explicit packet-backed macro users plus manual packet-entry XDP controls
- `3` kernel-only non-XDP controls
  - `tc_bitcount`
  - `tc_checksum`
  - `cgroup_hash_chain`

### Are all 8 canonical forms represented?

Not in the strong “scanner-visible on current x86 micro artifacts” sense.

I scanned all 62 built micro `.bpf.o` objects with `scanner/build/bpf-jit-scanner scan --all --json` and aggregated family coverage:

| Family | Benchmarks with sites | Total sites |
| --- | ---: | ---: |
| CMOV | 8 | 150 |
| WIDE | 51 | 146 |
| ROTATE | 16 | 1020 |
| LEA | 5 | 13 |
| EXTRACT | 5 | 525 |
| ZERO-EXT | 0 | 0 |
| ENDIAN | 1 | 256 |
| BRANCH-FLIP | 4 | 270 |

Interpretation:
- The suite clearly exercises 7 forms on current x86 artifacts.
- `ZERO_EXT_ELIDE` is still absent in the active x86 micro artifacts.
- This is consistent with the plan’s note that zero-ext is effectively a non-x86 form and expected to be zero on x86-64.
- Therefore:
  - the “62 benchmarks” claim is correct;
  - the stronger “active suite is aligned with all 8 canonical forms” wording in `CLAUDE.md` is too strong for current x86 micro evaluation artifacts.

### Do the Makefile targets produce the data the paper needs?

Partially.

What exists:
- `make vm-micro`
  - stock kernel + kernel-recompile + llvmbpf data
- `make vm-corpus`
  - corpus v5 VM batch data
- `make vm-e2e`
  - tracee / tetragon / bpftrace / scx / katran outputs

Main gaps against plan §5:
- Missing required baselines from §5.1:
  - no root Makefile targets for `kernel-fixed-*`
  - no root Makefile targets for `advisor-static`
  - no root Makefile targets for `advisor-profiled`
- Hardware coverage gap from §5.4:
  - ARM64 has smoke/selftest support, but no first-class full micro/corpus evaluation target in the root Makefile
  - smaller-core / Atom-like x86 remains manual/out-of-band
- Corpus construct-validity gap remains:
  - `corpus/run_real_world_exec_time.py` still uses one generic valid packet and one zero-filled context buffer, not path-targeted per-program triggering inputs
  - this is acceptable for narrow validation, but it does not fully solve the stronger construct-validity requirement emphasized at the top of the plan

## 5. Verification

Commands requested:

```bash
make -C micro micro_exec
make smoke
make scanner-tests
```

Results:
- `make -C micro micro_exec`
  - Passed
- `make smoke`
  - Passed
  - Current stdout summary:
    - `SMOKE OK: simple llvmbpf exec 47 ns, compile 4.249 ms, result 12345678`
- `make scanner-tests`
  - Failed
  - Failure is in scanner unit tests, not in the files changed by this audit
  - Observed failure pattern:
    - rotate-rule expectations in `scanner/tests/test_scanner.cpp`
    - examples from test output: lines `493`, `495`, `516-522`, `759`, `787-831`
  - Since this task did not modify scanner sources/tests, I am reporting this as a pre-existing or parallel issue, not attempting a speculative scanner fix inside this audit pass

## Recommended Follow-Ups

1. Decide whether `micro/Makefile all` should keep building `directive_hint` by default.
2. Update `CLAUDE.md` and `docs/kernel-jit-optimization-plan.md` to:
   - reflect Katran’s inclusion in `make vm-e2e`
   - stop implying current x86 micro artifacts represent all 8 canonical forms
3. Add explicit root Makefile entry points for the §5.1 required baselines if those baselines are still part of the paper contract.
4. Add a first-class ARM64 evaluation target if §5.4 ARM64 performance claims remain in scope.
5. Triage the current scanner unit-test failure separately from this Makefile/pipeline audit.
