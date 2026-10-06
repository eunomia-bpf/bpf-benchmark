# BPF Live Patching（LivePatchPass）实现级设计

日期：2026-03-26  
状态：设计草案  
范围：`daemon/` 用户态控制面与 pass 框架；不修改内核 verifier，只对已加载 BPF 字节码做热缓解。

## 1. 目标与边界

### 1.1 目标

基于 `docs/tmp/20260326/bpf_live_patching_research_20260326.md` 的结论，将当前仓库里的 Phase-1 `live_patch` 原型演进为**按 CVE 驱动**的 LivePatchPass 框架：

1. 用 YAML 维护漏洞签名数据库。
2. 以“每个 CVE 一个 matcher + 一个 patch template 引用”的方式识别已加载程序中的危险站点。
3. 对站点插入显式 runtime guard / sanitization / pointer refresh / edge isolation。
4. 通过现有 `REJIT + re-verify + rollback` 路径提交热补丁。
5. 提供 `patch` / `audit` / `watch` / `serve` 集成，而不是把安全热补丁混在纯优化路径里。

### 1.2 非目标

本设计不做以下事情：

1. 不修 verifier 本身。
2. 不试图覆盖所有 verifier CVE；只覆盖研究报告中判定为适合 bytecode-level hot patch 的那一类。
3. 不承诺零语义变化；允许 fail-closed 的保守缓解。
4. 不在 host 上运行内核/BPF 运行时测试；集成验证必须走 VM。

## 2. 现状与设计出发点

当前仓库已经有三块直接可复用基础：

1. `daemon/src/pass.rs` 已提供 `BpfPass`、`PassContext`、`PassManager`、analysis cache、transform attribution。
2. `daemon/src/passes/skb_load_bytes.rs`、`daemon/src/passes/bounds_check_merge.rs` 已证明“扫描站点 -> 插入/替换指令 -> `addr_map` -> `fixup_all_branches()` -> `remap_annotations()`”这条 rewrite 模式是成熟的。
3. `daemon/src/commands.rs` 的 `try_apply_one()` 已有 `REJIT`、verifier log 捕获、失败归因、禁用 pass 并重试的回滚框架。

另外，`daemon/src/passes/live_patch.rs` 已经是一个很有价值的 Phase-1 原型：它已经覆盖了四种核心形状：

1. null guard
2. helper 参数净化
3. packet pointer refresh
4. tail-call isolation

但当前实现仍是**启发式 hard-coded 扫描**，缺少：

1. CVE 签名数据库
2. kernel 版本 gating
3. per-CVE matcher 注册表
4. patch template 元数据
5. audit-only 输出
6. 细粒度 rollback 粒度

因此，本设计的核心不是推翻现有 `live_patch.rs`，而是把它拆成**可审计、可扩展、可按 CVE 启用**的框架。

## 3. 总体架构

建议把 LivePatch 设计成“同一实现类的多实例 pass”，而不是一个包打天下的单体 pass。

```text
YAML Signature DB
    ↓ load
SignatureDb
    ↓ resolve active CVEs by kernel range
Vec<Arc<CveSignature>>
    ↓ build_patch_pipeline()
LivePatchPass { signature = CVE-... }   one pass per CVE
    ↓
matcher.match_sites(bytecode, prog_info, analyses)
    ↓
Vec<VulnerableSite>
    ↓
template.emit(site)
    ↓
RewritePlan { pre/post insertions, replacements, safe exits }
    ↓
rewrite + addr_map + full branch fixup + annotation remap
    ↓
REJIT + re-verify
    ↓
success / audit report / rollback
```

这样做有两个直接收益：

1. **复用现有 rollback**。`try_apply_one()` 当前按 pass 名称禁用失败 pass；把 pass 粒度收敛到“每个 CVE 一个 pass”以后，verifier rejection 可以直接回滚到单个 CVE，而不是禁用整个 `live_patch` 家族。
2. **审计清晰**。最终日志、JSON 结果、watch/serve 事件都能直接落到 `live_patch/CVE-2024-56702` 这种粒度。

