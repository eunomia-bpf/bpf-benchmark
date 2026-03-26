# 设计 Review 与变更概览

本文档对 `bpf-benchmark` 仓库当前的设计状态、已完成变更、以及待办清理做一次全面整理。

## 1. 仓库整体定位

本仓库的核心目标是：在同一份 BPF ELF 产物上，对比 **kernel eBPF**（Linux 内核 JIT）和 **llvmbpf**（用户态 LLVM JIT）的执行表现，产出可直接进入论文的数据和图表。

当前活跃开发区域是 `micro/`，配套的配置文件在 `micro/config/` 与 `corpus/config/`，研究文档在 `docs/`。
`user_bpf_benchmark/` 是早期的多 runtime 对比（ubpf/rbpf/wasmtime/native），已不再活跃维护。

## 2. 三层架构设计

```
micro/config/micro_pure_jit.yaml               ──→  纯 JIT codegen/exec 微基准
micro/config/micro_runtime.yaml (historical)   ──→  map/helper runtime 机制基准（已退役）
corpus/config/macro_corpus.yaml                ──→  真实程序语料库批跑入口
```

两条 runtime 共享同一个 `programs/*.bpf.o` 产物，保证对比的是同一份字节码。

### 执行链路

```
run_micro.py (orchestrator)
  ├─ runner/libs/catalog.py  读取 config/*.yaml → 统一 manifest dataclass
  ├─ input_generators.py     生成 .mem 二进制输入 → micro/generated-inputs/
  └─ micro_exec (C++ runner)
       ├─ run-llvmbpf        ELF→bytecode→LLVM JIT→userspace exec，map 在用户态模拟
       └─ run-kernel          libbpf load→BPF_PROG_TEST_RUN 内核执行
```

每个 sample 输出一行 JSON，包含 `compile_ns`、`exec_ns`、`phases_ns`、`perf_counters`。
Python 层聚合后写入 `micro/results/*.json`，再由 `summarize_rq.py` 生成 markdown 摘要。

### IO 模式

| 模式 | 输入路径 | 结果回收 | 用途 |
|------|---------|---------|------|
| `staged` | `input_map` staging 一次 | XDP test packet 前 8 字节 | `micro_pure_jit` 主路径 |
| `map` | `input_map` | `result_map` | `micro_runtime` 路径 |
| `packet` | packet payload | packet 前 8 字节 | 保留但当前未用 |

### BPF 程序约定

每个 `programs/*.bpf.c`：
1. 定义一个 input struct 和对应的 `input_map`
2. 实现 `bench_*()` 函数，签名 `(const u8 *data, u32 len, u64 *out) → int`
3. 使用 `common.h` 中的宏包装成 XDP 程序：
   - `DEFINE_STAGED_INPUT_XDP_BENCH` → pure-jit suite
   - `DEFINE_MAP_BACKED_XDP_BENCH` → runtime suite

## 3. 当前 git 变更总结

相对上一次提交（`d2a5099`），staged 区域包含以下核心变更：

### 已完成

| 变更 | 说明 |
|------|------|
| config 拆分 | `micro/config/suite.yaml` → 后续拆分为 `micro/config/micro_pure_jit.yaml` 与 `corpus/config/macro_corpus.yaml`（runtime suite 已退役） |
| pure-jit 扩展 | 从 ~8 case 扩展到 22 case，覆盖 7 个 category/family |
| staged IO 路径 | `micro_pure_jit` 不再依赖 `result_map`，改用 packet header 回收结果 |
| runtime suite | 新增 `map_lookup_churn`、`map_roundtrip` 两个 map 机制测试 |
| input_generators | 扩展到 23 个生成器，全部确定性 LCG |
| summarize_rq.py | 新增 RQ 摘要生成，支持 bootstrap CI 和 geometric mean |
| 语料库 | `corpus/` 新增 `repos.yaml` + `fetch_real_world_corpus.py`，已拉取 6 个上游仓库 |
| 论文草稿 | `docs/ebpf-characterization-paper-draft.md` 5 个 RQ 骨架 |
| 执行计划 | `docs/characterization-execution-plan.md` 4 轮迭代计划 |

### 新增 BPF 程序清单

| Category | Programs |
|----------|----------|
| baseline | `simple`, `memory_pair_sum` |
| alu-mix | `bitcount`, `log2_fold` |
| control-flow | `binary_search`, `branch_layout`, `switch_dispatch` |
| memory-local | `checksum`, `packet_parse`, `bounds_ladder`, `stride_load_4`, `stride_load_16` |
| dependency-ilp | `dep_chain_short`, `dep_chain_long`, `spill_pressure`, `multi_acc_4`, `multi_acc_8` |
| loop-shape | `fibonacci_iter`, `fixed_loop_small`, `fixed_loop_large` |
| call-size | `code_clone_2`, `code_clone_8` |
| map-runtime | `map_lookup_churn`, `map_roundtrip` |

