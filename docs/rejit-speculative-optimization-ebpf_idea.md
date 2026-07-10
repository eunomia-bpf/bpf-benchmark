# Speculative eBPF Optimization (BpfReJIT)

> **论文核心方向：构建一个最小化、动态、可扩展的 eBPF 优化框架，让 deployed eBPF 从一次性静态编译，变成可在线、透明、runtime-guided specialization 的执行环境。Paper 必须展示真实程序上的可测量加速能力。**
> **编辑规则**：
> - **⚠️ 未经用户明确同意，禁止修改内核代码（vendor/linux-framework）。** 所有内核改动必须先调研→用户确认→再实施。codex/agent prompt 必须包含此约束。
> - 未经用户明确要求，禁止 git commit / git push。
> - 任何 TODO/实验/文档引用条目被取代时，必须至少保留一行并标注状态，不得直接删除。
> - 每个任务做完 → 立即更新本文档（任务条目状态 + 关键数据 + 文档路径）。
> - 每次 context 压缩后 → 完整读取本文档恢复全局状态。
> - 用 Bash tool 的 `run_in_background: true` 跑 codex，不阻塞主对话。**禁止用 shell `&` 或 `2>&1 &` 后台启动 codex**（外层 shell 退出导致假完成通知，codex 子进程仍在跑）。
> - **构建+修改+运行不拆分**：一个 subagent 负责完整流程（改代码→构建→运行→发现 bug→修复→再运行），不要拆成多个 agent。
> - **⚠️ 同一时间只能有一个 agent 修改内核代码（vendor/linux-framework），也只能有一个 agent 跑测试（VM benchmark / selftest）。** 多个 agent 同时改内核代码会产生 git 冲突；多个 agent 同时跑 VM 测试会竞争资源、结果不可靠。调度时必须串行化内核改动和测试任务。
> - **⚠️ codex 默认不要 commit/push，除非 prompt 明确要求。** 改完代码就停，由 Claude 统一 commit。
> - **⚠️ 如果需要 commit，必须在 main 分支直接做，不要开新分支。** 开分支导致合并冲突。
> - **⚠️ 暂时性性能数据和实验计划只能出现在两个地方：(1) 开头摘要区域的权威数据行；(2) §7 任务追踪表格的条目。** §1-§6 的正文不得包含会过期的具体数字或待办计划。如果 §1-§6 需要引用性能数据，只引用任务编号（如"见 #256"），不内联数据本身。
> - **⚠️ 禁止死代码和防御性编程**：替换子系统时（如 v1→v2）必须删除旧代码，不保留 `if v1 / else v2` 分支。内核代码中不保留"以防万一"的检查——只在有具体失败场景时才加 guard。每行内核代码都是审核负担，越少越好。
> - **⚠️ 零静默失败（Zero Silent Failure）**：所有错误必须传播和报告。禁止 `unwrap_or_default()`、`.ok()`、`except: pass`、`let _ = result` 等静默吞错模式。禁止 `compile_only` 等标注来掩盖运行时失败——每个 corpus 程序要么跑出测量结果，要么明确报错说明原因。
> - **⚠️ Makefile 是唯一构建/测试入口**：禁止手动 `cargo build`、`insmod` 等。
> - **⚠️ 禁止 sudo**：VM 内已是 root（vng），主机不跑 BPF。
> - **⚠️ VM 测试每个 target 一个 agent**：`make test` / `make micro` / `make corpus` 串行跑，平台用 `PLATFORM` / `ARCH` 选择。
> - **⚠️ Unit test 质量标准见 `CLAUDE.md` 的 "Unit Test Quality"**：非必要不加 unit test。新增测试必须能说明失败时定位哪一类 bug。合理测试覆盖逻辑分支、状态变化、计算/转换、边界、错误路径、外部 ABI/layout/序列化约定或 bug 回归。ABI/layout 测试不能只验 `size_of`，必须验字段 offset 或编码格式。禁止 trivial getter/setter、std/upstream lib 行为、自身重言、mock 测 mock、可读性测试、纯 const alias 和重复覆盖率测试。慢测试或真实系统依赖测试应放到集成/端到端层级，不要伪装成 unit test。
> - **bpfopt-suite v3 设计约束见 §4.6，Benchmark 设计约束见 §5.35。**
> **v1 权威数据**（#256 rerun，native-level rewrite 架构）：micro **1.057x** / applied-only **1.193x**；corpus **0.983x**；Tracee **+8.1%**；Tetragon **+20.3%/+32.2%**；Katran BPF **1.108-1.168x**；gap **0.581x**。`make selftest` **35/35**。v1 代码保存在 `v1-native-rewrite` 分支。
> **v2 当前权威数据**（#644，2026-04-02 本地重跑，artifact 时间戳为 2026-04-03 UTC）：benchmark 默认尝试当前全部 in-scope performance passes，报告只统计**实际 applied sites**。`make corpus` **20/20 app ok**，applied-only / all-comparable geomean **1.033x**，applied sample **61**；apply-side site totals：bpftrace **33**、BCC **961**、SCX **359**。`make selftest`、`make test`、`make negative-test`、`make micro` 全通过。**2026-04-03 再验证**：private-stack 覆盖迁移到 repo-owned tests 后，`make all`、`make check`、`make test` 仍全部通过。
> **2026-04-21/22 Wave 1 后三目标 corpus 权威重跑**（见 #663）：`x86_kvm_corpus_20260421_232916_947372`（30 samples）all-comparable geomean **1.010x**，applied sample **12**，20/20 app ok；`aws_x86_corpus_20260422_012001_472335`（1 sample）**0.983x**，applied sample **10**，20/20 app ok；`aws_arm64_corpus_20260422_044304_037607`（1 sample）**0.986x**，applied sample **10**，20/20 app ok。三目标 `no_programs_changed_in_loader` 统一 **36**。**注意**：该 reason 并非 bytes_jited/xlated same-size gap（`corpus/driver.py:471-540` 根本没比 bytes）。它是命名不准的历史 observability bucket，混了 "0 site 命中"、"pass 命中但 verifier 全 rollback"、"apply 成功但最终 bytecode 无差异" 三类情况，属 corpus 侧 taxonomy 过粗，非 apply correctness bug。详情见 #664。

---

## 0. Abstract

eBPF is widely adopted in production for observability, networking, and customizable kernel extensions, yet its just-in-time (JIT) compilers remain rigid, platform-agnostic, and under-optimized compared to mature runtimes such as JVM, WASM, or LLVM. More fundamentally, each program is compiled once at load time and never revisited, even as its runtime context — map contents, branch profile, helper-call patterns — only becomes known after the program is live. This paper presents BpfReJIT, a dynamic, transparent, and **fully userspace** framework that speculatively re-optimizes already-loaded eBPF programs on a **stock Linux kernel with zero kernel patches** (no new syscall, no verifier or JIT changes, no out-of-tree daemon). An `LD_PRELOAD` shim intercepts the BPF syscalls of unmodified upstream applications, captures each program's original bytecode, and exposes a per-process control socket; a userspace CLI toolchain (`bpfopt`) applies profile-guided BPF-to-BPF rewrite passes and reloads the optimized candidate through the stock `BPF_PROG_LOAD` path, so the existing kernel verifier re-certifies safety exactly as it did for the original program. Optimized versions are installed through the kernel's existing atomic-or-near-atomic attachment-update mechanisms and protected by inline guards with an in-program slow path, avoiding on-stack replacement entirely thanks to eBPF's run-to-completion execution model. Because the verifier remains the sole safety oracle and nothing in the kernel is modified, BpfReJIT runs on any 6.x kernel and preserves BTF/CO-RE and all existing eBPF tooling, loaders, and subsystems. We evaluate BpfReJIT across diverse hardware platforms and representative workloads (network monitoring, security enforcement, and observability tracing) and report guard-protected, profile-driven speedups on real programs while preserving the kernel's safety guarantees. [评测数值待 authoritative rerun 填入;旧 abstract 的 40%/50% 来自含 kinsn / llvmbpf 上界的旧设计,不属于本篇纯 BPF-to-BPF stock-kernel 范围。]

---

## 文档索引 / Documentation Index

