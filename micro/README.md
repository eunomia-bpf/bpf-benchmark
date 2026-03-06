# Micro Benchmark

`micro/` 现在按三层模型工作：

- `config/micro_pure_jit.yaml`: 纯 JIT codegen/exec 微基准
- `config/micro_runtime.yaml`: map/helper 等 runtime 机制微基准
- `config/macro_corpus.yaml`: macro/corpus 层入口

两条执行 runtime 仍然是 `llvmbpf` 和 `kernel eBPF`。每个 benchmark 维护一份 `programs/*.bpf.c`，编译后生成单一 `programs/*.bpf.o`，两条 runtime 都加载这同一个 ELF。

`micro_pure_jit` 当前采用 `staged` 入口：输入先通过一次 `input_map` staging 放进程序可读内存，结果通过测试 packet 的前 8 字节取回，不再依赖 `result_map`。`micro_runtime` 则保留完整的 map-backed runtime 路径，用来隔离 map/helper 机制本身的影响。

`micro_pure_jit` 的每个 benchmark 还显式记录 `category / family / level / hypothesis`，并支持用 `--shuffle-seed` 打乱执行顺序，结果摘要默认输出 geometric mean 和 bootstrap confidence interval，方便直接进入论文表格和图。

## 结构

- `../config/*.yaml`: suite、runtime、build 命令和 toolchain 路径
- `programs/*.bpf.c`: benchmark 源文件，`programs/common.h` 提供公共 helper / wrapper
- `run_micro.py`: 读取 suite、生成输入、调度实验、聚合 JSON
- `build/runner/micro_exec`: 实际执行 `llvmbpf` 和 `kernel eBPF`

## 依赖布局

仓库根目录引入了三个 submodule：

- `vendor/llvmbpf`
- `vendor/libbpf`
- `vendor/bpftool`

初始化并构建：

```bash
git submodule update --init --recursive
make -C micro
```

如果只想单独构建某一层：

```bash
make -C micro micro_exec
make -C micro programs
make -C micro vendor_bpftool
```

## 运行

列出当前 suite：

```bash
python3 micro/run_micro.py --list
```

列出 runtime suite：

```bash
python3 micro/run_micro.py --suite config/micro_runtime.yaml --list
```

运行默认 pure-jit suite：

```bash
python3 micro/run_micro.py \
  --runtime llvmbpf \
  --runtime kernel \
  --iterations 10 \
  --warmups 2 \
  --repeat 200 \
  --shuffle-seed 20260306
```

运行 runtime suite：

```bash
python3 micro/run_micro.py \
  --suite config/micro_runtime.yaml \
  --runtime llvmbpf \
  --runtime kernel
```

运行并采集 `perf_event` 计数器：

```bash
python3 micro/run_micro.py \
  --runtime llvmbpf \
  --runtime kernel \
  --iterations 10 \
  --warmups 2 \
  --repeat 200 \
  --perf-counters
```

只跑部分 benchmark：

```bash
python3 micro/run_micro.py \
  --bench simple \
  --bench bitcount \
  --runtime llvmbpf \
  --runtime kernel
```

如需顺手把 vendored `bpftool` 也编出来：

```bash
python3 micro/run_micro.py --build-bpftool
```

结果默认写到 suite 自己的默认输出：

- `micro/results/pure_jit.latest.json`
- `micro/results/runtime.latest.json`

从结果 JSON 生成面向 RQ 的 markdown 摘要：

```bash
python3 micro/summarize_rq.py \
  --results micro/results/pure-jit-expanded-full.json \
  --output docs/preliminary-characterization-summary.md
```

## 当前覆盖

- `micro_pure_jit`: 22 个 case
- `baseline`: `simple`, `memory_pair_sum`
- `alu-mix`: `bitcount`, `log2_fold`
- `control-flow`: `binary_search`, `branch_layout`, `switch_dispatch`
- `memory-local`: `checksum`, `packet_parse`, `bounds_ladder`, `stride_load_4`, `stride_load_16`
- `dependency-ilp`: `dep_chain_short`, `dep_chain_long`, `spill_pressure`, `multi_acc_4`, `multi_acc_8`
- `loop-shape`: `fibonacci_iter`, `fixed_loop_small`, `fixed_loop_large`
- `call-size`: `code_clone_2`, `code_clone_8`
- `micro_runtime`: `map_lookup_churn`, `map_roundtrip`

每个 `benchmark × runtime` 组合会记录：

- `compile_ns`
- `exec_ns`
- `baseline_adjustment`，当前用于 `micro_pure_jit` 的 harness-baseline 扣除视角
- `phases_ns` 分段时间统计
- `perf_counters` 执行窗口计数器汇总
- `derived_metrics`，当前包括 `ipc_median` / `branch_miss_rate_median` / `cache_miss_rate_median`
- 返回值分布
- `median / mean / min / max / p95 / stdev`

每个 pure-jit benchmark 还会额外记录：

- `runtime_comparison.llvmbpf_over_kernel_exec_ratio`
- `runtime_comparison.llvmbpf_over_kernel_adjusted_exec_ratio`

## 约束

- `kernel` 路径要求 `sudo -n` 可用
- `micro_pure_jit` 通过一次 `input_map` staging 提供输入，并通过 XDP test packet 的前 8 字节回收结果
- `micro_runtime` 通过 `result_map` 回收结果；`llvmbpf` 在 userspace 里模拟相同的 map 行为
- `--perf-counters` 通过 `perf_event_open` 采执行窗口计数器；kernel 计数包含 kernel 态，llvmbpf 计数只看 user 态
- 短窗口或受限 PMU 环境下，硬件计数器可能保持 0；结果里的 `perf_counters_meta.hardware_counters_observed` 会标出这一点
- `bpftool` 当前主要作为 vendored tooling，主执行链路已经不再 shell 调它
- `bpftool prog profile`、JIT dump、verifier 细分统计还没接到结果 JSON
- `micro_pure_jit` 里的 `call-size` 当前只纳入 `code-clone`。`bpf-to-bpf internal call` family 已验证会暴露现有 `llvmbpf` ELF loader 对 local subprogram call 的限制，所以还没有放进默认 suite
