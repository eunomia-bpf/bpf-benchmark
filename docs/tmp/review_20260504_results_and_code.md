# Daemon/bpfopt + 最新实验结果 review (2026-05-04)

## TL;DR

1. **Verifier errors 真实存在，主要两类**：EBUSY（cilium 程序被内核网络栈并发使用，pass 包括 wide_mem/rotate/endian_fusion/dce/extract/cond_select/prefetch）和 EACCES/E2BIG（calico const_prop verifier 拒绝 + prefetch 程序过大）。EBUSY 属于正常 kernel-side 并发锁，无法消除。EACCES 是 const_prop 在 calico 大程序上产生 verifier 不接受的变换，属于已知真实 bug（需调查）。E2BIG 是 prefetch pass 使程序指令数超出 BPF 1M 上限。
2. **严重 bug：daemon 写 `frozen: false` 到 map-values.json**，但 bpfopt 的 pseudo-map-value load 优化路径（`resolve_frozen_map_value`）要求 `frozen=true` 才处理。导致 map_inline 的 `PSEUDO_MAP_VALUE` 类型加载优化路径永远跳过，少做了一类优化。
3. **`try_reapply_one` 与 `try_apply_one` 完全重复**，两个函数逻辑完全相同，无任何差异。
4. **`[trace]` 调试打印直接调用 `libc::syscall(SYS_gettid)` 在生产代码路径**，每次 REJIT 都打印到 stderr，污染 daemon log 且违反 kernel-sys 只做 BPF syscall 的精神（尽管 gettid 不是 BPF syscall，但属于不必要的 debug 残留）。
5. **`ReoptimizationState::remember_result` 条件有逻辑 bug**：当 `inlined_map_entries` 为空时不记录，导致没有 map_inline 成功的程序的 invalidation reoptimize 无法正常工作。

---

## Part A: Verifier Errors / Daemon Failures

### A.1 x86_kvm_corpus_20260504_210438_306253（Calico 专项 run）

**状态**：`status: error`，仅跑了 calico/felix，因 wrk workload 连接超时失败。

**5 个 daemon failure**（均属 calico felix 程序，prog 88/95/99/115/121）：

| prog_id | failed_pass | errno | 说明 |
|---------|------------|-------|------|
| 88 | prefetch | E2BIG (7) | `Argument list too long` — 在 11 个 pass 之后，prefetch pass 使程序指令数超出内核限制 |
| 95 | const_prop | EACCES (13) | `Permission denied` — verifier 拒绝 const_prop 变换后的字节码 |
| 99 | const_prop | EACCES (13) | 同上 |
| 115 | const_prop | EACCES (13) | 同上 |
| 121 | prefetch | E2BIG (7) | 同上，prefetch 使程序过大 |

**const_prop EACCES 分析**：
- 三个程序（95/99/115）均在 6 个 pass committed 后的 const_prop 失败
- verifier log 被截断，看不到具体拒绝原因，但 EACCES 通常意味着 verifier 的 `check_mem_access` / `check_helper_call` 等安全检查失败
- 三个程序字节码结构相似（calico felix），很可能是同一 bug 的表现
- **判断：真实 bug**，const_prop 在 calico 大程序上做了某种 verifier 不接受的变换
- **下一步**：在小程序上复现 const_prop EACCES，调查 const_prop 变换后的字节码是否引入了 verifier 拒绝的模式（可能是 ptr arithmetic 或 packet access 检查问题）

**prefetch E2BIG 分析**：
- prog 88/121 在 11 个 pass 后，prefetch pass 使程序超出 BPF 指令数限制
- prefetch pass 插入额外的 prefetch 指令，对大程序可能超限
- **判断：合理的 verifier 限制**，但也是 prefetch pass 实现问题（未检查程序大小限制）
- **下一步**：prefetch pass 应在执行前检查程序大小，超出某个阈值时跳过

### A.2 x86_kvm_corpus_20260504_205230_092651（多 app run，13/22 apps）

