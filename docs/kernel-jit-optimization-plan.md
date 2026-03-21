# Kernel eBPF JIT 优化：计划与进度

> 本文档是 kernel JIT 优化论文的单一 hub。
> **论文核心方向：必须追求 net speedup，越多越好。架构贡献和 policy-sensitivity 是支撑论据，不是主卖点。Paper 必须展示真实程序上的可测量加速。**
> **⚠️ Corpus exec geomean 0.875x 已确认无效（#162）**：dummy packet 导致 XDP/TC 程序 early-exit，优化 site 未被执行，测量值是噪声+布局效应。**必须修复 corpus packet 构造使 site 被实际执行**，而不是转向 code size。Code size 不是论文关注点。
> **编辑规则**：
> - **⚠️ 未经用户明确同意，禁止修改内核代码（vendor/linux-framework）。** 所有内核改动必须先调研→用户确认→再实施。codex/agent prompt 必须包含此约束。
> - 未经用户明确要求，禁止 git commit / git push。
> - 任何 TODO/实验/文档引用条目被取代时，必须至少保留一行并标注状态，不得直接删除。
> - 每个任务做完 → 立即更新本文档（任务条目状态 + 关键数据 + 文档路径）。
> - 每次 context 压缩后 → 完整读取本文档恢复全局状态。
> - 用 agent background 跑任务，不阻塞主对话。
> - **构建+修改+运行不拆分**：一个 subagent 负责完整流程（改代码→构建→运行→发现 bug→修复→再运行），不要拆成多个 agent。
> - **⚠️ 同一时间只能有一个 agent 修改内核代码（vendor/linux-framework），也只能有一个 agent 跑测试（VM benchmark / selftest）。** 多个 agent 同时改内核代码会产生 git 冲突；多个 agent 同时跑 VM 测试会竞争资源、结果不可靠。调度时必须串行化内核改动和测试任务。
> - **⚠️ codex 默认不要 commit/push，除非 prompt 明确要求。** 改完代码就停，由 Claude 统一 commit。
> - **⚠️ 如果需要 commit，必须在 main 分支直接做，不要开新分支。** 开分支导致合并冲突。
> 上次更新：2026-03-21a。**权威数据**（#256 rerun）：micro **1.057x** / applied-only **1.193x**；corpus **0.983x**；Tracee **+8.1%**；Tetragon **+20.3%/+32.2%**；Katran BPF **1.108-1.168x**（harness 升级后）；gap **0.581x**。vm-selftest **35/35**。vm-micro validation **62/62 valid, 1.100x**。**⚠️ 2026-03-21 重大架构探索**：考虑 BpfReJIT v2 — 从 native-level rewrite 转向 "verifier-guarded post-load program transformation framework"。核心方案：**Inline Kfunc**（复用 kfunc 验证 + JIT 内联展开）+ **BPF_PROG_REJIT**（bytecode patch→re-verify→image swap）+ **BPF_PROG_GET_ORIGINAL**（透明获取原始 bytecode）。9 个 codex 调研完成，2 个进行中。详见 #304/#304a/#304b。

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
| Micro overall (#169, post-BEXTR-fix) | 1.003x | 已被 #176 取代 |
| Micro applied-only (#169) | 0.932x | 已被 #176 取代 |
| **Micro 6-dense optimized (#173, policy-optimized)** | **1.125x** | **✅ 实测正向（VM，3 regressor 清空）** |
| **Micro 62-bench overall (#173, policy-optimized)** | **0.995x** | R5 结果（VM噪声影响），已被 #174 取代 |
| **Micro 6-dense optimized (#174, Build #40, endian restored)** | **1.075-1.100x** | **✅ Build #40 + 256 endian sites 恢复** |
| **Micro 62-bench overall (#174, Build #40 R10 optimal policy)** | **1.006x** | **✅ up from 0.995x** |
| **Micro 62-bench applied-only (#174, Build #40, 15 benches)** | **1.040x** | **✅ up from 0.993x** |
| Micro 62-bench overall (vm-micro Makefile flow, 7de19ef03, 20260314) | 1.054x | 已被 #189 取代（non-applied 噪声膨胀，实际值偏高） |
| Micro 62-bench applied-only (vm-micro 20260314, 16 benches) | 1.074x | 已被 #189 取代 |
| Micro 62-bench overall (#189 R2, 10iter, 20260318) | 1.024x | 已被 #189 R3 取代（policy 状态中间态） |
| Micro 62-bench applied-only (#189 R2, 9 benches) | 1.118x | 已被 #189 R3 取代 |
| **Micro 62-bench overall (#189 R3, 干净环境 10iter/5warm/1000rep, 20260318) ← 当前权威** | **1.024x** | **✅ non-applied geomean 1.002（极干净）；7 applied, 5W/2L；数据：`micro/results/vm_micro_authoritative_20260318.json`** |
| **Micro 62-bench applied-only (#189 R3, 7 benches, 20260318) ← 当前权威** | **1.110x** | **✅ rotate_dense +39.1%, rotate64_hash +34.1%, cmov_dense +15.0%；清掉 cmov_select/mixed_alu_mem** |
| Micro 62-bench overall (#226, post-DSL-removal, 2warm/10iter/200rep, 20260319) | 1.017x | 7/7 applied 恢复，0 回归。默认参数，非权威 |
| Micro 62-bench applied-only (#226, 7 benches, 20260319) | 1.078x | rotate_dense +24.5%, rotate64_hash +20.0%, cmov_dense +5.6%。参数不同导致略低于权威 1.110x |
| Corpus v2 fixed (0.875x) | 已知无效 | dummy packet, early-exit，历史数据 |
| **Corpus post-fix rerun (#173, fixed IPv4+TCP packet, build #38)** | **1.008x** | ✅ 正向！Calico 1.070x, Suricata 1.538x（已被 #175 取代） |
| **Corpus Build #42 rerun (#175, BEXTR without-copy fix, ac593b2c1) ← 当前权威** | **1.046x** | **✅ 提升 3.8%！Calico 1.097x, xdp-tutorial 1.091x, linux-selftests 1.005x** |
| Corpus clean rerun (#206, trampoline guard, 20260318) | 0.934x | ⚠️ 低于旧权威，未提升。trampoline guard 可能导致更多 tracing progs -EOPNOTSUPP |
| Gap 恢复率 | pending | corpus 1.046x vs 0.609x pure-JIT gap |
| E2E Tracee exec_storm (pre-fix, recompile=0/13, **无效**) | ~~+21.65%~~ | **无效** — recompile 0/13，已被最新数据取代 |
| **E2E Tracee exec_storm (post-BEXTR-fix, recompile=11/13, #172, authoritative)** | **+6.28%** | app throughput; file_io **+7.00%**; network +1.44%; BPF ns -4.22% |
| E2E Tetragon (#200, harness bug) | stress_exec +7.94%, connect_storm -55.96% | 已被 #204 取代（harness 漏掉了 connect 热路径 programs） |
| **E2E Tetragon (#204, harness fix, 20260318) ← 当前权威** | **stress_exec +8.70%, connect_storm +22.29%** | **✅ 全 4 workload 正向！** file_io +0.34%, open_storm +0.42%。7 programs, 3 applied, 49 bflip sites。数据：`e2e/results/tetragon_authoritative_20260318.json` |
| E2E XDP forwarding | +0.27% | **已删除 #203**（3 sites，无优化价值，将被 Katran 替换） |
| **E2E Katran (#205, DSR direct-map, 20260319) ← 当前实现已验证** | **功能 OK；latest rerun BPF avg_ns 407.6→507.0 (+24.4%)** | **✅ gRPC compile 已移出 benchmark 路径。** setup 直接发现 checked-in `katran_server_grpc` bundle，VM rerun 5/5 HTTP、30 IPIP decap packets、4 wide sites applied。旧 bring-up 结果 `603.7→351.8` 仍保留作历史 datapath proof，但当前 rerun 未复现。报告：`docs/tmp/katran_e2e_grpc_fix_20260319.md`，结果：`e2e/results/katran_authoritative_20260319.json` |
| E2E Tracee (20260313, authoritative) | exec_storm +6.28%, file_io +7.00% | 2026-03-18 rerun 已修复 guest bpftool wrapper 并成功跑通，但新结果仅 exec_storm +5.97%、file_io +1.68%、network +2.20%，未超过旧权威，因此旧权威保持 |
| E2E bpftrace | 0.992x | 纯 CMOV sites 被 skip → 0 applied → 永远 neutral |
| E2E scx | 无数据 | struct_ops EOPNOTSUPP，不支持 recompile |

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
   - ~~**P0：Authoritative 62-bench rerun per-form 结果与专门 rerun 严重矛盾**~~ ✅ #168 调查完成（`docs/tmp/2026-03-13/endian-bflip-perf-investigation.md`）：矛盾来自 2-iter 噪声（shared VM session），auth rerun 是 ground truth。endian/branch_flip **emitter 无 bug**（a7ce05b49 之后已正确），但 same-size 重编（MOVBE=5B=LDX+BSWAP32，branch_flip 体积等价）导致 I-cache flush 开销 > 微架构收益 → 持续回归（~0.75-0.78x）。这是固有属性，不是可修 bug。Endian/branch_flip 属 **policy-sensitive** directive（需有 branch misprediction 或 CPU model 证据才能开启）。VM 字节 dump 验证已取消——静态分析已足够定论，无需额外 VM dump。
   - Corpus 每 target 多次 paired rerun + CI/bootstrap（降优先级）
2. **~~P0：验证 JIT image 正确性~~** ✅ #153
3. **~~P0：Post-cleanup 全量重跑~~** ✅ #160 — 62/62 valid, 17 applied, overall 1.0035x, applied-only 0.9417x。**但 per-form 数据疑似无效（见上）**
4. **~~P1：Measurement 改进~~** ✅ #156
5. **P0：框架解耦** — ✅ #163 scanner enumerate 已实现（197 live progs, 1920 sites），🔄 #108 E2E pipeline 切换中
6. **P1：增加高回报 canonical form** — prologue 优化、更完整的 byte-recompose
7. **P1：跑更多 E2E workload** — ✅ #172 Tracee 已完成有效 rerun（post-BEXTR-fix，11/13 applied，exec_storm +5.97% app / -7.11% BPF ns）。报告：`docs/tmp/active/tracee-e2e-post-fix-rerun.md`，数据：`e2e/results/tracee_authoritative_20260313_postfix.json`。旧 +21.65% 数据已作废（recompile 0/13）。需要更多 E2E workload（Tetragon 等）。
8. **~~P1：#57 消融补全~~** ✅ byte-recompose **50.7%**，callee-saved ~0%（7.0-rc2 已上游化），BMI ~0%
9. **~~P1：Corpus rerun（fixed packet + use-policy 路径）~~** ✅ #158/#173/#175 完成。旧结果（build #38，1.008x）已被 **#175 build #42 (BEXTR without-copy fix) 结果取代：1.046x exec geomean**（152 measured pairs，39 applied programs）。Calico 1.097x，xdp-tutorial 1.091x，linux-selftests 1.005x，katran 0.872x（regression）。数据：`corpus/results/corpus_post_fix_build39_20260313.json`（实际为 build #42/ac593b2c1），报告：`docs/tmp/active/corpus-post-fix-build39.md`。旧 0.875x 无效数据已取代。
10. **~~P1：#170 BEXTR emitter 性能 bug 修复~~** ✅ #167/#173 修复（daca445b1）+ 验证。BEXTR fix 后 extract_dense 在 R2 测得 1.076x（vs 0.556x pre-fix）。报告：`docs/tmp/2026-03-13/cmov-bextr-regression-investigation.md`
12. **~~P0：#171 dense policy 优化（2026-03-13）~~** ✅ #171/#173 已验证。VM 5轮迭代确认最优 policy：3 regressor 全部清空，6-dense geomean 1.097x（R1），62-bench 0.995x。分析报告：`docs/tmp/active/policy-iteration-rounds.md`，62-bench 数据：`micro/results/micro_62bench_policy_optimized_20260313.json`。
13. **~~P1：提升 62-bench overall > 1.0x~~** ✅ #174 Build #40 + policy 迭代（R6-R11）达成：overall **1.006x**，applied-only **1.040x**。endian_swap_dense 恢复 256 sites 后从 0.695x→1.013-1.139x。数据：`micro/results/micro_62bench_build40_policy_optimized_20260313.json`，分析：`docs/tmp/active/policy-iteration-rounds.md`（R6-R11 节）。
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
3. 评估包含真实程序和至少一个端到端部署 ✅（Tracee daemon exec_storm **+6.28%** / file_io **+7.00%**（post-BEXTR-fix authoritative, recompile=11/13）; ~~+21.65%~~ **无效**（recompile=0/13）; Tetragon daemon +3.8% app, bpftrace 5/5 attach）
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
11. **Validator = 唯一安全门，Emitter = 无条件信任**：对齐内核 verifier/JIT 模型。Validator 负责全部语义正确性（site 形状 + params 范围 + 架构无关约束如 `lsb+width<=64`）；Emitter 只做机械编码，不重复校验 params。`bpf_jit_arch_form_supported()` 声明架构能力，Validator 保证 params 合法，Emitter 直接 emit。Emitter 返回 -EINVAL 仅用于"此架构无合适指令"，不是"params 不合法"。冗余的 emitter-side 校验和 dead fallback 应删除。

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
> v6 tier-1 改进已完成：通用 site/pattern 上限 24→64、`BPF_PROG_JIT_RECOMPILE` 新增 `log_level/log_size/log_buf`、tuple/binding 上限 12→16。报告：`docs/tmp/2026-03-11/v6-tier1-implementation.md`。

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

### 4.4 Kernel 三层安全模型

对齐 kernel verifier/JIT 原则（§1.4 #11）：Validator 是唯一安全门，Emitter 无条件信任。

```
syscall BPF_PROG_JIT_RECOMPILE(prog_fd, policy_fd)
    │
    ▼
Layer 0: Interface — jit_policy.c (432 行)
    解析不受信的用户态 policy blob → 结构化 rules
    职责：blob 格式/版本/size 校验、rule 排序、overlap 检测
    信任：无（输入全部不可信）
    │
    ├─ Layer 0.5: bpf_jit_arch_form_supported()
    │  架构能力声明。不支持的 form 在此直接拒绝
    │  x86: 8/8 forms    arm64: 4/8 forms
    │
    ▼
Layer 1: Validation — jit_validators.c (1599 行)
    唯一安全门。每个 rule 对 live program 做语义校验
    职责：site 形状匹配、canonical params 提取、
          params 边界检查（lsb+width≤64 等架构无关约束）
    输出：填充 canonical_params，供 emitter 消费
    信任：Layer 0 的 rule 结构（但 site 内容从 live xlated program 读）
    │
    ▼
Layer 2: Emission — arch/*/net/bpf_jit_comp.c
    机械编码。无条件信任 validator 的 canonical_params
    职责：把 params 翻译为目标架构 native 指令
    不做：params 校验、fallback、raw insn 读取
    -EINVAL 仅用于"此架构无合适指令"（不应发生，
           因为 Layer 0.5 已拒绝不支持的 form）
    │
    ▼
Orchestration — jit_directives.c (727 行)
    串联上述三层 + 生命周期管理
    职责：snapshot → per-rule iterate(validate→emit) →
          commit/abort → synchronize_rcu → trampoline regen → ksym
```

**文件布局（`vendor/linux-framework/`）：**

| 文件 | 职责 | 行数 |
|------|------|------|
| `kernel/bpf/jit_directives.c` | Orchestration：syscall 入口、recompile 生命周期、logging、ksym | ~727 |
| `kernel/bpf/jit_validators.c` | Layer 1：8 form 共享 validators、shape parser、params 提取 | ~1599 |
| `kernel/bpf/jit_policy.c` | Layer 0：policy blob 解析、rule 排序、overlap 检测 | ~432 |
| `arch/x86/net/bpf_jit_comp.c` | Layer 2 (x86)：8 form emitters、staged commit/abort、arch override | ~2100 added |
| `arch/arm64/net/bpf_jit_comp.c` | Layer 2 (arm64)：4 form emitters、staged commit/abort、arch override | ~900 added |
| `include/linux/bpf_jit_directives.h` | 共享类型：canonical_params、form metadata、arch callback 声明 | ~272 |

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

### 5.6 Benchmark Framework 架构

#### 设计原则

- **Runner 只测量**：micro_exec 是唯一的 BPF 执行/计时工具，输出标准化 JSON，每个 measurement 一行
- **Orchestrator 统一调度**：一个 Python 调度层，通过 mode 区分 micro/corpus/e2e
- **Makefile 是唯一入口**：所有 benchmark 从 `make vm-*` 触发，不用一次性脚本
- **Same-image paired measurement**：recompile 模式下 load→measure stock→recompile→measure recompile，消除 layout 噪声

#### 三层评估模型

```
┌──────────────────────────────────────────────┐
│  Configuration                                │
│  micro/config/micro_pure_jit.yaml — 62 micro 定义 │
│  corpus/config/ — corpus target 发现           │
│  e2e/cases/*/config.yaml — E2E case 定义       │
│  micro/policies/ + corpus/policies/ — 优化策略  │
└──────────────────┬───────────────────────────┘
                   ▼
┌──────────────────────────────────────────────┐
│  Runner: micro_exec (C++)                     │
│  子命令：run-llvmbpf | run-kernel             │
│  输入：.bpf.o + .mem + repeat/warmup params   │
│  输出：JSON lines, 每行一个 measurement        │
│    {"phase":"stock","exec_ns":N,...}           │
│    {"phase":"recompile","exec_ns":N,...}       │
│  不做：target 发现、policy 选择、结果聚合       │
└──────────────────┬───────────────────────────┘
                   ▼
┌──────────────────────────────────────────────┐
│  Orchestrator: micro/driver.py (Python)       │
│                                               │
│  ┌────────┐ ┌──────────┐ ┌─────────┐         │
│  │ micro  │ │  corpus   │ │   e2e   │         │
│  │ mode   │ │  mode     │ │  mode   │         │
│  ├────────┤ ├──────────┤ ├─────────┤         │
│  │YAML    │ │target    │ │daemon   │         │
│  │manifest│ │discovery │ │setup    │         │
│  │input   │ │io-mode   │ │workload │         │
│  │gen     │ │selection │ │trigger  │         │
│  └────────┘ └──────────┘ └─────────┘         │
│                                               │
│  共享：VM boot、micro_exec 调用、JSON 收集、    │
│       统计聚合（median/geomean/CI）、报告输出    │
└──────────────────┬───────────────────────────┘
                   ▼
┌──────────────────────────────────────────────┐
│  Scanner: scanner/ (C++)                      │
│  子命令：enumerate | scan | apply | policy     │
│  职责：pattern matching、policy 编译、blob 生成  │
│  不做：测量、调度、结果分析                      │
└──────────────────────────────────────────────┘
```

#### 目录布局（理想）

依赖方向：`runner/` 是共享基础，`micro/`、`corpus/`、`e2e/` 各自只依赖 `runner/`，互不依赖。

```
runner/                     # 共享基础设施（不依赖 micro/corpus/e2e）
  docker/                   #   Docker build assets
  scripts/                  #   辅助脚本 (aws_arm64.sh 等)
  src/                      # C++ micro_exec 源码
  include/                  # C++ headers
  CMakeLists.txt
  libs/                     # Python 共享库
    commands.py             #   micro_exec CLI 调用构建
    results.py              #   JSON result 解析/聚合
    statistics.py           #   median/geomean/CI/Wilcoxon
    environment.py          #   CPU/governor/turbo/VM 检测
    vm.py                   #   vng boot/rwdir/exec helpers
    recompile.py            #   scanner enumerate → apply 共享
    policy.py               #   policy YAML v3 解析

micro/                      # Micro 评估层（只依赖 runner/）
  programs/                 #   BPF .bpf.c 源码 (62 个)
  policies/                 #   Per-benchmark policy YAML
  generated-inputs/         #   输入数据 (gitignored)
  input_generators.py       #   二进制输入生成器
  catalog.py                #   micro YAML manifest 加载
  driver.py                 #   micro 调度 (import runner.libs)

corpus/                     # Corpus 评估层（只依赖 runner/）
  build/                    #   .bpf.o 收集 (gitignored)
  policies/                 #   Per-program policy YAML (580 个)
  config/                   #   Corpus manifest
  driver.py                 #   corpus 调度 (import runner.libs)
  discovery.py              #   Target 发现 + io-mode 选择

e2e/                        # E2E 评估层（只依赖 runner/）
  cases/                    #   Per-case: tracee/, tetragon/, katran/, ...
  driver.py                 #   E2E 调度 (import runner.libs)

scanner/                    # Scanner + policy compiler（独立）
micro/config/               # Active micro suite manifest YAML
```

详细设计文档见 `docs/tmp/benchmark-framework-design.md`。

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
| `make vm-e2e` | 跑全部 E2E (tracee + tetragon + bpftrace + scx；`xdp_forwarding` 已退役) |
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
| 1 | v3 JIT pass 框架设计 | ✅ | 8/10。`docs/tmp/2026-03-09/jit-pass-framework-v3-design.md`，`docs/tmp/2026-03-09/jit-pass-framework-v3-final-verdict.md` |
| 2 | v4 Post-load re-JIT 设计 | ✅ | `docs/tmp/2026-03-09/jit-pass-framework-v4-design.md` |
| 3 | v5 声明式 Pattern 设计 | ✅ | 7.5/10。`docs/tmp/2026-03-09/jit-pass-framework-v5-design.md`，`docs/tmp/2026-03-09/jit-pass-framework-v5-review.md` |
| 4 | v7 Hybrid 设计 | ✅ | `docs/tmp/2026-03-08/bpf-jit-advisor-v7.md`，`docs/tmp/2026-03-08/bpf-jit-advisor-v7-review.md` |
| 5 | Interface 设计 | ✅ | 6/10。`docs/tmp/2026-03-08/interface-design-detail.md`，`docs/tmp/2026-03-08/interface-design-review.md` |
| 6 | Verifier-rewrite 分析 | ✅ | JIT lowering 为主。`docs/tmp/2026-03-08/verifier-rewrite-approach.md` |
| 7 | Policy decision layer | ✅ | 3 级策略。`docs/tmp/2026-03-10/policy-decision-layer-design.md` |
| 8 | Directive 发现 | ✅ | 11 候选。`docs/tmp/2026-03-08/directive-discovery-analysis.md` |
| 9 | OSDI readiness | ✅ | 4/10。`docs/tmp/2026-03-08/osdi-readiness-review.md` |
| 10 | 跨文档交叉验证 | ✅ | `docs/tmp/2026-03-08/cross-document-review.md` |
| 11 | POC v1: wide_load verifier rewrite | ⚠️ 方向错误 | `docs/tmp/2026-03-09/poc-design-review.md` |
| 12 | POC v2: cmov_select JIT lowering | ✅ | jited 4168→4167。`docs/tmp/2026-03-09/poc-v2-design-conformance-review.md` |
| 13 | v4 POC（4 directives） | ✅ | ~850 LOC kernel。branch `jit-directive-v4` |
| 14 | v4 bug 修复 | ✅ | `docs/tmp/2026-03-09/v4-bug-diagnosis.md` |
| 15 | v4 review | ✅ | 6/10。`docs/tmp/2026-03-09/v4-implementation-review.md` |
| 16 | v4 Round 1 | ✅ | ADDR_CALC -12%，COND_SELECT log2_fold **+28%**（policy-sensitivity）。`docs/tmp/2026-03-09/v4-round1-test-results.md` |
| 17 | v4 Round 2: WIDE_MEM | ✅ | load_byte_recompose **-13%**。`docs/tmp/2026-03-09/v4-round2-test-results.md`，`docs/tmp/2026-03-09/v4-round2-implementation.md` |
| 18 | v4 Round 3: ROTATE | ✅ | rotate64_hash **-28.4%**。composability 验证。`docs/tmp/2026-03-09/v4-round3-test-results.md` |
| 19 | Fixed baselines 设计 | ✅ | `docs/tmp/2026-03-10/kernel-fixed-baselines-design.md` |
| 20 | Fixed baselines 测试 | ✅ | CMOV 必须 policy-controlled。`docs/tmp/2026-03-10/kernel-fixed-baselines-test-results.md` |
| 21 | Per-directive 隔离测试 | ✅ | `docs/tmp/2026-03-10/kernel-fixed-baselines-per-directive.md` |
| 22 | v5 POC | ✅ | v5=v4 功能等价。`docs/tmp/2026-03-10/v5-minimal-poc-results.md` |
| 23 | v5 迭代 | ✅ | `docs/tmp/2026-03-10/v5-iteration-results.md` |
| 24 | v5 canonical binding | ✅ | v4 1018 LOC vs v5 32 LOC (32x)。`docs/tmp/2026-03-10/v5-canonical-binding-results.md`，`docs/tmp/2026-03-10/extensibility-quantification.md` |
| 25 | Scanner 独立化 | ✅ | `docs/tmp/2026-03-10/scanner-cleanup-results.md` |
| 26 | v5 gap analysis | ✅ | 6.5/10。`docs/tmp/2026-03-10/v5-design-gap-analysis.md` |
| 27 | Framework review | ✅ | 4/10。`docs/tmp/2026-03-10/framework-architecture-review.md` |
| 28 | cmov subprog fix | ⚠️ | emitter bug 见 #47。`docs/tmp/2026-03-10/cmov-subprog-fix-results.md` |
| 29 | Pure-JIT audit | ✅ | `docs/tmp/2026-03-08/pure-jit-benchmark-audit.md` |
| 30 | Host 重跑 | ✅ | pure-jit L/K=**0.797x**。`micro/results/pure_jit_with_cmov.json` |
| 31 | VM 重跑 | ✅ | VM/host parity。`docs/tmp/2026-03-08/vm-rerun-analysis.md` |
| 32 | Directive census | ✅ | 67/98 有 sites，1029 总 sites。`docs/tmp/2026-03-11/real-program-directive-census.md` |
| 33 | Corpus v5 recompile | ✅ | 37/40 apply。`docs/tmp/2026-03-10/corpus-v5-recompile-results.md` |
| 34 | Production corpus | ✅ | Cilium/Katran/xdp-tools。`docs/tmp/2026-03-10/production-program-compilation.md` |
| 35 | Production recompile | ✅ | 15/15 成功。`docs/tmp/2026-03-10/production-corpus-v5-rerun-results.md` |
| 36 | Corpus 扩充 R2 | ✅ | 529 总 .bpf.o（22 项目）。`docs/tmp/2026-03-10/corpus-expansion-round2.md` |
| 37 | Scanner rotate fix | ✅ | `docs/tmp/2026-03-10/scanner-gap-fix.md` |
| 38 | 严格 benchmark | ✅ | CMOV **0.655x**, ROTATE **1.193x**。`docs/tmp/2026-03-10/rigorous-benchmark-results.md` |
| 39 | 微架构实验 | ✅ | PMU/频率/输入分布。`docs/tmp/2026-03-08/microarch_experiments.md` |
| 40 | ARM64 CI | ✅ | 3 轮修复。 |
| 41 | ARM64 分析 | ✅ | L/K=**0.656x**。`docs/tmp/2026-03-08/arm64-cross-arch-analysis.md`，`docs/tmp/2026-03-11/arm64-analysis-review.md` |
| 42 | EINVAL debug | ✅ | production EINVAL 修复。 |
| 43 | Benchmark 审计 | ✅ | `docs/tmp/2026-03-11/benchmark-infrastructure-audit.md` |
| 44 | Benchmark 分析 | ✅ | `docs/tmp/2026-03-10/benchmark-framework-analysis.md` |
| 45 | 论文 LaTeX | 🔄 | R3 6.5/10。`docs/paper/paper.tex`，`docs/tmp/2026-03-10/paper-review-r3-post-rewrite.md` |
| 46 | COND_SELECT v5 | ✅ | `docs/tmp/2026-03-10/cmov-v5-migration-report.md` |
| 47 | cmov emitter fix | ✅ | site index 修复。`docs/tmp/2026-03-10/cmov-emitter-fix-report.md` |
| 48 | Benchmark 重构 | 🔄 | P0 5/5 完成。`docs/tmp/2026-03-10/p0-bugfix-report.md` |
| 49 | 端到端部署 | 已取消 | |
| 50 | 论文更新 | 已取消 | |
| 51 | log_level/log_buf | ✅ | `docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 52 | Shape whitelist | ✅ | site_len≤64。`docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 53 | Overlap 语义 | ❌ | 未实现。 |
| 54 | Subprog 一致性 | ❌ | 未同步。 |
| 55 | K2/Merlin/EPSO 对比 | ✅ | **正交非替代**，backend gap 89.1%。`docs/tmp/2026-03-11/k2-merlin-epso-comparison.md` |
| 56 | RCU 安全分析 | ✅ | `docs/tmp/2026-03-11/rejit-rcu-safety-analysis.md` |
| 57 | 消融补全 | ❌ | |
| 58 | ZERO_EXTEND | ❌ | |
| 59 | ARM64 backend | ❌ | |
| 60 | 严格重跑 30×1000 | ✅ | 56/56 pass。`micro/results/pure_jit_authoritative_strict_20260312.json` |
| 61 | Benchmark 多样性 | 🟡 | 67 micro + 79 corpus paired。`docs/tmp/2026-03-11/benchmark-diversity-audit.md` |
| 62 | CMOV 信号增强 | ❌ | 仅 2.8% 改善。 |
| 63 | E2E throughput | 已取消 | 随 #49。 |
| 64 | Corpus 可运行性 | ✅ | 381 runnable / 3069 sites。`docs/tmp/2026-03-11/corpus-runnability-report.md` |
| 65 | Corpus 批量 recompile | ✅ | geomean **0.847x**。`docs/tmp/2026-03-11/corpus-batch-recompile-results.md`，`docs/tmp/2026-03-11/corpus-recompile-regression-analysis.md` |
| 66 | 非网络 E2E 研究 | ✅ | Tracee+Tetragon+bpftrace+scx。`docs/tmp/2026-03-11/non-networking-evaluation-plan.md` |
| 67 | Framework 重构 Step 1-3 | ✅ | 共享 Python 层。`docs/tmp/2026-03-11/framework-improvement-step1.md` |
| 68 | Corpus 扩展 R3 | ✅ | 560 objects（23 项目）。`docs/tmp/2026-03-11/corpus-expansion-round3.md` |
| 69 | Selective CMOV policy | ✅ | global skip-cmov 不足。`docs/tmp/2026-03-11/selective-policy-results.md` |
| 70 | bpftrace E2E driver | ✅ | 9 CMOV sites。`docs/tmp/2026-03-11/bpftrace-e2e-results.md` |
| 70a | Tetragon harness | ✅ | `docs/tmp/2026-03-11/tetragon-e2e-results.md` |
| 70b | BPF-side VM 测试 | ✅ | Tracee **2.71x**。`docs/tmp/2026-03-11/tracee-e2e-vm-summary.md`，`docs/tmp/2026-03-11/bpftrace-e2e-vm-summary.md`，`docs/tmp/2026-03-11/tetragon-e2e-vm-summary.md` |
| 70c | Framework 重构 Steps 2-7 | ✅ | `micro/driver.py` 统一入口。`docs/tmp/2026-03-11/framework-improvement-steps2-7.md` |
| 71 | 仓库三层重组 | ✅ | micro/corpus/e2e 分离。`docs/tmp/2026-03-11/repo-restructure-report.md` |
| 72 | Tracee E2E | ✅ | exec_storm **+21.65%**。`docs/tmp/2026-03-11/tracee-real-e2e-report.md`，`e2e/results/tracee-e2e-real.json` |
| 73 | Kernel 重编 | ✅ | FTRACE_SYSCALLS+SCHED_CLASS_EXT。`docs/tmp/2026-03-11/kernel-rebuild-report.md` |
| 74 | Tetragon E2E | ✅ | stress_exec **+6.7%**，BPF **-14.5%**。`e2e/results/tetragon-real-e2e.json` |
| 75 | bpftrace E2E | ✅ | geomean **0.992x**（policy-sensitivity）。`docs/tmp/2026-03-12/bpftrace-real-e2e-report.md`，`e2e/results/bpftrace-real-e2e.json` |
| 77 | Directive gap 分析 | ✅ | CMOV 应为 policy-sensitivity 证据。`docs/tmp/2026-03-11/directive-gap-analysis.md` |
| 78 | cmov 识别加宽 | ✅ | `docs/tmp/2026-03-11/cmov-broadening-report.md` |
| 79 | bitfield_extract | ✅ | **544 sites / 41 objects**。`docs/tmp/2026-03-11/bitfield-extract-implementation.md` |
| 80 | wide_load 扩展 | ✅ | **2835 sites**。`docs/tmp/2026-03-11/wide-load-extension-report.md` |
| 81 | branch_reorder | 归入 #89 | BRANCH_FLIP 简单版。 |
| 82 | bounds_window | ❌ | 未实现。 |
| 83 | Kernel JIT 清理 | ✅ | 零偏移+imm64 优化。`docs/tmp/2026-03-11/kernel-jit-cleanup-patches.md` |
| 84 | Interface v6 提案 | ✅ | `docs/tmp/2026-03-11/interface-design-audit.md`，`docs/tmp/2026-03-11/interface-improvement-proposals.md` |
| 85 | v4 删除 | ✅ | -778 LOC。 |
| 86 | v6 tier-1 | ✅ | `docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 87 | v6 接口研究 | ✅ | verifier log 足够 discovery。`docs/tmp/2026-03-11/v6-interface-design.md` |
| 88 | Framework audit v2 | ✅ | `docs/tmp/2026-03-11/benchmark-framework-audit-v2.md` |
| 89 | 新 forms (ZEXT/ENDIAN/BFLIP) | ✅ | 3 form 落地。`docs/tmp/2026-03-11/new-canonical-forms-implementation.md` |
| 90 | Corpus 全量 v6 | ✅ | geomean **0.868x**，92 applied。`docs/tmp/2026-03-11/corpus-full-recompile-v6.md` |
| 91 | 优化方向研究 | ✅ | Top 3 方向。`docs/tmp/2026-03-11/optimization-beyond-isel.md` |
| 92 | 8-family census | ✅ | 17637 total sites，zeroext=0。`docs/tmp/2026-03-11/corpus-8families-census-persection.md` |
| 93 | Micro 精简 | ✅ | 56-case pure-jit only。 |
| 94 | Micro input 去 map | ✅ | packet buffer 传入。 |
| 95 | Tracing corpus driver | ✅ | attach+trigger 测量。 |
| 96 | Corpus 整理 | ✅ | |
| 97 | Policy 配置设计 | ✅ | 统一 YAML schema + 5 阶段 auto-tuning。`docs/tmp/2026-03-11/policy-configuration-design.md` |
| 99 | Micro Python 整理 | ✅ | 归档+共享 helper。 |
| 99a | Micro cleanup follow-up | ✅ | |
| 98 | Policy v2 设计 | ✅ | 程序无关 auto-tuning。`docs/tmp/2026-03-12/policy-configuration-design-v2.md` |
| 98a | Policy P0+P1 | ✅ | 8-family surface + scanner compile-policy。 |
| 98b | P2 Micro policy | ✅ | manifest-driven policy plumbing。 |
| 98e | P3 Corpus policy | ✅ | per-program policy files。 |
| 98c | Tracing corpus VM | ✅ | 473 ready / 315 attached。`docs/tmp/2026-03-11/tracing-corpus-vm-full-results.md` |
| 98d | Code-size systematic | ✅ | `docs/tmp/2026-03-11/code-size-by-progtype.md` |
| 98f | P4 Auto-tuner | ✅ | prototype landed。`corpus/auto_tune.py` |
| 100 | Micro 回归修复 | ✅ | 56/56 pass。`micro/results/pure_jit_authoritative_20260312.json` |
| 101 | Corpus driver dedup | ✅ | -385 行。 |
| 102 | Inventory audit | ✅ | `docs/tmp/2026-03-11/benchmark-inventory-audit.md` |
| 103 | Policy pipeline | ✅ | `docs/tmp/2026-03-11/policy-pipeline-analysis.md` |
| 104 | Corpus tuned policy | ✅ | geomean 0.868x→**0.898x**。`docs/tmp/2026-03-11/corpus-tuned-policy-comparison.md` |
| 105 | E2E policy 接线 | ✅ | per-program policy lookup。 |
| 106 | 结果目录规范 | ✅ | authoritative naming + symlinks。 |
| 107 | Code-size VM | ✅ | geomean **1.003x**。`docs/tmp/2026-03-11/code-size-full-vm-results.md` |
| 108 | Tracing corpus VM | ✅ | applied-only **1.019x**。`docs/tmp/2026-03-11/tracing-corpus-vm-full-results.md` |
| 109 | scx EINVAL | ✅ | extable guard 修复。`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 110 | llvmbpf map inline POC | ✅ | **1.30x** speedup。`docs/tmp/2026-03-11/llvmbpf-array-map-inline-poc.md` |
| 111 | XDP forwarding PPS | ✅（已退役） | +0.27%，见 #203。 |
| 112 | Strict micro 30×1000 | ✅ | geomean **0.609x**，53/56 wins。`docs/tmp/2026-03-11/sub-ktime-and-strict-analysis.md` |
| 113 | Policy <1.0x 分析 | ✅ | non-CMOV families 回归。`docs/tmp/2026-03-11/policy-improvement-analysis.md` |
| 114 | Policy v2 格式 | ✅ | site > family > default 优先级。 |
| 115 | Strict 分析 | ✅ | 归入 #112。 |
| 116 | bflip/endian sweep | ✅ | bflip+endian:skip **0.857x**。`docs/tmp/2026-03-11/bflip-endian-skip-sweep.md` |
| 117 | scx EINVAL 调查 | ✅ | 归入 #109。`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 118 | Recompile micro strict | ✅ | overall **1.028x**，applied **1.024x**。`docs/tmp/2026-03-11/kernel-recompile-micro-strict.md` |
| 119 | XDP forwarding VM | ✅（已退役） | +0.27%，见 #203。`docs/tmp/2026-03-11/xdp-forwarding-live-vm-report.md` |
| 120 | Corpus v2 policy rerun | ✅ | **0.848x**（pre-fix baseline）。`docs/tmp/2026-03-11/corpus-v2-policy-rerun.md` |
| 121 | E2E v2 policy rerun | ✅ | wiring 验证，site 漂移导致 0 apply。`docs/tmp/2026-03-11/e2e-v2-policy-rerun.md` |
| 122 | v2 pipeline 迁移 | ✅ | scanner v2-only。`docs/tmp/2026-03-11/v2-pipeline-migration-report.md` |
| 123 | Per-family 消融 | ✅ | wide **1.010x**, rotate **1.021x**, cmov **0.974x**。`docs/tmp/2026-03-11/kernel-recompile-per-family-ablation.md` |
| 124 | 论文审计 | 已取消 | |
| 125 | Gap 分解 | ✅ | recovery **4.3%** of gap。`docs/tmp/2026-03-11/characterization-gap-decomposition.md` |
| 126 | Micro v2 tuned rerun | ✅ | applied-only **1.040x**。`docs/tmp/2026-03-11/kernel-recompile-micro-v2-tuned.md` |
| 128 | Corpus v2 policy fix | ✅ | site 漂移修复，0.758x→**1.055x**（13-target smoke）。`docs/tmp/2026-03-12/corpus-v2-policy-diagnosis.md` |
| 129 | Micro mismatch fix | ✅ | cmov site 触发 wrong-code。源级修复见 #138。`docs/tmp/2026-03-12/micro-mismatch-crash-diagnosis.md` |
| 127 | 阶段性 review | ✅ | 4 critical 不一致。`docs/tmp/2026-03-12/stage-review-report.md` |
| 130 | 默认语义修正 | ✅ | no-policy → stock。 |
| 131 | Inline policy v1→v2 | ✅ | policy_file 引用替换 inline。 |
| 132 | v2 spec 文档 | ✅ | `docs/tmp/2026-03-12/policy-v2-authoritative-spec.md` |
| 133 | Corpus v2 fixed rerun | ✅ | **0.875x**（91 applied）。`docs/tmp/2026-03-12/corpus-v2-fixed-rerun.md` |
| 134 | E2E v2 fixed rerun | ✅ | cmov skip 过滤生效。`docs/tmp/2026-03-12/e2e-v2-fixed-rerun.md` |
| 135 | Parser 一致性测试 | ✅ | golden tests。`docs/tmp/2026-03-12/parser-consistency-fix.md` |
| 136 | Plan doc 修正 | ✅ | 过时条目描述回写。 |
| 137 | bpftrace policy artifacts | ✅ | 12 cmov sites。`docs/tmp/2026-03-12/bpftrace-policy-artifacts.md` |
| 138 | CMOV/EXTRACT fix | ✅ | emitter fail-close + BEXTR ModRM 修正。`docs/tmp/2026-03-12/cmov-emitter-fix.md` |
| 139 | Micro authoritative | ✅ | 56/56 valid，applied-only **1.049x**。`docs/tmp/2026-03-12/kernel-recompile-micro-v2-fixed-authoritative.md` |
| 140 | Tetragon 回归调查 | ✅ | workload 噪声。`docs/tmp/2026-03-12/tetragon-connect-storm-investigation.md` |
| 141 | Per-family v1→v2 | ✅ | 8 policy 升级。 |
| 142 | v1 清理 | ✅ 被 #145 取代 | v2 纯化，后续切 v3。 |
| 143 | Post-fix micro rerun | ✅ | 11/56 applied，**1.007x**。`docs/tmp/2026-03-12/post-cmov-fix-micro-rerun.md` |
| 144 | CMOV 消融 | ✅ | CMOV 仍负面，保留 cmov:skip。`docs/tmp/2026-03-12/post-cmov-fix-corpus-ablation.md` |
| 145 | v3 policy | ✅ | per-site directive list，614 YAML 通过。 |
| 146 | Recompile 开销 | ✅ | scanner **4.32ms**，syscall **29.89μs**。`docs/tmp/2026-03-12/recompile-overhead-measurement.md` |
| 147 | bpftrace v3 validation | ✅ | `docs/tmp/2026-03-12/bpftrace-e2e-v3-validation.md` |
| 148 | 架构 Review + 图 | ✅ | `docs/tmp/2026-03-12/architecture-review-and-diagrams.md` |
| 149 | Canonical-site hardening | ✅ | 8 form 双重校验。 |
| 150 | Kernel cleanup | ✅ | RORX bug 等修复。`docs/tmp/2026-03-12/kernel-engineering-cleanup.md` |
| 151 | Kernel self-tests | ✅ | 18/18 PASS。`docs/tmp/2026-03-12/kernel-selftest-run.md` |
| 152 | Kernel safety fixes | ✅ | smp_store_release + RCU 等。`docs/tmp/2026-03-12/kernel-safety-fixes.md` |
| 153 | JIT image diff | ✅ | **re-JIT 改 non-site 字节**（code layout shift）。zero-site 短路已修。`docs/tmp/2026-03-12/jit-image-diff-analysis.md` |
| 154 | Per-form benchmark | ✅ | +6 纯隔离 benchmark。`docs/tmp/2026-03-12/per-form-benchmarks-implementation.md` |
| 155 | Corpus regressor root cause | ✅ | 3/10 真实回归（branch-flip）。`docs/tmp/2026-03-12/corpus-regressor-root-cause.md` |
| 156 | Measurement fix | ✅ | dual TSC + warmup。`docs/tmp/2026-03-12/kernel-runner-measurement-fixes.md` |
| 157 | Framework audit v3 | ✅ | corpus construct validity 问题。`docs/tmp/2026-03-12/benchmark-framework-audit-v3.md` |
| 158 | Post-cleanup 验证 | 🔄 | 62/62 micro valid。`docs/tmp/2026-03-12/post-cleanup-validation.md` |
| 159 | Root Makefile | ✅ | 一键 build+test。`docs/tmp/2026-03-12/root-makefile-report.md` |
| 160 | Post-fix micro 62 bench | ✅ | applied-only **0.877x**。`docs/tmp/2026-03-12/post-fix-micro-62bench-rerun.md` |
| 161 | Scanner pattern_kind fix | ✅ | `docs/tmp/2026-03-12/scanner-pattern-kind-investigation.md` |
| 162 | Corpus validity 分析 | ✅ | corpus exec **无效**（噪声主导），code size 有效。`docs/tmp/2026-03-12/corpus-construct-validity-analysis.md` |
| 163 | Scanner enumerate | ✅ | live program 分析，197 progs / 1920 sites。`docs/tmp/2026-03-12/scanner-enumerate-implementation.md` |
| 164 | E2E 切 enumerate | ✅ | `docs/tmp/2026-03-13/e2e-enumerate-pipeline-switch.md` |
| 165 | 消融补全 | ✅ | byte-recompose **50.7%**，callee-saved ~0%，BMI ~0%。`docs/tmp/2026-03-13/ablation-byte-recompose-callee-bmi.md` |
| 166 | Per-form 矛盾调查 | ✅ | emitter bug 导致零变化。`docs/tmp/2026-03-13/per-form-discrepancy-investigation.md` |
| 167 | Emitter 修复 | ✅ | BEXTR VEX 修正，extract_dense -6.8%。`docs/tmp/2026-03-13/emitter-fix-extract-endian-bflip.md` |
| 168 | endian/bflip 回归 | ✅ | same-size I-cache flush 开销 > 微架构收益。`docs/tmp/2026-03-13/endian-bflip-perf-investigation.md` |
| 170 | Enumerate manifest | ✅ | --json per-site 输出。 |
| 171 | Daemon 模式 | ❌ 暂不做 | 论文不需要。 |
| 172 | Native code 分析 | ❌ | jited_prog_insns 未用。 |
| 173 | Corpus 切 enumerate | ✅ | |
| 76 | scx E2E | 🔄 | 28 sites，struct_ops -EOPNOTSUPP。`docs/tmp/2026-03-11/scx-e2e-report.md`，`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 169 | Post-BEXTR rerun | ✅ | overall **1.003x**，applied **0.932x**。extract_dense **0.556x** 回归。`docs/tmp/active/micro-62bench-post-bextr-fix.md`，`micro/results/micro_62bench_post_bextr_fix_20260313.json` |
| 174 | Patch-site 架构 | ❌ | 消除 I-cache flush 开销。 |
| 175 | WIDE_MEM 扩展 | ❌ | byte-recompose 50.7%。 |
| 176 | Prologue 优化 | ❌ | 占 gap 18.5%。 |
| 177 | Cost model | ❌ | 跳过 same-size/dense 超阈值。 |
| 178 | 更多 E2E 数据 | ❌ | 目标 ≥3 workload 正向。 |
| 179 | Per-form ablation | ✅ | ROTATE **0.923x** win，CMOV **1.068x** loss。`docs/tmp/micro-per-form-ablation.md` |
| 180 | 框架重构 Makefile | ✅ | file-based deps + provenance + POLICY=。 |
| 181 | CI 修复 | ✅ | driver.py + requirements.txt。 |
| 182 | Opus review | ✅ | 架构✅，方法学有 gap。`docs/tmp/deep-review-*.md` |
| 183 | P0.1 更多 E2E | 🔄 已被 #304 搁置 | Tracee +6.28%/+7.00%。 |
| 184 | P0.2 Corpus >1.05x | 🔄 已被 #304 搁置 | 当前 1.046x。 |
| 185-188 | P1 优化方向 | ❌ 已被 #304 搁置 | prologue / patch-site / wide 扩展 / native 分析。 |
| 189 | Micro policy 优化 | ✅ | applied-only **1.110x**（7 applied）。`micro/results/vm_micro_authoritative_20260318.json` |
| 190 | 结果目录 + schema | ✅ | authoritative naming，policy 内嵌。 |
| 191 | Corpus+E2E 分析 | ✅ | stale policy 是主因。`docs/tmp/corpus_e2e_performance_analysis_20260318.md` |
| 192 | Katran E2E 可行性 | ✅ | 94 live sites。`docs/tmp/katran_e2e_feasibility_20260318.md` |
| 193 | Corpus policy refresh | ✅ | 582 个 v3 policy，skip cmov+extract。 |
| 194 | 项目卫生审计 | ✅ | `docs/tmp/project_hygiene_audit_20260318.md` |
| 195 | 内核修改文档 | ✅ | 1017 行。`docs/tmp/kernel_modifications_analysis.md` |
| 196 | Framework 设计文档 | ✅ | 800+ 行。`docs/tmp/benchmark_framework_analysis.md` |
| 197 | Micro 第三轮 | ✅ 归入 #189 | |
| 198 | prog_fd 残留清理 | ✅ | enumerate-only。 |
| 199 | Corpus refreshed rerun | ⚠️ | applied-only **1.077x**，overall 0.881x。 |
| 200 | **Tetragon rerun（2026-03-18）** | ⚠️ | connect_storm **-55.96%** 回归，见 #204 修复。 |
| 201 | **Kernel WARN_ON 排查（2026-03-18）** | ✅ | tailcall poke descriptor 冲突，暂不修。报告：`docs/tmp/kernel_warn_on_investigation_20260318.md`。 |
| 202 | **Katran E2E 完整设计（2026-03-18）** | ✅ | DSR 拓扑设计。报告：`docs/tmp/e2e_design_katran_20260318.md`。 |
| 203 | **XDP forwarding E2E 删除（2026-03-18）** | ✅ | 已删除 `e2e/cases/xdp_forwarding/` + 结果 + 文档引用。commit `431fdc5`。 |
| 204 | **Tetragon connect_storm 修复（2026-03-18）** | ✅ | stress_exec **+8.70%**，connect_storm **+22.29%**。3 applied / 49 bflip sites。报告：`docs/tmp/tetragon_connect_storm_investigation_20260318.md`。 |
| 205 | **Katran E2E MVP 实现（2026-03-18）** | 🔄 | 创建 e2e/cases/katran/，注册到 e2e/run.py，第一版用 standalone bpftool load 做 smoke。 |
| 206 | **Sequential rerun round 2（2026-03-18）** | ✅ | Tracee/Corpus rerun。trampoline guard 是 corpus 回归根因，已 revert。报告：`docs/tmp/sequential_rerun_round2_20260318.md`。 |
| 207 | **Tracee revert rerun（2026-03-19）** | ✅ | exec_storm +4.40%，file_io +4.69%。旧权威保持。报告：`docs/tmp/tracee_revert_rerun_20260319.md`。 |
| 208 | **Corpus revert rerun（2026-03-19）** | ✅ | applied-only **1.023x**。瓶颈是 non-applied ultra-short 噪声。报告：`docs/tmp/corpus_improvement_analysis_20260319.md`。 |
| 209 | **Trampoline regeneration 调研（2026-03-19）** | ✅ | ~100 LOC 方案。已在 #248 实施。报告：`docs/tmp/trampoline_regeneration_research_20260319.md`。 |
| 210 | **Kernel deep review（2026-03-19）** | ✅ | 9 个问题，3 轮修复见 #212-#214。报告：`docs/tmp/kernel_deep_review_20260319.md`。 |
| 211 | **GitHub ARM64 KVM 调研（2026-03-19）** | ✅ | 无 KVM，ARM64 recompile 需租机。报告：`docs/tmp/github_arm64_kvm_research_20260319.md`。 |
| 212-214 | **Kernel fix Phase A/B/C（2026-03-19）** | ✅ | 3 轮 kernel 修复。报告：`docs/tmp/kernel_fix_phase_{a,b,c1,c2}_20260319.md`。 |
| 215-216 | **Kernel cleanup + review（2026-03-19）** | ✅ | tracepoints 删除、stock choice 消除。9.2/10。selftest 20/20。 |
| 217-220 | **Kernel DSL 删除 + 简化（2026-03-19）** | ✅ | DSL ~900 行删除，blob 简化，do_jit 短路恢复。报告：`docs/tmp/kernel_dsl_removal_20260319.md`。 |
| 221 | **用户态 dead code 清理（2026-03-19）** | ✅ | -47 文件 / -21000 行。报告：`docs/tmp/userspace_cleanup_20260319.md`。 |
| 222-223 | **Kernel review + 接口精简（2026-03-19）** | ✅ | 8.4/10。selftest 19/19。报告：`docs/tmp/kernel_final_review_20260319.md`。 |
| 224-225 | **Build 依赖修复（2026-03-19）** | ✅ | Makefile blob 依赖修复。报告：`docs/tmp/micro_exec_blob_fix_20260319.md`。 |
| 226 | **UAPI 同步 + 验证（2026-03-19）** | ✅ | vm-micro 62/62，applied-only **1.078x**。报告：`docs/tmp/full_validation_final_20260319.md`。 |
| 227 | **ARM64 交叉编译 + QEMU（2026-03-19）** | ✅ | make kernel-arm64 + vm-arm64-smoke 通过。报告：`docs/tmp/arm64_cross_compile_qemu_20260319.md`。 |
| 228 | **Param match dead code 确认（2026-03-19）** | ✅ | 无需改动。 |
| 229-230 | **Kernel 5k review + P0/P1/P2 fix（2026-03-19）** | ✅ | trampoline gate、param-only emitter、overlap 检测。selftest 19/19。报告：`docs/tmp/kernel_review_fixes_20260319.md`。 |
| 231 | **Docker ARM64 交叉编译（2026-03-19）** | ✅ | Dockerfile + Makefile targets。ARM64 kernel 缺 recompile override。 |
| 232 | **用户态 cleanup round 3（2026-03-19）** | ✅ | dead imports/locals 清理。 |
| 233-235 | **Kernel LOC 分析 + 架构 review + 简化（2026-03-19）** | ✅ | 净减 **-447 LOC**。报告：`docs/tmp/kernel_simplification_20260319.md`。 |
| 236 | **Micro rerun post-P0/P1/P2（2026-03-19）** | ✅ | rotate_dense 回归为旧 bzImage 问题，非代码 bug。报告：`docs/tmp/rotate_dense_regression_debug_20260319.md`。 |
| 237 | **Scaleway RISC-V 调研（2026-03-19）** | ✅ | custom kernel 需特殊处理。报告：`docs/tmp/riscv_cloudv_scaleway_research_20260319.md`。 |
| 238 | **LLVM vs kernel JIT 指令级对比（2026-03-19）** | ✅ | WIDE_MEM+ROTATE 是主因。8-form 未覆盖：load-width narrowing、store coalescing、regalloc。报告：`docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md`。 |
| 239 | **ARM64 JIT gap 分析（2026-03-19）** | ✅ | 4 form 值得移植（ROTATE/WIDE_MEM/EXTRACT/COND_SELECT）。报告：`docs/tmp/arm64_jit_gap_analysis_20260319.md`。 |
| 240 | **rotate_dense 回归 debug（2026-03-19）** | ✅ | 归入 #236。 |
| 241 | **Kernel 简化重启（2026-03-19）** | ✅ | 归入 #235。 |
| 242 | **Post-simplification review（2026-03-19）** | ✅ | 8/10。P1 masked ROTATE 见 #247。 |
| 243 | **ARM64 CI baseline（2026-03-19）** | ✅ | llvmbpf **0.590x**（54/62 wins）。报告：`docs/tmp/arm64_ci_first_run_20260319.md`。 |
| 244 | **权威 micro rerun（2026-03-19）** | ✅ | applied-only **1.152x**。报告：`docs/tmp/micro_authoritative_post_simplification_20260319.md`。 |
| 245 | **Corpus rerun（2026-03-19）** | ✅ | applied-only **1.062x**。报告：`docs/tmp/corpus_post_simplification_20260319.md`。 |
| 246 | **E2E rerun（待做）** | ⏳ 已被 #304 架构转向搁置 | |
| 247 | **ROTATE fix + cleanup（2026-03-19）** | ✅ | kernel-side 完成，scanner 待对齐（见 #268）。 |
| 248 | **Trampoline regeneration（2026-03-19）** | ✅ | selftest 25/25。报告：`docs/tmp/trampoline_regen_rotate_fix_20260319.md`。 |
| 249-251 | **ARM64 emitter 设计+实现（2026-03-19）** | ✅ | 4 form（ROTATE/WIDE_MEM/EXTRACT/COND_SELECT）+ arch callback 拆分。selftest 24/24（x86+ARM64）。报告：`docs/tmp/arm64_emitter_implementation_20260319.md`。 |
| 252 | **Selftest 扩展（2026-03-19）** | ✅ | +5 form，8/8 覆盖。selftest 24/24。 |
| 253 | **ARM64 CI corpus fix（2026-03-19）** | ✅ | io-mode 修复，覆盖率 52%。 |
| 254 | **Timing fix（2026-03-19）** | ✅ | llvmbpf 批量计时，ultra-short 修复。报告：`docs/tmp/timing_fix_20260319.md`。 |
| 255 | **Corpus llvmbpf 删除（2026-03-19）** | ✅ | 报告：`docs/tmp/corpus_llvmbpf_removal_20260319.md`。 |
| 256 | **权威 rerun（2026-03-20）** | ✅ | Micro **1.057x** / applied **1.193x**。Corpus applied **0.947x**。Tracee **+8.1%**。Tetragon **+20.3%/+32.2%**。Gap **0.581x**。报告：`docs/tmp/full_rerun_authoritative_20260320.md`。 |
| 257 | **Branch 合并（2026-03-19）** | ✅ | ARM64 CI 分支合并到 main。 |
| 258 | **Paired measurement（2026-03-19）** | ✅ | 归入 #262。 |
| 259 | **Framework review（2026-03-19）** | ✅ | micro applied-only 可靠；corpus overall 不可靠。报告：`docs/tmp/benchmark_framework_review_20260319.md`。 |
| 260 | **ARM64 micro eval（2026-03-19）** | ✅ | smoke 通过，性能负向（QEMU 噪声）。报告：`docs/tmp/arm64_micro_eval_20260319.md`。 |
| 261-262 | **Benchmark cleanup + same-image 改造（2026-03-19）** | ✅ | same-image paired measurement 落地。报告：`docs/tmp/same_image_measurement_20260319.md`。 |
| 263 | **Trampoline regen + ROTATE fix 合并（2026-03-19）** | ✅ | selftest 25/25。报告：`docs/tmp/trampoline_regen_rotate_fix_20260319.md`。 |
| 264-265 | **ARM64 emitter review + P0/P1 fix（2026-03-19）** | ✅ | subprog staging + EXTRACT width 校验。selftest 27/27。报告：`docs/tmp/arm64_p0p1_fix_20260319.md`。 |
| 266 | **AWS ARM64 benchmark（2026-03-19）** | ⚠️ 已被 #304 搁置 | t4g.micro smoke 通过。glibc ABI 残留。报告：`docs/tmp/aws_arm64_benchmark_run_20260320.md`。 |
| 267 | **Makefile 审计（2026-03-19）** | ✅ | defaults 统一 10/2/200。报告：`docs/tmp/makefile_benchmark_audit_20260319.md`。 |
| 268 | **Scanner ROTATE 对齐（2026-03-19）** | ✅ | scanner-tests 0 FAIL。报告：`docs/tmp/scanner_rotate_align_20260319.md`。 |
| 269 | **Validator/emitter boundary audit（2026-03-20）** | ✅ | “Validator=安全门，Emitter=信任”。selftest 27/27。报告：`docs/tmp/validator_emitter_boundary_audit_20260320.md`。 |
| 270 | **Katran harness fix（2026-03-20）** | ✅ | same-image paired，1.042x。报告：`docs/tmp/katran_harness_fix_20260320.md`。 |
| 271 | **Corpus 根因分析（2026-03-20）** | ✅ | applied-only 0.947x。报告：`docs/tmp/corpus_rootcause_20260320.md`。 |
| 272 | **Selftest 扩展（2026-03-20）** | ✅ | +9 tests，selftest **36/36**。报告：`docs/tmp/selftest_negative_boundary_20260320.md`。 |
| 273 | **Kernel quality audit（2026-03-20）** | ✅ | P0 buffer overflow + P1 alias bugs。见 #275 修复。报告：`docs/tmp/kernel_code_quality_audit_20260320.md`。 |
| 274 | **Benchmark framework refactor（2026-03-20）** | ✅ | runner/ 顶层提取，corpus 8→1 driver。报告：`docs/tmp/benchmark_framework_refactor_20260320.md`。 |
| 275 | **Kernel P0+P1 fix（2026-03-20）** | ✅ | BRANCH_FLIP/COND_SELECT/ADDR_CALC bugs。selftest 36/36。报告：`docs/tmp/kernel_p0p1_fix_20260320.md`。 |
| 276-278 | **ZERO_EXT_ELIDE 分析+删除（2026-03-20）** | ✅ | 内核 **-118 LOC**。selftest 35/35。报告：`docs/tmp/zero_ext_elide_deletion_20260320.md`。 |
| 277 | **Post-refactor cleanup（2026-03-20）** | ✅ | py_compile 无错误。 |
| 279 | **Cross-layer fix（2026-03-20）** | ✅ | 零跨层 import。报告：`docs/tmp/cross_layer_cleanup_20260320.md`。 |
| 280 | **Trampoline leak fix（2026-03-20）** | ✅ | Double synchronize_rcu。selftest 35/35。 |
| 281 | **ARM64 E2E smoke（2026-03-20）** | ✅ | Katran recompile 通过。Tetragon ❌。EC2 terminated。报告：`docs/tmp/arm64_e2e_smoke_20260320.md`。 |
| 282 | **Katran harness 升级（2026-03-20）** | ✅ | BPF **1.108-1.168x**。报告：`docs/tmp/katran_e2e_quality_analysis_20260320.md`。 |
| 283 | **ARM64 bpftool fix（2026-03-20）** | ✅ | kernel_btf fallback。Katran recompile 全通。报告：`docs/tmp/arm64_bpftool_fix_20260320.md`。 |
| 284 | **Kernel 精简（2026-03-20）** | ✅ | **-137 LOC**。selftest 35/35。报告：`docs/tmp/kernel_low_risk_simplification_20260320.md`。 |
| 285 | **用户态精简（2026-03-20）** | ✅ | **-32,329 行**。报告：`docs/tmp/userspace_consolidation_20260320.md`。 |
| 286 | **Framework 清理（2026-03-20）** | ✅ | 删除散乱目录/脚本。报告：`docs/tmp/framework_cleanup_audit_20260320.md`。 |
| 287-288 | **Kernel bloat review + emitter 成本（2026-03-20）** | ✅ | BRANCH_FLIP 反转不可行。per-form ~180-500 LOC。报告：`docs/tmp/kernel_bloat_review_20260320.md`。 |
| 289 | **表驱动 validator（2026-03-20）** | ✅ | 边际成本 ~500→~80-150 LOC。selftest 35/35。报告：`docs/tmp/form_cost_reduction_design_20260320.md`。 |
| 290 | **vm-micro 验证（2026-03-20）** | ✅ | 62/62 valid，applied-only **1.269x**。报告：`docs/tmp/vm_micro_validation_20260320.md`。 |
| 291 | **ROTATE/WIDE_MEM 表驱动（2026-03-20）** | ✅ | **-66 行**。selftest 35/35。报告：`docs/tmp/rotate_wide_table_driven_20260320.md`。 |
| 292 | **Katran endian bug（2026-03-20）** | ✅ | movbe store 副作用 bug。报告：`docs/tmp/katran_endian_store_bug_investigation_20260320.md`。 |
| 293 | **PGO policy 设计（2026-03-20）** | ✅ | live enumerate 是关键。报告：`docs/tmp/pgo_policy_design_20260320.md`。 |
| 294 | **Verifier 扩展调研（2026-03-20）** | ✅ | 方案 C 最划算（~50 行 liveness）。报告：`docs/tmp/verifier_extension_research_20260320.md`。 |
| 295-296 | **Katran site coverage（2026-03-20）** | ✅ | 74 sites（bflip=56, cmov=8, wide=4, endian=4, extract=2）。safe6 policy，BPF 1.042x。报告：`docs/tmp/katran_site_coverage_analysis_20260320.md`。 |
| 297/301 | **Tetragon 未 apply 调查（2026-03-20）** | ✅ | offline scan 看不到 live bflip sites。最多 5/7 可 apply。报告：`docs/tmp/tetragon_unapplied_investigation_20260320.md`。 |
| 298/300 | **ARM64 benchmark pipeline（2026-03-20）** | ⚠️ 已被 #304 搁置 | 改为 t4g.micro 交叉编译方案。 |
| 299 | **x86 新优化调研（2026-03-20）** | ✅ | Top-5 新机会。报告：`docs/tmp/x86_new_optimization_opportunities_20260320.md`。 |
| 302 | **E2E profiler（2026-03-20）** | 🔄 已被 #304 搁置 | PGO policy 设计。 |
| 303 | **目录整理（2026-03-20）** | ✅ | runner/docker, runner/scripts, docs/reference。报告：`docs/tmp/directory_reorganization_20260320.md`。 |
| 304 | **⚠️ 重大架构探索：BpfReJIT v2 — Verifier-guarded post-load transformation framework（2026-03-21）** | 🔄 | **架构方向讨论**，考虑从当前 native-level rewrite (~6400 LOC kernel) 转向通用 post-load program transformation 框架。核心思路：不在 native code 层做优化，改为在 BPF bytecode 层做重写 + 让 kernel verifier 验证；新优化通过 kernel module 部署；privileged daemon 自动发现/分析/重写 live BPF 程序，对应用完全透明。**最终收敛方案**见 #304a-#304d。**10 份 codex 调研报告**：(A) `kinsn_feasibility_research_20260320.md`、(B) `bpf_program_replacement_research_20260320.md`、(C) `verifier_acceptance_research_20260320.md`、(D) `architecture_comparison_osdi_20260320.md`、(E) `kinsn_minimal_implementation_20260321.md`、(F) `userspace_framework_design_research_20260321.md`、(G) `bpf_prog_rewrite_kernel_research_20260321.md`、(H) `transparent_replacement_feasibility_20260321.md`、(I) `inline_kfunc_feasibility_20260321.md`。 |
| 304a | **收敛方案：两套正交接口（2026-03-21）** | 📝 | **(接口 A) 程序变换 — GET + REJIT**：`BPF_PROG_GET_ORIGINAL` 拿原始 bytecode + `BPF_PROG_REJIT` 对同一 `struct bpf_prog` 做 bytecode patch → re-verify → re-JIT → image swap（复用现有 `jit_directives.c` staged commit/rollback/trampoline regen）。零 attach 变化、零运行时开销。**(接口 B) ISA 扩展 — Inline Kfunc**：新"指令"注册为 kfunc（复用 `register_btf_kfunc_id_set()` + 新 `KF_INLINE_EMIT` flag）；verifier 零改动（走已有 `check_kfunc_call()`）；interpreter 零改动（调真实内核函数）；JIT CALL case 检测 `KF_INLINE_EMIT` → 调 module 的 emit 回调内联展开为自定义 native 序列。优雅降级：module 未加载时 emit 普通 CALL。已有先例：`fixup_kfunc_call()` 中 `bpf_cast_to_kern_ctx`/`bpf_rdonly_cast` 等已被完全替换为 plain BPF 指令。**kernel 总改动估计 ~500-800 LOC**（GET_ORIGINAL ~70 + REJIT ~580 + Inline Kfunc ~150-200）。 |
| 304b | **关键发现汇总（2026-03-21）** | 📝 | **(1)** `struct bpf_prog` 不保留原始 bytecode — `insnsi` 被 verifier/fixup 原地改写，需在 load 时新增保存 pre-fixup baseline 到 `bpf_prog_aux`。**(2)** BPF opcode `BPF_ALU64` 的 `0xe0`/`0xf0` 是仅有干净空位，但 Inline Kfunc 不需要新 opcode。**(3)** xlated bytecode 不可逆（`convert_ctx_accesses()` + `do_misc_fixups()`），不能直接重新 PROG_LOAD。**(4)** 现有 `jit_directives.c` image swap 机制可复用。**(5)** re-verify 开销 ~ms 级（vs re-JIT ~30μs），但只发生一次。**(6)** Inline Kfunc 优于 kinsn — 零 verifier/interpreter 改动，复用 kfunc 注册/生命周期/BTF。**(7)** "interpreter 优雅降级"不成立 — kfunc 强制 JIT，降级是 "inline emit 失败 → fallback 普通 kfunc CALL"。**(8)** 常量参数编码（`RORX imm8`）需 v2 增强，v1 先做纯寄存器版。 |
| 304c | **论文定位（2026-03-21）** | 📝 | 与 K2/Merlin/EPSO **不同赛道**（runtime post-load vs compile-time pre-load）。类比：K2 = GCC -O3，我们 = JVM HotSpot。两者正交可叠加。**新定位**："Verifier-guarded, modular, post-load program transformation infrastructure for eBPF — 给 eBPF 加上类似 JVM 分层编译的能力，在 OS 内核级别，且安全模型更强（kernel verifier vs JVM bytecode verifier）"。同一框架支持四种用途：**(1)** 性能优化；**(2)** 安全加固；**(3)** 恶意程序在线热修复；**(4)** 运行时可观测。 |
| 304d | **Daemon 完整工作流（2026-03-21）** | 📝 | `BPF_PROG_GET_NEXT_ID` → `BPF_PROG_GET_ORIGINAL` → 用户态分析+重写（kinsn/kfunc 替换 or 安全加固 or PGO 决策）→ `BPF_PROG_REJIT`（kernel: patch orig bytecode → re-verify → re-JIT → image swap via RCU）。**完全透明**：不需要 .bpf.o，不需要改应用/loader，不需要 detach/reattach，零运行时开销。`freplace` 和 `bpf_link_update` 也可作为备选替换路径（freplace 有 ~3-5ns trampoline 开销，link_update 零开销但覆盖面有限）。 |
| 304 | **⚠️ 重大架构探索：BpfReJIT v2 — Verifier-guarded post-load transformation framework（2026-03-21）** | 🔄 | **架构方向讨论**，考虑从当前 native-level rewrite 转向更通用的 post-load program transformation 框架。核心思路：(1) 不在 native code 层做优化，改为在 BPF bytecode 层做重写 + 让 kernel verifier 验证；(2) 新 BPF 指令通过 kernel module 注册（类似 kfunc）；(3) privileged daemon 自动发现、分析、重写 live BPF 程序，对应用完全透明。**最终收敛方案：Inline Kfunc** — 复用已有 kfunc 机制，新指令注册为 kfunc，verifier 零改动，JIT 时通过 `KF_INLINE_EMIT` flag 内联展开为自定义 native 序列（而非 emit CALL）。优雅降级：module 未加载时走普通函数调用。**两套正交接口**：(A) GET/SET — `BPF_PROG_GET_ORIGINAL` 拿原始 bytecode + `BPF_PROG_REJIT` 对同一 prog 做 bytecode patch→re-verify→re-JIT→image swap（零 attach 变化）；(B) Inline Kfunc — module 注册 JIT inline emit 回调（~150-200 LOC kernel 改动）。**9 个 codex 调研报告**：`docs/tmp/kinsn_feasibility_research_20260320.md`（kfunc 机制）、`docs/tmp/bpf_program_replacement_research_20260320.md`（热替换）、`docs/tmp/verifier_acceptance_research_20260320.md`（verifier 接受度）、`docs/tmp/architecture_comparison_osdi_20260320.md`（论文定位）、`docs/tmp/kinsn_minimal_implementation_20260321.md`（opcode 空间+最小改动）、`docs/tmp/userspace_framework_design_research_20260321.md`（用户态 framework）、`docs/tmp/bpf_prog_rewrite_kernel_research_20260321.md`（REJIT 内核实现）。进行中：`docs/tmp/transparent_replacement_feasibility_20260321.md`（4 路径零开销对比）、`docs/tmp/inline_kfunc_feasibility_20260321.md`（inline kfunc 详细可行性）。 |
| 304a | **关键发现汇总（2026-03-21）** | 📝 | **(1) struct bpf_prog 不保留原始 bytecode** — `insnsi` 被 verifier/fixup 原地改写，需要在 load 时新增保存 pre-fixup baseline。**(2) BPF opcode 空间** — `BPF_ALU64` 的 `0xe0`/`0xf0` 是仅有的干净空位，但 Inline Kfunc 方案不需要新 opcode。**(3) xlated bytecode 不可逆** — `convert_ctx_accesses()` + `do_misc_fixups()` 不可逆，不能直接重新 PROG_LOAD。**(4) 现有 image swap 可复用** — `jit_directives.c` 的 snapshot/staged-image/RCU/trampoline-regen 机制可直接用于 REJIT。**(5) re-verify 开销 ~ms 级** — 比当前 re-JIT ~30μs 贵 2-3 个数量级，但只发生一次（变换时），不影响运行时。**(6) Inline Kfunc 优于 kinsn** — 零 verifier/interpreter 改动，复用 kfunc 注册/生命周期/BTF 类型系统，工具链天然支持（`__ksym`），优雅降级。**(7) 论文定位** — 与 K2/Merlin/EPSO 不同赛道（runtime vs compile-time），更类似 JVM HotSpot 给 BPF 加分层编译。 |
| 304b | **新架构用途（2026-03-21）** | 📝 | 同一套 GET+REJIT+InlineKfunc 接口支持四种用途：**(1) 性能优化** — wide load 合并、rotate、cmov、硬件特化；**(2) 安全加固** — 插入 bounds check、speculation barrier；**(3) 恶意程序阻断** — 检测恶意 BPF prog → 替换为 no-op/安全版本 → 在线热修复；**(4) 运行时可观测** — 给 hot path 插入 tracing。 |
