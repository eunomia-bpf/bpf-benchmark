# UEOS 实证研究与 Benchmark 框架设计

> 本文档是 UEOS (Userspace eBPF Optimization Service) 阶段 1 的详细设计。
> 目标：系统量化 kernel JIT vs LLVM JIT 的性能差距，验证 7 个假设，为后续优化策略提供数据驱动的决策依据。

---

## 零、Research Questions (RQ)

本阶段的实证研究回答以下 5 个 research questions：

**RQ1: 内核 JIT 与 LLVM JIT 的性能差距有多大？**
- 在 1,500+ 个真实 BPF 程序上系统量化 kernel JIT vs llvmbpf (-O3) 的执行时间、代码尺寸、IPC 差异
- 分层量化：纯计算（Layer 1）、因素隔离（Layer 2）、真实程序（Layer 3）
- 期望结果：代码尺寸差 15-40%，执行时间差 10-50%（依程序类型而异）

**RQ2: 差距的根因是什么？各因素贡献多大？**
- 将总差距分解为：基础代码质量(F1)、helper 调用(F2)、map 访问(F3)、Spectre 缓解(F4)、寄存器分配(F5)、分支布局(F6)、verifier 约束(F7)
- Layer 2 的 7 组因素隔离实验，每组定量回答 "该因素贡献了差距的 X%"
- 期望结果：F2(helper) + F4(Spectre) 是主要贡献因素（合计 > 50%）

**RQ3: 哪类 BPF 程序从优化中受益最大？**
- 验证假设 H1（网络策略 > 计算密集）和 H4（top-5 helper 占 80%+ 调用）
- 在 Layer 3 按程序类别（networking/tracing/security/scheduling）分组对比
- 期望结果：helper-heavy + map-heavy 的网络策略程序受益最大 → 直接指导 UEOS 策略选择器设计

**RQ4: Spectre 缓解与编译质量是否存在非线性交互？**
- 验证假设 H2：LLVM 内联 helper 后消除间接跳转 → retpoline 开销一并消失
- 2×2 factorial 实验：{kernel JIT, llvmbpf} × {mitigations=on, off}
- 期望结果：交互效应 > 0，即 "优化同时免费消除了部分安全开销"

**RQ5: 多程序场景下的优化空间如何变化？**
- 验证 H5（联合优化超线性收益）和 H7（多程序超线性退化）
- 同一 hook 挂 1-64 个程序，测量独立优化 vs 联合优化
- 期望结果：N>8 后退化超线性，联合优化在 N≥4 时收益超线性

这 5 个 RQ 覆盖了完整的"测量→归因→分类→发现→扩展"链条。RQ1-RQ2 是基础量化，RQ3 驱动策略选择，RQ4-RQ5 是反直觉发现（论文亮点）。

---

## 一、总体设计

### 1.1 设计原则

1. **从 micro 到 macro 分层**：先用微观 benchmark 量化单个因素（JIT 代码质量、helper 调用、Spectre 缓解），再用宏观 benchmark 验证端到端影响
2. **复用已有基础设施**：不重新造轮子，最大化复用 llvmbpf、Linux bench、bpf_performance、veristat 等已有工具
3. **可复现性**：所有实验用脚本自动化，固定 CPU 频率/NUMA/turbo boost，公开数据
4. **假设驱动**：每组实验对应一个明确的假设（H1-H7），用数据验证或证伪

### 1.2 分层架构

```
┌──────────────────────────────────────────────────────────────┐
│                 Layer 4: 端到端应用 Benchmark                │
│  Cilium pod-to-pod / Katran LB / Tetragon LSM / bpftrace   │
├──────────────────────────────────────────────────────────────┤
│                 Layer 3: 真实程序 Benchmark                  │
│  512+ 个真实 BPF 程序的 kernel JIT vs llvmbpf 性能矩阵      │
├──────────────────────────────────────────────────────────────┤
│                 Layer 2: 因素隔离 Benchmark                  │
│  Helper 调用 / Map 访问 / Spectre 缓解 / 寄存器分配 / ...   │
├──────────────────────────────────────────────────────────────┤
│                 Layer 1: 微观计算 Benchmark                  │
│  纯计算（已有 8 个） + 扩展（hash/sort/pattern-match/...）  │
└──────────────────────────────────────────────────────────────┘
```

---

## 二、可复用的基础设施清单

### 2.1 本仓库已有（bpf-benchmark）

| 组件 | 路径 | 能力 | 复用方式 |
|------|------|------|---------|
| 8 个纯计算 BPF 程序 | `user_bpf_benchmark/bpf_progs/*.bpf.c` | 覆盖整数运算、内存拷贝、字符串比较、跳转表 | Layer 1 基线，扩展为更多类型 |
| 预编译 bytecode | `user_bpf_benchmark/bpf_progs/*.bpf.bin` | 可直接加载到 llvmbpf | 直接用 |
| Python benchmark runner | `user_bpf_benchmark/run_benchmark.py` | 多运行时对比、10 次重复、JSON 输出、图表生成 | 扩展为通用 harness |
| 绘图脚本 | `user_bpf_benchmark/example-output/plot.py` | 柱状图生成 | 复用并扩展 |
| Native baseline | `*.native` (编译好的 C 版本) | 性能上界参照 | 继续用作参照 |
| WASM baseline | `*.wasm` (Wasmtime 版本) | 跨运行时对比 | 可选保留 |

### 2.2 llvmbpf（用户态 LLVM JIT 引擎）

