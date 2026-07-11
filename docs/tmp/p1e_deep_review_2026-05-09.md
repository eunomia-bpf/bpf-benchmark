# bpfopt 深度 review (2026-05-09)

## 总览
- 范围：`bpfopt/crates/bpfopt/src/` 全树，只读 review。
- 文件数：48 个 `.rs` 文件；排除 `*_tests.rs` 后 29 个。
- LOC：全树 29,334 LOC；排除 `*_tests.rs` 后 19,586 LOC；`passes/` 非测试源码 13,915 LOC。
- pass 数：`PASS_REGISTRY` 当前是 15 个 pass，不是 13 个：`noop` / `map_inline` / `const_prop` / `dce` / `skb_load_bytes_spec` / `bounds_check_merge` / `wide_mem` / `bulk_memory` / `rotate` / `cond_select` / `ccmp` / `extract` / `endian_fusion` / `branch_flip` / `prefetch`。
- 整体架构评分：
  - 清晰度：7/10。P1-C 之后 `RewritePlan`、`insn_width`、kop proof/remap 已经有共享骨架，但 `map_inline.rs` 仍然是超大单体。
  - 复用度：5/10。扫描、branch target、subprog、payload pack、packet pointer state、map ref decode 仍然在多处重复。
  - 健壮性：5/10。主要风险在 branch offset 宽度、metadata remap 链、path-insensitive scan、以及 pass-level fail-fast 不一致。

## 维度 1：跨 pass 重复

### 重复-1: site scan loop 模式重复
- 重复出现位置：
  - `bpfopt/crates/bpfopt/src/passes/rotate.rs:237`
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:256`
  - `bpfopt/crates/bpfopt/src/passes/extract.rs:74`
  - `bpfopt/crates/bpfopt/src/passes/endian.rs:77`
  - `bpfopt/crates/bpfopt/src/passes/ccmp.rs:287`
  - `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:279`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:57`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:390` and `bpfopt/crates/bpfopt/src/passes/prefetch.rs:487`
  - `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:103`
  - `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:225`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:465`
- 问题：每个 pass 都手写 `pc` loop、`LD_IMM64` 跨双槽步进、branch target stop 条件、局部 state advance。重复造成 bug 修复不能自然扩散，例如 JA32、subprog boundary、branch target handling。
- 建议抽出 API：
  - `InsnCursor::new(insns).next_pc_width()` 统一处理 `insn_width`。
  - `scan_sites(insns, cfg, matcher)`，matcher 返回 `Option<Site>` 和 `Advance::{ByInsn, ByRange}`。
  - 对 stateful scan 提供 `LinearScanState<T>::advance(insn, pc, effects)`。
- 收益估算：节省约 200 到 350 LOC；更重要的是 JA32 / `LD_IMM64` / branch target 修复只需要改一处。
- 优先级：P1。

### 重复-2: branch target、branch fixup、branch range 判断重复
- 重复出现位置：
  - `bpfopt/crates/bpfopt/src/analysis/branch_target.rs:27`
  - `bpfopt/crates/bpfopt/src/analysis/cfg.rs:47` and `bpfopt/crates/bpfopt/src/analysis/cfg.rs:131`
  - `bpfopt/crates/bpfopt/src/passes/rewrite.rs:16`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:106`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:265` and `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:398`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5217`
  - `bpfopt/crates/bpfopt/src/passes/ccmp.rs:350`
  - `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:546`
- 问题：多处都把 branch target 写成 `pc + 1 + off`，并且都假设 offset 是 `i16`。`analysis/branch_target.rs` 已经有部分能力，但 pass 里仍在重做。
- 建议抽出 API：
  - `BranchKind::{Cond16, Ja16, Ja32, PseudoCall, PseudoFunc}`
  - `decode_branch(insns, pc) -> Option<BranchInfo>`
  - `BranchInfo::target_pc()` 和 `BranchInfo::rewrite_offset(new_pc, new_target) -> Result<BpfInsn>`
  - `has_external_branch_target(range, allowed_internal_targets)`
- 收益估算：节省约 120 LOC；消除 JA32/i16 truncation 类 correctness bug。
- 优先级：P0。

### 重复-3: register use/def/kill 和小型数据流分析重复
- 重复出现位置：
  - 共享实现：`bpfopt/crates/bpfopt/src/analysis/liveness.rs:60`
  - pass 内重复：`bpfopt/crates/bpfopt/src/passes/endian.rs:233`
  - `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:769` and `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:797`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:774`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5456`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:526`
  - `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:225`
  - `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:467`
