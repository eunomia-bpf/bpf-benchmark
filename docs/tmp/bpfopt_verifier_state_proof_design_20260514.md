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

这四条决定了下面的结构、生命周期规则、mutation 边界,以及 “删除什么” 的硬约束。任何与之冲突的实现细节(包括为了 “渐进迁移” 而临时引入的并存类型)都不在本设计范围内。

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

## Open Questions

- 内核 verifier log 的 before / after / 边映射,需要在真实日志上对齐验证;
- `BranchDeltaState` 该怎么 normalize(显式保留还是丢弃);
- 现有 `UseDefGraph` 是完全替换成 `InsnNode.uses/defs` + `ProgramCFG.use_def_index`,还是部分保留;
- 块重排(permutation)能否安全携带事实,取决于现有 `BlockId` 重映射的保证。
