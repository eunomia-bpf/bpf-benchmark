# Benchmark Framework Analysis

Date: 2026-03-10

## §1 当前架构总览

### 1.1 结论摘要

当前 benchmark 框架不是“一套系统”，而是三层并行演化出来的组合体：

- 一套 declarative micro suite 体系：`benchmark_catalog.py` + `input_generators.py` + `run_micro.py`
- 一套 corpus / macro / v5 / rigorous 专项实验体系：9 个 `run_*.py` 各自带一部分 orchestration
- 一套 C++ 执行内核：`micro_exec` + `scanner/`，其中 `run-kernel` 已经同时承担 stock load、manual load、directive load、v4 recompile、v5 recompile、compile-only、JIT dump 等多种模式

这三层之间没有统一的 experiment model，也没有统一的 runtime / mode / result schema。结果是：

- 入口脚本多且重叠
- v4/v5 recompile 流程分裂在 Python、runner、scanner CLI 三处
- scanner 在构建上独立，在架构边界上不独立
- build 和产物管理没有收口，源码树长期被生成物污染

### 1.2 关键文件与 LOC

#### Python / YAML / Build 层

| 路径 | LOC | 当前职责 |
| --- | ---: | --- |
| `micro/run_micro.py` | 649 | micro suite 主编排器；构建、输入生成、llvmbpf/kernel 执行、结果汇总 |
| `micro/benchmark_catalog.py` | 181 | micro YAML 解析，仅支持 `micro_pure_jit.yaml` / `micro_runtime.yaml` 这套 schema |
| `micro/input_generators.py` | 1163 | micro 输入生成器注册表与落盘逻辑 |
| `config/micro_pure_jit.yaml` | 717 | pure-JIT suite；55 benchmarks |
| `config/micro_runtime.yaml` | 174 | runtime suite；11 benchmarks |
| `config/macro_corpus.yaml` | 226 | macro/corpus suite；13 programs，独立 schema |
| `micro/run_macro_corpus.py` | 1129 | macro corpus 主编排器；自带 YAML loader、libbpf / bpftool / scanner CLI 流程 |
| `micro/run_corpus_perf.py` | 946 | corpus stock vs `--recompile-all` 对比 |
| `micro/run_corpus_tracing.py` | 1020 | tracing attach/trigger 路径；部分复用 `run_corpus_perf.py` 内部 helper |
| `micro/cross_domain_census.py` | 386 | 跨域 census 报告脚本 |
| `micro/directive_census.py` | 1034 | Python 版 raw ELF scanner + object discovery |
| `micro/summarize_rq.py` | 442 | `run_micro.py` 风格 JSON 的 RQ 汇总 |
| `micro/generate_figures.py` | 747 | 论文图表脚本，依赖固定结果文件名与旧数据假设 |
| `micro/run_pass_ablation.py` | 666 | llvmbpf-only pass ablation driver |
| `micro/run_corpus_v5_framework.py` | 951 | 依赖既有 perf/tracing 结果的 40-program v5 framework driver |
| `micro/run_production_corpus_v5_framework.py` | 1322 | production corpus v5 driver |
| `micro/run_rigorous.py` | 1365 | publication-grade 本机严格实验 driver |
| `micro/run_rigorous_framework_vm.py` | 1013 | VM 版 rigorous driver；复用 `run_rigorous.py` 内部函数 |
| `micro/Makefile` | 78 | libbpf / runner / directive_hint / programs 的入口构建 |
| `micro/programs/Makefile` | 20 | `.bpf.c -> .bpf.o` 原地编译 |
| `micro/runner/CMakeLists.txt` | 76 | `micro_exec` 构建；把 `scanner/` 当 subdirectory vendor 进来 |
| `docs/tmp/benchmark-infrastructure-audit.md` | 1178 | 上一版审计；目前部分统计已过期 |

#### Runner / Scanner 层