## 4. 模块划分

建议把当前 `daemon/src/passes/live_patch.rs` 重构成目录模块：

```text
daemon/src/passes/live_patch/
  mod.rs
  db.rs               # YAML 加载、kernel range 解析、active CVE 选择
  signature.rs        # CveSignature / MatchSpec / PatchSpec
  matcher.rs          # CveMatcher trait + registry
  templates.rs        # 四类 patch template
  site.rs             # VulnerableSite / PatchPlan / AuditFinding
  engine.rs           # LivePatchPass::run() 主流程
  conflicts.rs        # 重叠站点合并与优先级
```

保留对外导出的 `LivePatchPass` 名称，但内部每个实例只绑定一个 `CveSignature`：

```rust
pub struct LivePatchPass {
    signature: Arc<CveSignature>,
    matcher: Arc<dyn CveMatcher>,
    mode: LivePatchMode,
}
```

`name()` 返回动态名称，例如：

```rust
"live_patch/CVE-2024-56702"
```

`category()` 继续是 `PassCategory::Security`。

## 5. CVE 签名数据库设计

### 5.1 文件布局

建议使用目录式 YAML，而不是把所有条目塞进一个文件：

```text
daemon/signatures/livepatch/
  index.yaml
  CVE-2024-56702.yaml
  CVE-2024-49861.yaml
  CVE-2024-38566.yaml
  ...
```

`index.yaml` 只存启用顺序、默认优先级、以及可选 alias。每个 CVE 文件单独维护，方便审计和 operator override。

### 5.2 Rust 数据结构

```rust
#[derive(Debug, Clone, Deserialize)]
pub struct CveSignature {
    pub cve: String,
    pub title: String,
    pub affected_kernels: KernelRangeSpec,
    pub match_spec: MatchSpec,
    pub patch: PatchSpec,
    pub proof_shift: ProofShift,
    pub priority: u32,
}

#[derive(Debug, Clone, Deserialize)]
pub struct MatchSpec {
    pub matcher_id: String,
    pub prog_types: Vec<u32>,
    pub helper_ids: Vec<i32>,
    pub attach_types: Vec<u32>,
    pub missing_check: Vec<String>,
    pub params: serde_yaml::Value,
}

#[derive(Debug, Clone, Deserialize)]
pub struct PatchSpec {
    pub template: PatchTemplateId,
    pub safe_fallback: SafeFallback,
    pub params: serde_yaml::Value,
}
```

### 5.3 kernel range 设计

这里必须承认一个现实：单靠 upstream 版本号无法完整表达 distro backport。建议数据库拆成两层：

1. `affected_kernels.upstream_range`
2. `affected_kernels.backport_overrides`

MVP 规则：

1. 先按 upstream range 判定。
2. 若命中 `backport_overrides`，则覆盖 upstream 结论。
3. 若当前内核无法精确归类，则默认 `audit-only`，不自动 patch。

可用的数据结构：

```rust
pub struct KernelRangeSpec {
    pub upstream_min: Option<String>,
    pub upstream_max_exclusive: Option<String>,
    pub include_release_regex: Vec<String>,
    pub exclude_release_regex: Vec<String>,
    pub require_unfixed_backport_tag: bool,
}
```

### 5.4 示例 YAML 条目

以下三条是**字段形状示例**；其中 `affected_kernels` 的具体区间应在落地时由 stable/backport 映射表校准，不在本文硬编码成最终权威值。

#### `CVE-2024-56702`：raw tracepoint NULL pointer

```yaml
cve: CVE-2024-56702
title: raw_tp nullable argument dereferenced as trusted non-NULL
affected_kernels:
  upstream_min: "TBD-by-stable-map"
  upstream_max_exclusive: "TBD-by-stable-map"
  include_release_regex: []
  exclude_release_regex: []
  require_unfixed_backport_tag: false
match_spec:
  matcher_id: raw_tp_nullable_arg
  prog_types: [17]          # BPF_PROG_TYPE_RAW_TRACEPOINT
  helper_ids: []
  attach_types: []
  missing_check: ["dominating_null_guard"]
  params:
    ctx_arg_index: 0
    deref_ops: ["ldx_mem", "stx_mem"]
patch:
  template: guard_insertion
  safe_fallback:
    kind: return_0
  params:
    guard_kind: null
    target_reg_origin: raw_tp_arg0
proof_shift:
  avoid_buggy_verifier_logic: true
  relies_on: ["explicit jeq reg,0", "direct safe exit"]
priority: 10
```

