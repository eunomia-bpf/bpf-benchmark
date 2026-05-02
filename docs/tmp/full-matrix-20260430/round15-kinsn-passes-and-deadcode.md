# Round 15：kinsn passes 启用状态 + dead code 审计

**生成时间**：2026-05-01  
**基于 commits**：ae45fc92, cff84bff, 4522507e, 758e90d1, ad3e401a 及之前所有

---

## Part 1：kinsn passes 清单 + 启用状态

### 1.1 所有 pass 文件列表

`bpfopt/crates/bpfopt/src/passes/` 下注册的 pass（来自 `mod.rs::PASS_REGISTRY`）：

| 序号 | pass 名 | 源文件 | 是否 kinsn-based | 依赖 kfunc 名 |
|------|---------|--------|-----------------|--------------|
| 1 | `map_inline` | `map_inline.rs` | 否（pure bytecode） | 无 |
| 2 | `const_prop` | `const_prop.rs` | 否（pure bytecode） | 无 |
| 3 | `dce` | `dce.rs` | 否（pure bytecode） | 无 |
| 4 | `skb_load_bytes_spec` | `skb_load_bytes.rs` | 否（pure bytecode） | 无 |
| 5 | `bounds_check_merge` | `bounds_check_merge.rs` | 否（pure bytecode） | 无 |
| 6 | `wide_mem` | `wide_mem.rs` | 否（pure bytecode）| 无（注释明确："No kinsn support needed -- pure BPF replacement"） |
| 7 | `bulk_memory` | `bulk_memory.rs` | **是** | `bpf_memcpy_bulk`, `bpf_memset_bulk` |
| 8 | `rotate` | `rotate.rs` | **是** | `bpf_rotate64` |
| 9 | `cond_select` | `cond_select.rs` | **是** | `bpf_select64` |
| 10 | `ccmp` | `ccmp.rs` | **是** | `bpf_ccmp64` (ARM64 only) |
| 11 | `extract` | `extract.rs` | **是** | `bpf_extract64` |
| 12 | `endian_fusion` | `endian.rs` | **是** | `bpf_endian_load16/32/64` |
| 13 | `branch_flip` | `branch_flip.rs` | 否（pure bytecode，PGO-guided 指令重排） | 无 |
| 14 | `prefetch` | `prefetch.rs` | **是** | `bpf_prefetch` |

**kinsn pass 定义**：运行时会发出 kfunc `CALL` 指令（BPF_CALL kfunc），需要 BTF module fd_array 才能通过 ReJIT verifier。

### 1.2 v3 §10 设计文档默认 12-pass policy

来源：`docs/tmp/bpfopt_design_v3.md` 第 33 行：

```
wide_mem, rotate, cond_select, extract, endian_fusion, map_inline,
const_prop, dce, bounds_check_merge, skb_load_bytes_spec, bulk_memory,
prefetch
```

### 1.3 daemon 实际启用 pass 列表

来源：`daemon/src/commands.rs:33-46`（`DEFAULT_DAEMON_PASS_LIST`）：

```rust
const DEFAULT_DAEMON_PASS_LIST: &[&str] = &[
    "wide_mem",
    "rotate",
    "cond_select",
    "extract",
    "endian_fusion",
    "map_inline",
    "const_prop",
    "dce",
    "bounds_check_merge",
    "skb_load_bytes_spec",
    "bulk_memory",
    "prefetch",
];
```

**daemon/commands.rs:1234-1253 `effective_pass_list()`**：严格拒绝任何不等于默认列表的 `enabled_passes`。没有覆盖机制，没有 env var 豁免。

### 1.4 runner 端的 pass list 决策逻辑

1. `runner/libs/rejit.py:378` `benchmark_rejit_enabled_passes()` — 如果设置了 `BPFREJIT_BENCH_PASSES` env var 则从 env 取，否则从 `benchmark_config.yaml` 读取
2. `corpus/config/benchmark_config.yaml` — 实际的默认 pass 列表（与 daemon 默认完全一致，共 12 个，不含 ccmp、branch_flip）
3. `runner/libs/case_common.py:181-186` `_effective_enabled_passes()` — 最终通过 `benchmark_rejit_enabled_passes()` 送入 daemon socket