| 路径 | LOC | 当前职责 |
| --- | ---: | --- |
| `micro/runner/include/micro_exec.hpp` | 164 | 共享类型、CLI option、result schema 声明 |
| `micro/runner/src/main.cpp` | 29 | `list-programs` / `run-llvmbpf` / `run-kernel` 分发 |
| `micro/runner/src/common.cpp` | 425 | 参数解析、文件读写、JSON 输出 |
| `micro/runner/src/kernel_runner.cpp` | 1164 | kernel 路径核心；manual load、scan、build blob、recompile、test_run、JIT dump |
| `micro/runner/src/llvmbpf_runner.cpp` | 724 | llvmbpf VM 路径 |
| `micro/runner/src/elf_program_loader.cpp` | 713 | ELF object program inventory / image load |
| `micro/runner/src/perf_counters.cpp` | 162 | perf_event 采样 |
| `scanner/CMakeLists.txt` | 117 | scanner library / CLI / tests 独立构建 |
| `scanner/README.md` | 142 | scanner 说明；已滞后于当前 layout |
| `scanner/include/bpf_jit_scanner/types.h` | 131 | v4 policy blob ABI / rule 常量 |
| `scanner/include/bpf_jit_scanner/scanner.h` | 127 | v4 低层扫描 C API |
| `scanner/include/bpf_jit_scanner/policy.h` | 73 | v4 blob build / patch API |
| `scanner/include/bpf_jit_scanner/engine.hpp` | 168 | v4 engine / registry / policy decision C++ API |
| `scanner/include/bpf_jit_scanner/pattern_v5.hpp` | 193 | v5 declarative pattern ABI / summary API |
| `scanner/src/scanner.cpp` | 648 | v4 matcher 实现 |
| `scanner/src/policy.cpp` | 116 | v4 blob build / patch 实现 |
| `scanner/src/engine.cpp` | 977 | v4 policy engine、feature extraction、arbitration |
| `scanner/src/pattern_v5.cpp` | 920 | v5 declarative descriptor、match、blob build |
| `scanner/src/cli.cpp` | 702 | scanner CLI；scan/apply/dump |
| `scanner/tests/test_scanner.cpp` | 394 | scanner 单测 |

### 1.3 入口脚本现状

当前一共有 9 个 benchmark 执行入口脚本：

| 入口 | 主要职责 | 是否与其它脚本重叠 |
| --- | --- | --- |
| `run_micro.py` | declarative micro suites | 是 |
| `run_macro_corpus.py` | declarative macro corpus | 是 |
| `run_corpus_perf.py` | corpus perf stock vs v4 all | 是 |
| `run_corpus_tracing.py` | tracing attach/trigger | 是 |
| `run_pass_ablation.py` | llvmbpf pass ablation | 是 |
| `run_corpus_v5_framework.py` | 40-program fixed union on framework kernel | 是 |
| `run_production_corpus_v5_framework.py` | production corpus v5 | 是 |
| `run_rigorous.py` | strict local experiment harness | 是 |
| `run_rigorous_framework_vm.py` | VM strict harness | 是 |

重叠最明显的公共动作包括：

- build runner / programs
- 发现 program inventory
- 选择 benchmark / runtime / mode
- materialize dummy packet / context
- 组装 `micro_exec` 命令
- 解析 runner JSON
- 汇总 JSON / Markdown
- host metadata、phase timing、error summarization

### 1.4 当前依赖关系图

```text
config/micro_pure_jit.yaml
config/micro_runtime.yaml
        │
        ▼
micro/benchmark_catalog.py ─────────────┐
        │                               │
        ├──► micro/run_micro.py         │
        ├──► micro/run_pass_ablation.py │
        └──► micro/run_rigorous.py ─────┴──► micro/run_rigorous_framework_vm.py

micro/input_generators.py ──────────────┬──► micro/run_micro.py
                                        ├──► micro/run_pass_ablation.py
                                        └──► micro/run_rigorous.py

config/macro_corpus.yaml ───────────────► micro/run_macro_corpus.py

micro/directive_census.py ──────────────┬──► micro/run_corpus_perf.py ───► micro/run_corpus_tracing.py
                                        ├──► micro/cross_domain_census.py
                                        └──► micro/run_production_corpus_v5_framework.py

docs/tmp/corpus-perf-results.json
docs/tmp/corpus-tracing-results.json ───► micro/run_corpus_v5_framework.py

all run_*.py drivers ───────────────────► micro/build/runner/micro_exec
                                          │
                                          ├──► run-llvmbpf ─► llvmbpf_runner.cpp
                                          ├──► list-programs ─► elf_program_loader.cpp
                                          └──► run-kernel ─► kernel_runner.cpp
                                                             │
                                                             ├──► scanner.h / policy.h (v4)
                                                             └──► pattern_v5.hpp (v5)

scanner CLI (bpf-jit-scanner) ──────────► engine.cpp / scanner.cpp / policy.cpp / pattern_v5.cpp

run_macro_corpus.py / run_production_corpus_v5_framework.py
在部分路径下直接调用 scanner CLI，而不是只经由 micro_exec。
```

