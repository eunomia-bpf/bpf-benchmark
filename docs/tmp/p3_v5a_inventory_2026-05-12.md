# P3 V5a Inventory: pass 内 hand-rolled analysis

日期：2026-05-12

范围：基于当前工作树精读 `bpfopt/crates/bpfopt/src/passes/{const_prop,bulk_memory,bounds_check_merge,wide_mem,skb_load_bytes,map_inline,endian}.rs`，以及 `analysis/bbprogram.rs`、`analysis/bbprogram_use_def.rs`、`analysis/bbprogram_api.rs`。本报告只做 read-only 盘点；没有修改实现代码。

LOC 估算按相关状态类型、transfer、扫描 helper、alias/provenance helper 的源码行粗算，包含少量 glue。

## 1. 每个 pass 的 hand-rolled 分析清单

### const_prop.rs

| file:line | 分析名 | 类型 | LOC | 现有 oracle 是否覆盖 | 缺什么 |
|---|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:11-32` | `RegConstFact` / `RegConstState` | reg-const + pointer-kind fact | 22 | 是：`reg_known_constant(site, reg)` + `reg_kind(site, reg)` | 无；可由 BBProgram per-site verifier fact 取代 |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:96-161` | `dataflow_predecessors` / `solve_block_entry_states` / `merge_predecessor_states` | CFG dataflow + reg-const meet | 66 | 是：若 pass 只信 `reg_known_constant` 的 per-site fact，不需要 pass 内 block-in/out | 无；结构边已有 `dataflow_successors` / `predecessors` |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:162-248` | `simulate_block` / `analyze_instruction` | reg state machine / transfer | 87 | 是：rewrite 判断可直接查询当前 site 的 verifier-derived const/kind；dead code 用 `site_is_dead_code` | 无；需明确当前 `reg_known_constant` 的 site-state 语义 |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:305-335` | `apply_program_facts` / `verifier_reg_may_be_pointer` | verifier reg-kind + reg-const overlay | 31 | 是：这段已经只是逐 reg 调 `reg_kind` / `reg_known_constant`，属于重复 glue | 可删；如保留，放到 BBProgram helper |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:336-427` | `evaluate_alu_result` / `reg_const` / `meet_states` / `unknown_state` | ALU reg-const evaluator + merge | 92 | 是：最终 replacement value 可来自 `reg_known_constant(site, dst)`，无需 pass 自己算 lattice | 可选：`reg_known_constant_u64(site, reg) -> Option<u64>` 避免 i64 往返表达不直观 |

结论：`const_prop` 的 hand-rolled 分析基本可 100% 等价替换为现有 BBProgram oracle；这是最大的一块纯删除候选之一。

### bulk_memory.rs

| file:line | 分析名 | 类型 | LOC | 现有 oracle 是否覆盖 | 缺什么 |
|---|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:116-139` | `RegValue = Option<u64>` + `SimpleRegValue` impl | reg-const | 24 | 是：`reg_known_constant(site, reg)` | 无 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:209-260` | `scan_sites` 中跨 insn 维护 `regs` | linear reg-const state | 52 | 是：`memset_lane_at` 可在 store site 直接查 src reg constant | 无 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:266-283` | `memcpy_alias_skip_reason` + stack/non-stack heuristic | stack-pointer / alias class | 18 | 是：`reg_kind(start_site, reg) == FramePointer` 可替代 `is_likely_stack_ptr` | 无；保持 unknown 时保守 skip |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:437-466` | `memset_lane_at(..., regs)` | reg-const for fill byte | 30 | 是：`reg_known_constant(site, insn.src_reg())` | 无 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:643-677` | `is_likely_stack_ptr` 32-insn lookback | stack-pointer + use-def lookback | 35 | 是：`reg_kind(site, reg)` 已覆盖 FramePointer kind | 无 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:678-718` | `advance_reg_state_range` / `advance_reg_state_at_site` | reg state machine driver | 41 | 是：删除 `regs` 后随之删除 | 无 |

结论：`bulk_memory` 的 pass-local reg state 和 stack heuristic 可 100% 用现有 oracle 替换；注意保持当前对 unknown/non-proven alias 的保守 skip 行为。

### bounds_check_merge.rs

| file:line | 分析名 | 类型 | LOC | 现有 oracle 是否覆盖 | 缺什么 |
|---|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:9-15` | `RegValue::{PacketData, PacketEnd, Scalar}` | packet-pointer kind + root + const_off | 7 | 部分：`reg_kind` 只有 `PacketPointer`，当前 `RegKind` 没有 `PacketEnd` variant | `PacketEnd` 表达；packet root / offset fact |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:154-198` | `scan_guard_sites` 中维护 `states`、`next_root_id`、`last_data_root` | packet-pointer state machine | 45 | 部分：kind 可由 verifier；root pairing/offset 不覆盖 | `packet_pointer_fact(site, reg)` |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:200-313` | `detect_guard_candidate` 读取 `states` 判断 root/data_end/cursor | packet-pointer relation + const_off | 114 | 部分：`reg_kind` 不够判断同一 packet root 和 cursor offset | `PacketPointerFact { kind, root, const_off }` |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:315-336` | `cursor_dead_after_compare` | use-def / liveness | 22 | 是但粗糙：`def_sites` + `uses_for_def` 已覆盖 | 可选 convenience：`uses_of_site_def(site, reg)` |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:450-512` | `apply_transfer` | packet-pointer transfer / scalar kill | 63 | 否：这是 pass 内完整重跑 packet pointer 状态 | `packet_pointer_fact(site, reg)`，并补齐 verifier log 对 `pkt_end`/offset/root 的结构化保存 |