### 1.5 已实现但未启用的 kinsn pass

#### `ccmp`（ARM64 conditional compare）

- **实现**：`bpfopt/crates/bpfopt/src/passes/ccmp.rs`，完整实现，有 8 个单元测试
- **添加时间**：commit `b80a1c19`（2026-04-30）
- **bpfopt CLI**：支持（`--pass ccmp`）
- **daemon 默认列表**：**未加入**
- **bpfopt PASS_REGISTRY**：已注册（`PASS_REGISTRY` 第 10 项）
- **daemon 代码存根**：`pass_needs_target()` line 1489 和 `missing_target_kinsns()` line 1505 都有 "ccmp" 的 match arm，但由于 `effective_pass_list()` 阻止 ccmp 进入 pass_list，这些 arm **永远不会被执行**（见下方 dead code 分析）
- **限制**：仅 ARM64 有效（x86 无 CCMP 指令等价物）

#### `branch_flip`（PGO-guided 分支翻转）

- **实现**：`bpfopt/crates/bpfopt/src/passes/branch_flip.rs`，完整实现，要求真实的 `--per-site` PMU profile
- **类型**：pure bytecode pass（不依赖 kinsn/kfunc）
- **daemon 默认列表**：**未加入**（CLAUDE.md 明确："remains outside the daemon's default 12-pass policy until Paper B benchmark results decide policy"）
- **runner 支持**：`runner/libs/rejit.py:818` 有 `branch_flip` profile 准备逻辑，但受 daemon `effective_pass_list()` 约束无法触达

---

## Part 2：Dead Code 审计

### 2.1 cargo build 警告

执行结果：
```
cd bpfopt && RUSTFLAGS="-D warnings" cargo build  →  Finished (0 warnings)
cd daemon && RUSTFLAGS="-D warnings" cargo build  →  Finished (0 warnings)
```

Rust 编译器未报告任何 dead_code warning。但 Rust 只检测 item 级别的可达性；**逻辑死分支（code paths that can never execute at runtime）不会触发 dead_code lint**。

### 2.2 逻辑死代码（Logical Dead Code）

#### D1：`wants_branch_flip` 分支永远为 false

**位置**：`daemon/src/commands.rs:1000-1013`

```rust
let wants_branch_flip = pass_list
    .iter()
    .any(|pass| canonical_pass(pass) == "branch_flip");
// ...
let profile_arg = if wants_branch_flip {
    let profile_path = profile_path
        .ok_or_else(|| anyhow!("branch_flip requested but no profile is loaded"))?;
    Some(profile_path)
} else if wants_prefetch { ... }
```

**原因**：`effective_pass_list()`（line 1234）要求 pass_list 精确等于 `DEFAULT_DAEMON_PASS_LIST`，而 DEFAULT list 不含 `branch_flip`。因此 `wants_branch_flip` 永远是 `false`，整个 `if wants_branch_flip { ... }` 分支永远不会执行。

**严重性**：中等。这是 Paper B 功能搭架子（daemon 预留了 branch_flip 支持但没真正开放），但在 fail-fast 规范下，不执行的代码应当被认为是 dead code。

**建议**：在 branch_flip 被正式纳入默认 pass list 前，删除 daemon 中的 `wants_branch_flip` 分支和相关 profile_arg 逻辑。

#### D2：`pass_needs_target` 和 `missing_target_kinsns` 中的 "ccmp" match arm

**位置**：
- `daemon/src/commands.rs:1489`（`needs_target()` 函数）
- `daemon/src/commands.rs:1505`（`missing_target_kinsns()` 函数）

```rust
// needs_target():
| "ccmp"   // ← 永远不会匹配：ccmp 不在 DEFAULT_DAEMON_PASS_LIST

// missing_target_kinsns():
"ccmp" => push_missing_target(&mut missing, &target, &["bpf_ccmp64"]),  // ← 同上
```

**原因**：同上 —— `effective_pass_list()` 保证了 pass_list 只会是 12 个默认 pass（不含 ccmp）。

**严重性**：低（仅死分支，不影响正确性）。