### 1.5 Suite、generator、对象覆盖

- `micro_pure_jit.yaml`: 55 benchmarks
- `micro_runtime.yaml`: 11 benchmarks
- `macro_corpus.yaml`: 13 programs
- `micro/programs/*.bpf.c`: 66
- `micro/programs/*.bpf.o`: 66
- `input_generators.py` 注册 generator: 68
- 当前 suite 实际使用 generator: 64
- 孤儿 generator: 4 个
  - `branch_fanout_32_predictable`
  - `branch_fanout_32_random`
  - `branch_layout_predictable`
  - `branch_layout_random`

当前配置覆盖是完整的：我没有发现 YAML 中引用了不存在的 generator，也没有发现 `micro/programs/*.bpf.c` 完全游离于 `micro_pure_jit.yaml + micro_runtime.yaml` 之外。

### 1.6 v4 / v5 recompile 代码到底在哪里

结论先行：

- 控制入口在 Python drivers，但真正的 benchmark 执行与 `BPF_PROG_JIT_RECOMPILE` 调用在 `micro/runner/src/kernel_runner.cpp`
- v4 matcher 已经在 `scanner/src/scanner.cpp`
- v5 declarative pattern / blob build 已经在 `scanner/src/pattern_v5.cpp`
- 但是 runner 并没有通过一个统一的 scanner runtime API 来使用它们，而是直接 include 多个 scanner 头文件并手动拼流程

更具体地说：

- v4 路径：
  - `run_rigorous.py` 等脚本通过 `--recompile-cmov` / `--recompile-wide` / `--recompile-rotate` / `--recompile-lea` / `--recompile-all` 驱动
  - `kernel_runner.cpp` 读取 xlated bytecode，直接调用 `bpf_jit_scan_cmov/wide_mem/rotate/addr_calc`
  - 然后在 runner 内调用 `bpf_jit_build_policy_blob`
  - 最后 runner 内直接发 `BPF_PROG_JIT_RECOMPILE`

- v5 路径：
  - `run_rigorous.py`、`run_macro_corpus.py`、`run_corpus_v5_framework.py`、`run_production_corpus_v5_framework.py` 通过 `--recompile-v5` 或 scanner CLI `--v5` 驱动
  - `kernel_runner.cpp` 直接调用 `bpf_jit_scanner::scan_v5_builtin()` 和 `build_policy_blob_v5()`
  - 然后仍然由 runner 自己发 `BPF_PROG_JIT_RECOMPILE`
  - 另一方面，`run_macro_corpus.py` 和 scanner CLI 也各自维护了一套“抓 live prog xlated -> 建 memfd -> 调 recompile syscall”的流程

所以答案是：

- v4/v5 benchmark recompile 不是独立模块，也不只在 Python
- 它们的 matcher / blob builder 分散在 `scanner/`
- 但 benchmark runner 的执行控制流仍然牢牢在 `kernel_runner.cpp`
- 它们目前是“多套分支”，不是“同一个 recompile abstraction 的两种 mode”

### 1.7 scanner 库现状

`scanner/` 现在是“构建上独立、架构上半独立”的状态。

已经独立的部分：

- 有自己的 `CMakeLists.txt`
- 可以单独 build library / CLI / tests
- 提供低层 C API、较高层 v4 policy engine、v5 declarative pattern API
- 有安装规则和 package config

没有独立干净的部分：

- `micro_exec` 不是只依赖 scanner 的一个高层入口，而是直接 include `scanner.h`、`policy.h`、`pattern_v5.hpp`
- `kernel_runner.cpp` 仍自己负责 live-program fetch、memfd、blob 应用、recompile syscall
- `scanner/src/cli.cpp` 又复制了一遍同样的逻辑
- `engine.cpp` 内部对 raw insn 的 parse / feature extraction 和 `scanner.cpp` 的 matcher helpers 有明显重叠
- `scanner/README.md` 的 layout 已经没写 `pattern_v5.hpp/.cpp`