- 问题：`cond_select`、`ccmp`、`bulk_memory` 等 pass 需要判断临时寄存器、site 内 conflict、helper clobber，但实际有的用 `LivenessAnalysis`，有的本地写 `writes_reg`、`reg_write_kind`、constant state。
- 建议抽出 API：
  - `InsnEffects { uses, defs, clobbers, memory_base, stack_range }`
  - `RegValueAnalysis<T>` 用于 constant / packet pointer / stack provenance 的 shared transfer skeleton。
  - `site_uses_or_defs(site_range, regs, effects)`。
- 收益估算：节省约 250 LOC；减少 helper call 后 R0-R5 kill、R10 frame pointer、MOV K 读 dst 等规则漂移。
- 优先级：P1。

### 重复-4: map reference pattern 匹配重复且不一致
- 重复出现位置：
  - `bpfopt/crates/bpfopt/src/pass.rs:938`
  - `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:134`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4104`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4207`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4663`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5232`
- 问题：`build_map_fd_bindings` 只识别 `BPF_PSEUDO_MAP_FD` 和 `BPF_PSEUDO_MAP_VALUE`，而 `map_inline` 另有逻辑识别 `BPF_PSEUDO_MAP_IDX` / `BPF_PSEUDO_MAP_IDX_VALUE`。同一类 map ref 的 decode 规则分裂。
- 建议抽出 API：
  - `MapRefKind::{Fd, FdValue, Idx, IdxValue}`
  - `MapRef::decode_ldimm64(insns, pc) -> Option<MapRef>`
  - `MapRefResolver::resolve(map_ref, map_ids, map_fd_bindings) -> Result<MapId>`
- 收益估算：节省约 80 LOC；修复 IDX canonical map ref 在 shared provider 层解析不全的问题。
- 优先级：P0。

### 重复-5: kop target availability check 重复
- 重复出现位置：
  - `bpfopt/crates/bpfopt/src/passes/rotate.rs:79` and `bpfopt/crates/bpfopt/src/passes/rotate.rs:127`
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:129` and `bpfopt/crates/bpfopt/src/passes/cond_select.rs:163`
  - `bpfopt/crates/bpfopt/src/passes/ccmp.rs:165`
  - `bpfopt/crates/bpfopt/src/passes/extract.rs:131`
  - `bpfopt/crates/bpfopt/src/passes/endian.rs:270`
  - `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:231`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:240`
  - `bpfopt/crates/bpfopt/src/pass.rs:1610`
- 问题：`PassMetadata` 已经有 `kop_targets`，但 `PassManager::run` 没有统一 gate；每个 pass 自己决定 skip 或 per-site skip，行为和 diagnostics 不一致。
- 建议抽出 API：
  - `BpfPass::kop_requirement() -> KopRequirement`
  - `KopRequirement::{All(&[target]), Any(&[target]), PerSite(&[target])}`
  - `PassManager` 在 pass 运行前自动返回 `PassResult::skipped`，per-site pass 仍可在 site 层细分。
- 收益估算：节省约 60 LOC；skip reason 统一，避免 pass 忘记检查 target。
- 优先级：P1。

