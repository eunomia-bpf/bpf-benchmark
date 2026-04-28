# BpfReJIT 全项目架构审查与论文差距分析

审查日期：2026-03-22  
审查对象：BpfReJIT 项目当前工作树  
说明：本文中的代码引用均基于当前 checkout 的行号；结论来自静态审查、轻量本地测试和项目计划文档，不包含一次完整的 VM benchmark 重跑。

## 审查方法

已阅读 `docs/kernel-jit-optimization-plan.md`，并重点审阅了以下路径：

- `daemon/src/`
- `runner/`
- `micro/`
- `corpus/`
- `e2e/`
- `module/`
- `tests/`

本次还实际执行了以下检查：

- `cargo test --manifest-path daemon/Cargo.toml`：通过，196 tests passed
- `cargo clippy --manifest-path daemon/Cargo.toml --all-targets -- -W dead_code -W unused_imports -W clippy::all`：通过，但仍有 11 个 bin warning / 15 个 test warning

未在本轮重新执行完整 corpus/e2e/VM 实验，因此性能结论以 `docs/kernel-jit-optimization-plan.md` 中的权威数据行为准。

## 一、执行摘要

我的总体判断是：**BpfReJIT 已经具备“可发表系统原型”的雏形，但离 OSDI'26 水准的完整系统论文还有明显距离；当前最大的差距不是工程 polish，而是论文主张与证据之间的结构性不匹配。**

最关键的结论有五条：

1. **论文主张过强，现有数据支撑不足。** 计划文档摘要把系统定位为“transparent, runtime-guided specialization”的动态框架，并在摘要中写出“up to 40% performance improvement, 50% reduction in binary size, negligible overhead”（`docs/kernel-jit-optimization-plan.md:4-5`, `docs/kernel-jit-optimization-plan.md:24`）。但当前权威数据同时给出了 micro 正收益与 corpus 负收益并存的现实：micro v2 geomean 为 `1.153x`，而 corpus blind/fixed geomean 分别只有 `0.868x`/`0.875x`，且回归明显多于收益（`docs/kernel-jit-optimization-plan.md:172`, `docs/kernel-jit-optimization-plan.md:181-185`）。
2. **runtime-guided/PGO 故事没有闭环。** 计划文档强调 runtime-guided specialization（`docs/kernel-jit-optimization-plan.md:4-5`, `docs/kernel-jit-optimization-plan.md:36`），但 daemon 里的 PGO 仍停留在基础设施层：`profiler.rs` 只轮询 `run_cnt/run_time_ns`（`daemon/src/profiler.rs:4-6`），`BranchFlipPass` 明确是 PGO-only 且无启发式回退（`daemon/src/passes/branch_flip.rs:119-136`），`PassManager::run_with_profiling()` 甚至仍是 `#[allow(dead_code)]` 的未接线接口（`daemon/src/pass.rs:542-558`）。
3. **安全加固主张目前不成立。** 计划文档将 Spectre 缓解列为安全加固卖点，并声称需要插入 `lfence`（`docs/kernel-jit-optimization-plan.md:205-211`），但真实实现只是插入 `JA +0` 占位 NOP，并在源码里明确写着“NOT a real speculation barrier”（`daemon/src/passes/spectre.rs:9-17`）。测试也在验证这个占位行为，而不是真正的 barrier 语义（`tests/unittest/rejit_spectre.c:5-17`, `tests/unittest/rejit_spectre.c:152-153`）。
4. **工程边界不清，评测层代码耦合严重。** runner/core 被 Katran 等个案逻辑污染，micro/corpus/e2e 三层各自维护大体相似但不共享的 orchestration；这不只是“代码不优雅”，而是会直接削弱论文里“通用、透明、可扩展”的说服力。
5. **module 层存在会阻塞投稿的正确性问题。** `bpf_extract64()` 在 `len == 64` 时存在 UB（`module/x86/bpf_extract.c:42-49`, `module/arm64/bpf_extract.c:58-65`），`bpf_rotate64()` 在 `shift == 0` 时存在 UB（`module/x86/bpf_rotate.c:30-34`, `module/arm64/bpf_rotate.c:45-49`），更严重的是 ARM64 与 x86 对同名 `bpf_rotate64` 的语义并不一致（`module/arm64/bpf_rotate.c:17-22`, `module/arm64/bpf_rotate.c:91-115`）。

如果今天必须判断是否“可以按当前叙事提交 OSDI'26”，我的结论是：**不建议。**  
如果时间紧张，当前系统更适合收缩成一篇强调“最小 kernel interface + in-place REJIT 机制”的论文；如果坚持“动态、透明、runtime-guided optimization framework”的完整叙事，则必须先补齐 P0 级缺口。

## 二、项目整体状态评估

### 2.1 与项目目标的对齐情况

从 `docs/kernel-jit-optimization-plan.md` 看，项目目标是明确而雄心勃勃的：

- 要证明一个“最小内核接口 + 用户态 daemon”可以把 eBPF 从一次性静态编译推进到可在线、透明、runtime-guided specialization（`docs/kernel-jit-optimization-plan.md:4-5`）。
- 要证明真实程序上的“可测量加速”和“安全加固能力”（`docs/kernel-jit-optimization-plan.md:4-5`）。
- 要遵守“Mandatory Falsification”：如果固定 kernel heuristic 就能恢复同样收益，则不应发布 userspace-guided interface（`docs/kernel-jit-optimization-plan.md:159`）。
- 要有两种 daemon 运行模式，其中 `watch` 是 production 目标（`docs/kernel-jit-optimization-plan.md:162`）。

从实现看，系统已经具备以下坚实基础：

- kernel 接口方向是清晰的：`BPF_PROG_REJIT` + `orig_prog_insns` + userspace raw syscall daemon，与计划文档叙事高度一致（`docs/kernel-jit-optimization-plan.md:154-160`；`daemon/src/bpf.rs:270-295`）。
- daemon pass framework 的基础结构是成型的，并且单元测试不少；本轮 `cargo test` 通过 196 个测试。
- kernel-side REJIT 测试覆盖面不错，尤其是 program type 覆盖（`tests/unittest/rejit_prog_types.c:3-11`）。

但和论文目标的关键错位同样明显：

