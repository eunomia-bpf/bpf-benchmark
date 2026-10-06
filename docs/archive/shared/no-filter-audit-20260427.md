# No-Filter Audit - 2026-04-27

## Scope

审计范围为仓库内一手 benchmark/framework 代码、配置和用例：

- `corpus/driver.py`
- `runner/libs/`
- `e2e/driver.py`
- `e2e/cases/`
- `corpus/config/benchmark_config.yaml`
- active app runner 配置和 Makefile target defaults

排除范围：`.git/`、`vendor/`、`runner/repos/`、生成结果目录、build 输出和 docs/tmp 旧临时文档。单元测试/微基准代码只在判断是否影响 benchmark 规则时参考。

## Summary

| Check | Result | Notes |
| --- | --- | --- |
| `live_rejit_programs` override 不过滤程序 | PASS | 只有 base implementation 和测试 stub；未发现 app override 过滤。 |
| `LifecycleAbort` / `before_rejit` ReJIT abort | PASS | 未发现实现命中。 |
| `_EXCLUDED_PROGRAM_NAMES` 或显式 exclusion list | PASS | 未发现 `_EXCLUDED_*PROGRAM*` / `excluded_programs` 等实现命中。 |
| 任何按名称/提示筛选待 ReJIT BPF program | FAIL | `bpftrace` runner 用 `program_name_hints` 只收集匹配名称的程序，可能把同一 app 启动产生但名称不匹配的程序排除在 ReJIT 外。 |
| prog_type 过滤待 ReJIT program | PASS | ReJIT 调用路径按 program id 全量循环；只发现 pass 内部的 prog_type safety/applicability 判断，不是 benchmark 层 program 过滤。 |
| `benchmark_config.yaml` pass exclusion | PASS | 当前 config 没有 per-prog_type rules、disable 或 exclusion。 |
| `workload_miss` 计算 | PASS | `corpus/driver.py`、`runner/libs/case_common.py`、`e2e/cases/` 未发现。 |
| `limitations` 字段 | PASS | 同上，未发现。 |
| threshold 过滤，例如 `run_cnt_cv` | PASS | 未发现 `run_cnt_cv`、CV threshold 或 run count threshold 过滤。 |
| `per_program_geomean` 覆盖所有 `run_cnt_delta > 0` 的 program | PASS | corpus summary 只因数学必要排除 baseline/post 任一侧 `run_cnt_delta <= 0` 的 program。 |
| 无多余 summary / informational-only artifact 逻辑 | FAIL | final artifact compaction 添加 `applied_site_totals` 和 stripped/output metadata 字段。 |
| 最终 JSON payload 干净 | FAIL | `corpus` 和 `e2e` 写出前都会调用 artifact compaction，因此会带入上述 informational-only 字段。 |
| app-level loader only | PASS | active app runners 通过真实 app/tool 启动加载 BPF；katran `xdp_root` bootstrap 符合例外。 |
| CLAUDE/AGENTS supported apps 规则 | PASS | active runner registry 只包含 8 个 supported apps；removed apps 未进入 active app runner/macro app 配置。 |
| 默认 target config 可用 | PASS | `runner/targets/*.env` 提供默认值，相关 Make targets 走这些 target env。 |

## Detailed Findings

### 1. No ReJIT Filtering

#### `live_rejit_programs` override

Result: PASS

Evidence:

- `runner/libs/app_runners/base.py:39` 定义唯一生产代码 implementation：返回 `list(self.programs)`。
- 未发现 app runner override `live_rejit_programs()` 来过滤程序。

#### Lifecycle abort hooks

Result: PASS

Evidence:

- 搜索 `LifecycleAbort`、`before_rejit` 只命中规则文档，未发现实现代码。

#### Explicit exclusion lists

Result: PASS

Evidence:

- 未发现 `_EXCLUDED_PROGRAM_NAMES`、`_EXCLUDED_*PROGRAM*`、`EXCLUDED_PROGRAM`、`excluded_programs`、`excluded_program_names` 等实现代码。

#### Name-based program selection

Result: FAIL

Failure:

- `runner/libs/app_runners/bpftrace.py:25` 定义 `SCRIPTS`，每个 script 带 `program_name_hints`。
- `runner/libs/app_runners/bpftrace.py:99` 的 `_program_name_matches()` 根据这些 hints 判断 program name。
- `runner/libs/app_runners/bpftrace.py:116` 的 `_discover_script_programs()` 使用：
  - `programs_after(before_ids)` 只看新出现 program；
  - 再用 `_program_name_matches(..., script_spec.program_name_hints)` 过滤。

Why this is a violation:

- 该逻辑不是 ReJIT apply 阶段的显式 skip，但它会决定 runner 记录哪些 app-loaded BPF programs。
- 后续 ReJIT 使用 runner/session 记录的 live program ids，因此名称不匹配的 bpftrace-loaded program 会被排除在 ReJIT 外。
- 这属于“类似排除列表/过滤”的 inclusion filter，不符合“Never filter, skip, or exclude any BPF program from ReJIT”。

#### prog_type filtering

Result: PASS

Evidence:

