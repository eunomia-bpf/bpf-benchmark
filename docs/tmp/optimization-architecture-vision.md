# bpfopt 架构演化路线图与学术贡献潜力

Date: 2026-05-10

## 1. 现状定位

bpfopt v3 是**最原始的 bytecode-rewriting 框架**：

```
stdin Vec<bpf_insn> → 13 个 pass 串行 (各自 scan loop + RewritePlan emit) → stdout Vec<bpf_insn>
```

**核心特征**：
- 唯一 IR 是 `Vec<bpf_insn>` (linear PC-indexed)
- 每 pass 自己写 scan loop + emit
- 分支用 PC offset 表达 → 任何 insn 长度变化都需 `addr_map` 重算
- liveness/use-def 每 pass 现算（cached in AnalysisCache）
- DCE = 找 dead def 删 def
- 没有 SSA、没有 use-def edges、没有 BB graph 作为一等公民
- pass ordering 靠经验编排
- 正确性靠 kernel verifier 兜底

**痛点（来自 P1-E deep review 9 重复 + 14 算法缺陷 + 当前 OTEL dce regression）**：
1. 13 pass 都重写 scan loop（重复 1）
2. 5 处重写 branch fixup（重复 2，缺陷-1 i16 截断 bug 源）
3. 多处重写 reg use/def 小数据流（重复 3）
4. dce 走 liveness 不知道 verifier 类型 → over-elimination 产 verifier-rejected bytecode
5. pass ordering 顺序很 fragile（rotate before/after const_prop？）
6. ~10000 LOC 总量，平均每 pass 500 LOC

## 2. 现代编译器优化框架对比

### 2.1 SSA-based IR (LLVM IR / GCC GIMPLE / Cranelift CLIF)
- Single Static Assignment：每个值唯一定义点 + φ 函数
- **use-def 是 IR 边而不是分析结果** → DCE = "use count == 0 → 删"，极简
- 分支引用 BB ID 不用 PC → addr_map 概念不存在
- 优化是 IR pattern → IR pattern transform
- LLVM 50+ scalar pass，每个 ~200 LOC

### 2.2 Pattern DSL (LLVM TableGen / MLIR DRR / Cranelift ISLE)
- 优化用**声明式**：`(add x 0) → x`、`(or (shl x c) (lshr x (sub w c))) → (rotl x c)`
- TableGen 自动生成 scan + emit 代码
- 每条 rule 5-10 行
- 编译期检查 pattern overlap、coverage

### 2.3 e-graph + Equality Saturation (egg crate, Cranelift egraph backend)
- 同时维护**所有等价形式**而不是 commit 一种
- 累积所有 alternatives，最后用 cost function 提取最优
- **彻底消灭 pass ordering 问题**
- Cranelift 已经走这条路

### 2.4 MLIR (Multi-Level IR)
- 多 dialect：高层 → 低层
- 每 dialect 自己 ops + lowering pattern
- 适合"kop-class" target-specific 操作

### 2.5 Verified compiler (CompCert / VeRiSafe)
- 每个 transform 形式化证明 source ≡ target
- 修 bug = 改证明
- 我们目前靠 kernel verifier 兜底，等于"transform 没证 + 后置 check"

## 3. 演化路线图

### Phase 1 (本月)：稳定当前架构 + 修核心 bug

- 完成 P1-A/B/C/G 系列（已大部分完成）
- 修 OTEL dce regression（P1-F invest 中 → fix codex）
- 修 P1-G review 6 个 P1 violations（P1-H fix codex 进行中）
- 验证：full corpus 7 apps OK + apply 数恢复到 5/7 baseline 水平

**没这步后面都白做**——架构混乱时上层重构会 thrash。

### Phase 2 (下月)：方案 A 模式 DSL

```rust
pass! {
    name: "rotate",
    pattern: ALU64_REG(SHL, dst, val, sh) | ALU64_REG(LSR, dst, val, sub_imm) | OR(dst, dst, dst),
    require: liveness(dst).dead_after(),
    emit: call_kop("bpf_rotate64", dst, val, sh),
}
```

