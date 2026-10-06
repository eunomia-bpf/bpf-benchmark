# UEOS 实证研究与 Benchmark 框架设计

> 本文档是 UEOS (Userspace eBPF Optimization Service) 阶段 1 的详细设计。
> 目标：系统量化 kernel JIT vs LLVM JIT 的性能差距，验证 7 个假设，为后续优化策略提供数据驱动的决策依据。

> 注：本文档主要描述 research questions、实验矩阵和测量方法。
> 当前实际 benchmark 执行架构、KVM/AWS 边界、构建容器与运行容器迁移方案，见
> [`docs/benchmark-runtime-architecture.md`](./benchmark-runtime-architecture.md)。

---

## 零、Research Questions (RQ)

本阶段的实证研究回答以下 5 组 research questions：

### RQ1: 内核 JIT 与 LLVM JIT 的性能差距有多大？

在 1,500+ 个真实 BPF 程序上系统量化 kernel JIT vs llvmbpf (-O3) 的差异。

- **RQ1.1 代码尺寸差距**：kernel JIT 生成的 native 指令数 vs llvmbpf -O3 的指令数差多少？代码膨胀比 (native_insn / ebpf_insn) 在两侧各是多少？
- **RQ1.2 执行时间差距**：在纯计算微基准和真实程序上，执行时间差距分别有多大？差距是否随程序复杂度变化？
- **RQ1.3 微架构质量差距**：IPC (instructions per cycle)、分支预测命中率、I-cache 命中率的差异如何？哪个微架构指标与性能差距相关性最强？

期望结果：代码尺寸差 15-40%，执行时间差 10-50%（依程序类型而异），IPC 差距 10-20%。

### RQ2: 差距的根因是什么？各因素贡献多大？

将总差距分解为可量化的独立因素。

- **RQ2.1 基础代码质量贡献**：寄存器分配、指令选择、指令调度这些基础编译质量因素合计贡献差距的百分之多少？
- **RQ2.2 Helper 调用开销贡献**：间接调用 (indirect call) + ABI 保存/恢复的 overhead 贡献差距的百分之多少？LLVM 内联 helper 后能消除多少？
- **RQ2.3 Map 访问模式贡献**：hash lookup 等 map 操作的间接调用开销贡献多少？是否存在类型特化优化机会？
- **RQ2.4 Spectre 缓解贡献**：retpoline / LFENCE / IBRS 等缓解措施对 kernel JIT 增加了多少开销？llvmbpf 通过消除间接跳转能免费避免多少？
- **RQ2.5 Verifier 约束贡献**：bpf_loop callback 模式 vs native loop、512B 栈限制、冗余边界检查，各自增加了多少运行时开销？

期望结果：RQ2.2 (helper) + RQ2.4 (Spectre) 是主要贡献因素（合计 > 50%）。

### RQ3: 哪类 BPF 程序从优化中受益最大？

分析程序特征与优化收益的关系，指导 UEOS 策略选择器设计。

- **RQ3.1 程序类别敏感性**：networking / tracing / security / scheduling 各类别的平均优化收益（speedup）是多少？哪类最大？
- **RQ3.2 Helper 调用分布**：真实程序中 top-N helper 函数占总调用的累计比例是多少？（验证 H4：top-5 占 80%+）
- **RQ3.3 优化预测模型**：哪些静态特征（指令数、helper 数、map 数、分支数）能最好地预测优化收益？是否能用简单回归模型指导策略选择？

期望结果：helper-heavy + map-heavy 的网络策略程序受益最大 → 直接指导策略选择器。

### RQ4: Spectre 缓解与编译质量是否存在非线性交互？

验证假设 H2：LLVM 内联 helper 后消除间接跳转 → retpoline 开销一并消失。

- **RQ4.1 交互效应量化**：2×2 factorial 实验 ({kernel JIT, llvmbpf} × {mitigations=on, off})，交互效应 (B-A)-(D-C) 有多大？是否统计显著？
- **RQ4.2 内联消除 Spectre 的程度**：对 helper-heavy 程序，内联后 retpoline/indirect-call 指令减少了多少？与执行时间改善的相关性？

期望结果：交互效应 > 0，即 "优化同时免费消除了部分安全开销"（论文亮点）。

### RQ5: 多程序场景下的优化空间如何变化？

验证 H5（联合优化超线性收益）和 H7（多程序超线性退化）。

- **RQ5.1 多程序退化曲线**：同一 hook 挂 1-64 个程序，每次触发的总延迟如何随 N 增长？N>8 后是否出现超线性退化？
- **RQ5.2 联合优化收益**：在 llvmbpf 中将 N 个程序联合编译（LTO）vs 独立编译，收益如何随 N 变化？N≥4 时是否出现超线性收益？

期望结果：N>8 退化超线性，联合优化在 N≥4 时收益超线性。

---

**RQ 覆盖链条**：RQ1（测量） → RQ2（归因） → RQ3（分类 & 预测） → RQ4（发现交互效应） → RQ5（扩展到多程序）。其中 RQ1-RQ2 是基础量化，RQ3 驱动策略选择，RQ4-RQ5 是反直觉发现（论文亮点）。

---

## 一、总体设计

### 1.1 设计原则

1. **两级 Benchmark**：micro-benchmark 量化单个因素（代码质量、helper 开销、Spectre 缓解），macro-benchmark 在真实程序和端到端场景验证影响
2. **复用已有基础设施**：不重新造轮子，最大化复用 llvmbpf、Linux bench、bpf_performance、veristat 等
3. **真实环境测量**：不做人为稳定化（禁 turbo、锁频率等），保持机器在正常运行状态，通过足够的重复次数和统计分析处理方差
4. **假设驱动**：每组实验对应一个明确的假设（H1-H7），用数据验证或证伪

### 1.2 两级架构