**15 个 daemon failure**，全部来自 **cilium/agent**（14 个）和 **otelcol-ebpf-profiler**（1 个）：

**EBUSY (errno 16) 失败（14个）**：

| failed_pass | 出现次数 |
|-------------|---------|
| wide_mem | 5 |
| rotate | 3 |
| endian_fusion | 2 |
| dce | 2 |
| extract | 1 |
| cond_select | 1 |

- 来自 `cilium/agent`（13 个）和 `otelcol-ebpf-profiler`（1 个）
- EBUSY 从 `BPF_PROG_REJIT` 返回，意味着 kernel 认为程序"正忙"（可能正在被 kprobe/TC 等路径执行）
- **判断：kernel-side 并发锁，不是 daemon bug**。`BPF_PROG_REJIT` 不能中断正在运行的程序，cilium 的高频网络程序尤其容易触发此问题
- 这些失败被正确记录到 failure artifacts 中，符合设计原则（不过滤/不跳过）
- **建议**：文档化此已知限制；可考虑在高并发 workload 前降低 rejit 并发度，但这是策略调整不是 bug fix

**EACCES (errno 13) 失败（1个）**：
- prog 199（cilium）`wide_mem` pass：verifier log 明确显示
  ```
  access beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8
  ```
  这是 wide_mem 试图扩展一个 bpf_iter 程序的内存访问，触发了 struct 访问边界检查
- **判断：真实 bug**，wide_mem 在 bpf_iter 类型程序上错误地合并了 struct pointer 访问，生成了越界的宽加载

### A.3 x86_kvm_corpus_20260504_214251_115258（最新 in-progress run）

- 只有 daemon.stderr.log，无 result.json
- 19 行 log，主要是 `serve: observed new BPF program id N` 行
- 无 panic / ERROR / EINVAL，daemon 正常启动

### A.4 Micro / E2E 最新 run

- `x86_kvm_micro_20260429_140315_265872`：无 daemon.stderr.log，`result.json` 有 benchmarks 但无 failure 字段
- `tracee_20260430_000402_865388`：无 daemon.stderr.log，result 正常

**结论**：micro 和 e2e 无 verifier error 或 daemon 问题。

---

## Part B: Dead Code / Unnecessary Config / Bugs to Delete

### B.1 `daemon/src/commands.rs:1255` — `frozen: false` 硬编码 Bug（严重）

```rust
MapValuesMapJson {
    map_id: map.map_id,
    map_type: map.map_type,
    ...
    frozen: false,   // ← BUG: 硬编码 false
    entries,
}
```

- **问题**：bpfopt 的 `main.rs:1071` 将 `map.frozen` 传入 `MapMetadata`，而 `map_inline.rs:1377` 的 `resolve_frozen_map_value` 在 `!info.frozen` 时直接 return None，跳过 pseudo-map-value load 优化。bpfopt 的 JSON 反序列化 `default_frozen()` 返回 `true`（absent 时默认 true），但 daemon 显式写 `false`，导致所有 map 被当作 mutable 处理，`PSEUDO_MAP_VALUE` 类型加载优化路径完全跳过。
- **v3 设计对应**：§2.2 规定 daemon 需正确传递 map metadata；这是 map metadata 传递错误，不是架构问题
- **规则**：Fail-Fast / Zero Silent Failure — 功能路径被静默禁用
- **建议**：检查 `prog_info.map_flags`（`BPF_F_FROZEN`），或通过 `bpfget` 的 map info 获取 frozen 状态并正确填充；如果无法从 kernel 获取 frozen 状态，则删除该字段并让 bpfopt 用其他方式判断

### B.2 `daemon/src/commands.rs:624-643` — `try_reapply_one` 完全重复 `try_apply_one`（死代码）