### 1.8 构建与产物现状

当前构建不是统一 build graph，而是三层拼接：

- `micro/Makefile` 负责编译 libbpf、programs、runner、directive_hint
- `micro/runner/CMakeLists.txt` 再把 `scanner/` 当 subdirectory vendor 进来
- `scanner/` 同时保留自己的独立 CMake build

这导致几个具体事实：

- `micro/Makefile all` 不构建 `vendor_bpftool`，但 `run_macro_corpus.py` / corpus 路径又依赖 `bpftool`
- `directive_hint` 不是复用 CMake target，而是手工把 `common.cpp`、`elf_program_loader.cpp` 再编一遍
- `micro/programs/Makefile` 把 `*.bpf.o` 和 `*.bpf.d` 原地写回源码目录
- `micro/Makefile clean` 不清 `micro/jit-dumps/`
- `micro/programs/Makefile clean` 不清 `*.directive.bin` / `*.policy.bin`
- `scanner/build/` 长期存在于源码树中，并且混有两代 CMake 元数据

当前可见的源码树生成物数量：

- `micro/generated-inputs/*.mem`: 64
- `micro/generated-inputs/*.directive.bin`: 4
- `micro/jit-dumps/*`: 133
- `micro/programs/*.bpf.o`: 66
- `micro/programs/*.bpf.d`: 66
- `micro/programs/*.directive.bin`: 5
- `micro/programs/*.policy.bin`: 2
- `micro/results/*.json`: 29
- `scanner/build/**`: 26 个条目

## §2 问题清单

### P0: 编排入口已经失控，系统边界是“脚本级复制”而不是“模块级复用”

表现：

- 9 个 `run_*.py` 入口都在做 orchestration，而且不是薄 wrapper
- `run_corpus_tracing.py` 直接 import `run_corpus_perf.py` 的内部 helper
- `run_rigorous_framework_vm.py` 直接 import `run_rigorous.py` 的内部 helper
- `run_macro_corpus.py` 完整重写了一套 YAML loader / runtime selection / inventory / result aggregation

后果：

- 同一实验动作在不同脚本里有不同语义
- 任一新 mode 都会诱发“复制一个新 driver”
- 很难保证结果 schema、错误处理、环境校验、artifact 命名一致

### P0: recompile 流程被拆成 runner 分支、scanner 库、scanner CLI、Python 旁路四套实现

表现：

- v4 在 `scanner.cpp`，v5 在 `pattern_v5.cpp`
- `kernel_runner.cpp` 直接调用它们并自己发 `BPF_PROG_JIT_RECOMPILE`
- `scanner/src/cli.cpp` 自己也做 live-program fetch / blob apply / recompile syscall
- `run_macro_corpus.py` 和 `run_production_corpus_v5_framework.py` 在部分路径直接调用 scanner CLI
- `run_corpus_tracing.py` 明确写着目前只做 compile-only probe，attached re-JIT + re-measure 没实现

后果：

- 同名“v5”实验在不同入口下不一定代表同一个执行语义
- scanner 无法成为唯一 policy authority
- 一旦 kernel ABI、blob version 或 site arbitration 变化，需要同时改多处

### P0: 配置模型没有统一，micro 和 macro 已经是两套不同语言

表现：

- `benchmark_catalog.py` 只认识 micro schema
- `macro_corpus.yaml` 由 `run_macro_corpus.py` 自己解析
- `macro_corpus.yaml` 的 `corpus:` 顶层块目前没有真正被消费
- `run_corpus_v5_framework.py` 甚至不依赖 declarative config，而是依赖已有结果文件构造 40-program union

后果：

- 无法用一个统一 driver 表达“backend + mode + transport + workload kind”
- suite 之间不能共享 validation、defaults、result schema
- config 难以演化成论文/实验唯一真相源

### P1: `kernel_runner.cpp` 已经是明显的“万能文件”

表现：

- 1164 LOC
- 同时承担：
  - host compatibility shim
  - manual `BPF_PROG_LOAD`
  - map 创建与 relocation
  - directive memfd / policy memfd
  - xlated / jited dump
  - v4/v5 scan 与 blob generation
  - `BPF_PROG_JIT_RECOMPILE`
  - `bpf_prog_test_run_opts`
  - phase timing / perf capture / result extraction

