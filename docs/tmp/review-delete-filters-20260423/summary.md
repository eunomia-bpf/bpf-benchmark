# Review delete-filters-all-programs-20260423 (read-only)

Review 对象：主 codex `bxbls22nz` 的 in-flight diff（第一次快照点）。视角：找"应该删而没删"的抽象。未改文件，未跑 VM / e2e / corpus 测试。已忽略与"删 filter/select"无关的 daemon pass 内部 heuristic fallback 和 BCC Python compat shim（load-bearing kernel UAPI 桥，见主 summary 第 24 行注记）。

## 1. Diff 统计

- `git diff --shortstat`: `13 files changed, 279 insertions(+), 356 deletions(-)`
- `git status --short`：跟踪内变更 `M 10 / A 3 / D 0`。新增跟踪：`docs/tmp/delete-filters-all-programs-20260423/summary.md`、`e2e/cases/tetragon/policies/{10-kprobes.yaml,20-tracepoints.yaml}`。另有 7 个未跟踪 `e2e/results/*` 目录。

## 2. 仍未删除的 filter/select 位置

- `e2e/driver.py:297` `_filter_suite_workloads_config()` 读 case config、按 `suite_apps` 过滤 `workloads`、写临时 YAML 覆盖 `args.config`；`:617` / `:633` 有活调用点。**case 内删完 filter，suite 层又把 workload 选择补回来了**。
- `e2e/driver.py:336` `_configure_bcc_case_from_suite()` 按 `selected_names` 过滤 BCC `tools` 并重写 config。仍是 active subset selection。
- `e2e/driver.py:373` `_configure_bpftrace_case_from_suite()` 保留 `selected_names` / `args.scripts`。case 侧已改成全跑，这层是旧 script-selection 壳。
- `e2e/driver.py:389` `_configure_scx_case_from_suite()` 仍设置 `args.workloads`。`e2e/cases/scx/case.py:509` 已直接用 `workload_specs()`，这层已无消费者。
- `corpus/driver.py:72` corpus 入口仍接 `--filter`。显式 app subset 参数。
- `corpus/driver.py:1133` `run_suite()` 把 `filters=list(args.filters or [])` 传给 `load_app_suite_from_yaml()`，直接裁掉 suite app。
- `runner/libs/app_suite_schema.py:93` `_matches_filter()` 按 name/runner/workload/args 模糊匹配；`:147` 生成 `selected_apps` —— 剩余 filter 引擎本体。
- `runner/libs/app_runners/tetragon.py:88` `DEFAULT_POLICY_DIR` + `:202` 强制 `--tracing-policy-dir`，始终注入仓库内 policy pack。**旧 synthetic policy 没真正删，只是从 runtime 生成换成了 repo 内静态 gating**。
- `runner/libs/app_runners/tracee.py:255` `wait_for_event(event_names=...)` 保留 event-name 过滤 API；`e2e/cases/tracee/case.py:353` 唯一调用点传 `event_names=()`。旧 filter 语义埋在底层，改成"空参数=全量"。

## 3. 可疑的新增代码

- `runner/libs/app_runners/tetragon.py:88` `:91` `:175` `:202`、`e2e/cases/tetragon/policies/{10-kprobes,20-tracepoints}.yaml:1`、`e2e/cases/tetragon/case.py:587` `:588` `:704` `:705` `:733` `:734`：把"启动时生成临时 policy"替换为"仓库内静态 policy pack + artifacts plumbing"。不是 delete-only，而是保留并扩大了旧 policy-gating 机制。
- `runner/libs/app_runners/tracee.py:438` 固定 `--events "*"`。不是残留旧分支，但是新增显式 event-selection 逻辑；如果目标是删除 selection surface，需单独确认。
- `e2e/cases/tracee/config.yaml:11` `latency_probe_timeout_s` 从 5 提到 20，像为新 all-events 路径的补偿性调参。

## 4. 残留的二分支 / fallback

- `e2e/driver.py:340` `selected_names = explicit or list(named)` 保留"显式子集 or 默认全量"二分支；`args.tools` 已不再由 parser 提供，死 compat 分支。
- `e2e/driver.py:377` bpftrace 同上；`args.scripts` 已无 parser。
- `runner/libs/app_runners/tracee.py:263` `wanted_names` 为空时 `wait_for_event()` 自动退化成"匹配任意事件"。典型"空参数 → 默认全量"分支。
- `e2e/cases/tetragon/case.py:767` `for value in (config.get("tetragon_extra_args") or [])` 保留"key 缺失 → 空列表" fallback。旧 `--cgroup-rate` 链已从 config 删掉，但 backdoor surface 还在。