### 重复-6: subprog boundary / prologue / epilogue 检测重复
- 重复出现位置：
  - `bpfopt/crates/bpfopt/src/pass.rs:452` and `bpfopt/crates/bpfopt/src/pass.rs:530`
  - `bpfopt/crates/bpfopt/src/analysis/cfg.rs:47`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:689`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4871`
  - `bpfopt/crates/bpfopt/src/passes/rotate.rs:142`
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:179`
  - `bpfopt/crates/bpfopt/src/passes/ccmp.rs:212`
  - `bpfopt/crates/bpfopt/src/passes/extract.rs:159`
  - `bpfopt/crates/bpfopt/src/passes/endian.rs:440`
- 问题：`CFGAnalysis` 已经能识别 pseudo call 和 `LD_IMM64 BPF_PSEUDO_FUNC` subprog entry，但 `map_inline::subprog_bounds` 只看 pseudo call；kop pass 又通过 `kop_replacement_subprog_skip_reason` 每次重算 `BpfProgram::new(insns.to_vec())`。
- 建议抽出 API：
  - `SubprogIndex::build(&[BpfInsn])`
  - `SubprogIndex::bounds(pc) -> Range<usize>`
  - `SubprogIndex::replacement_skip_reason(range, replacement_len)`
  - `PassContext` 或 `AnalysisCache` 提供 cached `CFGResult`。
- 收益估算：节省约 100 LOC；消除 pseudo func callback subprog boundary 漏识别。
- 优先级：P1。

### 重复-7: PC range / overlap / commit / cleanup 链重复
- 重复出现位置：
  - 共享实现：`bpfopt/crates/bpfopt/src/passes/rewrite.rs:90`
  - 手写 commit：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:337`
  - 手写 commit：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2879`
  - DCE 手写删除：`bpfopt/crates/bpfopt/src/passes/dce.rs:230`
  - bounds cleanup 链：`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:187`
- 问题：`RewritePlan` 已处理 ascending non-overlap、addr_map、branch fixup、BTF remap，但 branch_flip/map_inline/dce/bounds 仍然有自定义提交路径，导致 metadata remap 和 branch fixup 语义不一致。
- 建议抽出 API：
  - `RewritePlan` 支持 `replace_many/delete_many/cleanup(Unreachable|Nop)`。
  - `RewriteCommit { addr_map, intermediate_map, final_map }` 统一组合 cleanup addr_map。
  - 所有 pass 禁止直接构造 `new_insns`，除非有明确 escape hatch。
- 收益估算：节省约 180 LOC；重点收益是避免 bounds_check_merge 这类 cleanup 后漏 BTF remap。
- 优先级：P0。

### 重复-8: kop sidecar payload 编码/解码重复
- 重复出现位置：
  - decode helper：`bpfopt/crates/bpfopt/src/pass.rs:102`
  - rotate pack：`bpfopt/crates/bpfopt/src/passes/rotate.rs:174`
  - cond_select pack：`bpfopt/crates/bpfopt/src/passes/cond_select.rs:236`
  - extract pack：`bpfopt/crates/bpfopt/src/passes/extract.rs:191`
  - endian pack：`bpfopt/crates/bpfopt/src/passes/endian.rs:276`
  - ccmp pack：`bpfopt/crates/bpfopt/src/passes/ccmp.rs:361`
  - bulk_memory pack：`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:590`
  - prefetch pack：`bpfopt/crates/bpfopt/src/passes/prefetch.rs:218`
- 问题：每个 kop pass 自己 `shift + or`，proof decode 又集中在 `pass.rs::remap_kop_btf_metadata`。新增 payload 字段时很容易 encode/decode 不同步。
- 建议抽出 API：
  - `KopPayloadBuilder::new().reg("dst", reg, shift).u8(...).s16(...)`
  - 或每类 kop 一个 typed payload，统一实现 `encode()` / `decode()` / `proof_len()`.
- 收益估算：节省约 90 LOC；把 payload reserved-bit validation 和 BTF proof region 一起测试。
- 优先级：P1。

### 重复-9: packet ctx layout 与 packet pointer state 重复
- 重复出现位置：
  - `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:13`
  - `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:467`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:23`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:522`
  - `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:12`
  - `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:93`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:422`
- 问题：多个 pass 都需要 `ctx->data` / `ctx->data_end` offset 和 packet pointer provenance，但各自维护支持的 prog_type、寄存器 state、clear-on-branch-target 策略。
- 建议抽出 API：
  - `PacketCtxLayout::for_prog_type(prog_type) -> Option<PacketCtxLayout>`
  - `PacketPointerAnalysis` 产出 per-PC register packet provenance。
  - pass 只消费 analysis，不再本地扫描 ctx load。
- 收益估算：节省约 220 LOC；prog_type 支持范围不再漂移。
- 优先级：P1。

### 重复-10: pass-local JSON/CLI 解析工具重复
- 重复出现位置：
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:61`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:190`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:71`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:169`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:62`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:953`
- 问题：每个 arg-taking pass 都本地写 `--flag value` parser 和 `read_json_file`。
- 建议抽出 API：
  - `PassArgs::new(args).required_path("--profile-json")`
  - `read_json<T>(path, label) -> anyhow::Result<T>`
- 收益估算：节省约 40 LOC；错误信息统一。
- 优先级：P2。

## 维度 2：bad style

### Style-1: `passes/mod.rs` 使用 `#[rustfmt::skip]` 压缩核心 registry
- 位置：`bpfopt/crates/bpfopt/src/passes/mod.rs:86`, `bpfopt/crates/bpfopt/src/passes/mod.rs:138`, `bpfopt/crates/bpfopt/src/passes/mod.rs:146`
- 问题：核心 registry、metadata struct、macro 输出都被压在单行里。这里是新 pass 的入口，单行写法降低 review 可读性，也让 metadata flag 更难审。
- 改法建议：去掉 `rustfmt::skip`，把 `PassMetadata`、macro 输出、`PASS_REGISTRY` 按正常 Rust 格式展开。
- 优先级：P2。

