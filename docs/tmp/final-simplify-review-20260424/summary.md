# Final Simplify Review

## Verdict

这轮 `e2e/corpus/runner` 简化后的主线现在是通的。静态审查覆盖了当前完整代码，修掉了 5 个真实问题后，未再发现会阻断 `e2e`/`corpus` 生命周期、写盘、catalog 接入或导入解析的剩余硬错误。

本轮直接修复了这些问题：

1. `runner/libs/app_runners/__init__.py`
   `corpus` 里的 BCC app 之前通过 `get_app_runner()` 传的是 `tool_name`，但 `BCCRunner` 实际需要的是 `tool_binary` 和 `tool_args`，导致 `TypeError: unexpected keyword argument 'tool_name'`。现在改成从 `benchmark_catalog.py` 和 BCC setup 里解析真实 binary/args。
2. `e2e/cases/tetragon/case.py`
   最近 linter 改动后，`DEFAULT_WORKLOADS` 只消费了 `TETRAGON_E2E_WORKLOADS[0]`，等于把 catalog 接入写死成“只吃第一项”。现在改成完整消费 `TETRAGON_E2E_WORKLOADS`，并在空 workload 配置时直接报错。
3. `e2e/cases/katran/case.py`
   缺少 `Path` 导入，直接执行模块时会在 `__package__` fallback 路径上炸掉。已补上，并把 `daemon` 路径写进 payload。
4. `runner/libs/app_runners/tracee.py`
   `TRACEE_OUTPUT_MODE` 固定为 `none` 时，event-file collector 分支是不可达死代码。已删掉 `event_tail` / event file thread / 相关辅助逻辑，保留实际在用的 stdout/stderr tail。
5. `corpus/driver.py`
   app `start()` 失败路径之前不会显式等 quiescence，可能把未稳定的程序表残留带到下一个 app。现在在 start-failure 清理后补了 `wait_for_suite_quiescence()`，并顺手去掉了 `_build_app_error_result()` 的无用参数。

## Files Read

按“当前完整内容，不是 diff”读完了这批实际相关文件：

- `corpus/driver.py`
- `corpus/config/macro_apps.yaml`
- `e2e/driver.py`
- `e2e/README.md`
- `e2e/cases/bcc/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/katran/case.py`
- `e2e/cases/scx/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/tetragon/sync_upstream_policies.sh`
- `e2e/cases/tracee/case.py`
- `runner/libs/benchmark_catalog.py`
- `runner/libs/app_suite_schema.py`
- `runner/libs/bpf_stats.py`
- `runner/libs/case_common.py`
- `runner/libs/rejit.py`
- `runner/libs/suite_args.py`
- `runner/libs/run_artifacts.py`
- `runner/libs/app_runners/__init__.py`
- `runner/libs/app_runners/base.py`
- `runner/libs/app_runners/bcc.py`
- `runner/libs/app_runners/bpftrace.py`
- `runner/libs/app_runners/katran.py`
- `runner/libs/app_runners/process_support.py`
- `runner/libs/app_runners/scx.py`
- `runner/libs/app_runners/tetragon.py`
- `runner/libs/app_runners/tracee.py`
- `runner/suites/e2e.py`
- `runner/suites/corpus.py`
- `runner/mk/build.mk`

## Checklist

1. `6` 个 e2e case lifecycle 完整
   结论：通过。
   `bcc` / `bpftrace` / `katran` 统一走 `run_app_runner_lifecycle()`，实际顺序是 `runner.start()` -> baseline `measure()` -> `daemon.apply_rejit()` -> post-rejit `measure()` -> `runner.stop()`，主流程在 `runner/libs/case_common.py:303-331` 和 `runner/libs/case_common.py:109-219`。
   `tracee` / `tetragon` / `scx` 显式走 `run_case_lifecycle()`，各 case 都提供了 `start/workload/stop`，由同一套 lifecycle 框架串起来，分别见 `e2e/cases/tracee/case.py:273-359`、`e2e/cases/tetragon/case.py:184-240`、`e2e/cases/scx/case.py:238-291`。

2. `result.json` 包含原始测量数据 + daemon `rejit_result` + 基本元数据
   结论：通过。
   `e2e/driver.py:195-245` 会把 case payload 原样写入 `details/result.json`。各 case payload 都有 `generated_at` 和测量数据。
   `bcc` / `bpftrace` 的 `rejit_result` 在 `records[].rejit_result` 里；我直接检查了最新 artifact，record 键是 `baseline/post_rejit/rejit_result/process/name`。
   `katran` / `scx` / `tetragon` / `tracee` 顶层都有 `rejit_result`。
   `corpus` 当前代码的 app 结果结构由 `corpus/driver.py:312-328` 定义，顶层 payload 在 `corpus/driver.py:491-504` 组装，`main()` 在 `corpus/driver.py:571-600` 写入 artifact。
   注意：仓库里已经存在的 `corpus/results/*.json` 是旧样例，不应拿来判断当前 writer schema；当前代码路径已经是新的简化结构。

