# bpfopt pass architecture audit, 2026-05-08

## 1. Executive summary

bpfopt 现在已经有 LLVM pass framework 的外壳: `BpfPass`、`Analysis`、`AnalysisCache`、pass registry 和 per-pass metadata 都存在,但 transform 层仍主要是每个 pass 手写的线性 bytecode peephole。最大的重复不是某一个 opcode matcher,而是整套 rewrite 机械动作: 扫 site、排除跨 branch/subprog 的 unsafe range、构造 `new_insns + addr_map`、保护 `LD_IMM64` 双指令、fix branch offset、remap BTF/annotation。`map_inline.rs` 已经 5361 LOC,同时承担 side input 解析、map metadata、overlay/value 读取、hint 语义、verifier-state key extraction、alias/use 分析、branch patch 和实际 bytecode rewrite,复杂度已经超过单个 pass 文件的合理边界。analysis 层有 CFG/branch target/liveness,但不是 first-class enough: invalidation 是全清,verifier state 不是共享 oracle,branch target/subprog/use-def 仍在多个 pass 私有实现。建议用渐进式重构先抽 `RewriteBuilder` 和 `VerifierStateOracle`,再收敛 map reference/helper classifier 与小型 matcher,最后再机械拆分 `map_inline.rs`。

## 2. 重复造轮子清单