#### `CVE-2024-49861`：readonly map write via helper

```yaml
cve: CVE-2024-49861
title: helper may write into readonly or frozen map value
affected_kernels:
  upstream_min: "TBD-by-stable-map"
  upstream_max_exclusive: "TBD-by-stable-map"
  include_release_regex: []
  exclude_release_regex: []
  require_unfixed_backport_tag: false
match_spec:
  matcher_id: helper_write_to_readonly_map
  prog_types: []            # 多 prog_type；不做强限制
  helper_ids: [4, 45, 112, 113, 114, 115, 148]
  attach_types: []
  missing_check: ["readonly_map_write_rejection"]
  params:
    readonly_source: ["frozen_map", "rodata_map"]
    writable_arg_regs: [2, 3]
patch:
  template: sanitization
  safe_fallback:
    kind: redirect_to_stack
  params:
    strategy: stack_scratch_redirect
    zero_fill_bytes: true
proof_shift:
  avoid_buggy_verifier_logic: true
  relies_on: ["stack scratch dst", "no direct write to map value"]
priority: 20
```

#### `CVE-2024-38566`：socket nullable member dereference

```yaml
cve: CVE-2024-38566
title: verifier assumes socket-related pointer is non-NULL
affected_kernels:
  upstream_min: "TBD-by-stable-map"
  upstream_max_exclusive: "TBD-by-stable-map"
  include_release_regex: []
  exclude_release_regex: []
  require_unfixed_backport_tag: false
match_spec:
  matcher_id: nullable_socket_member
  prog_types: []
  helper_ids: []
  attach_types: []
  missing_check: ["dominating_null_guard"]
  params:
    ptr_origin: socket_sk_like
    deref_ops: ["ldx_mem", "stx_mem"]
patch:
  template: guard_insertion
  safe_fallback:
    kind: return_0
  params:
    guard_kind: null
    target_reg_origin: nullable_socket_member
proof_shift:
  avoid_buggy_verifier_logic: true
  relies_on: ["explicit null check before deref"]
priority: 10
```

## 6. 四类 Patch Template

当前 `daemon/src/passes/live_patch.rs` 已经证明四类模板都能在现有 rewrite 基础设施上表达；正式版本只需要把触发条件从“启发式”换成“CVE matcher + YAML 参数”。

### 6.1 Guard insertion

用途：在危险解引用前插入 null / bounds / size check。

输入：

```rust
GuardSite {
    anchor_pc: usize,
    guard_reg: u8,
    guard_kind: GuardKind,   // Null / Bounds / Size
    safe_fallback: SafeFallback,
}
```

发射方式：

1. 在 `anchor_pc` 之前插入比较指令。
2. 若失败则跳到统一 `safe_exit` stub。
3. `safe_exit` 的返回值由 `SafeFallback` 决定。

典型发射：

```text
if rX == 0 goto safe_exit
... original dereference ...
safe_exit:
  r0 = 0
  exit
```

适用 CVE：

1. `CVE-2024-56702`
2. `CVE-2024-38566`
3. `CVE-2025-21852`

### 6.2 Sanitization

用途：在 helper 或危险使用之前把寄存器归零/毒化，或把写目标改到安全栈槽。

输入：

```rust
SanitizeSite {
    anchor_pc: usize,
    strategy: SanitizeStrategy, // ZeroReg / PoisonReg / StackScratchRedirect
    regs: Vec<u8>,
    stack_size: usize,
}
```

常见策略：

1. `mov64 rX, 0`
2. helper 写入目标从 map value ptr 重写到 `fp - off`
3. release 之后把寄存器清零，阻止后续再次使用

