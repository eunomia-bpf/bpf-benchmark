# BoundsCheckMergePass 实现设计（2026-03-26）

基于以下已有材料：

- `docs/tmp/20260324/bounds_check_elimination_research_20260324.md`
- `docs/kernel-jit-optimization-plan.md` 中 §3.1 `Bounds check merge` 与 §4 架构
- `daemon/src/pass.rs`
- `daemon/src/passes/wide_mem.rs`
- `daemon/src/passes/map_inline.rs`
- `daemon/src/analysis/{cfg.rs,liveness.rs,map_info.rs}`
- `daemon/src/passes/utils.rs`

本文给出 daemon 侧 `BoundsCheckMergePass` 的实现级设计。目标是把 XDP/TC direct packet access 中的 bounds-check ladder 合并成单个更宽的支配性 guard，并删除后续冗余 guard；不是做“全局删 compare”的泛化 DCE。

## TL;DR

- `#442` 的正确工程定义是 `bounds-window merge / guard hoisting`，不是 pure delete。已有研究表明：`42` 个 guard site 中严格可直接删除的为 `0`，但 `35/42 = 83.3%` 落在 ladder 结构里。
- v1 不建议引入新的通用 `PacketAccessAnalysis`。当前 `Analysis` API 不能依赖其他 analysis，硬拆会重复 CFG 计算或扩大框架改动。更务实的做法是：`BoundsCheckMergePass` 直接复用 `CFGAnalysis + BranchTargetAnalysis + LivenessAnalysis`，把 packet-root 恢复和 guard/ladder 识别写成 pass 内私有 helper，风格对齐 `wide_mem.rs`。
- v1 pass 只覆盖 `XDP/TC`、`const window`、`same root`、`same epoch`、`same slow sink`、`side-effect-free linear fast path`。变量 offset / 非常量 length / 跨 helper / 跨互斥分支一律 fail-closed。
- 代码生成上，保留的是“最早且支配后续访问的 dominant guard”，但它在重写后会被扩成最大窗口；不一定保留原本“最大的那个 later guard”。
- 重写实现应沿用 `map_inline.rs` 的模式：`replacements + skip_pcs + addr_map + fixup_all_branches() + eliminate_unreachable_blocks() + eliminate_nops()`。
- pipeline 顺序建议为：`map_inline -> const_prop -> dce -> bounds_check_merge -> wide_mem -> rotate -> cond_select -> extract -> endian_fusion -> branch_flip`。

## 1. 设计目标与非目标

### 1.1 目标

对如下 verifier-friendly packet access 形态：

```c
if (data + off1 + len1 > data_end) goto err;
... packet loads ...
if (data + off2 + len2 > data_end) goto err;
... packet loads ...
if (data + off3 + len3 > data_end) goto err;
... packet loads ...
```

识别出同一 parser phase 内的 ladder，并改写为：

```c
if (data + max_end > data_end) goto err;
... 原有 loads/ALU ...
```

其中 `max_end = max(offi + leni)`。

pass 的收益点有三类：

1. 删除后续 compare/jcc。
2. 删除 guard-only 的 pointer-copy / add 指令。
3. 清理因此变成 unreachable 的冷路径小块。

### 1.2 非目标

v1 明确不做：

- helper-based packet access（如 `bpf_xdp_load_bytes()`）
- 跨 packet-changing helper / `tail_call` / `xdp_adjust_*` 的 merge
- 跨 IPv4 / IPv6 互斥分支的“全局最大窗口”合并
- 非常量长度访问
- 完整通用的 interval/range solver
- 对 host kernel 做任何测试或加载 BPF

## 2. 一个关键澄清：pass 匹配的是原始 bytecode，不是“verifier 改写后的专用 opcode”

根据 `docs/kernel-jit-optimization-plan.md` §4，daemon 通过 `BPF_PROG_GET_ORIGINAL` 拿到的是 load 时保存的原始 BPF bytecode，然后提交新的完整 bytecode 给 `BPF_PROG_REJIT` 重新走 verifier。

这意味着：

- daemon 看不到某个“verifier fixup 后的 bounds-check opcode”；
- 它真正匹配的是 verifier 将来能够识别并据此建立 `PTR_TO_PACKET{id,off,range}` 的 canonical compare 形态；
- `BoundsCheckMergePass` 的职责是重新安排 proof layout，让 re-verify 后仍然接受。