### Style-2: `KopDescriptor::probe_aliases()` 每次分配 `Vec`
- 位置：`bpfopt/crates/bpfopt/src/pass.rs:33`
- 问题：`probe_aliases(self) -> Vec<&'static str>` 为 1 或 2 个静态别名分配 `Vec`，serde 路径 `bpfopt/crates/bpfopt/src/pass.rs:56` 也会触发。
- 改法建议：返回 `&'static [&'static str]`，或实现小型 iterator；aliases 在 descriptor 层静态存储。
- 优先级：P2。

### Style-3: analysis 调用为了借用切片反复 `to_vec()`
- 位置：
  - `bpfopt/crates/bpfopt/src/pass.rs:454`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:62`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:189`
- 问题：这些路径只是要跑 CFG/Liveness，却构造 `BpfProgram::new(insns.to_vec())`。对大程序是无意义 clone，也让 helper 看起来拥有程序。
- 改法建议：让 `CFGAnalysis` / `LivenessAnalysis` 增加 `run_on_insns(&[BpfInsn])`，或把 `Analysis::run` 的输入抽象成只读 program view。
- 优先级：P2。

### Style-4: map lookup 热路径为 key 分配 `Vec`
- 位置：`bpfopt/crates/bpfopt/src/pass.rs:803`
- 问题：`program.map_values.get(&(map_id, key.to_vec()))` 每次 lookup 都复制 key。`MapProvider::lookup_elem` 是 pass hot path，尤其 map_inline fixed-point 会多轮调用。
- 改法建议：把 `map_values` 改成两级 map：`HashMap<u32, HashMap<Vec<u8>, Vec<u8>>>`，内层可用 borrowed lookup；或者用支持 borrowed key 的 newtype。
- 优先级：P2。

### Style-5: `CompressedMapValues::lookup` 返回 owned `Vec<u8>`
- 位置：`bpfopt/crates/bpfopt/src/pass.rs:667`
- 问题：raw bytes 只读场景返回 `Option<Vec<u8>>`，调用方即使只读也必须 clone。
- 改法建议：返回 `Option<&[u8]>`；如果有 overlay 需要构造值，再用 `Cow<'_, [u8]>`。
- 优先级：P2。

### Style-6: `wide_mem` 使用 stringly-typed `Binding`
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:19`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:318`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:526`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:560`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:596`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:628`
- 问题：一个 pass 内部用 `Binding { name: String, value: i64 }`，然后到处 `get_binding("width").unwrap_or(0)`。这既有 allocation，也把缺失字段降级成 sentinel。
- 改法建议：改为 typed struct，例如 `WideMemSite { start_pc, old_len, dst_reg, base_reg, base_off, width, ... }`；缺字段应在 scanner 构造时 impossible。
- 优先级：P1。

### Style-7: `const_prop` replacement clone 不必要
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/const_prop.rs:418`
  - `bpfopt/crates/bpfopt/src/passes/const_prop.rs:818`
- 问题：`rewrite_plan.replacements.iter()` 后把 `replacement.new_insns.clone()` 传入 `RewritePlan`；`replacement_if_changed` 又把 owned candidate 转回 `to_vec()`。
- 改法建议：`ConstPropRewritePlan` 消费式 `into_iter()` 提交；`replacement_if_changed` 返回 `bool` 或直接接收/返回 owned `Vec<BpfInsn>`。
- 优先级：P2。

### Style-8: `map_inline.rs` 单文件职责过多
- 位置：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1`
- 问题：单文件 5,493 LOC，混合 CLI arg、JSON snapshot、hint validation、key extraction、alias analysis、fixed-point loop、rewrite commit、diagnostics。局部 helper 很难判断哪些是 pass invariant，哪些是 parser/IO 细节。
- 改法建议：拆成明确模块：`snapshot.rs`、`hints.rs`、`key.rs`、`analysis.rs`、`rewrite.rs`。不要新增无语义的 `utils.rs`。
- 优先级：P1。

