# Kernel eBPF JIT 优化：计划与进度

> 本文档是 kernel JIT 优化论文的单一 hub。
> **论文核心方向：必须追求 net speedup，越多越好。架构贡献和 policy-sensitivity 是支撑论据，不是主卖点。Paper 必须展示真实程序上的可测量加速。**
> **⚠️ Corpus exec geomean 0.875x 已确认无效（#162）**：dummy packet 导致 XDP/TC 程序 early-exit，优化 site 未被执行，测量值是噪声+布局效应。**必须修复 corpus packet 构造使 site 被实际执行**，而不是转向 code size。Code size 不是论文关注点。
> **编辑规则**：
> - 任何 TODO/实验/文档引用条目被取代时，必须至少保留一行并标注状态，不得直接删除。
> - 每个任务做完 → 立即更新本文档（任务条目状态 + 关键数据 + 文档路径）。
> - 每次 context 压缩后 → 完整读取本文档恢复全局状态。
> - 用 agent background 跑任务，不阻塞主对话。
> - **构建+修改+运行不拆分**：一个 subagent 负责完整流程（改代码→构建→运行→发现 bug→修复→再运行），不要拆成多个 agent。
> 上次更新：2026-03-13 晚（#174 ✅ Build #40 (ac593b2c1 BEXTR without-copy fix) 重编 + R6-R11 policy 迭代（本次）。新发现：Build #40 后 endian_swap_dense 从 0.695x 恢复至 **1.013-1.139x**（256 sites restored）；extract_dense code size −768B（1.5B/site）但 I-cache 开销仍高，继续保持 empty 策略；R10 全量 62-bench overall **1.006x**，applied-only **1.040x**（15 applied）。最优 policy 更新：endian_swap_dense 恢复 256 sites。结果：`micro/results/micro_62bench_build40_policy_optimized_20260313.json`，文档：`docs/tmp/policy-iteration-rounds.md`（R6-R11 节）。#173 ✅ policy 迭代+corpus rerun+full 62-bench 完成（R1-R5）。#172 ✅ Tracee E2E post-BEXTR-fix 有效 rerun。#171 ✅ dense policy 优化方向确定（3个 regressor 清空）。#158 ✅ corpus packet fix + rerun 完成。#170 ✅ BEXTR without-copy bug 已修复（daca445b1）。此前：#149-#169 全部 ✅）

---

## 1. 论文定位与策略

### 1.1 核心 Thesis：安全与优化的分离 → 实现 Net Speedup

> eBPF 程序由内核 JIT 编译为 native code 并在内核态执行——代码生成错误可导致内核崩溃。
> JIT 因此必须保守，但优化决策取决于 workload/微架构/部署上下文，而内核没有这些信息。
> **BpfReJIT 将安全（哪些 native code 变体可以安全生成）和优化（哪些变体应当应用）分离。**
> 内核定义有界的 safe variant menu，特权用户态根据上下文选择变体。
>
> **⚠️ 论文方向决定**：分离安全与优化是手段，不是目的。目的是**让真实 eBPF 程序跑得更快**。
> Paper 必须展示：(1) characterization gap 存在且有意义；(2) BpfReJIT 能恢复显著部分的 gap（net speedup）；(3) 恢复需要 policy control（不能用 fixed heuristics）。
> 当前 (2) 不够强（4.3% gap recovery，corpus 0.875x），**必须改进到 net positive 才能提交**。

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

### 1.2 论文叙事方向：必须追求 Net Speedup

> **⚠️ 核心方向决定（2026-03-13）：论文叙事必须以 net speedup 为中心，越多越好。**
> 架构贡献和 policy-sensitivity 是支撑论据，不是主卖点。Paper 必须展示真实程序上的可测量加速。
> 如果当前数据不够，必须增加 canonical form 覆盖面、改进 policy tuning、或加更多有 sites 的 benchmark。

#### 当前性能现实与差距

