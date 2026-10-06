# Commit Review `a574a089`

范围：`git diff HEAD~1..HEAD`

**Findings**

1. High: `run_lifecycle_sessions()` 不再按 program policy 选 pass，而是把默认 benchmark pass 集直接应用到所有 program。这不是单纯“删冗余存储”，而是行为回退。[runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:127) 现在直接取 `benchmark_rejit_enabled_passes()`；[runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:199) 再把这同一组 pass 发给每个 session。可问题是 benchmark policy 仍然定义了 `struct_ops` 要禁用 `map_inline`/`dce`，[corpus/config/benchmark_config.yaml](/home/yunwei37/workspace/bpf-benchmark/corpus/config/benchmark_config.yaml:28) 明确写了这条规则。当前 `scx` e2e 又没有像 corpus 那样在 ReJIT 前跳过 live struct_ops，[e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:341) 直接走 `run_case_lifecycle()`。我本地用当前代码验证过：`benchmark_rejit_enabled_passes()` 仍包含 `map_inline,dce`，而旧的 `resolve_program_enabled_passes(..., {'prog_type': 'struct_ops'})` 会把它们去掉。也就是说，这个提交把原本受 policy 保护的 `scx` 路径重新暴露给全量 pass 了。

2. Medium: `scx` 的 live prog id 解析现在会在“一个 live program 都没刷新出来”时静默回退到旧 id，而不是 fail loud。[e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:82) 在 `allow_fallback=True` 时把 `live_programs` 回退为 `previous_programs`；随后 [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:90) 仍会按旧 name 生成 `logical_to_live`。`after_baseline()` 调用这个函数时用的正是默认 `allow_fallback=True`，[e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:327)；它只检查 `live_prog_ids` 非空，[e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:337) 并不会验证这些 id 真的还在当前 bpftool snapshot 里。这样一来，只要 refresh 暂时返回空集合，就可能把已经失效的旧 prog id 交给 daemon apply，而不是在 baseline 后直接报错。

**Requested Checks**

1. 有没有误删有价值的逻辑？
有，最值得保留的是“按 benchmark policy 做 per-program pass 选择”这条逻辑链。它不是展示层聚合，也不是重复存储，而是实际决定对每个 program 应用哪些 pass。这个提交把它删掉了，留下了 `benchmark_config.yaml` 和 `resolve_program_enabled_passes()`，但 live benchmark 路径已经不再使用它们。

2. 有没有引入新 bug？
有两处我认为是实质新回归：
- 上面的 policy 回归，会让 `struct_ops` 重新吃到本应禁用的 pass。
- `scx` live-id fallback 会把 stale id 当成 live id 继续往下走。

3. `benchmark_catalog.py` 内容是否正确覆盖了原来 `config.yaml` 的所有配置？
不是 1:1 全覆盖。
- BCC：是，`measurement_duration_s`、`attach_timeout_s`、tool 列表、`workload_spec`、`tool_args` 都搬到了 [runner/libs/benchmark_catalog.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/benchmark_catalog.py:32) 和 [runner/libs/benchmark_catalog.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/benchmark_catalog.py:43)。
- Tetragon：是，旧 `config.yaml` 里的 duration + workload 完整搬到了 [runner/libs/benchmark_catalog.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/benchmark_catalog.py:22)。
- Tracee：不是。当前只保留了 duration/sample_count/warmup/workloads，[runner/libs/benchmark_catalog.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/benchmark_catalog.py:10)；旧配置里的 `latency_probe_count`、`latency_probe_timeout_s`、`statistics.bootstrap_iterations`、`statistics.bootstrap_seed` 没有迁移。这里我看起来是“伴随功能删除一起缩配置面”，因为当前 [e2e/cases/tracee/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py:41) 也已经不再保留这些特性，所以它更像是有意删功能，而不是 dangling config。