| 重复模式 | 具体位置 | 为什么是重复/风险 |
|---|---|---|
| `new_insns + addr_map + LD_IMM64 pair + fixup_all_branches + remap` rewrite loop | `passes/rotate.rs:120-167`, `passes/cond_select.rs:215-259`, `passes/extract.rs:171-213`, `passes/bulk_memory.rs:210-252`, `passes/ccmp.rs:240-299`, `passes/endian.rs:483-546`, `passes/wide_mem.rs:659-705`, `passes/const_prop.rs:420-450`, `passes/prefetch.rs:314-346`, `passes/map_inline.rs:2740-2802` | 同一个“单 site 替换/插入/删除并维护 PC mapping”的机械动作由每个 pass 维护。任何一个 pass 忘记 `LD_IMM64` second slot、BTF remap 或 annotation remap 都会产生局部 bug。 |
| rewrite helper 已有但未统一 | `passes/utils.rs:20-73` `fixup_all_branches`, `passes/utils.rs:711-723` `map_replacement_range`, `passes/utils.rs:973-1012` `eliminate_marked_insns`, `passes/utils.rs:1033-1084` `fixup_surviving_branches` | utils 提供了碎片工具,但没有一个“plan/apply/commit”抽象。`fixup_all_branches` 和 `fixup_surviving_branches` 还各自维护类似 branch rewrite 逻辑。 |
| custom branch patching | `passes/ccmp.rs:448-471`, `passes/branch_flip.rs:337-412`, `passes/map_inline.rs:3343-3399` | 插入的新 branch 无法由 `fixup_all_branches` 处理,于是每个 pass 自己记录 pending branch/new target。`branch_flip` 甚至先调用通用 fixup,再把 jcc/ja offset 写回。 |
| branch target 计算重复 | `analysis/branch_target.rs:31-43`, `analysis/cfg.rs:52-67`, `analysis/cfg.rs:145-154`, `analysis/liveness.rs:124-141`, `passes/ccmp.rs:374-377`, `passes/map_inline.rs:5078-5083` | 多处手写 `pc + 1 + off/imm`。这类代码本身短,但它是 CFG、liveness、candidate safety 和 rewrite fixup 的共同 ABI,重复后难以保证 pseudo-call、pseudo-func、conditional branch 语义一致。 |
| interior branch target safety filter 重复 | `passes/rotate.rs:49-63`, `passes/extract.rs:133-146`, `passes/cond_select.rs:170-190`, `passes/ccmp.rs:187-198`, `passes/endian.rs:422-460`, `passes/wide_mem.rs:514-523`, `passes/branch_flip.rs:267-287` | kinsn/peephole pass 都在做“range 内部不能有外来 branch target,除非是自己的 branch target”判断。应是 rewrite/site safety 的共用 primitive,不是每个 pass 手写。 |
| kinsn replacement boilerplate 重复 | `passes/rotate.rs:9`, `passes/extract.rs:9`, `passes/cond_select.rs:11`, `passes/bulk_memory.rs:11`, `passes/ccmp.rs:9`, `passes/endian.rs:9`, `passes/prefetch.rs:16`; shared helpers 在 `passes/utils.rs:98-109`, `passes/utils.rs:725-777`, `passes/utils.rs:1115-1124` | 多个 kinsn pass 都重复 target availability、subprog boundary、sidecar/call emission、kinsn BTF remap。utils 有底层函数,但没有“构造一个 kinsn site rewrite”的更高层对象。 |
| map id/map reference 解析重复 | `pass.rs:436-462`, `passes/map_inline/map_info.rs:148-235`, `passes/map_inline.rs:3964-3981`, `passes/map_inline.rs:4063-4148`, `passes/map_inline.rs:1633-1701` | `BPF_LD_IMM64_RAW(BPF_PSEUDO_MAP_FD/IDX/MAP_VALUE/IDX_VALUE)` 和 helper arg map ref 的解析分散在 framework、MapInfoAnalysis、map_inline direct-value path、kernel-writer filter 中。map-in-map/outer-only fold 继续增加重复面。 |
| helper id classifier 私有硬编码 | `passes/map_inline.rs:25-28`, `passes/map_inline.rs:1703-1718`, `passes/map_inline.rs:5066` | `map_lookup/update/delete/ktime` helper id 在 pass 内硬编码,而不是集中使用 `kernel_sys`/libbpf-sys 常量和 helper classifier。这也让 map writer filter、lookup site scan、helper side-effect 判断分散。 |
| verifier-state oracle 私有实现 | `passes/const_prop.rs:33-38`, `passes/const_prop.rs:131-216`, `passes/map_inline.rs:1146-1348`, `passes/map_inline.rs:1541-1547`, `passes/wide_mem.rs:622-635` | const_prop 的 exact scalar oracle 是私有的; map_inline 另写 stack-byte/key extraction 和 scalar check; wide_mem 直接读 verifier states 来避开 BTF pointer rewrite。#251/#252 已证明这类 provenance guard 是跨 pass 需求。 |
| 常量计算/常量 materialization 重复 | `passes/const_prop.rs:661-758`, `passes/const_prop.rs:831-848`, `passes/map_inline.rs:4049-4061`, `passes/map_inline.rs:4665-4729`, `passes/map_inline.rs:4301-4422` | const_prop 与 map_inline 都有 ALU constant evaluation、`LD_IMM64` decode、constant load emission。一个是 forward dataflow,一个是 backward resolver,但共享的 primitive 没有抽出来。 |
| register use/def/effect 重复 | `analysis/liveness.rs:61-121`, `passes/prefetch.rs:806-819`, `passes/map_inline.rs:5324-5357` | liveness 已有 `insn_use_def`,但 map_inline 和 prefetch 仍维护私有 register read/write classifier。随着 helper clobber、callee-saved、pointer provenance 判断增加,重复会继续扩大。 |
| subprog bounds/insn stepping 重复 | `analysis/cfg.rs:180-192`, `passes/prefetch.rs:721-737`, `passes/map_inline.rs:4732-4759`; manual `LD_IMM64` stepping 分布在多处 rewrite loop | CFG 已经知道 subprog ranges,但 pass 仍私有计算。`LD_IMM64` width 处理也应该通过 iterator/rewriter 统一,而不是每个 loop 手写。 |
| soft fold key compare emission 是 pass-local mini codegen | `passes/map_inline.rs:3117-3259`, `passes/map_inline.rs:3297-3354` | 软 fold 生成 key compare bytecode、记录 mismatch branch、再 patch relative jump。这本质是通用“emit guarded fast path + fallback/NULL path”的 builder,现在和 map_inline 业务逻辑混在一起。 |
| metadata remap 责任不统一 | `passes/dce.rs:40-42`, `passes/const_prop.rs:448-450`, `passes/wide_mem.rs:703-705` 会 remap BTF; `passes/skb_load_bytes.rs:82-87`, `passes/bounds_check_merge.rs:232-233` 只 remap annotations | 不一定每个 pass 当前都需要 BTF,但“变更 insn count 后是否 remap BTF”不应靠 pass 作者记忆。rewrite commit 层应显式声明 BTF remap policy,否则容易漏。 |

