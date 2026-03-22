# Userspace Fix Round 2 (2026-03-19)

## Scope

根据 `docs/tmp/userspace_post_cleanup_review_20260319.md` 修复了这轮 userspace post-cleanup review 列出的用户态问题。

## Applied Fixes

1. `corpus/run_corpus_runnability.py`
   - 将已失效的 `run_corpus_perf` / `run_corpus_tracing` 导入切到现有的 `_driver_impl_run_corpus_perf` / `_driver_impl_run_corpus_tracing`
   - 保留 direct-script 和 package import 两种路径

2. `corpus/_driver_impl_run_production_corpus_v5_framework.py`
   - 从 `common` / `corpus.common` 补充导入 `extract_error`
   - 修复 `discover_programs()` 非零退出路径的潜在 `NameError`

3. 文档入口更新
   - `README.md`
   - `CLAUDE.md`
   - `micro/README.md`
   - `corpus/README.md`
   - 统一切到当前入口：
     - `python3 micro/driver.py suite ...`
     - `python3 micro/driver.py corpus ...`
     - `python3 e2e/run.py ...`
   - 删除对已删 wrapper / 目录的直接引用：
     - `run_micro.py`
     - `run_macro_corpus.py`
     - `run_corpus_perf.py`
     - `run_corpus_tracing.py`
     - `run_corpus_tracing_exec.py`
     - `run_tracing_corpus_vm.py`
     - `run_corpus_v5_framework.py`
     - `run_production_corpus_v5_framework.py`
     - `run_corpus_v5_vm_batch.py`
     - `config/ablation/`
     - `micro/archive/scripts/`
     - `micro/programs/archive/runtime/`
     - `corpus/archive/`

4. 删除 orphaned backend
   - 删除 `micro/_driver_impl_run_pass_ablation.py`
   - 调用者检查：
     - `rg -n "_driver_impl_run_pass_ablation" -g '!micro/results/**' -g '!docs/tmp/**' -g '!**/*.json' -g '!**/*.md' .`
     - 返回空结果，未发现活跃代码入口

5. Cleanup 收尾
   - `corpus/_driver_impl_run_corpus_v5_vm_batch.py`
     - 清理与本地同名 helper 冲突的 `text_invocation_summary` 导入
   - `micro/orchestrator/rigorous.py`
     - 删除未使用的 `select_benchmarks` 导入

## Validation

1. `python3 -m py_compile corpus/run_corpus_runnability.py corpus/_driver_impl_run_production_corpus_v5_framework.py corpus/_driver_impl_run_corpus_v5_vm_batch.py micro/orchestrator/rigorous.py`
   - OK

2. `python3 corpus/run_corpus_runnability.py --help`
   - OK
   - broken import 已消失，CLI 帮助正常输出

3. `make smoke`
   - OK
   - 产物：`micro/results/dev/smoke.json`
   - 运行日志中的 warning 为环境噪音提示，不是失败：
     - CPU governor=`powersave`
     - Turbo boost enabled
     - `perf_event_paranoid=2`
     - 未设置 CPU affinity

4. `python3 micro/driver.py --help`
   - OK

5. `python3 e2e/run.py --help`
   - OK

## Outcome

- `corpus/run_corpus_runnability.py` 已恢复可执行
- production corpus framework 的 failure path `NameError` 已修复
- 四份面向用户/协作者的文档已切到当前入口模型
- 无活跃调用者的 pass ablation backend 已删除
- 本轮 review 指定的重复 helper / dead import 已清理