### Style-9: error type 不一致
- 位置：
  - `bpfopt/crates/bpfopt/src/pass.rs:679`
  - `bpfopt/crates/bpfopt/src/pass.rs:702`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1692`
  - `bpfopt/crates/bpfopt/src/passes/rewrite.rs:112`
- 问题：同一层级同时使用 `anyhow::Result`、`Result<_, String>`、自定义 enum，再由上层拼接 context。错误边界不清，导致部分错误能带上下文，部分只能带字符串。
- 改法建议：pass 内部统一 `anyhow::Result`，可恢复/分类错误使用 `thiserror` 或小 enum；`MapProvider` 不要返回裸 `String`。
- 优先级：P2。

### Style-10: helper 可见性偏宽
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/rewrite.rs:16`
  - `bpfopt/crates/bpfopt/src/passes/rewrite.rs:71`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:57`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:151`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:169`
- 问题：这些 helper 都只在 crate 内 pass 层使用，但暴露为 `pub`。这扩大了 API 面，也让未来外部调用依赖未稳定语义。
- 改法建议：改为 `pub(crate)` 或 `pub(super)`；真正需要跨 crate 的再显式保留。
- 优先级：P2。

### Style-11: 冗长 doc/comment 和代码重复说明
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:334`
  - `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:577`
  - `bpfopt/crates/bpfopt/src/passes/noop.rs:2`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:17`
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:32`
- 问题：不少注释是在解释代码下一行就能读出的事实，或者重复 pass 名称/目标。与 CLAUDE.md “Default to writing no comments” 不一致。
- 改法建议：保留不变量、ABI、correctness proof、非显然安全条件；删掉描述性 prose。
- 优先级：P2。

### Style-12: `branch_flip` unwrap 和裸 cast 离 invariant 太远
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:361`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:364`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:375`
- 问题：`invert_jcc_op(...).unwrap()` 依赖 scan 阶段已经过滤；offset 用 `as i16` 依赖 block length 可编码。对 review 来说，safety invariant 不在使用点。
- 改法建议：使用 `let Some(new_op) = ... else { bail!(...) };`；offset 用 `i16::try_from(...)`，失败时 skip site 或 error。
- 优先级：P1。

### Style-13: `read_json_file` 和 CLI parser 局部复制
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:97`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:190`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:103`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:169`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:112`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:953`
- 问题：重复 parser 容易导致 flag 缺值、unknown flag、JSON context message 漂移。
- 改法建议：共享 `PassArgs` 和 `read_json<T>`。
- 优先级：P2。

### Style-14: platform capabilities 有 dead-field 味道
- 位置：`bpfopt/crates/bpfopt/src/pass.rs:1347`
- 问题：`has_bmi1`、`has_bmi2`、`has_movbe`、`has_rorx` 主要由 `main.rs` 和测试写入，pass 内实际 target availability 仍依赖 kop registry。当前只有 `has_cmov` 被 `PassContext::has_branchless_select()` 使用。
- 改法建议：要么 pass 明确消费 platform feature，要么把 feature probing 降到 diagnostics，不作为 `PassContext` public surface。
- 优先级：P2。

## 维度 3：算法缺陷

### 缺陷-1: branch fixup 全部按 i16 `off` 处理，漏 JA32 并可能截断 offset
- 缺陷描述：`BpfInsn::is_ja()` 把 `BPF_JMP32 | BPF_JA` 也归为 JA，但 `fixup_all_branches` 对所有非 call/exit jump 都读写 `off: i16`。多个 CFG/branch target 入口也同样只看 `off`。
- 位置：
  - `bpfopt/crates/bpfopt/src/insn.rs:267`
  - `bpfopt/crates/bpfopt/src/passes/rewrite.rs:48`
  - `bpfopt/crates/bpfopt/src/analysis/branch_target.rs:35`
  - `bpfopt/crates/bpfopt/src/analysis/cfg.rs:67`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:106`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5217`
- 触发条件 + 输入例子：程序含 `BPF_JMP32 | BPF_JA`，target 编码在 `imm`，或 rewrite 后 conditional/JA offset 超过 i16。
- 当前行为 vs 应有行为：当前会用 `off` 算 target，并把新 offset `as i16` 截断；应区分 `Ja16` 和 `Ja32`，分别使用 `off`/`imm`，并对不可编码 offset fail-fast 或 skip site。
- 优先级：P0。

### 缺陷-2: `branch_flip` 新 offset 用裸 `as i16`，大 diamond 可生成错误跳转
- 缺陷描述：flip 后的 `jcc.off = else_len + 1`、`ja.off = then_len` 没有范围检查。
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:364`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:375`
  - `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:465`
- 触发条件 + 输入例子：原程序合法但 else block 长度为 32,767 条，原 `JA off=32767` 可编码；flip 后 `jcc.off=32768`，`as i16` 变成负数。
- 当前行为 vs 应有行为：当前生成 wraparound branch；应在 scan 或 emit 阶段 `i16::try_from`，不可编码则 skip，并记录 skip reason。
- 优先级：P0。

### 缺陷-3: `bounds_check_merge` cleanup 后没有 remap BTF metadata
- 缺陷描述：主 rewrite 用 `BtfRemapPolicy::NoRemap` commit，随后调用 `eliminate_unreachable_blocks` 和 `eliminate_nops` 只 remap annotations，不 remap `func_info` / `line_info`。
- 位置：`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:187`
- 触发条件 + 输入例子：带 line_info/func_info 的程序中，merge 删除后续 guard，并产生 unreachable block 或 NOP cleanup。
- 当前行为 vs 应有行为：当前 `program.insns` 已变化但 BTF offsets 仍对应旧 PC；应组合主 rewrite addr_map 与 cleanup addr_map，最后调用 `remap_btf_metadata`。
- 优先级：P0。

### 缺陷-4: `dce` pass 描述说移除 unreachable/NOP，实际只删 dead register defs
- 缺陷描述：registry description 是 “Remove CFG-unreachable blocks and NOPs after simplification”，但 `DcePass::run` 只调用 `eliminate_dead_register_defs`。
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/mod.rs:150`
  - `bpfopt/crates/bpfopt/src/passes/dce.rs:33`
  - helpers 存在但未被本 pass 使用：`bpfopt/crates/bpfopt/src/passes/dce.rs:57`, `bpfopt/crates/bpfopt/src/passes/dce.rs:151`
