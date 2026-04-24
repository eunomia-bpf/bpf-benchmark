# Design Cleanliness Audit 2026-04-23

只读静态审计。未改源码，未跑 `make` / VM / AWS。`daemon/src/`、`bpfopt-suite/`、`vendor/linux-framework/`、`runner/repos/`、runtime artifacts、`runner/build-*` 均排除。

## 1. 维度 1-12 逐项审计

### 1. 多层 abstraction 只有单个实现 / 单个消费者

- 命令：`rg -n '^class ' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`57`
- 命令：`rg -n '^@dataclass' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`31`
- 命令：`rg -n '\bProtocol\b|\bABC\b|@abstractmethod' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`0`
- 判断：`有 1 条疑似`
- 结论：
  - `AppRunner` 有 6 个实现，`AgentSession` 有 3 个实现，不存在“只有 1 个实现的抽象基类/Protocol”。
  - 真正偏薄的是 [runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:18) 的 `SuiteSelection`：只有一个 `test_mode` 字段，主要只在 [runner/libs/run_contract.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/run_contract.py:294) 被拆回标量。

### 2. 类似 / 重复逻辑

- 命令：`rg -n 'run_case_lifecycle|run_app_runner_lifecycle|run_app_runner_phase_records|measure_app_runner_workload|def run_phase\(|def measure_workload\(|def _measure_runner_phase\(' corpus e2e runner -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`32`
- 判断：`明显问题`
- 结论：
  - [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1124) 仍然自己维护一套 `start -> baseline -> scan/apply -> post -> stop` 状态机，和 [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:299) 的通用 lifecycle helper 平行存在。
  - `bcc` / `bpftrace` 两个 E2E case 仍保留近乎同构的 `run_phase + summarize + markdown/report + aggregate` 链。

### 3. config / flag / env / default 多重 surface

- 命令：`rg -n 'os\.environ|argparse|ArgumentParser|config\[[^]]+\]|config\.get\(|def __init__\([^\n]*=' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`141`
- 命令：`rg -n 'SAMPLES|WARMUPS|INNER_REPEAT' Makefile runner/libs/suite_args.py runner/libs/run_target_suite.py runner/suites/micro.py docs/kernel-jit-optimization-plan.md -g 'Makefile' -g '*.py' -g '*.md' | wc -l`
  - 命中：`20`
- 命令：`rg -n 'daemon-binary|--daemon|args\.daemon|resolve_daemon_binary' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`23`
- 判断：`明显问题`
- 结论：
  - `micro` 的同一组 benchmark 默认值有冲突：
    - [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:37) 设的是 `SAMPLES=3`, `WARMUPS=1`, `INNER_REPEAT=100`
    - [runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:71) 设的是 `1/0/10`
    - [runner/libs/run_target_suite.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/run_target_suite.py:140) 在没显式传 `suite_args` 时会走后者
    - [runner/suites/micro.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/micro.py:51) 又把这三个参数做成 required CLI
  - 这不是单纯“多一层转发”，而是不同入口会得到不同默认 benchmark 语义。
  - `--daemon-binary -> resolve_daemon_binary() -> --daemon` 这条链虽然重复验证，但优先级是清楚的，没形成语义冲突。

### 4. artifact / metadata dict 死字段

- 命令：`rg -n 'artifacts\[|self\.artifacts\b' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`12`
- 命令：`rg -n 'metadata\[|self\.metadata\b' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`15`
- 命令：`rg -n '\bsuite_summary\b|\bscript_text\b' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`3`
- 判断：`有 2 条疑似`
- 结论：
  - [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1423) 把 `suite_summary` 写进结果，但 live code 里只有配对的加载点 [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1126)。
  - [e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:439) 把 `script_text` 塞进 payload，仓库内没有 reader。
  - daemon 返回的 `scan_results` / `counts` / `summary` / `rejit_result` 仍然被 corpus / e2e / markdown/reporting 路径读取，不属于死字段。

### 5. 重复的辅助函数 / 小 helper

- 命令：`rg -n 'def (_resolve_.*binary|resolve_.*binary|ensure_artifacts|ensure_required_tools)' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`16`
- 命令：`rg -n 'def run_phase\(|def geomean\(|def collect_record_errors\(|def build_markdown\(|def build_report\(' e2e/cases -g 'case.py' | wc -l`
  - 命中：`17`
- 判断：`有 2 条疑似`
- 结论：
  - 明显重复集中在 BCC / bpftrace 两个 case。
  - `ensure_artifacts()` / `resolve_*_binary()` 家族虽然名字相似，但大多是“daemon 存在性 + app 自身 artifact/preflight”组合，抽掉后的净收益不大。