- **“transparent, runtime-guided”** 只完成了“transparent REJIT interface”和部分 pass framework，真正的 runtime-guided decision loop 没有跑通。
- **“real-program speedup”** 目前只在 micro 层有正面故事，corpus 层反而是负面故事。
- **“security hardening”** 仍停留在 placeholder。
- **“production daemon mode”** 在文档中仍写着 `watch` 待实现（`docs/kernel-jit-optimization-plan.md:162`），但代码里已经暴露了 `Watch` 和 `Serve` 子命令（`daemon/src/main.rs:60-76`）；这说明项目对“什么叫完成”本身还没有统一标准。

### 2.2 距离 OSDI'26 的核心差距

| 维度 | 当前状态 | 关键证据 | 对投稿的影响 |
|---|---|---|---|
| 机制新颖性 | kernel interface 思路强，userspace daemon + REJIT 有系统味道 | `docs/kernel-jit-optimization-plan.md:153-160` | 正面，但需要更干净地证明“为什么不是 kernel peephole” |
| 运行时自适应 | 基础设施有，闭环没有 | `daemon/src/profiler.rs:4-6`, `daemon/src/pass.rs:542-558`, `daemon/src/passes/branch_flip.rs:119-136`, `daemon/README.md:199-202` | 直接削弱核心卖点 |
| 真实性能 | micro 有收益，corpus 为净回归 | `docs/kernel-jit-optimization-plan.md:172`, `docs/kernel-jit-optimization-plan.md:181-185` | 会被 reviewer 直接攻击 |
| 安全加固 | placeholder，仅测了占位 NOP | `docs/kernel-jit-optimization-plan.md:209-211`, `daemon/src/passes/spectre.rs:9-17`, `tests/unittest/rejit_spectre.c:152-153` | 当前不应写成贡献点 |
| 工程成熟度 | unit test 不错，但 orchestration 和 daemon service 边界很粗糙 | `daemon/src/main.rs:438-617`, `runner/src/kernel_runner.cpp:230-355`, `e2e/run.py:113-349` | 会让“可部署性/透明性”显得脆弱 |
| 跨 program type 叙事 | REJIT kernel interface 广，kfunc transform 实际只绑 XDP | `tests/unittest/rejit_prog_types.c:5-11`, `module/x86/bpf_rotate.c:96-99`, `module/arm64/bpf_rotate.c:133-136` | 论文 scope 与实现 scope 不一致 |

## 三、逐 component 代码审查

### 3.1 `daemon/src/`

#### 优点

- pass framework 的基本方向是合理的：analysis、transform、annotation、pipeline 这些概念清晰（`daemon/src/pass.rs:1-9`）。
- README 对当前 pipeline、PGO 限制、placeholder Spectre 都写得较诚实（`daemon/README.md:111-174`, `daemon/README.md:193-202`）。
- daemon 单元测试数量充足，说明 matcher/transform 级别的实现有一定稳定性。

#### 主要问题

1. **`main.rs` 是 god file，CLI、dry-run、apply、socket server、watch loop 全堆在一起。**  
   `daemon/src/main.rs` 共有 631 行；同一文件里同时承载 CLI 定义（`daemon/src/main.rs:25-92`）、enumerate/rewrite/apply 逻辑（`daemon/src/main.rs:129-433`）、Unix socket server（`daemon/src/main.rs:438-545`）和 watch loop（`daemon/src/main.rs:547-617`）。这导致 deployment path 很难单独测试，也让 daemon 很难演化出稳定协议层。

2. **`Serve` 路径是串行、阻塞式的，不能称为真正的长期运行 service。**  
   `cmd_serve()` 在 accept 到一个 client 后直接同步调用 `handle_client()`（`daemon/src/main.rs:456-460`），而 `handle_client()` 会一直读到 EOF 才返回（`daemon/src/main.rs:486-503`）。这意味着一个长连接客户端就能阻塞其他请求，代码里也没有并发处理、协议版本、请求超时、权限控制或 schema 验证。

3. **`Watch` 路径有生产语义缺陷。**  
   `cmd_watch()` 用 `optimized: HashSet<u32>` 记住“见过的 program id”，并在真正 `try_apply_one()` 前就把 id 插进去（`daemon/src/main.rs:554-583`）。结果是：
   - 一旦 apply 失败，该程序后续不会重试。
   - 已卸载程序不会从集合中清理。
   - 也没有“程序内容变化后重新评估”的机制。  
   这和计划文档里把 `watch` 定义为 production 目标的要求不匹配（`docs/kernel-jit-optimization-plan.md:162`）。

4. **verifier log 解析模块处于“写了但没接线”的状态。**  
   `verifier_log.rs` 自己就写明“not yet wired into the production rewrite pipeline”（`daemon/src/verifier_log.rs:12-13`）；`main.rs` 通过 `#[allow(dead_code)] mod verifier_log;` 把它保留下来（`daemon/src/main.rs:14-15`）；而真正触发 `BPF_PROG_REJIT` 的 `bpf_prog_rejit()` 又没有设置 log buffer/log level（`daemon/src/bpf.rs:274-295`）。这导致 REJIT 失败时诊断能力弱，也说明 verifier-state-guided optimization 还只是未来计划。

5. **PGO 只做到了“数据结构存在”，没有做到“系统闭环”。**  
   `ProfilingData`、`run_with_profiling()` 都在 pass framework 中，但目前仍被 dead-code 放着（`daemon/src/pass.rs:45-55`, `daemon/src/pass.rs:542-558`）。README 也承认 branch-level PGO 仍需要“injected programmatically”（`daemon/README.md:199-202`）。与此同时，`profiler.rs` 目前只读 program-level `run_cnt/run_time_ns`（`daemon/src/profiler.rs:4-6`），这不足以驱动 `branch_flip` 这种 branch-level decision；而 `BranchFlipPass` 又明确写成了 PGO-only、没有 heuristic fallback（`daemon/src/passes/branch_flip.rs:119-136`）。这条主线离“runtime-guided specialization”还差最后、也是最关键的一步。

6. **pass framework 有明显的“为未来设计过多，但现在没用起来”的痕迹。**  
   典型例子包括：
   - `ProgMeta` 上直接 `#[allow(dead_code)]`（`daemon/src/pass.rs:17-28`）
   - `ProfilingData` `#[allow(dead_code)]`（`daemon/src/pass.rs:45-55`）
   - `BpfProgram.meta` `#[allow(dead_code)]`（`daemon/src/pass.rs:64-77`）
   - `TransformEntry` `#[allow(dead_code)]`（`daemon/src/pass.rs:79-87`）
   - `PassManager::pass_count()` `#[allow(dead_code)]`（`daemon/src/pass.rs:472-476`）
   - `PassContext::test_default()` `#[allow(dead_code)]`（`daemon/src/pass.rs:563-583`）  
   本轮统计 `daemon/src` 下共有 **51 处** `allow(dead_code)`，这与计划文档里“禁止死代码和防御性编程”的要求是反向的（`docs/kernel-jit-optimization-plan.md:17`）。