**建议**：等 ccmp 加入默认 list 后自然变活；或在正式加入前删除这两行，改为 `bail!`。

#### D3：`loop body` 中 `pass == "branch_flip"` 检查

**位置**：`daemon/src/commands.rs:1063`

```rust
let profile_for_pass = (pass == "branch_flip" || pass == "prefetch")
    .then_some(profile_arg)
    .flatten();
```

**原因**：`pass` 来自 `pass_list` 迭代，而 pass_list 不含 `branch_flip`，所以 `pass == "branch_flip"` 永远是 `false`。

**建议**：等 branch_flip 正式进入默认 list 前，此条件可简化为 `pass == "prefetch"`。

### 2.3 过宽可见性（Overly Wide Visibility）

#### D4：`BpfProgram::has_transforms()` 公开方法但无外部调用者

**位置**：`bpfopt/crates/bpfopt/src/pass.rs:384`

```rust
pub fn has_transforms(&self) -> bool {
    self.transform_log.iter().any(|e| e.sites_applied > 0)
}
```

**原因**：`grep -rn "has_transforms"` 在整个 bpfopt 代码库中只找到定义本身，没有任何调用处。`transform_log` 字段会被多个 pass 写入（`log_transform()`），但没有代码读取 `has_transforms()`。

**严重性**：中等。`transform_log` 字段本身记录了变换信息，但 `has_transforms()` 查询函数没有被使用，违反 "No Dead Code" 规则。

**建议**：删除 `has_transforms()` 公开方法。如果 `transform_log` 本身也没有外部读取路径，整个字段也可以删除（但需确认报告生成逻辑）。

#### D5：`scan_wide_mem` 是 `pub fn` 但无模块外调用者

**位置**：`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:57`

```rust
pub fn scan_wide_mem(insns: &[BpfInsn]) -> Vec<RewriteSite> {
```

**原因**：`scan_wide_mem` 只被同文件中的 `WideMemPass::run()` 调用（line 422），以及 `wide_mem_tests.rs` 中的测试。它未被 `passes/mod.rs` 的 `pub use` 导出，实际上只需要 `pub(crate)` 或更窄的可见性。

**严重性**：低（可见性过宽但无实际外部 caller）。

**建议**：降级为 `pub(crate)`。

### 2.4 `_owned_fds` 字段说明（合法的 dead-code-looking 模式）

**位置**：`daemon/src/commands.rs:1559`

```rust
struct RejitFdArray {
    fds: Vec<i32>,
    btf_count: usize,
    _owned_fds: Vec<OwnedFd>,  // ← 前缀 _ 是有意的
}
```

**结论**：这是合法的 drop guard 模式 —— `_owned_fds` 持有 `OwnedFd` 以在 BPF_PROG_REJIT syscall 期间保持 fd 有效。前缀 `_` 是标准 Rust 约定来抑制 "field never read" 警告。**不是 dead code，不需要删除**。

---

## Part 3：整合总结 + Round 16 建议

### 3.1 kinsn pass 完整矩阵

| pass | 类型 | 在默认列表 | 加入时间 | 备注 |
|------|------|-----------|---------|------|
| `wide_mem` | pure bytecode | ✅ | 早期 | 宽内存合并 |
| `rotate` | **kinsn** | ✅ | 早期 | bpf_rotate64，ROL/ROR |
| `cond_select` | **kinsn** | ✅ | 早期 | bpf_select64，CMOV/CSEL |
| `extract` | **kinsn** | ✅ | 早期 | bpf_extract64，BEXTR |
| `endian_fusion` | **kinsn** | ✅ | 早期 | bpf_endian_load32/16/64，MOVBE |
| `map_inline` | pure bytecode | ✅ | 早期 | 需要 map 值 snapshot |
| `const_prop` | pure bytecode | ✅ | 早期 | 需要 verifier states |
| `dce` | pure bytecode | ✅ | 早期 | |
| `bounds_check_merge` | pure bytecode | ✅ | 早期 | |
| `skb_load_bytes_spec` | pure bytecode | ✅ | 早期 | |
| `bulk_memory` | **kinsn** | ✅ | 早期 | bpf_memcpy_bulk + bpf_memset_bulk |
| `prefetch` | **kinsn** | ✅ | 2026-04-30（9b9bd28e） | bpf_prefetch；最新加入 |
| `ccmp` | **kinsn** | ❌ **未启用** | 2026-04-30（b80a1c19） | ARM64 only，bpf_ccmp64 |
| `branch_flip` | pure bytecode（PGO） | ❌ **未启用** | Paper B scaffolding | 需要 per-site PMU profile |

