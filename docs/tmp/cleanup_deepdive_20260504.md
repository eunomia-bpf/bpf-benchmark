# Daemon/bpfopt 深度清理调研 (2026-05-04)

## TL;DR

daemon `commands.rs`（2574 行）和 `server.rs`（810 行）合计约 ~3400 行生产代码，可删约
**~120–160 行**（纯死代码/重复代码/调试残留），加上低风险重构约 **~60–80 行**，
总计 **~180–240 行**。
最高优先级：① `try_reapply_one` 重复函数（删 20 行）、② `[trace]` syscall 调试打印（删 15 行）、
③ `RejitSummary`/`bpfrejit_summary.json` 写而不读（删 ~30 行）、
④ `canonical_pass` kebab 别名瘦身（删 ~8–10 行）。
`frozen` bug 是功能问题不是死代码，需要专项修复。

---

## 高优先级（违反 v3 / CLAUDE.md，必删）

### H1. `try_reapply_one` 完全重复 `try_apply_one`

**位置**：`daemon/src/commands.rs:624–643`

**当前做什么**：
```rust
pub(crate) fn try_reapply_one(prog_id, config, enabled_passes, invalidation_tracker)
  -> Result<OptimizeOneResult>
{
    let mut kernel = LiveKernelOps;
    try_apply_one_with_map_access(
        ApplyOneRequest { prog_id, config, enabled_passes, invalidation_tracker },
        &mut kernel,
        bpf::bpf_map_get_fd_by_id,
        live_bpf_map_lookup,
        live_bpf_map_keys,
    )
}
```

`try_apply_one`（lines 603–622）体完全相同，一字不差。

**调用方**：
- `try_apply_one`：`commands.rs:717`（`try_apply_programs` 内部 lambda）
- `try_reapply_one`：`server.rs:189`（invalidation 触发的 reoptimization）

**为什么必删**：CLAUDE.md "No Dead Code — every fn must have a real caller"。两个函数完全等价，`try_reapply_one` 是多余的。

**修改方案**：
1. 删除 `commands.rs:624–643` 整个 `try_reapply_one` 函数。
2. `server.rs:189`：`commands::try_reapply_one(prog_id, &config, &enabled_passes, Some(&tracker_for_apply))`
   改为 `commands::try_apply_one(prog_id, &config, &enabled_passes, Some(&tracker_for_apply))`。

**可删行数**：20 行（函数体）+ `server.rs` 0 行（只改函数名，不增删行数）= **20 行**

**风险**：零风险。两函数体完全相同，已经过 `diff` 确认。

---

### H2. `[trace]` 调试打印 + `libc::syscall(SYS_gettid)`

**位置**：`daemon/src/commands.rs:914–928`

**当前做什么**：
```rust
let tid = unsafe { libc::syscall(libc::SYS_gettid) };
let t0 = std::time::Instant::now();
eprintln!("[trace] tid={tid} REJIT_ENTER prog={prog_id} pass={pass}");
// ... rejit_result ...
eprintln!(
    "[trace] tid={tid} REJIT_EXIT prog={prog_id} pass={pass} ok={} elapsed_us={}",
    rejit_result.is_ok(),
    t0.elapsed().as_micros()
);
```

每次 `BPF_PROG_REJIT` 都输出两行 `[trace]`，corpus run 生成数千行 `[trace]` 污染
`daemon.stderr.log`，极大干扰 log 分析。
`libc::syscall(SYS_gettid)` 是非 BPF syscall 直接调用，属于调试残留。

**为什么必删**：CLAUDE.md "No Dead Code（调试 trace 不属于正式功能）"。
如果需要 ReJIT 延迟信息，应通过结构化 `PassDetail.elapsed_ns` 字段，而非 `eprintln`。

**修改方案**：删除以下 5 行：
```
let tid = unsafe { libc::syscall(libc::SYS_gettid) };
let t0 = std::time::Instant::now();
eprintln!("[trace] tid={tid} REJIT_ENTER prog={prog_id} pass={pass}");
```
以及 `eprintln!("[trace] tid={tid} REJIT_EXIT ...")` 的整段（lines 924–928）。
`libc` 仍需保留（其他地方也有用，如 `signal()`）。

**可删行数**：**15 行**（5+4+空行+2）

**风险**：零风险。纯调试打印删除，不影响任何功能逻辑。

---

### H3. `RejitSummary` + `bpfrejit_summary.json` 写而不读

**位置**：
- struct 定义：`daemon/src/commands.rs:283–289`（7 行）
- `RejitReport.summary` 字段：`commands.rs:293`（1 行）
- 在 `rejit_program` 中构造 `RejitSummary`：`commands.rs:331–336`（6 行）
- `let rejit_summary_json = ...` 变量定义：`commands.rs:756`（1 行）
- `write_json_file(&rejit_summary_json, &rejit_summary)?;`：`commands.rs:987`（1 行）
- 测试中的 mock `RejitSummary`：`commands.rs:2471–2476`（6 行，在 `#[cfg(test)]`）