7. **analysis registry 是字符串注册，缺失类型安全和错误显式化。**  
   `AnalysisRegistry` 以 `HashMap<String, Box<dyn AnyAnalysis>>` 存储分析（`daemon/src/pass.rs:418-427`），执行时用 `required_analyses()` 返回的字符串去查表（`daemon/src/pass.rs:513-518`）。如果 pass 写错 analysis 名字，系统会直接静默跳过，而不是 fail-fast。对于论文里强调 extensible/pass pipeline 的系统，这个接口太脆弱。

8. **pass naming 和 legacy alias 继续泄漏兼容债。**  
   `passes/mod.rs` 里还在保留 `fixup_branches_inline` 的旧名 re-export（`daemon/src/passes/mod.rs:24-27`），同时支持 `barrier_placeholder` 和 legacy `spectre_mitigation` 两个 pass 名（`daemon/src/passes/mod.rs:50-55`, `daemon/src/passes/mod.rs:83-84`）。这类兼容层本身不严重，但它们说明 v1/v2 边界并没有被真正清理干净。

9. **默认 pipeline 仍偏“先做了再说”，和当前收益证据不匹配。**  
   默认 pipeline 会依次加上 `wide_mem`、`rotate`、`cond_select`、`extract`、`endian`、`branch_flip`（`daemon/src/passes/mod.rs:31-47`）。但权威数据已经显示 corpus 整体净回归（`docs/kernel-jit-optimization-plan.md:181-185`）。在这个阶段，系统更需要一个明确的 profitability gate，而不是“全开再用 benchmark 兜底”。

10. **kfunc “自动发现”其实仍是固定表驱动，不足以支撑 extensibility claim。**  
    `KNOWN_KFUNCS` 是一组硬编码的 `(kfunc_name, module_name)` 表（`daemon/src/kfunc_discovery.rs:16-26`），discover 过程本质是遍历固定集合（`daemon/src/kfunc_discovery.rs:247-313`），并且还保留了 `module_fd` 的 backward-compat fallback（`daemon/src/kfunc_discovery.rs:307-309`）。这更像“有限可扩展”，而不是真正的开放扩展框架。

11. **静态质量还有清理空间。**  
    `cargo clippy` 仍报出一批基础问题，包括 `needless_range_loop`、`collapsible_if`、`implicit_saturating_sub`、`needless_bool`、`match_like_matches_macro` 等，集中在 `analysis/cfg.rs`、`passes/wide_mem.rs`、`passes/rotate.rs`、`passes/branch_flip.rs`、`passes/endian.rs`。这些不是论文 blocker，但它们说明 daemon 还在快速演化阶段。

#### 结论

`daemon/` 是当前项目里最接近“研究系统核心”的部分，但也恰恰暴露出两个最关键问题：

- 机制线已经搭好，闭环还没跑通。
- 研究故事已经写得像 product，代码还停留在 prototype/service skeleton。

### 3.2 `runner/`

#### 优点

- C++ runner 的底层执行能力是有内容的，`micro_exec.hpp` 也已经统一了 CLI、sample schema 等基础接口（`runner/include/micro_exec.hpp:40-149`）。
- kernel 路径和 llvmbpf 路径都能产出较丰富的 timing/counter 样本。

#### 主要问题

1. **`kernel_runner.cpp` 是 1554 行的单体文件，职责过多。**  
   它不仅负责 kernel run，还承载了 TSC 计时、packet/context 构造、Katran fixture、REJIT shell-out、perf counter、compile-only 模式等杂糅职责（`runner/src/kernel_runner.cpp:67-120`, `runner/src/kernel_runner.cpp:230-355`, `runner/src/kernel_runner.cpp:1143-1211`）。

2. **generic runner 被 benchmark-specific Katran 逻辑污染。**  
   `kernel_runner.cpp` 顶部直接定义 Katran 常量（`runner/src/kernel_runner.cpp:70-76`），中段内置 Katran map 初始化逻辑（`runner/src/kernel_runner.cpp:230-355`），执行主路径里还会在通用 run 路径上条件触发 `initialize_katran_test_fixture()`（`runner/src/kernel_runner.cpp:1138-1139`）。这会让“透明 benchmark runner”变成“知道某几个 benchmark 的 runner”。

3. **REJIT 集成方式比较脆弱。**  
   `kernel_runner.cpp` 在 daemon 模式下通过 `std::system()` 直接拼命令行去调用 daemon apply（`runner/src/kernel_runner.cpp:1193-1204`）。这不是稳定的系统内部 API，更像脚本级 glue code。若论文要强调系统 architecture，这种集成方式会被认为太脆弱。

4. **`kernel_runner.cpp` 与 `llvmbpf_runner.cpp` 之间存在明显重复实现。**  
   两边都有近乎复制的 TSC 计时逻辑（`runner/src/kernel_runner.cpp:78-106` 对应 `runner/src/llvmbpf_runner.cpp:39-68`），都有 `packet_context_kind`/I/O mode 解析（`runner/src/kernel_runner.cpp` 与 `runner/src/llvmbpf_runner.cpp:484-582`），都有大量 execution scaffold。既然已经有 `runner/include/micro_exec.hpp:40-149` 这种 shared interface，继续保留这类重复实现说明抽象边界没有收敛。

5. **Python “base libraries” 继续泄漏 case-specific 假设。**  
   `runner/libs/workload.py` 里随处出现 `tracee-*`、`tetragon-*` 命名前缀，例如 `tracee-fio-`（`runner/libs/workload.py:139-145`）、`tracee-dd-`（`runner/libs/workload.py:171-179`）、`tetragon-open-storm-`（`runner/libs/workload.py:255-257`）、`tracee-open-`（`runner/libs/workload.py:364-377`）、`tracee-dd-read-`（`runner/libs/workload.py:431-445`）。这意味着所谓“shared workload library”实际上已经知道了上层 benchmark 语境。

6. **`runner/libs/corpus.py` 已经膨胀成 misc bucket。**  
   它同时承担 packet 构造、Katran 常量、命令执行、错误提取、execution planning 等多种职责；其中还直接写着“Keep these values in sync with e2e/cases/katran/case.py”（`runner/libs/corpus.py:154-162`），说明本应共享的抽象没有被真正抽出来。

