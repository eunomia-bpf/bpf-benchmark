# BpfReJIT Daemon Pass Framework 设计

日期: 2026-03-21

## 0. 动机与背景

当前 daemon (`daemon/src/`) 使用 ad-hoc pattern matching 架构：`matcher.rs` 中的 `scan_wide_mem()` 等硬编码函数逐一匹配特定指令序列。这种方式有以下问题：

1. **不可扩展**：每种新优化都要写新的 matcher 函数，增加 `Family` 枚举，修改 `emit.rs`、`rewriter.rs`
2. **没有统一分析基础设施**：CFG、liveness、dominator 等分析在 rewriter 中临时构建，无法复用
3. **没有 pass 间信息传递**：WideMemPass 发现的信息不能传给后续 pass
4. **不能利用 verifier 信息或 PGO 数据**：缺少统一的 metadata 注入机制

本文设计一个类似 LLVM PassManager 的 Rust 优化框架，作为 daemon 的核心引擎。

---

## 1. 核心 Trait 定义

### 1.1 BpfProgram — 程序 IR

设计决策：采用**线性指令流 + 注解**模式，而非 BB-based IR。理由：

- BPF 指令序列的 branch fixup 依赖线性 PC 偏移，BB-based IR 需要在最后阶段重新线性化，增加复杂度
- 当前所有变换都是 peephole 性质（pattern match → replace），不需要 BB 粒度的迭代数据流分析
- 保持与 kernel verifier 的 1:1 insn 对应关系，方便 debug
- 未来如需 BB-based 分析（如 liveness），可以在 Analysis 层构建 CFG 视图而不改变底层 IR

```rust
use std::collections::HashMap;
use std::any::{Any, TypeId};
use std::fmt;

use crate::insn::BpfInsn;

// ── 程序元信息 ────────────────────────────────────────────────────────

/// 程序来源的元信息，从 BPF_OBJ_GET_INFO_BY_FD 获取。
#[derive(Clone, Debug, Default)]
pub struct ProgMeta {
    pub prog_id: u32,
    pub prog_type: u32,
    pub prog_name: String,
    pub map_ids: Vec<u32>,
    pub btf_id: u32,
    pub run_cnt: u64,
    pub run_time_ns: u64,
}

/// 每条指令的注解 — 由分析 pass 填充，变换 pass 读取。
#[derive(Clone, Debug, Default)]
pub struct InsnAnnotation {
    /// 是否是某个 branch/call 的目标
    pub is_branch_target: bool,
    /// 是否是 subprogram 入口
    pub is_subprog_entry: bool,
    /// 是否是 LD_IMM64 的第二个 slot
    pub is_ldimm64_hi: bool,
    /// 所属 subprogram ID（-1 = main）
    pub subprog_id: i32,
    /// Verifier 提供的寄存器类型信息（可选）
    pub verifier_state: Option<VerifierRegState>,
    /// PGO: 此指令所在 branch 的 taken/not-taken 计数
    pub branch_profile: Option<BranchProfile>,
    /// 自由形式的 key-value metadata
    pub metadata: HashMap<String, i64>,
}

/// Verifier 导出的寄存器状态（per-insn）
#[derive(Clone, Debug)]
pub struct VerifierRegState {
    pub regs: [RegInfo; 11], // r0-r10
}

#[derive(Clone, Debug, Default)]
pub struct RegInfo {
    pub reg_type: u32,         // PTR_TO_CTX, SCALAR_VALUE, etc.
    pub known_value: Option<i64>,
    pub min_value: i64,
    pub max_value: i64,
    pub is_const: bool,
}

/// PGO 分支统计
#[derive(Clone, Debug)]
pub struct BranchProfile {
    pub taken_count: u64,
    pub not_taken_count: u64,
}

// ── 程序 IR ───────────────────────────────────────────────────────────

/// BPF 程序的 IR 表示 — 线性指令流 + per-insn 注解 + 元信息。
///
/// 这是所有 pass 操作的核心数据结构。变换 pass 修改 `insns`，
/// 分析 pass 填充 `annotations` 和 analysis cache。
#[derive(Clone)]
pub struct BpfProgram {
    /// 指令流（可变，变换 pass 会修改）
    pub insns: Vec<BpfInsn>,
    /// Per-insn 注解（长度与 insns 同步）
    pub annotations: Vec<InsnAnnotation>,
    /// 程序元信息
    pub meta: ProgMeta,
    /// 变换日志：记录每个 pass 做了什么
    pub transform_log: Vec<TransformEntry>,
}

#[derive(Clone, Debug)]
pub struct TransformEntry {
    pub pass_name: String,
    pub sites_applied: usize,
    pub insns_before: usize,
    pub insns_after: usize,
    pub details: Vec<String>,
}

impl BpfProgram {
    /// 从原始指令和元信息创建。注解初始化为 default。
    pub fn new(insns: Vec<BpfInsn>, meta: ProgMeta) -> Self {
        let len = insns.len();
        Self {
            insns,
            annotations: vec![InsnAnnotation::default(); len],
            meta,
            transform_log: Vec::new(),
        }
    }

    /// 替换指令流后重新同步注解长度。
    /// 变换 pass 在修改 insns 后必须调用此方法。
    pub fn sync_annotations(&mut self) {
        self.annotations.resize_with(self.insns.len(), InsnAnnotation::default);
    }

    /// 记录一次变换。
    pub fn log_transform(&mut self, entry: TransformEntry) {
        self.transform_log.push(entry);
    }

    /// 是否有任何变换被应用。
    pub fn has_transforms(&self) -> bool {
        self.transform_log.iter().any(|e| e.sites_applied > 0)
    }
}
```

### 1.2 Analysis Trait — 分析基础设施

类似 LLVM 的 `AnalysisManager`，分析结果按类型缓存，支持 invalidation。

```rust
/// 分析 pass 的 trait。每种分析产生一个类型化的 Result。
///
/// 分析 pass 不修改 BpfProgram 的指令流，只读取并产生分析结果。
/// 结果存入 AnalysisCache，可被多个变换 pass 共享。
pub trait Analysis: Send + Sync {
    /// 分析结果的具体类型
    type Result: Any + Clone + Send + Sync;

    /// 分析的名称（用于 debug/日志）
    fn name(&self) -> &str;

    /// 执行分析，返回结果。
    /// 接收不可变的 BpfProgram 引用。
    fn run(&self, program: &BpfProgram) -> Self::Result;
}

/// 分析结果缓存 — 按 TypeId 索引，支持 invalidation。
///
/// 变换 pass 修改程序后，PassManager 调用 `invalidate_all()` 清除缓存，
/// 下一个需要分析结果的 pass 会触发重新计算。
pub struct AnalysisCache {
    cache: HashMap<TypeId, Box<dyn Any + Send + Sync>>,
}

impl AnalysisCache {
    pub fn new() -> Self {
        Self { cache: HashMap::new() }
    }

    /// 获取分析结果。如果缓存中没有，运行分析并缓存。
    pub fn get<A: Analysis + 'static>(&mut self, analysis: &A, program: &BpfProgram) -> A::Result {
        let type_id = TypeId::of::<A::Result>();
        if let Some(cached) = self.cache.get(&type_id) {
            if let Some(result) = cached.downcast_ref::<A::Result>() {
                return result.clone();
            }
        }
        let result = analysis.run(program);
        self.cache.insert(type_id, Box::new(result.clone()));
        result
    }

    /// 使所有缓存失效（在变换 pass 修改程序后调用）。
    pub fn invalidate_all(&mut self) {
        self.cache.clear();
    }

    /// 使特定分析的缓存失效。
    pub fn invalidate<R: Any>(&mut self) {
        self.cache.remove(&TypeId::of::<R>());
    }
}
```

### 1.3 BpfPass Trait — 变换 Pass