**完整搜索结果**（grep 确认）：
`bpfrejit_summary`/`RejitSummary` 在以下文件中出现：
- `daemon/src/commands.rs`（上述位置，写方）
- **零 reader**：runner Python、corpus、e2e、micro、scripts、Makefile、docs 全部无引用。
`bpfrejit_summary.json` 写入临时工作目录 `WorkDir`，工作目录在函数返回后立即被 Drop 删除。
即使文件被写出，也在同一调用栈上被清理。

**为什么必删**：CLAUDE.md "No Dead Code"。写文件是有代价的 IO（磁盘写 + fsync），
且文件本身随 `WorkDir::drop` 立即消失，实际没有任何消费方。

**修改方案**：
1. 删除 `struct RejitSummary { ... }` 定义（lines 283–289）。
2. 将 `RejitReport` 的 `summary` 字段改为直接存 `verifier_states`（已存）：
   `RejitReport` 只剩 `verifier_states: VerifierStatesJson`，删掉 `summary` 字段。
3. 删除 `rejit_program` 中构造 `RejitSummary` 和返回 `summary` 的代码（lines 331–336）。
4. 删除 `commands.rs:756` `rejit_summary_json` 变量定义。
5. 删除 `commands.rs:986–987` `if let Some(rejit_summary) = ...` 中的
   `write_json_file(&rejit_summary_json, &rejit_summary)?;` 一行。
   （`if` 块剩余的 `refresh_invalidation_tracking` 调用保留。）
6. `last_rejit_summary` 变量用于：
   - `commands.rs:951`：`last_rejit_summary = Some(rejit_report.summary);`
   - `commands.rs:978`：`let applied = last_rejit_summary.is_some();`
   将 `last_rejit_summary: Option<RejitSummary>` 替换为 `last_rejit: bool`（是否有成功 rejit）：
   - `commands.rs:851`：`let mut last_rejit = false;`
   - `commands.rs:951`：`last_rejit = true;`
   - `commands.rs:978`：`let applied = last_rejit;`
   - `commands.rs:986`：`if last_rejit {`
7. 测试 `commands.rs:2471–2476` 中 `RejitSummary { ... }` 构造改为直接返回 `RejitReport { verifier_states }`.
   （`insn_count_before/after` 在测试外不再需要）

**可删行数**：~30 行（结构体 7 + 字段 1 + 构造 6 + 变量 1 + 写 1 + 重构改写约 5 行）

**风险**：低。`insn_count_before`/`insn_count_after` 仅在 `RejitSummary` 中使用，
删后无 regression，因为 `RejitReport.verifier_states`（主要有用字段）保留不变。

---

### H4. `bpf_memcpy_bulk`/`bpf_memset_bulk` 别名

**位置**：`daemon/src/commands.rs:1315–1330`

**当前做什么**：
```rust
"bulk_memory" => {
    push_missing_target(&mut missing, &target, &["bpf_bulk_memcpy", "bpf_memcpy_bulk"]);
    push_missing_target(&mut missing, &target, &["bpf_bulk_memset", "bpf_memset_bulk"]);
}
```

`push_missing_target` 实现是：如果 `target.kinsns` 中有任意一个 name，就不报 missing。
`bpfget` 的 `KINSN_PROBE_TARGETS` 定义了 `json_name: "bpf_bulk_memcpy"`（无 `bpf_memcpy_bulk`），
所以 `bpfget` 生成的 `target.json` 只会有 `bpf_bulk_memcpy`/`bpf_bulk_memset`。
`bpf_memcpy_bulk`/`bpf_memset_bulk` 是反转别名，在 `bpfget` 中不会出现。

**同时**，`bpfopt/src/main.rs:62–69` 的 `KINSN_ALIASES` 中：
```
("bpf_memcpy_bulk", "bpf_memcpy_bulk"),
("bpf_bulk_memcpy", "bpf_memcpy_bulk"),
```
这说明 `bpfopt` 的规范名是 `bpf_memcpy_bulk`，但 `bpfget` probe 结果的 JSON key 是 `bpf_bulk_memcpy`。
daemon `missing_target_kinsns` 检查的是 target.json 的 key，所以 `bpf_memcpy_bulk` 别名
检查从未成功触发。

**为什么必删**：CLAUDE.md "No Dead Code（未使用的别名名称）"。

