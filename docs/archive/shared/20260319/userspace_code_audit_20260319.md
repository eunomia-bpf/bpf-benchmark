# BpfReJIT 用户态代码审计（2026-03-19）

## 范围与方法

- 范围: `scanner/`, `micro/`, `corpus/`, `e2e/`, `config/`
- 不计入“活跃引用”证据的噪音路径: `vendor/`, `corpus/repos/`, `**/build/`, `**/results/`, `docs/`, `docs/tmp/`, `__pycache__/`
- 方法:
  - 用 `rg` 交叉检查函数/脚本入口是否有活跃调用点
  - 用 AST 脚本做一轮未用 import / top-level def 初筛，再用 `rg` 复核
  - 以根目录 `Makefile`、各目录 `README.md` 和统一 driver 为 canonical entrypoint
  - 单独检查 `archive/` / `tmp/` / `config/ablation/` 是否仍被活跃代码引用

## 执行摘要

- `scanner/` 未发现高置信的 `DEAD` / `REDUNDANT` / `OVERENGINEERED` / `STALE` 项。
- 高置信的“整文件/整配置”候选约 `20.8k` 行。
- 活跃文件内还能再清掉约 `0.16k` 行局部 dead code / unused import。
- 合计可精简约 `21.0k` 行。
- `archive/` 结论: `micro/archive/scripts/`、`corpus/archive/`、`micro/programs/archive/runtime/` 都没有被活跃代码引用；现有命中只来自 README、`CLAUDE.md` 和历史 results。

| 桶 | 估计可删行数 |
| --- | ---: |
| 活跃代码与 stale config | ~13,803 |
| 纯 archive / history 资产 | ~7,152 |
| 合计 | ~20,955 |

## scanner/

未发现高置信问题。`scanner` 的 policy/scan 路径仍被活跃入口使用:

- `scanner/src/cli.cpp:392`, `scanner/src/cli.cpp:1432`
- `scanner/src/pattern_v5.cpp:1876`, `scanner/src/pattern_v5.cpp:1884`
- `micro/runner/src/kernel_runner.cpp:1171`, `micro/runner/src/kernel_runner.cpp:1180`

结论: `scanner/` 目前看不到明确可删的 dead module 或旧兼容层。

## micro/

- `REDUNDANT` 位置: `micro/run_micro.py:1`
  - 估计可删: `21` 行
  - 说明: 该脚本只是在 `_main_through_driver()` 里把参数转发给 `micro.driver` 的 `suite` 子命令；活跃自动化已经直接走 `micro/driver.py`，见 `micro/driver.py:60` 和 `Makefile:275`。

- `DEAD` 位置: `micro/run_kernel_recompile_per_family.py:1`, `micro/run_kernel_recompile_per_family.py:1389`
  - 估计可删: `1,397` 行
  - 说明: 排除 `docs/` 和 `**/results/` 后，repo-wide `rg` 只剩脚本自引用字符串 `micro/run_kernel_recompile_per_family.py:209` 与 `micro/run_kernel_recompile_per_family.py:684`；没有被 `Makefile`、`driver`、README 工作流或其他脚本调用。

- `DEAD` 位置: `micro/orchestrator/inventory.py:92`, `micro/orchestrator/inventory.py:106`, `micro/orchestrator/environment.py:27`, `micro/orchestrator/results.py:234`, `micro/orchestrator/corpus.py:315`
  - 估计可删: `59` 行
  - 说明: `inventory_for_micro_benchmarks`、`inventory_for_corpus_object`、`resolve_optional_path`、`summarize_per_benchmark_samples`、`parse_json_lines_payloads` 在 repo-wide `rg` 里只剩定义和 `__all__` 导出，没有活跃调用点。

- `STALE` 位置: `micro/driver.py:106`
  - 估计可删: `8` 行
  - 说明: `census cross-domain` 仍然 dispatch 到 `corpus/tmp/cross_domain_census.py`，但 `corpus/README.md:49` 已把该脚本标成 legacy archived workflow。这个兼容入口还活着，但目标脚本已经不在支持路径里。

- `DEAD` 位置: `micro/_driver_impl_run_micro.py:7`
  - 估计可删: `1` 行
  - 说明: `os` import 未使用。