```rust
/// Pass 执行结果
#[derive(Clone, Debug)]
pub struct PassResult {
    /// pass 名称
    pub pass_name: String,
    /// 是否修改了程序（用于触发 analysis invalidation）
    pub changed: bool,
    /// 应用了多少个 site
    pub sites_applied: usize,
    /// 跳过了多少个 site（以及原因）
    pub sites_skipped: Vec<SkipReason>,
    /// 诊断信息
    pub diagnostics: Vec<String>,
}

#[derive(Clone, Debug)]
pub struct SkipReason {
    pub pc: usize,
    pub reason: String,
}

/// 变换 pass trait。
///
/// 每个优化是一个 pass：扫描程序、发现 rewrite site、应用变换。
/// Pass 可以通过 AnalysisCache 读取分析结果。
pub trait BpfPass: Send + Sync {
    /// Pass 名称
    fn name(&self) -> &str;

    /// Pass 所属的类别
    fn category(&self) -> PassCategory;

    /// 声明此 pass 依赖的分析（用于 PassManager 排序和预计算）
    fn required_analyses(&self) -> Vec<&str> {
        vec![]
    }

    /// 执行 pass。
    ///
    /// - `program`: 可变引用，pass 可以修改指令流
    /// - `analyses`: 分析缓存，pass 可以获取分析结果
    /// - `ctx`: 平台上下文（kfunc 可用性、CPU 特性等）
    ///
    /// 返回 PassResult 描述做了什么。
    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult>;
}

/// Pass 类别
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PassCategory {
    /// 性能优化
    Optimization,
    /// 安全加固
    Security,
    /// 可观测性增强
    Observability,
}

/// Pass 执行上下文 — 包含平台信息和外部配置。
///
/// 这些信息在整个 pipeline 执行期间不变。
#[derive(Clone, Debug)]
pub struct PassContext {
    /// 平台上可用的 kinsn kfunc 及其 BTF ID
    pub kfunc_registry: KfuncRegistry,
    /// CPU 特性
    pub platform: PlatformCapabilities,
    /// Policy 配置（哪些 pass 启用、参数等）
    pub policy: PolicyConfig,
}

/// 平台上可用的 kfunc 及其 BTF ID。
/// BTF ID = -1 表示该 kfunc 不可用。
#[derive(Clone, Debug, Default)]
pub struct KfuncRegistry {
    pub rotate64_btf_id: i32,
    pub select64_btf_id: i32,
    pub extract64_btf_id: i32,
    pub lea64_btf_id: i32,
    pub movbe64_btf_id: i32,
    /// 扩展：module FD（当使用 module kfunc 时，REJIT 的 fd_array 需要它）
    pub module_fd: Option<i32>,
}

/// CPU 平台特性
#[derive(Clone, Debug, Default)]
pub struct PlatformCapabilities {
    pub has_bmi1: bool,
    pub has_bmi2: bool,
    pub has_cmov: bool,
    pub has_movbe: bool,
    pub has_rorx: bool,
    pub arch: Arch,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub enum Arch {
    #[default]
    X86_64,
    Aarch64,
}

/// 优化策略配置
#[derive(Clone, Debug, Default)]
pub struct PolicyConfig {
    /// 启用的 pass 名称列表（空 = 全部启用）
    pub enabled_passes: Vec<String>,
    /// 禁用的 pass 名称列表
    pub disabled_passes: Vec<String>,
    /// 全局参数
    pub params: HashMap<String, String>,
}
```

### 1.4 PassManager — Pass 编排器

```rust
/// PassManager — 管理和执行 pass pipeline。
///
/// 类似 LLVM 的 FunctionPassManager：按顺序执行 pass，
/// 管理 analysis cache invalidation，收集统计信息。
pub struct PassManager {
    passes: Vec<Box<dyn BpfPass>>,
    /// 注册的分析（用于按需计算）
    analyses: AnalysisRegistry,
}

/// 分析注册表 — 存储所有可用的分析实例。
pub struct AnalysisRegistry {
    // 按名称索引的分析实例
    registry: HashMap<String, Box<dyn AnyAnalysis>>,
}

/// 类型擦除的 Analysis trait object wrapper
pub trait AnyAnalysis: Send + Sync {
    fn name(&self) -> &str;
    fn run_and_cache(&self, program: &BpfProgram, cache: &mut AnalysisCache);
}

/// 为所有 Analysis 实现 AnyAnalysis
impl<A: Analysis + 'static> AnyAnalysis for A
where
    A::Result: 'static,
{
    fn name(&self) -> &str {
        Analysis::name(self)
    }

    fn run_and_cache(&self, program: &BpfProgram, cache: &mut AnalysisCache) {
        cache.get(self, program);
    }
}

/// Pipeline 执行结果
#[derive(Clone, Debug)]
pub struct PipelineResult {
    pub pass_results: Vec<PassResult>,
    pub total_sites_applied: usize,
    pub program_changed: bool,
}

impl PassManager {
    pub fn new() -> Self {
        Self {
            passes: Vec::new(),
            analyses: AnalysisRegistry { registry: HashMap::new() },
        }
    }

    /// 注册一个分析。
    pub fn register_analysis<A: Analysis + 'static>(&mut self, analysis: A)
    where
        A::Result: 'static,
    {
        let name = analysis.name().to_string();
        self.analyses.registry.insert(name, Box::new(analysis));
    }

    /// 添加一个 pass 到 pipeline 末尾。
    pub fn add_pass<P: BpfPass + 'static>(&mut self, pass: P) {
        self.passes.push(Box::new(pass));
    }

    /// 执行整个 pipeline。
    ///
    /// 对于每个 pass：
    /// 1. 确保其依赖的分析已计算
    /// 2. 运行 pass
    /// 3. 如果 pass 修改了程序，invalidate analysis cache
    pub fn run(
        &self,
        program: &mut BpfProgram,
        ctx: &PassContext,
    ) -> anyhow::Result<PipelineResult> {
        let mut cache = AnalysisCache::new();
        let mut pass_results = Vec::new();
        let mut total_sites = 0usize;
        let mut any_changed = false;

        for pass in &self.passes {
            // 检查 policy 是否允许此 pass
            if !ctx.policy.disabled_passes.is_empty()
                && ctx.policy.disabled_passes.contains(&pass.name().to_string())
            {
                continue;
            }
            if !ctx.policy.enabled_passes.is_empty()
                && !ctx.policy.enabled_passes.contains(&pass.name().to_string())
            {
                continue;
            }

            // 确保依赖的分析已计算
            for analysis_name in pass.required_analyses() {
                if let Some(analysis) = self.analyses.registry.get(analysis_name) {
                    analysis.run_and_cache(program, &mut cache);
                }
            }

            // 运行 pass
            let result = pass.run(program, &mut cache, ctx)?;

            if result.changed {
                // 变换修改了程序 → invalidate 所有分析缓存
                cache.invalidate_all();
                // 同步注解
                program.sync_annotations();
                any_changed = true;
            }

            total_sites += result.sites_applied;
            pass_results.push(result);
        }

        Ok(PipelineResult {
            pass_results,
            total_sites_applied: total_sites,
            program_changed: any_changed,
        })
    }
}
```

---

## 2. 分析基础设施（Analysis Implementations）

### 2.1 CFGAnalysis — 控制流图