### 6. wrapper class / adapter / proxy 只转发

- 命令：`rg -n '__getattr__|__setattr__|self\._inner\.|self\._wrapped\.' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`0`
- 判断：`干净`
- 结论：
  - 没发现 `__getattr__`/`_inner`/`_wrapped` 这类纯转发壳。
  - 现有 adapter 多半在做参数规范化，不是空代理。

### 7. Reporting / summarize 层是否过厚

- 命令：`rg -n 'def summarize_|def compare_|def build_report|def build_markdown|def _build_program_measurements' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`29`
- 判断：`有 2 条疑似`
- 结论：
  - 没找到“三层 summarize 来回重组同一批字段”的死循环。
  - 厚度主要来自两处：
    - BCC / bpftrace 各自保留一整套近似相同的 markdown/report renderer
    - 少量 write-only payload 字段（上面的 `suite_summary` / `script_text`）
  - `changed` / `applied` / `comparable` 等字段目前仍被各自 case 的比较/展示逻辑消费，没有证据表明能直接合并成一个布尔位。

### 8. Makefile / mk 结构

- 命令：`rg --files runner/mk -g '*.mk' | wc -l`
  - 命中：`1`
- 命令：`rg -n '^include |^\.PHONY:|^[A-Za-z0-9_.-]+:' Makefile runner/mk -g 'Makefile' -g '*.mk' | wc -l`
  - 命中：`37`
- 判断：`相当干净`
- 结论：
  - 按用户禁止项，未执行 `make -pn`，这里只做静态结构检查。
  - `runner/mk/` 只有一个 [runner/mk/build.mk](/home/yunwei37/workspace/bpf-benchmark/runner/mk/build.mk:1)，image target 也都能在 [runner/containers/runner-runtime.Dockerfile](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:197) 看到调用。
  - 没证明出死 rule；构建层真正的问题不在 target 图，而在 `check` 的第二份 Python 文件清单，见维度 9。

### 9. 测试代码

- 命令：`rg -n 'def test_|@pytest.fixture' tests runner/tests -g '*.py' 2>/dev/null | wc -l`
  - 命中：`0`
- 判断：`明显问题`
- 结论：
  - 专门的 Python test 目录里没有 live pytest 测试。
  - 更大的问题是 [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:101) 的 `check` 只是手写 `py_compile` allowlist。静态比对结果是：
    - `check` 列了 `33` 个 `.py`
    - 实际 live `.py` 有 `68` 个
    - `35` 个没被 `check` 覆盖
  - 漏掉的是真正热路径，不是边角料；例子：
    - [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1)
    - [e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py:1)
    - [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:1)
    - [runner/libs/reporting.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/reporting.py:1)

### 10. docs/tmp/ 结构

- 命令：`rg -n 'e2e-cases|tracing-policy-dir|DEFAULT_POLICY_DIR' docs/tmp/delete-cli-args-20260423/summary.md docs/tmp/delete-filters-all-programs-20260423/summary.md docs/tmp/program-coverage-gaps-20260423/summary.md docs/tmp/round2-delete-subset-selection-20260423/summary.md docs/tmp/final-review-20260423/summary.md | wc -l`
  - 命中：`23`
- 判断：`明显问题`
- 结论：
  - 这些 working summaries 之间仍有当前态冲突：
    - [docs/tmp/delete-cli-args-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/delete-cli-args-20260423/summary.md:47) 还展示 `--e2e-cases "all"`
    - [docs/tmp/delete-filters-all-programs-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/delete-filters-all-programs-20260423/summary.md:45) 还把 `DEFAULT_POLICY_DIR` / `--tracing-policy-dir` 写成当前态
    - [docs/tmp/program-coverage-gaps-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/program-coverage-gaps-20260423/summary.md:87) 同样把 `--tracing-policy-dir` 当当前事实
    - [docs/tmp/round2-delete-subset-selection-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/round2-delete-subset-selection-20260423/summary.md:41) 则明确说这些都已删
  - 写本报告前，`git status --short docs/tmp` 里有 `1` 个未跟踪目录：`docs/tmp/daemon-rust-audit-20260423/summary.md`。它看起来是当前并行审计产物，不像历史 linger。

### 11. 全局状态 / 隐式 coupling

- 命令：`rg -n '^[A-Z_][A-Z0-9_]*\s*=\s*' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`183`
- 命令：`rg -n '^ROOT_DIR\s*=\s*Path\(__file__\)\.resolve\(\)\.parents\[2\]' runner e2e corpus -g '*.py' --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' | wc -l`
  - 命中：`2`
