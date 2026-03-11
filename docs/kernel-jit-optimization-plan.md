# Kernel eBPF JIT 优化：计划与进度

> 本文档是 kernel JIT 优化论文的单一 hub。
> **编辑规则**：
> - 任何 TODO/实验/文档引用条目被取代时，必须至少保留一行并标注状态，不得直接删除。
> - 每个任务做完 → 立即更新本文档（任务条目状态 + 关键数据 + 文档路径）。
> - 每次 context 压缩后 → 完整读取本文档恢复全局状态。
> - 用 agent background 跑任务，不阻塞主对话。
> 上次更新：2026-03-11

---

## 1. 论文定位与策略

### 1.1 核心 Thesis：安全与优化的分离

> eBPF 程序由内核 JIT 编译为 native code 并在内核态执行——代码生成错误可导致内核崩溃。
> JIT 因此必须保守，但优化决策取决于 workload/微架构/部署上下文，而内核没有这些信息。
> **BpfReJIT 将安全（哪些 native code 变体可以安全生成）和优化（哪些变体应当应用）分离。**
> 内核定义有界的 safe variant menu，特权用户态根据上下文选择变体。

#### 论文逻辑链条（Abstract → Conclusion）

1. eBPF 广泛部署（网络、追踪、安全、调度）
2. Kernel JIT 编译为 native code，运行在内核态
3. 代码生成 bug = 内核崩溃，JIT 必须保守
4. 安全和优化耦合（所有 instruction selection 决策硬编码）
5. Operator 无法影响，正确选择取决于内核没有的部署上下文
6. Fixed heuristics 不行：policy-sensitivity（CMOV +28.3%）+ combination interference（LEA fixed-all +14.2%）
7. Operator 不能直接提供 native code（安全约束）
8. BpfReJIT 分离安全与优化

#### 类比定位

| 系统 | 耦合了什么 | 分离出什么 |
|------|-----------|-----------|
| Exokernel | 保护 + 资源管理 | 应用控制资源管理 |
| sched_ext | 调度机制 + 调度策略 | BPF 程序定义调度策略 |
| **BpfReJIT** | **JIT 安全 + JIT 优化策略** | **用户态定义优化策略** |

### 1.2 OSDI/SOSP Novelty

**真正 novel 的部分**：
1. **Safety/optimization 分离** — kernel 管安全，userspace 管优化策略
2. **Fail-closed backend policy substrate** — digest binding、verifier remap、CPU gating、exact validators
3. **部署控制权** — 优化 owner 是 Cilium/Katran 等 loader，不是 kernel maintainer
4. **Policy-sensitive 证据** — 同一合法站点在不同 workload 下需要不同 lowering

**Go 条件（全部满足才提交）**：
1. 原型实现多个 directive，展示框架泛化能力 ✅（4 families）
2. Fixed kernel baseline 不能在所有场景下达到同等收益 ✅（CMOV +28.3%）
3. 评估包含真实程序和至少一个端到端部署 🔄
4. 与 characterization 深度整合 ✅（已合并）

**与 existing work 的关键差异**：