7. **底层 attach helper 的可移植性一般。**  
   `runner/libs/attach.py` 直接硬编码 `SYS_PERF_EVENT_OPEN` 和 `SYS_BPF` 的 syscall number，并写着 fallback “may need adjustment”（`runner/libs/attach.py:21-37`）。这在实验脚本里可以接受，但如果把 runner 当成可复用 benchmark substrate，就显得过于脆弱。

#### 结论

`runner/` 的核心问题不是“代码写得长”，而是**实验基础设施和 benchmark-specific policy 没有分层**。这会让所有后续结论都难以解释：到底是系统机制导致的结果，还是 harness 针对具体 workload 的定制导致的结果。

### 3.3 `micro/`

#### 优点

- benchmark catalog 方向是对的，suite 配置已经是 declarative 的，而不是硬编码在脚本里。
- micro 层的数据目前是项目最正面的证据来源之一。

#### 主要问题

1. **`micro/driver.py` 仍是 orchestration monolith。**  
   文件总长 666 行，顶部带着 import-path fallback hacks（`micro/driver.py:17-29`），中段负责 provenance 收集（`micro/driver.py:274-309`）、build orchestration（`micro/driver.py:339-360`），底部同时处理运行、正确性校验、结果汇总和 latest alias 写入（`micro/driver.py:428-662`）。它承担了太多角色。

2. **v1/v2 迁移后的 CLI 兼容债还在。**  
   `REMOVED_SUBCOMMAND_HINTS` 和 `_normalize_argv()` 专门保留了已删除命令的提示逻辑（`micro/driver.py:69-86`）。这类代码本身不大，但它们在整个仓库里不断重复出现，说明“删除旧系统”还没有真正完成。

3. **`micro/input_generators.py` 已经退化成纯兼容 shim。**  
   该文件只剩一行 `from runner.libs.input_generators import *`（`micro/input_generators.py:3-5`）。如果没有外部调用者仍依赖这个导入路径，这个文件应当直接删除；如果还有依赖，也应尽快迁移而不是长期保留。

4. **`programs/*.bpf.c` 没发现大面积明确死源文件，但缺少 reachability discipline。**  
   本轮没有拿到足够证据去断言某个 `micro/programs/*.bpf.c` 源文件完全无人使用，因此不建议武断删除 benchmark 程序源。但从目录组织看，真正的死代码更多在 orchestration compatibility 层，而不是 benchmark 内核本体。  
   额外的组织噪声包括空的 `micro/programs/archive/`，以及大量 in-tree build/result 产物。

#### 结论

`micro/` 当前更像“能产出结果的研究脚本系统”，还不是一个干净的 benchmark layer。它最大的问题是复杂度太多地长在 `driver.py` 上，而不是沉到共享 library 或 declarative schema 中。

### 3.4 `corpus/`

#### 优点

- corpus 层是项目真实性最重要的一层；当前 negative result 虽然不利于 paper，但它本身是高价值信号。
- `corpus/driver.py`、`modes.py`、`auto_tune.py` 各自已经形成一定能力，不是完全混乱的脚本集合。

#### 主要问题

1. **文件规模已经暴露出边界失控。**  
   `corpus/driver.py` 1283 行，`corpus/modes.py` 1856 行，`corpus/auto_tune.py` 1206 行；这三者再叠加 `runner/libs/corpus.py` 591 行，说明 corpus workflow 的复杂度已经被分散到多个大型脚本，而不是通过干净 API 管起来。

2. **`modes.py` 里还保留着对已不存在 daemon 接口的兼容路径。**  
   `build_scanner_command()` 直接写明“v2 daemon does not have a standalone 'scan' subcommand”（`corpus/modes.py:108-115`）；`parse_scanner_v5_output()` 也写明“exists so that existing callers compile”（`corpus/modes.py:118-123`）。这是标准的 stale compatibility code，应尽快删除。

3. **host-fallback / blind-apply / policy fallback 路径过多，污染了实验语义。**  
   参数层面就暴露了 `--blind-apply`、`--force-host-fallback`、`--use-policy`（`corpus/modes.py:220-240`）；执行层面又会在 kernel build 失败、BTF 缺失、guest smoke 失败时自动降级到 host-fallback（`corpus/modes.py:1372-1453`）。  
   这在工程上很“实用”，但在论文实验上很危险：如果 headline 数据混入了 compile-only fallback，reviewer 会直接怀疑结果是否还在同一个问题定义里。

4. **`runner.libs.corpus` 与 `corpus/*` 之间边界模糊。**  
   `runner/libs/corpus.py` 里有 Katran packet 常量（`runner/libs/corpus.py:149-162`）、通用命令运行器（`runner/libs/corpus.py:331-398`）、execution plan（`runner/libs/corpus.py:464-483`）。而 `corpus/auto_tune.py` 又反向 import `corpus.modes` 的执行函数与格式化工具（`corpus/auto_tune.py:40-53`）。这种双向依赖式组织非常不利于后续收敛。

5. **`corpus/driver.py` 与 `micro/driver.py` 存在重复的 orchestration 模式。**  
   `load_suite()`（`corpus/driver.py:307-366`）、`build_runner_command()` / `run_micro_exec_sample()`（`corpus/driver.py:472-542`）、latest alias 输出逻辑（`corpus/driver.py:1250-1262`）都和 micro 层呈现出高度相似的模式，但并没有沉成共享组件。这意味着 micro/corpus 两条“评测管线”还没有真正统一。

#### 结论

`corpus/` 是当前最需要“删代码而不是再加代码”的部分。因为它承载的是论文最关键的数据层，而现在的数据层却被兼容路径、fallback 路径和多份 orchestration 逻辑包围着。

### 3.5 `e2e/`

#### 优点

- E2E case 的覆盖面好，至少在题材上包含 tracee、tetragon、bpftrace、scx、katran，和论文想覆盖的应用域相符。

#### 主要问题

1. **`e2e/run.py` 还是手写 dispatch ladder，而不是 case registry。**  
   它单独维护了 `run_tracee_vm()`、`run_scx_vm()`、`run_katran_vm()` 三个 wrapper（`e2e/run.py:113-269`），又维护了 `apply_case_defaults()` 的 case ladder（`e2e/run.py:278-311`），`main()` 中再次做一次 case 分发（`e2e/run.py:313-349`）。这类结构会让每新增一个 case 都重复改三处以上。