后果：

- 任何新 mode 都只能继续往 `run-kernel` 塞 flag 和 branch
- 很难做 unit test
- runner 代码审查成本过高

### P1: `micro_exec` 的 CLI 和结果 schema 都在膨胀，而且是手写解析 / 手写 JSON

表现：

- `micro_exec.hpp` 的 `cli_options` 里有一串 `recompile_*` 布尔变量
- `common.cpp` 用手写 parser 维护所有选项关系
- `common.cpp` 用手写 `print_json()` 维护 result schema

后果：

- flag explosion 继续发生
- result schema 变更难以追踪
- Python 端解析与 C++ 端输出耦合太紧

### P1: scanner 虽然单独成库，但还没有成为真正的“唯一策略边界”

表现：

- `micro_exec` 仍直接 include 低层 matcher 和 v5 pattern 头文件
- CLI 和 runner 都保留 recompile apply 逻辑
- `engine.cpp` 与 `scanner.cpp` 对 raw insn 解析 / 站点特征有重复
- README 已过时

后果：

- scanner 的独立性只停留在 build packaging
- policy 行为不容易收口
- v4 engine 与 v5 路径没有统一抽象层

### P1: Python 版 static census 已经和 scanner 实现分叉，并且包含 stale 常量

表现：

- `directive_census.py` 重写了 `scan_cmov` / `scan_wide_mem` / `scan_rotate` / `scan_addr_calc`
- `cross_domain_census.py` 通过 `sys.path.insert` 当内部库来用
- `directive_census.py` 仍假设 micro object 数应为 62，但仓库当前已有 66

后果：

- census 统计和真正 runner/scanner 用的 matcher 可能分叉
- 任何 pattern 变更都要手改 Python 复制实现

### P1: 构建与输出管理不正确，生成物长期散落在源码目录

表现：

- `micro/programs/*.bpf.o`, `*.bpf.d`, `*.directive.bin`, `*.policy.bin` 原地落盘
- `micro/generated-inputs/*.mem` 原地落盘
- `micro/jit-dumps/*.asm/.bin/.log` 原地落盘
- `scanner/build/` 常驻源码树
- `micro/results/*.json`、`docs/tmp/*.json/.md` 混合 scratch 和 authoritative outputs
- clean 规则不完整

后果：

- 仓库状态噪音大
- 很难区分源码、缓存、实验输出、可复现结果
- 也不利于 CI 和 artifact retention

### P1: 下游消费者已经和真实数据集脱节

表现：

- `micro/README.md` 仍写 `micro_pure_jit: 29`、`micro_runtime: 5`
- `generate_figures.py` 仍默认读取 “31-benchmark authoritative JSON”
- `summarize_rq.py` 默认输入是 `micro/results/latest.json`，而 suite 默认输出是 `pure_jit.latest.json` / `runtime.latest.json`
- `docs/tmp/benchmark-infrastructure-audit.md` 中部分统计已过期

后果：

- 文档、图表、结果汇总不再与当前 suite 对齐
- 实验产物容易被误解或误引用

### P2: `benchmark_catalog.py` 和 `input_generators.py` 质量还能再提高

表现：

- `benchmark_catalog.py` 在 import 时直接 `load_suite()`
- runtime / benchmark 通过 dict comprehension 构造，重复名会静默覆盖
- 没有 schema validation
- `input_generators.py` 1163 LOC 单文件
- cache hit 时 `materialize_input()` 返回空 metadata，provenance 丢失
- 4 个孤儿 generator 尚未收敛

后果：

- catalog 很难扩展到 macro / corpus / VM / mode matrix
- 输入生成 provenance 不完整
- generator registry 的维护成本继续上升

### P2: suite 语义存在轻微漂移

表现：

- `micro_pure_jit.yaml` 中混入 `tc_bitcount`、`tc_checksum`、`cgroup_hash_chain` 这类 `kernel-only` / `non-xdp` breadth checks
- 但 suite 默认 runtime 仍是 `[llvmbpf, kernel]`

后果：

- “pure-JIT suite” 的语义已经不是单纯 staged XDP 微基准
- 后续如果再继续混入 kernel-only case，runtime 可比性会越来越弱