| 系统 | 优化层 | 能解决 backend 差距? | 部署可控? |
|------|--------|:---:|:---:|
| K2 (SIGCOMM'21) | BPF bytecode | ❌ | ❌ |
| Merlin (ASPLOS'24) | LLVM IR + BPF | ❌ | ❌ |
| EPSO (ASE'25) | BPF bytecode | ❌ | ❌ |
| **BpfReJIT** | **Backend lowering** | **✅** | **✅** |

### 1.3 Why Userspace — 5 个独立理由

| 理由 | 说明 |
|------|------|
| **可更新性** | userspace policy DB 可以每周更新，kernel heuristic 只能等升级 |
| **程序级组合** | 局部有利的变换可能全局有害（I-cache cliff），userspace 做全局预算 |
| **Workload 适应** | 分支可预测性取决于运行时数据分布，不是 ISA 特性 |
| **Fleet A/B testing** | 5% 机器先上新 policy，看效果再推广，无需改 kernel |
| **所有权** | service owner 已经拥有 BPF 性能调优（Cilium/Katran），kernel maintainer 不应维护每个 service 的 heuristic |

### 1.4 核心设计约束

1. **xlated_prog_len 不变量**：所有 directive 只改 native code emission，不改 BPF 指令。如果 xlated 变了说明优化在错误的层。
2. **正确 directive 判断标准**：用户态能不能做同样的事？如果能 → 错误的层（POC v1 wide_load 教训：BPF 指令重写 = 错误层）。
3. **Kernel 改动最小化**：参数化 validator 模板，每个 directive ~50-100 LOC。
4. **Fail-closed**：任何验证失败 fallback 到标准 emission。
5. **安全模型**：内核从不执行用户态代码——只在自己预定义的安全变体间切换。
6. **Mandatory Falsification**：如果 fixed kernel heuristics 在所有测试硬件和 workload 上恢复相同收益，正确结论是"用 kernel peepholes"，不是发布 userspace-guided interface。
7. **Pipeline placement**：directive rewrites 发生在 `do_check()` 之后、`convert_ctx_accesses()` 之前。
8. **Constant blinding 兼容**：constant blinding 是独立的第二次 BPF 重写，会打乱 insn offset——当前设计在 blinding 发生时直接 drop directive set。
9. **JIT convergence loop**：x86 JIT 是 convergence loop + final image pass，directive 必须跨 pass 确定性一致。

### 1.5 设计方向决策

| 决策 | 结论 | 原因 |
|------|------|------|
| 不做简单 kernel patches | ❌ | 目标是论文（系统贡献）|
| 不用 target-independent IR | ❌ | 太重，且 JIT 层问题本身是 target-specific |
| JIT lowering 实现 | ✅ | 当前所有 directive 都是 JIT backend lowering（见§1.5 实现层次）|
| Post-load re-JIT | ✅ | 独立于 BPF_PROG_LOAD，运行中程序可反复 re-JIT |
| v5 声明式 pattern | ✅ | 新 BPF pattern 只需改 userspace，新 canonical form 需改 kernel |

#### 实现层次

当前所有 directive 都是 **JIT lowering**：只改 native code emission，不改 BPF 指令（xlated_prog_len 不变量）。
- `cmov_select`：JIT 在 diamond pattern 处选择 cmovcc vs jcc+mov
- `wide_load`：JIT 将连续 byte-load 合并为 wide mov
- `rotate_fusion`：JIT 将 shift+or 替换为 rorx/ror
- `lea_fusion`：JIT 将 mov+shl+add 替换为 lea

> `branch_reorder`、`subprog_inline` 等需要改 BPF 指令的变换属于 future scope（需 verifier-level 支持），当前不在实现范围内。

#### 实现阶段

| 阶段 | 内容 | 状态 |
|------|------|:---:|
| Phase 1 (POC v2) | 单个硬编码 JIT directive (cmov_select) | ✅ |
| Phase 2 (v4→v5) | Post-load re-JIT + 通用 dispatch + 声明式 pattern | ✅ |
| Phase 3 | 跨架构 + 自动化 + 端到端部署 | ❌ |

---

## 2. Characterization 证据摘要

| 证据 | 数值 |
|------|------|
| Exec time geomean (L/K) | 0.849x (31 pure-JIT) |
| Code size geomean (L/K) | 0.496x |
| Byte-recompose 占 kernel surplus | 50.7%，2.24x 时间惩罚 |
| cmov 差距 | llvmbpf 31 vs kernel 0 |
| Prologue/epilogue 占 surplus | 18.5% |
| branch_layout 输入敏感性 | predictable 0.225x vs random 0.326x，差 44.6% |
| Real-program code-size | 0.618x geomean (36 unique) |
| Real-program exec-time | 0.514x geomean (14 unique) |
| Pass ablation | 仅 InstCombinePass + SimplifyCFGPass 有效 |
| cmov 消融 | switch_dispatch +26%，binary_search +12%；bounds_ladder -18%，large_mixed -24% |

---

## 3. Directive 分类体系

### 3.1 Policy-sensitive（撑论文 novelty）

| Directive | Why userspace policy | 证据 | 状态 |
|-----------|---------------------|------|:---:|
| **`cmov_select`** | 依赖分支可预测性/依赖链深度/CPU 家族 | cmov ablation 混合结果；log2_fold +28% vs cmov_select -82% | ✅ v4+v5 |
| **`branch_reorder`** | 依赖 workload 热度/输入分布/code-size budget | branch_layout 差 44.6% | scope 外（需 verifier-level CFG permutation）|
| **`subprog_inline`** | 依赖热度/code-size/I-cache | corpus 97.2% multi-function | future |

### 3.2 Substrate（peephole，复用框架基础设施）

| Directive | 状态 | 说明 |
|-----------|:---:|------|
| `wide_load` | ✅ v4+v5 | 50.7% surplus recovery，11 sites |
| `rotate_fusion` | ✅ v4+v5 | BMI2 依赖，126 sites，-28.4% exec |
| `lea_fusion` | ✅ v4+v5 | 5 sites，stride_load_16 -12% |
| `bitfield_extract` | ❌ | packet header extraction，Cilium 高频 |
| `bounds_window` | ❌ | 冗余 bounds check，需 retained facts |

### 3.3 不应做的方向

完整寄存器分配、指令调度、任意 native code 注入、target-independent replacement IR。

---

## 4. 系统架构

### 4.1 Control Plane vs Data Plane

```
┌───────────────────────────────────────────┐
│  Userspace Backend Policy Plane           │
│  ┌─────────────────────────────────────┐  │
│  │ Candidate discovery (pattern match) │  │
│  │ Site feature extraction             │  │
│  │ CPU + workload policy DB            │  │
│  │ Fleet policy / A/B rollout          │  │
│  │ Code-size budget management         │  │
│  │ Directive blob generation           │  │
│  └─────────────────────────────────────┘  │
└──────────────────┬────────────────────────┘
                   │ BPF_PROG_JIT_RECOMPILE(prog_fd, policy_fd)
┌──────────────────▼────────────────────────┐
│  Kernel Safety Plane                      │
│  ┌─────────────────────────────────────┐  │
│  │ Digest binding + CPU contract       │  │
│  │ Post-verifier remap (orig_idx)      │  │
│  │ Shared precondition checks          │  │
│  │ Kind-specific validators            │  │
│  │ Arch-specific emitters              │  │
│  │ Fail-closed fallback + logging      │  │
│  └─────────────────────────────────────┘  │
└───────────────────────────────────────────┘
```

### 4.2 Arch-neutral / Arch-specific 分离

```
┌─────────────────────────────┐
│  Arch-neutral (共享)         │
│  - Directive blob 格式       │
│  - orig_idx remap           │
│  - CPU gating               │
│  - Fail-closed + logging    │
│  - Kind-specific validators │
└──────────┬──────────────────┘
    ┌──────┴──────┐
┌───┴───┐   ┌────┴────┐
│ x86   │   │ arm64   │
│ cmovcc│   │  csel   │
│ rorx  │   │  extr   │
│ lea   │   │  add    │
└───────┘   └─────────┘
```

### 4.3 Validator 模板

每新增 directive 只需：~50-100 LOC validator + ~50-100 LOC emitter (per arch)。
Transport/blob/remap/CPU gating/fail-closed 全部通用。

---

## 5. 评估计划

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
- **End-to-end deployment**：至少一个（Cilium/Katran 级别）🔄 未完成

### 5.4 Required Hardware

1. Modern wide OoO x86 core ✅
2. Smaller-core / Atom-like x86 ❌
3. arm64 系统 🔄（CI 有，性能数据有限）

---

## 6. Kernel 分支与开发环境

### 6.1 分支清单（`vendor/linux`）

| 分支 | 用途 | 状态 |
|------|------|:---:|
| `master` | upstream 7.0-rc2 stock baseline | 基准 |
| `jit-directive-v4` | v4 框架：BPF_PROG_JIT_RECOMPILE + 4 directives（稳定基线） | ✅ |
| `jit-directive-v5` | **主力**：v5 声明式 pattern + canonical lowering（基于 v4） | ✅ |
| `jit-fixed-baselines` | 对照：CONFIG_BPF_JIT_FIXED_{ROTATE,WIDE_MEM,LEA,CMOV} | ✅ |
| `jit-directive-poc-v2` | 历史：POC v2 cmov_select 单 directive | 已被 v4 取代 |
| `jit-directive-poc` | 历史：POC v1 wide_load（方向错误）| 已弃用 |

### 6.2 Worktree 布局

- `vendor/linux` — 当前工作目录（可切换分支）
- `vendor/linux-framework` — `jit-directive-v5` worktree（永驻，基于 v4）
- `vendor/linux-baseline` — `master` worktree（stock 7.0-rc2，永驻）

### 6.3 开发环境

```
VM:        QEMU/KVM + virtme-ng
Kernel:    vendor/linux (v7.0-rc2) as submodule
JIT file:  arch/x86/net/bpf_jit_comp.c
Benchmark: micro/run_micro.py + micro_exec via BPF_PROG_TEST_RUN
Baseline:  host 6.15.11 + VM 7.0-rc2
CI:        GitHub Actions ARM64 + x86 (manual trigger)
VM 使用:   make -j$(nproc) bzImage && vng --run <worktree>/arch/x86/boot/bzImage --exec "..."
```

> v4 policy 优先级：在 `jit-fixed-baselines` 上，如果 v4 policy 附加到 prog，v4 规则优先于 fixed heuristic。

---

## 7. 任务追踪

> **规则**：
> - 所有重要数据和文档路径只在本列表维护，不在别处重复。
> - 每次执行 subagent 都必须输出文档到 `docs/tmp/` 或 `micro/results/`，并在对应条目记录路径和关键数据。
> - 条目被取代时保留一行标注状态，不得删除。

| # | 任务 | 状态 | 关键数据 / 文档 |
|---|------|:---:|------|
| 1 | v3 可扩展 JIT pass 框架设计 | ✅ | 8/10 review。`docs/tmp/jit-pass-framework-v3-design.md`，`docs/tmp/jit-pass-framework-v3-final-verdict.md` |
| 2 | v4 Post-load re-JIT 框架设计 | ✅ | `docs/tmp/jit-pass-framework-v4-design.md` |
| 3 | v5 声明式 Pattern 框架设计 | ✅ | 7.5/10 review。`docs/tmp/jit-pass-framework-v5-design.md`，`docs/tmp/jit-pass-framework-v5-review.md` |
| 4 | Design-v7 Hybrid 设计 | ✅ | `docs/tmp/bpf-jit-advisor-v7.md`，`docs/tmp/bpf-jit-advisor-v7-review.md` |
| 5 | Interface 详细设计 | ✅ | syscall/blob/CPU contract/安全/部署。`docs/tmp/interface-design-detail.md`，review 6/10 `docs/tmp/interface-design-review.md` |
| 6 | Verifier-rewrite 方案分析 | ✅ | 结论：JIT lowering 为主，verifier-level 属 future scope。`docs/tmp/verifier-rewrite-approach.md` |
| 7 | Policy decision layer 设计 | ✅ | 3 级策略（static/profile/AB）。`docs/tmp/policy-decision-layer-design.md` |
| 8 | Directive 发现 + 分类 | ✅ | 11 候选排名，5 新 benchmark。`docs/tmp/directive-discovery-analysis.md` |
| 9 | OSDI readiness review | ✅ | 4/10。`docs/tmp/osdi-readiness-review.md` |
| 10 | 跨文档交叉验证 | ✅ | `docs/tmp/cross-document-review.md` |
| 11 | POC v1: wide_load verifier rewrite | ⚠️ 方向错误 | BPF 指令重写 = 错误层（userspace 也能做）。`docs/tmp/poc-design-review.md` |
| 12 | POC v2: cmov_select JIT lowering | ✅ | xlated 7480→7480 不变，jited 4168→4167。`dd81852`。`docs/tmp/poc-v2-design-conformance-review.md` |
| 13 | v4 POC 实现（4 directives） | ✅ | CMOV+WIDE+ROTATE+LEA，BPF_PROG_JIT_RECOMPILE，~850 LOC kernel。branch `jit-directive-v4` |
| 14 | v4 correctness bug 修复 | ✅ | flag-clobber + subprog boundary + interior edge。`docs/tmp/v4-bug-diagnosis.md` |
| 15 | v4 implementation review | ✅ | 6/10，10 gaps (R1-R10)。`docs/tmp/v4-implementation-review.md` |
| 16 | v4 Round 1 修复 + 重测 | ✅ | R1/R3/R5/R6/R7 修复。ADDR_CALC: 4 prog 5 sites, stride_load_16 -12%。COND_SELECT: 1 prog 6 sites, log2_fold +28%（policy-sensitivity）。ROTATE/WIDE 仍 0 覆盖。`docs/tmp/v4-round1-test-results.md` |
| 17 | v4 Round 2: WIDE_MEM 突破 | ✅ | WIDE_MEM 0→11 sites（3 prog），load_byte_recompose -13%，stride_load_4 -14%。ROTATE 仍 0。`docs/tmp/v4-round2-test-results.md`，`docs/tmp/v4-round2-implementation.md` |
| 18 | v4 Round 3: ROTATE 突破 | ✅ | ALL 4 families active。ROTATE 0→126 sites（2 prog），rotate64_hash -28.4% exec -32.3% code，packet_rss_hash -10.5%。ROTATE+WIDE combined -36.6% exec -35% code（composability 验证）。kernel `3d3587b8c`。`docs/tmp/v4-round3-test-results.md` |
| 19 | Kernel-fixed baselines 设计 | ✅ | `docs/tmp/kernel-fixed-baselines-design.md` |
| 20 | Kernel-fixed baselines 测试 | ✅ | **Go/no-go PASSED**。fixed-all: rotate64_hash -16.8%, load_byte_recompose -13.0%, stride_load_16 +14.2%（LEA 组合回归），**log2_fold +28.3%**（CMOV 伤害）。结论：ROTATE/WIDE substrate 可固定，CMOV 必须 policy-controlled。kernel `1572a4ddb` on `jit-fixed-baselines`。`docs/tmp/kernel-fixed-baselines-test-results.md` |
| 21 | Per-directive 隔离测试 | ✅ | CMOV-only 只改 log2_fold（+19.7%），code size 可加但 exec time 不可加。`docs/tmp/kernel-fixed-baselines-per-directive.md` |
| 22 | v5 声明式 pattern POC | ✅ | rotate64_hash v5=v4（115 sites, jited 2409）。`docs/tmp/v5-minimal-poc-results.md` |
| 23 | v5 迭代改进 | ✅ | CMOV 上 v5（6 sites, +76%）。scanner 统一。`docs/tmp/v5-iteration-results.md` |
| 24 | v5 canonical binding table | ✅ | COND_SELECT + ROTATE 验证通过。v5 extensibility: v4 1018 LOC vs v5 32 LOC (32x)。`docs/tmp/v5-canonical-binding-results.md`，`docs/tmp/extensibility-quantification.md` |
| 25 | Scanner 独立化到 scanner/ | ✅ | kernel_runner.cpp 删除全部重复代码。`docs/tmp/scanner-cleanup-results.md` |
| 26 | v5 design gap analysis | ✅ | 6.5/10。`docs/tmp/v5-design-gap-analysis.md` |
| 27 | Framework architecture review | ✅ | 4/10。`docs/tmp/framework-architecture-review.md` |
| 28 | cmov_select subprog scan 修复 | ⚠️ | scanner 0→1 site ✅，但 emitter correctness bug 待修。`docs/tmp/cmov-subprog-fix-results.md` |
| 29 | Pure-JIT benchmark 审计 | ✅ | 49/50 OK，`map_lookup_repeat` 移到 runtime。`docs/tmp/pure-jit-benchmark-audit.md` |
| 30 | Host 重跑 50+11 | ✅ | pure-jit L/K=0.797x, runtime L/K=0.875x。`micro/results/pure_jit_with_cmov.json` |
| 31 | VM 重跑 (7.0-rc2) | ✅ | kernel VM/host=1.003x (parity)。`docs/tmp/vm-rerun-analysis.md` |
| 32 | Real program directive census | ✅ | 98 EM_BPF 扫描，67/98 有 sites，1029 总 sites。`docs/tmp/real-program-directive-census.md`，`micro/directive_census.py` |
| 33 | Corpus v5 recompile | ✅ | 37/40 apply 成功。xdp_synproxy +15%/+31%。`docs/tmp/corpus-v5-recompile-results.md` |
| 34 | Production corpus 编译 | ✅ | Cilium 3 prog（658 CMOV），Katran 5，xdp-tools 13。总 493。Cilium 无法加载（Operation not supported，需 kfunc）。`docs/tmp/production-program-compilation.md` |
| 35 | Production corpus v5 recompile | ✅ | 15/15 成功。katran -0.2%，xdp_vlan_swap -5.7%。`docs/tmp/production-corpus-v5-rerun-results.md` |
| 36 | Corpus 扩充 Round 2 | ✅ | +21→529 总 .bpf.o（22 个项目）。loxilb 912 sites/prog，Calico 314 sites。`docs/tmp/corpus-expansion-round2.md` |
| 37 | Scanner rotate gap 修复 | ✅ | core_kern 0→818，test_verif_scale2 0→992。`docs/tmp/scanner-gap-fix.md` |
| 38 | 严格 benchmarking | ✅ | 10×1000, CPU pin#23, perf governor, turbo off, Wilcoxon BH-adjusted。CMOV 0.655x (p=0.002), ROTATE 1.193x/1.235x (p=0.002), LEA 1.052x (p=0.012), WIDE 不显著 (p=0.164)。`docs/tmp/rigorous-benchmark-results.md` |
| 39 | 微架构实验 | ✅ | CPU 频率敏感性：binary_search 31.7%，load_byte_recompose 33.2%。输入分布：branch_layout predictable 0.225x vs random 0.326x（差 44.6%）。PMU：llvmbpf IPC 普遍高于 kernel（binary_search 6.86 vs 2.41）。`docs/tmp/microarch_experiments.md` |
| 40 | ARM64 CI 全流程 | ✅ | 3 轮修复。commits `1c17332`, `d2bd851`, `d8edc80` |
| 41 | ARM64 跨架构分析 | ✅ | pure-jit L/K=0.656x（vs x86 0.797x）。`docs/tmp/arm64-cross-arch-analysis.md`，review `docs/tmp/arm64-analysis-review.md` |
| 42 | Debug BPF_PROG_JIT_RECOMPILE EINVAL | ✅ | production programs 的 EINVAL 问题 |
| 43 | Benchmark 基础设施审计 | ✅ | `docs/tmp/benchmark-infrastructure-audit.md` |
| 44 | Benchmark 基础设施分析（重构方案） | ✅ | P0: 5 个 bug，P1: 10 项结构问题。`docs/tmp/benchmark-framework-analysis.md` |
| 45 | 论文 LaTeX 初稿 | 🔄 | ACM sigconf。R1 4/10 → R2 6/10 → R3 6.5/10。`docs/paper/paper.tex`，`docs/tmp/paper-review-r3-post-rewrite.md` |
| 46 | **COND_SELECT 上 v5 path** | ✅ | v5 pattern descriptor + canonical binding + parameterized emitter。scanner 找到 1 cmov site，VM 验证 result 一致，xlated 7480 不变，jited 4168→4167。`docs/tmp/cmov-v5-migration-report.md`，包含在 `jit-directive-v5` commit `2a6783cc7` |
| 47 | **cmov_select emitter bug 修复** | ✅ | 根因：absolute-vs-local site index 混用。修复：`bpf_jit_rule_local_site_start()` rebases site_start 到 subprog 本地。验证：cmov_select baseline=recompile，log2_fold 无回归。`docs/tmp/cmov-emitter-fix-report.md`，包含在 `jit-directive-v5` commit `2a6783cc7` |
| 48 | **Benchmark 基础设施重构** | 🔄 | P0 5/5 修复完成：call-overhead category、macro repeat、默认路径、按需 root/scanner、stats 统一 median。`docs/tmp/p0-bugfix-report.md`。P1 结构问题待做 |
| 49 | **端到端部署评估** | ❌ | Cilium/Katran 级别，论文 go 条件之一。需至少一个 PPS throughput 数据（见 #63） |
| 50 | **论文更新** | 🔄 | 集成 Round 3 + fixed baselines + corpus 数据 |
| 51 | jit_recompile 加 log_level/log_buf | ❌ | 用户态无法观察 rule accept/reject，policy 迭代缺 feedback |
| 52 | Shape whitelist 扩展 | ❌ | 硬编码 site_len 白名单，新 pattern 可能被 kernel 误拒 |
| 53 | Overlap/priority 语义 | ❌ | 当前 kernel 不拒绝也不仲裁重叠 rule |
| 54 | Subprog 一致性 | ❌ | v4 分支与 fixed-baselines 分支的 subprog 处理不同步 |
| 55 | K2/Merlin/EPSO 对比实验 | ✅ | **正交非替代**。backend-only gap 占 surplus 89.1%。dual-pass spot check: size geomean 0.995x（IR 侧几乎碰不到 backend gap）。K2/Merlin 代码可获取但不兼容当前 pipeline，EPSO 无公开 artifact。`docs/tmp/k2-merlin-epso-comparison.md`，`micro/results/llvm_dual_pass_boundary_spotcheck.md` |
| 56 | Re-JIT 原子性 / RCU 安全说明 | ✅ | POC benchmark-only safe（单线程 test_run）。Production 需：per-prog 串行化 + shadow image + RCU retirement + tailcall/trampoline 刷新。旧 image JIT text leak 未回收。`docs/tmp/rejit-rcu-safety-analysis.md` |
| 57 | 消融补全 | ❌ | byte-recompose / callee-saved / BMI |
| 58 | ZERO_EXTEND directive | ❌ | movzx vs xor+mov |
| 59 | ARM64 target backend | ❌ | 跨架构验证 |
| 60 | 严格重跑（30×1000） | ❌ | CPU pinning + performance governor |
| 61 | **Benchmark 多样性** | ❌ | 当前 61 个 micro 全是 XDP，需补 cgroup_skb/fentry/TC 类型 |
| 62 | **CMOV kernel JIT benefit 信号增强** | ❌ | cmov_select 仅 2.8% 改善，需更强 signal（更多 cmov-heavy benchmark 或不同微架构） |
| 63 | **End-to-end throughput 数据** | ❌ | 至少一个 PPS 数据（Katran XDP / Calico），#49 的子任务 |
| 64 | **Corpus 可运行性盘点 + 自动化 recompile** | ✅ | 532 objects, 1836 progs, 1214 loadable, 274 有 sites, 381 truly runnable。79 paired baseline/recompile (sched_cls 61, xdp 16, cgroup_skb 2)。3069 total sites (CMOV 840, WIDE 389, ROTATE 1840)。新脚本 `micro/run_corpus_runnability.py`。`docs/tmp/corpus-runnability-report.md`, `docs/tmp/corpus-runnability-results.json` |
| 65 | **Corpus 批量 recompile 实验** | ✅ | 78 measured pairs，7 项目。原始 exec geomean 0.813x，**排除噪声后 0.847x**（32/78 sub-resolution <50ns）。CMOV-only 可靠程序 0.718x（11/11 回归，验证 policy-sensitivity）。CMOV+WIDE 0.848x。噪声严重（控制组 ±36%）。`docs/tmp/corpus-batch-recompile-results.md`，`docs/tmp/corpus-recompile-regression-analysis.md` |
| 66 | **非网络端到端场景研究** | ✅ | **最佳 OSDI 方案**：Phase 1: Tracee（169 progs, 555 sites）+ Tetragon（kprobe/tracepoint）+ bpftrace（--emit-elf）。Phase 2: scx_rusty（11 struct_ops hooks）+ scx_lavd（22 hooks）。Corpus 已有大量非网络程序未利用：kprobe 508, tracing 442, tracepoint 151, lsm 75, struct_ops 51。核心差距不是"有没有程序"而是"有没有 honest attach+trigger 路径"。`docs/tmp/non-networking-evaluation-plan.md` |
| 67 | **Benchmark 框架重构 Step 1-3** | ✅ | `micro/orchestrator/` 5 模块（commands/results/environment/inventory/__init__）。`run_micro.py` 迁移到共享库。`UnifiedResultRecord` schema。README 55+11 修正。`directive_census.py` 动态计数。commit `c000ed3`。`docs/tmp/framework-improvement-step1.md` |
| 68 | **Corpus 扩展 Round 3** | ✅ | 560 objects（23 项目）, 2010 progs, 1280 loadable, 293 有 sites, 391 truly runnable（由 #64 baseline + Round 3 targeted reruns 合并）。新增/扩充：`scx` 4、`tetragon` 23、`systemd` 6 source-backed rebuild、5 个 selftests；`netbird` source-backed rebuild 但仍 `bpf_object__open_file` fail。新增 manifest `config/corpus_manifest.yaml`。`docs/tmp/corpus-expansion-round3.md`, `docs/tmp/corpus-expansion-round3-priority-runnability.md`, `docs/tmp/corpus-expansion-round3-selftests-runnability.md` |
| 69 | **Selective CMOV policy + corpus rerun** | ✅ | `micro_exec`/`run_corpus_v5_vm_batch.py` 新增 `--skip-families`，可在 v5 auto-scan policy 中排除 CMOV。blind-all rerun（repeat=200）原始 geomean `0.826x`；selective `--skip-families cmov` 原始 geomean `0.813x`，**未**在 full corpus 上胜出。但在 shared non-sub subset（46 measured rows, all four exec_ns >=50ns）selective `0.870x` > blind-all `0.828x`；Calico raw `0.865x` > `0.828x`，Calico non-sub CMOV-only `0.886x` > `0.811x`，CMOV+WIDE `0.846x` > `0.819x`。结论：global skip-cmov 只在目标 Calico predictable-branch slice 上证明有效，不足以给 raw corpus 带来净收益。`docs/tmp/corpus-batch-recompile-results.md`, `docs/tmp/corpus-batch-recompile-selective-results.md`, `docs/tmp/selective-policy-results.md` |
| 70 | **bpftrace 端到端 benchmark driver** | ✅ | 新增 `micro/run_e2e_bpftrace.py`：自动检查/安装 `bpftrace` + `stress-ng`，构建 `micro_exec`，跑 5 个代表性 bpftrace 脚本，支持 `--emit-elf` artifact-first 路径（原始 ELF candidate site census + libbpf-style section rename + `micro_exec --compile-only` load probe）和 live attach+trigger 路径（`bpftool prog show` 发现 bpftrace-owned programs，libbpf 读 `run_cnt/run_time_ns`，scanner `scan/apply --v5`，workload 前后比较 avg exec ns）。当前 host 全量实测：`--emit-elf` 5/5，live attach 5/5，检测到 9 个 CMOV sites（`open_latency` 5，`scheduler_latency` 4），generic artifact load 0/5；live `BPF_PROG_JIT_RECOMPILE` 在有 sites 的脚本上仍返回 `EINVAL`，因此 `rejit_ns/speedup` 为 `n/a`。结果：`docs/tmp/bpftrace-e2e-results.json`, `docs/tmp/bpftrace-e2e-results.md` |
| 70 | **Tetragon attach+trigger harness** | ✅ | 新脚本 `micro/run_e2e_tetragon.py`：优先尝试 Tetragon daemon + `TracingPolicy`，默认 fallback 到本地 `.bpf.o` whole-object load + explicit attach（`event_execve -> syscalls/sys_enter_execve`，`generic_kprobe_event -> security_file_open/security_socket_connect`），scanner v5 site census + JSON/Markdown 输出。Smoke（2026-03-11, host kernel `6.15.11-061511-generic`）：stock 3/3 OK，sites `event_execve=37`、`generic_kprobe_event=2`；avg_ns `2670/222/685`。当前 host 上 `BPF_PROG_JIT_RECOMPILE` 返回 `EINVAL`，re-JIT 对比待 framework kernel 重跑。输出：`docs/tmp/tetragon-e2e-results.json`，`docs/tmp/tetragon-e2e-results.md` |
| 70b | **BPF-side VM 测试** | ✅ | Tracee VM: sched_process_exec **2.71x**，security_file_open 1.17x，lsm_file_open 1.10x，security_socket_connect 0.66x（CMOV 回归）。bpftrace VM: open_latency 0.947x，scheduler_latency 0.965x（pure CMOV 回归，geomean 0.956x）。Tetragon VM: 0/3 失败（kernel 缺 CONFIG_FTRACE_SYSCALLS + CONFIG_BPF_KPROBE_OVERRIDE）。注意：这些都是 BPF run_time_ns 测量，**不是真正的端到端**。`docs/tmp/tracee-e2e-vm-summary.md`，`docs/tmp/bpftrace-e2e-vm-summary.md`，`docs/tmp/tetragon-e2e-vm-summary.md` |
| 70c | **Benchmark 框架重构 Steps 2-7** | ✅ | 统一入口 `micro/driver.py`（5 子命令），新增 `orchestrator/catalog.py`（统一 manifest loader）+ `orchestrator/reporting.py`（共享报告层）+ `orchestrator/corpus.py` + `orchestrator/rigorous.py`。旧 `run_*.py` 降级为兼容 wrapper → `_driver_impl_*.py`。`summarize_rq.py` / `generate_figures.py` 不再硬编码旧 benchmark 数。`docs/tmp/framework-improvement-steps2-7.md` |
| 71 | **仓库层次重组** | ❌ | 三层划分：`micro/`（隔离微基准）、`corpus/`（真实程序收集+测量+分析）、`e2e/`（端到端部署+分析）。corpus 测量脚本从 micro/ 移到 corpus/，e2e 脚本从 micro/ 移到 e2e/，分析脚本留在各自数据目录。orchestrator 留在 micro/ 供三层引用。legacy/ 收纳旧代码 |
| 72 | **E2E 骨架 + Tracee 真正端到端** | ❌ | 创建 `e2e/common/`（agent/workload/metrics/recompile/vm），实现 `e2e/cases/tracee/`：安装 Tracee daemon → baseline 60s（app ops/s + events/s + drops + CPU）→ recompile → post-reJIT 60s → 比较。必须在 VM 上跑出 stock vs recompiled 数据 |
| 73 | **Framework kernel 重编** | ❌ | vendor/linux-framework 添加 CONFIG_FTRACE_SYSCALLS=y + CONFIG_BPF_KPROBE_OVERRIDE=y + CONFIG_SCHED_CLASS_EXT=y，重编 bzImage，验证 Tetragon 程序可加载 + recompile 仍工作 |
| 74 | **Tetragon 真正端到端** | ❌ | 依赖 #71 + #73。`e2e/cases/tetragon/`：Tetragon daemon + TracingPolicy → trigger → 测 app throughput + events/s + overhead metrics。VM 上跑 |
| 75 | **bpftrace 真正端到端** | ❌ | 依赖 #71。`e2e/cases/bpftrace/`：启动 bpftrace 脚本 → recompile → workload → 测 app throughput + events/s + drops。VM 上跑 |
| 76 | **scx_rusty/lavd 端到端** | ❌ | 依赖 #71 + #73。`e2e/cases/scx/`：注册 struct_ops 调度器 → recompile → hackbench/schbench → 测 wakeup latency + throughput。需要 CONFIG_SCHED_CLASS_EXT kernel |