适用 CVE：

1. `CVE-2024-49861`
2. `CVE-2024-50164`
3. `CVE-2022-49873`

### 6.3 Pointer refresh

用途：helper / global subprog / extension 返回后，重新从 `ctx` 取 packet root，避免使用 stale packet pointer。

输入：

```rust
PointerRefreshSite {
    call_pc: usize,
    ctx_reg: u8,
    data_reg: u8,
    data_end_reg: u8,
    scratch_reg: u8,
    access_end: i32,
}
```

发射方式：

1. 必要时先保存 `ctx` 到 callee-saved 寄存器。
2. helper 后重新加载 `ctx->data` / `ctx->data_end`。
3. 用 `scratch = data + access_end` 构造显式 bounds guard。
4. 仅在 guard 通过后继续访问。

适用 CVE：

1. `CVE-2024-58098`
2. `CVE-2024-58100`

### 6.4 Edge isolation

用途：把危险 `tail_call` / helper / extension edge 直接 NOP 化或改成安全返回。

输入：

```rust
EdgeIsolationSite {
    anchor_pc: usize,
    action: IsolationAction, // NopOut / ReturnSafe / SkipCallAndContinue
}
```

策略：

1. `tail_call` 改写为 `r0 = safe_ret`
2. 危险 helper 改成 no-op 或安全 helper
3. extension edge 直接 fail-closed

适用 CVE：

1. `CVE-2024-50063`
2. 某些 attach-kind / extension compatibility bypass

## 7. Matcher 设计

### 7.1 核心 trait

```rust
pub trait CveMatcher: Send + Sync {
    fn cve_id(&self) -> &str;
    fn required_analyses(&self) -> &'static [&'static str];
    fn match_sites(
        &self,
        insns: &[BpfInsn],
        prog_info: &LivePatchProgramInfo,
        analyses: &LivePatchAnalysisView,
        signature: &CveSignature,
    ) -> anyhow::Result<Vec<VulnerableSite>>;
}
```

这里的 `prog_info` 不是只含 `prog_type`，而是一个面向 live patch 的 richer view：

```rust
pub struct LivePatchProgramInfo {
    pub prog_id: u32,
    pub prog_name: String,
    pub prog_type: u32,
    pub expected_attach_type: u32,
    pub attach_btf_id: u32,
    pub kernel_release: String,
    pub map_ids: Vec<u32>,
}
```

### 7.2 简单 matcher

简单 matcher 只需要：

1. `prog_type` 过滤
2. helper ID / 指令模式扫描
3. 缺失显式 guard 判断

典型例子：

1. `raw_tp_nullable_arg`
2. `helper_write_to_readonly_map`
3. `nullable_socket_member`

它们可以直接复用当前 `live_patch.rs` 的线性扫描骨架。

### 7.3 复杂 matcher

复杂 matcher 面向 pruning / precision 类漏洞，例如 `CVE-2023-2163` 这类需要 CFG 感知的情况。

复杂 matcher 需要：

1. basic block / CFG
2. dominating guard 检查
3. path-sensitive pattern pruning

实现上不建议把这套逻辑硬塞进 YAML DSL；YAML 只做 coarse filter，真正的复杂逻辑放在 Rust matcher 中。

### 7.4 matcher registry

注册表形式按用户要求设计为：

```rust
pub type MatcherRegistry = HashMap<String, Arc<dyn CveMatcher>>;
```

示例：

```rust
registry.insert("raw_tp_nullable_arg".into(), Arc::new(RawTpNullableArgMatcher));
registry.insert("helper_write_to_readonly_map".into(), Arc::new(ReadonlyMapWriteMatcher));
registry.insert("nullable_socket_member".into(), Arc::new(NullableSocketMemberMatcher));
```

### 7.5 `CVE-2024-49861` 的 matcher 依赖

这类 matcher 不能只看 bytecode；必须结合 live map 元数据。

当前仓库已经具备这条基础链路：