## §3 重构方案

### 3.1 目标架构

目标不是“再写一个新 driver”，而是把现有系统收敛成：

- 一个统一 Python driver
- 一套统一 manifest schema
- 一个共享 orchestration library
- 一个更薄的 C++ runner
- 一个真正拥有 policy ownership 的 scanner 库

建议的分层是：

```text
config/*.yaml
    │
    ▼
micro/orchestrator/
  catalog.py
  targets.py
  inputs.py
  runtimes.py
  execution.py
  environment.py
  results.py
  reporting.py
    │
    ▼
micro/driver.py  (唯一入口，子命令/模式化 CLI)
    │
    ├──► micro_exec
    ├──► scanner CLI / scanner API
    └──► bpftool / vng / libbpf helpers

micro_exec
    │
    ├──► llvmbpf backend
    └──► kernel backend
             │
             └──► scanner runtime API
```

### 3.2 统一编排入口

建议新增：

- `micro/driver.py`

建议保留但降级为兼容 wrapper：

- `micro/run_micro.py`
- `micro/run_macro_corpus.py`
- `micro/run_pass_ablation.py`
- `micro/run_rigorous.py`
- `micro/run_rigorous_framework_vm.py`

建议逐步退役：

- `micro/run_corpus_perf.py`
- `micro/run_corpus_tracing.py`
- `micro/run_corpus_v5_framework.py`
- `micro/run_production_corpus_v5_framework.py`

统一后的 CLI 形态建议是：

- `python micro/driver.py suite --config config/micro_pure_jit.yaml`
- `python micro/driver.py suite --config config/micro_runtime.yaml`
- `python micro/driver.py suite --config config/macro_corpus.yaml`
- `python micro/driver.py ablation ...`
- `python micro/driver.py rigorous ...`
- `python micro/driver.py census ...`

核心要求：

- 所有 mode 都复用同一套 build / selection / command assembly / result normalization / artifact naming
- “micro vs macro vs corpus vs VM” 不再决定入口脚本，只决定 target kind、transport 和 runtime matrix

### 3.3 统一 manifest schema

建议把 `benchmark_catalog.py` 升级为统一 manifest loader，或者迁移为新模块：

- `micro/orchestrator/catalog.py`
- `micro/orchestrator/schema.py`

统一 schema 需要能表达 4 个正交维度：

- target
  - micro benchmark
  - macro corpus object/program
  - attach/trigger workload
  - compile-only workload
- backend
  - `llvmbpf`
  - `kernel`
- policy mode
  - `stock`
  - `directive_blob`
  - `policy_blob`
  - `recompile_v4`
  - `recompile_v5`
- transport / environment
  - `local`
  - `vm`

建议把当前两套 schema 收敛为一个 `targets:` 顶层数组，而不是 `benchmarks:` / `programs:` 分裂。

建议新增字段：

- `kind: micro|macro|corpus`
- `backend`
- `policy_mode`
- `families: [cmov, wide, rotate, lea]`
- `transport: local|vm`
- `discovery`
- `program_selector`
- `artifacts`
- `expected_capabilities`

同时要补上：

- schema validation
- duplicate name detection
- alias collision detection
- manifest versioning

### 3.4 把共享 Python 逻辑抽成库，而不是脚本互相 import

建议新增目录：

- `micro/orchestrator/__init__.py`
- `micro/orchestrator/catalog.py`
- `micro/orchestrator/inputs.py`
- `micro/orchestrator/inventory.py`
- `micro/orchestrator/commands.py`
- `micro/orchestrator/results.py`
- `micro/orchestrator/environment.py`
- `micro/orchestrator/corpus.py`
- `micro/orchestrator/reporting.py`

迁移建议：

- 从 `run_micro.py` 抽出 suite execution skeleton
- 从 `run_macro_corpus.py`、`run_corpus_perf.py`、`run_corpus_tracing.py`、`run_corpus_v5_framework.py`、`run_production_corpus_v5_framework.py` 抽出：
  - inventory discovery
  - dummy packet/context materialization
  - runner JSON parsing
  - stderr summarization
  - phase summary aggregation
- 从 `run_rigorous.py` 抽出：
  - environment validation
  - CPU pinning / governor / turbo controls
  - statistical postprocessing