## 5. config 文件冗余字段

- `e2e/cases/tetragon/policies/10-kprobes.yaml`、`20-tracepoints.yaml` 本身是冗余 config artifact，只服务 policy-gating。
- `e2e/cases/tetragon/case.py:767` 读 `tetragon_extra_args`，但 checked-in `config_execve_rate.yaml` 已没这个 key —— config surface 没删干净，现有 config 恰好不再填写。
- 已清掉的旧 key 本轮未发现残留：`events` / `primary_events` / `latency_probe_events` / `expected_programs` / `target_programs` / `apply_programs` 全部 clean。

## 6. CLI / env 冗余参数

- `runner/suites/corpus.py:46` 仍暴露 `--corpus-filter` / `--filter`；`:106` 转发给 `corpus/driver.py --filter`。
- `runner/libs/suite_args.py:103` / `:108` 读 `AWS_*_CORPUS_FILTERS` 和 `FILTERS`；`:159` 解析 `--corpus-filter` / `--filter`。
- `runner/libs/run_contract.py:240` 根据 filtered suite 重新裁 `native_repos` / `scx_packages`。**filter 不只是测试便利参数，而是实际改变运行覆盖面**。
- `runner/suites/e2e.py:53` `:54` 暴露 `--e2e-cases` / `--e2e-case`；`runner/libs/suite_args.py:119` `:123` `:164` `:165` 读 `E2E_CASE(S)`。粗粒度 subset surface。

## 7. `expected_programs` 家族现状

`runner/` / `e2e/` / `daemon/` / `corpus/` live code/config 中已无 `expected_programs` / `expected_program` / `target_programs` / `apply_programs`。clean。

## 8. 总结

### 必须删（按影响）

1. **`e2e/driver.py` temp-YAML 过滤链**：`_write_suite_temp_yaml()` / `_filter_suite_workloads_config()` / `_configure_bcc_case_from_suite()` / `_configure_bpftrace_case_from_suite()` / `_configure_scx_case_from_suite()` + `apply_suite_case_config()` 的实际调用。**case 层删 filter 以后 suite 层把 subset selection 加回来了**，这是本轮最大漏洞。
2. **`runner/libs/app_runners/tetragon.py` + `e2e/cases/tetragon/policies/*.yaml` + `e2e/cases/tetragon/case.py` 静态 policy-pack 链**：本质仍是 policy-gating，旧 synthetic 挪成 repo-owned synthetic 并不算删。
3. **corpus filter 链**：`corpus/driver.py --filter` / `runner/suites/corpus.py` / `runner/libs/suite_args.py` / `runner/libs/app_suite_schema.py:_matches_filter()` / `runner/libs/run_contract.py`。

### 建议删

- `e2e/cases/tetragon/case.py:767` 的 `tetragon_extra_args` 读取 + 对应 runner extra-args surface。
- `runner/suites/e2e.py` / `runner/libs/suite_args.py` 的 `--e2e-cases` / `E2E_CASE(S)` 子集入口。
- `runner/libs/app_runners/tracee.py:255` `wait_for_event(event_names)` 过滤 API。

### 疑似死代码

- `e2e/driver.py:369` `:382` `:393` 的 `args.tools` / `args.scripts` / `args.workloads` 赋值。无 live consumer。
- `e2e/driver.py:340` `:377` `explicit or list(named)` 兼容分支。显式参数源已没。
- `runner/libs/app_runners/tracee.py:492` `DEFAULT_CONFIG` 常量。`_default_events()` 删除后无引用。

## 9. 不建议动

- `runner/libs/app_runners/bcc.py:351` `_prepare_bcc_python_compat`（已在主 summary 标注）——load-bearing 的第三方 UAPI 桥，非 API-shim 性质，删了 BCC tools 编译不过。
- daemon pass 内部 heuristic fallback（如常量传播遇到未知 symbol 时的保守退化）——这是真算法逻辑，不是"兼容分支"。