## 3. 抽象缺口清单

1. **RewriteBuilder / RewritePlan**

   缺少一个表示“在 old PC range 上替换/插入/删除 N 条指令,并自动修复 branch target、`LD_IMM64` pair、BTF、annotations”的对象。现在各 pass 持有 `BTreeMap<pc, replacement>` 或 `Vec<site>`,再复制几乎相同的 apply loop。建议抽象出:

   - `replace_range(start_pc, old_len, replacement)`
   - `insert_before(pc, replacement)`
   - `delete_range(start_pc, old_len)`
   - `add_internal_branch_patch(new_branch_label, target_label 或 old_target_pc)`
   - `commit(program, btf_policy, cleanup_policy) -> PassResult`

2. **统一 branch target / instruction cursor**

   `pc + 1 + off/imm`、pseudo-call target、pseudo-func target、`LD_IMM64` width 现在散落在 analysis 与 pass。需要一个小型 `InsnCursor`/`BranchTarget` API: `iter_real_insns()`, `insn_width(pc)`, `jump_target(pc)`, `pseudo_call_target(pc)`, `set_relative_target(pc, target_pc)`。这不是大 IR,只是把 bytecode ABI 集中起来。

3. **轻量 pattern matcher**

   LLVM 的 `PatternMatch` 很强,但 bpfopt 不需要 expression-template 级别复杂度。当前真正需要的是小型 matcher:

   - `helper_call(BPF_FUNC_map_lookup_elem)`
   - `seq([rsh_imm(dst), and_imm(dst)])`
   - `branch_diamond(cond, mov_then, mov_else)`
   - `ldimm64_map_ref(dst)`
   - `stack_key_materialization(call_pc, arg_reg)`

   目标是减少 scan 函数里重复 opcode mask、寄存器关系和 width stepping。

4. **VerifierStateOracle as analysis**

   verifier states 是 v3 pipeline 的关键 side input,但当前只是 `BpfProgram.verifier_states` 上的原始数组。const_prop 私有 oracle、map_inline 私有 key extraction、wide_mem 直接读状态都说明应提升为 `analysis/verifier_state.rs`。API 应 fail-closed,至少提供:

   - `exact_scalar_after(pc, reg) -> Option<u64>`
   - `exact_scalar_before(pc, reg) -> Option<u64>`
   - `stack_bytes_at_call(pc, frame, fp_off, len) -> Option<Vec<u8>>`
   - `reg_type_after(pc, reg) -> Option<RegKind>`
   - `consensus_across_frames_or_occurrences(...)`

5. **MapRefAnalysis / HelperClassifier**

   map reference 不是 map_inline 私有概念。需要把 `FD/IDX/MAP_VALUE/IDX_VALUE` 解析、`map_ids` order/fd binding、map writer helper、read-only helper side effect 归入一个共享 analysis 或 utility。`map_inline/map_info.rs` 可以保留 map behavior policy,但 raw map ref discovery 应该独立。

6. **RegisterEffect / local dataflow primitive**

   `analysis/liveness.rs` 已有 `insn_use_def`,但 map_inline/prefetch 需要更多: helper clobber、callee-saved helper survival、stack spill/reload、pointer-origin tracing。可以先导出一个 conservative `RegisterEffect` API,不做 SSA,只统一“这条 insn 读/写/kill 哪些 reg,helper 有什么 clobber”。

7. **SiteDescriptor**

   每个 pass 都定义自己的 site struct,但共享字段高度一致: `start_pc`, `old_len`, `replacement_len`, `target_pc`, `subprog range`, `safety reason`, `diagnostic label`。可以引入小型公共 descriptor,pass-specific payload 继续本地保存。这样 interior-target/subprog-boundary/LD_IMM64-straddle checks 可以收敛到一处。