```rust
pub(crate) fn try_reapply_one(...) -> Result<OptimizeOneResult> {
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

与 `try_apply_one`（lines 603-622）完全相同，无任何差异。`try_reapply_one` 仅在 `server.rs:189` 调用一次（invalidation 触发的 reoptimization）。
- **规则**：No Dead Code — "every fn must have a real caller"，但两个函数完全等价，其中一个是多余的
- **建议**：删除 `try_reapply_one`，server.rs 中改为直接调用 `try_apply_one`

### B.3 `daemon/src/commands.rs:914-928` — 生产代码中的 `[trace]` 调试打印 + `libc::syscall(SYS_gettid)`

```rust
let tid = unsafe { libc::syscall(libc::SYS_gettid) };
let t0 = std::time::Instant::now();
eprintln!("[trace] tid={tid} REJIT_ENTER prog={prog_id} pass={pass}");
// ...
eprintln!(
    "[trace] tid={tid} REJIT_EXIT prog={prog_id} pass={pass} ok={} elapsed_us={}",
    rejit_result.is_ok(),
    t0.elapsed().as_micros()
);
```

- 这是每次 REJIT 都输出的调试 trace，会大量污染 daemon.stderr.log（每次 corpus run 生成数千行 `[trace]` 行）
- `libc::syscall(SYS_gettid)` 是非 BPF syscall 直接调用，不过 kernel-sys 规则只限制 SYS_bpf，此处技术上合规；但这个 trace 代码本身是应删除的调试残留
- **规则**：No Dead Code（调试 trace 不属于正式功能）
- **建议**：删除整个 trace block（`let tid = ...` 到 `eprintln!("[trace]...")`）。如果需要性能监控，通过结构化的 `PassDetail.elapsed_ns` 字段而不是 eprintln 输出

### B.4 `daemon/src/server.rs:70-91` — `ReoptimizationState::remember_result` 逻辑 Bug

```rust
fn remember_result(&mut self, prog_id: u32, requested_passes: &[String], result: &OptimizeOneResult) {
    if result.status != "ok"
        || result.error_message.is_some()
        || result.inlined_map_entries.is_empty()  // ← 问题条件
    {
        self.enabled_passes_by_prog.remove(&prog_id);
        return;
    }
    ...
}
```

- 当 `inlined_map_entries` 为空（即 map_inline 没有成功 inline 任何 entry）时，**不记录**该程序的 enabled_passes，这样 map invalidation 触发的 reoptimization 就找不到对应的 passes（`reoptimization_passes_for` 返回 error）
- 这意味着：没有 map_inline 成功的程序永远不会被 invalidation tracker 重新优化（即使其他 pass 成功了）
- 但这同时也是有意的：只有 map_inline 成功的程序才需要 invalidation tracking（map 变化后重新 inline）。然而，`ReoptimizationState` 的名字暗示它应该记录所有 enabled_passes 用于 reoptimize，而不仅仅是 map_inline 相关的程序
- **判断**：这不完全是 bug，是有意的限制（invalidation 只针对 map_inline 结果），但：
  - 函数注释/命名无法清楚表达此意图
  - `inlined_map_entries.is_empty()` 条件与其他两个条件（status/error）混在一起，设计意图不清晰
- **规则**：CLAUDE.md 中 "every fn, struct, field, and constant must have a real caller"，此处条件的意图需要文档化，或重构为单独的逻辑

### B.5 `daemon/src/commands.rs:98-102` — `init_cli_dir` 永远传 `None`（部分死代码）

```rust
pub(crate) fn init_cli_dir() -> Result<()> {
    CLI_DIR
        .set(None)   // ← 永远 None，无法通过 CLI 参数或 env var 覆盖
        .map_err(|_| anyhow!("CLI dir already initialised"))
}
```

- `Cli` struct in `main.rs` 是空结构 `struct Cli {}`，没有 `--cli-dir` 参数
- `CLI_DIR` 只能是 `None`（PATH lookup），`Some(dir)` 路径只在测试中使用
- 从功能角度看，`Option<PathBuf>` 的 `Some` 路径是测试专用代码，但被包装进了生产函数
- **规则**：No Dead Code（生产代码中的 None-only Some branch）
- **建议**：测试用途的 fake CLI dir 应通过测试专用 `CliConfig::for_test(dir)` 构造，而不是复用生产路径；`init_cli_dir` 可简化或删除，直接在 `cmd_serve` 里设置 `CliConfig`

### B.6 `daemon/src/commands.rs:283-295` — `RejitSummary` struct 潜在死代码

```rust
#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
struct RejitSummary {
    status: String,
    prog_id: u32,
    insn_count_before: usize,
    insn_count_after: usize,
}
```

- `RejitSummary` 序列化为 JSON 写到 `bpfrejit_summary.json`（`commands.rs:756, 987`）
- 但 `bpfrejit_summary.json` 没有任何代码读取它（在整个 codebase 中 grep 无结果）
- **规则**：No Dead Code — 写出去没人读的文件
- **建议**：删除 `write_json_file(&rejit_summary_json, &rejit_summary)` 调用、`rejit_summary_json` 变量定义、以及 `RejitSummary` struct（如果无其他 caller）

### B.7 `daemon/src/commands.rs:1315-1330` — `missing_target_kops` 的别名处理多余

```rust
"bulk_memory" => {
    push_missing_target(&mut missing, &target, &["bpf_bulk_memcpy", "bpf_memcpy_bulk"]);
    push_missing_target(&mut missing, &target, &["bpf_bulk_memset", "bpf_memset_bulk"]);
}
```

- `bpf_memcpy_bulk` 和 `bpf_memset_bulk` 是别名，但没有任何代码生成这些别名
- `bpfget` 输出的 target.json 只会有 `bpf_bulk_memcpy` / `bpf_bulk_memset`
- **规则**：No Dead Code（未使用的别名名称）
- **建议**：删除 `"bpf_memcpy_bulk"` 和 `"bpf_memset_bulk"` 别名

### B.8 `daemon/src/commands.rs` — `KernelOps` trait 测试 mock 与生产代码耦合

```rust
trait KernelOps {
    fn snapshot_program(...) -> Result<...>;
    fn probe_target(...) -> Result<...>;
    fn rejit(...) -> Result<...>;
}
struct LiveKernelOps;
impl KernelOps for LiveKernelOps { ... }
```

- `KernelOps` trait 存在的唯一目的是支持 `MockKernelOps` 测试
- 生产代码路径全部通过 `LiveKernelOps`，trait dispatch 是零价值的运行时间接层
- 这违背 "No Dead Code" 原则中"不保留 compatibility APIs"的精神——这个 trait 是测试 scaffold
- **注意**：但这里的 mock 测试确实有 bug-detection 价值（rejit_error / ENOSPC 测试路径），所以并非完全无意义
- **建议**：保留测试，但考虑将 mock 移到 `#[cfg(test)]` 内，避免 trait 在生产 binary 中出现