**修改方案**：
```diff
-"bulk_memory" => {
-    push_missing_target(&mut missing, &target, &["bpf_bulk_memcpy", "bpf_memcpy_bulk"]);
-    push_missing_target(&mut missing, &target, &["bpf_bulk_memset", "bpf_memset_bulk"]);
-}
+"bulk_memory" => {
+    push_missing_target(&mut missing, &target, &["bpf_bulk_memcpy"]);
+    push_missing_target(&mut missing, &target, &["bpf_bulk_memset"]);
+}
```

**可删行数**：**2 行**（两个别名字符串字面量）

**风险**：低。`bpf_memcpy_bulk`/`bpf_memset_bulk` 别名从不出现在实际 `target.json` 中，
删后行为不变。

---

## 中优先级（dead code / 设计意图不清晰）

### M1. `canonical_pass` kebab-case 别名过多

**位置**：`daemon/src/commands.rs:1518–1537`

**当前实现**（14 个 match arm）：
```rust
fn canonical_pass(pass: &str) -> String {
    match pass.trim() {
        "wide-mem"   | "wide_mem"   => "wide_mem",
        "rotate"                    => "rotate",
        "const-prop" | "const_prop" => "const_prop",
        "cond-select"| "cond_select"=> "cond_select",
        "extract"                   => "extract",
        "endian" | "endian-fusion" | "endian_fusion" => "endian_fusion",
        "branch-flip"| "branch_flip"=> "branch_flip",
        "prefetch"                  => "prefetch",
        "dce"                       => "dce",
        "map-inline" | "map_inline" => "map_inline",
        "bulk-memory"| "bulk_memory"=> "bulk_memory",
        "bounds-check-merge" | "bounds_check_merge" => "bounds_check_merge",
        "skb-load-bytes" | "skb_load_bytes" |
        "skb-load-bytes-spec" | "skb_load_bytes_spec" => "skb_load_bytes_spec",
        other => return other.replace('-', "_"),
    }
    .to_string()
}
```

**runner 实际发送的 pass 名**：来自 `corpus/config/benchmark_config.yaml` 和 `runner/libs/rejit.py`，
全部是 `snake_case`：`wide_mem`, `rotate`, `const_prop`, `cond_select`, `extract`,
`endian_fusion`, `map_inline`, `const_prop`, `dce`, `bounds_check_merge`,
`skb_load_bytes_spec`, `bulk_memory`, `prefetch`。
`_PASS_TO_SITE_FIELD` dict 和 `rejit.py` 中的所有 pass 名均为 `snake_case`，无 kebab-case。

**注意**：`canonical_pass` 在 daemon 内部使用（接收 socket 传入的 pass 名），
不直接接收 bpfopt CLI 的 pass 参数（bpfopt 有自己的 `PASS_ALIASES` 表）。

**为什么应删/减**：CLAUDE.md "No Dead Code"。kebab-case 别名没有任何实际调用方。
`other => return other.replace('-', "_")` 的 fallthrough 是 fallback 行为，
违反 "No fallback" 原则，未知 pass 名应直接 fail-fast。

**修改方案（保守版）**：删除所有 kebab-case arm，只保留 snake_case；
`other` fallthrough 改为 fail-fast（return `Err` 而不是 replace）。

**但** `canonical_pass` 现在返回 `String`，如果改成 `Result<String>` 会影响调用方（4 处）。
较为安全的方案是：仅删 kebab 别名，`other` 行保留但加注释标明是未知 pass 名原样传递
（让 bpfopt 报错）。或直接 `bail!`。

推荐：把 `canonical_pass` 改名为 `normalize_pass` 并返回 `Result`，同时删 kebab alias。

```diff
-fn canonical_pass(pass: &str) -> String {
-    match pass.trim() {
-        "wide-mem"   | "wide_mem"   => "wide_mem",
-        "const-prop" | "const_prop" => "const_prop",
-        "cond-select"| "cond_select"=> "cond_select",
-        "endian" | "endian-fusion" | "endian_fusion" => "endian_fusion",
-        "branch-flip"| "branch_flip"=> "branch_flip",
-        "map-inline" | "map_inline" => "map_inline",
-        "bulk-memory"| "bulk_memory"=> "bulk_memory",
-        "bounds-check-merge" | "bounds_check_merge" => "bounds_check_merge",
-        "skb-load-bytes" | "skb_load_bytes" |
-        "skb-load-bytes-spec" | "skb_load_bytes_spec" => "skb_load_bytes_spec",
-        "rotate" | "extract" | "prefetch" | "dce" | "ccmp" => pass.trim(),
-        other => return other.replace('-', "_"),
-    }
-    .to_string()
-}
+fn canonical_pass(pass: &str) -> Result<String> {
+    match pass.trim() {
+        "wide_mem" | "const_prop" | "cond_select" | "endian_fusion" | "branch_flip" |
+        "map_inline" | "bulk_memory" | "bounds_check_merge" | "skb_load_bytes_spec" |
+        "rotate" | "extract" | "prefetch" | "dce" | "ccmp" => Ok(pass.trim().to_string()),
+        other => bail!("unknown pass name: {other:?}"),
+    }
+}
```