1. `commands.rs` 在构造 `BpfProgram` 时填充 `map_ids`
2. `pass.rs` 的 `BpfProgram` 持有 `map_ids`
3. `analysis/map_info.rs` 的 `MapInfoAnalysis` 能把 `LD_IMM64 + BPF_PSEUDO_MAP_FD` 解析回 live map，并识别 `frozen`

所以 readonly-map matcher 的实现建议是：

1. 先定位 helper 写目标寄存器。
2. 反向追踪该寄存器是否来源于 map lookup / pseudo-map value。
3. 用 `MapInfoAnalysis` 判断 map 是否 `frozen` 或属于 rodata 类 map。
4. 如果没有 dominating redirect/guard，则返回 `SanitizeSite`。

## 8. Patch 应用流程

### 8.1 单个 CVE pass 的 `run()` 流程

```text
1. 检查当前 kernel 是否命中 signature.affected_kernels
2. 运行 matcher，得到 vulnerable sites
3. 若 mode == AuditOnly：
   - 只生成 findings，不改 bytecode
4. 若 mode == Patch：
   - 由 template 生成 RewritePlan
   - 处理冲突与重叠站点
   - 重写指令流
   - 全量 branch fixup
   - annotation remap
   - 返回 changed = true
```

### 8.2 RewritePlan

建议复用当前 `live_patch.rs` 的结构形态：

```rust
pub struct RewritePlan {
    pub pre_insertions: BTreeMap<usize, Vec<InjectedInsn>>,
    pub post_insertions: BTreeMap<usize, Vec<InjectedInsn>>,
    pub replacements: BTreeMap<usize, Vec<BpfInsn>>,
    pub delete_pcs: HashSet<usize>,
    pub needs_safe_exit: bool,
}
```

### 8.3 分支修复

由于模板会改变指令数，必须执行**全量 branch fixup**，不能只修局部跳转。

原因：

1. 条件跳转 offset 会变化
2. pseudo-call 的 `imm` 也是 PC-relative
3. `LD_IMM64` 占两槽，地址映射必须按宽度处理
4. 多个模板叠加后，局部修补极易遗漏

因此建议沿用已有模式：

1. 构造 `addr_map: old_pc -> new_pc`
2. 调用 `passes::utils::fixup_all_branches()`
3. 如有必要，再跑 `eliminate_unreachable_blocks()` 与 `eliminate_nops()`
4. `program.remap_annotations(&addr_map)`

### 8.4 多 CVE 重叠冲突

多个签名可能命中同一位置。建议引入统一冲突规则：

1. 同一 `anchor_pc` 且同类 template：保留优先级更高的 signature。
2. 若一个站点既能“局部 guard”又能“edge isolation”，优先保留侵入性更小的模板。
3. `edge isolation` 只在无法安全 guard/sanitize 时生效。
4. 被抑制的匹配也要保留到 audit 日志里，状态标为 `suppressed_by_higher_priority_patch`。

默认优先级建议：

1. `guard_insertion`
2. `sanitization`
3. `pointer_refresh`
4. `edge_isolation`

## 9. “补丁不能依赖同一个 buggy verifier 逻辑”的实现原则

这是本设计最重要的安全约束。

每个模板都必须满足“proof shift”：

1. **null bug**：不再依赖 verifier 推断 non-NULL，而是在 bytecode 中显式 `jeq reg, 0`。
2. **readonly-map write bug**：不再依赖 verifier 拒绝非法写，而是把写目标改到 stack scratch，彻底避开只读 map value。
3. **stale packet pointer bug**：不再依赖旧 pointer id；helper 后重新从 `ctx` 加载 `data/data_end` 并重建 bounds check。
4. **tail-call / extension bypass**：不再依赖 verifier 对跨 hook 兼容性的推断，而是直接隔离危险 edge。

因此，re-verify 的地位是：

1. 第二道门
2. defense in depth
3. 不是热补丁正确性的唯一来源

## 10. 与 daemon 的集成

### 10.1 CLI 设计

新增独立子命令，而不是复用 `apply`：