```
┌──────────────────────────────────────────────────────────────────┐
│              Macro-Benchmark：真实程序 & 端到端场景               │
│                                                                  │
│  ┌─────────────────────┐  ┌─────────────────────────────────┐   │
│  │ 真实程序矩阵         │  │ 端到端应用场景                   │   │
│  │ BCF 1,588 变体       │  │ Cilium netns / Katran pktgen   │   │
│  │ + 120 补充程序       │  │ Tetragon LSM / bpftrace        │   │
│  │ + 多程序场景 (H5/H7) │  │                                │   │
│  └─────────────────────┘  └─────────────────────────────────┘   │
│  → RQ1(全量), RQ3, RQ5                → RQ1(端到端)              │
├──────────────────────────────────────────────────────────────────┤
│              Micro-Benchmark：因素隔离 & 受控实验                 │
│                                                                  │
│  ┌─────────────────────┐  ┌─────────────────────────────────┐   │
│  │ 纯计算基线 (16 个)   │  │ 因素隔离实验                     │   │
│  │ 整数/内存/分支/哈希   │  │ F2 Helper调用  F3 Map访问       │   │
│  │                     │  │ F4 Spectre     F5 寄存器分配     │   │
│  │                     │  │ F6 分支布局    F7 Verifier约束   │   │
│  └─────────────────────┘  └─────────────────────────────────┘   │
│  → RQ1.1, RQ1.3                       → RQ2, RQ4                │
└──────────────────────────────────────────────────────────────────┘
```

---

## 二、可复用的基础设施清单

### 2.1 本仓库已有（bpf-benchmark）

| 组件 | 路径 | 能力 | 复用方式 |
|------|------|------|---------|
| 8 个纯计算 BPF 程序 | `user_bpf_benchmark/bpf_progs/*.bpf.c` | 覆盖整数运算、内存拷贝、字符串比较、跳转表 | Micro-bench 基线，扩展为更多类型 |
| 预编译 bytecode | `user_bpf_benchmark/bpf_progs/*.bpf.bin` | 可直接加载到 llvmbpf | 直接用 |
| Python benchmark runner | `user_bpf_benchmark/run_benchmark.py` | 多运行时对比、10 次重复、JSON 输出、图表生成 | 扩展为通用 harness |
| 绘图脚本 | `user_bpf_benchmark/example-output/plot.py` | 柱状图生成 | 复用并扩展 |
| Native baseline | `*.native` (编译好的 C 版本) | 性能上界参照 | 继续用作参照 |

### 2.2 llvmbpf（用户态 LLVM JIT 引擎）

| 组件 | 文件 | 能力 | 复用方式 |
|------|------|------|---------|
| eBPF→LLVM IR 翻译 | `src/compiler.cpp` (1376 行) | 全指令集支持 | 核心编译引擎 |
| LLVM -O3 优化 | `src/llvm_jit_context.cpp:optimizeModule()` | 完整 -O3 pipeline | S1 策略直接用 |
| AOT 编译 | `llvmbpf_vm::do_aot_compile()` | 生成 native ELF | 生成可对比的 native code |
| -emit-llvm | `cli/main.cpp` | 导出 LLVM IR 文本 | 用于 IR 质量分析 |
| helper 注册 | `register_external_function()` | 注册外部函数 | S3 helper 内联 |
| ELF 解析 | `cli/main.cpp` (libbpf) | 从 ELF 加载 BPF 程序 | 加载真实程序 |

**关键扩展点**：
- `optimizeModule()` 需要支持逐个 pass 启用/禁用（用于 pass 消融实验）
- `cli/main.cpp` 需要增加 benchmark 模式（输出执行时间、编译时间）
- 需要增加 IR dump 功能（优化前后 IR 对比）

### 2.3 Linux 内核 Benchmark 工具

| 组件 | 路径 | 能力 | 复用方式 |
|------|------|------|---------|
| bench_trigger | `tools/testing/selftests/bpf/benchs/bench_trigger.c` | kprobe/fentry/uprobe 等 ~40 种 attach 开销 | Micro-bench hook 触发基线 |
| bench_ringbufs | 同上 | ringbuf/perfbuf 吞吐量 | Micro-bench 事件传递 |
| bench_bloom_filter_map | 同上 | bloom filter map 性能 | Micro-bench map 类型对比 |
| bench_bpf_loop | 同上 | bpf_loop helper 性能 | Micro-bench helper 开销 |
| bpf_jit_disasm | `tools/bpf/bpf_jit_disasm.c` | 导出 kernel JIT 生成的 native code | 代码质量分析 |
| veristat | `tools/testing/selftests/bpf/veristat.c` | 验证时间/指令数/状态数统计 | 静态分析 |

### 2.4 第三方工具

| 工具 | 用途 | 复用方式 |
|------|------|---------|
| `microsoft/bpf_performance` | YAML 驱动的 60+ helper/map 测试 | Micro-bench helper/map 开销 baseline |
| `pchaigno/tail-call-bench` | 0-33 深度 tail call 链开销 | Micro-bench tail call + Spectre 交互 |
| `aspsk/bpf-bench` | 内核模块级 hash/hashmap cycle 精度 | 微架构精确测量 |
| `perf stat` | 硬件计数器（IPC/cache miss/分支预测） | 所有级别的微架构指标 |
| `bpf_jit_disasm` | kernel JIT 反汇编 | 代码质量对比 |
| `llvm-objdump` | llvmbpf 生成代码反汇编 | 代码质量对比 |

### 2.5 程序数据集来源

| 来源 | 源文件数 | 可用 .bpf.o 数 | 复杂度 | 获取方式 |
|------|---------|---------------|--------|---------|
| **BCF 数据集** | ~503 unique | **1,588 编译变体** | 混合 | `github.com/SunHao-0/BCF/tree/main/bpf-progs`，直接可用 |
| **Linux selftests progs** | **~916** | ~916 (编译后) | 低-中 | `tools/testing/selftests/bpf/progs/` |
| **Cilium datapath** | 9 | 6-9 | **极高** | `cilium/cilium` repo `bpf/` |
| **Calico datapath** | 10 + 51 头文件 | **100s** | 高 | `projectcalico/calico` → `felix/bpf-gpl/` |
| **bcc libbpf-tools** | **57** | 57 | 中 | `iovisor/bcc` → `libbpf-tools/*.bpf.c` |
| **Tetragon sensors** | **23** | 23 | 高 | `cilium/tetragon` → `bpf/process/` |
| **sched_ext 调度器** | ~8 | ~8 | 中-高 | `sched-ext/scx` |
| **Katran** | ~5 | ~5 | 中 | `facebookincubator/katran` |
| **本仓库** | 8 | 8 | 低 | 直接用 + 扩展 |

