# Benchmark Blockers Fix Report

日期：2026-03-29  
范围：修复 `docs/tmp/20260329/benchmark_full_review_round3_20260329.md` 中阻塞 authoritative benchmark run 的 framework 问题。未跑 VM，未修改 `vendor/linux-framework/`，未 commit。

## 已修复项

### 1. Shared YAML schema 接通

- `corpus/config/macro_apps.yaml` 已迁移到 shared schema：
  - `defaults.repeat: 200`
  - 每个 app 的 `workload` 现在是 `corpus` / `e2e` 两个 key
  - `args:` 单键块已摊平成顶层 runner-specific 字段（如 `tool` / `script` / `scheduler` / `app`）
  - 新增 `katran` entry，`corpus=test_run`，`e2e=network`
- `runner/libs/app_suite_schema.py` 现在显式解析 `AppWorkload(corpus, e2e)`，并支持 top-level runner args。
- `corpus/orchestrator.py` 通过 `app.workload_for("corpus")` 选 corpus workload。
- `e2e/run.py` 现在读取同一份 suite，并按 case 使用 `workload.e2e`：
  - `tracee` / `tetragon`：临时过滤 config 里的 workloads
  - `bcc`：临时过滤 tools，并把 `workload_kind` 改写为 suite 的 `workload.e2e`
  - `bpftrace`：按 suite 选 scripts，并传 workload override
  - `scx`：按 suite 过滤 workloads
  - `katran`：从 suite 读 workload

### 2. Partial-apply 不再折叠成全-or-nothing

- `runner/libs/rejit.py` 的 socket apply 聚合现在返回：
  - `applied_any`
  - `all_applied`
  - `program_counts`
  - `per_program`
- `corpus/orchestrator.py` 和 E2E lifecycle 现在都按 “只要有任一 program applied 就继续 post-phase” 处理。
- corpus 结果里新增 per-program `applied` / `comparable` / `speedup` / `comparison_exclusion_reason` 标记，不再把 loader 内的 partial apply 压扁成一个布尔值。

### 3. Repeat 默认值修正

- `macro_apps.yaml` 默认 `repeat=200`。
- `corpus/orchestrator.py` 在未显式传 `--repeat` 时，默认使用 suite YAML 的 `repeat`。
- `Makefile` / `runner/Makefile` 的 `vm-corpus` 默认 repeat 现在是 `200`。
- `Makefile` help 文案已去掉 `vm-corpus` 对 `ITERATIONS/WARMUPS` 的误导性引用。

### 4. Authoritative corpus summary / report 接通

- `corpus/orchestrator.py` summary 现在包含：
  - `applied_only_geomean`
  - `all_comparable_geomean`
  - `sample_count`
  - `applied_sample_count`
  - `comparison_exclusion_reasons`
  - `comparison_exclusion_reason_counts`
  - `per_app`
- `corpus/orchestrator.py` 现在同时写：
  - JSON artifact
  - markdown summary (`--output-md`)
- `runner/Makefile` 的 `vm-corpus` 已把 `--output-md "$(VM_CORPUS_OUTPUT_MD)"` 接上。

### 5. Katran 已重新接入 framework

- 新增 shared app runner：
  - `runner/libs/app_runners/katran_support.py`
  - `runner/libs/app_runners/katran.py`
- `runner/libs/app_runners/__init__.py` 已注册 `katran` runner。
- Katran runner 现在支持两条 workload 路径：
  - `test_run`：给 corpus 用，走 `BPF_PROG_TEST_RUN`
  - `network`：给 E2E 用，走 namespace HTTP load
- 新增 E2E case：
  - `e2e/cases/katran/case.py`
  - `e2e/cases/katran/__init__.py`
- `e2e/run.py` 已把 `katran` 加入 parser choices、`CASE_SPECS`、`ALL_CASES`。

### 6. metrics.py silent degrade 移除

- `runner/libs/metrics.py::sample_bpf_stats()` 现在在以下情况会显式报错，而不是伪装成 0 或静默跳过：
  - prog FD lookup 失败
  - `bpf_prog_get_info_by_fd()` 失败
  - 请求的 prog_id 缺 stats

## 额外测试补强

- 新增 / 更新的 Python 单测覆盖：
  - shared app suite schema
  - corpus authoritative summary / exclusion reasons
  - e2e shared-suite BCC config rewrite
  - metrics fail-fast 行为

## 验证

- 已执行：`pytest tests/python/ -q`
- 结果：`76 passed`

## 说明

- 本次只修 framework blocker，不做 VM benchmark run。
- 从 framework 角度，这批阻塞项已经收口；下一步可以在 VM 中执行 authoritative corpus / e2e benchmark run。