2. **各 case 之间有大量 copy-paste helper。**  
   典型重复包括：
   - `git_sha()`：`e2e/cases/tracee/case.py:259`, `e2e/cases/scx/case.py:197`, `e2e/cases/katran/case.py:202`, `e2e/cases/bpftrace/case.py:152`, `e2e/cases/tetragon/case.py:537`
   - `host_metadata()`：`e2e/cases/tracee/case.py:266`, `e2e/cases/scx/case.py:204`, `e2e/cases/katran/case.py:209`, `e2e/cases/bpftrace/case.py:159`, `e2e/cases/tetragon/case.py:542`
   - `summarize_numbers()`：`e2e/cases/tracee/case.py:276`, `e2e/cases/scx/case.py:214`, `e2e/cases/katran/case.py:219`, `e2e/cases/tetragon/case.py:552`
   - `ensure_artifacts()`：`e2e/cases/tracee/case.py:295`, `e2e/cases/scx/case.py:309`, `e2e/cases/katran/case.py:628`, `e2e/cases/bpftrace/case.py:169`, `e2e/cases/tetragon/case.py:579`
   - `persist_results()` / `build_case_parser()` / `main()`：同样在多 case 重复出现（例如 `e2e/cases/tracee/case.py:805-829`, `e2e/cases/scx/case.py:810-880`, `e2e/cases/katran/case.py:622-2240`, `e2e/cases/tetragon/case.py:1114-1141`）  
   这已经不是“有些重复”，而是缺少一个明确的 case toolkit。

3. **Tracee case 里还有明显的局部重复 helper。**  
   `e2e/cases/tracee/case.py:567` 单独定义了 `percent_delta()`，而其他 case 各自又维护自己的 summary/ratio 工具。函数本身不大，但它揭示的是整个 e2e 层没有共享统计 helpers。

4. **E2E case 自身带 fallback 路径，会让“真实系统评估”变得语义模糊。**  
   例如 Tracee/Tetragon case 内部都包含不同程度的 fallback / workaround 路径，这对工程排障是有用的，但对论文 headline evaluation 不友好，因为结果很难向 reviewer 说明“这究竟还是不是 end-to-end system path”。

#### 结论

`e2e/` 当前最像“不断长出来的实验脚本集合”，而不是一个可维护的 benchmark framework。它的最大问题是代码重复，而不是单个 case 的正确性。

### 3.6 `module/`

#### 优点

- 模块化 kfunc/inline-emit 的方向很有论文价值：它把 architecture-specific lowering 放在 module，而不是继续污染 kernel core。
- 注释通常较详细，尤其是 x86/arm64 指令编码部分。

#### 严重问题

1. **`bpf_extract64()` fallback 在 `len == 64` 时存在未定义行为。**  
   x86 和 arm64 版本都用了 `(1ULL << len) - 1`（`module/x86/bpf_extract.c:42-49`, `module/arm64/bpf_extract.c:58-65`）。当 `len == 64` 时会左移 64 位，这是标准 C 的 UB。这个问题不是理论上的，因为接口签名允许 `len == 64`。

2. **`bpf_rotate64()` fallback 在 `shift == 0` 时存在未定义行为。**  
   x86 与 arm64 两边都写成：
   `shift &= 63; return (val << shift) | (val >> (64 - shift));`
   对应 `module/x86/bpf_rotate.c:30-34` 与 `module/arm64/bpf_rotate.c:45-49`。  
   当 `shift == 0` 时，右移量变成 64，同样是 UB。

3. **ARM64 与 x86 对同名 `bpf_rotate64` 的语义不一致，这是架构级设计缺陷。**  
   ARM64 文件头部注释明确承认：x86 用 `ROL`，ARM64 inline emit 用 `RORV`，并把“方向是架构细节”写进接口解释（`module/arm64/bpf_rotate.c:17-22`）；实际 emit 也确实生成 `RORV`（`module/arm64/bpf_rotate.c:91-115`），但 fallback 实现仍然是 rotate-left（`module/arm64/bpf_rotate.c:45-49`）。  
   这意味着同名 kfunc `bpf_rotate64` 在不同架构上没有稳定语义，直接威胁 correctness，也会让跨平台实验完全站不住。

4. **所有 kfunc 目前只注册给 `BPF_PROG_TYPE_XDP`。**  
   x86/arm64 两套 module 都调用 `register_btf_kfunc_id_set(BPF_PROG_TYPE_XDP, ...)`，见：
   - `module/x86/bpf_select.c:97`
   - `module/x86/bpf_rotate.c:96`
   - `module/x86/bpf_extract.c:122`
   - `module/x86/bpf_endian.c:202`
   - `module/arm64/bpf_select.c:144`
   - `module/arm64/bpf_rotate.c:133`
   - `module/arm64/bpf_extract.c:212`
   - `module/arm64/bpf_endian.c:282`  
   这和论文中想覆盖 tracing/security/observability/sched_ext 的系统叙事不一致；当前真正能利用 kfunc family 的 transform scope 比论文 scope 窄得多。

5. **仓库里保留了编译产物。**  
   例如：
   - `module/x86/bpf_extract.ko`
   - `module/x86/bpf_extract.mod.c`
   - `module/x86/bpf_rotate.ko`
   - `module/x86/bpf_rotate.mod.c`
   - `module/x86/bpf_select.ko`
   - `module/x86/bpf_select.mod.c`
   - `module/x86/Module.symvers`
   - `module/x86/modules.order`
   - `module/arm64/bpf_extract.ko`
   - `module/arm64/bpf_extract.mod.c`
   - `module/arm64/bpf_rotate.ko`
   - `module/arm64/bpf_rotate.mod.c`
   - `module/arm64/bpf_select.ko`
   - `module/arm64/bpf_select.mod.c`
   - `module/arm64/Module.symvers`
   - `module/arm64/modules.order`  
   这些都应从 source repo 中移除并纳入 ignore 规则。

#### 结论

`module/` 是当前最像“论文创新点”的层，但也同时含有**本轮审查里最严重的 correctness blocker**。在修掉这些问题前，不应继续扩展新 kinsn family。

### 3.7 `tests/`

#### 优点

- `tests/unittest/rejit_prog_types.c` 对 kernel REJIT 接口的跨 prog type 覆盖是很有价值的（`tests/unittest/rejit_prog_types.c:3-11`）。
- `tests/unittest/rejit_audit_tests.c` 这类定向 regression test 的存在，对系统论文很加分。
- daemon 自己的 Rust unit test 很强，本轮 `cargo test` 全部通过。

#### 主要问题