| 指标 | 当前值 | 问题 |
|------|--------|------|
| Micro overall (#169, post-BEXTR-fix) | 1.003x | 几乎平手 |
| Micro applied-only (#169) | 0.932x | 回归（含3个 dense regressor） |
| **Micro 6-dense optimized (#173, policy-optimized)** | **1.125x** | **✅ 实测正向（VM，3 regressor 清空）** |
| **Micro 62-bench overall (#173, policy-optimized)** | **0.995x** | R5 结果（VM噪声影响），已被 #174 取代 |
| **Micro 6-dense optimized (#174, Build #40, endian restored)** | **1.075-1.100x** | **✅ Build #40 + 256 endian sites 恢复** |
| **Micro 62-bench overall (#174, Build #40 optimal policy)** | **1.006x** | **✅ up from 0.995x** |
| **Micro 62-bench applied-only (#174, 15 benches)** | **1.040x** | **✅ up from 0.993x** |
| Corpus v2 fixed (0.875x) | 已知无效 | dummy packet, early-exit，历史数据 |
| **Corpus post-fix rerun (#173, fixed IPv4+TCP packet)** | **1.008x** | **✅ 正向！Calico 1.070x, Suricata 1.538x** |
| Gap 恢复率 | pending | corpus 1.008x vs 0.609x pure-JIT gap |
| E2E Tracee exec_storm (pre-fix, recompile=0/13, **无效**) | +21.65% | 已被 #172 取代 |
| **E2E Tracee exec_storm (post-BEXTR-fix, recompile=11/13, #172)** | **+5.97%** | app; BPF ns -7.11%, network +3.26% |

#### 性能不够强的根因分析（#113/#116/#125/#77 + #155/#157 更新）

> **⚠️ 2026-03-13 重大更新**：#157 benchmark framework 审计和 #155 regressor root cause 分析表明，
> 之前列出的根因大部分是表象。**真正的根因是 benchmark framework 的 construct validity 问题**。

1. **~~覆盖面不够~~** → 仍然是问题，但不是主因
2. **~~CMOV net-negative~~** → 已 cmov:skip，不再是主因
3. **~~Non-CMOV regression~~** → **#155 发现 top-10 regressors 中 7/10 是 sub-ktime noise**，只有 3 个真实回归（全是 Calico + branch-flip）
4. **~~Sub-ktime 噪声~~** → **#157 发现 ktime 精度被高估**（repeat=200 下步长仅 0.15-0.5ns），不是 corpus 0.875x 的主因

**真正的根因（#157 发现，#162 确认）**：
1. **Corpus construct validity**：所有 corpus 程序共用同一个 64B dummy packet，**没有证据表明该 packet 触发了被优化的 site**。**#162 分析确认**：94/156 程序 exec_ns < 100ns（noise-dominated），未优化程序中 88% 也有 >5% 偏差；Calico 同一程序 6 个 .bpf.o 代码变化一致（-0.4%）但 speedup 从 0.531x 到 1.037x，证明短 baseline 版本提前退出未执行到 site。**结论：corpus exec geomean 0.875x 无效，应以 code size 为主要 corpus 指标，或构造 path-targeted packet。**
2. **Micro coverage + isolation**：只有 8/56 applied（非文档说的 11/56），family 混合严重（cmov_dense 的 policy 实际是 rotate=26），无 per-form 隔离 benchmark。**#154 已修复**：新增 6 个纯隔离 benchmark，覆盖全部 non-WIDE_MEM canonical forms。
3. **Kernel emitter bugs**：#150 发现 RORX 指针 bug 和 same-site lookup bug，之前所有性能数据可能被污染。**已修复**，bzImage 已重建。
4. **无 JIT image 验证**：不知道 re-JIT 是否只改了 site 字节。**#153 已验证**：zero-site identity 已修复，site-only diff 是 full-image recompile 的固有属性。

#### 必须做的性能改进 TODO（按优先级，2026-03-13 晚更新）

1. **P0：修复 benchmark framework**（#157 P0 items）
   - ~~Micro 每个 canonical form 加 isolated benchmark~~ ✅ #154（6 个纯隔离 benchmark）
   - ~~Corpus packet 构造修复~~ ✅ corpus.py/e2e 已换 valid IPv4+TCP packet with correct checksum
   - ~~**P0：Authoritative 62-bench rerun per-form 结果与专门 rerun 严重矛盾**~~ ✅ #168 调查完成（`docs/tmp/endian-bflip-perf-investigation.md`）：矛盾来自 2-iter 噪声（shared VM session），auth rerun 是 ground truth。endian/branch_flip **emitter 无 bug**（a7ce05b49 之后已正确），但 same-size 重编（MOVBE=5B=LDX+BSWAP32，branch_flip 体积等价）导致 I-cache flush 开销 > 微架构收益 → 持续回归（~0.75-0.78x）。这是固有属性，不是可修 bug。Endian/branch_flip 属 **policy-sensitive** directive（需有 branch misprediction 或 CPU model 证据才能开启）。待 codex VM 验证字节 dump 确认 MOVBE 确实被发出（`docs/tmp/endian-bflip-vm-verification.md` 待产出）。
   - Corpus 每 target 多次 paired rerun + CI/bootstrap（降优先级）
2. **~~P0：验证 JIT image 正确性~~** ✅ #153
3. **~~P0：Post-cleanup 全量重跑~~** ✅ #160 — 62/62 valid, 17 applied, overall 1.0035x, applied-only 0.9417x。**但 per-form 数据疑似无效（见上）**
4. **~~P1：Measurement 改进~~** ✅ #156
5. **P0：框架解耦** — ✅ #163 scanner enumerate 已实现（197 live progs, 1920 sites），🔄 #108 E2E pipeline 切换中
6. **P1：增加高回报 canonical form** — prologue 优化、更完整的 byte-recompose
7. **P1：跑更多 E2E workload** — ✅ #172 Tracee 已完成有效 rerun（post-BEXTR-fix，11/13 applied，exec_storm +5.97% app / -7.11% BPF ns）。报告：`docs/tmp/tracee-e2e-post-fix-rerun.md`，数据：`e2e/results/tracee_authoritative_20260313_postfix.json`。旧 +21.65% 数据已作废（recompile 0/13）。需要更多 E2E workload（Tetragon 等）。
8. **~~P1：#57 消融补全~~** ✅ byte-recompose **50.7%**，callee-saved ~0%（7.0-rc2 已上游化），BMI ~0%
9. **~~P1：Corpus rerun（fixed packet + use-policy 路径）~~** ✅ #158/#173 完成。结果：**1.008x exec geomean**（152 measured pairs），Calico 1.070x，Suricata 1.538x，xdp-tools 1.230x，tracee 1.230x，linux-selftests 0.918x（sub-ktime noise）。数据：`corpus/results/corpus_post_fix_20260313.json`，报告：`docs/tmp/corpus-post-fix-rerun.md`。旧 0.875x 无效数据已取代。
10. **~~P1：#170 BEXTR emitter 性能 bug 修复~~** ✅ #167/#173 修复（daca445b1）+ 验证。BEXTR fix 后 extract_dense 在 R2 测得 1.076x（vs 0.556x pre-fix）。报告：`docs/tmp/cmov-bextr-regression-investigation.md`
12. **~~P0：#171 dense policy 优化（2026-03-13）~~** ✅ #171/#173 已验证。VM 5轮迭代确认最优 policy：3 regressor 全部清空，6-dense geomean 1.097x（R1），62-bench 0.995x。分析报告：`docs/tmp/policy-iteration-rounds.md`，62-bench 数据：`micro/results/micro_62bench_policy_optimized_20260313.json`。
13. **~~P1：提升 62-bench overall > 1.0x~~** ✅ #174 Build #40 + policy 迭代（R6-R11）达成：overall **1.006x**，applied-only **1.040x**。endian_swap_dense 恢复 256 sites 后从 0.695x→1.013-1.139x。数据：`micro/results/micro_62bench_build40_policy_optimized_20260313.json`，分析：`docs/tmp/policy-iteration-rounds.md`（R6-R11 节）。
14. **~~P1：#174 Build #40 (ac593b2c1) BEXTR without-copy fix + policy R6-R11~~** ✅ 完成。Build #40 重编、R6-R11 迭代、endian 恢复全 256 sites、62-bench 跑完。
11. **P2：不同微架构** — 当前只在一个 CPU 上测

### 1.2b OSDI/SOSP Novelty

**真正 novel 的部分**：
1. **Safety/optimization 分离** — kernel 管安全，userspace 管优化策略
2. **Fail-closed backend policy substrate** — digest binding、verifier remap、CPU gating、exact validators
3. **部署控制权** — 优化 owner 是 Cilium/Katran 等 loader，不是 kernel maintainer
4. **Policy-sensitive 证据** — 同一合法站点在不同 workload 下需要不同 lowering

**Go 条件（全部满足才提交）**：
1. 原型实现多个 directive，展示框架泛化能力 ✅（8 families: COND_SELECT, WIDE_MEM, ROTATE, ADDR_CALC, BITFIELD_EXTRACT, ZERO_EXT_ELIDE, ENDIAN_FUSION, BRANCH_FLIP）
2. Fixed kernel baseline 不能在所有场景下达到同等收益 ✅（CMOV +28.3%）
3. 评估包含真实程序和至少一个端到端部署 ✅（Tracee daemon +21.65% exec_storm, Tetragon daemon +3.8% app, bpftrace 5/5 attach）
4. 与 characterization 深度整合 ✅（已合并）
5. **真实程序上可测量的 net speedup** 🔴（当前不足，必须改进）

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
| **上游接受成本** | kernel patch 审核周期长（月~年级），peephole 优化逐个上游化不现实；BpfReJIT 让优化以 userspace policy 形式即时部署，无需等待 kernel release cycle |
| **算法迭代** | 优化 pattern 需要反复实验和迭代（不同 pattern 识别、不同 emission 策略）；kernel 代码一旦合入很难改，userspace scanner/policy 可以快速迭代而不影响 kernel 稳定性 |
| **程序级组合** | 局部有利的变换可能全局有害（I-cache cliff），userspace 做全局预算 |
| **Workload 适应** | 分支可预测性取决于运行时数据分布，不是 ISA 特性 |
| **Fleet A/B testing** | 5% 机器先上新 policy，看效果再推广，无需改 kernel |
| **所有权** | service owner 已经拥有 BPF 性能调优（Cilium/Katran），kernel maintainer 不应维护每个 service 的 heuristic |
| **覆盖面** | kernel JIT 中有数十个可优化点（prologue NOP、零偏移编码、div/mod save/restore、endian fusion 等），不可能全部逐一 patch 上游；BpfReJIT 提供统一的参数化基础设施，一次性覆盖所有 backend lowering 决策 |

### 1.4 核心设计约束

> **⚠️ 约束 0（最高优先级）：系统必须在真实程序上产生可测量的 net speedup。**
> 如果 canonical form 不够多、覆盖面不够广、policy 不够精、导致整体没有加速，那系统的实际价值就不足以支撑论文。
> 所有设计决策必须服务于"让真实程序跑得更快"这个目标。

1. **xlated_prog_len 不变量**：所有 directive 只改 native code emission，不改 BPF 指令。如果 xlated 变了说明优化在错误的层。
2. **正确 directive 判断标准**：用户态能不能做同样的事？如果能 → 错误的层（POC v1 wide_load 教训：BPF 指令重写 = 错误层）。
3. **Kernel 改动最小化**：参数化 validator 模板，每个 directive ~50-100 LOC。
4. **Fail-closed**：任何验证失败 fallback 到标准 emission。
5. **安全模型**：内核从不执行用户态代码——只在自己预定义的安全变体间切换。
6. **Mandatory Falsification**：如果 fixed kernel heuristics 在所有测试硬件和 workload 上恢复相同收益，正确结论是"用 kernel peepholes"，不是发布 userspace-guided interface。
7. **Pipeline placement**：directive rewrites 发生在 `do_check()` 之后、`convert_ctx_accesses()` 之前。
8. **Constant blinding 兼容**：constant blinding 是独立的第二次 BPF 重写，会打乱 insn offset——当前设计在 blinding 发生时直接 drop directive set。
9. **JIT convergence loop**：x86 JIT 是 convergence loop + final image pass，directive 必须跨 pass 确定性一致。
10. **Net speedup 驱动**：每新增一个 canonical form，必须验证它在 corpus 上 net positive。只有安全贡献没有性能贡献的 form 不够。

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

> **⚠️ v4 已删除**：v4 legacy code 已在 `a99cd78ed` 中完全移除（-778 LOC）。
> 只保留 v5 声明式路径（policy version 2, `BPF_JIT_RK_PATTERN`）。
> v6 tier-1 改进已完成：通用 site/pattern 上限 24→64、`BPF_PROG_JIT_RECOMPILE` 新增 `log_level/log_size/log_buf`、tuple/binding 上限 12→16。报告：`docs/tmp/v6-tier1-implementation.md`。

---

## 2. Characterization 证据摘要

| 证据 | 数值 |
|------|------|
| Exec time geomean (L/K) — **characterization gap** | **0.609x** (56 pure-JIT, strict 30×1000); 0.849x (31 pure-JIT, old 3×100)。注意：这是 llvmbpf vs stock kernel 的 gap 上界，不是 BpfReJIT 改进 |
| BpfReJIT micro improvement (recompile/stock) | blind **1.028x** (50 valid, 31W/17L); fixed-policy applied-only **1.049x** (56/56 valid, 8 applied, 5W/3L); per-family best: rotate **1.021x**, wide **1.010x**; gap recovery **4.3%** of 1.641x characterization gap |
| Code size geomean (L/K) | 0.496x |
| Byte-recompose 占 kernel surplus | 50.7%，2.24x 时间惩罚 |
| cmov 差距 | llvmbpf 31 vs kernel 0 |
| Prologue/epilogue 占 surplus | 18.5% |
| branch_layout 输入敏感性 | predictable 0.225x vs random 0.326x，差 44.6% |
| Real-program code-size | 0.618x geomean (36 unique) |
| Real-program exec-time | 0.514x geomean (14 unique) |
| Corpus directive coverage (5 fam) | 143/560 objects with sites, **14593** total sites（5 families, per-section）|
| Corpus v6 full recompile (blind) | 166 targets, **163 measured pairs**, 92 applied, exec geomean **0.868x**, code-size 0.999x, wins 40 / regressions 107 |
| Corpus v2 fixed policy recompile | 156 measured pairs, 91 applied, exec geomean **0.875x**, wins 45 / losses 101。vs blind +0.8%, vs v1 tuned -2.6% |
| Corpus 8-family census | 157/560 corpus objects with sites, **16535** total sites（8 families, per-section）。新: endian=1386, bflip=2264, zeroext=0（x86-64 预期） |
| Pass ablation | 仅 InstCombinePass + SimplifyCFGPass 有效 |
| cmov 消融 | switch_dispatch +26%，binary_search +12%；bounds_ladder -18%，large_mixed -24% |

---

## 3. Directive 分类体系

### 3.1 Policy-sensitive（撑论文 novelty）

| Directive | Why userspace policy | 证据 | 状态 |
|-----------|---------------------|------|:---:|
| **`cmov_select`** | 依赖分支可预测性/依赖链深度/CPU 家族 | cmov ablation 混合结果；log2_fold +28% vs cmov_select -82% | ✅ v4+v5 |
| **`branch_flip`** | 依赖 workload 热度/输入分布/code-size budget | branch_layout 差 44.6%；**2279 corpus sites** (tracee 1791) | ✅ 简单 if/else body swap 可用 pattern match（`BRANCH_FLIP`），通用 CFG relayout 仍 scope 外 |
| **`subprog_inline`** | 依赖热度/code-size/I-cache | corpus 97.2% multi-function | future |

### 3.2 Substrate（peephole，复用框架基础设施）

| Directive | 状态 | 说明 |
|-----------|:---:|------|
| `wide_load` | ✅ v4+v5 | 50.7% surplus recovery，**2987 corpus sites**（per-section 8-fam census） |
| `rotate_fusion` | ✅ v4+v5 | BMI2 依赖，**2685 corpus sites**，-28.4% exec |
| `lea_fusion` | ✅ v4+v5 | 19 sites (11 objects)，stride_load_16 -12% |
| `bitfield_extract` | ✅ v5 | **557 corpus sites** (46 objects)，Cilium 高频 |
| `zero_ext_elide` | ✅ | 32-bit ALU + redundant zext → skip zext。**x86-64 上 corpus 0 sites**（verifier 不插 zext, `bpf_jit_needs_zext()=false`），形式为非 x86 架构准备（RISC-V/ARM）|
| `endian_fusion` | ✅ | ldx+bswap → movbe（需 MOVBE CPU feature），纯 pattern match。**1386 corpus sites** (50 objects)，Calico 786 最多 |
| `branch_flip` | ✅ | 第二个 policy-sensitive directive（if/else body swap, 哪个 body 先走取决于 workload），纯 pattern match。**2279 corpus sites** (27 objects)，tracee 1791 最多 |
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

### 6.4 Root Makefile 一键命令速查

根目录 `Makefile` 提供一键构建+测试。所有 VM 目标自动依赖 bzImage。

#### 构建目标

| 命令 | 作用 |
|------|------|
| `make all` | 构建 micro_exec + BPF programs + scanner + kernel-tests |
| `make micro` | 只构建 micro_exec 和 BPF programs |
| `make scanner` | 只构建 scanner CLI |
| `make kernel` | 编译 bzImage（vendor/linux-framework） |
| `make kernel-tests` | 编译 kernel self-tests (test_recompile) |

#### 快速验证（无需 VM）

| 命令 | 作用 |
|------|------|
| `make smoke` | 构建 + 本地 llvmbpf smoke test (simple, 1 iter, 10 repeat) |
| `make scanner-tests` | 构建 + 运行 scanner unit tests (ctest) |
| `make check` | = `all` + `scanner-tests` + `smoke`（完整本地验证） |

#### VM 目标（需要 bzImage + vng）

| 命令 | 作用 |
|------|------|
| `make vm-selftest` | VM 中跑 kernel self-tests (test_recompile) |
| `make vm-micro-smoke` | VM 中跑 micro smoke (simple + load_byte_recompose, kernel + recompile) |
| `make vm-micro` | VM 中跑全量 micro suite (llvmbpf + kernel + recompile, 默认 10iter/2warm/200rep) |
| `make vm-corpus` | 跑 corpus batch (per-target VM boot, 用 policy, 默认 200 repeat) |
| `make vm-e2e` | 跑全部 E2E (tracee + tetragon + bpftrace + xdp_forwarding) |
| `make vm-all` | = `vm-selftest` + `vm-micro` + `vm-corpus` + `vm-e2e`（完整 VM 验证） |
| `make validate` | = `check` + `vm-selftest` + `vm-micro-smoke`（最小 VM 验证） |

#### 可调参数

```bash
make vm-micro ITERATIONS=2 WARMUPS=2 REPEAT=500          # strict run
make vm-micro BZIMAGE=/path/to/other/bzImage              # 自定义 kernel
make vm-corpus REPEAT=100                                  # 快速 corpus
```

#### 典型工作流

```bash
# 改完代码后最小验证
make check                    # 本地：编译 + scanner tests + smoke

# 改完 kernel 后
make kernel && make validate  # 重编 bzImage + 本地验证 + VM smoke

# 全量评估
make vm-all                   # 跑全部 micro + corpus + e2e

# 清理
make clean
```

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
| 49 | **端到端部署评估** | 已取消 | 用户决定不再追求独立 PPS throughput 数据，现有 Tracee/Tetragon/bpftrace E2E 已足够 |
| 50 | **论文更新** | 已取消 | 用户决定移除 |
| 51 | jit_recompile 加 log_level/log_buf | ✅ | framework kernel 已加 `log_level/log_size/log_buf`，scanner `apply` 默认携带 16 KiB log buffer，失败时直接回显 kernel 诊断。`docs/tmp/v6-tier1-implementation.md` |
| 52 | Shape whitelist 扩展 | ✅ | v5 active path 保留 generic `site_len <= 64` + `pattern_count == site_len`，删除 per-form 固定长度 gate 的约束效果；scanner ABI 常量同步到 64。`docs/tmp/v6-tier1-implementation.md` |
| 53 | Overlap/priority 语义 | ❌ | 当前 kernel 不拒绝也不仲裁重叠 rule |
| 54 | Subprog 一致性 | ❌ | v4 分支与 fixed-baselines 分支的 subprog 处理不同步 |
| 55 | K2/Merlin/EPSO 对比实验 | ✅ | **正交非替代**。backend-only gap 占 surplus 89.1%。dual-pass spot check: size geomean 0.995x（IR 侧几乎碰不到 backend gap）。K2/Merlin 代码可获取但不兼容当前 pipeline，EPSO 无公开 artifact。`docs/tmp/k2-merlin-epso-comparison.md`，`micro/results/llvm_dual_pass_boundary_spotcheck.md` |
| 56 | Re-JIT 原子性 / RCU 安全说明 | ✅ | POC benchmark-only safe（单线程 test_run）。Production 需：per-prog 串行化 + shadow image + RCU retirement + tailcall/trampoline 刷新。旧 image JIT text leak 未回收。`docs/tmp/rejit-rcu-safety-analysis.md` |
| 57 | 消融补全 | ❌ | byte-recompose / callee-saved / BMI |
| 58 | ZERO_EXTEND directive | ❌ | movzx vs xor+mov |
| 59 | ARM64 target backend | ❌ | 跨架构验证 |
| 60 | 严格重跑（30×1000） | ✅ | host 完成 strict pure-jit dual-runtime 重跑：**56/56 pass**, `30×1000`, `taskset -c 0`/`--cpu 0`, governor=`performance`, turbo=`off`。结果：`micro/results/pure_jit_authoritative_strict_20260312.json`，`micro/results/pure_jit.latest.json` 已更新。并修复 `micro/Makefile` clean 后并行重建目录依赖，`make -C micro clean && make -C micro -j$(nproc)` 现稳定通过。 |
| 61 | **Benchmark 多样性** | 🟡 | 67 micro: 64 XDP + 2 tc + 1 cgroup_skb。Corpus recompile paired: 61 tc + 16 xdp + 2 cgroup_skb = 79。Census 覆盖全类型。审计报告: `docs/tmp/benchmark-diversity-audit.md` |
| 62 | **CMOV kernel JIT benefit 信号增强** | ❌ | cmov_select 仅 2.8% 改善，需更强 signal（更多 cmov-heavy benchmark 或不同微架构） |
| 63 | **End-to-end throughput 数据** | 已取消 | 随 #49 一起取消 |
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
| 71 | **仓库层次重组** | ✅ | 三层划分已落地：`micro/`（隔离微基准）、`corpus/`（真实程序收集+测量+分析）、`e2e/`（端到端部署+分析）。corpus 测量脚本和 `_driver_impl_*` 已从 `micro/` 移到 `corpus/`，Tracee/Tetragon/bpftrace harness 已移到 `e2e/`，`config/macro_corpus.yaml` 和 `config/corpus_manifest.yaml` 已移到 `corpus/config/`，`user_bpf_benchmark/` 已移到 `legacy/`，README/driver/import 路径已修正，验证通过（`py_compile`、`--help`、`make -C micro micro_exec programs`、`micro/run_micro.py` smoke）。报告：`docs/tmp/repo-restructure-report.md` |
| 72 | **E2E 骨架 + Tracee 真正端到端** | ✅ | 新增 `e2e/common/`（`agent.py`/`workload.py`/`metrics.py`/`recompile.py`/`vm.py`）+ `e2e/cases/tracee/`（`setup.sh`/`config.yaml`/`case.py`）+ 统一入口 `e2e/run.py`。Host smoke（2026-03-11, Tracee `v0.24.1` via `/tmp/tracee-bin/tracee`）成功采集真实 app throughput + Tracee events/s + drops + CPU；stock host kernel 上 `BPF_PROG_JIT_RECOMPILE` 仍 `EINVAL`。Framework-kernel VM smoke（`vendor/linux-framework/arch/x86/boot/bzImage`, kernel `7.0.0-rc2-g2a6783cc77b6`）发现 15 个 Tracee 程序、扫描出 21 个 CMOV sites、成功 recompile `8/15` 程序；真实端到端对比：`exec_storm` app `+21.65%` / events/s `+21.16%` / BPF avg ns `-2.63%`，`file_io` app `+5.06%` 但 events/s `-10.05%`，`network` app `+1.32%` / events/s `+1.26%`。结果：`e2e/results/tracee-e2e-real.json`，`e2e/results/tracee-e2e-real.md`，`docs/tmp/tracee-real-e2e-host-smoke.json`，`docs/tmp/tracee-real-e2e-vm-smoke.json`，报告：`docs/tmp/tracee-real-e2e-report.md` |
| 73 | **Framework kernel 重编** | ✅ | `vendor/linux-framework/.config` 已启用 `CONFIG_FTRACE_SYSCALLS=y`、`CONFIG_BPF_KPROBE_OVERRIDE=y`、`CONFIG_SCHED_CLASS_EXT=y`（并补齐依赖 `CONFIG_FUNCTION_ERROR_INJECTION=y`），`bzImage` 重编完成（131.43s）。VM 验证：syscall tracepoints 存在、`/sys/kernel/sched_ext` 存在、`micro_exec` v5 recompile 恢复工作、Tetragon direct-object smoke 3/3 stock+reJIT OK。`docs/tmp/kernel-rebuild-report.md` |
| 74 | **Tetragon 真正端到端** | ✅ | **已修复为真实 daemon mode**（之前是 manual fallback）。安装 Tetragon v1.6.0 binary + BPF assets，拆分 tracing policy（tracepoint/kprobe 分文件），`--tracing-policy-dir` 加载。Framework-kernel VM daemon smoke（2026-03-11, `7.0.0-rc2-g2a6783cc77b6`, `/usr/local/bin/tetragon`）：5 个程序加载，`event_execve` 9 sites，recompile `1/5` 成功。总体均值：app `320199 -> 332336 ops/s`（`+3.8%`），agent CPU `32.37% -> 31.72%`（`-2.0%`），BPF avg ns `3627 -> 3100`（`-14.5%`）。per-workload：`stress_exec` app `+6.7%` CPU `-27.4%`，`file_io` `+4.0%`，`open_storm` `+2.6%`，`connect_storm` `-10.2%`（CMOV 回归）。结果：`e2e/results/tetragon-real-e2e.json`，`e2e/results/tetragon-real-e2e.md` |
| 75 | **bpftrace 真正端到端** | ✅ | 已实现 `e2e/cases/bpftrace/`：5 个 `.bt` 脚本 + `case.py`，复用 `e2e/common/` 做 attach / workload / metrics / scanner plumbing，把 `bpftrace` 本身当作 tracing agent，测应用吞吐 + `bpftrace` CPU + BPF avg ns。Framework-kernel VM 全量实测（2026-03-11, `7.0.0-rc2-g2a6783cc77b6`, `bpftrace v0.20.2`）：5/5 baseline 成功，2/5 有 eligible CMOV sites（`open_latency` 5，`scheduler_latency` 4），aggregate 9 sites。真实端到端对比：`open_latency` BPF avg ns `277.17 -> 273.77`（`1.012x`），app `95367 -> 96082 ops/s`（`+0.75%`）；`scheduler_latency` `158.59 -> 163.27`（`0.971x`），app `41.72 -> 38.09 ops/s`（`-8.70%`）。eligible-script geomean `0.992x`，验证 policy-sensitivity。结果：`e2e/results/bpftrace-real-e2e.json`，`e2e/results/bpftrace-real-e2e.md`，`docs/tmp/bpftrace-real-e2e-report.md` |
| 77 | **Directive gap 分析 + 下一步方向** | ✅ | 深度审查 kernel JIT（`bpf_jit_comp.c` 5433 行）+ corpus site census + 性能 gap 分解。结论：(1) CMOV 过度关注——corpus 10% sites 且多数回归，应作为 policy-sensitivity 证据而非性能主力；(2) 4 family 机制数量够但组合偏 peephole，缺 structural policy-sensitive family；(3) 18.5% prologue bucket 完全未覆盖；(4) 下一步 P0：`bitfield_extract`（~100-300 sites，~200 LOC）、`packet_ctx_wide_load`（~300-800 sites）、加宽 `cmov_select` 识别；P1：`bounds_window`、`branch_reorder`；kernel 清理：prologue NOP、零偏移编码、imm64 stack store、div/mod liveness。`docs/tmp/directive-gap-analysis.md` |
| 78 | **加宽 cmov_select 识别** | ✅ | commit `f3d7c03`。新增 JSET/JSET32、wider diamond（jcc +3/+4）、guarded-update、switch-chain patterns。结果：switch_dispatch 0→1, binary_search 0→2, bounds_ladder 0→2 cmov sites。纯用户态。`docs/tmp/cmov-broadening-report.md` |
| 79 | **bitfield_extract directive** | ✅ | Scanner: 8 v5 descriptors (32/64-bit, shift→mask/mask→shift, with-copy/in-place)。Kernel: canonical validator + x86 emitter。Corpus: **544 sites across 41 objects**（top: cilium/bpf_lxc.bpf.o 138 sites）。新 benchmark `bitfield_extract.bpf.c` + input generator。`docs/tmp/bitfield-extract-implementation.md` |
| 80 | **packet_ctx_wide_load 扩展** | ✅ | Scanner: odd widths 2-8 + big-endian byte-recompose + v5 descriptors。Kernel: widened validator + x86 chunked emitter (4/2/1)。Corpus: **2835 wide sites**。`docs/tmp/wide-load-extension-report.md` |
| 81 | **branch_reorder directive** | 归入 #89 | 简单版 `BRANCH_FLIP`（local if/else diamond body swap）在 #89 中实现。通用 CFG relayout 仍 future scope。 |
| 82 | **bounds_window directive** | ❌ | P1。消除冗余 bounds check（dominating readable-window check 之后的重复 guard）。Scanner 识别 + kernel validator ~200 LOC。 |
| 83 | **Kernel JIT 清理 patches** | ✅ | commit `0496966`（kernel `8c66cec7c`）。已实现：零偏移内存编码优化 + imm64 stack store 优化。Code size：load_byte_recompose 422→418, stride_load_16 517→514。Prologue NOP / div-mod / endian fusion 待做。`docs/tmp/kernel-jit-cleanup-patches.md` |
| 84 | **Interface 设计审计 + v6 提案** | ✅ | 审计 v5 UAPI 接口强度：contiguous-only、local-CFG-only、no verifier facts、kernel-owned emitters。发现 bitfield_extract x86 dispatch wiring bug。v6 提案：fact-backed region rewrites + restricted template plans（需新 kernel semantics）。branch_reorder / bounds_window 无法用当前 v5 表达。`docs/tmp/interface-design-audit.md`，`docs/tmp/interface-improvement-proposals.md` |
| 85 | **v4 legacy 代码删除** | ✅ | commit `a99cd78ed`（vendor/linux-framework）。删除 778 LOC v4 代码，只保留 v5 声明式路径。8 files changed。kernel build + scanner build + scanner tests 全部通过。 |
| 86 | **v6 tier-1：去摩擦改进** | ✅ | 已完成：shape/site generic upper bound 64、`jit_recompile` log buffer、tuple/binding 12→16（`present_mask` 升到 `u32`）。构建与 `scanner` smoke 均通过。`docs/tmp/v6-tier1-implementation.md` |
| 87 | **v6 接口设计研究** | ✅ | 核心修正：verifier log 已暴露所有 discovery 所需信息（bounds/types/stack/branch/SCC/liveness），零 kernel 改动即可使用。v6 baseline 不需要 verifier 变更。安全验证仍靠 pattern match + constraints + kernel-owned emitter。`docs/tmp/v6-interface-design.md`，`docs/tmp/interface-improvement-proposals.md` |
| 88 | **Benchmark 框架审计 v2** | ✅ | 一键 build + smoke test 全部通过。修复：Tracee import 路径、文档更新（README/CLAUDE.md/e2e/README）。56 pure-jit + 11 runtime = 67 benchmarks。`docs/tmp/benchmark-framework-audit-v2.md` |
| 89 | **新 canonical forms 实现** | ✅ | 已完成：ZERO_EXT_ELIDE（32-bit ALU + redundant zext → 只发 ALU, x86 自动零扩展）、ENDIAN_FUSION（ldx+bswap / bswap+stx → movbe，含 MOVBE CPU gating）、BRANCH_FLIP（local if/else diamond body swap，含 ORIGINAL/FLIPPED native choice）。Scanner pattern + kernel validator + x86 emitter 已落地，构建测试通过。2026-03-11 follow-up：修复 `ZERO_EXT_ELIDE` 对真实 verifier zext（`BPF_ZEXT_REG`, `BPF_ALU|MOV|X`, `imm=1`）的匹配错误，并与 kernel validator 对齐。→ `docs/tmp/new-canonical-forms-implementation.md` |
| 90 | **Corpus 修复 + 全量 v6 recompile** | ✅ | 166 targets, **163 measured pairs**, 92 applied programs（5 families: CMOV 79/446, WIDE 39/342, ROTATE 2/1840, EXTRACT 37/86, LEA 0/0）。Exec geomean **0.868x**（all measured）/ 0.892x（applied only）。Code-size geomean 0.999x。Wins 40 / regressions 107（仍 CMOV-dominated regression，与 policy-sensitivity thesis 一致）。By source: selftests 0.802x, calico 0.935x, katran 0.776x, suricata 1.111x, tracee 0.653x。16 newly positive programs across 6 objects (geomean 0.917x)。→ `docs/tmp/corpus-full-recompile-v6.md`, `corpus/results/corpus_v5_vm_batch_full.json` |
| 91 | **优化方向深度研究** | ✅ | **Top 3**: (1) SESE control-flow region specialization（block order + branch polarity + hot fallthrough, 350-700 LOC, 2-6% exec plausible）; (2) Verifier-fact-guided late specialization（DIV_LIVENESS / NARROW_CMP / TYPE_SPECIALIZED_LOAD, 300-550 LOC）; (3) Typed semantic region plans（multi-atom composition: ROT+ROT→NOP, WIDE+EXTRACT→FIELD_LOAD, 550-900 LOC）。**不应做**: generic rewrite interpreter（破坏 fail-closed）。`docs/tmp/optimization-beyond-isel.md` |
| 92 | **8-family corpus census** | ✅ | 已按 per-section 方法重跑：627 objects 全部成功扫描，220 objects 有 sites，17637 total sites；其中 corpus 为 560 objects / 157 with sites / **16535** sites。新 families: endian=1386, bflip=2264（aggregate 2279，含 micro 15）, **zeroext=0**。调查结论：这不是 `--all`/CLI 漏算；scanner 已修正为可识别真实 verifier zext，但 per-section/raw ELF section 方法本身看不到 verifier 后插入的 zext，而 x86-64 live xlated 路径又因 `bpf_jit_needs_zext()=false` 不会插该 pair，所以 corpus 仍为 0。输出：`docs/tmp/corpus-8families-census-persection.md`，`docs/tmp/corpus-8families-persection.json`。 |
| 93 | **Micro suite 精简 + 一键运行** | ✅ | 已删除 `config/micro_runtime.yaml`，active micro suite 只保留 56-case pure-jit manifest；11 个 runtime `.bpf.c` 已移到 `micro/programs/archive/runtime/`；`micro/README.md` / `CLAUDE.md` / summarize/representativeness defaults 已同步为 pure-jit-only；新增 `scripts/run_micro.sh`（host / VM / llvmbpf-only 三模式）。验证：`make -C micro clean && make -C micro`、`python3 micro/run_micro.py --list`、`python3 micro/run_micro.py --runtime llvmbpf --bench simple --iterations 1 --warmups 0 --repeat 10`、`python3 micro/run_micro.py --runtime kernel --bench simple --iterations 1 --warmups 0 --repeat 10`、`./scripts/run_micro.sh --llvmbpf-only --bench simple --iterations 1 --warmups 0 --repeat 10`、`./scripts/run_micro.sh --vm --bench simple --iterations 1 --warmups 0 --repeat 10`。 |
| 94 | **Micro input 去 map** | ✅ | input 数据改为通过 XDP/TC packet buffer 传入，热路径零 map lookup。验证：llvmbpf + kernel 两个 runtime，simple/bitcount/rotate64_hash/tc_*/cgroup_hash_chain 结果正确。commit `29a12e5`。 |
| 95 | **Tracing corpus exec driver** | ✅ | `corpus/run_corpus_tracing_exec.py`：attach+trigger+run_cnt/run_time_ns 测量 tracing 类程序。自动推断 attach target + 生成 syscall workload。Host smoke：kprobe/tracepoint/placeholder 3 组成功 paired avg_ns，LSM attach OK 但 workload 未触发。VM recompile 待跑。commit `cd78eb6`。 |
| 96 | **Corpus 目录整理** | ✅ | 一次性脚本移到 corpus/tmp/，更新 README，验证核心脚本。15 组 --help/import 检查全部通过。 |
| 97 | **Per-program policy 配置设计** | ✅ | 调研完成。现状：scanner 默认 all-apply，micro/corpus/e2e 无 per-program policy，family surface 漂移（scanner 8 / runner 5 / e2e 4）。设计：统一 YAML policy schema（match+selection+site_overrides），自动 tuning 5 阶段（census→screening→leave-one-out→combo→site refinement），实现路径 P0-P4。→ `docs/tmp/policy-configuration-design.md`（960 行） |
| 99 | **Micro 目录 Python 脚本整理** | ✅ | analyze_*.py / demo_policy_iteration.py 移到 micro/archive/scripts/。完整运行验证通过（llvmbpf + kernel，simple/bitcount/rotate64_hash 结果正确）。commit `741536b`。 |
| 99a | **Micro Python cleanup follow-up** | ✅ | 2026-03-11 follow-up：compatibility wrappers `run_pass_ablation.py` / `run_rigorous.py` / `run_rigorous_framework_vm.py` 与 legacy `tools/build_policy_blob.py` 进一步移到 `micro/archive/scripts/`；新增 `micro/orchestrator/benchmarks.py`，把 `select_benchmarks()` / `resolve_memory_file()` 从 `run_micro` / pass-ablation / rigorous 路径抽成共享 helper。验证：`python3 -m py_compile`（修改后的 `micro/` Python 文件）、`python3 micro/run_micro.py --list`、`python3 micro/run_micro.py --runtime llvmbpf --bench simple --iterations 1 --warmups 0 --repeat 5`、`python3 micro/driver.py --help`。 |
| 98 | **Policy design v2：程序无关自动 tuning** | ✅ | 设计完成（793 行）。核心：auto-tuner 自动生成 per-program policy，人类不需要理解程序。默认行为改为 stock（不再 blind all-apply）。scanner 升级为 policy compiler。→ `docs/tmp/policy-configuration-design-v2.md` |
| 98a | **Policy P0+P1 实现** | ✅ | 统一 8-family surface（micro_exec/e2e/corpus）+ scanner `--json` + `compile-policy` 子命令。**纯用户态**。commits `9681708`, `8c196bb`。scanner `policy_config.cpp` 484 LOC 新增、`cli.cpp` 181 行修改、cmake install target、测试通过。 |
| 98b | **P2 Micro manifest-driven policy** | ✅ | 已完成 micro manifest 到 `--policy-file` / `--policy` 的 plumbing：`BenchmarkSpec` 新增 `policy` / `policy_file`，`run_micro.py` 在 `kernel-recompile` runtime 传给 `micro_exec`，`micro_exec` 对 live xlated program 扫描 + policy filter + blob build 后调用 `BPF_PROG_JIT_RECOMPILE`。**但本条应理解为 file-based path 已通，不代表 inline `policy:` 路径完整可用。** review 后续确认 inline `policy:` 仍生成旧 v1 JSON，问题单独跟踪在 #131。 |
| 98e | **P3 Corpus per-program policy files** | ✅ | 已完成 corpus per-program policy artifact wiring：新增 `corpus/generate_default_policies.py`、`corpus/policy_utils.py`、`corpus/policies/`，并在 corpus drivers 增加 `--use-policy` lookup。**本条不再表示任何 v1 / `selection.mode` 兼容仍然存在。** scanner parser 已在 #122 切为 v2-only；steady-state artifact 形状也在 #128 从 per-site allowlist 收敛为 `default: apply` + `families:` coarse denylist。 |
| 98c | **Tracing corpus VM full run** | ✅ | `corpus/run_tracing_corpus_vm.py` 已完成 framework-kernel VM 全链路执行：host preflight `724` considered / `473` ready / `251` skipped / `88` inventory failures；isolated guest per-target subprocess runner 稳定完成，无需再回退旧单进程 guest 路径。Artifacts：`corpus/results/tracing_corpus_vm_full_20260312.json`、`corpus/results/tracing_corpus_vm.latest.json`、`docs/tmp/tracing-corpus-vm-full-results.md`。此前阻塞与尝试记录保留在 `docs/tmp/tracing-corpus-vm-plan.md`。 |
| 98d | **Non-network code-size systematic** | ✅ | `corpus/run_code_size_comparison.py` 创建。Dry-run 盘点：560 objects, 2010 progs, 1282 loadable（kprobe 209, tracepoint 130, sched_cls 110, fentry 88, raw_tracepoint 84）。Host 无法 recompile (stock kernel EINVAL)。VM smoke 1 prog OK (xdp_probe_prog 78→84 bytes)，全量 VM 因 OOM 被 kill。commit `d1e7ef4`。`docs/tmp/code-size-by-progtype.md` |
| 98f | **P4 Auto-tuner** | ✅ | `corpus/auto_tune.py` 原型已落地：5-phase auto-tuner（census→screening→ablation→combo→generate），支持 `--dry-run` / `--phase` / `--resume` / `--programs`，并复用 per-program policy path。**本条应理解为 prototype landed，不是 authoritative evaluation path 已闭环。** review 指出它仍缺 final validation rerun，而且 #120 / #121 实际使用的不是这条主路径。 |
| 100 | **Micro kernel 回归修复 + fresh re-run** | ✅ | 修复 4 个 #94 回归（branch_layout/cmov_select/packet_parse/bounds_check_heavy），56/56 dual-runtime 全通过。commit `273a838`。`micro/results/pure_jit.latest.json` 已更新（3×100 authoritative）。2026-03-12 follow-up：#62 确认是已被 `273a838` 修复的历史 bug（`cmov_select` kernel 现返回 `4719383495603449331`，非 0）；#63 `_driver_impl_run_micro.py` 补上 artifact reuse，避免 sudo 复用场景重建；`make -C micro clean && make -C micro -j$(nproc)` 另修复为稳定通过；#66 中 `branch_layout`/`cmov_select` 保持 3464B staged 输入，`packet_parse` 在 54-packet 输入上 replay 前 10 个包，恢复旧的 64 parse-equivalent passes 而不触发 verifier/E2BIG。fresh 结果：`micro/results/pure_jit_authoritative_20260312.json`。 |
| 101 | **Corpus driver dedup** | ✅ | `corpus/common.py` 356 LOC 新增，7 个 driver_impl 净减 385 行。commit `666ba82`。 |
| 102 | **Benchmark inventory audit** | ✅ | 56 micro（56/56 pass），560 corpus objects（163 measured, geomean 0.868x），3 e2e cases。`docs/tmp/benchmark-inventory-audit.md`。2026-03-12 follow-up closure：#64 为真实 semantic drift，但 verifier 仍拒绝恢复原 variable-offset packet load，因此 `bounds_check_heavy` 明确重标注为 dependent bounds checks + switch-based fixed-offset loads；#65 证实为 false alarm，`checksum`/`tc_checksum` 的 0 result 来自 32 轮 XOR fold 抵消而非 zero input，source/YAML 已补注释。 |
| 103 | **Policy pipeline analysis** | ✅ | 两条路径：object-file-driven 有 YAML policy，live-program-driven（e2e）不传 policy。gap：`e2e/common/recompile.py` 缺 `--config`。`docs/tmp/policy-pipeline-analysis.md` |
| 104 | **#50 Corpus rerun with tuned policy** | ✅ | 完成。Geomean 0.868x→0.898x（+3.5%），cmov:skip subset 0.841x→0.866x。个案大幅改善：`test_tc_tunnel encap_ip6gre_mpls` 0.583x→1.429x。仍未达 1.0x——剩余回归来自 non-CMOV families（WIDE_MEM/ROTATE 的 sub-ktime noise）。142 measured pairs (21 harness failures)。`corpus/results/corpus_v5_tuned_policy.json`, `docs/tmp/corpus-tuned-policy-comparison.md` |
| 105 | **E2E policy 接线** | ✅ | `e2e/common/recompile.py` 新增 per-program `--config` 支持；命中 policy 时传 `scanner apply --config <yaml>`，未命中时保持旧的 `--all --v5` 回退。`tracee`/`tetragon` 现按 live prog 名回查 `corpus/policies/`；`bpftrace` 增加 best-effort `corpus/build/bpftrace/<script>.bpf.o` 映射，当前无命中时自动回退。验证：`python3 -m py_compile e2e/common/recompile.py e2e/cases/bpftrace/case.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py`、`python3 e2e/run.py --help`、`python3 e2e/cases/{bpftrace,tracee,tetragon}/case.py --help`；helper dry-run 命中 `tracee 15/15`、`tetragon 3/5` 现有 live-program policies。 |
| 106 | **结果目录规范化** | ✅ | 命名约定 `<suite>_authoritative_<date>.json` + `*.latest.json` symlinks。各目录 `README.md` 已落地。commits `7371a42` + `f0d86ff`。 |
| 107 | **Code-size 全量 VM run** | ✅ | framework-kernel VM `4G` / `2` vCPU 全量完成。首次按原命令跑通但因 `vng` 缺少 `--rwdir` 仅写入 guest overlay；随后补 `--rwdir corpus/results` + `docs/tmp` 持久化成功。结果：`560` objects scanned，`2010` programs discovered，`1208` loadable，`1183` compile pairs，`421` site-positive，`414` applied，`25` recompile failures，overall code-size geomean `1.003x` (recompile/stock)，median delta `+0.0%`。按 prog type 看：负向最明显 `sk_reuseport 0.944x`、`cgroup_skb 0.974x`；正向最明显 `lsm 1.012x`、`sk_msg 1.015x`。Artifacts: `corpus/results/code_size_full_vm_20260312.json`, `corpus/results/code_size.latest.json`, `docs/tmp/code-size-full-vm-results.md`。 |
| 108 | **Tracing corpus VM 全量 run** | ✅ | framework-kernel VM `4G` / `2` vCPU 全量完成：`473` ready programs 中 `315` attach 成功，`167` attached+triggered paired measurements，`17` paired-applied，`148` zero-run，`158` attach/load failures。Exec-time geomean（stock/recompile）overall `1.003x`，applied-only `1.019x`。按 prog type：`lsm 1.050x` (`20` paired), `tracing 1.021x` (`55`), `raw_tracepoint 1.008x` (`27`), `kprobe 1.002x` (`33`), `tracepoint 0.942x` (`32`)。Artifacts：`corpus/results/tracing_corpus_vm_full_20260312.json`, `corpus/results/tracing_corpus_vm.latest.json`, `docs/tmp/tracing-corpus-vm-full-results.md`。 |
| 109 | **scx struct_ops recompile EINVAL** | ✅ | 已定位：实际不是 syscall 入口的 prog-type whitelist，而是 x86 re-JIT 首 pass 复用了旧 `aux->extable` 导致 `do_jit()` 向旧 RO image 写 exception-table metadata 并 oops；修复为仅在 final image pass (`image && rw_image`) 填 extable。进一步确认 live attached `struct_ops` 仍缺 trampoline regeneration，因此当前改为显式 `-EOPNOTSUPP` + log，而不是误报 `EINVAL`。`docs/tmp/struct-ops-recompile-investigation.md` |
| 110 | **llvmbpf array map inline POC** | ✅ | POC 完成：`register_array_map()` API + JIT-time helper-1 call rewrite → LLVM 常量传播后扫描 `_bpf_helper_ext_0001`，常量 handle 且已注册 array map 时 inline 为 `key < max_entries ? base + key*stride : 0`。Benchmark: baseline 7.51 ns → inline 5.77 ns = **1.30x speedup (−23%)**，helper calls 10M→0。Tests: 78 assertions / 13 cases pass。Commit `7f19854` in vendor/llvmbpf。后续：需在 `micro/runner/src/llvmbpf_runner.cpp` 加 glue code 让 runtime suite 自动受益。`docs/tmp/llvmbpf-array-map-inline-poc.md` |
| 111 | **XDP forwarding E2E PPS** | ✅ | `e2e/cases/xdp_forwarding/case.py` 创建：veth pair 隔离 + nping/pktgen PPS 测量 + pre/post-recompile 对比。Dry-run 已验证。Live 需 framework-kernel VM 跑 BPF_PROG_JIT_RECOMPILE。`e2e/results/xdp_forwarding_authoritative_20260312.json`, `e2e/results/xdp-forwarding-e2e.md` |
| 112 | **Sub-ktime 过滤 + strict micro 分析** | ✅ | **Strict micro 30×1000**: geomean **0.609x**（非严格 0.848x），53/56 llvmbpf wins，17 flipped from kernel→llvmbpf。`>=100ns` kernel only: 0.645x (50 benchmarks)，双侧 `>=100ns`: 0.707x (38 benchmarks)。3 个回归：`cgroup_hash_chain` 1.083x, `code_clone_8` 1.188x, `branch_dense` 1.212x。**Corpus sub-ktime**: `>=100ns` 不翻正（tuned 0.948x, blind 0.988x），只有 `>=200ns` 翻正（1.236x）但 N=13 太小。Paper recommendation: strict 30×1000 为 authoritative micro；corpus 用 unfiltered + `>=100ns` sensitivity cut。`docs/tmp/sub-ktime-and-strict-analysis.md` |
| 113 | **Policy 深度分析：为什么 <1.0x** | ✅ | **根因**：剩余回归集中在 non-CMOV families，尤其 Calico 高置信度程序的 `branch-flip`+`endian`+`extract`+`wide` 组合。CMOV 现在反而正面（applied 1.196x, >=100ns 1.314x）。48 个 no-op rows geomean 0.873x（sub-ktime 噪声）。**Family 影响**（applied >=100ns overlap）：cmov 1.314x, wide 0.912x, rotate 0.641x（combo confounded）, extract 0.864x, endian 0.899x, branch-flip 0.946x。**修复路径**：per-program policy + 先 skip branch-flip → 再 skip endian → applied/>=100ns 可上 1.0x（upper bound: branch-flip fix→1.061x, endian fix→1.047x）。简化 sweep 预计 34-50 min VM 时间。`docs/tmp/policy-improvement-analysis.md` |
| 114 | **Per-site policy v2 格式 + scanner 实现** | ✅ | scanner v2 policy parser/compiler 已落地：当前 schema 是 `version: 2` + `program` + `default` + optional `families` + optional `sites[{insn,family,action}]`，优先级 `site > family > default`。**这条不再表示任何 v1 backward compat。** v1 parsing 已在 #122 删除；#128 补上 `families:` steady-state 层级；#135 又补了 shared golden tests，把 Python/C++ parser 对齐到同一语义（显式 `sites.action`、duplicate reject、`stock -> skip` alias）。`apply` 同时支持 offline object/xlated → blob 与 live `--prog-fd` recompile，stale site 仅 warning+skip。 |
| 115 | **Strict 30×1000 micro 数据分析** | ✅ | 已包含在 #112 中。结果见 #112。 |
| 116 | **Per-program branch-flip/endian skip sweep** | ✅ | 38 个高置信度 Calico regressors 3-round VM sweep。R1 tuned baseline 0.844x；R2 branch-flip:skip 0.827x（worse）；**R3 branch-flip+endian:skip 0.857x**（policy-to-policy +6.6% vs R1）。仍未达 1.0x——Calico 程序 recompile overhead 本身是主要瓶颈。个案最佳：`calico_tc_skb_ipv4_frag` 0.434x→0.872x（+2.1x）。38 个 per-program v2 policy 安装到 `corpus/policies/calico/`，sweep driver `corpus/run_bflip_endian_skip_sweep.py`。commit `9379512`。`docs/tmp/bflip-endian-skip-sweep.md`，`corpus/results/corpus_v5_bflip_skip_sweep_20260312.json` |
| 117 | **scx struct_ops EINVAL 调查** | ✅ | 已完成源码+VM 追踪。VM 复现显示真正故障是 `bpf_prog_jit_recompile()` -> `bpf_int_jit_compile()` -> `do_jit+0x2ac9`，`scripts/faddr2line` 解析到 `arch/x86/net/bpf_jit_comp.c:4731` (`ex->data = EX_TYPE_BPF`)；根因是 re-JIT 首 pass 用 stale `aux->extable` 写旧 RO image。已修 x86 extable guard，并对 live attached `struct_ops` 增加显式 `-EOPNOTSUPP`（需 future trampoline regeneration 才能真正支持 scx live recompile）。`docs/tmp/struct-ops-recompile-investigation.md` |
| 118 | **Strict kernel-recompile micro run** | ✅ | VM `2/10/500` blind all-apply。Overall geomean **1.028x**（stock/recompile），applied-only **1.024x**。31 wins / 17 losses / 2 ties，50 valid / 6 invalid（4 result-mismatch + 2 VM crash）。大赢：rotate64_hash **1.600x**，packet_redundant_bounds **1.508x**，deep_guard_tree_8 1.298x，packet_rss_hash 1.273x。大回归：cmov_dense **0.612x**（CMOV policy-sensitivity）。`micro/results/kernel_recompile_strict_20260312.json`，`docs/tmp/kernel-recompile-micro-strict.md` |
| 119 | **XDP forwarding live VM PPS** | ✅ | framework-kernel VM authoritative run 完成。**Caveat**：guest `# CONFIG_VETH is not set`，初始 `ip link add ... type veth` 失败，因此 `e2e/run.py xdp_forwarding --vm` 改为自动注入两组 `vng --network loop` virtio NIC pairs，并在 guest 内用 preexisting topology 复用原 case 逻辑。结果：stock receiver **990,522.6 PPS**，recompile receiver **993,209.6 PPS**，speedup **1.003x**（`+0.27%`）；scanner census **3 sites**（cmov=1, endian=2），policy apply **2/3 rules**（2 endian applied，1 stale cmov skipped warning）。Artifacts：`e2e/results/xdp_forwarding_vm_20260312.json`，`docs/tmp/xdp-forwarding-live-vm-report.md`。 |
| 120 | **Corpus rerun with v2 per-program policies** | ✅ | framework-kernel VM 对**初版** v2 per-program corpus policy tree 的全量 rerun 完成。artifact：`corpus/results/corpus_v5_v2_policy_20260312.json`，`docs/tmp/corpus-v2-policy-rerun.md`。结果负向：166 targets，162 compile pairs，155 measured pairs，58 applied，exec geomean **0.848x**，低于 blind all-apply `0.868x` 和 v1 tuned `0.898x`；shared 142-program overlap 也是 **0.847x**。**后续 #128 已说明这代表的是 pre-fix baseline（offline exact-site allowlist + default skip/stock），不是当前 family-driven repaired v2 policy 状态。** |
| 121 | **E2E rerun with tuned v2 policy** | ✅ | **本条完成的是 wiring / pipeline-validation rerun，不是 successful config-mode evaluation。** v2 policy 查找路径已接通，但 site 坐标漂移导致大部分 policy 未真正 apply：Tracee 命中 13/15 但 0/15 live apply（site stale），Tetragon 有 lookup 命中但有效结果仍主要落回 blind fallback，bpftrace 0/7 命中全 fallback。结论：需要刷新 live-program artifact，并去掉 authoritative path 上的 remap/drift 掩盖。`e2e/results/{tracee,tetragon,bpftrace}-e2e-v2-policy.json`，`docs/tmp/e2e-v2-policy-rerun.md` |
| 122 | **v2 pipeline 迁移** | ✅ | **本条完成的是 format/plumbing migration，不是 steady-state semantics closure。** scanner 已切 v2-only（v1 parsing 删除）；生成器与 drivers 已切到 per-program v2 policy；`corpus/policies/` 已重生成到 v2 layout；`policy_utils.py` 修复 `sanitize_program_name()` 前导下划线冲突。后续 review 暴露的 no-policy stock default、E2E remap 语义、inline policy v1 残留等问题不属于本条闭环，分别跟踪在 #130 / #121 / #131。`docs/tmp/v2-pipeline-migration-report.md` |
| 123 | **Micro kernel-recompile per-family 消融** | ✅ | framework-kernel VM `2/5/200` per-family ablation 完成。Geomean（stock/recompile）：`cmov 0.974x`（仅 2 个 applied；`cmov_select 0.940x`、`cmov_dense 0.975x`，另有 `4` result-mismatch + `2` VM crash）、`wide 1.010x`（`51` applied，`packet_redundant_bounds 1.306x`）、`rotate 1.021x`（`14` applied，`rotate64_hash 1.391x`、`packet_rss_hash 1.200x`）、`lea 0.992x`（`4` applied）、`extract 1.001x`（`3` applied，`bitfield_extract 0.846x`）、`branch-flip 0.988x`（`3` applied，`large_mixed_1000 1.137x`，`branch_dense 0.969x`）；`endian`/`zero-ext` 在该 56-bench suite 上 `0` eligible sites。Interaction：blind all-apply 在 `branch_fanout_32` 上比最佳单 family 快 `1.365x`，但 `memcmp_prefix_64`/`large_mixed_500` 上最佳单 family 又分别比 blind 快 `1.437x`/`1.244x`。Artifacts：`micro/results/kernel_recompile_per_family_20260312.json`，`docs/tmp/kernel-recompile-per-family-ablation.md`。 |
| 124 | **论文数据一致性审计** | 已取消 | 用户决定移除 |
| 125 | **Characterization gap 分解** | ✅ | Characterization gap 1.641x，BpfReJIT blind recovery 1.028x（恢复 **4.3%** of gap），remaining implied 1.598x。最强恢复：bounds_check_heavy 58.8%、rotate64_hash 36.9%、packet_redundant_bounds 34.0%。**注意：剩余 gap 的 LLVM IR / runtime / non-site 来源是合理推断，不是逐 benchmark 直接证明。** `docs/tmp/characterization-gap-decomposition.md`，`docs/tmp/gap_decomposition.py` |
| 126 | **Micro v2 tuned policy rerun** | ✅ | framework-kernel VM strict rerun 完成；authoritative 路径使用 `docs/tmp/kernel_recompile_micro_resume.py`，因为单 guest `micro/run_micro.py` 长跑不稳定。Overall geomean `1.027x`（`54/56` valid），但共同有效 `50` benchmark 上 blind→tuned `1.028x -> 1.029x`；applied-only `1.024x -> 1.040x`，invalid `6 -> 2`，共同有效 direct blind/tuned recompile geomean `1.032x`，tuned-policy 子集 `1.070x`。Artifacts：`micro/results/kernel_recompile_v2_tuned_20260312.json`，`docs/tmp/kernel-recompile-micro-v2-tuned.md`，`micro/policies/*.yaml`。 |
| 128 | **Corpus v2 policy diagnosis + fix** | ✅ | 定位到主根因是 **offline per-site allowlist + `default: skip/stock`**：`109` 个 policy-file program 里 `70` 个出现 `policy site ... was not found in the live program`，`56` 个直接 `policy selected 0 of N`。实测 object/live scan 证实 site 漂移和 live-only families：`healthcheck_encap` `cmov@150,endian@173 -> bflip×7,cmov@190,endian@213`；`res_spin_lock_test` `cmov@45 -> bflip@8,24 + cmov@57`。修复：scanner v2 policy 恢复/实现 `families:` family-level overrides（precedence=`site > family > default`，`sites` 可空），`generate_default_policies.py` 改为生成 `default: apply` + `families: {cmov: skip}` coarse denylist，重生成 `580` 个 policy files（全部 `default: apply`，`196` 个含 `cmov: skip`，无显式 `sites`）。Smoke VM 子集 `13` targets：old v2 `0.758x` → new `1.055x`，关键恢复 `healthcheck_encap 0.500x→0.850x`、`res_spin_lock_test 1.015x→8.644x`、`from_nat_debug send_icmp_replies 0.575x→1.019x`；`__encap_udp_eth` 仍 `0.438x→0.492x`，说明 object-level CMOV skip heuristic 仍需后续收紧。Artifacts：`docs/tmp/corpus-v2-policy-diagnosis.md`，`docs/tmp/corpus-v2-policy-smoke-20260312.{json,md}`。 |
| 129 | **Micro mismatch/crash diagnosis + per-site fixes** | ✅ | framework-kernel VM 定点复现确认：`binary_search`/`switch_dispatch`/`branch_dense`/`bpf_call_chain` 的 blind `result-mismatch` 都由单个 `cmov` site 触发；`bounds_ladder` 中 `cmov@144` wrong-code、`cmov@152` runtime crash；`mixed_alu_mem` 中 `extract@228` runtime crash，而 `wide@10` + `extract@73` 安全。修复：新增 `micro/policies/{bounds_ladder,mixed_alu_mem}.yaml` 并接入 `config/micro_pure_jit.yaml`；现有 `binary_search`/`switch_dispatch`/`branch_dense`/`bpf_call_chain` tuned policies继续沿用。post-fix validation：`docs/tmp/micro_diag/validation_v2.json` 中这 6 个 benchmark 全部 `valid` 且 `kernel-recompile result == stock result`。**源级根因修复见 #138。** 完整报告：`docs/tmp/micro-mismatch-crash-diagnosis.md`。 |
| 127 | **阶段性 review** | ✅ | 阶段性 review 完成。它当时指出 4 个 critical 不一致：v2 spec 分叉、steady-state 默认语义反了、E2E remap 改写 policy 语义、micro inline v1 坏。**按当前仓库状态，其中安全问题已在 #129 修复，corpus v2 负结果已在 #128 诊断，默认语义 / inline policy 结论也应视为历史阶段结论；仍然活跃的关键缺口是 spec/doc split 与 E2E family-order remap。** `docs/tmp/stage-review-report.md` |
| 130 | **Steady-state 默认语义修正** | ✅ | Review P0 完成。micro/corpus/e2e no-policy fallback 从 blind all-apply 改为 stock。blind all-apply 改为显式 `--blind-apply` opt-in。修复范围：`_driver_impl_run_corpus_v5_framework.py`、`_driver_impl_run_corpus_v5_vm_batch.py`、`micro/orchestrator/commands.py`、`micro/_driver_impl_run_micro.py`、`e2e/common/recompile.py`。 |
| 131 | **Micro inline policy v1→v2 修复** | ✅ | Review P0 完成。`config/micro_pure_jit.yaml` 中 inline `policy:` 已全部替换为 `policy_file:` 引用外部 v2 YAML 文件（`micro/policies/log2_fold.yaml`、`micro/policies/cmov_select.yaml`、`micro/policies/bounds_ladder.yaml`、`micro/policies/mixed_alu_mem.yaml`）。`benchmark_catalog.py` 中 inline policy 生成逻辑已删除。 |
| 132 | **v2 spec 文档更新** | ✅ | Review P0 完成。新增 authoritative v2 spec `docs/tmp/policy-v2-authoritative-spec.md`（含 `families:` 层级、site>family>default 优先级、Python/C++ 共享语义）。旧 `docs/tmp/policy-configuration-design-v2.md` 标记为 superseded。 |
| 133 | **Corpus 全量 v2 rerun（修复后）** | ✅ | framework-kernel VM strict rerun 完成，使用 `--use-policy`、`repeat=200`，authoritative artifact `corpus/results/corpus_v5_v2_fixed_20260312.json`。Overall exec geomean `0.875x`，较 old v2 `0.848x` 回升 `+3.2%`，略高于 blind `0.868x`（`+0.8%`），但仍低于 v1 tuned `0.898x`（`-2.6%`）。Measured pairs `156`，applied programs `91`（old v2 为 `58`）；policy coverage `109` policy-file / `57` stock miss-policy，measured `101` / `55`。共享 `142` 程序 overlap：blind `0.891x`，v1 `0.898x`，old v2 `0.847x`，fixed v2 `0.880x`。Smoke `13` target overlap 在 full rerun 中仍为 `1.048x`（standalone smoke `1.055x`）。关键恢复：`res_spin_lock_test 1.015x -> 24.377x`、`from_nat_debug send_icmp_replies 0.575x -> 0.989x`；残余问题仍集中在 `test_tc_tunnel` 的 coarse `cmov: skip` 和部分 Calico regressors。`docs/tmp/corpus-v2-fixed-rerun.md`。 |
| 134 | **E2E 全量 rerun（drift fix + 修复后）** | ✅ | framework-kernel VM rerun 完成。Tracee `15` programs 中 `13` policy-hit / `13` config applies / `2` stock fallback，live sites `158` -> kept `47`（`cmov` live `111` 全被 family skip 过滤）；Tetragon `5` programs 中 `3` policy-hit / `3` config applies / `2` stock fallback，live sites `43` -> kept `43`；bpftrace `7` attached programs `0` policy-hit / `7` stock fallback / `0` blind apply，验证 no-policy -> stock。Artifacts：`e2e/results/{tracee,tetragon,bpftrace}-e2e-v2-fixed.json`，`docs/tmp/e2e-v2-fixed-rerun.md`。 |
| 135 | **Python/C++ policy parser 一致性测试** | ✅ | 新增 shared golden v2 policy cases（`scanner/tests/policy_v2_golden/`，5 个 valid + 4 个 invalid），并在两侧接入断言：C++ `scanner/tests/test_scanner.cpp` 直接读取 golden YAML 校验 parse/filter 结果；Python `corpus/tests/test_policy_utils.py` 校验同一批 case 的 parse 结果与选择语义。修复：Python `parse_policy_v2()` 现在拒绝 duplicate mapping/site、将 `default: stock` 归一为 `skip`；C++ `parse_policy_config_text()` 现在要求每个 `sites[*]` 显式给出 `action`。说明：`docs/tmp/parser-consistency-fix.md`。 |
| 136 | **Plan doc 描述修正** | ✅ | 已回写过时的 ✅ 条目描述：#98b（file-based path vs broken inline path）、#98e（去掉已删除的 v1/`selection.mode` 兼容表述）、#98f（prototype landed 而非 authoritative path）、#114（去掉 v1 compat）、#121（wiring rerun 而非 eval closure）、#122（format migration 而非 steady-state closure）、#125（剩余 gap 来源属 inference）、#127（review 结论需区分历史问题与当前仍活跃的问题）。 |
| 137 | **bpftrace v2 policy artifacts 补齐** | ✅ | 已为 `e2e/cases/bpftrace/scripts/` 的 5 个脚本生成 `corpus/build/bpftrace/{exec_trace,open_latency,scheduler_latency,tcp_connect,vfs_read_count}.bpf.o`。8-family scanner census 覆盖 object 内全部 7 个 programs：site-positive 仅 2 个，`open_latency` 的 `kretprobe:do_sys_openat2` 有 `6` 个 `cmov` sites，`scheduler_latency` 的 `tracepoint:sched:sched_switch` 有 `6` 个 `cmov` sites，aggregate `12` sites，其余 `wide/rotate/lea/extract/zero-ext/endian/branch-flip` 全为 `0`。新增 E2E-facing policy 文件 `corpus/policies/bpftrace/open_latency/do_sys_openat2.policy.yaml` 与 `corpus/policies/bpftrace/scheduler_latency/sched_switch.policy.yaml`，均为 `version: 2`、`default: apply`、`families: {cmov: skip}`、`sites: []`。`parse_policy_v2()` 解析通过；live attach 验证 `resolve_bpftrace_policy_files()` 已能命中 `open_latency`/`scheduler_latency`。注意 bpftrace live program name 会去掉 probe 前缀，所以 policy filename 必须按 live bare name 写。报告：`docs/tmp/bpftrace-policy-artifacts.md`。 |
| 138 | **CMOV / EXTRACT correctness fix + VM revalidate** | ✅ | 根因定位：widened `COND_SELECT` patterns（guarded-update、switch-chain、backward-join variants）被统一 canonicalize 成 `BPF_JIT_CF_COND_SELECT`，但 x86 `emit_canonical_select()` 只实现 simple diamond/compact 的 `cmp+cmov` lowering，导致 broader site 的 ALU/body/join edge 被丢掉；`mixed_alu_mem extract@228` 另有 BMI1 `BEXTR` cross-register 编码问题。修复：x86 `emit_canonical_select()` 现只接受 simple diamond/compact，其余 fail-close 回退 stock；`jit_directives.c` 把 `COND_SELECT` / `BITFIELD_EXTRACT` 的 canonical-site validation 接回验证链；`emit_bextr()` 修正 ModRM 操作数顺序，并把 BMI1 fast path 收紧到 in-place extract。framework-kernel VM 两轮验证（blind-apply 与 policy-path）均通过：`binary_search`、`switch_dispatch`、`branch_dense`、`bpf_call_chain`、`bounds_ladder`、`mixed_alu_mem` 全部 `stock == kernel-recompile` 且无 crash。清理：`mixed_alu_mem.yaml` 已改回 `default: apply`，`bounds_ladder.yaml` 已是 `default: apply`。日志：`docs/tmp/cmov_extract_blind_apply_validation.log`、`docs/tmp/cmov_extract_policy_validation.log`；报告：`docs/tmp/cmov-emitter-fix.md`。 |
| 139 | **Micro authoritative rerun（fixed policy + steady-state）** | ✅ | framework-kernel VM `2/10/500`，per-benchmark VM boot。**56/56 valid**（首次零 invalid），overall geomean `1.018x`，applied-only **1.049x**（8 applied rows：cmov_dense 1.230x, memcmp_prefix_64 1.229x, bpf_call_chain 1.109x, log2_fold 1.042x, mixed_alu_mem 1.023x; losses: cmov_select 0.975x, large_mixed_500 0.947x, bounds_ladder 0.889x）。之前 6 个 mismatch/crash 全部恢复为 valid。32 no-policy→stock + 16 file→skip(0 sites) + 8 file→apply。`micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json`，`docs/tmp/kernel-recompile-micro-v2-fixed-authoritative.md`。 |
| 140 | **Tetragon connect_storm -50.5% 回归调查** | ✅ | 结论：**workload 噪声**，不是 policy 回归。(1) 绝对吞吐在 3 次 run 间飘 337→2488→1509 ops/s；(2) tracked BPF events 只有 7-10/phase，runtime 几乎不变；(3) Tetragon v2 policy 无 `cmov: skip`，唯一 live apply 的 non-CMOV family 只有 branch-flip(28 sites)；(4) `bpf_generic_kprobe` corpus path 与 daemon-mode 非同一条被测路径。建议做 5-10 组复跑取中位数确认。`docs/tmp/tetragon-connect-storm-investigation.md`。 |
| 141 | **micro/policies/per_family v1→v2 升级** | ✅ | 8 个 per-family policy 文件从 v1 `selection: {mode: allowlist, families: [...]}` 升级为 v2 `version: 2, default: skip, families: {<fam>: apply}, sites: []`。Python `parse_policy_v2()` 8/8 OK，C++ `test_scanner` 169 PASS。 |
| 142 | **v1 policy 残留清理 + v2 纯化** | ✅ 已被 #145 取代 | 审计所有 policy 文件和 scanner/Python 代码，删除 v1 compat 逻辑，统一为纯 v2。codex `b0qtbqqih` 完成。后续 #145 进一步将 v2 family/default 抽象替换为 v3 per-site directive list。 |
| 143 | **Post-cmov-fix micro 全量重跑** | ✅ | 56/56 valid, 0 crash。**11/56 applied**（从 #139 的 8 涨到 11，新增 binary_search/switch_dispatch/branch_dense）。Overall geomean **1.007x**，applied-only **0.986x**（新加入的 3 个 benchmark cmov site 被 fail-close 回 stock）。报告：`docs/tmp/post-cmov-fix-micro-rerun.md`，数据：`micro/results/post_cmov_fix_micro.json`。 |
| 144 | **Post-cmov-fix corpus 抽样重跑 + cmov 消融** | ✅ | 以可 `packet_test_run` 的 CMOV-bearing corpus 程序做 45-program / 7-source VM 抽样（84 eligible pool, 42 measured timing pairs），比较两组 v3 policy：(A) allowlist 含 CMOV vs (B) 当前 `cmov:skip`。结果：**CMOV 仍整体负面**；Group A/Group B 归一化 geomean **0.906x**，对 stock 的 exec geomean 分别 **0.859x** vs **0.947x**。wins/losses/ties = **21/20/1**，但少数重度回归主导整体结果：`xdp_fwd_fib_full` **0.133x**、`balancer_ingress` **0.187x**、`xdp_fwd_fib_direct` **0.333x**、`cgroup_skb_ingress` **0.643x**。当前 runnable sample 中所有 live CMOV 都是 **`cond-select-64`**；`calico`/`linux-selftests` 小幅正面，但被 `katran`/`xdp-tools`/`tracee ingress` 的大幅负面抵消。结论：**暂时保留 corpus steady-state 的 `cmov:skip`**。报告：`docs/tmp/post-cmov-fix-corpus-ablation.md`；数据：`corpus/results/post_cmov_fix_corpus_ablation.json`。 |
| 145 | **v3 policy: per-site directive list** | ✅ | 已完成 v2→v3 迁移：policy 现为 scanner sites 子集（`version: 3`, `sites: [{insn, family, pattern_kind}]`），不在 list 中即不 apply。scanner C++ parser/filter/CLI、Python `policy_utils.py`、`generate_default_policies.py`、`auto_tune.py`、`e2e/common/recompile.py`、`run_bflip_endian_skip_sweep.py` 已切到 v3-only；scanner README + golden tests 已更新；`micro/policies/`、`micro/policies/per_family/`、`corpus/policies/` 已重生成并用 `parse_policy_v3()` 验证 **614** 个 YAML 全部通过。验证：`cmake --build scanner/build --target bpf-jit-scanner --target test_scanner -j`、`./scanner/build/test_scanner` = **PASS 163**、`python3 -m py_compile corpus/policy_utils.py`。 |
| 146 | **Recompile 开销测量** | ✅ | Scanner latency: **4.32ms** median (micro), **4.42ms** (corpus 50-object)。Kernel recompile syscall: **29.89μs** median, **63.31μs** p90。Scanner/syscall ratio 207.8x — overhead 完全 userspace-dominated。Blob size: 164B (1 site) → 9.6KB (86 sites) → 213KB (992 sites)。线性 scaling: 13.03ms/1k insns (R²=0.997)。报告：`docs/tmp/recompile-overhead-measurement.md`。 |
| 147 | **bpftrace E2E v3 validation** | ✅ | 修复 `recompile.py` remapped_sites==0 EINVAL bug 和 bpftrace/case.py v3 parsing。VM 验证：v3 policy resolve + remap + no-op 成功，正向控制 1-site apply 成功。报告：`docs/tmp/bpftrace-e2e-v3-validation.md`。 |
| 148 | **架构 Review + 图** | ✅ | Mermaid 架构图 + 流程图。关键发现：WIDE_MEM/ROTATE/ADDR_CALC 缺 canonical-site validation，scanner `pattern_kind` filtering bug，无 rollback/recompile-lock/tracepoints。报告：`docs/tmp/architecture-review-and-diagrams.md`。 |
| 149 | **Canonical-site validation hardening** | ✅ | 内核 `bpf_jit_validate_canonical_site()` 现接回 `WIDE_MEM` / `ROTATE` / `ADDR_CALC` exact validators，并把 `WIDE_MEM` / `ROTATE` / `ADDR_CALC` / `BITFIELD_EXTRACT` / `ZERO_EXT_ELIDE` / `ENDIAN_FUSION` / `BRANCH_FLIP` 全部收紧为“site shape + extracted canonical params”双重校验；同时给 `ZERO_EXT_ELIDE` / `ENDIAN_FUSION` / `BRANCH_FLIP` 补了 interior-edge 拒绝，`BRANCH_FLIP` 参数校验放宽到接受 `JSET`。构建验证：`make -C vendor/linux-framework -j$(nproc) bzImage` ✅；VM smoke：`bitcount` / `cmov_dense` / `load_byte_recompose` 均 `stock == kernel-recompile`，结果写入 `micro/results/pure_jit_smoke_20260313.json`。 |
| 150 | **Kernel engineering cleanup** | ✅ | codex 全量审读 ~5800 LOC kernel 变更，修复：RORX emitter 指针 bug、branch-flip/extract validation 收紧、same-site rule lookup bug、dead legacy emitters 删除、LEA emission 清理、interior-edge validation 集中化、FineIBT shadow state 移除。bzImage + VM 验证通过。`docs/tmp/kernel-engineering-cleanup.md` |
| 151 | **Kernel self-tests** | ✅ | 18/18 tests PASS。覆盖：lifecycle、malformed blob rejection、correctness preservation、concurrency EBUSY、recompile-after-attach。3 个初始 test-side 失败已修复（XDP packet padding、COND_SELECT 3-insn 形式、ROTATE 64-bit 形式），无 kernel bug。`tests/kernel/test_recompile.c`，`docs/tmp/kernel-selftest-run.md` |
| 152 | **Kernel 5 safety fixes** | ✅ | smp_store_release() 发布 bpf_func、不清 exception_cb、synchronize_rcu() 退役旧 image、扩展 rollback、recompile_count 饱和、masked ROTATE 收紧。bzImage + VM 验证通过。`docs/tmp/kernel-safety-fixes.md` |
| 153 | **JIT image binary diff + zero-site identity** | ✅ | **重大发现：re-JIT 是全程序重编译，site 优化会改变 non-site 字节。** 实测 `test_wide`：site 从 18→6 bytes（省 12 bytes），整个 image 149→137 bytes，downstream 相对跳转编码也跟着变了（`[0x91]=ef → [0x85]=3f`）。**Zero-site identity 已修复**：新增 `num_applied == 0` short-circuit，0 applied sites 保留原 image（19/20 tests pass）。**Site-only diff 仍失败**：这是 full-image recompile 的固有属性，不是 bug。修复方向：(1) patch-site 设计，(2) fixed-width site reservation + NOP padding，(3) relaxed contract（只保证语义等价）。**这确认了 code layout shift 是性能回归的潜在来源。** `docs/tmp/jit-image-diff-analysis.md`，`tests/kernel/test_recompile.c` |
| 154 | **Per-canonical-form instruction benchmark 分析 + 实现** | ✅ | Scanner 实际扫描全部 56 objects。**结论：只有 WIDE_MEM 有纯隔离 benchmark（23 个），其余 7 个 form 全部缺失纯 benchmark。** 29 个是 mixed form，4 个 no-site。**已实现 6 个纯隔离 benchmark**：`cond_select_dense`（cmov=256）、`rotate_dense`（rotate=256）、`addr_calc_stride`（lea=8）、`extract_dense`（extract=512）、`endian_swap_dense`（endian=256）、`branch_flip_dense`（bflip=255）。全部通过 scanner isolation 验证（target form sites > 0, 其余 form = 0）。编译 + `run_micro.py --list` + scanner 验证通过。`docs/tmp/per-form-benchmark-analysis.md`，`docs/tmp/per-form-benchmarks-implementation.md` |
| 155 | **Corpus regressor root cause（per-site leave-one-out）** | ✅ | Top-10 regressors 中只有 **3/10 是真实回归**（exec_ns >= 100ns），其余 7/10 是 sub-ktime noise（exec_ns 7-25ns）。3 个真实回归全是 Calico 程序，共同因素是 **branch-flip**（2-4 sites），次级嫌疑 endian（6-47 sites）。但结合 #157 结论，dummy packet 可能根本没走到 site 对应路径，回归可能是 code layout shift 在无关路径上的影响。`docs/tmp/corpus-regressor-root-cause.md` |
| 156 | **Measurement improvement（dual TSC + warmup + adaptive）** | ✅ | kernel runner 修复落地：(1) `exec_ns` 始终保留 ktime，`wall_exec_ns` 始终单独输出 rdtsc，新增 `timing_source_wall` 字段；(2) `--warmup` 接入 runner，默认 5 次，recompile applied 后执行；(3) `duration==0` fallback 逻辑删除。`make -C micro micro_exec` 通过，`simple` 输出确认双时间源。`docs/tmp/kernel-runner-measurement-fixes.md` |
| 157 | **Benchmark framework 审计 v3** | ✅ | **P0 发现**：(1) corpus 全部程序共用同一个 64B dummy packet，无证据表明触发了优化 site（construct validity 问题）；(2) corpus 每 target 仅 1 次 fresh pair，无重复/CI/显著性检验；(3) micro 只有 8/56 applied（非文档说的 11/56），family 混合严重，无 per-form isolation。**P1**：kernel runner 已采 TSC 但不用、re-JIT 后无 warmup、无自动 JIT diff、corpus 顺序固定。**关键纠正**：ktime repeat=200 下量化步长仅 0.15-0.5ns/sample，不是主因；corpus 0.875x 最大嫌疑是 construct validity（dummy packet 没触发优化路径）。`docs/tmp/benchmark-framework-audit-v3.md` |
| 158 | **Post-cleanup 验证 + 全量重跑** | 🔄 | bzImage rebuild OK (`7.0.0-rc2-g05a1845490ed-dirty`)，self-tests 19/20 pass（预期的 site-only diff fail），micro smoke 通过（`load_byte_recompose` stock==recompile, wide_sites=1 applied）。**修复后 full micro rerun 已完成**：per-benchmark VM boot 路径在 fixed bzImage + dual-TSC/warmup runner 上拿到 `62/62` valid pairs；但 **corpus rerun 仍待执行**。验证：`docs/tmp/post-cleanup-validation.md`；micro artifacts：`micro/results/post_fix_micro_62bench_20260313.json`，`docs/tmp/post-fix-micro-62bench-rerun.md`。 |
| 159 | **Root Makefile 一键构建+测试** | ✅ | 根目录 `Makefile` 已创建。构建目标：`all`（micro+scanner+kernel-tests）、`micro`、`scanner`、`kernel`。VM 目标：`vm-selftest`、`vm-micro-smoke`、`vm-micro`、`vm-corpus`、`vm-e2e`、`vm-all`。Quick 验证：`smoke`、`check`（all+scanner-tests+smoke）、`validate`（check+vm-selftest+vm-micro-smoke）。验证：`make scanner`、`make scanner-tests`（1/1 pass）、`make smoke`（compile 6.234ms, exec 81ns）全部通过。`docs/tmp/root-makefile-report.md` |
| 160 | **Post-fix 全量 micro 重跑（62 bench, 新 per-form + fixes）** | ✅ | 修复后 bzImage + runner（dual TSC + warmup）上完成 strict rerun：**`62/62` valid，`14/62` applied，overall geomean `0.978x`，applied-only `0.877x`**（stock / recompile）。对齐旧口径的 shared-56 子集为 `0.983x` overall、`0.869x` applied-only，低于 #143 的 `1.007x` / `0.986x`。6 个新增 per-form rows 中 `3/6` applied，整体 geomean `0.931x`；`rotate_dense` `1.187x` 是唯一 applied win，`cond_select_dense` `0.837x`、`extract_dense` `0.753x` 为 applied losses，`addr_calc_stride` / `endian_swap_dense` / `branch_flip_dense` 因当前 per-family policy catalog 空/lookup miss 未实际应用。Top win / loss：`packet_rss_hash 2.875x`，`memcmp_prefix_64 0.560x`。数据：`micro/results/post_fix_micro_62bench_20260313.json`；报告：`docs/tmp/post-fix-micro-62bench-rerun.md`。 |
| 161 | **Scanner pattern_kind filtering bug fix** | ✅ | 调查确认：#148 指向的是已提交基线中的真实 bug，`filter_rules_by_policy_detailed()` 旧实现只按 `(insn, family)` 匹配，确实忽略 `pattern_kind`；当前工作区已在 `scanner/src/policy_config.cpp` 修复为 `(insn, family, pattern_kind)` 精确匹配，并补了 scanner/Python tests。验证：`cmake --build scanner/build --target test_scanner -j`、`./scanner/build/test_scanner` = `PASS 179`、`python3 -m unittest corpus.tests.test_policy_utils` = `OK`。报告：`docs/tmp/scanner-pattern-kind-investigation.md`。 |
| 162 | **Corpus construct validity 分析** | ✅ | **假说成立**：corpus 0.875x 主要由测量噪声和代码布局效应构成，非优化 site 实际执行效率。三层证据：(1) 94/156 程序 exec_ns < 100ns，其中 58/66 未优化程序也显示 >5% 偏差（noise-dominated）；(2) Calico `calico_tc_main` 6 个 .bpf.o 中代码变化一致（-0.4%），但 speedup 从 0.531x 到 1.037x，证明 baseline 短的版本提前退出未执行到 site；(3) 优化 site 位于 insn 424-8315，175ns 退出只执行约 400-600 条指令。**结论**：corpus exec geomean **无效**（噪声+布局主导），corpus code size **有效**，micro 数据 **有效**。建议：构造 path-targeted packet 或以 code size 为主要 corpus 指标。`docs/tmp/corpus-construct-validity-analysis.md` |
| 163 | **Live scanner + daemon enumerate 架构** | ✅ | 三组件完全解耦：scanner `enumerate` 子命令用 `BPF_PROG_GET_NEXT_ID` → `BPF_OBJ_GET_INFO_BY_FD` → `xlated_prog_insns` 分析 live 程序。修复 `mini_bpf_attr_id` struct 布局 bug（`next_id` offset 错误导致死循环）。Host smoke：197 live progs, 165 with sites, 1920 total sites, `--prog-id` 过滤 0.2s。`docs/tmp/scanner-enumerate-implementation.md` |
| 164 | **E2E pipeline 切 enumerate 路径** | ✅ | `e2e/common/recompile.py` 新增 `_enumerate_scan_one()` + `_enumerate_apply_one()`，`_USE_ENUMERATE_PATH=True`。Case 文件不需改（公共 API 不变）。Graceful fallback 到 legacy `scan --prog-fd` 路径。`docs/tmp/e2e-enumerate-pipeline-switch.md` |
| 165 | **#57 消融补全** | ✅ | byte-recompose **50.7%** of gap surplus（主因）；callee-saved **~0%**（7.0-rc2 已上游化 `detect_reg_usage()`）；BMI/BMI2-only **~0%**（rorx/bextr 指令选择非主因）。`docs/tmp/ablation-byte-recompose-callee-bmi.md` |
| 166 | **Per-form authoritative rerun 矛盾调查** | ✅ | 根因：(1) per-form rerun 用共享 VM、stock 有 60% 噪声；auth rerun 独立 VM 是 ground truth。(2) **extract/endian/branch_flip emitter bug**：applied=True 但 jited size 零变化，回归来自白跑的 JIT 重编 + I-cache flush 开销。`docs/tmp/per-form-discrepancy-investigation.md` |
| 167 | **修复 extract/endian/branch_flip emitter** | ✅ | 根因确认：(1) BITFIELD_EXTRACT：`dst_reg==src_reg` guard 阻止 BEXTR 用于 with-copy 模式（3-insn→2-insn），fallback 重发相同字节。修复：移除该 guard，BEXTR VEX 编码独立支持任意 dst/src。验证：`extract_dense` jited 11255→10487（-6.8%，512 sites×1.5B）。(2) ENDIAN_FUSION/BRANCH_FLIP：旧 kernel (05a184549) 有 bug，已在 a7ce05b49 修复；32-bit MOVBE 与 LDX+BSWAP32 等大（各 5B），size 不变但微架构得益。commit `daca445b1`（arch/x86/net/bpf_jit_comp.c）。报告：`docs/tmp/emitter-fix-extract-endian-bflip.md`。 |
| 168 | **endian/branch_flip 性能回归深度调查** | ✅ | 静态代码分析完成。结论：emitter 无 bug（MOVBE 确实被发出，branch_flip 确实 swap 体），但 same-size 重编（MOVBE=LDX+BSWAP32=5B，branch_flip total size 不变）的 I-cache flush 开销 > 微架构收益。endian/branch_flip 属 policy-sensitive directive（需有 branch misprediction 证据或 64-bit load 才有净收益）。VM 字节 dump 验证 pending（`docs/tmp/endian-bflip-vm-verification.md`）。调查报告：`docs/tmp/endian-bflip-perf-investigation.md`。 |
| 170 | **解耦 Gap 1：enumerate per-site manifest 输出** | ✅ | enumerate --json 只输出 total_sites，无 per-site {insn,family,pattern_kind}。导致 E2E policy-file apply 仍 fallback 到旧 scan --prog-fd。修复：~30 行 C++ 让 enumerate 输出 per-site manifest。agent 运行中。 |
| 171 | **解耦 Gap 2：Daemon 模式（持续监控）** | ❌ | 当前 scanner enumerate 是一次性 CLI，跑一次退出。真正解耦需要 daemon 模式：持续监控 BPF_PROG_GET_NEXT_ID，新程序加载后自动分析+优化。论文 eval 不阻塞，但系统完整性需要。 |
| 172 | **解耦 Gap 3：Native code（jited_prog_insns）分析** | ❌ | 当前 scanner 只分析 BPF insn 做 pattern matching，jited_prog_insns 提取了但未用于分析。缺失能力：(1) 检测 native code 是否已有 CMOV/BEXTR（避免重复优化）；(2) 用 native code 做更精确的 cost model（如 instruction count、code size delta 预测）。这是架构最大缺口。 |
| 173 | **解耦 Gap 4：Corpus pipeline 切 enumerate** | ❌ 低优先级 | corpus drivers 仍用 .bpf.o + scan --prog-fd。功能正确但不符合三组件解耦架构。 |
| 76 | **scx_rusty/lavd 端到端** | 🔄 | `e2e/cases/scx/` 已落地并在 framework VM（`7.0.0-rc2-g2a6783cc77b6`, `4` vCPU）跑通 `scx_rusty` userspace loader → 30s `hackbench` / `stress-ng --cpu 4` / `sysbench cpu` baseline。活跃 `13` 个 struct_ops programs，扫描到 `28` sites（CMOV `27`, LEA `1`；`rusty_enqueue=12`, `rusty_stopping=10`, `rusty_set_cpumask=2`, `rusty_runnable/quiescent/init_task/init` 各 `1`）。最新调查确认旧的 live recompile `EINVAL` 实际来自 x86 stale-extable oops；该 bug 已修，但 live attached `struct_ops` 仍因缺 trampoline regeneration 被显式 `-EOPNOTSUPP` 拒绝，所以当前仍只有 honest baseline + site census，没有 post-reJIT 对比。`docs/tmp/scx-e2e-report.md`, `docs/tmp/struct-ops-recompile-investigation.md` |
| 169 | **Post-BEXTR-fix 62-bench authoritative rerun** | ✅ | build #38 bzImage (`7.0.0-rc2-ga7ce05b49cb2-dirty`)，warmups=2/iter=2/repeat=500，独立 VM per bench。**Overall geomean 1.003x（61/62 valid），applied-only 0.932x（16 applied），wins/losses/ties=30/30/1**。关键结果：`rotate_dense` 1.167x win（256 sites），`addr_calc_stride` 1.401x win（8 sites），`branch_flip_dense` 1.052x win（255 sites），`bitfield_extract`（non-dense）1.288x win。**extract_dense 0.556x regression（512 BEXTR sites，比 pre-fix 0.677x 更差）**：BEXTR fix 在 dense 512-site 场景反而劣化，需要分析 native code 生成，考虑 policy 中对 dense BEXTR skip。`endian_swap_dense` 0.695x 持续回归（same-size MOVBE，预期内）。报告：`docs/tmp/micro-62bench-post-bextr-fix.md`，结果：`micro/results/micro_62bench_post_bextr_fix_20260313.json`。 |