**BCF 数据集详细构成**（最重要的直接可用数据源）：

| 来源 | 独立对象名 | 编译变体数 | 方法 |
|------|-----------|-----------|------|
| Calico | 492 | 1,476 | 3 个 clang 版本 (15/20/21) |
| Cilium | 6 | 42 | 8 个 clang 版本 (14-21), -O1 |
| bpf-examples | 2 | 42 | 多 clang 版本 × 优化级别 |
| Inspektor Gadget | 1 | 11 | 多 clang 版本 × 优化级别 |
| BCC (ksnoop) | 1 | 8 | clang-20/21 × O1/O2/O3/Os |
| 手动收集 | 9 | 9 | xdp_synproxy, system_monitor 等 |
| **合计** | **~503** | **1,588** | |

> 注：BCF 的变体生成策略（同一源程序 × 多 clang 版本 × 多优化级别）天然适合我们的实验 — 可以同时测量编译器版本和优化级别对 JIT 差距的影响。

---

## 三、数据采集方法与工具

### 3.1 内核侧数据采集

#### 3.1.1 BPF_PROG_TEST_RUN (bpf syscall)

**原理**：通过 `bpf(BPF_PROG_TEST_RUN)` 系统调用在内核中执行已加载的 BPF 程序，返回执行耗时。

**提供的指标**：
- `duration`：单次执行耗时（纳秒）
- `retval`：程序返回值（用于正确性验证）
- 支持 `repeat` 参数批量执行

**支持的 prog type**：XDP, SCHED_CLS/ACT, CGROUP_SKB, SK_LOOKUP, RAW_TRACEPOINT, SYSCALL, FLOW_DISSECTOR 等。注意 KPROBE/TRACEPOINT/LSM 等 tracing 类型不支持。

**优点**：零额外开销、内核原生支持、结果可靠
**限制**：不支持所有 prog type；不提供硬件计数器；不测量实际 hook 触发开销
**集成方式**：通过 libbpf 的 `bpf_prog_test_run_opts()` 调用

#### 3.1.2 BPF_ENABLE_STATS (内核内置统计)

**原理**：`bpf(BPF_ENABLE_STATS)` 打开后，内核为每个 BPF 程序累计记录 `run_time_ns` 和 `run_cnt`。

**提供的指标**：
- `run_time_ns`：累计执行时间
- `run_cnt`：累计执行次数
- 平均每次执行时间 = `run_time_ns / run_cnt`

**查看方式**：
```bash
sudo sysctl kernel.bpf_stats_enabled=1
sudo bpftool prog show  # 输出中会包含 run_time_ns 和 run_cnt
```

**优点**：测量真实 hook 触发路径（包括 tracing 类型）；可用于所有 prog type
**限制**：有轻微开销（每次执行多一次时间戳读取）；只有时间和次数，无硬件计数器
**适用场景**：Macro-bench 中测量真实挂载的 BPF 程序的执行开销

#### 3.1.3 bpftool prog profile (硬件计数器)

**原理**：通过 fentry/fexit BPF trampoline 附着到目标 BPF 程序，在进入和退出时读取硬件计数器。

**提供的指标**（可选组合）：
- `cycles`：CPU 周期数
- `instructions`：指令数（计算 IPC = instructions/cycles）
- `llc_misses`：Last-Level Cache miss
- `itlb_misses`：指令 TLB miss
- `dtlb_misses`：数据 TLB miss

**使用方式**：
```bash
sudo bpftool prog profile id <ID> cycles instructions llc_misses duration
# Ctrl-C 终止，输出累计统计
```

**优点**：精确到单个 BPF 程序粒度；不影响其他程序；几乎零开销（BPF trampoline）
**限制**：需要目标程序有 BTF 信息；不支持所有 prog type（与 fentry attach 相关）
**适用场景**：RQ1.3 微架构质量对比，获取 IPC/cache miss 等指标

#### 3.1.4 bpf_jit_disasm (JIT 代码导出)

**原理**：从 `/proc/kallsyms` 和内核内存导出 BPF JIT 编译后的 native code。

**提供的指标**：
- Native 指令序列（可用 objdump 反汇编）
- 代码尺寸（字节数）
- Spectre 相关指令数（retpoline, LFENCE, indirect call）

**使用方式**：
```bash
# 需要 echo 2 > /proc/sys/net/core/bpf_jit_harden  (或用 bpftool)
sudo bpftool prog dump jited id <ID> > kernel_jit.bin
sudo bpftool prog dump jited id <ID> opcodes  # 带操作码
```

**适用场景**：RQ1.1 代码尺寸对比、RQ2.4 Spectre 指令统计

#### 3.1.5 veristat (验证统计)

**原理**：加载 BPF 程序但不执行，收集 verifier 的统计信息。

**提供的指标**：
- `insns`：验证器处理的指令数
- `states`：验证器探索的状态数
- `peak_states`：峰值状态数
- 验证耗时

**使用方式**：
```bash
veristat prog.bpf.o  # 输出每个 section 的验证统计
veristat -C prog_v1.bpf.o prog_v2.bpf.o  # 两个版本对比
```

**适用场景**：静态复杂度分析、verifier 开销量化

### 3.2 用户态（llvmbpf）数据采集

#### 3.2.1 clock_gettime / CLOCK_MONOTONIC

**原理**：用户态高精度时钟，测量 llvmbpf 编译和执行时间。

**精度**：~20-50ns 开销，对 μs 级别测量足够
**实现**：
```cpp
struct timespec start, end;
clock_gettime(CLOCK_MONOTONIC, &start);
uint64_t result;
vm.exec(mem, mem_len, result);
clock_gettime(CLOCK_MONOTONIC, &end);
uint64_t elapsed_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
```

#### 3.2.2 perf_event_open (硬件计数器)