- 判断：`有 1 条疑似`
- 结论：
  - 绝大多数全局都是 immutable 常量，没有跨模块 mutate 的 singleton。
  - 唯一清楚的重复路径根定义是：
    - [runner/libs/__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/__init__.py:12)
    - [runner/libs/input_generators.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/input_generators.py:9)

### 12. 未实施 TODO / FIXME / XXX / HACK

- 命令：`rg -n 'TODO|FIXME|XXX|HACK|KLUDGE' runner e2e corpus Makefile docs/kernel-jit-optimization-plan.md --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' --glob '!e2e/cases/bpftrace/scripts/*.bt' | wc -l`
  - 命中：`5`
- 命令：`rg -n 'TODO:' runner e2e corpus Makefile docs/kernel-jit-optimization-plan.md --glob '!runner/build-*/**' --glob '!runner/repos/**' --glob '!e2e/results/**' --glob '!corpus/results/**' --glob '!e2e/cases/bpftrace/scripts/*.bt' | wc -l`
  - 命中：`1`
- 判断：`有 1 条疑似`
- 结论：
  - 唯一真的待清 comment 是 [runner/src/kernel_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/runner/src/kernel_runner.cpp:968)。
  - 其余命中是：
    - 计划文档的“TODO 条目必须保留状态”规则
    - `mktemp ... XXXXXX`
    - `HACKBENCH_TIME_RE` 标识符名

## 2. 真 Finding 清单

### 🔴 BLOCKER

- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1137) 仍保留 corpus 自己的 lifecycle state machine，到 [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1335) 为止完整重复了 `start -> baseline -> scan/apply -> post -> stop` 骨架；这和 [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:299) 的通用 lifecycle 并存，而且也偏离了计划文档“Corpus 和 E2E 唯一区别是指标，不是生命周期”的要求（`docs/kernel-jit-optimization-plan.md:421-427`）。
- [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:37)、[runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:71)、[runner/libs/run_target_suite.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/run_target_suite.py:140)、[runner/suites/micro.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/micro.py:51) 对 `SAMPLES/WARMUPS/INNER_REPEAT` 维护了冲突的多重默认面。`make vm-micro` 和直接走 `run_target_suite` 的默认 benchmark 语义并不一致，这不能算“干净”。
- [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:101) 的 `check` 维护了一份手写 Python 文件 allowlist，但静态比对已经漂移到只覆盖 `33/68` 个 live `.py`。被漏掉的文件包括 [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1)、[e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py:1)、[e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:1)、[runner/libs/reporting.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/reporting.py:1)。这是明显的第二份源文件清单。

### 🟡 SHOULD

- [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:123) 到 [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:564) 与 [e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:131) 到 [e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:489) 仍有大块近似同构逻辑：`run_phase`、summary 聚合、`geomean`/`collect_record_errors`、markdown/report、top-level record 聚合都各写了一份。
- [docs/tmp/delete-cli-args-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/delete-cli-args-20260423/summary.md:47)、[docs/tmp/delete-filters-all-programs-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/delete-filters-all-programs-20260423/summary.md:45)、[docs/tmp/program-coverage-gaps-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/program-coverage-gaps-20260423/summary.md:87) 仍把已删 surface 写成当前态；而 [docs/tmp/round2-delete-subset-selection-20260423/summary.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/round2-delete-subset-selection-20260423/summary.md:41) 已明确记录删除。`docs/tmp/` 作为 working-summary 区，这种冲突会直接误导后续 reviewer。

### 🟢 NICE

- [runner/libs/app_runners/base.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/base.py:39) 的 `program_fds` 接口在 live tree 里只有一个空 override：[runner/libs/app_runners/scx.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/scx.py:321)。仓库内没有 reader。
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1423) 的 `suite_summary` 与 [e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:439) 的 `script_text` 都是 write-only payload 字段，仓库内没有消费方。
- [runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:18) 的 `SuiteSelection` 是一层很薄的标量包装，只有 `test_mode`，主要在 [runner/libs/run_contract.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/run_contract.py:294) 被立即拆开。
- [runner/libs/input_generators.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/input_generators.py:9) 重复定义了 `ROOT_DIR`，而同一个定义已经存在于 [runner/libs/__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/__init__.py:12)。

## 3. 可合并的双份逻辑

- Lifecycle skeleton
  - 代码：
    - [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1137)
    - [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:299)
  - 建议：
    - 不要让 corpus 再维护第二套 loader lifecycle。
    - corpus 特有的“多 app 分组 scan/apply + slice 回单 app”可以保留，但 `start/baseline/post/stop/error fanout` 这层应回到 shared helper。