| 组件 | 文件 | 能力 | 复用方式 |
|------|------|------|---------|
| eBPF→LLVM IR 翻译 | `src/compiler.cpp` (1376 行) | 全指令集支持 | 核心编译引擎 |
| LLVM -O3 优化 | `src/llvm_jit_context.cpp:optimizeModule()` | 完整 -O3 pipeline | S1 策略直接用 |
| AOT 编译 | `llvmbpf_vm::do_aot_compile()` | 生成 native ELF | 生成可对比的 native code |
| -emit-llvm | `cli/main.cpp` | 导出 LLVM IR 文本 | 用于 IR 质量分析 |
| helper 注册 | `register_external_function()` | 注册外部函数 | S3 helper 内联 |
| ELF 解析 | `cli/main.cpp` (libbpf) | 从 ELF 加载 BPF 程序 | 加载真实程序 |
| 单元测试框架 | `test/unit-test/` | BPF 程序正确性验证 | 等价性验证基线 |

**关键扩展点**：
- `optimizeModule()` 需要支持逐个 pass 启用/禁用（用于 pass 消融实验）
- `cli/main.cpp` 需要增加 benchmark 模式（输出执行时间、编译时间）
- 需要增加 IR dump 功能（优化前后 IR 对比）

### 2.3 Linux 内核 Benchmark 工具

| 组件 | 路径 | 能力 | 复用方式 |
|------|------|------|---------|
| bench_trigger | `tools/testing/selftests/bpf/benchs/bench_trigger.c` | kprobe/fentry/uprobe 等 ~40 种 attach 开销 | Layer 2 hook 触发基线 |
| bench_ringbufs | 同上 | ringbuf/perfbuf 吞吐量 | Layer 2 事件传递 |
| bench_bloom_filter_map | 同上 | bloom filter map 性能 | Layer 2 map 类型对比 |
| bench_htab_mem | 同上 | hashmap 内存模式 | Layer 2 map 性能 |
| bench_bpf_loop | 同上 | bpf_loop helper 性能 | Layer 2 helper 开销 |
| bpf_jit_disasm | `tools/bpf/bpf_jit_disasm.c` | 导出 kernel JIT 生成的 native code | Kernel JIT 代码质量分析 |
| veristat | `tools/testing/selftests/bpf/veristat.c` | 验证时间/指令数/状态数统计 | 加载链路测量 |

### 2.4 第三方工具

| 工具 | 用途 | 复用方式 |
|------|------|---------|
| `microsoft/bpf_performance` | YAML 驱动的 60+ helper/map 测试 | Layer 2 helper/map 开销 baseline |
| `pchaigno/tail-call-bench` | 0-33 深度 tail call 链开销 | Layer 2 tail call + Spectre 交互 |
| `aspsk/bpf-bench` | 内核模块级 hash/hashmap cycle 精度 | Layer 2 微架构精确测量 |
| `perf stat` | 硬件计数器（IPC/cache miss/分支预测） | 所有 layer 的微架构指标 |
| `bpf_jit_disasm` | kernel JIT 反汇编 | 代码质量对比 |
| `llvm-objdump` | llvmbpf 生成代码反汇编 | 代码质量对比 |

### 2.5 程序数据集来源

| 来源 | 源文件数 | 可用 .bpf.o 数 | 复杂度 | 获取方式 |
|------|---------|---------------|--------|---------|
| **BCF 数据集** | ~503 unique | **1,588 编译变体** | 混合 | `github.com/SunHao-0/BCF/tree/main/bpf-progs`，直接可用 |
| **Linux selftests progs** | **~916** | ~916 (编译后) | 低-中 | `tools/testing/selftests/bpf/progs/`，覆盖所有 prog type |
| **Linux selftests benchs** | 16 | 16 | 低-中 | `tools/testing/selftests/bpf/benchs/` |
| **Cilium datapath** | 9 (bpf_lxc, bpf_host, bpf_overlay, bpf_xdp, bpf_sock, ...) | 6-9 (真实数据面) | **极高** | `cilium/cilium` repo `bpf/` |
| **Calico datapath** | 10 (tc.c, xdp.c, connect_balancer.c, ...) + 51 头文件 | **100s** (编译 flag 排列组合) | 高 | `projectcalico/calico` → `felix/bpf-gpl/` |
| **bcc libbpf-tools** | **57** | 57 | 中 | `iovisor/bcc` → `libbpf-tools/*.bpf.c` |
| **Tetragon sensors** | **23** (generic_kprobe, generic_lsm, bpf_execve, ...) + 26 头文件 | 23 | 高 | `cilium/tetragon` → `bpf/process/` |
| **sched_ext 调度器** | ~8 | ~8 | 中-高 | `sched-ext/scx` → scx_rusty, scx_lavd, scx_bpfland |
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

## 三、数据采集规范