1. **测试结构偏“中间层很强、端到端 service 很弱”。**  
   daemon 的 matcher/pass 单元测试很多，但针对 `serve`/`watch`/socket protocol 的自动化测试几乎缺位；`tests/integration/vm_daemon_live.sh` 主要覆盖的是 enumerate/rewrite/apply/apply-all 的一次性路径（`tests/integration/vm_daemon_live.sh:42-107`），没有覆盖 `serve` 的多 client 行为，也没有覆盖 `watch` 的长期状态机问题。

2. **Spectre 测试在验证 placeholder，而不是真实缓解。**  
   `tests/unittest/rejit_spectre.c` 明确写着“Manually apply Spectre mitigation (insert NOP=JA+0 after each JCC)”（`tests/unittest/rejit_spectre.c:5-8`），并定义 `NOP = JA +0`（`tests/unittest/rejit_spectre.c:152-153`）。换言之，当前测试能证明“占位 pass 保持语义”，但不能证明“Spectre mitigation 生效”。

3. **Python 测试覆盖较窄。**  

4. **测试产物也留在树里。**  
   当前可见的 build 目录包括 `tests/kernel/build` 与 `tests/unittest/build`，不应长期留在源码树中。

#### 结论

测试层的核心问题不是“完全没有测”，而是**测得最好的部分不是论文最脆弱的部分**。论文最脆弱的是 runtime-guided daemon path、service path、real-program profitability，而这些恰恰还没有被系统化测试覆盖。

## 四、死代码、不必要的复杂度、建议删除项

### 4.1 明确的兼容残留 / 生产未接线代码

| 路径/符号 | 证据 | 判断 | 建议 |
|---|---|---|---|
| `daemon/src/verifier_log.rs` | 模块头注释明确写明未接线（`daemon/src/verifier_log.rs:12-13`），且在 `main.rs` 以 `#[allow(dead_code)]` 引入（`daemon/src/main.rs:14-15`） | 当前属于生产死代码 | 如果近期不接 verifier-state-guided optimization，建议删除并保留设计说明 |
| `daemon/src/pass.rs` 中 `ProfilingData` / `run_with_profiling()` | `#[allow(dead_code)]` 且没有生产调用点（`daemon/src/pass.rs:45-55`, `daemon/src/pass.rs:542-558`) | 未来接口预埋 | 要么尽快接线，要么从论文提交版里删掉，避免“未来设计”膨胀 |
| `micro/input_generators.py` | 仅为 re-export shim（`micro/input_generators.py:3-5`） | 明确兼容层 | 迁移调用者后删除整个文件 |
| `corpus/modes.py:build_scanner_command()` / `parse_scanner_v5_output()` | 注释写明“exists so that existing callers compile”（`corpus/modes.py:108-123`） | 明确 stale compatibility code | 删除函数和对应调用链 |
| `daemon/src/passes/mod.rs` 的 legacy alias | `fixup_branches_inline` backward compat 与 `spectre_mitigation` 旧名（`daemon/src/passes/mod.rs:24-27`, `daemon/src/passes/mod.rs:52-55`, `daemon/src/passes/mod.rs:83-84`） | 小型兼容债 | 提交前清理旧名，避免命名漂移 |
| `daemon/src/kfunc_discovery.rs` 的 `module_fd` fallback | 注释写着 “Legacy”（`daemon/src/kfunc_discovery.rs:307-309`） | 已被新结构替代 | 删除旧字段和 fallback 路径 |
| `micro/driver.py` 的 removed-subcommand hints | 专门保留对已删除命令的提示（`micro/driver.py:69-86`） | 迁移期代码 | 如果内部调用都已更新，删除 |

### 4.2 不必要的抽象 / 复杂度

1. **daemon pass framework 的“预埋未来接口”过多。**  
   `ProgMeta`、`ProfilingData`、`TransformEntry`、`run_with_profiling()`、`pass_count()`、`test_default()` 加起来形成了一个明显的模式：为了未来功能提前把接口都放进来了，但现在没有闭环。对研究原型而言，这会让代码显得比实际能力更复杂。

2. **string-keyed analysis registry 没有提供足够收益，却引入了脆弱性。**  
   `daemon/src/pass.rs:418-465` 与 `daemon/src/pass.rs:513-518` 是典型例子。

3. **runner/core 与 benchmark fixtures 没分层。**  
   这不是抽象不足，而是抽象位置错误：应当把 Katran/Tracee/Tetragon 的“场景差异”提升成明确接口，而不是让 generic runner 底层知道这些程序。

4. **corpus/micro/e2e 三套 orchestration 重复。**  
   这说明项目缺的不是更多脚本，而是一个统一的 experiment substrate。

### 4.3 建议从仓库删除或改为 ignore 的产物

以下路径明显属于 build/result/cache 产物，不应作为 source repo 常驻内容：

| 路径 | 当前体量 | 建议 |
|---|---:|---|
| `daemon/target` | 374M | 删除并 ignore |
| `runner/build` | 471M | 删除并 ignore |
| `micro/build` | 193M | 删除并 ignore |
| `micro/build-arm64` | 15M | 删除并 ignore |
| `micro/results` | 107M | 若非权威 artifact，迁出 repo；至少不要追踪中间结果 |
| `corpus/build` | 304M | 删除并 ignore |
| `corpus/repos` | 1.9G | 迁到外部 cache 或 dataset 管理路径 |
| `corpus/results` | 144M | 只保留权威快照，移除大部分中间产物 |
| `e2e/results` | 3.3M | 同上 |
| `tests/kernel/build` | 9.4M | 删除并 ignore |
| `tests/unittest/build` | 13M | 删除并 ignore |
| `module/x86` 下 `.ko/.mod.c/Module.symvers/modules.order` | 2.9M | 删除并 ignore |
| `module/arm64` 下 `.ko/.mod.c/Module.symvers/modules.order` | 1.1M | 删除并 ignore |
| 各处 `__pycache__` | 小但分散 | 删除并 ignore |

另外，如果 `micro/programs/archive/` 继续为空目录，也建议直接删除。

## 五、设计缺陷与改进建议

### 5.1 架构耦合问题

1. **系统核心与 benchmark 逻辑耦合。**  
   证据包括 `runner/src/kernel_runner.cpp:230-355` 的 Katran fixture、`runner/libs/corpus.py:154-162` 与 `e2e/cases/katran/case.py` 的手工同步关系。  
   建议：把“benchmark-specific fixture”上提为 case adapter；runner core 只保留 program loading、REJIT、timing、I/O plan 执行。