| Topic | File | Purpose |
| --- | --- | --- |
| **Plan + design hub (this doc)** | `docs/rejit-speculative-optimization-ebpf_idea.md` | paper plan, architecture, methodology, task tracking |
| Sister idea hubs (separate paper lines) | `docs/kinsn_idea.md`, `docs/nativebpf_idea.md` | idea #2 / #3 framing |
| Task history | `git log` | retired task tables and superseded plan snapshots are recovered from git history |
| Shim implementation | `bpfopt/shim/README.md` | LD_PRELOAD shim + per-pid socket + execute_step RPC |
| Userspace-only design notes | `docs/tmp/userspace_speculative_opt_design.md`, `docs/tmp/poc_a_katran_pidfd_swap.md`, `docs/tmp/poc_b_bcc_perf_event_swap.md`, `docs/tmp/poc_c_v2_shim_only_design.md`, `docs/tmp/poc_e_vendor_replace_x_sys_design.md` | per-attach-type swap recipes, static-Go fallback |
| Benchmark runtime | `docs/benchmark-runtime-architecture.md` | corpus / micro 执行架构 + container/VM runtime model |
| Story / pitch | `docs/bpfrejit-story.md` | high-level narrative |
| eBPF research plan | `docs/tmp/ebpf-bench-research-plan.md` | research methodology + 项目目标 |
| GHCR image cache | `docs/tmp/ghcr-image-cache.md` | base image strategy |
| Docker build cache | `docs/tmp/docker-build-cache-gc.md` | local docker cache 生命周期 |
| Paper writeup | `docs/speculative-optimization/` (submodule) | speculative-optimization paper LaTeX source |
| Ad-hoc reports | `docs/tmp/` | 临时调研/调试报告(按日期组织) |

---

## 1. 论文定位与策略

### 1.1 背景与问题

**背景。** Linux 内核 eBPF 已在生产环境广泛使用：网络（Cilium、Katran）、可观测（Tracee、Tetragon）、安全执行（KRSI/BPF LSM）、调度（sched_ext）。

**Paper anchor — speculative optimization。** 本论文把 bpfopt 定位成 **eBPF 上的 speculative optimization 系统**，对应到 30 年的 JIT speculation 文献:**Self [Chambers&Ungar OOPSLA'91] 的 polymorphic inline cache、HotSpot 的 tier 分层 + PGO、V8 TurboFan 的 OSR-based deoptimization、CoreJIT [POPL'21] 的 formally verified speculation/deopt**。bpfopt 在 eBPF 这个新 substrate 上重做这套技术,**且因为内核 verifier 的存在,deopt 的工程量比传统 JIT 小一个量级**(详 §1.4 Insight 3 与 §4 系统架构)。

**问题。** 与成熟的用户态运行时（JVM、WASM、LLVM 后端）相比，eBPF 存在两大不足：

1. **缺乏 speculative / runtime-guided 优化**：没有平台特定指令扩展（RORX、CMOV、BEXTR、LEA），没有运行时信息引导的 PGO 或动态 JIT 重编译（如 JVM 分层编译、V8 TurboFan），没有基于 workload profile 的分支重排、运行时常量特化、热点 map 内联,没有数据布局优化。**核心 missing piece 不是某个具体优化,而是"profile → 特化 → guard → re-specialize"这一整套 speculative 优化循环**。
2. **缺乏安全/安全加固**：没有运行时 Spectre 缓解注入，没有对有漏洞 BPF 程序的 live patching，没有对运行中程序的透明安全策略执行。

**证据。** 实验表明，对于相同的 BPF 源代码，llvmbpf（bpftime 用户态 LLVM JIT）相比内核 JIT 可实现 **30-40% 的性能提升**和 **50% 的二进制大小缩减**。

### 1.2 根因

在内核中实现类似 LLVM 的完整编译 pass 需要**数万到数十万行代码**，大量内核代码改动，容易出错（不安全），且非常困难。即使实现了简单的 peephole 优化，upstream 接受也需要很长时间（数月到数年）。而且，静态/固定的优化在某些 workload 上可能有害（例如，CMOV 在分支可预测的 workload 上比 branch 更慢）。

### 1.3 替代方案（已排除）

| 替代方案 | 问题 |
|----------|------|
| **在硬件或 SFI 沙箱中隔离 eBPF 指令** | 引入运行时开销；改变执行模型 |
| **在内核中实现所有优化** | 静态优化可能在某些 workload 上损害性能；复杂优化难以保证安全性且难以上游。已有人验证了 JIT 编译器（Jitk、Jitterbug）——不要破坏它们 |

### 1.4 核心 Insights

BpfReJIT 的设计基于三个层次的 insight：

#### Insight 1: 需要一个类似 LLVM pass 的、OS 内核级别的可扩展编译框架

> 成熟的用户态运行时（JVM、WASM、LLVM）通过**可扩展编译框架**获得高性能：LLVM 有 pass 基础设施，新优化 pass 可以作为插件注册；JVM HotSpot 基于运行时 profiling 做动态 JIT 重编译（PGO、分层编译、去优化）。
>
> eBPF 的内核 JIT **完全没有这些能力**。它是刚性的、单体的、平台无关的。我们需要一个**最小化的、动态的、可扩展的内核编译框架——类似 LLVM 的 pass 基础设施但面向 OS 内核**——为内核驻留的 eBPF 程序提供同样的可扩展、运行时引导的优化能力。

#### Insight 2: Runner / shim / bpfopt 三角分工 —— "什么时候优化" vs "用什么命令优化" vs "怎么改 bytecode"

> bpfopt 系统**完全在用户态**,内核改动为零。三个角色严格 dumb-executor 边界:
>
> - **Runner**(yaml 阅读者 + orchestrator):读 `runner/config/passes/<pass>/default.yaml`,把命令模板里的 `${INPUT}/${OUTPUT}/${REPORT}/${PROG_TYPE}/...` 由 runner 解析或交给 shim 替换,通过 per-pid unix 套接字向 shim 发 `execute_step` 命令。决定"什么时候优化"。
> - **Shim**(LD_PRELOAD 注入 app 的 `.so`):透明拦截 app 的 BPF syscall,落 bytecode + 维护 prog/map/link/perf state table。收到 runner 命令后**无条件 `/bin/sh -c <command>`**(env 里删 LD_PRELOAD 避免自递归)。决定"在 app 进程内怎么执行命令"。
> - **bpfopt CLI**(纯 bytecode 重写器):stdin/stdout 传 `struct bpf_insn[]`,跑一个 `--pass <name>`,无 syscall 依赖,无 kernel 知识。决定"怎么改 bytecode"。
>
> 新增优化 = 新写一个 `bpfopt` pass + 在 `runner/config/passes/<pass>/default.yaml` 描述命令模板。**零 shim 改动、零内核改动**。这是让 LLVM pass 基础设施成功的可扩展性模型,搬到 stock-kernel + 用户态的 form。

#### Insight 3: Safety ≠ Correctness —— 与内核 eBPF 安全模型对齐