### 3.1 每个 BPF 程序需要采集的静态特征

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
        "bpf_probe_read_kernel": 6,
        "bpf_ktime_get_ns": 2,
        "bpf_redirect": 3,
        "bpf_fib_lookup": 2,
        "bpf_csum_diff": 2,
        "bpf_skb_store_bytes": 1
      }
    },

    "map_access": {
      "total_lookups": 16,
      "unique_maps": 5,
      "map_types": ["BPF_MAP_TYPE_HASH", "BPF_MAP_TYPE_LRU_HASH", "BPF_MAP_TYPE_ARRAY"]
    },

    "tail_calls": 3,
    "stack_usage_bytes": 256,
    "lddw_count": 8,
    "alu64_ratio": 0.45,
    "memory_access_count": 96
  }
}
```

**工具**：编写一个 Python/C 分析器，读取 eBPF bytecode（.bpf.bin 或 ELF），提取上述特征。可基于 `pyelftools` + 自定义 eBPF 指令解码。

### 3.2 每个程序×编译配置需要采集的运行时指标

```json
{
  "program_id": "cilium_bpf_lxc_from_container",
  "compiler": "kernel_jit",       // 或 "llvmbpf_O3", "llvmbpf_O3_pgo", ...
  "kernel_version": "6.6.72",
  "spectre_mitigations": true,

  "compilation_metrics": {
    "compile_time_ns": 125000,
    "native_code_size_bytes": 8192,
    "native_insn_count": 1024,
    "code_inflation_ratio": 0.25,   // native_insn / ebpf_insn
    "spectre_insn_count": 32,       // retpoline + LFENCE 指令数
    "spectre_insn_ratio": 0.031     // spectre_insn / native_insn
  },

  "execution_metrics": {
    "runs": 10000,
    "exec_time_ns": {
      "mean": 450,
      "median": 440,
      "p99": 620,
      "stddev": 35,
      "min": 410,
      "max": 890
    },

    "hw_counters": {
      "instructions": 1200,
      "cycles": 450,
      "ipc": 2.67,
      "branch_instructions": 64,
      "branch_misses": 2,
      "branch_miss_rate": 0.031,
      "l1i_cache_misses": 1,
      "llc_cache_misses": 0,
      "dtlb_misses": 0
    }
  },

  "llvm_specific": {
    "ir_insn_count_before_opt": 512,
    "ir_insn_count_after_opt": 380,
    "optimization_ratio": 0.257,
    "passes_applied": ["instcombine", "gvn", "licm", "simplifycfg", "..."]
  }
}
```

### 3.3 测量环境 — 单机约束

**硬件**：唯一可用机器，所有 Layer 1-4 测量均在此机器完成。

```
Machine:  Intel Core Ultra 9 285K (Arrow Lake-S)
Cores:    24 cores (P-core × 8 + E-core × 16), no HyperThreading
Freq:     800MHz - 5.8GHz, 当前 governor: powersave
Cache:    L1d 768K, L1i 1.3M, L2 40M, L3 36M
RAM:      128GB DDR5, 单 NUMA node
Kernel:   6.15.11-061511-generic (PREEMPT_DYNAMIC)
OS:       Ubuntu 24.04.3 LTS
Spectre:  Enhanced IBRS + IBPB conditional (mitigations ON by default)
BPF:      CONFIG_BPF_JIT=y, CONFIG_BPF_SYSCALL=y, BTF enabled
          unprivileged_bpf_disabled=2 (需要 sudo)
```

**已安装工具链**：
- clang: 15, 17, 18, 20 (多版本可用于 BCF 式变体生成)
- llvm-dev: 14, 15, 17, 18, 20
- libelf-dev, libzstd-dev (llvmbpf 依赖已满足)
- bpftool: /usr/local/sbin/bpftool
- Docker + qemu-aarch64-static (可做 ARM cross-arch 测量)

**需要安装/修复**：
```bash
# perf 与当前内核版本不匹配，需从源码编译或降级内核
# 当前可用: /usr/lib/linux-tools/6.14.0-37-generic/perf (可临时用)
sudo ln -sf /usr/lib/linux-tools/6.14.0-37-generic/perf /usr/local/bin/perf
# 或者从 6.15 源码编译 perf
```

**单机约束的影响**：

| 原设计 | 单机适配 | 影响 |
|--------|---------|------|
| Spectre on/off 需要重启 | 用 GRUB 菜单切换 `mitigations=off` 重启 | 增加 ~10 min/次 |
| Cilium pod-to-pod 需要两台机器 | 用 **veth pair + network namespace** 模拟 | 延迟/吞吐数据仅反映单机 |
| Katran LB 需要流量生成器 | 用 **pktgen** (内核模块) 或 **netns + veth** 自环 | 单机 pps 足以对比 |
| 多核扩展性测量 | 24 cores 足够 (taskset -c 0-N) | 无影响 |
| ARM 测量 | Docker + qemu-aarch64-static 或 LLVM cross-compile | 性能数据不真实，但代码质量(指令数)可靠 |

**测量稳定性脚本**：

```bash
#!/bin/bash
# setup_bench_env.sh — 单机 benchmark 环境准备

# 1. CPU 频率锁定
echo performance | sudo tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor

# 2. 禁用 turbo boost (Arrow Lake)
echo 1 | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo

# 3. 绑定到 P-core (cpu 0-7 通常是 P-core)
# 验证: lscpu -e 查看 CORE 列
BENCH_CPUS="0"  # 默认绑定单个 P-core

# 4. 禁用 ASLR
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space

# 5. 关闭不必要的后台服务
sudo systemctl stop cron atd

# 6. 记录环境
{
  echo "=== Machine ==="
  uname -a
  echo "=== CPU ==="
  lscpu | head -25
  echo "=== Governor ==="
  cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
  echo "=== Turbo ==="
  cat /sys/devices/system/cpu/intel_pstate/no_turbo
  echo "=== Spectre ==="
  cat /sys/devices/system/cpu/vulnerabilities/spectre_v2
  echo "=== Kernel ==="
  cat /proc/version
  echo "=== BPF ==="
  bpftool version
} > bench_env.txt

echo "Environment ready. Pinned to CPU $BENCH_CPUS"
echo "Run benchmarks with: taskset -c $BENCH_CPUS ./benchmark"
```

**ARM 测量方案（可选扩展）**：

```bash
# 方案 1: Docker + qemu-aarch64 用户态模拟
# 优点: 零额外硬件。可测量代码质量（指令数/代码尺寸），不可测量真实性能
docker run --platform linux/arm64 -v $(pwd):/work ubuntu:24.04 bash -c \
    "apt update && apt install -y clang llvm && cd /work && ..."

# 方案 2: LLVM cross-compile 只看生成代码质量
# llvmbpf 支持多 target，可生成 ARM64 native code 分析代码质量
# 不执行，只统计指令数/代码尺寸/寄存器溢出等静态指标
clang --target=bpf -c prog.bpf.c -o prog.bpf.o
./llvmbpf_bench_runner prog.bpf.o --target aarch64 --emit-asm --no-exec