```text
bpfrejit-daemon patch --cve CVE-2024-56702
bpfrejit-daemon patch --all
bpfrejit-daemon patch --all --audit
bpfrejit-daemon patch --cve CVE-2024-49861 --prog-id 1234
```

建议 CLI 形态：

```rust
Patch {
    #[arg(long)]
    cve: Vec<String>,
    #[arg(long)]
    all: bool,
    #[arg(long)]
    audit: bool,
    #[arg(long)]
    prog_id: Option<u32>,
}
```

语义：

1. `--cve`：只启用指定 CVE。
2. `--all`：启用当前 kernel 上所有 active signatures。
3. `--audit`：只报告，不 patch。
4. `--prog-id`：缩小到单个 live program；省略则扫描全部 live programs。

### 10.2 pipeline 构造

建议新增：

```rust
pub fn build_patch_pipeline(active: &[Arc<CveSignature>], mode: LivePatchMode) -> PassManager
```

其行为是：

1. 注册标准 analyses：`cfg`、`branch_targets`、`liveness`、`map_info`
2. 为每个 active signature 创建一个 `LivePatchPass`
3. 按 `signature.priority` 排序加入 pipeline

### 10.3 `PassContext` 扩展

为了满足“matcher takes bytecode + prog_info”的要求，建议给 `PassContext` 增加一个 live patch 专用配置：

```rust
pub struct LivePatchContext {
    pub mode: LivePatchMode,
    pub kernel_release: String,
    pub prog_info: Option<LivePatchProgramInfo>,
}
```

`try_apply_one()` 已经拿到了 `bpf_prog_info`，填充这个字段不困难。

### 10.4 serve/watch 模式

#### watch

`watch` 模式增加安全模式参数：

1. `watch --patch-all-active-cves`
2. `watch --audit-active-cves`

行为：

1. 新程序出现时先跑 active signatures。
2. 若无命中，进入 no-op 集合。
3. 若命中且为 `Patch` 模式，调用 patch pipeline + REJIT。
4. 若命中且为 `AuditOnly`，记录 finding，不改程序。

为防止重复处理，watch 侧建议维护：

```text
(prog_id, loaded_tag, cve_id) -> applied/audited
```

其中 `loaded_tag` 可由 `(prog_id, orig_insn_hash)` 组成。

#### serve

新增 JSON 命令：

```json
{"cmd":"patch","prog_id":123,"cves":["CVE-2024-56702"],"audit":false}
{"cmd":"patch-all","audit":true}
```

返回结构建议独立于 `OptimizeOneResult`，因为 patch/audit 需要 finding 级输出：

```rust
pub struct PatchOneResult {
    pub status: String,
    pub program: ProgramInfo,
    pub summary: PatchSummary,
    pub findings: Vec<AuditFinding>,
    pub attempts: Vec<AttemptRecord>,
    pub timings_ns: TimingsNs,
}
```

### 10.5 rollback 集成

这是“每个 CVE 一个 pass”的最大价值点。

当前 `try_apply_one()` 的回滚逻辑已经是：

1. 解析 verifier log
2. 归因到 pass
3. 禁用 pass
4. 重试

只要 `LivePatchPass::name()` 变成 `live_patch/CVE-...`，就能直接把 rollback 粒度缩小到单个 CVE：

1. `live_patch/CVE-2024-56702` 失败，不影响 `live_patch/CVE-2024-49861`
2. audit 结果仍保留
3. 整体上比“禁掉整个 live_patch pass”安全得多

## 11. 测试计划

### 11.1 host 侧单元测试

入口走仓库已有的：

```text
make daemon-tests
```

覆盖面：

1. YAML loader 与 schema 校验
2. kernel range resolver
3. 每个 matcher 的正例/反例
4. 每个 template 的发射与 `addr_map`
5. 重叠站点冲突合并
6. audit-only 不改写 bytecode
7. unaffected programs 不被修改

建议至少补以下 matcher fixture：

1. `CVE-2024-56702`：raw_tp 缺 null guard 的正例、已有 guard 的负例、branch target 负例
2. `CVE-2024-49861`：helper 写 frozen map 的正例、写普通 map 的负例、已重定向到 stack 的负例
3. `CVE-2024-38566`：socket-like nullable ptr 缺 guard 的正例、已有 guard 的负例