```rust
/// 基本块信息
#[derive(Clone, Debug)]
pub struct BasicBlock {
    /// 起始 PC（inclusive）
    pub start: usize,
    /// 结束 PC（exclusive）
    pub end: usize,
    /// 前驱 BB 索引
    pub preds: Vec<usize>,
    /// 后继 BB 索引
    pub succs: Vec<usize>,
}

/// CFG 分析结果
#[derive(Clone, Debug)]
pub struct CFGResult {
    /// 基本块列表
    pub blocks: Vec<BasicBlock>,
    /// insn PC → 所属 BB 索引的映射
    pub insn_to_block: Vec<usize>,
    /// 所有 branch target 集合
    pub branch_targets: Vec<bool>,
    /// Subprogram 边界
    pub subprogs: Vec<SubprogRange>,
}

#[derive(Clone, Debug)]
pub struct SubprogRange {
    pub start: usize,
    pub end: usize,
}

/// CFG 分析
pub struct CFGAnalysis;

impl Analysis for CFGAnalysis {
    type Result = CFGResult;

    fn name(&self) -> &str {
        "cfg"
    }

    fn run(&self, program: &BpfProgram) -> CFGResult {
        let n = program.insns.len();
        let mut branch_targets = vec![false; n + 1];
        let mut subprog_entries = Vec::new();

        // Pass 1: 收集所有 branch target 和 subprog entry
        let mut pc = 0;
        while pc < n {
            let insn = &program.insns[pc];

            if insn.is_jmp_class() && !insn.is_exit() {
                if insn.is_call() {
                    // BPF-to-BPF call (src_reg == 1 for pseudo call)
                    if insn.src_reg() == 1 {
                        let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                        if target < n {
                            branch_targets[target] = true;
                            subprog_entries.push(target);
                        }
                    }
                } else if !insn.is_call() {
                    // JA or conditional jump
                    let target = (pc as i64 + 1 + insn.off as i64) as usize;
                    if target <= n {
                        branch_targets[target] = true;
                    }
                }
            }

            // Skip LD_IMM64 second slot
            if insn.is_ldimm64() {
                pc += 2;
            } else {
                pc += 1;
            }
        }

        // Pass 2: 切分基本块
        // BB 开始条件：(1) 程序入口 (2) branch target (3) branch/exit 后面的指令
        let mut block_starts = vec![false; n];
        if n > 0 {
            block_starts[0] = true;
        }
        for i in 0..n {
            if branch_targets[i] {
                block_starts[i] = true;
            }
        }

        pc = 0;
        while pc < n {
            let insn = &program.insns[pc];
            let next_pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };

            if insn.is_jmp_class() && next_pc < n {
                block_starts[next_pc] = true;
            }

            pc = next_pc;
        }

        // 构建 BB 列表
        let mut blocks: Vec<BasicBlock> = Vec::new();
        let mut insn_to_block = vec![0usize; n];
        let mut current_start = 0;

        for i in 0..n {
            if block_starts[i] && i > current_start {
                let bb_idx = blocks.len();
                for j in current_start..i {
                    insn_to_block[j] = bb_idx;
                }
                blocks.push(BasicBlock {
                    start: current_start,
                    end: i,
                    preds: Vec::new(),
                    succs: Vec::new(),
                });
                current_start = i;
            }
        }
        // 最后一个 BB
        let bb_idx = blocks.len();
        for j in current_start..n {
            insn_to_block[j] = bb_idx;
        }
        blocks.push(BasicBlock {
            start: current_start,
            end: n,
            preds: Vec::new(),
            succs: Vec::new(),
        });

        // Pass 3: 构建 CFG 边（pred/succ）
        for (bb_idx, block) in blocks.iter().enumerate() {
            if block.end == 0 {
                continue;
            }
            let last_pc = block.end - 1;
            let last_insn = &program.insns[last_pc];

            if last_insn.is_exit() {
                // 无后继
            } else if last_insn.is_ja() {
                let target = (last_pc as i64 + 1 + last_insn.off as i64) as usize;
                if target < n {
                    let target_bb = insn_to_block[target];
                    // succs/preds 在下面统一设置（需要 mut borrow）
                    // 这里先收集边
                    let _ = (bb_idx, target_bb);
                }
            }
            // ... 完整 CFG 构建省略，模式相同
        }

        // Subprog 边界
        subprog_entries.sort();
        subprog_entries.dedup();
        let mut subprogs = vec![SubprogRange { start: 0, end: n }]; // main
        for &entry in &subprog_entries {
            if entry > 0 {
                // 找到 subprog 的结束位置（下一个 subprog entry 或 n）
                subprogs.push(SubprogRange {
                    start: entry,
                    end: n, // 需要后续精化
                });
            }
        }

        CFGResult {
            blocks,
            insn_to_block,
            branch_targets,
            subprogs,
        }
    }
}
```

### 2.2 LivenessAnalysis — 寄存器活跃性

```rust
use std::collections::HashSet;

/// 每条指令的 live-in/live-out 寄存器集合
#[derive(Clone, Debug)]
pub struct LivenessResult {
    /// live_in[pc] = 该指令执行前活跃的寄存器集合
    pub live_in: Vec<HashSet<u8>>,
    /// live_out[pc] = 该指令执行后活跃的寄存器集合
    pub live_out: Vec<HashSet<u8>>,
}

pub struct LivenessAnalysis;

impl Analysis for LivenessAnalysis {
    type Result = LivenessResult;

    fn name(&self) -> &str {
        "liveness"
    }

    fn run(&self, program: &BpfProgram) -> LivenessResult {
        let n = program.insns.len();
        let mut live_in = vec![HashSet::new(); n];
        let mut live_out = vec![HashSet::new(); n];

        // 标准后向数据流分析
        // live_in[i] = use[i] ∪ (live_out[i] - def[i])
        // live_out[i] = ∪ live_in[s] for all successors s of i
        //
        // 迭代直到不动点

        let mut changed = true;
        while changed {
            changed = false;
            // 后向遍历
            for pc in (0..n).rev() {
                let insn = &program.insns[pc];
                let (uses, defs) = insn_use_def(insn);

                // 计算新 live_out
                let mut new_out = HashSet::new();
                // 获取后继
                let succs = get_successors(program, pc);
                for s in succs {
                    if s < n {
                        new_out.extend(&live_in[s]);
                    }
                }

                // 计算新 live_in = use ∪ (live_out - def)
                let mut new_in: HashSet<u8> = new_out.difference(&defs).cloned().collect();
                new_in.extend(&uses);

                if new_in != live_in[pc] || new_out != live_out[pc] {
                    live_in[pc] = new_in;
                    live_out[pc] = new_out;
                    changed = true;
                }
            }
        }

        LivenessResult { live_in, live_out }
    }
}

/// 获取一条指令的 use/def 寄存器集合。
fn insn_use_def(insn: &BpfInsn) -> (HashSet<u8>, HashSet<u8>) {
    let mut uses = HashSet::new();
    let mut defs = HashSet::new();

    let class = insn.class();

    match class {
        0x07 | 0x04 => {
            // ALU64 / ALU: dst = dst op src/imm
            defs.insert(insn.dst_reg());
            uses.insert(insn.dst_reg());
            if (insn.code & 0x08) == 0x08 {
                // BPF_X — src is a register
                uses.insert(insn.src_reg());
            }
        }
        0x01 => {
            // LDX: dst = *(src + off)
            defs.insert(insn.dst_reg());
            uses.insert(insn.src_reg());
        }
        0x02 | 0x03 => {
            // ST/STX: *(dst + off) = src/imm
            uses.insert(insn.dst_reg());
            if class == 0x03 {
                // STX uses src_reg
                uses.insert(insn.src_reg());
            }
        }
        0x05 | 0x06 => {
            // JMP/JMP32
            if insn.is_call() {
                // CALL: uses r1-r5 (args), defs r0 (return)
                for r in 1..=5 {
                    uses.insert(r);
                }
                defs.insert(0);
            } else if insn.is_exit() {
                // EXIT: uses r0 (return value)
                uses.insert(0);
            } else {
                // Conditional jump or JA
                if (insn.code & 0x08) == 0x08 {
                    uses.insert(insn.src_reg());
                }
                uses.insert(insn.dst_reg());
            }
        }
        0x00 => {
            // LD: LD_IMM64
            defs.insert(insn.dst_reg());
        }
        _ => {}
    }

    (uses, defs)
}

/// 获取指令 pc 的后继 PC。
fn get_successors(program: &BpfProgram, pc: usize) -> Vec<usize> {
    let insn = &program.insns[pc];
    let mut succs = Vec::new();
    let next = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };

    if insn.is_exit() {
        // 无后继
    } else if insn.is_ja() {
        let target = (pc as i64 + 1 + insn.off as i64) as usize;
        succs.push(target);
    } else if insn.is_cond_jmp() {
        succs.push(next); // fall-through
        let target = (pc as i64 + 1 + insn.off as i64) as usize;
        succs.push(target);
    } else {
        succs.push(next); // fall-through
    }

    succs
}
```

### 2.3 BranchTargetAnalysis

```rust
/// 简单的 branch target 集合分析（比 CFGAnalysis 轻量）
#[derive(Clone, Debug)]
pub struct BranchTargetResult {
    /// is_target[pc] = true 表示有 branch/call 指向这里
    pub is_target: Vec<bool>,
}

pub struct BranchTargetAnalysis;

impl Analysis for BranchTargetAnalysis {
    type Result = BranchTargetResult;

    fn name(&self) -> &str {
        "branch_targets"
    }

    fn run(&self, program: &BpfProgram) -> BranchTargetResult {
        let n = program.insns.len();
        let mut is_target = vec![false; n + 1];

        let mut pc = 0;
        while pc < n {
            let insn = &program.insns[pc];
            if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
                let target = (pc as i64 + 1 + insn.off as i64) as usize;
                if target <= n {
                    is_target[target] = true;
                }
            }
            if insn.is_call() && insn.src_reg() == 1 {
                // BPF-to-BPF pseudo call
                let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                if target < n {
                    is_target[target] = true;
                }
            }
            pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
        }

        BranchTargetResult { is_target }
    }
}
```

### 2.4 KfuncAvailabilityAnalysis

```rust
/// Kfunc 可用性分析结果
#[derive(Clone, Debug)]
pub struct KfuncAvailabilityResult {
    pub rotate64_available: bool,
    pub select64_available: bool,
    pub extract64_available: bool,
    pub lea64_available: bool,
    pub movbe64_available: bool,
}

pub struct KfuncAvailabilityAnalysis;

/// 注意：这个分析实际上不依赖 BpfProgram，而是依赖 PassContext。
/// 但为了统一框架，仍然实现 Analysis trait。
/// 实际的 kfunc 探测在 daemon 启动时完成，存入 KfuncRegistry。
impl Analysis for KfuncAvailabilityAnalysis {
    type Result = KfuncAvailabilityResult;

    fn name(&self) -> &str {
        "kfunc_availability"
    }

    fn run(&self, _program: &BpfProgram) -> KfuncAvailabilityResult {
        // 实际实现会从 PassContext 获取，这里是 placeholder
        // 真正的探测在 PassContext 构建时完成
        KfuncAvailabilityResult {
            rotate64_available: false,
            select64_available: false,
            extract64_available: false,
            lea64_available: false,
            movbe64_available: false,
        }
    }
}
```