# 方案 3: 论文中说明 "ARM 代码质量分析基于 cross-compile 静态指标"
# 这足以支持 "UEOS 对 ARM 同样有效" 的论点
```

**重复次数**：
- Micro benchmark (Layer 1-2)：每个配置 10,000 次执行，取中位数 + 95% CI
- 真实程序 (Layer 3)：每个配置 1,000 次执行
- 端到端 (Layer 4)：每个配置 5 次完整运行，每次 60 秒

---

## 四、Layer 1 — 微观计算 Benchmark

### 4.1 目的

量化 kernel JIT vs llvmbpf 在**纯计算**场景下的代码质量差异。这层隔离了 helper 调用、map 访问等外部因素，纯粹比较两个编译器生成的 native code 质量。

### 4.2 已有用例（直接复用）

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

### 4.3 需要新增的用例

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

### 4.4 测量方法

```python
# 伪代码：Layer 1 benchmark runner
for program in LAYER1_PROGRAMS:
    bytecode = load_bytecode(program)

    # --- Kernel JIT ---
    # 方法 1：通过 BPF_PROG_TEST_RUN 在内核执行
    kernel_fd = bpf_prog_load(bytecode, BPF_PROG_TYPE_XDP)
    for i in range(N_RUNS):
        time = bpf_prog_test_run(kernel_fd, input_data, repeat=1)
        record("kernel_jit", program, time)

    # 方法 2：导出 kernel JIT 代码分析
    kernel_native = bpf_jit_disasm(kernel_fd)
    analyze_code_quality(kernel_native)

    # --- llvmbpf Tier-1 (LLVM -O3, 无 profile) ---
    vm = llvmbpf_vm()
    vm.load_code(bytecode)
    t_compile = time_ns()
    func = vm.compile()  # -O3
    t_compile = time_ns() - t_compile

    ir_before, ir_after = vm.dump_ir()  # 需要新增功能

    for i in range(N_RUNS):
        time = measure_exec(func, input_data)
        record("llvmbpf_O3", program, time)

    # --- llvmbpf Tier-0 (LLVM -O0, 无优化) ---
    vm2 = llvmbpf_vm(opt_level=0)  # 需要新增选项
    vm2.load_code(bytecode)
    func2 = vm2.compile()
    for i in range(N_RUNS):
        time = measure_exec(func2, input_data)
        record("llvmbpf_O0", program, time)

    # --- Native C baseline ---
    native = compile_c_equivalent(program)
    for i in range(N_RUNS):
        time = measure_exec(native, input_data)
        record("native_c", program, time)
```

### 4.5 期望产出

1. **代码膨胀矩阵**：每个程序 × {kernel JIT, llvmbpf -O0, -O1, -O2, -O3, native C} 的 native 指令数
2. **执行时间矩阵**：同上，中位数 + 95% CI
3. **优化效果分解**：llvmbpf 各 pass 的独立贡献（pass 消融实验）
4. **关键发现**：哪类计算模式 LLVM 优化收益最大？（分支密集 vs 循环密集 vs 内存密集）

---

## 五、Layer 2 — 因素隔离 Benchmark

### 5.1 目的

隔离影响 JIT 差距的具体因素，回答："差距的 N% 来自 X 因素"。

### 5.2 因素分解

```
总 JIT 差距 = Σ(各因素贡献)
  ├── F1: 基础代码质量 (寄存器分配、指令选择、调度)     → Layer 1 已量化
  ├── F2: Helper 调用开销 (indirect call + ABI overhead) → 本层量化
  ├── F3: Map 访问模式 (hash lookup 特化机会)            → 本层量化
  ├── F4: Spectre 缓解 (retpoline/LFENCE)               → 本层量化
  ├── F5: 寄存器映射 (固定 vs LLVM 全局分配)            → 本层量化
  ├── F6: 分支布局 (kernel 顺序 vs LLVM 优化)           → 本层量化
  └── F7: Verifier 约束 (bpf_loop vs native loop)       → 本层量化
```

### 5.3 Benchmark 组 F2：Helper 调用开销

**目标**：量化每个 helper 调用的 overhead，以及 LLVM 内联 helper 后的收益。

**用例设计**：

```c
// f2_helper_call_N.bpf.c
// N 次连续 helper 调用，隔离调用开销
unsigned long long bpf_main(void *ctx) {
    unsigned long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += bpf_ktime_get_ns();  // 可替换为不同 helper
    }
    return sum;
}
```

| 用例 | Helper | N | 测试目标 |
|------|--------|---|---------|
| `f2_ktime_1` | `bpf_ktime_get_ns` | 1 | 单次调用 baseline |
| `f2_ktime_100` | `bpf_ktime_get_ns` | 100 | 批量调用，看 LLVM 能否优化 |
| `f2_map_lookup_1` | `bpf_map_lookup_elem` | 1 | 最常见 helper |
| `f2_map_lookup_100` | `bpf_map_lookup_elem` | 100 | 批量查找 |
| `f2_probe_read_1` | `bpf_probe_read_kernel` | 1 | 内存读取 helper |
| `f2_mixed_helpers` | 混合 5 种 helper | 各 20 次 | 真实调用模式 |

**llvmbpf 侧测量**：
- 不内联 vs 内联 helper 的执行时间差
- 内联后 LLVM 能做的额外优化（死代码消除、常量传播穿越调用边界）

### 5.4 Benchmark 组 F3：Map 访问模式

**目标**：量化不同 map 类型的访问开销，以及 LLVM 是否能对已知 map 类型做特化。

| 用例 | Map 类型 | 操作 | 测试目标 |
|------|----------|------|---------|
| `f3_hash_lookup` | HASH | lookup × 1000 | Hash map 查找开销 |
| `f3_array_lookup` | ARRAY | lookup × 1000 | Array map 查找开销 |
| `f3_percpu_hash` | PERCPU_HASH | lookup × 1000 | Per-CPU 变体 |
| `f3_lru_hash` | LRU_HASH | lookup × 1000 | LRU 淘汰 |
| `f3_hash_update` | HASH | update × 1000 | 写操作 |
| `f3_mixed_ops` | HASH + ARRAY | lookup+update 交替 | 混合访问模式 |

**注**：用户态 llvmbpf 测量需要用 mock map 实现；kernel 侧用真实 map。这是一个方法论挑战 — 需要确保 mock map 的 overhead 可校准。

### 5.5 Benchmark 组 F4：Spectre 缓解交互

**目标**：验证假设 H2 — Spectre 缓解开销是否与 JIT 质量有非线性交互。

**实验设计（2×2 factorial）**：

| 配置 | Compiler | Spectre | 预期 |
|------|----------|---------|------|
| A | Kernel JIT | OFF (`nospectre_v2`) | Kernel baseline |
| B | Kernel JIT | ON (default) | A + Spectre overhead |
| C | llvmbpf -O3 | OFF | LLVM baseline |
| D | llvmbpf -O3 + inline | ON (模拟) | C + 部分 Spectre，但因内联消除了部分 |

**关键测量**：
- `Spectre_overhead_kernel = B - A`
- `Spectre_overhead_llvmbpf = D - C`
- `Interaction_effect = (B - A) - (D - C)`
  - 如果 > 0：Spectre 缓解对 kernel JIT 的影响更大（因为 LLVM 消除了部分间接跳转）
  - 这就是 H2 要验证的非线性交互

**用例**：选择 helper 调用密集的程序（每个 helper call 在 kernel JIT 中都是 indirect call → retpoline）

```bash
# 内核侧控制 Spectre 缓解（需要重启，单机约束）
# 当前状态: Enhanced IBRS + IBPB conditional