结论：`bounds_check_merge` 不能直接靠现有 API 全替换。需要先把 packet pointer fact 做成 BBProgram analysis，并明确 `pkt`/`pkt_end`、root identity、const offset 的来源和多 verifier state 合并规则。

### wide_mem.rs

| file:line | 分析名 | 类型 | LOC | 现有 oracle 是否覆盖 | 缺什么 |
|---|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:165-175` | `is_likely_packet_ptr` 32-insn lookback | packet-pointer heuristic | 11 | 是：`reg_kind(start_site, base_reg)` 可直接判断 `PacketPointer`/pointer kind | 无；`None` 时按当前 conservative default skip |
| `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:220-225` | scratch live-after check | liveness | 6 | 已使用 `live_out_site_checked` | 无 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:256-268` | BTF/other pointer rejection | reg-kind | 13 | 已使用 `reg_kind` | 无 |

结论：`wide_mem` 剩余 hand-rolled 分析很小，`is_likely_packet_ptr` 可直接删除。

### skb_load_bytes.rs

| file:line | 分析名 | 类型 | LOC | 现有 oracle 是否覆盖 | 缺什么 |
|---|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:10-16` | `RegValue::{Ctx, Const, FpPlusConst}` | reg-kind + reg-const + stack-pointer offset | 7 | 部分：ctx/const 已覆盖；stack offset 未公开 | `reg_stack_offset(site, reg)` |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:36-84` | `SimpleRegValue` impl | reg state machine | 49 | 部分：`reg_known_constant` 覆盖 constants；`FpPlusConst` 需新 API | `reg_stack_offset(site, reg)` |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:126-158` | per-block `regs = initial_reg_state()` + `advance_reg_state` | linear reg state | 33 | 部分 | same |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:164-197` | `classify_site` 检查 arg1/arg2/arg3/arg4 | helper arg fact / stack pointer | 34 | 部分：arg1 用 `reg_kind == Context`；arg2/arg4 用 `reg_known_constant`；arg3 缺 stack offset | `reg_stack_offset(call_site, BPF_REG_3) -> Option<i32>` |
| `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:241-254` | `initial_reg_state` / `add_sub_i64` | ctx/fp seed + stack offset transfer | 14 | 部分 | 删除后不需要；由 `reg_stack_offset` 取代 |

