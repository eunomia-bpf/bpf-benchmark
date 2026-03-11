# eBPF Micro Benchmark：实验计划、进度与分析

> 本文档是 micro benchmark 层的统一参考，合并了原来分散在多个文件中的实验计划、进度追踪、RQ 定义和结果分析。
> 详细的阶段性报告（含机器码分析细节）见 `docs/stage-log-2026-03-07.md`。

> 更新说明（2026-03-07）：`config/micro_pure_jit.yaml` 当前包含 `30` 个 pure-jit / staged-codegen case，另有 `2` 个 packet-backed 对照 benchmark，其中新增 `bpf_call_chain` 作为首个 local-call benchmark；`config/micro_runtime.yaml` 当前包含 `9` 个 runtime case。第 4 节覆盖表与第 7 节进度已按此状态同步，并新增可复现的 representativeness 分析脚本 `micro/archive/scripts/analyze_representativeness.py` 与真实程序 code-size / exec-time 外部验证脚本 `corpus/run_real_world_code_size.py`、`corpus/run_real_world_exec_time.py`。第 `6.1`、`6.1b`、`6.1e` 节现已切换为 authoritative pure-JIT run（`30` iterations × `1000` repeats，iteration 级 runtime 随机交错 / counterbalanced），覆盖 `31` 个 benchmark；执行时间 geomean 为 `0.849x`，BH-corrected paired Wilcoxon 显著 `25/31`，编译时间 geomean 为 `3.394x`。第 `6.2`、`6.4`、`6.5` 节已按同一 `31`-case authoritative 数据同步；第 `6.6` 节已切换为 authoritative runtime run（`9` case，执行时间 geomean `0.829x`，BH-corrected paired Wilcoxon 显著 `7/9`）。真实程序外部验证现已更新到 code-size `162` paired instances（`36` unique，geomean `0.618x`）与 exec-time `98` paired instances（`14` unique；valid packet rerun，instance geomean `0.514x` / unique geomean `0.484x`，`97/98` kernel exec ≥ `20ns`）。
> Note: benchmarks use staged input via `bpf_map_lookup_elem`; this measures JIT codegen quality under realistic input staging, not helper-free isolation.

---

## 1. 目标

在同一份 BPF ELF 产物上对比 **kernel eBPF**（Linux 内核 JIT）和 **llvmbpf**（用户态 LLVM JIT），产出可直接进入论文的可复现数据。

核心假设：llvmbpf 拥有完整 LLVM -O3 优化能力，在分支布局、指令调度、寄存器分配等代码质量维度上应优于 kernel 的单遍 JIT，但会在 map/helper 等 runtime 机制上暴露不同的 overhead 特征。

## 2. Research Questions

### RQ1: 性能差距有多大？

- **RQ1.1 代码尺寸**：kernel JIT vs llvmbpf -O3 生成的 native 指令数、代码膨胀比
- **RQ1.2 执行时间**：纯计算微基准和真实程序上的执行时间差距，是否随复杂度变化
- **RQ1.3 微架构质量**：IPC、分支预测命中率、I-cache 命中率的差异

### RQ2: 差距的根因是什么？

- **RQ2.1 基础代码质量**：寄存器分配、指令选择、指令调度的合计贡献
- **RQ2.2 Helper 调用开销**：indirect call + ABI 保存恢复的 overhead
- **RQ2.3 Map 访问模式**：hash lookup 等 map 操作的间接调用开销
- **RQ2.4 Spectre 缓解**：retpoline / LFENCE / IBRS 对 kernel JIT 增加的开销
- **RQ2.5 Verifier 约束**：bpf_loop callback、512B 栈限制、冗余边界检查的运行时开销

### RQ3: 哪类程序受益最大？

- 程序类别敏感性（networking / tracing / security / scheduling）
- Helper 调用频率分布（top-N 占比）
- 静态特征（指令数、helper 数、map 数、分支数）与优化收益的预测关系

### RQ4: 代码生成质量与 Spectre 缓解是否存在交互效应？

- 2×2 factorial: {kernel, llvmbpf} × {mitigations on/off}，交互效应量化

### RQ5: 多程序场景下的变化

- 同一 hook 挂 N 个程序的退化曲线
- 联合编译 (LTO) vs 独立编译的收益

**RQ 覆盖链条**：RQ1（测量） → RQ2（归因） → RQ3（分类预测） → RQ4（交互效应） → RQ5（多程序）

## 3. 三层架构

```
config/micro_pure_jit.yaml   ──→  pure-JIT / staged-codegen 微基准   (32 case = 30 pure-jit + 2 packet-backed)
config/micro_runtime.yaml    ──→  map/helper runtime 机制基准        (9 case)
config/macro_corpus.yaml     ──→  真实程序语料库入口 + 外部验证层   (first slice)
```

### 设计要点

- 每个 benchmark 维护一份 `programs/*.bpf.c`，两条 runtime 加载同一个 `.bpf.o`
- `programs/common.h` 提供三种 XDP wrapper 宏：
  - `DEFINE_STAGED_INPUT_XDP_BENCH` — staged-codegen suite：`input_map` staging 输入，packet header 回收结果
  - `DEFINE_MAP_BACKED_XDP_BENCH` — runtime suite：`input_map` + `result_map` 全程 map 路径
  - `DEFINE_PACKET_BACKED_XDP_BENCH` — packet IO（保留）
- `run_micro.py` 读取 YAML → 生成输入 → 调度 `micro_exec` → 聚合 JSON → raw ratio + `io_mode`-aware baseline adjustment + bootstrap CI
- `micro_exec` C++ runner：`run-llvmbpf`（ELF→bytecode→LLVM JIT→userspace exec，map 在用户态模拟）和 `run-kernel`（libbpf→BPF_PROG_TEST_RUN）
- 结果 JSON 包含 `compile_ns`、`exec_ns`、`timing_source`、`wall_exec_ns`、`phases_ns`、`perf_counters`、`derived_metrics`

### 当前纳入