- `run_rigorous_framework_vm.py` 不再 import `run_rigorous.py` 内部函数，而是调用共享模块

### 3.5 简化并收口 `input_generators.py`

建议拆分：

- `micro/input_generators.py` -> `micro/inputs/`
- `micro/inputs/common.py`
- `micro/inputs/micro.py`
- `micro/inputs/runtime.py`
- `micro/inputs/corpus.py`

建议改动：

- `materialize_input()` 统一返回 provenance，即使命中缓存也返回 metadata
- generator registry 改成显式 dataclass 注册，而不是超长字典
- 为孤儿 generator 增加状态：
  - 纳入 suite
  - 明确废弃
  - 删除
- corpus dummy packet/context 不再在 4 个脚本里重复实现，统一下沉到 `inputs/corpus.py`

### 3.6 让 scanner 真正拥有 policy ownership

建议新增 scanner 高层 runtime API，而不是让 runner 和 CLI 各写一套 apply 流程：

- `scanner/include/bpf_jit_scanner/runtime.hpp`
- `scanner/src/runtime.cpp`

这个 API 至少应统一：

- dump xlated from prog fd
- v4 scan + decision + materialize
- v5 scan + materialize
- patch / seal memfd
- apply `BPF_PROG_JIT_RECOMPILE`

然后：

- `kernel_runner.cpp` 只依赖这个 runtime API
- `scanner/src/cli.cpp` 也只依赖这个 runtime API
- Python drivers 不再直接拼 scanner apply 细节

这样能把现在分裂的逻辑收回来：

- runner 的 recompile apply
- scanner CLI 的 recompile apply
- macro / production drivers 的 scanner CLI 旁路

### 3.7 拆分 C++ runner

建议目标结构：

- `micro/runner/include/micro_exec_cli.hpp`
- `micro/runner/include/micro_exec_result.hpp`
- `micro/runner/include/kernel_loader.hpp`
- `micro/runner/include/kernel_recompile.hpp`
- `micro/runner/include/kernel_exec.hpp`
- `micro/runner/src/cli.cpp`
- `micro/runner/src/result_json.cpp`
- `micro/runner/src/kernel_loader.cpp`
- `micro/runner/src/kernel_recompile.cpp`
- `micro/runner/src/kernel_exec.cpp`
- `micro/runner/src/kernel_compat.hpp`

对应拆法：

- `common.cpp`
  - CLI parser -> `cli.cpp`
  - JSON serializer -> `result_json.cpp`
  - file utils 可保留在 `common_io.cpp`
- `kernel_runner.cpp`
  - manual load / map relocation -> `kernel_loader.cpp`
  - scan/build/apply policy -> `kernel_recompile.cpp`
  - `bpf_prog_test_run_opts` / result extraction -> `kernel_exec.cpp`
  - missing UAPI constants / local structs -> `kernel_compat.hpp`

同时把 option 结构从 flag explosion 改成更稳定的组合：

- `backend = llvmbpf | kernel`
- `policy_mode = none | directive_blob | policy_blob | auto_v4 | auto_v5`
- `families = bitset`
- `execution_mode = run | compile_only | dump_only`

### 3.8 统一结果 schema

当前至少存在三类结果 schema：

- `run_micro.py` 风格
- corpus / macro 各自的 ad hoc schema
- strict / rigorous 的统计型 schema

建议统一为一个 core schema：

- `suite`
- `manifest`
- `host`
- `target`
- `backend`
- `policy_mode`
- `transport`
- `inventory`
- `artifacts`
- `compile`
- `execution`
- `directive_scan`
- `recompile`
- `perf_counters`
- `samples`

然后在 reporting 层派生：

- RQ summary
- figures
- corpus markdown
- rigorous statistics

这样 `summarize_rq.py` 和 `generate_figures.py` 就不需要盯死旧文件名和旧 suite 名。

### 3.9 收敛静态 census 路径

建议不要继续维护 Python matcher 的平行实现。

有两种可行方向：

- 方向 A：`directive_census.py` 改成离线调用 scanner CLI，对 xlated dump 扫描
- 方向 B：给 scanner 提供稳定 JSON 输出后，Python 只负责汇总，不负责匹配

我更推荐方向 A，因为：