结论：`skb_load_bytes` 需要一个很小的 BBProgram stack-pointer-offset oracle 后才能完整替换。

### map_inline.rs

| file:line | 分析名 | 类型 | LOC | 现有 oracle 是否覆盖 | 缺什么 |
|---|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:289-357` | `find_map_in_map_chain_for_outer` | R0 alias tracking + null-check CFG + stack spill/load alias | 69 | 部分：`insn_use_def_set`、CFG API 可辅助；没有 cached alias/provenance | lookup-result alias/use summary；stack slot provenance |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:400-462` | `lookup_key_setup_sites` / `collect_lookup_key_stack_store_sites` | stack store provenance for deletion | 63 | 部分：`reg_known_stack_bytes` 已给 key bytes，但不给 source setup/store sites | `stack_byte_source_sites(site, reg, width)` 或 `reg_known_stack_bytes_with_sources` |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2154-2235` | `find_direct_map_load_for_reg_before_site*` | map ref provenance through reg copy + stack spill/load | 82 | 部分：`map_bindings` 只解析 map id；use-def 只有 def->uses public query | `defs_for_use(site, reg)`；stack slot last-store/source provenance |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2248-2297` | `find_r2_stack_pointer_setup_simple` / `find_prev_reg_def_within` | stack pointer setup + bounded use-def lookback | 50 | 部分：bytes 已可查；setup sites 和 stack offset 缺 | `reg_stack_offset` + source sites |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2307-2380` | `find_prev_reg_def` / `resolve_map_value_pointer_inner` | pseudo-map-value pointer provenance + offset arithmetic | 74 | 否：现有 API 没有 “reg 源自哪个 pseudo map value load” | `reg_map_value_origin(site, reg)` |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2381-2422` | `resolve_stack_pointer_to_stack_inner` | stack-pointer offset analysis | 42 | 否：`reg_known_stack_bytes` 内部有 fp offset helper，但未公开 | `reg_stack_offset(site, reg)` |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2484-2602` | `classify_r0_uses_with_options` | use-def + liveness + R0 alias + stack spill + null-check | 119 | 部分：`insn_use_def_set` 可查单 insn，`def_sites/uses_for_def` 可查 forward uses；整体 alias scan 没有 oracle | `lookup_result_uses(call_site, options)` 或更通用 pointer-origin use summary |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2604-2656` | `resolve_stack_store_slot` / `resolve_stack_load_slot` | stack memory access classification | 53 | 否：需要 stack base offset oracle | `stack_access(site) -> Option<StackAccess>` |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2657-2755` | alias helper cluster | alias kill/survival/null-check/use detection | 99 | 部分：per-insn use/def 已有；alias semantics 未集中 | pointer-origin / alias relation cache |

结论：`map_inline` 已经用上 `reg_known_stack_bytes`，但仍有最大量 pass-local provenance/alias 分析。它应最后迁移：先补 `defs_for_use`、stack offset/access、stack byte source、map-value origin，再替换 R0 use classifier。

### endian.rs

| file:line | 分析名 | 类型 | LOC | 现有 oracle 是否覆盖 | 缺什么 |
|---|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/endian.rs:74-117` | `scan_endian_site_in_window` 中用 `insn_use_def_set` 找 dst use/def barrier | local use-def / bounded liveness | 44 | 部分：V4 已替换 `reads_reg`/`writes_reg`；仍是 pass-local bounded use-def scan | 可选 `uses_of_site_def(site, reg)` / `site_use_def(site)`，保留 MAX_NARROW_SCAN 语义 |
| `bpfopt/crates/bpfopt/src/passes/endian.rs:134-168` | `find_blocked_narrow_sites` 的 `read_before_endian` | local liveness / use-before-endian detection | 35 | 部分：`insn_use_def_set` 覆盖单 insn；BBProgram use-def 可更直接表达 load def 的 uses | `uses_of_site_def` 或 `first_use_or_def_after(site, reg, limit)` |