2. **daemon service 与 CLI/apply path 耦合。**  
   目前所有 service 逻辑都长在 `main.rs` 里（`daemon/src/main.rs:25-617`）。  
   建议：至少拆成 `cli.rs`、`apply.rs`、`server.rs`、`watch.rs`、`protocol.rs` 五层；提交版代码应该让 reviewer 一眼看出 architecture。

3. **corpus execution policy 与 measurement semantics 耦合。**  
   `corpus/modes.py` 既定义实验模式，又在 mode 内部自带 host-fallback 逻辑（`corpus/modes.py:1372-1453`）。  
   建议：显式把 `measurement_mode` 和 `recovery_mode` 分离；论文数字只允许来自单一、干净、可复现实验路径。

### 5.2 命名不一致

1. **计划文档要求“统一命名为 daemon”，代码里却仍到处是 scanner。**  
   计划文档明确写“用户态组件统一叫 daemon，不叫 scanner”（`docs/kernel-jit-optimization-plan.md:160-162`）。但代码里仍大量使用 `scanner_binary`、`build_scanner_command()`、`scanner_commit` 等命名，例如：
   - `micro/driver.py:283-285`
   - `corpus/driver.py:350-363`
   - `corpus/modes.py:100-115`
   - `e2e/cases/*/case.py` 中 `ensure_artifacts(..., scanner_binary, ...)`  
   这会持续制造认知摩擦，也说明 v1/v2 清理不彻底。

2. **`spectre_mitigation` 与 `barrier_placeholder` 双命名并存。**  
   见 `daemon/src/passes/mod.rs:52-55`, `daemon/src/passes/mod.rs:83-84`。  
   建议：如果当前只是 placeholder，就统一叫 `barrier_placeholder`；不要让旧名继续暗示真实 mitigation 已存在。

### 5.3 缺失的抽象

1. **缺一个统一 experiment substrate。**  
   现在 micro、corpus、e2e 分别维护自己的 driver/command building/output alias/provenance。  
   建议：抽一层 `experiment_core`，统一：
   - runtime descriptor
   - program descriptor
   - measurement mode
   - result schema
   - output layout

2. **缺一个统一 e2e case base。**  
   当前 `git_sha()`、`host_metadata()`、`ensure_artifacts()`、`persist_results()` 等大量重复。  
   建议：抽出 `e2e/case_common.py` 或 case registry，case 文件只保留 workload-specific setup/run/analyze。

3. **daemon 缺 typed protocol。**  
   当前 `process_request()` 直接收 `serde_json::Value`（`daemon/src/main.rs:506-545`）。  
   建议：至少定义 versioned request/response structs，并加入 protocol version 和 capability negotiation；否则“extensible daemon”很难让人信服。

### 5.4 建议的重构优先级

**P0：投稿前必须完成**

- 修复 `module/` 中所有 UB 和跨架构语义不一致问题。
- 要么实现真实 speculation barrier，要么把安全加固从摘要和贡献列表里删掉。
- 打通 branch-level PGO 闭环，或明确降级 paper 叙事，承认当前仅为 offline/profile-injected prototype。
- 去掉 corpus headline 路径里的 host-fallback/兼容扫描路径，保证评测语义干净。

**P1：强烈建议完成**

- 拆分 daemon `main.rs`。
- 抽离 runner 中的 Katran 等个案 fixture。
- 删除明显的 compat/dead code。
- 为 `serve`/`watch` 增加真正的自动化测试。

**P2：提升可读性和可维护性**

- 清理 clippy warning。
- 统一命名到 daemon。
- 收敛 micro/corpus/e2e 的输出和 driver 逻辑。

## 六、论文差距分析

### 6.1 目前缺少数据支撑的 claim

1. **“transparent, runtime-guided specialization”**  
   当前能证明的是：
   - 有一个最小 kernel interface 支持原地 REJIT。
   - daemon 可以做 bytecode rewrite。
   - 某些 micro benchmark 上能有收益。  
   当前还不能证明的是：
   - profiles 来自真实运行时闭环
   - daemon 能稳定长期运行并自动优化 live programs
   - runtime-guided decision 在真实程序上优于 blind/fixed policy  
   证据链缺口见 `daemon/src/profiler.rs:4-6`, `daemon/src/pass.rs:542-558`, `daemon/src/passes/branch_flip.rs:119-136`, `daemon/README.md:199-202`。

2. **“performance improvement” 作为系统整体 claim 仍不成立。**  
   计划文档摘要给出“up to 40% performance improvement”（`docs/kernel-jit-optimization-plan.md:24`），但当前最能代表真实程序的 corpus 数据却是净回归（`docs/kernel-jit-optimization-plan.md:181-182`）。  
   更重要的是，文档里还有一组 `llvmbpf vs kernel` 的 headroom 数据（`docs/kernel-jit-optimization-plan.md:171`, `docs/kernel-jit-optimization-plan.md:178-179`）。这组数据只能证明“理论优化空间”，不能拿来等价为“BpfReJIT 已经实现的收益”。如果论文写法混淆这两者，会被 reviewer 抓住。

3. **“security hardening capability” 目前没有实证。**  
   计划文档把 Spectre 缓解写成插入 `lfence`（`docs/kernel-jit-optimization-plan.md:210`），实现却只是 NOP placeholder（`daemon/src/passes/spectre.rs:9-17`）。这类 claim 当前应从摘要里拿掉。

4. **“negligible overhead” 也没有被系统测过。**  
   计划文档摘要里写了 negligible overhead（`docs/kernel-jit-optimization-plan.md:24`），但当前我没有看到对以下 overhead 的系统测量：
   - daemon `watch`/`serve` 的 steady-state CPU/memory 开销
   - `apply` 失败/回滚的 latency
   - BTF discovery/module FD 管理成本
   - production daemon 对 live program churn 的影响  
   没有这些实验，就不该在摘要中写“negligible overhead”。

### 6.2 reviewer 最可能质疑的问题

1. **为什么这不是 kernel peephole 的工作？**  
   计划文档自己提出了 Mandatory Falsification（`docs/kernel-jit-optimization-plan.md:159`）。reviewer 很可能会直接问：
   - 既然你们的 profitable transforms 很少，为什么不把它们做成 kernel JIT peepholes？
   - 如果 corpus 上整体仍是净回归，userspace-guided interface 的额外复杂度凭什么成立？

