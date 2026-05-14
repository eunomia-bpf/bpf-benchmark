# bpfopt 生命周期对齐事实设计

日期: 2026-05-14

## 问题

`map_inline`、`const_prop` 等面向 verifier 的 pass 需要关于同一条 BPF 指令流的事实(facts):

- verifier 证明的精确标量、指针种类、栈字节、包范围;
- 本地 bytecode 推导的寄存器/栈状态,例如 `r10 + off`;
- use-def 和 liveness;
- 分支/profile 标注;
- BTF/PC 元数据。

今天这些事实分散在多种形态:

- `ProgramCFG` 顶层 cache(liveness、lifted register facts);
- 裸 `BTreeMap<InsnSite, ...>`(verifier state、metadata);
- pass-private 扫描(`map_inline`、`cond_select`、`wide_mem`、`bulk_memory`、`rotate` 各扫一遍)。

这种割裂导致 pass 之间对 “常量”、“栈字节”、“verifier state” 各有解读,容易吃陈旧或不一致的事实。`map_inline` 和 `const_prop` 不应各持一份 “constant 是什么” 的理解;事实应该跟它生命周期归属的 IR 结点放在一起。

## 设计出发点

这次重构的核心原则,先于一切实现细节:

1. **一个生命周期对应一个 struct**。指令、终结子、块、CFG 是四个不同的生命周期单元(只有前三个持有事实,CFG 只放派生 cache)。每一级的事实直接 inline 进它自己的 struct,字段集按这一层真实需要的内容定。

2. **不创建额外的中间类型**。不引入共享 `Facts` 包装、不引入 `BlockVerifierProof` / `BlockAnalysis` / `BlockLiveness` 这种按 domain 切的 sidecar 类型、不引入 `BTreeMap<InsnSite, ...>` 这种与 IR 平行的长生命存储。事实跟着所属 IR 结点活,跟着所属 IR 结点死。

3. **不并存新旧两套**。任何新加的字段必须同一变更里替换掉旧的存储/查询/helper。review 阶段出现 “暂时保留旧 map,后续清理” 一律打回。

4. **不重复表达同一个事实**。同义的事实(例如块 entry verifier state == 块第一条指令 verifier_before)在 query 层做合并,不在两处都存。

5. **代码量要净减少,不是持平**。这是 refactor,不是加新能力 — 新加的 `InsnNode` / 终结子 / 块字段必须比删除的 sidecar 类型 + 顶层 `BTreeMap` + pass-private 扫描代码更少。出现 “行数持平,以后再瘦身” 一律打回。`cargo build` 体积也应跟着减小。

6. **统一中间表达形态 = 交叉验证的物理基础**。重构的另一个目的是让 verifier 端的证明和 analysis pass 端的本地推导**落在同一块内存里**:同一条指令的 `verifier_before` 和 `local_before` 互为对照,query 层可以一眼看出 "verifier 说 r2 是 fp-132,local 也说 r2 是 fp-132,通过" 还是 "verifier 没 r2 或 verifier 说 scalar,local 自我推导出 fp-132,不一致,verifier-required 查询返回 None"。今天 verifier facts 散在 `BTreeMap`、analysis facts 散在 `LiftedRegFact` / pass-private 扫描里,根本没法对照;集中之后每条指令 / 终结子位置都是一份并列的双重证据,这是后续所有验证、断言、回归检测的物理前提。

这六条决定了下面的结构、生命周期规则、mutation 边界,以及 “删除什么” 的硬约束。任何与之冲突的实现细节(包括为了 “渐进迁移” 而临时引入的并存类型、或者 “暂时不动旧 map” 这种话术)都不在本设计范围内。

## 核心决定

**事实直接 inline 进它生命周期所属的 IR 结点。**

- 不引入共享的 `Facts` 中间类型(避免把 “某些字段对某层无意义” 的语义偏差固化进类型);
- 不引入独立的长生命 sidecar(`BlockVerifierProof` / `BlockAnalysis` / `BlockLiveness` 之类禁止);
- 不引入第二套并行存储 — 旧的顶层 `BTreeMap<InsnSite, ...>`、`LiftedRegFact`、pass-private 扫描结果同一次变更里删干净,不准 “新旧并存,以后清理”。

三级生命周期单元各自持有自己的字段集:

- **指令** — `InsnNode`,包 `BpfInsn` + 该指令位置的事实;
- **终结子** — `Terminator`,块尾分支/跳转/退出 + 该位置的事实;
- **块** — `BasicBlock`,`InsnNode` 序列 + `Terminator` + 块 entry/exit 级事实;
- `ProgramCFG` 只持有派生 index 和版本 epoch,**不**作为事实的主生命周期所有者。

bpfopt IR 仍然是 BPF bytecode:

```text
BpfInsn       内核 ABI 指令(不改其字段)
InsnNode      BpfInsn + 该指令位置的事实
Terminator    分支/跳转/退出 + 该位置的事实
BasicBlock    InsnNode 序列 + Terminator + 块级事实
ProgramCFG    CFG 视图、变更 API、派生 index、epoch
```

## 结构

字段集**故意因层而异**。`ldimm64_second` 只在指令位置有意义,`branch_profile` 只在终结子位置有意义,块级事实不重复 verifier before/after。统一由查询 API 派分到对应层。

```rust
struct InsnNode {
    insn: BpfInsn,

    // verifier 证明的状态(可缺)
    verifier_before: ...,
    verifier_after: ...,

    // 本地 bytecode 推导(fp 偏移、ctx 装载、pkt data/end 来源等)
    local_before: ...,
    local_after: ...,

    // dataflow:站点持有结果,CFG 级算法不动点完成后写回
    uses: RegSet,
    defs: RegSet,
    live_in: Option<RegSet>,
    live_out: Option<RegSet>,
    reaching_defs_in: ...,
    reaching_defs_out: ...,

    // 元数据
    btf_pc: Option<usize>,
    ldimm64_second: Option<BpfInsn>,
}

struct Terminator {
    kind: TerminatorKind,

    // 终结子位置的 before-state;终结子之后是边,边状态归边
    verifier_before: ...,
    local_before: ...,

    uses: RegSet,
    defs: RegSet,

    branch_profile: Option<BranchProfile>,
    btf_pc: Option<usize>,
}

struct BasicBlock {
    id: BlockId,
    version: u64,
    frame: FrameId,
    predecessors: Vec<BlockId>,

    insns: Vec<InsnNode>,
    terminator: Terminator,

    // 块 entry/exit:CFG 不动点的产出落在这里
    live_in: Option<RegSet>,
    live_out: Option<RegSet>,
    reaching_defs_in: ...,
    reaching_defs_out: ...,
}

struct ProgramCFG {
    blocks: Vec<BasicBlock>,
    version: u64,

    // 只放派生 index 和 epoch,不持有事实本身
    use_def_index: Option<DefUseIndex>,   // DefSite -> Vec<UseSite>,可选
    facts_epoch: u64,                     // 不动点是否需要重算
}
```

`...` 是有意留空。设计要求不是把每个事实子类型都先定义出来,而是**字段直接挂在所属层级,不另立类型**。具体表示由实现给出。

## 生命周期规则

事实跟 IR 原子变动:

```text
删指令      -> 删除该 InsnNode(及其所有事实)
插指令      -> 插入新 InsnNode(事实初始化为空)
替换指令    -> 替换 InsnNode;字段重置为空,除非 mutation API 显式声明保留
拆分块      -> 拆 InsnNode 序列;块级事实失效
合并块      -> 合并 InsnNode 序列;块级事实失效
替换终结子  -> 重置 Terminator;受影响边的事实失效
删除块      -> 删除块及其所有事实
```

事实绑定在 `BasicBlock` / `InsnNode` 上是因为它们本来就是指令索引与变更生命周期的所有者。

## Mutation 边界

只有 `ProgramCFG` / `BasicBlock` 暴露的变更 API 能改 IR + 事实:

- 现在 `BasicBlock.insns` / `Terminator` 已经是 `pub(super)`,基本上 pass 进不去;
- 大多数改写已经走 `bbprogram_api.rs`;
- lift 构造直接 push 指令,这是构造不是改写,可以单独处理;
- `bbprogram_api.rs` 内部仍然直接动 `insns` 和 `terminator`,需要把字段重置/边失效一并接进同一 API。

passes 永远不直接动事实字段;读取也只能走查询 API,不准 grep 字段名。

## Verifier Log 边界

verifier log 只是输入格式:

```text
daemon ReJIT log_level=2
  -> verifier_log.rs 解析原始行
  -> ProgramCFG 把规范化后的字段写入对应 InsnNode / Terminator
  -> passes 通过 ProgramCFG 查询 API 读取
```

