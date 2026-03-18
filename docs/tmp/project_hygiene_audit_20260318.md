# bpf-benchmark 项目卫生审计

日期: 2026-03-18

## 审计范围

- 先激活了虚拟环境: `source /home/yunwei37/workspace/.venv/bin/activate`
- 参考材料: `CLAUDE.md`、`docs/kernel-jit-optimization-plan.md`
- 检查范围:
  - authoritative result JSON provenance
  - `micro/results/`、`corpus/results/`、`e2e/results/` 目录卫生
  - Python / Scanner C++ / config / shell / docs/tmp / Makefile / import 健康度
- 说明:
  - 当前工作树本身是 dirty 的；本次审计把现有未提交改动当作 baseline，不回滚用户已有改动
  - 未触碰 `vendor/`
  - 未删除任何 authoritative result 文件

## 执行摘要

1. 四个审计目标 result JSON 都不满足“自包含可复现”要求。它们都没有内嵌完整 policy 内容；仅凭 policy 文件路径不足以复现实验。
2. `micro/results/vm_micro_authoritative_20260314.json` 当前工作树内容已经不再对应文档中描述的 2026-03-14 authoritative 62-bench 结果；`micro/results/vm_micro.latest.json` 因此语义上也被污染。
3. Python 与 Scanner C++ 的 active policy parser 已经是 v3-only；没有发现仍在运行路径上的 v1/v2 YAML 解析残留。
4. 结果树里主要的卫生问题不是 parser 兼容，而是 artifact 管理:
   - corpus `post_cmov_fix_corpus_ablation*` 四棵树之间存在大量逐字节重复 policy 快照
   - 多个 top-level 结果文件夹混入了历史分析、preview、smoke、tmp、raw 产物
   - authoritative 命名与 latest alias 并不总是一致
5. 已执行的低风险清理:
   - 修复坏掉的 archive wrapper `micro/archive/scripts/run_pass_ablation.py`
   - 将测试 golden 目录从 `policy_v2_golden` 更正为 `policy_v3_golden`
   - 删除 2 个未引用的 archive 重复结果
   - 删除 `e2e/results/.gitkeep`
   - 删除 `docs/tmp` 的空目录和 transient `__pycache__`

## 1. Result JSON provenance 审计

### 1.1 审计结论总表

| 文件 | 记录 policy 路径 | 记录 policy 具体内容 / sites list | 记录 applied sites 数量 | 记录 kernel/scanner commit / policy hash | 结论 |
| --- | --- | --- | --- | --- | --- |
| `micro/results/vm_micro_authoritative_20260314.json` | 是，per-benchmark `policy_file` + top-level `provenance.policy_dir` | 否，`policy` 字段为空，未内嵌 sites list | 否 | 部分有。`kernel_commit=unknown`，`scanner_commit=unknown`，仅有 `policy_files_hash` | 不可自包含复现 |
| `micro/results/vm_micro_policy_improved_full_20260318.json` | 是 | 否 | 否 | 部分有。commit 仍是 `unknown`，仅有 `policy_files_hash` | 不可自包含复现 |
| `corpus/results/corpus_recompile_authoritative_20260313.json` | 是，top-level `policy_dir` + per-program `policy_path` | 否 | 只有 top-level `summary.applied_programs`，没有 per-program `applied_sites` | 否，未看到 commit/hash provenance | 不可自包含复现 |
| `e2e/results/tracee_authoritative_20260313_postfix.json` | 是，per-program `policy_file` | 否 | 是，`enumerate_record.applied_sites` | 否，未看到 commit/hash provenance | 仍不可自包含复现 |

### 1.2 逐文件分析

#### `micro/results/vm_micro_authoritative_20260314.json`

- 有:
  - top-level `provenance.policy_dir`
  - top-level `provenance.policy_files_hash`
  - per-benchmark `policy_file`
- 没有:
  - per-benchmark normalized policy text
  - per-benchmark sites list
  - per-benchmark `policy_sha256`
  - per-benchmark `applied_sites`
  - 可信的 `kernel_commit` / `scanner_commit`，当前值是 `unknown`