4 个调用方需要加 `?`：`commands.rs:744`, `473`, `785`, `1284`, `1300`。

**可删行数**：~12 行（kebab-case arm 约 8 行 + `other => return other.replace('-', "_")`
改为 bail 少 1 行）。调用方修改 4 处各 ~1 行改写，净减少约 **8–10 行**。

**风险**：中。需要确保 runner 从不发 kebab-case pass 名（已确认：`rejit.py` 和 `benchmark_config.yaml`
全部 snake_case）。`other => bail!` 会让未来的错误配置立即报错，更安全。

---

### M2. `ReoptimizationState::remember_result` 意图不清晰

**位置**：`daemon/src/server.rs:70–91`

**当前做什么**：
```rust
fn remember_result(&mut self, prog_id, requested_passes, result) {
    if result.status != "ok"
        || result.error_message.is_some()
        || result.inlined_map_entries.is_empty()  // ← 隐含限制
    {
        self.enabled_passes_by_prog.remove(&prog_id);
        return;
    }
    self.enabled_passes_by_prog.insert(prog_id, requested_passes.to_vec());
}
```

`inlined_map_entries.is_empty()` 条件隐含地限制了：只有 `map_inline` 真正 inline 了至少一个
entry 的程序才会被跟踪用于 invalidation reoptimization。

**是否 bug**：这是有意的设计（invalidation tracking 只对真正 inline 了 map value 的程序有意义），
但意图在代码中不透明，`result.status != "ok"` 检查与 `inlined_map_entries.is_empty()` 检查
混在同一个 if 分支，读者很难区分。

**已有测试**：`server.rs:586` `reoptimization_state_persists_pass_list_for_map_inline_results`
已经测试了这两条路径，测试注释说明了预期行为。

**为什么应改**：CLAUDE.md "every fn must have a real caller"，但这里更多是文档清晰度问题。
`inlined_map_entries.is_empty()` 作为"不需要 invalidation tracking 的判断"应该与
status/error_message 的"结果失败"判断分离，否则误导后续开发者以为这里是 bug。

**修改方案**：
```diff
 fn remember_result(&mut self, prog_id, requested_passes, result) {
-    if result.status != "ok"
-        || result.error_message.is_some()
-        || result.inlined_map_entries.is_empty()
-    {
+    // Only track programs where map_inline successfully inlined at least one entry.
+    // These are the only programs that need invalidation re-optimization when the
+    // underlying map value changes.
+    if result.status != "ok" || result.error_message.is_some() {
+        self.enabled_passes_by_prog.remove(&prog_id);
+        return;
+    }
+    if result.inlined_map_entries.is_empty() {
         self.enabled_passes_by_prog.remove(&prog_id);
         return;
     }
```

**可删行数**：净 0（只是重组，加注释约 +4 行，拆分 if 约 +2 行）

**风险**：零风险，语义完全不变，只加注释和拆分 if。

---

### M3. `init_cli_dir` 永远 None，`Some` 路径无法到达

**位置**：`daemon/src/commands.rs:98–102`（生产代码）

**当前做什么**：
```rust
pub(crate) fn init_cli_dir() -> Result<()> {
    CLI_DIR
        .set(None)   // always None
        .map_err(|_| anyhow!("CLI dir already initialised"))
}
```

`Cli {}` struct 在 `main.rs:20–21` 是空结构体，无 `--cli-dir` 参数。
`CLI_DIR` 只能是 `None`，`CliConfig::from_global()` 总是返回 `CliConfig { cli_dir: None }`，
`CliConfig::command()` 总是用 PATH lookup。`Some(dir)` 路径在生产代码中从不可达。

**在测试中**：`tests` 中用 `CliConfig::from_global()` 后 `CLI_DIR` 未 set，
`from_global()` 对 `CLI_DIR.get()` 是 `None.and_then(...)` → `None`，效果等同。
测试通过写 fake bpfopt 到临时目录再 `set_cli_dir(dir)` 的方式来绕过（见 `commands.rs:2482`），
但这个 `set_cli_dir` 也只在测试 mock 中。

**为什么可改**：CLAUDE.md "No Dead Code"（`Some` branch 是无法到达的代码路径）。