- 触发条件 + 输入例子：
  ```
  r0 = 1
  ja +1
  r0 = 2
  exit
  ```
  `r0 = 2` 对 exit live，但 CFG unreachable。
- 当前行为 vs 应有行为：当前 `dce` 单独运行不会删除 unreachable block / NOP；应先 unreachable cleanup，再 NOP cleanup，再 dead-def cleanup，并组合 addr_map。
- 优先级：P1。

### 缺陷-5: shared map fd binding 漏 `BPF_PSEUDO_MAP_IDX` / `IDX_VALUE`
- 缺陷描述：`BpfProgram::set_map_ids` 通过 `build_map_fd_bindings` 初始化 provider binding，但该函数只处理 FD/VALUE；`map_inline` 自己能处理 IDX/IDX_VALUE，shared layer 不能。
- 位置：
  - `bpfopt/crates/bpfopt/src/pass.rs:867`
  - `bpfopt/crates/bpfopt/src/pass.rs:938`
  - 对比完整处理：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:4104`
- 触发条件 + 输入例子：canonicalized bytecode 使用 `BPF_PSEUDO_MAP_IDX`，`map_ids = [100, 200]`，LDIMM64 imm=1 表示 map 200。
- 当前行为 vs 应有行为：当前 `map_fd_bindings` 不记录 idx->map_id，后续 snapshot lookup 可能无法解析；应统一用 `MapRef::decode_ldimm64` 支持四种 pseudo kind。
- 优先级：P0。

### 缺陷-6: `map_inline::subprog_bounds` 漏 `LD_IMM64 BPF_PSEUDO_FUNC` callback subprog
- 缺陷描述：CFGAnalysis 识别 `LD_IMM64` pseudo func 作为 subprog entry，但 map_inline 本地 `subprog_bounds` 只识别 `BPF_PSEUDO_CALL`。
- 位置：
  - 漏实现：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:4871`
  - 正确参考：`bpfopt/crates/bpfopt/src/analysis/cfg.rs:51`
- 触发条件 + 输入例子：callback subprog 由 `LD_IMM64 src=BPF_PSEUDO_FUNC imm=target` 引用，target 内有 map lookup；key setup 搜索可能向前跨过 callback entry。
- 当前行为 vs 应有行为：当前 bounds 可能返回 `(0, len)` 或错误 subprog range；应复用 `CFGResult.subprogs`。
- 优先级：P1。

### 缺陷-7: `map_inline` fixed-point hit cap 后只写 diagnostic，不 fail-fast
- 缺陷描述：fixed-point loop 最多 8 轮；如果第 8 轮仍 modified，只设置 `hit_iteration_cap` 并记录 diagnostic。
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2370`
  - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2409`
- 触发条件 + 输入例子：9 层 map-in-map chain，每轮 inline 后才暴露下一层；或迭代逻辑 bug 导致持续变化。
- 当前行为 vs 应有行为：当前返回成功但 bytecode 是部分优化结果；fail-fast 规则下应 `bail!`，至少不能静默成功。
- 优先级：P1。

