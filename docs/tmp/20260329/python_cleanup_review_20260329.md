# Python Cleanup Review 2026-03-29

## Scope

Reviewed the remaining Python/config surface requested in this pass:

- `runner/libs/`
- `corpus/`
- `e2e/`
- `corpus/config/macro_corpus.yaml`
- `corpus/config/benchmark_config.yaml`

The goal was to keep only code that still matches the orchestrator-only architecture and remove leftover batch/prepared/attach-trigger compatibility.

## Removed

  - Deleted. This was a host-kernel probing script, not a meaningful repo-owned pytest unit test, and it conflicts with the repo rule against host-side kernel/BPF actions.

- `corpus/run_code_size_comparison.py`
  - Deleted. Legacy standalone corpus driver with obsolete manifest/schema assumptions (`io_mode`, `compile_only`, old measurement flow). No active imports.

- `corpus/scripts/migrate_v1_to_v2.py`
  - Deleted. One-off migration script for the removed v1/v2 transition. No active imports.

- `runner/libs/corpus.py`
  - Deleted dead guest-batch helpers:
    - `load_guest_batch_targets()`
    - `write_guest_batch_records()`
  - Simplified the module header comment so it only describes the current role.

- `runner/libs/vm.py`
  - Deleted dead guest-batch runtime code:
    - `_parse_guest_event()`
    - `run_corpus_targets_in_guest_batch()`

- `runner/libs/rejit.py`
  - Deleted dead parsing helpers:
    - `_parse_last_json_object()`
    - `_parse_site_summary()`
  - Removed obsolete policy match keys that depended on the old manifest schema:
    - `test_method`
    - `attach_group`

- `runner/libs/commands.py`
  - Reduced to the only still-used entrypoint: `build_list_programs_command()`
  - Removed unused command builders for the old micro/batch flow.

- `e2e/cases/katran/case.py`
  - Removed obsolete `katran_server_binary` compatibility plumbing and related unused path resolution.

- `e2e/run.py`
  - Removed the stale `--katran-server-binary` CLI option because the Katran case no longer consumes it.

- `e2e/cases/tracee/case.py`
  - Removed markdown fallback to `skip_reason`; error rendering now uses the actual error path only.

- `e2e/cases/tetragon/case.py`
  - Removed markdown fallback to `skip_reason`; error rendering now uses the actual error path only.

- `corpus/modes.py`
  - Kept as a thin shim only.
  - Removed the stale historical docstring and replaced it with a minimal compatibility-shim description.

- `corpus/config/macro_corpus.yaml`
  - Removed remaining old-architecture residue:
    - `attach_group:` entries
    - `compile-only` tags
    - `attach_trigger` wording in descriptive text

## Kept

  - Kept. The remaining tests still exercise active behavior: manifest parsing, result aggregation, daemon socket/lifecycle handling, run artifact writing, e2e payload validation, and VM helper command construction.

- `runner/libs/results.py`
  - Kept. No references to the removed schema fields were found in this module.

- `corpus/driver.py`
  - Kept. It already only forwards to `corpus.orchestrator`.

- `corpus/orchestrator.py`
  - Kept. It is already the intended placeholder/TODO entrypoint for the new architecture.

- `runner/libs/batch_runner.py`
  - Not deleted in this pass.
  - It is still imported by:
    - `micro/driver.py`
    - `daemon/tests/static_verify.py`
    - `runner/scripts/k2_comparison.py`
  - This remains legacy surface, but removing it cleanly requires a coordinated follow-up outside the scope requested here.

- `runner/libs/corpus.py` guest-batch utility remnants
  - `sanitize_guest_batch_record()` and `packet_batch_timeout_seconds()` were not deleted because `runner/scripts/k2_comparison.py` still imports them.

## Config Checks

- `corpus/config/macro_corpus.yaml`
  - Confirmed no remaining forbidden schema/text residue:
    - no `attach_trigger`
    - no `compile-only`
    - no `attach_group:`
    - no `trigger`, `compile_only`, `io_mode`, `attach_group`, or `test_method` keys
  - Confirmed all measurement values are exactly:
    - `app_native`
    - `test_run`
  - Confirmed no manifest entry points at a missing `.bpf.o` source.

- `corpus/config/benchmark_config.yaml`
  - Confirmed no out-of-scope security passes:
    - `speculation_barrier`
    - `dangerous_helper_firewall`
    - `live_patch`
  - Confirmed all ablation/profile `active_list` pass references are valid members of the configured performance pass set.

## Validation

- `python3` compile check

  - Passed: `61 passed`