**修改方案**：这里不建议强制删 `CliConfig` 结构，因为测试需要 fake CLI dir。
更合理的方案是删除 `init_cli_dir`，在 `cmd_serve` 里直接：
```rust
let config = CliConfig { cli_dir: None };
```
同时 `CLI_DIR` static 和相关 getter 可删除，测试中改用 `CliConfig { cli_dir: Some(dir) }` 直接构造。

**可删行数**：`init_cli_dir` 6 行 + `CLI_DIR` static 1 行 + `from_global` 5 行 = **~12 行**，
调用方 `server.rs:161` 删一行，净减少 **~10 行**。

**风险**：低。需要更新测试中的 `CliConfig` 构造方式（测试在 `#[cfg(test)]` 中有自己的 helper）。

---

### M4. `KernelOps` trait 在生产 binary 中的可见性

**位置**：`daemon/src/commands.rs:247–281`

**当前做什么**：
```rust
trait KernelOps { ... }
struct LiveKernelOps;
impl KernelOps for LiveKernelOps { ... }
```

生产代码路径全部通过 `LiveKernelOps`，trait 的唯一价值是支持测试用的 `MockKernelOps`。
`MockKernelOps` 定义在 `commands.rs:2364`（`#[cfg(test)]` 块内）。

**为什么可改**：CLAUDE.md "No Dead Code—不保留 compatibility APIs"。
trait dispatch 在生产 binary 中是零价值的运行时间接层，`dyn KernelOps` 参数在测试之外
只有 `LiveKernelOps` 一种实现。

**修改方案**（保守）：
将 `KernelOps` trait 移到 `#[cfg(test)]` 块中；生产路径的 `try_apply_one_with_map_access`
直接接受 `LiveKernelOps`（不用 `&mut dyn KernelOps`），或将 rejit 逻辑直接内联到函数体
而非通过 trait dispatch。测试保留 `MockKernelOps`，但只在 `#[cfg(test)]` 中可用，
函数签名改为泛型 `K: KernelOps` 而非 `&mut dyn KernelOps`。

此项改动较大，需要重构测试 helper。

**可删行数**：~0（重构，不减少总行数，但消除生产代码中的 trait 间接层）

**风险**：中。需要重构 `try_apply_one_with_map_access` 签名，影响 10+ 个测试。

---

## 低优先级（小重构，可选）

### L1. `needs_target` 与 `pass_needs_target` 重复逻辑

**位置**：
- `pass_needs_target(pass: &str)` at `commands.rs:1046–1057`（12 行）
- `needs_target(passes: &[String])` at `commands.rs:1281–1294`（14 行）

`needs_target` 内部调用 `canonical_pass(pass).as_str()` + `matches!` 宏，
与 `pass_needs_target` 重复了相同的 pass 集合。两者是 "一个 pass" vs "pass 列表" 的关系，
不是死代码，但维护同一份 pass 名列表在两处。

**修改方案**：
```diff
-fn pass_needs_target(pass: &str) -> bool {
-    matches!(pass, "rotate" | "cond_select" | ...)
-}
+fn needs_target(passes: &[String]) -> bool {
+    passes.iter().any(|p| pass_needs_target(canonical_pass(p).as_str()))
+}
```
或删除 `pass_needs_target`，在调用处直接用 `needs_target` 的逻辑展开。

**可删行数**：~12 行

**风险**：低。只是内联，逻辑不变。

---

### L2. `bpfopt/src/main.rs` 的 PASS_ALIASES 含多余 kebab 别名

**位置**：`bpfopt/crates/bpfopt/src/main.rs:24–51`

`PASS_ALIASES` 包含 30+ 个条目，其中 kebab-case 形式（如 `"wide-mem"`, `"const-prop"`,
`"map-inline"`, `"skb-load-bytes"` 等）是给 bpfopt CLI `--pass` 参数使用的。

与 daemon 不同，bpfopt CLI 的 `--pass` 参数由人类直接调用（如文档示例中的 `--pass wide-mem`），
所以 kebab-case 在这里有用户文档价值，**不建议删除**。

`canonical_pass_names_accept_v3_cli_names` 测试（`main.rs:1237`）也明确验证了这些别名。

**结论**：bpfopt 的 PASS_ALIASES 保留，daemon 的 `canonical_pass` 才需要瘦身。

---

### L3. `bpfopt/src/main.rs` 的 KINSN_ALIASES 多余反转别名

**位置**：`bpfopt/crates/bpfopt/src/main.rs:53–78`

```rust
const KINSN_ALIASES: &[(&str, &str)] = &[
    ("bpf_memcpy_bulk", "bpf_memcpy_bulk"),  // bpfopt 规范名
    ("bpf_bulk_memcpy", "bpf_memcpy_bulk"),  // bpfget target.json 用的名字
    ...
```

