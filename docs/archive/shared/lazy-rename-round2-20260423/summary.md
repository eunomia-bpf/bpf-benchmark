# Lazy-Rename Round 2 (2026-04-23)

范围：`corpus/`、`e2e/`、`runner/libs/` live code；未改 `vendor/linux-framework/`；未跑 `make vm-*`；Python 命令均使用 `/home/yunwei37/workspace/.venv/bin/python3`。

## 已知 2 处修复

- 修 1，`e2e/cases/tetragon/config_execve_rate.yaml` 文件名撒谎：
  `e2e/cases/tetragon/config.yaml` 由 `git mv` 重命名；`[e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:40)` 改成默认读 `config.yaml`。这条是 rename-only 修复，没有保留兼容别名；live code `config_execve_rate` grep 已归零。
- 修 2，`measurement_mode` / `corpus_measurement_mode` 单值死抽象：
  `[runner/libs/app_runners/base.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/base.py:10)` 删除常量方法 `corpus_measurement_mode()`，`[corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:725)`、[861](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:861)、[1098](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1098)、[1145](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1145) 同步删掉结果字段、session 字段、校验分支和所有 plumbing。相关删除量：`runner/libs/app_runners/base.py (-3)` + `corpus/driver.py (-21 relevant deletions)`。

## Pattern 1-7 新发现并已删除

- Pattern 6，`selected_apps` 是 Round 8 删除 subset 之后留下的旧命名壳：
  `[runner/libs/app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py:136)` 和 `[corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:725)` 统一改成 `app_count`。删除量：`runner/libs/app_suite_schema.py (-1)` + `corpus/driver.py (-3 relevant deletions)`。
- Pattern 3/5，corpus app runner 适配层还把 `workload` 当可空值，并给多个 runner 留着永远不走的 fallback：
  `[runner/libs/app_runners/__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/__init__.py:9)` 现在要求非空 `workload`，删掉 6 个 `if workload:` 死分支；`[runner/libs/app_runners/bcc.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/bcc.py:368)`、[scx.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/scx.py:292)、[katran.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/katran.py:886) 取消 `workload_spec` 死默认。删除量：`__init__.py (-23)` + `bcc.py (-2)` + `scx.py (-2)` + `katran.py (-13)`。
- Pattern 2/3/7，bpftrace 还保留双入口 `script_name | script_path` 和单用 wrapper `suite_scripts()`：
  `[runner/libs/app_runners/bpftrace.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/bpftrace.py:94)` 收敛为只接受 `script_name`；`[e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:125)` 删掉多余 `script_path=`，`[e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:400)` inline 单次使用的 `suite_scripts()`。删除量：`bpftrace.py (-23)` + `e2e/cases/bpftrace/case.py (-20)`。
- Pattern 3/4，Tracee/Tetragon runner 还偷偷把“未提供 workload_spec”伪装成 `exec_storm` 默认值，Tracee 还多留了一个从未 override 的 `startup_settle_s` 扩展点：
  `[runner/libs/app_runners/tracee.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tracee.py:492)` 删除 `startup_settle_s` 形参，并把缺失 `workload_spec` 改成 loud-fail；`[runner/libs/app_runners/tetragon.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/tetragon.py:142)` 同样移除假的 `exec_storm` 默认值。删除量：`tracee.py (-5)` + `tetragon.py (-1)`。
- Pattern 4/7，多个 e2e case 顶部还留着完全不再读取的 `DEFAULT_OUTPUT_JSON/MD(/REPORT_MD)`：
  `[e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:36)`、[katran/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py:26)、[scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:32)、[tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:50) 一并删除。删除量：`bcc/case.py (-7)` + `katran/case.py (-6)` + `scx/case.py (-7)` + `tracee/case.py (-8)`。

## Pattern 扫描结果

- Pattern 1：除 `measurement_mode` 之外，没有再找到成立的“单值 enum / 永远同一个分支”；剩余 `status == "ok"/"error"` 都是实打实两值状态。
- Pattern 2：`find e2e/cases -name 'config*.yaml'` 只剩 `bcc/config.yaml`、`tetragon/config.yaml`、`tracee/config.yaml`；没再发现文件名撒谎。
- Pattern 5：没再发现“历史多路现在只剩 1 路”的 live switch-case，剩余 workload kind 分支都至少有两个真实值。
- Pattern 6：除 `selected_apps` 外，没有再找到成立的永远同值结构字段。
- Pattern 7：`pass` 命中大多是 socket/file read loop 或 HTTP `log_message()` 静默输出；没有发现 class-body-only / function-body-only 的 live 壳。

## 验证

- `python3 -m py_compile corpus/driver.py e2e/cases/{bcc,bpftrace,katran,scx,tetragon,tracee}/case.py runner/libs/app_runners/{__init__,base,bcc,bpftrace,katran,scx,tetragon,tracee}.py runner/libs/app_suite_schema.py`：通过。
- `make check`：通过。当前目标实际展开为 repo-wide `py_compile`，未触发 VM。
- `rg -n "measurement_mode|corpus_measurement_mode" runner/ e2e/ corpus/ 2>/dev/null | grep -v __pycache__ | grep -v "corpus/results"`：无输出。
- `rg -n "config_execve_rate" runner/ e2e/ corpus/ 2>/dev/null | grep -v __pycache__ | grep -v "corpus/results"`：无输出。
- `git diff --shortstat`：`20 files changed, 73 insertions(+), 407 deletions(-)`，净 `-334 LOC`。

## 自我 Review

- 保留了 `TraceeRunner` / `TetragonRunner` 的 `workload_spec: Mapping[str, object] | None = None` 形参，但不再伪装成 `exec_storm` 默认值。原因：e2e start path 只需要启动/附着 runner，并不走 corpus 的 `run_workload()`；如果未来有人误用 `run_workload()`，现在会直接 loud-fail，而不是默默跑错 workload。
- 没删除 `DEFAULT_STARTUP_SETTLE_S` 常量本身，因为它仍是唯一真实生效的固定启动等待值；删掉的只是“可配置但从未配置”的形参表面。
- 没把 `runner/libs/app_runners/tetragon.py` / `tracee.py` 进一步拆成单独 corpus/e2e runner，因为这已经超出 lazy-rename 清理；本轮目标是删死壳，不重做结构。