### 2.5 PGOAnalysis

```rust
/// PGO 分析结果
#[derive(Clone, Debug)]
pub struct PGOResult {
    /// 程序级别的运行统计
    pub run_cnt: u64,
    pub run_time_ns: u64,
    pub avg_ns_per_run: f64,

    /// Per-branch 统计（当可用时）
    /// key = branch 指令的 PC
    pub branch_stats: HashMap<usize, BranchProfile>,

    /// Hot path 标识（基于 perf branch profiling）
    pub hot_blocks: Vec<usize>, // BB indices
}

pub struct PGOAnalysis {
    /// 外部注入的 profiling 数据
    pub profiling_data: Option<ProfilingData>,
}

/// 从 perf / bpf_prog_info 收集的原始 profiling 数据
#[derive(Clone, Debug)]
pub struct ProfilingData {
    pub run_cnt: u64,
    pub run_time_ns: u64,
    /// Per-branch taken/not-taken（需要未来的 kernel 基础设施）
    pub branch_samples: HashMap<usize, BranchProfile>,
}

impl Analysis for PGOAnalysis {
    type Result = PGOResult;

    fn name(&self) -> &str {
        "pgo"
    }

    fn run(&self, program: &BpfProgram) -> PGOResult {
        let run_cnt = program.meta.run_cnt;
        let run_time_ns = program.meta.run_time_ns;
        let avg = if run_cnt > 0 { run_time_ns as f64 / run_cnt as f64 } else { 0.0 };

        let branch_stats = if let Some(ref data) = self.profiling_data {
            data.branch_samples.clone()
        } else {
            HashMap::new()
        };

        PGOResult {
            run_cnt,
            run_time_ns,
            avg_ns_per_run: avg,
            branch_stats,
            hot_blocks: Vec::new(), // TODO: compute from branch_stats + CFG
        }
    }
}
```

### 2.6 VerifierInfoAnalysis

#### 数据获取方式：解析 verifier log（无需内核修改）

**关键决策**：不引入内核修改，改为解析 `log_level=2` 的 verifier log 文本。

这一方案已在 `daemon/src/verifier_log.rs` 中实现（433 行，33 tests）。

**两种调用时机**：

1. **daemon 调 `BPF_PROG_REJIT` 时**：在 REJIT syscall 中设置 `log_level=2`，从 `log_buf` 解析 per-insn 寄存器状态，注入到 `BpfProgram::annotations`；
2. **首次 enumerate 时**：对 `GET_ORIGINAL` 拿到的 bytecode，通过临时的 `BPF_PROG_LOAD + log_level=2` 获取（不实际运行，仅用于 verify + 提取 log）。

**能从 verifier log 提取的信息**：

- per-insn 寄存器类型（`scalar` / `ctx` / `map_value` / `ptr_to_map` 等）
- per-insn 寄存器范围（`min_value` / `max_value`）
- 已知常量值（`known_value`，当 verifier 推断出确定值时）
- 指针 offset（`off` 字段）

**不能从 verifier log 获取的信息**（须其他 Analysis 补充）：

| 信息 | 为何 verifier log 不含 | 替代来源 |
|------|----------------------|---------|
| Liveness（live-in/live-out） | verifier 不输出寄存器活跃集合 | `LivenessAnalysis`（从 insns 自算） |
| PGO / branch profile | verifier 是静态分析，不含运行时数据 | `PGOAnalysis`（从 `bpf_stats` / perf 获取） |
| 完整 CFG | log 中有 "from X to Y" 但不完整、非结构化 | `CFGAnalysis`（从 insns 自算） |

**各 pass 的 Analysis 数据源映射**：

| Pass | 需要的 Analysis | 数据来源 |
|------|----------------|---------|
| WideMemPass | BranchTarget | insns 自算 |
| RotatePass | BranchTarget + Liveness + KfuncAvailability | insns 自算 + insns 自算 + BTF 查询 |
| CondSelectPass | BranchTarget + Liveness + PGO | insns 自算 + insns 自算 + bpf_stats |
| BranchFlipPass | CFG + PGO | insns 自算 + bpf_stats |
| ConstPropPass | VerifierInfo | **verifier log** |
| HelperFirewallPass | — | 直接 pattern match |
| SpectreMitigationPass | CFG | insns 自算 |
| BoundsHardeningPass | VerifierInfo | **verifier log** |

**已知限制**：

- verifier log 格式是内部实现，非稳定 API，kernel 版本间可能有格式变化，需要版本适配层
- `log_buf` 大小有限（默认 64KB），大程序可能截断；需要动态扩大 `log_size` 重试
- 用临时 `BPF_PROG_LOAD` 获取 log 时，程序的 map fd 等上下文可能不完整，影响 verifier 推断深度
- 作为 POC 可行；production 需考虑格式变化的 fallback（退化为 no-op 而非崩溃）

```rust
/// Verifier 信息分析结果
///
/// 数据来源：解析 verifier log (log_level=2)，**无需内核修改**。
///
/// 两种获取时机：
/// 1. daemon 在 BPF_PROG_REJIT 时设置 log_level=2，从 log_buf 解析；
/// 2. 首次 enumerate 时，对 GET_ORIGINAL bytecode 用临时 BPF_PROG_LOAD
///    + log_level=2 获取（不实际运行，仅用于提取 verifier 信息）。
///
/// 能提取：per-insn reg type / value range / known_value / ptr offset。
/// 不能提取：liveness、CFG、PGO（这些由其他 Analysis 负责）。
///
/// 已实现：daemon/src/verifier_log.rs（433 行，33 tests）
#[derive(Clone, Debug, Default)]
pub struct VerifierInfoResult {
    /// Per-insn 寄存器状态（None = 信息不可用或 log 截断）
    pub per_insn_state: Option<Vec<VerifierRegState>>,
    /// 已知的 frozen map 常量值
    pub frozen_map_values: HashMap<u32, Vec<u8>>, // map_id → value bytes
}

pub struct VerifierInfoAnalysis {
    /// 预先收集的 verifier log 文本（由 daemon 在 REJIT 或 enumerate 时填入）
    pub log_text: Option<String>,
}

impl Analysis for VerifierInfoAnalysis {
    type Result = VerifierInfoResult;

    fn name(&self) -> &str {
        "verifier_info"
    }

    fn run(&self, program: &BpfProgram) -> VerifierInfoResult {
        let log = match &self.log_text {
            Some(text) => text,
            None => return VerifierInfoResult::default(),
        };

        // 委托给 daemon/src/verifier_log.rs 的解析器
        match crate::verifier_log::parse_verifier_log(log, program.insns.len()) {
            Ok(per_insn) => VerifierInfoResult {
                per_insn_state: Some(per_insn),
                frozen_map_values: HashMap::new(),
            },
            Err(_) => {
                // log 格式不可解析（版本不兼容等）→ 退化为空结果，不影响其他 pass
                VerifierInfoResult::default()
            }
        }
    }
}
```

---

## 3. 具体 Pass 实现

### 3.1 WideMemPass — byte load 合并

从现有 `matcher.rs` 的 `scan_wide_mem()` 迁移而来。

