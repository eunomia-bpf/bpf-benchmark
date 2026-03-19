# Userspace Post-Cleanup Review (2026-03-19)

## Scope

按要求做了以下只读检查：

- `rg` 扫描指定的已删文件/目录名，区分活代码引用、Makefile/README/CLAUDE 引用、历史结果/旧报告噪音。
- 检查根 `Makefile` 的所有顶层 target 命令是否仍指向现有入口。
- 检查 `README.md`、`CLAUDE.md`，并顺带检查 `micro/README.md`、`corpus/README.md` 这两个直接面向子目录使用者的文档。
- `source /home/yunwei37/workspace/.venv/bin/activate && python3 -m py_compile` 覆盖仓库内全部现存 `.py`。
- 用 `pyflakes` 和引用搜索补查清理后暴露出来的 dead code / latent bug。

## Findings

### P0: `corpus/run_corpus_runnability.py` 仍然 import 已删除的 public wrapper，脚本当前不可运行

- 文件：`corpus/run_corpus_runnability.py`
- 位置：
  - `from run_corpus_perf import ...` at lines 27-49
  - `from run_corpus_tracing import ...` at line 50
- 这些模块对应的文件都已经删除：
  - `corpus/run_corpus_perf.py`
  - `corpus/run_corpus_tracing.py`
- 复现：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 corpus/run_corpus_runnability.py --help
```

- 实际结果：

```text
ModuleNotFoundError: No module named 'run_corpus_perf'
```

- 影响：
  - `run_corpus_runnability.py` 这个用户态脚本现在是硬损坏状态。
  - 这也是本轮 review 里唯一已经实锤、可直接复现的 broken import。

### P1: `corpus/_driver_impl_run_production_corpus_v5_framework.py` 有 failure-path `NameError`

- 文件：`corpus/_driver_impl_run_production_corpus_v5_framework.py:373`
- 问题：
  - `discover_programs()` 在非零退出码失败路径调用了 `extract_error(stderr, stdout, returncode)`。
  - 当前文件没有导入 `extract_error`，运行时会直接抛 `NameError`。
- 最小复现：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
python3 - <<'PY'
from pathlib import Path
import corpus._driver_impl_run_production_corpus_v5_framework as m
try:
    m.discover_programs(Path('/bin/false'), Path('README.md'), 1)
    print('NO_ERROR')
except Exception as exc:
    print(type(exc).__name__)
    print(exc)
PY
```

- 实际结果：

```text
NameError
name 'extract_error' is not defined
```

- 影响：
  - `list-programs` 只要是普通非零退出，而不是 timeout / `OSError`，这个 production corpus 路径就不是“记录失败”，而是直接 crash。

### P1: 文档入口仍明显指向已删除文件/目录

根文档里仍有明确 stale reference：

- `README.md:87`
  - 仍把 `run_micro.py` 描述为 micro 层 orchestrator，但 `micro/run_micro.py` 已删除。
- `CLAUDE.md:74`, `CLAUDE.md:77`, `CLAUDE.md:99`
  - 仍给出 `python3 micro/run_micro.py ...` 的直接调用方式和架构说明。
- `CLAUDE.md:95`
  - 仍提到 `config/ablation/`，目录已删除。
- `CLAUDE.md:116`, `CLAUDE.md:179`
  - 仍提到 `micro/programs/archive/runtime/`，目录已删除。

顺带检查发现，子目录文档也还没跟上清理：

- `micro/README.md:14`, `:39`, `:64`
  - 仍把 `run_micro.py` 当作现有入口。
- `micro/README.md:20`, `:23`, `:80`
  - 仍指向 `archive/scripts/`、`programs/archive/runtime/`、`micro/archive/scripts/`，这些目录都已删除。
- `corpus/README.md:7`, `:25-33`, `:80`, `:86`
  - 仍把 `run_macro_corpus.py`、`run_corpus_perf.py`、`run_corpus_tracing.py`、`run_corpus_tracing_exec.py`、`run_tracing_corpus_vm.py`、`run_corpus_v5_framework.py`、`run_production_corpus_v5_framework.py`、`run_corpus_v5_vm_batch.py` 描述为现有 top-level 入口，但这些 public wrapper 文件都已删除。
- `docs/paper/scripts/run_micro.sh:43`
  - usage 文案仍写成 “extra run_micro.py args”；脚本实现已经切到 `micro/driver.py suite`，这里只是文案残留，不是执行错误。

### P2: 清理后还有新的 dead code / 去重不完整痕迹

1. `micro/_driver_impl_run_pass_ablation.py` 看起来已经成为 orphaned backend
   - 文件里有 `main()`（line 522）和 `if __name__ == "__main__"`（line 632）。
   - repo 内 `rg "_driver_impl_run_pass_ablation"` 除文件自身外无任何活引用。
   - 说明 wrapper 删掉后，这个 `_driver_impl_` 还留在树里，但当前没有入口调用它。

2. `corpus/_driver_impl_run_corpus_v5_vm_batch.py` 有重复 helper
   - lines 63/93 从 `corpus.common` 导入了 `text_invocation_summary`
   - line 332 又在本地重新定义了同名函数
   - 这是很典型的 cleanup 后去重没收干净。

3. `micro/orchestrator/rigorous.py:23` 导入了未使用的 `select_benchmarks`
   - 不是功能性 bug，但属于 cleanup 后遗留的 dead import。

4. 其他 active user-space 文件还有一些同类小残留
   - 例如若干 unused import / unused local / no-op f-string。
   - 这些不会立刻打断主路径，但说明这轮清理还没有把私有实现层彻底收干净。

## Checks That Passed