> 不同于 JVM 或 LLVM 的编译框架必须同时保证**安全性和正确性**，BpfReJIT **将正确性与安全性分离**，与已有的内核 eBPF 安全模型对齐：
>
> - **内核 verifier 专注 safety**:不会破坏内核。每个 bpfopt 重写的 bytecode 通过 **stock `BPF_PROG_LOAD`** 重交内核 verifier(没有 REJIT syscall,没有任何项目-fork 内核改动);verifier 接受 = 跟原始 load 完全相同的 safety 保证。bpfopt 不写 validator,不证 pass 正确性。
> - **用户态工具链负责正确性**：编译变换保持程序语义。如果 pass 或 orchestration 脚本有 bug，程序行为可能改变，但内核安全不受影响（fail-safe）。
>
> **Verifier-state-driven specialization(关键 mechanism)**:基于 safety 分离,bpfopt 把 kernel verifier 同时当作:
>
> (A) **Safety certifier**:每个重写都过 verifier,verifier 的接受证书 = safety 保证。bpfopt 不需要自己证 safety。
>
> (B) **Static analyzer**:verifier 在 `log_level=2` 下输出每条指令处的**抽象解释状态**(tnum / numeric range / pointer provenance / bounds / alignment)。**bpfopt 把这些状态直接当 compiler IR 读**,驱动 constant propagation、dead branch elimination、bounds tightening、specialized code emission。
>
> Role (B) 是 bpfopt 真正区别于 K2 [SIGCOMM'21] / Merlin [ASPLOS'24] / EPSO [ASE'25] 的 design point — 他们都自己跑一套 abstract interpreter(K2 用 SMT,Merlin/EPSO 自己分析)再交 verifier 验。**bpfopt 砍掉了自己那一份 analyzer**,直接吃 verifier 已经算出来的 tnum / range。这条 design 之所以可行,是因为 eBPF verifier 比一般 JIT 的 type system 富一档(value-level abstract interpretation 不只 type check)。
>
> 三种 specialization 凑出 paper 的可操作 contribution:
>
> 1. **Speculative specialization**:profile 出运行时 invariant(map 热点 key、配置常量、循环实际 bound、分支倾向),用 inline guard 保护的 fast path 特化,guard miss 时走 inline slow path 并触发异步 re-specialize(详 §4 two-tier deopt)。
> 2. **Verifier-feedback compilation**:用 verifier 的 tnum/range 在用户态再跑一轮 const_prop / dce / bounds_check_merge,等价于把 verifier 已经做过的 work amortize 到优化层。

### 1.6 设计目标

1. **零内核改动**:stock kernel,没有 REJIT syscall,没有 out-of-tree daemon,没有 kinsn 内核模块,BTF/CO-RE 全保留。新增优化 = 新 `bpfopt` pass + 新 yaml,完全用户态。
2. **可扩展(Extensible)**:每个 pass 是一个独立 CLI 调用,pass 间用 file pipeline 串接。Runner 通过 yaml 描述命令模板,shim 不需要任何 pass 知识。
3. **透明(Transparent)**:对所有 eBPF 应用、loader 和其他 eBPF 工具完全透明 — `LD_PRELOAD=libbpfrejit_shim.so` 注入 + 控制 app 启动。不需要 .bpf.o,不需要改应用代码。(静态 Go 二进制 fallback 见 PoC-E。)
4. **安全(Safe)**:每次重新提交都过 stock verifier。bpfopt 不影响内核安全模型。
5. **稳态零开销**:guard miss 罕见时,specialized 程序运行路径开销仅 1-2 条额外 BPF 指令(inline guard);其余跟原始 program 一样跑。

### 1.7 三组件设计

完全用户态,**stock kernel,零内核改动**。三个组件:

**组件 1:LD_PRELOAD shim — `bpfopt/shim/libbpfrejit_shim.so`**

注入到 app 进程的 dumb executor。三件事:
- **拦截** libc 的 `syscall(SYS_bpf, ...)`、`perf_event_open(2)`、`ioctl(2)`、`close(2)`,捕获每次 `BPF_PROG_LOAD` 的原始 bytecode + attr,落盘成 `<dir>/bpfrejit_<pid>_<hash>.bpf`,在 in-process state table 里跟 `kernel_prog_id`(via `OBJ_GET_INFO_BY_FD`)关联。
- **bind** per-pid 套接字 `/var/run/bpfrejit/shim-<pid>.sock`,实现 `list_progs` / `execute_step` / `dump_state` 三个 RPC(协议沿用原 daemon 时期定义的 JSON 形态;daemon 已移除,shim 是唯一持久用户态组件)。
- **执行**:`execute_step` 收到 runner 发的 shell command 模板,替换 `${VAR}` 后 `posix_spawn("/bin/sh", "-c", ...)`,subprocess env 里删 `LD_PRELOAD` 避免自递归。

shim 不知道 yaml,不知道有哪些 pass,不知道 `bpfopt` 是什么 — 就是一个**通用 syscall hook + state table + shell executor**。语言 C,~1000 行 + musl 变体。

**组件 2:`bpfopt` — 纯 bytecode CLI**

stdin/stdout 传 raw `struct bpf_insn[]`,一次跑一个 `--pass <name>`,零 syscall 依赖。`--input/--output/--report` 走文件,`--map-values/--verifier-states/--profile` 作 side-input。当前已实现 `noop`、`map_inline`、`const_prop`、`dce`、`bounds_check_merge`、`branch_flip`、`skb_load_bytes_spec`、`wide_mem` 等。

**组件 3:Runner Python orchestration**

读 `runner/config/passes/<pass>/default.yaml` 中的命令模板,通过 per-pid shim socket 发 `execute_step`。负责 yaml 解析、profile lifecycle、measurement、pass 序列。**不写新代码** — 沿用现有 `runner/libs/rejit_plan.py:build_execute_plan_payload()` 的 yaml→JSON 协议,只是把原 daemon 的 socket 换成 shim 的 per-pid socket(daemon 已移除;router 转发或 runner 直接枚举,见 PoC-C v2 §6)。

> **谁知道什么**:
> - shim:对单个 app 进程的拦截 + state 完整知识;不知 yaml、不知 pass 名字
> - bpfopt CLI:对单个 pass 的 bytecode 重写完整知识;不知任何 app/runtime 状态
> - Runner:对 pass 顺序 / yaml / profile 完整知识;不知任何拦截细节

**static Go 二进制 fallback**:tetragon / cilium-agent / otelcol-profiler 静态 Go binary 不能 LD_PRELOAD,通过 `golang.org/x/sys/unix` 的 vendor-replace fork(详 `docs/tmp/poc_e_vendor_replace_x_sys_design.md`)在编译时注入同一份 shim handler ABI。Static Go 不在 idea #1 的主线评估,作为 fallback 列出。

### 1.8 类比定位

| 系统 | 类比 | 关键差异 |
|------|------|----------|
| **Self / PIC** [Chambers&Ungar OOPSLA'91, Hölzle et al PLDI'91] | polymorphic inline cache 风格的 inline guard + slow-path fallback | bpfopt 的 deopt mechanism **更像 PIC 而非 OSR** — 见 §4 two-tier deopt |
| **JVM HotSpot tiered + PGO** | 运行时分层编译 + profile-guided respec | 我们在 **OS 内核级别**;deopt 单位是程序版本(BPF_LINK_UPDATE 原子换),不是 stack frame |
| **V8 TurboFan + OSR** | speculative compilation + on-stack replacement | **我们不需要 OSR**:eBPF run-to-completion 语义 → inline slow path 替代 OSR(见 §4) |
| **CoreJIT** [POPL'21] | formally verified speculation/deopt | 我们用 stock verifier 当 safety oracle,把"证 deopt path safe"这事 outsource 给 verifier |
| **LLVM Pass** | 编译时 IR 变换,可扩展 | 我们是 **运行时 post-load + speculative**,verifier 当 safety oracle |
| **Linux livepatch** | 运行时内核代码替换 | 我们有 **verifier 强制 safety**;livepatch 完全信任 patch 作者 |
| **K2/Merlin/EPSO** | BPF bytecode 优化 | 他们 **offline / static / single-version**,bpfopt **online / profile-driven / multi-version + guard** |
| **Morpheus** [Miano et al, ASPLOS'22] | runtime traffic-guided 特化软件数据面(eBPF/XDP + DPDK)+ guard-protected 多版本 + 重 load 经 verifier | **最近邻 prior work,机制高度重叠**:online + 多版本 + profile-driven + guard + tail-call 原子换 + 重 load 经 **in-kernel verifier 兜底**(§6.3 明确),passes 也重叠(const_prop / dce / table-inline≈map_inline / branch-injection≈branch_flip / data-structure-spec≈map representation switching)。**"用 verifier 当 oracle" 不是区别 —— Morpheus 也靠 verifier。** 真正的区别:① Morpheus 只做**网络数据面**(match-action table + 流量信号),bpfopt 覆盖**通用 eBPF**(tracing/安全/观测,无 match-action table);② Morpheus 在 **LLVM IR 层 + 集成进 Polycube/FastClick 工具链**(必须用其工具链构建程序),bpfopt 在 **raw BPF 字节码层 + LD_PRELOAD shim 透明拦截未改动上游 app**(不需源码/IR/框架,作用于已部署程序);③ profiling 信号不同(Morpheus 插 per-packet map-access heatmap,bpfopt 用 run-stats / PMU per-site)。**投稿必须正面区分,否则审稿人直接问"这不是 Morpheus 吗"** |
| **BCF** [SOSP'25] | certificate-backed verification | 他们 offload verification,我们 offload optimization;两者正交可叠加 |

#### 与 eBPF 现有工作的关键差异(扩展轴)

| 系统 | 时机 | 优化版本数 | Profile-driven? | 触发 deopt? | 需要 .bpf.o? | Transparent? | Runtime PGO? | 安全保证 |
|------|------|:---:|:---:|:---:|:---:|:---:|:---:|----------|
| K2 (SIGCOMM'21) | offline / pre-load | 单版本 | 否 | 否 | 是 | 否 | 否 | SMT solver |
| Merlin (ASPLOS'24) | offline / pre-load | 单版本 | 否 | 否 | 是 | 否 | 否 | 编译器正确性 |
| EPSO (ASE'25) | offline / pre-load | 单版本 | 否 | 否 | 是 | 否 | 否 | 编译器正确性 |
| ePass (LPC'25 原型) | load/verify | 单版本 | 否 | 否 | 是 | 否 | 否 | in-kernel pass |
| BCF (SOSP'25) | load-time | 单版本 | 否 | 否 | 是 | 否 | 否 | certificate |
| Morpheus (ASPLOS'22) | online / runtime | 多版本 | ✅ | ✅ guard + re-specialize | 需 LLVM IR | 否(集成 Polycube/FastClick) | ✅ | **kernel verifier(重 load 重过)** |
| **bpfopt(本论文)** | **online / post-load** | **多版本** | **✅** | **✅ inline guard + async respec** | **否** | **✅** | **✅** | **kernel verifier** |

加粗的三轴(**online / multi-version / profile-driven + deopt**)是 bpfopt 跟**绝大多数**现有 eBPF 优化工作的本质差异 — 不只是时机不同,更是设计哲学不同。**唯一的例外是 Morpheus(ASPLOS'22),它也落在 online / multi-version / profile-driven 这格,且重 load 同样过 in-kernel verifier**——因此「用 verifier 当 oracle」不是与 Morpheus 的区别。bpfopt 与 Morpheus 的真正分水岭见下面的 related-work 段落(域的一般性 / 透明字节码部署 / map 之外的信号)。

**Related work — Morpheus(用于 paper 的 related-work 段落):**

> Morpheus [ASPLOS'22] is the closest prior work: it performs guard-protected, profile-driven runtime specialization of eBPF data planes with deoptimization fallback, reloading through the in-kernel verifier — mechanically a form of speculative optimization, though it is framed as unsupervised dynamic compilation for networking and does not connect to the speculative-JIT lineage. We share this paradigm but differ in three respects: (i) **generality** — we optimize arbitrary deployed eBPF (tracing, security, networking), not only match-action data planes; (ii) **transparency/deployment** — we operate on raw loaded bytecode via an `LD_PRELOAD` shim on unmodified binaries, whereas Morpheus works at the LLVM IR level and must be integrated into the data-plane framework (Polycube/FastClick); (iii) **signal** — we exploit PMU per-site branch profiles and run-statistics, signals Morpheus explicitly forgoes in favor of map-access heatmaps.

#### verifier 精度 / 可表达性相关工作

bpfopt 的 Insight 3(吃 verifier 已算出来的 tnum/range 当 ground truth、砍掉自己的 analyzer)依赖"verifier 的 value-level abstract interpretation 是 sound 的、可被信任当 oracle":

- **PREVAIL** [Gershuni et al, PLDI'19]:基于 abstract interpretation 的 eBPF verifier(Windows 在用)。讨论"verifier 当 abstract interpreter"绕不开的引用。
- **Tristate Numbers** [Vishwanathan et al, CGO'22] + **Range Analysis Verification** [CAV'23]:形式化证明并改进 verifier 的 tnum / range analysis。直接支撑"verifier 的 tnum/range 可信"。

另有一条**"改 / 换 verifier 以提升可表达性"**的正交路线 —— **Fast/Flexible Kernel Extensions** [SOSP'24]、**Rex** [ATC'25]、**VEP** [NSDI'25]、**Approximation Enforced Execution** [Sec'25]。它们都改动或替换 verifier;bpfopt 的卖点恰恰相反:**stock verifier、零内核改动**,因此与这条路线正交。

#### speculation / deopt 与在线换码相关工作(补充)

- **Deoptless** [Flückiger et al, PLDI'22]:用 dispatched OSR + specialized continuations 做投机,**不走传统 deopt**。bpfopt 的 two-tier deopt(inline guard + 同版本 slow path、不需要 OSR)应正面对标这条"避免传统 deopt"的路线(§4)。
- **Correctness of Speculative Optimizations with Dynamic Deoptimization** [Flückiger et al, POPL'18]:CoreJIT [POPL'21] 的奠基前作,形式化 guard/deopt 正确性 —— bpfopt 把"证 deopt path safe"outsource 给 verifier,与之对照。
- **KShot** [DSN'20] 等 live kernel patching:运行中内核代码原子替换的可行性先例;bpfopt 的程序版本原子换属同类"在线换码",但有 verifier 强制 safety(livepatch / KShot 信任 patch 作者)。
- **bpftime** [OSDI'25]:用户态 eBPF 运行时(含 llvmbpf LLVM JIT,本文用作性能上界参考);与 bpfopt 部署透明性目标相关,应正式引 OSDI'25 版。

### 1.9 四种用途

同一框架支持四种用途：

| 用途 | 说明 | OSDI 评估 |
|------|------|:---:|
| **性能优化** | wide load 合并、rotate、cmov、硬件特化 lowering、PGO、const propagation、map inlining | ✅ 主线 |
| **安全加固** | 插入 bounds check、speculation barrier、收紧权限、Spectre 缓解注入 | ⏸ future work |
| **恶意程序阻断** | 检测恶意 BPF prog → 替换为 no-op/安全版本 → 在线热修复，危险 helper 防火墙 | ⏸ future work |
| **运行时可观测** | 给 hot path 插入 tracing，不改应用代码 | ⏸ future work |

### 1.10 Why Userspace-only (详细理由)

| 理由 | 说明 |
|------|------|
| **零内核改动** | stock kernel,任何 6.x 即可,不需要 fork、不需要 patch upstream、不需要等内核发行版 |
| **可更新性** | 用户态 bpfopt + shim + runner 可任意时刻更新优化策略,不绑 kernel release cycle |
| **算法迭代** | 优化 pattern 需要反复实验,用户态可快速迭代而不影响内核稳定性 |
| **程序级组合** | 局部有利的变换可能全局有害(I-cache cliff),userspace 做全局预算和 phase-aware 调度 |
| **Workload 适应** | 分支可预测性、hot path、map 热点分布取决于运行时数据,**只能 online speculate** |
| **Fleet 管理** | A/B testing、gradual rollout、per-deployment customization |
| **所有权** | service owner(Cilium/Katran/Tracee 等)控制各自的优化策略,不是 kernel maintainer |
| **覆盖面** | kernel JIT 有几十个可优化点,统一 userspace 框架一次覆盖,无需逐个 patch 上游 |
| **BTF/CO-RE 完整保留** | 不动 verifier 不动 JIT,upstream BTF 一致性约束自动满足 |

### 1.11 核心设计约束

1. **Safety / correctness 架构分离**:stock kernel verifier 是 safety 的唯一 authority。bpfopt 不写 validator,不证 pass 正确性 — verifier 接受即 safety 保证(§1.4 Insight 3)。
2. **零内核改动**:不加 syscall、不动 verifier、不加 kinsn 模块。任何 6.x stock kernel 都能跑。
3. **透明 LD_PRELOAD shim**:不需要 .bpf.o、不需要改应用/loader,不需要 detach/reattach。静态 Go 二进制走 vendor-replace fallback(PoC-E)。
4. **稳态零开销**:inline guard 1-2 条 BPF 指令,verifier 接受后跟原始 program 同样路径执行;guard miss 才走 inline slow path。
5. **Fail-safe**:每次 candidate `BPF_PROG_LOAD` 走 stock verifier。失败就丢弃,保留上一次成功版本;原程序持续运行,不破坏 in-flight invocation。
6. **`bpfopt` 零 syscall 依赖**:`bpfopt` 只读写 raw `struct bpf_insn[]`,所有 BPF syscall 由 shim 在 app 进程内调,跟 bpfopt 隔离。
7. **Pipeline 协议**:`bpfopt --pass <name>` stdin/stdout 传 raw binary bytecode,side-input/output(profile / verifier-states / map values / report)走文件。Runner 把 yaml 命令模板通过 shim 套接字发到 app 进程,shim 替换 `${VAR}` 后 `/bin/sh -c`。
8. **Shim 是 dumb executor**:不知道 yaml,不知道 pass 名字。所有 pass 知识在 `bpfopt` + `runner/config/passes/*.yaml`,跟 shim 解耦。
9. **Runner 稳定边界**:沿用现有 `runner/libs/rejit_plan.py:build_execute_plan_payload()` 的 yaml→JSON 协议,把原本"发给 daemon"改成"发给每个 app 的 shim socket"(daemon 已移除)。Benchmark runner Python 改动最小。


## 3. 变换分类

### 3.1 性能优化变换

> **范围说明**:本表只列**纯 BPF-to-BPF rewrite pass**(即不依赖任何内核 patch / kinsn 框架的 pass)。所有依赖 kinsn 的变换(`rotate`、`cond_select`、`extract`、`endian_fusion`、`prefetch`、`ldp_stp`、`bulk_memory`、`ccmp`、`lea` 等)属于 idea #2,见 `docs/kinsn_idea.md`,**不在本论文范围**。

#### Speculative 分类(本论文 framing)

每个 pass 都属于以下三类之一:

| 类型 | 定义 | 需要 guard? | Deopt 方式 | 典型 pass |
|---|---|:---:|---|---|
| **A. Unconditional rewrite** | 输入输出语义恒等的纯 bytecode 重写,不依赖任何 runtime invariant | 不需要 | 无需 deopt | `wide_mem`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec` |
| **B. Verifier-feedback compilation** | 用 verifier 的 tnum/range 做 const_prop / branch fold(verifier-state 当 IR) | 不需要(verifier 已证)| 无需 deopt | `const_prop` |
| **C. Speculative specialization**(本论文 hero) | 基于 runtime profile 推测一个 invariant,生成 inline guard + fast path + inline slow path | 需要(Tier 1)| §4.3.5 two-tier(guard miss 走 inline slow path,async respec)| `map_inline`(热 key)、`branch_flip`(profile-driven 重排)、未来的 `loop_bound_spec`、`runtime_const_burn`、`cold_branch_prune`、`tail_call_chain_fuse`、`helper_call_elision`、`map_repr_switch` |

C 类是本论文跟所有 prior eBPF 优化(K2/Merlin/EPSO)的关键差异:**他们都是 A 类 + 部分 B 类**(单版本 + offline + static),**bpfopt 加入 C 类**(多版本 + online + profile-driven + guard-protected,见 §1.8 比较表)。

> **新 pass 设计原则**:看 candidate transformation 是不是依赖运行时观测的 invariant — 如果是,设计成 C 类 + inline guard。即使 invariant 在某些 deployment 恒为真(典型 const burn 场景),也仍生成 guard,代价 1-2 条指令,换来 fail-safe 与 verifier 自动认证。

| 变换 | 类 | 状态 | 说明 | Corpus 证据 |
|------|:---:|:---:|------|------|
| **WIDE_MEM** | A | ✅ 已实现 | byte load+shift+or → 已有 BPF wide load 指令。占 kernel surplus 50.7% | 49/62 micro applied |
| **BRANCH_FLIP** | C | ✅ 已实现;profile-guided | if/else body 重排。policy-sensitive;显式启用时要求 `bpfprof --per-site` 真实 profile;缺 PMU 数据直接 exit 1,无 heuristic fallback | profile-driven pass |
| **Dynamic map inlining** | C | ✅ 已实现 | snapshot once → inline 热 key → guard(key 等于热 key) → fast path 用 inline const,slow path 调 `map_lookup_elem` | **11556 个 map_lookup site;Katran 22→2 条(-91%);Tetragon 447→2(-99.6%)**。设计:`dynamic_map_inlining_design_20260324.md` |
| **Verifier const prop** | B | ✅ 已实现 | `log_level=2` → tnum/range 常量 → `MOV imm` → branch folding。Verifier-state-driven 的范式实例(§1.4 Insight 3) | **23% verifier state 含精确常量;62.5% 分支和立即数比较** |
| **DCE** | A | ✅ 已实现 | const prop / map inline 后的 unreachable block / dead store 消除 | bpfopt DCE 让更多条件变常量 |
| **Bounds check merge** | A | ✅ 已实现 | guard window merge / hoisting,合并小窗口为大窗口 | **42 guard sites,严格冗余=0%,但 83.3% 可合并(ladder 结构)**。实现:`BoundsCheckMergePass` |
| **`skb_load_bytes` → direct packet access** | A | 📝 值得做 | helper call specialization 的 P0 case;纯 bytecode rewrite | **590 skb_load_bytes site(Cilium 428)**。调研:`helper_call_inlining_research_20260324.md` |
| **Runtime-constant burn-in** | C | 📝 待实现 | 观测稳定的 map cell / 配置 / helper 返回值 → 编进 bytecode 当 immediate + guard | 未来工作 |
| **Loop bound specialization** | C | 📝 待实现 | profile 出实际 iteration count → 重写为 unrolled / tighter-bounded 版本 + guard | 直击 K2/EPSO 打不到的 verifier conservative loop bound 空间 |
| **Cold branch pruning** | C | 📝 待实现 | observed-never-taken 分支 → trap-and-reload guard | 跟 `branch_flip` 互补 |
| **Map representation switching** | C | 📝 future work | hash map 实际只有 N 条 entry 时 → array-backed lookup + guard | 未来工作;V8 object shape 类比 |
| **Frozen map inlining** | A | ❌ 不做 | BPF_MAP_FREEZE 后只读 map → 常量 MOV | **真实 workload 无显式 freeze,hot-path lookup ≈ 0** |
| **Subprog inline** | A/C | ⏸ 不在主线 | bytecode 层 budgeted inline。**REJIT 元数据 blocker** 在 stock-kernel + LD_PRELOAD shim 路径下不再适用(shim 在 PROG_LOAD 拦截层重发整 prog,无 func_info/line_info UAPI 增量),PGO selective inline 留作后续实验 | **834 调用点 / 67 对象(11.8%)**。调研:`subprog_inline_research_20260326.md` |
| **Spill/fill 消除** | A | ❌ 不做 | 冗余 spill/fill 消除 | 内核已有 KF_FASTCALL,增量收益低 |
| **除法强度削减** | A | ⏸ 后续 | 常量除数 → shift+multiply。支持 app 命中几乎全是 64-bit `/1e9`,纯 bytecode 需要 64x64→128 multiply-high emulation,先等 per-site profile 数据 | DIV/MOD 共 `1269` sites,Cilium `/1e9` 占 `553`。调研:`docs/tmp/division_reduction_research_20260430.md` |
| **寄存器重分配** | A | 📝 待实现 | BPF bytecode 层面 R1-R5→R6-R9 live-range 重分配,删除跨 helper caller-saved spill/fill | **62,406 matched pairs,59,297 跨 helper(95.0%),Tetragon+Tracee 占 91.7%**。调研:`docs/tmp/register_realloc_research_20260430.md` |
| **Stack-slot coalescing** | A/C | ⏸ verifier-state 版作 future work | 静态版调研:**0 coalescable pairs**(安全 slot 都是长生命周期 save slot)。verifier-state-driven 版可窄化 helper memory range,但静态版不进 first wave | 实测:`docs/tmp/stack_coalesce_census_20260506.md` |
| **PHI-style merge** | A/B | ⏸ second wave | 不同 path 后 reg 一致的合并简化。imm-only 安全且 site 数可观;copy-reg / alu-op 需要 verifier-state interference 分析 | **121,556 CFG merge points → 1,316 all-assign-same-imm sites + 61 copy-same-reg + 85 same-alu-op + 46 strict diamond**。实测:`docs/tmp/phi_merge_census_20260506.md` |
| **Loop-invariant code motion (LICM)** | A/B | ⏸ second wave | open-coded 循环里把不变量提到循环外。仅 stack-reload 候选;safety 需 verifier stack-state / helper-memory bounds | **934 open-coded loops → 118 unique stack-load LICM sites**。实测:`docs/tmp/licm_census_20260506.md` |
| **Strength reduction (mul/mod by const)** | A | ❌ 不做 | LLVM 已在源码层 reduce,BPF bytecode 直接是 LSH/AND 形态 | 实测:`docs/tmp/strength_reduction_census_20260506.md`(0 sites) |
| **Local instruction scheduling** | A | ❌ 不做 | 同 BB 内 pure ALU 指令调度。risk 高,收益 low-medium | 不在第一波 |
| **Helper inline beyond map_inline** | A | ❌ 不做 | `bpf_jiffies64` / `bpf_get_smp_processor_id` / current_task helpers 等已被 kernel inline | 新候选需窄 whitelist + 每调用 stability proof |

### 3.2 安全加固变换（暂不在 OSDI 评估范围）

> **2026-03-28 决定**：安全相关 pass（speculation_barrier、dangerous_helper_firewall、live_patch、权限收紧）暂不纳入当前评估和 benchmark pipeline。代码保留供 future work 引用，但不在默认 pipeline 中启用，也不在 benchmark_config.yaml 中配置。

| 变换 | 状态 | 说明 |
|------|:---:|------|
| **Spectre 缓解注入** | ⏸ 暂不评估 | SpeculationBarrierPass(用户态 `bpfopt` pass 插入 `BPF_NOSPEC`)。代码保留 |
| **LFENCE/BPF_NOSPEC 消除** | ⏸ 暂不评估 | corpus 861 程序实测 BPF_ST_NOSPEC = 0 |
| **危险 helper 防火墙** | ⏸ 暂不评估 | DangerousHelperFirewallPass。代码保留 |
| **BPF 程序漏洞热修复** | ⏸ 暂不评估 | LivePatchPass。代码保留 |
| **权限收紧** | ⏸ 暂不评估 | 调研完成，过权在部署层面非字节码层面 |

### 3.3 不在范围内

完整寄存器分配、指令调度、任意 native code 注入。

---

## 4. 系统架构

### 4.1 系统架构 — 全用户态 stock-kernel

```
┌─────────────────────────────────────────────────────────────────┐
│  Runner (Python, 现有 corpus/micro 框架不变)                    │
│                                                                 │
│  - 读 runner/config/passes/<pass>/default.yaml                  │
│  - rejit_plan.build_execute_plan_payload() 把 yaml.command      │
│    塞进 JSON                                                    │
│  - 通过 per-pid socket 发 execute_step 给目标 app 的 shim       │
│  - 原 daemon 时期的 socket 协议复用,socket path 变成 per-pid    │
└──────────────────┬──────────────────────────────────────────────┘
                   │  unix socket: /var/run/bpfrejit/shim-<pid>.sock
                   │  {"cmd":"execute_step","prog_id":N,
                   │   "command":"timeout 6000 bpfopt --pass noop
                   │              --input ${INPUT} --output ${OUTPUT}
                   │              --report ${REPORT} ..."}
                   ↓
┌─────────────────────────────────────────────────────────────────┐
│  App process (Tracee / Tetragon / Katran / Cilium / bpftrace /  │
│               BCC / otelcol-ebpf-profiler 等真实 upstream 二进制) │
│                                                                 │
│  ┌───────────────────────────────────────────────────────────┐  │
│  │  libbpfrejit_shim.so  (LD_PRELOAD-inject, ~1000 行 C)     │  │
│  │                                                           │  │
│  │  intercept thread (同步 syscall path):                    │  │
│  │    syscall(SYS_bpf, BPF_PROG_LOAD, ...) ── 落 bytecode    │  │
│  │      ── OBJ_GET_INFO_BY_FD → kernel_prog_id              │  │
│  │      ── obj_insert into prog/map/link/perf state table   │  │
│  │    perf_event_open(2), ioctl(2), close(2) 同样拦截       │  │
│  │                                                           │  │
│  │  socket thread:                                          │  │
│  │    /var/run/bpfrejit/shim-<pid>.sock                     │  │
│  │    execute_step → 替换 ${VAR} → posix_spawn /bin/sh -c   │  │
│  │      (env 删 LD_PRELOAD,避免 bpfopt 自己被 shim 拦截)    │  │
│  │                                                           │  │
│  └───────────────────────────────────────────────────────────┘  │
│              │                                                  │
│              │  fork+exec(/bin/sh -c "bpfopt --pass ...")       │
│              ↓                                                  │
│  ┌───────────────────────────────────────────────────────────┐  │
│  │  bpfopt (pure bytecode CLI, 零 syscall)                  │  │
│  │  stdin: struct bpf_insn[]   stdout: rewritten insn[]     │  │
│  │  --pass <name>  --input  --output  --report              │  │
│  └───────────────────────────────────────────────────────────┘  │
│              │                                                  │
│              │  rewritten bytecode → shim 后续做 candidate      │
│              │  BPF_PROG_LOAD(stock) → 成功后 link_update /      │
│              │  PERF_EVENT_IOC_SET_BPF 等 swap recipe(详 PoC-C v2)│
│              ↓                                                  │
│  ┌───────────────────────────────────────────────────────────┐  │
│  │  Stock kernel — verifier + JIT + attach 接口             │  │
│  │  零 patch:无 BPF_PROG_REJIT / 无 GET_ORIGINAL syscall    │  │
│  │  无 kinsn 模块。candidate prog 跟原始 prog 经同一         │  │
│  │  bpf_check() + bpf_int_jit_compile() 路径                │  │
│  └───────────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────────┘
```

**所有 BPF syscall(包括 candidate `BPF_PROG_LOAD`、`BPF_LINK_UPDATE`、`PERF_EVENT_IOC_SET_BPF`)都从 app 进程内发出**,因为这些操作需要触及 app 进程的 fd table。Runner / 外部进程在 stock kernel 下无法跨进程拿 app 的 fd ownership(详 `docs/tmp/poc_b_bcc_perf_event_swap.md`),这是 shim 必须在 app 进程内的根本原因。

### 4.2 工作流

```
1. App 启动(LD_PRELOAD=libbpfrejit_shim.so)
   shim_init → 建 state table → bind socket → 起 worker 线程
2. App 自然加载 BPF
   shim 拦截每次 BPF_PROG_LOAD,落原始 bytecode + 关联 kernel_prog_id
3. Runner 决定 optimize
   读 yaml,sequence pass(默认 policy 见 runner/config/passes/)
4. 每个 pass:
   runner ───execute_step(prog_id, shell command)──► shim socket
   shim:替换 ${INPUT}=<bytecode_path>, ${OUTPUT}=workdir/out.bin,
         ${REPORT}=workdir/report.json, ${PROG_TYPE}=..., ${TARGET}=...
   shim:/bin/sh -c <substituted> → 内部 fork bpfopt CLI
   bpfopt:读 stdin/--input,跑 --pass,写 stdout/--output + --report
5. (Phase 2 swap,待实现):
   shim 用 candidate bytecode 调 stock BPF_PROG_LOAD
   按 attach 类型走 swap recipe(LINK_UPDATE / SET_BPF / map_update_elem)
6. Runner 读 bpf_stats 测 exec_ns,记 logical_id ↔ {old, new} prog_id 映射
```

`runner/config/passes/noop/default.yaml` 的真实 command(已在仓库):

```yaml
log_level: 1
command: |
  timeout 6000 bpfopt --pass noop --input ${INPUT} --output ${OUTPUT} \
                       --report ${REPORT} --prog-type ${PROG_TYPE} \
                       --target ${TARGET}
```

Shim 把 yaml 的 `command` 字段视作 opaque shell text,只替换 `${VAR}` 然后 `/bin/sh -c`。**Shim 不知道 `bpfopt` 是什么、也不知道 `noop` 是什么**;新 pass 加进来只需要写一个 yaml + 一个 `bpfopt` pass,shim/Makefile/Dockerfile 零改动。

### 4.3 安全模型

```
Safety（kernel 保证）：
  verifier 验证新 bytecode → 内核不会崩溃/信息泄露/提权
  和 BPF_PROG_LOAD 完全相同的安全保证

Correctness（用户态工具链负责）：
  bpfopt pass 和 orchestration 脚本确保变换保持程序语义
  手段:differential testing、stock kernel verifier result(per-candidate-load)、gradual rollout、per-pass failure inspection
  用户态变换有 bug → 程序行为可能变 → 但内核安全不受影响（fail-safe）
```

### 4.3.5 Two-tier deoptimization 机制

bpfopt 是 speculative optimizer,**每个 speculative specialization 必须配对一个 deopt path**。传统 JIT(V8/HotSpot)用 **on-stack replacement(OSR)** 在 speculation 失效时把当前 stack frame 翻译回 interpreter 继续跑;**bpfopt 不需要 OSR**,因为 eBPF 程序天然 run-to-completion(每次 event 触发跑一遍完整 program,中途不暂停)。换来的是更简单的 deopt mechanism:

**Tier 1 — Inline guard fast/slow path(per-invocation)**

> Speculation 编进 bytecode 时**自带 slow path fallback**。比如 specialize "map 热点 key = K"时,生成的代码长这样:
>
> ```
>   if (key == K)        # guard,一两条 BPF 指令
>       <inline 编译进来的 hot value>
>   else
>       slow_path:        # 原 map_lookup_elem 走这条
>       call BPF_FUNC_map_lookup_elem
> ```
>
> Guard 每次 invocation 都跑(开销 ≈ 1-2 条指令),guard miss 时走同一 program version 里的 slow path,**不切换程序、不重新 verify**。这跟 **Self / PIC 时代的 inline cache** 同构,跟 V8 的 OSR-based deopt 不同。
>
> 这层处理 **per-packet / per-invocation** 的特化失效 — guard 极便宜、miss 极罕见时就划算。

**Tier 2 — Async respecialization(phase-shift)**

> Shim worker 线程后台监控 guard miss rate。如果 invariant 真的长时间漂移(workload phase 变化、配置更新、新 hot key 出现),累积的 miss 信号触发 runner 重发 `execute_step`,**异步重 specialize**:
>
> ```
> shim 观测 guard miss rate > threshold
>   → 通过 socket 告知 runner / runner 主动 poll
>   → runner 重发 execute_step(同一 prog,新 profile)
>   → shim 拿 candidate bytecode 调 stock BPF_PROG_LOAD
>   → kernel verifier 重过(safety 重新认证)
>   → 按 attach 类型走 swap recipe(LINK_UPDATE / SET_BPF detach+reopen /
>      MAP_UPDATE_ELEM PROG_ARRAY slot 等,详 PoC-C v2)
> ```
>
> 这层处理 **phase-level** 的特化失效。延迟是 ms-100ms 级,**只有 miss rate 真升上来才触发**,稳态零开销。

**为什么不需要 OSR**

OSR 在 V8 里的存在是因为 JS 函数可以跑很久(循环、长 call chain),speculation 失效时不能等当前调用结束。eBPF 程序每次 invocation 微秒级、run-to-completion,**guard miss 时让这次 invocation 走 inline slow path 完成就行**,不需要 mid-execution 切版本。这条 design 让 deopt 工程量比 V8 OSR 小一个数量级 — **没有 stack frame 翻译、没有 deopt metadata 表、没有 safe-point 标注**。Paper 里要明确 articulate 这个 saving 是 eBPF execution model 天然给的红利。

**两层 + verifier 的关系**

Tier 1 的 fast/slow path 都在**同一个 verifier-accepted program version** 里,所以两条 path 都是 safe。Tier 2 的新 version 重交 stock verifier,verifier 接受才生效。**两层都不需要 bpfopt 自己证 safety**,继续吃 verifier 当 oracle(§1.4 Insight 3)。

---

## 5. benchmark 设计

### 5.1 Required Baselines

1. Stock kernel JIT
2. `kernel-fixed-cmov/wide/rotate/lea` peephole（固定策略）
3. `advisor-static`（CPU DB only）
4. `advisor-profiled`（CPU DB + workload profile）
5. llvmbpf 作为上界参考

### 5.2 Required Questions

1. Userspace policy 是否在不同硬件/workload/程序间产生差异？✅
2. 这些差异是否 outperform fixed kernel heuristics？✅
3. Legality substrate 在真实程序上的 directive 接受率？🔄
4. 系统是否泛化到多个 directive 家族？✅
5. Operators 能否在类似 production 部署中安全管理 policy？🔄

### 5.5 测量方法约定

- **exec_ns** 是跨 runtime 对比的正确主指标（双方都测纯 BPF 执行）
- **wall_exec_ns** 不可用于跨 runtime 对比（kernel 包含 syscall dispatch 开销）
- timing_source 追踪来源（kernel=ktime, llvmbpf=rdtsc）
- 显著性标签使用 BH-adjusted Wilcoxon，ratio CI 使用 unadjusted bootstrap
- ktime 分辨率 <100ns 的 benchmark 标记为 sub-resolution

### 5.3 Required Workloads

- **Mechanism isolation**：load_byte_recompose, binary_search, switch_dispatch, branch_layout
- **Policy-sensitivity**：cmov_select vs log2_fold（见 #20, #38）
- **Real programs**：.bpf.o corpus（Cilium/Katran/loxilb/Calico/xdp-tools/selftests，见 #32-#36）
- **App-native deployment workload**：至少一个（Cilium/Katran 级别）🔄 未完成

### 5.35 Benchmark 设计约束

- **每个 corpus 程序必须有 exec_ns**。没有 "code size only" fallback。不能测 exec_ns 的程序不进 corpus。
- **BPF 程序用它在生产中被使用的方式来测量**。有原生应用的程序（Tracee/Tetragon/Katran/BCC/bpftrace/scx/KubeArmor）必须用 app-native loader，不用 generic libbpf。
- **两种测量路径，没有第三种**：(1) App-native：真实应用加载+触发 BPF，`bpf_enable_stats` 读 per-program exec_ns；(2) TEST_RUN：`BPF_PROG_TEST_RUN` 直接测，仅限 XDP/TC/socket_filter 等支持的 prog_type。
- **ARM64 默认走 AWS 远端**（t4g.small bench / t4g.micro test），不在本地 QEMU 跑 Python。
- **AWS 成本约束**（硬性规则）：所有 AWS 跑（smoke + authoritative）默认 `t3.small` x86 / `t4g.small` arm64（2 vCPU/2GB），test suite 用 `t3.micro` / `t4g.micro`。**`medium` 是绝对上限，仅允许作为 OOM 修复手段；禁止升级到 medium 以上**（不允许 c5/c6g、不允许 xlarge/2xlarge、不允许为 variance/并行/任何 SAMPLES 而升级）。variance 噪声 / 吞吐限制 / CPU credit throttling 必须通过代码优化（缩 workload、减少 tracing、降低并发 pass）解决，**不能换大机器**。spot instance 优先用于非时间敏感 run。SAMPLES 上限 = 3，paper-grade 由 per-program `min_runs ≥ 100` filter 决定，不靠 SAMPLES 拉到 30。
- **统计要求**：报告必须同时给 applied-only geomean 和 all-comparable geomean + sample count + comparison exclusion reasons。repeat ≥ 50，论文级 ≥ 500。

### 5.4 Required Hardware

1. Modern wide OoO x86 core ✅
2. Efficiency-oriented / Atom-like x86 ❌
3. arm64 系统 🔄（CI 有，性能数据有限）

### 5.6 Benchmark Framework 架构

#### 设计原则

- **BPF 程序用生产方式加载和触发**：有原生应用的程序由应用加载（app-native），不用 generic libbpf + 手写 trigger
- **Corpus 使用 App Runner**：同一个 AppRunner 类（start/workload/stop）负责真实应用生命周期，corpus 同时采集 per-program exec_ns 和原始 app workload metrics。
- **所有 corpus 程序必须用原生 app 加载**：禁止 bpftool loadall 替代原生 loader。每个 repo 都有原生 app/tool，没有 runner 的要去实现 runner。
- **三个正交维度：Loader × Workload × Measurement**：
  - **Loader**（谁加载 BPF）：原生 app（tracee, bcc/execsnoop, katran_server, libbpf-bootstrap/minimal, systemd, ...）。每个 repo 的程序必须由该 repo 自己的可执行文件加载。
  - **Workload driver**（什么触发 BPF 执行）：app 自身事件、exec_storm、fio、network_traffic 等。Workload 是独立维度，可叠加。
  - **Measurement**（读什么指标）：bpf_stats per-program exec_ns（corpus）以及原始 app throughput/latency/error counters
- **生命周期单元是 loader instance**：一个 loader instance = 一个可执行进程加载的所有 BPF 程序。Tracee 是一个 loader（启动一次加载 30+ BPF 程序）；BCC 的每个 tool（execsnoop, opensnoop, ...）是独立 loader（各加载 1-2 个 BPF 程序）；Katran 是一个 loader。Orchestrator 按 loader instance 分组，每个 instance 一次 start→measure→optimize→measure→stop 生命周期(optimize 由 runner 通过 per-pid shim socket 触发,见 §4)。
- **缺 runner 的 repo 必须补 runner**：不能标"不可测"然后跳过。没有 runner 是实现缺口，不是分类问题。
- **禁止在 object (.bpf.o) 层级做规划/分流/调度**：object 是编译产物的打包格式，对测量无意义。Orchestrator 的调度单元是 loader instance（app），不是 object。YAML 里不出现 .bpf.o 路径。program 通过 bpf_stats/get_next_id 在运行时自动发现，不需要预先枚举。
- **YAML 只列 app，不列 object/program**：YAML 定义 app（loader instance），每个 app 指定 runner + workload。启动 app 后通过 `list_progs` shim socket RPC 自动发现该 app 加载的 BPF 程序并测量,不需要在 YAML 里枚举 .bpf.o 或 program name。Object 只是编译产物的打包格式,和调度/测量无关。
- **YAML 定义 corpus app workload**：每个 app 指定 runner + workload。Corpus 读 bpf_stats exec_ns，并把原始 app workload metrics 放进 per-app JSON。
- **YAML schema**：
  ```yaml
  apps:
    - name: tracee
      runner: tracee
      workload:
        corpus: exec_storm     # corpus: bpf_stats + exec_storm
    - name: bcc/execsnoop
      runner: bcc
      tool: execsnoop
      workload:
        corpus: exec_storm
    - name: katran
      runner: katran
      workload:
        corpus: test_run       # corpus: BPF_PROG_TEST_RUN 精确测
  ```
- **Corpus TEST_RUN 走 Python + bpftool + ctypes**：`bpftool prog loadall/run/show` + `bpf_enable_stats` 直接测 live kernel program,同一加载实例上对比 baseline / post-optimize
- **micro 仍保留极简 C++ tool**：`micro_exec test-run` 只服务 isolated micro benchmark,没有 batch orchestration、没有 prepared state、没有 shim 通信
- **Python Orchestrator 是 corpus benchmark 的唯一编排者**：协调 app runner + shim socket + bpftool/bpf_stats 的顺序
- **每个测量单元是一个 loader instance**：没有跨 loader 的共享 state
- **并行在 orchestrator 层**：不同 loader instance 之间可并行（prepare 阶段），测量阶段串行避免 CPU 竞争噪声
- **Makefile 是唯一入口**：所有 benchmark 从 `make <suite>` 触发，平台由 `PLATFORM` / `ARCH` 选择
- **Same-image paired measurement**:load→baseline exec_ns→shim execute_step optimize→post exec_ns,同一加载实例上对比

#### 组件职责

```
┌─────────────────────────────────────────────────────────┐
│  macro_corpus.yaml                                       │
│  定义 WHAT：每个程序的测量方式                            │
│    measurement: app_native(repo=tracee) | test_run       │
│  不含 trigger 命令、io_mode 细节                         │
└───────────────────────┬─────────────────────────────────┘
                        │
┌───────────────────────▼─────────────────────────────────┐
│  Orchestrator（Python，~200 行）                         │
│  负责 WHEN + 协调顺序                                    │
│                                                          │
│  for each loader_instance:                               │
│    # Native app loader: app runner start                 │
│    # bpftool loader: bpftool loadall + attach            │
│    prog_ids = loader.start()                             │
│                                                          │
│    # Workload: test_run / exec_storm / fio / network     │
│    workload.run(seconds=10)                              │
│    baseline = read_bpf_stats(prog_ids)                   │
│                                                          │
│    shim_socket.execute_step(prog_ids, command)            │
│    workload.run(seconds=10)                              │
│    post = read_bpf_stats(prog_ids)                       │
│                                                          │
│    loader.stop()                                         │
│    report(prog_ids, baseline, post)                      │
│                                                          │
│  不做:BPF 加载、触发、测量实现、shim 内部细节            │
└────────┬─────────────────┬──────────────┬───────────────┘
         │                 │              │
┌────────▼────────┐  ┌─────▼──────┐  ┌────▼────────────────┐
│  Loader +       │  │  Shim (C,  │  │  bpftool +          │
│  Workload       │  │   in-app)  │  │  bpf_stats          │
│                 │  │            │  │                     │
│  负责:          │  │  负责:     │  │  负责:              │
│  start app      │  │  intercept │  │  prog loadall/run   │
│  run workload   │  │  执行命令  │  │  prog show + stats  │
│  stop app       │  │  swap     │  │  返回 exec_ns       │
│                 │  │            │  │                     │
│  不做:          │  │  不做:     │  │  不做:              │
│  BPF 加载       │  │  yaml 解析 │  │  shim 通信          │
│  直接测量       │  │  pass 调度 │  │  编排                │
│  优化           │  │  测量      │  │  app 生命周期       │
└─────────────────┘  └────────────┘  └─────────────────────┘
```

#### App-native 测量流程

```
Orchestrator              App + shim                                  bpf_stats
    │                       │                                            │
    ├── start(repo) ───────►│ LD_PRELOAD=shim.so, app starts             │
    │                       │ (shim binds /var/run/bpfrejit/shim-<pid>.sock)
    │                       │ app loads BPF; shim intercepts + tracks   │
    │◄── list_progs ────────┤                                            │
    │                       │                                            │
    ├── enable_bpf_stats ───────────────────────────────────────────────►│
    ├── workload.run(10s) ─►│ app drives events                          │
    ├── read_stats ─────────────────────────────────────────────────────►│ baseline exec_ns
    │                       │                                            │
    ├── execute_step(...) ─►│ shim: subst ${VAR} → /bin/sh -c bpfopt    │
    │                       │ shim: candidate BPF_PROG_LOAD + swap      │
    │                       │ (Phase 2 swap recipe per attach type)      │
    │                       │                                            │
    ├── workload.run(10s) ─►│                                            │
    ├── read_stats ─────────────────────────────────────────────────────►│ post exec_ns
    │                       │                                            │
    ├── stop() ────────────►│ cleanup                                    │
    │                       │                                            │
    ├── report(baseline, post)                                           │
```

#### Corpus App Runner Layer

```
runner/libs/app_runners/        ← Corpus app lifecycle layer
  tracee.py                       class TraceeRunner:
    def start() -> [prog_ids]       启动 tracee，返回加载的 BPF program IDs
    def run_workload(seconds)       exec storm / file IO / network traffic
    def stop()                      cleanup
  tetragon.py                     class TetragonRunner: ...
  katran.py                       class KatranRunner: ...
  bcc.py                          class BCCRunner: ...
  bpftrace.py                     class BpftraceRunner: ...
  scx.py                          class ScxRunner: ...

corpus/driver.py                使用 app_runners + bpftool + bpf_stats → per-program exec_ns
```

#### 目录布局（理想）

```
runner/                     # 共享基础设施
  libs/                     #   Python 共享库
    app_runners/            #     Per-repo app lifecycle
      tracee.py
      tetragon.py
      katran.py
      bcc.py
      ...
    results.py              #     JSON result 解析/聚合
    statistics.py           #     median/geomean/CI/Wilcoxon
    vm.py                   #     vng boot/exec helpers
    rejit.py                #     per-pid shim socket 通信(沿用原 daemon 时期的 JSON 协议)
    bpf_stats.py            #     bpf_enable_stats + read per-program stats
  src/                      #   C++ micro_exec(仅 TEST_RUN + llvmbpf)
  scripts/                  #   AWS/ARM64 远端脚本

corpus/                     # Corpus 评估层
  config/macro_corpus.yaml  #   程序列表 + 测量方式(app_native | test_run)
  driver.py                 #   调度:app_runner 或 micro_exec → 聚合结果

micro/                      # Micro 评估层
  programs/                 #   62 个 BPF .bpf.c
  driver.py                 #   调度 micro_exec

bpfopt/shim/                # LD_PRELOAD shim(C)+ musl variant
bpfopt/crates/bpfopt/       # bpfopt CLI(Rust,纯 bytecode rewriter)
runner/config/passes/       # 每个 pass 的 yaml 命令模板
```

详细设计文档见 `docs/tmp/20260320/benchmark-framework-design_20260320.md`。

---

## 6. 开发环境

**零内核改动**:任何 6.x stock kernel 都能跑。Repo 内 `vendor/linux` submodule 只为 selftest / micro / corpus 提供一个固定 baseline kernel,**不存在 fork 分支**。

### 6.1 开发栈

```
VM:        QEMU/KVM + virtme-ng(或裸跑 docker --privileged)
Kernel:    任何 stock 6.x(linux >= 6.7 推荐,有完整 link_update / SET_BPF 支持)
Shim:      bpfopt/shim/libbpfrejit_shim.so + libbpfrejit_shim_musl.so
bpfopt:    bpfopt/target/release/bpfopt(stock,无 syscall 依赖)
Benchmark: micro/driver.py + micro_exec via BPF_PROG_TEST_RUN; corpus/driver.py via app_runners
CI:        GitHub Actions ARM64 + x86(manual trigger)
```

### 6.2 Root Makefile 一键命令速查

| 命令 | 作用 |
|------|------|
| `make` (in `bpfopt/shim/`) | 构建 glibc shim |
| `make musl` (in `bpfopt/shim/`) | 在 alpine docker 里构建 musl shim(tracee 需要) |
| `make selftest-run` (in `bpfopt/shim/`) | 合成 PROG_LOAD selftest |
| `make smoke` (in `bpfopt/shim/`) | 对 `bpftool prog list` 跑 LD_PRELOAD smoke |
| `make test` | canonical 本地 x86 KVM 测试入口 |
| `make micro` | canonical 本地 x86 KVM micro benchmark 入口 |
| `make corpus` | 跑 corpus batch(默认 3 samples) |
| `PLATFORM=aws ARCH=arm64 make test` / `PLATFORM=aws ARCH=x86 make test` | canonical AWS 测试入口 |
| `make check` | 静态回归门禁(Python contract tests) |

---

## 7. 任务追踪

任务追踪已迁移到 git history。每个任务的详细记录在 commit messages 和 `docs/tmp/` 报告中。

- **历史记录（v1 #1 - #303 / v2 #304 - #673）**：归档在 git history;原 archive 文件已随 rename 一起淘汰
- **当前任务**：用 `git log --oneline` 查看
- **2026-05-05 changed flag deletion follow-up**：`docs/tmp/changed-flag-deletion-20260505.md`
- **调研报告**：`docs/tmp/` 按日期组织