```rust
use crate::insn::*;

/// WIDE_MEM 优化 pass：将 byte load + shift + or 序列合并为单条 wide load。
///
/// 这是 BpfReJIT 最重要的优化之一，占 kernel JIT surplus 的 50.7%。
/// 不需要 kinsn 支持 — 纯 BPF 指令替换。
pub struct WideMemPass;

impl BpfPass for WideMemPass {
    fn name(&self) -> &str {
        "wide_mem"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // 获取 branch target 信息（用于安全检查）
        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        // 扫描 sites
        let sites = scan_wide_mem_sites(&program.insns);

        // 过滤不安全的 sites（有 branch target 落入 site 内部的不能替换）
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            let mut has_interior_target = false;
            for pc in (site.start_pc + 1)..(site.start_pc + site.old_len) {
                if pc < bt.is_target.len() && bt.is_target[pc] {
                    has_interior_target = true;
                    break;
                }
            }

            if has_interior_target {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
            } else {
                safe_sites.push(site);
            }
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
            });
        }

        // 应用变换：使用现有的 rewriter 逻辑
        let orig_len = program.insns.len();
        let rewrite_sites: Vec<_> = safe_sites.iter().map(|s| {
            crate::matcher::RewriteSite {
                start_pc: s.start_pc,
                old_len: s.old_len,
                family: crate::matcher::Family::WideMem,
                bindings: vec![
                    crate::matcher::Binding { name: "dst_reg", value: s.dst_reg as i64 },
                    crate::matcher::Binding { name: "base_reg", value: s.base_reg as i64 },
                    crate::matcher::Binding { name: "base_off", value: s.base_off },
                    crate::matcher::Binding { name: "width", value: s.width as i64 },
                ],
            }
        }).collect();

        let result = crate::rewriter::rewrite(&program.insns, &rewrite_sites)?;
        let applied = result.sites_applied;

        program.insns = result.new_insns;
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: safe_sites.iter().map(|s| {
                format!("pc={} width={} dst=r{} base=r{}+{}",
                        s.start_pc, s.width, s.dst_reg, s.base_reg, s.base_off)
            }).collect(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}

/// WideMemPass 内部使用的 site 描述
struct WideMemSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    base_reg: u8,
    base_off: i64,
    width: u32,
}

/// 扫描 wide_mem 模式（从 matcher.rs 的 scan_wide_mem 迁移）
fn scan_wide_mem_sites(insns: &[BpfInsn]) -> Vec<WideMemSite> {
    // 复用现有 matcher::scan_wide_mem 逻辑
    let raw_sites = crate::matcher::scan_wide_mem(insns);
    raw_sites.into_iter().map(|s| {
        WideMemSite {
            start_pc: s.start_pc,
            old_len: s.old_len,
            dst_reg: s.get_binding("dst_reg").unwrap_or(0) as u8,
            base_reg: s.get_binding("base_reg").unwrap_or(0) as u8,
            base_off: s.get_binding("base_off").unwrap_or(0),
            width: s.get_binding("width").unwrap_or(0) as u32,
        }
    }).collect()
}
```

### 3.2 RotatePass — shift+or 合并为 kfunc call

```rust
/// ROTATE 优化 pass：将 shift+or 模式替换为 bpf_rotate64() kfunc call。
///
/// Pattern:
///   r_dst = r_val >> (64 - shift)   (RSH64_IMM)
///   r_tmp = r_val << shift           (LSH64_IMM)
///   r_dst |= r_tmp                   (OR64_REG)
///   ... 或等价的其他 shift+or rotate 模式
///
/// Replacement:
///   r1 = r_val                       (MOV64_REG, 如果 val 不在 r1)
///   r2 = shift                       (MOV64_IMM)
///   call bpf_rotate64                (kfunc call)
///   r_dst = r0                       (MOV64_REG, 如果 dst 不是 r0)
///
/// 需要 kinsn 支持：JIT 会把 kfunc call 内联为 RORX 指令。
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn name(&self) -> &str {
        "rotate"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // 前提检查：bpf_rotate64 kfunc 是否可用
        if ctx.kfunc_registry.rotate64_btf_id < 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_rotate64 kfunc not available".into(),
                }],
                diagnostics: vec![],
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_rotate_sites(&program.insns);
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            // 安全检查 1: interior branch target
            let has_interior = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc]);
            if has_interior {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
                continue;
            }

            // 安全检查 2: kfunc call 会破坏 r1-r5 (caller-saved)
            // 检查 live_out 中是否有 r1-r5 在 site 末尾仍然活跃
            let site_end = site.start_pc + site.old_len;
            if site_end < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                let caller_saved_conflict = (1u8..=5).any(|r| {
                    r != site.val_reg && live_after.contains(&r)
                });
                if caller_saved_conflict {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: "caller-saved register conflict".into(),
                    });
                    continue;
                }
            }

            safe_sites.push(site);
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
            });
        }

        // 生成替换
        let btf_id = ctx.kfunc_registry.rotate64_btf_id;
        let orig_len = program.insns.len();
        let mut applied = 0;

        // 使用通用的 site replacement 机制
        // （简化版：直接构建新指令流）
        let mut new_insns = Vec::with_capacity(program.insns.len());
        let mut addr_map = vec![0usize; program.insns.len() + 1];
        let mut pc = 0;
        let mut site_idx = 0;

        while pc < program.insns.len() {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].start_pc {
                let site = &safe_sites[site_idx];
                // Emit: r1 = val_reg, r2 = shift, call kfunc, dst = r0
                let mut replacement = Vec::new();
                if site.val_reg != 1 {
                    replacement.push(BpfInsn::mov64_reg(1, site.val_reg));
                }
                replacement.push(BpfInsn::mov64_imm(2, site.shift_amount as i32));
                replacement.push(BpfInsn::call_kfunc(btf_id));
                if site.dst_reg != 0 {
                    replacement.push(BpfInsn::mov64_reg(site.dst_reg, 0));
                }

                // Map old PCs to new
                for j in 0..site.old_len {
                    addr_map[pc + j] = new_pc;
                }

                new_insns.extend(replacement);
                pc += site.old_len;
                site_idx += 1;
                applied += 1;
            } else {
                new_insns.push(program.insns[pc]);
                if program.insns[pc].is_ldimm64() && pc + 1 < program.insns.len() {
                    pc += 1;
                    addr_map[pc] = new_insns.len();
                    new_insns.push(program.insns[pc]);
                }
                pc += 1;
            }
        }
        addr_map[program.insns.len()] = new_insns.len();

        // Branch fixup (复用 rewriter 的逻辑或内联)
        fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: vec![],
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}

struct RotateSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    val_reg: u8,
    shift_amount: u32,
}

fn scan_rotate_sites(insns: &[BpfInsn]) -> Vec<RotateSite> {
    let mut sites = Vec::new();
    let n = insns.len();

    let mut pc = 0;
    while pc + 2 < n {
        // Pattern: RSH64_IMM(dst, 64-S) ; LSH64_IMM(tmp, S) ; OR64_REG(dst, tmp)
        // 或变体: LSH64_IMM(dst, S) ; RSH64_IMM(tmp, 64-S) ; OR64_REG(dst, tmp)
        let i0 = &insns[pc];
        let i1 = &insns[pc + 1];
        let i2 = &insns[pc + 2];

        if let Some(site) = try_match_rotate(i0, i1, i2, pc) {
            let len = site.old_len;
            sites.push(site);
            pc += len;
        } else {
            pc += 1;
        }
    }

    sites
}

fn try_match_rotate(
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    pc: usize,
) -> Option<RotateSite> {
    // Pattern A: dst = val >> (64 - S); tmp = val << S; dst |= tmp
    let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
    let is_lsh = i1.code == (BPF_ALU64 | BPF_LSH | BPF_K);
    let is_or = i2.code == (BPF_ALU64 | BPF_OR | BPF_X);

    if is_rsh && is_lsh && is_or {
        let rsh_amount = i0.imm as u32;
        let lsh_amount = i1.imm as u32;

        // 必须满足 rsh + lsh == 64
        if rsh_amount + lsh_amount == 64 {
            let dst = i0.dst_reg();
            let tmp = i1.dst_reg();

            // OR 必须是 dst |= tmp
            if i2.dst_reg() == dst && i2.src_reg() == tmp {
                return Some(RotateSite {
                    start_pc: pc,
                    old_len: 3,
                    dst_reg: dst,
                    val_reg: dst, // 原始值在 dst 中（被 rsh 覆盖前）
                    shift_amount: lsh_amount,
                });
            }
        }
    }

    // Pattern B: 反向 (LSH first, RSH second)
    let is_lsh_first = i0.code == (BPF_ALU64 | BPF_LSH | BPF_K);
    let is_rsh_second = i1.code == (BPF_ALU64 | BPF_RSH | BPF_K);

    if is_lsh_first && is_rsh_second && is_or {
        let lsh_amount = i0.imm as u32;
        let rsh_amount = i1.imm as u32;

        if lsh_amount + rsh_amount == 64 {
            let dst = i0.dst_reg();
            let tmp = i1.dst_reg();

            if i2.dst_reg() == dst && i2.src_reg() == tmp {
                return Some(RotateSite {
                    start_pc: pc,
                    old_len: 3,
                    dst_reg: dst,
                    val_reg: dst,
                    shift_amount: lsh_amount,
                });
            }
        }
    }

    None
}

/// 内联的 branch fixup 函数（与 rewriter.rs 中的逻辑相同）
fn fixup_branches_inline(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
) {
    let old_n = old_insns.len();
    let mut old_pc = 0;
    while old_pc < old_n {
        let insn = &old_insns[old_pc];
        if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let new_pc = addr_map[old_pc];
            let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
            if old_target <= old_n {
                let new_target = addr_map[old_target];
                if new_pc < new_insns.len() && new_insns[new_pc].is_jmp_class() {
                    let new_off = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].off = new_off as i16;
                }
            }
        }
        old_pc = if insn.is_ldimm64() { old_pc + 2 } else { old_pc + 1 };
    }
}
```