- 不需要再维护 Python 版 pattern 逻辑
- census 与 benchmark runner 用的是同一套 scanner 代码
- v5 也能自然纳入，而不是只支持 Python 手写的 v4 风格规则

### 3.10 收敛 build graph 与 artifact 目录

建议目标：

- 单一顶层 build root，例如 `build/`
- programs 输出到 `build/micro/programs/`
- runner 输出到 `build/micro/runner/`
- scanner standalone 输出到 `build/scanner/`
- generated inputs / dumps / scratch results 输出到 `build/artifacts/` 或 `out/`

文件级建议：

- 保留 `micro/programs/*.bpf.c` 源码
- 修改 `micro/programs/Makefile`，输出目录改为 `micro/build/programs/` 或仓库顶层 `build/micro/programs/`
- 修改 `micro/Makefile` clean 规则，补清：
  - `micro/generated-inputs/*`
  - `micro/jit-dumps/*`
  - `micro/programs/*.directive.bin`
  - `micro/programs/*.policy.bin`
  - `scanner/build/`
  - `docs/tmp/*results*.json`
- 最终更推荐用顶层 `CMakeLists.txt` 或顶层 `Makefile` 统一驱动 scanner + runner + programs

## §4 推荐的清理步骤

下面这些步骤可以立即执行，而且不需要先做大规模功能重写。

### Step 1: 先冻结入口，不再新增新的 `run_*.py`

- 明确 `run_micro.py` 为当前唯一可继续演化的主入口
- 其它脚本进入“只修 bug，不扩功能”状态
- 新实验只能在共享模块或统一 driver 中增加 mode，不能再复制新脚本

### Step 2: 先把生成物移出源码树

- 修改 `micro/programs/Makefile`，让 `.bpf.o/.bpf.d` 输出到 build 目录
- 修改输入生成和 JIT dump 默认输出目录
- 删除长期驻留的 `scanner/build/`
- 补齐 clean 规则，至少覆盖目前已观测到的 64 `.mem`、133 `jit-dumps`、66 `.bpf.o`、66 `.bpf.d`

### Step 3: 修掉最明显的 stale metadata

- 更新 `micro/README.md` 中的 benchmark 数量
- 更新 `directive_census.py` 中 `expected 62 micro object paths`
- 更新 `generate_figures.py` 中 “31-benchmark authoritative JSON” 假设
- 更新 `summarize_rq.py` 默认输入路径与 suite 名判断
- 把 `docs/tmp/benchmark-infrastructure-audit.md` 标记为 superseded

### Step 4: 先做“共享 Python 库抽取”，再删脚本

- 把 inventory / command building / dummy input / JSON parsing 先抽到 `micro/orchestrator/`
- 让 `run_corpus_tracing.py`、`run_rigorous_framework_vm.py` 不再 import 其它脚本内部函数
- 等 wrapper 全部变薄后，再退役 legacy 脚本

### Step 5: 先让 scanner 成为唯一 recompile apply 实现

- 抽出 scanner runtime API
- `kernel_runner.cpp` 改为只调用 scanner runtime API
- `scanner/src/cli.cpp` 也调用同一个 API
- 删除 runner / CLI 两边重复的 memfd + syscall 代码

### Step 6: 再统一 manifest schema

- 先让 `benchmark_catalog.py` 支持 versioned schema 和 validation
- 再把 `macro_corpus.yaml` 收进同一 loader
- 最后把结果文件驱动的 `run_corpus_v5_framework.py` 替换成 manifest 驱动

### Step 7: 最后处理 runner 拆分

- 这一步风险最大，但收益也最高
- 前面几步做完后，`kernel_runner.cpp` 的职责边界会自然变清楚
- 届时再拆 `kernel_loader / kernel_recompile / kernel_exec`

## 附：我认为最值得优先做的三件事

1. 收敛入口：先建统一 `micro/driver.py` 和 `micro/orchestrator/`
2. 收敛 policy ownership：scanner 提供唯一 recompile runtime API
3. 收敛 artifact：所有生成物移出源码树

这三件事做完，现有 benchmark 框架就会从“脚本集合”变成“可维护系统”。其余问题，包括 schema 统一、rigorous/VM 合流、图表/RQ 修复，都会变成顺手工程，而不是体系级阻塞。