`bpfget` 生成的 `target.json` 中 key 是 `bpf_bulk_memcpy`（非 `bpf_memcpy_bulk`），
而 bpfopt 内部规范名是 `bpf_memcpy_bulk`。`KINSN_ALIASES` 的别名做了这个映射。
这是有意义的（bpfget probe 结果 → bpfopt 内部名），不是死代码。

**结论**：保留，不删。

---

### L4. `daemon/src/invalidation.rs:204` 和 `server.rs:502` 的 `unwrap_or_default`

**位置**：
- `daemon/src/invalidation.rs:204`：`state.values.get(&map_fd).cloned().unwrap_or_default()`
- `daemon/src/server.rs:502`：`values.get(&map_fd).cloned().unwrap_or_default()`

两处均在 `#[cfg(test)]` 的 `MockMapValueReader` 中，不在生产代码路径。
CLAUDE.md 要求不在生产路径上 silence error，测试 mock 中 `unwrap_or_default` 是合理的（
map_fd 不存在时返回空 HashMap 表示无值，语义清晰）。

**结论**：保留，不是生产代码问题。

---

## 深度分析 Q1：`map_inline` frozen vs 普通路径

### 两条路径的语义

**frozen 路径**（`build_direct_map_value_load_rewrites`）：
- 针对 `PSEUDO_MAP_VALUE`/`PSEUDO_MAP_IDX_VALUE` 类型的 LD_IMM64 指令（BPF 程序直接访问
  map 的 data section，不走 lookup helper）。
- 调用 `resolve_frozen_map_value()`（`map_inline.rs:1357`），只有 `info.frozen == true` 时
  才读取 map 的第 0 个 key 的 value 并常量化加载指令。
- 这类访问是静态地址，只有不可变（frozen）的 map 才能安全常量化（否则 map value 可能在
  运行时变化，inline 后会读到过时值）。

**普通路径**（`map lookup site inline`）：
- 针对 `bpf_map_lookup_elem` / `bpf_map_lookup_percpu_elem` 调用（lookup helper）。
- 使用 verifier state 提供的常量 key，从 `map-values.json` 读取对应 value，将
  lookup call + null check + load 序列替换为常量加载指令序列。
- 对可变 map，使用 invalidation tracking（map value 变化时 reoptimize）。

**为什么需要两条路径**：语义完全不同：
- `PSEUDO_MAP_VALUE` 路径处理的是"BPF 程序直接引用 map data section"的静态地址编码，
  不经过 lookup helper，对应 frozen array map 的场景。
- 普通 lookup 路径处理的是动态 lookup，可以对可变 map 做 speculative inline（配合 invalidation）。
- 两者的 IR 模式、替换方式、以及 frozen 要求完全不同，**不能合并**。

### `frozen: false` 硬编码的实际影响

`daemon/src/commands.rs:1255`：`frozen: false`

**影响分析**：
- `frozen: false` 写入 `map-values.json`，bpfopt 的 `default_frozen()` 返回 `true`（JSON 缺失字段时），
  但 daemon 显式写了 `false`，所以 bpfopt 读取后 `metadata.frozen == false`。
- `resolve_frozen_map_value`（`map_inline.rs:1377`）：`if !info.frozen { return Ok(None); }`，
  所以 `PSEUDO_MAP_VALUE` 路径完全跳过，无论实际 map 是否 frozen。
- 普通 lookup 路径不受影响（它走 verifier state + snapshot values，不检查 `info.frozen`，
  只检查 `info.has_removable_lookup_pattern()` 和 `info.has_speculative_invalidation()`）。
- **实际 loss**：对使用 frozen array map + `PSEUDO_MAP_VALUE` 访问模式的 BPF 程序，
  `map_inline` 少做了一类常量化优化。在 calico/cilium 等使用 frozen global data map 的程序上
  可能有影响，但由于这类程序的 EACCES/EBUSY 问题，目前无法量化。

### 能否修复 + 风险

**问题**：`bpf_map_info.map_flags` 不包含 frozen 状态。
kernel 的 `bpf_map_info`（`linux/bpf.h:6493`）只暴露 `map_flags`（创建时的标志，如
`BPF_F_RDONLY`），而 `map->frozen` 是一个独立的内核内部 bool，BPF_MAP_FREEZE syscall 设置，
但不反映在 `map_flags` 中。

**可行方案**：
1. **尝试 BPF_MAP_FREEZE**：如果 `BPF_MAP_FREEZE` 返回 `EBUSY`，说明已经 frozen。
   但这个 syscall 在某些情况下可能改变 map 状态（特别是竞争条件），不安全。
2. **删除 `frozen` 字段**，让 bpfopt 的 `PSEUDO_MAP_VALUE` 路径对所有 array map 都尝试，
   但这会导致非 frozen map 的 inline 是错误的（值可能已过时，且没有 invalidation tracking）。