3. `result.md` 能生成
   结论：通过。
   我直接调用了所有 `build_markdown()`：
   `bcc`、`bpftrace`、`katran`、`scx`、`tetragon`、`tracee`、`corpus` 全部返回非空字符串。

4. 没有断掉的 import
   结论：通过。
   做了两层检查：
   `python -m py_compile` 覆盖 `corpus/runner/e2e` 当前 Python 文件。
   AST + `importlib.util.find_spec()` 检查所有绝对 `from ... import ...` 模块解析，结果为 `absolute-from-imports-ok`。
   额外做了模块导入 smoke：`import e2e.driver, corpus.driver, ...` 通过。

5. 没有引用已删函数/模块
   结论：通过。
   精确 grep 未发现这些残留引用：
   `runner.libs.metrics`
   `summarize_phase_measurement`
   `compare_phases`
   `bootstrap_mean_ci`
   `verify_phase_measurement`
   `paired_cycles`
   `latency_probe`
   `scan_programs`

6. `benchmark_catalog.py` 被正确消费
   结论：通过，且修了两处实质性接线问题。
   `corpus/driver.py` 消费 `DEFAULT_CORPUS_SAMPLES` 和 `DEFAULT_CORPUS_WORKLOAD_DURATION_S`。
   `e2e/cases/tracee/case.py` 消费 `TRACEE_E2E_*`。
   `e2e/cases/tetragon/case.py` 消费 `TETRAGON_E2E_*`，现在是完整消费整个 workload 列表。
   `e2e/cases/bcc/case.py` 和 `runner/libs/app_runners/bcc.py` 消费 `BCC_*` 和 `BCC_TOOL_SPECS`。
   `runner/libs/app_suite_schema.py` 通过 `MACRO_APP_DEFINITION_BY_NAME` 解析 `schema_version: 2` 的 `macro_apps.yaml`。
   `runner/libs/app_runners/__init__.py` 现在也正确用 `BCC_TOOL_SPEC_BY_NAME` 构造 corpus BCC runners。

7. `corpus/driver.py` lifecycle 完整
   结论：通过。
   `corpus/driver.py:367-417` 负责 `start` 所有 app，然后统一交给 `run_lifecycle_sessions()` 做 baseline -> rejit -> post-rejit -> stop。
   `refresh_sessions` 会在 baseline 和 rejit 前刷新 live programs，见 `corpus/driver.py:279-289`。
   这次补了 start-failure 后的 quiescence，避免前一个 app 失败时把脏状态带到下一个 app。

8. `e2e/driver.py` 写盘流程正确
   结论：通过。
   `ArtifactSession` 在 `e2e/driver.py:186-193` 建立 run dir 并先写 `progress.json`。
   case 完成后会把 compacted payload 写到 `details/result.json`，并同步写 `result.md`，见 `e2e/driver.py:199-245`。
   出错路径也会落 `metadata.json` + `progress.json`，不会留下半成品空目录，见 `e2e/driver.py:250-265`。

9. `TraceeOutputCollector` 是否还有死代码
   结论：原来有，现在已经清掉。
   因为 `TRACEE_OUTPUT_MODE = "none"`，event-file path 和 `event_tail` 根本不会被走到。现在 `runner/libs/app_runners/tracee.py` 只保留 stdout/stderr collector 和健康检查实际用到的逻辑。

10. `make check`
   结论：通过。
   直接执行了 `make check`，返回 `0`。
   当前 `Makefile:86-93` 里的 `check` 目标本质上是对 `corpus/runner/e2e` 做 `py_compile`，它验证的是 Python 编译/语法层，不是完整 runtime smoke。

## Validation Commands Run

- `python -m py_compile ...` 覆盖本轮相关 Python 文件
- `python -c 'import ...'` 导入 smoke
- `python - <<PY ... importlib.util.find_spec ... PY` 检查绝对 `from ... import ...` 模块存在
- `python - <<PY ... build_markdown(...) ... PY` 验证 `result.md` 生成
- `python - <<PY ... get_app_runner(...) ... PY` 验证 macro suite runner 接口接线
- `make check`

## Remaining Notes

- 我没有再跑真实的 `vm-e2e` / `vm-corpus` runtime smoke；这次最终 verdict 依据的是完整代码阅读、导入/编译校验、现有 artifact 结构抽查、以及修复后的接口连通性验证。
- 以当前代码状态看，没有剩余的 P0/P1 级阻断问题。