**默认列表中 kinsn passes 数量：7 个**（rotate, cond_select, extract, endian_fusion, bulk_memory, prefetch，以及 ccmp 虽有 daemon 代码存根但不在默认列表）

实际数：`rotate + cond_select + extract + endian_fusion + bulk_memory + prefetch = 6 个 kinsn pass 在默认列表中`

### 3.2 dead code 清单

| ID | 位置 | 描述 | 严重性 | 建议 |
|----|------|------|--------|------|
| D1 | `daemon/src/commands.rs:1000-1013` | `wants_branch_flip` 分支永远 false | 中 | 删除整块，等 branch_flip 进入默认 list 再加回 |
| D2 | `daemon/src/commands.rs:1489,1505` | `needs_target/missing_target_kinsns` 中的 "ccmp" arm | 低 | 加入 ccmp 到默认 list 时自然激活；现在是死 match arm |
| D3 | `daemon/src/commands.rs:1063` | 循环体中 `pass == "branch_flip"` 永远 false | 低 | 等 branch_flip 进列表；现在可简化条件 |
| D4 | `bpfopt/crates/bpfopt/src/pass.rs:384` | `BpfProgram::has_transforms()` 无调用者 | 中 | 删除该方法 |
| D5 | `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:57` | `scan_wide_mem` 是 `pub` 但无外部调用 | 低 | 改为 `pub(crate)` 或 private |

### 3.3 Round 16 kinsn-only pass list 建议

目标：只跑 kinsn 路径，隔离 BTF module fd_array 和 per-pass ReJIT 的正确性测试。

**推荐 kinsn-only pass list（按 DEFAULT 顺序取子集）**：

```yaml
policy:
  default:
    passes:
      - rotate          # bpf_rotate64
      - cond_select     # bpf_select64
      - extract         # bpf_extract64
      - endian_fusion   # bpf_endian_load16/32/64
      - bulk_memory     # bpf_memcpy_bulk + bpf_memset_bulk
      - prefetch        # bpf_prefetch（最新，值得专项测试）
```

**不包含**：
- `wide_mem`（pure bytecode，不走 kinsn 路径）
- `map_inline`（需要 map 值 snapshot，不是 kinsn）
- `const_prop`（需要 verifier states，pure bytecode）
- `dce`（pure bytecode）
- `bounds_check_merge`（pure bytecode）
- `skb_load_bytes_spec`（pure bytecode）
- `ccmp`（kinsn 但未在 daemon 默认列表；daemon 拒绝非默认 list）

**注意**：当前 `effective_pass_list()` 拒绝任何非默认列表，所以这个 kinsn-only list **无法直接传给 daemon**。
选项：
1. 临时修改 `DEFAULT_DAEMON_PASS_LIST` → 改为 kinsn-only 子集
2. 或者放宽 `effective_pass_list()` 允许默认 list 的子集（非空且每个元素在默认 list 内）

**round 16 若只需验证 kinsn 路径**，推荐方案 1（临时替换 DEFAULT_DAEMON_PASS_LIST），运行完恢复。

---

## 附录：关键文件引用

- `corpus/config/benchmark_config.yaml` — runner 端默认 pass 列表
- `daemon/src/commands.rs:33-46` — `DEFAULT_DAEMON_PASS_LIST` 常量
- `daemon/src/commands.rs:1234-1253` — `effective_pass_list()` 拒绝非默认列表
- `bpfopt/crates/bpfopt/src/passes/mod.rs:59-135` — `PASS_REGISTRY`（完整 14-pass 注册表）
- `docs/tmp/bpfopt_design_v3.md:33` — v3 设计文档的 12-pass 基准列表
