# Task #19 Investigation: Consolidate duplicated logic

Date: 2026-04-21

Scope checked:
- `docs/kernel-jit-optimization-plan.md` first
- `runner/suites/corpus.py`
- `runner/suites/e2e.py`
- `runner/libs/suite_commands.py`
- `runner/libs/kvm_executor.py`
- `runner/libs/aws_executor.py`
- `e2e/driver.py`

## Overall verdict

Overall severity: **3/5**

Conclusion: there is some real DRY debt, but it is concentrated in two places:
- `e2e/driver.py` Tracee/Tetragon suite-config filtering is a clean, high-confidence duplicate.
- `runner/libs/suite_commands.py` and the `corpus`/`e2e` suite wrappers still have medium-sized repeated helpers, but most of the heavy shared logic has already been extracted into `runner/suites/_common.py` and `runner/libs/suite_commands.py`.

The executor side is **not** the main problem anymore. The runtime-container core has already been centralized.

## 1. `runner/suites/corpus.py` + `runner/suites/e2e.py`

Verdict: **mixed**

Real duplication:
- `runner/suites/corpus.py:83-87` and `runner/suites/e2e.py:85-89`
  Scale: 1 function pair, 5 lines each.
  Status: **true duplicate**.
  Differences: only `scratch_suffix` (`"corpus"` vs `"e2e"`) and argv source (`args.corpus_argv` vs `args.e2e_argv`).
- `runner/suites/corpus.py:111-123` and `runner/suites/e2e.py:98-110`
  Scale: 1 loop pair, 13 lines each.
  Status: **true duplicate**.
  Differences: only the source list name changes; behavior is the same `--rejit-passes` stripping logic.

Surface similarity only:
- `runner/suites/corpus.py:34-80` and `runner/suites/e2e.py:45-82`
  Scale: 2 parser functions, 47 lines vs 38 lines.
  Status: **surface-similar, not one clean shared function today**.
  Differences: `corpus` owns `--samples`, output paths, corpus filters, workload seconds; `e2e` owns case validation, `all` semantics, and smoke mode.
- `runner/suites/corpus.py:127-142` and `runner/suites/e2e.py:120-141`
  Scale: 2 run-wrapper functions, 16 lines vs 22 lines.
  Status: **surface-similar**.
  Differences: `corpus` always launches one driver with unconditional Katran artifact validation; `e2e` fans out per case, only validates Katran when needed, and moves runtime-LD setup into `_run_e2e_case()`.

Shared parameters if extracted:
- For the real duplicate pieces: `argv`, `option_name="--rejit-passes"`, `scratch_suffix`, maybe a `die` callback.
- For a larger shared run helper: `driver_path`, `driver_argv_builder`, `needs_katran`, `per_case_loop`, and suite-specific preflight hooks. That abstraction is possible, but starts to look framework-heavy.

Priority: **Medium**

Why not high:
- The serious shared parts are already in `runner/suites/_common.py`.
- The remaining true duplicate is small: about **18 lines of real duplication**, plus a larger amount of intentionally local suite orchestration.

Concrete harm if left alone:
- A future fix to `--rejit-passes` passthrough behavior must be made in two wrappers.
- If runtime env handling changes again, the tiny `_runtime_env()` wrappers can drift.

## 2. `runner/libs/suite_commands.py`

Verdict: **real duplicate exists, and the TaskGet note understates it**

Exact duplicate from the TaskGet hint:
- `runner/libs/suite_commands.py:149-153` and `runner/libs/suite_commands.py:179-183`
  Scale: 2 identical loops, 5 lines each.
  Status: **true duplicate**.
  Differences: none.

Bigger duplicated structure in the same file:
- `runner/libs/suite_commands.py:105-121`
- `runner/libs/suite_commands.py:132-148`
- `runner/libs/suite_commands.py:164-178`
- `runner/libs/suite_commands.py:195-210`
  Scale: 4 builder functions with the same 9-11 base argv items repeated.
  Status: **true duplicate core with suite-specific tails**.
  Differences:
  `micro` adds one output path.
  `corpus` adds JSON/Markdown outputs plus native-repo/SCX flags.
  `e2e` adds native-repo/SCX flags but no fixed output paths.
  `test` adds artifact-dir plus run-contract injection and only SCX flags.

Shared parameters if extracted:
- `suite_module`
- base identity fields from `config`
- extra fixed args for that suite
- whether to append `native_repos`
- whether to append `scx_packages`
- optional `config_path` / run-contract variant

Priority: **Medium**

Why not high:
- The file is small and centralized already.
- Refactoring only the 5-line artifact loops is not enough; the meaningful cleanup is a `build_base_suite_argv()` helper plus an `append_artifact_args()` helper.
- That is useful, but not urgent unless this file is being touched for new suite flags anyway.