**原理**：通过系统调用打开硬件性能计数器，在用户态代码段前后读取。

**可用计数器**（本机验证可用）：
- `cycles`, `instructions` → IPC
- `branch-instructions`, `branch-misses` → 分支预测
- `cache-references`, `cache-misses` → 缓存
- `ref-cycles` → 不受频率变化影响的参考周期

**实现方式**：在 llvmbpf_bench_runner 中封装 `perf_event_open()` 调用，JIT 执行前后读取计数器。
```c
// perf_event_open wrapper
int fd = perf_event_open(&attr, 0, -1, -1, 0);
ioctl(fd, PERF_EVENT_IOC_RESET, 0);
ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
// ... execute BPF program ...
ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
read(fd, &count, sizeof(count));
```

**优点**：用户态直接获取硬件计数器；可同时测量多个事件（group）；精度高
**限制**：需要 `perf_event_paranoid ≤ 2`（或 sudo）；多个计数器可能涉及多路复用

#### 3.2.3 LLVM Pass 统计

**原理**：在 LLVM 优化 pipeline 中注入统计，测量每个 pass 的效果。

**可获取的信息**：
- 优化前/后 IR 指令数（IR dump + `wc -l`）
- 每个 pass 的运行时间（LLVM `TimePassesIsEnabled`）
- 优化前/后 native 代码尺寸
- 寄存器溢出数 (spill count，从 LLVM MachineFunction stats)

**实现**：修改 llvmbpf 的 `optimizeModule()` 以支持 pass-by-pass 统计。

#### 3.2.4 llvm-objdump (用户态代码质量分析)

**提供的指标**：
- 反汇编 native 代码（与 kernel JIT 代码对比）
- 指令数、代码尺寸
- 寄存器使用模式（spill to stack 的频率）
- 分支指令分布

**使用方式**：
```bash
# llvmbpf AOT 编译后
llvm-objdump -d program.o  # 反汇编
llvm-objdump -d program.o | grep -c "push\|mov.*rsp" # 粗略 spill count
```

### 3.3 数据采集综合方案

| RQ | 内核侧工具 | 用户态工具 | 采集指标 |
|----|-----------|-----------|---------|
| RQ1.1 代码尺寸 | `bpftool prog dump jited` | `llvm-objdump` | native 指令数, 代码字节数, 代码膨胀比 |
| RQ1.2 执行时间 | `BPF_PROG_TEST_RUN` | `clock_gettime` | 执行时间 (ns), 编译时间 |
| RQ1.3 微架构 | `bpftool prog profile` | `perf_event_open` | IPC, branch-misses, cache-misses |
| RQ2.1 代码质量 | — | LLVM pass 统计, `llvm-objdump` | spill count, 指令选择模式 |
| RQ2.2 Helper | `BPF_PROG_TEST_RUN` | `clock_gettime` | 有/无 helper 的执行时间差 |
| RQ2.3 Map | `BPF_PROG_TEST_RUN` | `clock_gettime` | 不同 map 类型的访问时间 |
| RQ2.4 Spectre | `BPF_PROG_TEST_RUN` (重启切换) | `bpftool prog dump jited` | mitigations on/off 时间差, Spectre 指令数 |
| RQ2.5 Verifier | `BPF_PROG_TEST_RUN` | `clock_gettime` | bpf_loop vs native loop 时间差 |
| RQ3.x 分类 | veristat (静态特征) | bytecode 分析器 | 静态特征向量 + 收益标签 |
| RQ4.x Spectre | 2×2 factorial 全组 | — | 交互效应 |
| RQ5.x 多程序 | `BPF_ENABLE_STATS` | — | N 程序总延迟, 联合 vs 独立 |

### 3.4 每个 BPF 程序需要采集的静态特征

在编译/加载前通过字节码静态分析提取：

```json
{
  "program_id": "cilium_bpf_lxc_from_container",
  "source": "cilium",
  "category": "networking",
  "prog_type": "BPF_PROG_TYPE_SCHED_CLS",

  "static_features": {
    "insn_count": 4096,
    "basic_block_count": 128,
    "branch_count": 64,
    "backward_branch_count": 0,
    "helper_calls": {
      "total": 32,
      "unique_helpers": 8,
      "by_helper": {
        "bpf_map_lookup_elem": 12,
        "bpf_map_update_elem": 4,
        "bpf_probe_read_kernel": 6
      }
    },
    "map_access": {
      "total_lookups": 16,
      "unique_maps": 5,
      "map_types": ["BPF_MAP_TYPE_HASH", "BPF_MAP_TYPE_LRU_HASH"]
    },
    "tail_calls": 3,
    "stack_usage_bytes": 256,
    "alu64_ratio": 0.45,
    "memory_access_count": 96
  }
}
```

### 3.5 每个程序×编译配置需要采集的运行时指标

```json
{
  "program_id": "cilium_bpf_lxc_from_container",
  "compiler": "kernel_jit",
  "kernel_version": "6.15.11",
  "spectre_mitigations": true,

  "compilation_metrics": {
    "compile_time_ns": 125000,
    "native_code_size_bytes": 8192,
    "native_insn_count": 1024,
    "code_inflation_ratio": 0.25,
    "spectre_insn_count": 32,
    "spectre_insn_ratio": 0.031
  },

  "execution_metrics": {
    "runs": 10000,
    "exec_time_ns": {
      "mean": 450, "median": 440, "p99": 620,
      "stddev": 35, "min": 410, "max": 890
    },
    "hw_counters": {
      "instructions": 1200, "cycles": 450, "ipc": 2.67,
      "branch_misses": 2, "branch_miss_rate": 0.031,
      "l1i_cache_misses": 1, "llc_cache_misses": 0
    }
  },

  "llvm_specific": {
    "ir_insn_count_before_opt": 512,
    "ir_insn_count_after_opt": 380,
    "optimization_ratio": 0.257,
    "passes_applied": ["instcombine", "gvn", "licm", "simplifycfg"]
  }
}
```

### 3.6 测量环境

**硬件**：唯一可用机器，所有测量均在此机器完成。