**实现**：proc-macro ~500 LOC，编译时展开成 scan + emit + addr_map + BTF remap
**收益**：7 个 kop 类 pass 各从 ~500 LOC 缩到 ~30 LOC = **省 ~3000 LOC**
**正确性**：scan/fixup 集中实现一次，pattern 错了编译期就报
**扩展性**：加新 kop 写 5-10 行 pattern
**风险**：低（不动 IR，emit 路径不变）

### Phase 3 (再下月)：方案 B BB + use-def IR

```rust
struct BbProgram {
    blocks: Vec<BasicBlock>,
    edges: Vec<(BlockId, BlockId)>,
    insns: Vec<Inst>,
    use_def: Vec<UseDefEdge>,
}
```

每 pass 入口把 `Vec<BpfInsn>` 升级到 BB graph + use-def edges，退出时 lower 回 bytecode。

**收益**：
- DCE 缩到 ~30 行（删 use_count=0）
- branch fixup 消失（用 BlockId）
- liveness 自动在 IR 边上
- 大多 pass 缩 50-80%
- **整体可能省 -3000~-5000 LOC**

**成本**：~1500 LOC builder/lowerer 一次性投入 + 13 pass 渐进 port
**风险**：中（BPF verifier 严格，lowering 出来的 bytecode 必须严格符合 verifier 喜好）

### Phase 4 (paper 之后)：方案 C e-graph

把所有 bytecode → e-graph，所有 pass = rewrite rule，最后 extract。

**收益**：
- 整个 bpfopt ~ 2000 LOC 总量
- 真正解 pass ordering 问题
- 可数学证明等价性

**成本**：1-2 月研究投入（kfunc call、map_lookup、verifier types 怎么建模）
**学术潜力**：高（首个 e-graph BPF optimizer）

### Phase 5 (远期)：Verified rewriting

每 rewrite 形式化证明等价。3-6 月学术级投入。

## 4. 学术创新与社区贡献潜力

### 4.1 BpfReJIT 系统本身（已有）

**Novelty**：
- 首个对**已 load 的 BPF 程序**做 in-place re-JIT 的系统
- 维持 kernel safety model 不变（重新过 verifier）
- 桥接 runtime / compile-time gap

**会议方向**：OSDI / SOSP / EuroSys / ATC

### 4.2 kop 架构

**Novelty**：
- 可插拔 kernel inline emit
- 把 "which JIT template to emit" 决策**外部化**到 userspace
- 大多 JIT/emitter 是硬编码在 compiler 里；我们外置

**Contribution**：
- 上游 kernel 提议 kop 接口（让其他 BPF 生态系统也能 plug-in）
- LLVM BPF backend 加 kop 元数据（让 LLVM 直接 emit kop-aware bytecode）

### 4.3 Verifier-Feedback-Driven Optimization（PGO 的新形态）

**Novelty**：
- 传统 PGO 用 profile counts 反馈
- 我们用 **verifier 输出的 type narrowing 信息**做反馈
- map_inline / const_prop 用 verifier_states JSON 当 input
- 这是一种 **type-feedback-driven JIT**

**Paper angle**："Verifier-Feedback Optimization for Sandboxed Programs"

### 4.4 PMU-Guided Layout (branch_flip)

**Novelty**：
- 普通 JIT 都做 PMU-guided 但 BPF 没人做
- BPF 通常 stateless wrt PMU
- 我们用 hardware perf counter 反馈驱动 branch layout

**Contribution**：上游 LLVM BPF backend 加 PGO support

### 4.5 e-graph for In-Kernel Sandboxed Code（如果走 Phase 4）

**Novelty**：
- 首个 e-graph optimizer for in-kernel sandboxed programs
- Equality saturation 在 safety-checked execution context
- 必须保证所有 alternative 都过 verifier

**Paper angle**："Equality Saturation for Verified In-Kernel Optimization"  
**会议方向**：PLDI / OOPSLA / ASPLOS

### 4.6 Verified BPF Rewriting（Phase 5）

**Novelty**：
- 形式化证明 rewrite preserves semantics
- 理论上可以**移除** kernel verifier 在 re-JIT 路径上的角色
- "trust the optimizer instead of re-verifying"

**Paper angle**："Verified Optimization for Sandboxed Bytecode"  
**会议方向**：POPL / PLDI / CAV

### 4.7 MLIR Dialect for BPF

**Contribution**：
- 定义 MLIR dialect for BPF
- 高层 lowering：Rust / C / Hybrid → MLIR → BPF
- 启用更高级语言写 BPF 程序 + 优化在 MLIR 层完成