### Deleted-name scan: 没发现新的 Makefile/config broken entry

对以下名称做了 repo-wide 扫描并过滤掉 `docs/tmp/`、`**/results/**` 之类的历史噪音后：

- `run_kernel_recompile_per_family`
- `run_post_cmov_fix_corpus_ablation`
- `run_e2e_tetragon`
- `run_e2e_bpftrace`
- `run_tetragon_authoritative_wrapper`
- `run_micro.py`
- `run_macro_corpus`
- `run_corpus_perf`
- `run_corpus_tracing.py`
- `run_corpus_tracing_exec`
- `run_tracing_corpus_vm`
- `run_corpus_v5_framework`
- `run_production_corpus_v5_framework`
- `run_corpus_v5_vm_batch`
- `config/ablation/`
- `micro/archive/scripts/`
- `micro/programs/archive/runtime/`
- `corpus/archive/`

结论：

- `Makefile` 里没有残留对已删 wrapper 的引用。
- 活代码里没有发现对以下已删入口的残留引用：
  - `run_kernel_recompile_per_family`
  - `run_post_cmov_fix_corpus_ablation`
  - `run_e2e_tetragon`
  - `run_e2e_bpftrace`
  - `run_tetragon_authoritative_wrapper`
  - `corpus/archive/`
- 真正需要处理的残留，主要集中在：
  - `corpus/run_corpus_runnability.py` 的 import
  - 根/子目录文档仍指向已删 public wrapper

### Makefile targets: 顶层入口已切到新结构

检查了根 `Makefile`，并用 `make -n` 覆盖以下 target：

- `help`
- `verify-build`
- `compare`
- `all`
- `micro`
- `scanner`
- `kernel`
- `kernel-tests`
- `scanner-tests`
- `smoke`
- `check`
- `validate`
- `vm-selftest`
- `vm-micro-smoke`
- `vm-micro`
- `vm-corpus`
- `vm-e2e`
- `vm-all`
- `clean`

结论：

- 顶层 target 都还能解析，没有出现 “No rule to make target …” 或引用已删除脚本路径的问题。
- 关键 target 现在都指向现有入口：
  - `vm-micro` -> `python3 micro/driver.py suite ...`
  - `vm-corpus` -> `python3 micro/driver.py corpus v5-vm-batch ...`
  - `vm-e2e` -> `python3 e2e/run.py tracee|tetragon|bpftrace|scx|katran ...`

额外做的 parser/CLI 探测：

- `python3 micro/driver.py suite --help` -> OK
- `python3 micro/driver.py corpus v5-vm-batch --help` -> OK
- `python3 micro/driver.py corpus perf --help` -> OK
- `python3 micro/driver.py corpus tracing --help` -> OK
- `python3 micro/driver.py corpus tracing-exec --help` -> OK
- `python3 micro/driver.py corpus tracing-vm --help` -> OK
- `python3 micro/driver.py corpus v5-framework --help` -> OK
- `python3 micro/driver.py corpus v5-production --help` -> OK
- `python3 micro/driver.py corpus macro --help` -> OK
- `python3 e2e/run.py --help` -> OK

备注：

- `python3 micro/driver.py corpus --help` 当前不是标准 argparse 帮助，而是直接 `SystemExit("corpus mode required: ...")`。这不影响 Makefile，但说明统一入口的 UX 还可以更整齐。

### `py_compile`

执行：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
rg --files -g '*.py' -0 | xargs -0 -n 200 python3 -m py_compile
```

结果：

- 全部现存 `.py` 都通过 `py_compile`
- 只有 vendor 目录下出现 3 个 `SyntaxWarning: invalid escape sequence '\('`
  - `vendor/linux-baseline/.../convert_csv_to_c.py`
  - `vendor/linux-framework/.../convert_csv_to_c.py`
  - `vendor/linux/.../convert_csv_to_c.py`
- 没有 user-space 语法错误

备注：

- 这一步没有抓到 `run_corpus_runnability.py` 的 broken import，因为 `py_compile` 只验证语法，不执行 import graph。

## Structural Assessment

整体结构方向是合理的：

- 根 `Makefile` 作为 canonical entrypoint
- `micro/driver.py` 统一承接 micro/corpus 子命令
- `e2e/run.py` 统一承接 e2e case
- 私有实现收敛到 `micro/_driver_impl_*`、`corpus/_driver_impl_*`、`micro/orchestrator/*`

但当前还没有“完全收口”：

- 代码入口层已经切过去了，文档层没有完全跟上。
- 至少还有一个真实消费者 `corpus/run_corpus_runnability.py` 仍然依赖旧 public wrapper 名称。
- 少量 orphaned backend / duplicated helper / dead import 说明私有实现层的整理还差最后一轮。

## Bottom Line

结论不是 “cleanup 完全干净”，而是：

- **主路径 Makefile 入口基本干净**
- **仍有 2 个真实代码问题**
  - `corpus/run_corpus_runnability.py` broken import，当前不可运行
  - `corpus/_driver_impl_run_production_corpus_v5_framework.py` failure path `NameError`
- **文档仍有明显 stale reference**
- **还残留少量新暴露的 dead code / 去重不完整痕迹**

如果要把这轮清理收尾到“没有遗留问题”的标准，至少还需要：

1. 修正 `run_corpus_runnability.py` 到新的 `_driver_impl_*` / shared helper 路径
2. 补上 `extract_error` 导入
3. 更新 `README.md`、`CLAUDE.md`、`micro/README.md`、`corpus/README.md`
4. 删掉或重新接入 `micro/_driver_impl_run_pass_ablation.py`
5. 顺手清掉重复 helper / dead import