3. **只对 array-like map 设置 `frozen: true`**：array map 的 data section inline 在 BPF 场景中
   通常安全（程序启动后不再修改），可以保守地将所有 array map 标记为 frozen。
   但这是启发式方法，违反精确语义。
4. **最保守的正确修复**：直接删除 `frozen` 字段，让 daemon 不传该字段（JSON absent），
   bpfopt 的 `default_frozen()` 返回 `true` 将作为默认值。
   这等于告诉 bpfopt"假设所有 map 都是 frozen"，但实际上可变 map 也会被尝试 frozen-path，
   这对于 `PSEUDO_MAP_VALUE` 路径可能产生错误的优化（inline 了可变 map 的值）。
   **不推荐**。

**推荐方案（最安全）**：在 `daemon/crates/bpfget/src/lib.rs` 的 `get_map_infos` 中，
通过 `map_flags & BPF_F_RDONLY_PROG`（`1U << 7`）推断：
`BPF_F_RDONLY_PROG` 意味着 BPF 程序只能读该 map，通常与 frozen map 一起使用（但不完全等价）。
更好的方案是在 `bpfget` 的 `MapInfo` 中加 `is_rdonly_prog: bool`，
让 bpfopt 将 `is_rdonly_prog == true` 作为可以 PSEUDO_MAP_VALUE inline 的依据。

**结论**：`frozen` bug 需要单独 PR 修复，涉及 bpfget 的 MapInfo、daemon 的 write_map_values_snapshot、
以及 bpfopt 的 `MapSnapshotJson` 字段语义改变。不是纯删除清理。

---

## 深度分析 Q2：`try_reapply_one` vs `try_apply_one`

见 H1 章节。精确 diff：两个函数一字不差，函数签名相同，函数体完全相同（20 行）。
`try_reapply_one` 是多余的，应删除后让 `server.rs:189` 调用 `try_apply_one`。

---

## 深度分析 Q3：`bpfrejit_summary.json` 写而不读

**grep 确认**（完整搜索）：

```
daemon/src/commands.rs:284   struct RejitSummary { ... }       ← writer
daemon/src/commands.rs:293   RejitReport.summary: RejitSummary ← writer
daemon/src/commands.rs:331   RejitSummary { ... } 构造         ← writer
daemon/src/commands.rs:756   let rejit_summary_json = ...       ← writer
daemon/src/commands.rs:987   write_json_file(...) 调用          ← writer
daemon/src/commands.rs:2471  测试 RejitSummary mock             ← #[cfg(test)]
```

runner Python (`runner/libs/`)、corpus、e2e、micro、scripts、Makefile、docs：**零 reader**。

**额外细节**：
- `bpfrejit_summary.json` 写入的 `WorkDir`（`/tmp/bpfrejit-daemon-optimize-PID-N/`），
  `WorkDir::drop` 在函数返回时立即 `fs::remove_dir_all`，文件的生命周期仅在函数调用期间，
  没有任何外部进程有机会读取它。
- `RejitSummary` 包含的字段（`status`, `prog_id`, `insn_count_before`, `insn_count_after`）
  在 `OptimizeOneResult` 中已经通过 `ProgramInfo.orig_insn_count/final_insn_count` 暴露给 runner，
  **语义上冗余**。

可删结构：
- `struct RejitSummary` 定义（7 行）
- `RejitReport.summary` 字段（1 行）+ struct 关联代码（3 行）
- `rejit_program` 中构造和返回 `RejitSummary`（6 行）
- `let rejit_summary_json = ...` 变量（1 行）
- `write_json_file` 调用（1 行）
- `last_rejit_summary` 改为 `last_rejit: bool`（净 0 行，重写 3 处但行数不变）
- 测试 mock 中 `RejitSummary { ... }` 改为直接返回（重写不减行）

**估算可删行数**：约 **25–30 行**。

---

## 深度分析 Q4：`canonical_pass` 的 kebab-case 别名

**当前实现**：`daemon/src/commands.rs:1518–1537`，共 20 行

**所有别名列表**（kebab vs snake 对照）：
| kebab-case（别名）   | snake_case（规范）    | runner 发送？|
|----------------------|-----------------------|:---:|
| `wide-mem`           | `wide_mem`            | 否 |
| `const-prop`         | `const_prop`          | 否 |
| `cond-select`        | `cond_select`         | 否 |
| `endian`             | `endian_fusion`       | 否 |
| `endian-fusion`      | `endian_fusion`       | 否 |
| `branch-flip`        | `branch_flip`         | 否 |
| `map-inline`         | `map_inline`          | 否 |
| `bulk-memory`        | `bulk_memory`         | 否 |
| `bounds-check-merge` | `bounds_check_merge`  | 否 |
| `skb-load-bytes`     | `skb_load_bytes_spec` | 否 |
| `skb-load-bytes-spec`| `skb_load_bytes_spec` | 否 |
| `skb_load_bytes`     | `skb_load_bytes_spec` | 否（但 snake_case 别名）|