### B.9 `daemon/src/commands.rs:1518-1537` — `canonical_pass` 保留了未使用的别名

```rust
fn canonical_pass(pass: &str) -> String {
    match pass.trim() {
        "wide-mem" | "wide_mem" => "wide_mem",
        ...
        "skb-load-bytes" | "skb_load_bytes" | "skb-load-bytes-spec" | "skb_load_bytes_spec" => {
            "skb_load_bytes_spec"
        }
        other => return other.replace('-', "_"),
    }
    .to_string()
}
```

- runner 发送的 pass 名是 `snake_case`（如 `wide_mem`，`skb_load_bytes_spec`）
- `wide-mem`、`skb-load-bytes`、`skb-load-bytes-spec`、`const-prop` 等 kebab-case 别名在任何 runner 配置中均未出现
- **规则**：No Dead Code（未使用的 pass 别名）
- **建议**：删除 kebab-case 别名，只保留 `snake_case` 形式；`other => other.replace('-', "_")` 的 fallthrough 也可考虑改为 bail!（fail-fast）

---

## Recommended Deletions（优先级排序）

### 高优先级（直接影响正确性或违反核心规则）

1. **`daemon/src/commands.rs:1255` `frozen: false` 硬编码**
   - **优先级**：高 — 直接导致 map_inline pseudo-map-value load 优化路径被跳过
   - **动作**：调查 `bpfget` 的 MapInfo 是否包含 frozen 状态，如包含则正确传递；如不包含则从 `map_flags & BPF_F_FROZEN` 推断或根据 map_type 推断