```
Machine:  Intel Core Ultra 9 285K (Arrow Lake-S)
Cores:    24 cores (P-core × 8 + E-core × 16), no HyperThreading
Freq:     800MHz - 5.8GHz, governor: powersave (保持默认)
Cache:    L1d 768K, L1i 1.3M, L2 40M, L3 36M
RAM:      128GB DDR5, 单 NUMA node
Kernel:   6.15.11-061511-generic (PREEMPT_DYNAMIC)
OS:       Ubuntu 24.04.3 LTS
Spectre:  Enhanced IBRS + IBPB conditional (mitigations ON by default)
BPF:      CONFIG_BPF_JIT=y, CONFIG_BPF_SYSCALL=y, BTF enabled
          unprivileged_bpf_disabled=2 (需要 sudo)
```

**已安装工具链**：
- clang: 15, 17, 18, 20
- llvm-dev: 14, 15, 17, 18, 20
- libelf-dev, libzstd-dev
- bpftool: /usr/local/sbin/bpftool
- Docker + qemu-aarch64-static (可选 ARM 代码质量静态分析)

**测量策略**：
- 不做人为环境稳定化（不锁频、不禁 turbo、不关后台服务），模拟真实运行环境
- 所有 benchmark 绑定 P-core（`taskset -c 0-7`），避免 P-core/E-core 异构影响一致性
- 通过足够的重复次数 + 统计分析 (中位数、95% CI、方差分析) 处理噪声
- 记录环境信息用于可复现性（内核版本、CPU governor、Spectre 状态、负载等）

**重复次数**：
- Micro-benchmark：每个配置 10,000 次执行，取中位数 + 95% CI
- Macro-benchmark 真实程序：每个配置 1,000 次执行
- Macro-benchmark 端到端：每个配置 5 次完整运行，每次 60 秒

**Spectre on/off 切换（RQ4 专用）**：
```bash
# 两次启动：
# 1. 默认 (mitigations=auto) → 运行全部 benchmark → 保存结果
# 2. 修改 GRUB: GRUB_CMDLINE_LINUX="mitigations=off" → 重启 → 运行相同 benchmark
# 只需重启 2 次（批量运行）
```

**ARM 测量方案（可选扩展）**：
```bash
# LLVM cross-compile 只看生成代码质量（不执行）
# 统计指令数/代码尺寸/寄存器溢出等静态指标
./llvmbpf_bench_runner prog.bpf.o --target aarch64 --emit-asm --no-exec
# 论文中标注 "ARM 代码质量分析基于 cross-compile 静态指标"
```

---

## 四、Micro-Benchmark

### 4.1 目的

用受控实验隔离影响 JIT 差距的具体因素。包含两部分：
- **纯计算基线**：隔离 helper/map/Spectre 等外部因素，纯粹比较编译器代码质量
- **因素隔离**：逐个测量 helper 调用、map 访问、Spectre 缓解、寄存器分配、分支布局、verifier 约束的独立贡献

### 4.2 纯计算基线（已有 8 个 + 新增 8 个）

**已有用例（直接复用）**：

| 程序 | 计算特征 | 测试目标 |
|------|---------|---------|
| `simple.bpf.c` | 直接返回 | 函数调用 overhead 基线 |
| `memory_a_plus_b.bpf.c` | 内存读取 + 加法 | 内存访问 + ALU |
| `log2_int.bpf.c` | 8192 次 64 位 log2 | 整数运算 + 分支 |
| `prime.bpf.c` | 素数筛至 10^4 | 嵌套循环 + 除法 + 分支 |
| `memcpy.bpf.c` | 1MB 内存拷贝 | 内存带宽 |
| `strcmp_fail.bpf.c` | 字符串比较（早退出） | 内存 + 条件分支 |
| `strcmp_full.bpf.c` | 字符串比较（全匹配） | 内存 + 循环 |
| `switch.bpf.c` | 多路跳转 | 跳转表 / 二分查找 |

**需要新增的用例**：

| 程序 | 计算特征 | 测试目标 | LLVM 优化机会 |
|------|---------|---------|-------------|
| `hash_crc32.bpf.c` | CRC32 哈希 | 位运算 + 查表 | 循环展开、常量折叠 |
| `sort_bubble.bpf.c` | 冒泡排序 256 元素 | 嵌套循环 + 比较交换 | 循环优化、分支预测 |
| `binary_search.bpf.c` | 有序数组二分查找 | 条件分支密集 | 分支布局优化 |
| `bitcount.bpf.c` | popcount 1M 整数 | 位运算 | 内建函数替换 |
| `checksum.bpf.c` | IP checksum 计算 | 加法 + 位运算 | 向量化、循环展开 |
| `lpm_lookup.bpf.c` | 最长前缀匹配模拟 | 位运算 + 分支 | 分支消除 |
| `packet_parse.bpf.c` | 模拟 packet header 解析 | 结构体访问 + 边界检查 | 冗余检查消除 |
| `ringbuf_reserve.bpf.c` | 模拟 ringbuf 写操作 | 内存屏障 + 指针运算 | 屏障间指令调度 |

**测量方法**：

```python
# 伪代码：纯计算 micro-benchmark
for program in ALL_16_PROGRAMS:
    bytecode = load_bytecode(program)

    # --- Kernel JIT ---
    kernel_fd = bpf_prog_load(bytecode, BPF_PROG_TYPE_XDP)
    for i in range(10000):
        time = bpf_prog_test_run(kernel_fd, input_data, repeat=1)
        record("kernel_jit", program, time)
    kernel_native = bpftool_prog_dump_jited(kernel_fd)
    analyze_code_quality(kernel_native)

    # --- llvmbpf -O3 ---
    vm = llvmbpf_vm()
    vm.load_code(bytecode)
    func = vm.compile()  # -O3
    for i in range(10000):
        time = measure_exec(func, input_data)  # clock_gettime + perf_event_open
        record("llvmbpf_O3", program, time)

    # --- llvmbpf -O0 (隔离 LLVM 优化贡献) ---
    vm2 = llvmbpf_vm(opt_level=0)
    vm2.load_code(bytecode)
    func2 = vm2.compile()
    for i in range(10000):
        time = measure_exec(func2, input_data)
        record("llvmbpf_O0", program, time)
```