因此，用户问题里“after verifier fixup”的工程化解释应是：

- 不是 verifier 先把 bytecode 改成别的格式再给 daemon；
- 而是 daemon 需要识别 verifier 可接受的 pointer-vs-pointer compare pattern。

## 3. Bytecode pattern recognition

## 3.1 v1 支持的候选 compare 形态

候选 guard 只考虑 `BPF_JMP` 64-bit pointer compare，`JMP32` 一律跳过。支持的关系与 verifier `try_match_pkt_pointers()` 一致，可归一成两类：

```text
if cursor >  data_end goto slow
if cursor >= data_end goto slow
if data_end <  cursor goto slow
if data_end <= cursor goto slow
```

但 ladder merge 时必须额外保守一条：

- **所有被合并 guard 的比较严格性必须一致**。也就是 `>` / `<` 这一类（strict）只能和 strict guard 合并，`>=` / `<=` 这一类（inclusive）只能和 inclusive guard 合并。否则如果仅保留 dominant guard 的原始 compare opcode，再把窗口扩大到 later site，会把 later guard 的边界语义弱化或强化，破坏原程序语义。

以及它们的“fast-edge 反写”形式，例如：

```text
if data_end >= cursor goto fast
```

内部统一归一化为：

```text
Guard(root, data_end, window_end, slow_target, fast_target)
```

其中 `window_end` 表示相对同一 packet root 的“可读上界”。

### 3.1.1 典型 bytecode 骨架

pass 需要识别的不是 source-level AST，而是如下 BPF 骨架：

```text
r_data     = ctx->data
r_data_end = ctx->data_end
r_tmp      = r_data
r_tmp     += CONST_END
if r_tmp > r_data_end goto slow
```

或：

```text
r_cursor   = r_base
r_cursor  += CONST_DELTA
if r_data_end >= r_cursor goto fast
```

常见特征：

- `r_data` 和 `r_data_end` 都来自 `r1` 上下文字段加载及其 copy；
- `r_cursor` 是 `packet_root + const` 的派生指针；
- compare 右值/左值之一必须能恢复成 `data_end` lineage；
- compare 的另一个操作数必须能恢复成相同 root lineage 的 packet pointer。

## 3.2 `data` / `data_end` / `offset` 的识别方法

v1 不建议做单纯“向后看几条指令”的启发式；那对 packet ladder 太脆。更稳妥的做法是在 pass 内做一个轻量的、单文件实现的寄存器抽象解释。

建议的 pass 内状态：

```rust
enum RegValue {
    Unknown,
    Scalar,
    PacketData { root_id: u32, const_off: i32, epoch: u32 },
    PacketEnd  { root_id: u32, epoch: u32 },
}
```

解释规则：

1. `ctx->data` / `ctx->data_end` 的已知字段加载：
   - 对 `XDP`、`TC` 使用小型 per-prog-type 上下文字段表。
   - 加载后分配新的 `root_id`。
2. `mov dst, src`：
   - 直接复制 `RegValue`。
3. `add imm` 作用于 `PacketData`：
   - `const_off += imm`。
4. `add x` / `sub` / 不可识别 ALU：
   - v1 直接降为 `Unknown`。
5. helper call / `tail_call` / packet-changing helper：
   - `epoch += 1`，清空全部 `PacketData/PacketEnd` 状态。
6. 其他改写目标寄存器的指令：
   - 覆盖为 `Scalar` 或 `Unknown`。

借助这套状态，在 compare 点可以直接判断：

- 一个操作数是否是 `PacketData{root_id = X, const_off = end, epoch = E}`
- 另一个操作数是否是 `PacketEnd{root_id = X, epoch = E}`

于是就能恢复：

- `data`：`PacketData` 的 root lineage
- `data_end`：同 root_id 的 `PacketEnd`
- `offset`：`const_off`

## 3.3 Ladder 结构识别

v1 对 ladder 的定义应当保守：

1. 至少有 `2` 个 guard site。
2. 所有 site 绑定到同一 `root_id`。
3. 所有 site 位于同一 `epoch`。
4. 所有 site 的 fast path 形成线性前进链，不含回边。
5. 所有 site 的 slow edge 归一到同一个 canonical slow sink。
6. `window_end` 非递减。
7. dominant site 到最后一个 merged site 之间没有可见 side effect。

这里的 canonical slow sink 处理建议：

