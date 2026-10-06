# Repo-Wide Review Round 2 (2026-04-24)

## P1-P10
- `P1 activity/count gate`: `rg -n -S 'require_.*activity|activity_gate|did not execute any target programs|zero .*program executions|expected_programs|min_programs|max_programs' e2e/cases/bcc e2e/cases/bpftrace e2e/cases/katran e2e/cases/scx runner/libs/case_common.py` returned 0 hits. `corpus/driver.py:958-965` stays as a loud benchmark-validity failure, not a silent skip.
- `P2 单值 enum / 永远同分支`: actionable hit was `e2e/cases/scx/case.py` carrying a single fixed `mode="scx_rusty_loader"` field into payload/markdown. Removed. No allowed-scope `if ... == "program"` / `if ... == "app"` branch cleanup remained after scan.
- `P3 None/default fallback`: removed `runner/libs/app_runners/bpftrace.py:58-66` collector fallback, `runner/libs/app_runners/bcc.py:368-394` name-or-binary constructor fallback, and `e2e/cases/scx/case.py:663-667` dead `scheduler_binary.exists() else None` payload fallback.
- `P4 空壳 helper`: removed single-use `runner/libs/app_runners/bpftrace.py:_resolve_script()`.
- `P5 env surface`: scanned `runner/libs/` / `runner/suites/` env reads; no asymmetric write/read surface in allowed scope that was both dead and safe to delete this round.
- `P6 配置 / CLI / env 多重 surface`: reviewed allowed YAML/config consumers; no unread `bcc/bpftrace/scx/katran` config field required deletion. The only live cleanup here was removing dead payload surface in `scx`.
- `P7 死参数 / 死形参`: removed `_build_summary(app_count,status_counts)` fake parameters in `corpus/driver.py`, removed static `policy_context` parameter from `e2e/cases/bcc/case.py:117-177`, and removed dead constructor parameters from `runner/libs/app_runners/bcc.py:368-394`.
- `P8 跨 bcc/bpftrace/scx/katran activity gate`: same grep as `P1`; 0 hits in allowed case files and `runner/libs/case_common.py`.
- `P9 daemon Rust short-circuit / dead code`: scanned `unreachable!|todo!|unimplemented!|eprintln!.*stderr`; only valid loud-fail / invariant sites remained. No Rust edit was warranted.
- `P10 死字段`: removed `corpus` payload field `suite_summary`, removed write-only `command_used` assignments in `bcc/scx` runners, and removed dead `scx` preflight/mode payload residue.

## 真 lazy / 死代码清单
- High: `runner/libs/app_suite_schema.py:93` + `corpus/driver.py:1023-1184,1215-1259` carried a dead tuple summary through the corpus path even though no live reader consumed it.
- High: `runner/libs/app_runners/bcc.py:368-394` exposed a dead constructor surface (`tool_binary or tool_name`, optional tool discovery, optional args) even though the repo has exactly one caller and it always passes an explicit binary and args.
- Medium: `runner/libs/app_runners/bpftrace.py:58-66,95-107` kept a dead `collector=None` branch plus a single-use `_resolve_script()` helper.
- Medium: `e2e/cases/scx/case.py:407-412,485-501,663-667` still emitted/reporting single-value and already-proven fields (`mode`, `state_before`, `scheduler_binary` fallback) after the real preflight block was gone.
- Low: `runner/libs/app_runners/bcc.py:407` and `runner/libs/app_runners/scx.py:89-103,333-336` still wrote `command_used` values that no consumer in allowed scope reads.

## 删除清单
- `runner/libs/app_suite_schema.py:93`: `load_app_suite_from_yaml()` now returns only `AppSuite`; deleted the dead tuple summary half.
- `corpus/driver.py:718-750`: `_build_summary()` now computes `app_count` and `statuses` internally instead of taking dead caller-provided values.
- `corpus/driver.py:1023-1184`: `run_suite()` now consumes the already-parsed `AppSuite`; payload no longer writes dead `suite_summary`.
- `corpus/driver.py:1215-1259`: `main()` parses the suite once and passes it through instead of reloading the manifest.
- `runner/libs/app_runners/bpftrace.py:58-66`: removed `collector=None` fallback; output finalization now uses the only live collector path.
- `runner/libs/app_runners/bpftrace.py:95-133`: inlined script lookup and removed the dead `_resolve_script()` / stored `script_path` / write-only command tracking.
- `runner/libs/app_runners/bcc.py:368-394`: constructor now requires explicit `tool_binary` and `tool_args`; removed dead tool-name lookup and tools-dir fallback surface.
- `runner/libs/app_runners/bcc.py:407`: removed write-only `command_used` assignment.
- `e2e/cases/bcc/case.py:117-177`: removed dead `policy_context` parameter and inlined the fixed ReJIT policy context.
- `e2e/cases/bcc/case.py:467-473`: caller no longer passes the static `policy_context` shell.
- `runner/libs/app_runners/scx.py:89-103`: removed write-only `command_used` field from `ScxSchedulerSession`.
- `runner/libs/app_runners/scx.py:333-336`: removed write-only `command_used` copy from `ScxRunner.start()`.
- `e2e/cases/scx/case.py:407-412`: removed markdown emission of dead single-value `mode`.
- `e2e/cases/scx/case.py:485-501`: removed unused `state_before` and the empty `scheduler_extra_args=[]` surface.
- `e2e/cases/scx/case.py:663-667`: removed dead `scheduler_binary.exists() else None` fallback and the corresponding payload `mode` field.

## 未删保留清单
- `corpus/driver.py:958-965`: keep. If the workload never hit target programs, the corpus result is invalid and must loud-fail.
- `e2e/cases/scx/case.py:660-681`: keep. Missing post-ReJIT phase is a hard error, not optional output.
- `runner/libs/case_common.py:297,346`: keep. `program_counts` there are reporting fields, not gates or filters.
- `daemon/src/commands.rs:456-461`: keep. Missing original bytecode must loud-fail.
- `daemon/src/passes/cond_select.rs:100,261,265`: keep. These `unreachable!` sites are guarded invariants, not dead branches.

## 验证
- `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile corpus/driver.py runner/libs/app_suite_schema.py runner/libs/app_runners/{bcc,bpftrace,scx}.py e2e/cases/{bcc,scx}/case.py`: passed.
- `source /home/yunwei37/workspace/.venv/bin/activate && make check`: passed.
- `rg -n -S 'require_.*activity|activity_gate|did not execute any target programs|zero .*program executions|expected_programs|min_programs|max_programs' e2e/cases/bcc e2e/cases/bpftrace e2e/cases/katran e2e/cases/scx runner/libs/case_common.py`: 0 hits.
- `git diff --shortstat -- corpus/driver.py runner/libs/app_suite_schema.py runner/libs/app_runners/bcc.py runner/libs/app_runners/bpftrace.py runner/libs/app_runners/scx.py e2e/cases/bcc/case.py e2e/cases/scx/case.py`: `7 files changed, 43 insertions(+), 135 deletions(-)`; net `-92 LOC`.
- `cargo test --manifest-path daemon/Cargo.toml`: not run, because this round did not modify `daemon/src/**`.

## 自我 Review
- No compat shim, no new flag/env/config surface.
- No error path was converted into silent skip; removed branches were dead defaults or single-path residue.
- The final diff stays inside the allowed scope and does not touch `tetragon/tracee/runner-runtime.Dockerfile/build.mk`.