### 3.3 HelperFirewallPass — 安全加固：危险 helper 防火墙

```rust
/// 安全加固 pass：阻断危险 BPF helper 调用。
///
/// 将指定的 helper call 替换为 `r0 = -EPERM; goto next`，
/// 使程序继续执行但 helper 实际不被调用。
///
/// 用途：
/// - 中和恶意 BPF 程序的 bpf_probe_read_kernel 调用
/// - 阻止 bpf_send_signal 等特权 helper
/// - 运行时 live patching：发现漏洞后立即禁用危险 helper
pub struct HelperFirewallPass {
    /// 要阻断的 helper ID 列表
    pub blocked_helpers: Vec<u32>,
    /// 替换策略
    pub action: FirewallAction,
}

#[derive(Clone, Debug)]
pub enum FirewallAction {
    /// 替换为 `r0 = -EPERM`（helper 返回错误码）
    ReturnError(i32),
    /// 替换为 `r0 = 0`（静默成功但不执行）
    ReturnZero,
    /// 替换为 NOP（仅当 caller 不检查 r0 时安全）
    Nop,
}

impl BpfPass for HelperFirewallPass {
    fn name(&self) -> &str {
        "helper_firewall"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Security
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec![] // 不需要额外分析 — 直接匹配 CALL 指令
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let mut applied = 0;
        let mut diagnostics = Vec::new();
        let orig_len = program.insns.len();

        // 扫描所有 CALL 指令
        for pc in 0..program.insns.len() {
            let insn = &program.insns[pc];

            // 只处理 helper call（src_reg == 0），不处理 kfunc call（src_reg == 2）
            // 或 BPF-to-BPF call（src_reg == 1）
            if insn.is_call() && insn.src_reg() == 0 {
                let helper_id = insn.imm as u32;

                if self.blocked_helpers.contains(&helper_id) {
                    // 替换 CALL 为 MOV r0, error_code
                    match &self.action {
                        FirewallAction::ReturnError(code) => {
                            program.insns[pc] = BpfInsn::mov64_imm(0, *code);
                        }
                        FirewallAction::ReturnZero => {
                            program.insns[pc] = BpfInsn::mov64_imm(0, 0);
                        }
                        FirewallAction::Nop => {
                            program.insns[pc] = BpfInsn::nop();
                        }
                    }

                    applied += 1;
                    diagnostics.push(format!(
                        "blocked helper #{} at pc={} → {:?}",
                        helper_id, pc, self.action
                    ));
                }
            }
        }

        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(), // 长度不变（原地替换）
            details: diagnostics.clone(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: vec![],
            diagnostics,
        })
    }
}
```

### 3.4 CondSelectPass (框架代码)

```rust
/// COND_SELECT 优化 pass：将 branch+mov 模式替换为 bpf_select64() kfunc call。
///
/// Pattern:
///   JNE r_cond, 0, +1    (or other conditional branch)
///   MOV64 r_dst, r_false  (fall-through: condition false)
///   ... label:
///   MOV64 r_dst, r_true   (jump target: condition true)
///
/// Replacement:
///   r1 = r_cond; r2 = r_true; r3 = r_false
///   call bpf_select64
///   r_dst = r0
///
/// 注意：此变换是 policy-sensitive — CMOV 在可预测分支上比 branch 慢。
/// 需要 PGO 数据来判断是否应用。
pub struct CondSelectPass {
    /// 分支预测率阈值：只有 taken_rate < threshold 或 > (1-threshold) 的
    /// "可预测"分支才跳过（保留原始 branch），其余使用 CMOV。
    pub predictability_threshold: f64,
}

impl BpfPass for CondSelectPass {
    fn name(&self) -> &str {
        "cond_select"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness", "pgo"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if ctx.kfunc_registry.select64_btf_id < 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_select64 kfunc not available".into(),
                }],
                diagnostics: vec![],
            });
        }

        // PGO-guided 决策：获取 branch profile
        let pgo_analysis = PGOAnalysis { profiling_data: None };
        let pgo = analyses.get(&pgo_analysis, program);

        let mut skipped = Vec::new();
        let mut applied = 0;

        // 扫描 conditional branch + mov 模式
        // ... （模式匹配逻辑类似 RotatePass）

        // 对于每个 candidate site:
        // 1. 检查 PGO 数据 — 如果分支高度可预测则跳过
        // 2. 检查 liveness — caller-saved 寄存器冲突
        // 3. 检查 branch target — 安全性
        // 4. 应用变换

        // 框架代码，具体模式匹配在实现时补充

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}
```

### 3.5 BranchFlipPass (框架代码)

```rust
/// BRANCH_FLIP 优化 pass：基于 PGO 数据重排 if/else body。
///
/// 如果分支的 taken path（jump target）是 hot path，
/// 而 fall-through path 是 cold path，则翻转条件使 hot path 成为 fall-through。
/// 这对现代 CPU 的分支预测器有利（fall-through 是默认预测方向）。
///
/// 不需要 kinsn — 纯 BPF 指令重排。
pub struct BranchFlipPass {
    /// 最低 taken rate 差异才翻转（避免噪声）
    pub min_bias: f64, // e.g., 0.7 表示 taken > 70% 才考虑
}

impl BpfPass for BranchFlipPass {
    fn name(&self) -> &str {
        "branch_flip"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg", "pgo"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let pgo_analysis = PGOAnalysis { profiling_data: None };
        let pgo = analyses.get(&pgo_analysis, program);

        let mut applied = 0;
        let mut skipped = Vec::new();

        // 对每个 conditional branch:
        // 1. 查 PGO 数据中的 taken/not-taken 比率
        // 2. 如果 taken >> not_taken 且超过 min_bias:
        //    翻转条件（JEQ → JNE 等）并交换 fall-through/target
        // 3. 需要 CFG 分析来确定安全性（不能翻转跨 BB 的复杂控制流）

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}
```

### 3.6 SpectreMitigationPass (安全 pass)

```rust
/// Spectre 缓解 pass：在投机执行脆弱位置插入 lfence。
///
/// 扫描 conditional branch 后的内存访问模式：
/// 如果 branch-dependent 的指针被用于内存访问，
/// 在 branch 和内存访问之间插入 lfence 指令（通过 BPF_FENCE_MEM 或 kfunc）。
pub struct SpectreMitigationPass;

impl BpfPass for SpectreMitigationPass {
    fn name(&self) -> &str {
        "spectre_mitigation"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Security
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // 框架代码 — 具体实现需要：
        // 1. 识别 Spectre v1 pattern: branch → array index → memory access
        // 2. 在 branch 和 memory access 之间插入 barrier
        // 3. 使用 BPF_ST_NOSPEC 指令或等价 kfunc

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: false,
            sites_applied: 0,
            sites_skipped: vec![],
            diagnostics: vec!["spectre mitigation not yet implemented".into()],
        })
    }
}
```

---

## 4. PassManager 使用示例

### 4.1 构建 Pipeline

```rust
/// 构建默认的优化 pipeline。
pub fn build_default_pipeline() -> PassManager {
    let mut pm = PassManager::new();

    // 注册分析
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);

    // 添加 pass（按顺序执行）
    // 1. 纯 BPF 指令优化（不需要 kinsn）
    pm.add_pass(WideMemPass);

    // 2. 需要 kinsn 的优化
    pm.add_pass(RotatePass);
    pm.add_pass(CondSelectPass { predictability_threshold: 0.8 });

    // 3. PGO-guided 优化
    pm.add_pass(BranchFlipPass { min_bias: 0.7 });

    pm
}

/// 构建安全加固 pipeline。
pub fn build_security_pipeline(blocked_helpers: Vec<u32>) -> PassManager {
    let mut pm = PassManager::new();

    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);

    pm.add_pass(HelperFirewallPass {
        blocked_helpers,
        action: FirewallAction::ReturnError(-1), // -EPERM
    });
    pm.add_pass(SpectreMitigationPass);

    pm
}

/// 构建完整 pipeline（优化 + 安全）。
pub fn build_full_pipeline(blocked_helpers: Vec<u32>) -> PassManager {
    let mut pm = PassManager::new();

    // 分析
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);

    // 安全 pass 先执行（确保安全性）
    pm.add_pass(HelperFirewallPass {
        blocked_helpers,
        action: FirewallAction::ReturnError(-1),
    });
    pm.add_pass(SpectreMitigationPass);

    // 然后是优化 pass
    pm.add_pass(WideMemPass);
    pm.add_pass(RotatePass);
    pm.add_pass(CondSelectPass { predictability_threshold: 0.8 });
    pm.add_pass(BranchFlipPass { min_bias: 0.7 });

    pm
}
```