- BCC / bpftrace E2E orchestration
  - 代码：
    - [e2e/cases/bcc/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bcc/case.py:123)
    - [e2e/cases/bpftrace/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/bpftrace/case.py:131)
  - 建议：
    - 两边都已经落在 `run_app_runner_phase_records()` 之上，剩余的 phase wrapper / summary / aggregate / markdown/report 可以进一步合并，至少不该各自再维持一套 `geomean + collect_record_errors + table/report`。

- micro benchmark 默认值
  - 代码：
    - [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:37)
    - [runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:71)
    - [runner/libs/run_target_suite.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/run_target_suite.py:140)
  - 建议：
    - `SAMPLES/WARMUPS/INNER_REPEAT` 需要单一权威；现在 root Makefile 和 Python contract 各自维护默认值，应该删掉一边。

- Python source inventory
  - 代码：
    - [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:101)
    - live tree examples: [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1), [e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py:1), [runner/libs/reporting.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/reporting.py:1)
  - 建议：
    - `make check` 不应再保留一份手写 Python 文件表；这已经变成第二份、而且过时的 source inventory。

## 4. 合理保留清单

- [runner/libs/app_runners/process_support.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/process_support.py:15) 的 `programs_after()` / `wait_until_program_set_stable()` 是真正共享的底层原语，不是多余 wrapper。
- [runner/libs/app_runners/__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/__init__.py:9) 的 adapter 表是合理保留：它在做 corpus/E2E 共享 runner 的参数归一化，不是空转发。
- [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:238) 的 live-id remap 应保留。SCX scheduler 在 baseline 后 live prog id 会变化，这和 tracee/tetragon 用 workload 名字做 phase compare 不是同一问题，不能硬抽成一个“by_name helper”。
- `BPFTOOL_BIN` 的多 surface 也基本合理：
  - [runner/suites/_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/_common.py:292)
  - [runner/libs/run_contract.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/run_contract.py:51)
  - [runner/libs/__init__.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/__init__.py:19)
  - 这是 host CLI -> contract -> runtime resolution 的跨边界传递，不是简单重复配置。
- [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:188) 的 `aws-e2e` / [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:195) 的 `aws-corpus` 本轮不判死。它们和 arch-specific target 重叠，但计划文档把它们记录为仍在使用的单-suite AWS 入口，静态代码里也确实是活 target，不是尸体。

## 5. Corpus vs E2E lifecycle 合并评估

- 重叠区：
  - [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:299) 已经抽出了通用 `start -> baseline -> scan -> apply -> post -> stop`
  - [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1137) 到 [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1335) 又手写了一遍相同骨架
- 预估收益：
  - 能删掉一套独立 state machine 和它的 error/fatal fanout 语义
  - 粗看可净减大约 `80-120` 行 orchestration 代码，外加少一套“修 lifecycle bug 时要双改”的维护负担
  - 更重要的是回到计划文档定义的“loader instance 是唯一生命周期单元”
- 合并风险：
  - corpus 目前不是简单的“单 loader 跑 N 次”，而是“多 app 并发启动、统一 baseline、统一 scan/apply、再回切每 app post”
  - [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1260) 的 grouped apply / slice 回填是 corpus 特有逻辑，不能粗暴替换成“对每个 app 调一次 `run_case_lifecycle()`”
  - 天真的全量合并会改变测量顺序、daemon 交互粒度和 suite 级失败传播
- 结论：
  - 值得合并，但应当合并“生命周期骨架”，不是强行把 corpus 变成逐 app 调 helper 的完全同构流程。
  - 换句话说：`shared lifecycle + corpus-specific batch apply` 是低风险方向；`彻底把 corpus 改成 e2e 形状` 风险偏高。

## 6. 签收意见

- 干净度评分：`3 / 5`
- 一句话理由：
  - Round 8 之后主路径已经明显变薄，但还剩 `3` 个不能忽视的结构问题：`corpus` 第二套 lifecycle、`micro` 默认值双权威、`make check` 第二份且已过时的 Python source inventory。现在可以说“已经相当整洁”，不能说“删无可删”。
- 下一步最值得做的 3 件事：
  1. 把 corpus 的 lifecycle 骨架并回 shared helper，删掉 `corpus/driver.py` 里的第二套状态机。
  2. 把 `SAMPLES/WARMUPS/INNER_REPEAT` 收敛到单一默认来源，删掉冲突的一份默认面。
  3. 删掉 `make check` 的手写 Python allowlist 这份第二 source inventory，别再让 build system 维护一份已经漂移的文件表。