结论：`endian` 没有 `[RegValue; 11]` 类状态机残留；剩余是 bounded local use-def/liveness scan。它不阻塞 V5 verifier-derived analysis，但可以在新增 use-def convenience 后顺手收敛。

## 2. 现有 BBProgram oracle API 总览

| API | signature / 位置 | 内部如何算 | 当前使用者 |
|---|---|---|---|
| verifier constant | `BBProgram::reg_known_constant(&self, site: InsnSite, reg: u8) -> Option<i64>` (`analysis/bbprogram.rs:302-311`) | 每次从 `oracle` 取 `verifier_reg_states(site, reg)`；要求非空、无 `EdgeFullState`、所有 state exact 值一致；不是预计算 cache | `const_prop.rs:263,301,311`；建议迁移 `bulk_memory`、`skb_load_bytes` |
| verifier reg kind | `BBProgram::reg_kind(&self, site: InsnSite, reg: u8) -> Option<RegKind>` (`analysis/bbprogram.rs:312-321`) | 每次从 verifier reg type 映射 `RegKind`，要求所有 state kind 一致；不是预计算 cache | `const_prop.rs:321`、`wide_mem.rs:257`、`map_inline.rs:373`；建议迁移 `bulk_memory`、`bounds_check_merge`、`skb_load_bytes` |
| verifier stack bytes | `BBProgram::reg_known_stack_bytes(&self, site: InsnSite, reg: u8, key_width: usize) -> Option<Vec<u8>>` (`analysis/bbprogram.rs:324-350`) | 每次读 oracle state；要求 reg 是 fp-relative，按 verifier stack slot exact bytes/zero bytes 拼出 width，所有 states 一致 | `map_inline.rs:372` |
| dead code | `BBProgram::site_is_dead_code(&self, site: InsnSite) -> bool` (`analysis/bbprogram.rs:351-355`) | 读 oracle；所有 state 都 speculative 时认为 dead | `const_prop.rs:220`、`map_inline.rs:369` |
| site liveness | `BBProgram::live_out_site_checked(&self, site: InsnSite) -> anyhow::Result<RegSet>` (`analysis/bbprogram.rs:265-272`) | 每次调用都跑 `compute_site_liveness(self)` (`analysis/bbprogram.rs:1315-1370`)；不是 cache | `bulk_memory.rs:219`、`wide_mem.rs:220`、另有 `ccmp`、`cond_select`、`rotate` |
| per-insn use/def | `insn_use_def_set(insn: &BpfInsn) -> RegUseDefSet` (`analysis/bbprogram_use_def.rs:225-281`) | 纯 opcode decode；不查 BBProgram cache | `endian`、`map_inline`、`bulk_memory`、`cond_select`、`UseDefGraph::build` |
| use-def graph | `UseDefGraph::build(prog: &BBProgram) -> anyhow::Result<Self>` (`analysis/bbprogram_use_def.rs:39-72`) | fixed-point reaching defs over `dataflow_successors`，使用 kinsn-aware per-site facts；结果缓存到 `BBProgram.use_def` (`analysis/bbprogram.rs:71,706-729`) | 间接供 `def_sites` / `uses_for_def` / DCE |
| def sites | `BBProgram::def_sites(&self) -> impl Iterator<Item = DefSite>` (`analysis/bbprogram.rs:425-427`) | 读 cached `use_def.defs` | `dce.rs:25`、`bounds_check_merge.rs:321` |
| uses for def | `BBProgram::uses_for_def(&self, def: DefSite) -> &[UseSite]` (`analysis/bbprogram.rs:428-430`) | 读 cached `use_def.defs[def]` | `dce.rs:26`、`bounds_check_merge.rs:330` |
| CFG predecessor/successor | `predecessors(&self, block) -> &[BlockId]`, `successors(&self, block) -> &[BlockId]` (`analysis/bbprogram.rs:214-218`) | `rebuild_cfg_edges` 维护 cached vectors (`analysis/bbprogram.rs:679-704`) | `bbprogram_api`、`ccmp`、analysis tests |
| dataflow successors | `pub(crate) fn dataflow_successors(&self, block) -> anyhow::Result<Vec<BlockId>>` (`analysis/bbprogram.rs:750-756`) | 由 terminator 计算；call 只流向 return_to (`analysis/bbprogram.rs:1039-1053`) | `const_prop.rs:102`、`UseDefGraph::build` |
| linear-state reset hint | `should_reset_linear_state_at_block(&self, block) -> anyhow::Result<bool>` (`analysis/bbprogram.rs:220-238`) | 结构性查询：pred 数量、block 顺序、terminator fallthrough | `bulk_memory.rs:213`、`prefetch.rs:236`；V5 后不应再用于 reg state |
| branch target entry sites | `branch_target_entry_sites(&self) -> anyhow::Result<BTreeSet<InsnSite>>` (`analysis/bbprogram.rs:511-531`) | 每次扫描 terminator target 和 pc-relative ldimm64 target；不是 cache | `bounds_check_merge`、`wide_mem`、`skb_load_bytes`、`map_inline`、`branch_flip` |
| PMU profile queries | `branch_taken_rate`, `branch_miss_rate`, `site_hotness`, `prefetch_hint` (`analysis/bbprogram.rs:374-407`) | 读 cached `pmu_profile`，由 annotations attach | `branch_flip`、`prefetch` |
| map bindings | `map_bindings`, `map_fd_bindings` (`analysis/bbprogram.rs:286-294`) | lift side-input attach 时从 original insns/map_ids 收集，存于 `map_bindings` | `map_inline.rs:2078` 等 |
| structural window/edit APIs | `sites_in_block*`, `block_body_view`, `scan_block_starts`, `try_replace_range_with_skips`, etc. | 结构性 BBProgram view/edit，不是 verifier oracle | 多个 matcher / rewrite pass |