**期望产出**：
1. **代码膨胀矩阵**：16 程序 × {kernel JIT, llvmbpf -O0/-O3, native C} → RQ1.1
2. **执行时间矩阵**：同上，中位数 + 95% CI → RQ1.2
3. **微架构指标矩阵**：IPC, branch-misses, cache-misses → RQ1.3
4. **LLVM pass 消融**：各 pass 的独立贡献 → RQ2.1

### 4.3 因素隔离实验

#### F2: Helper 调用开销 (→ RQ2.2)

**目标**：量化每个 helper 调用的 overhead，以及 LLVM 内联 helper 后的收益。

| 用例 | Helper | N | 测试目标 |
|------|--------|---|---------|
| `f2_ktime_1` | `bpf_ktime_get_ns` | 1 | 单次调用 baseline |
| `f2_ktime_100` | `bpf_ktime_get_ns` | 100 | 批量调用 |
| `f2_map_lookup_1` | `bpf_map_lookup_elem` | 1 | 最常见 helper |
| `f2_map_lookup_100` | `bpf_map_lookup_elem` | 100 | 批量查找 |
| `f2_probe_read_1` | `bpf_probe_read_kernel` | 1 | 内存读取 helper |
| `f2_mixed_helpers` | 混合 5 种 | 各 20 次 | 真实调用模式 |

**llvmbpf 侧测量**：不内联 vs 内联 helper 的执行时间差 → 内联后 LLVM 做的额外优化（死代码消除、常量传播穿越调用边界）。

#### F3: Map 访问模式 (→ RQ2.3)

| 用例 | Map 类型 | 操作 | 测试目标 |
|------|----------|------|---------|
| `f3_hash_lookup` | HASH | lookup × 1000 | Hash map 查找开销 |
| `f3_array_lookup` | ARRAY | lookup × 1000 | Array map 查找开销 |
| `f3_percpu_hash` | PERCPU_HASH | lookup × 1000 | Per-CPU 变体 |
| `f3_lru_hash` | LRU_HASH | lookup × 1000 | LRU 淘汰 |
| `f3_hash_update` | HASH | update × 1000 | 写操作 |
| `f3_mixed_ops` | HASH + ARRAY | lookup+update 交替 | 混合访问模式 |

> 注：用户态 llvmbpf 测量需要用 mock map 实现；kernel 侧用真实 map。需要确保 mock map 的 overhead 可校准。

#### F4: Spectre 缓解交互 (→ RQ4)

**2×2 factorial 实验设计**：

| 配置 | Compiler | Spectre | 预期 |
|------|----------|---------|------|
| A | Kernel JIT | OFF (`mitigations=off`) | Kernel baseline |
| B | Kernel JIT | ON (default) | A + Spectre overhead |
| C | llvmbpf -O3 | OFF | LLVM baseline |
| D | llvmbpf -O3 + inline | ON (模拟) | C + 部分 Spectre，但因内联消除了部分 |

**关键测量**：
- `Spectre_overhead_kernel = B - A`
- `Spectre_overhead_llvmbpf = D - C`
- `Interaction_effect = (B - A) - (D - C)`
  - 如果 > 0：Spectre 缓解对 kernel JIT 影响更大（因为 LLVM 消除了部分间接跳转）

**用例**：选择 helper 调用密集的程序（每个 helper call 在 kernel JIT 中都是 indirect call → retpoline）。需要两次重启切换 `mitigations=on/off`。

#### F5: 寄存器分配 (→ RQ2.1)

| 用例 | 寄存器压力 | 预期差异 |
|------|-----------|---------|
| `f5_low_pressure` | 3 个局部变量 | 小差异（kernel 11 个 reg 够用） |
| `f5_medium_pressure` | 8 个局部变量 | 中等差异 |
| `f5_high_pressure` | 15+ 个局部变量 | 大差异（kernel 需大量 spill） |

在 LLVM 中分别用 RegAllocFast（模拟 kernel JIT）和 RegAllocGreedy（默认 -O3），比较溢出到栈的次数。

#### F6: 分支布局 (→ RQ2.1)

```c
// f6_branch_layout.bpf.c — 90% 走 fast path, 10% 走 slow path
unsigned long long bpf_main(void *ctx) {
    unsigned long long *data = (unsigned long long *)ctx;
    unsigned long long result = 0;
    for (int i = 0; i < 1000; i++) {
        if (data[i] < 900) {
            result += data[i];
        } else {
            result += data[i] * data[i];
            result ^= data[i] >> 3;
        }
    }
    return result;
}
```

kernel JIT：分支按源代码顺序排列。LLVM -O3：优化 basic block 布局。用 `perf_event_open` 的 `branch-misses` 计数器量化差异。

#### F7: Verifier 约束 (→ RQ2.5)

| 用例 | Verifier 约束 | 对比 |
|------|-------------|------|
| `f7_bpf_loop` | 使用 `bpf_loop(N, callback, ...)` | vs llvmbpf 中恢复为 native for loop |
| `f7_stack_512` | 栈使用接近 512B | vs llvmbpf 允许更大栈 |
| `f7_bounds_check` | 每次 ctx 访问都有边界检查 | vs llvmbpf 合并冗余检查 |

---

## 五、Macro-Benchmark

### 5.1 目的

在真实 BPF 程序和端到端场景中测量优化的实际影响。回答 "差距在真实场景中有多大？" 和 "用户能感受到多少改进？"

### 5.2 真实程序矩阵 (→ RQ1, RQ3)

#### 5.2.1 数据集构建

**第一批：BCF 数据集（1,588 个编译变体，直接可用）**

从 `github.com/SunHao-0/BCF/tree/main/bpf-progs` 下载。503 个独立对象名、1,588 个编译变体（同一源程序 × clang-14~21 × -O1/-O2/-O3/-Os）。

**第二批：补充真实程序（~120 个）**