- `STALE` 位置: `micro/archive/scripts/analyze_jit.py:1`, `micro/archive/scripts/analyze_paradox.py:1`, `micro/archive/scripts/analyze_performance_deep.py:1`, `micro/archive/scripts/analyze_pmu.py:1`, `micro/archive/scripts/analyze_representativeness.py:1`, `micro/archive/scripts/analyze_stability.py:1`, `micro/archive/scripts/analyze_statistics.py:1`, `micro/archive/scripts/build_policy_blob.py:1`, `micro/archive/scripts/demo_policy_iteration.py:1`, `micro/archive/scripts/run_pass_ablation.py:1`, `micro/archive/scripts/run_rigorous.py:1`, `micro/archive/scripts/run_rigorous_framework_vm.py:1`
  - 估计可删: `5,378` 行
  - 说明: 排除 `docs/` 和 `**/results/` 后没有任何活跃代码引用；只剩 `micro/README.md:20`、`micro/README.md:80` 和 `CLAUDE.md` 之类的历史说明。保留它们只对历史追溯有价值，对当前 benchmark runner 没有运行时意义。

- `STALE` 位置: `micro/programs/archive/runtime/atomic_counter_xadd.bpf.c:1`, `micro/programs/archive/runtime/get_time_heavy.bpf.c:1`, `micro/programs/archive/runtime/hash_map_lookup.bpf.c:1`, `micro/programs/archive/runtime/helper_call_1.bpf.c:1`, `micro/programs/archive/runtime/helper_call_10.bpf.c:1`, `micro/programs/archive/runtime/helper_call_100.bpf.c:1`, `micro/programs/archive/runtime/map_lookup_churn.bpf.c:1`, `micro/programs/archive/runtime/map_lookup_repeat.bpf.c:1`, `micro/programs/archive/runtime/map_roundtrip.bpf.c:1`, `micro/programs/archive/runtime/percpu_map_update.bpf.c:1`, `micro/programs/archive/runtime/probe_read_heavy.bpf.c:1`
  - 估计可删: `743` 行代码
  - 说明: `micro/programs/Makefile:6` 只编译顶层 `*.bpf.c`，这些 archived runtime benchmarks 已经被排除在 active build 外；`micro/README.md:23` 也明确说明它们只是历史保留。

## corpus/

- `REDUNDANT` 位置: `corpus/run_macro_corpus.py:1`, `corpus/run_corpus_perf.py:1`, `corpus/run_corpus_tracing.py:1`, `corpus/run_corpus_tracing_exec.py:1`, `corpus/run_tracing_corpus_vm.py:1`, `corpus/run_corpus_v5_framework.py:1`, `corpus/run_production_corpus_v5_framework.py:1`, `corpus/run_corpus_v5_vm_batch.py:1`
  - 估计可删: `210` 行
  - 说明: 这 8 个 wrapper 都只是导入 `_driver_impl_run_*` 后再回跳到 `micro.driver` 的 `corpus` dispatch，重复了同一套入口分发逻辑；真正的 canonical 路径在 `micro/driver.py:83`，而 `make vm-corpus` 也已直接走 `Makefile:287`。

- `DEAD` 位置: `corpus/run_post_cmov_fix_corpus_ablation.py:1`, `corpus/run_post_cmov_fix_corpus_ablation.py:953`
  - 估计可删: `1,121` 行
  - 说明: 排除 `docs/` 和 `**/results/` 后，repo-wide `rg` 只剩脚本内部生成的自引用字符串 `corpus/run_post_cmov_fix_corpus_ablation.py:405`；没有活跃调用点。

- `DEAD` 位置: `corpus/directive_census.py:178`, `corpus/directive_census.py:189`, `corpus/directive_census.py:193`, `corpus/directive_census.py:197`, `corpus/directive_census.py:201`
  - 估计可删: `17` 行
  - 说明: `parse_raw_insns`、`scan_cmov`、`scan_wide_mem`、`scan_rotate`、`scan_addr_calc` 没有活跃调用者，其中后四个函数源码还直接写了 `compatibility export only`。这就是典型旧兼容残留。

- `DEAD` 位置: `corpus/policy_utils.py:412`
  - 估计可删: `35` 行
  - 说明: `generate_default_policy_v3` 在 repo-wide `rg` 里只剩定义和 `__all__` 导出，没有任何调用点。

- `DEAD` 位置: `corpus/auto_tune.py:260`
  - 估计可删: `6` 行
  - 说明: `candidate_label` 无调用点；当前代码只用 `candidate_id_for_allowlist`。

- `STALE` 位置: `corpus/archive/run_bflip_endian_skip_sweep.py:1`
  - 估计可删: `1,031` 行
  - 说明: 没有活跃引用；与 `micro/archive/scripts/` 一样，只剩历史价值。