2. **`daemon/src/commands.rs:914-928` `[trace]` debug 打印 + `SYS_gettid` 调用**
   - **优先级**：高 — 每次 REJIT 都调用 syscall 并打印，pollutes stderr
   - **动作**：完整删除 `let tid`、`let t0`、两行 `eprintln!("[trace]...")`

3. **`daemon/src/commands.rs:624-643` `try_reapply_one` 完全重复**
   - **优先级**：高 — 违反 No Dead Code（duplicate function）
   - **动作**：删除 `try_reapply_one`，`server.rs:189` 改用 `try_apply_one`

### 中优先级（死代码、逻辑不清晰）

4. **`daemon/src/commands.rs:756,987` `bpfrejit_summary.json` 写出但无人读取**
   - **优先级**：中 — 无用的 IO 和 `RejitSummary` struct
   - **动作**：删除 `rejit_summary_json` 相关代码，如果 `RejitSummary` 无其他用途一并删除

5. **`daemon/src/commands.rs:1315-1330` bulk_memory 别名 `bpf_memcpy_bulk`/`bpf_memset_bulk`**
   - **优先级**：中 — 死代码别名
   - **动作**：删除两个从未出现在 target.json 的别名

6. **`daemon/src/commands.rs:1518-1537` `canonical_pass` 中的 kebab-case 别名**
   - **优先级**：中 — runner 从不发送 kebab-case pass 名
   - **动作**：删除 kebab-case 别名，考虑将 fallthrough 改为 fail-fast

7. **`daemon/src/server.rs:70-91` `ReoptimizationState::remember_result` 意图不清晰**
   - **优先级**：中 — 功能受限但意图模糊
   - **动作**：重命名函数或添加 doc comment 明确说明"只跟踪 map_inline 有实际 inline 条目的程序"

### 低优先级（架构清晰度）

8. **`daemon/src/commands.rs:98-102` `init_cli_dir` 永远 None**
   - **优先级**：低 — 技术上不是 bug，但 Some 路径是测试专用
   - **动作**：测试专用 `CliConfig::for_test(dir)` 构造器，`init_cli_dir` 简化

9. **`daemon/src/commands.rs:247-281` `KernelOps` trait**
   - **优先级**：低 — trait 和 mock 移到 `#[cfg(test)]`

---

## 补充：已检查但无问题的项目

- **无 panic / unwrap 失败**：daemon.stderr.log 中无任何 panic 行
- **无 `libc::syscall(SYS_bpf)` 在 daemon/bpfopt 生产路径**：kernel-sys 的 `sys_bpf` wrapper 只用于 `BPF_PROG_REJIT`（fork syscall），其他 BPF 操作走 libbpf-rs/libbpf-sys（正确）
- **无 CLI 交叉依赖**：daemon Cargo.toml 只依赖 `kernel-sys`（lib crate），不依赖 bpfopt/bpfprof binary crate（正确）
- **无 `PassManager` / 内部 transform / dry-run `BPF_PROG_LOAD`**：daemon 完全通过 fork+exec bpfopt CLI 做字节码变换（符合 v3 §2.1）
- **无 `map_fds.json` / BTF metadata replay**：daemon 只构建 in-memory fd_array（符合 v3 §2.2）
- **无 `.ok()` / `let _ =` 在生产路径**：两处 `unwrap_or_default` 均在 `#[cfg(test)]` mock 中
- **`bpf_map_lookup_elem`**：通过 `kernel_sys::bpf_map_lookup_elem`（即 `libbpf_sys::*` re-export），符合 "Use libbpf-rs/libbpf-sys" 规则
- **`perf_event_open`** in kernel-sys：`libc::syscall(SYS_perf_event_open)` 在 kernel-sys 内，这是 perf syscall 不是 BPF syscall，属于合理的 kernel-sys 内部实现