| 来源 | 程序 | Prog Type | 数量 |
|------|------|-----------|------|
| **bcc libbpf-tools** | execsnoop, biolatency, tcpconnect, ... | KPROBE/TP | **57** |
| **Tetragon** | bpf_generic_kprobe, bpf_generic_lsm_core, ... | KPROBE/LSM/TP | **23** |
| **Cilium** (补充) | bpf_sock, bpf_wireguard | SOCK_OPS/SCHED_CLS | 2 |
| **Katran** | xdp_root, balancer_kern, healthchecking_kern | XDP | 3 |
| **sched_ext** | scx_rusty, scx_lavd, scx_bpfland | STRUCT_OPS | 3 |
| **Linux selftests** (精选) | test_cls_redirect, xdp_redirect_map, ... | 各种 | ~30 |
| **合计** | | | **~120** |

**第三批（可选）：Linux selftests 全量** — ~916 个 BPF 源文件作为 "长尾" 数据。

#### 5.2.2 批量测量流程

```bash
#!/bin/bash
# macro_benchmark.sh — 真实程序批量测量

for prog in $DATASET_DIR/*.bpf.o; do
    name=$(basename $prog .bpf.o)

    # 1. 静态特征分析
    python3 analyze_bytecode.py $prog > $RESULTS/$name.static.json

    # 2. Kernel JIT: BPF_PROG_TEST_RUN
    sudo ./kernel_bench_runner $prog \
        --runs 1000 \
        --perf-counters instructions,cycles,branch-misses \
        --output $RESULTS/$name.kernel.json

    # 3. Kernel JIT 代码导出
    sudo bpftool prog dump jited id $ID > $RESULTS/$name.kernel.asm

    # 4. llvmbpf -O3
    ./llvmbpf_bench_runner $prog \
        --opt-level 3 --runs 1000 \
        --emit-ir $RESULTS/$name.llvm.ll \
        --emit-asm $RESULTS/$name.llvm.asm \
        --output $RESULTS/$name.llvmbpf_O3.json

    # 5. llvmbpf -O0 (隔离优化贡献)
    ./llvmbpf_bench_runner $prog \
        --opt-level 0 --runs 1000 \
        --output $RESULTS/$name.llvmbpf_O0.json

    # 6. llvmbpf -O3 + helper 内联
    ./llvmbpf_bench_runner $prog \
        --opt-level 3 --inline-helpers --runs 1000 \
        --output $RESULTS/$name.llvmbpf_O3_inline.json
done

python3 analyze_results.py $RESULTS/ --output $RESULTS/summary.json
```

#### 5.2.3 分析维度

**按程序类别分组** (→ RQ3.1)：
```
category = {networking, tracing, security, scheduling, storage}
for each category:
    avg_speedup = mean(llvmbpf_O3_time / kernel_jit_time for prog in category)
    → H1 预测: networking 的 avg_speedup > computing 的 avg_speedup
```

**Helper 调用频率分布** (→ RQ3.2)：
```
绘制 Pareto 图: helper × 累计调用占比
→ H4 预测: top-5 helpers 占总调用的 80%+
```

**优化预测模型** (→ RQ3.3)：
```
x = (helper_call_count, map_access_count, branch_count, insn_count)
y = speedup_ratio (llvmbpf_O3 / kernel_jit)
用线性回归/随机森林分析: 哪些静态特征最能预测优化收益？
→ 直接驱动 Strategy Composer 设计
```

### 5.3 多程序场景 (→ RQ5)

**H7 验证：多程序退化曲线**

```bash
# 在同一 hook 上挂 N 个 BPF 程序
for N in 1 2 4 8 16 32 64; do
    ./multi_prog_bench --hook kprobe:do_sys_openat2 --count $N --runs 10000
    # 输出: 每次 hook 触发的总延迟
done
# 预期: N>8 后出现超线性增长
```

**H5 验证：联合优化收益**

```bash
# llvmbpf 中分别独立编译 vs 联合编译 (LTO)
for N in 2 4 8 16; do
    programs = select_N_programs(cilium_programs, N)
    # 独立编译 → total_time_independent
    # 联合编译 (LTO) → total_time_joint
    speedup = total_time_independent / total_time_joint
    # 预期: speedup > 1.0 且随 N 增长
done
```

### 5.4 端到端应用场景 (→ RQ1 端到端)

#### 场景 1：Cilium 网络策略 — 单机 netns

```bash
# 2 个 network namespace，通过 veth pair 连接
sudo ip netns add ns1 && sudo ip netns add ns2
sudo ip link add veth1 type veth peer name veth2
sudo ip link set veth1 netns ns1 && sudo ip link set veth2 netns ns2
# 挂载 Cilium BPF 程序到 TC ingress
sudo ip netns exec ns1 tc filter add dev veth1 ingress bpf da obj cilium_bpf_lxc.o sec from-container
```

**工作负载**：`iperf3` 吞吐量 + `netperf` TCP_RR 延迟
**测量**：Baseline (kernel JIT) vs Optimized (llvmbpf -O3 编译) → 吞吐量 (Gbps), 延迟 (P50/P99 μs), CPU 利用率

#### 场景 2：XDP 负载均衡 (Katran) — 单机 pktgen

```bash
# veth pair + 内核 pktgen 模块
sudo ip link add xdp0 type veth peer name pktgen0
sudo ip link set dev xdp0 xdp obj katran_balancer.o sec xdp
# 用 pktgen 发 64 字节 UDP 包（最大 pps 测试）
```

**测量**：pps on single P-core, 多核扩展曲线 (1/2/4/8 P-cores)

#### 场景 3：Tetragon 安全监控

**工作负载**：`sysbench` CPU/fileio + `redis-benchmark` + `nginx`
**测量**：被监控应用的 overhead（吞吐量下降 %, 延迟增加 %）→ 优化前后对比

#### 场景 4：bpftrace 持续 Profiling

**工作负载**：运行 CPU 密集型应用（编译 Linux 内核）+ bpftrace 持续 profiling
**测量**：被 profiling 应用的 slowdown → 优化后 slowdown 变化

---

## 六、需要开发的工具

### 6.1 bytecode 静态分析器

```
工具名: ebpf_analyzer
输入: eBPF ELF 文件 或 .bpf.bin
输出: JSON 格式的静态特征（见 3.4 节）
实现: Python (pyelftools) 或 C (libbpf)
```

