# eBPF Benchmark 框架详细分析

> 本文档对 bpf-benchmark 项目的整体框架设计进行详细分析，涵盖顶层入口、三层 benchmark 模型、Scanner 工具、结果管理、VM 测试框架等所有关键组件。
> 生成日期：2026-03-18

---

## 目录

1. [项目概览](#1-项目概览)
2. [顶层入口 (Makefile)](#2-顶层入口-makefile)
3. [Micro Benchmark 层](#3-micro-benchmark-层)
4. [Corpus Benchmark 层](#4-corpus-benchmark-层)
5. [E2E Benchmark 层](#5-e2e-benchmark-层)
6. [Scanner 工具](#6-scanner-工具)
7. [结果管理](#7-结果管理)
8. [VM 测试框架](#8-vm-测试框架)
9. [三层 Benchmark 模型设计理念](#9-三层-benchmark-模型设计理念)
10. [整体数据流图](#10-整体数据流图)

---

## 1. 项目概览

### 1.1 项目目标

本项目是一个 eBPF 基准测试套件，核心目标是比较以下三种运行时的性能：

- **llvmbpf**：用户态 LLVM JIT 编译器（来自 eunomia-bpf 项目）
- **kernel eBPF**：原生内核 eBPF JIT（stock kernel）
- **kernel-recompile**：内核 eBPF + BpfReJIT 重编译优化（论文的核心贡献）

项目服务于论文 "BpfReJIT: Safe Post-Load JIT Specialization for Kernel eBPF"（目标 OSDI '26），核心论点是将 JIT 的安全约束与优化策略分离，让特权用户态根据部署上下文选择优化变体。

### 1.2 项目结构总览

```
bpf-benchmark/
├── Makefile                    # 顶层入口，所有 benchmark 操作的唯一规范入口
├── CLAUDE.md                   # 项目指南文档
├── config/                     # YAML 套件配置
│   ├── micro_pure_jit.yaml     # 微基准套件定义（62 个 benchmark）
│   └── ablation/               # 消融实验 YAML
├── micro/                      # Micro benchmark 层（主要活跃开发区域）
│   ├── driver.py               # 统一驱动入口
│   ├── run_micro.py            # 传统入口（现在转发到 driver.py）
│   ├── _driver_impl_run_micro.py  # 核心编排实现
│   ├── benchmark_catalog.py    # YAML 解析 → 类型化 dataclass
│   ├── input_generators.py     # 确定性二进制输入生成
│   ├── results_layout.py       # 结果文件命名/布局
│   ├── summarize_rq.py         # RQ 导向的 Markdown 汇总
│   ├── compare_results.py      # A/B 结果对比
│   ├── runner/                 # C++20 micro_exec 运行器
│   │   └── src/
│   │       ├── main.cpp
│   │       ├── llvmbpf_runner.cpp
│   │       ├── kernel_runner.cpp
│   │       ├── perf_counters.cpp
│   │       └── ...
│   ├── programs/               # BPF benchmark 程序
│   │   ├── common.h            # 公共宏和辅助函数
│   │   ├── bitcount.bpf.c
│   │   ├── ...（~60 个 .bpf.c）
│   │   └── archive/runtime/    # 已归档的运行时基准程序
│   ├── policies/               # 每 benchmark 的重编译策略
│   │   ├── bitcount.yaml
│   │   ├── ...
│   │   └── variants/           # 命名策略集
│   │       ├── all-apply/      # 全部站点启用
│   │       └── baseline/       # 不启用任何站点
│   ├── orchestrator/           # 编排子模块
│   │   ├── benchmarks.py       # 选择和输入解析
│   │   ├── catalog.py          # 清单加载
│   │   ├── commands.py         # 命令构建
│   │   ├── results.py          # 结果解析和统计
│   │   ├── reporting.py        # 报告生成
│   │   └── ...
│   ├── generated-inputs/       # 生成的输入 .mem 文件
│   └── results/                # Micro 结果 JSON
├── corpus/                     # Corpus benchmark 层
│   ├── config/
│   │   └── macro_corpus.yaml   # Corpus 套件定义
│   ├── _driver_impl_run_corpus_v5_vm_batch.py  # VM batch 驱动
│   ├── repos.yaml              # 上游项目清单
│   ├── repos/                  # 上游项目源码
│   ├── build/                  # 编译后的 BPF 对象文件
│   ├── policies/               # Corpus 策略文件
│   └── results/                # Corpus 结果
├── e2e/                        # E2E benchmark 层
│   ├── run.py                  # 统一 E2E 入口
│   ├── cases/                  # 各 E2E 测试场景
│   │   ├── tracee/             # Aqua Tracee 安全监控
│   │   ├── tetragon/           # Cilium Tetragon 安全监控
│   │   ├── bpftrace/           # bpftrace 动态追踪
│   │   ├── xdp_forwarding/     # XDP 转发基准
│   │   └── scx/                # sched_ext 调度器
│   ├── common/                 # 公共工具库
│   │   ├── recompile.py        # 重编译工具
│   │   ├── vm.py               # VM 管理
│   │   ├── workload.py         # 负载生成器
│   │   ├── agent.py            # BPF agent 管理
│   │   └── metrics.py          # 指标采集
│   └── results/                # E2E 结果
├── scanner/                    # JIT 重编译站点扫描工具
│   ├── src/
│   │   ├── cli.cpp             # CLI 入口（6 个子命令）
│   │   ├── pattern_v5.cpp      # V5 模式匹配
│   │   └── policy_config.cpp   # 策略配置解析
│   └── include/
│       └── bpf_jit_scanner/
│           ├── pattern_v5.hpp
│           └── policy_config.hpp
├── vendor/                     # 子模块
│   ├── llvmbpf/                # 用户态 LLVM BPF JIT
│   ├── libbpf/                 # 内核 BPF 库
│   ├── bpftool/                # BPF 工具
│   └── linux-framework/        # 定制内核（含 JIT directive 支持）
└── docs/
    ├── kernel-jit-optimization-plan.md  # 核心计划文档（单一 hub）
    ├── tmp/                    # 分析报告（.md）
    └── paper/                  # 论文 LaTeX 源码
```

---

## 2. 顶层入口 (Makefile)

文件路径：`/home/yunwei37/workspace/bpf-benchmark/Makefile`

Makefile 是整个 benchmark 框架的唯一规范入口。它定义了所有构建、测试和基准运行操作。

### 2.1 变量定义

```makefile
ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
MICRO_DIR := $(ROOT_DIR)/micro
SCANNER_DIR := $(ROOT_DIR)/scanner
KERNEL_DIR := $(ROOT_DIR)/vendor/linux-framework

# 默认参数（可被命令行覆盖）
BZIMAGE ?= vendor/linux-framework/arch/x86/boot/bzImage
ITERATIONS ?= 10
WARMUPS ?= 2
REPEAT ?= 200
BENCH ?=
POLICY ?= default
```

#### 参数传递机制

| 参数 | 默认值 | 说明 | 用法示例 |
|------|--------|------|---------|
| `ITERATIONS` | 10 | 每个 benchmark-runtime 对的测量迭代次数 | `make vm-micro ITERATIONS=30` |
| `WARMUPS` | 2 | 热身迭代次数 | `make vm-micro WARMUPS=5` |
| `REPEAT` | 200 | 每次 sample 内的重复执行次数 | `make vm-micro REPEAT=1000` |
| `BENCH` | 空 | 空格分隔的 benchmark 名称列表（空=全部） | `make vm-micro BENCH="simple bitcount"` |
| `POLICY` | default | 策略集名称 | `make vm-micro POLICY=all-apply` |
| `BZIMAGE` | vendor/.../bzImage | 自定义内核镜像路径 | `make vm-micro BZIMAGE=/path/to/bzImage` |

`BENCH` 参数通过以下逻辑转换为 `--bench` 标志：
```makefile
BENCH_FLAGS := $(foreach b,$(BENCH),--bench $(b))
```

`POLICY` 参数映射到策略目录：
```makefile
ifeq ($(POLICY),default)
  POLICY_DIR := $(ROOT_DIR)/micro/policies
else
  POLICY_DIR := $(ROOT_DIR)/micro/policies/variants/$(POLICY)
endif
```

三种内置策略集：
- `default` → `micro/policies/`（每 benchmark 的精细策略）
- `all-apply` → `micro/policies/variants/all-apply/`（所有站点启用）
- `baseline` → `micro/policies/variants/baseline/`（不启用任何站点）

### 2.2 构建 Target

#### `all` — 构建所有组件
```makefile
all:
    $(MAKE) micro
    $(MAKE) scanner
    $(MAKE) kernel-tests
```

#### `micro` — 构建 micro_exec 和 BPF 程序
```makefile
micro:
    $(MAKE) -C "$(MICRO_DIR)" micro_exec programs
```
产出：`micro/build/runner/micro_exec`（C++ 运行器）和 `micro/programs/*.bpf.o`（编译后的 BPF 对象）

#### `scanner` — 构建 bpf-jit-scanner
```makefile
scanner:
    cmake -S "$(SCANNER_DIR)" -B "$(SCANNER_BUILD_DIR)" -DCMAKE_BUILD_TYPE=Release
    cmake --build "$(SCANNER_BUILD_DIR)" --target bpf-jit-scanner -j"$(NPROC)"
```
产出：`scanner/build/bpf-jit-scanner`

#### `kernel` — 构建内核 bzImage
```makefile
kernel:
    $(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage
```
产出：`vendor/linux-framework/arch/x86/boot/bzImage`

### 2.3 文件依赖和增量构建

Makefile 使用基于文件的依赖实现增量构建：

```makefile
# micro_exec 依赖其源码
$(MICRO_RUNNER): $(MICRO_RUNNER_SOURCES)
    $(MAKE) -C "$(MICRO_DIR)" micro_exec

# BPF 程序依赖其源码（使用 stamp 文件跟踪）
$(MICRO_BPF_STAMP): $(MICRO_BPF_SOURCES)
    $(MAKE) -C "$(MICRO_DIR)" programs
    touch "$@"

# scanner 依赖其源码
$(SCANNER_PATH): $(SCANNER_SOURCES)
    cmake -S "$(SCANNER_DIR)" -B "$(SCANNER_BUILD_DIR)" ...
    cmake --build "$(SCANNER_BUILD_DIR)" ...

# bzImage 依赖关键内核 JIT 源文件
$(BZIMAGE_PATH): $(KERNEL_JIT_SOURCES)
    $(MAKE) -C "$(KERNEL_DIR)" -j"$(NPROC)" bzImage
```

其中 `KERNEL_JIT_SOURCES` 精确追踪两个关键文件：
```makefile
KERNEL_JIT_SOURCES := \
    $(KERNEL_DIR)/arch/x86/net/bpf_jit_comp.c \
    $(KERNEL_DIR)/kernel/bpf/jit_directives.c
```

### 2.4 Benchmark Target

#### `smoke` — 本地快速冒烟测试（不需要 VM）
```makefile
smoke: $(MICRO_RUNNER) $(MICRO_BPF_STAMP)
    python3 "$(MICRO_DIR)/driver.py" suite \
        --runtime llvmbpf \
        $(LOCAL_SMOKE_ARGS) \
        --output "$(SMOKE_OUTPUT)"
```
仅运行 `simple` benchmark，1 次迭代，0 次热身，10 次重复。只测试 llvmbpf 运行时。

#### `vm-micro` — VM 内完整 micro 套件
```makefile
vm-micro: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(SCANNER_PATH) verify-build $(BZIMAGE_PATH)
    $(VNG) --run "$(BZIMAGE_PATH)" --rwdir "$(ROOT_DIR)" -- \
        bash -lc 'cd "$(ROOT_DIR)" && python3 "$(MICRO_DIR)/driver.py" suite \
            --runtime llvmbpf \
            --runtime kernel \
            --runtime kernel-recompile \
            $(MICRO_ARGS) \
            $(POLICY_DIR_FLAG) \
            --output "$(VM_MICRO_OUTPUT)"'
```
运行全部三种运行时对比。依赖 `verify-build` 确保所有产物存在且最新。

#### `vm-corpus` — VM 内 corpus 套件
```makefile
vm-corpus: $(MICRO_RUNNER) $(MICRO_BPF_STAMP) $(SCANNER_PATH) verify-build $(BZIMAGE_PATH)
    python3 "$(MICRO_DIR)/driver.py" corpus v5-vm-batch \
        --skip-build \
        --kernel-image "$(BZIMAGE_PATH)" \
        --runner "$(MICRO_RUNNER)" \
        --scanner "$(SCANNER_PATH)" \
        --btf-custom-path "$(VMLINUX_PATH)" \
        --repeat "$(REPEAT)" \
        --use-policy \
        --output-json "$(VM_CORPUS_OUTPUT_JSON)" \
        --output-md "$(VM_CORPUS_OUTPUT_MD)"
```
注意 corpus 自己管理 VM 启动（内部使用 vng），所以不像 vm-micro 那样外套 vng。

#### `vm-e2e` — VM 内 E2E 套件
```makefile
vm-e2e: ...
    # 分别启动 4 个 VM 运行不同的 E2E 场景
    $(VNG) --run ... -- bash -lc 'python3 e2e/run.py tracee ...'
    $(VNG) --run ... -- bash -lc 'python3 e2e/run.py tetragon ...'
    $(VNG) --run ... -- bash -lc 'python3 e2e/run.py bpftrace ...'
    $(VNG) --run ... --network loop --network loop -- bash -lc 'python3 e2e/run.py xdp_forwarding ...'
```
XDP 转发场景需要 `--network loop --network loop` 创建虚拟网络接口。

#### `vm-all` — 顺序运行所有 VM benchmark
```makefile
vm-all:
    $(MAKE) vm-selftest
    $(MAKE) vm-micro
    $(MAKE) vm-corpus
    $(MAKE) vm-e2e
```

### 2.5 辅助 Target

#### `verify-build` — 构建产物验证
检查 bzImage、micro_exec、scanner 是否存在。额外检查源文件是否比产物更新（stale build 检测），并打印 provenance 信息（git commit、文件时间戳、当前 POLICY）。

#### `compare` — A/B 结果对比
```makefile
compare:
    python3 "$(MICRO_DIR)/compare_results.py" "$(OLD)" "$(NEW)"
```
用法：`make compare OLD=a.json NEW=b.json`

---

## 3. Micro Benchmark 层

这是项目的核心层，用于精细的 JIT 代码生成质量对比。

### 3.1 统一驱动入口 `driver.py`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/driver.py`

`driver.py` 是所有 benchmark 子系统的统一入口点。它支持四个子命令：

```python
def build_parser() -> argparse.ArgumentParser:
    parser.add_argument("subcommand", choices=["suite", "rigorous", "census", "corpus"])
```

- **`suite`**：运行声明式 micro benchmark 套件（最常用）
- **`rigorous`**：运行严格模式（local 或 vm 传输层）
- **`corpus`**：运行 corpus benchmark（多种模式）
- **`census`**：运行 directive 普查

`suite` 子命令的路由逻辑：
```python
def _suite_entry(argv):
    suite_path = Path(known.suite).resolve()
    manifest_kind = _detect_suite_kind(suite_path)
    if manifest_kind in {"macro", "corpus"}:
        return run_macro_corpus_impl.main(argv)
    return run_micro_impl.main(argv)
```

`corpus` 子命令支持 8 种模式：
```python
dispatch = {
    "macro": run_macro_corpus_impl.main,
    "perf": run_corpus_perf_impl.main,
    "tracing": run_corpus_tracing_impl.main,
    "tracing-exec": run_corpus_tracing_exec_impl.main,
    "tracing-vm": run_tracing_corpus_vm_impl.main,
    "v5-framework": run_corpus_v5_framework_impl.main,
    "v5-production": run_production_corpus_v5_framework_impl.main,
    "v5-vm-batch": run_corpus_v5_vm_batch_impl.main,
}
```

### 3.2 核心编排器 `_driver_impl_run_micro.py`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/_driver_impl_run_micro.py`

这是 micro benchmark 的核心逻辑实现。

#### 功能和职责

1. **解析命令行参数**：运行时选择、迭代次数、策略目录等
2. **加载套件定义**：通过 `benchmark_catalog.py` 加载 YAML
3. **确保构建产物**：检查并按需构建 micro_exec 和 BPF 程序
4. **收集 provenance 元数据**：kernel commit、scanner commit、策略哈希等
5. **编排测量循环**：对每个 benchmark-runtime 对执行热身+测量
6. **计算统计量**：median/mean/p95/stdev
7. **附加基线调整**：减去 baseline benchmark 的开销
8. **输出结果 JSON**

#### 测量循环的关键设计

```python
# 对每个 benchmark：
for benchmark in benchmarks:
    # 1. 为每个 runtime 准备命令和热身
    for runtime in runtimes:
        command = build_micro_benchmark_command(...)
        for _ in range(warmups):
            parse_runner_sample(run_command(command, args.cpu).stdout)

    # 2. 交叉迭代：消除运行时间顺序偏差
    for iteration_idx in range(iterations):
        # 2 个 runtime 时交替顺序：0→A,B; 1→B,A; 2→A,B; ...
        if len(runtimes) == 2:
            ordered = list(runtimes) if iteration_idx % 2 == 0 else list(reversed(runtimes))
        else:
            # >2 个 runtime 时使用种子化洗牌
            rng = random.Random(runtime_order_seed + iteration_idx)
            ordered = list(runtimes)
            rng.shuffle(ordered)

        for runtime in ordered:
            sample = parse_runner_sample(run_command(...).stdout)
            # 验证 expected_result
```

这种**交叉平衡**（counterbalanced）设计消除了因 CPU 频率漂移、热效应等导致的时间顺序偏差。

#### Provenance 收集

```python
def collect_provenance(args, iterations, warmups, policy_dir):
    return {
        "kernel_commit": _git_rev_parse(linux_dir),
        "scanner_commit": _git_rev_parse(scanner_dir),
        "policy_files_hash": _hash_policy_files(effective_policy_dir),
        "policy_dir": str(effective_policy_dir),
        "params": {"iterations": iterations, "warmups": warmups, "repeat": repeat},
        "cpu_model": _read_cpu_model(),
        "environment": _detect_environment(),  # "vm" 或 "bare-metal"
        "timestamp": datetime.now(timezone.utc).isoformat(),
    }
```

#### 基线调整

```python
def attach_baseline_adjustments(results, baseline_benchmark):
    # 从 baseline benchmark（默认为 "simple"）获取每个 runtime 的 median exec_ns
    # 对每个 benchmark 的每个 run：
    #   adjusted = median_exec - baseline_exec
    #   ratio = median_exec / baseline_exec
    # 额外计算 llvmbpf/kernel 的 raw_ratio 和 adjusted_ratio
```

baseline benchmark（`simple`）用于消除 harness 框架本身的固定开销。

### 3.3 YAML 解析 `benchmark_catalog.py`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/benchmark_catalog.py`

#### 数据模型

```
SuiteSpec
├── suite_name: str
├── manifest_path: Path
├── toolchains: dict[str, ToolchainSpec]
├── build: BuildSpec
│   ├── commands: dict[str, tuple[str, ...]]
│   ├── runner_binary: Path
│   └── bpftool_binary: Path
├── defaults: DefaultsSpec
│   ├── iterations: int
│   ├── warmups: int
│   ├── repeat: int
│   ├── runtimes: tuple[str, ...]
│   └── output: Path
├── analysis: AnalysisSpec
│   └── baseline_benchmark: str | None
├── runtimes: dict[str, RuntimeSpec]
│   └── RuntimeSpec
│       ├── name: str
│       ├── label: str
│       ├── mode: str          # "llvmbpf" | "kernel" | "kernel-recompile"
│       ├── default_repeat: int
│       ├── require_sudo: bool
│       └── aliases: tuple[str, ...]
└── benchmarks: dict[str, BenchmarkSpec]
    └── BenchmarkSpec
        ├── name: str
        ├── description: str
        ├── category: str
        ├── base_name: str     # 对应 .bpf.o 文件名
        ├── program_dir: Path
        ├── io_mode: str       # "staged" | "packet" | "map" | "tc" | "cgroup_skb"
        ├── kernel_input_size: int
        ├── family: str | None
        ├── tags: tuple[str, ...]
        ├── expected_result: int | None
        └── policy_file: Path | None
```

`io_mode` 决定了 harness 宏和运行器的数据传递方式：
- `staged`：通过 XDP packet payload 传递预生成的二进制数据（主流 pure-JIT 路径）
- `packet`：使用原始 packet 数据（packet-backed 控制组）
- `tc`/`cgroup_skb`：kernel-only 非 XDP 控制组

### 3.4 输入生成器 `input_generators.py`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/input_generators.py`

#### 功能和职责

为每个 benchmark 生成确定性的二进制输入数据。确定性保证了结果的可复现性。

#### 设计模式

每个生成器函数签名为 `generate_xxx(output: Path) -> dict[str, int]`：
1. 使用线性同余生成器（LCG）产生伪随机数据
2. 按 BPF 程序的 `input_map` value struct 布局打包二进制
3. 写入 `.mem` 文件到 `micro/generated-inputs/`

```python
def _lcg(state: int) -> int:
    return (state * 6364136223846793005 + 1442695040888963407) & MASK64
```

全局注册表 `GENERATORS` 包含 ~60 个生成器，涵盖：
- 基础算术（simple, bitcount, checksum）
- 数据结构操作（binary_search, hash_chain）
- 分支模式（branch_layout, branch_dense, branch_fanout_32）
- 内存访问模式（stride_load, load_byte_recompose）
- SIMD-like 操作（cmov_select, cond_select_dense）
- 位域操作（bitfield_extract, extract_dense）

#### 缓存机制

```python
def materialize_input(generator_name: str, force: bool = False) -> tuple[Path, dict[str, int]]:
    output = GENERATED_INPUT_DIR / f"{generator_name}.mem"
    if output.exists() and not force:
        return output, {}  # 已缓存，跳过生成
    metadata = GENERATORS[generator_name](output)
    return output, metadata
```

### 3.5 C++ 运行器 `micro/runner/`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/`

#### 架构

`micro_exec` 是一个 C++20 程序，提供三个子命令：

```cpp
// main.cpp
int main(int argc, char **argv) {
    const auto options = parse_args(argc, argv);
    if (options.command == "list-programs") { ... }
    if (options.command == "run-llvmbpf") { print_json(run_llvmbpf(options)); }
    if (options.command == "run-kernel") { print_json(run_kernel(options)); }
}
```

#### `run-llvmbpf` 子命令 (`llvmbpf_runner.cpp`)

功能：用户态 LLVM JIT 执行路径。

流程：
1. 加载 ELF 文件，提取 BPF 字节码
2. 通过 `llvmbpf_vm` 进行 JIT 编译（记录 compile_ns）
3. 在用户态执行编译后的 native code（记录 exec_ns）
4. 使用模拟的 map 操作
5. 数据包缓冲区分配在低 32 位地址空间（MAP_32BIT），以兼容 XDP context

关键技术约束：
- 使用 `lfence; rdtsc` / `rdtscp; lfence` 进行精确的 TSC 计时
- 不支持 BPF-to-BPF 内部子程序调用（ELF 加载器限制）

#### `run-kernel` 子命令 (`kernel_runner.cpp`)

功能：内核态执行路径（含可选重编译）。

流程：
1. 通过 libbpf 加载 BPF 程序到内核
2. 使用 `bpf_prog_test_run_opts` 执行
3. 对于 `kernel-recompile` 模式：
   - 使用 `BPF_PROG_JIT_RECOMPILE` syscall（自定义 bpf_cmd = 39）
   - 通过 memfd 传递 JIT directive blob
   - 支持 `BPF_F_JIT_DIRECTIVES_FD` flag

#### 输出格式

每次执行输出一行 JSON：
```json
{
    "compile_ns": 12345,
    "exec_ns": 678,
    "result": 12345678,
    "timing_source": "tsc",
    "phases_ns": {"load": 100, "attach": 200, ...},
    "perf_counters": {"instructions": 1000, "cycles": 500}
}
```

### 3.6 BPF 程序 `micro/programs/`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/programs/`

#### Harness 宏体系

`common.h` 定义了一套 harness 宏，将 benchmark 逻辑与执行框架解耦：

| 宏 | 程序类型 | 数据传递 | 用途 |
|---|---|---|---|
| `DEFINE_STAGED_INPUT_XDP_BENCH` | XDP | packet payload | Pure-JIT 主路径（48 个） |
| `DEFINE_PACKET_BACKED_XDP_BENCH` | XDP | raw packet | Packet-backed 控制组（5 个） |
| `DEFINE_FIXED_PACKET_BACKED_XDP_BENCH` | XDP | fixed-size packet | Packet-backed 变体 |
| `DEFINE_MAP_BACKED_TC_BENCH` | TC | packet payload | Kernel-only TC 控制组（2 个） |
| `DEFINE_MAP_BACKED_CGROUP_SKB_BENCH` | cgroup_skb | packet payload | Kernel-only cgroup 控制组（1 个） |

#### Staged XDP 宏的工作方式

```c
#define DEFINE_STAGED_INPUT_XDP_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE)
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx) {
        // 1. 从 packet data 中提取 payload
        u8 *data = (u8 *)(long)ctx->data;
        u8 *data_end = (u8 *)(long)ctx->data_end;
        micro_prepare_packet_payload(data, data_end, INPUT_SIZE, &payload, &payload_len);
        // 2. 调用 benchmark 函数
        BENCH_FN(payload, payload_len, &result);
        // 3. 将结果写回 packet 头部
        micro_write_u64_le(data, result);
        return XDP_PASS;
    }
```

"Staged" 意味着输入数据预先注入到 packet buffer，BPF 程序直接从 packet 内存读取，避免了 BPF map 查找的运行时开销——这确保测量的是纯 JIT 代码生成质量。

#### Benchmark 程序示例

```c
// bitcount.bpf.c
#include "common.h"

static __always_inline int bench_bitcount(const u8 *data, u32 len, u64 *out) {
    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);
    u64 acc = seed;
    for (u32 i = 0; i < BITCOUNT_MAX_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8);
        acc += micro_popcount64(value ^ acc);
        acc ^= value >> (i & 7);
    }
    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(bitcount_xdp, bench_bitcount,
                              bitcount_input_value, BITCOUNT_INPUT_SIZE)
```

每个 benchmark 程序遵循固定模式：
1. `#include "common.h"`
2. 定义 `bench_xxx(const u8 *data, u32 len, u64 *out)` 函数
3. 使用合适的 `DEFINE_*_BENCH` 宏生成入口

### 3.7 编排子模块 `micro/orchestrator/`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/orchestrator/`

#### `commands.py` — 命令构建

核心函数 `build_micro_benchmark_command` 根据 runtime mode 构建 micro_exec 命令：

```python
def build_micro_benchmark_command(runner_binary, *, runtime_mode, program, io_mode, repeat, ...):
    if runtime_mode == "llvmbpf":
        command = build_runner_command(runner_binary, "run-llvmbpf", ...)
    elif runtime_mode == "kernel":
        command = build_runner_command(runner_binary, "run-kernel", ...)
    elif runtime_mode in {"kernel-recompile", "kernel_recompile"}:
        # 传递 policy_file 或 recompile_v5/recompile_all 标志
        command = build_runner_command(runner_binary, "run-kernel", ..., recompile_v5=..., recompile_all=...)
```

`build_runner_command` 支持丰富的选项：`--io-mode`, `--repeat`, `--memory`, `--policy-file`, `--perf-counters`, `--dump-jit`, `--compile-only`, `--recompile-v5` 等。

#### `results.py` — 结果解析

定义了丰富的 TypedDict 类型：
- `SummaryStats`：count/mean/median/min/max/p95/stdev
- `RunnerSample`：compile_ns/exec_ns/result/perf_counters
- `DirectiveScanSummary`：各 family 的站点数
- `RecompileSummary`：重编译结果

`ns_summary()` 函数计算统计汇总：
```python
def ns_summary(values: list) -> SummaryStats:
    return {
        "count": len(values),
        "mean": statistics.mean(values),
        "median": statistics.median(values),
        "min": min(values),
        "max": max(values),
        "p95": _percentile(values, 0.95),
        "stdev": statistics.stdev(values) if len(values) > 1 else 0,
    }
```

#### `benchmarks.py` — Benchmark 选择

```python
def select_benchmarks(names, suite, *, default_names=None):
    # 名称为空时返回全部 benchmark
    # 否则按名称查找，未找到则报错
```

```python
def resolve_memory_file(benchmark, regenerate_inputs):
    # 调用 input_generators.materialize_input 获取 .mem 文件路径
```

### 3.8 策略文件 `micro/policies/`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/policies/`

每个有重编译站点的 benchmark 有一个策略 YAML 文件。策略文件是 version 3 格式：

```yaml
# bitcount.yaml
version: 3
program: 'bitcount_xdp'
sites: []
```

空的 `sites` 列表意味着不应用任何重编译（因为该 benchmark 没有值得应用的站点，或站点的收益不超过 I-cache 刷新开销）。

当有站点需要应用时：
```yaml
version: 3
program: 'load_byte_recompose_xdp'
sites:
  - {family: wide_mem, offset: 42}
  - {family: wide_mem, offset: 78}
```

策略变体：
- `variants/all-apply/`：所有站点都启用（用于消融实验）
- `variants/baseline/`：不启用任何站点（stock kernel 基线）

### 3.9 结果汇总工具

#### `summarize_rq.py` — RQ 导向汇总

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/summarize_rq.py`

将 JSON 结果转换为面向研究问题（Research Question）的 Markdown 报告。支持 bootstrap 置信区间（默认 5000 次迭代）。

#### `compare_results.py` — A/B 对比

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/compare_results.py`

自动推断比较的 runtime 对（优先 kernel-recompile/kernel，回退到 llvmbpf/kernel），计算每个 benchmark 的 ratio 变化和整体 geomean。超过 5% 的变化标记为 WORSE 或 BETTER。

### 3.10 套件配置 `config/micro_pure_jit.yaml`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/config/micro_pure_jit.yaml`

定义了 62 个 benchmark 的完整清单。结构层次：

```yaml
suite_name: micro_staged_codegen

paths:
  program_dir: micro/programs

toolchains:
  llvmbpf: { root: vendor/llvmbpf }
  libbpf: { root: vendor/libbpf }
  bpftool: { root: vendor/bpftool }

build:
  commands:
    micro_exec: [make, -C, micro, micro_exec]
    programs: [make, -C, micro, programs]
  runner_binary: micro/build/runner/micro_exec
  bpftool_binary: micro/build/vendor/bpftool/bpftool

defaults:
  iterations: 10
  warmups: 2
  repeat: 200
  runtimes: [llvmbpf, kernel]
  output: micro/results/pure_jit.latest.json

analysis:
  baseline_benchmark: simple   # 用于基线减法

runtimes:
  - name: llvmbpf
    label: llvmbpf LLVM JIT
    mode: llvmbpf
  - name: kernel
    label: kernel eBPF
    mode: kernel
    sudo: true
  - name: kernel-recompile
    label: kernel eBPF + manifest recompile policy
    mode: kernel-recompile
    sudo: true

benchmarks:
  - name: bitcount
    description: Kernighan popcount over generated u64 input
    category: alu-mix
    family: popcount
    level: medium
    base_name: bitcount
    kernel_input_size: 2056
    input_generator: bitcount
    expected_result: 8589936168
    policy_file: micro/policies/bitcount.yaml
    tags: [popcount, pure-jit]
  # ... (62 个 benchmark)
```

62 个 benchmark 分类：
- **48 个 staged XDP 计算案例**：纯 JIT 代码生成质量测试
- **6 个 per-form dense 变体**：密集站点场景（cmov_dense, extract_dense, rotate_dense, cond_select_dense, endian_swap_dense, branch_flip_dense）
- **5 个 packet-backed XDP 控制组**：排除 staged input 机制开销
- **3 个 kernel-only 非 XDP 控制组**：TC 和 cgroup_skb 路径

---

## 4. Corpus Benchmark 层

### 4.1 概述

Corpus 层测试真实世界 eBPF 程序的 JIT 重编译效果。程序来源包括：
- **Katran**（Meta 负载均衡器）
- **Calico**（Kubernetes 网络策略）
- **Suricata**（安全 IDS）
- **Tracee**（Aqua 安全监控）
- **Tetragon**（Cilium 安全监控）
- **systemd**、**Datadog Agent**、**Coroot** 等

### 4.2 配置 `corpus/config/macro_corpus.yaml`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml`

```yaml
suite_name: macro_corpus

corpus:
  manifest: corpus/repos.yaml
  local_repos: corpus/repos
  inventory: corpus/inventory.json

defaults:
  iterations: 3
  warmups: 1
  repeat: 1
  output: corpus/results/macro_corpus.latest.json

runtimes:
  - name: kernel
    label: kernel eBPF
    mode: kernel
  - name: kernel_recompile_v5
    label: kernel eBPF recompile v5
    mode: kernel-recompile-v5

programs:
  - name: katran_balancer
    source: corpus/build/katran/balancer.bpf.o
    prog_type: xdp
    test_method: bpf_prog_test_run
    ...
  - name: tracee_lsm_bpf
    test_method: attach_trigger
    trigger: "bpftool prog show >/dev/null"
    ...
  - name: systemd_sysctl_monitor
    test_method: compile_only
    ...
```

注意三种 `test_method`：
- `bpf_prog_test_run`：可以通过 `bpf_prog_test_run_opts` 直接执行
- `attach_trigger`：需要 attach 到内核后触发（如 LSM hook）
- `compile_only`：只测量编译时间（无法安全执行）

### 4.3 Corpus VM Batch 驱动 `_driver_impl_run_corpus_v5_vm_batch.py`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/corpus/_driver_impl_run_corpus_v5_vm_batch.py`

这是 corpus 的主要执行驱动。核心流程：

1. **加载 macro_corpus.yaml** 获取程序清单
2. **对每个程序**：
   - 通过 libbpf 加载到内核
   - 使用 scanner 的 `enumerate` 功能扫描优化站点
   - 应用策略配置
   - 执行 kernel baseline 和 kernel-recompile 对比
   - 收集 compile_ns 和 exec_ns
3. **生成汇总报告**（JSON + Markdown）

Corpus 驱动自己管理 VM 启动，因为需要在 VM 内进行完整的 BPF 程序加载流程。

### 4.4 关键文件

| 文件 | 功能 |
|------|------|
| `corpus/repos.yaml` | 上游项目源码仓库清单 |
| `corpus/repos/` | 克隆的上游项目源码 |
| `corpus/build/` | 编译后的 BPF 对象文件 |
| `corpus/inputs/` | 测试输入数据（dummy packet 等） |
| `corpus/inventory.json` | 程序清单和元数据 |
| `corpus/policies/` | 每个 corpus 程序的策略文件 |
| `corpus/results/` | 结果输出目录 |

---

## 5. E2E Benchmark 层

### 5.1 概述

E2E 层测量真实 eBPF 应用在实际工作负载下的端到端性能影响。不同于 micro/corpus 的隔离测量，E2E 测量的是**应用层可观测的性能变化**。

### 5.2 统一入口 `e2e/run.py`

文件路径：`/home/yunwei37/workspace/bpf-benchmark/e2e/run.py`

支持 5 种 E2E 场景：

```python
parser.add_argument("case", choices=("tracee", "tetragon", "bpftrace", "scx", "xdp_forwarding"))
```

#### 执行流程概览

```
1. 加载 eBPF 应用（如 Tracee）
2. 使用 scanner enumerate 扫描已加载程序的优化站点
3. 应用重编译策略
4. 运行工作负载（exec_storm, file_io, network 等）
5. 采集性能指标（BPF 运行时间、CPU 使用率、事件计数）
6. 对比 baseline vs recompiled
```

### 5.3 Tracee E2E 场景

文件路径：`/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py`

Tracee 是 Aqua Security 的运行时安全监控工具，它加载多个 BPF 程序追踪系统调用和安全事件。

测试流程：
1. 运行 setup.sh 安装依赖
2. 启动 Tracee agent（加载 BPF 程序）
3. 等待 agent 健康
4. 使用 `find_bpf_programs` 定位已加载的 BPF 程序
5. 运行 baseline 工作负载
6. 使用 `scan_programs` + `apply_recompile` 应用优化
7. 运行 recompile 工作负载
8. 计算 delta 和改善比例

工作负载类型：
- **exec_storm**：大量进程创建和退出
- **file_io**：密集文件操作
- **network**：网络连接和数据传输
- **scheduler_load**：调度器压力

### 5.4 其他 E2E 场景

| 场景 | 目标应用 | 特点 |
|------|---------|------|
| **tetragon** | Cilium Tetragon | execve tracepoint 和 kprobe 管线 |
| **bpftrace** | bpftrace | 动态追踪工具 |
| **scx** | sched_ext (scx_rusty) | BPF 调度器 |
| **xdp_forwarding** | XDP 转发器 | 需要虚拟网络接口（iperf3 流量） |

### 5.5 公共工具库 `e2e/common/`

#### `recompile.py` — 重编译工具

文件路径：`/home/yunwei37/workspace/bpf-benchmark/e2e/common/recompile.py`

核心功能：
- `scan_programs()`：调用 scanner enumerate 扫描已加载程序
- `apply_recompile()`：应用重编译策略
- `resolve_policy_files()`：解析策略文件

公共 recompile API 已固定为 scanner `enumerate --prog-id` 路径；旧的 fd-based fallback 已删除。

#### `vm.py` — VM 管理

文件路径：`/home/yunwei37/workspace/bpf-benchmark/e2e/common/vm.py`

```python
def run_in_vm(kernel_path, script_path, cpus, mem, timeout, *, networks=()):
    command = [
        vng,
        "--run", str(kernel),
        "--cwd", str(ROOT_DIR),
        "--disable-monitor",
        "--cpus", str(cpus),
        "--mem", str(mem),
        "--rwdir", str(RESULTS_DIR),
        "--rwdir", str(ROOT_DIR / "docs" / "tmp"),
    ]
    for network in networks:
        command.extend(["--network", str(network)])
    command.extend(["--exec", guest_path])
    return subprocess.run(command, ...)
```

`write_guest_script()` 生成临时的 shell 脚本，在 VM guest 内执行。自动处理 venv 激活、临时目录创建和权限设置。

#### `workload.py` — 负载生成器
- `run_exec_storm()`：反复 fork+exec 短命进程
- `run_file_io()`：创建、写入、读取、删除文件
- `run_network_load()`：网络连接和数据传输
- `run_scheduler_load()`：CPU 密集型任务

#### `metrics.py` — 指标采集
- `enable_bpf_stats()`：启用 BPF 运行时统计
- `sample_bpf_stats()`：采集各程序的 run_time_ns 和 run_cnt
- `sample_cpu_usage()`：采集 CPU 利用率
- `compute_delta()`：计算 baseline vs recompile 的差异

---

## 6. Scanner 工具

### 6.1 概述

文件路径：`/home/yunwei37/workspace/bpf-benchmark/scanner/`

`bpf-jit-scanner` 是一个 C++ 工具，用于扫描已 JIT 编译的 BPF 程序的 native code，识别可以通过重编译优化的站点（site）。

### 6.2 六个子命令

```
bpf-jit-scanner <subcommand> [options]

  scan              扫描单个程序的优化站点
  generate-policy   生成策略配置文件
  compile-policy    编译策略为二进制 blob
  apply             扫描并立即应用重编译
  dump              导出程序的 xlated 字节码
  enumerate         枚举系统中所有已加载的 BPF 程序并扫描
```

#### `scan` — 站点扫描

输入：位置参数文件或 `--xlated` 文件；live program 走 `enumerate --prog-id`
输出：JSON 格式的站点清单

扫描 8 个 family：
| Family | 标志 | 说明 |
|--------|------|------|
| COND_SELECT (CMOV) | `--cmov` | 条件选择 → CMOV 指令 |
| WIDE_MEM | `--wide-mem` | 字节级加载 → 宽内存操作 |
| ROTATE | `--rotate` | 位移 + OR → 原生旋转指令 |
| LEA | `--lea` | 乘法 + 加法 → LEA 地址计算 |
| EXTRACT (BEXTR) | `--extract` / `--bitfield-extract` | 位域提取 → BEXTR 指令 |
| ZERO_EXT | `--zero-ext` | 冗余零扩展消除 |
| ENDIAN | `--endian` | 字节序转换 → MOVBE 指令融合 |
| BRANCH_FLIP | `--branch-flip` | 分支方向翻转优化 |

#### `enumerate` — 系统枚举扫描

通过 `BPF_PROG_GET_NEXT_ID` syscall 枚举系统中所有已加载的 BPF 程序，逐一获取 JIT 代码并扫描。

```
bpf-jit-scanner enumerate --all --json --recompile --policy-dir /path/to/policies
```

可选 `--prog-id N` 过滤特定程序。支持 `--recompile` 直接应用重编译。

#### `generate-policy` — 策略生成

根据扫描结果和配置文件生成 YAML 策略。

#### `compile-policy` — 策略编译

将 YAML 策略编译为二进制 blob，通过 memfd 传递给内核的 `BPF_PROG_JIT_RECOMPILE` syscall。

#### `apply` — 扫描并应用

组合 scan + compile-policy + recompile syscall 的一步操作。

#### `dump` — 字节码导出

导出程序的 xlated（验证后的）BPF 字节码，用于离线分析。

### 6.3 Cost Model

scanner 内置了一个成本模型，用于决定哪些站点值得应用：

```cpp
struct CostModelOptions {
    bool skip_same_size = true;     // 规则 1：跳过不改变代码大小的变换
    bool skip_cmov = true;          // 规则 2：默认跳过 CMOV（策略敏感）
    uint32_t max_sites_per_form = 128; // 规则 3：站点数过多时跳过（I-cache 代价）
};
```

设计理由：
- **规则 1**：full-image recompile 的 I-cache 刷新开销 >= 同大小变换的微架构收益
- **规则 2**：CMOV 对可预测分支增加关键路径延迟（论文证实 cond_select_dense 回归 +53.8%）
- **规则 3**：大量站点的 recompile 导致 I-cache 大面积失效

### 6.4 与 Benchmark 框架的集成

Scanner 在框架中的角色：

```
                    ┌──────────────┐
                    │  micro_exec  │
                    │  kernel_runner│
                    │  (run-kernel)│
                    └──────┬───────┘
                           │ BPF_PROG_JIT_RECOMPILE syscall
                           │ (directive blob via memfd)
                           ▼
              ┌────────────────────────┐
              │   内核 JIT directive    │
              │   框架                  │
              │   (jit_directives.c)   │
              └────────────────────────┘
                           ▲
                           │ 策略 blob
              ┌────────────┴────────────┐
              │    bpf-jit-scanner      │
              │    (compile-policy)     │
              └────────────┬────────────┘
                           ▲
                           │ YAML 策略
              ┌────────────┴────────────┐
              │   micro/policies/*.yaml │
              └─────────────────────────┘
```

在 E2E 场景中：
```
应用启动 → BPF 程序加载 → scanner enumerate → 策略生成/应用 → 重编译 → 性能测量
```

---

## 7. 结果管理

### 7.1 结果文件命名约定

文件路径：`/home/yunwei37/workspace/bpf-benchmark/micro/results_layout.py`

三种命名格式：

| 格式 | 示例 | 用途 |
|------|------|------|
| `authoritative` | `pure_jit_authoritative_20260314.json` | 正式测量结果 |
| `smoke` | `pure_jit_smoke_20260314_121530.json` | 冒烟测试/部分运行 |
| `latest` | `pure_jit.latest.json` | 符号链接到最新 authoritative |

```python
RESULT_FILE_RE = re.compile(r"^(?P<suite>.+)_(?P<kind>authoritative|smoke)_(?P<date>\d{8})\.json$")
```

#### `latest` 别名机制

```python
def refresh_latest_alias(latest_path, target_path):
    # 删除旧链接
    latest_path.unlink()
    # 创建相对符号链接指向新的 authoritative 文件
    latest_path.symlink_to(Path(os.path.relpath(target_path, latest_path.parent)))
```

当输出路径以 `.latest.json` 结尾时，实际写入带时间戳的文件，然后自动更新 `.latest.json` 符号链接。

### 7.2 结果目录结构

```
micro/results/
├── pure_jit.latest.json → pure_jit_authoritative_20260314.json
├── pure_jit_authoritative_20260314.json
├── smoke.latest.json
├── vm_micro.latest.json → vm_micro_authoritative_20260314.json
├── vm_micro_authoritative_20260314.json
├── vm_micro_smoke.latest.json
├── per_form_ablation_20260313/
├── ablation/
└── archive/

corpus/results/
├── vm_corpus.latest.json
├── vm_corpus.latest.md

e2e/results/
├── tracee.latest.json
├── tracee.latest.md
├── tetragon.latest.json
├── bpftrace.latest.json
└── xdp_forwarding.latest.json
```

### 7.3 结果 JSON 结构

```json
{
    "suite": "micro_staged_codegen",
    "manifest": "/path/to/micro_pure_jit.yaml",
    "generated_at": "2026-03-14T12:00:00+00:00",
    "provenance": {
        "kernel_commit": "7de19ef03...",
        "scanner_commit": "abc123...",
        "policy_files_hash": "a1b2c3d4e5f67890",
        "policy_dir": "/path/to/micro/policies",
        "params": {"iterations": 10, "warmups": 2, "repeat": 200},
        "cpu_model": "Intel(R) Core(TM) i7-...",
        "environment": "vm",
        "timestamp": "2026-03-14T12:00:00+00:00"
    },
    "host": {
        "hostname": "...",
        "kernel_version": "6.x.y",
        "cpu_governor": "performance",
        "perf_event_paranoid": "1"
    },
    "defaults": {
        "iterations": 10,
        "warmups": 2,
        "repeat": 200,
        "blind_apply": false,
        "perf_counters": false
    },
    "benchmarks": [
        {
            "name": "bitcount",
            "category": "alu-mix",
            "family": "popcount",
            "io_mode": "staged",
            "expected_result": 8589936168,
            "runs": [
                {
                    "runtime": "llvmbpf",
                    "repeat": 200,
                    "samples": [...],
                    "compile_ns": {"count": 10, "mean": ..., "median": ..., "p95": ..., "stdev": ...},
                    "exec_ns": {"count": 10, "mean": ..., "median": ..., "p95": ..., "stdev": ...},
                    "timing_source": "tsc",
                    "baseline_adjustment": {
                        "baseline_benchmark": "simple",
                        "applied": true,
                        "baseline_exec_ns": 100,
                        "median_minus_baseline_ns": 500,
                        "median_over_baseline_ratio": 6.0
                    }
                }
            ],
            "runtime_comparison": {
                "llvmbpf_over_kernel_exec_ratio": 0.65,
                "llvmbpf_over_kernel_adjusted_exec_ratio": 0.62
            }
        }
    ]
}
```

### 7.4 Compare 工具

```
make compare OLD=micro/results/old.json NEW=micro/results/new.json
```

输出示例：
```
Comparing results:
  OLD: 2026-03-13T...  kernel=abc123  env=vm
  NEW: 2026-03-14T...  kernel=7de19ef  env=vm
  Ratio: kernel-recompile / kernel  (lower=faster numerator)

Benchmark              OLD ratio   NEW ratio      Delta  Flag
-------------------------------------------------------------
simple                    1.0012      1.0003    -0.0009
bitcount                  0.9823      0.9901    +0.0078
load_byte_recompose       0.9312      0.9050    -0.0262
cond_select_dense         1.4821      1.5380    +0.0559  WORSE
-------------------------------------------------------------
GEOMEAN (shared)          1.0054      1.0074    +0.0020

Significant regressions (>5%): cond_select_dense
```

---

## 8. VM 测试框架

### 8.1 virtme-ng (vng)

所有需要内核功能的 benchmark 都在 virtme-ng 虚拟机中运行。virtme-ng 提供轻量级的 KVM 虚拟化，使用自定义内核启动。

#### VM 启动方式

```bash
vng --run <bzImage> --rwdir <project_root> -- bash -lc '<command>'
```

关键参数：
- `--run <bzImage>`：指定内核镜像
- `--rwdir <path>`：挂载为 guest 内可读写的目录
- `--cwd <path>`：guest 工作目录
- `--cpus <N>`：guest CPU 数量
- `--mem <size>`：guest 内存大小
- `--disable-monitor`：禁用监控
- `--network loop`：创建虚拟网络接口
- `--exec <script>`：执行的脚本

#### 为什么需要 VM？

1. **内核运行时需要 root 权限**：`bpf_prog_test_run_opts` 需要 `CAP_BPF`
2. **自定义内核**：BpfReJIT 需要修改后的内核（`jit_directives.c`）
3. **隔离性**：避免污染宿主机的 BPF 子系统
4. **可复现性**：控制内核版本和配置

### 8.2 bzImage 构建

```bash
make kernel
# 等价于
make -C vendor/linux-framework -j$(nproc) bzImage
```

`vendor/linux-framework` 是一个 git submodule，包含修改后的 Linux 内核：
- `arch/x86/net/bpf_jit_comp.c`：x86 BPF JIT 编译器（增加了 directive 支持）
- `kernel/bpf/jit_directives.c`：JIT directive 框架（定义 safe variant menu）

### 8.3 VM 内执行流程

以 `make vm-micro` 为例：

```
宿主机                                VM Guest
────────                              ──────────
1. make vm-micro
2. 检查依赖（micro_exec, BPF programs, scanner, bzImage）
3. vng --run bzImage --rwdir . -- \
     bash -lc '                      ← 启动 VM
                                      4. cd 到项目目录
                                      5. 激活 Python venv
                                      6. python3 micro/driver.py suite \
                                           --runtime llvmbpf \
                                           --runtime kernel \
                                           --runtime kernel-recompile \
                                           --iterations 10 \
                                           --warmups 2 \
                                           --repeat 200 \
                                           --output micro/results/vm_micro.latest.json
                                      7. 对每个 benchmark × runtime：
                                         a. 调用 micro_exec run-llvmbpf (用户态)
                                         b. sudo micro_exec run-kernel (内核态)
                                         c. sudo micro_exec run-kernel --policy-file ... (重编译)
                                      8. 收集结果，计算统计量
                                      9. 写入 JSON 到 --rwdir 目录
                                     '
10. VM 退出                           ← VM 退出
11. 结果文件已在宿主机可见（共享目录）
```

---

## 9. 三层 Benchmark 模型设计理念

### 9.1 为什么需要三层？

三层模型对应不同的**测量目标**和**实验控制级别**：

```
              控制精度   现实程度   测量内容
┌──────────┐
│  Micro   │  最高      最低      纯 JIT 代码生成质量
│          │                      (isolate code generation)
├──────────┤
│  Corpus  │  中等      中等      真实程序的 JIT 性能影响
│          │                      (real BPF programs, isolated)
├──────────┤
│  E2E     │  最低      最高      应用层可观测的端到端性能
│          │                      (full application behavior)
└──────────┘
```

### 9.2 Micro 层：隔离 JIT 代码生成质量

**目标**：测量 JIT 编译器对特定计算模式生成的 native code 质量差异。

**实验控制**：
- 排除 BPF map 查找和 helper call 开销（纯 JIT 路径）
- 使用 staged input（预注入 packet buffer）消除运行时数据传递
- 使用 baseline subtraction 消除 harness 固定开销
- 交叉平衡运行时间顺序消除时间偏差
- 使用 TSC 指令精确计时

**适用场景**：
- 识别特定代码模式的优化机会（如 byte-recompose, CMOV, BEXTR）
- 测量单个优化变换的收益/回归
- 消融实验（逐一启用/禁用特定 form family）

**局限性**：
- 不能代表真实程序的综合行为
- 输入数据是合成的，可能不反映真实工作负载

### 9.3 Corpus 层：真实程序的隔离测量

**目标**：测量 JIT 重编译对真实开源 eBPF 程序的编译时间和执行时间影响。

**实验控制**：
- 使用真实的 BPF 程序（从上游项目编译）
- 使用 `bpf_prog_test_run_opts` 隔离执行（避免系统状态干扰）
- 通过 scanner enumerate 自动识别和应用优化站点

**适用场景**：
- 跨越不同域（网络、安全、可观测性）的综合评估
- 真实代码大小和指令分布下的性能表现
- Macro-level 的 geomean 指标（如"corpus exec geomean 1.046x"）

**局限性**：
- compile_only 程序只有编译时间数据
- 测试输入（dummy packet）可能不触发所有代码路径

### 9.4 E2E 层：应用级端到端性能

**目标**：测量 JIT 重编译对完整 eBPF 应用在实际工作负载下的性能影响。

**测量维度**：
- **BPF 运行时间**：各程序的 run_time_ns 变化
- **应用吞吐量**：工作负载的事件处理速率
- **系统开销**：CPU 使用率变化
- **重编译开销**：scanner 扫描时间 + syscall 时间

**适用场景**：
- 论文的"real-world impact"证据
- 展示端到端可测量的加速
- 验证 micro/corpus 层的预测是否在实际中成立

**当前数据（2026-03-14）**：
- Tracee exec_storm: **+6.28%** throughput improvement
- Tracee file_io: **+7.00%**
- Tracee network: **+1.44%**

### 9.5 三层之间的关系

```
Micro 发现                    Corpus 验证                   E2E 确认
─────────                    ─────────                     ─────────
byte-recompose               Calico wide_mem sites         Tracee BPF ns -4.22%
贡献 50.7% 的 gap            → exec 1.097x                → exec_storm +6.28%

CMOV 策略敏感                 Suricata cmov sites           应用级吞吐量改善
predictable: 0.482x          → exec 1.538x                需要 per-workload 策略选择
unpredictable: +28.3%

BEXTR without-copy fix        全 corpus 提升 3.8%           11/13 程序 recompile applied
extract_dense 0.556x          (1.008x → 1.046x)
```

---

## 10. 整体数据流图

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                            配置层                                           │
│                                                                             │
│  config/micro_pure_jit.yaml    corpus/config/macro_corpus.yaml              │
│  micro/policies/*.yaml         e2e/cases/*/config.yaml                      │
│  config/ablation/*.yaml                                                     │
└──────────────┬──────────────────────────────┬───────────────────────────────┘
               │                              │
               ▼                              ▼
┌──────────────────────────┐    ┌─────────────────────────────────┐
│    Makefile 顶层入口      │    │    各子系统的 Python 驱动         │
│                          │    │                                 │
│  make smoke              │    │  micro/driver.py suite          │
│  make vm-micro           │───▶│  micro/driver.py corpus v5-vm  │
│  make vm-corpus          │    │  e2e/run.py tracee/tetragon    │
│  make vm-e2e             │    │  ...                           │
│  make compare            │    │                                 │
└──────────┬───────────────┘    └────────┬─────────┬──────────────┘
           │                             │         │
           │                             ▼         ▼
           │              ┌──────────────────┐  ┌──────────────────────┐
           │              │ benchmark_catalog │  │  input_generators    │
           │              │ (YAML → dataclass)│  │  (生成 .mem 文件)    │
           │              └────────┬─────────┘  └──────────┬───────────┘
           │                       │                       │
           ▼                       ▼                       ▼
┌─────────────────────────────────────────────────────────────────────┐
│                         执行层                                       │
│                                                                     │
│  ┌───────────────────────────────────────────────────────────────┐  │
│  │                    vng (virtme-ng) VM                         │  │
│  │                                                               │  │
│  │  ┌─────────────────────┐    ┌──────────────────────────────┐ │  │
│  │  │     micro_exec      │    │    bpf-jit-scanner           │ │  │
│  │  │                     │    │                              │ │  │
│  │  │  run-llvmbpf:       │    │  scan: 单程序扫描            │ │  │
│  │  │    ELF → LLVM JIT   │    │  enumerate: 系统枚举扫描     │ │  │
│  │  │    → userspace exec │    │  generate-policy: 策略生成   │ │  │
│  │  │                     │    │  compile-policy: 策略编译    │ │  │
│  │  │  run-kernel:        │    │  apply: 扫描+应用            │ │  │
│  │  │    ELF → libbpf load│    │  dump: 字节码导出            │ │  │
│  │  │    → bpf_prog_test_ │    │                              │ │  │
│  │  │      run_opts       │    └──────────┬───────────────────┘ │  │
│  │  │                     │               │                     │  │
│  │  │  run-kernel +       │               │ directive blob      │  │
│  │  │  --recompile-v5:    │◄──────────────┘ (via memfd)        │  │
│  │  │    → BPF_PROG_JIT_  │                                     │  │
│  │  │      RECOMPILE(39)  │                                     │  │
│  │  └─────────┬───────────┘                                     │  │
│  │            │ JSON line per sample                             │  │
│  └────────────┼─────────────────────────────────────────────────┘  │
│               ▼                                                     │
│  ┌─────────────────────────────┐                                    │
│  │   Python 编排器 (results)   │                                    │
│  │                             │                                    │
│  │  parse_runner_sample()      │                                    │
│  │  ns_summary()               │                                    │
│  │  attach_baseline_adjustments│                                    │
│  └─────────────┬───────────────┘                                    │
└────────────────┼────────────────────────────────────────────────────┘
                 ▼
┌─────────────────────────────────────────────────────────────────────┐
│                         结果层                                       │
│                                                                     │
│  micro/results/                                                     │
│    ├── vm_micro.latest.json → vm_micro_authoritative_20260314.json  │
│    └── smoke.latest.json                                            │
│                                                                     │
│  corpus/results/                                                    │
│    ├── vm_corpus.latest.json                                        │
│    └── vm_corpus.latest.md                                          │
│                                                                     │
│  e2e/results/                                                       │
│    ├── tracee.latest.json                                           │
│    ├── tetragon.latest.json                                         │
│    └── xdp_forwarding.latest.json                                   │
│                                                                     │
│  docs/tmp/ (分析报告 .md only, 不含 JSON)                            │
│                                                                     │
│  ┌──────────────────────┐   ┌──────────────────┐                    │
│  │   compare_results.py │   │  summarize_rq.py │                    │
│  │   (A/B 对比)         │   │  (RQ 汇总报告)   │                    │
│  └──────────────────────┘   └──────────────────┘                    │
└─────────────────────────────────────────────────────────────────────┘
```

### 10.2 Micro 层完整数据流

```
                    config/micro_pure_jit.yaml
                              │
                    benchmark_catalog.load_suite()
                              │
                              ▼
                    ┌─────────────────┐
                    │   SuiteSpec      │
                    │   62 benchmarks │
                    │   3 runtimes    │
                    └────────┬────────┘
                             │
          ┌──────────────────┼──────────────────┐
          │                  │                  │
          ▼                  ▼                  ▼
  select_benchmarks()  select_runtimes()  materialize_input()
          │                  │                  │
          ▼                  ▼                  ▼
  [BenchmarkSpec...]  [RuntimeSpec...]   generated-inputs/*.mem
          │                  │                  │
          └──────────────────┼──────────────────┘
                             │
                             ▼
                  ┌───────────────────────┐
                  │   测量循环             │
                  │                       │
                  │  for benchmark:       │
                  │    for runtime:       │
                  │      warmup × N       │
                  │    for iteration:     │
                  │      [交叉平衡顺序]   │
                  │      for runtime:     │
                  │        micro_exec →   │
                  │        JSON sample    │
                  └───────────┬───────────┘
                              │
                              ▼
                  ┌───────────────────────┐
                  │   后处理              │
                  │                       │
                  │  ns_summary()         │
                  │  attach_baseline_     │
                  │    adjustments()      │
                  │  collect_provenance() │
                  └───────────┬───────────┘
                              │
                              ▼
                  ┌───────────────────────┐
                  │   输出                │
                  │                       │
                  │  xxx_authoritative_   │
                  │    YYYYMMDD.json      │
                  │  + .latest.json 链接  │
                  └───────────────────────┘
```

### 10.3 E2E 层数据流（以 Tracee 为例）

```
make vm-e2e
    │
    ▼
vng --run bzImage -- python3 e2e/run.py tracee
    │
    ▼
┌─────────────────────────────────────────┐
│  1. 运行 setup.sh 安装依赖              │
│  2. start_agent(tracee_binary)          │
│     → 加载 BPF 程序到内核               │
│  3. wait_healthy()                      │
│  4. find_bpf_programs()                 │
│     → 发现已加载的 BPF 程序 IDs         │
│                                         │
│  5. [BASELINE 阶段]                     │
│     enable_bpf_stats()                  │
│     sample_bpf_stats() → baseline_before│
│     run_exec_storm(duration=30s)        │
│     sample_bpf_stats() → baseline_after │
│     compute_delta(before, after)        │
│                                         │
│  6. [RECOMPILE 阶段]                    │
│     scan_programs(scanner, prog_ids)    │
│       → bpf-jit-scanner enumerate      │
│     apply_recompile(targets, policies)  │
│       → BPF_PROG_JIT_RECOMPILE syscall │
│                                         │
│  7. [RECOMPILE 测量阶段]                │
│     sample_bpf_stats() → recomp_before │
│     run_exec_storm(duration=30s)        │
│     sample_bpf_stats() → recomp_after  │
│     compute_delta(before, after)        │
│                                         │
│  8. 计算改善比例                         │
│     delta_ratio = recomp / baseline     │
│                                         │
│  9. stop_agent()                        │
│ 10. persist_results(json, md)           │
└─────────────────────────────────────────┘
```

---

## 附录：关键文件路径索引

| 组件 | 文件路径 |
|------|---------|
| 顶层 Makefile | `/home/yunwei37/workspace/bpf-benchmark/Makefile` |
| 项目指南 | `/home/yunwei37/workspace/bpf-benchmark/CLAUDE.md` |
| Micro 套件配置 | `/home/yunwei37/workspace/bpf-benchmark/config/micro_pure_jit.yaml` |
| Corpus 套件配置 | `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml` |
| 统一驱动入口 | `/home/yunwei37/workspace/bpf-benchmark/micro/driver.py` |
| Micro 核心编排 | `/home/yunwei37/workspace/bpf-benchmark/micro/_driver_impl_run_micro.py` |
| YAML 解析 | `/home/yunwei37/workspace/bpf-benchmark/micro/benchmark_catalog.py` |
| 输入生成器 | `/home/yunwei37/workspace/bpf-benchmark/micro/input_generators.py` |
| 结果布局 | `/home/yunwei37/workspace/bpf-benchmark/micro/results_layout.py` |
| RQ 汇总 | `/home/yunwei37/workspace/bpf-benchmark/micro/summarize_rq.py` |
| A/B 对比 | `/home/yunwei37/workspace/bpf-benchmark/micro/compare_results.py` |
| 命令构建 | `/home/yunwei37/workspace/bpf-benchmark/micro/orchestrator/commands.py` |
| 结果解析 | `/home/yunwei37/workspace/bpf-benchmark/micro/orchestrator/results.py` |
| Benchmark 选择 | `/home/yunwei37/workspace/bpf-benchmark/micro/orchestrator/benchmarks.py` |
| C++ Runner 入口 | `/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/main.cpp` |
| LLVM JIT Runner | `/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/llvmbpf_runner.cpp` |
| Kernel Runner | `/home/yunwei37/workspace/bpf-benchmark/micro/runner/src/kernel_runner.cpp` |
| BPF 程序公共头 | `/home/yunwei37/workspace/bpf-benchmark/micro/programs/common.h` |
| Corpus VM Batch | `/home/yunwei37/workspace/bpf-benchmark/corpus/_driver_impl_run_corpus_v5_vm_batch.py` |
| E2E 统一入口 | `/home/yunwei37/workspace/bpf-benchmark/e2e/run.py` |
| Tracee E2E Case | `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/case.py` |
| 重编译工具 | `/home/yunwei37/workspace/bpf-benchmark/e2e/common/recompile.py` |
| VM 工具 | `/home/yunwei37/workspace/bpf-benchmark/e2e/common/vm.py` |
| Scanner CLI | `/home/yunwei37/workspace/bpf-benchmark/scanner/src/cli.cpp` |
| Scanner Pattern V5 | `/home/yunwei37/workspace/bpf-benchmark/scanner/src/pattern_v5.cpp` |
| 计划文档 | `/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md` |
| 策略文件目录 | `/home/yunwei37/workspace/bpf-benchmark/micro/policies/` |
| 策略变体 | `/home/yunwei37/workspace/bpf-benchmark/micro/policies/variants/` |