## 4. 初步结果快照

基于 22-case `micro_pure_jit` suite 的 pilot 数据（Linux 6.15, x86_64, 10 iterations × 200 repeats）：

| 指标 | 值 | 95% bootstrap CI |
|------|---:|---:|
| Raw exec `llvmbpf/kernel` geomean | 1.06x | [0.80x, 1.46x] |
| Baseline-adjusted geomean | 0.68x | [0.54x, 0.84x] |
| Adjusted wins (llvmbpf/kernel/tie) | 14/4/3 | — |

**llvmbpf 优势区域**：control-flow (`branch_layout` 0.20x, `binary_search` 0.33x)、memory-local（stride loads 0.43-0.48x, `checksum` 0.75x）。
**kernel 优势区域**：`packet_parse` 1.22x, `fixed_loop_small` 1.17x, `code_clone_8` 1.15x, `multi_acc_4` 1.15x。

微架构上 llvmbpf 的 IPC 显著高于 kernel（3.89x vs 0.37x），但 cache miss rate 也更高。

## 5. 本次清理

| 操作 | 原因 |
|------|------|
| 删除 `docs/pure-jit-full-summary.md` | 与 `preliminary-characterization-summary.md` 内容重复（旧版 12-case 子集） |
| 删除 `docs/pure-jit-expanded-full-summary.md` | 与 `preliminary-characterization-summary.md` 完全相同 |
| 删除 `micro/config/` 空目录 | `suite.yaml` 已迁移到根 `config/`，目录残留 |
| 删除 `corpus/__pycache__/` | 不应被追踪的 Python 字节码缓存 |
| 更新根 `.gitignore` | 添加 `__pycache__/` 和 `*.pyc` 全局忽略 |
| 合并文档为 `docs/micro-bench-status.md` | 将 `micro/PLAN.md`、`characterization-execution-plan.md`、`characterization-todo.md`、`preliminary-characterization-summary.md`、`runtime-full-summary.md` 合并为统一文档，删除原文件 |
| 合并 `micro/THIRD_PARTY_NOTES.md` | 设计决策内容合并入 `docs/references/third-party-analysis.md`，删除原文件 |
| 合并 `references/ebpf-benchmark-gap-analysis.md` | 详细覆盖表格和缺口内容合并入 `docs/ebpf-bench-research-plan.md` §3，删除原文件 |

## 6. 文档结构整理

清理后 `docs/` 的职责划分：

| 文件 | 角色 | 状态 |
|------|------|------|
| `micro-bench-status.md` | **统一参考**：RQ、架构、覆盖、结果、进度、TODO | **活跃**，唯一进度入口 |
| `ebpf-characterization-paper-draft.md` | 论文骨架 | **活跃**，随数据更新 |
| `benchmark-framework-design.md` | 早期设计文档（RQ/假设框架、数据采集方法、测量环境） | **参考** |
| `ebpf-bench-research-plan.md` | 文献综述与 landscape + benchmark 缺口分析 | **参考**，90+ 论文梳理 |
| `references/*.md` | 第三方/内核 bench 分析 | **参考** |

## 7. 待办（下一步）

根据 `docs/micro-bench-status.md` 第 7 节，当前处于 **Iteration 2 → Iteration 3 过渡**：

### 高优先级

1. **JIT dump / code-size 采集** — 关闭 RQ1.1 和 RQ2 的代码质量维度
2. **verifier/load/JIT 分段统计** — 将 compile_ns 拆分为 verifier、JIT、ELF parse 三段
3. **扩展 llvmbpf ELF loader** — 支持 local subprogram call，解锁 `call-chain` family
4. **扩展 `micro_runtime`** — 增加 real helper-call、tail-call micro case

### 中优先级

5. **真实语料库批跑** — 在 corpus 的 429 个候选上尝试 kernel/llvmbpf 双跑
6. **图表生成脚本** — 为论文图表自动化

### 低优先级

7. **多程序实验** (RQ5)
8. **端到端场景**（tracing overhead, XDP throughput）

## 8. 已知约束

- `kernel` runtime 需要 `sudo -n` 无密码可用
- `llvmbpf` 通过 `MAP_32BIT` 分配低地址 packet buffer，供 XDP context 的 `u32` 指针使用
- `llvmbpf` ELF loader 不支持 BPF-to-BPF local subprogram call（已知限制，待扩展）
- `--perf-counters` 通过 `perf_event_open`；kernel 计数包含 kernel 态，llvmbpf 只看 user 态
- 短执行窗口或受限 PMU 下硬件计数器可能为 0，结果 JSON 中 `perf_counters_meta.hardware_counters_observed` 会标记
- `third-party/` 三个子目录（bpf_performance, tail-call-bench, bpf-bench）是参考项目快照，不参与编译和执行，仅用于设计借鉴