### 4.2 端到端使用

```rust
/// 端到端示例：从 kernel 获取程序 → 优化 → REJIT
fn optimize_program(prog_id: u32, ctx: &PassContext) -> anyhow::Result<()> {
    // 1. 获取原始 bytecode
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    if orig_insns.is_empty() {
        return Ok(());
    }

    // 2. 构建 BpfProgram IR
    let meta = ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };
    let mut program = BpfProgram::new(orig_insns.clone(), meta);

    // 3. 运行 pass pipeline
    let pm = build_default_pipeline();
    let result = pm.run(&mut program, ctx)?;

    // 4. 检查是否有变换
    if !result.program_changed {
        println!("prog {}: no optimizations applied", prog_id);
        return Ok(());
    }

    println!(
        "prog {} ({}): {} passes, {} sites applied, {} → {} insns",
        prog_id,
        info.name_str(),
        result.pass_results.len(),
        result.total_sites_applied,
        orig_insns.len(),
        program.insns.len(),
    );

    for pr in &result.pass_results {
        if pr.sites_applied > 0 {
            println!("  {}: {} sites applied", pr.pass_name, pr.sites_applied);
        }
    }

    // 5. 提交 REJIT
    bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &[])?;
    println!("  REJIT successful");

    Ok(())
}
```

---

## 5. 与现有代码的集成方案

### 5.1 迁移路径（渐进式）

目标是从 ad-hoc `matcher.rs` + `rewriter.rs` + `emit.rs` 架构迁移到 pass 框架，但保持向后兼容。

**阶段 1：引入框架 trait 和 PassManager（不改现有 pass）**

```
daemon/src/
├── main.rs          # 不变
├── bpf.rs           # 不变
├── insn.rs          # 不变
├── matcher.rs       # 保留，作为 WideMemPass 的内部实现
├── emit.rs          # 保留，作为 WideMemPass 的内部实现
├── rewriter.rs      # 保留，作为通用的 site→insn 替换 + branch fixup 工具
│
├── pass/            # 新增目录
│   ├── mod.rs       # BpfPass trait, PassResult, PassContext
│   ├── program.rs   # BpfProgram IR
│   ├── manager.rs   # PassManager
│   └── analysis/
│       ├── mod.rs   # Analysis trait, AnalysisCache
│       ├── cfg.rs
│       ├── liveness.rs
│       ├── branch_targets.rs
│       ├── kfunc.rs
│       └── pgo.rs
│
├── passes/          # 具体 pass 实现
│   ├── mod.rs
│   ├── wide_mem.rs  # WideMemPass — 内部调用 matcher::scan_wide_mem
│   ├── rotate.rs    # RotatePass
│   ├── cond_select.rs
│   ├── branch_flip.rs
│   ├── helper_firewall.rs
│   └── spectre.rs
│
└── pipeline.rs      # 预定义 pipeline 构建函数
```

**阶段 2：main.rs 支持两种模式**

```rust
// main.rs 新增 pipeline 模式
enum Command {
    // ... 现有命令
    Enumerate,
    Rewrite { prog_id: u32 },
    Apply { prog_id: u32 },
    ApplyAll,

    // 新增：pipeline 模式
    Pipeline {
        #[arg(long, default_value = "default")]
        profile: String, // "default", "security", "full"
    },
}
```

**阶段 3：逐步迁移各 pass**

1. `WideMemPass`：包装 `matcher::scan_wide_mem()` + `rewriter::rewrite()` + `emit::emit_wide_mem()`
2. `RotatePass`：新写 pattern match + emit（现有代码没有 rotate matcher）
3. `HelperFirewallPass`：新写（现有代码没有安全 pass）
4. 其他 pass 按需添加

**阶段 4：删除旧接口**

当所有命令都切换到 pipeline 模式后，删除直接使用 `matcher::scan_all()` + `rewriter::rewrite()` 的旧代码路径。

### 5.2 共享基础设施

现有的这些代码应该保留并被 pass 框架复用：

| 模块 | 保留原因 |
|------|---------|
| `insn.rs` | `BpfInsn` 结构体和编解码 — 所有 pass 都需要 |
| `bpf.rs` | Kernel syscall 封装 — pipeline 的输入输出 |
| `rewriter.rs::fixup_branches()` | Branch offset 修正 — 多个 pass 共用 |
| `matcher.rs::scan_wide_mem()` | WideMemPass 的内部实现 |
| `emit.rs::emit_wide_mem()` | WideMemPass 的内部实现 |

### 5.3 rewriter.rs 的角色变化

当前 `rewriter.rs` 的 `rewrite()` 函数同时做了两件事：
1. 根据 `RewriteSite` 列表构建新 insn 流（site → replacement）
2. 修正 branch offset（addr_map based fixup）

在 pass 框架中：
- **职责 1（site 替换）**：每个 pass 自己做，或者抽取为通用的 `apply_sites()` 工具函数
- **职责 2（branch fixup）**：抽取为独立的 `fixup_branches(old_insns, new_insns, addr_map)` 工具函数，所有 pass 共用

```rust
// rewriter.rs 新增公共接口
pub mod rewrite_utils {
    use crate::insn::BpfInsn;

    /// 根据 old→new 地址映射修正所有 branch/jump offset。
    /// 这是多个 pass 共用的基础设施。
    pub fn fixup_branches(
        new_insns: &mut [BpfInsn],
        old_insns: &[BpfInsn],
        addr_map: &[usize],
    ) -> anyhow::Result<()> {
        // ... 现有 fixup_branches 逻辑
        Ok(())
    }

    /// 通用的 site 替换 + branch fixup。
    /// 接收 (old_insns, sites, emit_fn) → new_insns
    pub fn apply_sites<F>(
        insns: &[BpfInsn],
        sites: &[(usize, usize)], // (start_pc, old_len)
        emit_fn: F,
    ) -> anyhow::Result<Vec<BpfInsn>>
    where
        F: Fn(usize) -> anyhow::Result<Vec<BpfInsn>>, // site_index → replacement insns
    {
        // 通用替换逻辑
        todo!()
    }
}
```

---

## 6. Verifier 信息和 PGO 信息的获取与使用

### 6.1 Verifier 信息导出

**当前方案（已实现，无需内核修改）：解析 verifier log**

不修改内核，通过 `log_level=2` 的 verifier log 文本获取 per-insn 寄存器信息。
已实现：`daemon/src/verifier_log.rs`（433 行，33 tests）。

**两种触发时机**：

```rust
// 时机 A：在 BPF_PROG_REJIT 时设置 log_level=2，解析返回的 log_buf
fn rejit_with_verifier_log(fd: RawFd, new_insns: &[BpfInsn]) -> anyhow::Result<VerifierInfoResult> {
    let mut log_buf = vec![0u8; 1 << 20]; // 1MB，大程序时可能需要动态扩容并重试
    let log_text = bpf::bpf_prog_rejit_with_log(fd, new_insns, &mut log_buf)?;
    let per_insn = crate::verifier_log::parse_verifier_log(&log_text, new_insns.len())?;
    Ok(VerifierInfoResult { per_insn_state: Some(per_insn), ..Default::default() })
}

// 时机 B：首次 enumerate 时，对 GET_ORIGINAL bytecode 用临时 BPF_PROG_LOAD
// 不实际运行，仅用于触发 verifier 并提取 log
fn probe_verifier_info(orig_insns: &[BpfInsn], prog_type: u32, btf_id: u32) -> anyhow::Result<VerifierInfoResult> {
    let mut log_buf = vec![0u8; 1 << 20];
    // BPF_PROG_LOAD 带 log_level=2；即使 load 成功，主要目的是拿 log
    let (_, log_text) = bpf::bpf_prog_load_with_log(orig_insns, prog_type, btf_id, &mut log_buf)?;
    let per_insn = crate::verifier_log::parse_verifier_log(&log_text, orig_insns.len())?;
    Ok(VerifierInfoResult { per_insn_state: Some(per_insn), ..Default::default() })
}
```

**能提取的信息**（来自 verifier log 的 per-insn 输出）：

```
// verifier log (log_level=2) 示例输出：
// 0: (79) r1 = *(u64 *)(r1 +0)   ; R1_w=ctx(off=0,imm=0)
// 1: (bf) r6 = r1                 ; R1_w=ctx(off=0,imm=0) R6_w=ctx(off=0,imm=0)
// 5: (b7) r2 = 42                 ; R2_w=42
// 7: (25) if r3 > 0x100 goto pc+3 ; R3_w=scalar(umin=0,umax=256,var_off=(0x0; 0xff))
```