关键现状：`use_def` 和 CFG edges 是 cache；verifier constant/kind/stack-byte 查询是按调用从 `oracle` 现算；site liveness 每次 fixed-point 重算。V5 若按 “lift 一次算好 cache 进 BBProgram” 执行，至少应把 verifier-derived per-site reg facts、site liveness、use-def site facts变成显式 cached analysis。

## 3. V5b/V5c 需要新增的 BBProgram method 提议

### 3.1 Stack pointer offset

```rust
pub fn reg_stack_offset(&self, site: InsnSite, reg: u8) -> Option<i32>;
```

实现思路：把 `bbprogram.rs:923-931` 的 `fp_stack_offset_from_reg_state` 公开成一致性查询：读取 `verifier_reg_states(site, reg)`，要求所有 states 都是 fp-relative 且 offset 一致，返回 fp-relative byte offset。与 `reg_known_stack_bytes` 使用同一 state 过滤规则。

替代代码：
`skb_load_bytes.rs:10-84,126-197,241-254`；`map_inline.rs:2381-2422,2604-2656`；`bulk_memory.rs:643-677` 的 stack 判定也可直接用 `reg_kind == FramePointer` 或此 API。

### 3.2 Site use/def cached query and reverse def lookup

```rust
pub fn site_use_def(&self, site: InsnSite) -> anyhow::Result<&RegUseDefSet>;
pub fn defs_for_use(&self, site: InsnSite, reg: u8) -> &[DefSite];
pub fn uses_of_site_def(&self, site: InsnSite, reg: u8) -> &[UseSite];
```

实现思路：`UseDefGraph` 已有 `uses: BTreeMap<UseSite, Vec<DefSite>>` 和 `defs: BTreeMap<DefSite, Vec<UseSite>>`，只是没有对 `uses` 的 public accessor，也没有 per-site cached `RegUseDefSet` accessor。`kinsn_aware_site_facts` 目前 build 时临时生成，可持久化到 BBProgram 或 UseDefGraph。

