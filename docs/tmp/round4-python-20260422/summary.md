# Round 4 Python Deletion 2026-04-22

Status: completed

Scope:
- only touched [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py)
- only touched [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py)
- only touched [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py)
- only touched [runner/libs/app_runners/__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/__init__.py)
- only touched [runner/libs/app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py)
- only touched [e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py)
- only touched [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py)
- only touched [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py)
- only touched [e2e/cases/katran/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py)
- did not touch any forbidden file
- did not run `make vm-e2e`
- did not run `make vm-corpus`

Validation:
- per-item `python3 -m py_compile` after item 2-10: PASS
- final `make check`: PASS

Actual line-count note:
- "实际删除行数" below is the local hunk-deletion count for this turn's edits.
- `git diff --shortstat` below is the required command output, but it is cumulative against `HEAD`; these files already carried Round 3 uncommitted edits before this turn.

## item 2

- Files/lines: former `corpus/driver.py:1060-1120`; after deletion [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1049) goes straight from `CorpusAppSession` to `run_suite()`.
- 删前/删后: `_run_app()` duplicated the app-runner lifecycle path that `run_suite()` already owns; now the dead helper is gone and there is only the live session flow.
- 估算删除行数: 61
- 实际删除行数: 61
- grep 验证: `rg -n "_run_app\\(" corpus/driver.py runner/libs/case_common.py runner/libs/rejit.py runner/libs/app_runners/__init__.py runner/libs/app_suite_schema.py e2e/driver.py e2e/cases/tetragon/case.py e2e/cases/bcc/case.py e2e/cases/katran/case.py`
- 结果: no output

## item 3

- Files/lines: [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:222), [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:271), [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:891), [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1191)
- 删前/删后: group merge 和 corpus slicer 会把 `selection_source` / `scan_enabled_passes` / `benchmark_profile` 写进结果 JSON；现在只保留运行时真正消费的字段，`_resolve_scan_pass_selection()` 也收紧为只返回 `(scan_enabled_passes, benchmark_config)`。
- 估算删除行数: 16
- 实际删除行数: 26
- grep 验证: `rg -n '"selection_source"|"scan_enabled_passes"|"benchmark_profile"|get\\("selection_source"\\)|get\\("scan_enabled_passes"\\)|get\\("benchmark_profile"\\)' corpus/driver.py runner/libs/case_common.py`
- 结果: no output

## item 4

- Files/lines: [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:616), [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:463), [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:768), [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:794), [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:937), [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:165), [e2e/cases/katran/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py:165)
- 删前/删后: apply/result payloads echoed `kernel_prog_name` / `command_used` / `runner_artifacts` without any reader; now these write-only fields are gone from runner apply results, lifecycle artifacts, corpus results, and BCC/Katran case payloads.
- 估算删除行数: 18
- 实际删除行数: 12
- grep 验证: `rg -n 'kernel_prog_name|"command_used"|"runner_artifacts"|get\\("command_used"\\)|get\\("runner_artifacts"\\)' corpus/driver.py runner/libs/case_common.py runner/libs/rejit.py e2e/cases/bcc/case.py e2e/cases/katran/case.py`
- 结果: no output

## item 5

- Files/lines: [runner/libs/app_runners/__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/__init__.py:9)
- 删前/删后: `get_app_runner()` used `_leaf_name()` and `_pop_string()` to accept `tool_name` / `script_name` aliases and derive names from `app_name`; now shared runners require the current explicit manifest shape: BCC needs `args.tool`, bpftrace needs `args.script`, SCX needs `args.scheduler`.
- 估算删除行数: 17
- 实际删除行数: 17
- grep 验证: `rg -n '_leaf_name|_pop_string|kwargs, "tool_name"|kwargs, "script_name"|_leaf_name\\(app_name\\)' runner/libs/app_runners/__init__.py`
- 结果: no output

## item 6

- Files/lines: [runner/libs/app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py:83), [runner/libs/app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py:106)
- 删前/删后: loader previously merged nested `args:` into flat app keys and exposed an unused `max_apps`; now it accepts only the flat manifest shape, rejects nested `args:`, and no longer carries `max_apps`.
- 估算删除行数: 14
- 实际删除行数: 18
- grep 验证: `rg -n 'max_apps=|\\bmax_apps\\b|duplicate app arg' runner/libs/app_suite_schema.py corpus/driver.py e2e/driver.py`
- 结果: no output
- grep 验证: `rg -n '^\\s*args:\\s*$' corpus/config/macro_apps.yaml`
- 结果: no output

