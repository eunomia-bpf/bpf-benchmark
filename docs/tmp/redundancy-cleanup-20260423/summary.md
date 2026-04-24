# Redundancy Cleanup Summary (2026-04-23)

Scope:
- Removed only the redundancy items assigned in the 2026-04-23 inventory/audit follow-up.
- Respected the explicit no-touch set from the parallel-work guard.
- No `make vm-*` commands were run.

Verification commands:
- `python3 -m py_compile runner/suites/test.py runner/suites/_common.py runner/suites/corpus.py runner/suites/e2e.py runner/libs/rejit.py runner/libs/workload.py runner/libs/suite_commands.py`
- `rg -n 'full' runner/suites/test.py`
- `rg -n --glob '!runner/repos/**' --glob '!runner/build-*/**' --glob '!**/results/**' 'minimal_syscall|mixed_system|system_telemetry_mix' .`
- `rg -n 'output-md|output_md' runner/libs/suite_commands.py runner/suites/corpus.py corpus/driver.py`
- `rg -n 'PROFILE=ablation_wide_mem|make compare|compare_results' micro/README.md micro docs Makefile runner/mk`

## 1. `full` test mode

- Path: `runner/suites/test.py:50-65`, `runner/suites/test.py:279-323`
- Removed:
  - argparse choice `"full"`
  - help text documenting `"full"` as an alias
  - normalization `args.test_mode = "test" if args.test_mode == "full" else args.test_mode`
  - internal helper name `_run_full_test_mode` -> `_run_test_mode`
- Reason:
  - `full` had no distinct semantics inside the suite entrypoint. It was only another spelling of `test`.
- Verification:
  - `rg -n 'full' runner/suites/test.py` is clean.
  - Residual caller-side normalization still exists at `runner/libs/suite_args.py:60`, but that file was explicitly out of bounds in this round because another parallel codex owns it.
- Git diff shortstat:
  - `1 file changed, 4 insertions(+), 5 deletions(-)` for `runner/suites/test.py`

## 2. wrapper-hidden `--rejit-passes`

- Path: `runner/suites/_common.py` former helper at the shared runtime-env layer, plus `runner/suites/corpus.py:68-88` and `runner/suites/e2e.py:64-73`
- Removed:
  - `_common.py` wrapper helper that translated `--rejit-passes` into `BPFREJIT_BENCH_PASSES`
  - dead helper plumbing `argv_option_value()` and `strip_option_with_value()`
  - corpus/e2e wrapper logic that silently stripped `--rejit-passes` before invoking the direct drivers
- Reason:
  - This was a compatibility shell only. The direct drivers already dropped `--rejit-passes`, so the wrapper translation was the only remaining shadow surface.
  - `BPFREJIT_BENCH_PASSES` itself is still live and was intentionally kept:
    - `runner/libs/case_common.py:194-195` uses it to select scan passes.
    - `runner/libs/case_common.py:214-216` uses it to build apply pass lists.
    - `runner/libs/rejit.py:486-493` parses the env var into the benchmark pass set.
- Verification:
  - wrapper suite argv is no longer rewritten; unknown `--rejit-passes` now fails loud at the direct driver parser instead of being silently consumed.
- Git diff shortstat:
  - `3 files changed, 6 insertions(+), 49 deletions(-)` for `runner/suites/_common.py`, `runner/suites/corpus.py`, `runner/suites/e2e.py`

## 3. workload alias `minimal_syscall`

- Path: `runner/libs/workload.py:1146-1149`
- Removed:
  - alias branch that mapped `minimal_syscall` to `run_user_exec_loop()`
- Reason:
  - `exec_loop` is the canonical name and the repository had no live caller for `minimal_syscall` outside historical docs.
- Verification:
  - `rg -n --glob '!runner/repos/**' --glob '!runner/build-*/**' --glob '!**/results/**' 'minimal_syscall' .` only hits historical `docs/tmp/`.
  - No checked-in config had to be migrated.
- Git diff shortstat:
  - shared with item 4: `1 file changed, 1 insertion(+), 3 deletions(-)` for `runner/libs/workload.py`

## 4. workload aliases `mixed_system` / `system_telemetry_mix`

- Path: `runner/libs/workload.py:1138-1139`, `runner/libs/workload.py:1180-1185`
- Removed:
  - alias branch that mapped `mixed_system` / `system_telemetry_mix` to `run_mixed_workload()`
- Reason:
  - `mixed` is the canonical dispatcher key and the repository had no live caller for either alias outside historical docs.
- Verification:
  - `rg -n --glob '!runner/repos/**' --glob '!runner/build-*/**' --glob '!**/results/**' 'mixed_system|system_telemetry_mix' .` only hits historical `docs/tmp/`.
  - No checked-in config had to be migrated.
- Git diff shortstat:
  - shared with item 3: `1 file changed, 1 insertion(+), 3 deletions(-)` for `runner/libs/workload.py`

## 5. stale `--output-md` producer

- Path: `runner/libs/suite_commands.py:164-168`
- Removed:
  - synthetic `--output-md <target_name>_corpus.md` injection in `build_corpus_suite_argv()`
- Reason:
  - This was producer-only. `runner/suites/corpus.py` has no parser for it, and `corpus/driver.py` has no downstream reader.
- Verification:
  - `rg -n 'output-md|output_md' runner/libs/suite_commands.py runner/suites/corpus.py corpus/driver.py` is clean.
- Git diff shortstat:
  - `1 file changed, 2 deletions(-)` for `runner/libs/suite_commands.py`

## 6. stale `micro/README.md` example

- Path: `micro/README.md:56-60`
- Removed:
  - stale `make vm-micro PROFILE=ablation_wide_mem` example
- Replaced with:
  - `make vm-micro BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`
- Reason:
  - `PROFILE` was already deleted in #656, so the README was advertising a dead flag.
- Verification:
  - `rg -n 'PROFILE=ablation_wide_mem' micro/README.md micro docs Makefile runner/mk` no longer hits the README.
- Git diff shortstat:
  - shared with item 7: `2 files changed, 2 insertions(+), 250 deletions(-)` for `micro/README.md` and `micro/compare_results.py`

## 7. `micro/compare_results.py`

- Path: `micro/compare_results.py:1`
- Removed:
  - the entire script
- Reason:
  - repo-wide live-caller search found no active caller in `runner/`, `e2e/`, `corpus/`, `Makefile`, or `micro/` after excluding generated/build outputs.
  - The only user-facing entry it documented was stale `make compare`, and root `Makefile` has no `compare:` target.
- Verification:
  - before deletion, `rg -n --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!**/results/**' 'compare_results' micro runner e2e corpus Makefile docs` only found the script itself plus historical docs.
- Git diff shortstat:
  - shared with item 6: `2 files changed, 2 insertions(+), 250 deletions(-)` for `micro/README.md` and `micro/compare_results.py`

## Final verification state

- `python3 -m py_compile` passed for every modified `.py` file that still exists.
- `runner/suites/test.py` no longer contains `full`.
- `runner/libs/workload.py` no longer contains live mapping entries for `minimal_syscall`, `mixed_system`, or `system_telemetry_mix`.
- `runner/libs/suite_commands.py` no longer injects `--output-md`.
- `micro/README.md` no longer contains `PROFILE=ablation_wide_mem`.
- `BPFREJIT_BENCH_PASSES` was intentionally retained as a live env control plane; only the wrapper-hidden `--rejit-passes` compatibility layer was removed.