- 额外严重问题:
  - 用 `git show HEAD:micro/results/vm_micro_authoritative_20260314.json` 对比后可确认:
    - `HEAD` 中该文件是 62 benchmarks 的 2026-03-14 authoritative payload
    - 当前工作树中的同名文件变成了 15 benchmarks 的 2026-03-18 rerun/subset payload
  - 这意味着:
    - 当前路径名和内容不一致
    - `docs/kernel-jit-optimization-plan.md` 里的描述与当前工作树文件不一致
    - `micro/results/vm_micro.latest.json` 也因此指向了一个语义上被污染的目标

#### `micro/results/vm_micro_policy_improved_full_20260318.json`

- 结构和上一个 micro JSON 基本同型
- 有:
  - `provenance.policy_dir`
  - `provenance.policy_files_hash`
  - per-benchmark `policy_file`
- 没有:
  - policy 内文 / sites list
  - per-benchmark policy hash
  - `applied_sites`
  - 可信 commit provenance
- 结论:
  - 这是“路径级 provenance”，不是“内容级 provenance”
  - 如果 `micro/policies/*.yaml` 后续发生修改，这个 JSON 自身不足以还原运行时实际 policy

#### `corpus/results/corpus_recompile_authoritative_20260313.json`

- 有:
  - top-level `policy_dir`
  - per-program `policy_path`
  - top-level `summary.applied_programs`
- 没有:
  - per-program policy 内容
  - per-program normalized sites list
  - per-program `applied_sites`
  - kernel/scanner git commit
  - policy hash
  - scanner/runner binary hash
- 结论:
  - 只能知道“用了哪个路径”
  - 不能知道“当时路径文件里到底是什么”
  - 也不能知道 remap 之后 live policy 到底是什么

#### `e2e/results/tracee_authoritative_20260313_postfix.json`

- 有:
  - per-program `policy_file`
  - `policy_summary`
  - applied program 的 `enumerate_record.applied_sites`
- 没有:
  - policy 内文
  - normalized/remapped sites list
  - policy hash
  - kernel/scanner commit
- 结论:
  - 四个文件里它的 provenance 最接近可用，因为它至少保留了 applied-site count
  - 但仍然不是可复现实验 artifact，因为缺 policy 内容和 commit/hash

### 1.3 缺失的关键 provenance 信息

所有 4 个文件都缺少下列关键项中的若干项:

- 精确 policy 内容:
  - 原始 YAML 文本，或等价的 normalized policy document
- 精确 policy 身份:
  - per-policy `sha256`
  - policy 来源 git sha / dirty 标志
- 精确应用结果:
  - `configured_sites`
  - `applied_sites`
  - `dropped_sites`
  - remap 后 live sites list
- 精确二进制 provenance:
  - `kernel_commit`
  - `scanner_commit`
  - scanner binary sha256
  - runner binary sha256
- 精确实验上下文:
  - repo `git_sha`
  - `git_dirty`
  - result schema version
  - toolchain / binary build identity

### 1.4 为什么“缺 policy 内容”会导致结果不可复现

如果 result JSON 只记录 `policy_file`，而不记录该文件当时的内容，那么只要仓库里的 policy 文件后来被编辑过，旧结果就无法从 JSON 自身恢复。当前工作树已经存在大量 `micro/policies/*.yaml` 改动，因此这个问题不是理论风险，而是当前就会发生的复现断裂。

### 1.5 修复建议

建议统一把 result schema 升级为“内容级 provenance”，至少记录到 per-benchmark / per-program 粒度:

```json
{
  "provenance": {
    "schema_version": 2,
    "repo_git_sha": "...",
    "repo_dirty": true,
    "kernel_commit": "...",
    "scanner_commit": "...",
    "scanner_binary_sha256": "...",
    "runner_binary_sha256": "..."
  },
  "policy": {
    "path": "micro/policies/foo.yaml",
    "sha256": "...",
    "text": "version: 3\nprogram: ...\nsites:\n  ...",
    "sites": [
      {"insn": 42, "family": "cmov", "pattern_kind": "cond-select-64"}
    ]
  },
  "policy_application": {
    "configured_sites": 7,
    "applied_sites": 5,
    "dropped_sites": 2,
    "live_sites": [
      {"start_insn": 108, "family": "cmov", "pattern_kind": "cond-select-64"}
    ]
  }
}
```

最低可接受修复线:

1. 记录 exact policy text 或 normalized sites list
2. 记录 per-policy hash
3. 记录 `applied_sites`
4. 记录真实 `kernel_commit` / `scanner_commit`
5. 记录 result schema version

## 2. 结果目录清理审计

### 2.1 latest 符号链接检查

| 链接 | 当前目标 | 状态 | 备注 |
| --- | --- | --- | --- |
| `micro/results/smoke.latest.json` | `smoke_authoritative_20260313.json` | 正常 | 目标存在 |
| `micro/results/vm_micro_smoke.latest.json` | `vm_micro_smoke_authoritative_20260313.json` | 正常 | 目标存在 |
| `micro/results/vm_micro.latest.json` | `vm_micro_authoritative_20260314.json` | 语义异常 | 目标路径存在，但当前文件内容已不是文档声称的 authoritative 62-bench payload |
| `corpus/results/code_size.latest.json` | `code_size_full_vm_20260312.json` | 正常 | 目标存在 |
| `corpus/results/corpus_v5_vm_batch.latest.json` | `corpus_v5_vm_batch_authoritative_20260311.json` | 正常 | 目标存在 |
| `corpus/results/expanded_corpus_build.latest.json` | `expanded_corpus_build_authoritative_20260310.json` | 正常 | 目标存在 |
| `corpus/results/real_world_code_size.latest.json` | `real_world_code_size_authoritative_20260307.json` | 正常 | 目标存在 |
| `corpus/results/real_world_exec_time.latest.json` | `real_world_exec_time_authoritative_20260307.json` | 正常 | 目标存在 |
| `corpus/results/tracing_corpus_vm.latest.json` | `tracing_corpus_vm_full_20260312.json` | 目标正常，文档不一致 | `corpus/results/README.md` 仍写旧 target |
| `e2e/results/bpftrace.latest.json` | `bpftrace_authoritative_20260312.json` | 正常 | 目标存在 |
| `e2e/results/scx.latest.json` | `scx_authoritative_20260311.json` | 正常 | 目标存在 |
| `e2e/results/tracee.latest.json` | `tracee_authoritative_20260313_postfix.json` | 正常但命名含糊 | target 存在，但 `tracee_authoritative_20260313.json` 同时仍留在 top-level |
| `e2e/results/xdp_forwarding.latest.json` | `xdp_forwarding_authoritative_20260312.json` | 正常 | 目标存在 |

### 2.2 命名一致性问题

- `vm_micro_authoritative_20260314.json`:
  - authoritative 名字和当前内容不一致
- `tracing_corpus_vm_full_20260312.json`:
  - 实际上被 `latest` 指向，但文件名没有 `authoritative`
- `tracee_authoritative_20260313_postfix.json`:
  - `postfix` 后缀说明它是修正版，但原始 `tracee_authoritative_20260313.json` 还在同级目录
- `vm_micro_policy_improved_full_r2_20260318.json`、`vm_micro_policy_iter_r{1,2,3}_subset_20260318.json`、`vm_micro_policy_subset_r2_20260318.json`:
  - 命名风格不统一，难以区分 authoritative / exploratory / temp

### 2.3 `micro/results/` 分类

目录规模:

- `ablation/`: 31 files
- `archive/`: 47 files
- `figures/`: 6 files
- `kernel_recompile_per_bench_post_bextr_20260313/`: 186 files
- `per_form_ablation_20260313/`: 8 files
- `raw_data/`: 11 files
- `rigorous/`: 12 files
- `stability/`: 64 files

#### authoritative（保留）

- `micro/results/smoke_authoritative_20260313.json`
- `micro/results/smoke.latest.json`
- `micro/results/vm_micro_smoke_authoritative_20260313.json`
- `micro/results/vm_micro_smoke.latest.json`
- `micro/results/micro_62bench_authoritative_20260313.json`
- `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json`
- `micro/results/vm_micro_authoritative_20260314.json`
  - 路径名仍应保留，但内容必须人工修正或恢复；见 `NEEDS_REVIEW`
- `micro/results/vm_micro.latest.json`
  - link 本身保留，但在修复上条之前不可信
- `micro/results/README.md`
  - 作为目录元数据保留，但内容已过时

#### archive（应移动到 archive/ 或保留在 archive-like 子树）