### 缺陷-8: `extract` scanner 覆盖面过窄，漏 ALU32 和其他常见 bitfield idiom
- 缺陷描述：只匹配相邻 `BPF_ALU64 RSH imm` + `BPF_ALU64 AND imm`，且 proof 限制 `bit_len <= 32`。没有覆盖 `BPF_ALU` 32-bit 形式、`LSH; RSH` zero-extension idiom、mask 在 register 中的形式。
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/extract.rs:23`
  - `bpfopt/crates/bpfopt/src/passes/extract.rs:74`
- 触发条件 + 输入例子：
  ```
  r1 = (u32)r1
  r1 >>= 8       // BPF_ALU RSH K
  r1 &= 0xff     // BPF_ALU AND K
  ```
- 当前行为 vs 应有行为：当前不产生 extract site；应至少覆盖 ALU32 RSH/AND，若 kop 支持 64-bit extract 则 payload/proof 也不应硬拒 `bit_len > 32`。
- 优先级：P1。

### 缺陷-9: `endian_fusion` little-endian matcher 使用疑似无效 opcode
- 缺陷描述：`endian_swap_size` 接受 `BPF_ALU | BPF_END | BPF_TO_BE`，但 little-endian 分支写成 `BPF_ALU64 | BPF_END | BPF_TO_LE`。eBPF endian conversion 通常使用 `BPF_ALU | BPF_END | BPF_TO_LE/BE`。
- 位置：`bpfopt/crates/bpfopt/src/passes/endian.rs:152`
- 触发条件 + 输入例子：
  ```
  r1 = *(u32 *)(r2 + 0)
  r1 = le32 r1   // BPF_ALU | BPF_END | BPF_TO_LE
  ```
- 当前行为 vs 应有行为：当前会漏掉合法 LE endian op，并可能匹配不应出现的 ALU64 encoding；应使用 `BPF_ALU` class 识别 BE/LE，或如果 pass 只支持 BE，删除 LE 分支。
- 优先级：P1。

### 缺陷-10: `bounds_check_merge` interleave safety 没有显式禁止 root/data_end 被改写
- 缺陷描述：`can_extend_ladder` 依赖 scanner state 判断同 root，但 `is_merge_safe_interleave` 本身允许 ALU/LDX 写任意寄存器，没有显式排除 `root_reg` / `data_end_reg`。
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:389`
  - `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:416`
- 触发条件 + 输入例子：
  ```
  r2 = ctx->data
  r3 = ctx->data_end
  r4 = r2 + 14
  if r4 > r3 goto slow
  r2 += variable_or_alias
  r4 = r2 + 34
  if r4 > r3 goto slow
  ```
- 当前行为 vs 应有行为：scanner state 可能能挡住部分 case，但 safety predicate 本身没有表达这个不变量，也没有专门测试。应在 merge predicate 中显式 reject interleave 对 root/data_end 的 def，或增加证明性测试。
- 优先级：P1。