Concrete harm if left alone:
- Adding or changing a shared suite flag means editing `micro` / `corpus` / `e2e` / `test` builders separately.
- It is easy to miss one builder and create executor-specific argument skew.

## 3. `runner/libs/kvm_executor.py` vs `runner/libs/aws_executor.py`

Verdict: **mostly not a real duplicate anymore**

What is already shared:
- `runner/libs/suite_commands.py:42-95` centralizes runtime-container argv building.
- `runner/libs/suite_commands.py:26-27` centralizes the host/result directory list.
- `runner/libs/kvm_executor.py:96` calls the shared builder directly.
- `runner/libs/aws_executor.py:637-648` calls the same shared builder through a thin wrapper.
- `runner/libs/kvm_executor.py:94-95` and `runner/libs/aws_executor.py:651-653` both use the shared directory list for `mkdir -p`.

Remaining overlap:
- Scale: roughly one 2-3 line `mkdir -p` pattern, plus two thin wrapper calls into the already-shared builder.
- Status: **surface-similar only**.

Why the semantics are different:
- `runner/libs/kvm_executor.py:90-103`
  Builds a guest shell script, bootstraps an ephemeral `dockerd`, installs the image tar with `bpfrejit-install`, then runs the container locally inside the VM.
- `runner/libs/aws_executor.py:656-694`
  Waits for SSH, ensures remote Docker, creates remote log/run dirs with ownership handling, runs the container via `sudo`, pulls logs/results back, and removes remote scratch.

Shared parameters if someone still wanted to force an abstraction:
- local vs remote workspace
- suite args source
- sudo / ownership policy
- log path handling
- cleanup policy
- result sync policy

That is too many axes for the amount of remaining duplicate code.

Priority: **Low**

Concrete harm if left alone:
- Very little. The high-value runtime-container logic is already shared.
- Further abstraction here risks hiding important KVM-vs-AWS lifecycle differences.

## 4. `e2e/driver.py` Tracee/Tetragon config filter copy

Verdict: **clean true duplicate**

References:
- `e2e/driver.py:297-320`
- `e2e/driver.py:323-346`

Scale:
- 2 functions
- 24 lines each
- diff is only labels/prefix strings

Differences:
- `"Tracee"` vs `"Tetragon"` in error text
- temp file prefix `"tracee-suite-"` vs `"tetragon-suite-"`

Everything else is the same:
- load YAML config
- require mapping payload
- compute `wanted = [app.workload_for("e2e") for app in suite_apps]`
- filter `payload["workloads"]`
- verify nothing requested is missing
- write a temp YAML
- mutate `args.config`

Shared parameters if extracted:
- `case_label`
- `temp_prefix`
- `args.config`
- `suite_apps`

Priority: **High**

Why high:
- This is a low-risk refactor with very little abstraction pressure.
- The code is already mechanically identical, so any future behavior change here will otherwise require two edits.

Concrete harm if left alone:
- If workload matching rules change, missing-workload errors change, or config filtering needs to preserve extra metadata/order differently, the fix must be duplicated.

Adjacent observation not in the original TaskGet hint:
- `e2e/cases/tracee/case.py:81-114` and `e2e/cases/tetragon/case.py:135-168` contain another near-identical program-selection helper, 34 lines each.
- That does not change the priority of this task directly, but it confirms the same drift pattern exists deeper in the same subsystem.

## Estimated refactor size and risk

If doing only the obvious/high-value part:
- `e2e/driver.py` workload-filter helper only
- Estimated touch size: **~25-45 LOC**
- Risk: **Low**

If doing the practical full slice for this task:
- `e2e/driver.py` helper
- `runner/suites/_common.py` helper for `--rejit-passes` passthrough handling
- `runner/libs/suite_commands.py` base-argv + artifact-args helpers
- Estimated touch size: **~120-220 LOC**
- Risk: **Low to medium**

If trying to fold executors into the same cleanup:
- Estimated touch size: **200-350+ LOC**
- Risk: **Medium**
- Recommendation: **do not include executor unification in the first pass**

## Recommendation

Recommended order:
1. Do `e2e/driver.py` Tracee/Tetragon workload-config helper first.
2. If already touching suite wrappers, add a tiny shared helper for `--rejit-passes` extraction/stripping.
3. If already touching `suite_commands.py`, refactor the builder base prefix and artifact-flag appenders together.
4. Skip `kvm_executor`/`aws_executor` unification unless a future bug shows real drift there.

Bottom line:
- This task is **worth doing**, but it is **not a stop-everything issue**.
- The right framing is **small targeted DRY cleanup**, not a large cross-layer framework refactor.