- `micro/results/ablation/**`
- `micro/results/archive/**`
- `micro/results/figures/**`
- `micro/results/kernel_recompile_per_bench_post_bextr_20260313/**`
- `micro/results/per_form_ablation_20260313/**`
- `micro/results/raw_data/**`
- `micro/results/rigorous/**`
- `micro/results/stability/**`
- top-level historical/supporting artifacts:
  - `micro/results/code-size-by-progtype.json`
  - `micro/results/micro_62bench_build40_policy_optimized_20260313.json`
  - `micro/results/recompile_overhead_summary.json`
  - `micro/results/causal_isolation_analysis.md`
  - `micro/results/combined_40_summary.md`
  - `micro/results/llvm_dual_pass_boundary_spotcheck.md`
  - `micro/results/new_benchmarks_authoritative_summary.md`
  - `micro/results/paradox_analysis.md`
  - `micro/results/pass_ablation.md`
  - `micro/results/pass_ablation_authoritative.md`
  - `micro/results/performance_deep_analysis.md`
  - `micro/results/pmu_analysis.md`
  - `micro/results/pmu_analysis_rigorous.md`
  - `micro/results/pure_jit_authoritative_analysis.md`
  - `micro/results/pure_jit_full_31_analysis.md`
  - `micro/results/pure_jit_rigorous_analysis.md`
  - `micro/results/representativeness_report.md`
  - `micro/results/runtime_authoritative_analysis.md`
  - `micro/results/runtime_full_9_analysis.md`
  - `micro/results/stability_analysis.md`
  - `micro/results/stability_analysis_authoritative.md`
  - `micro/results/vm_vs_host_comparison.md`

#### temp/intermediate（应删除或移出 top-level）

- `micro/results/vm_micro_policy_improved_full_r2_20260318.json`
- `micro/results/vm_micro_policy_iter_r1_subset_20260318.json`
- `micro/results/vm_micro_policy_iter_r2_subset_20260318.json`
- `micro/results/vm_micro_policy_iter_r3_subset_20260318.json`

#### stale/duplicate（可删除，或至少不应继续暴露在 top-level）

- `micro/results/vm_micro_policy_subset_r2_20260318.json`
  - 与当前工作树的 `micro/results/vm_micro_authoritative_20260314.json` 完全重复
  - 但由于 authoritative 文件本身已被覆盖，先标记 `NEEDS_REVIEW`，不自动删除

### 2.4 `corpus/results/` 分类

目录规模:

- `archive/`: 46 files
- `expansion/`: 2 files
- `post_cmov_fix_corpus_ablation/`: 98 files
- `post_cmov_fix_corpus_ablation_dryrun/`: 26 files
- `post_cmov_fix_corpus_ablation_preview/`: 92 files
- `post_cmov_fix_corpus_ablation_smokecheck/`: 28 files

#### authoritative（保留）

- `corpus/results/corpus_recompile_authoritative_20260313.json`
- `corpus/results/code_size_full_vm_20260312.json`
- `corpus/results/code_size.latest.json`
- `corpus/results/corpus_v5_vm_batch_authoritative_20260311.json`
- `corpus/results/corpus_v5_vm_batch.latest.json`
- `corpus/results/expanded_corpus_build_authoritative_20260310.json`
- `corpus/results/expanded_corpus_build.latest.json`
- `corpus/results/real_world_code_size_authoritative_20260307.json`
- `corpus/results/real_world_code_size.latest.json`
- `corpus/results/real_world_exec_time_authoritative_20260307.json`
- `corpus/results/real_world_exec_time.latest.json`
- `corpus/results/tracing_corpus_vm_full_20260312.json`
- `corpus/results/tracing_corpus_vm.latest.json`
- `corpus/results/README.md`
  - 应保留，但 `tracing_corpus_vm.latest.json` 的说明已落后于实际 target

#### archive（应移动到 archive/ 或保留在 archive-like 子树）

- `corpus/results/archive/**`
- `corpus/results/expansion/**`
- `corpus/results/post_cmov_fix_corpus_ablation/**`
  - 这是一整套 final ablation bundle，适合归档保存