## 4. LLVM 对应物对比

| 维度 | LLVM 怎么做 | bpfopt 当前对应物 | 代码层差距 |
|---|---|---|---|
| Pass interface | New PM pass 对 IR unit 运行,返回 `PreservedAnalyses`; pass manager 用 preservation 做精确 invalidation。 | `BpfPass::run(&mut BpfProgram, &PassContext, &mut AnalysisCache)` 只返回 `PassResult`,见 `pass.rs:612-639`。 | `PassManager::run_single_pass` 只要 insns 变了就 `invalidate_all` 并清 verifier states,见 `pass.rs:930-951`。安全但粗,也没有 pass 声明“我 preserve CFG/branch target”。 |
| Analysis framework | `AnalysisManager` 按 IR unit 缓存结果,pass 通过 manager 取分析,由 preservation/invalidation 管理生命周期。 | `AnalysisCache` 按 `TypeId` 存结果,见 `pass.rs:488-534`; `Analysis` trait 见 `pass.rs:471-480`。 | 缺精确 invalidation;标准 analyses 主要在测试 helper 注册,见 `passes/mod.rs:181-195`。生产 pass 仍经常局部重算 branch/subprog/register effects。 |
| Instruction matching | LLVM 有 `InstVisitor`、`PatternMatch` 和 typed opcode/class API。 | `BpfInsn` 有基本 classifier/constructor,如 `is_cond_jmp`, `is_call`, `is_ldimm64`, `mov64_imm`, `ja`,见 `insn.rs:259-395`。 | pass 仍手写 sequence scan 和 opcode/register 关系。例: cond_select diamond scan 在 `passes/cond_select.rs:271-397`, branch_flip diamond scan 在 `passes/branch_flip.rs:458-510`, extract RSH/AND scan 在 `passes/extract.rs:58-97`。 |
| IR mutation / branch fixup | LLVM IR 使用 basic block terminator 和 CFG edge,大多数 branch target 是 block reference;替换 instruction 不需要手动重算 PC-relative offset。 | BPF 是线性 PC-relative bytecode。通用 branch fixup 在 `passes/utils.rs:20-73`,但只能修 old instruction surviving targets。 | 每个 pass 维护 `addr_map`,新插入 branch 还要 custom patch,如 `passes/map_inline.rs:3356-3399`、`passes/ccmp.rs:448-471`。这正是 `RewriteBuilder` 应该吸收的责任。 |
| Def-use / SSA | LLVM SSA 让 use-def chain 成为 IR 基础;替换 def 能定位 uses,许多 dataflow 自动基于 SSA。 | bpfopt 处理 register bytecode,reg 重用频繁,没有 SSA。liveness 以 bitset/hashset use-def 近似,见 `analysis/liveness.rs:61-121`。 | 不建议全套 SSA 化。但现在连 conservative register effect 都没有统一,导致 map_inline/prefetch 重写 use/def classifier。 |
| CFG analysis | LLVM 的 `DominatorTree`, `LoopInfo`, `BranchProbabilityInfo` 等是共享 analysis,多 pass 复用。 | `CFGAnalysis`, `BranchTargetAnalysis`, `LivenessAnalysis` 已存在,见 `analysis/cfg.rs`, `analysis/branch_target.rs`, `analysis/liveness.rs`。 | CFG 仍是 thin layer。subprog bounds、successor、branch target 在 pass 私有重复,如 `passes/map_inline.rs:4732-4759`、`passes/prefetch.rs:721-737`。 |
| Pass-local metadata | LLVM pass pipeline 通常通过 analysis result、IR metadata 或 pass option 管理,但 framework core 不 re-export 某个 transform 的私有类型。 | `pass.rs` re-export `MapInlineHint` 以维持 `use crate::pass::*`,见 `pass.rs:16-18`; `BpfProgram` 存 `map_inline_hints`,见 `pass.rs:89-123`。 | map_inline side input 泄漏到 framework core。已有注释承认这是 pass-local metadata,但边界仍被打穿。 |
| Target-specific lowering | LLVM 后端用 target hooks/pseudo inst/MC layer 管理 target lowering。 | bpfopt 有 kinsn target registry、`PassContext.target`,以及 `emit_packed_kinsn_call_with_off`/`remap_kinsn_btf_metadata` 等 shared utilities。 | kinsn pass 的 site safety、availability、replacement/remap 仍重复在每个 pass。可以先抽 `KinsnRewritePlan`,不需要 LLVM 后端复杂度。 |
| Profile-guided pass | LLVM PGO profile 是 analysis/metadata 输入,缺失 profile 通常按 pass policy 明确失败或降级。 | `branch_flip` 明确要求 per-site PMU 字段,缺失则 error,见 `passes/branch_flip.rs:222-255`。 | 这一点 bpfopt 方向是对的: fail-fast、无 heuristic fallback。应把这种“profile/verifier oracle 是 first-class input”的思想推广到 verifier-state oracle。 |