## item 7

- Files/lines: former `e2e/cases/tetragon/case.py:126-146`; live workload path now starts at [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:122)
- 删前/删后: `run_workload()` -> `run_workload_with_options()` -> local `run_exec_storm_in_cgroup()` was a dead wrapper stack over shared helpers; now `measure_workload()` only uses `runner.run_workload_spec(...)`, which is the real active path.
- 估算删除行数: 17
- 实际删除行数: 23
- grep 验证: `rg -n 'run_workload_with_options\\(|run_exec_storm_in_cgroup\\(|def run_workload\\(' e2e/cases/tetragon/case.py`
- 结果: no output

## item 8

- Files/lines: [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:102), [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:414)
- 删前/删后: `CaseLifecycleState.scan_kwargs` existed with no writer and was only unpacked once before `scan_programs(...)`; now the field is removed and scan calls pass `enabled_passes=scan_enabled_passes` directly.
- 估算删除行数: 6
- 实际删除行数: 4
- grep 验证: `rg -n '\\bscan_kwargs\\b|scan_kwargs=' runner/libs/case_common.py corpus/driver.py e2e/driver.py e2e/cases/tetragon/case.py e2e/cases/bcc/case.py e2e/cases/katran/case.py`
- 结果: no output

## item 9

- Files/lines: [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:127), [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:363), [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:446)
- 删前/删后: `LifecycleRunResult` used to store unread `.setup_state` and `.metadata`; now the dataclass only carries live lifecycle outputs, and the now-unreachable `_clone_daemon_metadata()` helper was deleted with it.
- 估算删除行数: 10
- 实际删除行数: 9
- grep 验证: `rg -n '\\.setup_state\\b|lifecycle_result\\.metadata|setup_state=|metadata=copy.deepcopy\\(metadata\\)' runner/libs/case_common.py corpus/driver.py e2e/driver.py e2e/cases/tetragon/case.py e2e/cases/bcc/case.py e2e/cases/katran/case.py`
- 结果: no output

## item 10

- Files/lines: [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:138), [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1065), [e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py:606), [e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py:633)
- 删前/删后: `prepare_daemon_session(..., daemon_binary=...)` accepted an override that every caller passed back unchanged; now it always resolves from `daemon_session.daemon_binary`, callers are one-liners, and the dead `Path` import in `case_common.py` was removed.
- 估算删除行数: 4
- 实际删除行数: 8
- grep 验证: `rg -n 'prepare_daemon_session\\(.*daemon_binary=|daemon_binary=daemon_binary' runner/libs/case_common.py corpus/driver.py e2e/driver.py runner/libs/rejit.py`
- 结果: no output

## Totals

- 本轮手工删除行数合计: 178
- `git diff --shortstat -- corpus/driver.py runner/libs/rejit.py runner/libs/case_common.py runner/libs/app_runners/__init__.py runner/libs/app_runners/tetragon.py runner/libs/app_suite_schema.py e2e/driver.py e2e/cases/tetragon/case.py e2e/cases/bcc/case.py e2e/cases/katran/case.py`
- 输出: `10 files changed, 174 insertions(+), 525 deletions(-)`
- 说明: 上面的 `git diff --shortstat` 是相对 `HEAD` 的累计输出；这些文件在本轮开始前已经带有 Round 3 的未提交改动，所以不能把它当作本轮独占统计。本轮独占删除量以上面的 178 行为准。

## Breakage And Fixes

- 没有出现需要二次修补的 breakage。item 2-10 的每一步 `python3 -m py_compile` 都直接通过，最终 `make check` 也通过。
- item 外顺手删除的显然死代码:
- `runner/libs/case_common.py` 里的 `_clone_daemon_metadata()`，因为 item 9 删除 `LifecycleRunResult.metadata` 后已不可达。
- `runner/libs/case_common.py` 里的 `Path` import，因为 item 10 删除 `daemon_binary` override 后已不再使用。