- top-level historical/supporting artifacts:
  - `corpus/results/batch_code_size.md`
  - `corpus/results/bytecode_features.json`
  - `corpus/results/corpus-8families-persection.json`
  - `corpus/results/expanded_corpus_build.md`
  - `corpus/results/helper_pareto.json`
  - `corpus/results/post_cmov_fix_corpus_ablation.json`
  - `corpus/results/real_world_code_size.md`
  - `corpus/results/real_world_exec_time.md`
  - `corpus/results/real_world_exec_time_v2.md`
  - `corpus/results/recompile_overhead_corpus_inventory.json`
  - `corpus/results/valid_packet.bin`

#### temp/intermediate（应删除）

- `corpus/results/post_cmov_fix_corpus_ablation_preview/**`
- `corpus/results/post_cmov_fix_corpus_ablation_dryrun/**`
- `corpus/results/post_cmov_fix_corpus_ablation_smokecheck/**`
- `corpus/results/expanded_corpus_build.smoke.md`
- `corpus/results/real_world_exec_time.smoke.md`
- `corpus/results/tracing_exec_driver.smoke.kprobe.md`
- `corpus/results/tracing_exec_driver.smoke.lsm.md`
- `corpus/results/tracing_exec_driver.smoke.placeholder.md`
- `corpus/results/tracing_exec_driver.smoke.tracepoint.md`

#### stale/duplicate（可删）

- `corpus/results/` 当前存在 90 组重复文件、224 个重复文件实例
- 几乎全部来自 `post_cmov_fix_corpus_ablation`、`_preview`、`_dryrun`、`_smokecheck` 四棵树之间的重复 policy snapshot
- 代表例子:
  - `corpus/results/post_cmov_fix_corpus_ablation/policies_with_cmov/calico/from_hep_debug/calico_tc_main.policy.yaml`
  - `corpus/results/post_cmov_fix_corpus_ablation_preview/policies_with_cmov/calico/from_hep_debug/calico_tc_main.policy.yaml`
  - `corpus/results/post_cmov_fix_corpus_ablation_dryrun/policies_with_cmov/calico/from_hep_debug/calico_tc_main.policy.yaml`
  - `corpus/results/post_cmov_fix_corpus_ablation_smokecheck/policies_with_cmov/calico/from_hep_debug/calico_tc_main.policy.yaml`
- 处理建议:
  - 只保留 final bundle
  - preview/dryrun/smokecheck 只保留摘要 JSON/MD，不要再复制整套 policy tree

### 2.5 `e2e/results/` 分类

目录规模:

- `archive/`: 20 files

#### authoritative（保留）

- `e2e/results/bpftrace_authoritative_20260312.json`
- `e2e/results/bpftrace.latest.json`
- `e2e/results/scx_authoritative_20260311.json`
- `e2e/results/scx.latest.json`
- `e2e/results/tracee_authoritative_20260313_postfix.json`
- `e2e/results/tracee.latest.json`
- `e2e/results/xdp_forwarding_authoritative_20260312.json`
- `e2e/results/xdp_forwarding.latest.json`
- `e2e/results/README.md`

#### archive（应移动到 archive/ 或保留在 archive-like 子树）

- `e2e/results/archive/**`
- top-level historical/supporting docs:
  - `e2e/results/bpftrace-real-e2e.md`
  - `e2e/results/scx-e2e.md`
  - `e2e/results/tetragon-real-e2e.md`
  - `e2e/results/tracee-e2e-real.md`
  - `e2e/results/tracee-e2e-real-postfix.md`
  - `e2e/results/xdp-forwarding-e2e.md`

#### temp/intermediate（应删除）

- 当前 top-level 没有必须立刻删除的 active temp 文件
- `archive/` 里仍有 `xdp_forwarding_vm_smoke_tmp.json` 这类明显 temp 命名，建议后续统一清理 archive 命名

#### stale/duplicate（可删）

- `e2e/results/tracee_authoritative_20260313.json`
  - 已被 `tracee_authoritative_20260313_postfix.json` 语义上取代
  - `tracee.latest.json` 也已经指向 postfix 版
  - 建议人工确认后移入 archive

## 3. 过时代码和旧兼容入口扫描

### 3.1 Python

- `v1` / `legacy` / `compat` / `deprecated` / `old` / `fallback` 关键词能搜到一些命中，但 active 代码里没有发现仍在工作的 v1/v2 policy YAML parser
- active parser 结论:
  - `corpus/policy_utils.py` 只接受 `version == 3`