### 缺陷-11: packet/prefetch scan 是线性近似，容易漏 site，且规则与 CFG 不一致
- 缺陷描述：`scan_packet_deref_prefetch_sites` 线性扫描并只在 branch target 清状态；packet pointer provenance 没有真正按 CFG join/meet 计算。
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:487`
  - `bpfopt/crates/bpfopt/src/passes/prefetch.rs:547`
  - 类似模式：`bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:103`
- 触发条件 + 输入例子：
  ```
  r2 = ctx->data
  if cond goto L1
  r2 = ctx->data + 64
  L1:
  *(u64 *)(r2 + 8)
  ```
- 当前行为 vs 应有行为：当前在 branch target 清状态，可能漏掉两条路径都安全的 prefetch；更复杂 CFG 下不同 pass 的保守/激进程度会漂移。应改为 CFG 数据流 analysis，join 时只保留所有 predecessor 一致的 packet provenance。
- 优先级：P2。

### 缺陷-12: `prefetch` candidate 去重 key 过窄
- 缺陷描述：`dedup_candidates` 只按 `(insert_pc, ptr_reg)` 去重，没有包含 candidate kind、target_pc、subprog/range 信息。
- 位置：`bpfopt/crates/bpfopt/src/passes/prefetch.rs:789`
- 触发条件 + 输入例子：同一个 insert_pc、同一 ptr_reg 同时由 map-value deref 和 packet deref scanner 产生候选，或同一 target 通过不同 scanner path 产生候选。
- 当前行为 vs 应有行为：当前可能误删语义不同的候选，也可能保留同 target 不同 insert_pc 的重复 prefetch。应先按 CFG/subprog 分组，再按 `(target_pc, insert_pc, ptr_reg, kind)` 做 deterministic dedup。
- 优先级：P2。

### 缺陷-13: `bulk_memory` overlap 判断使用 raw run bytes，可能错过可安全重写的前缀
- 缺陷描述：`try_match_memcpy_run_at` 先收集 `raw_bytes`，再因尾部小于 `MIN_BULK_BYTES` 丢弃 tail；overlap check 却用丢弃前的 `raw_bytes`。
- 位置：
  - `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:360`
  - `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:378`
  - `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:665`
- 触发条件 + 输入例子：同 base copy 中前 32B 不 overlap，后 8B tail overlap 且会被 `trim_trailing_small_chunk` 丢弃。
- 当前行为 vs 应有行为：当前整段 skip，漏掉前 32B 的合法 bulk copy；应先计算 consumed chunks，再仅对 consumed byte range 做 overlap check。
- 优先级：P2。

### 缺陷-14: `liveness`/CFG 的 branch successor 没有统一处理 JA32 与 pseudo func
- 缺陷描述：`LivenessAnalysis::get_successors` 对 jump 只读 `off`；subprog/callback entry 的处理依赖 CFG，但 liveness 本身没有 subprog/call graph awareness。
- 位置：
  - `bpfopt/crates/bpfopt/src/analysis/liveness.rs:123`
  - `bpfopt/crates/bpfopt/src/analysis/cfg.rs:51`
- 触发条件 + 输入例子：`BPF_JMP32 | BPF_JA` 大跳转，或 callback subprog 中有 liveness-sensitive rewrite site。
- 当前行为 vs 应有行为：当前 successor set 可能错误，导致 temp reg live-after 判断过松或过紧；应基于同一个 `BranchInfo`/`CFGResult` 计算 liveness successor。
- 优先级：P1。

### 缺陷-15: proof region decode 与 per-pass payload encode 没有 compile-time 绑定
- 缺陷描述：`remap_kop_btf_metadata` 解码所有 kop payload，但 payload encode 分散在各 pass。新增字段时没有类型系统约束 encode/decode 同步。
- 位置：
  - decode：`bpfopt/crates/bpfopt/src/pass.rs:340`
  - encode examples：`bpfopt/crates/bpfopt/src/passes/ccmp.rs:361`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:590`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:218`
- 触发条件 + 输入例子：某 kop payload 新增 reserved bit 或 offset 字段，pass encode 更新但 `kop_proof_len` 没更新。
- 当前行为 vs 应有行为：当前只能靠测试覆盖；应每个 kop payload 有单一 typed definition，同时生成 encode/decode/proof_len。
- 优先级：P1。

## 整体推荐

### 短期 (1 round) 应做的 P0 修复
- 抽出统一 `BranchInfo`，修复 JA32 / i16 overflow / branch target 计算，并让 `rewrite.rs`、CFG、DCE、branch_flip、map_inline 共用。
- 修复 `bounds_check_merge` 的 BTF remap 链：主 rewrite 和 cleanup addr_map 必须组合后 remap metadata。
- 修复 map ref decode：shared `build_map_fd_bindings` 必须支持 FD/VALUE/IDX/IDX_VALUE，最好直接替换为 `MapRef::decode_ldimm64`。

### 中期 (3-5 round) 应做的 P1 重构
- 引入 `SubprogIndex`，删除 map_inline/prefetch/kop pass 的本地 subprog bounds 逻辑。
- 引入 `InsnEffects` 和 CFG 数据流 skeleton，统一 register use/def/kill、packet pointer state、constant state。
- 把 kop payload 做成 typed encode/decode/proof，一处定义覆盖 pass encode 和 BTF proof decode。
- 让 `PassManager` 根据 `PassMetadata.kop_targets` 做统一 kop availability gate。
- 拆分 `map_inline.rs`，但只按真实职责拆模块，不新增 dump-style `utils.rs`。

### 长期可选 P2
- 清理 `rustfmt::skip`、长注释、过宽 `pub`、热路径 clone/alloc。
- 统一 pass-local CLI/JSON parser。
- 把 prefetch / skb / bounds 的 packet ctx layout 做成共享 analysis。
- 给 const/map fixed-point 类 pass 增加明确收敛 cap 语义：收敛失败必须 error，不是 diagnostic 成功。

## 不变量
- 我没有改任何 `.rs` 文件。
- 我没有 commit。
- 我没有跑 `make`。
- 我只新增本报告：`docs/tmp/p1e_deep_review_2026-05-09.md`。
