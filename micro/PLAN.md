# Micro Benchmark Plan

## 目标

先把 `micro/` 落成一个可直接比较 `kernel eBPF` 和 `llvmbpf` 的微基准层，不等 macro 数据集全部就绪。

## 当前设计

- 每个 benchmark 维护一份单独的 `programs/*.bpf.c`，避免 runtime wrapper 分叉。
- `programs/common.h` 承担公共 helper 和 map-backed wrapper，benchmark 私有逻辑留在各自源文件里。
- 两条 runtime 都加载同一个 `programs/*.bpf.o`，保证比较的是同一份 ELF，而不是两套实现。
- `config/suite.yaml` 负责实验描述；`run_micro.py` 负责 orchestration；`micro_exec` 负责 runtime 细节。
- `llvmbpf` 通过 ELF loader 读取同一个 `.bpf.o`，并在 userspace 模拟 `input_map/result_map`。
- `kernel` 通过 `libbpf` + `BPF_PROG_TEST_RUN` 直接加载和执行同一个 `.bpf.o`。
- 当前结果 JSON 已记录 `compile_ns` / `exec_ns`、phase breakdown，以及可选的 `perf_event_open` 执行窗口计数器。

这样可以先把“同程序、双 runtime”的纯计算基线跑通，再扩展到设计文档里的因素隔离实验。

## 当前纳入

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

## 暂不纳入

- `bpftool prog profile`
- pass ablation
- Spectre on/off 双启动实验
- Macro benchmark 数据集批跑

## 完成标准

满足以下条件就算第一阶段可用：

- `python3 micro/run_micro.py --list` 能列出 bench 和 runtime
- `make -C micro` 能生成 runner 和共享 `.bpf.o` 产物
- `python3 micro/run_micro.py --runtime llvmbpf --runtime kernel` 能输出有效结果
- 结果写入 `micro/results/*.json`

## 下一步

- 把 F2 helper / F3 map / F6 branch layout 做成独立实验组
- 扩展 `perf_event_open` 采集面到 compile/load 阶段
- 接 `bpftool prog dump jited` / `bpftool prog profile`
- 增加 verifier/JIT/load 分段统计