替代代码：
`map_inline.rs:2154-2235,2248-2297,2307-2380,2745-2755`；`endian.rs:74-117,134-168`；`bounds_check_merge.rs:315-336` 可从手写 `def_sites().find(...)` 收敛为一行。

### 3.3 Cached site liveness

```rust
pub fn live_out_site_checked(&self, site: InsnSite) -> anyhow::Result<RegSet>;
pub fn live_in_site_checked(&self, site: InsnSite) -> anyhow::Result<RegSet>;
```

实现思路：保留现有 signature，但把 `compute_site_liveness` 的结果作为 BBProgram cache，在 `new` / mutation rebuild 时更新。新增 `live_in` 查询可服务后续 alias/use-region 判定，避免 pass 自己从 use-def 扫。

替代代码：
`bulk_memory.rs` 和 `wide_mem.rs` 已用 `live_out_site_checked`，收益主要是性能和 V5 架构一致性；`map_inline` R0 use classifier 可借 `live_in/live_out` 简化。

### 3.4 Packet pointer fact

```rust
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PacketPointerKind {
    Data,
    DataEnd,
    Meta,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct PacketPointerFact {
    pub kind: PacketPointerKind,
    pub root: u32,
    pub const_off: i32,
}

pub fn packet_pointer_fact(&self, site: InsnSite, reg: u8) -> Option<PacketPointerFact>;
```

实现思路：lift/verifier analysis 统一解析 verifier reg type `pkt` / `pkt_end` / `pkt_meta`、offset，并给同一 `ctx->data` / `ctx->data_end` proof scope 分配稳定 `root`。当前 `RegKind` 没有 `PacketEnd`，`verifier_log.rs` 也没有把 packet range/root 信息序列化出来；若依赖 verifier log，需要补 JSON field（例如 `id`/`range`）或在 lift packet analysis 中从 ctx load provenance 合成 root。

替代代码：
`bounds_check_merge.rs:9-15,154-313,450-512`；`wide_mem.rs:165-175` 也可用它替代 packet heuristic。

### 3.5 Stack access and stack byte source

```rust
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum StackAccessKind {
    Load,
    Store,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct StackAccess {
    pub kind: StackAccessKind,
    pub base_reg: u8,
    pub off: i16,
    pub width: u8,
}

pub fn stack_access(&self, site: InsnSite) -> Option<StackAccess>;

pub struct StackBytesFact {
    pub bytes: Vec<u8>,
    pub source_sites: BTreeSet<InsnSite>,
}

pub fn reg_known_stack_bytes_with_sources(
    &self,
    site: InsnSite,
    reg: u8,
    count: usize,
) -> Option<StackBytesFact>;
```

实现思路：`stack_access` 用 `reg_stack_offset(site, base_reg)` + opcode size 统一计算 stack load/store slot。`reg_known_stack_bytes_with_sources` 复用现有 `reg_known_stack_bytes` 的 byte fact，同时用 cached stack store provenance 记录覆盖这些 bytes 的 store sites。source site 必须保守：遇到不完整覆盖、overlap ambiguity、branch merge disagreement 时返回 `None` 或空 source set但不允许删除 setup。

替代代码：
`map_inline.rs:400-462,2248-2297,2604-2656`。

### 3.6 Map value / map reference provenance

```rust
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub struct MapRefOrigin {
    pub load_site: InsnSite,
    pub src_reg: u8,
    pub imm: i32,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct MapValueOrigin {
    pub map_ref: MapRefOrigin,
    pub value_off: i32,
}

pub fn reg_map_ref_origin(&self, site: InsnSite, reg: u8) -> Option<MapRefOrigin>;
pub fn reg_map_value_origin(&self, site: InsnSite, reg: u8) -> Option<MapValueOrigin>;
```

