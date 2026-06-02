# 2026-05-31 prefetch-research-micro-smoke

## 结论

已新增第一组 prefetch research micro 载体，并完成本地 object / native build smoke。

本实验没有跑 runtime performance，因此没有性能结论。它只确认新增 benchmark 可以进入
micro manifest、生成 deterministic input，并通过 Makefile 编译成 BPF object 和 native `.so`。

新增 benchmark 都在 manifest 里标记 `new-2026-05-31`：

| benchmark | 目的 |
|---|---|
| `prefetch_distance_0` | immediate-before-load 负例。 |
| `prefetch_distance_2` | 极短 lookahead。 |
| `prefetch_distance_4` | 短 lookahead。 |
| `prefetch_distance_8` | 对齐当前 `bpfopt` `TARGET_PREFETCH_DISTANCE=8` 的近似 case。 |
| `prefetch_distance_16` | 对齐当前 `bpfopt` `MAX_PREFETCH_DISTANCE=16` 的近似 case。 |
| `prefetch_distance_32` | 更长 lookahead，判断当前 max window 是否太保守。 |
| `prefetch_indirect_lookup` | 先读 packet payload index，再访问另一区域，模拟 indirect lookup。 |

## 实验问题

这个 smoke 要回答：

1. prefetch research micro 的代码是否能编译。
2. 新增 case 是否能被 `micro_pure_jit.yaml` 正确加载。
3. deterministic input generator 是否能生成 prefetch research 输入。
4. 后续 AWS kernel runtime 实验是否有可直接引用的 benchmark names。

## 命令

从工作区执行：

```bash
cd /home/ruoji/github/bpf-opt

python3 -m py_compile \
  code/runner/libs/input_generators.py \
  code/micro/catalog.py

PYTHONPATH=/home/ruoji/github/bpf-opt/code python3 - <<'PY'
from micro.catalog import load_catalog
from runner.libs.input_generators import materialize_input
manifest = load_catalog('/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml')
for target in manifest.targets:
    if 'new-2026-05-31' in target.tags:
        print(f'{target.name}\t{target.program_names[0]}\t{target.expected_result}')
path, meta = materialize_input('prefetch_research', force=True)
print(f'input\t{path}\t{meta}')
PY

make -C code/micro/programs \
  OUTPUT_DIR=/tmp/bpf-opt-prefetch-research-build-smoke \
  /tmp/bpf-opt-prefetch-research-build-smoke/prefetch_research.bpf.o

make -C code/micro/programs \
  OUTPUT_DIR=/tmp/bpf-opt-prefetch-research-build-smoke \
  /tmp/bpf-opt-prefetch-research-build-smoke/prefetch_research.native.so
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：local build smoke
- AWS：未使用；无 instance、无 AWS wall time、无 AWS 费用。
- benchmark runtime：未执行。

## 文件改动

代码 / benchmark manifest：

- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_research.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py`

文档 / 实验记录：

- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-smoke/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-smoke/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-smoke/analysis/new-prefetch-cases.tsv`

## 数据文件

- `data/run-contract.json`
- `data/py_compile.log`
- `data/py_compile.stderr.log`
- `data/catalog_materialize.log`
- `data/catalog_materialize.stderr.log`
- `data/make_bpf_object.log`
- `data/make_bpf_object.stderr.log`
- `data/make_native_so.log`
- `data/make_native_so.stderr.log`
- `data/bpf_symbol_check.log`
- `data/bpf_symbol_check.stderr.log`
- `data/prefetch_research.bpf.o`
- `data/prefetch_research.native.so`
- `data/prefetch_research.mem`
- `analysis/new-prefetch-cases.tsv`

## 问题和处理

- 没有跑 runtime correctness 或 performance；本实验只做编译和 manifest smoke。
- 新增 case 共用一个 source/object：`prefetch_research.bpf.c`。manifest 用不同
  `program_name` 区分 7 个 XDP program。
- 新增 input 是 generated input，不需要提交 `code/micro/generated-inputs/prefetch_research.mem`；
  本实验把本次 raw input 副本保存到 `data/prefetch_research.mem`。
- 后续 AWS runtime attribution 发现 4096-byte payload 对 XDP staged packet / verifier path
  太激进；当前代码已在
  `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution`
  中修正为 1400-byte payload。因此本 smoke 只保留为“初始编译 smoke”，不代表最终 runtime
  benchmark shape。

## 结果

| check | status |
|---|---|
| Python compile | passed |
| manifest load | passed |
| input materialize | passed |
| BPF object build through Makefile | passed |
| native `.so` build through Makefile | passed |
| BPF object symbol check | passed; 7 XDP program symbols present |

## 后续

后续 runtime correctness / attribution 已完成，见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/report.md
```

## 收尾一致性复查

已回看：

- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- 相关 action：`01-code-change-flow.md`、`02-experiment-flow.md`、
  `05-documentation-flow.md`、`08-experiment-record-flow.md`。

发现和处理：

- 原 plan 仍把 “建 prefetch micro” 写成下一步。已更新为新增 micro 已存在，下一步是
  runtime correctness 和 AWS kernel attribution。
- 本次没有修改 prefetch selector、LLVM backend、kernel module 或 runner runtime 逻辑，因此没有删除
  旧 workaround，也不需要重跑已有 PRFM family 实验。

是否重跑：

- 已重跑本次新增 micro 的最小必要验证：Python compile、manifest/input smoke、BPF object build、
  native `.so` build。
