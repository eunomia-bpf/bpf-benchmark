# Micro Benchmark Plan

## 目标

先把 `micro/` 落成一个可以直接比较 `kernel eBPF` 和 `llvmbpf` 的微基准层，不等 macro 数据集全部就绪。当前阶段只做一件事：

- 为每个 benchmark 维护一份单独的 `*.bpf.c` 源文件
- 用单一 `programs/*.bpf.o` 产物保证两侧加载完全一致
- 用声明式 suite + 统一 runner 采集 load/JIT 时间、执行时间和结果校验

这样可以先把“可对照的纯计算基线”跑通，再往设计文档里的 F2-F7 因素隔离实验扩展。

## 当前范围

### 已纳入

- `llvmbpf` runtime（vendored `vendor/llvmbpf`）
- `kernel` runtime（vendored `vendor/libbpf` + `BPF_PROG_TEST_RUN`）
- vendored `bpftool`
- 统一结果 JSON
- 声明式 `suite.yaml`
- 共享输入生成
- `programs/common.h` 公共 helper / wrapper
- `micro_exec` 执行 helper
- 单一 `programs/*.bpf.o` 产物供两个 runtime 共用
- 第三方方案吸收说明（见 `THIRD_PARTY_NOTES.md`）

### 暂不阻塞当前目录创建

- `bpftool prog profile` / `perf_event_open` 硬件计数器
- pass ablation
- Spectre on/off 双启动实验
- Macro benchmark 数据集批跑

## 目录约定

```text
micro/
├── PLAN.md
├── README.md
├── THIRD_PARTY_NOTES.md
├── Makefile
├── benchmark_catalog.py
├── config/
│   └── suite.yaml
├── input_generators.py
├── run_micro.py
├── runner/
│   ├── CMakeLists.txt
│   ├── include/
│   └── src/
├── generated-inputs/
├── programs/
│   ├── Makefile
│   ├── common.h
│   ├── *.bpf.c
│   └── *.bpf.o           # single build artifact used by both runtimes
├── build/
└── results/
```

## 当前执行方式

- `run_micro.py` 读取 `config/suite.yaml`
- `Makefile` 统一构建 `libbpf`、`llvmbpf` helper、single-program object 和 vendored `bpftool`
- `micro_exec` 负责实际执行：
  - `run-llvmbpf`
  - `run-kernel`
- 两条 runtime 都加载同一个 `programs/*.bpf.o`
- Python runner 只负责 orchestration，不再负责 runtime 细节

## 完成标准

满足以下条件就算第一阶段可用：

- `python3 micro/run_micro.py --list` 能列出 bench 和 runtime
- `make -C micro` 能生成 runner 和共享 `.bpf.o` 产物
- `python3 micro/run_micro.py --runtime llvmbpf --runtime kernel` 能输出有效结果
- 结果写入 `micro/results/*.json`

## 下一步

- 把 F2 helper / F3 map / F6 branch layout 做成独立实验组
- 接 `perf stat` 或 `perf_event_open` 收 IPC / branch-miss / cache-miss
- 接 `bpftool prog dump jited` / `bpftool prog profile`
- 增加 verifier/JIT/load 分段统计