### 6.2 llvmbpf benchmark runner

```
工具名: llvmbpf_bench_runner
输入: eBPF ELF 文件 + 配置选项
输出: JSON 格式的编译/执行指标（见 3.5 节）
功能:
  - 支持 --opt-level 0/1/2/3
  - 支持 --emit-ir (导出优化前后 IR)
  - 支持 --emit-asm (导出 native code)
  - 支持 --inline-helpers (启用 S3)
  - 支持 --runs N (重复执行次数)
  - 支持 --perf-counters (硬件计数器, 通过 perf_event_open)
  - 支持 --pass-list (指定启用的 LLVM pass, 用于消融实验)
实现: C++ (基于 llvmbpf)

需要对 llvmbpf 的修改:
  1. optimizeModule() 支持可配置优化级别
  2. optimizeModule() 支持 pass 消融（逐个启用/禁用）
  3. 新增 dump_ir_before/after() 接口
  4. compile() 返回编译时间统计
```

### 6.3 kernel benchmark runner

```
工具名: kernel_bench_runner
输入: eBPF ELF 文件 + 配置选项
输出: JSON 格式的执行指标
功能:
  - BPF_PROG_LOAD 加载 + BPF_PROG_TEST_RUN 执行
  - 记录验证时间、JIT 编译时间、执行时间
  - 通过 perf_event_open 收集硬件计数器
  - 导出 kernel JIT 生成的 native code
实现: C (libbpf)
```

### 6.4 结果分析与可视化

```
工具名: analyze_results.py
输出:
  - 性能差距矩阵 (heatmap)
  - 假设验证结果 (统计检验 + 置信区间)
  - 因素分解瀑布图 (waterfall chart)
  - Pareto 图 (helper 调用频率)
  - 多程序扩展曲线 (N vs overhead)
  - 消融研究柱状图 (strategy ablation)
实现: Python (matplotlib + seaborn + scipy.stats)
```

---

## 七、实施时间线

```
第 1-2 周: 工具开发
  ├── ebpf_analyzer (bytecode 静态分析)
  ├── 扩展 llvmbpf（可配置优化级别 + IR dump + pass 消融）
  ├── llvmbpf_bench_runner
  └── kernel_bench_runner

第 3-4 周: Micro-Benchmark
  ├── 编写纯计算新增用例 (8 个) + F2-F7 因素隔离用例
  ├── 运行全矩阵（16 纯计算 × 5 配置 + 6 组因素隔离）
  └── 初步分析：RQ1.1-1.3, RQ2.1-2.5

第 5-6 周: Macro-Benchmark 真实程序
  ├── 构建 BCF 数据集 + 补充程序
  ├── 批量运行 1,500+ 程序 × {kernel JIT, llvmbpf -O0/-O3, llvmbpf+inline}
  ├── 静态特征提取 + 分类分析
  └── H1/H4 假设验证：RQ3.1-3.3

第 7-8 周: Macro-Benchmark 端到端 + 补充实验
  ├── 多程序实验 (H5/H7)：RQ5.1-5.2
  ├── Cilium/Katran/Tetragon 端到端测量
  ├── Spectre 交互实验（2 次重启）：RQ4.1-4.2
  └── 综合分析 + 因素分解

第 9-10 周: 分析与报告
  ├── 可视化全部结果
  ├── 统计检验（假设验证的 p-value + 置信区间）
  └── 撰写论文
```

---

## 八、风险与缓解

| 风险 | 影响 | 缓解措施 |
|------|------|---------|
| kernel JIT vs llvmbpf 差距太小（< 10%） | 论文价值降低 | 聚焦 helper-heavy 程序；强调 PGO 增量收益 |
| BPF_PROG_TEST_RUN 不支持某些 prog type | 无法测量部分程序 | XDP/TC 可用；tracing 类改用 BPF_ENABLE_STATS + 实际 hook 触发 |
| 用户态 mock map 与内核 map 性能不一致 | F3 数据不可靠 | 用 kernel bench 数据校准 mock map overhead |
| BCF 数据集无法获取 | 数据集规模缩小 | 自建（Cilium/bcc/selftests，本机有 clang 15/17/18/20） |
| Spectre 实验需要重启 | 每次切换 ~10min | 批量运行：默认跑完 → 重启 mitigations=off 跑完（只需 2 次重启） |
| 真实环境测量方差大 | 结果不稳定 | 足够重复次数 + 统计分析 (CI/方差检验)；报告中说明 |
| perf 与内核版本不匹配 | 无硬件计数器 | 用 6.14 的 perf 临时替代，或从 6.15 源码编译 |
| ARM 无真实硬件 | 无真实性能数据 | LLVM cross-compile 做代码质量静态分析 |
| Arrow Lake P-core vs E-core 异构 | 性能数据不一致 | 所有 benchmark 绑定 P-core (`taskset -c 0-7`) |

---

## 九、预期产出与论文映射

| 产出 | 论文位置 | 用途 |
|------|---------|------|
| Micro-bench 代码质量矩阵 | §2.2 Table 1 | 动机：LLVM vs kernel JIT 基础差距 |
| Micro-bench 因素分解瀑布图 | §2.3 Figure 2 | 动机：差距来源分解 |
| Macro-bench 真实程序差距分布 | §2.2 Figure 1 | 核心实证结果 |
| RQ3 按类别分组对比 | §2.3 Finding 1 | 反直觉发现 |
| RQ4 Spectre 交互效应 | §2.3 Finding 2 | 反直觉发现 → motivate S4 |
| RQ2.5 Verifier 约束影响 | §2.3 Finding 3 | motivate S6 |
| RQ3.2 Pareto 图 | §2.3 Finding 4 | motivate S3 (只需 top-5) |
| RQ5.2 超线性联合优化 | §2.3 Finding 5 | motivate S5 |
| RQ5.1 多程序退化曲线 | §2.3 Finding 6 | motivate S5 |
| Macro-bench 端到端改进 | §5 Evaluation | 系统评估 |
| 策略消融矩阵 | §5.2 Table 3 | 策略交互分析 |