- llvmbpf runtime（vendor/llvmbpf）
- kernel runtime（vendor/libbpf + BPF_PROG_TEST_RUN）
- vendored bpftool（可选）
- 声明式 config/*.yaml
- 共享输入生成器（确定性 LCG，40 个生成器）
- Family 元数据：category / family / level / hypothesis
- Phase timing + perf_event_open full-repeat 计数器
- Baseline-adjusted ratio + bootstrap CI + geometric mean
- Benchmark shuffle + per-iteration runtime 随机交错执行

### 暂不纳入

- `bpftool prog profile` / JIT dump 采集
- LLVM pass ablation
- Spectre on/off 双启动实验
- Macro benchmark 批跑
- 完整的 `bpf-to-bpf local call` family（当前已新增 `bpf_call_chain` 单 benchmark；更系统的 family 与 `32`-case authoritative 重跑仍未完成）

## 4. 当前覆盖

### micro_staged_codegen (32 case = 30 pure-jit + 2 packet-backed)

| Category | Family | Benchmarks |
|----------|--------|------------|
| baseline | baseline | `simple`（staged baseline）, `simple_packet`（packet-backed）, `memory_pair_sum` |
| alu-mix | popcount | `bitcount` |
| alu-mix | log2-fold | `log2_fold` |
| dependency-ilp | dep-chain | `dep_chain_short`, `dep_chain_long` |
| control-flow | search | `binary_search` |
| control-flow | branch-skew | `branch_layout` |
| control-flow | switch-dispatch | `switch_dispatch` |
| memory-local | reduction | `checksum` |
| memory-local | parser | `packet_parse` |
| memory-local | bounds-density | `bounds_ladder` |
| memory-local | stride-load | `stride_load_4`, `stride_load_16` |
| dependency-ilp | spill-pressure | `spill_pressure` |
| dependency-ilp | multi-acc | `multi_acc_4`, `multi_acc_8` |
| loop-shape | recurrence | `fibonacci_iter`, `fibonacci_iter_packet`（packet-backed） |
| loop-shape | fixed-loop | `fixed_loop_small`, `fixed_loop_large` |
| call-size | code-clone | `code_clone_2`, `code_clone_8` |
| call-overhead | bpf-local-call | `bpf_call_chain` |
| control-flow | branch-density | `branch_dense` |
| memory-local | bounds-style | `bounds_check_heavy` |
| alu-mix | mixed-alu-mem | `mixed_alu_mem` |
| loop-shape | nested-loop | `nested_loop_2`, `nested_loop_3` |
| program-scale | large-mixed | `large_mixed_500`, `large_mixed_1000` |

### micro_runtime (9 case)

| Category | Benchmarks |
|----------|------------|
| map-runtime | `map_lookup_churn`, `map_roundtrip`, `hash_map_lookup`, `percpu_map_update` |
| helper-runtime | `helper_call_1`, `helper_call_10`, `helper_call_100`, `probe_read_heavy`, `get_time_heavy` |

### 真实语料库（corpus）

6 个上游仓库，124 个候选程序源文件：

| Repo | 数量 |
|------|---:|
| bcc (libbpf-tools) | 57 |
| tetragon | 28 |
| cilium | 9 |
| libbpf-bootstrap | 15 |
| xdp-examples | 13 |
| katran | 2 |

> 2026-03-07 multi-function loader fix：llvmbpf 的 multi-function ELF loader 已修复，真实程序 compile-only paired set 从 `105` 扩到 `162`（`36` 个 unique program name），llvmbpf compile-only inspect 成功数从 `890` 提升到 `948`。当前 micro suite 已补入首个 local-call benchmark `bpf_call_chain`，但 representativeness 里的 multi-function gap 仍需单独承认。

### 真实程序 code-size 外部验证（多源）

- 脚本：`corpus/run_real_world_code_size.py`
- 报告：`corpus/results/real_world_code_size.md`
- 当前覆盖：`libbpf-bootstrap`、`bcf/cilium`、`bcf/inspektor-gadget`、`bcf/collected`
- 当前结果：纳入 `77` 个 input artifacts，枚举出 `949` 个真实 program，其中 `162` 个在 `llvmbpf` 和 `kernel` 上都完成了 compile-only inspect
- 代码尺寸结论：`llvmbpf/kernel` native code-size geomean 为 `0.618x`
- Caveat：`162` 个 paired instances 仍含有大量编译器版本重复（尤其 Cilium 程序会在 `clang-14` 到 `clang-21` 间重复出现 `8x`）；按 unique program name 去重后为 `36` 个 unique programs，来自 `cilium`、`libbpf-bootstrap` 与 `collected`。按该口径去重后，code-size geomean 仍约为 `0.641x`；llvmbpf 在 `151/162` 个 instances 与 `34/36` 个 unique programs 上更小，但 `handle_lxc_traffic` 与 `usdt_auto_attach` 出现了约 `1.07x` 的轻微反转。
- 当前失败分解：
  - llvmbpf：`948` ok / `1` error，multi-function loader 修复后只剩个别 jump-target / pseudo-instruction 兼容性问题
  - kernel：`162` ok / `787` error，失败主要是缺少 map/BTF / attach context 时的 verifier 拒绝

### 真实程序 execution-time 外部验证（初步）

- 脚本：`corpus/run_real_world_exec_time.py`
- 报告：`corpus/results/real_world_exec_time_v2.md`
- 方法：从更新后的 `162` 个 code-size paired instances 出发，尝试以 `--io-mode packet --raw-packet --repeat 1000` 在双 runtime 上执行
- 成功：`98/162` instances 双侧运行成功（`100` 个 kernel ok，其中 `98` 个 llvmbpf 也 ok）；按 unique program name 去重后为 `14` 个 unique programs
- 失败分解：`61` 个 `ENOTSUPP`（tracepoint/kprobe/cgroup），`1` 个 `Bad address`（iter/task），`2` 个 llvmbpf error

| 指标 | 值 |
|------|---:|
| Paired exec-time instances | 98 |
| Unique programs | 14 |
| Exec ratio geomean (L/K, all 98) | 0.514x |
| Exec ratio geomean (L/K, 14 unique) | 0.484x |
| llvmbpf wins / kernel wins / tie (unique) | 13 / 1 / 0 |

**重要 caveat**：已改用 valid Ethernet+IPv4+TCP raw packet（`--raw-packet`），dummy 全零包触发的 fast-exit artifact 已基本消除。当前 `97/98` 个 instance 的 kernel `exec_ns` 已达到 `20ns` 以上，其中 `tc_ingress` 达到 `120ns`。因此这些结果不再是“全部 sub-resolution”的入口路径测量；但大多数程序仍处于几十纳秒量级，仍应将其视作 lightweight external check，而非完整负载下的定量结论。

## 5. 测量环境

```
Machine:  Intel Core Ultra 9 285K (Arrow Lake-S)
Cores:    24 (P-core × 8 + E-core × 16), no HT
Cache:    L1d 768K, L1i 1.3M, L2 40M, L3 36M
RAM:      128GB DDR5
Kernel:   6.15.11-061511-generic (PREEMPT_DYNAMIC)
OS:       Ubuntu 24.04.3 LTS
Spectre:  Enhanced IBRS + IBPB conditional
BPF:      CONFIG_BPF_JIT=y, CONFIG_BPF_SYSCALL=y, BTF enabled
```

测量策略：
- 不做人为稳定化（不锁频、不禁 turbo），通过足够重复 + 统计分析处理噪声
- 默认参数：iterations=10, warmups=2, repeat=200
- benchmark 级顺序可用 `--shuffle-seed` 打乱；同一 benchmark 内的 runtime 顺序按 iteration 随机交错执行
- 可选 `--perf-counters` 采集 full-repeat 计数器，`--perf-scope` 支持 `full_repeat_raw` 和 `full_repeat_avg`
- 结果 JSON 自动记录环境元数据：`git_sha`、`kernel_version`、`kernel_cmdline`、`cpu_governor`、`turbo_state`、`perf_event_paranoid`
- 摘要层输出 geometric mean + bootstrap 95% CI（10000 iterations）

### 约束

- `kernel` runtime 需要 `sudo -n` 无密码可用
- llvmbpf 通过 `MAP_32BIT` 分配低地址 packet buffer，供 XDP context 的 u32 指针使用
- llvmbpf multi-function ELF loader 已修复；当前 real-world 剩余失败主要来自个别 jump-target / pseudo-instruction 兼容性问题，而非普遍性的 local subprogram call 不支持
- `--perf-counters` kernel 计数包含 kernel 态，llvmbpf 只看 user 态
- `full_repeat_raw` 输出整段 repeat 的原始计数，`full_repeat_avg` 输出除以 repeat 后的 per-repeat 平均值
- 短执行窗口或受限 PMU 下硬件计数器可能为 0

### 5.1 Threats to Validity

- 真实程序 execution-time 对比受 `BPF_PROG_TEST_RUN` 结构性限制：tracepoint/kprobe/perf_event 程序返回 `ENOTSUPP` (`524`)，fentry/fexit 在 dummy input 下 `exec_ns=0`。TC/classifier 和 socket_filter 程序可以运行（当前通过 `--io-mode packet --raw-packet` 提供 valid Ethernet+IPv4+TCP input）；已在 `98/162` 个 paired instance（`14` 个 unique program）上获得执行时间数据。valid packet rerun 后 instance geomean 为 `0.514x`、unique geomean 为 `0.484x`，llvmbpf 在 `13/14` 个 unique programs 上更快，且 `97/98` 个 kernel timing 已达到 `20ns` 以上（其中 `1/98` 超过 `100ns`）。这些结果仍主要反映短 packet path，而非完整 workload。
- 单一平台：仅在 x86-64 Intel Arrow Lake-S 上测试，未覆盖 ARM64；BPF JIT 在 ARM64 上的后端代码可能不同，结论外推需谨慎。
- `exec_ns` 计时来源不对等：kernel 使用 `ktime_get_ns`（~100ns 分辨率，可能受 NTP 调整影响），llvmbpf 使用 `rdtsc`（亚纳秒分辨率，受 TSC 频率校准影响）。两者都测纯 BPF 执行时间，但 ktime 的量化粒度意味着 kernel 侧对 <100ns 程序的计时本质上是噪声（已在 paradox 分析中将 3 个 sub-resolution case 标记为 measurement artifact）。对于 >100ns 的程序，两种时钟源在绝对精度上的差异相对于观测到的 exec ratio 范围（0.29x–1.88x）可忽略。论文中应标注 `timing_source` 并讨论此不对等。
- PMU 范围不等价：kernel perf counters 包含 kernel-mode 事件，llvmbpf 只看 user-mode；当前 PMU 结果仅作定性补充证据，不进入主论证链。
- 外部验证集中度：code-size paired set 虽已扩到 `162` 个 instances / `36` 个 unique programs，但仍含大量 clang 版本重复；其中 compile-only paired 结果来自 `3` 个 repo（`cilium`、`libbpf-bootstrap`、`collected`），而 exec-time subset 仍只覆盖 `98` 个 instances / `14` 个 unique programs，且仅来自 `2` 个 repo（`cilium` 与 `libbpf-bootstrap`）。
- CPU 频率控制：authoritative run 使用 `--strict-env`（taskset 绑核 + `performance` governor），但未显式禁用 turbo boost 或 SMT。Intel Arrow Lake-S 的 turbo boost 可能引入跨 iteration 的频率抖动；drift 分析显示 `3/62` pair 有显著漂移（最大 16.13%），表明频率变化的影响有限但非零。

## 6. 结果

> 以下 pure-JIT 主结果（§`6.1` / §`6.1b` / §`6.1e`）已切换为 authoritative 分析结果（`micro/results/pure_jit_authoritative_analysis.md`，生成于 `2026-03-07`）。
> 旧版 baseline-adjusted 数据已废弃，llvmbpf 改用 per-iteration rdtsc 测量纯 vm.exec() 时间。

### 6.1 micro_staged_codegen 执行时间 (31 case)

> authoritative run：`30` iterations × `1000` repeats，iteration 内 runtime 顺序随机交错（counterbalanced）；完整分析见 `micro/results/pure_jit_authoritative_analysis.md`

**Suite-Level**

| 指标 | 值 |
|------|---:|
| Exec time llvmbpf/kernel geomean | 0.849x |
| 95% CI | [0.834, 0.865] |
| Significant benchmarks (BH-corrected paired Wilcoxon p < 0.05) | 25 / 31 |
| Wins (llvmbpf/kernel/tie) | 21/10/0 |

**Benchmark-Level（按 exec ratio 排序）**

| Benchmark | Category | llvmbpf ns (mean) | kernel ns (mean) | Exec ratio | Code ratio |
|-----------|----------|------------------:|----------------:|-----------:|-----------:|
| `branch_layout` | control-flow | 162.03 | 560.50 | 0.289x | 0.354x |
| `nested_loop_3` | loop-shape | 277.27 | 684.13 | 0.405x | 0.884x |
| `stride_load_16` | memory-local | 104.20 | 246.40 | 0.423x | 0.332x |
| `stride_load_4` | memory-local | 106.53 | 241.20 | 0.442x | 0.332x |
| `bounds_ladder` | memory-local | 90.60 | 189.07 | 0.479x | 0.394x |
| `binary_search` | control-flow | 212.77 | 442.17 | 0.481x | 0.449x |
| `large_mixed_500` | program-scale | 354.67 | 511.97 | 0.693x | 0.464x |
| `mixed_alu_mem` | alu-mix | 512.47 | 695.60 | 0.737x | 0.817x |
| `large_mixed_1000` | program-scale | 743.67 | 1,001.60 | 0.742x | 0.419x |
| `fixed_loop_small` | loop-shape | 103.53 | 136.43 | 0.759x | 0.359x |
| `switch_dispatch` | control-flow | 211.67 | 268.33 | 0.789x | 0.800x |
| `fibonacci_iter` | loop-shape | 577.03 | 718.97 | 0.803x | 0.395x |
| `fibonacci_iter_packet` | loop-shape | 599.27 | 732.20 | 0.818x | 0.343x |
| `nested_loop_2` | loop-shape | 440.57 | 535.27 | 0.823x | 0.501x |
| `dep_chain_short` | dependency-ilp | 126.83 | 147.23 | 0.861x | 0.413x |
| `spill_pressure` | dependency-ilp | 255.57 | 293.50 | 0.871x | 0.759x |
| `checksum` | memory-local | 10,829.10 | 12,031.43 | 0.900x | 0.418x |
| `multi_acc_4` | dependency-ilp | 273.00 | 286.93 | 0.951x | 0.646x |
| `multi_acc_8` | dependency-ilp | 435.83 | 458.47 | 0.951x | 0.756x |
| `dep_chain_long` | dependency-ilp | 419.40 | 434.90 | 0.964x | 0.414x |
| `packet_parse` | memory-local | 98.93 | 102.63 | 0.964x | 0.496x |
| `log2_fold` | alu-mix | 312.30 | 310.50 | 1.006x | 0.659x |
| `bounds_check_heavy` | memory-local | 283.13 | 253.10 | 1.119x | 0.807x |
| `fixed_loop_large` | loop-shape | 1,492.97 | 1,251.10 | 1.193x | 0.425x |
| `memory_pair_sum` | baseline | 19.10 | 15.27 | 1.251x | 0.238x |
| `code_clone_2` | call-size | 409.43 | 324.83 | 1.260x | 0.492x |
| `simple_packet` | baseline | 17.70 | 13.40 | 1.321x | 0.490x |
| `branch_dense` | control-flow | 628.17 | 445.90 | 1.409x | 0.732x |
| `simple` | baseline | 20.90 | 13.70 | 1.526x | 0.622x |
| `bitcount` | alu-mix | 4,646.57 | 2,985.33 | 1.556x | 0.446x |
| `code_clone_8` | call-size | 2,266.93 | 1,206.97 | 1.878x | 0.542x |

### 6.1b 统计严谨性分析（authoritative 31-case run）

> 本节以 `micro/results/pure_jit_authoritative_analysis.md` 为准，并以 §`6.1` 的 authoritative `31`-case 主结果为正文依据；旧的 `22`-case pilot 已被 authoritative `31`-case run 取代，仅保留为历史记录。
> Primary test: matched `iteration_index` paired Wilcoxon signed-rank + Benjamini-Hochberg correction；Bootstrap `10000` 次（seed `0`）用于 geomean 95% CI；Mann-Whitney U 仅作补充参考。

| 指标 | 值 |
|------|---:|
| Benchmarks with valid paired Wilcoxon input | 31 / 31 |
| Exec ratio geomean (L/K) | 0.849x |
| 95% CI | [0.834, 0.865] |
| 统计显著 benchmarks (BH-adjusted paired Wilcoxon p < 0.05) | 25 / 31 |
| 不显著 benchmarks | `simple_packet`, `log2_fold`, `dep_chain_long`, `packet_parse`, `bounds_check_heavy`, `multi_acc_4` |

**结论**：authoritative 数据确认整体结论不变：llvmbpf 在多数 benchmark 上执行更快，但仍有少数 case 接近持平或受短时窗口噪声影响而未达显著。旧 `22`-case pilot 仅保留为历史记录，不再作为正文结论依据。

### 6.1c BCF 静态字节码分析与 Helper Pareto (H4)

> 数据来源：`corpus/results/bytecode_features.json`、`corpus/results/helper_pareto.json`
> 分析脚本：`corpus/analyze_bytecode.py`，覆盖 1588 个 BCF 程序

**Helper 调用频率 Pareto (H4: top-5 = 80%+)**

| Rank | Helper ID | 名称 | 调用次数 | 占比 | 累计 |
|---:|---:|---|---:|---:|---:|
| 1 | 6 | trace_printk | 391,689 | 49.15% | 49.15% |
| 2 | 1 | map_lookup_elem | 107,497 | 13.49% | 62.64% |
| 3 | 39 | (probe_read_kernel) | 76,589 | 9.61% | 72.26% |
| 4 | 2 | map_update_elem | 47,511 | 5.96% | 78.22% |
| 5 | 11 | (tail_call) | 26,625 | 3.34% | 81.56% |

**H4 结论**：Top-5 helper 占总调用的 81.56%，假设验证通过。对 runtime 优化的启示：优先实现 trace_printk 的高效内联路径（49% 调用量），其次是 map_lookup/update（19.5%）。

**程序特征分布（1588 个程序）：**
- 多函数 ELF section（`has_subprograms`）：97.2% 的程序含有多个函数符号（Calico 主导），但仅 3.3% 含有显式 BPF-to-BPF call 指令（`bpf2bpf_call_count > 0`）
- 平均 BPF insn 数：中位数 ~10,977，p90 ~22,899
- Helper 种类：共 45 种不同 helper ID

### 6.1d 时间序列稳定性分析

> 数据来源：`micro/results/pure_jit_authoritative.json`，分析脚本：`micro/archive/scripts/analyze_stability.py`
> 覆盖 62 个 benchmark × runtime 对（31 benchmarks × 2 runtimes），时间序列图见 `micro/results/stability/`

| 指标 | 值 |
|------|---:|
| 有显著 drift 的 pair (p < 0.05) | 3 / 62 |
| 强自相关的 pair (\|ACF(1)\| > 0.3) | 3 / 62 |
| 最大 drift 幅度 | 16.13% (stride_load_4 kernel) |

**结论**：测量系统在 30 iterations 运行期间保持高度稳定。3 个有 drift 的 pair 中最大为 `stride_load_4` kernel（16.13%），其余两个分别为 `mixed_alu_mem` kernel（-4.46%）和 `fixed_loop_large` llvmbpf（3.12%），不改变 suite 级结论。

### 6.1e 编译时间分析

> 数据来源：`micro/results/pure_jit_authoritative_analysis.md` (Compile Time Analysis section)

| 指标 | 值 |
|------|---:|
| llvmbpf/kernel compile time geomean | 3.394x |
| llvmbpf 更快的 benchmark | 5/31 (`bitcount`, `binary_search`, `branch_layout`, `switch_dispatch`, `checksum`) |
| llvmbpf 更慢的 benchmark | 26/31（其中 `branch_dense` 近似持平，ratio=`1.004x`） |

**模式**：对于小程序 (< 200 BPF insns)，llvmbpf LLVM -O3 开销主导，编译常见慢 `8`-`16x`。对于部分大/复杂程序（如 `bitcount`、`binary_search`、`branch_layout`、`switch_dispatch`、`checksum`），kernel verifier + JIT 反而更慢。编译时间差异对 networking fast-path 不重要（一次性开销），但对频繁加载场景（如 Cilium live reload）有影响。

### 6.1f kernel 侧 rdtsc 测量（测量方法对齐）

> 修改：`micro/runner/src/kernel_runner.cpp` 添加 rdtsc/rdtscp 围栏计时

kernel_runner 现在同时输出：
- `exec_ns`：kernel 内部 `ktime_get_ns` 测量的纯 BPF 执行时间（不含 syscall）
- `wall_exec_ns`：用户态 rdtsc 测量的 wall-clock 时间（包含 BPF_PROG_TEST_RUN syscall dispatch 开销）
- `exec_cycles`：rdtsc 原始 cycle 数

对 `simple` benchmark (repeat=100) 的验证：kernel `exec_ns=25ns` vs `wall_exec_ns=193μs`，差距 ~7700x，主要是 syscall dispatch 开销。论文中应使用 `exec_ns`（kernel 内部计时）作为 kernel 性能指标，`wall_exec_ns` 作为端到端 dispatch cost 的参考。

### 6.2 代码质量对比（code-size + 指令分析）

**Code Size**

| 指标 | 值 |
|------|---:|
| llvmbpf/kernel native code size geomean | 0.496x |
| llvmbpf 全面更小 | 31/31 benchmarks |

**指令级分析**（完整报告见 `micro/jit-dumps/report.md`）

| 维度 | llvmbpf/kernel ratio | 说明 |
|------|---:|------|
| 总指令数 | 0.44x | LLVM 生成不到一半的指令 |
| Prologue 指令 | 0.40x | kernel 固定保存 rbp+rbx+r13-r15，LLVM 按需保存 |
| Spill 指令 | 0.85x | 寄存器溢出差距不如预期大 |
| 分支指令 | 0.76x | kernel 1:1 翻译 BPF 分支，LLVM 做布局优化 |
| cmov 指令 | 31 vs 0 | LLVM 用条件移动替代分支（`switch_dispatch` 28 个 cmov） |

**Kernel 额外指令来源分解**

| 来源 | 占总增量比例 | 说明 |
|------|---:|------|
| Byte-load-recompose | 50.7% | kernel 用 `movzbq + shl + or` 逐字节重组 32/64 位值（verifier 安全要求） |
| 分支指令 | 19.9% | 1:1 翻译 BPF 分支，不做布局优化 |
| Prologue/epilogue | 18.5% | 固定 callee-saved 寄存器保存 |

### 6.3 LLVM 优化级别消融

| 优化级别 | Code size (avg) | 说明 |
|---------|---:|------|
| -O0 | 1057 B | 无优化 baseline |
| -O1 | 307 B | **所有主要优化在此完成**（0.29x of O0） |
| -O2 | 307 B | 与 O1 完全相同 |
| -O3 | 307 B | 与 O1 完全相同 |

**关键发现**：对 BPF 程序这种短小代码，O1→O3 零增量。基础优化（DCE、常量传播、寄存器分配）就够了，高级优化（loop unroll、vectorization）无用。

### 6.4 核心矛盾："代码更小但执行更慢"

authoritative `31`-case run 中，`10/31` 个 benchmark 出现 llvmbpf 代码更小但执行更慢（即 exec ratio `> 1.0` 且 code ratio `< 1.0`）：

| Benchmark | Exec ratio | Code ratio | 显著性 |
|-----------|-----------:|-----------:|--------|
| `simple` | 1.526x | 0.622x | Yes |
| `simple_packet` | 1.321x | 0.490x | No |
| `memory_pair_sum` | 1.251x | 0.238x | Yes |
| `bitcount` | 1.556x | 0.446x | Yes |
| `log2_fold` | 1.006x | 0.659x | No |
| `branch_dense` | 1.409x | 0.732x | Yes |
| `bounds_check_heavy` | 1.119x | 0.807x | No |
| `fixed_loop_large` | 1.193x | 0.425x | Yes |
| `code_clone_2` | 1.260x | 0.492x | Yes |
| `code_clone_8` | 1.878x | 0.542x | Yes |

其中 `7/10` 个 case 在 BH-corrected paired Wilcoxon 下显著。但 `3` 个 case（`simple`、`simple_packet`、`memory_pair_sum`）的 kernel exec 均低于本平台 ~100ns 的 `ktime_get_ns()` 分辨率，属于**计时量化噪声**（measurement artifact），应从实质性 paradox 分析中排除。排除后剩余 `7` 个 real paradox case，其中 `5` 个显著。

**论文洞察**：代码大小 ≠ 性能。authoritative 数据表明 llvmbpf 的 native code-size 优势是普遍的（`31/31` 更小），但执行时间收益仍取决于具体数据流、循环形态和 runtime 机制，不能仅用代码尺寸预测。

**因果分类（详见 `micro/results/paradox_analysis.md`）**

10 个 paradox case 分为 4 类；其中 sub-resolution 为 measurement artifact，实质性 paradox 为 7 个：

| 类别 | 数量 | 性质 | Benchmarks | 机制 |
|------|--:|------|------------|------|
| sub-resolution | 3 | measurement artifact | simple, simple_packet, memory_pair_sum | kernel exec < 100ns，`ktime_get_ns()` 量化噪声主导，应排除 |
| tight-loop | 3 | real paradox | bitcount, fixed_loop_large, log2_fold | 循环承载依赖链决定运行时间，LLVM 消除的主要是非关键路径指令 |
| code-clone | 2 | real paradox | code_clone_8, code_clone_2 | 克隆的直行数学体在循环内，kernel 的直接翻译与 LLVM 优化同等高效 |
| branch-heavy | 2 | real paradox | branch_dense, bounds_check_heavy | 每次循环迭代 7-8 个条件分支，分支预测器压力（而非代码尺寸）主导关键路径 |

**核心洞察**：排除 3 个 sub-resolution measurement artifact 后，`7/7` 个 real paradox case 均为真实的”更小但更慢”现象。LLVM 的指令消除主要减少非关键路径指令；在这些 case 中，运行时间由循环依赖链、克隆直行数学或密集控制流决定，代码更小不等于关键路径更短。

**补充因果隔离（详见 `micro/results/causal_isolation_analysis.md`；对应 stage-log §4.5）**：新增 `4` 个 byte-recompose causal benchmark 后，`load_byte_recompose` 的 exec ratio 为 **`0.447x`**，整组 causal benchmark 的 exec geomean 为 **`0.660x`**，且 `4/4` 均显著。这把 kernel byte-recompose lowering 的时间代价从“额外指令多”推进到“额外时间有多大”的层面，定量回答了 byte-recompose 是否真在动态关键路径上。

**补充深度性能分析（详见 `micro/results/performance_deep_analysis.md`；对应 stage-log §4.6）**：per-category geomean 显示 llvmbpf 的优势主要集中在 `control-flow`（`0.627x`）与 `memory-local`（`0.665x`），而 `call-size`（`1.539x`）与 `baseline`（`1.361x`）仍偏向 kernel；同时，静态特征 runtime model 的 `R^2 = 0.070`，说明仅靠 instruction count / branch count / code ratio 这类静态变量几乎无法预测 steady-state exec ratio。

### 6.5 测量方法论修正

| 维度 | 现行 authoritative 方法 |
|------|------------------------|
| 采样设计 | `30` iterations × `1000` repeats；同一 benchmark 内按 iteration 随机交错 / counterbalanced 执行 `llvmbpf` 与 `kernel` |
| 配对原则 | 以 `iteration_index` 做 matched pairs，避免 runtime 执行顺序和时间漂移混入跨-runtime 差异 |
| 主检验 | paired Wilcoxon signed-rank；跨 benchmark 用 Benjamini-Hochberg 做多重比较校正 |
| 区间估计 | Bootstrap `10000` 次（seed `0`）计算 geomean 95% CI |
| 次检验 | Mann-Whitney U 仅作补充参考，不再作为主结论依据 |
| 计时来源 | llvmbpf 用 per-iteration `rdtsc/rdtscp` 仅包围 `vm.exec()`；kernel 用 `exec_ns` (`ktime`) 作为纯 BPF 执行时间 |
| 已废弃方法 | 旧的 baseline-adjusted ratio 已移除；正文统一使用 authoritative raw exec ratio |

**备注**：perf counter 仍受 kernel/user 计数窗口不完全等价的限制，适合作为辅助诊断，不作为主显著性结论依据。
**PMU caveat**：当前 `micro/results/pmu_analysis_rigorous.md` 仅覆盖 `18` 个 benchmark 的 kernel 侧 PMU 数据，其中只有 `3` 个 benchmark 同时具备 `llvmbpf + kernel` 的 IPC 数据；这类 sparseness 主要来自 benchmark 执行窗口过短，短于 `perf_event_open` / PMU 调度粒度。因而论文中 PMU 只作为定性补充证据，不作为主因果证据；因果归因以 code-size ratio、指令模式分析和 §`6.4` 的“代码更小但执行更慢”悖论分析为主。

### 6.6 micro_runtime (9 case)

> authoritative run：`30` iterations × `1000` repeats；Primary test 为 matched `iteration_index` paired Wilcoxon + BH correction。完整分析见 `micro/results/runtime_authoritative_analysis.md`

| 指标 | 值 |
|------|---:|
| Exec time llvmbpf/kernel geomean | 0.829x |
| 95% CI | [0.801, 0.859] |
| Significant benchmarks (BH-corrected paired Wilcoxon p < 0.05) | 7 / 9 |
| Wins (llvmbpf/kernel/tie) | 6/3/0 |

| Benchmark | Exec ratio | 显著性 |
|-----------|-----------:|--------|
| `map_lookup_churn` | 1.307x | Yes |
| `map_roundtrip` | 0.726x | Yes |
| `hash_map_lookup` | 0.681x | Yes |
| `percpu_map_update` | 0.490x | Yes |
| `helper_call_1` | 1.047x | No |
| `helper_call_10` | 0.990x | No |
| `helper_call_100` | 0.962x | Yes |
| `probe_read_heavy` | 0.566x | Yes |
| `get_time_heavy` | 1.038x | Yes |

**结论**：runtime suite 中 llvmbpf 在 `6/9` 个 case 上更快，优势主要集中在 map-heavy 和 `probe_read` workload；kernel 仅在 `map_lookup_churn` 与 `get_time_heavy` 上显著更快，`helper_call_1` 虽 ratio `> 1.0` 但未达显著。

### 6.7 Feature-Space Representativeness

> 分析脚本：`micro/archive/scripts/analyze_representativeness.py`
> 报告：`micro/results/representativeness_report.md`
> 真实语料：`corpus/results/bytecode_features.json`（`1588` 个程序）
> 统计口径：当前 representativeness report 纳入 `35` 个 pure-jit benchmark 与 `9` 个 runtime benchmark，合计 `44` 个 benchmark，覆盖 `10` 个 category。其中 `31` 个 pure-jit benchmark 有 authoritative 结果（§6.1），另外 `4` 个（`load_byte`、`load_byte_recompose`、`load_word32`、`load_native_u64`）是后续添加的 byte-recompose 因果隔离 benchmark，尚无 authoritative 结果但已纳入 feature-space 覆盖分析

这里的 framing 必须明确：这些 micro-benchmark 的设计目标是**因果隔离**特定 JIT 机制（如分支布局、寄存器分配、memory access pattern、helper/map runtime path），而**不是**在统计意义上代表全部真实 BPF 程序。representativeness 分析的作用，是把这种 external-validity gap 定量化、公开化，让读者能够诚实判断“机制级结论能外推到什么范围”；与之互补的外部效度证据，则来自前文真实程序 code-size 外部验证（当前 paired 结果为 `162` 个 instances / `36` 个 unique programs；llvmbpf compile-only inspect `948` ok / `1` error）。

**关键静态特征范围（combined suite vs. 真实语料）**

| 特征 | 真实语料中位数 | 真实语料 p90 | Combined max |
|------|--------------:|------------:|-------------:|
| Total insns | 10977 | 22899 | 1596 |
| Branch insns | 1135 | 1458 | 196 |
| Memory ops | 5203 | 11437 | 253 |
| Helper calls | 289 | 847 | 101 |
| BPF-to-BPF calls | 0 | 0 | 0 |

**覆盖率摘要（combined suite）**

| 指标 | 覆盖率 |
|------|------:|
| 落在指令数范围内的 corpus 程序 | 3.7% |
| 落在 helper-call 范围内的 corpus 程序 | 4.4% |
| 落在 BPF-to-BPF call 范围内的 corpus 程序 | 96.7% |
| 落在 5D feature box 内的 corpus 程序 | 0.8% |

**剩余缺口**

- **程序规模仍是主缺口**：combined suite 的最大程序仅到 `1596` 条 BPF insns，而真实语料中位数已达 `10977`、p90 为 `22899`；分支与内存操作维度也有同向压缩（例如 Branch max `196` vs corpus median `1135`，Memory ops max `253` vs corpus median `5203`）。
- **helper-heavy workload 覆盖仍弱**：suite 的静态 helper 调用上限为 `101`，低于真实语料的中位数 `289` 与 p90 `847`，因此仅靠 helper 这一维也只覆盖 `4.4%` 的 corpus。
- **子程序结构存在结构性空白**：从静态 `bpf2bpf_call_count` 维度看，range coverage 高达 `96.7%`，但这并不代表“多函数程序”被覆盖；报告同时显示 `97.2%` 的真实程序包含多个函数，而当前 suite 仅新增了 `bpf_call_chain` 这一项 local-call 覆盖。虽然 llvmbpf 的 multi-function ELF loader 已修复并把外部 paired code-size 集扩到 `162/36`，该结构性缺口仍未被 representativeness 分析自动消除。
- **多维联合代表性极低**：只有 `0.8%` 的真实程序落在 combined 5D feature box 内，因此论文必须把 micro-benchmark 结论明确定位为”机制级因果证据”，并继续依赖真实程序 code-size 外部验证与 macro-corpus 分析提供外部效度。

### 6.8 Executive Summary (2026-03-07)

> Full details with machine code analysis: `docs/stage-log-2026-03-07.md`.

**Execution time**: llvmbpf is **0.849x** (pure-JIT, 31 benchmarks) and **0.829x** (runtime, 9 benchmarks) vs kernel, with 25/31 and 7/9 results statistically significant (BH-corrected paired Wilcoxon). llvmbpf wins 21/31 benchmarks; kernel wins 10/31.

**Code quality**: llvmbpf generates **0.496x** native code (31/31 smaller). JIT dump analysis across 22 benchmarks shows kernel's extra instructions come from: byte-load-recompose (50.7% of surplus), branch 1:1 translation (19.9%), and fixed callee-saved prologue (18.5%). LLVM uniquely uses `cmov` (31 total, kernel = 0) and BMI bit-manipulation instructions.

**Paradox (“smaller but slower”)**: 7 real cases after excluding 3 sub-resolution artifacts. Root causes: loop-carried dependency chains (3), cloned straight-line math (2), branch-predictor pressure from 7–8 conditionals/iteration (2). Core insight: LLVM eliminates non-critical-path instructions; critical path is determined by data dependencies and branch density, not code size.

**External validation**: 162 paired real programs (36 unique) from 4 repos — code-size geomean **0.618x**; llvmbpf is still smaller on **34/36** unique programs. Exec-time: 98/162 packet-runnable programs completed on both runtimes (14 unique), with valid raw packets improving the geomean to **0.514x** by instance and **0.484x** by unique program; `97/98` kernel timings are now at least `20ns`, and `tc_ingress` reaches `120ns`. Feature-space coverage: **0.8%** of 1588-program BCF corpus.

**Publication readiness**: 7.5/10. Strong micro-benchmark rigor and causal analysis; external validity is better than the 105-pair stage but still bounded (0.8% coverage, 36 unique code-size programs, real-program exec-time still concentrated in short TC/socket packet paths). Top gaps are expanding local-call coverage beyond a single benchmark and broadening real-program execution coverage, not the old loader blocker itself.

## 下一步优先级（2026-03-07 更新）

> 按 impact/effort 排序的行动计划。当前评分 8.0/10，目标 8.5/10。
> 本轮进展：N1(valid-packet) + N2(kernel改进分析) + N5(local-call) + N7/N8(定位) + N10(图表) 已完成；N3(pass消融) 基础设施就绪。

### P0 — 完成 valid-packet 外部验证（7.5 → 8.0 的关键）

- [x] **N1. 构造真实网络包** — 此前 98 个 exec-time 实例全部 sub-resolution（kernel exec < 100ns），根因是 dummy 全零包触发 TC 程序快速退出。需要构造合法 Ethernet + IP + TCP header（≥54 字节），使程序走完整处理路径。目标：获得第一批 kernel exec > 100ns 的真实程序性能数据。
  - 已完成：生成 valid Ethernet+IPv4+TCP packet，添加 --raw-packet flag。Geomean 从 0.694x 改善到 0.514x。
  - 验证：`97/98` 个 kernel exec_ns 已达到 `20ns` 以上，其中 `tc_ingress` 达到 `120ns`

### P1 — 论文 "so what" 贡献（8.0 → 8.5）

- [x] **N2. Kernel JIT 改进建议与 patch prototype** — 基于分析提出 3 个具体建议，详见 `docs/kernel-jit-improvements.md`：
  1. byte-recompose 优化：占 50.7% 额外指令，2.24x 时间惩罚
  2. cmov 支持：kernel 0 个 vs llvmbpf 31 个（switch_dispatch 28 个）
  3. per-function callee-saved：占 18.5% 额外指令
  - 已完成详细分析文档（含指令序列、量化证据、实现建议）
  - 剩余：Linux kernel patch prototype

- [~] **N3. LLVM Pass 消融（T3.7）** — 逐 pass 禁用 instcombine / GVN / LICM 等，识别对 BPF 最关键的 pass。
  - 已完成：pass ablation 基础设施（`--llvm-disable-pass` / `--llvm-log-passes`）
  - 已确认 O1 已包含大部分关键 pass（instcombine/SROA/LICM/SCCP/ADCE），O2 新增 GVN/DSE/JumpThreading，O3 仅增 argpromotion/callsite-splitting/CHR
  - 剩余：对 9 个候选 pass 逐个消融跑 benchmark 矩阵

### P2 — 扩大外部效度

- [ ] **N4. 扩展 BCF corpus 全量 code-size 扫描** — 当前只扫了 4 repo / 949 程序。llvmbpf 侧已解锁（948/949 ok），但 kernel 侧仅 162/949 ok。需探索 kernel 侧绕过 verifier 的方案（如 veristat、bpf_prog_test_run with dummy context）。
  - 目标：500+ paired programs 的 code-size 分布图

- [~] **N5. micro suite 增加 local-call benchmark family** — 现在 loader 支持多函数了，可以写含 BPF-to-BPF call 的 benchmark，继续填补当前仅有单点覆盖的子程序结构空白。
  - 已创建 `bpf_call_chain` benchmark，llvmbpf `284ns/580B` vs kernel `384ns/938B`

- [ ] **N6. 第二平台交叉验证** — 当前只在 x86-64 Arrow Lake-S 上测试。至少在一个不同 x86 微架构或 ARM64 上跑 reduced suite。
  - 需要：硬件访问

### P3 — 论文写作与定位

- [x] **N7. 与 K2/Merlin/EPSO 正交性分析（T3.15）** — 详见 `docs/related-work-positioning.md`：bytecode 级优化（verifier 前）与 JIT 后端优化（native 级）正交可叠加；code-size 0.496x 超越 bytecode 级工具的 6-26%
- [x] **N8. 跨工具对比定位（T3.16）** — 详见 `docs/related-work-positioning.md`：与 CoNEXT'25 / "No Two Snowflakes" / ETH Zurich 等 5 个系统的差异化分析
- [ ] **N9. 论文初稿写作** — 基于 stage-log 结构，填充 Introduction / Background / Methodology / Results / Discussion / Threats
- [x] **N10. 图表生成脚本** — `micro/generate_figures.py` 生成 6 张 PDF 图表（exec ratio / code size / category / compile time / scatter / causal isolation）于 `micro/results/figures/`

### 已完成（本轮）

- [x] **多函数 ELF loader 修复** — llvmbpf ok 890→948，paired 105→162（36 unique）
- [x] **raw-packet 支持** — C++ runner 新增 `--raw-packet` flag，Python 脚本生成 valid packet。exec-time geomean 0.694x → 0.514x
- [x] **BPF-to-BPF local call benchmark** — `bpf_call_chain` (3 `__noinline` subprograms × 64 rounds)。llvmbpf 0.74x exec, 0.62x code-size
- [x] **因果隔离 byte-recompose 时间量化** — load_byte_recompose 0.447x，geomean 0.660x，4/4 显著
- [x] **深度性能分析脚本** — `micro/archive/scripts/analyze_performance_deep.py`，6 维分析 + 报告
- [x] **exec-time 重跑** — 98/162 paired（14 unique），valid packet 后 geomean 0.514x，`97/98` kernel exec ≥ `20ns`
- [x] **stage-log 论文化重写** — abstract + takeaway + narrative prose
- [x] **文档全面同步** — stage-log / osdi-rigor-plan / micro-bench-status 三文档对齐
- [x] **Kernel JIT 改进建议文档** — `docs/kernel-jit-improvements.md`，3 个改进（byte-recompose / cmov / callee-saved），含指令序列和量化证据
- [x] **Related work 定位分析** — `docs/related-work-positioning.md`，K2/Merlin/EPSO 正交性 + 5 个 empirical study 差异化
- [x] **论文图表生成** — `micro/generate_figures.py`，6 张 PDF 图表于 `micro/results/figures/`
- [~] **LLVM pass 消融基础设施** — `--llvm-disable-pass` / `--llvm-log-passes` flag（实现中）

## 7. 迭代计划与进度

### Iteration 1 — 基础设施 ✅

- [x] perf_event_open 支持
- [x] 语料库 manifest + fetch 脚本
- [x] 论文骨架
- [x] RQ 摘要脚本

### Iteration 2 — 扩展 suite ✅（大部分完成）

- [x] 拆分 config 为 micro_pure_jit / micro_runtime / macro_corpus
- [x] 扩展 micro_staged_codegen 到 29-case family 结构（另含 `2` 个 packet-backed 对照 benchmark）
- [x] 拆分 pure-jit 和 runtime ABI 为 staged/map 模式
- [x] 增加 map/helper-like 和 verifier-style micro case
- [x] Bootstrap/gmean-oriented 摘要生成
- [x] 第一波真实语料库拉取

### Iteration 3 — 代码质量与归因（进行中）

**已完成：**
- [x] JIT dump / code-size 采集 — `--dump-jit` flag + `code_size` JSON 字段（RQ1.1 已关闭）
- [x] rdtsc 精确测量修正 — 消除 harness 开销，llvmbpf exec_ns 现在公平
- [x] LLVM 优化级别消融 — `--opt-level 0/1/2/3`，发现 O1=O2=O3
- [x] 指令级 JIT 分析 — `dump_all_jit.sh` + `micro/archive/scripts/analyze_jit.py`，byte-recompose / BMI / cmov / prologue / 依赖链
- [x] BCF 数据集获取 — 1588 个程序已下载到 `corpus/bcf/`
- [x] llvmbpf dummy helper 注册 — 注册 helper 3-220 为 no-op stub，解锁 Cilium/collected/inspektor-gadget 编译
- [x] ELF loader relocation 修复 — 跳过越界 relocation 而非 crash，支持带子程序的 ELF
- [x] suite rename — `config/micro_pure_jit.yaml` 的 `suite_name` 现为 `micro_staged_codegen`
- [x] packet-backed baselines — 新增 `simple_packet` 与 `fibonacci_iter_packet`
- [x] runtime order randomization — 同一 benchmark 内按 iteration 随机交错 `llvmbpf/kernel` 顺序并记录 `iteration_runtime_orders`
- [x] timing metadata — 结果 JSON 新增 `timing_source`、`wall_exec_ns`、`exec_cycles`、`tsc_freq_hz`
- [x] environment metadata — 结果 JSON `host` 块记录 git SHA、kernel cmdline、governor 等环境信息
- [x] perf scope modes — `--perf-scope full_repeat_raw|full_repeat_avg`
- [x] baseline subtraction fix — `baseline_adjustment` 仅在 `io_mode` 匹配时应用，避免 mixed-`io_mode` case 误扣基线

**BCF / real-world 批量结果（2026-03-07 current 4-repo slice）：**
- 当前 slice 扫描 `77` 个 artifacts、枚举 `949` 个程序
- llvmbpf compile-only inspect：`948/949` ok
  - Cilium: `904/904` ✅
  - libbpf-bootstrap: `24/24` ✅
  - inspektor-gadget: `11/11` ✅
  - collected: `9/10` ✅
- kernel load + inspect：`162/949` ok
- 双 runtime paired code-size：`162/949`（`36` 个 unique program name）
- 双 runtime exec-time：`98/162` paired instances（`14` 个 unique program name）；valid packet 后 geomean `0.514x`，`97/98` kernel exec ≥ `20ns`
- **当前瓶颈**：主要不再是 llvmbpf loader，而是 kernel verifier/load context 与 `BPF_PROG_TEST_RUN` hook 覆盖；llvmbpf 剩余失败已收敛到个别 jump-target / pseudo-instruction 兼容性问题

**TODO — 广度扩展（scale up to 500+ programs）：**
- [ ] **T3.1 BCF 真实程序 code-size 批量对比** — kernel 侧 load + bpf_prog_info 取 jited_prog_len；llvmbpf 侧 load_code + compile 取 native size。不需要执行。目标：500+ 程序的 code inflation ratio 分布图
- [x] **T3.2 BCF 静态特征提取** — `corpus/analyze_bytecode.py` 提取 1588 个程序的 insn count、helper call、BPF-to-BPF call、map 数。输出 `corpus/results/bytecode_features.json`
- [x] **T3.3 Helper 调用频率 Pareto 分析 (H4)** — Top-5 = 81.56%，H4 验证通过。详见 §6.1c

**TODO — 深度加强（rigorous root cause）：**
- [x] **T3.4 编译时间分析** — authoritative 31-case run geomean L/K = 3.394x。5/31 llvmbpf 更快，26/31 kernel 更快（其中 `branch_dense` 近似持平）。详见 §6.1e
- [x] **T3.5 统计严谨性补充** — authoritative 31-case run，30 iterations × 1000 repeats，bootstrap CI + paired Wilcoxon + BH correction。详见 §6.1b
**注**：PMU 相关任务保留为 supplementary material。当前只有 `18` 个 benchmark 有 kernel 侧 PMU 数据，且仅 `3` 个 benchmark 有双 runtime IPC；短执行窗口与 PMU 调度粒度不匹配使其不适合作为主因果证据。
- [x] **T3.6 时间域因素分解** — 4 个 byte-recompose 因果隔离 benchmark 已完成 authoritative run（30 iter × 1000 repeat），geomean 0.660x，4/4 显著。`load_byte_recompose` 0.447x 量化了 byte-recompose pattern 的时间惩罚（2.24x）。详见 `micro/results/causal_isolation_analysis.md`。剩余：其他模式（branch/prologue）的隔离 benchmark 尚未构建。
- [ ] **T3.7 LLVM Pass-level 消融** — 不只是 O0/O1/O2/O3，而是逐个 pass 启用（instcombine、GVN、RegAlloc、SimplifyCFG 等），识别对 BPF 最有价值的 pass
- [ ] **T3.8 Perf counter 相关性分析** — supplementary only：IPC/branch-miss/cache-miss vs exec ratio 的 Pearson/Spearman 相关系数矩阵
- [~] **T3.9 静态特征→优化收益预测模型 (RQ3.3)** — `micro/archive/scripts/analyze_performance_deep.py` 已完成初步 linear regression：3 个静态特征（insn_count, branch_count, code_ratio）预测 exec_ratio，R²=0.070，说明简单静态特征几乎无法预测运行时性能。详见 `micro/results/performance_deep_analysis.md`。剩余：随机森林 / 更多特征（helper count, loop depth）未尝试。

**TODO — 补充实验：**
- [ ] **T3.10 Spectre 2×2 实验** — 需重启 mitigations=off（低优先级）
- [ ] **T3.11 verifier/load/JIT 分段统计** — 接入 veristat 或 BPF_OBJ_GET_INFO_BY_FD 取 verified_insns
- [x] **T3.12 增加 helper-call micro case** — 当前 runtime suite 已扩展到 9 个 case；tail-call family 仍待补
- [x] **T3.13 扩展 llvmbpf ELF loader 支持 local subprogram call / multi-function ELF** — 真实程序 compile-only paired set 从 `105` 扩到 `162`，llvmbpf ok 从 `890` 提升到 `948`
- [x] **T3.14b BPF-to-BPF local call benchmark** — `bpf_call_chain`: llvmbpf `0.74x` exec, `0.62x` code-size (`3 __noinline subprograms × 64 rounds`)

**TODO — Actionable Insights（OSDI/SOSP 要求的"so what"）：**
- [ ] **T3.14 内核 JIT 改进建议** — 基于分析结果，提出具体 patch 级建议（如：添加 cmov 支持、优化 byte-recompose pattern、按需 callee-saved 保存）
- [ ] **T3.15 与 K2/Merlin/EPSO 的正交性分析** — 比较 bytecode 级优化（verifier 前）vs JIT 后端优化（native 级）的空间重叠度，证明互补性
- [ ] **T3.16 跨工具对比定位** — 将我们的 characterization 与 CoNEXT'25（网络应用性能）、"No Two Snowflakes"（运行时差异）、ETH Zurich（多核扩展）等已有实证工作对比，明确差异化

### Iteration 4 — 系统贡献与提交

- [ ] Helper inlining (S3) 实现 — UEOS 核心差异化
- [ ] 等价性验证 V1（BPF_PROG_TEST_RUN 差分测试）
- [ ] 端到端 Cilium/Katran 评估
- [ ] 多程序实验（RQ5）
- [ ] 图表生成脚本
- [ ] 论文写作

## 8. 数据采集方法总结

| 维度 | kernel 侧工具 | llvmbpf 侧工具 |
|------|-------------|---------------|
| 执行时间 | `exec_ns` + `timing_source=ktime` | `exec_ns` + `timing_source=rdtsc` |
| Wall exec 时间 | `wall_exec_ns` + `exec_cycles` + `tsc_freq_hz`（BPF_PROG_TEST_RUN 外层 rdtsc） | `wall_exec_ns` + `exec_cycles` + `tsc_freq_hz`（repeat 级 wall time） |
| 编译/加载时间 | bpf_object__open + bpf_object__load | llvmbpf load_code + compile |
| 硬件计数器 | perf_event_open (include_kernel=true), `--perf-scope full_repeat_raw|full_repeat_avg` | perf_event_open (user only), `--perf-scope full_repeat_raw|full_repeat_avg` |
| 代码尺寸 | bpf_prog_info.jited_prog_len / xlated_prog_len | get_compiled_code().size / insn_count × 8 |
| JIT 代码 dump | `--dump-jit` → .kernel.bin | `--dump-jit` → .llvmbpf.bin |
| 指令分析 | `objdump -D -b binary -m i386:x86-64` | 同左 |
| Verifier 统计 | veristat（待接入） | N/A |
| Phase 分段 | object_open / object_load / prog_run_wall / result_read | program_image / memory_prepare / input_stage / vm_load_code / jit_compile |
| 环境元数据 | `host.git_sha` / `kernel_cmdline` / `cpu_governor` / `turbo_state` / `perf_event_paranoid` | 同一结果 JSON `host` 块 |
| 优化级别 | N/A (kernel JIT 无选项) | `--opt-level 0/1/2/3` |

## 9. 添加新 benchmark 的流程

1. 创建 `micro/programs/<name>.bpf.c`：定义 input struct + `input_map` + `bench_*()` 函数 + 对应 `DEFINE_*_XDP_BENCH` 宏
2. 在 `micro/input_generators.py` 中添加生成器函数并注册到 `GENERATORS`
3. 在对应 `config/*.yaml` 中添加 benchmark 条目：`name`、`base_name`、`kernel_input_size`、`input_generator`、`expected_result`、category/family/level/hypothesis/tags

## 10. 参考文档

以下文档保留在 `docs/` 中作为背景参考，不再单独维护进度：

| 文件 | 角色 |
|------|------|
| `benchmark-framework-design.md` | 早期设计文档，定义了 RQ 子问题、7 个假设、两级架构、数据采集方法清单和测量环境详细信息 |
| `ebpf-bench-research-plan.md` | 文献综述，90+ 论文梳理，现有 benchmark 工具分析 |
| `references/linux-bench-framework-analysis.md` | Linux 内核 bench 框架架构分析 |
| `references/third-party-analysis.md` | 三个第三方 benchmark 项目详细分析 |
| `ebpf-characterization-paper-draft.md` | 论文草稿（随数据更新） |