- v1 可允许 chase 一层或数层 trivial `ja` trampoline；
- 如果两个 guard 的 slow edge 最终落不到同一 block，直接跳过。

### 3.3.1 为什么要“线性 fast path”

因为真实 parser 里常见的 `14 -> 34 -> 54` 并不总是 strict redundancy：

- `14` 往往是读 `eth->h_proto` 的前提；
- `34` 和 `54` 常常分处 IPv4 / IPv6 互斥分支；
- 跨互斥分支合并会把某条协议专有 guard 错提到另一条协议路径。

所以 v1 只做：

- 同一 fast-path 链上的 ladder merge；
- 不做跨 diamond merge。

## 3.4 允许和不允许的 interleaving

允许的 interleaving：

- 标量 `MOV/ALU`
- 非 packet 的 `LDX/LD_IMM64`
- stack spill/fill
- 已经在当前窗口内的 packet load

不允许的 interleaving：

- helper call / kfunc / pseudo-call / `tail_call`
- `xdp_adjust_head/meta/tail`
- `skb_pull_data` / 其他 packet-changing helper
- map update / map delete / perf event / trace emit
- packet store
- loop backedge

原因很直接：如果把 later guard 合到更早位置，会改变“原先通过小窗口后才能执行的副作用”是否发生。

## 3.5 变量 offset、非常量 length、混合 pattern

v1 策略：

- `const end`：支持
- `const + sym` / `const + scale * sym`：识别但跳过，记 `skip_reason`
- 非常量 length：跳过
- guard 中间夹杂 branch target：跳过

也就是说，v1 首版只做 `Phase 1: constant-window merge`。

Phase 2 再扩展为：

```rust
PacketData {
    root_id,
    base_const,
    sym: Option<SymExpr>,   // 例如 4 * ihl
    interval: Interval,     // 例如 ihl in [6, 15]
    epoch,
}
```

用于支持 `22 + 4 * ihl` 这类 Cilium option parser。

## 4. 合并算法

## 4.1 站点抽象

每个候选 guard site 记录为：

```rust
struct GuardSite {
    compare_pc: usize,
    block_idx: usize,
    setup_pcs: Vec<usize>,
    removable_setup_pcs: Vec<usize>,
    root_reg: u8,
    data_end_reg: u8,
    cursor_reg: u8,
    root_id: u32,
    epoch: u32,
    window_end: i32,
    slow_target_pc: usize,
    fast_target_pc: usize,
    orientation: GuardOrientation,
}
```

其中：

- `setup_pcs` 是 compare 之前为该 guard 准备 cursor 的指令；
- `removable_setup_pcs` 是经 liveness 和 branch-target 过滤后，确认“只为该 guard 服务”的那部分；
- `window_end` 是相对同一 root 的上界。

## 4.2 计算 merged window

从语义上，真实访问窗口可以描述成：

```text
[min_offset, max_offset + max_len)
```

但对 verifier 友好的 emitted proof 实际只需要：

```text
root + merged_end <= data_end
merged_end = max(site.window_end)
```

因此实现上分两层：

1. 诊断/文档层：记录概念上的 `[min_offset, merged_end)`；
2. codegen 层：只发出 `root + merged_end` 的 compare。

这是因为 verifier 的 packet proof 本质上是“从 root 起的可读前缀长度”，不是任意下界区间。

## 4.3 选择保留哪个 check

这里的“dominant one”不是“原来窗口最大的 later guard”，而是：

- 最早能支配后续所有访问、并且适合承载 merged proof 的那个 site。

v1 选择顺序建议：

1. 优先选择 ladder 的第一个 guard。
2. 若第一个 guard 的 compare 位置无法安全重写，再尝试 ladder 中更后的 guard。
3. 若没有任何 site 可安全承载 merged proof，则整个 ladder 跳过。

### 4.3.1 为什么不一定能直接改第一个 guard 的 `add imm`

因为第一个 guard 的 `cursor_reg` 可能在 compare 之后仍然活着。例如：

```text
r3 = data
r3 += 14
if r3 > data_end goto slow
... 后面继续把 r3 当 eth_end / header cursor 用 ...
```

若直接把 `14` 改成 `54`，会破坏后续语义。

因此 dominant site 的 codegen 需要两种模式：

#### 模式 A：原位扩宽

适用条件：