- `_driver_impl_*.py` 不是死代码:
  - `micro/driver.py` 和多个 public wrapper 仍然直接导入它们
- `micro/archive/` 下的脚本没有被 active 运行时 import
- 发现并修复的真问题:
  - `micro/archive/scripts/run_pass_ablation.py` 仍然调用已不存在的 `driver.py ablation` 子命令，`--help` 都会失败
  - 已改为直接调用 `micro._driver_impl_run_pass_ablation.main()`
- 需要保留的 compatibility 路径:
  - `e2e/common/recompile.py` 里的 `legacy` / `fallback` 逻辑主要是 scanner/runtime 兼容胶水，不是旧 policy parser；暂不建议贸然删

### 3.2 Scanner C++

- active C++ parser 也是 v3-only
- 没有发现 v1/v2 YAML policy parser 仍然留在运行路径上
- 需要避免误判的点:
  - `BPF_JIT_POLICY_VERSION_2` 是 policy blob ABI 版本，不等同于旧 YAML schema
- 剩余兼容残留:
  - `scanner/src/cli.cpp` 仍接受 `--v5`、`--per-site` 这类 no-op compatibility flag
  - 这不是 parser 旧版残留，但属于 CLI 兼容债务；删除前要先审 caller
- 已执行清理:
  - 把测试 golden 目录从 `scanner/tests/policy_v2_golden/` 改成 `scanner/tests/policy_v3_golden/`
  - 同步更新了 C++ 与 Python 测试引用

### 3.3 Config

- `config/` 很小，主要是:
  - `config/micro_pure_jit.yaml`
  - `config/ablation/*.yaml`
- `config/micro_pure_jit.yaml` 中没有发现注释掉的旧 benchmark 条目
- 没有发现可以无脑删除的过时 config 文件

### 3.4 Shell 脚本

- 根目录没有 `scripts/` 目录，但文档里仍有旧引用；这是文档债务
- `micro/run_corpus_tracing.sh`
  - 未被其他代码引用
  - 直接绕过 Makefile 运行 benchmark
  - 标记 `NEEDS_REVIEW`
- `micro/dump_all_jit.sh`
  - 仍被文档提到，保留
- `docs/paper/scripts/run_micro.sh`
  - 文件头明确标记 `DEPRECATED`
  - 仍是可工作的兼容入口
  - 若目标是“Makefile 唯一入口”，后续应决定是否彻底下线

### 3.5 `docs/tmp/`

- 扫描时文件规模: 320 files
- 按 immediate child 统计:
  - `2026-03-07`: 8
  - `2026-03-08`: 33
  - `2026-03-09`: 20
  - `2026-03-10`: 61
  - `2026-03-11`: 93
  - `2026-03-12`: 64
  - `2026-03-13`: 17
  - `active`: 15
- root-level 未按日期归档的文件:
  - `docs/tmp/analyze_per_form_ablation.py`
  - `docs/tmp/benchmark_framework_analysis.md`
  - `docs/tmp/gen_and_run_ablation.sh`
  - `docs/tmp/kernel_modifications_analysis.md`
  - `docs/tmp/micro-per-form-ablation.md`
  - `docs/tmp/micro_performance_improvement_analysis.md`
  - `docs/tmp/micro_policy_improvement_results.md`
  - `docs/tmp/tracee-e2e-build42-run.log`
- 明显过时或临时的候选:
  - `docs/tmp/gen_and_run_ablation.sh`
  - `docs/tmp/tracee-e2e-build42-run.log`
  - `docs/tmp/2026-03-12/post-fix-micro-62bench-rerun.partial.md`
  - `docs/tmp/2026-03-12/post_fix_micro_62bench_20260313.raw.md`
  - `docs/tmp/2026-03-12/post_fix_micro_62bench_20260313.rerun.raw.md`
  - `docs/tmp/2026-03-12/kernel-recompile-micro-v2-fixed-authoritative.resume.tmp.md`
  - `docs/tmp/2026-03-11/kernel-recompile-micro-v2-tuned.resume.tmp.md`
- 已执行清理:
  - 删除空目录 `docs/tmp/vm-tmp`
  - 删除 transient `docs/tmp/__pycache__/`

