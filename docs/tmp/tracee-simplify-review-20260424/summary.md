# Tracee Simplify Review 2026-04-24

## Verdict

通过，但在 review 过程中发现并修了 1 个残留问题。

- `e2e/cases/tracee/case.py` 虽然已经删掉了大部分统计/比较框架，但每条 record 里还残留了不在目标范围内的数据：collector 派生的 `event_counts` / `drop_counters` / `event_parse_errors`，以及 `agent_cpu` / `system_cpu` / `ops_total`。这和“只保留 daemon 原始输出一份、benchmark 测量数据一份、基本元数据”的目标不一致。
- 已修复为最小 record 结构：`cycle_index`、`name`、`kind`、`metric`、`app_throughput`、`bpf`。对应 markdown 也只渲染 throughput 和 `bpf` summary，不再渲染 event/cpu 派生字段。

## Tracee Check Items

- 已完整读取当前 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py)。
- 已检查 `git diff HEAD -- e2e/cases/tracee/case.py`，本次改动确实是“大删减 + 少量重组”。
- 已确认以下内容已正确删除，当前 `case.py` / `config.yaml` 中均不存在：
  - `verify_phase_measurement` 及调用
  - `paired_cycles`
  - `bootstrap_mean_ci`
  - `summarize_numeric_distribution`
  - `exact_paired_permutation_pvalue`
  - `paired_metric_report`
  - `summarize_phase`
  - `compare_phases`
  - `aggregate_phase_samples`
  - latency probe 整套代码
  - `_filtered_float_values`
  - `phase_records`
  - `summarize_workload_samples`
- 已确认以下内容仍被正确保留：
  - `measure_workload()` 核心逻辑仍在 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:51) 到 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:72)，保留 `throughput` 和 `bpf_stats delta`
  - `run_phase()` 核心仍在 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:75) 到 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:97)，负责跑 workload 并收集 records
  - lifecycle 流程仍在 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:226) 之后的 `setup/start/workload/stop/cleanup`
  - `result.md` 生成仍保留：Tracee 的 renderer 在 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:126)，统一写盘入口在 [e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py:261)
- 已检查误删风险：
  - 必要 import 仍完整
  - `build_markdown()` 仍导出并被 `e2e/driver.py` 使用
  - error payload 仍可生成 `result.md`
- 已检查遗漏：
  - 修复前仍有 event/cpu/ops 残留字段
  - 修复后 `tracee/case.py` 中已无额外分析/聚合/统计路径残留

## Related Diffs

- [runner/libs/app_runners/process_support.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/process_support.py:27) 到 [runner/libs/app_runners/process_support.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/process_support.py:89)
  - 新增 `describe_process_exit()` 和更详细的 program-set stabilization 诊断。
  - 逻辑合理，能更早暴露“进程先退出、程序集尚未稳定”的失败原因。
- [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:57) 到 [runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:69)
  - 把上面的诊断接进 Tetragon 启动路径，并保留 cleanup 错误拼接。
  - 逻辑合理，没有看到行为回退风险。
- [e2e/cases/tetragon/sync_upstream_policies.sh](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/sync_upstream_policies.sh:13)
  - 删除 3 个 upstream policy，并在同步脚本里写明具体 VM/kernel 失败原因。
  - 这组改动合理，属于“把已验证会失败的 policy 从 bulk-load 集里剔除”，不是静默删除。

## Validation

- `python3 -m py_compile e2e/cases/tracee/case.py`: passed
- `make check`: passed
- 注意：当前仓库里的 `make check` 实际只执行 repository-wide `py_compile`，不是功能/集成测试
- 本地 `git status` 需要加 `--ignore-submodules=all` 才能工作，因为 `vendor/libbpf` 子模块指向了一个不存在的临时路径；这不影响本次 review 结论