## 5. 我们做的为什么不好

1. **正确性负担落在每个 pass 作者身上**

   任何会改变 insn count 的 pass 都必须同时处理 `LD_IMM64` 双指令、branch offset、BTF remap、annotation remap、analysis invalidation。现在已经能看到责任不统一: `dce`, `const_prop`, `wide_mem` 会 remap BTF,但 `skb_load_bytes_spec` 和 `bounds_check_merge` 的 commit path 只 remap annotations。即使当前测试能过,这也是一个维护陷阱。

2. **`map_inline.rs` 已经不是单一 pass 逻辑**

   5361 LOC 的 `map_inline.rs` 同时做 map lookup site 识别、map-in-map chain、constant key extraction、verifier stack bytes、compressed overlay/value 读取、kernel-write filter、hard fold、soft fold、outer-only fold、branch patch、fixed-point accounting 和 diagnostics。#244/#245/#247/#249/#251/#252/#254 这些迭代都压到同一个文件后,局部修改很容易撞到无关路径。

3. **verifier state 的抽象层级太低**

   v3 设计已经规定 `map_inline`/`const_prop` 的 verifier states 来自真实 per-pass ReJIT log,见 `CLAUDE.md:99` 和 `docs/kernel-jit-optimization-plan.md:352-409`。但代码层只给 pass 一个原始 `program.verifier_states`;const_prop 自己建 exact scalar oracle,map_inline 自己读 stack key,wide_mem 自己检查 BTF ptr。#251/#252 的 const_prop guard 说明 verifier provenance 不是 const_prop 私事,而是多个 pass 的共同安全 oracle。

4. **address map 语义不统一**

   普通 kinsn pass 用 `map_replacement_range`; wide_mem 把整个 old range 映射到一个 new pc; endian 需要 copy middle 的 custom mapping; map_inline 还叠加 skip_pcs、replacement_new_pcs、cleanup map 和 replacement branch patches。这些都是合理需求,但不应分散表达。统一 plan 可以让“old pc 到 new pc 的语义”显式化。

5. **framework/pass 边界仍有泄漏**

   `pass.rs` re-export map_inline hint type 并在 `BpfProgram` 存 pass-local hint。虽然这是为了兼容 `use crate::pass::*`,但架构上等于让 framework core 知道某个具体 pass 的 option shape。后续如果 branch_flip/profile hint 或 prefetch hint 也这么做,core 会继续膨胀。

6. **analysis cache 安全但不经济**

   `run_single_pass` 一旦发现 bytecode 变化就全量 invalidation 并清空 verifier states。这符合 fail-fast,但会让 pass 更倾向自己临时计算小分析,因为复用 analysis 没有 preservation 契约。短期不是性能问题,而是架构压力: 共享分析存在,但 pass 不自然地依赖它。

7. **hard-coded helper id 与 syscall/type 统一原则相冲突**

   `map_inline.rs` 私有硬编码 `HELPER_MAP_LOOKUP_ELEM = 1`, `UPDATE = 2`, `DELETE = 3`, `KTIME = 5`。项目规则要求尽量使用 libbpf/libbpf-sys/kernel-sys re-export 的类型和常量。这里应集中成 helper classifier,否则 map writer filter、lookup scan、helper side-effect policy 会继续复制 magic number。