- compare 所用的 `cursor_reg` 在 compare 后不再活跃；
- `setup_pcs` 全部是 guard-only。

重写：

- 改写 `add imm` 为 `merged_end`；
- 保留 compare，slow edge 不变。

#### 模式 B：在 compare 位置合成新的 temp guard

适用条件：

- 原 `cursor_reg` 在 compare 后仍然活着，不能改其定义；
- 但在 `compare_pc` 处能找到一个 dead temp reg。

重写：

```text
tmp = root
tmp += merged_end
if tmp > data_end goto slow
```

然后删除原 compare。

temp reg 选择策略：

- 使用 `LivenessAnalysis.live_in[compare_pc]`；
- 选一个不活跃、不是 `r10`、不是 `root_reg/data_end_reg/cursor_reg` 的寄存器；
- 没有 dead temp 就跳过该 ladder。

## 4.4 删除哪些 later checks

对每个被 merged 的 later guard：

1. `compare_pc` 一定删除。
2. `setup_pcs` 只有在下列条件同时成立时才删除：
   - 其定义的寄存器在 compare 后不活跃；
   - 这些 setup 指令内部没有 branch target；
   - 它们不被后续实际访问复用。
3. 否则仅删除 compare，保留 cursor materialization。

这点必须明确写进实现里，因为 later guard 往往长成：

```text
r4 = r6
r4 += 34
if r4 > r7 goto slow
```

其中 `r4 = r6; r4 += 34` 有时只是 guard temp，有时也会在随后访问中继续使用。两者不能一刀切。

## 4.5 Branch target fixup

重写流程应完全对齐 `map_inline.rs`：

1. 构造：
   - `replacements: BTreeMap<usize, Vec<BpfInsn>>`
   - `skip_pcs: HashSet<usize>`
2. 线性重建 `new_insns`
3. 生成 `addr_map`
4. 调用 `super::utils::fixup_all_branches(&mut new_insns, &program.insns, &addr_map)`
5. 再执行：
   - `eliminate_unreachable_blocks(&new_insns)`
   - `eliminate_nops(&new_insns)`

为什么需要 cleanup：

- later guard 被删后，某些冷块可能彻底无前驱；
- 某些 trampoline `ja +0` 或空 block 会出现；
- 这些情况已经有现成工具，不需要在 pass 内重复发明。

## 4.6 伪代码

```text
scan_guard_sites(program):
  run local packet abstract interpretation
  for each conditional jump:
    if not verifier-friendly packet compare: continue
    recover root_id / epoch / window_end / slow_target / fast_target
    recover setup_pcs
    compute removable_setup_pcs with liveness + branch_targets
    emit GuardSite

form_ladders(sites, cfg):
  walk fast-path chains
  group consecutive sites with same root_id, epoch, slow sink
  require no visible side effect and nondecreasing window_end

rewrite_ladder(ladder):
  merged_end = max(site.window_end)
  choose dominant site
  if dominant site cannot host merged guard: skip
  emit dominant merged guard
  for every later site:
    delete compare_pc
    delete removable_setup_pcs
  rebuild program + fix branches + cleanup
```

## 5. verifier 接受性

## 5.1 verifier 会不会因为删掉中间 guard 而拒绝

会，如果满足以下任一情况：

1. 被删的 guard 是后续访问唯一的 proof basis。
2. 保留下来的 merged guard 不支配后续访问。
3. merged guard 和 later access 不属于同一 packet root lineage。
4. 中间跨过了 packet pointer invalidation。
5. emitted compare 不再是 verifier 认可的 64-bit packet-vs-packet_end 关系。

## 5.2 为什么“保留一个更早、更宽的 dominant guard”通常能通过

因为 verifier 需要的不是“每个 load 前都看见一次 compare”，而是：

- 在访问点前，存在一个同 root lineage 的 dominating guard；
- 它建立的 readable range 足够大；
- 中间没有失效。

换句话说，later compare 本身不是目的；`reg->range` 才是目的。只要 merged guard 保留了这个 proof，later compare 可以删。

## 5.3 具体接受策略

v1 pass 必须遵守以下策略：

1. merged guard 仍使用 packet root 派生出的 cursor 与同 root 的 `data_end` 做 64-bit compare。
2. merged guard 不能跨 epoch。
3. 删除 later guard 时，不得破坏 later access 仍使用的 packet cursor 计算。
4. 若 dominant guard 只能通过“新 temp”发出，则 temp 必须是同 root 的 copy。
5. re-verify 失败时，仍依赖现有 rollback / verifier-attribution 机制 fail-safe。