### 4.8 In-Kernel JIT 协作模型

**Novelty**：
- userspace bpfopt + kernel kop modules 协同设计
- userspace 决策"哪个 kop"，kernel 决定"如何 inline"
- 允许 hot-swap JIT strategy 而不重 build kernel

**Contribution**：上游 kernel 提案

### 4.9 性能 characterization study

**Novelty**：
- 首个系统研究"BPF 程序 load 后还能优化多少"
- 对比：AOT compiler quality vs runtime re-optimization
- 真实 workload 数据（7 production apps）

**Paper angle**："Quantifying Post-Load Optimization Headroom for In-Kernel BPF Programs"

### 4.10 社区贡献清单

| 贡献 | 上游项目 | 状态 |
|---|---|---|
| BPF_PROG_REJIT syscall | linux kernel | 已 fork 实现，未 upstream |
| kop 模块接口 | linux kernel | 已实现，未 upstream |
| LLVM BPF backend 改进（fix 不跑的 pass） | LLVM | 待调研 |
| BPF re-JIT C library API | libbpf | 设计中 |
| bpfopt CLI 作为 standalone tool | 自己开源 | 待发布 |
| kop modules 上游 | linux kernel | 待提案 |
| Test corpus 7 apps × full prog | 自己开源 | dump 中 |
| 论文 datasets | OSDI 2026 / 后续 | 准备中 |

### 4.11 论文 contribution 清单建议

针对 OSDI 2026 投稿（"BpfReJIT: Dynamic, Extensible Compilation Framework for Kernel eBPF"）：

**主 contribution**：
1. **BpfReJIT system**：first in-kernel re-JIT 系统
2. **kop architecture**：可插拔 inline emit
3. **kop-class optimizations**：rotate / cmov / movbe / extract / etc. 在已 load BPF 上的应用
4. **Performance evaluation**：7 apps, geomean speedup, ablation studies

**潜在 secondary contribution**（如果 Phase 2-3 完成）：
5. **Pattern DSL**：声明式 BPF rewrite
6. **BB+use-def IR**：BPF 中间表示设计

**潜在长期 contribution**（Phase 4-5）：
7. **e-graph for sandboxed code**：自成一篇
8. **Verified BPF rewriting**：自成一篇

## 5. TODO 列表（Phase 1 收尾 + Phase 2 启动准备）

### Phase 1 收尾（本月内）
- [x] P1-A RewritePlan + 7 pass 迁移
- [x] P1-B pass-owned KopDescriptor + tetragon panic fix + call_off=0 fix
- [x] P1-C utils.rs 拆分 + wrapper/sentinel 清理
- [x] P1-G mega refactor (rewrite 顶级 + 9 重复 + 缺陷-1/2 fix)
- [ ] P1-F dce regression 修复（invest + fix codex 进行中）
- [ ] P1-H 6 P1 violations 修复（fix codex 进行中）
- [ ] testbin/ dump（noop force-fail dump 进行中）
- [ ] Full corpus 7 apps OK + apply 数 ≥ 5/7 baseline
- [ ] Phase 1 完成总结报告

### Phase 2 准备（本月底）
- [ ] **调研 1**：LLVM BPF backend 现状 (`docs/research/llvm-bpf-backend.md`)
- [ ] **调研 2**：eBPF 优化论文综述 (`docs/research/ebpf-optimization-papers.md`)
- [ ] 选 pattern DSL 设计（自己写 proc-macro vs 借用 egg / Bril / etc.）
- [ ] 评估 LLVM BPF backend 上游贡献机会

### Phase 3 准备（下月）
- [ ] BB + use-def IR 数据结构设计
- [ ] BPF bytecode → IR builder 草案
- [ ] IR → BPF bytecode lowerer 草案
- [ ] verifier_states JSON 怎么映射到 IR 节点

### Phase 4 准备（远期）
- [ ] e-graph for BPF 可行性调研
- [ ] kfunc call + verifier types 在 e-graph 中的建模

### 论文准备
- [ ] 完成 Phase 1 + 2 后跑 authoritative benchmark
- [ ] 写 OSDI 2026 投稿
- [ ] 准备 reproducer artifact（基于 testbin/ + standalone bpfopt）