实现思路：在 lift 后的 provenance analysis 中沿 cached use-def 处理 `LD_IMM64 map_fd/map_idx/map_value`、MOV、ADD/SUB imm、stack spill/load。用 verifier `reg_kind == MapValue` 作校验，不能用时返回 None，不回退到 heuristic scan。

替代代码：
`map_inline.rs:2154-2235,2307-2380,1927-2034`。

### 3.7 Helper return alias/use summary

```rust
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct PointerUseSummary {
    pub fixed_offset_loads: Vec<PointerLoadUse>,
    pub other_uses: Vec<InsnSite>,
    pub alias_copies: Vec<InsnSite>,
    pub null_check: Option<InsnSite>,
}

pub struct PointerLoadUse {
    pub site: InsnSite,
    pub dst_reg: u8,
    pub size: u8,
    pub offset: i16,
}

pub fn helper_return_pointer_uses(
    &self,
    call_site: InsnSite,
    helper_id: i32,
    options: PointerUseOptions,
) -> anyhow::Result<PointerUseSummary>;
```

实现思路：BBProgram analysis 以 helper return def 为 origin，沿 use-def、stack spill/load、callee-saved helper survival、null-check CFG 走一次，产出 pass 可消费的 summary。`map_inline` 不应自己维护 `alias_regs` / `alias_stack_slots`。如果不想做 helper-specific API，可先做更通用的 `pointer_origin(site, reg)` + `uses_of_origin(origin)`，但 `map_inline` 当前需要的输出就是上面四类。

替代代码：
`map_inline.rs:289-357,2484-2602,2657-2755`。

## 4. V5 实施顺序提议

1. 先做 BBProgram cache 基建：cache `site_use_def`、`defs_for_use`、`live_in/live_out`，并保持 mutation 后统一 rebuild/invalidate。这一步风险低，会立刻改善 `endian`、`bounds_check_merge`、`map_inline` 的后续替换基础。
2. 先改 `wide_mem`：删除 `is_likely_packet_ptr`，用 `reg_kind` 保守判断 packet pointer。最低风险，改动小。
3. 再改 `bulk_memory`：删除 `RegValue` / `advance_reg_state_*` / `is_likely_stack_ptr`。收益中等，现有 `reg_known_constant` 和 `reg_kind` 足够。
4. 再改 `const_prop`：删除整套 `RegConstFact` dataflow。LOC 收益最大，但必须先锁定 `reg_known_constant` 的 site-state 语义和 32-bit normalization。
5. 然后补 `reg_stack_offset` / `stack_access`，改 `skb_load_bytes`。此 pass 小，但需要新 API 才能不退回手写 FP+const state。
6. 之后改 `endian`：不是 V5 的主要 verifier-derived blocker，可在 use-def convenience 可用后把 bounded scan 收敛掉。
7. 再做 `bounds_check_merge`：先补 `packet_pointer_fact` 和 `PacketEnd` 表达，再删 `apply_transfer`。风险高于前面几个，因为 packet root/offset 的等价性要非常清楚。
8. 最后做 `map_inline`：分三段迁移，先 map-ref/map-value origin，再 stack byte sources/setup deletion，最后 R0 helper-return alias use summary。它 LOC 最大、行为最复杂，应该最后收。

最低风险优先：`wide_mem` -> `bulk_memory`。

最高 LOC 收益：`const_prop` 和 `map_inline`，但 `map_inline` 必须最后。

## 5. 风险评估

### const_prop

- `reg_known_constant(site, reg)` 的 “site 是 pre-state 还是 post-state” 必须固定。当前代码把它当 ALU site 的 verifier post-state 使用；直接替换前要用测试覆盖 MOV/ALU32/ALU64/LD_IMM64。
- `reg_known_constant` 返回 `i64`，内部来自 `u64 as i64`；当前代码再转回 `u64`。大常量语义要避免被后续代码误读成 signed。
- oracle 在 `EdgeFullState`、缺失 states、多路径不一致时返回 None；替换后应自然 skip，而不是恢复 pass-local state fallback。
- mutation 后 BBProgram 会 invalidate oracle；`const_prop` 必须只基于 mutation 前收集的 candidates 做一轮，不能在同一 pass 后半段继续查旧 oracle。