## e2e/

- `DEAD` 位置: `e2e/run_e2e_tetragon.py:1`, `e2e/run_e2e_bpftrace.py:1`, `e2e/run_tetragon_authoritative_wrapper.py:1`
  - 估计可删: `3,414` 行
  - 说明: 这三份 case-specific wrapper/runner 在排除 `docs/` 和 `**/results/` 后没有任何 repo 内引用。活跃路径已经是 `e2e/run.py:20`, `e2e/run.py:43`, `e2e/run.py:52` 直接导入 `e2e/cases/*/case.py`，而 Makefile 也只调用 `e2e/run.py`，见 `Makefile:298` 到 `Makefile:322`。`e2e/README.md:13` 里“still used by some fallback paths”的说法已经过时。

- `DEAD` 位置: `e2e/common/recompile.py:111`
  - 估计可删: `24` 行
  - 说明: `_scanner_json_payload` 没有调用点；当前实现直接消费下游解析结果，不再走这个 helper。

- `DEAD` 位置: `e2e/cases/katran/case.py:500`
  - 估计可删: `2` 行
  - 说明: `ipv4_u32` 无调用点。

- `DEAD` 位置: `e2e/run.py:12`, `e2e/cases/tracee/case.py:28`, `e2e/cases/tetragon/case.py:14`, `e2e/cases/katran/case.py:21`, `e2e/run_tetragon_authoritative_wrapper.py:6`
  - 估计可删: `5` 行
  - 说明: 未用 import:
    - `e2e/run.py:12` `DEFAULT_VENV_ACTIVATE`
    - `e2e/cases/tracee/case.py:28` `describe_command`
    - `e2e/cases/tetragon/case.py:14` `time`
    - `e2e/cases/katran/case.py:21` `Any`
    - `e2e/run_tetragon_authoritative_wrapper.py:6` `Any`

## config/

- `STALE` 位置: `config/ablation/ablation_branch_flip.yaml:1`, `config/ablation/ablation_cmov.yaml:1`, `config/ablation/ablation_endian.yaml:1`, `config/ablation/ablation_extract.yaml:1`, `config/ablation/ablation_lea.yaml:1`, `config/ablation/ablation_rotate.yaml:1`, `config/ablation/ablation_wide.yaml:1`
  - 估计可删: `7,483` 行
  - 说明: 当前活跃 micro manifest 只有 `micro/benchmark_catalog.py:12` 指向的 `config/micro_pure_jit.yaml`。命名 ablation policy 现在通过 `Makefile:69` 到 `Makefile:80` 的 `micro/policies/variants/*` 选择，而不是通过这些 YAML。排除 `docs/` 和 `**/results/` 后，对 `config/ablation/*.yaml` 的命中只剩历史结果和 `CLAUDE.md` 描述，没有活跃代码读取它们。

## 额外观察

- `micro/driver.py` 同时承担 micro/corpus/census 的多路复用，再叠加一层 `corpus/run_*.py` 与 `micro/run_micro.py` wrapper，属于明显过度抽象。现在既有统一 driver，又有每模式一份薄 wrapper，两套入口只是在重复做参数透传。
- `archive/` 目录里的内容当前更像“历史资料”而不是“可运行的备选路径”。如果项目决定保留历史资产，建议明确搬到仓库外部归档，或者至少从主工作树路径中隔离，以免继续污染入口面和搜索结果。

## 汇总

| 目录 | 估计可精简 |
| --- | ---: |
| `scanner/` | `0` |
| `micro/` 活跃路径 | `1,486` |
| `micro/` archive/history | `6,121` |
| `corpus/` 活跃路径 | `1,389` |
| `corpus/` archive/history | `1,031` |
| `e2e/` | `3,445` |
| `config/` | `7,483` |
| 合计 | `~20,955` |

优先级建议:

1. 先删 `e2e/run_e2e_{tetragon,bpftrace}.py`、`e2e/run_tetragon_authoritative_wrapper.py`、`micro/run_kernel_recompile_per_family.py`、`corpus/run_post_cmov_fix_corpus_ablation.py` 这类完全失活的大脚本。
2. 再收掉 `micro/run_micro.py` 和 `corpus/run_*.py` 的重复 wrapper，只保留统一 driver。
3. 最后清理 `config/ablation/` 与 `archive/` 历史资产；如果需要保留历史，可移出活跃树而不是继续留在当前入口旁边。