- `runner/libs/rejit.py:794` 到 `runner/libs/rejit.py:806` 对传入的 `prog_ids` 逐个调用 daemon ReJIT，没有按 `prog_type` 过滤。
- `runner/libs/rejit.py:855` 到 `runner/libs/rejit.py:858` 只做 positive integer id normalization。
- `corpus/driver.py:583` 到 `corpus/driver.py:600` 使用 live ReJIT program ids 调用 ReJIT，没有按 `prog_type` 剔除。

Non-failing observations:

- `daemon/src/passes/wide_mem.rs:345` 和 `bpfopt/crates/bpfopt-core/src/passes/wide_mem.rs:345` 存在 pass 内部 `prog_type` safety 判断。
- `daemon/src/passes/bounds_check_merge.rs:94`、`daemon/src/passes/skb_load_bytes.rs:72` 以及 bpfopt-core 对应文件存在 pass applicability 判断。
- 这些判断限制的是 pass 内部优化 site 或 pass applicability，不是 benchmark/framework 层跳过某个 BPF program 的 ReJIT。

#### benchmark_config pass exclusion

Result: PASS

Evidence:

- `corpus/config/benchmark_config.yaml:1` 到 `corpus/config/benchmark_config.yaml:27` 只定义 pass 列表和 default passes。
- 未发现 `rules`、`disable`、`prog_type` 或 per-prog_type pass exclusion。

## 2. No Unnecessary Extra Calculations

#### `workload_miss`

Result: PASS

Evidence:

- `corpus/driver.py`
- `runner/libs/case_common.py`
- `e2e/cases/`

以上范围未发现 `workload_miss` 字段或计算。

#### `limitations`

Result: PASS

Evidence:

- `corpus/driver.py`
- `runner/libs/case_common.py`
- `e2e/cases/`

以上范围未发现 `limitations` 字段。

#### Threshold filtering

Result: PASS

Evidence:

- 未发现 `run_cnt_cv`、`cv_threshold`、`coefficient of variation` 或 `run_cnt` threshold 过滤。
- `runner/libs/bpf_stats.py:91` 到 `runner/libs/bpf_stats.py:99` 只计算 delta 和 `avg_ns_per_run`。

#### per-program geomean inclusion

Result: PASS

Evidence:

- `corpus/driver.py:143` 到 `corpus/driver.py:145` 只在 baseline 或 post-ReJIT 的 `run_cnt_delta <= 0` 时返回 `None`。
- `corpus/driver.py:168` 到 `corpus/driver.py:174` 用 `post_rejit_avg / baseline_avg` 计算 ratio。
- `corpus/driver.py:188` 到 `corpus/driver.py:211` 遍历 baseline/post 都存在的 program records，把所有非 `None` per-program entries 纳入 ratios，并计算 `per_program_geomean`、`program_count`、`wins`、`losses`。

Conclusion:

- `run_cnt_delta > 0` 是 avg/ratio 计算的数学必要条件，不是 threshold 过滤。

#### Extra summary / artifact calculations

Result: FAIL

Failure:

- `runner/libs/rejit.py:478` 到 `runner/libs/rejit.py:480` 在 artifact compaction 中额外计算并写入 `applied_site_totals`。
- `runner/libs/rejit.py:505` 到 `runner/libs/rejit.py:514` 写入 `output_chars`、`output_stripped`、`debug_result_stripped`、`inlined_map_entries_stripped`。
- `corpus/driver.py:871` 到 `corpus/driver.py:872` 在写 corpus `result.json` 前调用 `compact_rejit_results_for_artifact()`。
- `e2e/driver.py:188` 到 `e2e/driver.py:190` 在写 e2e `result.json` 前同样调用 `compact_rejit_results_for_artifact()`。

Why this is a violation:

- 这些字段不是 corpus per-program metric 所需字段，也不是错误本身。
- 其中 `output_stripped` / `debug_result_stripped` / `inlined_map_entries_stripped` / `output_chars` 属于 artifact-size/informational metadata。
- `applied_site_totals` 是额外 summary 逻辑，不属于指定的 corpus `summary` 字段集合。

## 3. Clean Result Payload

Result: FAIL

Expected clean corpus payload:

- `per_program`
- `summary.per_program_geomean`
- `summary.program_count`
- `summary.wins`
- `summary.losses`
- error fields only when actual failure occurs

Evidence that core corpus payload is mostly clean:

- `corpus/driver.py:790` 到 `corpus/driver.py:805` 的 top-level payload 包含 `per_program` 和 `summary`，没有 `workload_miss` 或 `limitations`。
- `runner/libs/case_common.py:28` 到 `runner/libs/case_common.py:40` 的 phase payload 没有 informational-only fields。
- `e2e/cases/bcc/case.py:164` 到 `e2e/cases/bcc/case.py:177`、`e2e/cases/bpftrace/case.py:173` 到 `e2e/cases/bpftrace/case.py:184`、`e2e/cases/katran/case.py:116` 到 `e2e/cases/katran/case.py:130`、`e2e/cases/tetragon/case.py:269` 到 `e2e/cases/tetragon/case.py:284`、`e2e/cases/tracee/case.py:354` 到 `e2e/cases/tracee/case.py:383` 没有 `workload_miss` 或 `limitations`。