## 5.4 与 `BPF_NOSPEC/LFENCE` 的关系

`bounds_check_elimination_research_20260324.md` 已经说明：

- `#442` 优化的是 packet proof layout；
- `#433` 优化的是 verifier/JIT 因 proof fragmentation 不得不补出来的 barrier。

因此，`BoundsCheckMergePass` 自己不需要处理 `BPF_NOSPEC`，但它会为未来的 `LFENCE/BPF_NOSPEC` 消除创造更干净的前提。

## 6. Pass 实现设计

## 6.1 文件布局

建议新增：

- `daemon/src/passes/bounds_check_merge.rs`

并修改：

- `daemon/src/passes/mod.rs`

v1 不建议新增 `daemon/src/analysis/packet_bounds.rs`，理由如下：

1. 目前 `Analysis::run(&self, program)` 不能依赖其他 analysis cache；
2. 若强行做成 analysis，要么重复 CFG，要么先改 pass framework；
3. 当前只有这一处需要 packet guard/ladder 事实；
4. `wide_mem.rs` 已经证明“复杂模式识别 + 重写”完全可以做成单文件 pass。

因此 v1 的推荐实现是：

- 复用已有 analysis：`cfg`、`branch_targets`、`liveness`
- packet-root 恢复、side-effect 分类、ladder 形成都写成 pass 私有 helper

如果未来 `LFENCE` 消除、packet-wide-load 也需要同一套 packet facts，再考虑把它抽成通用 analysis，并同时扩展 analysis API。

## 6.2 `required_analyses()`

建议：

```rust
fn required_analyses(&self) -> Vec<&str> {
    vec!["cfg", "branch_targets", "liveness"]
}
```

用途：

- `cfg`：block 边界、fast/slow successor、线性链判断
- `branch_targets`：避免删掉被跳入的 setup/compare
- `liveness`：判断 setup 是否 guard-only、是否可删、是否可选 temp reg

## 6.3 pass 内核心数据结构

建议最小集合：

```rust
enum RegValue { ... }          // packet abstract interpretation
struct GuardSite { ... }       // 单个 guard
struct Ladder { ... }          // 一条可 merge 的链
enum SideEffectKind { ... }    // packet-mutating / visible / none
struct SiteRewrite { ... }     // 对齐 map_inline 的 replacements + skip_pcs
```

其中 `SiteRewrite` 最终应落到：

- `replacements: BTreeMap<usize, Vec<BpfInsn>>`
- `skip_pcs: HashSet<usize>`

## 6.4 与现有 pass 的风格对齐

应刻意复用两种已有模式：

1. `wide_mem.rs`
   - 单文件内完成 scanner + emitter + pass
   - 基于 liveness / branch target 做保守过滤

2. `map_inline.rs`
   - 用 `replacements + skip_pcs + addr_map` 方式重建代码
   - 重写后再做 branch fixup 与 unreachable/nop cleanup

`BoundsCheckMergePass` 不需要引入新 IR，也不需要改 `PassManager`。

## 7. 与 PassManager 的集成顺序

推荐插入顺序：

```text
map_inline
const_prop
dce
bounds_check_merge
wide_mem
rotate
cond_select
extract
endian_fusion
branch_flip
```

理由：

1. `map_inline + const_prop + dce` 先把 specialization 带来的死分支、无用 compare、简化常量都清干净，guard ladder 形状会更稳定。
2. `bounds_check_merge` 自己会改 CFG，因此应该在依赖稳定控制流的后续 peephole 之前运行。
3. 当前 `wide_mem` 会对 XDP/TC packet pointer 保守跳过；`bounds_check_merge` 不改变 load width，不受这个限制。未来若 `wide_mem` 扩展到 packet-safe wide load，提前 merge 还能提供更强窗口。
4. `branch_flip` 依赖最终分支形状和 PGO，应该最后做。

## 8. 测试计划

## 8.1 Rust 单元测试（`make daemon-tests`）

先定义一张最小“输入形状 -> 预期变换”表，避免测试只写名字不写行为：