**runner 验证**：`corpus/config/benchmark_config.yaml`（全部 snake_case），
`runner/libs/rejit.py` 的 `_PASS_TO_SITE_FIELD` dict key（全部 snake_case），
`rejit.py:benchmark_config_enabled_passes` 从 YAML 读取后原样传给 daemon socket。
**确认：runner 从不发 kebab-case pass 名**。

**`other => return other.replace('-', "_")` fallthrough**：
这是一个静默的 fallback，任何未知 pass 名都会被接受并原样（替换 `-`）传给 bpfopt。
如果 runner 发来了错误的 pass 名（如 typo `"wiide_mem"`），daemon 会静默接受，
bpfopt 才会报错（不在 PASS_ALIASES 中）。这是一个违反 fail-fast 原则的设计。

**为什么当初引入**：`git log` 显示 `canonical_pass` 是在 daemon 支持 bpfopt v3 CLI 格式时
引入的（`skb-load-bytes` 是 v3 bpfopt CLI 的 kebab-case 参数名），目的是让 daemon socket
接受与 bpfopt CLI 相同格式的 pass 名。但 runner 实际上从未使用 kebab-case。

**可删行数**：删除 11 个 kebab-case arm（~8 行），删除 `skb_load_bytes` snake-but-rename alias，
`other` 改 bail（-1 行 +1 行 net 0），净减少约 **8–10 行**。

---

## 合并/重构建议

### Q1 frozen 路径合并：不可合并

两条路径语义不同，不能合并。修复方向是正确传递 frozen/rdonly 状态。

### Q2 try_apply_one / try_reapply_one 合并

删除 `try_reapply_one`，server.rs 改调 `try_apply_one`。**可立即执行。**

### 建议重构：`last_rejit_summary` → `last_rejit: bool`

```rust
// Before:
let mut last_rejit_summary: Option<RejitSummary> = None;
// ...
last_rejit_summary = Some(rejit_report.summary);
// ...
let applied = last_rejit_summary.is_some();
if let Some(rejit_summary) = last_rejit_summary.as_ref() {
    write_json_file(&rejit_summary_json, &rejit_summary)?;  // DELETE THIS
    refresh_invalidation_tracking(...)?;
}

// After:
let mut last_rejit = false;
// ...
last_rejit = true;
// ...
let applied = last_rejit;
if last_rejit {
    refresh_invalidation_tracking(...)?;
}
```

---

## 总计

| 类别 | 可删行数 | 风险 |
|------|---------|------|
| H1 `try_reapply_one` 重复 | ~20 | 零 |
| H2 `[trace]` 调试打印 | ~15 | 零 |
| H3 `RejitSummary`/summary_json | ~30 | 低 |
| H4 `bpf_memcpy_bulk` 别名 | ~2 | 低 |
| M1 `canonical_pass` kebab 别名 | ~10 | 低-中 |
| M2 `remember_result` 注释重组 | ~0（+注释） | 零 |
| M3 `init_cli_dir` 简化 | ~10 | 低 |
| L1 `needs_target`/`pass_needs_target` 合并 | ~12 | 低 |
| **合计** | **~100–120 行** | — |

- **优先级 1（必删）**：H1 + H2 + H3 + H4 ≈ **~67 行**
- **优先级 2（dead code 清理）**：M1 + M3 ≈ **~20 行**
- **优先级 3（重构优化）**：L1 + M2 ≈ **~12 行**

---

## 执行顺序建议

| 顺序 | 内容 | 理由 |
|------|------|------|
| 1 | H1 删 `try_reapply_one` + H2 删 `[trace]` | 零风险，互相独立，可一个 PR |
| 2 | H3 删 `RejitSummary`/`bpfrejit_summary.json` + H4 删别名 | 低风险，可合并一个 PR |
| 3 | M1 `canonical_pass` kebab 删 + fail-fast 化 | 需要调用方修改，独立 PR |
| 4 | M3 `init_cli_dir` 简化 | 需要测试 helper 重构，独立 PR |
| 5 | L1 `needs_target` 合并 + M2 注释 | 可选，最低优先级 |
| 6（专项）| `frozen: false` bug 修复 | 需要 bpfget + daemon + bpfopt 协同，单独 PR |

**注意**：步骤 1–4 互相独立，可以并行派 codex 处理。步骤 6（frozen bug）需要单独设计，
建议在其他清理完成后再做，避免 PR 冲突。