2. **runtime-guided 在哪里？**  
   `BranchFlipPass` 需要 branch profile（`daemon/src/passes/branch_flip.rs:119-136`），README 又承认 profile 目前需要手工注入（`daemon/README.md:199-202`）。reviewer 会把这看作“paper story 比系统实现超前一整代”。

3. **你们的通用性到底有多强？**  
   计划文档面向网络、观测、安全、调度等多个场景（`docs/kernel-jit-optimization-plan.md:32-37`），但 transform 真正依赖的 kfunc 只注册给 XDP（见 `module/*` 引用）。reviewer 会质疑：
   - 这是 REJIT interface 的通用系统，还是 XDP-focused transform prototype？

4. **真实程序为什么更慢？**  
   corpus geomean 为 `0.868x` / `0.875x`（`docs/kernel-jit-optimization-plan.md:181-182`），回归多于收益。reviewer 不会满足于“micro 很好看”；他们会要求解释：
   - 是 transform 误用？
   - 是 profitability model 不行？
   - 是 benchmark harness 语义混入 fallback？
   - 是 transform family 本身只对少数模式有效？

5. **安全部分是不是 oversell？**  
   目前答案基本是“是”。如果不改，reviewer 很容易据此下调整篇 paper 的可信度。

6. **工程 artifact 是否足够干净、可复现？**  
   repo 里保留大量 build/result/module artifact，本身就会让 artifact reviewer 质疑实验卫生与 source-of-truth 管理。

### 6.3 缺失的关键实验

我认为投稿前至少要补齐以下实验中的大部分：

1. **真正的 PGO 闭环实验。**  
   需要展示 profile 收集、策略生成、REJIT、再运行的完整 loop，而不是手工注入 annotation。

2. **profitability / policy 质量实验。**  
   不只是 blind vs fixed；需要解释为什么某些 family 在 corpus 上伤害更大，并给出可验证的 gating 策略。

3. **daemon 开销实验。**  
   `watch`/`serve` 的 steady-state overhead、program churn 开销、失败重试/回滚行为。

4. **失败语义实验。**  
   verify 失败、module 缺失、kfunc 不可用、policy 错配时，系统是否真正 fail-safe。计划文档把 fail-safe 作为核心设计约束（`docs/kernel-jit-optimization-plan.md:157`），但实验上还没看到这条主线。

5. **跨架构一致性实验。**  
   尤其是在修复 rotate/extract correctness 之后，需要证明 x86/arm64 语义一致且收益一致。

6. **program-type 覆盖实验。**  
   kernel REJIT 接口可以跨 prog type（`tests/unittest/rejit_prog_types.c:5-11`），但 kfunc transforms 现在偏 XDP。论文必须清楚地区分“接口覆盖范围”和“transform 覆盖范围”。

7. **security 实验。**  
   要么真正实现 barrier/hardening，要么把这块从论文中删掉。

### 6.4 related work 对比是否充分

基于当前 plan 文档，我认为 related work 还不够扎实。现有文档在背景部分把 eBPF 对比到了 JVM/WASM/LLVM（`docs/kernel-jit-optimization-plan.md:34-39`），但真正需要系统化比较的对象至少还包括：

- **kernel peephole / in-kernel optimization**  
  这是 Mandatory Falsification 直接要求面对的 baseline。
- **offline/alternative JIT headroom systems**  
  如 llvmbpf/bpftime 一类系统。当前 plan 文档已经用它们证明 headroom（`docs/kernel-jit-optimization-plan.md:171`, `docs/kernel-jit-optimization-plan.md:178-179`），但还没有把“headroom provider”和“our deployed system”清楚切开。
- **dynamic optimization / PGO / hot patching 类系统**  
  如果论文要强调 runtime-guided、live recompile、userspace daemon 管理 kernel-resident code，就必须明确说明你和这些思想系谱的差异到底在哪。
- **security hardening / live patching 相关工作**  
  如果还保留安全部分，就必须补足这条 related work 线；否则 reviewer 会觉得这部分是临时拼进来的副故事。

我的建议是：**related work 必须围绕“为什么不能只做 kernel peephole”来组织，而不是围绕“我们也像 JVM 一样动态”来组织。**

### 6.5 论文定位建议

如果你们能在投稿前修完 P0 问题，并把 corpus/real-program 数据拉回正收益，那么可以继续维持当前“大系统论文”定位。  
如果做不到，我建议收缩成下面两种更可信的定位之一：

1. **最小 kernel interface 论文**  
   核心贡献是：如何用极少 kernel 改动提供安全、可回滚、可原地替换的 REJIT interface；优化只是 case study。

2. **deployed eBPF optimization prototype 论文**  
   明确承认当前只完成部分 transforms 和部分 deployment path，重点讲接口设计、x86/arm64 lowering、经验性教训，以及为什么 real-program profitability 很难。

如果 corpus 最终仍然是净回归，**不要把论文写成“我们普遍加速了真实程序”**。那样会很危险。

## 七、优先级清单

### P0：不完成就不应以当前叙事投稿

1. 修复 `module/` 中的 UB 与跨架构 rotate 语义不一致。
2. 删除或真正实现 Spectre/security story。
3. 打通 branch-level PGO 闭环，至少在一个真实 workload 上证明 runtime-guided 优于 blind/fixed。
4. 清洗 corpus headline 路径，禁止 fallback 污染主数据。
5. 对“为什么不是 kernel peephole”给出强实验回答。

### P1：强烈建议在投稿前完成

1. 拆分 `daemon/src/main.rs` 并为 `serve`/`watch` 增加测试。
2. 从 runner 中抽离 Katran 等个案 fixture。
3. 删除 compat/dead code，统一命名到 daemon。
4. 抽出 e2e case 公共层，去掉复制粘贴。

### P2：工程收尾

1. 清理 clippy warnings。
2. 清理仓库 build/result/module artifact。
3. 收敛 micro/corpus/e2e 的结果 schema 与 output layout。

## 八、最终结论

**项目状态判断：**

- 作为系统研究原型：有价值，而且核心机制是有新意的。
- 作为今天就能投 OSDI'26 的完整系统论文：还不够。

**最本质的问题不是“代码还要再重构一下”，而是：**

- 核心 runtime-guided 叙事还没闭环。
- 真实程序数据还在反驳摘要级性能主张。
- 安全加固主张当前是 placeholder。
- module 层还有 correctness blocker。

如果优先级只能排一件事，我建议先做这条主线：  
**修 correctness blocker -> 清洗 corpus 实验语义 -> 打通一个真实 PGO 闭环 -> 再决定论文是继续走“大系统”还是收缩定位。**

