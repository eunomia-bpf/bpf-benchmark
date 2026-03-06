# Micro Benchmark

`micro/` 用一套声明式 suite 比较同一份 eBPF 程序对象在 `llvmbpf` 和 `kernel eBPF` 上的表现。每个 benchmark 维护一份 `programs/*.bpf.c`，编译后生成单一 `programs/*.bpf.o`，两条 runtime 都加载这同一个 ELF。

## 结构

- `config/suite.yaml`: benchmark、runtime、build 命令和 toolchain 路径
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

运行双 runtime：

```bash
python3 micro/run_micro.py \
  --runtime llvmbpf \
  --runtime kernel \
  --iterations 10 \
  --warmups 2 \
  --repeat 200
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

结果默认写到 `micro/results/latest.json`。

## 当前覆盖

- `simple`
- `bitcount`
- `binary_search`
- `checksum`
- `packet_parse`
- `branch_layout`

每个 `benchmark × runtime` 组合会记录：

- `compile_ns`
- `exec_ns`
- `phases_ns` 分段时间统计
- `perf_counters` 执行窗口计数器汇总
- `derived_metrics`，当前包括 `ipc_median` / `branch_miss_rate_median` / `cache_miss_rate_median`
- 返回值分布
- `median / mean / min / max / p95 / stdev`

## 约束

- `kernel` 路径要求 `sudo -n` 可用
- `kernel` 结果校验通过 `result_map` 读取，不依赖 XDP return code
- `llvmbpf` 也从同一个 ELF `.bpf.o` 加载，并在 userspace 里模拟 `input_map/result_map`
- `--perf-counters` 通过 `perf_event_open` 采执行窗口计数器；kernel 计数包含 kernel 态，llvmbpf 计数只看 user 态
- 短窗口或受限 PMU 环境下，硬件计数器可能保持 0；结果里的 `perf_counters_meta.hardware_counters_observed` 会标出这一点
- `bpftool` 当前主要作为 vendored tooling，主执行链路已经不再 shell 调它
- `bpftool prog profile`、JIT dump、verifier 细分统计还没接到结果 JSON