| Case | 输入形状 | 预期变换 |
|---|---|---|
| single check | 单个 `data + N > data_end` | 不变 |
| ladder of 2 | `14 -> 34`，同 root/sink/epoch | 保留第一个 guard，扩成 `34`，删除第二个 compare |
| ladder of 3 | `14 -> 34 -> 54` | 保留 dominant guard，扩成 `54`，删除后两个 compare |
| ladder of 4 | `14 -> 34 -> 54 -> 74` | 同上，最终窗口 `74` |
| non-adjacent | guard 之间夹纯标量 ALU / stack spill-fill | 仍可 merge |
| variable offset | `22 + 4*ihl` | v1 跳过，Phase 2 再支持 |
| mixed branch | `34` 与 `54` 位于 IPv4 / IPv6 互斥路径 | 不跨分支 merge |
| cursor live | later guard 的 cursor 后续仍被 load 复用 | 仅删除 compare，保留 setup |
| side effect mixed in | 两个 guard 之间有 helper / map update | 不 merge |

在 `daemon/src/passes/bounds_check_merge.rs` 内新增最少以下 case：

1. `single_check_noop`
   - 单个 bounds check，不变。

2. `ladder_2_same_root_same_sink`
   - `14 -> 34`
   - 期望：保留第一个 guard，改成 `34`，第二个 compare 删除。

3. `ladder_3_linear`
   - `14 -> 34 -> 54`
   - 期望：merged 为 `54`，删除后两个 compare。

4. `ladder_4_with_scalar_interleave`
   - 两个 guard 中间夹标量 ALU 和 stack spill/fill。
   - 期望：仍可 merge。

5. `later_setup_kept_when_cursor_live`
   - later guard 的 cursor 计算被后续 load 复用。
   - 期望：只删 compare，不删 setup。

6. `later_setup_removed_when_guard_only`
   - later guard 的 cursor temp compare 后死亡。
   - 期望：setup + compare 一起删除。

7. `dominant_uses_synth_temp_when_cursor_live`
   - 第一个 guard 的 cursor 仍活跃。
   - 期望：在 compare 点合成新的 temp guard，而不是改原 `add imm`。

8. `skip_when_no_dead_temp_reg`
   - 无可用 dead temp。
   - 期望：不变，带 `skip_reason`。

9. `skip_different_slow_sink`
   - 两个 guard slow edge 不同。
   - 期望：不 merge。

10. `skip_across_packet_mutating_helper`
    - 第一和第二个 guard 中间插 `xdp_adjust_head` 等。
    - 期望：epoch 切断，不 merge。

11. `skip_variable_offset_v1`
    - `data + (ihl << 2) + 22`
    - 期望：识别但跳过。

12. `skip_nonconstant_length_v1`
    - length 不是常量。
    - 期望：跳过。

13. `skip_interior_branch_target`
    - guard setup 或 compare 本身被其他 branch 跳入。
    - 期望：跳过。

14. `cleanup_dead_cold_block_after_merge`
    - 删除 later guard 后 slow block 无前驱。
    - 期望：cleanup 后冷块消失，branch offset 正确。

15. `no_cross_branch_ipv4_ipv6_merge`
    - `34` / `54` 位于互斥分支。
    - 期望：不跨分支合并。

## 8.2 VM verifier acceptance（`make vm-static-test`）

这部分是权威验收，不在 host 上做。

策略：

1. 先跑定向对象：
   - `katran/balancer.bpf.o:xdp`
   - `xdp-tools/xdp_forward.bpf.o:xdp`
   - `cilium/bpf_lxc.bpf.o:tc/entry`
   - `cilium/bpf_overlay.bpf.o:tc/entry`

2. 再跑 corpus 静态验证：
   - 使用现有 `daemon/tests/static_verify.py`
   - 目标是 `verifier_accepted=true`，且不引入新的 verifier retry/failure 模式

3. 重点检查 verifier log 中是否出现：
   - `invalid access to packet`
   - `expected=packet_ptr`
   - `unreachable insn`
   - `misaligned access`

## 8.3 变换正确性断言

每个正例测试除 bytecode diff 外，还应断言：

1. `sites_applied` 符合预期；
2. `sites_skipped` 的原因可解释；
3. 分支 fixup 后跳转目标正确；
4. 当 cleanup 发生时，`addr_map` 合成后 annotation remap 不出界。

## 8.4 Phase 2 额外测试

当实现 affine/interval 后，再补：

1. `22 + 4*ihl` 被 `ihl in [6,15]` 约束后可 merge
2. option parser 中 `35/36/38/40/44` 可被更宽窗口覆盖
3. interval 无法求上界时保守跳过