## 6. 改进路径

### P0. 抽 `RewriteBuilder` / `RewritePlan`

把 `passes/utils.rs` 中零散的 `fixup_all_branches`, `map_replacement_range`, `compose_addr_maps`, `remap_btf_metadata` 包成一个统一 commit 层。先支持 replace/delete/insert 和 internal branch patch,再让 `const_prop`, `skb_load_bytes_spec`, `bounds_check_merge`, `map_inline` hard/direct fold 迁入;第二批迁 kinsn passes。

- 影响文件: 新增 `bpfopt/crates/bpfopt/src/passes/rewrite.rs` 或扩展 `passes/utils.rs`;迁移 `const_prop.rs`, `skb_load_bytes.rs`, `bounds_check_merge.rs`, `map_inline.rs`,后续 `rotate.rs`/`extract.rs`/`cond_select.rs`/`bulk_memory.rs`/`ccmp.rs`/`endian.rs`/`wide_mem.rs`/`prefetch.rs`。
- 行数估计: 新增 250-400 LOC;删除/收敛 500-800 LOC 重复 apply loop 和 branch patch boilerplate。
- 风险: branch offset、`LD_IMM64` pair、BTF remap policy、cleanup map composition 都可能影响现有 pass。应先用现有 branch fixup/unit tests 覆盖,再一次迁一个 pass,每次保持输出 bytecode 等价。

### P0. 提升 `VerifierStateOracle` 到 analysis 层

把 const_prop 的 exact scalar oracle、map_inline 的 stack key/verifier scalar extraction、wide_mem 的 verifier type guard 收敛成 `analysis/verifier_state.rs`。API 必须 fail-closed: state 缺失或不一致返回 `None`/error reason,不能 heuristic fallback。

- 影响文件: 新增 `bpfopt/crates/bpfopt/src/analysis/verifier_state.rs`;修改 `passes/const_prop.rs:33-216`, `passes/map_inline.rs:1146-1348`, `passes/map_inline.rs:1541-1547`, `passes/wide_mem.rs:622-635`。
- 行数估计: 新增 250-350 LOC;删除/替换 200-300 LOC 私有 verifier parsing/checking。
- 风险: oracle 语义如果比旧实现更保守,`map_inline` applied site 或 `const_prop` fold 数可能下降。必须保持 #251/#252 的 pointer-provenance guard,并用 katran hard/soft/outer-only cases 回归。

### P1. 抽 `MapRefAnalysis` 和 helper classifier

把 map reference discovery 从 map_inline 里拆出来,覆盖 `BPF_PSEUDO_MAP_FD`, `BPF_PSEUDO_MAP_IDX`, `BPF_PSEUDO_MAP_VALUE`, `BPF_PSEUDO_MAP_IDX_VALUE` 以及 helper arg map ref。helper classifier 使用 `kernel_sys`/libbpf-sys 常量,集中表达 lookup/update/delete/push/pop/readonly helper side effects。

- 影响文件: 新增 `bpfopt/crates/bpfopt/src/analysis/map_ref.rs` 或扩展 `passes/map_inline/map_info.rs`;修改 `pass.rs:436-462`, `passes/map_inline/map_info.rs:148-237`, `passes/map_inline.rs:25-28`, `passes/map_inline.rs:1633-1718`, `passes/map_inline.rs:3964-4148`。
- 行数估计: 新增 150-250 LOC;删除 100-180 LOC 重复 map-id/helper 解析。
- 风险: `map_ids` 的旧顺序绑定和 rewritten pseudo-map-value 指令必须保持兼容。map-in-map outer-only fold 尤其需要覆盖,否则会误把 outer map_ptr 和 value pointer 混淆。

### P1. 增加 `InsnCursor` / `BranchTarget` / 小型 matcher utilities