# 方案: 修改 GRUB 菜单，两次启动
# 1. 默认启动 (mitigations=auto) → 运行全部 benchmark → 保存结果
# 2. 重启 with: GRUB_CMDLINE_LINUX="mitigations=off"
sudo sed -i 's/GRUB_CMDLINE_LINUX=""/GRUB_CMDLINE_LINUX="mitigations=off"/' /etc/default/grub
sudo update-grub && sudo reboot
# 3. 运行相同 benchmark → 保存结果
# 4. 恢复默认启动

cat /sys/devices/system/cpu/vulnerabilities/spectre_v2
# 当前: Mitigation: Enhanced / Automatic IBRS; IBPB: conditional
# mitigations=off: Vulnerable
```

### 5.6 Benchmark 组 F5：寄存器分配

**目标**：量化 kernel JIT 固定寄存器映射 vs LLVM 全局寄存器分配的差异。

**方法**：
- 设计寄存器压力不同的程序（少量局部变量 vs 大量局部变量）
- 在 LLVM 中分别用 RegAllocFast（模拟 kernel JIT 的简单分配）和 RegAllocGreedy（默认 -O3）
- 比较溢出到栈的次数（spill count）

| 用例 | 寄存器压力 | 预期差异 |
|------|-----------|---------|
| `f5_low_pressure` | 3 个局部变量 | 小差异（kernel 11 个 reg 够用） |
| `f5_medium_pressure` | 8 个局部变量 | 中等差异 |
| `f5_high_pressure` | 15+ 个局部变量 | 大差异（kernel 需大量 spill） |

### 5.7 Benchmark 组 F6：分支布局

**目标**：量化分支预测对 JIT 差距的贡献。

**方法**：设计有明确热路径/冷路径的程序。

```c
// f6_branch_layout.bpf.c
// 90% 走 fast path, 10% 走 slow path
unsigned long long bpf_main(void *ctx) {
    unsigned long long *data = (unsigned long long *)ctx;
    unsigned long long result = 0;
    for (int i = 0; i < 1000; i++) {
        if (data[i] < 900) {  // 90% taken
            result += data[i];            // fast path: 1 instruction
        } else {
            result += data[i] * data[i];  // slow path: 多指令
            result ^= data[i] >> 3;
        }
    }
    return result;
}
```

**kernel JIT**：分支按源代码顺序排列（fall-through 是 taken）
**LLVM -O3**：优化 basic block 布局，hot path fall-through
**LLVM -O3 + PGO**：基于 profile 的最优布局

用 `perf stat` 的 `branch-misses` 计数器量化差异。

### 5.8 Benchmark 组 F7：Verifier 约束

**目标**：验证假设 H3 — verifier 约束是否影响运行时性能。

| 用例 | Verifier 约束 | 对比 |
|------|-------------|------|
| `f7_bpf_loop` | 使用 `bpf_loop(N, callback, ...)` | vs llvmbpf 中恢复为 native for loop |
| `f7_stack_512` | 栈使用接近 512B | vs llvmbpf 允许更大栈 |
| `f7_bounds_check` | 每次 ctx 访问都有边界检查 | vs llvmbpf 合并冗余检查 |

```c
// f7_bpf_loop.bpf.c — kernel 版本（受 verifier 约束）
static int callback(int idx, void *ctx) {
    *(int *)ctx += idx * idx;
    return 0;
}
unsigned long long bpf_main(void *mem) {
    int sum = 0;
    bpf_loop(10000, callback, &sum, 0);
    return sum;
}