从上面可解析出：
- **寄存器类型**：`ctx`、`scalar`、`map_value`、`ptr_to_map` 等
- **寄存器值范围**：`umin`/`umax`/`smin`/`smax`
- **已知常量**：`R2_w=42`（verifier 推断出确定值）
- **指针 offset**：`off=0`

**用途**：

| 分析/Pass | 使用的 verifier 信息 |
|-----------|---------------------|
| ConstPropPass | `known_value` → 常量折叠，将已知常量的 load 替换为 MOV IMM |
| WideMemPass | `reg_type == PTR_TO_*` → 确认 base 是有效指针，增强替换安全性 |
| BoundsHardeningPass | `min_value/max_value` → 判断是否需要额外 bounds check |
| CondSelectPass | `known_value` → 如果条件是已知常量，直接优化为无条件跳转 |

**已知限制**：

1. **格式不稳定**：verifier log 是内部实现，非 UAPI；kernel 版本间格式可能变化。解析器需要版本适配，遇到无法识别的格式时静默退化（返回空结果）。
2. **log 截断**：`log_buf` 大小有限（默认 64KB）。大程序（>1000 insns）可能截断。需要动态扩大 `log_size` 重试（从 64KB 开始，失败则翻倍到 1MB、4MB）。
3. **不完整上下文**：用临时 `BPF_PROG_LOAD` 获取 log 时，程序的 map fd 等上下文可能不完整，verifier 可能无法推断深度信息（如 map value 范围）。
4. **POC 可行性**：当前方案足够用于 ConstPropPass 和 BoundsHardeningPass 的 POC 验证；production 阶段如需更可靠的数据，可考虑扩展 `bpf_prog_info`（下面备用方案）。

**备用方案（需要内核修改，暂不实现）**：扩展 `bpf_prog_info`

```c
// include/uapi/linux/bpf.h（备用，当前不实现）
struct bpf_prog_info {
    // ... 现有字段 ...
    __u32 verifier_state_len;
    __aligned_u64 verifier_state;  // 指向 bpf_insn_verifier_state 数组
};

struct bpf_insn_verifier_state {
    __u32 flags;         // IS_CONST, IS_PTR, etc.
    __s64 known_value;
    __s64 min_value;
    __s64 max_value;
    __u32 reg_type;      // SCALAR_VALUE, PTR_TO_CTX, etc.
    __u32 off;
};
```

这个方案更可靠（结构化二进制，不受 log 格式变化影响），但需要内核改动。如果论文评审要求更严谨的数据导出，可作为后续工作。

### 6.2 PGO 数据获取

**当前可用（无需内核改动）**：

```rust
// 1. 程序级别统计
let info = bpf::bpf_prog_get_info(fd, false)?;
let run_cnt = info.run_cnt;       // 需要 BPF_ENABLE_STATS 或 sysctl
let run_time_ns = info.run_time_ns;

// 2. perf branch profiling（用户态）
// 通过 perf_event_open 采样 BPF JIT image 的 branch miss 信息
// 然后反向映射到 BPF insn PC
```

**需要新基础设施（未来）**：

Per-branch taken/not-taken 计数是 PGO 的核心。方案：

**方案 A：BPF instrumentation（不需要内核改动）**

Daemon 在 branch 前插入计数器更新指令（通过 REJIT），收集数据后还原原始程序。

```
原始：  JNE r1, 0, +5
插桩后：
  r_tmp = map_lookup(branch_counters, branch_id)
  if JNE r1, 0, +N:
    *(r_tmp + 0) += 1    // taken
    JA +M
  else:
    *(r_tmp + 8) += 1    // not-taken
    ...
```

缺点：插桩改变程序行为（icache、timing），需要两次 REJIT。

**方案 B：perf branch record（不需要内核改动）**

通过 `perf record -e branches:u -j any` 采样 JIT image 的分支行为，然后用 BPF prog 的 JIT symbol 映射回 BPF insn PC。

```rust
// 解析 perf branch record
struct PerfBranchSample {
    from_ip: u64,   // JIT image 中的 branch 指令地址
    to_ip: u64,     // 跳转目标地址
    taken: bool,
}

// 映射回 BPF insn PC
// 需要 bpf_prog_info.jited_ksyms + jited_func_lens 来定位 JIT image
// 然后用 jited_line_info 映射回 insn PC
```

优点：零运行时开销，使用现有基础设施。
缺点：采样精度取决于 perf 采样率；需要 JIT image → insn 反向映射。

**方案 C：内核 per-branch 计数器（需要内核改动，最精确）**

```c
// 新 sysctl 或 prog flag
// 启用后，kernel 在每个 conditional branch 的 JIT 代码中插入计数器更新
// 类似 gcc -fprofile-arcs
struct bpf_branch_info {
    __u32 insn_idx;
    __u64 taken_cnt;
    __u64 not_taken_cnt;
};

// 通过 GET_INFO 获取
__u32 nr_branch_info;
__aligned_u64 branch_info;  // 指向 bpf_branch_info 数组
```

**推荐实现顺序**：

1. **Phase 1（现在）**：只用 `run_cnt/run_time_ns` 做程序级别的 hot/cold 判断
2. **Phase 2**：用 perf branch record 做采样级别的 per-branch profiling
3. **Phase 3（如果论文需要）**：实现内核 per-branch 计数器

### 6.3 PGO 数据在 Pass 框架中的流转

```
┌─────────────┐     ┌──────────────┐     ┌────────────┐
│ Profiler     │────>│ PGOAnalysis  │────>│ Passes     │
│ (收集数据)   │     │ (分析缓存)   │     │ (使用数据)  │
└─────────────┘     └──────────────┘     └────────────┘
      │                                        │
      │  perf branch record                    │
      │  bpf_prog_info.run_cnt                 │  BranchFlipPass: taken/not-taken ratio
      │  instrumented counters                 │  CondSelectPass: 可预测性判断
      │                                        │  ConstPropPass: hot path 优先
      └────────────────────────────────────────┘
```

Daemon 的主循环：

```rust
loop {
    // 1. 枚举 live programs
    for prog_id in bpf::iter_prog_ids() {
        // 2. 收集 profiling 数据
        let profiling = profiler.collect(prog_id)?;

        // 3. 构建 BpfProgram + PassContext
        let mut program = fetch_program(prog_id)?;
        let ctx = build_context(profiling);

        // 4. 运行 pass pipeline
        let pm = build_default_pipeline();
        let result = pm.run(&mut program, &ctx)?;

        // 5. 如果有优化，提交 REJIT
        if result.program_changed {
            submit_rejit(prog_id, &program)?;
        }
    }

    // 6. 等待一段时间再扫描
    std::thread::sleep(std::time::Duration::from_secs(30));
}
```

---

## 7. 设计决策总结

| 决策 | 选择 | 理由 |
|------|------|------|
| IR 表示 | 线性 insn + annotation | BPF 变换都是 peephole 性质，BB-based 过重 |
| Analysis 缓存 | TypeId-indexed HashMap | Rust 的 Any trait 天然支持，类型安全 |
| Analysis invalidation | 全量 invalidate on change | 简单；BPF 程序通常 <5000 insns，重算成本低 |
| Pass 排序 | 用户指定顺序 | 初期够用；未来可加 pass dependency DAG |
| 安全 pass 优先 | 安全 pass 在优化 pass 之前 | 确保安全加固不被优化 undo |
| Branch fixup | 每个 pass 自己做或用共用工具 | 避免全局 fixup 的复杂度 |
| Verifier 信息 | 解析 verifier log (log_level=2) | 零内核改动；已实现 verifier_log.rs（433行，33 tests）；备用方案为扩展 GET_INFO |
| PGO Phase 1 | run_cnt/run_time_ns only | 已有基础设施，零改动 |
| PGO Phase 2 | perf branch record | 零运行时开销 |

---

## 8. 与论文的对应

| 论文章节 | 框架组件 |
|---------|---------|
| Insight 1: LLVM-pass-like framework | PassManager + BpfPass trait |
| Insight 2: mechanism/policy separation | PassContext (kinsn registry) / pass pipeline (policy) |
| §3 变换分类 | 各 Pass 实现 |
| §4.1 daemon 架构 | Pipeline + AnalysisCache |
| §4.2 工作流 | `optimize_program()` 端到端流程 |
| §5 评估 | PassResult 统计 + transform_log |

框架设计直接支撑论文的核心主张：BpfReJIT 提供了一个**可扩展的编译框架**——新优化只需实现 `BpfPass` trait 并注册到 `PassManager`，无需修改内核代码。