passes **禁止** import / 检查原始 verifier-log 类型:`VerifierInsn`、`VerifierInsnKind`、`RegState`、`StackState`。

verifier 导入器负责:

- PC ↔ 块 / 指令 / 终结子映射;
- before / after / 边分类;
- delta / 全状态 normalize;
- 保留所有 visit 与 frame;
- 把文本 verifier state 写入 `InsnNode.verifier_*` 或 `Terminator.verifier_before`。

## 统一查询

passes 通过 `ProgramCFG` 上的查询 API 拿事实,**不直接读字段**(读字段也算耦合,日后调整存储就要全 grep):

```rust
prog.verifier_exact_scalar_after(site, reg)        -> Option<i64>
prog.verifier_reg_kind_after(site, reg)            -> Option<RegKind>
prog.verifier_stack_bytes_before(site, reg, width) -> Option<StackBytes>
prog.local_reg_before(site, reg)                   -> Option<LocalReg>
prog.live_out(site)                                -> Option<RegSet>
prog.reaching_defs(site, reg)                      -> Option<DefSiteSet>
```

`site` 是统一定位类型(`Site::Insn(b, i)` / `Site::Terminator(b)` / `Site::BlockEntry(b)` / `Site::BlockExit(b)`),query API 内部按 site 派分到对应层级的字段。

query 层拥有 meet / 一致性规则:

- 没有任何 state -> 没有事实;
- 缺寄存器 -> 没有 verifier 事实;
- 多个 visit 不一致 -> 没有 exact 事实;
- 多个 frame 不一致 -> 没有单 frame 事实;
- 仅边证据不能当作站点级证据;
- verifier-required 查询**不准**静默回退到 local 事实。

允许交叉验证:

```text
local 说 r2 == fp-132
verifier 说 r2 == fp-132 且 stack bytes 精确
  -> map_inline 用 verifier stack bytes,记录 local 一致

local 说 r2 == fp-132
verifier 没 r2 或 verifier 说 r2 是 scalar
  -> verifier-required 查询返回 None;不一致暴露出来
```

## 各层放什么

**InsnNode**

- verifier before/after state、local register/stack state;
- use/def 集;
- liveness in/out;
- reaching defs in/out;
- BTF/PC 元数据;
- LD_IMM64 第二槽。

**Terminator**

- verifier before state、local before state;
- use/def(分支条件读的寄存器);
- branch profile(命中 / 未命中);
- 边分类(由 verifier 导入器写)。

**BasicBlock**(块 entry/exit)

- live_in / live_out;
- reaching_defs_in / reaching_defs_out;
- 不重复 verifier state — 同义于 `block.insns[0].verifier_before` 和 `terminator.verifier_after`,query 层做合并即可。

**ProgramCFG**

- 派生 index(例如 `DefSite -> Vec<UseSite>`);
- 不动点 epoch、版本号;
- 派生 index 是 cache,**不是**事实的主生命周期所有者。事实变了 index 失效,不是反过来。

## 什么留在 pass 内

短暂的匹配器状态可以留在 pass 内,**不要**升级成长生命 sidecar:

- 候选列表;
- 临时扫描窗口;
- `map_inline` 改写计划;
- `cond_select` diamond 候选;
- `wide_mem` ladder 窗口;
- `bulk_memory` run 候选。

如果 pass-local 结果跨 pass 复用或影响正确性,必须升级到对应层级的字段(`InsnNode` / `Terminator` / `BasicBlock`),不准新开 sidecar map。

## Pass 职责

`const_prop` 只用 verifier 查询:

```rust
prog.verifier_reg_kind_after(site, dst_reg)
prog.verifier_exact_scalar_after(site, dst_reg)
```

`map_inline` key 证明用 verifier stack-bytes 查询:

```rust
prog.verifier_stack_bytes_before(call_site, BPF_REG_2, key_size)
```

`map_inline` 可以用 local 事实和结构扫描找 setup / delete 位置,但**不准**把 local 事实当成 key 字节的 verifier 证明。

其他 pass 一律消费共享事实,不再开 pass-private dataflow(纯匹配器内部状态除外)。

## Preservation

默认保守失效:

```text
指令体变了    -> 该 InsnNode 字段重置为空
块体变了      -> 块级事实失效
终结子变了    -> Terminator 字段重置;受影响边失效
CFG 边变了    -> 相关 liveness / reaching defs 失效
```

