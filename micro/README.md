# Micro Benchmark

`micro/` 现在采用声明式配置，不再把 benchmark/runtimes 硬编码在 runner 里。

当前执行栈分两层：

- `config/suite.yaml` 定义 benchmark、runtime、build 命令和 toolchain 路径
- `run_micro.py` 负责读取 YAML、生成输入、调度实验、聚合 JSON
- `build/runner/micro_exec` 负责真正执行 `llvmbpf` 和 `kernel eBPF`

两条 runtime 现在加载的是同一份 `programs/*.bpf.o`，不是两套 wrapper。

当前只保留两条执行路径：

- `llvmbpf`: 通过 vendored `vendor/llvmbpf`
- `kernel`: 通过 vendored `vendor/libbpf` + `BPF_PROG_TEST_RUN`

`vendor/bpftool` 也已纳入 submodule，并可本地构建，用于后续 `dump jited` / `prog profile` 等扩展。

## 当前覆盖

- `simple`
- `bitcount`
- `binary_search`
- `checksum`
- `packet_parse`
- `branch_layout`

## 依赖布局

仓库根目录新增了三个正式 submodule：

- `vendor/llvmbpf`
- `vendor/libbpf`
- `vendor/bpftool`

初始化后可直接构建：

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

## 用法

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

## 结果结构

每个 `benchmark × runtime` 组合会记录：

- `compile_ns`
- `exec_ns`
- 返回值分布
- `median / mean / min / max / p95 / stdev`

## 当前边界

- `kernel` 路径要求 `sudo -n` 可用
- `kernel` 结果校验通过 `result_map` 读取，不依赖 XDP return code
- `llvmbpf` 也从同一个 ELF `.bpf.o` 加载，并在 userspace 里模拟 `input_map/result_map`
- `bpftool` 当前主要作为 vendored tooling，主执行链路已经不再 shell 调它
- 硬件计数器、JIT dump、verifier 细分统计还没接到结果 JSON