### 3.6 Makefile 入口

- 根 `Makefile` 是当前 canonical benchmark 入口
- 但它不是唯一入口。仍有多条直接运行路径绕过 Makefile:
  - `python3 micro/run_micro.py`
  - `python3 corpus/run_*.py`
  - `python3 e2e/run.py`
  - `docs/paper/scripts/run_micro.sh`
  - `micro/run_corpus_tracing.sh`
- 结论:
  - “Makefile 是主入口”成立
  - “Makefile 是唯一入口”不成立

### 3.7 Python import 健康度

- `python3 -m py_compile` 覆盖 219 个 `.py` 文件: 通过
- 静态本地 import 扫描:
  - missing imports: 0
  - local cycles: 0
- 回归验证:
  - `python3 -m unittest corpus.tests.test_policy_utils`: 通过
  - 重新编译并运行 `scanner/build/test_scanner`: `PASS 179`

## 4. 已执行的清理动作

1. 修复 `micro/archive/scripts/run_pass_ablation.py`
   - 从调用失效的 `driver.py ablation` 改为直接调用实现模块
2. 重命名测试 golden 目录
   - `scanner/tests/policy_v2_golden/` -> `scanner/tests/policy_v3_golden/`
   - 更新 `scanner/tests/test_scanner.cpp`
   - 更新 `corpus/tests/test_policy_utils.py`
3. 删除未引用的 archive 重复结果:
   - `micro/results/archive/post_fix_micro_62bench_20260313.rerun.json`
   - `e2e/results/archive/tracee_real_e2e_vm_smoke.json`
4. 删除无意义占位文件:
   - `e2e/results/.gitkeep`
5. 删除纯临时垃圾:
   - `docs/tmp/vm-tmp/`
   - `docs/tmp/__pycache__/`

## 5. NEEDS_REVIEW

### 高优先级

- `micro/results/vm_micro_authoritative_20260314.json`
  - 应从 VCS 恢复真正的 2026-03-14 authoritative payload，或把当前内容改名为新的 2026-03-18 subset/iter result
- `micro/results/vm_micro.latest.json`
  - 在上条修复之前，不应继续被当作 authoritative alias 使用
- result schema
  - 需要统一补上 policy 内容级 provenance，否则 authoritative JSON 依然不可复现

### 中优先级

- `micro/results/vm_micro_policy_subset_r2_20260318.json`
  - 当前与被覆盖的 `vm_micro_authoritative_20260314.json` 完全重复；待 authoritative 文件恢复后再决定是否删除
- `micro/results/vm_micro_policy_improved_full_20260318.json`
  - 如果这是新的候选 authoritative 结果，应改用 authoritative 命名并补 provenance；否则应归档
- `corpus/results/tracing_corpus_vm_full_20260312.json`
  - 实际被 latest 指向，但文件名没有 `authoritative`；建议统一命名策略
- `corpus/results/README.md`
  - `tracing_corpus_vm.latest.json` 的说明已过时
- `e2e/results/tracee_authoritative_20260313.json`
  - 已被 postfix 版取代，建议确认后移入 archive

### 低优先级

- `micro/run_corpus_tracing.sh`
  - 是否彻底下线，取决于是否要收敛到 Makefile-only workflow
- `docs/paper/scripts/run_micro.sh`
  - 已标记 deprecated，但仍是可用兼容入口；需要明确去留
- `docs/tmp/` root-level 文件
  - 建议统一移入按日期目录，尤其是脚本和日志文件
- `corpus/results/post_cmov_fix_corpus_ablation_preview/**`
- `corpus/results/post_cmov_fix_corpus_ablation_dryrun/**`
- `corpus/results/post_cmov_fix_corpus_ablation_smokecheck/**`
  - 建议只保留摘要，不要复制整套 policy tree

## 6. 推荐的后续顺序

1. 先修 `vm_micro_authoritative_20260314.json` / `vm_micro.latest.json` 的语义污染
2. 再升级 result schema，至少把 policy text/hash/applied_sites 写进 result JSON
3. 然后清理 corpus ablation preview/dryrun/smokecheck 的重复 policy 快照
4. 最后统一 benchmark 入口策略:
   - 明确哪些 direct wrapper 保留
   - 哪些脚本正式下线