运行时语义等价**不**自动保留 verifier 事实。任何保留必须在 mutation API 上显式声明,不准 pass 写完之后偷偷复用旧字段。

## 期望代码影响

一次性到位:

- 加 `InsnNode`(包 `BpfInsn` + 该指令位置的事实字段);
- `BasicBlock.insns: Vec<BpfInsn>` 改成 `Vec<InsnNode>`,`Terminator` 加事实字段,`BasicBlock` 加块级字段;
- 删旧的 `BTreeMap<InsnSite, VerifierState>`、顶层 liveness map、`LiftedRegFact` 等独立存储;
- 删旧的 verifier 查询、liveness、use-def helper,统一换成 `ProgramCFG` 查询 API;
- `const_prop` / `map_inline` 改用统一查询;
- pass 里被新存储覆盖的 dataflow 扫描全部删掉。

硬约束:

- 旧存储和新存储**不能**同 patch 共存。同一次变更里替换并删旧,review 出现 “暂时保留旧 map,后续清理” 这种行立即打回;
- passes 不准 import 原始 verifier-log 类型,不准直接读 `InsnNode.*` 字段(走查询 API);
- 净行数应该减少。新加的 `InsnNode` 字段被删除的 sidecar 类型 + 顶层 map + pass-private 扫描抵消并超过。

## 还需要在设计里明确的点

把代码扫了一遍,下面这些场景设计里没有写清楚,先记下来不然实施会撞墙:

### 多次 visit 同一站点

verifier 对同一条指令在不同路径上 visit 多次,今天 `VerifierStatesBySite = BTreeMap<InsnSite, Arc<[VerifierInsn]>>` 用 `Arc<slice>` 把所有 visit 存下来。设计里讲 “disagreeing visits mean no exact fact”,但**没说物理存哪**:
是 `InsnNode.verifier_before: Vec<VisitState>` 保留所有 visit,
还是 `InsnNode.verifier_before: VerifierMeet`(已合并),
还是两者都有(原始 + 合并 cache)。

定:**`InsnNode.verifier_before` 直接存所有 visit(`Box<[VisitState]>` 之类),meet 在查询时算**。理由:meet 是规则,不是事实;放 query 层,passes 永远拿到 “meet 后的事实或 None”;原始 visit 不丢,日后加新查询(比如 “只看某 frame” / “只看某 visit 子集”)还能用。

### 分支边的 verifier state

`CondBranch { taken, fallthrough }` —— verifier 在 taken 边和 fallthrough 边上的 state 可能不同(比如 `if r1 == 0 goto X`:taken 上 r1=0,fallthrough 上 r1≠0)。

定:**边特有的 state 放在 `Terminator` 内的两个槽**:`Terminator { ..., taken_edge_state: ..., fallthrough_edge_state: ... }`;不放在 successor block 的 entry,因为 successor 可能有多个前驱,合并后会丢上下文。query API 提供 `prog.verifier_state_on_edge(from_block, to_block)`。

### 跨 frame 的 site 查询

`BasicBlock.frame: FrameId` 已经存在。跨 frame 的 site 比较(`map_inline` 里有 caller frame + callee frame 同时讨论)需要明确:**query API 默认拒绝跨 frame 的事实合并**(`disagreeing frames mean no single-frame fact` 已经写了),但单 frame 内的查询不变。passes 处理跨 frame 时显式调 `prog.frame_of(site)` 自己判断。

### InsnSite 在 mutation 后的稳定性

`InsnSite { block: BlockId, idx: usize }` 是基于位置的,**任何插入/删除/拆分块都会让现有 site 变指**。今天的代码已经有这个问题,sidecar map 通过 `bbprogram_api` 的 `shift_*` / `remap_site_map` 在 mutation 时迁移 key。

定:**新设计里事实跟着 `InsnNode` 走,自动跟着 Vec 索引移动 —— 不需要手动 shift_site key**。但 pass 持有的 `InsnSite` 仍然会变指,这是原本就有的语义,无变化:**pass 在一次 mutation 后必须重新枚举 site,不准缓存跨 mutation 的 site**。文档加一条 invariant。

### 构造时的初始事实

`bbprogram_lift.rs` 今天从 verifier log 构造 `VerifierStatesBySite`。新设计里 lift 直接把 verifier state 写进每个 `InsnNode.verifier_*` 字段,**construction 阶段就把事实落位,不存在 “空 InsnNode + 后续填” 这一步**。

### 内存占用

