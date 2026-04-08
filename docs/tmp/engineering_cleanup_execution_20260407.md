# Engineering Cleanup Execution 2026-04-07

This file is a historical execution log for one cleanup lane. It is not the
canonical current runner contract. For the current refactor design, active todo,
and current code/log status, use `docs/tmp/aws_arm64_remote.md`.

## Scope

- Kept review item `#1` intact as requested. Per-program pass tracking remains in place, including `effective_enabled_passes_by_program` and the related daemon/benchmark reporting path.
- Did not touch review items `#11` and `#13`.
- Did not add new tests, docstrings, or comments.
- Did not change daemon or benchmark feature behavior beyond removing dead/duplicate code and aligning Makefile/test plumbing.

## Executed Changes

- `#2` Removed BCC per-tool `rejit_passes` overrides from [`e2e/cases/bcc/case.py`](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py). Deleted `ToolSpec.rejit_passes`, YAML parsing for per-tool pass overrides, and the per-tool requested/selected pass diff payloads. BCC now uses the shared benchmark pass selection while still reporting top-level selected/requested passes.
- `#2` Removed the matching Python coverage from [`tests/python/test_bcc_case.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_bcc_case.py). Kept only the remaining loader/plumbing coverage. No active BCC YAML config still carries `rejit_passes`.
- `#3` Consolidated duplicate BPF stats logic into [`runner/libs/bpf_stats.py`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/bpf_stats.py) as the canonical implementation. [`runner/libs/metrics.py`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/metrics.py) now keeps CPU/delta helpers and re-exports BPF stat helpers instead of duplicating libbpf/bpftool code.
- `#3` Updated imports across corpus/E2E/app-runner code to use the canonical BPF stats module and merged duplicate test coverage into [`tests/python/test_bpf_stats.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_bpf_stats.py). Deleted [`tests/python/test_metrics.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_metrics.py).
- `#4` Deleted dead integration scripts and helper-only artifacts: [`tests/integration/vm_comprehensive.sh`](/home/yunwei37/workspace/bpf-benchmark/tests/integration/vm_comprehensive.sh), [`tests/integration/vm_daemon_live.sh`](/home/yunwei37/workspace/bpf-benchmark/tests/integration/vm_daemon_live.sh), [`tests/helpers/Makefile`](/home/yunwei37/workspace/bpf-benchmark/tests/helpers/Makefile), [`tests/helpers/hold_bpf_prog.c`](/home/yunwei37/workspace/bpf-benchmark/tests/helpers/hold_bpf_prog.c), and the compiled helper `tests/hold_bpf_prog`.
- `#5` Deleted duplicate SCX repro driver `tests/integration/scx_prog_show_race.py`. The repo-owned negative reproducer in `tests/negative/scx_prog_show_race.c` remains.
- `#6` Deleted [`tests/negative/scx_bad_rejit_replay.c`](/home/yunwei37/workspace/bpf-benchmark/tests/negative/scx_bad_rejit_replay.c) and removed it from [`tests/negative/Makefile`](/home/yunwei37/workspace/bpf-benchmark/tests/negative/Makefile).
- `#7` Deleted [`tests/unittest/rejit_daemon_e2e.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_daemon_e2e.c) and its dead BPF fixture [`tests/unittest/progs/test_daemon_e2e_socket_filter.bpf.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/progs/test_daemon_e2e_socket_filter.bpf.c). Removed the target from [`tests/unittest/Makefile`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/Makefile).
- `#8` Deleted pure contract/signature tests [`tests/python/test_katran_runner_contract.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_katran_runner_contract.py) and [`tests/python/test_app_runners_contract.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_app_runners_contract.py).
- `#9` Simplified orchestration coverage by removing duplicate metadata-assembly tests from [`tests/python/test_corpus_driver.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_corpus_driver.py) and [`tests/python/test_e2e_driver.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_e2e_driver.py). Kept the minimal per-program plumbing coverage in [`tests/python/test_case_common.py`](/home/yunwei37/workspace/bpf-benchmark/tests/python/test_case_common.py) because it exercises the preserved `#1` behavior.
- `#10` Removed duplicate verifier rejection coverage from [`tests/unittest/rejit_safety_tests.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_safety_tests.c) and [`tests/unittest/rejit_verifier_negative_tests.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_verifier_negative_tests.c). The overlapping rejection cases remain covered in `tests/negative/adversarial_rejit.c`.
- `#12` Aligned the root target surface with plan doc §6.4 in [`Makefile`](/home/yunwei37/workspace/bpf-benchmark/Makefile). Added `vm-selftest`, `vm-negative-test`, and `vm-micro-smoke`; updated help/validate wiring; and removed stale script commentary referencing missing targets in [`runner/scripts/vm-selftest.sh`](/home/yunwei37/workspace/bpf-benchmark/runner/scripts/vm-selftest.sh).
- `#12` During validation, `make check` exposed that [`runner/Makefile`](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile) did not define `VM_CORPUS_SAMPLES` and `VM_CORPUS_TIMEOUT` even though the root Makefile and runner contract expected them. Added the matching defaults there to keep the contract surface consistent.
- `#14` Deleted alias-only BPF source [`tests/unittest/progs/test_hotswap_struct_ops_late_rollback.bpf.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/progs/test_hotswap_struct_ops_late_rollback.bpf.c). [`tests/unittest/Makefile`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/Makefile) now builds the alias object directly from the canonical source with the existing macro override.

## Validation

- First `make check` run failed in `tests/python/test_corpus_benchmark_defaults.py` because [`runner/Makefile`](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile) was missing `VM_CORPUS_SAMPLES` and `VM_CORPUS_TIMEOUT`.
- After syncing those defaults into [`runner/Makefile`](/home/yunwei37/workspace/bpf-benchmark/runner/Makefile), `make check` passed fully.
- Final validation result:
- `make check`
- daemon tests: `535 passed`
- python tests: `103 passed`
- smoke: passed, wrote `micro/results/smoke_20260407_174807/metadata.json`

## Notes

- Historical docs and archived result artifacts under `docs/tmp/`, `docs/paper/`, `corpus/results/`, and `e2e/results/` still mention removed scripts or legacy `tool_rejit_passes` fields. Those references were left untouched because they are historical records, not active code paths.
