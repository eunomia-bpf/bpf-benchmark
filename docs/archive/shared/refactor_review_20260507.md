# Refactor Review 2026-05-07

## Critical Issues

No critical always-break issues found in the reviewed KVM corpus path. The deleted modules have no remaining live Python imports in `Makefile`, `runner/`, or `corpus/` after excluding archived docs/results, and `python3 -m py_compile` passed for the changed live Python files.

## Significant Issues

### 1. `make micro` now defaults to 3 samples instead of 1

- Location: `Makefile:31`, `Makefile:90`, `CLAUDE.md:146`
- Problem: `SAMPLES ?= 3` is now used for both corpus and micro. `MICRO_ARGS` expands to `--samples "$(SAMPLES)"`, so a plain `make micro` dry-run now invokes `runner.libs.kvm_executor x86-kvm micro --samples "3" ...`. The documented contract is default 3 for corpus and default 1 for micro.
- Impact: Micro runs become 3x heavier by default and no longer match the documented benchmark contract. This is a behavioral regression even though explicit `SAMPLES=1 make micro` still works.
- Fix recommendation: Preserve separate defaulting while keeping the user-facing `SAMPLES` override. For example, capture `$(origin SAMPLES)` before assigning the corpus default, then derive `MICRO_SAMPLES := 1` only when `SAMPLES` was not supplied by the environment/command line; use `MICRO_SAMPLES` in `MICRO_ARGS` and keep `BPFREJIT_SAMPLES`/corpus on the corpus default of 3.

### 2. Docker env forwarding lets host `BPFREJIT_*` override run-config infrastructure

- Location: `runner/libs/suite_commands.py:131-137`
- Problem: `_config_env_pairs()` first emits authoritative infrastructure env such as `BPFREJIT_WORKSPACE`, `BPFREJIT_TARGET_ARCH`, `BPFREJIT_TARGET_NAME`, and `BPFREJIT_RUN_TOKEN`, but the subsequent loop forwards every non-empty host `BPFREJIT_*` variable after that. Docker keeps the later duplicate value, so a stale host `BPFREJIT_WORKSPACE`, `BPFREJIT_TARGET_ARCH`, `BPFREJIT_NATIVE_REPOS`, etc. can override the `RunConfig`-derived values.
- Impact: Corpus can run against the wrong workspace/arch/token or validate the wrong artifact set. This is especially risky now that `corpus.driver` ignores CLI flags and trusts env exclusively.
- Fix recommendation: Replace prefix-wide forwarding with an explicit allowlist of user knobs, or emit user knobs first and `_config_env_pairs()` last so infrastructure always wins. The allowlist should include only intended tunables such as `BPFREJIT_BENCH_PASSES`, `BPFREJIT_CORPUS_APPS`, `BPFREJIT_KEEP_ALL_WORKDIRS`, `BPFREJIT_SAMPLES`, `BPFREJIT_WORKLOAD_DURATION`, `BPFREJIT_WARMUPS`, `BPFREJIT_SKIP_REJIT`, and `BPFREJIT_KEEP_FAILURE_ARTIFACTS`.

### 3. Run tokens are no longer unique per run

- Location: `runner/libs/run_contract.py:278`, `Makefile:111-124`, `runner/libs/aws_executor.py:652-657`
- Problem: after deleting `run_target_suite.py`, no layer generates a random run token. `build_run_config()` falls back to `f"{target_name}_{suite_name}"`, so every `x86-kvm/corpus`, `aws-x86/corpus`, etc. run reuses the same token. AWS then derives `remote_stage_dir` and local `run-state` from that fixed token, and test artifacts are likewise written under a fixed token-derived directory.
- Impact: Sequential happy-path corpus may still pass, but failed/interrupted AWS runs and repeated test runs lose isolation. Stale state, reused remote stage paths, and overwritten test artifacts become much more likely. It also removes useful per-run identity from logs and contracts.
- Fix recommendation: Generate a unique token for run configs when `RUN_TOKEN` is absent, either in Make before invoking the executor or inside `_build_run_config_mapping()`. Keep `build_target_config()` deterministic for terminate, but use a sanitized `run.<target>.<suite>.<hex>` style token for actual suite runs.

## Minor Cleanup Suggestions

### 1. Broken dead cleanup helper remains after the context signature change

- Location: `runner/libs/aws_executor.py:705-709`, `runner/libs/aws_common.py:37`
- Problem: `cleanup_failed_run_for_config()` still accepts a config path and calls `aws_common._build_context("run", config_path)`, but `_build_context()` now expects a `RunConfig`, not a `Path`. `rg` did not find any live caller after `run_target_suite.py` was deleted.
- Fix recommendation: Delete `cleanup_failed_run_for_config()` if it is no longer part of the entrypoint flow. If an external/debug caller must remain, read/build a `RunConfig` before calling `_build_context()`.

### 2. Stale Makefile variables/paths remain from the deleted control-dir flow

- Location: `Makefile:71`, `Makefile:145`
- Problem: `KEEP_ARG` is no longer used, and `clean-build` still removes `.state/runner-contracts` even though the refactor dropped run-config/suite-args files.
- Fix recommendation: Remove `KEEP_ARG`; remove the `.state/runner-contracts` cleanup if no other live path creates it.

### 3. Stale deleted-entrypoint docs remain

- Location: `README.md:57-59`
- Problem: README still tells users not to invoke `python -m runner.libs.run_target_suite`, but that module is deleted.
- Fix recommendation: Reword to say the root Makefile is the only supported entrypoint, without naming the deleted module as an existing component.

### 4. Stale corpus-driver imports/constants after merging the wrapper

- Location: `corpus/driver.py:48`, `corpus/driver.py:54`, `corpus/driver.py:64-65`
- Problem: `add_common_args`, `nonnegative_int`, `DEFAULT_DAEMON`, and `DEFAULT_OUTPUT_JSON` are vestigial after env-only parsing.
- Fix recommendation: Remove the unused imports/constants in the same cleanup patch as the other vestigial surfaces.

### 5. Stale failure-artifact knob comment

- Location: `runner/libs/rejit.py:383`
- Problem: The comment references `make vm-corpus KEEP_FAILURE_ARTIFACTS=1`, but the current documented Make knob is `KEEP_WORKDIRS=1`.
- Fix recommendation: Update the comment to `KEEP_WORKDIRS=1` / `KEEP_WORKDIRS=all`.

## Additional Checks

- `python3 -m py_compile runner/libs/run_contract.py runner/libs/kvm_executor.py runner/libs/aws_executor.py runner/libs/aws_common.py runner/libs/suite_commands.py runner/suites/_common.py runner/suites/micro.py runner/suites/test.py corpus/driver.py` passed.
- `make -n PLATFORM=kvm ARCH=x86 selftest` and `negative-test` still pass `--test-mode ...` through to `runner.suites.test`, whose parser consumes it.
- `make -n PLATFORM=kvm ARCH=x86 micro` still passes the legacy micro CLI args that `runner.suites.micro` requires, but with the wrong default sample count noted above.
- `make -n PLATFORM=aws ARCH=x86 corpus` now dispatches through `runner.libs.aws_executor run aws-x86 corpus`; terminate dry path is plausibly intact because `aws_executor terminate <target>` builds a target-only config and only needs AWS region/profile for tag-based termination.

## Final Verdict

Fix-then-ship. The KVM corpus smoke result is credible for the narrow path tested, but the micro default regression and env override hazard should be fixed before landing. The unique-token issue should also be fixed before relying on AWS or repeated test artifacts.