`Vec<InsnNode>` 比 `Vec<BpfInsn> + parallel BTreeMap` 大,因为每条指令都附带可能为 None 的事实槽位。最大程序约 katran balancer 2542 条指令;若每个 `InsnNode` 含 verifier_before/after + local_before/after + use/def/live + reaching_defs + btf_pc + ldimm64_second,大致 200~400 字节(取决于 verifier visit 数)。3000 条指令 ≈ 1MB,可接受。但 verifier visit 多的情况(同一站点 100+ visit)需要观察,**必要时把 `verifier_before/after` 做成 `Option<Arc<...>>` 让多 visit 走 Arc 共享**。

### `LiftedRegFact` 的归宿

`LiftedRegFact` 是个 enum(`Unknown` / `FpOff` / 等),是 `prog.reg_fact_at(site, reg)` 的返回值。**它作为查询返回类型保留**;被删的是 `LiftedRegFacts` struct(顶层 cache 容器)和 `lifted_reg_facts_cache: Mutex<...>` 字段。passes 继续看到同一个 enum,只是底层从 cache 转成直接读 `InsnNode.local_*` 字段。

### `verifier_log.rs` 的去留

verifier log parser 作为**输入格式解析器**保留(`verifier_log.rs` 整个文件),因为 daemon ReJIT 日志的解析逻辑跟事实存储无关。lift 阶段把解析结果写进 `InsnNode.verifier_*` 字段,**之后 `VerifierInsn` / `RegState` / `StackState` 这些类型在 ProgramCFG 之外永远不出现**。

### 测试不变量

按 [feedback-testbin-apply-count-verify](feedback_testbin_apply_count_verify.md) 的硬约束:重构前后 testbin 542 progs 的 `applied / matched / skipped / output-bytes` **每一个数字都必须对齐**,不允许抽样。这是设计的功能等价检验,不能跳。

## 代码现状与修改清单

扫了 `bpfopt/crates/bpfopt/src/`,当前分散的事实存储位置:

### 待删除(顶层 sidecar 类型)

```text
analysis/bbprogram.rs:72    verifier_states: Option<VerifierStatesBySite>
analysis/bbprogram.rs:73    branch_profile_by_site: BTreeMap<InsnSite, BranchProfile>
analysis/bbprogram.rs:79    ldimm64_second_slots: BTreeMap<InsnSite, BpfInsn>
analysis/bbprogram.rs:80    pc_relative_ldimm64_targets: BTreeMap<InsnSite, BlockId>
analysis/bbprogram.rs:83    lifted_reg_facts_cache: Mutex<Option<Arc<LiftedRegFacts>>>
analysis/bbprogram.rs:1322  struct LiftedRegFacts            // 顶层 cache 容器
analysis/bbprogram.rs:???   site_liveness_cache: Mutex<...>
analysis/bbprogram.rs:16    type BtfMetadataMap = BTreeMap<InsnSite, usize>
```

### `verifier_facts.rs` 整文件 223 行重新分配

文件本身删,内容按 3 类分流:

| 类别 | 函数/类型 | 处理 |
|---|---|---|
| **A. 存储类型** | `type VerifierStatesBySite = BTreeMap<InsnSite, Arc<[VerifierInsn]>>` | **删**(被 `InsnNode.verifier_before/after` 替代)|
| **B. site-lookup 查询**(5 个,~80 行) | `states_at` / `reg_known_constant` / `reg_kind` / `reg_known_stack_bytes` / `site_is_dead_code` | **删** —— 改写成 `ProgramCFG` 方法,直接读 `InsnNode` 字段,不再走 `BTreeMap` lookup |
| **C. 原始类型解释 helper**(10 个,~140 行) | `reg_exact_value_for_width` / `fp_stack_offset_from_reg_state` / `known_stack_bytes_from_state` / `verifier_stack_slot_*` / `reg_kind_from_verifier_type` / `verifier_reg_states` / `verifier_post_insn_reg_states` 等 | **搬到 `verifier_log.rs`**,挂在 `RegState` / `StackState` / `VerifierInsn` 上作为 inherent method(`state.exact_value(is_32)` / `state.fp_stack_offset()` / `stack.exact_bytes()`)|

C 类是关键:这些函数把**原始 verifier-log 类型 → 类型化事实**(`Option<i64>` 精确常量、`RegKind` 种类、`Option<i32>` fp 偏移、`[u8; 8]` 栈字节)。今天 passes 通过 `verifier_facts.rs` 的查询间接消费这些 helper;迁移后:

1. **lift 阶段一次性调用 C 类 helper**,把原始 `VerifierInsn` 解释成类型化字段写进 `InsnNode.verifier_before / verifier_after`(具体形态:`{ reg_facts: [Option<RegFact>; 11], stack_bytes: Option<StackBytes>, is_dead: bool, ... }`);
2. lift 之后 `InsnNode` **不再持有 `VerifierInsn`**,只持有已解析的类型化字段;
3. `ProgramCFG` 之外的代码(包括所有 passes)**永远看不到** `VerifierInsn / RegState / StackState`,只看 `InsnNode` 的类型化字段。

把 helper 挂在 `verifier_log.rs` 上的理由:那里是 raw verifier-log 类型的唯一定义点,解释方法跟被解释的类型同居最 idiomatic;lift 拿到 `&VerifierInsn` 直接调 `.fp_stack_offset()` / `.exact_value(is_32)` 写入 `InsnNode`,不再需要中间 utility 文件。

`verifier_log.rs` 因此从 690 行涨到约 830 行(吃掉的 140 行 helper),`analysis/verifier_facts.rs` 整个 223 行删,`analysis/mod.rs` 里相关 re-export 一并删。文件总数减少一个。

`verifier_facts.rs` 头部那条 TODO(“This file is the landing point for that work”)就是这次完成的目标 —— landing 完成,文件本身退场。

### 新加(inline 进 IR 结点)

`InsnNode`(替换裸 `BpfInsn` 在 `BasicBlock.insns` 里的存储)、`Terminator` 的事实字段、`BasicBlock` 的块级字段。结构按 “结构” 节定义。

### 保留(语义不变)

```text
LiftedRegFact (enum)        — 仍是 prog.reg_fact_at 的返回类型
UseDefGraph                 — 降级为 ProgramCFG 上的派生 index(use_def_index)
verifier_log.rs             — 输入解析器,逻辑不动
RegSet / RegKind            — 公共类型
```

### Mutation 改动

`analysis/bbprogram_api.rs`(782 行)今天 `delete_insn / insert_insns / remap_blocks` 里手动 shift 这些 map:
- `pc_relative_ldimm64_targets`
- `ldimm64_second_slots`

迁移后:`Vec<InsnNode>` 的 `remove / insert / drain` 自动带走对应的事实槽,**`shift_*` 系列方法和 `remap_site_map` 大部分可以删**(只剩 BlockId 重映射部分,因为 BlockId 是非位置型 id,有自己的 remap 表)。

### Pass 改动

```text
passes/const_prop.rs:20     prog.site_is_dead_code(site)          // 签名不变
passes/const_prop.rs:32     prog.reg_kind(site, dst_reg)           // 签名不变
passes/const_prop.rs:37     prog.reg_known_constant(...)           // 签名不变
passes/map_inline.rs:451    prog.site_is_dead_code(call_site)
passes/map_inline.rs:454    prog.reg_known_stack_bytes(...)
passes/map_inline.rs:455    prog.reg_kind(call_site, BPF_REG_2)
passes/map_inline.rs:2723   prog.reg_fact_at(site, dst)            // 返回 LiftedRegFact
passes/map_inline.rs:2745   prog.reg_fact_at(site, src)
```

**所有 pass-侧查询的方法签名不变** —— 改动是 ProgramCFG 内部实现(去掉 cache 间接,直接读 InsnNode 字段)。pass 文件本身**只会减少**(去掉 pass-private 扫描),不会增加。

### Construction(`bbprogram_lift.rs` 672 行)

`lift_with_kinsn_registry` 今天:
1. 把 raw insns + verifier states 收集成 `ProgramCFG::new` 的参数;
2. `new` 内部把这些塞进 BTreeMap 字段。

迁移后:
1. lift 阶段直接构造 `Vec<InsnNode>`,每个 `InsnNode` 在创建时就**把对应的 verifier state、ldimm64_second、pc_relative_ldimm64_target、btf_pc 写进字段**;
2. `ProgramCFG::new` 接受的参数从一堆 `BTreeMap<InsnSite, ...>` 降到 `blocks: Vec<BasicBlock>` + `entry` + `kinsn_reg`;
3. `lift_verifier_states_by_site`(391 行起)从返回 `Option<VerifierStatesBySite>` 改成在构造 `InsnNode` 时直接写入 `verifier_before/after` 字段。