4. `macro_apps.yaml` 简化后是否丢了必要信息（runner/workload/tool/duration 等）？
对当前 corpus 路径来说，必要信息基本都还在，只是搬到了 catalog。
- `runner` / `tool|script|scheduler` / `duration_s` / corpus workload 都由 [runner/libs/benchmark_catalog.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/benchmark_catalog.py:68) 的 `MACRO_APP_DEFINITIONS` 承载，再由 [runner/libs/app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py:83) 还原成 `AppSpec`。
- 但旧 manifest 里 `workload.corpus` 和 `workload.e2e` 的双值语义已经丢了；`AppSpec.workload_for()` 现在对 `corpus`/`e2e` 返回同一个字符串，[runner/libs/app_suite_schema.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_suite_schema.py:20)。这会影响旧 schema 里 workload 不同的三个 app：`tetragon/default`、`katran`、`tracee/default`。我没有找到当前 live caller 会对 schema v2 suite 调 `workload_for("e2e")`，所以今天不是 runtime bug，但它确实是 manifest 语义缩窄。

5. `scx case.py` 改动最大，逻辑是否完整？
大方向是完整的：它现在确实只存 baseline/post 的 throughput + BPF delta，不再重复保存 CPU/context-switch/latency/site-summary/comparison 这些派生层。

但有两处不完整：
- 它依赖的通用 lifecycle 已经不再做 per-program pass policy，导致 `scx` 这个最敏感的 `struct_ops` case 被回归影响。
- 它自己的 live-id 解析引入了 stale-id fallback，baseline 后 resolve apply target 这一步不够严格。

除此之外，我没有看到明显的断链：workload 列表、before/after BPF 采样、debug context、payload 组装都还是闭合的。

6. `rejit.py` 的改动是否安全？
我认为“文件内改动本身”大体安全。
- `compact_rejit_result_for_artifact()` / `compact_rejit_results_for_artifact()` 只是压缩 artifact payload，大幅减小 `rejit_result` 存储面；当前 live code 里没有地方依赖 compact 后仍保留完整 `per_program/passes/output/debug_result`。
- 删掉 `scan_programs()` wrapper 也安全；我用 `rg` 查了 live source，没有剩余调用者。

这次真正不安全的行为变化，不在 `rejit.py` 本身，而在 [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:109) 不再调用 `rejit.py` 里那套 policy-selection helper。

7. `case_common.py` 删掉的函数是否真的没有调用者？
按当前 live source 调用图看，是的。

我用 `rg` 检查了 `corpus/ e2e/ runner/ tests/`（排除了 `docs/tmp`、`e2e/results`、`corpus/results`、build/vendor 噪音），没有找到已删除这些 helper 的剩余调用者：
- `summarize_numbers`
- `percent_delta`
- `percentile`
- `speedup_ratio`
- `measure_app_runner_workload`
- `run_app_runner_phase_records`
- `zero_site_totals`
- `rejit_program_result`
- 以及随之删掉的 `runner.libs.metrics` 采样 helper

所以“有无悬空调用者”这个问题上，我没发现问题。

**Verification**

- 看了完整 `git diff HEAD~1..HEAD`，并重点复核了 `benchmark_catalog.py`、`macro_apps.yaml`、`app_suite_schema.py`、`case_common.py`、`rejit.py`、`e2e/cases/scx/case.py`、`corpus/driver.py`、`e2e/driver.py`。
- 跑了 `python -m py_compile` 覆盖本次核心改动文件，语法和导入层面无报错。
- 用 `rg` 检查了 `case_common.py` 删除函数与 `rejit.py::scan_programs()` 的 live caller，未发现残留调用。
- 另外用当前代码实际求值确认了 `benchmark_rejit_enabled_passes()` 与 `resolve_program_enabled_passes(..., prog_type='struct_ops')` 的输出差异，证明 policy 回归不是纯理论问题。

**Bottom Line**

这个提交在“结果存储面”上的简化方向基本成立，但混入了至少一处不该删的行为逻辑：per-program policy pass selection。我的结论是：这不是“纯重构无行为变化”的安全提交，至少需要修掉上面两处问题之后，才能把这次大清理视为稳妥。