Failure:

- final `result.json` 写出前经过 `compact_rejit_results_for_artifact()`，会加入或保留 redundant informational-only compaction fields。
- 具体 failure 行号同上一节：
  - `runner/libs/rejit.py:478` 到 `runner/libs/rejit.py:480`
  - `runner/libs/rejit.py:505` 到 `runner/libs/rejit.py:514`
  - `corpus/driver.py:871` 到 `corpus/driver.py:872`
  - `e2e/driver.py:188` 到 `e2e/driver.py:190`

## 4. CLAUDE/AGENTS Design Rules

#### No ReJIT Filtering

Result: FAIL

Reason:

- General ReJIT path is unfiltered, but `bpftrace` discovery has name-hint filtering before ids reach ReJIT.
- See `runner/libs/app_runners/bpftrace.py:25`、`runner/libs/app_runners/bpftrace.py:99`、`runner/libs/app_runners/bpftrace.py:116`。

#### App-Level Loader Only

Result: PASS

Evidence:

- `runner/libs/app_runners/process_support.py:202` 到 `runner/libs/app_runners/process_support.py:260` starts native process sessions and discovers app-created programs.
- `runner/libs/app_runners/tracee.py:93` 到 `runner/libs/app_runners/tracee.py:145` starts Tracee as an app process.
- `runner/libs/app_runners/tetragon.py:36` 到 `runner/libs/app_runners/tetragon.py:77` starts Tetragon as an app process.
- `runner/libs/app_runners/bcc.py:363` 到 `runner/libs/app_runners/bcc.py:420` starts real BCC tools.
- `runner/libs/app_runners/bpftrace.py:126` 到 `runner/libs/app_runners/bpftrace.py:168` starts real `bpftrace` commands.
- `runner/libs/app_runners/katran.py:494` 到 `runner/libs/app_runners/katran.py:498` bootstraps `xdp_root`, matching the documented katran exception, then starts katran server at `runner/libs/app_runners/katran.py:499` 到 `runner/libs/app_runners/katran.py:518`。

Notes:

- Unit/microbenchmark fixtures may load `.bpf.o` files directly, but they are not benchmark app runners.

#### Corpus Metrics: Per-Program avg_ns_per_run

Result: PASS

Evidence:

- `runner/libs/bpf_stats.py:91` 到 `runner/libs/bpf_stats.py:99` calculates `avg_ns_per_run = run_time_ns_delta / run_cnt_delta` only when `run_cnt_delta > 0`。
- `corpus/driver.py:143` 到 `corpus/driver.py:174` builds per-program baseline/post averages and ratio.
- `corpus/driver.py:188` 到 `corpus/driver.py:211` builds `per_program_geomean`、`program_count`、`wins`、`losses`。

#### No Redundant Informational Fields

Result: FAIL

Reason:

- No `workload_miss` or `limitations` remain in audited paths.
- However final ReJIT artifact compaction still introduces informational-only fields at `runner/libs/rejit.py:478` 到 `runner/libs/rejit.py:514`。

#### Default Config Must Work

Result: PASS

Evidence:

- `runner/targets/x86-kvm.env:1` 到 `runner/targets/x86-kvm.env:11` provides defaults for local VM targets.
- `runner/targets/aws-x86.env:1` 到 `runner/targets/aws-x86.env:17` provides AWS x86 defaults.
- `runner/targets/aws-arm64.env:1` 到 `runner/targets/aws-arm64.env:17` provides AWS arm64 defaults.
- `Makefile:106` 到 `Makefile:110` defines `vm-corpus` and `vm-e2e` via `runner.libs.run_target_suite`。
- `Makefile:118` 到 `Makefile:128` defines `aws-arm64-test` and `aws-x86-test` via target env files.

#### Supported / Removed Apps

Result: PASS

Evidence:

- `runner/libs/app_runners/__init__.py:75` 到 `runner/libs/app_runners/__init__.py:84` active runner registry contains exactly:
  - `tracee`
  - `tetragon`
  - `bpftrace`
  - `bcc`
  - `katran`
  - `calico`
  - `cilium`
  - `otelcol-ebpf-profiler`
- `corpus/config/macro_apps.yaml:5` 到 `corpus/config/macro_apps.yaml:26` contains supported macro app entries and no active `scx`、`suricata`、`systemd`、`loxilb` entries.

Observation:

- `runner/repos.yaml` still contains repo metadata entries for some removed apps, but they are not present in active app runner registry or macro app config. This is not counted as a benchmark-rule failure in this audit.

## Required Fixes For Full PASS

1. Remove bpftrace name-hint filtering from program discovery, or change discovery so every BPF program created by the bpftrace app startup is recorded and therefore passed to ReJIT.
2. Remove redundant artifact compaction fields from final `result.json` payloads:
   - `applied_site_totals`
   - `output_chars`
   - `output_stripped`
   - `debug_result_stripped`
   - `inlined_map_entries_stripped`
3. Keep actual error surfacing as errors, not informational metadata.