先不做通用 IR,只提供 bytecode-safe primitives: `iter_real_insns`, `insn_width`, `jump_target`, `pseudo_call_target`, `set_relative_target`, `subprog_bounds_from_cfg`,以及 `helper_call(id)`, `ldimm64_map_ref(dst)`, `seq2/seq3` 这类轻量 matcher。

- 影响文件: `bpfopt/crates/bpfopt/src/insn.rs`, 新增 `bpfopt/crates/bpfopt/src/analysis/targets.rs` 或 `passes/matcher.rs`;逐步替换 `analysis/cfg.rs`, `analysis/branch_target.rs`, `analysis/liveness.rs`, `passes/cond_select.rs`, `passes/branch_flip.rs`, `passes/extract.rs`, `passes/map_inline.rs`, `passes/prefetch.rs`。
- 行数估计: 新增 150-250 LOC;第一阶段删除 100-200 LOC target/subprog/width stepping 重复。
- 风险: candidate scan 的 pc stepping 一旦改变,可能改变 matched site 数。建议初期只包现有逻辑,每迁一个 scanner 就比较 pass diagnostics。

### P2. 行为不变地拆分 `map_inline.rs`

在 P0/P1 抽出 rewrite/oracle/map-ref 后,再机械拆 `map_inline.rs`: `hints.rs`, `key_extraction.rs`, `value_rewrite.rs`, `soft_fold.rs`, `map_in_map.rs`, `alias.rs`, `diagnostics.rs`。保持 public surface 和 tests 不变,不要在拆文件时顺手改语义。

- 影响文件: `bpfopt/crates/bpfopt/src/passes/map_inline.rs`, 新增 `bpfopt/crates/bpfopt/src/passes/map_inline/*.rs`,更新 `passes/mod.rs` module wiring。
- 行数估计: 净行数基本不变;主文件从 5361 LOC 降到约 800-1200 LOC orchestration,其余分模块。
- 风险: 这是高冲突改动,容易和 active map_inline 迭代冲突。应放在 rewrite/oracle 稳定之后,并拆成纯 move commits,避免把行为改动混进去。

## 7. 不建议的改造

1. **不建议全套 SSA 化**

   BPF 是 register-based bytecode,寄存器复用、helper clobber、verifier type/provenance 和 PC-relative metadata 是核心语义。为了几个 peephole 和 map_inline key extraction 引入完整 SSA,成本远大于收益。可以做局部 use-def/reaching-def primitive,不要做全 IR 替换。

2. **不建议把 bpfopt 迁成 LLVM pass pipeline 或嵌 LLVM**

   v3 设计要求 `bpfopt` 是 pure bytecode CLI,stdin/stdout 传 raw `struct bpf_insn[]`,daemon 负责 per-pass ReJIT 和 verifier log。引入 LLVM pipeline 不仅过重,还会偏离 `docs/kernel-jit-optimization-plan.md:333-344` 和 `CLAUDE.md:96-103` 的边界。

3. **不建议大爆炸重写所有 pass**

   当前 pass 大多有具体 paper/workload 目标,直接重写会同时改变太多 bytecode 输出和 diagnostics。正确路径是先抽 builder/oracle,一次迁一个 pass,保持行为等价。

4. **不建议把 verifier-state 缺失变成 heuristic fallback**

   #251/#252 的教训是 verifier provenance guard 必须 fail-closed。缺 site state、parse fail 或跨 occurrence 不一致时,pass 应跳过/报 diagnostic,不能猜 scalar 或 pointer 类型。

5. **不建议把 framework core 继续塞 pass-local option**

   `map_inline_hints` 已经是边界泄漏。后续 branch_flip profile、prefetch hint、map overlay 等不要继续在 `BpfProgram`/`pass.rs` 增加 pass-local public fields;应走 pass side-input parser 或 typed analysis result。

6. **不建议改 runner/daemon benchmark 边界来解决 pass 内重复**

   这次问题在 bpfopt pass implementation layer,不是 runner Python 或 daemon socket protocol。v3 规则明确 runner 稳定,daemon owns kernel calls,bpfopt 是 pure bytecode CLI。不要为了 pass 抽象去动 benchmark entrypoint 或 ReJIT orchestration。