// f7_native_loop.c — llvmbpf 可优化为的版本
unsigned long long bpf_main(void *mem) {
    int sum = 0;
    for (int i = 0; i < 10000; i++) {
        sum += i * i;
    }
    return sum;
}
```

---

## 六、Layer 3 — 真实程序 Benchmark

### 6.1 目的

在 512+ 个真实 BPF 程序上系统测量 kernel JIT vs llvmbpf 差距，验证假设 H1、H4、H5。

### 6.2 数据集构建

**第一批：BCF 数据集（1,588 个编译变体，直接可用）**

从 `github.com/SunHao-0/BCF/tree/main/bpf-progs` 下载。包含 503 个独立对象名、1,588 个编译变体（同一源程序 × clang-14~21 × -O1/-O2/-O3/-Os）。来源包括 Calico (492 对象/1,476 变体)、Cilium (6/42)、bpf-examples (2/42)、BCC (1/8)、手动收集 (9/9)。

BCF 的变体生成策略天然适合我们的实验：可以同时测量编译器版本和优化级别对 JIT 差距的影响。

**第二批：补充真实程序（~120 个）**

覆盖 BCF 数据集未包含的程序类型和应用场景：

| 来源 | 程序 | Prog Type | 数量 | 获取方式 |
|------|------|-----------|------|---------|
| **bcc libbpf-tools** | execsnoop, biolatency, tcpconnect, funclatency, ... | KPROBE/TP | **57** | `iovisor/bcc` → `libbpf-tools/*.bpf.c` |
| **Tetragon** | bpf_generic_kprobe, bpf_generic_lsm_core, bpf_execve_event, bpf_exit, bpf_fork, ... | KPROBE/LSM/TP | **23** | `cilium/tetragon` → `bpf/process/` |
| **Cilium** (补充) | bpf_sock, bpf_wireguard | SOCK_OPS/SCHED_CLS | 2 | `cilium/cilium` → `bpf/` |
| **Katran** | xdp_root, balancer_kern, healthchecking_kern | XDP | 3 | `facebookincubator/katran` |
| **sched_ext** | scx_rusty, scx_lavd, scx_bpfland | STRUCT_OPS | 3 | `sched-ext/scx` |
| **Linux selftests** (精选) | test_cls_redirect, xdp_redirect_map, test_tc_peer, ... | 各种 | ~30 | `tools/testing/selftests/bpf/progs/` (从 916 个中精选) |
| **合计** | | | **~120** | |

**第三批（可选扩展）：Linux selftests 全量**

`tools/testing/selftests/bpf/progs/` 包含 ~916 个 BPF 源文件，覆盖所有 prog type。可编译后批量测量，但大多数是简单的测试程序，实际优化空间有限。建议作为 "长尾" 数据 — 运行全量测量，但论文重点分析前两批。

### 6.3 测量流程

```bash
#!/bin/bash
# layer3_benchmark.sh — 真实程序批量测量

DATASET_DIR="./dataset"
RESULTS_DIR="./results/layer3"
KERNEL_VERSIONS=("6.1" "6.6" "6.12")

for prog in $DATASET_DIR/*.bpf.o; do
    name=$(basename $prog .bpf.o)

    # 1. 静态分析
    python3 analyze_bytecode.py $prog > $RESULTS_DIR/$name.static.json

    # 2. Kernel JIT 测量
    #    加载到内核，用 BPF_PROG_TEST_RUN 执行
    sudo ./kernel_bench_runner $prog \
        --runs 1000 \
        --perf-counters instructions,cycles,branch-misses,L1-icache-load-misses \
        --output $RESULTS_DIR/$name.kernel.json

    # 3. Kernel JIT 代码导出
    sudo bpf_jit_disasm > $RESULTS_DIR/$name.kernel.asm

    # 4. llvmbpf -O3 测量
    ./llvmbpf_bench_runner $prog \
        --opt-level 3 \
        --runs 1000 \
        --emit-ir $RESULTS_DIR/$name.llvm.ll \
        --emit-asm $RESULTS_DIR/$name.llvm.asm \
        --output $RESULTS_DIR/$name.llvmbpf_O3.json

    # 5. llvmbpf -O0 测量（隔离 LLVM 优化的贡献）
    ./llvmbpf_bench_runner $prog \
        --opt-level 0 \
        --runs 1000 \
        --output $RESULTS_DIR/$name.llvmbpf_O0.json

    # 6. llvmbpf -O3 + helper 内联
    ./llvmbpf_bench_runner $prog \
        --opt-level 3 \
        --inline-helpers \
        --runs 1000 \
        --output $RESULTS_DIR/$name.llvmbpf_O3_inline.json
done

# 7. 汇总分析
python3 analyze_layer3.py $RESULTS_DIR/ --output $RESULTS_DIR/summary.json
```

### 6.4 分析维度

**按程序类别分组**（验证 H1）：
```
category = {networking, tracing, security, scheduling, storage}
for each category:
    avg_speedup = mean(llvmbpf_O3_time / kernel_jit_time for prog in category)
    → H1 预测: networking 的 avg_speedup > computing 的 avg_speedup
```

**Helper 调用频率分布**（验证 H4）：
```
helper_freq = Counter()
for prog in all_programs:
    for helper in prog.helper_calls:
        helper_freq[helper] += 1
→ H4 预测: top-5 helpers 占总调用的 80%+
→ 绘制 Pareto 图（helper × 累计调用占比）
```

**代码质量相关性分析**：
```
对每个程序计算：
  x = (helper_call_count, map_access_count, branch_count, insn_count)
  y = speedup_ratio (llvmbpf_O3 / kernel_jit)

用线性回归/随机森林分析：哪些静态特征最能预测优化收益？
→ 这直接驱动 Strategy Composer 的设计
```

---

## 七、Layer 4 — 端到端应用 Benchmark

### 7.1 目的

在真实应用场景中测量优化的端到端影响。这层回答 "用户能感受到多少改进？"

### 7.2 场景 1：Cilium 网络策略（XDP/TC）— 单机 netns

**设置（单机）**：
- 2 个 network namespace，通过 veth pair 连接
- 用 Cilium 的 BPF 程序手动挂载（不需要完整 Cilium 部署）
- BPF 程序挂载在 TC ingress/egress

```bash
# 创建 netns + veth pair
sudo ip netns add ns1
sudo ip netns add ns2
sudo ip link add veth1 type veth peer name veth2
sudo ip link set veth1 netns ns1
sudo ip link set veth2 netns ns2
sudo ip netns exec ns1 ip addr add 10.0.0.1/24 dev veth1
sudo ip netns exec ns2 ip addr add 10.0.0.2/24 dev veth2
sudo ip netns exec ns1 ip link set veth1 up
sudo ip netns exec ns2 ip link set veth2 up

# 挂载 Cilium BPF 程序到 TC
sudo ip netns exec ns1 tc qdisc add dev veth1 clsact
sudo ip netns exec ns1 tc filter add dev veth1 ingress bpf da obj cilium_bpf_lxc.o sec from-container
```

**工作负载**：
- `iperf3` 吞吐量测试（TCP, UDP）
- `netperf` TCP_RR 延迟测试（P50/P99）

**测量**：
- Baseline: 原始 BPF 程序（kernel JIT）
- Optimized: 替换为 llvmbpf -O3 编译版本
- 指标: 吞吐量 (Gbps), 延迟 (P50/P99 μs), CPU 利用率

```bash
# 吞吐量测量
sudo ip netns exec ns2 iperf3 -s &
sudo ip netns exec ns1 iperf3 -c 10.0.0.2 -t 60 -J > baseline.json

# 替换优化后的 BPF 程序
sudo ip netns exec ns1 tc filter replace dev veth1 ingress bpf da obj cilium_opt.o sec from-container
sudo ip netns exec ns1 iperf3 -c 10.0.0.2 -t 60 -J > optimized.json
```

### 7.3 场景 2：XDP 负载均衡（Katran）— 单机 pktgen

**设置（单机）**：
- Katran XDP L4 负载均衡器挂载在 veth 上
- 使用内核 pktgen 模块生成流量（零额外硬件）

```bash
# 方案: veth pair + pktgen
sudo ip link add xdp0 type veth peer name pktgen0
sudo ip link set xdp0 up && sudo ip link set pktgen0 up
# 挂载 Katran XDP 程序到 xdp0
sudo ip link set dev xdp0 xdp obj katran_balancer.o sec xdp

# 用 pktgen 从 pktgen0 发包
sudo modprobe pktgen
echo "add_device pktgen0" > /proc/net/pktgen/kpktgend_0
echo "pkt_size 64" > /proc/net/pktgen/pktgen0
echo "count 10000000" > /proc/net/pktgen/pktgen0
echo "dst 10.0.0.1" > /proc/net/pktgen/pktgen0
echo "start" > /proc/net/pktgen/pgctrl
```

**工作负载**：64 字节 UDP 包（最大 pps 测试）

**测量**：
- pps on single P-core (`taskset -c 0`)
- 多核扩展曲线 (1/2/4/8 P-cores)
- 替换前后的 pps 差异

### 7.4 场景 3：Tetragon 安全监控（LSM）

**设置**：
- Tetragon 部署在宿主机
- 配置 process lifecycle + file access 监控策略

**工作负载**：
- `sysbench` CPU/fileio/threads 测试
- `redis-benchmark` 吞吐量测试
- `nginx` 请求处理

**测量**：
- 被监控应用的 overhead（吞吐量下降 %, 延迟增加 %）
- 优化 Tetragon BPF 程序后的 overhead 变化

### 7.5 场景 4：bpftrace 持续 Profiling

**设置**：
- 用 bpftrace 挂载多个 kprobe/tracepoint

**工作负载**：
- 运行一个 CPU 密集型应用（如编译 Linux 内核）
- 同时运行 bpftrace 持续 profiling

**测量**：
- 被 profiling 应用的 slowdown（编译时间增加 %）
- 优化 bpftrace 的 BPF 程序后 slowdown 变化
- bpftrace 本身的事件处理吞吐量

---

## 八、Layer 3.5 — 多程序 Benchmark（验证 H5、H7）

### 8.1 目的

验证多程序场景的假设：H5（联合优化超线性收益）和 H7（多程序超线性退化）。

### 8.2 Benchmark 设计

**H7 验证：多程序退化曲线**

```bash
# 在同一 hook 上挂 N 个 BPF 程序
for N in 1 2 4 8 16 32 64; do
    # 方法: 用 BPF_LINK_CREATE 在同一 kprobe hook 上挂 N 个程序
    # 每个程序是相同的（隔离程序间差异）
    ./multi_prog_bench --hook kprobe:do_sys_openat2 --count $N --runs 10000
    # 输出: 每次 hook 触发的总延迟
done
# 预期: N>8 后出现超线性增长
```

**H5 验证：联合优化收益**

```bash
# 在 llvmbpf 中分别独立编译 vs 联合编译
for N in 2 4 8 16; do
    programs = select_N_programs(cilium_programs, N)

    # 独立编译
    for prog in programs:
        llvmbpf_compile(prog, opt_level=3)
    total_time_independent = sum(exec_time(prog) for prog in programs)

    # 联合编译（LTO）
    llvmbpf_compile_joint(programs, opt_level=3, lto=True)
    total_time_joint = exec_time(joint_program)

    speedup = total_time_independent / total_time_joint
    # 预期: speedup > 1.0 且随 N 增长
done
```

---

## 九、需要开发的工具

### 9.1 bytecode 静态分析器

```
工具名: ebpf_analyzer
输入: eBPF ELF 文件 或 .bpf.bin
输出: JSON 格式的静态特征（见 3.1 节）
实现: Python (pyelftools) 或 C (libbpf)
估计工作量: 1 周
```

### 9.2 llvmbpf benchmark runner

```
工具名: llvmbpf_bench_runner
输入: eBPF ELF 文件 + 配置选项
输出: JSON 格式的编译/执行指标（见 3.2 节）
功能:
  - 支持 --opt-level 0/1/2/3
  - 支持 --emit-ir (导出优化前后 IR)
  - 支持 --emit-asm (导出 native code)
  - 支持 --inline-helpers (启用 S3)
  - 支持 --runs N (重复执行次数)
  - 支持 --perf-counters (硬件计数器, 通过 perf_event_open)
  - 支持 --pass-list (指定启用的 LLVM pass, 用于消融实验)
实现: C++ (基于 llvmbpf)
估计工作量: 2 周

需要对 llvmbpf 的修改:
  1. optimizeModule() 支持可配置优化级别
  2. optimizeModule() 支持 pass 消融（逐个启用/禁用）
  3. 新增 dump_ir_before/after() 接口
  4. compile() 返回编译时间统计
```

### 9.3 kernel benchmark runner

```
工具名: kernel_bench_runner
输入: eBPF ELF 文件 + 配置选项
输出: JSON 格式的执行指标
功能:
  - 通过 BPF_PROG_LOAD 加载到内核
  - 通过 BPF_PROG_TEST_RUN 执行
  - 记录验证时间、JIT 编译时间、执行时间
  - 收集硬件计数器
  - 导出 kernel JIT 生成的 native code
实现: C (libbpf)
估计工作量: 2 周
```

### 9.4 结果分析与可视化

```
工具名: analyze_results.py
输入: 各 Layer 的 JSON 结果文件
输出:
  - 性能差距矩阵 (heatmap)
  - 假设验证结果 (统计检验 + 置信区间)
  - 因素分解瀑布图 (waterfall chart)
  - Pareto 图 (helper 调用频率)
  - 多程序扩展曲线 (N vs overhead)
  - 消融研究柱状图 (strategy ablation)
实现: Python (matplotlib + seaborn + scipy.stats)
估计工作量: 1 周
```

---

## 十、实施时间线

```
第 1 周: 工具开发
  ├── ebpf_analyzer (bytecode 静态分析)
  ├── 扩展 llvmbpf（可配置优化级别 + IR dump + pass 消融）
  └── 搭建测量环境（CPU 锁频脚本 + perf 配置）

第 2 周: 工具开发 + Layer 1
  ├── llvmbpf_bench_runner
  ├── kernel_bench_runner
  ├── 编写 Layer 1 新增用例 (8 个)
  └── 运行 Layer 1 全矩阵（8+8 程序 × 5 编译器配置）

第 3-4 周: Layer 2 因素隔离
  ├── 编写 F2-F7 各组 benchmark
  ├── 运行全矩阵
  └── 初步因素分解分析

第 5-6 周: Layer 3 真实程序
  ├── 构建 BCF 数据集 + 补充程序
  ├── 批量运行 512+ 程序 × {kernel JIT, llvmbpf -O0, -O1, -O2, -O3}
  ├── 静态特征提取
  └── H1/H4 假设验证

第 7-8 周: Layer 3.5 多程序 + Layer 4 端到端
  ├── H5/H7 多程序实验
  ├── Cilium 端到端测量
  ├── H2 Spectre 交互实验（需要两次启动，不同 kernel cmdline）
  └── 综合分析 + 因素分解

第 9-10 周: 分析与报告
  ├── 可视化全部结果
  ├── 统计检验（假设验证的 p-value）
  ├── 撰写实证分析报告
  └── 提交 eBPF Workshop 论文初稿

第 11-12 周: 迭代与补充
  ├── 基于审稿反馈补充实验
  ├── H3/H6 补充实验
  └── 最终版本
```

---

## 十一、风险与缓解

| 风险 | 影响 | 缓解措施 |
|------|------|---------|
| kernel JIT vs llvmbpf 差距太小（< 10%） | 论文价值降低 | 聚焦 helper-heavy 程序（差距应更大）；强调 PGO 的增量收益 |
| BPF_PROG_TEST_RUN 不支持某些 prog type | 无法测量部分程序 | 对 XDP/TC 可用；tracing 类改用实际 hook 触发测量 |
| 用户态 mock map 与内核 map 性能不一致 | F3 数据不可靠 | 用 kernel bench 数据校准 mock map overhead |
| BCF 数据集无法获取 | 数据集规模缩小 | 自建数据集（从 Cilium/bcc/selftests 编译，本机有 clang 15/17/18/20） |
| Spectre 实验需要重启（单机） | 每次切换 ~10min | 批量运行：默认启动跑完全部 → 重启 mitigations=off 跑完全部 → 只需重启 2 次 |
| 网络 benchmark 无法双机（单机） | 吞吐量受 veth overhead 影响 | 用 netns+veth，论文说明 "单机 veth 测量，绝对值可能偏保守但相对差异可靠" |
| perf 与内核版本不匹配 | 无硬件计数器 | 用 6.14 的 perf 临时替代，或从 6.15 源码编译 perf |
| ARM 无真实硬件 | 无真实性能数据 | 用 LLVM cross-compile 做代码质量静态分析（指令数/溢出数），论文中标注 |
| llvmbpf pass 消融需要修改代码 | 开发周期 | 先用 -O0/-O1/-O2/-O3 粗粒度对比，再逐步细化 |
| Arrow Lake P-core vs E-core 异构 | 性能数据不一致 | 所有 benchmark 绑定 P-core (cpu 0-7)，用 `taskset` 固定 |

---

## 十二、预期产出与论文映射

| 产出 | 论文位置 | 用途 |
|------|---------|------|
| Layer 1 代码质量矩阵 | §2.2 Table 1 | 动机：LLVM vs kernel JIT 基础差距 |
| Layer 2 因素分解瀑布图 | §2.3 Figure 2 | 动机：差距来源分解 |
| Layer 3 真实程序差距分布 | §2.2 Figure 1 | 核心实证结果 |
| H1 按类别分组对比 | §2.3 Finding 1 | 反直觉发现 |
| H2 Spectre 交互效应 | §2.3 Finding 2 | 反直觉发现 → motivate S4 |
| H3 Verifier 约束影响 | §2.3 Finding 3 | motivate S6 |
| H4 Pareto 图 | §2.3 Finding 4 | motivate S3 (只需 top-5) |
| H5 超线性联合优化 | §2.3 Finding 5 | motivate S5 |
| H7 多程序退化曲线 | §2.3 Finding 6 | motivate S5 |
| Layer 4 端到端改进 | §5 Evaluation | 系统评估 |
| 策略消融矩阵 | §5.2 Table 3 | 策略交互分析 |