### bulk_memory

- `is_likely_stack_ptr` 当前在不确定时会偏保守。换成 `reg_kind` 后，`None`/`Unknown` 在 packet/alias-sensitive 判断里必须继续保守 skip。
- `memset` 的 STX src constant 查询要确认 verifier state 在 store site 能看到 store operand 的值。
- `should_reset_linear_state_at_block` 删除后，跨 block 行为会完全由 verifier oracle 决定；缺 verifier state 不能 fallback 到 linear simulation。

### bounds_check_merge

- 当前 `RegKind` 没有 `PacketEnd`，`reg_kind_from_verifier_type` 也没有专门处理 `pkt_end`。不补这个，`PacketEnd` 无法表达。
- 当前 verifier JSON 没有序列化 `RegState.id`，parser 也忽略 packet log 中常见的 `r=...` 属性。`packet_pointer_fact` 若依赖 root identity，需要先补 verifier-state schema 或 lift-time packet provenance。
- 多 verifier states 在同一 site 上的 packet root/offset 不一致时必须返回 None 并 skip，不能选择一条路径。
- `interleaves_are_merge_safe` 仍是 pass-specific CFG safety；即使 packet fact 迁入 BBProgram，也要保留或提升这类 rewrite safety predicate，避免误删跨 guard 的副作用。

### wide_mem

- 当前 heuristic 找不到 def 时返回 true，导致 packet-unsafe prog type 保守 skip。换成 `reg_kind` 时，`None` 也应按 packet-unsafe 保守 skip，除非能证明是 `FramePointer`/scalar-safe。
- BTF/Other pointer rejection 已经用 `reg_kind`；合并 packet 判断时不要放宽现有 field-boundary skip。

### skb_load_bytes

- helper call site 的 arg state 需要明确定义为 call 前 operand state；如果现有 verifier oracle site fact是 post-call，需要新增 before-state fact，不能用 post-call clobbered regs。
- `reg_stack_offset` 对多路径 FP offset 不一致必须返回 None；pass 应 skip，不做线性 fallback。
- 当前 per-block state 不跟 CFG；oracle 替换可能发现更多真实可优化点，也可能因 missing verifier state 更保守。需要回归覆盖 branch target 和 helper arg cases。

### map_inline

- `reg_known_stack_bytes` 已给 key bytes，但 deletion 还依赖 setup/store source sites。source provenance 如果不完整，必须保留 setup，不可误删。
- R0 alias summary 要保留当前 null-check/non-null successor 语义、callee-saved helper survival、stack spill/load alias、fixed-offset load 分类。任何一处放宽都会影响 hash/map-in-map safety。
- map value origin 必须区分 `BPF_PSEUDO_MAP_FD_VALUE` / `BPF_PSEUDO_MAP_IDX_VALUE` 和普通 map fd load；不要用 verifier `map_value` kind 单独决定 map id。
- loops / multiple reaching defs / stack alias overlap 必须保守返回 unknown。当前手写 scanner 是线性、带 budget 的；新 use-def/provenance cache需要显式处理 merge。
- kernel-mutable map 检测仍是 map_inline policy，不应被下沉成 generic BBProgram analysis。

### endian

- 当前 bounded scan 的 MAX_NARROW_SCAN 和 “遇到 jump/ldimm64/def 就停止” 是行为的一部分。用全局 use-def 替换时不能跨越这些局部边界。
- `read_before_endian` 只关心 narrowing fusion 前是否有 upper bits 可能被读；`uses_for_def` 可能返回窗口外 use，直接使用会过度保守。
- 这个 pass 没有 reg state machine，适合在 use-def convenience 稳定后做清理，不应阻塞 V5 主线。