### 11.2 REJIT / re-verify 集成测试

这类测试必须在 VM 跑，不在 host kernel 上执行。

入口建议挂到现有 VM 流程中，至少纳入：

```text
make vm-test
```

需要新增的 VM 场景：

1. `patch --cve CVE-2024-56702` 对命中程序成功 REJIT
2. `patch --cve CVE-2024-49861` 对命中程序成功 REJIT
3. `patch --all --audit` 只报告、不改程序
4. 人工构造一个会触发 verifier rejection 的坏补丁，验证 rollback 会禁用对应 `live_patch/CVE-...` 并重试

### 11.3 不受影响程序

必须有专门测试验证：

1. 未命中 matcher 的程序 `insns` 完全不变
2. 已有显式 guard 的程序不重复插 guard
3. audit-only 模式下 `changed=false`
4. 未命中 active kernel range 的 signature 不参与 patch

### 11.4 分支修复回归

每个会增加/删除指令的模板都应有分支修复测试：

1. 条件跳转
2. `LD_IMM64`
3. pseudo-call / subprog
4. 多站点叠加后的 offset 稳定性

## 12. 安全保证

实现完成后，LivePatchPass 应该提供以下保证：

1. **补丁绕开缺陷 verifier 规则**。所有模板都以显式 runtime check / redirection 为核心，不把安全性寄托在原有 buggy inference 上。
2. **始终 re-verify**。补丁提交仍必须经过现有 `BPF_PROG_REJIT` verifier 路径。
3. **失败必回滚**。一旦 re-verify 失败，沿用 `commands.rs` 里的 pass attribution + disable + retry 逻辑。
4. **不命中则不改**。matcher 只对保守可识别模式下手。
5. **可审计**。每条 finding 记录 `cve_id / pc / template / action / reason`。

## 13. 限制与保守策略

为了避免安全 pass 自己引入新风险，建议默认开启以下保守限制：

1. 单个 CVE pass 的最大指令增长上限，例如 `max(+64 insns, +20%)`
2. 单个程序可应用的最大 patch 站点数
3. 若 kernel range 判定不明确，则降级为 audit-only
4. 若冲突解析后仍不确定，放弃 patch 并报告 `ambiguous_site_conflict`
5. 若无法找到安全 scratch reg / stack 槽，则跳过该站点而不是勉强 patch

## 14. 建议实施顺序

### Phase 1：框架拆分

1. 把现有 `live_patch.rs` 拆成 matcher/template/engine 三层
2. 保留当前 null guard / helper sanitize / pointer refresh / tail-call isolation 的 emitter 逻辑
3. 引入 `LivePatchMode`

### Phase 2：落地前三个 CVE

1. `CVE-2024-56702`
2. `CVE-2024-49861`
3. `CVE-2024-38566`

理由：这三类都属于研究报告中“高可行”且模板明确的类型。

### Phase 3：CLI + audit + watch/serve

1. 新增 `patch` 子命令
2. 新增 audit-only 输出
3. watch/serve 接 active signature 集

### Phase 4：复杂 matcher

1. 引入 CFG-aware matcher
2. 先覆盖 pruning bug 中“局部 exploit gadget 仍可签名”的子集

## 15. 结论

这套设计与仓库现状是对齐的：

1. 低层 rewrite 机制已经存在；
2. `REJIT + re-verify + rollback` 已经存在；
3. `live_patch.rs` 当前原型已经验证了四类模板的可表达性；
4. 真正缺的是“按 CVE 驱动的签名库、matcher 注册表、template 元数据和审计接口”。

因此，LivePatchPass 最合理的演进路径不是继续堆启发式规则，而是升级为：

> YAML 签名库 + 每 CVE 一 matcher + 四类模板 + 每 CVE 一 pass + 现有 verifier rollback 复用

这既符合研究报告中的 trust model，也能直接落到当前 daemon 的实现骨架上。