### 代码量预估

verifier_facts.rs 223 行里 A+B 类(~80)是净删,C 类(~140)是搬到 verifier_log.rs 当 `RegState/StackState/VerifierInsn` 的 inherent method —— 后者不算新增,因为是已有逻辑的物理迁移。

| 删除 | 行数 |
|---|---:|
| `verifier_facts.rs` A 类(`VerifierStatesBySite` 类型)+ B 类(5 个 site-lookup 查询) | ~80 |
| `bbprogram.rs` 顶层 BTreeMap + Mutex cache + LiftedRegFacts struct + 相关 helper | ~250 |
| `bbprogram_api.rs` shift / remap_site_map / sidecar 同步代码 | ~150 |
| `bbprogram_lift.rs` 单独的 lift_verifier_states_by_site + 中间 BTreeMap | ~80 |
| pass-private dataflow 扫描(wide_mem / cond_select / bulk_memory / rotate 等) | ~200 |
| **总计净删** | **~760** |

| 搬迁(不计入净增减) | 行数 |
|---|---:|
| `verifier_facts.rs` C 类(10 个解释 helper)→ `verifier_log.rs` 作 inherent method | ~140 |

| 新加 | 行数 |
|---|---:|
| `InsnNode` struct + Default/Clone | ~50 |
| `Terminator` 字段扩展(每个变种加事实槽) | ~60 |
| `BasicBlock` 块级字段 | ~30 |
| 统一查询 API(`verifier_*` / `local_*` / `live_*` / `reaching_defs_*` + Site enum) | ~250 |
| Mutation 时的 fact 重置点(集中在 `bbprogram_api.rs` 已有 mutation 函数里加 1-2 行) | ~50 |
| **总计加** | **~440** |

**净减少约 320 行**(还没算 pass-private 扫描里间接清掉的胶水代码,实际减少更多)。文件总数减少一个(`verifier_facts.rs` 退场)。符合设计原则 #5。

### 重构顺序(操作建议,不是 stage)

虽然原则要求一次性 patch,但操作上可以分成可独立 compile / 可独立测的步骤,**最后一个 commit 之前不能落库**:

1. 定义 `InsnNode` 类型 + `BasicBlock.insns: Vec<InsnNode>` + Terminator/Block 字段;
2. 把 lift 改写成直接填 `InsnNode` 字段(此时 `BTreeMap` 还在,但内容空);
3. ProgramCFG 查询方法改成读 InsnNode 字段(`BTreeMap` 还在但不再读);
4. mutation API 删 shift / remap_site_map(`BTreeMap` 还在但不维护);
5. 删 `BTreeMap` 声明 + `verifier_facts.rs` + `LiftedRegFacts` struct;
6. 删 pass-private 扫描代码(替换成 ProgramCFG 查询);
7. `cargo build` + testbin 542-prog equivalence test 全过;
8. 合成单一 patch 提交。

中间状态(步骤 2~6)代码会临时膨胀,只能存在于一个 working tree,**不准入库,不准提 PR 中间状态**。

### 风险点

- **BlockId 重映射**:`bbprogram_api.rs` 的 `merge_blocks / drop_blocks` 在调 `remap_site_map` 之前要先 reorder `Vec<InsnNode>` 的所有 site 引用(主要是 `pc_relative_ldimm64_targets`,迁移后这个变成 `InsnNode.ldimm64_target_block: Option<BlockId>`,**它本身就需要 BlockId 重映射处理**)。
- **`use_def: UseDefGraph` 现在被 5 处地方读**,迁移成 “每个 InsnNode 的 uses/defs + 顶层 derive index” 时所有读点都要走 API。
- **verifier visit 数量爆炸**:tracee 某些 prog 单 site 可能有几十个 visit,`InsnNode` 字段如果 inline 存,内存会涨。设计里说 `Box<[VisitState]>` 或 `Option<Arc<[...]>>` 共享,实施时选 Arc 路径。

## Open Questions

- 内核 verifier log 的 before / after / 边映射,需要在真实日志上对齐验证;
- `BranchDeltaState` 该怎么 normalize(显式保留还是丢弃);
- 现有 `UseDefGraph` 是完全替换成 `InsnNode.uses/defs` + `ProgramCFG.use_def_index`,还是部分保留;
- 块重排(permutation)能否安全携带事实,取决于现有 `BlockId` 重映射的保证。