## 9. 量化机会与预期收益

## 9.1 研究结论摘要

来自 `bounds_check_elimination_research_20260324.md` 的关键数据：

- 扫描范围：`cilium` / `katran` / `xdp-tools` 的全部 `XDP/TC` text section
- 总计：`22` 个 section、`42` 个 direct packet guard site
- strict redundant：`0 / 42 = 0%`
- mergeable ladder：`35 / 42 = 83.3%`
- ladder 分布在 `6` 个 section：
  - `cilium/bpf_lxc.bpf.o:tc/entry`
  - `cilium/bpf_overlay.bpf.o:tc/entry`
  - `cilium/bpf_xdp.bpf.o:xdp/entry`
  - `katran/balancer.bpf.o:xdp`
  - `xdp-tools/xdp_flowtable.bpf.o:xdp`
  - `xdp-tools/xdp_forward.bpf.o:xdp`

这说明：

- 真正稀缺的是“现成可删”的 later compare；
- 真正高价值的是“同一 parser phase 内多窗口 ladder 的合并”。

## 9.2 预期代码尺寸收益

保守估计方式：

1. 每消掉一个 later guard，至少少 `1` 条条件跳转。
2. 在常见 `tmp = root; tmp += const; if tmp > data_end goto slow` 形态下，通常还能再删 `1-2` 条 setup。

因此：

- 以 `35` 个 ladder-site、按每个 section 最终至少保留 `1` 个 dominant guard 的粗上界估算，最多可减少约 `29` 个 guard compare；
- 仅按 “删 compare” 算，BPF 指令减少上界约 `29` 条；
- 按更现实的 “compare + 部分 setup” 算，BPF 指令减少上界约 `58-87` 条。

这里是 corpus 上的 opportunity upper bound，不等于 v1 首版立即全拿到：

- `Katran 14/34/54`
- `xdp_forward 14/34/54`
- `Cilium TC 14/34`

这些是 v1 constant-window 最应优先覆盖的部分。

## 9.3 预期性能收益

预期收益来源不是单一“少几条指令”，而是三件事叠加：

1. 少一次或多次 `add + compare + jcc`
2. 更短的 fast-path 依赖链
3. 更少的 parser 分支点，分支预测更稳定

在 XDP/TC parser 热路径里，这类收益通常比普通 straight-line peephole 更值钱，因为 packet parser 的关键路径很容易被小而密的 guard ladder 主导。

额外的间接收益：

- 更宽、更早的 dominant proof 可能减少后续 `BPF_NOSPEC/LFENCE` 的需要，这会和 `#433` 形成联动，但不应在 v1 中混做一个 pass。

## 10. 分阶段落地建议

### Phase 1：const-window linear ladder

范围：

- `XDP/TC`
- `const window`
- 同 root / 同 epoch / 同 slow sink
- side-effect-free fast-path 线性链

实现方式：

- 不引入新 analysis
- pass 内私有 packet abstract interpretation
- 依赖 `cfg + branch_targets + liveness`

### Phase 2：affine + interval

新增能力：

- `const + sym`
- `const + scale * sym`
- 由前置分支得到的区间 refinement

目标：

- 覆盖 Cilium `35/36/38/40/44` 一类 option ladder

### Phase 3：若出现第二个消费者，再抽通用 packet analysis

候选消费者：

- `LFENCE/BPF_NOSPEC` elimination
- future packet-safe `wide_mem`
- packet helper specialization

在那之前，不值得为了“架构漂亮”先改 `Analysis` API。

## 11. 最终设计结论

`BoundsCheckMergePass` 的 v1 形态应当是一个保守、结构化、verifier-friendly 的 control-flow rewrite pass：

- 输入：原始 BPF bytecode
- 识别：同 root / 同 epoch / side-effect-free 的 packet guard ladder
- 变换：保留一个 dominant guard，扩成最大窗口；删除后续 compare；只在安全时删除 setup
- 修复：沿用 `addr_map + fixup_all_branches + unreachable/nop cleanup`
- 验收：`make daemon-tests` + `make vm-static-test`

这条路线直接对准已有研究里的 `83.3% mergeable ladder opportunity`，同时避免为了首版收益去引入新的 pass framework 复杂度，是当前 daemon 架构下最合理的实现切分。
